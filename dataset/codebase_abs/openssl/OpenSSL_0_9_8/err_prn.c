void F_1 ( int (* F_2)( const char * V_1 , T_1 V_2 , void * V_3 ) ,
void * V_3 )
{
unsigned long V_4 ;
char V_5 [ 256 ] ;
char V_6 [ 4096 ] ;
const char * V_7 , * V_8 ;
int line , V_9 ;
unsigned long V_10 ;
V_10 = F_3 () ;
while ( ( V_4 = F_4 ( & V_7 , & line , & V_8 , & V_9 ) ) != 0 )
{
F_5 ( V_4 , V_5 , sizeof V_5 ) ;
F_6 ( V_6 , sizeof( V_6 ) , L_1 , V_10 , V_5 ,
V_7 , line , ( V_9 & V_11 ) ? V_8 : L_2 ) ;
F_2 ( V_6 , strlen ( V_6 ) , V_3 ) ;
}
}
static int F_7 ( const char * V_1 , T_1 V_2 , void * V_12 )
{
T_2 V_13 ;
F_8 ( & V_13 , F_9 () ) ;
F_10 ( & V_13 , V_12 , V_14 ) ;
return F_11 ( & V_13 , L_3 , V_1 ) ;
}
void F_12 ( T_3 * V_12 )
{
F_1 ( F_7 , V_12 ) ;
}
static int F_13 ( const char * V_1 , T_1 V_2 , void * V_15 )
{
return F_14 ( ( T_2 * ) V_15 , V_1 , V_2 ) ;
}
void F_15 ( T_2 * V_15 )
{
F_1 ( F_13 , V_15 ) ;
}
