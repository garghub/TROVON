static struct V_1 * T_1 F_1 ( const char * V_2 ,
T_2 V_3 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 ,
. V_7 = V_3 + V_8 - 1 ,
. V_9 = V_10 ,
}
} ;
return F_2 ( V_2 , - 1 ,
V_5 , F_3 ( V_5 ) , NULL , 0 ,
F_4 ( 32 ) ) ;
}
static int T_1 F_5 ( void )
{
char * V_11 = L_1 ;
char * V_12 = L_2 ;
if ( F_6 () ) {
F_1 ( V_11 , V_13 ) ;
F_1 ( V_12 , V_14 ) ;
}
if ( F_7 () ) {
F_1 ( V_11 , V_15 ) ;
F_1 ( V_12 , V_16 ) ;
}
return 0 ;
}
