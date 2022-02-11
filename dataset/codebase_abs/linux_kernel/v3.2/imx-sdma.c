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
T_1 V_15 , V_16 , V_17 ;
if ( V_11 && V_12 && V_13 )
return - V_18 ;
V_15 = F_3 ( V_2 -> V_19 + V_20 ) ;
V_16 = F_3 ( V_2 -> V_19 + V_21 ) ;
V_17 = F_3 ( V_2 -> V_19 + V_22 ) ;
if ( V_13 )
V_17 &= ~ ( 1 << V_14 ) ;
else
V_17 |= ( 1 << V_14 ) ;
if ( V_11 )
V_15 &= ~ ( 1 << V_14 ) ;
else
V_15 |= ( 1 << V_14 ) ;
if ( V_12 )
V_16 &= ~ ( 1 << V_14 ) ;
else
V_16 |= ( 1 << V_14 ) ;
F_4 ( V_15 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_16 , V_2 -> V_19 + V_21 ) ;
F_4 ( V_17 , V_2 -> V_19 + V_22 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_23 ;
F_6 ( & V_10 -> V_24 ) ;
F_4 ( 1 << V_14 , V_2 -> V_19 + V_25 ) ;
V_23 = F_7 ( & V_10 -> V_24 , V_26 ) ;
return V_23 ? 0 : - V_27 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_28 , int V_29 ,
T_1 V_30 )
{
struct V_31 * V_32 = V_2 -> V_14 [ 0 ] . V_33 ;
void * V_34 ;
T_2 V_35 ;
int V_23 ;
F_9 ( & V_2 -> V_36 ) ;
V_34 = F_10 ( NULL ,
V_29 ,
& V_35 , V_37 ) ;
if ( ! V_34 ) {
V_23 = - V_38 ;
goto V_39;
}
V_32 -> V_40 . V_41 = V_42 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = V_29 / 2 ;
V_32 -> V_49 = V_35 ;
V_32 -> V_50 = V_30 ;
memcpy ( V_34 , V_28 , V_29 ) ;
V_23 = F_5 ( & V_2 -> V_14 [ 0 ] ) ;
F_11 ( NULL , V_29 , V_34 , V_35 ) ;
V_39:
F_12 ( & V_2 -> V_36 ) ;
return V_23 ;
}
static void F_13 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
T_1 V_51 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
V_51 = F_3 ( V_2 -> V_19 + V_52 ) ;
V_51 |= ( 1 << V_14 ) ;
F_4 ( V_51 , V_2 -> V_19 + V_52 ) ;
}
static void F_14 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
T_1 V_51 ;
V_51 = F_3 ( V_2 -> V_19 + V_52 ) ;
V_51 &= ~ ( 1 << V_14 ) ;
F_4 ( V_51 , V_2 -> V_19 + V_52 ) ;
}
static void F_15 ( struct V_9 * V_10 )
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
static void F_16 ( struct V_9 * V_10 )
{
struct V_31 * V_33 ;
int V_61 , error = 0 ;
for ( V_61 = 0 ; V_61 < V_10 -> V_57 ; V_61 ++ ) {
V_33 = & V_10 -> V_33 [ V_61 ] ;
if ( V_33 -> V_40 . V_43 & ( V_44 | V_54 ) )
error = - V_62 ;
}
if ( error )
V_10 -> V_43 = V_55 ;
else
V_10 -> V_43 = V_63 ;
if ( V_10 -> V_58 . V_59 )
V_10 -> V_58 . V_59 ( V_10 -> V_58 . V_60 ) ;
V_10 -> V_64 = V_10 -> V_58 . V_65 ;
}
static void F_17 ( struct V_9 * V_10 )
{
F_18 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_14 == 0 )
return;
if ( V_10 -> V_66 & V_67 )
F_15 ( V_10 ) ;
else
F_16 ( V_10 ) ;
}
static T_3 F_19 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
T_1 V_70 ;
V_70 = F_3 ( V_2 -> V_19 + V_71 ) ;
F_4 ( V_70 , V_2 -> V_19 + V_71 ) ;
while ( V_70 ) {
int V_14 = F_20 ( V_70 ) - 1 ;
struct V_9 * V_10 = & V_2 -> V_14 [ V_14 ] ;
F_17 ( V_10 ) ;
V_70 &= ~ ( 1 << V_14 ) ;
}
return V_72 ;
}
static void F_21 ( struct V_9 * V_10 ,
enum V_73 V_74 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_75 = 0 , V_76 = 0 ;
int V_77 = 0 , V_78 = 0 ;
V_10 -> V_79 = 0 ;
V_10 -> V_80 = 0 ;
switch ( V_74 ) {
case V_81 :
V_78 = V_2 -> V_82 -> V_83 ;
break;
case V_84 :
V_76 = V_2 -> V_82 -> V_85 ;
V_75 = V_2 -> V_82 -> V_86 ;
break;
case V_87 :
V_75 = V_2 -> V_82 -> V_88 ;
V_76 = V_2 -> V_82 -> V_89 ;
break;
case V_90 :
V_75 = V_2 -> V_82 -> V_91 ;
V_76 = V_2 -> V_82 -> V_92 ;
break;
case V_93 :
V_75 = V_2 -> V_82 -> V_94 ;
V_76 = V_2 -> V_82 -> V_95 ;
break;
case V_96 :
V_75 = V_2 -> V_82 -> V_97 ;
V_76 = V_2 -> V_82 -> V_98 ;
break;
case V_99 :
case V_100 :
case V_101 :
V_75 = V_2 -> V_82 -> V_102 ;
V_76 = V_2 -> V_82 -> V_92 ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_75 = V_2 -> V_82 -> V_109 ;
V_76 = V_2 -> V_82 -> V_95 ;
break;
case V_110 :
V_75 = V_2 -> V_82 -> V_111 ;
V_76 = V_2 -> V_82 -> V_111 ;
V_77 = V_2 -> V_82 -> V_112 ;
break;
case V_113 :
V_75 = V_2 -> V_82 -> V_114 ;
V_76 = V_2 -> V_82 -> V_115 ;
break;
case V_116 :
V_75 = V_2 -> V_82 -> V_117 ;
break;
case V_118 :
V_75 = V_2 -> V_82 -> V_119 ;
V_76 = V_2 -> V_82 -> V_120 ;
break;
case V_121 :
V_76 = V_2 -> V_82 -> V_122 ;
break;
default:
break;
}
V_10 -> V_79 = V_75 ;
V_10 -> V_80 = V_76 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_123 ;
struct V_124 * V_125 = V_2 -> V_125 ;
struct V_31 * V_32 = V_2 -> V_14 [ 0 ] . V_33 ;
int V_23 ;
if ( V_10 -> V_126 == V_127 ) {
V_123 = V_10 -> V_79 ;
} else {
V_123 = V_10 -> V_80 ;
}
if ( V_123 < 0 )
return V_123 ;
F_23 ( V_2 -> V_128 , L_1 , V_123 ) ;
F_23 ( V_2 -> V_128 , L_2 , V_10 -> V_129 ) ;
F_23 ( V_2 -> V_128 , L_3 , V_10 -> V_130 ) ;
F_23 ( V_2 -> V_128 , L_4 , V_10 -> V_131 ) ;
F_23 ( V_2 -> V_128 , L_5 , V_10 -> V_132 ) ;
F_23 ( V_2 -> V_128 , L_6 , V_10 -> V_133 ) ;
F_9 ( & V_2 -> V_36 ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> V_134 . V_135 = V_123 ;
V_125 -> V_136 [ 0 ] = V_10 -> V_133 ;
V_125 -> V_136 [ 1 ] = V_10 -> V_132 ;
V_125 -> V_136 [ 2 ] = V_10 -> V_131 ;
V_125 -> V_136 [ 6 ] = V_10 -> V_130 ;
V_125 -> V_136 [ 7 ] = V_10 -> V_129 ;
V_32 -> V_40 . V_41 = V_137 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = sizeof( * V_125 ) / 4 ;
V_32 -> V_49 = V_2 -> V_138 ;
V_32 -> V_50 = 2048 + ( sizeof( * V_125 ) / 4 ) * V_14 ;
V_23 = F_5 ( & V_2 -> V_14 [ 0 ] ) ;
F_12 ( & V_2 -> V_36 ) ;
return V_23 ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
F_4 ( 1 << V_14 , V_2 -> V_19 + V_139 ) ;
V_10 -> V_43 = V_55 ;
}
static int F_25 ( struct V_9 * V_10 )
{
int V_23 ;
F_24 ( V_10 ) ;
V_10 -> V_132 = 0 ;
V_10 -> V_133 = 0 ;
V_10 -> V_130 = 0 ;
V_10 -> V_131 = 0 ;
if ( V_10 -> V_140 ) {
if ( V_10 -> V_140 > 32 )
return - V_18 ;
F_13 ( V_10 , V_10 -> V_140 ) ;
}
switch ( V_10 -> V_74 ) {
case V_84 :
F_2 ( V_10 , false , true , true ) ;
break;
case V_81 :
F_2 ( V_10 , false , true , false ) ;
break;
default:
F_2 ( V_10 , true , true , false ) ;
break;
}
F_21 ( V_10 , V_10 -> V_74 ) ;
if ( ( V_10 -> V_74 != V_81 ) &&
( V_10 -> V_74 != V_84 ) ) {
if ( V_10 -> V_141 ) {
V_10 -> V_133 = 1 << ( V_10 -> V_141 % 32 ) ;
if ( V_10 -> V_141 > 31 )
V_10 -> V_129 |= 1 << 31 ;
V_10 -> V_132 = 1 << ( V_10 -> V_140 % 32 ) ;
if ( V_10 -> V_140 > 31 )
V_10 -> V_129 |= 1 << 30 ;
} else {
V_10 -> V_132 = 1 << V_10 -> V_140 ;
V_10 -> V_133 = 1 << ( V_10 -> V_140 - 32 ) ;
}
V_10 -> V_129 |= V_10 -> V_129 ;
V_10 -> V_130 = V_10 -> V_142 ;
} else {
V_10 -> V_129 = 0 ;
}
V_23 = F_22 ( V_10 ) ;
return V_23 ;
}
static int F_26 ( struct V_9 * V_10 ,
unsigned int V_143 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
if ( V_143 < V_144
|| V_143 > V_145 ) {
return - V_18 ;
}
F_4 ( V_143 , V_2 -> V_19 + V_146 + 4 * V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_23 = - V_147 ;
V_10 -> V_33 = F_10 ( NULL , V_148 , & V_10 -> V_149 , V_37 ) ;
if ( ! V_10 -> V_33 ) {
V_23 = - V_38 ;
goto V_150;
}
memset ( V_10 -> V_33 , 0 , V_148 ) ;
V_2 -> V_151 [ V_14 ] . V_152 = V_10 -> V_149 ;
V_2 -> V_151 [ V_14 ] . V_153 = V_10 -> V_149 ;
F_28 ( V_2 -> V_154 ) ;
F_26 ( V_10 , V_155 ) ;
F_6 ( & V_10 -> V_24 ) ;
V_10 -> V_53 = 0 ;
return 0 ;
V_150:
return V_23 ;
}
static void F_29 ( struct V_1 * V_2 , int V_14 )
{
F_4 ( 1 << V_14 , V_2 -> V_19 + V_25 ) ;
}
static T_4 F_30 ( struct V_9 * V_10 )
{
T_4 V_65 = V_10 -> V_156 . V_65 ;
if ( ++ V_65 < 0 )
V_65 = 1 ;
V_10 -> V_156 . V_65 = V_65 ;
V_10 -> V_58 . V_65 = V_65 ;
return V_65 ;
}
static struct V_9 * F_31 ( struct V_157 * V_156 )
{
return F_32 ( V_156 , struct V_9 , V_156 ) ;
}
static T_4 F_33 ( struct V_158 * V_159 )
{
struct V_9 * V_10 = F_31 ( V_159 -> V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_4 V_65 ;
F_34 ( & V_10 -> V_160 ) ;
V_65 = F_30 ( V_10 ) ;
F_29 ( V_2 , V_10 -> V_14 ) ;
F_35 ( & V_10 -> V_160 ) ;
return V_65 ;
}
static int F_36 ( struct V_157 * V_156 )
{
struct V_9 * V_10 = F_31 ( V_156 ) ;
struct V_161 * V_162 = V_156 -> V_163 ;
int V_164 , V_23 ;
if ( ! V_162 )
return - V_18 ;
switch ( V_162 -> V_143 ) {
case V_165 :
V_164 = 3 ;
break;
case V_166 :
V_164 = 2 ;
break;
case V_167 :
default:
V_164 = 1 ;
break;
}
V_10 -> V_74 = V_162 -> V_74 ;
V_10 -> V_140 = V_162 -> V_168 ;
V_23 = F_26 ( V_10 , V_164 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_27 ( V_10 ) ;
if ( V_23 )
return V_23 ;
F_37 ( & V_10 -> V_58 , V_156 ) ;
V_10 -> V_58 . V_169 = F_33 ;
V_10 -> V_58 . V_66 = V_170 ;
return 0 ;
}
static void F_38 ( struct V_157 * V_156 )
{
struct V_9 * V_10 = F_31 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_24 ( V_10 ) ;
if ( V_10 -> V_140 )
F_14 ( V_10 , V_10 -> V_140 ) ;
if ( V_10 -> V_141 )
F_14 ( V_10 , V_10 -> V_141 ) ;
V_10 -> V_140 = 0 ;
V_10 -> V_141 = 0 ;
F_26 ( V_10 , 0 ) ;
F_11 ( NULL , V_148 , V_10 -> V_33 , V_10 -> V_149 ) ;
F_39 ( V_2 -> V_154 ) ;
}
static struct V_158 * F_40 (
struct V_157 * V_156 , struct V_171 * V_172 ,
unsigned int V_173 , enum V_174 V_126 ,
unsigned long V_66 )
{
struct V_9 * V_10 = F_31 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_23 , V_61 , V_48 ;
int V_14 = V_10 -> V_14 ;
struct V_171 * V_175 ;
if ( V_10 -> V_43 == V_56 )
return NULL ;
V_10 -> V_43 = V_56 ;
V_10 -> V_66 = 0 ;
F_23 ( V_2 -> V_128 , L_7 ,
V_173 , V_14 ) ;
V_10 -> V_126 = V_126 ;
V_23 = F_22 ( V_10 ) ;
if ( V_23 )
goto V_39;
if ( V_173 > V_176 ) {
F_41 ( V_2 -> V_128 , L_8 ,
V_14 , V_173 , V_176 ) ;
V_23 = - V_18 ;
goto V_39;
}
F_42 (sgl, sg, sg_len, i) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_61 ] ;
int V_177 ;
V_33 -> V_49 = V_175 -> V_178 ;
V_48 = V_175 -> V_179 ;
if ( V_48 > 0xffff ) {
F_41 ( V_2 -> V_128 , L_9 ,
V_14 , V_48 , 0xffff ) ;
V_23 = - V_18 ;
goto V_39;
}
V_33 -> V_40 . V_48 = V_48 ;
if ( V_10 -> V_180 > V_181 ) {
V_23 = - V_18 ;
goto V_39;
}
switch ( V_10 -> V_180 ) {
case V_181 :
V_33 -> V_40 . V_41 = 0 ;
if ( V_48 & 3 || V_175 -> V_178 & 3 )
return NULL ;
break;
case V_182 :
V_33 -> V_40 . V_41 = 2 ;
if ( V_48 & 1 || V_175 -> V_178 & 1 )
return NULL ;
break;
case V_183 :
V_33 -> V_40 . V_41 = 1 ;
break;
default:
return NULL ;
}
V_177 = V_44 | V_47 | V_184 ;
if ( V_61 + 1 == V_173 ) {
V_177 |= V_45 ;
V_177 |= V_185 ;
V_177 &= ~ V_184 ;
}
F_23 ( V_2 -> V_128 , L_10 ,
V_61 , V_48 , V_175 -> V_178 ,
V_177 & V_46 ? L_11 : L_12 ,
V_177 & V_45 ? L_13 : L_12 ) ;
V_33 -> V_40 . V_43 = V_177 ;
}
V_10 -> V_57 = V_173 ;
V_2 -> V_151 [ V_14 ] . V_153 = V_10 -> V_149 ;
return & V_10 -> V_58 ;
V_39:
V_10 -> V_43 = V_55 ;
return NULL ;
}
static struct V_158 * F_43 (
struct V_157 * V_156 , T_2 V_186 , T_5 V_187 ,
T_5 V_188 , enum V_174 V_126 )
{
struct V_9 * V_10 = F_31 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_189 = V_187 / V_188 ;
int V_14 = V_10 -> V_14 ;
int V_23 , V_61 = 0 , V_28 = 0 ;
F_23 ( V_2 -> V_128 , L_14 , V_190 , V_14 ) ;
if ( V_10 -> V_43 == V_56 )
return NULL ;
V_10 -> V_43 = V_56 ;
V_10 -> V_66 |= V_67 ;
V_10 -> V_126 = V_126 ;
V_23 = F_22 ( V_10 ) ;
if ( V_23 )
goto V_39;
if ( V_189 > V_176 ) {
F_41 ( V_2 -> V_128 , L_8 ,
V_14 , V_189 , V_176 ) ;
goto V_39;
}
if ( V_188 > 0xffff ) {
F_41 ( V_2 -> V_128 , L_15 ,
V_14 , V_188 , 0xffff ) ;
goto V_39;
}
while ( V_28 < V_187 ) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_61 ] ;
int V_177 ;
V_33 -> V_49 = V_186 ;
V_33 -> V_40 . V_48 = V_188 ;
if ( V_10 -> V_180 > V_181 )
goto V_39;
if ( V_10 -> V_180 == V_181 )
V_33 -> V_40 . V_41 = 0 ;
else
V_33 -> V_40 . V_41 = V_10 -> V_180 ;
V_177 = V_44 | V_47 | V_184 | V_45 ;
if ( V_61 + 1 == V_189 )
V_177 |= V_46 ;
F_23 ( V_2 -> V_128 , L_10 ,
V_61 , V_188 , V_186 ,
V_177 & V_46 ? L_11 : L_12 ,
V_177 & V_45 ? L_13 : L_12 ) ;
V_33 -> V_40 . V_43 = V_177 ;
V_186 += V_188 ;
V_28 += V_188 ;
V_61 ++ ;
}
V_10 -> V_57 = V_189 ;
V_2 -> V_151 [ V_14 ] . V_153 = V_10 -> V_149 ;
return & V_10 -> V_58 ;
V_39:
V_10 -> V_43 = V_55 ;
return NULL ;
}
static int F_44 ( struct V_157 * V_156 , enum V_191 V_192 ,
unsigned long V_193 )
{
struct V_9 * V_10 = F_31 ( V_156 ) ;
struct V_194 * V_195 = ( void * ) V_193 ;
switch ( V_192 ) {
case V_196 :
F_24 ( V_10 ) ;
return 0 ;
case V_197 :
if ( V_195 -> V_126 == V_127 ) {
V_10 -> V_142 = V_195 -> V_198 ;
V_10 -> V_129 = V_195 -> V_199 ;
V_10 -> V_180 = V_195 -> V_200 ;
} else {
V_10 -> V_142 = V_195 -> V_201 ;
V_10 -> V_129 = V_195 -> V_202 ;
V_10 -> V_180 = V_195 -> V_203 ;
}
return F_25 ( V_10 ) ;
default:
return - V_204 ;
}
return - V_18 ;
}
static enum V_205 F_45 ( struct V_157 * V_156 ,
T_4 V_65 ,
struct V_206 * V_207 )
{
struct V_9 * V_10 = F_31 ( V_156 ) ;
T_4 V_208 ;
V_208 = V_156 -> V_65 ;
F_46 ( V_207 , V_10 -> V_64 , V_208 , 0 ) ;
return V_10 -> V_43 ;
}
static void F_47 ( struct V_157 * V_156 )
{
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_209 * V_210 )
{
T_6 * V_211 = ( T_1 * ) V_210 ;
T_6 * V_212 = ( T_1 * ) V_2 -> V_82 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_213 ; V_61 ++ )
if ( V_211 [ V_61 ] > 0 )
V_212 [ V_61 ] = V_211 [ V_61 ] ;
}
static void F_49 ( const struct V_214 * V_215 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
const struct V_216 * V_217 ;
const struct V_209 * V_210 ;
unsigned short * V_218 ;
if ( ! V_215 ) {
F_41 ( V_2 -> V_128 , L_16 ) ;
return;
}
if ( V_215 -> V_29 < sizeof( * V_217 ) )
goto V_219;
V_217 = (struct V_216 * ) V_215 -> V_162 ;
if ( V_217 -> V_220 != V_221 )
goto V_219;
if ( V_217 -> V_222 + V_217 -> V_223 > V_215 -> V_29 )
goto V_219;
V_210 = ( void * ) V_217 + V_217 -> V_224 ;
V_218 = ( void * ) V_217 + V_217 -> V_222 ;
F_28 ( V_2 -> V_154 ) ;
F_8 ( V_2 , V_218 ,
V_217 -> V_223 ,
V_210 -> V_225 ) ;
F_39 ( V_2 -> V_154 ) ;
F_48 ( V_2 , V_210 ) ;
F_50 ( V_2 -> V_128 , L_17 ,
V_217 -> V_226 ,
V_217 -> V_227 ) ;
V_219:
F_51 ( V_215 ) ;
}
static int T_7 F_52 ( struct V_1 * V_2 ,
const char * V_228 )
{
int V_23 ;
V_23 = F_53 ( V_229 ,
V_230 , V_228 , V_2 -> V_128 ,
V_37 , V_2 , F_49 ) ;
return V_23 ;
}
static int T_7 F_54 ( struct V_1 * V_2 )
{
int V_61 , V_23 ;
T_2 V_231 ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_232 = 32 ;
break;
case V_233 :
V_2 -> V_232 = 48 ;
break;
default:
F_41 ( V_2 -> V_128 , L_18 ,
V_2 -> V_5 ) ;
return - V_234 ;
}
F_28 ( V_2 -> V_154 ) ;
F_4 ( 0 , V_2 -> V_19 + V_235 ) ;
V_2 -> V_151 = F_10 ( NULL ,
V_236 * sizeof ( struct V_237 ) +
sizeof( struct V_124 ) ,
& V_231 , V_37 ) ;
if ( ! V_2 -> V_151 ) {
V_23 = - V_38 ;
goto V_238;
}
V_2 -> V_125 = ( void * ) V_2 -> V_151 +
V_236 * sizeof ( struct V_237 ) ;
V_2 -> V_138 = V_231 +
V_236 * sizeof ( struct V_237 ) ;
memset ( V_2 -> V_151 , 0 ,
V_236 * sizeof ( struct V_237 ) ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_232 ; V_61 ++ )
F_4 ( 0 , V_2 -> V_19 + F_1 ( V_2 , V_61 ) ) ;
for ( V_61 = 0 ; V_61 < V_236 ; V_61 ++ )
F_4 ( 0 , V_2 -> V_19 + V_146 + V_61 * 4 ) ;
V_23 = F_27 ( & V_2 -> V_14 [ 0 ] ) ;
if ( V_23 )
goto V_238;
F_2 ( & V_2 -> V_14 [ 0 ] , false , true , false ) ;
F_4 ( 0x4050 , V_2 -> V_19 + V_239 ) ;
F_4 ( 0 , V_2 -> V_19 + V_240 ) ;
F_4 ( V_231 , V_2 -> V_19 + V_235 ) ;
F_4 ( V_241 , V_2 -> V_19 + V_240 ) ;
F_26 ( & V_2 -> V_14 [ 0 ] , 7 ) ;
F_39 ( V_2 -> V_154 ) ;
return 0 ;
V_238:
F_39 ( V_2 -> V_154 ) ;
F_41 ( V_2 -> V_128 , L_19 , V_23 ) ;
return V_23 ;
}
static int T_7 F_55 ( struct V_242 * V_243 )
{
const struct V_244 * V_245 =
F_56 ( V_246 , & V_243 -> V_128 ) ;
struct V_247 * V_248 = V_243 -> V_128 . V_249 ;
const char * V_228 ;
int V_23 ;
int V_68 ;
struct V_250 * V_251 ;
struct V_252 * V_253 = V_243 -> V_128 . V_254 ;
int V_61 ;
struct V_1 * V_2 ;
T_6 * V_212 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
F_58 ( & V_2 -> V_36 ) ;
V_2 -> V_128 = & V_243 -> V_128 ;
V_251 = F_59 ( V_243 , V_255 , 0 ) ;
V_68 = F_60 ( V_243 , 0 ) ;
if ( ! V_251 || V_68 < 0 ) {
V_23 = - V_18 ;
goto V_256;
}
if ( ! F_61 ( V_251 -> V_257 , F_62 ( V_251 ) , V_243 -> V_258 ) ) {
V_23 = - V_147 ;
goto V_259;
}
V_2 -> V_154 = F_63 ( & V_243 -> V_128 , NULL ) ;
if ( F_64 ( V_2 -> V_154 ) ) {
V_23 = F_65 ( V_2 -> V_154 ) ;
goto V_260;
}
V_2 -> V_19 = F_66 ( V_251 -> V_257 , F_62 ( V_251 ) ) ;
if ( ! V_2 -> V_19 ) {
V_23 = - V_38 ;
goto V_261;
}
V_23 = F_67 ( V_68 , F_19 , 0 , L_20 , V_2 ) ;
if ( V_23 )
goto V_262;
V_2 -> V_82 = F_57 ( sizeof( * V_2 -> V_82 ) , V_37 ) ;
if ( ! V_2 -> V_82 ) {
V_23 = - V_38 ;
goto V_263;
}
V_212 = ( T_6 * ) V_2 -> V_82 ;
for ( V_61 = 0 ; V_61 < V_213 ; V_61 ++ )
V_212 [ V_61 ] = - V_18 ;
if ( V_245 )
V_243 -> V_264 = V_245 -> V_162 ;
V_2 -> V_5 = V_243 -> V_264 -> V_265 ;
F_68 ( V_266 , V_2 -> V_267 . V_268 ) ;
F_68 ( V_269 , V_2 -> V_267 . V_268 ) ;
F_69 ( & V_2 -> V_267 . V_270 ) ;
for ( V_61 = 0 ; V_61 < V_236 ; V_61 ++ ) {
struct V_9 * V_10 = & V_2 -> V_14 [ V_61 ] ;
V_10 -> V_2 = V_2 ;
F_70 ( & V_10 -> V_160 ) ;
V_10 -> V_156 . V_271 = & V_2 -> V_267 ;
V_10 -> V_14 = V_61 ;
if ( V_61 )
F_71 ( & V_10 -> V_156 . V_247 ,
& V_2 -> V_267 . V_270 ) ;
}
V_23 = F_54 ( V_2 ) ;
if ( V_23 )
goto V_272;
if ( V_253 && V_253 -> V_82 )
F_48 ( V_2 , V_253 -> V_82 ) ;
if ( V_253 ) {
F_52 ( V_2 , V_253 -> V_228 ) ;
} else {
V_23 = F_72 ( V_248 , L_21 ,
& V_228 ) ;
if ( V_23 ) {
F_41 ( & V_243 -> V_128 , L_22 ) ;
goto V_272;
}
V_23 = F_52 ( V_2 , V_228 ) ;
if ( V_23 ) {
F_41 ( & V_243 -> V_128 , L_23 ) ;
goto V_272;
}
}
V_2 -> V_267 . V_128 = & V_243 -> V_128 ;
V_2 -> V_267 . V_273 = F_36 ;
V_2 -> V_267 . V_274 = F_38 ;
V_2 -> V_267 . V_275 = F_45 ;
V_2 -> V_267 . V_276 = F_40 ;
V_2 -> V_267 . V_277 = F_43 ;
V_2 -> V_267 . V_278 = F_44 ;
V_2 -> V_267 . V_279 = F_47 ;
V_2 -> V_267 . V_128 -> V_280 = & V_2 -> V_280 ;
F_73 ( V_2 -> V_267 . V_128 , 65535 ) ;
V_23 = F_74 ( & V_2 -> V_267 ) ;
if ( V_23 ) {
F_41 ( & V_243 -> V_128 , L_24 ) ;
goto V_272;
}
F_50 ( V_2 -> V_128 , L_25 ) ;
return 0 ;
V_272:
F_75 ( V_2 -> V_82 ) ;
V_263:
F_76 ( V_68 , V_2 ) ;
V_262:
F_77 ( V_2 -> V_19 ) ;
V_261:
F_78 ( V_2 -> V_154 ) ;
V_260:
F_79 ( V_251 -> V_257 , F_62 ( V_251 ) ) ;
V_259:
V_256:
F_75 ( V_2 ) ;
return V_23 ;
}
static int T_8 F_80 ( struct V_242 * V_243 )
{
return - V_147 ;
}
static int T_7 F_81 ( void )
{
return F_82 ( & V_281 , F_55 ) ;
}
