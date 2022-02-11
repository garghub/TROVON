static bool F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_2 ,
( unsigned long * ) & V_1 -> V_3 ) ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return F_4 ( V_2 ,
( unsigned long * ) & V_1 -> V_3 ) ;
}
static int F_5 ( int V_4 , struct V_1 * V_1 )
{
return F_2 ( V_4 , ( unsigned long * ) V_1 -> V_5 ) ;
}
static inline struct V_6 * F_6 ( struct V_7 * V_8 )
{
return F_7 ( V_8 , struct V_6 , V_8 ) ;
}
static inline short F_8 ( unsigned long V_9 )
{
if ( V_9 >= V_10 || V_11 [ V_9 ] == 0 )
return - 1 ;
return V_11 [ V_9 ] ;
}
static inline struct V_12 * F_9 ( struct V_7 * V_8 )
{
return F_6 ( V_8 ) -> V_13 . V_14 ;
}
static struct V_15 * F_10 ( struct V_7 * V_8 , T_1 V_16 )
{
struct V_15 * V_15 = F_11 ( V_8 -> V_17 , V_16 >> V_18 ) ;
if ( F_12 ( V_15 ) )
return NULL ;
return V_15 ;
}
static void F_13 ( struct V_15 * V_15 )
{
F_14 ( V_15 ) ;
}
static void F_15 ( struct V_15 * V_15 )
{
F_16 ( V_15 ) ;
}
static inline bool F_17 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_21 |
V_22 ) ) ==
( V_23 | V_24 | V_22 ) ;
}
static inline bool F_18 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_21 |
V_22 ) ) ==
( V_23 | V_25 | V_22 ) ;
}
static inline bool F_19 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_21 |
V_22 ) ) ==
( V_23 | V_26 | V_22 ) ;
}
static inline bool F_20 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_22 ) )
== ( V_27 | V_22 ) ;
}
static inline bool F_21 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_21 |
V_22 ) ) ==
( V_23 | V_28 | V_22 ) ;
}
static inline bool F_22 ( void )
{
return V_29 . V_30 & V_31 ;
}
static inline bool F_23 ( void )
{
return V_29 . V_30 & V_32 ;
}
static inline bool F_24 ( struct V_17 * V_17 )
{
return ( F_23 () ) && ( F_25 ( V_17 ) ) ;
}
static inline bool F_26 ( void )
{
return V_29 . V_30 &
V_33 ;
}
static inline bool F_27 ( void )
{
return V_29 . V_34 &
V_35 ;
}
static inline bool F_28 ( void )
{
return V_29 . V_34 &
V_36 ;
}
static inline bool F_29 ( void )
{
return V_29 . V_34 &
V_37 ;
}
static inline bool F_30 ( void )
{
return V_29 . V_34 &
V_38 ;
}
static inline bool F_31 ( void )
{
return V_29 . V_39 & V_40 ;
}
static inline bool F_32 ( void )
{
return F_29 () &&
F_30 () &&
F_31 () ;
}
static inline bool F_33 ( void )
{
return F_23 () &&
F_27 () ;
}
static inline bool F_34 ( void )
{
return V_41 . V_42 & V_43 ;
}
static inline bool F_35 ( void )
{
return V_41 . V_42 & V_44 ;
}
static inline bool F_36 ( void )
{
return V_41 . V_42 & V_45 ;
}
static inline bool F_37 ( void )
{
return V_41 . V_42 & V_46 ;
}
static inline bool F_38 ( void )
{
return V_41 . V_42 & V_47 ;
}
static inline bool F_39 ( void )
{
return V_41 . V_42 & V_48 ;
}
static inline bool F_40 ( void )
{
return V_41 . V_42 & V_49 ;
}
static inline bool F_41 ( void )
{
return V_41 . V_42 & V_50 ;
}
static inline bool F_42 ( void )
{
return V_41 . V_42 & V_51 ;
}
static inline bool F_43 ( void )
{
return V_41 . V_52 & V_53 ;
}
static inline bool F_44 ( void )
{
return V_41 . V_52 & V_54 ;
}
static inline bool F_45 ( void )
{
return V_29 . V_34 &
V_55 ;
}
static inline bool F_46 ( void )
{
return V_29 . V_34 &
V_56 ;
}
static inline bool F_47 ( void )
{
return V_29 . V_34 &
V_57 ;
}
static inline bool F_48 ( struct V_17 * V_17 )
{
return V_58 && F_25 ( V_17 ) ;
}
static inline bool F_49 ( void )
{
return V_29 . V_34 &
V_59 ;
}
static inline bool F_50 ( void )
{
return V_29 . V_34 &
V_60 ;
}
static inline bool F_51 ( void )
{
return V_29 . V_34 &
V_61 ;
}
static inline bool F_52 ( void )
{
return V_29 . V_39 & V_62 ;
}
static inline bool F_53 ( void )
{
return V_29 . V_34 &
V_63 ;
}
static inline bool F_54 ( void )
{
T_3 V_64 ;
F_55 ( V_65 , V_64 ) ;
if ( ! ( V_64 & V_66 ) )
return false ;
return V_29 . V_34 &
V_67 ;
}
static inline bool F_56 ( void )
{
return V_58 ;
}
static inline bool F_57 ( struct V_12 * V_12 , T_2 V_68 )
{
return V_12 -> V_69 & V_68 ;
}
static inline bool F_58 ( struct V_12 * V_12 , T_2 V_68 )
{
return ( V_12 -> V_69 &
V_33 ) &&
( V_12 -> V_70 & V_68 ) ;
}
static inline bool F_59 ( struct V_12 * V_12 ,
struct V_7 * V_8 )
{
return V_12 -> V_71 & V_62 ;
}
static inline bool F_60 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_22 ) )
== ( V_23 | V_22 ) ;
}
static int F_61 ( struct V_6 * V_72 , T_2 V_73 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 -> V_75 ; ++ V_74 )
if ( V_76 [ V_72 -> V_77 [ V_74 ] . V_78 ] == V_73 )
return V_74 ;
return - 1 ;
}
static inline void F_62 ( int V_79 , T_4 V_52 , T_5 V_80 )
{
struct {
T_3 V_52 : 16 ;
T_3 V_81 : 48 ;
T_3 V_80 ;
} V_82 = { V_52 , 0 , V_80 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_63 ( int V_79 , T_3 V_83 , T_1 V_84 )
{
struct {
T_3 V_83 , V_84 ;
} V_82 = { V_83 , V_84 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_85 * F_64 ( struct V_6 * V_72 , T_2 V_73 )
{
int V_74 ;
V_74 = F_61 ( V_72 , V_73 ) ;
if ( V_74 >= 0 )
return & V_72 -> V_77 [ V_74 ] ;
return NULL ;
}
static void F_65 ( struct V_86 * V_86 )
{
T_3 V_87 = F_66 ( V_86 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_67 ( V_88 L_1 ,
V_86 , V_87 ) ;
}
static inline void F_68 ( struct V_89 * V_89 )
{
F_65 ( V_89 -> V_86 ) ;
V_89 -> V_90 = - 1 ;
V_89 -> V_91 = 0 ;
}
static void F_69 ( struct V_86 * V_86 )
{
T_3 V_87 = F_66 ( V_86 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_67 ( V_88 L_2 ,
V_86 , V_87 ) ;
}
static inline void F_70 ( int V_90 )
{
F_71 ( V_90 , & V_92 ) ;
}
static inline void F_72 ( int V_90 )
{
F_73 ( V_90 , & V_92 ) ;
}
static inline int F_74 ( int V_90 )
{
return F_75 ( V_90 , & V_92 ) ;
}
static void F_76 ( void )
{
int V_90 = F_77 () ;
struct V_89 * V_93 ;
if ( ! F_74 ( V_90 ) )
return;
F_78 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_65 ( V_93 -> V_86 ) ;
}
static inline void F_70 ( int V_90 ) { }
static inline void F_72 ( int V_90 ) { }
static void F_79 ( void * V_94 )
{
struct V_89 * V_89 = V_94 ;
int V_90 = F_77 () ;
if ( V_89 -> V_90 != V_90 )
return;
if ( F_80 ( V_95 , V_90 ) == V_89 -> V_86 )
F_80 ( V_95 , V_90 ) = NULL ;
F_72 ( V_90 ) ;
F_81 ( & V_89 -> V_96 ) ;
F_82 () ;
F_68 ( V_89 ) ;
F_70 ( V_90 ) ;
}
static void F_83 ( struct V_89 * V_89 )
{
int V_90 = V_89 -> V_90 ;
if ( V_90 != - 1 )
F_84 ( V_90 ,
F_79 , V_89 , 1 ) ;
}
static inline void F_85 ( struct V_6 * V_72 )
{
if ( V_72 -> V_52 == 0 )
return;
if ( F_43 () )
F_62 ( V_97 , V_72 -> V_52 , 0 ) ;
}
static inline void F_86 ( void )
{
if ( F_44 () )
F_62 ( V_98 , 0 , 0 ) ;
}
static inline void F_87 ( struct V_6 * V_72 )
{
if ( F_43 () )
F_85 ( V_72 ) ;
else
F_86 () ;
}
static inline void F_88 ( void )
{
if ( F_42 () )
F_63 ( V_99 , 0 , 0 ) ;
}
static inline void F_89 ( T_3 V_83 )
{
if ( V_100 ) {
if ( F_41 () )
F_63 ( V_101 , V_83 , 0 ) ;
else
F_88 () ;
}
}
static T_7 unsigned long F_90 ( unsigned long V_9 )
{
unsigned long V_102 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_102 ;
}
static T_7 T_4 F_91 ( unsigned long V_9 )
{
return F_90 ( V_9 ) ;
}
static T_7 T_2 F_92 ( unsigned long V_9 )
{
return F_90 ( V_9 ) ;
}
static T_7 T_3 F_93 ( unsigned long V_9 )
{
#ifdef F_94
return F_90 ( V_9 ) ;
#else
return F_90 ( V_9 ) | ( ( T_3 ) F_90 ( V_9 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_95 ( unsigned long V_9 , unsigned long V_102 )
{
F_67 ( V_88 L_3 ,
V_9 , V_102 , F_92 ( V_103 ) ) ;
F_96 () ;
}
static void F_97 ( unsigned long V_9 , unsigned long V_102 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_98 ( error ) )
F_95 ( V_9 , V_102 ) ;
}
static void F_99 ( unsigned long V_9 , T_4 V_102 )
{
F_97 ( V_9 , V_102 ) ;
}
static void F_100 ( unsigned long V_9 , T_2 V_102 )
{
F_97 ( V_9 , V_102 ) ;
}
static void F_101 ( unsigned long V_9 , T_3 V_102 )
{
F_97 ( V_9 , V_102 ) ;
#ifndef F_94
asm volatile ("");
F_97 ( V_9 + 1 , V_102 >> 32 ) ;
#endif
}
static void F_102 ( unsigned long V_9 , T_2 V_104 )
{
F_97 ( V_9 , F_90 ( V_9 ) & ~ V_104 ) ;
}
static void F_103 ( unsigned long V_9 , T_2 V_104 )
{
F_97 ( V_9 , F_90 ( V_9 ) | V_104 ) ;
}
static void F_104 ( struct V_6 * V_72 )
{
V_72 -> V_105 . V_106 = 0 ;
}
static bool F_105 ( struct V_6 * V_72 , unsigned V_107 ,
unsigned V_9 )
{
bool V_108 ;
T_2 V_104 = 1 << ( V_107 * V_109 + V_9 ) ;
if ( ! ( V_72 -> V_8 . V_110 . V_111 & ( 1 << V_112 ) ) ) {
V_72 -> V_8 . V_110 . V_111 |= ( 1 << V_112 ) ;
V_72 -> V_105 . V_106 = 0 ;
}
V_108 = V_72 -> V_105 . V_106 & V_104 ;
V_72 -> V_105 . V_106 |= V_104 ;
return V_108 ;
}
static T_4 F_106 ( struct V_6 * V_72 , unsigned V_107 )
{
T_4 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_114 ;
if ( ! F_105 ( V_72 , V_107 , V_115 ) )
* V_113 = F_91 ( V_116 [ V_107 ] . V_114 ) ;
return * V_113 ;
}
static T_9 F_107 ( struct V_6 * V_72 , unsigned V_107 )
{
T_9 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_117 ;
if ( ! F_105 ( V_72 , V_107 , V_118 ) )
* V_113 = F_90 ( V_116 [ V_107 ] . V_117 ) ;
return * V_113 ;
}
static T_2 F_108 ( struct V_6 * V_72 , unsigned V_107 )
{
T_2 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_119 ;
if ( ! F_105 ( V_72 , V_107 , V_120 ) )
* V_113 = F_92 ( V_116 [ V_107 ] . V_119 ) ;
return * V_113 ;
}
static T_2 F_109 ( struct V_6 * V_72 , unsigned V_107 )
{
T_2 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_121 ;
if ( ! F_105 ( V_72 , V_107 , V_122 ) )
* V_113 = F_92 ( V_116 [ V_107 ] . V_123 ) ;
return * V_113 ;
}
static void F_110 ( struct V_7 * V_8 )
{
T_2 V_124 ;
V_124 = ( 1u << V_24 ) | ( 1u << V_26 ) | ( 1u << V_28 ) |
( 1u << V_25 ) | ( 1u << V_125 ) ;
if ( ( V_8 -> V_126 &
( V_127 | V_128 ) ) ==
( V_127 | V_128 ) )
V_124 |= 1u << V_129 ;
if ( F_6 ( V_8 ) -> V_130 . V_131 )
V_124 = ~ 0 ;
if ( V_100 )
V_124 &= ~ ( 1u << V_24 ) ;
if ( V_8 -> V_132 )
V_124 &= ~ ( 1u << V_25 ) ;
if ( F_111 ( V_8 ) )
V_124 |= F_9 ( V_8 ) -> V_133 ;
F_100 ( V_134 , V_124 ) ;
}
static void F_112 ( unsigned long V_135 ,
unsigned long exit )
{
F_102 ( V_136 , V_135 ) ;
F_102 ( V_137 , exit ) ;
}
static void F_113 ( struct V_6 * V_72 , unsigned V_73 )
{
unsigned V_74 ;
struct V_138 * V_139 = & V_72 -> V_138 ;
switch ( V_73 ) {
case V_140 :
if ( V_141 ) {
F_112 ( V_142 ,
V_143 ) ;
return;
}
break;
case V_144 :
if ( V_145 ) {
F_112 (
V_146 ,
V_147 ) ;
return;
}
break;
}
for ( V_74 = 0 ; V_74 < V_139 -> V_148 ; ++ V_74 )
if ( V_139 -> V_149 [ V_74 ] . V_78 == V_73 )
break;
if ( V_74 == V_139 -> V_148 )
return;
-- V_139 -> V_148 ;
V_139 -> V_149 [ V_74 ] = V_139 -> V_149 [ V_139 -> V_148 ] ;
V_139 -> V_150 [ V_74 ] = V_139 -> V_150 [ V_139 -> V_148 ] ;
F_100 ( V_151 , V_139 -> V_148 ) ;
F_100 ( V_152 , V_139 -> V_148 ) ;
}
static void F_114 ( unsigned long V_135 ,
unsigned long exit , unsigned long V_153 ,
unsigned long V_154 , T_3 V_155 , T_3 V_156 )
{
F_101 ( V_153 , V_155 ) ;
F_101 ( V_154 , V_156 ) ;
F_103 ( V_136 , V_135 ) ;
F_103 ( V_137 , exit ) ;
}
static void F_115 ( struct V_6 * V_72 , unsigned V_73 ,
T_3 V_155 , T_3 V_156 )
{
unsigned V_74 ;
struct V_138 * V_139 = & V_72 -> V_138 ;
switch ( V_73 ) {
case V_140 :
if ( V_141 ) {
F_114 ( V_142 ,
V_143 ,
V_157 ,
V_158 ,
V_155 , V_156 ) ;
return;
}
break;
case V_144 :
if ( V_145 ) {
F_114 (
V_146 ,
V_147 ,
V_159 ,
V_160 ,
V_155 , V_156 ) ;
return;
}
break;
}
for ( V_74 = 0 ; V_74 < V_139 -> V_148 ; ++ V_74 )
if ( V_139 -> V_149 [ V_74 ] . V_78 == V_73 )
break;
if ( V_74 == V_161 ) {
F_116 ( V_162 L_4
L_5 , V_73 ) ;
return;
} else if ( V_74 == V_139 -> V_148 ) {
++ V_139 -> V_148 ;
F_100 ( V_151 , V_139 -> V_148 ) ;
F_100 ( V_152 , V_139 -> V_148 ) ;
}
V_139 -> V_149 [ V_74 ] . V_78 = V_73 ;
V_139 -> V_149 [ V_74 ] . V_102 = V_155 ;
V_139 -> V_150 [ V_74 ] . V_78 = V_73 ;
V_139 -> V_150 [ V_74 ] . V_102 = V_156 ;
}
static void F_117 ( void )
{
struct V_163 * V_164 = & F_118 ( V_165 ) ;
struct V_166 * V_167 ;
V_167 = ( void * ) V_164 -> V_168 ;
V_167 [ V_169 ] . type = 9 ;
F_119 () ;
}
static bool F_120 ( struct V_6 * V_72 , int V_170 )
{
T_3 V_171 ;
T_3 V_172 ;
V_171 = V_72 -> V_8 . V_110 . V_173 ;
V_172 = V_174 | V_175 ;
#ifdef F_94
V_172 |= V_176 | V_177 ;
if ( V_171 & V_176 )
V_172 &= ~ ( T_3 ) V_175 ;
#endif
V_171 &= ~ V_172 ;
V_171 |= V_178 & V_172 ;
V_72 -> V_77 [ V_170 ] . V_179 = V_171 ;
V_72 -> V_77 [ V_170 ] . V_104 = ~ V_172 ;
F_113 ( V_72 , V_140 ) ;
if ( V_100 && ( ( V_72 -> V_8 . V_110 . V_173 ^ V_178 ) & V_174 ) ) {
V_171 = V_72 -> V_8 . V_110 . V_173 ;
if ( ! ( V_171 & V_176 ) )
V_171 &= ~ V_177 ;
F_115 ( V_72 , V_140 , V_171 , V_178 ) ;
return false ;
}
return true ;
}
static unsigned long F_121 ( T_4 V_114 )
{
struct V_163 * V_164 = & F_118 ( V_165 ) ;
struct V_166 * V_180 ;
unsigned long V_181 ;
unsigned long V_93 ;
if ( ! ( V_114 & ~ 3 ) )
return 0 ;
V_181 = V_164 -> V_168 ;
if ( V_114 & 4 ) {
T_4 V_182 = F_122 () ;
if ( ! ( V_182 & ~ 3 ) )
return 0 ;
V_181 = F_121 ( V_182 ) ;
}
V_180 = (struct V_166 * ) ( V_181 + ( V_114 & ~ 7 ) ) ;
V_93 = F_123 ( V_180 ) ;
#ifdef F_94
if ( V_180 -> V_183 == 0 && ( V_180 -> type == 2 || V_180 -> type == 9 || V_180 -> type == 11 ) )
V_93 |= ( ( unsigned long ) ( (struct V_184 * ) V_180 ) -> V_185 ) << 32 ;
#endif
return V_93 ;
}
static inline unsigned long F_124 ( void )
{
T_4 V_186 ;
asm("str %0" : "=g"(tr));
return F_121 ( V_186 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_74 ;
if ( V_72 -> V_187 . V_188 )
return;
V_72 -> V_187 . V_188 = 1 ;
V_72 -> V_187 . V_189 = F_122 () ;
V_72 -> V_187 . V_190 = V_72 -> V_187 . V_189 ;
F_126 ( V_191 , V_72 -> V_187 . V_192 ) ;
if ( ! ( V_72 -> V_187 . V_192 & 7 ) ) {
F_99 ( V_193 , V_72 -> V_187 . V_192 ) ;
V_72 -> V_187 . V_194 = 0 ;
} else {
F_99 ( V_193 , 0 ) ;
V_72 -> V_187 . V_194 = 1 ;
}
F_126 ( V_195 , V_72 -> V_187 . V_196 ) ;
if ( ! ( V_72 -> V_187 . V_196 & 7 ) )
F_99 ( V_197 , V_72 -> V_187 . V_196 ) ;
else {
F_99 ( V_197 , 0 ) ;
V_72 -> V_187 . V_190 = 1 ;
}
#ifdef F_94
F_126 ( V_198 , V_72 -> V_187 . V_199 ) ;
F_126 ( V_200 , V_72 -> V_187 . V_201 ) ;
#endif
#ifdef F_94
F_97 ( V_202 , F_127 ( V_203 ) ) ;
F_97 ( V_204 , F_127 ( V_205 ) ) ;
#else
F_97 ( V_202 , F_121 ( V_72 -> V_187 . V_192 ) ) ;
F_97 ( V_204 , F_121 ( V_72 -> V_187 . V_196 ) ) ;
#endif
#ifdef F_94
F_55 ( V_206 , V_72 -> V_207 ) ;
if ( F_128 ( & V_72 -> V_8 ) )
F_129 ( V_206 , V_72 -> V_208 ) ;
#endif
for ( V_74 = 0 ; V_74 < V_72 -> V_209 ; ++ V_74 )
F_130 ( V_72 -> V_77 [ V_74 ] . V_78 ,
V_72 -> V_77 [ V_74 ] . V_179 ,
V_72 -> V_77 [ V_74 ] . V_104 ) ;
}
static void F_131 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_187 . V_188 )
return;
++ V_72 -> V_8 . V_210 . V_211 ;
V_72 -> V_187 . V_188 = 0 ;
#ifdef F_94
if ( F_128 ( & V_72 -> V_8 ) )
F_55 ( V_206 , V_72 -> V_208 ) ;
#endif
if ( V_72 -> V_187 . V_190 ) {
F_132 ( V_72 -> V_187 . V_189 ) ;
#ifdef F_94
F_133 ( V_72 -> V_187 . V_196 ) ;
#else
F_134 ( V_195 , V_72 -> V_187 . V_196 ) ;
#endif
}
if ( V_72 -> V_187 . V_194 )
F_134 ( V_191 , V_72 -> V_187 . V_192 ) ;
#ifdef F_94
if ( F_98 ( V_72 -> V_187 . V_199 | V_72 -> V_187 . V_201 ) ) {
F_134 ( V_198 , V_72 -> V_187 . V_199 ) ;
F_134 ( V_200 , V_72 -> V_187 . V_201 ) ;
}
#endif
F_117 () ;
#ifdef F_94
F_129 ( V_206 , V_72 -> V_207 ) ;
#endif
if ( ! F_135 () && ! V_72 -> V_8 . V_212 )
F_136 () ;
F_137 ( & F_118 ( V_165 ) ) ;
}
static void F_138 ( struct V_6 * V_72 )
{
F_139 () ;
F_131 ( V_72 ) ;
F_140 () ;
}
static void F_141 ( struct V_7 * V_8 , int V_90 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_87 = F_66 ( F_80 ( V_213 , V_90 ) ) ;
if ( ! V_214 )
F_142 ( V_87 ) ;
else if ( V_72 -> V_89 -> V_90 != V_90 )
F_83 ( V_72 -> V_89 ) ;
if ( F_80 ( V_95 , V_90 ) != V_72 -> V_89 -> V_86 ) {
F_80 ( V_95 , V_90 ) = V_72 -> V_89 -> V_86 ;
F_69 ( V_72 -> V_89 -> V_86 ) ;
}
if ( V_72 -> V_89 -> V_90 != V_90 ) {
struct V_163 * V_164 = & F_118 ( V_165 ) ;
unsigned long V_215 ;
F_143 ( V_216 , V_8 ) ;
F_144 () ;
F_72 ( V_90 ) ;
F_145 () ;
F_146 ( & V_72 -> V_89 -> V_96 ,
& F_80 ( V_217 , V_90 ) ) ;
F_70 ( V_90 ) ;
F_147 () ;
F_97 ( V_218 , F_124 () ) ;
F_97 ( V_219 , V_164 -> V_168 ) ;
F_55 ( V_220 , V_215 ) ;
F_97 ( V_221 , V_215 ) ;
V_72 -> V_89 -> V_90 = V_90 ;
}
}
static void F_148 ( struct V_7 * V_8 )
{
F_131 ( F_6 ( V_8 ) ) ;
if ( ! V_214 ) {
F_79 ( F_6 ( V_8 ) -> V_89 ) ;
V_8 -> V_90 = - 1 ;
F_149 () ;
}
}
static void F_150 ( struct V_7 * V_8 )
{
T_9 V_222 ;
if ( V_8 -> V_132 )
return;
V_8 -> V_132 = 1 ;
V_222 = F_90 ( V_223 ) ;
V_222 &= ~ ( V_224 | V_225 ) ;
V_222 |= F_151 ( V_8 , V_224 | V_225 ) ;
F_97 ( V_223 , V_222 ) ;
F_110 ( V_8 ) ;
V_8 -> V_110 . V_226 = V_224 ;
if ( F_111 ( V_8 ) )
V_8 -> V_110 . V_226 &=
~ F_9 ( V_8 ) -> V_227 ;
F_97 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
}
static inline unsigned long F_152 ( struct V_12 * V_229 )
{
return ( V_229 -> V_230 & ~ V_229 -> V_227 ) |
( V_229 -> V_231 & V_229 -> V_227 ) ;
}
static inline unsigned long F_153 ( struct V_12 * V_229 )
{
return ( V_229 -> V_232 & ~ V_229 -> V_233 ) |
( V_229 -> V_234 & V_229 -> V_233 ) ;
}
static void F_154 ( struct V_7 * V_8 )
{
F_155 ( V_8 ) ;
F_103 ( V_223 , V_224 | V_225 ) ;
F_110 ( V_8 ) ;
V_8 -> V_110 . V_226 = 0 ;
F_97 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
V_12 -> V_230 = ( V_12 -> V_230 & ~ V_224 ) |
( V_8 -> V_110 . V_222 & V_224 ) ;
F_97 ( V_235 , F_152 ( V_12 ) ) ;
} else
F_97 ( V_235 , V_8 -> V_110 . V_222 ) ;
}
static unsigned long F_156 ( struct V_7 * V_8 )
{
unsigned long V_236 , V_237 ;
if ( ! F_157 ( V_238 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ) {
F_158 ( V_238 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_236 = F_90 ( V_239 ) ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
V_236 &= V_240 ;
V_237 = F_6 ( V_8 ) -> V_130 . V_237 ;
V_236 |= V_237 & ~ V_240 ;
}
F_6 ( V_8 ) -> V_236 = V_236 ;
}
return F_6 ( V_8 ) -> V_236 ;
}
static void F_159 ( struct V_7 * V_8 , unsigned long V_236 )
{
F_158 ( V_238 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
F_6 ( V_8 ) -> V_236 = V_236 ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
F_6 ( V_8 ) -> V_130 . V_237 = V_236 ;
V_236 |= V_241 | V_242 ;
}
F_97 ( V_239 , V_236 ) ;
}
static T_2 F_160 ( struct V_7 * V_8 , int V_104 )
{
T_2 V_243 = F_92 ( V_244 ) ;
int V_108 = 0 ;
if ( V_243 & V_245 )
V_108 |= V_246 ;
if ( V_243 & V_247 )
V_108 |= V_248 ;
return V_108 & V_104 ;
}
static void F_161 ( struct V_7 * V_8 , int V_104 )
{
T_2 V_249 = F_92 ( V_244 ) ;
T_2 V_243 = V_249 ;
V_243 &= ~ ( V_245 | V_247 ) ;
if ( V_104 & V_248 )
V_243 |= V_247 ;
else if ( V_104 & V_246 )
V_243 |= V_245 ;
if ( ( V_243 != V_249 ) )
F_100 ( V_244 , V_243 ) ;
}
static void F_162 ( struct V_7 * V_8 )
{
unsigned long V_250 ;
V_250 = F_163 ( V_8 ) ;
V_250 += F_92 ( V_251 ) ;
F_164 ( V_8 , V_250 ) ;
F_161 ( V_8 , 0 ) ;
}
static int F_165 ( struct V_7 * V_8 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( ! ( V_12 -> V_133 & ( 1u << V_24 ) ) )
return 0 ;
F_166 ( V_8 ) ;
return 1 ;
}
static void F_167 ( struct V_7 * V_8 , unsigned V_148 ,
bool V_252 , T_2 V_253 ,
bool V_254 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_19 = V_148 | V_22 ;
if ( V_148 == V_24 && F_111 ( V_8 ) &&
! V_72 -> V_13 . V_255 && F_165 ( V_8 ) )
return;
if ( V_252 ) {
F_100 ( V_256 , V_253 ) ;
V_19 |= V_257 ;
}
if ( V_72 -> V_130 . V_131 ) {
int V_258 = 0 ;
if ( F_168 ( V_148 ) )
V_258 = V_8 -> V_110 . V_259 ;
if ( F_169 ( V_8 , V_148 , V_258 ) != V_260 )
F_143 ( V_261 , V_8 ) ;
return;
}
if ( F_168 ( V_148 ) ) {
F_100 ( V_262 ,
V_72 -> V_8 . V_110 . V_259 ) ;
V_19 |= V_263 ;
} else
V_19 |= V_23 ;
F_100 ( V_264 , V_19 ) ;
}
static bool F_170 ( void )
{
return F_50 () ;
}
static bool F_171 ( void )
{
return F_51 () && V_100 ;
}
static void F_172 ( struct V_6 * V_72 , int V_265 , int V_266 )
{
struct V_85 V_267 ;
V_267 = V_72 -> V_77 [ V_266 ] ;
V_72 -> V_77 [ V_266 ] = V_72 -> V_77 [ V_265 ] ;
V_72 -> V_77 [ V_265 ] = V_267 ;
}
static void F_173 ( struct V_7 * V_8 )
{
unsigned long * V_268 ;
if ( F_25 ( V_8 -> V_17 ) && F_174 ( V_8 -> V_110 . V_269 ) ) {
if ( F_128 ( V_8 ) )
V_268 = V_270 ;
else
V_268 = V_271 ;
} else {
if ( F_128 ( V_8 ) )
V_268 = V_272 ;
else
V_268 = V_273 ;
}
F_101 ( V_274 , F_66 ( V_268 ) ) ;
}
static void F_175 ( struct V_6 * V_72 )
{
int V_209 , V_78 ;
V_209 = 0 ;
#ifdef F_94
if ( F_128 ( & V_72 -> V_8 ) ) {
V_78 = F_61 ( V_72 , V_275 ) ;
if ( V_78 >= 0 )
F_172 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_61 ( V_72 , V_276 ) ;
if ( V_78 >= 0 )
F_172 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_61 ( V_72 , V_277 ) ;
if ( V_78 >= 0 )
F_172 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_61 ( V_72 , V_278 ) ;
if ( V_78 >= 0 && V_72 -> V_279 )
F_172 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_61 ( V_72 , V_280 ) ;
if ( ( V_78 >= 0 ) && ( V_72 -> V_8 . V_110 . V_173 & V_175 ) )
F_172 ( V_72 , V_78 , V_209 ++ ) ;
}
#endif
V_78 = F_61 ( V_72 , V_140 ) ;
if ( V_78 >= 0 && F_120 ( V_72 , V_78 ) )
F_172 ( V_72 , V_78 , V_209 ++ ) ;
V_72 -> V_209 = V_209 ;
if ( F_22 () )
F_173 ( & V_72 -> V_8 ) ;
}
static T_3 F_176 ( void )
{
T_3 V_281 , V_282 ;
F_177 ( V_281 ) ;
V_282 = F_93 ( V_283 ) ;
return V_281 + V_282 ;
}
T_3 F_178 ( struct V_7 * V_8 , T_3 V_281 )
{
T_3 V_282 ;
V_282 = F_111 ( V_8 ) ?
F_6 ( V_8 ) -> V_13 . V_284 :
F_93 ( V_283 ) ;
return V_281 + V_282 ;
}
static void F_179 ( struct V_7 * V_8 , T_2 V_285 , bool V_286 )
{
if ( ! V_286 )
return;
if ( V_285 > V_287 ) {
V_8 -> V_110 . V_288 = 1 ;
V_8 -> V_110 . V_289 = 1 ;
} else
F_180 ( 1 , L_6 ) ;
}
static T_3 F_181 ( struct V_7 * V_8 )
{
return F_93 ( V_283 ) ;
}
static void F_182 ( struct V_7 * V_8 , T_3 V_290 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 ;
F_6 ( V_8 ) -> V_13 . V_284 = V_290 ;
V_12 = F_9 ( V_8 ) ;
F_101 ( V_283 , V_290 +
( F_57 ( V_12 , V_291 ) ?
V_12 -> V_282 : 0 ) ) ;
} else {
F_101 ( V_283 , V_290 ) ;
}
}
static void F_183 ( struct V_7 * V_8 , T_10 V_292 , bool V_150 )
{
T_3 V_290 = F_93 ( V_283 ) ;
F_101 ( V_283 , V_290 + V_292 ) ;
if ( F_111 ( V_8 ) ) {
F_6 ( V_8 ) -> V_13 . V_284 += V_292 ;
}
}
static T_3 F_184 ( struct V_7 * V_8 , T_3 V_293 )
{
return V_293 - F_185 () ;
}
static bool F_186 ( struct V_7 * V_8 )
{
struct V_294 * V_295 = F_187 ( V_8 , 1 , 0 ) ;
return V_295 && ( V_295 -> V_296 & ( 1 << ( V_297 & 31 ) ) ) ;
}
static inline bool F_188 ( struct V_7 * V_8 )
{
return V_13 && F_186 ( V_8 ) ;
}
static T_11 void F_189 ( void )
{
F_190 ( V_298 ,
V_299 , V_300 ) ;
V_299 |= V_301 ;
V_300 &= V_302 |
V_303 | V_62 |
V_304 ;
V_300 |= V_301 ;
V_305 = V_306 ;
#ifdef F_94
V_307 = V_308 ;
#else
V_307 = 0 ;
#endif
V_307 |= V_306 ;
F_190 ( V_309 ,
V_310 , V_311 ) ;
V_310 = V_312 ;
V_311 &=
V_313 | V_314 ;
V_311 |= V_312 ;
F_190 ( V_315 ,
V_316 , V_317 ) ;
V_316 = 0 ;
V_317 &=
V_318 | V_291 |
V_319 | V_320 |
V_321 | V_322 |
V_323 |
#ifdef F_94
V_324 | V_325 |
#endif
V_326 | V_327 |
V_328 | V_329 |
V_330 | V_331 |
V_332 |
V_33 ;
V_317 |= V_31 ;
F_190 ( V_333 ,
V_334 , V_335 ) ;
V_334 = 0 ;
V_335 &=
V_35 |
V_63 ;
F_190 ( V_65 , V_336 , V_337 ) ;
V_336 &= V_338 |
V_339 ;
V_337 = 0 ;
}
static inline bool F_191 ( T_2 V_3 , T_2 V_340 , T_2 V_341 )
{
return ( ( V_3 & V_341 ) | V_340 ) == V_3 ;
}
static inline T_3 F_192 ( T_2 V_340 , T_2 V_341 )
{
return V_340 | ( ( T_3 ) V_341 << 32 ) ;
}
static int F_193 ( struct V_7 * V_8 , T_2 V_342 , T_3 * V_343 )
{
if ( ! F_188 ( V_8 ) && V_342 >= V_344 &&
V_342 <= V_345 ) {
F_194 ( V_8 , V_346 , 0 ) ;
return 1 ;
}
switch ( V_342 ) {
case V_347 :
* V_343 = 0 ;
break;
case V_344 :
* V_343 = V_348 |
( ( T_3 ) V_349 << V_350 ) |
( V_351 << V_352 ) ;
break;
case V_353 :
case V_298 :
* V_343 = F_192 ( V_299 ,
V_300 ) ;
break;
case V_354 :
case V_315 :
* V_343 = F_192 ( V_316 ,
V_317 ) ;
break;
case V_355 :
case V_356 :
* V_343 = F_192 ( V_305 ,
V_307 ) ;
break;
case V_345 :
case V_309 :
* V_343 = F_192 ( V_310 ,
V_311 ) ;
break;
case V_65 :
* V_343 = F_192 ( V_336 ,
V_337 ) ;
break;
#define F_195 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_196 X86_CR4_VMXE
case V_357 :
* V_343 = F_195 ;
break;
case V_358 :
* V_343 = - 1ULL ;
break;
case V_359 :
* V_343 = F_196 ;
break;
case V_360 :
* V_343 = - 1ULL ;
break;
case V_361 :
* V_343 = 0x1f ;
break;
case V_333 :
* V_343 = F_192 ( V_334 ,
V_335 ) ;
break;
case V_362 :
* V_343 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_197 ( struct V_7 * V_8 , T_2 V_342 , T_3 V_179 )
{
if ( ! F_188 ( V_8 ) )
return 0 ;
if ( V_342 == V_347 )
return 1 ;
return 0 ;
}
static int F_198 ( struct V_7 * V_8 , T_2 V_342 , T_3 * V_343 )
{
T_3 V_179 ;
struct V_85 * V_73 ;
if ( ! V_343 ) {
F_67 ( V_88 L_7 ) ;
return - V_363 ;
}
switch ( V_342 ) {
#ifdef F_94
case V_203 :
V_179 = F_90 ( V_364 ) ;
break;
case V_205 :
V_179 = F_90 ( V_365 ) ;
break;
case V_206 :
F_138 ( F_6 ( V_8 ) ) ;
V_179 = F_6 ( V_8 ) -> V_208 ;
break;
#endif
case V_140 :
return F_199 ( V_8 , V_342 , V_343 ) ;
case V_366 :
V_179 = F_176 () ;
break;
case V_367 :
V_179 = F_92 ( V_368 ) ;
break;
case V_369 :
V_179 = F_90 ( V_370 ) ;
break;
case V_220 :
V_179 = F_90 ( V_371 ) ;
break;
case V_278 :
if ( ! F_6 ( V_8 ) -> V_279 )
return 1 ;
default:
if ( F_193 ( V_8 , V_342 , V_343 ) )
return 0 ;
V_73 = F_64 ( F_6 ( V_8 ) , V_342 ) ;
if ( V_73 ) {
V_179 = V_73 -> V_179 ;
break;
}
return F_199 ( V_8 , V_342 , V_343 ) ;
}
* V_343 = V_179 ;
return 0 ;
}
static int F_200 ( struct V_7 * V_8 , struct V_372 * V_373 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 ;
int V_108 = 0 ;
T_2 V_342 = V_373 -> V_78 ;
T_3 V_179 = V_373 -> V_179 ;
switch ( V_342 ) {
case V_140 :
V_108 = F_201 ( V_8 , V_373 ) ;
break;
#ifdef F_94
case V_203 :
F_104 ( V_72 ) ;
F_97 ( V_364 , V_179 ) ;
break;
case V_205 :
F_104 ( V_72 ) ;
F_97 ( V_365 , V_179 ) ;
break;
case V_206 :
F_138 ( V_72 ) ;
V_72 -> V_208 = V_179 ;
break;
#endif
case V_367 :
F_100 ( V_368 , V_179 ) ;
break;
case V_369 :
F_97 ( V_370 , V_179 ) ;
break;
case V_220 :
F_97 ( V_371 , V_179 ) ;
break;
case V_366 :
F_202 ( V_8 , V_373 ) ;
break;
case V_374 :
if ( V_29 . V_375 & V_313 ) {
F_101 ( V_376 , V_179 ) ;
V_8 -> V_110 . V_377 = V_179 ;
break;
}
V_108 = F_201 ( V_8 , V_373 ) ;
break;
case V_378 :
V_108 = F_201 ( V_8 , V_373 ) ;
break;
case V_278 :
if ( ! V_72 -> V_279 )
return 1 ;
if ( ( V_179 >> 32 ) != 0 )
return 1 ;
default:
if ( F_197 ( V_8 , V_342 , V_179 ) )
break;
V_73 = F_64 ( V_72 , V_342 ) ;
if ( V_73 ) {
V_73 -> V_179 = V_179 ;
if ( V_73 - V_72 -> V_77 < V_72 -> V_209 ) {
F_139 () ;
F_130 ( V_73 -> V_78 , V_73 -> V_179 ,
V_73 -> V_104 ) ;
F_140 () ;
}
break;
}
V_108 = F_201 ( V_8 , V_373 ) ;
}
return V_108 ;
}
static void F_203 ( struct V_7 * V_8 , enum V_379 V_380 )
{
F_158 ( V_380 , ( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
switch ( V_380 ) {
case V_381 :
V_8 -> V_110 . V_382 [ V_381 ] = F_90 ( V_383 ) ;
break;
case V_384 :
V_8 -> V_110 . V_382 [ V_384 ] = F_90 ( V_385 ) ;
break;
case V_386 :
if ( V_100 )
F_204 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_205 ( void )
{
return F_206 () ;
}
static T_11 int F_207 ( void )
{
T_3 V_73 ;
F_55 ( V_347 , V_73 ) ;
if ( V_73 & V_387 ) {
if ( ! ( V_73 & V_388 )
&& F_208 () )
return 1 ;
if ( ! ( V_73 & V_389 )
&& ( V_73 & V_388 )
&& ! F_208 () ) {
F_67 ( V_162 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_73 & V_389 )
&& ! F_208 () )
return 1 ;
}
return 0 ;
}
static void F_142 ( T_3 V_16 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_209 ( void * V_390 )
{
int V_90 = F_77 () ;
T_3 V_87 = F_66 ( F_80 ( V_213 , V_90 ) ) ;
T_3 V_391 , V_392 ;
if ( F_210 () & V_393 )
return - V_394 ;
F_211 ( & F_80 ( V_217 , V_90 ) ) ;
F_70 ( V_90 ) ;
F_55 ( V_347 , V_391 ) ;
V_392 = V_387 ;
V_392 |= V_389 ;
if ( F_208 () )
V_392 |= V_388 ;
if ( ( V_391 & V_392 ) != V_392 ) {
F_129 ( V_347 , V_391 | V_392 ) ;
}
F_212 ( F_210 () | V_393 ) ;
if ( V_214 ) {
F_142 ( V_87 ) ;
F_88 () ;
}
F_213 ( & F_118 ( V_165 ) ) ;
return 0 ;
}
static void F_214 ( void )
{
int V_90 = F_77 () ;
struct V_89 * V_93 , * V_395 ;
F_215 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_79 ( V_93 ) ;
}
static void F_149 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_216 ( void * V_390 )
{
if ( V_214 ) {
F_214 () ;
F_149 () ;
}
F_212 ( F_210 () & ~ V_393 ) ;
}
static T_11 int F_217 ( T_2 V_396 , T_2 V_397 ,
T_2 V_73 , T_2 * V_398 )
{
T_2 V_399 , V_400 ;
T_2 V_401 = V_396 | V_397 ;
F_190 ( V_73 , V_399 , V_400 ) ;
V_401 &= V_400 ;
V_401 |= V_399 ;
if ( V_396 & ~ V_401 )
return - V_402 ;
* V_398 = V_401 ;
return 0 ;
}
static T_11 bool F_218 ( T_2 V_73 , T_2 V_401 )
{
T_2 V_399 , V_400 ;
F_190 ( V_73 , V_399 , V_400 ) ;
return V_400 & V_401 ;
}
static T_11 int F_219 ( struct V_29 * V_403 )
{
T_2 V_399 , V_400 ;
T_2 V_404 , V_405 , V_406 , V_407 ;
T_2 V_408 = 0 ;
T_2 V_409 = 0 ;
T_2 V_410 = 0 ;
T_2 V_411 = 0 ;
T_2 V_412 = 0 ;
V_404 = V_319 |
#ifdef F_94
V_324 |
V_325 |
#endif
V_322 |
V_323 |
V_328 |
V_326 |
V_291 |
V_321 |
V_329 |
V_320 |
V_330 ;
V_405 = V_32 |
V_31 |
V_33 ;
if ( F_217 ( V_404 , V_405 , V_315 ,
& V_409 ) < 0 )
return - V_402 ;
#ifdef F_94
if ( ( V_409 & V_32 ) )
V_409 &= ~ V_324 &
~ V_325 ;
#endif
if ( V_409 & V_33 ) {
V_406 = 0 ;
V_407 = V_35 |
V_36 |
V_63 |
V_59 |
V_55 |
V_56 |
V_57 |
V_60 |
V_61 |
V_37 |
V_38 |
V_67 ;
if ( F_217 ( V_406 , V_407 ,
V_333 ,
& V_410 ) < 0 )
return - V_402 ;
}
#ifndef F_94
if ( ! ( V_410 &
V_35 ) )
V_409 &= ~ V_32 ;
#endif
if ( ! ( V_409 & V_32 ) )
V_410 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_410 & V_55 ) {
V_409 &= ~ ( V_322 |
V_323 |
V_320 ) ;
F_190 ( V_362 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_404 = 0 ;
#ifdef F_94
V_404 |= V_308 ;
#endif
V_405 = V_413 | V_414 |
V_415 ;
if ( F_217 ( V_404 , V_405 , V_356 ,
& V_411 ) < 0 )
return - V_402 ;
V_404 = V_302 | V_303 ;
V_405 = V_62 | V_40 ;
if ( F_217 ( V_404 , V_405 , V_298 ,
& V_408 ) < 0 )
return - V_402 ;
if ( ! ( V_410 &
V_38 ) ||
! ( V_411 & V_415 ) )
V_408 &= ~ V_40 ;
V_404 = 0 ;
V_405 = V_313 ;
if ( F_217 ( V_404 , V_405 , V_309 ,
& V_412 ) < 0 )
return - V_402 ;
F_190 ( V_344 , V_399 , V_400 ) ;
if ( ( V_400 & 0x1fff ) > V_416 )
return - V_402 ;
#ifdef F_94
if ( V_400 & ( 1u << 16 ) )
return - V_402 ;
#endif
if ( ( ( V_400 >> 18 ) & 15 ) != 6 )
return - V_402 ;
V_403 -> V_417 = V_400 & 0x1fff ;
V_403 -> V_418 = F_220 ( V_29 . V_417 ) ;
V_403 -> V_419 = V_399 ;
V_403 -> V_39 = V_408 ;
V_403 -> V_30 = V_409 ;
V_403 -> V_34 = V_410 ;
V_403 -> V_420 = V_411 ;
V_403 -> V_375 = V_412 ;
V_141 =
F_218 ( V_309 ,
V_142 )
&& F_218 ( V_356 ,
V_143 ) ;
V_145 =
F_218 ( V_309 ,
V_146 )
&& F_218 ( V_356 ,
V_147 ) ;
if ( V_145 && V_421 . V_422 == 0x6 ) {
switch ( V_421 . V_423 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_145 = false ;
F_116 ( V_162 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_86 * F_221 ( int V_90 )
{
int V_424 = F_222 ( V_90 ) ;
struct V_15 * V_425 ;
struct V_86 * V_86 ;
V_425 = F_223 ( V_424 , V_426 , V_29 . V_418 ) ;
if ( ! V_425 )
return NULL ;
V_86 = F_224 ( V_425 ) ;
memset ( V_86 , 0 , V_29 . V_417 ) ;
V_86 -> V_419 = V_29 . V_419 ;
return V_86 ;
}
static struct V_86 * F_225 ( void )
{
return F_221 ( F_77 () ) ;
}
static void F_226 ( struct V_86 * V_86 )
{
F_227 ( ( unsigned long ) V_86 , V_29 . V_418 ) ;
}
static void F_228 ( struct V_89 * V_89 )
{
if ( ! V_89 -> V_86 )
return;
F_83 ( V_89 ) ;
F_226 ( V_89 -> V_86 ) ;
V_89 -> V_86 = NULL ;
}
static void F_229 ( void )
{
int V_90 ;
F_230 (cpu) {
F_226 ( F_80 ( V_213 , V_90 ) ) ;
F_80 ( V_213 , V_90 ) = NULL ;
}
}
static T_11 int F_231 ( void )
{
int V_90 ;
F_230 (cpu) {
struct V_86 * V_86 ;
V_86 = F_221 ( V_90 ) ;
if ( ! V_86 ) {
F_229 () ;
return - V_427 ;
}
F_80 ( V_213 , V_90 ) = V_86 ;
}
return 0 ;
}
static T_11 int F_232 ( void )
{
if ( F_219 ( & V_29 ) < 0 )
return - V_402 ;
if ( F_233 ( V_428 ) )
F_234 ( V_174 ) ;
if ( ! F_49 () )
V_429 = 0 ;
if ( ! F_54 () )
V_430 = 0 ;
if ( ! F_45 () ||
! F_39 () ) {
V_100 = 0 ;
V_431 = 0 ;
V_432 = 0 ;
}
if ( ! F_40 () )
V_432 = 0 ;
if ( ! F_46 () )
V_431 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_433 -> V_434 = NULL ;
if ( V_100 && ! F_37 () )
F_235 () ;
if ( ! F_47 () )
V_435 = 0 ;
if ( ! F_32 () )
V_436 = 0 ;
if ( V_436 )
V_433 -> V_434 = NULL ;
else {
V_433 -> V_437 = NULL ;
V_433 -> V_438 = NULL ;
V_433 -> V_439 = V_440 ;
}
if ( V_13 )
F_189 () ;
return F_231 () ;
}
static T_12 void F_236 ( void )
{
F_229 () ;
}
static bool F_237 ( struct V_7 * V_8 )
{
return V_441 && ! F_238 ( V_8 ) ;
}
static void F_239 ( struct V_7 * V_8 , int V_107 ,
struct V_442 * V_443 )
{
if ( ! V_441 ) {
if ( V_107 == V_444 || V_107 == V_445 )
V_443 -> V_114 &= ~ V_446 ;
V_443 -> V_447 = V_443 -> V_114 & V_446 ;
V_443 -> V_183 = 1 ;
}
F_240 ( V_8 , V_443 , V_107 ) ;
}
static void F_241 ( struct V_7 * V_8 )
{
unsigned long V_448 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_450 ] , V_450 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_451 ] , V_451 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_452 ] , V_452 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_453 ] , V_453 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_445 ] , V_445 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_444 ] , V_444 ) ;
V_72 -> V_130 . V_131 = 0 ;
F_104 ( V_72 ) ;
F_240 ( V_8 , & V_72 -> V_130 . V_449 [ V_454 ] , V_454 ) ;
V_448 = F_90 ( V_239 ) ;
V_448 &= V_240 ;
V_448 |= V_72 -> V_130 . V_237 & ~ V_240 ;
F_97 ( V_239 , V_448 ) ;
F_97 ( V_455 , ( F_90 ( V_455 ) & ~ V_456 ) |
( F_90 ( V_457 ) & V_456 ) ) ;
F_110 ( V_8 ) ;
F_239 ( V_8 , V_444 , & V_72 -> V_130 . V_449 [ V_444 ] ) ;
F_239 ( V_8 , V_445 , & V_72 -> V_130 . V_449 [ V_445 ] ) ;
F_239 ( V_8 , V_450 , & V_72 -> V_130 . V_449 [ V_450 ] ) ;
F_239 ( V_8 , V_451 , & V_72 -> V_130 . V_449 [ V_451 ] ) ;
F_239 ( V_8 , V_452 , & V_72 -> V_130 . V_449 [ V_452 ] ) ;
F_239 ( V_8 , V_453 , & V_72 -> V_130 . V_449 [ V_453 ] ) ;
F_158 ( V_458 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_459 = 0 ;
}
static void F_243 ( int V_107 , struct V_442 * V_443 )
{
const struct V_460 * V_461 = & V_116 [ V_107 ] ;
struct V_442 V_462 = * V_443 ;
V_462 . V_447 = 0x3 ;
if ( V_107 == V_444 )
V_462 . type = 0x3 ;
if ( ! V_441 ) {
V_462 . V_114 = V_462 . V_117 >> 4 ;
V_462 . V_117 = V_462 . V_117 & 0xffff0 ;
V_462 . V_119 = 0xffff ;
V_462 . V_463 = 0 ;
V_462 . V_464 = 0 ;
V_462 . V_465 = 1 ;
V_462 . V_183 = 1 ;
V_462 . V_466 = 0 ;
V_462 . V_467 = 0 ;
V_462 . type = 0x3 ;
V_462 . V_468 = 0 ;
if ( V_443 -> V_117 & 0xf )
F_116 ( V_162 L_12
L_13
L_14 , V_107 ) ;
}
F_99 ( V_461 -> V_114 , V_462 . V_114 ) ;
F_100 ( V_461 -> V_117 , V_462 . V_117 ) ;
F_100 ( V_461 -> V_119 , V_462 . V_119 ) ;
F_100 ( V_461 -> V_123 , F_244 ( & V_462 ) ) ;
}
static void F_245 ( struct V_7 * V_8 )
{
unsigned long V_448 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_454 ] , V_454 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_450 ] , V_450 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_451 ] , V_451 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_452 ] , V_452 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_453 ] , V_453 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_445 ] , V_445 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_449 [ V_444 ] , V_444 ) ;
V_72 -> V_130 . V_131 = 1 ;
if ( ! V_8 -> V_17 -> V_110 . V_469 )
F_116 ( V_162 L_15
L_16 ) ;
F_104 ( V_72 ) ;
F_97 ( V_470 , V_8 -> V_17 -> V_110 . V_469 ) ;
F_100 ( V_471 , V_472 - 1 ) ;
F_100 ( V_473 , 0x008b ) ;
V_448 = F_90 ( V_239 ) ;
V_72 -> V_130 . V_237 = V_448 ;
V_448 |= V_241 | V_242 ;
F_97 ( V_239 , V_448 ) ;
F_97 ( V_455 , F_90 ( V_455 ) | V_456 ) ;
F_110 ( V_8 ) ;
F_243 ( V_445 , & V_72 -> V_130 . V_449 [ V_445 ] ) ;
F_243 ( V_444 , & V_72 -> V_130 . V_449 [ V_444 ] ) ;
F_243 ( V_450 , & V_72 -> V_130 . V_449 [ V_450 ] ) ;
F_243 ( V_451 , & V_72 -> V_130 . V_449 [ V_451 ] ) ;
F_243 ( V_453 , & V_72 -> V_130 . V_449 [ V_453 ] ) ;
F_243 ( V_452 , & V_72 -> V_130 . V_449 [ V_452 ] ) ;
F_246 ( V_8 ) ;
}
static void F_247 ( struct V_7 * V_8 , T_3 V_173 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 = F_64 ( V_72 , V_140 ) ;
if ( ! V_73 )
return;
F_138 ( F_6 ( V_8 ) ) ;
V_8 -> V_110 . V_173 = V_173 ;
if ( V_173 & V_176 ) {
F_100 ( V_136 ,
F_92 ( V_136 ) |
V_314 ) ;
V_73 -> V_179 = V_173 ;
} else {
F_100 ( V_136 ,
F_92 ( V_136 ) &
~ V_314 ) ;
V_73 -> V_179 = V_173 & ~ V_177 ;
}
F_175 ( V_72 ) ;
}
static void F_248 ( struct V_7 * V_8 )
{
T_2 V_474 ;
F_104 ( F_6 ( V_8 ) ) ;
V_474 = F_92 ( V_473 ) ;
if ( ( V_474 & V_475 ) != V_476 ) {
F_249 ( L_17 ,
V_477 ) ;
F_100 ( V_473 ,
( V_474 & ~ V_475 )
| V_476 ) ;
}
F_247 ( V_8 , V_8 -> V_110 . V_173 | V_176 ) ;
}
static void F_250 ( struct V_7 * V_8 )
{
F_100 ( V_136 ,
F_92 ( V_136 )
& ~ V_314 ) ;
F_247 ( V_8 , V_8 -> V_110 . V_173 & ~ V_176 ) ;
}
static void F_251 ( struct V_7 * V_8 )
{
F_87 ( F_6 ( V_8 ) ) ;
if ( V_100 ) {
if ( ! F_252 ( V_8 -> V_110 . V_478 . V_479 ) )
return;
F_89 ( F_253 ( V_8 -> V_110 . V_478 . V_479 ) ) ;
}
}
static void F_155 ( struct V_7 * V_8 )
{
T_9 V_226 = V_8 -> V_110 . V_226 ;
V_8 -> V_110 . V_222 &= ~ V_226 ;
V_8 -> V_110 . V_222 |= F_90 ( V_223 ) & V_226 ;
}
static void F_254 ( struct V_7 * V_8 )
{
if ( V_100 && F_255 ( V_8 ) )
V_8 -> V_110 . V_480 = F_90 ( V_481 ) ;
F_158 ( V_482 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
}
static void F_256 ( struct V_7 * V_8 )
{
T_9 V_483 = V_8 -> V_110 . V_483 ;
V_8 -> V_110 . V_484 &= ~ V_483 ;
V_8 -> V_110 . V_484 |= F_90 ( V_455 ) & V_483 ;
}
static void F_257 ( struct V_7 * V_8 )
{
if ( ! F_157 ( V_386 ,
( unsigned long * ) & V_8 -> V_110 . V_485 ) )
return;
if ( F_255 ( V_8 ) && F_258 ( V_8 ) && ! F_128 ( V_8 ) ) {
F_101 ( V_486 , V_8 -> V_110 . V_478 . V_487 [ 0 ] ) ;
F_101 ( V_488 , V_8 -> V_110 . V_478 . V_487 [ 1 ] ) ;
F_101 ( V_489 , V_8 -> V_110 . V_478 . V_487 [ 2 ] ) ;
F_101 ( V_490 , V_8 -> V_110 . V_478 . V_487 [ 3 ] ) ;
}
}
static void F_204 ( struct V_7 * V_8 )
{
if ( F_255 ( V_8 ) && F_258 ( V_8 ) && ! F_128 ( V_8 ) ) {
V_8 -> V_110 . V_478 . V_487 [ 0 ] = F_93 ( V_486 ) ;
V_8 -> V_110 . V_478 . V_487 [ 1 ] = F_93 ( V_488 ) ;
V_8 -> V_110 . V_478 . V_487 [ 2 ] = F_93 ( V_489 ) ;
V_8 -> V_110 . V_478 . V_487 [ 3 ] = F_93 ( V_490 ) ;
}
F_158 ( V_386 ,
( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
F_158 ( V_386 ,
( unsigned long * ) & V_8 -> V_110 . V_485 ) ;
}
static void F_259 ( unsigned long * V_491 ,
unsigned long V_222 ,
struct V_7 * V_8 )
{
if ( ! F_157 ( V_482 , ( T_9 * ) & V_8 -> V_110 . V_111 ) )
F_254 ( V_8 ) ;
if ( ! ( V_222 & V_492 ) ) {
F_100 ( V_493 ,
F_92 ( V_493 ) |
( V_322 |
V_323 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_260 ( V_8 , F_261 ( V_8 ) ) ;
} else if ( ! F_255 ( V_8 ) ) {
F_100 ( V_493 ,
F_92 ( V_493 ) &
~ ( V_322 |
V_323 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_260 ( V_8 , F_261 ( V_8 ) ) ;
}
if ( ! ( V_222 & V_494 ) )
* V_491 &= ~ V_494 ;
}
static void F_262 ( struct V_7 * V_8 , unsigned long V_222 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_491 ;
V_491 = ( V_222 & ~ V_495 ) ;
if ( V_431 )
V_491 |= V_496 ;
else {
V_491 |= V_497 ;
if ( V_72 -> V_130 . V_131 && ( V_222 & V_498 ) )
F_241 ( V_8 ) ;
if ( ! V_72 -> V_130 . V_131 && ! ( V_222 & V_498 ) )
F_245 ( V_8 ) ;
}
#ifdef F_94
if ( V_8 -> V_110 . V_173 & V_177 ) {
if ( ! F_255 ( V_8 ) && ( V_222 & V_492 ) )
F_248 ( V_8 ) ;
if ( F_255 ( V_8 ) && ! ( V_222 & V_492 ) )
F_250 ( V_8 ) ;
}
#endif
if ( V_100 )
F_259 ( & V_491 , V_222 , V_8 ) ;
if ( ! V_8 -> V_132 )
V_491 |= V_224 | V_225 ;
F_97 ( V_235 , V_222 ) ;
F_97 ( V_223 , V_491 ) ;
V_8 -> V_110 . V_222 = V_222 ;
V_72 -> F_237 = F_237 ( V_8 ) ;
}
static T_3 F_253 ( unsigned long V_479 )
{
T_3 V_83 ;
V_83 = V_499 |
V_500 << V_501 ;
if ( V_432 )
V_83 |= V_502 ;
V_83 |= ( V_479 & V_503 ) ;
return V_83 ;
}
static void F_263 ( struct V_7 * V_8 , unsigned long V_480 )
{
unsigned long V_504 ;
T_3 V_83 ;
V_504 = V_480 ;
if ( V_100 ) {
V_83 = F_253 ( V_480 ) ;
F_101 ( V_505 , V_83 ) ;
V_504 = F_255 ( V_8 ) ? F_264 ( V_8 ) :
V_8 -> V_17 -> V_110 . V_506 ;
F_257 ( V_8 ) ;
}
F_251 ( V_8 ) ;
F_97 ( V_481 , V_504 ) ;
}
static int F_260 ( struct V_7 * V_8 , unsigned long V_484 )
{
unsigned long V_507 = V_484 | ( F_6 ( V_8 ) -> V_130 . V_131 ?
V_508 : V_509 ) ;
if ( V_484 & V_393 ) {
if ( ! F_188 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_510 &&
( ( V_484 & F_196 ) != F_196 ) )
return 1 ;
V_8 -> V_110 . V_484 = V_484 ;
if ( V_100 ) {
if ( ! F_255 ( V_8 ) ) {
V_507 &= ~ V_511 ;
V_507 |= V_512 ;
V_507 &= ~ V_513 ;
} else if ( ! ( V_484 & V_511 ) ) {
V_507 &= ~ V_511 ;
}
}
F_97 ( V_457 , V_484 ) ;
F_97 ( V_455 , V_507 ) ;
return 0 ;
}
static void F_242 ( struct V_7 * V_8 ,
struct V_442 * V_462 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_121 ;
if ( V_72 -> V_130 . V_131 && V_107 != V_514 ) {
* V_462 = V_72 -> V_130 . V_449 [ V_107 ] ;
if ( V_107 == V_454
|| V_462 -> V_114 == F_106 ( V_72 , V_107 ) )
return;
V_462 -> V_117 = F_107 ( V_72 , V_107 ) ;
V_462 -> V_114 = F_106 ( V_72 , V_107 ) ;
return;
}
V_462 -> V_117 = F_107 ( V_72 , V_107 ) ;
V_462 -> V_119 = F_108 ( V_72 , V_107 ) ;
V_462 -> V_114 = F_106 ( V_72 , V_107 ) ;
V_121 = F_109 ( V_72 , V_107 ) ;
V_462 -> type = V_121 & 15 ;
V_462 -> V_183 = ( V_121 >> 4 ) & 1 ;
V_462 -> V_447 = ( V_121 >> 5 ) & 3 ;
V_462 -> V_465 = ( V_121 >> 7 ) & 1 ;
V_462 -> V_468 = ( V_121 >> 12 ) & 1 ;
V_462 -> V_466 = ( V_121 >> 13 ) & 1 ;
V_462 -> V_464 = ( V_121 >> 14 ) & 1 ;
V_462 -> V_463 = ( V_121 >> 15 ) & 1 ;
V_462 -> V_467 = ( V_121 >> 16 ) & 1 ;
}
static T_3 F_265 ( struct V_7 * V_8 , int V_107 )
{
struct V_442 V_183 ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
F_242 ( V_8 , & V_183 , V_107 ) ;
return V_183 . V_117 ;
}
return F_107 ( F_6 ( V_8 ) , V_107 ) ;
}
static int F_266 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_267 ( V_8 ) )
return 0 ;
if ( ! F_128 ( V_8 )
&& ( F_268 ( V_8 ) & V_242 ) )
return 3 ;
if ( ! F_157 ( V_458 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ) {
F_158 ( V_458 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_459 = F_106 ( V_72 , V_444 ) & 3 ;
}
return V_72 -> V_459 ;
}
static T_2 F_244 ( struct V_442 * V_462 )
{
T_2 V_121 ;
if ( V_462 -> V_467 || ! V_462 -> V_465 )
V_121 = 1 << 16 ;
else {
V_121 = V_462 -> type & 15 ;
V_121 |= ( V_462 -> V_183 & 1 ) << 4 ;
V_121 |= ( V_462 -> V_447 & 3 ) << 5 ;
V_121 |= ( V_462 -> V_465 & 1 ) << 7 ;
V_121 |= ( V_462 -> V_468 & 1 ) << 12 ;
V_121 |= ( V_462 -> V_466 & 1 ) << 13 ;
V_121 |= ( V_462 -> V_464 & 1 ) << 14 ;
V_121 |= ( V_462 -> V_463 & 1 ) << 15 ;
}
return V_121 ;
}
static void F_240 ( struct V_7 * V_8 ,
struct V_442 * V_462 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
const struct V_460 * V_461 = & V_116 [ V_107 ] ;
F_104 ( V_72 ) ;
if ( V_107 == V_444 )
F_269 ( V_458 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
if ( V_72 -> V_130 . V_131 && V_107 != V_514 ) {
V_72 -> V_130 . V_449 [ V_107 ] = * V_462 ;
if ( V_107 == V_454 )
F_99 ( V_461 -> V_114 , V_462 -> V_114 ) ;
else if ( V_462 -> V_183 )
F_243 ( V_107 , & V_72 -> V_130 . V_449 [ V_107 ] ) ;
goto V_515;
}
F_97 ( V_461 -> V_117 , V_462 -> V_117 ) ;
F_100 ( V_461 -> V_119 , V_462 -> V_119 ) ;
F_99 ( V_461 -> V_114 , V_462 -> V_114 ) ;
if ( V_431 && ( V_107 != V_514 ) )
V_462 -> type |= 0x1 ;
F_100 ( V_461 -> V_123 , F_244 ( V_462 ) ) ;
V_515:
V_72 -> F_237 |= F_237 ( V_8 ) ;
}
static void F_270 ( struct V_7 * V_8 , int * V_464 , int * V_466 )
{
T_2 V_121 = F_109 ( F_6 ( V_8 ) , V_444 ) ;
* V_464 = ( V_121 >> 14 ) & 1 ;
* V_466 = ( V_121 >> 13 ) & 1 ;
}
static void F_271 ( struct V_7 * V_8 , struct V_163 * V_516 )
{
V_516 -> V_417 = F_92 ( V_517 ) ;
V_516 -> V_168 = F_90 ( V_518 ) ;
}
static void F_272 ( struct V_7 * V_8 , struct V_163 * V_516 )
{
F_100 ( V_517 , V_516 -> V_417 ) ;
F_97 ( V_518 , V_516 -> V_168 ) ;
}
static void F_273 ( struct V_7 * V_8 , struct V_163 * V_516 )
{
V_516 -> V_417 = F_92 ( V_519 ) ;
V_516 -> V_168 = F_90 ( V_520 ) ;
}
static void F_274 ( struct V_7 * V_8 , struct V_163 * V_516 )
{
F_100 ( V_519 , V_516 -> V_417 ) ;
F_97 ( V_520 , V_516 -> V_168 ) ;
}
static bool F_275 ( struct V_7 * V_8 , int V_107 )
{
struct V_442 V_462 ;
T_2 V_121 ;
F_242 ( V_8 , & V_462 , V_107 ) ;
V_462 . V_447 = 0x3 ;
if ( V_107 == V_444 )
V_462 . type = 0x3 ;
V_121 = F_244 ( & V_462 ) ;
if ( V_462 . V_117 != ( V_462 . V_114 << 4 ) )
return false ;
if ( V_462 . V_119 != 0xffff )
return false ;
if ( V_121 != 0xf3 )
return false ;
return true ;
}
static bool F_276 ( struct V_7 * V_8 )
{
struct V_442 V_521 ;
unsigned int V_522 ;
F_242 ( V_8 , & V_521 , V_444 ) ;
V_522 = V_521 . V_114 & V_446 ;
if ( V_521 . V_467 )
return false ;
if ( ~ V_521 . type & ( V_523 | V_524 ) )
return false ;
if ( ! V_521 . V_183 )
return false ;
if ( V_521 . type & V_525 ) {
if ( V_521 . V_447 > V_522 )
return false ;
} else {
if ( V_521 . V_447 != V_522 )
return false ;
}
if ( ! V_521 . V_465 )
return false ;
return true ;
}
static bool F_277 ( struct V_7 * V_8 )
{
struct V_442 V_526 ;
unsigned int V_527 ;
F_242 ( V_8 , & V_526 , V_445 ) ;
V_527 = V_526 . V_114 & V_446 ;
if ( V_526 . V_467 )
return true ;
if ( V_526 . type != 3 && V_526 . type != 7 )
return false ;
if ( ! V_526 . V_183 )
return false ;
if ( V_526 . V_447 != V_527 )
return false ;
if ( ! V_526 . V_465 )
return false ;
return true ;
}
static bool F_278 ( struct V_7 * V_8 , int V_107 )
{
struct V_442 V_462 ;
unsigned int V_528 ;
F_242 ( V_8 , & V_462 , V_107 ) ;
V_528 = V_462 . V_114 & V_446 ;
if ( V_462 . V_467 )
return true ;
if ( ! V_462 . V_183 )
return false ;
if ( ! V_462 . V_465 )
return false ;
if ( ~ V_462 . type & ( V_523 | V_525 ) ) {
if ( V_462 . V_447 < V_528 )
return false ;
}
return true ;
}
static bool F_279 ( struct V_7 * V_8 )
{
struct V_442 V_186 ;
F_242 ( V_8 , & V_186 , V_454 ) ;
if ( V_186 . V_467 )
return false ;
if ( V_186 . V_114 & V_529 )
return false ;
if ( V_186 . type != 3 && V_186 . type != 11 )
return false ;
if ( ! V_186 . V_465 )
return false ;
return true ;
}
static bool F_280 ( struct V_7 * V_8 )
{
struct V_442 V_530 ;
F_242 ( V_8 , & V_530 , V_514 ) ;
if ( V_530 . V_467 )
return true ;
if ( V_530 . V_114 & V_529 )
return false ;
if ( V_530 . type != 2 )
return false ;
if ( ! V_530 . V_465 )
return false ;
return true ;
}
static bool F_281 ( struct V_7 * V_8 )
{
struct V_442 V_521 , V_526 ;
F_242 ( V_8 , & V_521 , V_444 ) ;
F_242 ( V_8 , & V_526 , V_445 ) ;
return ( ( V_521 . V_114 & V_446 ) ==
( V_526 . V_114 & V_446 ) ) ;
}
static bool F_238 ( struct V_7 * V_8 )
{
if ( V_431 )
return true ;
if ( ! F_267 ( V_8 ) || ( F_156 ( V_8 ) & V_242 ) ) {
if ( ! F_275 ( V_8 , V_444 ) )
return false ;
if ( ! F_275 ( V_8 , V_445 ) )
return false ;
if ( ! F_275 ( V_8 , V_451 ) )
return false ;
if ( ! F_275 ( V_8 , V_450 ) )
return false ;
if ( ! F_275 ( V_8 , V_452 ) )
return false ;
if ( ! F_275 ( V_8 , V_453 ) )
return false ;
} else {
if ( ! F_281 ( V_8 ) )
return false ;
if ( ! F_276 ( V_8 ) )
return false ;
if ( ! F_277 ( V_8 ) )
return false ;
if ( ! F_278 ( V_8 , V_451 ) )
return false ;
if ( ! F_278 ( V_8 , V_450 ) )
return false ;
if ( ! F_278 ( V_8 , V_452 ) )
return false ;
if ( ! F_278 ( V_8 , V_453 ) )
return false ;
if ( ! F_279 ( V_8 ) )
return false ;
if ( ! F_280 ( V_8 ) )
return false ;
}
return true ;
}
static int F_282 ( struct V_17 * V_17 )
{
T_13 V_531 ;
T_4 V_179 = 0 ;
int V_532 , V_533 , V_108 = 0 ;
V_533 = F_283 ( & V_17 -> V_534 ) ;
V_531 = V_17 -> V_110 . V_469 >> V_18 ;
V_532 = F_284 ( V_17 , V_531 , 0 , V_416 ) ;
if ( V_532 < 0 )
goto V_515;
V_179 = V_535 + V_536 ;
V_532 = F_285 ( V_17 , V_531 ++ , & V_179 ,
V_537 , sizeof( T_4 ) ) ;
if ( V_532 < 0 )
goto V_515;
V_532 = F_284 ( V_17 , V_531 ++ , 0 , V_416 ) ;
if ( V_532 < 0 )
goto V_515;
V_532 = F_284 ( V_17 , V_531 , 0 , V_416 ) ;
if ( V_532 < 0 )
goto V_515;
V_179 = ~ 0 ;
V_532 = F_285 ( V_17 , V_531 , & V_179 ,
V_472 - 2 * V_416 - 1 ,
sizeof( T_6 ) ) ;
if ( V_532 < 0 )
goto V_515;
V_108 = 1 ;
V_515:
F_286 ( & V_17 -> V_534 , V_533 ) ;
return V_108 ;
}
static int F_287 ( struct V_17 * V_17 )
{
int V_74 , V_533 , V_532 , V_108 ;
T_14 V_538 ;
T_2 V_267 ;
if ( ! V_100 )
return 1 ;
if ( F_98 ( ! V_17 -> V_110 . V_539 ) ) {
F_67 ( V_88 L_18
L_19 ) ;
return 0 ;
}
if ( F_288 ( V_17 -> V_110 . V_540 ) )
return 1 ;
V_108 = 0 ;
V_538 = V_17 -> V_110 . V_506 >> V_18 ;
V_533 = F_283 ( & V_17 -> V_534 ) ;
V_532 = F_284 ( V_17 , V_538 , 0 , V_416 ) ;
if ( V_532 < 0 )
goto V_515;
for ( V_74 = 0 ; V_74 < V_541 ; V_74 ++ ) {
V_267 = ( V_74 << 22 ) + ( V_542 | V_543 | V_544 |
V_545 | V_546 | V_547 ) ;
V_532 = F_285 ( V_17 , V_538 ,
& V_267 , V_74 * sizeof( V_267 ) , sizeof( V_267 ) ) ;
if ( V_532 < 0 )
goto V_515;
}
V_17 -> V_110 . V_540 = true ;
V_108 = 1 ;
V_515:
F_286 ( & V_17 -> V_534 , V_533 ) ;
return V_108 ;
}
static void F_289 ( int V_107 )
{
const struct V_460 * V_461 = & V_116 [ V_107 ] ;
unsigned int V_121 ;
F_99 ( V_461 -> V_114 , 0 ) ;
F_97 ( V_461 -> V_117 , 0 ) ;
F_100 ( V_461 -> V_119 , 0xffff ) ;
V_121 = 0x93 ;
if ( V_107 == V_444 )
V_121 |= 0x08 ;
F_100 ( V_461 -> V_123 , V_121 ) ;
}
static int F_290 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_548 V_549 ;
int V_532 = 0 ;
F_291 ( & V_17 -> V_550 ) ;
if ( V_17 -> V_110 . V_551 )
goto V_515;
V_549 . V_552 = V_553 ;
V_549 . V_448 = 0 ;
V_549 . V_554 = 0xfee00000ULL ;
V_549 . V_555 = V_416 ;
V_532 = F_292 ( V_17 , & V_549 ) ;
if ( V_532 )
goto V_515;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_532 = - V_556 ;
goto V_515;
}
V_17 -> V_110 . V_551 = V_15 ;
V_515:
F_293 ( & V_17 -> V_550 ) ;
return V_532 ;
}
static int F_294 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_548 V_549 ;
int V_532 = 0 ;
F_291 ( & V_17 -> V_550 ) ;
if ( V_17 -> V_110 . V_539 )
goto V_515;
V_549 . V_552 = V_557 ;
V_549 . V_448 = 0 ;
V_549 . V_554 =
V_17 -> V_110 . V_506 ;
V_549 . V_555 = V_416 ;
V_532 = F_292 ( V_17 , & V_549 ) ;
if ( V_532 )
goto V_515;
V_15 = F_11 ( V_17 , V_17 -> V_110 . V_506 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_532 = - V_556 ;
goto V_515;
}
V_17 -> V_110 . V_539 = V_15 ;
V_515:
F_293 ( & V_17 -> V_550 ) ;
return V_532 ;
}
static void F_295 ( struct V_6 * V_72 )
{
int V_52 ;
V_72 -> V_52 = 0 ;
if ( ! V_429 )
return;
F_296 ( & V_558 ) ;
V_52 = F_297 ( V_559 , V_560 ) ;
if ( V_52 < V_560 ) {
V_72 -> V_52 = V_52 ;
F_158 ( V_52 , V_559 ) ;
}
F_298 ( & V_558 ) ;
}
static void F_299 ( struct V_6 * V_72 )
{
if ( ! V_429 )
return;
F_296 ( & V_558 ) ;
if ( V_72 -> V_52 != 0 )
F_269 ( V_72 -> V_52 , V_559 ) ;
F_298 ( & V_558 ) ;
}
static void F_300 ( unsigned long * V_268 ,
T_2 V_73 , int type )
{
int V_561 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_562 )
F_269 ( V_73 , V_268 + 0x000 / V_561 ) ;
if ( type & V_563 )
F_269 ( V_73 , V_268 + 0x800 / V_561 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_562 )
F_269 ( V_73 , V_268 + 0x400 / V_561 ) ;
if ( type & V_563 )
F_269 ( V_73 , V_268 + 0xc00 / V_561 ) ;
}
}
static void F_301 ( unsigned long * V_268 ,
T_2 V_73 , int type )
{
int V_561 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_562 )
F_158 ( V_73 , V_268 + 0x000 / V_561 ) ;
if ( type & V_563 )
F_158 ( V_73 , V_268 + 0x800 / V_561 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_562 )
F_158 ( V_73 , V_268 + 0x400 / V_561 ) ;
if ( type & V_563 )
F_158 ( V_73 , V_268 + 0xc00 / V_561 ) ;
}
}
static void F_302 ( T_2 V_73 , bool V_564 )
{
if ( ! V_564 )
F_300 ( V_273 ,
V_73 , V_562 | V_563 ) ;
F_300 ( V_272 ,
V_73 , V_562 | V_563 ) ;
}
static void F_303 ( T_2 V_73 )
{
F_301 ( V_271 ,
V_73 , V_562 ) ;
F_301 ( V_270 ,
V_73 , V_562 ) ;
}
static void F_304 ( T_2 V_73 )
{
F_300 ( V_271 ,
V_73 , V_562 ) ;
F_300 ( V_270 ,
V_73 , V_562 ) ;
}
static void F_305 ( T_2 V_73 )
{
F_300 ( V_271 ,
V_73 , V_563 ) ;
F_300 ( V_270 ,
V_73 , V_563 ) ;
}
static int F_306 ( struct V_17 * V_17 )
{
return V_436 && F_25 ( V_17 ) ;
}
static void F_307 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_532 ;
if ( F_5 ( V_4 , & V_72 -> V_1 ) )
return;
V_532 = F_1 ( & V_72 -> V_1 ) ;
F_143 ( V_565 , V_8 ) ;
#ifdef F_308
if ( ! V_532 && ( V_8 -> V_566 == V_567 ) )
V_269 -> V_568 ( F_309 ( V_8 -> V_90 ) ,
V_569 ) ;
else
#endif
F_310 ( V_8 ) ;
}
static void F_311 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_72 -> V_1 ) )
return;
F_312 ( V_8 , V_72 -> V_1 . V_5 ) ;
}
static void V_440 ( struct V_7 * V_8 )
{
return;
}
static void F_313 ( struct V_6 * V_72 )
{
T_2 V_570 , V_571 ;
unsigned long V_572 ;
struct V_163 V_516 ;
F_97 ( V_573 , F_314 () & ~ V_224 ) ;
F_97 ( V_574 , F_210 () ) ;
F_97 ( V_575 , F_315 () ) ;
F_99 ( V_576 , V_577 ) ;
#ifdef F_94
F_99 ( V_578 , 0 ) ;
F_99 ( V_579 , 0 ) ;
#else
F_99 ( V_578 , V_580 ) ;
F_99 ( V_579 , V_580 ) ;
#endif
F_99 ( V_581 , V_580 ) ;
F_99 ( V_582 , V_169 * 8 ) ;
F_316 ( & V_516 ) ;
F_97 ( V_583 , V_516 . V_168 ) ;
V_72 -> V_584 = V_516 . V_168 ;
F_97 ( V_585 , V_586 ) ;
F_190 ( V_367 , V_570 , V_571 ) ;
F_100 ( V_587 , V_570 ) ;
F_55 ( V_369 , V_572 ) ;
F_97 ( V_588 , V_572 ) ;
if ( V_29 . V_420 & V_414 ) {
F_190 ( V_374 , V_570 , V_571 ) ;
F_101 ( V_589 , V_570 | ( ( T_3 ) V_571 << 32 ) ) ;
}
}
static void F_317 ( struct V_6 * V_72 )
{
V_72 -> V_8 . V_110 . V_483 = V_590 ;
if ( V_100 )
V_72 -> V_8 . V_110 . V_483 |= V_591 ;
if ( F_111 ( & V_72 -> V_8 ) )
V_72 -> V_8 . V_110 . V_483 &=
~ F_9 ( & V_72 -> V_8 ) -> V_233 ;
F_97 ( V_592 , ~ V_72 -> V_8 . V_110 . V_483 ) ;
}
static T_2 F_318 ( struct V_6 * V_72 )
{
T_2 V_39 = V_29 . V_39 ;
if ( ! F_306 ( V_72 -> V_8 . V_17 ) )
V_39 &= ~ V_40 ;
return V_39 ;
}
static T_2 F_319 ( struct V_6 * V_72 )
{
T_2 V_593 = V_29 . V_30 ;
if ( ! F_24 ( V_72 -> V_8 . V_17 ) ) {
V_593 &= ~ V_32 ;
#ifdef F_94
V_593 |= V_325 |
V_324 ;
#endif
}
if ( ! V_100 )
V_593 |= V_323 |
V_322 |
V_320 ;
return V_593 ;
}
static T_2 F_320 ( struct V_6 * V_72 )
{
T_2 V_593 = V_29 . V_34 ;
if ( ! F_48 ( V_72 -> V_8 . V_17 ) )
V_593 &= ~ V_35 ;
if ( V_72 -> V_52 == 0 )
V_593 &= ~ V_59 ;
if ( ! V_100 ) {
V_593 &= ~ V_55 ;
V_431 = 0 ;
V_593 &= ~ V_61 ;
}
if ( ! V_431 )
V_593 &= ~ V_56 ;
if ( ! V_435 )
V_593 &= ~ V_57 ;
if ( ! F_306 ( V_72 -> V_8 . V_17 ) )
V_593 &= ~ ( V_37 |
V_38 ) ;
V_593 &= ~ V_36 ;
V_593 &= ~ V_67 ;
return V_593 ;
}
static void F_321 ( void )
{
F_322 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_323 ( struct V_6 * V_72 )
{
#ifdef F_94
unsigned long V_594 ;
#endif
int V_74 ;
F_101 ( V_595 , F_66 ( V_596 ) ) ;
F_101 ( V_597 , F_66 ( V_598 ) ) ;
if ( V_430 ) {
F_101 ( V_599 , F_66 ( V_600 ) ) ;
F_101 ( V_601 , F_66 ( V_602 ) ) ;
}
if ( F_22 () )
F_101 ( V_274 , F_66 ( V_273 ) ) ;
F_101 ( V_603 , - 1ull ) ;
F_100 ( V_604 , F_318 ( V_72 ) ) ;
F_100 ( V_493 , F_319 ( V_72 ) ) ;
if ( F_26 () ) {
F_100 ( V_605 ,
F_320 ( V_72 ) ) ;
}
if ( F_306 ( V_72 -> V_8 . V_17 ) ) {
F_101 ( V_606 , 0 ) ;
F_101 ( V_607 , 0 ) ;
F_101 ( V_608 , 0 ) ;
F_101 ( V_609 , 0 ) ;
F_99 ( V_610 , 0 ) ;
F_101 ( V_611 , V_569 ) ;
F_101 ( V_612 , F_66 ( ( & V_72 -> V_1 ) ) ) ;
}
if ( V_435 ) {
F_100 ( V_613 , V_435 ) ;
F_100 ( V_614 , V_615 ) ;
}
F_100 ( V_616 , 0 ) ;
F_100 ( V_617 , 0 ) ;
F_100 ( V_618 , 0 ) ;
F_99 ( V_193 , 0 ) ;
F_99 ( V_197 , 0 ) ;
F_313 ( V_72 ) ;
#ifdef F_94
F_55 ( V_203 , V_594 ) ;
F_97 ( V_202 , V_594 ) ;
F_55 ( V_205 , V_594 ) ;
F_97 ( V_204 , V_594 ) ;
#else
F_97 ( V_202 , 0 ) ;
F_97 ( V_204 , 0 ) ;
#endif
F_100 ( V_619 , 0 ) ;
F_100 ( V_152 , 0 ) ;
F_101 ( V_620 , F_66 ( V_72 -> V_138 . V_150 ) ) ;
F_100 ( V_151 , 0 ) ;
F_101 ( V_621 , F_66 ( V_72 -> V_138 . V_149 ) ) ;
if ( V_29 . V_375 & V_313 ) {
T_2 V_622 , V_623 ;
T_3 V_624 ;
F_190 ( V_374 , V_622 , V_623 ) ;
V_624 = V_622 | ( ( T_3 ) V_623 << 32 ) ;
F_101 ( V_376 , V_624 ) ;
V_72 -> V_8 . V_110 . V_377 = V_624 ;
}
for ( V_74 = 0 ; V_74 < V_625 ; ++ V_74 ) {
T_2 V_78 = V_76 [ V_74 ] ;
T_2 V_626 , V_627 ;
int V_628 = V_72 -> V_75 ;
if ( F_324 ( V_78 , & V_626 , & V_627 ) < 0 )
continue;
if ( F_325 ( V_78 , V_626 , V_627 ) < 0 )
continue;
V_72 -> V_77 [ V_628 ] . V_78 = V_74 ;
V_72 -> V_77 [ V_628 ] . V_179 = 0 ;
V_72 -> V_77 [ V_628 ] . V_104 = - 1ull ;
++ V_72 -> V_75 ;
}
F_100 ( V_137 , V_29 . V_420 ) ;
F_100 ( V_136 , V_29 . V_375 ) ;
F_97 ( V_228 , ~ 0UL ) ;
F_317 ( V_72 ) ;
return 0 ;
}
static void F_326 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_73 ;
V_72 -> V_130 . V_131 = 0 ;
V_72 -> V_629 = 0 ;
V_72 -> V_8 . V_110 . V_382 [ V_630 ] = F_327 () ;
F_328 ( & V_72 -> V_8 , 0 ) ;
V_73 = 0xfee00000 | V_631 ;
if ( F_329 ( & V_72 -> V_8 ) )
V_73 |= V_632 ;
F_330 ( & V_72 -> V_8 , V_73 ) ;
F_104 ( V_72 ) ;
F_289 ( V_444 ) ;
F_99 ( V_633 , 0xf000 ) ;
F_100 ( V_634 , 0xffff0000 ) ;
F_289 ( V_451 ) ;
F_289 ( V_450 ) ;
F_289 ( V_452 ) ;
F_289 ( V_453 ) ;
F_289 ( V_445 ) ;
F_99 ( V_635 , 0 ) ;
F_97 ( V_470 , 0 ) ;
F_100 ( V_471 , 0xffff ) ;
F_100 ( V_473 , 0x008b ) ;
F_99 ( V_636 , 0 ) ;
F_97 ( V_637 , 0 ) ;
F_100 ( V_638 , 0xffff ) ;
F_100 ( V_639 , 0x00082 ) ;
F_100 ( V_368 , 0 ) ;
F_97 ( V_371 , 0 ) ;
F_97 ( V_370 , 0 ) ;
F_97 ( V_239 , 0x02 ) ;
F_164 ( V_8 , 0xfff0 ) ;
F_97 ( V_520 , 0 ) ;
F_100 ( V_519 , 0xffff ) ;
F_97 ( V_518 , 0 ) ;
F_100 ( V_517 , 0xffff ) ;
F_100 ( V_640 , V_641 ) ;
F_100 ( V_244 , 0 ) ;
F_100 ( V_642 , 0 ) ;
F_101 ( V_643 , 0 ) ;
F_175 ( V_72 ) ;
F_100 ( V_264 , 0 ) ;
if ( F_23 () ) {
F_101 ( V_644 , 0 ) ;
if ( F_24 ( V_72 -> V_8 . V_17 ) )
F_101 ( V_644 ,
F_66 ( V_72 -> V_8 . V_110 . V_269 -> V_382 ) ) ;
F_100 ( V_645 , 0 ) ;
}
if ( F_48 ( V_72 -> V_8 . V_17 ) )
F_101 ( V_646 ,
F_331 ( V_72 -> V_8 . V_17 -> V_110 . V_551 ) ) ;
if ( F_306 ( V_8 -> V_17 ) )
memset ( & V_72 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_72 -> V_52 != 0 )
F_99 ( V_647 , V_72 -> V_52 ) ;
V_72 -> V_8 . V_110 . V_222 = V_648 | V_649 | V_650 ;
F_262 ( & V_72 -> V_8 , F_332 ( V_8 ) ) ;
F_260 ( & V_72 -> V_8 , 0 ) ;
F_247 ( & V_72 -> V_8 , 0 ) ;
F_150 ( & V_72 -> V_8 ) ;
F_110 ( & V_72 -> V_8 ) ;
F_87 ( V_72 ) ;
}
static bool F_333 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_302 ;
}
static bool F_334 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_303 ;
}
static int F_335 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( F_111 ( V_8 ) && F_333 ( V_8 ) )
return - V_394 ;
V_69 = F_92 ( V_493 ) ;
V_69 |= V_318 ;
F_100 ( V_493 , V_69 ) ;
return 0 ;
}
static int F_336 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () )
return F_335 ( V_8 ) ;
if ( F_92 ( V_244 ) & V_245 )
return F_335 ( V_8 ) ;
V_69 = F_92 ( V_493 ) ;
V_69 |= V_651 ;
F_100 ( V_493 , V_69 ) ;
return 0 ;
}
static void F_337 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_15 V_652 ;
int V_653 = V_8 -> V_110 . V_654 . V_148 ;
F_338 ( V_653 ) ;
++ V_8 -> V_210 . V_655 ;
if ( V_72 -> V_130 . V_131 ) {
int V_258 = 0 ;
if ( V_8 -> V_110 . V_654 . V_656 )
V_258 = V_8 -> V_110 . V_259 ;
if ( F_169 ( V_8 , V_653 , V_258 ) != V_260 )
F_143 ( V_261 , V_8 ) ;
return;
}
V_652 = V_653 | V_22 ;
if ( V_8 -> V_110 . V_654 . V_656 ) {
V_652 |= V_657 ;
F_100 ( V_262 ,
V_72 -> V_8 . V_110 . V_259 ) ;
} else
V_652 |= V_27 ;
F_100 ( V_264 , V_652 ) ;
}
static void F_339 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( F_111 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_72 -> V_629 = 1 ;
V_72 -> V_658 = 0 ;
}
++ V_8 -> V_210 . V_659 ;
V_72 -> V_660 = false ;
if ( V_72 -> V_130 . V_131 ) {
if ( F_169 ( V_8 , V_661 , 0 ) != V_260 )
F_143 ( V_261 , V_8 ) ;
return;
}
F_100 ( V_264 ,
V_662 | V_22 | V_661 ) ;
}
static bool F_340 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_629 ;
if ( F_6 ( V_8 ) -> V_660 )
return false ;
return F_92 ( V_244 ) & V_663 ;
}
static void F_341 ( struct V_7 * V_8 , bool V_664 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_72 -> V_629 != V_664 ) {
V_72 -> V_629 = V_664 ;
V_72 -> V_658 = 0 ;
}
} else {
V_72 -> V_660 = ! V_664 ;
if ( V_664 )
F_103 ( V_244 ,
V_663 ) ;
else
F_102 ( V_244 ,
V_663 ) ;
}
}
static int F_342 ( struct V_7 * V_8 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_255 )
return 0 ;
if ( F_334 ( V_8 ) ) {
F_166 ( V_8 ) ;
V_12 -> V_665 = V_666 ;
V_12 -> V_667 = V_661 |
V_662 | V_22 ;
V_8 -> V_110 . V_668 = 0 ;
F_341 ( V_8 , true ) ;
return 0 ;
}
}
if ( ! F_52 () && F_6 ( V_8 ) -> V_629 )
return 0 ;
return ! ( F_92 ( V_244 ) &
( V_247 | V_245
| V_663 ) ) ;
}
static int F_343 ( struct V_7 * V_8 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_255 )
return 0 ;
if ( F_333 ( V_8 ) ) {
F_166 ( V_8 ) ;
V_12 -> V_665 =
V_669 ;
V_12 -> V_667 = 0 ;
}
}
return ( F_90 ( V_239 ) & V_670 ) &&
! ( F_92 ( V_244 ) &
( V_245 | V_247 ) ) ;
}
static int F_344 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_108 ;
struct V_548 V_671 = {
. V_552 = V_672 ,
. V_554 = V_16 ,
. V_555 = V_416 * 3 ,
. V_448 = 0 ,
} ;
V_108 = F_345 ( V_17 , & V_671 ) ;
if ( V_108 )
return V_108 ;
V_17 -> V_110 . V_469 = V_16 ;
if ( ! F_282 ( V_17 ) )
return - V_427 ;
return 0 ;
}
static bool F_346 ( struct V_7 * V_8 , int V_673 )
{
switch ( V_673 ) {
case V_129 :
F_6 ( V_8 ) -> V_8 . V_110 . V_259 =
F_92 ( V_251 ) ;
if ( V_8 -> V_126 & V_128 )
return false ;
case V_125 :
if ( V_8 -> V_126 &
( V_674 | V_675 ) )
return false ;
case V_676 :
case V_677 :
case V_678 :
case V_26 :
case V_679 :
case V_680 :
case V_346 :
case V_681 :
return true ;
break;
}
return false ;
}
static int F_347 ( struct V_7 * V_8 ,
int V_673 , T_2 V_682 )
{
if ( ( ( V_673 == V_346 ) || ( V_673 == V_680 ) ) && V_682 == 0 ) {
if ( F_348 ( V_8 , 0 ) == V_260 ) {
if ( V_8 -> V_110 . V_683 ) {
V_8 -> V_110 . V_683 = 0 ;
return F_349 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_350 ( V_8 , V_673 ) ;
return 1 ;
}
static void F_351 ( void )
{
#if F_352 ( V_684 ) && F_352 ( F_94 )
struct V_685 V_382 = {
. V_521 = 3 ,
. V_448 = V_670 ,
} ;
F_353 ( & V_382 , 0 ) ;
#endif
}
static int F_354 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_355 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_686 * V_686 = V_8 -> V_687 ;
T_2 V_19 , V_688 , V_253 ;
unsigned long V_689 , V_250 , V_690 ;
T_2 V_691 ;
enum V_692 V_693 ;
V_691 = V_72 -> V_694 ;
V_19 = V_72 -> V_695 ;
if ( F_21 ( V_19 ) )
return F_354 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_662 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_150 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_693 = F_348 ( V_8 , V_696 ) ;
if ( V_693 != V_260 )
F_350 ( V_8 , V_26 ) ;
return 1 ;
}
V_253 = 0 ;
if ( V_19 & V_257 )
V_253 = F_92 ( V_697 ) ;
if ( ( V_691 & V_698 ) &&
! ( F_17 ( V_19 ) && ! ( V_253 & V_699 ) ) ) {
V_8 -> V_687 -> V_700 = V_701 ;
V_8 -> V_687 -> V_702 . V_703 = V_704 ;
V_8 -> V_687 -> V_702 . V_705 = 2 ;
V_8 -> V_687 -> V_702 . V_179 [ 0 ] = V_691 ;
V_8 -> V_687 -> V_702 . V_179 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_356 ( V_100 ) ;
V_689 = F_90 ( V_706 ) ;
F_357 ( V_689 , V_253 ) ;
if ( F_358 ( V_8 ) )
F_359 ( V_8 , V_689 ) ;
return F_360 ( V_8 , V_689 , V_253 , NULL , 0 ) ;
}
V_688 = V_19 & V_21 ;
if ( V_72 -> V_130 . V_131 && F_346 ( V_8 , V_688 ) )
return F_347 ( V_8 , V_688 , V_253 ) ;
switch ( V_688 ) {
case V_125 :
V_690 = F_90 ( V_706 ) ;
if ( ! ( V_8 -> V_126 &
( V_674 | V_675 ) ) ) {
V_8 -> V_110 . V_690 = V_690 | V_707 ;
F_350 ( V_8 , V_125 ) ;
return 1 ;
}
V_686 -> V_708 . V_110 . V_690 = V_690 | V_707 ;
V_686 -> V_708 . V_110 . V_709 = F_90 ( V_710 ) ;
case V_129 :
V_72 -> V_8 . V_110 . V_259 =
F_92 ( V_251 ) ;
V_686 -> V_700 = V_711 ;
V_250 = F_163 ( V_8 ) ;
V_686 -> V_708 . V_110 . V_712 = F_90 ( V_634 ) + V_250 ;
V_686 -> V_708 . V_110 . V_713 = V_688 ;
break;
default:
V_686 -> V_700 = V_714 ;
V_686 -> V_715 . V_713 = V_688 ;
V_686 -> V_715 . V_253 = V_253 ;
break;
}
return 0 ;
}
static int F_361 ( struct V_7 * V_8 )
{
++ V_8 -> V_210 . V_716 ;
return 1 ;
}
static int F_362 ( struct V_7 * V_8 )
{
V_8 -> V_687 -> V_700 = V_717 ;
return 0 ;
}
static int F_363 ( struct V_7 * V_8 )
{
unsigned long V_718 ;
int V_417 , V_719 , string ;
unsigned V_720 ;
V_718 = F_90 ( V_706 ) ;
string = ( V_718 & 16 ) != 0 ;
V_719 = ( V_718 & 8 ) != 0 ;
++ V_8 -> V_210 . V_721 ;
if ( string || V_719 )
return F_348 ( V_8 , 0 ) == V_260 ;
V_720 = V_718 >> 16 ;
V_417 = ( V_718 & 7 ) + 1 ;
F_162 ( V_8 ) ;
return F_364 ( V_8 , V_417 , V_720 ) ;
}
static void
F_365 ( struct V_7 * V_8 , unsigned char * V_722 )
{
V_722 [ 0 ] = 0x0f ;
V_722 [ 1 ] = 0x01 ;
V_722 [ 2 ] = 0xc1 ;
}
static int F_366 ( struct V_7 * V_8 , unsigned long V_723 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_724 = V_723 ;
V_723 = ( V_723 & ~ V_12 -> V_227 ) |
( V_12 -> V_230 & V_12 -> V_227 ) ;
if ( ( V_723 & F_195 ) != F_195 )
return 1 ;
if ( F_367 ( V_8 , V_723 ) )
return 1 ;
F_97 ( V_235 , V_724 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_510 &&
( ( V_723 & F_195 ) != F_195 ) )
return 1 ;
return F_367 ( V_8 , V_723 ) ;
}
}
static int F_368 ( struct V_7 * V_8 , unsigned long V_723 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_724 = V_723 ;
V_723 = ( V_723 & ~ V_12 -> V_233 ) |
( V_12 -> V_232 & V_12 -> V_233 ) ;
if ( F_369 ( V_8 , V_723 ) )
return 1 ;
F_97 ( V_457 , V_724 ) ;
return 0 ;
} else
return F_369 ( V_8 , V_723 ) ;
}
static void F_370 ( struct V_7 * V_8 )
{
if ( F_111 ( V_8 ) ) {
F_97 ( V_235 ,
F_90 ( V_235 ) & ~ V_224 ) ;
V_8 -> V_110 . V_222 &= ~ V_224 ;
} else
F_262 ( V_8 , F_151 ( V_8 , ~ V_224 ) ) ;
}
static int F_371 ( struct V_7 * V_8 )
{
unsigned long V_718 , V_723 ;
int V_725 ;
int V_380 ;
int V_726 ;
V_718 = F_90 ( V_706 ) ;
V_725 = V_718 & 15 ;
V_380 = ( V_718 >> 8 ) & 15 ;
switch ( ( V_718 >> 4 ) & 3 ) {
case 0 :
V_723 = F_372 ( V_8 , V_380 ) ;
F_373 ( V_725 , V_723 ) ;
switch ( V_725 ) {
case 0 :
V_726 = F_366 ( V_8 , V_723 ) ;
F_374 ( V_8 , V_726 ) ;
return 1 ;
case 3 :
V_726 = F_375 ( V_8 , V_723 ) ;
F_374 ( V_8 , V_726 ) ;
return 1 ;
case 4 :
V_726 = F_368 ( V_8 , V_723 ) ;
F_374 ( V_8 , V_726 ) ;
return 1 ;
case 8 : {
T_6 V_727 = F_376 ( V_8 ) ;
T_6 V_728 = F_372 ( V_8 , V_380 ) ;
V_726 = F_328 ( V_8 , V_728 ) ;
F_374 ( V_8 , V_726 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_727 <= V_728 )
return 1 ;
V_8 -> V_687 -> V_700 = V_729 ;
return 0 ;
}
}
break;
case 2 :
F_370 ( V_8 ) ;
F_373 ( 0 , F_332 ( V_8 ) ) ;
F_162 ( V_8 ) ;
F_150 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_725 ) {
case 3 :
V_723 = F_264 ( V_8 ) ;
F_377 ( V_8 , V_380 , V_723 ) ;
F_378 ( V_725 , V_723 ) ;
F_162 ( V_8 ) ;
return 1 ;
case 8 :
V_723 = F_376 ( V_8 ) ;
F_377 ( V_8 , V_380 , V_723 ) ;
F_378 ( V_725 , V_723 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_723 = ( V_718 >> V_730 ) & 0x0f ;
F_373 ( 0 , ( F_332 ( V_8 ) & ~ 0xful ) | V_723 ) ;
F_379 ( V_8 , V_723 ) ;
F_162 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_687 -> V_700 = 0 ;
F_380 ( V_8 , L_20 ,
( int ) ( V_718 >> 4 ) & 3 , V_725 ) ;
return 0 ;
}
static int F_381 ( struct V_7 * V_8 )
{
unsigned long V_718 ;
int V_731 , V_380 ;
if ( ! F_382 ( V_8 , 0 ) )
return 1 ;
V_731 = F_90 ( V_710 ) ;
if ( V_731 & V_732 ) {
if ( V_8 -> V_126 & V_675 ) {
V_8 -> V_687 -> V_708 . V_110 . V_690 = V_8 -> V_110 . V_690 ;
V_8 -> V_687 -> V_708 . V_110 . V_709 = V_731 ;
V_8 -> V_687 -> V_708 . V_110 . V_712 =
F_90 ( V_634 ) +
F_90 ( V_385 ) ;
V_8 -> V_687 -> V_708 . V_110 . V_713 = V_125 ;
V_8 -> V_687 -> V_700 = V_711 ;
return 0 ;
} else {
V_8 -> V_110 . V_709 &= ~ V_732 ;
V_8 -> V_110 . V_690 |= V_733 ;
F_97 ( V_710 , V_8 -> V_110 . V_709 ) ;
F_350 ( V_8 , V_125 ) ;
return 1 ;
}
}
V_718 = F_90 ( V_706 ) ;
V_731 = V_718 & V_734 ;
V_380 = F_383 ( V_718 ) ;
if ( V_718 & V_735 ) {
unsigned long V_723 ;
if ( ! F_384 ( V_8 , V_731 , & V_723 ) )
F_377 ( V_8 , V_380 , V_723 ) ;
} else
F_385 ( V_8 , V_731 , V_8 -> V_110 . V_382 [ V_380 ] ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static void F_386 ( struct V_7 * V_8 , unsigned long V_723 )
{
F_97 ( V_710 , V_723 ) ;
}
static int F_387 ( struct V_7 * V_8 )
{
F_388 ( V_8 ) ;
return 1 ;
}
static int F_389 ( struct V_7 * V_8 )
{
T_2 V_296 = V_8 -> V_110 . V_382 [ V_736 ] ;
T_3 V_179 ;
if ( F_198 ( V_8 , V_296 , & V_179 ) ) {
F_390 ( V_296 ) ;
F_391 ( V_8 , 0 ) ;
return 1 ;
}
F_392 ( V_296 , V_179 ) ;
V_8 -> V_110 . V_382 [ V_737 ] = V_179 & - 1u ;
V_8 -> V_110 . V_382 [ V_630 ] = ( V_179 >> 32 ) & - 1u ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_393 ( struct V_7 * V_8 )
{
struct V_372 V_73 ;
T_2 V_296 = V_8 -> V_110 . V_382 [ V_736 ] ;
T_3 V_179 = ( V_8 -> V_110 . V_382 [ V_737 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_110 . V_382 [ V_630 ] & - 1u ) << 32 ) ;
V_73 . V_179 = V_179 ;
V_73 . V_78 = V_296 ;
V_73 . V_738 = false ;
if ( F_200 ( V_8 , & V_73 ) != 0 ) {
F_394 ( V_296 , V_179 ) ;
F_391 ( V_8 , 0 ) ;
return 1 ;
}
F_395 ( V_296 , V_179 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_396 ( struct V_7 * V_8 )
{
F_143 ( V_565 , V_8 ) ;
return 1 ;
}
static int F_397 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_92 ( V_493 ) ;
V_69 &= ~ V_318 ;
F_100 ( V_493 , V_69 ) ;
F_143 ( V_565 , V_8 ) ;
++ V_8 -> V_210 . V_739 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_687 -> V_740 &&
! F_398 ( V_8 ) ) {
V_8 -> V_687 -> V_700 = V_741 ;
return 0 ;
}
return 1 ;
}
static int F_399 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
return F_349 ( V_8 ) ;
}
static int F_400 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
F_401 ( V_8 ) ;
return 1 ;
}
static int F_402 ( struct V_7 * V_8 )
{
return F_348 ( V_8 , 0 ) == V_260 ;
}
static int F_403 ( struct V_7 * V_8 )
{
unsigned long V_718 = F_90 ( V_706 ) ;
F_404 ( V_8 , V_718 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_405 ( struct V_7 * V_8 )
{
int V_726 ;
V_726 = F_406 ( V_8 ) ;
F_374 ( V_8 , V_726 ) ;
return 1 ;
}
static int F_407 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
F_408 ( V_8 ) ;
return 1 ;
}
static int F_409 ( struct V_7 * V_8 )
{
T_3 V_742 = F_410 ( V_8 ) ;
T_2 V_78 = F_372 ( V_8 , V_736 ) ;
if ( F_411 ( V_8 , V_78 , V_742 ) == 0 )
F_162 ( V_8 ) ;
return 1 ;
}
static int F_412 ( struct V_7 * V_8 )
{
if ( F_288 ( V_743 ) ) {
unsigned long V_718 = F_90 ( V_706 ) ;
int V_744 , V_290 ;
V_744 = V_718 & V_745 ;
V_290 = V_718 & V_746 ;
if ( ( V_744 == V_747 ) &&
( V_290 == V_748 ) ) {
F_413 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
}
return F_348 ( V_8 , 0 ) == V_260 ;
}
static int F_414 ( struct V_7 * V_8 )
{
unsigned long V_718 = F_90 ( V_706 ) ;
int V_4 = V_718 & 0xff ;
F_415 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_416 ( struct V_7 * V_8 )
{
unsigned long V_718 = F_90 ( V_706 ) ;
T_2 V_290 = V_718 & 0xfff ;
F_417 ( V_8 , V_290 ) ;
return 1 ;
}
static int F_418 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_718 ;
bool V_252 = false ;
T_2 V_253 = 0 ;
T_4 V_749 ;
int V_750 , type , V_751 , V_752 ;
V_751 = ( V_72 -> V_694 & V_698 ) ;
V_752 = ( V_72 -> V_694 & V_753 ) ;
type = ( V_72 -> V_694 & V_754 ) ;
V_718 = F_90 ( V_706 ) ;
V_750 = ( T_2 ) V_718 >> 30 ;
if ( V_750 == V_755 && V_751 ) {
switch ( type ) {
case V_662 :
V_8 -> V_110 . V_756 = false ;
F_341 ( V_8 , true ) ;
break;
case V_27 :
case V_657 :
F_419 ( V_8 ) ;
break;
case V_23 :
if ( V_72 -> V_694 &
V_757 ) {
V_252 = true ;
V_253 =
F_92 ( V_758 ) ;
}
case V_263 :
F_420 ( V_8 ) ;
break;
default:
break;
}
}
V_749 = V_718 ;
if ( ! V_751 || ( type != V_23 &&
type != V_27 &&
type != V_662 ) )
F_162 ( V_8 ) ;
if ( F_421 ( V_8 , V_749 ,
type == V_657 ? V_752 : - 1 , V_750 ,
V_252 , V_253 ) == V_759 ) {
V_8 -> V_687 -> V_700 = V_701 ;
V_8 -> V_687 -> V_702 . V_703 = V_760 ;
V_8 -> V_687 -> V_702 . V_705 = 0 ;
return 0 ;
}
F_97 ( V_710 , F_90 ( V_710 ) & ~ 55 ) ;
return 1 ;
}
static int F_422 ( struct V_7 * V_8 )
{
unsigned long V_718 ;
T_1 V_84 ;
T_2 V_253 ;
int V_761 ;
V_718 = F_90 ( V_706 ) ;
V_761 = ( V_718 >> 7 ) & 0x3 ;
if ( V_761 != 0x3 && V_761 != 0x1 && V_761 != 0 ) {
F_67 ( V_88 L_21 ) ;
F_67 ( V_88 L_22 ,
( long unsigned int ) F_93 ( V_762 ) ,
F_90 ( V_763 ) ) ;
F_67 ( V_88 L_23 ,
( long unsigned int ) V_718 ) ;
V_8 -> V_687 -> V_700 = V_764 ;
V_8 -> V_687 -> V_765 . V_766 = V_767 ;
return 0 ;
}
V_84 = F_93 ( V_762 ) ;
F_357 ( V_84 , V_718 ) ;
V_253 = V_718 & ( 1U << 1 ) ;
V_253 |= ( V_718 >> 3 ) & 0x1 ;
return F_360 ( V_8 , V_84 , V_253 , NULL , 0 ) ;
}
static T_3 F_423 ( T_3 V_768 , int V_769 )
{
int V_74 ;
T_3 V_104 = 0 ;
for ( V_74 = 51 ; V_74 > V_421 . V_770 ; V_74 -- )
V_104 |= ( 1ULL << V_74 ) ;
if ( V_769 > 2 )
V_104 |= 0xf8 ;
else if ( V_769 == 2 ) {
if ( V_768 & ( 1ULL << 7 ) )
V_104 |= 0x1ff000 ;
else
V_104 |= 0x78 ;
}
return V_104 ;
}
static void F_424 ( struct V_7 * V_8 , T_3 V_768 ,
int V_769 )
{
F_67 ( V_88 L_24 , V_477 , V_768 , V_769 ) ;
F_425 ( ( V_768 & 0x7 ) == 0x2 ) ;
F_425 ( ( V_768 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_425 ( ( V_768 & 0x7 ) == 0x4 ) ;
if ( ( V_768 & 0x7 ) ) {
T_3 V_771 = V_768 & F_423 ( V_768 , V_769 ) ;
if ( V_771 != 0 ) {
F_67 ( V_88 L_25 ,
V_477 , V_771 ) ;
F_425 ( 1 ) ;
}
if ( V_769 == 1 || ( V_769 == 2 && ( V_768 & ( 1ULL << 7 ) ) ) ) {
T_3 V_772 = ( V_768 & 0x38 ) >> 3 ;
if ( V_772 == 2 || V_772 == 3 ||
V_772 == 7 ) {
F_67 ( V_88 L_26 ,
V_477 , V_772 ) ;
F_425 ( 1 ) ;
}
}
}
}
static int F_426 ( struct V_7 * V_8 )
{
T_3 V_773 [ 4 ] ;
int V_774 , V_74 , V_108 ;
T_1 V_84 ;
V_84 = F_93 ( V_762 ) ;
V_108 = F_427 ( V_8 , V_84 , true ) ;
if ( F_288 ( V_108 == 1 ) )
return F_428 ( V_8 , V_84 , 0 , NULL , 0 ) ==
V_260 ;
if ( F_98 ( ! V_108 ) )
return 1 ;
F_67 ( V_88 L_27 ) ;
F_67 ( V_88 L_28 , V_84 ) ;
V_774 = F_429 ( V_8 , V_84 , V_773 ) ;
for ( V_74 = V_775 ; V_74 > V_775 - V_774 ; -- V_74 )
F_424 ( V_8 , V_773 [ V_74 - 1 ] , V_74 ) ;
V_8 -> V_687 -> V_700 = V_764 ;
V_8 -> V_687 -> V_765 . V_766 = V_776 ;
return 0 ;
}
static int F_430 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_92 ( V_493 ) ;
V_69 &= ~ V_651 ;
F_100 ( V_493 , V_69 ) ;
++ V_8 -> V_210 . V_777 ;
F_143 ( V_565 , V_8 ) ;
return 1 ;
}
static int F_431 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
enum V_692 V_726 = V_260 ;
int V_108 = 1 ;
T_2 V_778 ;
bool V_779 ;
unsigned V_780 = 130 ;
V_778 = F_92 ( V_493 ) ;
V_779 = V_778 & V_318 ;
while ( ! F_238 ( V_8 ) && V_780 -- != 0 ) {
if ( V_779 && F_343 ( V_8 ) )
return F_397 ( & V_72 -> V_8 ) ;
if ( F_157 ( V_565 , & V_8 -> V_781 ) )
return 1 ;
V_726 = F_348 ( V_8 , V_782 ) ;
if ( V_726 == V_783 ) {
V_108 = 0 ;
goto V_515;
}
if ( V_726 != V_260 ) {
V_8 -> V_687 -> V_700 = V_701 ;
V_8 -> V_687 -> V_702 . V_703 = V_760 ;
V_8 -> V_687 -> V_702 . V_705 = 0 ;
return 0 ;
}
if ( V_8 -> V_110 . V_683 ) {
V_8 -> V_110 . V_683 = 0 ;
V_108 = F_349 ( V_8 ) ;
goto V_515;
}
if ( F_432 ( V_784 ) )
goto V_515;
if ( F_433 () )
F_434 () ;
}
V_72 -> F_237 = F_237 ( V_8 ) ;
V_515:
return V_108 ;
}
static int F_435 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
F_436 ( V_8 ) ;
return 1 ;
}
static int F_437 ( struct V_7 * V_8 )
{
F_350 ( V_8 , V_26 ) ;
return 1 ;
}
static struct V_89 * F_438 ( struct V_6 * V_72 )
{
struct V_785 * V_786 ;
F_78 (item, &vmx->nested.vmcs02_pool, list)
if ( V_786 -> V_787 == V_72 -> V_13 . V_788 ) {
F_439 ( & V_786 -> V_789 , & V_72 -> V_13 . V_790 ) ;
return & V_786 -> V_791 ;
}
if ( V_72 -> V_13 . V_792 >= F_440 ( V_793 , 1 ) ) {
V_786 = F_441 ( V_72 -> V_13 . V_790 . V_794 ,
struct V_785 , V_789 ) ;
V_786 -> V_787 = V_72 -> V_13 . V_788 ;
F_439 ( & V_786 -> V_789 , & V_72 -> V_13 . V_790 ) ;
return & V_786 -> V_791 ;
}
V_786 = F_442 ( sizeof( struct V_785 ) , V_426 ) ;
if ( ! V_786 )
return NULL ;
V_786 -> V_791 . V_86 = F_225 () ;
if ( ! V_786 -> V_791 . V_86 ) {
F_443 ( V_786 ) ;
return NULL ;
}
F_68 ( & V_786 -> V_791 ) ;
V_786 -> V_787 = V_72 -> V_13 . V_788 ;
F_146 ( & ( V_786 -> V_789 ) , & ( V_72 -> V_13 . V_790 ) ) ;
V_72 -> V_13 . V_792 ++ ;
return & V_786 -> V_791 ;
}
static void F_444 ( struct V_6 * V_72 , T_1 V_787 )
{
struct V_785 * V_786 ;
F_78 (item, &vmx->nested.vmcs02_pool, list)
if ( V_786 -> V_787 == V_787 ) {
F_228 ( & V_786 -> V_791 ) ;
F_81 ( & V_786 -> V_789 ) ;
F_443 ( V_786 ) ;
V_72 -> V_13 . V_792 -- ;
return;
}
}
static void F_445 ( struct V_6 * V_72 )
{
struct V_785 * V_786 , * V_395 ;
F_215 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_72 -> V_89 != & V_786 -> V_791 )
F_228 ( & V_786 -> V_791 ) ;
F_81 ( & V_786 -> V_789 ) ;
F_443 ( V_786 ) ;
}
V_72 -> V_13 . V_792 = 0 ;
if ( V_72 -> V_89 != & V_72 -> V_795 )
F_228 ( & V_72 -> V_795 ) ;
}
static int F_446 ( struct V_7 * V_8 )
{
struct V_442 V_521 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_86 * V_796 ;
if ( ! F_447 ( V_8 , V_393 ) ||
! F_151 ( V_8 , V_498 ) ||
( F_156 ( V_8 ) & V_242 ) ) {
F_350 ( V_8 , V_26 ) ;
return 1 ;
}
F_242 ( V_8 , & V_521 , V_444 ) ;
if ( F_128 ( V_8 ) && ! V_521 . V_466 ) {
F_350 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_266 ( V_8 ) ) {
F_391 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_510 ) {
F_448 ( V_8 , V_797 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_430 ) {
V_796 = F_225 () ;
if ( ! V_796 )
return - V_427 ;
V_796 -> V_419 |= ( 1u << 31 ) ;
F_65 ( V_796 ) ;
V_72 -> V_13 . V_798 = V_796 ;
}
F_211 ( & ( V_72 -> V_13 . V_790 ) ) ;
V_72 -> V_13 . V_792 = 0 ;
V_72 -> V_13 . V_510 = true ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_449 ( struct V_7 * V_8 )
{
struct V_442 V_521 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! V_72 -> V_13 . V_510 ) {
F_350 ( V_8 , V_26 ) ;
return 0 ;
}
F_242 ( V_8 , & V_521 , V_444 ) ;
if ( ( F_156 ( V_8 ) & V_242 ) ||
( F_128 ( V_8 ) && ! V_521 . V_466 ) ) {
F_350 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_266 ( V_8 ) ) {
F_391 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_450 ( struct V_6 * V_72 )
{
T_2 V_593 ;
if ( V_430 ) {
if ( V_72 -> V_13 . V_14 != NULL ) {
F_451 ( V_72 ) ;
V_72 -> V_13 . V_799 = false ;
V_593 = F_92 ( V_605 ) ;
V_593 &= ~ V_67 ;
F_100 ( V_605 , V_593 ) ;
F_101 ( V_603 , - 1ull ) ;
}
}
F_452 ( V_72 -> V_13 . V_800 ) ;
F_13 ( V_72 -> V_13 . V_800 ) ;
}
static void F_453 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_13 . V_510 )
return;
V_72 -> V_13 . V_510 = false ;
if ( V_72 -> V_13 . V_788 != - 1ull ) {
F_450 ( V_72 ) ;
V_72 -> V_13 . V_788 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
if ( V_430 )
F_226 ( V_72 -> V_13 . V_798 ) ;
if ( V_72 -> V_13 . V_551 ) {
F_13 ( V_72 -> V_13 . V_551 ) ;
V_72 -> V_13 . V_551 = 0 ;
}
F_445 ( V_72 ) ;
}
static int F_454 ( struct V_7 * V_8 )
{
if ( ! F_449 ( V_8 ) )
return 1 ;
F_453 ( F_6 ( V_8 ) ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_455 ( struct V_7 * V_8 ,
unsigned long V_718 ,
T_2 V_801 , T_5 * V_108 )
{
int V_802 = V_801 & 3 ;
int V_803 = ( V_801 >> 7 ) & 7 ;
bool V_804 = V_801 & ( 1u << 10 ) ;
int V_805 = ( V_801 >> 15 ) & 7 ;
int V_806 = ( V_801 >> 18 ) & 0xf ;
bool V_807 = ! ( V_801 & ( 1u << 22 ) ) ;
int V_808 = ( V_801 >> 23 ) & 0xf ;
bool V_809 = ! ( V_801 & ( 1u << 27 ) ) ;
if ( V_804 ) {
F_350 ( V_8 , V_26 ) ;
return 1 ;
}
* V_108 = F_265 ( V_8 , V_805 ) ;
if ( V_809 )
* V_108 += F_372 ( V_8 , V_808 ) ;
if ( V_807 )
* V_108 += F_372 ( V_8 , V_806 ) << V_802 ;
* V_108 += V_718 ;
if ( V_803 == 1 )
* V_108 &= 0xffffffff ;
return 0 ;
}
static void F_456 ( struct V_7 * V_8 )
{
F_159 ( V_8 , F_156 ( V_8 )
& ~ ( V_810 | V_811 | V_812 |
V_813 | V_814 | V_815 ) ) ;
}
static void F_457 ( struct V_7 * V_8 )
{
F_159 ( V_8 , ( F_156 ( V_8 )
& ~ ( V_811 | V_812 | V_813 |
V_814 | V_815 ) )
| V_810 ) ;
}
static void F_448 ( struct V_7 * V_8 ,
T_2 V_816 )
{
if ( F_6 ( V_8 ) -> V_13 . V_788 == - 1ull ) {
F_457 ( V_8 ) ;
return;
}
F_159 ( V_8 , ( F_156 ( V_8 )
& ~ ( V_810 | V_811 | V_812 |
V_814 | V_815 ) )
| V_813 ) ;
F_9 ( V_8 ) -> V_816 = V_816 ;
}
static int F_458 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_787 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
struct V_817 V_818 ;
if ( ! F_449 ( V_8 ) )
return 1 ;
if ( F_455 ( V_8 , F_90 ( V_706 ) ,
F_92 ( V_819 ) , & V_80 ) )
return 1 ;
if ( F_459 ( & V_8 -> V_110 . V_820 , V_80 , & V_787 ,
sizeof( V_787 ) , & V_818 ) ) {
F_460 ( V_8 , & V_818 ) ;
return 1 ;
}
if ( ! F_461 ( V_787 , V_416 ) ) {
F_448 ( V_8 , V_821 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_787 == V_72 -> V_13 . V_788 ) {
F_450 ( V_72 ) ;
V_72 -> V_13 . V_788 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
V_15 = F_10 ( V_8 , V_787 ) ;
if ( V_15 == NULL ) {
F_143 ( V_261 , V_8 ) ;
return 1 ;
}
V_12 = F_462 ( V_15 ) ;
V_12 -> V_822 = 0 ;
F_452 ( V_15 ) ;
F_13 ( V_15 ) ;
F_444 ( V_72 , V_787 ) ;
F_162 ( V_8 ) ;
F_456 ( V_8 ) ;
return 1 ;
}
static int F_463 ( struct V_7 * V_8 )
{
return F_464 ( V_8 , true ) ;
}
static int F_465 ( struct V_7 * V_8 )
{
return F_464 ( V_8 , false ) ;
}
static inline int F_466 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_823 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_467 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_468 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_108 )
{
short V_290 = F_8 ( V_9 ) ;
char * V_113 ;
if ( V_290 < 0 )
return 0 ;
V_113 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_290 ;
switch ( F_466 ( V_9 ) ) {
case V_824 :
* V_108 = * ( ( V_825 * ) V_113 ) ;
return 1 ;
case V_826 :
* V_108 = * ( ( T_4 * ) V_113 ) ;
return 1 ;
case V_823 :
* V_108 = * ( ( T_2 * ) V_113 ) ;
return 1 ;
case V_827 :
* V_108 = * ( ( T_3 * ) V_113 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_469 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_828 ) {
short V_290 = F_8 ( V_9 ) ;
char * V_113 = ( ( char * ) F_9 ( V_8 ) ) + V_290 ;
if ( V_290 < 0 )
return false ;
switch ( F_466 ( V_9 ) ) {
case V_826 :
* ( T_4 * ) V_113 = V_828 ;
return true ;
case V_823 :
* ( T_2 * ) V_113 = V_828 ;
return true ;
case V_827 :
* ( T_3 * ) V_113 = V_828 ;
return true ;
case V_824 :
* ( V_825 * ) V_113 = V_828 ;
return true ;
default:
return false ;
}
}
static void F_451 ( struct V_6 * V_72 )
{
int V_74 ;
unsigned long V_9 ;
T_3 V_828 ;
struct V_86 * V_796 = V_72 -> V_13 . V_798 ;
unsigned long * V_229 = ( unsigned long * ) V_829 ;
int V_830 = V_831 ;
F_69 ( V_796 ) ;
for ( V_74 = 0 ; V_74 < V_830 ; V_74 ++ ) {
V_9 = V_229 [ V_74 ] ;
switch ( F_466 ( V_9 ) ) {
case V_826 :
V_828 = F_91 ( V_9 ) ;
break;
case V_823 :
V_828 = F_92 ( V_9 ) ;
break;
case V_827 :
V_828 = F_93 ( V_9 ) ;
break;
case V_824 :
V_828 = F_90 ( V_9 ) ;
break;
}
F_469 ( & V_72 -> V_8 , V_9 , V_828 ) ;
}
F_65 ( V_796 ) ;
F_69 ( V_72 -> V_89 -> V_86 ) ;
}
static void F_470 ( struct V_6 * V_72 )
{
unsigned long * V_229 [] = {
( unsigned long * ) V_829 ,
( unsigned long * ) V_832
} ;
int V_833 = F_471 ( V_229 ) ;
int V_834 [] = {
V_831 ,
V_835
} ;
int V_74 , V_836 ;
unsigned long V_9 ;
T_3 V_828 = 0 ;
struct V_86 * V_796 = V_72 -> V_13 . V_798 ;
F_69 ( V_796 ) ;
for ( V_836 = 0 ; V_836 < V_833 ; V_836 ++ ) {
for ( V_74 = 0 ; V_74 < V_834 [ V_836 ] ; V_74 ++ ) {
V_9 = V_229 [ V_836 ] [ V_74 ] ;
F_468 ( & V_72 -> V_8 , V_9 , & V_828 ) ;
switch ( F_466 ( V_9 ) ) {
case V_826 :
F_99 ( V_9 , ( T_4 ) V_828 ) ;
break;
case V_823 :
F_100 ( V_9 , ( T_2 ) V_828 ) ;
break;
case V_827 :
F_101 ( V_9 , ( T_3 ) V_828 ) ;
break;
case V_824 :
F_97 ( V_9 , ( long ) V_828 ) ;
break;
}
}
}
F_65 ( V_796 ) ;
F_69 ( V_72 -> V_89 -> V_86 ) ;
}
static int F_472 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( V_72 -> V_13 . V_788 == - 1ull ) {
F_457 ( V_8 ) ;
F_162 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_473 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_828 ;
unsigned long V_718 = F_90 ( V_706 ) ;
T_2 V_801 = F_92 ( V_819 ) ;
T_5 V_80 = 0 ;
if ( ! F_449 ( V_8 ) ||
! F_472 ( V_8 ) )
return 1 ;
V_9 = F_372 ( V_8 , ( ( ( V_801 ) >> 28 ) & 0xf ) ) ;
if ( ! F_468 ( V_8 , V_9 , & V_828 ) ) {
F_448 ( V_8 , V_837 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_801 & ( 1u << 10 ) ) {
F_377 ( V_8 , ( ( ( V_801 ) >> 3 ) & 0xf ) ,
V_828 ) ;
} else {
if ( F_455 ( V_8 , V_718 ,
V_801 , & V_80 ) )
return 1 ;
F_474 ( & V_8 -> V_110 . V_820 , V_80 ,
& V_828 , ( F_128 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_456 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_475 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_80 ;
unsigned long V_718 = F_90 ( V_706 ) ;
T_2 V_801 = F_92 ( V_819 ) ;
T_3 V_828 = 0 ;
struct V_817 V_818 ;
if ( ! F_449 ( V_8 ) ||
! F_472 ( V_8 ) )
return 1 ;
if ( V_801 & ( 1u << 10 ) )
V_828 = F_372 ( V_8 ,
( ( ( V_801 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_455 ( V_8 , V_718 ,
V_801 , & V_80 ) )
return 1 ;
if ( F_459 ( & V_8 -> V_110 . V_820 , V_80 ,
& V_828 , ( F_128 ( V_8 ) ? 8 : 4 ) , & V_818 ) ) {
F_460 ( V_8 , & V_818 ) ;
return 1 ;
}
}
V_9 = F_372 ( V_8 , ( ( ( V_801 ) >> 28 ) & 0xf ) ) ;
if ( F_467 ( V_9 ) ) {
F_448 ( V_8 ,
V_838 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( ! F_469 ( V_8 , V_9 , V_828 ) ) {
F_448 ( V_8 , V_837 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
F_456 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_476 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_787 ;
struct V_817 V_818 ;
T_2 V_593 ;
if ( ! F_449 ( V_8 ) )
return 1 ;
if ( F_455 ( V_8 , F_90 ( V_706 ) ,
F_92 ( V_819 ) , & V_80 ) )
return 1 ;
if ( F_459 ( & V_8 -> V_110 . V_820 , V_80 , & V_787 ,
sizeof( V_787 ) , & V_818 ) ) {
F_460 ( V_8 , & V_818 ) ;
return 1 ;
}
if ( ! F_461 ( V_787 , V_416 ) ) {
F_448 ( V_8 , V_839 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_788 != V_787 ) {
struct V_12 * V_840 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_787 ) ;
if ( V_15 == NULL ) {
F_457 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
V_840 = F_462 ( V_15 ) ;
if ( V_840 -> V_419 != V_348 ) {
F_452 ( V_15 ) ;
F_15 ( V_15 ) ;
F_448 ( V_8 ,
V_841 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_788 != - 1ull )
F_450 ( V_72 ) ;
V_72 -> V_13 . V_788 = V_787 ;
V_72 -> V_13 . V_14 = V_840 ;
V_72 -> V_13 . V_800 = V_15 ;
if ( V_430 ) {
V_593 = F_92 ( V_605 ) ;
V_593 |= V_67 ;
F_100 ( V_605 , V_593 ) ;
F_101 ( V_603 ,
F_66 ( V_72 -> V_13 . V_798 ) ) ;
V_72 -> V_13 . V_799 = true ;
}
}
F_456 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_477 ( struct V_7 * V_8 )
{
unsigned long V_718 = F_90 ( V_706 ) ;
T_2 V_801 = F_92 ( V_819 ) ;
T_5 V_842 ;
struct V_817 V_818 ;
if ( ! F_449 ( V_8 ) )
return 1 ;
if ( F_455 ( V_8 , V_718 ,
V_801 , & V_842 ) )
return 1 ;
if ( F_474 ( & V_8 -> V_110 . V_820 , V_842 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_788 ,
sizeof( T_3 ) , & V_818 ) ) {
F_460 ( V_8 , & V_818 ) ;
return 1 ;
}
F_456 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static bool F_478 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_718 ;
T_1 V_843 , V_844 ;
unsigned int V_720 ;
int V_417 ;
T_6 V_845 ;
if ( F_57 ( V_12 , V_327 ) )
return 1 ;
if ( ! F_57 ( V_12 , V_328 ) )
return 0 ;
V_718 = F_90 ( V_706 ) ;
V_720 = V_718 >> 16 ;
V_417 = ( V_718 & 7 ) + 1 ;
V_844 = ( T_1 ) - 1 ;
V_845 = - 1 ;
while ( V_417 > 0 ) {
if ( V_720 < 0x8000 )
V_843 = V_12 -> V_846 ;
else if ( V_720 < 0x10000 )
V_843 = V_12 -> V_847 ;
else
return 1 ;
V_843 += ( V_720 & 0x7fff ) / 8 ;
if ( V_844 != V_843 )
if ( F_479 ( V_8 -> V_17 , V_843 , & V_845 , 1 ) )
return 1 ;
if ( V_845 & ( 1 << ( V_720 & 7 ) ) )
return 1 ;
V_720 ++ ;
V_417 -- ;
V_844 = V_843 ;
}
return 0 ;
}
static bool F_480 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_700 )
{
T_2 V_342 = V_8 -> V_110 . V_382 [ V_736 ] ;
T_1 V_843 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_843 = V_12 -> V_268 ;
if ( V_700 == V_848 )
V_843 += 2048 ;
if ( V_342 >= 0xc0000000 ) {
V_342 -= 0xc0000000 ;
V_843 += 1024 ;
}
if ( V_342 < 1024 * 8 ) {
unsigned char V_845 ;
if ( F_479 ( V_8 -> V_17 , V_843 + V_342 / 8 , & V_845 , 1 ) )
return 1 ;
return 1 & ( V_845 >> ( V_342 & 7 ) ) ;
} else
return 1 ;
}
static bool F_481 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_718 = F_90 ( V_706 ) ;
int V_725 = V_718 & 15 ;
int V_380 = ( V_718 >> 8 ) & 15 ;
unsigned long V_723 = F_372 ( V_8 , V_380 ) ;
switch ( ( V_718 >> 4 ) & 3 ) {
case 0 :
switch ( V_725 ) {
case 0 :
if ( V_12 -> V_227 &
( V_723 ^ V_12 -> V_231 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_849 >= 1 &&
V_12 -> V_850 == V_723 ) ||
( V_12 -> V_849 >= 2 &&
V_12 -> V_851 == V_723 ) ||
( V_12 -> V_849 >= 3 &&
V_12 -> V_852 == V_723 ) ||
( V_12 -> V_849 >= 4 &&
V_12 -> V_853 == V_723 ) )
return 0 ;
if ( F_57 ( V_12 , V_322 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_233 &
( V_12 -> V_234 ^ V_723 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_324 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_12 -> V_227 & V_224 ) &&
( V_12 -> V_231 & V_224 ) )
return 1 ;
break;
case 1 :
switch ( V_725 ) {
case 3 :
if ( V_12 -> V_69 &
V_323 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_325 )
return 1 ;
break;
}
break;
case 3 :
if ( V_12 -> V_227 & 0xe &
( V_723 ^ V_12 -> V_231 ) )
return 1 ;
if ( ( V_12 -> V_227 & 0x1 ) &&
! ( V_12 -> V_231 & 0x1 ) &&
( V_723 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_482 ( struct V_7 * V_8 )
{
T_2 V_19 = F_92 ( V_854 ) ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_700 = V_72 -> V_700 ;
if ( V_72 -> V_13 . V_255 )
return 0 ;
if ( F_98 ( V_72 -> V_855 ) ) {
F_483 ( L_29 , V_477 ,
F_92 ( V_103 ) ) ;
return 1 ;
}
switch ( V_700 ) {
case V_666 :
if ( ! F_60 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_100 ;
return V_12 -> V_133 &
( 1u << ( V_19 & V_21 ) ) ;
case V_669 :
return 0 ;
case V_856 :
return 1 ;
case V_857 :
return F_57 ( V_12 , V_318 ) ;
case V_858 :
return F_57 ( V_12 , V_651 ) ;
case V_859 :
return 1 ;
case V_860 :
return 1 ;
case V_861 :
return F_57 ( V_12 , V_319 ) ;
case V_862 :
return 1 ;
case V_863 :
return F_57 ( V_12 , V_320 ) ;
case V_864 :
return F_57 ( V_12 , V_330 ) ;
case V_865 :
return F_57 ( V_12 , V_331 ) ;
case V_866 : case V_867 :
case V_868 : case V_869 :
case V_870 : case V_871 :
case V_872 : case V_873 :
case V_874 : case V_875 :
return 1 ;
case V_876 :
return F_481 ( V_8 , V_12 ) ;
case V_877 :
return F_57 ( V_12 , V_326 ) ;
case V_878 :
return F_478 ( V_8 , V_12 ) ;
case V_879 :
case V_848 :
return F_480 ( V_8 , V_12 , V_700 ) ;
case V_880 :
return 1 ;
case V_881 :
return F_57 ( V_12 , V_321 ) ;
case V_882 :
return F_57 ( V_12 , V_329 ) ;
case V_883 :
return F_57 ( V_12 , V_332 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_884 :
return 0 ;
case V_885 :
return 1 ;
case V_886 :
return F_58 ( V_12 ,
V_35 ) ;
case V_767 :
case V_776 :
return 0 ;
case V_887 :
return V_12 -> V_71 &
V_304 ;
case V_888 :
return F_58 ( V_12 , V_63 ) ;
case V_889 :
return 1 ;
default:
return 1 ;
}
}
static void F_484 ( struct V_7 * V_8 , T_3 * V_890 , T_3 * V_891 )
{
* V_890 = F_90 ( V_706 ) ;
* V_891 = F_92 ( V_854 ) ;
}
static int F_485 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_700 = V_72 -> V_700 ;
T_2 V_892 = V_72 -> V_694 ;
if ( V_72 -> F_237 )
return F_431 ( V_8 ) ;
if ( V_72 -> V_13 . V_255 )
F_143 ( V_565 , V_8 ) ;
if ( ! F_111 ( V_8 ) && ( V_700 == V_868 ||
V_700 == V_872 ) )
V_72 -> V_13 . V_255 = 1 ;
else
V_72 -> V_13 . V_255 = 0 ;
if ( F_111 ( V_8 ) && F_482 ( V_8 ) ) {
F_166 ( V_8 ) ;
return 1 ;
}
if ( V_700 & V_893 ) {
V_8 -> V_687 -> V_700 = V_894 ;
V_8 -> V_687 -> V_895 . V_896
= V_700 ;
return 0 ;
}
if ( F_98 ( V_72 -> V_855 ) ) {
V_8 -> V_687 -> V_700 = V_894 ;
V_8 -> V_687 -> V_895 . V_896
= F_92 ( V_103 ) ;
return 0 ;
}
if ( ( V_892 & V_698 ) &&
( V_700 != V_666 &&
V_700 != V_767 &&
V_700 != V_859 ) ) {
V_8 -> V_687 -> V_700 = V_701 ;
V_8 -> V_687 -> V_702 . V_703 = V_897 ;
V_8 -> V_687 -> V_702 . V_705 = 2 ;
V_8 -> V_687 -> V_702 . V_179 [ 0 ] = V_892 ;
V_8 -> V_687 -> V_702 . V_179 [ 1 ] = V_700 ;
return 0 ;
}
if ( F_98 ( ! F_52 () && V_72 -> V_629 &&
! ( F_111 ( V_8 ) && F_59 (
F_9 ( V_8 ) , V_8 ) ) ) ) {
if ( F_343 ( V_8 ) ) {
V_72 -> V_629 = 0 ;
} else if ( V_72 -> V_658 > 1000000000LL &&
V_8 -> V_110 . V_668 ) {
F_67 ( V_162 L_30
L_31 ,
V_477 , V_8 -> V_898 ) ;
V_72 -> V_629 = 0 ;
}
}
if ( V_700 < V_899
&& V_900 [ V_700 ] )
return V_900 [ V_700 ] ( V_8 ) ;
else {
V_8 -> V_687 -> V_700 = V_764 ;
V_8 -> V_687 -> V_765 . V_766 = V_700 ;
}
return 0 ;
}
static void V_434 ( struct V_7 * V_8 , int V_901 , int V_902 )
{
if ( V_902 == - 1 || V_901 < V_902 ) {
F_100 ( V_645 , 0 ) ;
return;
}
F_100 ( V_645 , V_902 ) ;
}
static void F_486 ( struct V_7 * V_8 , bool V_903 )
{
T_2 V_904 ;
if ( ! F_28 () ||
! F_306 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_904 = F_92 ( V_605 ) ;
if ( V_903 ) {
V_904 &= ~ V_35 ;
V_904 |= V_36 ;
} else {
V_904 &= ~ V_36 ;
V_904 |= V_35 ;
}
F_100 ( V_605 , V_904 ) ;
F_173 ( V_8 ) ;
}
static void F_487 ( struct V_17 * V_17 , int V_905 )
{
T_4 V_906 ;
T_6 V_391 ;
if ( ! F_306 ( V_17 ) )
return;
if ( V_905 == - 1 )
V_905 = 0 ;
V_906 = F_91 ( V_610 ) ;
V_391 = V_906 >> 8 ;
if ( V_905 != V_391 ) {
V_906 &= 0xff ;
V_906 |= V_905 << 8 ;
F_99 ( V_610 , V_906 ) ;
}
}
static void F_488 ( int V_4 )
{
T_4 V_906 ;
T_6 V_391 ;
V_906 = F_91 ( V_610 ) ;
V_391 = ( T_6 ) V_906 & 0xff ;
if ( ( T_6 ) V_4 != V_391 ) {
V_906 &= ~ 0xff ;
V_906 |= ( T_6 ) V_4 ;
F_99 ( V_610 , V_906 ) ;
}
}
static void F_489 ( struct V_7 * V_8 , int V_907 )
{
if ( V_907 == - 1 )
return;
F_488 ( V_907 ) ;
}
static void F_490 ( struct V_7 * V_8 , T_3 * V_908 )
{
if ( ! F_306 ( V_8 -> V_17 ) )
return;
F_101 ( V_606 , V_908 [ 0 ] ) ;
F_101 ( V_607 , V_908 [ 1 ] ) ;
F_101 ( V_608 , V_908 [ 2 ] ) ;
F_101 ( V_609 , V_908 [ 3 ] ) ;
}
static void F_491 ( struct V_6 * V_72 )
{
T_2 V_695 ;
if ( ! ( V_72 -> V_700 == V_884
|| V_72 -> V_700 == V_666 ) )
return;
V_72 -> V_695 = F_92 ( V_854 ) ;
V_695 = V_72 -> V_695 ;
if ( F_21 ( V_695 ) )
F_351 () ;
if ( ( V_695 & V_20 ) == V_662 &&
( V_695 & V_22 ) ) {
F_492 ( & V_72 -> V_8 ) ;
asm("int $2");
F_493 ( & V_72 -> V_8 ) ;
}
}
static void F_494 ( struct V_7 * V_8 )
{
T_2 V_695 = F_92 ( V_854 ) ;
if ( ( V_695 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_135 ;
T_16 * V_909 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
#ifdef F_94
unsigned long V_267 ;
#endif
V_4 = V_695 & V_21 ;
V_909 = ( T_16 * ) V_72 -> V_584 + V_4 ;
V_135 = F_495 ( * V_909 ) ;
asm volatile(
#ifdef F_94
"mov %%" _ASM_SP ", %[sp]\n\t"
"and $0xfffffffffffffff0, %%" _ASM_SP "\n\t"
"push $%c[ss]\n\t"
"push %[sp]\n\t"
#endif
"pushf\n\t"
"orl $0x200, (%%" _ASM_SP ")\n\t"
__ASM_SIZE(push) " $%c[cs]\n\t"
"call *%[entry]\n\t"
:
#ifdef F_94
[sp]"=&r"(tmp)
#endif
:
[entry]"r"(entry),
[ss]"i"(__KERNEL_DS),
[cs]"i"(__KERNEL_CS)
);
} else
F_147 () ;
}
static void F_496 ( struct V_6 * V_72 )
{
T_2 V_695 ;
bool V_910 ;
T_6 V_4 ;
bool V_911 ;
V_911 = V_72 -> V_694 & V_698 ;
if ( F_52 () ) {
if ( V_72 -> V_660 )
return;
V_695 = F_92 ( V_854 ) ;
V_910 = ( V_695 & V_912 ) != 0 ;
V_4 = V_695 & V_21 ;
if ( ( V_695 & V_22 ) && V_910 &&
V_4 != V_679 && ! V_911 )
F_103 ( V_244 ,
V_663 ) ;
else
V_72 -> V_660 =
! ( F_92 ( V_244 )
& V_663 ) ;
} else if ( F_98 ( V_72 -> V_629 ) )
V_72 -> V_658 +=
F_497 ( F_498 ( F_499 () , V_72 -> V_913 ) ) ;
}
static void F_500 ( struct V_7 * V_8 ,
T_2 V_694 ,
int V_914 ,
int V_915 )
{
T_6 V_4 ;
int type ;
bool V_911 ;
V_911 = V_694 & V_698 ;
V_8 -> V_110 . V_756 = false ;
F_420 ( V_8 ) ;
F_419 ( V_8 ) ;
if ( ! V_911 )
return;
F_143 ( V_565 , V_8 ) ;
V_4 = V_694 & V_753 ;
type = V_694 & V_754 ;
switch ( type ) {
case V_662 :
V_8 -> V_110 . V_756 = true ;
F_341 ( V_8 , false ) ;
break;
case V_263 :
V_8 -> V_110 . V_259 = F_92 ( V_914 ) ;
case V_23 :
if ( V_694 & V_757 ) {
T_2 V_726 = F_92 ( V_915 ) ;
F_194 ( V_8 , V_4 , V_726 ) ;
} else
F_350 ( V_8 , V_4 ) ;
break;
case V_657 :
V_8 -> V_110 . V_259 = F_92 ( V_914 ) ;
case V_27 :
F_501 ( V_8 , V_4 , type == V_657 ) ;
break;
default:
break;
}
}
static void F_502 ( struct V_6 * V_72 )
{
F_500 ( & V_72 -> V_8 , V_72 -> V_694 ,
V_251 ,
V_758 ) ;
}
static void F_503 ( struct V_7 * V_8 )
{
F_500 ( V_8 ,
F_92 ( V_264 ) ,
V_262 ,
V_256 ) ;
F_100 ( V_264 , 0 ) ;
}
static void F_504 ( struct V_6 * V_72 )
{
int V_74 , V_916 ;
struct V_917 * V_918 ;
V_918 = F_505 ( & V_916 ) ;
if ( ! V_918 )
return;
for ( V_74 = 0 ; V_74 < V_916 ; V_74 ++ )
if ( V_918 [ V_74 ] . V_150 == V_918 [ V_74 ] . V_149 )
F_113 ( V_72 , V_918 [ V_74 ] . V_73 ) ;
else
F_115 ( V_72 , V_918 [ V_74 ] . V_73 , V_918 [ V_74 ] . V_149 ,
V_918 [ V_74 ] . V_150 ) ;
}
static void T_17 F_506 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_919 ;
if ( F_98 ( ! F_52 () && V_72 -> V_629 ) )
V_72 -> V_913 = F_499 () ;
if ( V_72 -> F_237 )
return;
if ( V_72 -> V_13 . V_799 ) {
F_470 ( V_72 ) ;
V_72 -> V_13 . V_799 = false ;
}
if ( F_157 ( V_381 , ( unsigned long * ) & V_8 -> V_110 . V_485 ) )
F_97 ( V_383 , V_8 -> V_110 . V_382 [ V_381 ] ) ;
if ( F_157 ( V_384 , ( unsigned long * ) & V_8 -> V_110 . V_485 ) )
F_97 ( V_385 , V_8 -> V_110 . V_382 [ V_384 ] ) ;
if ( V_8 -> V_126 & V_674 )
F_161 ( V_8 , 0 ) ;
F_504 ( V_72 ) ;
V_919 = F_507 () ;
V_72 -> V_920 = V_72 -> V_89 -> V_91 ;
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
#ifdef F_94
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
#ifdef F_94
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
#ifdef F_94
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
#ifdef F_94
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_919 )
F_508 ( V_919 ) ;
#ifndef F_94
F_134 ( V_198 , V_921 ) ;
F_134 ( V_200 , V_921 ) ;
#endif
V_8 -> V_110 . V_111 = ~ ( ( 1 << V_384 ) | ( 1 << V_381 )
| ( 1 << V_238 )
| ( 1 << V_458 )
| ( 1 << V_386 )
| ( 1 << V_112 )
| ( 1 << V_482 ) ) ;
V_8 -> V_110 . V_485 = 0 ;
V_72 -> V_694 = F_92 ( V_922 ) ;
V_72 -> V_89 -> V_91 = 1 ;
V_72 -> V_700 = F_92 ( V_923 ) ;
F_509 ( V_72 -> V_700 , V_8 , V_924 ) ;
F_491 ( V_72 ) ;
F_496 ( V_72 ) ;
F_502 ( V_72 ) ;
}
static void F_510 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_299 ( V_72 ) ;
F_453 ( V_72 ) ;
F_228 ( V_72 -> V_89 ) ;
F_443 ( V_72 -> V_77 ) ;
F_511 ( V_8 ) ;
F_512 ( V_925 , V_72 ) ;
}
static struct V_7 * F_513 ( struct V_17 * V_17 , unsigned int V_926 )
{
int V_726 ;
struct V_6 * V_72 = F_514 ( V_925 , V_426 ) ;
int V_90 ;
if ( ! V_72 )
return F_515 ( - V_427 ) ;
F_295 ( V_72 ) ;
V_726 = F_516 ( & V_72 -> V_8 , V_17 , V_926 ) ;
if ( V_726 )
goto V_927;
V_72 -> V_77 = F_442 ( V_416 , V_426 ) ;
V_726 = - V_427 ;
if ( ! V_72 -> V_77 ) {
goto V_928;
}
V_72 -> V_89 = & V_72 -> V_795 ;
V_72 -> V_89 -> V_86 = F_225 () ;
if ( ! V_72 -> V_89 -> V_86 )
goto V_929;
if ( ! V_214 )
F_142 ( F_66 ( F_80 ( V_213 , F_77 () ) ) ) ;
F_68 ( V_72 -> V_89 ) ;
if ( ! V_214 )
F_149 () ;
V_90 = F_517 () ;
F_141 ( & V_72 -> V_8 , V_90 ) ;
V_72 -> V_8 . V_90 = V_90 ;
V_726 = F_323 ( V_72 ) ;
F_148 ( & V_72 -> V_8 ) ;
F_518 () ;
if ( V_726 )
goto F_226;
if ( F_48 ( V_17 ) ) {
V_726 = F_290 ( V_17 ) ;
if ( V_726 )
goto F_226;
}
if ( V_100 ) {
if ( ! V_17 -> V_110 . V_506 )
V_17 -> V_110 . V_506 =
V_930 ;
V_726 = - V_427 ;
if ( F_294 ( V_17 ) != 0 )
goto F_226;
if ( ! F_287 ( V_17 ) )
goto F_226;
}
V_72 -> V_13 . V_788 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
return & V_72 -> V_8 ;
F_226:
F_228 ( V_72 -> V_89 ) ;
V_929:
F_443 ( V_72 -> V_77 ) ;
V_928:
F_511 ( & V_72 -> V_8 ) ;
V_927:
F_299 ( V_72 ) ;
F_512 ( V_925 , V_72 ) ;
return F_515 ( V_726 ) ;
}
static void T_11 F_519 ( void * V_931 )
{
struct V_29 V_403 ;
* ( int * ) V_931 = 0 ;
if ( F_219 ( & V_403 ) < 0 )
* ( int * ) V_931 = - V_402 ;
if ( memcmp ( & V_29 , & V_403 , sizeof( struct V_29 ) ) != 0 ) {
F_67 ( V_88 L_32 ,
F_520 () ) ;
* ( int * ) V_931 = - V_402 ;
}
}
static int F_521 ( void )
{
return V_500 + 1 ;
}
static T_3 F_522 ( struct V_7 * V_8 , T_13 V_932 , bool V_933 )
{
T_3 V_108 ;
if ( V_933 )
V_108 = V_934 << V_935 ;
else if ( V_8 -> V_17 -> V_110 . V_936 &&
! ( V_8 -> V_17 -> V_110 . V_937 & V_938 ) )
V_108 = F_523 ( V_8 , V_932 ) <<
V_935 ;
else
V_108 = ( V_939 << V_935 )
| V_940 ;
return V_108 ;
}
static int F_524 ( void )
{
if ( V_100 && ! F_38 () )
return V_941 ;
else
return V_942 ;
}
static void F_525 ( struct V_7 * V_8 )
{
struct V_294 * V_295 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_593 ;
V_72 -> V_279 = false ;
if ( F_170 () ) {
V_593 = F_92 ( V_605 ) ;
if ( V_593 & V_60 ) {
V_295 = F_187 ( V_8 , 0x80000001 , 0 ) ;
if ( V_295 && ( V_295 -> V_943 & V_68 ( V_944 ) ) )
V_72 -> V_279 = true ;
else {
V_593 &= ~ V_60 ;
F_100 ( V_605 ,
V_593 ) ;
}
}
}
V_295 = F_187 ( V_8 , 0x7 , 0 ) ;
if ( F_171 () &&
V_295 && ( V_295 -> V_945 & V_68 ( V_946 ) ) &&
F_526 ( V_8 ) ) {
V_593 = F_92 ( V_605 ) ;
V_593 |= V_61 ;
F_100 ( V_605 ,
V_593 ) ;
} else {
if ( F_26 () ) {
V_593 = F_92 ( V_605 ) ;
V_593 &= ~ V_61 ;
F_100 ( V_605 ,
V_593 ) ;
}
if ( V_295 )
V_295 -> V_945 &= ~ V_68 ( V_946 ) ;
}
}
static void F_527 ( T_2 V_947 , struct V_294 * V_135 )
{
if ( V_947 == 1 && V_13 )
V_135 -> V_296 |= V_68 ( V_297 ) ;
}
static void F_528 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_593 ;
F_99 ( V_948 , V_12 -> V_949 ) ;
F_99 ( V_633 , V_12 -> V_950 ) ;
F_99 ( V_951 , V_12 -> V_952 ) ;
F_99 ( V_953 , V_12 -> V_954 ) ;
F_99 ( V_955 , V_12 -> V_956 ) ;
F_99 ( V_957 , V_12 -> V_958 ) ;
F_99 ( V_636 , V_12 -> V_959 ) ;
F_99 ( V_635 , V_12 -> V_960 ) ;
F_100 ( V_961 , V_12 -> V_962 ) ;
F_100 ( V_963 , V_12 -> V_964 ) ;
F_100 ( V_965 , V_12 -> V_966 ) ;
F_100 ( V_967 , V_12 -> V_968 ) ;
F_100 ( V_969 , V_12 -> V_970 ) ;
F_100 ( V_971 , V_12 -> V_972 ) ;
F_100 ( V_638 , V_12 -> V_973 ) ;
F_100 ( V_471 , V_12 -> V_974 ) ;
F_100 ( V_519 , V_12 -> V_975 ) ;
F_100 ( V_517 , V_12 -> V_976 ) ;
F_100 ( V_977 , V_12 -> V_978 ) ;
F_100 ( V_979 , V_12 -> V_980 ) ;
F_100 ( V_981 , V_12 -> V_982 ) ;
F_100 ( V_983 , V_12 -> V_984 ) ;
F_100 ( V_985 , V_12 -> V_986 ) ;
F_100 ( V_987 , V_12 -> V_988 ) ;
F_100 ( V_639 , V_12 -> V_989 ) ;
F_100 ( V_473 , V_12 -> V_990 ) ;
F_97 ( V_991 , V_12 -> V_992 ) ;
F_97 ( V_634 , V_12 -> V_993 ) ;
F_97 ( V_994 , V_12 -> V_995 ) ;
F_97 ( V_996 , V_12 -> V_997 ) ;
F_97 ( V_364 , V_12 -> V_998 ) ;
F_97 ( V_365 , V_12 -> V_999 ) ;
F_97 ( V_637 , V_12 -> V_1000 ) ;
F_97 ( V_470 , V_12 -> V_1001 ) ;
F_97 ( V_520 , V_12 -> V_1002 ) ;
F_97 ( V_518 , V_12 -> V_1003 ) ;
F_101 ( V_643 , V_12 -> V_1004 ) ;
F_100 ( V_264 ,
V_12 -> V_1005 ) ;
F_100 ( V_256 ,
V_12 -> V_1006 ) ;
F_100 ( V_262 ,
V_12 -> V_1007 ) ;
F_100 ( V_244 ,
V_12 -> V_1008 ) ;
F_100 ( V_368 , V_12 -> V_1009 ) ;
F_385 ( V_8 , 7 , V_12 -> V_1010 ) ;
F_97 ( V_239 , V_12 -> V_1011 ) ;
F_97 ( V_642 ,
V_12 -> V_1012 ) ;
F_97 ( V_371 , V_12 -> V_1013 ) ;
F_97 ( V_370 , V_12 -> V_1014 ) ;
F_101 ( V_603 , - 1ull ) ;
F_100 ( V_604 ,
( V_29 . V_39 |
V_12 -> V_71 ) ) ;
if ( V_12 -> V_71 & V_304 )
F_100 ( V_1015 ,
V_12 -> V_1016 ) ;
F_100 ( V_616 ,
V_100 ? V_12 -> V_1017 : 0 ) ;
F_100 ( V_617 ,
V_100 ? V_12 -> V_1018 : 0 ) ;
if ( F_26 () ) {
T_2 V_593 = F_320 ( V_72 ) ;
if ( ! V_72 -> V_279 )
V_593 &= ~ V_60 ;
V_593 &= ~ V_35 ;
if ( F_57 ( V_12 ,
V_33 ) )
V_593 |= V_12 -> V_70 ;
if ( V_593 & V_35 ) {
if ( V_72 -> V_13 . V_551 )
F_13 ( V_72 -> V_13 . V_551 ) ;
V_72 -> V_13 . V_551 =
F_10 ( V_8 , V_12 -> V_1019 ) ;
if ( ! V_72 -> V_13 . V_551 )
V_593 &=
~ V_35 ;
else
F_101 ( V_646 ,
F_331 ( V_72 -> V_13 . V_551 ) ) ;
}
F_100 ( V_605 , V_593 ) ;
}
F_313 ( V_72 ) ;
V_72 -> V_1020 = 0 ;
V_593 = F_319 ( V_72 ) ;
V_593 &= ~ V_318 ;
V_593 &= ~ V_651 ;
V_593 &= ~ V_32 ;
V_593 |= V_12 -> V_69 ;
V_593 &= ~ V_31 ;
V_593 &= ~ V_328 ;
V_593 |= V_327 ;
F_100 ( V_493 , V_593 ) ;
F_110 ( V_8 ) ;
V_8 -> V_110 . V_226 &= ~ V_12 -> V_227 ;
F_97 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
F_100 ( V_137 ,
V_12 -> V_1021 | V_29 . V_420 ) ;
F_100 ( V_136 , V_12 -> V_1022 |
( V_29 . V_375 & ~ V_314 ) ) ;
if ( V_12 -> V_1022 & V_313 )
F_101 ( V_376 , V_12 -> V_1023 ) ;
else if ( V_29 . V_375 & V_313 )
F_101 ( V_376 , V_72 -> V_8 . V_110 . V_377 ) ;
F_317 ( V_72 ) ;
if ( V_12 -> V_69 & V_291 )
F_101 ( V_283 ,
V_72 -> V_13 . V_284 + V_12 -> V_282 ) ;
else
F_101 ( V_283 , V_72 -> V_13 . V_284 ) ;
if ( V_429 ) {
F_99 ( V_647 , V_72 -> V_52 ) ;
F_251 ( V_8 ) ;
}
if ( V_12 -> V_1022 & V_142 )
V_8 -> V_110 . V_173 = V_12 -> V_1024 ;
else if ( V_12 -> V_1022 & V_314 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_247 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_262 ( V_8 , V_12 -> V_230 ) ;
F_97 ( V_235 , F_152 ( V_12 ) ) ;
F_260 ( V_8 , V_12 -> V_232 ) ;
F_97 ( V_457 , F_153 ( V_12 ) ) ;
F_375 ( V_8 , V_12 -> V_504 ) ;
F_246 ( V_8 ) ;
F_377 ( V_8 , V_381 , V_12 -> V_1025 ) ;
F_377 ( V_8 , V_384 , V_12 -> V_1026 ) ;
}
static int F_464 ( struct V_7 * V_8 , bool V_1027 )
{
struct V_12 * V_12 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_89 * V_791 ;
bool V_1028 ;
if ( ! F_449 ( V_8 ) ||
! F_472 ( V_8 ) )
return 1 ;
F_162 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_430 )
F_451 ( V_72 ) ;
if ( V_12 -> V_822 == V_1027 ) {
F_448 ( V_8 ,
V_1027 ? V_1029
: V_1030 ) ;
return 1 ;
}
if ( V_12 -> V_1031 != V_641 ) {
F_448 ( V_8 , V_1032 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_461 ( V_12 -> V_268 , V_416 ) ) {
F_448 ( V_8 , V_1032 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_461 ( V_12 -> V_1019 , V_416 ) ) {
F_448 ( V_8 , V_1032 ) ;
return 1 ;
}
if ( V_12 -> V_1033 > 0 ||
V_12 -> V_1034 > 0 ||
V_12 -> V_1035 > 0 ) {
F_529 ( L_33 ,
V_477 ) ;
F_448 ( V_8 , V_1032 ) ;
return 1 ;
}
if ( ! F_191 ( V_12 -> V_69 ,
V_316 , V_317 ) ||
! F_191 ( V_12 -> V_70 ,
V_334 , V_335 ) ||
! F_191 ( V_12 -> V_71 ,
V_299 , V_300 ) ||
! F_191 ( V_12 -> V_1021 ,
V_305 , V_307 ) ||
! F_191 ( V_12 -> V_1022 ,
V_310 , V_311 ) )
{
F_448 ( V_8 , V_1032 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1036 & F_195 ) != F_195 ) ||
( ( V_12 -> V_1037 & F_196 ) != F_196 ) ) {
F_448 ( V_8 ,
V_1038 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_230 & F_195 ) != F_195 ) ||
( ( V_12 -> V_232 & F_196 ) != F_196 ) ) {
F_530 ( V_8 , V_12 ,
V_880 , V_1039 ) ;
return 1 ;
}
if ( V_12 -> V_1040 != - 1ull ) {
F_530 ( V_8 , V_12 ,
V_880 , V_1041 ) ;
return 1 ;
}
if ( V_12 -> V_1022 & V_142 ) {
V_1028 = ( V_12 -> V_1022 & V_314 ) != 0 ;
if ( ! F_531 ( V_8 , V_12 -> V_1024 ) ||
V_1028 != ! ! ( V_12 -> V_1024 & V_176 ) ||
( ( V_12 -> V_230 & V_492 ) &&
V_1028 != ! ! ( V_12 -> V_1024 & V_177 ) ) ) {
F_530 ( V_8 , V_12 ,
V_880 , V_1039 ) ;
return 1 ;
}
}
if ( V_12 -> V_1021 & V_143 ) {
V_1028 = ( V_12 -> V_1021 &
V_308 ) != 0 ;
if ( ! F_531 ( V_8 , V_12 -> V_1042 ) ||
V_1028 != ! ! ( V_12 -> V_1042 & V_176 ) ||
V_1028 != ! ! ( V_12 -> V_1042 & V_177 ) ) {
F_530 ( V_8 , V_12 ,
V_880 , V_1039 ) ;
return 1 ;
}
}
V_791 = F_438 ( V_72 ) ;
if ( ! V_791 )
return - V_427 ;
F_532 ( V_8 ) ;
V_72 -> V_13 . V_284 = F_93 ( V_283 ) ;
V_90 = F_517 () ;
V_72 -> V_89 = V_791 ;
F_148 ( V_8 ) ;
F_141 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_518 () ;
F_104 ( V_72 ) ;
V_12 -> V_822 = 1 ;
F_528 ( V_8 , V_12 ) ;
return 1 ;
}
static inline unsigned long
F_533 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_90 ( V_223 ) & V_8 -> V_110 . V_226 ) |
( V_12 -> V_230 & V_12 -> V_227 ) |
( F_90 ( V_235 ) & ~ ( V_12 -> V_227 |
V_8 -> V_110 . V_226 ) ) ;
}
static inline unsigned long
F_534 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_90 ( V_455 ) & V_8 -> V_110 . V_483 ) |
( V_12 -> V_232 & V_12 -> V_233 ) |
( F_90 ( V_457 ) & ~ ( V_12 -> V_233 |
V_8 -> V_110 . V_483 ) ) ;
}
static void F_535 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1043 ;
unsigned int V_148 ;
if ( V_8 -> V_110 . V_713 . V_1044 ) {
V_148 = V_8 -> V_110 . V_713 . V_148 ;
V_1043 = V_148 | V_698 ;
if ( F_168 ( V_148 ) ) {
V_12 -> V_1045 =
V_8 -> V_110 . V_259 ;
V_1043 |= V_263 ;
} else
V_1043 |= V_23 ;
if ( V_8 -> V_110 . V_713 . V_252 ) {
V_1043 |= V_757 ;
V_12 -> V_1046 =
V_8 -> V_110 . V_713 . V_253 ;
}
V_12 -> V_1047 = V_1043 ;
} else if ( V_8 -> V_110 . V_668 ) {
V_12 -> V_1047 =
V_662 | V_22 | V_661 ;
} else if ( V_8 -> V_110 . V_654 . V_1044 ) {
V_148 = V_8 -> V_110 . V_654 . V_148 ;
V_1043 = V_148 | V_698 ;
if ( V_8 -> V_110 . V_654 . V_656 ) {
V_1043 |= V_657 ;
V_12 -> V_1007 =
V_8 -> V_110 . V_259 ;
} else
V_1043 |= V_27 ;
V_12 -> V_1047 = V_1043 ;
}
}
static void F_536 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
V_12 -> V_230 = F_533 ( V_8 , V_12 ) ;
V_12 -> V_232 = F_534 ( V_8 , V_12 ) ;
F_384 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1010 ) ;
V_12 -> V_1025 = F_372 ( V_8 , V_381 ) ;
V_12 -> V_1026 = F_372 ( V_8 , V_384 ) ;
V_12 -> V_1011 = F_90 ( V_239 ) ;
V_12 -> V_949 = F_91 ( V_948 ) ;
V_12 -> V_950 = F_91 ( V_633 ) ;
V_12 -> V_952 = F_91 ( V_951 ) ;
V_12 -> V_954 = F_91 ( V_953 ) ;
V_12 -> V_956 = F_91 ( V_955 ) ;
V_12 -> V_958 = F_91 ( V_957 ) ;
V_12 -> V_959 = F_91 ( V_636 ) ;
V_12 -> V_960 = F_91 ( V_635 ) ;
V_12 -> V_962 = F_92 ( V_961 ) ;
V_12 -> V_964 = F_92 ( V_963 ) ;
V_12 -> V_966 = F_92 ( V_965 ) ;
V_12 -> V_968 = F_92 ( V_967 ) ;
V_12 -> V_970 = F_92 ( V_969 ) ;
V_12 -> V_972 = F_92 ( V_971 ) ;
V_12 -> V_973 = F_92 ( V_638 ) ;
V_12 -> V_974 = F_92 ( V_471 ) ;
V_12 -> V_975 = F_92 ( V_519 ) ;
V_12 -> V_976 = F_92 ( V_517 ) ;
V_12 -> V_978 = F_92 ( V_977 ) ;
V_12 -> V_980 = F_92 ( V_979 ) ;
V_12 -> V_982 = F_92 ( V_981 ) ;
V_12 -> V_984 = F_92 ( V_983 ) ;
V_12 -> V_986 = F_92 ( V_985 ) ;
V_12 -> V_988 = F_92 ( V_987 ) ;
V_12 -> V_989 = F_92 ( V_639 ) ;
V_12 -> V_990 = F_92 ( V_473 ) ;
V_12 -> V_992 = F_90 ( V_991 ) ;
V_12 -> V_993 = F_90 ( V_634 ) ;
V_12 -> V_995 = F_90 ( V_994 ) ;
V_12 -> V_997 = F_90 ( V_996 ) ;
V_12 -> V_998 = F_90 ( V_364 ) ;
V_12 -> V_999 = F_90 ( V_365 ) ;
V_12 -> V_1000 = F_90 ( V_637 ) ;
V_12 -> V_1001 = F_90 ( V_470 ) ;
V_12 -> V_1002 = F_90 ( V_520 ) ;
V_12 -> V_1003 = F_90 ( V_518 ) ;
V_12 -> V_1008 =
F_92 ( V_244 ) ;
V_12 -> V_1012 =
F_90 ( V_642 ) ;
V_12 -> V_1022 =
( V_12 -> V_1022 & ~ V_314 ) |
( F_92 ( V_136 ) & V_314 ) ;
V_12 -> V_1004 = F_93 ( V_643 ) ;
if ( V_12 -> V_1021 & V_413 )
V_12 -> V_1023 = F_93 ( V_376 ) ;
V_12 -> V_1009 = F_92 ( V_368 ) ;
V_12 -> V_1013 = F_90 ( V_371 ) ;
V_12 -> V_1014 = F_90 ( V_370 ) ;
V_12 -> V_665 = F_6 ( V_8 ) -> V_700 ;
V_12 -> V_718 = F_90 ( V_706 ) ;
V_12 -> V_667 = F_92 ( V_854 ) ;
if ( ( V_12 -> V_667 &
( V_22 | V_257 ) ) ==
( V_22 | V_257 ) )
V_12 -> V_1048 =
F_92 ( V_697 ) ;
V_12 -> V_1047 = 0 ;
V_12 -> V_1045 = F_92 ( V_251 ) ;
V_12 -> V_801 = F_92 ( V_819 ) ;
if ( ! ( V_12 -> V_665 & V_893 ) ) {
V_12 -> V_1005 &= ~ V_22 ;
F_535 ( V_8 , V_12 ) ;
}
V_8 -> V_110 . V_756 = false ;
F_420 ( V_8 ) ;
F_419 ( V_8 ) ;
}
static void F_537 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
if ( V_12 -> V_1021 & V_143 )
V_8 -> V_110 . V_173 = V_12 -> V_1042 ;
else if ( V_12 -> V_1021 & V_308 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_247 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_377 ( V_8 , V_381 , V_12 -> V_1020 ) ;
F_377 ( V_8 , V_384 , V_12 -> V_1049 ) ;
F_159 ( V_8 , V_1050 ) ;
F_367 ( V_8 , V_12 -> V_1036 ) ;
F_110 ( V_8 ) ;
V_8 -> V_110 . V_226 = ( V_8 -> V_132 ? V_224 : 0 ) ;
F_97 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
V_8 -> V_110 . V_483 = ~ F_90 ( V_592 ) ;
F_369 ( V_8 , V_12 -> V_1037 ) ;
F_375 ( V_8 , V_12 -> V_1051 ) ;
F_246 ( V_8 ) ;
if ( V_429 ) {
F_251 ( V_8 ) ;
}
F_100 ( V_368 , V_12 -> V_1052 ) ;
F_97 ( V_371 , V_12 -> V_1053 ) ;
F_97 ( V_370 , V_12 -> V_1054 ) ;
F_97 ( V_518 , V_12 -> V_1055 ) ;
F_97 ( V_520 , V_12 -> V_1056 ) ;
F_97 ( V_470 , V_12 -> V_1057 ) ;
F_97 ( V_365 , V_12 -> V_1058 ) ;
F_97 ( V_364 , V_12 -> V_1059 ) ;
F_99 ( V_948 , V_12 -> V_1060 ) ;
F_99 ( V_633 , V_12 -> V_1061 ) ;
F_99 ( V_951 , V_12 -> V_1062 ) ;
F_99 ( V_953 , V_12 -> V_1063 ) ;
F_99 ( V_955 , V_12 -> V_1064 ) ;
F_99 ( V_957 , V_12 -> V_1065 ) ;
F_99 ( V_635 , V_12 -> V_1066 ) ;
if ( V_12 -> V_1021 & V_414 )
F_101 ( V_376 , V_12 -> V_1067 ) ;
if ( V_12 -> V_1021 & V_147 )
F_101 ( V_159 ,
V_12 -> V_1068 ) ;
F_385 ( V_8 , 7 , 0x400 ) ;
F_101 ( V_643 , 0 ) ;
}
static void F_166 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_538 ( V_72 -> V_13 . V_255 ) ;
F_539 ( V_8 ) ;
F_536 ( V_8 , V_12 ) ;
V_90 = F_517 () ;
V_72 -> V_89 = & V_72 -> V_795 ;
F_148 ( V_8 ) ;
F_141 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_518 () ;
F_104 ( V_72 ) ;
if ( V_793 == 0 )
F_444 ( V_72 , V_72 -> V_13 . V_788 ) ;
F_537 ( V_8 , V_12 ) ;
F_101 ( V_283 , V_72 -> V_13 . V_284 ) ;
V_72 -> V_1020 = 0 ;
if ( V_72 -> V_13 . V_551 ) {
F_13 ( V_72 -> V_13 . V_551 ) ;
V_72 -> V_13 . V_551 = 0 ;
}
if ( F_98 ( V_72 -> V_855 ) ) {
V_72 -> V_855 = 0 ;
F_448 ( V_8 , F_92 ( V_103 ) ) ;
} else
F_456 ( V_8 ) ;
if ( V_430 )
V_72 -> V_13 . V_799 = true ;
}
static void F_530 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_750 , unsigned long V_1069 )
{
F_537 ( V_8 , V_12 ) ;
V_12 -> V_665 = V_750 | V_893 ;
V_12 -> V_718 = V_1069 ;
F_456 ( V_8 ) ;
if ( V_430 )
F_6 ( V_8 ) -> V_13 . V_799 = true ;
}
static int F_540 ( struct V_7 * V_8 ,
struct V_1070 * V_1071 ,
enum V_1072 V_1073 )
{
return V_1074 ;
}
static int T_11 F_541 ( void )
{
int V_532 , V_74 , V_73 ;
F_542 ( V_140 , & V_178 ) ;
for ( V_74 = 0 ; V_74 < V_625 ; ++ V_74 )
F_543 ( V_74 , V_76 [ V_74 ] ) ;
V_596 = ( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_596 )
return - V_427 ;
V_532 = - V_427 ;
V_598 = ( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_598 )
goto V_515;
V_273 = ( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_273 )
goto V_1075;
V_271 =
( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_271 )
goto V_1076;
V_272 = ( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_272 )
goto V_1077;
V_270 =
( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_270 )
goto V_1078;
V_600 = ( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_600 )
goto V_1079;
V_602 = ( unsigned long * ) F_544 ( V_426 ) ;
if ( ! V_602 )
goto V_1080;
memset ( V_600 , 0xff , V_416 ) ;
memset ( V_602 , 0xff , V_416 ) ;
for ( V_74 = 0 ; V_74 < V_831 ; V_74 ++ ) {
F_545 ( V_829 [ V_74 ] , V_602 ) ;
F_545 ( V_829 [ V_74 ] , V_600 ) ;
}
for ( V_74 = 0 ; V_74 < V_835 ; V_74 ++ )
F_545 ( V_832 [ V_74 ] , V_600 ) ;
memset ( V_596 , 0xff , V_416 ) ;
F_545 ( 0x80 , V_596 ) ;
memset ( V_598 , 0xff , V_416 ) ;
memset ( V_273 , 0xff , V_416 ) ;
memset ( V_272 , 0xff , V_416 ) ;
F_546 ( 0 , V_559 ) ;
V_532 = F_547 ( & V_1081 , sizeof( struct V_6 ) ,
F_548 ( struct V_6 ) , V_1082 ) ;
if ( V_532 )
goto V_1083;
#ifdef F_549
F_550 ( V_1084 ,
F_76 ) ;
#endif
F_302 ( V_203 , false ) ;
F_302 ( V_205 , false ) ;
F_302 ( V_206 , true ) ;
F_302 ( V_367 , false ) ;
F_302 ( V_220 , false ) ;
F_302 ( V_369 , false ) ;
memcpy ( V_271 ,
V_273 , V_416 ) ;
memcpy ( V_270 ,
V_272 , V_416 ) ;
if ( V_436 ) {
for ( V_73 = 0x800 ; V_73 <= 0x8ff ; V_73 ++ )
F_304 ( V_73 ) ;
F_303 ( 0x802 ) ;
F_303 ( 0x839 ) ;
F_305 ( 0x808 ) ;
F_305 ( 0x80b ) ;
F_305 ( 0x83f ) ;
}
if ( V_100 ) {
F_551 ( 0ull ,
( V_432 ) ? V_1085 : 0ull ,
( V_432 ) ? V_1086 : 0ull ,
0ull , V_1087 ) ;
F_321 () ;
F_552 () ;
} else
F_553 () ;
return 0 ;
V_1083:
F_554 ( ( unsigned long ) V_602 ) ;
V_1080:
F_554 ( ( unsigned long ) V_600 ) ;
V_1079:
F_554 ( ( unsigned long ) V_270 ) ;
V_1078:
F_554 ( ( unsigned long ) V_272 ) ;
V_1077:
F_554 ( ( unsigned long ) V_271 ) ;
V_1076:
F_554 ( ( unsigned long ) V_273 ) ;
V_1075:
F_554 ( ( unsigned long ) V_598 ) ;
V_515:
F_554 ( ( unsigned long ) V_596 ) ;
return V_532 ;
}
static void T_12 F_555 ( void )
{
F_554 ( ( unsigned long ) V_271 ) ;
F_554 ( ( unsigned long ) V_270 ) ;
F_554 ( ( unsigned long ) V_273 ) ;
F_554 ( ( unsigned long ) V_272 ) ;
F_554 ( ( unsigned long ) V_598 ) ;
F_554 ( ( unsigned long ) V_596 ) ;
F_554 ( ( unsigned long ) V_602 ) ;
F_554 ( ( unsigned long ) V_600 ) ;
#ifdef F_549
F_550 ( V_1084 , NULL ) ;
F_556 () ;
#endif
F_557 () ;
}
