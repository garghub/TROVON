static void T_1 F_1 ( struct V_1 * V_2 )
{
void T_2 * V_3 ;
T_3 V_4 ;
V_3 = F_2 ( V_2 , 0 , F_3 ( V_2 ) ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( L_1 , V_2 ) ;
return;
}
V_4 = F_6 ( V_3 + V_5 ) ;
V_4 &= ~ F_7 ( 19 , 16 ) ;
F_8 ( V_4 | ( 3 << 16 ) , V_3 + V_5 ) ;
F_9 ( V_2 , V_3 , & V_6 ) ;
}
