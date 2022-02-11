static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_1 V_7 ;
V_6 = F_2 ( V_4 -> V_8 , 0 , V_4 -> V_9 ,
& V_7 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 , L_1 ,
V_4 -> V_9 ) ;
return V_6 ;
}
if ( V_7 & V_10 )
return 0 ;
V_7 |= V_10 ;
V_6 = F_4 ( V_4 -> V_8 , 0 , V_4 -> V_9 ,
V_7 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 , L_2 ,
V_4 -> V_9 ) ;
return V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_1 V_7 ;
F_6 ( L_3 ) ;
if ( V_4 -> V_9 == V_11 ) {
F_7 ( & V_2 -> V_8 , L_4 ) ;
return F_4 ( V_4 -> V_8 , 0 ,
V_11 , 0x00U ) ;
}
V_6 = F_2 ( V_4 -> V_8 , 0 , V_4 -> V_9 ,
& V_7 ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_8 , L_5 ,
V_4 -> V_9 ) ;
return V_6 ;
}
V_7 &= ~ V_10 ;
return F_4 ( V_4 -> V_8 , 0 , V_4 -> V_9 ,
V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_7 ;
int V_6 ;
V_6 = F_2 ( V_4 -> V_8 , 0 , V_4 -> V_9 ,
& V_7 ) ;
if ( V_6 ) {
F_8 ( & V_2 -> V_8 , L_5 ,
V_4 -> V_9 ) ;
return V_6 ;
}
return V_7 & V_10 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_12 >= V_4 -> V_13 )
return - V_14 ;
return V_4 -> V_15 [ V_12 ] ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_7 ;
int V_6 ;
if ( V_4 -> V_16 )
return V_4 -> V_16 ;
V_6 = F_2 ( V_4 -> V_8 , 0 ,
V_4 -> V_9 , & V_7 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 ,
L_6 ,
V_4 -> V_9 ) ;
return V_6 ;
}
V_7 &= 0xE0 ;
V_7 >>= 5 ;
if ( V_7 >= V_4 -> V_13 ) {
F_8 ( & V_2 -> V_8 ,
L_7 ,
V_4 -> V_9 ) ;
return - V_14 ;
}
return V_4 -> V_15 [ V_7 ] ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_7 ;
int V_6 ;
V_6 = F_2 ( V_4 -> V_8 , 0 ,
V_4 -> V_9 , & V_7 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 ,
L_8 ,
V_4 -> V_9 ) ;
return V_6 ;
}
V_7 &= ~ 0xE0 ;
V_7 |= ( V_12 << 5 ) ;
V_6 = F_4 ( V_4 -> V_8 , 0 ,
V_4 -> V_9 , V_7 ) ;
if ( V_6 )
F_3 ( & V_2 -> V_8 , L_9 ,
V_4 -> V_9 ) ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_7 ;
int V_6 ;
int V_18 ;
T_1 V_19 ;
if ( V_4 -> V_9 == V_20 )
V_19 = V_21 ;
else if ( V_4 -> V_9 == V_22 )
V_19 = V_23 ;
else
return - V_14 ;
V_18 = F_14 ( V_2 , V_17 , V_17 ) ;
V_6 = F_2 ( V_4 -> V_8 , 0 ,
V_19 , & V_7 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 ,
L_8 ,
V_19 ) ;
return V_6 ;
}
V_7 &= ~ 0xE0 ;
V_7 |= ( V_18 << 5 ) ;
V_6 = F_4 ( V_4 -> V_8 , 0 ,
V_19 , V_7 ) ;
if ( V_6 )
F_3 ( & V_2 -> V_8 , L_9 ,
V_4 -> V_9 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_24 -> V_25 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> V_9 ) {
case V_26 :
case V_27 :
case V_11 :
case V_20 :
case V_28 :
case V_29 :
return 200 ;
case V_30 :
return 600 ;
case V_31 :
return 400 ;
case V_22 :
return 1000 ;
default:
break;
}
return 0 ;
}
static int T_2 F_17 ( struct V_32 * V_33 )
{
struct V_34 * V_24 = V_33 -> V_8 . V_35 ;
struct V_36 V_37 = { } ;
int V_6 = 0 ;
T_1 V_38 ;
int V_39 ;
V_6 = F_2 ( & V_33 -> V_8 , 0 ,
V_11 , & V_38 ) ;
if ( V_6 ) {
F_8 ( & V_33 -> V_8 , L_10 ) ;
return V_6 ;
}
if ( V_38 & 0x10 )
F_18 ( & V_33 -> V_8 ,
L_11 ) ;
else
F_18 ( & V_33 -> V_8 ,
L_12 ) ;
for ( V_39 = 0 ; V_39 < F_19 ( V_40 ) ; V_39 ++ ) {
V_6 = F_4 ( & V_33 -> V_8 , 0 ,
V_40 [ V_39 ] ,
V_24 -> V_41 [ V_39 ] ) ;
if ( V_6 ) {
F_8 ( & V_33 -> V_8 , L_13 ,
V_6 ) ;
return V_6 ;
}
}
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ ) {
struct V_3 * V_2 = & V_43 [ V_39 ] ;
struct V_1 * V_44 ;
V_2 -> V_8 = & V_33 -> V_8 ;
V_2 -> V_24 = V_24 ;
V_37 . V_8 = & V_33 -> V_8 ;
V_37 . V_45 = V_2 ;
V_37 . V_46 = & V_24 -> V_47 [ V_39 ] ;
V_44 = F_20 ( & V_48 [ V_39 ] , & V_37 ) ;
if ( F_21 ( V_44 ) ) {
V_6 = F_22 ( V_44 ) ;
F_8 ( & V_33 -> V_8 ,
L_14 ,
V_49 , V_48 [ V_39 ] . V_50 ,
V_6 ) ;
while ( -- V_39 >= 0 )
F_23 ( V_43 [ V_39 ] . V_44 ) ;
return V_6 ;
}
V_2 -> V_44 = V_44 ;
}
return 0 ;
}
static int T_3 F_24 ( struct V_32 * V_33 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ ) {
struct V_3 * V_2 = & V_43 [ V_39 ] ;
F_23 ( V_2 -> V_44 ) ;
}
return 0 ;
}
static T_4 int F_25 ( void )
{
return F_26 ( & V_51 ) ;
}
static T_5 void F_27 ( void )
{
F_28 ( & V_51 ) ;
}
