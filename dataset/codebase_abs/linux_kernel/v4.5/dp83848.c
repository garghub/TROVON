static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_5 == V_6 ) {
V_3 = F_4 ( V_2 , V_7 ,
V_8 |
V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_4 ,
V_10 |
V_11 |
V_12 |
V_13 ) ;
}
return F_4 ( V_2 , V_7 , 0x0 ) ;
}
