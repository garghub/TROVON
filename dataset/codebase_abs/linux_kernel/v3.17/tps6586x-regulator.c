static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 , V_6 ;
int V_7 ;
if ( V_4 -> V_8 [ 0 ] == V_4 -> V_8 [ 1 ] &&
V_4 -> V_9 [ 0 ] == V_4 -> V_9 [ 1 ] )
return 0 ;
V_7 = F_2 ( V_2 , V_4 -> V_8 [ 0 ] , & V_5 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_2 ( V_2 , V_4 -> V_8 [ 1 ] , & V_6 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_6 & ( 1 << V_4 -> V_9 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_5 & ( 1 << V_4 -> V_9 [ 0 ] ) ) ) {
V_7 = F_3 ( V_2 , V_4 -> V_8 [ 0 ] ,
1 << V_4 -> V_9 [ 0 ] ) ;
if ( V_7 )
return V_7 ;
}
return F_4 ( V_2 , V_4 -> V_8 [ 1 ] ,
1 << V_4 -> V_9 [ 1 ] ) ;
}
static int F_5 ( struct V_10 * V_11 ,
int V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = V_11 -> V_15 . V_2 ;
struct V_16 * V_17 = V_14 -> V_18 ;
T_1 V_19 ;
if ( V_17 == NULL )
return 0 ;
if ( ! ( V_17 -> V_20 & V_21 ) )
return 0 ;
switch ( V_12 ) {
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
default:
F_6 ( & V_11 -> V_15 , L_1 ) ;
return - V_26 ;
}
return F_7 ( V_2 , V_19 ,
V_17 -> V_20 & V_27 ) ;
}
static struct V_3 * F_8 ( int V_12 , int V_28 )
{
struct V_3 * V_4 ;
struct V_3 * V_29 = NULL ;
int V_30 ;
int V_31 ;
switch ( V_28 ) {
case V_32 :
V_29 = V_33 ;
V_30 = F_9 ( V_33 ) ;
break;
case V_34 :
case V_35 :
V_29 = V_36 ;
V_30 = F_9 ( V_36 ) ;
break;
case V_37 :
V_29 = V_38 ;
V_30 = F_9 ( V_38 ) ;
break;
}
if ( V_29 ) {
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_4 = & V_29 [ V_31 ] ;
if ( V_4 -> V_39 . V_12 == V_12 )
return V_4 ;
}
}
for ( V_31 = 0 ; V_31 < F_9 ( V_3 ) ; V_31 ++ ) {
V_4 = & V_3 [ V_31 ] ;
if ( V_4 -> V_39 . V_12 == V_12 )
return V_4 ;
}
return NULL ;
}
static struct V_40 * F_10 (
struct V_10 * V_11 ,
struct V_41 * * V_42 )
{
const unsigned int V_30 = F_9 ( V_43 ) ;
struct V_44 * V_45 = V_11 -> V_15 . V_2 -> V_46 ;
struct V_44 * V_47 ;
const char * V_48 = NULL ;
unsigned int V_31 ;
struct V_40 * V_49 ;
int V_50 ;
V_47 = F_11 ( V_45 , L_2 ) ;
if ( ! V_47 ) {
F_6 ( & V_11 -> V_15 , L_3 ) ;
return NULL ;
}
V_50 = V_41 ( & V_11 -> V_15 , V_47 , V_43 , V_30 ) ;
F_12 ( V_47 ) ;
if ( V_50 < 0 ) {
F_6 ( & V_11 -> V_15 , L_4 , V_50 ) ;
return NULL ;
}
V_49 = F_13 ( & V_11 -> V_15 , sizeof( * V_49 ) , V_51 ) ;
if ( ! V_49 )
return NULL ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
int V_12 ;
if ( ! V_43 [ V_31 ] . V_52 )
continue;
V_49 -> V_53 [ V_31 ] = V_43 [ V_31 ] . V_52 ;
V_12 = ( int ) V_43 [ V_31 ] . V_18 ;
if ( V_12 == V_54 )
V_48 = V_49 -> V_53 [ V_31 ] -> V_55 . V_56 ;
if ( ( V_12 == V_57 ) || ( V_12 == V_58 ) )
V_49 -> V_53 [ V_31 ] -> V_59 = V_48 ;
}
* V_42 = V_43 ;
return V_49 ;
}
static struct V_40 * F_10 (
struct V_10 * V_11 ,
struct V_41 * * V_42 )
{
* V_42 = NULL ;
return NULL ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = NULL ;
struct V_60 V_61 = { } ;
struct V_62 * V_63 ;
struct V_13 * V_64 ;
struct V_40 * V_49 ;
struct V_41 * V_42 = NULL ;
int V_28 ;
int V_12 ;
int V_50 ;
F_15 ( & V_11 -> V_15 , L_5 ) ;
V_49 = F_16 ( V_11 -> V_15 . V_2 ) ;
if ( ( ! V_49 ) && ( V_11 -> V_15 . V_2 -> V_46 ) )
V_49 = F_10 ( V_11 ,
& V_42 ) ;
if ( ! V_49 ) {
F_6 ( & V_11 -> V_15 , L_6 ) ;
return - V_65 ;
}
V_28 = F_17 ( V_11 -> V_15 . V_2 ) ;
for ( V_12 = 0 ; V_12 < V_66 ; ++ V_12 ) {
V_64 = V_49 -> V_53 [ V_12 ] ;
V_4 = F_8 ( V_12 , V_28 ) ;
if ( ! V_4 ) {
F_6 ( & V_11 -> V_15 , L_7 ) ;
return - V_26 ;
}
V_50 = F_1 ( V_11 -> V_15 . V_2 , V_4 ) ;
if ( V_50 ) {
F_6 ( & V_11 -> V_15 ,
L_8 , V_12 , V_50 ) ;
return V_50 ;
}
V_61 . V_15 = V_11 -> V_15 . V_2 ;
V_61 . V_52 = V_64 ;
V_61 . V_18 = V_4 ;
if ( V_42 )
V_61 . V_46 = V_42 [ V_12 ] . V_46 ;
V_63 = F_18 ( & V_11 -> V_15 , & V_4 -> V_39 , & V_61 ) ;
if ( F_19 ( V_63 ) ) {
F_6 ( & V_11 -> V_15 , L_9 ,
V_4 -> V_39 . V_56 ) ;
return F_20 ( V_63 ) ;
}
if ( V_64 ) {
V_50 = F_5 ( V_11 , V_12 ,
V_64 ) ;
if ( V_50 < 0 ) {
F_6 ( & V_11 -> V_15 ,
L_10 , V_50 ) ;
return V_50 ;
}
}
}
F_21 ( V_11 , V_63 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_67 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_67 ) ;
}
