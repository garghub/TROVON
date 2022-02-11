void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
}
static inline unsigned long F_3 ( struct V_1 * V_2 )
{
if ( ! F_4 ( V_2 -> V_3 ) )
return F_5 ( V_2 ) -> V_4 ;
return 0 ;
}
static inline void F_6 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_6 )
{
if ( F_4 ( V_2 -> V_3 ) )
return;
if ( V_5 )
V_2 -> V_7 . V_8 -> V_9 = 1 ;
else if ( V_6 )
V_2 -> V_7 . V_8 -> V_9 = 0 ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
T_1 V_10 ;
T_1 V_11 ;
bool V_12 ;
if ( F_4 ( V_2 -> V_3 ) )
return false ;
V_10 = V_2 -> V_7 . V_8 -> V_13 ;
V_11 = F_8 ( V_2 , 1 ) ;
if ( ! ( V_2 -> V_7 . V_8 -> V_14 & V_15 ) ) {
V_10 &= 0xffffffff ;
V_11 &= 0xffffffff ;
}
V_12 = ( V_10 == V_11 ) ;
V_12 = V_12 && ! ( V_2 -> V_7 . V_8 -> V_14 & V_16 ) ;
return V_12 ;
}
void F_9 ( struct V_1 * V_2 , int V_17 , T_2 V_18 )
{
V_2 -> V_7 . V_8 -> V_19 = F_10 ( V_2 ) ;
V_2 -> V_7 . V_8 -> V_20 = V_2 -> V_7 . V_8 -> V_14 | V_18 ;
F_11 ( V_2 , F_3 ( V_2 ) + V_17 ) ;
V_2 -> V_7 . V_21 . V_22 ( V_2 ) ;
}
static int F_12 ( unsigned int V_17 )
{
unsigned int V_23 ;
switch ( V_17 ) {
case 0x100 : V_23 = V_24 ; break;
case 0x200 : V_23 = V_25 ; break;
case 0x300 : V_23 = V_26 ; break;
case 0x380 : V_23 = V_27 ; break;
case 0x400 : V_23 = V_28 ; break;
case 0x480 : V_23 = V_29 ; break;
case 0x500 : V_23 = V_30 ; break;
case 0x501 : V_23 = V_31 ; break;
case 0x600 : V_23 = V_32 ; break;
case 0x700 : V_23 = V_33 ; break;
case 0x800 : V_23 = V_34 ; break;
case 0x900 : V_23 = V_35 ; break;
case 0xc00 : V_23 = V_36 ; break;
case 0xd00 : V_23 = V_37 ; break;
case 0xf20 : V_23 = V_38 ; break;
case 0xf40 : V_23 = V_39 ; break;
default: V_23 = V_40 ; break;
}
return V_23 ;
}
void F_13 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
unsigned long V_6 = V_2 -> V_7 . V_41 ;
F_14 ( F_12 ( V_17 ) ,
& V_2 -> V_7 . V_41 ) ;
F_6 ( V_2 , V_2 -> V_7 . V_41 ,
V_6 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_17 )
{
V_2 -> V_42 . V_43 ++ ;
F_16 ( F_12 ( V_17 ) ,
& V_2 -> V_7 . V_41 ) ;
#ifdef F_17
F_18 ( V_44 L_1 , V_17 ) ;
#endif
}
void F_19 ( struct V_1 * V_2 , T_1 V_18 )
{
F_9 ( V_2 , V_45 , V_18 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_46 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
return F_22 ( V_35 , & V_2 -> V_7 . V_41 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_46 ) ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
unsigned int V_17 = V_49 ;
if ( V_48 -> V_48 == V_50 )
V_17 = V_51 ;
F_15 ( V_2 , V_17 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_49 ) ;
F_13 ( V_2 , V_51 ) ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_52 )
{
int V_53 = 1 ;
int V_17 = 0 ;
bool V_12 = F_7 ( V_2 ) ;
switch ( V_52 ) {
case V_35 :
V_53 = ( V_2 -> V_7 . V_8 -> V_14 & V_54 ) && ! V_12 ;
V_17 = V_46 ;
break;
case V_30 :
case V_31 :
V_53 = ( V_2 -> V_7 . V_8 -> V_14 & V_54 ) && ! V_12 ;
V_17 = V_49 ;
break;
case V_24 :
V_17 = V_55 ;
break;
case V_25 :
V_17 = V_56 ;
break;
case V_26 :
V_17 = V_57 ;
break;
case V_28 :
V_17 = V_58 ;
break;
case V_27 :
V_17 = V_59 ;
break;
case V_29 :
V_17 = V_60 ;
break;
case V_32 :
V_17 = V_61 ;
break;
case V_33 :
V_17 = V_45 ;
break;
case V_39 :
V_17 = V_62 ;
break;
case V_38 :
V_17 = V_63 ;
break;
case V_34 :
V_17 = V_64 ;
break;
case V_36 :
V_17 = V_65 ;
break;
case V_37 :
V_17 = V_66 ;
break;
case V_67 :
V_17 = V_68 ;
break;
default:
V_53 = 0 ;
F_18 ( V_69 L_2 , V_52 ) ;
break;
}
#if 0
printk(KERN_INFO "Deliver interrupt 0x%x? %x\n", vec, deliver);
#endif
if ( V_53 )
F_9 ( V_2 , V_17 , 0 ) ;
return V_53 ;
}
static bool F_27 ( struct V_1 * V_2 , unsigned int V_52 )
{
switch ( V_52 ) {
case V_35 :
return false ;
case V_31 :
return false ;
}
return true ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned long * V_70 = & V_2 -> V_7 . V_41 ;
unsigned long V_6 = V_2 -> V_7 . V_41 ;
unsigned int V_52 ;
#ifdef F_17
if ( V_2 -> V_7 . V_41 )
F_18 ( V_71 L_3 , V_2 -> V_7 . V_41 ) ;
#endif
V_52 = F_29 ( * V_70 ) ;
while ( V_52 < V_40 ) {
if ( F_26 ( V_2 , V_52 ) &&
F_27 ( V_2 , V_52 ) ) {
F_14 ( V_52 , & V_2 -> V_7 . V_41 ) ;
break;
}
V_52 = F_30 ( V_70 ,
V_72 * sizeof( * V_70 ) ,
V_52 + 1 ) ;
}
F_6 ( V_2 , * V_70 , V_6 ) ;
return 0 ;
}
T_3 F_31 ( struct V_1 * V_2 , T_4 V_73 , bool V_74 ,
bool * V_75 )
{
T_1 V_76 = V_2 -> V_7 . V_77 ;
if ( ! ( V_2 -> V_7 . V_8 -> V_14 & V_15 ) )
V_76 = ( V_78 ) V_76 ;
if ( F_32 ( V_76 ) &&
F_32 ( ( ( V_73 << V_79 ) & V_80 ) ==
( ( V_76 & V_81 ) & V_80 ) ) ) {
T_1 V_82 = ( ( T_1 ) V_2 -> V_7 . V_8 ) & V_81 ;
T_3 V_83 ;
V_83 = ( T_3 ) F_33 ( ( void * ) V_82 ) >> V_79 ;
F_34 ( F_35 ( V_83 ) ) ;
if ( V_75 )
* V_75 = true ;
return V_83 ;
}
return F_36 ( V_2 -> V_3 , V_73 , V_74 , V_75 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_84 , bool V_85 ,
bool V_86 , struct V_87 * V_88 )
{
int V_89 = ( V_2 -> V_7 . V_8 -> V_14 & ( V_85 ? V_90 : V_91 ) ) ;
int V_92 ;
if ( V_89 ) {
V_92 = V_2 -> V_7 . V_21 . V_93 ( V_2 , V_84 , V_88 , V_85 , V_86 ) ;
} else {
V_88 -> V_84 = V_84 ;
V_88 -> V_94 = V_84 & V_80 ;
V_88 -> V_95 = V_96 | V_84 >> 12 ;
V_88 -> V_97 = true ;
V_88 -> V_98 = true ;
V_88 -> V_99 = true ;
V_92 = 0 ;
}
return V_92 ;
}
static T_5 F_38 ( void )
{
return V_100 ;
}
static T_5 F_39 ( struct V_1 * V_2 , struct V_87 * V_88 ,
bool V_101 )
{
T_5 V_102 ;
if ( V_101 && ! V_88 -> V_97 )
goto V_103;
if ( ! V_101 && ! V_88 -> V_98 )
goto V_103;
V_102 = F_40 ( V_2 -> V_3 , V_88 -> V_94 >> V_79 ) ;
if ( F_41 ( V_102 ) )
goto V_103;
return V_102 | ( V_88 -> V_94 & ~ V_81 ) ;
V_103:
return F_38 () ;
}
int F_42 ( struct V_1 * V_2 , T_1 * V_84 , int V_104 , void * V_105 ,
bool V_85 )
{
struct V_87 V_88 ;
V_2 -> V_42 . V_106 ++ ;
if ( F_37 ( V_2 , * V_84 , V_85 , true , & V_88 ) )
return - V_107 ;
* V_84 = V_88 . V_94 ;
if ( ! V_88 . V_98 )
return - V_108 ;
if ( F_43 ( V_2 -> V_3 , V_88 . V_94 , V_105 , V_104 ) )
return V_109 ;
return V_110 ;
}
int F_44 ( struct V_1 * V_2 , T_1 * V_84 , int V_104 , void * V_105 ,
bool V_85 )
{
struct V_87 V_88 ;
T_5 V_111 = * V_84 ;
V_2 -> V_42 . V_112 ++ ;
if ( F_37 ( V_2 , * V_84 , V_85 , false , & V_88 ) )
goto V_113;
* V_84 = V_88 . V_94 ;
V_111 = F_39 ( V_2 , & V_88 , true ) ;
if ( F_41 ( V_111 ) )
goto V_114;
if ( F_45 ( V_105 , ( void V_115 * ) V_111 , V_104 ) ) {
F_18 ( V_44 L_4 , V_111 ) ;
goto V_114;
}
return V_110 ;
V_113:
return - V_107 ;
V_114:
return V_109 ;
}
int F_46 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
}
int F_49 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
return V_2 -> V_3 -> V_7 . V_118 -> V_119 ( V_2 , V_117 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
return V_2 -> V_3 -> V_7 . V_118 -> V_120 ( V_2 , V_117 ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
int V_123 ;
V_122 -> V_124 = F_10 ( V_2 ) ;
V_122 -> V_125 = F_52 ( V_2 ) ;
V_122 -> V_126 = F_53 ( V_2 ) ;
V_122 -> V_127 = F_54 ( V_2 ) ;
V_122 -> V_128 = F_55 ( V_2 ) ;
V_122 -> V_14 = V_2 -> V_7 . V_8 -> V_14 ;
V_122 -> V_19 = V_2 -> V_7 . V_8 -> V_19 ;
V_122 -> V_20 = V_2 -> V_7 . V_8 -> V_20 ;
V_122 -> V_129 = V_2 -> V_7 . V_129 ;
V_122 -> V_130 = V_2 -> V_7 . V_8 -> V_130 ;
V_122 -> V_131 = V_2 -> V_7 . V_8 -> V_131 ;
V_122 -> V_132 = V_2 -> V_7 . V_8 -> V_132 ;
V_122 -> V_133 = V_2 -> V_7 . V_8 -> V_133 ;
V_122 -> V_134 = V_2 -> V_7 . V_8 -> V_134 ;
V_122 -> V_135 = V_2 -> V_7 . V_8 -> V_135 ;
V_122 -> V_136 = V_2 -> V_7 . V_8 -> V_136 ;
V_122 -> V_137 = V_2 -> V_7 . V_8 -> V_137 ;
for ( V_123 = 0 ; V_123 < F_56 ( V_122 -> V_138 ) ; V_123 ++ )
V_122 -> V_138 [ V_123 ] = F_8 ( V_2 , V_123 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
int V_123 ;
F_11 ( V_2 , V_122 -> V_124 ) ;
F_58 ( V_2 , V_122 -> V_125 ) ;
F_59 ( V_2 , V_122 -> V_126 ) ;
F_60 ( V_2 , V_122 -> V_127 ) ;
F_61 ( V_2 , V_122 -> V_128 ) ;
F_62 ( V_2 , V_122 -> V_14 ) ;
V_2 -> V_7 . V_8 -> V_19 = V_122 -> V_19 ;
V_2 -> V_7 . V_8 -> V_20 = V_122 -> V_20 ;
V_2 -> V_7 . V_8 -> V_130 = V_122 -> V_130 ;
V_2 -> V_7 . V_8 -> V_131 = V_122 -> V_131 ;
V_2 -> V_7 . V_8 -> V_132 = V_122 -> V_132 ;
V_2 -> V_7 . V_8 -> V_133 = V_122 -> V_133 ;
V_2 -> V_7 . V_8 -> V_134 = V_122 -> V_134 ;
V_2 -> V_7 . V_8 -> V_135 = V_122 -> V_135 ;
V_2 -> V_7 . V_8 -> V_136 = V_122 -> V_136 ;
V_2 -> V_7 . V_8 -> V_137 = V_122 -> V_137 ;
for ( V_123 = 0 ; V_123 < F_56 ( V_122 -> V_138 ) ; V_123 ++ )
F_63 ( V_2 , V_123 , V_122 -> V_138 [ V_123 ] ) ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
return - V_141 ;
}
int F_65 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
return - V_141 ;
}
int F_66 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
int V_92 ;
union V_144 V_145 ;
int V_104 ;
long int V_123 ;
V_104 = F_67 ( V_143 -> V_146 ) ;
if ( V_104 > sizeof( V_145 ) )
return - V_147 ;
V_92 = V_2 -> V_3 -> V_7 . V_118 -> V_148 ( V_2 , V_143 -> V_146 , & V_145 ) ;
if ( V_92 == - V_147 ) {
V_92 = 0 ;
switch ( V_143 -> V_146 ) {
case V_149 :
V_145 = F_68 ( V_143 -> V_146 , V_2 -> V_7 . V_8 -> V_150 ) ;
break;
case V_151 :
V_145 = F_68 ( V_143 -> V_146 , V_2 -> V_7 . V_8 -> V_152 ) ;
break;
case V_153 ... V_154 :
V_123 = V_143 -> V_146 - V_153 ;
V_145 = F_68 ( V_143 -> V_146 , V_2 -> V_7 . V_155 [ V_123 ] ) ;
break;
case V_156 :
V_145 = F_68 ( V_143 -> V_146 , V_2 -> V_7 . V_157 ) ;
break;
#ifdef F_69
case V_158 ... V_159 :
if ( ! F_70 ( V_160 ) ) {
V_92 = - V_161 ;
break;
}
V_145 . V_162 = V_2 -> V_7 . V_163 [ V_143 -> V_146 - V_158 ] ;
break;
case V_164 :
if ( ! F_70 ( V_160 ) ) {
V_92 = - V_161 ;
break;
}
V_145 = F_68 ( V_143 -> V_146 , V_2 -> V_7 . V_165 . V_166 [ 3 ] ) ;
break;
case V_167 :
V_145 = F_68 ( V_143 -> V_146 , V_2 -> V_7 . V_168 ) ;
break;
#endif
case V_169 : {
T_6 V_170 = V_171 ;
V_92 = F_71 ( ( T_6 V_115 * ) ( long ) V_143 -> V_172 ,
& V_170 , sizeof( T_6 ) ) ;
break;
}
#ifdef F_72
case V_173 :
if ( ! V_2 -> V_7 . V_174 ) {
V_92 = - V_161 ;
break;
}
V_145 = F_68 ( V_143 -> V_146 , F_73 ( V_2 ) ) ;
break;
#endif
default:
V_92 = - V_147 ;
break;
}
}
if ( V_92 )
return V_92 ;
if ( F_71 ( ( char V_115 * ) ( unsigned long ) V_143 -> V_172 , & V_145 , V_104 ) )
V_92 = - V_175 ;
return V_92 ;
}
int F_74 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
int V_92 ;
union V_144 V_145 ;
int V_104 ;
long int V_123 ;
V_104 = F_67 ( V_143 -> V_146 ) ;
if ( V_104 > sizeof( V_145 ) )
return - V_147 ;
if ( F_45 ( & V_145 , ( char V_115 * ) ( unsigned long ) V_143 -> V_172 , V_104 ) )
return - V_175 ;
V_92 = V_2 -> V_3 -> V_7 . V_118 -> V_176 ( V_2 , V_143 -> V_146 , & V_145 ) ;
if ( V_92 == - V_147 ) {
V_92 = 0 ;
switch ( V_143 -> V_146 ) {
case V_149 :
V_2 -> V_7 . V_8 -> V_150 = F_75 ( V_143 -> V_146 , V_145 ) ;
break;
case V_151 :
V_2 -> V_7 . V_8 -> V_152 = F_75 ( V_143 -> V_146 , V_145 ) ;
break;
case V_153 ... V_154 :
V_123 = V_143 -> V_146 - V_153 ;
V_2 -> V_7 . V_155 [ V_123 ] = F_75 ( V_143 -> V_146 , V_145 ) ;
break;
case V_156 :
V_2 -> V_7 . V_157 = F_75 ( V_143 -> V_146 , V_145 ) ;
break;
#ifdef F_69
case V_158 ... V_159 :
if ( ! F_70 ( V_160 ) ) {
V_92 = - V_161 ;
break;
}
V_2 -> V_7 . V_163 [ V_143 -> V_146 - V_158 ] = V_145 . V_162 ;
break;
case V_164 :
if ( ! F_70 ( V_160 ) ) {
V_92 = - V_161 ;
break;
}
V_2 -> V_7 . V_165 . V_166 [ 3 ] = F_75 ( V_143 -> V_146 , V_145 ) ;
break;
case V_167 :
if ( ! F_70 ( V_160 ) ) {
V_92 = - V_161 ;
break;
}
V_2 -> V_7 . V_168 = F_75 ( V_143 -> V_146 , V_145 ) ;
break;
#endif
#ifdef F_72
case V_173 :
if ( ! V_2 -> V_7 . V_174 ) {
V_92 = - V_161 ;
break;
}
V_92 = F_76 ( V_2 ,
F_75 ( V_143 -> V_146 , V_145 ) ) ;
break;
#endif
default:
V_92 = - V_147 ;
break;
}
}
return V_92 ;
}
void F_77 ( struct V_1 * V_2 , int V_177 )
{
V_2 -> V_3 -> V_7 . V_118 -> V_178 ( V_2 , V_177 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_7 . V_118 -> V_179 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 , T_2 V_14 )
{
V_2 -> V_3 -> V_7 . V_118 -> V_180 ( V_2 , V_14 ) ;
}
int F_79 ( struct V_181 * V_181 , struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_7 . V_118 -> V_182 ( V_181 , V_2 ) ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
return 0 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
return - V_147 ;
}
void F_82 ( unsigned long V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
F_20 ( V_2 ) ;
F_83 ( V_2 ) ;
}
struct V_1 * F_84 ( struct V_3 * V_3 , unsigned int V_146 )
{
return V_3 -> V_7 . V_118 -> V_187 ( V_3 , V_146 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_7 . V_118 -> V_188 ( V_2 ) ;
}
int F_86 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_7 . V_118 -> V_189 ( V_2 ) ;
}
int F_87 ( struct V_3 * V_3 , struct V_190 * log )
{
return V_3 -> V_7 . V_118 -> V_191 ( V_3 , log ) ;
}
void F_88 ( struct V_3 * V_3 , struct V_192 * free ,
struct V_192 * V_193 )
{
V_3 -> V_7 . V_118 -> V_194 ( free , V_193 ) ;
}
int F_89 ( struct V_3 * V_3 , struct V_192 * V_195 ,
unsigned long V_196 )
{
return V_3 -> V_7 . V_118 -> V_197 ( V_195 , V_196 ) ;
}
void F_90 ( struct V_3 * V_3 , struct V_192 * V_198 )
{
V_3 -> V_7 . V_118 -> V_199 ( V_3 , V_198 ) ;
}
int F_91 ( struct V_3 * V_3 ,
struct V_192 * V_198 ,
struct V_200 * V_201 )
{
return V_3 -> V_7 . V_118 -> V_202 ( V_3 , V_198 , V_201 ) ;
}
void F_92 ( struct V_3 * V_3 ,
struct V_200 * V_201 ,
const struct V_192 * V_203 )
{
V_3 -> V_7 . V_118 -> V_204 ( V_3 , V_201 , V_203 ) ;
}
int F_93 ( struct V_3 * V_3 , unsigned long V_111 )
{
return V_3 -> V_7 . V_118 -> V_205 ( V_3 , V_111 ) ;
}
int F_94 ( struct V_3 * V_3 , unsigned long V_206 , unsigned long V_207 )
{
return V_3 -> V_7 . V_118 -> V_208 ( V_3 , V_206 , V_207 ) ;
}
int F_95 ( struct V_3 * V_3 , unsigned long V_111 )
{
return V_3 -> V_7 . V_118 -> V_209 ( V_3 , V_111 ) ;
}
int F_96 ( struct V_3 * V_3 , unsigned long V_111 )
{
return V_3 -> V_7 . V_118 -> V_210 ( V_3 , V_111 ) ;
}
void F_97 ( struct V_3 * V_3 , unsigned long V_111 , T_7 V_88 )
{
V_3 -> V_7 . V_118 -> V_211 ( V_3 , V_111 , V_88 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_7 . V_118 -> V_212 ( V_2 ) ;
}
int F_99 ( struct V_3 * V_3 )
{
#ifdef F_100
F_101 ( & V_3 -> V_7 . V_213 ) ;
F_101 ( & V_3 -> V_7 . V_214 ) ;
#endif
return V_3 -> V_7 . V_118 -> V_215 ( V_3 ) ;
}
void F_102 ( struct V_3 * V_3 )
{
V_3 -> V_7 . V_118 -> V_216 ( V_3 ) ;
#ifdef F_100
F_103 ( V_3 ) ;
F_104 ( ! F_105 ( & V_3 -> V_7 . V_213 ) ) ;
#endif
}
int F_106 ( void )
{
return 0 ;
}
static int F_107 ( void )
{
int V_92 ;
V_92 = F_108 ( NULL , sizeof( struct V_1 ) , 0 , V_217 ) ;
if ( V_92 )
return V_92 ;
#ifdef F_109
V_92 = F_110 () ;
#endif
return V_92 ;
}
static void F_111 ( void )
{
#ifdef F_109
F_112 () ;
#endif
F_113 () ;
}
