static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_2 -> V_7 = & V_8 [ 0 ] ;
V_5 -> V_9 |= V_10 |
V_11 | V_12 ;
V_6 = F_3 ( V_2 , NULL ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_13 = V_5 -> V_14 [ 0 ] -> V_15 ;
if ( ! V_5 -> V_16 )
return - V_17 ;
return F_4 ( V_2 , V_5 -> V_16 , V_18 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , & V_19 ) ;
}
