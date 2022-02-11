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
static void F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 , const T_1 * V_26 ,
struct V_12 * V_13 ,
struct V_27 * V_28 ,
enum V_29 V_30 )
{
struct V_31 * V_32 ;
T_1 * V_33 ;
T_2 V_34 = V_28 -> V_34 ;
T_3 V_35 ;
struct V_36 V_37 ;
F_12 ( sizeof( V_37 ) != sizeof( V_13 -> V_37 ) ) ;
if ( ! V_13 -> V_37 . V_38 )
return;
if ( ! V_26 )
return;
if ( V_26 [ 1 ] < sizeof( struct V_31 ) )
return;
memcpy ( & V_37 , & V_13 -> V_37 , sizeof( V_37 ) ) ;
F_13 ( V_23 , & V_37 ) ;
V_32 = (struct V_31 * ) ( V_26 + 2 ) ;
V_35 = V_37 . V_35 ;
switch ( V_32 -> V_39 & V_40 ) {
case V_41 :
if ( V_34 & V_42 ) {
V_35 &= ~ V_43 ;
V_35 &= ~ V_44 ;
}
break;
case V_45 :
if ( V_34 & V_46 ) {
V_35 &= ~ V_43 ;
V_35 &= ~ V_44 ;
}
break;
}
V_35 &= ~ V_47 ;
switch ( V_30 ) {
case V_48 :
case V_49 :
F_14 ( 1 ) ;
case V_50 :
V_35 |= V_51 <<
V_52 ;
break;
case V_53 :
V_35 |= V_54 <<
V_52 ;
break;
case V_55 :
V_35 |= V_56 <<
V_52 ;
break;
}
V_33 = F_15 ( V_25 , sizeof( struct V_57 ) + 2 ) ;
F_16 ( V_33 , & V_37 , V_35 ) ;
}
static void F_17 ( struct V_22 * V_23 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_24 * V_25 ;
struct V_58 * V_59 ;
T_1 * V_33 , V_60 ;
T_4 V_61 = 0 , V_62 ;
int V_15 , V_17 , V_63 , V_11 ;
T_3 V_64 ;
struct V_12 * V_13 ;
T_2 V_14 = 0 ;
V_13 = V_2 -> V_65 . V_66 -> V_67 [ V_8 -> V_68 -> V_69 ] ;
if ( V_8 -> V_70 . V_11 ) {
V_63 = F_9 ( V_8 -> V_70 . V_10 ,
V_8 -> V_70 . V_11 ,
V_13 , & V_14 ) ;
} else {
V_14 = ~ 0 ;
V_63 = V_13 -> V_19 ;
}
V_25 = F_18 ( V_2 -> V_65 . V_71 +
sizeof( * V_59 ) +
2 + V_8 -> V_70 . V_72 +
4 + V_63 +
4 +
2 + 2 * V_13 -> V_73 +
2 + sizeof( struct V_57 ) +
V_8 -> V_74 +
9 ,
V_75 ) ;
if ( ! V_25 )
return;
F_19 ( V_25 , V_2 -> V_65 . V_71 ) ;
V_64 = V_76 ;
if ( V_13 -> V_69 == V_77 ) {
if ( ! ( V_2 -> V_65 . V_34 & V_78 ) )
V_64 |= V_79 ;
if ( ! ( V_2 -> V_65 . V_34 & V_80 ) )
V_64 |= V_81 ;
}
if ( V_8 -> V_70 . V_82 & V_83 )
V_64 |= V_83 ;
if ( ( V_8 -> V_70 . V_82 & V_84 ) &&
( V_2 -> V_65 . V_34 & V_85 ) )
V_64 |= V_84 ;
V_59 = (struct V_58 * ) F_15 ( V_25 , 24 ) ;
memset ( V_59 , 0 , 24 ) ;
memcpy ( V_59 -> V_86 , V_8 -> V_87 , V_88 ) ;
memcpy ( V_59 -> V_89 , V_23 -> V_90 . V_91 , V_88 ) ;
memcpy ( V_59 -> V_92 , V_8 -> V_87 , V_88 ) ;
if ( ! F_20 ( V_8 -> V_70 . V_93 ) ) {
F_15 ( V_25 , 10 ) ;
V_59 -> V_94 = F_21 ( V_95 |
V_96 ) ;
V_59 -> V_97 . V_98 . V_99 = F_21 ( V_64 ) ;
V_59 -> V_97 . V_98 . V_100 =
F_21 ( V_2 -> V_65 . V_101 . V_100 ) ;
memcpy ( V_59 -> V_97 . V_98 . V_102 , V_8 -> V_70 . V_93 ,
V_88 ) ;
} else {
F_15 ( V_25 , 4 ) ;
V_59 -> V_94 = F_21 ( V_95 |
V_103 ) ;
V_59 -> V_97 . V_104 . V_99 = F_21 ( V_64 ) ;
V_59 -> V_97 . V_104 . V_100 =
F_21 ( V_2 -> V_65 . V_101 . V_100 ) ;
}
V_33 = F_15 ( V_25 , 2 + V_8 -> V_70 . V_72 ) ;
* V_33 ++ = V_105 ;
* V_33 ++ = V_8 -> V_70 . V_72 ;
memcpy ( V_33 , V_8 -> V_70 . V_106 , V_8 -> V_70 . V_72 ) ;
V_11 = V_63 ;
if ( V_11 > 8 )
V_11 = 8 ;
V_33 = F_15 ( V_25 , V_11 + 2 ) ;
* V_33 ++ = V_107 ;
* V_33 ++ = V_11 ;
V_17 = 0 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
if ( F_10 ( V_15 ) & V_14 ) {
int V_18 = V_13 -> V_20 [ V_15 ] . V_21 ;
* V_33 ++ = ( T_1 ) ( V_18 / 5 ) ;
if ( ++ V_17 == 8 )
break;
}
}
if ( V_63 > V_17 ) {
V_33 = F_15 ( V_25 , V_63 - V_17 + 2 ) ;
* V_33 ++ = V_108 ;
* V_33 ++ = V_63 - V_17 ;
for ( V_15 ++ ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
if ( F_10 ( V_15 ) & V_14 ) {
int V_18 = V_13 -> V_20 [ V_15 ] . V_21 ;
* V_33 ++ = ( T_1 ) ( V_18 / 5 ) ;
}
}
}
if ( V_64 & V_84 ) {
V_33 = F_15 ( V_25 , 4 ) ;
* V_33 ++ = V_109 ;
* V_33 ++ = 2 ;
* V_33 ++ = 0 ;
* V_33 ++ = V_8 -> V_68 -> V_110 ;
V_33 = F_15 ( V_25 , 2 * V_13 -> V_73 + 2 ) ;
* V_33 ++ = V_111 ;
* V_33 ++ = 2 * V_13 -> V_73 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_73 ; V_15 ++ ) {
* V_33 ++ = F_22 (
V_13 -> V_112 [ V_15 ] . V_113 ) ;
* V_33 ++ = 1 ;
}
}
if ( V_8 -> V_74 && V_8 -> V_114 ) {
static const T_1 V_115 [] = {
V_105 ,
V_107 ,
V_108 ,
V_109 ,
V_111 ,
V_116 ,
V_117 ,
V_118 ,
V_119 ,
V_120 ,
} ;
V_62 = F_23 ( V_8 -> V_114 , V_8 -> V_74 ,
V_115 , F_24 ( V_115 ) ,
V_61 ) ;
V_33 = F_15 ( V_25 , V_62 - V_61 ) ;
memcpy ( V_33 , V_8 -> V_114 + V_61 , V_62 - V_61 ) ;
V_61 = V_62 ;
}
if ( V_8 -> V_70 . V_121 && V_8 -> V_70 . V_122 &&
V_2 -> V_65 . V_123 >= 4 )
F_11 ( V_23 , V_25 , V_8 -> V_70 . V_124 ,
V_13 , V_8 -> V_68 , V_8 -> V_70 . V_30 ) ;
if ( V_8 -> V_74 && V_8 -> V_114 ) {
V_62 = F_25 ( V_8 -> V_114 , V_8 -> V_74 ,
V_61 ) ;
V_33 = F_15 ( V_25 , V_62 - V_61 ) ;
memcpy ( V_33 , V_8 -> V_114 + V_61 , V_62 - V_61 ) ;
V_61 = V_62 ;
}
if ( V_8 -> V_70 . V_122 && V_2 -> V_65 . V_123 >= 4 ) {
if ( V_8 -> V_70 . V_125 ) {
V_60 = V_2 -> V_126 ;
V_60 |= ( V_2 -> V_127 <<
V_128 ) ;
} else {
V_60 = 0 ;
}
V_33 = F_15 ( V_25 , 9 ) ;
* V_33 ++ = V_129 ;
* V_33 ++ = 7 ;
* V_33 ++ = 0x00 ;
* V_33 ++ = 0x50 ;
* V_33 ++ = 0xf2 ;
* V_33 ++ = 2 ;
* V_33 ++ = 0 ;
* V_33 ++ = 1 ;
* V_33 ++ = V_60 ;
}
if ( V_8 -> V_74 && V_8 -> V_114 ) {
V_62 = V_8 -> V_74 ;
V_33 = F_15 ( V_25 , V_62 - V_61 ) ;
memcpy ( V_33 , V_8 -> V_114 + V_61 , V_62 - V_61 ) ;
}
F_26 ( V_25 ) -> V_34 |= V_130 ;
F_27 ( V_23 , V_25 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_131 * V_132 ;
T_3 V_133 = V_76 ;
if ( V_8 -> V_134 . V_135 )
V_133 |= V_83 ;
V_132 = F_29 ( V_2 -> V_65 . V_66 , V_8 -> V_68 , V_8 -> V_87 ,
V_8 -> V_134 . V_106 , V_8 -> V_134 . V_72 ,
V_76 | V_83 ,
V_133 ) ;
if ( ! V_132 )
return;
F_30 ( V_2 -> V_65 . V_66 , V_132 ) ;
F_31 ( V_132 ) ;
}
static enum V_136 T_5
F_32 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_2 ;
if ( ! V_8 -> V_134 . V_137 ) {
int V_138 = F_33 ( V_2 , V_23 , V_8 -> V_87 ,
V_139 ) ;
if ( V_138 )
return V_140 ;
}
V_8 -> V_134 . V_137 = true ;
V_8 -> V_134 . V_141 ++ ;
if ( V_8 -> V_134 . V_141 > V_142 ) {
F_34 ( V_143 L_1 ,
V_23 -> V_144 , V_8 -> V_87 ) ;
F_28 ( V_2 , V_8 ) ;
return V_140 ;
}
F_34 ( V_143 L_2 ,
V_23 -> V_144 , V_8 -> V_87 , V_8 -> V_134 . V_141 ,
V_142 ) ;
F_35 ( V_23 , NULL , V_8 -> V_134 . V_106 ,
V_8 -> V_134 . V_72 , NULL , 0 ,
( T_2 ) - 1 , true , false ) ;
V_8 -> V_4 = V_145 + V_146 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_147 ;
}
static enum V_136 T_5
F_36 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_2 ;
if ( ! V_8 -> V_134 . V_137 ) {
int V_138 = F_33 ( V_2 , V_23 , V_8 -> V_87 ,
V_139 ) ;
if ( V_138 )
return V_140 ;
}
V_8 -> V_134 . V_137 = true ;
V_8 -> V_134 . V_141 ++ ;
if ( V_8 -> V_134 . V_141 > V_142 ) {
F_34 ( V_143 L_3
L_4 , V_23 -> V_144 , V_8 -> V_87 ) ;
F_28 ( V_2 , V_8 ) ;
return V_140 ;
}
F_34 ( V_143 L_5 ,
V_23 -> V_144 , V_8 -> V_87 , V_8 -> V_134 . V_141 ) ;
F_37 ( V_23 , 1 , V_8 -> V_134 . V_148 , V_8 -> V_114 ,
V_8 -> V_74 , V_8 -> V_87 , NULL , 0 , 0 ) ;
V_8 -> V_134 . V_149 = 2 ;
V_8 -> V_4 = V_145 + V_146 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_147 ;
}
static enum V_136 T_5
F_38 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_2 ;
if ( ! V_8 -> V_70 . V_137 ) {
int V_138 = F_33 ( V_2 , V_23 , V_8 -> V_87 ,
V_150 ) ;
if ( V_138 )
return V_140 ;
}
V_8 -> V_70 . V_137 = true ;
V_8 -> V_70 . V_141 ++ ;
if ( V_8 -> V_70 . V_141 > V_151 ) {
F_34 ( V_143 L_6
L_4 ,
V_23 -> V_144 , V_8 -> V_87 ) ;
if ( V_8 -> V_70 . V_152 )
F_30 ( V_2 -> V_65 . V_66 , V_8 -> V_70 . V_152 ) ;
return V_140 ;
}
F_34 ( V_143 L_7 ,
V_23 -> V_144 , V_8 -> V_87 , V_8 -> V_70 . V_141 ) ;
F_17 ( V_23 , V_8 ) ;
V_8 -> V_4 = V_145 + V_153 ;
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_147 ;
}
static enum V_136 T_5
F_39 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_154 ) {
V_8 -> V_4 = V_145 + F_40 ( V_8 -> V_155 . V_156 ) ;
F_41 ( V_8 -> V_23 -> V_157 , ( unsigned long ) V_8 ,
V_8 -> V_68 , V_8 -> V_158 ,
V_8 -> V_155 . V_156 , V_75 ) ;
return V_147 ;
}
return V_140 ;
}
static enum V_136 T_5
F_42 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_154 ) {
V_8 -> V_4 = V_145 + F_40 ( V_8 -> V_159 . V_160 ) ;
F_27 ( V_8 -> V_23 , V_8 -> V_159 . V_161 ) ;
return V_147 ;
}
return V_140 ;
}
static enum V_136 T_5
F_43 ( struct V_7 * V_8 )
{
if ( V_8 -> V_154 )
return V_140 ;
F_34 ( V_143 L_8 ,
V_8 -> V_23 -> V_144 , V_8 -> V_87 ) ;
V_8 -> V_4 = F_44 ( V_8 -> V_70 . V_152 -> V_162 ) ;
return V_147 ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_58 * V_59 ,
T_4 V_163 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
T_1 * V_33 ;
struct V_164 V_165 ;
V_33 = V_59 -> V_97 . V_166 . V_167 ;
F_46 ( V_33 , V_163 - ( V_33 - ( T_1 * ) V_59 ) , & V_165 ) ;
if ( ! V_165 . V_168 )
return;
F_37 ( V_23 , 3 , V_8 -> V_134 . V_148 ,
V_165 . V_168 - 2 , V_165 . V_169 + 2 ,
V_8 -> V_87 , V_8 -> V_134 . V_170 ,
V_8 -> V_134 . V_171 , V_8 -> V_134 . V_172 ) ;
V_8 -> V_134 . V_149 = 4 ;
}
static enum V_136 T_5
F_47 ( struct V_7 * V_8 ,
struct V_58 * V_59 , T_4 V_163 )
{
T_3 V_173 , V_174 , V_175 ;
if ( V_8 -> type != V_176 )
return V_177 ;
if ( V_163 < 24 + 6 )
return V_147 ;
V_173 = F_48 ( V_59 -> V_97 . V_166 . V_173 ) ;
V_174 = F_48 ( V_59 -> V_97 . V_166 . V_174 ) ;
V_175 = F_48 ( V_59 -> V_97 . V_166 . V_175 ) ;
if ( V_173 != V_8 -> V_134 . V_148 ||
V_174 != V_8 -> V_134 . V_149 )
return V_147 ;
if ( V_175 != V_178 ) {
F_34 ( V_143 L_9 ,
V_8 -> V_23 -> V_144 , V_59 -> V_89 , V_175 ) ;
return V_179 ;
}
switch ( V_8 -> V_134 . V_148 ) {
case V_180 :
case V_181 :
case V_182 :
break;
case V_183 :
if ( V_8 -> V_134 . V_149 != 4 ) {
F_45 ( V_8 , V_59 , V_163 ) ;
return V_147 ;
}
break;
default:
F_14 ( 1 ) ;
return V_147 ;
}
F_34 ( V_143 L_10 , V_8 -> V_23 -> V_144 ) ;
return V_179 ;
}
static enum V_136 T_5
F_49 ( struct V_7 * V_8 ,
struct V_58 * V_59 , T_4 V_163 ,
bool V_184 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_2 ;
T_3 V_99 , V_175 , V_185 ;
struct V_164 V_165 ;
T_1 * V_33 ;
if ( V_8 -> type != V_186 )
return V_177 ;
if ( V_163 < 24 + 6 )
return V_147 ;
V_99 = F_48 ( V_59 -> V_97 . V_187 . V_99 ) ;
V_175 = F_48 ( V_59 -> V_97 . V_187 . V_175 ) ;
V_185 = F_48 ( V_59 -> V_97 . V_187 . V_185 ) ;
F_34 ( V_143 L_11
L_12 ,
V_23 -> V_144 , V_184 ? L_13 : L_14 , V_59 -> V_89 ,
V_99 , V_175 , ( T_3 ) ( V_185 & ~ ( F_10 ( 15 ) | F_10 ( 14 ) ) ) ) ;
V_33 = V_59 -> V_97 . V_187 . V_167 ;
F_46 ( V_33 , V_163 - ( V_33 - ( T_1 * ) V_59 ) , & V_165 ) ;
if ( V_175 == V_188 &&
V_165 . V_189 && V_165 . V_190 == 5 &&
V_165 . V_189 [ 0 ] == V_191 ) {
T_2 V_192 , V_193 ;
V_192 = F_50 ( V_165 . V_189 + 1 ) ;
V_193 = V_192 * 1024 / 1000 ;
F_34 ( V_143 L_15
L_16 ,
V_23 -> V_144 , V_59 -> V_89 , V_192 , V_193 ) ;
V_8 -> V_4 = V_145 + F_40 ( V_193 ) ;
if ( V_193 > V_153 )
F_3 ( V_2 , V_8 -> V_4 ) ;
return V_147 ;
}
if ( V_175 != V_178 )
F_34 ( V_143 L_17 ,
V_23 -> V_144 , V_59 -> V_89 , V_175 ) ;
else
F_34 ( V_143 L_18 , V_23 -> V_144 ) ;
return V_179 ;
}
static enum V_136 T_5
F_51 ( struct V_7 * V_8 ,
struct V_58 * V_59 , T_4 V_163 ,
struct V_194 * V_195 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_2 ;
T_4 V_196 ;
F_1 ( V_2 ) ;
if ( V_8 -> type != V_197 )
return V_177 ;
if ( V_163 < 24 + 12 )
return V_147 ;
V_196 = ( T_1 * ) V_59 -> V_97 . V_198 . V_167 - ( T_1 * ) V_59 ;
if ( V_196 > V_163 )
return V_147 ;
F_34 ( V_143 L_19 , V_23 -> V_144 ) ;
return V_179 ;
}
static enum V_136 T_5
F_52 ( struct V_7 * V_8 ,
struct V_58 * V_59 , T_4 V_163 )
{
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_2 ;
F_1 ( V_2 ) ;
if ( V_8 -> type != V_199 )
return V_177 ;
if ( V_163 < 24 + 12 )
return V_147 ;
F_34 ( V_143 L_20 , V_23 -> V_144 ) ;
return V_179 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_194 * V_195 ;
struct V_58 * V_59 ;
struct V_7 * V_8 ;
enum V_136 V_200 = V_147 ;
T_3 V_201 ;
V_195 = (struct V_194 * ) V_25 -> V_202 ;
V_59 = (struct V_58 * ) V_25 -> V_203 ;
V_201 = F_48 ( V_59 -> V_94 ) ;
F_54 ( & V_2 -> V_3 ) ;
F_55 (wk, &local->work_list, list) {
const T_1 * V_92 = NULL ;
switch ( V_8 -> type ) {
case V_197 :
case V_176 :
case V_186 :
case V_199 :
V_92 = V_8 -> V_87 ;
break;
default:
continue;
}
if ( F_56 ( V_92 , V_59 -> V_92 ) )
continue;
switch ( V_201 & V_204 ) {
case V_205 :
V_200 = F_52 ( V_8 , V_59 , V_25 -> V_163 ) ;
break;
case V_206 :
V_200 = F_51 ( V_8 , V_59 , V_25 -> V_163 ,
V_195 ) ;
break;
case V_207 :
V_200 = F_47 ( V_8 , V_59 , V_25 -> V_163 ) ;
break;
case V_208 :
V_200 = F_49 ( V_8 , V_59 ,
V_25 -> V_163 , false ) ;
break;
case V_209 :
V_200 = F_49 ( V_8 , V_59 ,
V_25 -> V_163 , true ) ;
break;
default:
F_14 ( 1 ) ;
V_200 = V_147 ;
}
if ( V_200 == V_177 )
continue;
break;
}
switch ( V_200 ) {
case V_177 :
break;
case V_147 :
break;
case V_179 :
F_57 ( & V_8 -> V_210 ) ;
break;
default:
F_58 ( 1 , L_21 , V_200 ) ;
}
F_59 ( & V_2 -> V_3 ) ;
if ( V_200 != V_179 )
goto V_211;
switch ( V_8 -> V_212 ( V_8 , V_25 ) ) {
case V_213 :
F_7 ( V_8 ) ;
break;
case V_214 :
F_60 () ;
V_8 -> V_154 = false ;
F_54 ( & V_2 -> V_3 ) ;
F_61 ( & V_8 -> V_210 , & V_2 -> V_215 ) ;
F_59 ( & V_2 -> V_3 ) ;
}
V_211:
F_62 ( V_25 ) ;
}
static void F_63 ( unsigned long V_203 )
{
struct V_1 * V_2 = ( void * ) V_203 ;
if ( V_2 -> V_216 )
return;
F_64 ( & V_2 -> V_65 , & V_2 -> V_217 ) ;
}
static void F_65 ( struct V_218 * V_219 )
{
struct V_1 * V_2 =
F_66 ( V_219 , struct V_1 , V_217 ) ;
struct V_24 * V_25 ;
struct V_7 * V_8 , * V_220 ;
F_67 ( F_7 ) ;
enum V_136 V_200 ;
bool V_221 = false ;
if ( V_2 -> V_222 )
return;
if ( F_58 ( V_2 -> V_223 , L_22 ) )
return;
while ( ( V_25 = F_68 ( & V_2 -> V_224 ) ) )
F_53 ( V_2 , V_25 ) ;
F_54 ( & V_2 -> V_3 ) ;
F_69 ( V_2 ) ;
F_70 (wk, tmp, &local->work_list, list) {
bool V_154 = V_8 -> V_154 ;
if ( ! V_154 && V_2 -> V_225 &&
V_8 -> V_68 == V_2 -> V_225 &&
V_8 -> V_158 == V_2 -> V_226 ) {
V_154 = true ;
V_8 -> V_4 = V_145 ;
}
if ( ! V_154 && ! V_2 -> V_225 ) {
F_71 ( V_2 , true ) ;
V_2 -> V_225 = V_8 -> V_68 ;
V_2 -> V_226 = V_8 -> V_158 ;
F_72 ( V_2 , 0 ) ;
V_154 = true ;
V_8 -> V_4 = V_145 ;
}
if ( ! V_154 )
continue;
if ( F_73 ( V_8 -> V_4 ) ) {
F_3 ( V_2 , V_8 -> V_4 ) ;
continue;
}
switch ( V_8 -> type ) {
default:
F_14 ( 1 ) ;
V_200 = V_147 ;
break;
case V_227 :
V_200 = V_140 ;
break;
case V_197 :
V_200 = F_32 ( V_8 ) ;
break;
case V_176 :
V_200 = F_36 ( V_8 ) ;
break;
case V_186 :
V_200 = F_38 ( V_8 ) ;
break;
case V_228 :
V_200 = F_39 ( V_8 ) ;
break;
case V_229 :
V_200 = F_42 ( V_8 ) ;
break;
case V_199 :
V_200 = F_43 ( V_8 ) ;
break;
}
V_8 -> V_154 = V_154 ;
switch ( V_200 ) {
case V_147 :
F_3 ( V_2 , V_8 -> V_4 ) ;
break;
case V_140 :
F_57 ( & V_8 -> V_210 ) ;
F_60 () ;
F_74 ( & V_8 -> V_210 , & F_7 ) ;
break;
default:
F_58 ( 1 , L_21 , V_200 ) ;
}
}
F_55 (wk, &local->work_list, list) {
if ( ! V_8 -> V_154 )
continue;
if ( V_8 -> V_68 != V_2 -> V_225 ||
V_8 -> V_158 != V_2 -> V_226 )
continue;
V_221 = true ;
}
if ( ! V_221 && V_2 -> V_225 ) {
V_2 -> V_225 = NULL ;
F_72 ( V_2 , 0 ) ;
F_75 ( V_2 , true ) ;
F_3 ( V_2 , V_145 + V_230 / 2 ) ;
}
if ( F_76 ( & V_2 -> V_215 ) && V_2 -> V_231 &&
! V_2 -> V_222 )
F_77 ( & V_2 -> V_65 ,
& V_2 -> V_232 ,
F_78 ( 0 ) ) ;
F_69 ( V_2 ) ;
F_59 ( & V_2 -> V_3 ) ;
F_70 (wk, tmp, &free_work, list) {
V_8 -> V_212 ( V_8 , NULL ) ;
F_79 ( & V_8 -> V_210 ) ;
F_80 ( V_8 ) ;
}
}
void F_81 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( F_14 ( ! V_8 -> V_68 ) )
return;
if ( F_14 ( ! V_8 -> V_23 ) )
return;
if ( F_14 ( ! V_8 -> V_212 ) )
return;
if ( F_14 ( ! F_82 ( V_8 -> V_23 ) ) )
return;
V_8 -> V_154 = false ;
V_2 = V_8 -> V_23 -> V_2 ;
F_54 ( & V_2 -> V_3 ) ;
F_61 ( & V_8 -> V_210 , & V_2 -> V_215 ) ;
F_59 ( & V_2 -> V_3 ) ;
F_64 ( & V_2 -> V_65 , & V_2 -> V_217 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_215 ) ;
F_85 ( & V_2 -> V_5 , F_63 ,
( unsigned long ) V_2 ) ;
F_86 ( & V_2 -> V_217 , F_65 ) ;
F_87 ( & V_2 -> V_224 ) ;
}
void F_88 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_7 * V_8 ;
bool V_233 = false ;
F_54 ( & V_2 -> V_3 ) ;
F_55 (wk, &local->work_list, list) {
if ( V_8 -> V_23 != V_23 )
continue;
V_233 = true ;
V_8 -> type = V_227 ;
V_8 -> V_154 = true ;
V_8 -> V_4 = V_145 ;
}
F_59 ( & V_2 -> V_3 ) ;
if ( V_233 )
F_65 ( & V_2 -> V_217 ) ;
F_54 ( & V_2 -> V_3 ) ;
F_55 (wk, &local->work_list, list) {
if ( V_8 -> V_23 != V_23 )
continue;
F_14 ( 1 ) ;
break;
}
F_59 ( & V_2 -> V_3 ) ;
}
T_6 F_89 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_58 * V_59 ;
struct V_7 * V_8 ;
T_3 V_201 ;
if ( V_25 -> V_163 < 24 )
return V_234 ;
V_59 = (struct V_58 * ) V_25 -> V_203 ;
V_201 = F_48 ( V_59 -> V_94 ) ;
F_90 (wk, &local->work_list, list) {
if ( V_23 != V_8 -> V_23 )
continue;
if ( F_56 ( V_8 -> V_87 , V_59 -> V_89 ) )
continue;
if ( F_56 ( V_8 -> V_87 , V_59 -> V_92 ) )
continue;
switch ( V_201 & V_204 ) {
case V_207 :
case V_206 :
case V_208 :
case V_209 :
case V_205 :
F_91 ( & V_2 -> V_224 , V_25 ) ;
F_64 ( & V_2 -> V_65 , & V_2 -> V_217 ) ;
return V_235 ;
}
}
return V_236 ;
}
static enum V_237 F_92 ( struct V_7 * V_8 ,
struct V_24 * V_25 )
{
F_93 ( V_8 -> V_23 -> V_157 , ( unsigned long ) V_8 ,
V_8 -> V_68 , V_8 -> V_158 ,
V_75 ) ;
return V_213 ;
}
int F_94 ( struct V_22 * V_23 ,
struct V_27 * V_68 ,
enum V_238 V_239 ,
unsigned int V_156 , T_7 * V_240 )
{
struct V_7 * V_8 ;
V_8 = F_95 ( sizeof( * V_8 ) , V_75 ) ;
if ( ! V_8 )
return - V_241 ;
V_8 -> type = V_228 ;
V_8 -> V_68 = V_68 ;
V_8 -> V_158 = V_239 ;
V_8 -> V_23 = V_23 ;
V_8 -> V_212 = F_92 ;
V_8 -> V_155 . V_156 = V_156 ;
* V_240 = ( unsigned long ) V_8 ;
F_81 ( V_8 ) ;
return 0 ;
}
int F_96 ( struct V_22 * V_23 ,
T_7 V_240 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_7 * V_8 , * V_220 ;
bool V_242 = false ;
F_54 ( & V_2 -> V_3 ) ;
F_70 (wk, tmp, &local->work_list, list) {
if ( ( unsigned long ) V_8 == V_240 ) {
V_8 -> V_4 = V_145 ;
V_242 = true ;
break;
}
}
F_59 ( & V_2 -> V_3 ) ;
if ( ! V_242 )
return - V_243 ;
F_64 ( & V_2 -> V_65 , & V_2 -> V_217 ) ;
return 0 ;
}
