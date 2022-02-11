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
unsigned long V_22 = 500 ;
F_7 ( V_2 , 0 ) ;
while ( ! ( V_21 = F_3 ( V_2 -> V_16 + V_23 ) & 1 ) ) {
if ( V_22 -- <= 0 )
break;
F_11 ( 1 ) ;
}
if ( V_21 ) {
F_6 ( V_21 , V_2 -> V_16 + V_23 ) ;
} else {
F_12 ( V_2 -> V_24 , L_1 ) ;
}
if ( F_13 ( V_2 -> V_16 + V_25 ) == 0 )
F_6 ( V_26 , V_2 -> V_16 + V_25 ) ;
return V_21 ? 0 : - V_27 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_28 , int V_29 ,
T_1 V_30 )
{
struct V_31 * V_32 = V_2 -> V_11 [ 0 ] . V_33 ;
void * V_34 ;
T_2 V_35 ;
int V_21 ;
unsigned long V_36 ;
V_34 = F_15 ( NULL ,
V_29 ,
& V_35 , V_37 ) ;
if ( ! V_34 ) {
return - V_38 ;
}
F_16 ( & V_2 -> V_39 , V_36 ) ;
V_32 -> V_40 . V_41 = V_42 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = V_29 / 2 ;
V_32 -> V_49 = V_35 ;
V_32 -> V_50 = V_30 ;
memcpy ( V_34 , V_28 , V_29 ) ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_39 , V_36 ) ;
F_18 ( NULL , V_29 , V_34 , V_35 ) ;
return V_21 ;
}
static void F_19 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
unsigned long V_51 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
V_51 = F_3 ( V_2 -> V_16 + V_52 ) ;
F_5 ( V_11 , & V_51 ) ;
F_6 ( V_51 , V_2 -> V_16 + V_52 ) ;
}
static void F_20 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
unsigned long V_51 ;
V_51 = F_3 ( V_2 -> V_16 + V_52 ) ;
F_4 ( V_11 , & V_51 ) ;
F_6 ( V_51 , V_2 -> V_16 + V_52 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
if ( V_7 -> V_53 . V_54 )
V_7 -> V_53 . V_54 ( V_7 -> V_53 . V_55 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_31 * V_33 ;
while ( 1 ) {
V_33 = & V_7 -> V_33 [ V_7 -> V_56 ] ;
if ( V_33 -> V_40 . V_43 & V_44 )
break;
if ( V_33 -> V_40 . V_43 & V_57 )
V_7 -> V_43 = V_58 ;
V_33 -> V_40 . V_43 |= V_44 ;
V_7 -> V_56 ++ ;
V_7 -> V_56 %= V_7 -> V_59 ;
}
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_31 * V_33 ;
int V_60 , error = 0 ;
V_7 -> V_61 = 0 ;
for ( V_60 = 0 ; V_60 < V_7 -> V_59 ; V_60 ++ ) {
V_33 = & V_7 -> V_33 [ V_60 ] ;
if ( V_33 -> V_40 . V_43 & ( V_44 | V_57 ) )
error = - V_62 ;
V_7 -> V_61 += V_33 -> V_40 . V_48 ;
}
if ( error )
V_7 -> V_43 = V_58 ;
else
V_7 -> V_43 = V_63 ;
F_24 ( & V_7 -> V_53 ) ;
if ( V_7 -> V_53 . V_54 )
V_7 -> V_53 . V_54 ( V_7 -> V_53 . V_55 ) ;
}
static void F_25 ( unsigned long V_64 )
{
struct V_6 * V_7 = (struct V_6 * ) V_64 ;
if ( V_7 -> V_36 & V_65 )
F_21 ( V_7 ) ;
else
F_23 ( V_7 ) ;
}
static T_3 F_26 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned long V_68 ;
V_68 = F_3 ( V_2 -> V_16 + V_23 ) ;
V_68 &= ~ 1 ;
F_6 ( V_68 , V_2 -> V_16 + V_23 ) ;
while ( V_68 ) {
int V_11 = F_27 ( V_68 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
if ( V_7 -> V_36 & V_65 )
F_22 ( V_7 ) ;
F_28 ( & V_7 -> V_69 ) ;
F_4 ( V_11 , & V_68 ) ;
}
return V_70 ;
}
static void F_29 ( struct V_6 * V_7 ,
enum V_71 V_72 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_73 = 0 , V_74 = 0 ;
int V_75 = 0 , V_76 = 0 ;
V_7 -> V_77 = 0 ;
V_7 -> V_78 = 0 ;
V_7 -> V_79 = 0 ;
switch ( V_72 ) {
case V_80 :
V_76 = V_2 -> V_81 -> V_82 ;
break;
case V_83 :
V_74 = V_2 -> V_81 -> V_84 ;
V_73 = V_2 -> V_81 -> V_85 ;
break;
case V_86 :
V_73 = V_2 -> V_81 -> V_87 ;
V_74 = V_2 -> V_81 -> V_88 ;
break;
case V_89 :
V_73 = V_2 -> V_81 -> V_90 ;
V_74 = V_2 -> V_81 -> V_91 ;
break;
case V_92 :
V_73 = V_2 -> V_81 -> V_93 ;
V_74 = V_2 -> V_81 -> V_94 ;
break;
case V_95 :
V_73 = V_2 -> V_81 -> V_96 ;
V_74 = V_2 -> V_81 -> V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_73 = V_2 -> V_81 -> V_102 ;
V_74 = V_2 -> V_81 -> V_91 ;
break;
case V_103 :
V_73 = V_2 -> V_81 -> V_104 ;
V_74 = V_2 -> V_81 -> V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_73 = V_2 -> V_81 -> V_112 ;
V_74 = V_2 -> V_81 -> V_94 ;
break;
case V_113 :
V_73 = V_2 -> V_81 -> V_114 ;
V_74 = V_2 -> V_81 -> V_114 ;
V_75 = V_2 -> V_81 -> V_115 ;
break;
case V_116 :
V_73 = V_2 -> V_81 -> V_112 ;
V_74 = V_2 -> V_81 -> V_94 ;
V_75 = V_2 -> V_81 -> V_115 ;
break;
case V_117 :
V_73 = V_2 -> V_81 -> V_118 ;
V_74 = V_2 -> V_81 -> V_119 ;
break;
case V_120 :
V_73 = V_2 -> V_81 -> V_121 ;
break;
case V_122 :
V_73 = V_2 -> V_81 -> V_123 ;
V_74 = V_2 -> V_81 -> V_124 ;
break;
case V_125 :
V_74 = V_2 -> V_81 -> V_126 ;
break;
default:
break;
}
V_7 -> V_77 = V_73 ;
V_7 -> V_78 = V_74 ;
V_7 -> V_79 = V_75 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_127 ;
struct V_128 * V_129 = V_2 -> V_129 ;
struct V_31 * V_32 = V_2 -> V_11 [ 0 ] . V_33 ;
int V_21 ;
unsigned long V_36 ;
if ( V_7 -> V_130 == V_131 )
V_127 = V_7 -> V_77 ;
else if ( V_7 -> V_130 == V_132 )
V_127 = V_7 -> V_79 ;
else
V_127 = V_7 -> V_78 ;
if ( V_127 < 0 )
return V_127 ;
F_31 ( V_2 -> V_24 , L_2 , V_127 ) ;
F_31 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_133 ) ;
F_31 ( V_2 -> V_24 , L_4 , V_7 -> V_134 ) ;
F_31 ( V_2 -> V_24 , L_5 , V_7 -> V_135 ) ;
F_31 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_136 [ 0 ] ) ;
F_31 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_136 [ 1 ] ) ;
F_16 ( & V_2 -> V_39 , V_36 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> V_137 . V_138 = V_127 ;
V_129 -> V_139 [ 0 ] = V_7 -> V_136 [ 1 ] ;
V_129 -> V_139 [ 1 ] = V_7 -> V_136 [ 0 ] ;
V_129 -> V_139 [ 2 ] = V_7 -> V_135 ;
V_129 -> V_139 [ 6 ] = V_7 -> V_134 ;
V_129 -> V_139 [ 7 ] = V_7 -> V_133 ;
V_32 -> V_40 . V_41 = V_140 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = sizeof( * V_129 ) / 4 ;
V_32 -> V_49 = V_2 -> V_141 ;
V_32 -> V_50 = 2048 + ( sizeof( * V_129 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_39 , V_36 ) ;
return V_21 ;
}
static struct V_6 * F_32 ( struct V_142 * V_143 )
{
return F_33 ( V_143 , struct V_6 , V_143 ) ;
}
static int F_34 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_144 ) ;
V_7 -> V_43 = V_58 ;
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_145 = V_7 -> V_133 & V_146 ;
int V_147 = ( V_7 -> V_133 & V_148 ) >> 16 ;
F_36 ( V_7 -> V_149 % 32 , & V_7 -> V_136 [ 1 ] ) ;
F_36 ( V_7 -> V_150 % 32 , & V_7 -> V_136 [ 0 ] ) ;
if ( V_7 -> V_149 > 31 )
V_7 -> V_133 |= V_151 ;
if ( V_7 -> V_150 > 31 )
V_7 -> V_133 |= V_152 ;
if ( V_145 > V_147 ) {
V_7 -> V_133 &= ~ ( V_146 |
V_148 ) ;
V_7 -> V_133 |= V_147 ;
V_7 -> V_133 |= V_145 << 16 ;
F_37 ( V_7 -> V_136 [ 0 ] , V_7 -> V_136 [ 1 ] ) ;
}
if ( V_7 -> V_153 >= V_2 -> V_154 &&
V_7 -> V_153 <= V_2 -> V_155 )
V_7 -> V_133 |= V_156 ;
if ( V_7 -> V_157 >= V_2 -> V_154 &&
V_7 -> V_157 <= V_2 -> V_155 )
V_7 -> V_133 |= V_158 ;
V_7 -> V_133 |= V_159 ;
}
static int F_38 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
int V_21 ;
F_34 ( V_143 ) ;
V_7 -> V_136 [ 0 ] = 0 ;
V_7 -> V_136 [ 1 ] = 0 ;
V_7 -> V_134 = 0 ;
V_7 -> V_135 = 0 ;
if ( V_7 -> V_149 ) {
if ( V_7 -> V_149 >= V_7 -> V_2 -> V_5 -> V_160 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_149 ) ;
}
if ( V_7 -> V_150 ) {
if ( V_7 -> V_150 >= V_7 -> V_2 -> V_5 -> V_160 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_150 ) ;
}
switch ( V_7 -> V_72 ) {
case V_83 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_80 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_29 ( V_7 , V_7 -> V_72 ) ;
if ( ( V_7 -> V_72 != V_80 ) &&
( V_7 -> V_72 != V_83 ) ) {
if ( V_7 -> V_150 ) {
if ( V_7 -> V_72 == V_116 ||
V_7 -> V_72 == V_113 )
F_35 ( V_7 ) ;
} else
F_5 ( V_7 -> V_149 , V_7 -> V_136 ) ;
V_7 -> V_133 |= V_7 -> V_133 ;
V_7 -> V_134 = V_7 -> V_157 ;
V_7 -> V_135 = V_7 -> V_153 ;
} else {
V_7 -> V_133 = 0 ;
}
V_21 = F_30 ( V_7 ) ;
return V_21 ;
}
static int F_39 ( struct V_6 * V_7 ,
unsigned int V_161 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_161 < V_162
|| V_161 > V_163 ) {
return - V_15 ;
}
F_6 ( V_161 , V_2 -> V_16 + V_164 + 4 * V_11 ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_165 ;
V_7 -> V_33 = F_41 ( NULL , V_166 , & V_7 -> V_167 ,
V_37 ) ;
if ( ! V_7 -> V_33 ) {
V_21 = - V_38 ;
goto V_168;
}
V_2 -> V_169 [ V_11 ] . V_170 = V_7 -> V_167 ;
V_2 -> V_169 [ V_11 ] . V_171 = V_7 -> V_167 ;
F_39 ( V_7 , V_172 ) ;
return 0 ;
V_168:
return V_21 ;
}
static T_4 F_42 ( struct V_173 * V_174 )
{
unsigned long V_36 ;
struct V_6 * V_7 = F_32 ( V_174 -> V_143 ) ;
T_4 V_175 ;
F_16 ( & V_7 -> V_176 , V_36 ) ;
V_175 = F_43 ( V_174 ) ;
F_17 ( & V_7 -> V_176 , V_36 ) ;
return V_175 ;
}
static int F_44 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_177 * V_64 = V_143 -> V_178 ;
int V_179 , V_21 ;
if ( ! V_64 )
return - V_15 ;
switch ( V_64 -> V_161 ) {
case V_180 :
V_179 = 3 ;
break;
case V_181 :
V_179 = 2 ;
break;
case V_182 :
default:
V_179 = 1 ;
break;
}
V_7 -> V_72 = V_64 -> V_72 ;
V_7 -> V_149 = V_64 -> V_183 ;
V_7 -> V_150 = V_64 -> V_184 ;
V_21 = F_45 ( V_7 -> V_2 -> V_185 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_45 ( V_7 -> V_2 -> V_186 ) ;
if ( V_21 )
goto V_187;
V_21 = F_40 ( V_7 ) ;
if ( V_21 )
goto V_188;
V_21 = F_39 ( V_7 , V_179 ) ;
if ( V_21 )
goto V_188;
F_46 ( & V_7 -> V_53 , V_143 ) ;
V_7 -> V_53 . V_189 = F_42 ;
V_7 -> V_53 . V_36 = V_190 ;
return 0 ;
V_188:
F_47 ( V_7 -> V_2 -> V_186 ) ;
V_187:
F_47 ( V_7 -> V_2 -> V_185 ) ;
return V_21 ;
}
static void F_48 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_34 ( V_143 ) ;
if ( V_7 -> V_149 )
F_20 ( V_7 , V_7 -> V_149 ) ;
if ( V_7 -> V_150 )
F_20 ( V_7 , V_7 -> V_150 ) ;
V_7 -> V_149 = 0 ;
V_7 -> V_150 = 0 ;
F_39 ( V_7 , 0 ) ;
F_18 ( NULL , V_166 , V_7 -> V_33 , V_7 -> V_167 ) ;
F_47 ( V_2 -> V_185 ) ;
F_47 ( V_2 -> V_186 ) ;
}
static struct V_173 * F_49 (
struct V_142 * V_143 , struct V_191 * V_192 ,
unsigned int V_193 , enum V_194 V_130 ,
unsigned long V_36 , void * V_129 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_60 , V_48 ;
int V_11 = V_7 -> V_11 ;
struct V_191 * V_195 ;
if ( V_7 -> V_43 == V_196 )
return NULL ;
V_7 -> V_43 = V_196 ;
V_7 -> V_36 = 0 ;
V_7 -> V_56 = 0 ;
F_31 ( V_2 -> V_24 , L_8 ,
V_193 , V_11 ) ;
V_7 -> V_130 = V_130 ;
V_21 = F_30 ( V_7 ) ;
if ( V_21 )
goto V_197;
if ( V_193 > V_198 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_193 , V_198 ) ;
V_21 = - V_15 ;
goto V_197;
}
V_7 -> V_199 = 0 ;
F_50 (sgl, sg, sg_len, i) {
struct V_31 * V_33 = & V_7 -> V_33 [ V_60 ] ;
int V_200 ;
V_33 -> V_49 = V_195 -> V_201 ;
V_48 = F_51 ( V_195 ) ;
if ( V_48 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_48 , 0xffff ) ;
V_21 = - V_15 ;
goto V_197;
}
V_33 -> V_40 . V_48 = V_48 ;
V_7 -> V_199 += V_48 ;
if ( V_7 -> V_202 > V_203 ) {
V_21 = - V_15 ;
goto V_197;
}
switch ( V_7 -> V_202 ) {
case V_203 :
V_33 -> V_40 . V_41 = 0 ;
if ( V_48 & 3 || V_195 -> V_201 & 3 )
return NULL ;
break;
case V_204 :
V_33 -> V_40 . V_41 = 2 ;
if ( V_48 & 1 || V_195 -> V_201 & 1 )
return NULL ;
break;
case V_205 :
V_33 -> V_40 . V_41 = 1 ;
break;
default:
return NULL ;
}
V_200 = V_44 | V_47 | V_206 ;
if ( V_60 + 1 == V_193 ) {
V_200 |= V_45 ;
V_200 |= V_207 ;
V_200 &= ~ V_206 ;
}
F_31 ( V_2 -> V_24 , L_11 ,
V_60 , V_48 , ( V_208 ) V_195 -> V_201 ,
V_200 & V_46 ? L_12 : L_13 ,
V_200 & V_45 ? L_14 : L_13 ) ;
V_33 -> V_40 . V_43 = V_200 ;
}
V_7 -> V_59 = V_193 ;
V_2 -> V_169 [ V_11 ] . V_171 = V_7 -> V_167 ;
return & V_7 -> V_53 ;
V_197:
V_7 -> V_43 = V_58 ;
return NULL ;
}
static struct V_173 * F_52 (
struct V_142 * V_143 , T_2 V_209 , T_5 V_210 ,
T_5 V_211 , enum V_194 V_130 ,
unsigned long V_36 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_212 = V_210 / V_211 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_60 = 0 , V_28 = 0 ;
F_31 ( V_2 -> V_24 , L_15 , V_213 , V_11 ) ;
if ( V_7 -> V_43 == V_196 )
return NULL ;
V_7 -> V_43 = V_196 ;
V_7 -> V_56 = 0 ;
V_7 -> V_211 = V_211 ;
V_7 -> V_36 |= V_65 ;
V_7 -> V_130 = V_130 ;
V_21 = F_30 ( V_7 ) ;
if ( V_21 )
goto V_197;
if ( V_212 > V_198 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_212 , V_198 ) ;
goto V_197;
}
if ( V_211 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_211 , 0xffff ) ;
goto V_197;
}
while ( V_28 < V_210 ) {
struct V_31 * V_33 = & V_7 -> V_33 [ V_60 ] ;
int V_200 ;
V_33 -> V_49 = V_209 ;
V_33 -> V_40 . V_48 = V_211 ;
if ( V_7 -> V_202 > V_203 )
goto V_197;
if ( V_7 -> V_202 == V_203 )
V_33 -> V_40 . V_41 = 0 ;
else
V_33 -> V_40 . V_41 = V_7 -> V_202 ;
V_200 = V_44 | V_47 | V_206 | V_45 ;
if ( V_60 + 1 == V_212 )
V_200 |= V_46 ;
F_31 ( V_2 -> V_24 , L_11 ,
V_60 , V_211 , ( V_208 ) V_209 ,
V_200 & V_46 ? L_12 : L_13 ,
V_200 & V_45 ? L_14 : L_13 ) ;
V_33 -> V_40 . V_43 = V_200 ;
V_209 += V_211 ;
V_28 += V_211 ;
V_60 ++ ;
}
V_7 -> V_59 = V_212 ;
V_2 -> V_169 [ V_11 ] . V_171 = V_7 -> V_167 ;
return & V_7 -> V_53 ;
V_197:
V_7 -> V_43 = V_58 ;
return NULL ;
}
static int F_53 ( struct V_142 * V_143 ,
struct V_214 * V_215 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
if ( V_215 -> V_130 == V_131 ) {
V_7 -> V_157 = V_215 -> V_216 ;
V_7 -> V_133 = V_215 -> V_217 *
V_215 -> V_218 ;
V_7 -> V_202 = V_215 -> V_218 ;
} else if ( V_215 -> V_130 == V_132 ) {
V_7 -> V_153 = V_215 -> V_216 ;
V_7 -> V_157 = V_215 -> V_219 ;
V_7 -> V_133 = V_215 -> V_217 &
V_146 ;
V_7 -> V_133 |= ( V_215 -> V_220 << 16 ) &
V_148 ;
V_7 -> V_202 = V_215 -> V_221 ;
} else {
V_7 -> V_157 = V_215 -> V_219 ;
V_7 -> V_133 = V_215 -> V_220 *
V_215 -> V_221 ;
V_7 -> V_202 = V_215 -> V_221 ;
}
V_7 -> V_130 = V_215 -> V_130 ;
return F_38 ( V_143 ) ;
}
static enum V_222 F_54 ( struct V_142 * V_143 ,
T_4 V_175 ,
struct V_223 * V_224 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
T_1 V_225 ;
if ( V_7 -> V_36 & V_65 )
V_225 = ( V_7 -> V_59 - V_7 -> V_56 ) * V_7 -> V_211 ;
else
V_225 = V_7 -> V_199 - V_7 -> V_61 ;
F_55 ( V_224 , V_143 -> V_226 , V_143 -> V_175 ,
V_225 ) ;
return V_7 -> V_43 ;
}
static void F_56 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_43 == V_196 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
const struct V_227 * V_228 )
{
T_6 * V_229 = ( T_1 * ) V_228 ;
T_6 * V_230 = ( T_1 * ) V_2 -> V_81 ;
int V_60 ;
if ( ! V_2 -> V_231 )
V_2 -> V_231 = V_232 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_231 ; V_60 ++ )
if ( V_229 [ V_60 ] > 0 )
V_230 [ V_60 ] = V_229 [ V_60 ] ;
}
static void F_58 ( const struct V_233 * V_234 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
const struct V_235 * V_236 ;
const struct V_227 * V_228 ;
unsigned short * V_237 ;
if ( ! V_234 ) {
F_59 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_234 -> V_29 < sizeof( * V_236 ) )
goto V_238;
V_236 = (struct V_235 * ) V_234 -> V_64 ;
if ( V_236 -> V_239 != V_240 )
goto V_238;
if ( V_236 -> V_241 + V_236 -> V_242 > V_234 -> V_29 )
goto V_238;
switch ( V_236 -> V_243 ) {
case 1 :
V_2 -> V_231 = V_232 ;
break;
case 2 :
V_2 -> V_231 = V_244 ;
break;
case 3 :
V_2 -> V_231 = V_245 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_238;
}
V_228 = ( void * ) V_236 + V_236 -> V_246 ;
V_237 = ( void * ) V_236 + V_236 -> V_241 ;
F_45 ( V_2 -> V_185 ) ;
F_45 ( V_2 -> V_186 ) ;
F_14 ( V_2 , V_237 ,
V_236 -> V_242 ,
V_228 -> V_247 ) ;
F_47 ( V_2 -> V_185 ) ;
F_47 ( V_2 -> V_186 ) ;
F_57 ( V_2 , V_228 ) ;
F_59 ( V_2 -> V_24 , L_19 ,
V_236 -> V_243 ,
V_236 -> V_248 ) ;
V_238:
F_60 ( V_234 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_249 * V_250 = V_2 -> V_24 -> V_251 ;
struct V_249 * V_252 = F_62 ( V_250 , L_20 , 0 ) ;
struct V_253 * V_254 ;
struct V_255 * V_256 ;
char V_257 [] = L_21 ;
T_1 V_258 , V_51 , V_259 , V_260 , V_60 ;
int V_21 = 0 ;
if ( F_63 ( V_250 ) || F_63 ( V_252 ) )
goto V_168;
V_254 = F_64 ( V_250 , V_257 , NULL ) ;
V_260 = V_254 ? ( V_254 -> V_261 / sizeof( T_1 ) ) : 0 ;
if ( ! V_260 ) {
F_31 ( V_2 -> V_24 , L_22 ) ;
goto V_168;
} else if ( V_260 % V_262 ) {
F_12 ( V_2 -> V_24 , L_23 ,
V_257 , V_262 ) ;
V_21 = - V_15 ;
goto V_168;
}
V_256 = F_65 ( V_252 ) ;
if ( F_63 ( V_256 ) ) {
F_12 ( V_2 -> V_24 , L_24 ) ;
V_21 = F_66 ( V_256 ) ;
goto V_168;
}
for ( V_60 = 0 ; V_60 < V_260 ; V_60 += V_262 ) {
V_21 = F_67 ( V_250 , V_257 , V_60 , & V_258 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_257 , V_60 ) ;
goto V_168;
}
V_21 = F_67 ( V_250 , V_257 , V_60 + 1 , & V_259 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_257 , V_60 + 1 ) ;
goto V_168;
}
V_21 = F_67 ( V_250 , V_257 , V_60 + 2 , & V_51 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_257 , V_60 + 2 ) ;
goto V_168;
}
F_68 ( V_256 , V_258 , F_9 ( V_259 ) , V_51 << V_259 ) ;
}
V_168:
if ( ! F_63 ( V_252 ) )
F_69 ( V_252 ) ;
return V_21 ;
}
static int F_70 ( struct V_1 * V_2 ,
const char * V_263 )
{
int V_21 ;
V_21 = F_71 ( V_264 ,
V_265 , V_263 , V_2 -> V_24 ,
V_37 , V_2 , F_58 ) ;
return V_21 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_60 , V_21 ;
T_2 V_266 ;
V_21 = F_45 ( V_2 -> V_185 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_45 ( V_2 -> V_186 ) ;
if ( V_21 )
goto V_187;
F_6 ( 0 , V_2 -> V_16 + V_267 ) ;
V_2 -> V_169 = F_15 ( NULL ,
V_268 * sizeof ( struct V_269 ) +
sizeof( struct V_128 ) ,
& V_266 , V_37 ) ;
if ( ! V_2 -> V_169 ) {
V_21 = - V_38 ;
goto V_270;
}
V_2 -> V_129 = ( void * ) V_2 -> V_169 +
V_268 * sizeof ( struct V_269 ) ;
V_2 -> V_141 = V_266 +
V_268 * sizeof ( struct V_269 ) ;
memset ( V_2 -> V_169 , 0 ,
V_268 * sizeof ( struct V_269 ) ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_5 -> V_160 ; V_60 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_60 ) ) ;
for ( V_60 = 0 ; V_60 < V_268 ; V_60 ++ )
F_6 ( 0 , V_2 -> V_16 + V_164 + V_60 * 4 ) ;
V_21 = F_40 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_270;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_271 ) ;
F_6 ( 0 , V_2 -> V_16 + V_25 ) ;
F_6 ( V_266 , V_2 -> V_16 + V_267 ) ;
F_39 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_47 ( V_2 -> V_185 ) ;
F_47 ( V_2 -> V_186 ) ;
return 0 ;
V_270:
F_47 ( V_2 -> V_186 ) ;
V_187:
F_47 ( V_2 -> V_185 ) ;
F_12 ( V_2 -> V_24 , L_26 , V_21 ) ;
return V_21 ;
}
static bool F_73 ( struct V_142 * V_143 , void * V_272 )
{
struct V_6 * V_7 = F_32 ( V_143 ) ;
struct V_177 * V_64 = V_272 ;
if ( ! F_74 ( V_143 ) )
return false ;
V_7 -> V_64 = * V_64 ;
V_143 -> V_178 = & V_7 -> V_64 ;
return true ;
}
static struct V_142 * F_75 ( struct V_273 * V_274 ,
struct V_275 * V_276 )
{
struct V_1 * V_2 = V_276 -> V_277 ;
T_7 V_278 = V_2 -> V_279 . V_280 ;
struct V_177 V_64 ;
if ( V_274 -> V_281 != 3 )
return NULL ;
V_64 . V_183 = V_274 -> args [ 0 ] ;
V_64 . V_72 = V_274 -> args [ 1 ] ;
V_64 . V_161 = V_274 -> args [ 2 ] ;
V_64 . V_184 = 0 ;
return F_76 ( V_278 , F_73 , & V_64 ) ;
}
static int F_77 ( struct V_282 * V_283 )
{
const struct V_284 * V_285 =
F_78 ( V_286 , & V_283 -> V_24 ) ;
struct V_249 * V_250 = V_283 -> V_24 . V_251 ;
struct V_249 * V_287 ;
const char * V_263 ;
int V_21 ;
int V_66 ;
struct V_288 * V_289 ;
struct V_288 V_290 ;
struct V_291 * V_292 = F_79 ( & V_283 -> V_24 ) ;
int V_60 ;
struct V_1 * V_2 ;
T_6 * V_230 ;
const struct V_293 * V_5 = NULL ;
if ( V_285 )
V_5 = V_285 -> V_64 ;
else if ( V_283 -> V_294 )
V_5 = ( void * ) V_283 -> V_294 -> V_295 ;
if ( ! V_5 ) {
F_12 ( & V_283 -> V_24 , L_27 ) ;
return - V_15 ;
}
V_21 = F_80 ( & V_283 -> V_24 , F_81 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_82 ( & V_283 -> V_24 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
F_83 ( & V_2 -> V_39 ) ;
V_2 -> V_24 = & V_283 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_66 = F_84 ( V_283 , 0 ) ;
if ( V_66 < 0 )
return V_66 ;
V_289 = F_85 ( V_283 , V_296 , 0 ) ;
V_2 -> V_16 = F_86 ( & V_283 -> V_24 , V_289 ) ;
if ( F_63 ( V_2 -> V_16 ) )
return F_66 ( V_2 -> V_16 ) ;
V_2 -> V_185 = F_87 ( & V_283 -> V_24 , L_28 ) ;
if ( F_63 ( V_2 -> V_185 ) )
return F_66 ( V_2 -> V_185 ) ;
V_2 -> V_186 = F_87 ( & V_283 -> V_24 , L_29 ) ;
if ( F_63 ( V_2 -> V_186 ) )
return F_66 ( V_2 -> V_186 ) ;
F_88 ( V_2 -> V_185 ) ;
F_88 ( V_2 -> V_186 ) ;
V_21 = F_89 ( & V_283 -> V_24 , V_66 , F_26 , 0 , L_30 ,
V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_81 = F_90 ( sizeof( * V_2 -> V_81 ) , V_37 ) ;
if ( ! V_2 -> V_81 )
return - V_38 ;
V_230 = ( T_6 * ) V_2 -> V_81 ;
for ( V_60 = 0 ; V_60 < V_232 ; V_60 ++ )
V_230 [ V_60 ] = - V_15 ;
F_91 ( V_297 , V_2 -> V_279 . V_280 ) ;
F_91 ( V_298 , V_2 -> V_279 . V_280 ) ;
F_92 ( & V_2 -> V_279 . V_299 ) ;
for ( V_60 = 0 ; V_60 < V_268 ; V_60 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_60 ] ;
V_7 -> V_2 = V_2 ;
F_83 ( & V_7 -> V_176 ) ;
V_7 -> V_143 . V_300 = & V_2 -> V_279 ;
F_93 ( & V_7 -> V_143 ) ;
V_7 -> V_11 = V_60 ;
F_94 ( & V_7 -> V_69 , F_25 ,
( unsigned long ) V_7 ) ;
if ( V_60 )
F_95 ( & V_7 -> V_143 . V_249 ,
& V_2 -> V_279 . V_299 ) ;
}
V_21 = F_72 ( V_2 ) ;
if ( V_21 )
goto V_301;
V_21 = F_61 ( V_2 ) ;
if ( V_21 )
goto V_301;
if ( V_2 -> V_5 -> V_81 )
F_57 ( V_2 , V_2 -> V_5 -> V_81 ) ;
if ( V_292 && V_292 -> V_81 )
F_57 ( V_2 , V_292 -> V_81 ) ;
if ( V_292 ) {
V_21 = F_70 ( V_2 , V_292 -> V_263 ) ;
if ( V_21 )
F_96 ( & V_283 -> V_24 , L_31 ) ;
} else {
V_21 = F_97 ( V_250 , L_32 ,
& V_263 ) ;
if ( V_21 )
F_96 ( & V_283 -> V_24 , L_33 ) ;
else {
V_21 = F_70 ( V_2 , V_263 ) ;
if ( V_21 )
F_96 ( & V_283 -> V_24 , L_34 ) ;
}
}
V_2 -> V_279 . V_24 = & V_283 -> V_24 ;
V_2 -> V_279 . V_302 = F_44 ;
V_2 -> V_279 . V_303 = F_48 ;
V_2 -> V_279 . V_304 = F_54 ;
V_2 -> V_279 . V_305 = F_49 ;
V_2 -> V_279 . V_306 = F_52 ;
V_2 -> V_279 . V_307 = F_53 ;
V_2 -> V_279 . V_308 = F_34 ;
V_2 -> V_279 . V_309 = F_9 ( V_203 ) ;
V_2 -> V_279 . V_310 = F_9 ( V_203 ) ;
V_2 -> V_279 . V_311 = F_9 ( V_131 ) | F_9 ( V_312 ) ;
V_2 -> V_279 . V_313 = V_314 ;
V_2 -> V_279 . V_315 = F_56 ;
V_2 -> V_279 . V_24 -> V_316 = & V_2 -> V_316 ;
F_98 ( V_2 -> V_279 . V_24 , 65535 ) ;
F_99 ( V_283 , V_2 ) ;
V_21 = F_100 ( & V_2 -> V_279 ) ;
if ( V_21 ) {
F_12 ( & V_283 -> V_24 , L_35 ) ;
goto V_301;
}
if ( V_250 ) {
V_21 = F_101 ( V_250 , F_75 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_283 -> V_24 , L_36 ) ;
goto V_317;
}
V_287 = F_102 ( NULL , NULL , L_37 ) ;
V_21 = F_103 ( V_287 , 0 , & V_290 ) ;
if ( ! V_21 ) {
V_2 -> V_154 = V_290 . V_318 ;
V_2 -> V_155 = V_290 . V_319 ;
}
F_69 ( V_287 ) ;
}
return 0 ;
V_317:
F_104 ( & V_2 -> V_279 ) ;
V_301:
F_105 ( V_2 -> V_81 ) ;
return V_21 ;
}
static int F_106 ( struct V_282 * V_283 )
{
struct V_1 * V_2 = F_107 ( V_283 ) ;
int V_60 ;
F_104 ( & V_2 -> V_279 ) ;
F_105 ( V_2 -> V_81 ) ;
for ( V_60 = 0 ; V_60 < V_268 ; V_60 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_60 ] ;
F_108 ( & V_7 -> V_69 ) ;
}
F_99 ( V_283 , NULL ) ;
return 0 ;
}
