static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 && ! V_2 -> V_6 ) {
F_2 ( V_5 ) ;
if ( V_2 -> V_7 )
V_2 -> V_7 ( V_2 , true ) ;
V_2 -> V_6 = 1 ;
}
F_3 ( V_5 , V_2 -> V_8 , 0 ,
V_9 , V_3 ) ;
if ( ! V_3 && V_2 -> V_6 ) {
V_2 -> V_6 = 0 ;
if ( V_2 -> V_7 )
V_2 -> V_7 ( V_2 , false ) ;
F_4 ( V_5 ) ;
}
}
static void F_5 ( struct V_10 * V_11 )
{
struct V_1 * V_2 =
F_6 ( V_11 , struct V_1 , V_12 ) ;
if ( V_2 -> V_13 )
F_1 ( V_2 , V_2 -> V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_14 )
{
if ( V_14 <= 0 )
return 0 ;
V_14 *= 1000 ;
V_14 = V_14 - V_15
+ V_16 / 2 ;
if ( V_14 < 0 )
V_14 = 0 ;
else if ( V_14 >= ( V_17 - V_15 ) )
V_14 = 1 ;
else {
V_14 /= V_16 ;
V_14 = 255 - V_14 ;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 , int V_14 )
{
if ( V_14 <= 0 )
return 0 ;
V_14 = 12000 / V_14 ;
if ( V_14 > 0xff )
return 0xff ;
if ( V_14 <= 0 )
return 1 ;
return V_14 ;
}
static int F_9 ( struct V_18 * V_19 , unsigned int type ,
unsigned int V_20 , int V_14 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
switch ( V_20 ) {
case V_21 :
if ( V_14 )
V_14 = 1000 ;
case V_22 :
if ( V_2 -> V_23 )
V_2 -> V_3 = F_7 ( V_2 , V_14 ) ;
else
V_2 -> V_3 = F_8 ( V_2 , V_14 ) ;
break;
default:
return - 1 ;
}
F_11 ( & V_2 -> V_12 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_6 ) {
F_1 ( V_2 , 0 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 )
F_15 ( V_2 -> V_19 ) ;
else
F_16 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
F_12 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_18 * V_18 ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_18 = F_18 () ;
if ( ! V_18 )
return - V_25 ;
V_18 -> V_26 = L_1 ;
V_18 -> V_27 = V_2 -> V_27 ;
V_18 -> V_28 . V_29 = V_30 ;
V_18 -> V_19 . V_31 = & V_5 -> V_32 -> V_33 ;
V_18 -> V_28 . V_34 = V_5 -> V_35 . V_36 >> 16 ;
V_18 -> V_28 . V_37 = V_5 -> V_35 . V_36 & 0xffff ;
V_18 -> V_28 . V_38 = 0x01 ;
V_18 -> V_39 [ 0 ] = F_19 ( V_40 ) ;
V_18 -> V_41 [ 0 ] = F_19 ( V_21 ) | F_19 ( V_22 ) ;
V_18 -> V_42 = F_9 ;
F_20 ( V_18 , V_2 ) ;
V_2 -> V_19 = V_18 ;
return 0 ;
}
int F_21 ( struct V_4 * V_5 , int V_43 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( ! V_2 )
return 0 ;
V_43 = ! ! V_43 ;
if ( V_2 -> V_13 != V_43 ) {
V_2 -> V_13 = V_43 ;
if ( ! V_43 )
F_12 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
int F_22 ( struct V_4 * V_5 , int V_8 )
{
struct V_1 * V_2 ;
int V_44 ;
if ( ! F_23 ( V_5 , L_2 ) )
return 0 ;
if ( V_5 -> V_45 == V_46 )
return 0 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_47 ) ;
if ( V_2 == NULL )
return - V_25 ;
snprintf ( V_2 -> V_27 , sizeof( V_2 -> V_27 ) ,
L_3 , V_5 -> V_32 -> V_48 , V_5 -> V_49 ) ;
F_25 ( V_5 , V_8 , 0 ,
V_50 , 0x01 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_2 = V_2 ;
F_26 ( & V_2 -> V_12 , & F_5 ) ;
F_27 ( & V_2 -> V_51 ) ;
V_44 = F_17 ( V_2 ) ;
if ( V_44 < 0 ) {
F_28 ( V_2 ) ;
V_5 -> V_2 = NULL ;
return V_44 ;
}
return 0 ;
}
void F_29 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_2 ) {
if ( V_2 -> V_19 )
F_14 ( V_2 ) ;
V_5 -> V_2 = NULL ;
F_28 ( V_2 ) ;
}
}
int F_30 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
int V_44 ;
if ( ! V_2 || ! V_2 -> V_19 )
return 0 ;
V_44 = F_31 ( V_2 -> V_19 ) ;
if ( V_44 < 0 ) {
F_32 ( V_5 , L_4 ) ;
F_16 ( V_2 -> V_19 ) ;
V_5 -> V_2 = NULL ;
F_28 ( V_2 ) ;
return V_44 ;
}
V_2 -> V_24 = true ;
return 0 ;
}
static bool F_33 ( struct V_52 * V_53 )
{
struct V_4 * V_5 = F_34 ( V_53 ) ;
return F_35 ( V_5 , F_36 ( V_53 ) ,
F_37 ( V_53 ) ) & V_54 ;
}
int F_38 ( struct V_52 * V_53 ,
struct V_55 * V_56 )
{
struct V_4 * V_5 = F_34 ( V_53 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_2 && ( ! V_2 -> V_13 || ! F_33 ( V_53 ) ) ) {
V_56 -> V_57 . integer . V_57 [ 0 ] =
V_56 -> V_57 . integer . V_57 [ 1 ] = V_2 -> V_13 ;
return 0 ;
}
return F_39 ( V_53 , V_56 ) ;
}
int F_40 ( struct V_52 * V_53 ,
struct V_55 * V_56 )
{
struct V_4 * V_5 = F_34 ( V_53 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_2 ) {
T_1 V_58 = F_41 ( V_53 ) ;
int V_43 = 0 ;
long * V_59 = V_56 -> V_57 . integer . V_57 ;
if ( V_58 & 1 ) {
V_43 |= * V_59 ;
V_59 ++ ;
}
if ( V_58 & 2 )
V_43 |= * V_59 ;
F_21 ( V_5 , V_43 ) ;
}
if ( ! F_33 ( V_53 ) )
return 0 ;
return F_42 ( V_53 , V_56 ) ;
}
