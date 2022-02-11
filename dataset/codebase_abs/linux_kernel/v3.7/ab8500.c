static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_2 ) ;
F_6 ( F_4 ( V_2 ) ,
L_3 ,
V_5 -> V_12 . V_13 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , 0x0 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_4 ) ;
F_6 ( F_4 ( V_2 ) ,
L_5 ,
V_5 -> V_12 . V_13 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , 0x0 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_8 , V_5 -> V_9 , & V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_6 , V_5 -> V_9 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_7
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_14 ) ;
if ( V_14 & V_5 -> V_10 )
return true ;
else
return false ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 , V_15 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_16 , V_5 -> V_17 , & V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_9 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_10
L_11 ,
V_5 -> V_12 . V_13 , V_5 -> V_16 ,
V_5 -> V_17 , V_5 -> V_18 ,
V_5 -> V_19 , V_14 ) ;
V_15 = V_14 & V_5 -> V_18 ;
return V_15 >> V_5 -> V_19 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_20 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_14 = ( T_1 ) V_20 << V_5 -> V_19 ;
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_18 , V_14 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_12 ) ;
F_6 ( F_4 ( V_2 ) ,
L_13
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_18 , V_14 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_21 ,
unsigned int V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_23 ;
}
static T_2 int
F_13 ( struct V_24 * V_25 , int V_26 , int V_27 )
{
int V_28 ;
if ( V_27 & ~ V_29 [ V_26 ] . V_30 ) {
F_3 ( & V_25 -> V_7 ,
L_14 ) ;
return - V_6 ;
}
V_28 = F_5 (
& V_25 -> V_7 ,
V_29 [ V_26 ] . V_31 ,
V_29 [ V_26 ] . V_32 ,
V_29 [ V_26 ] . V_30 ,
V_27 ) ;
if ( V_28 < 0 ) {
F_3 ( & V_25 -> V_7 ,
L_15 ,
V_29 [ V_26 ] . V_31 ,
V_29 [ V_26 ] . V_32 ) ;
return V_28 ;
}
F_6 ( & V_25 -> V_7 ,
L_16 ,
V_29 [ V_26 ] . V_31 ,
V_29 [ V_26 ] . V_32 ,
V_29 [ V_26 ] . V_30 ,
V_27 ) ;
return 0 ;
}
static T_2 int F_14 ( struct V_24 * V_25 ,
struct V_33 * V_34 ,
int V_26 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = NULL ;
struct V_37 V_38 = { } ;
int V_28 ;
V_5 = & V_4 [ V_26 ] ;
V_5 -> V_7 = & V_25 -> V_7 ;
V_38 . V_7 = & V_25 -> V_7 ;
V_38 . V_34 = V_34 ;
V_38 . V_39 = V_5 ;
V_38 . V_40 = V_36 ;
if ( F_15 ( V_5 -> V_7 ) < 0x20 ) {
if ( V_5 -> V_12 . V_26 == V_41 ) {
V_5 -> V_12 . V_42 =
F_16 ( V_43 ) ;
V_5 -> V_12 . V_44 = V_43 ;
V_5 -> V_18 = 0xf ;
}
}
V_5 -> V_45 = F_17 ( & V_5 -> V_12 , & V_38 ) ;
if ( F_18 ( V_5 -> V_45 ) ) {
V_28 = F_19 ( V_5 -> V_45 ) ;
F_3 ( & V_25 -> V_7 , L_17 ,
V_5 -> V_12 . V_13 ) ;
while ( -- V_26 >= 0 ) {
V_5 = & V_4 [ V_26 ] ;
F_20 ( V_5 -> V_45 ) ;
}
return V_28 ;
}
return 0 ;
}
static T_2 int
F_21 ( struct V_24 * V_25 , struct V_35 * V_36 )
{
int V_28 , V_46 ;
for ( V_46 = 0 ; V_46 < F_16 ( V_4 ) ; V_46 ++ ) {
V_28 = F_14 (
V_25 , V_47 [ V_46 ] . V_34 ,
V_46 , V_47 [ V_46 ] . V_40 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static T_2 int F_22 ( struct V_24 * V_25 )
{
struct V_48 * V_48 = F_23 ( V_25 -> V_7 . V_49 ) ;
struct V_50 * V_51 ;
struct V_35 * V_36 = V_25 -> V_7 . V_40 ;
int V_46 , V_28 ;
if ( V_36 ) {
V_28 = F_24 ( & V_25 -> V_7 , V_36 ,
V_47 ,
F_16 ( V_47 ) ) ;
if ( V_28 < 0 ) {
F_3 ( & V_25 -> V_7 ,
L_18 , V_28 ) ;
return V_28 ;
}
V_28 = F_21 ( V_25 , V_36 ) ;
return V_28 ;
}
if ( ! V_48 ) {
F_3 ( & V_25 -> V_7 , L_19 ) ;
return - V_6 ;
}
V_51 = F_25 ( V_48 -> V_7 ) ;
if ( ! V_51 ) {
F_3 ( & V_25 -> V_7 , L_20 ) ;
return - V_6 ;
}
if ( V_51 -> V_52 != F_16 ( V_4 ) ) {
F_3 ( & V_25 -> V_7 , L_21 ) ;
return - V_6 ;
}
for ( V_46 = 0 ; V_46 < V_51 -> V_53 ; V_46 ++ ) {
int V_26 , V_27 ;
V_26 = V_51 -> V_54 [ V_46 ] . V_26 ;
V_27 = V_51 -> V_54 [ V_46 ] . V_27 ;
if ( V_26 >= V_55 ) {
F_3 ( & V_25 -> V_7 ,
L_22 ) ;
return - V_6 ;
}
V_28 = F_13 ( V_25 , V_26 , V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
}
for ( V_46 = 0 ; V_46 < F_16 ( V_4 ) ; V_46 ++ ) {
V_28 = F_14 ( V_25 , & V_51 -> V_45 [ V_46 ] , V_46 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
}
return 0 ;
}
static T_3 int F_26 ( struct V_24 * V_25 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_16 ( V_4 ) ; V_46 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_46 ] ;
F_6 ( F_4 ( V_5 -> V_45 ) ,
L_23 , V_5 -> V_12 . V_13 ) ;
F_20 ( V_5 -> V_45 ) ;
}
return 0 ;
}
static int T_4 F_27 ( void )
{
int V_3 ;
V_3 = F_28 ( & V_56 ) ;
if ( V_3 != 0 )
F_29 ( L_24 , V_3 ) ;
return V_3 ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_56 ) ;
}
