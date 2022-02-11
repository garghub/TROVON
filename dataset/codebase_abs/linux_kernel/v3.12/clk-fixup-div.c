static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static unsigned long F_4 ( struct V_2 * V_3 ,
unsigned long V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_8 -> V_9 ( & V_7 -> V_5 . V_3 , V_6 ) ;
}
static long F_5 ( struct V_2 * V_3 , unsigned long V_10 ,
unsigned long * V_11 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_8 -> V_12 ( & V_7 -> V_5 . V_3 , V_10 , V_11 ) ;
}
static int F_6 ( struct V_2 * V_3 , unsigned long V_10 ,
unsigned long V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * div = F_2 ( V_3 ) ;
unsigned int V_5 , V_13 ;
unsigned long V_14 = 0 ;
T_1 V_15 ;
V_5 = V_6 / V_10 ;
V_13 = V_5 - 1 ;
if ( V_13 > F_7 ( div ) )
V_13 = F_7 ( div ) ;
F_8 ( div -> V_16 , V_14 ) ;
V_15 = F_9 ( div -> V_17 ) ;
V_15 &= ~ ( F_7 ( div ) << div -> V_18 ) ;
V_15 |= V_13 << div -> V_18 ;
V_7 -> V_19 ( & V_15 ) ;
F_10 ( V_15 , div -> V_17 ) ;
F_11 ( div -> V_16 , V_14 ) ;
return 0 ;
}
struct V_20 * F_12 ( const char * V_21 , const char * V_22 ,
void T_2 * V_17 , T_3 V_18 , T_3 V_23 ,
void (* V_19)( T_1 * V_15 ) )
{
struct V_1 * V_7 ;
struct V_20 * V_20 ;
struct V_24 V_25 ;
if ( ! V_19 )
return F_13 ( - V_26 ) ;
V_7 = F_14 ( sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return F_13 ( - V_28 ) ;
V_25 . V_21 = V_21 ;
V_25 . V_8 = & V_29 ;
V_25 . V_14 = V_30 ;
V_25 . V_31 = V_22 ? & V_22 : NULL ;
V_25 . V_32 = V_22 ? 1 : 0 ;
V_7 -> V_5 . V_17 = V_17 ;
V_7 -> V_5 . V_18 = V_18 ;
V_7 -> V_5 . V_23 = V_23 ;
V_7 -> V_5 . V_16 = & V_33 ;
V_7 -> V_5 . V_3 . V_25 = & V_25 ;
V_7 -> V_8 = & V_34 ;
V_7 -> V_19 = V_19 ;
V_20 = F_15 ( NULL , & V_7 -> V_5 . V_3 ) ;
if ( F_16 ( V_20 ) )
F_17 ( V_7 ) ;
return V_20 ;
}
