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
if ( V_7 -> V_51 . V_52 )
V_7 -> V_51 . V_52 ( V_7 -> V_51 . V_53 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_29 * V_31 ;
while ( 1 ) {
V_31 = & V_7 -> V_31 [ V_7 -> V_54 ] ;
if ( V_31 -> V_38 . V_41 & V_42 )
break;
if ( V_31 -> V_38 . V_41 & V_55 )
V_7 -> V_41 = V_56 ;
V_31 -> V_38 . V_41 |= V_42 ;
V_7 -> V_54 ++ ;
V_7 -> V_54 %= V_7 -> V_57 ;
}
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_29 * V_31 ;
int V_58 , error = 0 ;
V_7 -> V_59 = 0 ;
for ( V_58 = 0 ; V_58 < V_7 -> V_57 ; V_58 ++ ) {
V_31 = & V_7 -> V_31 [ V_58 ] ;
if ( V_31 -> V_38 . V_41 & ( V_42 | V_55 ) )
error = - V_60 ;
V_7 -> V_59 += V_31 -> V_38 . V_46 ;
}
if ( error )
V_7 -> V_41 = V_56 ;
else
V_7 -> V_41 = V_61 ;
F_23 ( & V_7 -> V_51 ) ;
if ( V_7 -> V_51 . V_52 )
V_7 -> V_51 . V_52 ( V_7 -> V_51 . V_53 ) ;
}
static void F_24 ( unsigned long V_62 )
{
struct V_6 * V_7 = (struct V_6 * ) V_62 ;
if ( V_7 -> V_34 & V_63 )
F_20 ( V_7 ) ;
else
F_22 ( V_7 ) ;
}
static T_3 F_25 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned long V_66 ;
V_66 = F_3 ( V_2 -> V_16 + V_23 ) ;
V_66 &= ~ 1 ;
F_6 ( V_66 , V_2 -> V_16 + V_23 ) ;
while ( V_66 ) {
int V_11 = F_26 ( V_66 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
if ( V_7 -> V_34 & V_63 )
F_21 ( V_7 ) ;
F_27 ( & V_7 -> V_67 ) ;
F_4 ( V_11 , & V_66 ) ;
}
return V_68 ;
}
static void F_28 ( struct V_6 * V_7 ,
enum V_69 V_70 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_71 = 0 , V_72 = 0 ;
int V_73 = 0 , V_74 = 0 ;
V_7 -> V_75 = 0 ;
V_7 -> V_76 = 0 ;
switch ( V_70 ) {
case V_77 :
V_74 = V_2 -> V_78 -> V_79 ;
break;
case V_80 :
V_72 = V_2 -> V_78 -> V_81 ;
V_71 = V_2 -> V_78 -> V_82 ;
break;
case V_83 :
V_71 = V_2 -> V_78 -> V_84 ;
V_72 = V_2 -> V_78 -> V_85 ;
break;
case V_86 :
V_71 = V_2 -> V_78 -> V_87 ;
V_72 = V_2 -> V_78 -> V_88 ;
break;
case V_89 :
V_71 = V_2 -> V_78 -> V_90 ;
V_72 = V_2 -> V_78 -> V_91 ;
break;
case V_92 :
V_71 = V_2 -> V_78 -> V_93 ;
V_72 = V_2 -> V_78 -> V_94 ;
break;
case V_95 :
case V_96 :
case V_97 :
V_71 = V_2 -> V_78 -> V_98 ;
V_72 = V_2 -> V_78 -> V_88 ;
break;
case V_99 :
V_71 = V_2 -> V_78 -> V_100 ;
V_72 = V_2 -> V_78 -> V_101 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_71 = V_2 -> V_78 -> V_108 ;
V_72 = V_2 -> V_78 -> V_91 ;
break;
case V_109 :
V_71 = V_2 -> V_78 -> V_110 ;
V_72 = V_2 -> V_78 -> V_110 ;
V_73 = V_2 -> V_78 -> V_111 ;
break;
case V_112 :
V_71 = V_2 -> V_78 -> V_108 ;
V_72 = V_2 -> V_78 -> V_91 ;
V_73 = V_2 -> V_78 -> V_111 ;
break;
case V_113 :
V_71 = V_2 -> V_78 -> V_114 ;
V_72 = V_2 -> V_78 -> V_115 ;
break;
case V_116 :
V_71 = V_2 -> V_78 -> V_117 ;
break;
case V_118 :
V_71 = V_2 -> V_78 -> V_119 ;
V_72 = V_2 -> V_78 -> V_120 ;
break;
case V_121 :
V_72 = V_2 -> V_78 -> V_122 ;
break;
default:
break;
}
V_7 -> V_75 = V_71 ;
V_7 -> V_76 = V_72 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_123 ;
struct V_124 * V_125 = V_2 -> V_125 ;
struct V_29 * V_30 = V_2 -> V_11 [ 0 ] . V_31 ;
int V_21 ;
unsigned long V_34 ;
if ( V_7 -> V_126 == V_127 ) {
V_123 = V_7 -> V_75 ;
} else {
V_123 = V_7 -> V_76 ;
}
if ( V_123 < 0 )
return V_123 ;
F_30 ( V_2 -> V_24 , L_2 , V_123 ) ;
F_30 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_128 ) ;
F_30 ( V_2 -> V_24 , L_4 , V_7 -> V_129 ) ;
F_30 ( V_2 -> V_24 , L_5 , V_7 -> V_130 ) ;
F_30 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_131 [ 0 ] ) ;
F_30 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_131 [ 1 ] ) ;
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
static void F_31 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_137 ) ;
V_7 -> V_41 = V_56 ;
}
static int F_32 ( struct V_6 * V_7 )
{
int V_21 ;
F_31 ( V_7 ) ;
V_7 -> V_131 [ 0 ] = 0 ;
V_7 -> V_131 [ 1 ] = 0 ;
V_7 -> V_129 = 0 ;
V_7 -> V_130 = 0 ;
if ( V_7 -> V_138 ) {
if ( V_7 -> V_138 >= V_7 -> V_2 -> V_5 -> V_139 )
return - V_15 ;
F_18 ( V_7 , V_7 -> V_138 ) ;
}
switch ( V_7 -> V_70 ) {
case V_80 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_77 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_28 ( V_7 , V_7 -> V_70 ) ;
if ( ( V_7 -> V_70 != V_77 ) &&
( V_7 -> V_70 != V_80 ) ) {
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
V_21 = F_29 ( V_7 ) ;
return V_21 ;
}
static int F_33 ( struct V_6 * V_7 ,
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
static int F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_146 ;
V_7 -> V_31 = F_35 ( NULL , V_147 , & V_7 -> V_148 ,
V_35 ) ;
if ( ! V_7 -> V_31 ) {
V_21 = - V_36 ;
goto V_149;
}
V_2 -> V_150 [ V_11 ] . V_151 = V_7 -> V_148 ;
V_2 -> V_150 [ V_11 ] . V_152 = V_7 -> V_148 ;
F_33 ( V_7 , V_153 ) ;
return 0 ;
V_149:
return V_21 ;
}
static struct V_6 * F_36 ( struct V_154 * V_155 )
{
return F_37 ( V_155 , struct V_6 , V_155 ) ;
}
static T_4 F_38 ( struct V_156 * V_157 )
{
unsigned long V_34 ;
struct V_6 * V_7 = F_36 ( V_157 -> V_155 ) ;
T_4 V_158 ;
F_15 ( & V_7 -> V_159 , V_34 ) ;
V_158 = F_39 ( V_157 ) ;
F_16 ( & V_7 -> V_159 , V_34 ) ;
return V_158 ;
}
static int F_40 ( struct V_154 * V_155 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_160 * V_62 = V_155 -> V_161 ;
int V_162 , V_21 ;
if ( ! V_62 )
return - V_15 ;
switch ( V_62 -> V_142 ) {
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
V_7 -> V_70 = V_62 -> V_70 ;
V_7 -> V_138 = V_62 -> V_166 ;
F_41 ( V_7 -> V_2 -> V_167 ) ;
F_41 ( V_7 -> V_2 -> V_168 ) ;
V_21 = F_34 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_33 ( V_7 , V_162 ) ;
if ( V_21 )
return V_21 ;
F_42 ( & V_7 -> V_51 , V_155 ) ;
V_7 -> V_51 . V_169 = F_38 ;
V_7 -> V_51 . V_34 = V_170 ;
return 0 ;
}
static void F_43 ( struct V_154 * V_155 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_31 ( V_7 ) ;
if ( V_7 -> V_138 )
F_19 ( V_7 , V_7 -> V_138 ) ;
if ( V_7 -> V_140 )
F_19 ( V_7 , V_7 -> V_140 ) ;
V_7 -> V_138 = 0 ;
V_7 -> V_140 = 0 ;
F_33 ( V_7 , 0 ) ;
F_17 ( NULL , V_147 , V_7 -> V_31 , V_7 -> V_148 ) ;
F_44 ( V_2 -> V_167 ) ;
F_44 ( V_2 -> V_168 ) ;
}
static struct V_156 * F_45 (
struct V_154 * V_155 , struct V_171 * V_172 ,
unsigned int V_173 , enum V_174 V_126 ,
unsigned long V_34 , void * V_125 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_58 , V_46 ;
int V_11 = V_7 -> V_11 ;
struct V_171 * V_175 ;
if ( V_7 -> V_41 == V_176 )
return NULL ;
V_7 -> V_41 = V_176 ;
V_7 -> V_34 = 0 ;
V_7 -> V_54 = 0 ;
F_30 ( V_2 -> V_24 , L_8 ,
V_173 , V_11 ) ;
V_7 -> V_126 = V_126 ;
V_21 = F_29 ( V_7 ) ;
if ( V_21 )
goto V_177;
if ( V_173 > V_178 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_173 , V_178 ) ;
V_21 = - V_15 ;
goto V_177;
}
V_7 -> V_179 = 0 ;
F_46 (sgl, sg, sg_len, i) {
struct V_29 * V_31 = & V_7 -> V_31 [ V_58 ] ;
int V_180 ;
V_31 -> V_47 = V_175 -> V_181 ;
V_46 = F_47 ( V_175 ) ;
if ( V_46 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_46 , 0xffff ) ;
V_21 = - V_15 ;
goto V_177;
}
V_31 -> V_38 . V_46 = V_46 ;
V_7 -> V_179 += V_46 ;
if ( V_7 -> V_182 > V_183 ) {
V_21 = - V_15 ;
goto V_177;
}
switch ( V_7 -> V_182 ) {
case V_183 :
V_31 -> V_38 . V_39 = 0 ;
if ( V_46 & 3 || V_175 -> V_181 & 3 )
return NULL ;
break;
case V_184 :
V_31 -> V_38 . V_39 = 2 ;
if ( V_46 & 1 || V_175 -> V_181 & 1 )
return NULL ;
break;
case V_185 :
V_31 -> V_38 . V_39 = 1 ;
break;
default:
return NULL ;
}
V_180 = V_42 | V_45 | V_186 ;
if ( V_58 + 1 == V_173 ) {
V_180 |= V_43 ;
V_180 |= V_187 ;
V_180 &= ~ V_186 ;
}
F_30 ( V_2 -> V_24 , L_11 ,
V_58 , V_46 , ( V_188 ) V_175 -> V_181 ,
V_180 & V_44 ? L_12 : L_13 ,
V_180 & V_43 ? L_14 : L_13 ) ;
V_31 -> V_38 . V_41 = V_180 ;
}
V_7 -> V_57 = V_173 ;
V_2 -> V_150 [ V_11 ] . V_152 = V_7 -> V_148 ;
return & V_7 -> V_51 ;
V_177:
V_7 -> V_41 = V_56 ;
return NULL ;
}
static struct V_156 * F_48 (
struct V_154 * V_155 , T_2 V_189 , T_5 V_190 ,
T_5 V_191 , enum V_174 V_126 ,
unsigned long V_34 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_192 = V_190 / V_191 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_58 = 0 , V_26 = 0 ;
F_30 ( V_2 -> V_24 , L_15 , V_193 , V_11 ) ;
if ( V_7 -> V_41 == V_176 )
return NULL ;
V_7 -> V_41 = V_176 ;
V_7 -> V_54 = 0 ;
V_7 -> V_191 = V_191 ;
V_7 -> V_34 |= V_63 ;
V_7 -> V_126 = V_126 ;
V_21 = F_29 ( V_7 ) ;
if ( V_21 )
goto V_177;
if ( V_192 > V_178 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_192 , V_178 ) ;
goto V_177;
}
if ( V_191 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_191 , 0xffff ) ;
goto V_177;
}
while ( V_26 < V_190 ) {
struct V_29 * V_31 = & V_7 -> V_31 [ V_58 ] ;
int V_180 ;
V_31 -> V_47 = V_189 ;
V_31 -> V_38 . V_46 = V_191 ;
if ( V_7 -> V_182 > V_183 )
goto V_177;
if ( V_7 -> V_182 == V_183 )
V_31 -> V_38 . V_39 = 0 ;
else
V_31 -> V_38 . V_39 = V_7 -> V_182 ;
V_180 = V_42 | V_45 | V_186 | V_43 ;
if ( V_58 + 1 == V_192 )
V_180 |= V_44 ;
F_30 ( V_2 -> V_24 , L_11 ,
V_58 , V_191 , ( V_188 ) V_189 ,
V_180 & V_44 ? L_12 : L_13 ,
V_180 & V_43 ? L_14 : L_13 ) ;
V_31 -> V_38 . V_41 = V_180 ;
V_189 += V_191 ;
V_26 += V_191 ;
V_58 ++ ;
}
V_7 -> V_57 = V_192 ;
V_2 -> V_150 [ V_11 ] . V_152 = V_7 -> V_148 ;
return & V_7 -> V_51 ;
V_177:
V_7 -> V_41 = V_56 ;
return NULL ;
}
static int F_49 ( struct V_154 * V_155 , enum V_194 V_195 ,
unsigned long V_196 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_197 * V_198 = ( void * ) V_196 ;
switch ( V_195 ) {
case V_199 :
F_31 ( V_7 ) ;
return 0 ;
case V_200 :
if ( V_198 -> V_126 == V_127 ) {
V_7 -> V_141 = V_198 -> V_201 ;
V_7 -> V_128 = V_198 -> V_202 *
V_198 -> V_203 ;
V_7 -> V_182 = V_198 -> V_203 ;
} else {
V_7 -> V_141 = V_198 -> V_204 ;
V_7 -> V_128 = V_198 -> V_205 *
V_198 -> V_206 ;
V_7 -> V_182 = V_198 -> V_206 ;
}
V_7 -> V_126 = V_198 -> V_126 ;
return F_32 ( V_7 ) ;
default:
return - V_207 ;
}
return - V_15 ;
}
static enum V_208 F_50 ( struct V_154 * V_155 ,
T_4 V_158 ,
struct V_209 * V_210 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
T_1 V_211 ;
if ( V_7 -> V_34 & V_63 )
V_211 = ( V_7 -> V_57 - V_7 -> V_54 ) * V_7 -> V_191 ;
else
V_211 = V_7 -> V_179 - V_7 -> V_59 ;
F_51 ( V_210 , V_155 -> V_212 , V_155 -> V_158 ,
V_211 ) ;
return V_7 -> V_41 ;
}
static void F_52 ( struct V_154 * V_155 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_41 == V_176 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
const struct V_213 * V_214 )
{
T_6 * V_215 = ( T_1 * ) V_214 ;
T_6 * V_216 = ( T_1 * ) V_2 -> V_78 ;
int V_58 ;
if ( ! V_2 -> V_217 )
V_2 -> V_217 = V_218 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_217 ; V_58 ++ )
if ( V_215 [ V_58 ] > 0 )
V_216 [ V_58 ] = V_215 [ V_58 ] ;
}
static void F_54 ( const struct V_219 * V_220 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
const struct V_221 * V_222 ;
const struct V_213 * V_214 ;
unsigned short * V_223 ;
if ( ! V_220 ) {
F_12 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_220 -> V_27 < sizeof( * V_222 ) )
goto V_224;
V_222 = (struct V_221 * ) V_220 -> V_62 ;
if ( V_222 -> V_225 != V_226 )
goto V_224;
if ( V_222 -> V_227 + V_222 -> V_228 > V_220 -> V_27 )
goto V_224;
switch ( V_222 -> V_229 ) {
case 1 :
V_2 -> V_217 = V_218 ;
break;
case 2 :
V_2 -> V_217 = V_230 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_224;
}
V_214 = ( void * ) V_222 + V_222 -> V_231 ;
V_223 = ( void * ) V_222 + V_222 -> V_227 ;
F_41 ( V_2 -> V_167 ) ;
F_41 ( V_2 -> V_168 ) ;
F_13 ( V_2 , V_223 ,
V_222 -> V_228 ,
V_214 -> V_232 ) ;
F_44 ( V_2 -> V_167 ) ;
F_44 ( V_2 -> V_168 ) ;
F_53 ( V_2 , V_214 ) ;
F_55 ( V_2 -> V_24 , L_19 ,
V_222 -> V_229 ,
V_222 -> V_233 ) ;
V_224:
F_56 ( V_220 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
const char * V_234 )
{
int V_21 ;
V_21 = F_58 ( V_235 ,
V_236 , V_234 , V_2 -> V_24 ,
V_35 , V_2 , F_54 ) ;
return V_21 ;
}
static int T_7 F_59 ( struct V_1 * V_2 )
{
int V_58 , V_21 ;
T_2 V_237 ;
F_41 ( V_2 -> V_167 ) ;
F_41 ( V_2 -> V_168 ) ;
F_6 ( 0 , V_2 -> V_16 + V_238 ) ;
V_2 -> V_150 = F_14 ( NULL ,
V_239 * sizeof ( struct V_240 ) +
sizeof( struct V_124 ) ,
& V_237 , V_35 ) ;
if ( ! V_2 -> V_150 ) {
V_21 = - V_36 ;
goto V_241;
}
V_2 -> V_125 = ( void * ) V_2 -> V_150 +
V_239 * sizeof ( struct V_240 ) ;
V_2 -> V_136 = V_237 +
V_239 * sizeof ( struct V_240 ) ;
memset ( V_2 -> V_150 , 0 ,
V_239 * sizeof ( struct V_240 ) ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_5 -> V_139 ; V_58 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_58 ) ) ;
for ( V_58 = 0 ; V_58 < V_239 ; V_58 ++ )
F_6 ( 0 , V_2 -> V_16 + V_145 + V_58 * 4 ) ;
V_21 = F_34 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_241;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_242 ) ;
F_6 ( 0 , V_2 -> V_16 + V_243 ) ;
F_6 ( V_237 , V_2 -> V_16 + V_238 ) ;
F_6 ( V_244 , V_2 -> V_16 + V_243 ) ;
F_33 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_44 ( V_2 -> V_167 ) ;
F_44 ( V_2 -> V_168 ) ;
return 0 ;
V_241:
F_44 ( V_2 -> V_167 ) ;
F_44 ( V_2 -> V_168 ) ;
F_12 ( V_2 -> V_24 , L_20 , V_21 ) ;
return V_21 ;
}
static bool F_60 ( struct V_154 * V_155 , void * V_245 )
{
struct V_6 * V_7 = F_36 ( V_155 ) ;
struct V_160 * V_62 = V_245 ;
if ( ! F_61 ( V_155 ) )
return false ;
V_7 -> V_62 = * V_62 ;
V_155 -> V_161 = & V_7 -> V_62 ;
return true ;
}
static struct V_154 * F_62 ( struct V_246 * V_247 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = V_249 -> V_250 ;
T_8 V_251 = V_2 -> V_252 . V_253 ;
struct V_160 V_62 ;
if ( V_247 -> V_254 != 3 )
return NULL ;
V_62 . V_166 = V_247 -> args [ 0 ] ;
V_62 . V_70 = V_247 -> args [ 1 ] ;
V_62 . V_142 = V_247 -> args [ 2 ] ;
return F_63 ( V_251 , F_60 , & V_62 ) ;
}
static int F_64 ( struct V_255 * V_256 )
{
const struct V_257 * V_258 =
F_65 ( V_259 , & V_256 -> V_24 ) ;
struct V_260 * V_261 = V_256 -> V_24 . V_262 ;
const char * V_234 ;
int V_21 ;
int V_64 ;
struct V_263 * V_264 ;
struct V_265 * V_266 = F_66 ( & V_256 -> V_24 ) ;
int V_58 ;
struct V_1 * V_2 ;
T_6 * V_216 ;
const struct V_267 * V_5 = NULL ;
if ( V_258 )
V_5 = V_258 -> V_62 ;
else if ( V_256 -> V_268 )
V_5 = ( void * ) V_256 -> V_268 -> V_269 ;
if ( ! V_5 ) {
F_12 ( & V_256 -> V_24 , L_21 ) ;
return - V_15 ;
}
V_21 = F_67 ( & V_256 -> V_24 , F_68 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_69 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_70 ( & V_2 -> V_37 ) ;
V_2 -> V_24 = & V_256 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_264 = F_71 ( V_256 , V_270 , 0 ) ;
V_64 = F_72 ( V_256 , 0 ) ;
if ( ! V_264 || V_64 < 0 ) {
V_21 = - V_15 ;
goto V_271;
}
if ( ! F_73 ( V_264 -> V_272 , F_74 ( V_264 ) , V_256 -> V_273 ) ) {
V_21 = - V_146 ;
goto V_274;
}
V_2 -> V_167 = F_75 ( & V_256 -> V_24 , L_22 ) ;
if ( F_76 ( V_2 -> V_167 ) ) {
V_21 = F_77 ( V_2 -> V_167 ) ;
goto V_275;
}
V_2 -> V_168 = F_75 ( & V_256 -> V_24 , L_23 ) ;
if ( F_76 ( V_2 -> V_168 ) ) {
V_21 = F_77 ( V_2 -> V_168 ) ;
goto V_275;
}
F_78 ( V_2 -> V_167 ) ;
F_78 ( V_2 -> V_168 ) ;
V_2 -> V_16 = F_79 ( V_264 -> V_272 , F_74 ( V_264 ) ) ;
if ( ! V_2 -> V_16 ) {
V_21 = - V_36 ;
goto V_276;
}
V_21 = F_80 ( V_64 , F_25 , 0 , L_24 , V_2 ) ;
if ( V_21 )
goto V_277;
V_2 -> V_78 = F_69 ( sizeof( * V_2 -> V_78 ) , V_35 ) ;
if ( ! V_2 -> V_78 ) {
V_21 = - V_36 ;
goto V_278;
}
V_216 = ( T_6 * ) V_2 -> V_78 ;
for ( V_58 = 0 ; V_58 < V_218 ; V_58 ++ )
V_216 [ V_58 ] = - V_15 ;
F_81 ( V_279 , V_2 -> V_252 . V_253 ) ;
F_81 ( V_280 , V_2 -> V_252 . V_253 ) ;
F_82 ( & V_2 -> V_252 . V_281 ) ;
for ( V_58 = 0 ; V_58 < V_239 ; V_58 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_58 ] ;
V_7 -> V_2 = V_2 ;
F_70 ( & V_7 -> V_159 ) ;
V_7 -> V_155 . V_282 = & V_2 -> V_252 ;
F_83 ( & V_7 -> V_155 ) ;
V_7 -> V_11 = V_58 ;
F_84 ( & V_7 -> V_67 , F_24 ,
( unsigned long ) V_7 ) ;
if ( V_58 )
F_85 ( & V_7 -> V_155 . V_260 ,
& V_2 -> V_252 . V_281 ) ;
}
V_21 = F_59 ( V_2 ) ;
if ( V_21 )
goto V_283;
if ( V_2 -> V_5 -> V_78 )
F_53 ( V_2 , V_2 -> V_5 -> V_78 ) ;
if ( V_266 && V_266 -> V_78 )
F_53 ( V_2 , V_266 -> V_78 ) ;
if ( V_266 ) {
V_21 = F_57 ( V_2 , V_266 -> V_234 ) ;
if ( V_21 )
F_86 ( & V_256 -> V_24 , L_25 ) ;
} else {
V_21 = F_87 ( V_261 , L_26 ,
& V_234 ) ;
if ( V_21 )
F_86 ( & V_256 -> V_24 , L_27 ) ;
else {
V_21 = F_57 ( V_2 , V_234 ) ;
if ( V_21 )
F_86 ( & V_256 -> V_24 , L_28 ) ;
}
}
V_2 -> V_252 . V_24 = & V_256 -> V_24 ;
V_2 -> V_252 . V_284 = F_40 ;
V_2 -> V_252 . V_285 = F_43 ;
V_2 -> V_252 . V_286 = F_50 ;
V_2 -> V_252 . V_287 = F_45 ;
V_2 -> V_252 . V_288 = F_48 ;
V_2 -> V_252 . V_289 = F_49 ;
V_2 -> V_252 . V_290 = F_52 ;
V_2 -> V_252 . V_24 -> V_291 = & V_2 -> V_291 ;
F_88 ( V_2 -> V_252 . V_24 , 65535 ) ;
F_89 ( V_256 , V_2 ) ;
V_21 = F_90 ( & V_2 -> V_252 ) ;
if ( V_21 ) {
F_12 ( & V_256 -> V_24 , L_29 ) ;
goto V_283;
}
if ( V_261 ) {
V_21 = F_91 ( V_261 , F_62 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_256 -> V_24 , L_30 ) ;
goto V_292;
}
}
F_55 ( V_2 -> V_24 , L_31 ) ;
return 0 ;
V_292:
F_92 ( & V_2 -> V_252 ) ;
V_283:
F_93 ( V_2 -> V_78 ) ;
V_278:
F_94 ( V_64 , V_2 ) ;
V_277:
F_95 ( V_2 -> V_16 ) ;
V_276:
V_275:
F_96 ( V_264 -> V_272 , F_74 ( V_264 ) ) ;
V_274:
V_271:
F_93 ( V_2 ) ;
return V_21 ;
}
static int F_97 ( struct V_255 * V_256 )
{
struct V_1 * V_2 = F_98 ( V_256 ) ;
struct V_263 * V_264 = F_71 ( V_256 , V_270 , 0 ) ;
int V_64 = F_72 ( V_256 , 0 ) ;
int V_58 ;
F_92 ( & V_2 -> V_252 ) ;
F_93 ( V_2 -> V_78 ) ;
F_94 ( V_64 , V_2 ) ;
F_95 ( V_2 -> V_16 ) ;
F_96 ( V_264 -> V_272 , F_74 ( V_264 ) ) ;
for ( V_58 = 0 ; V_58 < V_239 ; V_58 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_58 ] ;
F_99 ( & V_7 -> V_67 ) ;
}
F_93 ( V_2 ) ;
F_89 ( V_256 , NULL ) ;
F_55 ( & V_256 -> V_24 , L_32 ) ;
return 0 ;
}
