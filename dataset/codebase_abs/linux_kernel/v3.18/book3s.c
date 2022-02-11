void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 & V_5 ) {
T_1 V_6 = F_4 ( V_2 ) ;
if ( ( V_6 & V_7 ) == V_8 )
F_5 ( V_2 , V_6 & ~ V_7 ) ;
V_2 -> V_3 . V_4 &= ~ V_5 ;
}
}
static inline unsigned long F_6 ( struct V_1 * V_2 )
{
if ( ! F_7 ( V_2 -> V_9 ) )
return F_8 ( V_2 ) -> V_10 ;
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 ,
unsigned long V_11 , unsigned long V_12 )
{
if ( F_7 ( V_2 -> V_9 ) )
return;
if ( V_11 )
F_10 ( V_2 , 1 ) ;
else if ( V_12 )
F_10 ( V_2 , 0 ) ;
}
static inline bool F_11 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_1 V_14 ;
bool V_15 ;
if ( F_7 ( V_2 -> V_9 ) )
return false ;
V_13 = F_12 ( V_2 ) ;
V_14 = F_13 ( V_2 , 1 ) ;
if ( ! ( F_14 ( V_2 ) & V_16 ) ) {
V_13 &= 0xffffffff ;
V_14 &= 0xffffffff ;
}
V_15 = ( V_13 == V_14 ) ;
V_15 = V_15 && ! ( F_14 ( V_2 ) & V_17 ) ;
return V_15 ;
}
void F_15 ( struct V_1 * V_2 , int V_18 , T_2 V_19 )
{
F_3 ( V_2 ) ;
F_16 ( V_2 , F_4 ( V_2 ) ) ;
F_17 ( V_2 , F_14 ( V_2 ) | V_19 ) ;
F_5 ( V_2 , F_6 ( V_2 ) + V_18 ) ;
V_2 -> V_3 . V_20 . V_21 ( V_2 ) ;
}
static int F_18 ( unsigned int V_18 )
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
void F_19 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
unsigned long V_12 = V_2 -> V_3 . V_41 ;
F_20 ( F_18 ( V_18 ) ,
& V_2 -> V_3 . V_41 ) ;
F_9 ( V_2 , V_2 -> V_3 . V_41 ,
V_12 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_42 . V_43 ++ ;
F_22 ( F_18 ( V_18 ) ,
& V_2 -> V_3 . V_41 ) ;
#ifdef F_23
F_24 ( V_44 L_1 , V_18 ) ;
#endif
}
void F_25 ( struct V_1 * V_2 , T_1 V_19 )
{
F_15 ( V_2 , V_45 , V_19 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_46 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_28 ( V_34 , & V_2 -> V_3 . V_41 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_46 ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
unsigned int V_18 = V_49 ;
if ( V_48 -> V_48 == V_50 )
V_18 = V_51 ;
F_21 ( V_2 , V_18 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_49 ) ;
F_19 ( V_2 , V_51 ) ;
}
void F_32 ( struct V_1 * V_2 , T_1 V_52 ,
T_1 V_19 )
{
F_33 ( V_2 , V_52 ) ;
F_34 ( V_2 , V_19 ) ;
F_21 ( V_2 , V_53 ) ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_19 )
{
T_2 V_54 = F_14 ( V_2 ) ;
V_54 &= ~ ( V_55 | V_56 | V_57 ) ;
V_54 |= V_19 & ( V_55 | V_56 | V_57 ) ;
F_36 ( V_2 , V_54 ) ;
F_21 ( V_2 , V_58 ) ;
}
int F_37 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_60 = 1 ;
int V_18 = 0 ;
bool V_15 = F_11 ( V_2 ) ;
switch ( V_59 ) {
case V_34 :
V_60 = ( F_14 ( V_2 ) & V_61 ) && ! V_15 ;
V_18 = V_46 ;
break;
case V_29 :
case V_30 :
V_60 = ( F_14 ( V_2 ) & V_61 ) && ! V_15 ;
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
F_24 ( V_75 L_2 , V_59 ) ;
break;
}
#if 0
printk(KERN_INFO "Deliver interrupt 0x%x? %x\n", vec, deliver);
#endif
if ( V_60 )
F_15 ( V_2 , V_18 , 0 ) ;
return V_60 ;
}
static bool F_38 ( struct V_1 * V_2 , unsigned int V_59 )
{
switch ( V_59 ) {
case V_34 :
return false ;
case V_30 :
return false ;
}
return true ;
}
int F_39 ( struct V_1 * V_2 )
{
unsigned long * V_76 = & V_2 -> V_3 . V_41 ;
unsigned long V_12 = V_2 -> V_3 . V_41 ;
unsigned int V_59 ;
#ifdef F_23
if ( V_2 -> V_3 . V_41 )
F_24 ( V_77 L_3 , V_2 -> V_3 . V_41 ) ;
#endif
V_59 = F_40 ( * V_76 ) ;
while ( V_59 < V_40 ) {
if ( F_37 ( V_2 , V_59 ) &&
F_38 ( V_2 , V_59 ) ) {
F_20 ( V_59 , & V_2 -> V_3 . V_41 ) ;
break;
}
V_59 = F_41 ( V_76 ,
V_78 * sizeof( * V_76 ) ,
V_59 + 1 ) ;
}
F_9 ( V_2 , * V_76 , V_12 ) ;
return 0 ;
}
T_3 F_42 ( struct V_1 * V_2 , T_4 V_79 , bool V_80 ,
bool * V_81 )
{
T_1 V_82 = V_2 -> V_3 . V_83 & V_84 ;
T_5 V_85 = V_79 >> V_86 ;
if ( ! ( F_14 ( V_2 ) & V_16 ) )
V_82 = ( V_87 ) V_82 ;
V_79 &= ~ 0xFFFULL ;
if ( F_43 ( V_82 ) && F_43 ( ( V_79 & V_84 ) == V_82 ) ) {
T_1 V_88 = ( ( T_1 ) V_2 -> V_3 . V_89 ) & V_90 ;
T_3 V_91 ;
V_91 = ( T_3 ) F_44 ( ( void * ) V_88 ) >> V_86 ;
F_45 ( F_46 ( V_91 ) ) ;
if ( V_81 )
* V_81 = true ;
return V_91 ;
}
return F_47 ( V_2 -> V_9 , V_85 , V_80 , V_81 ) ;
}
int F_48 ( struct V_1 * V_2 , T_1 V_92 , enum V_93 V_94 ,
enum V_95 V_96 , struct V_97 * V_98 )
{
bool V_99 = ( V_94 == V_100 ) ;
bool V_101 = ( V_96 == V_102 ) ;
int V_103 = ( F_14 ( V_2 ) & ( V_99 ? V_104 : V_105 ) ) ;
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
if ( ( F_14 ( V_2 ) & ( V_105 | V_104 ) ) == V_104 &&
! V_99 ) {
if ( ( V_2 -> V_3 . V_4 & V_5 ) &&
( ( V_92 & V_7 ) == V_8 ) )
V_98 -> V_108 &= ~ V_7 ;
}
}
return V_106 ;
}
int F_49 ( struct V_1 * V_2 , enum V_114 type ,
T_6 * V_115 )
{
T_1 V_6 = F_4 ( V_2 ) ;
int V_106 ;
if ( type == V_116 )
V_6 -= 4 ;
V_106 = F_50 ( V_2 , & V_6 , sizeof( T_6 ) , V_115 , false ) ;
if ( V_106 == V_117 )
return V_106 ;
else
return V_118 ;
}
int F_51 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
}
int F_54 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_122 ( V_2 , V_120 ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_123 ( V_2 , V_120 ) ;
}
int F_56 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 ;
V_125 -> V_6 = F_4 ( V_2 ) ;
V_125 -> V_127 = F_57 ( V_2 ) ;
V_125 -> V_128 = F_58 ( V_2 ) ;
V_125 -> V_129 = F_59 ( V_2 ) ;
V_125 -> V_130 = F_60 ( V_2 ) ;
V_125 -> V_54 = F_14 ( V_2 ) ;
V_125 -> V_131 = F_61 ( V_2 ) ;
V_125 -> V_132 = F_62 ( V_2 ) ;
V_125 -> V_133 = V_2 -> V_3 . V_133 ;
V_125 -> V_134 = F_63 ( V_2 ) ;
V_125 -> V_135 = F_64 ( V_2 ) ;
V_125 -> V_136 = F_65 ( V_2 ) ;
V_125 -> V_137 = F_66 ( V_2 ) ;
V_125 -> V_138 = F_67 ( V_2 ) ;
V_125 -> V_139 = F_68 ( V_2 ) ;
V_125 -> V_140 = F_69 ( V_2 ) ;
V_125 -> V_141 = F_70 ( V_2 ) ;
for ( V_126 = 0 ; V_126 < F_71 ( V_125 -> V_142 ) ; V_126 ++ )
V_125 -> V_142 [ V_126 ] = F_13 ( V_2 , V_126 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 ;
F_5 ( V_2 , V_125 -> V_6 ) ;
F_73 ( V_2 , V_125 -> V_127 ) ;
F_74 ( V_2 , V_125 -> V_128 ) ;
F_75 ( V_2 , V_125 -> V_129 ) ;
F_76 ( V_2 , V_125 -> V_130 ) ;
F_77 ( V_2 , V_125 -> V_54 ) ;
F_16 ( V_2 , V_125 -> V_131 ) ;
F_17 ( V_2 , V_125 -> V_132 ) ;
F_78 ( V_2 , V_125 -> V_134 ) ;
F_79 ( V_2 , V_125 -> V_135 ) ;
F_80 ( V_2 , V_125 -> V_136 ) ;
F_81 ( V_2 , V_125 -> V_137 ) ;
F_82 ( V_2 , V_125 -> V_138 ) ;
F_83 ( V_2 , V_125 -> V_139 ) ;
F_84 ( V_2 , V_125 -> V_140 ) ;
F_85 ( V_2 , V_125 -> V_141 ) ;
for ( V_126 = 0 ; V_126 < F_71 ( V_125 -> V_142 ) ; V_126 ++ )
F_86 ( V_2 , V_126 , V_125 -> V_142 [ V_126 ] ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
return - V_145 ;
}
int F_88 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
return - V_145 ;
}
int F_89 ( struct V_1 * V_2 , T_2 V_146 ,
union V_147 * V_148 )
{
int V_106 = 0 ;
long int V_126 ;
V_106 = V_2 -> V_9 -> V_3 . V_121 -> V_149 ( V_2 , V_146 , V_148 ) ;
if ( V_106 == - V_150 ) {
V_106 = 0 ;
switch ( V_146 ) {
case V_151 :
* V_148 = F_90 ( V_146 , F_91 ( V_2 ) ) ;
break;
case V_152 :
* V_148 = F_90 ( V_146 , F_92 ( V_2 ) ) ;
break;
case V_153 ... V_154 :
V_126 = V_146 - V_153 ;
* V_148 = F_90 ( V_146 , F_93 ( V_2 , V_126 ) ) ;
break;
case V_155 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_156 . V_157 ) ;
break;
#ifdef F_94
case V_158 ... V_159 :
if ( F_95 ( V_160 ) ) {
V_126 = V_146 - V_158 ;
V_148 -> V_161 [ 0 ] = V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 0 ] ;
V_148 -> V_161 [ 1 ] = V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 1 ] ;
} else {
V_106 = - V_163 ;
}
break;
#endif
case V_164 :
* V_148 = F_90 ( V_146 , V_165 ) ;
break;
#ifdef F_96
case V_166 :
if ( ! V_2 -> V_3 . V_167 ) {
V_106 = - V_163 ;
break;
}
* V_148 = F_90 ( V_146 , F_97 ( V_2 ) ) ;
break;
#endif
case V_168 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_169 ) ;
break;
case V_170 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_171 ) ;
break;
case V_172 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_173 ) ;
break;
case V_174 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_175 ) ;
break;
case V_176 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_177 ) ;
break;
case V_178 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_179 ) ;
break;
case V_180 :
* V_148 = F_90 ( V_146 , V_2 -> V_3 . V_181 ) ;
break;
default:
V_106 = - V_150 ;
break;
}
}
return V_106 ;
}
int F_98 ( struct V_1 * V_2 , T_2 V_146 ,
union V_147 * V_148 )
{
int V_106 = 0 ;
long int V_126 ;
V_106 = V_2 -> V_9 -> V_3 . V_121 -> V_182 ( V_2 , V_146 , V_148 ) ;
if ( V_106 == - V_150 ) {
V_106 = 0 ;
switch ( V_146 ) {
case V_151 :
F_33 ( V_2 , F_99 ( V_146 , * V_148 ) ) ;
break;
case V_152 :
F_34 ( V_2 , F_99 ( V_146 , * V_148 ) ) ;
break;
case V_153 ... V_154 :
V_126 = V_146 - V_153 ;
F_93 ( V_2 , V_126 ) = F_99 ( V_146 , * V_148 ) ;
break;
case V_155 :
V_2 -> V_3 . V_156 . V_157 = F_99 ( V_146 , * V_148 ) ;
break;
#ifdef F_94
case V_158 ... V_159 :
if ( F_95 ( V_160 ) ) {
V_126 = V_146 - V_158 ;
V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 0 ] = V_148 -> V_161 [ 0 ] ;
V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 1 ] = V_148 -> V_161 [ 1 ] ;
} else {
V_106 = - V_163 ;
}
break;
#endif
#ifdef F_96
case V_166 :
if ( ! V_2 -> V_3 . V_167 ) {
V_106 = - V_163 ;
break;
}
V_106 = F_100 ( V_2 ,
F_99 ( V_146 , * V_148 ) ) ;
break;
#endif
case V_168 :
V_2 -> V_3 . V_169 = F_99 ( V_146 , * V_148 ) ;
break;
case V_170 :
V_2 -> V_3 . V_171 = F_99 ( V_146 , * V_148 ) ;
break;
case V_172 :
V_2 -> V_3 . V_173 = F_99 ( V_146 , * V_148 ) ;
break;
case V_174 :
V_2 -> V_3 . V_175 = F_99 ( V_146 , * V_148 ) ;
break;
case V_176 :
V_2 -> V_3 . V_177 = F_99 ( V_146 , * V_148 ) ;
break;
case V_178 :
V_2 -> V_3 . V_179 = F_99 ( V_146 , * V_148 ) ;
break;
case V_180 :
V_2 -> V_3 . V_181 = F_99 ( V_146 , * V_148 ) ;
break;
default:
V_106 = - V_150 ;
break;
}
}
return V_106 ;
}
void F_101 ( struct V_1 * V_2 , int V_183 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_184 ( V_2 , V_183 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_185 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_2 , T_2 V_54 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_186 ( V_2 , V_54 ) ;
}
int F_103 ( struct V_187 * V_187 , struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_188 ( V_187 , V_2 ) ;
}
int F_104 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
return 0 ;
}
int F_105 ( struct V_1 * V_2 ,
struct V_191 * V_192 )
{
V_2 -> V_193 = V_192 -> V_194 ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_107 ( V_2 ) ;
}
struct V_1 * F_108 ( struct V_9 * V_9 , unsigned int V_146 )
{
return V_9 -> V_3 . V_121 -> V_195 ( V_9 , V_146 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_196 ( V_2 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_197 ( V_2 ) ;
}
int F_111 ( struct V_9 * V_9 , struct V_198 * log )
{
return V_9 -> V_3 . V_121 -> V_199 ( V_9 , log ) ;
}
void F_112 ( struct V_9 * V_9 , struct V_200 * free ,
struct V_200 * V_201 )
{
V_9 -> V_3 . V_121 -> V_202 ( free , V_201 ) ;
}
int F_113 ( struct V_9 * V_9 , struct V_200 * V_203 ,
unsigned long V_204 )
{
return V_9 -> V_3 . V_121 -> V_205 ( V_203 , V_204 ) ;
}
void F_114 ( struct V_9 * V_9 , struct V_200 * V_206 )
{
V_9 -> V_3 . V_121 -> V_207 ( V_9 , V_206 ) ;
}
int F_115 ( struct V_9 * V_9 ,
struct V_200 * V_206 ,
struct V_208 * V_209 )
{
return V_9 -> V_3 . V_121 -> V_210 ( V_9 , V_206 , V_209 ) ;
}
void F_116 ( struct V_9 * V_9 ,
struct V_208 * V_209 ,
const struct V_200 * V_211 )
{
V_9 -> V_3 . V_121 -> V_212 ( V_9 , V_209 , V_211 ) ;
}
int F_117 ( struct V_9 * V_9 , unsigned long V_213 )
{
return V_9 -> V_3 . V_121 -> V_214 ( V_9 , V_213 ) ;
}
int F_118 ( struct V_9 * V_9 , unsigned long V_215 , unsigned long V_216 )
{
return V_9 -> V_3 . V_121 -> V_217 ( V_9 , V_215 , V_216 ) ;
}
int F_119 ( struct V_9 * V_9 , unsigned long V_215 , unsigned long V_216 )
{
return V_9 -> V_3 . V_121 -> V_218 ( V_9 , V_215 , V_216 ) ;
}
int F_120 ( struct V_9 * V_9 , unsigned long V_213 )
{
return V_9 -> V_3 . V_121 -> V_219 ( V_9 , V_213 ) ;
}
void F_121 ( struct V_9 * V_9 , unsigned long V_213 , T_7 V_98 )
{
V_9 -> V_3 . V_121 -> V_220 ( V_9 , V_213 , V_98 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_221 ( V_2 ) ;
}
int F_123 ( struct V_9 * V_9 )
{
#ifdef F_124
F_125 ( & V_9 -> V_3 . V_222 ) ;
F_125 ( & V_9 -> V_3 . V_223 ) ;
#endif
return V_9 -> V_3 . V_121 -> V_224 ( V_9 ) ;
}
void F_126 ( struct V_9 * V_9 )
{
V_9 -> V_3 . V_121 -> V_225 ( V_9 ) ;
#ifdef F_124
F_127 ( V_9 ) ;
F_128 ( ! F_129 ( & V_9 -> V_3 . V_222 ) ) ;
#endif
}
int F_130 ( void )
{
return 0 ;
}
int F_131 ( struct V_9 * V_9 , unsigned long V_226 )
{
return V_9 -> V_3 . V_121 -> V_227 ( V_226 ) ;
}
static int F_132 ( void )
{
int V_106 ;
V_106 = F_133 ( NULL , sizeof( struct V_1 ) , 0 , V_228 ) ;
if ( V_106 )
return V_106 ;
#ifdef F_134
V_106 = F_135 () ;
#endif
return V_106 ;
}
static void F_136 ( void )
{
#ifdef F_134
F_137 () ;
#endif
F_138 () ;
}
