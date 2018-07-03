import java.util.ArrayList;
import java.util.Scanner;

public class CustomerManager3 {

	//고객 정보를 저장할 자료구조 선언
	static ArrayList<Customer> custList = new ArrayList<>();

	//리스트 정보를 조회하기 위해 인덱스를 필요로 함
	static int index = -1;

	static int count = 0;//custList.size()

	//기본 입력장치로부터 데이터를 입력받기 위해 Scanner객체 생성
	static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {

		while(true) {
			count = custList.size();
			System.out.printf("\n[INFO] 고객 수 : %d, 인덱스 : %d\n", count, index);
			System.out.println("메뉴를 입력하세요.");
			System.out.println("(I)nsert, (P)revious, (N)ext, " +
					"(C)urrent, (U)pdate, (D)elete, (Q)uit");
			System.out.print("메뉴 입력: ");
			String menu = scan.next();
			menu = menu.toLowerCase();	//입력한 문자열을 모두소문자로 변환
			switch(menu.charAt(0)) {
			case 'i':
				System.out.println("고객정보 입력을 시작합니다.");
				insertCustomerData();
				System.out.println("고객정보를 입력했습니다.");
				break;
			case 'p' :
				System.out.println("이전 데이터를 출력합니다.");
				if(index <= 0) {
					System.out.println("이전 데이터가 존재하지 않습니다.");
				}else {
					index--;
					printCustomerData(index);
				}
				break;
			case 'n' :
				System.out.println("다음 데이터를 출력합니다.");
				if(index >= count-1) {
					System.out.println("다음 데이터가 존재하지 않습니다.");
				}else {
					index++;
					printCustomerData(index);
				}
				break;
			case 'c' :
				System.out.println("현재 데이터를 출력합니다.");
				if( (index >= 0) && (index < count)) {
					printCustomerData(index);
				}else {
					System.out.println("출력할 데이터가 선택되지 않았습니다.");
				}
				break;			
			case 'u' :
				System.out.println("데이터를 수정합니다.");
				if( (index >= 0) && (index < count)) {
					System.out.println(index + "번째 데이터를 수정합니다.");
					updateCustomerData(index);
				}else {
					System.out.println("수정할 데이터가 선택되지 않았습니다.");
				}
				break;
			case 'd' :
				System.out.println("데이터를 삭제합니다.");
				if( (index >= 0) && (index < count)) {
					System.out.println(index + "번째 데이터를 삭제합니다.");
					deleteCustomerData(index);
				}else {
					System.out.println("삭제할 데이터가 선택되지 않았습니다.");
				}
				break;
			case 'q' :
				System.out.println("프로그램을 종료합니다.");
				scan.close();	//Scanner 객체를 닫아준다.
				System.exit(0);	//프로그램을 종료시킨다.
				break;	
			default : 
				System.out.println("메뉴를 잘 못 입력했습니다.");	
			}//end switch
		}//end while
	}//end main

	public static void insertCustomerData() {
		System.out.print("이름 : ");
		String name = scan.next();
		System.out.print("성별(M/F) : ");
		char gender = scan.next().charAt(0);
		//비어있으면 추가하는 기능
		
		System.out.print("이메일 : ");
		String email = scan.next();
		
		//비어있으면 추가하는 기능
		while(email.isEmpty()) {
			System.out.println("다시 입력해주세요.");
			email = scan.next();
		}
		//입력에서 @와 .이 없으면
		while((!email.contains("@")) || (!email.contains("."))) {
			System.out.println("형식에 맞춰 입력해주세요.");
			email = scan.next();
		}
		System.out.print("출생년도 : ");	
		
		String birthYear = scan.next();
		
		while(!IsNumber(birthYear)) {
			birthYear = scan.next();
			System.out.println("숫자만 입력해주세요.");
		}
		//only 숫자 , 6자리이상 X

		int birth_num = Integer.parseInt(birthYear);
		System.out.println(birth_num);
		while(birth_num > 1e6-1) {
			
			while(!IsNumber(birthYear)) {
				birthYear = scan.next();
				System.out.println("숫자만 입력해주세요.");
			}
			
			birth_num = Integer.parseInt(birthYear);
			System.out.println("6자리의 생년월일을 입력해주세요.");
			birthYear = scan.next();
		}

		//입력받은 데이터로 고객 객체를 생성
		Customer cust = new Customer(name, gender, email, birthYear);

		//고객 객체를 ArrayList에 저장
		custList.add(cust);
	}

	//고객데이터 출력
	public static void printCustomerData(int index) {
		Customer cust = custList.get(index);
		System.out.println("==========CUSTOMER INFO================");
		System.out.println("이름 : " + cust.getName());
		System.out.println("성별 : " + cust.getGender());
		System.out.println("이메일 : " + cust.getEmail());
		System.out.println("출생년도 : " + cust.getBirthYear());
		System.out.println("=======================================");
	}

	//index 위치의 고객정보를 삭제합니다.
	public static void deleteCustomerData(int index) {
		custList.remove(index);
	}

	//index 위치의 고객 정보를 수정합니다.
	public static void updateCustomerData(int index) {
		Customer cust = custList.get(index);
		System.out.println("---------UPDATE CUSTOMER INFO----------");
		System.out.print("이름(" + cust.getName() + ") :");
		cust.setName(scan.next());

		System.out.print("성별(" + cust.getGender() + ") :");
		cust.setGender(scan.next().charAt(0));

		System.out.print("이메일(" + cust.getEmail() + ") :");
		cust.setEmail(scan.next());

		System.out.print("출생년도(" + cust.getBirthYear() + ") :");
		cust.setBirthYear(scan.next());		
	}
	
	public static boolean IsNumber(String strNumber) {
		
		boolean result = true;
		try {
			for(char ch : strNumber.toCharArray()) {
				if(!Character.isDigit(ch)) {
					result = false;
					break;
				}
			}
		}catch(Exception ex) {
			
			System.out.println("숫자만 입력하세요.");
			
		}
		return result;
	}

}//end class