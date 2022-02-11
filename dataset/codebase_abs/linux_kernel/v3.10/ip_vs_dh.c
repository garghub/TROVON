static inline unsigned int F_1 ( int V_1 , const union V_2 * V_3 )
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
F_4 ( int V_1 , struct V_10 * V_11 , const union V_2 * V_3 )
{
return F_5 ( V_11 -> V_12 [ F_1 ( V_1 , V_3 ) ] . V_13 ) ;
}
static int
F_6 ( struct V_10 * V_11 , struct V_14 * V_15 )
{
int V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_9 * V_13 ;
bool V_21 ;
V_18 = & V_11 -> V_12 [ 0 ] ;
V_20 = & V_15 -> V_22 ;
V_21 = F_7 ( V_20 ) ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_13 = F_8 ( V_18 -> V_13 , 1 ) ;
if ( V_13 )
F_9 ( V_13 ) ;
if ( V_21 )
F_10 ( V_18 -> V_13 , NULL ) ;
else {
if ( V_20 == & V_15 -> V_22 )
V_20 = V_20 -> V_24 ;
V_13 = F_11 ( V_20 , struct V_9 , V_25 ) ;
F_12 ( V_13 ) ;
F_10 ( V_18 -> V_13 , V_13 ) ;
V_20 = V_20 -> V_24 ;
}
V_18 ++ ;
}
return 0 ;
}
static void F_13 ( struct V_10 * V_11 )
{
int V_16 ;
struct V_17 * V_18 ;
struct V_9 * V_13 ;
V_18 = & V_11 -> V_12 [ 0 ] ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_13 = F_8 ( V_18 -> V_13 , 1 ) ;
if ( V_13 ) {
F_9 ( V_13 ) ;
F_10 ( V_18 -> V_13 , NULL ) ;
}
V_18 ++ ;
}
}
static int F_14 ( struct V_14 * V_15 )
{
struct V_10 * V_11 ;
V_11 = F_15 ( sizeof( struct V_10 ) , V_26 ) ;
if ( V_11 == NULL )
return - V_27 ;
V_15 -> V_28 = V_11 ;
F_16 ( 6 , L_1
L_2 ,
sizeof( struct V_17 ) * V_23 ) ;
F_6 ( V_11 , V_15 ) ;
return 0 ;
}
static void F_17 ( struct V_14 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_28 ;
F_13 ( V_11 ) ;
F_18 ( V_11 , V_29 ) ;
F_16 ( 6 , L_3 ,
sizeof( struct V_17 ) * V_23 ) ;
}
static int F_19 ( struct V_14 * V_15 ,
struct V_9 * V_13 )
{
struct V_10 * V_11 = V_15 -> V_28 ;
F_6 ( V_11 , V_15 ) ;
return 0 ;
}
static inline int F_20 ( struct V_9 * V_13 )
{
return V_13 -> V_30 & V_31 ;
}
static struct V_9 *
F_21 ( struct V_14 * V_15 , const struct V_32 * V_33 )
{
struct V_9 * V_13 ;
struct V_10 * V_11 ;
struct V_34 V_35 ;
F_22 ( V_15 -> V_1 , V_33 , & V_35 ) ;
F_16 ( 6 , L_4 , V_36 ) ;
V_11 = (struct V_10 * ) V_15 -> V_28 ;
V_13 = F_4 ( V_15 -> V_1 , V_11 , & V_35 . V_37 ) ;
if ( ! V_13
|| ! ( V_13 -> V_30 & V_38 )
|| F_23 ( & V_13 -> V_39 ) <= 0
|| F_20 ( V_13 ) ) {
F_24 ( V_15 , L_5 ) ;
return NULL ;
}
F_25 ( 6 , L_6 ,
F_26 ( V_15 -> V_1 , & V_35 . V_37 ) ,
F_26 ( V_15 -> V_1 , & V_13 -> V_3 ) ,
F_27 ( V_13 -> V_40 ) ) ;
return V_13 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_41 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_41 ) ;
F_32 () ;
}
