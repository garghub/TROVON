static inline T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( V_1 >= 12 && V_1 <= 14 )
return V_2 * 6 ;
else
return V_2 * 2 ;
}
static inline T_1 F_2 ( T_2 V_1 , T_1 V_2 )
{
if ( V_1 >= 12 && V_1 <= 14 )
return V_2 / 6 ;
else
return V_2 / 2 ;
}
static inline unsigned long F_3 ( T_1 V_2 )
{
if ( ( V_2 == 0xfff ) || ( V_2 == 0 ) )
return 0 ;
return 1350000UL / V_2 ;
}
static inline T_1 F_4 ( long V_3 )
{
if ( V_3 <= 0 )
return 0x0fff ;
return F_5 ( ( 1350000 + ( V_3 >> 1 ) ) / V_3 , 1 , 0xffe ) ;
}
static inline unsigned long F_6 ( T_2 V_4 )
{
return V_4 * 100 ;
}
static inline T_2 F_7 ( unsigned long V_2 )
{
return F_5 ( ( V_2 + 50 ) / 100 , 0 , 0xff ) ;
}
static inline long F_8 ( T_3 V_4 )
{
return V_4 * 1000 ;
}
static inline T_3 F_9 ( long V_2 , T_3 V_5 , T_3 V_6 )
{
return F_5 ( V_2 / 1000 , V_5 , V_6 ) ;
}
static unsigned int F_10 ( T_2 V_4 , T_1 V_7 )
{
unsigned long V_8 ;
if ( V_4 & 0x80 ) {
V_8 = V_7 * 1000 / ( ( V_7 == 48000 ) ? 384 : 256 ) ;
return V_8 / ( ( V_4 & 0x7f ) + 1 ) ;
} else
return V_9 [ V_4 & 0x0f ] ;
}
static T_2 F_11 ( unsigned long V_2 , T_1 V_7 )
{
unsigned long V_8 ;
T_2 V_10 , V_11 ;
unsigned long V_12 , V_13 ;
for ( V_10 = 0 ; V_10 < F_12 ( V_9 ) - 1 ; V_10 ++ ) {
if ( V_2 > ( V_9 [ V_10 ] +
V_9 [ V_10 + 1 ] ) / 2 )
break;
}
if ( V_2 < 375 )
return V_10 ;
V_12 = V_9 [ V_10 ] ;
V_8 = V_7 * 1000 / ( ( V_7 == 48000 ) ? 384 : 256 ) ;
V_11 = F_5 ( F_13 ( V_8 , V_2 ) , 1 , 128 ) ;
V_13 = V_8 / V_11 ;
V_11 = 0x80 | ( V_11 - 1 ) ;
if ( abs ( V_2 - V_12 ) > abs ( V_2 - V_13 ) )
return V_11 ;
else
return V_10 ;
}
static int F_14 ( struct V_14 * V_15 , T_2 V_16 )
{
struct V_17 * V_18 = F_15 ( V_15 ) ;
int V_19 ;
if ( ( V_18 -> V_16 & 0x07 ) == V_16 )
return 0 ;
V_16 |= V_18 -> V_16 & ~ 0x07 ;
V_19 = F_16 ( V_15 , V_20 , V_16 ) ;
if ( V_19 < 0 ) {
F_17 ( & V_15 -> V_21 ,
L_1 ,
( int ) V_16 , V_19 ) ;
return V_19 ;
}
V_18 -> V_16 = V_16 ;
return 0 ;
}
static T_2 F_18 ( struct V_14 * V_15 , T_1 V_4 )
{
int V_19 ;
V_19 = F_14 ( V_15 , V_4 >> 8 ) ;
if ( V_19 < 0 )
return 0x00 ;
V_19 = F_19 ( V_15 , V_4 & 0xff ) ;
if ( V_19 < 0 ) {
F_17 ( & V_15 -> V_21 ,
L_2 ,
( int ) V_4 , V_19 ) ;
return 0x00 ;
}
return V_19 ;
}
static int F_20 ( struct V_14 * V_15 , T_1 V_4 , T_2 V_22 )
{
int V_19 ;
V_19 = F_14 ( V_15 , V_4 >> 8 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_16 ( V_15 , V_4 & 0xff , V_22 ) ;
if ( V_19 < 0 )
F_17 ( & V_15 -> V_21 ,
L_3 ,
( int ) V_4 , V_19 ) ;
return V_19 ;
}
static void F_21 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_15 ( V_15 ) ;
int V_23 , V_24 ;
T_2 V_25 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_26 ) ; V_23 ++ ) {
if ( ! ( V_18 -> V_27 & ( 1 << V_23 ) ) )
continue;
V_18 -> V_26 [ V_23 ] [ V_28 ] =
F_18 ( V_15 , V_29 [ V_23 ] [ V_28 ] ) ;
V_18 -> V_26 [ V_23 ] [ V_30 ] =
F_18 ( V_15 , V_29 [ V_23 ] [ V_30 ] ) ;
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_31 ) ; V_23 ++ ) {
if ( ( V_23 == 2 && V_18 -> V_32 == V_33 ) ||
( V_23 >= 4 && ! ( V_18 -> V_27 & ( 1 << ( V_23 + 11 ) ) ) ) )
continue;
V_18 -> V_31 [ V_23 ] [ V_28 ] =
F_18 ( V_15 , F_22 ( V_23 , V_28 ) ) ;
V_18 -> V_31 [ V_23 ] [ V_30 ] =
F_18 ( V_15 , F_22 ( V_23 , V_30 ) ) ;
}
V_25 = 0 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_34 ) ; V_23 ++ ) {
if ( ( V_23 & 1 ) == 0 && ( V_18 -> V_35 & ( 3 << V_23 ) ) )
V_25 = F_18 ( V_15 , F_23 ( V_23 ) ) ;
if ( ! ( V_18 -> V_35 & ( 1 << V_23 ) ) )
continue;
V_18 -> V_36 [ V_23 ] =
F_18 ( V_15 , F_24 ( V_23 ) ) << 4 ;
V_18 -> V_36 [ V_23 ] |=
( V_25 >> F_25 ( V_23 ) ) & 0x0F ;
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_37 ) ; V_23 ++ ) {
if ( ! ( V_18 -> V_38 & ( 1 << V_23 ) ) )
continue;
for ( V_24 = V_39 ; V_24 <= V_40 ; V_24 ++ )
V_18 -> V_37 [ V_23 ] [ V_24 ] =
F_18 ( V_15 , V_41 [ V_23 ] [ V_24 ] ) ;
}
if ( V_18 -> V_42 ) {
for ( V_24 = V_43 ; V_24 <= V_44 ; V_24 ++ )
V_18 -> V_45 [ V_24 ] =
F_18 ( V_15 , F_26 ( V_24 ) ) ;
}
if ( V_18 -> V_46 ) {
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_47 ) ; V_23 ++ )
V_18 -> V_47 [ V_23 ] =
F_18 ( V_15 , F_27 ( V_23 ) ) ;
}
V_18 -> V_48 = 1 ;
}
static struct V_17 * F_28 ( struct V_49 * V_21 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
int V_23 , V_50 ;
F_30 ( & V_18 -> V_51 ) ;
if ( V_18 -> V_52 )
goto V_53;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_54 ) ; V_23 ++ )
V_18 -> V_54 [ V_23 ] = F_18 ( V_15 , F_31 ( V_23 ) ) ;
V_18 -> V_55 [ 0 ] = F_18 ( V_15 , V_56 ) ;
V_18 -> V_55 [ 1 ] = F_18 ( V_15 , V_57 ) ;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_58 ) ; V_23 ++ )
V_18 -> V_58 [ V_23 ] = F_18 ( V_15 , F_32 ( V_23 ) ) ;
V_18 -> V_59 = F_18 ( V_15 , V_60 ) ;
for ( V_23 = 0 ; V_23 < V_18 -> V_61 ; V_23 ++ ) {
for ( V_50 = V_62 ; V_50 <= V_63 ; V_50 ++ )
V_18 -> V_64 [ V_23 ] [ V_50 ] =
F_18 ( V_15 , F_33 ( V_23 , V_50 ) ) ;
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_65 ) ; V_23 ++ ) {
V_18 -> V_65 [ V_23 ] =
F_18 ( V_15 , F_34 ( V_23 ) ) << 4 ;
V_18 -> V_65 [ V_23 ] |=
F_18 ( V_15 , F_35 ( V_23 ) ) >> 4 ;
}
V_18 -> V_66 = F_18 ( V_15 , V_67 ) & 0x3f ;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_68 ) ; V_23 ++ ) {
V_18 -> V_68 [ V_23 ] [ V_69 ] =
F_18 ( V_15 , F_36 ( V_23 ) ) & 0x7f ;
V_18 -> V_68 [ V_23 ] [ V_70 ] =
F_18 ( V_15 , F_37 ( V_23 ) ) ;
V_50 = F_18 ( V_15 , F_38 ( V_23 ) ) ;
V_18 -> V_68 [ V_23 ] [ V_71 ] = V_50 >> 4 ;
V_18 -> V_68 [ V_23 ] [ V_72 ] = V_50 & 0x0f ;
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_73 ) ; V_23 ++ ) {
for ( V_50 = 0 ; V_50 < 7 ; V_50 ++ ) {
V_18 -> V_73 [ V_23 ] [ V_74 ] [ V_50 ] =
F_18 ( V_15 ,
F_39 ( V_23 , V_50 ) ) ;
V_18 -> V_73 [ V_23 ] [ V_75 ] [ V_50 ] =
F_18 ( V_15 , F_40 ( V_23 , V_50 ) ) ;
}
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_76 ) ; V_23 ++ )
V_18 -> V_76 [ V_23 ] =
F_18 ( V_15 , F_41 ( V_23 ) ) ;
V_18 -> V_52 = 1 ;
V_53:
F_42 ( & V_18 -> V_51 ) ;
return V_18 ;
}
static struct V_17 * F_43 ( struct V_49 * V_21 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
T_1 V_50 ;
T_2 V_77 ;
int V_23 ;
F_30 ( & V_18 -> V_51 ) ;
if ( ! V_18 -> V_48 )
F_21 ( V_15 ) ;
if ( ! ( F_44 ( V_78 , V_18 -> V_79 + V_80 * 2 )
|| ! V_18 -> V_81 ) )
goto V_53;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_26 ) ; V_23 ++ ) {
if ( ! ( V_18 -> V_27 & ( 1 << V_23 ) ) )
continue;
V_50 = F_18 ( V_15 , V_29 [ V_23 ] [ V_82 ] ) << 2 ;
V_50 |= F_18 ( V_15 , V_83 ) >> 6 ;
V_18 -> V_26 [ V_23 ] [ V_82 ] = V_50 ;
}
if ( V_18 -> V_84 ) {
T_2 V_85 = F_18 ( V_15 , F_22 ( 0 , V_28 ) ) ;
T_2 V_86 = F_18 ( V_15 , F_22 ( 0 , V_30 ) ) ;
for ( V_23 = 0 ; V_23 < 3 ; V_23 ++ ) {
if ( ! ( V_18 -> V_84 & ( 1 << V_23 ) ) )
continue;
V_18 -> V_26 [ V_23 ] [ V_28 ] =
F_18 ( V_15 , V_29 [ V_23 ] [ V_28 ] ) ;
V_18 -> V_26 [ V_23 ] [ V_30 ] =
F_18 ( V_15 , V_29 [ V_23 ] [ V_30 ] ) ;
V_18 -> V_31 [ V_23 ] [ V_28 ] = ( V_85 >> ( 2 * V_23 ) ) & 0x03 ;
V_18 -> V_31 [ V_23 ] [ V_30 ] = ( V_86 >> ( 2 * V_23 ) ) & 0x03 ;
}
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_34 ) ; V_23 ++ ) {
if ( ! ( V_18 -> V_35 & ( 1 << V_23 ) ) )
continue;
V_18 -> V_34 [ V_23 ] = F_18 ( V_15 , F_45 ( V_23 ) ) << 4 ;
V_18 -> V_34 [ V_23 ] |= F_18 ( V_15 , V_83 ) >> 4 ;
}
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_37 ) ; V_23 ++ ) {
V_18 -> V_37 [ V_23 ] [ V_87 ] =
F_18 ( V_15 , V_41 [ V_23 ] [ V_87 ] ) ;
V_18 -> V_88 [ V_23 ] =
F_18 ( V_15 , V_83 ) ;
}
if ( V_18 -> V_42 ) {
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_89 ) ; V_23 ++ ) {
if ( ! ( V_18 -> V_90 & ( 1 << V_23 ) ) )
continue;
V_18 -> V_89 [ V_23 ] =
F_18 ( V_15 , F_46 ( V_23 ) ) ;
V_18 -> V_91 [ V_23 ] =
F_18 ( V_15 , V_83 ) ;
}
}
for ( V_23 = 0 ; V_23 < V_18 -> V_61 ; V_23 ++ ) {
V_18 -> V_64 [ V_23 ] [ V_92 ] =
F_18 ( V_15 , F_33 ( V_23 , V_92 ) ) ;
}
V_50 = F_18 ( V_15 , V_93 ) ;
if ( V_50 & V_94 )
F_20 ( V_15 , V_93 ,
V_50 & ~ V_94 ) ;
V_77 = F_18 ( V_15 , F_47 ( 5 ) ) & ( 1 << 6 ) ;
F_20 ( V_15 , V_93 , V_50 | V_94 ) ;
for ( V_23 = 0 ; V_23 < F_12 ( V_18 -> V_95 ) ; V_23 ++ )
V_18 -> V_95 [ V_23 ] = F_18 ( V_15 , F_47 ( V_23 ) ) ;
V_18 -> V_95 [ 5 ] |= V_77 ;
if ( ! ( V_50 & V_94 ) )
F_20 ( V_15 , V_93 ,
V_50 & ~ V_94 ) ;
V_18 -> V_79 = V_78 ;
V_18 -> V_81 = 1 ;
V_53:
F_42 ( & V_18 -> V_51 ) ;
return V_18 ;
}
static T_4
F_48 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_43 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 >> 3 ;
int V_102 = V_100 -> V_1 & 0x07 ;
T_2 V_2 ;
if ( V_101 == V_103 )
V_2 = ( V_18 -> V_95 [ V_1 ] >> V_102 ) & 1 ;
else
V_2 = ( V_18 -> V_47 [ V_1 ] >> V_102 ) & 1 ;
return sprintf ( V_98 , L_4 , V_2 ) ;
}
static T_4
F_50 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 >> 3 ;
int V_105 = V_100 -> V_1 & 0x07 ;
T_2 V_106 = 1 << V_105 ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
if ( V_2 != 0 && V_2 != 1 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
V_18 -> V_47 [ V_1 ] = F_18 ( V_15 , F_27 ( V_1 ) ) ;
V_18 -> V_47 [ V_1 ] &= ~ V_106 ;
V_18 -> V_47 [ V_1 ] |= V_2 << V_105 ;
F_20 ( V_15 , F_27 ( V_1 ) , V_18 -> V_47 [ V_1 ] ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_52 ( struct V_49 * V_21 ,
struct V_96 * V_97 , const char * V_98 ,
T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 || V_2 != 0 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
V_2 = F_18 ( V_15 , V_108 ) ;
V_2 |= 0x80 ;
F_20 ( V_15 , V_108 , V_2 ) ;
F_18 ( V_15 , F_47 ( 5 ) ) ;
V_18 -> V_81 = 0 ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_53 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
struct V_17 * V_18 = F_43 ( V_21 ) ;
T_1 V_2 ;
if ( V_101 == V_109 )
V_2 = V_18 -> V_34 [ V_1 ] & 0x0fff ;
else
V_2 = V_18 -> V_36 [ V_1 ] & 0x0fff ;
return sprintf ( V_98 , L_5 , F_3 ( V_2 ) ) ;
}
static T_4
F_54 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 ;
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) )
return - V_107 ;
V_2 = F_4 ( V_2 ) ;
F_30 ( & V_18 -> V_51 ) ;
V_18 -> V_36 [ V_1 ] = V_2 ;
F_20 ( V_15 , F_24 ( V_1 ) , ( V_2 >> 4 ) & 0xff ) ;
V_2 &= 0x0f ;
if ( V_1 & 1 ) {
V_2 <<= 4 ;
V_2 |= F_18 ( V_15 , F_23 ( V_1 ) )
& 0x0f ;
} else {
V_2 |= F_18 ( V_15 , F_23 ( V_1 ) )
& 0xf0 ;
}
F_20 ( V_15 , F_23 ( V_1 ) , V_2 & 0xff ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_55 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned int V_2 ;
V_18 = V_101 == V_92 ? F_43 ( V_21 )
: F_28 ( V_21 ) ;
switch ( V_101 ) {
case V_63 :
V_2 = F_6 ( V_18 -> V_64 [ V_1 ] [ V_101 ] ) ;
break;
case V_62 :
V_2 = F_10 ( V_18 -> V_64 [ V_1 ] [ V_101 ] , V_18 -> V_7 ) ;
break;
default:
V_2 = V_18 -> V_64 [ V_1 ] [ V_101 ] ;
break;
}
return sprintf ( V_98 , L_4 , V_2 ) ;
}
static T_4
F_56 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
switch ( V_101 ) {
case V_63 :
V_2 = F_7 ( V_2 ) ;
break;
case V_62 :
V_2 = F_11 ( V_2 , V_18 -> V_7 ) ;
break;
default:
V_2 = F_5 ( V_2 , 0 , 0xff ) ;
break;
}
F_20 ( V_15 , F_33 ( V_1 , V_101 ) , V_2 ) ;
V_18 -> V_64 [ V_1 ] [ V_101 ] = V_2 ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_57 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
int V_1 = V_100 -> V_1 ;
T_2 V_50 ;
if ( V_18 -> V_55 [ 0 ] & ( 1 << V_1 ) ) {
V_50 = 2 ;
goto V_110;
}
for ( V_50 = 0 ; V_50 < 6 ; V_50 ++ ) {
if ( V_18 -> V_58 [ V_50 ] & ( 1 << V_1 ) ) {
V_50 = 3 ;
goto V_110;
}
}
V_50 = 1 ;
V_110:
return sprintf ( V_98 , L_4 , V_50 ) ;
}
static T_4
F_58 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 ;
unsigned long V_2 ;
int V_23 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
if ( V_2 < 1 || V_2 > 2 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
switch ( V_2 ) {
case 1 :
V_18 -> V_55 [ 0 ] &= ~ ( 1 << V_1 ) ;
F_20 ( V_15 , V_56 , V_18 -> V_55 [ 0 ] ) ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ ) {
V_18 -> V_58 [ V_23 ] &= ~ ( 1 << V_1 ) ;
F_20 ( V_15 , F_32 ( V_23 ) ,
V_18 -> V_58 [ V_23 ] ) ;
}
break;
case 2 :
V_18 -> V_55 [ 0 ] |= ( 1 << V_1 ) ;
F_20 ( V_15 , V_56 , V_18 -> V_55 [ 0 ] ) ;
break;
}
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_59 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_28 ( V_21 ) ;
int V_1 = F_49 ( V_97 ) -> V_1 ;
unsigned int V_111 ;
if ( V_18 -> V_59 & ( 1 << V_1 ) )
V_111 = 0 ;
else
V_111 = 1 ;
return sprintf ( V_98 , L_4 , V_111 ) ;
}
static int F_60 ( const struct V_17 * V_18 , int V_112 )
{
int V_113 = 0 , V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
if ( V_114 [ V_23 ] [ V_112 ] == V_115 )
continue;
if ( V_114 [ V_23 ] [ V_112 ] < 6 )
V_113 += ( V_18 -> V_38 >> V_114 [ V_23 ] [ V_112 ] ) & 1 ;
else
V_113 += ( V_18 -> V_90 >> ( V_114 [ V_23 ] [ V_112 ] - 6 ) ) & 1 ;
}
return V_113 ;
}
static T_4
F_61 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
int V_1 = V_100 -> V_1 ;
T_2 V_50 = V_18 -> V_54 [ V_1 / 2 ] ;
if ( V_1 & 1 )
V_50 >>= 4 ;
else
V_50 &= 0x0f ;
if ( V_50 >= 4 || V_114 [ V_50 ] [ V_1 ] == V_115 )
return - V_107 ;
return sprintf ( V_98 , L_4 , ( unsigned int ) V_114 [ V_50 ] [ V_1 ] + 1 ) ;
}
static T_4
F_62 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 ;
int V_50 ;
unsigned long V_116 ;
T_2 V_2 = V_1 / 2 ;
if ( F_51 ( V_98 , 10 , & V_116 ) < 0 ||
V_116 < 1 || V_116 > 14 )
return - V_107 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( V_114 [ V_50 ] [ V_1 ] == V_116 - 1 )
break;
}
if ( V_50 == 4 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
if ( V_1 & 1 ) {
V_50 <<= 4 ;
V_18 -> V_54 [ V_2 ] &= 0x0f ;
} else {
V_18 -> V_54 [ V_2 ] &= 0xf0 ;
}
V_18 -> V_54 [ V_2 ] |= V_50 ;
F_20 ( V_15 , F_31 ( V_2 ) , V_18 -> V_54 [ V_2 ] ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_63 ( struct V_49 * V_21 , struct V_96 * V_97 ,
char * V_98 )
{
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
T_2 V_50 = 0xff ;
switch ( V_101 ) {
case V_117 :
V_50 = ( V_18 -> V_55 [ 1 ] >> V_1 ) & 1 ;
if ( V_50 )
V_50 = 4 ;
else
V_50 = 3 ;
break;
case V_118 :
V_50 = V_18 -> V_58 [ V_1 ] ;
break;
}
return sprintf ( V_98 , L_4 , V_50 ) ;
}
static T_4
F_64 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned long V_50 ;
if ( F_51 ( V_98 , 10 , & V_50 ) < 0 )
return - V_107 ;
switch ( V_101 ) {
case V_117 :
if ( V_50 != 3 && V_50 != 4 )
return - V_107 ;
V_50 -= 3 ;
F_30 ( & V_18 -> V_51 ) ;
V_18 -> V_55 [ 1 ] &= ~ ( 1 << V_1 ) ;
V_18 -> V_55 [ 1 ] |= V_50 << V_1 ;
F_20 ( V_15 , V_57 , V_18 -> V_55 [ 1 ] ) ;
F_42 ( & V_18 -> V_51 ) ;
break;
case V_118 :
F_30 ( & V_18 -> V_51 ) ;
V_50 = F_5 ( V_50 , 0 , 0xff ) ;
F_20 ( V_15 , F_32 ( V_1 ) , V_50 ) ;
V_18 -> V_58 [ V_1 ] = V_50 ;
F_42 ( & V_18 -> V_51 ) ;
break;
}
return V_104 ;
}
static T_4
F_65 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
T_1 V_50 = 0 ;
switch ( V_101 ) {
case V_119 :
V_50 = F_3 ( V_18 -> V_65 [ V_1 ] ) ;
break;
case V_120 :
V_50 = V_18 -> V_66 ;
break;
}
return sprintf ( V_98 , L_4 , V_50 ) ;
}
static T_4
F_66 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
switch ( V_101 ) {
case V_119 :
V_2 = F_4 ( F_5 ( V_2 , 0 , 0xfff ) ) ;
F_20 ( V_15 , F_34 ( V_1 ) , V_2 >> 4 ) ;
F_20 ( V_15 , F_35 ( V_1 ) , ( V_2 << 4 ) & 0xf0 ) ;
V_18 -> V_65 [ V_1 ] = V_2 ;
break;
case V_120 :
V_2 = F_5 ( V_2 , 0 , 0x3f ) ;
F_20 ( V_15 , V_67 , V_2 ) ;
V_18 -> V_66 = V_2 ;
break;
}
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_67 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
long V_50 = F_8 ( V_18 -> V_68 [ V_1 ] [ V_101 ] ) ;
return sprintf ( V_98 , L_6 , V_50 ) ;
}
static T_4
F_68 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned long V_2 ;
T_2 V_50 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
V_2 /= 1000 ;
F_30 ( & V_18 -> V_51 ) ;
switch ( V_101 ) {
case V_69 :
V_2 = F_5 ( V_2 , 0 , 0x7f ) ;
F_20 ( V_15 , F_36 ( V_1 ) , V_2 ) ;
break;
case V_70 :
V_2 = F_5 ( V_2 , 0 , 0x7f ) ;
F_20 ( V_15 , F_37 ( V_1 ) , V_2 ) ;
break;
case V_71 :
V_2 = F_5 ( V_2 , 0 , 0x0f ) ;
V_50 = F_18 ( V_15 , F_38 ( V_1 ) ) ;
V_50 &= 0x0f ;
V_50 |= ( V_2 << 4 ) & 0xf0 ;
F_20 ( V_15 , F_38 ( V_1 ) , V_50 ) ;
break;
case V_72 :
V_2 = F_5 ( V_2 , 0 , 0x0f ) ;
V_50 = F_18 ( V_15 , F_38 ( V_1 ) ) ;
V_50 &= 0xf0 ;
V_50 |= V_2 & 0x0f ;
F_20 ( V_15 , F_38 ( V_1 ) , V_50 ) ;
break;
}
V_18 -> V_68 [ V_1 ] [ V_101 ] = V_2 ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_69 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
return sprintf ( V_98 , L_4 , V_18 -> V_73 [ V_1 ] [ V_75 ] [ V_101 ] ) ;
}
static T_4
F_70 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
F_20 ( V_15 , F_40 ( V_1 , V_101 ) , V_2 ) ;
V_18 -> V_73 [ V_1 ] [ V_75 ] [ V_101 ] = V_2 ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_71 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
return sprintf ( V_98 , L_4 ,
( V_18 -> V_73 [ V_1 ] [ V_74 ] [ V_101 ] ) * 1000 ) ;
}
static T_4
F_72 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
V_2 /= 1000 ;
F_30 ( & V_18 -> V_51 ) ;
F_20 ( V_15 , F_39 ( V_1 , V_101 ) , V_2 ) ;
V_18 -> V_73 [ V_1 ] [ V_74 ] [ V_101 ] = V_2 ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_73 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
struct V_17 * V_18 = F_43 ( V_21 ) ;
long V_37 = F_8 ( V_18 -> V_37 [ V_1 ] [ V_101 ] ) ;
if ( V_101 == V_87 )
V_37 += ( V_18 -> V_88 [ V_1 ] >> 6 ) * 250 ;
return sprintf ( V_98 , L_6 , V_37 ) ;
}
static T_4
F_74 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
long V_50 ;
if ( F_75 ( V_98 , 10 , & V_50 ) < 0 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
V_18 -> V_37 [ V_1 ] [ V_101 ] = F_9 ( V_50 , - 128 , 127 ) ;
F_20 ( V_15 , V_41 [ V_1 ] [ V_101 ] , V_18 -> V_37 [ V_1 ] [ V_101 ] ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_76 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_77 ( V_21 ) ;
int V_50 ;
if ( V_18 -> V_42 & 2 )
V_50 = 5 ;
else
V_50 = 6 ;
return sprintf ( V_98 , L_7 , V_50 ) ;
}
static T_4
F_78 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 ;
struct V_17 * V_18 = F_43 ( V_21 ) ;
long V_37 = F_8 ( V_18 -> V_89 [ V_1 ] ) ;
V_37 += ( V_18 -> V_91 [ V_1 ] >> 6 ) * 250 ;
return sprintf ( V_98 , L_6 , V_37 ) ;
}
static T_4
F_79 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
struct V_17 * V_18 = F_77 ( V_21 ) ;
long V_37 = F_8 ( V_18 -> V_45 [ V_101 ] ) ;
return sprintf ( V_98 , L_6 , V_37 ) ;
}
static T_4
F_80 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
long V_50 ;
if ( F_75 ( V_98 , 10 , & V_50 ) < 0 )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
V_18 -> V_45 [ V_101 ] = F_9 ( V_50 , - 128 , 127 ) ;
F_20 ( V_15 , F_26 ( V_101 ) , V_18 -> V_45 [ V_101 ] ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_81 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_17 * V_18 = F_77 ( V_21 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 ;
int V_50 ;
if ( V_18 -> V_121 & ( 1 << V_1 ) )
V_50 = 3 ;
else
V_50 = 4 ;
return sprintf ( V_98 , L_7 , V_50 ) ;
}
static T_4
F_82 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_1 = V_100 -> V_1 ;
int V_122 ;
unsigned long V_2 ;
T_2 V_50 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
if ( ( V_2 != 4 ) && ( V_2 != 3 ) )
return - V_107 ;
F_30 ( & V_18 -> V_51 ) ;
if ( V_2 == 3 ) {
V_2 = 0x01 ;
V_18 -> V_121 |= 1 << V_1 ;
} else if ( V_2 == 4 ) {
V_2 = 0x03 ;
V_18 -> V_121 &= ~ ( 1 << V_1 ) ;
}
V_122 = 2 * V_1 ;
V_50 = F_18 ( V_15 , V_123 ) ;
V_50 &= ~ ( 0x03 << V_122 ) ;
V_50 |= V_2 << V_122 ;
F_20 ( V_15 , V_123 , V_50 ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_83 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
struct V_17 * V_18 = F_43 ( V_21 ) ;
T_1 V_2 = V_18 -> V_26 [ V_1 ] [ V_101 ] ;
T_2 V_124 ;
switch ( V_101 ) {
case V_82 :
if ( ( V_1 >= 17 ) &&
! ( ( V_18 -> V_125 >> ( V_1 - 17 ) ) & 1 ) )
V_2 *= 8 ;
break;
case V_28 :
case V_30 :
V_124 = V_126 [ V_1 ] [ V_127 ] ;
V_2 <<= 2 ;
V_2 |= ( V_18 -> V_31 [ V_124 ] [ V_101 ] >>
V_126 [ V_1 ] [ V_128 ] ) & 0x03 ;
if ( ( V_1 >= 17 ) &&
! ( ( V_18 -> V_125 >> ( V_1 - 17 ) ) & 1 ) )
V_2 *= 8 ;
break;
}
V_2 = F_1 ( V_1 , V_2 ) ;
return sprintf ( V_98 , L_7 , V_2 ) ;
}
static T_4
F_84 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
int V_1 = V_100 -> V_1 ;
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
unsigned long V_2 ;
T_2 V_50 ;
T_2 V_124 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
V_2 = F_2 ( V_1 , V_2 ) ;
if ( ( V_1 >= 17 ) &&
! ( ( V_18 -> V_125 >> ( V_1 - 17 ) ) & 1 ) )
V_2 /= 8 ;
V_2 = F_5 ( V_2 , 0 , 0x3FF ) ;
F_30 ( & V_18 -> V_51 ) ;
V_124 = V_126 [ V_1 ] [ V_127 ] ;
V_50 = F_18 ( V_15 , F_22 ( V_124 , V_101 ) ) ;
V_50 &= ~ ( 0x03 << V_126 [ V_1 ] [ V_128 ] ) ;
V_50 |= ( V_2 & 0x03 ) << V_126 [ V_1 ] [ V_128 ] ;
F_20 ( V_15 , F_22 ( V_124 , V_101 ) , V_50 ) ;
V_18 -> V_31 [ V_124 ] [ V_101 ] = V_50 ;
V_50 = ( V_2 >> 2 ) & 0xff ;
F_20 ( V_15 , V_29 [ V_1 ] [ V_101 ] , V_50 ) ;
V_18 -> V_26 [ V_1 ] [ V_101 ] = V_50 ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static T_4
F_85 ( struct V_49 * V_21 , struct V_96 * V_97 , char * V_98 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
T_1 V_2 = V_18 -> V_76 [ V_101 ] ;
switch ( V_101 ) {
case V_129 :
case V_130 :
V_2 = F_6 ( V_2 ) ;
break;
}
return sprintf ( V_98 , L_7 , V_2 ) ;
}
static T_4
F_86 ( struct V_49 * V_21 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_104 )
{
struct V_99 * V_100 =
F_49 ( V_97 ) ;
int V_101 = V_100 -> V_101 ;
struct V_14 * V_15 = F_29 ( V_21 ) ;
struct V_17 * V_18 = F_15 ( V_15 ) ;
unsigned long V_2 ;
if ( F_51 ( V_98 , 10 , & V_2 ) < 0 )
return - V_107 ;
switch ( V_101 ) {
case V_131 :
V_2 = F_5 ( V_2 , 0 , 0xff ) ;
break;
case V_129 :
case V_130 :
V_2 = F_7 ( V_2 ) ;
if ( V_2 == 0 )
return - V_107 ;
break;
}
F_30 ( & V_18 -> V_51 ) ;
V_18 -> V_76 [ V_101 ] = V_2 ;
F_20 ( V_15 , F_41 ( V_101 ) , V_2 ) ;
F_42 ( & V_18 -> V_51 ) ;
return V_104 ;
}
static void F_87 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_15 ( V_15 ) ;
static const T_1 V_7 [ 4 ] = {
14318 , 24000 , 33333 , 48000
} ;
T_2 V_132 ;
if ( V_133 )
F_20 ( V_15 , V_134 , 0x80 ) ;
V_132 = F_18 ( V_15 , V_134 ) ;
if ( ! ( V_132 & V_135 ) ) {
F_88 ( & V_15 -> V_21 , L_8 ) ;
F_20 ( V_15 , V_134 ,
V_132 | V_135 ) ;
}
V_18 -> V_7 = V_7 [ ( V_132 >> 3 ) & 0x3 ] ;
F_89 ( & V_15 -> V_21 , L_9 , V_18 -> V_7 ) ;
}
static int F_90 ( struct V_14 * V_15 )
{
int V_136 ;
V_136 = F_19 ( V_15 , V_137 ) ;
if ( V_136 < 0 || ( V_136 & 0xf0 ) != 0x50 ) {
int V_138 ;
V_138 = F_19 ( V_15 ,
V_139 ) ;
if ( V_138 == 0x50 )
V_136 = V_138 ;
}
return V_136 ;
}
static int F_91 ( struct V_14 * V_15 ,
struct V_140 * V_141 )
{
int V_16 , V_142 , V_136 , V_143 , V_144 , V_132 ;
struct V_145 * V_146 = V_15 -> V_146 ;
unsigned short V_147 = V_15 -> V_148 ;
const char * V_149 ;
if ( ! F_92 ( V_146 , V_150 ) )
return - V_151 ;
V_16 = F_19 ( V_15 , V_20 ) ;
if ( V_16 < 0 || ( V_16 & 0x7c ) ) {
F_89 ( & V_146 -> V_21 ,
L_10 ,
V_147 , L_11 ) ;
return - V_151 ;
}
V_142 = F_19 ( V_15 , V_152 ) ;
V_143 = V_16 & 0x80 ? 0x5c : 0xa3 ;
if ( V_142 != V_143 ) {
F_89 ( & V_146 -> V_21 ,
L_10 ,
V_147 , L_12 ) ;
return - V_151 ;
}
V_136 = F_90 ( V_15 ) |
( F_19 ( V_15 , V_153 ) << 8 ) ;
if ( ( V_136 >> 4 ) != 0x795 ) {
F_89 ( & V_146 -> V_21 ,
L_10 ,
V_147 , L_13 ) ;
return - V_151 ;
}
if ( ( V_16 & 0x07 ) == 0 ) {
V_144 = F_19 ( V_15 ,
V_154 ) ;
if ( ( V_144 & 0x7f ) != V_147 ) {
F_89 ( & V_146 -> V_21 ,
L_14
L_15 , V_147 , L_16 ) ;
return - V_151 ;
}
}
if ( ( V_16 & 0x07 ) != 0 )
F_16 ( V_15 , V_20 ,
V_16 & ~ 0x07 ) ;
V_132 = F_19 ( V_15 , V_134 ) ;
if ( V_132 & V_155 )
V_149 = L_17 ;
else
V_149 = L_18 ;
F_93 ( V_141 -> type , V_149 , V_156 ) ;
F_88 ( & V_146 -> V_21 , L_19 , V_149 ,
'A' + ( V_136 & 0xf ) , V_147 ) ;
return 0 ;
}
static int F_94 ( struct V_49 * V_21 ,
const struct V_96 * V_97 )
{
F_95 ( V_21 , V_97 ) ;
return 0 ;
}
static void F_96 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_15 ( V_15 ) ;
T_2 V_157 ;
int V_23 , V_158 , V_159 ;
V_157 = F_18 ( V_15 , V_160 ) ;
if ( ( V_157 & 0x07 ) == 0x00 || ( V_157 & 0x07 ) == 0x07 )
return;
V_18 -> V_84 = ( V_157 >> 3 ) & 0x07 ;
for ( V_23 = 0 ; V_23 < 2 ; V_23 ++ ) {
if ( ! ( V_18 -> V_84 & ( 1 << V_23 ) ) )
continue;
V_158 = F_97 ( & V_15 -> V_21 . V_161 ,
& V_162 [ V_23 ] [ 2 ] . V_163 . V_97 ,
V_164 ) ;
V_159 = F_97 ( & V_15 -> V_21 . V_161 ,
& V_162 [ V_23 ] [ 3 ] . V_163 . V_97 ,
V_164 ) ;
if ( V_158 || V_159 )
F_98 ( & V_15 -> V_21 , L_20
L_21 , V_23 , V_158 , V_159 ) ;
else
F_88 ( & V_15 -> V_21 , L_22
L_23 , V_23 ) ;
}
}
static void F_99 ( struct V_17 * V_18 , T_2 V_132 ,
int V_165 , int V_166 )
{
switch ( V_132 ) {
case 0x2 :
V_18 -> V_27 |= 1 << V_166 ;
break;
case 0x1 :
if ( V_165 >= 4 )
break;
V_18 -> V_121 |= 1 << V_165 ;
case 0x3 :
V_18 -> V_38 |= 1 << V_165 ;
break;
}
}
static int F_100 ( struct V_14 * V_15 ,
const struct V_167 * V_168 )
{
int V_23 ;
T_2 V_50 ;
struct V_49 * V_21 = & V_15 -> V_21 ;
struct V_17 * V_18 ;
int V_19 ;
V_18 = F_101 ( sizeof( struct V_17 ) , V_169 ) ;
if ( ! V_18 ) {
V_19 = - V_170 ;
goto exit;
}
F_102 ( V_15 , V_18 ) ;
V_18 -> V_32 = V_168 -> V_171 ;
V_18 -> V_16 = F_19 ( V_15 , V_20 ) ;
F_103 ( & V_18 -> V_51 ) ;
F_87 ( V_15 ) ;
V_18 -> V_27 = F_18 ( V_15 , V_172 )
| ( F_18 ( V_15 , V_173 ) << 8 ) ;
V_18 -> V_35 = F_18 ( V_15 , V_174 )
| ( F_18 ( V_15 , V_175 ) << 8 ) ;
V_50 = F_18 ( V_15 , V_176 ) ;
if ( V_50 & 0x20 )
V_18 -> V_42 = 1 ;
F_99 ( V_18 , ( V_50 >> 2 ) & 0x3 , 5 , 16 ) ;
F_99 ( V_18 , V_50 & 0x3 , 4 , 15 ) ;
V_50 = F_18 ( V_15 , V_123 ) ;
F_99 ( V_18 , V_50 >> 6 , 3 , 20 ) ;
F_99 ( V_18 , ( V_50 >> 4 ) & 0x3 , 2 , 19 ) ;
F_99 ( V_18 , ( V_50 >> 2 ) & 0x3 , 1 , 18 ) ;
F_99 ( V_18 , V_50 & 0x3 , 0 , 17 ) ;
if ( V_18 -> V_42 ) {
if ( 1 & F_18 ( V_15 , V_177 ) )
V_18 -> V_42 |= 2 ;
V_18 -> V_90 = F_18 ( V_15 , V_178 ) ;
}
if ( V_18 -> V_42 == 1 ) {
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( ! ( V_18 -> V_90 & ( 1 << V_23 ) ) )
continue;
V_50 = F_18 ( V_15 , F_104 ( V_23 ) ) ;
F_88 ( & V_15 -> V_21 ,
L_24 ,
V_23 + 1 , ( unsigned int ) V_50 & 0x7f ) ;
}
}
V_18 -> V_125 = F_18 ( V_15 , V_179 ) & 0x0f ;
if ( V_18 -> V_32 == V_180 )
V_18 -> V_61 = 8 ;
else
V_18 -> V_61 = 2 ;
if ( V_18 -> V_32 == V_180 ) {
V_18 -> V_46 = 1 ;
} else {
V_50 = F_18 ( V_15 , V_181 ) ;
if ( ( V_50 & V_182 ) == 0 )
V_18 -> V_46 = 1 ;
}
V_19 = F_105 ( V_21 , V_183 ) ;
if ( V_19 )
goto V_184;
if ( V_18 -> V_32 == V_180 )
F_96 ( V_15 ) ;
V_18 -> V_185 = F_106 ( V_21 ) ;
if ( F_107 ( V_18 -> V_185 ) ) {
V_19 = F_108 ( V_18 -> V_185 ) ;
goto V_184;
}
return 0 ;
V_184:
F_105 ( V_21 , F_94 ) ;
F_109 ( V_18 ) ;
exit:
return V_19 ;
}
static int F_110 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_15 ( V_15 ) ;
F_111 ( V_18 -> V_185 ) ;
F_105 ( & V_15 -> V_21 , F_94 ) ;
F_109 ( V_18 ) ;
return 0 ;
}
static int T_6 F_112 ( void )
{
return F_113 ( & V_186 ) ;
}
static void T_7 F_114 ( void )
{
F_115 ( & V_186 ) ;
}
