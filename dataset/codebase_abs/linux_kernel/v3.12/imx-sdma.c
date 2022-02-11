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
V_7 -> V_76 = V_72 ;
V_7 -> V_77 = V_73 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_120 ;
struct V_121 * V_122 = V_2 -> V_122 ;
struct V_29 * V_30 = V_2 -> V_11 [ 0 ] . V_31 ;
int V_21 ;
unsigned long V_34 ;
if ( V_7 -> V_123 == V_124 ) {
V_120 = V_7 -> V_76 ;
} else {
V_120 = V_7 -> V_77 ;
}
if ( V_120 < 0 )
return V_120 ;
F_29 ( V_2 -> V_24 , L_2 , V_120 ) ;
F_29 ( V_2 -> V_24 , L_3 , ( T_1 ) V_7 -> V_125 ) ;
F_29 ( V_2 -> V_24 , L_4 , V_7 -> V_126 ) ;
F_29 ( V_2 -> V_24 , L_5 , V_7 -> V_127 ) ;
F_29 ( V_2 -> V_24 , L_6 , ( T_1 ) V_7 -> V_128 [ 0 ] ) ;
F_29 ( V_2 -> V_24 , L_7 , ( T_1 ) V_7 -> V_128 [ 1 ] ) ;
F_15 ( & V_2 -> V_37 , V_34 ) ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_129 . V_130 = V_120 ;
V_122 -> V_131 [ 0 ] = V_7 -> V_128 [ 1 ] ;
V_122 -> V_131 [ 1 ] = V_7 -> V_128 [ 0 ] ;
V_122 -> V_131 [ 2 ] = V_7 -> V_127 ;
V_122 -> V_131 [ 6 ] = V_7 -> V_126 ;
V_122 -> V_131 [ 7 ] = V_7 -> V_125 ;
V_30 -> V_38 . V_39 = V_132 ;
V_30 -> V_38 . V_41 = V_42 | V_43 | V_44 | V_45 ;
V_30 -> V_38 . V_46 = sizeof( * V_122 ) / 4 ;
V_30 -> V_47 = V_2 -> V_133 ;
V_30 -> V_48 = 2048 + ( sizeof( * V_122 ) / 4 ) * V_11 ;
V_21 = F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_37 , V_34 ) ;
return V_21 ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
F_6 ( F_9 ( V_11 ) , V_2 -> V_16 + V_134 ) ;
V_7 -> V_41 = V_53 ;
}
static int F_31 ( struct V_6 * V_7 )
{
int V_21 ;
F_30 ( V_7 ) ;
V_7 -> V_128 [ 0 ] = 0 ;
V_7 -> V_128 [ 1 ] = 0 ;
V_7 -> V_126 = 0 ;
V_7 -> V_127 = 0 ;
if ( V_7 -> V_135 ) {
if ( V_7 -> V_135 >= V_7 -> V_2 -> V_5 -> V_136 )
return - V_15 ;
F_18 ( V_7 , V_7 -> V_135 ) ;
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
if ( V_7 -> V_137 ) {
V_7 -> V_128 [ 1 ] = F_9 ( V_7 -> V_137 % 32 ) ;
if ( V_7 -> V_137 > 31 )
F_5 ( 31 , & V_7 -> V_125 ) ;
V_7 -> V_128 [ 0 ] = F_9 ( V_7 -> V_135 % 32 ) ;
if ( V_7 -> V_135 > 31 )
F_5 ( 30 , & V_7 -> V_125 ) ;
} else {
F_5 ( V_7 -> V_135 , V_7 -> V_128 ) ;
}
V_7 -> V_125 |= V_7 -> V_125 ;
V_7 -> V_126 = V_7 -> V_138 ;
} else {
V_7 -> V_125 = 0 ;
}
V_21 = F_28 ( V_7 ) ;
return V_21 ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned int V_139 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
if ( V_139 < V_140
|| V_139 > V_141 ) {
return - V_15 ;
}
F_6 ( V_139 , V_2 -> V_16 + V_142 + 4 * V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 = V_7 -> V_11 ;
int V_21 = - V_143 ;
V_7 -> V_31 = F_14 ( NULL , V_144 , & V_7 -> V_145 , V_35 ) ;
if ( ! V_7 -> V_31 ) {
V_21 = - V_36 ;
goto V_146;
}
memset ( V_7 -> V_31 , 0 , V_144 ) ;
V_2 -> V_147 [ V_11 ] . V_148 = V_7 -> V_145 ;
V_2 -> V_147 [ V_11 ] . V_149 = V_7 -> V_145 ;
F_32 ( V_7 , V_150 ) ;
return 0 ;
V_146:
return V_21 ;
}
static struct V_6 * F_34 ( struct V_151 * V_152 )
{
return F_35 ( V_152 , struct V_6 , V_152 ) ;
}
static T_4 F_36 ( struct V_153 * V_154 )
{
unsigned long V_34 ;
struct V_6 * V_7 = F_34 ( V_154 -> V_152 ) ;
T_4 V_155 ;
F_15 ( & V_7 -> V_156 , V_34 ) ;
V_155 = F_37 ( V_154 ) ;
F_16 ( & V_7 -> V_156 , V_34 ) ;
return V_155 ;
}
static int F_38 ( struct V_151 * V_152 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
struct V_157 * V_63 = V_152 -> V_158 ;
int V_159 , V_21 ;
if ( ! V_63 )
return - V_15 ;
switch ( V_63 -> V_139 ) {
case V_160 :
V_159 = 3 ;
break;
case V_161 :
V_159 = 2 ;
break;
case V_162 :
default:
V_159 = 1 ;
break;
}
V_7 -> V_71 = V_63 -> V_71 ;
V_7 -> V_135 = V_63 -> V_163 ;
F_39 ( V_7 -> V_2 -> V_164 ) ;
F_39 ( V_7 -> V_2 -> V_165 ) ;
V_21 = F_33 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( V_7 , V_159 ) ;
if ( V_21 )
return V_21 ;
F_40 ( & V_7 -> V_56 , V_152 ) ;
V_7 -> V_56 . V_166 = F_36 ;
V_7 -> V_56 . V_34 = V_167 ;
return 0 ;
}
static void F_41 ( struct V_151 * V_152 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_30 ( V_7 ) ;
if ( V_7 -> V_135 )
F_19 ( V_7 , V_7 -> V_135 ) ;
if ( V_7 -> V_137 )
F_19 ( V_7 , V_7 -> V_137 ) ;
V_7 -> V_135 = 0 ;
V_7 -> V_137 = 0 ;
F_32 ( V_7 , 0 ) ;
F_17 ( NULL , V_144 , V_7 -> V_31 , V_7 -> V_145 ) ;
F_42 ( V_2 -> V_164 ) ;
F_42 ( V_2 -> V_165 ) ;
}
static struct V_153 * F_43 (
struct V_151 * V_152 , struct V_168 * V_169 ,
unsigned int V_170 , enum V_171 V_123 ,
unsigned long V_34 , void * V_122 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_21 , V_59 , V_46 ;
int V_11 = V_7 -> V_11 ;
struct V_168 * V_172 ;
if ( V_7 -> V_41 == V_54 )
return NULL ;
V_7 -> V_41 = V_54 ;
V_7 -> V_34 = 0 ;
V_7 -> V_51 = 0 ;
F_29 ( V_2 -> V_24 , L_8 ,
V_170 , V_11 ) ;
V_7 -> V_123 = V_123 ;
V_21 = F_28 ( V_7 ) ;
if ( V_21 )
goto V_173;
if ( V_170 > V_174 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_170 , V_174 ) ;
V_21 = - V_15 ;
goto V_173;
}
V_7 -> V_175 = 0 ;
F_44 (sgl, sg, sg_len, i) {
struct V_29 * V_31 = & V_7 -> V_31 [ V_59 ] ;
int V_176 ;
V_31 -> V_47 = V_172 -> V_177 ;
V_46 = F_45 ( V_172 ) ;
if ( V_46 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_10 ,
V_11 , V_46 , 0xffff ) ;
V_21 = - V_15 ;
goto V_173;
}
V_31 -> V_38 . V_46 = V_46 ;
V_7 -> V_175 += V_46 ;
if ( V_7 -> V_178 > V_179 ) {
V_21 = - V_15 ;
goto V_173;
}
switch ( V_7 -> V_178 ) {
case V_179 :
V_31 -> V_38 . V_39 = 0 ;
if ( V_46 & 3 || V_172 -> V_177 & 3 )
return NULL ;
break;
case V_180 :
V_31 -> V_38 . V_39 = 2 ;
if ( V_46 & 1 || V_172 -> V_177 & 1 )
return NULL ;
break;
case V_181 :
V_31 -> V_38 . V_39 = 1 ;
break;
default:
return NULL ;
}
V_176 = V_42 | V_45 | V_182 ;
if ( V_59 + 1 == V_170 ) {
V_176 |= V_43 ;
V_176 |= V_183 ;
V_176 &= ~ V_182 ;
}
F_29 ( V_2 -> V_24 , L_11 ,
V_59 , V_46 , V_172 -> V_177 ,
V_176 & V_44 ? L_12 : L_13 ,
V_176 & V_43 ? L_14 : L_13 ) ;
V_31 -> V_38 . V_41 = V_176 ;
}
V_7 -> V_55 = V_170 ;
V_2 -> V_147 [ V_11 ] . V_149 = V_7 -> V_145 ;
return & V_7 -> V_56 ;
V_173:
V_7 -> V_41 = V_53 ;
return NULL ;
}
static struct V_153 * F_46 (
struct V_151 * V_152 , T_2 V_184 , T_5 V_185 ,
T_5 V_186 , enum V_171 V_123 ,
unsigned long V_34 , void * V_122 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_187 = V_185 / V_186 ;
int V_11 = V_7 -> V_11 ;
int V_21 , V_59 = 0 , V_26 = 0 ;
F_29 ( V_2 -> V_24 , L_15 , V_188 , V_11 ) ;
if ( V_7 -> V_41 == V_54 )
return NULL ;
V_7 -> V_41 = V_54 ;
V_7 -> V_51 = 0 ;
V_7 -> V_34 |= V_64 ;
V_7 -> V_123 = V_123 ;
V_21 = F_28 ( V_7 ) ;
if ( V_21 )
goto V_173;
if ( V_187 > V_174 ) {
F_12 ( V_2 -> V_24 , L_9 ,
V_11 , V_187 , V_174 ) ;
goto V_173;
}
if ( V_186 > 0xffff ) {
F_12 ( V_2 -> V_24 , L_16 ,
V_11 , V_186 , 0xffff ) ;
goto V_173;
}
while ( V_26 < V_185 ) {
struct V_29 * V_31 = & V_7 -> V_31 [ V_59 ] ;
int V_176 ;
V_31 -> V_47 = V_184 ;
V_31 -> V_38 . V_46 = V_186 ;
if ( V_7 -> V_178 > V_179 )
goto V_173;
if ( V_7 -> V_178 == V_179 )
V_31 -> V_38 . V_39 = 0 ;
else
V_31 -> V_38 . V_39 = V_7 -> V_178 ;
V_176 = V_42 | V_45 | V_182 | V_43 ;
if ( V_59 + 1 == V_187 )
V_176 |= V_44 ;
F_29 ( V_2 -> V_24 , L_11 ,
V_59 , V_186 , V_184 ,
V_176 & V_44 ? L_12 : L_13 ,
V_176 & V_43 ? L_14 : L_13 ) ;
V_31 -> V_38 . V_41 = V_176 ;
V_184 += V_186 ;
V_26 += V_186 ;
V_59 ++ ;
}
V_7 -> V_55 = V_187 ;
V_2 -> V_147 [ V_11 ] . V_149 = V_7 -> V_145 ;
return & V_7 -> V_56 ;
V_173:
V_7 -> V_41 = V_53 ;
return NULL ;
}
static int F_47 ( struct V_151 * V_152 , enum V_189 V_190 ,
unsigned long V_191 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
struct V_192 * V_193 = ( void * ) V_191 ;
switch ( V_190 ) {
case V_194 :
F_30 ( V_7 ) ;
return 0 ;
case V_195 :
if ( V_193 -> V_123 == V_124 ) {
V_7 -> V_138 = V_193 -> V_196 ;
V_7 -> V_125 = V_193 -> V_197 *
V_193 -> V_198 ;
V_7 -> V_178 = V_193 -> V_198 ;
} else {
V_7 -> V_138 = V_193 -> V_199 ;
V_7 -> V_125 = V_193 -> V_200 *
V_193 -> V_201 ;
V_7 -> V_178 = V_193 -> V_201 ;
}
V_7 -> V_123 = V_193 -> V_123 ;
return F_31 ( V_7 ) ;
default:
return - V_202 ;
}
return - V_15 ;
}
static enum V_203 F_48 ( struct V_151 * V_152 ,
T_4 V_155 ,
struct V_204 * V_205 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
F_49 ( V_205 , V_152 -> V_206 , V_152 -> V_155 ,
V_7 -> V_175 - V_7 -> V_60 ) ;
return V_7 -> V_41 ;
}
static void F_50 ( struct V_151 * V_152 )
{
struct V_6 * V_7 = F_34 ( V_152 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_41 == V_54 )
F_7 ( V_2 , V_7 -> V_11 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
const struct V_207 * V_208 )
{
T_6 * V_209 = ( T_1 * ) V_208 ;
T_6 * V_210 = ( T_1 * ) V_2 -> V_79 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_211 ; V_59 ++ )
if ( V_209 [ V_59 ] > 0 )
V_210 [ V_59 ] = V_209 [ V_59 ] ;
}
static void F_52 ( const struct V_212 * V_213 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
const struct V_214 * V_215 ;
const struct V_207 * V_208 ;
unsigned short * V_216 ;
if ( ! V_213 ) {
F_12 ( V_2 -> V_24 , L_17 ) ;
return;
}
if ( V_213 -> V_27 < sizeof( * V_215 ) )
goto V_217;
V_215 = (struct V_214 * ) V_213 -> V_63 ;
if ( V_215 -> V_218 != V_219 )
goto V_217;
if ( V_215 -> V_220 + V_215 -> V_221 > V_213 -> V_27 )
goto V_217;
V_208 = ( void * ) V_215 + V_215 -> V_222 ;
V_216 = ( void * ) V_215 + V_215 -> V_220 ;
F_39 ( V_2 -> V_164 ) ;
F_39 ( V_2 -> V_165 ) ;
F_13 ( V_2 , V_216 ,
V_215 -> V_221 ,
V_208 -> V_223 ) ;
F_42 ( V_2 -> V_164 ) ;
F_42 ( V_2 -> V_165 ) ;
F_51 ( V_2 , V_208 ) ;
F_53 ( V_2 -> V_24 , L_18 ,
V_215 -> V_224 ,
V_215 -> V_225 ) ;
V_217:
F_54 ( V_213 ) ;
}
static int T_7 F_55 ( struct V_1 * V_2 ,
const char * V_226 )
{
int V_21 ;
V_21 = F_56 ( V_227 ,
V_228 , V_226 , V_2 -> V_24 ,
V_35 , V_2 , F_52 ) ;
return V_21 ;
}
static int T_7 F_57 ( struct V_1 * V_2 )
{
int V_59 , V_21 ;
T_2 V_229 ;
F_39 ( V_2 -> V_164 ) ;
F_39 ( V_2 -> V_165 ) ;
F_6 ( 0 , V_2 -> V_16 + V_230 ) ;
V_2 -> V_147 = F_14 ( NULL ,
V_231 * sizeof ( struct V_232 ) +
sizeof( struct V_121 ) ,
& V_229 , V_35 ) ;
if ( ! V_2 -> V_147 ) {
V_21 = - V_36 ;
goto V_233;
}
V_2 -> V_122 = ( void * ) V_2 -> V_147 +
V_231 * sizeof ( struct V_232 ) ;
V_2 -> V_133 = V_229 +
V_231 * sizeof ( struct V_232 ) ;
memset ( V_2 -> V_147 , 0 ,
V_231 * sizeof ( struct V_232 ) ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_5 -> V_136 ; V_59 ++ )
F_6 ( 0 , V_2 -> V_16 + F_1 ( V_2 , V_59 ) ) ;
for ( V_59 = 0 ; V_59 < V_231 ; V_59 ++ )
F_6 ( 0 , V_2 -> V_16 + V_142 + V_59 * 4 ) ;
V_21 = F_33 ( & V_2 -> V_11 [ 0 ] ) ;
if ( V_21 )
goto V_233;
F_2 ( & V_2 -> V_11 [ 0 ] , false , true , false ) ;
F_6 ( 0x4050 , V_2 -> V_16 + V_234 ) ;
F_6 ( 0 , V_2 -> V_16 + V_235 ) ;
F_6 ( V_229 , V_2 -> V_16 + V_230 ) ;
F_6 ( V_236 , V_2 -> V_16 + V_235 ) ;
F_32 ( & V_2 -> V_11 [ 0 ] , 7 ) ;
F_42 ( V_2 -> V_164 ) ;
F_42 ( V_2 -> V_165 ) ;
return 0 ;
V_233:
F_42 ( V_2 -> V_164 ) ;
F_42 ( V_2 -> V_165 ) ;
F_12 ( V_2 -> V_24 , L_19 , V_21 ) ;
return V_21 ;
}
static bool F_58 ( struct V_151 * V_152 , void * V_237 )
{
struct V_157 * V_63 = V_237 ;
if ( ! F_59 ( V_152 ) )
return false ;
V_152 -> V_158 = V_63 ;
return true ;
}
static struct V_151 * F_60 ( struct V_238 * V_239 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = V_241 -> V_242 ;
T_8 V_243 = V_2 -> V_244 . V_245 ;
struct V_157 V_63 ;
if ( V_239 -> V_246 != 3 )
return NULL ;
V_63 . V_163 = V_239 -> args [ 0 ] ;
V_63 . V_71 = V_239 -> args [ 1 ] ;
V_63 . V_139 = V_239 -> args [ 2 ] ;
return F_61 ( V_243 , F_58 , & V_63 ) ;
}
static int T_7 F_62 ( struct V_247 * V_248 )
{
const struct V_249 * V_250 =
F_63 ( V_251 , & V_248 -> V_24 ) ;
struct V_252 * V_253 = V_248 -> V_24 . V_254 ;
const char * V_226 ;
int V_21 ;
int V_65 ;
struct V_255 * V_256 ;
struct V_257 * V_258 = F_64 ( & V_248 -> V_24 ) ;
int V_59 ;
struct V_1 * V_2 ;
T_6 * V_210 ;
const struct V_259 * V_5 = NULL ;
if ( V_250 )
V_5 = V_250 -> V_63 ;
else if ( V_248 -> V_260 )
V_5 = ( void * ) V_248 -> V_260 -> V_261 ;
if ( ! V_5 ) {
F_12 ( & V_248 -> V_24 , L_20 ) ;
return - V_15 ;
}
V_2 = F_65 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_66 ( & V_2 -> V_37 ) ;
V_2 -> V_24 = & V_248 -> V_24 ;
V_2 -> V_5 = V_5 ;
V_256 = F_67 ( V_248 , V_262 , 0 ) ;
V_65 = F_68 ( V_248 , 0 ) ;
if ( ! V_256 || V_65 < 0 ) {
V_21 = - V_15 ;
goto V_263;
}
if ( ! F_69 ( V_256 -> V_264 , F_70 ( V_256 ) , V_248 -> V_265 ) ) {
V_21 = - V_143 ;
goto V_266;
}
V_2 -> V_164 = F_71 ( & V_248 -> V_24 , L_21 ) ;
if ( F_72 ( V_2 -> V_164 ) ) {
V_21 = F_73 ( V_2 -> V_164 ) ;
goto V_267;
}
V_2 -> V_165 = F_71 ( & V_248 -> V_24 , L_22 ) ;
if ( F_72 ( V_2 -> V_165 ) ) {
V_21 = F_73 ( V_2 -> V_165 ) ;
goto V_267;
}
F_74 ( V_2 -> V_164 ) ;
F_74 ( V_2 -> V_165 ) ;
V_2 -> V_16 = F_75 ( V_256 -> V_264 , F_70 ( V_256 ) ) ;
if ( ! V_2 -> V_16 ) {
V_21 = - V_36 ;
goto V_268;
}
V_21 = F_76 ( V_65 , F_24 , 0 , L_23 , V_2 ) ;
if ( V_21 )
goto V_269;
V_2 -> V_79 = F_65 ( sizeof( * V_2 -> V_79 ) , V_35 ) ;
if ( ! V_2 -> V_79 ) {
V_21 = - V_36 ;
goto V_270;
}
V_210 = ( T_6 * ) V_2 -> V_79 ;
for ( V_59 = 0 ; V_59 < V_211 ; V_59 ++ )
V_210 [ V_59 ] = - V_15 ;
F_77 ( V_271 , V_2 -> V_244 . V_245 ) ;
F_77 ( V_272 , V_2 -> V_244 . V_245 ) ;
F_78 ( & V_2 -> V_244 . V_273 ) ;
for ( V_59 = 0 ; V_59 < V_231 ; V_59 ++ ) {
struct V_6 * V_7 = & V_2 -> V_11 [ V_59 ] ;
V_7 -> V_2 = V_2 ;
F_66 ( & V_7 -> V_156 ) ;
V_7 -> V_152 . V_274 = & V_2 -> V_244 ;
F_79 ( & V_7 -> V_152 ) ;
V_7 -> V_11 = V_59 ;
F_80 ( & V_7 -> V_68 , F_23 ,
( unsigned long ) V_7 ) ;
if ( V_59 )
F_81 ( & V_7 -> V_152 . V_252 ,
& V_2 -> V_244 . V_273 ) ;
}
V_21 = F_57 ( V_2 ) ;
if ( V_21 )
goto V_275;
if ( V_2 -> V_5 -> V_79 )
F_51 ( V_2 , V_2 -> V_5 -> V_79 ) ;
if ( V_258 && V_258 -> V_79 )
F_51 ( V_2 , V_258 -> V_79 ) ;
if ( V_258 ) {
V_21 = F_55 ( V_2 , V_258 -> V_226 ) ;
if ( V_21 )
F_82 ( & V_248 -> V_24 , L_24 ) ;
} else {
V_21 = F_83 ( V_253 , L_25 ,
& V_226 ) ;
if ( V_21 )
F_82 ( & V_248 -> V_24 , L_26 ) ;
else {
V_21 = F_55 ( V_2 , V_226 ) ;
if ( V_21 )
F_82 ( & V_248 -> V_24 , L_27 ) ;
}
}
V_2 -> V_244 . V_24 = & V_248 -> V_24 ;
V_2 -> V_244 . V_276 = F_38 ;
V_2 -> V_244 . V_277 = F_41 ;
V_2 -> V_244 . V_278 = F_48 ;
V_2 -> V_244 . V_279 = F_43 ;
V_2 -> V_244 . V_280 = F_46 ;
V_2 -> V_244 . V_281 = F_47 ;
V_2 -> V_244 . V_282 = F_50 ;
V_2 -> V_244 . V_24 -> V_283 = & V_2 -> V_283 ;
F_84 ( V_2 -> V_244 . V_24 , 65535 ) ;
V_21 = F_85 ( & V_2 -> V_244 ) ;
if ( V_21 ) {
F_12 ( & V_248 -> V_24 , L_28 ) ;
goto V_275;
}
if ( V_253 ) {
V_21 = F_86 ( V_253 , F_60 , V_2 ) ;
if ( V_21 ) {
F_12 ( & V_248 -> V_24 , L_29 ) ;
goto V_284;
}
}
F_53 ( V_2 -> V_24 , L_30 ) ;
return 0 ;
V_284:
F_87 ( & V_2 -> V_244 ) ;
V_275:
F_88 ( V_2 -> V_79 ) ;
V_270:
F_89 ( V_65 , V_2 ) ;
V_269:
F_90 ( V_2 -> V_16 ) ;
V_268:
V_267:
F_91 ( V_256 -> V_264 , F_70 ( V_256 ) ) ;
V_266:
V_263:
F_88 ( V_2 ) ;
return V_21 ;
}
static int F_92 ( struct V_247 * V_248 )
{
return - V_143 ;
}
static int T_7 F_93 ( void )
{
return F_94 ( & V_285 , F_62 ) ;
}
