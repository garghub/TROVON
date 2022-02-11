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
struct V_30 * V_32 ;
int error = 0 ;
enum V_52 V_53 = V_7 -> V_42 ;
while ( 1 ) {
V_32 = & V_7 -> V_32 [ V_7 -> V_54 ] ;
if ( V_32 -> V_39 . V_42 & V_43 )
break;
if ( V_32 -> V_39 . V_42 & V_55 ) {
V_32 -> V_39 . V_42 &= ~ V_55 ;
V_7 -> V_42 = V_56 ;
error = - V_57 ;
}
V_7 -> V_58 = V_32 -> V_39 . V_47 ;
V_32 -> V_39 . V_42 |= V_43 ;
V_32 -> V_39 . V_47 = V_7 -> V_59 ;
V_7 -> V_60 = V_7 -> V_54 ;
V_7 -> V_54 = ( V_7 -> V_54 + 1 ) % V_7 -> V_61 ;
F_22 ( & V_7 -> V_62 , NULL ) ;
if ( error )
V_7 -> V_42 = V_53 ;
}
}
static void F_23 ( unsigned long V_63 )
{
struct V_6 * V_7 = (struct V_6 * ) V_63 ;
struct V_30 * V_32 ;
int V_64 , error = 0 ;
V_7 -> V_58 = 0 ;
for ( V_64 = 0 ; V_64 < V_7 -> V_61 ; V_64 ++ ) {
V_32 = & V_7 -> V_32 [ V_64 ] ;
if ( V_32 -> V_39 . V_42 & ( V_43 | V_55 ) )
error = - V_57 ;
V_7 -> V_58 += V_32 -> V_39 . V_47 ;
}
if ( error )
V_7 -> V_42 = V_56 ;
else
V_7 -> V_42 = V_65 ;
F_24 ( & V_7 -> V_62 ) ;
F_22 ( & V_7 -> V_62 , NULL ) ;
}
static T_3 F_25 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned long V_68 ;
V_68 = F_3 ( V_2 -> V_16 + V_69 ) ;
F_6 ( V_68 , V_2 -> V_16 + V_69 ) ;
V_68 &= ~ 1 ;
while ( V_68 ) {
int V_11 = F_26 ( V_68 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
if ( V_7 -> V_35 & V_70 )
F_21 ( V_7 ) ;
else
F_27 ( & V_7 -> V_71 ) ;
F_4 ( V_11 , & V_68 ) ;
}
return V_72 ;
}
static void F_28 ( struct V_6 * V_7 ,
enum V_73 V_74 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_75 = 0 , V_76 = 0 ;
int V_77 = 0 ;
V_7 -> V_78 = 0 ;
V_7 -> V_79 = 0 ;
V_7 -> V_80 = 0 ;
switch ( V_74 ) {
case V_81 :
break;
case V_82 :
V_76 = V_2 -> V_83 -> V_84 ;
V_75 = V_2 -> V_83 -> V_85 ;
break;
case V_86 :
V_75 = V_2 -> V_83 -> V_87 ;
V_76 = V_2 -> V_83 -> V_88 ;
break;
case V_89 :
V_75 = V_2 -> V_83 -> V_90 ;
V_76 = V_2 -> V_83 -> V_91 ;
break;
case V_92 :
V_75 = V_2 -> V_83 -> V_93 ;
V_76 = V_2 -> V_83 -> V_94 ;
break;
case V_95 :
V_75 = V_2 -> V_83 -> V_96 ;
V_76 = V_2 -> V_83 -> V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_75 = V_2 -> V_83 -> V_102 ;
V_76 = V_2 -> V_83 -> V_91 ;
break;
case V_103 :
V_75 = V_2 -> V_83 -> V_104 ;
V_76 = V_2 -> V_83 -> V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_75 = V_2 -> V_83 -> V_112 ;
V_76 = V_2 -> V_83 -> V_94 ;
break;
case V_113 :
V_75 = V_2 -> V_83 -> V_114 ;
V_76 = V_2 -> V_83 -> V_114 ;
V_77 = V_2 -> V_83 -> V_115 ;
break;
case V_116 :
V_75 = V_2 -> V_83 -> V_112 ;
V_76 = V_2 -> V_83 -> V_94 ;
V_77 = V_2 -> V_83 -> V_115 ;
break;
case V_117 :
V_75 = V_2 -> V_83 -> V_118 ;
V_76 = V_2 -> V_83 -> V_119 ;
break;
case V_120 :
V_75 = V_2 -> V_83 -> V_121 ;
break;
case V_122 :
V_75 = V_2 -> V_83 -> V_123 ;
V_76 = V_2 -> V_83 -> V_124 ;
break;
case V_125 :
V_76 = V_2 -> V_83 -> V_126 ;
break;
default:
break;
}
V_7 -> V_78 = V_75 ;
V_7 -> V_79 = V_76 ;
V_7 -> V_80 = V_77 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_127 ;
struct V_128 * V_129 = V_2 -> V_129 ;
struct V_30 * V_31 = V_2 -> V_11 [ 0 ] . V_32 ;
int V_21 ;
unsigned long V_35 ;
if ( V_7 -> V_130 == V_131 )
V_127 = V_7 -> V_78 ;
else if ( V_7 -> V_130 == V_132 )
V_127 = V_7 -> V_80 ;
else
V_127 = V_7 -> V_79 ;
if ( V_127 < 0 )
return V_127 ;
F_30 ( V_2 -> V_24 , L_2 , V_127 ) ;
F_30 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_133 ) ;
F_30 ( V_2 -> V_24 , L_4 , V_7 -> V_134 ) ;
F_30 ( V_2 -> V_24 , L_5 , V_7 -> V_135 ) ;
F_30 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_136 [ 0 ] ) ;
F_30 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_136 [ 1 ] ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> V_137 . V_138 = V_127 ;
V_129 -> V_139 [ 0 ] = V_7 -> V_136 [ 1 ] ;
V_129 -> V_139 [ 1 ] = V_7 -> V_136 [ 0 ] ;
V_129 -> V_139 [ 2 ] = V_7 -> V_135 ;
V_129 -> V_139 [ 6 ] = V_7 -> V_134 ;
V_129 -> V_139 [ 7 ] = V_7 -> V_133 ;
V_31 -> V_39 . V_40 = V_140 ;
V_31 -> V_39 . V_42 = V_43 | V_44 | V_45 | V_46 ;
V_31 -> V_39 . V_47 = sizeof( * V_129 ) / 4 ;
V_31 -> V_48 = V_2 -> V_141 ;
V_31 -> V_49 = 2048 + ( sizeof( * V_129 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
return V_21 ;
}
static struct V_6 * F_31 ( struct V_142 * V_143 )
{
return F_32 ( V_143 , struct V_6 , V_143 ) ;
}
static int F_33 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_23 ) ;
V_7 -> V_42 = V_56 ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_144 = V_7 -> V_133 & V_145 ;
int V_146 = ( V_7 -> V_133 & V_147 ) >> 16 ;
F_35 ( V_7 -> V_148 % 32 , & V_7 -> V_136 [ 1 ] ) ;
F_35 ( V_7 -> V_149 % 32 , & V_7 -> V_136 [ 0 ] ) ;
if ( V_7 -> V_148 > 31 )
V_7 -> V_133 |= V_150 ;
if ( V_7 -> V_149 > 31 )
V_7 -> V_133 |= V_151 ;
if ( V_144 > V_146 ) {
V_7 -> V_133 &= ~ ( V_145 |
V_147 ) ;
V_7 -> V_133 |= V_146 ;
V_7 -> V_133 |= V_144 << 16 ;
F_36 ( V_7 -> V_136 [ 0 ] , V_7 -> V_136 [ 1 ] ) ;
}
if ( V_7 -> V_152 >= V_2 -> V_153 &&
V_7 -> V_152 <= V_2 -> V_154 )
V_7 -> V_133 |= V_155 ;
if ( V_7 -> V_156 >= V_2 -> V_153 &&
V_7 -> V_156 <= V_2 -> V_154 )
V_7 -> V_133 |= V_157 ;
V_7 -> V_133 |= V_158 ;
}
static int F_37 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
int V_21 ;
F_33 ( V_143 ) ;
V_7 -> V_136 [ 0 ] = 0 ;
V_7 -> V_136 [ 1 ] = 0 ;
V_7 -> V_134 = 0 ;
V_7 -> V_135 = 0 ;
if ( V_7 -> V_148 ) {
if ( V_7 -> V_148 >= V_7 -> V_2 -> V_5 -> V_159 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_148 ) ;
}
if ( V_7 -> V_149 ) {
if ( V_7 -> V_149 >= V_7 -> V_2 -> V_5 -> V_159 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_149 ) ;
}
switch ( V_7 -> V_74 ) {
case V_82 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_81 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_28 ( V_7 , V_7 -> V_74 ) ;
if ( ( V_7 -> V_74 != V_81 ) &&
( V_7 -> V_74 != V_82 ) ) {
if ( V_7 -> V_149 ) {
if ( V_7 -> V_74 == V_116 ||
V_7 -> V_74 == V_113 )
F_34 ( V_7 ) ;
} else
F_5 ( V_7 -> V_148 , V_7 -> V_136 ) ;
V_7 -> V_134 = V_7 -> V_156 ;
V_7 -> V_135 = V_7 -> V_152 ;
} else {
V_7 -> V_133 = 0 ;
}
V_21 = F_29 ( V_7 ) ;
return V_21 ;
}
static int F_38 ( struct V_6 * V_7 ,
unsigned int V_160 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_160 < V_161
|| V_160 > V_162 ) {
return - V_15 ;
}
F_6 ( V_160 , V_2 -> V_16 + V_163 + 4 * V_11 ) ;
return 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_164 ;
V_7 -> V_32 = F_40 ( NULL , V_165 , & V_7 -> V_166 ,
V_36 ) ;
if ( ! V_7 -> V_32 ) {
V_21 = - V_37 ;
goto V_167;
}
V_2 -> V_168 [ V_11 ] . V_169 = V_7 -> V_166 ;
V_2 -> V_168 [ V_11 ] . V_170 = V_7 -> V_166 ;
F_38 ( V_7 , V_171 ) ;
return 0 ;
V_167:
return V_21 ;
}
static T_4 F_41 ( struct V_172 * V_173 )
{
unsigned long V_35 ;
struct V_6 * V_7 = F_31 ( V_173 -> V_143 ) ;
T_4 V_174 ;
F_16 ( & V_7 -> V_175 , V_35 ) ;
V_174 = F_42 ( V_173 ) ;
F_17 ( & V_7 -> V_175 , V_35 ) ;
return V_174 ;
}
static int F_43 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_176 * V_63 = V_143 -> V_177 ;
int V_178 , V_21 ;
if ( ! V_63 )
return - V_15 ;
switch ( V_63 -> V_160 ) {
case V_179 :
V_178 = 3 ;
break;
case V_180 :
V_178 = 2 ;
break;
case V_181 :
default:
V_178 = 1 ;
break;
}
V_7 -> V_74 = V_63 -> V_74 ;
V_7 -> V_148 = V_63 -> V_182 ;
V_7 -> V_149 = V_63 -> V_183 ;
V_21 = F_44 ( V_7 -> V_2 -> V_184 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_44 ( V_7 -> V_2 -> V_185 ) ;
if ( V_21 )
goto V_186;
V_21 = F_39 ( V_7 ) ;
if ( V_21 )
goto V_187;
V_21 = F_38 ( V_7 , V_178 ) ;
if ( V_21 )
goto V_187;
F_45 ( & V_7 -> V_62 , V_143 ) ;
V_7 -> V_62 . V_188 = F_41 ;
V_7 -> V_62 . V_35 = V_189 ;
return 0 ;
V_187:
F_46 ( V_7 -> V_2 -> V_185 ) ;
V_186:
F_46 ( V_7 -> V_2 -> V_184 ) ;
return V_21 ;
}
static void F_47 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_33 ( V_143 ) ;
if ( V_7 -> V_148 )
F_20 ( V_7 , V_7 -> V_148 ) ;
if ( V_7 -> V_149 )
F_20 ( V_7 , V_7 -> V_149 ) ;
V_7 -> V_148 = 0 ;
V_7 -> V_149 = 0 ;
F_38 ( V_7 , 0 ) ;
F_18 ( NULL , V_165 , V_7 -> V_32 , V_7 -> V_166 ) ;
F_46 ( V_2 -> V_184 ) ;
F_46 ( V_2 -> V_185 ) ;
}
static struct V_172 * F_48 (
struct V_142 * V_143 , struct V_190 * V_191 ,
unsigned int V_192 , enum V_193 V_130 ,
unsigned long V_35 , void * V_129 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_64 , V_47 ;
int V_11 = V_7 -> V_11 ;
struct V_190 * V_194 ;
if ( V_7 -> V_42 == V_195 )
return NULL ;
V_7 -> V_42 = V_195 ;
V_7 -> V_35 = 0 ;
V_7 -> V_54 = 0 ;
V_7 -> V_60 = 0 ;
V_7 -> V_58 = 0 ;
F_30 ( V_2 -> V_24 , L_8 ,
V_192 , V_11 ) ;
V_7 -> V_130 = V_130 ;
V_21 = F_29 ( V_7 ) ;
if ( V_21 )
goto V_196;
if ( V_192 > V_197 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_192 , V_197 ) ;
V_21 = - V_15 ;
goto V_196;
}
V_7 -> V_198 = 0 ;
F_49 (sgl, sg, sg_len, i) {
struct V_30 * V_32 = & V_7 -> V_32 [ V_64 ] ;
int V_199 ;
V_32 -> V_48 = V_194 -> V_200 ;
V_47 = F_50 ( V_194 ) ;
if ( V_47 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_47 , 0xffff ) ;
V_21 = - V_15 ;
goto V_196;
}
V_32 -> V_39 . V_47 = V_47 ;
V_7 -> V_198 += V_47 ;
if ( V_7 -> V_201 > V_202 ) {
V_21 = - V_15 ;
goto V_196;
}
switch ( V_7 -> V_201 ) {
case V_202 :
V_32 -> V_39 . V_40 = 0 ;
if ( V_47 & 3 || V_194 -> V_200 & 3 )
return NULL ;
break;
case V_203 :
V_32 -> V_39 . V_40 = 2 ;
if ( V_47 & 1 || V_194 -> V_200 & 1 )
return NULL ;
break;
case V_204 :
V_32 -> V_39 . V_40 = 1 ;
break;
default:
return NULL ;
}
V_199 = V_43 | V_46 | V_205 ;
if ( V_64 + 1 == V_192 ) {
V_199 |= V_44 ;
V_199 |= V_206 ;
V_199 &= ~ V_205 ;
}
F_30 ( V_2 -> V_24 , L_11 ,
V_64 , V_47 , ( V_207 ) V_194 -> V_200 ,
V_199 & V_45 ? L_12 : L_13 ,
V_199 & V_44 ? L_14 : L_13 ) ;
V_32 -> V_39 . V_42 = V_199 ;
}
V_7 -> V_61 = V_192 ;
V_2 -> V_168 [ V_11 ] . V_170 = V_7 -> V_166 ;
return & V_7 -> V_62 ;
V_196:
V_7 -> V_42 = V_56 ;
return NULL ;
}
static struct V_172 * F_51 (
struct V_142 * V_143 , T_2 V_208 , T_5 V_209 ,
T_5 V_59 , enum V_193 V_130 ,
unsigned long V_35 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_210 = V_209 / V_59 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_64 = 0 , V_27 = 0 ;
F_30 ( V_2 -> V_24 , L_15 , V_211 , V_11 ) ;
if ( V_7 -> V_42 == V_195 )
return NULL ;
V_7 -> V_42 = V_195 ;
V_7 -> V_54 = 0 ;
V_7 -> V_60 = 0 ;
V_7 -> V_58 = 0 ;
V_7 -> V_59 = V_59 ;
V_7 -> V_35 |= V_70 ;
V_7 -> V_130 = V_130 ;
V_21 = F_29 ( V_7 ) ;
if ( V_21 )
goto V_196;
if ( V_210 > V_197 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_210 , V_197 ) ;
goto V_196;
}
if ( V_59 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_59 , 0xffff ) ;
goto V_196;
}
while ( V_27 < V_209 ) {
struct V_30 * V_32 = & V_7 -> V_32 [ V_64 ] ;
int V_199 ;
V_32 -> V_48 = V_208 ;
V_32 -> V_39 . V_47 = V_59 ;
if ( V_7 -> V_201 > V_202 )
goto V_196;
if ( V_7 -> V_201 == V_202 )
V_32 -> V_39 . V_40 = 0 ;
else
V_32 -> V_39 . V_40 = V_7 -> V_201 ;
V_199 = V_43 | V_46 | V_205 | V_44 ;
if ( V_64 + 1 == V_210 )
V_199 |= V_45 ;
F_30 ( V_2 -> V_24 , L_11 ,
V_64 , V_59 , ( V_207 ) V_208 ,
V_199 & V_45 ? L_12 : L_13 ,
V_199 & V_44 ? L_14 : L_13 ) ;
V_32 -> V_39 . V_42 = V_199 ;
V_208 += V_59 ;
V_27 += V_59 ;
V_64 ++ ;
}
V_7 -> V_61 = V_210 ;
V_2 -> V_168 [ V_11 ] . V_170 = V_7 -> V_166 ;
return & V_7 -> V_62 ;
V_196:
V_7 -> V_42 = V_56 ;
return NULL ;
}
static int F_52 ( struct V_142 * V_143 ,
struct V_212 * V_213 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
if ( V_213 -> V_130 == V_131 ) {
V_7 -> V_156 = V_213 -> V_214 ;
V_7 -> V_133 = V_213 -> V_215 *
V_213 -> V_216 ;
V_7 -> V_201 = V_213 -> V_216 ;
} else if ( V_213 -> V_130 == V_132 ) {
V_7 -> V_152 = V_213 -> V_214 ;
V_7 -> V_156 = V_213 -> V_217 ;
V_7 -> V_133 = V_213 -> V_215 &
V_145 ;
V_7 -> V_133 |= ( V_213 -> V_218 << 16 ) &
V_147 ;
V_7 -> V_201 = V_213 -> V_219 ;
} else {
V_7 -> V_156 = V_213 -> V_217 ;
V_7 -> V_133 = V_213 -> V_218 *
V_213 -> V_219 ;
V_7 -> V_201 = V_213 -> V_219 ;
}
V_7 -> V_130 = V_213 -> V_130 ;
return F_37 ( V_143 ) ;
}
static enum V_52 F_53 ( struct V_142 * V_143 ,
T_4 V_174 ,
struct V_220 * V_221 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
T_1 V_222 ;
if ( V_7 -> V_35 & V_70 )
V_222 = ( V_7 -> V_61 - V_7 -> V_60 ) *
V_7 -> V_59 - V_7 -> V_58 ;
else
V_222 = V_7 -> V_198 - V_7 -> V_58 ;
F_54 ( V_221 , V_143 -> V_223 , V_143 -> V_174 ,
V_222 ) ;
return V_7 -> V_42 ;
}
static void F_55 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_42 == V_195 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
const struct V_224 * V_225 )
{
T_6 * V_226 = ( T_1 * ) V_225 ;
T_6 * V_227 = ( T_1 * ) V_2 -> V_83 ;
int V_64 ;
if ( ! V_2 -> V_228 )
V_2 -> V_228 = V_229 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_228 ; V_64 ++ )
if ( V_226 [ V_64 ] > 0 )
V_227 [ V_64 ] = V_226 [ V_64 ] ;
}
static void F_57 ( const struct V_230 * V_231 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
const struct V_232 * V_233 ;
const struct V_224 * V_225 ;
unsigned short * V_234 ;
if ( ! V_231 ) {
F_58 ( V_2 -> V_24 , L_17 ) ;
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
case 4 :
V_2 -> V_228 = V_243 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_235;
}
V_225 = ( void * ) V_233 + V_233 -> V_244 ;
V_234 = ( void * ) V_233 + V_233 -> V_238 ;
F_44 ( V_2 -> V_184 ) ;
F_44 ( V_2 -> V_185 ) ;
F_14 ( V_2 , V_234 ,
V_233 -> V_239 ,
V_225 -> V_245 ) ;
F_46 ( V_2 -> V_184 ) ;
F_46 ( V_2 -> V_185 ) ;
F_56 ( V_2 , V_225 ) ;
F_58 ( V_2 -> V_24 , L_19 ,
V_233 -> V_240 ,
V_233 -> V_246 ) ;
V_235:
F_59 ( V_231 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_247 * V_248 = V_2 -> V_24 -> V_249 ;
struct V_247 * V_250 = F_61 ( V_248 , L_20 , 0 ) ;
struct V_251 * V_252 ;
struct V_253 * V_254 ;
char V_255 [] = L_21 ;
T_1 V_22 , V_50 , V_256 , V_257 , V_64 ;
int V_21 = 0 ;
if ( F_62 ( V_248 ) || F_62 ( V_250 ) )
goto V_167;
V_252 = F_63 ( V_248 , V_255 , NULL ) ;
V_257 = V_252 ? ( V_252 -> V_258 / sizeof( T_1 ) ) : 0 ;
if ( ! V_257 ) {
F_30 ( V_2 -> V_24 , L_22 ) ;
goto V_167;
} else if ( V_257 % V_259 ) {
F_12 ( V_2 -> V_24 , L_23 ,
V_255 , V_259 ) ;
V_21 = - V_15 ;
goto V_167;
}
V_254 = F_64 ( V_250 ) ;
if ( F_62 ( V_254 ) ) {
F_12 ( V_2 -> V_24 , L_24 ) ;
V_21 = F_65 ( V_254 ) ;
goto V_167;
}
for ( V_64 = 0 ; V_64 < V_257 ; V_64 += V_259 ) {
V_21 = F_66 ( V_248 , V_255 , V_64 , & V_22 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_255 , V_64 ) ;
goto V_167;
}
V_21 = F_66 ( V_248 , V_255 , V_64 + 1 , & V_256 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_255 , V_64 + 1 ) ;
goto V_167;
}
V_21 = F_66 ( V_248 , V_255 , V_64 + 2 , & V_50 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_255 , V_64 + 2 ) ;
goto V_167;
}
F_67 ( V_254 , V_22 , F_9 ( V_256 ) , V_50 << V_256 ) ;
}
V_167:
if ( ! F_62 ( V_250 ) )
F_68 ( V_250 ) ;
return V_21 ;
}
static int F_69 ( struct V_1 * V_2 ,
const char * V_260 )
{
int V_21 ;
V_21 = F_70 ( V_261 ,
V_262 , V_260 , V_2 -> V_24 ,
V_36 , V_2 , F_57 ) ;
return V_21 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_64 , V_21 ;
T_2 V_263 ;
V_21 = F_44 ( V_2 -> V_184 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_44 ( V_2 -> V_185 ) ;
if ( V_21 )
goto V_186;
F_6 ( 0 , V_2 -> V_16 + V_264 ) ;
V_2 -> V_168 = F_15 ( NULL ,
V_265 * sizeof ( struct V_266 ) +
sizeof( struct V_128 ) ,
& V_263 , V_36 ) ;
if ( ! V_2 -> V_168 ) {
V_21 = - V_37 ;
goto V_267;
}
V_2 -> V_129 = ( void * ) V_2 -> V_168 +
V_265 * sizeof ( struct V_266 ) ;
V_2 -> V_141 = V_263 +
V_265 * sizeof ( struct V_266 ) ;
memset ( V_2 -> V_168 , 0 ,
V_265 * sizeof ( struct V_266 ) ) ;
for ( V_64 = 0 ; V_64 < V_2 -> V_5 -> V_159 ; V_64 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_64 ) ) ;
for ( V_64 = 0 ; V_64 < V_265 ; V_64 ++ )
F_6 ( 0 , V_2 -> V_16 + V_163 + V_64 * 4 ) ;
V_21 = F_39 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_267;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_268 ) ;
F_6 ( 0 , V_2 -> V_16 + V_25 ) ;
F_6 ( V_263 , V_2 -> V_16 + V_264 ) ;
F_38 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_46 ( V_2 -> V_184 ) ;
F_46 ( V_2 -> V_185 ) ;
return 0 ;
V_267:
F_46 ( V_2 -> V_185 ) ;
V_186:
F_46 ( V_2 -> V_184 ) ;
F_12 ( V_2 -> V_24 , L_26 , V_21 ) ;
return V_21 ;
}
static bool F_72 ( struct V_142 * V_143 , void * V_269 )
{
struct V_6 * V_7 = F_31 ( V_143 ) ;
struct V_176 * V_63 = V_269 ;
if ( ! F_73 ( V_143 ) )
return false ;
V_7 -> V_63 = * V_63 ;
V_143 -> V_177 = & V_7 -> V_63 ;
return true ;
}
static struct V_142 * F_74 ( struct V_270 * V_271 ,
struct V_272 * V_273 )
{
struct V_1 * V_2 = V_273 -> V_274 ;
T_7 V_275 = V_2 -> V_276 . V_277 ;
struct V_176 V_63 ;
if ( V_271 -> V_278 != 3 )
return NULL ;
V_63 . V_182 = V_271 -> args [ 0 ] ;
V_63 . V_74 = V_271 -> args [ 1 ] ;
V_63 . V_160 = V_271 -> args [ 2 ] ;
V_63 . V_183 = 0 ;
return F_75 ( V_275 , F_72 , & V_63 ) ;
}
static int F_76 ( struct V_279 * V_280 )
{
const struct V_281 * V_282 =
F_77 ( V_283 , & V_280 -> V_24 ) ;
struct V_247 * V_248 = V_280 -> V_24 . V_249 ;
struct V_247 * V_284 ;
const char * V_260 ;
int V_21 ;
int V_66 ;
struct V_285 * V_286 ;
struct V_285 V_287 ;
struct V_288 * V_289 = F_78 ( & V_280 -> V_24 ) ;
int V_64 ;
struct V_1 * V_2 ;
T_6 * V_227 ;
const struct V_290 * V_5 = NULL ;
if ( V_282 )
V_5 = V_282 -> V_63 ;
else if ( V_280 -> V_291 )
V_5 = ( void * ) V_280 -> V_291 -> V_292 ;
if ( ! V_5 ) {
F_12 ( & V_280 -> V_24 , L_27 ) ;
return - V_15 ;
}
V_21 = F_79 ( & V_280 -> V_24 , F_80 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_81 ( & V_280 -> V_24 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
F_82 ( & V_2 -> V_38 ) ;
V_2 -> V_24 = & V_280 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_66 = F_83 ( V_280 , 0 ) ;
if ( V_66 < 0 )
return V_66 ;
V_286 = F_84 ( V_280 , V_293 , 0 ) ;
V_2 -> V_16 = F_85 ( & V_280 -> V_24 , V_286 ) ;
if ( F_62 ( V_2 -> V_16 ) )
return F_65 ( V_2 -> V_16 ) ;
V_2 -> V_184 = F_86 ( & V_280 -> V_24 , L_28 ) ;
if ( F_62 ( V_2 -> V_184 ) )
return F_65 ( V_2 -> V_184 ) ;
V_2 -> V_185 = F_86 ( & V_280 -> V_24 , L_29 ) ;
if ( F_62 ( V_2 -> V_185 ) )
return F_65 ( V_2 -> V_185 ) ;
F_87 ( V_2 -> V_184 ) ;
F_87 ( V_2 -> V_185 ) ;
V_21 = F_88 ( & V_280 -> V_24 , V_66 , F_25 , 0 , L_30 ,
V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_83 = F_89 ( sizeof( * V_2 -> V_83 ) , V_36 ) ;
if ( ! V_2 -> V_83 )
return - V_37 ;
V_227 = ( T_6 * ) V_2 -> V_83 ;
for ( V_64 = 0 ; V_64 < V_229 ; V_64 ++ )
V_227 [ V_64 ] = - V_15 ;
F_90 ( V_294 , V_2 -> V_276 . V_277 ) ;
F_90 ( V_295 , V_2 -> V_276 . V_277 ) ;
F_91 ( & V_2 -> V_276 . V_296 ) ;
for ( V_64 = 0 ; V_64 < V_265 ; V_64 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_64 ] ;
V_7 -> V_2 = V_2 ;
F_82 ( & V_7 -> V_175 ) ;
V_7 -> V_143 . V_297 = & V_2 -> V_276 ;
F_92 ( & V_7 -> V_143 ) ;
V_7 -> V_11 = V_64 ;
F_93 ( & V_7 -> V_71 , F_23 ,
( unsigned long ) V_7 ) ;
if ( V_64 )
F_94 ( & V_7 -> V_143 . V_247 ,
& V_2 -> V_276 . V_296 ) ;
}
V_21 = F_71 ( V_2 ) ;
if ( V_21 )
goto V_298;
V_21 = F_60 ( V_2 ) ;
if ( V_21 )
goto V_298;
if ( V_2 -> V_5 -> V_83 )
F_56 ( V_2 , V_2 -> V_5 -> V_83 ) ;
if ( V_289 && V_289 -> V_83 )
F_56 ( V_2 , V_289 -> V_83 ) ;
if ( V_289 ) {
V_21 = F_69 ( V_2 , V_289 -> V_260 ) ;
if ( V_21 )
F_95 ( & V_280 -> V_24 , L_31 ) ;
} else {
V_21 = F_96 ( V_248 , L_32 ,
& V_260 ) ;
if ( V_21 )
F_95 ( & V_280 -> V_24 , L_33 ) ;
else {
V_21 = F_69 ( V_2 , V_260 ) ;
if ( V_21 )
F_95 ( & V_280 -> V_24 , L_34 ) ;
}
}
V_2 -> V_276 . V_24 = & V_280 -> V_24 ;
V_2 -> V_276 . V_299 = F_43 ;
V_2 -> V_276 . V_300 = F_47 ;
V_2 -> V_276 . V_301 = F_53 ;
V_2 -> V_276 . V_302 = F_48 ;
V_2 -> V_276 . V_303 = F_51 ;
V_2 -> V_276 . V_304 = F_52 ;
V_2 -> V_276 . V_305 = F_33 ;
V_2 -> V_276 . V_306 = F_9 ( V_202 ) ;
V_2 -> V_276 . V_307 = F_9 ( V_202 ) ;
V_2 -> V_276 . V_308 = F_9 ( V_131 ) | F_9 ( V_309 ) ;
V_2 -> V_276 . V_310 = V_311 ;
V_2 -> V_276 . V_312 = F_55 ;
V_2 -> V_276 . V_24 -> V_313 = & V_2 -> V_313 ;
F_97 ( V_2 -> V_276 . V_24 , 65535 ) ;
F_98 ( V_280 , V_2 ) ;
V_21 = F_99 ( & V_2 -> V_276 ) ;
if ( V_21 ) {
F_12 ( & V_280 -> V_24 , L_35 ) ;
goto V_298;
}
if ( V_248 ) {
V_21 = F_100 ( V_248 , F_74 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_280 -> V_24 , L_36 ) ;
goto V_314;
}
V_284 = F_101 ( NULL , NULL , L_37 ) ;
V_21 = F_102 ( V_284 , 0 , & V_287 ) ;
if ( ! V_21 ) {
V_2 -> V_153 = V_287 . V_315 ;
V_2 -> V_154 = V_287 . V_316 ;
}
F_68 ( V_284 ) ;
}
return 0 ;
V_314:
F_103 ( & V_2 -> V_276 ) ;
V_298:
F_104 ( V_2 -> V_83 ) ;
return V_21 ;
}
static int F_105 ( struct V_279 * V_280 )
{
struct V_1 * V_2 = F_106 ( V_280 ) ;
int V_64 ;
F_107 ( & V_280 -> V_24 , V_2 -> V_66 , V_2 ) ;
F_103 ( & V_2 -> V_276 ) ;
F_104 ( V_2 -> V_83 ) ;
for ( V_64 = 0 ; V_64 < V_265 ; V_64 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_64 ] ;
F_108 ( & V_7 -> V_71 ) ;
}
F_98 ( V_280 , NULL ) ;
return 0 ;
}
