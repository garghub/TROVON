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
bool V_10 = false , V_11 = false , V_12 = false ;
switch ( V_2 -> V_13 . V_14 ) {
case V_15 :
V_6 = V_16 ;
break;
case V_17 :
V_6 = V_18 ;
break;
case V_19 :
case V_20 :
V_6 = V_21 ;
break;
case V_22 :
V_6 = V_21 | V_23 ;
break;
case V_24 :
if ( V_2 -> V_25 ) {
V_6 = V_26 ;
V_10 = true ;
} else {
V_6 = V_16 ;
}
break;
default:
V_6 = V_16 ;
break;
}
switch ( V_2 -> V_27 . V_28 ) {
case V_29 :
V_6 |= V_30 ;
V_12 = true ;
break;
case V_31 :
V_6 |= V_2 -> V_32 . type == V_33 ?
V_34 : V_35 ;
V_12 = true ;
break;
case V_36 :
V_6 |= V_37 ;
break;
case V_38 :
V_6 |= V_2 -> V_32 . type == V_33 ?
V_39 : V_40 ;
V_12 = true ;
break;
default:
break;
}
V_8 = V_41 | F_6 ( 1 ) ;
if ( ! ( V_2 -> V_32 . V_42 & V_43 ) )
V_8 |= V_44 ;
if ( ! ( V_2 -> V_32 . V_42 & V_45 ) )
V_8 |= V_46 ;
switch ( V_2 -> V_13 . V_47 ) {
case V_48 :
F_1 ( V_2 ,
F_7 ( V_2 -> V_13 . V_49 * V_2 -> V_13 . V_50 , 0x80 ) ,
V_51 ) ;
V_7 = V_52 ;
V_11 = true ;
break;
case V_53 :
V_7 = V_54 ;
V_11 = true ;
break;
case V_55 :
V_7 = 0 ;
V_11 = true ;
break;
case V_56 :
V_7 = V_57 ;
break;
case V_58 :
V_7 = 0 ;
break;
case V_59 :
if ( V_2 -> V_60 == V_61 || V_2 -> V_60 == V_62 ) {
V_7 = V_63 ;
break;
}
default:
F_8 ( V_2 , L_1 ,
V_2 -> V_13 . V_47 ) ;
return - V_64 ;
}
V_6 |= V_65 ;
if ( V_12 == V_11 )
V_6 |= V_66 ;
V_9 = V_10 ? V_67 : V_68 ;
F_1 ( V_2 , V_9 , V_69 ) ;
F_1 ( V_2 , V_9 , V_70 ) ;
F_1 ( V_2 , V_7 , V_71 ) ;
F_1 ( V_2 , V_8 , V_72 ) ;
F_1 ( V_2 , V_6 | V_73 , V_74 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , L_2 ,
V_2 -> V_25 ? L_3 : L_4 ) ;
if ( V_2 -> V_25 )
F_1 ( V_2 , V_75 , V_76 ) ;
else
F_1 ( V_2 , V_77 , V_76 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_76 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_78 ;
F_13 ( V_2 ) ;
V_78 = F_5 ( V_2 ) ;
if ( V_78 )
return V_78 ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_74 ) & ~ V_73 , V_74 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_70 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_69 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_3 ( V_2 , V_69 ) , V_69 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_79 ) & V_80 ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 )
return ( F_3 ( V_2 , V_79 ) & V_81 )
>> V_82 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , int V_83 , T_2 V_84 )
{
const struct V_85 * V_86 ;
int V_87 , V_88 ;
T_2 V_4 ;
V_86 = F_21 ( V_2 -> V_13 . V_47 ) ;
V_87 = V_2 -> V_89 . V_90 * V_86 -> V_91 ;
V_88 = V_2 -> V_89 . V_92 * V_2 -> V_13 . V_93 ;
V_4 = V_84 + V_87 + V_88 ;
if ( F_22 ( ( V_87 | V_88 | V_4 ) & V_94 ) )
return;
F_1 ( V_2 , V_4 , F_23 ( V_83 ) ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned short V_95 )
{
int V_96 ;
const struct V_97 * V_98 = NULL ;
const struct V_97 * V_99 = NULL ;
for ( V_96 = 0 ; V_96 < F_25 ( V_100 ) ; V_96 ++ ) {
V_98 = V_99 ;
V_99 = & V_100 [ V_96 ] ;
if ( V_95 < V_99 -> V_101 )
break;
}
if ( V_98 && V_99 &&
V_95 - V_98 -> V_101 < V_99 -> V_101 - V_95 )
V_99 = V_98 ;
F_1 ( V_2 , V_99 -> V_102 [ 0 ] , V_103 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 1 ] , V_104 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 2 ] , V_105 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 3 ] , V_106 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 4 ] , V_107 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 5 ] , V_108 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 6 ] , V_109 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 7 ] , V_110 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 8 ] , V_111 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 9 ] , V_112 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 10 ] , V_113 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 11 ] , V_114 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 12 ] , V_115 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 13 ] , V_116 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 14 ] , V_117 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 15 ] , V_118 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 16 ] , V_119 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 17 ] , V_120 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 18 ] , V_121 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 19 ] , V_122 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 20 ] , V_123 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 21 ] , V_124 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 22 ] , V_125 ) ;
F_1 ( V_2 , V_99 -> V_102 [ 23 ] , V_126 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_95 , V_127 ;
F_1 ( V_2 , V_2 -> V_128 . V_90 , V_129 ) ;
F_1 ( V_2 , V_2 -> V_128 . V_90 + V_2 -> V_128 . V_49 - 1 , V_130 ) ;
switch ( V_2 -> V_13 . V_14 ) {
case V_19 :
case V_20 :
case V_22 :
F_1 ( V_2 , V_2 -> V_128 . V_92 / 2 , V_131 ) ;
F_1 ( V_2 , ( V_2 -> V_128 . V_92 + V_2 -> V_128 . V_50 ) / 2 - 1 ,
V_132 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_128 . V_92 , V_131 ) ;
F_1 ( V_2 , V_2 -> V_128 . V_92 + V_2 -> V_128 . V_50 - 1 ,
V_132 ) ;
break;
}
V_127 = 0 ;
if ( V_2 -> V_128 . V_50 != V_2 -> V_89 . V_50 )
V_127 = ( 4096 * V_2 -> V_128 . V_50 ) / V_2 -> V_89 . V_50 ;
F_1 ( V_2 , V_127 , V_133 ) ;
V_95 = 0 ;
if ( V_2 -> V_128 . V_49 != V_2 -> V_89 . V_49 )
V_95 = ( 4096 * V_2 -> V_128 . V_49 ) / V_2 -> V_89 . V_49 ;
if ( V_95 > 0 && V_95 < 2048 )
V_95 = 2048 ;
F_1 ( V_2 , V_95 , V_134 ) ;
if ( V_95 < 4096 )
V_95 *= 2 ;
F_24 ( V_2 , V_95 ) ;
F_1 ( V_2 , 0 , V_135 ) ;
F_1 ( V_2 , 0 , V_136 ) ;
F_1 ( V_2 , V_2 -> V_13 . V_49 - 1 , V_137 ) ;
switch ( V_2 -> V_13 . V_14 ) {
case V_19 :
case V_20 :
case V_22 :
F_1 ( V_2 , V_2 -> V_13 . V_50 / 2 - 1 , V_138 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_13 . V_50 - 1 , V_138 ) ;
break;
}
if ( V_2 -> V_13 . V_47 == V_48 )
F_1 ( V_2 , F_7 ( V_2 -> V_13 . V_49 , 0x20 ) , V_139 ) ;
else
F_1 ( V_2 , F_7 ( V_2 -> V_13 . V_49 , 0x10 ) , V_139 ) ;
F_10 ( V_2 ,
L_5 ,
V_2 -> V_128 . V_49 , V_2 -> V_128 . V_50 , V_2 -> V_128 . V_90 ,
V_2 -> V_128 . V_92 , V_127 , V_95 , V_2 -> V_13 . V_49 , V_2 -> V_13 . V_50 ,
0 , 0 ) ;
}
void F_26 ( struct V_1 * V_2 , struct V_140 * V_141 ,
T_1 V_49 , T_1 V_50 )
{
V_141 -> V_49 = V_49 ;
V_141 -> V_50 = V_50 ;
}
static bool F_27 ( struct V_1 * V_2 , int V_83 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 ;
T_2 V_146 ;
if ( V_2 -> V_147 [ V_83 ] != NULL )
return true ;
if ( F_28 ( & V_2 -> V_148 ) )
return false ;
F_10 ( V_2 , L_6 , V_83 ) ;
V_143 = F_29 ( V_2 -> V_148 . V_149 , struct V_142 , V_150 ) ;
V_145 = & V_143 -> V_151 ;
F_30 ( F_31 ( V_145 ) ) ;
V_2 -> V_147 [ V_83 ] = V_145 ;
V_146 = F_32 ( & V_145 -> V_152 , 0 ) ;
F_20 ( V_2 , V_83 , V_146 ) ;
return true ;
}
static bool F_33 ( struct V_1 * V_2 )
{
int V_83 , V_153 ;
V_153 = V_2 -> V_25 ? V_154 : 1 ;
for ( V_83 = 0 ; V_83 < V_153 ; V_83 ++ )
if ( ! F_27 ( V_2 , V_83 ) )
return false ;
return true ;
}
static T_3 F_34 ( int V_155 , void * V_156 )
{
struct V_1 * V_2 = V_156 ;
T_1 V_157 ;
int V_83 ;
unsigned int V_158 , V_159 = 0 ;
unsigned long V_42 ;
F_35 ( & V_2 -> V_160 , V_42 ) ;
V_157 = F_16 ( V_2 ) ;
if ( ! V_157 )
goto V_161;
F_17 ( V_2 ) ;
V_159 = 1 ;
if ( V_2 -> V_162 == V_163 ) {
F_10 ( V_2 , L_7 ) ;
goto V_161;
}
if ( V_2 -> V_162 == V_164 ) {
F_10 ( V_2 , L_8 ) ;
goto V_161;
}
V_83 = F_19 ( V_2 ) ;
V_158 = V_2 -> V_158 ++ ;
F_10 ( V_2 , L_9 ,
V_158 , V_83 ,
V_83 == 0 ? 'x' : V_2 -> V_147 [ 0 ] != NULL ? '1' : '0' ,
V_83 == 1 ? 'x' : V_2 -> V_147 [ 1 ] != NULL ? '1' : '0' ,
V_83 == 2 ? 'x' : V_2 -> V_147 [ 2 ] != NULL ? '1' : '0' ,
! F_28 ( & V_2 -> V_148 ) ) ;
if ( F_22 ( ( V_2 -> V_147 [ V_83 ] == NULL ) ) )
goto V_161;
V_2 -> V_147 [ V_83 ] -> V_14 = V_2 -> V_13 . V_14 ;
V_2 -> V_147 [ V_83 ] -> V_158 = V_158 ;
V_2 -> V_147 [ V_83 ] -> V_152 . V_165 = F_36 () ;
F_37 ( & V_2 -> V_147 [ V_83 ] -> V_152 , V_166 ) ;
V_2 -> V_147 [ V_83 ] = NULL ;
if ( ! F_33 ( V_2 ) ) {
V_2 -> V_162 = V_167 ;
if ( V_2 -> V_25 ) {
F_11 ( V_2 ) ;
F_10 ( V_2 , L_10 , V_158 ) ;
}
} else {
if ( ! V_2 -> V_25 )
F_9 ( V_2 ) ;
}
V_161:
F_38 ( & V_2 -> V_160 , V_42 ) ;
return F_39 ( V_159 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
enum V_168 V_162 )
{
struct V_142 * V_143 , * V_169 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_154 ; V_96 ++ ) {
if ( V_2 -> V_147 [ V_96 ] ) {
F_37 ( & V_2 -> V_147 [ V_96 ] -> V_152 ,
V_162 ) ;
V_2 -> V_147 [ V_96 ] = NULL ;
}
}
F_41 (buf, node, &vin->buf_list, list) {
F_37 ( & V_143 -> V_151 . V_152 , V_162 ) ;
F_42 ( & V_143 -> V_150 ) ;
}
}
static int F_43 ( struct V_170 * V_171 , unsigned int * V_172 ,
unsigned int * V_173 , unsigned int V_174 [] ,
struct V_175 * V_176 [] )
{
struct V_1 * V_2 = F_44 ( V_171 ) ;
if ( * V_173 )
return V_174 [ 0 ] < V_2 -> V_13 . V_177 ? - V_64 : 0 ;
* V_173 = 1 ;
V_174 [ 0 ] = V_2 -> V_13 . V_177 ;
return 0 ;
}
static int F_45 ( struct V_178 * V_151 )
{
struct V_1 * V_2 = F_44 ( V_151 -> V_170 ) ;
unsigned long V_179 = V_2 -> V_13 . V_177 ;
if ( F_46 ( V_151 , 0 ) < V_179 ) {
F_8 ( V_2 , L_11 ,
F_46 ( V_151 , 0 ) , V_179 ) ;
return - V_64 ;
}
F_47 ( V_151 , 0 , V_179 ) ;
return 0 ;
}
static void F_48 ( struct V_178 * V_151 )
{
struct V_144 * V_145 = F_49 ( V_151 ) ;
struct V_1 * V_2 = F_44 ( V_151 -> V_170 ) ;
unsigned long V_42 ;
F_35 ( & V_2 -> V_160 , V_42 ) ;
F_50 ( F_31 ( V_145 ) , & V_2 -> V_148 ) ;
if ( V_2 -> V_162 == V_167 )
if ( F_33 ( V_2 ) )
F_9 ( V_2 ) ;
F_38 ( & V_2 -> V_160 , V_42 ) ;
}
static int F_51 ( struct V_170 * V_171 , unsigned int V_180 )
{
struct V_1 * V_2 = F_44 ( V_171 ) ;
struct V_181 * V_182 ;
unsigned long V_42 ;
int V_78 ;
V_182 = F_52 ( V_2 ) ;
F_53 ( V_182 , V_183 , V_184 , 1 ) ;
F_35 ( & V_2 -> V_160 , V_42 ) ;
V_2 -> V_162 = V_185 ;
V_2 -> V_158 = 0 ;
V_2 -> V_25 = V_180 > V_154 ;
if ( ! F_33 ( V_2 ) ) {
F_8 ( V_2 , L_12 ) ;
V_78 = - V_64 ;
goto V_186;
}
V_78 = F_12 ( V_2 ) ;
V_186:
if ( V_78 ) {
F_40 ( V_2 , V_187 ) ;
F_53 ( V_182 , V_183 , V_184 , 0 ) ;
}
F_38 ( & V_2 -> V_160 , V_42 ) ;
return V_78 ;
}
static void F_54 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_44 ( V_171 ) ;
struct V_181 * V_182 ;
unsigned long V_42 ;
int V_188 = 0 ;
F_35 ( & V_2 -> V_160 , V_42 ) ;
V_2 -> V_162 = V_164 ;
while ( V_188 ++ < V_189 ) {
F_14 ( V_2 ) ;
if ( ! F_18 ( V_2 ) ) {
V_2 -> V_162 = V_163 ;
break;
}
F_38 ( & V_2 -> V_160 , V_42 ) ;
F_55 ( V_190 ) ;
F_35 ( & V_2 -> V_160 , V_42 ) ;
}
if ( V_2 -> V_162 != V_163 ) {
F_8 ( V_2 , L_13 ) ;
V_2 -> V_162 = V_163 ;
}
F_40 ( V_2 , V_191 ) ;
F_38 ( & V_2 -> V_160 , V_42 ) ;
V_182 = F_52 ( V_2 ) ;
F_53 ( V_182 , V_183 , V_184 , 0 ) ;
F_15 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_192 ) ;
F_58 ( & V_2 -> V_193 ) ;
}
int F_59 ( struct V_1 * V_2 , int V_155 )
{
struct V_170 * V_194 = & V_2 -> V_195 ;
int V_96 , V_78 ;
V_78 = F_60 ( V_2 -> V_196 , & V_2 -> V_193 ) ;
if ( V_78 )
return V_78 ;
F_61 ( & V_2 -> V_192 ) ;
F_62 ( & V_2 -> V_148 ) ;
F_63 ( & V_2 -> V_160 ) ;
V_2 -> V_162 = V_163 ;
for ( V_96 = 0 ; V_96 < V_154 ; V_96 ++ )
V_2 -> V_147 [ V_96 ] = NULL ;
V_194 -> type = V_197 ;
V_194 -> V_198 = V_199 | V_200 | V_201 ;
V_194 -> V_192 = & V_2 -> V_192 ;
V_194 -> V_202 = V_2 ;
V_194 -> V_203 = sizeof( struct V_142 ) ;
V_194 -> V_204 = & V_205 ;
V_194 -> V_206 = & V_207 ;
V_194 -> V_208 = V_209 ;
V_194 -> V_210 = 2 ;
V_194 -> V_196 = V_2 -> V_196 ;
V_78 = F_64 ( V_194 ) ;
if ( V_78 < 0 ) {
F_8 ( V_2 , L_14 ) ;
goto error;
}
V_78 = F_65 ( V_2 -> V_196 , V_155 , F_34 , V_211 ,
V_212 , V_2 ) ;
if ( V_78 ) {
F_8 ( V_2 , L_15 ) ;
goto error;
}
return 0 ;
error:
F_56 ( V_2 ) ;
return V_78 ;
}
