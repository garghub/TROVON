static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_8 = F_5 ( V_3 ) ;
if ( ( V_8 == V_9 ) && ( V_5 == 0 ) )
return ( V_7 -> V_10 [ 0 ] - 50 ) * 1000 ;
return V_7 -> V_10 [ V_5 ] * 1000 ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned V_5 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_12 , V_13 , V_8 = F_5 ( V_3 ) ;
T_1 V_14 ;
V_13 = V_5 << V_11 -> V_15 ;
V_14 = ( ( 1 << V_11 -> V_16 ) - 1 ) << V_11 -> V_15 ;
V_12 = F_7 ( V_4 , V_11 -> V_17 , V_13 , V_14 ) ;
if ( V_12 )
return V_12 ;
switch ( V_8 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_12 = F_8 ( V_4 , V_11 -> V_22 , 1 << V_11 -> V_23 ) ;
break;
}
return V_12 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_12 ;
V_12 = F_10 ( V_4 , V_11 -> V_17 , & V_13 ) ;
if ( V_12 )
return V_12 ;
V_14 = ( ( 1 << V_11 -> V_16 ) - 1 ) << V_11 -> V_15 ;
V_13 = ( V_13 & V_14 ) >> V_11 -> V_15 ;
if ( V_13 >= V_11 -> V_24 . V_25 )
F_11 () ;
return V_13 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_8 ( V_4 , V_11 -> V_26 [ 0 ] ,
1 << V_11 -> V_27 [ 0 ] ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_14 ( V_4 , V_11 -> V_26 [ 0 ] ,
1 << V_11 -> V_27 [ 0 ] ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_28 ;
int V_12 ;
V_12 = F_10 ( V_4 , V_11 -> V_26 [ 0 ] , & V_28 ) ;
if ( V_12 )
return V_12 ;
return ! ! ( V_28 & ( 1 << V_11 -> V_27 [ 0 ] ) ) ;
}
static inline int F_16 ( struct V_1 * V_4 ,
struct V_6 * V_11 )
{
T_1 V_29 , V_30 ;
int V_12 ;
if ( V_11 -> V_26 [ 0 ] == V_11 -> V_26 [ 1 ] &&
V_11 -> V_27 [ 0 ] == V_11 -> V_27 [ 1 ] )
return 0 ;
V_12 = F_10 ( V_4 , V_11 -> V_26 [ 0 ] , & V_29 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_10 ( V_4 , V_11 -> V_26 [ 1 ] , & V_30 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_30 & ( 1 << V_11 -> V_27 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_29 & ( 1 << V_11 -> V_27 [ 0 ] ) ) ) {
V_12 = F_8 ( V_4 , V_11 -> V_26 [ 0 ] ,
1 << V_11 -> V_27 [ 0 ] ) ;
if ( V_12 )
return V_12 ;
}
return F_14 ( V_4 , V_11 -> V_26 [ 1 ] ,
1 << V_11 -> V_27 [ 1 ] ) ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_1 * V_4 = V_32 -> V_33 . V_4 ;
struct V_34 * V_35 = V_32 -> V_33 . V_36 ;
struct V_37 * V_38 = V_35 -> V_39 ;
T_1 V_40 ;
if ( V_38 == NULL )
return 0 ;
if ( ! ( V_38 -> V_41 & V_42 ) )
return 0 ;
switch ( V_32 -> V_43 ) {
case V_20 :
V_40 = V_44 ;
break;
case V_21 :
V_40 = V_45 ;
break;
default:
F_18 ( & V_32 -> V_33 , L_1 ) ;
return - V_46 ;
}
return F_19 ( V_4 , V_40 ,
V_38 -> V_41 & V_47 ) ;
}
static inline struct V_6 * F_20 ( int V_43 )
{
struct V_6 * V_11 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < F_21 ( V_6 ) ; V_48 ++ ) {
V_11 = & V_6 [ V_48 ] ;
if ( V_11 -> V_24 . V_43 == V_43 )
return V_11 ;
}
return NULL ;
}
static int T_2 F_22 ( struct V_31 * V_32 )
{
struct V_6 * V_11 = NULL ;
struct V_49 V_50 = { } ;
struct V_2 * V_3 ;
int V_43 = V_32 -> V_43 ;
int V_51 ;
F_23 ( & V_32 -> V_33 , L_2 , V_43 ) ;
V_11 = F_20 ( V_43 ) ;
if ( V_11 == NULL ) {
F_24 ( & V_32 -> V_33 , L_3 ) ;
return - V_46 ;
}
V_51 = F_16 ( V_32 -> V_33 . V_4 , V_11 ) ;
if ( V_51 )
return V_51 ;
V_50 . V_33 = & V_32 -> V_33 ;
V_50 . V_52 = V_32 -> V_33 . V_52 ;
V_50 . V_53 = V_32 -> V_33 . V_36 ;
V_50 . V_39 = V_11 ;
V_3 = F_25 ( & V_11 -> V_24 , & V_50 ) ;
if ( F_26 ( V_3 ) ) {
F_24 ( & V_32 -> V_33 , L_4 ,
V_11 -> V_24 . V_54 ) ;
return F_27 ( V_3 ) ;
}
F_28 ( V_32 , V_3 ) ;
return F_17 ( V_32 ) ;
}
static int T_3 F_29 ( struct V_31 * V_32 )
{
struct V_2 * V_3 = F_30 ( V_32 ) ;
F_31 ( V_3 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_55 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_55 ) ;
}
