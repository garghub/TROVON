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
if ( F_13 ( V_2 -> V_16 + V_25 ) == 0 )
F_6 ( V_26 , V_2 -> V_16 + V_25 ) ;
return V_21 ? 0 : - V_27 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_28 , int V_29 ,
T_1 V_30 )
{
struct V_31 * V_32 = V_2 -> V_11 [ 0 ] . V_33 ;
void * V_34 ;
T_2 V_35 ;
int V_21 ;
unsigned long V_36 ;
V_34 = F_15 ( NULL ,
V_29 ,
& V_35 , V_37 ) ;
if ( ! V_34 ) {
return - V_38 ;
}
F_16 ( & V_2 -> V_39 , V_36 ) ;
V_32 -> V_40 . V_41 = V_42 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = V_29 / 2 ;
V_32 -> V_49 = V_35 ;
V_32 -> V_50 = V_30 ;
memcpy ( V_34 , V_28 , V_29 ) ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_39 , V_36 ) ;
F_18 ( NULL , V_29 , V_34 , V_35 ) ;
return V_21 ;
}
static void F_19 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
unsigned long V_51 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
V_51 = F_3 ( V_2 -> V_16 + V_52 ) ;
F_5 ( V_11 , & V_51 ) ;
F_6 ( V_51 , V_2 -> V_16 + V_52 ) ;
}
static void F_20 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
T_1 V_52 = F_1 ( V_2 , V_3 ) ;
unsigned long V_51 ;
V_51 = F_3 ( V_2 -> V_16 + V_52 ) ;
F_4 ( V_11 , & V_51 ) ;
F_6 ( V_51 , V_2 -> V_16 + V_52 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
if ( V_7 -> V_53 . V_54 )
V_7 -> V_53 . V_54 ( V_7 -> V_53 . V_55 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_31 * V_33 ;
while ( 1 ) {
V_33 = & V_7 -> V_33 [ V_7 -> V_56 ] ;
if ( V_33 -> V_40 . V_43 & V_44 )
break;
if ( V_33 -> V_40 . V_43 & V_57 )
V_7 -> V_43 = V_58 ;
V_33 -> V_40 . V_43 |= V_44 ;
V_7 -> V_56 ++ ;
V_7 -> V_56 %= V_7 -> V_59 ;
}
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_31 * V_33 ;
int V_60 , error = 0 ;
V_7 -> V_61 = 0 ;
for ( V_60 = 0 ; V_60 < V_7 -> V_59 ; V_60 ++ ) {
V_33 = & V_7 -> V_33 [ V_60 ] ;
if ( V_33 -> V_40 . V_43 & ( V_44 | V_57 ) )
error = - V_62 ;
V_7 -> V_61 += V_33 -> V_40 . V_48 ;
}
if ( error )
V_7 -> V_43 = V_58 ;
else
V_7 -> V_43 = V_63 ;
F_24 ( & V_7 -> V_53 ) ;
if ( V_7 -> V_53 . V_54 )
V_7 -> V_53 . V_54 ( V_7 -> V_53 . V_55 ) ;
}
static void F_25 ( unsigned long V_64 )
{
struct V_6 * V_7 = (struct V_6 * ) V_64 ;
if ( V_7 -> V_36 & V_65 )
F_21 ( V_7 ) ;
else
F_23 ( V_7 ) ;
}
static T_3 F_26 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned long V_68 ;
V_68 = F_3 ( V_2 -> V_16 + V_23 ) ;
V_68 &= ~ 1 ;
F_6 ( V_68 , V_2 -> V_16 + V_23 ) ;
while ( V_68 ) {
int V_11 = F_27 ( V_68 ) - 1 ;
struct V_6 * V_7 = & V_2 -> V_11 [ V_11 ] ;
if ( V_7 -> V_36 & V_65 )
F_22 ( V_7 ) ;
F_28 ( & V_7 -> V_69 ) ;
F_4 ( V_11 , & V_68 ) ;
}
return V_70 ;
}
static void F_29 ( struct V_6 * V_7 ,
enum V_71 V_72 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_73 = 0 , V_74 = 0 ;
int V_75 = 0 , V_76 = 0 ;
V_7 -> V_77 = 0 ;
V_7 -> V_78 = 0 ;
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
case V_100 :
V_73 = V_2 -> V_80 -> V_101 ;
V_74 = V_2 -> V_80 -> V_90 ;
break;
case V_102 :
V_73 = V_2 -> V_80 -> V_103 ;
V_74 = V_2 -> V_80 -> V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_73 = V_2 -> V_80 -> V_111 ;
V_74 = V_2 -> V_80 -> V_93 ;
break;
case V_112 :
V_73 = V_2 -> V_80 -> V_113 ;
V_74 = V_2 -> V_80 -> V_113 ;
V_75 = V_2 -> V_80 -> V_114 ;
break;
case V_115 :
V_73 = V_2 -> V_80 -> V_111 ;
V_74 = V_2 -> V_80 -> V_93 ;
V_75 = V_2 -> V_80 -> V_114 ;
break;
case V_116 :
V_73 = V_2 -> V_80 -> V_117 ;
V_74 = V_2 -> V_80 -> V_118 ;
break;
case V_119 :
V_73 = V_2 -> V_80 -> V_120 ;
break;
case V_121 :
V_73 = V_2 -> V_80 -> V_122 ;
V_74 = V_2 -> V_80 -> V_123 ;
break;
case V_124 :
V_74 = V_2 -> V_80 -> V_125 ;
break;
default:
break;
}
V_7 -> V_77 = V_73 ;
V_7 -> V_78 = V_74 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_126 ;
struct V_127 * V_128 = V_2 -> V_128 ;
struct V_31 * V_32 = V_2 -> V_11 [ 0 ] . V_33 ;
int V_21 ;
unsigned long V_36 ;
if ( V_7 -> V_129 == V_130 ) {
V_126 = V_7 -> V_77 ;
} else {
V_126 = V_7 -> V_78 ;
}
if ( V_126 < 0 )
return V_126 ;
F_31 ( V_2 -> V_24 , L_2 , V_126 ) ;
F_31 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_131 ) ;
F_31 ( V_2 -> V_24 , L_4 , V_7 -> V_132 ) ;
F_31 ( V_2 -> V_24 , L_5 , V_7 -> V_133 ) ;
F_31 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_134 [ 0 ] ) ;
F_31 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_134 [ 1 ] ) ;
F_16 ( & V_2 -> V_39 , V_36 ) ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> V_135 . V_136 = V_126 ;
V_128 -> V_137 [ 0 ] = V_7 -> V_134 [ 1 ] ;
V_128 -> V_137 [ 1 ] = V_7 -> V_134 [ 0 ] ;
V_128 -> V_137 [ 2 ] = V_7 -> V_133 ;
V_128 -> V_137 [ 6 ] = V_7 -> V_132 ;
V_128 -> V_137 [ 7 ] = V_7 -> V_131 ;
V_32 -> V_40 . V_41 = V_138 ;
V_32 -> V_40 . V_43 = V_44 | V_45 | V_46 | V_47 ;
V_32 -> V_40 . V_48 = sizeof( * V_128 ) / 4 ;
V_32 -> V_49 = V_2 -> V_139 ;
V_32 -> V_50 = 2048 + ( sizeof( * V_128 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_39 , V_36 ) ;
return V_21 ;
}
static struct V_6 * F_32 ( struct V_140 * V_141 )
{
return F_33 ( V_141 , struct V_6 , V_141 ) ;
}
static int F_34 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_142 ) ;
V_7 -> V_43 = V_58 ;
return 0 ;
}
static int F_35 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
int V_21 ;
F_34 ( V_141 ) ;
V_7 -> V_134 [ 0 ] = 0 ;
V_7 -> V_134 [ 1 ] = 0 ;
V_7 -> V_132 = 0 ;
V_7 -> V_133 = 0 ;
if ( V_7 -> V_143 ) {
if ( V_7 -> V_143 >= V_7 -> V_2 -> V_5 -> V_144 )
return - V_15 ;
F_19 ( V_7 , V_7 -> V_143 ) ;
}
switch ( V_7 -> V_72 ) {
case V_82 :
F_2 ( V_7 , false , true , true ) ;
break;
case V_79 :
F_2 ( V_7 , false , true , false ) ;
break;
default:
F_2 ( V_7 , true , true , false ) ;
break;
}
F_29 ( V_7 , V_7 -> V_72 ) ;
if ( ( V_7 -> V_72 != V_79 ) &&
( V_7 -> V_72 != V_82 ) ) {
if ( V_7 -> V_145 ) {
V_7 -> V_134 [ 1 ] = F_9 ( V_7 -> V_145 % 32 ) ;
if ( V_7 -> V_145 > 31 )
F_5 ( 31 , & V_7 -> V_131 ) ;
V_7 -> V_134 [ 0 ] = F_9 ( V_7 -> V_143 % 32 ) ;
if ( V_7 -> V_143 > 31 )
F_5 ( 30 , & V_7 -> V_131 ) ;
} else {
F_5 ( V_7 -> V_143 , V_7 -> V_134 ) ;
}
V_7 -> V_131 |= V_7 -> V_131 ;
V_7 -> V_132 = V_7 -> V_146 ;
} else {
V_7 -> V_131 = 0 ;
}
V_21 = F_30 ( V_7 ) ;
return V_21 ;
}
static int F_36 ( struct V_6 * V_7 ,
unsigned int V_147 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_147 < V_148
|| V_147 > V_149 ) {
return - V_15 ;
}
F_6 ( V_147 , V_2 -> V_16 + V_150 + 4 * V_11 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_151 ;
V_7 -> V_33 = F_38 ( NULL , V_152 , & V_7 -> V_153 ,
V_37 ) ;
if ( ! V_7 -> V_33 ) {
V_21 = - V_38 ;
goto V_154;
}
V_2 -> V_155 [ V_11 ] . V_156 = V_7 -> V_153 ;
V_2 -> V_155 [ V_11 ] . V_157 = V_7 -> V_153 ;
F_36 ( V_7 , V_158 ) ;
return 0 ;
V_154:
return V_21 ;
}
static T_4 F_39 ( struct V_159 * V_160 )
{
unsigned long V_36 ;
struct V_6 * V_7 = F_32 ( V_160 -> V_141 ) ;
T_4 V_161 ;
F_16 ( & V_7 -> V_162 , V_36 ) ;
V_161 = F_40 ( V_160 ) ;
F_17 ( & V_7 -> V_162 , V_36 ) ;
return V_161 ;
}
static int F_41 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_163 * V_64 = V_141 -> V_164 ;
int V_165 , V_21 ;
if ( ! V_64 )
return - V_15 ;
switch ( V_64 -> V_147 ) {
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
V_7 -> V_72 = V_64 -> V_72 ;
V_7 -> V_143 = V_64 -> V_169 ;
F_42 ( V_7 -> V_2 -> V_170 ) ;
F_42 ( V_7 -> V_2 -> V_171 ) ;
V_21 = F_37 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( V_7 , V_165 ) ;
if ( V_21 )
return V_21 ;
F_43 ( & V_7 -> V_53 , V_141 ) ;
V_7 -> V_53 . V_172 = F_39 ;
V_7 -> V_53 . V_36 = V_173 ;
return 0 ;
}
static void F_44 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_34 ( V_141 ) ;
if ( V_7 -> V_143 )
F_20 ( V_7 , V_7 -> V_143 ) ;
if ( V_7 -> V_145 )
F_20 ( V_7 , V_7 -> V_145 ) ;
V_7 -> V_143 = 0 ;
V_7 -> V_145 = 0 ;
F_36 ( V_7 , 0 ) ;
F_18 ( NULL , V_152 , V_7 -> V_33 , V_7 -> V_153 ) ;
F_45 ( V_2 -> V_170 ) ;
F_45 ( V_2 -> V_171 ) ;
}
static struct V_159 * F_46 (
struct V_140 * V_141 , struct V_174 * V_175 ,
unsigned int V_176 , enum V_177 V_129 ,
unsigned long V_36 , void * V_128 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_60 , V_48 ;
int V_11 = V_7 -> V_11 ;
struct V_174 * V_178 ;
if ( V_7 -> V_43 == V_179 )
return NULL ;
V_7 -> V_43 = V_179 ;
V_7 -> V_36 = 0 ;
V_7 -> V_56 = 0 ;
F_31 ( V_2 -> V_24 , L_8 ,
V_176 , V_11 ) ;
V_7 -> V_129 = V_129 ;
V_21 = F_30 ( V_7 ) ;
if ( V_21 )
goto V_180;
if ( V_176 > V_181 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_176 , V_181 ) ;
V_21 = - V_15 ;
goto V_180;
}
V_7 -> V_182 = 0 ;
F_47 (sgl, sg, sg_len, i) {
struct V_31 * V_33 = & V_7 -> V_33 [ V_60 ] ;
int V_183 ;
V_33 -> V_49 = V_178 -> V_184 ;
V_48 = F_48 ( V_178 ) ;
if ( V_48 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_48 , 0xffff ) ;
V_21 = - V_15 ;
goto V_180;
}
V_33 -> V_40 . V_48 = V_48 ;
V_7 -> V_182 += V_48 ;
if ( V_7 -> V_185 > V_186 ) {
V_21 = - V_15 ;
goto V_180;
}
switch ( V_7 -> V_185 ) {
case V_186 :
V_33 -> V_40 . V_41 = 0 ;
if ( V_48 & 3 || V_178 -> V_184 & 3 )
return NULL ;
break;
case V_187 :
V_33 -> V_40 . V_41 = 2 ;
if ( V_48 & 1 || V_178 -> V_184 & 1 )
return NULL ;
break;
case V_188 :
V_33 -> V_40 . V_41 = 1 ;
break;
default:
return NULL ;
}
V_183 = V_44 | V_47 | V_189 ;
if ( V_60 + 1 == V_176 ) {
V_183 |= V_45 ;
V_183 |= V_190 ;
V_183 &= ~ V_189 ;
}
F_31 ( V_2 -> V_24 , L_11 ,
V_60 , V_48 , ( V_191 ) V_178 -> V_184 ,
V_183 & V_46 ? L_12 : L_13 ,
V_183 & V_45 ? L_14 : L_13 ) ;
V_33 -> V_40 . V_43 = V_183 ;
}
V_7 -> V_59 = V_176 ;
V_2 -> V_155 [ V_11 ] . V_157 = V_7 -> V_153 ;
return & V_7 -> V_53 ;
V_180:
V_7 -> V_43 = V_58 ;
return NULL ;
}
static struct V_159 * F_49 (
struct V_140 * V_141 , T_2 V_192 , T_5 V_193 ,
T_5 V_194 , enum V_177 V_129 ,
unsigned long V_36 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_195 = V_193 / V_194 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_60 = 0 , V_28 = 0 ;
F_31 ( V_2 -> V_24 , L_15 , V_196 , V_11 ) ;
if ( V_7 -> V_43 == V_179 )
return NULL ;
V_7 -> V_43 = V_179 ;
V_7 -> V_56 = 0 ;
V_7 -> V_194 = V_194 ;
V_7 -> V_36 |= V_65 ;
V_7 -> V_129 = V_129 ;
V_21 = F_30 ( V_7 ) ;
if ( V_21 )
goto V_180;
if ( V_195 > V_181 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_195 , V_181 ) ;
goto V_180;
}
if ( V_194 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_194 , 0xffff ) ;
goto V_180;
}
while ( V_28 < V_193 ) {
struct V_31 * V_33 = & V_7 -> V_33 [ V_60 ] ;
int V_183 ;
V_33 -> V_49 = V_192 ;
V_33 -> V_40 . V_48 = V_194 ;
if ( V_7 -> V_185 > V_186 )
goto V_180;
if ( V_7 -> V_185 == V_186 )
V_33 -> V_40 . V_41 = 0 ;
else
V_33 -> V_40 . V_41 = V_7 -> V_185 ;
V_183 = V_44 | V_47 | V_189 | V_45 ;
if ( V_60 + 1 == V_195 )
V_183 |= V_46 ;
F_31 ( V_2 -> V_24 , L_11 ,
V_60 , V_194 , ( V_191 ) V_192 ,
V_183 & V_46 ? L_12 : L_13 ,
V_183 & V_45 ? L_14 : L_13 ) ;
V_33 -> V_40 . V_43 = V_183 ;
V_192 += V_194 ;
V_28 += V_194 ;
V_60 ++ ;
}
V_7 -> V_59 = V_195 ;
V_2 -> V_155 [ V_11 ] . V_157 = V_7 -> V_153 ;
return & V_7 -> V_53 ;
V_180:
V_7 -> V_43 = V_58 ;
return NULL ;
}
static int F_50 ( struct V_140 * V_141 ,
struct V_197 * V_198 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
if ( V_198 -> V_129 == V_130 ) {
V_7 -> V_146 = V_198 -> V_199 ;
V_7 -> V_131 = V_198 -> V_200 *
V_198 -> V_201 ;
V_7 -> V_185 = V_198 -> V_201 ;
} else {
V_7 -> V_146 = V_198 -> V_202 ;
V_7 -> V_131 = V_198 -> V_203 *
V_198 -> V_204 ;
V_7 -> V_185 = V_198 -> V_204 ;
}
V_7 -> V_129 = V_198 -> V_129 ;
return F_35 ( V_141 ) ;
}
static enum V_205 F_51 ( struct V_140 * V_141 ,
T_4 V_161 ,
struct V_206 * V_207 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
T_1 V_208 ;
if ( V_7 -> V_36 & V_65 )
V_208 = ( V_7 -> V_59 - V_7 -> V_56 ) * V_7 -> V_194 ;
else
V_208 = V_7 -> V_182 - V_7 -> V_61 ;
F_52 ( V_207 , V_141 -> V_209 , V_141 -> V_161 ,
V_208 ) ;
return V_7 -> V_43 ;
}
static void F_53 ( struct V_140 * V_141 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_43 == V_179 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
const struct V_210 * V_211 )
{
T_6 * V_212 = ( T_1 * ) V_211 ;
T_6 * V_213 = ( T_1 * ) V_2 -> V_80 ;
int V_60 ;
if ( ! V_2 -> V_214 )
V_2 -> V_214 = V_215 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_214 ; V_60 ++ )
if ( V_212 [ V_60 ] > 0 )
V_213 [ V_60 ] = V_212 [ V_60 ] ;
}
static void F_55 ( const struct V_216 * V_217 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
const struct V_218 * V_219 ;
const struct V_210 * V_211 ;
unsigned short * V_220 ;
if ( ! V_217 ) {
F_56 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_217 -> V_29 < sizeof( * V_219 ) )
goto V_221;
V_219 = (struct V_218 * ) V_217 -> V_64 ;
if ( V_219 -> V_222 != V_223 )
goto V_221;
if ( V_219 -> V_224 + V_219 -> V_225 > V_217 -> V_29 )
goto V_221;
switch ( V_219 -> V_226 ) {
case 1 :
V_2 -> V_214 = V_215 ;
break;
case 2 :
V_2 -> V_214 = V_227 ;
break;
case 3 :
V_2 -> V_214 = V_228 ;
break;
default:
F_12 ( V_2 -> V_24 , L_18 ) ;
goto V_221;
}
V_211 = ( void * ) V_219 + V_219 -> V_229 ;
V_220 = ( void * ) V_219 + V_219 -> V_224 ;
F_42 ( V_2 -> V_170 ) ;
F_42 ( V_2 -> V_171 ) ;
F_14 ( V_2 , V_220 ,
V_219 -> V_225 ,
V_211 -> V_230 ) ;
F_45 ( V_2 -> V_170 ) ;
F_45 ( V_2 -> V_171 ) ;
F_54 ( V_2 , V_211 ) ;
F_56 ( V_2 -> V_24 , L_19 ,
V_219 -> V_226 ,
V_219 -> V_231 ) ;
V_221:
F_57 ( V_217 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
const char * V_232 )
{
int V_21 ;
V_21 = F_59 ( V_233 ,
V_234 , V_232 , V_2 -> V_24 ,
V_37 , V_2 , F_55 ) ;
return V_21 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_60 , V_21 ;
T_2 V_235 ;
F_42 ( V_2 -> V_170 ) ;
F_42 ( V_2 -> V_171 ) ;
F_6 ( 0 , V_2 -> V_16 + V_236 ) ;
V_2 -> V_155 = F_15 ( NULL ,
V_237 * sizeof ( struct V_238 ) +
sizeof( struct V_127 ) ,
& V_235 , V_37 ) ;
if ( ! V_2 -> V_155 ) {
V_21 = - V_38 ;
goto V_239;
}
V_2 -> V_128 = ( void * ) V_2 -> V_155 +
V_237 * sizeof ( struct V_238 ) ;
V_2 -> V_139 = V_235 +
V_237 * sizeof ( struct V_238 ) ;
memset ( V_2 -> V_155 , 0 ,
V_237 * sizeof ( struct V_238 ) ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_5 -> V_144 ; V_60 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_60 ) ) ;
for ( V_60 = 0 ; V_60 < V_237 ; V_60 ++ )
F_6 ( 0 , V_2 -> V_16 + V_150 + V_60 * 4 ) ;
V_21 = F_37 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_239;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_240 ) ;
F_6 ( 0 , V_2 -> V_16 + V_25 ) ;
F_6 ( V_235 , V_2 -> V_16 + V_236 ) ;
F_36 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_45 ( V_2 -> V_170 ) ;
F_45 ( V_2 -> V_171 ) ;
return 0 ;
V_239:
F_45 ( V_2 -> V_170 ) ;
F_45 ( V_2 -> V_171 ) ;
F_12 ( V_2 -> V_24 , L_20 , V_21 ) ;
return V_21 ;
}
static bool F_61 ( struct V_140 * V_141 , void * V_241 )
{
struct V_6 * V_7 = F_32 ( V_141 ) ;
struct V_163 * V_64 = V_241 ;
if ( ! F_62 ( V_141 ) )
return false ;
V_7 -> V_64 = * V_64 ;
V_141 -> V_164 = & V_7 -> V_64 ;
return true ;
}
static struct V_140 * F_63 ( struct V_242 * V_243 ,
struct V_244 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_246 ;
T_7 V_247 = V_2 -> V_248 . V_249 ;
struct V_163 V_64 ;
if ( V_243 -> V_250 != 3 )
return NULL ;
V_64 . V_169 = V_243 -> args [ 0 ] ;
V_64 . V_72 = V_243 -> args [ 1 ] ;
V_64 . V_147 = V_243 -> args [ 2 ] ;
return F_64 ( V_247 , F_61 , & V_64 ) ;
}
static int F_65 ( struct V_251 * V_252 )
{
const struct V_253 * V_254 =
F_66 ( V_255 , & V_252 -> V_24 ) ;
struct V_256 * V_257 = V_252 -> V_24 . V_258 ;
const char * V_232 ;
int V_21 ;
int V_66 ;
struct V_259 * V_260 ;
struct V_261 * V_262 = F_67 ( & V_252 -> V_24 ) ;
int V_60 ;
struct V_1 * V_2 ;
T_6 * V_213 ;
const struct V_263 * V_5 = NULL ;
if ( V_254 )
V_5 = V_254 -> V_64 ;
else if ( V_252 -> V_264 )
V_5 = ( void * ) V_252 -> V_264 -> V_265 ;
if ( ! V_5 ) {
F_12 ( & V_252 -> V_24 , L_21 ) ;
return - V_15 ;
}
V_21 = F_68 ( & V_252 -> V_24 , F_69 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
V_2 = F_70 ( & V_252 -> V_24 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
F_71 ( & V_2 -> V_39 ) ;
V_2 -> V_24 = & V_252 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_66 = F_72 ( V_252 , 0 ) ;
if ( V_66 < 0 )
return V_66 ;
V_260 = F_73 ( V_252 , V_266 , 0 ) ;
V_2 -> V_16 = F_74 ( & V_252 -> V_24 , V_260 ) ;
if ( F_75 ( V_2 -> V_16 ) )
return F_76 ( V_2 -> V_16 ) ;
V_2 -> V_170 = F_77 ( & V_252 -> V_24 , L_22 ) ;
if ( F_75 ( V_2 -> V_170 ) )
return F_76 ( V_2 -> V_170 ) ;
V_2 -> V_171 = F_77 ( & V_252 -> V_24 , L_23 ) ;
if ( F_75 ( V_2 -> V_171 ) )
return F_76 ( V_2 -> V_171 ) ;
F_78 ( V_2 -> V_170 ) ;
F_78 ( V_2 -> V_171 ) ;
V_21 = F_79 ( & V_252 -> V_24 , V_66 , F_26 , 0 , L_24 ,
V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_80 = F_80 ( sizeof( * V_2 -> V_80 ) , V_37 ) ;
if ( ! V_2 -> V_80 )
return - V_38 ;
V_213 = ( T_6 * ) V_2 -> V_80 ;
for ( V_60 = 0 ; V_60 < V_215 ; V_60 ++ )
V_213 [ V_60 ] = - V_15 ;
F_81 ( V_267 , V_2 -> V_248 . V_249 ) ;
F_81 ( V_268 , V_2 -> V_248 . V_249 ) ;
F_82 ( & V_2 -> V_248 . V_269 ) ;
for ( V_60 = 0 ; V_60 < V_237 ; V_60 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_60 ] ;
V_7 -> V_2 = V_2 ;
F_71 ( & V_7 -> V_162 ) ;
V_7 -> V_141 . V_270 = & V_2 -> V_248 ;
F_83 ( & V_7 -> V_141 ) ;
V_7 -> V_11 = V_60 ;
F_84 ( & V_7 -> V_69 , F_25 ,
( unsigned long ) V_7 ) ;
if ( V_60 )
F_85 ( & V_7 -> V_141 . V_256 ,
& V_2 -> V_248 . V_269 ) ;
}
V_21 = F_60 ( V_2 ) ;
if ( V_21 )
goto V_271;
if ( V_2 -> V_5 -> V_80 )
F_54 ( V_2 , V_2 -> V_5 -> V_80 ) ;
if ( V_262 && V_262 -> V_80 )
F_54 ( V_2 , V_262 -> V_80 ) ;
if ( V_262 ) {
V_21 = F_58 ( V_2 , V_262 -> V_232 ) ;
if ( V_21 )
F_86 ( & V_252 -> V_24 , L_25 ) ;
} else {
V_21 = F_87 ( V_257 , L_26 ,
& V_232 ) ;
if ( V_21 )
F_86 ( & V_252 -> V_24 , L_27 ) ;
else {
V_21 = F_58 ( V_2 , V_232 ) ;
if ( V_21 )
F_86 ( & V_252 -> V_24 , L_28 ) ;
}
}
V_2 -> V_248 . V_24 = & V_252 -> V_24 ;
V_2 -> V_248 . V_272 = F_41 ;
V_2 -> V_248 . V_273 = F_44 ;
V_2 -> V_248 . V_274 = F_51 ;
V_2 -> V_248 . V_275 = F_46 ;
V_2 -> V_248 . V_276 = F_49 ;
V_2 -> V_248 . V_277 = F_50 ;
V_2 -> V_248 . V_278 = F_34 ;
V_2 -> V_248 . V_279 = F_9 ( V_186 ) ;
V_2 -> V_248 . V_280 = F_9 ( V_186 ) ;
V_2 -> V_248 . V_281 = F_9 ( V_130 ) | F_9 ( V_282 ) ;
V_2 -> V_248 . V_283 = V_284 ;
V_2 -> V_248 . V_285 = F_53 ;
V_2 -> V_248 . V_24 -> V_286 = & V_2 -> V_286 ;
F_88 ( V_2 -> V_248 . V_24 , 65535 ) ;
F_89 ( V_252 , V_2 ) ;
V_21 = F_90 ( & V_2 -> V_248 ) ;
if ( V_21 ) {
F_12 ( & V_252 -> V_24 , L_29 ) ;
goto V_271;
}
if ( V_257 ) {
V_21 = F_91 ( V_257 , F_63 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_252 -> V_24 , L_30 ) ;
goto V_287;
}
}
F_56 ( V_2 -> V_24 , L_31 ) ;
return 0 ;
V_287:
F_92 ( & V_2 -> V_248 ) ;
V_271:
F_93 ( V_2 -> V_80 ) ;
return V_21 ;
}
static int F_94 ( struct V_251 * V_252 )
{
struct V_1 * V_2 = F_95 ( V_252 ) ;
int V_60 ;
F_92 ( & V_2 -> V_248 ) ;
F_93 ( V_2 -> V_80 ) ;
for ( V_60 = 0 ; V_60 < V_237 ; V_60 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_60 ] ;
F_96 ( & V_7 -> V_69 ) ;
}
F_89 ( V_252 , NULL ) ;
F_56 ( & V_252 -> V_24 , L_32 ) ;
return 0 ;
}
