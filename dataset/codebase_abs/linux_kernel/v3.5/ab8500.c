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
static int F_10 ( struct V_1 * V_2 , unsigned V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
if ( V_5 -> V_16 )
return V_5 -> V_16 ;
if ( V_15 >= V_5 -> V_17 )
return - V_6 ;
return V_5 -> V_18 [ V_15 ] ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_19 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_20 , V_5 -> V_21 , & V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_9 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_10
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_22 , V_14 ) ;
V_19 = V_14 & V_5 -> V_22 ;
if ( V_5 -> V_12 . V_23 == V_24 )
return V_19 >> 0x3 ;
else
return V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_15 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_14 = ( T_1 ) V_15 ;
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_22 , V_14 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_11 ) ;
F_6 ( F_4 ( V_2 ) ,
L_12
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_22 , V_14 ) ;
return V_3 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_25 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_26 ,
unsigned int V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! V_3 )
return 0 ;
return V_5 -> V_25 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
return V_5 -> V_16 ;
}
static T_2 int
F_16 ( struct V_28 * V_29 , int V_23 , int V_30 )
{
int V_31 ;
if ( V_30 & ~ V_32 [ V_23 ] . V_33 ) {
F_3 ( & V_29 -> V_7 ,
L_13 ) ;
return - V_6 ;
}
V_31 = F_5 (
& V_29 -> V_7 ,
V_32 [ V_23 ] . V_34 ,
V_32 [ V_23 ] . V_35 ,
V_32 [ V_23 ] . V_33 ,
V_30 ) ;
if ( V_31 < 0 ) {
F_3 ( & V_29 -> V_7 ,
L_14 ,
V_32 [ V_23 ] . V_34 ,
V_32 [ V_23 ] . V_35 ) ;
return V_31 ;
}
F_6 ( & V_29 -> V_7 ,
L_15 ,
V_32 [ V_23 ] . V_34 ,
V_32 [ V_23 ] . V_35 ,
V_32 [ V_23 ] . V_33 ,
V_30 ) ;
return 0 ;
}
static T_2 int F_17 ( struct V_28 * V_29 ,
struct V_36 * V_37 ,
int V_23 ,
struct V_38 * V_39 )
{
struct V_4 * V_5 = NULL ;
struct V_40 V_41 = { } ;
int V_31 ;
V_5 = & V_4 [ V_23 ] ;
V_5 -> V_7 = & V_29 -> V_7 ;
V_41 . V_7 = & V_29 -> V_7 ;
V_41 . V_37 = V_37 ;
V_41 . V_42 = V_5 ;
V_41 . V_43 = V_39 ;
if ( F_18 ( V_5 -> V_7 ) < 0x20 ) {
if ( V_5 -> V_12 . V_23 == V_44 ) {
V_5 -> V_12 . V_45 =
F_19 ( V_46 ) ;
V_5 -> V_18 = V_46 ;
V_5 -> V_17 =
F_19 ( V_46 ) ;
V_5 -> V_22 = 0xf ;
}
}
V_5 -> V_47 = F_20 ( & V_5 -> V_12 , & V_41 ) ;
if ( F_21 ( V_5 -> V_47 ) ) {
V_31 = F_22 ( V_5 -> V_47 ) ;
F_3 ( & V_29 -> V_7 , L_16 ,
V_5 -> V_12 . V_13 ) ;
while ( -- V_23 >= 0 ) {
V_5 = & V_4 [ V_23 ] ;
F_23 ( V_5 -> V_47 ) ;
}
return V_31 ;
}
return 0 ;
}
static T_2 int
F_24 ( struct V_28 * V_29 , struct V_38 * V_39 )
{
int V_31 , V_48 ;
for ( V_48 = 0 ; V_48 < F_19 ( V_4 ) ; V_48 ++ ) {
V_31 = F_17 (
V_29 , V_49 [ V_48 ] . V_37 ,
V_48 , V_49 [ V_48 ] . V_43 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static T_2 int F_25 ( struct V_28 * V_29 )
{
struct V_50 * V_50 = F_26 ( V_29 -> V_7 . V_51 ) ;
struct V_52 * V_53 ;
struct V_38 * V_39 = V_29 -> V_7 . V_43 ;
int V_48 , V_31 ;
if ( V_39 ) {
V_31 = F_27 ( & V_29 -> V_7 , V_39 ,
V_49 ,
F_19 ( V_49 ) ) ;
if ( V_31 < 0 ) {
F_3 ( & V_29 -> V_7 ,
L_17 , V_31 ) ;
return V_31 ;
}
V_31 = F_24 ( V_29 , V_39 ) ;
return V_31 ;
}
if ( ! V_50 ) {
F_3 ( & V_29 -> V_7 , L_18 ) ;
return - V_6 ;
}
V_53 = F_28 ( V_50 -> V_7 ) ;
if ( ! V_53 ) {
F_3 ( & V_29 -> V_7 , L_19 ) ;
return - V_6 ;
}
if ( V_53 -> V_54 != F_19 ( V_4 ) ) {
F_3 ( & V_29 -> V_7 , L_20 ) ;
return - V_6 ;
}
for ( V_48 = 0 ; V_48 < V_53 -> V_55 ; V_48 ++ ) {
int V_23 , V_30 ;
V_23 = V_53 -> V_56 [ V_48 ] . V_23 ;
V_30 = V_53 -> V_56 [ V_48 ] . V_30 ;
if ( V_23 >= V_57 ) {
F_3 ( & V_29 -> V_7 ,
L_21 ) ;
return - V_6 ;
}
V_31 = F_16 ( V_29 , V_23 , V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
}
for ( V_48 = 0 ; V_48 < F_19 ( V_4 ) ; V_48 ++ ) {
V_31 = F_17 ( V_29 , & V_53 -> V_47 [ V_48 ] , V_48 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
}
return 0 ;
}
static T_3 int F_29 ( struct V_28 * V_29 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_19 ( V_4 ) ; V_48 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_48 ] ;
F_6 ( F_4 ( V_5 -> V_47 ) ,
L_22 , V_5 -> V_12 . V_13 ) ;
F_23 ( V_5 -> V_47 ) ;
}
return 0 ;
}
static int T_4 F_30 ( void )
{
int V_3 ;
V_3 = F_31 ( & V_58 ) ;
if ( V_3 != 0 )
F_32 ( L_23 , V_3 ) ;
return V_3 ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_58 ) ;
}
