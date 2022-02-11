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
V_34 = F_9 ( NULL ,
V_29 ,
& V_35 , V_36 ) ;
if ( ! V_34 )
return - V_37 ;
V_32 -> V_38 . V_39 = V_40 ;
V_32 -> V_38 . V_41 = V_42 | V_43 | V_44 | V_45 ;
V_32 -> V_38 . V_46 = V_29 / 2 ;
V_32 -> V_47 = V_35 ;
V_32 -> V_48 = V_30 ;
memcpy ( V_34 , V_28 , V_29 ) ;
V_23 = F_5 ( & V_2 -> V_14 [ 0 ] ) ;
F_10 ( NULL , V_29 , V_34 , V_35 ) ;
return V_23 ;
}
static void F_11 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
T_1 V_49 ;
T_1 V_50 = F_1 ( V_2 , V_3 ) ;
V_49 = F_3 ( V_2 -> V_19 + V_50 ) ;
V_49 |= ( 1 << V_14 ) ;
F_4 ( V_49 , V_2 -> V_19 + V_50 ) ;
}
static void F_12 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
T_1 V_50 = F_1 ( V_2 , V_3 ) ;
T_1 V_49 ;
V_49 = F_3 ( V_2 -> V_19 + V_50 ) ;
V_49 &= ~ ( 1 << V_14 ) ;
F_4 ( V_49 , V_2 -> V_19 + V_50 ) ;
}
static void F_13 ( struct V_9 * V_10 )
{
struct V_31 * V_33 ;
while ( 1 ) {
V_33 = & V_10 -> V_33 [ V_10 -> V_51 ] ;
if ( V_33 -> V_38 . V_41 & V_42 )
break;
if ( V_33 -> V_38 . V_41 & V_52 )
V_10 -> V_41 = V_53 ;
else
V_10 -> V_41 = V_54 ;
V_33 -> V_38 . V_41 |= V_42 ;
V_10 -> V_51 ++ ;
V_10 -> V_51 %= V_10 -> V_55 ;
if ( V_10 -> V_56 . V_57 )
V_10 -> V_56 . V_57 ( V_10 -> V_56 . V_58 ) ;
}
}
static void F_14 ( struct V_9 * V_10 )
{
struct V_31 * V_33 ;
int V_59 , error = 0 ;
for ( V_59 = 0 ; V_59 < V_10 -> V_55 ; V_59 ++ ) {
V_33 = & V_10 -> V_33 [ V_59 ] ;
if ( V_33 -> V_38 . V_41 & ( V_42 | V_52 ) )
error = - V_60 ;
}
if ( error )
V_10 -> V_41 = V_53 ;
else
V_10 -> V_41 = V_61 ;
if ( V_10 -> V_56 . V_57 )
V_10 -> V_56 . V_57 ( V_10 -> V_56 . V_58 ) ;
V_10 -> V_62 = V_10 -> V_56 . V_63 ;
}
static void F_15 ( struct V_9 * V_10 )
{
F_16 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_14 == 0 )
return;
if ( V_10 -> V_64 & V_65 )
F_13 ( V_10 ) ;
else
F_14 ( V_10 ) ;
}
static T_3 F_17 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
T_1 V_68 ;
V_68 = F_3 ( V_2 -> V_19 + V_69 ) ;
F_4 ( V_68 , V_2 -> V_19 + V_69 ) ;
while ( V_68 ) {
int V_14 = F_18 ( V_68 ) - 1 ;
struct V_9 * V_10 = & V_2 -> V_14 [ V_14 ] ;
F_15 ( V_10 ) ;
V_68 &= ~ ( 1 << V_14 ) ;
}
return V_70 ;
}
static void F_19 ( struct V_9 * V_10 ,
enum V_71 V_72 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_73 = 0 , V_74 = 0 ;
int V_75 = 0 , V_76 = 0 ;
V_10 -> V_77 = 0 ;
V_10 -> V_78 = 0 ;
switch ( V_72 ) {
case V_79 :
V_76 = V_2 -> V_80 -> V_81 ;
break;
case V_82 :
V_74 = V_2 -> V_80 -> V_83 ;
V_73 = V_2 -> V_80 -> V_84 ;
break;
case V_85 :
V_73 = V_2 -> V_80 -> V_86 ;
V_74 = V_2 -> V_80 -> V_87 ;
break;
case V_88 :
V_73 = V_2 -> V_80 -> V_89 ;
V_74 = V_2 -> V_80 -> V_90 ;
break;
case V_91 :
V_73 = V_2 -> V_80 -> V_92 ;
V_74 = V_2 -> V_80 -> V_93 ;
break;
case V_94 :
V_73 = V_2 -> V_80 -> V_95 ;
V_74 = V_2 -> V_80 -> V_96 ;
break;
case V_97 :
case V_98 :
case V_99 :
V_73 = V_2 -> V_80 -> V_100 ;
V_74 = V_2 -> V_80 -> V_90 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_73 = V_2 -> V_80 -> V_107 ;
V_74 = V_2 -> V_80 -> V_93 ;
break;
case V_108 :
V_73 = V_2 -> V_80 -> V_109 ;
V_74 = V_2 -> V_80 -> V_109 ;
V_75 = V_2 -> V_80 -> V_110 ;
break;
case V_111 :
V_73 = V_2 -> V_80 -> V_112 ;
V_74 = V_2 -> V_80 -> V_113 ;
break;
case V_114 :
V_73 = V_2 -> V_80 -> V_115 ;
break;
case V_116 :
V_73 = V_2 -> V_80 -> V_117 ;
V_74 = V_2 -> V_80 -> V_118 ;
break;
case V_119 :
V_74 = V_2 -> V_80 -> V_120 ;
break;
default:
break;
}
V_10 -> V_77 = V_73 ;
V_10 -> V_78 = V_74 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_121 ;
struct V_122 * V_123 = V_2 -> V_123 ;
struct V_31 * V_32 = V_2 -> V_14 [ 0 ] . V_33 ;
int V_23 ;
if ( V_10 -> V_124 == V_125 ) {
V_121 = V_10 -> V_77 ;
} else {
V_121 = V_10 -> V_78 ;
}
if ( V_121 < 0 )
return V_121 ;
F_21 ( V_2 -> V_126 , L_1 , V_121 ) ;
F_21 ( V_2 -> V_126 , L_2 , V_10 -> V_127 ) ;
F_21 ( V_2 -> V_126 , L_3 , V_10 -> V_128 ) ;
F_21 ( V_2 -> V_126 , L_4 , V_10 -> V_129 ) ;
F_21 ( V_2 -> V_126 , L_5 , V_10 -> V_130 ) ;
F_21 ( V_2 -> V_126 , L_6 , V_10 -> V_131 ) ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_123 -> V_132 . V_133 = V_121 ;
V_123 -> V_134 [ 0 ] = V_10 -> V_131 ;
V_123 -> V_134 [ 1 ] = V_10 -> V_130 ;
V_123 -> V_134 [ 2 ] = V_10 -> V_129 ;
V_123 -> V_134 [ 6 ] = V_10 -> V_128 ;
V_123 -> V_134 [ 7 ] = V_10 -> V_127 ;
V_32 -> V_38 . V_39 = V_135 ;
V_32 -> V_38 . V_41 = V_42 | V_43 | V_44 | V_45 ;
V_32 -> V_38 . V_46 = sizeof( * V_123 ) / 4 ;
V_32 -> V_47 = V_2 -> V_136 ;
V_32 -> V_48 = 2048 + ( sizeof( * V_123 ) / 4 ) * V_14 ;
V_23 = F_5 ( & V_2 -> V_14 [ 0 ] ) ;
return V_23 ;
}
static void F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
F_4 ( 1 << V_14 , V_2 -> V_19 + V_137 ) ;
V_10 -> V_41 = V_53 ;
}
static int F_23 ( struct V_9 * V_10 )
{
int V_23 ;
F_22 ( V_10 ) ;
V_10 -> V_130 = 0 ;
V_10 -> V_131 = 0 ;
V_10 -> V_128 = 0 ;
V_10 -> V_129 = 0 ;
if ( V_10 -> V_138 ) {
if ( V_10 -> V_138 > 32 )
return - V_18 ;
F_11 ( V_10 , V_10 -> V_138 ) ;
}
switch ( V_10 -> V_72 ) {
case V_82 :
F_2 ( V_10 , false , true , true ) ;
break;
case V_79 :
F_2 ( V_10 , false , true , false ) ;
break;
default:
F_2 ( V_10 , true , true , false ) ;
break;
}
F_19 ( V_10 , V_10 -> V_72 ) ;
if ( ( V_10 -> V_72 != V_79 ) &&
( V_10 -> V_72 != V_82 ) ) {
if ( V_10 -> V_139 ) {
V_10 -> V_131 = 1 << ( V_10 -> V_139 % 32 ) ;
if ( V_10 -> V_139 > 31 )
V_10 -> V_127 |= 1 << 31 ;
V_10 -> V_130 = 1 << ( V_10 -> V_138 % 32 ) ;
if ( V_10 -> V_138 > 31 )
V_10 -> V_127 |= 1 << 30 ;
} else {
V_10 -> V_130 = 1 << V_10 -> V_138 ;
V_10 -> V_131 = 1 << ( V_10 -> V_138 - 32 ) ;
}
V_10 -> V_127 |= V_10 -> V_127 ;
V_10 -> V_128 = V_10 -> V_140 ;
} else {
V_10 -> V_127 = 0 ;
}
V_23 = F_20 ( V_10 ) ;
return V_23 ;
}
static int F_24 ( struct V_9 * V_10 ,
unsigned int V_141 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
if ( V_141 < V_142
|| V_141 > V_143 ) {
return - V_18 ;
}
F_4 ( V_141 , V_2 -> V_19 + V_144 + 4 * V_14 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_23 = - V_145 ;
V_10 -> V_33 = F_9 ( NULL , V_146 , & V_10 -> V_147 , V_36 ) ;
if ( ! V_10 -> V_33 ) {
V_23 = - V_37 ;
goto V_148;
}
memset ( V_10 -> V_33 , 0 , V_146 ) ;
V_2 -> V_149 [ V_14 ] . V_150 = V_10 -> V_147 ;
V_2 -> V_149 [ V_14 ] . V_151 = V_10 -> V_147 ;
F_26 ( V_2 -> V_152 ) ;
F_24 ( V_10 , V_153 ) ;
F_6 ( & V_10 -> V_24 ) ;
V_10 -> V_51 = 0 ;
return 0 ;
V_148:
return V_23 ;
}
static void F_27 ( struct V_1 * V_2 , int V_14 )
{
F_4 ( 1 << V_14 , V_2 -> V_19 + V_25 ) ;
}
static T_4 F_28 ( struct V_9 * V_10 )
{
T_4 V_63 = V_10 -> V_154 . V_63 ;
if ( ++ V_63 < 0 )
V_63 = 1 ;
V_10 -> V_154 . V_63 = V_63 ;
V_10 -> V_56 . V_63 = V_63 ;
return V_63 ;
}
static struct V_9 * F_29 ( struct V_155 * V_154 )
{
return F_30 ( V_154 , struct V_9 , V_154 ) ;
}
static T_4 F_31 ( struct V_156 * V_157 )
{
struct V_9 * V_10 = F_29 ( V_157 -> V_154 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_4 V_63 ;
F_32 ( & V_10 -> V_158 ) ;
V_63 = F_28 ( V_10 ) ;
F_27 ( V_2 , V_10 -> V_14 ) ;
F_33 ( & V_10 -> V_158 ) ;
return V_63 ;
}
static int F_34 ( struct V_155 * V_154 )
{
struct V_9 * V_10 = F_29 ( V_154 ) ;
struct V_159 * V_160 = V_154 -> V_161 ;
int V_162 , V_23 ;
if ( ! V_160 )
return - V_18 ;
switch ( V_160 -> V_141 ) {
case V_163 :
V_162 = 3 ;
break;
case V_164 :
V_162 = 2 ;
break;
case V_165 :
default:
V_162 = 1 ;
break;
}
V_10 -> V_72 = V_160 -> V_72 ;
V_10 -> V_138 = V_160 -> V_166 ;
V_23 = F_24 ( V_10 , V_162 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_25 ( V_10 ) ;
if ( V_23 )
return V_23 ;
F_35 ( & V_10 -> V_56 , V_154 ) ;
V_10 -> V_56 . V_167 = F_31 ;
V_10 -> V_56 . V_64 = V_168 ;
return 0 ;
}
static void F_36 ( struct V_155 * V_154 )
{
struct V_9 * V_10 = F_29 ( V_154 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_22 ( V_10 ) ;
if ( V_10 -> V_138 )
F_12 ( V_10 , V_10 -> V_138 ) ;
if ( V_10 -> V_139 )
F_12 ( V_10 , V_10 -> V_139 ) ;
V_10 -> V_138 = 0 ;
V_10 -> V_139 = 0 ;
F_24 ( V_10 , 0 ) ;
F_10 ( NULL , V_146 , V_10 -> V_33 , V_10 -> V_147 ) ;
F_37 ( V_2 -> V_152 ) ;
}
static struct V_156 * F_38 (
struct V_155 * V_154 , struct V_169 * V_170 ,
unsigned int V_171 , enum V_172 V_124 ,
unsigned long V_64 )
{
struct V_9 * V_10 = F_29 ( V_154 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_23 , V_59 , V_46 ;
int V_14 = V_10 -> V_14 ;
struct V_169 * V_173 ;
if ( V_10 -> V_41 == V_54 )
return NULL ;
V_10 -> V_41 = V_54 ;
V_10 -> V_64 = 0 ;
F_21 ( V_2 -> V_126 , L_7 ,
V_171 , V_14 ) ;
V_10 -> V_124 = V_124 ;
V_23 = F_20 ( V_10 ) ;
if ( V_23 )
goto V_174;
if ( V_171 > V_175 ) {
F_39 ( V_2 -> V_126 , L_8 ,
V_14 , V_171 , V_175 ) ;
V_23 = - V_18 ;
goto V_174;
}
F_40 (sgl, sg, sg_len, i) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_59 ] ;
int V_176 ;
V_33 -> V_47 = V_173 -> V_177 ;
V_46 = V_173 -> V_178 ;
if ( V_46 > 0xffff ) {
F_39 ( V_2 -> V_126 , L_9 ,
V_14 , V_46 , 0xffff ) ;
V_23 = - V_18 ;
goto V_174;
}
V_33 -> V_38 . V_46 = V_46 ;
if ( V_10 -> V_179 > V_180 ) {
V_23 = - V_18 ;
goto V_174;
}
switch ( V_10 -> V_179 ) {
case V_180 :
V_33 -> V_38 . V_39 = 0 ;
if ( V_46 & 3 || V_173 -> V_177 & 3 )
return NULL ;
break;
case V_181 :
V_33 -> V_38 . V_39 = 2 ;
if ( V_46 & 1 || V_173 -> V_177 & 1 )
return NULL ;
break;
case V_182 :
V_33 -> V_38 . V_39 = 1 ;
break;
default:
return NULL ;
}
V_176 = V_42 | V_45 | V_183 ;
if ( V_59 + 1 == V_171 ) {
V_176 |= V_43 ;
V_176 |= V_184 ;
V_176 &= ~ V_183 ;
}
F_21 ( V_2 -> V_126 , L_10 ,
V_59 , V_46 , V_173 -> V_177 ,
V_176 & V_44 ? L_11 : L_12 ,
V_176 & V_43 ? L_13 : L_12 ) ;
V_33 -> V_38 . V_41 = V_176 ;
}
V_10 -> V_55 = V_171 ;
V_2 -> V_149 [ V_14 ] . V_151 = V_10 -> V_147 ;
return & V_10 -> V_56 ;
V_174:
V_10 -> V_41 = V_53 ;
return NULL ;
}
static struct V_156 * F_41 (
struct V_155 * V_154 , T_2 V_185 , T_5 V_186 ,
T_5 V_187 , enum V_172 V_124 )
{
struct V_9 * V_10 = F_29 ( V_154 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_188 = V_186 / V_187 ;
int V_14 = V_10 -> V_14 ;
int V_23 , V_59 = 0 , V_28 = 0 ;
F_21 ( V_2 -> V_126 , L_14 , V_189 , V_14 ) ;
if ( V_10 -> V_41 == V_54 )
return NULL ;
V_10 -> V_41 = V_54 ;
V_10 -> V_64 |= V_65 ;
V_10 -> V_124 = V_124 ;
V_23 = F_20 ( V_10 ) ;
if ( V_23 )
goto V_174;
if ( V_188 > V_175 ) {
F_39 ( V_2 -> V_126 , L_8 ,
V_14 , V_188 , V_175 ) ;
goto V_174;
}
if ( V_187 > 0xffff ) {
F_39 ( V_2 -> V_126 , L_15 ,
V_14 , V_187 , 0xffff ) ;
goto V_174;
}
while ( V_28 < V_186 ) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_59 ] ;
int V_176 ;
V_33 -> V_47 = V_185 ;
V_33 -> V_38 . V_46 = V_187 ;
if ( V_10 -> V_179 > V_180 )
goto V_174;
if ( V_10 -> V_179 == V_180 )
V_33 -> V_38 . V_39 = 0 ;
else
V_33 -> V_38 . V_39 = V_10 -> V_179 ;
V_176 = V_42 | V_45 | V_183 | V_43 ;
if ( V_59 + 1 == V_188 )
V_176 |= V_44 ;
F_21 ( V_2 -> V_126 , L_10 ,
V_59 , V_187 , V_185 ,
V_176 & V_44 ? L_11 : L_12 ,
V_176 & V_43 ? L_13 : L_12 ) ;
V_33 -> V_38 . V_41 = V_176 ;
V_185 += V_187 ;
V_28 += V_187 ;
V_59 ++ ;
}
V_10 -> V_55 = V_188 ;
V_2 -> V_149 [ V_14 ] . V_151 = V_10 -> V_147 ;
return & V_10 -> V_56 ;
V_174:
V_10 -> V_41 = V_53 ;
return NULL ;
}
static int F_42 ( struct V_155 * V_154 , enum V_190 V_191 ,
unsigned long V_192 )
{
struct V_9 * V_10 = F_29 ( V_154 ) ;
struct V_193 * V_194 = ( void * ) V_192 ;
switch ( V_191 ) {
case V_195 :
F_22 ( V_10 ) ;
return 0 ;
case V_196 :
if ( V_194 -> V_124 == V_125 ) {
V_10 -> V_140 = V_194 -> V_197 ;
V_10 -> V_127 = V_194 -> V_198 ;
V_10 -> V_179 = V_194 -> V_199 ;
} else {
V_10 -> V_140 = V_194 -> V_200 ;
V_10 -> V_127 = V_194 -> V_201 ;
V_10 -> V_179 = V_194 -> V_202 ;
}
return F_23 ( V_10 ) ;
default:
return - V_203 ;
}
return - V_18 ;
}
static enum V_204 F_43 ( struct V_155 * V_154 ,
T_4 V_63 ,
struct V_205 * V_206 )
{
struct V_9 * V_10 = F_29 ( V_154 ) ;
T_4 V_207 ;
V_207 = V_154 -> V_63 ;
F_44 ( V_206 , V_10 -> V_62 , V_207 , 0 ) ;
return V_10 -> V_41 ;
}
static void F_45 ( struct V_155 * V_154 )
{
}
static void F_46 ( struct V_1 * V_2 ,
const struct V_208 * V_209 )
{
T_6 * V_210 = ( T_1 * ) V_209 ;
T_6 * V_211 = ( T_1 * ) V_2 -> V_80 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_212 ; V_59 ++ )
if ( V_210 [ V_59 ] > 0 )
V_211 [ V_59 ] = V_210 [ V_59 ] ;
}
static int T_7 F_47 ( struct V_1 * V_2 ,
const char * V_213 )
{
const struct V_214 * V_215 ;
const struct V_216 * V_217 ;
int V_23 ;
const struct V_208 * V_209 ;
unsigned short * V_218 ;
V_23 = F_48 ( & V_215 , V_213 , V_2 -> V_126 ) ;
if ( V_23 )
return V_23 ;
if ( V_215 -> V_29 < sizeof( * V_217 ) )
goto V_219;
V_217 = (struct V_216 * ) V_215 -> V_160 ;
if ( V_217 -> V_220 != V_221 )
goto V_219;
if ( V_217 -> V_222 + V_217 -> V_223 > V_215 -> V_29 )
goto V_219;
V_209 = ( void * ) V_217 + V_217 -> V_224 ;
V_218 = ( void * ) V_217 + V_217 -> V_222 ;
F_26 ( V_2 -> V_152 ) ;
F_8 ( V_2 , V_218 ,
V_217 -> V_223 ,
V_209 -> V_225 ) ;
F_37 ( V_2 -> V_152 ) ;
F_46 ( V_2 , V_209 ) ;
F_49 ( V_2 -> V_126 , L_16 ,
V_217 -> V_226 ,
V_217 -> V_227 ) ;
V_219:
F_50 ( V_215 ) ;
return V_23 ;
}
static int T_7 F_51 ( struct V_1 * V_2 )
{
int V_59 , V_23 ;
T_2 V_228 ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_229 = 32 ;
break;
case V_230 :
V_2 -> V_229 = 48 ;
break;
default:
F_39 ( V_2 -> V_126 , L_17 ,
V_2 -> V_5 ) ;
return - V_231 ;
}
F_26 ( V_2 -> V_152 ) ;
F_4 ( 0 , V_2 -> V_19 + V_232 ) ;
V_2 -> V_149 = F_9 ( NULL ,
V_233 * sizeof ( struct V_234 ) +
sizeof( struct V_122 ) ,
& V_228 , V_36 ) ;
if ( ! V_2 -> V_149 ) {
V_23 = - V_37 ;
goto V_235;
}
V_2 -> V_123 = ( void * ) V_2 -> V_149 +
V_233 * sizeof ( struct V_234 ) ;
V_2 -> V_136 = V_228 +
V_233 * sizeof ( struct V_234 ) ;
memset ( V_2 -> V_149 , 0 ,
V_233 * sizeof ( struct V_234 ) ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_229 ; V_59 ++ )
F_4 ( 0 , V_2 -> V_19 + F_1 ( V_2 , V_59 ) ) ;
for ( V_59 = 0 ; V_59 < V_233 ; V_59 ++ )
F_4 ( 0 , V_2 -> V_19 + V_144 + V_59 * 4 ) ;
V_23 = F_25 ( & V_2 -> V_14 [ 0 ] ) ;
if ( V_23 )
goto V_235;
F_2 ( & V_2 -> V_14 [ 0 ] , false , true , false ) ;
F_4 ( 0x4050 , V_2 -> V_19 + V_236 ) ;
F_4 ( 0 , V_2 -> V_19 + V_237 ) ;
F_4 ( V_228 , V_2 -> V_19 + V_232 ) ;
F_4 ( V_238 , V_2 -> V_19 + V_237 ) ;
F_24 ( & V_2 -> V_14 [ 0 ] , 7 ) ;
F_37 ( V_2 -> V_152 ) ;
return 0 ;
V_235:
F_37 ( V_2 -> V_152 ) ;
F_39 ( V_2 -> V_126 , L_18 , V_23 ) ;
return V_23 ;
}
static int T_7 F_52 ( struct V_239 * V_240 )
{
const struct V_241 * V_242 =
F_53 ( V_243 , & V_240 -> V_126 ) ;
struct V_244 * V_245 = V_240 -> V_126 . V_246 ;
const char * V_213 ;
int V_23 ;
int V_66 ;
struct V_247 * V_248 ;
struct V_249 * V_250 = V_240 -> V_126 . V_251 ;
int V_59 ;
struct V_1 * V_2 ;
V_2 = F_54 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_126 = & V_240 -> V_126 ;
V_248 = F_55 ( V_240 , V_252 , 0 ) ;
V_66 = F_56 ( V_240 , 0 ) ;
if ( ! V_248 || V_66 < 0 ) {
V_23 = - V_18 ;
goto V_253;
}
if ( ! F_57 ( V_248 -> V_254 , F_58 ( V_248 ) , V_240 -> V_255 ) ) {
V_23 = - V_145 ;
goto V_256;
}
V_2 -> V_152 = F_59 ( & V_240 -> V_126 , NULL ) ;
if ( F_60 ( V_2 -> V_152 ) ) {
V_23 = F_61 ( V_2 -> V_152 ) ;
goto V_257;
}
V_2 -> V_19 = F_62 ( V_248 -> V_254 , F_58 ( V_248 ) ) ;
if ( ! V_2 -> V_19 ) {
V_23 = - V_37 ;
goto V_258;
}
V_23 = F_63 ( V_66 , F_17 , 0 , L_19 , V_2 ) ;
if ( V_23 )
goto V_259;
V_2 -> V_80 = F_54 ( sizeof( * V_2 -> V_80 ) , V_36 ) ;
if ( ! V_2 -> V_80 ) {
V_23 = - V_37 ;
goto V_260;
}
if ( V_242 )
V_240 -> V_261 = V_242 -> V_160 ;
V_2 -> V_5 = V_240 -> V_261 -> V_262 ;
F_64 ( V_263 , V_2 -> V_264 . V_265 ) ;
F_64 ( V_266 , V_2 -> V_264 . V_265 ) ;
F_65 ( & V_2 -> V_264 . V_267 ) ;
for ( V_59 = 0 ; V_59 < V_233 ; V_59 ++ ) {
struct V_9 * V_10 = & V_2 -> V_14 [ V_59 ] ;
V_10 -> V_2 = V_2 ;
F_66 ( & V_10 -> V_158 ) ;
V_10 -> V_154 . V_268 = & V_2 -> V_264 ;
V_10 -> V_14 = V_59 ;
if ( V_59 )
F_67 ( & V_10 -> V_154 . V_244 ,
& V_2 -> V_264 . V_267 ) ;
}
V_23 = F_51 ( V_2 ) ;
if ( V_23 )
goto V_269;
if ( V_250 && V_250 -> V_80 )
F_46 ( V_2 , V_250 -> V_80 ) ;
if ( V_250 ) {
F_47 ( V_2 , V_250 -> V_213 ) ;
} else {
V_23 = F_68 ( V_245 , L_20 ,
& V_213 ) ;
if ( V_23 ) {
F_39 ( & V_240 -> V_126 , L_21 ) ;
goto V_269;
}
V_23 = F_47 ( V_2 , V_213 ) ;
if ( V_23 ) {
F_39 ( & V_240 -> V_126 , L_22 ) ;
goto V_269;
}
}
V_2 -> V_264 . V_126 = & V_240 -> V_126 ;
V_2 -> V_264 . V_270 = F_34 ;
V_2 -> V_264 . V_271 = F_36 ;
V_2 -> V_264 . V_272 = F_43 ;
V_2 -> V_264 . V_273 = F_38 ;
V_2 -> V_264 . V_274 = F_41 ;
V_2 -> V_264 . V_275 = F_42 ;
V_2 -> V_264 . V_276 = F_45 ;
V_2 -> V_264 . V_126 -> V_277 = & V_2 -> V_277 ;
F_69 ( V_2 -> V_264 . V_126 , 65535 ) ;
V_23 = F_70 ( & V_2 -> V_264 ) ;
if ( V_23 ) {
F_39 ( & V_240 -> V_126 , L_23 ) ;
goto V_269;
}
F_49 ( V_2 -> V_126 , L_24 ) ;
return 0 ;
V_269:
F_71 ( V_2 -> V_80 ) ;
V_260:
F_72 ( V_66 , V_2 ) ;
V_259:
F_73 ( V_2 -> V_19 ) ;
V_258:
F_74 ( V_2 -> V_152 ) ;
V_257:
F_75 ( V_248 -> V_254 , F_58 ( V_248 ) ) ;
V_256:
V_253:
F_71 ( V_2 ) ;
return V_23 ;
}
static int T_8 F_76 ( struct V_239 * V_240 )
{
return - V_145 ;
}
static int T_7 F_77 ( void )
{
return F_78 ( & V_278 , F_52 ) ;
}
