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
if ( V_4 -> V_23 )
return V_4 -> V_23 -> V_24 ;
else
return 0 ;
}
static int F_16 ( struct V_25 * V_26 ,
struct V_27 * V_23 ,
struct V_28 * V_29 ,
struct V_30 * V_31 ,
int V_32 )
{
struct V_33 * V_11 ;
struct V_3 * V_2 ;
struct V_1 * V_34 ;
struct V_35 V_36 = { } ;
int V_5 , V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_11 = & V_39 [ V_37 ] ;
if ( V_11 -> V_32 == V_32 )
break;
}
if ( V_11 -> V_32 != V_32 )
return - V_40 ;
V_2 = & V_41 [ V_37 ] ;
V_2 -> V_7 = & V_26 -> V_7 ;
if ( V_23 ) {
V_2 -> V_23 = V_23 ;
V_36 . V_29 = & V_23 -> V_42 [ V_37 ] ;
} else if ( V_31 ) {
V_36 . V_43 = V_31 ;
V_36 . V_29 = V_29 ;
}
V_36 . V_7 = & V_26 -> V_7 ;
V_36 . V_44 = V_2 ;
V_34 = F_17 ( V_11 , & V_36 ) ;
if ( F_18 ( V_34 ) ) {
V_5 = F_19 ( V_34 ) ;
F_9 ( & V_26 -> V_7 ,
L_10 ,
V_45 , V_11 -> V_46 ,
V_5 ) ;
return V_5 ;
}
V_2 -> V_34 = V_34 ;
return 0 ;
}
static int F_20 ( struct V_25 * V_26 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
struct V_3 * V_2 = & V_41 [ V_37 ] ;
F_21 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
return 0 ;
}
static int
F_22 ( struct V_25 * V_26 , struct V_30 * V_31 )
{
int V_5 , V_37 ;
for ( V_37 = 0 ; V_37 < F_23 ( V_47 ) ; V_37 ++ ) {
V_5 = F_5 ( & V_26 -> V_7 , 0 ,
V_47 [ V_37 ] ,
V_48 [ V_37 ] ) ;
if ( V_5 ) {
F_9 ( & V_26 -> V_7 , L_11 ,
V_5 ) ;
return V_5 ;
}
}
for ( V_37 = 0 ; V_37 < F_23 ( V_49 ) ; V_37 ++ ) {
V_5 = F_16 (
V_26 , NULL , V_49 [ V_37 ] . V_29 ,
V_49 [ V_37 ] . V_43 ,
( int ) V_49 [ V_37 ] . V_44 ) ;
if ( V_5 ) {
F_20 ( V_26 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_27 * V_23 = F_25 ( & V_26 -> V_7 ) ;
struct V_30 * V_31 = V_26 -> V_7 . V_43 ;
int V_5 = 0 ;
T_1 V_50 ;
int V_37 ;
V_5 = F_3 ( & V_26 -> V_7 , 0 ,
V_10 , & V_50 ) ;
if ( V_5 ) {
F_9 ( & V_26 -> V_7 , L_12 ) ;
return V_5 ;
}
if ( V_50 & 0x10 )
F_26 ( & V_26 -> V_7 ,
L_13 ) ;
else
F_26 ( & V_26 -> V_7 ,
L_14 ) ;
if ( V_31 ) {
V_5 = F_27 ( & V_26 -> V_7 , V_31 ,
V_49 ,
F_23 ( V_49 ) ) ;
if ( V_5 < 0 ) {
F_9 ( & V_26 -> V_7 ,
L_15 , V_5 ) ;
return V_5 ;
}
return F_22 ( V_26 , V_31 ) ;
}
for ( V_37 = 0 ; V_37 < F_23 ( V_47 ) ; V_37 ++ ) {
V_5 = F_5 ( & V_26 -> V_7 , 0 ,
V_47 [ V_37 ] ,
V_23 -> V_51 [ V_37 ] ) ;
if ( V_5 ) {
F_9 ( & V_26 -> V_7 , L_11 ,
V_5 ) ;
return V_5 ;
}
}
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
struct V_33 * V_11 = & V_39 [ V_37 ] ;
V_5 = F_16 ( V_26 , V_23 , NULL , NULL ,
V_11 -> V_32 ) ;
if ( V_5 ) {
F_20 ( V_26 ) ;
return V_5 ;
}
}
return 0 ;
}
static T_2 int F_28 ( void )
{
return F_29 ( & V_52 ) ;
}
static T_3 void F_30 ( void )
{
F_31 ( & V_52 ) ;
}
