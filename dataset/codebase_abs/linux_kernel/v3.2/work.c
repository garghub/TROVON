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
if ( ! V_23 )
return;
F_17 ( V_23 , V_2 -> V_71 . V_77 ) ;
V_70 = V_82 ;
if ( V_13 -> V_75 == V_83 ) {
if ( ! ( V_2 -> V_71 . V_32 & V_84 ) )
V_70 |= V_85 ;
if ( ! ( V_2 -> V_71 . V_32 & V_86 ) )
V_70 |= V_87 ;
}
if ( V_8 -> V_76 . V_88 & V_89 )
V_70 |= V_89 ;
if ( ( V_8 -> V_76 . V_88 & V_90 ) &&
( V_2 -> V_71 . V_32 & V_91 ) )
V_70 |= V_90 ;
V_65 = (struct V_64 * ) F_13 ( V_23 , 24 ) ;
memset ( V_65 , 0 , 24 ) ;
memcpy ( V_65 -> V_92 , V_8 -> V_93 , V_94 ) ;
memcpy ( V_65 -> V_95 , V_63 -> V_96 . V_97 , V_94 ) ;
memcpy ( V_65 -> V_98 , V_8 -> V_93 , V_94 ) ;
if ( ! F_18 ( V_8 -> V_76 . V_99 ) ) {
F_13 ( V_23 , 10 ) ;
V_65 -> V_100 = F_14 ( V_101 |
V_102 ) ;
V_65 -> V_103 . V_104 . V_105 = F_14 ( V_70 ) ;
V_65 -> V_103 . V_104 . V_106 =
F_14 ( V_2 -> V_71 . V_107 . V_106 ) ;
memcpy ( V_65 -> V_103 . V_104 . V_108 , V_8 -> V_76 . V_99 ,
V_94 ) ;
} else {
F_13 ( V_23 , 4 ) ;
V_65 -> V_100 = F_14 ( V_101 |
V_109 ) ;
V_65 -> V_103 . V_110 . V_105 = F_14 ( V_70 ) ;
V_65 -> V_103 . V_110 . V_106 =
F_14 ( V_2 -> V_71 . V_107 . V_106 ) ;
}
V_31 = F_13 ( V_23 , 2 + V_8 -> V_76 . V_78 ) ;
* V_31 ++ = V_111 ;
* V_31 ++ = V_8 -> V_76 . V_78 ;
memcpy ( V_31 , V_8 -> V_76 . V_112 , V_8 -> V_76 . V_78 ) ;
V_11 = V_69 ;
if ( V_11 > 8 )
V_11 = 8 ;
V_31 = F_13 ( V_23 , V_11 + 2 ) ;
* V_31 ++ = V_113 ;
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
* V_31 ++ = V_114 ;
* V_31 ++ = V_69 - V_17 ;
for ( V_15 ++ ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
if ( F_10 ( V_15 ) & V_14 ) {
int V_18 = V_13 -> V_20 [ V_15 ] . V_21 ;
* V_31 ++ = ( T_1 ) ( V_18 / 5 ) ;
}
}
}
if ( V_70 & V_90 ) {
V_31 = F_13 ( V_23 , 4 ) ;
* V_31 ++ = V_115 ;
* V_31 ++ = 2 ;
* V_31 ++ = 0 ;
* V_31 ++ = V_8 -> V_74 -> V_116 ;
V_31 = F_13 ( V_23 , 2 * V_13 -> V_79 + 2 ) ;
* V_31 ++ = V_117 ;
* V_31 ++ = 2 * V_13 -> V_79 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_79 ; V_15 ++ ) {
* V_31 ++ = F_19 (
V_13 -> V_118 [ V_15 ] . V_119 ) ;
* V_31 ++ = 1 ;
}
}
if ( V_8 -> V_80 && V_8 -> V_120 ) {
static const T_1 V_121 [] = {
V_111 ,
V_113 ,
V_114 ,
V_115 ,
V_117 ,
V_122 ,
V_123 ,
V_124 ,
V_125 ,
V_126 ,
} ;
V_68 = F_20 ( V_8 -> V_120 , V_8 -> V_80 ,
V_121 , F_21 ( V_121 ) ,
V_67 ) ;
V_31 = F_13 ( V_23 , V_68 - V_67 ) ;
memcpy ( V_31 , V_8 -> V_120 + V_67 , V_68 - V_67 ) ;
V_67 = V_68 ;
}
if ( V_8 -> V_76 . V_127 && V_8 -> V_76 . V_128 &&
V_2 -> V_71 . V_129 >= 4 )
F_11 ( V_23 , V_8 -> V_76 . V_130 ,
V_13 , V_8 -> V_74 , V_8 -> V_76 . V_28 ) ;
if ( V_8 -> V_80 && V_8 -> V_120 ) {
V_68 = F_22 ( V_8 -> V_120 , V_8 -> V_80 ,
V_67 ) ;
V_31 = F_13 ( V_23 , V_68 - V_67 ) ;
memcpy ( V_31 , V_8 -> V_120 + V_67 , V_68 - V_67 ) ;
V_67 = V_68 ;
}
if ( V_8 -> V_76 . V_128 && V_2 -> V_71 . V_129 >= 4 ) {
if ( V_8 -> V_76 . V_131 ) {
V_66 = V_2 -> V_132 ;
V_66 |= ( V_2 -> V_133 <<
V_134 ) ;
} else {
V_66 = 0 ;
}
V_31 = F_13 ( V_23 , 9 ) ;
* V_31 ++ = V_135 ;
* V_31 ++ = 7 ;
* V_31 ++ = 0x00 ;
* V_31 ++ = 0x50 ;
* V_31 ++ = 0xf2 ;
* V_31 ++ = 2 ;
* V_31 ++ = 0 ;
* V_31 ++ = 1 ;
* V_31 ++ = V_66 ;
}
if ( V_8 -> V_80 && V_8 -> V_120 ) {
V_68 = V_8 -> V_80 ;
V_31 = F_13 ( V_23 , V_68 - V_67 ) ;
memcpy ( V_31 , V_8 -> V_120 + V_67 , V_68 - V_67 ) ;
}
F_23 ( V_23 ) -> V_32 |= V_136 ;
F_24 ( V_63 , V_23 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_137 * V_138 ;
T_3 V_139 = V_82 ;
if ( V_8 -> V_140 . V_141 )
V_139 |= V_89 ;
V_138 = F_26 ( V_2 -> V_71 . V_72 , V_8 -> V_74 , V_8 -> V_93 ,
V_8 -> V_140 . V_112 , V_8 -> V_140 . V_78 ,
V_82 | V_89 ,
V_139 ) ;
if ( ! V_138 )
return;
F_27 ( V_2 -> V_71 . V_72 , V_138 ) ;
F_28 ( V_138 ) ;
}
static enum V_142 T_6
F_29 ( struct V_7 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
if ( ! V_8 -> V_140 . V_143 ) {
int V_144 = F_30 ( V_2 , V_63 , V_8 -> V_93 ,
V_145 ) ;
if ( V_144 )
return V_146 ;
}
V_8 -> V_140 . V_143 = true ;
V_8 -> V_140 . V_147 ++ ;
if ( V_8 -> V_140 . V_147 > V_148 ) {
F_31 ( V_149 L_1 ,
V_63 -> V_150 , V_8 -> V_93 ) ;
F_25 ( V_2 , V_8 ) ;
return V_146 ;
}
F_31 ( V_149 L_2 ,
V_63 -> V_150 , V_8 -> V_93 , V_8 -> V_140 . V_147 ,
V_148 ) ;
F_32 ( V_63 , NULL , V_8 -> V_140 . V_112 ,
V_8 -> V_140 . V_78 , NULL , 0 ,
( T_2 ) - 1 , true , false ) ;
V_8 -> V_4 = V_151 + V_152 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_153 ;
}
static enum V_142 T_6
F_33 ( struct V_7 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
if ( ! V_8 -> V_140 . V_143 ) {
int V_144 = F_30 ( V_2 , V_63 , V_8 -> V_93 ,
V_145 ) ;
if ( V_144 )
return V_146 ;
}
V_8 -> V_140 . V_143 = true ;
V_8 -> V_140 . V_147 ++ ;
if ( V_8 -> V_140 . V_147 > V_148 ) {
F_31 ( V_149 L_3
L_4 , V_63 -> V_150 , V_8 -> V_93 ) ;
F_25 ( V_2 , V_8 ) ;
return V_146 ;
}
F_31 ( V_149 L_5 ,
V_63 -> V_150 , V_8 -> V_93 , V_8 -> V_140 . V_147 ) ;
F_34 ( V_63 , 1 , V_8 -> V_140 . V_154 , V_8 -> V_120 ,
V_8 -> V_80 , V_8 -> V_93 , NULL , 0 , 0 ) ;
V_8 -> V_140 . V_155 = 2 ;
V_8 -> V_4 = V_151 + V_152 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_153 ;
}
static enum V_142 T_6
F_35 ( struct V_7 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
if ( ! V_8 -> V_76 . V_143 ) {
int V_144 = F_30 ( V_2 , V_63 , V_8 -> V_93 ,
V_156 ) ;
if ( V_144 )
return V_146 ;
}
V_8 -> V_76 . V_143 = true ;
V_8 -> V_76 . V_147 ++ ;
if ( V_8 -> V_76 . V_147 > V_157 ) {
F_31 ( V_149 L_6
L_4 ,
V_63 -> V_150 , V_8 -> V_93 ) ;
if ( V_8 -> V_76 . V_158 )
F_27 ( V_2 -> V_71 . V_72 , V_8 -> V_76 . V_158 ) ;
return V_146 ;
}
F_31 ( V_149 L_7 ,
V_63 -> V_150 , V_8 -> V_93 , V_8 -> V_76 . V_147 ) ;
F_15 ( V_63 , V_8 ) ;
V_8 -> V_4 = V_151 + V_159 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_153 ;
}
static enum V_142 T_6
F_36 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_160 ) {
V_8 -> V_4 = V_151 + F_37 ( V_8 -> V_161 . V_162 ) ;
F_38 ( V_8 -> V_63 -> V_163 , ( unsigned long ) V_8 ,
V_8 -> V_74 , V_8 -> V_164 ,
V_8 -> V_161 . V_162 , V_81 ) ;
return V_153 ;
}
return V_146 ;
}
static enum V_142 T_6
F_39 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_160 ) {
V_8 -> V_4 = V_151 + F_37 ( V_8 -> V_165 . V_166 ) ;
F_24 ( V_8 -> V_63 , V_8 -> V_165 . V_167 ) ;
return V_153 ;
}
return V_146 ;
}
static enum V_142 T_6
F_40 ( struct V_7 * V_8 )
{
if ( V_8 -> V_160 )
return V_146 ;
F_31 ( V_149 L_8 ,
V_8 -> V_63 -> V_150 , V_8 -> V_93 ) ;
V_8 -> V_4 = F_41 ( V_8 -> V_76 . V_158 -> V_168 ) ;
return V_153 ;
}
static void F_42 ( struct V_7 * V_8 ,
struct V_64 * V_65 ,
T_5 V_169 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
T_1 * V_31 ;
struct V_170 V_171 ;
V_31 = V_65 -> V_103 . V_172 . V_173 ;
F_43 ( V_31 , V_169 - ( V_31 - ( T_1 * ) V_65 ) , & V_171 ) ;
if ( ! V_171 . V_174 )
return;
F_34 ( V_63 , 3 , V_8 -> V_140 . V_154 ,
V_171 . V_174 - 2 , V_171 . V_175 + 2 ,
V_8 -> V_93 , V_8 -> V_140 . V_176 ,
V_8 -> V_140 . V_177 , V_8 -> V_140 . V_178 ) ;
V_8 -> V_140 . V_155 = 4 ;
}
static enum V_142 T_6
F_44 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_169 )
{
T_3 V_179 , V_180 , V_181 ;
if ( V_8 -> type != V_182 )
return V_183 ;
if ( V_169 < 24 + 6 )
return V_153 ;
V_179 = F_45 ( V_65 -> V_103 . V_172 . V_179 ) ;
V_180 = F_45 ( V_65 -> V_103 . V_172 . V_180 ) ;
V_181 = F_45 ( V_65 -> V_103 . V_172 . V_181 ) ;
if ( V_179 != V_8 -> V_140 . V_154 ||
V_180 != V_8 -> V_140 . V_155 )
return V_153 ;
if ( V_181 != V_184 ) {
F_31 ( V_149 L_9 ,
V_8 -> V_63 -> V_150 , V_65 -> V_95 , V_181 ) ;
return V_185 ;
}
switch ( V_8 -> V_140 . V_154 ) {
case V_186 :
case V_187 :
case V_188 :
break;
case V_189 :
if ( V_8 -> V_140 . V_155 != 4 ) {
F_42 ( V_8 , V_65 , V_169 ) ;
return V_153 ;
}
break;
default:
F_12 ( 1 ) ;
return V_153 ;
}
F_31 ( V_149 L_10 , V_8 -> V_63 -> V_150 ) ;
return V_185 ;
}
static enum V_142 T_6
F_46 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_169 ,
bool V_190 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_3 V_105 , V_181 , V_191 ;
struct V_170 V_171 ;
T_1 * V_31 ;
if ( V_8 -> type != V_192 )
return V_183 ;
if ( V_169 < 24 + 6 )
return V_153 ;
V_105 = F_45 ( V_65 -> V_103 . V_193 . V_105 ) ;
V_181 = F_45 ( V_65 -> V_103 . V_193 . V_181 ) ;
V_191 = F_45 ( V_65 -> V_103 . V_193 . V_191 ) ;
F_31 ( V_149 L_11
L_12 ,
V_63 -> V_150 , V_190 ? L_13 : L_14 , V_65 -> V_95 ,
V_105 , V_181 , ( T_3 ) ( V_191 & ~ ( F_10 ( 15 ) | F_10 ( 14 ) ) ) ) ;
V_31 = V_65 -> V_103 . V_193 . V_173 ;
F_43 ( V_31 , V_169 - ( V_31 - ( T_1 * ) V_65 ) , & V_171 ) ;
if ( V_181 == V_194 &&
V_171 . V_195 && V_171 . V_196 == 5 &&
V_171 . V_195 [ 0 ] == V_197 ) {
T_2 V_198 , V_199 ;
V_198 = F_47 ( V_171 . V_195 + 1 ) ;
V_199 = V_198 * 1024 / 1000 ;
F_31 ( V_149 L_15
L_16 ,
V_63 -> V_150 , V_65 -> V_95 , V_198 , V_199 ) ;
V_8 -> V_4 = V_151 + F_37 ( V_199 ) ;
if ( V_199 > V_159 )
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_153 ;
}
if ( V_181 != V_184 )
F_31 ( V_149 L_17 ,
V_63 -> V_150 , V_65 -> V_95 , V_181 ) ;
else
F_31 ( V_149 L_18 , V_63 -> V_150 ) ;
return V_185 ;
}
static enum V_142 T_6
F_48 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_169 ,
struct V_200 * V_201 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_5 V_202 ;
F_1 ( V_2 ) ;
if ( V_8 -> type != V_203 )
return V_183 ;
if ( V_169 < 24 + 12 )
return V_153 ;
V_202 = ( T_1 * ) V_65 -> V_103 . V_204 . V_173 - ( T_1 * ) V_65 ;
if ( V_202 > V_169 )
return V_153 ;
F_31 ( V_149 L_19 , V_63 -> V_150 ) ;
return V_185 ;
}
static enum V_142 T_6
F_49 ( struct V_7 * V_8 ,
struct V_64 * V_65 , T_5 V_169 )
{
struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_2 = V_63 -> V_2 ;
F_1 ( V_2 ) ;
if ( V_8 -> type != V_205 )
return V_183 ;
if ( V_169 < 24 + 12 )
return V_153 ;
F_31 ( V_149 L_20 , V_63 -> V_150 ) ;
return V_185 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_200 * V_201 ;
struct V_64 * V_65 ;
struct V_7 * V_8 ;
enum V_142 V_206 = V_153 ;
T_3 V_207 ;
V_201 = (struct V_200 * ) V_23 -> V_208 ;
V_65 = (struct V_64 * ) V_23 -> V_209 ;
V_207 = F_45 ( V_65 -> V_100 ) ;
F_51 ( & V_2 -> V_3 ) ;
F_52 (wk, &local->work_list, list) {
const T_1 * V_98 = NULL ;
switch ( V_8 -> type ) {
case V_203 :
case V_182 :
case V_192 :
case V_205 :
V_98 = V_8 -> V_93 ;
break;
default:
continue;
}
if ( F_53 ( V_98 , V_65 -> V_98 ) )
continue;
switch ( V_207 & V_210 ) {
case V_211 :
V_206 = F_49 ( V_8 , V_65 , V_23 -> V_169 ) ;
break;
case V_212 :
V_206 = F_48 ( V_8 , V_65 , V_23 -> V_169 ,
V_201 ) ;
break;
case V_213 :
V_206 = F_44 ( V_8 , V_65 , V_23 -> V_169 ) ;
break;
case V_214 :
V_206 = F_46 ( V_8 , V_65 ,
V_23 -> V_169 , false ) ;
break;
case V_215 :
V_206 = F_46 ( V_8 , V_65 ,
V_23 -> V_169 , true ) ;
break;
default:
F_12 ( 1 ) ;
V_206 = V_153 ;
}
if ( V_206 == V_183 )
continue;
break;
}
switch ( V_206 ) {
case V_183 :
break;
case V_153 :
break;
case V_185 :
F_54 ( & V_8 -> V_216 ) ;
break;
default:
F_55 ( 1 , L_21 , V_206 ) ;
}
F_56 ( & V_2 -> V_3 ) ;
if ( V_206 != V_185 )
goto V_217;
switch ( V_8 -> V_218 ( V_8 , V_23 ) ) {
case V_219 :
F_7 ( V_8 ) ;
break;
case V_220 :
F_57 () ;
V_8 -> V_160 = false ;
F_51 ( & V_2 -> V_3 ) ;
F_58 ( & V_8 -> V_216 , & V_2 -> V_221 ) ;
F_56 ( & V_2 -> V_3 ) ;
}
V_217:
F_59 ( V_23 ) ;
}
static bool F_60 ( enum V_222 V_223 ,
enum V_222 V_224 )
{
switch ( V_223 ) {
case V_225 :
return true ;
case V_226 :
if ( V_224 != V_225 )
return true ;
return false ;
case V_227 :
case V_228 :
return ( V_223 == V_224 ) ;
}
F_12 ( 1 ) ;
return false ;
}
static enum V_222
F_61 ( enum V_222 V_223 ,
enum V_222 V_224 )
{
switch ( V_223 ) {
case V_225 :
return V_224 ;
case V_226 :
if ( V_224 != V_225 )
return V_224 ;
return V_223 ;
case V_227 :
case V_228 :
return V_223 ;
}
F_12 ( 1 ) ;
return V_223 ;
}
static void F_62 ( unsigned long V_209 )
{
struct V_1 * V_2 = ( void * ) V_209 ;
if ( V_2 -> V_229 )
return;
F_63 ( & V_2 -> V_71 , & V_2 -> V_230 ) ;
}
static void F_64 ( struct V_231 * V_232 )
{
struct V_1 * V_2 =
F_65 ( V_232 , struct V_1 , V_230 ) ;
struct V_22 * V_23 ;
struct V_7 * V_8 , * V_35 ;
F_66 ( F_7 ) ;
enum V_142 V_206 ;
bool V_233 = false ;
if ( V_2 -> V_234 )
return;
if ( F_55 ( V_2 -> V_235 , L_22 ) )
return;
while ( ( V_23 = F_67 ( & V_2 -> V_236 ) ) )
F_50 ( V_2 , V_23 ) ;
F_51 ( & V_2 -> V_3 ) ;
F_68 ( V_2 ) ;
F_69 (wk, tmp, &local->work_list, list) {
bool V_160 = V_8 -> V_160 ;
if ( ! V_160 && V_2 -> V_237 &&
V_8 -> V_74 == V_2 -> V_237 &&
V_8 -> V_164 == V_2 -> V_238 ) {
V_160 = true ;
V_8 -> V_4 = V_151 ;
}
if ( ! V_160 && ! V_2 -> V_237 ) {
bool V_239 ;
bool V_240 = false ;
bool V_241 ;
enum V_222 V_223 ;
V_239 = F_70 ( V_2 ) ;
V_223 = V_8 -> V_164 ;
if ( V_8 -> V_74 == V_2 -> V_71 . V_107 . V_26 )
V_223 = F_61 ( V_8 -> V_164 ,
V_2 -> V_71 . V_107 . V_242 ) ;
if ( V_2 -> V_237 )
if ( ( V_2 -> V_237 != V_8 -> V_74 ) ||
( V_2 -> V_238 != V_223 ) )
V_240 = true ;
V_2 -> V_237 = V_8 -> V_74 ;
V_2 -> V_238 = V_223 ;
V_241 = F_70 ( V_2 ) ;
if ( V_239 != V_241 ) {
if ( V_241 ) {
F_71 ( V_2 ,
true ) ;
F_72 ( V_2 , 0 ) ;
} else {
F_72 ( V_2 , 0 ) ;
F_73 ( V_2 ,
true ,
false ) ;
}
} else if ( V_240 )
F_72 ( V_2 , 0 ) ;
V_160 = true ;
V_8 -> V_4 = V_151 ;
}
if ( ! V_160 )
continue;
if ( F_74 ( V_8 -> V_4 ) ) {
F_3 ( V_2 , V_8 -> V_4 ) ;
continue;
}
switch ( V_8 -> type ) {
default:
F_12 ( 1 ) ;
V_206 = V_153 ;
break;
case V_243 :
V_206 = V_146 ;
break;
case V_203 :
V_206 = F_29 ( V_8 ) ;
break;
case V_182 :
V_206 = F_33 ( V_8 ) ;
break;
case V_192 :
V_206 = F_35 ( V_8 ) ;
break;
case V_244 :
V_206 = F_36 ( V_8 ) ;
break;
case V_245 :
V_206 = F_39 ( V_8 ) ;
break;
case V_205 :
V_206 = F_40 ( V_8 ) ;
break;
}
V_8 -> V_160 = V_160 ;
switch ( V_206 ) {
case V_153 :
F_3 ( V_2 , V_8 -> V_4 ) ;
break;
case V_146 :
F_54 ( & V_8 -> V_216 ) ;
F_57 () ;
F_75 ( & V_8 -> V_216 , & F_7 ) ;
break;
default:
F_55 ( 1 , L_21 , V_206 ) ;
}
}
F_52 (wk, &local->work_list, list) {
if ( ! V_8 -> V_160 )
continue;
if ( V_8 -> V_74 != V_2 -> V_237 )
continue;
if ( ! F_60 ( V_8 -> V_164 ,
V_2 -> V_238 ) )
continue;
V_233 = true ;
}
if ( ! V_233 && V_2 -> V_237 ) {
V_2 -> V_237 = NULL ;
if ( ! F_70 ( V_2 ) )
F_72 ( V_2 , 0 ) ;
F_73 ( V_2 , true , true ) ;
F_3 ( V_2 , V_151 + V_246 / 2 ) ;
}
if ( F_76 ( & V_2 -> V_221 ) && V_2 -> V_247 &&
! V_2 -> V_234 )
F_77 ( & V_2 -> V_71 ,
& V_2 -> V_248 ,
F_78 ( 0 ) ) ;
F_68 ( V_2 ) ;
F_56 ( & V_2 -> V_3 ) ;
F_69 (wk, tmp, &free_work, list) {
V_8 -> V_218 ( V_8 , NULL ) ;
F_79 ( & V_8 -> V_216 ) ;
F_80 ( V_8 ) ;
}
}
void F_81 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( F_12 ( ! V_8 -> V_74 ) )
return;
if ( F_12 ( ! V_8 -> V_63 ) )
return;
if ( F_12 ( ! V_8 -> V_218 ) )
return;
if ( F_12 ( ! F_82 ( V_8 -> V_63 ) ) )
return;
V_8 -> V_160 = false ;
V_2 = V_8 -> V_63 -> V_2 ;
F_51 ( & V_2 -> V_3 ) ;
F_58 ( & V_8 -> V_216 , & V_2 -> V_221 ) ;
F_56 ( & V_2 -> V_3 ) ;
F_63 ( & V_2 -> V_71 , & V_2 -> V_230 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_221 ) ;
F_85 ( & V_2 -> V_5 , F_62 ,
( unsigned long ) V_2 ) ;
F_86 ( & V_2 -> V_230 , F_64 ) ;
F_87 ( & V_2 -> V_236 ) ;
}
void F_88 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_7 * V_8 ;
bool V_249 = false ;
F_51 ( & V_2 -> V_3 ) ;
F_52 (wk, &local->work_list, list) {
if ( V_8 -> V_63 != V_63 )
continue;
V_249 = true ;
V_8 -> type = V_243 ;
V_8 -> V_160 = true ;
V_8 -> V_4 = V_151 ;
}
F_56 ( & V_2 -> V_3 ) ;
if ( V_249 )
F_64 ( & V_2 -> V_230 ) ;
F_51 ( & V_2 -> V_3 ) ;
F_52 (wk, &local->work_list, list) {
if ( V_8 -> V_63 != V_63 )
continue;
F_12 ( 1 ) ;
break;
}
F_56 ( & V_2 -> V_3 ) ;
}
T_7 F_89 ( struct V_62 * V_63 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_64 * V_65 ;
struct V_7 * V_8 ;
T_3 V_207 ;
if ( V_23 -> V_169 < 24 )
return V_250 ;
V_65 = (struct V_64 * ) V_23 -> V_209 ;
V_207 = F_45 ( V_65 -> V_100 ) ;
F_90 (wk, &local->work_list, list) {
if ( V_63 != V_8 -> V_63 )
continue;
if ( F_53 ( V_8 -> V_93 , V_65 -> V_95 ) )
continue;
if ( F_53 ( V_8 -> V_93 , V_65 -> V_98 ) )
continue;
switch ( V_207 & V_210 ) {
case V_213 :
case V_212 :
case V_214 :
case V_215 :
case V_211 :
F_91 ( & V_2 -> V_236 , V_23 ) ;
F_63 ( & V_2 -> V_71 , & V_2 -> V_230 ) ;
return V_251 ;
}
}
return V_252 ;
}
static enum V_253 F_92 ( struct V_7 * V_8 ,
struct V_22 * V_23 )
{
F_93 ( V_8 -> V_63 -> V_163 , ( unsigned long ) V_8 ,
V_8 -> V_74 , V_8 -> V_164 ,
V_81 ) ;
return V_219 ;
}
int F_94 ( struct V_62 * V_63 ,
struct V_25 * V_74 ,
enum V_222 V_242 ,
unsigned int V_162 , T_8 * V_254 )
{
struct V_7 * V_8 ;
V_8 = F_95 ( sizeof( * V_8 ) , V_81 ) ;
if ( ! V_8 )
return - V_255 ;
V_8 -> type = V_244 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_164 = V_242 ;
V_8 -> V_63 = V_63 ;
V_8 -> V_218 = F_92 ;
V_8 -> V_161 . V_162 = V_162 ;
* V_254 = ( unsigned long ) V_8 ;
F_81 ( V_8 ) ;
return 0 ;
}
int F_96 ( struct V_62 * V_63 ,
T_8 V_254 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_7 * V_8 , * V_35 ;
bool V_256 = false ;
F_51 ( & V_2 -> V_3 ) ;
F_69 (wk, tmp, &local->work_list, list) {
if ( ( unsigned long ) V_8 == V_254 ) {
V_8 -> V_4 = V_151 ;
V_256 = true ;
break;
}
}
F_56 ( & V_2 -> V_3 ) ;
if ( ! V_256 )
return - V_257 ;
F_63 ( & V_2 -> V_71 , & V_2 -> V_230 ) ;
return 0 ;
}
