static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_3 ( sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_2 -> V_11 = V_7 ;
V_2 -> V_12 = & V_13 [ 0 ] ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_14 = F_5 ( V_5 , 2 ) ;
return F_6 ( V_2 , V_2 -> V_14 ) ;
}
static int F_7 ( struct V_4 * V_2 ,
const struct V_15 * V_16 )
{
return F_8 ( V_2 , & V_17 ,
V_16 -> V_18 ) ;
}
