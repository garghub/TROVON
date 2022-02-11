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
V_6 &= ~ F_7 ( 19 , 16 ) ;
F_8 ( V_6 | ( 3 << 16 ) , V_5 + V_7 ) ;
F_9 ( V_2 , V_5 , V_4 ) ;
F_10 ( V_8 . V_9 . V_10 . V_11 ,
& V_12 ) ;
}
static void T_1 F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , & V_13 ) ;
}
static void T_1 F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 , & V_14 ) ;
}
