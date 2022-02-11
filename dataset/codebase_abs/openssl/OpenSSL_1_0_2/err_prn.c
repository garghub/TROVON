void F_1 ( int (* F_2) ( const char * V_1 , T_1 V_2 , void * V_3 ) ,
void * V_3 )
{
unsigned long V_4 ;
char V_5 [ 256 ] ;
char V_6 [ 4096 ] ;
const char * V_7 , * V_8 ;
int line , V_9 ;
unsigned long V_10 ;
T_2 V_11 ;
F_3 ( & V_11 ) ;
V_10 = F_4 ( & V_11 ) ;
while ( ( V_4 = F_5 ( & V_7 , & line , & V_8 , & V_9 ) ) != 0 ) {
F_6 ( V_4 , V_5 , sizeof V_5 ) ;
F_7 ( V_6 , sizeof( V_6 ) , L_1 , V_10 , V_5 ,
V_7 , line , ( V_9 & V_12 ) ? V_8 : L_2 ) ;
if ( F_2 ( V_6 , strlen ( V_6 ) , V_3 ) <= 0 )
break;
}
}
static int F_8 ( const char * V_1 , T_1 V_2 , void * V_13 )
{
T_3 V_14 ;
F_9 ( & V_14 , F_10 () ) ;
F_11 ( & V_14 , V_13 , V_15 ) ;
return F_12 ( & V_14 , L_3 , V_1 ) ;
}
void F_13 ( T_4 * V_13 )
{
F_1 ( F_8 , V_13 ) ;
}
static int F_14 ( const char * V_1 , T_1 V_2 , void * V_16 )
{
return F_15 ( ( T_3 * ) V_16 , V_1 , V_2 ) ;
}
void F_16 ( T_3 * V_16 )
{
F_1 ( F_14 , V_16 ) ;
}
