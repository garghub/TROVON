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
if ( V_4 -> V_23 )
F_14 ( V_4 -> V_18 ) ;
else
F_15 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_11 ( V_4 ) ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_17 * V_17 ;
struct V_6 * V_7 = V_4 -> V_7 ;
V_17 = F_17 () ;
if ( ! V_17 )
return - V_24 ;
V_17 -> V_25 = L_1 ;
V_17 -> V_26 = V_4 -> V_26 ;
V_17 -> V_27 . V_28 = V_29 ;
V_17 -> V_27 . V_30 = V_7 -> V_31 >> 16 ;
V_17 -> V_27 . V_32 = V_7 -> V_31 & 0xffff ;
V_17 -> V_27 . V_33 = 0x01 ;
V_17 -> V_34 [ 0 ] = F_18 ( V_35 ) ;
V_17 -> V_36 [ 0 ] = F_18 ( V_20 ) | F_18 ( V_21 ) ;
V_17 -> V_37 = F_8 ;
V_17 -> V_18 . V_38 = & V_7 -> V_18 ;
F_19 ( V_17 , V_4 ) ;
V_4 -> V_18 = V_17 ;
return 0 ;
}
int F_20 ( struct V_6 * V_7 , int V_39 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
if ( ! V_4 )
return 0 ;
V_39 = ! ! V_39 ;
if ( V_4 -> V_9 != V_39 ) {
V_4 -> V_9 = V_39 ;
if ( ! V_39 )
F_11 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
int F_21 ( struct V_6 * V_7 , int V_11 )
{
struct V_3 * V_4 ;
int V_40 ;
if ( ! F_22 ( V_7 , L_2 ) )
return 0 ;
if ( V_7 -> V_41 == V_42 )
return 0 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_43 ) ;
if ( V_4 == NULL )
return - V_24 ;
snprintf ( V_4 -> V_26 , sizeof( V_4 -> V_26 ) ,
L_3 , V_7 -> V_44 -> V_45 -> V_46 , V_7 -> V_47 ) ;
F_24 ( V_7 , V_11 , 0 ,
V_48 , 0x01 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_7 = V_7 ;
V_7 -> V_4 = V_4 ;
F_25 ( & V_4 -> V_5 , & F_1 ) ;
F_26 ( & V_4 -> V_49 ) ;
V_40 = F_16 ( V_4 ) ;
if ( V_40 < 0 ) {
F_27 ( V_4 ) ;
V_7 -> V_4 = NULL ;
return V_40 ;
}
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 ) {
if ( V_4 -> V_18 )
F_13 ( V_4 ) ;
V_7 -> V_4 = NULL ;
F_27 ( V_4 ) ;
}
}
int F_29 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
int V_40 ;
if ( ! V_4 || ! V_4 -> V_18 )
return 0 ;
V_40 = F_30 ( V_4 -> V_18 ) ;
if ( V_40 < 0 ) {
F_31 ( V_7 , L_4 ) ;
F_15 ( V_4 -> V_18 ) ;
V_7 -> V_4 = NULL ;
F_27 ( V_4 ) ;
return V_40 ;
}
V_4 -> V_23 = true ;
return 0 ;
}
static bool F_32 ( struct V_50 * V_51 )
{
struct V_6 * V_7 = F_33 ( V_51 ) ;
return F_34 ( V_7 , F_35 ( V_51 ) ,
F_36 ( V_51 ) ) & V_52 ;
}
int F_37 ( struct V_50 * V_51 ,
struct V_53 * V_54 )
{
struct V_6 * V_7 = F_33 ( V_51 ) ;
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 && ( ! V_4 -> V_9 || ! F_32 ( V_51 ) ) ) {
V_54 -> V_55 . integer . V_55 [ 0 ] =
V_54 -> V_55 . integer . V_55 [ 1 ] = V_4 -> V_9 ;
return 0 ;
}
return F_38 ( V_51 , V_54 ) ;
}
int F_39 ( struct V_50 * V_51 ,
struct V_53 * V_54 )
{
struct V_6 * V_7 = F_33 ( V_51 ) ;
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 ) {
T_1 V_56 = F_40 ( V_51 ) ;
int V_39 = 0 ;
long * V_57 = V_54 -> V_55 . integer . V_55 ;
if ( V_56 & 1 ) {
V_39 |= * V_57 ;
V_57 ++ ;
}
if ( V_56 & 2 )
V_39 |= * V_57 ;
F_20 ( V_7 , V_39 ) ;
}
if ( ! F_32 ( V_51 ) )
return 0 ;
return F_41 ( V_51 , V_54 ) ;
}
