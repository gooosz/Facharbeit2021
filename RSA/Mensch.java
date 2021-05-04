import java.util.*;
import java.math.BigInteger;

public class Mensch {
	Rsa encrypt;
	List<BigInteger> pocketsOfKeys;
	List<BigInteger> encryptedList;
	BigInteger privaterKey;
	
	public Mensch() {
		encrypt = new Rsa();
		pocketsOfKeys = new ArrayList<BigInteger>();
		encryptedList = new ArrayList<BigInteger>();
		privaterKey = encrypt.privateKey();
	}
	
	public void getEncryptedList()
	{
		for(BigInteger bigNum: encryptedList)
		{
			System.out.print(bigNum + " , ");
		}
	}
	
	public void sendPublicKeys(Mensch person)
	{
		//remove all current keys, so that new keys can be accessed
		//remove all keys from the person's array
		for(int i=person.pocketsOfKeys.size()-1; i>=0; i--)
		{
			person.pocketsOfKeys.remove(i);
		}
		for(int i=pocketsOfKeys.size()-1; i>=0; i--)
		{
			this.pocketsOfKeys.remove(i);
		}
		
		BigInteger e = encrypt.returnE();
		BigInteger n = encrypt.returnN();
		person.pocketsOfKeys.add(e);
		person.pocketsOfKeys.add(n);
		this.pocketsOfKeys.add(e);
		this.pocketsOfKeys.add(n);
	}
	
	public void sendEncryptedMessage(Mensch person, String wort)
	{
		List<BigInteger> einzeln = encrypt.nachrichtVerschluesseln(wort, this.pocketsOfKeys.get(0), this.pocketsOfKeys.get(1));
		for(BigInteger bigNum: einzeln)
		{
			person.encryptedList.add(bigNum);
		}
	}
	
	public String decryptMessage(List<BigInteger> list)
	{
		String wort = encrypt.nachrichtEntschluesseln(list, privaterKey, pocketsOfKeys.get(1));
		return wort;
	}
	
	public void sendeNachricht(Mensch person, String wort)
	{
		person.sendPublicKeys(this);
		this.sendEncryptedMessage(person, wort);
		person.decryptMessage(person.encryptedList);
	}
}
