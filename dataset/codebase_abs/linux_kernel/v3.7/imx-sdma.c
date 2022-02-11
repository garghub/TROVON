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
static int F_10 ( struct V_1 * V_2 )
{
int V_24 ;
unsigned long V_25 = 500 ;
F_7 ( V_2 , 0 ) ;
while ( ! ( V_24 = F_3 ( V_2 -> V_19 + V_26 ) & 1 ) ) {
if ( V_25 -- <= 0 )
break;
F_11 ( 1 ) ;
}
if ( V_24 ) {
F_6 ( V_24 , V_2 -> V_19 + V_26 ) ;
} else {
F_12 ( V_2 -> V_27 , L_1 ) ;
}
return V_24 ? 0 : - V_28 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_29 , int V_30 ,
T_1 V_31 )
{
struct V_32 * V_33 = V_2 -> V_14 [ 0 ] . V_34 ;
void * V_35 ;
T_2 V_36 ;
int V_24 ;
unsigned long V_37 ;
V_35 = F_14 ( NULL ,
V_30 ,
& V_36 , V_38 ) ;
if ( ! V_35 ) {
return - V_39 ;
}
F_15 ( & V_2 -> V_40 , V_37 ) ;
V_33 -> V_41 . V_42 = V_43 ;
V_33 -> V_41 . V_44 = V_45 | V_46 | V_47 | V_48 ;
V_33 -> V_41 . V_49 = V_30 / 2 ;
V_33 -> V_50 = V_36 ;
V_33 -> V_51 = V_31 ;
memcpy ( V_35 , V_29 , V_30 ) ;
V_24 = F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_40 , V_37 ) ;
F_17 ( NULL , V_30 , V_35 , V_36 ) ;
return V_24 ;
}
static void F_18 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
unsigned long V_52 ;
T_1 V_53 = F_1 ( V_2 , V_3 ) ;
V_52 = F_3 ( V_2 -> V_19 + V_53 ) ;
F_5 ( V_14 , & V_52 ) ;
F_6 ( V_52 , V_2 -> V_19 + V_53 ) ;
}
static void F_19 ( struct V_9 * V_10 , unsigned int V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
T_1 V_53 = F_1 ( V_2 , V_3 ) ;
unsigned long V_52 ;
V_52 = F_3 ( V_2 -> V_19 + V_53 ) ;
F_4 ( V_14 , & V_52 ) ;
F_6 ( V_52 , V_2 -> V_19 + V_53 ) ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_32 * V_34 ;
while ( 1 ) {
V_34 = & V_10 -> V_34 [ V_10 -> V_54 ] ;
if ( V_34 -> V_41 . V_44 & V_45 )
break;
if ( V_34 -> V_41 . V_44 & V_55 )
V_10 -> V_44 = V_56 ;
else
V_10 -> V_44 = V_57 ;
V_34 -> V_41 . V_44 |= V_45 ;
V_10 -> V_54 ++ ;
V_10 -> V_54 %= V_10 -> V_58 ;
if ( V_10 -> V_59 . V_60 )
V_10 -> V_59 . V_60 ( V_10 -> V_59 . V_61 ) ;
}
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_32 * V_34 ;
int V_62 , error = 0 ;
V_10 -> V_63 = 0 ;
for ( V_62 = 0 ; V_62 < V_10 -> V_58 ; V_62 ++ ) {
V_34 = & V_10 -> V_34 [ V_62 ] ;
if ( V_34 -> V_41 . V_44 & ( V_45 | V_55 ) )
error = - V_64 ;
V_10 -> V_63 += V_34 -> V_41 . V_49 ;
}
if ( error )
V_10 -> V_44 = V_56 ;
else
V_10 -> V_44 = V_65 ;
F_22 ( & V_10 -> V_59 ) ;
if ( V_10 -> V_59 . V_60 )
V_10 -> V_59 . V_60 ( V_10 -> V_59 . V_61 ) ;
}
static void F_23 ( unsigned long V_66 )
{
struct V_9 * V_10 = (struct V_9 * ) V_66 ;
F_24 ( & V_10 -> V_67 ) ;
if ( V_10 -> V_37 & V_68 )
F_20 ( V_10 ) ;
else
F_21 ( V_10 ) ;
}
static T_3 F_25 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
unsigned long V_71 ;
V_71 = F_3 ( V_2 -> V_19 + V_26 ) ;
V_71 &= ~ 1 ;
F_6 ( V_71 , V_2 -> V_19 + V_26 ) ;
while ( V_71 ) {
int V_14 = F_26 ( V_71 ) - 1 ;
struct V_9 * V_10 = & V_2 -> V_14 [ V_14 ] ;
F_27 ( & V_10 -> V_72 ) ;
F_4 ( V_14 , & V_71 ) ;
}
return V_73 ;
}
static void F_28 ( struct V_9 * V_10 ,
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
static int F_29 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_124 ;
struct V_125 * V_126 = V_2 -> V_126 ;
struct V_32 * V_33 = V_2 -> V_14 [ 0 ] . V_34 ;
int V_24 ;
unsigned long V_37 ;
if ( V_10 -> V_127 == V_128 ) {
V_124 = V_10 -> V_80 ;
} else {
V_124 = V_10 -> V_81 ;
}
if ( V_124 < 0 )
return V_124 ;
F_30 ( V_2 -> V_27 , L_2 , V_124 ) ;
F_30 ( V_2 -> V_27 , L_3 , ( T_1 ) V_10 -> V_129 ) ;
F_30 ( V_2 -> V_27 , L_4 , V_10 -> V_130 ) ;
F_30 ( V_2 -> V_27 , L_5 , V_10 -> V_131 ) ;
F_30 ( V_2 -> V_27 , L_6 , ( T_1 ) V_10 -> V_132 [ 0 ] ) ;
F_30 ( V_2 -> V_27 , L_7 , ( T_1 ) V_10 -> V_132 [ 1 ] ) ;
F_15 ( & V_2 -> V_40 , V_37 ) ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> V_133 . V_134 = V_124 ;
V_126 -> V_135 [ 0 ] = V_10 -> V_132 [ 1 ] ;
V_126 -> V_135 [ 1 ] = V_10 -> V_132 [ 0 ] ;
V_126 -> V_135 [ 2 ] = V_10 -> V_131 ;
V_126 -> V_135 [ 6 ] = V_10 -> V_130 ;
V_126 -> V_135 [ 7 ] = V_10 -> V_129 ;
V_33 -> V_41 . V_42 = V_136 ;
V_33 -> V_41 . V_44 = V_45 | V_46 | V_47 | V_48 ;
V_33 -> V_41 . V_49 = sizeof( * V_126 ) / 4 ;
V_33 -> V_50 = V_2 -> V_137 ;
V_33 -> V_51 = 2048 + ( sizeof( * V_126 ) / 4 ) * V_14 ;
V_24 = F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_40 , V_37 ) ;
return V_24 ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
F_6 ( F_9 ( V_14 ) , V_2 -> V_19 + V_138 ) ;
V_10 -> V_44 = V_56 ;
}
static int F_32 ( struct V_9 * V_10 )
{
int V_24 ;
F_31 ( V_10 ) ;
V_10 -> V_132 [ 0 ] = 0 ;
V_10 -> V_132 [ 1 ] = 0 ;
V_10 -> V_130 = 0 ;
V_10 -> V_131 = 0 ;
if ( V_10 -> V_139 ) {
if ( V_10 -> V_139 >= V_10 -> V_2 -> V_140 )
return - V_18 ;
F_18 ( V_10 , V_10 -> V_139 ) ;
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
F_28 ( V_10 , V_10 -> V_75 ) ;
if ( ( V_10 -> V_75 != V_82 ) &&
( V_10 -> V_75 != V_85 ) ) {
if ( V_10 -> V_141 ) {
V_10 -> V_132 [ 1 ] = F_9 ( V_10 -> V_141 % 32 ) ;
if ( V_10 -> V_141 > 31 )
F_5 ( 31 , & V_10 -> V_129 ) ;
V_10 -> V_132 [ 0 ] = F_9 ( V_10 -> V_139 % 32 ) ;
if ( V_10 -> V_139 > 31 )
F_5 ( 30 , & V_10 -> V_129 ) ;
} else {
F_5 ( V_10 -> V_139 , V_10 -> V_132 ) ;
}
V_10 -> V_129 |= V_10 -> V_129 ;
V_10 -> V_130 = V_10 -> V_142 ;
} else {
V_10 -> V_129 = 0 ;
}
V_24 = F_29 ( V_10 ) ;
return V_24 ;
}
static int F_33 ( struct V_9 * V_10 ,
unsigned int V_143 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
if ( V_143 < V_144
|| V_143 > V_145 ) {
return - V_18 ;
}
F_6 ( V_143 , V_2 -> V_19 + V_146 + 4 * V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 = V_10 -> V_14 ;
int V_24 = - V_147 ;
V_10 -> V_34 = F_14 ( NULL , V_148 , & V_10 -> V_149 , V_38 ) ;
if ( ! V_10 -> V_34 ) {
V_24 = - V_39 ;
goto V_150;
}
memset ( V_10 -> V_34 , 0 , V_148 ) ;
V_2 -> V_151 [ V_14 ] . V_152 = V_10 -> V_149 ;
V_2 -> V_151 [ V_14 ] . V_153 = V_10 -> V_149 ;
F_33 ( V_10 , V_154 ) ;
F_35 ( & V_10 -> V_67 ) ;
return 0 ;
V_150:
return V_24 ;
}
static struct V_9 * F_36 ( struct V_155 * V_156 )
{
return F_37 ( V_156 , struct V_9 , V_156 ) ;
}
static T_4 F_38 ( struct V_157 * V_158 )
{
unsigned long V_37 ;
struct V_9 * V_10 = F_36 ( V_158 -> V_156 ) ;
T_4 V_159 ;
F_15 ( & V_10 -> V_160 , V_37 ) ;
V_159 = F_39 ( V_158 ) ;
F_16 ( & V_10 -> V_160 , V_37 ) ;
return V_159 ;
}
static int F_40 ( struct V_155 * V_156 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
struct V_161 * V_66 = V_156 -> V_162 ;
int V_163 , V_24 ;
if ( ! V_66 )
return - V_18 ;
switch ( V_66 -> V_143 ) {
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
V_10 -> V_75 = V_66 -> V_75 ;
V_10 -> V_139 = V_66 -> V_167 ;
F_41 ( V_10 -> V_2 -> V_168 ) ;
F_41 ( V_10 -> V_2 -> V_169 ) ;
V_24 = F_34 ( V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_33 ( V_10 , V_163 ) ;
if ( V_24 )
return V_24 ;
F_42 ( & V_10 -> V_59 , V_156 ) ;
V_10 -> V_59 . V_170 = F_38 ;
V_10 -> V_59 . V_37 = V_171 ;
return 0 ;
}
static void F_43 ( struct V_155 * V_156 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_31 ( V_10 ) ;
if ( V_10 -> V_139 )
F_19 ( V_10 , V_10 -> V_139 ) ;
if ( V_10 -> V_141 )
F_19 ( V_10 , V_10 -> V_141 ) ;
V_10 -> V_139 = 0 ;
V_10 -> V_141 = 0 ;
F_33 ( V_10 , 0 ) ;
F_17 ( NULL , V_148 , V_10 -> V_34 , V_10 -> V_149 ) ;
F_44 ( V_2 -> V_168 ) ;
F_44 ( V_2 -> V_169 ) ;
}
static struct V_157 * F_45 (
struct V_155 * V_156 , struct V_172 * V_173 ,
unsigned int V_174 , enum V_175 V_127 ,
unsigned long V_37 , void * V_126 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_24 , V_62 , V_49 ;
int V_14 = V_10 -> V_14 ;
struct V_172 * V_176 ;
if ( V_10 -> V_44 == V_57 )
return NULL ;
V_10 -> V_44 = V_57 ;
V_10 -> V_37 = 0 ;
V_10 -> V_54 = 0 ;
F_30 ( V_2 -> V_27 , L_8 ,
V_174 , V_14 ) ;
V_10 -> V_127 = V_127 ;
V_24 = F_29 ( V_10 ) ;
if ( V_24 )
goto V_177;
if ( V_174 > V_178 ) {
F_12 ( V_2 -> V_27 , L_9 ,
V_14 , V_174 , V_178 ) ;
V_24 = - V_18 ;
goto V_177;
}
V_10 -> V_179 = 0 ;
F_46 (sgl, sg, sg_len, i) {
struct V_32 * V_34 = & V_10 -> V_34 [ V_62 ] ;
int V_180 ;
V_34 -> V_50 = V_176 -> V_181 ;
V_49 = F_47 ( V_176 ) ;
if ( V_49 > 0xffff ) {
F_12 ( V_2 -> V_27 , L_10 ,
V_14 , V_49 , 0xffff ) ;
V_24 = - V_18 ;
goto V_177;
}
V_34 -> V_41 . V_49 = V_49 ;
V_10 -> V_179 += V_49 ;
if ( V_10 -> V_182 > V_183 ) {
V_24 = - V_18 ;
goto V_177;
}
switch ( V_10 -> V_182 ) {
case V_183 :
V_34 -> V_41 . V_42 = 0 ;
if ( V_49 & 3 || V_176 -> V_181 & 3 )
return NULL ;
break;
case V_184 :
V_34 -> V_41 . V_42 = 2 ;
if ( V_49 & 1 || V_176 -> V_181 & 1 )
return NULL ;
break;
case V_185 :
V_34 -> V_41 . V_42 = 1 ;
break;
default:
return NULL ;
}
V_180 = V_45 | V_48 | V_186 ;
if ( V_62 + 1 == V_174 ) {
V_180 |= V_46 ;
V_180 |= V_187 ;
V_180 &= ~ V_186 ;
}
F_30 ( V_2 -> V_27 , L_11 ,
V_62 , V_49 , V_176 -> V_181 ,
V_180 & V_47 ? L_12 : L_13 ,
V_180 & V_46 ? L_14 : L_13 ) ;
V_34 -> V_41 . V_44 = V_180 ;
}
V_10 -> V_58 = V_174 ;
V_2 -> V_151 [ V_14 ] . V_153 = V_10 -> V_149 ;
return & V_10 -> V_59 ;
V_177:
V_10 -> V_44 = V_56 ;
return NULL ;
}
static struct V_157 * F_48 (
struct V_155 * V_156 , T_2 V_188 , T_5 V_189 ,
T_5 V_190 , enum V_175 V_127 ,
unsigned long V_37 , void * V_126 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_191 = V_189 / V_190 ;
int V_14 = V_10 -> V_14 ;
int V_24 , V_62 = 0 , V_29 = 0 ;
F_30 ( V_2 -> V_27 , L_15 , V_192 , V_14 ) ;
if ( V_10 -> V_44 == V_57 )
return NULL ;
V_10 -> V_44 = V_57 ;
V_10 -> V_54 = 0 ;
V_10 -> V_37 |= V_68 ;
V_10 -> V_127 = V_127 ;
V_24 = F_29 ( V_10 ) ;
if ( V_24 )
goto V_177;
if ( V_191 > V_178 ) {
F_12 ( V_2 -> V_27 , L_9 ,
V_14 , V_191 , V_178 ) ;
goto V_177;
}
if ( V_190 > 0xffff ) {
F_12 ( V_2 -> V_27 , L_16 ,
V_14 , V_190 , 0xffff ) ;
goto V_177;
}
while ( V_29 < V_189 ) {
struct V_32 * V_34 = & V_10 -> V_34 [ V_62 ] ;
int V_180 ;
V_34 -> V_50 = V_188 ;
V_34 -> V_41 . V_49 = V_190 ;
if ( V_10 -> V_182 > V_183 )
goto V_177;
if ( V_10 -> V_182 == V_183 )
V_34 -> V_41 . V_42 = 0 ;
else
V_34 -> V_41 . V_42 = V_10 -> V_182 ;
V_180 = V_45 | V_48 | V_186 | V_46 ;
if ( V_62 + 1 == V_191 )
V_180 |= V_47 ;
F_30 ( V_2 -> V_27 , L_11 ,
V_62 , V_190 , V_188 ,
V_180 & V_47 ? L_12 : L_13 ,
V_180 & V_46 ? L_14 : L_13 ) ;
V_34 -> V_41 . V_44 = V_180 ;
V_188 += V_190 ;
V_29 += V_190 ;
V_62 ++ ;
}
V_10 -> V_58 = V_191 ;
V_2 -> V_151 [ V_14 ] . V_153 = V_10 -> V_149 ;
return & V_10 -> V_59 ;
V_177:
V_10 -> V_44 = V_56 ;
return NULL ;
}
static int F_49 ( struct V_155 * V_156 , enum V_193 V_194 ,
unsigned long V_195 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
struct V_196 * V_197 = ( void * ) V_195 ;
switch ( V_194 ) {
case V_198 :
F_31 ( V_10 ) ;
return 0 ;
case V_199 :
if ( V_197 -> V_127 == V_128 ) {
V_10 -> V_142 = V_197 -> V_200 ;
V_10 -> V_129 = V_197 -> V_201 *
V_197 -> V_202 ;
V_10 -> V_182 = V_197 -> V_202 ;
} else {
V_10 -> V_142 = V_197 -> V_203 ;
V_10 -> V_129 = V_197 -> V_204 *
V_197 -> V_205 ;
V_10 -> V_182 = V_197 -> V_205 ;
}
V_10 -> V_127 = V_197 -> V_127 ;
return F_32 ( V_10 ) ;
default:
return - V_206 ;
}
return - V_18 ;
}
static enum V_207 F_50 ( struct V_155 * V_156 ,
T_4 V_159 ,
struct V_208 * V_209 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
T_4 V_210 ;
V_210 = V_156 -> V_159 ;
F_51 ( V_209 , V_156 -> V_211 , V_210 ,
V_10 -> V_179 - V_10 -> V_63 ) ;
return V_10 -> V_44 ;
}
static void F_52 ( struct V_155 * V_156 )
{
struct V_9 * V_10 = F_36 ( V_156 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_44 == V_57 )
F_7 ( V_2 , V_10 -> V_14 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
const struct V_212 * V_213 )
{
T_6 * V_214 = ( T_1 * ) V_213 ;
T_6 * V_215 = ( T_1 * ) V_2 -> V_83 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_216 ; V_62 ++ )
if ( V_214 [ V_62 ] > 0 )
V_215 [ V_62 ] = V_214 [ V_62 ] ;
}
static void F_54 ( const struct V_217 * V_218 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
const struct V_219 * V_220 ;
const struct V_212 * V_213 ;
unsigned short * V_221 ;
if ( ! V_218 ) {
F_12 ( V_2 -> V_27 , L_17 ) ;
return;
}
if ( V_218 -> V_30 < sizeof( * V_220 ) )
goto V_222;
V_220 = (struct V_219 * ) V_218 -> V_66 ;
if ( V_220 -> V_223 != V_224 )
goto V_222;
if ( V_220 -> V_225 + V_220 -> V_226 > V_218 -> V_30 )
goto V_222;
V_213 = ( void * ) V_220 + V_220 -> V_227 ;
V_221 = ( void * ) V_220 + V_220 -> V_225 ;
F_41 ( V_2 -> V_168 ) ;
F_41 ( V_2 -> V_169 ) ;
F_13 ( V_2 , V_221 ,
V_220 -> V_226 ,
V_213 -> V_228 ) ;
F_44 ( V_2 -> V_168 ) ;
F_44 ( V_2 -> V_169 ) ;
F_53 ( V_2 , V_213 ) ;
F_55 ( V_2 -> V_27 , L_18 ,
V_220 -> V_229 ,
V_220 -> V_230 ) ;
V_222:
F_56 ( V_218 ) ;
}
static int T_7 F_57 ( struct V_1 * V_2 ,
const char * V_231 )
{
int V_24 ;
V_24 = F_58 ( V_232 ,
V_233 , V_231 , V_2 -> V_27 ,
V_38 , V_2 , F_54 ) ;
return V_24 ;
}
static int T_7 F_59 ( struct V_1 * V_2 )
{
int V_62 , V_24 ;
T_2 V_234 ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_140 = 32 ;
break;
case V_235 :
V_2 -> V_140 = 48 ;
break;
default:
F_12 ( V_2 -> V_27 , L_19 ,
V_2 -> V_5 ) ;
return - V_236 ;
}
F_41 ( V_2 -> V_168 ) ;
F_41 ( V_2 -> V_169 ) ;
F_6 ( 0 , V_2 -> V_19 + V_237 ) ;
V_2 -> V_151 = F_14 ( NULL ,
V_238 * sizeof ( struct V_239 ) +
sizeof( struct V_125 ) ,
& V_234 , V_38 ) ;
if ( ! V_2 -> V_151 ) {
V_24 = - V_39 ;
goto V_240;
}
V_2 -> V_126 = ( void * ) V_2 -> V_151 +
V_238 * sizeof ( struct V_239 ) ;
V_2 -> V_137 = V_234 +
V_238 * sizeof ( struct V_239 ) ;
memset ( V_2 -> V_151 , 0 ,
V_238 * sizeof ( struct V_239 ) ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_140 ; V_62 ++ )
F_6 ( 0 , V_2 -> V_19 + F_1 ( V_2 , V_62 ) ) ;
for ( V_62 = 0 ; V_62 < V_238 ; V_62 ++ )
F_6 ( 0 , V_2 -> V_19 + V_146 + V_62 * 4 ) ;
V_24 = F_34 ( & V_2 -> V_14 [ 0 ] ) ;
if ( V_24 )
goto V_240;
F_2 ( & V_2 -> V_14 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_19 + V_241 ) ;
F_6 ( 0 , V_2 -> V_19 + V_242 ) ;
F_6 ( V_234 , V_2 -> V_19 + V_237 ) ;
F_6 ( V_243 , V_2 -> V_19 + V_242 ) ;
F_33 ( & V_2 -> V_14 [ 0 ] , 7 ) ;
F_44 ( V_2 -> V_168 ) ;
F_44 ( V_2 -> V_169 ) ;
return 0 ;
V_240:
F_44 ( V_2 -> V_168 ) ;
F_44 ( V_2 -> V_169 ) ;
F_12 ( V_2 -> V_27 , L_20 , V_24 ) ;
return V_24 ;
}
static int T_7 F_60 ( struct V_244 * V_245 )
{
const struct V_246 * V_247 =
F_61 ( V_248 , & V_245 -> V_27 ) ;
struct V_249 * V_250 = V_245 -> V_27 . V_251 ;
const char * V_231 ;
int V_24 ;
int V_69 ;
struct V_252 * V_253 ;
struct V_254 * V_255 = V_245 -> V_27 . V_256 ;
int V_62 ;
struct V_1 * V_2 ;
T_6 * V_215 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
F_63 ( & V_2 -> V_40 ) ;
V_2 -> V_27 = & V_245 -> V_27 ;
V_253 = F_64 ( V_245 , V_257 , 0 ) ;
V_69 = F_65 ( V_245 , 0 ) ;
if ( ! V_253 || V_69 < 0 ) {
V_24 = - V_18 ;
goto V_258;
}
if ( ! F_66 ( V_253 -> V_259 , F_67 ( V_253 ) , V_245 -> V_260 ) ) {
V_24 = - V_147 ;
goto V_261;
}
V_2 -> V_168 = F_68 ( & V_245 -> V_27 , L_21 ) ;
if ( F_69 ( V_2 -> V_168 ) ) {
V_24 = F_70 ( V_2 -> V_168 ) ;
goto V_262;
}
V_2 -> V_169 = F_68 ( & V_245 -> V_27 , L_22 ) ;
if ( F_69 ( V_2 -> V_169 ) ) {
V_24 = F_70 ( V_2 -> V_169 ) ;
goto V_262;
}
F_71 ( V_2 -> V_168 ) ;
F_71 ( V_2 -> V_169 ) ;
V_2 -> V_19 = F_72 ( V_253 -> V_259 , F_67 ( V_253 ) ) ;
if ( ! V_2 -> V_19 ) {
V_24 = - V_39 ;
goto V_263;
}
V_24 = F_73 ( V_69 , F_25 , 0 , L_23 , V_2 ) ;
if ( V_24 )
goto V_264;
V_2 -> V_83 = F_62 ( sizeof( * V_2 -> V_83 ) , V_38 ) ;
if ( ! V_2 -> V_83 ) {
V_24 = - V_39 ;
goto V_265;
}
V_215 = ( T_6 * ) V_2 -> V_83 ;
for ( V_62 = 0 ; V_62 < V_216 ; V_62 ++ )
V_215 [ V_62 ] = - V_18 ;
if ( V_247 )
V_245 -> V_266 = V_247 -> V_66 ;
V_2 -> V_5 = V_245 -> V_266 -> V_267 ;
F_74 ( V_268 , V_2 -> V_269 . V_270 ) ;
F_74 ( V_271 , V_2 -> V_269 . V_270 ) ;
F_75 ( & V_2 -> V_269 . V_272 ) ;
for ( V_62 = 0 ; V_62 < V_238 ; V_62 ++ ) {
struct V_9 * V_10 = & V_2 -> V_14 [ V_62 ] ;
V_10 -> V_2 = V_2 ;
F_63 ( & V_10 -> V_160 ) ;
V_10 -> V_156 . V_273 = & V_2 -> V_269 ;
F_76 ( & V_10 -> V_156 ) ;
V_10 -> V_14 = V_62 ;
F_77 ( & V_10 -> V_72 , F_23 ,
( unsigned long ) V_10 ) ;
if ( V_62 )
F_78 ( & V_10 -> V_156 . V_249 ,
& V_2 -> V_269 . V_272 ) ;
}
V_24 = F_59 ( V_2 ) ;
if ( V_24 )
goto V_274;
if ( V_255 && V_255 -> V_83 )
F_53 ( V_2 , V_255 -> V_83 ) ;
if ( V_255 ) {
V_24 = F_57 ( V_2 , V_255 -> V_231 ) ;
if ( V_24 )
F_79 ( & V_245 -> V_27 , L_24 ) ;
} else {
V_24 = F_80 ( V_250 , L_25 ,
& V_231 ) ;
if ( V_24 )
F_79 ( & V_245 -> V_27 , L_26 ) ;
else {
V_24 = F_57 ( V_2 , V_231 ) ;
if ( V_24 )
F_79 ( & V_245 -> V_27 , L_27 ) ;
}
}
V_2 -> V_269 . V_27 = & V_245 -> V_27 ;
V_2 -> V_269 . V_275 = F_40 ;
V_2 -> V_269 . V_276 = F_43 ;
V_2 -> V_269 . V_277 = F_50 ;
V_2 -> V_269 . V_278 = F_45 ;
V_2 -> V_269 . V_279 = F_48 ;
V_2 -> V_269 . V_280 = F_49 ;
V_2 -> V_269 . V_281 = F_52 ;
V_2 -> V_269 . V_27 -> V_282 = & V_2 -> V_282 ;
F_81 ( V_2 -> V_269 . V_27 , 65535 ) ;
V_24 = F_82 ( & V_2 -> V_269 ) ;
if ( V_24 ) {
F_12 ( & V_245 -> V_27 , L_28 ) ;
goto V_274;
}
F_55 ( V_2 -> V_27 , L_29 ) ;
return 0 ;
V_274:
F_83 ( V_2 -> V_83 ) ;
V_265:
F_84 ( V_69 , V_2 ) ;
V_264:
F_85 ( V_2 -> V_19 ) ;
V_263:
V_262:
F_86 ( V_253 -> V_259 , F_67 ( V_253 ) ) ;
V_261:
V_258:
F_83 ( V_2 ) ;
return V_24 ;
}
static int T_8 F_87 ( struct V_244 * V_245 )
{
return - V_147 ;
}
static int T_7 F_88 ( void )
{
return F_89 ( & V_283 , F_60 ) ;
}
