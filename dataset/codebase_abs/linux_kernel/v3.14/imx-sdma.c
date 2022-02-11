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
return V_21 ? 0 : - V_25 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_26 , int V_27 ,
T_1 V_28 )
{
struct V_29 * V_30 = V_2 -> V_11 [ 0 ] . V_31 ;
void * V_32 ;
T_2 V_33 ;
int V_21 ;
unsigned long V_34 ;
V_32 = F_14 ( NULL ,
V_27 ,
& V_33 , V_35 ) ;
if ( ! V_32 ) {
return - V_36 ;
}
F_15 ( & V_2 -> V_37 , V_34 ) ;
V_30 -> V_38 . V_39 = V_40 ;
V_30 -> V_38 . V_41 = V_42 | V_43 | V_44 | V_45 ;
V_30 -> V_38 . V_46 = V_27 / 2 ;
V_30 -> V_47 = V_33 ;
V_30 -> V_48 = V_28 ;
memcpy ( V_32 , V_26 , V_27 ) ;
V_21 = F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_37 , V_34 ) ;
F_17 ( NULL , V_27 , V_32 , V_33 ) ;
return V_21 ;
}
static void F_18 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
unsigned long V_49 ;
T_1 V_50 = F_1 ( V_2 , V_3 ) ;
V_49 = F_3 ( V_2 -> V_16 + V_50 ) ;
F_5 ( V_11 , & V_49 ) ;
F_6 ( V_49 , V_2 -> V_16 + V_50 ) ;
}
static void F_19 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
T_1 V_50 = F_1 ( V_2 , V_3 ) ;
unsigned long V_49 ;
V_49 = F_3 ( V_2 -> V_16 + V_50 ) ;
F_4 ( V_11 , & V_49 ) ;
F_6 ( V_49 , V_2 -> V_16 + V_50 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_29 * V_31 ;
while ( 1 ) {
V_31 = & V_7 -> V_31 [ V_7 -> V_51 ] ;
if ( V_31 -> V_38 . V_41 & V_42 )
break;
if ( V_31 -> V_38 . V_41 & V_52 )
V_7 -> V_41 = V_53 ;
else
V_7 -> V_41 = V_54 ;
V_31 -> V_38 . V_41 |= V_42 ;
V_7 -> V_51 ++ ;
V_7 -> V_51 %= V_7 -> V_55 ;
if ( V_7 -> V_56 . V_57 )
V_7 -> V_56 . V_57 ( V_7 -> V_56 . V_58 ) ;
}
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_29 * V_31 ;
int V_59 , error = 0 ;
V_7 -> V_60 = 0 ;
for ( V_59 = 0 ; V_59 < V_7 -> V_55 ; V_59 ++ ) {
V_31 = & V_7 -> V_31 [ V_59 ] ;
if ( V_31 -> V_38 . V_41 & ( V_42 | V_52 ) )
error = - V_61 ;
V_7 -> V_60 += V_31 -> V_38 . V_46 ;
}
if ( error )
V_7 -> V_41 = V_53 ;
else
V_7 -> V_41 = V_62 ;
F_22 ( & V_7 -> V_56 ) ;
if ( V_7 -> V_56 . V_57 )
V_7 -> V_56 . V_57 ( V_7 -> V_56 . V_58 ) ;
}
static void F_23 ( unsigned long V_63 )
{
struct V_6 * V_7 = (struct V_6 * ) V_63 ;
if ( V_7 -> V_34 & V_64 )
F_20 ( V_7 ) ;
else
F_21 ( V_7 ) ;
}
static T_3 F_24 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned long V_67 ;
V_67 = F_3 ( V_2 -> V_16 + V_23 ) ;
V_67 &= ~ 1 ;
F_6 ( V_67 , V_2 -> V_16 + V_23 ) ;
while ( V_67 ) {
int V_11 = F_25 ( V_67 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
F_26 ( & V_7 -> V_68 ) ;
F_4 ( V_11 , & V_67 ) ;
}
return V_69 ;
}
static void F_27 ( struct V_6 * V_7 ,
enum V_70 V_71 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_72 = 0 , V_73 = 0 ;
int V_74 = 0 , V_75 = 0 ;
V_7 -> V_76 = 0 ;
V_7 -> V_77 = 0 ;
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
V_72 = V_2 -> V_79 -> V_101 ;
V_73 = V_2 -> V_79 -> V_102 ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_72 = V_2 -> V_79 -> V_109 ;
V_73 = V_2 -> V_79 -> V_92 ;
break;
case V_110 :
V_72 = V_2 -> V_79 -> V_111 ;
V_73 = V_2 -> V_79 -> V_111 ;
V_74 = V_2 -> V_79 -> V_112 ;
break;
case V_113 :
V_72 = V_2 -> V_79 -> V_114 ;
V_73 = V_2 -> V_79 -> V_115 ;
break;
case V_116 :
V_72 = V_2 -> V_79 -> V_117 ;
break;
case V_118 :
V_72 = V_2 -> V_79 -> V_119 ;
V_73 = V_2 -> V_79 -> V_120 ;
break;
case V_121 :
V_73 = V_2 -> V_79 -> V_122 ;
break;
default:
break;
}
V_7 -> V_76 = V_72 ;
V_7 -> V_77 = V_73 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_123 ;
struct V_124 * V_125 = V_2 -> V_125 ;
struct V_29 * V_30 = V_2 -> V_11 [ 0 ] . V_31 ;
int V_21 ;
unsigned long V_34 ;
if ( V_7 -> V_126 == V_127 ) {
V_123 = V_7 -> V_76 ;
} else {
V_123 = V_7 -> V_77 ;
}
if ( V_123 < 0 )
return V_123 ;
F_29 ( V_2 -> V_24 , L_2 , V_123 ) ;
F_29 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_128 ) ;
F_29 ( V_2 -> V_24 , L_4 , V_7 -> V_129 ) ;
F_29 ( V_2 -> V_24 , L_5 , V_7 -> V_130 ) ;
F_29 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_131 [ 0 ] ) ;
F_29 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_131 [ 1 ] ) ;
F_15 ( & V_2 -> V_37 , V_34 ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> V_132 . V_133 = V_123 ;
V_125 -> V_134 [ 0 ] = V_7 -> V_131 [ 1 ] ;
V_125 -> V_134 [ 1 ] = V_7 -> V_131 [ 0 ] ;
V_125 -> V_134 [ 2 ] = V_7 -> V_130 ;
V_125 -> V_134 [ 6 ] = V_7 -> V_129 ;
V_125 -> V_134 [ 7 ] = V_7 -> V_128 ;
V_30 -> V_38 . V_39 = V_135 ;
V_30 -> V_38 . V_41 = V_42 | V_43 | V_44 | V_45 ;
V_30 -> V_38 . V_46 = sizeof( * V_125 ) / 4 ;
V_30 -> V_47 = V_2 -> V_136 ;
V_30 -> V_48 = 2048 + ( sizeof( * V_125 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_37 , V_34 ) ;
return V_21 ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_137 ) ;
V_7 -> V_41 = V_53 ;
}
static int F_31 ( struct V_6 * V_7 )
{
int V_21 ;
F_30 ( V_7 ) ;
V_7 -> V_131 [ 0 ] = 0 ;
V_7 -> V_131 [ 1 ] = 0 ;
V_7 -> V_129 = 0 ;
V_7 -> V_130 = 0 ;
if ( V_7 -> V_138 ) {
if ( V_7 -> V_138 >= V_7 -> V_2 -> V_5 -> V_139 )
return - V_15 ;
F_18 ( V_7 , V_7 -> V_138 ) ;
}
switch ( V_7 -> V_71 ) {
case V_81 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_78 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_27 ( V_7 , V_7 -> V_71 ) ;
if ( ( V_7 -> V_71 != V_78 ) &&
( V_7 -> V_71 != V_81 ) ) {
if ( V_7 -> V_140 ) {
V_7 -> V_131 [ 1 ] = F_9 ( V_7 -> V_140 % 32 ) ;
if ( V_7 -> V_140 > 31 )
F_5 ( 31 , & V_7 -> V_128 ) ;
V_7 -> V_131 [ 0 ] = F_9 ( V_7 -> V_138 % 32 ) ;
if ( V_7 -> V_138 > 31 )
F_5 ( 30 , & V_7 -> V_128 ) ;
} else {
F_5 ( V_7 -> V_138 , V_7 -> V_131 ) ;
}
V_7 -> V_128 |= V_7 -> V_128 ;
V_7 -> V_129 = V_7 -> V_141 ;
} else {
V_7 -> V_128 = 0 ;
}
V_21 = F_28 ( V_7 ) ;
return V_21 ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned int V_142 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_142 < V_143
|| V_142 > V_144 ) {
return - V_15 ;
}
F_6 ( V_142 , V_2 -> V_16 + V_145 + 4 * V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_146 ;
V_7 -> V_31 = F_14 ( NULL , V_147 , & V_7 -> V_148 , V_35 ) ;
if ( ! V_7 -> V_31 ) {
V_21 = - V_36 ;
goto V_149;
}
memset ( V_7 -> V_31 , 0 , V_147 ) ;
V_2 -> V_150 [ V_11 ] . V_151 = V_7 -> V_148 ;
V_2 -> V_150 [ V_11 ] . V_152 = V_7 -> V_148 ;
F_32 ( V_7 , V_153 ) ;
return 0 ;
V_149:
return V_21 ;
}
static struct V_6 * F_34 ( struct V_154 * V_155 )
{
return F_35 ( V_155 , struct V_6 , V_155 ) ;
}
static T_4 F_36 ( struct V_156 * V_157 )
{
unsigned long V_34 ;
struct V_6 * V_7 = F_34 ( V_157 -> V_155 ) ;
T_4 V_158 ;
F_15 ( & V_7 -> V_159 , V_34 ) ;
V_158 = F_37 ( V_157 ) ;
F_16 ( & V_7 -> V_159 , V_34 ) ;
return V_158 ;
}
static int F_38 ( struct V_154 * V_155 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
struct V_160 * V_63 = V_155 -> V_161 ;
int V_162 , V_21 ;
if ( ! V_63 )
return - V_15 ;
switch ( V_63 -> V_142 ) {
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
V_7 -> V_71 = V_63 -> V_71 ;
V_7 -> V_138 = V_63 -> V_166 ;
F_39 ( V_7 -> V_2 -> V_167 ) ;
F_39 ( V_7 -> V_2 -> V_168 ) ;
V_21 = F_33 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( V_7 , V_162 ) ;
if ( V_21 )
return V_21 ;
F_40 ( & V_7 -> V_56 , V_155 ) ;
V_7 -> V_56 . V_169 = F_36 ;
V_7 -> V_56 . V_34 = V_170 ;
return 0 ;
}
static void F_41 ( struct V_154 * V_155 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_30 ( V_7 ) ;
if ( V_7 -> V_138 )
F_19 ( V_7 , V_7 -> V_138 ) ;
if ( V_7 -> V_140 )
F_19 ( V_7 , V_7 -> V_140 ) ;
V_7 -> V_138 = 0 ;
V_7 -> V_140 = 0 ;
F_32 ( V_7 , 0 ) ;
F_17 ( NULL , V_147 , V_7 -> V_31 , V_7 -> V_148 ) ;
F_42 ( V_2 -> V_167 ) ;
F_42 ( V_2 -> V_168 ) ;
}
static struct V_156 * F_43 (
struct V_154 * V_155 , struct V_171 * V_172 ,
unsigned int V_173 , enum V_174 V_126 ,
unsigned long V_34 , void * V_125 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_59 , V_46 ;
int V_11 = V_7 -> V_11 ;
struct V_171 * V_175 ;
if ( V_7 -> V_41 == V_54 )
return NULL ;
V_7 -> V_41 = V_54 ;
V_7 -> V_34 = 0 ;
V_7 -> V_51 = 0 ;
F_29 ( V_2 -> V_24 , L_8 ,
V_173 , V_11 ) ;
V_7 -> V_126 = V_126 ;
V_21 = F_28 ( V_7 ) ;
if ( V_21 )
goto V_176;
if ( V_173 > V_177 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_173 , V_177 ) ;
V_21 = - V_15 ;
goto V_176;
}
V_7 -> V_178 = 0 ;
F_44 (sgl, sg, sg_len, i) {
struct V_29 * V_31 = & V_7 -> V_31 [ V_59 ] ;
int V_179 ;
V_31 -> V_47 = V_175 -> V_180 ;
V_46 = F_45 ( V_175 ) ;
if ( V_46 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_46 , 0xffff ) ;
V_21 = - V_15 ;
goto V_176;
}
V_31 -> V_38 . V_46 = V_46 ;
V_7 -> V_178 += V_46 ;
if ( V_7 -> V_181 > V_182 ) {
V_21 = - V_15 ;
goto V_176;
}
switch ( V_7 -> V_181 ) {
case V_182 :
V_31 -> V_38 . V_39 = 0 ;
if ( V_46 & 3 || V_175 -> V_180 & 3 )
return NULL ;
break;
case V_183 :
V_31 -> V_38 . V_39 = 2 ;
if ( V_46 & 1 || V_175 -> V_180 & 1 )
return NULL ;
break;
case V_184 :
V_31 -> V_38 . V_39 = 1 ;
break;
default:
return NULL ;
}
V_179 = V_42 | V_45 | V_185 ;
if ( V_59 + 1 == V_173 ) {
V_179 |= V_43 ;
V_179 |= V_186 ;
V_179 &= ~ V_185 ;
}
F_29 ( V_2 -> V_24 , L_11 ,
V_59 , V_46 , ( V_187 ) V_175 -> V_180 ,
V_179 & V_44 ? L_12 : L_13 ,
V_179 & V_43 ? L_14 : L_13 ) ;
V_31 -> V_38 . V_41 = V_179 ;
}
V_7 -> V_55 = V_173 ;
V_2 -> V_150 [ V_11 ] . V_152 = V_7 -> V_148 ;
return & V_7 -> V_56 ;
V_176:
V_7 -> V_41 = V_53 ;
return NULL ;
}
static struct V_156 * F_46 (
struct V_154 * V_155 , T_2 V_188 , T_5 V_189 ,
T_5 V_190 , enum V_174 V_126 ,
unsigned long V_34 , void * V_125 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_191 = V_189 / V_190 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_59 = 0 , V_26 = 0 ;
F_29 ( V_2 -> V_24 , L_15 , V_192 , V_11 ) ;
if ( V_7 -> V_41 == V_54 )
return NULL ;
V_7 -> V_41 = V_54 ;
V_7 -> V_51 = 0 ;
V_7 -> V_34 |= V_64 ;
V_7 -> V_126 = V_126 ;
V_21 = F_28 ( V_7 ) ;
if ( V_21 )
goto V_176;
if ( V_191 > V_177 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_191 , V_177 ) ;
goto V_176;
}
if ( V_190 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_190 , 0xffff ) ;
goto V_176;
}
while ( V_26 < V_189 ) {
struct V_29 * V_31 = & V_7 -> V_31 [ V_59 ] ;
int V_179 ;
V_31 -> V_47 = V_188 ;
V_31 -> V_38 . V_46 = V_190 ;
if ( V_7 -> V_181 > V_182 )
goto V_176;
if ( V_7 -> V_181 == V_182 )
V_31 -> V_38 . V_39 = 0 ;
else
V_31 -> V_38 . V_39 = V_7 -> V_181 ;
V_179 = V_42 | V_45 | V_185 | V_43 ;
if ( V_59 + 1 == V_191 )
V_179 |= V_44 ;
F_29 ( V_2 -> V_24 , L_11 ,
V_59 , V_190 , ( V_187 ) V_188 ,
V_179 & V_44 ? L_12 : L_13 ,
V_179 & V_43 ? L_14 : L_13 ) ;
V_31 -> V_38 . V_41 = V_179 ;
V_188 += V_190 ;
V_26 += V_190 ;
V_59 ++ ;
}
V_7 -> V_55 = V_191 ;
V_2 -> V_150 [ V_11 ] . V_152 = V_7 -> V_148 ;
return & V_7 -> V_56 ;
V_176:
V_7 -> V_41 = V_53 ;
return NULL ;
}
static int F_47 ( struct V_154 * V_155 , enum V_193 V_194 ,
unsigned long V_195 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
struct V_196 * V_197 = ( void * ) V_195 ;
switch ( V_194 ) {
case V_198 :
F_30 ( V_7 ) ;
return 0 ;
case V_199 :
if ( V_197 -> V_126 == V_127 ) {
V_7 -> V_141 = V_197 -> V_200 ;
V_7 -> V_128 = V_197 -> V_201 *
V_197 -> V_202 ;
V_7 -> V_181 = V_197 -> V_202 ;
} else {
V_7 -> V_141 = V_197 -> V_203 ;
V_7 -> V_128 = V_197 -> V_204 *
V_197 -> V_205 ;
V_7 -> V_181 = V_197 -> V_205 ;
}
V_7 -> V_126 = V_197 -> V_126 ;
return F_31 ( V_7 ) ;
default:
return - V_206 ;
}
return - V_15 ;
}
static enum V_207 F_48 ( struct V_154 * V_155 ,
T_4 V_158 ,
struct V_208 * V_209 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
F_49 ( V_209 , V_155 -> V_210 , V_155 -> V_158 ,
V_7 -> V_178 - V_7 -> V_60 ) ;
return V_7 -> V_41 ;
}
static void F_50 ( struct V_154 * V_155 )
{
struct V_6 * V_7 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_41 == V_54 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
const struct V_211 * V_212 )
{
T_6 * V_213 = ( T_1 * ) V_212 ;
T_6 * V_214 = ( T_1 * ) V_2 -> V_79 ;
int V_59 ;
if ( ! V_2 -> V_215 )
V_2 -> V_215 = V_216 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_215 ; V_59 ++ )
if ( V_213 [ V_59 ] > 0 )
V_214 [ V_59 ] = V_213 [ V_59 ] ;
}
static void F_52 ( const struct V_217 * V_218 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
const struct V_219 * V_220 ;
const struct V_211 * V_212 ;
unsigned short * V_221 ;
if ( ! V_218 ) {
F_12 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_218 -> V_27 < sizeof( * V_220 ) )
goto V_222;
V_220 = (struct V_219 * ) V_218 -> V_63 ;
if ( V_220 -> V_223 != V_224 )
goto V_222;
if ( V_220 -> V_225 + V_220 -> V_226 > V_218 -> V_27 )
goto V_222;
switch ( V_220 -> V_227 ) {
case 1 :
V_2 -> V_215 = V_216 ;
break;
case 2 :
V_2 -> V_215 = V_228 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_222;
}
V_212 = ( void * ) V_220 + V_220 -> V_229 ;
V_221 = ( void * ) V_220 + V_220 -> V_225 ;
F_39 ( V_2 -> V_167 ) ;
F_39 ( V_2 -> V_168 ) ;
F_13 ( V_2 , V_221 ,
V_220 -> V_226 ,
V_212 -> V_230 ) ;
F_42 ( V_2 -> V_167 ) ;
F_42 ( V_2 -> V_168 ) ;
F_51 ( V_2 , V_212 ) ;
F_53 ( V_2 -> V_24 , L_19 ,
V_220 -> V_227 ,
V_220 -> V_231 ) ;
V_222:
F_54 ( V_218 ) ;
}
static int T_7 F_55 ( struct V_1 * V_2 ,
const char * V_232 )
{
int V_21 ;
V_21 = F_56 ( V_233 ,
V_234 , V_232 , V_2 -> V_24 ,
V_35 , V_2 , F_52 ) ;
return V_21 ;
}
static int T_7 F_57 ( struct V_1 * V_2 )
{
int V_59 , V_21 ;
T_2 V_235 ;
F_39 ( V_2 -> V_167 ) ;
F_39 ( V_2 -> V_168 ) ;
F_6 ( 0 , V_2 -> V_16 + V_236 ) ;
V_2 -> V_150 = F_14 ( NULL ,
V_237 * sizeof ( struct V_238 ) +
sizeof( struct V_124 ) ,
& V_235 , V_35 ) ;
if ( ! V_2 -> V_150 ) {
V_21 = - V_36 ;
goto V_239;
}
V_2 -> V_125 = ( void * ) V_2 -> V_150 +
V_237 * sizeof ( struct V_238 ) ;
V_2 -> V_136 = V_235 +
V_237 * sizeof ( struct V_238 ) ;
memset ( V_2 -> V_150 , 0 ,
V_237 * sizeof ( struct V_238 ) ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_5 -> V_139 ; V_59 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_59 ) ) ;
for ( V_59 = 0 ; V_59 < V_237 ; V_59 ++ )
F_6 ( 0 , V_2 -> V_16 + V_145 + V_59 * 4 ) ;
V_21 = F_33 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_239;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_240 ) ;
F_6 ( 0 , V_2 -> V_16 + V_241 ) ;
F_6 ( V_235 , V_2 -> V_16 + V_236 ) ;
F_6 ( V_242 , V_2 -> V_16 + V_241 ) ;
F_32 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_42 ( V_2 -> V_167 ) ;
F_42 ( V_2 -> V_168 ) ;
return 0 ;
V_239:
F_42 ( V_2 -> V_167 ) ;
F_42 ( V_2 -> V_168 ) ;
F_12 ( V_2 -> V_24 , L_20 , V_21 ) ;
return V_21 ;
}
static bool F_58 ( struct V_154 * V_155 , void * V_243 )
{
struct V_160 * V_63 = V_243 ;
if ( ! F_59 ( V_155 ) )
return false ;
V_155 -> V_161 = V_63 ;
return true ;
}
static struct V_154 * F_60 ( struct V_244 * V_245 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_247 -> V_248 ;
T_8 V_249 = V_2 -> V_250 . V_251 ;
struct V_160 V_63 ;
if ( V_245 -> V_252 != 3 )
return NULL ;
V_63 . V_166 = V_245 -> args [ 0 ] ;
V_63 . V_71 = V_245 -> args [ 1 ] ;
V_63 . V_142 = V_245 -> args [ 2 ] ;
return F_61 ( V_249 , F_58 , & V_63 ) ;
}
static int T_7 F_62 ( struct V_253 * V_254 )
{
const struct V_255 * V_256 =
F_63 ( V_257 , & V_254 -> V_24 ) ;
struct V_258 * V_259 = V_254 -> V_24 . V_260 ;
const char * V_232 ;
int V_21 ;
int V_65 ;
struct V_261 * V_262 ;
struct V_263 * V_264 = F_64 ( & V_254 -> V_24 ) ;
int V_59 ;
struct V_1 * V_2 ;
T_6 * V_214 ;
const struct V_265 * V_5 = NULL ;
if ( V_256 )
V_5 = V_256 -> V_63 ;
else if ( V_254 -> V_266 )
V_5 = ( void * ) V_254 -> V_266 -> V_267 ;
if ( ! V_5 ) {
F_12 ( & V_254 -> V_24 , L_21 ) ;
return - V_15 ;
}
V_21 = F_65 ( & V_254 -> V_24 , F_66 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_67 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_68 ( & V_2 -> V_37 ) ;
V_2 -> V_24 = & V_254 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_262 = F_69 ( V_254 , V_268 , 0 ) ;
V_65 = F_70 ( V_254 , 0 ) ;
if ( ! V_262 || V_65 < 0 ) {
V_21 = - V_15 ;
goto V_269;
}
if ( ! F_71 ( V_262 -> V_270 , F_72 ( V_262 ) , V_254 -> V_271 ) ) {
V_21 = - V_146 ;
goto V_272;
}
V_2 -> V_167 = F_73 ( & V_254 -> V_24 , L_22 ) ;
if ( F_74 ( V_2 -> V_167 ) ) {
V_21 = F_75 ( V_2 -> V_167 ) ;
goto V_273;
}
V_2 -> V_168 = F_73 ( & V_254 -> V_24 , L_23 ) ;
if ( F_74 ( V_2 -> V_168 ) ) {
V_21 = F_75 ( V_2 -> V_168 ) ;
goto V_273;
}
F_76 ( V_2 -> V_167 ) ;
F_76 ( V_2 -> V_168 ) ;
V_2 -> V_16 = F_77 ( V_262 -> V_270 , F_72 ( V_262 ) ) ;
if ( ! V_2 -> V_16 ) {
V_21 = - V_36 ;
goto V_274;
}
V_21 = F_78 ( V_65 , F_24 , 0 , L_24 , V_2 ) ;
if ( V_21 )
goto V_275;
V_2 -> V_79 = F_67 ( sizeof( * V_2 -> V_79 ) , V_35 ) ;
if ( ! V_2 -> V_79 ) {
V_21 = - V_36 ;
goto V_276;
}
V_214 = ( T_6 * ) V_2 -> V_79 ;
for ( V_59 = 0 ; V_59 < V_216 ; V_59 ++ )
V_214 [ V_59 ] = - V_15 ;
F_79 ( V_277 , V_2 -> V_250 . V_251 ) ;
F_79 ( V_278 , V_2 -> V_250 . V_251 ) ;
F_80 ( & V_2 -> V_250 . V_279 ) ;
for ( V_59 = 0 ; V_59 < V_237 ; V_59 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_59 ] ;
V_7 -> V_2 = V_2 ;
F_68 ( & V_7 -> V_159 ) ;
V_7 -> V_155 . V_280 = & V_2 -> V_250 ;
F_81 ( & V_7 -> V_155 ) ;
V_7 -> V_11 = V_59 ;
F_82 ( & V_7 -> V_68 , F_23 ,
( unsigned long ) V_7 ) ;
if ( V_59 )
F_83 ( & V_7 -> V_155 . V_258 ,
& V_2 -> V_250 . V_279 ) ;
}
V_21 = F_57 ( V_2 ) ;
if ( V_21 )
goto V_281;
if ( V_2 -> V_5 -> V_79 )
F_51 ( V_2 , V_2 -> V_5 -> V_79 ) ;
if ( V_264 && V_264 -> V_79 )
F_51 ( V_2 , V_264 -> V_79 ) ;
if ( V_264 ) {
V_21 = F_55 ( V_2 , V_264 -> V_232 ) ;
if ( V_21 )
F_84 ( & V_254 -> V_24 , L_25 ) ;
} else {
V_21 = F_85 ( V_259 , L_26 ,
& V_232 ) ;
if ( V_21 )
F_84 ( & V_254 -> V_24 , L_27 ) ;
else {
V_21 = F_55 ( V_2 , V_232 ) ;
if ( V_21 )
F_84 ( & V_254 -> V_24 , L_28 ) ;
}
}
V_2 -> V_250 . V_24 = & V_254 -> V_24 ;
V_2 -> V_250 . V_282 = F_38 ;
V_2 -> V_250 . V_283 = F_41 ;
V_2 -> V_250 . V_284 = F_48 ;
V_2 -> V_250 . V_285 = F_43 ;
V_2 -> V_250 . V_286 = F_46 ;
V_2 -> V_250 . V_287 = F_47 ;
V_2 -> V_250 . V_288 = F_50 ;
V_2 -> V_250 . V_24 -> V_289 = & V_2 -> V_289 ;
F_86 ( V_2 -> V_250 . V_24 , 65535 ) ;
V_21 = F_87 ( & V_2 -> V_250 ) ;
if ( V_21 ) {
F_12 ( & V_254 -> V_24 , L_29 ) ;
goto V_281;
}
if ( V_259 ) {
V_21 = F_88 ( V_259 , F_60 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_254 -> V_24 , L_30 ) ;
goto V_290;
}
}
F_53 ( V_2 -> V_24 , L_31 ) ;
return 0 ;
V_290:
F_89 ( & V_2 -> V_250 ) ;
V_281:
F_90 ( V_2 -> V_79 ) ;
V_276:
F_91 ( V_65 , V_2 ) ;
V_275:
F_92 ( V_2 -> V_16 ) ;
V_274:
V_273:
F_93 ( V_262 -> V_270 , F_72 ( V_262 ) ) ;
V_272:
V_269:
F_90 ( V_2 ) ;
return V_21 ;
}
static int F_94 ( struct V_253 * V_254 )
{
return - V_146 ;
}
static int T_7 F_95 ( void )
{
return F_96 ( & V_291 , F_62 ) ;
}
