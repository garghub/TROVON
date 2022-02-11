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
V_10 = F_8 ( V_9 , V_14 ,
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
V_10 = F_8 ( V_9 , V_14 , V_13 , 0 ) ;
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
V_10 = F_5 ( V_9 , V_15 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_4 ,
V_10 ) ;
return 0 ;
}
if ( V_10 & V_16 )
return V_17 [ V_10 & V_18 ] ;
F_6 ( V_9 -> V_12 , L_5 ) ;
return 0 ;
}
static long F_13 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long * V_20 )
{
int V_21 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_14 ( V_17 ) ; V_22 ++ )
if ( abs ( V_17 [ V_22 ] - V_19 ) <
abs ( V_17 [ V_21 ] - V_19 ) )
V_21 = V_22 ;
return V_17 [ V_21 ] ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_14 ( V_17 ) ; V_22 ++ )
if ( V_17 [ V_22 ] == V_19 )
break;
if ( V_22 == F_14 ( V_17 ) )
return - V_23 ;
if ( F_4 ( V_2 ) )
return - V_24 ;
return F_8 ( V_9 , V_15 ,
V_18 , V_22 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_8 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_15 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_4 ,
V_10 ) ;
return 0 ;
}
if ( V_10 & V_16 )
return 0 ;
V_10 = F_5 ( V_9 , V_25 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_6 ,
V_10 ) ;
return 0 ;
}
switch ( V_10 & V_26 ) {
case 0 :
return 0 ;
case 1 :
return 1 ;
default:
F_6 ( V_9 -> V_12 , L_7 ,
V_10 & V_26 ) ;
return 0 ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_27 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_28 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_8 ,
V_10 ) ;
return true ;
}
return ( V_10 & V_29 ) != 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_27 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_19 ( V_9 ) ;
if ( V_10 != 0 ) {
F_9 ( V_9 -> V_12 , L_9 , V_10 ) ;
return V_10 ;
}
V_10 = F_8 ( V_9 , V_28 ,
V_29 , V_29 ) ;
if ( V_10 != 0 )
F_9 ( V_9 -> V_12 , L_10 , V_10 ) ;
F_20 ( V_9 ) ;
return V_10 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_27 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_19 ( V_9 ) ;
if ( V_10 != 0 ) {
F_9 ( V_9 -> V_12 , L_9 , V_10 ) ;
return;
}
V_10 = F_8 ( V_9 , V_28 ,
V_29 , 0 ) ;
if ( V_10 != 0 )
F_9 ( V_9 -> V_12 , L_11 , V_10 ) ;
F_20 ( V_9 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_27 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_9 , V_28 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_8 ,
V_10 ) ;
return 0 ;
}
if ( V_10 & V_30 )
return 0 ;
else
return 1 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_27 ) ;
struct V_9 * V_9 = V_4 -> V_9 ;
return F_8 ( V_9 , V_28 ,
V_30 ,
V_31 << V_32 ) ;
}
static int F_24 ( struct V_33 * V_34 )
{
struct V_9 * V_9 = F_25 ( V_34 -> V_12 . V_31 ) ;
struct V_3 * V_4 ;
int V_10 ;
V_4 = F_26 ( & V_34 -> V_12 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_10 = F_5 ( V_9 , V_15 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 -> V_12 , L_4 ,
V_10 ) ;
return V_10 ;
}
V_4 -> V_6 = V_10 & V_37 ;
V_4 -> V_5 . V_38 = & V_39 ;
V_4 -> V_40 = F_27 ( & V_34 -> V_12 , & V_4 -> V_5 ) ;
if ( F_28 ( V_4 -> V_40 ) )
return F_29 ( V_4 -> V_40 ) ;
V_4 -> V_8 . V_38 = & V_41 ;
V_4 -> V_42 = F_27 ( & V_34 -> V_12 , & V_4 -> V_8 ) ;
if ( F_28 ( V_4 -> V_42 ) )
return F_29 ( V_4 -> V_42 ) ;
V_4 -> V_27 . V_38 = & V_43 ;
V_4 -> V_44 = F_27 ( & V_34 -> V_12 , & V_4 -> V_27 ) ;
if ( F_28 ( V_4 -> V_44 ) )
return F_29 ( V_4 -> V_44 ) ;
F_30 ( & V_34 -> V_12 , V_4 ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
return 0 ;
}
