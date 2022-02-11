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
V_10 -> V_65 = V_10 -> V_58 . V_66 ;
if ( V_10 -> V_58 . V_59 )
V_10 -> V_58 . V_59 ( V_10 -> V_58 . V_60 ) ;
}
static void F_17 ( struct V_9 * V_10 )
{
F_18 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_14 == 0 )
return;
if ( V_10 -> V_67 & V_68 )
F_15 ( V_10 ) ;
else
F_16 ( V_10 ) ;
}
static T_3 F_19 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
T_1 V_71 ;
V_71 = F_3 ( V_2 -> V_19 + V_72 ) ;
F_4 ( V_71 , V_2 -> V_19 + V_72 ) ;
while ( V_71 ) {
int V_14 = F_20 ( V_71 ) - 1 ;
struct V_9 * V_10 = & V_2 -> V_14 [ V_14 ] ;
F_17 ( V_10 ) ;
V_71 &= ~ ( 1 << V_14 ) ;
}
return V_73 ;
}
static void F_21 ( struct V_9 * V_10 ,
enum V_74 V_75 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_76 = 0 , V_77 = 0 ;
int V_78 = 0 , V_79 = 0 ;
V_10 -> V_80 = 0 ;
V_10 -> V_81 = 0 ;
switch ( V_75 ) {
case V_82 :
V_79 = V_2 -> V_83 -> V_84 ;
break;
case V_85 :
V_77 = V_2 -> V_83 -> V_86 ;
V_76 = V_2 -> V_83 -> V_87 ;
break;
case V_88 :
V_76 = V_2 -> V_83 -> V_89 ;
V_77 = V_2 -> V_83 -> V_90 ;
break;
case V_91 :
V_76 = V_2 -> V_83 -> V_92 ;
V_77 = V_2 -> V_83 -> V_93 ;
break;
case V_94 :
V_76 = V_2 -> V_83 -> V_95 ;
V_77 = V_2 -> V_83 -> V_96 ;
break;
case V_97 :
V_76 = V_2 -> V_83 -> V_98 ;
V_77 = V_2 -> V_83 -> V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
V_76 = V_2 -> V_83 -> V_103 ;
V_77 = V_2 -> V_83 -> V_93 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
V_76 = V_2 -> V_83 -> V_110 ;
V_77 = V_2 -> V_83 -> V_96 ;
break;
case V_111 :
V_76 = V_2 -> V_83 -> V_112 ;
V_77 = V_2 -> V_83 -> V_112 ;
V_78 = V_2 -> V_83 -> V_113 ;
break;
case V_114 :
V_76 = V_2 -> V_83 -> V_115 ;
V_77 = V_2 -> V_83 -> V_116 ;
break;
case V_117 :
V_76 = V_2 -> V_83 -> V_118 ;
break;
case V_119 :
V_76 = V_2 -> V_83 -> V_120 ;
V_77 = V_2 -> V_83 -> V_121 ;
break;
case V_122 :
V_77 = V_2 -> V_83 -> V_123 ;
break;
default:
break;
}
V_10 -> V_80 = V_76 ;
V_10 -> V_81 = V_77 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_124 ;
struct V_125 * V_126 = V_2 -> V_126 ;
struct V_31 * V_32 = V_2 -> V_14 [ 0 ] . V_33 ;
int V_23 ;
if ( V_10 -> V_127 == V_128 ) {
V_124 = V_10 -> V_80 ;
} else {
V_124 = V_10 -> V_81 ;
}
if ( V_124 < 0 )
return V_124 ;
F_23 ( V_2 -> V_129 , L_1 , V_124 ) ;
F_23 ( V_2 -> V_129 , L_2 , V_10 -> V_130 ) ;
F_23 ( V_2 -> V_129 , L_3 , V_10 -> V_131 ) ;
F_23 ( V_2 -> V_129 , L_4 , V_10 -> V_132 ) ;
F_23 ( V_2 -> V_129 , L_5 , V_10 -> V_133 ) ;
F_23 ( V_2 -> V_129 , L_6 , V_10 -> V_134 ) ;
F_9 ( & V_2 -> V_36 ) ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> V_135 . V_136 = V_124 ;
V_126 -> V_137 [ 0 ] = V_10 -> V_134 ;
V_126 -> V_137 [ 1 ] = V_10 -> V_133 ;
V_126 -> V_137 [ 2 ] = V_10 -> V_132 ;
V_126 -> V_137 [ 6 ] = V_10 -> V_131 ;
V_126 -> V_137 [ 7 ] = V_10 -> V_130 ;
V_32 -> V_40 . V_41 = V_138 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = sizeof( * V_126 ) / 4 ;
V_32 -> V_49 = V_2 -> V_139 ;
V_32 -> V_50 = 2048 + ( sizeof( * V_126 ) / 4 ) * V_14 ;
V_23 = F_5 ( & V_2 -> V_14 [ 0 ] ) ;
F_12 ( & V_2 -> V_36 ) ;
return V_23 ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
F_4 ( 1 << V_14 , V_2 -> V_19 + V_140 ) ;
V_10 -> V_43 = V_55 ;
}
static int F_25 ( struct V_9 * V_10 )
{
int V_23 ;
F_24 ( V_10 ) ;
V_10 -> V_133 = 0 ;
V_10 -> V_134 = 0 ;
V_10 -> V_131 = 0 ;
V_10 -> V_132 = 0 ;
if ( V_10 -> V_141 ) {
if ( V_10 -> V_141 > 32 )
return - V_18 ;
F_13 ( V_10 , V_10 -> V_141 ) ;
}
switch ( V_10 -> V_75 ) {
case V_85 :
F_2 ( V_10 , false , true , true ) ;
break;
case V_82 :
F_2 ( V_10 , false , true , false ) ;
break;
default:
F_2 ( V_10 , true , true , false ) ;
break;
}
F_21 ( V_10 , V_10 -> V_75 ) ;
if ( ( V_10 -> V_75 != V_82 ) &&
( V_10 -> V_75 != V_85 ) ) {
if ( V_10 -> V_142 ) {
V_10 -> V_134 = 1 << ( V_10 -> V_142 % 32 ) ;
if ( V_10 -> V_142 > 31 )
V_10 -> V_130 |= 1 << 31 ;
V_10 -> V_133 = 1 << ( V_10 -> V_141 % 32 ) ;
if ( V_10 -> V_141 > 31 )
V_10 -> V_130 |= 1 << 30 ;
} else {
V_10 -> V_133 = 1 << V_10 -> V_141 ;
V_10 -> V_134 = 1 << ( V_10 -> V_141 - 32 ) ;
}
V_10 -> V_130 |= V_10 -> V_130 ;
V_10 -> V_131 = V_10 -> V_143 ;
} else {
V_10 -> V_130 = 0 ;
}
V_23 = F_22 ( V_10 ) ;
return V_23 ;
}
static int F_26 ( struct V_9 * V_10 ,
unsigned int V_144 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
if ( V_144 < V_145
|| V_144 > V_146 ) {
return - V_18 ;
}
F_4 ( V_144 , V_2 -> V_19 + V_147 + 4 * V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_23 = - V_148 ;
V_10 -> V_33 = F_10 ( NULL , V_149 , & V_10 -> V_150 , V_37 ) ;
if ( ! V_10 -> V_33 ) {
V_23 = - V_38 ;
goto V_151;
}
memset ( V_10 -> V_33 , 0 , V_149 ) ;
V_2 -> V_152 [ V_14 ] . V_153 = V_10 -> V_150 ;
V_2 -> V_152 [ V_14 ] . V_154 = V_10 -> V_150 ;
F_28 ( V_2 -> V_155 ) ;
F_26 ( V_10 , V_156 ) ;
F_6 ( & V_10 -> V_24 ) ;
V_10 -> V_53 = 0 ;
return 0 ;
V_151:
return V_23 ;
}
static void F_29 ( struct V_1 * V_2 , int V_14 )
{
F_4 ( 1 << V_14 , V_2 -> V_19 + V_25 ) ;
}
static T_4 F_30 ( struct V_9 * V_10 )
{
T_4 V_66 = V_10 -> V_157 . V_66 ;
if ( ++ V_66 < 0 )
V_66 = 1 ;
V_10 -> V_157 . V_66 = V_66 ;
V_10 -> V_58 . V_66 = V_66 ;
return V_66 ;
}
static struct V_9 * F_31 ( struct V_158 * V_157 )
{
return F_32 ( V_157 , struct V_9 , V_157 ) ;
}
static T_4 F_33 ( struct V_159 * V_160 )
{
unsigned long V_67 ;
struct V_9 * V_10 = F_31 ( V_160 -> V_157 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_4 V_66 ;
F_34 ( & V_10 -> V_161 , V_67 ) ;
V_66 = F_30 ( V_10 ) ;
F_29 ( V_2 , V_10 -> V_14 ) ;
F_35 ( & V_10 -> V_161 , V_67 ) ;
return V_66 ;
}
static int F_36 ( struct V_158 * V_157 )
{
struct V_9 * V_10 = F_31 ( V_157 ) ;
struct V_162 * V_163 = V_157 -> V_164 ;
int V_165 , V_23 ;
if ( ! V_163 )
return - V_18 ;
switch ( V_163 -> V_144 ) {
case V_166 :
V_165 = 3 ;
break;
case V_167 :
V_165 = 2 ;
break;
case V_168 :
default:
V_165 = 1 ;
break;
}
V_10 -> V_75 = V_163 -> V_75 ;
V_10 -> V_141 = V_163 -> V_169 ;
V_23 = F_26 ( V_10 , V_165 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_27 ( V_10 ) ;
if ( V_23 )
return V_23 ;
F_37 ( & V_10 -> V_58 , V_157 ) ;
V_10 -> V_58 . V_170 = F_33 ;
V_10 -> V_58 . V_67 = V_171 ;
return 0 ;
}
static void F_38 ( struct V_158 * V_157 )
{
struct V_9 * V_10 = F_31 ( V_157 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_24 ( V_10 ) ;
if ( V_10 -> V_141 )
F_14 ( V_10 , V_10 -> V_141 ) ;
if ( V_10 -> V_142 )
F_14 ( V_10 , V_10 -> V_142 ) ;
V_10 -> V_141 = 0 ;
V_10 -> V_142 = 0 ;
F_26 ( V_10 , 0 ) ;
F_11 ( NULL , V_149 , V_10 -> V_33 , V_10 -> V_150 ) ;
F_39 ( V_2 -> V_155 ) ;
}
static struct V_159 * F_40 (
struct V_158 * V_157 , struct V_172 * V_173 ,
unsigned int V_174 , enum V_175 V_127 ,
unsigned long V_67 )
{
struct V_9 * V_10 = F_31 ( V_157 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_23 , V_61 , V_48 ;
int V_14 = V_10 -> V_14 ;
struct V_172 * V_176 ;
if ( V_10 -> V_43 == V_56 )
return NULL ;
V_10 -> V_43 = V_56 ;
V_10 -> V_67 = 0 ;
F_23 ( V_2 -> V_129 , L_7 ,
V_174 , V_14 ) ;
V_10 -> V_127 = V_127 ;
V_23 = F_22 ( V_10 ) ;
if ( V_23 )
goto V_39;
if ( V_174 > V_177 ) {
F_41 ( V_2 -> V_129 , L_8 ,
V_14 , V_174 , V_177 ) ;
V_23 = - V_18 ;
goto V_39;
}
V_10 -> V_178 = 0 ;
F_42 (sgl, sg, sg_len, i) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_61 ] ;
int V_179 ;
V_33 -> V_49 = V_176 -> V_180 ;
V_48 = V_176 -> V_181 ;
if ( V_48 > 0xffff ) {
F_41 ( V_2 -> V_129 , L_9 ,
V_14 , V_48 , 0xffff ) ;
V_23 = - V_18 ;
goto V_39;
}
V_33 -> V_40 . V_48 = V_48 ;
V_10 -> V_178 += V_48 ;
if ( V_10 -> V_182 > V_183 ) {
V_23 = - V_18 ;
goto V_39;
}
switch ( V_10 -> V_182 ) {
case V_183 :
V_33 -> V_40 . V_41 = 0 ;
if ( V_48 & 3 || V_176 -> V_180 & 3 )
return NULL ;
break;
case V_184 :
V_33 -> V_40 . V_41 = 2 ;
if ( V_48 & 1 || V_176 -> V_180 & 1 )
return NULL ;
break;
case V_185 :
V_33 -> V_40 . V_41 = 1 ;
break;
default:
return NULL ;
}
V_179 = V_44 | V_47 | V_186 ;
if ( V_61 + 1 == V_174 ) {
V_179 |= V_45 ;
V_179 |= V_187 ;
V_179 &= ~ V_186 ;
}
F_23 ( V_2 -> V_129 , L_10 ,
V_61 , V_48 , V_176 -> V_180 ,
V_179 & V_46 ? L_11 : L_12 ,
V_179 & V_45 ? L_13 : L_12 ) ;
V_33 -> V_40 . V_43 = V_179 ;
}
V_10 -> V_57 = V_174 ;
V_2 -> V_152 [ V_14 ] . V_154 = V_10 -> V_150 ;
return & V_10 -> V_58 ;
V_39:
V_10 -> V_43 = V_55 ;
return NULL ;
}
static struct V_159 * F_43 (
struct V_158 * V_157 , T_2 V_188 , T_5 V_189 ,
T_5 V_190 , enum V_175 V_127 )
{
struct V_9 * V_10 = F_31 ( V_157 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_191 = V_189 / V_190 ;
int V_14 = V_10 -> V_14 ;
int V_23 , V_61 = 0 , V_28 = 0 ;
F_23 ( V_2 -> V_129 , L_14 , V_192 , V_14 ) ;
if ( V_10 -> V_43 == V_56 )
return NULL ;
V_10 -> V_43 = V_56 ;
V_10 -> V_67 |= V_68 ;
V_10 -> V_127 = V_127 ;
V_23 = F_22 ( V_10 ) ;
if ( V_23 )
goto V_39;
if ( V_191 > V_177 ) {
F_41 ( V_2 -> V_129 , L_8 ,
V_14 , V_191 , V_177 ) ;
goto V_39;
}
if ( V_190 > 0xffff ) {
F_41 ( V_2 -> V_129 , L_15 ,
V_14 , V_190 , 0xffff ) ;
goto V_39;
}
while ( V_28 < V_189 ) {
struct V_31 * V_33 = & V_10 -> V_33 [ V_61 ] ;
int V_179 ;
V_33 -> V_49 = V_188 ;
V_33 -> V_40 . V_48 = V_190 ;
if ( V_10 -> V_182 > V_183 )
goto V_39;
if ( V_10 -> V_182 == V_183 )
V_33 -> V_40 . V_41 = 0 ;
else
V_33 -> V_40 . V_41 = V_10 -> V_182 ;
V_179 = V_44 | V_47 | V_186 | V_45 ;
if ( V_61 + 1 == V_191 )
V_179 |= V_46 ;
F_23 ( V_2 -> V_129 , L_10 ,
V_61 , V_190 , V_188 ,
V_179 & V_46 ? L_11 : L_12 ,
V_179 & V_45 ? L_13 : L_12 ) ;
V_33 -> V_40 . V_43 = V_179 ;
V_188 += V_190 ;
V_28 += V_190 ;
V_61 ++ ;
}
V_10 -> V_57 = V_191 ;
V_2 -> V_152 [ V_14 ] . V_154 = V_10 -> V_150 ;
return & V_10 -> V_58 ;
V_39:
V_10 -> V_43 = V_55 ;
return NULL ;
}
static int F_44 ( struct V_158 * V_157 , enum V_193 V_194 ,
unsigned long V_195 )
{
struct V_9 * V_10 = F_31 ( V_157 ) ;
struct V_196 * V_197 = ( void * ) V_195 ;
switch ( V_194 ) {
case V_198 :
F_24 ( V_10 ) ;
return 0 ;
case V_199 :
if ( V_197 -> V_127 == V_128 ) {
V_10 -> V_143 = V_197 -> V_200 ;
V_10 -> V_130 = V_197 -> V_201 *
V_197 -> V_202 ;
V_10 -> V_182 = V_197 -> V_202 ;
} else {
V_10 -> V_143 = V_197 -> V_203 ;
V_10 -> V_130 = V_197 -> V_204 *
V_197 -> V_205 ;
V_10 -> V_182 = V_197 -> V_205 ;
}
V_10 -> V_127 = V_197 -> V_127 ;
return F_25 ( V_10 ) ;
default:
return - V_206 ;
}
return - V_18 ;
}
static enum V_207 F_45 ( struct V_158 * V_157 ,
T_4 V_66 ,
struct V_208 * V_209 )
{
struct V_9 * V_10 = F_31 ( V_157 ) ;
T_4 V_210 ;
V_210 = V_157 -> V_66 ;
F_46 ( V_209 , V_10 -> V_65 , V_210 ,
V_10 -> V_178 - V_10 -> V_62 ) ;
return V_10 -> V_43 ;
}
static void F_47 ( struct V_158 * V_157 )
{
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_211 * V_212 )
{
T_6 * V_213 = ( T_1 * ) V_212 ;
T_6 * V_214 = ( T_1 * ) V_2 -> V_83 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_215 ; V_61 ++ )
if ( V_213 [ V_61 ] > 0 )
V_214 [ V_61 ] = V_213 [ V_61 ] ;
}
static void F_49 ( const struct V_216 * V_217 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
const struct V_218 * V_219 ;
const struct V_211 * V_212 ;
unsigned short * V_220 ;
if ( ! V_217 ) {
F_41 ( V_2 -> V_129 , L_16 ) ;
return;
}
if ( V_217 -> V_29 < sizeof( * V_219 ) )
goto V_221;
V_219 = (struct V_218 * ) V_217 -> V_163 ;
if ( V_219 -> V_222 != V_223 )
goto V_221;
if ( V_219 -> V_224 + V_219 -> V_225 > V_217 -> V_29 )
goto V_221;
V_212 = ( void * ) V_219 + V_219 -> V_226 ;
V_220 = ( void * ) V_219 + V_219 -> V_224 ;
F_28 ( V_2 -> V_155 ) ;
F_8 ( V_2 , V_220 ,
V_219 -> V_225 ,
V_212 -> V_227 ) ;
F_39 ( V_2 -> V_155 ) ;
F_48 ( V_2 , V_212 ) ;
F_50 ( V_2 -> V_129 , L_17 ,
V_219 -> V_228 ,
V_219 -> V_229 ) ;
V_221:
F_51 ( V_217 ) ;
}
static int T_7 F_52 ( struct V_1 * V_2 ,
const char * V_230 )
{
int V_23 ;
V_23 = F_53 ( V_231 ,
V_232 , V_230 , V_2 -> V_129 ,
V_37 , V_2 , F_49 ) ;
return V_23 ;
}
static int T_7 F_54 ( struct V_1 * V_2 )
{
int V_61 , V_23 ;
T_2 V_233 ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_234 = 32 ;
break;
case V_235 :
V_2 -> V_234 = 48 ;
break;
default:
F_41 ( V_2 -> V_129 , L_18 ,
V_2 -> V_5 ) ;
return - V_236 ;
}
F_28 ( V_2 -> V_155 ) ;
F_4 ( 0 , V_2 -> V_19 + V_237 ) ;
V_2 -> V_152 = F_10 ( NULL ,
V_238 * sizeof ( struct V_239 ) +
sizeof( struct V_125 ) ,
& V_233 , V_37 ) ;
if ( ! V_2 -> V_152 ) {
V_23 = - V_38 ;
goto V_240;
}
V_2 -> V_126 = ( void * ) V_2 -> V_152 +
V_238 * sizeof ( struct V_239 ) ;
V_2 -> V_139 = V_233 +
V_238 * sizeof ( struct V_239 ) ;
memset ( V_2 -> V_152 , 0 ,
V_238 * sizeof ( struct V_239 ) ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_234 ; V_61 ++ )
F_4 ( 0 , V_2 -> V_19 + F_1 ( V_2 , V_61 ) ) ;
for ( V_61 = 0 ; V_61 < V_238 ; V_61 ++ )
F_4 ( 0 , V_2 -> V_19 + V_147 + V_61 * 4 ) ;
V_23 = F_27 ( & V_2 -> V_14 [ 0 ] ) ;
if ( V_23 )
goto V_240;
F_2 ( & V_2 -> V_14 [ 0 ] , false , true , false ) ;
F_4 ( 0x4050 , V_2 -> V_19 + V_241 ) ;
F_4 ( 0 , V_2 -> V_19 + V_242 ) ;
F_4 ( V_233 , V_2 -> V_19 + V_237 ) ;
F_4 ( V_243 , V_2 -> V_19 + V_242 ) ;
F_26 ( & V_2 -> V_14 [ 0 ] , 7 ) ;
F_39 ( V_2 -> V_155 ) ;
return 0 ;
V_240:
F_39 ( V_2 -> V_155 ) ;
F_41 ( V_2 -> V_129 , L_19 , V_23 ) ;
return V_23 ;
}
static int T_7 F_55 ( struct V_244 * V_245 )
{
const struct V_246 * V_247 =
F_56 ( V_248 , & V_245 -> V_129 ) ;
struct V_249 * V_250 = V_245 -> V_129 . V_251 ;
const char * V_230 ;
int V_23 ;
int V_69 ;
struct V_252 * V_253 ;
struct V_254 * V_255 = V_245 -> V_129 . V_256 ;
int V_61 ;
struct V_1 * V_2 ;
T_6 * V_214 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
F_58 ( & V_2 -> V_36 ) ;
V_2 -> V_129 = & V_245 -> V_129 ;
V_253 = F_59 ( V_245 , V_257 , 0 ) ;
V_69 = F_60 ( V_245 , 0 ) ;
if ( ! V_253 || V_69 < 0 ) {
V_23 = - V_18 ;
goto V_258;
}
if ( ! F_61 ( V_253 -> V_259 , F_62 ( V_253 ) , V_245 -> V_260 ) ) {
V_23 = - V_148 ;
goto V_261;
}
V_2 -> V_155 = F_63 ( & V_245 -> V_129 , NULL ) ;
if ( F_64 ( V_2 -> V_155 ) ) {
V_23 = F_65 ( V_2 -> V_155 ) ;
goto V_262;
}
V_2 -> V_19 = F_66 ( V_253 -> V_259 , F_62 ( V_253 ) ) ;
if ( ! V_2 -> V_19 ) {
V_23 = - V_38 ;
goto V_263;
}
V_23 = F_67 ( V_69 , F_19 , 0 , L_20 , V_2 ) ;
if ( V_23 )
goto V_264;
V_2 -> V_83 = F_57 ( sizeof( * V_2 -> V_83 ) , V_37 ) ;
if ( ! V_2 -> V_83 ) {
V_23 = - V_38 ;
goto V_265;
}
V_214 = ( T_6 * ) V_2 -> V_83 ;
for ( V_61 = 0 ; V_61 < V_215 ; V_61 ++ )
V_214 [ V_61 ] = - V_18 ;
if ( V_247 )
V_245 -> V_266 = V_247 -> V_163 ;
V_2 -> V_5 = V_245 -> V_266 -> V_267 ;
F_68 ( V_268 , V_2 -> V_269 . V_270 ) ;
F_68 ( V_271 , V_2 -> V_269 . V_270 ) ;
F_69 ( & V_2 -> V_269 . V_272 ) ;
for ( V_61 = 0 ; V_61 < V_238 ; V_61 ++ ) {
struct V_9 * V_10 = & V_2 -> V_14 [ V_61 ] ;
V_10 -> V_2 = V_2 ;
F_70 ( & V_10 -> V_161 ) ;
V_10 -> V_157 . V_273 = & V_2 -> V_269 ;
V_10 -> V_14 = V_61 ;
if ( V_61 )
F_71 ( & V_10 -> V_157 . V_249 ,
& V_2 -> V_269 . V_272 ) ;
}
V_23 = F_54 ( V_2 ) ;
if ( V_23 )
goto V_274;
if ( V_255 && V_255 -> V_83 )
F_48 ( V_2 , V_255 -> V_83 ) ;
if ( V_255 ) {
F_52 ( V_2 , V_255 -> V_230 ) ;
} else {
V_23 = F_72 ( V_250 , L_21 ,
& V_230 ) ;
if ( V_23 ) {
F_41 ( & V_245 -> V_129 , L_22 ) ;
goto V_274;
}
V_23 = F_52 ( V_2 , V_230 ) ;
if ( V_23 ) {
F_41 ( & V_245 -> V_129 , L_23 ) ;
goto V_274;
}
}
V_2 -> V_269 . V_129 = & V_245 -> V_129 ;
V_2 -> V_269 . V_275 = F_36 ;
V_2 -> V_269 . V_276 = F_38 ;
V_2 -> V_269 . V_277 = F_45 ;
V_2 -> V_269 . V_278 = F_40 ;
V_2 -> V_269 . V_279 = F_43 ;
V_2 -> V_269 . V_280 = F_44 ;
V_2 -> V_269 . V_281 = F_47 ;
V_2 -> V_269 . V_129 -> V_282 = & V_2 -> V_282 ;
F_73 ( V_2 -> V_269 . V_129 , 65535 ) ;
V_23 = F_74 ( & V_2 -> V_269 ) ;
if ( V_23 ) {
F_41 ( & V_245 -> V_129 , L_24 ) ;
goto V_274;
}
F_50 ( V_2 -> V_129 , L_25 ) ;
return 0 ;
V_274:
F_75 ( V_2 -> V_83 ) ;
V_265:
F_76 ( V_69 , V_2 ) ;
V_264:
F_77 ( V_2 -> V_19 ) ;
V_263:
F_78 ( V_2 -> V_155 ) ;
V_262:
F_79 ( V_253 -> V_259 , F_62 ( V_253 ) ) ;
V_261:
V_258:
F_75 ( V_2 ) ;
return V_23 ;
}
static int T_8 F_80 ( struct V_244 * V_245 )
{
return - V_148 ;
}
static int T_7 F_81 ( void )
{
return F_82 ( & V_283 , F_55 ) ;
}
