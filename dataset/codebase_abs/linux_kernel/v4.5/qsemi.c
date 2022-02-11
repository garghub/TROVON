static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0x0dc0 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_4 ( V_2 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_8 == V_9 )
V_4 = F_2 ( V_2 , V_10 ,
V_11 ) ;
else
V_4 = F_2 ( V_2 , V_10 , 0 ) ;
return V_4 ;
}
