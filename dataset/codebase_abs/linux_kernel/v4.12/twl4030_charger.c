static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
if ( ! V_2 )
return 0 ;
V_4 = F_2 ( V_2 , & V_3 ) ;
if ( V_4 < 0 )
return 0 ;
return V_3 > 4500 ;
}
static int F_3 ( T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
T_1 V_3 = 0 ;
int V_9 ;
V_9 = F_4 ( V_5 , & V_3 , V_8 ) ;
if ( V_9 )
return V_9 ;
V_3 &= ~ V_6 ;
V_3 |= V_7 ;
return F_5 ( V_5 , V_3 , V_8 ) ;
}
static int F_6 ( T_1 V_8 , T_1 * V_3 )
{
return F_4 ( V_10 , V_3 , V_8 ) ;
}
static int F_7 ( T_1 V_6 , T_1 V_7 )
{
return F_3 ( V_11 , V_6 ,
V_12 | V_13 | V_7 ,
V_14 ) ;
}
static int F_8 ( T_1 V_8 )
{
int V_9 , V_15 ;
T_1 V_3 ;
V_9 = F_6 ( V_8 + 1 , & V_3 ) ;
if ( V_9 )
return V_9 ;
V_15 = ( int ) ( V_3 & 0x03 ) << 8 ;
V_9 = F_6 ( V_8 , & V_3 ) ;
if ( V_9 )
return V_9 ;
return V_15 | V_3 ;
}
static int F_9 ( int V_16 , bool V_17 )
{
if ( V_17 )
return ( V_16 * 16618 - 8500 * 1000 ) / 5 ;
else
return ( V_16 * 16618 - 8500 * 1000 ) / 10 ;
}
static int F_10 ( int V_18 , bool V_17 )
{
int V_9 ;
if ( V_17 )
V_18 /= 2 ;
V_9 = ( V_18 * 10 + 8500 * 1000 ) / 16618 ;
if ( V_9 < 512 )
V_9 = 512 ;
return V_9 ;
}
static int F_11 ( struct V_19 * V_20 )
{
int V_21 ;
int V_22 ;
unsigned V_8 , V_23 ;
T_1 V_24 , V_25 , V_26 ;
bool V_17 = false ;
T_1 V_27 ;
if ( F_1 ( V_20 -> V_2 ) ) {
V_22 = V_20 -> V_28 ;
V_20 -> V_29 = true ;
} else {
V_22 = V_20 -> V_30 ;
V_20 -> V_29 = false ;
if ( V_22 > V_20 -> V_31 ) {
V_22 = V_20 -> V_31 ;
V_20 -> V_30 = V_22 ;
}
if ( V_22 < V_20 -> V_31 )
F_12 ( & V_20 -> V_32 , V_33 ) ;
}
if ( V_20 -> V_34 >= 200000 )
V_17 = true ;
if ( V_20 -> V_35 >= 400000 )
V_17 = true ;
if ( V_20 -> V_36 >= 820000 )
V_17 = true ;
if ( V_22 > 852000 )
V_17 = true ;
V_21 = F_6 ( V_37 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( F_4 ( V_11 , & V_27 ,
V_14 ) < 0 )
V_27 = 0 ;
V_27 &= 7 ;
if ( ( ! ! V_17 ) != ! ! ( V_24 & V_38 ) )
F_7 ( V_27 , 0 ) ;
V_8 = F_10 ( V_20 -> V_34 , V_17 ) ;
if ( V_8 > 0x278 )
V_8 = 0x278 ;
if ( V_8 < 0x200 )
V_8 = 0x200 ;
V_8 = ( V_8 >> 3 ) & 0xf ;
V_26 = V_8 << 4 ;
V_8 = F_10 ( V_20 -> V_35 , V_17 ) ;
if ( V_8 > 0x2F0 )
V_8 = 0x2F0 ;
if ( V_8 < 0x200 )
V_8 = 0x200 ;
V_8 = ( V_8 >> 4 ) & 0xf ;
V_26 |= V_8 ;
V_21 = F_6 ( V_39 , & V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_25 != V_26 ) {
V_21 = F_5 ( V_10 , 0xF4 ,
V_40 ) ;
if ( V_21 < 0 )
return V_21 ;
F_5 ( V_10 ,
V_26 , V_39 ) ;
}
V_8 = F_10 ( V_20 -> V_36 , V_17 ) ;
if ( V_8 > 0x3E0 )
V_8 = 0x3E0 ;
if ( V_8 < 0x200 )
V_8 = 0x200 ;
V_26 = ( V_8 >> 5 ) & 0xF ;
V_26 <<= 4 ;
V_21 = F_6 ( V_41 , & V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ( V_25 & 0xF0 ) != V_26 ) {
V_26 |= ( V_25 & 0x0F ) ;
V_21 = F_5 ( V_10 , 0xE7 ,
V_40 ) ;
if ( V_21 < 0 )
return V_21 ;
F_5 ( V_10 ,
V_26 , V_41 ) ;
}
V_8 = F_10 ( V_22 , V_17 ) ;
if ( V_8 > 0x3ff )
V_8 = 0x3ff ;
V_21 = F_6 ( V_42 , & V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
V_23 = V_25 ;
V_21 = F_6 ( V_43 , & V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
V_23 |= V_25 << 8 ;
if ( V_8 != V_25 ) {
V_21 = F_5 ( V_10 , 0xE7 ,
V_40 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_5 ( V_10 ,
( V_8 & 0x100 ) ? 3 : 2 ,
V_43 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_5 ( V_10 , 0xE7 ,
V_40 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_5 ( V_10 ,
V_8 & 0xff ,
V_42 ) ;
}
if ( ( ! ! V_17 ) != ! ! ( V_24 & V_38 ) ) {
V_24 ^= V_38 ;
F_5 ( V_10 ,
V_24 , V_37 ) ;
F_7 ( 0 , V_27 ) ;
}
return 0 ;
}
static void F_13 ( struct V_44 * V_45 )
{
int V_46 , V_47 ;
int V_48 ;
struct V_19 * V_20 = F_14 ( V_45 , struct V_19 ,
V_32 . V_49 ) ;
V_48 = F_8 ( V_50 ) ;
if ( V_48 < 0 )
V_46 = 0 ;
else
V_46 = V_48 * 6843 ;
V_47 = F_15 () ;
F_16 ( V_20 -> V_51 , L_1 , V_46 , V_47 ,
V_20 -> V_30 , V_20 -> V_31 ) ;
if ( V_46 < V_52 ) {
V_20 -> V_30 -= V_53 ;
V_20 -> V_31 = V_20 -> V_30 ;
} else if ( V_20 -> V_30 >= V_20 -> V_31 ||
V_20 -> V_30 + V_53 > V_54 ) {
return;
} else {
V_20 -> V_30 += V_53 ;
F_12 ( & V_20 -> V_32 , V_33 ) ;
}
F_11 ( V_20 ) ;
}
static int F_17 ( struct V_19 * V_20 , bool V_55 )
{
int V_9 ;
if ( V_20 -> V_56 == V_57 )
V_55 = false ;
if ( V_55 && ! F_18 ( V_20 -> V_58 ) ) {
F_11 ( V_20 ) ;
if ( ! V_20 -> V_59 ) {
F_19 ( V_20 -> V_58 -> V_51 ) ;
V_20 -> V_59 = 1 ;
}
if ( V_20 -> V_56 == V_60 )
V_9 = F_7 ( 0 , V_61 ) ;
V_9 = F_3 ( V_10 , 0 ,
V_62 , V_63 ) ;
if ( V_20 -> V_56 == V_64 ) {
F_7 ( V_65 | V_66 , 0 ) ;
V_9 = F_5 ( V_10 , 0x33 ,
V_67 ) ;
V_9 = F_5 ( V_10 , 0x2a ,
V_68 ) ;
V_9 = F_5 ( V_10 , 0x26 ,
V_68 ) ;
V_9 = F_5 ( V_10 , 0xf3 ,
V_67 ) ;
V_9 = F_5 ( V_10 , 0x9c ,
V_40 ) ;
V_9 = F_5 ( V_10 , 0xf0 ,
V_69 ) ;
}
} else {
V_9 = F_7 ( V_61 , 0 ) ;
V_9 |= F_5 ( V_10 , 0x2a ,
V_68 ) ;
if ( V_20 -> V_59 ) {
F_20 ( V_20 -> V_58 -> V_51 ) ;
F_21 ( V_20 -> V_58 -> V_51 ) ;
V_20 -> V_59 = 0 ;
}
V_20 -> V_30 = 0 ;
}
return V_9 ;
}
static int F_22 ( struct V_19 * V_20 , bool V_55 )
{
int V_9 ;
if ( V_20 -> V_70 == V_57 )
V_55 = false ;
if ( V_55 )
V_9 = F_7 ( 0 , V_65 ) ;
else
V_9 = F_7 ( V_65 , 0 ) ;
return V_9 ;
}
static int F_23 ( int V_71 , int V_72 )
{
int V_9 ;
T_1 V_73 ;
if ( V_71 < 2500000 ||
V_72 < 25 ) {
V_9 = F_3 ( V_74 ,
V_75 , 0 , V_76 ) ;
return V_9 ;
}
V_73 = V_75 ;
if ( V_71 >= 3200000 )
V_73 |= V_77 ;
else if ( V_71 >= 3100000 )
V_73 |= V_78 ;
else if ( V_71 >= 3000000 )
V_73 |= V_79 ;
else
V_73 |= V_80 ;
if ( V_72 >= 1000 )
V_73 |= V_81 ;
else if ( V_72 >= 500 )
V_73 |= V_82 ;
else if ( V_72 >= 150 )
V_73 |= V_83 ;
else
V_73 |= V_84 ;
V_9 = F_3 ( V_74 ,
V_85 | V_86 ,
V_73 ,
V_76 ) ;
return V_9 ;
}
static T_2 F_24 ( int V_87 , void * V_88 )
{
struct V_19 * V_20 = V_88 ;
F_16 ( V_20 -> V_51 , L_2 ) ;
V_20 -> V_28 = 500000 ;
F_11 ( V_20 ) ;
F_25 ( V_20 -> V_89 ) ;
F_25 ( V_20 -> V_90 ) ;
return V_91 ;
}
static T_2 F_26 ( int V_87 , void * V_88 )
{
struct V_19 * V_20 = V_88 ;
T_1 V_92 , V_93 ;
int V_9 ;
V_9 = F_4 ( V_94 , & V_92 ,
V_95 ) ;
if ( V_9 < 0 )
return V_91 ;
V_9 = F_4 ( V_94 , & V_93 ,
V_96 ) ;
if ( V_9 < 0 )
return V_91 ;
F_16 ( V_20 -> V_51 , L_3 , V_93 , V_92 ) ;
if ( V_92 & ( V_97 | V_98 ) ) {
F_25 ( V_20 -> V_89 ) ;
F_25 ( V_20 -> V_90 ) ;
}
F_11 ( V_20 ) ;
if ( V_92 & ( V_99 | V_100 ) )
F_27 ( V_20 -> V_51 , L_4 ) ;
if ( V_92 & V_101 )
F_28 ( V_20 -> V_51 , L_5 ) ;
if ( V_93 & V_102 )
F_28 ( V_20 -> V_51 , L_6 ) ;
if ( V_93 & V_103 )
F_28 ( V_20 -> V_51 , L_7 ) ;
if ( V_93 & V_104 )
F_28 ( V_20 -> V_51 , L_8 ) ;
return V_91 ;
}
static T_3
F_29 ( struct V_105 * V_51 , struct V_106 * V_107 ,
const char * V_108 , T_4 V_109 )
{
struct V_19 * V_20 = F_30 ( V_51 -> V_110 ) ;
int V_22 = 0 ;
int V_21 = 0 ;
V_21 = F_31 ( V_108 , 10 , & V_22 ) ;
if ( V_21 )
return V_21 ;
if ( V_22 < 0 )
return - V_111 ;
if ( V_51 == & V_20 -> V_89 -> V_51 )
V_20 -> V_28 = V_22 ;
else
V_20 -> V_31 = V_22 ;
F_11 ( V_20 ) ;
return V_109 ;
}
static T_3 F_32 ( struct V_105 * V_51 ,
struct V_106 * V_107 , char * V_108 )
{
int V_21 = 0 ;
int V_22 = - 1 ;
T_1 V_24 ;
struct V_19 * V_20 = F_30 ( V_51 -> V_110 ) ;
if ( V_51 == & V_20 -> V_89 -> V_51 ) {
if ( ! V_20 -> V_29 )
V_22 = V_20 -> V_28 ;
} else {
if ( V_20 -> V_29 )
V_22 = V_20 -> V_31 ;
}
if ( V_22 < 0 ) {
V_22 = F_8 ( V_42 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_6 ( V_37 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
V_22 = F_9 ( V_22 , V_24 & V_38 ) ;
}
return F_33 ( V_108 , V_112 , L_9 , V_22 ) ;
}
static void F_34 ( struct V_44 * V_45 )
{
struct V_19 * V_20 = F_14 ( V_45 , struct V_19 , V_49 ) ;
switch ( V_20 -> V_113 ) {
case V_114 :
case V_115 :
F_17 ( V_20 , true ) ;
break;
case V_116 :
F_17 ( V_20 , false ) ;
break;
}
}
static int F_35 ( struct V_117 * V_118 , unsigned long V_3 ,
void * V_119 )
{
struct V_19 * V_20 = F_14 ( V_118 , struct V_19 , V_120 ) ;
F_16 ( V_20 -> V_51 , L_10 , V_3 ) ;
if ( V_121 )
V_20 -> V_31 = 500000 ;
else
V_20 -> V_31 = 100000 ;
V_20 -> V_113 = V_3 ;
F_36 ( & V_20 -> V_49 ) ;
return V_122 ;
}
static T_3
F_37 ( struct V_105 * V_51 , struct V_106 * V_107 ,
const char * V_108 , T_4 V_109 )
{
struct V_19 * V_20 = F_30 ( V_51 -> V_110 ) ;
int V_123 ;
int V_21 ;
if ( F_38 ( V_108 , V_124 [ 0 ] ) )
V_123 = 0 ;
else if ( F_38 ( V_108 , V_124 [ 1 ] ) )
V_123 = 1 ;
else if ( F_38 ( V_108 , V_124 [ 2 ] ) )
V_123 = 2 ;
else
return - V_111 ;
if ( V_51 == & V_20 -> V_89 -> V_51 ) {
if ( V_123 == 2 )
return - V_111 ;
F_22 ( V_20 , false ) ;
V_20 -> V_70 = V_123 ;
V_21 = F_22 ( V_20 , true ) ;
} else {
F_17 ( V_20 , false ) ;
V_20 -> V_56 = V_123 ;
V_21 = F_17 ( V_20 , true ) ;
}
return ( V_21 == 0 ) ? V_109 : V_21 ;
}
static T_3
F_39 ( struct V_105 * V_51 ,
struct V_106 * V_107 , char * V_108 )
{
struct V_19 * V_20 = F_30 ( V_51 -> V_110 ) ;
int V_125 = 0 ;
int V_126 ;
int V_123 = V_20 -> V_56 ;
if ( V_51 == & V_20 -> V_89 -> V_51 )
V_123 = V_20 -> V_70 ;
for ( V_126 = 0 ; V_126 < F_40 ( V_124 ) ; V_126 ++ )
if ( V_123 == V_126 )
V_125 += snprintf ( V_108 + V_125 , V_112 - V_125 ,
L_11 , V_124 [ V_126 ] ) ;
else
V_125 += snprintf ( V_108 + V_125 , V_112 - V_125 ,
L_12 , V_124 [ V_126 ] ) ;
V_108 [ V_125 - 1 ] = '\n' ;
return V_125 ;
}
static int F_15 ( void )
{
int V_47 ;
int V_9 ;
T_1 V_24 ;
V_47 = F_8 ( V_127 ) ;
if ( V_47 < 0 )
return V_47 ;
V_9 = F_6 ( V_37 , & V_24 ) ;
if ( V_9 )
return V_9 ;
return F_9 ( V_47 , V_24 & V_38 ) ;
}
static int F_41 ( struct V_19 * V_20 )
{
int V_9 ;
T_1 V_128 ;
V_9 = F_6 ( V_129 , & V_128 ) ;
if ( V_9 ) {
F_42 ( L_13 ) ;
return V_9 ;
}
F_16 ( V_20 -> V_51 , L_14 , V_128 ) ;
return V_128 ;
}
static int F_43 ( int V_128 )
{
V_128 &= V_130 ;
if ( V_131 <= V_128 && V_128 <= V_132 )
return V_133 ;
else if ( V_134 <= V_128 &&
V_128 <= V_135 )
return V_136 ;
else
return V_137 ;
}
static int F_44 ( struct V_138 * V_139 ,
enum V_140 V_141 ,
union V_142 * V_3 )
{
struct V_19 * V_20 = F_30 ( V_139 -> V_51 . V_110 ) ;
int V_143 ;
int V_128 ;
int V_9 ;
V_128 = F_41 ( V_20 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( V_139 -> V_144 -> type == V_145 )
V_143 = V_128 & V_146 ;
else
V_143 = V_128 & V_147 ;
if ( ! V_143 ) {
T_1 V_148 ;
F_6 ( V_149 , & V_148 ) ;
if ( V_139 -> V_144 -> type == V_145 )
V_143 = V_148 & 1 ;
else
V_143 = V_148 & 2 ;
if ( V_143 )
V_128 = V_131 ;
}
switch ( V_141 ) {
case V_150 :
if ( V_143 )
V_3 -> V_151 = F_43 ( V_128 ) ;
else
V_3 -> V_151 = V_137 ;
break;
case V_152 :
if ( ! V_143 )
return - V_153 ;
if ( V_139 -> V_144 -> type == V_145 ) {
V_9 = F_8 ( V_50 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_151 = V_9 * 6843 ;
} else {
V_9 = F_8 ( V_154 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_151 = V_9 * 9775 ;
}
break;
case V_155 :
if ( ! V_143 )
return - V_153 ;
V_9 = F_15 () ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_151 = V_9 ;
break;
case V_156 :
V_3 -> V_151 = V_143 &&
F_43 ( V_128 ) !=
V_137 ;
break;
case V_157 :
V_3 -> V_151 = - 1 ;
if ( V_139 -> V_144 -> type != V_145 ) {
if ( ! V_20 -> V_29 )
V_3 -> V_151 = V_20 -> V_28 ;
} else {
if ( V_20 -> V_29 )
V_3 -> V_151 = V_20 -> V_31 ;
}
if ( V_3 -> V_151 < 0 ) {
T_1 V_24 ;
V_3 -> V_151 = F_8 ( V_42 ) ;
if ( V_3 -> V_151 < 0 )
return V_3 -> V_151 ;
V_9 = F_6 ( V_37 , & V_24 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_151 = F_9 ( V_3 -> V_151 , V_24 &
V_38 ) ;
}
break;
default:
return - V_111 ;
}
return 0 ;
}
static int F_45 ( struct V_138 * V_139 ,
enum V_140 V_141 ,
const union V_142 * V_3 )
{
struct V_19 * V_20 = F_30 ( V_139 -> V_51 . V_110 ) ;
switch ( V_141 ) {
case V_157 :
if ( V_139 -> V_144 -> type == V_145 )
V_20 -> V_31 = V_3 -> V_151 ;
else
V_20 -> V_28 = V_3 -> V_151 ;
F_11 ( V_20 ) ;
break;
default:
return - V_111 ;
}
return 0 ;
}
static int F_46 ( struct V_138 * V_139 ,
enum V_140 V_141 )
{
switch ( V_141 ) {
case V_157 :
return true ;
default:
return false ;
}
}
static const struct V_158 *
F_47 ( struct V_105 * V_51 )
{
struct V_159 * V_160 = V_51 -> V_161 ;
struct V_158 * V_162 ;
T_5 V_163 ;
if ( ! V_160 )
return NULL ;
V_162 = F_48 ( V_51 , sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return V_162 ;
if ( F_49 ( V_160 , L_15 , & V_163 ) == 0 )
V_162 -> V_165 = V_163 ;
if ( F_49 ( V_160 , L_16 , & V_163 ) == 0 )
V_162 -> V_166 = V_163 ;
return V_162 ;
}
static inline const struct V_158 *
F_47 ( struct V_105 * V_51 )
{
return NULL ;
}
static int F_50 ( struct V_167 * V_168 )
{
struct V_19 * V_20 ;
const struct V_158 * V_162 = V_168 -> V_51 . V_169 ;
int V_9 ;
T_5 V_8 ;
V_20 = F_48 ( & V_168 -> V_51 , sizeof( * V_20 ) , V_164 ) ;
if ( V_20 == NULL )
return - V_170 ;
if ( ! V_162 )
V_162 = F_47 ( & V_168 -> V_51 ) ;
V_20 -> V_34 = 80100 ;
V_20 -> V_35 = 241000 ;
V_20 -> V_36 = 500000 ;
V_20 -> V_28 = 500000 ;
if ( V_121 )
V_20 -> V_31 = 500000 ;
else
V_20 -> V_31 = 100000 ;
V_20 -> V_56 = V_60 ;
V_20 -> V_70 = V_60 ;
V_20 -> V_51 = & V_168 -> V_51 ;
V_20 -> V_171 = F_51 ( V_168 , 0 ) ;
V_20 -> V_172 = F_51 ( V_168 , 1 ) ;
F_52 ( V_168 , V_20 ) ;
V_20 -> V_89 = F_53 ( & V_168 -> V_51 , & V_173 ,
NULL ) ;
if ( F_54 ( V_20 -> V_89 ) ) {
V_9 = F_55 ( V_20 -> V_89 ) ;
F_56 ( & V_168 -> V_51 , L_17 , V_9 ) ;
return V_9 ;
}
V_20 -> V_90 = F_53 ( & V_168 -> V_51 , & V_174 ,
NULL ) ;
if ( F_54 ( V_20 -> V_90 ) ) {
V_9 = F_55 ( V_20 -> V_90 ) ;
F_56 ( & V_168 -> V_51 , L_18 , V_9 ) ;
return V_9 ;
}
V_9 = F_57 ( & V_168 -> V_51 , V_20 -> V_171 , NULL ,
F_24 , V_175 , V_168 -> V_176 ,
V_20 ) ;
if ( V_9 < 0 ) {
F_56 ( & V_168 -> V_51 , L_19 ,
V_20 -> V_171 , V_9 ) ;
return V_9 ;
}
V_9 = F_57 ( & V_168 -> V_51 , V_20 -> V_172 , NULL ,
F_26 , V_175 , V_168 -> V_176 , V_20 ) ;
if ( V_9 < 0 ) {
F_56 ( & V_168 -> V_51 , L_19 ,
V_20 -> V_172 , V_9 ) ;
return V_9 ;
}
V_20 -> V_2 = F_58 ( & V_168 -> V_51 , L_20 ) ;
if ( F_54 ( V_20 -> V_2 ) ) {
V_20 -> V_2 = NULL ;
F_27 ( & V_168 -> V_51 , L_21 ) ;
}
F_59 ( & V_20 -> V_49 , F_34 ) ;
F_60 ( & V_20 -> V_32 , F_13 ) ;
V_20 -> V_120 . V_177 = F_35 ;
if ( V_20 -> V_51 -> V_161 ) {
struct V_159 * V_178 ;
V_178 = F_61 ( V_20 -> V_51 -> V_161 -> V_110 ,
NULL , L_22 ) ;
if ( V_178 )
V_20 -> V_58 = F_62 (
V_20 -> V_51 , V_178 , & V_20 -> V_120 ) ;
}
V_8 = ~ ( T_5 ) ( V_97 | V_98 | V_99 |
V_100 | V_101 ) ;
V_9 = F_5 ( V_94 , V_8 ,
V_179 ) ;
if ( V_9 < 0 ) {
F_56 ( & V_168 -> V_51 , L_23 , V_9 ) ;
goto V_180;
}
V_8 = ~ ( T_5 ) ( V_102 | V_103 | V_104 ) ;
V_9 = F_5 ( V_94 , V_8 ,
V_181 ) ;
if ( V_9 < 0 )
F_27 ( & V_168 -> V_51 , L_23 , V_9 ) ;
F_11 ( V_20 ) ;
if ( F_63 ( & V_20 -> V_90 -> V_51 , & V_182 ) )
F_27 ( & V_168 -> V_51 , L_24 ) ;
if ( F_63 ( & V_20 -> V_90 -> V_51 , & V_183 ) )
F_27 ( & V_168 -> V_51 , L_24 ) ;
if ( F_63 ( & V_20 -> V_89 -> V_51 , & V_183 ) )
F_27 ( & V_168 -> V_51 , L_24 ) ;
if ( F_63 ( & V_20 -> V_89 -> V_51 , & V_182 ) )
F_27 ( & V_168 -> V_51 , L_24 ) ;
F_22 ( V_20 , true ) ;
if ( ! F_18 ( V_20 -> V_58 ) )
F_35 ( & V_20 -> V_120 ,
V_20 -> V_58 -> V_184 ,
NULL ) ;
else
F_17 ( V_20 , false ) ;
if ( V_162 )
F_23 ( V_162 -> V_165 ,
V_162 -> V_166 ) ;
else
F_23 ( 0 , 0 ) ;
return 0 ;
V_180:
F_64 ( V_20 -> V_2 ) ;
return V_9 ;
}
static int F_65 ( struct V_167 * V_168 )
{
struct V_19 * V_20 = F_66 ( V_168 ) ;
F_22 ( V_20 , false ) ;
F_17 ( V_20 , false ) ;
F_23 ( 0 , 0 ) ;
F_64 ( V_20 -> V_2 ) ;
F_67 ( & V_20 -> V_90 -> V_51 , & V_182 ) ;
F_67 ( & V_20 -> V_90 -> V_51 , & V_183 ) ;
F_67 ( & V_20 -> V_89 -> V_51 , & V_182 ) ;
F_67 ( & V_20 -> V_89 -> V_51 , & V_183 ) ;
F_5 ( V_94 , 0xff ,
V_179 ) ;
F_5 ( V_94 , 0xff ,
V_181 ) ;
return 0 ;
}
