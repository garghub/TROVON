static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_8 = F_5 ( V_3 ) ;
if ( ( V_8 == V_9 ) && ( V_5 == 0 ) )
return ( V_7 -> V_10 [ 0 ] - 50 ) * 1000 ;
return V_7 -> V_10 [ V_5 ] * 1000 ;
}
static int F_6 ( struct V_1 * V_4 ,
struct V_6 * V_11 ,
int V_12 , int V_13 ,
unsigned * V_5 )
{
int V_14 , V_15 ;
T_1 V_16 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_17 . V_18 ; V_14 ++ ) {
V_15 = V_11 -> V_10 [ V_14 ] * 1000 ;
if ( V_11 -> V_17 . V_19 == V_9 && V_14 == 0 )
V_15 -= 50 * 1000 ;
if ( V_12 <= V_15 && V_15 <= V_13 ) {
* V_5 = V_14 ;
V_14 <<= V_11 -> V_20 ;
V_16 = ( ( 1 << V_11 -> V_21 ) - 1 ) << V_11 -> V_20 ;
return F_7 ( V_4 , V_11 -> V_22 , V_14 , V_16 ) ;
}
}
return - V_23 ;
}
static int F_8 ( struct V_2 * V_3 ,
int V_12 , int V_13 , unsigned * V_5 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_6 ( V_4 , V_11 , V_12 , V_13 ,
V_5 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_14 , V_16 ;
int V_24 ;
V_24 = F_10 ( V_4 , V_11 -> V_22 , & V_14 ) ;
if ( V_24 )
return V_24 ;
V_16 = ( ( 1 << V_11 -> V_21 ) - 1 ) << V_11 -> V_20 ;
V_14 = ( V_14 & V_16 ) >> V_11 -> V_20 ;
if ( V_14 >= V_11 -> V_17 . V_18 )
F_11 () ;
return V_11 -> V_10 [ V_14 ] * 1000 ;
}
static int F_12 ( struct V_2 * V_3 ,
int V_12 , int V_13 , unsigned * V_5 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_24 ;
V_24 = F_6 ( V_4 , V_11 , V_12 , V_13 ,
V_5 ) ;
if ( V_24 )
return V_24 ;
return F_13 ( V_4 , V_11 -> V_25 , 1 << V_11 -> V_26 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_13 ( V_4 , V_11 -> V_27 [ 0 ] ,
1 << V_11 -> V_28 [ 0 ] ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_16 ( V_4 , V_11 -> V_27 [ 0 ] ,
1 << V_11 -> V_28 [ 0 ] ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_29 ;
int V_24 ;
V_24 = F_10 ( V_4 , V_11 -> V_27 [ 0 ] , & V_29 ) ;
if ( V_24 )
return V_24 ;
return ! ! ( V_29 & ( 1 << V_11 -> V_28 [ 0 ] ) ) ;
}
static inline int F_18 ( struct V_1 * V_4 ,
struct V_6 * V_11 )
{
T_1 V_30 , V_31 ;
int V_24 ;
if ( V_11 -> V_27 [ 0 ] == V_11 -> V_27 [ 1 ] &&
V_11 -> V_28 [ 0 ] == V_11 -> V_28 [ 1 ] )
return 0 ;
V_24 = F_10 ( V_4 , V_11 -> V_27 [ 0 ] , & V_30 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_10 ( V_4 , V_11 -> V_27 [ 1 ] , & V_31 ) ;
if ( V_24 )
return V_24 ;
if ( ! ( V_31 & ( 1 << V_11 -> V_28 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_30 & ( 1 << V_11 -> V_28 [ 0 ] ) ) ) {
V_24 = F_13 ( V_4 , V_11 -> V_27 [ 0 ] ,
1 << V_11 -> V_28 [ 0 ] ) ;
if ( V_24 )
return V_24 ;
}
return F_16 ( V_4 , V_11 -> V_27 [ 1 ] ,
1 << V_11 -> V_28 [ 1 ] ) ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_1 * V_4 = V_33 -> V_34 . V_4 ;
struct V_35 * V_36 = V_33 -> V_34 . V_37 ;
struct V_38 * V_39 = V_36 -> V_40 ;
T_1 V_41 ;
if ( V_39 == NULL )
return 0 ;
if ( ! ( V_39 -> V_42 & V_43 ) )
return 0 ;
switch ( V_33 -> V_19 ) {
case V_44 :
V_41 = V_45 ;
break;
case V_46 :
V_41 = V_47 ;
break;
default:
F_20 ( & V_33 -> V_34 , L_1 ) ;
return - V_23 ;
}
return F_21 ( V_4 , V_41 ,
V_39 -> V_42 & V_48 ) ;
}
static inline struct V_6 * F_22 ( int V_19 )
{
struct V_6 * V_11 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_23 ( V_6 ) ; V_49 ++ ) {
V_11 = & V_6 [ V_49 ] ;
if ( V_11 -> V_17 . V_19 == V_19 )
return V_11 ;
}
return NULL ;
}
static int T_2 F_24 ( struct V_32 * V_33 )
{
struct V_6 * V_11 = NULL ;
struct V_2 * V_3 ;
int V_19 = V_33 -> V_19 ;
int V_50 ;
F_25 ( & V_33 -> V_34 , L_2 , V_19 ) ;
V_11 = F_22 ( V_19 ) ;
if ( V_11 == NULL ) {
F_26 ( & V_33 -> V_34 , L_3 ) ;
return - V_23 ;
}
V_50 = F_18 ( V_33 -> V_34 . V_4 , V_11 ) ;
if ( V_50 )
return V_50 ;
V_3 = F_27 ( & V_11 -> V_17 , & V_33 -> V_34 ,
V_33 -> V_34 . V_37 , V_11 , NULL ) ;
if ( F_28 ( V_3 ) ) {
F_26 ( & V_33 -> V_34 , L_4 ,
V_11 -> V_17 . V_51 ) ;
return F_29 ( V_3 ) ;
}
F_30 ( V_33 , V_3 ) ;
return F_19 ( V_33 ) ;
}
static int T_3 F_31 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = F_32 ( V_33 ) ;
F_33 ( V_3 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_52 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_52 ) ;
}
