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
int V_25 , int V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_5 -> V_17 ; V_27 ++ ) {
if ( ( V_5 -> V_18 [ V_27 ] >= V_25 ) &&
( V_5 -> V_18 [ V_27 ] <= V_26 ) )
return V_27 ;
}
return - V_6 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_25 , int V_26 ,
unsigned * V_15 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_12 ( V_2 , V_25 , V_26 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_11 ) ;
return V_3 ;
}
* V_15 = V_3 ;
V_14 = ( T_1 ) V_3 ;
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_22 , V_14 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_12 ) ;
F_6 ( F_4 ( V_2 ) ,
L_13
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_22 , V_14 ) ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_28 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_29 ,
unsigned int V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! V_3 )
return 0 ;
return V_5 -> V_28 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
return V_5 -> V_16 ;
}
static T_2 int F_17 ( struct V_31 * V_32 )
{
struct V_33 * V_33 = F_18 ( V_32 -> V_7 . V_34 ) ;
struct V_35 * V_36 ;
int V_27 , V_37 ;
if ( ! V_33 ) {
F_3 ( & V_32 -> V_7 , L_14 ) ;
return - V_6 ;
}
V_36 = F_19 ( V_33 -> V_7 ) ;
if ( ! V_36 ) {
F_3 ( & V_32 -> V_7 , L_15 ) ;
return - V_6 ;
}
if ( V_36 -> V_38 != F_20 ( V_4 ) ) {
F_3 ( & V_32 -> V_7 , L_16 ) ;
return - V_6 ;
}
for ( V_27 = 0 ; V_27 < V_36 -> V_39 ; V_27 ++ ) {
int V_23 ;
T_1 V_40 ;
V_23 = V_36 -> V_41 [ V_27 ] . V_23 ;
V_40 = V_36 -> V_41 [ V_27 ] . V_40 ;
if ( V_23 >= V_42 ) {
F_3 ( & V_32 -> V_7 ,
L_17 ) ;
return - V_6 ;
}
if ( V_40 & ~ V_43 [ V_23 ] . V_44 ) {
F_3 ( & V_32 -> V_7 ,
L_18 ) ;
return - V_6 ;
}
V_37 = F_5 ( & V_32 -> V_7 ,
V_43 [ V_23 ] . V_45 ,
V_43 [ V_23 ] . V_46 ,
V_43 [ V_23 ] . V_44 ,
V_40 ) ;
if ( V_37 < 0 ) {
F_3 ( & V_32 -> V_7 ,
L_19 ,
V_43 [ V_23 ] . V_45 ,
V_43 [ V_23 ] . V_46 ) ;
return V_37 ;
}
F_6 ( & V_32 -> V_7 ,
L_20 ,
V_43 [ V_23 ] . V_45 ,
V_43 [ V_23 ] . V_46 ,
V_43 [ V_23 ] . V_44 ,
V_40 ) ;
}
for ( V_27 = 0 ; V_27 < F_20 ( V_4 ) ; V_27 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_27 ] ;
V_5 -> V_7 = & V_32 -> V_7 ;
if ( F_21 ( V_5 -> V_7 ) < 0x20 ) {
if ( V_5 -> V_12 . V_23 == V_47 ) {
V_5 -> V_12 . V_48 =
F_20 ( V_49 ) ;
V_5 -> V_18 = V_49 ;
V_5 -> V_17 =
F_20 ( V_49 ) ;
V_5 -> V_22 = 0xf ;
}
}
V_5 -> V_50 = F_22 ( & V_5 -> V_12 , & V_32 -> V_7 ,
& V_36 -> V_50 [ V_27 ] , V_5 , NULL ) ;
if ( F_23 ( V_5 -> V_50 ) ) {
V_37 = F_24 ( V_5 -> V_50 ) ;
F_3 ( & V_32 -> V_7 , L_21 ,
V_5 -> V_12 . V_13 ) ;
while ( -- V_27 >= 0 ) {
V_5 = & V_4 [ V_27 ] ;
F_25 ( V_5 -> V_50 ) ;
}
return V_37 ;
}
F_6 ( F_4 ( V_5 -> V_50 ) ,
L_22 , V_5 -> V_12 . V_13 ) ;
}
return 0 ;
}
static T_3 int F_26 ( struct V_31 * V_32 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_20 ( V_4 ) ; V_27 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_27 ] ;
F_6 ( F_4 ( V_5 -> V_50 ) ,
L_23 , V_5 -> V_12 . V_13 ) ;
F_25 ( V_5 -> V_50 ) ;
}
return 0 ;
}
static int T_4 F_27 ( void )
{
int V_3 ;
V_3 = F_28 ( & V_51 ) ;
if ( V_3 != 0 )
F_29 ( L_24 , V_3 ) ;
return V_3 ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_51 ) ;
}
