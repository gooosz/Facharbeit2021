import java.util.*;

public class Main {
    public static void main(String args[])
    {
    	Scanner sc = new Scanner(System.in);
    	System.out.println("Satz, der Verschlüsselt werden soll: ");
    	String str = sc.nextLine();
    	Mensch person1 = new Mensch();
        Mensch person2 = new Mensch();
        person1.sendeNachricht(person2, str);
        System.out.println("Satz ist verschlüsselt als: ");
        System.out.println(person2.encryptedList);
        System.out.print("Entschlüsselt: ");
        System.out.println(person2.decryptMessage(person2.encryptedList));
        System.out.println();
        System.out.println("Eigenschaften der Verschlüsselung");
        System.out.println("Primzahl p1: " + person1.encrypt.p1);
        System.out.println("Primzahl p2: " + person1.encrypt.p2);
        System.out.println("e: " + person1.encrypt.returnE());
        System.out.println("n: " + person1.encrypt.returnN());
        System.out.println("phi: " + person1.encrypt.phi);
        System.out.println("d: " + person2.privaterKey);
    }
}