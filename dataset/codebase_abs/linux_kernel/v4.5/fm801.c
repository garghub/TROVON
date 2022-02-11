static inline void F_1 ( struct V_1 * V_2 , unsigned short V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
if ( ! ( F_6 ( V_2 , V_8 ) & V_9 ) )
return true ;
F_7 ( 10 ) ;
}
return false ;
}
static bool F_8 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
if ( F_6 ( V_2 , V_8 ) & V_10 )
return true ;
F_7 ( 10 ) ;
}
return false ;
}
static int F_9 ( struct V_1 * V_2 , unsigned short V_11 ,
unsigned short V_12 , unsigned short V_4 )
{
int V_13 ;
unsigned long V_14 ;
unsigned short V_15 , V_16 ;
F_10 ( & V_2 -> V_17 , V_14 ) ;
V_15 = F_3 ( V_2 , V_11 ) ;
V_16 = ( V_15 & ~ V_12 ) | V_4 ;
V_13 = V_15 != V_16 ;
if ( V_13 )
F_1 ( V_2 , V_11 , V_16 ) ;
F_11 ( & V_2 -> V_17 , V_14 ) ;
return V_13 ;
}
static void F_12 ( struct V_18 * V_19 ,
unsigned short V_11 ,
unsigned short V_20 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( ! F_5 ( V_2 , 100 ) ) {
F_13 ( V_2 -> V_22 -> V_23 , L_1 ) ;
return;
}
F_14 ( V_2 , V_24 , V_20 ) ;
F_14 ( V_2 , V_8 , V_11 | ( V_19 -> V_25 << V_26 ) ) ;
if ( ! F_5 ( V_2 , 1000 ) )
F_13 ( V_2 -> V_22 -> V_23 , L_2 ,
V_19 -> V_27 ) ;
}
static unsigned short F_15 ( struct V_18 * V_19 , unsigned short V_11 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( ! F_5 ( V_2 , 100 ) ) {
F_13 ( V_2 -> V_22 -> V_23 , L_1 ) ;
return 0 ;
}
F_14 ( V_2 , V_8 ,
V_11 | ( V_19 -> V_25 << V_26 ) | V_28 ) ;
if ( ! F_5 ( V_2 , 100 ) ) {
F_13 ( V_2 -> V_22 -> V_23 , L_2 ,
V_19 -> V_27 ) ;
return 0 ;
}
if ( ! F_8 ( V_2 , 1000 ) ) {
F_13 ( V_2 -> V_22 -> V_23 ,
L_3 , V_19 -> V_27 ) ;
return 0 ;
}
return F_6 ( V_2 , V_24 ) ;
}
static unsigned short F_16 ( unsigned int V_29 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < F_17 ( V_30 ) ; V_7 ++ )
if ( V_30 [ V_7 ] == V_29 )
return V_7 ;
F_18 () ;
return F_17 ( V_30 ) - 1 ;
}
static int F_19 ( struct V_31 * V_32 ,
int V_33 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
F_21 ( & V_2 -> V_17 ) ;
switch ( V_33 ) {
case V_34 :
V_2 -> V_35 &= ~ ( V_36 |
V_37 |
V_38 ) ;
V_2 -> V_35 |= V_39 |
V_40 ;
break;
case V_41 :
V_2 -> V_35 &= ~ ( V_39 | V_38 ) ;
break;
case V_42 :
case V_43 :
V_2 -> V_35 |= V_38 ;
break;
case V_44 :
case V_45 :
V_2 -> V_35 &= ~ V_38 ;
break;
default:
F_22 ( & V_2 -> V_17 ) ;
F_18 () ;
return - V_46 ;
}
F_14 ( V_2 , V_47 , V_2 -> V_35 ) ;
F_22 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 ,
int V_33 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
F_21 ( & V_2 -> V_17 ) ;
switch ( V_33 ) {
case V_34 :
V_2 -> V_48 &= ~ ( V_36 |
V_37 |
V_38 ) ;
V_2 -> V_48 |= V_39 |
V_40 ;
break;
case V_41 :
V_2 -> V_48 &= ~ ( V_39 | V_38 ) ;
break;
case V_42 :
case V_43 :
V_2 -> V_48 |= V_38 ;
break;
case V_44 :
case V_45 :
V_2 -> V_48 &= ~ V_38 ;
break;
default:
F_22 ( & V_2 -> V_17 ) ;
F_18 () ;
return - V_46 ;
}
F_14 ( V_2 , V_49 , V_2 -> V_48 ) ;
F_22 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 ,
struct V_50 * V_51 )
{
return F_25 ( V_32 , F_26 ( V_51 ) ) ;
}
static int F_27 ( struct V_31 * V_32 )
{
return F_28 ( V_32 ) ;
}
static int F_29 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
V_2 -> V_54 = F_30 ( V_32 ) ;
V_2 -> V_55 = F_31 ( V_32 ) ;
F_32 ( & V_2 -> V_17 ) ;
V_2 -> V_35 &= ~ ( V_39 | V_56 |
V_57 | V_58 |
V_59 ) ;
if ( F_33 ( V_53 -> V_60 ) == 16 )
V_2 -> V_35 |= V_56 ;
if ( V_53 -> V_61 > 1 ) {
V_2 -> V_35 |= V_57 ;
if ( V_53 -> V_61 == 4 )
V_2 -> V_35 |= V_62 ;
else if ( V_53 -> V_61 == 6 )
V_2 -> V_35 |= V_63 ;
}
V_2 -> V_35 |= F_16 ( V_53 -> V_29 ) << V_64 ;
V_2 -> V_65 = 0 ;
F_14 ( V_2 , V_47 , V_2 -> V_35 ) ;
F_14 ( V_2 , V_66 , V_2 -> V_55 - 1 ) ;
V_2 -> V_67 = V_53 -> V_68 ;
V_2 -> V_69 = 0 ;
F_34 ( V_2 , V_70 , V_2 -> V_67 ) ;
F_34 ( V_2 , V_71 ,
V_2 -> V_67 + ( V_2 -> V_55 % V_2 -> V_54 ) ) ;
F_35 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
V_2 -> V_72 = F_30 ( V_32 ) ;
V_2 -> V_73 = F_31 ( V_32 ) ;
F_32 ( & V_2 -> V_17 ) ;
V_2 -> V_48 &= ~ ( V_39 | V_56 |
V_57 | V_58 ) ;
if ( F_33 ( V_53 -> V_60 ) == 16 )
V_2 -> V_48 |= V_56 ;
if ( V_53 -> V_61 > 1 )
V_2 -> V_48 |= V_57 ;
V_2 -> V_48 |= F_16 ( V_53 -> V_29 ) << V_64 ;
V_2 -> V_74 = 0 ;
F_14 ( V_2 , V_49 , V_2 -> V_48 ) ;
F_14 ( V_2 , V_75 , V_2 -> V_73 - 1 ) ;
V_2 -> V_76 = V_53 -> V_68 ;
V_2 -> V_77 = 0 ;
F_34 ( V_2 , V_78 , V_2 -> V_76 ) ;
F_34 ( V_2 , V_79 ,
V_2 -> V_76 + ( V_2 -> V_73 % V_2 -> V_72 ) ) ;
F_35 ( & V_2 -> V_17 ) ;
return 0 ;
}
static T_2 F_37 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
T_3 V_80 ;
if ( ! ( V_2 -> V_35 & V_39 ) )
return 0 ;
F_21 ( & V_2 -> V_17 ) ;
V_80 = V_2 -> V_69 + ( V_2 -> V_55 - 1 ) - F_6 ( V_2 , V_66 ) ;
if ( F_6 ( V_2 , V_81 ) & V_82 ) {
V_80 += V_2 -> V_55 ;
V_80 %= V_2 -> V_54 ;
}
F_22 ( & V_2 -> V_17 ) ;
return F_38 ( V_32 -> V_53 , V_80 ) ;
}
static T_2 F_39 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
T_3 V_80 ;
if ( ! ( V_2 -> V_48 & V_39 ) )
return 0 ;
F_21 ( & V_2 -> V_17 ) ;
V_80 = V_2 -> V_77 + ( V_2 -> V_73 - 1 ) - F_6 ( V_2 , V_75 ) ;
if ( F_6 ( V_2 , V_81 ) & V_83 ) {
V_80 += V_2 -> V_73 ;
V_80 %= V_2 -> V_72 ;
}
F_22 ( & V_2 -> V_17 ) ;
return F_38 ( V_32 -> V_53 , V_80 ) ;
}
static T_4 F_40 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
unsigned short V_86 ;
unsigned int V_87 ;
V_86 = F_6 ( V_2 , V_81 ) ;
V_86 &= V_82 | V_83 | V_88 | V_89 ;
if ( ! V_86 )
return V_90 ;
F_14 ( V_2 , V_81 , V_86 ) ;
if ( V_2 -> V_91 && ( V_86 & V_82 ) && V_2 -> V_92 ) {
F_21 ( & V_2 -> V_17 ) ;
V_2 -> V_65 ++ ;
V_2 -> V_69 += V_2 -> V_55 ;
V_2 -> V_69 %= V_2 -> V_54 ;
V_87 = V_2 -> V_69 + V_2 -> V_55 ;
V_87 %= V_2 -> V_54 ;
if ( V_2 -> V_65 & 1 )
F_34 ( V_2 , V_70 , V_2 -> V_67 + V_87 ) ;
else
F_34 ( V_2 , V_71 , V_2 -> V_67 + V_87 ) ;
F_22 ( & V_2 -> V_17 ) ;
F_41 ( V_2 -> V_92 ) ;
}
if ( V_2 -> V_91 && ( V_86 & V_83 ) && V_2 -> V_93 ) {
F_21 ( & V_2 -> V_17 ) ;
V_2 -> V_74 ++ ;
V_2 -> V_77 += V_2 -> V_73 ;
V_2 -> V_77 %= V_2 -> V_72 ;
V_87 = V_2 -> V_77 + V_2 -> V_73 ;
V_87 %= V_2 -> V_72 ;
if ( V_2 -> V_74 & 1 )
F_34 ( V_2 , V_78 , V_2 -> V_76 + V_87 ) ;
else
F_34 ( V_2 , V_79 , V_2 -> V_76 + V_87 ) ;
F_22 ( & V_2 -> V_17 ) ;
F_41 ( V_2 -> V_93 ) ;
}
if ( V_2 -> V_94 && ( V_86 & V_88 ) )
F_42 ( V_84 , V_2 -> V_94 -> V_21 ) ;
if ( V_86 & V_89 ) {
}
return V_95 ;
}
static int F_43 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
int V_96 ;
V_2 -> V_92 = V_32 ;
V_53 -> V_97 = V_98 ;
F_44 ( V_53 , 0 , V_99 ,
& V_100 ) ;
if ( V_2 -> V_101 ) {
V_53 -> V_97 . V_102 = 6 ;
F_44 ( V_53 , 0 ,
V_103 ,
& V_104 ) ;
}
if ( ( V_96 = F_45 ( V_53 , V_105 ) ) < 0 )
return V_96 ;
return 0 ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
int V_96 ;
V_2 -> V_93 = V_32 ;
V_53 -> V_97 = V_106 ;
F_44 ( V_53 , 0 , V_99 ,
& V_100 ) ;
if ( ( V_96 = F_45 ( V_53 , V_105 ) ) < 0 )
return V_96 ;
return 0 ;
}
static int F_47 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
V_2 -> V_92 = NULL ;
return 0 ;
}
static int F_48 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_20 ( V_32 ) ;
V_2 -> V_93 = NULL ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_107 )
{
struct V_108 * V_109 = F_50 ( V_2 -> V_23 ) ;
struct V_110 * V_91 ;
int V_96 ;
if ( ( V_96 = F_51 ( V_2 -> V_22 , L_4 , V_107 , 1 , 1 , & V_91 ) ) < 0 )
return V_96 ;
F_52 ( V_91 , V_111 , & V_112 ) ;
F_52 ( V_91 , V_113 , & V_114 ) ;
V_91 -> V_21 = V_2 ;
V_91 -> V_115 = 0 ;
strcpy ( V_91 -> V_116 , L_4 ) ;
V_2 -> V_91 = V_91 ;
F_53 ( V_91 , V_117 ,
F_54 ( V_109 ) ,
V_2 -> V_101 ? 128 * 1024 : 64 * 1024 , 128 * 1024 ) ;
return F_55 ( V_91 , V_111 ,
V_118 ,
V_2 -> V_101 ? 6 : 2 , 0 ,
NULL ) ;
}
static void F_56 ( struct V_119 * V_120 , T_5 V_121 )
{
struct V_1 * V_2 = V_120 -> V_21 ;
unsigned short V_11 = F_6 ( V_2 , V_122 ) ;
struct V_123 V_124 = * F_57 ( V_2 ) ;
V_11 &= ~ ( F_58 ( V_124 . V_125 ) |
F_58 ( V_124 . V_126 ) |
F_58 ( V_124 . V_127 ) ) ;
V_11 |= ( V_121 & V_128 ) ? F_58 ( V_124 . V_125 ) : 0 ;
V_11 |= ( V_121 & V_129 ) ? F_58 ( V_124 . V_126 ) : 0 ;
V_11 |= ( V_121 & V_130 ) ? 0 : F_58 ( V_124 . V_127 ) ;
F_14 ( V_2 , V_122 , V_11 ) ;
}
static T_5 F_59 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_21 ;
unsigned short V_11 = F_6 ( V_2 , V_122 ) ;
struct V_123 V_124 = * F_57 ( V_2 ) ;
T_5 V_131 ;
V_131 = 0 ;
if ( V_11 & F_58 ( V_124 . V_125 ) )
V_131 |= V_128 ;
if ( V_11 & F_58 ( V_124 . V_132 ) )
V_131 |= V_133 ;
return V_131 ;
}
static void F_60 ( struct V_119 * V_120 , bool V_134 )
{
struct V_1 * V_2 = V_120 -> V_21 ;
unsigned short V_11 = F_6 ( V_2 , V_122 ) ;
struct V_123 V_124 = * F_57 ( V_2 ) ;
V_11 |= F_61 ( V_124 . V_125 ) |
F_61 ( V_124 . V_127 ) |
F_61 ( V_124 . V_126 ) |
F_61 ( V_124 . V_132 ) ;
if ( V_134 ) {
V_11 &= ~ ( F_62 ( V_124 . V_125 ) |
F_62 ( V_124 . V_127 ) |
F_62 ( V_124 . V_126 ) |
F_58 ( V_124 . V_125 ) |
F_58 ( V_124 . V_126 ) |
F_58 ( V_124 . V_127 ) ) ;
} else {
V_11 |= F_62 ( V_124 . V_125 ) |
F_62 ( V_124 . V_132 ) |
F_58 ( V_124 . V_125 ) |
F_58 ( V_124 . V_132 ) |
F_58 ( V_124 . V_127 ) ;
V_11 &= ~ ( F_62 ( V_124 . V_127 ) |
F_62 ( V_124 . V_126 ) |
F_58 ( V_124 . V_126 ) ) ;
}
F_14 ( V_2 , V_122 , V_11 ) ;
}
static int F_63 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
int V_12 = ( V_136 -> V_139 >> 16 ) & 0xff ;
V_138 -> type = V_12 == 1 ? V_140 : V_141 ;
V_138 -> V_142 = 1 ;
V_138 -> V_4 . integer . V_143 = 0 ;
V_138 -> V_4 . integer . V_144 = V_12 ;
return 0 ;
}
static int F_64 ( struct V_135 * V_136 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_65 ( V_136 ) ;
int V_11 = V_136 -> V_139 & 0xff ;
int V_147 = ( V_136 -> V_139 >> 8 ) & 0xff ;
int V_12 = ( V_136 -> V_139 >> 16 ) & 0xff ;
int V_148 = ( V_136 -> V_139 >> 24 ) & 0xff ;
long * V_4 = V_146 -> V_4 . integer . V_4 ;
V_4 [ 0 ] = ( F_3 ( V_2 , V_11 ) >> V_147 ) & V_12 ;
if ( V_148 )
V_4 [ 0 ] = V_12 - V_4 [ 0 ] ;
return 0 ;
}
static int F_66 ( struct V_135 * V_136 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_65 ( V_136 ) ;
int V_11 = V_136 -> V_139 & 0xff ;
int V_147 = ( V_136 -> V_139 >> 8 ) & 0xff ;
int V_12 = ( V_136 -> V_139 >> 16 ) & 0xff ;
int V_148 = ( V_136 -> V_139 >> 24 ) & 0xff ;
unsigned short V_20 ;
V_20 = ( V_146 -> V_4 . integer . V_4 [ 0 ] & V_12 ) ;
if ( V_148 )
V_20 = V_12 - V_20 ;
return F_9 ( V_2 , V_11 , V_12 << V_147 , V_20 << V_147 ) ;
}
static int F_67 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
int V_12 = ( V_136 -> V_139 >> 16 ) & 0xff ;
V_138 -> type = V_12 == 1 ? V_140 : V_141 ;
V_138 -> V_142 = 2 ;
V_138 -> V_4 . integer . V_143 = 0 ;
V_138 -> V_4 . integer . V_144 = V_12 ;
return 0 ;
}
static int F_68 ( struct V_135 * V_136 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_65 ( V_136 ) ;
int V_11 = V_136 -> V_139 & 0xff ;
int V_149 = ( V_136 -> V_139 >> 8 ) & 0x0f ;
int V_150 = ( V_136 -> V_139 >> 12 ) & 0x0f ;
int V_12 = ( V_136 -> V_139 >> 16 ) & 0xff ;
int V_148 = ( V_136 -> V_139 >> 24 ) & 0xff ;
long * V_4 = V_146 -> V_4 . integer . V_4 ;
F_32 ( & V_2 -> V_17 ) ;
V_4 [ 0 ] = ( F_3 ( V_2 , V_11 ) >> V_149 ) & V_12 ;
V_4 [ 1 ] = ( F_3 ( V_2 , V_11 ) >> V_150 ) & V_12 ;
F_35 ( & V_2 -> V_17 ) ;
if ( V_148 ) {
V_4 [ 0 ] = V_12 - V_4 [ 0 ] ;
V_4 [ 1 ] = V_12 - V_4 [ 1 ] ;
}
return 0 ;
}
static int F_69 ( struct V_135 * V_136 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_65 ( V_136 ) ;
int V_11 = V_136 -> V_139 & 0xff ;
int V_149 = ( V_136 -> V_139 >> 8 ) & 0x0f ;
int V_150 = ( V_136 -> V_139 >> 12 ) & 0x0f ;
int V_12 = ( V_136 -> V_139 >> 16 ) & 0xff ;
int V_148 = ( V_136 -> V_139 >> 24 ) & 0xff ;
unsigned short V_151 , V_152 ;
V_151 = V_146 -> V_4 . integer . V_4 [ 0 ] & V_12 ;
V_152 = V_146 -> V_4 . integer . V_4 [ 1 ] & V_12 ;
if ( V_148 ) {
V_151 = V_12 - V_151 ;
V_152 = V_12 - V_152 ;
}
return F_9 ( V_2 , V_11 ,
( V_12 << V_149 ) | ( V_12 << V_150 ) ,
( V_151 << V_149 ) | ( V_152 << V_150 ) ) ;
}
static int F_70 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
static const char * const V_153 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
return F_71 ( V_138 , 1 , 5 , V_153 ) ;
}
static int F_72 ( struct V_135 * V_136 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_65 ( V_136 ) ;
unsigned short V_20 ;
V_20 = F_6 ( V_2 , V_154 ) & 7 ;
if ( V_20 > 4 )
V_20 = 4 ;
V_146 -> V_4 . V_155 . V_156 [ 0 ] = V_20 ;
return 0 ;
}
static int F_73 ( struct V_135 * V_136 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_65 ( V_136 ) ;
unsigned short V_20 ;
if ( ( V_20 = V_146 -> V_4 . V_155 . V_156 [ 0 ] ) > 4 )
return - V_46 ;
return F_9 ( V_2 , V_157 , 7 , V_20 ) ;
}
static void F_74 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = V_159 -> V_21 ;
V_2 -> V_160 = NULL ;
}
static void F_75 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( V_19 -> V_27 == 0 ) {
V_2 -> V_19 = NULL ;
} else {
V_2 -> V_161 = NULL ;
}
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_162 V_19 ;
unsigned int V_163 ;
int V_96 ;
static struct V_164 V_165 = {
. V_166 = F_12 ,
. V_167 = F_15 ,
} ;
if ( ( V_96 = V_158 ( V_2 -> V_22 , 0 , & V_165 , V_2 , & V_2 -> V_160 ) ) < 0 )
return V_96 ;
V_2 -> V_160 -> V_168 = F_74 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_21 = V_2 ;
V_19 . V_168 = F_75 ;
if ( ( V_96 = F_77 ( V_2 -> V_160 , & V_19 , & V_2 -> V_19 ) ) < 0 )
return V_96 ;
if ( V_2 -> V_169 ) {
V_19 . V_27 = 1 ;
V_19 . V_25 = V_2 -> V_170 ;
if ( ( V_96 = F_77 ( V_2 -> V_160 , & V_19 , & V_2 -> V_161 ) ) < 0 )
return V_96 ;
}
for ( V_163 = 0 ; V_163 < V_171 ; V_163 ++ )
F_78 ( V_2 -> V_22 , F_79 ( & V_172 [ V_163 ] , V_2 ) ) ;
if ( V_2 -> V_101 ) {
for ( V_163 = 0 ; V_163 < V_173 ; V_163 ++ )
F_78 ( V_2 -> V_22 , F_79 ( & V_174 [ V_163 ] , V_2 ) ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned int V_175 ,
unsigned short V_11 , unsigned long V_176 )
{
unsigned long V_177 = V_178 + V_176 ;
F_14 ( V_2 , V_8 ,
V_11 | ( V_175 << V_26 ) | V_28 ) ;
F_7 ( 5 ) ;
do {
if ( ( F_6 ( V_2 , V_8 ) &
( V_10 | V_9 ) ) == V_10 )
return 0 ;
F_81 ( 1 ) ;
} while ( F_82 ( V_177 , V_178 ) );
return - V_179 ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_180 , ( 1 << 5 ) | ( 1 << 6 ) ) ;
F_6 ( V_2 , V_180 ) ;
F_7 ( 100 ) ;
F_14 ( V_2 , V_180 , 0 ) ;
return F_80 ( V_2 , 0 , V_181 , F_84 ( 750 ) ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned short V_182 ;
if ( V_2 -> V_101 ) {
if ( V_2 -> V_170 ) {
F_80 ( V_2 , V_2 -> V_170 ,
V_183 , F_84 ( 50 ) ) ;
} else {
int V_163 ;
for ( V_163 = 3 ; V_163 > 0 ; V_163 -- ) {
if ( ! F_80 ( V_2 , V_163 , V_183 ,
F_84 ( 50 ) ) ) {
V_182 = F_6 ( V_2 , V_24 ) ;
if ( V_182 != 0xffff && V_182 != 0 ) {
V_2 -> V_169 = 1 ;
V_2 -> V_170 = V_163 ;
break;
}
}
}
}
F_80 ( V_2 , 0 , V_183 , F_84 ( 750 ) ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned short V_182 ;
F_14 ( V_2 , V_184 , 0x0808 ) ;
F_14 ( V_2 , V_185 , 0x9f1f ) ;
F_14 ( V_2 , V_186 , 0x8808 ) ;
F_14 ( V_2 , V_187 , 0x0003 ) ;
V_182 = F_6 ( V_2 , V_188 ) ;
if ( V_2 -> V_84 < 0 )
V_182 |= 0x00c3 ;
else
V_182 &= ~ 0x0083 ;
F_14 ( V_2 , V_188 , V_182 ) ;
F_14 ( V_2 , V_81 ,
V_82 | V_83 | V_88 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
unsigned short V_182 ;
if ( V_2 -> V_84 < 0 )
goto V_189;
V_182 = F_6 ( V_2 , V_188 ) ;
V_182 |= 0x00c3 ;
F_14 ( V_2 , V_188 , V_182 ) ;
F_88 ( V_2 -> V_23 , V_2 -> V_84 , V_2 ) ;
V_189:
#ifdef F_89
if ( ! ( V_2 -> V_190 & V_191 ) ) {
F_90 ( & V_2 -> V_120 ) ;
F_91 ( & V_2 -> V_192 ) ;
}
#endif
return 0 ;
}
static int F_92 ( struct V_193 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_194 ;
return F_87 ( V_2 ) ;
}
static int F_93 ( struct V_195 * V_22 ,
struct V_108 * V_196 ,
int V_190 ,
int V_197 ,
struct V_1 * * V_198 )
{
struct V_1 * V_2 ;
int V_96 ;
static struct V_199 V_165 = {
. V_200 = F_92 ,
} ;
* V_198 = NULL ;
if ( ( V_96 = F_94 ( V_196 ) ) < 0 )
return V_96 ;
V_2 = F_95 ( & V_196 -> V_23 , sizeof( * V_2 ) , V_201 ) ;
if ( V_2 == NULL )
return - V_202 ;
F_96 ( & V_2 -> V_17 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_23 = & V_196 -> V_23 ;
V_2 -> V_84 = - 1 ;
V_2 -> V_190 = V_190 ;
if ( ( V_96 = F_97 ( V_196 , L_4 ) ) < 0 )
return V_96 ;
V_2 -> V_5 = F_98 ( V_196 , 0 ) ;
if ( V_196 -> V_203 >= 0xb1 )
V_2 -> V_101 = 1 ;
if ( ! ( V_2 -> V_190 & V_204 ) ) {
if ( F_83 ( V_2 ) < 0 ) {
F_99 ( V_2 -> V_22 -> V_23 ,
L_10 ) ;
V_2 -> V_190 = 3 | V_204 ;
} else {
F_85 ( V_2 ) ;
}
}
F_86 ( V_2 ) ;
if ( ( V_2 -> V_190 & V_204 ) == 0 ) {
if ( F_100 ( & V_196 -> V_23 , V_196 -> V_84 , F_40 ,
V_205 , V_206 , V_2 ) ) {
F_13 ( V_22 -> V_23 , L_11 , V_196 -> V_84 ) ;
F_87 ( V_2 ) ;
return - V_207 ;
}
V_2 -> V_84 = V_196 -> V_84 ;
F_101 ( V_196 ) ;
}
if ( ( V_96 = F_102 ( V_22 , V_208 , V_2 , & V_165 ) ) < 0 ) {
F_87 ( V_2 ) ;
return V_96 ;
}
#ifdef F_89
V_96 = F_103 ( & V_196 -> V_23 , & V_2 -> V_192 ) ;
if ( V_96 < 0 ) {
F_87 ( V_2 ) ;
return V_96 ;
}
V_2 -> V_120 . V_192 = & V_2 -> V_192 ;
V_2 -> V_120 . V_197 = V_197 ;
V_2 -> V_120 . V_21 = V_2 ;
V_2 -> V_120 . V_165 = & V_209 ;
sprintf ( V_2 -> V_120 . V_210 , L_12 , F_104 ( V_196 ) ) ;
if ( ( V_2 -> V_190 & V_211 ) > 0 &&
( V_2 -> V_190 & V_211 ) < 4 ) {
if ( F_105 ( & V_2 -> V_120 , V_212 ) ) {
F_13 ( V_22 -> V_23 , L_13 ) ;
F_87 ( V_2 ) ;
return - V_213 ;
}
} else if ( ( V_2 -> V_190 & V_211 ) == 0 ) {
unsigned int V_214 = V_2 -> V_190 & V_204 ;
for ( V_190 = 1 ; V_190 <= 3 ; V_190 ++ ) {
V_2 -> V_190 = V_190 ;
if ( ! F_105 ( & V_2 -> V_120 , V_212 ) ) {
F_99 ( V_22 -> V_23 ,
L_14 ,
F_57 ( V_2 ) -> V_116 ) ;
break;
}
}
if ( V_190 == 4 ) {
F_13 ( V_22 -> V_23 , L_13 ) ;
V_2 -> V_190 = V_191 ;
}
V_2 -> V_190 |= V_214 ;
}
if ( ! ( V_2 -> V_190 & V_191 ) ) {
F_106 ( V_2 -> V_120 . V_22 , F_57 ( V_2 ) -> V_116 ,
sizeof( V_2 -> V_120 . V_22 ) ) ;
}
#endif
* V_198 = V_2 ;
return 0 ;
}
static int F_107 ( struct V_108 * V_196 ,
const struct V_215 * V_216 )
{
static int V_23 ;
struct V_195 * V_22 ;
struct V_1 * V_2 ;
struct V_217 * V_218 ;
int V_96 ;
if ( V_23 >= V_219 )
return - V_213 ;
if ( ! V_220 [ V_23 ] ) {
V_23 ++ ;
return - V_221 ;
}
V_96 = F_108 ( & V_196 -> V_23 , V_222 [ V_23 ] , V_223 [ V_23 ] , V_212 ,
0 , & V_22 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ( V_96 = F_93 ( V_22 , V_196 , V_190 [ V_23 ] , V_197 [ V_23 ] , & V_2 ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
V_22 -> V_21 = V_2 ;
strcpy ( V_22 -> V_224 , L_4 ) ;
strcpy ( V_22 -> V_225 , L_15 ) ;
strcat ( V_22 -> V_225 , V_2 -> V_101 ? L_16 : L_17 ) ;
sprintf ( V_22 -> V_226 , L_18 ,
V_22 -> V_225 , V_2 -> V_5 , V_2 -> V_84 ) ;
if ( V_2 -> V_190 & V_204 )
goto V_227;
if ( ( V_96 = F_49 ( V_2 , 0 ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
if ( ( V_96 = F_76 ( V_2 ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
if ( ( V_96 = F_110 ( V_22 , 0 , V_228 ,
V_2 -> V_5 + V_229 ,
V_230 |
V_231 ,
- 1 , & V_2 -> V_94 ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
if ( ( V_96 = F_111 ( V_22 , V_2 -> V_5 + V_232 ,
V_2 -> V_5 + V_233 ,
V_234 , 1 , & V_218 ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
if ( ( V_96 = F_112 ( V_218 , 0 , 1 , NULL ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
V_227:
if ( ( V_96 = F_113 ( V_22 ) ) < 0 ) {
F_109 ( V_22 ) ;
return V_96 ;
}
F_114 ( V_196 , V_22 ) ;
V_23 ++ ;
return 0 ;
}
static void F_115 ( struct V_108 * V_196 )
{
F_109 ( F_116 ( V_196 ) ) ;
}
static int F_117 ( struct V_107 * V_23 )
{
struct V_195 * V_22 = F_118 ( V_23 ) ;
struct V_1 * V_2 = V_22 -> V_21 ;
int V_163 ;
F_119 ( V_22 , V_235 ) ;
for ( V_163 = 0 ; V_163 < F_17 ( V_236 ) ; V_163 ++ )
V_2 -> V_236 [ V_163 ] = F_3 ( V_2 , V_236 [ V_163 ] ) ;
if ( V_2 -> V_190 & V_204 ) {
} else {
F_120 ( V_2 -> V_91 ) ;
F_121 ( V_2 -> V_19 ) ;
F_121 ( V_2 -> V_161 ) ;
}
return 0 ;
}
static int F_122 ( struct V_107 * V_23 )
{
struct V_195 * V_22 = F_118 ( V_23 ) ;
struct V_1 * V_2 = V_22 -> V_21 ;
int V_163 ;
if ( V_2 -> V_190 & V_204 ) {
F_86 ( V_2 ) ;
} else {
F_83 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_123 ( V_2 -> V_19 ) ;
F_123 ( V_2 -> V_161 ) ;
}
for ( V_163 = 0 ; V_163 < F_17 ( V_236 ) ; V_163 ++ )
F_1 ( V_2 , V_236 [ V_163 ] , V_2 -> V_236 [ V_163 ] ) ;
#ifdef F_89
if ( ! ( V_2 -> V_190 & V_191 ) )
F_124 ( & V_2 -> V_120 ) ;
#endif
F_119 ( V_22 , V_237 ) ;
return 0 ;
}
