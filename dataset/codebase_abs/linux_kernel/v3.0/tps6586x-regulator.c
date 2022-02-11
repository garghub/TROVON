static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return V_7 -> V_8 [ V_5 ] * 1000 ;
}
static int F_5 ( struct V_1 * V_4 ,
struct V_6 * V_9 ,
int V_10 , int V_11 ,
unsigned * V_5 )
{
int V_12 , V_13 ;
T_1 V_14 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_15 . V_16 ; V_12 ++ ) {
V_13 = V_9 -> V_8 [ V_12 ] * 1000 ;
if ( V_9 -> V_15 . V_17 == V_18 && V_12 == 0 )
V_13 -= 50 * 1000 ;
if ( V_10 <= V_13 && V_13 <= V_11 ) {
* V_5 = V_12 ;
V_12 <<= V_9 -> V_19 ;
V_14 = ( ( 1 << V_9 -> V_20 ) - 1 ) << V_9 -> V_19 ;
return F_6 ( V_4 , V_9 -> V_21 , V_12 , V_14 ) ;
}
}
return - V_22 ;
}
static int F_7 ( struct V_2 * V_3 ,
int V_10 , int V_11 , unsigned * V_5 )
{
struct V_6 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_5 ( V_4 , V_9 , V_10 , V_11 ,
V_5 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_12 , V_14 ;
int V_23 ;
V_23 = F_9 ( V_4 , V_9 -> V_21 , & V_12 ) ;
if ( V_23 )
return V_23 ;
V_14 = ( ( 1 << V_9 -> V_20 ) - 1 ) << V_9 -> V_19 ;
V_12 = ( V_12 & V_14 ) >> V_9 -> V_19 ;
if ( V_12 >= V_9 -> V_15 . V_16 )
F_10 () ;
return V_9 -> V_8 [ V_12 ] * 1000 ;
}
static int F_11 ( struct V_2 * V_3 ,
int V_10 , int V_11 , unsigned * V_5 )
{
struct V_6 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_23 ;
V_23 = F_5 ( V_4 , V_9 , V_10 , V_11 ,
V_5 ) ;
if ( V_23 )
return V_23 ;
return F_12 ( V_4 , V_9 -> V_24 , 1 << V_9 -> V_25 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_6 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_12 ( V_4 , V_9 -> V_26 [ 0 ] ,
1 << V_9 -> V_27 [ 0 ] ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_6 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_15 ( V_4 , V_9 -> V_26 [ 0 ] ,
1 << V_9 -> V_27 [ 0 ] ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_6 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_28 ;
int V_23 ;
V_23 = F_9 ( V_4 , V_9 -> V_26 [ 0 ] , & V_28 ) ;
if ( V_23 )
return V_23 ;
return ! ! ( V_28 & ( 1 << V_9 -> V_27 [ 0 ] ) ) ;
}
static inline int F_17 ( struct V_1 * V_4 ,
struct V_6 * V_9 )
{
T_1 V_29 , V_30 ;
int V_23 ;
if ( V_9 -> V_26 [ 0 ] == V_9 -> V_26 [ 1 ] &&
V_9 -> V_27 [ 0 ] == V_9 -> V_27 [ 1 ] )
return 0 ;
V_23 = F_9 ( V_4 , V_9 -> V_26 [ 0 ] , & V_29 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_9 ( V_4 , V_9 -> V_26 [ 1 ] , & V_30 ) ;
if ( V_23 )
return V_23 ;
if ( ! ( V_30 & ( 1 << V_9 -> V_27 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_29 & ( 1 << V_9 -> V_27 [ 0 ] ) ) ) {
V_23 = F_12 ( V_4 , V_9 -> V_26 [ 0 ] ,
1 << V_9 -> V_27 [ 0 ] ) ;
if ( V_23 )
return V_23 ;
}
return F_15 ( V_4 , V_9 -> V_26 [ 1 ] ,
1 << V_9 -> V_27 [ 1 ] ) ;
}
static inline struct V_6 * F_18 ( int V_17 )
{
struct V_6 * V_9 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_19 ( V_6 ) ; V_31 ++ ) {
V_9 = & V_6 [ V_31 ] ;
if ( V_9 -> V_15 . V_17 == V_17 )
return V_9 ;
}
return NULL ;
}
static int T_2 F_20 ( struct V_32 * V_33 )
{
struct V_6 * V_9 = NULL ;
struct V_2 * V_3 ;
int V_17 = V_33 -> V_17 ;
int V_34 ;
F_21 ( & V_33 -> V_35 , L_1 , V_17 ) ;
V_9 = F_18 ( V_17 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_33 -> V_35 , L_2 ) ;
return - V_22 ;
}
V_34 = F_17 ( V_33 -> V_35 . V_4 , V_9 ) ;
if ( V_34 )
return V_34 ;
V_3 = F_23 ( & V_9 -> V_15 , & V_33 -> V_35 ,
V_33 -> V_35 . V_36 , V_9 ) ;
if ( F_24 ( V_3 ) ) {
F_22 ( & V_33 -> V_35 , L_3 ,
V_9 -> V_15 . V_37 ) ;
return F_25 ( V_3 ) ;
}
F_26 ( V_33 , V_3 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = F_28 ( V_33 ) ;
F_29 ( V_3 ) ;
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_38 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_38 ) ;
}
