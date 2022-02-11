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
F_1 ( V_2 , 0 , V_72 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_71 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_3 ( V_2 , V_71 ) , V_71 ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_77 ) & V_78 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_79 )
{
if ( V_2 -> V_30 )
return ( V_79 & V_80 ) >> V_81 ;
return 0 ;
}
static enum V_82 F_16 ( struct V_1 * V_2 , T_1 V_79 )
{
if ( V_2 -> V_14 . V_15 == V_28 ) {
if ( V_79 & V_83 )
return V_18 ;
return V_16 ;
}
return V_2 -> V_14 . V_15 ;
}
static void F_17 ( struct V_1 * V_2 , int V_84 , T_3 V_85 )
{
const struct V_86 * V_87 ;
int V_88 , V_89 ;
T_3 V_4 ;
V_87 = F_18 ( V_2 -> V_14 . V_52 ) ;
V_88 = V_2 -> V_90 . V_91 * V_87 -> V_92 ;
V_89 = V_2 -> V_90 . V_93 * V_2 -> V_14 . V_94 ;
V_4 = V_85 + V_88 + V_89 ;
if ( F_19 ( ( V_88 | V_89 | V_4 ) & V_95 ) )
return;
F_1 ( V_2 , V_4 , F_20 ( V_84 ) ) ;
}
static bool F_21 ( struct V_1 * V_2 , int V_84 )
{
struct V_96 * V_97 ;
struct V_98 * V_99 ;
T_3 V_100 ;
if ( V_2 -> V_101 [ V_84 ] != NULL )
return true ;
if ( F_22 ( & V_2 -> V_102 ) )
return false ;
F_23 ( V_2 , L_2 , V_84 ) ;
V_97 = F_24 ( V_2 -> V_102 . V_103 , struct V_96 , V_104 ) ;
V_99 = & V_97 -> V_105 ;
F_25 ( F_26 ( V_99 ) ) ;
V_2 -> V_101 [ V_84 ] = V_99 ;
V_100 = F_27 ( & V_99 -> V_106 , 0 ) ;
F_17 ( V_2 , V_84 , V_100 ) ;
return true ;
}
static bool F_28 ( struct V_1 * V_2 )
{
int V_84 , V_107 ;
V_107 = V_2 -> V_30 ? V_108 : 1 ;
for ( V_84 = 0 ; V_84 < V_107 ; V_84 ++ )
if ( ! F_21 ( V_2 , V_84 ) )
return false ;
return true ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_23 ( V_2 , L_3 ,
V_2 -> V_30 ? L_4 : L_5 ) ;
if ( V_2 -> V_30 )
F_1 ( V_2 , V_109 , V_110 ) ;
else
F_1 ( V_2 , V_111 , V_110 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_96 * V_97 , * V_112 ;
int V_113 , V_114 ;
V_113 = 0 ;
F_31 (buf, node, &vin->buf_list, list)
V_113 ++ ;
V_2 -> V_30 = V_113 > V_108 ;
if ( ! F_28 ( V_2 ) ) {
F_10 ( V_2 , L_6 ) ;
return - V_66 ;
}
F_32 ( V_2 ) ;
V_114 = F_5 ( V_2 ) ;
if ( V_114 )
return V_114 ;
F_29 ( V_2 ) ;
V_2 -> V_115 = V_116 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_110 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_76 ) & ~ V_75 , V_76 ) ;
}
static void F_34 ( struct V_1 * V_2 , unsigned short V_117 )
{
int V_118 ;
const struct V_119 * V_120 = NULL ;
const struct V_119 * V_121 = NULL ;
for ( V_118 = 0 ; V_118 < F_35 ( V_122 ) ; V_118 ++ ) {
V_120 = V_121 ;
V_121 = & V_122 [ V_118 ] ;
if ( V_117 < V_121 -> V_123 )
break;
}
if ( V_120 && V_121 &&
V_117 - V_120 -> V_123 < V_121 -> V_123 - V_117 )
V_121 = V_120 ;
F_1 ( V_2 , V_121 -> V_124 [ 0 ] , V_125 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 1 ] , V_126 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 2 ] , V_127 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 3 ] , V_128 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 4 ] , V_129 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 5 ] , V_130 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 6 ] , V_131 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 7 ] , V_132 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 8 ] , V_133 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 9 ] , V_134 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 10 ] , V_135 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 11 ] , V_136 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 12 ] , V_137 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 13 ] , V_138 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 14 ] , V_139 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 15 ] , V_140 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 16 ] , V_141 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 17 ] , V_142 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 18 ] , V_143 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 19 ] , V_144 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 20 ] , V_145 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 21 ] , V_146 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 22 ] , V_147 ) ;
F_1 ( V_2 , V_121 -> V_124 [ 23 ] , V_148 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
T_1 V_117 , V_149 ;
F_1 ( V_2 , V_2 -> V_150 . V_91 , V_151 ) ;
F_1 ( V_2 , V_2 -> V_150 . V_91 + V_2 -> V_150 . V_54 - 1 , V_152 ) ;
switch ( V_2 -> V_14 . V_15 ) {
case V_20 :
case V_26 :
case V_27 :
F_1 ( V_2 , V_2 -> V_150 . V_93 / 2 , V_153 ) ;
F_1 ( V_2 , ( V_2 -> V_150 . V_93 + V_2 -> V_150 . V_55 ) / 2 - 1 ,
V_154 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_150 . V_93 , V_153 ) ;
F_1 ( V_2 , V_2 -> V_150 . V_93 + V_2 -> V_150 . V_55 - 1 ,
V_154 ) ;
break;
}
V_149 = 0 ;
if ( V_2 -> V_150 . V_55 != V_2 -> V_90 . V_55 )
V_149 = ( 4096 * V_2 -> V_150 . V_55 ) / V_2 -> V_90 . V_55 ;
F_1 ( V_2 , V_149 , V_155 ) ;
V_117 = 0 ;
if ( V_2 -> V_150 . V_54 != V_2 -> V_90 . V_54 )
V_117 = ( 4096 * V_2 -> V_150 . V_54 ) / V_2 -> V_90 . V_54 ;
if ( V_117 > 0 && V_117 < 2048 )
V_117 = 2048 ;
F_1 ( V_2 , V_117 , V_156 ) ;
if ( V_117 < 4096 )
V_117 *= 2 ;
F_34 ( V_2 , V_117 ) ;
F_1 ( V_2 , 0 , V_157 ) ;
F_1 ( V_2 , 0 , V_158 ) ;
F_1 ( V_2 , V_2 -> V_14 . V_54 - 1 , V_159 ) ;
switch ( V_2 -> V_14 . V_15 ) {
case V_20 :
case V_26 :
case V_27 :
F_1 ( V_2 , V_2 -> V_14 . V_55 / 2 - 1 , V_160 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_14 . V_55 - 1 , V_160 ) ;
break;
}
if ( V_2 -> V_14 . V_52 == V_53 )
F_1 ( V_2 , F_9 ( V_2 -> V_14 . V_54 , 0x20 ) , V_161 ) ;
else
F_1 ( V_2 , F_9 ( V_2 -> V_14 . V_54 , 0x10 ) , V_161 ) ;
F_23 ( V_2 ,
L_7 ,
V_2 -> V_150 . V_54 , V_2 -> V_150 . V_55 , V_2 -> V_150 . V_91 ,
V_2 -> V_150 . V_93 , V_149 , V_117 , V_2 -> V_14 . V_54 , V_2 -> V_14 . V_55 ,
0 , 0 ) ;
}
void F_36 ( struct V_1 * V_2 , struct V_162 * V_163 ,
T_1 V_54 , T_1 V_55 )
{
V_163 -> V_54 = V_54 ;
V_163 -> V_55 = V_55 ;
}
static T_4 F_37 ( int V_164 , void * V_165 )
{
struct V_1 * V_2 = V_165 ;
T_1 V_166 , V_79 ;
int V_84 ;
unsigned int V_118 , V_167 , V_168 = 0 ;
unsigned long V_47 ;
F_38 ( & V_2 -> V_169 , V_47 ) ;
V_166 = F_12 ( V_2 ) ;
if ( ! V_166 )
goto V_170;
F_13 ( V_2 ) ;
V_168 = 1 ;
if ( V_2 -> V_115 == V_171 ) {
F_23 ( V_2 , L_8 ) ;
goto V_170;
}
if ( V_2 -> V_115 == V_172 ) {
F_23 ( V_2 , L_9 ) ;
goto V_170;
}
V_79 = F_3 ( V_2 , V_77 ) ;
V_84 = F_15 ( V_2 , V_79 ) ;
V_167 = V_2 -> V_167 ++ ;
F_23 ( V_2 , L_10 ,
V_167 , V_84 ,
V_84 == 0 ? 'x' : V_2 -> V_101 [ 0 ] != NULL ? '1' : '0' ,
V_84 == 1 ? 'x' : V_2 -> V_101 [ 1 ] != NULL ? '1' : '0' ,
V_84 == 2 ? 'x' : V_2 -> V_101 [ 2 ] != NULL ? '1' : '0' ,
! F_22 ( & V_2 -> V_102 ) ) ;
if ( F_19 ( ( V_2 -> V_101 [ V_84 ] == NULL ) ) )
goto V_170;
V_2 -> V_101 [ V_84 ] -> V_15 = F_16 ( V_2 , V_79 ) ;
V_2 -> V_101 [ V_84 ] -> V_167 = V_167 ;
V_2 -> V_101 [ V_84 ] -> V_106 . V_173 = F_39 () ;
F_40 ( & V_2 -> V_101 [ V_84 ] -> V_106 , V_174 ) ;
V_2 -> V_101 [ V_84 ] = NULL ;
if ( ! F_28 ( V_2 ) ) {
V_2 -> V_115 = V_175 ;
if ( V_2 -> V_30 ) {
F_33 ( V_2 ) ;
F_23 ( V_2 , L_11 , V_167 ) ;
for ( V_118 = 0 ; V_118 < V_108 ; V_118 ++ ) {
if ( V_2 -> V_101 [ V_118 ] ) {
F_41 ( F_26 ( V_2 -> V_101 [ V_118 ] ) ,
& V_2 -> V_102 ) ;
V_2 -> V_101 [ V_118 ] = NULL ;
}
}
if ( ! F_22 ( & V_2 -> V_102 ) )
F_30 ( V_2 ) ;
}
} else {
if ( ! V_2 -> V_30 )
F_29 ( V_2 ) ;
}
V_170:
F_42 ( & V_2 -> V_169 , V_47 ) ;
return F_43 ( V_168 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
enum V_176 V_115 )
{
struct V_96 * V_97 , * V_112 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_108 ; V_118 ++ ) {
if ( V_2 -> V_101 [ V_118 ] ) {
F_40 ( & V_2 -> V_101 [ V_118 ] -> V_106 ,
V_115 ) ;
V_2 -> V_101 [ V_118 ] = NULL ;
}
}
F_31 (buf, node, &vin->buf_list, list) {
F_40 ( & V_97 -> V_105 . V_106 , V_115 ) ;
F_45 ( & V_97 -> V_104 ) ;
}
}
static int F_46 ( struct V_177 * V_178 , unsigned int * V_179 ,
unsigned int * V_180 , unsigned int V_181 [] ,
struct V_182 * V_183 [] )
{
struct V_1 * V_2 = F_47 ( V_178 ) ;
if ( * V_180 )
return V_181 [ 0 ] < V_2 -> V_14 . V_184 ? - V_66 : 0 ;
* V_180 = 1 ;
V_181 [ 0 ] = V_2 -> V_14 . V_184 ;
return 0 ;
}
static int F_48 ( struct V_185 * V_105 )
{
struct V_1 * V_2 = F_47 ( V_105 -> V_177 ) ;
unsigned long V_186 = V_2 -> V_14 . V_184 ;
if ( F_49 ( V_105 , 0 ) < V_186 ) {
F_10 ( V_2 , L_12 ,
F_49 ( V_105 , 0 ) , V_186 ) ;
return - V_66 ;
}
F_50 ( V_105 , 0 , V_186 ) ;
return 0 ;
}
static void F_51 ( struct V_185 * V_105 )
{
struct V_98 * V_99 = F_52 ( V_105 ) ;
struct V_1 * V_2 = F_47 ( V_105 -> V_177 ) ;
unsigned long V_47 ;
F_38 ( & V_2 -> V_169 , V_47 ) ;
F_53 ( F_26 ( V_99 ) , & V_2 -> V_102 ) ;
if ( V_2 -> V_115 == V_175 )
F_30 ( V_2 ) ;
F_42 ( & V_2 -> V_169 , V_47 ) ;
}
static int F_54 ( struct V_177 * V_178 , unsigned int V_187 )
{
struct V_1 * V_2 = F_47 ( V_178 ) ;
struct V_188 * V_189 ;
unsigned long V_47 ;
int V_114 ;
V_189 = F_7 ( V_2 ) ;
F_6 ( V_189 , V_22 , V_190 , 1 ) ;
F_38 ( & V_2 -> V_169 , V_47 ) ;
V_2 -> V_167 = 0 ;
V_114 = F_30 ( V_2 ) ;
if ( V_114 ) {
F_44 ( V_2 , V_191 ) ;
F_6 ( V_189 , V_22 , V_190 , 0 ) ;
}
F_42 ( & V_2 -> V_169 , V_47 ) ;
return V_114 ;
}
static void F_55 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = F_47 ( V_178 ) ;
struct V_188 * V_189 ;
unsigned long V_47 ;
int V_192 = 0 ;
F_38 ( & V_2 -> V_169 , V_47 ) ;
V_2 -> V_115 = V_172 ;
while ( V_192 ++ < V_193 ) {
F_33 ( V_2 ) ;
if ( ! F_14 ( V_2 ) ) {
V_2 -> V_115 = V_171 ;
break;
}
F_42 ( & V_2 -> V_169 , V_47 ) ;
F_56 ( V_194 ) ;
F_38 ( & V_2 -> V_169 , V_47 ) ;
}
if ( V_2 -> V_115 != V_171 ) {
F_10 ( V_2 , L_13 ) ;
V_2 -> V_115 = V_171 ;
}
F_44 ( V_2 , V_195 ) ;
F_42 ( & V_2 -> V_169 , V_47 ) ;
V_189 = F_7 ( V_2 ) ;
F_6 ( V_189 , V_22 , V_190 , 0 ) ;
F_11 ( V_2 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_196 ) ;
F_59 ( & V_2 -> V_197 ) ;
}
int F_60 ( struct V_1 * V_2 , int V_164 )
{
struct V_177 * V_198 = & V_2 -> V_199 ;
int V_118 , V_114 ;
V_114 = F_61 ( V_2 -> V_200 , & V_2 -> V_197 ) ;
if ( V_114 )
return V_114 ;
F_62 ( & V_2 -> V_196 ) ;
F_63 ( & V_2 -> V_102 ) ;
F_64 ( & V_2 -> V_169 ) ;
V_2 -> V_115 = V_171 ;
for ( V_118 = 0 ; V_118 < V_108 ; V_118 ++ )
V_2 -> V_101 [ V_118 ] = NULL ;
V_198 -> type = V_201 ;
V_198 -> V_202 = V_203 | V_204 | V_205 ;
V_198 -> V_196 = & V_2 -> V_196 ;
V_198 -> V_206 = V_2 ;
V_198 -> V_207 = sizeof( struct V_96 ) ;
V_198 -> V_208 = & V_209 ;
V_198 -> V_210 = & V_211 ;
V_198 -> V_212 = V_213 ;
V_198 -> V_214 = 1 ;
V_198 -> V_200 = V_2 -> V_200 ;
V_114 = F_65 ( V_198 ) ;
if ( V_114 < 0 ) {
F_10 ( V_2 , L_14 ) ;
goto error;
}
V_114 = F_66 ( V_2 -> V_200 , V_164 , F_37 , V_215 ,
V_216 , V_2 ) ;
if ( V_114 ) {
F_10 ( V_2 , L_15 ) ;
goto error;
}
return 0 ;
error:
F_57 ( V_2 ) ;
return V_114 ;
}
