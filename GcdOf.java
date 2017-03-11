//package myPracticeee;
import java.util.Scanner;

public class GcdOf {
public static int gcd(int n1,int n2){
	 int r=(n1>=n2)?n2:n1;
	 
	 for(int i=r;i>0;i--){
		 if(n1%i==0 && n2%i==0) return i;
	 }
	 
	 return 1;
}
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		//System.out.println("Enter two number:");
		int n1=sc.nextInt();
		int n2=sc.nextInt();
		sc.close();
		n1=gcd(n1,n2);
		if(n1==1)
			System.out.println("Co-prime");
		//else
			//System.out.println(n1+"Prime");
	}

}
