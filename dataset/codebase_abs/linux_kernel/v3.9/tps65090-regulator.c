static inline bool F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 (
struct V_5 * V_6 , bool V_7 )
{
int V_8 ;
struct V_9 * V_10 = V_6 -> V_11 -> V_10 ;
unsigned int V_12 = V_6 -> V_13 -> V_14 ;
if ( V_7 )
V_8 = F_3 ( V_10 , V_12 , 1 ) ;
else
V_8 = F_4 ( V_10 , V_12 , 1 ) ;
if ( V_8 < 0 )
F_5 ( V_6 -> V_11 , L_1 , V_12 ) ;
return V_8 ;
}
static int F_6 (
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
int V_8 = 0 ;
struct V_9 * V_10 = V_6 -> V_11 -> V_10 ;
unsigned int V_12 = V_6 -> V_13 -> V_14 ;
if ( V_16 -> V_17 -> V_18 . V_19 ||
V_16 -> V_17 -> V_18 . V_20 ) {
V_8 = F_3 ( V_10 , V_12 , 0 ) ;
if ( V_8 < 0 ) {
F_5 ( V_6 -> V_11 , L_2 , V_12 ) ;
return V_8 ;
}
}
return F_2 ( V_6 , false ) ;
}
static void F_7 (
struct V_15 * V_16 ,
struct V_21 * V_22 )
{
if ( F_8 ( V_16 -> V_23 ) ) {
int V_24 = V_25 ;
if ( V_16 -> V_17 -> V_18 . V_19 ||
V_16 -> V_17 -> V_18 . V_20 )
V_24 = V_26 ;
V_22 -> V_27 = V_16 -> V_23 ;
V_22 -> V_28 = V_24 ;
}
}
static struct V_29 * F_9 (
struct V_30 * V_31 ,
struct V_32 * * V_33 )
{
struct V_29 * V_34 ;
struct V_35 * V_36 = V_31 -> V_11 . V_10 -> V_37 ;
struct V_35 * V_38 ;
int V_39 = 0 , V_8 ;
struct V_15 * V_40 ;
V_34 = F_10 ( & V_31 -> V_11 , sizeof( * V_34 ) ,
V_41 ) ;
if ( ! V_34 ) {
F_5 ( & V_31 -> V_11 , L_3 ) ;
return F_11 ( - V_42 ) ;
}
V_40 = F_10 ( & V_31 -> V_11 , V_43 *
sizeof( * V_40 ) , V_41 ) ;
if ( ! V_40 ) {
F_5 ( & V_31 -> V_11 , L_4 ) ;
return F_11 ( - V_42 ) ;
}
V_38 = F_12 ( V_36 , L_5 ) ;
if ( ! V_38 ) {
F_5 ( & V_31 -> V_11 , L_6 ) ;
return F_11 ( - V_44 ) ;
}
V_8 = V_32 ( & V_31 -> V_11 , V_38 , V_45 ,
F_13 ( V_45 ) ) ;
if ( V_8 < 0 ) {
F_5 ( & V_31 -> V_11 ,
L_7 , V_8 ) ;
return F_11 ( V_8 ) ;
}
* V_33 = V_45 ;
for ( V_39 = 0 ; V_39 < F_13 ( V_45 ) ; V_39 ++ ) {
struct V_46 * V_47 ;
struct V_15 * V_48 ;
V_48 = & V_40 [ V_39 ] ;
V_47 = V_45 [ V_39 ] . V_49 ;
if ( ! V_47 || ! V_45 [ V_39 ] . V_37 )
continue;
V_48 -> V_17 = V_47 ;
V_48 -> V_50 = F_14 (
V_45 [ V_39 ] . V_37 ,
L_8 ) ;
if ( V_48 -> V_50 )
V_48 -> V_23 = F_15 ( V_36 ,
L_9 , 0 ) ;
V_34 -> V_40 [ V_39 ] = V_48 ;
}
return V_34 ;
}
static inline struct V_29 * F_9 (
struct V_30 * V_31 ,
struct V_32 * * V_33 )
{
* V_33 = NULL ;
return NULL ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_51 * V_52 = F_17 ( V_31 -> V_11 . V_10 ) ;
struct V_5 * V_6 = NULL ;
struct V_21 V_22 = { } ;
struct V_53 * V_54 ;
struct V_15 * V_16 ;
struct V_5 * V_55 ;
struct V_29 * V_34 ;
struct V_32 * V_33 = NULL ;
int V_56 ;
int V_8 ;
F_18 ( & V_31 -> V_11 , L_10 ) ;
V_34 = F_19 ( V_31 -> V_11 . V_10 ) ;
if ( ! V_34 && V_52 -> V_11 -> V_37 )
V_34 = F_9 ( V_31 ,
& V_33 ) ;
if ( F_20 ( V_34 ) ) {
F_5 ( & V_31 -> V_11 , L_11 ) ;
return V_34 ? F_21 ( V_34 ) : - V_57 ;
}
V_55 = F_10 ( & V_31 -> V_11 , V_43 * sizeof( * V_55 ) ,
V_41 ) ;
if ( ! V_55 ) {
F_5 ( & V_31 -> V_11 , L_12 ) ;
return - V_42 ;
}
for ( V_56 = 0 ; V_56 < V_43 ; V_56 ++ ) {
V_16 = V_34 -> V_40 [ V_56 ] ;
V_6 = & V_55 [ V_56 ] ;
V_6 -> V_11 = & V_31 -> V_11 ;
V_6 -> V_13 = & V_58 [ V_56 ] ;
if ( V_16 && F_1 ( V_56 ) && V_16 -> V_17 ) {
if ( V_16 -> V_50 ) {
F_7 (
V_16 , & V_22 ) ;
V_6 -> V_13 -> V_59 = & V_60 ;
} else {
V_8 = F_6 (
V_6 , V_16 ) ;
if ( V_8 < 0 ) {
F_5 ( & V_31 -> V_11 ,
L_13 ) ;
goto V_61;
}
}
}
V_22 . V_11 = V_31 -> V_11 . V_10 ;
V_22 . V_62 = V_6 ;
V_22 . V_63 = V_52 -> V_64 ;
if ( V_16 )
V_22 . V_49 = V_16 -> V_17 ;
else
V_22 . V_49 = NULL ;
if ( V_33 )
V_22 . V_37 = V_33 [ V_56 ] . V_37 ;
else
V_22 . V_37 = NULL ;
V_54 = F_22 ( V_6 -> V_13 , & V_22 ) ;
if ( F_23 ( V_54 ) ) {
F_5 ( & V_31 -> V_11 , L_14 ,
V_6 -> V_13 -> V_65 ) ;
V_8 = F_21 ( V_54 ) ;
goto V_61;
}
V_6 -> V_54 = V_54 ;
if ( V_16 && F_1 ( V_56 ) && V_16 -> V_17 &&
V_16 -> V_50 ) {
V_8 = F_2 ( V_6 , true ) ;
if ( V_8 < 0 ) {
V_56 ++ ;
goto V_61;
}
}
}
F_24 ( V_31 , V_55 ) ;
return 0 ;
V_61:
while ( -- V_56 >= 0 ) {
V_6 = & V_55 [ V_56 ] ;
F_25 ( V_6 -> V_54 ) ;
}
return V_8 ;
}
static int F_26 ( struct V_30 * V_31 )
{
struct V_5 * V_55 = F_27 ( V_31 ) ;
struct V_5 * V_6 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_43 ; ++ V_56 ) {
V_6 = & V_55 [ V_56 ] ;
F_25 ( V_6 -> V_54 ) ;
}
return 0 ;
}
static int T_1 F_28 ( void )
{
return F_29 ( & V_66 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_66 ) ;
}
