static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = ( V_2 -> V_5 == 2 ? V_6 : V_7 ) ;
return V_4 + V_3 * 4 ;
}
static int F_2 ( struct V_8 * V_9 ,
bool V_10 , bool V_11 , bool V_12 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
T_1 V_14 , V_15 , V_16 ;
if ( V_10 && V_11 && V_12 )
return - V_17 ;
V_14 = F_3 ( V_2 -> V_18 + V_19 ) ;
V_15 = F_3 ( V_2 -> V_18 + V_20 ) ;
V_16 = F_3 ( V_2 -> V_18 + V_21 ) ;
if ( V_12 )
V_16 &= ~ ( 1 << V_13 ) ;
else
V_16 |= ( 1 << V_13 ) ;
if ( V_10 )
V_14 &= ~ ( 1 << V_13 ) ;
else
V_14 |= ( 1 << V_13 ) ;
if ( V_11 )
V_15 &= ~ ( 1 << V_13 ) ;
else
V_15 |= ( 1 << V_13 ) ;
F_4 ( V_14 , V_2 -> V_18 + V_19 ) ;
F_4 ( V_15 , V_2 -> V_18 + V_20 ) ;
F_4 ( V_16 , V_2 -> V_18 + V_21 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
int V_22 ;
F_6 ( & V_9 -> V_23 ) ;
F_4 ( 1 << V_13 , V_2 -> V_18 + V_24 ) ;
V_22 = F_7 ( & V_9 -> V_23 , V_25 ) ;
return V_22 ? 0 : - V_26 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_27 , int V_28 ,
T_1 V_29 )
{
struct V_30 * V_31 = V_2 -> V_13 [ 0 ] . V_32 ;
void * V_33 ;
T_2 V_34 ;
int V_22 ;
V_33 = F_9 ( NULL ,
V_28 ,
& V_34 , V_35 ) ;
if ( ! V_33 )
return - V_36 ;
V_31 -> V_37 . V_38 = V_39 ;
V_31 -> V_37 . V_40 = V_41 | V_42 | V_43 | V_44 ;
V_31 -> V_37 . V_45 = V_28 / 2 ;
V_31 -> V_46 = V_34 ;
V_31 -> V_47 = V_29 ;
memcpy ( V_33 , V_27 , V_28 ) ;
V_22 = F_5 ( & V_2 -> V_13 [ 0 ] ) ;
F_10 ( NULL , V_28 , V_33 , V_34 ) ;
return V_22 ;
}
static void F_11 ( struct V_8 * V_9 , unsigned int V_3 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
T_1 V_48 ;
T_1 V_49 = F_1 ( V_2 , V_3 ) ;
V_48 = F_3 ( V_2 -> V_18 + V_49 ) ;
V_48 |= ( 1 << V_13 ) ;
F_4 ( V_48 , V_2 -> V_18 + V_49 ) ;
}
static void F_12 ( struct V_8 * V_9 , unsigned int V_3 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
T_1 V_49 = F_1 ( V_2 , V_3 ) ;
T_1 V_48 ;
V_48 = F_3 ( V_2 -> V_18 + V_49 ) ;
V_48 &= ~ ( 1 << V_13 ) ;
F_4 ( V_48 , V_2 -> V_18 + V_49 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
struct V_30 * V_32 ;
while ( 1 ) {
V_32 = & V_9 -> V_32 [ V_9 -> V_50 ] ;
if ( V_32 -> V_37 . V_40 & V_41 )
break;
if ( V_32 -> V_37 . V_40 & V_51 )
V_9 -> V_40 = V_52 ;
else
V_9 -> V_40 = V_53 ;
V_32 -> V_37 . V_40 |= V_41 ;
V_9 -> V_50 ++ ;
V_9 -> V_50 %= V_9 -> V_54 ;
if ( V_9 -> V_55 . V_56 )
V_9 -> V_55 . V_56 ( V_9 -> V_55 . V_57 ) ;
}
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_30 * V_32 ;
int V_58 , error = 0 ;
for ( V_58 = 0 ; V_58 < V_9 -> V_54 ; V_58 ++ ) {
V_32 = & V_9 -> V_32 [ V_58 ] ;
if ( V_32 -> V_37 . V_40 & ( V_41 | V_51 ) )
error = - V_59 ;
}
if ( error )
V_9 -> V_40 = V_52 ;
else
V_9 -> V_40 = V_60 ;
if ( V_9 -> V_55 . V_56 )
V_9 -> V_55 . V_56 ( V_9 -> V_55 . V_57 ) ;
V_9 -> V_61 = V_9 -> V_55 . V_62 ;
}
static void F_15 ( struct V_8 * V_9 )
{
F_16 ( & V_9 -> V_23 ) ;
if ( V_9 -> V_13 == 0 )
return;
if ( V_9 -> V_63 & V_64 )
F_13 ( V_9 ) ;
else
F_14 ( V_9 ) ;
}
static T_3 F_17 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
T_1 V_67 ;
V_67 = F_3 ( V_2 -> V_18 + V_68 ) ;
F_4 ( V_67 , V_2 -> V_18 + V_68 ) ;
while ( V_67 ) {
int V_13 = F_18 ( V_67 ) - 1 ;
struct V_8 * V_9 = & V_2 -> V_13 [ V_13 ] ;
F_15 ( V_9 ) ;
V_67 &= ~ ( 1 << V_13 ) ;
}
return V_69 ;
}
static void F_19 ( struct V_8 * V_9 ,
enum V_70 V_71 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_72 = 0 , V_73 = 0 ;
int V_74 = 0 , V_75 = 0 ;
V_9 -> V_76 = 0 ;
V_9 -> V_77 = 0 ;
switch ( V_71 ) {
case V_78 :
V_75 = V_2 -> V_79 -> V_80 ;
break;
case V_81 :
V_73 = V_2 -> V_79 -> V_82 ;
V_72 = V_2 -> V_79 -> V_83 ;
break;
case V_84 :
V_72 = V_2 -> V_79 -> V_85 ;
V_73 = V_2 -> V_79 -> V_86 ;
break;
case V_87 :
V_72 = V_2 -> V_79 -> V_88 ;
V_73 = V_2 -> V_79 -> V_89 ;
break;
case V_90 :
V_72 = V_2 -> V_79 -> V_91 ;
V_73 = V_2 -> V_79 -> V_92 ;
break;
case V_93 :
V_72 = V_2 -> V_79 -> V_94 ;
V_73 = V_2 -> V_79 -> V_95 ;
break;
case V_96 :
case V_97 :
case V_98 :
V_72 = V_2 -> V_79 -> V_99 ;
V_73 = V_2 -> V_79 -> V_89 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
V_72 = V_2 -> V_79 -> V_106 ;
V_73 = V_2 -> V_79 -> V_92 ;
break;
case V_107 :
V_72 = V_2 -> V_79 -> V_108 ;
V_73 = V_2 -> V_79 -> V_108 ;
V_74 = V_2 -> V_79 -> V_109 ;
break;
case V_110 :
V_72 = V_2 -> V_79 -> V_111 ;
V_73 = V_2 -> V_79 -> V_112 ;
break;
case V_113 :
V_72 = V_2 -> V_79 -> V_114 ;
break;
case V_115 :
V_72 = V_2 -> V_79 -> V_116 ;
V_73 = V_2 -> V_79 -> V_117 ;
break;
case V_118 :
V_73 = V_2 -> V_79 -> V_119 ;
break;
default:
break;
}
V_9 -> V_76 = V_72 ;
V_9 -> V_77 = V_73 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
int V_120 ;
struct V_121 * V_122 = V_2 -> V_122 ;
struct V_30 * V_31 = V_2 -> V_13 [ 0 ] . V_32 ;
int V_22 ;
if ( V_9 -> V_123 == V_124 ) {
V_120 = V_9 -> V_76 ;
} else {
V_120 = V_9 -> V_77 ;
}
if ( V_120 < 0 )
return V_120 ;
F_21 ( V_2 -> V_125 , L_1 , V_120 ) ;
F_21 ( V_2 -> V_125 , L_2 , V_9 -> V_126 ) ;
F_21 ( V_2 -> V_125 , L_3 , V_9 -> V_127 ) ;
F_21 ( V_2 -> V_125 , L_4 , V_9 -> V_128 ) ;
F_21 ( V_2 -> V_125 , L_5 , V_9 -> V_129 ) ;
F_21 ( V_2 -> V_125 , L_6 , V_9 -> V_130 ) ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_131 . V_132 = V_120 ;
V_122 -> V_133 [ 0 ] = V_9 -> V_130 ;
V_122 -> V_133 [ 1 ] = V_9 -> V_129 ;
V_122 -> V_133 [ 2 ] = V_9 -> V_128 ;
V_122 -> V_133 [ 6 ] = V_9 -> V_127 ;
V_122 -> V_133 [ 7 ] = V_9 -> V_126 ;
V_31 -> V_37 . V_38 = V_134 ;
V_31 -> V_37 . V_40 = V_41 | V_42 | V_43 | V_44 ;
V_31 -> V_37 . V_45 = sizeof( * V_122 ) / 4 ;
V_31 -> V_46 = V_2 -> V_135 ;
V_31 -> V_47 = 2048 + ( sizeof( * V_122 ) / 4 ) * V_13 ;
V_22 = F_5 ( & V_2 -> V_13 [ 0 ] ) ;
return V_22 ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
F_4 ( 1 << V_13 , V_2 -> V_18 + V_136 ) ;
V_9 -> V_40 = V_52 ;
}
static int F_23 ( struct V_8 * V_9 )
{
int V_22 ;
F_22 ( V_9 ) ;
V_9 -> V_129 = 0 ;
V_9 -> V_130 = 0 ;
V_9 -> V_127 = 0 ;
V_9 -> V_128 = 0 ;
if ( V_9 -> V_137 ) {
if ( V_9 -> V_137 > 32 )
return - V_17 ;
F_11 ( V_9 , V_9 -> V_137 ) ;
}
switch ( V_9 -> V_71 ) {
case V_81 :
F_2 ( V_9 , false , true , true ) ;
break;
case V_78 :
F_2 ( V_9 , false , true , false ) ;
break;
default:
F_2 ( V_9 , true , true , false ) ;
break;
}
F_19 ( V_9 , V_9 -> V_71 ) ;
if ( ( V_9 -> V_71 != V_78 ) &&
( V_9 -> V_71 != V_81 ) ) {
if ( V_9 -> V_138 ) {
V_9 -> V_130 = 1 << ( V_9 -> V_138 % 32 ) ;
if ( V_9 -> V_138 > 31 )
V_9 -> V_126 |= 1 << 31 ;
V_9 -> V_129 = 1 << ( V_9 -> V_137 % 32 ) ;
if ( V_9 -> V_137 > 31 )
V_9 -> V_126 |= 1 << 30 ;
} else {
V_9 -> V_129 = 1 << V_9 -> V_137 ;
V_9 -> V_130 = 1 << ( V_9 -> V_137 - 32 ) ;
}
V_9 -> V_126 |= V_9 -> V_126 ;
V_9 -> V_127 = V_9 -> V_139 ;
} else {
V_9 -> V_126 = 0 ;
}
V_22 = F_20 ( V_9 ) ;
return V_22 ;
}
static int F_24 ( struct V_8 * V_9 ,
unsigned int V_140 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
if ( V_140 < V_141
|| V_140 > V_142 ) {
return - V_17 ;
}
F_4 ( V_140 , V_2 -> V_18 + V_143 + 4 * V_13 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_13 = V_9 -> V_13 ;
int V_22 = - V_144 ;
V_9 -> V_32 = F_9 ( NULL , V_145 , & V_9 -> V_146 , V_35 ) ;
if ( ! V_9 -> V_32 ) {
V_22 = - V_36 ;
goto V_147;
}
memset ( V_9 -> V_32 , 0 , V_145 ) ;
V_2 -> V_148 [ V_13 ] . V_149 = V_9 -> V_146 ;
V_2 -> V_148 [ V_13 ] . V_150 = V_9 -> V_146 ;
F_26 ( V_2 -> V_151 ) ;
F_24 ( V_9 , V_152 ) ;
F_6 ( & V_9 -> V_23 ) ;
V_9 -> V_50 = 0 ;
return 0 ;
V_147:
return V_22 ;
}
static void F_27 ( struct V_1 * V_2 , int V_13 )
{
F_4 ( 1 << V_13 , V_2 -> V_18 + V_24 ) ;
}
static T_4 F_28 ( struct V_8 * V_9 )
{
T_4 V_62 = V_9 -> V_153 . V_62 ;
if ( ++ V_62 < 0 )
V_62 = 1 ;
V_9 -> V_153 . V_62 = V_62 ;
V_9 -> V_55 . V_62 = V_62 ;
return V_62 ;
}
static struct V_8 * F_29 ( struct V_154 * V_153 )
{
return F_30 ( V_153 , struct V_8 , V_153 ) ;
}
static T_4 F_31 ( struct V_155 * V_156 )
{
struct V_8 * V_9 = F_29 ( V_156 -> V_153 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_4 V_62 ;
F_32 ( & V_9 -> V_157 ) ;
V_62 = F_28 ( V_9 ) ;
F_27 ( V_2 , V_9 -> V_13 ) ;
F_33 ( & V_9 -> V_157 ) ;
return V_62 ;
}
static int F_34 ( struct V_154 * V_153 )
{
struct V_8 * V_9 = F_29 ( V_153 ) ;
struct V_158 * V_159 = V_153 -> V_160 ;
int V_161 , V_22 ;
if ( ! V_159 )
return - V_17 ;
switch ( V_159 -> V_140 ) {
case V_162 :
V_161 = 3 ;
break;
case V_163 :
V_161 = 2 ;
break;
case V_164 :
default:
V_161 = 1 ;
break;
}
V_9 -> V_71 = V_159 -> V_71 ;
V_9 -> V_137 = V_159 -> V_165 ;
V_22 = F_24 ( V_9 , V_161 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_25 ( V_9 ) ;
if ( V_22 )
return V_22 ;
F_35 ( & V_9 -> V_55 , V_153 ) ;
V_9 -> V_55 . V_166 = F_31 ;
V_9 -> V_55 . V_63 = V_167 ;
return 0 ;
}
static void F_36 ( struct V_154 * V_153 )
{
struct V_8 * V_9 = F_29 ( V_153 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
F_22 ( V_9 ) ;
if ( V_9 -> V_137 )
F_12 ( V_9 , V_9 -> V_137 ) ;
if ( V_9 -> V_138 )
F_12 ( V_9 , V_9 -> V_138 ) ;
V_9 -> V_137 = 0 ;
V_9 -> V_138 = 0 ;
F_24 ( V_9 , 0 ) ;
F_10 ( NULL , V_145 , V_9 -> V_32 , V_9 -> V_146 ) ;
F_37 ( V_2 -> V_151 ) ;
}
static struct V_155 * F_38 (
struct V_154 * V_153 , struct V_168 * V_169 ,
unsigned int V_170 , enum V_171 V_123 ,
unsigned long V_63 )
{
struct V_8 * V_9 = F_29 ( V_153 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_22 , V_58 , V_45 ;
int V_13 = V_9 -> V_13 ;
struct V_168 * V_172 ;
if ( V_9 -> V_40 == V_53 )
return NULL ;
V_9 -> V_40 = V_53 ;
V_9 -> V_63 = 0 ;
F_21 ( V_2 -> V_125 , L_7 ,
V_170 , V_13 ) ;
V_9 -> V_123 = V_123 ;
V_22 = F_20 ( V_9 ) ;
if ( V_22 )
goto V_173;
if ( V_170 > V_174 ) {
F_39 ( V_2 -> V_125 , L_8 ,
V_13 , V_170 , V_174 ) ;
V_22 = - V_17 ;
goto V_173;
}
F_40 (sgl, sg, sg_len, i) {
struct V_30 * V_32 = & V_9 -> V_32 [ V_58 ] ;
int V_175 ;
V_32 -> V_46 = V_172 -> V_176 ;
V_45 = V_172 -> V_177 ;
if ( V_45 > 0xffff ) {
F_39 ( V_2 -> V_125 , L_9 ,
V_13 , V_45 , 0xffff ) ;
V_22 = - V_17 ;
goto V_173;
}
V_32 -> V_37 . V_45 = V_45 ;
if ( V_9 -> V_178 > V_179 ) {
V_22 = - V_17 ;
goto V_173;
}
switch ( V_9 -> V_178 ) {
case V_179 :
V_32 -> V_37 . V_38 = 0 ;
if ( V_45 & 3 || V_172 -> V_176 & 3 )
return NULL ;
break;
case V_180 :
V_32 -> V_37 . V_38 = 2 ;
if ( V_45 & 1 || V_172 -> V_176 & 1 )
return NULL ;
break;
case V_181 :
V_32 -> V_37 . V_38 = 1 ;
break;
default:
return NULL ;
}
V_175 = V_41 | V_44 | V_182 ;
if ( V_58 + 1 == V_170 ) {
V_175 |= V_42 ;
V_175 |= V_183 ;
V_175 &= ~ V_182 ;
}
F_21 ( V_2 -> V_125 , L_10 ,
V_58 , V_45 , V_172 -> V_176 ,
V_175 & V_43 ? L_11 : L_12 ,
V_175 & V_42 ? L_13 : L_12 ) ;
V_32 -> V_37 . V_40 = V_175 ;
}
V_9 -> V_54 = V_170 ;
V_2 -> V_148 [ V_13 ] . V_150 = V_9 -> V_146 ;
return & V_9 -> V_55 ;
V_173:
V_9 -> V_40 = V_52 ;
return NULL ;
}
static struct V_155 * F_41 (
struct V_154 * V_153 , T_2 V_184 , T_5 V_185 ,
T_5 V_186 , enum V_171 V_123 )
{
struct V_8 * V_9 = F_29 ( V_153 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_187 = V_185 / V_186 ;
int V_13 = V_9 -> V_13 ;
int V_22 , V_58 = 0 , V_27 = 0 ;
F_21 ( V_2 -> V_125 , L_14 , V_188 , V_13 ) ;
if ( V_9 -> V_40 == V_53 )
return NULL ;
V_9 -> V_40 = V_53 ;
V_9 -> V_63 |= V_64 ;
V_9 -> V_123 = V_123 ;
V_22 = F_20 ( V_9 ) ;
if ( V_22 )
goto V_173;
if ( V_187 > V_174 ) {
F_39 ( V_2 -> V_125 , L_8 ,
V_13 , V_187 , V_174 ) ;
goto V_173;
}
if ( V_186 > 0xffff ) {
F_39 ( V_2 -> V_125 , L_15 ,
V_13 , V_186 , 0xffff ) ;
goto V_173;
}
while ( V_27 < V_185 ) {
struct V_30 * V_32 = & V_9 -> V_32 [ V_58 ] ;
int V_175 ;
V_32 -> V_46 = V_184 ;
V_32 -> V_37 . V_45 = V_186 ;
if ( V_9 -> V_178 > V_179 )
goto V_173;
if ( V_9 -> V_178 == V_179 )
V_32 -> V_37 . V_38 = 0 ;
else
V_32 -> V_37 . V_38 = V_9 -> V_178 ;
V_175 = V_41 | V_44 | V_182 | V_42 ;
if ( V_58 + 1 == V_187 )
V_175 |= V_43 ;
F_21 ( V_2 -> V_125 , L_10 ,
V_58 , V_186 , V_184 ,
V_175 & V_43 ? L_11 : L_12 ,
V_175 & V_42 ? L_13 : L_12 ) ;
V_32 -> V_37 . V_40 = V_175 ;
V_184 += V_186 ;
V_27 += V_186 ;
V_58 ++ ;
}
V_9 -> V_54 = V_187 ;
V_2 -> V_148 [ V_13 ] . V_150 = V_9 -> V_146 ;
return & V_9 -> V_55 ;
V_173:
V_9 -> V_40 = V_52 ;
return NULL ;
}
static int F_42 ( struct V_154 * V_153 , enum V_189 V_190 ,
unsigned long V_191 )
{
struct V_8 * V_9 = F_29 ( V_153 ) ;
struct V_192 * V_193 = ( void * ) V_191 ;
switch ( V_190 ) {
case V_194 :
F_22 ( V_9 ) ;
return 0 ;
case V_195 :
if ( V_193 -> V_123 == V_124 ) {
V_9 -> V_139 = V_193 -> V_196 ;
V_9 -> V_126 = V_193 -> V_197 ;
V_9 -> V_178 = V_193 -> V_198 ;
} else {
V_9 -> V_139 = V_193 -> V_199 ;
V_9 -> V_126 = V_193 -> V_200 ;
V_9 -> V_178 = V_193 -> V_201 ;
}
return F_23 ( V_9 ) ;
default:
return - V_202 ;
}
return - V_17 ;
}
static enum V_203 F_43 ( struct V_154 * V_153 ,
T_4 V_62 ,
struct V_204 * V_205 )
{
struct V_8 * V_9 = F_29 ( V_153 ) ;
T_4 V_206 ;
V_206 = V_153 -> V_62 ;
F_44 ( V_205 , V_9 -> V_61 , V_206 , 0 ) ;
return V_9 -> V_40 ;
}
static void F_45 ( struct V_154 * V_153 )
{
}
static void F_46 ( struct V_1 * V_2 ,
const struct V_207 * V_208 )
{
T_6 * V_209 = ( T_1 * ) V_208 ;
T_6 * V_210 = ( T_1 * ) V_2 -> V_79 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_211 ; V_58 ++ )
if ( V_209 [ V_58 ] > 0 )
V_210 [ V_58 ] = V_209 [ V_58 ] ;
}
static int T_7 F_47 ( struct V_1 * V_2 ,
const char * V_212 , int V_213 )
{
const struct V_214 * V_215 ;
char * V_216 ;
const struct V_217 * V_218 ;
int V_22 ;
const struct V_207 * V_208 ;
unsigned short * V_219 ;
V_216 = F_48 ( V_35 , L_16 , V_212 , V_213 ) ;
if ( ! V_216 )
return - V_36 ;
V_22 = F_49 ( & V_215 , V_216 , V_2 -> V_125 ) ;
if ( V_22 ) {
F_50 ( V_216 ) ;
return V_22 ;
}
F_50 ( V_216 ) ;
if ( V_215 -> V_28 < sizeof( * V_218 ) )
goto V_220;
V_218 = (struct V_217 * ) V_215 -> V_159 ;
if ( V_218 -> V_221 != V_222 )
goto V_220;
if ( V_218 -> V_223 + V_218 -> V_224 > V_215 -> V_28 )
goto V_220;
V_208 = ( void * ) V_218 + V_218 -> V_225 ;
V_219 = ( void * ) V_218 + V_218 -> V_223 ;
F_26 ( V_2 -> V_151 ) ;
F_8 ( V_2 , V_219 ,
V_218 -> V_224 ,
V_208 -> V_226 ) ;
F_37 ( V_2 -> V_151 ) ;
F_46 ( V_2 , V_208 ) ;
F_51 ( V_2 -> V_125 , L_17 ,
V_218 -> V_227 ,
V_218 -> V_228 ) ;
V_220:
F_52 ( V_215 ) ;
return V_22 ;
}
static int T_7 F_53 ( struct V_1 * V_2 )
{
int V_58 , V_22 ;
T_2 V_229 ;
switch ( V_2 -> V_5 ) {
case 1 :
V_2 -> V_230 = 32 ;
break;
case 2 :
V_2 -> V_230 = 48 ;
break;
default:
F_39 ( V_2 -> V_125 , L_18 , V_2 -> V_5 ) ;
return - V_231 ;
}
F_26 ( V_2 -> V_151 ) ;
F_4 ( 0 , V_2 -> V_18 + V_232 ) ;
V_2 -> V_148 = F_9 ( NULL ,
V_233 * sizeof ( struct V_234 ) +
sizeof( struct V_121 ) ,
& V_229 , V_35 ) ;
if ( ! V_2 -> V_148 ) {
V_22 = - V_36 ;
goto V_235;
}
V_2 -> V_122 = ( void * ) V_2 -> V_148 +
V_233 * sizeof ( struct V_234 ) ;
V_2 -> V_135 = V_229 +
V_233 * sizeof ( struct V_234 ) ;
memset ( V_2 -> V_148 , 0 ,
V_233 * sizeof ( struct V_234 ) ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_230 ; V_58 ++ )
F_4 ( 0 , V_2 -> V_18 + F_1 ( V_2 , V_58 ) ) ;
for ( V_58 = 0 ; V_58 < V_233 ; V_58 ++ )
F_4 ( 0 , V_2 -> V_18 + V_143 + V_58 * 4 ) ;
V_22 = F_25 ( & V_2 -> V_13 [ 0 ] ) ;
if ( V_22 )
goto V_235;
F_2 ( & V_2 -> V_13 [ 0 ] , false , true , false ) ;
F_4 ( 0x4050 , V_2 -> V_18 + V_236 ) ;
F_4 ( 0 , V_2 -> V_18 + V_237 ) ;
F_4 ( V_229 , V_2 -> V_18 + V_232 ) ;
F_4 ( V_238 , V_2 -> V_18 + V_237 ) ;
F_24 ( & V_2 -> V_13 [ 0 ] , 7 ) ;
F_37 ( V_2 -> V_151 ) ;
return 0 ;
V_235:
F_37 ( V_2 -> V_151 ) ;
F_39 ( V_2 -> V_125 , L_19 , V_22 ) ;
return V_22 ;
}
static int T_7 F_54 ( struct V_239 * V_240 )
{
int V_22 ;
int V_65 ;
struct V_241 * V_242 ;
struct V_243 * V_244 = V_240 -> V_125 . V_245 ;
int V_58 ;
struct V_1 * V_2 ;
V_2 = F_55 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_125 = & V_240 -> V_125 ;
V_242 = F_56 ( V_240 , V_246 , 0 ) ;
V_65 = F_57 ( V_240 , 0 ) ;
if ( ! V_242 || V_65 < 0 || ! V_244 ) {
V_22 = - V_17 ;
goto V_247;
}
if ( ! F_58 ( V_242 -> V_248 , F_59 ( V_242 ) , V_240 -> V_249 ) ) {
V_22 = - V_144 ;
goto V_250;
}
V_2 -> V_151 = F_60 ( & V_240 -> V_125 , NULL ) ;
if ( F_61 ( V_2 -> V_151 ) ) {
V_22 = F_62 ( V_2 -> V_151 ) ;
goto V_251;
}
V_2 -> V_18 = F_63 ( V_242 -> V_248 , F_59 ( V_242 ) ) ;
if ( ! V_2 -> V_18 ) {
V_22 = - V_36 ;
goto V_252;
}
V_22 = F_64 ( V_65 , F_17 , 0 , L_20 , V_2 ) ;
if ( V_22 )
goto V_253;
V_2 -> V_79 = F_55 ( sizeof( * V_2 -> V_79 ) , V_35 ) ;
if ( ! V_2 -> V_79 )
goto V_254;
V_2 -> V_5 = V_244 -> V_255 ;
F_65 ( V_256 , V_2 -> V_257 . V_258 ) ;
F_65 ( V_259 , V_2 -> V_257 . V_258 ) ;
F_66 ( & V_2 -> V_257 . V_260 ) ;
for ( V_58 = 0 ; V_58 < V_233 ; V_58 ++ ) {
struct V_8 * V_9 = & V_2 -> V_13 [ V_58 ] ;
V_9 -> V_2 = V_2 ;
F_67 ( & V_9 -> V_157 ) ;
V_9 -> V_153 . V_261 = & V_2 -> V_257 ;
V_9 -> V_13 = V_58 ;
if ( V_58 )
F_68 ( & V_9 -> V_153 . V_262 ,
& V_2 -> V_257 . V_260 ) ;
}
V_22 = F_53 ( V_2 ) ;
if ( V_22 )
goto V_263;
if ( V_244 -> V_79 )
F_46 ( V_2 , V_244 -> V_79 ) ;
F_47 ( V_2 , V_244 -> V_212 , V_244 -> V_213 ) ;
V_2 -> V_257 . V_125 = & V_240 -> V_125 ;
V_2 -> V_257 . V_264 = F_34 ;
V_2 -> V_257 . V_265 = F_36 ;
V_2 -> V_257 . V_266 = F_43 ;
V_2 -> V_257 . V_267 = F_38 ;
V_2 -> V_257 . V_268 = F_41 ;
V_2 -> V_257 . V_269 = F_42 ;
V_2 -> V_257 . V_270 = F_45 ;
V_2 -> V_257 . V_125 -> V_271 = & V_2 -> V_271 ;
F_69 ( V_2 -> V_257 . V_125 , 65535 ) ;
V_22 = F_70 ( & V_2 -> V_257 ) ;
if ( V_22 ) {
F_39 ( & V_240 -> V_125 , L_21 ) ;
goto V_263;
}
F_51 ( V_2 -> V_125 , L_22 ) ;
return 0 ;
V_263:
F_50 ( V_2 -> V_79 ) ;
V_254:
F_71 ( V_65 , V_2 ) ;
V_253:
F_72 ( V_2 -> V_18 ) ;
V_252:
F_73 ( V_2 -> V_151 ) ;
V_251:
F_74 ( V_242 -> V_248 , F_59 ( V_242 ) ) ;
V_250:
V_247:
F_50 ( V_2 ) ;
return V_22 ;
}
static int T_8 F_75 ( struct V_239 * V_240 )
{
return - V_144 ;
}
static int T_7 F_76 ( void )
{
return F_77 ( & V_272 , F_54 ) ;
}
