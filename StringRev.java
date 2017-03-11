
import java.io.*;
import java.util.Scanner;
public class StringRev {
   public static String reverse(String str){
	   String str1="",str2="";
	   String[] retval=str.split("\\s");
	   
	   str1=retval[0];
	   str2=retval[1];
	
	   str2=str2+" "+str1;
	   return str2;
		   
	   }
   
	
	public static void main(String[] args) {
		System.out.println("Enter a string:");
		Scanner sc=new Scanner(System.in);
		String str=sc.nextLine();
		sc.close();
         System.out.println("Reverse="+reverse(str));
	}

}
