void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 & V_5 ) {
T_1 V_6 = F_2 ( V_2 ) ;
if ( ( V_6 & V_7 ) == V_8 )
F_3 ( V_2 , V_6 & ~ V_7 ) ;
V_2 -> V_3 . V_4 &= ~ V_5 ;
}
}
static inline unsigned long F_4 ( struct V_1 * V_2 )
{
if ( ! F_5 ( V_2 -> V_9 ) )
return F_6 ( V_2 ) -> V_10 ;
return 0 ;
}
static inline void F_7 ( struct V_1 * V_2 ,
unsigned long V_11 , unsigned long V_12 )
{
if ( F_5 ( V_2 -> V_9 ) )
return;
if ( V_11 )
F_8 ( V_2 , 1 ) ;
else if ( V_12 )
F_8 ( V_2 , 0 ) ;
}
static inline bool F_9 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_1 V_14 ;
bool V_15 ;
if ( F_5 ( V_2 -> V_9 ) )
return false ;
V_13 = F_10 ( V_2 ) ;
V_14 = F_11 ( V_2 , 1 ) ;
if ( ! ( F_12 ( V_2 ) & V_16 ) ) {
V_13 &= 0xffffffff ;
V_14 &= 0xffffffff ;
}
V_15 = ( V_13 == V_14 ) ;
V_15 = V_15 && ! ( F_12 ( V_2 ) & V_17 ) ;
return V_15 ;
}
void F_13 ( struct V_1 * V_2 , int V_18 , T_2 V_19 )
{
F_1 ( V_2 ) ;
F_14 ( V_2 , F_2 ( V_2 ) ) ;
F_15 ( V_2 , F_12 ( V_2 ) | V_19 ) ;
F_3 ( V_2 , F_4 ( V_2 ) + V_18 ) ;
V_2 -> V_3 . V_20 . V_21 ( V_2 ) ;
}
static int F_16 ( unsigned int V_18 )
{
unsigned int V_22 ;
switch ( V_18 ) {
case 0x100 : V_22 = V_23 ; break;
case 0x200 : V_22 = V_24 ; break;
case 0x300 : V_22 = V_25 ; break;
case 0x380 : V_22 = V_26 ; break;
case 0x400 : V_22 = V_27 ; break;
case 0x480 : V_22 = V_28 ; break;
case 0x500 : V_22 = V_29 ; break;
case 0x501 : V_22 = V_30 ; break;
case 0x600 : V_22 = V_31 ; break;
case 0x700 : V_22 = V_32 ; break;
case 0x800 : V_22 = V_33 ; break;
case 0x900 : V_22 = V_34 ; break;
case 0xc00 : V_22 = V_35 ; break;
case 0xd00 : V_22 = V_36 ; break;
case 0xf20 : V_22 = V_37 ; break;
case 0xf40 : V_22 = V_38 ; break;
case 0xf60 : V_22 = V_39 ; break;
default: V_22 = V_40 ; break;
}
return V_22 ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
unsigned long V_12 = V_2 -> V_3 . V_41 ;
F_18 ( F_16 ( V_18 ) ,
& V_2 -> V_3 . V_41 ) ;
F_7 ( V_2 , V_2 -> V_3 . V_41 ,
V_12 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_42 . V_43 ++ ;
F_20 ( F_16 ( V_18 ) ,
& V_2 -> V_3 . V_41 ) ;
#ifdef F_21
F_22 ( V_44 L_1 , V_18 ) ;
#endif
}
void F_23 ( struct V_1 * V_2 , T_1 V_19 )
{
F_13 ( V_2 , V_45 , V_19 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_46 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
return F_26 ( V_34 , & V_2 -> V_3 . V_41 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_46 ) ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
unsigned int V_18 = V_49 ;
if ( V_48 -> V_48 == V_50 )
V_18 = V_51 ;
F_19 ( V_2 , V_18 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_49 ) ;
F_17 ( V_2 , V_51 ) ;
}
void F_30 ( struct V_1 * V_2 , T_1 V_52 ,
T_1 V_19 )
{
F_31 ( V_2 , V_52 ) ;
F_32 ( V_2 , V_19 ) ;
F_19 ( V_2 , V_53 ) ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_19 )
{
T_2 V_54 = F_12 ( V_2 ) ;
V_54 &= ~ ( V_55 | V_56 | V_57 ) ;
V_54 |= V_19 & ( V_55 | V_56 | V_57 ) ;
F_34 ( V_2 , V_54 ) ;
F_19 ( V_2 , V_58 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned int V_59 )
{
int V_60 = 1 ;
int V_18 = 0 ;
bool V_15 = F_9 ( V_2 ) ;
switch ( V_59 ) {
case V_34 :
V_60 = ( F_12 ( V_2 ) & V_61 ) && ! V_15 ;
V_18 = V_46 ;
break;
case V_29 :
case V_30 :
V_60 = ( F_12 ( V_2 ) & V_61 ) && ! V_15 ;
V_18 = V_49 ;
break;
case V_23 :
V_18 = V_62 ;
break;
case V_24 :
V_18 = V_63 ;
break;
case V_25 :
V_18 = V_53 ;
break;
case V_27 :
V_18 = V_58 ;
break;
case V_26 :
V_18 = V_64 ;
break;
case V_28 :
V_18 = V_65 ;
break;
case V_31 :
V_18 = V_66 ;
break;
case V_32 :
V_18 = V_45 ;
break;
case V_38 :
V_18 = V_67 ;
break;
case V_37 :
V_18 = V_68 ;
break;
case V_33 :
V_18 = V_69 ;
break;
case V_35 :
V_18 = V_70 ;
break;
case V_36 :
V_18 = V_71 ;
break;
case V_72 :
V_18 = V_73 ;
break;
case V_39 :
V_18 = V_74 ;
break;
default:
V_60 = 0 ;
F_22 ( V_75 L_2 , V_59 ) ;
break;
}
#if 0
printk(KERN_INFO "Deliver interrupt 0x%x? %x\n", vec, deliver);
#endif
if ( V_60 )
F_13 ( V_2 , V_18 , 0 ) ;
return V_60 ;
}
static bool F_36 ( struct V_1 * V_2 , unsigned int V_59 )
{
switch ( V_59 ) {
case V_34 :
return false ;
case V_30 :
return false ;
}
return true ;
}
int F_37 ( struct V_1 * V_2 )
{
unsigned long * V_76 = & V_2 -> V_3 . V_41 ;
unsigned long V_12 = V_2 -> V_3 . V_41 ;
unsigned int V_59 ;
#ifdef F_21
if ( V_2 -> V_3 . V_41 )
F_22 ( V_77 L_3 , V_2 -> V_3 . V_41 ) ;
#endif
V_59 = F_38 ( * V_76 ) ;
while ( V_59 < V_40 ) {
if ( F_35 ( V_2 , V_59 ) &&
F_36 ( V_2 , V_59 ) ) {
F_18 ( V_59 , & V_2 -> V_3 . V_41 ) ;
break;
}
V_59 = F_39 ( V_76 ,
V_78 * sizeof( * V_76 ) ,
V_59 + 1 ) ;
}
F_7 ( V_2 , * V_76 , V_12 ) ;
return 0 ;
}
T_3 F_40 ( struct V_1 * V_2 , T_4 V_79 , bool V_80 ,
bool * V_81 )
{
T_1 V_82 = V_2 -> V_3 . V_83 & V_84 ;
T_5 V_85 = V_79 >> V_86 ;
if ( ! ( F_12 ( V_2 ) & V_16 ) )
V_82 = ( V_87 ) V_82 ;
V_79 &= ~ 0xFFFULL ;
if ( F_41 ( V_82 ) && F_41 ( ( V_79 & V_84 ) == V_82 ) ) {
T_1 V_88 = ( ( T_1 ) V_2 -> V_3 . V_89 ) & V_90 ;
T_3 V_91 ;
V_91 = ( T_3 ) F_42 ( ( void * ) V_88 ) >> V_86 ;
F_43 ( F_44 ( V_91 ) ) ;
if ( V_81 )
* V_81 = true ;
return V_91 ;
}
return F_45 ( V_2 -> V_9 , V_85 , V_80 , V_81 ) ;
}
int F_46 ( struct V_1 * V_2 , T_1 V_92 , enum V_93 V_94 ,
enum V_95 V_96 , struct V_97 * V_98 )
{
bool V_99 = ( V_94 == V_100 ) ;
bool V_101 = ( V_96 == V_102 ) ;
int V_103 = ( F_12 ( V_2 ) & ( V_99 ? V_104 : V_105 ) ) ;
int V_106 ;
if ( V_103 ) {
V_106 = V_2 -> V_3 . V_20 . V_107 ( V_2 , V_92 , V_98 , V_99 , V_101 ) ;
} else {
V_98 -> V_92 = V_92 ;
V_98 -> V_108 = V_92 & V_84 ;
V_98 -> V_109 = V_110 | V_92 >> 12 ;
V_98 -> V_111 = true ;
V_98 -> V_112 = true ;
V_98 -> V_113 = true ;
V_106 = 0 ;
if ( ( F_12 ( V_2 ) & ( V_105 | V_104 ) ) == V_104 &&
! V_99 ) {
if ( ( V_2 -> V_3 . V_4 & V_5 ) &&
( ( V_92 & V_7 ) == V_8 ) )
V_98 -> V_108 &= ~ V_7 ;
}
}
return V_106 ;
}
int F_47 ( struct V_1 * V_2 , enum V_114 type ,
T_6 * V_115 )
{
T_1 V_6 = F_2 ( V_2 ) ;
int V_106 ;
if ( type == V_116 )
V_6 -= 4 ;
V_106 = F_48 ( V_2 , & V_6 , sizeof( T_6 ) , V_115 , false ) ;
if ( V_106 == V_117 )
return V_106 ;
else
return V_118 ;
}
int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_51 ( struct V_1 * V_2 )
{
}
int F_52 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_122 ( V_2 , V_120 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_123 ( V_2 , V_120 ) ;
}
int F_54 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 ;
V_125 -> V_6 = F_2 ( V_2 ) ;
V_125 -> V_127 = F_55 ( V_2 ) ;
V_125 -> V_128 = F_56 ( V_2 ) ;
V_125 -> V_129 = F_57 ( V_2 ) ;
V_125 -> V_130 = F_58 ( V_2 ) ;
V_125 -> V_54 = F_12 ( V_2 ) ;
V_125 -> V_131 = F_59 ( V_2 ) ;
V_125 -> V_132 = F_60 ( V_2 ) ;
V_125 -> V_133 = V_2 -> V_3 . V_133 ;
V_125 -> V_134 = F_61 ( V_2 ) ;
V_125 -> V_135 = F_62 ( V_2 ) ;
V_125 -> V_136 = F_63 ( V_2 ) ;
V_125 -> V_137 = F_64 ( V_2 ) ;
V_125 -> V_138 = F_65 ( V_2 ) ;
V_125 -> V_139 = F_66 ( V_2 ) ;
V_125 -> V_140 = F_67 ( V_2 ) ;
V_125 -> V_141 = F_68 ( V_2 ) ;
for ( V_126 = 0 ; V_126 < F_69 ( V_125 -> V_142 ) ; V_126 ++ )
V_125 -> V_142 [ V_126 ] = F_11 ( V_2 , V_126 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 ;
F_3 ( V_2 , V_125 -> V_6 ) ;
F_71 ( V_2 , V_125 -> V_127 ) ;
F_72 ( V_2 , V_125 -> V_128 ) ;
F_73 ( V_2 , V_125 -> V_129 ) ;
F_74 ( V_2 , V_125 -> V_130 ) ;
F_75 ( V_2 , V_125 -> V_54 ) ;
F_14 ( V_2 , V_125 -> V_131 ) ;
F_15 ( V_2 , V_125 -> V_132 ) ;
F_76 ( V_2 , V_125 -> V_134 ) ;
F_77 ( V_2 , V_125 -> V_135 ) ;
F_78 ( V_2 , V_125 -> V_136 ) ;
F_79 ( V_2 , V_125 -> V_137 ) ;
F_80 ( V_2 , V_125 -> V_138 ) ;
F_81 ( V_2 , V_125 -> V_139 ) ;
F_82 ( V_2 , V_125 -> V_140 ) ;
F_83 ( V_2 , V_125 -> V_141 ) ;
for ( V_126 = 0 ; V_126 < F_69 ( V_125 -> V_142 ) ; V_126 ++ )
F_84 ( V_2 , V_126 , V_125 -> V_142 [ V_126 ] ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
return - V_145 ;
}
int F_86 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
return - V_145 ;
}
int F_87 ( struct V_1 * V_2 , T_2 V_146 ,
union V_147 * V_148 )
{
int V_106 = 0 ;
long int V_126 ;
V_106 = V_2 -> V_9 -> V_3 . V_121 -> V_149 ( V_2 , V_146 , V_148 ) ;
if ( V_106 == - V_150 ) {
V_106 = 0 ;
switch ( V_146 ) {
case V_151 :
* V_148 = F_88 ( V_146 , F_89 ( V_2 ) ) ;
break;
case V_152 :
* V_148 = F_88 ( V_146 , F_90 ( V_2 ) ) ;
break;
case V_153 ... V_154 :
V_126 = V_146 - V_153 ;
* V_148 = F_88 ( V_146 , F_91 ( V_2 , V_126 ) ) ;
break;
case V_155 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_156 . V_157 ) ;
break;
#ifdef F_92
case V_158 ... V_159 :
if ( F_93 ( V_160 ) ) {
V_126 = V_146 - V_158 ;
V_148 -> V_161 [ 0 ] = V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 0 ] ;
V_148 -> V_161 [ 1 ] = V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 1 ] ;
} else {
V_106 = - V_163 ;
}
break;
#endif
case V_164 :
* V_148 = F_88 ( V_146 , V_165 ) ;
break;
#ifdef F_94
case V_166 :
if ( ! V_2 -> V_3 . V_167 ) {
V_106 = - V_163 ;
break;
}
* V_148 = F_88 ( V_146 , F_95 ( V_2 ) ) ;
break;
#endif
case V_168 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_169 ) ;
break;
case V_170 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_171 ) ;
break;
case V_172 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_173 ) ;
break;
case V_174 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_175 ) ;
break;
case V_176 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_177 ) ;
break;
case V_178 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_179 ) ;
break;
case V_180 :
* V_148 = F_88 ( V_146 , V_2 -> V_3 . V_181 ) ;
break;
default:
V_106 = - V_150 ;
break;
}
}
return V_106 ;
}
int F_96 ( struct V_1 * V_2 , T_2 V_146 ,
union V_147 * V_148 )
{
int V_106 = 0 ;
long int V_126 ;
V_106 = V_2 -> V_9 -> V_3 . V_121 -> V_182 ( V_2 , V_146 , V_148 ) ;
if ( V_106 == - V_150 ) {
V_106 = 0 ;
switch ( V_146 ) {
case V_151 :
F_31 ( V_2 , F_97 ( V_146 , * V_148 ) ) ;
break;
case V_152 :
F_32 ( V_2 , F_97 ( V_146 , * V_148 ) ) ;
break;
case V_153 ... V_154 :
V_126 = V_146 - V_153 ;
F_91 ( V_2 , V_126 ) = F_97 ( V_146 , * V_148 ) ;
break;
case V_155 :
V_2 -> V_3 . V_156 . V_157 = F_97 ( V_146 , * V_148 ) ;
break;
#ifdef F_92
case V_158 ... V_159 :
if ( F_93 ( V_160 ) ) {
V_126 = V_146 - V_158 ;
V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 0 ] = V_148 -> V_161 [ 0 ] ;
V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 1 ] = V_148 -> V_161 [ 1 ] ;
} else {
V_106 = - V_163 ;
}
break;
#endif
#ifdef F_94
case V_166 :
if ( ! V_2 -> V_3 . V_167 ) {
V_106 = - V_163 ;
break;
}
V_106 = F_98 ( V_2 ,
F_97 ( V_146 , * V_148 ) ) ;
break;
#endif
case V_168 :
V_2 -> V_3 . V_169 = F_97 ( V_146 , * V_148 ) ;
break;
case V_170 :
V_2 -> V_3 . V_171 = F_97 ( V_146 , * V_148 ) ;
break;
case V_172 :
V_2 -> V_3 . V_173 = F_97 ( V_146 , * V_148 ) ;
break;
case V_174 :
V_2 -> V_3 . V_175 = F_97 ( V_146 , * V_148 ) ;
break;
case V_176 :
V_2 -> V_3 . V_177 = F_97 ( V_146 , * V_148 ) ;
break;
case V_178 :
V_2 -> V_3 . V_179 = F_97 ( V_146 , * V_148 ) ;
break;
case V_180 :
V_2 -> V_3 . V_181 = F_97 ( V_146 , * V_148 ) ;
break;
default:
V_106 = - V_150 ;
break;
}
}
return V_106 ;
}
void F_99 ( struct V_1 * V_2 , int V_183 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_184 ( V_2 , V_183 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_185 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 , T_2 V_54 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_186 ( V_2 , V_54 ) ;
}
int F_101 ( struct V_187 * V_187 , struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_188 ( V_187 , V_2 ) ;
}
int F_102 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
return 0 ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_191 * V_192 )
{
V_2 -> V_193 = V_192 -> V_194 ;
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_105 ( V_2 ) ;
}
struct V_1 * F_106 ( struct V_9 * V_9 , unsigned int V_146 )
{
return V_9 -> V_3 . V_121 -> V_195 ( V_9 , V_146 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_196 ( V_2 ) ;
}
int F_108 ( struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_197 ( V_2 ) ;
}
int F_109 ( struct V_9 * V_9 , struct V_198 * log )
{
return V_9 -> V_3 . V_121 -> V_199 ( V_9 , log ) ;
}
void F_110 ( struct V_9 * V_9 , struct V_200 * free ,
struct V_200 * V_201 )
{
V_9 -> V_3 . V_121 -> V_202 ( free , V_201 ) ;
}
int F_111 ( struct V_9 * V_9 , struct V_200 * V_203 ,
unsigned long V_204 )
{
return V_9 -> V_3 . V_121 -> V_205 ( V_203 , V_204 ) ;
}
void F_112 ( struct V_9 * V_9 , struct V_200 * V_206 )
{
V_9 -> V_3 . V_121 -> V_207 ( V_9 , V_206 ) ;
}
int F_113 ( struct V_9 * V_9 ,
struct V_200 * V_206 ,
const struct V_208 * V_209 )
{
return V_9 -> V_3 . V_121 -> V_210 ( V_9 , V_206 , V_209 ) ;
}
void F_114 ( struct V_9 * V_9 ,
const struct V_208 * V_209 ,
const struct V_200 * V_211 ,
const struct V_200 * V_212 )
{
V_9 -> V_3 . V_121 -> V_213 ( V_9 , V_209 , V_211 , V_212 ) ;
}
int F_115 ( struct V_9 * V_9 , unsigned long V_214 )
{
return V_9 -> V_3 . V_121 -> V_215 ( V_9 , V_214 ) ;
}
int F_116 ( struct V_9 * V_9 , unsigned long V_216 , unsigned long V_217 )
{
return V_9 -> V_3 . V_121 -> V_218 ( V_9 , V_216 , V_217 ) ;
}
int F_117 ( struct V_9 * V_9 , unsigned long V_216 , unsigned long V_217 )
{
return V_9 -> V_3 . V_121 -> V_219 ( V_9 , V_216 , V_217 ) ;
}
int F_118 ( struct V_9 * V_9 , unsigned long V_214 )
{
return V_9 -> V_3 . V_121 -> V_220 ( V_9 , V_214 ) ;
}
void F_119 ( struct V_9 * V_9 , unsigned long V_214 , T_7 V_98 )
{
V_9 -> V_3 . V_121 -> V_221 ( V_9 , V_214 , V_98 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_222 ( V_2 ) ;
}
int F_121 ( struct V_9 * V_9 )
{
#ifdef F_122
F_123 ( & V_9 -> V_3 . V_223 ) ;
F_124 ( & V_9 -> V_3 . V_224 ) ;
#endif
return V_9 -> V_3 . V_121 -> V_225 ( V_9 ) ;
}
void F_125 ( struct V_9 * V_9 )
{
V_9 -> V_3 . V_121 -> V_226 ( V_9 ) ;
#ifdef F_122
F_126 ( V_9 ) ;
F_127 ( ! F_128 ( & V_9 -> V_3 . V_223 ) ) ;
#endif
}
int F_129 ( struct V_1 * V_2 )
{
unsigned long V_227 = F_11 ( V_2 , 4 ) ;
unsigned long V_228 = F_11 ( V_2 , 5 ) ;
T_2 V_229 ;
int V_230 ;
int V_231 ;
if ( ! F_130 ( V_227 ) || ( V_227 > sizeof( V_229 ) ) )
return V_232 ;
V_230 = F_131 ( & V_2 -> V_9 -> V_233 ) ;
V_231 = F_132 ( V_2 , V_234 , V_228 , V_227 , & V_229 ) ;
F_133 ( & V_2 -> V_9 -> V_233 , V_230 ) ;
if ( V_231 != 0 )
return V_232 ;
switch ( V_227 ) {
case 1 :
F_84 ( V_2 , 4 , * ( V_235 * ) & V_229 ) ;
break;
case 2 :
F_84 ( V_2 , 4 , F_134 ( * ( V_236 * ) & V_229 ) ) ;
break;
case 4 :
F_84 ( V_2 , 4 , F_135 ( * ( V_237 * ) & V_229 ) ) ;
break;
case 8 :
F_84 ( V_2 , 4 , F_136 ( * ( V_238 * ) & V_229 ) ) ;
break;
default:
F_137 () ;
}
return V_239 ;
}
int F_138 ( struct V_1 * V_2 )
{
unsigned long V_227 = F_11 ( V_2 , 4 ) ;
unsigned long V_228 = F_11 ( V_2 , 5 ) ;
unsigned long V_148 = F_11 ( V_2 , 6 ) ;
T_2 V_229 ;
int V_230 ;
int V_231 ;
switch ( V_227 ) {
case 1 :
* ( V_235 * ) & V_229 = V_148 ;
break;
case 2 :
* ( V_236 * ) & V_229 = F_139 ( V_148 ) ;
break;
case 4 :
* ( V_237 * ) & V_229 = F_140 ( V_148 ) ;
break;
case 8 :
* ( V_238 * ) & V_229 = F_141 ( V_148 ) ;
break;
default:
return V_232 ;
}
V_230 = F_131 ( & V_2 -> V_9 -> V_233 ) ;
V_231 = F_142 ( V_2 , V_234 , V_228 , V_227 , & V_229 ) ;
F_133 ( & V_2 -> V_9 -> V_233 , V_230 ) ;
if ( V_231 != 0 )
return V_232 ;
return V_239 ;
}
int F_143 ( void )
{
return 0 ;
}
int F_144 ( struct V_9 * V_9 , unsigned long V_240 )
{
return V_9 -> V_3 . V_121 -> V_241 ( V_240 ) ;
}
static int F_145 ( void )
{
int V_106 ;
V_106 = F_146 ( NULL , sizeof( struct V_1 ) , 0 , V_242 ) ;
if ( V_106 )
return V_106 ;
#ifdef F_147
V_106 = F_148 () ;
#endif
return V_106 ;
}
static void F_149 ( void )
{
#ifdef F_147
F_150 () ;
#endif
F_151 () ;
}
