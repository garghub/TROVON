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
F_22 ( & V_7 -> V_60 , NULL ) ;
V_7 -> V_54 ++ ;
V_7 -> V_54 %= V_7 -> V_61 ;
if ( error )
V_7 -> V_42 = V_53 ;
}
}
static void F_23 ( unsigned long V_62 )
{
struct V_6 * V_7 = (struct V_6 * ) V_62 ;
struct V_30 * V_32 ;
int V_63 , error = 0 ;
V_7 -> V_58 = 0 ;
for ( V_63 = 0 ; V_63 < V_7 -> V_61 ; V_63 ++ ) {
V_32 = & V_7 -> V_32 [ V_63 ] ;
if ( V_32 -> V_39 . V_42 & ( V_43 | V_55 ) )
error = - V_57 ;
V_7 -> V_58 += V_32 -> V_39 . V_47 ;
}
if ( error )
V_7 -> V_42 = V_56 ;
else
V_7 -> V_42 = V_64 ;
F_24 ( & V_7 -> V_60 ) ;
F_22 ( & V_7 -> V_60 , NULL ) ;
}
static T_3 F_25 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned long V_67 ;
V_67 = F_3 ( V_2 -> V_16 + V_68 ) ;
F_6 ( V_67 , V_2 -> V_16 + V_68 ) ;
V_67 &= ~ 1 ;
while ( V_67 ) {
int V_11 = F_26 ( V_67 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
if ( V_7 -> V_35 & V_69 )
F_21 ( V_7 ) ;
else
F_27 ( & V_7 -> V_70 ) ;
F_4 ( V_11 , & V_67 ) ;
}
return V_71 ;
}
static void F_28 ( struct V_6 * V_7 ,
enum V_72 V_73 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_74 = 0 , V_75 = 0 ;
int V_76 = 0 ;
V_7 -> V_77 = 0 ;
V_7 -> V_78 = 0 ;
V_7 -> V_79 = 0 ;
switch ( V_73 ) {
case V_80 :
break;
case V_81 :
V_75 = V_2 -> V_82 -> V_83 ;
V_74 = V_2 -> V_82 -> V_84 ;
break;
case V_85 :
V_74 = V_2 -> V_82 -> V_86 ;
V_75 = V_2 -> V_82 -> V_87 ;
break;
case V_88 :
V_74 = V_2 -> V_82 -> V_89 ;
V_75 = V_2 -> V_82 -> V_90 ;
break;
case V_91 :
V_74 = V_2 -> V_82 -> V_92 ;
V_75 = V_2 -> V_82 -> V_93 ;
break;
case V_94 :
V_74 = V_2 -> V_82 -> V_95 ;
V_75 = V_2 -> V_82 -> V_96 ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
V_74 = V_2 -> V_82 -> V_101 ;
V_75 = V_2 -> V_82 -> V_90 ;
break;
case V_102 :
V_74 = V_2 -> V_82 -> V_103 ;
V_75 = V_2 -> V_82 -> V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_74 = V_2 -> V_82 -> V_111 ;
V_75 = V_2 -> V_82 -> V_93 ;
break;
case V_112 :
V_74 = V_2 -> V_82 -> V_113 ;
V_75 = V_2 -> V_82 -> V_113 ;
V_76 = V_2 -> V_82 -> V_114 ;
break;
case V_115 :
V_74 = V_2 -> V_82 -> V_111 ;
V_75 = V_2 -> V_82 -> V_93 ;
V_76 = V_2 -> V_82 -> V_114 ;
break;
case V_116 :
V_74 = V_2 -> V_82 -> V_117 ;
V_75 = V_2 -> V_82 -> V_118 ;
break;
case V_119 :
V_74 = V_2 -> V_82 -> V_120 ;
break;
case V_121 :
V_74 = V_2 -> V_82 -> V_122 ;
V_75 = V_2 -> V_82 -> V_123 ;
break;
case V_124 :
V_75 = V_2 -> V_82 -> V_125 ;
break;
default:
break;
}
V_7 -> V_77 = V_74 ;
V_7 -> V_78 = V_75 ;
V_7 -> V_79 = V_76 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_126 ;
struct V_127 * V_128 = V_2 -> V_128 ;
struct V_30 * V_31 = V_2 -> V_11 [ 0 ] . V_32 ;
int V_21 ;
unsigned long V_35 ;
if ( V_7 -> V_129 == V_130 )
V_126 = V_7 -> V_77 ;
else if ( V_7 -> V_129 == V_131 )
V_126 = V_7 -> V_79 ;
else
V_126 = V_7 -> V_78 ;
if ( V_126 < 0 )
return V_126 ;
F_30 ( V_2 -> V_24 , L_2 , V_126 ) ;
F_30 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_132 ) ;
F_30 ( V_2 -> V_24 , L_4 , V_7 -> V_133 ) ;
F_30 ( V_2 -> V_24 , L_5 , V_7 -> V_134 ) ;
F_30 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_135 [ 0 ] ) ;
F_30 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_135 [ 1 ] ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> V_136 . V_137 = V_126 ;
V_128 -> V_138 [ 0 ] = V_7 -> V_135 [ 1 ] ;
V_128 -> V_138 [ 1 ] = V_7 -> V_135 [ 0 ] ;
V_128 -> V_138 [ 2 ] = V_7 -> V_134 ;
V_128 -> V_138 [ 6 ] = V_7 -> V_133 ;
V_128 -> V_138 [ 7 ] = V_7 -> V_132 ;
V_31 -> V_39 . V_40 = V_139 ;
V_31 -> V_39 . V_42 = V_43 | V_44 | V_45 | V_46 ;
V_31 -> V_39 . V_47 = sizeof( * V_128 ) / 4 ;
V_31 -> V_48 = V_2 -> V_140 ;
V_31 -> V_49 = 2048 + ( sizeof( * V_128 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
return V_21 ;
}
static struct V_6 * F_31 ( struct V_141 * V_142 )
{
return F_32 ( V_142 , struct V_6 , V_142 ) ;
}
static int F_33 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_23 ) ;
V_7 -> V_42 = V_56 ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_143 = V_7 -> V_132 & V_144 ;
int V_145 = ( V_7 -> V_132 & V_146 ) >> 16 ;
F_35 ( V_7 -> V_147 % 32 , & V_7 -> V_135 [ 1 ] ) ;
F_35 ( V_7 -> V_148 % 32 , & V_7 -> V_135 [ 0 ] ) ;
if ( V_7 -> V_147 > 31 )
V_7 -> V_132 |= V_149 ;
if ( V_7 -> V_148 > 31 )
V_7 -> V_132 |= V_150 ;
if ( V_143 > V_145 ) {
V_7 -> V_132 &= ~ ( V_144 |
V_146 ) ;
V_7 -> V_132 |= V_145 ;
V_7 -> V_132 |= V_143 << 16 ;
F_36 ( V_7 -> V_135 [ 0 ] , V_7 -> V_135 [ 1 ] ) ;
}
if ( V_7 -> V_151 >= V_2 -> V_152 &&
V_7 -> V_151 <= V_2 -> V_153 )
V_7 -> V_132 |= V_154 ;
if ( V_7 -> V_155 >= V_2 -> V_152 &&
V_7 -> V_155 <= V_2 -> V_153 )
V_7 -> V_132 |= V_156 ;
V_7 -> V_132 |= V_157 ;
}
static int F_37 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
int V_21 ;
F_33 ( V_142 ) ;
V_7 -> V_135 [ 0 ] = 0 ;
V_7 -> V_135 [ 1 ] = 0 ;
V_7 -> V_133 = 0 ;
V_7 -> V_134 = 0 ;
if ( V_7 -> V_147 ) {
if ( V_7 -> V_147 >= V_7 -> V_2 -> V_5 -> V_158 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_147 ) ;
}
if ( V_7 -> V_148 ) {
if ( V_7 -> V_148 >= V_7 -> V_2 -> V_5 -> V_158 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_148 ) ;
}
switch ( V_7 -> V_73 ) {
case V_81 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_80 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_28 ( V_7 , V_7 -> V_73 ) ;
if ( ( V_7 -> V_73 != V_80 ) &&
( V_7 -> V_73 != V_81 ) ) {
if ( V_7 -> V_148 ) {
if ( V_7 -> V_73 == V_115 ||
V_7 -> V_73 == V_112 )
F_34 ( V_7 ) ;
} else
F_5 ( V_7 -> V_147 , V_7 -> V_135 ) ;
V_7 -> V_133 = V_7 -> V_155 ;
V_7 -> V_134 = V_7 -> V_151 ;
} else {
V_7 -> V_132 = 0 ;
}
V_21 = F_29 ( V_7 ) ;
return V_21 ;
}
static int F_38 ( struct V_6 * V_7 ,
unsigned int V_159 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_159 < V_160
|| V_159 > V_161 ) {
return - V_15 ;
}
F_6 ( V_159 , V_2 -> V_16 + V_162 + 4 * V_11 ) ;
return 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_163 ;
V_7 -> V_32 = F_40 ( NULL , V_164 , & V_7 -> V_165 ,
V_36 ) ;
if ( ! V_7 -> V_32 ) {
V_21 = - V_37 ;
goto V_166;
}
V_2 -> V_167 [ V_11 ] . V_168 = V_7 -> V_165 ;
V_2 -> V_167 [ V_11 ] . V_169 = V_7 -> V_165 ;
F_38 ( V_7 , V_170 ) ;
return 0 ;
V_166:
return V_21 ;
}
static T_4 F_41 ( struct V_171 * V_172 )
{
unsigned long V_35 ;
struct V_6 * V_7 = F_31 ( V_172 -> V_142 ) ;
T_4 V_173 ;
F_16 ( & V_7 -> V_174 , V_35 ) ;
V_173 = F_42 ( V_172 ) ;
F_17 ( & V_7 -> V_174 , V_35 ) ;
return V_173 ;
}
static int F_43 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_175 * V_62 = V_142 -> V_176 ;
int V_177 , V_21 ;
if ( ! V_62 )
return - V_15 ;
switch ( V_62 -> V_159 ) {
case V_178 :
V_177 = 3 ;
break;
case V_179 :
V_177 = 2 ;
break;
case V_180 :
default:
V_177 = 1 ;
break;
}
V_7 -> V_73 = V_62 -> V_73 ;
V_7 -> V_147 = V_62 -> V_181 ;
V_7 -> V_148 = V_62 -> V_182 ;
V_21 = F_44 ( V_7 -> V_2 -> V_183 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_44 ( V_7 -> V_2 -> V_184 ) ;
if ( V_21 )
goto V_185;
V_21 = F_39 ( V_7 ) ;
if ( V_21 )
goto V_186;
V_21 = F_38 ( V_7 , V_177 ) ;
if ( V_21 )
goto V_186;
F_45 ( & V_7 -> V_60 , V_142 ) ;
V_7 -> V_60 . V_187 = F_41 ;
V_7 -> V_60 . V_35 = V_188 ;
return 0 ;
V_186:
F_46 ( V_7 -> V_2 -> V_184 ) ;
V_185:
F_46 ( V_7 -> V_2 -> V_183 ) ;
return V_21 ;
}
static void F_47 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_33 ( V_142 ) ;
if ( V_7 -> V_147 )
F_20 ( V_7 , V_7 -> V_147 ) ;
if ( V_7 -> V_148 )
F_20 ( V_7 , V_7 -> V_148 ) ;
V_7 -> V_147 = 0 ;
V_7 -> V_148 = 0 ;
F_38 ( V_7 , 0 ) ;
F_18 ( NULL , V_164 , V_7 -> V_32 , V_7 -> V_165 ) ;
F_46 ( V_2 -> V_183 ) ;
F_46 ( V_2 -> V_184 ) ;
}
static struct V_171 * F_48 (
struct V_141 * V_142 , struct V_189 * V_190 ,
unsigned int V_191 , enum V_192 V_129 ,
unsigned long V_35 , void * V_128 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_63 , V_47 ;
int V_11 = V_7 -> V_11 ;
struct V_189 * V_193 ;
if ( V_7 -> V_42 == V_194 )
return NULL ;
V_7 -> V_42 = V_194 ;
V_7 -> V_35 = 0 ;
V_7 -> V_54 = 0 ;
F_30 ( V_2 -> V_24 , L_8 ,
V_191 , V_11 ) ;
V_7 -> V_129 = V_129 ;
V_21 = F_29 ( V_7 ) ;
if ( V_21 )
goto V_195;
if ( V_191 > V_196 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_191 , V_196 ) ;
V_21 = - V_15 ;
goto V_195;
}
V_7 -> V_197 = 0 ;
F_49 (sgl, sg, sg_len, i) {
struct V_30 * V_32 = & V_7 -> V_32 [ V_63 ] ;
int V_198 ;
V_32 -> V_48 = V_193 -> V_199 ;
V_47 = F_50 ( V_193 ) ;
if ( V_47 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_47 , 0xffff ) ;
V_21 = - V_15 ;
goto V_195;
}
V_32 -> V_39 . V_47 = V_47 ;
V_7 -> V_197 += V_47 ;
if ( V_7 -> V_200 > V_201 ) {
V_21 = - V_15 ;
goto V_195;
}
switch ( V_7 -> V_200 ) {
case V_201 :
V_32 -> V_39 . V_40 = 0 ;
if ( V_47 & 3 || V_193 -> V_199 & 3 )
return NULL ;
break;
case V_202 :
V_32 -> V_39 . V_40 = 2 ;
if ( V_47 & 1 || V_193 -> V_199 & 1 )
return NULL ;
break;
case V_203 :
V_32 -> V_39 . V_40 = 1 ;
break;
default:
return NULL ;
}
V_198 = V_43 | V_46 | V_204 ;
if ( V_63 + 1 == V_191 ) {
V_198 |= V_44 ;
V_198 |= V_205 ;
V_198 &= ~ V_204 ;
}
F_30 ( V_2 -> V_24 , L_11 ,
V_63 , V_47 , ( V_206 ) V_193 -> V_199 ,
V_198 & V_45 ? L_12 : L_13 ,
V_198 & V_44 ? L_14 : L_13 ) ;
V_32 -> V_39 . V_42 = V_198 ;
}
V_7 -> V_61 = V_191 ;
V_2 -> V_167 [ V_11 ] . V_169 = V_7 -> V_165 ;
return & V_7 -> V_60 ;
V_195:
V_7 -> V_42 = V_56 ;
return NULL ;
}
static struct V_171 * F_51 (
struct V_141 * V_142 , T_2 V_207 , T_5 V_208 ,
T_5 V_59 , enum V_192 V_129 ,
unsigned long V_35 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_209 = V_208 / V_59 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_63 = 0 , V_27 = 0 ;
F_30 ( V_2 -> V_24 , L_15 , V_210 , V_11 ) ;
if ( V_7 -> V_42 == V_194 )
return NULL ;
V_7 -> V_42 = V_194 ;
V_7 -> V_54 = 0 ;
V_7 -> V_59 = V_59 ;
V_7 -> V_35 |= V_69 ;
V_7 -> V_129 = V_129 ;
V_21 = F_29 ( V_7 ) ;
if ( V_21 )
goto V_195;
if ( V_209 > V_196 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_209 , V_196 ) ;
goto V_195;
}
if ( V_59 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_59 , 0xffff ) ;
goto V_195;
}
while ( V_27 < V_208 ) {
struct V_30 * V_32 = & V_7 -> V_32 [ V_63 ] ;
int V_198 ;
V_32 -> V_48 = V_207 ;
V_32 -> V_39 . V_47 = V_59 ;
if ( V_7 -> V_200 > V_201 )
goto V_195;
if ( V_7 -> V_200 == V_201 )
V_32 -> V_39 . V_40 = 0 ;
else
V_32 -> V_39 . V_40 = V_7 -> V_200 ;
V_198 = V_43 | V_46 | V_204 | V_44 ;
if ( V_63 + 1 == V_209 )
V_198 |= V_45 ;
F_30 ( V_2 -> V_24 , L_11 ,
V_63 , V_59 , ( V_206 ) V_207 ,
V_198 & V_45 ? L_12 : L_13 ,
V_198 & V_44 ? L_14 : L_13 ) ;
V_32 -> V_39 . V_42 = V_198 ;
V_207 += V_59 ;
V_27 += V_59 ;
V_63 ++ ;
}
V_7 -> V_61 = V_209 ;
V_2 -> V_167 [ V_11 ] . V_169 = V_7 -> V_165 ;
return & V_7 -> V_60 ;
V_195:
V_7 -> V_42 = V_56 ;
return NULL ;
}
static int F_52 ( struct V_141 * V_142 ,
struct V_211 * V_212 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
if ( V_212 -> V_129 == V_130 ) {
V_7 -> V_155 = V_212 -> V_213 ;
V_7 -> V_132 = V_212 -> V_214 *
V_212 -> V_215 ;
V_7 -> V_200 = V_212 -> V_215 ;
} else if ( V_212 -> V_129 == V_131 ) {
V_7 -> V_151 = V_212 -> V_213 ;
V_7 -> V_155 = V_212 -> V_216 ;
V_7 -> V_132 = V_212 -> V_214 &
V_144 ;
V_7 -> V_132 |= ( V_212 -> V_217 << 16 ) &
V_146 ;
V_7 -> V_200 = V_212 -> V_218 ;
} else {
V_7 -> V_155 = V_212 -> V_216 ;
V_7 -> V_132 = V_212 -> V_217 *
V_212 -> V_218 ;
V_7 -> V_200 = V_212 -> V_218 ;
}
V_7 -> V_129 = V_212 -> V_129 ;
return F_37 ( V_142 ) ;
}
static enum V_52 F_53 ( struct V_141 * V_142 ,
T_4 V_173 ,
struct V_219 * V_220 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
T_1 V_221 ;
if ( V_7 -> V_35 & V_69 )
V_221 = ( V_7 -> V_61 - V_7 -> V_54 ) *
V_7 -> V_59 - V_7 -> V_58 ;
else
V_221 = V_7 -> V_197 - V_7 -> V_58 ;
F_54 ( V_220 , V_142 -> V_222 , V_142 -> V_173 ,
V_221 ) ;
return V_7 -> V_42 ;
}
static void F_55 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_42 == V_194 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
const struct V_223 * V_224 )
{
T_6 * V_225 = ( T_1 * ) V_224 ;
T_6 * V_226 = ( T_1 * ) V_2 -> V_82 ;
int V_63 ;
if ( ! V_2 -> V_227 )
V_2 -> V_227 = V_228 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_227 ; V_63 ++ )
if ( V_225 [ V_63 ] > 0 )
V_226 [ V_63 ] = V_225 [ V_63 ] ;
}
static void F_57 ( const struct V_229 * V_230 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
const struct V_231 * V_232 ;
const struct V_223 * V_224 ;
unsigned short * V_233 ;
if ( ! V_230 ) {
F_58 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_230 -> V_28 < sizeof( * V_232 ) )
goto V_234;
V_232 = (struct V_231 * ) V_230 -> V_62 ;
if ( V_232 -> V_235 != V_236 )
goto V_234;
if ( V_232 -> V_237 + V_232 -> V_238 > V_230 -> V_28 )
goto V_234;
switch ( V_232 -> V_239 ) {
case 1 :
V_2 -> V_227 = V_228 ;
break;
case 2 :
V_2 -> V_227 = V_240 ;
break;
case 3 :
V_2 -> V_227 = V_241 ;
break;
case 4 :
V_2 -> V_227 = V_242 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_234;
}
V_224 = ( void * ) V_232 + V_232 -> V_243 ;
V_233 = ( void * ) V_232 + V_232 -> V_237 ;
F_44 ( V_2 -> V_183 ) ;
F_44 ( V_2 -> V_184 ) ;
F_14 ( V_2 , V_233 ,
V_232 -> V_238 ,
V_224 -> V_244 ) ;
F_46 ( V_2 -> V_183 ) ;
F_46 ( V_2 -> V_184 ) ;
F_56 ( V_2 , V_224 ) ;
F_58 ( V_2 -> V_24 , L_19 ,
V_232 -> V_239 ,
V_232 -> V_245 ) ;
V_234:
F_59 ( V_230 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = V_2 -> V_24 -> V_248 ;
struct V_246 * V_249 = F_61 ( V_247 , L_20 , 0 ) ;
struct V_250 * V_251 ;
struct V_252 * V_253 ;
char V_254 [] = L_21 ;
T_1 V_22 , V_50 , V_255 , V_256 , V_63 ;
int V_21 = 0 ;
if ( F_62 ( V_247 ) || F_62 ( V_249 ) )
goto V_166;
V_251 = F_63 ( V_247 , V_254 , NULL ) ;
V_256 = V_251 ? ( V_251 -> V_257 / sizeof( T_1 ) ) : 0 ;
if ( ! V_256 ) {
F_30 ( V_2 -> V_24 , L_22 ) ;
goto V_166;
} else if ( V_256 % V_258 ) {
F_12 ( V_2 -> V_24 , L_23 ,
V_254 , V_258 ) ;
V_21 = - V_15 ;
goto V_166;
}
V_253 = F_64 ( V_249 ) ;
if ( F_62 ( V_253 ) ) {
F_12 ( V_2 -> V_24 , L_24 ) ;
V_21 = F_65 ( V_253 ) ;
goto V_166;
}
for ( V_63 = 0 ; V_63 < V_256 ; V_63 += V_258 ) {
V_21 = F_66 ( V_247 , V_254 , V_63 , & V_22 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_254 , V_63 ) ;
goto V_166;
}
V_21 = F_66 ( V_247 , V_254 , V_63 + 1 , & V_255 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_254 , V_63 + 1 ) ;
goto V_166;
}
V_21 = F_66 ( V_247 , V_254 , V_63 + 2 , & V_50 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_24 , L_25 ,
V_254 , V_63 + 2 ) ;
goto V_166;
}
F_67 ( V_253 , V_22 , F_9 ( V_255 ) , V_50 << V_255 ) ;
}
V_166:
if ( ! F_62 ( V_249 ) )
F_68 ( V_249 ) ;
return V_21 ;
}
static int F_69 ( struct V_1 * V_2 ,
const char * V_259 )
{
int V_21 ;
V_21 = F_70 ( V_260 ,
V_261 , V_259 , V_2 -> V_24 ,
V_36 , V_2 , F_57 ) ;
return V_21 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_63 , V_21 ;
T_2 V_262 ;
V_21 = F_44 ( V_2 -> V_183 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_44 ( V_2 -> V_184 ) ;
if ( V_21 )
goto V_185;
F_6 ( 0 , V_2 -> V_16 + V_263 ) ;
V_2 -> V_167 = F_15 ( NULL ,
V_264 * sizeof ( struct V_265 ) +
sizeof( struct V_127 ) ,
& V_262 , V_36 ) ;
if ( ! V_2 -> V_167 ) {
V_21 = - V_37 ;
goto V_266;
}
V_2 -> V_128 = ( void * ) V_2 -> V_167 +
V_264 * sizeof ( struct V_265 ) ;
V_2 -> V_140 = V_262 +
V_264 * sizeof ( struct V_265 ) ;
memset ( V_2 -> V_167 , 0 ,
V_264 * sizeof ( struct V_265 ) ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_5 -> V_158 ; V_63 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_63 ) ) ;
for ( V_63 = 0 ; V_63 < V_264 ; V_63 ++ )
F_6 ( 0 , V_2 -> V_16 + V_162 + V_63 * 4 ) ;
V_21 = F_39 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_266;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_267 ) ;
F_6 ( 0 , V_2 -> V_16 + V_25 ) ;
F_6 ( V_262 , V_2 -> V_16 + V_263 ) ;
F_38 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_46 ( V_2 -> V_183 ) ;
F_46 ( V_2 -> V_184 ) ;
return 0 ;
V_266:
F_46 ( V_2 -> V_184 ) ;
V_185:
F_46 ( V_2 -> V_183 ) ;
F_12 ( V_2 -> V_24 , L_26 , V_21 ) ;
return V_21 ;
}
static bool F_72 ( struct V_141 * V_142 , void * V_268 )
{
struct V_6 * V_7 = F_31 ( V_142 ) ;
struct V_175 * V_62 = V_268 ;
if ( ! F_73 ( V_142 ) )
return false ;
V_7 -> V_62 = * V_62 ;
V_142 -> V_176 = & V_7 -> V_62 ;
return true ;
}
static struct V_141 * F_74 ( struct V_269 * V_270 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = V_272 -> V_273 ;
T_7 V_274 = V_2 -> V_275 . V_276 ;
struct V_175 V_62 ;
if ( V_270 -> V_277 != 3 )
return NULL ;
V_62 . V_181 = V_270 -> args [ 0 ] ;
V_62 . V_73 = V_270 -> args [ 1 ] ;
V_62 . V_159 = V_270 -> args [ 2 ] ;
V_62 . V_182 = 0 ;
return F_75 ( V_274 , F_72 , & V_62 ) ;
}
static int F_76 ( struct V_278 * V_279 )
{
const struct V_280 * V_281 =
F_77 ( V_282 , & V_279 -> V_24 ) ;
struct V_246 * V_247 = V_279 -> V_24 . V_248 ;
struct V_246 * V_283 ;
const char * V_259 ;
int V_21 ;
int V_65 ;
struct V_284 * V_285 ;
struct V_284 V_286 ;
struct V_287 * V_288 = F_78 ( & V_279 -> V_24 ) ;
int V_63 ;
struct V_1 * V_2 ;
T_6 * V_226 ;
const struct V_289 * V_5 = NULL ;
if ( V_281 )
V_5 = V_281 -> V_62 ;
else if ( V_279 -> V_290 )
V_5 = ( void * ) V_279 -> V_290 -> V_291 ;
if ( ! V_5 ) {
F_12 ( & V_279 -> V_24 , L_27 ) ;
return - V_15 ;
}
V_21 = F_79 ( & V_279 -> V_24 , F_80 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_81 ( & V_279 -> V_24 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
F_82 ( & V_2 -> V_38 ) ;
V_2 -> V_24 = & V_279 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_65 = F_83 ( V_279 , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
V_285 = F_84 ( V_279 , V_292 , 0 ) ;
V_2 -> V_16 = F_85 ( & V_279 -> V_24 , V_285 ) ;
if ( F_62 ( V_2 -> V_16 ) )
return F_65 ( V_2 -> V_16 ) ;
V_2 -> V_183 = F_86 ( & V_279 -> V_24 , L_28 ) ;
if ( F_62 ( V_2 -> V_183 ) )
return F_65 ( V_2 -> V_183 ) ;
V_2 -> V_184 = F_86 ( & V_279 -> V_24 , L_29 ) ;
if ( F_62 ( V_2 -> V_184 ) )
return F_65 ( V_2 -> V_184 ) ;
F_87 ( V_2 -> V_183 ) ;
F_87 ( V_2 -> V_184 ) ;
V_21 = F_88 ( & V_279 -> V_24 , V_65 , F_25 , 0 , L_30 ,
V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_82 = F_89 ( sizeof( * V_2 -> V_82 ) , V_36 ) ;
if ( ! V_2 -> V_82 )
return - V_37 ;
V_226 = ( T_6 * ) V_2 -> V_82 ;
for ( V_63 = 0 ; V_63 < V_228 ; V_63 ++ )
V_226 [ V_63 ] = - V_15 ;
F_90 ( V_293 , V_2 -> V_275 . V_276 ) ;
F_90 ( V_294 , V_2 -> V_275 . V_276 ) ;
F_91 ( & V_2 -> V_275 . V_295 ) ;
for ( V_63 = 0 ; V_63 < V_264 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_63 ] ;
V_7 -> V_2 = V_2 ;
F_82 ( & V_7 -> V_174 ) ;
V_7 -> V_142 . V_296 = & V_2 -> V_275 ;
F_92 ( & V_7 -> V_142 ) ;
V_7 -> V_11 = V_63 ;
F_93 ( & V_7 -> V_70 , F_23 ,
( unsigned long ) V_7 ) ;
if ( V_63 )
F_94 ( & V_7 -> V_142 . V_246 ,
& V_2 -> V_275 . V_295 ) ;
}
V_21 = F_71 ( V_2 ) ;
if ( V_21 )
goto V_297;
V_21 = F_60 ( V_2 ) ;
if ( V_21 )
goto V_297;
if ( V_2 -> V_5 -> V_82 )
F_56 ( V_2 , V_2 -> V_5 -> V_82 ) ;
if ( V_288 && V_288 -> V_82 )
F_56 ( V_2 , V_288 -> V_82 ) ;
if ( V_288 ) {
V_21 = F_69 ( V_2 , V_288 -> V_259 ) ;
if ( V_21 )
F_95 ( & V_279 -> V_24 , L_31 ) ;
} else {
V_21 = F_96 ( V_247 , L_32 ,
& V_259 ) ;
if ( V_21 )
F_95 ( & V_279 -> V_24 , L_33 ) ;
else {
V_21 = F_69 ( V_2 , V_259 ) ;
if ( V_21 )
F_95 ( & V_279 -> V_24 , L_34 ) ;
}
}
V_2 -> V_275 . V_24 = & V_279 -> V_24 ;
V_2 -> V_275 . V_298 = F_43 ;
V_2 -> V_275 . V_299 = F_47 ;
V_2 -> V_275 . V_300 = F_53 ;
V_2 -> V_275 . V_301 = F_48 ;
V_2 -> V_275 . V_302 = F_51 ;
V_2 -> V_275 . V_303 = F_52 ;
V_2 -> V_275 . V_304 = F_33 ;
V_2 -> V_275 . V_305 = F_9 ( V_201 ) ;
V_2 -> V_275 . V_306 = F_9 ( V_201 ) ;
V_2 -> V_275 . V_307 = F_9 ( V_130 ) | F_9 ( V_308 ) ;
V_2 -> V_275 . V_309 = V_310 ;
V_2 -> V_275 . V_311 = F_55 ;
V_2 -> V_275 . V_24 -> V_312 = & V_2 -> V_312 ;
F_97 ( V_2 -> V_275 . V_24 , 65535 ) ;
F_98 ( V_279 , V_2 ) ;
V_21 = F_99 ( & V_2 -> V_275 ) ;
if ( V_21 ) {
F_12 ( & V_279 -> V_24 , L_35 ) ;
goto V_297;
}
if ( V_247 ) {
V_21 = F_100 ( V_247 , F_74 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_279 -> V_24 , L_36 ) ;
goto V_313;
}
V_283 = F_101 ( NULL , NULL , L_37 ) ;
V_21 = F_102 ( V_283 , 0 , & V_286 ) ;
if ( ! V_21 ) {
V_2 -> V_152 = V_286 . V_314 ;
V_2 -> V_153 = V_286 . V_315 ;
}
F_68 ( V_283 ) ;
}
return 0 ;
V_313:
F_103 ( & V_2 -> V_275 ) ;
V_297:
F_104 ( V_2 -> V_82 ) ;
return V_21 ;
}
static int F_105 ( struct V_278 * V_279 )
{
struct V_1 * V_2 = F_106 ( V_279 ) ;
int V_63 ;
F_107 ( & V_279 -> V_24 , V_2 -> V_65 , V_2 ) ;
F_103 ( & V_2 -> V_275 ) ;
F_104 ( V_2 -> V_82 ) ;
for ( V_63 = 0 ; V_63 < V_264 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_63 ] ;
F_108 ( & V_7 -> V_70 ) ;
}
F_98 ( V_279 , NULL ) ;
return 0 ;
}
