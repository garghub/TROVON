static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_3 * V_5 -> V_6 / V_5 -> div ;
}
static long F_3 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_4 ( V_2 -> V_9 ) & V_10 ) {
unsigned long V_11 ;
V_11 = ( V_7 / V_5 -> V_6 ) * V_5 -> div ;
* V_8 = F_5 ( F_6 ( V_2 -> V_9 ) ,
V_11 ) ;
}
return ( * V_8 / V_5 -> div ) * V_5 -> V_6 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_3 )
{
return 0 ;
}
struct V_9 * F_8 ( struct V_12 * V_13 , const char * V_14 ,
const char * V_15 , unsigned long V_16 ,
unsigned int V_6 , unsigned int div )
{
struct V_4 * V_5 ;
struct V_17 V_18 ;
struct V_9 * V_9 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 ) {
F_10 ( L_1 , V_20 ) ;
return F_11 ( - V_21 ) ;
}
V_5 -> V_6 = V_6 ;
V_5 -> div = div ;
V_5 -> V_2 . V_18 = & V_18 ;
V_18 . V_14 = V_14 ;
V_18 . V_22 = & V_23 ;
V_18 . V_16 = V_16 ;
V_18 . V_24 = & V_15 ;
V_18 . V_25 = 1 ;
V_9 = F_12 ( V_13 , & V_5 -> V_2 ) ;
if ( F_13 ( V_9 ) )
F_14 ( V_5 ) ;
return V_9 ;
}
