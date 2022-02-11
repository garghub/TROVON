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
return 1 ;
} else {
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
return 0 ;
}
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
F_32 ( struct V_1 * V_1 , T_4 V_88 )
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
F_33 ( struct V_1 * V_1 , T_4 V_88 )
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
T_5 V_91 )
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
bool V_101 = false ;
V_99 -> V_102 = ( void V_103 * ) ( V_1 -> V_2 +
V_13 ) ;
V_99 -> V_104 = V_1 -> V_105 + V_13 ;
V_99 -> V_106 = V_107 ;
F_37 ( & V_1 -> V_108 ) ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
if ( ( int ) F_38 ( V_97 ) != V_41 ) {
V_100 = - V_109 ;
goto error;
}
} else {
V_100 = F_25 ( V_1 , F_38 ( V_97 ) ) ;
if ( V_100 < 0 )
goto error;
V_101 = V_100 > 0 ;
}
V_100 = F_32 ( V_1 , F_39 ( V_97 ) ) ;
if ( V_100 < 0 )
goto error;
F_31 ( V_1 , F_40 ( V_97 ) , 1 ) ;
if ( V_1 -> V_110 != 0 ) {
if ( F_41 ( V_97 ) << V_1 -> V_5 !=
V_1 -> V_110 )
{
V_100 = - V_111 ;
goto error;
}
}
V_1 -> V_112 =
F_41 ( V_97 ) << V_1 -> V_5 ;
F_34 ( V_1 , V_1 -> V_112 ) ;
if ( ( V_1 -> V_25 & V_113 ) == 0 ) {
V_1 -> V_25 &= ~ ( V_114 | V_115 | V_116 ) ;
F_12 ( V_1 -> V_25 |= V_1 -> V_117 , V_1 -> V_2 + V_27 ) ;
}
V_100 = 0 ;
error:
F_42 ( & V_1 -> V_108 ) ;
if ( V_101 ) {
F_43 ( 3000 , 10000 ) ;
F_14 ( V_1 ) ;
}
return V_100 ;
}
static int
F_44 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
int V_100 , V_118 , V_41 ;
V_99 -> V_102 = ( void V_103 * ) ( V_1 -> V_2 +
V_16 ) ;
V_99 -> V_104 = V_1 -> V_105 + V_16 ;
V_99 -> V_106 = V_107 ;
F_37 ( & V_1 -> V_108 ) ;
if ( ( V_100 = F_33 ( V_1 , F_39 ( V_97 ) ) ) < 0 ) {
F_42 ( & V_1 -> V_108 ) ;
return V_100 ;
}
if ( F_24 ( V_1 ) == V_55 ) {
if ( ( V_100 = F_26 ( V_1 ,
F_38 ( V_97 ) ) ) < 0 )
{
F_42 ( & V_1 -> V_108 ) ;
return V_100 ;
}
} else if ( ( V_41 = F_22 ( V_1 , & V_118 ) ) > 0 ) {
if ( ( int ) F_38 ( V_97 ) != V_41 ) {
F_42 ( & V_1 -> V_108 ) ;
return - V_109 ;
}
if ( ( V_118 && V_99 -> V_119 . V_120 == 2 ) ||
( ! V_118 && V_99 -> V_119 . V_120 == 8 ) )
{
F_42 ( & V_1 -> V_108 ) ;
return - V_109 ;
}
}
F_31 ( V_1 , F_40 ( V_97 ) , 0 ) ;
if ( V_1 -> V_112 != 0 ) {
if ( F_41 ( V_97 ) << V_1 -> V_7 !=
V_1 -> V_112 )
{
F_42 ( & V_1 -> V_108 ) ;
return - V_111 ;
}
}
V_1 -> V_110 =
F_41 ( V_97 ) << V_1 -> V_7 ;
F_34 ( V_1 , V_1 -> V_110 ) ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static void
F_45 ( struct V_1 * V_1 ,
int V_121 )
{
if ( V_121 & V_122 )
F_12 ( 0 , V_1 -> V_2 + V_123 ) ;
if ( V_121 & V_124 )
F_12 ( 0 , V_1 -> V_2 + V_125 ) ;
if ( V_121 & V_126 ) {
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_127 )
F_12 ( 0 , V_1 -> V_2 + V_128 ) ;
}
if ( V_121 & V_129 ) {
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( V_1 -> V_46 & V_130 )
F_12 ( 0 , V_1 -> V_2 + V_131 ) ;
}
if ( V_121 & V_132 )
V_1 -> V_25 |= V_133 ;
if ( V_121 & V_134 )
V_1 -> V_25 &= ~ V_133 ;
if ( V_121 & V_135 )
V_1 -> V_25 |= V_136 ;
if ( V_121 & V_137 )
V_1 -> V_25 &= ~ V_136 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
}
static T_6
F_46 ( int V_138 ,
void * V_139 )
{
struct V_1 * V_1 = (struct V_1 * ) V_139 ;
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
if ( ! ( ( V_1 -> V_46 & V_127 ) ||
( V_1 -> V_46 & V_130 ) ) )
{
return V_140 ;
}
if ( V_1 -> V_46 & V_127 ) {
F_47 ( V_1 -> V_141 ) ;
F_12 ( 0 , V_1 -> V_2 + V_128 ) ;
}
if ( V_1 -> V_46 & V_130 ) {
F_47 ( V_1 -> V_142 ) ;
F_12 ( 0 , V_1 -> V_2 + V_131 ) ;
}
return V_143 ;
}
static void
F_48 ( struct V_1 * V_1 ,
struct V_98 * V_99 )
{
unsigned int V_144 ;
F_49 ( V_99 , V_145 ,
V_107 ) ;
if ( ( V_144 = V_1 -> V_112 ) != 0 ||
( V_144 = V_1 -> V_110 ) != 0 )
F_49 ( V_99 ,
V_146 ,
V_144 ) ;
else
F_50 ( V_99 , 0 ,
V_146 ,
& V_147 ) ;
}
static int
F_51 ( struct V_8 * V_9 )
{
int V_41 , V_53 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_52 ( V_9 ) ;
F_37 ( & V_1 -> V_108 ) ;
if ( V_1 -> V_141 != NULL ) {
F_42 ( & V_1 -> V_108 ) ;
return - V_111 ;
}
V_1 -> V_25 &= ~ V_113 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
V_1 -> V_141 = V_9 ;
F_42 ( & V_1 -> V_108 ) ;
V_99 -> V_119 = V_148 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
V_99 -> V_119 . V_149 = F_53 ( V_41 ) ;
V_99 -> V_119 . V_150 = V_41 ;
V_99 -> V_119 . V_151 = V_41 ;
}
F_48 ( V_1 , V_99 ) ;
V_1 -> V_117 = V_1 -> V_152 ;
V_1 -> V_153 -> V_154 [ 0 ] . V_155 &= ~ V_156 ;
F_54 ( V_1 -> V_157 , V_158 |
V_159 , & V_1 -> V_153 -> V_160 ) ;
return 0 ;
}
static int
F_55 ( struct V_8 * V_9 )
{
int V_118 , V_41 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_52 ( V_9 ) ;
V_99 -> V_119 = V_161 ;
if ( F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_118 ) ) > 0 )
{
if ( V_118 ) {
return - V_109 ;
}
V_99 -> V_119 . V_149 = F_53 ( V_41 ) ;
V_99 -> V_119 . V_150 = V_41 ;
V_99 -> V_119 . V_151 = V_41 ;
}
F_37 ( & V_1 -> V_108 ) ;
if ( V_1 -> V_142 != NULL ) {
F_42 ( & V_1 -> V_108 ) ;
return - V_111 ;
}
V_1 -> V_142 = V_9 ;
F_42 ( & V_1 -> V_108 ) ;
F_48 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_56 ( struct V_8 * V_9 )
{
int V_41 , V_53 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_52 ( V_9 ) ;
F_37 ( & V_1 -> V_108 ) ;
if ( V_1 -> V_141 != NULL ) {
F_42 ( & V_1 -> V_108 ) ;
return - V_111 ;
}
V_1 -> V_25 |= V_113 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
V_1 -> V_141 = V_9 ;
F_42 ( & V_1 -> V_108 ) ;
V_99 -> V_119 = V_162 ;
if ( ! ( V_1 -> V_25 & V_54 ) &&
F_24 ( V_1 ) != V_55 &&
( V_41 = F_22 ( V_1 , & V_53 ) ) > 0 )
{
V_99 -> V_119 . V_149 = F_53 ( V_41 ) ;
V_99 -> V_119 . V_150 = V_41 ;
V_99 -> V_119 . V_151 = V_41 ;
}
F_48 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_57 ( struct V_8 * V_9 )
{
int V_118 , V_41 ;
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_98 * V_99 = V_9 -> V_99 ;
F_52 ( V_9 ) ;
V_99 -> V_119 = V_163 ;
if ( F_24 ( V_1 ) == V_55 ) {
return - V_109 ;
}
if ( ( V_41 = F_22 ( V_1 , & V_118 ) ) > 0 ) {
if ( ! V_118 ) {
return - V_109 ;
}
V_99 -> V_119 . V_149 = F_53 ( V_41 ) ;
V_99 -> V_119 . V_150 = V_41 ;
V_99 -> V_119 . V_151 = V_41 ;
}
F_37 ( & V_1 -> V_108 ) ;
if ( V_1 -> V_142 != NULL ) {
F_42 ( & V_1 -> V_108 ) ;
return - V_111 ;
}
V_1 -> V_142 = V_9 ;
F_42 ( & V_1 -> V_108 ) ;
F_48 ( V_1 , V_99 ) ;
return 0 ;
}
static int
F_58 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
int V_164 = 0 ;
F_37 ( & V_1 -> V_108 ) ;
if ( F_59 ( V_1 ) ) {
F_45 ( V_1 , V_165 ) ;
}
V_1 -> V_141 = NULL ;
V_1 -> V_112 = 0 ;
V_164 = ( V_1 -> V_25 & V_113 ) == 0 ;
F_42 ( & V_1 -> V_108 ) ;
if ( V_164 ) {
V_1 -> V_153 -> V_154 [ 0 ] . V_155 |= V_156 ;
F_54 ( V_1 -> V_157 , V_158 |
V_159 , & V_1 -> V_153 -> V_160 ) ;
}
return 0 ;
}
static int
F_60 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_108 ) ;
if ( F_61 ( V_1 ) ) {
F_45 ( V_1 , V_166 ) ;
}
V_1 -> V_142 = NULL ;
V_1 -> V_110 = 0 ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_62 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_108 ) ;
if ( F_59 ( V_1 ) ) {
F_45 ( V_1 , V_165 ) ;
}
F_12 ( 0 , V_1 -> V_2 + V_123 ) ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_63 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_37 ( & V_1 -> V_108 ) ;
if ( F_61 ( V_1 ) ) {
F_45 ( V_1 , V_166 ) ;
}
F_12 ( 0 , V_1 -> V_2 + V_125 ) ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_64 ( struct V_8 * V_9 ,
int V_167 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_8 * V_168 ;
bool V_169 ;
F_65 (s, substream) {
if ( F_5 ( V_168 ) == V_1 )
F_66 ( V_168 , V_9 ) ;
}
V_169 = ( V_1 -> V_141 && V_1 -> V_142 ) &&
( V_1 -> V_141 -> V_170 ==
V_1 -> V_142 -> V_170 ) ;
switch ( V_167 ) {
case V_171 :
if ( ! F_59 ( V_1 ) ) {
if ( V_9 != V_1 -> V_141 )
return - V_111 ;
F_45 ( V_1 , V_169 ? V_172
: V_173 ) ;
}
break;
case V_174 :
case V_175 :
if ( F_59 ( V_1 ) ) {
if ( V_9 != V_1 -> V_141 )
return - V_111 ;
F_45 ( V_1 , V_169 ? V_176
: V_165 ) ;
}
break;
case V_177 :
if ( F_59 ( V_1 ) )
F_45 ( V_1 , V_169 ? V_176
: V_165 ) ;
break;
case V_178 :
case V_179 :
if ( ! F_59 ( V_1 ) )
F_45 ( V_1 , V_169 ? V_180
: V_181 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int
F_67 ( struct V_8 * V_9 ,
int V_167 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_8 * V_168 ;
bool V_169 ;
F_65 (s, substream) {
if ( F_5 ( V_168 ) == V_1 )
F_66 ( V_168 , V_9 ) ;
}
V_169 = ( V_1 -> V_141 && V_1 -> V_142 ) &&
( V_1 -> V_141 -> V_170 ==
V_1 -> V_142 -> V_170 ) ;
switch ( V_167 ) {
case V_171 :
if ( ! F_61 ( V_1 ) ) {
if ( V_9 != V_1 -> V_142 )
return - V_111 ;
F_45 ( V_1 , V_169 ? V_172
: V_182 ) ;
}
break;
case V_174 :
case V_175 :
if ( F_61 ( V_1 ) ) {
if ( V_9 != V_1 -> V_142 )
return - V_111 ;
F_45 ( V_1 , V_169 ? V_176
: V_166 ) ;
}
break;
case V_177 :
if ( F_61 ( V_1 ) )
F_45 ( V_1 , V_169 ? V_176
: V_166 ) ;
break;
case V_178 :
case V_179 :
if ( ! F_61 ( V_1 ) )
F_45 ( V_1 , V_169 ? V_180
: V_183 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static T_1
F_68 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
return F_1 ( V_1 ) ;
}
static T_1
F_69 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
return F_3 ( V_1 ) ;
}
static void
F_70 ( void * V_184 )
{
struct V_1 * V_1 = (struct V_1 * ) V_184 ;
if ( V_1 == NULL ) {
return;
}
if ( V_1 -> V_138 >= 0 ) {
F_45 ( V_1 , V_176 ) ;
V_1 -> V_19 &= ~ V_185 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_71 ( V_1 -> V_138 , ( void * ) V_1 ) ;
V_1 -> V_138 = - 1 ;
}
if ( V_1 -> V_2 ) {
F_72 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
if ( V_1 -> V_105 ) {
F_73 ( V_1 -> V_77 ) ;
V_1 -> V_105 = 0 ;
}
#ifdef F_74
F_75 ( V_1 -> V_186 ) ;
F_75 ( V_1 -> V_187 ) ;
#endif
F_76 ( V_1 -> V_77 ) ;
}
static void
F_77 ( struct V_188 * V_189 )
{
struct V_1 * V_1 = V_189 -> V_184 ;
V_1 -> V_190 = NULL ;
}
static void
F_78 ( struct V_188 * V_189 )
{
struct V_1 * V_1 = V_189 -> V_184 ;
V_1 -> V_191 = NULL ;
}
static int
F_79 ( struct V_1 * V_1 )
{
struct V_192 * V_77 = V_1 -> V_77 ;
int V_100 ;
V_1 -> V_138 = - 1 ;
F_80 ( & V_1 -> V_108 ) ;
if ( ( V_100 = F_81 ( V_77 ) ) < 0 )
return V_100 ;
if ( ( V_100 = F_82 ( V_77 , L_1 ) ) < 0 )
return V_100 ;
V_1 -> V_105 = F_83 ( V_1 -> V_77 , 0 ) ;
V_1 -> V_2 = F_84 ( V_1 -> V_105 , V_193 ) ;
if ( ! V_1 -> V_2 ) {
F_85 ( V_1 -> V_157 -> V_194 ,
L_2 ,
V_1 -> V_105 , V_1 -> V_105 + V_193 - 1 ) ;
return - V_195 ;
}
if ( F_86 ( V_77 -> V_138 , F_46 , V_196 ,
V_197 , V_1 ) ) {
F_85 ( V_1 -> V_157 -> V_194 , L_3 , V_77 -> V_138 ) ;
return - V_111 ;
}
V_1 -> V_138 = V_77 -> V_138 ;
F_87 ( V_77 , 8 , & V_1 -> V_65 ) ;
if ( ( V_100 = F_88 ( V_1 -> V_157 , L_4 , 0 ,
1 , 1 , & V_1 -> V_190 ) ) < 0 )
{
return V_100 ;
}
V_1 -> V_190 -> V_184 = V_1 ;
V_1 -> V_190 -> V_198 = F_77 ;
strcpy ( V_1 -> V_190 -> V_199 , L_4 ) ;
F_89 ( V_1 -> V_190 , V_200 , & V_201 ) ;
F_89 ( V_1 -> V_190 , V_202 , & V_203 ) ;
V_1 -> V_190 -> V_204 = 0 ;
if ( V_77 -> V_78 == V_205 ) {
V_1 -> V_191 = NULL ;
} else {
if ( ( V_100 = F_88 ( V_1 -> V_157 , L_5 , 1 ,
1 , 1 , & V_1 -> V_191 ) ) < 0 )
{
return V_100 ;
}
V_1 -> V_191 -> V_184 = V_1 ;
V_1 -> V_191 -> V_198 = F_78 ;
strcpy ( V_1 -> V_191 -> V_199 , L_5 ) ;
F_89 ( V_1 -> V_191 , V_200 , & V_206 ) ;
F_89 ( V_1 -> V_191 , V_202 , & V_207 ) ;
V_1 -> V_191 -> V_204 = 0 ;
}
V_1 -> V_112 = 0 ;
V_1 -> V_110 = 0 ;
F_45 ( V_1 , V_176 ) ;
V_1 -> V_25 =
V_61 |
V_208 |
V_54 |
V_72 ;
V_1 -> V_19 = V_63 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 | V_209 ,
V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_17 ( V_1 ) ;
V_1 -> V_19 |= V_185 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_12 ( 0 , V_1 -> V_2 + V_123 ) ;
F_12 ( 0 , V_1 -> V_2 + V_125 ) ;
V_1 -> V_24 [ 0 ] = V_1 -> V_24 [ 1 ] = 0 ;
if ( F_90 ( V_1 ) ) {
F_14 ( V_1 ) ;
}
if ( ( V_100 = F_91 ( V_1 -> V_157 , V_1 ) ) < 0 ) {
return V_100 ;
}
F_92 ( V_1 ) ;
return 0 ;
}
static void
F_93 ( struct V_210 * V_211 , struct V_212 * V_213 )
{
int V_40 ;
struct V_1 * V_1 = V_211 -> V_184 ;
V_1 -> V_46 = F_2 ( V_1 -> V_2 + V_27 ) ;
F_94 ( V_213 , V_1 -> V_157 -> V_214 ) ;
F_94 ( V_213 , L_6 , V_1 -> V_157 -> V_215 + 1 ) ;
F_94 ( V_213 , L_7 ) ;
if ( V_1 -> V_25 & V_95 ) {
F_94 ( V_213 , L_8
L_9 ) ;
} else if ( V_1 -> V_25 & V_93 ) {
F_94 ( V_213 , L_10 ) ;
} else {
F_94 ( V_213 , L_11 ) ;
}
F_94 ( V_213 , L_12 ) ;
switch ( F_24 ( V_1 ) ) {
case V_71 :
F_94 ( V_213 , L_13 ) ;
break;
case V_74 :
F_94 ( V_213 , L_14 ) ;
break;
case V_75 :
F_94 ( V_213 , L_15 ) ;
break;
case V_76 :
F_94 ( V_213 , L_16 ) ;
break;
case V_55 :
F_94 ( V_213 , L_17 ) ;
break;
}
if ( F_22 ( V_1 , & V_40 ) < 0 ) {
F_94 ( V_213 , L_18 ) ;
} else {
if ( V_40 ) {
F_94 ( V_213 , L_19 ) ;
} else {
F_94 ( V_213 , L_20 ) ;
}
F_94 ( V_213 , L_21 ,
F_22 ( V_1 , & V_40 ) ) ;
}
if ( V_1 -> V_25 & V_87 ) {
F_94 ( V_213 , L_22 ) ;
} else {
F_94 ( V_213 , L_23 ) ;
}
F_94 ( V_213 , L_24 ) ;
if ( V_1 -> V_25 & V_208 ) {
F_94 ( V_213 , L_25 ) ;
} else {
F_94 ( V_213 , L_26 ) ;
}
F_94 ( V_213 , L_21 ,
F_23 ( V_1 ) ) ;
if ( V_1 -> V_25 & V_86 ) {
F_94 ( V_213 , L_22 ) ;
} else {
F_94 ( V_213 , L_23 ) ;
}
if ( V_1 -> V_19 & V_68 ) {
F_94 ( V_213 , L_27 ) ;
} else if ( V_1 -> V_25 & V_54 ) {
F_94 ( V_213 , L_28 ) ;
} else if ( F_24 ( V_1 ) == V_55 ) {
F_94 ( V_213 , L_29 ) ;
} else if ( F_22 ( V_1 , & V_40 ) < 0 ) {
F_94 ( V_213 , L_30 ) ;
} else {
F_94 ( V_213 , L_31 ) ;
}
if ( V_1 -> V_25 & V_114 ) {
F_94 ( V_213 , L_32 ) ;
} else {
F_94 ( V_213 , L_33 ) ;
}
if ( V_1 -> V_25 & V_116 ) {
F_94 ( V_213 , L_34 ) ;
} else {
F_94 ( V_213 , L_35 ) ;
}
if ( V_1 -> V_25 & V_115 ) {
F_94 ( V_213 , L_36 ) ;
} else {
F_94 ( V_213 , L_37 ) ;
}
if ( F_30 ( V_1 ) ) {
F_94 ( V_213 , L_38 ) ;
switch ( F_18 ( V_1 ) ) {
case V_216 :
F_94 ( V_213 , L_39 ) ;
break;
case V_217 :
F_94 ( V_213 , L_40 ) ;
break;
case V_218 :
F_94 ( V_213 , L_41 ) ;
break;
case V_219 :
F_94 ( V_213 , L_42 ) ;
break;
}
switch ( F_20 ( V_1 ) ) {
case V_220 :
F_94 ( V_213 , L_43 ) ;
break;
case V_221 :
F_94 ( V_213 , L_44 ) ;
break;
case V_222 :
F_94 ( V_213 , L_45 ) ;
break;
case V_223 :
F_94 ( V_213 , L_46 ) ;
break;
}
F_94 ( V_213 , L_47 , V_1 -> V_24 [ 0 ] ) ;
F_94 ( V_213 , L_48 , V_1 -> V_24 [ 1 ] ) ;
}
}
static void F_92 ( struct V_1 * V_1 )
{
struct V_210 * V_211 ;
if ( ! F_95 ( V_1 -> V_157 , L_49 , & V_211 ) )
F_96 ( V_211 , V_1 , F_93 ) ;
}
static int
F_97 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_227 -> V_228 . integer . V_228 [ 0 ] = V_1 -> V_25 & V_208 ? 0 : 1 ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_99 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
unsigned int V_17 ;
int V_229 ;
V_17 = V_227 -> V_228 . integer . V_228 [ 0 ] ? 0 : V_208 ;
F_37 ( & V_1 -> V_108 ) ;
V_17 = ( V_1 -> V_25 & ~ V_208 ) | V_17 ;
V_229 = V_17 != V_1 -> V_25 ;
V_1 -> V_25 = V_17 ;
F_12 ( V_17 , V_1 -> V_2 + V_27 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int
F_100 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
static const char * const V_232 [ 5 ] = {
L_50 , L_51 , L_52 , L_53 , L_54
} ;
struct V_1 * V_1 = F_98 ( V_225 ) ;
const char * V_233 [ 5 ] = {
V_232 [ 0 ] , V_232 [ 1 ] , V_232 [ 2 ] , V_232 [ 3 ] , V_232 [ 4 ]
} ;
int V_234 ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_205 :
case V_235 :
V_234 = 3 ;
break;
case V_80 :
V_234 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
V_234 = 4 ;
V_233 [ 3 ] = V_232 [ 4 ] ;
} else {
V_234 = 5 ;
}
break;
default:
F_35 () ;
return - V_38 ;
}
return F_101 ( V_231 , 1 , V_234 , V_233 ) ;
}
static int
F_102 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
unsigned int V_236 = 3 ;
F_37 ( & V_1 -> V_108 ) ;
V_227 -> V_228 . V_237 . V_238 [ 0 ] = F_24 ( V_1 ) ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_205 :
case V_235 :
V_236 = 3 ;
break;
case V_80 :
V_236 = 4 ;
break;
case V_79 :
if ( V_1 -> V_65 > 4 ) {
if ( V_227 -> V_228 . V_237 . V_238 [ 0 ] == V_55 ) {
V_227 -> V_228 . V_237 . V_238 [ 0 ] = V_76 ;
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
if ( V_227 -> V_228 . V_237 . V_238 [ 0 ] >= V_236 ) {
V_227 -> V_228 . V_237 . V_238 [ 0 ] = V_236 - 1 ;
}
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_103 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
unsigned int V_17 ;
int V_229 , V_236 = 3 ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_205 :
case V_235 :
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
V_17 = V_227 -> V_228 . V_237 . V_238 [ 0 ] % V_236 ;
if ( V_1 -> V_77 -> V_78 == V_79 && V_1 -> V_65 > 4 ) {
if ( V_17 == V_76 ) {
V_17 = V_55 ;
}
}
F_37 ( & V_1 -> V_108 ) ;
V_229 = ( int ) V_17 != F_24 ( V_1 ) ;
F_29 ( V_1 , V_17 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int
F_104 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
static const char * const V_233 [ 3 ] = { L_55 , L_52 , L_56 } ;
return F_101 ( V_231 , 1 , 3 , V_233 ) ;
}
static int
F_105 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_227 -> V_228 . V_237 . V_238 [ 0 ] = F_28 ( V_1 ) ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_106 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
unsigned int V_17 ;
int V_229 ;
V_17 = V_227 -> V_228 . V_237 . V_238 [ 0 ] % 3 ;
F_37 ( & V_1 -> V_108 ) ;
V_229 = ( int ) V_17 != F_28 ( V_1 ) ;
F_27 ( V_1 , V_17 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int
F_107 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
static const char * const V_233 [ 4 ] = {
L_57 , L_58 , L_59 , L_60
} ;
return F_101 ( V_231 , 1 , 4 , V_233 ) ;
}
static int
F_108 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_227 -> V_228 . V_237 . V_238 [ 0 ] = F_20 ( V_1 ) ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_109 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
unsigned int V_17 ;
int V_229 ;
V_17 = V_227 -> V_228 . V_237 . V_238 [ 0 ] % 4 ;
F_37 ( & V_1 -> V_108 ) ;
V_229 = ( int ) V_17 != F_20 ( V_1 ) ;
F_21 ( V_1 , V_17 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int
F_110 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
static const char * const V_233 [ 4 ] = { L_61 , L_62 , L_63 , L_64 } ;
return F_101 ( V_231 , 1 , 4 , V_233 ) ;
}
static int
F_111 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_227 -> V_228 . V_237 . V_238 [ 0 ] = F_18 ( V_1 ) ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_112 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
unsigned int V_17 ;
int V_229 ;
V_17 = V_227 -> V_228 . V_237 . V_238 [ 0 ] % 4 ;
F_37 ( & V_1 -> V_108 ) ;
V_229 = ( int ) V_17 != F_18 ( V_1 ) ;
F_19 ( V_1 , V_17 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static T_7 F_113 ( struct V_239 * V_240 )
{
T_7 V_17 = 0 ;
V_17 |= ( V_240 -> V_241 [ 0 ] & V_242 ) ? V_114 : 0 ;
V_17 |= ( V_240 -> V_241 [ 0 ] & V_243 ) ? V_115 : 0 ;
if ( V_17 & V_114 )
V_17 |= ( V_240 -> V_241 [ 0 ] & V_244 ) ? V_116 : 0 ;
else
V_17 |= ( V_240 -> V_241 [ 0 ] & V_245 ) ? V_116 : 0 ;
return V_17 ;
}
static void F_114 ( struct V_239 * V_240 , T_7 V_17 )
{
V_240 -> V_241 [ 0 ] = ( ( V_17 & V_114 ) ? V_242 : 0 ) |
( ( V_17 & V_115 ) ? V_243 : 0 ) ;
if ( V_17 & V_114 )
V_240 -> V_241 [ 0 ] |= ( V_17 & V_116 ) ? V_244 : 0 ;
else
V_240 -> V_241 [ 0 ] |= ( V_17 & V_116 ) ? V_245 : 0 ;
}
static int F_115 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
V_231 -> type = V_246 ;
V_231 -> V_12 = 1 ;
return 0 ;
}
static int F_116 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_114 ( & V_227 -> V_228 . V_247 , V_1 -> V_152 ) ;
return 0 ;
}
static int F_117 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
int V_229 ;
T_7 V_17 ;
V_17 = F_113 ( & V_227 -> V_228 . V_247 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_229 = V_17 != V_1 -> V_152 ;
V_1 -> V_152 = V_17 ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int F_118 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
V_231 -> type = V_246 ;
V_231 -> V_12 = 1 ;
return 0 ;
}
static int F_119 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_114 ( & V_227 -> V_228 . V_247 , V_1 -> V_117 ) ;
return 0 ;
}
static int F_120 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
int V_229 ;
T_7 V_17 ;
V_17 = F_113 ( & V_227 -> V_228 . V_247 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_229 = V_17 != V_1 -> V_117 ;
V_1 -> V_117 = V_17 ;
V_1 -> V_25 &= ~ ( V_114 | V_115 | V_116 ) ;
V_1 -> V_25 |= V_17 ;
F_12 ( V_1 -> V_25 , V_1 -> V_2 + V_27 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int F_121 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
V_231 -> type = V_246 ;
V_231 -> V_12 = 1 ;
return 0 ;
}
static int F_122 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
V_227 -> V_228 . V_247 . V_241 [ 0 ] = V_225 -> V_248 ;
return 0 ;
}
static int
F_123 ( struct V_224 * V_225 , struct V_230 * V_231 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
V_231 -> type = V_249 ;
V_231 -> V_12 = 2 ;
V_231 -> V_228 . integer . V_250 = 0 ;
V_231 -> V_228 . integer . V_251 = F_124 ( V_1 ) ;
return 0 ;
}
static int
F_125 ( struct V_224 * V_225 , struct V_226 * V_252 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_252 -> V_228 . integer . V_228 [ 0 ] = V_1 -> V_24 [ 0 ] ;
V_252 -> V_228 . integer . V_228 [ 1 ] = V_1 -> V_24 [ 1 ] ;
F_42 ( & V_1 -> V_108 ) ;
return 0 ;
}
static int
F_126 ( struct V_224 * V_225 , struct V_226 * V_252 )
{
struct V_1 * V_1 = F_98 ( V_225 ) ;
int V_229 = 0 ;
unsigned int V_24 , V_253 ;
if ( ! F_90 ( V_1 ) )
return - V_38 ;
V_253 = F_124 ( V_1 ) ;
F_37 ( & V_1 -> V_108 ) ;
V_24 = V_252 -> V_228 . integer . V_228 [ 0 ] ;
if ( V_24 != V_1 -> V_24 [ 0 ] && V_24 <= V_253 ) {
V_1 -> V_24 [ 0 ] = V_24 ;
V_229 = 1 ;
}
V_24 = V_252 -> V_228 . integer . V_228 [ 1 ] ;
if ( V_24 != V_1 -> V_24 [ 1 ] && V_24 <= V_253 ) {
V_1 -> V_24 [ 1 ] = V_24 ;
V_229 = 1 ;
}
if ( V_229 )
F_14 ( V_1 ) ;
F_42 ( & V_1 -> V_108 ) ;
return V_229 ;
}
static int
F_91 ( struct V_254 * V_157 ,
struct V_1 * V_1 )
{
int V_255 , V_100 ;
struct V_224 * V_256 ;
for ( V_255 = 0 ; V_255 < 7 ; V_255 ++ ) {
if ( ( V_100 = F_127 ( V_157 , V_256 = F_128 ( & V_257 [ V_255 ] , V_1 ) ) ) < 0 )
return V_100 ;
if ( V_255 == 1 )
V_1 -> V_153 = V_256 ;
}
if ( F_90 ( V_1 ) ) {
for ( V_255 = 7 ; V_255 < 10 ; V_255 ++ )
if ( ( V_100 = F_127 ( V_157 , F_128 ( & V_257 [ V_255 ] , V_1 ) ) ) < 0 )
return V_100 ;
}
return 0 ;
}
static int F_129 ( struct V_78 * V_194 )
{
struct V_254 * V_157 = F_130 ( V_194 ) ;
struct V_1 * V_1 = V_157 -> V_184 ;
F_131 ( V_157 , V_258 ) ;
F_132 ( V_1 -> V_141 ) ;
F_132 ( V_1 -> V_142 ) ;
V_1 -> V_259 = F_2 ( V_1 -> V_2 + V_3 )
& V_4 ;
V_1 -> V_260 = F_2 ( V_1 -> V_2 + V_6 )
& V_4 ;
F_133 ( V_1 -> V_186 ,
V_1 -> V_2 + V_13 , V_107 ) ;
F_133 ( V_1 -> V_187 ,
V_1 -> V_2 + V_16 , V_107 ) ;
V_1 -> V_19 &= ~ V_185 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
return 0 ;
}
static int F_134 ( struct V_78 * V_194 )
{
struct V_254 * V_157 = F_130 ( V_194 ) ;
struct V_1 * V_1 = V_157 -> V_184 ;
F_12 ( 0 , V_1 -> V_2 + V_261
+ V_1 -> V_259 ) ;
F_12 ( 0 , V_1 -> V_2 + V_262
+ V_1 -> V_260 ) ;
F_135 ( V_1 -> V_2 + V_13 ,
V_1 -> V_186 , V_107 ) ;
F_135 ( V_1 -> V_2 + V_16 ,
V_1 -> V_187 , V_107 ) ;
F_12 ( V_1 -> V_19 | V_209 ,
V_1 -> V_2 + V_23 ) ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
F_17 ( V_1 ) ;
V_1 -> V_19 |= V_185 ;
F_12 ( V_1 -> V_19 , V_1 -> V_2 + V_23 ) ;
if ( F_90 ( V_1 ) ) {
F_43 ( 3000 , 10000 ) ;
F_14 ( V_1 ) ;
}
F_131 ( V_157 , V_263 ) ;
return 0 ;
}
static void F_136 ( struct V_254 * V_157 )
{
F_70 ( V_157 -> V_184 ) ;
}
static int
F_137 ( struct V_192 * V_77 ,
const struct V_264 * V_265 )
{
static int V_194 ;
struct V_1 * V_1 ;
struct V_254 * V_157 ;
int V_100 ;
T_8 V_17 ;
if ( V_194 >= V_266 ) {
return - V_267 ;
}
if ( ! V_268 [ V_194 ] ) {
V_194 ++ ;
return - V_269 ;
}
V_100 = F_138 ( & V_77 -> V_194 , V_270 [ V_194 ] , V_160 [ V_194 ] , V_271 ,
sizeof( struct V_1 ) , & V_157 ) ;
if ( V_100 < 0 )
return V_100 ;
V_157 -> V_198 = F_136 ;
V_1 = V_157 -> V_184 ;
V_1 -> V_157 = V_157 ;
V_1 -> V_77 = V_77 ;
if ( ( V_100 = F_79 ( V_1 ) ) < 0 ) {
F_139 ( V_157 ) ;
return V_100 ;
}
#ifdef F_74
V_1 -> V_186 = F_140 ( V_107 ) ;
if ( ! V_1 -> V_186 ) {
F_85 ( V_157 -> V_194 ,
L_65 ) ;
F_139 ( V_157 ) ;
return - V_195 ;
}
V_1 -> V_187 = F_140 ( V_107 ) ;
if ( ! V_1 -> V_187 ) {
F_85 ( V_157 -> V_194 ,
L_66 ) ;
F_139 ( V_157 ) ;
return - V_195 ;
}
#endif
strcpy ( V_157 -> V_272 , L_67 ) ;
switch ( V_1 -> V_77 -> V_78 ) {
case V_205 :
strcpy ( V_157 -> V_273 , L_68 ) ;
break;
case V_235 :
strcpy ( V_157 -> V_273 , L_69 ) ;
break;
case V_80 :
strcpy ( V_157 -> V_273 , L_70 ) ;
break;
case V_79 :
F_87 ( V_1 -> V_77 , 8 , & V_17 ) ;
if ( V_17 < 5 ) {
strcpy ( V_157 -> V_273 , L_71 ) ;
} else {
strcpy ( V_157 -> V_273 , L_72 ) ;
}
break;
}
sprintf ( V_157 -> V_214 , L_73 , V_157 -> V_273 ,
V_1 -> V_105 , V_1 -> V_138 ) ;
if ( ( V_100 = F_141 ( V_157 ) ) < 0 ) {
F_139 ( V_157 ) ;
return V_100 ;
}
F_142 ( V_77 , V_157 ) ;
V_194 ++ ;
return 0 ;
}
static void F_143 ( struct V_192 * V_77 )
{
F_139 ( F_144 ( V_77 ) ) ;
}
