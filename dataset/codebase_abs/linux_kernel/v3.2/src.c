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
F_4 ( F_6 ( F_7 ( V_8 ) ) ,
V_6 + V_9 + V_1 * 8 ) ;
}
void T_2 F_8 ( void )
{
struct V_10 * V_11 ;
V_11 = F_9 ( NULL , NULL , L_1 ) ;
V_6 = F_10 ( V_11 , 0 ) ;
F_11 ( ! V_6 ) ;
}
