static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 ;
return V_4 -> V_6 ;
}
static void F_2 ( struct V_7 * V_8 , T_2 V_6 ,
T_2 V_9 )
{
int V_10 ;
V_9 &= V_11 ;
V_6 &= V_9 ;
if ( V_9 == V_11 ) {
F_3 ( V_6 , V_8 -> V_12 ) ;
return;
}
if ( V_9 == 0 ) {
F_4 ( V_8 -> V_12 , ( 1 << V_13 ) ) ;
return;
}
for ( V_10 = 0 ; V_10 < ( 1 << V_13 ) ; V_10 ++ ) {
if ( ( V_10 & V_9 ) == V_6 )
F_3 ( V_10 , V_8 -> V_12 ) ;
}
}
static inline struct V_7 * F_5 ( struct V_14 * V_15 )
{
return (struct V_7 * ) V_15 -> V_5 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 = F_5 ( V_15 ) ;
T_1 V_6 ;
int V_18 = 0 ;
int V_10 ;
const struct V_19 * V_20 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 & V_21 ) {
for ( V_10 = 0 , V_20 = V_8 -> V_22 ;
V_10 < V_8 -> V_23 ; V_10 ++ , V_20 ++ ) {
if ( ! ( ( ( V_20 -> V_6 ^ V_6 ) & V_20 -> V_9 ) ) ) {
V_18 = 1 ;
break;
}
}
} else {
V_6 &= V_11 ;
V_18 = ( F_7 ( V_6 , V_8 -> V_12 ) ? 1 : 0 ) ;
}
return V_18 ;
}
static int F_8 ( struct V_24 * V_25 , void * V_5 , int V_26 ,
struct V_14 * V_15 )
{
struct V_19 * V_27 = V_5 ;
struct V_7 * V_8 ;
int V_10 ;
if ( ! V_26 )
return - V_28 ;
if ( V_26 % sizeof( struct V_19 ) )
return - V_28 ;
if ( V_26 > sizeof( struct V_19 ) * V_29 )
return - V_28 ;
V_8 = F_9 ( sizeof( struct V_7 ) + V_26 , V_30 ) ;
if ( ! V_8 )
return - V_31 ;
V_8 -> V_32 = V_26 / sizeof( struct V_19 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_32 ; V_10 ++ ) {
if ( V_27 [ V_10 ] . V_6 & V_21 ) {
memcpy ( V_8 -> V_22 + V_8 -> V_23 ,
& V_27 [ V_10 ] ,
sizeof( struct V_19 ) ) ;
V_8 -> V_23 ++ ;
}
}
for ( V_10 = 0 ; V_10 < V_8 -> V_32 ; V_10 ++ ) {
if ( ! ( V_27 [ V_10 ] . V_6 & V_21 ) ) {
memcpy ( V_8 -> V_22
+ V_8 -> V_23
+ V_8 -> V_33 ,
& V_27 [ V_10 ] , sizeof( struct V_19 ) ) ;
V_8 -> V_33 ++ ;
F_2 ( V_8 ,
V_27 [ V_10 ] . V_6 , V_27 [ V_10 ] . V_9 ) ;
}
}
V_15 -> V_34 = sizeof( struct V_7 ) + V_26 ;
V_15 -> V_5 = ( unsigned long ) V_8 ;
return 0 ;
}
static void F_10 ( struct V_24 * V_25 , struct V_14 * V_15 )
{
struct V_7 * V_8 = F_5 ( V_15 ) ;
F_11 ( V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_7 * V_8 = F_5 ( V_15 ) ;
if ( F_13 ( V_2 , sizeof( struct V_19 ) * V_8 -> V_32 ,
& V_8 -> V_22 ) < 0 )
return - V_35 ;
return 0 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_36 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_36 ) ;
}
