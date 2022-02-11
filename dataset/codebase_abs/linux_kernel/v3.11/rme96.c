static inline unsigned int
F_1 ( struct V_1 * V_1 )
{
return ( F_2 ( V_1 -> V_2 + V_3 )
& V_4 ) >> V_1 -> V_5 ;
}
static inline unsigned int
F_3 ( struct V_1 * V_1 )
{
return ( F_2 ( V_1 -> V_2 + V_6 )
& V_4 ) >> V_1 -> V_7 ;
}
static int
F_4 ( struct V_8 * V_9 ,
int V_10 ,
T_1 V_11 ,
T_1 V_12 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
V_12 <<= V_1 -> V_5 ;
V_11 <<= V_1 -> V_5 ;
F_6 ( V_1 -> V_2 + V_13 + V_11 ,
0 , V_12 ) ;
return 0 ;
}
static int
F_7 ( struct V_8 * V_9 ,
int V_10 ,
T_1 V_11 ,
void T_2 * V_14 ,
T_1 V_12 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
V_12 <<= V_1 -> V_5 ;
V_11 <<= V_1 -> V_5 ;
F_8 ( V_1 -> V_2 + V_13 + V_11 , V_14 ,
V_12 ) ;
return 0 ;
}
static int
F_9 ( struct V_8 * V_9 ,
int V_10 ,
T_1 V_11 ,
void T_2 * V_15 ,
T_1 V_12 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
V_12 <<= V_1 -> V_7 ;
V_11 <<= V_1 -> V_7 ;
F_10 ( V_15 , V_1 -> V_2 + V_16 + V_11 ,
V_12 ) ;
return 0 ;
}
static void
F_11 ( struct V_1 * V_1 , T_3 V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
if ( V_17 & 0x8000 ) {
V_1 -> V_19 |= V_20 ;
} else {
V_1 -> V_19 &= ~ V_20 ;
}
V_1 -> V_19 &= ~ ( V_21 | V_22 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_13 ( 10 ) ;
V_1 -> V_19 |= V_21 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_13 ( 10 ) ;
V_17 <<= 1 ;
}
V_1 -> V_19 &= ~ ( V_21 | V_20 ) ;
V_1 -> V_19 |= V_22 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_13 ( 10 ) ;
V_1 -> V_19 &= ~ V_22 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
}
static void
F_14 ( struct V_1 * V_1 )
{
if ( F_15 ( V_1 ) ) {
F_11 ( V_1 , ( V_1 -> V_24 [ 0 ] << 2 ) | 0x0 ) ;
F_11 ( V_1 , ( V_1 -> V_24 [ 1 ] << 2 ) | 0x2 ) ;
} else if ( F_16 ( V_1 ) ) {
F_11 ( V_1 , ( V_1 -> V_24 [ 0 ] & 0x3FF ) | 0x000 ) ;
F_11 ( V_1 , ( V_1 -> V_24 [ 1 ] & 0x3FF ) | 0x400 ) ;
}
}
static void
F_17 ( struct V_1 * V_1 )
{
F_12 ( V_1 -> V_25 | V_26 ,
V_1 -> V_2 + V_27 ) ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static int
F_18 ( struct V_1 * V_1 )
{
return ( ( V_1 -> V_25 >> V_28 ) & 1 ) +
( ( ( V_1 -> V_25 >> V_29 ) & 1 ) << 1 ) ;
}
static int
F_19 ( struct V_1 * V_1 ,
int V_30 )
{
if ( V_30 & 1 ) {
V_1 -> V_25 |= V_31 ;
} else {
V_1 -> V_25 &= ~ V_31 ;
}
if ( V_30 & 2 ) {
V_1 -> V_25 |= V_32 ;
} else {
V_1 -> V_25 &= ~ V_32 ;
}
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_1 )
{
return ( ( V_1 -> V_25 >> V_33 ) & 1 ) +
( ( ( V_1 -> V_25 >> V_34 ) & 1 ) << 1 ) ;
}
static int
F_21 ( struct V_1 * V_1 ,
int V_35 )
{
switch ( V_35 ) {
case 0 :
V_1 -> V_25 = ( V_1 -> V_25 & ~ V_36 ) &
~ V_37 ;
break;
case 1 :
V_1 -> V_25 = ( V_1 -> V_25 | V_36 ) &
~ V_37 ;
break;
case 2 :
V_1 -> V_25 = ( V_1 -> V_25 & ~ V_36 ) |
V_37 ;
break;
case 3 :
V_1 -> V_25 = ( V_1 -> V_25 | V_36 ) |
V_37 ;
break;
default:
return - V_38 ;
}
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_1 ,
int * V_39 )
{
int V_40 , V_41 ;
* V_39 = 0 ;
if ( V_1 -> V_19 & V_42 ) {
V_40 = ( ( V_1 -> V_19 >> V_43 ) & 1 ) +
( ( ( V_1 -> V_19 >> V_44 ) & 1 ) << 1 ) ;
switch ( V_40 ) {
case 1 :
V_41 = 32000 ;
break;
case 2 :
V_41 = 44100 ;
break;
case 3 :
V_41 = 48000 ;
break;
default:
return - 1 ;
}
return ( V_1 -> V_19 & V_45 ) ? V_41 << 1 : V_41 ;
}
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_47 ) {
* V_39 = 1 ;
if ( V_1 -> V_46 & V_48 ) {
return 48000 ;
}
return 44100 ;
}
if ( V_1 -> V_46 & V_49 ) {
return - 1 ;
}
V_40 = ( ( V_1 -> V_46 >> V_50 ) & 1 ) +
( ( ( V_1 -> V_46 >> V_51 ) & 1 ) << 1 ) +
( ( ( V_1 -> V_46 >> V_52 ) & 1 ) << 2 ) ;
switch ( V_40 ) {
case 0 :
if ( V_1 -> V_46 & V_48 ) {
return 64000 ;
}
return - 1 ;
case 3 : return 96000 ;
case 4 : return 88200 ;
case 5 : return 48000 ;
case 6 : return 44100 ;
case 7 : return 32000 ;
default:
break;
}
return - 1 ;
}
static int
F_23 ( struct V_1 * V_1 )
{
int V_41 , V_53 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
return V_41 ;
}
V_41 = ( ( V_1 -> V_25 >> V_56 ) & 1 ) +
( ( ( V_1 -> V_25 >> V_57 ) & 1 ) << 1 ) ;
switch ( V_41 ) {
case 1 :
V_41 = 32000 ;
break;
case 2 :
V_41 = 44100 ;
break;
case 3 :
V_41 = 48000 ;
break;
default:
return - 1 ;
}
return ( V_1 -> V_25 & V_58 ) ? V_41 << 1 : V_41 ;
}
static int
F_25 ( struct V_1 * V_1 ,
int V_41 )
{
int V_59 ;
V_59 = V_1 -> V_25 & V_58 ;
switch ( V_41 ) {
case 32000 :
V_1 -> V_25 &= ~ V_58 ;
V_1 -> V_25 = ( V_1 -> V_25 | V_60 ) &
~ V_61 ;
break;
case 44100 :
V_1 -> V_25 &= ~ V_58 ;
V_1 -> V_25 = ( V_1 -> V_25 | V_61 ) &
~ V_60 ;
break;
case 48000 :
V_1 -> V_25 &= ~ V_58 ;
V_1 -> V_25 = ( V_1 -> V_25 | V_60 ) |
V_61 ;
break;
case 64000 :
V_1 -> V_25 |= V_58 ;
V_1 -> V_25 = ( V_1 -> V_25 | V_60 ) &
~ V_61 ;
break;
case 88200 :
V_1 -> V_25 |= V_58 ;
V_1 -> V_25 = ( V_1 -> V_25 | V_61 ) &
~ V_60 ;
break;
case 96000 :
V_1 -> V_25 |= V_58 ;
V_1 -> V_25 = ( V_1 -> V_25 | V_60 ) |
V_61 ;
break;
default:
return - V_38 ;
}
if ( ( ! V_59 && V_1 -> V_25 & V_58 ) ||
( V_59 && ! ( V_1 -> V_25 & V_58 ) ) )
{
F_17 ( V_1 ) ;
} else {
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_1 ,
int V_41 )
{
switch ( V_41 ) {
case 32000 :
V_1 -> V_19 = ( ( V_1 -> V_19 | V_62 ) &
~ V_63 ) & ~ V_64 ;
break;
case 44100 :
V_1 -> V_19 = ( ( V_1 -> V_19 & ~ V_62 ) |
V_63 ) & ~ V_64 ;
break;
case 48000 :
V_1 -> V_19 = ( ( V_1 -> V_19 | V_62 ) |
V_63 ) & ~ V_64 ;
break;
case 64000 :
if ( V_1 -> V_65 < 4 ) {
return - V_38 ;
}
V_1 -> V_19 = ( ( V_1 -> V_19 | V_62 ) &
~ V_63 ) | V_64 ;
break;
case 88200 :
if ( V_1 -> V_65 < 4 ) {
return - V_38 ;
}
V_1 -> V_19 = ( ( V_1 -> V_19 & ~ V_62 ) |
V_63 ) | V_64 ;
break;
case 96000 :
V_1 -> V_19 = ( ( V_1 -> V_19 | V_62 ) |
V_63 ) | V_64 ;
break;
default:
return - V_38 ;
}
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_1 ,
int V_66 )
{
switch ( V_66 ) {
case V_67 :
V_1 -> V_25 &= ~ V_54 ;
V_1 -> V_19 &= ~ V_68 ;
break;
case V_69 :
V_1 -> V_25 |= V_54 ;
V_1 -> V_19 &= ~ V_68 ;
break;
case V_70 :
V_1 -> V_25 |= V_54 ;
V_1 -> V_19 |= V_68 ;
break;
default:
return - V_38 ;
}
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
return 0 ;
}
static int
F_28 ( struct V_1 * V_1 )
{
if ( V_1 -> V_19 & V_68 ) {
return V_70 ;
}
return ( V_1 -> V_25 & V_54 ) ? V_69 :
V_67 ;
}
static int
F_29 ( struct V_1 * V_1 ,
int type )
{
int V_40 ;
switch ( type ) {
case V_71 :
V_1 -> V_25 = ( V_1 -> V_25 & ~ V_72 ) &
~ V_73 ;
break;
case V_74 :
V_1 -> V_25 = ( V_1 -> V_25 | V_72 ) &
~ V_73 ;
break;
case V_75 :
V_1 -> V_25 = ( V_1 -> V_25 & ~ V_72 ) |
V_73 ;
break;
case V_76 :
if ( ( V_1 -> V_77 -> V_78 != V_79 &&
V_1 -> V_77 -> V_78 != V_80 ) ||
( V_1 -> V_77 -> V_78 == V_79 &&
V_1 -> V_65 > 4 ) )
{
return - V_38 ;
}
V_1 -> V_25 = ( V_1 -> V_25 | V_72 ) |
V_73 ;
break;
case V_55 :
if ( ! F_30 ( V_1 ) ) {
return - V_38 ;
}
V_1 -> V_19 |= V_42 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
if ( V_1 -> V_65 < 4 ) {
if ( F_22 ( V_1 , & V_40 ) == 88200 ) {
F_26 ( V_1 , 44100 ) ;
}
if ( F_22 ( V_1 , & V_40 ) == 64000 ) {
F_26 ( V_1 , 32000 ) ;
}
}
return 0 ;
default:
return - V_38 ;
}
if ( type != V_55 && F_30 ( V_1 ) ) {
V_1 -> V_19 &= ~ V_42 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
}
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_19 & V_42 ) {
return V_55 ;
}
return ( ( V_1 -> V_25 >> V_81 ) & 1 ) +
( ( ( V_1 -> V_25 >> V_82 ) & 1 ) << 1 ) ;
}
static void
F_31 ( struct V_1 * V_1 ,
int V_83 ,
int V_84 )
{
int V_85 ;
if ( V_83 == 2 ) {
V_85 = 1 ;
} else {
V_85 = 3 ;
}
if ( V_84 ) {
V_85 += ( V_1 -> V_25 & V_86 ) ? 2 : 1 ;
V_1 -> V_5 = V_85 ;
} else {
V_85 += ( V_1 -> V_25 & V_87 ) ? 2 : 1 ;
V_1 -> V_7 = V_85 ;
}
}
static int
F_32 ( struct V_1 * V_1 ,
int V_88 )
{
switch ( V_88 ) {
case V_89 :
V_1 -> V_25 &= ~ V_86 ;
break;
case V_90 :
V_1 -> V_25 |= V_86 ;
break;
default:
return - V_38 ;
}
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
return 0 ;
}
static int
F_33 ( struct V_1 * V_1 ,
int V_88 )
{
switch ( V_88 ) {
case V_89 :
V_1 -> V_25 &= ~ V_87 ;
break;
case V_90 :
V_1 -> V_25 |= V_87 ;
break;
default:
return - V_38 ;
}
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
return 0 ;
}
static void
F_34 ( struct V_1 * V_1 ,
T_4 V_91 )
{
switch ( V_91 ) {
case V_92 :
V_1 -> V_25 &= ~ V_93 ;
break;
case V_94 :
V_1 -> V_25 |= V_93 ;
break;
default:
F_35 () ;
break;
}
V_1 -> V_25 &= ~ V_95 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static int
F_36 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
int V_100 , V_41 , V_53 ;
V_99 -> V_101 = ( void V_102 * ) ( V_1 -> V_2 +
V_13 ) ;
V_99 -> V_103 = V_1 -> V_104 + V_13 ;
V_99 -> V_105 = V_106 ;
F_37 ( & V_1 -> V_107 ) ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
if ( ( int ) F_38 ( V_97 ) != V_41 ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_108 ;
}
} else if ( ( V_100 = F_25 ( V_1 , F_38 ( V_97 ) ) ) < 0 ) {
F_39 ( & V_1 -> V_107 ) ;
return V_100 ;
}
if ( ( V_100 = F_32 ( V_1 , F_40 ( V_97 ) ) ) < 0 ) {
F_39 ( & V_1 -> V_107 ) ;
return V_100 ;
}
F_31 ( V_1 , F_41 ( V_97 ) , 1 ) ;
if ( V_1 -> V_109 != 0 ) {
if ( F_42 ( V_97 ) << V_1 -> V_5 !=
V_1 -> V_109 )
{
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
}
V_1 -> V_111 =
F_42 ( V_97 ) << V_1 -> V_5 ;
F_34 ( V_1 , V_1 -> V_111 ) ;
if ( ( V_1 -> V_25 & V_112 ) == 0 ) {
V_1 -> V_25 &= ~ ( V_113 | V_114 | V_115 ) ;
F_12 ( V_1 -> V_25 |= V_1 -> V_116 , V_1 -> V_2 + V_27 ) ;
}
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_43 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
int V_100 , V_117 , V_41 ;
V_99 -> V_101 = ( void V_102 * ) ( V_1 -> V_2 +
V_16 ) ;
V_99 -> V_103 = V_1 -> V_104 + V_16 ;
V_99 -> V_105 = V_106 ;
F_37 ( & V_1 -> V_107 ) ;
if ( ( V_100 = F_33 ( V_1 , F_40 ( V_97 ) ) ) < 0 ) {
F_39 ( & V_1 -> V_107 ) ;
return V_100 ;
}
if ( F_24 ( V_1 ) == V_55 ) {
if ( ( V_100 = F_26 ( V_1 ,
F_38 ( V_97 ) ) ) < 0 )
{
F_39 ( & V_1 -> V_107 ) ;
return V_100 ;
}
} else if ( ( V_41 = F_22 ( V_1 , & V_117 ) ) > 0 ) {
if ( ( int ) F_38 ( V_97 ) != V_41 ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_108 ;
}
if ( ( V_117 && V_99 -> V_118 . V_119 == 2 ) ||
( ! V_117 && V_99 -> V_118 . V_119 == 8 ) )
{
F_39 ( & V_1 -> V_107 ) ;
return - V_108 ;
}
}
F_31 ( V_1 , F_41 ( V_97 ) , 0 ) ;
if ( V_1 -> V_111 != 0 ) {
if ( F_42 ( V_97 ) << V_1 -> V_7 !=
V_1 -> V_111 )
{
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
}
V_1 -> V_109 =
F_42 ( V_97 ) << V_1 -> V_7 ;
F_34 ( V_1 , V_1 -> V_109 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static void
F_44 ( struct V_1 * V_1 ,
int V_120 )
{
if ( ! V_120 ) {
F_12 ( 0 , V_1 -> V_2 + V_121 ) ;
}
V_1 -> V_25 |= V_122 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static void
F_45 ( struct V_1 * V_1 ,
int V_120 )
{
if ( ! V_120 ) {
F_12 ( 0 , V_1 -> V_2 + V_123 ) ;
}
V_1 -> V_25 |= V_124 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static void
F_46 ( struct V_1 * V_1 )
{
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_125 ) {
F_12 ( 0 , V_1 -> V_2 + V_126 ) ;
}
V_1 -> V_25 &= ~ V_122 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static void
F_47 ( struct V_1 * V_1 )
{
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_127 ) {
F_12 ( 0 , V_1 -> V_2 + V_128 ) ;
}
V_1 -> V_25 &= ~ V_124 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static T_5
F_48 ( int V_129 ,
void * V_130 )
{
struct V_1 * V_1 = (struct V_1 * ) V_130 ;
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( ! ( ( V_1 -> V_46 & V_125 ) ||
( V_1 -> V_46 & V_127 ) ) )
{
return V_131 ;
}
if ( V_1 -> V_46 & V_125 ) {
F_49 ( V_1 -> V_132 ) ;
F_12 ( 0 , V_1 -> V_2 + V_126 ) ;
}
if ( V_1 -> V_46 & V_127 ) {
F_49 ( V_1 -> V_133 ) ;
F_12 ( 0 , V_1 -> V_2 + V_128 ) ;
}
return V_134 ;
}
static void
F_50 ( struct V_1 * V_1 ,
struct V_98 * V_99 )
{
unsigned int V_135 ;
F_51 ( V_99 , V_136 ,
V_106 , V_106 ) ;
if ( ( V_135 = V_1 -> V_111 ) != 0 ||
( V_135 = V_1 -> V_109 ) != 0 )
F_51 ( V_99 ,
V_137 ,
V_135 , V_135 ) ;
else
F_52 ( V_99 , 0 ,
V_137 ,
& V_138 ) ;
}
static int
F_53 ( struct V_8 * V_9 )
{
int V_41 , V_53 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_132 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_25 &= ~ V_112 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
V_1 -> V_132 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
V_99 -> V_118 = V_139 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
V_99 -> V_118 . V_140 = F_54 ( V_41 ) ;
V_99 -> V_118 . V_141 = V_41 ;
V_99 -> V_118 . V_142 = V_41 ;
}
F_50 ( V_1 , V_99 ) ;
V_1 -> V_116 = V_1 -> V_143 ;
V_1 -> V_144 -> V_145 [ 0 ] . V_146 &= ~ V_147 ;
F_55 ( V_1 -> V_148 , V_149 |
V_150 , & V_1 -> V_144 -> V_151 ) ;
return 0 ;
}
static int
F_56 ( struct V_8 * V_9 )
{
int V_117 , V_41 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
V_99 -> V_118 = V_152 ;
if ( F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_117 ) ) > 0 )
{
if ( V_117 ) {
return - V_108 ;
}
V_99 -> V_118 . V_140 = F_54 ( V_41 ) ;
V_99 -> V_118 . V_141 = V_41 ;
V_99 -> V_118 . V_142 = V_41 ;
}
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_133 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_133 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
F_50 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_57 ( struct V_8 * V_9 )
{
int V_41 , V_53 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_132 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_25 |= V_112 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
V_1 -> V_132 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
V_99 -> V_118 = V_153 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
V_99 -> V_118 . V_140 = F_54 ( V_41 ) ;
V_99 -> V_118 . V_141 = V_41 ;
V_99 -> V_118 . V_142 = V_41 ;
}
F_50 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_58 ( struct V_8 * V_9 )
{
int V_117 , V_41 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
V_99 -> V_118 = V_154 ;
if ( F_24 ( V_1 ) == V_55 ) {
return - V_108 ;
}
if ( ( V_41 = F_22 ( V_1 , & V_117 ) ) > 0 ) {
if ( ! V_117 ) {
return - V_108 ;
}
V_99 -> V_118 . V_140 = F_54 ( V_41 ) ;
V_99 -> V_118 . V_141 = V_41 ;
V_99 -> V_118 . V_142 = V_41 ;
}
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_133 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_133 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
F_50 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_59 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
int V_155 = 0 ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_60 ( V_1 ) ) {
F_46 ( V_1 ) ;
}
V_1 -> V_132 = NULL ;
V_1 -> V_111 = 0 ;
V_155 = ( V_1 -> V_25 & V_112 ) == 0 ;
F_39 ( & V_1 -> V_107 ) ;
if ( V_155 ) {
V_1 -> V_144 -> V_145 [ 0 ] . V_146 |= V_147 ;
F_55 ( V_1 -> V_148 , V_149 |
V_150 , & V_1 -> V_144 -> V_151 ) ;
}
return 0 ;
}
static int
F_61 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_62 ( V_1 ) ) {
F_47 ( V_1 ) ;
}
V_1 -> V_133 = NULL ;
V_1 -> V_109 = 0 ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_63 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_60 ( V_1 ) ) {
F_46 ( V_1 ) ;
}
F_12 ( 0 , V_1 -> V_2 + V_121 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_64 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_62 ( V_1 ) ) {
F_47 ( V_1 ) ;
}
F_12 ( 0 , V_1 -> V_2 + V_123 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_65 ( struct V_8 * V_9 ,
int V_156 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
switch ( V_156 ) {
case V_157 :
if ( ! F_60 ( V_1 ) ) {
if ( V_9 != V_1 -> V_132 ) {
return - V_110 ;
}
F_44 ( V_1 , 0 ) ;
}
break;
case V_158 :
if ( F_60 ( V_1 ) ) {
if ( V_9 != V_1 -> V_132 ) {
return - V_110 ;
}
F_46 ( V_1 ) ;
}
break;
case V_159 :
if ( F_60 ( V_1 ) ) {
F_46 ( V_1 ) ;
}
break;
case V_160 :
if ( ! F_60 ( V_1 ) ) {
F_44 ( V_1 , 1 ) ;
}
break;
default:
return - V_38 ;
}
return 0 ;
}
static int
F_66 ( struct V_8 * V_9 ,
int V_156 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
switch ( V_156 ) {
case V_157 :
if ( ! F_62 ( V_1 ) ) {
if ( V_9 != V_1 -> V_133 ) {
return - V_110 ;
}
F_45 ( V_1 , 0 ) ;
}
break;
case V_158 :
if ( F_62 ( V_1 ) ) {
if ( V_9 != V_1 -> V_133 ) {
return - V_110 ;
}
F_47 ( V_1 ) ;
}
break;
case V_159 :
if ( F_62 ( V_1 ) ) {
F_47 ( V_1 ) ;
}
break;
case V_160 :
if ( ! F_62 ( V_1 ) ) {
F_45 ( V_1 , 1 ) ;
}
break;
default:
return - V_38 ;
}
return 0 ;
}
static T_1
F_67 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
return F_1 ( V_1 ) ;
}
static T_1
F_68 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
return F_3 ( V_1 ) ;
}
static void
F_69 ( void * V_161 )
{
struct V_1 * V_1 = (struct V_1 * ) V_161 ;
if ( V_1 == NULL ) {
return;
}
if ( V_1 -> V_129 >= 0 ) {
F_46 ( V_1 ) ;
F_47 ( V_1 ) ;
V_1 -> V_19 &= ~ V_162 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_70 ( V_1 -> V_129 , ( void * ) V_1 ) ;
V_1 -> V_129 = - 1 ;
}
if ( V_1 -> V_2 ) {
F_71 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
if ( V_1 -> V_104 ) {
F_72 ( V_1 -> V_77 ) ;
V_1 -> V_104 = 0 ;
}
F_73 ( V_1 -> V_77 ) ;
}
static void
F_74 ( struct V_163 * V_164 )
{
struct V_1 * V_1 = V_164 -> V_161 ;
V_1 -> V_165 = NULL ;
}
static void
F_75 ( struct V_163 * V_164 )
{
struct V_1 * V_1 = V_164 -> V_161 ;
V_1 -> V_166 = NULL ;
}
static int
F_76 ( struct V_1 * V_1 )
{
struct V_167 * V_77 = V_1 -> V_77 ;
int V_100 ;
V_1 -> V_129 = - 1 ;
F_77 ( & V_1 -> V_107 ) ;
if ( ( V_100 = F_78 ( V_77 ) ) < 0 )
return V_100 ;
if ( ( V_100 = F_79 ( V_77 , L_1 ) ) < 0 )
return V_100 ;
V_1 -> V_104 = F_80 ( V_1 -> V_77 , 0 ) ;
V_1 -> V_2 = F_81 ( V_1 -> V_104 , V_168 ) ;
if ( ! V_1 -> V_2 ) {
F_82 ( V_169 L_2 , V_1 -> V_104 , V_1 -> V_104 + V_168 - 1 ) ;
return - V_170 ;
}
if ( F_83 ( V_77 -> V_129 , F_48 , V_171 ,
V_172 , V_1 ) ) {
F_82 ( V_169 L_3 , V_77 -> V_129 ) ;
return - V_110 ;
}
V_1 -> V_129 = V_77 -> V_129 ;
F_84 ( V_77 , 8 , & V_1 -> V_65 ) ;
if ( ( V_100 = F_85 ( V_1 -> V_148 , L_4 , 0 ,
1 , 1 , & V_1 -> V_165 ) ) < 0 )
{
return V_100 ;
}
V_1 -> V_165 -> V_161 = V_1 ;
V_1 -> V_165 -> V_173 = F_74 ;
strcpy ( V_1 -> V_165 -> V_174 , L_4 ) ;
F_86 ( V_1 -> V_165 , V_175 , & V_176 ) ;
F_86 ( V_1 -> V_165 , V_177 , & V_178 ) ;
V_1 -> V_165 -> V_179 = 0 ;
if ( V_77 -> V_78 == V_180 ) {
V_1 -> V_166 = NULL ;
} else {
if ( ( V_100 = F_85 ( V_1 -> V_148 , L_5 , 1 ,
1 , 1 , & V_1 -> V_166 ) ) < 0 )
{
return V_100 ;
}
V_1 -> V_166 -> V_161 = V_1 ;
V_1 -> V_166 -> V_173 = F_75 ;
strcpy ( V_1 -> V_166 -> V_174 , L_5 ) ;
F_86 ( V_1 -> V_166 , V_175 , & V_181 ) ;
F_86 ( V_1 -> V_166 , V_177 , & V_182 ) ;
V_1 -> V_166 -> V_179 = 0 ;
}
V_1 -> V_111 = 0 ;
V_1 -> V_109 = 0 ;
F_46 ( V_1 ) ;
F_47 ( V_1 ) ;
V_1 -> V_25 =
V_61 |
V_183 |
V_54 |
V_72 ;
V_1 -> V_19 = V_63 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 | V_184 ,
V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_17 ( V_1 ) ;
V_1 -> V_19 |= V_162 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_12 ( 0 , V_1 -> V_2 + V_121 ) ;
F_12 ( 0 , V_1 -> V_2 + V_123 ) ;
V_1 -> V_24 [ 0 ] = V_1 -> V_24 [ 1 ] = 0 ;
if ( F_87 ( V_1 ) ) {
F_14 ( V_1 ) ;
}
if ( ( V_100 = F_88 ( V_1 -> V_148 , V_1 ) ) < 0 ) {
return V_100 ;
}
F_89 ( V_1 ) ;
return 0 ;
}
static void
F_90 ( struct V_185 * V_186 , struct V_187 * V_188 )
{
int V_40 ;
struct V_1 * V_1 = V_186 -> V_161 ;
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
F_91 ( V_188 , V_1 -> V_148 -> V_189 ) ;
F_91 ( V_188 , L_6 , V_1 -> V_148 -> V_190 + 1 ) ;
F_91 ( V_188 , L_7 ) ;
if ( V_1 -> V_25 & V_95 ) {
F_91 ( V_188 , L_8
L_9 ) ;
} else if ( V_1 -> V_25 & V_93 ) {
F_91 ( V_188 , L_10 ) ;
} else {
F_91 ( V_188 , L_11 ) ;
}
F_91 ( V_188 , L_12 ) ;
switch ( F_24 ( V_1 ) ) {
case V_71 :
F_91 ( V_188 , L_13 ) ;
break;
case V_74 :
F_91 ( V_188 , L_14 ) ;
break;
case V_75 :
F_91 ( V_188 , L_15 ) ;
break;
case V_76 :
F_91 ( V_188 , L_16 ) ;
break;
case V_55 :
F_91 ( V_188 , L_17 ) ;
break;
}
if ( F_22 ( V_1 , & V_40 ) < 0 ) {
F_91 ( V_188 , L_18 ) ;
} else {
if ( V_40 ) {
F_91 ( V_188 , L_19 ) ;
} else {
F_91 ( V_188 , L_20 ) ;
}
F_91 ( V_188 , L_21 ,
F_22 ( V_1 , & V_40 ) ) ;
}
if ( V_1 -> V_25 & V_87 ) {
F_91 ( V_188 , L_22 ) ;
} else {
F_91 ( V_188 , L_23 ) ;
}
F_91 ( V_188 , L_24 ) ;
if ( V_1 -> V_25 & V_183 ) {
F_91 ( V_188 , L_25 ) ;
} else {
F_91 ( V_188 , L_26 ) ;
}
F_91 ( V_188 , L_21 ,
F_23 ( V_1 ) ) ;
if ( V_1 -> V_25 & V_86 ) {
F_91 ( V_188 , L_22 ) ;
} else {
F_91 ( V_188 , L_23 ) ;
}
if ( V_1 -> V_19 & V_68 ) {
F_91 ( V_188 , L_27 ) ;
} else if ( V_1 -> V_25 & V_54 ) {
F_91 ( V_188 , L_28 ) ;
} else if ( F_24 ( V_1 ) == V_55 ) {
F_91 ( V_188 , L_29 ) ;
} else if ( F_22 ( V_1 , & V_40 ) < 0 ) {
F_91 ( V_188 , L_30 ) ;
} else {
F_91 ( V_188 , L_31 ) ;
}
if ( V_1 -> V_25 & V_113 ) {
F_91 ( V_188 , L_32 ) ;
} else {
F_91 ( V_188 , L_33 ) ;
}
if ( V_1 -> V_25 & V_115 ) {
F_91 ( V_188 , L_34 ) ;
} else {
F_91 ( V_188 , L_35 ) ;
}
if ( V_1 -> V_25 & V_114 ) {
F_91 ( V_188 , L_36 ) ;
} else {
F_91 ( V_188 , L_37 ) ;
}
if ( F_30 ( V_1 ) ) {
F_91 ( V_188 , L_38 ) ;
switch ( F_18 ( V_1 ) ) {
case V_191 :
F_91 ( V_188 , L_39 ) ;
break;
case V_192 :
F_91 ( V_188 , L_40 ) ;
break;
case V_193 :
F_91 ( V_188 , L_41 ) ;
break;
case V_194 :
F_91 ( V_188 , L_42 ) ;
break;
}
switch ( F_20 ( V_1 ) ) {
case V_195 :
F_91 ( V_188 , L_43 ) ;
break;
case V_196 :
F_91 ( V_188 , L_44 ) ;
break;
case V_197 :
F_91 ( V_188 , L_45 ) ;
break;
case V_198 :
F_91 ( V_188 , L_46 ) ;
break;
}
F_91 ( V_188 , L_47 , V_1 -> V_24 [ 0 ] ) ;
F_91 ( V_188 , L_48 , V_1 -> V_24 [ 1 ] ) ;
}
}
static void F_89 ( struct V_1 * V_1 )
{
struct V_185 * V_186 ;
if ( ! F_92 ( V_1 -> V_148 , L_49 , & V_186 ) )
F_93 ( V_186 , V_1 , F_90 ) ;
}
static int
F_94 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_202 -> V_203 . integer . V_203 [ 0 ] = V_1 -> V_25 & V_183 ? 0 : 1 ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_96 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
unsigned int V_17 ;
int V_204 ;
V_17 = V_202 -> V_203 . integer . V_203 [ 0 ] ? 0 : V_183 ;
F_37 ( & V_1 -> V_107 ) ;
V_17 = ( V_1 -> V_25 & ~ V_183 ) | V_17 ;
V_204 = V_17 != V_1 -> V_25 ;
V_1 -> V_25 = V_17 ;
F_12 ( V_17 , V_1 -> V_2 + V_27 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int
F_97 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
static char * V_207 [ 5 ] = { L_50 , L_51 , L_52 , L_53 , L_54 } ;
struct V_1 * V_1 = F_95 ( V_200 ) ;
char * V_208 [ 5 ] = { V_207 [ 0 ] , V_207 [ 1 ] , V_207 [ 2 ] , V_207 [ 3 ] , V_207 [ 4 ] } ;
V_206 -> type = V_209 ;
V_206 -> V_12 = 1 ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_180 :
case V_210 :
V_206 -> V_203 . V_211 . V_212 = 3 ;
break;
case V_80 :
V_206 -> V_203 . V_211 . V_212 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
V_206 -> V_203 . V_211 . V_212 = 4 ;
V_208 [ 3 ] = V_207 [ 4 ] ;
} else {
V_206 -> V_203 . V_211 . V_212 = 5 ;
}
break;
default:
F_35 () ;
break;
}
if ( V_206 -> V_203 . V_211 . V_213 > V_206 -> V_203 . V_211 . V_212 - 1 ) {
V_206 -> V_203 . V_211 . V_213 = V_206 -> V_203 . V_211 . V_212 - 1 ;
}
strcpy ( V_206 -> V_203 . V_211 . V_174 , V_208 [ V_206 -> V_203 . V_211 . V_213 ] ) ;
return 0 ;
}
static int
F_98 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
unsigned int V_212 = 3 ;
F_37 ( & V_1 -> V_107 ) ;
V_202 -> V_203 . V_211 . V_213 [ 0 ] = F_24 ( V_1 ) ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_180 :
case V_210 :
V_212 = 3 ;
break;
case V_80 :
V_212 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
if ( V_202 -> V_203 . V_211 . V_213 [ 0 ] == V_55 ) {
V_202 -> V_203 . V_211 . V_213 [ 0 ] = V_76 ;
}
V_212 = 4 ;
} else {
V_212 = 5 ;
}
break;
default:
F_35 () ;
break;
}
if ( V_202 -> V_203 . V_211 . V_213 [ 0 ] >= V_212 ) {
V_202 -> V_203 . V_211 . V_213 [ 0 ] = V_212 - 1 ;
}
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_99 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
unsigned int V_17 ;
int V_204 , V_212 = 3 ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_180 :
case V_210 :
V_212 = 3 ;
break;
case V_80 :
V_212 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
V_212 = 4 ;
} else {
V_212 = 5 ;
}
break;
default:
F_35 () ;
break;
}
V_17 = V_202 -> V_203 . V_211 . V_213 [ 0 ] % V_212 ;
if ( V_1 -> V_77 -> V_78 == V_79 && V_1 -> V_65 > 4 ) {
if ( V_17 == V_76 ) {
V_17 = V_55 ;
}
}
F_37 ( & V_1 -> V_107 ) ;
V_204 = ( int ) V_17 != F_24 ( V_1 ) ;
F_29 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int
F_100 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
static char * V_208 [ 3 ] = { L_55 , L_52 , L_56 } ;
V_206 -> type = V_209 ;
V_206 -> V_12 = 1 ;
V_206 -> V_203 . V_211 . V_212 = 3 ;
if ( V_206 -> V_203 . V_211 . V_213 > 2 ) {
V_206 -> V_203 . V_211 . V_213 = 2 ;
}
strcpy ( V_206 -> V_203 . V_211 . V_174 , V_208 [ V_206 -> V_203 . V_211 . V_213 ] ) ;
return 0 ;
}
static int
F_101 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_202 -> V_203 . V_211 . V_213 [ 0 ] = F_28 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_102 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
unsigned int V_17 ;
int V_204 ;
V_17 = V_202 -> V_203 . V_211 . V_213 [ 0 ] % 3 ;
F_37 ( & V_1 -> V_107 ) ;
V_204 = ( int ) V_17 != F_28 ( V_1 ) ;
F_27 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int
F_103 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
static char * V_208 [ 4 ] = { L_57 , L_58 , L_59 , L_60 } ;
V_206 -> type = V_209 ;
V_206 -> V_12 = 1 ;
V_206 -> V_203 . V_211 . V_212 = 4 ;
if ( V_206 -> V_203 . V_211 . V_213 > 3 ) {
V_206 -> V_203 . V_211 . V_213 = 3 ;
}
strcpy ( V_206 -> V_203 . V_211 . V_174 , V_208 [ V_206 -> V_203 . V_211 . V_213 ] ) ;
return 0 ;
}
static int
F_104 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_202 -> V_203 . V_211 . V_213 [ 0 ] = F_20 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_105 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
unsigned int V_17 ;
int V_204 ;
V_17 = V_202 -> V_203 . V_211 . V_213 [ 0 ] % 4 ;
F_37 ( & V_1 -> V_107 ) ;
V_204 = ( int ) V_17 != F_20 ( V_1 ) ;
F_21 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int
F_106 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
static char * V_208 [ 4 ] = { L_61 , L_62 , L_63 , L_64 } ;
V_206 -> type = V_209 ;
V_206 -> V_12 = 1 ;
V_206 -> V_203 . V_211 . V_212 = 4 ;
if ( V_206 -> V_203 . V_211 . V_213 > 3 ) {
V_206 -> V_203 . V_211 . V_213 = 3 ;
}
strcpy ( V_206 -> V_203 . V_211 . V_174 , V_208 [ V_206 -> V_203 . V_211 . V_213 ] ) ;
return 0 ;
}
static int
F_107 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_202 -> V_203 . V_211 . V_213 [ 0 ] = F_18 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_108 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
unsigned int V_17 ;
int V_204 ;
V_17 = V_202 -> V_203 . V_211 . V_213 [ 0 ] % 4 ;
F_37 ( & V_1 -> V_107 ) ;
V_204 = ( int ) V_17 != F_18 ( V_1 ) ;
F_19 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static T_6 F_109 ( struct V_214 * V_215 )
{
T_6 V_17 = 0 ;
V_17 |= ( V_215 -> V_216 [ 0 ] & V_217 ) ? V_113 : 0 ;
V_17 |= ( V_215 -> V_216 [ 0 ] & V_218 ) ? V_114 : 0 ;
if ( V_17 & V_113 )
V_17 |= ( V_215 -> V_216 [ 0 ] & V_219 ) ? V_115 : 0 ;
else
V_17 |= ( V_215 -> V_216 [ 0 ] & V_220 ) ? V_115 : 0 ;
return V_17 ;
}
static void F_110 ( struct V_214 * V_215 , T_6 V_17 )
{
V_215 -> V_216 [ 0 ] = ( ( V_17 & V_113 ) ? V_217 : 0 ) |
( ( V_17 & V_114 ) ? V_218 : 0 ) ;
if ( V_17 & V_113 )
V_215 -> V_216 [ 0 ] |= ( V_17 & V_115 ) ? V_219 : 0 ;
else
V_215 -> V_216 [ 0 ] |= ( V_17 & V_115 ) ? V_220 : 0 ;
}
static int F_111 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
V_206 -> type = V_221 ;
V_206 -> V_12 = 1 ;
return 0 ;
}
static int F_112 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_110 ( & V_202 -> V_203 . V_222 , V_1 -> V_143 ) ;
return 0 ;
}
static int F_113 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
int V_204 ;
T_6 V_17 ;
V_17 = F_109 ( & V_202 -> V_203 . V_222 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_204 = V_17 != V_1 -> V_143 ;
V_1 -> V_143 = V_17 ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int F_114 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
V_206 -> type = V_221 ;
V_206 -> V_12 = 1 ;
return 0 ;
}
static int F_115 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_110 ( & V_202 -> V_203 . V_222 , V_1 -> V_116 ) ;
return 0 ;
}
static int F_116 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
int V_204 ;
T_6 V_17 ;
V_17 = F_109 ( & V_202 -> V_203 . V_222 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_204 = V_17 != V_1 -> V_116 ;
V_1 -> V_116 = V_17 ;
V_1 -> V_25 &= ~ ( V_113 | V_114 | V_115 ) ;
V_1 -> V_25 |= V_17 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int F_117 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
V_206 -> type = V_221 ;
V_206 -> V_12 = 1 ;
return 0 ;
}
static int F_118 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
V_202 -> V_203 . V_222 . V_216 [ 0 ] = V_200 -> V_223 ;
return 0 ;
}
static int
F_119 ( struct V_199 * V_200 , struct V_205 * V_206 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
V_206 -> type = V_224 ;
V_206 -> V_12 = 2 ;
V_206 -> V_203 . integer . V_225 = 0 ;
V_206 -> V_203 . integer . V_226 = F_120 ( V_1 ) ;
return 0 ;
}
static int
F_121 ( struct V_199 * V_200 , struct V_201 * V_227 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_227 -> V_203 . integer . V_203 [ 0 ] = V_1 -> V_24 [ 0 ] ;
V_227 -> V_203 . integer . V_203 [ 1 ] = V_1 -> V_24 [ 1 ] ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_122 ( struct V_199 * V_200 , struct V_201 * V_227 )
{
struct V_1 * V_1 = F_95 ( V_200 ) ;
int V_204 = 0 ;
unsigned int V_24 , V_228 ;
if ( ! F_87 ( V_1 ) )
return - V_38 ;
V_228 = F_120 ( V_1 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_24 = V_227 -> V_203 . integer . V_203 [ 0 ] ;
if ( V_24 != V_1 -> V_24 [ 0 ] && V_24 <= V_228 ) {
V_1 -> V_24 [ 0 ] = V_24 ;
V_204 = 1 ;
}
V_24 = V_227 -> V_203 . integer . V_203 [ 1 ] ;
if ( V_24 != V_1 -> V_24 [ 1 ] && V_24 <= V_228 ) {
V_1 -> V_24 [ 1 ] = V_24 ;
V_204 = 1 ;
}
if ( V_204 )
F_14 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_204 ;
}
static int
F_88 ( struct V_229 * V_148 ,
struct V_1 * V_1 )
{
int V_230 , V_100 ;
struct V_199 * V_231 ;
for ( V_230 = 0 ; V_230 < 7 ; V_230 ++ ) {
if ( ( V_100 = F_123 ( V_148 , V_231 = F_124 ( & V_232 [ V_230 ] , V_1 ) ) ) < 0 )
return V_100 ;
if ( V_230 == 1 )
V_1 -> V_144 = V_231 ;
}
if ( F_87 ( V_1 ) ) {
for ( V_230 = 7 ; V_230 < 10 ; V_230 ++ )
if ( ( V_100 = F_123 ( V_148 , F_124 ( & V_232 [ V_230 ] , V_1 ) ) ) < 0 )
return V_100 ;
}
return 0 ;
}
static void F_125 ( struct V_229 * V_148 )
{
F_69 ( V_148 -> V_161 ) ;
}
static int
F_126 ( struct V_167 * V_77 ,
const struct V_233 * V_234 )
{
static int V_235 ;
struct V_1 * V_1 ;
struct V_229 * V_148 ;
int V_100 ;
T_7 V_17 ;
if ( V_235 >= V_236 ) {
return - V_237 ;
}
if ( ! V_238 [ V_235 ] ) {
V_235 ++ ;
return - V_239 ;
}
V_100 = F_127 ( V_240 [ V_235 ] , V_151 [ V_235 ] , V_241 ,
sizeof( struct V_1 ) , & V_148 ) ;
if ( V_100 < 0 )
return V_100 ;
V_148 -> V_173 = F_125 ;
V_1 = V_148 -> V_161 ;
V_1 -> V_148 = V_148 ;
V_1 -> V_77 = V_77 ;
F_128 ( V_148 , & V_77 -> V_235 ) ;
if ( ( V_100 = F_76 ( V_1 ) ) < 0 ) {
F_129 ( V_148 ) ;
return V_100 ;
}
strcpy ( V_148 -> V_242 , L_65 ) ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_180 :
strcpy ( V_148 -> V_243 , L_66 ) ;
break;
case V_210 :
strcpy ( V_148 -> V_243 , L_67 ) ;
break;
case V_80 :
strcpy ( V_148 -> V_243 , L_68 ) ;
break;
case V_79 :
F_84 ( V_1 -> V_77 , 8 , & V_17 ) ;
if ( V_17 < 5 ) {
strcpy ( V_148 -> V_243 , L_69 ) ;
} else {
strcpy ( V_148 -> V_243 , L_70 ) ;
}
break;
}
sprintf ( V_148 -> V_189 , L_71 , V_148 -> V_243 ,
V_1 -> V_104 , V_1 -> V_129 ) ;
if ( ( V_100 = F_130 ( V_148 ) ) < 0 ) {
F_129 ( V_148 ) ;
return V_100 ;
}
F_131 ( V_77 , V_148 ) ;
V_235 ++ ;
return 0 ;
}
static void F_132 ( struct V_167 * V_77 )
{
F_129 ( F_133 ( V_77 ) ) ;
}
