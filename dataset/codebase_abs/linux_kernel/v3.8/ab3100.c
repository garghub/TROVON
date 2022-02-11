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
static int F_16 ( struct V_25 * V_26 )
{
struct V_27 * V_23 = V_26 -> V_7 . V_28 ;
struct V_29 V_30 = { } ;
int V_5 = 0 ;
T_1 V_31 ;
int V_32 ;
V_5 = F_3 ( & V_26 -> V_7 , 0 ,
V_10 , & V_31 ) ;
if ( V_5 ) {
F_9 ( & V_26 -> V_7 , L_10 ) ;
return V_5 ;
}
if ( V_31 & 0x10 )
F_17 ( & V_26 -> V_7 ,
L_11 ) ;
else
F_17 ( & V_26 -> V_7 ,
L_12 ) ;
for ( V_32 = 0 ; V_32 < F_18 ( V_33 ) ; V_32 ++ ) {
V_5 = F_5 ( & V_26 -> V_7 , 0 ,
V_33 [ V_32 ] ,
V_23 -> V_34 [ V_32 ] ) ;
if ( V_5 ) {
F_9 ( & V_26 -> V_7 , L_13 ,
V_5 ) ;
return V_5 ;
}
}
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
struct V_3 * V_2 = & V_36 [ V_32 ] ;
struct V_1 * V_37 ;
V_2 -> V_7 = & V_26 -> V_7 ;
V_2 -> V_23 = V_23 ;
V_30 . V_7 = & V_26 -> V_7 ;
V_30 . V_38 = V_2 ;
V_30 . V_39 = & V_23 -> V_40 [ V_32 ] ;
V_37 = F_19 ( & V_41 [ V_32 ] , & V_30 ) ;
if ( F_20 ( V_37 ) ) {
V_5 = F_21 ( V_37 ) ;
F_9 ( & V_26 -> V_7 ,
L_14 ,
V_42 , V_41 [ V_32 ] . V_43 ,
V_5 ) ;
while ( -- V_32 >= 0 )
F_22 ( V_36 [ V_32 ] . V_37 ) ;
return V_5 ;
}
V_2 -> V_37 = V_37 ;
}
return 0 ;
}
static int F_23 ( struct V_25 * V_26 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
struct V_3 * V_2 = & V_36 [ V_32 ] ;
F_22 ( V_2 -> V_37 ) ;
}
return 0 ;
}
static T_2 int F_24 ( void )
{
return F_25 ( & V_44 ) ;
}
static T_3 void F_26 ( void )
{
F_27 ( & V_44 ) ;
}
