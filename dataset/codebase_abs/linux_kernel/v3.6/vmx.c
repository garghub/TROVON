static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline short F_3 ( unsigned long V_4 )
{
if ( V_4 >= V_5 || V_6 [ V_4 ] == 0 )
return - 1 ;
return V_6 [ V_4 ] ;
}
static inline struct V_7 * F_4 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_8 . V_9 ;
}
static struct V_10 * F_5 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_10 * V_10 = F_6 ( V_3 -> V_12 , V_11 >> V_13 ) ;
if ( F_7 ( V_10 ) ) {
F_8 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
static void F_9 ( struct V_10 * V_10 )
{
F_10 ( V_10 ) ;
}
static void F_11 ( struct V_10 * V_10 )
{
F_8 ( V_10 ) ;
}
static inline bool F_12 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_19 | V_17 ) ;
}
static inline bool F_13 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_20 | V_17 ) ;
}
static inline bool F_14 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_21 | V_17 ) ;
}
static inline bool F_15 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_17 ) )
== ( V_22 | V_17 ) ;
}
static inline bool F_16 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_23 | V_17 ) ;
}
static inline bool F_17 ( void )
{
return V_24 . V_25 & V_26 ;
}
static inline bool F_18 ( void )
{
return V_24 . V_25 & V_27 ;
}
static inline bool F_19 ( struct V_12 * V_12 )
{
return ( F_18 () ) && ( F_20 ( V_12 ) ) ;
}
static inline bool F_21 ( void )
{
return V_24 . V_25 &
V_28 ;
}
static inline bool F_22 ( void )
{
return V_24 . V_29 &
V_30 ;
}
static inline bool F_23 ( void )
{
return F_18 () &&
F_22 () ;
}
static inline bool F_24 ( void )
{
return V_31 . V_32 & V_33 ;
}
static inline bool F_25 ( void )
{
return V_31 . V_32 & V_34 ;
}
static inline bool F_26 ( void )
{
return V_31 . V_32 & V_35 ;
}
static inline bool F_27 ( void )
{
return V_31 . V_32 & V_36 ;
}
static inline bool F_28 ( void )
{
return V_31 . V_32 & V_37 ;
}
static inline bool F_29 ( void )
{
return V_31 . V_32 & V_38 ;
}
static inline bool F_30 ( void )
{
return V_31 . V_32 & V_39 ;
}
static inline bool F_31 ( void )
{
return V_31 . V_32 & V_40 ;
}
static inline bool F_32 ( void )
{
return V_31 . V_32 & V_41 ;
}
static inline bool F_33 ( void )
{
return V_31 . V_32 & V_42 ;
}
static inline bool F_34 ( void )
{
return V_31 . V_43 & V_44 ;
}
static inline bool F_35 ( void )
{
return V_31 . V_43 & V_45 ;
}
static inline bool F_36 ( void )
{
return V_24 . V_29 &
V_46 ;
}
static inline bool F_37 ( void )
{
return V_24 . V_29 &
V_47 ;
}
static inline bool F_38 ( void )
{
return V_24 . V_29 &
V_48 ;
}
static inline bool F_39 ( struct V_12 * V_12 )
{
return V_49 && F_20 ( V_12 ) ;
}
static inline bool F_40 ( void )
{
return V_24 . V_29 &
V_50 ;
}
static inline bool F_41 ( void )
{
return V_24 . V_29 &
V_51 ;
}
static inline bool F_42 ( void )
{
return V_24 . V_29 &
V_52 ;
}
static inline bool F_43 ( void )
{
return V_24 . V_53 & V_54 ;
}
static inline bool F_44 ( void )
{
return V_24 . V_29 &
V_55 ;
}
static inline bool F_45 ( void )
{
return V_49 ;
}
static inline bool F_46 ( struct V_7 * V_7 , T_2 V_56 )
{
return V_7 -> V_57 & V_56 ;
}
static inline bool F_47 ( struct V_7 * V_7 , T_2 V_56 )
{
return ( V_7 -> V_57 &
V_28 ) &&
( V_7 -> V_58 & V_56 ) ;
}
static inline bool F_48 ( struct V_7 * V_7 ,
struct V_2 * V_3 )
{
return V_7 -> V_59 & V_54 ;
}
static inline bool F_49 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_17 ) )
== ( V_18 | V_17 ) ;
}
static int F_50 ( struct V_1 * V_60 , T_2 V_61 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_60 -> V_63 ; ++ V_62 )
if ( V_64 [ V_60 -> V_65 [ V_62 ] . V_66 ] == V_61 )
return V_62 ;
return - 1 ;
}
static inline void F_51 ( int V_67 , T_3 V_43 , T_4 V_68 )
{
struct {
T_5 V_43 : 16 ;
T_5 V_69 : 48 ;
T_5 V_68 ;
} V_70 = { V_43 , 0 , V_68 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_52 ( int V_67 , T_5 V_71 , T_1 V_72 )
{
struct {
T_5 V_71 , V_72 ;
} V_70 = { V_71 , V_72 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_73 * F_53 ( struct V_1 * V_60 , T_2 V_61 )
{
int V_62 ;
V_62 = F_50 ( V_60 , V_61 ) ;
if ( V_62 >= 0 )
return & V_60 -> V_65 [ V_62 ] ;
return NULL ;
}
static void F_54 ( struct V_74 * V_74 )
{
T_5 V_75 = F_55 ( V_74 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_56 ( V_76 L_1 ,
V_74 , V_75 ) ;
}
static inline void F_57 ( struct V_77 * V_77 )
{
F_54 ( V_77 -> V_74 ) ;
V_77 -> V_78 = - 1 ;
V_77 -> V_79 = 0 ;
}
static void F_58 ( struct V_74 * V_74 )
{
T_5 V_75 = F_55 ( V_74 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_56 ( V_76 L_2 ,
V_74 , V_75 ) ;
}
static void F_59 ( void * V_80 )
{
struct V_77 * V_77 = V_80 ;
int V_78 = F_60 () ;
if ( V_77 -> V_78 != V_78 )
return;
if ( F_61 ( V_81 , V_78 ) == V_77 -> V_74 )
F_61 ( V_81 , V_78 ) = NULL ;
F_62 ( & V_77 -> V_82 ) ;
F_57 ( V_77 ) ;
}
static void F_63 ( struct V_77 * V_77 )
{
if ( V_77 -> V_78 != - 1 )
F_64 (
V_77 -> V_78 , F_59 , V_77 , 1 ) ;
}
static inline void F_65 ( struct V_1 * V_60 )
{
if ( V_60 -> V_43 == 0 )
return;
if ( F_34 () )
F_51 ( V_83 , V_60 -> V_43 , 0 ) ;
}
static inline void F_66 ( void )
{
if ( F_35 () )
F_51 ( V_84 , 0 , 0 ) ;
}
static inline void F_67 ( struct V_1 * V_60 )
{
if ( F_34 () )
F_65 ( V_60 ) ;
else
F_66 () ;
}
static inline void F_68 ( void )
{
if ( F_33 () )
F_52 ( V_85 , 0 , 0 ) ;
}
static inline void F_69 ( T_5 V_71 )
{
if ( V_86 ) {
if ( F_32 () )
F_52 ( V_87 , V_71 , 0 ) ;
else
F_68 () ;
}
}
static inline void F_70 ( T_5 V_71 , T_1 V_72 )
{
if ( V_86 ) {
if ( F_31 () )
F_52 ( V_88 ,
V_71 , V_72 ) ;
else
F_69 ( V_71 ) ;
}
}
static T_7 unsigned long F_71 ( unsigned long V_4 )
{
unsigned long V_89 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_89 ;
}
static T_7 T_3 F_72 ( unsigned long V_4 )
{
return F_71 ( V_4 ) ;
}
static T_7 T_2 F_73 ( unsigned long V_4 )
{
return F_71 ( V_4 ) ;
}
static T_7 T_5 F_74 ( unsigned long V_4 )
{
#ifdef F_75
return F_71 ( V_4 ) ;
#else
return F_71 ( V_4 ) | ( ( T_5 ) F_71 ( V_4 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_76 ( unsigned long V_4 , unsigned long V_89 )
{
F_56 ( V_76 L_3 ,
V_4 , V_89 , F_73 ( V_90 ) ) ;
F_77 () ;
}
static void F_78 ( unsigned long V_4 , unsigned long V_89 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_79 ( error ) )
F_76 ( V_4 , V_89 ) ;
}
static void F_80 ( unsigned long V_4 , T_3 V_89 )
{
F_78 ( V_4 , V_89 ) ;
}
static void F_81 ( unsigned long V_4 , T_2 V_89 )
{
F_78 ( V_4 , V_89 ) ;
}
static void F_82 ( unsigned long V_4 , T_5 V_89 )
{
F_78 ( V_4 , V_89 ) ;
#ifndef F_75
asm volatile ("");
F_78 ( V_4 + 1 , V_89 >> 32 ) ;
#endif
}
static void F_83 ( unsigned long V_4 , T_2 V_91 )
{
F_78 ( V_4 , F_71 ( V_4 ) & ~ V_91 ) ;
}
static void F_84 ( unsigned long V_4 , T_2 V_91 )
{
F_78 ( V_4 , F_71 ( V_4 ) | V_91 ) ;
}
static void F_85 ( struct V_1 * V_60 )
{
V_60 -> V_92 . V_93 = 0 ;
}
static bool F_86 ( struct V_1 * V_60 , unsigned V_94 ,
unsigned V_4 )
{
bool V_95 ;
T_2 V_91 = 1 << ( V_94 * V_96 + V_4 ) ;
if ( ! ( V_60 -> V_3 . V_97 . V_98 & ( 1 << V_99 ) ) ) {
V_60 -> V_3 . V_97 . V_98 |= ( 1 << V_99 ) ;
V_60 -> V_92 . V_93 = 0 ;
}
V_95 = V_60 -> V_92 . V_93 & V_91 ;
V_60 -> V_92 . V_93 |= V_91 ;
return V_95 ;
}
static T_3 F_87 ( struct V_1 * V_60 , unsigned V_94 )
{
T_3 * V_100 = & V_60 -> V_92 . V_94 [ V_94 ] . V_101 ;
if ( ! F_86 ( V_60 , V_94 , V_102 ) )
* V_100 = F_72 ( V_103 [ V_94 ] . V_101 ) ;
return * V_100 ;
}
static T_9 F_88 ( struct V_1 * V_60 , unsigned V_94 )
{
T_9 * V_100 = & V_60 -> V_92 . V_94 [ V_94 ] . V_104 ;
if ( ! F_86 ( V_60 , V_94 , V_105 ) )
* V_100 = F_71 ( V_103 [ V_94 ] . V_104 ) ;
return * V_100 ;
}
static T_2 F_89 ( struct V_1 * V_60 , unsigned V_94 )
{
T_2 * V_100 = & V_60 -> V_92 . V_94 [ V_94 ] . V_106 ;
if ( ! F_86 ( V_60 , V_94 , V_107 ) )
* V_100 = F_73 ( V_103 [ V_94 ] . V_106 ) ;
return * V_100 ;
}
static T_2 F_90 ( struct V_1 * V_60 , unsigned V_94 )
{
T_2 * V_100 = & V_60 -> V_92 . V_94 [ V_94 ] . V_108 ;
if ( ! F_86 ( V_60 , V_94 , V_109 ) )
* V_100 = F_73 ( V_103 [ V_94 ] . V_110 ) ;
return * V_100 ;
}
static void F_91 ( struct V_2 * V_3 )
{
T_2 V_111 ;
V_111 = ( 1u << V_19 ) | ( 1u << V_21 ) | ( 1u << V_23 ) |
( 1u << V_20 ) | ( 1u << V_112 ) ;
if ( ( V_3 -> V_113 &
( V_114 | V_115 ) ) ==
( V_114 | V_115 ) )
V_111 |= 1u << V_116 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 )
V_111 = ~ 0 ;
if ( V_86 )
V_111 &= ~ ( 1u << V_19 ) ;
if ( V_3 -> V_119 )
V_111 &= ~ ( 1u << V_20 ) ;
if ( F_92 ( V_3 ) )
V_111 |= F_4 ( V_3 ) -> V_120 ;
F_81 ( V_121 , V_111 ) ;
}
static void F_93 ( unsigned long V_122 ,
unsigned long exit )
{
F_83 ( V_123 , V_122 ) ;
F_83 ( V_124 , exit ) ;
}
static void F_94 ( struct V_1 * V_60 , unsigned V_61 )
{
unsigned V_62 ;
struct V_125 * V_126 = & V_60 -> V_125 ;
switch ( V_61 ) {
case V_127 :
if ( V_128 ) {
F_93 ( V_129 ,
V_130 ) ;
return;
}
break;
case V_131 :
if ( V_132 ) {
F_93 (
V_133 ,
V_134 ) ;
return;
}
break;
}
for ( V_62 = 0 ; V_62 < V_126 -> V_135 ; ++ V_62 )
if ( V_126 -> V_136 [ V_62 ] . V_66 == V_61 )
break;
if ( V_62 == V_126 -> V_135 )
return;
-- V_126 -> V_135 ;
V_126 -> V_136 [ V_62 ] = V_126 -> V_136 [ V_126 -> V_135 ] ;
V_126 -> V_137 [ V_62 ] = V_126 -> V_137 [ V_126 -> V_135 ] ;
F_81 ( V_138 , V_126 -> V_135 ) ;
F_81 ( V_139 , V_126 -> V_135 ) ;
}
static void F_95 ( unsigned long V_122 ,
unsigned long exit , unsigned long V_140 ,
unsigned long V_141 , T_5 V_142 , T_5 V_143 )
{
F_82 ( V_140 , V_142 ) ;
F_82 ( V_141 , V_143 ) ;
F_84 ( V_123 , V_122 ) ;
F_84 ( V_124 , exit ) ;
}
static void F_96 ( struct V_1 * V_60 , unsigned V_61 ,
T_5 V_142 , T_5 V_143 )
{
unsigned V_62 ;
struct V_125 * V_126 = & V_60 -> V_125 ;
switch ( V_61 ) {
case V_127 :
if ( V_128 ) {
F_95 ( V_129 ,
V_130 ,
V_144 ,
V_145 ,
V_142 , V_143 ) ;
return;
}
break;
case V_131 :
if ( V_132 ) {
F_95 (
V_133 ,
V_134 ,
V_146 ,
V_147 ,
V_142 , V_143 ) ;
return;
}
break;
}
for ( V_62 = 0 ; V_62 < V_126 -> V_135 ; ++ V_62 )
if ( V_126 -> V_136 [ V_62 ] . V_66 == V_61 )
break;
if ( V_62 == V_148 ) {
F_97 ( V_149 L_4
L_5 , V_61 ) ;
return;
} else if ( V_62 == V_126 -> V_135 ) {
++ V_126 -> V_135 ;
F_81 ( V_138 , V_126 -> V_135 ) ;
F_81 ( V_139 , V_126 -> V_135 ) ;
}
V_126 -> V_136 [ V_62 ] . V_66 = V_61 ;
V_126 -> V_136 [ V_62 ] . V_89 = V_142 ;
V_126 -> V_137 [ V_62 ] . V_66 = V_61 ;
V_126 -> V_137 [ V_62 ] . V_89 = V_143 ;
}
static void F_98 ( void )
{
struct V_150 * V_151 = & F_99 ( V_152 ) ;
struct V_153 * V_154 ;
V_154 = ( void * ) V_151 -> V_155 ;
V_154 [ V_156 ] . type = 9 ;
F_100 () ;
}
static bool F_101 ( struct V_1 * V_60 , int V_157 )
{
T_5 V_158 ;
T_5 V_159 ;
V_158 = V_60 -> V_3 . V_97 . V_160 ;
V_159 = V_161 | V_162 ;
#ifdef F_75
V_159 |= V_163 | V_164 ;
if ( V_158 & V_163 )
V_159 &= ~ ( T_5 ) V_162 ;
#endif
V_158 &= ~ V_159 ;
V_158 |= V_165 & V_159 ;
V_60 -> V_65 [ V_157 ] . V_166 = V_158 ;
V_60 -> V_65 [ V_157 ] . V_91 = ~ V_159 ;
F_94 ( V_60 , V_127 ) ;
if ( V_86 && ( ( V_60 -> V_3 . V_97 . V_160 ^ V_165 ) & V_161 ) ) {
V_158 = V_60 -> V_3 . V_97 . V_160 ;
if ( ! ( V_158 & V_163 ) )
V_158 &= ~ V_164 ;
F_96 ( V_60 , V_127 , V_158 , V_165 ) ;
return false ;
}
return true ;
}
static unsigned long F_102 ( T_3 V_101 )
{
struct V_150 * V_151 = & F_99 ( V_152 ) ;
struct V_153 * V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
if ( ! ( V_101 & ~ 3 ) )
return 0 ;
V_168 = V_151 -> V_155 ;
if ( V_101 & 4 ) {
T_3 V_170 = F_103 () ;
if ( ! ( V_170 & ~ 3 ) )
return 0 ;
V_168 = F_102 ( V_170 ) ;
}
V_167 = (struct V_153 * ) ( V_168 + ( V_101 & ~ 7 ) ) ;
V_169 = F_104 ( V_167 ) ;
#ifdef F_75
if ( V_167 -> V_171 == 0 && ( V_167 -> type == 2 || V_167 -> type == 9 || V_167 -> type == 11 ) )
V_169 |= ( ( unsigned long ) ( (struct V_172 * ) V_167 ) -> V_173 ) << 32 ;
#endif
return V_169 ;
}
static inline unsigned long F_105 ( void )
{
T_3 V_174 ;
asm("str %0" : "=g"(tr));
return F_102 ( V_174 ) ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
int V_62 ;
if ( V_60 -> V_175 . V_176 )
return;
V_60 -> V_175 . V_176 = 1 ;
V_60 -> V_175 . V_177 = F_103 () ;
V_60 -> V_175 . V_178 = V_60 -> V_175 . V_177 ;
F_107 ( V_179 , V_60 -> V_175 . V_180 ) ;
if ( ! ( V_60 -> V_175 . V_180 & 7 ) ) {
F_80 ( V_181 , V_60 -> V_175 . V_180 ) ;
V_60 -> V_175 . V_182 = 0 ;
} else {
F_80 ( V_181 , 0 ) ;
V_60 -> V_175 . V_182 = 1 ;
}
F_107 ( V_183 , V_60 -> V_175 . V_184 ) ;
if ( ! ( V_60 -> V_175 . V_184 & 7 ) )
F_80 ( V_185 , V_60 -> V_175 . V_184 ) ;
else {
F_80 ( V_185 , 0 ) ;
V_60 -> V_175 . V_178 = 1 ;
}
#ifdef F_75
F_107 ( V_186 , V_60 -> V_175 . V_187 ) ;
F_107 ( V_188 , V_60 -> V_175 . V_189 ) ;
#endif
#ifdef F_75
F_78 ( V_190 , F_108 ( V_191 ) ) ;
F_78 ( V_192 , F_108 ( V_193 ) ) ;
#else
F_78 ( V_190 , F_102 ( V_60 -> V_175 . V_180 ) ) ;
F_78 ( V_192 , F_102 ( V_60 -> V_175 . V_184 ) ) ;
#endif
#ifdef F_75
F_109 ( V_194 , V_60 -> V_195 ) ;
if ( F_110 ( & V_60 -> V_3 ) )
F_111 ( V_194 , V_60 -> V_196 ) ;
#endif
for ( V_62 = 0 ; V_62 < V_60 -> V_197 ; ++ V_62 )
F_112 ( V_60 -> V_65 [ V_62 ] . V_66 ,
V_60 -> V_65 [ V_62 ] . V_166 ,
V_60 -> V_65 [ V_62 ] . V_91 ) ;
}
static void F_113 ( struct V_1 * V_60 )
{
if ( ! V_60 -> V_175 . V_176 )
return;
++ V_60 -> V_3 . V_198 . V_199 ;
V_60 -> V_175 . V_176 = 0 ;
#ifdef F_75
if ( F_110 ( & V_60 -> V_3 ) )
F_109 ( V_194 , V_60 -> V_196 ) ;
#endif
if ( V_60 -> V_175 . V_178 ) {
F_114 ( V_60 -> V_175 . V_177 ) ;
#ifdef F_75
F_115 ( V_60 -> V_175 . V_184 ) ;
#else
F_116 ( V_183 , V_60 -> V_175 . V_184 ) ;
#endif
}
if ( V_60 -> V_175 . V_182 )
F_116 ( V_179 , V_60 -> V_175 . V_180 ) ;
#ifdef F_75
if ( F_79 ( V_60 -> V_175 . V_187 | V_60 -> V_175 . V_189 ) ) {
F_116 ( V_186 , V_60 -> V_175 . V_187 ) ;
F_116 ( V_188 , V_60 -> V_175 . V_189 ) ;
}
#endif
F_98 () ;
#ifdef F_75
F_111 ( V_194 , V_60 -> V_195 ) ;
#endif
if ( F_117 () )
F_118 () ;
F_119 ( & F_99 ( V_152 ) ) ;
}
static void F_120 ( struct V_1 * V_60 )
{
F_121 () ;
F_113 ( V_60 ) ;
F_122 () ;
}
static void F_123 ( struct V_2 * V_3 , int V_78 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_5 V_75 = F_55 ( F_61 ( V_200 , V_78 ) ) ;
if ( ! V_201 )
F_124 ( V_75 ) ;
else if ( V_60 -> V_77 -> V_78 != V_78 )
F_63 ( V_60 -> V_77 ) ;
if ( F_61 ( V_81 , V_78 ) != V_60 -> V_77 -> V_74 ) {
F_61 ( V_81 , V_78 ) = V_60 -> V_77 -> V_74 ;
F_58 ( V_60 -> V_77 -> V_74 ) ;
}
if ( V_60 -> V_77 -> V_78 != V_78 ) {
struct V_150 * V_151 = & F_99 ( V_152 ) ;
unsigned long V_202 ;
F_125 ( V_203 , V_3 ) ;
F_126 () ;
F_127 ( & V_60 -> V_77 -> V_82 ,
& F_61 ( V_204 , V_78 ) ) ;
F_128 () ;
F_78 ( V_205 , F_105 () ) ;
F_78 ( V_206 , V_151 -> V_155 ) ;
F_109 ( V_207 , V_202 ) ;
F_78 ( V_208 , V_202 ) ;
V_60 -> V_77 -> V_78 = V_78 ;
}
}
static void F_129 ( struct V_2 * V_3 )
{
F_113 ( F_1 ( V_3 ) ) ;
if ( ! V_201 ) {
F_59 ( F_1 ( V_3 ) -> V_77 ) ;
V_3 -> V_78 = - 1 ;
F_130 () ;
}
}
static void F_131 ( struct V_2 * V_3 )
{
T_9 V_209 ;
if ( V_3 -> V_119 )
return;
V_3 -> V_119 = 1 ;
V_209 = F_71 ( V_210 ) ;
V_209 &= ~ ( V_211 | V_212 ) ;
V_209 |= F_132 ( V_3 , V_211 | V_212 ) ;
F_78 ( V_210 , V_209 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_213 = V_211 ;
if ( F_92 ( V_3 ) )
V_3 -> V_97 . V_213 &=
~ F_4 ( V_3 ) -> V_214 ;
F_78 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
}
static inline unsigned long F_133 ( struct V_7 * V_216 )
{
return ( V_216 -> V_217 & ~ V_216 -> V_214 ) |
( V_216 -> V_218 & V_216 -> V_214 ) ;
}
static inline unsigned long F_134 ( struct V_7 * V_216 )
{
return ( V_216 -> V_219 & ~ V_216 -> V_220 ) |
( V_216 -> V_221 & V_216 -> V_220 ) ;
}
static void F_135 ( struct V_2 * V_3 )
{
F_136 ( V_3 ) ;
F_84 ( V_210 , V_211 | V_212 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_213 = 0 ;
F_78 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
if ( F_92 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_217 = ( V_7 -> V_217 & ~ V_211 ) |
( V_3 -> V_97 . V_209 & V_211 ) ;
F_78 ( V_222 , F_133 ( V_7 ) ) ;
} else
F_78 ( V_222 , V_3 -> V_97 . V_209 ) ;
}
static unsigned long F_137 ( struct V_2 * V_3 )
{
unsigned long V_223 , V_224 ;
if ( ! F_138 ( V_225 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ) {
F_139 ( V_225 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
V_223 = F_71 ( V_226 ) ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
V_223 &= V_227 ;
V_224 = F_1 ( V_3 ) -> V_117 . V_224 ;
V_223 |= V_224 & ~ V_227 ;
}
F_1 ( V_3 ) -> V_223 = V_223 ;
}
return F_1 ( V_3 ) -> V_223 ;
}
static void F_140 ( struct V_2 * V_3 , unsigned long V_223 )
{
F_139 ( V_225 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
F_141 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
F_1 ( V_3 ) -> V_223 = V_223 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
F_1 ( V_3 ) -> V_117 . V_224 = V_223 ;
V_223 |= V_229 | V_230 ;
}
F_78 ( V_226 , V_223 ) ;
}
static T_2 F_142 ( struct V_2 * V_3 , int V_91 )
{
T_2 V_231 = F_73 ( V_232 ) ;
int V_95 = 0 ;
if ( V_231 & V_233 )
V_95 |= V_234 ;
if ( V_231 & V_235 )
V_95 |= V_236 ;
return V_95 & V_91 ;
}
static void F_143 ( struct V_2 * V_3 , int V_91 )
{
T_2 V_237 = F_73 ( V_232 ) ;
T_2 V_231 = V_237 ;
V_231 &= ~ ( V_233 | V_235 ) ;
if ( V_91 & V_236 )
V_231 |= V_235 ;
else if ( V_91 & V_234 )
V_231 |= V_233 ;
if ( ( V_231 != V_237 ) )
F_81 ( V_232 , V_231 ) ;
}
static void F_144 ( struct V_2 * V_3 )
{
unsigned long V_238 ;
V_238 = F_145 ( V_3 ) ;
V_238 += F_73 ( V_239 ) ;
F_146 ( V_3 , V_238 ) ;
F_143 ( V_3 , 0 ) ;
}
static int F_147 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( ! ( V_7 -> V_120 & ( 1u << V_19 ) ) )
return 0 ;
F_148 ( V_3 ) ;
return 1 ;
}
static void F_149 ( struct V_2 * V_3 , unsigned V_135 ,
bool V_240 , T_2 V_241 ,
bool V_242 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_14 = V_135 | V_17 ;
if ( V_135 == V_19 && F_92 ( V_3 ) &&
F_147 ( V_3 ) )
return;
if ( V_240 ) {
F_81 ( V_243 , V_241 ) ;
V_14 |= V_244 ;
}
if ( V_60 -> V_117 . V_118 ) {
int V_245 = 0 ;
if ( F_150 ( V_135 ) )
V_245 = V_3 -> V_97 . V_246 ;
if ( F_151 ( V_3 , V_135 , V_245 ) != V_247 )
F_125 ( V_248 , V_3 ) ;
return;
}
if ( F_150 ( V_135 ) ) {
F_81 ( V_249 ,
V_60 -> V_3 . V_97 . V_246 ) ;
V_14 |= V_250 ;
} else
V_14 |= V_18 ;
F_81 ( V_251 , V_14 ) ;
}
static bool F_152 ( void )
{
return F_41 () ;
}
static bool F_153 ( void )
{
return F_42 () && V_86 ;
}
static void F_154 ( struct V_1 * V_60 , int V_252 , int V_253 )
{
struct V_73 V_254 ;
V_254 = V_60 -> V_65 [ V_253 ] ;
V_60 -> V_65 [ V_253 ] = V_60 -> V_65 [ V_252 ] ;
V_60 -> V_65 [ V_252 ] = V_254 ;
}
static void F_155 ( struct V_1 * V_60 )
{
int V_197 , V_66 ;
unsigned long * V_255 ;
V_197 = 0 ;
#ifdef F_75
if ( F_110 ( & V_60 -> V_3 ) ) {
V_66 = F_50 ( V_60 , V_256 ) ;
if ( V_66 >= 0 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_257 ) ;
if ( V_66 >= 0 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_258 ) ;
if ( V_66 >= 0 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_259 ) ;
if ( V_66 >= 0 && V_60 -> V_260 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_261 ) ;
if ( ( V_66 >= 0 ) && ( V_60 -> V_3 . V_97 . V_160 & V_162 ) )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
}
#endif
V_66 = F_50 ( V_60 , V_127 ) ;
if ( V_66 >= 0 && F_101 ( V_60 , V_66 ) )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_60 -> V_197 = V_197 ;
if ( F_17 () ) {
if ( F_110 ( & V_60 -> V_3 ) )
V_255 = V_262 ;
else
V_255 = V_263 ;
F_82 ( V_264 , F_55 ( V_255 ) ) ;
}
}
static T_5 F_156 ( void )
{
T_5 V_265 , V_266 ;
F_157 ( V_265 ) ;
V_266 = F_74 ( V_267 ) ;
return V_265 + V_266 ;
}
T_5 F_158 ( struct V_2 * V_3 )
{
T_5 V_265 , V_266 ;
F_157 ( V_265 ) ;
V_266 = F_92 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_268 :
F_74 ( V_267 ) ;
return V_265 + V_266 ;
}
static void F_159 ( struct V_2 * V_3 , T_2 V_269 , bool V_270 )
{
if ( ! V_270 )
return;
if ( V_269 > V_271 ) {
V_3 -> V_97 . V_272 = 1 ;
V_3 -> V_97 . V_273 = 1 ;
} else
F_160 ( 1 , L_6 ) ;
}
static void F_161 ( struct V_2 * V_3 , T_5 V_274 )
{
if ( F_92 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_268 = V_274 ;
V_7 = F_4 ( V_3 ) ;
F_82 ( V_267 , V_274 +
( F_46 ( V_7 , V_275 ) ?
V_7 -> V_266 : 0 ) ) ;
} else {
F_82 ( V_267 , V_274 ) ;
}
}
static void F_162 ( struct V_2 * V_3 , T_10 V_276 , bool V_137 )
{
T_5 V_274 = F_74 ( V_267 ) ;
F_82 ( V_267 , V_274 + V_276 ) ;
if ( F_92 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_268 += V_276 ;
}
}
static T_5 F_163 ( struct V_2 * V_3 , T_5 V_277 )
{
return V_277 - F_164 () ;
}
static bool F_165 ( struct V_2 * V_3 )
{
struct V_278 * V_279 = F_166 ( V_3 , 1 , 0 ) ;
return V_279 && ( V_279 -> V_280 & ( 1 << ( V_281 & 31 ) ) ) ;
}
static inline bool F_167 ( struct V_2 * V_3 )
{
return V_8 && F_165 ( V_3 ) ;
}
static T_11 void F_168 ( void )
{
V_282 = 0x16 ;
V_283 = 0x16 |
V_284 | V_285 |
V_54 ;
V_286 = 0 ;
#ifdef F_75
V_287 = V_288 ;
#else
V_287 = 0 ;
#endif
F_169 ( V_289 ,
V_290 , V_291 ) ;
V_290 = 0 ;
V_291 &=
V_292 | V_293 ;
F_169 ( V_294 ,
V_295 , V_296 ) ;
V_295 = 0 ;
V_296 &=
V_297 | V_275 |
V_298 | V_299 |
V_300 | V_301 |
V_302 |
#ifdef F_75
V_303 | V_304 |
#endif
V_305 | V_306 |
V_307 | V_308 |
V_309 |
V_28 ;
V_296 |= V_26 ;
F_169 ( V_310 ,
V_311 , V_312 ) ;
V_311 = 0 ;
V_312 &=
V_30 ;
}
static inline bool F_170 ( T_2 V_313 , T_2 V_314 , T_2 V_315 )
{
return ( ( V_313 & V_315 ) | V_314 ) == V_313 ;
}
static inline T_5 F_171 ( T_2 V_314 , T_2 V_315 )
{
return V_314 | ( ( T_5 ) V_315 << 32 ) ;
}
static int F_172 ( struct V_2 * V_3 , T_2 V_316 , T_5 * V_317 )
{
if ( ! F_167 ( V_3 ) && V_316 >= V_318 &&
V_316 <= V_319 ) {
F_173 ( V_3 , V_320 , 0 ) ;
return 1 ;
}
switch ( V_316 ) {
case V_321 :
* V_317 = 0 ;
break;
case V_318 :
* V_317 = V_322 |
( ( T_5 ) V_323 << V_324 ) |
( V_325 << V_326 ) ;
break;
case V_327 :
case V_328 :
* V_317 = F_171 ( V_282 ,
V_283 ) ;
break;
case V_329 :
case V_294 :
* V_317 = F_171 ( V_295 ,
V_296 ) ;
break;
case V_330 :
case V_331 :
* V_317 = F_171 ( V_286 ,
V_287 ) ;
break;
case V_319 :
case V_289 :
* V_317 = F_171 ( V_290 ,
V_291 ) ;
break;
case V_332 :
* V_317 = 0 ;
break;
#define F_174 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_175 X86_CR4_VMXE
case V_333 :
* V_317 = F_174 ;
break;
case V_334 :
* V_317 = - 1ULL ;
break;
case V_335 :
* V_317 = F_175 ;
break;
case V_336 :
* V_317 = - 1ULL ;
break;
case V_337 :
* V_317 = 0x1f ;
break;
case V_310 :
* V_317 = F_171 ( V_311 ,
V_312 ) ;
break;
case V_338 :
* V_317 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_176 ( struct V_2 * V_3 , T_2 V_316 , T_5 V_166 )
{
if ( ! F_167 ( V_3 ) )
return 0 ;
if ( V_316 == V_321 )
return 1 ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , T_2 V_316 , T_5 * V_317 )
{
T_5 V_166 ;
struct V_73 * V_61 ;
if ( ! V_317 ) {
F_56 ( V_76 L_7 ) ;
return - V_339 ;
}
switch ( V_316 ) {
#ifdef F_75
case V_191 :
V_166 = F_71 ( V_340 ) ;
break;
case V_193 :
V_166 = F_71 ( V_341 ) ;
break;
case V_194 :
F_120 ( F_1 ( V_3 ) ) ;
V_166 = F_1 ( V_3 ) -> V_196 ;
break;
#endif
case V_127 :
return F_178 ( V_3 , V_316 , V_317 ) ;
case V_342 :
V_166 = F_156 () ;
break;
case V_343 :
V_166 = F_73 ( V_344 ) ;
break;
case V_345 :
V_166 = F_71 ( V_346 ) ;
break;
case V_207 :
V_166 = F_71 ( V_347 ) ;
break;
case V_259 :
if ( ! F_1 ( V_3 ) -> V_260 )
return 1 ;
default:
if ( F_172 ( V_3 , V_316 , V_317 ) )
return 0 ;
V_61 = F_53 ( F_1 ( V_3 ) , V_316 ) ;
if ( V_61 ) {
V_166 = V_61 -> V_166 ;
break;
}
return F_178 ( V_3 , V_316 , V_317 ) ;
}
* V_317 = V_166 ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 , T_2 V_316 , T_5 V_166 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_73 * V_61 ;
int V_95 = 0 ;
switch ( V_316 ) {
case V_127 :
V_95 = F_180 ( V_3 , V_316 , V_166 ) ;
break;
#ifdef F_75
case V_191 :
F_85 ( V_60 ) ;
F_78 ( V_340 , V_166 ) ;
break;
case V_193 :
F_85 ( V_60 ) ;
F_78 ( V_341 , V_166 ) ;
break;
case V_194 :
F_120 ( V_60 ) ;
V_60 -> V_196 = V_166 ;
break;
#endif
case V_343 :
F_81 ( V_344 , V_166 ) ;
break;
case V_345 :
F_78 ( V_346 , V_166 ) ;
break;
case V_207 :
F_78 ( V_347 , V_166 ) ;
break;
case V_342 :
F_181 ( V_3 , V_166 ) ;
break;
case V_348 :
if ( V_24 . V_349 & V_292 ) {
F_82 ( V_350 , V_166 ) ;
V_3 -> V_97 . V_351 = V_166 ;
break;
}
V_95 = F_180 ( V_3 , V_316 , V_166 ) ;
break;
case V_259 :
if ( ! V_60 -> V_260 )
return 1 ;
if ( ( V_166 >> 32 ) != 0 )
return 1 ;
default:
if ( F_176 ( V_3 , V_316 , V_166 ) )
break;
V_61 = F_53 ( V_60 , V_316 ) ;
if ( V_61 ) {
V_61 -> V_166 = V_166 ;
if ( V_61 - V_60 -> V_65 < V_60 -> V_197 ) {
F_121 () ;
F_112 ( V_61 -> V_66 , V_61 -> V_166 ,
V_61 -> V_91 ) ;
F_122 () ;
}
break;
}
V_95 = F_180 ( V_3 , V_316 , V_166 ) ;
}
return V_95 ;
}
static void F_182 ( struct V_2 * V_3 , enum V_352 V_353 )
{
F_139 ( V_353 , ( unsigned long * ) & V_3 -> V_97 . V_98 ) ;
switch ( V_353 ) {
case V_354 :
V_3 -> V_97 . V_355 [ V_354 ] = F_71 ( V_356 ) ;
break;
case V_357 :
V_3 -> V_97 . V_355 [ V_357 ] = F_71 ( V_358 ) ;
break;
case V_359 :
if ( V_86 )
F_183 ( V_3 ) ;
break;
default:
break;
}
}
static void F_184 ( struct V_2 * V_3 , struct V_360 * V_361 )
{
if ( V_3 -> V_113 & V_362 )
F_78 ( V_363 , V_361 -> V_97 . V_364 [ 7 ] ) ;
else
F_78 ( V_363 , V_3 -> V_97 . V_365 ) ;
F_91 ( V_3 ) ;
}
static T_11 int F_185 ( void )
{
return F_186 () ;
}
static T_11 int F_187 ( void )
{
T_5 V_61 ;
F_109 ( V_321 , V_61 ) ;
if ( V_61 & V_366 ) {
if ( ! ( V_61 & V_367 )
&& F_188 () )
return 1 ;
if ( ! ( V_61 & V_368 )
&& ( V_61 & V_367 )
&& ! F_188 () ) {
F_56 ( V_149 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_61 & V_368 )
&& ! F_188 () )
return 1 ;
}
return 0 ;
}
static void F_124 ( T_5 V_11 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_189 ( void * V_369 )
{
int V_78 = F_60 () ;
T_5 V_75 = F_55 ( F_61 ( V_200 , V_78 ) ) ;
T_5 V_370 , V_371 ;
if ( F_190 () & V_372 )
return - V_373 ;
F_191 ( & F_61 ( V_204 , V_78 ) ) ;
F_109 ( V_321 , V_370 ) ;
V_371 = V_366 ;
V_371 |= V_368 ;
if ( F_188 () )
V_371 |= V_367 ;
if ( ( V_370 & V_371 ) != V_371 ) {
F_111 ( V_321 , V_370 | V_371 ) ;
}
F_192 ( F_190 () | V_372 ) ;
if ( V_201 ) {
F_124 ( V_75 ) ;
F_68 () ;
}
F_193 ( & F_99 ( V_152 ) ) ;
return 0 ;
}
static void F_194 ( void )
{
int V_78 = F_60 () ;
struct V_77 * V_169 , * V_374 ;
F_195 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_59 ( V_169 ) ;
}
static void F_130 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_196 ( void * V_369 )
{
if ( V_201 ) {
F_194 () ;
F_130 () ;
}
F_192 ( F_190 () & ~ V_372 ) ;
}
static T_11 int F_197 ( T_2 V_375 , T_2 V_376 ,
T_2 V_61 , T_2 * V_377 )
{
T_2 V_378 , V_379 ;
T_2 V_380 = V_375 | V_376 ;
F_169 ( V_61 , V_378 , V_379 ) ;
V_380 &= V_379 ;
V_380 |= V_378 ;
if ( V_375 & ~ V_380 )
return - V_381 ;
* V_377 = V_380 ;
return 0 ;
}
static T_11 bool F_198 ( T_2 V_61 , T_2 V_380 )
{
T_2 V_378 , V_379 ;
F_169 ( V_61 , V_378 , V_379 ) ;
return V_379 & V_380 ;
}
static T_11 int F_199 ( struct V_24 * V_382 )
{
T_2 V_378 , V_379 ;
T_2 V_383 , V_384 , V_385 , V_386 ;
T_2 V_387 = 0 ;
T_2 V_388 = 0 ;
T_2 V_389 = 0 ;
T_2 V_390 = 0 ;
T_2 V_391 = 0 ;
V_383 = V_284 | V_285 ;
V_384 = V_54 ;
if ( F_197 ( V_383 , V_384 , V_328 ,
& V_387 ) < 0 )
return - V_381 ;
V_383 = V_298 |
#ifdef F_75
V_303 |
V_304 |
#endif
V_301 |
V_302 |
V_307 |
V_305 |
V_275 |
V_300 |
V_308 |
V_299 |
V_309 ;
V_384 = V_27 |
V_26 |
V_28 ;
if ( F_197 ( V_383 , V_384 , V_294 ,
& V_388 ) < 0 )
return - V_381 ;
#ifdef F_75
if ( ( V_388 & V_27 ) )
V_388 &= ~ V_303 &
~ V_304 ;
#endif
if ( V_388 & V_28 ) {
V_385 = 0 ;
V_386 = V_30 |
V_55 |
V_50 |
V_46 |
V_47 |
V_48 |
V_51 |
V_52 ;
if ( F_197 ( V_385 , V_386 ,
V_310 ,
& V_389 ) < 0 )
return - V_381 ;
}
#ifndef F_75
if ( ! ( V_389 &
V_30 ) )
V_388 &= ~ V_27 ;
#endif
if ( V_389 & V_46 ) {
V_388 &= ~ ( V_301 |
V_302 |
V_299 ) ;
F_169 ( V_338 ,
V_31 . V_32 , V_31 . V_43 ) ;
}
V_383 = 0 ;
#ifdef F_75
V_383 |= V_288 ;
#endif
V_384 = V_392 | V_393 ;
if ( F_197 ( V_383 , V_384 , V_331 ,
& V_390 ) < 0 )
return - V_381 ;
V_383 = 0 ;
V_384 = V_292 ;
if ( F_197 ( V_383 , V_384 , V_289 ,
& V_391 ) < 0 )
return - V_381 ;
F_169 ( V_318 , V_378 , V_379 ) ;
if ( ( V_379 & 0x1fff ) > V_394 )
return - V_381 ;
#ifdef F_75
if ( V_379 & ( 1u << 16 ) )
return - V_381 ;
#endif
if ( ( ( V_379 >> 18 ) & 15 ) != 6 )
return - V_381 ;
V_382 -> V_395 = V_379 & 0x1fff ;
V_382 -> V_396 = F_200 ( V_24 . V_395 ) ;
V_382 -> V_397 = V_378 ;
V_382 -> V_53 = V_387 ;
V_382 -> V_25 = V_388 ;
V_382 -> V_29 = V_389 ;
V_382 -> V_398 = V_390 ;
V_382 -> V_349 = V_391 ;
V_128 =
F_198 ( V_289 ,
V_129 )
&& F_198 ( V_331 ,
V_130 ) ;
V_132 =
F_198 ( V_289 ,
V_133 )
&& F_198 ( V_331 ,
V_134 ) ;
if ( V_132 && V_399 . V_400 == 0x6 ) {
switch ( V_399 . V_401 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_132 = false ;
F_97 ( V_149 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_74 * F_201 ( int V_78 )
{
int V_402 = F_202 ( V_78 ) ;
struct V_10 * V_403 ;
struct V_74 * V_74 ;
V_403 = F_203 ( V_402 , V_404 , V_24 . V_396 ) ;
if ( ! V_403 )
return NULL ;
V_74 = F_204 ( V_403 ) ;
memset ( V_74 , 0 , V_24 . V_395 ) ;
V_74 -> V_397 = V_24 . V_397 ;
return V_74 ;
}
static struct V_74 * F_205 ( void )
{
return F_201 ( F_60 () ) ;
}
static void F_206 ( struct V_74 * V_74 )
{
F_207 ( ( unsigned long ) V_74 , V_24 . V_396 ) ;
}
static void F_208 ( struct V_77 * V_77 )
{
if ( ! V_77 -> V_74 )
return;
F_63 ( V_77 ) ;
F_206 ( V_77 -> V_74 ) ;
V_77 -> V_74 = NULL ;
}
static void F_209 ( void )
{
int V_78 ;
F_210 (cpu) {
F_206 ( F_61 ( V_200 , V_78 ) ) ;
F_61 ( V_200 , V_78 ) = NULL ;
}
}
static T_11 int F_211 ( void )
{
int V_78 ;
F_210 (cpu) {
struct V_74 * V_74 ;
V_74 = F_201 ( V_78 ) ;
if ( ! V_74 ) {
F_209 () ;
return - V_405 ;
}
F_61 ( V_200 , V_78 ) = V_74 ;
}
return 0 ;
}
static T_11 int F_212 ( void )
{
if ( F_199 ( & V_24 ) < 0 )
return - V_381 ;
if ( F_213 ( V_406 ) )
F_214 ( V_161 ) ;
if ( ! F_40 () )
V_407 = 0 ;
if ( ! F_36 () ||
! F_29 () ) {
V_86 = 0 ;
V_408 = 0 ;
V_409 = 0 ;
}
if ( ! F_30 () )
V_409 = 0 ;
if ( ! F_37 () )
V_408 = 0 ;
if ( ! F_23 () )
V_49 = 0 ;
if ( ! F_18 () )
V_410 -> V_411 = NULL ;
if ( V_86 && ! F_27 () )
F_215 () ;
if ( ! F_38 () )
V_412 = 0 ;
if ( V_8 )
F_168 () ;
return F_211 () ;
}
static T_12 void F_216 ( void )
{
F_209 () ;
}
static void F_217 ( int V_94 , struct V_413 * V_414 )
{
struct V_415 * V_416 = & V_103 [ V_94 ] ;
if ( F_71 ( V_416 -> V_104 ) == V_414 -> V_104 && ( V_414 -> V_104 & V_417 ) ) {
F_80 ( V_416 -> V_101 , V_414 -> V_101 ) ;
F_78 ( V_416 -> V_104 , V_414 -> V_104 ) ;
F_81 ( V_416 -> V_106 , V_414 -> V_106 ) ;
F_81 ( V_416 -> V_110 , V_414 -> V_108 ) ;
} else {
T_2 V_418 = ( F_72 ( V_416 -> V_101 ) & V_419 )
<< V_420 ;
F_81 ( V_416 -> V_110 , 0x93 | V_418 ) ;
}
}
static void F_218 ( struct V_2 * V_3 )
{
unsigned long V_421 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
V_60 -> V_422 = 1 ;
V_60 -> V_117 . V_118 = 0 ;
F_85 ( V_60 ) ;
F_80 ( V_423 , V_60 -> V_117 . V_174 . V_101 ) ;
F_78 ( V_424 , V_60 -> V_117 . V_174 . V_104 ) ;
F_81 ( V_425 , V_60 -> V_117 . V_174 . V_106 ) ;
F_81 ( V_426 , V_60 -> V_117 . V_174 . V_108 ) ;
V_421 = F_71 ( V_226 ) ;
V_421 &= V_227 ;
V_421 |= V_60 -> V_117 . V_224 & ~ V_227 ;
F_78 ( V_226 , V_421 ) ;
F_78 ( V_427 , ( F_71 ( V_427 ) & ~ V_428 ) |
( F_71 ( V_429 ) & V_428 ) ) ;
F_91 ( V_3 ) ;
if ( V_430 )
return;
F_217 ( V_431 , & V_60 -> V_117 . V_188 ) ;
F_217 ( V_432 , & V_60 -> V_117 . V_186 ) ;
F_217 ( V_433 , & V_60 -> V_117 . V_183 ) ;
F_217 ( V_434 , & V_60 -> V_117 . V_179 ) ;
F_85 ( V_60 ) ;
F_80 ( V_435 , 0 ) ;
F_81 ( V_436 , 0x93 ) ;
F_80 ( V_437 ,
F_72 ( V_437 ) & ~ V_419 ) ;
F_81 ( V_438 , 0x9b ) ;
}
static T_4 F_219 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_97 . V_439 ) {
struct V_440 * V_441 ;
struct V_442 * V_443 ;
T_13 V_444 ;
V_441 = V_440 ( V_12 ) ;
V_443 = F_220 ( V_441 , 0 ) ;
V_444 = V_443 -> V_444 + V_443 -> V_445 - 3 ;
return V_444 << V_13 ;
}
return V_12 -> V_97 . V_439 ;
}
static void F_221 ( int V_94 , struct V_413 * V_414 )
{
struct V_415 * V_416 = & V_103 [ V_94 ] ;
V_414 -> V_101 = F_72 ( V_416 -> V_101 ) ;
V_414 -> V_104 = F_71 ( V_416 -> V_104 ) ;
V_414 -> V_106 = F_73 ( V_416 -> V_106 ) ;
V_414 -> V_108 = F_73 ( V_416 -> V_110 ) ;
F_80 ( V_416 -> V_101 , V_414 -> V_104 >> 4 ) ;
F_81 ( V_416 -> V_104 , V_414 -> V_104 & 0xffff0 ) ;
F_81 ( V_416 -> V_106 , 0xffff ) ;
F_81 ( V_416 -> V_110 , 0xf3 ) ;
if ( V_414 -> V_104 & 0xf )
F_97 ( V_149 L_12
L_13 ,
V_94 ) ;
}
static void F_222 ( struct V_2 * V_3 )
{
unsigned long V_421 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_446 V_447 ;
if ( V_408 )
return;
V_60 -> V_422 = 1 ;
V_60 -> V_117 . V_118 = 1 ;
if ( ! V_3 -> V_12 -> V_97 . V_439 ) {
F_97 ( V_149 L_14
L_15 ) ;
F_223 ( & V_3 -> V_12 -> V_448 , V_3 -> V_449 ) ;
F_224 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_449 = F_225 ( & V_3 -> V_12 -> V_448 ) ;
}
F_85 ( V_60 ) ;
V_60 -> V_117 . V_174 . V_101 = F_72 ( V_423 ) ;
V_60 -> V_117 . V_174 . V_104 = F_71 ( V_424 ) ;
F_78 ( V_424 , F_219 ( V_3 -> V_12 ) ) ;
V_60 -> V_117 . V_174 . V_106 = F_73 ( V_425 ) ;
F_81 ( V_425 , V_450 - 1 ) ;
V_60 -> V_117 . V_174 . V_108 = F_73 ( V_426 ) ;
F_81 ( V_426 , 0x008b ) ;
V_421 = F_71 ( V_226 ) ;
V_60 -> V_117 . V_224 = V_421 ;
V_421 |= V_229 | V_230 ;
F_78 ( V_226 , V_421 ) ;
F_78 ( V_427 , F_71 ( V_427 ) | V_428 ) ;
F_91 ( V_3 ) ;
if ( V_430 )
goto V_451;
F_226 ( V_3 , & V_447 , V_452 ) ;
F_227 ( V_3 , & V_447 , V_452 ) ;
F_226 ( V_3 , & V_447 , V_453 ) ;
F_227 ( V_3 , & V_447 , V_453 ) ;
F_226 ( V_3 , & V_447 , V_431 ) ;
F_227 ( V_3 , & V_447 , V_431 ) ;
F_226 ( V_3 , & V_447 , V_432 ) ;
F_227 ( V_3 , & V_447 , V_432 ) ;
F_226 ( V_3 , & V_447 , V_433 ) ;
F_227 ( V_3 , & V_447 , V_433 ) ;
F_226 ( V_3 , & V_447 , V_434 ) ;
F_227 ( V_3 , & V_447 , V_434 ) ;
V_451:
F_228 ( V_3 ) ;
}
static void F_229 ( struct V_2 * V_3 , T_5 V_160 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_73 * V_61 = F_53 ( V_60 , V_127 ) ;
if ( ! V_61 )
return;
F_120 ( F_1 ( V_3 ) ) ;
V_3 -> V_97 . V_160 = V_160 ;
if ( V_160 & V_163 ) {
F_81 ( V_123 ,
F_73 ( V_123 ) |
V_293 ) ;
V_61 -> V_166 = V_160 ;
} else {
F_81 ( V_123 ,
F_73 ( V_123 ) &
~ V_293 ) ;
V_61 -> V_166 = V_160 & ~ V_164 ;
}
F_155 ( V_60 ) ;
}
static void F_230 ( struct V_2 * V_3 )
{
T_2 V_454 ;
F_85 ( F_1 ( V_3 ) ) ;
V_454 = F_73 ( V_426 ) ;
if ( ( V_454 & V_455 ) != V_456 ) {
F_231 ( L_16 ,
V_457 ) ;
F_81 ( V_426 ,
( V_454 & ~ V_455 )
| V_456 ) ;
}
F_229 ( V_3 , V_3 -> V_97 . V_160 | V_163 ) ;
}
static void F_232 ( struct V_2 * V_3 )
{
F_81 ( V_123 ,
F_73 ( V_123 )
& ~ V_293 ) ;
F_229 ( V_3 , V_3 -> V_97 . V_160 & ~ V_163 ) ;
}
static void F_233 ( struct V_2 * V_3 )
{
F_67 ( F_1 ( V_3 ) ) ;
if ( V_86 ) {
if ( ! F_234 ( V_3 -> V_97 . V_458 . V_459 ) )
return;
F_69 ( F_235 ( V_3 -> V_97 . V_458 . V_459 ) ) ;
}
}
static void F_136 ( struct V_2 * V_3 )
{
T_9 V_213 = V_3 -> V_97 . V_213 ;
V_3 -> V_97 . V_209 &= ~ V_213 ;
V_3 -> V_97 . V_209 |= F_71 ( V_210 ) & V_213 ;
}
static void F_236 ( struct V_2 * V_3 )
{
if ( V_86 && F_237 ( V_3 ) )
V_3 -> V_97 . V_460 = F_71 ( V_461 ) ;
F_139 ( V_462 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
}
static void F_238 ( struct V_2 * V_3 )
{
T_9 V_463 = V_3 -> V_97 . V_463 ;
V_3 -> V_97 . V_464 &= ~ V_463 ;
V_3 -> V_97 . V_464 |= F_71 ( V_427 ) & V_463 ;
}
static void F_239 ( struct V_2 * V_3 )
{
if ( ! F_138 ( V_359 ,
( unsigned long * ) & V_3 -> V_97 . V_465 ) )
return;
if ( F_237 ( V_3 ) && F_240 ( V_3 ) && ! F_110 ( V_3 ) ) {
F_82 ( V_466 , V_3 -> V_97 . V_458 . V_467 [ 0 ] ) ;
F_82 ( V_468 , V_3 -> V_97 . V_458 . V_467 [ 1 ] ) ;
F_82 ( V_469 , V_3 -> V_97 . V_458 . V_467 [ 2 ] ) ;
F_82 ( V_470 , V_3 -> V_97 . V_458 . V_467 [ 3 ] ) ;
}
}
static void F_183 ( struct V_2 * V_3 )
{
if ( F_237 ( V_3 ) && F_240 ( V_3 ) && ! F_110 ( V_3 ) ) {
V_3 -> V_97 . V_458 . V_467 [ 0 ] = F_74 ( V_466 ) ;
V_3 -> V_97 . V_458 . V_467 [ 1 ] = F_74 ( V_468 ) ;
V_3 -> V_97 . V_458 . V_467 [ 2 ] = F_74 ( V_469 ) ;
V_3 -> V_97 . V_458 . V_467 [ 3 ] = F_74 ( V_470 ) ;
}
F_139 ( V_359 ,
( unsigned long * ) & V_3 -> V_97 . V_98 ) ;
F_139 ( V_359 ,
( unsigned long * ) & V_3 -> V_97 . V_465 ) ;
}
static void F_241 ( unsigned long * V_471 ,
unsigned long V_209 ,
struct V_2 * V_3 )
{
if ( ! F_138 ( V_462 , ( T_9 * ) & V_3 -> V_97 . V_98 ) )
F_236 ( V_3 ) ;
if ( ! ( V_209 & V_472 ) ) {
F_81 ( V_473 ,
F_73 ( V_473 ) |
( V_301 |
V_302 ) ) ;
V_3 -> V_97 . V_209 = V_209 ;
F_242 ( V_3 , F_243 ( V_3 ) ) ;
} else if ( ! F_237 ( V_3 ) ) {
F_81 ( V_473 ,
F_73 ( V_473 ) &
~ ( V_301 |
V_302 ) ) ;
V_3 -> V_97 . V_209 = V_209 ;
F_242 ( V_3 , F_243 ( V_3 ) ) ;
}
if ( ! ( V_209 & V_474 ) )
* V_471 &= ~ V_474 ;
}
static void F_244 ( struct V_2 * V_3 , unsigned long V_209 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned long V_471 ;
if ( V_408 )
V_471 = ( V_209 & ~ V_475 )
| V_476 ;
else
V_471 = ( V_209 & ~ V_477 ) | V_478 ;
if ( V_60 -> V_117 . V_118 && ( V_209 & V_479 ) )
F_218 ( V_3 ) ;
if ( ! V_60 -> V_117 . V_118 && ! ( V_209 & V_479 ) )
F_222 ( V_3 ) ;
#ifdef F_75
if ( V_3 -> V_97 . V_160 & V_164 ) {
if ( ! F_237 ( V_3 ) && ( V_209 & V_472 ) )
F_230 ( V_3 ) ;
if ( F_237 ( V_3 ) && ! ( V_209 & V_472 ) )
F_232 ( V_3 ) ;
}
#endif
if ( V_86 )
F_241 ( & V_471 , V_209 , V_3 ) ;
if ( ! V_3 -> V_119 )
V_471 |= V_211 | V_212 ;
F_78 ( V_222 , V_209 ) ;
F_78 ( V_210 , V_471 ) ;
V_3 -> V_97 . V_209 = V_209 ;
F_141 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
}
static T_5 F_235 ( unsigned long V_459 )
{
T_5 V_71 ;
V_71 = V_480 |
V_481 << V_482 ;
if ( V_409 )
V_71 |= V_483 ;
V_71 |= ( V_459 & V_484 ) ;
return V_71 ;
}
static void F_245 ( struct V_2 * V_3 , unsigned long V_460 )
{
unsigned long V_485 ;
T_5 V_71 ;
V_485 = V_460 ;
if ( V_86 ) {
V_71 = F_235 ( V_460 ) ;
F_82 ( V_486 , V_71 ) ;
V_485 = F_237 ( V_3 ) ? F_246 ( V_3 ) :
V_3 -> V_12 -> V_97 . V_487 ;
F_239 ( V_3 ) ;
}
F_233 ( V_3 ) ;
F_78 ( V_461 , V_485 ) ;
}
static int F_242 ( struct V_2 * V_3 , unsigned long V_464 )
{
unsigned long V_488 = V_464 | ( F_1 ( V_3 ) -> V_117 . V_118 ?
V_489 : V_490 ) ;
if ( V_464 & V_372 ) {
if ( ! F_167 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_491 )
return 1 ;
V_3 -> V_97 . V_464 = V_464 ;
if ( V_86 ) {
if ( ! F_237 ( V_3 ) ) {
V_488 &= ~ V_492 ;
V_488 |= V_493 ;
} else if ( ! ( V_464 & V_492 ) ) {
V_488 &= ~ V_492 ;
}
}
F_78 ( V_429 , V_464 ) ;
F_78 ( V_427 , V_488 ) ;
return 0 ;
}
static void F_226 ( struct V_2 * V_3 ,
struct V_446 * V_447 , int V_94 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_413 * V_414 ;
T_2 V_108 ;
if ( V_60 -> V_117 . V_118
&& ( V_94 == V_494 || V_94 == V_431
|| V_94 == V_432 || V_94 == V_434
|| V_94 == V_433 )
&& ! V_430 ) {
switch ( V_94 ) {
case V_494 : V_414 = & V_60 -> V_117 . V_174 ; break;
case V_431 : V_414 = & V_60 -> V_117 . V_188 ; break;
case V_432 : V_414 = & V_60 -> V_117 . V_186 ; break;
case V_434 : V_414 = & V_60 -> V_117 . V_179 ; break;
case V_433 : V_414 = & V_60 -> V_117 . V_183 ; break;
default: F_247 () ;
}
V_447 -> V_101 = V_414 -> V_101 ;
V_447 -> V_104 = V_414 -> V_104 ;
V_447 -> V_106 = V_414 -> V_106 ;
V_108 = V_414 -> V_108 ;
if ( V_94 == V_494
|| V_447 -> V_101 == F_87 ( V_60 , V_94 ) )
goto V_495;
}
V_447 -> V_104 = F_88 ( V_60 , V_94 ) ;
V_447 -> V_106 = F_89 ( V_60 , V_94 ) ;
V_447 -> V_101 = F_87 ( V_60 , V_94 ) ;
V_108 = F_90 ( V_60 , V_94 ) ;
V_495:
if ( ( V_108 & V_496 ) && ! V_430 )
V_108 = 0 ;
V_447 -> type = V_108 & 15 ;
V_447 -> V_171 = ( V_108 >> 4 ) & 1 ;
V_447 -> V_418 = ( V_108 >> 5 ) & 3 ;
V_447 -> V_497 = ( V_108 >> 7 ) & 1 ;
V_447 -> V_498 = ( V_108 >> 12 ) & 1 ;
V_447 -> V_499 = ( V_108 >> 13 ) & 1 ;
V_447 -> V_500 = ( V_108 >> 14 ) & 1 ;
V_447 -> V_501 = ( V_108 >> 15 ) & 1 ;
V_447 -> V_502 = ( V_108 >> 16 ) & 1 ;
}
static T_5 F_248 ( struct V_2 * V_3 , int V_94 )
{
struct V_446 V_171 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
F_226 ( V_3 , & V_171 , V_94 ) ;
return V_171 . V_104 ;
}
return F_88 ( F_1 ( V_3 ) , V_94 ) ;
}
static int F_249 ( struct V_2 * V_3 )
{
if ( ! F_250 ( V_3 ) )
return 0 ;
if ( ! F_110 ( V_3 )
&& ( F_251 ( V_3 ) & V_230 ) )
return 3 ;
return F_87 ( F_1 ( V_3 ) , V_453 ) & 3 ;
}
static int F_252 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( F_79 ( V_60 -> V_422 && V_430 ) ) {
return V_60 -> V_503 ;
}
if ( ! F_138 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ) {
F_139 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
V_60 -> V_503 = F_249 ( V_3 ) ;
}
return V_60 -> V_503 ;
}
static T_2 F_253 ( struct V_446 * V_447 )
{
T_2 V_108 ;
if ( V_447 -> V_502 || ! V_447 -> V_497 )
V_108 = 1 << 16 ;
else {
V_108 = V_447 -> type & 15 ;
V_108 |= ( V_447 -> V_171 & 1 ) << 4 ;
V_108 |= ( V_447 -> V_418 & 3 ) << 5 ;
V_108 |= ( V_447 -> V_497 & 1 ) << 7 ;
V_108 |= ( V_447 -> V_498 & 1 ) << 12 ;
V_108 |= ( V_447 -> V_499 & 1 ) << 13 ;
V_108 |= ( V_447 -> V_500 & 1 ) << 14 ;
V_108 |= ( V_447 -> V_501 & 1 ) << 15 ;
}
return V_108 ;
}
static void F_227 ( struct V_2 * V_3 ,
struct V_446 * V_447 , int V_94 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_415 * V_416 = & V_103 [ V_94 ] ;
T_2 V_108 ;
F_85 ( V_60 ) ;
if ( V_60 -> V_117 . V_118 && V_94 == V_494 ) {
F_80 ( V_416 -> V_101 , V_447 -> V_101 ) ;
V_60 -> V_117 . V_174 . V_101 = V_447 -> V_101 ;
V_60 -> V_117 . V_174 . V_104 = V_447 -> V_104 ;
V_60 -> V_117 . V_174 . V_106 = V_447 -> V_106 ;
V_60 -> V_117 . V_174 . V_108 = F_253 ( V_447 ) ;
return;
}
F_78 ( V_416 -> V_104 , V_447 -> V_104 ) ;
F_81 ( V_416 -> V_106 , V_447 -> V_106 ) ;
F_80 ( V_416 -> V_101 , V_447 -> V_101 ) ;
if ( V_60 -> V_117 . V_118 && V_447 -> V_171 ) {
if ( V_447 -> V_104 == 0xffff0000 && V_447 -> V_101 == 0xf000 )
F_78 ( V_416 -> V_104 , 0xf0000 ) ;
V_108 = 0xf3 ;
} else
V_108 = F_253 ( V_447 ) ;
if ( V_408 && ( V_94 != V_504 ) )
V_108 |= 0x1 ;
F_81 ( V_416 -> V_110 , V_108 ) ;
F_141 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
if ( ! V_408 && V_60 -> V_117 . V_118 ) {
switch ( V_94 ) {
case V_453 :
F_81 ( V_438 , 0xf3 ) ;
F_81 ( V_505 , 0xffff ) ;
if ( F_71 ( V_506 ) == 0xffff0000 )
F_78 ( V_506 , 0xf0000 ) ;
F_80 ( V_437 ,
F_71 ( V_506 ) >> 4 ) ;
break;
case V_431 :
F_221 ( V_431 , & V_60 -> V_117 . V_188 ) ;
break;
case V_432 :
F_221 ( V_432 , & V_60 -> V_117 . V_186 ) ;
break;
case V_433 :
F_221 ( V_433 , & V_60 -> V_117 . V_183 ) ;
break;
case V_434 :
F_221 ( V_434 , & V_60 -> V_117 . V_179 ) ;
break;
case V_452 :
F_80 ( V_435 ,
F_71 ( V_507 ) >> 4 ) ;
F_81 ( V_508 , 0xffff ) ;
F_81 ( V_436 , 0xf3 ) ;
break;
}
}
}
static void F_254 ( struct V_2 * V_3 , int * V_500 , int * V_499 )
{
T_2 V_108 = F_90 ( F_1 ( V_3 ) , V_453 ) ;
* V_500 = ( V_108 >> 14 ) & 1 ;
* V_499 = ( V_108 >> 13 ) & 1 ;
}
static void F_255 ( struct V_2 * V_3 , struct V_150 * V_509 )
{
V_509 -> V_395 = F_73 ( V_510 ) ;
V_509 -> V_155 = F_71 ( V_511 ) ;
}
static void F_256 ( struct V_2 * V_3 , struct V_150 * V_509 )
{
F_81 ( V_510 , V_509 -> V_395 ) ;
F_78 ( V_511 , V_509 -> V_155 ) ;
}
static void F_257 ( struct V_2 * V_3 , struct V_150 * V_509 )
{
V_509 -> V_395 = F_73 ( V_512 ) ;
V_509 -> V_155 = F_71 ( V_513 ) ;
}
static void F_258 ( struct V_2 * V_3 , struct V_150 * V_509 )
{
F_81 ( V_512 , V_509 -> V_395 ) ;
F_78 ( V_513 , V_509 -> V_155 ) ;
}
static bool F_259 ( struct V_2 * V_3 , int V_94 )
{
struct V_446 V_447 ;
T_2 V_108 ;
F_226 ( V_3 , & V_447 , V_94 ) ;
V_108 = F_253 ( & V_447 ) ;
if ( V_447 . V_104 != ( V_447 . V_101 << 4 ) )
return false ;
if ( V_447 . V_106 != 0xffff )
return false ;
if ( V_108 != 0xf3 )
return false ;
return true ;
}
static bool F_260 ( struct V_2 * V_3 )
{
struct V_446 V_514 ;
unsigned int V_515 ;
F_226 ( V_3 , & V_514 , V_453 ) ;
V_515 = V_514 . V_101 & V_419 ;
if ( V_514 . V_502 )
return false ;
if ( ~ V_514 . type & ( V_516 | V_517 ) )
return false ;
if ( ! V_514 . V_171 )
return false ;
if ( V_514 . type & V_518 ) {
if ( V_514 . V_418 > V_515 )
return false ;
} else {
if ( V_514 . V_418 != V_515 )
return false ;
}
if ( ! V_514 . V_497 )
return false ;
return true ;
}
static bool F_261 ( struct V_2 * V_3 )
{
struct V_446 V_519 ;
unsigned int V_520 ;
F_226 ( V_3 , & V_519 , V_452 ) ;
V_520 = V_519 . V_101 & V_419 ;
if ( V_519 . V_502 )
return true ;
if ( V_519 . type != 3 && V_519 . type != 7 )
return false ;
if ( ! V_519 . V_171 )
return false ;
if ( V_519 . V_418 != V_520 )
return false ;
if ( ! V_519 . V_497 )
return false ;
return true ;
}
static bool F_262 ( struct V_2 * V_3 , int V_94 )
{
struct V_446 V_447 ;
unsigned int V_521 ;
F_226 ( V_3 , & V_447 , V_94 ) ;
V_521 = V_447 . V_101 & V_419 ;
if ( V_447 . V_502 )
return true ;
if ( ! V_447 . V_171 )
return false ;
if ( ! V_447 . V_497 )
return false ;
if ( ~ V_447 . type & ( V_516 | V_518 ) ) {
if ( V_447 . V_418 < V_521 )
return false ;
}
return true ;
}
static bool F_263 ( struct V_2 * V_3 )
{
struct V_446 V_174 ;
F_226 ( V_3 , & V_174 , V_494 ) ;
if ( V_174 . V_502 )
return false ;
if ( V_174 . V_101 & V_522 )
return false ;
if ( V_174 . type != 3 && V_174 . type != 11 )
return false ;
if ( ! V_174 . V_497 )
return false ;
return true ;
}
static bool F_264 ( struct V_2 * V_3 )
{
struct V_446 V_523 ;
F_226 ( V_3 , & V_523 , V_504 ) ;
if ( V_523 . V_502 )
return true ;
if ( V_523 . V_101 & V_522 )
return false ;
if ( V_523 . type != 2 )
return false ;
if ( ! V_523 . V_497 )
return false ;
return true ;
}
static bool F_265 ( struct V_2 * V_3 )
{
struct V_446 V_514 , V_519 ;
F_226 ( V_3 , & V_514 , V_453 ) ;
F_226 ( V_3 , & V_519 , V_452 ) ;
return ( ( V_514 . V_101 & V_419 ) ==
( V_519 . V_101 & V_419 ) ) ;
}
static bool F_266 ( struct V_2 * V_3 )
{
if ( ! F_250 ( V_3 ) ) {
if ( ! F_259 ( V_3 , V_453 ) )
return false ;
if ( ! F_259 ( V_3 , V_452 ) )
return false ;
if ( ! F_259 ( V_3 , V_432 ) )
return false ;
if ( ! F_259 ( V_3 , V_431 ) )
return false ;
if ( ! F_259 ( V_3 , V_434 ) )
return false ;
if ( ! F_259 ( V_3 , V_433 ) )
return false ;
} else {
if ( ! F_265 ( V_3 ) )
return false ;
if ( ! F_260 ( V_3 ) )
return false ;
if ( ! F_261 ( V_3 ) )
return false ;
if ( ! F_262 ( V_3 , V_432 ) )
return false ;
if ( ! F_262 ( V_3 , V_431 ) )
return false ;
if ( ! F_262 ( V_3 , V_434 ) )
return false ;
if ( ! F_262 ( V_3 , V_433 ) )
return false ;
if ( ! F_263 ( V_3 ) )
return false ;
if ( ! F_264 ( V_3 ) )
return false ;
}
return true ;
}
static int F_267 ( struct V_12 * V_12 )
{
T_13 V_524 ;
T_3 V_166 = 0 ;
int V_525 , V_526 , V_95 = 0 ;
V_526 = F_225 ( & V_12 -> V_448 ) ;
V_524 = F_219 ( V_12 ) >> V_13 ;
V_525 = F_268 ( V_12 , V_524 , 0 , V_394 ) ;
if ( V_525 < 0 )
goto V_527;
V_166 = V_528 + V_529 ;
V_525 = F_269 ( V_12 , V_524 ++ , & V_166 ,
V_530 , sizeof( T_3 ) ) ;
if ( V_525 < 0 )
goto V_527;
V_525 = F_268 ( V_12 , V_524 ++ , 0 , V_394 ) ;
if ( V_525 < 0 )
goto V_527;
V_525 = F_268 ( V_12 , V_524 , 0 , V_394 ) ;
if ( V_525 < 0 )
goto V_527;
V_166 = ~ 0 ;
V_525 = F_269 ( V_12 , V_524 , & V_166 ,
V_450 - 2 * V_394 - 1 ,
sizeof( T_6 ) ) ;
if ( V_525 < 0 )
goto V_527;
V_95 = 1 ;
V_527:
F_223 ( & V_12 -> V_448 , V_526 ) ;
return V_95 ;
}
static int F_270 ( struct V_12 * V_12 )
{
int V_62 , V_526 , V_525 , V_95 ;
T_14 V_531 ;
T_2 V_254 ;
if ( ! V_86 )
return 1 ;
if ( F_79 ( ! V_12 -> V_97 . V_532 ) ) {
F_56 ( V_76 L_17
L_18 ) ;
return 0 ;
}
if ( F_271 ( V_12 -> V_97 . V_533 ) )
return 1 ;
V_95 = 0 ;
V_531 = V_12 -> V_97 . V_487 >> V_13 ;
V_526 = F_225 ( & V_12 -> V_448 ) ;
V_525 = F_268 ( V_12 , V_531 , 0 , V_394 ) ;
if ( V_525 < 0 )
goto V_527;
for ( V_62 = 0 ; V_62 < V_534 ; V_62 ++ ) {
V_254 = ( V_62 << 22 ) + ( V_535 | V_536 | V_537 |
V_538 | V_539 | V_540 ) ;
V_525 = F_269 ( V_12 , V_531 ,
& V_254 , V_62 * sizeof( V_254 ) , sizeof( V_254 ) ) ;
if ( V_525 < 0 )
goto V_527;
}
V_12 -> V_97 . V_533 = true ;
V_95 = 1 ;
V_527:
F_223 ( & V_12 -> V_448 , V_526 ) ;
return V_95 ;
}
static void F_272 ( int V_94 )
{
struct V_415 * V_416 = & V_103 [ V_94 ] ;
unsigned int V_108 ;
F_80 ( V_416 -> V_101 , 0 ) ;
F_78 ( V_416 -> V_104 , 0 ) ;
F_81 ( V_416 -> V_106 , 0xffff ) ;
if ( V_408 ) {
V_108 = 0x93 ;
if ( V_94 == V_453 )
V_108 |= 0x08 ;
} else
V_108 = 0xf3 ;
F_81 ( V_416 -> V_110 , V_108 ) ;
}
static int F_273 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_541 V_542 ;
int V_525 = 0 ;
F_274 ( & V_12 -> V_543 ) ;
if ( V_12 -> V_97 . V_544 )
goto V_527;
V_542 . V_443 = V_545 ;
V_542 . V_421 = 0 ;
V_542 . V_546 = 0xfee00000ULL ;
V_542 . V_547 = V_394 ;
V_525 = F_275 ( V_12 , & V_542 , 0 ) ;
if ( V_525 )
goto V_527;
V_10 = F_6 ( V_12 , 0xfee00 ) ;
if ( F_7 ( V_10 ) ) {
V_525 = - V_548 ;
goto V_527;
}
V_12 -> V_97 . V_544 = V_10 ;
V_527:
F_276 ( & V_12 -> V_543 ) ;
return V_525 ;
}
static int F_277 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_541 V_542 ;
int V_525 = 0 ;
F_274 ( & V_12 -> V_543 ) ;
if ( V_12 -> V_97 . V_532 )
goto V_527;
V_542 . V_443 = V_549 ;
V_542 . V_421 = 0 ;
V_542 . V_546 =
V_12 -> V_97 . V_487 ;
V_542 . V_547 = V_394 ;
V_525 = F_275 ( V_12 , & V_542 , 0 ) ;
if ( V_525 )
goto V_527;
V_10 = F_6 ( V_12 , V_12 -> V_97 . V_487 >> V_13 ) ;
if ( F_7 ( V_10 ) ) {
V_525 = - V_548 ;
goto V_527;
}
V_12 -> V_97 . V_532 = V_10 ;
V_527:
F_276 ( & V_12 -> V_543 ) ;
return V_525 ;
}
static void F_278 ( struct V_1 * V_60 )
{
int V_43 ;
V_60 -> V_43 = 0 ;
if ( ! V_407 )
return;
F_279 ( & V_550 ) ;
V_43 = F_280 ( V_551 , V_552 ) ;
if ( V_43 < V_552 ) {
V_60 -> V_43 = V_43 ;
F_139 ( V_43 , V_551 ) ;
}
F_281 ( & V_550 ) ;
}
static void F_282 ( struct V_1 * V_60 )
{
if ( ! V_407 )
return;
F_279 ( & V_550 ) ;
if ( V_60 -> V_43 != 0 )
F_141 ( V_60 -> V_43 , V_551 ) ;
F_281 ( & V_550 ) ;
}
static void F_283 ( unsigned long * V_255 , T_2 V_61 )
{
int V_553 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_61 <= 0x1fff ) {
F_141 ( V_61 , V_255 + 0x000 / V_553 ) ;
F_141 ( V_61 , V_255 + 0x800 / V_553 ) ;
} else if ( ( V_61 >= 0xc0000000 ) && ( V_61 <= 0xc0001fff ) ) {
V_61 &= 0x1fff ;
F_141 ( V_61 , V_255 + 0x400 / V_553 ) ;
F_141 ( V_61 , V_255 + 0xc00 / V_553 ) ;
}
}
static void F_284 ( T_2 V_61 , bool V_554 )
{
if ( ! V_554 )
F_283 ( V_263 , V_61 ) ;
F_283 ( V_262 , V_61 ) ;
}
static void F_285 ( void )
{
T_2 V_555 , V_556 ;
unsigned long V_557 ;
struct V_150 V_509 ;
F_78 ( V_558 , F_286 () | V_211 ) ;
F_78 ( V_559 , F_190 () ) ;
F_78 ( V_560 , F_287 () ) ;
F_80 ( V_561 , V_562 ) ;
#ifdef F_75
F_80 ( V_563 , 0 ) ;
F_80 ( V_564 , 0 ) ;
#else
F_80 ( V_563 , V_565 ) ;
F_80 ( V_564 , V_565 ) ;
#endif
F_80 ( V_566 , V_565 ) ;
F_80 ( V_567 , V_156 * 8 ) ;
F_288 ( & V_509 ) ;
F_78 ( V_568 , V_509 . V_155 ) ;
asm("mov $.Lkvm_vmx_return, %0" : "=r"(tmpl));
F_78 ( V_569 , V_557 ) ;
F_169 ( V_343 , V_555 , V_556 ) ;
F_81 ( V_570 , V_555 ) ;
F_109 ( V_345 , V_557 ) ;
F_78 ( V_571 , V_557 ) ;
if ( V_24 . V_398 & V_393 ) {
F_169 ( V_348 , V_555 , V_556 ) ;
F_82 ( V_572 , V_555 | ( ( T_5 ) V_556 << 32 ) ) ;
}
}
static void F_289 ( struct V_1 * V_60 )
{
V_60 -> V_3 . V_97 . V_463 = V_573 ;
if ( V_86 )
V_60 -> V_3 . V_97 . V_463 |= V_574 ;
if ( F_92 ( & V_60 -> V_3 ) )
V_60 -> V_3 . V_97 . V_463 &=
~ F_4 ( & V_60 -> V_3 ) -> V_220 ;
F_78 ( V_575 , ~ V_60 -> V_3 . V_97 . V_463 ) ;
}
static T_2 F_290 ( struct V_1 * V_60 )
{
T_2 V_576 = V_24 . V_25 ;
if ( ! F_19 ( V_60 -> V_3 . V_12 ) ) {
V_576 &= ~ V_27 ;
#ifdef F_75
V_576 |= V_304 |
V_303 ;
#endif
}
if ( ! V_86 )
V_576 |= V_302 |
V_301 |
V_299 ;
return V_576 ;
}
static T_2 F_291 ( struct V_1 * V_60 )
{
T_2 V_576 = V_24 . V_29 ;
if ( ! F_39 ( V_60 -> V_3 . V_12 ) )
V_576 &= ~ V_30 ;
if ( V_60 -> V_43 == 0 )
V_576 &= ~ V_50 ;
if ( ! V_86 ) {
V_576 &= ~ V_46 ;
V_408 = 0 ;
V_576 &= ~ V_52 ;
}
if ( ! V_408 )
V_576 &= ~ V_47 ;
if ( ! V_412 )
V_576 &= ~ V_48 ;
return V_576 ;
}
static void F_292 ( void )
{
F_293 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_294 ( struct V_1 * V_60 )
{
#ifdef F_75
unsigned long V_577 ;
#endif
int V_62 ;
F_82 ( V_578 , F_55 ( V_579 ) ) ;
F_82 ( V_580 , F_55 ( V_581 ) ) ;
if ( F_17 () )
F_82 ( V_264 , F_55 ( V_263 ) ) ;
F_82 ( V_582 , - 1ull ) ;
F_81 ( V_583 ,
V_24 . V_53 ) ;
F_81 ( V_473 , F_290 ( V_60 ) ) ;
if ( F_21 () ) {
F_81 ( V_584 ,
F_291 ( V_60 ) ) ;
}
if ( V_412 ) {
F_81 ( V_585 , V_412 ) ;
F_81 ( V_586 , V_587 ) ;
}
F_81 ( V_588 , 0 ) ;
F_81 ( V_589 , 0 ) ;
F_81 ( V_590 , 0 ) ;
F_80 ( V_181 , 0 ) ;
F_80 ( V_185 , 0 ) ;
F_285 () ;
#ifdef F_75
F_109 ( V_191 , V_577 ) ;
F_78 ( V_190 , V_577 ) ;
F_109 ( V_193 , V_577 ) ;
F_78 ( V_192 , V_577 ) ;
#else
F_78 ( V_190 , 0 ) ;
F_78 ( V_192 , 0 ) ;
#endif
F_81 ( V_591 , 0 ) ;
F_81 ( V_139 , 0 ) ;
F_82 ( V_592 , F_55 ( V_60 -> V_125 . V_137 ) ) ;
F_81 ( V_138 , 0 ) ;
F_82 ( V_593 , F_55 ( V_60 -> V_125 . V_136 ) ) ;
if ( V_24 . V_349 & V_292 ) {
T_2 V_594 , V_595 ;
T_5 V_596 ;
F_169 ( V_348 , V_594 , V_595 ) ;
V_596 = V_594 | ( ( T_5 ) V_595 << 32 ) ;
F_82 ( V_350 , V_596 ) ;
V_60 -> V_3 . V_97 . V_351 = V_596 ;
}
for ( V_62 = 0 ; V_62 < V_597 ; ++ V_62 ) {
T_2 V_66 = V_64 [ V_62 ] ;
T_2 V_598 , V_599 ;
int V_600 = V_60 -> V_63 ;
if ( F_295 ( V_66 , & V_598 , & V_599 ) < 0 )
continue;
if ( F_296 ( V_66 , V_598 , V_599 ) < 0 )
continue;
V_60 -> V_65 [ V_600 ] . V_66 = V_62 ;
V_60 -> V_65 [ V_600 ] . V_166 = 0 ;
V_60 -> V_65 [ V_600 ] . V_91 = - 1ull ;
++ V_60 -> V_63 ;
}
F_81 ( V_124 , V_24 . V_398 ) ;
F_81 ( V_123 , V_24 . V_349 ) ;
F_78 ( V_215 , ~ 0UL ) ;
F_289 ( V_60 ) ;
F_181 ( & V_60 -> V_3 , 0 ) ;
return 0 ;
}
static int F_297 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_5 V_61 ;
int V_95 ;
V_3 -> V_97 . V_98 = ~ ( ( 1 << V_357 ) | ( 1 << V_354 ) ) ;
V_60 -> V_117 . V_118 = 0 ;
V_60 -> V_601 = 0 ;
V_60 -> V_3 . V_97 . V_355 [ V_602 ] = F_298 () ;
F_299 ( & V_60 -> V_3 , 0 ) ;
V_61 = 0xfee00000 | V_603 ;
if ( F_300 ( & V_60 -> V_3 ) )
V_61 |= V_604 ;
F_301 ( & V_60 -> V_3 , V_61 ) ;
V_95 = F_302 ( & V_60 -> V_3 ) ;
if ( V_95 != 0 )
goto V_527;
F_85 ( V_60 ) ;
F_272 ( V_453 ) ;
if ( F_300 ( & V_60 -> V_3 ) ) {
F_80 ( V_437 , 0xf000 ) ;
F_78 ( V_506 , 0x000f0000 ) ;
} else {
F_80 ( V_437 , V_60 -> V_3 . V_97 . V_605 << 8 ) ;
F_78 ( V_506 , V_60 -> V_3 . V_97 . V_605 << 12 ) ;
}
F_272 ( V_432 ) ;
F_272 ( V_431 ) ;
F_272 ( V_434 ) ;
F_272 ( V_433 ) ;
F_272 ( V_452 ) ;
F_80 ( V_423 , 0 ) ;
F_78 ( V_424 , 0 ) ;
F_81 ( V_425 , 0xffff ) ;
F_81 ( V_426 , 0x008b ) ;
F_80 ( V_606 , 0 ) ;
F_78 ( V_607 , 0 ) ;
F_81 ( V_608 , 0xffff ) ;
F_81 ( V_609 , 0x00082 ) ;
F_81 ( V_344 , 0 ) ;
F_78 ( V_347 , 0 ) ;
F_78 ( V_346 , 0 ) ;
F_78 ( V_226 , 0x02 ) ;
if ( F_300 ( & V_60 -> V_3 ) )
F_146 ( V_3 , 0xfff0 ) ;
else
F_146 ( V_3 , 0 ) ;
F_303 ( V_3 , V_354 , 0 ) ;
F_78 ( V_363 , 0x400 ) ;
F_78 ( V_513 , 0 ) ;
F_81 ( V_512 , 0xffff ) ;
F_78 ( V_511 , 0 ) ;
F_81 ( V_510 , 0xffff ) ;
F_81 ( V_610 , V_611 ) ;
F_81 ( V_232 , 0 ) ;
F_81 ( V_612 , 0 ) ;
F_82 ( V_613 , 0 ) ;
F_155 ( V_60 ) ;
F_81 ( V_251 , 0 ) ;
if ( F_18 () ) {
F_82 ( V_614 , 0 ) ;
if ( F_19 ( V_60 -> V_3 . V_12 ) )
F_82 ( V_614 ,
F_55 ( V_60 -> V_3 . V_97 . V_615 -> V_355 ) ) ;
F_81 ( V_616 , 0 ) ;
}
if ( F_39 ( V_60 -> V_3 . V_12 ) )
F_82 ( V_617 ,
F_304 ( V_60 -> V_3 . V_12 -> V_97 . V_544 ) ) ;
if ( V_60 -> V_43 != 0 )
F_80 ( V_618 , V_60 -> V_43 ) ;
V_60 -> V_3 . V_97 . V_209 = V_619 | V_620 | V_621 ;
V_3 -> V_449 = F_225 ( & V_3 -> V_12 -> V_448 ) ;
F_244 ( & V_60 -> V_3 , F_305 ( V_3 ) ) ;
F_223 ( & V_3 -> V_12 -> V_448 , V_3 -> V_449 ) ;
F_242 ( & V_60 -> V_3 , 0 ) ;
F_229 ( & V_60 -> V_3 , 0 ) ;
F_131 ( & V_60 -> V_3 ) ;
F_91 ( & V_60 -> V_3 ) ;
F_67 ( V_60 ) ;
V_95 = 0 ;
V_60 -> V_422 = 0 ;
V_527:
return V_95 ;
}
static bool F_306 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_59 &
V_284 ;
}
static void F_307 ( struct V_2 * V_3 )
{
T_2 V_57 ;
if ( F_92 ( V_3 ) && F_306 ( V_3 ) ) {
F_125 ( V_622 , V_3 ) ;
return;
}
V_57 = F_73 ( V_473 ) ;
V_57 |= V_297 ;
F_81 ( V_473 , V_57 ) ;
}
static void F_308 ( struct V_2 * V_3 )
{
T_2 V_57 ;
if ( ! F_43 () ) {
F_307 ( V_3 ) ;
return;
}
if ( F_73 ( V_232 ) & V_233 ) {
F_307 ( V_3 ) ;
return;
}
V_57 = F_73 ( V_473 ) ;
V_57 |= V_623 ;
F_81 ( V_473 , V_57 ) ;
}
static void F_309 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_15 V_624 ;
int V_625 = V_3 -> V_97 . V_626 . V_135 ;
F_310 ( V_625 ) ;
++ V_3 -> V_198 . V_627 ;
if ( V_60 -> V_117 . V_118 ) {
int V_245 = 0 ;
if ( V_3 -> V_97 . V_626 . V_628 )
V_245 = V_3 -> V_97 . V_246 ;
if ( F_151 ( V_3 , V_625 , V_245 ) != V_247 )
F_125 ( V_248 , V_3 ) ;
return;
}
V_624 = V_625 | V_17 ;
if ( V_3 -> V_97 . V_626 . V_628 ) {
V_624 |= V_629 ;
F_81 ( V_249 ,
V_60 -> V_3 . V_97 . V_246 ) ;
} else
V_624 |= V_22 ;
F_81 ( V_251 , V_624 ) ;
}
static void F_311 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( F_92 ( V_3 ) )
return;
if ( ! F_43 () ) {
V_60 -> V_601 = 1 ;
V_60 -> V_630 = 0 ;
}
++ V_3 -> V_198 . V_631 ;
V_60 -> V_632 = false ;
if ( V_60 -> V_117 . V_118 ) {
if ( F_151 ( V_3 , V_633 , 0 ) != V_247 )
F_125 ( V_248 , V_3 ) ;
return;
}
F_81 ( V_251 ,
V_634 | V_17 | V_633 ) ;
}
static int F_312 ( struct V_2 * V_3 )
{
if ( ! F_43 () && F_1 ( V_3 ) -> V_601 )
return 0 ;
return ! ( F_73 ( V_232 ) &
( V_235 | V_233
| V_635 ) ) ;
}
static bool F_313 ( struct V_2 * V_3 )
{
if ( ! F_43 () )
return F_1 ( V_3 ) -> V_601 ;
if ( F_1 ( V_3 ) -> V_632 )
return false ;
return F_73 ( V_232 ) & V_635 ;
}
static void F_314 ( struct V_2 * V_3 , bool V_636 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( ! F_43 () ) {
if ( V_60 -> V_601 != V_636 ) {
V_60 -> V_601 = V_636 ;
V_60 -> V_630 = 0 ;
}
} else {
V_60 -> V_632 = ! V_636 ;
if ( V_636 )
F_84 ( V_232 ,
V_635 ) ;
else
F_83 ( V_232 ,
V_635 ) ;
}
}
static int F_315 ( struct V_2 * V_3 )
{
if ( F_92 ( V_3 ) && F_306 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_637 ||
( V_7 -> V_638 &
V_639 ) )
return 0 ;
F_148 ( V_3 ) ;
V_7 -> V_640 = V_641 ;
V_7 -> V_642 = 0 ;
}
return ( F_71 ( V_226 ) & V_643 ) &&
! ( F_73 ( V_232 ) &
( V_233 | V_235 ) ) ;
}
static int F_224 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_95 ;
struct V_541 V_644 = {
. V_443 = V_645 ,
. V_546 = V_11 ,
. V_547 = V_394 * 3 ,
. V_421 = 0 ,
} ;
V_95 = F_316 ( V_12 , & V_644 , 0 ) ;
if ( V_95 )
return V_95 ;
V_12 -> V_97 . V_439 = V_11 ;
if ( ! F_267 ( V_12 ) )
return - V_405 ;
return 0 ;
}
static int F_317 ( struct V_2 * V_3 ,
int V_646 , T_2 V_647 )
{
if ( ( ( V_646 == V_320 ) || ( V_646 == V_648 ) ) && V_647 == 0 )
if ( F_318 ( V_3 , 0 ) == V_247 )
return 1 ;
switch ( V_646 ) {
case V_112 :
if ( V_3 -> V_113 &
( V_649 | V_362 ) )
return 0 ;
F_319 ( V_3 , V_646 ) ;
return 1 ;
case V_116 :
F_1 ( V_3 ) -> V_3 . V_97 . V_246 =
F_73 ( V_239 ) ;
if ( V_3 -> V_113 & V_115 )
return 0 ;
case V_650 :
case V_651 :
case V_652 :
case V_21 :
case V_653 :
case V_648 :
case V_320 :
case V_654 :
F_319 ( V_3 , V_646 ) ;
return 1 ;
}
return 0 ;
}
static void F_320 ( void )
{
#if F_321 ( V_655 ) && F_321 ( F_75 )
struct V_656 V_355 = {
. V_514 = 3 ,
. V_421 = V_643 ,
} ;
F_322 ( & V_355 , 0 ) ;
#endif
}
static int F_323 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_324 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_657 * V_657 = V_3 -> V_658 ;
T_2 V_14 , V_659 , V_241 ;
unsigned long V_660 , V_238 , V_661 ;
T_2 V_662 ;
enum V_663 V_664 ;
V_662 = V_60 -> V_665 ;
V_14 = V_60 -> V_666 ;
if ( F_16 ( V_14 ) )
return F_323 ( V_3 ) ;
if ( ( V_662 & V_639 ) &&
! F_12 ( V_14 ) ) {
V_3 -> V_658 -> V_667 = V_668 ;
V_3 -> V_658 -> V_669 . V_670 = V_671 ;
V_3 -> V_658 -> V_669 . V_672 = 2 ;
V_3 -> V_658 -> V_669 . V_166 [ 0 ] = V_662 ;
V_3 -> V_658 -> V_669 . V_166 [ 1 ] = V_14 ;
return 0 ;
}
if ( ( V_14 & V_15 ) == V_634 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_131 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_664 = F_318 ( V_3 , V_673 ) ;
if ( V_664 != V_247 )
F_319 ( V_3 , V_21 ) ;
return 1 ;
}
V_241 = 0 ;
if ( V_14 & V_244 )
V_241 = F_73 ( V_674 ) ;
if ( F_12 ( V_14 ) ) {
F_325 ( V_86 ) ;
V_660 = F_71 ( V_675 ) ;
F_326 ( V_660 , V_241 ) ;
if ( F_327 ( V_3 ) )
F_328 ( V_3 , V_660 ) ;
return F_329 ( V_3 , V_660 , V_241 , NULL , 0 ) ;
}
if ( V_60 -> V_117 . V_118 &&
F_317 ( V_3 , V_14 & V_16 ,
V_241 ) ) {
if ( V_3 -> V_97 . V_676 ) {
V_3 -> V_97 . V_676 = 0 ;
return F_330 ( V_3 ) ;
}
return 1 ;
}
V_659 = V_14 & V_16 ;
switch ( V_659 ) {
case V_112 :
V_661 = F_71 ( V_675 ) ;
if ( ! ( V_3 -> V_113 &
( V_649 | V_362 ) ) ) {
V_3 -> V_97 . V_661 = V_661 | V_677 ;
F_319 ( V_3 , V_112 ) ;
return 1 ;
}
V_657 -> V_678 . V_97 . V_661 = V_661 | V_677 ;
V_657 -> V_678 . V_97 . V_365 = F_71 ( V_363 ) ;
case V_116 :
V_60 -> V_3 . V_97 . V_246 =
F_73 ( V_239 ) ;
V_657 -> V_667 = V_679 ;
V_238 = F_145 ( V_3 ) ;
V_657 -> V_678 . V_97 . V_680 = F_71 ( V_506 ) + V_238 ;
V_657 -> V_678 . V_97 . V_681 = V_659 ;
break;
default:
V_657 -> V_667 = V_682 ;
V_657 -> V_683 . V_681 = V_659 ;
V_657 -> V_683 . V_241 = V_241 ;
break;
}
return 0 ;
}
static int F_331 ( struct V_2 * V_3 )
{
++ V_3 -> V_198 . V_684 ;
return 1 ;
}
static int F_332 ( struct V_2 * V_3 )
{
V_3 -> V_658 -> V_667 = V_685 ;
return 0 ;
}
static int F_333 ( struct V_2 * V_3 )
{
unsigned long V_686 ;
int V_395 , V_687 , string ;
unsigned V_688 ;
V_686 = F_71 ( V_675 ) ;
string = ( V_686 & 16 ) != 0 ;
V_687 = ( V_686 & 8 ) != 0 ;
++ V_3 -> V_198 . V_689 ;
if ( string || V_687 )
return F_318 ( V_3 , 0 ) == V_247 ;
V_688 = V_686 >> 16 ;
V_395 = ( V_686 & 7 ) + 1 ;
F_144 ( V_3 ) ;
return F_334 ( V_3 , V_395 , V_688 ) ;
}
static void
F_335 ( struct V_2 * V_3 , unsigned char * V_690 )
{
V_690 [ 0 ] = 0x0f ;
V_690 [ 1 ] = 0x01 ;
V_690 [ 2 ] = 0xc1 ;
}
static int F_336 ( struct V_2 * V_3 , unsigned long V_691 )
{
if ( F_1 ( V_3 ) -> V_8 . V_491 &&
( ( V_691 & F_174 ) != F_174 ) )
return 1 ;
if ( F_92 ( V_3 ) ) {
if ( F_337 ( V_3 , ( V_691 & V_3 -> V_97 . V_213 ) |
( V_3 -> V_97 . V_209 & ~ V_3 -> V_97 . V_213 ) ) )
return 1 ;
F_78 ( V_222 , V_691 ) ;
return 0 ;
} else
return F_337 ( V_3 , V_691 ) ;
}
static int F_338 ( struct V_2 * V_3 , unsigned long V_691 )
{
if ( F_92 ( V_3 ) ) {
if ( F_339 ( V_3 , ( V_691 & V_3 -> V_97 . V_463 ) |
( V_3 -> V_97 . V_464 & ~ V_3 -> V_97 . V_463 ) ) )
return 1 ;
F_78 ( V_429 , V_691 ) ;
return 0 ;
} else
return F_339 ( V_3 , V_691 ) ;
}
static void F_340 ( struct V_2 * V_3 )
{
if ( F_92 ( V_3 ) ) {
F_78 ( V_222 ,
F_71 ( V_222 ) & ~ V_211 ) ;
V_3 -> V_97 . V_209 &= ~ V_211 ;
} else
F_244 ( V_3 , F_132 ( V_3 , ~ V_211 ) ) ;
}
static int F_341 ( struct V_2 * V_3 )
{
unsigned long V_686 , V_691 ;
int V_692 ;
int V_353 ;
int V_693 ;
V_686 = F_71 ( V_675 ) ;
V_692 = V_686 & 15 ;
V_353 = ( V_686 >> 8 ) & 15 ;
switch ( ( V_686 >> 4 ) & 3 ) {
case 0 :
V_691 = F_342 ( V_3 , V_353 ) ;
F_343 ( V_692 , V_691 ) ;
switch ( V_692 ) {
case 0 :
V_693 = F_336 ( V_3 , V_691 ) ;
F_344 ( V_3 , V_693 ) ;
return 1 ;
case 3 :
V_693 = F_345 ( V_3 , V_691 ) ;
F_344 ( V_3 , V_693 ) ;
return 1 ;
case 4 :
V_693 = F_338 ( V_3 , V_691 ) ;
F_344 ( V_3 , V_693 ) ;
return 1 ;
case 8 : {
T_6 V_694 = F_346 ( V_3 ) ;
T_6 V_695 = F_342 ( V_3 , V_353 ) ;
V_693 = F_299 ( V_3 , V_695 ) ;
F_344 ( V_3 , V_693 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_694 <= V_695 )
return 1 ;
V_3 -> V_658 -> V_667 = V_696 ;
return 0 ;
}
} ;
break;
case 2 :
F_340 ( V_3 ) ;
F_343 ( 0 , F_305 ( V_3 ) ) ;
F_144 ( V_3 ) ;
F_131 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_692 ) {
case 3 :
V_691 = F_246 ( V_3 ) ;
F_303 ( V_3 , V_353 , V_691 ) ;
F_347 ( V_692 , V_691 ) ;
F_144 ( V_3 ) ;
return 1 ;
case 8 :
V_691 = F_346 ( V_3 ) ;
F_303 ( V_3 , V_353 , V_691 ) ;
F_347 ( V_692 , V_691 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_691 = ( V_686 >> V_697 ) & 0x0f ;
F_343 ( 0 , ( F_305 ( V_3 ) & ~ 0xful ) | V_691 ) ;
F_348 ( V_3 , V_691 ) ;
F_144 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_658 -> V_667 = 0 ;
F_349 ( V_3 , L_19 ,
( int ) ( V_686 >> 4 ) & 3 , V_692 ) ;
return 0 ;
}
static int F_350 ( struct V_2 * V_3 )
{
unsigned long V_686 ;
int V_698 , V_353 ;
if ( ! F_351 ( V_3 , 0 ) )
return 1 ;
V_698 = F_71 ( V_363 ) ;
if ( V_698 & V_699 ) {
if ( V_3 -> V_113 & V_362 ) {
V_3 -> V_658 -> V_678 . V_97 . V_661 = V_3 -> V_97 . V_661 ;
V_3 -> V_658 -> V_678 . V_97 . V_365 = V_698 ;
V_3 -> V_658 -> V_678 . V_97 . V_680 =
F_71 ( V_506 ) +
F_71 ( V_358 ) ;
V_3 -> V_658 -> V_678 . V_97 . V_681 = V_112 ;
V_3 -> V_658 -> V_667 = V_679 ;
return 0 ;
} else {
V_3 -> V_97 . V_365 &= ~ V_699 ;
V_3 -> V_97 . V_661 |= V_700 ;
F_78 ( V_363 , V_3 -> V_97 . V_365 ) ;
F_319 ( V_3 , V_112 ) ;
return 1 ;
}
}
V_686 = F_71 ( V_675 ) ;
V_698 = V_686 & V_701 ;
V_353 = F_352 ( V_686 ) ;
if ( V_686 & V_702 ) {
unsigned long V_691 ;
if ( ! F_353 ( V_3 , V_698 , & V_691 ) )
F_303 ( V_3 , V_353 , V_691 ) ;
} else
F_354 ( V_3 , V_698 , V_3 -> V_97 . V_355 [ V_353 ] ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static void F_355 ( struct V_2 * V_3 , unsigned long V_691 )
{
F_78 ( V_363 , V_691 ) ;
}
static int F_356 ( struct V_2 * V_3 )
{
F_357 ( V_3 ) ;
return 1 ;
}
static int F_358 ( struct V_2 * V_3 )
{
T_2 V_280 = V_3 -> V_97 . V_355 [ V_703 ] ;
T_5 V_166 ;
if ( F_177 ( V_3 , V_280 , & V_166 ) ) {
F_359 ( V_280 ) ;
F_360 ( V_3 , 0 ) ;
return 1 ;
}
F_361 ( V_280 , V_166 ) ;
V_3 -> V_97 . V_355 [ V_704 ] = V_166 & - 1u ;
V_3 -> V_97 . V_355 [ V_602 ] = ( V_166 >> 32 ) & - 1u ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_362 ( struct V_2 * V_3 )
{
T_2 V_280 = V_3 -> V_97 . V_355 [ V_703 ] ;
T_5 V_166 = ( V_3 -> V_97 . V_355 [ V_704 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_97 . V_355 [ V_602 ] & - 1u ) << 32 ) ;
if ( F_179 ( V_3 , V_280 , V_166 ) != 0 ) {
F_363 ( V_280 , V_166 ) ;
F_360 ( V_3 , 0 ) ;
return 1 ;
}
F_364 ( V_280 , V_166 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_365 ( struct V_2 * V_3 )
{
F_125 ( V_705 , V_3 ) ;
return 1 ;
}
static int F_366 ( struct V_2 * V_3 )
{
T_2 V_57 ;
V_57 = F_73 ( V_473 ) ;
V_57 &= ~ V_297 ;
F_81 ( V_473 , V_57 ) ;
F_125 ( V_705 , V_3 ) ;
++ V_3 -> V_198 . V_706 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_658 -> V_707 &&
! F_367 ( V_3 ) ) {
V_3 -> V_658 -> V_667 = V_708 ;
return 0 ;
}
return 1 ;
}
static int F_368 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
return F_330 ( V_3 ) ;
}
static int F_369 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_370 ( V_3 ) ;
return 1 ;
}
static int F_371 ( struct V_2 * V_3 )
{
return F_318 ( V_3 , 0 ) == V_247 ;
}
static int F_372 ( struct V_2 * V_3 )
{
unsigned long V_686 = F_71 ( V_675 ) ;
F_373 ( V_3 , V_686 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_374 ( struct V_2 * V_3 )
{
int V_693 ;
V_693 = F_375 ( V_3 ) ;
F_344 ( V_3 , V_693 ) ;
return 1 ;
}
static int F_376 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_377 ( V_3 ) ;
return 1 ;
}
static int F_378 ( struct V_2 * V_3 )
{
T_5 V_709 = F_379 ( V_3 ) ;
T_2 V_66 = F_342 ( V_3 , V_703 ) ;
if ( F_380 ( V_3 , V_66 , V_709 ) == 0 )
F_144 ( V_3 ) ;
return 1 ;
}
static int F_381 ( struct V_2 * V_3 )
{
if ( F_271 ( V_710 ) ) {
unsigned long V_686 = F_71 ( V_675 ) ;
int V_711 , V_274 ;
V_711 = V_686 & V_712 ;
V_274 = V_686 & V_713 ;
if ( ( V_711 == V_714 ) &&
( V_274 == V_715 ) ) {
F_382 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
}
return F_318 ( V_3 , 0 ) == V_247 ;
}
static int F_383 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned long V_686 ;
bool V_240 = false ;
T_2 V_241 = 0 ;
T_3 V_716 ;
int V_717 , type , V_718 , V_719 ;
V_718 = ( V_60 -> V_665 & V_639 ) ;
V_719 = ( V_60 -> V_665 & V_720 ) ;
type = ( V_60 -> V_665 & V_721 ) ;
V_686 = F_71 ( V_675 ) ;
V_717 = ( T_2 ) V_686 >> 30 ;
if ( V_717 == V_722 && V_718 ) {
switch ( type ) {
case V_634 :
V_3 -> V_97 . V_723 = false ;
F_314 ( V_3 , true ) ;
break;
case V_22 :
case V_629 :
F_384 ( V_3 ) ;
break;
case V_18 :
if ( V_60 -> V_665 &
V_724 ) {
V_240 = true ;
V_241 =
F_73 ( V_725 ) ;
}
case V_250 :
F_385 ( V_3 ) ;
break;
default:
break;
}
}
V_716 = V_686 ;
if ( ! V_718 || ( type != V_18 &&
type != V_22 &&
type != V_634 ) )
F_144 ( V_3 ) ;
if ( F_386 ( V_3 , V_716 ,
type == V_629 ? V_719 : - 1 , V_717 ,
V_240 , V_241 ) == V_726 ) {
V_3 -> V_658 -> V_667 = V_668 ;
V_3 -> V_658 -> V_669 . V_670 = V_727 ;
V_3 -> V_658 -> V_669 . V_672 = 0 ;
return 0 ;
}
F_78 ( V_363 , F_71 ( V_363 ) & ~ 55 ) ;
return 1 ;
}
static int F_387 ( struct V_2 * V_3 )
{
unsigned long V_686 ;
T_1 V_72 ;
T_2 V_241 ;
int V_728 ;
V_686 = F_71 ( V_675 ) ;
if ( V_686 & ( 1 << 6 ) ) {
F_56 ( V_76 L_20 ) ;
return - V_339 ;
}
V_728 = ( V_686 >> 7 ) & 0x3 ;
if ( V_728 != 0x3 && V_728 != 0x1 && V_728 != 0 ) {
F_56 ( V_76 L_21 ) ;
F_56 ( V_76 L_22 ,
( long unsigned int ) F_74 ( V_729 ) ,
F_71 ( V_730 ) ) ;
F_56 ( V_76 L_23 ,
( long unsigned int ) V_686 ) ;
V_3 -> V_658 -> V_667 = V_731 ;
V_3 -> V_658 -> V_732 . V_733 = V_734 ;
return 0 ;
}
V_72 = F_74 ( V_729 ) ;
F_326 ( V_72 , V_686 ) ;
V_241 = V_686 & ( 1U << 1 ) ;
V_241 |= ( V_686 >> 3 ) & 0x1 ;
return F_329 ( V_3 , V_72 , V_241 , NULL , 0 ) ;
}
static T_5 F_388 ( T_5 V_735 , int V_736 )
{
int V_62 ;
T_5 V_91 = 0 ;
for ( V_62 = 51 ; V_62 > V_399 . V_737 ; V_62 -- )
V_91 |= ( 1ULL << V_62 ) ;
if ( V_736 > 2 )
V_91 |= 0xf8 ;
else if ( V_736 == 2 ) {
if ( V_735 & ( 1ULL << 7 ) )
V_91 |= 0x1ff000 ;
else
V_91 |= 0x78 ;
}
return V_91 ;
}
static void F_389 ( struct V_2 * V_3 , T_5 V_735 ,
int V_736 )
{
F_56 ( V_76 L_24 , V_457 , V_735 , V_736 ) ;
F_390 ( ( V_735 & 0x7 ) == 0x2 ) ;
F_390 ( ( V_735 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_390 ( ( V_735 & 0x7 ) == 0x4 ) ;
if ( ( V_735 & 0x7 ) ) {
T_5 V_738 = V_735 & F_388 ( V_735 , V_736 ) ;
if ( V_738 != 0 ) {
F_56 ( V_76 L_25 ,
V_457 , V_738 ) ;
F_390 ( 1 ) ;
}
if ( V_736 == 1 || ( V_736 == 2 && ( V_735 & ( 1ULL << 7 ) ) ) ) {
T_5 V_739 = ( V_735 & 0x38 ) >> 3 ;
if ( V_739 == 2 || V_739 == 3 ||
V_739 == 7 ) {
F_56 ( V_76 L_26 ,
V_457 , V_739 ) ;
F_390 ( 1 ) ;
}
}
}
}
static int F_391 ( struct V_2 * V_3 )
{
T_5 V_740 [ 4 ] ;
int V_741 , V_62 , V_95 ;
T_1 V_72 ;
V_72 = F_74 ( V_729 ) ;
V_95 = F_392 ( V_3 , V_72 , true ) ;
if ( F_271 ( V_95 == 1 ) )
return F_393 ( V_3 , V_72 , 0 , NULL , 0 ) ==
V_247 ;
if ( F_79 ( ! V_95 ) )
return 1 ;
F_56 ( V_76 L_27 ) ;
F_56 ( V_76 L_28 , V_72 ) ;
V_741 = F_394 ( V_3 , V_72 , V_740 ) ;
for ( V_62 = V_742 ; V_62 > V_742 - V_741 ; -- V_62 )
F_389 ( V_3 , V_740 [ V_62 - 1 ] , V_62 ) ;
V_3 -> V_658 -> V_667 = V_731 ;
V_3 -> V_658 -> V_732 . V_733 = V_743 ;
return 0 ;
}
static int F_395 ( struct V_2 * V_3 )
{
T_2 V_57 ;
V_57 = F_73 ( V_473 ) ;
V_57 &= ~ V_623 ;
F_81 ( V_473 , V_57 ) ;
++ V_3 -> V_198 . V_744 ;
F_125 ( V_705 , V_3 ) ;
return 1 ;
}
static int F_396 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
enum V_663 V_693 = V_247 ;
int V_95 = 1 ;
T_2 V_745 ;
bool V_746 ;
unsigned V_747 = 130 ;
V_745 = F_73 ( V_473 ) ;
V_746 = V_745 & V_297 ;
while ( ! F_266 ( V_3 ) && V_747 -- != 0 ) {
if ( V_746 && F_315 ( V_3 ) )
return F_366 ( & V_60 -> V_3 ) ;
if ( F_138 ( V_705 , & V_3 -> V_748 ) )
return 1 ;
V_693 = F_318 ( V_3 , 0 ) ;
if ( V_693 == V_749 ) {
V_95 = 0 ;
goto V_527;
}
if ( V_693 != V_247 ) {
V_3 -> V_658 -> V_667 = V_668 ;
V_3 -> V_658 -> V_669 . V_670 = V_727 ;
V_3 -> V_658 -> V_669 . V_672 = 0 ;
return 0 ;
}
if ( F_397 ( V_750 ) )
goto V_527;
if ( F_398 () )
F_399 () ;
}
V_60 -> V_422 = ! F_266 ( V_3 ) ;
V_527:
return V_95 ;
}
static int F_400 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_401 ( V_3 ) ;
return 1 ;
}
static int F_402 ( struct V_2 * V_3 )
{
F_319 ( V_3 , V_21 ) ;
return 1 ;
}
static struct V_77 * F_403 ( struct V_1 * V_60 )
{
struct V_751 * V_752 ;
F_404 (item, &vmx->nested.vmcs02_pool, list)
if ( V_752 -> V_753 == V_60 -> V_8 . V_754 ) {
F_405 ( & V_752 -> V_755 , & V_60 -> V_8 . V_756 ) ;
return & V_752 -> V_757 ;
}
if ( V_60 -> V_8 . V_758 >= F_406 ( V_759 , 1 ) ) {
V_752 = F_407 ( V_60 -> V_8 . V_756 . V_760 ,
struct V_751 , V_755 ) ;
V_752 -> V_753 = V_60 -> V_8 . V_754 ;
F_405 ( & V_752 -> V_755 , & V_60 -> V_8 . V_756 ) ;
return & V_752 -> V_757 ;
}
V_752 = (struct V_751 * )
F_408 ( sizeof( struct V_751 ) , V_404 ) ;
if ( ! V_752 )
return NULL ;
V_752 -> V_757 . V_74 = F_205 () ;
if ( ! V_752 -> V_757 . V_74 ) {
F_409 ( V_752 ) ;
return NULL ;
}
F_57 ( & V_752 -> V_757 ) ;
V_752 -> V_753 = V_60 -> V_8 . V_754 ;
F_127 ( & ( V_752 -> V_755 ) , & ( V_60 -> V_8 . V_756 ) ) ;
V_60 -> V_8 . V_758 ++ ;
return & V_752 -> V_757 ;
}
static void F_410 ( struct V_1 * V_60 , T_1 V_753 )
{
struct V_751 * V_752 ;
F_404 (item, &vmx->nested.vmcs02_pool, list)
if ( V_752 -> V_753 == V_753 ) {
F_208 ( & V_752 -> V_757 ) ;
F_62 ( & V_752 -> V_755 ) ;
F_409 ( V_752 ) ;
V_60 -> V_8 . V_758 -- ;
return;
}
}
static void F_411 ( struct V_1 * V_60 )
{
struct V_751 * V_752 , * V_374 ;
F_195 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_60 -> V_77 != & V_752 -> V_757 )
F_208 ( & V_752 -> V_757 ) ;
F_62 ( & V_752 -> V_755 ) ;
F_409 ( V_752 ) ;
}
V_60 -> V_8 . V_758 = 0 ;
if ( V_60 -> V_77 != & V_60 -> V_761 )
F_208 ( & V_60 -> V_761 ) ;
}
static int F_412 ( struct V_2 * V_3 )
{
struct V_446 V_514 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( ! F_413 ( V_3 , V_372 ) ||
! F_132 ( V_3 , V_479 ) ||
( F_137 ( V_3 ) & V_230 ) ) {
F_319 ( V_3 , V_21 ) ;
return 1 ;
}
F_226 ( V_3 , & V_514 , V_453 ) ;
if ( F_110 ( V_3 ) && ! V_514 . V_499 ) {
F_319 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_252 ( V_3 ) ) {
F_360 ( V_3 , 0 ) ;
return 1 ;
}
F_191 ( & ( V_60 -> V_8 . V_756 ) ) ;
V_60 -> V_8 . V_758 = 0 ;
V_60 -> V_8 . V_491 = true ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_414 ( struct V_2 * V_3 )
{
struct V_446 V_514 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( ! V_60 -> V_8 . V_491 ) {
F_319 ( V_3 , V_21 ) ;
return 0 ;
}
F_226 ( V_3 , & V_514 , V_453 ) ;
if ( ( F_137 ( V_3 ) & V_230 ) ||
( F_110 ( V_3 ) && ! V_514 . V_499 ) ) {
F_319 ( V_3 , V_21 ) ;
return 0 ;
}
if ( F_252 ( V_3 ) ) {
F_360 ( V_3 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_415 ( struct V_1 * V_60 )
{
if ( ! V_60 -> V_8 . V_491 )
return;
V_60 -> V_8 . V_491 = false ;
if ( V_60 -> V_8 . V_754 != - 1ull ) {
F_416 ( V_60 -> V_8 . V_762 ) ;
F_9 ( V_60 -> V_8 . V_762 ) ;
V_60 -> V_8 . V_754 = - 1ull ;
V_60 -> V_8 . V_9 = NULL ;
}
if ( V_60 -> V_8 . V_544 ) {
F_9 ( V_60 -> V_8 . V_544 ) ;
V_60 -> V_8 . V_544 = 0 ;
}
F_411 ( V_60 ) ;
}
static int F_417 ( struct V_2 * V_3 )
{
if ( ! F_414 ( V_3 ) )
return 1 ;
F_415 ( F_1 ( V_3 ) ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_418 ( struct V_2 * V_3 ,
unsigned long V_686 ,
T_2 V_763 , T_4 * V_95 )
{
int V_764 = V_763 & 3 ;
int V_765 = ( V_763 >> 7 ) & 7 ;
bool V_766 = V_763 & ( 1u << 10 ) ;
int V_767 = ( V_763 >> 15 ) & 7 ;
int V_768 = ( V_763 >> 18 ) & 0xf ;
bool V_769 = ! ( V_763 & ( 1u << 22 ) ) ;
int V_770 = ( V_763 >> 23 ) & 0xf ;
bool V_771 = ! ( V_763 & ( 1u << 27 ) ) ;
if ( V_766 ) {
F_319 ( V_3 , V_21 ) ;
return 1 ;
}
* V_95 = F_248 ( V_3 , V_767 ) ;
if ( V_771 )
* V_95 += F_342 ( V_3 , V_770 ) ;
if ( V_769 )
* V_95 += F_342 ( V_3 , V_768 ) << V_764 ;
* V_95 += V_686 ;
if ( V_765 == 1 )
* V_95 &= 0xffffffff ;
return 0 ;
}
static void F_419 ( struct V_2 * V_3 )
{
F_140 ( V_3 , F_137 ( V_3 )
& ~ ( V_772 | V_773 | V_774 |
V_775 | V_776 | V_777 ) ) ;
}
static void F_420 ( struct V_2 * V_3 )
{
F_140 ( V_3 , ( F_137 ( V_3 )
& ~ ( V_773 | V_774 | V_775 |
V_776 | V_777 ) )
| V_772 ) ;
}
static void F_421 ( struct V_2 * V_3 ,
T_2 V_778 )
{
if ( F_1 ( V_3 ) -> V_8 . V_754 == - 1ull ) {
F_420 ( V_3 ) ;
return;
}
F_140 ( V_3 , ( F_137 ( V_3 )
& ~ ( V_772 | V_773 | V_774 |
V_776 | V_777 ) )
| V_775 ) ;
F_4 ( V_3 ) -> V_778 = V_778 ;
}
static int F_422 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_4 V_68 ;
T_1 V_753 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_779 V_780 ;
if ( ! F_414 ( V_3 ) )
return 1 ;
if ( F_418 ( V_3 , F_71 ( V_675 ) ,
F_73 ( V_781 ) , & V_68 ) )
return 1 ;
if ( F_423 ( & V_3 -> V_97 . V_782 , V_68 , & V_753 ,
sizeof( V_753 ) , & V_780 ) ) {
F_424 ( V_3 , & V_780 ) ;
return 1 ;
}
if ( ! F_425 ( V_753 , V_394 ) ) {
F_421 ( V_3 , V_783 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_753 == V_60 -> V_8 . V_754 ) {
F_416 ( V_60 -> V_8 . V_762 ) ;
F_9 ( V_60 -> V_8 . V_762 ) ;
V_60 -> V_8 . V_754 = - 1ull ;
V_60 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_753 ) ;
if ( V_10 == NULL ) {
F_125 ( V_248 , V_3 ) ;
return 1 ;
}
V_7 = F_426 ( V_10 ) ;
V_7 -> V_784 = 0 ;
F_416 ( V_10 ) ;
F_9 ( V_10 ) ;
F_410 ( V_60 , V_753 ) ;
F_144 ( V_3 ) ;
F_419 ( V_3 ) ;
return 1 ;
}
static int F_427 ( struct V_2 * V_3 )
{
return F_428 ( V_3 , true ) ;
}
static int F_429 ( struct V_2 * V_3 )
{
return F_428 ( V_3 , false ) ;
}
static inline int F_430 ( unsigned long V_4 )
{
if ( 0x1 & V_4 )
return V_785 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_431 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_432 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_95 )
{
short V_274 = F_3 ( V_4 ) ;
char * V_100 ;
if ( V_274 < 0 )
return 0 ;
V_100 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_274 ;
switch ( F_430 ( V_4 ) ) {
case V_786 :
* V_95 = * ( ( V_787 * ) V_100 ) ;
return 1 ;
case V_788 :
* V_95 = * ( ( T_3 * ) V_100 ) ;
return 1 ;
case V_785 :
* V_95 = * ( ( T_2 * ) V_100 ) ;
return 1 ;
case V_789 :
* V_95 = * ( ( T_5 * ) V_100 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_433 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( V_60 -> V_8 . V_754 == - 1ull ) {
F_420 ( V_3 ) ;
F_144 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_434 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_790 ;
unsigned long V_686 = F_71 ( V_675 ) ;
T_2 V_763 = F_73 ( V_781 ) ;
T_4 V_68 = 0 ;
if ( ! F_414 ( V_3 ) ||
! F_433 ( V_3 ) )
return 1 ;
V_4 = F_342 ( V_3 , ( ( ( V_763 ) >> 28 ) & 0xf ) ) ;
if ( ! F_432 ( V_3 , V_4 , & V_790 ) ) {
F_421 ( V_3 , V_791 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_763 & ( 1u << 10 ) ) {
F_303 ( V_3 , ( ( ( V_763 ) >> 3 ) & 0xf ) ,
V_790 ) ;
} else {
if ( F_418 ( V_3 , V_686 ,
V_763 , & V_68 ) )
return 1 ;
F_435 ( & V_3 -> V_97 . V_782 , V_68 ,
& V_790 , ( F_110 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_419 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_436 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_68 ;
unsigned long V_686 = F_71 ( V_675 ) ;
T_2 V_763 = F_73 ( V_781 ) ;
char * V_100 ;
short V_274 ;
T_5 V_790 = 0 ;
struct V_779 V_780 ;
if ( ! F_414 ( V_3 ) ||
! F_433 ( V_3 ) )
return 1 ;
if ( V_763 & ( 1u << 10 ) )
V_790 = F_342 ( V_3 ,
( ( ( V_763 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_418 ( V_3 , V_686 ,
V_763 , & V_68 ) )
return 1 ;
if ( F_423 ( & V_3 -> V_97 . V_782 , V_68 ,
& V_790 , ( F_110 ( V_3 ) ? 8 : 4 ) , & V_780 ) ) {
F_424 ( V_3 , & V_780 ) ;
return 1 ;
}
}
V_4 = F_342 ( V_3 , ( ( ( V_763 ) >> 28 ) & 0xf ) ) ;
if ( F_431 ( V_4 ) ) {
F_421 ( V_3 ,
V_792 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
V_274 = F_3 ( V_4 ) ;
if ( V_274 < 0 ) {
F_421 ( V_3 , V_791 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
V_100 = ( ( char * ) F_4 ( V_3 ) ) + V_274 ;
switch ( F_430 ( V_4 ) ) {
case V_788 :
* ( T_3 * ) V_100 = V_790 ;
break;
case V_785 :
* ( T_2 * ) V_100 = V_790 ;
break;
case V_789 :
* ( T_5 * ) V_100 = V_790 ;
break;
case V_786 :
* ( V_787 * ) V_100 = V_790 ;
break;
default:
F_421 ( V_3 , V_791 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
F_419 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_437 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_4 V_68 ;
T_1 V_753 ;
struct V_779 V_780 ;
if ( ! F_414 ( V_3 ) )
return 1 ;
if ( F_418 ( V_3 , F_71 ( V_675 ) ,
F_73 ( V_781 ) , & V_68 ) )
return 1 ;
if ( F_423 ( & V_3 -> V_97 . V_782 , V_68 , & V_753 ,
sizeof( V_753 ) , & V_780 ) ) {
F_424 ( V_3 , & V_780 ) ;
return 1 ;
}
if ( ! F_425 ( V_753 , V_394 ) ) {
F_421 ( V_3 , V_793 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_60 -> V_8 . V_754 != V_753 ) {
struct V_7 * V_794 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_753 ) ;
if ( V_10 == NULL ) {
F_420 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
V_794 = F_426 ( V_10 ) ;
if ( V_794 -> V_397 != V_322 ) {
F_416 ( V_10 ) ;
F_11 ( V_10 ) ;
F_421 ( V_3 ,
V_795 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_60 -> V_8 . V_754 != - 1ull ) {
F_416 ( V_60 -> V_8 . V_762 ) ;
F_9 ( V_60 -> V_8 . V_762 ) ;
}
V_60 -> V_8 . V_754 = V_753 ;
V_60 -> V_8 . V_9 = V_794 ;
V_60 -> V_8 . V_762 = V_10 ;
}
F_419 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_438 ( struct V_2 * V_3 )
{
unsigned long V_686 = F_71 ( V_675 ) ;
T_2 V_763 = F_73 ( V_781 ) ;
T_4 V_796 ;
struct V_779 V_780 ;
if ( ! F_414 ( V_3 ) )
return 1 ;
if ( F_418 ( V_3 , V_686 ,
V_763 , & V_796 ) )
return 1 ;
if ( F_435 ( & V_3 -> V_97 . V_782 , V_796 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_754 ,
sizeof( T_5 ) , & V_780 ) ) {
F_424 ( V_3 , & V_780 ) ;
return 1 ;
}
F_419 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static bool F_439 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_667 )
{
T_2 V_316 = V_3 -> V_97 . V_355 [ V_703 ] ;
T_1 V_797 ;
if ( ! F_46 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_797 = V_7 -> V_255 ;
if ( V_667 == V_798 )
V_797 += 2048 ;
if ( V_316 >= 0xc0000000 ) {
V_316 -= 0xc0000000 ;
V_797 += 1024 ;
}
if ( V_316 < 1024 * 8 ) {
unsigned char V_799 ;
F_440 ( V_3 -> V_12 , V_797 + V_316 / 8 , & V_799 , 1 ) ;
return 1 & ( V_799 >> ( V_316 & 7 ) ) ;
} else
return 1 ;
}
static bool F_441 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_686 = F_71 ( V_675 ) ;
int V_692 = V_686 & 15 ;
int V_353 = ( V_686 >> 8 ) & 15 ;
unsigned long V_691 = F_342 ( V_3 , V_353 ) ;
switch ( ( V_686 >> 4 ) & 3 ) {
case 0 :
switch ( V_692 ) {
case 0 :
if ( V_7 -> V_214 &
( V_691 ^ V_7 -> V_218 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_800 >= 1 &&
V_7 -> V_801 == V_691 ) ||
( V_7 -> V_800 >= 2 &&
V_7 -> V_802 == V_691 ) ||
( V_7 -> V_800 >= 3 &&
V_7 -> V_803 == V_691 ) ||
( V_7 -> V_800 >= 4 &&
V_7 -> V_804 == V_691 ) )
return 0 ;
if ( F_46 ( V_7 , V_301 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_220 &
( V_7 -> V_221 ^ V_691 ) )
return 1 ;
break;
case 8 :
if ( F_46 ( V_7 , V_303 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_214 & V_211 ) &&
( V_7 -> V_218 & V_211 ) )
return 1 ;
break;
case 1 :
switch ( V_692 ) {
case 3 :
if ( V_7 -> V_57 &
V_302 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_57 &
V_304 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_214 & 0xe &
( V_691 ^ V_7 -> V_218 ) )
return 1 ;
if ( ( V_7 -> V_214 & 0x1 ) &&
! ( V_7 -> V_218 & 0x1 ) &&
( V_691 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_442 ( struct V_2 * V_3 )
{
T_2 V_667 = F_73 ( V_805 ) ;
T_2 V_14 = F_73 ( V_806 ) ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_60 -> V_8 . V_637 )
return 0 ;
if ( F_79 ( V_60 -> V_807 ) ) {
F_443 ( L_29 , V_457 ,
F_73 ( V_90 ) ) ;
return 1 ;
}
switch ( V_667 ) {
case V_808 :
if ( ! F_49 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_86 ;
return V_7 -> V_120 &
( 1u << ( V_14 & V_16 ) ) ;
case V_641 :
return 0 ;
case V_809 :
return 1 ;
case V_810 :
case V_811 :
return 1 ;
case V_812 :
return 1 ;
case V_813 :
return 1 ;
case V_814 :
return F_46 ( V_7 , V_298 ) ;
case V_815 :
return 1 ;
case V_816 :
return F_46 ( V_7 , V_299 ) ;
case V_817 :
return F_46 ( V_7 , V_309 ) ;
case V_818 :
return F_46 ( V_7 , V_819 ) ;
case V_820 : case V_821 :
case V_822 : case V_823 :
case V_824 : case V_825 :
case V_826 : case V_827 :
case V_828 : case V_829 :
return 1 ;
case V_830 :
return F_441 ( V_3 , V_7 ) ;
case V_831 :
return F_46 ( V_7 , V_305 ) ;
case V_832 :
return 1 ;
case V_833 :
case V_798 :
return F_439 ( V_3 , V_7 , V_667 ) ;
case V_834 :
return 1 ;
case V_835 :
return F_46 ( V_7 , V_300 ) ;
case V_836 :
return F_46 ( V_7 , V_308 ) ;
case V_837 :
return F_46 ( V_7 , V_838 ) ||
F_47 ( V_7 ,
V_48 ) ;
case V_839 :
return 0 ;
case V_840 :
return 1 ;
case V_841 :
return F_47 ( V_7 ,
V_30 ) ;
case V_734 :
case V_743 :
return 0 ;
case V_842 :
return F_47 ( V_7 , V_55 ) ;
case V_843 :
return 1 ;
default:
return 1 ;
}
}
static void F_444 ( struct V_2 * V_3 , T_5 * V_844 , T_5 * V_845 )
{
* V_844 = F_71 ( V_675 ) ;
* V_845 = F_73 ( V_806 ) ;
}
static int F_445 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_667 = V_60 -> V_667 ;
T_2 V_846 = V_60 -> V_665 ;
if ( V_60 -> V_422 && V_430 )
return F_396 ( V_3 ) ;
if ( V_60 -> V_8 . V_637 )
F_125 ( V_705 , V_3 ) ;
if ( ! F_92 ( V_3 ) && ( V_667 == V_822 ||
V_667 == V_826 ) )
V_60 -> V_8 . V_637 = 1 ;
else
V_60 -> V_8 . V_637 = 0 ;
if ( F_92 ( V_3 ) && F_442 ( V_3 ) ) {
F_148 ( V_3 ) ;
return 1 ;
}
if ( V_667 & V_847 ) {
V_3 -> V_658 -> V_667 = V_848 ;
V_3 -> V_658 -> V_849 . V_850
= V_667 ;
return 0 ;
}
if ( F_79 ( V_60 -> V_807 ) ) {
V_3 -> V_658 -> V_667 = V_848 ;
V_3 -> V_658 -> V_849 . V_850
= F_73 ( V_90 ) ;
return 0 ;
}
if ( ( V_846 & V_639 ) &&
( V_667 != V_808 &&
V_667 != V_734 &&
V_667 != V_812 ) )
F_56 ( V_149 L_30
L_31 ,
V_457 , V_846 , V_667 ) ;
if ( F_79 ( ! F_43 () && V_60 -> V_601 &&
! ( F_92 ( V_3 ) && F_48 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_315 ( V_3 ) ) {
V_60 -> V_601 = 0 ;
} else if ( V_60 -> V_630 > 1000000000LL &&
V_3 -> V_97 . V_851 ) {
F_56 ( V_149 L_32
L_33 ,
V_457 , V_3 -> V_852 ) ;
V_60 -> V_601 = 0 ;
}
}
if ( V_667 < V_853
&& V_854 [ V_667 ] )
return V_854 [ V_667 ] ( V_3 ) ;
else {
V_3 -> V_658 -> V_667 = V_731 ;
V_3 -> V_658 -> V_732 . V_733 = V_667 ;
}
return 0 ;
}
static void V_411 ( struct V_2 * V_3 , int V_855 , int V_856 )
{
if ( V_856 == - 1 || V_855 < V_856 ) {
F_81 ( V_616 , 0 ) ;
return;
}
F_81 ( V_616 , V_856 ) ;
}
static void F_446 ( struct V_1 * V_60 )
{
T_2 V_666 ;
if ( ! ( V_60 -> V_667 == V_839
|| V_60 -> V_667 == V_808 ) )
return;
V_60 -> V_666 = F_73 ( V_806 ) ;
V_666 = V_60 -> V_666 ;
if ( F_16 ( V_666 ) )
F_320 () ;
if ( ( V_666 & V_15 ) == V_634 &&
( V_666 & V_17 ) ) {
F_447 ( & V_60 -> V_3 ) ;
asm("int $2");
F_448 ( & V_60 -> V_3 ) ;
}
}
static void F_449 ( struct V_1 * V_60 )
{
T_2 V_666 ;
bool V_857 ;
T_6 V_858 ;
bool V_859 ;
V_859 = V_60 -> V_665 & V_639 ;
if ( F_43 () ) {
if ( V_60 -> V_632 )
return;
V_666 = F_73 ( V_806 ) ;
V_857 = ( V_666 & V_860 ) != 0 ;
V_858 = V_666 & V_16 ;
if ( ( V_666 & V_17 ) && V_857 &&
V_858 != V_653 && ! V_859 )
F_84 ( V_232 ,
V_635 ) ;
else
V_60 -> V_632 =
! ( F_73 ( V_232 )
& V_635 ) ;
} else if ( F_79 ( V_60 -> V_601 ) )
V_60 -> V_630 +=
F_450 ( F_451 ( F_452 () , V_60 -> V_861 ) ) ;
}
static void F_453 ( struct V_1 * V_60 ,
T_2 V_665 ,
int V_862 ,
int V_863 )
{
T_6 V_858 ;
int type ;
bool V_859 ;
V_859 = V_665 & V_639 ;
V_60 -> V_3 . V_97 . V_723 = false ;
F_385 ( & V_60 -> V_3 ) ;
F_384 ( & V_60 -> V_3 ) ;
if ( ! V_859 )
return;
F_125 ( V_705 , & V_60 -> V_3 ) ;
V_858 = V_665 & V_720 ;
type = V_665 & V_721 ;
switch ( type ) {
case V_634 :
V_60 -> V_3 . V_97 . V_723 = true ;
F_314 ( & V_60 -> V_3 , false ) ;
break;
case V_250 :
V_60 -> V_3 . V_97 . V_246 =
F_73 ( V_862 ) ;
case V_18 :
if ( V_665 & V_724 ) {
T_2 V_693 = F_73 ( V_863 ) ;
F_173 ( & V_60 -> V_3 , V_858 , V_693 ) ;
} else
F_319 ( & V_60 -> V_3 , V_858 ) ;
break;
case V_629 :
V_60 -> V_3 . V_97 . V_246 =
F_73 ( V_862 ) ;
case V_22 :
F_454 ( & V_60 -> V_3 , V_858 ,
type == V_629 ) ;
break;
default:
break;
}
}
static void F_455 ( struct V_1 * V_60 )
{
if ( F_92 ( & V_60 -> V_3 ) )
return;
F_453 ( V_60 , V_60 -> V_665 ,
V_239 ,
V_725 ) ;
}
static void F_456 ( struct V_2 * V_3 )
{
if ( F_92 ( V_3 ) )
return;
F_453 ( F_1 ( V_3 ) ,
F_73 ( V_251 ) ,
V_249 ,
V_243 ) ;
F_81 ( V_251 , 0 ) ;
}
static void F_457 ( struct V_1 * V_60 )
{
int V_62 , V_864 ;
struct V_865 * V_866 ;
V_866 = F_458 ( & V_864 ) ;
if ( ! V_866 )
return;
for ( V_62 = 0 ; V_62 < V_864 ; V_62 ++ )
if ( V_866 [ V_62 ] . V_137 == V_866 [ V_62 ] . V_136 )
F_94 ( V_60 , V_866 [ V_62 ] . V_61 ) ;
else
F_96 ( V_60 , V_866 [ V_62 ] . V_61 , V_866 [ V_62 ] . V_136 ,
V_866 [ V_62 ] . V_137 ) ;
}
static void T_16 F_459 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( F_92 ( V_3 ) && ! V_60 -> V_8 . V_637 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_638 &
V_639 ) {
F_81 ( V_251 ,
V_7 -> V_638 ) ;
F_81 ( V_249 ,
V_7 -> V_867 ) ;
if ( V_7 -> V_638 &
V_724 )
F_81 ( V_243 ,
V_7 -> V_868 ) ;
}
}
if ( F_79 ( ! F_43 () && V_60 -> V_601 ) )
V_60 -> V_861 = F_452 () ;
if ( V_60 -> V_422 && V_430 )
return;
if ( F_138 ( V_354 , ( unsigned long * ) & V_3 -> V_97 . V_465 ) )
F_78 ( V_356 , V_3 -> V_97 . V_355 [ V_354 ] ) ;
if ( F_138 ( V_357 , ( unsigned long * ) & V_3 -> V_97 . V_465 ) )
F_78 ( V_358 , V_3 -> V_97 . V_355 [ V_357 ] ) ;
if ( V_3 -> V_113 & V_649 )
F_143 ( V_3 , 0 ) ;
F_457 ( V_60 ) ;
V_60 -> V_869 = V_60 -> V_77 -> V_79 ;
asm(
"push %%"R"dx; push %%"R"bp;"
"push %%"R"cx \n\t"
"push %%"R"cx \n\t"
"cmp %%"R"sp, %c[host_rsp](%0) \n\t"
"je 1f \n\t"
"mov %%"R"sp, %c[host_rsp](%0) \n\t"
__ex(ASM_VMX_VMWRITE_RSP_RDX) "\n\t"
"1: \n\t"
"mov %c[cr2](%0), %%"R"ax \n\t"
"mov %%cr2, %%"R"dx \n\t"
"cmp %%"R"ax, %%"R"dx \n\t"
"je 2f \n\t"
"mov %%"R"ax, %%cr2 \n\t"
"2: \n\t"
"cmpl $0, %c[launched](%0) \n\t"
"mov %c[rax](%0), %%"R"ax \n\t"
"mov %c[rbx](%0), %%"R"bx \n\t"
"mov %c[rdx](%0), %%"R"dx \n\t"
"mov %c[rsi](%0), %%"R"si \n\t"
"mov %c[rdi](%0), %%"R"di \n\t"
"mov %c[rbp](%0), %%"R"bp \n\t"
#ifdef F_75
"mov %c[r8](%0), %%r8 \n\t"
"mov %c[r9](%0), %%r9 \n\t"
"mov %c[r10](%0), %%r10 \n\t"
"mov %c[r11](%0), %%r11 \n\t"
"mov %c[r12](%0), %%r12 \n\t"
"mov %c[r13](%0), %%r13 \n\t"
"mov %c[r14](%0), %%r14 \n\t"
"mov %c[r15](%0), %%r15 \n\t"
#endif
"mov %c[rcx](%0), %%"R"cx \n\t"
"jne .Llaunched \n\t"
__ex(ASM_VMX_VMLAUNCH) "\n\t"
"jmp .Lkvm_vmx_return \n\t"
".Llaunched: " __ex(ASM_VMX_VMRESUME) "\n\t"
".Lkvm_vmx_return: "
"mov %0, %c[wordsize](%%"R"sp) \n\t"
"pop %0 \n\t"
"mov %%"R"ax, %c[rax](%0) \n\t"
"mov %%"R"bx, %c[rbx](%0) \n\t"
"pop"Q" %c[rcx](%0) \n\t"
"mov %%"R"dx, %c[rdx](%0) \n\t"
"mov %%"R"si, %c[rsi](%0) \n\t"
"mov %%"R"di, %c[rdi](%0) \n\t"
"mov %%"R"bp, %c[rbp](%0) \n\t"
#ifdef F_75
"mov %%r8, %c[r8](%0) \n\t"
"mov %%r9, %c[r9](%0) \n\t"
"mov %%r10, %c[r10](%0) \n\t"
"mov %%r11, %c[r11](%0) \n\t"
"mov %%r12, %c[r12](%0) \n\t"
"mov %%r13, %c[r13](%0) \n\t"
"mov %%r14, %c[r14](%0) \n\t"
"mov %%r15, %c[r15](%0) \n\t"
#endif
"mov %%cr2, %%"R"ax \n\t"
"mov %%"R"ax, %c[cr2](%0) \n\t"
"pop %%"R"bp; pop %%"R"dx \n\t"
"setbe %c[fail](%0) \n\t"
: : "c"(vmx), "d"((unsigned long)HOST_RSP),
[launched]"i"(offsetof(struct vcpu_vmx, __launched)),
[fail]"i"(offsetof(struct vcpu_vmx, fail)),
[host_rsp]"i"(offsetof(struct vcpu_vmx, host_rsp)),
[rax]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RAX])),
[rbx]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RBX])),
[rcx]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RCX])),
[rdx]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RDX])),
[rsi]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RSI])),
[rdi]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RDI])),
[rbp]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RBP])),
#ifdef F_75
[r8]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R8])),
[r9]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R9])),
[r10]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R10])),
[r11]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R11])),
[r12]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R12])),
[r13]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R13])),
[r14]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R14])),
[r15]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R15])),
#endif
[cr2]"i"(offsetof(struct vcpu_vmx, vcpu.arch.cr2)),
[wordsize]"i"(sizeof(ulong))
: "cc", "memory"
, R"ax", R"bx", R"di", R"si"
#ifdef F_75
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#endif
);
#ifndef F_75
F_116 ( V_186 , V_870 ) ;
F_116 ( V_188 , V_870 ) ;
#endif
V_3 -> V_97 . V_98 = ~ ( ( 1 << V_357 ) | ( 1 << V_354 )
| ( 1 << V_225 )
| ( 1 << V_228 )
| ( 1 << V_359 )
| ( 1 << V_99 )
| ( 1 << V_462 ) ) ;
V_3 -> V_97 . V_465 = 0 ;
V_60 -> V_665 = F_73 ( V_871 ) ;
if ( F_92 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_638 = V_60 -> V_665 ;
if ( V_60 -> V_665 & V_639 ) {
V_7 -> V_868 =
F_73 ( V_725 ) ;
V_7 -> V_867 =
F_73 ( V_239 ) ;
}
}
V_60 -> V_77 -> V_79 = 1 ;
V_60 -> V_667 = F_73 ( V_805 ) ;
F_460 ( V_60 -> V_667 , V_3 , V_872 ) ;
F_446 ( V_60 ) ;
F_449 ( V_60 ) ;
F_455 ( V_60 ) ;
}
static void F_461 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
F_282 ( V_60 ) ;
F_415 ( V_60 ) ;
F_208 ( V_60 -> V_77 ) ;
F_409 ( V_60 -> V_65 ) ;
F_462 ( V_3 ) ;
F_463 ( V_873 , V_60 ) ;
}
static struct V_2 * F_464 ( struct V_12 * V_12 , unsigned int V_874 )
{
int V_693 ;
struct V_1 * V_60 = F_465 ( V_873 , V_404 ) ;
int V_78 ;
if ( ! V_60 )
return F_466 ( - V_405 ) ;
F_278 ( V_60 ) ;
V_693 = F_467 ( & V_60 -> V_3 , V_12 , V_874 ) ;
if ( V_693 )
goto V_875;
V_60 -> V_65 = F_408 ( V_394 , V_404 ) ;
V_693 = - V_405 ;
if ( ! V_60 -> V_65 ) {
goto V_876;
}
V_60 -> V_77 = & V_60 -> V_761 ;
V_60 -> V_77 -> V_74 = F_205 () ;
if ( ! V_60 -> V_77 -> V_74 )
goto V_877;
if ( ! V_201 )
F_124 ( F_55 ( F_61 ( V_200 , F_60 () ) ) ) ;
F_57 ( V_60 -> V_77 ) ;
if ( ! V_201 )
F_130 () ;
V_78 = F_468 () ;
F_123 ( & V_60 -> V_3 , V_78 ) ;
V_60 -> V_3 . V_78 = V_78 ;
V_693 = F_294 ( V_60 ) ;
F_129 ( & V_60 -> V_3 ) ;
F_469 () ;
if ( V_693 )
goto F_206;
if ( F_39 ( V_12 ) )
V_693 = F_273 ( V_12 ) ;
if ( V_693 )
goto F_206;
if ( V_86 ) {
if ( ! V_12 -> V_97 . V_487 )
V_12 -> V_97 . V_487 =
V_878 ;
V_693 = - V_405 ;
if ( F_277 ( V_12 ) != 0 )
goto F_206;
if ( ! F_270 ( V_12 ) )
goto F_206;
}
V_60 -> V_8 . V_754 = - 1ull ;
V_60 -> V_8 . V_9 = NULL ;
return & V_60 -> V_3 ;
F_206:
F_208 ( V_60 -> V_77 ) ;
V_877:
F_409 ( V_60 -> V_65 ) ;
V_876:
F_462 ( & V_60 -> V_3 ) ;
V_875:
F_282 ( V_60 ) ;
F_463 ( V_873 , V_60 ) ;
return F_466 ( V_693 ) ;
}
static void T_11 F_470 ( void * V_879 )
{
struct V_24 V_382 ;
* ( int * ) V_879 = 0 ;
if ( F_199 ( & V_382 ) < 0 )
* ( int * ) V_879 = - V_381 ;
if ( memcmp ( & V_24 , & V_382 , sizeof( struct V_24 ) ) != 0 ) {
F_56 ( V_76 L_34 ,
F_471 () ) ;
* ( int * ) V_879 = - V_381 ;
}
}
static int F_472 ( void )
{
return V_481 + 1 ;
}
static T_5 F_473 ( struct V_2 * V_3 , T_13 V_880 , bool V_881 )
{
T_5 V_95 ;
if ( V_881 )
V_95 = V_882 << V_883 ;
else if ( V_3 -> V_12 -> V_97 . V_884 &&
! ( V_3 -> V_12 -> V_97 . V_885 & V_886 ) )
V_95 = F_474 ( V_3 , V_880 ) <<
V_883 ;
else
V_95 = ( V_887 << V_883 )
| V_888 ;
return V_95 ;
}
static int F_475 ( void )
{
if ( V_86 && ! F_28 () )
return V_889 ;
else
return V_890 ;
}
static void F_476 ( struct V_2 * V_3 )
{
struct V_278 * V_279 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_576 ;
V_60 -> V_260 = false ;
if ( F_152 () ) {
V_576 = F_73 ( V_584 ) ;
if ( V_576 & V_51 ) {
V_279 = F_166 ( V_3 , 0x80000001 , 0 ) ;
if ( V_279 && ( V_279 -> V_891 & V_56 ( V_892 ) ) )
V_60 -> V_260 = true ;
else {
V_576 &= ~ V_51 ;
F_81 ( V_584 ,
V_576 ) ;
}
}
}
V_576 = F_73 ( V_584 ) ;
V_279 = F_166 ( V_3 , 0x7 , 0 ) ;
if ( F_153 () &&
V_279 && ( V_279 -> V_893 & V_56 ( V_894 ) ) &&
F_477 ( V_3 ) ) {
V_576 |= V_52 ;
F_81 ( V_584 ,
V_576 ) ;
} else {
V_576 &= ~ V_52 ;
F_81 ( V_584 ,
V_576 ) ;
if ( V_279 )
V_279 -> V_893 &= ~ V_56 ( V_894 ) ;
}
}
static void F_478 ( T_2 V_895 , struct V_278 * V_122 )
{
if ( V_895 == 1 && V_8 )
V_122 -> V_280 |= V_56 ( V_281 ) ;
}
static void F_479 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_576 ;
F_80 ( V_896 , V_7 -> V_897 ) ;
F_80 ( V_437 , V_7 -> V_898 ) ;
F_80 ( V_435 , V_7 -> V_899 ) ;
F_80 ( V_900 , V_7 -> V_901 ) ;
F_80 ( V_902 , V_7 -> V_903 ) ;
F_80 ( V_904 , V_7 -> V_905 ) ;
F_80 ( V_606 , V_7 -> V_906 ) ;
F_80 ( V_423 , V_7 -> V_907 ) ;
F_81 ( V_908 , V_7 -> V_909 ) ;
F_81 ( V_505 , V_7 -> V_910 ) ;
F_81 ( V_508 , V_7 -> V_911 ) ;
F_81 ( V_912 , V_7 -> V_913 ) ;
F_81 ( V_914 , V_7 -> V_915 ) ;
F_81 ( V_916 , V_7 -> V_917 ) ;
F_81 ( V_608 , V_7 -> V_918 ) ;
F_81 ( V_425 , V_7 -> V_919 ) ;
F_81 ( V_512 , V_7 -> V_920 ) ;
F_81 ( V_510 , V_7 -> V_921 ) ;
F_81 ( V_922 , V_7 -> V_923 ) ;
F_81 ( V_438 , V_7 -> V_924 ) ;
F_81 ( V_436 , V_7 -> V_925 ) ;
F_81 ( V_926 , V_7 -> V_927 ) ;
F_81 ( V_928 , V_7 -> V_929 ) ;
F_81 ( V_930 , V_7 -> V_931 ) ;
F_81 ( V_609 , V_7 -> V_932 ) ;
F_81 ( V_426 , V_7 -> V_933 ) ;
F_78 ( V_934 , V_7 -> V_935 ) ;
F_78 ( V_506 , V_7 -> V_936 ) ;
F_78 ( V_507 , V_7 -> V_937 ) ;
F_78 ( V_938 , V_7 -> V_939 ) ;
F_78 ( V_340 , V_7 -> V_940 ) ;
F_78 ( V_341 , V_7 -> V_941 ) ;
F_78 ( V_607 , V_7 -> V_942 ) ;
F_78 ( V_424 , V_7 -> V_943 ) ;
F_78 ( V_513 , V_7 -> V_944 ) ;
F_78 ( V_511 , V_7 -> V_945 ) ;
F_82 ( V_613 , V_7 -> V_946 ) ;
F_81 ( V_251 ,
V_7 -> V_947 ) ;
F_81 ( V_243 ,
V_7 -> V_948 ) ;
F_81 ( V_249 ,
V_7 -> V_949 ) ;
F_81 ( V_232 ,
V_7 -> V_950 ) ;
F_81 ( V_610 , V_7 -> V_951 ) ;
F_81 ( V_344 , V_7 -> V_952 ) ;
F_78 ( V_363 , V_7 -> V_953 ) ;
F_78 ( V_226 , V_7 -> V_954 ) ;
F_78 ( V_612 ,
V_7 -> V_955 ) ;
F_78 ( V_347 , V_7 -> V_956 ) ;
F_78 ( V_346 , V_7 -> V_957 ) ;
F_82 ( V_582 , - 1ull ) ;
F_81 ( V_583 ,
( V_24 . V_53 |
V_7 -> V_59 ) ) ;
F_81 ( V_588 ,
V_86 ? V_7 -> V_958 : 0 ) ;
F_81 ( V_589 ,
V_86 ? V_7 -> V_959 : 0 ) ;
if ( F_21 () ) {
T_2 V_576 = F_291 ( V_60 ) ;
if ( ! V_60 -> V_260 )
V_576 &= ~ V_51 ;
V_576 &= ~ V_30 ;
if ( F_46 ( V_7 ,
V_28 ) )
V_576 |= V_7 -> V_58 ;
if ( V_576 & V_30 ) {
if ( V_60 -> V_8 . V_544 )
F_9 ( V_60 -> V_8 . V_544 ) ;
V_60 -> V_8 . V_544 =
F_5 ( V_3 , V_7 -> V_960 ) ;
if ( ! V_60 -> V_8 . V_544 )
V_576 &=
~ V_30 ;
else
F_82 ( V_617 ,
F_304 ( V_60 -> V_8 . V_544 ) ) ;
}
F_81 ( V_584 , V_576 ) ;
}
F_285 () ;
V_60 -> V_961 = 0 ;
V_576 = F_290 ( V_60 ) ;
V_576 &= ~ V_297 ;
V_576 &= ~ V_623 ;
V_576 &= ~ V_27 ;
V_576 |= V_7 -> V_57 ;
V_576 &= ~ V_26 ;
V_576 &= ~ V_307 ;
V_576 |= V_306 ;
F_81 ( V_473 , V_576 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_213 &= ~ V_7 -> V_214 ;
F_78 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
F_81 ( V_124 ,
V_7 -> V_962 | V_24 . V_398 ) ;
F_81 ( V_123 , V_7 -> V_963 |
( V_24 . V_349 & ~ V_293 ) ) ;
if ( V_7 -> V_963 & V_292 )
F_82 ( V_350 , V_7 -> V_964 ) ;
else if ( V_24 . V_349 & V_292 )
F_82 ( V_350 , V_60 -> V_3 . V_97 . V_351 ) ;
F_289 ( V_60 ) ;
if ( V_7 -> V_57 & V_275 )
F_82 ( V_267 ,
V_60 -> V_8 . V_268 + V_7 -> V_266 ) ;
else
F_82 ( V_267 , V_60 -> V_8 . V_268 ) ;
if ( V_407 ) {
F_80 ( V_618 , V_60 -> V_43 ) ;
F_233 ( V_3 ) ;
}
if ( V_7 -> V_963 & V_129 )
V_3 -> V_97 . V_160 = V_7 -> V_965 ;
if ( V_7 -> V_963 & V_293 )
V_3 -> V_97 . V_160 |= ( V_163 | V_164 ) ;
else
V_3 -> V_97 . V_160 &= ~ ( V_163 | V_164 ) ;
F_229 ( V_3 , V_3 -> V_97 . V_160 ) ;
F_244 ( V_3 , V_7 -> V_217 ) ;
F_78 ( V_222 , F_133 ( V_7 ) ) ;
F_242 ( V_3 , V_7 -> V_219 ) ;
F_78 ( V_429 , F_134 ( V_7 ) ) ;
F_345 ( V_3 , V_7 -> V_485 ) ;
F_228 ( V_3 ) ;
F_303 ( V_3 , V_354 , V_7 -> V_966 ) ;
F_303 ( V_3 , V_357 , V_7 -> V_967 ) ;
}
static int F_428 ( struct V_2 * V_3 , bool V_968 )
{
struct V_7 * V_7 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
int V_78 ;
struct V_77 * V_757 ;
if ( ! F_414 ( V_3 ) ||
! F_433 ( V_3 ) )
return 1 ;
F_144 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_784 == V_968 ) {
F_421 ( V_3 ,
V_968 ? V_969
: V_970 ) ;
return 1 ;
}
if ( ( V_7 -> V_57 & V_26 ) &&
! F_425 ( V_7 -> V_255 , V_394 ) ) {
F_421 ( V_3 , V_971 ) ;
return 1 ;
}
if ( F_47 ( V_7 , V_30 ) &&
! F_425 ( V_7 -> V_960 , V_394 ) ) {
F_421 ( V_3 , V_971 ) ;
return 1 ;
}
if ( V_7 -> V_972 > 0 ||
V_7 -> V_973 > 0 ||
V_7 -> V_974 > 0 ) {
F_480 ( L_35 ,
V_457 ) ;
F_421 ( V_3 , V_971 ) ;
return 1 ;
}
if ( ! F_170 ( V_7 -> V_57 ,
V_295 , V_296 ) ||
! F_170 ( V_7 -> V_58 ,
V_311 , V_312 ) ||
! F_170 ( V_7 -> V_59 ,
V_282 , V_283 ) ||
! F_170 ( V_7 -> V_962 ,
V_286 , V_287 ) ||
! F_170 ( V_7 -> V_963 ,
V_290 , V_291 ) )
{
F_421 ( V_3 , V_971 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_975 & F_174 ) != F_174 ) ||
( ( V_7 -> V_976 & F_175 ) != F_175 ) ) {
F_421 ( V_3 ,
V_977 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_217 & F_174 ) != F_174 ) ||
( ( V_7 -> V_219 & F_175 ) != F_175 ) ) {
F_481 ( V_3 , V_7 ,
V_834 , V_978 ) ;
return 1 ;
}
if ( V_7 -> V_979 != - 1ull ) {
F_481 ( V_3 , V_7 ,
V_834 , V_980 ) ;
return 1 ;
}
V_757 = F_403 ( V_60 ) ;
if ( ! V_757 )
return - V_405 ;
F_482 ( V_3 ) ;
V_60 -> V_8 . V_268 = F_74 ( V_267 ) ;
V_78 = F_468 () ;
V_60 -> V_77 = V_757 ;
F_129 ( V_3 ) ;
F_123 ( V_3 , V_78 ) ;
V_3 -> V_78 = V_78 ;
F_469 () ;
V_7 -> V_784 = 1 ;
F_479 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_483 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_71 ( V_210 ) & V_3 -> V_97 . V_213 ) |
( V_7 -> V_217 & V_7 -> V_214 ) |
( F_71 ( V_222 ) & ~ ( V_7 -> V_214 |
V_3 -> V_97 . V_213 ) ) ;
}
static inline unsigned long
F_484 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_71 ( V_427 ) & V_3 -> V_97 . V_463 ) |
( V_7 -> V_219 & V_7 -> V_220 ) |
( F_71 ( V_429 ) & ~ ( V_7 -> V_220 |
V_3 -> V_97 . V_463 ) ) ;
}
void F_485 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_217 = F_483 ( V_3 , V_7 ) ;
V_7 -> V_219 = F_484 ( V_3 , V_7 ) ;
F_353 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_953 ) ;
V_7 -> V_966 = F_342 ( V_3 , V_354 ) ;
V_7 -> V_967 = F_342 ( V_3 , V_357 ) ;
V_7 -> V_954 = F_71 ( V_226 ) ;
V_7 -> V_897 = F_72 ( V_896 ) ;
V_7 -> V_898 = F_72 ( V_437 ) ;
V_7 -> V_899 = F_72 ( V_435 ) ;
V_7 -> V_901 = F_72 ( V_900 ) ;
V_7 -> V_903 = F_72 ( V_902 ) ;
V_7 -> V_905 = F_72 ( V_904 ) ;
V_7 -> V_906 = F_72 ( V_606 ) ;
V_7 -> V_907 = F_72 ( V_423 ) ;
V_7 -> V_909 = F_73 ( V_908 ) ;
V_7 -> V_910 = F_73 ( V_505 ) ;
V_7 -> V_911 = F_73 ( V_508 ) ;
V_7 -> V_913 = F_73 ( V_912 ) ;
V_7 -> V_915 = F_73 ( V_914 ) ;
V_7 -> V_917 = F_73 ( V_916 ) ;
V_7 -> V_918 = F_73 ( V_608 ) ;
V_7 -> V_919 = F_73 ( V_425 ) ;
V_7 -> V_920 = F_73 ( V_512 ) ;
V_7 -> V_921 = F_73 ( V_510 ) ;
V_7 -> V_923 = F_73 ( V_922 ) ;
V_7 -> V_924 = F_73 ( V_438 ) ;
V_7 -> V_925 = F_73 ( V_436 ) ;
V_7 -> V_927 = F_73 ( V_926 ) ;
V_7 -> V_929 = F_73 ( V_928 ) ;
V_7 -> V_931 = F_73 ( V_930 ) ;
V_7 -> V_932 = F_73 ( V_609 ) ;
V_7 -> V_933 = F_73 ( V_426 ) ;
V_7 -> V_935 = F_71 ( V_934 ) ;
V_7 -> V_936 = F_71 ( V_506 ) ;
V_7 -> V_937 = F_71 ( V_507 ) ;
V_7 -> V_939 = F_71 ( V_938 ) ;
V_7 -> V_940 = F_71 ( V_340 ) ;
V_7 -> V_941 = F_71 ( V_341 ) ;
V_7 -> V_942 = F_71 ( V_607 ) ;
V_7 -> V_943 = F_71 ( V_424 ) ;
V_7 -> V_944 = F_71 ( V_513 ) ;
V_7 -> V_945 = F_71 ( V_511 ) ;
V_7 -> V_951 = F_73 ( V_610 ) ;
V_7 -> V_950 =
F_73 ( V_232 ) ;
V_7 -> V_955 =
F_71 ( V_612 ) ;
V_7 -> V_946 = F_74 ( V_613 ) ;
if ( V_7 -> V_963 & V_392 )
V_7 -> V_964 = F_74 ( V_350 ) ;
V_7 -> V_952 = F_73 ( V_344 ) ;
V_7 -> V_956 = F_71 ( V_347 ) ;
V_7 -> V_957 = F_71 ( V_346 ) ;
V_7 -> V_640 = F_73 ( V_805 ) ;
V_7 -> V_686 = F_71 ( V_675 ) ;
V_7 -> V_642 = F_73 ( V_806 ) ;
V_7 -> V_981 = F_73 ( V_674 ) ;
V_7 -> V_638 =
F_73 ( V_871 ) ;
V_7 -> V_868 =
F_73 ( V_725 ) ;
V_7 -> V_867 = F_73 ( V_239 ) ;
V_7 -> V_763 = F_73 ( V_781 ) ;
if ( ! ( V_7 -> V_640 & V_847 ) )
V_7 -> V_947 &= ~ V_17 ;
}
void F_486 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_962 & V_130 )
V_3 -> V_97 . V_160 = V_7 -> V_982 ;
if ( V_7 -> V_962 & V_288 )
V_3 -> V_97 . V_160 |= ( V_163 | V_164 ) ;
else
V_3 -> V_97 . V_160 &= ~ ( V_163 | V_164 ) ;
F_229 ( V_3 , V_3 -> V_97 . V_160 ) ;
F_303 ( V_3 , V_354 , V_7 -> V_961 ) ;
F_303 ( V_3 , V_357 , V_7 -> V_983 ) ;
F_337 ( V_3 , V_7 -> V_975 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_213 = ( V_3 -> V_119 ? V_211 : 0 ) ;
F_78 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
V_3 -> V_97 . V_463 = ~ F_71 ( V_575 ) ;
F_339 ( V_3 , V_7 -> V_976 ) ;
F_345 ( V_3 , V_7 -> V_984 ) ;
F_228 ( V_3 ) ;
if ( V_407 ) {
F_233 ( V_3 ) ;
}
F_81 ( V_344 , V_7 -> V_985 ) ;
F_78 ( V_347 , V_7 -> V_986 ) ;
F_78 ( V_346 , V_7 -> V_987 ) ;
F_78 ( V_511 , V_7 -> V_988 ) ;
F_78 ( V_513 , V_7 -> V_989 ) ;
F_78 ( V_424 , V_7 -> V_990 ) ;
F_78 ( V_341 , V_7 -> V_991 ) ;
F_78 ( V_340 , V_7 -> V_992 ) ;
F_80 ( V_896 , V_7 -> V_993 ) ;
F_80 ( V_437 , V_7 -> V_994 ) ;
F_80 ( V_435 , V_7 -> V_995 ) ;
F_80 ( V_900 , V_7 -> V_996 ) ;
F_80 ( V_902 , V_7 -> V_997 ) ;
F_80 ( V_904 , V_7 -> V_998 ) ;
F_80 ( V_423 , V_7 -> V_999 ) ;
if ( V_7 -> V_962 & V_393 )
F_82 ( V_350 , V_7 -> V_1000 ) ;
if ( V_7 -> V_962 & V_134 )
F_82 ( V_146 ,
V_7 -> V_1001 ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
int V_78 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_487 ( V_3 ) ;
F_485 ( V_3 , V_7 ) ;
V_78 = F_468 () ;
V_60 -> V_77 = & V_60 -> V_761 ;
F_129 ( V_3 ) ;
F_123 ( V_3 , V_78 ) ;
V_3 -> V_78 = V_78 ;
F_469 () ;
if ( V_759 == 0 )
F_410 ( V_60 , V_60 -> V_8 . V_754 ) ;
F_486 ( V_3 , V_7 ) ;
F_82 ( V_267 , V_60 -> V_8 . V_268 ) ;
V_60 -> V_961 = 0 ;
if ( V_60 -> V_8 . V_544 ) {
F_9 ( V_60 -> V_8 . V_544 ) ;
V_60 -> V_8 . V_544 = 0 ;
}
if ( F_79 ( V_60 -> V_807 ) ) {
V_60 -> V_807 = 0 ;
F_421 ( V_3 , F_73 ( V_90 ) ) ;
} else
F_419 ( V_3 ) ;
}
static void F_481 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_717 , unsigned long V_1002 )
{
F_486 ( V_3 , V_7 ) ;
V_7 -> V_640 = V_717 | V_847 ;
V_7 -> V_686 = V_1002 ;
F_419 ( V_3 ) ;
}
static int F_488 ( struct V_2 * V_3 ,
struct V_1003 * V_1004 ,
enum V_1005 V_1006 )
{
return V_1007 ;
}
static int T_11 F_489 ( void )
{
int V_525 , V_62 ;
F_490 ( V_127 , & V_165 ) ;
for ( V_62 = 0 ; V_62 < V_597 ; ++ V_62 )
F_491 ( V_62 , V_64 [ V_62 ] ) ;
V_579 = ( unsigned long * ) F_492 ( V_404 ) ;
if ( ! V_579 )
return - V_405 ;
V_525 = - V_405 ;
V_581 = ( unsigned long * ) F_492 ( V_404 ) ;
if ( ! V_581 )
goto V_527;
V_263 = ( unsigned long * ) F_492 ( V_404 ) ;
if ( ! V_263 )
goto V_1008;
V_262 = ( unsigned long * ) F_492 ( V_404 ) ;
if ( ! V_262 )
goto V_1009;
memset ( V_579 , 0xff , V_394 ) ;
F_493 ( 0x80 , V_579 ) ;
memset ( V_581 , 0xff , V_394 ) ;
memset ( V_263 , 0xff , V_394 ) ;
memset ( V_262 , 0xff , V_394 ) ;
F_494 ( 0 , V_551 ) ;
V_525 = F_495 ( & V_1010 , sizeof( struct V_1 ) ,
F_496 ( struct V_1 ) , V_1011 ) ;
if ( V_525 )
goto V_1012;
F_284 ( V_191 , false ) ;
F_284 ( V_193 , false ) ;
F_284 ( V_194 , true ) ;
F_284 ( V_343 , false ) ;
F_284 ( V_207 , false ) ;
F_284 ( V_345 , false ) ;
if ( V_86 ) {
F_497 ( 0ull ,
( V_409 ) ? V_1013 : 0ull ,
( V_409 ) ? V_1014 : 0ull ,
0ull , V_1015 ) ;
F_292 () ;
F_498 () ;
} else
F_499 () ;
return 0 ;
V_1012:
F_500 ( ( unsigned long ) V_262 ) ;
V_1009:
F_500 ( ( unsigned long ) V_263 ) ;
V_1008:
F_500 ( ( unsigned long ) V_581 ) ;
V_527:
F_500 ( ( unsigned long ) V_579 ) ;
return V_525 ;
}
static void T_12 F_501 ( void )
{
F_500 ( ( unsigned long ) V_263 ) ;
F_500 ( ( unsigned long ) V_262 ) ;
F_500 ( ( unsigned long ) V_581 ) ;
F_500 ( ( unsigned long ) V_579 ) ;
F_502 () ;
}
