static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_8 ;
V_2 -> V_9 = & V_10 [ 0 ] ;
V_5 -> V_11 |= V_12 |
V_13 | V_14 ;
V_8 = F_3 ( V_2 , NULL ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_15 = V_5 -> V_16 [ 0 ] -> V_17 ;
if ( ! V_5 -> V_18 )
return - V_19 ;
V_7 = F_4 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_20 ;
return F_5 ( V_2 , V_5 -> V_18 , V_21 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
return F_7 ( V_5 , & V_22 ) ;
}
