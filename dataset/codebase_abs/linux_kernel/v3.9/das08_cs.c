static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_9 ;
V_2 -> V_10 = & V_11 [ 0 ] ;
V_5 -> V_12 |= V_13 ;
V_9 = F_3 ( V_2 , NULL ) ;
if ( V_9 )
return V_9 ;
V_8 = V_5 -> V_14 [ 0 ] -> V_15 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return - V_17 ;
V_2 -> V_18 = V_7 ;
return F_5 ( V_2 , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
return F_10 ( V_5 , & V_19 ) ;
}
