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
static int F_18 ( struct V_31 * V_32 )
{
struct V_1 * V_4 = V_32 -> V_33 . V_4 ;
struct V_34 * V_35 = V_32 -> V_33 . V_36 ;
struct V_37 * V_38 = V_35 -> V_39 ;
T_1 V_40 ;
if ( V_38 == NULL )
return 0 ;
if ( ! ( V_38 -> V_41 & V_42 ) )
return 0 ;
switch ( V_32 -> V_17 ) {
case V_43 :
V_40 = V_44 ;
break;
case V_45 :
V_40 = V_46 ;
break;
default:
F_19 ( & V_32 -> V_33 , L_1 ) ;
return - V_22 ;
}
return F_20 ( V_4 , V_40 ,
V_38 -> V_41 & V_47 ) ;
}
static inline struct V_6 * F_21 ( int V_17 )
{
struct V_6 * V_9 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < F_22 ( V_6 ) ; V_48 ++ ) {
V_9 = & V_6 [ V_48 ] ;
if ( V_9 -> V_15 . V_17 == V_17 )
return V_9 ;
}
return NULL ;
}
static int T_2 F_23 ( struct V_31 * V_32 )
{
struct V_6 * V_9 = NULL ;
struct V_2 * V_3 ;
int V_17 = V_32 -> V_17 ;
int V_49 ;
F_24 ( & V_32 -> V_33 , L_2 , V_17 ) ;
V_9 = F_21 ( V_17 ) ;
if ( V_9 == NULL ) {
F_25 ( & V_32 -> V_33 , L_3 ) ;
return - V_22 ;
}
V_49 = F_17 ( V_32 -> V_33 . V_4 , V_9 ) ;
if ( V_49 )
return V_49 ;
V_3 = F_26 ( & V_9 -> V_15 , & V_32 -> V_33 ,
V_32 -> V_33 . V_36 , V_9 ) ;
if ( F_27 ( V_3 ) ) {
F_25 ( & V_32 -> V_33 , L_4 ,
V_9 -> V_15 . V_50 ) ;
return F_28 ( V_3 ) ;
}
F_29 ( V_32 , V_3 ) ;
return F_18 ( V_32 ) ;
}
static int T_3 F_30 ( struct V_31 * V_32 )
{
struct V_2 * V_3 = F_31 ( V_32 ) ;
F_32 ( V_3 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
return F_34 ( & V_51 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_51 ) ;
}
