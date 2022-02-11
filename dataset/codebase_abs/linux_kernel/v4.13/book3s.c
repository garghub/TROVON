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
F_13 ( V_2 , V_46 , 0 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_47 , 0 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_48 , 0 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_49 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
return F_29 ( V_34 , & V_2 -> V_3 . V_41 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_49 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
unsigned int V_18 = V_52 ;
if ( V_51 -> V_51 == V_53 )
V_18 = V_54 ;
F_19 ( V_2 , V_18 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_52 ) ;
F_17 ( V_2 , V_54 ) ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_55 ,
T_1 V_19 )
{
F_34 ( V_2 , V_55 ) ;
F_35 ( V_2 , V_19 ) ;
F_19 ( V_2 , V_56 ) ;
}
void F_36 ( struct V_1 * V_2 , T_1 V_19 )
{
T_2 V_57 = F_12 ( V_2 ) ;
V_57 &= ~ ( V_58 | V_59 | V_60 ) ;
V_57 |= V_19 & ( V_58 | V_59 | V_60 ) ;
F_37 ( V_2 , V_57 ) ;
F_19 ( V_2 , V_61 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
int V_63 = 1 ;
int V_18 = 0 ;
bool V_15 = F_9 ( V_2 ) ;
switch ( V_62 ) {
case V_34 :
V_63 = ( F_12 ( V_2 ) & V_64 ) && ! V_15 ;
V_18 = V_49 ;
break;
case V_29 :
case V_30 :
V_63 = ( F_12 ( V_2 ) & V_64 ) && ! V_15 ;
V_18 = V_52 ;
break;
case V_23 :
V_18 = V_65 ;
break;
case V_24 :
V_18 = V_66 ;
break;
case V_25 :
V_18 = V_56 ;
break;
case V_27 :
V_18 = V_61 ;
break;
case V_26 :
V_18 = V_67 ;
break;
case V_28 :
V_18 = V_68 ;
break;
case V_31 :
V_18 = V_69 ;
break;
case V_32 :
V_18 = V_45 ;
break;
case V_38 :
V_18 = V_48 ;
break;
case V_37 :
V_18 = V_47 ;
break;
case V_33 :
V_18 = V_46 ;
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
V_63 = 0 ;
F_22 ( V_75 L_2 , V_62 ) ;
break;
}
#if 0
printk(KERN_INFO "Deliver interrupt 0x%x? %x\n", vec, deliver);
#endif
if ( V_63 )
F_13 ( V_2 , V_18 , 0 ) ;
return V_63 ;
}
static bool F_39 ( struct V_1 * V_2 , unsigned int V_62 )
{
switch ( V_62 ) {
case V_34 :
return false ;
case V_30 :
return false ;
}
return true ;
}
int F_40 ( struct V_1 * V_2 )
{
unsigned long * V_76 = & V_2 -> V_3 . V_41 ;
unsigned long V_12 = V_2 -> V_3 . V_41 ;
unsigned int V_62 ;
#ifdef F_21
if ( V_2 -> V_3 . V_41 )
F_22 ( V_77 L_3 , V_2 -> V_3 . V_41 ) ;
#endif
V_62 = F_41 ( * V_76 ) ;
while ( V_62 < V_40 ) {
if ( F_38 ( V_2 , V_62 ) &&
F_39 ( V_2 , V_62 ) ) {
F_18 ( V_62 , & V_2 -> V_3 . V_41 ) ;
break;
}
V_62 = F_42 ( V_76 ,
V_78 * sizeof( * V_76 ) ,
V_62 + 1 ) ;
}
F_7 ( V_2 , * V_76 , V_12 ) ;
return 0 ;
}
T_3 F_43 ( struct V_1 * V_2 , T_4 V_79 , bool V_80 ,
bool * V_81 )
{
T_1 V_82 = V_2 -> V_3 . V_83 & V_84 ;
T_5 V_85 = V_79 >> V_86 ;
if ( ! ( F_12 ( V_2 ) & V_16 ) )
V_82 = ( V_87 ) V_82 ;
V_79 &= ~ 0xFFFULL ;
if ( F_44 ( V_82 ) && F_44 ( ( V_79 & V_84 ) == V_82 ) ) {
T_1 V_88 = ( ( T_1 ) V_2 -> V_3 . V_89 ) & V_90 ;
T_3 V_91 ;
V_91 = ( T_3 ) F_45 ( ( void * ) V_88 ) >> V_86 ;
F_46 ( F_47 ( V_91 ) ) ;
if ( V_81 )
* V_81 = true ;
return V_91 ;
}
return F_48 ( V_2 -> V_9 , V_85 , V_80 , V_81 ) ;
}
int F_49 ( struct V_1 * V_2 , T_1 V_92 , enum V_93 V_94 ,
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
int F_50 ( struct V_1 * V_2 , enum V_114 type ,
T_6 * V_115 )
{
T_1 V_6 = F_2 ( V_2 ) ;
int V_106 ;
if ( type == V_116 )
V_6 -= 4 ;
V_106 = F_51 ( V_2 , & V_6 , sizeof( T_6 ) , V_115 , false ) ;
if ( V_106 == V_117 )
return V_106 ;
else
return V_118 ;
}
int F_52 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_54 ( struct V_1 * V_2 )
{
}
int F_55 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_122 ( V_2 , V_120 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_123 ( V_2 , V_120 ) ;
}
int F_57 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 ;
V_125 -> V_6 = F_2 ( V_2 ) ;
V_125 -> V_127 = F_58 ( V_2 ) ;
V_125 -> V_128 = F_59 ( V_2 ) ;
V_125 -> V_129 = F_60 ( V_2 ) ;
V_125 -> V_130 = F_61 ( V_2 ) ;
V_125 -> V_57 = F_12 ( V_2 ) ;
V_125 -> V_131 = F_62 ( V_2 ) ;
V_125 -> V_132 = F_63 ( V_2 ) ;
V_125 -> V_133 = V_2 -> V_3 . V_133 ;
V_125 -> V_134 = F_64 ( V_2 ) ;
V_125 -> V_135 = F_65 ( V_2 ) ;
V_125 -> V_136 = F_66 ( V_2 ) ;
V_125 -> V_137 = F_67 ( V_2 ) ;
V_125 -> V_138 = F_68 ( V_2 ) ;
V_125 -> V_139 = F_69 ( V_2 ) ;
V_125 -> V_140 = F_70 ( V_2 ) ;
V_125 -> V_141 = F_71 ( V_2 ) ;
for ( V_126 = 0 ; V_126 < F_72 ( V_125 -> V_142 ) ; V_126 ++ )
V_125 -> V_142 [ V_126 ] = F_11 ( V_2 , V_126 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 ;
F_3 ( V_2 , V_125 -> V_6 ) ;
F_74 ( V_2 , V_125 -> V_127 ) ;
F_75 ( V_2 , V_125 -> V_128 ) ;
F_76 ( V_2 , V_125 -> V_129 ) ;
F_77 ( V_2 , V_125 -> V_130 ) ;
F_78 ( V_2 , V_125 -> V_57 ) ;
F_14 ( V_2 , V_125 -> V_131 ) ;
F_15 ( V_2 , V_125 -> V_132 ) ;
F_79 ( V_2 , V_125 -> V_134 ) ;
F_80 ( V_2 , V_125 -> V_135 ) ;
F_81 ( V_2 , V_125 -> V_136 ) ;
F_82 ( V_2 , V_125 -> V_137 ) ;
F_83 ( V_2 , V_125 -> V_138 ) ;
F_84 ( V_2 , V_125 -> V_139 ) ;
F_85 ( V_2 , V_125 -> V_140 ) ;
F_86 ( V_2 , V_125 -> V_141 ) ;
for ( V_126 = 0 ; V_126 < F_72 ( V_125 -> V_142 ) ; V_126 ++ )
F_87 ( V_2 , V_126 , V_125 -> V_142 [ V_126 ] ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
return - V_145 ;
}
int F_89 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
return - V_145 ;
}
int F_90 ( struct V_1 * V_2 , T_2 V_146 ,
union V_147 * V_148 )
{
int V_106 = 0 ;
long int V_126 ;
V_106 = V_2 -> V_9 -> V_3 . V_121 -> V_149 ( V_2 , V_146 , V_148 ) ;
if ( V_106 == - V_150 ) {
V_106 = 0 ;
switch ( V_146 ) {
case V_151 :
* V_148 = F_91 ( V_146 , F_92 ( V_2 ) ) ;
break;
case V_152 :
* V_148 = F_91 ( V_146 , F_93 ( V_2 ) ) ;
break;
case V_153 ... V_154 :
V_126 = V_146 - V_153 ;
* V_148 = F_91 ( V_146 , F_94 ( V_2 , V_126 ) ) ;
break;
case V_155 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_156 . V_157 ) ;
break;
#ifdef F_95
case V_158 ... V_159 :
if ( F_96 ( V_160 ) ) {
V_126 = V_146 - V_158 ;
V_148 -> V_161 [ 0 ] = V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 0 ] ;
V_148 -> V_161 [ 1 ] = V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 1 ] ;
} else {
V_106 = - V_163 ;
}
break;
#endif
case V_164 :
* V_148 = F_91 ( V_146 , V_165 ) ;
break;
#ifdef F_97
case V_166 :
if ( ! V_2 -> V_3 . V_167 && ! V_2 -> V_3 . V_168 ) {
V_106 = - V_163 ;
break;
}
if ( F_98 () )
* V_148 = F_91 ( V_146 , F_99 ( V_2 ) ) ;
else
* V_148 = F_91 ( V_146 , F_100 ( V_2 ) ) ;
break;
#endif
case V_169 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_170 ) ;
break;
case V_171 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_172 ) ;
break;
case V_173 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_174 ) ;
break;
case V_175 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_176 ) ;
break;
case V_177 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_178 ) ;
break;
case V_179 :
* V_148 = F_91 ( V_146 , V_2 -> V_3 . V_180 ) ;
break;
default:
V_106 = - V_150 ;
break;
}
}
return V_106 ;
}
int F_101 ( struct V_1 * V_2 , T_2 V_146 ,
union V_147 * V_148 )
{
int V_106 = 0 ;
long int V_126 ;
V_106 = V_2 -> V_9 -> V_3 . V_121 -> V_181 ( V_2 , V_146 , V_148 ) ;
if ( V_106 == - V_150 ) {
V_106 = 0 ;
switch ( V_146 ) {
case V_151 :
F_34 ( V_2 , F_102 ( V_146 , * V_148 ) ) ;
break;
case V_152 :
F_35 ( V_2 , F_102 ( V_146 , * V_148 ) ) ;
break;
case V_153 ... V_154 :
V_126 = V_146 - V_153 ;
F_94 ( V_2 , V_126 ) = F_102 ( V_146 , * V_148 ) ;
break;
case V_155 :
V_2 -> V_3 . V_156 . V_157 = F_102 ( V_146 , * V_148 ) ;
break;
#ifdef F_95
case V_158 ... V_159 :
if ( F_96 ( V_160 ) ) {
V_126 = V_146 - V_158 ;
V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 0 ] = V_148 -> V_161 [ 0 ] ;
V_2 -> V_3 . V_156 . V_162 [ V_126 ] [ 1 ] = V_148 -> V_161 [ 1 ] ;
} else {
V_106 = - V_163 ;
}
break;
#endif
#ifdef F_97
case V_166 :
if ( ! V_2 -> V_3 . V_167 && ! V_2 -> V_3 . V_168 ) {
V_106 = - V_163 ;
break;
}
if ( F_98 () )
V_106 = F_103 ( V_2 , F_102 ( V_146 , * V_148 ) ) ;
else
V_106 = F_104 ( V_2 , F_102 ( V_146 , * V_148 ) ) ;
break;
#endif
case V_169 :
V_2 -> V_3 . V_170 = F_102 ( V_146 , * V_148 ) ;
break;
case V_171 :
V_2 -> V_3 . V_172 = F_102 ( V_146 , * V_148 ) ;
break;
case V_173 :
V_2 -> V_3 . V_174 = F_102 ( V_146 , * V_148 ) ;
break;
case V_175 :
V_2 -> V_3 . V_176 = F_102 ( V_146 , * V_148 ) ;
break;
case V_177 :
V_2 -> V_3 . V_178 = F_102 ( V_146 , * V_148 ) ;
break;
case V_179 :
V_2 -> V_3 . V_180 = F_102 ( V_146 , * V_148 ) ;
break;
default:
V_106 = - V_150 ;
break;
}
}
return V_106 ;
}
void F_105 ( struct V_1 * V_2 , int V_182 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_183 ( V_2 , V_182 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_184 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 , T_2 V_57 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_185 ( V_2 , V_57 ) ;
}
int F_107 ( struct V_186 * V_186 , struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_187 ( V_186 , V_2 ) ;
}
int F_108 ( struct V_1 * V_2 ,
struct V_188 * V_189 )
{
return 0 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
V_2 -> V_192 = V_191 -> V_193 ;
return 0 ;
}
void F_110 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_111 ( V_2 ) ;
}
struct V_1 * F_112 ( struct V_9 * V_9 , unsigned int V_146 )
{
return V_9 -> V_3 . V_121 -> V_194 ( V_9 , V_146 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_195 ( V_2 ) ;
}
int F_114 ( struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_3 . V_121 -> V_196 ( V_2 ) ;
}
int F_115 ( struct V_9 * V_9 , struct V_197 * log )
{
return V_9 -> V_3 . V_121 -> V_198 ( V_9 , log ) ;
}
void F_116 ( struct V_9 * V_9 , struct V_199 * free ,
struct V_199 * V_200 )
{
V_9 -> V_3 . V_121 -> V_201 ( free , V_200 ) ;
}
int F_117 ( struct V_9 * V_9 , struct V_199 * V_202 ,
unsigned long V_203 )
{
return V_9 -> V_3 . V_121 -> V_204 ( V_202 , V_203 ) ;
}
void F_118 ( struct V_9 * V_9 , struct V_199 * V_205 )
{
V_9 -> V_3 . V_121 -> V_206 ( V_9 , V_205 ) ;
}
int F_119 ( struct V_9 * V_9 ,
struct V_199 * V_205 ,
const struct V_207 * V_208 )
{
return V_9 -> V_3 . V_121 -> V_209 ( V_9 , V_205 , V_208 ) ;
}
void F_120 ( struct V_9 * V_9 ,
const struct V_207 * V_208 ,
const struct V_199 * V_210 ,
const struct V_199 * V_211 )
{
V_9 -> V_3 . V_121 -> V_212 ( V_9 , V_208 , V_210 , V_211 ) ;
}
int F_121 ( struct V_9 * V_9 , unsigned long V_213 )
{
return V_9 -> V_3 . V_121 -> V_214 ( V_9 , V_213 ) ;
}
int F_122 ( struct V_9 * V_9 , unsigned long V_215 , unsigned long V_216 )
{
return V_9 -> V_3 . V_121 -> V_217 ( V_9 , V_215 , V_216 ) ;
}
int F_123 ( struct V_9 * V_9 , unsigned long V_215 , unsigned long V_216 )
{
return V_9 -> V_3 . V_121 -> V_218 ( V_9 , V_215 , V_216 ) ;
}
int F_124 ( struct V_9 * V_9 , unsigned long V_213 )
{
return V_9 -> V_3 . V_121 -> V_219 ( V_9 , V_213 ) ;
}
void F_125 ( struct V_9 * V_9 , unsigned long V_213 , T_7 V_98 )
{
V_9 -> V_3 . V_121 -> V_220 ( V_9 , V_213 , V_98 ) ;
}
void F_126 ( struct V_1 * V_2 )
{
V_2 -> V_9 -> V_3 . V_121 -> V_221 ( V_2 ) ;
}
int F_127 ( struct V_9 * V_9 )
{
#ifdef F_128
F_129 ( & V_9 -> V_3 . V_222 ) ;
F_130 ( & V_9 -> V_3 . V_223 ) ;
#endif
return V_9 -> V_3 . V_121 -> V_224 ( V_9 ) ;
}
void F_131 ( struct V_9 * V_9 )
{
V_9 -> V_3 . V_121 -> V_225 ( V_9 ) ;
#ifdef F_128
F_132 ( V_9 ) ;
F_133 ( ! F_134 ( & V_9 -> V_3 . V_222 ) ) ;
#endif
}
int F_135 ( struct V_1 * V_2 )
{
unsigned long V_226 = F_11 ( V_2 , 4 ) ;
unsigned long V_227 = F_11 ( V_2 , 5 ) ;
T_2 V_228 ;
int V_229 ;
int V_230 ;
if ( ! F_136 ( V_226 ) || ( V_226 > sizeof( V_228 ) ) )
return V_231 ;
V_229 = F_137 ( & V_2 -> V_9 -> V_232 ) ;
V_230 = F_138 ( V_2 , V_233 , V_227 , V_226 , & V_228 ) ;
F_139 ( & V_2 -> V_9 -> V_232 , V_229 ) ;
if ( V_230 != 0 )
return V_231 ;
switch ( V_226 ) {
case 1 :
F_87 ( V_2 , 4 , * ( V_234 * ) & V_228 ) ;
break;
case 2 :
F_87 ( V_2 , 4 , F_140 ( * ( V_235 * ) & V_228 ) ) ;
break;
case 4 :
F_87 ( V_2 , 4 , F_141 ( * ( V_236 * ) & V_228 ) ) ;
break;
case 8 :
F_87 ( V_2 , 4 , F_142 ( * ( V_237 * ) & V_228 ) ) ;
break;
default:
F_143 () ;
}
return V_238 ;
}
int F_144 ( struct V_1 * V_2 )
{
unsigned long V_226 = F_11 ( V_2 , 4 ) ;
unsigned long V_227 = F_11 ( V_2 , 5 ) ;
unsigned long V_148 = F_11 ( V_2 , 6 ) ;
T_2 V_228 ;
int V_229 ;
int V_230 ;
switch ( V_226 ) {
case 1 :
* ( V_234 * ) & V_228 = V_148 ;
break;
case 2 :
* ( V_235 * ) & V_228 = F_145 ( V_148 ) ;
break;
case 4 :
* ( V_236 * ) & V_228 = F_146 ( V_148 ) ;
break;
case 8 :
* ( V_237 * ) & V_228 = F_147 ( V_148 ) ;
break;
default:
return V_231 ;
}
V_229 = F_137 ( & V_2 -> V_9 -> V_232 ) ;
V_230 = F_148 ( V_2 , V_233 , V_227 , V_226 , & V_228 ) ;
F_139 ( & V_2 -> V_9 -> V_232 , V_229 ) ;
if ( V_230 != 0 )
return V_231 ;
return V_238 ;
}
int F_149 ( void )
{
return 0 ;
}
int F_150 ( struct V_9 * V_9 , unsigned long V_239 )
{
return V_9 -> V_3 . V_121 -> V_240 ( V_239 ) ;
}
int F_151 ( struct V_9 * V_9 , int V_241 , T_6 V_51 , int V_242 ,
bool V_243 )
{
if ( F_98 () )
return F_152 ( V_9 , V_241 , V_51 , V_242 ,
V_243 ) ;
else
return F_153 ( V_9 , V_241 , V_51 , V_242 ,
V_243 ) ;
}
int F_154 ( struct V_244 * V_245 ,
struct V_9 * V_9 , int V_241 ,
int V_242 , bool V_243 )
{
return F_151 ( V_9 , V_241 , V_245 -> V_246 ,
V_242 , V_243 ) ;
}
static int F_155 ( struct V_244 * V_247 ,
struct V_9 * V_9 , int V_241 , int V_242 ,
bool V_243 )
{
return F_151 ( V_9 , V_241 , V_247 -> V_246 , V_242 , V_243 ) ;
}
int F_156 ( struct V_9 * V_9 ,
struct V_244 * V_248 , int V_246 )
{
V_248 -> V_246 = V_246 ;
V_248 -> type = V_249 ;
V_248 -> V_250 = F_155 ;
V_248 -> V_251 . V_251 = 0 ;
V_248 -> V_251 . V_252 = V_246 ;
return 1 ;
}
int F_157 ( struct V_9 * V_9 , unsigned V_251 , unsigned V_252 )
{
return V_252 ;
}
static int F_158 ( void )
{
int V_106 ;
V_106 = F_159 ( NULL , sizeof( struct V_1 ) , 0 , V_253 ) ;
if ( V_106 )
return V_106 ;
#ifdef F_160
V_106 = F_161 () ;
#endif
#ifdef F_97
#ifdef F_162
if ( F_98 () ) {
F_163 () ;
F_164 ( & V_254 , V_255 ) ;
} else
#endif
F_164 ( & V_256 , V_255 ) ;
#endif
return V_106 ;
}
static void F_165 ( void )
{
#ifdef F_97
if ( F_98 () )
F_166 () ;
#endif
#ifdef F_160
F_167 () ;
#endif
F_168 () ;
}
