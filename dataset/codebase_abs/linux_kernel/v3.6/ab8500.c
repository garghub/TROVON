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
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_18 , V_14 ) ;
V_15 = V_14 & V_5 -> V_18 ;
if ( V_5 -> V_12 . V_19 == V_20 )
return V_15 >> 0x3 ;
else
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_21 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_14 = ( T_1 ) V_21 ;
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_18 , V_14 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_11 ) ;
F_6 ( F_4 ( V_2 ) ,
L_12
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_18 , V_14 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_22 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_23 ,
unsigned int V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_22 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_12 -> V_25 ;
}
static T_2 int
F_15 ( struct V_26 * V_27 , int V_19 , int V_28 )
{
int V_29 ;
if ( V_28 & ~ V_30 [ V_19 ] . V_31 ) {
F_3 ( & V_27 -> V_7 ,
L_13 ) ;
return - V_6 ;
}
V_29 = F_5 (
& V_27 -> V_7 ,
V_30 [ V_19 ] . V_32 ,
V_30 [ V_19 ] . V_33 ,
V_30 [ V_19 ] . V_31 ,
V_28 ) ;
if ( V_29 < 0 ) {
F_3 ( & V_27 -> V_7 ,
L_14 ,
V_30 [ V_19 ] . V_32 ,
V_30 [ V_19 ] . V_33 ) ;
return V_29 ;
}
F_6 ( & V_27 -> V_7 ,
L_15 ,
V_30 [ V_19 ] . V_32 ,
V_30 [ V_19 ] . V_33 ,
V_30 [ V_19 ] . V_31 ,
V_28 ) ;
return 0 ;
}
static T_2 int F_16 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
int V_19 ,
struct V_36 * V_37 )
{
struct V_4 * V_5 = NULL ;
struct V_38 V_39 = { } ;
int V_29 ;
V_5 = & V_4 [ V_19 ] ;
V_5 -> V_7 = & V_27 -> V_7 ;
V_39 . V_7 = & V_27 -> V_7 ;
V_39 . V_35 = V_35 ;
V_39 . V_40 = V_5 ;
V_39 . V_41 = V_37 ;
if ( F_17 ( V_5 -> V_7 ) < 0x20 ) {
if ( V_5 -> V_12 . V_19 == V_42 ) {
V_5 -> V_12 . V_43 =
F_18 ( V_44 ) ;
V_5 -> V_12 . V_45 = V_44 ;
V_5 -> V_18 = 0xf ;
}
}
V_5 -> V_46 = F_19 ( & V_5 -> V_12 , & V_39 ) ;
if ( F_20 ( V_5 -> V_46 ) ) {
V_29 = F_21 ( V_5 -> V_46 ) ;
F_3 ( & V_27 -> V_7 , L_16 ,
V_5 -> V_12 . V_13 ) ;
while ( -- V_19 >= 0 ) {
V_5 = & V_4 [ V_19 ] ;
F_22 ( V_5 -> V_46 ) ;
}
return V_29 ;
}
return 0 ;
}
static T_2 int
F_23 ( struct V_26 * V_27 , struct V_36 * V_37 )
{
int V_29 , V_47 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_4 ) ; V_47 ++ ) {
V_29 = F_16 (
V_27 , V_48 [ V_47 ] . V_35 ,
V_47 , V_48 [ V_47 ] . V_41 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static T_2 int F_24 ( struct V_26 * V_27 )
{
struct V_49 * V_49 = F_25 ( V_27 -> V_7 . V_50 ) ;
struct V_51 * V_52 ;
struct V_36 * V_37 = V_27 -> V_7 . V_41 ;
int V_47 , V_29 ;
if ( V_37 ) {
V_29 = F_26 ( & V_27 -> V_7 , V_37 ,
V_48 ,
F_18 ( V_48 ) ) ;
if ( V_29 < 0 ) {
F_3 ( & V_27 -> V_7 ,
L_17 , V_29 ) ;
return V_29 ;
}
V_29 = F_23 ( V_27 , V_37 ) ;
return V_29 ;
}
if ( ! V_49 ) {
F_3 ( & V_27 -> V_7 , L_18 ) ;
return - V_6 ;
}
V_52 = F_27 ( V_49 -> V_7 ) ;
if ( ! V_52 ) {
F_3 ( & V_27 -> V_7 , L_19 ) ;
return - V_6 ;
}
if ( V_52 -> V_53 != F_18 ( V_4 ) ) {
F_3 ( & V_27 -> V_7 , L_20 ) ;
return - V_6 ;
}
for ( V_47 = 0 ; V_47 < V_52 -> V_54 ; V_47 ++ ) {
int V_19 , V_28 ;
V_19 = V_52 -> V_55 [ V_47 ] . V_19 ;
V_28 = V_52 -> V_55 [ V_47 ] . V_28 ;
if ( V_19 >= V_56 ) {
F_3 ( & V_27 -> V_7 ,
L_21 ) ;
return - V_6 ;
}
V_29 = F_15 ( V_27 , V_19 , V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
}
for ( V_47 = 0 ; V_47 < F_18 ( V_4 ) ; V_47 ++ ) {
V_29 = F_16 ( V_27 , & V_52 -> V_46 [ V_47 ] , V_47 , NULL ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static T_3 int F_28 ( struct V_26 * V_27 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_4 ) ; V_47 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_47 ] ;
F_6 ( F_4 ( V_5 -> V_46 ) ,
L_22 , V_5 -> V_12 . V_13 ) ;
F_22 ( V_5 -> V_46 ) ;
}
return 0 ;
}
static int T_4 F_29 ( void )
{
int V_3 ;
V_3 = F_30 ( & V_57 ) ;
if ( V_3 != 0 )
F_31 ( L_23 , V_3 ) ;
return V_3 ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_57 ) ;
}
