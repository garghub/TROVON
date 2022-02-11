int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 ;
V_5 = V_3 - V_6 + V_7 ;
return F_2 ( V_2 , V_5 , 0x07 , V_4 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_5 , V_4 ;
V_5 = V_3 - V_6 + V_7 ;
V_4 = F_4 ( V_2 , V_5 ) & 0x07 ;
return V_4 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , int V_8 )
{
T_1 V_4 , V_5 ;
V_5 = V_3 - V_6 + V_7 ;
V_4 = ! ! V_8 << 3 ;
return F_2 ( V_2 , V_5 , 1 << 3 , V_4 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_5 , V_4 ;
V_5 = V_3 - V_6 + V_7 ;
V_4 = F_4 ( V_2 , V_5 ) ;
return V_4 & ( 1 << 3 ) ;
}
int F_7 ( struct V_1 * V_2 ,
int V_3 , int V_9 , int V_10 )
{
T_1 V_5 , V_4 , V_11 ;
V_5 = V_12 [ V_9 ] + 1 ;
V_4 = ! ! V_10 << ( V_3 - V_6 ) ;
V_11 = 1 << ( V_3 - V_6 ) ;
return F_2 ( V_2 , V_5 , V_11 , V_4 ) ;
}
