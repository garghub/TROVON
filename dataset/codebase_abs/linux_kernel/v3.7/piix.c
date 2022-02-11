static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
int V_5 = V_2 -> V_6 & 1 ;
int V_7 = V_1 -> V_8 ? 0x42 : 0x40 ;
int V_9 = 0x44 ;
unsigned long V_10 ;
T_3 V_11 ;
T_4 V_12 ;
static F_3 ( V_13 ) ;
int V_14 = 0 ;
const T_4 V_15 = V_2 -> V_16 - V_17 ;
static const T_4 V_18 [] [ 2 ] = {
{ 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_4 ( & V_13 , V_10 ) ;
F_5 ( V_4 , V_7 , & V_11 ) ;
if ( V_15 > 1 )
V_14 |= 1 ;
if ( V_2 -> V_19 == V_20 )
V_14 |= 4 ;
if ( F_6 ( V_2 , V_15 ) )
V_14 |= 2 ;
if ( V_5 ) {
V_11 |= 0x4000 ;
V_11 &= ~ 0x0070 ;
if ( V_15 > 1 ) {
V_11 |= V_14 << 4 ;
}
F_7 ( V_4 , V_9 , & V_12 ) ;
V_12 &= V_1 -> V_8 ? 0x0f : 0xf0 ;
V_12 |= ( ( V_18 [ V_15 ] [ 0 ] << 2 ) | V_18 [ V_15 ] [ 1 ] ) <<
( V_1 -> V_8 ? 4 : 0 ) ;
} else {
V_11 &= ~ 0x3307 ;
if ( V_15 > 1 ) {
V_11 |= V_14 ;
}
V_11 |= ( V_18 [ V_15 ] [ 0 ] << 12 ) | ( V_18 [ V_15 ] [ 1 ] << 8 ) ;
}
F_8 ( V_4 , V_7 , V_11 ) ;
if ( V_5 )
F_9 ( V_4 , V_9 , V_12 ) ;
F_10 ( & V_13 , V_10 ) ;
}
static void F_11 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
T_4 V_21 = V_1 -> V_8 ? 0x42 : 0x40 ;
int V_22 = 3 << ( V_2 -> V_6 * 4 ) ;
int V_23 = 1 << V_2 -> V_6 ;
int V_24 = 0x01 << V_2 -> V_6 ;
int V_25 = 0x10 << V_2 -> V_6 ;
int V_26 = 0 ;
int V_27 ;
T_3 V_28 , V_29 ;
T_4 V_30 , V_31 , V_32 ;
const T_4 V_33 = V_2 -> V_34 ;
F_5 ( V_4 , V_21 , & V_28 ) ;
V_27 = ( V_28 & 0x4000 ) ? 1 : 0 ;
F_7 ( V_4 , 0x48 , & V_30 ) ;
F_5 ( V_4 , 0x4a , & V_29 ) ;
F_7 ( V_4 , 0x54 , & V_31 ) ;
F_7 ( V_4 , 0x55 , & V_32 ) ;
if ( V_33 >= V_35 ) {
T_4 V_36 = V_33 - V_35 ;
V_26 = F_12 ( T_4 , 2 - ( V_36 & 1 ) , V_36 ) << ( V_2 -> V_6 * 4 ) ;
if ( ! ( V_30 & V_23 ) )
F_9 ( V_4 , 0x48 , V_30 | V_23 ) ;
if ( V_33 == V_37 ) {
F_9 ( V_4 , 0x55 , ( T_4 ) V_32 | V_25 ) ;
} else {
F_9 ( V_4 , 0x55 , ( T_4 ) V_32 & ~ V_25 ) ;
}
if ( ( V_29 & V_22 ) != V_26 )
F_8 ( V_4 , 0x4a , ( V_29 & ~ V_22 ) | V_26 ) ;
if ( V_33 > V_38 ) {
if ( ! ( V_31 & V_24 ) )
F_9 ( V_4 , 0x54 , V_31 | V_24 ) ;
} else
F_9 ( V_4 , 0x54 , V_31 & ~ V_24 ) ;
} else {
const T_4 V_39 [] = { 0 , 3 , 4 } ;
if ( V_30 & V_23 )
F_9 ( V_4 , 0x48 , V_30 & ~ V_23 ) ;
if ( V_29 & V_22 )
F_8 ( V_4 , 0x4a , V_29 & ~ V_22 ) ;
if ( V_31 & V_24 )
F_9 ( V_4 , 0x54 , V_31 & ~ V_24 ) ;
if ( V_32 & V_25 )
F_9 ( V_4 , 0x55 , ( T_4 ) V_32 & ~ V_25 ) ;
if ( V_33 >= V_40 )
V_2 -> V_16 =
V_39 [ V_33 - V_40 ] + V_17 ;
else
V_2 -> V_16 = V_41 ;
F_1 ( V_1 , V_2 ) ;
}
}
static int F_13 ( struct V_3 * V_4 )
{
T_5 V_42 = 0 ;
F_14 ( V_4 , 0x54 , & V_42 ) ;
F_15 ( V_4 , 0x54 , V_42 | 0x400 ) ;
return 0 ;
}
static void F_16 ( T_2 * V_2 )
{
T_1 * V_1 = V_2 -> V_1 ;
T_4 V_43 ;
if ( V_2 -> V_44 || V_1 -> V_45 == 0 )
return;
V_43 = F_17 ( V_1 -> V_45 + V_46 ) ;
F_18 ( V_43 , V_1 -> V_45 + V_46 ) ;
}
static T_4 F_19 ( T_1 * V_1 )
{
struct V_3 * V_47 = F_2 ( V_1 -> V_4 ) ;
const struct V_48 * V_49 = & V_48 [ 0 ] ;
T_4 V_50 = 0 , V_51 = V_1 -> V_8 ? 0xc0 : 0x30 ;
while ( V_49 -> V_52 ) {
if ( V_49 -> V_52 == V_47 -> V_52 &&
V_49 -> V_53 == V_47 -> V_54 &&
V_49 -> V_55 == V_47 -> V_56 ) {
return V_57 ;
}
V_49 ++ ;
}
F_7 ( V_47 , 0x54 , & V_50 ) ;
return ( V_50 & V_51 ) ? V_58 : V_59 ;
}
static void T_6 F_20 ( T_1 * V_1 )
{
if ( ! V_1 -> V_45 )
return;
if ( V_60 )
V_1 -> V_61 = V_1 -> V_62 = V_1 -> V_63 = 0 ;
}
static int T_6 F_21 ( struct V_3 * V_4 , const struct V_64 * V_65 )
{
return F_22 ( V_4 , & V_66 [ V_65 -> V_67 ] , NULL ) ;
}
static void T_6 F_23 ( void )
{
struct V_3 * V_47 = NULL ;
T_3 V_68 ;
while( ( V_47 = F_24 ( V_69 , V_70 , V_47 ) ) != NULL )
{
F_5 ( V_47 , 0x41 , & V_68 ) ;
if ( V_47 -> V_71 == 0x00 )
V_60 = 1 ;
else if ( V_68 & ( 1 << 14 ) && V_47 -> V_71 < 5 )
V_60 = 2 ;
}
if( V_60 )
F_25 (KERN_WARNING DRV_NAME L_1 ) ;
if( V_60 == 2 )
F_25 (KERN_WARNING DRV_NAME L_2 ) ;
}
static int T_7 F_26 ( void )
{
F_23 () ;
return F_27 ( & V_72 ) ;
}
static void T_8 F_28 ( void )
{
F_29 ( & V_72 ) ;
}
