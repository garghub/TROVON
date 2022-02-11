static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 ;
}
static long F_3 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long * V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_6 > V_5 -> V_8 )
return - V_9 ;
else
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 = V_6 ;
return 0 ;
}
struct V_10 * F_5 ( const char * V_11 ,
unsigned long V_6 , unsigned long V_8 )
{
struct V_4 * V_5 ;
struct V_12 V_13 ;
struct V_10 * V_10 ;
V_5 = F_6 ( sizeof( * V_5 ) , V_14 ) ;
if ( ! V_5 ) {
F_7 ( L_1 , V_15 ) ;
return F_8 ( - V_16 ) ;
}
V_5 -> V_6 = V_6 ;
V_5 -> V_8 = V_8 ;
V_13 . V_17 = & V_18 ;
V_13 . V_11 = V_11 ;
V_13 . V_19 = 0 ;
V_13 . V_20 = NULL ;
V_13 . V_21 = 0 ;
V_5 -> V_2 . V_13 = & V_13 ;
V_10 = F_9 ( NULL , & V_5 -> V_2 ) ;
if ( F_10 ( V_10 ) )
F_11 ( V_5 ) ;
return V_10 ;
}
