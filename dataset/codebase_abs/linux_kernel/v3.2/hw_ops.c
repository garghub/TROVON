static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
struct V_5 T_2 * V_6 = V_4 -> V_7 ;
T_1 V_8 ;
int V_9 = 0 ;
F_2 ( & V_4 -> V_10 ) ;
V_8 = F_3 ( & V_6 -> V_11 ) ;
if ( V_8 & 0x0000ff ) {
* V_3 = F_3 ( & V_6 -> V_12 ) ;
V_9 = 4 ;
}
F_4 ( & V_4 -> V_10 ) ;
return V_9 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_4 -> V_7 -> V_11 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_9 = 0 ;
T_1 V_14 ;
F_2 ( & V_4 -> V_10 ) ;
V_14 = F_3 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_13 & ( V_15 | V_16 ) ) {
if ( V_14 & 0xff0000 )
V_9 |= V_15 | V_16 ;
else {
F_7 ( V_4 , 2 , V_17 ) ;
F_8 ( V_4 , 2 , V_18 ) ;
}
}
if ( V_13 & ( V_19 | V_20 ) ) {
if ( V_14 & 0x00ff00 )
V_9 = V_19 | V_20 ;
else {
F_7 ( V_4 , 2 ,
V_21 ) ;
F_8 ( V_4 , 2 ,
V_22 ) ;
}
}
F_4 ( & V_4 -> V_10 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
struct V_5 T_2 * V_6 = V_4 -> V_7 ;
struct V_23 T_2 * V_24 = V_4 -> V_24 ;
int V_9 ;
F_2 ( & V_4 -> V_10 ) ;
if ( F_3 ( & V_6 -> V_11 ) & 0xff0000 ) {
* V_3 = F_10 ( & V_24 -> V_25 ) ;
V_9 = 4 ;
} else {
F_8 ( V_4 , 2 , V_18 ) ;
V_9 = 0 ;
}
F_4 ( & V_4 -> V_10 ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
struct V_5 T_2 * V_6 = V_4 -> V_7 ;
int V_9 ;
F_2 ( & V_4 -> V_10 ) ;
if ( F_3 ( & V_6 -> V_11 ) & 0x00ff00 ) {
F_12 ( & V_6 -> V_26 , V_3 ) ;
V_9 = 4 ;
} else {
F_8 ( V_4 , 2 , V_22 ) ;
V_9 = 0 ;
}
F_4 ( & V_4 -> V_10 ) ;
return V_9 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
F_12 ( & V_2 -> V_4 -> V_7 -> V_27 , V_3 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
F_12 ( & V_2 -> V_4 -> V_7 -> V_28 , V_3 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_3 V_29 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
struct V_23 T_2 * V_24 = V_4 -> V_24 ;
T_3 V_30 ;
F_2 ( & V_4 -> V_10 ) ;
V_30 = F_10 ( & V_24 -> V_31 ) ;
if ( V_29 )
V_30 |= 1 ;
else
V_30 &= ~ 1 ;
F_16 ( & V_24 -> V_31 , V_30 ) ;
F_4 ( & V_4 -> V_10 ) ;
}
static T_3 F_17 ( struct V_1 * V_2 )
{
return ( ( F_10 ( & V_2 -> V_4 -> V_24 -> V_31 ) & 1 ) != 0 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_3 V_29 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
struct V_23 T_2 * V_24 = V_4 -> V_24 ;
T_3 V_30 ;
F_2 ( & V_4 -> V_10 ) ;
V_30 = F_10 ( & V_24 -> V_31 ) ;
if ( V_29 )
V_30 |= 2 ;
else
V_30 &= ~ 2 ;
F_16 ( & V_24 -> V_31 , V_30 ) ;
F_4 ( & V_4 -> V_10 ) ;
}
static T_3 F_19 ( struct V_1 * V_2 )
{
return ( ( F_10 ( & V_2 -> V_4 -> V_24 -> V_31 ) & 2 ) != 0 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_4 -> V_7 -> V_32 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_29 )
{
F_12 ( & V_2 -> V_4 -> V_7 -> V_32 , V_29 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_4 -> V_7 -> V_33 ) ;
}
static char * F_23 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_34 ;
}
static void F_24 ( struct V_1 * V_2 , T_3 V_29 )
{
F_16 ( & V_2 -> V_4 -> V_24 -> V_35 , V_29 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_4 -> V_7 -> V_36 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_29 )
{
F_2 ( & V_2 -> V_4 -> V_10 ) ;
if ( V_29 & V_37 )
F_24 ( V_2 ,
V_38 ) ;
F_12 ( & V_2 -> V_4 -> V_7 -> V_36 , V_29 ) ;
F_4 ( & V_2 -> V_4 -> V_10 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 -> V_10 ) ;
F_12 ( & V_2 -> V_4 -> V_7 -> V_36 , V_39 ) ;
while ( F_3 ( & V_2 -> V_4 -> V_7 -> V_33 ) & V_40 )
F_28 () ;
F_4 ( & V_2 -> V_4 -> V_10 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
T_3 V_41 ;
F_2 ( & V_4 -> V_10 ) ;
V_41 = F_30 ( V_4 ) | V_42 ;
F_31 ( V_4 , V_41 ) ;
F_4 ( & V_4 -> V_10 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
T_3 V_41 ;
F_2 ( & V_4 -> V_10 ) ;
V_41 = F_30 ( V_4 ) & ~ V_42 ;
F_31 ( V_4 , V_41 ) ;
F_4 ( & V_4 -> V_10 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_43 , T_1 V_44 )
{
struct V_5 T_2 * V_6 = V_2 -> V_4 -> V_7 ;
int V_9 ;
F_2 ( & V_2 -> V_4 -> V_10 ) ;
V_9 = - V_45 ;
if ( F_3 ( & V_6 -> V_46 ) )
goto V_47;
V_9 = 0 ;
F_12 ( & V_6 -> V_48 , V_43 ) ;
F_12 ( & V_6 -> V_46 , V_44 ) ;
V_47:
F_4 ( & V_2 -> V_4 -> V_10 ) ;
return V_9 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_4 -> V_7 -> V_49 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_4 -> V_7 -> V_50 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
T_1 V_53 ;
struct V_5 T_2 * V_6 = V_2 -> V_4 -> V_7 ;
F_2 ( & V_2 -> V_4 -> V_10 ) ;
F_12 ( & V_6 -> V_54 , V_52 -> V_55 ) ;
F_16 ( & V_6 -> V_56 , V_52 -> V_57 ) ;
F_12 ( & V_6 -> V_58 . V_59 . V_60 ,
V_52 -> V_61 << 16 | V_52 -> V_62 ) ;
F_12 ( & V_6 -> V_58 . V_59 . V_63 ,
V_52 -> V_64 << 16 | V_52 -> V_52 ) ;
V_53 = F_3 ( & V_6 -> V_58 . V_59 . V_63 ) ;
F_4 ( & V_2 -> V_4 -> V_10 ) ;
switch ( V_53 & 0xffff ) {
case 0 :
return 0 ;
case 2 :
return - V_45 ;
default:
return - V_65 ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_23 T_2 * V_24 = V_2 -> V_4 -> V_24 ;
if ( ! F_38 ( V_66 , & V_2 -> V_4 -> V_67 ) )
F_16 ( & V_24 -> V_68 , V_69 ) ;
}
