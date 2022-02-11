static inline int F_1 ( void )
{
return F_2 ( 11 ) > 4500 ;
}
static inline int F_1 ( void )
{
return 0 ;
}
static int F_3 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
int V_6 ;
V_6 = F_4 ( V_1 , & V_5 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_5 &= ~ V_2 ;
V_5 |= V_3 ;
return F_5 ( V_1 , V_5 , V_4 ) ;
}
static int F_6 ( T_1 V_4 , T_1 * V_5 )
{
return F_4 ( V_7 , V_5 , V_4 ) ;
}
static int F_7 ( T_1 V_2 , T_1 V_3 )
{
return F_3 ( V_8 , V_2 ,
V_9 | V_10 | V_3 ,
V_11 ) ;
}
static int F_8 ( T_1 V_4 )
{
int V_6 , V_12 ;
T_1 V_5 ;
V_6 = F_6 ( V_4 + 1 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_12 = ( int ) ( V_5 & 0x03 ) << 8 ;
V_6 = F_6 ( V_4 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return V_12 | V_5 ;
}
static int F_9 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_5 = 0 ;
V_6 = F_4 ( V_7 , & V_5 , V_15 ) ;
if ( V_6 )
return V_6 ;
if ( V_5 & V_16 )
return 0 ;
V_6 = F_4 ( V_17 , & V_5 ,
V_18 ) ;
if ( V_6 )
return V_6 ;
if ( V_5 & V_19 )
return 0 ;
return - V_20 ;
}
static int F_10 ( int V_21 , bool V_22 )
{
if ( V_22 )
return ( V_21 * 16618 - 8500 * 1000 ) / 5 ;
else
return ( V_21 * 16618 - 8500 * 1000 ) / 10 ;
}
static int F_11 ( int V_23 , bool V_22 )
{
int V_6 ;
if ( V_22 )
V_23 /= 2 ;
V_6 = ( V_23 * 10 + 8500 * 1000 ) / 16618 ;
if ( V_6 < 512 )
V_6 = 512 ;
return V_6 ;
}
static int F_12 ( struct V_13 * V_14 )
{
int V_24 ;
int V_25 ;
unsigned V_4 , V_26 ;
T_1 V_27 , V_28 , V_29 ;
bool V_22 = false ;
T_1 V_30 ;
if ( F_1 () ) {
V_25 = V_14 -> V_31 ;
V_14 -> V_32 = true ;
} else {
V_25 = V_14 -> V_33 ;
V_14 -> V_32 = false ;
if ( V_25 > V_14 -> V_34 ) {
V_25 = V_14 -> V_34 ;
V_14 -> V_33 = V_25 ;
}
if ( V_25 < V_14 -> V_34 )
F_13 ( & V_14 -> V_35 , V_36 ) ;
}
if ( V_14 -> V_37 >= 200000 )
V_22 = true ;
if ( V_14 -> V_38 >= 400000 )
V_22 = true ;
if ( V_14 -> V_39 >= 820000 )
V_22 = true ;
if ( V_25 > 852000 )
V_22 = true ;
V_24 = F_6 ( V_40 , & V_27 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_4 ( V_8 , & V_30 ,
V_11 ) < 0 )
V_30 = 0 ;
V_30 &= 7 ;
if ( ( ! ! V_22 ) != ! ! ( V_27 & V_41 ) )
F_7 ( V_30 , 0 ) ;
V_4 = F_11 ( V_14 -> V_37 , V_22 ) ;
if ( V_4 > 0x278 )
V_4 = 0x278 ;
if ( V_4 < 0x200 )
V_4 = 0x200 ;
V_4 = ( V_4 >> 3 ) & 0xf ;
V_29 = V_4 << 4 ;
V_4 = F_11 ( V_14 -> V_38 , V_22 ) ;
if ( V_4 > 0x2F0 )
V_4 = 0x2F0 ;
if ( V_4 < 0x200 )
V_4 = 0x200 ;
V_4 = ( V_4 >> 4 ) & 0xf ;
V_29 |= V_4 ;
V_24 = F_6 ( V_42 , & V_28 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_28 != V_29 ) {
V_24 = F_5 ( V_7 , 0xF4 ,
V_43 ) ;
if ( V_24 < 0 )
return V_24 ;
F_5 ( V_7 ,
V_29 , V_42 ) ;
}
V_4 = F_11 ( V_14 -> V_39 , V_22 ) ;
if ( V_4 > 0x3E0 )
V_4 = 0x3E0 ;
if ( V_4 < 0x200 )
V_4 = 0x200 ;
V_29 = ( V_4 >> 5 ) & 0xF ;
V_29 <<= 4 ;
V_24 = F_6 ( V_44 , & V_28 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ( V_28 & 0xF0 ) != V_29 ) {
V_29 |= ( V_28 & 0x0F ) ;
V_24 = F_5 ( V_7 , 0xE7 ,
V_43 ) ;
if ( V_24 < 0 )
return V_24 ;
F_5 ( V_7 ,
V_29 , V_44 ) ;
}
V_4 = F_11 ( V_25 , V_22 ) ;
if ( V_4 > 0x3ff )
V_4 = 0x3ff ;
V_24 = F_6 ( V_45 , & V_28 ) ;
if ( V_24 < 0 )
return V_24 ;
V_26 = V_28 ;
V_24 = F_6 ( V_46 , & V_28 ) ;
if ( V_24 < 0 )
return V_24 ;
V_26 |= V_28 << 8 ;
if ( V_4 != V_28 ) {
V_24 = F_5 ( V_7 , 0xE7 ,
V_43 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_5 ( V_7 ,
( V_4 & 0x100 ) ? 3 : 2 ,
V_46 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_5 ( V_7 , 0xE7 ,
V_43 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_5 ( V_7 ,
V_4 & 0xff ,
V_45 ) ;
}
if ( ( ! ! V_22 ) != ! ! ( V_27 & V_41 ) ) {
V_27 ^= V_41 ;
F_5 ( V_7 ,
V_27 , V_40 ) ;
F_7 ( 0 , V_30 ) ;
}
return 0 ;
}
static void F_14 ( struct V_47 * V_48 )
{
int V_49 , V_50 ;
int V_51 ;
struct V_13 * V_14 = F_15 ( V_48 , struct V_13 ,
V_35 . V_52 ) ;
V_51 = F_8 ( V_53 ) ;
if ( V_51 < 0 )
V_49 = 0 ;
else
V_49 = V_51 * 6843 ;
V_50 = F_16 () ;
F_17 ( V_14 -> V_54 , L_1 , V_49 , V_50 ,
V_14 -> V_33 , V_14 -> V_34 ) ;
if ( V_49 < V_55 ) {
V_14 -> V_33 -= V_56 ;
V_14 -> V_34 = V_14 -> V_33 ;
} else if ( V_14 -> V_33 >= V_14 -> V_34 ||
V_14 -> V_33 + V_56 > V_57 ) {
return;
} else {
V_14 -> V_33 += V_56 ;
F_13 ( & V_14 -> V_35 , V_36 ) ;
}
F_12 ( V_14 ) ;
}
static int F_18 ( struct V_13 * V_14 , bool V_58 )
{
int V_6 ;
if ( V_14 -> V_59 == V_60 )
V_58 = false ;
if ( V_58 && ! F_19 ( V_14 -> V_61 ) ) {
F_12 ( V_14 ) ;
if ( ! V_14 -> V_62 ) {
F_20 ( V_14 -> V_61 -> V_54 ) ;
V_14 -> V_62 = 1 ;
}
if ( V_14 -> V_59 == V_63 )
V_6 = F_7 ( 0 , V_64 ) ;
V_6 = F_3 ( V_7 , 0 ,
V_65 , V_66 ) ;
if ( V_14 -> V_59 == V_67 ) {
F_7 ( V_68 | V_69 , 0 ) ;
V_6 = F_5 ( V_7 , 0x33 ,
V_70 ) ;
V_6 = F_5 ( V_7 , 0x2a ,
V_71 ) ;
V_6 = F_5 ( V_7 , 0x26 ,
V_71 ) ;
V_6 = F_5 ( V_7 , 0xf3 ,
V_70 ) ;
V_6 = F_5 ( V_7 , 0x9c ,
V_43 ) ;
V_6 = F_5 ( V_7 , 0xf0 ,
V_72 ) ;
}
} else {
V_6 = F_7 ( V_64 , 0 ) ;
V_6 |= F_5 ( V_7 , 0x2a ,
V_71 ) ;
if ( V_14 -> V_62 ) {
F_21 ( V_14 -> V_61 -> V_54 ) ;
F_22 ( V_14 -> V_61 -> V_54 ) ;
V_14 -> V_62 = 0 ;
}
V_14 -> V_33 = 0 ;
}
return V_6 ;
}
static int F_23 ( struct V_13 * V_14 , bool V_58 )
{
int V_6 ;
if ( V_14 -> V_73 == V_60 )
V_58 = false ;
if ( V_58 )
V_6 = F_7 ( 0 , V_68 ) ;
else
V_6 = F_7 ( V_68 , 0 ) ;
return V_6 ;
}
static int F_24 ( int V_74 , int V_75 )
{
int V_6 ;
T_1 V_76 ;
if ( V_74 < 2500000 ||
V_75 < 25 ) {
V_6 = F_3 ( V_77 ,
V_78 , 0 , V_79 ) ;
return V_6 ;
}
V_76 = V_78 ;
if ( V_74 >= 3200000 )
V_76 |= V_80 ;
else if ( V_74 >= 3100000 )
V_76 |= V_81 ;
else if ( V_74 >= 3000000 )
V_76 |= V_82 ;
else
V_76 |= V_83 ;
if ( V_75 >= 1000 )
V_76 |= V_84 ;
else if ( V_75 >= 500 )
V_76 |= V_85 ;
else if ( V_75 >= 150 )
V_76 |= V_86 ;
else
V_76 |= V_87 ;
V_6 = F_3 ( V_77 ,
V_88 | V_89 ,
V_76 ,
V_79 ) ;
return V_6 ;
}
static T_2 F_25 ( int V_90 , void * V_91 )
{
struct V_13 * V_14 = V_91 ;
F_17 ( V_14 -> V_54 , L_2 ) ;
V_14 -> V_31 = 500000 ;
F_12 ( V_14 ) ;
F_26 ( V_14 -> V_92 ) ;
F_26 ( V_14 -> V_93 ) ;
return V_94 ;
}
static T_2 F_27 ( int V_90 , void * V_91 )
{
struct V_13 * V_14 = V_91 ;
T_1 V_95 , V_96 ;
int V_6 ;
V_6 = F_4 ( V_97 , & V_95 ,
V_98 ) ;
if ( V_6 < 0 )
return V_94 ;
V_6 = F_4 ( V_97 , & V_96 ,
V_99 ) ;
if ( V_6 < 0 )
return V_94 ;
F_17 ( V_14 -> V_54 , L_3 , V_96 , V_95 ) ;
if ( V_95 & ( V_100 | V_101 ) ) {
F_26 ( V_14 -> V_92 ) ;
F_26 ( V_14 -> V_93 ) ;
}
F_12 ( V_14 ) ;
if ( V_95 & ( V_102 | V_103 ) )
F_28 ( V_14 -> V_54 , L_4 ) ;
if ( V_95 & V_104 )
F_29 ( V_14 -> V_54 , L_5 ) ;
if ( V_96 & V_105 )
F_29 ( V_14 -> V_54 , L_6 ) ;
if ( V_96 & V_106 )
F_29 ( V_14 -> V_54 , L_7 ) ;
if ( V_96 & V_107 )
F_29 ( V_14 -> V_54 , L_8 ) ;
return V_94 ;
}
static T_3
F_30 ( struct V_108 * V_54 , struct V_109 * V_110 ,
const char * V_111 , T_4 V_112 )
{
struct V_13 * V_14 = F_31 ( V_54 -> V_113 ) ;
int V_25 = 0 ;
int V_24 = 0 ;
V_24 = F_32 ( V_111 , 10 , & V_25 ) ;
if ( V_24 )
return V_24 ;
if ( V_25 < 0 )
return - V_114 ;
if ( V_54 == & V_14 -> V_92 -> V_54 )
V_14 -> V_31 = V_25 ;
else
V_14 -> V_34 = V_25 ;
F_12 ( V_14 ) ;
return V_112 ;
}
static T_3 F_33 ( struct V_108 * V_54 ,
struct V_109 * V_110 , char * V_111 )
{
int V_24 = 0 ;
int V_25 = - 1 ;
T_1 V_27 ;
struct V_13 * V_14 = F_31 ( V_54 -> V_113 ) ;
if ( V_54 == & V_14 -> V_92 -> V_54 ) {
if ( ! V_14 -> V_32 )
V_25 = V_14 -> V_31 ;
} else {
if ( V_14 -> V_32 )
V_25 = V_14 -> V_34 ;
}
if ( V_25 < 0 ) {
V_25 = F_8 ( V_45 ) ;
if ( V_25 < 0 )
return V_25 ;
V_24 = F_6 ( V_40 , & V_27 ) ;
if ( V_24 < 0 )
return V_24 ;
V_25 = F_10 ( V_25 , V_27 & V_41 ) ;
}
return F_34 ( V_111 , V_115 , L_9 , V_25 ) ;
}
static void F_35 ( struct V_47 * V_48 )
{
struct V_13 * V_14 = F_15 ( V_48 , struct V_13 , V_52 ) ;
switch ( V_14 -> V_116 ) {
case V_117 :
case V_118 :
F_18 ( V_14 , true ) ;
break;
case V_119 :
F_18 ( V_14 , false ) ;
break;
}
}
static int F_36 ( struct V_120 * V_121 , unsigned long V_5 ,
void * V_122 )
{
struct V_13 * V_14 = F_15 ( V_121 , struct V_13 , V_123 ) ;
F_17 ( V_14 -> V_54 , L_10 , V_5 ) ;
if ( V_124 )
V_14 -> V_34 = 500000 ;
else
V_14 -> V_34 = 100000 ;
V_14 -> V_116 = V_5 ;
F_37 ( & V_14 -> V_52 ) ;
return V_125 ;
}
static T_3
F_38 ( struct V_108 * V_54 , struct V_109 * V_110 ,
const char * V_111 , T_4 V_112 )
{
struct V_13 * V_14 = F_31 ( V_54 -> V_113 ) ;
int V_126 ;
int V_24 ;
if ( F_39 ( V_111 , V_127 [ 0 ] ) )
V_126 = 0 ;
else if ( F_39 ( V_111 , V_127 [ 1 ] ) )
V_126 = 1 ;
else if ( F_39 ( V_111 , V_127 [ 2 ] ) )
V_126 = 2 ;
else
return - V_114 ;
if ( V_54 == & V_14 -> V_92 -> V_54 ) {
if ( V_126 == 2 )
return - V_114 ;
F_23 ( V_14 , false ) ;
V_14 -> V_73 = V_126 ;
V_24 = F_23 ( V_14 , true ) ;
} else {
F_18 ( V_14 , false ) ;
V_14 -> V_59 = V_126 ;
V_24 = F_18 ( V_14 , true ) ;
}
return ( V_24 == 0 ) ? V_112 : V_24 ;
}
static T_3
F_40 ( struct V_108 * V_54 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_13 * V_14 = F_31 ( V_54 -> V_113 ) ;
int V_128 = 0 ;
int V_129 ;
int V_126 = V_14 -> V_59 ;
if ( V_54 == & V_14 -> V_92 -> V_54 )
V_126 = V_14 -> V_73 ;
for ( V_129 = 0 ; V_129 < F_41 ( V_127 ) ; V_129 ++ )
if ( V_126 == V_129 )
V_128 += snprintf ( V_111 + V_128 , V_115 - V_128 ,
L_11 , V_127 [ V_129 ] ) ;
else
V_128 += snprintf ( V_111 + V_128 , V_115 - V_128 ,
L_12 , V_127 [ V_129 ] ) ;
V_111 [ V_128 - 1 ] = '\n' ;
return V_128 ;
}
static int F_16 ( void )
{
int V_50 ;
int V_6 ;
T_1 V_27 ;
V_50 = F_8 ( V_130 ) ;
if ( V_50 < 0 )
return V_50 ;
V_6 = F_6 ( V_40 , & V_27 ) ;
if ( V_6 )
return V_6 ;
return F_10 ( V_50 , V_27 & V_41 ) ;
}
static int F_42 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_131 ;
V_6 = F_6 ( V_132 , & V_131 ) ;
if ( V_6 ) {
F_43 ( L_13 ) ;
return V_6 ;
}
F_17 ( V_14 -> V_54 , L_14 , V_131 ) ;
return V_131 ;
}
static int F_44 ( int V_131 )
{
V_131 &= V_133 ;
if ( V_134 <= V_131 && V_131 <= V_135 )
return V_136 ;
else if ( V_137 <= V_131 &&
V_131 <= V_138 )
return V_139 ;
else
return V_140 ;
}
static int F_45 ( struct V_141 * V_142 ,
enum V_143 V_144 ,
union V_145 * V_5 )
{
struct V_13 * V_14 = F_31 ( V_142 -> V_54 . V_113 ) ;
int V_146 ;
int V_131 ;
int V_6 ;
V_131 = F_42 ( V_14 ) ;
if ( V_131 < 0 )
return V_131 ;
if ( V_142 -> V_147 -> type == V_148 )
V_146 = V_131 & V_149 ;
else
V_146 = V_131 & V_150 ;
if ( ! V_146 ) {
T_1 V_151 ;
F_6 ( V_152 , & V_151 ) ;
if ( V_142 -> V_147 -> type == V_148 )
V_146 = V_151 & 1 ;
else
V_146 = V_151 & 2 ;
if ( V_146 )
V_131 = V_134 ;
}
switch ( V_144 ) {
case V_153 :
if ( V_146 )
V_5 -> V_154 = F_44 ( V_131 ) ;
else
V_5 -> V_154 = V_140 ;
break;
case V_155 :
if ( ! V_146 )
return - V_156 ;
if ( V_142 -> V_147 -> type == V_148 ) {
V_6 = F_8 ( V_53 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_154 = V_6 * 6843 ;
} else {
V_6 = F_8 ( V_157 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_154 = V_6 * 9775 ;
}
break;
case V_158 :
if ( ! V_146 )
return - V_156 ;
V_6 = F_16 () ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_154 = V_6 ;
break;
case V_159 :
V_5 -> V_154 = V_146 &&
F_44 ( V_131 ) !=
V_140 ;
break;
default:
return - V_114 ;
}
return 0 ;
}
static const struct V_160 *
F_46 ( struct V_108 * V_54 )
{
struct V_161 * V_162 = V_54 -> V_163 ;
struct V_160 * V_164 ;
T_5 V_165 ;
if ( ! V_162 )
return NULL ;
V_164 = F_47 ( V_54 , sizeof( * V_164 ) , V_166 ) ;
if ( ! V_164 )
return V_164 ;
if ( F_48 ( V_162 , L_15 , & V_165 ) == 0 )
V_164 -> V_167 = V_165 ;
if ( F_48 ( V_162 , L_16 , & V_165 ) == 0 )
V_164 -> V_168 = V_165 ;
return V_164 ;
}
static inline const struct V_160 *
F_46 ( struct V_108 * V_54 )
{
return NULL ;
}
static int F_49 ( struct V_169 * V_170 )
{
struct V_13 * V_14 ;
const struct V_160 * V_164 = V_170 -> V_54 . V_171 ;
int V_6 ;
T_5 V_4 ;
V_14 = F_47 ( & V_170 -> V_54 , sizeof( * V_14 ) , V_166 ) ;
if ( V_14 == NULL )
return - V_172 ;
if ( ! V_164 )
V_164 = F_46 ( & V_170 -> V_54 ) ;
V_14 -> V_37 = 80100 ;
V_14 -> V_38 = 241000 ;
V_14 -> V_39 = 500000 ;
V_14 -> V_31 = 500000 ;
if ( V_124 )
V_14 -> V_34 = 500000 ;
else
V_14 -> V_34 = 100000 ;
V_14 -> V_59 = V_63 ;
V_14 -> V_73 = V_63 ;
V_14 -> V_54 = & V_170 -> V_54 ;
V_14 -> V_173 = F_50 ( V_170 , 0 ) ;
V_14 -> V_174 = F_50 ( V_170 , 1 ) ;
V_6 = F_9 ( V_14 ) ;
if ( V_6 ) {
F_29 ( & V_170 -> V_54 , L_17 , V_6 ) ;
return V_6 ;
}
F_51 ( V_170 , V_14 ) ;
V_14 -> V_92 = F_52 ( & V_170 -> V_54 , & V_175 ,
NULL ) ;
if ( F_53 ( V_14 -> V_92 ) ) {
V_6 = F_54 ( V_14 -> V_92 ) ;
F_55 ( & V_170 -> V_54 , L_18 , V_6 ) ;
return V_6 ;
}
V_14 -> V_93 = F_52 ( & V_170 -> V_54 , & V_176 ,
NULL ) ;
if ( F_53 ( V_14 -> V_93 ) ) {
V_6 = F_54 ( V_14 -> V_93 ) ;
F_55 ( & V_170 -> V_54 , L_19 , V_6 ) ;
return V_6 ;
}
V_6 = F_56 ( & V_170 -> V_54 , V_14 -> V_173 , NULL ,
F_25 , V_177 , V_170 -> V_178 ,
V_14 ) ;
if ( V_6 < 0 ) {
F_55 ( & V_170 -> V_54 , L_20 ,
V_14 -> V_173 , V_6 ) ;
return V_6 ;
}
V_6 = F_56 ( & V_170 -> V_54 , V_14 -> V_174 , NULL ,
F_27 , V_177 , V_170 -> V_178 , V_14 ) ;
if ( V_6 < 0 ) {
F_55 ( & V_170 -> V_54 , L_20 ,
V_14 -> V_174 , V_6 ) ;
return V_6 ;
}
F_57 ( & V_14 -> V_52 , F_35 ) ;
F_58 ( & V_14 -> V_35 , F_14 ) ;
V_14 -> V_123 . V_179 = F_36 ;
if ( V_14 -> V_54 -> V_163 ) {
struct V_161 * V_180 ;
V_180 = F_59 ( V_14 -> V_54 -> V_163 -> V_113 ,
NULL , L_21 ) ;
if ( V_180 )
V_14 -> V_61 = F_60 (
V_14 -> V_54 , V_180 , & V_14 -> V_123 ) ;
}
V_4 = ~ ( T_5 ) ( V_100 | V_101 | V_102 |
V_103 | V_104 ) ;
V_6 = F_5 ( V_97 , V_4 ,
V_181 ) ;
if ( V_6 < 0 ) {
F_55 ( & V_170 -> V_54 , L_22 , V_6 ) ;
return V_6 ;
}
V_4 = ~ ( T_5 ) ( V_105 | V_106 | V_107 ) ;
V_6 = F_5 ( V_97 , V_4 ,
V_182 ) ;
if ( V_6 < 0 )
F_28 ( & V_170 -> V_54 , L_22 , V_6 ) ;
F_12 ( V_14 ) ;
if ( F_61 ( & V_14 -> V_93 -> V_54 , & V_183 ) )
F_28 ( & V_170 -> V_54 , L_23 ) ;
if ( F_61 ( & V_14 -> V_93 -> V_54 , & V_184 ) )
F_28 ( & V_170 -> V_54 , L_23 ) ;
if ( F_61 ( & V_14 -> V_92 -> V_54 , & V_184 ) )
F_28 ( & V_170 -> V_54 , L_23 ) ;
if ( F_61 ( & V_14 -> V_92 -> V_54 , & V_183 ) )
F_28 ( & V_170 -> V_54 , L_23 ) ;
F_23 ( V_14 , true ) ;
if ( ! F_19 ( V_14 -> V_61 ) )
F_36 ( & V_14 -> V_123 ,
V_14 -> V_61 -> V_185 ,
NULL ) ;
else
F_18 ( V_14 , false ) ;
if ( V_164 )
F_24 ( V_164 -> V_167 ,
V_164 -> V_168 ) ;
else
F_24 ( 0 , 0 ) ;
return 0 ;
}
static int T_6 F_62 ( struct V_169 * V_170 )
{
struct V_13 * V_14 = F_63 ( V_170 ) ;
F_23 ( V_14 , false ) ;
F_18 ( V_14 , false ) ;
F_24 ( 0 , 0 ) ;
F_64 ( & V_14 -> V_93 -> V_54 , & V_183 ) ;
F_64 ( & V_14 -> V_93 -> V_54 , & V_184 ) ;
F_64 ( & V_14 -> V_92 -> V_54 , & V_183 ) ;
F_64 ( & V_14 -> V_92 -> V_54 , & V_184 ) ;
F_5 ( V_97 , 0xff ,
V_181 ) ;
F_5 ( V_97 , 0xff ,
V_182 ) ;
return 0 ;
}
