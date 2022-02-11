static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_6 ;
V_5 = F_3 ( V_4 -> V_7 , 0 , V_4 -> V_8 ,
& V_6 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_7 , L_1 ,
V_4 -> V_8 ) ;
return V_5 ;
}
if ( V_6 & V_9 )
return 0 ;
V_6 |= V_9 ;
V_5 = F_5 ( V_4 -> V_7 , 0 , V_4 -> V_8 ,
V_6 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_7 , L_2 ,
V_4 -> V_8 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_6 ;
F_7 ( L_3 ) ;
if ( V_4 -> V_8 == V_10 ) {
F_8 ( & V_2 -> V_7 , L_4 ) ;
return F_5 ( V_4 -> V_7 , 0 ,
V_10 , 0x00U ) ;
}
V_5 = F_3 ( V_4 -> V_7 , 0 , V_4 -> V_8 ,
& V_6 ) ;
if ( V_5 ) {
F_9 ( & V_2 -> V_7 , L_5 ,
V_4 -> V_8 ) ;
return V_5 ;
}
V_6 &= ~ V_9 ;
return F_5 ( V_4 -> V_7 , 0 , V_4 -> V_8 ,
V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_7 , 0 , V_4 -> V_8 ,
& V_6 ) ;
if ( V_5 ) {
F_9 ( & V_2 -> V_7 , L_5 ,
V_4 -> V_8 ) ;
return V_5 ;
}
return V_6 & V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_7 , 0 ,
V_4 -> V_8 , & V_6 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_7 ,
L_6 ,
V_4 -> V_8 ) ;
return V_5 ;
}
V_6 &= 0xE0 ;
V_6 >>= 5 ;
if ( V_6 >= V_2 -> V_11 -> V_12 ) {
F_9 ( & V_2 -> V_7 ,
L_7 ,
V_4 -> V_8 ) ;
return - V_13 ;
}
return V_2 -> V_11 -> V_14 [ V_6 ] ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_7 , 0 ,
V_4 -> V_8 , & V_6 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_7 ,
L_8 ,
V_4 -> V_8 ) ;
return V_5 ;
}
V_6 &= ~ 0xE0 ;
V_6 |= ( V_15 << 5 ) ;
V_5 = F_5 ( V_4 -> V_7 , 0 ,
V_4 -> V_8 , V_6 ) ;
if ( V_5 )
F_4 ( & V_2 -> V_7 , L_9 ,
V_4 -> V_8 ) ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_5 ;
int V_17 ;
T_1 V_18 ;
if ( V_4 -> V_8 == V_19 )
V_18 = V_20 ;
else if ( V_4 -> V_8 == V_21 )
V_18 = V_22 ;
else
return - V_13 ;
V_17 = F_14 ( V_2 , V_16 , V_16 ) ;
V_5 = F_3 ( V_4 -> V_7 , 0 ,
V_18 , & V_6 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_7 ,
L_8 ,
V_18 ) ;
return V_5 ;
}
V_6 &= ~ 0xE0 ;
V_6 |= ( V_17 << 5 ) ;
V_5 = F_5 ( V_4 -> V_7 , 0 ,
V_18 , V_6 ) ;
if ( V_5 )
F_4 ( & V_2 -> V_7 , L_9 ,
V_4 -> V_8 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_23 -> V_24 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_11 -> V_25 ;
}
static int T_2 F_17 ( struct V_26 * V_27 )
{
struct V_28 * V_23 = V_27 -> V_7 . V_29 ;
struct V_30 V_31 = { } ;
int V_5 = 0 ;
T_1 V_32 ;
int V_33 ;
V_5 = F_3 ( & V_27 -> V_7 , 0 ,
V_10 , & V_32 ) ;
if ( V_5 ) {
F_9 ( & V_27 -> V_7 , L_10 ) ;
return V_5 ;
}
if ( V_32 & 0x10 )
F_18 ( & V_27 -> V_7 ,
L_11 ) ;
else
F_18 ( & V_27 -> V_7 ,
L_12 ) ;
for ( V_33 = 0 ; V_33 < F_19 ( V_34 ) ; V_33 ++ ) {
V_5 = F_5 ( & V_27 -> V_7 , 0 ,
V_34 [ V_33 ] ,
V_23 -> V_35 [ V_33 ] ) ;
if ( V_5 ) {
F_9 ( & V_27 -> V_7 , L_13 ,
V_5 ) ;
return V_5 ;
}
}
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
struct V_3 * V_2 = & V_37 [ V_33 ] ;
struct V_1 * V_38 ;
V_2 -> V_7 = & V_27 -> V_7 ;
V_2 -> V_23 = V_23 ;
V_31 . V_7 = & V_27 -> V_7 ;
V_31 . V_39 = V_2 ;
V_31 . V_40 = & V_23 -> V_41 [ V_33 ] ;
V_38 = F_20 ( & V_42 [ V_33 ] , & V_31 ) ;
if ( F_21 ( V_38 ) ) {
V_5 = F_22 ( V_38 ) ;
F_9 ( & V_27 -> V_7 ,
L_14 ,
V_43 , V_42 [ V_33 ] . V_44 ,
V_5 ) ;
while ( -- V_33 >= 0 )
F_23 ( V_37 [ V_33 ] . V_38 ) ;
return V_5 ;
}
V_2 -> V_38 = V_38 ;
}
return 0 ;
}
static int T_3 F_24 ( struct V_26 * V_27 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
struct V_3 * V_2 = & V_37 [ V_33 ] ;
F_23 ( V_2 -> V_38 ) ;
}
return 0 ;
}
static T_4 int F_25 ( void )
{
return F_26 ( & V_45 ) ;
}
static T_5 void F_27 ( void )
{
F_28 ( & V_45 ) ;
}
