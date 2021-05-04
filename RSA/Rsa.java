import java.math.BigInteger;
import java.util.*;

public class Rsa
{
	int anfang = 0;
    String wort;
    List <Integer> key;

    //primezahlen
    Random rnd = new Random();
    BigInteger p1 = BigInteger.probablePrime(4096, rnd);
    BigInteger p2 = BigInteger.probablePrime(4096, rnd);

    BigInteger phi = eulersPhi(p1).multiply(eulersPhi(p2));
    //key
    BigInteger e = sendPublicKey1();


    public Rsa()
    {
        key = new ArrayList<Integer>();
    }

    public BigInteger ggT(BigInteger a, BigInteger b)
    {
        return a.gcd(b);
    }

    public BigInteger eulersPhi(BigInteger x)
    {
        return x.subtract(BigInteger.valueOf(1));
    }

    public BigInteger sendPublicKey1()
    {
        int bitlength = rnd.nextInt((phi.bitCount() - 2048) + 1)+ 2048;
        BigInteger e = BigInteger.probablePrime(bitlength, rnd);
        if (e.gcd(phi).compareTo(BigInteger.valueOf(1)) != 0)
        {
            sendPublicKey1();
        }
        return e;
    }

    public BigInteger returnE()
    {
        return e;
    }

    public BigInteger returnN()
    {
        BigInteger n = p1.multiply(p2);
        return n;
    }

    public BigInteger getQ(BigInteger a, BigInteger b)
    {
        BigInteger rest = b.remainder(a);
        b = b.subtract(rest);
        return b.divide(a);
    }

    public boolean equals(BigInteger a, BigInteger b)
    {
        return a.compareTo(b) == 0;
    }

    public BigInteger privateKey()
    {
        // ertelle Arrays, die die values des erweiterten euklidischen Algorithmus annehmen
        int laenge = 10000;
        BigInteger[] a = new BigInteger[laenge];
        BigInteger[] b = new BigInteger[laenge];
        BigInteger[] q = new BigInteger[laenge];
        BigInteger[] r = new BigInteger[laenge];

        //startwerte
        a[0] = e;
        b[0] = phi;
        q[0] = getQ(b[0], a[0]);
        r[0] = a[0].remainder(b[0]);

        //erweiterter euklidischer Algorithmus
        for (int i=1; i<laenge; i++)
        {
            a[i] = b[i-1];
            b[i] = r[i-1];
            r[i] = a[i].remainder(b[i]);
            q[i] = getQ(b[i], a[i]);
            //wenn der rest r = 0 ist, hat man den ggT und man kann aufhören
            if(r[i].compareTo(BigInteger.valueOf(0)) == 0)
            {
                break;
            }
        }
        //zählen wieviele Schritte der erweiterte euklidische Algorithmus hat
        int counter = 0;
        for (int i=0; i<laenge; i++)
        {
            //a[i].compareTo(BigInteger.valueOf(0)) != 0
        	try {
        	if (!equals(a[i], BigInteger.valueOf(0)))
            {
                counter++;
            }
        	}
        	catch(NullPointerException e)
        	{
        		break;
        	}
        }
        //erweiterte arrays
        BigInteger[] d = new BigInteger[counter];
        BigInteger[] k = new BigInteger[counter];
        d[counter-1] = BigInteger.valueOf(0);
        k[counter-1] = BigInteger.valueOf(1);
        for (int i= counter-2; i>=0; i--)
        {
            d[i] = k[i+1];
            k[i] = q[i].multiply(k[i+1]);
            k[i] = d[i+1].subtract(k[i]);
        }
        
        if (d[0].signum() <= 0)
        {
            d[0] = d[0].add(b[0]);
        }
        
        

        return d[0];
    }

    public BigInteger encrypt(double m, BigInteger e, BigInteger n)
    {
        BigInteger verschluesselung = BigInteger.valueOf((long) m);

        verschluesselung = verschluesselung.modPow(e, n);
        return verschluesselung;
    }

    public BigInteger decrypt(BigInteger c, BigInteger d, BigInteger n)
    {
        BigInteger x = c;
        x = x.modPow(d, n);
        return x;
    }

    public List<BigInteger> nachrichtVerschluesseln(String t, BigInteger e, BigInteger n)
    {
        List<Integer> nums = stringToNumber(t);
        List<BigInteger> encrypted = new ArrayList<BigInteger>();
        //encryption aller einzelnen Elemente der Liste
        for (double c: nums)
        {
            BigInteger x = encrypt(c, e, n);
            encrypted.add(x);
        }
        return encrypted;
    }

    public String nachrichtEntschluesseln(List<BigInteger> encrypted, BigInteger d, BigInteger n)
    {
        List<BigInteger> decrypted = new ArrayList<BigInteger>();
        for (BigInteger h: encrypted)
        {
            BigInteger y = decrypt(h, d, n);
            decrypted.add(y);
        }
        List<Integer> nums = new ArrayList<Integer>();
        for (BigInteger bigNum: decrypted)
        {
            int number = bigNum.intValue();
            nums.add(number);
        }
        String wort = numberToString(nums);
        return wort;
    }

    public List<Integer> stringToNumber(String pWord)
    {
        List<Integer> numberList = new ArrayList<Integer>();
        for (char c: pWord.toCharArray())
        {
            numberList.add((int) c);
        }
        return numberList;
    }

    public String numberToString(List<Integer> numberList)
    {
        List <Character> charList = new ArrayList<Character>();
        for (int pZahl: numberList)
        {
            charList.add((char) pZahl);
        }
        StringBuilder wort = new StringBuilder();
        for (Character c: charList)
        {
            wort.append(c);
        }
        return wort.toString();
    }

}