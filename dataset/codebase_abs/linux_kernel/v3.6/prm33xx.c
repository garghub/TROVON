T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( V_3 + V_1 + V_2 ) ;
}
void F_3 ( T_1 V_4 , T_2 V_1 , T_3 V_2 )
{
F_4 ( V_4 , V_3 + V_1 + V_2 ) ;
}
T_1 F_5 ( T_1 V_5 , T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_3 ( V_7 , V_1 , V_2 ) ;
return V_7 ;
}
int F_6 ( T_4 V_8 , T_2 V_1 , T_3 V_9 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_9 ) ;
V_7 &= 1 << V_8 ;
V_7 >>= V_8 ;
return V_7 ;
}
int F_7 ( T_4 V_8 , T_2 V_1 , T_3 V_9 )
{
T_1 V_5 = 1 << V_8 ;
F_5 ( V_5 , V_5 , V_1 , V_9 ) ;
return 0 ;
}
int F_8 ( T_4 V_8 , T_2 V_1 ,
T_3 V_9 , T_3 V_10 )
{
int V_11 ;
T_1 V_5 = 1 << V_8 ;
if ( F_6 ( V_8 , V_1 , V_9 ) == 0 )
return - V_12 ;
F_5 ( 0xffffffff , V_5 , V_1 , V_10 ) ;
F_5 ( V_5 , 0 , V_1 , V_9 ) ;
F_9 ( F_6 ( V_8 , V_1 ,
V_10 ) ,
V_13 , V_11 ) ;
return ( V_11 == V_13 ) ? - V_14 : 0 ;
}
