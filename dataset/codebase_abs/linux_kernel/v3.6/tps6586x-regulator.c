static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 , V_9 , V_10 = F_5 ( V_3 ) ;
T_1 V_11 ;
V_9 = V_5 << V_7 -> V_12 ;
V_11 = ( ( 1 << V_7 -> V_13 ) - 1 ) << V_7 -> V_12 ;
V_8 = F_6 ( V_4 , V_7 -> V_14 , V_9 , V_11 ) ;
if ( V_8 )
return V_8 ;
switch ( V_10 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_8 = F_7 ( V_4 , V_7 -> V_19 , 1 << V_7 -> V_20 ) ;
break;
}
return V_8 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_9 , V_11 ;
int V_8 ;
V_8 = F_9 ( V_4 , V_7 -> V_14 , & V_9 ) ;
if ( V_8 )
return V_8 ;
V_11 = ( ( 1 << V_7 -> V_13 ) - 1 ) << V_7 -> V_12 ;
V_9 = ( V_9 & V_11 ) >> V_7 -> V_12 ;
if ( V_9 >= V_7 -> V_21 . V_22 )
F_10 () ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_7 ( V_4 , V_7 -> V_23 [ 0 ] ,
1 << V_7 -> V_24 [ 0 ] ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_13 ( V_4 , V_7 -> V_23 [ 0 ] ,
1 << V_7 -> V_24 [ 0 ] ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_25 ;
int V_8 ;
V_8 = F_9 ( V_4 , V_7 -> V_23 [ 0 ] , & V_25 ) ;
if ( V_8 )
return V_8 ;
return ! ! ( V_25 & ( 1 << V_7 -> V_24 [ 0 ] ) ) ;
}
static inline int F_15 ( struct V_1 * V_4 ,
struct V_6 * V_7 )
{
T_1 V_26 , V_27 ;
int V_8 ;
if ( V_7 -> V_23 [ 0 ] == V_7 -> V_23 [ 1 ] &&
V_7 -> V_24 [ 0 ] == V_7 -> V_24 [ 1 ] )
return 0 ;
V_8 = F_9 ( V_4 , V_7 -> V_23 [ 0 ] , & V_26 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_9 ( V_4 , V_7 -> V_23 [ 1 ] , & V_27 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_27 & ( 1 << V_7 -> V_24 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_26 & ( 1 << V_7 -> V_24 [ 0 ] ) ) ) {
V_8 = F_7 ( V_4 , V_7 -> V_23 [ 0 ] ,
1 << V_7 -> V_24 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
}
return F_13 ( V_4 , V_7 -> V_23 [ 1 ] ,
1 << V_7 -> V_24 [ 1 ] ) ;
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_1 * V_4 = V_29 -> V_30 . V_4 ;
struct V_31 * V_32 = V_29 -> V_30 . V_33 ;
struct V_34 * V_35 = V_32 -> V_36 ;
T_1 V_37 ;
if ( V_35 == NULL )
return 0 ;
if ( ! ( V_35 -> V_38 & V_39 ) )
return 0 ;
switch ( V_29 -> V_40 ) {
case V_17 :
V_37 = V_41 ;
break;
case V_18 :
V_37 = V_42 ;
break;
default:
F_17 ( & V_29 -> V_30 , L_1 ) ;
return - V_43 ;
}
return F_18 ( V_4 , V_37 ,
V_35 -> V_38 & V_44 ) ;
}
static inline struct V_6 * F_19 ( int V_40 )
{
struct V_6 * V_7 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_20 ( V_6 ) ; V_45 ++ ) {
V_7 = & V_6 [ V_45 ] ;
if ( V_7 -> V_21 . V_40 == V_40 )
return V_7 ;
}
return NULL ;
}
static int T_2 F_21 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = NULL ;
struct V_46 V_47 = { } ;
struct V_2 * V_3 ;
int V_40 = V_29 -> V_40 ;
int V_48 ;
F_22 ( & V_29 -> V_30 , L_2 , V_40 ) ;
V_7 = F_19 ( V_40 ) ;
if ( V_7 == NULL ) {
F_23 ( & V_29 -> V_30 , L_3 ) ;
return - V_43 ;
}
V_48 = F_15 ( V_29 -> V_30 . V_4 , V_7 ) ;
if ( V_48 )
return V_48 ;
V_47 . V_30 = V_29 -> V_30 . V_4 ;
V_47 . V_49 = V_29 -> V_30 . V_49 ;
V_47 . V_50 = V_29 -> V_30 . V_33 ;
V_47 . V_36 = V_7 ;
V_3 = F_24 ( & V_7 -> V_21 , & V_47 ) ;
if ( F_25 ( V_3 ) ) {
F_23 ( & V_29 -> V_30 , L_4 ,
V_7 -> V_21 . V_51 ) ;
return F_26 ( V_3 ) ;
}
F_27 ( V_29 , V_3 ) ;
return F_16 ( V_29 ) ;
}
static int T_3 F_28 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_29 ( V_29 ) ;
F_30 ( V_3 ) ;
return 0 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_52 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_52 ) ;
}
