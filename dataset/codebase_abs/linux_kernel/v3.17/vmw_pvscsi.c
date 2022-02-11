static struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_4 ) ;
}
static struct V_5 *
F_2 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 , * V_9 ;
V_9 = & V_3 -> V_10 [ V_3 -> V_11 ] ;
for ( V_8 = V_3 -> V_10 ; V_8 < V_9 ; V_8 ++ )
if ( V_8 -> V_7 == V_7 )
return V_8 ;
return NULL ;
}
static struct V_5 *
F_3 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 ;
if ( F_4 ( & V_3 -> V_12 ) )
return NULL ;
V_8 = F_5 ( & V_3 -> V_12 , struct V_5 , V_13 ) ;
V_8 -> V_7 = V_7 ;
F_6 ( & V_8 -> V_13 ) ;
return V_8 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_5 * V_8 )
{
V_8 -> V_7 = NULL ;
V_8 -> V_14 = NULL ;
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
static T_1 F_9 ( const struct V_2 * V_3 ,
const struct V_5 * V_8 )
{
return V_8 - V_3 -> V_10 + 1 ;
}
static struct V_5 *
F_10 ( const struct V_2 * V_3 , T_1 V_15 )
{
return & V_3 -> V_10 [ V_15 - 1 ] ;
}
static void F_11 ( const struct V_2 * V_3 ,
T_2 V_16 , T_2 V_17 )
{
F_12 ( V_17 , V_3 -> V_18 + V_16 ) ;
}
static T_2 F_13 ( const struct V_2 * V_3 , T_2 V_16 )
{
return F_14 ( V_3 -> V_18 + V_16 ) ;
}
static T_2 F_15 ( const struct V_2 * V_3 )
{
return F_13 ( V_3 , V_19 ) ;
}
static void F_16 ( const struct V_2 * V_3 ,
T_2 V_17 )
{
F_11 ( V_3 , V_19 , V_17 ) ;
}
static void F_17 ( const struct V_2 * V_3 )
{
T_2 V_20 ;
V_20 = V_21 ;
if ( V_3 -> V_22 )
V_20 |= V_23 ;
F_11 ( V_3 , V_24 , V_20 ) ;
}
static void F_18 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_24 , 0 ) ;
}
static void F_19 ( const struct V_2 * V_3 ,
T_2 V_7 , const void * V_25 , T_3 V_26 )
{
const T_2 * V_27 = V_25 ;
T_3 V_28 ;
V_26 /= sizeof( * V_27 ) ;
F_11 ( V_3 , V_29 , V_7 ) ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ )
F_11 ( V_3 ,
V_30 , V_27 [ V_28 ] ) ;
}
static void F_20 ( const struct V_2 * V_3 ,
const struct V_5 * V_8 )
{
struct V_31 V_7 = { 0 } ;
V_7 . V_32 = V_8 -> V_7 -> V_1 -> V_33 ;
V_7 . V_15 = F_9 ( V_3 , V_8 ) ;
F_19 ( V_3 , V_34 , & V_7 , sizeof( V_7 ) ) ;
}
static void F_21 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_35 , 0 ) ;
}
static void F_22 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_36 , 0 ) ;
}
static int F_23 ( unsigned char V_37 )
{
return V_37 == V_38 || V_37 == V_39 ||
V_37 == V_40 || V_37 == V_41 ||
V_37 == V_42 || V_37 == V_43 ||
V_37 == V_44 || V_37 == V_45 ;
}
static void F_24 ( const struct V_2 * V_3 ,
unsigned char V_37 )
{
if ( F_23 ( V_37 ) ) {
struct V_46 * V_47 = V_3 -> V_48 ;
if ( ! V_3 -> V_49 ||
V_47 -> V_50 - V_47 -> V_51 >= V_47 -> V_52 )
F_21 ( V_3 ) ;
} else {
F_22 ( V_3 ) ;
}
}
static void F_25 ( const struct V_2 * V_3 )
{
F_26 ( F_1 ( V_3 ) , L_1 , V_3 ) ;
F_19 ( V_3 , V_53 , NULL , 0 ) ;
}
static void F_27 ( const struct V_2 * V_3 )
{
F_26 ( F_1 ( V_3 ) , L_2 , V_3 ) ;
F_19 ( V_3 , V_54 , NULL , 0 ) ;
}
static void F_28 ( const struct V_2 * V_3 , T_2 V_32 )
{
struct V_55 V_7 = { 0 } ;
F_26 ( F_1 ( V_3 ) , L_3 , V_32 ) ;
V_7 . V_32 = V_32 ;
F_19 ( V_3 , V_56 ,
& V_7 , sizeof( V_7 ) ) ;
}
static void F_29 ( struct V_5 * V_8 ,
struct V_57 * V_58 , unsigned V_59 )
{
unsigned V_28 ;
struct V_60 * V_61 ;
F_30 ( V_59 > V_62 ) ;
V_61 = & V_8 -> V_63 -> V_61 [ 0 ] ;
for ( V_28 = 0 ; V_28 < V_59 ; V_28 ++ , V_58 ++ ) {
V_61 [ V_28 ] . V_64 = F_31 ( V_58 ) ;
V_61 [ V_28 ] . V_65 = F_32 ( V_58 ) ;
V_61 [ V_28 ] . V_66 = 0 ;
}
}
static void F_33 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 ,
struct V_67 * V_68 )
{
unsigned V_59 ;
unsigned V_69 = F_34 ( V_7 ) ;
struct V_57 * V_58 ;
V_68 -> V_70 = V_69 ;
V_68 -> V_71 = 0 ;
if ( V_69 == 0 )
return;
V_58 = F_35 ( V_7 ) ;
V_59 = F_36 ( V_7 ) ;
if ( V_59 != 0 ) {
int V_72 = F_37 ( V_7 ) ;
if ( V_72 > 1 ) {
F_29 ( V_8 , V_58 , V_72 ) ;
V_68 -> V_66 |= V_73 ;
V_8 -> V_74 = F_38 ( V_3 -> V_4 , V_8 -> V_63 ,
V_75 , V_76 ) ;
V_68 -> V_71 = V_8 -> V_74 ;
} else
V_68 -> V_71 = F_31 ( V_58 ) ;
} else {
V_8 -> V_77 = F_38 ( V_3 -> V_4 , V_58 , V_69 ,
V_7 -> V_78 ) ;
V_68 -> V_71 = V_8 -> V_77 ;
}
}
static void F_39 ( const struct V_2 * V_3 ,
struct V_5 * V_8 )
{
struct V_6 * V_7 ;
unsigned V_69 ;
V_7 = V_8 -> V_7 ;
V_69 = F_34 ( V_7 ) ;
if ( V_69 != 0 ) {
unsigned V_59 = F_36 ( V_7 ) ;
if ( V_59 != 0 ) {
F_40 ( V_7 ) ;
if ( V_8 -> V_74 ) {
F_41 ( V_3 -> V_4 , V_8 -> V_74 ,
V_75 , V_76 ) ;
V_8 -> V_74 = 0 ;
}
} else
F_41 ( V_3 -> V_4 , V_8 -> V_77 , V_69 ,
V_7 -> V_78 ) ;
}
if ( V_7 -> V_79 )
F_41 ( V_3 -> V_4 , V_8 -> V_80 ,
V_81 , V_82 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
V_3 -> V_48 = F_43 ( V_3 -> V_4 , V_83 ,
& V_3 -> V_84 ) ;
if ( ! V_3 -> V_48 )
return - V_85 ;
V_3 -> V_86 = F_44 ( V_87 ,
V_88 ) ;
V_3 -> V_11 = V_3 -> V_86
* V_89 ;
V_3 -> V_90 = F_43 ( V_3 -> V_4 ,
V_3 -> V_86 * V_83 ,
& V_3 -> V_91 ) ;
if ( ! V_3 -> V_90 )
return - V_85 ;
V_3 -> V_92 = F_44 ( V_93 ,
V_88 ) ;
V_3 -> V_94 = F_43 ( V_3 -> V_4 ,
V_3 -> V_92 * V_83 ,
& V_3 -> V_95 ) ;
if ( ! V_3 -> V_94 )
return - V_85 ;
F_30 ( ! F_45 ( V_3 -> V_84 , V_83 ) ) ;
F_30 ( ! F_45 ( V_3 -> V_91 , V_83 ) ) ;
F_30 ( ! F_45 ( V_3 -> V_95 , V_83 ) ) ;
if ( ! V_3 -> V_22 )
return 0 ;
V_3 -> V_96 = F_44 ( V_97 ,
V_98 ) ;
V_3 -> V_99 = F_43 ( V_3 -> V_4 ,
V_3 -> V_96 * V_83 ,
& V_3 -> V_100 ) ;
if ( ! V_3 -> V_99 )
return - V_85 ;
F_30 ( ! F_45 ( V_3 -> V_100 , V_83 ) ) ;
return 0 ;
}
static void F_46 ( const struct V_2 * V_3 )
{
struct V_101 V_7 = { 0 } ;
T_4 V_102 ;
unsigned V_28 ;
V_7 . V_103 = V_3 -> V_84 >> V_104 ;
V_7 . V_105 = V_3 -> V_86 ;
V_7 . V_106 = V_3 -> V_92 ;
V_102 = V_3 -> V_91 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_86 ; V_28 ++ ) {
V_7 . V_107 [ V_28 ] = V_102 >> V_104 ;
V_102 += V_83 ;
}
V_102 = V_3 -> V_95 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_92 ; V_28 ++ ) {
V_7 . V_108 [ V_28 ] = V_102 >> V_104 ;
V_102 += V_83 ;
}
memset ( V_3 -> V_48 , 0 , V_83 ) ;
memset ( V_3 -> V_90 , 0 , V_3 -> V_86 * V_83 ) ;
memset ( V_3 -> V_94 , 0 , V_3 -> V_92 * V_83 ) ;
F_19 ( V_3 , V_109 ,
& V_7 , sizeof( V_7 ) ) ;
if ( V_3 -> V_22 ) {
struct V_110 V_111 = { 0 } ;
V_111 . V_112 = V_3 -> V_96 ;
V_102 = V_3 -> V_100 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_96 ; V_28 ++ ) {
V_111 . V_113 [ V_28 ] = V_102 >> V_104 ;
V_102 += V_83 ;
}
memset ( V_3 -> V_99 , 0 , V_3 -> V_96 * V_83 ) ;
F_19 ( V_3 , V_114 ,
& V_111 , sizeof( V_111 ) ) ;
}
}
static int F_47 ( struct V_115 * V_116 ,
int V_117 ,
int V_118 )
{
int V_119 ;
struct V_120 * V_121 = V_116 -> V_122 ;
if ( V_118 != V_123 )
return - V_124 ;
V_119 = V_121 -> V_125 ;
if ( ! V_116 -> V_126 )
V_119 = 1 ;
if ( V_117 > V_119 )
V_117 = V_119 ;
F_48 ( V_116 , F_49 ( V_116 ) , V_117 ) ;
if ( V_116 -> V_127 > 7 )
F_50 ( V_128 , V_116 ,
L_4 ,
V_116 -> V_129 , V_116 -> V_126 ,
V_116 -> V_130 , V_116 -> V_131 ,
V_116 -> V_132 , ( V_116 -> V_133 [ 7 ] & 2 ) >> 1 ) ;
return V_116 -> V_129 ;
}
static void F_51 ( struct V_2 * V_3 ,
const struct V_134 * V_68 )
{
struct V_5 * V_8 ;
struct V_6 * V_7 ;
struct V_135 * V_14 ;
T_2 V_136 = V_68 -> V_137 ;
T_2 V_138 = V_68 -> V_139 ;
V_8 = F_10 ( V_3 , V_68 -> V_15 ) ;
V_7 = V_8 -> V_7 ;
V_14 = V_8 -> V_14 ;
F_39 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
if ( V_14 ) {
F_52 ( V_14 ) ;
return;
}
V_7 -> V_140 = 0 ;
if ( V_138 != V_141 &&
( V_136 == V_142 ||
V_136 == V_143 ||
V_136 == V_144 ) ) {
V_7 -> V_140 = ( V_145 << 16 ) | V_138 ;
if ( V_138 == V_146 && V_7 -> V_79 )
V_7 -> V_140 |= ( V_147 << 24 ) ;
} else
switch ( V_136 ) {
case V_142 :
case V_143 :
case V_144 :
V_7 -> V_140 = ( V_145 << 16 ) ;
break;
case V_148 :
case V_149 :
F_53 ( V_7 , F_34 ( V_7 ) - V_68 -> V_70 ) ;
V_7 -> V_140 = ( V_150 << 16 ) ;
break;
case V_151 :
V_7 -> V_140 = ( V_152 << 16 ) ;
break;
case V_153 :
case V_154 :
case V_155 :
V_7 -> V_140 = ( V_156 << 24 ) ;
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
V_7 -> V_140 |= ( V_150 << 16 ) ;
break;
case V_165 :
case V_166 :
case V_167 :
V_7 -> V_140 = ( V_168 << 16 ) ;
break;
case V_169 :
V_7 -> V_140 = ( V_170 << 16 ) ;
break;
case V_171 :
V_7 -> V_140 = ( V_172 << 16 ) ;
break;
default:
V_7 -> V_140 = ( V_150 << 16 ) ;
F_54 ( V_173 , V_7 ,
L_5 ,
V_136 ) ;
}
F_26 ( & V_7 -> V_1 -> V_174 ,
L_6 ,
V_7 , V_7 -> V_175 [ 0 ] , V_8 , V_7 -> V_140 , V_136 , V_138 ) ;
V_7 -> V_176 ( V_7 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_134 * V_177 = V_3 -> V_94 ;
T_2 V_178 = V_47 -> V_179 ;
while ( V_47 -> V_180 != V_47 -> V_181 ) {
struct V_134 * V_68 = V_177 + ( V_47 -> V_180 &
F_56 ( V_178 ) ) ;
F_57 () ;
F_51 ( V_3 , V_68 ) ;
F_57 () ;
V_47 -> V_180 ++ ;
}
}
static int F_58 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 )
{
struct V_46 * V_47 ;
struct V_67 * V_68 ;
struct V_115 * V_116 ;
T_2 V_182 ;
V_47 = V_3 -> V_48 ;
V_116 = V_7 -> V_1 ;
V_182 = V_47 -> V_183 ;
if ( V_47 -> V_50 - V_47 -> V_180 >= 1 << V_182 ) {
F_54 ( V_184 , V_7 , L_7
L_8 ,
V_47 -> V_50 , V_47 -> V_180 ) ;
return - 1 ;
}
V_68 = V_3 -> V_90 + ( V_47 -> V_50 & F_56 ( V_182 ) ) ;
V_68 -> V_185 = V_116 -> V_186 ;
V_68 -> V_32 = V_116 -> V_33 ;
memset ( V_68 -> V_187 , 0 , sizeof( V_68 -> V_187 ) ) ;
V_68 -> V_187 [ 1 ] = V_116 -> V_187 ;
if ( V_7 -> V_79 ) {
V_8 -> V_80 = F_38 ( V_3 -> V_4 , V_7 -> V_79 ,
V_81 ,
V_82 ) ;
V_68 -> V_188 = V_8 -> V_80 ;
V_68 -> V_189 = V_81 ;
} else {
V_68 -> V_189 = 0 ;
V_68 -> V_188 = 0 ;
}
V_68 -> V_190 = V_7 -> V_191 ;
V_68 -> V_192 = F_59 () ;
memcpy ( V_68 -> V_193 , V_7 -> V_175 , V_68 -> V_190 ) ;
V_68 -> V_194 = V_195 ;
if ( V_116 -> V_126 &&
( V_7 -> V_194 == V_196 ||
V_7 -> V_194 == V_197 ) )
V_68 -> V_194 = V_7 -> V_194 ;
if ( V_7 -> V_78 == V_198 )
V_68 -> V_66 = V_199 ;
else if ( V_7 -> V_78 == V_200 )
V_68 -> V_66 = V_201 ;
else if ( V_7 -> V_78 == V_202 )
V_68 -> V_66 = V_203 ;
else
V_68 -> V_66 = 0 ;
F_33 ( V_3 , V_8 , V_7 , V_68 ) ;
V_68 -> V_15 = F_9 ( V_3 , V_8 ) ;
F_57 () ;
V_47 -> V_50 ++ ;
return 0 ;
}
static int F_60 ( struct V_6 * V_7 , void (* F_61)( struct V_6 * ) )
{
struct V_120 * V_122 = V_7 -> V_1 -> V_122 ;
struct V_2 * V_3 = F_62 ( V_122 ) ;
struct V_5 * V_8 ;
unsigned long V_66 ;
F_63 ( & V_3 -> V_204 , V_66 ) ;
V_8 = F_3 ( V_3 , V_7 ) ;
if ( ! V_8 || F_58 ( V_3 , V_8 , V_7 ) != 0 ) {
if ( V_8 )
F_7 ( V_3 , V_8 ) ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
return V_205 ;
}
V_7 -> V_176 = F_61 ;
F_26 ( & V_7 -> V_1 -> V_174 ,
L_9 , V_7 , V_8 , V_7 -> V_175 [ 0 ] ) ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
F_24 ( V_3 , V_7 -> V_175 [ 0 ] ) ;
return 0 ;
}
void F_65 ( struct V_2 * V_3 )
{
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; V_28 ++ ) {
struct V_5 * V_8 = & V_3 -> V_10 [ V_28 ] ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( V_7 ) {
F_54 ( V_184 , V_7 ,
L_10 , V_7 ) ;
F_39 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
V_7 -> V_140 = ( V_168 << 16 ) ;
V_7 -> V_176 ( V_7 ) ;
}
}
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_120 * V_122 = V_7 -> V_1 -> V_122 ;
struct V_2 * V_3 = F_62 ( V_122 ) ;
unsigned long V_66 ;
bool V_22 ;
F_54 ( V_128 , V_7 , L_11 ) ;
F_63 ( & V_3 -> V_204 , V_66 ) ;
V_22 = V_3 -> V_22 ;
if ( V_22 ) {
V_3 -> V_22 = 0 ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
F_67 ( V_3 -> V_206 ) ;
F_63 ( & V_3 -> V_204 , V_66 ) ;
}
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
F_55 ( V_3 ) ;
F_65 ( V_3 ) ;
V_3 -> V_22 = V_22 ;
F_46 ( V_3 ) ;
F_17 ( V_3 ) ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
return V_207 ;
}
static int F_68 ( struct V_6 * V_7 )
{
struct V_120 * V_122 = V_7 -> V_1 -> V_122 ;
struct V_2 * V_3 = F_62 ( V_122 ) ;
unsigned long V_66 ;
F_54 ( V_128 , V_7 , L_12 ) ;
F_63 ( & V_3 -> V_204 , V_66 ) ;
F_22 ( V_3 ) ;
F_27 ( V_3 ) ;
F_55 ( V_3 ) ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
return V_207 ;
}
static int F_69 ( struct V_6 * V_7 )
{
struct V_120 * V_122 = V_7 -> V_1 -> V_122 ;
struct V_2 * V_3 = F_62 ( V_122 ) ;
unsigned long V_66 ;
F_54 ( V_128 , V_7 , L_13 ,
V_122 -> V_208 , V_7 -> V_1 -> V_33 ) ;
F_63 ( & V_3 -> V_204 , V_66 ) ;
F_22 ( V_3 ) ;
F_28 ( V_3 , V_7 -> V_1 -> V_33 ) ;
F_55 ( V_3 ) ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
return V_207 ;
}
static const char * F_70 ( struct V_120 * V_122 )
{
struct V_2 * V_3 = F_62 ( V_122 ) ;
static char V_209 [ 256 ] ;
sprintf ( V_209 , L_14
L_15 , V_3 -> V_210 ,
V_3 -> V_86 , V_3 -> V_92 , V_3 -> V_96 ,
V_211 . V_212 ) ;
return V_209 ;
}
static void F_71 ( const struct V_2 * V_3 ,
const struct V_213 * V_68 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_120 * V_122 = V_3 -> V_122 ;
struct V_115 * V_116 ;
F_72 ( V_128 L_16 ,
V_68 -> type , V_47 -> V_214 , V_47 -> V_215 , V_47 -> V_216 ) ;
F_73 ( V_217 != 2 ) ;
if ( V_68 -> type == V_218 ) {
struct V_219 * V_25 ;
V_25 = (struct V_219 * ) V_68 ;
F_72 ( V_128
L_17 ,
V_25 -> V_185 , V_25 -> V_32 , V_25 -> V_187 [ 1 ] ) ;
if ( ! F_74 ( V_122 ) )
return;
V_116 = F_75 ( V_122 , V_25 -> V_185 , V_25 -> V_32 ,
V_25 -> V_187 [ 1 ] ) ;
if ( V_116 ) {
F_72 ( V_128 L_18 ) ;
F_76 ( V_116 ) ;
} else
F_77 ( V_3 -> V_122 , V_25 -> V_185 ,
V_25 -> V_32 , V_25 -> V_187 [ 1 ] ) ;
F_78 ( V_122 ) ;
} else if ( V_68 -> type == V_220 ) {
struct V_219 * V_25 ;
V_25 = (struct V_219 * ) V_68 ;
F_72 ( V_128
L_19 ,
V_25 -> V_185 , V_25 -> V_32 , V_25 -> V_187 [ 1 ] ) ;
if ( ! F_74 ( V_122 ) )
return;
V_116 = F_75 ( V_122 , V_25 -> V_185 , V_25 -> V_32 ,
V_25 -> V_187 [ 1 ] ) ;
if ( V_116 ) {
F_79 ( V_116 ) ;
F_76 ( V_116 ) ;
} else
F_72 ( V_128
L_20 ,
V_25 -> V_185 , V_25 -> V_32 , V_25 -> V_187 [ 1 ] ) ;
F_78 ( V_122 ) ;
}
}
static int F_80 ( const struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
return V_47 -> V_214 != V_47 -> V_215 ;
}
static void F_81 ( const struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_213 * V_177 = V_3 -> V_99 ;
T_2 V_221 = V_47 -> V_216 ;
while ( F_80 ( V_3 ) ) {
struct V_213 * V_68 = V_177 + ( V_47 -> V_215 &
F_56 ( V_221 ) ) ;
F_57 () ;
F_71 ( V_3 , V_68 ) ;
F_57 () ;
V_47 -> V_215 ++ ;
}
}
static void F_82 ( struct V_222 * V_223 )
{
struct V_2 * V_3 ;
V_3 = F_83 ( V_223 , struct V_2 , V_224 ) ;
F_81 ( V_3 ) ;
}
static int F_84 ( struct V_2 * V_3 )
{
char V_225 [ 32 ] ;
if ( ! V_226 )
return 0 ;
F_11 ( V_3 , V_29 ,
V_114 ) ;
if ( F_13 ( V_3 , V_227 ) == - 1 )
return 0 ;
snprintf ( V_225 , sizeof( V_225 ) ,
L_21 , V_3 -> V_122 -> V_208 ) ;
V_3 -> V_206 = F_85 ( V_225 ) ;
if ( ! V_3 -> V_206 ) {
F_72 ( V_184 L_22 ) ;
return 0 ;
}
F_86 ( & V_3 -> V_224 , F_82 ) ;
return 1 ;
}
static bool F_87 ( struct V_2 * V_3 ,
bool V_228 )
{
T_2 V_17 ;
if ( ! V_229 )
return false ;
F_11 ( V_3 , V_29 ,
V_230 ) ;
V_17 = F_13 ( V_3 , V_227 ) ;
if ( V_17 == - 1 ) {
F_72 ( V_128 L_23 ) ;
return false ;
} else {
struct V_231 V_111 = { 0 } ;
V_111 . V_228 = V_228 ;
F_72 ( V_128
L_24 ,
V_228 ? L_25 : L_26 ) ;
F_19 ( V_3 ,
V_230 ,
& V_111 , sizeof( V_111 ) ) ;
return F_13 ( V_3 ,
V_227 ) != 0 ;
}
}
static T_5 F_88 ( int V_232 , void * V_233 )
{
struct V_2 * V_3 = V_233 ;
int V_234 ;
if ( V_3 -> V_235 || V_3 -> V_236 )
V_234 = true ;
else {
T_2 V_17 = F_15 ( V_3 ) ;
V_234 = ( V_17 & V_237 ) != 0 ;
if ( V_234 )
F_16 ( V_233 , V_17 ) ;
}
if ( V_234 ) {
unsigned long V_66 ;
F_63 ( & V_3 -> V_204 , V_66 ) ;
F_55 ( V_3 ) ;
if ( V_3 -> V_22 && F_80 ( V_3 ) )
F_89 ( V_3 -> V_206 , & V_3 -> V_224 ) ;
F_64 ( & V_3 -> V_204 , V_66 ) ;
}
return F_90 ( V_234 ) ;
}
static void F_91 ( const struct V_2 * V_3 )
{
struct V_5 * V_8 = V_3 -> V_10 ;
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; ++ V_28 , ++ V_8 )
F_92 ( ( unsigned long ) V_8 -> V_63 , F_93 ( V_75 ) ) ;
}
static int F_94 ( const struct V_2 * V_3 ,
unsigned int * V_232 )
{
struct V_238 V_239 = { 0 , V_240 } ;
int V_241 ;
V_241 = F_95 ( V_3 -> V_4 , & V_239 , 1 ) ;
if ( V_241 )
return V_241 ;
* V_232 = V_239 . V_242 ;
return 0 ;
}
static void F_96 ( struct V_2 * V_3 )
{
if ( V_3 -> V_232 ) {
F_97 ( V_3 -> V_232 , V_3 ) ;
V_3 -> V_232 = 0 ;
}
if ( V_3 -> V_235 ) {
F_98 ( V_3 -> V_4 ) ;
V_3 -> V_235 = 0 ;
} else if ( V_3 -> V_236 ) {
F_99 ( V_3 -> V_4 ) ;
V_3 -> V_236 = 0 ;
}
}
static void F_100 ( struct V_2 * V_3 )
{
F_96 ( V_3 ) ;
if ( V_3 -> V_206 )
F_101 ( V_3 -> V_206 ) ;
if ( V_3 -> V_18 )
F_102 ( V_3 -> V_4 , V_3 -> V_18 ) ;
F_103 ( V_3 -> V_4 ) ;
if ( V_3 -> V_10 ) {
F_91 ( V_3 ) ;
F_104 ( V_3 -> V_10 ) ;
}
if ( V_3 -> V_48 )
F_105 ( V_3 -> V_4 , V_83 ,
V_3 -> V_48 , V_3 -> V_84 ) ;
if ( V_3 -> V_90 )
F_105 ( V_3 -> V_4 ,
V_3 -> V_86 * V_83 ,
V_3 -> V_90 , V_3 -> V_91 ) ;
if ( V_3 -> V_94 )
F_105 ( V_3 -> V_4 ,
V_3 -> V_92 * V_83 ,
V_3 -> V_94 , V_3 -> V_95 ) ;
if ( V_3 -> V_99 )
F_105 ( V_3 -> V_4 ,
V_3 -> V_96 * V_83 ,
V_3 -> V_99 , V_3 -> V_100 ) ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_5 * V_8 ;
int V_28 ;
V_8 = V_3 -> V_10 ;
F_73 ( sizeof( struct V_243 ) > V_75 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; ++ V_28 , ++ V_8 ) {
V_8 -> V_63 = ( void * ) F_107 ( V_244 ,
F_93 ( V_75 ) ) ;
V_8 -> V_74 = 0 ;
F_30 ( ! F_45 ( ( ( unsigned long ) V_8 -> V_63 ) , V_83 ) ) ;
if ( ! V_8 -> V_63 ) {
for (; V_28 >= 0 ; -- V_28 , -- V_8 ) {
F_92 ( ( unsigned long ) V_8 -> V_63 ,
F_93 ( V_75 ) ) ;
V_8 -> V_63 = NULL ;
}
return - V_85 ;
}
}
return 0 ;
}
static T_2 F_108 ( struct V_2 * V_3 )
{
struct V_245 V_7 ;
struct V_246 * V_247 ;
struct V_1 * V_4 ;
T_4 V_248 ;
void * V_249 ;
T_2 V_250 = 16 ;
V_4 = F_1 ( V_3 ) ;
V_249 = F_43 ( V_3 -> V_4 , V_83 ,
& V_248 ) ;
if ( ! V_249 ) {
F_109 ( V_4 , L_27 ) ;
goto exit;
}
F_30 ( V_248 & ~ V_251 ) ;
V_7 . V_252 = ( ( T_1 ) V_253 ) << 32 ;
V_7 . V_254 = V_255 ;
V_7 . V_256 = V_248 ;
V_7 . V_257 = 0 ;
V_247 = V_249 ;
memset ( V_247 , 0 , sizeof *V_247 ) ;
V_247 -> V_137 = V_258 ;
V_247 -> V_139 = V_259 ;
F_19 ( V_3 , V_260 , & V_7 , sizeof V_7 ) ;
if ( V_247 -> V_137 == V_142 &&
V_247 -> V_139 == V_261 ) {
struct V_262 * V_263 ;
V_263 = V_249 ;
V_250 = V_263 -> V_250 ;
} else
F_109 ( V_4 , L_28 ,
V_247 -> V_137 , V_247 -> V_139 ) ;
F_105 ( V_3 -> V_4 , V_83 , V_249 , V_248 ) ;
exit:
return V_250 ;
}
static int F_110 ( struct V_264 * V_265 , const struct V_266 * V_33 )
{
struct V_2 * V_3 ;
struct V_2 V_267 ;
struct V_120 * V_122 = NULL ;
unsigned int V_28 ;
unsigned long V_66 = 0 ;
int error ;
T_2 V_268 ;
error = - V_269 ;
if ( F_111 ( V_265 ) )
return error ;
if ( F_112 ( V_265 , F_113 ( 64 ) ) == 0 &&
F_114 ( V_265 , F_113 ( 64 ) ) == 0 ) {
F_72 ( V_128 L_29 ) ;
} else if ( F_112 ( V_265 , F_113 ( 32 ) ) == 0 &&
F_114 ( V_265 , F_113 ( 32 ) ) == 0 ) {
F_72 ( V_128 L_30 ) ;
} else {
F_72 ( V_184 L_31 ) ;
goto V_270;
}
V_3 = & V_267 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_265 ;
V_3 -> V_210 = V_265 -> V_271 ;
if ( F_115 ( V_265 , L_32 ) ) {
F_72 ( V_184 L_33 ) ;
goto V_270;
}
for ( V_28 = 0 ; V_28 < V_272 ; V_28 ++ ) {
if ( ( F_116 ( V_265 , V_28 ) & V_273 ) )
continue;
if ( F_117 ( V_265 , V_28 ) < V_274 )
continue;
break;
}
if ( V_28 == V_272 ) {
F_72 ( V_184
L_34 ) ;
goto V_275;
}
V_3 -> V_18 = F_118 ( V_265 , V_28 , V_274 ) ;
if ( ! V_3 -> V_18 ) {
F_72 ( V_184
L_35 ,
V_28 , V_274 ) ;
goto V_275;
}
F_119 ( V_265 ) ;
V_268 = F_108 ( V_3 ) ;
F_72 ( V_128 L_36 , V_268 ) ;
if ( V_88 == 0 )
V_88 = ( V_268 > 16 ) ?
V_276 :
V_277 ;
F_72 ( V_128
L_37 ,
V_88 ) ;
V_211 . V_125 =
F_44 ( V_87 , V_88 ) *
V_89 ;
V_211 . V_212 =
F_44 ( V_211 . V_125 , V_278 ) ;
V_122 = F_120 ( & V_211 , sizeof( struct V_2 ) ) ;
if ( ! V_122 ) {
F_72 ( V_184 L_38 ) ;
goto V_275;
}
V_3 = F_62 ( V_122 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_265 ;
V_3 -> V_122 = V_122 ;
V_3 -> V_210 = V_267 . V_210 ;
V_3 -> V_18 = V_267 . V_18 ;
F_121 ( & V_3 -> V_204 ) ;
V_122 -> V_279 = 0 ;
V_122 -> V_280 = 1 ;
V_122 -> V_281 = 16 ;
V_122 -> V_268 = V_268 ;
F_122 ( V_265 , V_122 ) ;
F_25 ( V_3 ) ;
V_3 -> V_22 = F_84 ( V_3 ) ;
error = F_42 ( V_3 ) ;
if ( error ) {
F_72 ( V_184 L_39 ) ;
goto V_282;
}
F_46 ( V_3 ) ;
V_3 -> V_10 = F_123 ( V_3 -> V_11 ,
sizeof( struct V_5 ) , V_244 ) ;
if ( ! V_3 -> V_10 ) {
F_72 ( V_184 L_40 ) ;
error = - V_85 ;
goto V_283;
}
F_124 ( & V_3 -> V_12 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; V_28 ++ ) {
struct V_5 * V_8 = V_3 -> V_10 + V_28 ;
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
error = F_106 ( V_3 ) ;
if ( error ) {
F_72 ( V_184 L_41 ) ;
goto V_283;
}
if ( ! V_284 &&
F_94 ( V_3 , & V_3 -> V_232 ) == 0 ) {
F_72 ( V_128 L_42 ) ;
V_3 -> V_236 = 1 ;
} else if ( ! V_285 && F_125 ( V_265 ) == 0 ) {
F_72 ( V_128 L_43 ) ;
V_3 -> V_235 = 1 ;
V_3 -> V_232 = V_265 -> V_232 ;
} else {
F_72 ( V_128 L_44 ) ;
V_3 -> V_232 = V_265 -> V_232 ;
V_66 = V_286 ;
}
V_3 -> V_49 = F_87 ( V_3 , true ) ;
F_72 ( V_173 L_45 ,
V_3 -> V_49 ? L_25 : L_26 ) ;
error = F_126 ( V_3 -> V_232 , F_88 , V_66 ,
L_32 , V_3 ) ;
if ( error ) {
F_72 ( V_184
L_46 , error ) ;
V_3 -> V_232 = 0 ;
goto V_283;
}
error = F_127 ( V_122 , & V_265 -> V_4 ) ;
if ( error ) {
F_72 ( V_184
L_47 , error ) ;
goto V_283;
}
F_128 ( & V_265 -> V_4 , L_48 ,
V_3 -> V_210 , V_122 -> V_208 ) ;
F_17 ( V_3 ) ;
F_129 ( V_122 ) ;
return 0 ;
V_283:
F_25 ( V_3 ) ;
V_282:
F_100 ( V_3 ) ;
F_78 ( V_122 ) ;
V_270:
F_130 ( V_265 ) ;
return error ;
V_275:
F_100 ( V_3 ) ;
goto V_270;
}
static void F_131 ( struct V_2 * V_3 )
{
F_18 ( V_3 ) ;
if ( V_3 -> V_206 )
F_67 ( V_3 -> V_206 ) ;
F_96 ( V_3 ) ;
F_22 ( V_3 ) ;
F_55 ( V_3 ) ;
F_25 ( V_3 ) ;
}
static void F_132 ( struct V_264 * V_4 )
{
struct V_120 * V_122 = F_133 ( V_4 ) ;
struct V_2 * V_3 = F_62 ( V_122 ) ;
F_131 ( V_3 ) ;
}
static void F_134 ( struct V_264 * V_265 )
{
struct V_120 * V_122 = F_133 ( V_265 ) ;
struct V_2 * V_3 = F_62 ( V_122 ) ;
F_135 ( V_122 ) ;
F_131 ( V_3 ) ;
F_100 ( V_3 ) ;
F_78 ( V_122 ) ;
F_130 ( V_265 ) ;
}
static int T_6 F_136 ( void )
{
F_137 ( L_49 ,
V_287 , V_288 ) ;
return F_138 ( & V_289 ) ;
}
static void T_7 F_139 ( void )
{
F_140 ( & V_289 ) ;
}
