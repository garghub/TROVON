static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( ! ( F_2 ( V_2 , V_5 ) & V_6 ) )
return true ;
F_3 ( 10 ) ;
}
return false ;
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( F_2 ( V_2 , V_5 ) & V_7 )
return true ;
F_3 ( 10 ) ;
}
return false ;
}
static int F_5 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned short V_9 , unsigned short V_10 )
{
int V_11 ;
unsigned long V_12 ;
unsigned short V_13 , V_14 ;
F_6 ( & V_2 -> V_15 , V_12 ) ;
V_13 = F_7 ( V_2 -> V_16 + V_8 ) ;
V_14 = ( V_13 & ~ V_9 ) | V_10 ;
V_11 = V_13 != V_14 ;
if ( V_11 )
F_8 ( V_14 , V_2 -> V_16 + V_8 ) ;
F_9 ( & V_2 -> V_15 , V_12 ) ;
return V_11 ;
}
static void F_10 ( struct V_17 * V_18 ,
unsigned short V_8 ,
unsigned short V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
if ( ! F_1 ( V_2 , 100 ) ) {
F_11 ( V_2 -> V_21 -> V_22 , L_1 ) ;
return;
}
F_12 ( V_2 , V_23 , V_19 ) ;
F_12 ( V_2 , V_5 , V_8 | ( V_18 -> V_24 << V_25 ) ) ;
if ( ! F_1 ( V_2 , 1000 ) )
F_11 ( V_2 -> V_21 -> V_22 , L_2 ,
V_18 -> V_26 ) ;
}
static unsigned short F_13 ( struct V_17 * V_18 , unsigned short V_8 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
if ( ! F_1 ( V_2 , 100 ) ) {
F_11 ( V_2 -> V_21 -> V_22 , L_1 ) ;
return 0 ;
}
F_12 ( V_2 , V_5 ,
V_8 | ( V_18 -> V_24 << V_25 ) | V_27 ) ;
if ( ! F_1 ( V_2 , 100 ) ) {
F_11 ( V_2 -> V_21 -> V_22 , L_2 ,
V_18 -> V_26 ) ;
return 0 ;
}
if ( ! F_4 ( V_2 , 1000 ) ) {
F_11 ( V_2 -> V_21 -> V_22 ,
L_3 , V_18 -> V_26 ) ;
return 0 ;
}
return F_2 ( V_2 , V_23 ) ;
}
static unsigned short F_14 ( unsigned int V_28 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_15 ( V_29 ) ; V_4 ++ )
if ( V_29 [ V_4 ] == V_28 )
return V_4 ;
F_16 () ;
return F_15 ( V_29 ) - 1 ;
}
static int F_17 ( struct V_30 * V_31 ,
int V_32 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
F_19 ( & V_2 -> V_15 ) ;
switch ( V_32 ) {
case V_33 :
V_2 -> V_34 &= ~ ( V_35 |
V_36 |
V_37 ) ;
V_2 -> V_34 |= V_38 |
V_39 ;
break;
case V_40 :
V_2 -> V_34 &= ~ ( V_38 | V_37 ) ;
break;
case V_41 :
case V_42 :
V_2 -> V_34 |= V_37 ;
break;
case V_43 :
case V_44 :
V_2 -> V_34 &= ~ V_37 ;
break;
default:
F_20 ( & V_2 -> V_15 ) ;
F_16 () ;
return - V_45 ;
}
F_12 ( V_2 , V_46 , V_2 -> V_34 ) ;
F_20 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_31 ,
int V_32 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
F_19 ( & V_2 -> V_15 ) ;
switch ( V_32 ) {
case V_33 :
V_2 -> V_47 &= ~ ( V_35 |
V_36 |
V_37 ) ;
V_2 -> V_47 |= V_38 |
V_39 ;
break;
case V_40 :
V_2 -> V_47 &= ~ ( V_38 | V_37 ) ;
break;
case V_41 :
case V_42 :
V_2 -> V_47 |= V_37 ;
break;
case V_43 :
case V_44 :
V_2 -> V_47 &= ~ V_37 ;
break;
default:
F_20 ( & V_2 -> V_15 ) ;
F_16 () ;
return - V_45 ;
}
F_12 ( V_2 , V_48 , V_2 -> V_47 ) ;
F_20 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 ,
struct V_49 * V_50 )
{
return F_23 ( V_31 , F_24 ( V_50 ) ) ;
}
static int F_25 ( struct V_30 * V_31 )
{
return F_26 ( V_31 ) ;
}
static int F_27 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
struct V_51 * V_52 = V_31 -> V_52 ;
V_2 -> V_53 = F_28 ( V_31 ) ;
V_2 -> V_54 = F_29 ( V_31 ) ;
F_30 ( & V_2 -> V_15 ) ;
V_2 -> V_34 &= ~ ( V_38 | V_55 |
V_56 | V_57 |
V_58 ) ;
if ( F_31 ( V_52 -> V_59 ) == 16 )
V_2 -> V_34 |= V_55 ;
if ( V_52 -> V_60 > 1 ) {
V_2 -> V_34 |= V_56 ;
if ( V_52 -> V_60 == 4 )
V_2 -> V_34 |= V_61 ;
else if ( V_52 -> V_60 == 6 )
V_2 -> V_34 |= V_62 ;
}
V_2 -> V_34 |= F_14 ( V_52 -> V_28 ) << V_63 ;
V_2 -> V_64 = 0 ;
F_12 ( V_2 , V_46 , V_2 -> V_34 ) ;
F_12 ( V_2 , V_65 , V_2 -> V_54 - 1 ) ;
V_2 -> V_66 = V_52 -> V_67 ;
V_2 -> V_68 = 0 ;
F_32 ( V_2 , V_69 , V_2 -> V_66 ) ;
F_32 ( V_2 , V_70 ,
V_2 -> V_66 + ( V_2 -> V_54 % V_2 -> V_53 ) ) ;
F_33 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_34 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
struct V_51 * V_52 = V_31 -> V_52 ;
V_2 -> V_71 = F_28 ( V_31 ) ;
V_2 -> V_72 = F_29 ( V_31 ) ;
F_30 ( & V_2 -> V_15 ) ;
V_2 -> V_47 &= ~ ( V_38 | V_55 |
V_56 | V_57 ) ;
if ( F_31 ( V_52 -> V_59 ) == 16 )
V_2 -> V_47 |= V_55 ;
if ( V_52 -> V_60 > 1 )
V_2 -> V_47 |= V_56 ;
V_2 -> V_47 |= F_14 ( V_52 -> V_28 ) << V_63 ;
V_2 -> V_73 = 0 ;
F_12 ( V_2 , V_48 , V_2 -> V_47 ) ;
F_12 ( V_2 , V_74 , V_2 -> V_72 - 1 ) ;
V_2 -> V_75 = V_52 -> V_67 ;
V_2 -> V_76 = 0 ;
F_32 ( V_2 , V_77 , V_2 -> V_75 ) ;
F_32 ( V_2 , V_78 ,
V_2 -> V_75 + ( V_2 -> V_72 % V_2 -> V_71 ) ) ;
F_33 ( & V_2 -> V_15 ) ;
return 0 ;
}
static T_1 F_35 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
T_2 V_79 ;
if ( ! ( V_2 -> V_34 & V_38 ) )
return 0 ;
F_19 ( & V_2 -> V_15 ) ;
V_79 = V_2 -> V_68 + ( V_2 -> V_54 - 1 ) - F_2 ( V_2 , V_65 ) ;
if ( F_2 ( V_2 , V_80 ) & V_81 ) {
V_79 += V_2 -> V_54 ;
V_79 %= V_2 -> V_53 ;
}
F_20 ( & V_2 -> V_15 ) ;
return F_36 ( V_31 -> V_52 , V_79 ) ;
}
static T_1 F_37 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
T_2 V_79 ;
if ( ! ( V_2 -> V_47 & V_38 ) )
return 0 ;
F_19 ( & V_2 -> V_15 ) ;
V_79 = V_2 -> V_76 + ( V_2 -> V_72 - 1 ) - F_2 ( V_2 , V_74 ) ;
if ( F_2 ( V_2 , V_80 ) & V_82 ) {
V_79 += V_2 -> V_72 ;
V_79 %= V_2 -> V_71 ;
}
F_20 ( & V_2 -> V_15 ) ;
return F_36 ( V_31 -> V_52 , V_79 ) ;
}
static T_3 F_38 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
unsigned short V_85 ;
unsigned int V_86 ;
V_85 = F_2 ( V_2 , V_80 ) ;
V_85 &= V_81 | V_82 | V_87 | V_88 ;
if ( ! V_85 )
return V_89 ;
F_12 ( V_2 , V_80 , V_85 ) ;
if ( V_2 -> V_90 && ( V_85 & V_81 ) && V_2 -> V_91 ) {
F_19 ( & V_2 -> V_15 ) ;
V_2 -> V_64 ++ ;
V_2 -> V_68 += V_2 -> V_54 ;
V_2 -> V_68 %= V_2 -> V_53 ;
V_86 = V_2 -> V_68 + V_2 -> V_54 ;
V_86 %= V_2 -> V_53 ;
if ( V_2 -> V_64 & 1 )
F_32 ( V_2 , V_69 , V_2 -> V_66 + V_86 ) ;
else
F_32 ( V_2 , V_70 , V_2 -> V_66 + V_86 ) ;
F_20 ( & V_2 -> V_15 ) ;
F_39 ( V_2 -> V_91 ) ;
}
if ( V_2 -> V_90 && ( V_85 & V_82 ) && V_2 -> V_92 ) {
F_19 ( & V_2 -> V_15 ) ;
V_2 -> V_73 ++ ;
V_2 -> V_76 += V_2 -> V_72 ;
V_2 -> V_76 %= V_2 -> V_71 ;
V_86 = V_2 -> V_76 + V_2 -> V_72 ;
V_86 %= V_2 -> V_71 ;
if ( V_2 -> V_73 & 1 )
F_32 ( V_2 , V_77 , V_2 -> V_75 + V_86 ) ;
else
F_32 ( V_2 , V_78 , V_2 -> V_75 + V_86 ) ;
F_20 ( & V_2 -> V_15 ) ;
F_39 ( V_2 -> V_92 ) ;
}
if ( V_2 -> V_93 && ( V_85 & V_87 ) )
F_40 ( V_83 , V_2 -> V_93 -> V_20 ) ;
if ( V_85 & V_88 )
;
return V_94 ;
}
static int F_41 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
struct V_51 * V_52 = V_31 -> V_52 ;
int V_95 ;
V_2 -> V_91 = V_31 ;
V_52 -> V_96 = V_97 ;
F_42 ( V_52 , 0 , V_98 ,
& V_99 ) ;
if ( V_2 -> V_100 ) {
V_52 -> V_96 . V_101 = 6 ;
F_42 ( V_52 , 0 ,
V_102 ,
& V_103 ) ;
}
if ( ( V_95 = F_43 ( V_52 , V_104 ) ) < 0 )
return V_95 ;
return 0 ;
}
static int F_44 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
struct V_51 * V_52 = V_31 -> V_52 ;
int V_95 ;
V_2 -> V_92 = V_31 ;
V_52 -> V_96 = V_105 ;
F_42 ( V_52 , 0 , V_98 ,
& V_99 ) ;
if ( ( V_95 = F_43 ( V_52 , V_104 ) ) < 0 )
return V_95 ;
return 0 ;
}
static int F_45 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
V_2 -> V_91 = NULL ;
return 0 ;
}
static int F_46 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
V_2 -> V_92 = NULL ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_106 )
{
struct V_107 * V_90 ;
int V_95 ;
if ( ( V_95 = F_48 ( V_2 -> V_21 , L_4 , V_106 , 1 , 1 , & V_90 ) ) < 0 )
return V_95 ;
F_49 ( V_90 , V_108 , & V_109 ) ;
F_49 ( V_90 , V_110 , & V_111 ) ;
V_90 -> V_20 = V_2 ;
V_90 -> V_112 = 0 ;
strcpy ( V_90 -> V_113 , L_4 ) ;
V_2 -> V_90 = V_90 ;
F_50 ( V_90 , V_114 ,
F_51 ( V_2 -> V_115 ) ,
V_2 -> V_100 ? 128 * 1024 : 64 * 1024 , 128 * 1024 ) ;
return F_52 ( V_90 , V_108 ,
V_116 ,
V_2 -> V_100 ? 6 : 2 , 0 ,
NULL ) ;
}
static void F_53 ( struct V_117 * V_118 , T_4 V_119 )
{
struct V_1 * V_2 = V_118 -> V_20 ;
unsigned short V_8 = F_2 ( V_2 , V_120 ) ;
struct V_121 V_122 = * F_54 ( V_2 ) ;
V_8 &= ~ ( F_55 ( V_122 . V_123 ) |
F_55 ( V_122 . V_124 ) |
F_55 ( V_122 . V_125 ) ) ;
V_8 |= ( V_119 & V_126 ) ? F_55 ( V_122 . V_123 ) : 0 ;
V_8 |= ( V_119 & V_127 ) ? F_55 ( V_122 . V_124 ) : 0 ;
V_8 |= ( V_119 & V_128 ) ? 0 : F_55 ( V_122 . V_125 ) ;
F_12 ( V_2 , V_120 , V_8 ) ;
}
static T_4 F_56 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_20 ;
unsigned short V_8 = F_2 ( V_2 , V_120 ) ;
struct V_121 V_122 = * F_54 ( V_2 ) ;
T_4 V_129 ;
V_129 = 0 ;
if ( V_8 & F_55 ( V_122 . V_123 ) )
V_129 |= V_126 ;
if ( V_8 & F_55 ( V_122 . V_130 ) )
V_129 |= V_131 ;
return V_129 ;
}
static void F_57 ( struct V_117 * V_118 , bool V_132 )
{
struct V_1 * V_2 = V_118 -> V_20 ;
unsigned short V_8 = F_2 ( V_2 , V_120 ) ;
struct V_121 V_122 = * F_54 ( V_2 ) ;
V_8 |= F_58 ( V_122 . V_123 ) |
F_58 ( V_122 . V_125 ) |
F_58 ( V_122 . V_124 ) |
F_58 ( V_122 . V_130 ) ;
if ( V_132 ) {
V_8 &= ~ ( F_59 ( V_122 . V_123 ) |
F_59 ( V_122 . V_125 ) |
F_59 ( V_122 . V_124 ) |
F_55 ( V_122 . V_123 ) |
F_55 ( V_122 . V_124 ) |
F_55 ( V_122 . V_125 ) ) ;
} else {
V_8 |= F_59 ( V_122 . V_123 ) |
F_59 ( V_122 . V_130 ) |
F_55 ( V_122 . V_123 ) |
F_55 ( V_122 . V_130 ) |
F_55 ( V_122 . V_125 ) ;
V_8 &= ~ ( F_59 ( V_122 . V_125 ) |
F_59 ( V_122 . V_124 ) |
F_55 ( V_122 . V_124 ) ) ;
}
F_12 ( V_2 , V_120 , V_8 ) ;
}
static int F_60 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
int V_9 = ( V_134 -> V_137 >> 16 ) & 0xff ;
V_136 -> type = V_9 == 1 ? V_138 : V_139 ;
V_136 -> V_140 = 1 ;
V_136 -> V_10 . integer . V_141 = 0 ;
V_136 -> V_10 . integer . V_142 = V_9 ;
return 0 ;
}
static int F_61 ( struct V_133 * V_134 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_62 ( V_134 ) ;
int V_8 = V_134 -> V_137 & 0xff ;
int V_145 = ( V_134 -> V_137 >> 8 ) & 0xff ;
int V_9 = ( V_134 -> V_137 >> 16 ) & 0xff ;
int V_146 = ( V_134 -> V_137 >> 24 ) & 0xff ;
V_144 -> V_10 . integer . V_10 [ 0 ] = ( F_7 ( V_2 -> V_16 + V_8 ) >> V_145 ) & V_9 ;
if ( V_146 )
V_144 -> V_10 . integer . V_10 [ 0 ] = V_9 - V_144 -> V_10 . integer . V_10 [ 0 ] ;
return 0 ;
}
static int F_63 ( struct V_133 * V_134 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_62 ( V_134 ) ;
int V_8 = V_134 -> V_137 & 0xff ;
int V_145 = ( V_134 -> V_137 >> 8 ) & 0xff ;
int V_9 = ( V_134 -> V_137 >> 16 ) & 0xff ;
int V_146 = ( V_134 -> V_137 >> 24 ) & 0xff ;
unsigned short V_19 ;
V_19 = ( V_144 -> V_10 . integer . V_10 [ 0 ] & V_9 ) ;
if ( V_146 )
V_19 = V_9 - V_19 ;
return F_5 ( V_2 , V_8 , V_9 << V_145 , V_19 << V_145 ) ;
}
static int F_64 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
int V_9 = ( V_134 -> V_137 >> 16 ) & 0xff ;
V_136 -> type = V_9 == 1 ? V_138 : V_139 ;
V_136 -> V_140 = 2 ;
V_136 -> V_10 . integer . V_141 = 0 ;
V_136 -> V_10 . integer . V_142 = V_9 ;
return 0 ;
}
static int F_65 ( struct V_133 * V_134 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_62 ( V_134 ) ;
int V_8 = V_134 -> V_137 & 0xff ;
int V_147 = ( V_134 -> V_137 >> 8 ) & 0x0f ;
int V_148 = ( V_134 -> V_137 >> 12 ) & 0x0f ;
int V_9 = ( V_134 -> V_137 >> 16 ) & 0xff ;
int V_146 = ( V_134 -> V_137 >> 24 ) & 0xff ;
F_30 ( & V_2 -> V_15 ) ;
V_144 -> V_10 . integer . V_10 [ 0 ] = ( F_7 ( V_2 -> V_16 + V_8 ) >> V_147 ) & V_9 ;
V_144 -> V_10 . integer . V_10 [ 1 ] = ( F_7 ( V_2 -> V_16 + V_8 ) >> V_148 ) & V_9 ;
F_33 ( & V_2 -> V_15 ) ;
if ( V_146 ) {
V_144 -> V_10 . integer . V_10 [ 0 ] = V_9 - V_144 -> V_10 . integer . V_10 [ 0 ] ;
V_144 -> V_10 . integer . V_10 [ 1 ] = V_9 - V_144 -> V_10 . integer . V_10 [ 1 ] ;
}
return 0 ;
}
static int F_66 ( struct V_133 * V_134 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_62 ( V_134 ) ;
int V_8 = V_134 -> V_137 & 0xff ;
int V_147 = ( V_134 -> V_137 >> 8 ) & 0x0f ;
int V_148 = ( V_134 -> V_137 >> 12 ) & 0x0f ;
int V_9 = ( V_134 -> V_137 >> 16 ) & 0xff ;
int V_146 = ( V_134 -> V_137 >> 24 ) & 0xff ;
unsigned short V_149 , V_150 ;
V_149 = V_144 -> V_10 . integer . V_10 [ 0 ] & V_9 ;
V_150 = V_144 -> V_10 . integer . V_10 [ 1 ] & V_9 ;
if ( V_146 ) {
V_149 = V_9 - V_149 ;
V_150 = V_9 - V_150 ;
}
return F_5 ( V_2 , V_8 ,
( V_9 << V_147 ) | ( V_9 << V_148 ) ,
( V_149 << V_147 ) | ( V_150 << V_148 ) ) ;
}
static int F_67 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
static const char * const V_151 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
return F_68 ( V_136 , 1 , 5 , V_151 ) ;
}
static int F_69 ( struct V_133 * V_134 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_62 ( V_134 ) ;
unsigned short V_19 ;
V_19 = F_2 ( V_2 , V_152 ) & 7 ;
if ( V_19 > 4 )
V_19 = 4 ;
V_144 -> V_10 . V_153 . V_154 [ 0 ] = V_19 ;
return 0 ;
}
static int F_70 ( struct V_133 * V_134 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_62 ( V_134 ) ;
unsigned short V_19 ;
if ( ( V_19 = V_144 -> V_10 . V_153 . V_154 [ 0 ] ) > 4 )
return - V_45 ;
return F_5 ( V_2 , V_155 , 7 , V_19 ) ;
}
static void F_71 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = V_157 -> V_20 ;
V_2 -> V_158 = NULL ;
}
static void F_72 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
if ( V_18 -> V_26 == 0 ) {
V_2 -> V_18 = NULL ;
} else {
V_2 -> V_159 = NULL ;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_160 V_18 ;
unsigned int V_161 ;
int V_95 ;
static struct V_162 V_163 = {
. V_164 = F_10 ,
. V_165 = F_13 ,
} ;
if ( ( V_95 = V_156 ( V_2 -> V_21 , 0 , & V_163 , V_2 , & V_2 -> V_158 ) ) < 0 )
return V_95 ;
V_2 -> V_158 -> V_166 = F_71 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_20 = V_2 ;
V_18 . V_166 = F_72 ;
if ( ( V_95 = F_74 ( V_2 -> V_158 , & V_18 , & V_2 -> V_18 ) ) < 0 )
return V_95 ;
if ( V_2 -> V_167 ) {
V_18 . V_26 = 1 ;
V_18 . V_24 = V_2 -> V_168 ;
if ( ( V_95 = F_74 ( V_2 -> V_158 , & V_18 , & V_2 -> V_159 ) ) < 0 )
return V_95 ;
}
for ( V_161 = 0 ; V_161 < V_169 ; V_161 ++ )
F_75 ( V_2 -> V_21 , F_76 ( & V_170 [ V_161 ] , V_2 ) ) ;
if ( V_2 -> V_100 ) {
for ( V_161 = 0 ; V_161 < V_171 ; V_161 ++ )
F_75 ( V_2 -> V_21 , F_76 ( & V_172 [ V_161 ] , V_2 ) ) ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , unsigned int V_173 ,
unsigned short V_8 , unsigned long V_174 )
{
unsigned long V_175 = V_176 + V_174 ;
F_12 ( V_2 , V_5 ,
V_8 | ( V_173 << V_25 ) | V_27 ) ;
F_3 ( 5 ) ;
do {
if ( ( F_2 ( V_2 , V_5 ) &
( V_7 | V_6 ) ) == V_7 )
return 0 ;
F_78 ( 1 ) ;
} while ( F_79 ( V_175 , V_176 ) );
return - V_177 ;
}
static int F_80 ( struct V_1 * V_2 , int V_178 )
{
unsigned short V_179 ;
if ( V_2 -> V_180 & V_181 )
goto V_182;
F_12 ( V_2 , V_183 , ( 1 << 5 ) | ( 1 << 6 ) ) ;
F_2 ( V_2 , V_183 ) ;
F_3 ( 100 ) ;
F_12 ( V_2 , V_183 , 0 ) ;
if ( F_77 ( V_2 , 0 , V_184 , F_81 ( 750 ) ) < 0 )
if ( ! V_178 ) {
F_82 ( V_2 -> V_21 -> V_22 ,
L_10 ) ;
V_2 -> V_180 = 3 | V_181 ;
goto V_182;
}
if ( V_2 -> V_100 ) {
if ( V_2 -> V_168 ) {
F_77 ( V_2 , V_2 -> V_168 ,
V_185 , F_81 ( 50 ) ) ;
} else {
int V_161 ;
for ( V_161 = 3 ; V_161 > 0 ; V_161 -- ) {
if ( ! F_77 ( V_2 , V_161 , V_185 ,
F_81 ( 50 ) ) ) {
V_179 = F_2 ( V_2 , V_23 ) ;
if ( V_179 != 0xffff && V_179 != 0 ) {
V_2 -> V_167 = 1 ;
V_2 -> V_168 = V_161 ;
break;
}
}
}
}
F_77 ( V_2 , 0 , V_185 , F_81 ( 750 ) ) ;
}
V_182:
F_12 ( V_2 , V_186 , 0x0808 ) ;
F_12 ( V_2 , V_187 , 0x9f1f ) ;
F_12 ( V_2 , V_188 , 0x8808 ) ;
F_12 ( V_2 , V_189 , 0x0003 ) ;
V_179 = F_2 ( V_2 , V_190 ) ;
if ( V_2 -> V_83 < 0 )
V_179 |= 0x00c3 ;
else
V_179 &= ~ 0x0083 ;
F_12 ( V_2 , V_190 , V_179 ) ;
F_12 ( V_2 , V_80 ,
V_81 | V_82 | V_87 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
unsigned short V_179 ;
if ( V_2 -> V_83 < 0 )
goto V_191;
V_179 = F_2 ( V_2 , V_190 ) ;
V_179 |= 0x00c3 ;
F_12 ( V_2 , V_190 , V_179 ) ;
V_191:
#ifdef F_84
if ( ! ( V_2 -> V_180 & V_192 ) ) {
F_85 ( & V_2 -> V_118 ) ;
F_86 ( & V_2 -> V_193 ) ;
}
#endif
return 0 ;
}
static int F_87 ( struct V_194 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_195 ;
return F_83 ( V_2 ) ;
}
static int F_88 ( struct V_196 * V_21 ,
struct V_197 * V_115 ,
int V_180 ,
int V_198 ,
struct V_1 * * V_199 )
{
struct V_1 * V_2 ;
int V_95 ;
static struct V_200 V_163 = {
. V_201 = F_87 ,
} ;
* V_199 = NULL ;
if ( ( V_95 = F_89 ( V_115 ) ) < 0 )
return V_95 ;
V_2 = F_90 ( & V_115 -> V_22 , sizeof( * V_2 ) , V_202 ) ;
if ( V_2 == NULL )
return - V_203 ;
F_91 ( & V_2 -> V_15 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_115 = V_115 ;
V_2 -> V_83 = - 1 ;
V_2 -> V_180 = V_180 ;
if ( ( V_95 = F_92 ( V_115 , L_4 ) ) < 0 )
return V_95 ;
V_2 -> V_16 = F_93 ( V_115 , 0 ) ;
if ( ( V_180 & V_181 ) == 0 ) {
if ( F_94 ( & V_115 -> V_22 , V_115 -> V_83 , F_38 ,
V_204 , V_205 , V_2 ) ) {
F_11 ( V_21 -> V_22 , L_11 , V_115 -> V_83 ) ;
F_83 ( V_2 ) ;
return - V_206 ;
}
V_2 -> V_83 = V_115 -> V_83 ;
F_95 ( V_115 ) ;
}
if ( V_115 -> V_207 >= 0xb1 )
V_2 -> V_100 = 1 ;
F_80 ( V_2 , 0 ) ;
V_180 = V_2 -> V_180 ;
if ( ( V_95 = F_96 ( V_21 , V_208 , V_2 , & V_163 ) ) < 0 ) {
F_83 ( V_2 ) ;
return V_95 ;
}
#ifdef F_84
V_95 = F_97 ( & V_115 -> V_22 , & V_2 -> V_193 ) ;
if ( V_95 < 0 ) {
F_83 ( V_2 ) ;
return V_95 ;
}
V_2 -> V_118 . V_193 = & V_2 -> V_193 ;
V_2 -> V_118 . V_198 = V_198 ;
V_2 -> V_118 . V_20 = V_2 ;
V_2 -> V_118 . V_163 = & V_209 ;
sprintf ( V_2 -> V_118 . V_210 , L_12 , F_98 ( V_115 ) ) ;
if ( ( V_180 & V_211 ) > 0 &&
( V_180 & V_211 ) < 4 ) {
if ( F_99 ( & V_2 -> V_118 , V_212 ) ) {
F_11 ( V_21 -> V_22 , L_13 ) ;
F_83 ( V_2 ) ;
return - V_213 ;
}
} else if ( ( V_180 & V_211 ) == 0 ) {
for ( V_180 = 1 ; V_180 <= 3 ; V_180 ++ ) {
V_2 -> V_180 = V_180 ;
if ( ! F_99 ( & V_2 -> V_118 , V_212 ) ) {
F_82 ( V_21 -> V_22 ,
L_14 ,
F_54 ( V_2 ) -> V_113 ) ;
break;
}
}
if ( V_180 == 4 ) {
F_11 ( V_21 -> V_22 , L_13 ) ;
V_2 -> V_180 = V_192 ;
}
}
if ( ! ( V_2 -> V_180 & V_192 ) ) {
F_100 ( V_2 -> V_118 . V_21 , F_54 ( V_2 ) -> V_113 ,
sizeof( V_2 -> V_118 . V_21 ) ) ;
}
#endif
* V_199 = V_2 ;
return 0 ;
}
static int F_101 ( struct V_197 * V_115 ,
const struct V_214 * V_215 )
{
static int V_22 ;
struct V_196 * V_21 ;
struct V_1 * V_2 ;
struct V_216 * V_217 ;
int V_95 ;
if ( V_22 >= V_218 )
return - V_213 ;
if ( ! V_219 [ V_22 ] ) {
V_22 ++ ;
return - V_220 ;
}
V_95 = F_102 ( & V_115 -> V_22 , V_221 [ V_22 ] , V_222 [ V_22 ] , V_212 ,
0 , & V_21 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ( V_95 = F_88 ( V_21 , V_115 , V_180 [ V_22 ] , V_198 [ V_22 ] , & V_2 ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
V_21 -> V_20 = V_2 ;
strcpy ( V_21 -> V_223 , L_4 ) ;
strcpy ( V_21 -> V_224 , L_15 ) ;
strcat ( V_21 -> V_224 , V_2 -> V_100 ? L_16 : L_17 ) ;
sprintf ( V_21 -> V_225 , L_18 ,
V_21 -> V_224 , V_2 -> V_16 , V_2 -> V_83 ) ;
if ( V_2 -> V_180 & V_181 )
goto V_226;
if ( ( V_95 = F_47 ( V_2 , 0 ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
if ( ( V_95 = F_73 ( V_2 ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
if ( ( V_95 = F_104 ( V_21 , 0 , V_227 ,
V_2 -> V_16 + V_228 ,
V_229 |
V_230 ,
- 1 , & V_2 -> V_93 ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
if ( ( V_95 = F_105 ( V_21 , V_2 -> V_16 + V_231 ,
V_2 -> V_16 + V_232 ,
V_233 , 1 , & V_217 ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
if ( ( V_95 = F_106 ( V_217 , 0 , 1 , NULL ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
V_226:
if ( ( V_95 = F_107 ( V_21 ) ) < 0 ) {
F_103 ( V_21 ) ;
return V_95 ;
}
F_108 ( V_115 , V_21 ) ;
V_22 ++ ;
return 0 ;
}
static void F_109 ( struct V_197 * V_115 )
{
F_103 ( F_110 ( V_115 ) ) ;
}
static int F_111 ( struct V_106 * V_22 )
{
struct V_196 * V_21 = F_112 ( V_22 ) ;
struct V_1 * V_2 = V_21 -> V_20 ;
int V_161 ;
F_113 ( V_21 , V_234 ) ;
F_114 ( V_2 -> V_90 ) ;
F_115 ( V_2 -> V_18 ) ;
F_115 ( V_2 -> V_159 ) ;
for ( V_161 = 0 ; V_161 < F_15 ( V_235 ) ; V_161 ++ )
V_2 -> V_235 [ V_161 ] = F_7 ( V_2 -> V_16 + V_235 [ V_161 ] ) ;
return 0 ;
}
static int F_116 ( struct V_106 * V_22 )
{
struct V_196 * V_21 = F_112 ( V_22 ) ;
struct V_1 * V_2 = V_21 -> V_20 ;
int V_161 ;
F_80 ( V_2 , 1 ) ;
F_117 ( V_2 -> V_18 ) ;
F_117 ( V_2 -> V_159 ) ;
for ( V_161 = 0 ; V_161 < F_15 ( V_235 ) ; V_161 ++ )
F_8 ( V_2 -> V_235 [ V_161 ] , V_2 -> V_16 + V_235 [ V_161 ] ) ;
F_113 ( V_21 , V_236 ) ;
return 0 ;
}
