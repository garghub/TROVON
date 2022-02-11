static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
T_2 V_10 ;
bool V_11 = false , V_12 = false , V_13 = false ;
switch ( V_2 -> V_14 . V_15 ) {
case V_16 :
V_6 = V_17 ;
break;
case V_18 :
V_6 = V_19 ;
break;
case V_20 :
V_6 = V_21 ;
if ( ! F_6 ( F_7 ( V_2 ) , V_22 , V_23 , & V_10 ) ) {
if ( V_10 & V_24 )
V_6 = V_21 | V_25 ;
}
break;
case V_26 :
V_6 = V_21 ;
break;
case V_27 :
V_6 = V_21 | V_25 ;
break;
case V_28 :
case V_29 :
if ( V_2 -> V_30 ) {
V_6 = V_31 ;
V_11 = true ;
} else {
V_6 = V_17 ;
}
break;
default:
V_6 = V_17 ;
break;
}
switch ( V_2 -> V_32 . V_33 ) {
case V_34 :
V_6 |= V_35 ;
V_13 = true ;
break;
case V_36 :
V_6 |= V_2 -> V_32 . V_37 . type == V_38 ?
V_39 : V_40 ;
V_13 = true ;
break;
case V_41 :
V_6 |= V_42 ;
break;
case V_43 :
V_6 |= V_2 -> V_32 . V_37 . type == V_38 ?
V_44 : V_45 ;
V_13 = true ;
break;
default:
break;
}
V_8 = V_46 | F_8 ( 1 ) ;
if ( ! ( V_2 -> V_32 . V_37 . V_47 & V_48 ) )
V_8 |= V_49 ;
if ( ! ( V_2 -> V_32 . V_37 . V_47 & V_50 ) )
V_8 |= V_51 ;
switch ( V_2 -> V_14 . V_52 ) {
case V_53 :
F_1 ( V_2 ,
F_9 ( V_2 -> V_14 . V_54 * V_2 -> V_14 . V_55 , 0x80 ) ,
V_56 ) ;
V_7 = V_57 ;
V_12 = true ;
break;
case V_58 :
V_7 = V_59 ;
V_12 = true ;
break;
case V_60 :
V_7 = 0 ;
V_12 = true ;
break;
case V_61 :
V_7 = V_62 ;
break;
case V_63 :
V_7 = 0 ;
break;
case V_64 :
V_7 = V_65 ;
break;
default:
F_10 ( V_2 , L_1 ,
V_2 -> V_14 . V_52 ) ;
return - V_66 ;
}
V_6 |= V_67 ;
if ( V_13 == V_12 )
V_6 |= V_68 ;
V_9 = V_11 ? V_69 : V_70 ;
F_1 ( V_2 , V_9 , V_71 ) ;
F_1 ( V_2 , V_9 , V_72 ) ;
F_1 ( V_2 , V_7 , V_73 ) ;
F_1 ( V_2 , V_8 , V_74 ) ;
F_1 ( V_2 , V_6 | V_75 , V_76 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 , L_2 ,
V_2 -> V_30 ? L_3 : L_4 ) ;
if ( V_2 -> V_30 )
F_1 ( V_2 , V_77 , V_78 ) ;
else
F_1 ( V_2 , V_79 , V_78 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_78 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_80 ;
F_15 ( V_2 ) ;
V_80 = F_5 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_76 ) & ~ V_75 , V_76 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_72 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_71 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_3 ( V_2 , V_71 ) , V_71 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_81 ) & V_82 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_83 )
{
if ( V_2 -> V_30 )
return ( V_83 & V_84 ) >> V_85 ;
return 0 ;
}
static enum V_86 F_22 ( struct V_1 * V_2 , T_1 V_83 )
{
if ( V_2 -> V_14 . V_15 == V_28 ) {
if ( V_83 & V_87 )
return V_18 ;
return V_16 ;
}
return V_2 -> V_14 . V_15 ;
}
static void F_23 ( struct V_1 * V_2 , int V_88 , T_3 V_89 )
{
const struct V_90 * V_91 ;
int V_92 , V_93 ;
T_3 V_4 ;
V_91 = F_24 ( V_2 -> V_14 . V_52 ) ;
V_92 = V_2 -> V_94 . V_95 * V_91 -> V_96 ;
V_93 = V_2 -> V_94 . V_97 * V_2 -> V_14 . V_98 ;
V_4 = V_89 + V_92 + V_93 ;
if ( F_25 ( ( V_92 | V_93 | V_4 ) & V_99 ) )
return;
F_1 ( V_2 , V_4 , F_26 ( V_88 ) ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned short V_100 )
{
int V_101 ;
const struct V_102 * V_103 = NULL ;
const struct V_102 * V_104 = NULL ;
for ( V_101 = 0 ; V_101 < F_28 ( V_105 ) ; V_101 ++ ) {
V_103 = V_104 ;
V_104 = & V_105 [ V_101 ] ;
if ( V_100 < V_104 -> V_106 )
break;
}
if ( V_103 && V_104 &&
V_100 - V_103 -> V_106 < V_104 -> V_106 - V_100 )
V_104 = V_103 ;
F_1 ( V_2 , V_104 -> V_107 [ 0 ] , V_108 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 1 ] , V_109 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 2 ] , V_110 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 3 ] , V_111 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 4 ] , V_112 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 5 ] , V_113 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 6 ] , V_114 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 7 ] , V_115 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 8 ] , V_116 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 9 ] , V_117 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 10 ] , V_118 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 11 ] , V_119 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 12 ] , V_120 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 13 ] , V_121 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 14 ] , V_122 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 15 ] , V_123 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 16 ] , V_124 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 17 ] , V_125 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 18 ] , V_126 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 19 ] , V_127 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 20 ] , V_128 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 21 ] , V_129 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 22 ] , V_130 ) ;
F_1 ( V_2 , V_104 -> V_107 [ 23 ] , V_131 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_100 , V_132 ;
F_1 ( V_2 , V_2 -> V_133 . V_95 , V_134 ) ;
F_1 ( V_2 , V_2 -> V_133 . V_95 + V_2 -> V_133 . V_54 - 1 , V_135 ) ;
switch ( V_2 -> V_14 . V_15 ) {
case V_20 :
case V_26 :
case V_27 :
F_1 ( V_2 , V_2 -> V_133 . V_97 / 2 , V_136 ) ;
F_1 ( V_2 , ( V_2 -> V_133 . V_97 + V_2 -> V_133 . V_55 ) / 2 - 1 ,
V_137 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_133 . V_97 , V_136 ) ;
F_1 ( V_2 , V_2 -> V_133 . V_97 + V_2 -> V_133 . V_55 - 1 ,
V_137 ) ;
break;
}
V_132 = 0 ;
if ( V_2 -> V_133 . V_55 != V_2 -> V_94 . V_55 )
V_132 = ( 4096 * V_2 -> V_133 . V_55 ) / V_2 -> V_94 . V_55 ;
F_1 ( V_2 , V_132 , V_138 ) ;
V_100 = 0 ;
if ( V_2 -> V_133 . V_54 != V_2 -> V_94 . V_54 )
V_100 = ( 4096 * V_2 -> V_133 . V_54 ) / V_2 -> V_94 . V_54 ;
if ( V_100 > 0 && V_100 < 2048 )
V_100 = 2048 ;
F_1 ( V_2 , V_100 , V_139 ) ;
if ( V_100 < 4096 )
V_100 *= 2 ;
F_27 ( V_2 , V_100 ) ;
F_1 ( V_2 , 0 , V_140 ) ;
F_1 ( V_2 , 0 , V_141 ) ;
F_1 ( V_2 , V_2 -> V_14 . V_54 - 1 , V_142 ) ;
switch ( V_2 -> V_14 . V_15 ) {
case V_20 :
case V_26 :
case V_27 :
F_1 ( V_2 , V_2 -> V_14 . V_55 / 2 - 1 , V_143 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_14 . V_55 - 1 , V_143 ) ;
break;
}
if ( V_2 -> V_14 . V_52 == V_53 )
F_1 ( V_2 , F_9 ( V_2 -> V_14 . V_54 , 0x20 ) , V_144 ) ;
else
F_1 ( V_2 , F_9 ( V_2 -> V_14 . V_54 , 0x10 ) , V_144 ) ;
F_12 ( V_2 ,
L_5 ,
V_2 -> V_133 . V_54 , V_2 -> V_133 . V_55 , V_2 -> V_133 . V_95 ,
V_2 -> V_133 . V_97 , V_132 , V_100 , V_2 -> V_14 . V_54 , V_2 -> V_14 . V_55 ,
0 , 0 ) ;
}
void F_29 ( struct V_1 * V_2 , struct V_145 * V_146 ,
T_1 V_54 , T_1 V_55 )
{
V_146 -> V_54 = V_54 ;
V_146 -> V_55 = V_55 ;
}
static bool F_30 ( struct V_1 * V_2 , int V_88 )
{
struct V_147 * V_148 ;
struct V_149 * V_150 ;
T_3 V_151 ;
if ( V_2 -> V_152 [ V_88 ] != NULL )
return true ;
if ( F_31 ( & V_2 -> V_153 ) )
return false ;
F_12 ( V_2 , L_6 , V_88 ) ;
V_148 = F_32 ( V_2 -> V_153 . V_154 , struct V_147 , V_155 ) ;
V_150 = & V_148 -> V_156 ;
F_33 ( F_34 ( V_150 ) ) ;
V_2 -> V_152 [ V_88 ] = V_150 ;
V_151 = F_35 ( & V_150 -> V_157 , 0 ) ;
F_23 ( V_2 , V_88 , V_151 ) ;
return true ;
}
static bool F_36 ( struct V_1 * V_2 )
{
int V_88 , V_158 ;
V_158 = V_2 -> V_30 ? V_159 : 1 ;
for ( V_88 = 0 ; V_88 < V_158 ; V_88 ++ )
if ( ! F_30 ( V_2 , V_88 ) )
return false ;
return true ;
}
static T_4 F_37 ( int V_160 , void * V_161 )
{
struct V_1 * V_2 = V_161 ;
T_1 V_162 , V_83 ;
int V_88 ;
unsigned int V_163 , V_164 = 0 ;
unsigned long V_47 ;
F_38 ( & V_2 -> V_165 , V_47 ) ;
V_162 = F_18 ( V_2 ) ;
if ( ! V_162 )
goto V_166;
F_19 ( V_2 ) ;
V_164 = 1 ;
if ( V_2 -> V_167 == V_168 ) {
F_12 ( V_2 , L_7 ) ;
goto V_166;
}
if ( V_2 -> V_167 == V_169 ) {
F_12 ( V_2 , L_8 ) ;
goto V_166;
}
V_83 = F_3 ( V_2 , V_81 ) ;
V_88 = F_21 ( V_2 , V_83 ) ;
V_163 = V_2 -> V_163 ++ ;
F_12 ( V_2 , L_9 ,
V_163 , V_88 ,
V_88 == 0 ? 'x' : V_2 -> V_152 [ 0 ] != NULL ? '1' : '0' ,
V_88 == 1 ? 'x' : V_2 -> V_152 [ 1 ] != NULL ? '1' : '0' ,
V_88 == 2 ? 'x' : V_2 -> V_152 [ 2 ] != NULL ? '1' : '0' ,
! F_31 ( & V_2 -> V_153 ) ) ;
if ( F_25 ( ( V_2 -> V_152 [ V_88 ] == NULL ) ) )
goto V_166;
V_2 -> V_152 [ V_88 ] -> V_15 = F_22 ( V_2 , V_83 ) ;
V_2 -> V_152 [ V_88 ] -> V_163 = V_163 ;
V_2 -> V_152 [ V_88 ] -> V_157 . V_170 = F_39 () ;
F_40 ( & V_2 -> V_152 [ V_88 ] -> V_157 , V_171 ) ;
V_2 -> V_152 [ V_88 ] = NULL ;
if ( ! F_36 ( V_2 ) ) {
V_2 -> V_167 = V_172 ;
if ( V_2 -> V_30 ) {
F_13 ( V_2 ) ;
F_12 ( V_2 , L_10 , V_163 ) ;
}
} else {
if ( ! V_2 -> V_30 )
F_11 ( V_2 ) ;
}
V_166:
F_41 ( & V_2 -> V_165 , V_47 ) ;
return F_42 ( V_164 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
enum V_173 V_167 )
{
struct V_147 * V_148 , * V_174 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_159 ; V_101 ++ ) {
if ( V_2 -> V_152 [ V_101 ] ) {
F_40 ( & V_2 -> V_152 [ V_101 ] -> V_157 ,
V_167 ) ;
V_2 -> V_152 [ V_101 ] = NULL ;
}
}
F_44 (buf, node, &vin->buf_list, list) {
F_40 ( & V_148 -> V_156 . V_157 , V_167 ) ;
F_45 ( & V_148 -> V_155 ) ;
}
}
static int F_46 ( struct V_175 * V_176 , unsigned int * V_177 ,
unsigned int * V_178 , unsigned int V_179 [] ,
struct V_180 * V_181 [] )
{
struct V_1 * V_2 = F_47 ( V_176 ) ;
if ( * V_178 )
return V_179 [ 0 ] < V_2 -> V_14 . V_182 ? - V_66 : 0 ;
* V_178 = 1 ;
V_179 [ 0 ] = V_2 -> V_14 . V_182 ;
return 0 ;
}
static int F_48 ( struct V_183 * V_156 )
{
struct V_1 * V_2 = F_47 ( V_156 -> V_175 ) ;
unsigned long V_184 = V_2 -> V_14 . V_182 ;
if ( F_49 ( V_156 , 0 ) < V_184 ) {
F_10 ( V_2 , L_11 ,
F_49 ( V_156 , 0 ) , V_184 ) ;
return - V_66 ;
}
F_50 ( V_156 , 0 , V_184 ) ;
return 0 ;
}
static void F_51 ( struct V_183 * V_156 )
{
struct V_149 * V_150 = F_52 ( V_156 ) ;
struct V_1 * V_2 = F_47 ( V_156 -> V_175 ) ;
unsigned long V_47 ;
F_38 ( & V_2 -> V_165 , V_47 ) ;
F_53 ( F_34 ( V_150 ) , & V_2 -> V_153 ) ;
if ( V_2 -> V_167 == V_172 )
if ( F_36 ( V_2 ) )
F_11 ( V_2 ) ;
F_41 ( & V_2 -> V_165 , V_47 ) ;
}
static int F_54 ( struct V_175 * V_176 , unsigned int V_185 )
{
struct V_1 * V_2 = F_47 ( V_176 ) ;
struct V_186 * V_187 ;
unsigned long V_47 ;
int V_80 ;
V_187 = F_7 ( V_2 ) ;
F_6 ( V_187 , V_22 , V_188 , 1 ) ;
F_38 ( & V_2 -> V_165 , V_47 ) ;
V_2 -> V_167 = V_189 ;
V_2 -> V_163 = 0 ;
V_2 -> V_30 = V_185 > V_159 ;
if ( ! F_36 ( V_2 ) ) {
F_10 ( V_2 , L_12 ) ;
V_80 = - V_66 ;
goto V_190;
}
V_80 = F_14 ( V_2 ) ;
V_190:
if ( V_80 ) {
F_43 ( V_2 , V_191 ) ;
F_6 ( V_187 , V_22 , V_188 , 0 ) ;
}
F_41 ( & V_2 -> V_165 , V_47 ) ;
return V_80 ;
}
static void F_55 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = F_47 ( V_176 ) ;
struct V_186 * V_187 ;
unsigned long V_47 ;
int V_192 = 0 ;
F_38 ( & V_2 -> V_165 , V_47 ) ;
V_2 -> V_167 = V_169 ;
while ( V_192 ++ < V_193 ) {
F_16 ( V_2 ) ;
if ( ! F_20 ( V_2 ) ) {
V_2 -> V_167 = V_168 ;
break;
}
F_41 ( & V_2 -> V_165 , V_47 ) ;
F_56 ( V_194 ) ;
F_38 ( & V_2 -> V_165 , V_47 ) ;
}
if ( V_2 -> V_167 != V_168 ) {
F_10 ( V_2 , L_13 ) ;
V_2 -> V_167 = V_168 ;
}
F_43 ( V_2 , V_195 ) ;
F_41 ( & V_2 -> V_165 , V_47 ) ;
V_187 = F_7 ( V_2 ) ;
F_6 ( V_187 , V_22 , V_188 , 0 ) ;
F_17 ( V_2 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_196 ) ;
F_59 ( & V_2 -> V_197 ) ;
}
int F_60 ( struct V_1 * V_2 , int V_160 )
{
struct V_175 * V_198 = & V_2 -> V_199 ;
int V_101 , V_80 ;
V_80 = F_61 ( V_2 -> V_200 , & V_2 -> V_197 ) ;
if ( V_80 )
return V_80 ;
F_62 ( & V_2 -> V_196 ) ;
F_63 ( & V_2 -> V_153 ) ;
F_64 ( & V_2 -> V_165 ) ;
V_2 -> V_167 = V_168 ;
for ( V_101 = 0 ; V_101 < V_159 ; V_101 ++ )
V_2 -> V_152 [ V_101 ] = NULL ;
V_198 -> type = V_201 ;
V_198 -> V_202 = V_203 | V_204 | V_205 ;
V_198 -> V_196 = & V_2 -> V_196 ;
V_198 -> V_206 = V_2 ;
V_198 -> V_207 = sizeof( struct V_147 ) ;
V_198 -> V_208 = & V_209 ;
V_198 -> V_210 = & V_211 ;
V_198 -> V_212 = V_213 ;
V_198 -> V_214 = 2 ;
V_198 -> V_200 = V_2 -> V_200 ;
V_80 = F_65 ( V_198 ) ;
if ( V_80 < 0 ) {
F_10 ( V_2 , L_14 ) ;
goto error;
}
V_80 = F_66 ( V_2 -> V_200 , V_160 , F_37 , V_215 ,
V_216 , V_2 ) ;
if ( V_80 ) {
F_10 ( V_2 , L_15 ) ;
goto error;
}
return 0 ;
error:
F_57 ( V_2 ) ;
return V_80 ;
}
