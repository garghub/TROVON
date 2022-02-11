static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static inline int F_3 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 , V_8 ;
int V_9 ;
if ( V_6 -> V_10 [ 0 ] == V_6 -> V_10 [ 1 ] &&
V_6 -> V_11 [ 0 ] == V_6 -> V_11 [ 1 ] )
return 0 ;
V_9 = F_4 ( V_4 , V_6 -> V_10 [ 0 ] , & V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_4 , V_6 -> V_10 [ 1 ] , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_8 & ( 1 << V_6 -> V_11 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_7 & ( 1 << V_6 -> V_11 [ 0 ] ) ) ) {
V_9 = F_5 ( V_4 , V_6 -> V_10 [ 0 ] ,
1 << V_6 -> V_11 [ 0 ] ) ;
if ( V_9 )
return V_9 ;
}
return F_6 ( V_4 , V_6 -> V_10 [ 1 ] ,
1 << V_6 -> V_11 [ 1 ] ) ;
}
static int F_7 ( struct V_12 * V_13 ,
int V_14 , struct V_15 * V_16 )
{
struct V_1 * V_4 = V_13 -> V_17 . V_4 ;
struct V_18 * V_19 = V_16 -> V_20 ;
T_1 V_21 ;
if ( V_19 == NULL )
return 0 ;
if ( ! ( V_19 -> V_22 & V_23 ) )
return 0 ;
switch ( V_14 ) {
case V_24 :
V_21 = V_25 ;
break;
case V_26 :
V_21 = V_27 ;
break;
default:
F_8 ( & V_13 -> V_17 , L_1 ) ;
return - V_28 ;
}
return F_9 ( V_4 , V_21 ,
V_19 -> V_22 & V_29 ) ;
}
static struct V_5 * F_10 ( int V_14 , int V_30 )
{
struct V_5 * V_6 ;
struct V_5 * V_31 = NULL ;
int V_32 ;
int V_33 ;
switch ( V_30 ) {
case V_34 :
V_31 = V_35 ;
V_32 = F_11 ( V_35 ) ;
break;
case V_36 :
V_31 = V_37 ;
V_32 = F_11 ( V_37 ) ;
break;
}
if ( V_31 ) {
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_6 = & V_31 [ V_33 ] ;
if ( V_6 -> V_38 . V_14 == V_14 )
return V_6 ;
}
}
for ( V_33 = 0 ; V_33 < F_11 ( V_5 ) ; V_33 ++ ) {
V_6 = & V_5 [ V_33 ] ;
if ( V_6 -> V_38 . V_14 == V_14 )
return V_6 ;
}
return NULL ;
}
static struct V_39 * F_12 (
struct V_12 * V_13 ,
struct V_40 * * V_41 )
{
const unsigned int V_32 = F_11 ( V_42 ) ;
struct V_43 * V_44 = V_13 -> V_17 . V_4 -> V_45 ;
struct V_43 * V_46 ;
const char * V_47 = NULL ;
unsigned int V_33 ;
struct V_39 * V_48 ;
int V_49 ;
V_46 = F_13 ( V_44 , L_2 ) ;
if ( ! V_46 ) {
F_8 ( & V_13 -> V_17 , L_3 ) ;
return NULL ;
}
V_49 = V_40 ( & V_13 -> V_17 , V_46 , V_42 , V_32 ) ;
F_14 ( V_46 ) ;
if ( V_49 < 0 ) {
F_8 ( & V_13 -> V_17 , L_4 , V_49 ) ;
return NULL ;
}
V_48 = F_15 ( & V_13 -> V_17 , sizeof( * V_48 ) , V_50 ) ;
if ( ! V_48 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
int V_14 ;
if ( ! V_42 [ V_33 ] . V_51 )
continue;
V_48 -> V_52 [ V_33 ] = V_42 [ V_33 ] . V_51 ;
V_14 = ( int ) V_42 [ V_33 ] . V_20 ;
if ( V_14 == V_53 )
V_47 = V_48 -> V_52 [ V_33 ] -> V_54 . V_55 ;
if ( ( V_14 == V_56 ) || ( V_14 == V_57 ) )
V_48 -> V_52 [ V_33 ] -> V_58 = V_47 ;
}
* V_41 = V_42 ;
return V_48 ;
}
static struct V_39 * F_12 (
struct V_12 * V_13 ,
struct V_40 * * V_41 )
{
* V_41 = NULL ;
return NULL ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = NULL ;
struct V_59 V_60 = { } ;
struct V_2 * V_3 ;
struct V_15 * V_61 ;
struct V_39 * V_48 ;
struct V_40 * V_41 = NULL ;
int V_30 ;
int V_14 ;
int V_49 ;
F_17 ( & V_13 -> V_17 , L_5 ) ;
V_48 = F_18 ( V_13 -> V_17 . V_4 ) ;
if ( ( ! V_48 ) && ( V_13 -> V_17 . V_4 -> V_45 ) )
V_48 = F_12 ( V_13 ,
& V_41 ) ;
if ( ! V_48 ) {
F_8 ( & V_13 -> V_17 , L_6 ) ;
return - V_62 ;
}
V_30 = F_19 ( V_13 -> V_17 . V_4 ) ;
for ( V_14 = 0 ; V_14 < V_63 ; ++ V_14 ) {
V_61 = V_48 -> V_52 [ V_14 ] ;
V_6 = F_10 ( V_14 , V_30 ) ;
if ( ! V_6 ) {
F_8 ( & V_13 -> V_17 , L_7 ) ;
return - V_28 ;
}
V_49 = F_3 ( V_13 -> V_17 . V_4 , V_6 ) ;
if ( V_49 ) {
F_8 ( & V_13 -> V_17 ,
L_8 , V_14 , V_49 ) ;
return V_49 ;
}
V_60 . V_17 = V_13 -> V_17 . V_4 ;
V_60 . V_51 = V_61 ;
V_60 . V_20 = V_6 ;
if ( V_41 )
V_60 . V_45 = V_41 [ V_14 ] . V_45 ;
V_3 = F_20 ( & V_13 -> V_17 , & V_6 -> V_38 , & V_60 ) ;
if ( F_21 ( V_3 ) ) {
F_8 ( & V_13 -> V_17 , L_9 ,
V_6 -> V_38 . V_55 ) ;
return F_22 ( V_3 ) ;
}
if ( V_61 ) {
V_49 = F_7 ( V_13 , V_14 ,
V_61 ) ;
if ( V_49 < 0 ) {
F_8 ( & V_13 -> V_17 ,
L_10 , V_49 ) ;
return V_49 ;
}
}
}
F_23 ( V_13 , V_3 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_64 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_64 ) ;
}
