static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 -> V_7 -> V_8 ( & V_6 -> V_5 . V_3 ) ;
}
static int F_5 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned long V_10 = 0 ;
T_2 V_11 ;
F_6 ( V_5 -> V_12 , V_10 ) ;
V_11 = F_7 ( V_5 -> V_13 ) ;
V_11 &= ~ ( V_5 -> V_14 << V_5 -> V_15 ) ;
V_11 |= V_9 << V_5 -> V_15 ;
V_6 -> V_16 ( & V_11 ) ;
F_8 ( V_11 , V_5 -> V_13 ) ;
F_9 ( V_5 -> V_12 , V_10 ) ;
return 0 ;
}
struct V_17 * F_10 ( const char * V_18 , void T_3 * V_13 ,
T_1 V_15 , T_1 V_19 , const char * * V_20 ,
int V_21 , void (* V_16)( T_2 * V_11 ) )
{
struct V_1 * V_6 ;
struct V_17 * V_17 ;
struct V_22 V_23 ;
if ( ! V_16 )
return F_11 ( - V_24 ) ;
V_6 = F_12 ( sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return F_11 ( - V_26 ) ;
V_23 . V_18 = V_18 ;
V_23 . V_7 = & V_27 ;
V_23 . V_28 = V_20 ;
V_23 . V_21 = V_21 ;
V_23 . V_10 = 0 ;
V_6 -> V_5 . V_13 = V_13 ;
V_6 -> V_5 . V_15 = V_15 ;
V_6 -> V_5 . V_14 = F_13 ( V_19 ) - 1 ;
V_6 -> V_5 . V_12 = & V_29 ;
V_6 -> V_5 . V_3 . V_23 = & V_23 ;
V_6 -> V_7 = & V_30 ;
V_6 -> V_16 = V_16 ;
V_17 = F_14 ( NULL , & V_6 -> V_5 . V_3 ) ;
if ( F_15 ( V_17 ) )
F_16 ( V_6 ) ;
return V_17 ;
}
