static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static unsigned long F_4 ( struct V_2 * V_3 ,
unsigned long V_6 )
{
struct V_1 * div = F_1 ( V_3 ) ;
return div -> V_7 -> V_8 ( & div -> V_5 . V_3 , V_6 ) ;
}
static long F_5 ( struct V_2 * V_3 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_1 * div = F_1 ( V_3 ) ;
return div -> V_7 -> V_11 ( & div -> V_5 . V_3 , V_9 , V_10 ) ;
}
static int F_6 ( struct V_2 * V_3 , unsigned long V_9 ,
unsigned long V_6 )
{
struct V_1 * div = F_1 ( V_3 ) ;
int V_12 ;
V_12 = div -> V_7 -> V_13 ( & div -> V_5 . V_3 , V_9 , V_6 ) ;
if ( ! V_12 )
V_12 = F_7 ( div -> V_14 , div -> V_15 ) ;
return V_12 ;
}
struct V_16 * F_8 ( const char * V_17 , const char * V_18 ,
void T_1 * V_14 , T_2 V_19 , T_2 V_20 , T_2 V_15 )
{
struct V_1 * div ;
struct V_16 * V_16 ;
struct V_21 V_22 ;
div = F_9 ( sizeof( * div ) , V_23 ) ;
if ( ! div )
return F_10 ( - V_24 ) ;
V_22 . V_17 = V_17 ;
V_22 . V_7 = & V_25 ;
V_22 . V_26 = V_27 ;
V_22 . V_28 = ( V_18 ? & V_18 : NULL ) ;
V_22 . V_29 = ( V_18 ? 1 : 0 ) ;
div -> V_14 = V_14 ;
div -> V_15 = V_15 ;
div -> V_5 . V_14 = V_14 ;
div -> V_5 . V_19 = V_19 ;
div -> V_5 . V_20 = V_20 ;
div -> V_5 . V_26 = V_30 ;
div -> V_5 . V_31 = & V_32 ;
div -> V_5 . V_3 . V_22 = & V_22 ;
div -> V_7 = & V_33 ;
V_16 = F_11 ( NULL , & div -> V_5 . V_3 ) ;
if ( F_12 ( V_16 ) )
F_13 ( div ) ;
return V_16 ;
}
