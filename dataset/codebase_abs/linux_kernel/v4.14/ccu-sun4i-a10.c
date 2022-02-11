static void T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
void T_2 * V_5 ;
T_3 V_6 ;
V_5 = F_2 ( V_2 , 0 , F_3 ( V_2 ) ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_1 ,
F_3 ( V_2 ) ) ;
return;
}
V_6 = F_6 ( V_5 + V_7 ) ;
V_6 &= ~ F_7 ( 29 , 26 ) ;
F_8 ( V_6 | ( 4 << 26 ) , V_5 + V_7 ) ;
V_6 = F_6 ( V_5 + V_8 ) ;
V_6 &= ~ F_7 ( 7 , 6 ) ;
F_8 ( V_6 | ( 2 << 6 ) , V_5 + V_8 ) ;
F_9 ( V_2 , V_5 , V_4 ) ;
}
static void T_1 F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 , & V_9 ) ;
}
static void T_1 F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , & V_10 ) ;
}
