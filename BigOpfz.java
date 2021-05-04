import java.math.BigInteger;
import java.util.*;

public class BigOpfz {
	static int anfang = 0;
	static String wort;
	public static void main(String args[])
	{
		System.out.println("Primfaktoren von: ");
		Scanner sc = new Scanner(System.in);
		int eingabe = sc.nextInt();
		System.out.println("Primfaktoren sind: " + primfaktoren(eingabe, primes(eingabe)));
		
	}
	
	public static boolean isPrime(int x)
	{
		for (int i=2; i<x; i++)
		{
			if (x % i == 0)
			{
				return false;
			}
			 
		}
		return true;
	}
	
	// erstelle Array von zahlen bis x
	public static boolean[] numbers(int x)
	{
		boolean[] zahlen = new boolean[x];
		if(x < 2)
		{
			System.out.println("Zahl muss größer gleich 2 sein");
			zahlen[0] = false;
		}
		else
		{
			// alle indizes werden auf true gesetzt
			for(int i = 0; i <= x- 2; i++)			
			{
				zahlen[i] = true;
			}
		}
		return zahlen;
	}
		
	// alle indizes im array, die keine Primzahl sind, werden auf false gesetzt
	public static int[] primes(int y)
	{
		// y = y+1;
		boolean[] primzahlen = numbers(y);
		int laenge =(int) Math.sqrt(primzahlen.length);
		for(int i=0; i<y-2; i++)
		{
			// es reicht aus bis sqrt(von der Länge des Arrays) zu gehen
			for(int h=2; h<= laenge;h++)
			{
				// Zahl "multiple" ist ein multiple vom array am Index i
				int multiple = (h* (i+2));
				if (multiple <= primzahlen.length -1)
				{
					//alle multiples, die im array vorhanden sind, werden auf 'false' gesetzt, -2 weil array bei 0 und nicht 2 beginnt
					primzahlen[multiple-2] = false;
				}
			}
		}
		
		int anfang = 0;
		int[] primeValue = new int[primzahlen.length / 2];
		for (int i=0; i<primzahlen.length; i++)
		{
			if (primzahlen[i] && anfang < primeValue.length)
			{
				primeValue[anfang] = i + 2;
				anfang += 1;
			}
		}
		// y wird als Value angegeben, daher folgender Code, um y zu removen:
	    for (int j = 0; j < primeValue.length; j++)
	    {
	    	if (!isPrime(primeValue[j]))
	    	{
	    		primeValue[j] = 0;
	    	}
	    }
		// zähle wieviele Primzahlen in primeValue gespeichert sind
	    int counter = 0;
	    for (int i=0; i<primeValue.length; i++)
	    {
	    	if (primeValue[i] > 0)
	    	{
	    		counter += 1;
	    	}
	    }
	    int[] primeWert = new int[counter];
	    for (int i=0; i<primeWert.length; i++)
	    {
	    	if (primeValue[i] > 0)
	    	{
	    		primeWert[i] = primeValue[i];
	    	}
	    }
	    return primeWert;
	}
	
	public static void zeige(int[] pArray)
	{
		for(int i=0; i<pArray.length; i++)
		{
			System.out.println(pArray[i] + " " + String.valueOf(i));
		}
	}
	
	static List <Integer> key = new ArrayList<Integer>();

	public static List<Integer> primfaktoren(int x, int[] pArray)
	{
		int y;
		// concat String;
		if (!isPrime(x))
		{
			if (x % (pArray[anfang]) == 0)
			{
				key.add(pArray[anfang]);
				y = x / pArray[anfang];
				primfaktoren(y, pArray);
			}
			else
			{
				anfang += 1;
				primfaktoren(x, pArray);
			}
		}
		else
		{
			key.add(x);
		}
		return key;
	}
}	