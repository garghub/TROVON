static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_5 = 1 << ( V_4 -> V_6 % 32 ) , V_7 ;
V_7 = F_4 ( V_4 -> V_8 + V_4 -> V_9 -> V_10 ) ;
if ( V_7 & V_5 ) {
V_7 = F_4 ( V_4 -> V_8 + V_4 -> V_9 -> V_11 ) ;
if ( ( V_7 & V_5 ) == 0 )
return 1 ;
}
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_5 = 1 << ( V_4 -> V_6 % 32 ) ;
F_6 ( V_5 , V_4 -> V_8 + V_4 -> V_9 -> V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_5 = 1 << ( V_4 -> V_6 % 32 ) ;
F_6 ( V_5 , V_4 -> V_8 + V_4 -> V_9 -> V_13 ) ;
}
static unsigned long
F_8 ( struct V_2 * V_3 ,
unsigned long V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long long V_15 ;
V_15 = ( unsigned long long ) V_14 * V_4 -> V_16 ;
F_9 ( V_15 , V_4 -> div ) ;
return ( unsigned long ) V_15 ;
}
struct V_17 * F_10 ( const char * V_18 ,
const char * V_19 ,
unsigned long V_20 ,
void T_2 * V_8 ,
unsigned int V_16 ,
unsigned int div ,
unsigned int V_6 )
{
const struct V_21 * V_9 ;
struct V_1 * V_4 ;
struct V_22 V_23 ;
struct V_17 * V_17 ;
V_9 = F_11 ( V_6 ) ;
if ( ! V_9 )
return F_12 ( - V_24 ) ;
V_4 = F_13 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return F_12 ( - V_26 ) ;
V_23 . V_18 = V_18 ;
V_23 . V_20 = V_20 ;
V_23 . V_27 = V_19 ? & V_19 : NULL ;
V_23 . V_28 = V_19 ? 1 : 0 ;
V_23 . V_29 = & V_30 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_16 = V_16 ;
V_4 -> div = div ;
V_4 -> V_6 = V_6 ;
V_4 -> V_3 . V_23 = & V_23 ;
V_17 = F_14 ( NULL , & V_4 -> V_3 ) ;
if ( F_15 ( V_17 ) )
F_16 ( V_4 ) ;
return V_17 ;
}
