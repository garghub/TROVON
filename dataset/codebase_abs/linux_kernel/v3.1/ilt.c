void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 () ;
F_2 ( V_2 , V_6 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 () ;
F_2 ( V_2 , V_7 ,
( V_4 & 0xFFFF0000 ) >> 16 ) ;
F_2 ( V_2 , V_6 ,
V_4 & 0x0000FFFF ) ;
}
T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
return F_6 ( V_2 , V_6 ) ;
}
