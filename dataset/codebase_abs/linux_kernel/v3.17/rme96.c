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
return F_8 ( V_1 -> V_2 + V_13 + V_11 , V_14 ,
V_12 ) ;
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
return F_10 ( V_15 , V_1 -> V_2 + V_16 + V_11 ,
V_12 ) ;
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
if ( V_120 & V_121 )
F_12 ( 0 , V_1 -> V_2 + V_122 ) ;
if ( V_120 & V_123 )
F_12 ( 0 , V_1 -> V_2 + V_124 ) ;
if ( V_120 & V_125 ) {
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_126 )
F_12 ( 0 , V_1 -> V_2 + V_127 ) ;
}
if ( V_120 & V_128 ) {
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_129 )
F_12 ( 0 , V_1 -> V_2 + V_130 ) ;
}
if ( V_120 & V_131 )
V_1 -> V_25 |= V_132 ;
if ( V_120 & V_133 )
V_1 -> V_25 &= ~ V_132 ;
if ( V_120 & V_134 )
V_1 -> V_25 |= V_135 ;
if ( V_120 & V_136 )
V_1 -> V_25 &= ~ V_135 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static T_5
F_45 ( int V_137 ,
void * V_138 )
{
struct V_1 * V_1 = (struct V_1 * ) V_138 ;
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( ! ( ( V_1 -> V_46 & V_126 ) ||
( V_1 -> V_46 & V_129 ) ) )
{
return V_139 ;
}
if ( V_1 -> V_46 & V_126 ) {
F_46 ( V_1 -> V_140 ) ;
F_12 ( 0 , V_1 -> V_2 + V_127 ) ;
}
if ( V_1 -> V_46 & V_129 ) {
F_46 ( V_1 -> V_141 ) ;
F_12 ( 0 , V_1 -> V_2 + V_130 ) ;
}
return V_142 ;
}
static void
F_47 ( struct V_1 * V_1 ,
struct V_98 * V_99 )
{
unsigned int V_143 ;
F_48 ( V_99 , V_144 ,
V_106 , V_106 ) ;
if ( ( V_143 = V_1 -> V_111 ) != 0 ||
( V_143 = V_1 -> V_109 ) != 0 )
F_48 ( V_99 ,
V_145 ,
V_143 , V_143 ) ;
else
F_49 ( V_99 , 0 ,
V_145 ,
& V_146 ) ;
}
static int
F_50 ( struct V_8 * V_9 )
{
int V_41 , V_53 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_51 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_140 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_25 &= ~ V_112 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
V_1 -> V_140 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
V_99 -> V_118 = V_147 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
V_99 -> V_118 . V_148 = F_52 ( V_41 ) ;
V_99 -> V_118 . V_149 = V_41 ;
V_99 -> V_118 . V_150 = V_41 ;
}
F_47 ( V_1 , V_99 ) ;
V_1 -> V_116 = V_1 -> V_151 ;
V_1 -> V_152 -> V_153 [ 0 ] . V_154 &= ~ V_155 ;
F_53 ( V_1 -> V_156 , V_157 |
V_158 , & V_1 -> V_152 -> V_159 ) ;
return 0 ;
}
static int
F_54 ( struct V_8 * V_9 )
{
int V_117 , V_41 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_51 ( V_9 ) ;
V_99 -> V_118 = V_160 ;
if ( F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_117 ) ) > 0 )
{
if ( V_117 ) {
return - V_108 ;
}
V_99 -> V_118 . V_148 = F_52 ( V_41 ) ;
V_99 -> V_118 . V_149 = V_41 ;
V_99 -> V_118 . V_150 = V_41 ;
}
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_141 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_141 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
F_47 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_55 ( struct V_8 * V_9 )
{
int V_41 , V_53 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_51 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_140 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_25 |= V_112 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
V_1 -> V_140 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
V_99 -> V_118 = V_161 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
V_99 -> V_118 . V_148 = F_52 ( V_41 ) ;
V_99 -> V_118 . V_149 = V_41 ;
V_99 -> V_118 . V_150 = V_41 ;
}
F_47 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_56 ( struct V_8 * V_9 )
{
int V_117 , V_41 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_51 ( V_9 ) ;
V_99 -> V_118 = V_162 ;
if ( F_24 ( V_1 ) == V_55 ) {
return - V_108 ;
}
if ( ( V_41 = F_22 ( V_1 , & V_117 ) ) > 0 ) {
if ( ! V_117 ) {
return - V_108 ;
}
V_99 -> V_118 . V_148 = F_52 ( V_41 ) ;
V_99 -> V_118 . V_149 = V_41 ;
V_99 -> V_118 . V_150 = V_41 ;
}
F_37 ( & V_1 -> V_107 ) ;
if ( V_1 -> V_141 != NULL ) {
F_39 ( & V_1 -> V_107 ) ;
return - V_110 ;
}
V_1 -> V_141 = V_9 ;
F_39 ( & V_1 -> V_107 ) ;
F_47 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_57 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
int V_163 = 0 ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_58 ( V_1 ) ) {
F_44 ( V_1 , V_164 ) ;
}
V_1 -> V_140 = NULL ;
V_1 -> V_111 = 0 ;
V_163 = ( V_1 -> V_25 & V_112 ) == 0 ;
F_39 ( & V_1 -> V_107 ) ;
if ( V_163 ) {
V_1 -> V_152 -> V_153 [ 0 ] . V_154 |= V_155 ;
F_53 ( V_1 -> V_156 , V_157 |
V_158 , & V_1 -> V_152 -> V_159 ) ;
}
return 0 ;
}
static int
F_59 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_60 ( V_1 ) ) {
F_44 ( V_1 , V_165 ) ;
}
V_1 -> V_141 = NULL ;
V_1 -> V_109 = 0 ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_61 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_58 ( V_1 ) ) {
F_44 ( V_1 , V_164 ) ;
}
F_12 ( 0 , V_1 -> V_2 + V_122 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_62 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_107 ) ;
if ( F_60 ( V_1 ) ) {
F_44 ( V_1 , V_165 ) ;
}
F_12 ( 0 , V_1 -> V_2 + V_124 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_63 ( struct V_8 * V_9 ,
int V_166 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_8 * V_167 ;
bool V_168 ;
F_64 (s, substream) {
if ( F_5 ( V_167 ) == V_1 )
F_65 ( V_167 , V_9 ) ;
}
V_168 = ( V_1 -> V_140 && V_1 -> V_141 ) &&
( V_1 -> V_140 -> V_169 ==
V_1 -> V_141 -> V_169 ) ;
switch ( V_166 ) {
case V_170 :
if ( ! F_58 ( V_1 ) ) {
if ( V_9 != V_1 -> V_140 )
return - V_110 ;
F_44 ( V_1 , V_168 ? V_171
: V_172 ) ;
}
break;
case V_173 :
case V_174 :
if ( F_58 ( V_1 ) ) {
if ( V_9 != V_1 -> V_140 )
return - V_110 ;
F_44 ( V_1 , V_168 ? V_175
: V_164 ) ;
}
break;
case V_176 :
if ( F_58 ( V_1 ) )
F_44 ( V_1 , V_168 ? V_175
: V_164 ) ;
break;
case V_177 :
case V_178 :
if ( ! F_58 ( V_1 ) )
F_44 ( V_1 , V_168 ? V_179
: V_180 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int
F_66 ( struct V_8 * V_9 ,
int V_166 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_8 * V_167 ;
bool V_168 ;
F_64 (s, substream) {
if ( F_5 ( V_167 ) == V_1 )
F_65 ( V_167 , V_9 ) ;
}
V_168 = ( V_1 -> V_140 && V_1 -> V_141 ) &&
( V_1 -> V_140 -> V_169 ==
V_1 -> V_141 -> V_169 ) ;
switch ( V_166 ) {
case V_170 :
if ( ! F_60 ( V_1 ) ) {
if ( V_9 != V_1 -> V_141 )
return - V_110 ;
F_44 ( V_1 , V_168 ? V_171
: V_181 ) ;
}
break;
case V_173 :
case V_174 :
if ( F_60 ( V_1 ) ) {
if ( V_9 != V_1 -> V_141 )
return - V_110 ;
F_44 ( V_1 , V_168 ? V_175
: V_165 ) ;
}
break;
case V_176 :
if ( F_60 ( V_1 ) )
F_44 ( V_1 , V_168 ? V_175
: V_165 ) ;
break;
case V_177 :
case V_178 :
if ( ! F_60 ( V_1 ) )
F_44 ( V_1 , V_168 ? V_179
: V_182 ) ;
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
F_69 ( void * V_183 )
{
struct V_1 * V_1 = (struct V_1 * ) V_183 ;
if ( V_1 == NULL ) {
return;
}
if ( V_1 -> V_137 >= 0 ) {
F_44 ( V_1 , V_175 ) ;
V_1 -> V_19 &= ~ V_184 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_70 ( V_1 -> V_137 , ( void * ) V_1 ) ;
V_1 -> V_137 = - 1 ;
}
if ( V_1 -> V_2 ) {
F_71 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
if ( V_1 -> V_104 ) {
F_72 ( V_1 -> V_77 ) ;
V_1 -> V_104 = 0 ;
}
#ifdef F_73
F_74 ( V_1 -> V_185 ) ;
F_74 ( V_1 -> V_186 ) ;
#endif
F_75 ( V_1 -> V_77 ) ;
}
static void
F_76 ( struct V_187 * V_188 )
{
struct V_1 * V_1 = V_188 -> V_183 ;
V_1 -> V_189 = NULL ;
}
static void
F_77 ( struct V_187 * V_188 )
{
struct V_1 * V_1 = V_188 -> V_183 ;
V_1 -> V_190 = NULL ;
}
static int
F_78 ( struct V_1 * V_1 )
{
struct V_191 * V_77 = V_1 -> V_77 ;
int V_100 ;
V_1 -> V_137 = - 1 ;
F_79 ( & V_1 -> V_107 ) ;
if ( ( V_100 = F_80 ( V_77 ) ) < 0 )
return V_100 ;
if ( ( V_100 = F_81 ( V_77 , L_1 ) ) < 0 )
return V_100 ;
V_1 -> V_104 = F_82 ( V_1 -> V_77 , 0 ) ;
V_1 -> V_2 = F_83 ( V_1 -> V_104 , V_192 ) ;
if ( ! V_1 -> V_2 ) {
F_84 ( V_1 -> V_156 -> V_193 ,
L_2 ,
V_1 -> V_104 , V_1 -> V_104 + V_192 - 1 ) ;
return - V_194 ;
}
if ( F_85 ( V_77 -> V_137 , F_45 , V_195 ,
V_196 , V_1 ) ) {
F_84 ( V_1 -> V_156 -> V_193 , L_3 , V_77 -> V_137 ) ;
return - V_110 ;
}
V_1 -> V_137 = V_77 -> V_137 ;
F_86 ( V_77 , 8 , & V_1 -> V_65 ) ;
if ( ( V_100 = F_87 ( V_1 -> V_156 , L_4 , 0 ,
1 , 1 , & V_1 -> V_189 ) ) < 0 )
{
return V_100 ;
}
V_1 -> V_189 -> V_183 = V_1 ;
V_1 -> V_189 -> V_197 = F_76 ;
strcpy ( V_1 -> V_189 -> V_198 , L_4 ) ;
F_88 ( V_1 -> V_189 , V_199 , & V_200 ) ;
F_88 ( V_1 -> V_189 , V_201 , & V_202 ) ;
V_1 -> V_189 -> V_203 = 0 ;
if ( V_77 -> V_78 == V_204 ) {
V_1 -> V_190 = NULL ;
} else {
if ( ( V_100 = F_87 ( V_1 -> V_156 , L_5 , 1 ,
1 , 1 , & V_1 -> V_190 ) ) < 0 )
{
return V_100 ;
}
V_1 -> V_190 -> V_183 = V_1 ;
V_1 -> V_190 -> V_197 = F_77 ;
strcpy ( V_1 -> V_190 -> V_198 , L_5 ) ;
F_88 ( V_1 -> V_190 , V_199 , & V_205 ) ;
F_88 ( V_1 -> V_190 , V_201 , & V_206 ) ;
V_1 -> V_190 -> V_203 = 0 ;
}
V_1 -> V_111 = 0 ;
V_1 -> V_109 = 0 ;
F_44 ( V_1 , V_175 ) ;
V_1 -> V_25 =
V_61 |
V_207 |
V_54 |
V_72 ;
V_1 -> V_19 = V_63 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 | V_208 ,
V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_17 ( V_1 ) ;
V_1 -> V_19 |= V_184 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_12 ( 0 , V_1 -> V_2 + V_122 ) ;
F_12 ( 0 , V_1 -> V_2 + V_124 ) ;
V_1 -> V_24 [ 0 ] = V_1 -> V_24 [ 1 ] = 0 ;
if ( F_89 ( V_1 ) ) {
F_14 ( V_1 ) ;
}
if ( ( V_100 = F_90 ( V_1 -> V_156 , V_1 ) ) < 0 ) {
return V_100 ;
}
F_91 ( V_1 ) ;
return 0 ;
}
static void
F_92 ( struct V_209 * V_210 , struct V_211 * V_212 )
{
int V_40 ;
struct V_1 * V_1 = V_210 -> V_183 ;
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
F_93 ( V_212 , V_1 -> V_156 -> V_213 ) ;
F_93 ( V_212 , L_6 , V_1 -> V_156 -> V_214 + 1 ) ;
F_93 ( V_212 , L_7 ) ;
if ( V_1 -> V_25 & V_95 ) {
F_93 ( V_212 , L_8
L_9 ) ;
} else if ( V_1 -> V_25 & V_93 ) {
F_93 ( V_212 , L_10 ) ;
} else {
F_93 ( V_212 , L_11 ) ;
}
F_93 ( V_212 , L_12 ) ;
switch ( F_24 ( V_1 ) ) {
case V_71 :
F_93 ( V_212 , L_13 ) ;
break;
case V_74 :
F_93 ( V_212 , L_14 ) ;
break;
case V_75 :
F_93 ( V_212 , L_15 ) ;
break;
case V_76 :
F_93 ( V_212 , L_16 ) ;
break;
case V_55 :
F_93 ( V_212 , L_17 ) ;
break;
}
if ( F_22 ( V_1 , & V_40 ) < 0 ) {
F_93 ( V_212 , L_18 ) ;
} else {
if ( V_40 ) {
F_93 ( V_212 , L_19 ) ;
} else {
F_93 ( V_212 , L_20 ) ;
}
F_93 ( V_212 , L_21 ,
F_22 ( V_1 , & V_40 ) ) ;
}
if ( V_1 -> V_25 & V_87 ) {
F_93 ( V_212 , L_22 ) ;
} else {
F_93 ( V_212 , L_23 ) ;
}
F_93 ( V_212 , L_24 ) ;
if ( V_1 -> V_25 & V_207 ) {
F_93 ( V_212 , L_25 ) ;
} else {
F_93 ( V_212 , L_26 ) ;
}
F_93 ( V_212 , L_21 ,
F_23 ( V_1 ) ) ;
if ( V_1 -> V_25 & V_86 ) {
F_93 ( V_212 , L_22 ) ;
} else {
F_93 ( V_212 , L_23 ) ;
}
if ( V_1 -> V_19 & V_68 ) {
F_93 ( V_212 , L_27 ) ;
} else if ( V_1 -> V_25 & V_54 ) {
F_93 ( V_212 , L_28 ) ;
} else if ( F_24 ( V_1 ) == V_55 ) {
F_93 ( V_212 , L_29 ) ;
} else if ( F_22 ( V_1 , & V_40 ) < 0 ) {
F_93 ( V_212 , L_30 ) ;
} else {
F_93 ( V_212 , L_31 ) ;
}
if ( V_1 -> V_25 & V_113 ) {
F_93 ( V_212 , L_32 ) ;
} else {
F_93 ( V_212 , L_33 ) ;
}
if ( V_1 -> V_25 & V_115 ) {
F_93 ( V_212 , L_34 ) ;
} else {
F_93 ( V_212 , L_35 ) ;
}
if ( V_1 -> V_25 & V_114 ) {
F_93 ( V_212 , L_36 ) ;
} else {
F_93 ( V_212 , L_37 ) ;
}
if ( F_30 ( V_1 ) ) {
F_93 ( V_212 , L_38 ) ;
switch ( F_18 ( V_1 ) ) {
case V_215 :
F_93 ( V_212 , L_39 ) ;
break;
case V_216 :
F_93 ( V_212 , L_40 ) ;
break;
case V_217 :
F_93 ( V_212 , L_41 ) ;
break;
case V_218 :
F_93 ( V_212 , L_42 ) ;
break;
}
switch ( F_20 ( V_1 ) ) {
case V_219 :
F_93 ( V_212 , L_43 ) ;
break;
case V_220 :
F_93 ( V_212 , L_44 ) ;
break;
case V_221 :
F_93 ( V_212 , L_45 ) ;
break;
case V_222 :
F_93 ( V_212 , L_46 ) ;
break;
}
F_93 ( V_212 , L_47 , V_1 -> V_24 [ 0 ] ) ;
F_93 ( V_212 , L_48 , V_1 -> V_24 [ 1 ] ) ;
}
}
static void F_91 ( struct V_1 * V_1 )
{
struct V_209 * V_210 ;
if ( ! F_94 ( V_1 -> V_156 , L_49 , & V_210 ) )
F_95 ( V_210 , V_1 , F_92 ) ;
}
static int
F_96 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_226 -> V_227 . integer . V_227 [ 0 ] = V_1 -> V_25 & V_207 ? 0 : 1 ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_98 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
unsigned int V_17 ;
int V_228 ;
V_17 = V_226 -> V_227 . integer . V_227 [ 0 ] ? 0 : V_207 ;
F_37 ( & V_1 -> V_107 ) ;
V_17 = ( V_1 -> V_25 & ~ V_207 ) | V_17 ;
V_228 = V_17 != V_1 -> V_25 ;
V_1 -> V_25 = V_17 ;
F_12 ( V_17 , V_1 -> V_2 + V_27 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int
F_99 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
static char * V_231 [ 5 ] = { L_50 , L_51 , L_52 , L_53 , L_54 } ;
struct V_1 * V_1 = F_97 ( V_224 ) ;
char * V_232 [ 5 ] = { V_231 [ 0 ] , V_231 [ 1 ] , V_231 [ 2 ] , V_231 [ 3 ] , V_231 [ 4 ] } ;
V_230 -> type = V_233 ;
V_230 -> V_12 = 1 ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_204 :
case V_234 :
V_230 -> V_227 . V_235 . V_236 = 3 ;
break;
case V_80 :
V_230 -> V_227 . V_235 . V_236 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
V_230 -> V_227 . V_235 . V_236 = 4 ;
V_232 [ 3 ] = V_231 [ 4 ] ;
} else {
V_230 -> V_227 . V_235 . V_236 = 5 ;
}
break;
default:
F_35 () ;
break;
}
if ( V_230 -> V_227 . V_235 . V_237 > V_230 -> V_227 . V_235 . V_236 - 1 ) {
V_230 -> V_227 . V_235 . V_237 = V_230 -> V_227 . V_235 . V_236 - 1 ;
}
strcpy ( V_230 -> V_227 . V_235 . V_198 , V_232 [ V_230 -> V_227 . V_235 . V_237 ] ) ;
return 0 ;
}
static int
F_100 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
unsigned int V_236 = 3 ;
F_37 ( & V_1 -> V_107 ) ;
V_226 -> V_227 . V_235 . V_237 [ 0 ] = F_24 ( V_1 ) ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_204 :
case V_234 :
V_236 = 3 ;
break;
case V_80 :
V_236 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
if ( V_226 -> V_227 . V_235 . V_237 [ 0 ] == V_55 ) {
V_226 -> V_227 . V_235 . V_237 [ 0 ] = V_76 ;
}
V_236 = 4 ;
} else {
V_236 = 5 ;
}
break;
default:
F_35 () ;
break;
}
if ( V_226 -> V_227 . V_235 . V_237 [ 0 ] >= V_236 ) {
V_226 -> V_227 . V_235 . V_237 [ 0 ] = V_236 - 1 ;
}
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_101 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
unsigned int V_17 ;
int V_228 , V_236 = 3 ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_204 :
case V_234 :
V_236 = 3 ;
break;
case V_80 :
V_236 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
V_236 = 4 ;
} else {
V_236 = 5 ;
}
break;
default:
F_35 () ;
break;
}
V_17 = V_226 -> V_227 . V_235 . V_237 [ 0 ] % V_236 ;
if ( V_1 -> V_77 -> V_78 == V_79 && V_1 -> V_65 > 4 ) {
if ( V_17 == V_76 ) {
V_17 = V_55 ;
}
}
F_37 ( & V_1 -> V_107 ) ;
V_228 = ( int ) V_17 != F_24 ( V_1 ) ;
F_29 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int
F_102 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
static char * V_232 [ 3 ] = { L_55 , L_52 , L_56 } ;
V_230 -> type = V_233 ;
V_230 -> V_12 = 1 ;
V_230 -> V_227 . V_235 . V_236 = 3 ;
if ( V_230 -> V_227 . V_235 . V_237 > 2 ) {
V_230 -> V_227 . V_235 . V_237 = 2 ;
}
strcpy ( V_230 -> V_227 . V_235 . V_198 , V_232 [ V_230 -> V_227 . V_235 . V_237 ] ) ;
return 0 ;
}
static int
F_103 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_226 -> V_227 . V_235 . V_237 [ 0 ] = F_28 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_104 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
unsigned int V_17 ;
int V_228 ;
V_17 = V_226 -> V_227 . V_235 . V_237 [ 0 ] % 3 ;
F_37 ( & V_1 -> V_107 ) ;
V_228 = ( int ) V_17 != F_28 ( V_1 ) ;
F_27 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int
F_105 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
static char * V_232 [ 4 ] = { L_57 , L_58 , L_59 , L_60 } ;
V_230 -> type = V_233 ;
V_230 -> V_12 = 1 ;
V_230 -> V_227 . V_235 . V_236 = 4 ;
if ( V_230 -> V_227 . V_235 . V_237 > 3 ) {
V_230 -> V_227 . V_235 . V_237 = 3 ;
}
strcpy ( V_230 -> V_227 . V_235 . V_198 , V_232 [ V_230 -> V_227 . V_235 . V_237 ] ) ;
return 0 ;
}
static int
F_106 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_226 -> V_227 . V_235 . V_237 [ 0 ] = F_20 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_107 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
unsigned int V_17 ;
int V_228 ;
V_17 = V_226 -> V_227 . V_235 . V_237 [ 0 ] % 4 ;
F_37 ( & V_1 -> V_107 ) ;
V_228 = ( int ) V_17 != F_20 ( V_1 ) ;
F_21 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int
F_108 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
static char * V_232 [ 4 ] = { L_61 , L_62 , L_63 , L_64 } ;
V_230 -> type = V_233 ;
V_230 -> V_12 = 1 ;
V_230 -> V_227 . V_235 . V_236 = 4 ;
if ( V_230 -> V_227 . V_235 . V_237 > 3 ) {
V_230 -> V_227 . V_235 . V_237 = 3 ;
}
strcpy ( V_230 -> V_227 . V_235 . V_198 , V_232 [ V_230 -> V_227 . V_235 . V_237 ] ) ;
return 0 ;
}
static int
F_109 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_226 -> V_227 . V_235 . V_237 [ 0 ] = F_18 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_110 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
unsigned int V_17 ;
int V_228 ;
V_17 = V_226 -> V_227 . V_235 . V_237 [ 0 ] % 4 ;
F_37 ( & V_1 -> V_107 ) ;
V_228 = ( int ) V_17 != F_18 ( V_1 ) ;
F_19 ( V_1 , V_17 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static T_6 F_111 ( struct V_238 * V_239 )
{
T_6 V_17 = 0 ;
V_17 |= ( V_239 -> V_240 [ 0 ] & V_241 ) ? V_113 : 0 ;
V_17 |= ( V_239 -> V_240 [ 0 ] & V_242 ) ? V_114 : 0 ;
if ( V_17 & V_113 )
V_17 |= ( V_239 -> V_240 [ 0 ] & V_243 ) ? V_115 : 0 ;
else
V_17 |= ( V_239 -> V_240 [ 0 ] & V_244 ) ? V_115 : 0 ;
return V_17 ;
}
static void F_112 ( struct V_238 * V_239 , T_6 V_17 )
{
V_239 -> V_240 [ 0 ] = ( ( V_17 & V_113 ) ? V_241 : 0 ) |
( ( V_17 & V_114 ) ? V_242 : 0 ) ;
if ( V_17 & V_113 )
V_239 -> V_240 [ 0 ] |= ( V_17 & V_115 ) ? V_243 : 0 ;
else
V_239 -> V_240 [ 0 ] |= ( V_17 & V_115 ) ? V_244 : 0 ;
}
static int F_113 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
V_230 -> type = V_245 ;
V_230 -> V_12 = 1 ;
return 0 ;
}
static int F_114 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_112 ( & V_226 -> V_227 . V_246 , V_1 -> V_151 ) ;
return 0 ;
}
static int F_115 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
int V_228 ;
T_6 V_17 ;
V_17 = F_111 ( & V_226 -> V_227 . V_246 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_228 = V_17 != V_1 -> V_151 ;
V_1 -> V_151 = V_17 ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int F_116 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
V_230 -> type = V_245 ;
V_230 -> V_12 = 1 ;
return 0 ;
}
static int F_117 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_112 ( & V_226 -> V_227 . V_246 , V_1 -> V_116 ) ;
return 0 ;
}
static int F_118 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
int V_228 ;
T_6 V_17 ;
V_17 = F_111 ( & V_226 -> V_227 . V_246 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_228 = V_17 != V_1 -> V_116 ;
V_1 -> V_116 = V_17 ;
V_1 -> V_25 &= ~ ( V_113 | V_114 | V_115 ) ;
V_1 -> V_25 |= V_17 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int F_119 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
V_230 -> type = V_245 ;
V_230 -> V_12 = 1 ;
return 0 ;
}
static int F_120 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
V_226 -> V_227 . V_246 . V_240 [ 0 ] = V_224 -> V_247 ;
return 0 ;
}
static int
F_121 ( struct V_223 * V_224 , struct V_229 * V_230 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
V_230 -> type = V_248 ;
V_230 -> V_12 = 2 ;
V_230 -> V_227 . integer . V_249 = 0 ;
V_230 -> V_227 . integer . V_250 = F_122 ( V_1 ) ;
return 0 ;
}
static int
F_123 ( struct V_223 * V_224 , struct V_225 * V_251 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_251 -> V_227 . integer . V_227 [ 0 ] = V_1 -> V_24 [ 0 ] ;
V_251 -> V_227 . integer . V_227 [ 1 ] = V_1 -> V_24 [ 1 ] ;
F_39 ( & V_1 -> V_107 ) ;
return 0 ;
}
static int
F_124 ( struct V_223 * V_224 , struct V_225 * V_251 )
{
struct V_1 * V_1 = F_97 ( V_224 ) ;
int V_228 = 0 ;
unsigned int V_24 , V_252 ;
if ( ! F_89 ( V_1 ) )
return - V_38 ;
V_252 = F_122 ( V_1 ) ;
F_37 ( & V_1 -> V_107 ) ;
V_24 = V_251 -> V_227 . integer . V_227 [ 0 ] ;
if ( V_24 != V_1 -> V_24 [ 0 ] && V_24 <= V_252 ) {
V_1 -> V_24 [ 0 ] = V_24 ;
V_228 = 1 ;
}
V_24 = V_251 -> V_227 . integer . V_227 [ 1 ] ;
if ( V_24 != V_1 -> V_24 [ 1 ] && V_24 <= V_252 ) {
V_1 -> V_24 [ 1 ] = V_24 ;
V_228 = 1 ;
}
if ( V_228 )
F_14 ( V_1 ) ;
F_39 ( & V_1 -> V_107 ) ;
return V_228 ;
}
static int
F_90 ( struct V_253 * V_156 ,
struct V_1 * V_1 )
{
int V_254 , V_100 ;
struct V_223 * V_255 ;
for ( V_254 = 0 ; V_254 < 7 ; V_254 ++ ) {
if ( ( V_100 = F_125 ( V_156 , V_255 = F_126 ( & V_256 [ V_254 ] , V_1 ) ) ) < 0 )
return V_100 ;
if ( V_254 == 1 )
V_1 -> V_152 = V_255 ;
}
if ( F_89 ( V_1 ) ) {
for ( V_254 = 7 ; V_254 < 10 ; V_254 ++ )
if ( ( V_100 = F_125 ( V_156 , F_126 ( & V_256 [ V_254 ] , V_1 ) ) ) < 0 )
return V_100 ;
}
return 0 ;
}
static int F_127 ( struct V_78 * V_193 )
{
struct V_191 * V_77 = F_128 ( V_193 ) ;
struct V_253 * V_156 = F_129 ( V_193 ) ;
struct V_1 * V_1 = V_156 -> V_183 ;
F_130 ( V_156 , V_257 ) ;
F_131 ( V_1 -> V_140 ) ;
F_131 ( V_1 -> V_141 ) ;
V_1 -> V_258 = F_2 ( V_1 -> V_2 + V_3 )
& V_4 ;
V_1 -> V_259 = F_2 ( V_1 -> V_2 + V_6 )
& V_4 ;
F_132 ( V_1 -> V_185 ,
V_1 -> V_2 + V_13 , V_106 ) ;
F_132 ( V_1 -> V_186 ,
V_1 -> V_2 + V_16 , V_106 ) ;
V_1 -> V_19 &= ~ V_184 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_75 ( V_77 ) ;
F_133 ( V_77 ) ;
return 0 ;
}
static int F_134 ( struct V_78 * V_193 )
{
struct V_191 * V_77 = F_128 ( V_193 ) ;
struct V_253 * V_156 = F_129 ( V_193 ) ;
struct V_1 * V_1 = V_156 -> V_183 ;
F_135 ( V_77 ) ;
if ( F_80 ( V_77 ) < 0 ) {
F_84 ( V_193 , L_65 ) ;
F_136 ( V_156 ) ;
return - V_108 ;
}
F_12 ( 0 , V_1 -> V_2 + V_260
+ V_1 -> V_258 ) ;
F_12 ( 0 , V_1 -> V_2 + V_261
+ V_1 -> V_259 ) ;
F_137 ( V_1 -> V_2 + V_13 ,
V_1 -> V_185 , V_106 ) ;
F_137 ( V_1 -> V_2 + V_16 ,
V_1 -> V_186 , V_106 ) ;
F_12 ( V_1 -> V_19 | V_208 ,
V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_17 ( V_1 ) ;
V_1 -> V_19 |= V_184 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
if ( F_89 ( V_1 ) ) {
F_138 ( 3000 , 10000 ) ;
F_14 ( V_1 ) ;
}
F_130 ( V_156 , V_262 ) ;
return 0 ;
}
static void F_139 ( struct V_253 * V_156 )
{
F_69 ( V_156 -> V_183 ) ;
}
static int
F_140 ( struct V_191 * V_77 ,
const struct V_263 * V_264 )
{
static int V_193 ;
struct V_1 * V_1 ;
struct V_253 * V_156 ;
int V_100 ;
T_7 V_17 ;
if ( V_193 >= V_265 ) {
return - V_266 ;
}
if ( ! V_267 [ V_193 ] ) {
V_193 ++ ;
return - V_268 ;
}
V_100 = F_141 ( & V_77 -> V_193 , V_269 [ V_193 ] , V_159 [ V_193 ] , V_270 ,
sizeof( struct V_1 ) , & V_156 ) ;
if ( V_100 < 0 )
return V_100 ;
V_156 -> V_197 = F_139 ;
V_1 = V_156 -> V_183 ;
V_1 -> V_156 = V_156 ;
V_1 -> V_77 = V_77 ;
if ( ( V_100 = F_78 ( V_1 ) ) < 0 ) {
F_142 ( V_156 ) ;
return V_100 ;
}
#ifdef F_73
V_1 -> V_185 = F_143 ( V_106 ) ;
if ( ! V_1 -> V_185 ) {
F_84 ( V_156 -> V_193 ,
L_66 ) ;
F_142 ( V_156 ) ;
return - V_194 ;
}
V_1 -> V_186 = F_143 ( V_106 ) ;
if ( ! V_1 -> V_186 ) {
F_84 ( V_156 -> V_193 ,
L_67 ) ;
F_142 ( V_156 ) ;
return - V_194 ;
}
#endif
strcpy ( V_156 -> V_271 , L_68 ) ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_204 :
strcpy ( V_156 -> V_272 , L_69 ) ;
break;
case V_234 :
strcpy ( V_156 -> V_272 , L_70 ) ;
break;
case V_80 :
strcpy ( V_156 -> V_272 , L_71 ) ;
break;
case V_79 :
F_86 ( V_1 -> V_77 , 8 , & V_17 ) ;
if ( V_17 < 5 ) {
strcpy ( V_156 -> V_272 , L_72 ) ;
} else {
strcpy ( V_156 -> V_272 , L_73 ) ;
}
break;
}
sprintf ( V_156 -> V_213 , L_74 , V_156 -> V_272 ,
V_1 -> V_104 , V_1 -> V_137 ) ;
if ( ( V_100 = F_144 ( V_156 ) ) < 0 ) {
F_142 ( V_156 ) ;
return V_100 ;
}
F_145 ( V_77 , V_156 ) ;
V_193 ++ ;
return 0 ;
}
static void F_146 ( struct V_191 * V_77 )
{
F_142 ( F_147 ( V_77 ) ) ;
}
