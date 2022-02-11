void F_1 ( T_1 * V_1 )
{
unsigned long V_2 ;
char V_3 [ 200 ] ;
const char * V_4 , * V_5 ;
int line , V_6 ;
unsigned long V_7 ;
V_7 = F_2 () ;
while ( ( V_2 = F_3 ( & V_4 , & line , & V_5 , & V_6 ) ) != 0 )
{
fprintf ( V_1 , L_1 , V_7 , F_4 ( V_2 , V_3 ) ,
V_4 , line , ( V_6 & V_8 ) ? V_5 : L_2 ) ;
}
}
void F_5 ( T_2 * V_9 )
{
unsigned long V_2 ;
char V_3 [ 256 ] ;
char V_10 [ 256 ] ;
const char * V_4 , * V_5 ;
int line , V_6 ;
unsigned long V_7 ;
V_7 = F_2 () ;
while ( ( V_2 = F_3 ( & V_4 , & line , & V_5 , & V_6 ) ) != 0 )
{
sprintf ( V_10 , L_3 , V_7 , F_4 ( V_2 , V_3 ) ,
V_4 , line ) ;
F_6 ( V_9 , V_10 , strlen ( V_10 ) ) ;
if ( V_6 & V_8 )
F_6 ( V_9 , V_5 , strlen ( V_5 ) ) ;
F_6 ( V_9 , L_4 , 1 ) ;
}
}
