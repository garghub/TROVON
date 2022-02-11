static T_1 F_1 ( T_2 V_1 , const struct V_2 * V_3 )
{
if ( V_3 -> V_4 != V_5 )
return V_1 * V_3 -> V_6 / 8 ;
switch ( V_3 -> V_7 ) {
case V_8 :
return V_1 * V_3 -> V_6 / 8 ;
case V_9 :
case V_10 :
return V_1 * 2 ;
}
return - V_11 ;
}
static T_1 F_2 ( const struct V_2 * V_3 ,
T_2 V_12 , T_2 V_13 )
{
switch ( V_3 -> V_7 ) {
case V_9 :
return V_12 * V_13 * 2 ;
default:
return - V_11 ;
}
}
static const struct V_2 * F_3 (
T_2 V_14 ,
const struct V_15 * V_16 ,
int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
if ( V_16 [ V_18 ] . V_14 == V_14 )
return & V_16 [ V_18 ] . V_19 ;
return NULL ;
}
static const struct V_2 * F_4 (
T_2 V_14 )
{
return F_3 ( V_14 , V_20 , F_5 ( V_20 ) ) ;
}
static unsigned int F_6 ( const struct V_21 * V_22 ,
unsigned int V_23 )
{
unsigned long V_24 ;
bool V_25 = true , V_26 = true , V_27 , V_28 , V_29 ;
bool V_30 , V_31 ;
V_24 = V_22 -> V_23 & V_23 ;
switch ( V_22 -> type ) {
case V_32 :
V_25 = V_24 & ( V_33 |
V_34 ) ;
V_26 = V_24 & ( V_35 |
V_36 ) ;
case V_37 :
V_27 = V_24 & ( V_38 |
V_39 ) ;
V_28 = V_24 & ( V_40 |
V_41 ) ;
V_29 = V_24 & ( V_42 | V_43 ) ;
return ( ! V_25 || ! V_26 || ! V_27 || ! V_28 || ! V_29 ) ?
0 : V_24 ;
case V_44 :
V_30 = V_24 & V_45 ;
V_31 = V_24 & ( V_46 |
V_47 ) ;
return ( ! V_30 || ! V_31 ) ? 0 : V_24 ;
}
return 0 ;
}
static const struct V_48
* F_7 ( struct V_48 * V_49 ,
unsigned int V_50 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_49 [ V_18 ] . V_14 ; V_18 ++ )
if ( V_49 [ V_18 ] . V_51 -> V_50 == V_50 )
return V_49 + V_18 ;
return NULL ;
}
static struct V_48 * F_8 (
struct V_52 * V_53 , struct V_54 * V_55 ,
int (* F_9)( struct V_52 * , unsigned int ,
struct V_48 * V_56 ) )
{
unsigned int V_18 , V_57 = 0 , V_58 = 0 ;
int V_59 ;
struct V_60 V_14 = {
. V_61 = V_62 ,
} ;
struct V_48 * V_49 ;
while ( ! F_10 ( V_55 , V_63 , V_64 , NULL , & V_14 ) ) {
V_58 ++ ;
V_14 . V_65 ++ ;
}
for ( V_18 = 0 ; V_18 < V_58 ; V_18 ++ ) {
V_59 = F_9 ( V_53 , V_18 , NULL ) ;
if ( V_59 < 0 )
return F_11 ( V_59 ) ;
V_57 += V_59 ;
}
if ( ! V_57 )
return F_11 ( - V_66 ) ;
V_49 = F_12 ( V_57 + 1 , sizeof( * V_49 ) , V_67 ) ;
if ( ! V_49 )
return F_11 ( - V_68 ) ;
V_57 = 0 ;
for ( V_18 = 0 ; V_18 < V_58 ; V_18 ++ ) {
V_59 = F_9 ( V_53 , V_18 , V_49 + V_57 ) ;
if ( V_59 < 0 )
goto V_69;
V_57 += V_59 ;
}
V_49 [ V_57 ] . V_14 = 0 ;
return V_49 ;
V_69:
F_13 ( V_49 ) ;
return F_11 ( V_59 ) ;
}
static struct V_70 * F_14 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_15 ( V_72 ) ;
return F_16 ( V_74 , struct V_70 , V_74 ) ;
}
static struct V_75 * F_17 ( struct V_76 * V_77 )
{
return V_77 -> V_53 . V_78 ;
}
static struct V_76 * F_18 ( struct V_52 * V_53 )
{
return F_16 ( V_53 , struct V_76 , V_53 ) ;
}
static void F_19 ( void * V_28 )
{
struct V_76 * V_77 = V_28 ;
F_20 ( V_77 , V_79 ) ;
}
static void F_21 ( void * V_28 )
{
struct V_76 * V_77 = V_28 ;
F_20 ( V_77 , V_80 ) ;
}
static void F_22 ( void * V_28 )
{
struct V_76 * V_77 = V_28 ;
F_20 ( V_77 , V_81 ) ;
}
static int F_23 ( struct V_76 * V_77 ,
struct V_70 * V_82 , int V_83 ,
struct V_84 * V_85 , int V_86 )
{
struct V_87 * V_87 = V_77 -> V_88 [ V_83 ] ;
struct V_89 * V_90 ;
V_90 = F_24 ( V_87 , V_85 , V_86 , V_91 ,
V_92 | V_93 ) ;
if ( ! V_90 ) {
F_25 ( F_17 ( V_77 ) ,
L_1 ) ;
goto V_94;
}
V_90 -> V_95 = V_77 ;
switch ( V_83 ) {
case 0 :
V_90 -> V_96 = F_19 ;
break;
case 1 :
V_90 -> V_96 = F_21 ;
break;
case 2 :
V_90 -> V_96 = F_22 ;
break;
}
V_82 -> V_97 [ V_83 ] = V_90 ;
return 0 ;
V_94:
F_26 ( F_17 ( V_77 ) ,
L_2 ,
V_98 , V_82 , V_90 ) ;
return - V_68 ;
}
static void F_27 ( struct V_76 * V_77 ,
struct V_70 * V_82 )
{
V_82 -> V_99 = V_79 ;
if ( V_82 -> V_100 == 3 )
V_82 -> V_99 |= V_80 | V_81 ;
}
static void F_28 ( struct V_76 * V_77 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_77 -> V_101 ; V_18 ++ ) {
F_26 ( F_17 ( V_77 ) ,
L_3 , V_98 , V_18 ) ;
F_29 ( V_77 -> V_88 [ V_18 ] ) ;
}
}
static void F_30 ( struct V_76 * V_77 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_77 -> V_101 ; V_18 ++ ) {
F_26 ( F_17 ( V_77 ) ,
L_3 , V_98 , V_18 ) ;
F_31 ( V_77 -> V_88 [ V_18 ] ) ;
}
}
static void F_32 ( struct V_76 * V_77 ,
struct V_70 * V_82 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_77 -> V_101 ; V_18 ++ ) {
V_82 -> V_102 [ V_18 ] = F_33 ( V_82 -> V_97 [ V_18 ] ) ;
F_26 ( F_17 ( V_77 ) ,
L_4 ,
V_98 , V_18 , V_82 , V_82 -> V_97 [ V_18 ] -> V_102 ) ;
}
}
static void F_34 ( struct V_76 * V_77 )
{
unsigned long V_103 ;
F_26 ( F_17 ( V_77 ) , L_5 , V_98 ) ;
F_35 ( F_36 ( V_77 -> V_104 + V_105 ) , V_77 -> V_104 + V_105 ) ;
V_103 = F_36 ( V_77 -> V_104 + V_106 ) | V_107 ;
V_103 &= ~ V_108 ;
F_35 ( V_103 , V_77 -> V_104 + V_106 ) ;
}
static void F_37 ( struct V_76 * V_77 )
{
unsigned long V_103 ;
F_30 ( V_77 ) ;
V_103 = F_36 ( V_77 -> V_104 + V_106 ) & ~ V_107 ;
F_35 ( V_103 , V_77 -> V_104 + V_106 ) ;
V_77 -> V_109 = NULL ;
F_26 ( F_17 ( V_77 ) , L_5 , V_98 ) ;
}
static void F_38 ( struct V_76 * V_77 ,
struct V_70 * V_82 ,
enum V_110 V_111 )
{
struct V_71 * V_72 = & V_82 -> V_74 . V_112 ;
struct V_73 * V_74 = F_15 ( V_72 ) ;
F_39 ( & V_82 -> V_113 ) ;
V_72 -> V_114 = F_40 () ;
V_74 -> V_115 = V_77 -> V_116 ++ ;
V_74 -> V_117 = V_118 ;
F_41 ( V_72 , V_119 ) ;
F_26 ( F_17 ( V_77 ) , L_6 ,
V_98 , V_82 ) ;
if ( F_42 ( & V_77 -> V_120 ) ) {
F_37 ( V_77 ) ;
return;
}
V_77 -> V_109 = F_43 ( V_77 -> V_120 . V_121 ,
struct V_70 , V_113 ) ;
}
static void F_44 ( struct V_76 * V_77 ,
T_3 V_122 ,
T_3 V_123 )
{
bool V_124 = V_122 != V_123 ;
F_26 ( F_17 ( V_77 ) ,
L_7 ,
V_98 , V_77 -> V_109 , V_124 ) ;
if ( V_77 -> V_109 && V_124 )
F_34 ( V_77 ) ;
}
static void F_20 ( struct V_76 * V_77 ,
enum V_125 V_126 )
{
struct V_70 * V_82 , * V_127 ;
unsigned long V_23 ;
T_2 V_128 , V_129 ;
int V_130 ;
enum V_131 V_132 ;
T_3 V_123 ;
F_45 ( & V_77 -> V_133 , V_23 ) ;
V_128 = F_36 ( V_77 -> V_104 + V_105 ) ;
F_26 ( F_17 ( V_77 ) , L_8 ,
V_128 , V_126 ) ;
V_129 = V_134 ;
if ( V_77 -> V_101 == 3 )
V_129 |= V_135 | V_136 ;
if ( ! V_77 -> V_109 )
goto V_137;
V_82 = V_77 -> V_109 ;
F_46 ( V_82 -> V_138 || F_42 ( & V_82 -> V_113 ) ) ;
switch ( V_126 ) {
case V_80 :
V_130 = 1 ;
break;
case V_81 :
V_130 = 2 ;
break;
default:
V_130 = 0 ;
break;
}
V_127 = F_43 ( V_77 -> V_120 . V_139 ,
struct V_70 , V_113 ) ;
V_132 = F_47 ( V_77 -> V_88 [ V_130 ] ,
V_127 -> V_102 [ V_130 ] ,
NULL , & V_123 ) ;
if ( V_128 & V_129 &&
V_132 != V_140 ) {
F_26 ( F_17 ( V_77 ) , L_9 ,
V_128 ) ;
F_37 ( V_77 ) ;
F_48 (buf, &pcdev->capture, queue)
F_32 ( V_77 , V_82 ) ;
F_34 ( V_77 ) ;
goto V_137;
}
V_82 -> V_99 &= ~ V_126 ;
if ( ! V_82 -> V_99 ) {
F_38 ( V_77 , V_82 , V_119 ) ;
F_44 ( V_77 , V_127 -> V_102 [ V_130 ] ,
V_123 ) ;
}
V_137:
F_49 ( & V_77 -> V_133 , V_23 ) ;
}
static T_2 F_50 ( struct V_141 * V_142 ,
struct V_76 * V_77 )
{
unsigned long V_143 = V_77 -> V_143 ;
T_2 div ;
unsigned long V_144 ;
V_144 = F_51 ( V_77 -> V_145 ) ;
V_77 -> V_146 = V_144 ;
if ( V_143 > V_144 / 4 ) {
V_143 = V_144 / 4 ;
F_52 ( F_17 ( V_77 ) ,
L_10 , V_143 ) ;
}
div = ( V_144 + 2 * V_143 - 1 ) / ( 2 * V_143 ) - 1 ;
if ( V_77 -> V_147 & V_148 )
V_77 -> V_143 = V_144 / ( 2 * ( div + 1 ) ) ;
F_26 ( F_17 ( V_77 ) , L_11 ,
V_144 , V_143 , div ) ;
return div ;
}
static void F_53 ( struct V_76 * V_77 ,
unsigned long V_27 )
{
T_2 V_149 = V_77 -> V_146 / V_27 + 1 ;
F_35 ( V_149 , V_77 -> V_104 + V_150 ) ;
}
static void F_54 ( struct V_76 * V_77 )
{
T_2 V_151 = 0 ;
F_35 ( 0x3ff , V_77 -> V_104 + V_106 ) ;
if ( V_77 -> V_147 & V_152 )
V_151 |= V_153 ;
if ( V_77 -> V_147 & V_148 )
V_151 |= V_154 ;
if ( V_77 -> V_147 & V_155 )
V_151 |= V_156 ;
if ( V_77 -> V_147 & V_157 )
V_151 |= V_158 ;
if ( V_77 -> V_147 & V_159 )
V_151 |= V_160 ;
F_35 ( V_77 -> V_161 | V_151 , V_77 -> V_104 + V_162 ) ;
if ( V_77 -> V_147 & V_148 )
F_53 ( V_77 , V_77 -> V_143 ) ;
else
F_53 ( V_77 , 13000000 ) ;
F_55 ( V_77 -> V_145 ) ;
}
static void F_56 ( struct V_76 * V_77 )
{
F_57 ( V_77 -> V_145 ) ;
}
static void F_58 ( unsigned long V_163 )
{
struct V_76 * V_77 = (struct V_76 * ) V_163 ;
unsigned long V_164 ;
struct V_70 * V_82 ;
F_26 ( F_17 ( V_77 ) ,
L_12 ,
F_36 ( V_77 -> V_104 + V_105 ) ) ;
V_164 = F_36 ( V_77 -> V_104 + V_165 ) | V_166 ;
F_35 ( V_164 , V_77 -> V_104 + V_165 ) ;
V_77 -> V_109 = F_59 ( & V_77 -> V_120 ,
struct V_70 , V_113 ) ;
V_82 = V_77 -> V_109 ;
F_27 ( V_77 , V_82 ) ;
F_28 ( V_77 ) ;
}
static T_4 F_60 ( int V_167 , void * V_28 )
{
struct V_76 * V_77 = V_28 ;
unsigned long V_168 , V_103 ;
V_168 = F_36 ( V_77 -> V_104 + V_105 ) ;
F_26 ( F_17 ( V_77 ) ,
L_13 , V_168 ) ;
if ( ! V_168 )
return V_169 ;
F_35 ( V_168 , V_77 -> V_104 + V_105 ) ;
if ( V_168 & V_170 ) {
V_103 = F_36 ( V_77 -> V_104 + V_106 ) | V_108 ;
F_35 ( V_103 , V_77 -> V_104 + V_106 ) ;
F_61 ( & V_77 -> V_171 ) ;
}
return V_172 ;
}
static int F_62 ( struct V_76 * V_77 ,
unsigned char V_173 , unsigned long * V_23 )
{
* V_23 = ( V_77 -> V_147 & V_174 ?
V_42 : V_43 ) |
V_33 |
V_34 |
V_35 |
V_36 |
V_40 |
V_38 |
V_39 ;
if ( ( 1 << ( V_173 - 1 ) ) & V_77 -> V_175 )
return 0 ;
return - V_11 ;
}
static void F_63 ( struct V_76 * V_77 ,
unsigned long V_23 , T_5 V_176 )
{
unsigned long V_177 , V_178 ;
T_2 V_103 , V_179 , V_180 , V_181 , V_151 = 0 , V_182 ;
int V_59 = F_64 ( V_77 , V_183 , V_184 , & V_182 ) ;
if ( V_59 < 0 )
V_182 = 0 ;
switch ( V_77 -> V_185 -> V_51 -> V_6 ) {
case 10 :
V_177 = 4 ;
V_178 = 0x40 ;
break;
case 9 :
V_177 = 3 ;
V_178 = 0x20 ;
break;
default:
case 8 :
V_177 = 2 ;
V_178 = 0 ;
}
if ( V_77 -> V_147 & V_152 )
V_151 |= V_153 ;
if ( V_77 -> V_147 & V_148 )
V_151 |= V_154 ;
if ( V_23 & V_39 )
V_151 |= V_156 ;
if ( V_23 & V_34 )
V_151 |= V_158 ;
if ( V_23 & V_36 )
V_151 |= V_160 ;
V_103 = F_36 ( V_77 -> V_104 + V_106 ) ;
if ( V_103 & V_107 )
F_35 ( V_103 & ~ V_107 , V_77 -> V_104 + V_106 ) ;
V_179 = F_65 ( V_77 -> V_186 . V_1 - 1 ) | V_178 | V_177 ;
switch ( V_176 ) {
case V_187 :
V_77 -> V_101 = 3 ;
V_179 |= V_188 ;
case V_189 :
case V_190 :
case V_191 :
case V_192 :
V_179 |= F_66 ( 2 ) ;
break;
case V_193 :
V_179 |= F_67 ( 1 ) | F_68 ( 2 ) |
V_194 | F_66 ( 1 ) ;
break;
case V_195 :
V_179 |= F_66 ( 1 ) | F_67 ( 2 ) ;
break;
}
V_180 = 0 ;
V_181 = F_69 ( V_77 -> V_186 . V_13 - 1 ) |
F_70 ( F_71 ( ( T_2 ) 255 , V_182 ) ) ;
V_151 |= V_77 -> V_161 ;
F_35 ( V_179 , V_77 -> V_104 + V_196 ) ;
F_35 ( V_180 , V_77 -> V_104 + V_197 ) ;
F_35 ( V_181 , V_77 -> V_104 + V_198 ) ;
F_35 ( V_151 , V_77 -> V_104 + V_162 ) ;
V_103 = ( V_103 & V_107 ) | ( V_77 -> V_147 & V_174 ?
V_199 : ( V_200 | V_201 ) ) ;
V_103 |= V_202 | V_203 ;
F_35 ( V_103 , V_77 -> V_104 + V_106 ) ;
}
static void F_72 ( struct V_70 * V_82 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 3 && V_82 -> V_97 [ V_18 ] ; V_18 ++ ) {
F_73 ( V_82 -> V_97 [ V_18 ] ) ;
F_13 ( V_82 -> V_85 [ V_18 ] ) ;
V_82 -> V_97 [ V_18 ] = NULL ;
V_82 -> V_85 [ V_18 ] = NULL ;
V_82 -> V_204 [ V_18 ] = 0 ;
V_82 -> V_205 [ V_18 ] = 0 ;
}
V_82 -> V_100 = 0 ;
}
static int F_74 ( struct V_76 * V_77 ,
struct V_70 * V_82 )
{
struct V_71 * V_72 = & V_82 -> V_74 . V_112 ;
struct V_206 * V_207 = F_75 ( V_72 , 0 ) ;
int V_208 = V_77 -> V_101 ;
int V_18 , V_59 = 0 ;
unsigned long V_209 = F_76 ( V_72 , 0 ) ;
switch ( V_208 ) {
case 1 :
V_82 -> V_205 [ 0 ] = V_209 ;
break;
case 3 :
V_82 -> V_205 [ 0 ] = V_209 / 2 ;
V_82 -> V_205 [ 1 ] = V_209 / 4 ;
V_82 -> V_205 [ 2 ] = V_209 / 4 ;
break;
default:
return - V_11 ;
} ;
V_82 -> V_100 = V_208 ;
V_59 = F_77 ( V_207 -> V_210 , V_207 -> V_211 , 0 , V_208 ,
V_82 -> V_205 , V_82 -> V_85 , V_82 -> V_204 , V_67 ) ;
if ( V_59 < 0 ) {
F_25 ( F_17 ( V_77 ) ,
L_14 , V_59 ) ;
return V_59 ;
}
for ( V_18 = 0 ; V_18 < V_208 ; V_18 ++ ) {
V_59 = F_23 ( V_77 , V_82 , V_18 ,
V_82 -> V_85 [ V_18 ] , V_82 -> V_204 [ V_18 ] ) ;
if ( V_59 ) {
F_72 ( V_82 ) ;
return V_59 ;
}
}
F_78 ( & V_82 -> V_113 ) ;
return V_59 ;
}
static void F_79 ( struct V_71 * V_72 )
{
struct V_70 * V_82 = F_14 ( V_72 ) ;
struct V_76 * V_77 = F_80 ( V_72 -> V_212 ) ;
F_26 ( F_17 ( V_77 ) ,
L_15 , V_98 , V_72 ) ;
F_72 ( V_82 ) ;
}
static void F_81 ( struct V_71 * V_72 )
{
struct V_70 * V_82 = F_14 ( V_72 ) ;
struct V_76 * V_77 = F_80 ( V_72 -> V_212 ) ;
F_26 ( F_17 ( V_77 ) ,
L_16 ,
V_98 , V_72 , V_77 -> V_101 , F_82 ( V_72 , 0 ) ,
V_77 -> V_109 ) ;
F_83 ( & V_82 -> V_113 , & V_77 -> V_120 ) ;
F_32 ( V_77 , V_82 ) ;
}
static int F_84 ( struct V_71 * V_72 )
{
struct V_76 * V_77 = F_80 ( V_72 -> V_212 ) ;
struct V_70 * V_82 = F_14 ( V_72 ) ;
int V_59 = 0 ;
switch ( V_77 -> V_101 ) {
case 1 :
case 3 :
F_85 ( V_72 , 0 , V_77 -> V_186 . V_213 ) ;
break;
default:
return - V_11 ;
}
F_26 ( F_17 ( V_77 ) ,
L_17 ,
V_98 , V_72 , V_77 -> V_101 , F_82 ( V_72 , 0 ) ) ;
F_46 ( ! V_77 -> V_185 ) ;
#ifdef F_86
for ( V_18 = 0 ; V_18 < V_72 -> V_214 ; V_18 ++ )
memset ( ( void * ) F_87 ( V_72 , V_18 ) ,
0xaa , F_82 ( V_72 , V_18 ) ) ;
#endif
V_82 -> V_138 = 0 ;
F_27 ( V_77 , V_82 ) ;
return V_59 ;
}
static int F_88 ( struct V_71 * V_72 )
{
struct V_76 * V_77 = F_80 ( V_72 -> V_212 ) ;
struct V_70 * V_82 = F_14 ( V_72 ) ;
F_26 ( F_17 ( V_77 ) ,
L_18 ,
V_98 , V_77 -> V_101 ) ;
return F_74 ( V_77 , V_82 ) ;
}
static int F_89 ( struct V_212 * V_215 ,
unsigned int * V_216 ,
unsigned int * V_214 , unsigned int V_217 [] ,
struct V_75 * V_218 [] )
{
struct V_76 * V_77 = F_80 ( V_215 ) ;
int V_209 = V_77 -> V_186 . V_213 ;
F_26 ( F_17 ( V_77 ) ,
L_19 ,
V_98 , V_215 , * V_216 , * V_214 , V_209 ) ;
if ( * V_214 )
return V_217 [ 0 ] < V_209 ? - V_11 : 0 ;
* V_214 = 1 ;
switch ( V_77 -> V_101 ) {
case 1 :
case 3 :
V_217 [ 0 ] = V_209 ;
break;
default:
return - V_11 ;
}
if ( ! * V_216 )
* V_216 = 1 ;
return 0 ;
}
static int F_90 ( struct V_212 * V_215 , unsigned int V_219 )
{
struct V_76 * V_77 = F_80 ( V_215 ) ;
F_26 ( F_17 ( V_77 ) , L_20 ,
V_98 , V_219 , V_77 -> V_109 ) ;
V_77 -> V_116 = 0 ;
if ( ! V_77 -> V_109 )
F_34 ( V_77 ) ;
return 0 ;
}
static void F_91 ( struct V_212 * V_215 )
{
struct V_76 * V_77 = F_80 ( V_215 ) ;
struct V_70 * V_82 , * V_220 ;
F_26 ( F_17 ( V_77 ) , L_21 ,
V_98 , V_77 -> V_109 ) ;
F_37 ( V_77 ) ;
F_92 (buf, tmp, &pcdev->capture, queue)
F_38 ( V_77 , V_82 , V_221 ) ;
}
static int F_93 ( struct V_76 * V_77 )
{
int V_59 ;
struct V_212 * V_215 = & V_77 -> V_222 ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
V_215 -> type = V_223 ;
V_215 -> V_224 = V_225 | V_226 | V_227 ;
V_215 -> V_228 = V_77 ;
V_215 -> V_229 = V_230 ;
V_215 -> V_231 = sizeof( struct V_70 ) ;
V_215 -> V_78 = V_77 -> V_53 . V_78 ;
V_215 -> V_232 = & V_233 ;
V_215 -> V_234 = & V_235 ;
V_215 -> V_133 = & V_77 -> V_236 ;
V_59 = F_94 ( V_215 ) ;
F_26 ( F_17 ( V_77 ) ,
L_22 , V_215 , V_59 ) ;
return V_59 ;
}
static int F_95 ( struct V_76 * V_77 )
{
struct V_21 V_22 = { . type = V_32 ,} ;
T_2 V_176 = V_77 -> V_185 -> V_51 -> V_50 ;
unsigned long V_237 , V_24 ;
int V_59 ;
V_59 = F_62 ( V_77 ,
V_77 -> V_185 -> V_51 -> V_6 ,
& V_237 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_64 ( V_77 , V_238 , V_239 , & V_22 ) ;
if ( ! V_59 ) {
V_24 = F_6 ( & V_22 ,
V_237 ) ;
if ( ! V_24 ) {
F_52 ( F_17 ( V_77 ) ,
L_23 ,
V_22 . V_23 , V_237 ) ;
return - V_11 ;
}
} else if ( V_59 != - V_240 ) {
return V_59 ;
} else {
V_24 = V_237 ;
}
V_77 -> V_101 = 1 ;
if ( ( V_24 & V_33 ) &&
( V_24 & V_34 ) ) {
if ( V_77 -> V_147 & V_157 )
V_24 &= ~ V_33 ;
else
V_24 &= ~ V_34 ;
}
if ( ( V_24 & V_35 ) &&
( V_24 & V_36 ) ) {
if ( V_77 -> V_147 & V_159 )
V_24 &= ~ V_35 ;
else
V_24 &= ~ V_36 ;
}
if ( ( V_24 & V_38 ) &&
( V_24 & V_39 ) ) {
if ( V_77 -> V_147 & V_155 )
V_24 &= ~ V_38 ;
else
V_24 &= ~ V_39 ;
}
V_22 . V_23 = V_24 ;
V_59 = F_64 ( V_77 , V_238 , V_241 , & V_22 ) ;
if ( V_59 < 0 && V_59 != - V_240 ) {
F_26 ( F_17 ( V_77 ) ,
L_24 ,
V_24 , V_59 ) ;
return V_59 ;
}
F_63 ( V_77 , V_24 , V_176 ) ;
return 0 ;
}
static int F_96 ( struct V_76 * V_77 ,
unsigned char V_173 )
{
struct V_21 V_22 = { . type = V_32 ,} ;
unsigned long V_237 , V_24 ;
int V_59 = F_62 ( V_77 , V_173 , & V_237 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_64 ( V_77 , V_238 , V_239 , & V_22 ) ;
if ( ! V_59 ) {
V_24 = F_6 ( & V_22 ,
V_237 ) ;
if ( ! V_24 ) {
F_52 ( F_17 ( V_77 ) ,
L_23 ,
V_22 . V_23 , V_237 ) ;
return - V_11 ;
}
} else if ( V_59 == - V_240 ) {
V_59 = 0 ;
}
return V_59 ;
}
static bool F_97 ( const struct V_2 * V_19 )
{
return V_19 -> V_7 == V_8 ||
( V_19 -> V_6 == 8 &&
V_19 -> V_7 == V_9 ) ||
( V_19 -> V_6 > 8 &&
V_19 -> V_7 == V_10 ) ;
}
static int F_98 ( struct V_52 * V_53 ,
unsigned int V_242 ,
struct V_48 * V_56 )
{
struct V_76 * V_77 = F_18 ( V_53 ) ;
int V_243 = 0 , V_59 ;
struct V_60 V_14 = {
. V_61 = V_62 ,
. V_65 = V_242 ,
} ;
const struct V_2 * V_19 ;
V_59 = F_64 ( V_77 , V_63 , V_64 , NULL , & V_14 ) ;
if ( V_59 < 0 )
return 0 ;
V_19 = F_4 ( V_14 . V_14 ) ;
if ( ! V_19 ) {
F_25 ( F_17 ( V_77 ) ,
L_25 , V_242 , V_14 . V_14 ) ;
return 0 ;
}
V_59 = F_96 ( V_77 , V_19 -> V_6 ) ;
if ( V_59 < 0 )
return 0 ;
switch ( V_14 . V_14 ) {
case V_244 :
V_243 ++ ;
if ( V_56 ) {
V_56 -> V_51 = & V_245 [ 0 ] ;
V_56 -> V_14 = V_14 . V_14 ;
V_56 ++ ;
F_26 ( F_17 ( V_77 ) ,
L_26 ,
V_245 [ 0 ] . V_246 , V_14 . V_14 ) ;
}
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
if ( V_56 )
F_26 ( F_17 ( V_77 ) ,
L_27 ,
V_19 -> V_246 ) ;
break;
default:
if ( ! F_97 ( V_19 ) )
return 0 ;
if ( V_56 )
F_26 ( F_17 ( V_77 ) ,
L_28 ,
V_19 -> V_246 ) ;
break;
}
V_243 ++ ;
if ( V_56 ) {
V_56 -> V_51 = V_19 ;
V_56 -> V_14 = V_14 . V_14 ;
V_56 ++ ;
}
return V_243 ;
}
static int F_99 ( struct V_76 * V_77 )
{
struct V_48 * V_56 ;
V_56 = F_8 ( & V_77 -> V_53 , V_77 -> V_183 ,
F_98 ) ;
if ( F_100 ( V_56 ) )
return F_101 ( V_56 ) ;
V_77 -> V_49 = V_56 ;
return 0 ;
}
static void F_102 ( struct V_76 * V_77 )
{
F_13 ( V_77 -> V_49 ) ;
}
static int F_103 ( T_2 V_1 , T_2 V_13 )
{
return V_13 < 32 || V_13 > 2048 || V_1 < 48 || V_1 > 2048 ||
( V_1 & 0x01 ) ;
}
static int F_104 ( struct V_252 * V_252 , void * V_253 ,
struct V_254 * V_255 )
{
struct V_76 * V_77 = F_105 ( V_252 ) ;
if ( V_255 -> V_255 > V_256 )
return - V_257 ;
V_255 -> V_258 = F_36 ( V_77 -> V_104 + V_255 -> V_255 ) ;
V_255 -> V_209 = sizeof( T_5 ) ;
return 0 ;
}
static int F_106 ( struct V_252 * V_252 , void * V_253 ,
const struct V_254 * V_255 )
{
struct V_76 * V_77 = F_105 ( V_252 ) ;
if ( V_255 -> V_255 > V_256 )
return - V_257 ;
if ( V_255 -> V_209 != sizeof( T_5 ) )
return - V_11 ;
F_35 ( V_255 -> V_258 , V_77 -> V_104 + V_255 -> V_255 ) ;
return 0 ;
}
static int F_107 ( struct V_252 * V_259 , void * V_253 ,
struct V_260 * V_261 )
{
struct V_76 * V_77 = F_105 ( V_259 ) ;
const struct V_2 * V_262 ;
unsigned int V_242 ;
for ( V_242 = 0 ; V_77 -> V_49 [ V_242 ] . V_14 ; V_242 ++ ) ;
if ( V_261 -> V_65 >= V_242 )
return - V_11 ;
V_262 = V_77 -> V_49 [ V_261 -> V_65 ] . V_51 ;
V_261 -> V_263 = V_262 -> V_50 ;
return 0 ;
}
static int F_108 ( struct V_252 * V_259 , void * V_253 ,
struct V_264 * V_261 )
{
struct V_76 * V_77 = F_105 ( V_259 ) ;
struct V_265 * V_266 = & V_261 -> V_19 . V_266 ;
V_266 -> V_1 = V_77 -> V_186 . V_1 ;
V_266 -> V_13 = V_77 -> V_186 . V_13 ;
V_266 -> V_267 = V_77 -> V_186 . V_267 ;
V_266 -> V_213 = V_77 -> V_186 . V_213 ;
V_266 -> V_117 = V_77 -> V_186 . V_117 ;
V_266 -> V_263 = V_77 -> V_185 -> V_51 -> V_50 ;
V_266 -> V_268 = V_77 -> V_186 . V_268 ;
F_26 ( F_17 ( V_77 ) , L_29 ,
V_77 -> V_185 -> V_51 -> V_50 ) ;
return 0 ;
}
static int F_109 ( struct V_252 * V_259 , void * V_253 ,
struct V_264 * V_261 )
{
struct V_76 * V_77 = F_105 ( V_259 ) ;
const struct V_48 * V_56 ;
struct V_265 * V_266 = & V_261 -> V_19 . V_266 ;
struct V_269 V_270 ;
struct V_271 V_262 = {
. V_61 = V_272 ,
} ;
struct V_273 * V_3 = & V_262 . V_262 ;
T_5 V_176 = V_266 -> V_263 ;
int V_59 ;
V_56 = F_7 ( V_77 -> V_49 , V_176 ) ;
if ( ! V_56 ) {
F_52 ( F_17 ( V_77 ) , L_30 , V_176 ) ;
return - V_11 ;
}
F_110 ( & V_266 -> V_1 , 48 , 2048 , 1 ,
& V_266 -> V_13 , 32 , 2048 , 0 ,
V_176 == V_187 ? 4 : 0 ) ;
F_111 ( V_3 , V_266 , V_56 -> V_14 ) ;
V_59 = F_64 ( V_77 , V_63 , V_274 , & V_270 , & V_262 ) ;
if ( V_59 < 0 )
return V_59 ;
F_112 ( V_266 , V_3 ) ;
switch ( V_3 -> V_117 ) {
case V_275 :
case V_118 :
V_266 -> V_117 = V_118 ;
break;
default:
F_25 ( F_17 ( V_77 ) , L_31 ,
V_3 -> V_117 ) ;
return - V_11 ;
}
V_59 = F_1 ( V_266 -> V_1 , V_56 -> V_51 ) ;
if ( V_59 < 0 )
return V_59 ;
V_266 -> V_267 = V_59 ;
V_59 = F_2 ( V_56 -> V_51 , V_266 -> V_267 ,
V_266 -> V_13 ) ;
if ( V_59 < 0 )
return V_59 ;
V_266 -> V_213 = V_59 ;
return 0 ;
}
static int F_113 ( struct V_252 * V_259 , void * V_253 ,
struct V_264 * V_261 )
{
struct V_76 * V_77 = F_105 ( V_259 ) ;
const struct V_48 * V_56 ;
struct V_265 * V_266 = & V_261 -> V_19 . V_266 ;
struct V_271 V_262 = {
. V_61 = V_62 ,
} ;
unsigned long V_23 ;
int V_59 , V_276 ;
F_26 ( F_17 ( V_77 ) ,
L_32 ,
V_266 -> V_1 , V_266 -> V_13 , V_266 -> V_263 ) ;
F_45 ( & V_77 -> V_133 , V_23 ) ;
V_276 = V_77 -> V_109 || F_114 ( & V_77 -> V_222 ) ;
F_49 ( & V_77 -> V_133 , V_23 ) ;
if ( V_276 )
return - V_277 ;
V_59 = F_109 ( V_259 , V_253 , V_261 ) ;
if ( V_59 )
return V_59 ;
V_56 = F_7 ( V_77 -> V_49 ,
V_266 -> V_263 ) ;
F_111 ( & V_262 . V_262 , V_266 , V_56 -> V_14 ) ;
V_59 = F_64 ( V_77 , V_63 , V_274 , NULL , & V_262 ) ;
if ( V_59 < 0 ) {
F_52 ( F_17 ( V_77 ) ,
L_33 ,
V_266 -> V_263 ) ;
} else if ( F_103 ( V_266 -> V_1 , V_266 -> V_13 ) ) {
F_52 ( F_17 ( V_77 ) ,
L_34 ,
V_266 -> V_1 , V_266 -> V_13 ) ;
return - V_11 ;
}
V_77 -> V_185 = V_56 ;
V_77 -> V_186 = * V_266 ;
V_59 = F_95 ( V_77 ) ;
return V_59 ;
}
static int F_115 ( struct V_252 * V_252 , void * V_253 ,
struct V_278 * V_279 )
{
F_116 ( V_279 -> V_280 , L_35 , sizeof( V_279 -> V_280 ) ) ;
F_116 ( V_279 -> V_281 , V_282 , sizeof( V_279 -> V_281 ) ) ;
F_116 ( V_279 -> V_283 , V_284 , sizeof( V_279 -> V_283 ) ) ;
V_279 -> V_285 = V_286 | V_287 ;
V_279 -> V_288 = V_279 -> V_285 | V_289 ;
return 0 ;
}
static int F_117 ( struct V_252 * V_252 , void * V_253 ,
struct V_290 * V_18 )
{
if ( V_18 -> V_65 > 0 )
return - V_11 ;
V_18 -> type = V_291 ;
F_116 ( V_18 -> V_246 , L_36 , sizeof( V_18 -> V_246 ) ) ;
return 0 ;
}
static int F_118 ( struct V_252 * V_252 , void * V_253 , unsigned int * V_18 )
{
* V_18 = 0 ;
return 0 ;
}
static int F_119 ( struct V_252 * V_252 , void * V_253 , unsigned int V_18 )
{
if ( V_18 > 0 )
return - V_11 ;
return 0 ;
}
static int F_120 ( struct V_252 * V_259 )
{
struct V_76 * V_77 = F_105 ( V_259 ) ;
int V_59 ;
F_121 ( & V_77 -> V_236 ) ;
V_59 = F_122 ( V_259 ) ;
if ( V_59 < 0 )
goto V_137;
V_59 = F_64 ( V_77 , V_292 , V_293 , 1 ) ;
if ( V_59 )
F_123 ( V_259 ) ;
V_137:
F_124 ( & V_77 -> V_236 ) ;
return V_59 ;
}
static int F_125 ( struct V_252 * V_259 )
{
struct V_76 * V_77 = F_105 ( V_259 ) ;
int V_59 ;
V_59 = F_126 ( V_259 ) ;
if ( V_59 < 0 )
return V_59 ;
F_121 ( & V_77 -> V_236 ) ;
V_59 = F_64 ( V_77 , V_292 , V_293 , 0 ) ;
F_124 ( & V_77 -> V_236 ) ;
return V_59 ;
}
static int F_127 ( struct V_294 * V_295 ,
struct V_54 * V_55 ,
struct V_296 * V_297 )
{
int V_298 ;
struct V_52 * V_53 = V_295 -> V_53 ;
struct V_76 * V_77 = F_18 ( V_53 ) ;
struct V_299 * V_300 = & V_77 -> V_300 ;
struct V_265 * V_266 = & V_77 -> V_186 ;
struct V_271 V_262 = {
. V_61 = V_62 ,
} ;
struct V_273 * V_3 = & V_262 . V_262 ;
F_128 ( F_17 ( V_77 ) , L_37 ,
V_98 ) ;
F_121 ( & V_77 -> V_236 ) ;
* V_300 = V_301 ;
V_300 -> V_53 = V_53 ;
V_300 -> V_133 = & V_77 -> V_236 ;
V_77 -> V_183 = V_55 ;
V_77 -> V_300 . V_113 = & V_77 -> V_222 ;
V_77 -> V_300 . V_53 = & V_77 -> V_53 ;
V_77 -> V_300 . V_302 = V_55 -> V_302 ;
F_129 ( & V_77 -> V_300 , V_77 ) ;
V_298 = F_99 ( V_77 ) ;
if ( V_298 ) {
F_25 ( F_17 ( V_77 ) , L_38 ,
V_298 ) ;
goto V_137;
}
V_77 -> V_185 = V_77 -> V_49 ;
V_266 -> V_117 = V_118 ;
V_266 -> V_1 = V_303 ;
V_266 -> V_13 = V_304 ;
V_266 -> V_267 =
F_1 ( V_266 -> V_1 ,
V_77 -> V_185 -> V_51 ) ;
V_266 -> V_213 =
F_2 ( V_77 -> V_185 -> V_51 ,
V_266 -> V_267 , V_266 -> V_13 ) ;
V_266 -> V_263 = V_77 -> V_185 -> V_51 -> V_50 ;
F_111 ( V_3 , V_266 , V_77 -> V_185 -> V_14 ) ;
V_298 = F_64 ( V_77 , V_63 , V_274 , NULL , & V_262 ) ;
if ( V_298 )
goto V_137;
F_112 ( V_266 , V_3 ) ;
F_130 ( L_39 ,
V_98 , V_266 -> V_268 , V_266 -> V_263 ) ;
V_298 = F_93 ( V_77 ) ;
if ( V_298 )
goto V_137;
V_298 = F_131 ( & V_77 -> V_300 , V_305 , - 1 ) ;
if ( V_298 ) {
F_132 ( V_53 , L_40 , V_298 ) ;
V_77 -> V_183 = NULL ;
} else {
F_128 ( F_17 ( V_77 ) ,
L_41 ,
V_55 -> V_246 ) ;
}
V_137:
F_124 ( & V_77 -> V_236 ) ;
return V_298 ;
}
static void F_133 ( struct V_294 * V_295 ,
struct V_54 * V_55 ,
struct V_296 * V_297 )
{
struct V_76 * V_77 = F_18 ( V_295 -> V_53 ) ;
F_121 ( & V_77 -> V_236 ) ;
F_128 ( F_17 ( V_77 ) ,
L_42 ,
V_55 -> V_246 ) ;
F_35 ( 0x3ff , V_77 -> V_104 + V_106 ) ;
F_30 ( V_77 ) ;
F_102 ( V_77 ) ;
F_134 ( & V_77 -> V_300 ) ;
V_77 -> V_183 = NULL ;
F_124 ( & V_77 -> V_236 ) ;
}
static int F_135 ( struct V_75 * V_78 )
{
struct V_76 * V_77 = F_136 ( V_78 ) ;
int V_18 = 0 , V_59 = 0 ;
V_77 -> V_306 [ V_18 ++ ] = F_36 ( V_77 -> V_104 + V_106 ) ;
V_77 -> V_306 [ V_18 ++ ] = F_36 ( V_77 -> V_104 + V_196 ) ;
V_77 -> V_306 [ V_18 ++ ] = F_36 ( V_77 -> V_104 + V_197 ) ;
V_77 -> V_306 [ V_18 ++ ] = F_36 ( V_77 -> V_104 + V_198 ) ;
V_77 -> V_306 [ V_18 ++ ] = F_36 ( V_77 -> V_104 + V_162 ) ;
if ( V_77 -> V_183 ) {
V_59 = F_64 ( V_77 , V_292 , V_293 , 0 ) ;
if ( V_59 == - V_240 )
V_59 = 0 ;
}
return V_59 ;
}
static int F_137 ( struct V_75 * V_78 )
{
struct V_76 * V_77 = F_136 ( V_78 ) ;
int V_18 = 0 , V_59 = 0 ;
F_35 ( V_77 -> V_306 [ V_18 ++ ] & ~ V_107 , V_77 -> V_104 + V_106 ) ;
F_35 ( V_77 -> V_306 [ V_18 ++ ] , V_77 -> V_104 + V_196 ) ;
F_35 ( V_77 -> V_306 [ V_18 ++ ] , V_77 -> V_104 + V_197 ) ;
F_35 ( V_77 -> V_306 [ V_18 ++ ] , V_77 -> V_104 + V_198 ) ;
F_35 ( V_77 -> V_306 [ V_18 ++ ] , V_77 -> V_104 + V_162 ) ;
if ( V_77 -> V_183 ) {
V_59 = F_64 ( V_77 , V_292 , V_293 , 1 ) ;
if ( V_59 == - V_240 )
V_59 = 0 ;
}
if ( ! V_59 && V_77 -> V_109 )
F_34 ( V_77 ) ;
return V_59 ;
}
static int F_138 ( struct V_75 * V_78 ,
struct V_76 * V_77 ,
struct V_296 * V_297 )
{
T_2 V_307 ;
struct V_308 * V_309 , * V_310 = V_78 -> V_311 ;
struct V_312 V_313 ;
int V_298 = F_139 ( V_310 , L_43 ,
& V_307 ) ;
if ( ! V_298 ) {
V_77 -> V_147 |= V_148 ;
V_77 -> V_143 = V_307 ;
}
V_310 = F_140 ( V_310 , NULL ) ;
if ( ! V_310 ) {
F_25 ( V_78 , L_44 ) ;
return - V_11 ;
}
V_298 = F_141 ( V_310 , & V_313 ) ;
if ( V_298 ) {
F_25 ( V_78 , L_45 ) ;
goto V_137;
}
switch ( V_313 . V_314 . V_315 . V_316 ) {
case 4 :
V_77 -> V_147 |= V_317 ;
break;
case 5 :
V_77 -> V_147 |= V_318 ;
break;
case 8 :
V_77 -> V_147 |= V_319 ;
break;
case 9 :
V_77 -> V_147 |= V_320 ;
break;
case 10 :
V_77 -> V_147 |= V_321 ;
break;
default:
break;
}
if ( V_313 . V_314 . V_315 . V_23 & V_42 )
V_77 -> V_147 |= V_174 ;
if ( V_313 . V_314 . V_315 . V_23 & V_33 )
V_77 -> V_147 |= V_157 ;
if ( V_313 . V_314 . V_315 . V_23 & V_35 )
V_77 -> V_147 |= V_159 ;
if ( V_313 . V_314 . V_315 . V_23 & V_38 )
V_77 -> V_147 |= V_152 | V_155 ;
if ( V_313 . V_314 . V_315 . V_23 & V_39 )
V_77 -> V_147 |= V_152 ;
V_297 -> V_322 = V_323 ;
V_309 = F_142 ( V_310 ) ;
if ( V_309 ) {
V_297 -> V_324 . V_325 . V_326 = V_309 ;
F_143 ( V_309 ) ;
} else {
F_144 ( V_78 , L_46 , F_145 ( V_310 ) ) ;
}
V_137:
F_143 ( V_310 ) ;
return V_298 ;
}
static int F_146 ( struct V_141 * V_142 )
{
struct V_76 * V_77 ;
struct V_327 * V_328 ;
void T_6 * V_104 ;
struct V_329 V_330 = {
. V_331 = 0 ,
. V_332 = 8 ,
. V_333 = V_91 ,
} ;
T_7 V_334 ;
struct V_335 V_336 ;
char V_337 [ V_338 ] ;
int V_167 ;
int V_298 = 0 , V_18 ;
V_328 = F_147 ( V_142 , V_339 , 0 ) ;
V_167 = F_148 ( V_142 , 0 ) ;
if ( ! V_328 || V_167 < 0 )
return - V_340 ;
V_77 = F_149 ( & V_142 -> V_78 , sizeof( * V_77 ) , V_67 ) ;
if ( ! V_77 ) {
F_25 ( & V_142 -> V_78 , L_47 ) ;
return - V_68 ;
}
V_77 -> V_145 = F_150 ( & V_142 -> V_78 , NULL ) ;
if ( F_100 ( V_77 -> V_145 ) )
return F_101 ( V_77 -> V_145 ) ;
V_77 -> V_328 = V_328 ;
V_77 -> V_341 = V_142 -> V_78 . V_342 ;
if ( & V_142 -> V_78 . V_311 && ! V_77 -> V_341 ) {
V_298 = F_138 ( & V_142 -> V_78 , V_77 , & V_77 -> V_297 ) ;
} else {
V_77 -> V_147 = V_77 -> V_341 -> V_23 ;
V_77 -> V_143 = V_77 -> V_341 -> V_343 * 10000 ;
V_77 -> V_297 . V_322 = V_344 ;
V_77 -> V_297 . V_324 . V_345 . V_346 =
V_77 -> V_341 -> V_347 ;
V_77 -> V_297 . V_324 . V_345 . V_348 = V_77 -> V_341 -> V_349 ;
}
if ( V_298 < 0 )
return V_298 ;
if ( ! ( V_77 -> V_147 & ( V_319 |
V_320 | V_321 ) ) ) {
F_52 ( & V_142 -> V_78 , L_48
L_49 ) ;
V_77 -> V_147 |= V_321 ;
}
if ( V_77 -> V_147 & V_319 )
V_77 -> V_175 = 1 << 7 ;
if ( V_77 -> V_147 & V_320 )
V_77 -> V_175 |= 1 << 8 ;
if ( V_77 -> V_147 & V_321 )
V_77 -> V_175 |= 1 << 9 ;
if ( ! V_77 -> V_143 ) {
F_52 ( & V_142 -> V_78 ,
L_50
L_51 ) ;
V_77 -> V_143 = 20000000 ;
}
V_77 -> V_161 = F_50 ( V_142 , V_77 ) ;
F_78 ( & V_77 -> V_120 ) ;
F_151 ( & V_77 -> V_133 ) ;
F_152 ( & V_77 -> V_236 ) ;
V_104 = F_153 ( & V_142 -> V_78 , V_328 ) ;
if ( F_100 ( V_104 ) )
return F_101 ( V_104 ) ;
V_77 -> V_167 = V_167 ;
V_77 -> V_104 = V_104 ;
F_154 ( V_334 ) ;
F_155 ( V_350 , V_334 ) ;
F_155 ( V_351 , V_334 ) ;
V_336 . V_352 = 0 ;
V_336 . V_353 = 68 ;
V_77 -> V_88 [ 0 ] =
F_156 ( V_334 , V_354 ,
& V_336 , & V_142 -> V_78 , L_52 ) ;
if ( ! V_77 -> V_88 [ 0 ] ) {
F_25 ( & V_142 -> V_78 , L_53 ) ;
return - V_340 ;
}
V_336 . V_353 = 69 ;
V_77 -> V_88 [ 1 ] =
F_156 ( V_334 , V_354 ,
& V_336 , & V_142 -> V_78 , L_54 ) ;
if ( ! V_77 -> V_88 [ 1 ] ) {
F_25 ( & V_142 -> V_78 , L_53 ) ;
V_298 = - V_340 ;
goto V_355;
}
V_336 . V_353 = 70 ;
V_77 -> V_88 [ 2 ] =
F_156 ( V_334 , V_354 ,
& V_336 , & V_142 -> V_78 , L_55 ) ;
if ( ! V_77 -> V_88 [ 2 ] ) {
F_25 ( & V_142 -> V_78 , L_56 ) ;
V_298 = - V_340 ;
goto V_356;
}
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_330 . V_357 = V_77 -> V_328 -> V_358 + V_359 + V_18 * 8 ;
V_298 = F_157 ( V_77 -> V_88 [ V_18 ] , & V_330 ) ;
if ( V_298 < 0 ) {
F_25 ( & V_142 -> V_78 , L_57 ,
V_298 ) ;
goto V_360;
}
}
V_298 = F_158 ( & V_142 -> V_78 , V_77 -> V_167 , F_60 , 0 ,
V_282 , V_77 ) ;
if ( V_298 ) {
F_25 ( & V_142 -> V_78 , L_58 ) ;
goto V_360;
}
F_159 ( & V_77 -> V_171 , F_58 , ( unsigned long ) V_77 ) ;
F_54 ( V_77 ) ;
F_160 ( & V_142 -> V_78 , V_77 ) ;
V_298 = F_161 ( & V_142 -> V_78 , & V_77 -> V_53 ) ;
if ( V_298 )
goto V_360;
V_77 -> V_361 [ 0 ] = & V_77 -> V_297 ;
V_77 -> V_295 . V_362 = V_77 -> V_361 ;
V_77 -> V_295 . V_363 = 1 ;
V_77 -> V_295 . V_364 = F_127 ;
V_77 -> V_295 . V_365 = F_133 ;
if ( ! F_162 () )
V_77 -> V_297 . V_322 = V_344 ;
V_298 = F_93 ( V_77 ) ;
if ( V_298 )
goto V_366;
if ( V_77 -> V_143 ) {
F_163 ( V_337 , sizeof( V_337 ) ,
V_77 -> V_297 . V_324 . V_345 . V_346 ,
V_77 -> V_297 . V_324 . V_345 . V_348 ) ;
V_77 -> V_367 = F_164 ( & V_368 ,
V_337 , NULL ) ;
if ( F_100 ( V_77 -> V_367 ) ) {
V_298 = F_101 ( V_77 -> V_367 ) ;
goto V_366;
}
}
V_298 = F_165 ( & V_77 -> V_53 , & V_77 -> V_295 ) ;
if ( V_298 )
goto V_369;
return 0 ;
V_369:
F_166 ( V_77 -> V_367 ) ;
V_366:
F_167 ( & V_77 -> V_53 ) ;
V_360:
F_168 ( V_77 -> V_88 [ 2 ] ) ;
V_356:
F_168 ( V_77 -> V_88 [ 1 ] ) ;
V_355:
F_168 ( V_77 -> V_88 [ 0 ] ) ;
return V_298 ;
}
static int F_169 ( struct V_141 * V_142 )
{
struct V_76 * V_77 = F_136 ( & V_142 -> V_78 ) ;
F_56 ( V_77 ) ;
F_168 ( V_77 -> V_88 [ 0 ] ) ;
F_168 ( V_77 -> V_88 [ 1 ] ) ;
F_168 ( V_77 -> V_88 [ 2 ] ) ;
F_166 ( V_77 -> V_367 ) ;
F_167 ( & V_77 -> V_53 ) ;
F_128 ( & V_142 -> V_78 , L_59 ) ;
return 0 ;
}
