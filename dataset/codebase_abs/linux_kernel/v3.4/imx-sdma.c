static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = ( V_2 -> V_5 == V_6 ? V_7 :
V_8 ) ;
return V_4 + V_3 * 4 ;
}
static int F_2 ( struct V_9 * V_10 ,
bool V_11 , bool V_12 , bool V_13 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
unsigned long V_15 , V_16 , V_17 ;
if ( V_11 && V_12 && V_13 )
return - V_18 ;
V_15 = F_3 ( V_2 -> V_19 + V_20 ) ;
V_16 = F_3 ( V_2 -> V_19 + V_21 ) ;
V_17 = F_3 ( V_2 -> V_19 + V_22 ) ;
if ( V_13 )
F_4 ( V_14 , & V_17 ) ;
else
F_5 ( V_14 , & V_17 ) ;
if ( V_11 )
F_4 ( V_14 , & V_15 ) ;
else
F_5 ( V_14 , & V_15 ) ;
if ( V_12 )
F_4 ( V_14 , & V_16 ) ;
else
F_5 ( V_14 , & V_16 ) ;
F_6 ( V_15 , V_2 -> V_19 + V_20 ) ;
F_6 ( V_16 , V_2 -> V_19 + V_21 ) ;
F_6 ( V_17 , V_2 -> V_19 + V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , int V_14 )
{
F_8 ( F_9 ( V_14 ) , V_2 -> V_19 + V_23 ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_24 ;
F_11 ( & V_10 -> V_25 ) ;
F_7 ( V_2 , V_14 ) ;
V_24 = F_12 ( & V_10 -> V_25 , V_26 ) ;
return V_24 ? 0 : - V_27 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_28 , int V_29 ,
T_1 V_30 )
{
struct V_31 * V_32 = V_2 -> V_14 [ 0 ] . V_33 ;
void * V_34 ;
T_2 V_35 ;
int V_24 ;
F_14 ( & V_2 -> V_36 ) ;
V_34 = F_15 ( NULL ,
V_29 ,
& V_35 , V_37 ) ;
if ( ! V_34 ) {
V_24 = - V_38 ;
goto V_39;
}
V_32 -> V_40 . V_41 = V_42 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = V_29 / 2 ;
V_32 -> V_49 = V_35 ;
V_32 -> V_50 = V_30 ;
memcpy ( V_34 , V_28 , V_29 ) ;
V_24 = F_10 ( & V_2 -> V_14 [ 0 ] ) ;
F_16 ( NULL , V_29 , V_34 , V_35 ) ;
V_39:
F_17 ( & V_2 -> V_36 ) ;
return V_24 ;
}
static void F_18 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
unsigned long V_51 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
V_51 = F_3 ( V_2 -> V_19 + V_52 ) ;
F_5 ( V_14 , & V_51 ) ;
F_6 ( V_51 , V_2 -> V_19 + V_52 ) ;
}
static void F_19 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
unsigned long V_51 ;
V_51 = F_3 ( V_2 -> V_19 + V_52 ) ;
F_4 ( V_14 , & V_51 ) ;
F_6 ( V_51 , V_2 -> V_19 + V_52 ) ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_31 * V_33 ;
while ( 1 ) {
V_33 = & V_10 -> V_33 [ V_10 -> V_53 ] ;
if ( V_33 -> V_40 . V_43 & V_44 )
break;
if ( V_33 -> V_40 . V_43 & V_54 )
V_10 -> V_43 = V_55 ;
else
V_10 -> V_43 = V_56 ;
V_33 -> V_40 . V_43 |= V_44 ;
V_10 -> V_53 ++ ;
V_10 -> V_53 %= V_10 -> V_57 ;
if ( V_10 -> V_58 . V_59 )
V_10 -> V_58 . V_59 ( V_10 -> V_58 . V_60 ) ;
}
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_31 * V_33 ;
int V_61 , error = 0 ;
V_10 -> V_62 = 0 ;
for ( V_61 = 0 ; V_61 < V_10 -> V_57 ; V_61 ++ ) {
V_33 = & V_10 -> V_33 [ V_61 ] ;
if ( V_33 -> V_40 . V_43 & ( V_44 | V_54 ) )
error = - V_63 ;
V_10 -> V_62 += V_33 -> V_40 . V_48 ;
}
if ( error )
V_10 -> V_43 = V_55 ;
else
V_10 -> V_43 = V_64 ;
F_22 ( & V_10 -> V_58 ) ;
if ( V_10 -> V_58 . V_59 )
V_10 -> V_58 . V_59 ( V_10 -> V_58 . V_60 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
F_24 ( & V_10 -> V_25 ) ;
if ( V_10 -> V_14 == 0 )
return;
if ( V_10 -> V_65 & V_66 )
F_20 ( V_10 ) ;
else
F_21 ( V_10 ) ;
}
static T_3 F_25 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
unsigned long V_69 ;
V_69 = F_3 ( V_2 -> V_19 + V_70 ) ;
F_6 ( V_69 , V_2 -> V_19 + V_70 ) ;
while ( V_69 ) {
int V_14 = F_26 ( V_69 ) - 1 ;
struct V_9 * V_10 = & V_2 -> V_14 [ V_14 ] ;
F_23 ( V_10 ) ;
F_4 ( V_14 , & V_69 ) ;
}
return V_71 ;
}
static void F_27 ( struct V_9 * V_10 ,
enum V_72 V_73 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_74 = 0 , V_75 = 0 ;
int V_76 = 0 , V_77 = 0 ;
V_10 -> V_78 = 0 ;
V_10 -> V_79 = 0 ;
switch ( V_73 ) {
case V_80 :
V_77 = V_2 -> V_81 -> V_82 ;
break;
case V_83 :
V_75 = V_2 -> V_81 -> V_84 ;
V_74 = V_2 -> V_81 -> V_85 ;
break;
case V_86 :
V_74 = V_2 -> V_81 -> V_87 ;
V_75 = V_2 -> V_81 -> V_88 ;
break;
case V_89 :
V_74 = V_2 -> V_81 -> V_90 ;
V_75 = V_2 -> V_81 -> V_91 ;
break;
case V_92 :
V_74 = V_2 -> V_81 -> V_93 ;
V_75 = V_2 -> V_81 -> V_94 ;
break;
case V_95 :
V_74 = V_2 -> V_81 -> V_96 ;
V_75 = V_2 -> V_81 -> V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
V_74 = V_2 -> V_81 -> V_101 ;
V_75 = V_2 -> V_81 -> V_91 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_74 = V_2 -> V_81 -> V_108 ;
V_75 = V_2 -> V_81 -> V_94 ;
break;
case V_109 :
V_74 = V_2 -> V_81 -> V_110 ;
V_75 = V_2 -> V_81 -> V_110 ;
V_76 = V_2 -> V_81 -> V_111 ;
break;
case V_112 :
V_74 = V_2 -> V_81 -> V_113 ;
V_75 = V_2 -> V_81 -> V_114 ;
break;
case V_115 :
V_74 = V_2 -> V_81 -> V_116 ;
break;
case V_117 :
V_74 = V_2 -> V_81 -> V_118 ;
V_75 = V_2 -> V_81 -> V_119 ;
break;
case V_120 :
V_75 = V_2 -> V_81 -> V_121 ;
break;
default:
break;
}
V_10 -> V_78 = V_74 ;
V_10 -> V_79 = V_75 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_122 ;
struct V_123 * V_124 = V_2 -> V_124 ;
struct V_31 * V_32 = V_2 -> V_14 [ 0 ] . V_33 ;
int V_24 ;
if ( V_10 -> V_125 == V_126 ) {
V_122 = V_10 -> V_78 ;
} else {
V_122 = V_10 -> V_79 ;
}
if ( V_122 < 0 )
return V_122 ;
F_29 ( V_2 -> V_127 , L_1 , V_122 ) ;
F_29 ( V_2 -> V_127 , L_2 , ( T_1 ) V_10 -> V_128 ) ;
F_29 ( V_2 -> V_127 , L_3 , V_10 -> V_129 ) ;
F_29 ( V_2 -> V_127 , L_4 , V_10 -> V_130 ) ;
F_29 ( V_2 -> V_127 , L_5 , ( T_1 ) V_10 -> V_131 [ 0 ] ) ;
F_29 ( V_2 -> V_127 , L_6 , ( T_1 ) V_10 -> V_131 [ 1 ] ) ;
F_14 ( & V_2 -> V_36 ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_132 . V_133 = V_122 ;
V_124 -> V_134 [ 0 ] = V_10 -> V_131 [ 1 ] ;
V_124 -> V_134 [ 1 ] = V_10 -> V_131 [ 0 ] ;
V_124 -> V_134 [ 2 ] = V_10 -> V_130 ;
V_124 -> V_134 [ 6 ] = V_10 -> V_129 ;
V_124 -> V_134 [ 7 ] = V_10 -> V_128 ;
V_32 -> V_40 . V_41 = V_135 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = sizeof( * V_124 ) / 4 ;
V_32 -> V_49 = V_2 -> V_136 ;
V_32 -> V_50 = 2048 + ( sizeof( * V_124 ) / 4 ) * V_14 ;
V_24 = F_10 ( & V_2 -> V_14 [ 0 ] ) ;
F_17 ( & V_2 -> V_36 ) ;
return V_24 ;
}
static void F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
F_6 ( F_9 ( V_14 ) , V_2 -> V_19 + V_137 ) ;
V_10 -> V_43 = V_55 ;
}
static int F_31 ( struct V_9 * V_10 )
{
int V_24 ;
F_30 ( V_10 ) ;
V_10 -> V_131 [ 0 ] = 0 ;
V_10 -> V_131 [ 1 ] = 0 ;
V_10 -> V_129 = 0 ;
V_10 -> V_130 = 0 ;
if ( V_10 -> V_138 ) {
if ( V_10 -> V_138 >= V_10 -> V_2 -> V_139 )
return - V_18 ;
F_18 ( V_10 , V_10 -> V_138 ) ;
}
switch ( V_10 -> V_73 ) {
case V_83 :
F_2 ( V_10 , false , true , true ) ;
break;
case V_80 :
F_2 ( V_10 , false , true , false ) ;
break;
default:
F_2 ( V_10 , true , true , false ) ;
break;
}
F_27 ( V_10 , V_10 -> V_73 ) ;
if ( ( V_10 -> V_73 != V_80 ) &&
( V_10 -> V_73 != V_83 ) ) {
if ( V_10 -> V_140 ) {
V_10 -> V_131 [ 1 ] = F_9 ( V_10 -> V_140 % 32 ) ;
if ( V_10 -> V_140 > 31 )
F_5 ( 31 , & V_10 -> V_128 ) ;
V_10 -> V_131 [ 0 ] = F_9 ( V_10 -> V_138 % 32 ) ;
if ( V_10 -> V_138 > 31 )
F_5 ( 30 , & V_10 -> V_128 ) ;
} else {
F_5 ( V_10 -> V_138 , V_10 -> V_131 ) ;
}
V_10 -> V_128 |= V_10 -> V_128 ;
V_10 -> V_129 = V_10 -> V_141 ;
} else {
V_10 -> V_128 = 0 ;
}
V_24 = F_28 ( V_10 ) ;
return V_24 ;
}
static int F_32 ( struct V_9 * V_10 ,
unsigned int V_142 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
if ( V_142 < V_143
|| V_142 > V_144 ) {
return - V_18 ;
}
F_6 ( V_142 , V_2 -> V_19 + V_145 + 4 * V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_24 = - V_146 ;
V_10 -> V_33 = F_15 ( NULL , V_147 , & V_10 -> V_148 , V_37 ) ;
if ( ! V_10 -> V_33 ) {
V_24 = - V_38 ;
goto V_149;
}
memset ( V_10 -> V_33 , 0 , V_147 ) ;
V_2 -> V_150 [ V_14 ] . V_151 = V_10 -> V_148 ;
V_2 -> V_150 [ V_14 ] . V_152 = V_10 -> V_148 ;
F_32 ( V_10 , V_153 ) ;
F_11 ( & V_10 -> V_25 ) ;
V_10 -> V_53 = 0 ;
return 0 ;
V_149:
return V_24 ;
}
static struct V_9 * F_34 ( struct V_154 * V_155 )
{
return F_35 ( V_155 , struct V_9 , V_155 ) ;
}
static T_4 F_36 ( struct V_156 * V_157 )
{
unsigned long V_65 ;
struct V_9 * V_10 = F_34 ( V_157 -> V_155 ) ;
T_4 V_158 ;
F_37 ( & V_10 -> V_159 , V_65 ) ;
V_158 = F_38 ( V_157 ) ;
F_39 ( & V_10 -> V_159 , V_65 ) ;
return V_158 ;
}
static int F_40 ( struct V_154 * V_155 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
struct V_160 * V_161 = V_155 -> V_162 ;
int V_163 , V_24 ;
if ( ! V_161 )
return - V_18 ;
switch ( V_161 -> V_142 ) {
case V_164 :
V_163 = 3 ;
break;
case V_165 :
V_163 = 2 ;
break;
case V_166 :
default:
V_163 = 1 ;
break;
}
V_10 -> V_73 = V_161 -> V_73 ;
V_10 -> V_138 = V_161 -> V_167 ;
F_41 ( V_10 -> V_2 -> V_168 ) ;
V_24 = F_33 ( V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_32 ( V_10 , V_163 ) ;
if ( V_24 )
return V_24 ;
F_42 ( & V_10 -> V_58 , V_155 ) ;
V_10 -> V_58 . V_169 = F_36 ;
V_10 -> V_58 . V_65 = V_170 ;
return 0 ;
}
static void F_43 ( struct V_154 * V_155 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_30 ( V_10 ) ;
if ( V_10 -> V_138 )
F_19 ( V_10 , V_10 -> V_138 ) ;
if ( V_10 -> V_140 )
F_19 ( V_10 , V_10 -> V_140 ) ;
V_10 -> V_138 = 0 ;
V_10 -> V_140 = 0 ;
F_32 ( V_10 , 0 ) ;
F_16 ( NULL , V_147 , V_10 -> V_33 , V_10 -> V_148 ) ;
F_44 ( V_2 -> V_168 ) ;
}
static struct V_156 * F_45 (
struct V_154 * V_155 , struct V_171 * V_172 ,
unsigned int V_173 , enum V_174 V_125 ,
unsigned long V_65 , void * V_124 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_24 , V_61 , V_48 ;
int V_14 = V_10 -> V_14 ;
struct V_171 * V_175 ;
if ( V_10 -> V_43 == V_56 )
return NULL ;
V_10 -> V_43 = V_56 ;
V_10 -> V_65 = 0 ;
F_29 ( V_2 -> V_127 , L_7 ,
V_173 , V_14 ) ;
V_10 -> V_125 = V_125 ;
V_24 = F_28 ( V_10 ) ;
if ( V_24 )
goto V_39;
if ( V_173 > V_176 ) {
F_46 ( V_2 -> V_127 , L_8 ,
V_14 , V_173 , V_176 ) ;
V_24 = - V_18 ;
goto V_39;
}
V_10 -> V_177 = 0 ;
F_47 (sgl, sg, sg_len, i) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_61 ] ;
int V_178 ;
V_33 -> V_49 = V_175 -> V_179 ;
V_48 = V_175 -> V_180 ;
if ( V_48 > 0xffff ) {
F_46 ( V_2 -> V_127 , L_9 ,
V_14 , V_48 , 0xffff ) ;
V_24 = - V_18 ;
goto V_39;
}
V_33 -> V_40 . V_48 = V_48 ;
V_10 -> V_177 += V_48 ;
if ( V_10 -> V_181 > V_182 ) {
V_24 = - V_18 ;
goto V_39;
}
switch ( V_10 -> V_181 ) {
case V_182 :
V_33 -> V_40 . V_41 = 0 ;
if ( V_48 & 3 || V_175 -> V_179 & 3 )
return NULL ;
break;
case V_183 :
V_33 -> V_40 . V_41 = 2 ;
if ( V_48 & 1 || V_175 -> V_179 & 1 )
return NULL ;
break;
case V_184 :
V_33 -> V_40 . V_41 = 1 ;
break;
default:
return NULL ;
}
V_178 = V_44 | V_47 | V_185 ;
if ( V_61 + 1 == V_173 ) {
V_178 |= V_45 ;
V_178 |= V_186 ;
V_178 &= ~ V_185 ;
}
F_29 ( V_2 -> V_127 , L_10 ,
V_61 , V_48 , V_175 -> V_179 ,
V_178 & V_46 ? L_11 : L_12 ,
V_178 & V_45 ? L_13 : L_12 ) ;
V_33 -> V_40 . V_43 = V_178 ;
}
V_10 -> V_57 = V_173 ;
V_2 -> V_150 [ V_14 ] . V_152 = V_10 -> V_148 ;
return & V_10 -> V_58 ;
V_39:
V_10 -> V_43 = V_55 ;
return NULL ;
}
static struct V_156 * F_48 (
struct V_154 * V_155 , T_2 V_187 , T_5 V_188 ,
T_5 V_189 , enum V_174 V_125 ,
void * V_124 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_190 = V_188 / V_189 ;
int V_14 = V_10 -> V_14 ;
int V_24 , V_61 = 0 , V_28 = 0 ;
F_29 ( V_2 -> V_127 , L_14 , V_191 , V_14 ) ;
if ( V_10 -> V_43 == V_56 )
return NULL ;
V_10 -> V_43 = V_56 ;
V_10 -> V_65 |= V_66 ;
V_10 -> V_125 = V_125 ;
V_24 = F_28 ( V_10 ) ;
if ( V_24 )
goto V_39;
if ( V_190 > V_176 ) {
F_46 ( V_2 -> V_127 , L_8 ,
V_14 , V_190 , V_176 ) ;
goto V_39;
}
if ( V_189 > 0xffff ) {
F_46 ( V_2 -> V_127 , L_15 ,
V_14 , V_189 , 0xffff ) ;
goto V_39;
}
while ( V_28 < V_188 ) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_61 ] ;
int V_178 ;
V_33 -> V_49 = V_187 ;
V_33 -> V_40 . V_48 = V_189 ;
if ( V_10 -> V_181 > V_182 )
goto V_39;
if ( V_10 -> V_181 == V_182 )
V_33 -> V_40 . V_41 = 0 ;
else
V_33 -> V_40 . V_41 = V_10 -> V_181 ;
V_178 = V_44 | V_47 | V_185 | V_45 ;
if ( V_61 + 1 == V_190 )
V_178 |= V_46 ;
F_29 ( V_2 -> V_127 , L_10 ,
V_61 , V_189 , V_187 ,
V_178 & V_46 ? L_11 : L_12 ,
V_178 & V_45 ? L_13 : L_12 ) ;
V_33 -> V_40 . V_43 = V_178 ;
V_187 += V_189 ;
V_28 += V_189 ;
V_61 ++ ;
}
V_10 -> V_57 = V_190 ;
V_2 -> V_150 [ V_14 ] . V_152 = V_10 -> V_148 ;
return & V_10 -> V_58 ;
V_39:
V_10 -> V_43 = V_55 ;
return NULL ;
}
static int F_49 ( struct V_154 * V_155 , enum V_192 V_193 ,
unsigned long V_194 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
struct V_195 * V_196 = ( void * ) V_194 ;
switch ( V_193 ) {
case V_197 :
F_30 ( V_10 ) ;
return 0 ;
case V_198 :
if ( V_196 -> V_125 == V_126 ) {
V_10 -> V_141 = V_196 -> V_199 ;
V_10 -> V_128 = V_196 -> V_200 *
V_196 -> V_201 ;
V_10 -> V_181 = V_196 -> V_201 ;
} else {
V_10 -> V_141 = V_196 -> V_202 ;
V_10 -> V_128 = V_196 -> V_203 *
V_196 -> V_204 ;
V_10 -> V_181 = V_196 -> V_204 ;
}
V_10 -> V_125 = V_196 -> V_125 ;
return F_31 ( V_10 ) ;
default:
return - V_205 ;
}
return - V_18 ;
}
static enum V_206 F_50 ( struct V_154 * V_155 ,
T_4 V_158 ,
struct V_207 * V_208 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
T_4 V_209 ;
V_209 = V_155 -> V_158 ;
F_51 ( V_208 , V_155 -> V_210 , V_209 ,
V_10 -> V_177 - V_10 -> V_62 ) ;
return V_10 -> V_43 ;
}
static void F_52 ( struct V_154 * V_155 )
{
struct V_9 * V_10 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_43 == V_56 )
F_7 ( V_2 , V_10 -> V_14 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
const struct V_211 * V_212 )
{
T_6 * V_213 = ( T_1 * ) V_212 ;
T_6 * V_214 = ( T_1 * ) V_2 -> V_81 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_215 ; V_61 ++ )
if ( V_213 [ V_61 ] > 0 )
V_214 [ V_61 ] = V_213 [ V_61 ] ;
}
static void F_54 ( const struct V_216 * V_217 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
const struct V_218 * V_219 ;
const struct V_211 * V_212 ;
unsigned short * V_220 ;
if ( ! V_217 ) {
F_46 ( V_2 -> V_127 , L_16 ) ;
return;
}
if ( V_217 -> V_29 < sizeof( * V_219 ) )
goto V_221;
V_219 = (struct V_218 * ) V_217 -> V_161 ;
if ( V_219 -> V_222 != V_223 )
goto V_221;
if ( V_219 -> V_224 + V_219 -> V_225 > V_217 -> V_29 )
goto V_221;
V_212 = ( void * ) V_219 + V_219 -> V_226 ;
V_220 = ( void * ) V_219 + V_219 -> V_224 ;
F_41 ( V_2 -> V_168 ) ;
F_13 ( V_2 , V_220 ,
V_219 -> V_225 ,
V_212 -> V_227 ) ;
F_44 ( V_2 -> V_168 ) ;
F_53 ( V_2 , V_212 ) ;
F_55 ( V_2 -> V_127 , L_17 ,
V_219 -> V_228 ,
V_219 -> V_229 ) ;
V_221:
F_56 ( V_217 ) ;
}
static int T_7 F_57 ( struct V_1 * V_2 ,
const char * V_230 )
{
int V_24 ;
V_24 = F_58 ( V_231 ,
V_232 , V_230 , V_2 -> V_127 ,
V_37 , V_2 , F_54 ) ;
return V_24 ;
}
static int T_7 F_59 ( struct V_1 * V_2 )
{
int V_61 , V_24 ;
T_2 V_233 ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_139 = 32 ;
break;
case V_234 :
V_2 -> V_139 = 48 ;
break;
default:
F_46 ( V_2 -> V_127 , L_18 ,
V_2 -> V_5 ) ;
return - V_235 ;
}
F_41 ( V_2 -> V_168 ) ;
F_6 ( 0 , V_2 -> V_19 + V_236 ) ;
V_2 -> V_150 = F_15 ( NULL ,
V_237 * sizeof ( struct V_238 ) +
sizeof( struct V_123 ) ,
& V_233 , V_37 ) ;
if ( ! V_2 -> V_150 ) {
V_24 = - V_38 ;
goto V_239;
}
V_2 -> V_124 = ( void * ) V_2 -> V_150 +
V_237 * sizeof ( struct V_238 ) ;
V_2 -> V_136 = V_233 +
V_237 * sizeof ( struct V_238 ) ;
memset ( V_2 -> V_150 , 0 ,
V_237 * sizeof ( struct V_238 ) ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_139 ; V_61 ++ )
F_6 ( 0 , V_2 -> V_19 + F_1 ( V_2 , V_61 ) ) ;
for ( V_61 = 0 ; V_61 < V_237 ; V_61 ++ )
F_6 ( 0 , V_2 -> V_19 + V_145 + V_61 * 4 ) ;
V_24 = F_33 ( & V_2 -> V_14 [ 0 ] ) ;
if ( V_24 )
goto V_239;
F_2 ( & V_2 -> V_14 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_19 + V_240 ) ;
F_6 ( 0 , V_2 -> V_19 + V_241 ) ;
F_6 ( V_233 , V_2 -> V_19 + V_236 ) ;
F_6 ( V_242 , V_2 -> V_19 + V_241 ) ;
F_32 ( & V_2 -> V_14 [ 0 ] , 7 ) ;
F_44 ( V_2 -> V_168 ) ;
return 0 ;
V_239:
F_44 ( V_2 -> V_168 ) ;
F_46 ( V_2 -> V_127 , L_19 , V_24 ) ;
return V_24 ;
}
static int T_7 F_60 ( struct V_243 * V_244 )
{
const struct V_245 * V_246 =
F_61 ( V_247 , & V_244 -> V_127 ) ;
struct V_248 * V_249 = V_244 -> V_127 . V_250 ;
const char * V_230 ;
int V_24 ;
int V_67 ;
struct V_251 * V_252 ;
struct V_253 * V_254 = V_244 -> V_127 . V_255 ;
int V_61 ;
struct V_1 * V_2 ;
T_6 * V_214 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
F_63 ( & V_2 -> V_36 ) ;
V_2 -> V_127 = & V_244 -> V_127 ;
V_252 = F_64 ( V_244 , V_256 , 0 ) ;
V_67 = F_65 ( V_244 , 0 ) ;
if ( ! V_252 || V_67 < 0 ) {
V_24 = - V_18 ;
goto V_257;
}
if ( ! F_66 ( V_252 -> V_258 , F_67 ( V_252 ) , V_244 -> V_259 ) ) {
V_24 = - V_146 ;
goto V_260;
}
V_2 -> V_168 = F_68 ( & V_244 -> V_127 , NULL ) ;
if ( F_69 ( V_2 -> V_168 ) ) {
V_24 = F_70 ( V_2 -> V_168 ) ;
goto V_261;
}
V_2 -> V_19 = F_71 ( V_252 -> V_258 , F_67 ( V_252 ) ) ;
if ( ! V_2 -> V_19 ) {
V_24 = - V_38 ;
goto V_262;
}
V_24 = F_72 ( V_67 , F_25 , 0 , L_20 , V_2 ) ;
if ( V_24 )
goto V_263;
V_2 -> V_81 = F_62 ( sizeof( * V_2 -> V_81 ) , V_37 ) ;
if ( ! V_2 -> V_81 ) {
V_24 = - V_38 ;
goto V_264;
}
V_214 = ( T_6 * ) V_2 -> V_81 ;
for ( V_61 = 0 ; V_61 < V_215 ; V_61 ++ )
V_214 [ V_61 ] = - V_18 ;
if ( V_246 )
V_244 -> V_265 = V_246 -> V_161 ;
V_2 -> V_5 = V_244 -> V_265 -> V_266 ;
F_73 ( V_267 , V_2 -> V_268 . V_269 ) ;
F_73 ( V_270 , V_2 -> V_268 . V_269 ) ;
F_74 ( & V_2 -> V_268 . V_271 ) ;
for ( V_61 = 0 ; V_61 < V_237 ; V_61 ++ ) {
struct V_9 * V_10 = & V_2 -> V_14 [ V_61 ] ;
V_10 -> V_2 = V_2 ;
F_75 ( & V_10 -> V_159 ) ;
V_10 -> V_155 . V_272 = & V_2 -> V_268 ;
F_76 ( & V_10 -> V_155 ) ;
V_10 -> V_14 = V_61 ;
if ( V_61 )
F_77 ( & V_10 -> V_155 . V_248 ,
& V_2 -> V_268 . V_271 ) ;
}
V_24 = F_59 ( V_2 ) ;
if ( V_24 )
goto V_273;
if ( V_254 && V_254 -> V_81 )
F_53 ( V_2 , V_254 -> V_81 ) ;
if ( V_254 ) {
V_24 = F_57 ( V_2 , V_254 -> V_230 ) ;
if ( V_24 )
F_78 ( & V_244 -> V_127 , L_21 ) ;
} else {
V_24 = F_79 ( V_249 , L_22 ,
& V_230 ) ;
if ( V_24 )
F_78 ( & V_244 -> V_127 , L_23 ) ;
else {
V_24 = F_57 ( V_2 , V_230 ) ;
if ( V_24 )
F_78 ( & V_244 -> V_127 , L_24 ) ;
}
}
V_2 -> V_268 . V_127 = & V_244 -> V_127 ;
V_2 -> V_268 . V_274 = F_40 ;
V_2 -> V_268 . V_275 = F_43 ;
V_2 -> V_268 . V_276 = F_50 ;
V_2 -> V_268 . V_277 = F_45 ;
V_2 -> V_268 . V_278 = F_48 ;
V_2 -> V_268 . V_279 = F_49 ;
V_2 -> V_268 . V_280 = F_52 ;
V_2 -> V_268 . V_127 -> V_281 = & V_2 -> V_281 ;
F_80 ( V_2 -> V_268 . V_127 , 65535 ) ;
V_24 = F_81 ( & V_2 -> V_268 ) ;
if ( V_24 ) {
F_46 ( & V_244 -> V_127 , L_25 ) ;
goto V_273;
}
F_55 ( V_2 -> V_127 , L_26 ) ;
return 0 ;
V_273:
F_82 ( V_2 -> V_81 ) ;
V_264:
F_83 ( V_67 , V_2 ) ;
V_263:
F_84 ( V_2 -> V_19 ) ;
V_262:
F_85 ( V_2 -> V_168 ) ;
V_261:
F_86 ( V_252 -> V_258 , F_67 ( V_252 ) ) ;
V_260:
V_257:
F_82 ( V_2 ) ;
return V_24 ;
}
static int T_8 F_87 ( struct V_243 * V_244 )
{
return - V_146 ;
}
static int T_7 F_88 ( void )
{
return F_89 ( & V_282 , F_60 ) ;
}
