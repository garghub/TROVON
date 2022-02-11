static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = V_8 -> V_10 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_11 ;
if ( V_8 -> V_10 == V_4 -> V_9 . integer . V_9 [ 0 ] )
return 0 ;
if ( V_6 -> V_12 )
return - V_13 ;
V_11 = F_5 ( V_6 , V_14 ) ;
V_8 -> V_10 = V_4 -> V_9 . integer . V_9 [ 0 ] ;
if ( ( ( V_11 >> 2 ) & 0x3 ) == V_8 -> V_10 )
return 1 ;
V_11 = ( V_11 & 0x1f3 ) | ( V_8 -> V_10 << 2 ) ;
F_6 ( V_6 , V_14 , V_11 ) ;
F_7 ( V_6 , V_8 -> V_15 ) ;
F_8 ( V_6 , V_8 -> V_16 ) ;
return 1 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_17 * V_18 = & V_6 -> V_18 ;
F_10 ( V_18 , V_19 ,
F_11 ( V_19 ) ) ;
F_12 ( V_18 , V_20 , F_11 ( V_20 ) ) ;
return 0 ;
}
static void F_13 ( struct V_21 * V_22 , unsigned int V_23 ,
unsigned int V_24 )
{
T_2 V_25 ;
unsigned int V_26 , V_27 , V_28 ;
V_27 = V_23 / V_24 ;
if ( V_27 < 6 ) {
V_24 >>= 1 ;
V_22 -> V_29 = 1 ;
V_27 = V_23 / V_24 ;
} else
V_22 -> V_29 = 0 ;
if ( ( V_27 < 6 ) || ( V_27 > 12 ) )
F_14 ( V_30
L_1 , V_27 ) ;
V_22 -> V_31 = V_27 ;
V_28 = V_23 % V_24 ;
V_25 = V_32 * ( long long ) V_28 ;
F_15 ( V_25 , V_24 ) ;
V_26 = V_25 & 0xFFFFFFFF ;
if ( ( V_26 % 10 ) >= 5 )
V_26 += 5 ;
V_26 /= 10 ;
V_22 -> V_33 = V_26 ;
}
static int F_16 ( struct V_34 * V_35 , int V_36 ,
int V_24 , unsigned int V_37 , unsigned int V_38 )
{
T_1 V_39 , V_40 ;
int V_41 ;
struct V_5 * V_6 = V_35 -> V_6 ;
if ( V_36 < V_42 || V_36 > V_43 )
return - V_44 ;
if ( V_36 == V_42 ) {
V_41 = 0 ;
V_40 = 0x10 ;
V_39 = F_5 ( V_6 , V_45 ) & 0xffef ;
} else {
V_41 = 4 ;
V_40 = 0x8 ;
V_39 = F_5 ( V_6 , V_45 ) & 0xfff7 ;
}
if ( ! V_37 || ! V_38 ) {
F_6 ( V_6 , V_46 + V_41 , 0x0026 ) ;
F_6 ( V_6 , V_45 , V_39 ) ;
return 0 ;
} else {
T_1 V_9 = 0 ;
struct V_21 V_22 ;
F_13 ( & V_22 , V_38 * 8 , V_37 ) ;
V_9 = ( V_22 . V_31 << 5 ) + ( ( V_22 . V_33 & 0x3c0000 ) >> 18 ) ;
F_6 ( V_6 , V_47 + V_41 , V_9 ) ;
V_9 = ( V_22 . V_33 & 0x03fe00 ) >> 9 ;
F_6 ( V_6 , V_48 + V_41 , V_9 ) ;
V_9 = V_22 . V_33 & 0x0001ff ;
F_6 ( V_6 , V_49 + V_41 , V_9 ) ;
F_6 ( V_6 , V_46 + V_41 , 0x0027 |
( V_22 . V_29 << 3 ) ) ;
F_6 ( V_6 , V_45 , V_39 | V_40 ) ;
}
return 0 ;
}
static int F_17 ( int V_50 , int V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < F_11 ( V_53 ) ; V_52 ++ ) {
if ( V_53 [ V_52 ] . V_51 == V_51 && V_53 [ V_52 ] . V_50 == V_50 )
return V_52 ;
}
return - V_54 ;
}
static int F_18 ( struct V_34 * V_35 ,
int V_55 , unsigned int V_56 , int V_57 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_56 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
if ( V_55 == V_58 ) {
V_8 -> V_59 = V_56 ;
return 0 ;
} else if ( V_55 == V_60 ) {
V_8 -> V_61 = V_56 ;
return 0 ;
}
break;
}
return - V_54 ;
}
static int F_19 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 V_63 = F_5 ( V_6 , V_64 ) & 0x01ec ;
switch ( V_62 & V_65 ) {
case V_66 :
V_63 |= 0x0002 ;
break;
case V_67 :
break;
case V_68 :
V_63 |= 0x0001 ;
break;
case V_69 :
V_63 |= 0x0003 ;
break;
case V_70 :
V_63 |= 0x0013 ;
break;
default:
return - V_54 ;
}
F_6 ( V_6 , V_64 , V_63 ) ;
return 0 ;
}
static int F_20 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_34 * V_75 )
{
struct V_76 * V_77 = V_72 -> V_78 ;
struct V_5 * V_6 = V_77 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_63 = F_5 ( V_6 , V_64 ) & 0x01f3 ;
T_1 V_79 = F_5 ( V_6 , V_80 ) & 0x017f ;
switch ( F_21 ( V_74 ) ) {
case V_81 :
break;
case V_82 :
V_63 |= 0x0004 ;
break;
case V_83 :
V_63 |= 0x0008 ;
break;
case V_84 :
V_63 |= 0x000c ;
break;
}
if ( F_22 ( V_74 ) * 384 == V_8 -> V_61 )
V_79 |= 0x80 ;
F_6 ( V_6 , V_80 , V_79 ) ;
F_6 ( V_6 , V_64 , V_63 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 V_63 , V_11 ;
V_63 = F_5 ( V_6 , V_64 ) & 0x011f ;
V_11 = F_5 ( V_6 , V_14 ) & 0x015d ;
switch ( V_62 & V_85 ) {
case V_86 :
break;
case V_87 :
V_11 |= 0x2 ;
case V_88 :
V_63 |= 0x0040 ;
break;
default:
return - V_54 ;
}
switch ( V_62 & V_65 ) {
case V_69 :
case V_70 :
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_91 :
V_63 |= 0x0080 ;
break;
default:
return - V_54 ;
}
break;
case V_66 :
case V_67 :
case V_68 :
V_63 &= ~ 0x0010 ;
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_92 :
V_63 |= 0x0090 ;
break;
case V_91 :
V_63 |= 0x0080 ;
break;
case V_93 :
V_63 |= 0x0010 ;
break;
default:
return - V_54 ;
}
break;
default:
return - V_54 ;
}
F_6 ( V_6 , V_64 , V_63 ) ;
F_6 ( V_6 , V_14 , V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_34 * V_35 ,
int V_94 , int div )
{
struct V_5 * V_6 = V_35 -> V_6 ;
T_1 V_39 ;
switch ( V_94 ) {
case V_95 :
V_39 = F_5 ( V_6 , V_45 ) & 0x003f ;
F_6 ( V_6 , V_45 , V_39 | div ) ;
break;
case V_96 :
V_39 = F_5 ( V_6 , V_97 ) & 0x01c7 ;
F_6 ( V_6 , V_97 , V_39 | div ) ;
break;
case V_98 :
V_39 = F_5 ( V_6 , V_97 ) & 0x003f ;
F_6 ( V_6 , V_97 , V_39 | div ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 V_99 = F_5 ( V_6 , V_100 ) & 0x01e0 ;
switch ( V_62 & V_65 ) {
case V_66 :
V_99 |= 0x0002 ;
break;
case V_67 :
break;
case V_68 :
V_99 |= 0x0001 ;
break;
case V_69 :
V_99 |= 0x0003 ;
break;
case V_70 :
V_99 |= 0x0013 ;
break;
default:
return - V_54 ;
}
F_6 ( V_6 , V_100 , V_99 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 V_11 , V_99 ;
V_99 = F_5 ( V_6 , V_100 ) & 0x011f ;
V_11 = F_5 ( V_6 , V_14 ) & 0x00ae ;
switch ( V_62 & V_85 ) {
case V_86 :
break;
case V_87 :
V_11 |= 0x1 ;
case V_88 :
V_99 |= 0x0040 ;
break;
default:
return - V_54 ;
}
switch ( V_62 & V_65 ) {
case V_69 :
case V_70 :
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_91 :
V_99 |= 0x0080 ;
break;
default:
return - V_54 ;
}
break;
case V_66 :
case V_67 :
case V_68 :
V_99 &= ~ 0x0010 ;
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_92 :
V_99 |= 0x0090 ;
break;
case V_91 :
V_99 |= 0x0080 ;
break;
case V_93 :
V_99 |= 0x0010 ;
break;
default:
return - V_54 ;
}
break;
default:
return - V_54 ;
}
F_6 ( V_6 , V_100 , V_99 ) ;
F_6 ( V_6 , V_14 , V_11 ) ;
return 0 ;
}
static int F_27 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_34 * V_75 )
{
struct V_76 * V_77 = V_72 -> V_78 ;
struct V_5 * V_6 = V_77 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_79 = F_5 ( V_6 , V_80 ) & 0x01c0 ;
T_1 V_99 = F_5 ( V_6 , V_100 ) & 0x01f3 ;
int V_101 ;
V_101 = F_17 ( V_8 -> V_59 , F_22 ( V_74 ) ) ;
if ( V_101 < 0 ) {
F_14 ( V_102 L_2 ) ;
return V_101 ;
}
F_6 ( V_6 , V_80 , V_79 | ( V_53 [ V_101 ] . V_103 << 1 ) |
V_53 [ V_101 ] . V_104 ) ;
switch ( F_21 ( V_74 ) ) {
case V_81 :
break;
case V_82 :
V_99 |= 0x0004 ;
break;
case V_83 :
V_99 |= 0x0008 ;
break;
case V_84 :
V_99 |= 0x000c ;
break;
}
F_6 ( V_6 , V_100 , V_99 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_5 ( V_6 , V_45 ) & 0xfffb ;
F_6 ( V_6 , V_45 , clock ) ;
return F_19 ( V_6 , V_62 ) ;
}
static int F_29 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
return F_25 ( V_6 , V_62 ) ;
}
static int F_30 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_5 ( V_6 , V_45 ) & 0xfffb ;
F_6 ( V_6 , V_45 , clock ) ;
return F_19 ( V_6 , V_62 ) ;
}
static int F_31 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_5 ( V_6 , V_45 ) & 0xfffb ;
F_6 ( V_6 , V_45 , clock | 0x4 ) ;
if ( F_25 ( V_6 , V_62 ) < 0 )
return - V_54 ;
return F_19 ( V_6 , V_62 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_105 = 0 ;
switch ( V_8 -> V_10 ) {
case 0 :
V_105 = F_29 ( V_6 , V_62 ) ;
break;
case 1 :
V_105 = F_30 ( V_6 , V_62 ) ;
break;
case 2 :
case 3 :
V_105 = F_31 ( V_6 , V_62 ) ;
break;
default:
break;
}
if ( V_105 )
return V_105 ;
return F_26 ( V_6 , V_62 ) ;
}
static int F_32 ( struct V_34 * V_35 ,
unsigned int V_62 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_15 = V_62 ;
return F_7 ( V_6 , V_62 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
unsigned int V_62 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_105 = 0 ;
if ( V_8 -> V_10 != 0 )
return 0 ;
V_105 = F_28 ( V_6 , V_62 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_23 ( V_6 , V_62 ) ;
if ( V_105 )
return V_105 ;
return 0 ;
}
static int F_33 ( struct V_34 * V_35 ,
unsigned int V_62 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_16 = V_62 ;
return F_8 ( V_6 , V_62 ) ;
}
static int F_34 ( struct V_34 * V_75 , int V_106 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
T_1 V_107 = F_5 ( V_6 , V_108 ) & 0xfff7 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_106 && V_8 -> V_10 == 1 ) {
if ( ! V_6 -> V_12 )
F_6 ( V_6 , V_108 , V_107 | 0x8 ) ;
} else {
if ( V_106 )
F_6 ( V_6 , V_108 , V_107 | 0x8 ) ;
else
F_6 ( V_6 , V_108 , V_107 ) ;
}
return 0 ;
}
static int F_35 ( struct V_5 * V_6 ,
enum V_109 V_110 )
{
T_1 V_111 = F_5 ( V_6 , V_112 ) & 0xfe3e ;
switch ( V_110 ) {
case V_113 :
F_6 ( V_6 , V_112 , V_111 | 0x00c0 ) ;
break;
case V_114 :
F_6 ( V_6 , V_112 , V_111 | 0x01c1 ) ;
break;
case V_115 :
F_6 ( V_6 , V_112 , V_111 | 0x0141 ) ;
break;
case V_116 :
F_6 ( V_6 , V_112 , 0x0001 ) ;
break;
}
V_6 -> V_18 . V_117 = V_110 ;
return 0 ;
}
static void F_36 ( struct V_118 * V_119 )
{
struct V_17 * V_18 =
F_37 ( V_119 , struct V_17 ,
V_120 . V_119 ) ;
struct V_5 * V_6 = V_18 -> V_6 ;
F_35 ( V_6 , V_18 -> V_117 ) ;
}
static int F_38 ( struct V_5 * V_6 , T_3 V_121 )
{
F_35 ( V_6 , V_116 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
T_1 * V_122 = V_6 -> V_122 ;
int V_52 ;
for ( V_52 = 1 ; V_52 < F_11 ( V_123 ) ; V_52 ++ ) {
if ( V_52 == V_124 )
continue;
if ( V_122 [ V_52 ] == V_123 [ V_52 ] )
continue;
F_6 ( V_6 , V_52 , V_122 [ V_52 ] ) ;
}
F_35 ( V_6 , V_115 ) ;
if ( V_6 -> V_18 . V_125 == V_113 ) {
F_35 ( V_6 , V_114 ) ;
V_6 -> V_18 . V_117 = V_113 ;
F_40 ( & V_6 -> V_18 . V_120 ,
F_41 ( V_126 ) ) ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_105 ;
F_43 ( & V_6 -> V_18 . V_120 , F_36 ) ;
V_105 = F_44 ( V_6 , 7 , 9 , V_8 -> V_127 ) ;
if ( V_105 < 0 ) {
F_45 ( V_6 -> V_128 , L_3 , V_105 ) ;
return V_105 ;
}
V_105 = F_46 ( V_6 ) ;
if ( V_105 < 0 ) {
F_45 ( V_6 -> V_128 , L_4 , V_105 ) ;
return V_105 ;
}
F_35 ( V_6 , V_115 ) ;
V_8 -> V_10 = 0 ;
F_35 ( V_6 , V_114 ) ;
F_40 ( & V_6 -> V_18 . V_120 ,
F_41 ( V_126 ) ) ;
F_47 ( V_6 , V_129 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_130 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_131 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_132 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_133 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_134 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_135 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_136 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_137 , 0x0100 , 0x0100 ) ;
F_47 ( V_6 , V_138 , 0x0100 , 0x0100 ) ;
F_48 ( V_6 , V_139 ,
F_11 ( V_139 ) ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 )
{
F_50 ( & V_6 -> V_18 . V_120 ) ;
F_35 ( V_6 , V_116 ) ;
return 0 ;
}
static int T_4 F_51 ( struct V_140 * V_141 )
{
struct V_7 * V_8 ;
int V_105 ;
V_8 = F_52 ( sizeof( struct V_7 ) , V_142 ) ;
if ( V_8 == NULL )
return - V_143 ;
V_8 -> V_127 = V_144 ;
F_53 ( V_141 , V_8 ) ;
V_105 = F_54 ( & V_141 -> V_128 ,
& V_145 , V_146 , F_11 ( V_146 ) ) ;
if ( V_105 < 0 )
F_55 ( V_8 ) ;
return V_105 ;
}
static int T_5 F_56 ( struct V_140 * V_141 )
{
F_57 ( & V_141 -> V_128 ) ;
F_55 ( F_58 ( V_141 ) ) ;
return 0 ;
}
static T_4 int F_59 ( struct V_147 * V_148 ,
const struct V_149 * V_150 )
{
struct V_7 * V_8 ;
int V_105 ;
V_8 = F_52 ( sizeof( struct V_7 ) , V_142 ) ;
if ( V_8 == NULL )
return - V_143 ;
F_60 ( V_148 , V_8 ) ;
V_8 -> V_127 = V_151 ;
V_105 = F_54 ( & V_148 -> V_128 ,
& V_145 , V_146 , F_11 ( V_146 ) ) ;
if ( V_105 < 0 )
F_55 ( V_8 ) ;
return V_105 ;
}
static T_5 int F_61 ( struct V_147 * V_152 )
{
F_57 ( & V_152 -> V_128 ) ;
F_55 ( F_62 ( V_152 ) ) ;
return 0 ;
}
static int T_6 F_63 ( void )
{
int V_105 = 0 ;
#if F_64 ( V_153 ) || F_64 ( V_154 )
V_105 = F_65 ( & V_155 ) ;
if ( V_105 != 0 ) {
F_14 ( V_102 L_5 ,
V_105 ) ;
}
#endif
#if F_64 ( V_156 )
V_105 = F_66 ( & V_157 ) ;
if ( V_105 != 0 ) {
F_14 ( V_102 L_6 ,
V_105 ) ;
}
#endif
return V_105 ;
}
static void T_7 F_67 ( void )
{
#if F_64 ( V_153 ) || F_64 ( V_154 )
F_68 ( & V_155 ) ;
#endif
#if F_64 ( V_156 )
F_69 ( & V_157 ) ;
#endif
}
