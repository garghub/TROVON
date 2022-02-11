static inline unsigned F_1 ( int V_1 , const union V_2 * V_3 )
{
T_1 V_4 = V_3 -> V_5 ;
#ifdef F_2
if ( V_1 == V_6 )
V_4 = V_3 -> V_7 [ 0 ] ^ V_3 -> V_7 [ 1 ] ^
V_3 -> V_7 [ 2 ] ^ V_3 -> V_7 [ 3 ] ;
#endif
return ( F_3 ( V_4 ) * 2654435761UL ) & V_8 ;
}
static inline struct V_9 *
F_4 ( int V_1 , struct V_10 * V_11 ,
const union V_2 * V_3 )
{
return ( V_11 [ F_1 ( V_1 , V_3 ) ] ) . V_12 ;
}
static int
F_5 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
int V_15 ;
struct V_10 * V_16 ;
struct V_17 * V_18 ;
struct V_9 * V_12 ;
V_16 = V_11 ;
V_18 = & V_14 -> V_19 ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
if ( F_6 ( V_18 ) ) {
V_16 -> V_12 = NULL ;
} else {
if ( V_18 == & V_14 -> V_19 )
V_18 = V_18 -> V_21 ;
V_12 = F_7 ( V_18 , struct V_9 , V_22 ) ;
F_8 ( & V_12 -> V_23 ) ;
V_16 -> V_12 = V_12 ;
V_18 = V_18 -> V_21 ;
}
V_16 ++ ;
}
return 0 ;
}
static void F_9 ( struct V_10 * V_11 )
{
int V_15 ;
struct V_10 * V_16 ;
V_16 = V_11 ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
if ( V_16 -> V_12 ) {
F_10 ( & V_16 -> V_12 -> V_23 ) ;
V_16 -> V_12 = NULL ;
}
V_16 ++ ;
}
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_10 * V_11 ;
V_11 = F_12 ( sizeof( struct V_10 ) * V_20 ,
V_24 ) ;
if ( V_11 == NULL )
return - V_25 ;
V_14 -> V_26 = V_11 ;
F_13 ( 6 , L_1
L_2 ,
sizeof( struct V_10 ) * V_20 ) ;
F_5 ( V_11 , V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_26 ;
F_9 ( V_11 ) ;
F_15 ( V_14 -> V_26 ) ;
F_13 ( 6 , L_3 ,
sizeof( struct V_10 ) * V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_26 ;
F_9 ( V_11 ) ;
F_5 ( V_11 , V_14 ) ;
return 0 ;
}
static inline int F_17 ( struct V_9 * V_12 )
{
return V_12 -> V_27 & V_28 ;
}
static struct V_9 *
F_18 ( struct V_13 * V_14 , const struct V_29 * V_30 )
{
struct V_9 * V_12 ;
struct V_10 * V_11 ;
struct V_31 V_32 ;
F_19 ( V_14 -> V_1 , F_20 ( V_30 ) , & V_32 ) ;
F_13 ( 6 , L_4 , V_33 ) ;
V_11 = (struct V_10 * ) V_14 -> V_26 ;
V_12 = F_4 ( V_14 -> V_1 , V_11 , & V_32 . V_34 ) ;
if ( ! V_12
|| ! ( V_12 -> V_27 & V_35 )
|| F_21 ( & V_12 -> V_36 ) <= 0
|| F_17 ( V_12 ) ) {
return NULL ;
}
F_22 ( 6 , L_5 ,
F_23 ( V_14 -> V_1 , & V_32 . V_34 ) ,
F_23 ( V_14 -> V_1 , & V_12 -> V_3 ) ,
F_24 ( V_12 -> V_37 ) ) ;
return V_12 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_38 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_38 ) ;
}
