static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
T_2 V_5 ;
T_2 V_6 ;
V_4 = V_2 -> V_7 . V_8 [ 0 ] ;
V_5 = V_2 -> V_7 . V_9 [ 0 ] ;
V_6 = V_2 -> V_7 . V_9 [ 1 ] ;
V_2 -> V_7 . V_9 [ 0 ] |= V_3 ;
if ( ( V_4 == 0 ) && ! ( V_5 & V_3 ) && ( V_6 & V_3 ) ) {
V_2 -> V_7 . V_8 [ 0 ] = 1 ;
}
}
static int F_2 ( struct V_1 * V_2 , T_1 * V_10 )
{
T_1 V_11 ;
int V_12 = 0 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
V_11 = V_2 -> V_7 . V_14 . V_15 ;
if ( V_11 & 0x0000ff ) {
* V_10 = V_2 -> V_7 . V_14 . V_16 ;
V_2 -> V_7 . V_14 . V_15 &= ~ ( 0x0000ff ) ;
V_2 -> V_7 . V_8 [ 28 ] = 1 ;
F_1 ( V_2 , V_17 ) ;
V_12 = 4 ;
}
F_4 ( & V_2 -> V_7 . V_13 ) ;
return V_12 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_14 . V_15 ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
int V_12 ;
T_1 V_19 ;
V_12 = 0 ;
F_7 ( & V_2 -> V_7 . V_13 ) ;
V_19 = V_2 -> V_7 . V_14 . V_15 ;
if ( V_18 & ( V_20 | V_21 ) ) {
if ( V_19 & 0xff0000 )
V_12 |= V_20 | V_21 ;
else {
V_2 -> V_7 . V_22 . V_23 &=
~ V_24 ;
V_2 -> V_7 . V_22 . V_25 |=
V_26 ;
}
}
if ( V_18 & ( V_27 | V_28 ) ) {
if ( V_19 & 0x00ff00 )
V_12 = V_27 | V_28 ;
else {
V_2 -> V_7 . V_22 . V_23 &=
~ V_29 ;
V_2 -> V_7 . V_22 . V_25 |=
V_30 ;
}
}
F_8 ( & V_2 -> V_7 . V_13 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_10 )
{
int V_12 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
if ( V_2 -> V_7 . V_14 . V_15 & 0xff0000 ) {
* V_10 = V_2 -> V_7 . V_31 . V_32 ;
V_2 -> V_7 . V_14 . V_15 &= ~ ( 0xff0000 ) ;
V_2 -> V_7 . V_8 [ 30 ] = 1 ;
F_1 ( V_2 , V_33 ) ;
V_12 = 4 ;
} else {
V_2 -> V_7 . V_22 . V_25 |= V_26 ;
V_12 = 0 ;
}
F_4 ( & V_2 -> V_7 . V_13 ) ;
return V_12 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_10 )
{
int V_12 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
if ( ( V_2 -> V_7 . V_14 . V_15 ) & 0x00ff00 ) {
int V_34 = V_2 -> V_7 . V_8 [ 29 ] ;
int V_35 = ( V_2 -> V_7 . V_14 . V_15 & 0x00ff00 ) >> 8 ;
F_11 ( V_35 != ( 4 - V_34 ) ) ;
V_2 -> V_7 . V_36 [ V_34 ] = V_10 ;
V_2 -> V_7 . V_8 [ 29 ] = ++ V_34 ;
V_2 -> V_7 . V_14 . V_15 &= ~ ( 0x00ff00 ) ;
V_2 -> V_7 . V_14 . V_15 |= ( ( ( 4 - V_34 ) & 0xff ) << 8 ) ;
F_1 ( V_2 , V_37 ) ;
V_12 = 4 ;
} else {
V_2 -> V_7 . V_22 . V_25 |=
V_30 ;
V_12 = 0 ;
}
F_4 ( & V_2 -> V_7 . V_13 ) ;
return V_12 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_9 [ 3 ] ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
F_3 ( & V_2 -> V_7 . V_13 ) ;
if ( V_2 -> V_7 . V_31 . V_38 & 0x1 )
V_2 -> V_7 . V_9 [ 3 ] |= V_10 ;
else
V_2 -> V_7 . V_9 [ 3 ] = V_10 ;
V_2 -> V_7 . V_8 [ 3 ] = 1 ;
F_1 ( V_2 , V_39 ) ;
F_4 ( & V_2 -> V_7 . V_13 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_9 [ 4 ] ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_10 )
{
F_3 ( & V_2 -> V_7 . V_13 ) ;
if ( V_2 -> V_7 . V_31 . V_38 & 0x2 )
V_2 -> V_7 . V_9 [ 4 ] |= V_10 ;
else
V_2 -> V_7 . V_9 [ 4 ] = V_10 ;
V_2 -> V_7 . V_8 [ 4 ] = 1 ;
F_1 ( V_2 , V_40 ) ;
F_4 ( & V_2 -> V_7 . V_13 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_41 )
{
T_2 V_42 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
V_42 = V_2 -> V_7 . V_31 . V_38 ;
if ( V_41 )
V_42 |= 1 ;
else
V_42 &= ~ 1 ;
V_2 -> V_7 . V_31 . V_38 = V_42 ;
F_4 ( & V_2 -> V_7 . V_13 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_7 . V_31 . V_38 & 1 ) != 0 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_2 V_41 )
{
T_2 V_42 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
V_42 = V_2 -> V_7 . V_31 . V_38 ;
if ( V_41 )
V_42 |= 2 ;
else
V_42 &= ~ 2 ;
V_2 -> V_7 . V_31 . V_38 = V_42 ;
F_4 ( & V_2 -> V_7 . V_13 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_7 . V_31 . V_38 & 2 ) != 0 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_14 . V_43 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_41 )
{
V_2 -> V_7 . V_14 . V_43 = V_41 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_14 . V_44 ;
}
static char * F_23 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_45 -> V_46 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_41 )
{
V_2 -> V_7 . V_31 . V_47 = V_41 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_14 . V_48 ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_41 )
{
F_3 ( & V_2 -> V_7 . V_13 ) ;
V_2 -> V_7 . V_14 . V_48 = V_41 ;
if ( V_41 & V_49 ) {
V_2 -> V_7 . V_14 . V_44 &=
~ V_50 &
~ V_51 &
~ V_52 &
~ V_53 &
~ V_54 ;
V_2 -> V_7 . V_14 . V_44 |= V_55 ;
} else {
V_2 -> V_7 . V_14 . V_44 &= ~ V_55 ;
}
F_4 ( & V_2 -> V_7 . V_13 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 , V_56 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_57 * V_7 = & V_2 -> V_7 ;
T_2 V_58 ;
F_3 ( & V_7 -> V_13 ) ;
V_58 = V_7 -> V_22 . V_59 | V_60 ;
V_7 -> V_22 . V_59 = V_58 ;
F_4 ( & V_7 -> V_13 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_57 * V_7 = & V_2 -> V_7 ;
T_2 V_58 ;
F_3 ( & V_7 -> V_13 ) ;
V_58 = V_7 -> V_22 . V_59 & ~ V_60 ;
V_7 -> V_22 . V_59 = V_58 ;
F_4 ( & V_7 -> V_13 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_61 ,
T_1 V_62 )
{
struct V_63 * V_14 = & V_2 -> V_7 . V_14 ;
int V_12 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
V_12 = - V_64 ;
if ( V_14 -> V_65 )
goto V_66;
V_12 = 0 ;
V_14 -> V_67 = V_61 ;
V_14 -> V_65 = V_62 ;
V_2 -> V_7 . V_14 . V_68 &= V_61 ;
V_66:
F_4 ( & V_2 -> V_7 . V_13 ) ;
return V_12 ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_14 . V_68 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_14 . V_69 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
int V_12 ;
F_3 ( & V_2 -> V_7 . V_13 ) ;
V_12 = - V_64 ;
F_4 ( & V_2 -> V_7 . V_13 ) ;
return V_12 ;
}
static void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_7 . V_31 . V_72 |= V_73 ;
}
