static int F_1 ( unsigned long V_1 , unsigned int V_2 ,
struct V_3 * V_4 )
{
if ( V_2 == 0x1c06 && V_5 ) {
V_5 = false ;
F_2 ( L_1 ,
V_1 , V_2 ) ;
return 0 ;
}
return 1 ;
}
static void T_1 F_3 ( void )
{
F_4 ( 16 + 6 , F_1 , V_6 , V_7 ,
L_2 ) ;
}
