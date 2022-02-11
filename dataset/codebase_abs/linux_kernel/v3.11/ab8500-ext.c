static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
if ( V_5 -> V_8 && V_5 -> V_8 -> V_9 )
V_6 = V_5 -> V_10 ;
else
V_6 = V_5 -> V_11 ;
V_3 = F_5 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_5 -> V_2 ) ,
L_2 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_3 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
if ( V_5 -> V_8 && V_5 -> V_8 -> V_9 )
V_6 = V_5 -> V_18 ;
else
V_6 = 0 ;
V_3 = F_5 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_5 -> V_2 ) ,
L_4 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) , L_5
L_6 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
V_3 = F_9 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 , & V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_7 , V_5 -> V_14 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) , L_8
L_6 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( ( ( V_6 & V_5 -> V_15 ) == V_5 -> V_19 ) ||
( ( V_6 & V_5 -> V_15 ) == V_5 -> V_10 ) )
return 1 ;
else
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
int V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
switch ( V_20 ) {
case V_21 :
V_6 = V_5 -> V_10 ;
break;
case V_22 :
V_6 = V_5 -> V_19 ;
break;
default:
return - V_7 ;
}
if ( F_8 ( V_2 ) &&
! ( V_5 -> V_8 && V_5 -> V_8 -> V_9 ) ) {
V_3 = F_5 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_9 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_10
L_11 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
}
V_5 -> V_11 = V_6 ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
if ( V_5 -> V_11 == V_5 -> V_10 )
V_3 = V_21 ;
else if ( V_5 -> V_11 == V_5 -> V_19 )
V_3 = V_22 ;
else
V_3 = - V_7 ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 , int V_23 ,
int V_24 , unsigned * V_25 )
{
struct V_26 * V_27 = V_2 -> V_28 ;
if ( ! V_27 ) {
F_3 ( F_4 ( V_2 ) , L_12 ) ;
return - V_7 ;
}
if ( V_27 -> V_23 == V_23 &&
V_27 -> V_24 == V_24 )
return 0 ;
F_3 ( F_4 ( V_2 ) ,
L_13 ,
V_23 , V_24 ,
V_27 -> V_23 , V_27 -> V_24 ) ;
return - V_7 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_25 )
{
struct V_26 * V_27 = V_2 -> V_28 ;
if ( V_27 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_14 ) ;
return - V_7 ;
}
if ( V_27 -> V_23 && V_27 -> V_24 ) {
if ( V_27 -> V_23 == V_27 -> V_24 )
return V_27 -> V_23 ;
}
return - V_7 ;
}
static int F_14 ( struct V_29 * V_30 )
{
struct V_31 * V_31 = F_15 ( V_30 -> V_12 . V_32 ) ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = V_30 -> V_12 . V_39 ;
struct V_40 V_41 = { } ;
int V_42 , V_43 ;
if ( V_38 ) {
V_43 = F_16 ( & V_30 -> V_12 , V_38 ,
V_44 ,
F_17 ( V_44 ) ) ;
if ( V_43 < 0 ) {
F_3 ( & V_30 -> V_12 ,
L_15 , V_43 ) ;
return V_43 ;
}
}
if ( ! V_31 ) {
F_3 ( & V_30 -> V_12 , L_16 ) ;
return - V_7 ;
}
V_34 = F_18 ( V_31 -> V_12 ) ;
if ( ! V_34 ) {
F_3 ( & V_30 -> V_12 , L_17 ) ;
return - V_7 ;
}
V_36 = V_34 -> V_45 ;
if ( ! V_36 ) {
F_3 ( & V_30 -> V_12 , L_18 ) ;
return - V_7 ;
}
if ( V_36 -> V_46 != F_17 ( V_4 ) ) {
F_3 ( & V_30 -> V_12 , L_19 ) ;
return - V_7 ;
}
if ( F_19 ( V_31 ) ) {
struct V_4 * V_5 ;
V_5 = & V_4 [ V_47 ] ;
V_5 -> V_11 = 0x30 ;
V_5 -> V_10 = 0x30 ;
V_5 -> V_19 = 0x10 ;
}
for ( V_42 = 0 ; V_42 < F_17 ( V_4 ) ; V_42 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_42 ] ;
V_5 -> V_12 = & V_30 -> V_12 ;
V_5 -> V_8 = (struct V_48 * )
V_36 -> V_49 [ V_42 ] . V_50 ;
V_41 . V_12 = & V_30 -> V_12 ;
V_41 . V_50 = V_5 ;
V_41 . V_39 = V_44 [ V_42 ] . V_39 ;
V_41 . V_51 = ( V_38 ) ?
V_44 [ V_42 ] . V_51 :
& V_36 -> V_49 [ V_42 ] ;
V_5 -> V_2 = F_20 ( & V_5 -> V_16 , & V_41 ) ;
if ( F_21 ( V_5 -> V_2 ) ) {
V_43 = F_22 ( V_5 -> V_2 ) ;
F_3 ( & V_30 -> V_12 , L_20 ,
V_5 -> V_16 . V_17 ) ;
while ( -- V_42 >= 0 ) {
V_5 = & V_4 [ V_42 ] ;
F_23 ( V_5 -> V_2 ) ;
}
return V_43 ;
}
F_6 ( F_4 ( V_5 -> V_2 ) ,
L_21 , V_5 -> V_16 . V_17 ) ;
}
return 0 ;
}
static int F_24 ( struct V_29 * V_30 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_17 ( V_4 ) ; V_42 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_42 ] ;
F_25 ( F_4 ( V_5 -> V_2 ) ,
L_22 , V_5 -> V_16 . V_17 ) ;
F_23 ( V_5 -> V_2 ) ;
}
return 0 ;
}
static int T_2 F_26 ( void )
{
int V_3 ;
V_3 = F_27 ( & V_52 ) ;
if ( V_3 )
F_28 ( L_23 , V_3 ) ;
return V_3 ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_52 ) ;
}
