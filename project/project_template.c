#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct store{
	char product_name[50] ;
	int product_price ;
	int status;
	struct store* prev ;
	struct store* next ;	
};


struct shopping_cart{
	char product_name[50] ; 
	int product_price ;
	struct shopping_cart* next ;
};



// Add any functon you want

struct store* head;
int counter =0;
void print_list(struct store* tail)
{
	
    //	struct store* head = (struct store*) malloc(sizeof(struct store));
 if(counter ==0){
	 
	head = tail->next;
}
	 else if(counter !=0){
	 
	
	tail = head->next;
}

	do 
	{
		printf("product_name: %s\n", head->product_name);
		printf("product_price: %d\n\n", head->product_price);
		printf("status: %d\n\n", head->status);
		head = head->next ;	
		counter++;
		break;
		
		
	} while(head != tail->next);
	
	printf("\n\n");


}
	


void next_pro(struct store* tail){
	//print_list(t);
	
	
	if(counter ==0){
	 
	head = tail->next;
}
	 else if(counter !=0){
	 
	
	tail = head->next;
}

	do 
	{
		printf("product_name: %s\n", head->product_name);
		printf("product_price: %d\n\n", head->product_price);
		printf("status: %d\n\n", head->status);
		head = head->next ;	
		counter++;
		break;
		
		
	} while(head != tail->next);
	
	printf("\n\n");
	
}

prev_pro(struct store* tail){
	if(counter ==0){
	 
	head = tail->next;
}
	 else if(counter !=0){
	 
	
	head = head->next;
}

	do 
	{
		printf("product_name: %s\n", head->product_name);
		printf("product_price: %d\n\n", head->product_price);
		printf("status: %d\n\n", head->status);
		head = head->next ;	
		counter++;
		break;
		
		
	} while(head != tail->next);
	
	printf("\n\n");
}







void store_type(struct store* market,struct store* grocery,struct store* tech){
	struct store* t;
	printf("Stores Menu:\n");
	printf("\n1-Market		2-Grocery		3-Tech\n\n");
	int type_op;
	printf("\nPlease enter store number to browse it's products, or 4 to return to main menu: ");
	scanf("%d",&type_op);
	
	printf("\n\n\n===========================================================\n\n");
	printf("Welcome to the Super Market");
	
	
		switch(type_op){
		
		case 1:
		 print_list(market);
		 t=market;
		 int o;
		 while(o>=0){
		 printf("Enter option (next or prev): ");
		 scanf("%d",&o);
		 switch(o){
		 	case 1:	
		 		next_pro(t);
		 	    break;
		 	
		 	case 2:
		 		prev_pro(t);
		 		break;
		 }
			 }
	}
}




struct store* add_at_end(struct store* tail , char name[50], int price, int status)
{
	// Complete
	

	
	
	 struct store* newP = (struct store*) malloc(sizeof(struct store));
	newP->product_price = price ; 
	newP->status=status;
	
	int i ; 
	for(i = 0 ; i< 50 ;i++)
		newP->product_name[i] = name[i] ;
	
	newP->prev = tail ; 
	newP->next = tail->next; 
	
	tail->next = newP ; 
	tail = newP ;
	
	return tail ;

}

struct store* add_to_empty(struct store* tail, char name[50], int price , int status)
{
	// Complete
	
	struct store* newP = (struct store*) malloc(sizeof(struct store));
	newP->product_price = price ; 
	newP->status = status ; 
	


	int i ; 
	for(i = 0 ; i< 50 ;i++)
		newP->product_name[i] = name[i] ;

///////////////////////////////////////////////////////////////////
	struct store* head = tail->next ; 
	
	newP->prev = newP ;
	newP->next = newP ;
	
	//tail->next = newP ;
	

	return newP ; 

}



/*
struct shopping_cart* add_to_empty(struct shopping_cart* tail, char name[50], int price )
{




}
*/









int main()
{
	struct store* market = (struct store*) malloc(sizeof(struct store));
	struct store* tail = (struct store*) malloc(sizeof(struct store));	
	
	struct shopping_cart* shptail = (struct shopping_cart*) malloc(sizeof(struct shopping_cart));	
	
	//char product_name[50];
	//strcpy(product_name,"Pepsi");
	
	market = add_to_empty(market , "Pepsi" , 5 , 1);
	market = add_at_end(market , "Chips", 5,  0);
	market = add_at_end(market , "Chocolate", 10,  1);
	
	
	
// ====================================================================

	struct store* grocery = (struct store*) malloc(sizeof(struct store));
	
	grocery = add_to_empty(grocery , "Apples" , 5 , 1);
	grocery = add_at_end(grocery , "Oranges", 5,  0);
	grocery = add_at_end(grocery , "Carrots", 10,  1);
	
	
// ====================================================================

	struct store* tech = (struct store*) malloc(sizeof(struct store));
	
	tech = add_to_empty(tech , "Mouse" , 5 , 1);
	tech = add_at_end(tech , "Keyboard", 5,  0);
	tech = add_at_end(tech , "Laptop", 10,  1);
	
	
// ==================================================================== 

	printf("========================================================================\n");
	printf("|   Welcome to CS212 Data Structures & Algorithms console commerce ^^  |\n");
	printf("========================================================================\n\n");
	
	
	int option ; 
	 
	
	do{
		printf("1- View Stores\n");
		printf("2- View My shopping Cart\n");
		printf("3- Exit console commerce\n");
		
		printf("\nPlease enter an option number: ");
		
		scanf("%d", &option);
				
		printf("\n\n===========================================================\n\n");
		
		// Complete here
		
		
		switch(option){
			case 1:
			store_type(market , grocery , tech);
			break;
			
		}
	} while(option != 3);


	
	
}


