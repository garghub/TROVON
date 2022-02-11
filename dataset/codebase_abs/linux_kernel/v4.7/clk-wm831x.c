static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
return V_4 -> V_6 ;
}
static unsigned long F_3 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
if ( V_4 -> V_6 )
return 32768 ;
else
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_11 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_1 ,
V_10 ) ;
return true ;
}
return ( V_10 & V_13 ) != 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_8 ( V_9 , V_11 ,
V_13 , V_13 ) ;
if ( V_10 != 0 )
F_9 ( V_9 -> V_12 , L_2 , V_10 ) ;
F_10 ( 2000 , 2000 ) ;
return V_10 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_8 ( V_9 , V_11 , V_13 , 0 ) ;
if ( V_10 != 0 )
F_9 ( V_9 -> V_12 , L_3 , V_10 ) ;
}
static unsigned long F_12 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_14 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_4 ,
V_10 ) ;
return 0 ;
}
if ( V_10 & V_15 )
return V_16 [ V_10 & V_17 ] ;
F_6 ( V_9 -> V_12 , L_5 ) ;
return 0 ;
}
static long F_13 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long * V_19 )
{
int V_20 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_16 ) ; V_21 ++ )
if ( abs ( V_16 [ V_21 ] - V_18 ) <
abs ( V_16 [ V_20 ] - V_18 ) )
V_20 = V_21 ;
return V_16 [ V_20 ] ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_16 ) ; V_21 ++ )
if ( V_16 [ V_21 ] == V_18 )
break;
if ( V_21 == F_14 ( V_16 ) )
return - V_22 ;
if ( F_4 ( V_2 ) )
return - V_23 ;
return F_8 ( V_9 , V_14 ,
V_17 , V_21 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_14 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_4 ,
V_10 ) ;
return 0 ;
}
if ( V_10 & V_15 )
return 0 ;
V_10 = F_5 ( V_9 , V_24 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_6 ,
V_10 ) ;
return 0 ;
}
switch ( V_10 & V_25 ) {
case 0 :
return 0 ;
case 1 :
return 1 ;
default:
F_6 ( V_9 -> V_12 , L_7 ,
V_10 & V_25 ) ;
return 0 ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_26 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_27 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_8 ,
V_10 ) ;
return true ;
}
return ( V_10 & V_28 ) != 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_26 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_19 ( V_9 ) ;
if ( V_10 != 0 ) {
F_9 ( V_9 -> V_12 , L_9 , V_10 ) ;
return V_10 ;
}
V_10 = F_8 ( V_9 , V_27 ,
V_28 , V_28 ) ;
if ( V_10 != 0 )
F_9 ( V_9 -> V_12 , L_10 , V_10 ) ;
F_20 ( V_9 ) ;
return V_10 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_26 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_19 ( V_9 ) ;
if ( V_10 != 0 ) {
F_9 ( V_9 -> V_12 , L_9 , V_10 ) ;
return;
}
V_10 = F_8 ( V_9 , V_27 ,
V_28 , 0 ) ;
if ( V_10 != 0 )
F_9 ( V_9 -> V_12 , L_11 , V_10 ) ;
F_20 ( V_9 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_26 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_27 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_8 ,
V_10 ) ;
return 0 ;
}
if ( V_10 & V_29 )
return 1 ;
else
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_26 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
return F_8 ( V_9 , V_27 ,
V_29 ,
V_30 << V_31 ) ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_9 * V_9 = F_25 ( V_33 -> V_12 . V_30 ) ;
struct V_3 * V_4 ;
int V_10 ;
V_4 = F_26 ( & V_33 -> V_12 , sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 )
return - V_35 ;
V_4 -> V_9 = V_9 ;
V_10 = F_5 ( V_9 , V_14 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_4 ,
V_10 ) ;
return V_10 ;
}
V_4 -> V_6 = V_10 & V_36 ;
V_4 -> V_5 . V_37 = & V_38 ;
V_4 -> V_39 = F_27 ( & V_33 -> V_12 , & V_4 -> V_5 ) ;
if ( F_28 ( V_4 -> V_39 ) )
return F_29 ( V_4 -> V_39 ) ;
V_4 -> V_8 . V_37 = & V_40 ;
V_4 -> V_41 = F_27 ( & V_33 -> V_12 , & V_4 -> V_8 ) ;
if ( F_28 ( V_4 -> V_41 ) )
return F_29 ( V_4 -> V_41 ) ;
V_4 -> V_26 . V_37 = & V_42 ;
V_4 -> V_43 = F_27 ( & V_33 -> V_12 , & V_4 -> V_26 ) ;
if ( F_28 ( V_4 -> V_43 ) )
return F_29 ( V_4 -> V_43 ) ;
F_30 ( V_33 , V_4 ) ;
return 0 ;
}
