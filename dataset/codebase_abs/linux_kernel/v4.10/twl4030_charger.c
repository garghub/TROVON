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
static int F_9 ( struct V_16 * V_17 )
{
int V_9 ;
T_1 V_3 = 0 ;
V_9 = F_4 ( V_10 , & V_3 , V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_3 & V_19 )
return 0 ;
V_9 = F_4 ( V_20 , & V_3 ,
V_21 ) ;
if ( V_9 )
return V_9 ;
if ( V_3 & V_22 )
return 0 ;
return - V_23 ;
}
static int F_10 ( int V_24 , bool V_25 )
{
if ( V_25 )
return ( V_24 * 16618 - 8500 * 1000 ) / 5 ;
else
return ( V_24 * 16618 - 8500 * 1000 ) / 10 ;
}
static int F_11 ( int V_26 , bool V_25 )
{
int V_9 ;
if ( V_25 )
V_26 /= 2 ;
V_9 = ( V_26 * 10 + 8500 * 1000 ) / 16618 ;
if ( V_9 < 512 )
V_9 = 512 ;
return V_9 ;
}
static int F_12 ( struct V_16 * V_17 )
{
int V_27 ;
int V_28 ;
unsigned V_8 , V_29 ;
T_1 V_30 , V_31 , V_32 ;
bool V_25 = false ;
T_1 V_33 ;
if ( F_1 ( V_17 -> V_2 ) ) {
V_28 = V_17 -> V_34 ;
V_17 -> V_35 = true ;
} else {
V_28 = V_17 -> V_36 ;
V_17 -> V_35 = false ;
if ( V_28 > V_17 -> V_37 ) {
V_28 = V_17 -> V_37 ;
V_17 -> V_36 = V_28 ;
}
if ( V_28 < V_17 -> V_37 )
F_13 ( & V_17 -> V_38 , V_39 ) ;
}
if ( V_17 -> V_40 >= 200000 )
V_25 = true ;
if ( V_17 -> V_41 >= 400000 )
V_25 = true ;
if ( V_17 -> V_42 >= 820000 )
V_25 = true ;
if ( V_28 > 852000 )
V_25 = true ;
V_27 = F_6 ( V_43 , & V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( F_4 ( V_11 , & V_33 ,
V_14 ) < 0 )
V_33 = 0 ;
V_33 &= 7 ;
if ( ( ! ! V_25 ) != ! ! ( V_30 & V_44 ) )
F_7 ( V_33 , 0 ) ;
V_8 = F_11 ( V_17 -> V_40 , V_25 ) ;
if ( V_8 > 0x278 )
V_8 = 0x278 ;
if ( V_8 < 0x200 )
V_8 = 0x200 ;
V_8 = ( V_8 >> 3 ) & 0xf ;
V_32 = V_8 << 4 ;
V_8 = F_11 ( V_17 -> V_41 , V_25 ) ;
if ( V_8 > 0x2F0 )
V_8 = 0x2F0 ;
if ( V_8 < 0x200 )
V_8 = 0x200 ;
V_8 = ( V_8 >> 4 ) & 0xf ;
V_32 |= V_8 ;
V_27 = F_6 ( V_45 , & V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_31 != V_32 ) {
V_27 = F_5 ( V_10 , 0xF4 ,
V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
F_5 ( V_10 ,
V_32 , V_45 ) ;
}
V_8 = F_11 ( V_17 -> V_42 , V_25 ) ;
if ( V_8 > 0x3E0 )
V_8 = 0x3E0 ;
if ( V_8 < 0x200 )
V_8 = 0x200 ;
V_32 = ( V_8 >> 5 ) & 0xF ;
V_32 <<= 4 ;
V_27 = F_6 ( V_47 , & V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ( V_31 & 0xF0 ) != V_32 ) {
V_32 |= ( V_31 & 0x0F ) ;
V_27 = F_5 ( V_10 , 0xE7 ,
V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
F_5 ( V_10 ,
V_32 , V_47 ) ;
}
V_8 = F_11 ( V_28 , V_25 ) ;
if ( V_8 > 0x3ff )
V_8 = 0x3ff ;
V_27 = F_6 ( V_48 , & V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
V_29 = V_31 ;
V_27 = F_6 ( V_49 , & V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
V_29 |= V_31 << 8 ;
if ( V_8 != V_31 ) {
V_27 = F_5 ( V_10 , 0xE7 ,
V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_5 ( V_10 ,
( V_8 & 0x100 ) ? 3 : 2 ,
V_49 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_5 ( V_10 , 0xE7 ,
V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_5 ( V_10 ,
V_8 & 0xff ,
V_48 ) ;
}
if ( ( ! ! V_25 ) != ! ! ( V_30 & V_44 ) ) {
V_30 ^= V_44 ;
F_5 ( V_10 ,
V_30 , V_43 ) ;
F_7 ( 0 , V_33 ) ;
}
return 0 ;
}
static void F_14 ( struct V_50 * V_51 )
{
int V_52 , V_53 ;
int V_54 ;
struct V_16 * V_17 = F_15 ( V_51 , struct V_16 ,
V_38 . V_55 ) ;
V_54 = F_8 ( V_56 ) ;
if ( V_54 < 0 )
V_52 = 0 ;
else
V_52 = V_54 * 6843 ;
V_53 = F_16 () ;
F_17 ( V_17 -> V_57 , L_1 , V_52 , V_53 ,
V_17 -> V_36 , V_17 -> V_37 ) ;
if ( V_52 < V_58 ) {
V_17 -> V_36 -= V_59 ;
V_17 -> V_37 = V_17 -> V_36 ;
} else if ( V_17 -> V_36 >= V_17 -> V_37 ||
V_17 -> V_36 + V_59 > V_60 ) {
return;
} else {
V_17 -> V_36 += V_59 ;
F_13 ( & V_17 -> V_38 , V_39 ) ;
}
F_12 ( V_17 ) ;
}
static int F_18 ( struct V_16 * V_17 , bool V_61 )
{
int V_9 ;
if ( V_17 -> V_62 == V_63 )
V_61 = false ;
if ( V_61 && ! F_19 ( V_17 -> V_64 ) ) {
F_12 ( V_17 ) ;
if ( ! V_17 -> V_65 ) {
F_20 ( V_17 -> V_64 -> V_57 ) ;
V_17 -> V_65 = 1 ;
}
if ( V_17 -> V_62 == V_66 )
V_9 = F_7 ( 0 , V_67 ) ;
V_9 = F_3 ( V_10 , 0 ,
V_68 , V_69 ) ;
if ( V_17 -> V_62 == V_70 ) {
F_7 ( V_71 | V_72 , 0 ) ;
V_9 = F_5 ( V_10 , 0x33 ,
V_73 ) ;
V_9 = F_5 ( V_10 , 0x2a ,
V_74 ) ;
V_9 = F_5 ( V_10 , 0x26 ,
V_74 ) ;
V_9 = F_5 ( V_10 , 0xf3 ,
V_73 ) ;
V_9 = F_5 ( V_10 , 0x9c ,
V_46 ) ;
V_9 = F_5 ( V_10 , 0xf0 ,
V_75 ) ;
}
} else {
V_9 = F_7 ( V_67 , 0 ) ;
V_9 |= F_5 ( V_10 , 0x2a ,
V_74 ) ;
if ( V_17 -> V_65 ) {
F_21 ( V_17 -> V_64 -> V_57 ) ;
F_22 ( V_17 -> V_64 -> V_57 ) ;
V_17 -> V_65 = 0 ;
}
V_17 -> V_36 = 0 ;
}
return V_9 ;
}
static int F_23 ( struct V_16 * V_17 , bool V_61 )
{
int V_9 ;
if ( V_17 -> V_76 == V_63 )
V_61 = false ;
if ( V_61 )
V_9 = F_7 ( 0 , V_71 ) ;
else
V_9 = F_7 ( V_71 , 0 ) ;
return V_9 ;
}
static int F_24 ( int V_77 , int V_78 )
{
int V_9 ;
T_1 V_79 ;
if ( V_77 < 2500000 ||
V_78 < 25 ) {
V_9 = F_3 ( V_80 ,
V_81 , 0 , V_82 ) ;
return V_9 ;
}
V_79 = V_81 ;
if ( V_77 >= 3200000 )
V_79 |= V_83 ;
else if ( V_77 >= 3100000 )
V_79 |= V_84 ;
else if ( V_77 >= 3000000 )
V_79 |= V_85 ;
else
V_79 |= V_86 ;
if ( V_78 >= 1000 )
V_79 |= V_87 ;
else if ( V_78 >= 500 )
V_79 |= V_88 ;
else if ( V_78 >= 150 )
V_79 |= V_89 ;
else
V_79 |= V_90 ;
V_9 = F_3 ( V_80 ,
V_91 | V_92 ,
V_79 ,
V_82 ) ;
return V_9 ;
}
static T_2 F_25 ( int V_93 , void * V_94 )
{
struct V_16 * V_17 = V_94 ;
F_17 ( V_17 -> V_57 , L_2 ) ;
V_17 -> V_34 = 500000 ;
F_12 ( V_17 ) ;
F_26 ( V_17 -> V_95 ) ;
F_26 ( V_17 -> V_96 ) ;
return V_97 ;
}
static T_2 F_27 ( int V_93 , void * V_94 )
{
struct V_16 * V_17 = V_94 ;
T_1 V_98 , V_99 ;
int V_9 ;
V_9 = F_4 ( V_100 , & V_98 ,
V_101 ) ;
if ( V_9 < 0 )
return V_97 ;
V_9 = F_4 ( V_100 , & V_99 ,
V_102 ) ;
if ( V_9 < 0 )
return V_97 ;
F_17 ( V_17 -> V_57 , L_3 , V_99 , V_98 ) ;
if ( V_98 & ( V_103 | V_104 ) ) {
F_26 ( V_17 -> V_95 ) ;
F_26 ( V_17 -> V_96 ) ;
}
F_12 ( V_17 ) ;
if ( V_98 & ( V_105 | V_106 ) )
F_28 ( V_17 -> V_57 , L_4 ) ;
if ( V_98 & V_107 )
F_29 ( V_17 -> V_57 , L_5 ) ;
if ( V_99 & V_108 )
F_29 ( V_17 -> V_57 , L_6 ) ;
if ( V_99 & V_109 )
F_29 ( V_17 -> V_57 , L_7 ) ;
if ( V_99 & V_110 )
F_29 ( V_17 -> V_57 , L_8 ) ;
return V_97 ;
}
static T_3
F_30 ( struct V_111 * V_57 , struct V_112 * V_113 ,
const char * V_114 , T_4 V_115 )
{
struct V_16 * V_17 = F_31 ( V_57 -> V_116 ) ;
int V_28 = 0 ;
int V_27 = 0 ;
V_27 = F_32 ( V_114 , 10 , & V_28 ) ;
if ( V_27 )
return V_27 ;
if ( V_28 < 0 )
return - V_117 ;
if ( V_57 == & V_17 -> V_95 -> V_57 )
V_17 -> V_34 = V_28 ;
else
V_17 -> V_37 = V_28 ;
F_12 ( V_17 ) ;
return V_115 ;
}
static T_3 F_33 ( struct V_111 * V_57 ,
struct V_112 * V_113 , char * V_114 )
{
int V_27 = 0 ;
int V_28 = - 1 ;
T_1 V_30 ;
struct V_16 * V_17 = F_31 ( V_57 -> V_116 ) ;
if ( V_57 == & V_17 -> V_95 -> V_57 ) {
if ( ! V_17 -> V_35 )
V_28 = V_17 -> V_34 ;
} else {
if ( V_17 -> V_35 )
V_28 = V_17 -> V_37 ;
}
if ( V_28 < 0 ) {
V_28 = F_8 ( V_48 ) ;
if ( V_28 < 0 )
return V_28 ;
V_27 = F_6 ( V_43 , & V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_28 = F_10 ( V_28 , V_30 & V_44 ) ;
}
return F_34 ( V_114 , V_118 , L_9 , V_28 ) ;
}
static void F_35 ( struct V_50 * V_51 )
{
struct V_16 * V_17 = F_15 ( V_51 , struct V_16 , V_55 ) ;
switch ( V_17 -> V_119 ) {
case V_120 :
case V_121 :
F_18 ( V_17 , true ) ;
break;
case V_122 :
F_18 ( V_17 , false ) ;
break;
}
}
static int F_36 ( struct V_123 * V_124 , unsigned long V_3 ,
void * V_125 )
{
struct V_16 * V_17 = F_15 ( V_124 , struct V_16 , V_126 ) ;
F_17 ( V_17 -> V_57 , L_10 , V_3 ) ;
if ( V_127 )
V_17 -> V_37 = 500000 ;
else
V_17 -> V_37 = 100000 ;
V_17 -> V_119 = V_3 ;
F_37 ( & V_17 -> V_55 ) ;
return V_128 ;
}
static T_3
F_38 ( struct V_111 * V_57 , struct V_112 * V_113 ,
const char * V_114 , T_4 V_115 )
{
struct V_16 * V_17 = F_31 ( V_57 -> V_116 ) ;
int V_129 ;
int V_27 ;
if ( F_39 ( V_114 , V_130 [ 0 ] ) )
V_129 = 0 ;
else if ( F_39 ( V_114 , V_130 [ 1 ] ) )
V_129 = 1 ;
else if ( F_39 ( V_114 , V_130 [ 2 ] ) )
V_129 = 2 ;
else
return - V_117 ;
if ( V_57 == & V_17 -> V_95 -> V_57 ) {
if ( V_129 == 2 )
return - V_117 ;
F_23 ( V_17 , false ) ;
V_17 -> V_76 = V_129 ;
V_27 = F_23 ( V_17 , true ) ;
} else {
F_18 ( V_17 , false ) ;
V_17 -> V_62 = V_129 ;
V_27 = F_18 ( V_17 , true ) ;
}
return ( V_27 == 0 ) ? V_115 : V_27 ;
}
static T_3
F_40 ( struct V_111 * V_57 ,
struct V_112 * V_113 , char * V_114 )
{
struct V_16 * V_17 = F_31 ( V_57 -> V_116 ) ;
int V_131 = 0 ;
int V_132 ;
int V_129 = V_17 -> V_62 ;
if ( V_57 == & V_17 -> V_95 -> V_57 )
V_129 = V_17 -> V_76 ;
for ( V_132 = 0 ; V_132 < F_41 ( V_130 ) ; V_132 ++ )
if ( V_129 == V_132 )
V_131 += snprintf ( V_114 + V_131 , V_118 - V_131 ,
L_11 , V_130 [ V_132 ] ) ;
else
V_131 += snprintf ( V_114 + V_131 , V_118 - V_131 ,
L_12 , V_130 [ V_132 ] ) ;
V_114 [ V_131 - 1 ] = '\n' ;
return V_131 ;
}
static int F_16 ( void )
{
int V_53 ;
int V_9 ;
T_1 V_30 ;
V_53 = F_8 ( V_133 ) ;
if ( V_53 < 0 )
return V_53 ;
V_9 = F_6 ( V_43 , & V_30 ) ;
if ( V_9 )
return V_9 ;
return F_10 ( V_53 , V_30 & V_44 ) ;
}
static int F_42 ( struct V_16 * V_17 )
{
int V_9 ;
T_1 V_134 ;
V_9 = F_6 ( V_135 , & V_134 ) ;
if ( V_9 ) {
F_43 ( L_13 ) ;
return V_9 ;
}
F_17 ( V_17 -> V_57 , L_14 , V_134 ) ;
return V_134 ;
}
static int F_44 ( int V_134 )
{
V_134 &= V_136 ;
if ( V_137 <= V_134 && V_134 <= V_138 )
return V_139 ;
else if ( V_140 <= V_134 &&
V_134 <= V_141 )
return V_142 ;
else
return V_143 ;
}
static int F_45 ( struct V_144 * V_145 ,
enum V_146 V_147 ,
union V_148 * V_3 )
{
struct V_16 * V_17 = F_31 ( V_145 -> V_57 . V_116 ) ;
int V_149 ;
int V_134 ;
int V_9 ;
V_134 = F_42 ( V_17 ) ;
if ( V_134 < 0 )
return V_134 ;
if ( V_145 -> V_150 -> type == V_151 )
V_149 = V_134 & V_152 ;
else
V_149 = V_134 & V_153 ;
if ( ! V_149 ) {
T_1 V_154 ;
F_6 ( V_155 , & V_154 ) ;
if ( V_145 -> V_150 -> type == V_151 )
V_149 = V_154 & 1 ;
else
V_149 = V_154 & 2 ;
if ( V_149 )
V_134 = V_137 ;
}
switch ( V_147 ) {
case V_156 :
if ( V_149 )
V_3 -> V_157 = F_44 ( V_134 ) ;
else
V_3 -> V_157 = V_143 ;
break;
case V_158 :
if ( ! V_149 )
return - V_159 ;
if ( V_145 -> V_150 -> type == V_151 ) {
V_9 = F_8 ( V_56 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_157 = V_9 * 6843 ;
} else {
V_9 = F_8 ( V_160 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_157 = V_9 * 9775 ;
}
break;
case V_161 :
if ( ! V_149 )
return - V_159 ;
V_9 = F_16 () ;
if ( V_9 < 0 )
return V_9 ;
V_3 -> V_157 = V_9 ;
break;
case V_162 :
V_3 -> V_157 = V_149 &&
F_44 ( V_134 ) !=
V_143 ;
break;
default:
return - V_117 ;
}
return 0 ;
}
static const struct V_163 *
F_46 ( struct V_111 * V_57 )
{
struct V_164 * V_165 = V_57 -> V_166 ;
struct V_163 * V_167 ;
T_5 V_168 ;
if ( ! V_165 )
return NULL ;
V_167 = F_47 ( V_57 , sizeof( * V_167 ) , V_169 ) ;
if ( ! V_167 )
return V_167 ;
if ( F_48 ( V_165 , L_15 , & V_168 ) == 0 )
V_167 -> V_170 = V_168 ;
if ( F_48 ( V_165 , L_16 , & V_168 ) == 0 )
V_167 -> V_171 = V_168 ;
return V_167 ;
}
static inline const struct V_163 *
F_46 ( struct V_111 * V_57 )
{
return NULL ;
}
static int F_49 ( struct V_172 * V_173 )
{
struct V_16 * V_17 ;
const struct V_163 * V_167 = V_173 -> V_57 . V_174 ;
int V_9 ;
T_5 V_8 ;
V_17 = F_47 ( & V_173 -> V_57 , sizeof( * V_17 ) , V_169 ) ;
if ( V_17 == NULL )
return - V_175 ;
if ( ! V_167 )
V_167 = F_46 ( & V_173 -> V_57 ) ;
V_17 -> V_40 = 80100 ;
V_17 -> V_41 = 241000 ;
V_17 -> V_42 = 500000 ;
V_17 -> V_34 = 500000 ;
if ( V_127 )
V_17 -> V_37 = 500000 ;
else
V_17 -> V_37 = 100000 ;
V_17 -> V_62 = V_66 ;
V_17 -> V_76 = V_66 ;
V_17 -> V_57 = & V_173 -> V_57 ;
V_17 -> V_176 = F_50 ( V_173 , 0 ) ;
V_17 -> V_177 = F_50 ( V_173 , 1 ) ;
V_9 = F_9 ( V_17 ) ;
if ( V_9 ) {
F_29 ( & V_173 -> V_57 , L_17 , V_9 ) ;
return V_9 ;
}
F_51 ( V_173 , V_17 ) ;
V_17 -> V_95 = F_52 ( & V_173 -> V_57 , & V_178 ,
NULL ) ;
if ( F_53 ( V_17 -> V_95 ) ) {
V_9 = F_54 ( V_17 -> V_95 ) ;
F_55 ( & V_173 -> V_57 , L_18 , V_9 ) ;
return V_9 ;
}
V_17 -> V_96 = F_52 ( & V_173 -> V_57 , & V_179 ,
NULL ) ;
if ( F_53 ( V_17 -> V_96 ) ) {
V_9 = F_54 ( V_17 -> V_96 ) ;
F_55 ( & V_173 -> V_57 , L_19 , V_9 ) ;
return V_9 ;
}
V_9 = F_56 ( & V_173 -> V_57 , V_17 -> V_176 , NULL ,
F_25 , V_180 , V_173 -> V_181 ,
V_17 ) ;
if ( V_9 < 0 ) {
F_55 ( & V_173 -> V_57 , L_20 ,
V_17 -> V_176 , V_9 ) ;
return V_9 ;
}
V_9 = F_56 ( & V_173 -> V_57 , V_17 -> V_177 , NULL ,
F_27 , V_180 , V_173 -> V_181 , V_17 ) ;
if ( V_9 < 0 ) {
F_55 ( & V_173 -> V_57 , L_20 ,
V_17 -> V_177 , V_9 ) ;
return V_9 ;
}
V_17 -> V_2 = F_57 ( & V_173 -> V_57 , L_21 ) ;
if ( F_53 ( V_17 -> V_2 ) ) {
V_17 -> V_2 = NULL ;
F_28 ( & V_173 -> V_57 , L_22 ) ;
}
F_58 ( & V_17 -> V_55 , F_35 ) ;
F_59 ( & V_17 -> V_38 , F_14 ) ;
V_17 -> V_126 . V_182 = F_36 ;
if ( V_17 -> V_57 -> V_166 ) {
struct V_164 * V_183 ;
V_183 = F_60 ( V_17 -> V_57 -> V_166 -> V_116 ,
NULL , L_23 ) ;
if ( V_183 )
V_17 -> V_64 = F_61 (
V_17 -> V_57 , V_183 , & V_17 -> V_126 ) ;
}
V_8 = ~ ( T_5 ) ( V_103 | V_104 | V_105 |
V_106 | V_107 ) ;
V_9 = F_5 ( V_100 , V_8 ,
V_184 ) ;
if ( V_9 < 0 ) {
F_55 ( & V_173 -> V_57 , L_24 , V_9 ) ;
goto V_185;
}
V_8 = ~ ( T_5 ) ( V_108 | V_109 | V_110 ) ;
V_9 = F_5 ( V_100 , V_8 ,
V_186 ) ;
if ( V_9 < 0 )
F_28 ( & V_173 -> V_57 , L_24 , V_9 ) ;
F_12 ( V_17 ) ;
if ( F_62 ( & V_17 -> V_96 -> V_57 , & V_187 ) )
F_28 ( & V_173 -> V_57 , L_25 ) ;
if ( F_62 ( & V_17 -> V_96 -> V_57 , & V_188 ) )
F_28 ( & V_173 -> V_57 , L_25 ) ;
if ( F_62 ( & V_17 -> V_95 -> V_57 , & V_188 ) )
F_28 ( & V_173 -> V_57 , L_25 ) ;
if ( F_62 ( & V_17 -> V_95 -> V_57 , & V_187 ) )
F_28 ( & V_173 -> V_57 , L_25 ) ;
F_23 ( V_17 , true ) ;
if ( ! F_19 ( V_17 -> V_64 ) )
F_36 ( & V_17 -> V_126 ,
V_17 -> V_64 -> V_189 ,
NULL ) ;
else
F_18 ( V_17 , false ) ;
if ( V_167 )
F_24 ( V_167 -> V_170 ,
V_167 -> V_171 ) ;
else
F_24 ( 0 , 0 ) ;
return 0 ;
V_185:
F_63 ( V_17 -> V_2 ) ;
return V_9 ;
}
static int T_6 F_64 ( struct V_172 * V_173 )
{
struct V_16 * V_17 = F_65 ( V_173 ) ;
F_23 ( V_17 , false ) ;
F_18 ( V_17 , false ) ;
F_24 ( 0 , 0 ) ;
F_63 ( V_17 -> V_2 ) ;
F_66 ( & V_17 -> V_96 -> V_57 , & V_187 ) ;
F_66 ( & V_17 -> V_96 -> V_57 , & V_188 ) ;
F_66 ( & V_17 -> V_95 -> V_57 , & V_187 ) ;
F_66 ( & V_17 -> V_95 -> V_57 , & V_188 ) ;
F_5 ( V_100 , 0xff ,
V_184 ) ;
F_5 ( V_100 , 0xff ,
V_186 ) ;
return 0 ;
}
