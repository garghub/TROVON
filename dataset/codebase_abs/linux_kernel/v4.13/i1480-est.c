static int T_1 F_1 ( void )
{
int V_1 = F_2 ( V_2 , 0x00 , 0x8086 , 0x0c3b ,
V_3 ,
F_3 ( V_3 ) ) ;
if ( V_1 < 0 ) {
F_4 ( V_4 L_1 , V_1 ) ;
return V_1 ;
}
V_1 = F_2 ( V_2 , 0x01 , 0x8086 , 0x0c3b ,
V_5 , F_3 ( V_5 ) ) ;
if ( V_1 < 0 ) {
F_4 ( V_4 L_2 , V_1 ) ;
return V_1 ;
}
return 0 ;
}
static void T_2 F_5 ( void )
{
F_6 ( V_2 , 0x00 , 0x8086 , 0x0c3b ,
V_3 , F_3 ( V_3 ) ) ;
F_6 ( V_2 , 0x01 , 0x8086 , 0x0c3b ,
V_5 , F_3 ( V_5 ) ) ;
}
