static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
for ( V_2 = 0 ; V_2 <= 31 ; V_2 ++ ) {
if ( ( ( V_1 >> V_2 ) & 0x1 ) == 1 )
break;
}
return V_2 ;
}
T_1
F_2 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 )
{
T_1 V_6 = 0 , V_7 , V_8 ;
V_7 = F_3 ( V_4 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_6 = ( V_7 & V_1 ) >> V_8 ;
return V_6 ;
}
void
F_4 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 , T_1 V_9 )
{
T_1 V_7 , V_8 ;
if ( V_1 != V_10 ) {
V_7 = F_3 ( V_4 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_9 = ( ( V_7 & ( ~ V_1 ) ) | ( V_9 << V_8 ) ) ;
}
F_5 ( V_4 , V_5 , V_9 ) ;
}
static T_1
F_6 ( struct V_3 * V_4 , enum V_11 V_12 ,
T_1 V_13 )
{
T_1 V_14 = 0 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
struct V_17 * V_18 = & V_16 -> V_19 [ V_12 ] ;
T_1 V_20 ;
T_1 V_21 , V_22 ;
T_2 V_23 = 0 ;
V_13 &= 0x3f ;
V_20 = V_13 ;
V_21 = F_2 ( V_4 , V_24 , V_10 ) ;
if ( V_12 == V_25 )
V_22 = V_21 ;
else
V_22 = F_2 ( V_4 , V_18 -> V_26 ,
V_10 ) ;
V_22 = ( V_22 & ~ V_27 ) |
( V_20 << 23 ) | V_28 ;
F_4 ( V_4 , V_24 ,
V_10 , V_21 & ( ~ V_28 ) ) ;
F_8 ( 10 ) ;
F_4 ( V_4 , V_18 -> V_26 , V_10 , V_22 ) ;
F_8 ( 100 ) ;
F_4 ( V_4 , V_24 , V_10 ,
V_21 | V_28 ) ;
F_8 ( 10 ) ;
if ( V_12 == V_25 )
V_23 = ( T_2 ) F_2 ( V_4 ,
V_29 , V_30 ) ;
else if ( V_12 == V_31 )
V_23 = ( T_2 ) F_2 ( V_4 ,
V_32 , V_30 ) ;
if ( V_23 ) {
V_14 = F_2 ( V_4 , V_18 -> V_33 ,
V_34 ) ;
} else {
V_14 = F_2 ( V_4 , V_18 -> V_35 ,
V_34 ) ;
}
return V_14 ;
}
static void
F_9 ( struct V_3 * V_4 , enum V_11 V_12 ,
T_1 V_13 , T_1 V_9 )
{
T_1 V_36 = 0 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
struct V_17 * V_18 = & V_16 -> V_19 [ V_12 ] ;
T_1 V_20 ;
V_13 &= 0x3f ;
V_20 = V_13 ;
V_36 = ( ( V_20 << 20 ) | ( V_9 & 0x000fffff ) ) & 0x0fffffff ;
F_4 ( V_4 , V_18 -> V_37 , V_10 , V_36 ) ;
}
T_1
F_10 ( struct V_3 * V_4 , enum V_11 V_12 ,
T_1 V_5 , T_1 V_1 )
{
T_1 V_38 , V_39 , V_8 ;
V_38 = F_6 ( V_4 , V_12 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_39 = ( V_38 & V_1 ) >> V_8 ;
return V_39 ;
}
void
F_11 ( struct V_3 * V_4 , enum V_11 V_12 ,
T_1 V_5 , T_1 V_1 , T_1 V_9 )
{
T_1 V_38 , V_8 ;
if ( V_1 != V_40 ) {
V_38 = F_6 ( V_4 , V_12 , V_5 ) ;
V_8 = F_1 ( V_1 ) ;
V_9 = ( ( V_38 & ( ~ V_1 ) ) | ( V_9 << V_8 ) ) ;
}
F_9 ( V_4 , V_12 , V_5 , V_9 ) ;
}
T_3 F_12 ( struct V_3 * V_4 )
{
int V_41 = V_42 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_4 * V_43 ;
T_4 V_44 [] = V_45 ;
bool V_46 = F_13 ( V_16 -> V_47 ) ;
V_43 = V_44 ;
if ( V_48 ==
F_14 ( & V_16 -> V_49 ) )
V_41 = V_50 ;
F_15 ( V_4 , V_51 , 0x0A ) ;
if ( V_46 && ( V_52 == V_16 -> V_53 ) )
F_15 ( V_4 , 0x40 , 0x04 ) ;
return V_41 ;
}
static void
F_16 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
V_16 -> V_19 [ V_25 ] . V_54 = V_55 ;
V_16 -> V_19 [ V_31 ] . V_54 = V_55 ;
V_16 -> V_19 [ V_25 ] . V_56 = V_57 ;
V_16 -> V_19 [ V_31 ] . V_56 = V_57 ;
V_16 -> V_19 [ V_25 ] . V_58 = V_59 ;
V_16 -> V_19 [ V_31 ] . V_58 = V_60 ;
V_16 -> V_19 [ V_25 ] . V_61 = V_59 ;
V_16 -> V_19 [ V_31 ] . V_61 = V_60 ;
V_16 -> V_19 [ V_25 ] . V_37 = V_62 ;
V_16 -> V_19 [ V_31 ] . V_37 = V_63 ;
V_16 -> V_19 [ V_25 ] . V_64 = V_65 ;
V_16 -> V_19 [ V_31 ] . V_64 = V_65 ;
V_16 -> V_19 [ V_25 ] . V_66 = V_67 ;
V_16 -> V_19 [ V_31 ] . V_66 = V_67 ;
V_16 -> V_19 [ V_25 ] . V_68 = V_29 ;
V_16 -> V_19 [ V_31 ] . V_68 = V_32 ;
V_16 -> V_19 [ V_25 ] . V_26 = V_24 ;
V_16 -> V_19 [ V_31 ] . V_26 = V_69 ;
V_16 -> V_19 [ V_25 ] . V_70 =
V_71 ;
V_16 -> V_19 [ V_31 ] . V_70 =
V_71 ;
V_16 -> V_19 [ V_25 ] . V_72 = V_73 ;
V_16 -> V_19 [ V_31 ] . V_72 = V_74 ;
V_16 -> V_19 [ V_25 ] . V_75 = V_76 ;
V_16 -> V_19 [ V_31 ] . V_75 = V_77 ;
V_16 -> V_19 [ V_25 ] . V_78 = V_79 ;
V_16 -> V_19 [ V_31 ] . V_78 = V_80 ;
V_16 -> V_19 [ V_25 ] . V_81 = V_82 ;
V_16 -> V_19 [ V_31 ] . V_81 = V_83 ;
V_16 -> V_19 [ V_25 ] . V_84 = V_85 ;
V_16 -> V_19 [ V_31 ] . V_84 = V_86 ;
V_16 -> V_19 [ V_25 ] . V_87 = V_88 ;
V_16 -> V_19 [ V_31 ] . V_87 = V_89 ;
V_16 -> V_19 [ V_25 ] . V_35 = V_90 ;
V_16 -> V_19 [ V_31 ] . V_35 = V_91 ;
V_16 -> V_19 [ V_25 ] . V_33 =
V_92 ;
V_16 -> V_19 [ V_31 ] . V_33 =
V_93 ;
}
static void
F_17 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_1 , T_1 V_9 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
if ( V_5 == V_94 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 0 ] = V_9 ;
}
if ( V_5 == V_97 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 1 ] = V_9 ;
}
if ( V_5 == V_98 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 6 ] = V_9 ;
}
if ( V_5 == V_99 && V_1 == 0xffffff00 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 7 ] = V_9 ;
}
if ( V_5 == V_100 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 2 ] = V_9 ;
}
if ( V_5 == V_101 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 3 ] = V_9 ;
}
if ( V_5 == V_102 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 4 ] = V_9 ;
}
if ( V_5 == V_103 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 5 ] = V_9 ;
}
if ( V_5 == V_104 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 8 ] = V_9 ;
}
if ( V_5 == V_105 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 9 ] = V_9 ;
}
if ( V_5 == V_106 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 14 ] = V_9 ;
}
if ( V_5 == V_99 && V_1 == 0x000000ff ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 15 ] = V_9 ;
}
if ( V_5 == V_107 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 10 ] = V_9 ;
}
if ( V_5 == V_108 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 11 ] = V_9 ;
}
if ( V_5 == V_109 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 12 ] = V_9 ;
}
if ( V_5 == V_110 ) {
V_16 -> V_95 [ V_16 -> V_96 ] [ 13 ] = V_9 ;
V_16 -> V_96 ++ ;
}
}
static int
F_18 ( struct V_3 * V_4 , T_2 V_111 )
{
int V_2 ;
T_1 * V_112 ;
T_5 V_113 ;
V_113 = V_114 ;
V_112 = ( T_1 * ) V_115 ;
if ( V_111 == V_116 ) {
for ( V_2 = 0 ; V_2 < V_113 ; V_2 = V_2 + 3 ) {
F_17 ( V_4 ,
V_112 [ V_2 ] ,
V_112 [ V_2 + 1 ] ,
V_112 [ V_2 + 2 ] ) ;
}
}
return V_42 ;
}
static void
F_19 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_117 , 0x3 , 0x2 ) ;
F_4 ( V_4 , V_118 , 0x300033 , 0x200022 ) ;
F_4 ( V_4 , V_119 , V_120 , 0x45 ) ;
F_4 ( V_4 , V_121 , V_122 , 0x23 ) ;
F_4 ( V_4 , V_123 , 0x30 , 0x1 ) ;
F_4 ( V_4 , 0xe74 , 0x0c000000 , 0x2 ) ;
F_4 ( V_4 , 0xe78 , 0x0c000000 , 0x2 ) ;
F_4 ( V_4 , 0xe7c , 0x0c000000 , 0x2 ) ;
F_4 ( V_4 , 0xe80 , 0x0c000000 , 0x2 ) ;
F_4 ( V_4 , 0xe88 , 0x0c000000 , 0x2 ) ;
}
static int
F_20 ( struct V_3 * V_4 )
{
struct V_124 * V_125 = F_21 ( V_4 ) ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
int V_41 = V_42 ;
T_2 V_126 [] = V_127 ;
T_2 V_128 [] = V_129 ;
T_2 V_130 [] = V_131 ;
T_2 V_132 [] = V_133 ;
T_2 * V_134 = NULL , * V_135 = NULL ;
T_2 * V_136 = NULL , * V_137 = NULL ;
V_134 = V_126 ;
V_135 = V_128 ;
V_136 = V_130 ;
V_137 = V_132 ;
if ( V_48 == F_22 ( & V_16 -> V_49 ,
V_138 ) )
V_41 = V_50 ;
if ( V_41 != V_42 )
goto V_139;
if ( V_16 -> V_140 == V_141 ) {
F_19 ( V_4 ) ;
F_23 ( L_1 ) ;
}
if ( V_125 -> V_142 == false ) {
V_16 -> V_96 = 0 ;
V_41 = F_18 ( V_4 ,
V_116 ) ;
}
if ( V_41 != V_42 )
goto V_139;
if ( V_48 == F_22 ( & V_16 -> V_49 ,
V_143 ) )
V_41 = V_50 ;
V_139:
return V_41 ;
}
int
F_24 ( struct V_3 * V_4 )
{
int V_41 = V_42 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_144 = 0 ;
T_2 V_145 ;
F_16 ( V_4 ) ;
V_144 = F_25 ( V_4 , V_146 ) ;
F_8 ( 2 ) ;
F_15 ( V_4 , V_146 , ( V_144 | V_147 ) ) ;
F_8 ( 2 ) ;
F_15 ( V_4 , V_146 + 1 , 0xff ) ;
F_8 ( 2 ) ;
V_144 = F_25 ( V_4 , V_148 ) ;
F_15 ( V_4 , V_148 ,
( V_144 | V_149 | V_150 ) ) ;
V_144 = F_25 ( V_4 , V_151 + 1 ) ;
F_15 ( V_4 , V_151 + 1 , ( V_144 & ( ~ V_152 ) ) ) ;
V_144 = F_25 ( V_4 , V_151 + 2 ) ;
F_15 ( V_4 , V_151 + 2 , ( V_144 & ( ~ V_153 ) ) ) ;
F_15 ( V_4 , V_154 , 0x07 ) ;
V_41 = F_20 ( V_4 ) ;
if ( V_16 -> V_155 >= 0x01 ) {
V_145 = V_16 -> V_145 & 0x3F ;
F_4 ( V_4 , V_156 , 0xFFF000 ,
( V_145 | ( V_145 << 6 ) ) ) ;
}
F_4 ( V_4 , V_157 , V_10 , 0x01572505 ) ;
return V_41 ;
}
int
F_26 ( struct V_3 * V_4 )
{
int V_41 = V_42 ;
V_41 = F_27 ( V_4 ) ;
return V_41 ;
}
static void F_28 ( struct V_3 * V_4 ,
T_2 V_158 , T_2 * V_159 , T_2 * V_160 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_161 = ( V_158 - 1 ) ;
V_159 [ V_25 ] = V_16 -> V_162 [ V_25 ] [ V_161 ] ;
V_159 [ V_31 ] = V_16 -> V_162 [ V_31 ] [ V_161 ] ;
if ( F_29 ( V_4 ) == V_141 || F_29 ( V_4 ) == V_163 ) {
V_160 [ V_25 ] =
V_16 -> V_164 [ V_25 ] [ V_161 ] ;
V_160 [ V_31 ] =
V_16 -> V_164 [ V_31 ] [ V_161 ] ;
} else if ( F_29 ( V_4 ) == V_165 ) {
V_160 [ V_25 ] =
V_16 -> V_166 [ V_25 ] [ V_161 ] ;
V_160 [ V_31 ] =
V_16 -> V_166 [ V_31 ] [ V_161 ] ;
}
}
static void F_30 ( struct V_3 * V_4 , T_2 V_158 ,
T_2 * V_159 , T_2 * V_160 )
{
}
void F_31 ( struct V_3 * V_4 , T_2 V_158 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_159 [ 2 ] , V_160 [ 2 ] ;
if ( V_16 -> V_167 == false )
return;
F_28 ( V_4 , V_158 , & V_159 [ 0 ] ,
& V_160 [ 0 ] ) ;
F_30 ( V_4 , V_158 , & V_159 [ 0 ] ,
& V_160 [ 0 ] ) ;
F_32 ( V_4 , & V_159 [ 0 ] ) ;
F_33 ( V_4 , & V_160 [ 0 ] , V_158 ) ;
}
static void
F_34 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_168 ;
T_2 V_169 ;
if ( V_16 -> V_170 == V_171 )
return;
if ( V_16 -> V_170 == V_172 )
return;
if ( V_4 -> V_173 )
return;
V_168 = F_25 ( V_4 , V_174 ) ;
V_169 = F_25 ( V_4 , V_175 + 2 ) ;
switch ( V_16 -> V_176 ) {
case V_177 :
V_168 |= V_178 ;
F_15 ( V_4 , V_174 , V_168 ) ;
break;
case V_179 :
V_168 &= ~ V_178 ;
F_15 ( V_4 , V_174 , V_168 ) ;
V_169 = ( V_169 & 0x90 ) |
( V_16 -> V_180 << 5 ) ;
F_15 ( V_4 , V_175 + 2 , V_169 ) ;
break;
default:
break;
}
switch ( V_16 -> V_176 ) {
case V_177 :
F_4 ( V_4 , V_181 , V_182 , 0x0 ) ;
F_4 ( V_4 , V_183 , V_182 , 0x0 ) ;
F_4 ( V_4 , V_184 , V_185 , 1 ) ;
break;
case V_179 :
F_4 ( V_4 , V_181 , V_182 , 0x1 ) ;
F_4 ( V_4 , V_183 , V_182 , 0x1 ) ;
F_4 ( V_4 , V_186 , V_187 ,
( V_16 -> V_180 >> 1 ) ) ;
F_4 ( V_4 , V_188 , 0xC00 ,
V_16 -> V_180 ) ;
F_4 ( V_4 , V_184 , V_185 , 0 ) ;
F_4 ( V_4 , 0x818 , ( V_189 | V_190 ) ,
( V_16 -> V_180 ==
V_191 ) ? 2 : 1 ) ;
break;
default:
break;
}
switch ( V_16 -> V_170 ) {
case V_172 :
break;
case V_192 :
break;
case V_193 :
break;
case V_171 :
break;
case V_194 :
F_35 ( V_4 , V_16 -> V_176 ) ;
break;
default:
break;
}
}
void
F_36 ( struct V_3 * V_4 ,
enum V_195 V_196 , unsigned char V_13 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
enum V_195 V_197 = V_16 -> V_176 ;
V_16 -> V_176 = V_196 ;
V_16 -> V_180 = V_13 ;
if ( ( ! V_4 -> V_173 ) && ( ! V_4 -> V_198 ) )
F_34 ( V_4 ) ;
else
V_16 -> V_176 = V_197 ;
}
static void F_37 ( struct V_3 * V_4 , T_2 V_158 )
{
T_2 V_12 ;
T_1 V_199 , V_200 ;
struct V_15 * V_16 = F_7 ( V_4 ) ;
if ( V_4 -> V_201 )
F_23 ( L_2 , V_202 , V_158 ) ;
F_31 ( V_4 , V_158 ) ;
V_199 = V_203 ;
V_200 = V_158 ;
for ( V_12 = 0 ; V_12 < V_16 -> V_204 ; V_12 ++ ) {
V_16 -> V_205 [ V_12 ] =
( V_16 -> V_205 [ V_12 ] & 0xfffffc00 ) | V_200 ;
F_11 ( V_4 , (enum V_11 ) V_12 , V_199 ,
V_40 , V_16 -> V_205 [ V_12 ] ) ;
}
}
void F_38 ( struct V_3 * V_4 , T_2 V_158 )
{
struct V_15 * V_16 = F_7 ( V_4 ) ;
T_2 V_206 = V_16 -> V_207 ;
bool V_208 = true ;
if ( V_16 -> V_170 == V_171 ) {
return;
}
if ( V_158 == 0 )
V_158 = 1 ;
V_16 -> V_207 = V_158 ;
if ( ( ! V_4 -> V_173 ) && ( ! V_4 -> V_198 ) ) {
F_37 ( V_4 , V_158 ) ;
if ( ! V_208 )
V_16 -> V_207 = V_206 ;
} else {
V_16 -> V_207 = V_206 ;
}
}
