static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = V_2 -> V_5 -> V_4 ;
return V_4 + V_3 * 4 ;
}
static int F_2 ( struct V_6 * V_7 ,
bool V_8 , bool V_9 , bool V_10 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
unsigned long V_12 , V_13 , V_14 ;
if ( V_8 && V_9 && V_10 )
return - V_15 ;
V_12 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_13 = F_3 ( V_2 -> V_16 + V_18 ) ;
V_14 = F_3 ( V_2 -> V_16 + V_19 ) ;
if ( V_10 )
F_4 ( V_11 , & V_14 ) ;
else
F_5 ( V_11 , & V_14 ) ;
if ( V_8 )
F_4 ( V_11 , & V_12 ) ;
else
F_5 ( V_11 , & V_12 ) ;
if ( V_9 )
F_4 ( V_11 , & V_13 ) ;
else
F_5 ( V_11 , & V_13 ) ;
F_6 ( V_12 , V_2 -> V_16 + V_17 ) ;
F_6 ( V_13 , V_2 -> V_16 + V_18 ) ;
F_6 ( V_14 , V_2 -> V_16 + V_19 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , int V_11 )
{
F_8 ( F_9 ( V_11 ) , V_2 -> V_16 + V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_21 ;
T_1 V_22 ;
F_7 ( V_2 , 0 ) ;
V_21 = F_11 ( V_2 -> V_16 + V_23 ,
V_22 , ! ( V_22 & 1 ) , 1 , 500 ) ;
if ( V_21 )
F_12 ( V_2 -> V_24 , L_1 ) ;
if ( F_13 ( V_2 -> V_16 + V_25 ) == 0 )
F_6 ( V_26 , V_2 -> V_16 + V_25 ) ;
return V_21 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_27 , int V_28 ,
T_1 V_29 )
{
struct V_30 * V_31 = V_2 -> V_11 [ 0 ] . V_32 ;
void * V_33 ;
T_2 V_34 ;
int V_21 ;
unsigned long V_35 ;
V_33 = F_15 ( NULL ,
V_28 ,
& V_34 , V_36 ) ;
if ( ! V_33 ) {
return - V_37 ;
}
F_16 ( & V_2 -> V_38 , V_35 ) ;
V_31 -> V_39 . V_40 = V_41 ;
V_31 -> V_39 . V_42 = V_43 | V_44 | V_45 | V_46 ;
V_31 -> V_39 . V_47 = V_28 / 2 ;
V_31 -> V_48 = V_34 ;
V_31 -> V_49 = V_29 ;
memcpy ( V_33 , V_27 , V_28 ) ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
F_18 ( NULL , V_28 , V_33 , V_34 ) ;
return V_21 ;
}
static void F_19 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
unsigned long V_50 ;
T_1 V_51 = F_1 ( V_2 , V_3 ) ;
V_50 = F_3 ( V_2 -> V_16 + V_51 ) ;
F_5 ( V_11 , & V_50 ) ;
F_6 ( V_50 , V_2 -> V_16 + V_51 ) ;
}
static void F_20 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
T_1 V_51 = F_1 ( V_2 , V_3 ) ;
unsigned long V_50 ;
V_50 = F_3 ( V_2 -> V_16 + V_51 ) ;
F_4 ( V_11 , & V_50 ) ;
F_6 ( V_50 , V_2 -> V_16 + V_51 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
if ( V_7 -> V_52 . V_53 )
V_7 -> V_52 . V_53 ( V_7 -> V_52 . V_54 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_30 * V_32 ;
while ( 1 ) {
V_32 = & V_7 -> V_32 [ V_7 -> V_55 ] ;
if ( V_32 -> V_39 . V_42 & V_43 )
break;
if ( V_32 -> V_39 . V_42 & V_56 )
V_7 -> V_42 = V_57 ;
V_32 -> V_39 . V_42 |= V_43 ;
V_7 -> V_55 ++ ;
V_7 -> V_55 %= V_7 -> V_58 ;
}
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_30 * V_32 ;
int V_59 , error = 0 ;
V_7 -> V_60 = 0 ;
for ( V_59 = 0 ; V_59 < V_7 -> V_58 ; V_59 ++ ) {
V_32 = & V_7 -> V_32 [ V_59 ] ;
if ( V_32 -> V_39 . V_42 & ( V_43 | V_56 ) )
error = - V_61 ;
V_7 -> V_60 += V_32 -> V_39 . V_47 ;
}
if ( error )
V_7 -> V_42 = V_57 ;
else
V_7 -> V_42 = V_62 ;
F_24 ( & V_7 -> V_52 ) ;
if ( V_7 -> V_52 . V_53 )
V_7 -> V_52 . V_53 ( V_7 -> V_52 . V_54 ) ;
}
static void F_25 ( unsigned long V_63 )
{
struct V_6 * V_7 = (struct V_6 * ) V_63 ;
if ( V_7 -> V_35 & V_64 )
F_21 ( V_7 ) ;
else
F_23 ( V_7 ) ;
}
static T_3 F_26 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned long V_67 ;
V_67 = F_3 ( V_2 -> V_16 + V_68 ) ;
F_6 ( V_67 , V_2 -> V_16 + V_68 ) ;
V_67 &= ~ 1 ;
while ( V_67 ) {
int V_11 = F_27 ( V_67 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
if ( V_7 -> V_35 & V_64 )
F_22 ( V_7 ) ;
F_28 ( & V_7 -> V_69 ) ;
F_4 ( V_11 , & V_67 ) ;
}
return V_70 ;
}
static void F_29 ( struct V_6 * V_7 ,
enum V_71 V_72 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_73 = 0 , V_74 = 0 ;
int V_75 = 0 ;
V_7 -> V_76 = 0 ;
V_7 -> V_77 = 0 ;
V_7 -> V_78 = 0 ;
switch ( V_72 ) {
case V_79 :
break;
case V_80 :
V_74 = V_2 -> V_81 -> V_82 ;
V_73 = V_2 -> V_81 -> V_83 ;
break;
case V_84 :
V_73 = V_2 -> V_81 -> V_85 ;
V_74 = V_2 -> V_81 -> V_86 ;
break;
case V_87 :
V_73 = V_2 -> V_81 -> V_88 ;
V_74 = V_2 -> V_81 -> V_89 ;
break;
case V_90 :
V_73 = V_2 -> V_81 -> V_91 ;
V_74 = V_2 -> V_81 -> V_92 ;
break;
case V_93 :
V_73 = V_2 -> V_81 -> V_94 ;
V_74 = V_2 -> V_81 -> V_95 ;
break;
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_73 = V_2 -> V_81 -> V_100 ;
V_74 = V_2 -> V_81 -> V_89 ;
break;
case V_101 :
V_73 = V_2 -> V_81 -> V_102 ;
V_74 = V_2 -> V_81 -> V_103 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
V_73 = V_2 -> V_81 -> V_110 ;
V_74 = V_2 -> V_81 -> V_92 ;
break;
case V_111 :
V_73 = V_2 -> V_81 -> V_112 ;
V_74 = V_2 -> V_81 -> V_112 ;
V_75 = V_2 -> V_81 -> V_113 ;
break;
case V_114 :
V_73 = V_2 -> V_81 -> V_110 ;
V_74 = V_2 -> V_81 -> V_92 ;
V_75 = V_2 -> V_81 -> V_113 ;
break;
case V_115 :
V_73 = V_2 -> V_81 -> V_116 ;
V_74 = V_2 -> V_81 -> V_117 ;
break;
case V_118 :
V_73 = V_2 -> V_81 -> V_119 ;
break;
case V_120 :
V_73 = V_2 -> V_81 -> V_121 ;
V_74 = V_2 -> V_81 -> V_122 ;
break;
case V_123 :
V_74 = V_2 -> V_81 -> V_124 ;
break;
default:
break;
}
V_7 -> V_76 = V_73 ;
V_7 -> V_77 = V_74 ;
V_7 -> V_78 = V_75 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_125 ;
struct V_126 * V_127 = V_2 -> V_127 ;
struct V_30 * V_31 = V_2 -> V_11 [ 0 ] . V_32 ;
int V_21 ;
unsigned long V_35 ;
if ( V_7 -> V_128 == V_129 )
V_125 = V_7 -> V_76 ;
else if ( V_7 -> V_128 == V_130 )
V_125 = V_7 -> V_78 ;
else
V_125 = V_7 -> V_77 ;
if ( V_125 < 0 )
return V_125 ;
F_31 ( V_2 -> V_24 , L_2 , V_125 ) ;
F_31 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_131 ) ;
F_31 ( V_2 -> V_24 , L_4 , V_7 -> V_132 ) ;
F_31 ( V_2 -> V_24 , L_5 , V_7 -> V_133 ) ;
F_31 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_134 [ 0 ] ) ;
F_31 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_134 [ 1 ] ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
V_127 -> V_135 . V_136 = V_125 ;
V_127 -> V_137 [ 0 ] = V_7 -> V_134 [ 1 ] ;
V_127 -> V_137 [ 1 ] = V_7 -> V_134 [ 0 ] ;
V_127 -> V_137 [ 2 ] = V_7 -> V_133 ;
V_127 -> V_137 [ 6 ] = V_7 -> V_132 ;
V_127 -> V_137 [ 7 ] = V_7 -> V_131 ;
V_31 -> V_39 . V_40 = V_138 ;
V_31 -> V_39 . V_42 = V_43 | V_44 | V_45 | V_46 ;
V_31 -> V_39 . V_47 = sizeof( * V_127 ) / 4 ;
V_31 -> V_48 = V_2 -> V_139 ;
V_31 -> V_49 = 2048 + ( sizeof( * V_127 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
return V_21 ;
}
static struct V_6 * F_32 ( struct V_140 * V_141 )
{
return F_33 ( V_141 , struct V_6 , V_141 ) ;
}
static int F_34 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_23 ) ;
V_7 -> V_42 = V_57 ;
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_142 = V_7 -> V_131 & V_143 ;
int V_144 = ( V_7 -> V_131 & V_145 ) >> 16 ;
F_36 ( V_7 -> V_146 % 32 , & V_7 -> V_134 [ 1 ] ) ;
F_36 ( V_7 -> V_147 % 32 , & V_7 -> V_134 [ 0 ] ) ;
if ( V_7 -> V_146 > 31 )
V_7 -> V_131 |= V_148 ;
if ( V_7 -> V_147 > 31 )
V_7 -> V_131 |= V_149 ;
if ( V_142 > V_144 ) {
V_7 -> V_131 &= ~ ( V_143 |
V_145 ) ;
V_7 -> V_131 |= V_144 ;
V_7 -> V_131 |= V_142 << 16 ;
F_37 ( V_7 -> V_134 [ 0 ] , V_7 -> V_134 [ 1 ] ) ;
}
if ( V_7 -> V_150 >= V_2 -> V_151 &&
V_7 -> V_150 <= V_2 -> V_152 )
V_7 -> V_131 |= V_153 ;
if ( V_7 -> V_154 >= V_2 -> V_151 &&
V_7 -> V_154 <= V_2 -> V_152 )
V_7 -> V_131 |= V_155 ;
V_7 -> V_131 |= V_156 ;
}
static int F_38 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
int V_21 ;
F_34 ( V_141 ) ;
V_7 -> V_134 [ 0 ] = 0 ;
V_7 -> V_134 [ 1 ] = 0 ;
V_7 -> V_132 = 0 ;
V_7 -> V_133 = 0 ;
if ( V_7 -> V_146 ) {
if ( V_7 -> V_146 >= V_7 -> V_2 -> V_5 -> V_157 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_146 ) ;
}
if ( V_7 -> V_147 ) {
if ( V_7 -> V_147 >= V_7 -> V_2 -> V_5 -> V_157 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_147 ) ;
}
switch ( V_7 -> V_72 ) {
case V_80 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_79 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_29 ( V_7 , V_7 -> V_72 ) ;
if ( ( V_7 -> V_72 != V_79 ) &&
( V_7 -> V_72 != V_80 ) ) {
if ( V_7 -> V_147 ) {
if ( V_7 -> V_72 == V_114 ||
V_7 -> V_72 == V_111 )
F_35 ( V_7 ) ;
} else
F_5 ( V_7 -> V_146 , V_7 -> V_134 ) ;
V_7 -> V_132 = V_7 -> V_154 ;
V_7 -> V_133 = V_7 -> V_150 ;
} else {
V_7 -> V_131 = 0 ;
}
V_21 = F_30 ( V_7 ) ;
return V_21 ;
}
static int F_39 ( struct V_6 * V_7 ,
unsigned int V_158 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_158 < V_159
|| V_158 > V_160 ) {
return - V_15 ;
}
F_6 ( V_158 , V_2 -> V_16 + V_161 + 4 * V_11 ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_162 ;
V_7 -> V_32 = F_41 ( NULL , V_163 , & V_7 -> V_164 ,
V_36 ) ;
if ( ! V_7 -> V_32 ) {
V_21 = - V_37 ;
goto V_165;
}
V_2 -> V_166 [ V_11 ] . V_167 = V_7 -> V_164 ;
V_2 -> V_166 [ V_11 ] . V_168 = V_7 -> V_164 ;
F_39 ( V_7 , V_169 ) ;
return 0 ;
V_165:
return V_21 ;
}
static T_4 F_42 ( struct V_170 * V_171 )
{
unsigned long V_35 ;
struct V_6 * V_7 = F_32 ( V_171 -> V_141 ) ;
T_4 V_172 ;
F_16 ( & V_7 -> V_173 , V_35 ) ;
V_172 = F_43 ( V_171 ) ;
F_17 ( & V_7 -> V_173 , V_35 ) ;
return V_172 ;
}
static int F_44 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_174 * V_63 = V_141 -> V_175 ;
int V_176 , V_21 ;
if ( ! V_63 )
return - V_15 ;
switch ( V_63 -> V_158 ) {
case V_177 :
V_176 = 3 ;
break;
case V_178 :
V_176 = 2 ;
break;
case V_179 :
default:
V_176 = 1 ;
break;
}
V_7 -> V_72 = V_63 -> V_72 ;
V_7 -> V_146 = V_63 -> V_180 ;
V_7 -> V_147 = V_63 -> V_181 ;
V_21 = F_45 ( V_7 -> V_2 -> V_182 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_45 ( V_7 -> V_2 -> V_183 ) ;
if ( V_21 )
goto V_184;
V_21 = F_40 ( V_7 ) ;
if ( V_21 )
goto V_185;
V_21 = F_39 ( V_7 , V_176 ) ;
if ( V_21 )
goto V_185;
F_46 ( & V_7 -> V_52 , V_141 ) ;
V_7 -> V_52 . V_186 = F_42 ;
V_7 -> V_52 . V_35 = V_187 ;
return 0 ;
V_185:
F_47 ( V_7 -> V_2 -> V_183 ) ;
V_184:
F_47 ( V_7 -> V_2 -> V_182 ) ;
return V_21 ;
}
static void F_48 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_34 ( V_141 ) ;
if ( V_7 -> V_146 )
F_20 ( V_7 , V_7 -> V_146 ) ;
if ( V_7 -> V_147 )
F_20 ( V_7 , V_7 -> V_147 ) ;
V_7 -> V_146 = 0 ;
V_7 -> V_147 = 0 ;
F_39 ( V_7 , 0 ) ;
F_18 ( NULL , V_163 , V_7 -> V_32 , V_7 -> V_164 ) ;
F_47 ( V_2 -> V_182 ) ;
F_47 ( V_2 -> V_183 ) ;
}
static struct V_170 * F_49 (
struct V_140 * V_141 , struct V_188 * V_189 ,
unsigned int V_190 , enum V_191 V_128 ,
unsigned long V_35 , void * V_127 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_59 , V_47 ;
int V_11 = V_7 -> V_11 ;
struct V_188 * V_192 ;
if ( V_7 -> V_42 == V_193 )
return NULL ;
V_7 -> V_42 = V_193 ;
V_7 -> V_35 = 0 ;
V_7 -> V_55 = 0 ;
F_31 ( V_2 -> V_24 , L_8 ,
V_190 , V_11 ) ;
V_7 -> V_128 = V_128 ;
V_21 = F_30 ( V_7 ) ;
if ( V_21 )
goto V_194;
if ( V_190 > V_195 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_190 , V_195 ) ;
V_21 = - V_15 ;
goto V_194;
}
V_7 -> V_196 = 0 ;
F_50 (sgl, sg, sg_len, i) {
struct V_30 * V_32 = & V_7 -> V_32 [ V_59 ] ;
int V_197 ;
V_32 -> V_48 = V_192 -> V_198 ;
V_47 = F_51 ( V_192 ) ;
if ( V_47 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_47 , 0xffff ) ;
V_21 = - V_15 ;
goto V_194;
}
V_32 -> V_39 . V_47 = V_47 ;
V_7 -> V_196 += V_47 ;
if ( V_7 -> V_199 > V_200 ) {
V_21 = - V_15 ;
goto V_194;
}
switch ( V_7 -> V_199 ) {
case V_200 :
V_32 -> V_39 . V_40 = 0 ;
if ( V_47 & 3 || V_192 -> V_198 & 3 )
return NULL ;
break;
case V_201 :
V_32 -> V_39 . V_40 = 2 ;
if ( V_47 & 1 || V_192 -> V_198 & 1 )
return NULL ;
break;
case V_202 :
V_32 -> V_39 . V_40 = 1 ;
break;
default:
return NULL ;
}
V_197 = V_43 | V_46 | V_203 ;
if ( V_59 + 1 == V_190 ) {
V_197 |= V_44 ;
V_197 |= V_204 ;
V_197 &= ~ V_203 ;
}
F_31 ( V_2 -> V_24 , L_11 ,
V_59 , V_47 , ( V_205 ) V_192 -> V_198 ,
V_197 & V_45 ? L_12 : L_13 ,
V_197 & V_44 ? L_14 : L_13 ) ;
V_32 -> V_39 . V_42 = V_197 ;
}
V_7 -> V_58 = V_190 ;
V_2 -> V_166 [ V_11 ] . V_168 = V_7 -> V_164 ;
return & V_7 -> V_52 ;
V_194:
V_7 -> V_42 = V_57 ;
return NULL ;
}
static struct V_170 * F_52 (
struct V_140 * V_141 , T_2 V_206 , T_5 V_207 ,
T_5 V_208 , enum V_191 V_128 ,
unsigned long V_35 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_209 = V_207 / V_208 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_59 = 0 , V_27 = 0 ;
F_31 ( V_2 -> V_24 , L_15 , V_210 , V_11 ) ;
if ( V_7 -> V_42 == V_193 )
return NULL ;
V_7 -> V_42 = V_193 ;
V_7 -> V_55 = 0 ;
V_7 -> V_208 = V_208 ;
V_7 -> V_35 |= V_64 ;
V_7 -> V_128 = V_128 ;
V_21 = F_30 ( V_7 ) ;
if ( V_21 )
goto V_194;
if ( V_209 > V_195 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_209 , V_195 ) ;
goto V_194;
}
if ( V_208 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_208 , 0xffff ) ;
goto V_194;
}
while ( V_27 < V_207 ) {
struct V_30 * V_32 = & V_7 -> V_32 [ V_59 ] ;
int V_197 ;
V_32 -> V_48 = V_206 ;
V_32 -> V_39 . V_47 = V_208 ;
if ( V_7 -> V_199 > V_200 )
goto V_194;
if ( V_7 -> V_199 == V_200 )
V_32 -> V_39 . V_40 = 0 ;
else
V_32 -> V_39 . V_40 = V_7 -> V_199 ;
V_197 = V_43 | V_46 | V_203 | V_44 ;
if ( V_59 + 1 == V_209 )
V_197 |= V_45 ;
F_31 ( V_2 -> V_24 , L_11 ,
V_59 , V_208 , ( V_205 ) V_206 ,
V_197 & V_45 ? L_12 : L_13 ,
V_197 & V_44 ? L_14 : L_13 ) ;
V_32 -> V_39 . V_42 = V_197 ;
V_206 += V_208 ;
V_27 += V_208 ;
V_59 ++ ;
}
V_7 -> V_58 = V_209 ;
V_2 -> V_166 [ V_11 ] . V_168 = V_7 -> V_164 ;
return & V_7 -> V_52 ;
V_194:
V_7 -> V_42 = V_57 ;
return NULL ;
}
static int F_53 ( struct V_140 * V_141 ,
struct V_211 * V_212 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
if ( V_212 -> V_128 == V_129 ) {
V_7 -> V_154 = V_212 -> V_213 ;
V_7 -> V_131 = V_212 -> V_214 *
V_212 -> V_215 ;
V_7 -> V_199 = V_212 -> V_215 ;
} else if ( V_212 -> V_128 == V_130 ) {
V_7 -> V_150 = V_212 -> V_213 ;
V_7 -> V_154 = V_212 -> V_216 ;
V_7 -> V_131 = V_212 -> V_214 &
V_143 ;
V_7 -> V_131 |= ( V_212 -> V_217 << 16 ) &
V_145 ;
V_7 -> V_199 = V_212 -> V_218 ;
} else {
V_7 -> V_154 = V_212 -> V_216 ;
V_7 -> V_131 = V_212 -> V_217 *
V_212 -> V_218 ;
V_7 -> V_199 = V_212 -> V_218 ;
}
V_7 -> V_128 = V_212 -> V_128 ;
return F_38 ( V_141 ) ;
}
static enum V_219 F_54 ( struct V_140 * V_141 ,
T_4 V_172 ,
struct V_220 * V_221 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
T_1 V_222 ;
if ( V_7 -> V_35 & V_64 )
V_222 = ( V_7 -> V_58 - V_7 -> V_55 ) * V_7 -> V_208 ;
else
V_222 = V_7 -> V_196 - V_7 -> V_60 ;
F_55 ( V_221 , V_141 -> V_223 , V_141 -> V_172 ,
V_222 ) ;
return V_7 -> V_42 ;
}
static void F_56 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_42 == V_193 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
const struct V_224 * V_225 )
{
T_6 * V_226 = ( T_1 * ) V_225 ;
T_6 * V_227 = ( T_1 * ) V_2 -> V_81 ;
int V_59 ;
if ( ! V_2 -> V_228 )
V_2 -> V_228 = V_229 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_228 ; V_59 ++ )
if ( V_226 [ V_59 ] > 0 )
V_227 [ V_59 ] = V_226 [ V_59 ] ;
}
static void F_58 ( const struct V_230 * V_231 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
const struct V_232 * V_233 ;
const struct V_224 * V_225 ;
unsigned short * V_234 ;
if ( ! V_231 ) {
F_59 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_231 -> V_28 < sizeof( * V_233 ) )
goto V_235;
V_233 = (struct V_232 * ) V_231 -> V_63 ;
if ( V_233 -> V_236 != V_237 )
goto V_235;
if ( V_233 -> V_238 + V_233 -> V_239 > V_231 -> V_28 )
goto V_235;
switch ( V_233 -> V_240 ) {
case 1 :
V_2 -> V_228 = V_229 ;
break;
case 2 :
V_2 -> V_228 = V_241 ;
break;
case 3 :
V_2 -> V_228 = V_242 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_235;
}
V_225 = ( void * ) V_233 + V_233 -> V_243 ;
V_234 = ( void * ) V_233 + V_233 -> V_238 ;
F_45 ( V_2 -> V_182 ) ;
F_45 ( V_2 -> V_183 ) ;
F_14 ( V_2 , V_234 ,
V_233 -> V_239 ,
V_225 -> V_244 ) ;
F_47 ( V_2 -> V_182 ) ;
F_47 ( V_2 -> V_183 ) ;
F_57 ( V_2 , V_225 ) ;
F_59 ( V_2 -> V_24 , L_19 ,
V_233 -> V_240 ,
V_233 -> V_245 ) ;
V_235:
F_60 ( V_231 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = V_2 -> V_24 -> V_248 ;
struct V_246 * V_249 = F_62 ( V_247 , L_20 , 0 ) ;
struct V_250 * V_251 ;
struct V_252 * V_253 ;
char V_254 [] = L_21 ;
T_1 V_22 , V_50 , V_255 , V_256 , V_59 ;
int V_21 = 0 ;
if ( F_63 ( V_247 ) || F_63 ( V_249 ) )
goto V_165;
V_251 = F_64 ( V_247 , V_254 , NULL ) ;
V_256 = V_251 ? ( V_251 -> V_257 / sizeof( T_1 ) ) : 0 ;
if ( ! V_256 ) {
F_31 ( V_2 -> V_24 , L_22 ) ;
goto V_165;
} else if ( V_256 % V_258 ) {
F_12 ( V_2 -> V_24 , L_23 ,
V_254 , V_258 ) ;
V_21 = - V_15 ;
goto V_165;
}
V_253 = F_65 ( V_249 ) ;
if ( F_63 ( V_253 ) ) {
F_12 ( V_2 -> V_24 , L_24 ) ;
V_21 = F_66 ( V_253 ) ;
goto V_165;
}
for ( V_59 = 0 ; V_59 < V_256 ; V_59 += V_258 ) {
V_21 = F_67 ( V_247 , V_254 , V_59 , & V_22 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_254 , V_59 ) ;
goto V_165;
}
V_21 = F_67 ( V_247 , V_254 , V_59 + 1 , & V_255 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_254 , V_59 + 1 ) ;
goto V_165;
}
V_21 = F_67 ( V_247 , V_254 , V_59 + 2 , & V_50 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_254 , V_59 + 2 ) ;
goto V_165;
}
F_68 ( V_253 , V_22 , F_9 ( V_255 ) , V_50 << V_255 ) ;
}
V_165:
if ( ! F_63 ( V_249 ) )
F_69 ( V_249 ) ;
return V_21 ;
}
static int F_70 ( struct V_1 * V_2 ,
const char * V_259 )
{
int V_21 ;
V_21 = F_71 ( V_260 ,
V_261 , V_259 , V_2 -> V_24 ,
V_36 , V_2 , F_58 ) ;
return V_21 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_59 , V_21 ;
T_2 V_262 ;
V_21 = F_45 ( V_2 -> V_182 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_45 ( V_2 -> V_183 ) ;
if ( V_21 )
goto V_184;
F_6 ( 0 , V_2 -> V_16 + V_263 ) ;
V_2 -> V_166 = F_15 ( NULL ,
V_264 * sizeof ( struct V_265 ) +
sizeof( struct V_126 ) ,
& V_262 , V_36 ) ;
if ( ! V_2 -> V_166 ) {
V_21 = - V_37 ;
goto V_266;
}
V_2 -> V_127 = ( void * ) V_2 -> V_166 +
V_264 * sizeof ( struct V_265 ) ;
V_2 -> V_139 = V_262 +
V_264 * sizeof ( struct V_265 ) ;
memset ( V_2 -> V_166 , 0 ,
V_264 * sizeof ( struct V_265 ) ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_5 -> V_157 ; V_59 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_59 ) ) ;
for ( V_59 = 0 ; V_59 < V_264 ; V_59 ++ )
F_6 ( 0 , V_2 -> V_16 + V_161 + V_59 * 4 ) ;
V_21 = F_40 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_266;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_267 ) ;
F_6 ( 0 , V_2 -> V_16 + V_25 ) ;
F_6 ( V_262 , V_2 -> V_16 + V_263 ) ;
F_39 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_47 ( V_2 -> V_182 ) ;
F_47 ( V_2 -> V_183 ) ;
return 0 ;
V_266:
F_47 ( V_2 -> V_183 ) ;
V_184:
F_47 ( V_2 -> V_182 ) ;
F_12 ( V_2 -> V_24 , L_26 , V_21 ) ;
return V_21 ;
}
static bool F_73 ( struct V_140 * V_141 , void * V_268 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_174 * V_63 = V_268 ;
if ( ! F_74 ( V_141 ) )
return false ;
V_7 -> V_63 = * V_63 ;
V_141 -> V_175 = & V_7 -> V_63 ;
return true ;
}
static struct V_140 * F_75 ( struct V_269 * V_270 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = V_272 -> V_273 ;
T_7 V_274 = V_2 -> V_275 . V_276 ;
struct V_174 V_63 ;
if ( V_270 -> V_277 != 3 )
return NULL ;
V_63 . V_180 = V_270 -> args [ 0 ] ;
V_63 . V_72 = V_270 -> args [ 1 ] ;
V_63 . V_158 = V_270 -> args [ 2 ] ;
V_63 . V_181 = 0 ;
return F_76 ( V_274 , F_73 , & V_63 ) ;
}
static int F_77 ( struct V_278 * V_279 )
{
const struct V_280 * V_281 =
F_78 ( V_282 , & V_279 -> V_24 ) ;
struct V_246 * V_247 = V_279 -> V_24 . V_248 ;
struct V_246 * V_283 ;
const char * V_259 ;
int V_21 ;
int V_65 ;
struct V_284 * V_285 ;
struct V_284 V_286 ;
struct V_287 * V_288 = F_79 ( & V_279 -> V_24 ) ;
int V_59 ;
struct V_1 * V_2 ;
T_6 * V_227 ;
const struct V_289 * V_5 = NULL ;
if ( V_281 )
V_5 = V_281 -> V_63 ;
else if ( V_279 -> V_290 )
V_5 = ( void * ) V_279 -> V_290 -> V_291 ;
if ( ! V_5 ) {
F_12 ( & V_279 -> V_24 , L_27 ) ;
return - V_15 ;
}
V_21 = F_80 ( & V_279 -> V_24 , F_81 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_82 ( & V_279 -> V_24 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
F_83 ( & V_2 -> V_38 ) ;
V_2 -> V_24 = & V_279 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_65 = F_84 ( V_279 , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
V_285 = F_85 ( V_279 , V_292 , 0 ) ;
V_2 -> V_16 = F_86 ( & V_279 -> V_24 , V_285 ) ;
if ( F_63 ( V_2 -> V_16 ) )
return F_66 ( V_2 -> V_16 ) ;
V_2 -> V_182 = F_87 ( & V_279 -> V_24 , L_28 ) ;
if ( F_63 ( V_2 -> V_182 ) )
return F_66 ( V_2 -> V_182 ) ;
V_2 -> V_183 = F_87 ( & V_279 -> V_24 , L_29 ) ;
if ( F_63 ( V_2 -> V_183 ) )
return F_66 ( V_2 -> V_183 ) ;
F_88 ( V_2 -> V_182 ) ;
F_88 ( V_2 -> V_183 ) ;
V_21 = F_89 ( & V_279 -> V_24 , V_65 , F_26 , 0 , L_30 ,
V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_81 = F_90 ( sizeof( * V_2 -> V_81 ) , V_36 ) ;
if ( ! V_2 -> V_81 )
return - V_37 ;
V_227 = ( T_6 * ) V_2 -> V_81 ;
for ( V_59 = 0 ; V_59 < V_229 ; V_59 ++ )
V_227 [ V_59 ] = - V_15 ;
F_91 ( V_293 , V_2 -> V_275 . V_276 ) ;
F_91 ( V_294 , V_2 -> V_275 . V_276 ) ;
F_92 ( & V_2 -> V_275 . V_295 ) ;
for ( V_59 = 0 ; V_59 < V_264 ; V_59 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_59 ] ;
V_7 -> V_2 = V_2 ;
F_83 ( & V_7 -> V_173 ) ;
V_7 -> V_141 . V_296 = & V_2 -> V_275 ;
F_93 ( & V_7 -> V_141 ) ;
V_7 -> V_11 = V_59 ;
F_94 ( & V_7 -> V_69 , F_25 ,
( unsigned long ) V_7 ) ;
if ( V_59 )
F_95 ( & V_7 -> V_141 . V_246 ,
& V_2 -> V_275 . V_295 ) ;
}
V_21 = F_72 ( V_2 ) ;
if ( V_21 )
goto V_297;
V_21 = F_61 ( V_2 ) ;
if ( V_21 )
goto V_297;
if ( V_2 -> V_5 -> V_81 )
F_57 ( V_2 , V_2 -> V_5 -> V_81 ) ;
if ( V_288 && V_288 -> V_81 )
F_57 ( V_2 , V_288 -> V_81 ) ;
if ( V_288 ) {
V_21 = F_70 ( V_2 , V_288 -> V_259 ) ;
if ( V_21 )
F_96 ( & V_279 -> V_24 , L_31 ) ;
} else {
V_21 = F_97 ( V_247 , L_32 ,
& V_259 ) ;
if ( V_21 )
F_96 ( & V_279 -> V_24 , L_33 ) ;
else {
V_21 = F_70 ( V_2 , V_259 ) ;
if ( V_21 )
F_96 ( & V_279 -> V_24 , L_34 ) ;
}
}
V_2 -> V_275 . V_24 = & V_279 -> V_24 ;
V_2 -> V_275 . V_298 = F_44 ;
V_2 -> V_275 . V_299 = F_48 ;
V_2 -> V_275 . V_300 = F_54 ;
V_2 -> V_275 . V_301 = F_49 ;
V_2 -> V_275 . V_302 = F_52 ;
V_2 -> V_275 . V_303 = F_53 ;
V_2 -> V_275 . V_304 = F_34 ;
V_2 -> V_275 . V_305 = F_9 ( V_200 ) ;
V_2 -> V_275 . V_306 = F_9 ( V_200 ) ;
V_2 -> V_275 . V_307 = F_9 ( V_129 ) | F_9 ( V_308 ) ;
V_2 -> V_275 . V_309 = V_310 ;
V_2 -> V_275 . V_311 = F_56 ;
V_2 -> V_275 . V_24 -> V_312 = & V_2 -> V_312 ;
F_98 ( V_2 -> V_275 . V_24 , 65535 ) ;
F_99 ( V_279 , V_2 ) ;
V_21 = F_100 ( & V_2 -> V_275 ) ;
if ( V_21 ) {
F_12 ( & V_279 -> V_24 , L_35 ) ;
goto V_297;
}
if ( V_247 ) {
V_21 = F_101 ( V_247 , F_75 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_279 -> V_24 , L_36 ) ;
goto V_313;
}
V_283 = F_102 ( NULL , NULL , L_37 ) ;
V_21 = F_103 ( V_283 , 0 , & V_286 ) ;
if ( ! V_21 ) {
V_2 -> V_151 = V_286 . V_314 ;
V_2 -> V_152 = V_286 . V_315 ;
}
F_69 ( V_283 ) ;
}
return 0 ;
V_313:
F_104 ( & V_2 -> V_275 ) ;
V_297:
F_105 ( V_2 -> V_81 ) ;
return V_21 ;
}
static int F_106 ( struct V_278 * V_279 )
{
struct V_1 * V_2 = F_107 ( V_279 ) ;
int V_59 ;
F_108 ( & V_279 -> V_24 , V_2 -> V_65 , V_2 ) ;
F_104 ( & V_2 -> V_275 ) ;
F_105 ( V_2 -> V_81 ) ;
for ( V_59 = 0 ; V_59 < V_264 ; V_59 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_59 ] ;
F_109 ( & V_7 -> V_69 ) ;
}
F_99 ( V_279 , NULL ) ;
return 0 ;
}
