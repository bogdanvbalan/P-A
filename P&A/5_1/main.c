#include <ctype.h> 

int getch(void);    
void ungetch(int); 
 
/* getint:  get next integer from input into *pn */    
int getint(int *pn) {        
   	int c, d, sign; 
 
    while (isspace(c = getch()))   /* skip white space */            
    	;        
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {            
    	ungetch(c);  /* it is not a number */            
    	return 0;        
    }        
    sign = (c == '-') ? -1 : 1;        
    if ((c == '+' || c == '-') && isdigit((d = getch()))) {
    	ungetch(d);           
    	c = getch();        
    }
    else {
    	ungetch(d);
    	ungetch(c);
    }
    for (*pn = 0; isdigit(c); c = getch())            
    	*pn = 10 * *pn + (c - '0');        
    *pn *= sign;        
    if (c != EOF)            
    	ungetch(c);        
    return c;    
} 

int main() {

}