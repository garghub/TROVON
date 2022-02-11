static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 ;
if ( ! V_4 -> V_9 )
return;
V_8 = V_4 -> V_8 ;
if ( V_8 && ! V_4 -> V_10 ) {
F_3 ( V_7 ) ;
V_4 -> V_10 = 1 ;
}
F_4 ( V_7 , V_4 -> V_11 , 0 ,
V_12 , V_8 ) ;
if ( ! V_8 && V_4 -> V_10 ) {
V_4 -> V_10 = 0 ;
F_5 ( V_7 ) ;
}
}
static int F_6 ( struct V_3 * V_4 , int V_13 )
{
if ( V_13 <= 0 )
return 0 ;
V_13 *= 1000 ;
V_13 = V_13 - V_14
+ V_15 / 2 ;
if ( V_13 < 0 )
V_13 = 0 ;
else if ( V_13 >= ( V_16 - V_14 ) )
V_13 = 1 ;
else {
V_13 /= V_15 ;
V_13 = 255 - V_13 ;
}
return V_13 ;
}
static int F_7 ( struct V_3 * V_4 , int V_13 )
{
if ( V_13 <= 0 )
return 0 ;
V_13 = 12000 / V_13 ;
if ( V_13 > 0xff )
return 0xff ;
if ( V_13 <= 0 )
return 1 ;
return V_13 ;
}
static int F_8 ( struct V_17 * V_18 , unsigned int type ,
unsigned int V_19 , int V_13 )
{
struct V_3 * V_4 = F_9 ( V_18 ) ;
switch ( V_19 ) {
case V_20 :
if ( V_13 )
V_13 = 1000 ;
case V_21 :
if ( V_4 -> V_22 )
V_4 -> V_8 = F_6 ( V_4 , V_13 ) ;
else
V_4 -> V_8 = F_7 ( V_4 , V_13 ) ;
break;
default:
return - 1 ;
}
F_10 ( & V_4 -> V_5 ) ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_5 ) ;
if ( V_4 -> V_10 ) {
F_4 ( V_4 -> V_7 , V_4 -> V_11 , 0 ,
V_12 , 0 ) ;
V_4 -> V_10 = 0 ;
F_5 ( V_4 -> V_7 ) ;
}
}
static void F_13 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_11 ( V_4 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_17 * V_17 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_23 ;
V_17 = F_16 () ;
if ( ! V_17 ) {
F_17 ( V_24 L_1 ) ;
return - V_25 ;
}
V_17 -> V_26 = L_2 ;
V_17 -> V_27 = V_4 -> V_27 ;
V_17 -> V_28 . V_29 = V_30 ;
V_17 -> V_28 . V_31 = V_7 -> V_32 >> 16 ;
V_17 -> V_28 . V_33 = V_7 -> V_32 & 0xffff ;
V_17 -> V_28 . V_34 = 0x01 ;
V_17 -> V_35 [ 0 ] = F_18 ( V_36 ) ;
V_17 -> V_37 [ 0 ] = F_18 ( V_20 ) | F_18 ( V_21 ) ;
V_17 -> V_38 = F_8 ;
V_17 -> V_18 . V_39 = & V_7 -> V_40 -> V_41 -> V_18 ;
F_19 ( V_17 , V_4 ) ;
V_23 = F_20 ( V_17 ) ;
if ( V_23 < 0 ) {
F_21 ( V_17 ) ;
F_17 ( V_24 L_3 ) ;
return V_23 ;
}
V_4 -> V_18 = V_17 ;
return 0 ;
}
int F_22 ( struct V_6 * V_7 , int V_42 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
if ( ! V_4 )
return 0 ;
V_42 = ! ! V_42 ;
if ( V_4 -> V_9 != V_42 ) {
V_4 -> V_9 = V_42 ;
if ( ! V_42 )
F_11 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
int F_23 ( struct V_6 * V_7 , int V_11 )
{
struct V_3 * V_4 ;
int V_23 ;
if ( ! F_24 ( V_7 , L_4 ) )
return 0 ;
if ( V_7 -> V_43 == V_44 )
return 0 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_45 ) ;
if ( V_4 == NULL )
return - V_25 ;
snprintf ( V_4 -> V_27 , sizeof( V_4 -> V_27 ) ,
L_5 , V_7 -> V_40 -> V_46 -> V_47 , V_7 -> V_48 ) ;
F_26 ( V_7 , V_11 , 0 ,
V_49 , 0x01 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_7 = V_7 ;
V_7 -> V_4 = V_4 ;
F_27 ( & V_4 -> V_5 , & F_1 ) ;
F_28 ( & V_4 -> V_50 ) ;
V_23 = F_15 ( V_4 ) ;
if ( V_23 < 0 ) {
F_29 ( V_4 ) ;
V_7 -> V_4 = NULL ;
return V_23 ;
}
return 0 ;
}
void F_30 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 ) {
if ( V_4 -> V_18 )
F_13 ( V_4 ) ;
V_7 -> V_4 = NULL ;
F_29 ( V_4 ) ;
}
}
static bool F_31 ( struct V_51 * V_52 )
{
struct V_6 * V_7 = F_32 ( V_52 ) ;
return F_33 ( V_7 , F_34 ( V_52 ) ,
F_35 ( V_52 ) ) & V_53 ;
}
int F_36 ( struct V_51 * V_52 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_32 ( V_52 ) ;
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 && ( ! V_4 -> V_9 || ! F_31 ( V_52 ) ) ) {
V_55 -> V_56 . integer . V_56 [ 0 ] =
V_55 -> V_56 . integer . V_56 [ 1 ] = V_4 -> V_9 ;
return 0 ;
}
return F_37 ( V_52 , V_55 ) ;
}
int F_38 ( struct V_51 * V_52 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_32 ( V_52 ) ;
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 ) {
T_1 V_57 = F_39 ( V_52 ) ;
int V_42 = 0 ;
long * V_58 = V_55 -> V_56 . integer . V_56 ;
if ( V_57 & 1 ) {
V_42 |= * V_58 ;
V_58 ++ ;
}
if ( V_57 & 2 )
V_42 |= * V_58 ;
F_22 ( V_7 , V_42 ) ;
}
if ( ! F_31 ( V_52 ) )
return 0 ;
return F_40 ( V_52 , V_55 ) ;
}
