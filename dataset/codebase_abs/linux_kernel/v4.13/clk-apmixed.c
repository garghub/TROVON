static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return ( F_4 ( V_4 -> V_5 ) & V_6 ) == V_6 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_5 ) ;
V_7 |= V_8 ;
F_6 ( V_7 , V_4 -> V_5 ) ;
F_7 ( 100 ) ;
V_7 |= V_9 ;
F_6 ( V_7 , V_4 -> V_5 ) ;
V_7 |= V_10 ;
F_6 ( V_7 , V_4 -> V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_5 ) ;
V_7 &= ~ V_6 ;
F_6 ( V_7 , V_4 -> V_5 ) ;
}
struct V_11 * T_2 F_9 ( const char * V_12 ,
const char * V_13 , void T_3 * V_14 )
{
struct V_1 * V_4 ;
struct V_15 V_16 = {} ;
struct V_11 * V_11 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return F_11 ( - V_18 ) ;
V_4 -> V_5 = V_14 ;
V_4 -> V_3 . V_16 = & V_16 ;
V_16 . V_12 = V_12 ;
V_16 . V_19 = & V_20 ;
V_16 . V_21 = & V_13 ;
V_16 . V_22 = 1 ;
V_11 = F_12 ( NULL , & V_4 -> V_3 ) ;
if ( F_13 ( V_11 ) ) {
F_14 ( L_1 , V_12 , F_15 ( V_11 ) ) ;
F_16 ( V_4 ) ;
}
return V_11 ;
}
