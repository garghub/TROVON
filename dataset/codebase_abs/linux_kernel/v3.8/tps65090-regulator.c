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
static int F_9 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_10 ( V_30 -> V_11 . V_10 ) ;
struct V_5 * V_6 = NULL ;
struct V_21 V_22 = { } ;
struct V_33 * V_34 ;
struct V_15 * V_16 ;
struct V_5 * V_35 ;
struct V_36 * V_37 ;
int V_38 ;
int V_8 ;
F_11 ( & V_30 -> V_11 , L_3 ) ;
V_37 = F_12 ( V_30 -> V_11 . V_10 ) ;
if ( ! V_37 ) {
F_5 ( & V_30 -> V_11 , L_4 ) ;
return - V_39 ;
}
V_35 = F_13 ( & V_30 -> V_11 , V_40 * sizeof( * V_35 ) ,
V_41 ) ;
if ( ! V_35 ) {
F_5 ( & V_30 -> V_11 , L_5 ) ;
return - V_42 ;
}
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
V_16 = V_37 -> V_43 [ V_38 ] ;
V_6 = & V_35 [ V_38 ] ;
V_6 -> V_11 = & V_30 -> V_11 ;
V_6 -> V_13 = & V_44 [ V_38 ] ;
if ( V_16 && F_1 ( V_38 ) && V_16 -> V_17 ) {
if ( V_16 -> V_45 ) {
F_7 (
V_16 , & V_22 ) ;
V_6 -> V_13 -> V_46 = & V_47 ;
} else {
V_8 = F_6 (
V_6 , V_16 ) ;
if ( V_8 < 0 ) {
F_5 ( & V_30 -> V_11 ,
L_6 ) ;
goto V_48;
}
}
}
V_22 . V_11 = & V_30 -> V_11 ;
V_22 . V_49 = V_6 ;
V_22 . V_50 = V_32 -> V_51 ;
if ( V_16 )
V_22 . V_52 = V_16 -> V_17 ;
else
V_22 . V_52 = NULL ;
V_34 = F_14 ( V_6 -> V_13 , & V_22 ) ;
if ( F_15 ( V_34 ) ) {
F_5 ( & V_30 -> V_11 , L_7 ,
V_6 -> V_13 -> V_53 ) ;
V_8 = F_16 ( V_34 ) ;
goto V_48;
}
V_6 -> V_34 = V_34 ;
if ( V_16 && F_1 ( V_38 ) && V_16 -> V_17 &&
V_16 -> V_45 ) {
V_8 = F_2 ( V_6 , true ) ;
if ( V_8 < 0 ) {
V_38 ++ ;
goto V_48;
}
}
}
F_17 ( V_30 , V_35 ) ;
return 0 ;
V_48:
while ( -- V_38 >= 0 ) {
V_6 = & V_35 [ V_38 ] ;
F_18 ( V_6 -> V_34 ) ;
}
return V_8 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_5 * V_35 = F_20 ( V_30 ) ;
struct V_5 * V_6 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_40 ; ++ V_38 ) {
V_6 = & V_35 [ V_38 ] ;
F_18 ( V_6 -> V_34 ) ;
}
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_54 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_54 ) ;
}
