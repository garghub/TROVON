static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , V_6 ,
F_5 () ) ) ;
}
static struct V_2 *
F_6 ( struct V_2 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return F_8 ( - V_10 ) ;
return & V_8 -> V_3 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 -> V_11 ) ;
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
if ( V_18 ) {
F_14 ( & V_19 ) ;
F_15 ( & V_18 -> V_20 -> V_21 ,
( unsigned long ) V_13 ) ;
F_16 ( & V_19 ) ;
}
return 0 ;
}
static void F_17 ( struct V_22 * V_23 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
F_18 (p, css, tset) {
F_19 ( V_5 ) ;
F_20 ( V_5 -> V_24 , 0 , F_12 ,
( void * ) ( unsigned long ) F_1 ( V_3 ) -> V_12 ) ;
F_21 ( V_5 ) ;
}
}
static T_1 F_22 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
return F_1 ( V_3 ) -> V_12 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_25 * V_26 ,
T_1 V_27 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_28 V_29 ;
struct V_4 * V_5 ;
F_24 () ;
V_8 -> V_12 = ( V_30 ) V_27 ;
F_25 ( V_3 , 0 , & V_29 ) ;
while ( ( V_5 = F_26 ( & V_29 ) ) ) {
F_19 ( V_5 ) ;
F_20 ( V_5 -> V_24 , 0 , F_12 ,
( void * ) ( unsigned long ) V_8 -> V_12 ) ;
F_21 ( V_5 ) ;
}
F_27 ( & V_29 ) ;
return 0 ;
}
