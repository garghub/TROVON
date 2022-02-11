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
if ( F_7 ( V_10 ) )
return NULL ;
return V_10 ;
}
static void F_8 ( struct V_10 * V_10 )
{
F_9 ( V_10 ) ;
}
static void F_10 ( struct V_10 * V_10 )
{
F_11 ( V_10 ) ;
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
if ( ! F_117 () && ! V_60 -> V_3 . V_200 )
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
T_5 V_75 = F_55 ( F_61 ( V_201 , V_78 ) ) ;
if ( ! V_202 )
F_124 ( V_75 ) ;
else if ( V_60 -> V_77 -> V_78 != V_78 )
F_63 ( V_60 -> V_77 ) ;
if ( F_61 ( V_81 , V_78 ) != V_60 -> V_77 -> V_74 ) {
F_61 ( V_81 , V_78 ) = V_60 -> V_77 -> V_74 ;
F_58 ( V_60 -> V_77 -> V_74 ) ;
}
if ( V_60 -> V_77 -> V_78 != V_78 ) {
struct V_150 * V_151 = & F_99 ( V_152 ) ;
unsigned long V_203 ;
F_125 ( V_204 , V_3 ) ;
F_126 () ;
F_127 ( & V_60 -> V_77 -> V_82 ,
& F_61 ( V_205 , V_78 ) ) ;
F_128 () ;
F_78 ( V_206 , F_105 () ) ;
F_78 ( V_207 , V_151 -> V_155 ) ;
F_109 ( V_208 , V_203 ) ;
F_78 ( V_209 , V_203 ) ;
V_60 -> V_77 -> V_78 = V_78 ;
}
}
static void F_129 ( struct V_2 * V_3 )
{
F_113 ( F_1 ( V_3 ) ) ;
if ( ! V_202 ) {
F_59 ( F_1 ( V_3 ) -> V_77 ) ;
V_3 -> V_78 = - 1 ;
F_130 () ;
}
}
static void F_131 ( struct V_2 * V_3 )
{
T_9 V_210 ;
if ( V_3 -> V_119 )
return;
V_3 -> V_119 = 1 ;
V_210 = F_71 ( V_211 ) ;
V_210 &= ~ ( V_212 | V_213 ) ;
V_210 |= F_132 ( V_3 , V_212 | V_213 ) ;
F_78 ( V_211 , V_210 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_214 = V_212 ;
if ( F_92 ( V_3 ) )
V_3 -> V_97 . V_214 &=
~ F_4 ( V_3 ) -> V_215 ;
F_78 ( V_216 , ~ V_3 -> V_97 . V_214 ) ;
}
static inline unsigned long F_133 ( struct V_7 * V_217 )
{
return ( V_217 -> V_218 & ~ V_217 -> V_215 ) |
( V_217 -> V_219 & V_217 -> V_215 ) ;
}
static inline unsigned long F_134 ( struct V_7 * V_217 )
{
return ( V_217 -> V_220 & ~ V_217 -> V_221 ) |
( V_217 -> V_222 & V_217 -> V_221 ) ;
}
static void F_135 ( struct V_2 * V_3 )
{
F_136 ( V_3 ) ;
F_84 ( V_211 , V_212 | V_213 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_214 = 0 ;
F_78 ( V_216 , ~ V_3 -> V_97 . V_214 ) ;
if ( F_92 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_218 = ( V_7 -> V_218 & ~ V_212 ) |
( V_3 -> V_97 . V_210 & V_212 ) ;
F_78 ( V_223 , F_133 ( V_7 ) ) ;
} else
F_78 ( V_223 , V_3 -> V_97 . V_210 ) ;
}
static unsigned long F_137 ( struct V_2 * V_3 )
{
unsigned long V_224 , V_225 ;
if ( ! F_138 ( V_226 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ) {
F_139 ( V_226 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
V_224 = F_71 ( V_227 ) ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
V_224 &= V_228 ;
V_225 = F_1 ( V_3 ) -> V_117 . V_225 ;
V_224 |= V_225 & ~ V_228 ;
}
F_1 ( V_3 ) -> V_224 = V_224 ;
}
return F_1 ( V_3 ) -> V_224 ;
}
static void F_140 ( struct V_2 * V_3 , unsigned long V_224 )
{
F_139 ( V_226 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
F_141 ( V_229 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
F_1 ( V_3 ) -> V_224 = V_224 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
F_1 ( V_3 ) -> V_117 . V_225 = V_224 ;
V_224 |= V_230 | V_231 ;
}
F_78 ( V_227 , V_224 ) ;
}
static T_2 F_142 ( struct V_2 * V_3 , int V_91 )
{
T_2 V_232 = F_73 ( V_233 ) ;
int V_95 = 0 ;
if ( V_232 & V_234 )
V_95 |= V_235 ;
if ( V_232 & V_236 )
V_95 |= V_237 ;
return V_95 & V_91 ;
}
static void F_143 ( struct V_2 * V_3 , int V_91 )
{
T_2 V_238 = F_73 ( V_233 ) ;
T_2 V_232 = V_238 ;
V_232 &= ~ ( V_234 | V_236 ) ;
if ( V_91 & V_237 )
V_232 |= V_236 ;
else if ( V_91 & V_235 )
V_232 |= V_234 ;
if ( ( V_232 != V_238 ) )
F_81 ( V_233 , V_232 ) ;
}
static void F_144 ( struct V_2 * V_3 )
{
unsigned long V_239 ;
V_239 = F_145 ( V_3 ) ;
V_239 += F_73 ( V_240 ) ;
F_146 ( V_3 , V_239 ) ;
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
bool V_241 , T_2 V_242 ,
bool V_243 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_14 = V_135 | V_17 ;
if ( V_135 == V_19 && F_92 ( V_3 ) &&
F_147 ( V_3 ) )
return;
if ( V_241 ) {
F_81 ( V_244 , V_242 ) ;
V_14 |= V_245 ;
}
if ( V_60 -> V_117 . V_118 ) {
int V_246 = 0 ;
if ( F_150 ( V_135 ) )
V_246 = V_3 -> V_97 . V_247 ;
if ( F_151 ( V_3 , V_135 , V_246 ) != V_248 )
F_125 ( V_249 , V_3 ) ;
return;
}
if ( F_150 ( V_135 ) ) {
F_81 ( V_250 ,
V_60 -> V_3 . V_97 . V_247 ) ;
V_14 |= V_251 ;
} else
V_14 |= V_18 ;
F_81 ( V_252 , V_14 ) ;
}
static bool F_152 ( void )
{
return F_41 () ;
}
static bool F_153 ( void )
{
return F_42 () && V_86 ;
}
static void F_154 ( struct V_1 * V_60 , int V_253 , int V_254 )
{
struct V_73 V_255 ;
V_255 = V_60 -> V_65 [ V_254 ] ;
V_60 -> V_65 [ V_254 ] = V_60 -> V_65 [ V_253 ] ;
V_60 -> V_65 [ V_253 ] = V_255 ;
}
static void F_155 ( struct V_1 * V_60 )
{
int V_197 , V_66 ;
unsigned long * V_256 ;
V_197 = 0 ;
#ifdef F_75
if ( F_110 ( & V_60 -> V_3 ) ) {
V_66 = F_50 ( V_60 , V_257 ) ;
if ( V_66 >= 0 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_258 ) ;
if ( V_66 >= 0 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_259 ) ;
if ( V_66 >= 0 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_260 ) ;
if ( V_66 >= 0 && V_60 -> V_261 )
F_154 ( V_60 , V_66 , V_197 ++ ) ;
V_66 = F_50 ( V_60 , V_262 ) ;
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
V_256 = V_263 ;
else
V_256 = V_264 ;
F_82 ( V_265 , F_55 ( V_256 ) ) ;
}
}
static T_5 F_156 ( void )
{
T_5 V_266 , V_267 ;
F_157 ( V_266 ) ;
V_267 = F_74 ( V_268 ) ;
return V_266 + V_267 ;
}
T_5 F_158 ( struct V_2 * V_3 )
{
T_5 V_266 , V_267 ;
F_157 ( V_266 ) ;
V_267 = F_92 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_269 :
F_74 ( V_268 ) ;
return V_266 + V_267 ;
}
static void F_159 ( struct V_2 * V_3 , T_2 V_270 , bool V_271 )
{
if ( ! V_271 )
return;
if ( V_270 > V_272 ) {
V_3 -> V_97 . V_273 = 1 ;
V_3 -> V_97 . V_274 = 1 ;
} else
F_160 ( 1 , L_6 ) ;
}
static void F_161 ( struct V_2 * V_3 , T_5 V_275 )
{
if ( F_92 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_269 = V_275 ;
V_7 = F_4 ( V_3 ) ;
F_82 ( V_268 , V_275 +
( F_46 ( V_7 , V_276 ) ?
V_7 -> V_267 : 0 ) ) ;
} else {
F_82 ( V_268 , V_275 ) ;
}
}
static void F_162 ( struct V_2 * V_3 , T_10 V_277 , bool V_137 )
{
T_5 V_275 = F_74 ( V_268 ) ;
F_82 ( V_268 , V_275 + V_277 ) ;
if ( F_92 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_269 += V_277 ;
}
}
static T_5 F_163 ( struct V_2 * V_3 , T_5 V_278 )
{
return V_278 - F_164 () ;
}
static bool F_165 ( struct V_2 * V_3 )
{
struct V_279 * V_280 = F_166 ( V_3 , 1 , 0 ) ;
return V_280 && ( V_280 -> V_281 & ( 1 << ( V_282 & 31 ) ) ) ;
}
static inline bool F_167 ( struct V_2 * V_3 )
{
return V_8 && F_165 ( V_3 ) ;
}
static T_11 void F_168 ( void )
{
V_283 = 0x16 ;
V_284 = 0x16 |
V_285 | V_286 |
V_54 ;
V_287 = 0 ;
#ifdef F_75
V_288 = V_289 ;
#else
V_288 = 0 ;
#endif
F_169 ( V_290 ,
V_291 , V_292 ) ;
V_291 = 0 ;
V_292 &=
V_293 | V_294 ;
F_169 ( V_295 ,
V_296 , V_297 ) ;
V_296 = 0 ;
V_297 &=
V_298 | V_276 |
V_299 | V_300 |
V_301 | V_302 |
V_303 |
#ifdef F_75
V_304 | V_305 |
#endif
V_306 | V_307 |
V_308 | V_309 |
V_310 | V_311 |
V_28 ;
V_297 |= V_26 ;
F_169 ( V_312 ,
V_313 , V_314 ) ;
V_313 = 0 ;
V_314 &=
V_30 ;
}
static inline bool F_170 ( T_2 V_315 , T_2 V_316 , T_2 V_317 )
{
return ( ( V_315 & V_317 ) | V_316 ) == V_315 ;
}
static inline T_5 F_171 ( T_2 V_316 , T_2 V_317 )
{
return V_316 | ( ( T_5 ) V_317 << 32 ) ;
}
static int F_172 ( struct V_2 * V_3 , T_2 V_318 , T_5 * V_319 )
{
if ( ! F_167 ( V_3 ) && V_318 >= V_320 &&
V_318 <= V_321 ) {
F_173 ( V_3 , V_322 , 0 ) ;
return 1 ;
}
switch ( V_318 ) {
case V_323 :
* V_319 = 0 ;
break;
case V_320 :
* V_319 = V_324 |
( ( T_5 ) V_325 << V_326 ) |
( V_327 << V_328 ) ;
break;
case V_329 :
case V_330 :
* V_319 = F_171 ( V_283 ,
V_284 ) ;
break;
case V_331 :
case V_295 :
* V_319 = F_171 ( V_296 ,
V_297 ) ;
break;
case V_332 :
case V_333 :
* V_319 = F_171 ( V_287 ,
V_288 ) ;
break;
case V_321 :
case V_290 :
* V_319 = F_171 ( V_291 ,
V_292 ) ;
break;
case V_334 :
* V_319 = 0 ;
break;
#define F_174 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_175 X86_CR4_VMXE
case V_335 :
* V_319 = F_174 ;
break;
case V_336 :
* V_319 = - 1ULL ;
break;
case V_337 :
* V_319 = F_175 ;
break;
case V_338 :
* V_319 = - 1ULL ;
break;
case V_339 :
* V_319 = 0x1f ;
break;
case V_312 :
* V_319 = F_171 ( V_313 ,
V_314 ) ;
break;
case V_340 :
* V_319 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_176 ( struct V_2 * V_3 , T_2 V_318 , T_5 V_166 )
{
if ( ! F_167 ( V_3 ) )
return 0 ;
if ( V_318 == V_323 )
return 1 ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , T_2 V_318 , T_5 * V_319 )
{
T_5 V_166 ;
struct V_73 * V_61 ;
if ( ! V_319 ) {
F_56 ( V_76 L_7 ) ;
return - V_341 ;
}
switch ( V_318 ) {
#ifdef F_75
case V_191 :
V_166 = F_71 ( V_342 ) ;
break;
case V_193 :
V_166 = F_71 ( V_343 ) ;
break;
case V_194 :
F_120 ( F_1 ( V_3 ) ) ;
V_166 = F_1 ( V_3 ) -> V_196 ;
break;
#endif
case V_127 :
return F_178 ( V_3 , V_318 , V_319 ) ;
case V_344 :
V_166 = F_156 () ;
break;
case V_345 :
V_166 = F_73 ( V_346 ) ;
break;
case V_347 :
V_166 = F_71 ( V_348 ) ;
break;
case V_208 :
V_166 = F_71 ( V_349 ) ;
break;
case V_260 :
if ( ! F_1 ( V_3 ) -> V_261 )
return 1 ;
default:
if ( F_172 ( V_3 , V_318 , V_319 ) )
return 0 ;
V_61 = F_53 ( F_1 ( V_3 ) , V_318 ) ;
if ( V_61 ) {
V_166 = V_61 -> V_166 ;
break;
}
return F_178 ( V_3 , V_318 , V_319 ) ;
}
* V_319 = V_166 ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 , T_2 V_318 , T_5 V_166 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_73 * V_61 ;
int V_95 = 0 ;
switch ( V_318 ) {
case V_127 :
V_95 = F_180 ( V_3 , V_318 , V_166 ) ;
break;
#ifdef F_75
case V_191 :
F_85 ( V_60 ) ;
F_78 ( V_342 , V_166 ) ;
break;
case V_193 :
F_85 ( V_60 ) ;
F_78 ( V_343 , V_166 ) ;
break;
case V_194 :
F_120 ( V_60 ) ;
V_60 -> V_196 = V_166 ;
break;
#endif
case V_345 :
F_81 ( V_346 , V_166 ) ;
break;
case V_347 :
F_78 ( V_348 , V_166 ) ;
break;
case V_208 :
F_78 ( V_349 , V_166 ) ;
break;
case V_344 :
F_181 ( V_3 , V_166 ) ;
break;
case V_350 :
if ( V_24 . V_351 & V_293 ) {
F_82 ( V_352 , V_166 ) ;
V_3 -> V_97 . V_353 = V_166 ;
break;
}
V_95 = F_180 ( V_3 , V_318 , V_166 ) ;
break;
case V_260 :
if ( ! V_60 -> V_261 )
return 1 ;
if ( ( V_166 >> 32 ) != 0 )
return 1 ;
default:
if ( F_176 ( V_3 , V_318 , V_166 ) )
break;
V_61 = F_53 ( V_60 , V_318 ) ;
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
V_95 = F_180 ( V_3 , V_318 , V_166 ) ;
}
return V_95 ;
}
static void F_182 ( struct V_2 * V_3 , enum V_354 V_355 )
{
F_139 ( V_355 , ( unsigned long * ) & V_3 -> V_97 . V_98 ) ;
switch ( V_355 ) {
case V_356 :
V_3 -> V_97 . V_357 [ V_356 ] = F_71 ( V_358 ) ;
break;
case V_359 :
V_3 -> V_97 . V_357 [ V_359 ] = F_71 ( V_360 ) ;
break;
case V_361 :
if ( V_86 )
F_183 ( V_3 ) ;
break;
default:
break;
}
}
static T_11 int F_184 ( void )
{
return F_185 () ;
}
static T_11 int F_186 ( void )
{
T_5 V_61 ;
F_109 ( V_323 , V_61 ) ;
if ( V_61 & V_362 ) {
if ( ! ( V_61 & V_363 )
&& F_187 () )
return 1 ;
if ( ! ( V_61 & V_364 )
&& ( V_61 & V_363 )
&& ! F_187 () ) {
F_56 ( V_149 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_61 & V_364 )
&& ! F_187 () )
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
static int F_188 ( void * V_365 )
{
int V_78 = F_60 () ;
T_5 V_75 = F_55 ( F_61 ( V_201 , V_78 ) ) ;
T_5 V_366 , V_367 ;
if ( F_189 () & V_368 )
return - V_369 ;
F_190 ( & F_61 ( V_205 , V_78 ) ) ;
F_109 ( V_323 , V_366 ) ;
V_367 = V_362 ;
V_367 |= V_364 ;
if ( F_187 () )
V_367 |= V_363 ;
if ( ( V_366 & V_367 ) != V_367 ) {
F_111 ( V_323 , V_366 | V_367 ) ;
}
F_191 ( F_189 () | V_368 ) ;
if ( V_202 ) {
F_124 ( V_75 ) ;
F_68 () ;
}
F_192 ( & F_99 ( V_152 ) ) ;
return 0 ;
}
static void F_193 ( void )
{
int V_78 = F_60 () ;
struct V_77 * V_169 , * V_370 ;
F_194 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_59 ( V_169 ) ;
}
static void F_130 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_195 ( void * V_365 )
{
if ( V_202 ) {
F_193 () ;
F_130 () ;
}
F_191 ( F_189 () & ~ V_368 ) ;
}
static T_11 int F_196 ( T_2 V_371 , T_2 V_372 ,
T_2 V_61 , T_2 * V_373 )
{
T_2 V_374 , V_375 ;
T_2 V_376 = V_371 | V_372 ;
F_169 ( V_61 , V_374 , V_375 ) ;
V_376 &= V_375 ;
V_376 |= V_374 ;
if ( V_371 & ~ V_376 )
return - V_377 ;
* V_373 = V_376 ;
return 0 ;
}
static T_11 bool F_197 ( T_2 V_61 , T_2 V_376 )
{
T_2 V_374 , V_375 ;
F_169 ( V_61 , V_374 , V_375 ) ;
return V_375 & V_376 ;
}
static T_11 int F_198 ( struct V_24 * V_378 )
{
T_2 V_374 , V_375 ;
T_2 V_379 , V_380 , V_381 , V_382 ;
T_2 V_383 = 0 ;
T_2 V_384 = 0 ;
T_2 V_385 = 0 ;
T_2 V_386 = 0 ;
T_2 V_387 = 0 ;
V_379 = V_285 | V_286 ;
V_380 = V_54 ;
if ( F_196 ( V_379 , V_380 , V_330 ,
& V_383 ) < 0 )
return - V_377 ;
V_379 = V_299 |
#ifdef F_75
V_304 |
V_305 |
#endif
V_302 |
V_303 |
V_308 |
V_306 |
V_276 |
V_301 |
V_309 |
V_300 |
V_310 ;
V_380 = V_27 |
V_26 |
V_28 ;
if ( F_196 ( V_379 , V_380 , V_295 ,
& V_384 ) < 0 )
return - V_377 ;
#ifdef F_75
if ( ( V_384 & V_27 ) )
V_384 &= ~ V_304 &
~ V_305 ;
#endif
if ( V_384 & V_28 ) {
V_381 = 0 ;
V_382 = V_30 |
V_55 |
V_50 |
V_46 |
V_47 |
V_48 |
V_51 |
V_52 ;
if ( F_196 ( V_381 , V_382 ,
V_312 ,
& V_385 ) < 0 )
return - V_377 ;
}
#ifndef F_75
if ( ! ( V_385 &
V_30 ) )
V_384 &= ~ V_27 ;
#endif
if ( V_385 & V_46 ) {
V_384 &= ~ ( V_302 |
V_303 |
V_300 ) ;
F_169 ( V_340 ,
V_31 . V_32 , V_31 . V_43 ) ;
}
V_379 = 0 ;
#ifdef F_75
V_379 |= V_289 ;
#endif
V_380 = V_388 | V_389 ;
if ( F_196 ( V_379 , V_380 , V_333 ,
& V_386 ) < 0 )
return - V_377 ;
V_379 = 0 ;
V_380 = V_293 ;
if ( F_196 ( V_379 , V_380 , V_290 ,
& V_387 ) < 0 )
return - V_377 ;
F_169 ( V_320 , V_374 , V_375 ) ;
if ( ( V_375 & 0x1fff ) > V_390 )
return - V_377 ;
#ifdef F_75
if ( V_375 & ( 1u << 16 ) )
return - V_377 ;
#endif
if ( ( ( V_375 >> 18 ) & 15 ) != 6 )
return - V_377 ;
V_378 -> V_391 = V_375 & 0x1fff ;
V_378 -> V_392 = F_199 ( V_24 . V_391 ) ;
V_378 -> V_393 = V_374 ;
V_378 -> V_53 = V_383 ;
V_378 -> V_25 = V_384 ;
V_378 -> V_29 = V_385 ;
V_378 -> V_394 = V_386 ;
V_378 -> V_351 = V_387 ;
V_128 =
F_197 ( V_290 ,
V_129 )
&& F_197 ( V_333 ,
V_130 ) ;
V_132 =
F_197 ( V_290 ,
V_133 )
&& F_197 ( V_333 ,
V_134 ) ;
if ( V_132 && V_395 . V_396 == 0x6 ) {
switch ( V_395 . V_397 ) {
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
static struct V_74 * F_200 ( int V_78 )
{
int V_398 = F_201 ( V_78 ) ;
struct V_10 * V_399 ;
struct V_74 * V_74 ;
V_399 = F_202 ( V_398 , V_400 , V_24 . V_392 ) ;
if ( ! V_399 )
return NULL ;
V_74 = F_203 ( V_399 ) ;
memset ( V_74 , 0 , V_24 . V_391 ) ;
V_74 -> V_393 = V_24 . V_393 ;
return V_74 ;
}
static struct V_74 * F_204 ( void )
{
return F_200 ( F_60 () ) ;
}
static void F_205 ( struct V_74 * V_74 )
{
F_206 ( ( unsigned long ) V_74 , V_24 . V_392 ) ;
}
static void F_207 ( struct V_77 * V_77 )
{
if ( ! V_77 -> V_74 )
return;
F_63 ( V_77 ) ;
F_205 ( V_77 -> V_74 ) ;
V_77 -> V_74 = NULL ;
}
static void F_208 ( void )
{
int V_78 ;
F_209 (cpu) {
F_205 ( F_61 ( V_201 , V_78 ) ) ;
F_61 ( V_201 , V_78 ) = NULL ;
}
}
static T_11 int F_210 ( void )
{
int V_78 ;
F_209 (cpu) {
struct V_74 * V_74 ;
V_74 = F_200 ( V_78 ) ;
if ( ! V_74 ) {
F_208 () ;
return - V_401 ;
}
F_61 ( V_201 , V_78 ) = V_74 ;
}
return 0 ;
}
static T_11 int F_211 ( void )
{
if ( F_198 ( & V_24 ) < 0 )
return - V_377 ;
if ( F_212 ( V_402 ) )
F_213 ( V_161 ) ;
if ( ! F_40 () )
V_403 = 0 ;
if ( ! F_36 () ||
! F_29 () ) {
V_86 = 0 ;
V_404 = 0 ;
V_405 = 0 ;
}
if ( ! F_30 () )
V_405 = 0 ;
if ( ! F_37 () )
V_404 = 0 ;
if ( ! F_23 () )
V_49 = 0 ;
if ( ! F_18 () )
V_406 -> V_407 = NULL ;
if ( V_86 && ! F_27 () )
F_214 () ;
if ( ! F_38 () )
V_408 = 0 ;
if ( V_8 )
F_168 () ;
return F_210 () ;
}
static T_12 void F_215 ( void )
{
F_208 () ;
}
static void F_216 ( struct V_2 * V_3 , int V_94 , struct V_409 * V_410 )
{
const struct V_411 * V_412 = & V_103 [ V_94 ] ;
struct V_409 V_255 = * V_410 ;
if ( ! ( F_71 ( V_412 -> V_104 ) == V_255 . V_104 && V_255 . V_171 ) ) {
V_255 . V_104 = F_71 ( V_412 -> V_104 ) ;
V_255 . V_101 = F_72 ( V_412 -> V_101 ) ;
V_255 . V_171 = 1 ;
}
F_217 ( V_3 , & V_255 , V_94 ) ;
}
static void F_218 ( struct V_2 * V_3 )
{
unsigned long V_413 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
V_60 -> V_414 = 1 ;
V_60 -> V_117 . V_118 = 0 ;
F_85 ( V_60 ) ;
F_217 ( V_3 , & V_60 -> V_117 . V_415 [ V_416 ] , V_416 ) ;
V_413 = F_71 ( V_227 ) ;
V_413 &= V_228 ;
V_413 |= V_60 -> V_117 . V_225 & ~ V_228 ;
F_78 ( V_227 , V_413 ) ;
F_78 ( V_417 , ( F_71 ( V_417 ) & ~ V_418 ) |
( F_71 ( V_419 ) & V_418 ) ) ;
F_91 ( V_3 ) ;
if ( V_420 )
return;
F_216 ( V_3 , V_421 , & V_60 -> V_117 . V_415 [ V_421 ] ) ;
F_216 ( V_3 , V_422 , & V_60 -> V_117 . V_415 [ V_422 ] ) ;
F_216 ( V_3 , V_423 , & V_60 -> V_117 . V_415 [ V_423 ] ) ;
F_216 ( V_3 , V_424 , & V_60 -> V_117 . V_415 [ V_424 ] ) ;
F_85 ( V_60 ) ;
F_80 ( V_425 , 0 ) ;
F_81 ( V_426 , 0x93 ) ;
F_80 ( V_427 ,
F_72 ( V_427 ) & ~ V_428 ) ;
F_81 ( V_429 , 0x9b ) ;
}
static T_4 F_219 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_97 . V_430 ) {
struct V_431 * V_432 ;
struct V_433 * V_434 ;
T_13 V_435 ;
V_432 = V_431 ( V_12 ) ;
V_434 = F_220 ( V_432 , 0 ) ;
V_435 = V_434 -> V_435 + V_434 -> V_436 - 3 ;
return V_435 << V_13 ;
}
return V_12 -> V_97 . V_430 ;
}
static void F_221 ( int V_94 , struct V_409 * V_410 )
{
const struct V_411 * V_412 = & V_103 [ V_94 ] ;
F_80 ( V_412 -> V_101 , V_410 -> V_104 >> 4 ) ;
F_81 ( V_412 -> V_104 , V_410 -> V_104 & 0xffff0 ) ;
F_81 ( V_412 -> V_106 , 0xffff ) ;
F_81 ( V_412 -> V_110 , 0xf3 ) ;
if ( V_410 -> V_104 & 0xf )
F_97 ( V_149 L_12
L_13 ,
V_94 ) ;
}
static void F_222 ( struct V_2 * V_3 )
{
unsigned long V_413 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_409 V_437 ;
if ( V_404 )
return;
F_223 ( V_3 , & V_60 -> V_117 . V_415 [ V_416 ] , V_416 ) ;
F_223 ( V_3 , & V_60 -> V_117 . V_415 [ V_421 ] , V_421 ) ;
F_223 ( V_3 , & V_60 -> V_117 . V_415 [ V_422 ] , V_422 ) ;
F_223 ( V_3 , & V_60 -> V_117 . V_415 [ V_423 ] , V_423 ) ;
F_223 ( V_3 , & V_60 -> V_117 . V_415 [ V_424 ] , V_424 ) ;
V_60 -> V_414 = 1 ;
V_60 -> V_117 . V_118 = 1 ;
if ( ! V_3 -> V_12 -> V_97 . V_430 ) {
F_97 ( V_149 L_14
L_15 ) ;
F_224 ( & V_3 -> V_12 -> V_438 , V_3 -> V_439 ) ;
F_225 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_439 = F_226 ( & V_3 -> V_12 -> V_438 ) ;
}
F_85 ( V_60 ) ;
F_78 ( V_440 , F_219 ( V_3 -> V_12 ) ) ;
F_81 ( V_441 , V_442 - 1 ) ;
F_81 ( V_443 , 0x008b ) ;
V_413 = F_71 ( V_227 ) ;
V_60 -> V_117 . V_225 = V_413 ;
V_413 |= V_230 | V_231 ;
F_78 ( V_227 , V_413 ) ;
F_78 ( V_417 , F_71 ( V_417 ) | V_418 ) ;
F_91 ( V_3 ) ;
if ( V_420 )
goto V_444;
F_223 ( V_3 , & V_437 , V_445 ) ;
F_217 ( V_3 , & V_437 , V_445 ) ;
F_223 ( V_3 , & V_437 , V_446 ) ;
F_217 ( V_3 , & V_437 , V_446 ) ;
F_223 ( V_3 , & V_437 , V_421 ) ;
F_217 ( V_3 , & V_437 , V_421 ) ;
F_223 ( V_3 , & V_437 , V_422 ) ;
F_217 ( V_3 , & V_437 , V_422 ) ;
F_223 ( V_3 , & V_437 , V_424 ) ;
F_217 ( V_3 , & V_437 , V_424 ) ;
F_223 ( V_3 , & V_437 , V_423 ) ;
F_217 ( V_3 , & V_437 , V_423 ) ;
V_444:
F_227 ( V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 , T_5 V_160 )
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
V_294 ) ;
V_61 -> V_166 = V_160 ;
} else {
F_81 ( V_123 ,
F_73 ( V_123 ) &
~ V_294 ) ;
V_61 -> V_166 = V_160 & ~ V_164 ;
}
F_155 ( V_60 ) ;
}
static void F_229 ( struct V_2 * V_3 )
{
T_2 V_447 ;
F_85 ( F_1 ( V_3 ) ) ;
V_447 = F_73 ( V_443 ) ;
if ( ( V_447 & V_448 ) != V_449 ) {
F_230 ( L_16 ,
V_450 ) ;
F_81 ( V_443 ,
( V_447 & ~ V_448 )
| V_449 ) ;
}
F_228 ( V_3 , V_3 -> V_97 . V_160 | V_163 ) ;
}
static void F_231 ( struct V_2 * V_3 )
{
F_81 ( V_123 ,
F_73 ( V_123 )
& ~ V_294 ) ;
F_228 ( V_3 , V_3 -> V_97 . V_160 & ~ V_163 ) ;
}
static void F_232 ( struct V_2 * V_3 )
{
F_67 ( F_1 ( V_3 ) ) ;
if ( V_86 ) {
if ( ! F_233 ( V_3 -> V_97 . V_451 . V_452 ) )
return;
F_69 ( F_234 ( V_3 -> V_97 . V_451 . V_452 ) ) ;
}
}
static void F_136 ( struct V_2 * V_3 )
{
T_9 V_214 = V_3 -> V_97 . V_214 ;
V_3 -> V_97 . V_210 &= ~ V_214 ;
V_3 -> V_97 . V_210 |= F_71 ( V_211 ) & V_214 ;
}
static void F_235 ( struct V_2 * V_3 )
{
if ( V_86 && F_236 ( V_3 ) )
V_3 -> V_97 . V_453 = F_71 ( V_454 ) ;
F_139 ( V_455 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
}
static void F_237 ( struct V_2 * V_3 )
{
T_9 V_456 = V_3 -> V_97 . V_456 ;
V_3 -> V_97 . V_457 &= ~ V_456 ;
V_3 -> V_97 . V_457 |= F_71 ( V_417 ) & V_456 ;
}
static void F_238 ( struct V_2 * V_3 )
{
if ( ! F_138 ( V_361 ,
( unsigned long * ) & V_3 -> V_97 . V_458 ) )
return;
if ( F_236 ( V_3 ) && F_239 ( V_3 ) && ! F_110 ( V_3 ) ) {
F_82 ( V_459 , V_3 -> V_97 . V_451 . V_460 [ 0 ] ) ;
F_82 ( V_461 , V_3 -> V_97 . V_451 . V_460 [ 1 ] ) ;
F_82 ( V_462 , V_3 -> V_97 . V_451 . V_460 [ 2 ] ) ;
F_82 ( V_463 , V_3 -> V_97 . V_451 . V_460 [ 3 ] ) ;
}
}
static void F_183 ( struct V_2 * V_3 )
{
if ( F_236 ( V_3 ) && F_239 ( V_3 ) && ! F_110 ( V_3 ) ) {
V_3 -> V_97 . V_451 . V_460 [ 0 ] = F_74 ( V_459 ) ;
V_3 -> V_97 . V_451 . V_460 [ 1 ] = F_74 ( V_461 ) ;
V_3 -> V_97 . V_451 . V_460 [ 2 ] = F_74 ( V_462 ) ;
V_3 -> V_97 . V_451 . V_460 [ 3 ] = F_74 ( V_463 ) ;
}
F_139 ( V_361 ,
( unsigned long * ) & V_3 -> V_97 . V_98 ) ;
F_139 ( V_361 ,
( unsigned long * ) & V_3 -> V_97 . V_458 ) ;
}
static void F_240 ( unsigned long * V_464 ,
unsigned long V_210 ,
struct V_2 * V_3 )
{
if ( ! F_138 ( V_455 , ( T_9 * ) & V_3 -> V_97 . V_98 ) )
F_235 ( V_3 ) ;
if ( ! ( V_210 & V_465 ) ) {
F_81 ( V_466 ,
F_73 ( V_466 ) |
( V_302 |
V_303 ) ) ;
V_3 -> V_97 . V_210 = V_210 ;
F_241 ( V_3 , F_242 ( V_3 ) ) ;
} else if ( ! F_236 ( V_3 ) ) {
F_81 ( V_466 ,
F_73 ( V_466 ) &
~ ( V_302 |
V_303 ) ) ;
V_3 -> V_97 . V_210 = V_210 ;
F_241 ( V_3 , F_242 ( V_3 ) ) ;
}
if ( ! ( V_210 & V_467 ) )
* V_464 &= ~ V_467 ;
}
static void F_243 ( struct V_2 * V_3 , unsigned long V_210 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned long V_464 ;
if ( V_404 )
V_464 = ( V_210 & ~ V_468 )
| V_469 ;
else
V_464 = ( V_210 & ~ V_470 ) | V_471 ;
if ( V_60 -> V_117 . V_118 && ( V_210 & V_472 ) )
F_218 ( V_3 ) ;
if ( ! V_60 -> V_117 . V_118 && ! ( V_210 & V_472 ) )
F_222 ( V_3 ) ;
#ifdef F_75
if ( V_3 -> V_97 . V_160 & V_164 ) {
if ( ! F_236 ( V_3 ) && ( V_210 & V_465 ) )
F_229 ( V_3 ) ;
if ( F_236 ( V_3 ) && ! ( V_210 & V_465 ) )
F_231 ( V_3 ) ;
}
#endif
if ( V_86 )
F_240 ( & V_464 , V_210 , V_3 ) ;
if ( ! V_3 -> V_119 )
V_464 |= V_212 | V_213 ;
F_78 ( V_223 , V_210 ) ;
F_78 ( V_211 , V_464 ) ;
V_3 -> V_97 . V_210 = V_210 ;
F_141 ( V_229 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
}
static T_5 F_234 ( unsigned long V_452 )
{
T_5 V_71 ;
V_71 = V_473 |
V_474 << V_475 ;
if ( V_405 )
V_71 |= V_476 ;
V_71 |= ( V_452 & V_477 ) ;
return V_71 ;
}
static void F_244 ( struct V_2 * V_3 , unsigned long V_453 )
{
unsigned long V_478 ;
T_5 V_71 ;
V_478 = V_453 ;
if ( V_86 ) {
V_71 = F_234 ( V_453 ) ;
F_82 ( V_479 , V_71 ) ;
V_478 = F_236 ( V_3 ) ? F_245 ( V_3 ) :
V_3 -> V_12 -> V_97 . V_480 ;
F_238 ( V_3 ) ;
}
F_232 ( V_3 ) ;
F_78 ( V_454 , V_478 ) ;
}
static int F_241 ( struct V_2 * V_3 , unsigned long V_457 )
{
unsigned long V_481 = V_457 | ( F_1 ( V_3 ) -> V_117 . V_118 ?
V_482 : V_483 ) ;
if ( V_457 & V_368 ) {
if ( ! F_167 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_484 )
return 1 ;
V_3 -> V_97 . V_457 = V_457 ;
if ( V_86 ) {
if ( ! F_236 ( V_3 ) ) {
V_481 &= ~ V_485 ;
V_481 |= V_486 ;
} else if ( ! ( V_457 & V_485 ) ) {
V_481 &= ~ V_485 ;
}
}
F_78 ( V_419 , V_457 ) ;
F_78 ( V_417 , V_481 ) ;
return 0 ;
}
static void F_223 ( struct V_2 * V_3 ,
struct V_409 * V_437 , int V_94 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_108 ;
if ( V_60 -> V_117 . V_118
&& ( V_94 == V_416 || V_94 == V_421
|| V_94 == V_422 || V_94 == V_423
|| V_94 == V_424 ) ) {
* V_437 = V_60 -> V_117 . V_415 [ V_94 ] ;
if ( V_94 == V_416
|| V_437 -> V_101 == F_87 ( V_60 , V_94 ) )
return;
V_437 -> V_104 = F_88 ( V_60 , V_94 ) ;
V_437 -> V_101 = F_87 ( V_60 , V_94 ) ;
return;
}
V_437 -> V_104 = F_88 ( V_60 , V_94 ) ;
V_437 -> V_106 = F_89 ( V_60 , V_94 ) ;
V_437 -> V_101 = F_87 ( V_60 , V_94 ) ;
V_108 = F_90 ( V_60 , V_94 ) ;
if ( ( V_108 & V_487 ) && ! V_420 )
V_108 = 0 ;
V_437 -> type = V_108 & 15 ;
V_437 -> V_171 = ( V_108 >> 4 ) & 1 ;
V_437 -> V_488 = ( V_108 >> 5 ) & 3 ;
V_437 -> V_489 = ( V_108 >> 7 ) & 1 ;
V_437 -> V_490 = ( V_108 >> 12 ) & 1 ;
V_437 -> V_491 = ( V_108 >> 13 ) & 1 ;
V_437 -> V_492 = ( V_108 >> 14 ) & 1 ;
V_437 -> V_493 = ( V_108 >> 15 ) & 1 ;
V_437 -> V_494 = ( V_108 >> 16 ) & 1 ;
}
static T_5 F_246 ( struct V_2 * V_3 , int V_94 )
{
struct V_409 V_171 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
F_223 ( V_3 , & V_171 , V_94 ) ;
return V_171 . V_104 ;
}
return F_88 ( F_1 ( V_3 ) , V_94 ) ;
}
static int F_247 ( struct V_2 * V_3 )
{
if ( ! F_248 ( V_3 ) )
return 0 ;
if ( ! F_110 ( V_3 )
&& ( F_249 ( V_3 ) & V_231 ) )
return 3 ;
return F_87 ( F_1 ( V_3 ) , V_446 ) & 3 ;
}
static int F_250 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( F_79 ( V_60 -> V_414 && V_420 ) ) {
return V_60 -> V_495 ;
}
if ( ! F_138 ( V_229 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ) {
F_139 ( V_229 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
V_60 -> V_495 = F_247 ( V_3 ) ;
}
return V_60 -> V_495 ;
}
static T_2 F_251 ( struct V_409 * V_437 )
{
T_2 V_108 ;
if ( V_437 -> V_494 || ! V_437 -> V_489 )
V_108 = 1 << 16 ;
else {
V_108 = V_437 -> type & 15 ;
V_108 |= ( V_437 -> V_171 & 1 ) << 4 ;
V_108 |= ( V_437 -> V_488 & 3 ) << 5 ;
V_108 |= ( V_437 -> V_489 & 1 ) << 7 ;
V_108 |= ( V_437 -> V_490 & 1 ) << 12 ;
V_108 |= ( V_437 -> V_491 & 1 ) << 13 ;
V_108 |= ( V_437 -> V_492 & 1 ) << 14 ;
V_108 |= ( V_437 -> V_493 & 1 ) << 15 ;
}
return V_108 ;
}
static void F_217 ( struct V_2 * V_3 ,
struct V_409 * V_437 , int V_94 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
const struct V_411 * V_412 = & V_103 [ V_94 ] ;
T_2 V_108 ;
F_85 ( V_60 ) ;
if ( V_60 -> V_117 . V_118 && V_94 == V_416 ) {
F_80 ( V_412 -> V_101 , V_437 -> V_101 ) ;
V_60 -> V_117 . V_415 [ V_416 ] = * V_437 ;
return;
}
F_78 ( V_412 -> V_104 , V_437 -> V_104 ) ;
F_81 ( V_412 -> V_106 , V_437 -> V_106 ) ;
F_80 ( V_412 -> V_101 , V_437 -> V_101 ) ;
if ( V_60 -> V_117 . V_118 && V_437 -> V_171 ) {
V_60 -> V_117 . V_415 [ V_94 ] = * V_437 ;
if ( V_437 -> V_104 == 0xffff0000 && V_437 -> V_101 == 0xf000 )
F_78 ( V_412 -> V_104 , 0xf0000 ) ;
V_108 = 0xf3 ;
} else
V_108 = F_251 ( V_437 ) ;
if ( V_404 && ( V_94 != V_496 ) )
V_108 |= 0x1 ;
F_81 ( V_412 -> V_110 , V_108 ) ;
F_141 ( V_229 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
if ( ! V_404 && V_60 -> V_117 . V_118 ) {
switch ( V_94 ) {
case V_446 :
F_81 ( V_429 , 0xf3 ) ;
F_81 ( V_497 , 0xffff ) ;
if ( F_71 ( V_498 ) == 0xffff0000 )
F_78 ( V_498 , 0xf0000 ) ;
F_80 ( V_427 ,
F_71 ( V_498 ) >> 4 ) ;
break;
case V_421 :
case V_422 :
case V_424 :
case V_423 :
F_221 ( V_94 , & V_60 -> V_117 . V_415 [ V_94 ] ) ;
break;
case V_445 :
F_80 ( V_425 ,
F_71 ( V_499 ) >> 4 ) ;
F_81 ( V_500 , 0xffff ) ;
F_81 ( V_426 , 0xf3 ) ;
break;
}
}
}
static void F_252 ( struct V_2 * V_3 , int * V_492 , int * V_491 )
{
T_2 V_108 = F_90 ( F_1 ( V_3 ) , V_446 ) ;
* V_492 = ( V_108 >> 14 ) & 1 ;
* V_491 = ( V_108 >> 13 ) & 1 ;
}
static void F_253 ( struct V_2 * V_3 , struct V_150 * V_501 )
{
V_501 -> V_391 = F_73 ( V_502 ) ;
V_501 -> V_155 = F_71 ( V_503 ) ;
}
static void F_254 ( struct V_2 * V_3 , struct V_150 * V_501 )
{
F_81 ( V_502 , V_501 -> V_391 ) ;
F_78 ( V_503 , V_501 -> V_155 ) ;
}
static void F_255 ( struct V_2 * V_3 , struct V_150 * V_501 )
{
V_501 -> V_391 = F_73 ( V_504 ) ;
V_501 -> V_155 = F_71 ( V_505 ) ;
}
static void F_256 ( struct V_2 * V_3 , struct V_150 * V_501 )
{
F_81 ( V_504 , V_501 -> V_391 ) ;
F_78 ( V_505 , V_501 -> V_155 ) ;
}
static bool F_257 ( struct V_2 * V_3 , int V_94 )
{
struct V_409 V_437 ;
T_2 V_108 ;
F_223 ( V_3 , & V_437 , V_94 ) ;
V_108 = F_251 ( & V_437 ) ;
if ( V_437 . V_104 != ( V_437 . V_101 << 4 ) )
return false ;
if ( V_437 . V_106 < 0xffff )
return false ;
if ( ( ( V_108 | ( 3 << V_506 ) ) & ~ ( V_507 | V_508 ) ) != 0xf3 )
return false ;
return true ;
}
static bool F_258 ( struct V_2 * V_3 )
{
struct V_409 V_509 ;
unsigned int V_510 ;
F_223 ( V_3 , & V_509 , V_446 ) ;
V_510 = V_509 . V_101 & V_428 ;
if ( V_509 . V_494 )
return false ;
if ( ~ V_509 . type & ( V_511 | V_512 ) )
return false ;
if ( ! V_509 . V_171 )
return false ;
if ( V_509 . type & V_513 ) {
if ( V_509 . V_488 > V_510 )
return false ;
} else {
if ( V_509 . V_488 != V_510 )
return false ;
}
if ( ! V_509 . V_489 )
return false ;
return true ;
}
static bool F_259 ( struct V_2 * V_3 )
{
struct V_409 V_514 ;
unsigned int V_515 ;
F_223 ( V_3 , & V_514 , V_445 ) ;
V_515 = V_514 . V_101 & V_428 ;
if ( V_514 . V_494 )
return true ;
if ( V_514 . type != 3 && V_514 . type != 7 )
return false ;
if ( ! V_514 . V_171 )
return false ;
if ( V_514 . V_488 != V_515 )
return false ;
if ( ! V_514 . V_489 )
return false ;
return true ;
}
static bool F_260 ( struct V_2 * V_3 , int V_94 )
{
struct V_409 V_437 ;
unsigned int V_516 ;
F_223 ( V_3 , & V_437 , V_94 ) ;
V_516 = V_437 . V_101 & V_428 ;
if ( V_437 . V_494 )
return true ;
if ( ! V_437 . V_171 )
return false ;
if ( ! V_437 . V_489 )
return false ;
if ( ~ V_437 . type & ( V_511 | V_513 ) ) {
if ( V_437 . V_488 < V_516 )
return false ;
}
return true ;
}
static bool F_261 ( struct V_2 * V_3 )
{
struct V_409 V_174 ;
F_223 ( V_3 , & V_174 , V_416 ) ;
if ( V_174 . V_494 )
return false ;
if ( V_174 . V_101 & V_517 )
return false ;
if ( V_174 . type != 3 && V_174 . type != 11 )
return false ;
if ( ! V_174 . V_489 )
return false ;
return true ;
}
static bool F_262 ( struct V_2 * V_3 )
{
struct V_409 V_518 ;
F_223 ( V_3 , & V_518 , V_496 ) ;
if ( V_518 . V_494 )
return true ;
if ( V_518 . V_101 & V_517 )
return false ;
if ( V_518 . type != 2 )
return false ;
if ( ! V_518 . V_489 )
return false ;
return true ;
}
static bool F_263 ( struct V_2 * V_3 )
{
struct V_409 V_509 , V_514 ;
F_223 ( V_3 , & V_509 , V_446 ) ;
F_223 ( V_3 , & V_514 , V_445 ) ;
return ( ( V_509 . V_101 & V_428 ) ==
( V_514 . V_101 & V_428 ) ) ;
}
static bool F_264 ( struct V_2 * V_3 )
{
if ( ! F_248 ( V_3 ) ) {
if ( ! F_257 ( V_3 , V_446 ) )
return false ;
if ( ! F_257 ( V_3 , V_445 ) )
return false ;
if ( ! F_257 ( V_3 , V_422 ) )
return false ;
if ( ! F_257 ( V_3 , V_421 ) )
return false ;
if ( ! F_257 ( V_3 , V_423 ) )
return false ;
if ( ! F_257 ( V_3 , V_424 ) )
return false ;
} else {
if ( ! F_263 ( V_3 ) )
return false ;
if ( ! F_258 ( V_3 ) )
return false ;
if ( ! F_259 ( V_3 ) )
return false ;
if ( ! F_260 ( V_3 , V_422 ) )
return false ;
if ( ! F_260 ( V_3 , V_421 ) )
return false ;
if ( ! F_260 ( V_3 , V_423 ) )
return false ;
if ( ! F_260 ( V_3 , V_424 ) )
return false ;
if ( ! F_261 ( V_3 ) )
return false ;
if ( ! F_262 ( V_3 ) )
return false ;
}
return true ;
}
static int F_265 ( struct V_12 * V_12 )
{
T_13 V_519 ;
T_3 V_166 = 0 ;
int V_520 , V_521 , V_95 = 0 ;
V_521 = F_226 ( & V_12 -> V_438 ) ;
V_519 = F_219 ( V_12 ) >> V_13 ;
V_520 = F_266 ( V_12 , V_519 , 0 , V_390 ) ;
if ( V_520 < 0 )
goto V_522;
V_166 = V_523 + V_524 ;
V_520 = F_267 ( V_12 , V_519 ++ , & V_166 ,
V_525 , sizeof( T_3 ) ) ;
if ( V_520 < 0 )
goto V_522;
V_520 = F_266 ( V_12 , V_519 ++ , 0 , V_390 ) ;
if ( V_520 < 0 )
goto V_522;
V_520 = F_266 ( V_12 , V_519 , 0 , V_390 ) ;
if ( V_520 < 0 )
goto V_522;
V_166 = ~ 0 ;
V_520 = F_267 ( V_12 , V_519 , & V_166 ,
V_442 - 2 * V_390 - 1 ,
sizeof( T_6 ) ) ;
if ( V_520 < 0 )
goto V_522;
V_95 = 1 ;
V_522:
F_224 ( & V_12 -> V_438 , V_521 ) ;
return V_95 ;
}
static int F_268 ( struct V_12 * V_12 )
{
int V_62 , V_521 , V_520 , V_95 ;
T_14 V_526 ;
T_2 V_255 ;
if ( ! V_86 )
return 1 ;
if ( F_79 ( ! V_12 -> V_97 . V_527 ) ) {
F_56 ( V_76 L_17
L_18 ) ;
return 0 ;
}
if ( F_269 ( V_12 -> V_97 . V_528 ) )
return 1 ;
V_95 = 0 ;
V_526 = V_12 -> V_97 . V_480 >> V_13 ;
V_521 = F_226 ( & V_12 -> V_438 ) ;
V_520 = F_266 ( V_12 , V_526 , 0 , V_390 ) ;
if ( V_520 < 0 )
goto V_522;
for ( V_62 = 0 ; V_62 < V_529 ; V_62 ++ ) {
V_255 = ( V_62 << 22 ) + ( V_530 | V_531 | V_532 |
V_533 | V_534 | V_535 ) ;
V_520 = F_267 ( V_12 , V_526 ,
& V_255 , V_62 * sizeof( V_255 ) , sizeof( V_255 ) ) ;
if ( V_520 < 0 )
goto V_522;
}
V_12 -> V_97 . V_528 = true ;
V_95 = 1 ;
V_522:
F_224 ( & V_12 -> V_438 , V_521 ) ;
return V_95 ;
}
static void F_270 ( int V_94 )
{
const struct V_411 * V_412 = & V_103 [ V_94 ] ;
unsigned int V_108 ;
F_80 ( V_412 -> V_101 , 0 ) ;
F_78 ( V_412 -> V_104 , 0 ) ;
F_81 ( V_412 -> V_106 , 0xffff ) ;
if ( V_404 ) {
V_108 = 0x93 ;
if ( V_94 == V_446 )
V_108 |= 0x08 ;
} else
V_108 = 0xf3 ;
F_81 ( V_412 -> V_110 , V_108 ) ;
}
static int F_271 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_536 V_537 ;
int V_520 = 0 ;
F_272 ( & V_12 -> V_538 ) ;
if ( V_12 -> V_97 . V_539 )
goto V_522;
V_537 . V_434 = V_540 ;
V_537 . V_413 = 0 ;
V_537 . V_541 = 0xfee00000ULL ;
V_537 . V_542 = V_390 ;
V_520 = F_273 ( V_12 , & V_537 , 0 ) ;
if ( V_520 )
goto V_522;
V_10 = F_6 ( V_12 , 0xfee00 ) ;
if ( F_7 ( V_10 ) ) {
V_520 = - V_543 ;
goto V_522;
}
V_12 -> V_97 . V_539 = V_10 ;
V_522:
F_274 ( & V_12 -> V_538 ) ;
return V_520 ;
}
static int F_275 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_536 V_537 ;
int V_520 = 0 ;
F_272 ( & V_12 -> V_538 ) ;
if ( V_12 -> V_97 . V_527 )
goto V_522;
V_537 . V_434 = V_544 ;
V_537 . V_413 = 0 ;
V_537 . V_541 =
V_12 -> V_97 . V_480 ;
V_537 . V_542 = V_390 ;
V_520 = F_273 ( V_12 , & V_537 , 0 ) ;
if ( V_520 )
goto V_522;
V_10 = F_6 ( V_12 , V_12 -> V_97 . V_480 >> V_13 ) ;
if ( F_7 ( V_10 ) ) {
V_520 = - V_543 ;
goto V_522;
}
V_12 -> V_97 . V_527 = V_10 ;
V_522:
F_274 ( & V_12 -> V_538 ) ;
return V_520 ;
}
static void F_276 ( struct V_1 * V_60 )
{
int V_43 ;
V_60 -> V_43 = 0 ;
if ( ! V_403 )
return;
F_277 ( & V_545 ) ;
V_43 = F_278 ( V_546 , V_547 ) ;
if ( V_43 < V_547 ) {
V_60 -> V_43 = V_43 ;
F_139 ( V_43 , V_546 ) ;
}
F_279 ( & V_545 ) ;
}
static void F_280 ( struct V_1 * V_60 )
{
if ( ! V_403 )
return;
F_277 ( & V_545 ) ;
if ( V_60 -> V_43 != 0 )
F_141 ( V_60 -> V_43 , V_546 ) ;
F_279 ( & V_545 ) ;
}
static void F_281 ( unsigned long * V_256 , T_2 V_61 )
{
int V_548 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_61 <= 0x1fff ) {
F_141 ( V_61 , V_256 + 0x000 / V_548 ) ;
F_141 ( V_61 , V_256 + 0x800 / V_548 ) ;
} else if ( ( V_61 >= 0xc0000000 ) && ( V_61 <= 0xc0001fff ) ) {
V_61 &= 0x1fff ;
F_141 ( V_61 , V_256 + 0x400 / V_548 ) ;
F_141 ( V_61 , V_256 + 0xc00 / V_548 ) ;
}
}
static void F_282 ( T_2 V_61 , bool V_549 )
{
if ( ! V_549 )
F_281 ( V_264 , V_61 ) ;
F_281 ( V_263 , V_61 ) ;
}
static void F_283 ( void )
{
T_2 V_550 , V_551 ;
unsigned long V_552 ;
struct V_150 V_501 ;
F_78 ( V_553 , F_284 () & ~ V_212 ) ;
F_78 ( V_554 , F_189 () ) ;
F_78 ( V_555 , F_285 () ) ;
F_80 ( V_556 , V_557 ) ;
#ifdef F_75
F_80 ( V_558 , 0 ) ;
F_80 ( V_559 , 0 ) ;
#else
F_80 ( V_558 , V_560 ) ;
F_80 ( V_559 , V_560 ) ;
#endif
F_80 ( V_561 , V_560 ) ;
F_80 ( V_562 , V_156 * 8 ) ;
F_286 ( & V_501 ) ;
F_78 ( V_563 , V_501 . V_155 ) ;
F_78 ( V_564 , V_565 ) ;
F_169 ( V_345 , V_550 , V_551 ) ;
F_81 ( V_566 , V_550 ) ;
F_109 ( V_347 , V_552 ) ;
F_78 ( V_567 , V_552 ) ;
if ( V_24 . V_394 & V_389 ) {
F_169 ( V_350 , V_550 , V_551 ) ;
F_82 ( V_568 , V_550 | ( ( T_5 ) V_551 << 32 ) ) ;
}
}
static void F_287 ( struct V_1 * V_60 )
{
V_60 -> V_3 . V_97 . V_456 = V_569 ;
if ( V_86 )
V_60 -> V_3 . V_97 . V_456 |= V_570 ;
if ( F_92 ( & V_60 -> V_3 ) )
V_60 -> V_3 . V_97 . V_456 &=
~ F_4 ( & V_60 -> V_3 ) -> V_221 ;
F_78 ( V_571 , ~ V_60 -> V_3 . V_97 . V_456 ) ;
}
static T_2 F_288 ( struct V_1 * V_60 )
{
T_2 V_572 = V_24 . V_25 ;
if ( ! F_19 ( V_60 -> V_3 . V_12 ) ) {
V_572 &= ~ V_27 ;
#ifdef F_75
V_572 |= V_305 |
V_304 ;
#endif
}
if ( ! V_86 )
V_572 |= V_303 |
V_302 |
V_300 ;
return V_572 ;
}
static T_2 F_289 ( struct V_1 * V_60 )
{
T_2 V_572 = V_24 . V_29 ;
if ( ! F_39 ( V_60 -> V_3 . V_12 ) )
V_572 &= ~ V_30 ;
if ( V_60 -> V_43 == 0 )
V_572 &= ~ V_50 ;
if ( ! V_86 ) {
V_572 &= ~ V_46 ;
V_404 = 0 ;
V_572 &= ~ V_52 ;
}
if ( ! V_404 )
V_572 &= ~ V_47 ;
if ( ! V_408 )
V_572 &= ~ V_48 ;
return V_572 ;
}
static void F_290 ( void )
{
F_291 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_292 ( struct V_1 * V_60 )
{
#ifdef F_75
unsigned long V_573 ;
#endif
int V_62 ;
F_82 ( V_574 , F_55 ( V_575 ) ) ;
F_82 ( V_576 , F_55 ( V_577 ) ) ;
if ( F_17 () )
F_82 ( V_265 , F_55 ( V_264 ) ) ;
F_82 ( V_578 , - 1ull ) ;
F_81 ( V_579 ,
V_24 . V_53 ) ;
F_81 ( V_466 , F_288 ( V_60 ) ) ;
if ( F_21 () ) {
F_81 ( V_580 ,
F_289 ( V_60 ) ) ;
}
if ( V_408 ) {
F_81 ( V_581 , V_408 ) ;
F_81 ( V_582 , V_583 ) ;
}
F_81 ( V_584 , 0 ) ;
F_81 ( V_585 , 0 ) ;
F_81 ( V_586 , 0 ) ;
F_80 ( V_181 , 0 ) ;
F_80 ( V_185 , 0 ) ;
F_283 () ;
#ifdef F_75
F_109 ( V_191 , V_573 ) ;
F_78 ( V_190 , V_573 ) ;
F_109 ( V_193 , V_573 ) ;
F_78 ( V_192 , V_573 ) ;
#else
F_78 ( V_190 , 0 ) ;
F_78 ( V_192 , 0 ) ;
#endif
F_81 ( V_587 , 0 ) ;
F_81 ( V_139 , 0 ) ;
F_82 ( V_588 , F_55 ( V_60 -> V_125 . V_137 ) ) ;
F_81 ( V_138 , 0 ) ;
F_82 ( V_589 , F_55 ( V_60 -> V_125 . V_136 ) ) ;
if ( V_24 . V_351 & V_293 ) {
T_2 V_590 , V_591 ;
T_5 V_592 ;
F_169 ( V_350 , V_590 , V_591 ) ;
V_592 = V_590 | ( ( T_5 ) V_591 << 32 ) ;
F_82 ( V_352 , V_592 ) ;
V_60 -> V_3 . V_97 . V_353 = V_592 ;
}
for ( V_62 = 0 ; V_62 < V_593 ; ++ V_62 ) {
T_2 V_66 = V_64 [ V_62 ] ;
T_2 V_594 , V_595 ;
int V_596 = V_60 -> V_63 ;
if ( F_293 ( V_66 , & V_594 , & V_595 ) < 0 )
continue;
if ( F_294 ( V_66 , V_594 , V_595 ) < 0 )
continue;
V_60 -> V_65 [ V_596 ] . V_66 = V_62 ;
V_60 -> V_65 [ V_596 ] . V_166 = 0 ;
V_60 -> V_65 [ V_596 ] . V_91 = - 1ull ;
++ V_60 -> V_63 ;
}
F_81 ( V_124 , V_24 . V_394 ) ;
F_81 ( V_123 , V_24 . V_351 ) ;
F_78 ( V_216 , ~ 0UL ) ;
F_287 ( V_60 ) ;
F_181 ( & V_60 -> V_3 , 0 ) ;
return 0 ;
}
static int F_295 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_5 V_61 ;
int V_95 ;
V_3 -> V_97 . V_98 = ~ ( ( 1 << V_359 ) | ( 1 << V_356 ) ) ;
V_60 -> V_117 . V_118 = 0 ;
V_60 -> V_597 = 0 ;
V_60 -> V_3 . V_97 . V_357 [ V_598 ] = F_296 () ;
F_297 ( & V_60 -> V_3 , 0 ) ;
V_61 = 0xfee00000 | V_599 ;
if ( F_298 ( & V_60 -> V_3 ) )
V_61 |= V_600 ;
F_299 ( & V_60 -> V_3 , V_61 ) ;
V_95 = F_300 ( & V_60 -> V_3 ) ;
if ( V_95 != 0 )
goto V_522;
F_85 ( V_60 ) ;
F_270 ( V_446 ) ;
if ( F_298 ( & V_60 -> V_3 ) ) {
F_80 ( V_427 , 0xf000 ) ;
F_78 ( V_498 , 0x000f0000 ) ;
} else {
F_80 ( V_427 , V_60 -> V_3 . V_97 . V_601 << 8 ) ;
F_78 ( V_498 , V_60 -> V_3 . V_97 . V_601 << 12 ) ;
}
F_270 ( V_422 ) ;
F_270 ( V_421 ) ;
F_270 ( V_423 ) ;
F_270 ( V_424 ) ;
F_270 ( V_445 ) ;
F_80 ( V_602 , 0 ) ;
F_78 ( V_440 , 0 ) ;
F_81 ( V_441 , 0xffff ) ;
F_81 ( V_443 , 0x008b ) ;
F_80 ( V_603 , 0 ) ;
F_78 ( V_604 , 0 ) ;
F_81 ( V_605 , 0xffff ) ;
F_81 ( V_606 , 0x00082 ) ;
F_81 ( V_346 , 0 ) ;
F_78 ( V_349 , 0 ) ;
F_78 ( V_348 , 0 ) ;
F_78 ( V_227 , 0x02 ) ;
if ( F_298 ( & V_60 -> V_3 ) )
F_146 ( V_3 , 0xfff0 ) ;
else
F_146 ( V_3 , 0 ) ;
F_301 ( V_3 , V_356 , 0 ) ;
F_78 ( V_505 , 0 ) ;
F_81 ( V_504 , 0xffff ) ;
F_78 ( V_503 , 0 ) ;
F_81 ( V_502 , 0xffff ) ;
F_81 ( V_607 , V_608 ) ;
F_81 ( V_233 , 0 ) ;
F_81 ( V_609 , 0 ) ;
F_82 ( V_610 , 0 ) ;
F_155 ( V_60 ) ;
F_81 ( V_252 , 0 ) ;
if ( F_18 () ) {
F_82 ( V_611 , 0 ) ;
if ( F_19 ( V_60 -> V_3 . V_12 ) )
F_82 ( V_611 ,
F_55 ( V_60 -> V_3 . V_97 . V_612 -> V_357 ) ) ;
F_81 ( V_613 , 0 ) ;
}
if ( F_39 ( V_60 -> V_3 . V_12 ) )
F_82 ( V_614 ,
F_302 ( V_60 -> V_3 . V_12 -> V_97 . V_539 ) ) ;
if ( V_60 -> V_43 != 0 )
F_80 ( V_615 , V_60 -> V_43 ) ;
V_60 -> V_3 . V_97 . V_210 = V_616 | V_617 | V_618 ;
V_3 -> V_439 = F_226 ( & V_3 -> V_12 -> V_438 ) ;
F_243 ( & V_60 -> V_3 , F_303 ( V_3 ) ) ;
F_224 ( & V_3 -> V_12 -> V_438 , V_3 -> V_439 ) ;
F_241 ( & V_60 -> V_3 , 0 ) ;
F_228 ( & V_60 -> V_3 , 0 ) ;
F_131 ( & V_60 -> V_3 ) ;
F_91 ( & V_60 -> V_3 ) ;
F_67 ( V_60 ) ;
V_95 = 0 ;
V_60 -> V_414 = 0 ;
V_522:
return V_95 ;
}
static bool F_304 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_59 &
V_285 ;
}
static void F_305 ( struct V_2 * V_3 )
{
T_2 V_57 ;
if ( F_92 ( V_3 ) && F_304 ( V_3 ) ) {
F_125 ( V_619 , V_3 ) ;
return;
}
V_57 = F_73 ( V_466 ) ;
V_57 |= V_298 ;
F_81 ( V_466 , V_57 ) ;
}
static void F_306 ( struct V_2 * V_3 )
{
T_2 V_57 ;
if ( ! F_43 () ) {
F_305 ( V_3 ) ;
return;
}
if ( F_73 ( V_233 ) & V_234 ) {
F_305 ( V_3 ) ;
return;
}
V_57 = F_73 ( V_466 ) ;
V_57 |= V_620 ;
F_81 ( V_466 , V_57 ) ;
}
static void F_307 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_15 V_621 ;
int V_622 = V_3 -> V_97 . V_623 . V_135 ;
F_308 ( V_622 ) ;
++ V_3 -> V_198 . V_624 ;
if ( V_60 -> V_117 . V_118 ) {
int V_246 = 0 ;
if ( V_3 -> V_97 . V_623 . V_625 )
V_246 = V_3 -> V_97 . V_247 ;
if ( F_151 ( V_3 , V_622 , V_246 ) != V_248 )
F_125 ( V_249 , V_3 ) ;
return;
}
V_621 = V_622 | V_17 ;
if ( V_3 -> V_97 . V_623 . V_625 ) {
V_621 |= V_626 ;
F_81 ( V_250 ,
V_60 -> V_3 . V_97 . V_247 ) ;
} else
V_621 |= V_22 ;
F_81 ( V_252 , V_621 ) ;
}
static void F_309 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( F_92 ( V_3 ) )
return;
if ( ! F_43 () ) {
V_60 -> V_597 = 1 ;
V_60 -> V_627 = 0 ;
}
++ V_3 -> V_198 . V_628 ;
V_60 -> V_629 = false ;
if ( V_60 -> V_117 . V_118 ) {
if ( F_151 ( V_3 , V_630 , 0 ) != V_248 )
F_125 ( V_249 , V_3 ) ;
return;
}
F_81 ( V_252 ,
V_631 | V_17 | V_630 ) ;
}
static int F_310 ( struct V_2 * V_3 )
{
if ( ! F_43 () && F_1 ( V_3 ) -> V_597 )
return 0 ;
return ! ( F_73 ( V_233 ) &
( V_236 | V_234
| V_632 ) ) ;
}
static bool F_311 ( struct V_2 * V_3 )
{
if ( ! F_43 () )
return F_1 ( V_3 ) -> V_597 ;
if ( F_1 ( V_3 ) -> V_629 )
return false ;
return F_73 ( V_233 ) & V_632 ;
}
static void F_312 ( struct V_2 * V_3 , bool V_633 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( ! F_43 () ) {
if ( V_60 -> V_597 != V_633 ) {
V_60 -> V_597 = V_633 ;
V_60 -> V_627 = 0 ;
}
} else {
V_60 -> V_629 = ! V_633 ;
if ( V_633 )
F_84 ( V_233 ,
V_632 ) ;
else
F_83 ( V_233 ,
V_632 ) ;
}
}
static int F_313 ( struct V_2 * V_3 )
{
if ( F_92 ( V_3 ) && F_304 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_634 ||
( V_7 -> V_635 &
V_636 ) )
return 0 ;
F_148 ( V_3 ) ;
V_7 -> V_637 = V_638 ;
V_7 -> V_639 = 0 ;
}
return ( F_71 ( V_227 ) & V_640 ) &&
! ( F_73 ( V_233 ) &
( V_234 | V_236 ) ) ;
}
static int F_225 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_95 ;
struct V_536 V_641 = {
. V_434 = V_642 ,
. V_541 = V_11 ,
. V_542 = V_390 * 3 ,
. V_413 = 0 ,
} ;
V_95 = F_314 ( V_12 , & V_641 , 0 ) ;
if ( V_95 )
return V_95 ;
V_12 -> V_97 . V_430 = V_11 ;
if ( ! F_265 ( V_12 ) )
return - V_401 ;
return 0 ;
}
static int F_315 ( struct V_2 * V_3 ,
int V_643 , T_2 V_644 )
{
if ( ( ( V_643 == V_322 ) || ( V_643 == V_645 ) ) && V_644 == 0 )
if ( F_316 ( V_3 , 0 ) == V_248 )
return 1 ;
switch ( V_643 ) {
case V_112 :
if ( V_3 -> V_113 &
( V_646 | V_647 ) )
return 0 ;
F_317 ( V_3 , V_643 ) ;
return 1 ;
case V_116 :
F_1 ( V_3 ) -> V_3 . V_97 . V_247 =
F_73 ( V_240 ) ;
if ( V_3 -> V_113 & V_115 )
return 0 ;
case V_648 :
case V_649 :
case V_650 :
case V_21 :
case V_651 :
case V_645 :
case V_322 :
case V_652 :
F_317 ( V_3 , V_643 ) ;
return 1 ;
}
return 0 ;
}
static void F_318 ( void )
{
#if F_319 ( V_653 ) && F_319 ( F_75 )
struct V_654 V_357 = {
. V_509 = 3 ,
. V_413 = V_640 ,
} ;
F_320 ( & V_357 , 0 ) ;
#endif
}
static int F_321 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_322 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_655 * V_655 = V_3 -> V_656 ;
T_2 V_14 , V_657 , V_242 ;
unsigned long V_658 , V_239 , V_659 ;
T_2 V_660 ;
enum V_661 V_662 ;
V_660 = V_60 -> V_663 ;
V_14 = V_60 -> V_664 ;
if ( F_16 ( V_14 ) )
return F_321 ( V_3 ) ;
if ( ( V_660 & V_636 ) &&
! F_12 ( V_14 ) ) {
V_3 -> V_656 -> V_665 = V_666 ;
V_3 -> V_656 -> V_667 . V_668 = V_669 ;
V_3 -> V_656 -> V_667 . V_670 = 2 ;
V_3 -> V_656 -> V_667 . V_166 [ 0 ] = V_660 ;
V_3 -> V_656 -> V_667 . V_166 [ 1 ] = V_14 ;
return 0 ;
}
if ( ( V_14 & V_15 ) == V_631 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_131 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_662 = F_316 ( V_3 , V_671 ) ;
if ( V_662 != V_248 )
F_317 ( V_3 , V_21 ) ;
return 1 ;
}
V_242 = 0 ;
if ( V_14 & V_245 )
V_242 = F_73 ( V_672 ) ;
if ( F_12 ( V_14 ) ) {
F_323 ( V_86 ) ;
V_658 = F_71 ( V_673 ) ;
F_324 ( V_658 , V_242 ) ;
if ( F_325 ( V_3 ) )
F_326 ( V_3 , V_658 ) ;
return F_327 ( V_3 , V_658 , V_242 , NULL , 0 ) ;
}
if ( V_60 -> V_117 . V_118 &&
F_315 ( V_3 , V_14 & V_16 ,
V_242 ) ) {
if ( V_3 -> V_97 . V_674 ) {
V_3 -> V_97 . V_674 = 0 ;
return F_328 ( V_3 ) ;
}
return 1 ;
}
V_657 = V_14 & V_16 ;
switch ( V_657 ) {
case V_112 :
V_659 = F_71 ( V_673 ) ;
if ( ! ( V_3 -> V_113 &
( V_646 | V_647 ) ) ) {
V_3 -> V_97 . V_659 = V_659 | V_675 ;
F_317 ( V_3 , V_112 ) ;
return 1 ;
}
V_655 -> V_676 . V_97 . V_659 = V_659 | V_675 ;
V_655 -> V_676 . V_97 . V_677 = F_71 ( V_678 ) ;
case V_116 :
V_60 -> V_3 . V_97 . V_247 =
F_73 ( V_240 ) ;
V_655 -> V_665 = V_679 ;
V_239 = F_145 ( V_3 ) ;
V_655 -> V_676 . V_97 . V_680 = F_71 ( V_498 ) + V_239 ;
V_655 -> V_676 . V_97 . V_681 = V_657 ;
break;
default:
V_655 -> V_665 = V_682 ;
V_655 -> V_683 . V_681 = V_657 ;
V_655 -> V_683 . V_242 = V_242 ;
break;
}
return 0 ;
}
static int F_329 ( struct V_2 * V_3 )
{
++ V_3 -> V_198 . V_684 ;
return 1 ;
}
static int F_330 ( struct V_2 * V_3 )
{
V_3 -> V_656 -> V_665 = V_685 ;
return 0 ;
}
static int F_331 ( struct V_2 * V_3 )
{
unsigned long V_686 ;
int V_391 , V_687 , string ;
unsigned V_688 ;
V_686 = F_71 ( V_673 ) ;
string = ( V_686 & 16 ) != 0 ;
V_687 = ( V_686 & 8 ) != 0 ;
++ V_3 -> V_198 . V_689 ;
if ( string || V_687 )
return F_316 ( V_3 , 0 ) == V_248 ;
V_688 = V_686 >> 16 ;
V_391 = ( V_686 & 7 ) + 1 ;
F_144 ( V_3 ) ;
return F_332 ( V_3 , V_391 , V_688 ) ;
}
static void
F_333 ( struct V_2 * V_3 , unsigned char * V_690 )
{
V_690 [ 0 ] = 0x0f ;
V_690 [ 1 ] = 0x01 ;
V_690 [ 2 ] = 0xc1 ;
}
static int F_334 ( struct V_2 * V_3 , unsigned long V_691 )
{
if ( F_1 ( V_3 ) -> V_8 . V_484 &&
( ( V_691 & F_174 ) != F_174 ) )
return 1 ;
if ( F_92 ( V_3 ) ) {
if ( F_335 ( V_3 , ( V_691 & V_3 -> V_97 . V_214 ) |
( V_3 -> V_97 . V_210 & ~ V_3 -> V_97 . V_214 ) ) )
return 1 ;
F_78 ( V_223 , V_691 ) ;
return 0 ;
} else
return F_335 ( V_3 , V_691 ) ;
}
static int F_336 ( struct V_2 * V_3 , unsigned long V_691 )
{
if ( F_92 ( V_3 ) ) {
if ( F_337 ( V_3 , ( V_691 & V_3 -> V_97 . V_456 ) |
( V_3 -> V_97 . V_457 & ~ V_3 -> V_97 . V_456 ) ) )
return 1 ;
F_78 ( V_419 , V_691 ) ;
return 0 ;
} else
return F_337 ( V_3 , V_691 ) ;
}
static void F_338 ( struct V_2 * V_3 )
{
if ( F_92 ( V_3 ) ) {
F_78 ( V_223 ,
F_71 ( V_223 ) & ~ V_212 ) ;
V_3 -> V_97 . V_210 &= ~ V_212 ;
} else
F_243 ( V_3 , F_132 ( V_3 , ~ V_212 ) ) ;
}
static int F_339 ( struct V_2 * V_3 )
{
unsigned long V_686 , V_691 ;
int V_692 ;
int V_355 ;
int V_693 ;
V_686 = F_71 ( V_673 ) ;
V_692 = V_686 & 15 ;
V_355 = ( V_686 >> 8 ) & 15 ;
switch ( ( V_686 >> 4 ) & 3 ) {
case 0 :
V_691 = F_340 ( V_3 , V_355 ) ;
F_341 ( V_692 , V_691 ) ;
switch ( V_692 ) {
case 0 :
V_693 = F_334 ( V_3 , V_691 ) ;
F_342 ( V_3 , V_693 ) ;
return 1 ;
case 3 :
V_693 = F_343 ( V_3 , V_691 ) ;
F_342 ( V_3 , V_693 ) ;
return 1 ;
case 4 :
V_693 = F_336 ( V_3 , V_691 ) ;
F_342 ( V_3 , V_693 ) ;
return 1 ;
case 8 : {
T_6 V_694 = F_344 ( V_3 ) ;
T_6 V_695 = F_340 ( V_3 , V_355 ) ;
V_693 = F_297 ( V_3 , V_695 ) ;
F_342 ( V_3 , V_693 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_694 <= V_695 )
return 1 ;
V_3 -> V_656 -> V_665 = V_696 ;
return 0 ;
}
}
break;
case 2 :
F_338 ( V_3 ) ;
F_341 ( 0 , F_303 ( V_3 ) ) ;
F_144 ( V_3 ) ;
F_131 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_692 ) {
case 3 :
V_691 = F_245 ( V_3 ) ;
F_301 ( V_3 , V_355 , V_691 ) ;
F_345 ( V_692 , V_691 ) ;
F_144 ( V_3 ) ;
return 1 ;
case 8 :
V_691 = F_344 ( V_3 ) ;
F_301 ( V_3 , V_355 , V_691 ) ;
F_345 ( V_692 , V_691 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_691 = ( V_686 >> V_697 ) & 0x0f ;
F_341 ( 0 , ( F_303 ( V_3 ) & ~ 0xful ) | V_691 ) ;
F_346 ( V_3 , V_691 ) ;
F_144 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_656 -> V_665 = 0 ;
F_347 ( V_3 , L_19 ,
( int ) ( V_686 >> 4 ) & 3 , V_692 ) ;
return 0 ;
}
static int F_348 ( struct V_2 * V_3 )
{
unsigned long V_686 ;
int V_698 , V_355 ;
if ( ! F_349 ( V_3 , 0 ) )
return 1 ;
V_698 = F_71 ( V_678 ) ;
if ( V_698 & V_699 ) {
if ( V_3 -> V_113 & V_647 ) {
V_3 -> V_656 -> V_676 . V_97 . V_659 = V_3 -> V_97 . V_659 ;
V_3 -> V_656 -> V_676 . V_97 . V_677 = V_698 ;
V_3 -> V_656 -> V_676 . V_97 . V_680 =
F_71 ( V_498 ) +
F_71 ( V_360 ) ;
V_3 -> V_656 -> V_676 . V_97 . V_681 = V_112 ;
V_3 -> V_656 -> V_665 = V_679 ;
return 0 ;
} else {
V_3 -> V_97 . V_677 &= ~ V_699 ;
V_3 -> V_97 . V_659 |= V_700 ;
F_78 ( V_678 , V_3 -> V_97 . V_677 ) ;
F_317 ( V_3 , V_112 ) ;
return 1 ;
}
}
V_686 = F_71 ( V_673 ) ;
V_698 = V_686 & V_701 ;
V_355 = F_350 ( V_686 ) ;
if ( V_686 & V_702 ) {
unsigned long V_691 ;
if ( ! F_351 ( V_3 , V_698 , & V_691 ) )
F_301 ( V_3 , V_355 , V_691 ) ;
} else
F_352 ( V_3 , V_698 , V_3 -> V_97 . V_357 [ V_355 ] ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static void F_353 ( struct V_2 * V_3 , unsigned long V_691 )
{
F_78 ( V_678 , V_691 ) ;
}
static int F_354 ( struct V_2 * V_3 )
{
F_355 ( V_3 ) ;
return 1 ;
}
static int F_356 ( struct V_2 * V_3 )
{
T_2 V_281 = V_3 -> V_97 . V_357 [ V_703 ] ;
T_5 V_166 ;
if ( F_177 ( V_3 , V_281 , & V_166 ) ) {
F_357 ( V_281 ) ;
F_358 ( V_3 , 0 ) ;
return 1 ;
}
F_359 ( V_281 , V_166 ) ;
V_3 -> V_97 . V_357 [ V_704 ] = V_166 & - 1u ;
V_3 -> V_97 . V_357 [ V_598 ] = ( V_166 >> 32 ) & - 1u ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_360 ( struct V_2 * V_3 )
{
T_2 V_281 = V_3 -> V_97 . V_357 [ V_703 ] ;
T_5 V_166 = ( V_3 -> V_97 . V_357 [ V_704 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_97 . V_357 [ V_598 ] & - 1u ) << 32 ) ;
if ( F_179 ( V_3 , V_281 , V_166 ) != 0 ) {
F_361 ( V_281 , V_166 ) ;
F_358 ( V_3 , 0 ) ;
return 1 ;
}
F_362 ( V_281 , V_166 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_363 ( struct V_2 * V_3 )
{
F_125 ( V_705 , V_3 ) ;
return 1 ;
}
static int F_364 ( struct V_2 * V_3 )
{
T_2 V_57 ;
V_57 = F_73 ( V_466 ) ;
V_57 &= ~ V_298 ;
F_81 ( V_466 , V_57 ) ;
F_125 ( V_705 , V_3 ) ;
++ V_3 -> V_198 . V_706 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_656 -> V_707 &&
! F_365 ( V_3 ) ) {
V_3 -> V_656 -> V_665 = V_708 ;
return 0 ;
}
return 1 ;
}
static int F_366 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
return F_328 ( V_3 ) ;
}
static int F_367 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_368 ( V_3 ) ;
return 1 ;
}
static int F_369 ( struct V_2 * V_3 )
{
return F_316 ( V_3 , 0 ) == V_248 ;
}
static int F_370 ( struct V_2 * V_3 )
{
unsigned long V_686 = F_71 ( V_673 ) ;
F_371 ( V_3 , V_686 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_372 ( struct V_2 * V_3 )
{
int V_693 ;
V_693 = F_373 ( V_3 ) ;
F_342 ( V_3 , V_693 ) ;
return 1 ;
}
static int F_374 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_375 ( V_3 ) ;
return 1 ;
}
static int F_376 ( struct V_2 * V_3 )
{
T_5 V_709 = F_377 ( V_3 ) ;
T_2 V_66 = F_340 ( V_3 , V_703 ) ;
if ( F_378 ( V_3 , V_66 , V_709 ) == 0 )
F_144 ( V_3 ) ;
return 1 ;
}
static int F_379 ( struct V_2 * V_3 )
{
if ( F_269 ( V_710 ) ) {
unsigned long V_686 = F_71 ( V_673 ) ;
int V_711 , V_275 ;
V_711 = V_686 & V_712 ;
V_275 = V_686 & V_713 ;
if ( ( V_711 == V_714 ) &&
( V_275 == V_715 ) ) {
F_380 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
}
return F_316 ( V_3 , 0 ) == V_248 ;
}
static int F_381 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned long V_686 ;
bool V_241 = false ;
T_2 V_242 = 0 ;
T_3 V_716 ;
int V_717 , type , V_718 , V_719 ;
V_718 = ( V_60 -> V_663 & V_636 ) ;
V_719 = ( V_60 -> V_663 & V_720 ) ;
type = ( V_60 -> V_663 & V_721 ) ;
V_686 = F_71 ( V_673 ) ;
V_717 = ( T_2 ) V_686 >> 30 ;
if ( V_717 == V_722 && V_718 ) {
switch ( type ) {
case V_631 :
V_3 -> V_97 . V_723 = false ;
F_312 ( V_3 , true ) ;
break;
case V_22 :
case V_626 :
F_382 ( V_3 ) ;
break;
case V_18 :
if ( V_60 -> V_663 &
V_724 ) {
V_241 = true ;
V_242 =
F_73 ( V_725 ) ;
}
case V_251 :
F_383 ( V_3 ) ;
break;
default:
break;
}
}
V_716 = V_686 ;
if ( ! V_718 || ( type != V_18 &&
type != V_22 &&
type != V_631 ) )
F_144 ( V_3 ) ;
if ( F_384 ( V_3 , V_716 ,
type == V_626 ? V_719 : - 1 , V_717 ,
V_241 , V_242 ) == V_726 ) {
V_3 -> V_656 -> V_665 = V_666 ;
V_3 -> V_656 -> V_667 . V_668 = V_727 ;
V_3 -> V_656 -> V_667 . V_670 = 0 ;
return 0 ;
}
F_78 ( V_678 , F_71 ( V_678 ) & ~ 55 ) ;
return 1 ;
}
static int F_385 ( struct V_2 * V_3 )
{
unsigned long V_686 ;
T_1 V_72 ;
T_2 V_242 ;
int V_728 ;
V_686 = F_71 ( V_673 ) ;
if ( V_686 & ( 1 << 6 ) ) {
F_56 ( V_76 L_20 ) ;
return - V_341 ;
}
V_728 = ( V_686 >> 7 ) & 0x3 ;
if ( V_728 != 0x3 && V_728 != 0x1 && V_728 != 0 ) {
F_56 ( V_76 L_21 ) ;
F_56 ( V_76 L_22 ,
( long unsigned int ) F_74 ( V_729 ) ,
F_71 ( V_730 ) ) ;
F_56 ( V_76 L_23 ,
( long unsigned int ) V_686 ) ;
V_3 -> V_656 -> V_665 = V_731 ;
V_3 -> V_656 -> V_732 . V_733 = V_734 ;
return 0 ;
}
V_72 = F_74 ( V_729 ) ;
F_324 ( V_72 , V_686 ) ;
V_242 = V_686 & ( 1U << 1 ) ;
V_242 |= ( V_686 >> 3 ) & 0x1 ;
return F_327 ( V_3 , V_72 , V_242 , NULL , 0 ) ;
}
static T_5 F_386 ( T_5 V_735 , int V_736 )
{
int V_62 ;
T_5 V_91 = 0 ;
for ( V_62 = 51 ; V_62 > V_395 . V_737 ; V_62 -- )
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
static void F_387 ( struct V_2 * V_3 , T_5 V_735 ,
int V_736 )
{
F_56 ( V_76 L_24 , V_450 , V_735 , V_736 ) ;
F_388 ( ( V_735 & 0x7 ) == 0x2 ) ;
F_388 ( ( V_735 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_388 ( ( V_735 & 0x7 ) == 0x4 ) ;
if ( ( V_735 & 0x7 ) ) {
T_5 V_738 = V_735 & F_386 ( V_735 , V_736 ) ;
if ( V_738 != 0 ) {
F_56 ( V_76 L_25 ,
V_450 , V_738 ) ;
F_388 ( 1 ) ;
}
if ( V_736 == 1 || ( V_736 == 2 && ( V_735 & ( 1ULL << 7 ) ) ) ) {
T_5 V_739 = ( V_735 & 0x38 ) >> 3 ;
if ( V_739 == 2 || V_739 == 3 ||
V_739 == 7 ) {
F_56 ( V_76 L_26 ,
V_450 , V_739 ) ;
F_388 ( 1 ) ;
}
}
}
}
static int F_389 ( struct V_2 * V_3 )
{
T_5 V_740 [ 4 ] ;
int V_741 , V_62 , V_95 ;
T_1 V_72 ;
V_72 = F_74 ( V_729 ) ;
V_95 = F_390 ( V_3 , V_72 , true ) ;
if ( F_269 ( V_95 == 1 ) )
return F_391 ( V_3 , V_72 , 0 , NULL , 0 ) ==
V_248 ;
if ( F_79 ( ! V_95 ) )
return 1 ;
F_56 ( V_76 L_27 ) ;
F_56 ( V_76 L_28 , V_72 ) ;
V_741 = F_392 ( V_3 , V_72 , V_740 ) ;
for ( V_62 = V_742 ; V_62 > V_742 - V_741 ; -- V_62 )
F_387 ( V_3 , V_740 [ V_62 - 1 ] , V_62 ) ;
V_3 -> V_656 -> V_665 = V_731 ;
V_3 -> V_656 -> V_732 . V_733 = V_743 ;
return 0 ;
}
static int F_393 ( struct V_2 * V_3 )
{
T_2 V_57 ;
V_57 = F_73 ( V_466 ) ;
V_57 &= ~ V_620 ;
F_81 ( V_466 , V_57 ) ;
++ V_3 -> V_198 . V_744 ;
F_125 ( V_705 , V_3 ) ;
return 1 ;
}
static int F_394 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
enum V_661 V_693 = V_248 ;
int V_95 = 1 ;
T_2 V_745 ;
bool V_746 ;
unsigned V_747 = 130 ;
V_745 = F_73 ( V_466 ) ;
V_746 = V_745 & V_298 ;
while ( ! F_264 ( V_3 ) && V_747 -- != 0 ) {
if ( V_746 && F_313 ( V_3 ) )
return F_364 ( & V_60 -> V_3 ) ;
if ( F_138 ( V_705 , & V_3 -> V_748 ) )
return 1 ;
V_693 = F_316 ( V_3 , 0 ) ;
if ( V_693 == V_749 ) {
V_95 = 0 ;
goto V_522;
}
if ( V_693 != V_248 ) {
V_3 -> V_656 -> V_665 = V_666 ;
V_3 -> V_656 -> V_667 . V_668 = V_727 ;
V_3 -> V_656 -> V_667 . V_670 = 0 ;
return 0 ;
}
if ( F_395 ( V_750 ) )
goto V_522;
if ( F_396 () )
F_397 () ;
}
V_60 -> V_414 = ! F_264 ( V_3 ) ;
V_522:
return V_95 ;
}
static int F_398 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_399 ( V_3 ) ;
return 1 ;
}
static int F_400 ( struct V_2 * V_3 )
{
F_317 ( V_3 , V_21 ) ;
return 1 ;
}
static struct V_77 * F_401 ( struct V_1 * V_60 )
{
struct V_751 * V_752 ;
F_402 (item, &vmx->nested.vmcs02_pool, list)
if ( V_752 -> V_753 == V_60 -> V_8 . V_754 ) {
F_403 ( & V_752 -> V_755 , & V_60 -> V_8 . V_756 ) ;
return & V_752 -> V_757 ;
}
if ( V_60 -> V_8 . V_758 >= F_404 ( V_759 , 1 ) ) {
V_752 = F_405 ( V_60 -> V_8 . V_756 . V_760 ,
struct V_751 , V_755 ) ;
V_752 -> V_753 = V_60 -> V_8 . V_754 ;
F_403 ( & V_752 -> V_755 , & V_60 -> V_8 . V_756 ) ;
return & V_752 -> V_757 ;
}
V_752 = (struct V_751 * )
F_406 ( sizeof( struct V_751 ) , V_400 ) ;
if ( ! V_752 )
return NULL ;
V_752 -> V_757 . V_74 = F_204 () ;
if ( ! V_752 -> V_757 . V_74 ) {
F_407 ( V_752 ) ;
return NULL ;
}
F_57 ( & V_752 -> V_757 ) ;
V_752 -> V_753 = V_60 -> V_8 . V_754 ;
F_127 ( & ( V_752 -> V_755 ) , & ( V_60 -> V_8 . V_756 ) ) ;
V_60 -> V_8 . V_758 ++ ;
return & V_752 -> V_757 ;
}
static void F_408 ( struct V_1 * V_60 , T_1 V_753 )
{
struct V_751 * V_752 ;
F_402 (item, &vmx->nested.vmcs02_pool, list)
if ( V_752 -> V_753 == V_753 ) {
F_207 ( & V_752 -> V_757 ) ;
F_62 ( & V_752 -> V_755 ) ;
F_407 ( V_752 ) ;
V_60 -> V_8 . V_758 -- ;
return;
}
}
static void F_409 ( struct V_1 * V_60 )
{
struct V_751 * V_752 , * V_370 ;
F_194 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_60 -> V_77 != & V_752 -> V_757 )
F_207 ( & V_752 -> V_757 ) ;
F_62 ( & V_752 -> V_755 ) ;
F_407 ( V_752 ) ;
}
V_60 -> V_8 . V_758 = 0 ;
if ( V_60 -> V_77 != & V_60 -> V_761 )
F_207 ( & V_60 -> V_761 ) ;
}
static int F_410 ( struct V_2 * V_3 )
{
struct V_409 V_509 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( ! F_411 ( V_3 , V_368 ) ||
! F_132 ( V_3 , V_472 ) ||
( F_137 ( V_3 ) & V_231 ) ) {
F_317 ( V_3 , V_21 ) ;
return 1 ;
}
F_223 ( V_3 , & V_509 , V_446 ) ;
if ( F_110 ( V_3 ) && ! V_509 . V_491 ) {
F_317 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_250 ( V_3 ) ) {
F_358 ( V_3 , 0 ) ;
return 1 ;
}
F_190 ( & ( V_60 -> V_8 . V_756 ) ) ;
V_60 -> V_8 . V_758 = 0 ;
V_60 -> V_8 . V_484 = true ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_412 ( struct V_2 * V_3 )
{
struct V_409 V_509 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( ! V_60 -> V_8 . V_484 ) {
F_317 ( V_3 , V_21 ) ;
return 0 ;
}
F_223 ( V_3 , & V_509 , V_446 ) ;
if ( ( F_137 ( V_3 ) & V_231 ) ||
( F_110 ( V_3 ) && ! V_509 . V_491 ) ) {
F_317 ( V_3 , V_21 ) ;
return 0 ;
}
if ( F_250 ( V_3 ) ) {
F_358 ( V_3 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_413 ( struct V_1 * V_60 )
{
if ( ! V_60 -> V_8 . V_484 )
return;
V_60 -> V_8 . V_484 = false ;
if ( V_60 -> V_8 . V_754 != - 1ull ) {
F_414 ( V_60 -> V_8 . V_762 ) ;
F_8 ( V_60 -> V_8 . V_762 ) ;
V_60 -> V_8 . V_754 = - 1ull ;
V_60 -> V_8 . V_9 = NULL ;
}
if ( V_60 -> V_8 . V_539 ) {
F_8 ( V_60 -> V_8 . V_539 ) ;
V_60 -> V_8 . V_539 = 0 ;
}
F_409 ( V_60 ) ;
}
static int F_415 ( struct V_2 * V_3 )
{
if ( ! F_412 ( V_3 ) )
return 1 ;
F_413 ( F_1 ( V_3 ) ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_416 ( struct V_2 * V_3 ,
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
F_317 ( V_3 , V_21 ) ;
return 1 ;
}
* V_95 = F_246 ( V_3 , V_767 ) ;
if ( V_771 )
* V_95 += F_340 ( V_3 , V_770 ) ;
if ( V_769 )
* V_95 += F_340 ( V_3 , V_768 ) << V_764 ;
* V_95 += V_686 ;
if ( V_765 == 1 )
* V_95 &= 0xffffffff ;
return 0 ;
}
static void F_417 ( struct V_2 * V_3 )
{
F_140 ( V_3 , F_137 ( V_3 )
& ~ ( V_772 | V_773 | V_774 |
V_775 | V_776 | V_777 ) ) ;
}
static void F_418 ( struct V_2 * V_3 )
{
F_140 ( V_3 , ( F_137 ( V_3 )
& ~ ( V_773 | V_774 | V_775 |
V_776 | V_777 ) )
| V_772 ) ;
}
static void F_419 ( struct V_2 * V_3 ,
T_2 V_778 )
{
if ( F_1 ( V_3 ) -> V_8 . V_754 == - 1ull ) {
F_418 ( V_3 ) ;
return;
}
F_140 ( V_3 , ( F_137 ( V_3 )
& ~ ( V_772 | V_773 | V_774 |
V_776 | V_777 ) )
| V_775 ) ;
F_4 ( V_3 ) -> V_778 = V_778 ;
}
static int F_420 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_4 V_68 ;
T_1 V_753 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_779 V_780 ;
if ( ! F_412 ( V_3 ) )
return 1 ;
if ( F_416 ( V_3 , F_71 ( V_673 ) ,
F_73 ( V_781 ) , & V_68 ) )
return 1 ;
if ( F_421 ( & V_3 -> V_97 . V_782 , V_68 , & V_753 ,
sizeof( V_753 ) , & V_780 ) ) {
F_422 ( V_3 , & V_780 ) ;
return 1 ;
}
if ( ! F_423 ( V_753 , V_390 ) ) {
F_419 ( V_3 , V_783 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_753 == V_60 -> V_8 . V_754 ) {
F_414 ( V_60 -> V_8 . V_762 ) ;
F_8 ( V_60 -> V_8 . V_762 ) ;
V_60 -> V_8 . V_754 = - 1ull ;
V_60 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_753 ) ;
if ( V_10 == NULL ) {
F_125 ( V_249 , V_3 ) ;
return 1 ;
}
V_7 = F_424 ( V_10 ) ;
V_7 -> V_784 = 0 ;
F_414 ( V_10 ) ;
F_8 ( V_10 ) ;
F_408 ( V_60 , V_753 ) ;
F_144 ( V_3 ) ;
F_417 ( V_3 ) ;
return 1 ;
}
static int F_425 ( struct V_2 * V_3 )
{
return F_426 ( V_3 , true ) ;
}
static int F_427 ( struct V_2 * V_3 )
{
return F_426 ( V_3 , false ) ;
}
static inline int F_428 ( unsigned long V_4 )
{
if ( 0x1 & V_4 )
return V_785 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_429 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_430 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_95 )
{
short V_275 = F_3 ( V_4 ) ;
char * V_100 ;
if ( V_275 < 0 )
return 0 ;
V_100 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_275 ;
switch ( F_428 ( V_4 ) ) {
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
static int F_431 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
if ( V_60 -> V_8 . V_754 == - 1ull ) {
F_418 ( V_3 ) ;
F_144 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_432 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_790 ;
unsigned long V_686 = F_71 ( V_673 ) ;
T_2 V_763 = F_73 ( V_781 ) ;
T_4 V_68 = 0 ;
if ( ! F_412 ( V_3 ) ||
! F_431 ( V_3 ) )
return 1 ;
V_4 = F_340 ( V_3 , ( ( ( V_763 ) >> 28 ) & 0xf ) ) ;
if ( ! F_430 ( V_3 , V_4 , & V_790 ) ) {
F_419 ( V_3 , V_791 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_763 & ( 1u << 10 ) ) {
F_301 ( V_3 , ( ( ( V_763 ) >> 3 ) & 0xf ) ,
V_790 ) ;
} else {
if ( F_416 ( V_3 , V_686 ,
V_763 , & V_68 ) )
return 1 ;
F_433 ( & V_3 -> V_97 . V_782 , V_68 ,
& V_790 , ( F_110 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_417 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_434 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_68 ;
unsigned long V_686 = F_71 ( V_673 ) ;
T_2 V_763 = F_73 ( V_781 ) ;
char * V_100 ;
short V_275 ;
T_5 V_790 = 0 ;
struct V_779 V_780 ;
if ( ! F_412 ( V_3 ) ||
! F_431 ( V_3 ) )
return 1 ;
if ( V_763 & ( 1u << 10 ) )
V_790 = F_340 ( V_3 ,
( ( ( V_763 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_416 ( V_3 , V_686 ,
V_763 , & V_68 ) )
return 1 ;
if ( F_421 ( & V_3 -> V_97 . V_782 , V_68 ,
& V_790 , ( F_110 ( V_3 ) ? 8 : 4 ) , & V_780 ) ) {
F_422 ( V_3 , & V_780 ) ;
return 1 ;
}
}
V_4 = F_340 ( V_3 , ( ( ( V_763 ) >> 28 ) & 0xf ) ) ;
if ( F_429 ( V_4 ) ) {
F_419 ( V_3 ,
V_792 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
V_275 = F_3 ( V_4 ) ;
if ( V_275 < 0 ) {
F_419 ( V_3 , V_791 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
V_100 = ( ( char * ) F_4 ( V_3 ) ) + V_275 ;
switch ( F_428 ( V_4 ) ) {
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
F_419 ( V_3 , V_791 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
F_417 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_435 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_4 V_68 ;
T_1 V_753 ;
struct V_779 V_780 ;
if ( ! F_412 ( V_3 ) )
return 1 ;
if ( F_416 ( V_3 , F_71 ( V_673 ) ,
F_73 ( V_781 ) , & V_68 ) )
return 1 ;
if ( F_421 ( & V_3 -> V_97 . V_782 , V_68 , & V_753 ,
sizeof( V_753 ) , & V_780 ) ) {
F_422 ( V_3 , & V_780 ) ;
return 1 ;
}
if ( ! F_423 ( V_753 , V_390 ) ) {
F_419 ( V_3 , V_793 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_60 -> V_8 . V_754 != V_753 ) {
struct V_7 * V_794 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_753 ) ;
if ( V_10 == NULL ) {
F_418 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
V_794 = F_424 ( V_10 ) ;
if ( V_794 -> V_393 != V_324 ) {
F_414 ( V_10 ) ;
F_10 ( V_10 ) ;
F_419 ( V_3 ,
V_795 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_60 -> V_8 . V_754 != - 1ull ) {
F_414 ( V_60 -> V_8 . V_762 ) ;
F_8 ( V_60 -> V_8 . V_762 ) ;
}
V_60 -> V_8 . V_754 = V_753 ;
V_60 -> V_8 . V_9 = V_794 ;
V_60 -> V_8 . V_762 = V_10 ;
}
F_417 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static int F_436 ( struct V_2 * V_3 )
{
unsigned long V_686 = F_71 ( V_673 ) ;
T_2 V_763 = F_73 ( V_781 ) ;
T_4 V_796 ;
struct V_779 V_780 ;
if ( ! F_412 ( V_3 ) )
return 1 ;
if ( F_416 ( V_3 , V_686 ,
V_763 , & V_796 ) )
return 1 ;
if ( F_433 ( & V_3 -> V_97 . V_782 , V_796 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_754 ,
sizeof( T_5 ) , & V_780 ) ) {
F_422 ( V_3 , & V_780 ) ;
return 1 ;
}
F_417 ( V_3 ) ;
F_144 ( V_3 ) ;
return 1 ;
}
static bool F_437 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_665 )
{
T_2 V_318 = V_3 -> V_97 . V_357 [ V_703 ] ;
T_1 V_797 ;
if ( ! F_46 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_797 = V_7 -> V_256 ;
if ( V_665 == V_798 )
V_797 += 2048 ;
if ( V_318 >= 0xc0000000 ) {
V_318 -= 0xc0000000 ;
V_797 += 1024 ;
}
if ( V_318 < 1024 * 8 ) {
unsigned char V_799 ;
F_438 ( V_3 -> V_12 , V_797 + V_318 / 8 , & V_799 , 1 ) ;
return 1 & ( V_799 >> ( V_318 & 7 ) ) ;
} else
return 1 ;
}
static bool F_439 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_686 = F_71 ( V_673 ) ;
int V_692 = V_686 & 15 ;
int V_355 = ( V_686 >> 8 ) & 15 ;
unsigned long V_691 = F_340 ( V_3 , V_355 ) ;
switch ( ( V_686 >> 4 ) & 3 ) {
case 0 :
switch ( V_692 ) {
case 0 :
if ( V_7 -> V_215 &
( V_691 ^ V_7 -> V_219 ) )
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
if ( F_46 ( V_7 , V_302 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_221 &
( V_7 -> V_222 ^ V_691 ) )
return 1 ;
break;
case 8 :
if ( F_46 ( V_7 , V_304 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_215 & V_212 ) &&
( V_7 -> V_219 & V_212 ) )
return 1 ;
break;
case 1 :
switch ( V_692 ) {
case 3 :
if ( V_7 -> V_57 &
V_303 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_57 &
V_305 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_215 & 0xe &
( V_691 ^ V_7 -> V_219 ) )
return 1 ;
if ( ( V_7 -> V_215 & 0x1 ) &&
! ( V_7 -> V_219 & 0x1 ) &&
( V_691 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_440 ( struct V_2 * V_3 )
{
T_2 V_665 = F_73 ( V_805 ) ;
T_2 V_14 = F_73 ( V_806 ) ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_60 -> V_8 . V_634 )
return 0 ;
if ( F_79 ( V_60 -> V_807 ) ) {
F_441 ( L_29 , V_450 ,
F_73 ( V_90 ) ) ;
return 1 ;
}
switch ( V_665 ) {
case V_808 :
if ( ! F_49 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_86 ;
return V_7 -> V_120 &
( 1u << ( V_14 & V_16 ) ) ;
case V_638 :
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
return F_46 ( V_7 , V_299 ) ;
case V_815 :
return 1 ;
case V_816 :
return F_46 ( V_7 , V_300 ) ;
case V_817 :
return F_46 ( V_7 , V_310 ) ;
case V_818 :
return F_46 ( V_7 , V_311 ) ;
case V_819 : case V_820 :
case V_821 : case V_822 :
case V_823 : case V_824 :
case V_825 : case V_826 :
case V_827 : case V_828 :
return 1 ;
case V_829 :
return F_439 ( V_3 , V_7 ) ;
case V_830 :
return F_46 ( V_7 , V_306 ) ;
case V_831 :
return 1 ;
case V_832 :
case V_798 :
return F_437 ( V_3 , V_7 , V_665 ) ;
case V_833 :
return 1 ;
case V_834 :
return F_46 ( V_7 , V_301 ) ;
case V_835 :
return F_46 ( V_7 , V_309 ) ;
case V_836 :
return F_46 ( V_7 , V_837 ) ||
F_47 ( V_7 ,
V_48 ) ;
case V_838 :
return 0 ;
case V_839 :
return 1 ;
case V_840 :
return F_47 ( V_7 ,
V_30 ) ;
case V_734 :
case V_743 :
return 0 ;
case V_841 :
return F_47 ( V_7 , V_55 ) ;
case V_842 :
return 1 ;
default:
return 1 ;
}
}
static void F_442 ( struct V_2 * V_3 , T_5 * V_843 , T_5 * V_844 )
{
* V_843 = F_71 ( V_673 ) ;
* V_844 = F_73 ( V_806 ) ;
}
static int F_443 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_665 = V_60 -> V_665 ;
T_2 V_845 = V_60 -> V_663 ;
if ( V_60 -> V_414 && V_420 )
return F_394 ( V_3 ) ;
if ( V_60 -> V_8 . V_634 )
F_125 ( V_705 , V_3 ) ;
if ( ! F_92 ( V_3 ) && ( V_665 == V_821 ||
V_665 == V_825 ) )
V_60 -> V_8 . V_634 = 1 ;
else
V_60 -> V_8 . V_634 = 0 ;
if ( F_92 ( V_3 ) && F_440 ( V_3 ) ) {
F_148 ( V_3 ) ;
return 1 ;
}
if ( V_665 & V_846 ) {
V_3 -> V_656 -> V_665 = V_847 ;
V_3 -> V_656 -> V_848 . V_849
= V_665 ;
return 0 ;
}
if ( F_79 ( V_60 -> V_807 ) ) {
V_3 -> V_656 -> V_665 = V_847 ;
V_3 -> V_656 -> V_848 . V_849
= F_73 ( V_90 ) ;
return 0 ;
}
if ( ( V_845 & V_636 ) &&
( V_665 != V_808 &&
V_665 != V_734 &&
V_665 != V_812 ) )
F_56 ( V_149 L_30
L_31 ,
V_450 , V_845 , V_665 ) ;
if ( F_79 ( ! F_43 () && V_60 -> V_597 &&
! ( F_92 ( V_3 ) && F_48 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_313 ( V_3 ) ) {
V_60 -> V_597 = 0 ;
} else if ( V_60 -> V_627 > 1000000000LL &&
V_3 -> V_97 . V_850 ) {
F_56 ( V_149 L_32
L_33 ,
V_450 , V_3 -> V_851 ) ;
V_60 -> V_597 = 0 ;
}
}
if ( V_665 < V_852
&& V_853 [ V_665 ] )
return V_853 [ V_665 ] ( V_3 ) ;
else {
V_3 -> V_656 -> V_665 = V_731 ;
V_3 -> V_656 -> V_732 . V_733 = V_665 ;
}
return 0 ;
}
static void V_407 ( struct V_2 * V_3 , int V_854 , int V_855 )
{
if ( V_855 == - 1 || V_854 < V_855 ) {
F_81 ( V_613 , 0 ) ;
return;
}
F_81 ( V_613 , V_855 ) ;
}
static void F_444 ( struct V_1 * V_60 )
{
T_2 V_664 ;
if ( ! ( V_60 -> V_665 == V_838
|| V_60 -> V_665 == V_808 ) )
return;
V_60 -> V_664 = F_73 ( V_806 ) ;
V_664 = V_60 -> V_664 ;
if ( F_16 ( V_664 ) )
F_318 () ;
if ( ( V_664 & V_15 ) == V_631 &&
( V_664 & V_17 ) ) {
F_445 ( & V_60 -> V_3 ) ;
asm("int $2");
F_446 ( & V_60 -> V_3 ) ;
}
}
static void F_447 ( struct V_1 * V_60 )
{
T_2 V_664 ;
bool V_856 ;
T_6 V_857 ;
bool V_858 ;
V_858 = V_60 -> V_663 & V_636 ;
if ( F_43 () ) {
if ( V_60 -> V_629 )
return;
V_664 = F_73 ( V_806 ) ;
V_856 = ( V_664 & V_859 ) != 0 ;
V_857 = V_664 & V_16 ;
if ( ( V_664 & V_17 ) && V_856 &&
V_857 != V_651 && ! V_858 )
F_84 ( V_233 ,
V_632 ) ;
else
V_60 -> V_629 =
! ( F_73 ( V_233 )
& V_632 ) ;
} else if ( F_79 ( V_60 -> V_597 ) )
V_60 -> V_627 +=
F_448 ( F_449 ( F_450 () , V_60 -> V_860 ) ) ;
}
static void F_451 ( struct V_1 * V_60 ,
T_2 V_663 ,
int V_861 ,
int V_862 )
{
T_6 V_857 ;
int type ;
bool V_858 ;
V_858 = V_663 & V_636 ;
V_60 -> V_3 . V_97 . V_723 = false ;
F_383 ( & V_60 -> V_3 ) ;
F_382 ( & V_60 -> V_3 ) ;
if ( ! V_858 )
return;
F_125 ( V_705 , & V_60 -> V_3 ) ;
V_857 = V_663 & V_720 ;
type = V_663 & V_721 ;
switch ( type ) {
case V_631 :
V_60 -> V_3 . V_97 . V_723 = true ;
F_312 ( & V_60 -> V_3 , false ) ;
break;
case V_251 :
V_60 -> V_3 . V_97 . V_247 =
F_73 ( V_861 ) ;
case V_18 :
if ( V_663 & V_724 ) {
T_2 V_693 = F_73 ( V_862 ) ;
F_173 ( & V_60 -> V_3 , V_857 , V_693 ) ;
} else
F_317 ( & V_60 -> V_3 , V_857 ) ;
break;
case V_626 :
V_60 -> V_3 . V_97 . V_247 =
F_73 ( V_861 ) ;
case V_22 :
F_452 ( & V_60 -> V_3 , V_857 ,
type == V_626 ) ;
break;
default:
break;
}
}
static void F_453 ( struct V_1 * V_60 )
{
if ( F_92 ( & V_60 -> V_3 ) )
return;
F_451 ( V_60 , V_60 -> V_663 ,
V_240 ,
V_725 ) ;
}
static void F_454 ( struct V_2 * V_3 )
{
if ( F_92 ( V_3 ) )
return;
F_451 ( F_1 ( V_3 ) ,
F_73 ( V_252 ) ,
V_250 ,
V_244 ) ;
F_81 ( V_252 , 0 ) ;
}
static void F_455 ( struct V_1 * V_60 )
{
int V_62 , V_863 ;
struct V_864 * V_865 ;
V_865 = F_456 ( & V_863 ) ;
if ( ! V_865 )
return;
for ( V_62 = 0 ; V_62 < V_863 ; V_62 ++ )
if ( V_865 [ V_62 ] . V_137 == V_865 [ V_62 ] . V_136 )
F_94 ( V_60 , V_865 [ V_62 ] . V_61 ) ;
else
F_96 ( V_60 , V_865 [ V_62 ] . V_61 , V_865 [ V_62 ] . V_136 ,
V_865 [ V_62 ] . V_137 ) ;
}
static void T_16 F_457 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned long V_866 ;
if ( F_92 ( V_3 ) && ! V_60 -> V_8 . V_634 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_635 &
V_636 ) {
F_81 ( V_252 ,
V_7 -> V_635 ) ;
F_81 ( V_250 ,
V_7 -> V_867 ) ;
if ( V_7 -> V_635 &
V_724 )
F_81 ( V_244 ,
V_7 -> V_868 ) ;
}
}
if ( F_79 ( ! F_43 () && V_60 -> V_597 ) )
V_60 -> V_860 = F_450 () ;
if ( V_60 -> V_414 && V_420 )
return;
if ( F_138 ( V_356 , ( unsigned long * ) & V_3 -> V_97 . V_458 ) )
F_78 ( V_358 , V_3 -> V_97 . V_357 [ V_356 ] ) ;
if ( F_138 ( V_359 , ( unsigned long * ) & V_3 -> V_97 . V_458 ) )
F_78 ( V_360 , V_3 -> V_97 . V_357 [ V_359 ] ) ;
if ( V_3 -> V_113 & V_646 )
F_143 ( V_3 , 0 ) ;
F_455 ( V_60 ) ;
V_866 = F_458 () ;
V_60 -> V_869 = V_60 -> V_77 -> V_79 ;
asm(
"push %%" _ASM_DX "; push %%" _ASM_BP ";"
"push %%" _ASM_CX " \n\t"
"push %%" _ASM_CX " \n\t"
"cmp %%" _ASM_SP ", %c[host_rsp](%0) \n\t"
"je 1f \n\t"
"mov %%" _ASM_SP ", %c[host_rsp](%0) \n\t"
__ex(ASM_VMX_VMWRITE_RSP_RDX) "\n\t"
"1: \n\t"
"mov %c[cr2](%0), %%" _ASM_AX " \n\t"
"mov %%cr2, %%" _ASM_DX " \n\t"
"cmp %%" _ASM_AX ", %%" _ASM_DX " \n\t"
"je 2f \n\t"
"mov %%" _ASM_AX", %%cr2 \n\t"
"2: \n\t"
"cmpl $0, %c[launched](%0) \n\t"
"mov %c[rax](%0), %%" _ASM_AX " \n\t"
"mov %c[rbx](%0), %%" _ASM_BX " \n\t"
"mov %c[rdx](%0), %%" _ASM_DX " \n\t"
"mov %c[rsi](%0), %%" _ASM_SI " \n\t"
"mov %c[rdi](%0), %%" _ASM_DI " \n\t"
"mov %c[rbp](%0), %%" _ASM_BP " \n\t"
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
"mov %c[rcx](%0), %%" _ASM_CX " \n\t"
"jne 1f \n\t"
__ex(ASM_VMX_VMLAUNCH) "\n\t"
"jmp 2f \n\t"
"1: " __ex(ASM_VMX_VMRESUME) "\n\t"
"2: "
"mov %0, %c[wordsize](%%" _ASM_SP ") \n\t"
"pop %0 \n\t"
"mov %%" _ASM_AX ", %c[rax](%0) \n\t"
"mov %%" _ASM_BX ", %c[rbx](%0) \n\t"
__ASM_SIZE(pop) " %c[rcx](%0) \n\t"
"mov %%" _ASM_DX ", %c[rdx](%0) \n\t"
"mov %%" _ASM_SI ", %c[rsi](%0) \n\t"
"mov %%" _ASM_DI ", %c[rdi](%0) \n\t"
"mov %%" _ASM_BP ", %c[rbp](%0) \n\t"
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
"mov %%cr2, %%" _ASM_AX " \n\t"
"mov %%" _ASM_AX ", %c[cr2](%0) \n\t"
"pop %%" _ASM_BP "; pop %%" _ASM_DX " \n\t"
"setbe %c[fail](%0) \n\t"
".pushsection .rodata \n\t"
".global vmx_return \n\t"
"vmx_return: " _ASM_PTR " 2b \n\t"
".popsection"
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
#ifdef F_75
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_866 )
F_459 ( V_866 ) ;
#ifndef F_75
F_116 ( V_186 , V_870 ) ;
F_116 ( V_188 , V_870 ) ;
#endif
V_3 -> V_97 . V_98 = ~ ( ( 1 << V_359 ) | ( 1 << V_356 )
| ( 1 << V_226 )
| ( 1 << V_229 )
| ( 1 << V_361 )
| ( 1 << V_99 )
| ( 1 << V_455 ) ) ;
V_3 -> V_97 . V_458 = 0 ;
V_60 -> V_663 = F_73 ( V_871 ) ;
if ( F_92 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_635 = V_60 -> V_663 ;
if ( V_60 -> V_663 & V_636 ) {
V_7 -> V_868 =
F_73 ( V_725 ) ;
V_7 -> V_867 =
F_73 ( V_240 ) ;
}
}
V_60 -> V_77 -> V_79 = 1 ;
V_60 -> V_665 = F_73 ( V_805 ) ;
F_460 ( V_60 -> V_665 , V_3 , V_872 ) ;
F_444 ( V_60 ) ;
F_447 ( V_60 ) ;
F_453 ( V_60 ) ;
}
static void F_461 ( struct V_2 * V_3 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
F_280 ( V_60 ) ;
F_413 ( V_60 ) ;
F_207 ( V_60 -> V_77 ) ;
F_407 ( V_60 -> V_65 ) ;
F_462 ( V_3 ) ;
F_463 ( V_873 , V_60 ) ;
}
static struct V_2 * F_464 ( struct V_12 * V_12 , unsigned int V_874 )
{
int V_693 ;
struct V_1 * V_60 = F_465 ( V_873 , V_400 ) ;
int V_78 ;
if ( ! V_60 )
return F_466 ( - V_401 ) ;
F_276 ( V_60 ) ;
V_693 = F_467 ( & V_60 -> V_3 , V_12 , V_874 ) ;
if ( V_693 )
goto V_875;
V_60 -> V_65 = F_406 ( V_390 , V_400 ) ;
V_693 = - V_401 ;
if ( ! V_60 -> V_65 ) {
goto V_876;
}
V_60 -> V_77 = & V_60 -> V_761 ;
V_60 -> V_77 -> V_74 = F_204 () ;
if ( ! V_60 -> V_77 -> V_74 )
goto V_877;
if ( ! V_202 )
F_124 ( F_55 ( F_61 ( V_201 , F_60 () ) ) ) ;
F_57 ( V_60 -> V_77 ) ;
if ( ! V_202 )
F_130 () ;
V_78 = F_468 () ;
F_123 ( & V_60 -> V_3 , V_78 ) ;
V_60 -> V_3 . V_78 = V_78 ;
V_693 = F_292 ( V_60 ) ;
F_129 ( & V_60 -> V_3 ) ;
F_469 () ;
if ( V_693 )
goto F_205;
if ( F_39 ( V_12 ) )
V_693 = F_271 ( V_12 ) ;
if ( V_693 )
goto F_205;
if ( V_86 ) {
if ( ! V_12 -> V_97 . V_480 )
V_12 -> V_97 . V_480 =
V_878 ;
V_693 = - V_401 ;
if ( F_275 ( V_12 ) != 0 )
goto F_205;
if ( ! F_268 ( V_12 ) )
goto F_205;
}
V_60 -> V_8 . V_754 = - 1ull ;
V_60 -> V_8 . V_9 = NULL ;
return & V_60 -> V_3 ;
F_205:
F_207 ( V_60 -> V_77 ) ;
V_877:
F_407 ( V_60 -> V_65 ) ;
V_876:
F_462 ( & V_60 -> V_3 ) ;
V_875:
F_280 ( V_60 ) ;
F_463 ( V_873 , V_60 ) ;
return F_466 ( V_693 ) ;
}
static void T_11 F_470 ( void * V_879 )
{
struct V_24 V_378 ;
* ( int * ) V_879 = 0 ;
if ( F_198 ( & V_378 ) < 0 )
* ( int * ) V_879 = - V_377 ;
if ( memcmp ( & V_24 , & V_378 , sizeof( struct V_24 ) ) != 0 ) {
F_56 ( V_76 L_34 ,
F_471 () ) ;
* ( int * ) V_879 = - V_377 ;
}
}
static int F_472 ( void )
{
return V_474 + 1 ;
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
struct V_279 * V_280 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_572 ;
V_60 -> V_261 = false ;
if ( F_152 () ) {
V_572 = F_73 ( V_580 ) ;
if ( V_572 & V_51 ) {
V_280 = F_166 ( V_3 , 0x80000001 , 0 ) ;
if ( V_280 && ( V_280 -> V_891 & V_56 ( V_892 ) ) )
V_60 -> V_261 = true ;
else {
V_572 &= ~ V_51 ;
F_81 ( V_580 ,
V_572 ) ;
}
}
}
V_280 = F_166 ( V_3 , 0x7 , 0 ) ;
if ( F_153 () &&
V_280 && ( V_280 -> V_893 & V_56 ( V_894 ) ) &&
F_477 ( V_3 ) ) {
V_572 = F_73 ( V_580 ) ;
V_572 |= V_52 ;
F_81 ( V_580 ,
V_572 ) ;
} else {
if ( F_21 () ) {
V_572 = F_73 ( V_580 ) ;
V_572 &= ~ V_52 ;
F_81 ( V_580 ,
V_572 ) ;
}
if ( V_280 )
V_280 -> V_893 &= ~ V_56 ( V_894 ) ;
}
}
static void F_478 ( T_2 V_895 , struct V_279 * V_122 )
{
if ( V_895 == 1 && V_8 )
V_122 -> V_281 |= V_56 ( V_282 ) ;
}
static void F_479 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
T_2 V_572 ;
F_80 ( V_896 , V_7 -> V_897 ) ;
F_80 ( V_427 , V_7 -> V_898 ) ;
F_80 ( V_425 , V_7 -> V_899 ) ;
F_80 ( V_900 , V_7 -> V_901 ) ;
F_80 ( V_902 , V_7 -> V_903 ) ;
F_80 ( V_904 , V_7 -> V_905 ) ;
F_80 ( V_603 , V_7 -> V_906 ) ;
F_80 ( V_602 , V_7 -> V_907 ) ;
F_81 ( V_908 , V_7 -> V_909 ) ;
F_81 ( V_497 , V_7 -> V_910 ) ;
F_81 ( V_500 , V_7 -> V_911 ) ;
F_81 ( V_912 , V_7 -> V_913 ) ;
F_81 ( V_914 , V_7 -> V_915 ) ;
F_81 ( V_916 , V_7 -> V_917 ) ;
F_81 ( V_605 , V_7 -> V_918 ) ;
F_81 ( V_441 , V_7 -> V_919 ) ;
F_81 ( V_504 , V_7 -> V_920 ) ;
F_81 ( V_502 , V_7 -> V_921 ) ;
F_81 ( V_922 , V_7 -> V_923 ) ;
F_81 ( V_429 , V_7 -> V_924 ) ;
F_81 ( V_426 , V_7 -> V_925 ) ;
F_81 ( V_926 , V_7 -> V_927 ) ;
F_81 ( V_928 , V_7 -> V_929 ) ;
F_81 ( V_930 , V_7 -> V_931 ) ;
F_81 ( V_606 , V_7 -> V_932 ) ;
F_81 ( V_443 , V_7 -> V_933 ) ;
F_78 ( V_934 , V_7 -> V_935 ) ;
F_78 ( V_498 , V_7 -> V_936 ) ;
F_78 ( V_499 , V_7 -> V_937 ) ;
F_78 ( V_938 , V_7 -> V_939 ) ;
F_78 ( V_342 , V_7 -> V_940 ) ;
F_78 ( V_343 , V_7 -> V_941 ) ;
F_78 ( V_604 , V_7 -> V_942 ) ;
F_78 ( V_440 , V_7 -> V_943 ) ;
F_78 ( V_505 , V_7 -> V_944 ) ;
F_78 ( V_503 , V_7 -> V_945 ) ;
F_82 ( V_610 , V_7 -> V_946 ) ;
F_81 ( V_252 ,
V_7 -> V_947 ) ;
F_81 ( V_244 ,
V_7 -> V_948 ) ;
F_81 ( V_250 ,
V_7 -> V_949 ) ;
F_81 ( V_233 ,
V_7 -> V_950 ) ;
F_81 ( V_607 , V_7 -> V_951 ) ;
F_81 ( V_346 , V_7 -> V_952 ) ;
F_78 ( V_678 , V_7 -> V_953 ) ;
F_78 ( V_227 , V_7 -> V_954 ) ;
F_78 ( V_609 ,
V_7 -> V_955 ) ;
F_78 ( V_349 , V_7 -> V_956 ) ;
F_78 ( V_348 , V_7 -> V_957 ) ;
F_82 ( V_578 , - 1ull ) ;
F_81 ( V_579 ,
( V_24 . V_53 |
V_7 -> V_59 ) ) ;
F_81 ( V_584 ,
V_86 ? V_7 -> V_958 : 0 ) ;
F_81 ( V_585 ,
V_86 ? V_7 -> V_959 : 0 ) ;
if ( F_21 () ) {
T_2 V_572 = F_289 ( V_60 ) ;
if ( ! V_60 -> V_261 )
V_572 &= ~ V_51 ;
V_572 &= ~ V_30 ;
if ( F_46 ( V_7 ,
V_28 ) )
V_572 |= V_7 -> V_58 ;
if ( V_572 & V_30 ) {
if ( V_60 -> V_8 . V_539 )
F_8 ( V_60 -> V_8 . V_539 ) ;
V_60 -> V_8 . V_539 =
F_5 ( V_3 , V_7 -> V_960 ) ;
if ( ! V_60 -> V_8 . V_539 )
V_572 &=
~ V_30 ;
else
F_82 ( V_614 ,
F_302 ( V_60 -> V_8 . V_539 ) ) ;
}
F_81 ( V_580 , V_572 ) ;
}
F_283 () ;
V_60 -> V_961 = 0 ;
V_572 = F_288 ( V_60 ) ;
V_572 &= ~ V_298 ;
V_572 &= ~ V_620 ;
V_572 &= ~ V_27 ;
V_572 |= V_7 -> V_57 ;
V_572 &= ~ V_26 ;
V_572 &= ~ V_308 ;
V_572 |= V_307 ;
F_81 ( V_466 , V_572 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_214 &= ~ V_7 -> V_215 ;
F_78 ( V_216 , ~ V_3 -> V_97 . V_214 ) ;
F_81 ( V_124 ,
V_7 -> V_962 | V_24 . V_394 ) ;
F_81 ( V_123 , V_7 -> V_963 |
( V_24 . V_351 & ~ V_294 ) ) ;
if ( V_7 -> V_963 & V_293 )
F_82 ( V_352 , V_7 -> V_964 ) ;
else if ( V_24 . V_351 & V_293 )
F_82 ( V_352 , V_60 -> V_3 . V_97 . V_353 ) ;
F_287 ( V_60 ) ;
if ( V_7 -> V_57 & V_276 )
F_82 ( V_268 ,
V_60 -> V_8 . V_269 + V_7 -> V_267 ) ;
else
F_82 ( V_268 , V_60 -> V_8 . V_269 ) ;
if ( V_403 ) {
F_80 ( V_615 , V_60 -> V_43 ) ;
F_232 ( V_3 ) ;
}
if ( V_7 -> V_963 & V_129 )
V_3 -> V_97 . V_160 = V_7 -> V_965 ;
if ( V_7 -> V_963 & V_294 )
V_3 -> V_97 . V_160 |= ( V_163 | V_164 ) ;
else
V_3 -> V_97 . V_160 &= ~ ( V_163 | V_164 ) ;
F_228 ( V_3 , V_3 -> V_97 . V_160 ) ;
F_243 ( V_3 , V_7 -> V_218 ) ;
F_78 ( V_223 , F_133 ( V_7 ) ) ;
F_241 ( V_3 , V_7 -> V_220 ) ;
F_78 ( V_419 , F_134 ( V_7 ) ) ;
F_343 ( V_3 , V_7 -> V_478 ) ;
F_227 ( V_3 ) ;
F_301 ( V_3 , V_356 , V_7 -> V_966 ) ;
F_301 ( V_3 , V_359 , V_7 -> V_967 ) ;
}
static int F_426 ( struct V_2 * V_3 , bool V_968 )
{
struct V_7 * V_7 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
int V_78 ;
struct V_77 * V_757 ;
if ( ! F_412 ( V_3 ) ||
! F_431 ( V_3 ) )
return 1 ;
F_144 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_784 == V_968 ) {
F_419 ( V_3 ,
V_968 ? V_969
: V_970 ) ;
return 1 ;
}
if ( ( V_7 -> V_57 & V_26 ) &&
! F_423 ( V_7 -> V_256 , V_390 ) ) {
F_419 ( V_3 , V_971 ) ;
return 1 ;
}
if ( F_47 ( V_7 , V_30 ) &&
! F_423 ( V_7 -> V_960 , V_390 ) ) {
F_419 ( V_3 , V_971 ) ;
return 1 ;
}
if ( V_7 -> V_972 > 0 ||
V_7 -> V_973 > 0 ||
V_7 -> V_974 > 0 ) {
F_480 ( L_35 ,
V_450 ) ;
F_419 ( V_3 , V_971 ) ;
return 1 ;
}
if ( ! F_170 ( V_7 -> V_57 ,
V_296 , V_297 ) ||
! F_170 ( V_7 -> V_58 ,
V_313 , V_314 ) ||
! F_170 ( V_7 -> V_59 ,
V_283 , V_284 ) ||
! F_170 ( V_7 -> V_962 ,
V_287 , V_288 ) ||
! F_170 ( V_7 -> V_963 ,
V_291 , V_292 ) )
{
F_419 ( V_3 , V_971 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_975 & F_174 ) != F_174 ) ||
( ( V_7 -> V_976 & F_175 ) != F_175 ) ) {
F_419 ( V_3 ,
V_977 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_218 & F_174 ) != F_174 ) ||
( ( V_7 -> V_220 & F_175 ) != F_175 ) ) {
F_481 ( V_3 , V_7 ,
V_833 , V_978 ) ;
return 1 ;
}
if ( V_7 -> V_979 != - 1ull ) {
F_481 ( V_3 , V_7 ,
V_833 , V_980 ) ;
return 1 ;
}
V_757 = F_401 ( V_60 ) ;
if ( ! V_757 )
return - V_401 ;
F_482 ( V_3 ) ;
V_60 -> V_8 . V_269 = F_74 ( V_268 ) ;
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
( F_71 ( V_211 ) & V_3 -> V_97 . V_214 ) |
( V_7 -> V_218 & V_7 -> V_215 ) |
( F_71 ( V_223 ) & ~ ( V_7 -> V_215 |
V_3 -> V_97 . V_214 ) ) ;
}
static inline unsigned long
F_484 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_71 ( V_417 ) & V_3 -> V_97 . V_456 ) |
( V_7 -> V_220 & V_7 -> V_221 ) |
( F_71 ( V_419 ) & ~ ( V_7 -> V_221 |
V_3 -> V_97 . V_456 ) ) ;
}
void F_485 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_218 = F_483 ( V_3 , V_7 ) ;
V_7 -> V_220 = F_484 ( V_3 , V_7 ) ;
F_351 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_953 ) ;
V_7 -> V_966 = F_340 ( V_3 , V_356 ) ;
V_7 -> V_967 = F_340 ( V_3 , V_359 ) ;
V_7 -> V_954 = F_71 ( V_227 ) ;
V_7 -> V_897 = F_72 ( V_896 ) ;
V_7 -> V_898 = F_72 ( V_427 ) ;
V_7 -> V_899 = F_72 ( V_425 ) ;
V_7 -> V_901 = F_72 ( V_900 ) ;
V_7 -> V_903 = F_72 ( V_902 ) ;
V_7 -> V_905 = F_72 ( V_904 ) ;
V_7 -> V_906 = F_72 ( V_603 ) ;
V_7 -> V_907 = F_72 ( V_602 ) ;
V_7 -> V_909 = F_73 ( V_908 ) ;
V_7 -> V_910 = F_73 ( V_497 ) ;
V_7 -> V_911 = F_73 ( V_500 ) ;
V_7 -> V_913 = F_73 ( V_912 ) ;
V_7 -> V_915 = F_73 ( V_914 ) ;
V_7 -> V_917 = F_73 ( V_916 ) ;
V_7 -> V_918 = F_73 ( V_605 ) ;
V_7 -> V_919 = F_73 ( V_441 ) ;
V_7 -> V_920 = F_73 ( V_504 ) ;
V_7 -> V_921 = F_73 ( V_502 ) ;
V_7 -> V_923 = F_73 ( V_922 ) ;
V_7 -> V_924 = F_73 ( V_429 ) ;
V_7 -> V_925 = F_73 ( V_426 ) ;
V_7 -> V_927 = F_73 ( V_926 ) ;
V_7 -> V_929 = F_73 ( V_928 ) ;
V_7 -> V_931 = F_73 ( V_930 ) ;
V_7 -> V_932 = F_73 ( V_606 ) ;
V_7 -> V_933 = F_73 ( V_443 ) ;
V_7 -> V_935 = F_71 ( V_934 ) ;
V_7 -> V_936 = F_71 ( V_498 ) ;
V_7 -> V_937 = F_71 ( V_499 ) ;
V_7 -> V_939 = F_71 ( V_938 ) ;
V_7 -> V_940 = F_71 ( V_342 ) ;
V_7 -> V_941 = F_71 ( V_343 ) ;
V_7 -> V_942 = F_71 ( V_604 ) ;
V_7 -> V_943 = F_71 ( V_440 ) ;
V_7 -> V_944 = F_71 ( V_505 ) ;
V_7 -> V_945 = F_71 ( V_503 ) ;
V_7 -> V_951 = F_73 ( V_607 ) ;
V_7 -> V_950 =
F_73 ( V_233 ) ;
V_7 -> V_955 =
F_71 ( V_609 ) ;
V_7 -> V_946 = F_74 ( V_610 ) ;
if ( V_7 -> V_963 & V_388 )
V_7 -> V_964 = F_74 ( V_352 ) ;
V_7 -> V_952 = F_73 ( V_346 ) ;
V_7 -> V_956 = F_71 ( V_349 ) ;
V_7 -> V_957 = F_71 ( V_348 ) ;
V_7 -> V_637 = F_73 ( V_805 ) ;
V_7 -> V_686 = F_71 ( V_673 ) ;
V_7 -> V_639 = F_73 ( V_806 ) ;
V_7 -> V_981 = F_73 ( V_672 ) ;
V_7 -> V_635 =
F_73 ( V_871 ) ;
V_7 -> V_868 =
F_73 ( V_725 ) ;
V_7 -> V_867 = F_73 ( V_240 ) ;
V_7 -> V_763 = F_73 ( V_781 ) ;
if ( ! ( V_7 -> V_637 & V_846 ) )
V_7 -> V_947 &= ~ V_17 ;
}
void F_486 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_962 & V_130 )
V_3 -> V_97 . V_160 = V_7 -> V_982 ;
if ( V_7 -> V_962 & V_289 )
V_3 -> V_97 . V_160 |= ( V_163 | V_164 ) ;
else
V_3 -> V_97 . V_160 &= ~ ( V_163 | V_164 ) ;
F_228 ( V_3 , V_3 -> V_97 . V_160 ) ;
F_301 ( V_3 , V_356 , V_7 -> V_961 ) ;
F_301 ( V_3 , V_359 , V_7 -> V_983 ) ;
F_335 ( V_3 , V_7 -> V_975 ) ;
F_91 ( V_3 ) ;
V_3 -> V_97 . V_214 = ( V_3 -> V_119 ? V_212 : 0 ) ;
F_78 ( V_216 , ~ V_3 -> V_97 . V_214 ) ;
V_3 -> V_97 . V_456 = ~ F_71 ( V_571 ) ;
F_337 ( V_3 , V_7 -> V_976 ) ;
F_343 ( V_3 , V_7 -> V_984 ) ;
F_227 ( V_3 ) ;
if ( V_403 ) {
F_232 ( V_3 ) ;
}
F_81 ( V_346 , V_7 -> V_985 ) ;
F_78 ( V_349 , V_7 -> V_986 ) ;
F_78 ( V_348 , V_7 -> V_987 ) ;
F_78 ( V_503 , V_7 -> V_988 ) ;
F_78 ( V_505 , V_7 -> V_989 ) ;
F_78 ( V_440 , V_7 -> V_990 ) ;
F_78 ( V_343 , V_7 -> V_991 ) ;
F_78 ( V_342 , V_7 -> V_992 ) ;
F_80 ( V_896 , V_7 -> V_993 ) ;
F_80 ( V_427 , V_7 -> V_994 ) ;
F_80 ( V_425 , V_7 -> V_995 ) ;
F_80 ( V_900 , V_7 -> V_996 ) ;
F_80 ( V_902 , V_7 -> V_997 ) ;
F_80 ( V_904 , V_7 -> V_998 ) ;
F_80 ( V_602 , V_7 -> V_999 ) ;
if ( V_7 -> V_962 & V_389 )
F_82 ( V_352 , V_7 -> V_1000 ) ;
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
F_408 ( V_60 , V_60 -> V_8 . V_754 ) ;
F_486 ( V_3 , V_7 ) ;
F_82 ( V_268 , V_60 -> V_8 . V_269 ) ;
V_60 -> V_961 = 0 ;
if ( V_60 -> V_8 . V_539 ) {
F_8 ( V_60 -> V_8 . V_539 ) ;
V_60 -> V_8 . V_539 = 0 ;
}
if ( F_79 ( V_60 -> V_807 ) ) {
V_60 -> V_807 = 0 ;
F_419 ( V_3 , F_73 ( V_90 ) ) ;
} else
F_417 ( V_3 ) ;
}
static void F_481 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_717 , unsigned long V_1002 )
{
F_486 ( V_3 , V_7 ) ;
V_7 -> V_637 = V_717 | V_846 ;
V_7 -> V_686 = V_1002 ;
F_417 ( V_3 ) ;
}
static int F_488 ( struct V_2 * V_3 ,
struct V_1003 * V_1004 ,
enum V_1005 V_1006 )
{
return V_1007 ;
}
static int T_11 F_489 ( void )
{
int V_520 , V_62 ;
F_490 ( V_127 , & V_165 ) ;
for ( V_62 = 0 ; V_62 < V_593 ; ++ V_62 )
F_491 ( V_62 , V_64 [ V_62 ] ) ;
V_575 = ( unsigned long * ) F_492 ( V_400 ) ;
if ( ! V_575 )
return - V_401 ;
V_520 = - V_401 ;
V_577 = ( unsigned long * ) F_492 ( V_400 ) ;
if ( ! V_577 )
goto V_522;
V_264 = ( unsigned long * ) F_492 ( V_400 ) ;
if ( ! V_264 )
goto V_1008;
V_263 = ( unsigned long * ) F_492 ( V_400 ) ;
if ( ! V_263 )
goto V_1009;
memset ( V_575 , 0xff , V_390 ) ;
F_493 ( 0x80 , V_575 ) ;
memset ( V_577 , 0xff , V_390 ) ;
memset ( V_264 , 0xff , V_390 ) ;
memset ( V_263 , 0xff , V_390 ) ;
F_494 ( 0 , V_546 ) ;
V_520 = F_495 ( & V_1010 , sizeof( struct V_1 ) ,
F_496 ( struct V_1 ) , V_1011 ) ;
if ( V_520 )
goto V_1012;
F_282 ( V_191 , false ) ;
F_282 ( V_193 , false ) ;
F_282 ( V_194 , true ) ;
F_282 ( V_345 , false ) ;
F_282 ( V_208 , false ) ;
F_282 ( V_347 , false ) ;
if ( V_86 ) {
F_497 ( 0ull ,
( V_405 ) ? V_1013 : 0ull ,
( V_405 ) ? V_1014 : 0ull ,
0ull , V_1015 ) ;
F_290 () ;
F_498 () ;
} else
F_499 () ;
return 0 ;
V_1012:
F_500 ( ( unsigned long ) V_263 ) ;
V_1009:
F_500 ( ( unsigned long ) V_264 ) ;
V_1008:
F_500 ( ( unsigned long ) V_577 ) ;
V_522:
F_500 ( ( unsigned long ) V_575 ) ;
return V_520 ;
}
static void T_12 F_501 ( void )
{
F_500 ( ( unsigned long ) V_264 ) ;
F_500 ( ( unsigned long ) V_263 ) ;
F_500 ( ( unsigned long ) V_577 ) ;
F_500 ( ( unsigned long ) V_575 ) ;
F_502 () ;
}
