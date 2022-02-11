static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
F_1 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_5 ) ||
F_5 ( V_4 , V_2 -> V_5 . V_6 ) )
F_6 ( & V_2 -> V_5 , V_4 ) ;
}
void F_7 ( struct V_7 * V_8 )
{
F_8 ( V_8 , V_9 ) ;
}
static int F_9 ( const T_1 * V_10 , int V_11 ,
struct V_12 * V_13 ,
T_2 * V_14 )
{
int V_15 , V_16 , V_17 ;
* V_14 = 0 ;
V_17 = 0 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
int V_18 = ( V_10 [ V_15 ] & 0x7F ) * 5 ;
for ( V_16 = 0 ; V_16 < V_13 -> V_19 ; V_16 ++ )
if ( V_13 -> V_20 [ V_16 ] . V_21 == V_18 ) {
* V_14 |= F_10 ( V_16 ) ;
V_17 ++ ;
break;
}
}
return V_17 ;
}
static void F_11 ( struct V_22 * V_23 , const T_1 * V_24 ,
struct V_12 * V_13 ,
struct V_25 * V_26 ,
enum V_27 V_28 )
{
struct V_29 * V_30 ;
T_1 * V_31 ;
T_2 V_32 = V_26 -> V_32 ;
T_3 V_33 = V_13 -> V_34 . V_33 ;
T_4 V_35 ;
if ( ! V_13 -> V_34 . V_36 )
return;
if ( ! V_24 )
return;
if ( V_24 [ 1 ] < sizeof( struct V_29 ) )
return;
V_30 = (struct V_29 * ) ( V_24 + 2 ) ;
switch ( V_30 -> V_37 & V_38 ) {
case V_39 :
if ( V_32 & V_40 ) {
V_33 &= ~ V_41 ;
V_33 &= ~ V_42 ;
}
break;
case V_43 :
if ( V_32 & V_44 ) {
V_33 &= ~ V_41 ;
V_33 &= ~ V_42 ;
}
break;
}
V_33 &= ~ V_45 ;
switch ( V_28 ) {
case V_46 :
case V_47 :
F_12 ( 1 ) ;
case V_48 :
V_33 |= V_49 <<
V_50 ;
break;
case V_51 :
V_33 |= V_52 <<
V_50 ;
break;
case V_53 :
V_33 |= V_54 <<
V_50 ;
break;
}
V_31 = F_13 ( V_23 , sizeof( struct V_55 ) + 2 ) ;
* V_31 ++ = V_56 ;
* V_31 ++ = sizeof( struct V_55 ) ;
memset ( V_31 , 0 , sizeof( struct V_55 ) ) ;
V_35 = F_14 ( V_33 ) ;
memcpy ( V_31 , & V_35 , sizeof( T_3 ) ) ;
V_31 += sizeof( T_3 ) ;
* V_31 ++ = V_13 -> V_34 . V_57 |
( V_13 -> V_34 . V_58 <<
V_59 ) ;
memcpy ( V_31 , & V_13 -> V_34 . V_60 , sizeof( V_13 -> V_34 . V_60 ) ) ;
V_31 += sizeof( V_13 -> V_34 . V_60 ) ;
V_31 += sizeof( T_4 ) ;
V_31 += sizeof( V_61 ) ;
V_31 += sizeof( T_1 ) ;
}
static void F_15 ( struct V_62 * V_63 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_22 * V_23 ;
struct V_64 * V_65 ;
T_1 * V_31 , V_66 ;
T_5 V_67 = 0 , V_68 ;
int V_15 , V_17 , V_69 , V_11 ;
T_3 V_70 ;
struct V_12 * V_13 ;
T_2 V_14 = 0 ;
V_13 = V_2 -> V_71 . V_72 -> V_73 [ V_8 -> V_74 -> V_75 ] ;
if ( V_8 -> V_76 . V_11 ) {
V_69 = F_9 ( V_8 -> V_76 . V_10 ,
V_8 -> V_76 . V_11 ,
V_13 , & V_14 ) ;
} else {
V_14 = ~ 0 ;
V_69 = V_13 -> V_19 ;
}
V_23 = F_16 ( V_2 -> V_71 . V_77 +
sizeof( * V_65 ) +
2 + V_8 -> V_76 . V_78 +
4 + V_69 +
4 +
2 + 2 * V_13 -> V_79 +
2 + sizeof( struct V_55 ) +
V_8 -> V_80 +
9 ,
V_81 ) ;
if ( ! V_23 ) {
F_17 ( V_82 L_1
L_2 , V_63 -> V_83 ) ;
return;
}
F_18 ( V_23 , V_2 -> V_71 . V_77 ) ;
V_70 = V_84 ;
if ( V_13 -> V_75 == V_85 ) {
if ( ! ( V_2 -> V_71 . V_32 & V_86 ) )
V_70 |= V_87 ;
if ( ! ( V_2 -> V_71 . V_32 & V_88 ) )
V_70 |= V_89 ;
}
if ( V_8 -> V_76 . V_90 & V_91 )
V_70 |= V_91 ;
if ( ( V_8 -> V_76 . V_90 & V_92 ) &&
( V_2 -> V_71 . V_32 & V_93 ) )
V_70 |= V_92 ;
V_65 = (struct V_64 * ) F_13 ( V_23 , 24 ) ;
memset ( V_65 , 0 , 24 ) ;
memcpy ( V_65 -> V_94 , V_8 -> V_95 , V_96 ) ;
memcpy ( V_65 -> V_97 , V_63 -> V_98 . V_99 , V_96 ) ;
memcpy ( V_65 -> V_100 , V_8 -> V_95 , V_96 ) ;
if ( ! F_19 ( V_8 -> V_76 . V_101 ) ) {
F_13 ( V_23 , 10 ) ;
V_65 -> V_102 = F_14 ( V_103 |
V_104 ) ;
V_65 -> V_105 . V_106 . V_107 = F_14 ( V_70 ) ;
V_65 -> V_105 . V_106 . V_108 =
F_14 ( V_2 -> V_71 . V_109 . V_108 ) ;
memcpy ( V_65 -> V_105 . V_106 . V_110 , V_8 -> V_76 . V_101 ,
V_96 ) ;
} else {
F_13 ( V_23 , 4 ) ;
V_65 -> V_102 = F_14 ( V_103 |
V_111 ) ;
V_65 -> V_105 . V_112 . V_107 = F_14 ( V_70 ) ;
V_65 -> V_105 . V_112 . V_108 =
F_14 ( V_2 -> V_71 . V_109 . V_108 ) ;
}
V_31 = F_13 ( V_23 , 2 + V_8 -> V_76 . V_78 ) ;
* V_31 ++ = V_113 ;
* V_31 ++ = V_8 -> V_76 . V_78 ;
memcpy ( V_31 , V_8 -> V_76 . V_114 , V_8 -> V_76 . V_78 ) ;
V_11 = V_69 ;
if ( V_11 > 8 )
V_11 = 8 ;
V_31 = F_13 ( V_23 , V_11 + 2 ) ;
* V_31 ++ = V_115 ;
* V_31 ++ = V_11 ;
V_17 = 0 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
if ( F_10 ( V_15 ) & V_14 ) {
int V_18 = V_13 -> V_20 [ V_15 ] . V_21 ;
* V_31 ++ = ( T_1 ) ( V_18 / 5 ) ;
if ( ++ V_17 == 8 )
break;
}
}
if ( V_69 > V_17 ) {
V_31 = F_13 ( V_23 , V_69 - V_17 + 2 ) ;
* V_31 ++ = V_116 ;
* V_31 ++ = V_69 - V_17 ;
for ( V_15 ++ ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
if ( F_10 ( V_15 ) & V_14 ) {
int V_18 = V_13 -> V_20 [ V_15 ] . V_21 ;
* V_31 ++ = ( T_1 ) ( V_18 / 5 ) ;
}
}
}
if ( V_70 & V_92 ) {
V_31 = F_13 ( V_23 , 4 ) ;
* V_31 ++ = V_117 ;
* V_31 ++ = 2 ;
* V_31 ++ = 0 ;
* V_31 ++ = V_8 -> V_74 -> V_118 ;
V_31 = F_13 ( V_23 , 2 * V_13 -> V_79 + 2 ) ;
* V_31 ++ = V_119 ;
* V_31 ++ = 2 * V_13 -> V_79 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_79 ; V_15 ++ ) {
* V_31 ++ = F_20 (
V_13 -> V_120 [ V_15 ] . V_121 ) ;
* V_31 ++ = 1 ;
}
}
if ( V_8 -> V_80 && V_8 -> V_122 ) {
static const T_1 V_123 [] = {
V_113 ,
V_115 ,
V_116 ,
V_117 ,
V_119 ,
V_124 ,
V_125 ,
V_126 ,
V_127 ,
V_128 ,
} ;
V_68 = F_21 ( V_8 -> V_122 , V_8 -> V_80 ,
V_123 , F_22 ( V_123 ) ,
V_67 ) ;
V_31 = F_13 ( V_23 , V_68 - V_67 ) ;
memcpy ( V_31 , V_8 -> V_122 + V_67 , V_68 - V_67 ) ;
V_67 = V_68 ;
}
if ( V_8 -> V_76 . V_129 && V_8 -> V_76 . V_130 &&
V_2 -> V_71 . V_131 >= 4 )
F_11 ( V_23 , V_8 -> V_76 . V_132 ,
V_13 , V_8 -> V_74 , V_8 -> V_76 . V_28 ) ;
if ( V_8 -> V_80 && V_8 -> V_122 ) {
V_68 = F_23 ( V_8 -> V_122 , V_8 -> V_80 ,
V_67 ) ;
V_31 = F_13 ( V_23 , V_68 - V_67 ) ;
memcpy ( V_31 , V_8 -> V_122 + V_67 , V_68 - V_67 ) ;
V_67 = V_68 ;
}
if ( V_8 -> V_76 . V_130 && V_2 -> V_71 . V_131 >= 4 ) {
if ( V_8 -> V_76 . V_133 ) {
V_66 = V_2 -> V_134 ;
V_66 |= ( V_2 -> V_135 <<
V_136 ) ;
} else {
V_66 = 0 ;
}
V_31 = F_13 ( V_23 , 9 ) ;
* V_31 ++ = V_137 ;
* V_31 ++ = 7 ;
* V_31 ++ = 0x00 ;
* V_31 ++ = 0x50 ;
* V_31 ++ = 0xf2 ;
* V_31 ++ = 2 ;
* V_31 ++ = 0 ;
* V_31 ++ = 1 ;
* V_31 ++ = V_66 ;
}
if ( V_8 -> V_80 && V_8 -> V_122 ) {
V_68 = V_8 -> V_80 ;
V_31 = F_13 ( V_23 , V_68 - V_67 ) ;
memcpy ( V_31 , V_8 -> V_122 + V_67 , V_68 - V_67 ) ;
}
F_24 ( V_23 ) -> V_32 |= V_138 ;
F_25 ( V_63 , V_23 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_139 * V_140 ;
T_3 V_141 = V_84 ;
if ( V_8 -> V_142 . V_143 )
V_141 |= V_91 ;
V_140 = F_27 ( V_2 -> V_71 . V_72 , V_8 -> V_74 , V_8 -> V_95 ,
V_8 -> V_142 . V_114 , V_8 -> V_142 . V_78 ,
V_84 | V_91 ,
V_141 ) ;
if ( ! V_140 )
return;
F_28 ( V_2 -> V_71 . V_72 , V_140 ) ;
F_29 ( V_140 ) ;
}
static enum V_144 T_6
F_30 ( struct V_7 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
V_8 -> V_142 . V_145 ++ ;
if ( V_8 -> V_142 . V_145 > V_146 ) {
F_17 ( V_82 L_3 ,
V_63 -> V_83 , V_8 -> V_95 ) ;
F_26 ( V_2 , V_8 ) ;
return V_147 ;
}
F_17 ( V_82 L_4 ,
V_63 -> V_83 , V_8 -> V_95 , V_8 -> V_142 . V_145 ,
V_146 ) ;
F_31 ( V_63 , NULL , V_8 -> V_142 . V_114 ,
V_8 -> V_142 . V_78 , NULL , 0 ) ;
V_8 -> V_4 = V_148 + V_149 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_150 ;
}
static enum V_144 T_6
F_32 ( struct V_7 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
V_8 -> V_142 . V_145 ++ ;
if ( V_8 -> V_142 . V_145 > V_146 ) {
F_17 ( V_82 L_5
L_6 , V_63 -> V_83 , V_8 -> V_95 ) ;
F_26 ( V_2 , V_8 ) ;
return V_147 ;
}
F_17 ( V_82 L_7 ,
V_63 -> V_83 , V_8 -> V_95 , V_8 -> V_142 . V_145 ) ;
F_33 ( V_63 , 1 , V_8 -> V_142 . V_151 , V_8 -> V_122 ,
V_8 -> V_80 , V_8 -> V_95 , NULL , 0 , 0 ) ;
V_8 -> V_142 . V_152 = 2 ;
V_8 -> V_4 = V_148 + V_149 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_150 ;
}
static enum V_144 T_6
F_34 ( struct V_7 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
V_8 -> V_76 . V_145 ++ ;
if ( V_8 -> V_76 . V_145 > V_153 ) {
F_17 ( V_82 L_8
L_6 ,
V_63 -> V_83 , V_8 -> V_95 ) ;
if ( V_8 -> V_76 . V_154 )
F_28 ( V_2 -> V_71 . V_72 , V_8 -> V_76 . V_154 ) ;
return V_147 ;
}
F_17 ( V_82 L_9 ,
V_63 -> V_83 , V_8 -> V_95 , V_8 -> V_76 . V_145 ) ;
F_15 ( V_63 , V_8 ) ;
V_8 -> V_4 = V_148 + V_155 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_150 ;
}
static enum V_144 T_6
F_35 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_156 ) {
V_8 -> V_4 = V_148 + F_36 ( V_8 -> V_157 . V_158 ) ;
F_37 ( V_8 -> V_63 -> V_159 , ( unsigned long ) V_8 ,
V_8 -> V_74 , V_8 -> V_160 ,
V_8 -> V_157 . V_158 , V_81 ) ;
return V_150 ;
}
return V_147 ;
}
static enum V_144 T_6
F_38 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_156 ) {
V_8 -> V_4 = V_148 + F_36 ( V_8 -> V_161 . V_162 ) ;
F_25 ( V_8 -> V_63 , V_8 -> V_161 . V_163 ) ;
return V_150 ;
}
return V_147 ;
}
static enum V_144 T_6
F_39 ( struct V_7 * V_8 )
{
if ( V_8 -> V_156 )
return V_147 ;
F_17 ( V_82 L_10 ,
V_8 -> V_63 -> V_83 , V_8 -> V_95 ) ;
V_8 -> V_4 = F_40 ( V_8 -> V_76 . V_154 -> V_164 ) ;
return V_150 ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_64 * V_65 ,
T_5 V_165 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
T_1 * V_31 ;
struct V_166 V_167 ;
V_31 = V_65 -> V_105 . V_168 . V_169 ;
F_42 ( V_31 , V_165 - ( V_31 - ( T_1 * ) V_65 ) , & V_167 ) ;
if ( ! V_167 . V_170 )
return;
F_33 ( V_63 , 3 , V_8 -> V_142 . V_151 ,
V_167 . V_170 - 2 , V_167 . V_171 + 2 ,
V_8 -> V_95 , V_8 -> V_142 . V_172 ,
V_8 -> V_142 . V_173 , V_8 -> V_142 . V_174 ) ;
V_8 -> V_142 . V_152 = 4 ;
}
static enum V_144 T_6
F_43 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_165 )
{
T_3 V_175 , V_176 , V_177 ;
if ( V_8 -> type != V_178 )
return V_179 ;
if ( V_165 < 24 + 6 )
return V_150 ;
V_175 = F_44 ( V_65 -> V_105 . V_168 . V_175 ) ;
V_176 = F_44 ( V_65 -> V_105 . V_168 . V_176 ) ;
V_177 = F_44 ( V_65 -> V_105 . V_168 . V_177 ) ;
if ( V_175 != V_8 -> V_142 . V_151 ||
V_176 != V_8 -> V_142 . V_152 )
return V_150 ;
if ( V_177 != V_180 ) {
F_17 ( V_82 L_11 ,
V_8 -> V_63 -> V_83 , V_65 -> V_97 , V_177 ) ;
return V_181 ;
}
switch ( V_8 -> V_142 . V_151 ) {
case V_182 :
case V_183 :
case V_184 :
break;
case V_185 :
if ( V_8 -> V_142 . V_152 != 4 ) {
F_41 ( V_8 , V_65 , V_165 ) ;
return V_150 ;
}
break;
default:
F_12 ( 1 ) ;
return V_150 ;
}
F_17 ( V_82 L_12 , V_8 -> V_63 -> V_83 ) ;
return V_181 ;
}
static enum V_144 T_6
F_45 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_165 ,
bool V_186 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_3 V_107 , V_177 , V_187 ;
struct V_166 V_167 ;
T_1 * V_31 ;
if ( V_8 -> type != V_188 )
return V_179 ;
if ( V_165 < 24 + 6 )
return V_150 ;
V_107 = F_44 ( V_65 -> V_105 . V_189 . V_107 ) ;
V_177 = F_44 ( V_65 -> V_105 . V_189 . V_177 ) ;
V_187 = F_44 ( V_65 -> V_105 . V_189 . V_187 ) ;
F_17 ( V_82 L_13
L_14 ,
V_63 -> V_83 , V_186 ? L_15 : L_16 , V_65 -> V_97 ,
V_107 , V_177 , ( T_3 ) ( V_187 & ~ ( F_10 ( 15 ) | F_10 ( 14 ) ) ) ) ;
V_31 = V_65 -> V_105 . V_189 . V_169 ;
F_42 ( V_31 , V_165 - ( V_31 - ( T_1 * ) V_65 ) , & V_167 ) ;
if ( V_177 == V_190 &&
V_167 . V_191 && V_167 . V_192 == 5 &&
V_167 . V_191 [ 0 ] == V_193 ) {
T_2 V_194 , V_195 ;
V_194 = F_46 ( V_167 . V_191 + 1 ) ;
V_195 = V_194 * 1024 / 1000 ;
F_17 ( V_82 L_17
L_18 ,
V_63 -> V_83 , V_65 -> V_97 , V_194 , V_195 ) ;
V_8 -> V_4 = V_148 + F_36 ( V_195 ) ;
if ( V_195 > V_155 )
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_150 ;
}
if ( V_177 != V_180 )
F_17 ( V_82 L_19 ,
V_63 -> V_83 , V_65 -> V_97 , V_177 ) ;
else
F_17 ( V_82 L_20 , V_63 -> V_83 ) ;
return V_181 ;
}
static enum V_144 T_6
F_47 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_165 ,
struct V_196 * V_197 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_5 V_198 ;
F_1 ( V_2 ) ;
if ( V_8 -> type != V_199 )
return V_179 ;
if ( V_165 < 24 + 12 )
return V_150 ;
V_198 = ( T_1 * ) V_65 -> V_105 . V_200 . V_169 - ( T_1 * ) V_65 ;
if ( V_198 > V_165 )
return V_150 ;
F_17 ( V_82 L_21 , V_63 -> V_83 ) ;
return V_181 ;
}
static enum V_144 T_6
F_48 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_165 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
F_1 ( V_2 ) ;
if ( V_8 -> type != V_201 )
return V_179 ;
if ( V_165 < 24 + 12 )
return V_150 ;
F_17 ( V_82 L_22 , V_63 -> V_83 ) ;
return V_181 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_196 * V_197 ;
struct V_64 * V_65 ;
struct V_7 * V_8 ;
enum V_144 V_202 = V_150 ;
T_3 V_203 ;
V_197 = (struct V_196 * ) V_23 -> V_204 ;
V_65 = (struct V_64 * ) V_23 -> V_205 ;
V_203 = F_44 ( V_65 -> V_102 ) ;
F_50 ( & V_2 -> V_3 ) ;
F_51 (wk, &local->work_list, list) {
const T_1 * V_100 = NULL ;
switch ( V_8 -> type ) {
case V_199 :
case V_178 :
case V_188 :
case V_201 :
V_100 = V_8 -> V_95 ;
break;
default:
continue;
}
if ( F_52 ( V_100 , V_65 -> V_100 ) )
continue;
switch ( V_203 & V_206 ) {
case V_207 :
V_202 = F_48 ( V_8 , V_65 , V_23 -> V_165 ) ;
break;
case V_208 :
V_202 = F_47 ( V_8 , V_65 , V_23 -> V_165 ,
V_197 ) ;
break;
case V_209 :
V_202 = F_43 ( V_8 , V_65 , V_23 -> V_165 ) ;
break;
case V_210 :
V_202 = F_45 ( V_8 , V_65 ,
V_23 -> V_165 , false ) ;
break;
case V_211 :
V_202 = F_45 ( V_8 , V_65 ,
V_23 -> V_165 , true ) ;
break;
default:
F_12 ( 1 ) ;
V_202 = V_150 ;
}
if ( V_202 == V_179 )
continue;
break;
}
switch ( V_202 ) {
case V_179 :
break;
case V_150 :
break;
case V_181 :
F_53 ( & V_8 -> V_212 ) ;
break;
default:
F_54 ( 1 , L_23 , V_202 ) ;
}
F_55 ( & V_2 -> V_3 ) ;
if ( V_202 != V_181 )
goto V_213;
switch ( V_8 -> V_214 ( V_8 , V_23 ) ) {
case V_215 :
F_7 ( V_8 ) ;
break;
case V_216 :
F_56 () ;
V_8 -> V_156 = false ;
F_50 ( & V_2 -> V_3 ) ;
F_57 ( & V_8 -> V_212 , & V_2 -> V_217 ) ;
F_55 ( & V_2 -> V_3 ) ;
}
V_213:
F_58 ( V_23 ) ;
}
static bool F_59 ( enum V_218 V_219 ,
enum V_218 V_220 )
{
switch ( V_219 ) {
case V_221 :
return true ;
case V_222 :
if ( V_220 != V_221 )
return true ;
return false ;
case V_223 :
case V_224 :
return ( V_219 == V_220 ) ;
}
F_12 ( 1 ) ;
return false ;
}
static enum V_218
F_60 ( enum V_218 V_219 ,
enum V_218 V_220 )
{
switch ( V_219 ) {
case V_221 :
return V_220 ;
case V_222 :
if ( V_220 != V_221 )
return V_220 ;
return V_219 ;
case V_223 :
case V_224 :
return V_219 ;
}
F_12 ( 1 ) ;
return V_219 ;
}
static void F_61 ( unsigned long V_205 )
{
struct V_1 * V_2 = ( void * ) V_205 ;
if ( V_2 -> V_225 )
return;
F_62 ( & V_2 -> V_71 , & V_2 -> V_226 ) ;
}
static void F_63 ( struct V_227 * V_228 )
{
struct V_1 * V_2 =
F_64 ( V_228 , struct V_1 , V_226 ) ;
struct V_22 * V_23 ;
struct V_7 * V_8 , * V_35 ;
F_65 ( F_7 ) ;
enum V_144 V_202 ;
bool V_229 = false ;
if ( V_2 -> V_230 )
return;
if ( F_54 ( V_2 -> V_231 , L_24 ) )
return;
while ( ( V_23 = F_66 ( & V_2 -> V_232 ) ) )
F_49 ( V_2 , V_23 ) ;
F_50 ( & V_2 -> V_3 ) ;
F_67 ( V_2 ) ;
F_68 (wk, tmp, &local->work_list, list) {
bool V_156 = V_8 -> V_156 ;
if ( ! V_156 && V_2 -> V_233 &&
V_8 -> V_74 == V_2 -> V_233 &&
V_8 -> V_160 == V_2 -> V_234 ) {
V_156 = true ;
V_8 -> V_4 = V_148 ;
}
if ( ! V_156 && ! V_2 -> V_233 ) {
bool V_235 ;
bool V_236 = false ;
bool V_237 ;
enum V_218 V_219 ;
V_235 = F_69 ( V_2 ) ;
V_219 = V_8 -> V_160 ;
if ( V_8 -> V_74 == V_2 -> V_71 . V_109 . V_26 )
V_219 = F_60 ( V_8 -> V_160 ,
V_2 -> V_71 . V_109 . V_238 ) ;
if ( V_2 -> V_233 )
if ( ( V_2 -> V_233 != V_8 -> V_74 ) ||
( V_2 -> V_234 != V_219 ) )
V_236 = true ;
V_2 -> V_233 = V_8 -> V_74 ;
V_2 -> V_234 = V_219 ;
V_237 = F_69 ( V_2 ) ;
if ( V_235 != V_237 ) {
if ( V_237 ) {
F_70 ( V_2 ,
true ) ;
F_71 ( V_2 , 0 ) ;
} else {
F_71 ( V_2 , 0 ) ;
F_72 ( V_2 ,
true ,
false ) ;
}
} else if ( V_236 )
F_71 ( V_2 , 0 ) ;
V_156 = true ;
V_8 -> V_4 = V_148 ;
}
if ( ! V_156 )
continue;
if ( F_73 ( V_8 -> V_4 ) ) {
F_3 ( V_2 , V_8 -> V_4 ) ;
continue;
}
switch ( V_8 -> type ) {
default:
F_12 ( 1 ) ;
V_202 = V_150 ;
break;
case V_239 :
V_202 = V_147 ;
break;
case V_199 :
V_202 = F_30 ( V_8 ) ;
break;
case V_178 :
V_202 = F_32 ( V_8 ) ;
break;
case V_188 :
V_202 = F_34 ( V_8 ) ;
break;
case V_240 :
V_202 = F_35 ( V_8 ) ;
break;
case V_241 :
V_202 = F_38 ( V_8 ) ;
break;
case V_201 :
V_202 = F_39 ( V_8 ) ;
break;
}
V_8 -> V_156 = V_156 ;
switch ( V_202 ) {
case V_150 :
F_3 ( V_2 , V_8 -> V_4 ) ;
break;
case V_147 :
F_53 ( & V_8 -> V_212 ) ;
F_56 () ;
F_74 ( & V_8 -> V_212 , & F_7 ) ;
break;
default:
F_54 ( 1 , L_23 , V_202 ) ;
}
}
F_51 (wk, &local->work_list, list) {
if ( ! V_8 -> V_156 )
continue;
if ( V_8 -> V_74 != V_2 -> V_233 )
continue;
if ( F_59 ( V_8 -> V_160 ,
V_2 -> V_234 ) )
continue;
V_229 = true ;
}
if ( ! V_229 && V_2 -> V_233 ) {
bool V_235 = F_69 ( V_2 ) ;
V_2 -> V_233 = NULL ;
if ( F_69 ( V_2 ) && ! V_235 )
F_71 ( V_2 , 0 ) ;
F_72 ( V_2 , true , true ) ;
F_3 ( V_2 , V_148 + V_242 / 2 ) ;
}
if ( F_75 ( & V_2 -> V_217 ) && V_2 -> V_243 &&
! V_2 -> V_230 )
F_76 ( & V_2 -> V_71 ,
& V_2 -> V_244 ,
F_77 ( 0 ) ) ;
F_67 ( V_2 ) ;
F_55 ( & V_2 -> V_3 ) ;
F_68 (wk, tmp, &free_work, list) {
V_8 -> V_214 ( V_8 , NULL ) ;
F_78 ( & V_8 -> V_212 ) ;
F_79 ( V_8 ) ;
}
}
void F_80 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( F_12 ( ! V_8 -> V_74 ) )
return;
if ( F_12 ( ! V_8 -> V_63 ) )
return;
if ( F_12 ( ! V_8 -> V_214 ) )
return;
if ( F_12 ( ! F_81 ( V_8 -> V_63 ) ) )
return;
V_8 -> V_156 = false ;
V_2 = V_8 -> V_63 -> V_2 ;
F_50 ( & V_2 -> V_3 ) ;
F_57 ( & V_8 -> V_212 , & V_2 -> V_217 ) ;
F_55 ( & V_2 -> V_3 ) ;
F_62 ( & V_2 -> V_71 , & V_2 -> V_226 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( & V_2 -> V_217 ) ;
F_84 ( & V_2 -> V_5 , F_61 ,
( unsigned long ) V_2 ) ;
F_85 ( & V_2 -> V_226 , F_63 ) ;
F_86 ( & V_2 -> V_232 ) ;
}
void F_87 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_7 * V_8 ;
bool V_245 = false ;
F_50 ( & V_2 -> V_3 ) ;
F_51 (wk, &local->work_list, list) {
if ( V_8 -> V_63 != V_63 )
continue;
V_245 = true ;
V_8 -> type = V_239 ;
V_8 -> V_156 = true ;
V_8 -> V_4 = V_148 ;
}
F_55 ( & V_2 -> V_3 ) ;
if ( V_245 )
F_63 ( & V_2 -> V_226 ) ;
F_50 ( & V_2 -> V_3 ) ;
F_51 (wk, &local->work_list, list) {
if ( V_8 -> V_63 != V_63 )
continue;
F_12 ( 1 ) ;
break;
}
F_55 ( & V_2 -> V_3 ) ;
}
T_7 F_88 ( struct V_62 * V_63 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_64 * V_65 ;
struct V_7 * V_8 ;
T_3 V_203 ;
if ( V_23 -> V_165 < 24 )
return V_246 ;
V_65 = (struct V_64 * ) V_23 -> V_205 ;
V_203 = F_44 ( V_65 -> V_102 ) ;
F_89 (wk, &local->work_list, list) {
if ( V_63 != V_8 -> V_63 )
continue;
if ( F_52 ( V_8 -> V_95 , V_65 -> V_97 ) )
continue;
if ( F_52 ( V_8 -> V_95 , V_65 -> V_100 ) )
continue;
switch ( V_203 & V_206 ) {
case V_209 :
case V_208 :
case V_210 :
case V_211 :
case V_207 :
F_90 ( & V_2 -> V_232 , V_23 ) ;
F_62 ( & V_2 -> V_71 , & V_2 -> V_226 ) ;
return V_247 ;
}
}
return V_248 ;
}
static enum V_249 F_91 ( struct V_7 * V_8 ,
struct V_22 * V_23 )
{
F_92 ( V_8 -> V_63 -> V_159 , ( unsigned long ) V_8 ,
V_8 -> V_74 , V_8 -> V_160 ,
V_81 ) ;
return V_215 ;
}
int F_93 ( struct V_62 * V_63 ,
struct V_25 * V_74 ,
enum V_218 V_238 ,
unsigned int V_158 , T_8 * V_250 )
{
struct V_7 * V_8 ;
V_8 = F_94 ( sizeof( * V_8 ) , V_81 ) ;
if ( ! V_8 )
return - V_251 ;
V_8 -> type = V_240 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_160 = V_238 ;
V_8 -> V_63 = V_63 ;
V_8 -> V_214 = F_91 ;
V_8 -> V_157 . V_158 = V_158 ;
* V_250 = ( unsigned long ) V_8 ;
F_80 ( V_8 ) ;
return 0 ;
}
int F_95 ( struct V_62 * V_63 ,
T_8 V_250 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_7 * V_8 , * V_35 ;
bool V_252 = false ;
F_50 ( & V_2 -> V_3 ) ;
F_68 (wk, tmp, &local->work_list, list) {
if ( ( unsigned long ) V_8 == V_250 ) {
V_8 -> V_4 = V_148 ;
V_252 = true ;
break;
}
}
F_55 ( & V_2 -> V_3 ) ;
if ( ! V_252 )
return - V_253 ;
F_62 ( & V_2 -> V_71 , & V_2 -> V_226 ) ;
return 0 ;
}
