#include <stdio.h>
#include <string.h>

FILE *file;

struct electrogazMember{
	
	int  totalAmount;
	int  unit;
	int  serviceCharges;
	int  minCharges;
	int  otherCharges;
	int  unitCharges;
	int  waterMeterNo;
	int  electricalMeterNo;
	
};


void calculatingBillingForWater(int waterMeterNo  ,int waterUnit){
	struct electrogazMember electro;
	int tweentPer;
	
	electro.minCharges  = 30;
	electro.serviceCharges = 300;
	
	if(waterUnit < 500){
		electro.unitCharges  =  waterUnit * 100;
		
		if(electro.unitCharges > 1000){
			tweentPer  = (electro.unitCharges * 20)/100;
		}
	}else if( (waterUnit >= 500) &&  (waterUnit <= 1000)  ){
		electro.unitCharges  = waterUnit * 150;
		
		if(electro.unitCharges > 1000){
			tweentPer  = (electro.unitCharges * 20)/100;
		}
	}else if( (waterUnit >= 1001) && (waterUnit <= 1500)){
		electro.unitCharges  = waterUnit * 200;
		
		if(electro.unitCharges > 1000){
			tweentPer  = (electro.unitCharges * 20)/100;
		}
	}else{
		electro.unitCharges  = waterUnit * 250;
		
		if(electro.unitCharges > 1000){
			tweentPer  = (electro.unitCharges * 20)/100;
		}
	}
	
	electro.otherCharges  = electro.minCharges + electro.serviceCharges + tweentPer;
	electro.totalAmount   = electro.unitCharges + electro.otherCharges;
	
	
	printf("\n\n ************ BILL FOR WATER CUSTOMER ***********\n\n");
	printf("\t Water Meter Number is           =  %d   \n"  , waterMeterNo);
	printf("\t Individual Charges /per Unit Is =  %d $ \n"  , electro.unitCharges);
	printf("\t Unit Consumed                   =  %i   \n"  , waterUnit);
	printf("\t Other Charges                   =  %i $ \n"  , electro.otherCharges);
	printf("\t Total Amount Is                 =  %i $ \n"  , electro.totalAmount);
	
	
	
	file  = fopen("C:/Users/PRINCE/Desktop/ElectroGasReport/waterReport.txt", "a");
	
	if(file == NULL){
		printf("Can not Open File");
	//exit(1);
	}else{
			char wMeter[10];
			char wUnitChrg[10];
			char wUnite[10];
			char wOtherCharge[10];
			char wTotalCahrges[10];
			
			fputs(itoa(waterMeterNo,wMeter,10),file);
			fputs("\t" , file);
			fputs(itoa(electro.unitCharges,wUnitChrg,10),file);
			fputs("$\t" , file);
			fputs(itoa(waterUnit,wUnite,10),file);
			fputs("\t" , file);
			fputs(itoa(electro.otherCharges,wOtherCharge,10),file);
			fputs("$\t" , file);
			fputs(itoa(electro.totalAmount,wTotalCahrges,10),file);
			fputs("$\n" , file);
			printf("\n\n\t Water Billing Has Been Saved Successfull!!! ");	
	}
	
	
}

void  viewAllWaterCustomer(){
	
	
	file  = fopen("C:/Users/PRINCE/Desktop/ElectroGasReport/waterReport.txt", "r");
	
	char viewAllWaterCustomerBilling[1000];
	
	printf("\n\n\t LIST OF CUSTOMER THAT HAS BEEN BILLED FOR WATER \n");
	while (fgets(viewAllWaterCustomerBilling,1000,file)){
		printf("%s \t"  , viewAllWaterCustomerBilling);
	}
	
	fclose(file);

}



void calculatingBillingForElectricity(int electricalMeterNo  ,int electricalUnit){
	struct electrogazMember electro;
	int thifteen;
	
	electro.minCharges  = 100;
	electro.serviceCharges = 100;
	
	if(electricalUnit < 100){
		electro.unitCharges  =  electricalUnit * 60;
		
		if(electro.unitCharges > 500){
			thifteen  = (electro.unitCharges * 15)/100;
		}
	}else if( (electricalUnit >= 101) &&  (electricalUnit <= 200)  ){
		electro.unitCharges  = electricalUnit * 80;
		
		if(electro.unitCharges > 500){
			thifteen  = (electro.unitCharges * 15)/100;
		}
	}else if( (electricalUnit >= 201) &&  (electricalUnit <= 300)  ){
		electro.unitCharges  = electricalUnit * 90;
		
		if(electro.unitCharges > 500){
			thifteen  = (electro.unitCharges * 15)/100;
		}
	}else{
		electro.unitCharges  = electricalUnit * 120;
		
		if(electro.unitCharges > 500){
			thifteen  = (electro.unitCharges * 15)/100;
		}
	}
	
	electro.otherCharges  = electro.minCharges + electro.serviceCharges + thifteen;
	electro.totalAmount   = electro.unitCharges + electro.otherCharges;
	
	
	printf("\n\n ************ BILL FOR ELECTRICTY CUSTOMER ***********\n\n");
	printf("\t Electricty Meter Number is           =  %d   \n"  , electricalMeterNo);
	printf("\t Individual Charges /per Unit Is =  %d $ \n"  , electro.unitCharges);
	printf("\t Unit Consumed                   =  %i   \n"  , electricalUnit);
	printf("\t Other Charges                   =  %i $ \n"  , electro.otherCharges);
	printf("\t Total Amount Is                 =  %i $ \n"  , electro.totalAmount);
	
	
	
	file  = fopen("C:/Users/PRINCE/Desktop/ElectroGasReport/ElectricalReport.txt", "a");
	
	if(file == NULL){
		printf("Can not Open File");
		exit(1);
	}else{
			char wMeter[10];
			char wUnitChrg[10];
			char wUnite[10];
			char wOtherCharge[10];
			char wTotalCahrges[10];
			
			fputs(itoa(electricalMeterNo,wMeter,10),file);
			fputs("\t" , file);
			fputs(itoa(electro.unitCharges,wUnitChrg,10),file);
			fputs("$\t" , file);
			fputs(itoa(electricalUnit,wUnite,10),file);
			fputs("\t" , file);
			fputs(itoa(electro.otherCharges,wOtherCharge,10),file);
			fputs("$\t" , file);
			fputs(itoa(electro.totalAmount,wTotalCahrges,10),file);
			fputs("$\n" , file);
			printf("\n\n\t Electrical  Billing Has Been Saved Successfull!!! ");	
	}
	
	
}

void  viewAllElectricalCustomer(){
	
	
	file  = fopen("C:/Users/PRINCE/Desktop/ElectroGasReport/ElectricalReport.txt", "r");
	
	char viewAllElectricalCustomerBilling[1000];
	
	printf("\n\n\t LIST OF CUSTOMER THAT HAS BEEN BILLED FOR ELECTRICITY \n");
	while (fgets(viewAllElectricalCustomerBilling,1000,file)){
		printf("%s \t"  , viewAllElectricalCustomerBilling);
	}
	
	fclose(file);

}


int main(int argc, char *argv[]) {
	
	struct electrogazMember electro;
	char   makeChoice;
	
	printf("******** WELCOME TO ELECTROGAZ BILLING SYSTEM ********** \n\n");
	printf("\t Make Your Choice :\n");
	printf("\t W. Water Billing System \n");
	printf("\t E. Eletricity Billing System \n\n");
	
	printf("\t Enter Your Choice : ");
	scanf("%c"  , &makeChoice);
	
	
	if ((makeChoice =='W') || (makeChoice =='w')){
		
		int choice1;
		printf("\n ##### WELCOME TO WATER  BILLING SYSTEM  ##### \n\n");
		
		
		printf("\t Choose Action  :\n");
		printf("\t 1. Water Billing Customer \n");
		printf("\t 2. View Water Billing Customer \n\n");
		
		printf("\t Enter Your Choice : ");
		scanf("%d"  , &choice1);
		
		
		switch(choice1){
			case 1:

				printf("\n \t Enter Customer Water Meter  : ");
				scanf("%d"  , &electro.waterMeterNo);
				
				printf("\t Enter  Water Unit Consumed  :  ");
				scanf("%i"  , &electro.unit);
				calculatingBillingForWater(electro.waterMeterNo  , electro.unit);
				
			break;
				
			case 2:
					viewAllWaterCustomer();
			break;
			
			default:
					printf("Oooops Invalid Choice ,  Choose  Either 1 or 2");
			break;
		}
		
		
	}else if ((makeChoice =='E') || (makeChoice =='e')){
		printf("\n ##### WELCOME TO ELECTRICITY  BILLING SYSTEM  ##### \n\n");
		int choice1;
		
		
		printf("\t Choose Action  :\n");
		printf("\t 1. Electricity Billing Customer \n");
		printf("\t 2. View Electricity Billing Customer \n\n");
		
		printf("\t Enter Your Choice : ");
		scanf("%d"  , &choice1);
		
		
		switch(choice1){
			case 1:
				
				printf("\n \t Enter Customer Electricity Meter  : ");
				scanf("%d"  , &electro.electricalMeterNo);
				
				printf("\t Enter  Electricity Unit Consumed  :  ");
				scanf("%i"  , &electro.unit);
				calculatingBillingForElectricity(electro.electricalMeterNo  , electro.unit);
				
			break;
				
			case 2:
					viewAllElectricalCustomer();
			break;
			
			default:
					printf("\n\t  Oooops Invalid Choice ,  Choose  Either 1 or 2");
			break;
		}
		
	}else{
		printf("\n\t Ooops Invalid Choice  , Choose Either W or E  , w or e \n\n");
	}
	
	
	
	return 0;
}
