static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , V_6 ) ) ;
}
static struct V_2 *
F_5 ( struct V_2 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_6 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return F_7 ( - V_10 ) ;
return & V_8 -> V_3 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( F_9 ( V_3 ) ) ;
if ( V_11 )
V_8 -> V_12 = V_11 -> V_12 ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_11 ( F_1 ( V_3 ) ) ;
}
static int F_12 ( const void * V_13 , struct V_14 * V_14 , unsigned V_15 )
{
int V_16 ;
struct V_17 * V_18 = F_13 ( V_14 , & V_16 ) ;
if ( V_18 )
V_18 -> V_19 -> V_20 = ( V_21 ) ( unsigned long ) V_13 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
void * V_13 = ( void * ) ( unsigned long ) V_8 -> V_12 ;
struct V_4 * V_5 ;
F_15 (p, tset) {
F_16 ( V_5 ) ;
F_17 ( V_5 -> V_24 , 0 , F_12 , V_13 ) ;
F_18 ( V_5 ) ;
}
}
static T_1 F_19 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
return F_1 ( V_3 ) -> V_12 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_25 * V_26 ,
T_1 V_27 )
{
F_1 ( V_3 ) -> V_12 = ( V_21 ) V_27 ;
return 0 ;
}
