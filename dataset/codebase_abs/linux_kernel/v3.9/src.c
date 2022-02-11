void F_1 ( int V_1 , bool V_2 )
{
T_1 V_3 , V_4 ;
V_1 = F_2 ( V_1 ) ;
V_3 = 1 << ( V_5 + V_1 - 1 ) ;
V_4 = F_3 ( V_6 + V_7 ) ;
V_4 = V_2 ? V_4 | V_3 : V_4 & ~ V_3 ;
F_4 ( V_4 , V_6 + V_7 ) ;
}
void F_5 ( int V_1 , void * V_8 )
{
V_1 = F_2 ( V_1 ) ;
F_4 ( F_6 ( V_8 ) ,
V_6 + V_9 + V_1 * 8 ) ;
}
T_1 F_7 ( int V_1 )
{
V_1 = F_2 ( V_1 ) ;
return F_3 ( V_6 + V_9 + V_1 * 8 + 4 ) ;
}
void F_8 ( int V_1 , T_1 V_10 )
{
V_1 = F_2 ( V_1 ) ;
F_4 ( V_10 , V_6 + V_9 + V_1 * 8 + 4 ) ;
}
void F_9 ( void )
{
T_1 V_4 ;
V_4 = F_3 ( V_6 + V_7 ) ;
V_4 &= ~ ( 0x7 << V_5 ) ;
F_4 ( V_4 , V_6 + V_7 ) ;
F_4 ( 0 , V_6 + V_9 ) ;
}
void T_2 F_10 ( void )
{
struct V_11 * V_12 ;
T_1 V_4 ;
V_12 = F_11 ( NULL , NULL , L_1 ) ;
V_6 = F_12 ( V_12 , 0 ) ;
F_13 ( ! V_6 ) ;
V_4 = F_3 ( V_6 + V_7 ) ;
V_4 &= ~ ( 1 << V_13 ) ;
F_4 ( V_4 , V_6 + V_7 ) ;
}
