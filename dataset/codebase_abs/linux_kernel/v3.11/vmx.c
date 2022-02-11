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
F_183 ( V_8 -> V_292 ,
F_93 ( V_283 ) , V_290 ) ;
F_101 ( V_283 , V_290 ) ;
}
}
static void F_184 ( struct V_7 * V_8 , T_10 V_293 , bool V_150 )
{
T_3 V_290 = F_93 ( V_283 ) ;
F_101 ( V_283 , V_290 + V_293 ) ;
if ( F_111 ( V_8 ) ) {
F_6 ( V_8 ) -> V_13 . V_284 += V_293 ;
} else
F_183 ( V_8 -> V_292 , V_290 ,
V_290 + V_293 ) ;
}
static T_3 F_185 ( struct V_7 * V_8 , T_3 V_294 )
{
return V_294 - F_186 () ;
}
static bool F_187 ( struct V_7 * V_8 )
{
struct V_295 * V_296 = F_188 ( V_8 , 1 , 0 ) ;
return V_296 && ( V_296 -> V_297 & ( 1 << ( V_298 & 31 ) ) ) ;
}
static inline bool F_189 ( struct V_7 * V_8 )
{
return V_13 && F_187 ( V_8 ) ;
}
static T_11 void F_190 ( void )
{
F_191 ( V_299 ,
V_300 , V_301 ) ;
V_300 |= V_302 ;
V_301 &= V_303 |
V_304 | V_62 |
V_305 ;
V_301 |= V_302 ;
V_306 = V_307 ;
#ifdef F_94
V_308 = V_309 ;
#else
V_308 = 0 ;
#endif
V_308 |= V_307 ;
F_191 ( V_310 ,
V_311 , V_312 ) ;
V_311 = V_313 ;
V_312 &=
V_314 | V_315 ;
V_312 |= V_313 ;
F_191 ( V_316 ,
V_317 , V_318 ) ;
V_317 = 0 ;
V_318 &=
V_319 | V_291 |
V_320 | V_321 |
V_322 | V_323 |
V_324 |
#ifdef F_94
V_325 | V_326 |
#endif
V_327 | V_328 |
V_329 | V_330 |
V_331 | V_332 |
V_333 |
V_33 ;
V_318 |= V_31 ;
F_191 ( V_334 ,
V_335 , V_336 ) ;
V_335 = 0 ;
V_336 &=
V_35 |
V_63 ;
F_191 ( V_65 , V_337 , V_338 ) ;
V_337 &= V_339 |
V_340 ;
V_338 = 0 ;
}
static inline bool F_192 ( T_2 V_3 , T_2 V_341 , T_2 V_342 )
{
return ( ( V_3 & V_342 ) | V_341 ) == V_3 ;
}
static inline T_3 F_193 ( T_2 V_341 , T_2 V_342 )
{
return V_341 | ( ( T_3 ) V_342 << 32 ) ;
}
static int F_194 ( struct V_7 * V_8 , T_2 V_343 , T_3 * V_344 )
{
if ( ! F_189 ( V_8 ) && V_343 >= V_345 &&
V_343 <= V_346 ) {
F_195 ( V_8 , V_347 , 0 ) ;
return 1 ;
}
switch ( V_343 ) {
case V_348 :
* V_344 = 0 ;
break;
case V_345 :
* V_344 = V_349 |
( ( T_3 ) V_350 << V_351 ) |
( V_352 << V_353 ) ;
break;
case V_354 :
case V_299 :
* V_344 = F_193 ( V_300 ,
V_301 ) ;
break;
case V_355 :
case V_316 :
* V_344 = F_193 ( V_317 ,
V_318 ) ;
break;
case V_356 :
case V_357 :
* V_344 = F_193 ( V_306 ,
V_308 ) ;
break;
case V_346 :
case V_310 :
* V_344 = F_193 ( V_311 ,
V_312 ) ;
break;
case V_65 :
* V_344 = F_193 ( V_337 ,
V_338 ) ;
break;
#define F_196 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_197 X86_CR4_VMXE
case V_358 :
* V_344 = F_196 ;
break;
case V_359 :
* V_344 = - 1ULL ;
break;
case V_360 :
* V_344 = F_197 ;
break;
case V_361 :
* V_344 = - 1ULL ;
break;
case V_362 :
* V_344 = 0x1f ;
break;
case V_334 :
* V_344 = F_193 ( V_335 ,
V_336 ) ;
break;
case V_363 :
* V_344 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_198 ( struct V_7 * V_8 , T_2 V_343 , T_3 V_179 )
{
if ( ! F_189 ( V_8 ) )
return 0 ;
if ( V_343 == V_348 )
return 1 ;
return 0 ;
}
static int F_199 ( struct V_7 * V_8 , T_2 V_343 , T_3 * V_344 )
{
T_3 V_179 ;
struct V_85 * V_73 ;
if ( ! V_344 ) {
F_67 ( V_88 L_7 ) ;
return - V_364 ;
}
switch ( V_343 ) {
#ifdef F_94
case V_203 :
V_179 = F_90 ( V_365 ) ;
break;
case V_205 :
V_179 = F_90 ( V_366 ) ;
break;
case V_206 :
F_138 ( F_6 ( V_8 ) ) ;
V_179 = F_6 ( V_8 ) -> V_208 ;
break;
#endif
case V_140 :
return F_200 ( V_8 , V_343 , V_344 ) ;
case V_367 :
V_179 = F_176 () ;
break;
case V_368 :
V_179 = F_92 ( V_369 ) ;
break;
case V_370 :
V_179 = F_90 ( V_371 ) ;
break;
case V_220 :
V_179 = F_90 ( V_372 ) ;
break;
case V_278 :
if ( ! F_6 ( V_8 ) -> V_279 )
return 1 ;
default:
if ( F_194 ( V_8 , V_343 , V_344 ) )
return 0 ;
V_73 = F_64 ( F_6 ( V_8 ) , V_343 ) ;
if ( V_73 ) {
V_179 = V_73 -> V_179 ;
break;
}
return F_200 ( V_8 , V_343 , V_344 ) ;
}
* V_344 = V_179 ;
return 0 ;
}
static int F_201 ( struct V_7 * V_8 , struct V_373 * V_374 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 ;
int V_108 = 0 ;
T_2 V_343 = V_374 -> V_78 ;
T_3 V_179 = V_374 -> V_179 ;
switch ( V_343 ) {
case V_140 :
V_108 = F_202 ( V_8 , V_374 ) ;
break;
#ifdef F_94
case V_203 :
F_104 ( V_72 ) ;
F_97 ( V_365 , V_179 ) ;
break;
case V_205 :
F_104 ( V_72 ) ;
F_97 ( V_366 , V_179 ) ;
break;
case V_206 :
F_138 ( V_72 ) ;
V_72 -> V_208 = V_179 ;
break;
#endif
case V_368 :
F_100 ( V_369 , V_179 ) ;
break;
case V_370 :
F_97 ( V_371 , V_179 ) ;
break;
case V_220 :
F_97 ( V_372 , V_179 ) ;
break;
case V_367 :
F_203 ( V_8 , V_374 ) ;
break;
case V_375 :
if ( V_29 . V_376 & V_314 ) {
F_101 ( V_377 , V_179 ) ;
V_8 -> V_110 . V_378 = V_179 ;
break;
}
V_108 = F_202 ( V_8 , V_374 ) ;
break;
case V_379 :
V_108 = F_202 ( V_8 , V_374 ) ;
break;
case V_278 :
if ( ! V_72 -> V_279 )
return 1 ;
if ( ( V_179 >> 32 ) != 0 )
return 1 ;
default:
if ( F_198 ( V_8 , V_343 , V_179 ) )
break;
V_73 = F_64 ( V_72 , V_343 ) ;
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
V_108 = F_202 ( V_8 , V_374 ) ;
}
return V_108 ;
}
static void F_204 ( struct V_7 * V_8 , enum V_380 V_381 )
{
F_158 ( V_381 , ( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
switch ( V_381 ) {
case V_382 :
V_8 -> V_110 . V_383 [ V_382 ] = F_90 ( V_384 ) ;
break;
case V_385 :
V_8 -> V_110 . V_383 [ V_385 ] = F_90 ( V_386 ) ;
break;
case V_387 :
if ( V_100 )
F_205 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_206 ( void )
{
return F_207 () ;
}
static T_11 int F_208 ( void )
{
T_3 V_73 ;
F_55 ( V_348 , V_73 ) ;
if ( V_73 & V_388 ) {
if ( ! ( V_73 & V_389 )
&& F_209 () )
return 1 ;
if ( ! ( V_73 & V_390 )
&& ( V_73 & V_389 )
&& ! F_209 () ) {
F_67 ( V_162 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_73 & V_390 )
&& ! F_209 () )
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
static int F_210 ( void * V_391 )
{
int V_90 = F_77 () ;
T_3 V_87 = F_66 ( F_80 ( V_213 , V_90 ) ) ;
T_3 V_392 , V_393 ;
if ( F_211 () & V_394 )
return - V_395 ;
F_212 ( & F_80 ( V_217 , V_90 ) ) ;
F_70 ( V_90 ) ;
F_55 ( V_348 , V_392 ) ;
V_393 = V_388 ;
V_393 |= V_390 ;
if ( F_209 () )
V_393 |= V_389 ;
if ( ( V_392 & V_393 ) != V_393 ) {
F_129 ( V_348 , V_392 | V_393 ) ;
}
F_213 ( F_211 () | V_394 ) ;
if ( V_214 ) {
F_142 ( V_87 ) ;
F_88 () ;
}
F_214 ( & F_118 ( V_165 ) ) ;
return 0 ;
}
static void F_215 ( void )
{
int V_90 = F_77 () ;
struct V_89 * V_93 , * V_396 ;
F_216 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_79 ( V_93 ) ;
}
static void F_149 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_217 ( void * V_391 )
{
if ( V_214 ) {
F_215 () ;
F_149 () ;
}
F_213 ( F_211 () & ~ V_394 ) ;
}
static T_11 int F_218 ( T_2 V_397 , T_2 V_398 ,
T_2 V_73 , T_2 * V_399 )
{
T_2 V_400 , V_401 ;
T_2 V_402 = V_397 | V_398 ;
F_191 ( V_73 , V_400 , V_401 ) ;
V_402 &= V_401 ;
V_402 |= V_400 ;
if ( V_397 & ~ V_402 )
return - V_403 ;
* V_399 = V_402 ;
return 0 ;
}
static T_11 bool F_219 ( T_2 V_73 , T_2 V_402 )
{
T_2 V_400 , V_401 ;
F_191 ( V_73 , V_400 , V_401 ) ;
return V_401 & V_402 ;
}
static T_11 int F_220 ( struct V_29 * V_404 )
{
T_2 V_400 , V_401 ;
T_2 V_405 , V_406 , V_407 , V_408 ;
T_2 V_409 = 0 ;
T_2 V_410 = 0 ;
T_2 V_411 = 0 ;
T_2 V_412 = 0 ;
T_2 V_413 = 0 ;
V_405 = V_320 |
#ifdef F_94
V_325 |
V_326 |
#endif
V_323 |
V_324 |
V_329 |
V_327 |
V_291 |
V_322 |
V_330 |
V_321 |
V_331 ;
V_406 = V_32 |
V_31 |
V_33 ;
if ( F_218 ( V_405 , V_406 , V_316 ,
& V_410 ) < 0 )
return - V_403 ;
#ifdef F_94
if ( ( V_410 & V_32 ) )
V_410 &= ~ V_325 &
~ V_326 ;
#endif
if ( V_410 & V_33 ) {
V_407 = 0 ;
V_408 = V_35 |
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
if ( F_218 ( V_407 , V_408 ,
V_334 ,
& V_411 ) < 0 )
return - V_403 ;
}
#ifndef F_94
if ( ! ( V_411 &
V_35 ) )
V_410 &= ~ V_32 ;
#endif
if ( ! ( V_410 & V_32 ) )
V_411 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_411 & V_55 ) {
V_410 &= ~ ( V_323 |
V_324 |
V_321 ) ;
F_191 ( V_363 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_405 = 0 ;
#ifdef F_94
V_405 |= V_309 ;
#endif
V_406 = V_414 | V_415 |
V_416 ;
if ( F_218 ( V_405 , V_406 , V_357 ,
& V_412 ) < 0 )
return - V_403 ;
V_405 = V_303 | V_304 ;
V_406 = V_62 | V_40 ;
if ( F_218 ( V_405 , V_406 , V_299 ,
& V_409 ) < 0 )
return - V_403 ;
if ( ! ( V_411 &
V_38 ) ||
! ( V_412 & V_416 ) )
V_409 &= ~ V_40 ;
V_405 = 0 ;
V_406 = V_314 ;
if ( F_218 ( V_405 , V_406 , V_310 ,
& V_413 ) < 0 )
return - V_403 ;
F_191 ( V_345 , V_400 , V_401 ) ;
if ( ( V_401 & 0x1fff ) > V_417 )
return - V_403 ;
#ifdef F_94
if ( V_401 & ( 1u << 16 ) )
return - V_403 ;
#endif
if ( ( ( V_401 >> 18 ) & 15 ) != 6 )
return - V_403 ;
V_404 -> V_418 = V_401 & 0x1fff ;
V_404 -> V_419 = F_221 ( V_29 . V_418 ) ;
V_404 -> V_420 = V_400 ;
V_404 -> V_39 = V_409 ;
V_404 -> V_30 = V_410 ;
V_404 -> V_34 = V_411 ;
V_404 -> V_421 = V_412 ;
V_404 -> V_376 = V_413 ;
V_141 =
F_219 ( V_310 ,
V_142 )
&& F_219 ( V_357 ,
V_143 ) ;
V_145 =
F_219 ( V_310 ,
V_146 )
&& F_219 ( V_357 ,
V_147 ) ;
if ( V_145 && V_422 . V_423 == 0x6 ) {
switch ( V_422 . V_424 ) {
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
static struct V_86 * F_222 ( int V_90 )
{
int V_425 = F_223 ( V_90 ) ;
struct V_15 * V_426 ;
struct V_86 * V_86 ;
V_426 = F_224 ( V_425 , V_427 , V_29 . V_419 ) ;
if ( ! V_426 )
return NULL ;
V_86 = F_225 ( V_426 ) ;
memset ( V_86 , 0 , V_29 . V_418 ) ;
V_86 -> V_420 = V_29 . V_420 ;
return V_86 ;
}
static struct V_86 * F_226 ( void )
{
return F_222 ( F_77 () ) ;
}
static void F_227 ( struct V_86 * V_86 )
{
F_228 ( ( unsigned long ) V_86 , V_29 . V_419 ) ;
}
static void F_229 ( struct V_89 * V_89 )
{
if ( ! V_89 -> V_86 )
return;
F_83 ( V_89 ) ;
F_227 ( V_89 -> V_86 ) ;
V_89 -> V_86 = NULL ;
}
static void F_230 ( void )
{
int V_90 ;
F_231 (cpu) {
F_227 ( F_80 ( V_213 , V_90 ) ) ;
F_80 ( V_213 , V_90 ) = NULL ;
}
}
static T_11 int F_232 ( void )
{
int V_90 ;
F_231 (cpu) {
struct V_86 * V_86 ;
V_86 = F_222 ( V_90 ) ;
if ( ! V_86 ) {
F_230 () ;
return - V_428 ;
}
F_80 ( V_213 , V_90 ) = V_86 ;
}
return 0 ;
}
static T_11 int F_233 ( void )
{
if ( F_220 ( & V_29 ) < 0 )
return - V_403 ;
if ( F_234 ( V_429 ) )
F_235 ( V_174 ) ;
if ( ! F_49 () )
V_430 = 0 ;
if ( ! F_54 () )
V_431 = 0 ;
if ( ! F_45 () ||
! F_39 () ) {
V_100 = 0 ;
V_432 = 0 ;
V_433 = 0 ;
}
if ( ! F_40 () )
V_433 = 0 ;
if ( ! F_46 () )
V_432 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_434 -> V_435 = NULL ;
if ( V_100 && ! F_37 () )
F_236 () ;
if ( ! F_47 () )
V_436 = 0 ;
if ( ! F_32 () )
V_437 = 0 ;
if ( V_437 )
V_434 -> V_435 = NULL ;
else {
V_434 -> V_438 = NULL ;
V_434 -> V_439 = NULL ;
V_434 -> V_440 = V_441 ;
}
if ( V_13 )
F_190 () ;
return F_232 () ;
}
static T_12 void F_237 ( void )
{
F_230 () ;
}
static bool F_238 ( struct V_7 * V_8 )
{
return V_442 && ! F_239 ( V_8 ) ;
}
static void F_240 ( struct V_7 * V_8 , int V_107 ,
struct V_443 * V_444 )
{
if ( ! V_442 ) {
if ( V_107 == V_445 || V_107 == V_446 )
V_444 -> V_114 &= ~ V_447 ;
V_444 -> V_448 = V_444 -> V_114 & V_447 ;
V_444 -> V_183 = 1 ;
}
F_241 ( V_8 , V_444 , V_107 ) ;
}
static void F_242 ( struct V_7 * V_8 )
{
unsigned long V_449 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_451 ] , V_451 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_452 ] , V_452 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_453 ] , V_453 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_454 ] , V_454 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_446 ] , V_446 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_445 ] , V_445 ) ;
V_72 -> V_130 . V_131 = 0 ;
F_104 ( V_72 ) ;
F_241 ( V_8 , & V_72 -> V_130 . V_450 [ V_455 ] , V_455 ) ;
V_449 = F_90 ( V_239 ) ;
V_449 &= V_240 ;
V_449 |= V_72 -> V_130 . V_237 & ~ V_240 ;
F_97 ( V_239 , V_449 ) ;
F_97 ( V_456 , ( F_90 ( V_456 ) & ~ V_457 ) |
( F_90 ( V_458 ) & V_457 ) ) ;
F_110 ( V_8 ) ;
F_240 ( V_8 , V_445 , & V_72 -> V_130 . V_450 [ V_445 ] ) ;
F_240 ( V_8 , V_446 , & V_72 -> V_130 . V_450 [ V_446 ] ) ;
F_240 ( V_8 , V_451 , & V_72 -> V_130 . V_450 [ V_451 ] ) ;
F_240 ( V_8 , V_452 , & V_72 -> V_130 . V_450 [ V_452 ] ) ;
F_240 ( V_8 , V_453 , & V_72 -> V_130 . V_450 [ V_453 ] ) ;
F_240 ( V_8 , V_454 , & V_72 -> V_130 . V_450 [ V_454 ] ) ;
F_158 ( V_459 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_460 = 0 ;
}
static void F_244 ( int V_107 , struct V_443 * V_444 )
{
const struct V_461 * V_462 = & V_116 [ V_107 ] ;
struct V_443 V_463 = * V_444 ;
V_463 . V_448 = 0x3 ;
if ( V_107 == V_445 )
V_463 . type = 0x3 ;
if ( ! V_442 ) {
V_463 . V_114 = V_463 . V_117 >> 4 ;
V_463 . V_117 = V_463 . V_117 & 0xffff0 ;
V_463 . V_119 = 0xffff ;
V_463 . V_464 = 0 ;
V_463 . V_465 = 0 ;
V_463 . V_466 = 1 ;
V_463 . V_183 = 1 ;
V_463 . V_467 = 0 ;
V_463 . V_468 = 0 ;
V_463 . type = 0x3 ;
V_463 . V_469 = 0 ;
if ( V_444 -> V_117 & 0xf )
F_116 ( V_162 L_12
L_13
L_14 , V_107 ) ;
}
F_99 ( V_462 -> V_114 , V_463 . V_114 ) ;
F_100 ( V_462 -> V_117 , V_463 . V_117 ) ;
F_100 ( V_462 -> V_119 , V_463 . V_119 ) ;
F_100 ( V_462 -> V_123 , F_245 ( & V_463 ) ) ;
}
static void F_246 ( struct V_7 * V_8 )
{
unsigned long V_449 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_455 ] , V_455 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_451 ] , V_451 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_452 ] , V_452 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_453 ] , V_453 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_454 ] , V_454 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_446 ] , V_446 ) ;
F_243 ( V_8 , & V_72 -> V_130 . V_450 [ V_445 ] , V_445 ) ;
V_72 -> V_130 . V_131 = 1 ;
if ( ! V_8 -> V_17 -> V_110 . V_470 )
F_116 ( V_162 L_15
L_16 ) ;
F_104 ( V_72 ) ;
F_97 ( V_471 , V_8 -> V_17 -> V_110 . V_470 ) ;
F_100 ( V_472 , V_473 - 1 ) ;
F_100 ( V_474 , 0x008b ) ;
V_449 = F_90 ( V_239 ) ;
V_72 -> V_130 . V_237 = V_449 ;
V_449 |= V_241 | V_242 ;
F_97 ( V_239 , V_449 ) ;
F_97 ( V_456 , F_90 ( V_456 ) | V_457 ) ;
F_110 ( V_8 ) ;
F_244 ( V_446 , & V_72 -> V_130 . V_450 [ V_446 ] ) ;
F_244 ( V_445 , & V_72 -> V_130 . V_450 [ V_445 ] ) ;
F_244 ( V_451 , & V_72 -> V_130 . V_450 [ V_451 ] ) ;
F_244 ( V_452 , & V_72 -> V_130 . V_450 [ V_452 ] ) ;
F_244 ( V_454 , & V_72 -> V_130 . V_450 [ V_454 ] ) ;
F_244 ( V_453 , & V_72 -> V_130 . V_450 [ V_453 ] ) ;
F_247 ( V_8 ) ;
}
static void F_248 ( struct V_7 * V_8 , T_3 V_173 )
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
V_315 ) ;
V_73 -> V_179 = V_173 ;
} else {
F_100 ( V_136 ,
F_92 ( V_136 ) &
~ V_315 ) ;
V_73 -> V_179 = V_173 & ~ V_177 ;
}
F_175 ( V_72 ) ;
}
static void F_249 ( struct V_7 * V_8 )
{
T_2 V_475 ;
F_104 ( F_6 ( V_8 ) ) ;
V_475 = F_92 ( V_474 ) ;
if ( ( V_475 & V_476 ) != V_477 ) {
F_250 ( L_17 ,
V_478 ) ;
F_100 ( V_474 ,
( V_475 & ~ V_476 )
| V_477 ) ;
}
F_248 ( V_8 , V_8 -> V_110 . V_173 | V_176 ) ;
}
static void F_251 ( struct V_7 * V_8 )
{
F_100 ( V_136 ,
F_92 ( V_136 )
& ~ V_315 ) ;
F_248 ( V_8 , V_8 -> V_110 . V_173 & ~ V_176 ) ;
}
static void F_252 ( struct V_7 * V_8 )
{
F_87 ( F_6 ( V_8 ) ) ;
if ( V_100 ) {
if ( ! F_253 ( V_8 -> V_110 . V_479 . V_480 ) )
return;
F_89 ( F_254 ( V_8 -> V_110 . V_479 . V_480 ) ) ;
}
}
static void F_155 ( struct V_7 * V_8 )
{
T_9 V_226 = V_8 -> V_110 . V_226 ;
V_8 -> V_110 . V_222 &= ~ V_226 ;
V_8 -> V_110 . V_222 |= F_90 ( V_223 ) & V_226 ;
}
static void F_255 ( struct V_7 * V_8 )
{
if ( V_100 && F_256 ( V_8 ) )
V_8 -> V_110 . V_481 = F_90 ( V_482 ) ;
F_158 ( V_483 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
}
static void F_257 ( struct V_7 * V_8 )
{
T_9 V_484 = V_8 -> V_110 . V_484 ;
V_8 -> V_110 . V_485 &= ~ V_484 ;
V_8 -> V_110 . V_485 |= F_90 ( V_456 ) & V_484 ;
}
static void F_258 ( struct V_7 * V_8 )
{
if ( ! F_157 ( V_387 ,
( unsigned long * ) & V_8 -> V_110 . V_486 ) )
return;
if ( F_256 ( V_8 ) && F_259 ( V_8 ) && ! F_128 ( V_8 ) ) {
F_101 ( V_487 , V_8 -> V_110 . V_479 . V_488 [ 0 ] ) ;
F_101 ( V_489 , V_8 -> V_110 . V_479 . V_488 [ 1 ] ) ;
F_101 ( V_490 , V_8 -> V_110 . V_479 . V_488 [ 2 ] ) ;
F_101 ( V_491 , V_8 -> V_110 . V_479 . V_488 [ 3 ] ) ;
}
}
static void F_205 ( struct V_7 * V_8 )
{
if ( F_256 ( V_8 ) && F_259 ( V_8 ) && ! F_128 ( V_8 ) ) {
V_8 -> V_110 . V_479 . V_488 [ 0 ] = F_93 ( V_487 ) ;
V_8 -> V_110 . V_479 . V_488 [ 1 ] = F_93 ( V_489 ) ;
V_8 -> V_110 . V_479 . V_488 [ 2 ] = F_93 ( V_490 ) ;
V_8 -> V_110 . V_479 . V_488 [ 3 ] = F_93 ( V_491 ) ;
}
F_158 ( V_387 ,
( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
F_158 ( V_387 ,
( unsigned long * ) & V_8 -> V_110 . V_486 ) ;
}
static void F_260 ( unsigned long * V_492 ,
unsigned long V_222 ,
struct V_7 * V_8 )
{
if ( ! F_157 ( V_483 , ( T_9 * ) & V_8 -> V_110 . V_111 ) )
F_255 ( V_8 ) ;
if ( ! ( V_222 & V_493 ) ) {
F_100 ( V_494 ,
F_92 ( V_494 ) |
( V_323 |
V_324 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_261 ( V_8 , F_262 ( V_8 ) ) ;
} else if ( ! F_256 ( V_8 ) ) {
F_100 ( V_494 ,
F_92 ( V_494 ) &
~ ( V_323 |
V_324 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_261 ( V_8 , F_262 ( V_8 ) ) ;
}
if ( ! ( V_222 & V_495 ) )
* V_492 &= ~ V_495 ;
}
static void F_263 ( struct V_7 * V_8 , unsigned long V_222 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_492 ;
V_492 = ( V_222 & ~ V_496 ) ;
if ( V_432 )
V_492 |= V_497 ;
else {
V_492 |= V_498 ;
if ( V_72 -> V_130 . V_131 && ( V_222 & V_499 ) )
F_242 ( V_8 ) ;
if ( ! V_72 -> V_130 . V_131 && ! ( V_222 & V_499 ) )
F_246 ( V_8 ) ;
}
#ifdef F_94
if ( V_8 -> V_110 . V_173 & V_177 ) {
if ( ! F_256 ( V_8 ) && ( V_222 & V_493 ) )
F_249 ( V_8 ) ;
if ( F_256 ( V_8 ) && ! ( V_222 & V_493 ) )
F_251 ( V_8 ) ;
}
#endif
if ( V_100 )
F_260 ( & V_492 , V_222 , V_8 ) ;
if ( ! V_8 -> V_132 )
V_492 |= V_224 | V_225 ;
F_97 ( V_235 , V_222 ) ;
F_97 ( V_223 , V_492 ) ;
V_8 -> V_110 . V_222 = V_222 ;
V_72 -> F_238 = F_238 ( V_8 ) ;
}
static T_3 F_254 ( unsigned long V_480 )
{
T_3 V_83 ;
V_83 = V_500 |
V_501 << V_502 ;
if ( V_433 )
V_83 |= V_503 ;
V_83 |= ( V_480 & V_504 ) ;
return V_83 ;
}
static void F_264 ( struct V_7 * V_8 , unsigned long V_481 )
{
unsigned long V_505 ;
T_3 V_83 ;
V_505 = V_481 ;
if ( V_100 ) {
V_83 = F_254 ( V_481 ) ;
F_101 ( V_506 , V_83 ) ;
V_505 = F_256 ( V_8 ) ? F_265 ( V_8 ) :
V_8 -> V_17 -> V_110 . V_507 ;
F_258 ( V_8 ) ;
}
F_252 ( V_8 ) ;
F_97 ( V_482 , V_505 ) ;
}
static int F_261 ( struct V_7 * V_8 , unsigned long V_485 )
{
unsigned long V_508 = V_485 | ( F_6 ( V_8 ) -> V_130 . V_131 ?
V_509 : V_510 ) ;
if ( V_485 & V_394 ) {
if ( ! F_189 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_511 &&
( ( V_485 & F_197 ) != F_197 ) )
return 1 ;
V_8 -> V_110 . V_485 = V_485 ;
if ( V_100 ) {
if ( ! F_256 ( V_8 ) ) {
V_508 &= ~ V_512 ;
V_508 |= V_513 ;
V_508 &= ~ V_514 ;
} else if ( ! ( V_485 & V_512 ) ) {
V_508 &= ~ V_512 ;
}
}
F_97 ( V_458 , V_485 ) ;
F_97 ( V_456 , V_508 ) ;
return 0 ;
}
static void F_243 ( struct V_7 * V_8 ,
struct V_443 * V_463 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_121 ;
if ( V_72 -> V_130 . V_131 && V_107 != V_515 ) {
* V_463 = V_72 -> V_130 . V_450 [ V_107 ] ;
if ( V_107 == V_455
|| V_463 -> V_114 == F_106 ( V_72 , V_107 ) )
return;
V_463 -> V_117 = F_107 ( V_72 , V_107 ) ;
V_463 -> V_114 = F_106 ( V_72 , V_107 ) ;
return;
}
V_463 -> V_117 = F_107 ( V_72 , V_107 ) ;
V_463 -> V_119 = F_108 ( V_72 , V_107 ) ;
V_463 -> V_114 = F_106 ( V_72 , V_107 ) ;
V_121 = F_109 ( V_72 , V_107 ) ;
V_463 -> V_468 = ( V_121 >> 16 ) & 1 ;
V_463 -> type = V_121 & 15 ;
V_463 -> V_183 = ( V_121 >> 4 ) & 1 ;
V_463 -> V_448 = ( V_121 >> 5 ) & 3 ;
V_463 -> V_466 = ! V_463 -> V_468 ;
V_463 -> V_469 = ( V_121 >> 12 ) & 1 ;
V_463 -> V_467 = ( V_121 >> 13 ) & 1 ;
V_463 -> V_465 = ( V_121 >> 14 ) & 1 ;
V_463 -> V_464 = ( V_121 >> 15 ) & 1 ;
}
static T_3 F_266 ( struct V_7 * V_8 , int V_107 )
{
struct V_443 V_183 ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
F_243 ( V_8 , & V_183 , V_107 ) ;
return V_183 . V_117 ;
}
return F_107 ( F_6 ( V_8 ) , V_107 ) ;
}
static int F_267 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_268 ( V_8 ) )
return 0 ;
if ( ! F_128 ( V_8 )
&& ( F_269 ( V_8 ) & V_242 ) )
return 3 ;
if ( ! F_157 ( V_459 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ) {
F_158 ( V_459 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_460 = F_106 ( V_72 , V_445 ) & 3 ;
}
return V_72 -> V_460 ;
}
static T_2 F_245 ( struct V_443 * V_463 )
{
T_2 V_121 ;
if ( V_463 -> V_468 || ! V_463 -> V_466 )
V_121 = 1 << 16 ;
else {
V_121 = V_463 -> type & 15 ;
V_121 |= ( V_463 -> V_183 & 1 ) << 4 ;
V_121 |= ( V_463 -> V_448 & 3 ) << 5 ;
V_121 |= ( V_463 -> V_466 & 1 ) << 7 ;
V_121 |= ( V_463 -> V_469 & 1 ) << 12 ;
V_121 |= ( V_463 -> V_467 & 1 ) << 13 ;
V_121 |= ( V_463 -> V_465 & 1 ) << 14 ;
V_121 |= ( V_463 -> V_464 & 1 ) << 15 ;
}
return V_121 ;
}
static void F_241 ( struct V_7 * V_8 ,
struct V_443 * V_463 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
const struct V_461 * V_462 = & V_116 [ V_107 ] ;
F_104 ( V_72 ) ;
if ( V_107 == V_445 )
F_270 ( V_459 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
if ( V_72 -> V_130 . V_131 && V_107 != V_515 ) {
V_72 -> V_130 . V_450 [ V_107 ] = * V_463 ;
if ( V_107 == V_455 )
F_99 ( V_462 -> V_114 , V_463 -> V_114 ) ;
else if ( V_463 -> V_183 )
F_244 ( V_107 , & V_72 -> V_130 . V_450 [ V_107 ] ) ;
goto V_516;
}
F_97 ( V_462 -> V_117 , V_463 -> V_117 ) ;
F_100 ( V_462 -> V_119 , V_463 -> V_119 ) ;
F_99 ( V_462 -> V_114 , V_463 -> V_114 ) ;
if ( V_432 && ( V_107 != V_515 ) )
V_463 -> type |= 0x1 ;
F_100 ( V_462 -> V_123 , F_245 ( V_463 ) ) ;
V_516:
V_72 -> F_238 |= F_238 ( V_8 ) ;
}
static void F_271 ( struct V_7 * V_8 , int * V_465 , int * V_467 )
{
T_2 V_121 = F_109 ( F_6 ( V_8 ) , V_445 ) ;
* V_465 = ( V_121 >> 14 ) & 1 ;
* V_467 = ( V_121 >> 13 ) & 1 ;
}
static void F_272 ( struct V_7 * V_8 , struct V_163 * V_517 )
{
V_517 -> V_418 = F_92 ( V_518 ) ;
V_517 -> V_168 = F_90 ( V_519 ) ;
}
static void F_273 ( struct V_7 * V_8 , struct V_163 * V_517 )
{
F_100 ( V_518 , V_517 -> V_418 ) ;
F_97 ( V_519 , V_517 -> V_168 ) ;
}
static void F_274 ( struct V_7 * V_8 , struct V_163 * V_517 )
{
V_517 -> V_418 = F_92 ( V_520 ) ;
V_517 -> V_168 = F_90 ( V_521 ) ;
}
static void F_275 ( struct V_7 * V_8 , struct V_163 * V_517 )
{
F_100 ( V_520 , V_517 -> V_418 ) ;
F_97 ( V_521 , V_517 -> V_168 ) ;
}
static bool F_276 ( struct V_7 * V_8 , int V_107 )
{
struct V_443 V_463 ;
T_2 V_121 ;
F_243 ( V_8 , & V_463 , V_107 ) ;
V_463 . V_448 = 0x3 ;
if ( V_107 == V_445 )
V_463 . type = 0x3 ;
V_121 = F_245 ( & V_463 ) ;
if ( V_463 . V_117 != ( V_463 . V_114 << 4 ) )
return false ;
if ( V_463 . V_119 != 0xffff )
return false ;
if ( V_121 != 0xf3 )
return false ;
return true ;
}
static bool F_277 ( struct V_7 * V_8 )
{
struct V_443 V_522 ;
unsigned int V_523 ;
F_243 ( V_8 , & V_522 , V_445 ) ;
V_523 = V_522 . V_114 & V_447 ;
if ( V_522 . V_468 )
return false ;
if ( ~ V_522 . type & ( V_524 | V_525 ) )
return false ;
if ( ! V_522 . V_183 )
return false ;
if ( V_522 . type & V_526 ) {
if ( V_522 . V_448 > V_523 )
return false ;
} else {
if ( V_522 . V_448 != V_523 )
return false ;
}
if ( ! V_522 . V_466 )
return false ;
return true ;
}
static bool F_278 ( struct V_7 * V_8 )
{
struct V_443 V_527 ;
unsigned int V_528 ;
F_243 ( V_8 , & V_527 , V_446 ) ;
V_528 = V_527 . V_114 & V_447 ;
if ( V_527 . V_468 )
return true ;
if ( V_527 . type != 3 && V_527 . type != 7 )
return false ;
if ( ! V_527 . V_183 )
return false ;
if ( V_527 . V_448 != V_528 )
return false ;
if ( ! V_527 . V_466 )
return false ;
return true ;
}
static bool F_279 ( struct V_7 * V_8 , int V_107 )
{
struct V_443 V_463 ;
unsigned int V_529 ;
F_243 ( V_8 , & V_463 , V_107 ) ;
V_529 = V_463 . V_114 & V_447 ;
if ( V_463 . V_468 )
return true ;
if ( ! V_463 . V_183 )
return false ;
if ( ! V_463 . V_466 )
return false ;
if ( ~ V_463 . type & ( V_524 | V_526 ) ) {
if ( V_463 . V_448 < V_529 )
return false ;
}
return true ;
}
static bool F_280 ( struct V_7 * V_8 )
{
struct V_443 V_186 ;
F_243 ( V_8 , & V_186 , V_455 ) ;
if ( V_186 . V_468 )
return false ;
if ( V_186 . V_114 & V_530 )
return false ;
if ( V_186 . type != 3 && V_186 . type != 11 )
return false ;
if ( ! V_186 . V_466 )
return false ;
return true ;
}
static bool F_281 ( struct V_7 * V_8 )
{
struct V_443 V_531 ;
F_243 ( V_8 , & V_531 , V_515 ) ;
if ( V_531 . V_468 )
return true ;
if ( V_531 . V_114 & V_530 )
return false ;
if ( V_531 . type != 2 )
return false ;
if ( ! V_531 . V_466 )
return false ;
return true ;
}
static bool F_282 ( struct V_7 * V_8 )
{
struct V_443 V_522 , V_527 ;
F_243 ( V_8 , & V_522 , V_445 ) ;
F_243 ( V_8 , & V_527 , V_446 ) ;
return ( ( V_522 . V_114 & V_447 ) ==
( V_527 . V_114 & V_447 ) ) ;
}
static bool F_239 ( struct V_7 * V_8 )
{
if ( V_432 )
return true ;
if ( ! F_268 ( V_8 ) || ( F_156 ( V_8 ) & V_242 ) ) {
if ( ! F_276 ( V_8 , V_445 ) )
return false ;
if ( ! F_276 ( V_8 , V_446 ) )
return false ;
if ( ! F_276 ( V_8 , V_452 ) )
return false ;
if ( ! F_276 ( V_8 , V_451 ) )
return false ;
if ( ! F_276 ( V_8 , V_453 ) )
return false ;
if ( ! F_276 ( V_8 , V_454 ) )
return false ;
} else {
if ( ! F_282 ( V_8 ) )
return false ;
if ( ! F_277 ( V_8 ) )
return false ;
if ( ! F_278 ( V_8 ) )
return false ;
if ( ! F_279 ( V_8 , V_452 ) )
return false ;
if ( ! F_279 ( V_8 , V_451 ) )
return false ;
if ( ! F_279 ( V_8 , V_453 ) )
return false ;
if ( ! F_279 ( V_8 , V_454 ) )
return false ;
if ( ! F_280 ( V_8 ) )
return false ;
if ( ! F_281 ( V_8 ) )
return false ;
}
return true ;
}
static int F_283 ( struct V_17 * V_17 )
{
T_13 V_532 ;
T_4 V_179 = 0 ;
int V_533 , V_534 , V_108 = 0 ;
V_534 = F_284 ( & V_17 -> V_535 ) ;
V_532 = V_17 -> V_110 . V_470 >> V_18 ;
V_533 = F_285 ( V_17 , V_532 , 0 , V_417 ) ;
if ( V_533 < 0 )
goto V_516;
V_179 = V_536 + V_537 ;
V_533 = F_286 ( V_17 , V_532 ++ , & V_179 ,
V_538 , sizeof( T_4 ) ) ;
if ( V_533 < 0 )
goto V_516;
V_533 = F_285 ( V_17 , V_532 ++ , 0 , V_417 ) ;
if ( V_533 < 0 )
goto V_516;
V_533 = F_285 ( V_17 , V_532 , 0 , V_417 ) ;
if ( V_533 < 0 )
goto V_516;
V_179 = ~ 0 ;
V_533 = F_286 ( V_17 , V_532 , & V_179 ,
V_473 - 2 * V_417 - 1 ,
sizeof( T_6 ) ) ;
if ( V_533 < 0 )
goto V_516;
V_108 = 1 ;
V_516:
F_287 ( & V_17 -> V_535 , V_534 ) ;
return V_108 ;
}
static int F_288 ( struct V_17 * V_17 )
{
int V_74 , V_534 , V_533 , V_108 ;
T_14 V_539 ;
T_2 V_267 ;
if ( ! V_100 )
return 1 ;
if ( F_98 ( ! V_17 -> V_110 . V_540 ) ) {
F_67 ( V_88 L_18
L_19 ) ;
return 0 ;
}
if ( F_289 ( V_17 -> V_110 . V_541 ) )
return 1 ;
V_108 = 0 ;
V_539 = V_17 -> V_110 . V_507 >> V_18 ;
V_534 = F_284 ( & V_17 -> V_535 ) ;
V_533 = F_285 ( V_17 , V_539 , 0 , V_417 ) ;
if ( V_533 < 0 )
goto V_516;
for ( V_74 = 0 ; V_74 < V_542 ; V_74 ++ ) {
V_267 = ( V_74 << 22 ) + ( V_543 | V_544 | V_545 |
V_546 | V_547 | V_548 ) ;
V_533 = F_286 ( V_17 , V_539 ,
& V_267 , V_74 * sizeof( V_267 ) , sizeof( V_267 ) ) ;
if ( V_533 < 0 )
goto V_516;
}
V_17 -> V_110 . V_541 = true ;
V_108 = 1 ;
V_516:
F_287 ( & V_17 -> V_535 , V_534 ) ;
return V_108 ;
}
static void F_290 ( int V_107 )
{
const struct V_461 * V_462 = & V_116 [ V_107 ] ;
unsigned int V_121 ;
F_99 ( V_462 -> V_114 , 0 ) ;
F_97 ( V_462 -> V_117 , 0 ) ;
F_100 ( V_462 -> V_119 , 0xffff ) ;
V_121 = 0x93 ;
if ( V_107 == V_445 )
V_121 |= 0x08 ;
F_100 ( V_462 -> V_123 , V_121 ) ;
}
static int F_291 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_549 V_550 ;
int V_533 = 0 ;
F_292 ( & V_17 -> V_551 ) ;
if ( V_17 -> V_110 . V_552 )
goto V_516;
V_550 . V_553 = V_554 ;
V_550 . V_449 = 0 ;
V_550 . V_555 = 0xfee00000ULL ;
V_550 . V_556 = V_417 ;
V_533 = F_293 ( V_17 , & V_550 ) ;
if ( V_533 )
goto V_516;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_533 = - V_557 ;
goto V_516;
}
V_17 -> V_110 . V_552 = V_15 ;
V_516:
F_294 ( & V_17 -> V_551 ) ;
return V_533 ;
}
static int F_295 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_549 V_550 ;
int V_533 = 0 ;
F_292 ( & V_17 -> V_551 ) ;
if ( V_17 -> V_110 . V_540 )
goto V_516;
V_550 . V_553 = V_558 ;
V_550 . V_449 = 0 ;
V_550 . V_555 =
V_17 -> V_110 . V_507 ;
V_550 . V_556 = V_417 ;
V_533 = F_293 ( V_17 , & V_550 ) ;
if ( V_533 )
goto V_516;
V_15 = F_11 ( V_17 , V_17 -> V_110 . V_507 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_533 = - V_557 ;
goto V_516;
}
V_17 -> V_110 . V_540 = V_15 ;
V_516:
F_294 ( & V_17 -> V_551 ) ;
return V_533 ;
}
static void F_296 ( struct V_6 * V_72 )
{
int V_52 ;
V_72 -> V_52 = 0 ;
if ( ! V_430 )
return;
F_297 ( & V_559 ) ;
V_52 = F_298 ( V_560 , V_561 ) ;
if ( V_52 < V_561 ) {
V_72 -> V_52 = V_52 ;
F_158 ( V_52 , V_560 ) ;
}
F_299 ( & V_559 ) ;
}
static void F_300 ( struct V_6 * V_72 )
{
if ( ! V_430 )
return;
F_297 ( & V_559 ) ;
if ( V_72 -> V_52 != 0 )
F_270 ( V_72 -> V_52 , V_560 ) ;
F_299 ( & V_559 ) ;
}
static void F_301 ( unsigned long * V_268 ,
T_2 V_73 , int type )
{
int V_562 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_563 )
F_270 ( V_73 , V_268 + 0x000 / V_562 ) ;
if ( type & V_564 )
F_270 ( V_73 , V_268 + 0x800 / V_562 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_563 )
F_270 ( V_73 , V_268 + 0x400 / V_562 ) ;
if ( type & V_564 )
F_270 ( V_73 , V_268 + 0xc00 / V_562 ) ;
}
}
static void F_302 ( unsigned long * V_268 ,
T_2 V_73 , int type )
{
int V_562 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_563 )
F_158 ( V_73 , V_268 + 0x000 / V_562 ) ;
if ( type & V_564 )
F_158 ( V_73 , V_268 + 0x800 / V_562 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_563 )
F_158 ( V_73 , V_268 + 0x400 / V_562 ) ;
if ( type & V_564 )
F_158 ( V_73 , V_268 + 0xc00 / V_562 ) ;
}
}
static void F_303 ( T_2 V_73 , bool V_565 )
{
if ( ! V_565 )
F_301 ( V_273 ,
V_73 , V_563 | V_564 ) ;
F_301 ( V_272 ,
V_73 , V_563 | V_564 ) ;
}
static void F_304 ( T_2 V_73 )
{
F_302 ( V_271 ,
V_73 , V_563 ) ;
F_302 ( V_270 ,
V_73 , V_563 ) ;
}
static void F_305 ( T_2 V_73 )
{
F_301 ( V_271 ,
V_73 , V_563 ) ;
F_301 ( V_270 ,
V_73 , V_563 ) ;
}
static void F_306 ( T_2 V_73 )
{
F_301 ( V_271 ,
V_73 , V_564 ) ;
F_301 ( V_270 ,
V_73 , V_564 ) ;
}
static int F_307 ( struct V_17 * V_17 )
{
return V_437 && F_25 ( V_17 ) ;
}
static void F_308 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_533 ;
if ( F_5 ( V_4 , & V_72 -> V_1 ) )
return;
V_533 = F_1 ( & V_72 -> V_1 ) ;
F_143 ( V_566 , V_8 ) ;
#ifdef F_309
if ( ! V_533 && ( V_8 -> V_567 == V_568 ) )
V_269 -> V_569 ( F_310 ( V_8 -> V_90 ) ,
V_570 ) ;
else
#endif
F_311 ( V_8 ) ;
}
static void F_312 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_72 -> V_1 ) )
return;
F_313 ( V_8 , V_72 -> V_1 . V_5 ) ;
}
static void V_441 ( struct V_7 * V_8 )
{
return;
}
static void F_314 ( struct V_6 * V_72 )
{
T_2 V_571 , V_572 ;
unsigned long V_573 ;
struct V_163 V_517 ;
F_97 ( V_574 , F_315 () & ~ V_224 ) ;
F_97 ( V_575 , F_211 () ) ;
F_97 ( V_576 , F_316 () ) ;
F_99 ( V_577 , V_578 ) ;
#ifdef F_94
F_99 ( V_579 , 0 ) ;
F_99 ( V_580 , 0 ) ;
#else
F_99 ( V_579 , V_581 ) ;
F_99 ( V_580 , V_581 ) ;
#endif
F_99 ( V_582 , V_581 ) ;
F_99 ( V_583 , V_169 * 8 ) ;
F_317 ( & V_517 ) ;
F_97 ( V_584 , V_517 . V_168 ) ;
V_72 -> V_585 = V_517 . V_168 ;
F_97 ( V_586 , V_587 ) ;
F_191 ( V_368 , V_571 , V_572 ) ;
F_100 ( V_588 , V_571 ) ;
F_55 ( V_370 , V_573 ) ;
F_97 ( V_589 , V_573 ) ;
if ( V_29 . V_421 & V_415 ) {
F_191 ( V_375 , V_571 , V_572 ) ;
F_101 ( V_590 , V_571 | ( ( T_3 ) V_572 << 32 ) ) ;
}
}
static void F_318 ( struct V_6 * V_72 )
{
V_72 -> V_8 . V_110 . V_484 = V_591 ;
if ( V_100 )
V_72 -> V_8 . V_110 . V_484 |= V_592 ;
if ( F_111 ( & V_72 -> V_8 ) )
V_72 -> V_8 . V_110 . V_484 &=
~ F_9 ( & V_72 -> V_8 ) -> V_233 ;
F_97 ( V_593 , ~ V_72 -> V_8 . V_110 . V_484 ) ;
}
static T_2 F_319 ( struct V_6 * V_72 )
{
T_2 V_39 = V_29 . V_39 ;
if ( ! F_307 ( V_72 -> V_8 . V_17 ) )
V_39 &= ~ V_40 ;
return V_39 ;
}
static T_2 F_320 ( struct V_6 * V_72 )
{
T_2 V_594 = V_29 . V_30 ;
if ( ! F_24 ( V_72 -> V_8 . V_17 ) ) {
V_594 &= ~ V_32 ;
#ifdef F_94
V_594 |= V_326 |
V_325 ;
#endif
}
if ( ! V_100 )
V_594 |= V_324 |
V_323 |
V_321 ;
return V_594 ;
}
static T_2 F_321 ( struct V_6 * V_72 )
{
T_2 V_594 = V_29 . V_34 ;
if ( ! F_48 ( V_72 -> V_8 . V_17 ) )
V_594 &= ~ V_35 ;
if ( V_72 -> V_52 == 0 )
V_594 &= ~ V_59 ;
if ( ! V_100 ) {
V_594 &= ~ V_55 ;
V_432 = 0 ;
V_594 &= ~ V_61 ;
}
if ( ! V_432 )
V_594 &= ~ V_56 ;
if ( ! V_436 )
V_594 &= ~ V_57 ;
if ( ! F_307 ( V_72 -> V_8 . V_17 ) )
V_594 &= ~ ( V_37 |
V_38 ) ;
V_594 &= ~ V_36 ;
V_594 &= ~ V_67 ;
return V_594 ;
}
static void F_322 ( void )
{
F_323 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_324 ( struct V_6 * V_72 )
{
#ifdef F_94
unsigned long V_595 ;
#endif
int V_74 ;
F_101 ( V_596 , F_66 ( V_597 ) ) ;
F_101 ( V_598 , F_66 ( V_599 ) ) ;
if ( V_431 ) {
F_101 ( V_600 , F_66 ( V_601 ) ) ;
F_101 ( V_602 , F_66 ( V_603 ) ) ;
}
if ( F_22 () )
F_101 ( V_274 , F_66 ( V_273 ) ) ;
F_101 ( V_604 , - 1ull ) ;
F_100 ( V_605 , F_319 ( V_72 ) ) ;
F_100 ( V_494 , F_320 ( V_72 ) ) ;
if ( F_26 () ) {
F_100 ( V_606 ,
F_321 ( V_72 ) ) ;
}
if ( F_307 ( V_72 -> V_8 . V_17 ) ) {
F_101 ( V_607 , 0 ) ;
F_101 ( V_608 , 0 ) ;
F_101 ( V_609 , 0 ) ;
F_101 ( V_610 , 0 ) ;
F_99 ( V_611 , 0 ) ;
F_101 ( V_612 , V_570 ) ;
F_101 ( V_613 , F_66 ( ( & V_72 -> V_1 ) ) ) ;
}
if ( V_436 ) {
F_100 ( V_614 , V_436 ) ;
F_100 ( V_615 , V_616 ) ;
}
F_100 ( V_617 , 0 ) ;
F_100 ( V_618 , 0 ) ;
F_100 ( V_619 , 0 ) ;
F_99 ( V_193 , 0 ) ;
F_99 ( V_197 , 0 ) ;
F_314 ( V_72 ) ;
#ifdef F_94
F_55 ( V_203 , V_595 ) ;
F_97 ( V_202 , V_595 ) ;
F_55 ( V_205 , V_595 ) ;
F_97 ( V_204 , V_595 ) ;
#else
F_97 ( V_202 , 0 ) ;
F_97 ( V_204 , 0 ) ;
#endif
F_100 ( V_620 , 0 ) ;
F_100 ( V_152 , 0 ) ;
F_101 ( V_621 , F_66 ( V_72 -> V_138 . V_150 ) ) ;
F_100 ( V_151 , 0 ) ;
F_101 ( V_622 , F_66 ( V_72 -> V_138 . V_149 ) ) ;
if ( V_29 . V_376 & V_314 ) {
T_2 V_623 , V_624 ;
T_3 V_625 ;
F_191 ( V_375 , V_623 , V_624 ) ;
V_625 = V_623 | ( ( T_3 ) V_624 << 32 ) ;
F_101 ( V_377 , V_625 ) ;
V_72 -> V_8 . V_110 . V_378 = V_625 ;
}
for ( V_74 = 0 ; V_74 < V_626 ; ++ V_74 ) {
T_2 V_78 = V_76 [ V_74 ] ;
T_2 V_627 , V_628 ;
int V_629 = V_72 -> V_75 ;
if ( F_325 ( V_78 , & V_627 , & V_628 ) < 0 )
continue;
if ( F_326 ( V_78 , V_627 , V_628 ) < 0 )
continue;
V_72 -> V_77 [ V_629 ] . V_78 = V_74 ;
V_72 -> V_77 [ V_629 ] . V_179 = 0 ;
V_72 -> V_77 [ V_629 ] . V_104 = - 1ull ;
++ V_72 -> V_75 ;
}
F_100 ( V_137 , V_29 . V_421 ) ;
F_100 ( V_136 , V_29 . V_376 ) ;
F_97 ( V_228 , ~ 0UL ) ;
F_318 ( V_72 ) ;
return 0 ;
}
static void F_327 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_73 ;
V_72 -> V_130 . V_131 = 0 ;
V_72 -> V_630 = 0 ;
V_72 -> V_8 . V_110 . V_383 [ V_631 ] = F_328 () ;
F_329 ( & V_72 -> V_8 , 0 ) ;
V_73 = 0xfee00000 | V_632 ;
if ( F_330 ( & V_72 -> V_8 ) )
V_73 |= V_633 ;
F_331 ( & V_72 -> V_8 , V_73 ) ;
F_104 ( V_72 ) ;
F_290 ( V_445 ) ;
F_99 ( V_634 , 0xf000 ) ;
F_100 ( V_635 , 0xffff0000 ) ;
F_290 ( V_452 ) ;
F_290 ( V_451 ) ;
F_290 ( V_453 ) ;
F_290 ( V_454 ) ;
F_290 ( V_446 ) ;
F_99 ( V_636 , 0 ) ;
F_97 ( V_471 , 0 ) ;
F_100 ( V_472 , 0xffff ) ;
F_100 ( V_474 , 0x008b ) ;
F_99 ( V_637 , 0 ) ;
F_97 ( V_638 , 0 ) ;
F_100 ( V_639 , 0xffff ) ;
F_100 ( V_640 , 0x00082 ) ;
F_100 ( V_369 , 0 ) ;
F_97 ( V_372 , 0 ) ;
F_97 ( V_371 , 0 ) ;
F_97 ( V_239 , 0x02 ) ;
F_164 ( V_8 , 0xfff0 ) ;
F_97 ( V_521 , 0 ) ;
F_100 ( V_520 , 0xffff ) ;
F_97 ( V_519 , 0 ) ;
F_100 ( V_518 , 0xffff ) ;
F_100 ( V_641 , V_642 ) ;
F_100 ( V_244 , 0 ) ;
F_100 ( V_643 , 0 ) ;
F_101 ( V_644 , 0 ) ;
F_175 ( V_72 ) ;
F_100 ( V_264 , 0 ) ;
if ( F_23 () ) {
F_101 ( V_645 , 0 ) ;
if ( F_24 ( V_72 -> V_8 . V_17 ) )
F_101 ( V_645 ,
F_66 ( V_72 -> V_8 . V_110 . V_269 -> V_383 ) ) ;
F_100 ( V_646 , 0 ) ;
}
if ( F_48 ( V_72 -> V_8 . V_17 ) )
F_101 ( V_647 ,
F_332 ( V_72 -> V_8 . V_17 -> V_110 . V_552 ) ) ;
if ( F_307 ( V_8 -> V_17 ) )
memset ( & V_72 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_72 -> V_52 != 0 )
F_99 ( V_648 , V_72 -> V_52 ) ;
V_72 -> V_8 . V_110 . V_222 = V_649 | V_650 | V_651 ;
F_263 ( & V_72 -> V_8 , F_333 ( V_8 ) ) ;
F_261 ( & V_72 -> V_8 , 0 ) ;
F_248 ( & V_72 -> V_8 , 0 ) ;
F_150 ( & V_72 -> V_8 ) ;
F_110 ( & V_72 -> V_8 ) ;
F_87 ( V_72 ) ;
}
static bool F_334 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_303 ;
}
static bool F_335 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_304 ;
}
static int F_336 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( F_111 ( V_8 ) && F_334 ( V_8 ) )
return - V_395 ;
V_69 = F_92 ( V_494 ) ;
V_69 |= V_319 ;
F_100 ( V_494 , V_69 ) ;
return 0 ;
}
static int F_337 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () )
return F_336 ( V_8 ) ;
if ( F_92 ( V_244 ) & V_245 )
return F_336 ( V_8 ) ;
V_69 = F_92 ( V_494 ) ;
V_69 |= V_652 ;
F_100 ( V_494 , V_69 ) ;
return 0 ;
}
static void F_338 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_15 V_653 ;
int V_654 = V_8 -> V_110 . V_655 . V_148 ;
F_339 ( V_654 ) ;
++ V_8 -> V_210 . V_656 ;
if ( V_72 -> V_130 . V_131 ) {
int V_258 = 0 ;
if ( V_8 -> V_110 . V_655 . V_657 )
V_258 = V_8 -> V_110 . V_259 ;
if ( F_169 ( V_8 , V_654 , V_258 ) != V_260 )
F_143 ( V_261 , V_8 ) ;
return;
}
V_653 = V_654 | V_22 ;
if ( V_8 -> V_110 . V_655 . V_657 ) {
V_653 |= V_658 ;
F_100 ( V_262 ,
V_72 -> V_8 . V_110 . V_259 ) ;
} else
V_653 |= V_27 ;
F_100 ( V_264 , V_653 ) ;
}
static void F_340 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( F_111 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_72 -> V_630 = 1 ;
V_72 -> V_659 = 0 ;
}
++ V_8 -> V_210 . V_660 ;
V_72 -> V_661 = false ;
if ( V_72 -> V_130 . V_131 ) {
if ( F_169 ( V_8 , V_662 , 0 ) != V_260 )
F_143 ( V_261 , V_8 ) ;
return;
}
F_100 ( V_264 ,
V_663 | V_22 | V_662 ) ;
}
static bool F_341 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_630 ;
if ( F_6 ( V_8 ) -> V_661 )
return false ;
return F_92 ( V_244 ) & V_664 ;
}
static void F_342 ( struct V_7 * V_8 , bool V_665 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_72 -> V_630 != V_665 ) {
V_72 -> V_630 = V_665 ;
V_72 -> V_659 = 0 ;
}
} else {
V_72 -> V_661 = ! V_665 ;
if ( V_665 )
F_103 ( V_244 ,
V_664 ) ;
else
F_102 ( V_244 ,
V_664 ) ;
}
}
static int F_343 ( struct V_7 * V_8 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_255 )
return 0 ;
if ( F_335 ( V_8 ) ) {
F_166 ( V_8 ) ;
V_12 -> V_666 = V_667 ;
V_12 -> V_668 = V_662 |
V_663 | V_22 ;
V_8 -> V_110 . V_669 = 0 ;
F_342 ( V_8 , true ) ;
return 0 ;
}
}
if ( ! F_52 () && F_6 ( V_8 ) -> V_630 )
return 0 ;
return ! ( F_92 ( V_244 ) &
( V_247 | V_245
| V_664 ) ) ;
}
static int F_344 ( struct V_7 * V_8 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_255 )
return 0 ;
if ( F_334 ( V_8 ) ) {
F_166 ( V_8 ) ;
V_12 -> V_666 =
V_670 ;
V_12 -> V_668 = 0 ;
}
}
return ( F_90 ( V_239 ) & V_671 ) &&
! ( F_92 ( V_244 ) &
( V_245 | V_247 ) ) ;
}
static int F_345 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_108 ;
struct V_549 V_672 = {
. V_553 = V_673 ,
. V_555 = V_16 ,
. V_556 = V_417 * 3 ,
. V_449 = 0 ,
} ;
V_108 = F_346 ( V_17 , & V_672 ) ;
if ( V_108 )
return V_108 ;
V_17 -> V_110 . V_470 = V_16 ;
if ( ! F_283 ( V_17 ) )
return - V_428 ;
return 0 ;
}
static bool F_347 ( struct V_7 * V_8 , int V_674 )
{
switch ( V_674 ) {
case V_129 :
F_6 ( V_8 ) -> V_8 . V_110 . V_259 =
F_92 ( V_251 ) ;
if ( V_8 -> V_126 & V_128 )
return false ;
case V_125 :
if ( V_8 -> V_126 &
( V_675 | V_676 ) )
return false ;
case V_677 :
case V_678 :
case V_679 :
case V_26 :
case V_680 :
case V_681 :
case V_347 :
case V_682 :
return true ;
break;
}
return false ;
}
static int F_348 ( struct V_7 * V_8 ,
int V_674 , T_2 V_683 )
{
if ( ( ( V_674 == V_347 ) || ( V_674 == V_681 ) ) && V_683 == 0 ) {
if ( F_349 ( V_8 , 0 ) == V_260 ) {
if ( V_8 -> V_110 . V_684 ) {
V_8 -> V_110 . V_684 = 0 ;
return F_350 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_351 ( V_8 , V_674 ) ;
return 1 ;
}
static void F_352 ( void )
{
#if F_353 ( V_685 ) && F_353 ( F_94 )
struct V_686 V_383 = {
. V_522 = 3 ,
. V_449 = V_671 ,
} ;
F_354 ( & V_383 , 0 ) ;
#endif
}
static int F_355 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_356 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_687 * V_687 = V_8 -> V_688 ;
T_2 V_19 , V_689 , V_253 ;
unsigned long V_690 , V_250 , V_691 ;
T_2 V_692 ;
enum V_693 V_694 ;
V_692 = V_72 -> V_695 ;
V_19 = V_72 -> V_696 ;
if ( F_21 ( V_19 ) )
return F_355 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_663 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_150 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_694 = F_349 ( V_8 , V_697 ) ;
if ( V_694 != V_260 )
F_351 ( V_8 , V_26 ) ;
return 1 ;
}
V_253 = 0 ;
if ( V_19 & V_257 )
V_253 = F_92 ( V_698 ) ;
if ( ( V_692 & V_699 ) &&
! ( F_17 ( V_19 ) && ! ( V_253 & V_700 ) ) ) {
V_8 -> V_688 -> V_701 = V_702 ;
V_8 -> V_688 -> V_703 . V_704 = V_705 ;
V_8 -> V_688 -> V_703 . V_706 = 2 ;
V_8 -> V_688 -> V_703 . V_179 [ 0 ] = V_692 ;
V_8 -> V_688 -> V_703 . V_179 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_357 ( V_100 ) ;
V_690 = F_90 ( V_707 ) ;
F_358 ( V_690 , V_253 ) ;
if ( F_359 ( V_8 ) )
F_360 ( V_8 , V_690 ) ;
return F_361 ( V_8 , V_690 , V_253 , NULL , 0 ) ;
}
V_689 = V_19 & V_21 ;
if ( V_72 -> V_130 . V_131 && F_347 ( V_8 , V_689 ) )
return F_348 ( V_8 , V_689 , V_253 ) ;
switch ( V_689 ) {
case V_125 :
V_691 = F_90 ( V_707 ) ;
if ( ! ( V_8 -> V_126 &
( V_675 | V_676 ) ) ) {
V_8 -> V_110 . V_691 = V_691 | V_708 ;
F_351 ( V_8 , V_125 ) ;
return 1 ;
}
V_687 -> V_709 . V_110 . V_691 = V_691 | V_708 ;
V_687 -> V_709 . V_110 . V_710 = F_90 ( V_711 ) ;
case V_129 :
V_72 -> V_8 . V_110 . V_259 =
F_92 ( V_251 ) ;
V_687 -> V_701 = V_712 ;
V_250 = F_163 ( V_8 ) ;
V_687 -> V_709 . V_110 . V_713 = F_90 ( V_635 ) + V_250 ;
V_687 -> V_709 . V_110 . V_714 = V_689 ;
break;
default:
V_687 -> V_701 = V_715 ;
V_687 -> V_716 . V_714 = V_689 ;
V_687 -> V_716 . V_253 = V_253 ;
break;
}
return 0 ;
}
static int F_362 ( struct V_7 * V_8 )
{
++ V_8 -> V_210 . V_717 ;
return 1 ;
}
static int F_363 ( struct V_7 * V_8 )
{
V_8 -> V_688 -> V_701 = V_718 ;
return 0 ;
}
static int F_364 ( struct V_7 * V_8 )
{
unsigned long V_719 ;
int V_418 , V_720 , string ;
unsigned V_721 ;
V_719 = F_90 ( V_707 ) ;
string = ( V_719 & 16 ) != 0 ;
V_720 = ( V_719 & 8 ) != 0 ;
++ V_8 -> V_210 . V_722 ;
if ( string || V_720 )
return F_349 ( V_8 , 0 ) == V_260 ;
V_721 = V_719 >> 16 ;
V_418 = ( V_719 & 7 ) + 1 ;
F_162 ( V_8 ) ;
return F_365 ( V_8 , V_418 , V_721 ) ;
}
static void
F_366 ( struct V_7 * V_8 , unsigned char * V_723 )
{
V_723 [ 0 ] = 0x0f ;
V_723 [ 1 ] = 0x01 ;
V_723 [ 2 ] = 0xc1 ;
}
static int F_367 ( struct V_7 * V_8 , unsigned long V_724 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_725 = V_724 ;
V_724 = ( V_724 & ~ V_12 -> V_227 ) |
( V_12 -> V_230 & V_12 -> V_227 ) ;
if ( ( V_724 & F_196 ) != F_196 )
return 1 ;
if ( F_368 ( V_8 , V_724 ) )
return 1 ;
F_97 ( V_235 , V_725 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_511 &&
( ( V_724 & F_196 ) != F_196 ) )
return 1 ;
return F_368 ( V_8 , V_724 ) ;
}
}
static int F_369 ( struct V_7 * V_8 , unsigned long V_724 )
{
if ( F_111 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_725 = V_724 ;
V_724 = ( V_724 & ~ V_12 -> V_233 ) |
( V_12 -> V_232 & V_12 -> V_233 ) ;
if ( F_370 ( V_8 , V_724 ) )
return 1 ;
F_97 ( V_458 , V_725 ) ;
return 0 ;
} else
return F_370 ( V_8 , V_724 ) ;
}
static void F_371 ( struct V_7 * V_8 )
{
if ( F_111 ( V_8 ) ) {
F_97 ( V_235 ,
F_90 ( V_235 ) & ~ V_224 ) ;
V_8 -> V_110 . V_222 &= ~ V_224 ;
} else
F_263 ( V_8 , F_151 ( V_8 , ~ V_224 ) ) ;
}
static int F_372 ( struct V_7 * V_8 )
{
unsigned long V_719 , V_724 ;
int V_726 ;
int V_381 ;
int V_727 ;
V_719 = F_90 ( V_707 ) ;
V_726 = V_719 & 15 ;
V_381 = ( V_719 >> 8 ) & 15 ;
switch ( ( V_719 >> 4 ) & 3 ) {
case 0 :
V_724 = F_373 ( V_8 , V_381 ) ;
F_374 ( V_726 , V_724 ) ;
switch ( V_726 ) {
case 0 :
V_727 = F_367 ( V_8 , V_724 ) ;
F_375 ( V_8 , V_727 ) ;
return 1 ;
case 3 :
V_727 = F_376 ( V_8 , V_724 ) ;
F_375 ( V_8 , V_727 ) ;
return 1 ;
case 4 :
V_727 = F_369 ( V_8 , V_724 ) ;
F_375 ( V_8 , V_727 ) ;
return 1 ;
case 8 : {
T_6 V_728 = F_377 ( V_8 ) ;
T_6 V_729 = F_373 ( V_8 , V_381 ) ;
V_727 = F_329 ( V_8 , V_729 ) ;
F_375 ( V_8 , V_727 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_728 <= V_729 )
return 1 ;
V_8 -> V_688 -> V_701 = V_730 ;
return 0 ;
}
}
break;
case 2 :
F_371 ( V_8 ) ;
F_374 ( 0 , F_333 ( V_8 ) ) ;
F_162 ( V_8 ) ;
F_150 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_726 ) {
case 3 :
V_724 = F_265 ( V_8 ) ;
F_378 ( V_8 , V_381 , V_724 ) ;
F_379 ( V_726 , V_724 ) ;
F_162 ( V_8 ) ;
return 1 ;
case 8 :
V_724 = F_377 ( V_8 ) ;
F_378 ( V_8 , V_381 , V_724 ) ;
F_379 ( V_726 , V_724 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_724 = ( V_719 >> V_731 ) & 0x0f ;
F_374 ( 0 , ( F_333 ( V_8 ) & ~ 0xful ) | V_724 ) ;
F_380 ( V_8 , V_724 ) ;
F_162 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_688 -> V_701 = 0 ;
F_381 ( V_8 , L_20 ,
( int ) ( V_719 >> 4 ) & 3 , V_726 ) ;
return 0 ;
}
static int F_382 ( struct V_7 * V_8 )
{
unsigned long V_719 ;
int V_732 , V_381 ;
if ( ! F_383 ( V_8 , 0 ) )
return 1 ;
V_732 = F_90 ( V_711 ) ;
if ( V_732 & V_733 ) {
if ( V_8 -> V_126 & V_676 ) {
V_8 -> V_688 -> V_709 . V_110 . V_691 = V_8 -> V_110 . V_691 ;
V_8 -> V_688 -> V_709 . V_110 . V_710 = V_732 ;
V_8 -> V_688 -> V_709 . V_110 . V_713 =
F_90 ( V_635 ) +
F_90 ( V_386 ) ;
V_8 -> V_688 -> V_709 . V_110 . V_714 = V_125 ;
V_8 -> V_688 -> V_701 = V_712 ;
return 0 ;
} else {
V_8 -> V_110 . V_710 &= ~ V_733 ;
V_8 -> V_110 . V_691 |= V_734 ;
F_97 ( V_711 , V_8 -> V_110 . V_710 ) ;
F_351 ( V_8 , V_125 ) ;
return 1 ;
}
}
V_719 = F_90 ( V_707 ) ;
V_732 = V_719 & V_735 ;
V_381 = F_384 ( V_719 ) ;
if ( V_719 & V_736 ) {
unsigned long V_724 ;
if ( ! F_385 ( V_8 , V_732 , & V_724 ) )
F_378 ( V_8 , V_381 , V_724 ) ;
} else
F_386 ( V_8 , V_732 , V_8 -> V_110 . V_383 [ V_381 ] ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static void F_387 ( struct V_7 * V_8 , unsigned long V_724 )
{
F_97 ( V_711 , V_724 ) ;
}
static int F_388 ( struct V_7 * V_8 )
{
F_389 ( V_8 ) ;
return 1 ;
}
static int F_390 ( struct V_7 * V_8 )
{
T_2 V_297 = V_8 -> V_110 . V_383 [ V_737 ] ;
T_3 V_179 ;
if ( F_199 ( V_8 , V_297 , & V_179 ) ) {
F_391 ( V_297 ) ;
F_392 ( V_8 , 0 ) ;
return 1 ;
}
F_393 ( V_297 , V_179 ) ;
V_8 -> V_110 . V_383 [ V_738 ] = V_179 & - 1u ;
V_8 -> V_110 . V_383 [ V_631 ] = ( V_179 >> 32 ) & - 1u ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_394 ( struct V_7 * V_8 )
{
struct V_373 V_73 ;
T_2 V_297 = V_8 -> V_110 . V_383 [ V_737 ] ;
T_3 V_179 = ( V_8 -> V_110 . V_383 [ V_738 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_110 . V_383 [ V_631 ] & - 1u ) << 32 ) ;
V_73 . V_179 = V_179 ;
V_73 . V_78 = V_297 ;
V_73 . V_739 = false ;
if ( F_201 ( V_8 , & V_73 ) != 0 ) {
F_395 ( V_297 , V_179 ) ;
F_392 ( V_8 , 0 ) ;
return 1 ;
}
F_396 ( V_297 , V_179 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_397 ( struct V_7 * V_8 )
{
F_143 ( V_566 , V_8 ) ;
return 1 ;
}
static int F_398 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_92 ( V_494 ) ;
V_69 &= ~ V_319 ;
F_100 ( V_494 , V_69 ) ;
F_143 ( V_566 , V_8 ) ;
++ V_8 -> V_210 . V_740 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_688 -> V_741 &&
! F_399 ( V_8 ) ) {
V_8 -> V_688 -> V_701 = V_742 ;
return 0 ;
}
return 1 ;
}
static int F_400 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
return F_350 ( V_8 ) ;
}
static int F_401 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
F_402 ( V_8 ) ;
return 1 ;
}
static int F_403 ( struct V_7 * V_8 )
{
return F_349 ( V_8 , 0 ) == V_260 ;
}
static int F_404 ( struct V_7 * V_8 )
{
unsigned long V_719 = F_90 ( V_707 ) ;
F_405 ( V_8 , V_719 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_406 ( struct V_7 * V_8 )
{
int V_727 ;
V_727 = F_407 ( V_8 ) ;
F_375 ( V_8 , V_727 ) ;
return 1 ;
}
static int F_408 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
F_409 ( V_8 ) ;
return 1 ;
}
static int F_410 ( struct V_7 * V_8 )
{
T_3 V_743 = F_411 ( V_8 ) ;
T_2 V_78 = F_373 ( V_8 , V_737 ) ;
if ( F_412 ( V_8 , V_78 , V_743 ) == 0 )
F_162 ( V_8 ) ;
return 1 ;
}
static int F_413 ( struct V_7 * V_8 )
{
if ( F_289 ( V_744 ) ) {
unsigned long V_719 = F_90 ( V_707 ) ;
int V_745 , V_290 ;
V_745 = V_719 & V_746 ;
V_290 = V_719 & V_747 ;
if ( ( V_745 == V_748 ) &&
( V_290 == V_749 ) ) {
F_414 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
}
return F_349 ( V_8 , 0 ) == V_260 ;
}
static int F_415 ( struct V_7 * V_8 )
{
unsigned long V_719 = F_90 ( V_707 ) ;
int V_4 = V_719 & 0xff ;
F_416 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_417 ( struct V_7 * V_8 )
{
unsigned long V_719 = F_90 ( V_707 ) ;
T_2 V_290 = V_719 & 0xfff ;
F_418 ( V_8 , V_290 ) ;
return 1 ;
}
static int F_419 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_719 ;
bool V_252 = false ;
T_2 V_253 = 0 ;
T_4 V_750 ;
int V_751 , type , V_752 , V_753 ;
V_752 = ( V_72 -> V_695 & V_699 ) ;
V_753 = ( V_72 -> V_695 & V_754 ) ;
type = ( V_72 -> V_695 & V_755 ) ;
V_719 = F_90 ( V_707 ) ;
V_751 = ( T_2 ) V_719 >> 30 ;
if ( V_751 == V_756 && V_752 ) {
switch ( type ) {
case V_663 :
V_8 -> V_110 . V_757 = false ;
F_342 ( V_8 , true ) ;
break;
case V_27 :
case V_658 :
F_420 ( V_8 ) ;
break;
case V_23 :
if ( V_72 -> V_695 &
V_758 ) {
V_252 = true ;
V_253 =
F_92 ( V_759 ) ;
}
case V_263 :
F_421 ( V_8 ) ;
break;
default:
break;
}
}
V_750 = V_719 ;
if ( ! V_752 || ( type != V_23 &&
type != V_27 &&
type != V_663 ) )
F_162 ( V_8 ) ;
if ( F_422 ( V_8 , V_750 ,
type == V_658 ? V_753 : - 1 , V_751 ,
V_252 , V_253 ) == V_760 ) {
V_8 -> V_688 -> V_701 = V_702 ;
V_8 -> V_688 -> V_703 . V_704 = V_761 ;
V_8 -> V_688 -> V_703 . V_706 = 0 ;
return 0 ;
}
F_97 ( V_711 , F_90 ( V_711 ) & ~ 55 ) ;
return 1 ;
}
static int F_423 ( struct V_7 * V_8 )
{
unsigned long V_719 ;
T_1 V_84 ;
T_2 V_253 ;
int V_762 ;
V_719 = F_90 ( V_707 ) ;
V_762 = ( V_719 >> 7 ) & 0x3 ;
if ( V_762 != 0x3 && V_762 != 0x1 && V_762 != 0 ) {
F_67 ( V_88 L_21 ) ;
F_67 ( V_88 L_22 ,
( long unsigned int ) F_93 ( V_763 ) ,
F_90 ( V_764 ) ) ;
F_67 ( V_88 L_23 ,
( long unsigned int ) V_719 ) ;
V_8 -> V_688 -> V_701 = V_765 ;
V_8 -> V_688 -> V_766 . V_767 = V_768 ;
return 0 ;
}
V_84 = F_93 ( V_763 ) ;
F_358 ( V_84 , V_719 ) ;
V_253 = V_719 & ( 1U << 1 ) ;
V_253 |= ( V_719 >> 3 ) & 0x1 ;
return F_361 ( V_8 , V_84 , V_253 , NULL , 0 ) ;
}
static T_3 F_424 ( T_3 V_769 , int V_770 )
{
int V_74 ;
T_3 V_104 = 0 ;
for ( V_74 = 51 ; V_74 > V_422 . V_771 ; V_74 -- )
V_104 |= ( 1ULL << V_74 ) ;
if ( V_770 > 2 )
V_104 |= 0xf8 ;
else if ( V_770 == 2 ) {
if ( V_769 & ( 1ULL << 7 ) )
V_104 |= 0x1ff000 ;
else
V_104 |= 0x78 ;
}
return V_104 ;
}
static void F_425 ( struct V_7 * V_8 , T_3 V_769 ,
int V_770 )
{
F_67 ( V_88 L_24 , V_478 , V_769 , V_770 ) ;
F_426 ( ( V_769 & 0x7 ) == 0x2 ) ;
F_426 ( ( V_769 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_426 ( ( V_769 & 0x7 ) == 0x4 ) ;
if ( ( V_769 & 0x7 ) ) {
T_3 V_772 = V_769 & F_424 ( V_769 , V_770 ) ;
if ( V_772 != 0 ) {
F_67 ( V_88 L_25 ,
V_478 , V_772 ) ;
F_426 ( 1 ) ;
}
if ( V_770 == 1 || ( V_770 == 2 && ( V_769 & ( 1ULL << 7 ) ) ) ) {
T_3 V_773 = ( V_769 & 0x38 ) >> 3 ;
if ( V_773 == 2 || V_773 == 3 ||
V_773 == 7 ) {
F_67 ( V_88 L_26 ,
V_478 , V_773 ) ;
F_426 ( 1 ) ;
}
}
}
}
static int F_427 ( struct V_7 * V_8 )
{
T_3 V_774 [ 4 ] ;
int V_775 , V_74 , V_108 ;
T_1 V_84 ;
V_84 = F_93 ( V_763 ) ;
V_108 = F_428 ( V_8 , V_84 , true ) ;
if ( F_289 ( V_108 == V_776 ) )
return F_429 ( V_8 , V_84 , 0 , NULL , 0 ) ==
V_260 ;
if ( F_98 ( V_108 == V_777 ) )
return F_361 ( V_8 , V_84 , 0 , NULL , 0 ) ;
if ( F_98 ( V_108 == V_778 ) )
return 1 ;
F_67 ( V_88 L_27 ) ;
F_67 ( V_88 L_28 , V_84 ) ;
V_775 = F_430 ( V_8 , V_84 , V_774 ) ;
for ( V_74 = V_779 ; V_74 > V_779 - V_775 ; -- V_74 )
F_425 ( V_8 , V_774 [ V_74 - 1 ] , V_74 ) ;
V_8 -> V_688 -> V_701 = V_765 ;
V_8 -> V_688 -> V_766 . V_767 = V_780 ;
return 0 ;
}
static int F_431 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_92 ( V_494 ) ;
V_69 &= ~ V_652 ;
F_100 ( V_494 , V_69 ) ;
++ V_8 -> V_210 . V_781 ;
F_143 ( V_566 , V_8 ) ;
return 1 ;
}
static int F_432 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
enum V_693 V_727 = V_260 ;
int V_108 = 1 ;
T_2 V_782 ;
bool V_783 ;
unsigned V_784 = 130 ;
V_782 = F_92 ( V_494 ) ;
V_783 = V_782 & V_319 ;
while ( ! F_239 ( V_8 ) && V_784 -- != 0 ) {
if ( V_783 && F_344 ( V_8 ) )
return F_398 ( & V_72 -> V_8 ) ;
if ( F_157 ( V_566 , & V_8 -> V_785 ) )
return 1 ;
V_727 = F_349 ( V_8 , V_786 ) ;
if ( V_727 == V_787 ) {
V_108 = 0 ;
goto V_516;
}
if ( V_727 != V_260 ) {
V_8 -> V_688 -> V_701 = V_702 ;
V_8 -> V_688 -> V_703 . V_704 = V_761 ;
V_8 -> V_688 -> V_703 . V_706 = 0 ;
return 0 ;
}
if ( V_8 -> V_110 . V_684 ) {
V_8 -> V_110 . V_684 = 0 ;
V_108 = F_350 ( V_8 ) ;
goto V_516;
}
if ( F_433 ( V_788 ) )
goto V_516;
if ( F_434 () )
F_435 () ;
}
V_72 -> F_238 = F_238 ( V_8 ) ;
V_516:
return V_108 ;
}
static int F_436 ( struct V_7 * V_8 )
{
F_162 ( V_8 ) ;
F_437 ( V_8 ) ;
return 1 ;
}
static int F_438 ( struct V_7 * V_8 )
{
F_351 ( V_8 , V_26 ) ;
return 1 ;
}
static struct V_89 * F_439 ( struct V_6 * V_72 )
{
struct V_789 * V_790 ;
F_78 (item, &vmx->nested.vmcs02_pool, list)
if ( V_790 -> V_791 == V_72 -> V_13 . V_792 ) {
F_440 ( & V_790 -> V_793 , & V_72 -> V_13 . V_794 ) ;
return & V_790 -> V_795 ;
}
if ( V_72 -> V_13 . V_796 >= F_441 ( V_797 , 1 ) ) {
V_790 = F_442 ( V_72 -> V_13 . V_794 . V_798 ,
struct V_789 , V_793 ) ;
V_790 -> V_791 = V_72 -> V_13 . V_792 ;
F_440 ( & V_790 -> V_793 , & V_72 -> V_13 . V_794 ) ;
return & V_790 -> V_795 ;
}
V_790 = F_443 ( sizeof( struct V_789 ) , V_427 ) ;
if ( ! V_790 )
return NULL ;
V_790 -> V_795 . V_86 = F_226 () ;
if ( ! V_790 -> V_795 . V_86 ) {
F_444 ( V_790 ) ;
return NULL ;
}
F_68 ( & V_790 -> V_795 ) ;
V_790 -> V_791 = V_72 -> V_13 . V_792 ;
F_146 ( & ( V_790 -> V_793 ) , & ( V_72 -> V_13 . V_794 ) ) ;
V_72 -> V_13 . V_796 ++ ;
return & V_790 -> V_795 ;
}
static void F_445 ( struct V_6 * V_72 , T_1 V_791 )
{
struct V_789 * V_790 ;
F_78 (item, &vmx->nested.vmcs02_pool, list)
if ( V_790 -> V_791 == V_791 ) {
F_229 ( & V_790 -> V_795 ) ;
F_81 ( & V_790 -> V_793 ) ;
F_444 ( V_790 ) ;
V_72 -> V_13 . V_796 -- ;
return;
}
}
static void F_446 ( struct V_6 * V_72 )
{
struct V_789 * V_790 , * V_396 ;
F_216 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_72 -> V_89 != & V_790 -> V_795 )
F_229 ( & V_790 -> V_795 ) ;
F_81 ( & V_790 -> V_793 ) ;
F_444 ( V_790 ) ;
}
V_72 -> V_13 . V_796 = 0 ;
if ( V_72 -> V_89 != & V_72 -> V_799 )
F_229 ( & V_72 -> V_799 ) ;
}
static int F_447 ( struct V_7 * V_8 )
{
struct V_443 V_522 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_86 * V_800 ;
if ( ! F_448 ( V_8 , V_394 ) ||
! F_151 ( V_8 , V_499 ) ||
( F_156 ( V_8 ) & V_242 ) ) {
F_351 ( V_8 , V_26 ) ;
return 1 ;
}
F_243 ( V_8 , & V_522 , V_445 ) ;
if ( F_128 ( V_8 ) && ! V_522 . V_467 ) {
F_351 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_267 ( V_8 ) ) {
F_392 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_511 ) {
F_449 ( V_8 , V_801 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_431 ) {
V_800 = F_226 () ;
if ( ! V_800 )
return - V_428 ;
V_800 -> V_420 |= ( 1u << 31 ) ;
F_65 ( V_800 ) ;
V_72 -> V_13 . V_802 = V_800 ;
}
F_212 ( & ( V_72 -> V_13 . V_794 ) ) ;
V_72 -> V_13 . V_796 = 0 ;
V_72 -> V_13 . V_511 = true ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_450 ( struct V_7 * V_8 )
{
struct V_443 V_522 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! V_72 -> V_13 . V_511 ) {
F_351 ( V_8 , V_26 ) ;
return 0 ;
}
F_243 ( V_8 , & V_522 , V_445 ) ;
if ( ( F_156 ( V_8 ) & V_242 ) ||
( F_128 ( V_8 ) && ! V_522 . V_467 ) ) {
F_351 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_267 ( V_8 ) ) {
F_392 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_451 ( struct V_6 * V_72 )
{
T_2 V_594 ;
if ( V_431 ) {
if ( V_72 -> V_13 . V_14 != NULL ) {
F_452 ( V_72 ) ;
V_72 -> V_13 . V_803 = false ;
V_594 = F_92 ( V_606 ) ;
V_594 &= ~ V_67 ;
F_100 ( V_606 , V_594 ) ;
F_101 ( V_604 , - 1ull ) ;
}
}
F_453 ( V_72 -> V_13 . V_804 ) ;
F_13 ( V_72 -> V_13 . V_804 ) ;
}
static void F_454 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_13 . V_511 )
return;
V_72 -> V_13 . V_511 = false ;
if ( V_72 -> V_13 . V_792 != - 1ull ) {
F_451 ( V_72 ) ;
V_72 -> V_13 . V_792 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
if ( V_431 )
F_227 ( V_72 -> V_13 . V_802 ) ;
if ( V_72 -> V_13 . V_552 ) {
F_13 ( V_72 -> V_13 . V_552 ) ;
V_72 -> V_13 . V_552 = 0 ;
}
F_446 ( V_72 ) ;
}
static int F_455 ( struct V_7 * V_8 )
{
if ( ! F_450 ( V_8 ) )
return 1 ;
F_454 ( F_6 ( V_8 ) ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_456 ( struct V_7 * V_8 ,
unsigned long V_719 ,
T_2 V_805 , T_5 * V_108 )
{
int V_806 = V_805 & 3 ;
int V_807 = ( V_805 >> 7 ) & 7 ;
bool V_808 = V_805 & ( 1u << 10 ) ;
int V_809 = ( V_805 >> 15 ) & 7 ;
int V_810 = ( V_805 >> 18 ) & 0xf ;
bool V_811 = ! ( V_805 & ( 1u << 22 ) ) ;
int V_812 = ( V_805 >> 23 ) & 0xf ;
bool V_813 = ! ( V_805 & ( 1u << 27 ) ) ;
if ( V_808 ) {
F_351 ( V_8 , V_26 ) ;
return 1 ;
}
* V_108 = F_266 ( V_8 , V_809 ) ;
if ( V_813 )
* V_108 += F_373 ( V_8 , V_812 ) ;
if ( V_811 )
* V_108 += F_373 ( V_8 , V_810 ) << V_806 ;
* V_108 += V_719 ;
if ( V_807 == 1 )
* V_108 &= 0xffffffff ;
return 0 ;
}
static void F_457 ( struct V_7 * V_8 )
{
F_159 ( V_8 , F_156 ( V_8 )
& ~ ( V_814 | V_815 | V_816 |
V_817 | V_818 | V_819 ) ) ;
}
static void F_458 ( struct V_7 * V_8 )
{
F_159 ( V_8 , ( F_156 ( V_8 )
& ~ ( V_815 | V_816 | V_817 |
V_818 | V_819 ) )
| V_814 ) ;
}
static void F_449 ( struct V_7 * V_8 ,
T_2 V_820 )
{
if ( F_6 ( V_8 ) -> V_13 . V_792 == - 1ull ) {
F_458 ( V_8 ) ;
return;
}
F_159 ( V_8 , ( F_156 ( V_8 )
& ~ ( V_814 | V_815 | V_816 |
V_818 | V_819 ) )
| V_817 ) ;
F_9 ( V_8 ) -> V_820 = V_820 ;
}
static int F_459 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_791 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
struct V_821 V_822 ;
if ( ! F_450 ( V_8 ) )
return 1 ;
if ( F_456 ( V_8 , F_90 ( V_707 ) ,
F_92 ( V_823 ) , & V_80 ) )
return 1 ;
if ( F_460 ( & V_8 -> V_110 . V_824 , V_80 , & V_791 ,
sizeof( V_791 ) , & V_822 ) ) {
F_461 ( V_8 , & V_822 ) ;
return 1 ;
}
if ( ! F_462 ( V_791 , V_417 ) ) {
F_449 ( V_8 , V_825 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_791 == V_72 -> V_13 . V_792 ) {
F_451 ( V_72 ) ;
V_72 -> V_13 . V_792 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
V_15 = F_10 ( V_8 , V_791 ) ;
if ( V_15 == NULL ) {
F_143 ( V_261 , V_8 ) ;
return 1 ;
}
V_12 = F_463 ( V_15 ) ;
V_12 -> V_826 = 0 ;
F_453 ( V_15 ) ;
F_13 ( V_15 ) ;
F_445 ( V_72 , V_791 ) ;
F_162 ( V_8 ) ;
F_457 ( V_8 ) ;
return 1 ;
}
static int F_464 ( struct V_7 * V_8 )
{
return F_465 ( V_8 , true ) ;
}
static int F_466 ( struct V_7 * V_8 )
{
return F_465 ( V_8 , false ) ;
}
static inline int F_467 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_827 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_468 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_469 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_108 )
{
short V_290 = F_8 ( V_9 ) ;
char * V_113 ;
if ( V_290 < 0 )
return 0 ;
V_113 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_290 ;
switch ( F_467 ( V_9 ) ) {
case V_828 :
* V_108 = * ( ( V_829 * ) V_113 ) ;
return 1 ;
case V_830 :
* V_108 = * ( ( T_4 * ) V_113 ) ;
return 1 ;
case V_827 :
* V_108 = * ( ( T_2 * ) V_113 ) ;
return 1 ;
case V_831 :
* V_108 = * ( ( T_3 * ) V_113 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_470 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_832 ) {
short V_290 = F_8 ( V_9 ) ;
char * V_113 = ( ( char * ) F_9 ( V_8 ) ) + V_290 ;
if ( V_290 < 0 )
return false ;
switch ( F_467 ( V_9 ) ) {
case V_830 :
* ( T_4 * ) V_113 = V_832 ;
return true ;
case V_827 :
* ( T_2 * ) V_113 = V_832 ;
return true ;
case V_831 :
* ( T_3 * ) V_113 = V_832 ;
return true ;
case V_828 :
* ( V_829 * ) V_113 = V_832 ;
return true ;
default:
return false ;
}
}
static void F_452 ( struct V_6 * V_72 )
{
int V_74 ;
unsigned long V_9 ;
T_3 V_832 ;
struct V_86 * V_800 = V_72 -> V_13 . V_802 ;
unsigned long * V_229 = ( unsigned long * ) V_833 ;
int V_834 = V_835 ;
F_69 ( V_800 ) ;
for ( V_74 = 0 ; V_74 < V_834 ; V_74 ++ ) {
V_9 = V_229 [ V_74 ] ;
switch ( F_467 ( V_9 ) ) {
case V_830 :
V_832 = F_91 ( V_9 ) ;
break;
case V_827 :
V_832 = F_92 ( V_9 ) ;
break;
case V_831 :
V_832 = F_93 ( V_9 ) ;
break;
case V_828 :
V_832 = F_90 ( V_9 ) ;
break;
}
F_470 ( & V_72 -> V_8 , V_9 , V_832 ) ;
}
F_65 ( V_800 ) ;
F_69 ( V_72 -> V_89 -> V_86 ) ;
}
static void F_471 ( struct V_6 * V_72 )
{
unsigned long * V_229 [] = {
( unsigned long * ) V_833 ,
( unsigned long * ) V_836
} ;
int V_837 = F_472 ( V_229 ) ;
int V_838 [] = {
V_835 ,
V_839
} ;
int V_74 , V_840 ;
unsigned long V_9 ;
T_3 V_832 = 0 ;
struct V_86 * V_800 = V_72 -> V_13 . V_802 ;
F_69 ( V_800 ) ;
for ( V_840 = 0 ; V_840 < V_837 ; V_840 ++ ) {
for ( V_74 = 0 ; V_74 < V_838 [ V_840 ] ; V_74 ++ ) {
V_9 = V_229 [ V_840 ] [ V_74 ] ;
F_469 ( & V_72 -> V_8 , V_9 , & V_832 ) ;
switch ( F_467 ( V_9 ) ) {
case V_830 :
F_99 ( V_9 , ( T_4 ) V_832 ) ;
break;
case V_827 :
F_100 ( V_9 , ( T_2 ) V_832 ) ;
break;
case V_831 :
F_101 ( V_9 , ( T_3 ) V_832 ) ;
break;
case V_828 :
F_97 ( V_9 , ( long ) V_832 ) ;
break;
}
}
}
F_65 ( V_800 ) ;
F_69 ( V_72 -> V_89 -> V_86 ) ;
}
static int F_473 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( V_72 -> V_13 . V_792 == - 1ull ) {
F_458 ( V_8 ) ;
F_162 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_474 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_832 ;
unsigned long V_719 = F_90 ( V_707 ) ;
T_2 V_805 = F_92 ( V_823 ) ;
T_5 V_80 = 0 ;
if ( ! F_450 ( V_8 ) ||
! F_473 ( V_8 ) )
return 1 ;
V_9 = F_373 ( V_8 , ( ( ( V_805 ) >> 28 ) & 0xf ) ) ;
if ( ! F_469 ( V_8 , V_9 , & V_832 ) ) {
F_449 ( V_8 , V_841 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_805 & ( 1u << 10 ) ) {
F_378 ( V_8 , ( ( ( V_805 ) >> 3 ) & 0xf ) ,
V_832 ) ;
} else {
if ( F_456 ( V_8 , V_719 ,
V_805 , & V_80 ) )
return 1 ;
F_475 ( & V_8 -> V_110 . V_824 , V_80 ,
& V_832 , ( F_128 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_457 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_476 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_80 ;
unsigned long V_719 = F_90 ( V_707 ) ;
T_2 V_805 = F_92 ( V_823 ) ;
T_3 V_832 = 0 ;
struct V_821 V_822 ;
if ( ! F_450 ( V_8 ) ||
! F_473 ( V_8 ) )
return 1 ;
if ( V_805 & ( 1u << 10 ) )
V_832 = F_373 ( V_8 ,
( ( ( V_805 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_456 ( V_8 , V_719 ,
V_805 , & V_80 ) )
return 1 ;
if ( F_460 ( & V_8 -> V_110 . V_824 , V_80 ,
& V_832 , ( F_128 ( V_8 ) ? 8 : 4 ) , & V_822 ) ) {
F_461 ( V_8 , & V_822 ) ;
return 1 ;
}
}
V_9 = F_373 ( V_8 , ( ( ( V_805 ) >> 28 ) & 0xf ) ) ;
if ( F_468 ( V_9 ) ) {
F_449 ( V_8 ,
V_842 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( ! F_470 ( V_8 , V_9 , V_832 ) ) {
F_449 ( V_8 , V_841 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
F_457 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_477 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_791 ;
struct V_821 V_822 ;
T_2 V_594 ;
if ( ! F_450 ( V_8 ) )
return 1 ;
if ( F_456 ( V_8 , F_90 ( V_707 ) ,
F_92 ( V_823 ) , & V_80 ) )
return 1 ;
if ( F_460 ( & V_8 -> V_110 . V_824 , V_80 , & V_791 ,
sizeof( V_791 ) , & V_822 ) ) {
F_461 ( V_8 , & V_822 ) ;
return 1 ;
}
if ( ! F_462 ( V_791 , V_417 ) ) {
F_449 ( V_8 , V_843 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_792 != V_791 ) {
struct V_12 * V_844 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_791 ) ;
if ( V_15 == NULL ) {
F_458 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
V_844 = F_463 ( V_15 ) ;
if ( V_844 -> V_420 != V_349 ) {
F_453 ( V_15 ) ;
F_15 ( V_15 ) ;
F_449 ( V_8 ,
V_845 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_792 != - 1ull )
F_451 ( V_72 ) ;
V_72 -> V_13 . V_792 = V_791 ;
V_72 -> V_13 . V_14 = V_844 ;
V_72 -> V_13 . V_804 = V_15 ;
if ( V_431 ) {
V_594 = F_92 ( V_606 ) ;
V_594 |= V_67 ;
F_100 ( V_606 , V_594 ) ;
F_101 ( V_604 ,
F_66 ( V_72 -> V_13 . V_802 ) ) ;
V_72 -> V_13 . V_803 = true ;
}
}
F_457 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static int F_478 ( struct V_7 * V_8 )
{
unsigned long V_719 = F_90 ( V_707 ) ;
T_2 V_805 = F_92 ( V_823 ) ;
T_5 V_846 ;
struct V_821 V_822 ;
if ( ! F_450 ( V_8 ) )
return 1 ;
if ( F_456 ( V_8 , V_719 ,
V_805 , & V_846 ) )
return 1 ;
if ( F_475 ( & V_8 -> V_110 . V_824 , V_846 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_792 ,
sizeof( T_3 ) , & V_822 ) ) {
F_461 ( V_8 , & V_822 ) ;
return 1 ;
}
F_457 ( V_8 ) ;
F_162 ( V_8 ) ;
return 1 ;
}
static bool F_479 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_719 ;
T_1 V_847 , V_848 ;
unsigned int V_721 ;
int V_418 ;
T_6 V_849 ;
if ( F_57 ( V_12 , V_328 ) )
return 1 ;
if ( ! F_57 ( V_12 , V_329 ) )
return 0 ;
V_719 = F_90 ( V_707 ) ;
V_721 = V_719 >> 16 ;
V_418 = ( V_719 & 7 ) + 1 ;
V_848 = ( T_1 ) - 1 ;
V_849 = - 1 ;
while ( V_418 > 0 ) {
if ( V_721 < 0x8000 )
V_847 = V_12 -> V_850 ;
else if ( V_721 < 0x10000 )
V_847 = V_12 -> V_851 ;
else
return 1 ;
V_847 += ( V_721 & 0x7fff ) / 8 ;
if ( V_848 != V_847 )
if ( F_480 ( V_8 -> V_17 , V_847 , & V_849 , 1 ) )
return 1 ;
if ( V_849 & ( 1 << ( V_721 & 7 ) ) )
return 1 ;
V_721 ++ ;
V_418 -- ;
V_848 = V_847 ;
}
return 0 ;
}
static bool F_481 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_701 )
{
T_2 V_343 = V_8 -> V_110 . V_383 [ V_737 ] ;
T_1 V_847 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_847 = V_12 -> V_268 ;
if ( V_701 == V_852 )
V_847 += 2048 ;
if ( V_343 >= 0xc0000000 ) {
V_343 -= 0xc0000000 ;
V_847 += 1024 ;
}
if ( V_343 < 1024 * 8 ) {
unsigned char V_849 ;
if ( F_480 ( V_8 -> V_17 , V_847 + V_343 / 8 , & V_849 , 1 ) )
return 1 ;
return 1 & ( V_849 >> ( V_343 & 7 ) ) ;
} else
return 1 ;
}
static bool F_482 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_719 = F_90 ( V_707 ) ;
int V_726 = V_719 & 15 ;
int V_381 = ( V_719 >> 8 ) & 15 ;
unsigned long V_724 = F_373 ( V_8 , V_381 ) ;
switch ( ( V_719 >> 4 ) & 3 ) {
case 0 :
switch ( V_726 ) {
case 0 :
if ( V_12 -> V_227 &
( V_724 ^ V_12 -> V_231 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_853 >= 1 &&
V_12 -> V_854 == V_724 ) ||
( V_12 -> V_853 >= 2 &&
V_12 -> V_855 == V_724 ) ||
( V_12 -> V_853 >= 3 &&
V_12 -> V_856 == V_724 ) ||
( V_12 -> V_853 >= 4 &&
V_12 -> V_857 == V_724 ) )
return 0 ;
if ( F_57 ( V_12 , V_323 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_233 &
( V_12 -> V_234 ^ V_724 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_325 ) )
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
switch ( V_726 ) {
case 3 :
if ( V_12 -> V_69 &
V_324 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_326 )
return 1 ;
break;
}
break;
case 3 :
if ( V_12 -> V_227 & 0xe &
( V_724 ^ V_12 -> V_231 ) )
return 1 ;
if ( ( V_12 -> V_227 & 0x1 ) &&
! ( V_12 -> V_231 & 0x1 ) &&
( V_724 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_483 ( struct V_7 * V_8 )
{
T_2 V_19 = F_92 ( V_858 ) ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_701 = V_72 -> V_701 ;
if ( V_72 -> V_13 . V_255 )
return 0 ;
if ( F_98 ( V_72 -> V_859 ) ) {
F_484 ( L_29 , V_478 ,
F_92 ( V_103 ) ) ;
return 1 ;
}
switch ( V_701 ) {
case V_667 :
if ( ! F_60 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_100 ;
return V_12 -> V_133 &
( 1u << ( V_19 & V_21 ) ) ;
case V_670 :
return 0 ;
case V_860 :
return 1 ;
case V_861 :
return F_57 ( V_12 , V_319 ) ;
case V_862 :
return F_57 ( V_12 , V_652 ) ;
case V_863 :
return 1 ;
case V_864 :
return 1 ;
case V_865 :
return F_57 ( V_12 , V_320 ) ;
case V_866 :
return 1 ;
case V_867 :
return F_57 ( V_12 , V_321 ) ;
case V_868 :
return F_57 ( V_12 , V_331 ) ;
case V_869 :
return F_57 ( V_12 , V_332 ) ;
case V_870 : case V_871 :
case V_872 : case V_873 :
case V_874 : case V_875 :
case V_876 : case V_877 :
case V_878 : case V_879 :
return 1 ;
case V_880 :
return F_482 ( V_8 , V_12 ) ;
case V_881 :
return F_57 ( V_12 , V_327 ) ;
case V_882 :
return F_479 ( V_8 , V_12 ) ;
case V_883 :
case V_852 :
return F_481 ( V_8 , V_12 , V_701 ) ;
case V_884 :
return 1 ;
case V_885 :
return F_57 ( V_12 , V_322 ) ;
case V_886 :
return F_57 ( V_12 , V_330 ) ;
case V_887 :
return F_57 ( V_12 , V_333 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_888 :
return 0 ;
case V_889 :
return 1 ;
case V_890 :
return F_58 ( V_12 ,
V_35 ) ;
case V_768 :
case V_780 :
return 0 ;
case V_891 :
return V_12 -> V_71 &
V_305 ;
case V_892 :
return F_58 ( V_12 , V_63 ) ;
case V_893 :
return 1 ;
default:
return 1 ;
}
}
static void F_485 ( struct V_7 * V_8 , T_3 * V_894 , T_3 * V_895 )
{
* V_894 = F_90 ( V_707 ) ;
* V_895 = F_92 ( V_858 ) ;
}
static int F_486 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_701 = V_72 -> V_701 ;
T_2 V_896 = V_72 -> V_695 ;
if ( V_72 -> F_238 )
return F_432 ( V_8 ) ;
if ( V_72 -> V_13 . V_255 )
F_143 ( V_566 , V_8 ) ;
if ( ! F_111 ( V_8 ) && ( V_701 == V_872 ||
V_701 == V_876 ) )
V_72 -> V_13 . V_255 = 1 ;
else
V_72 -> V_13 . V_255 = 0 ;
if ( F_111 ( V_8 ) && F_483 ( V_8 ) ) {
F_166 ( V_8 ) ;
return 1 ;
}
if ( V_701 & V_897 ) {
V_8 -> V_688 -> V_701 = V_898 ;
V_8 -> V_688 -> V_899 . V_900
= V_701 ;
return 0 ;
}
if ( F_98 ( V_72 -> V_859 ) ) {
V_8 -> V_688 -> V_701 = V_898 ;
V_8 -> V_688 -> V_899 . V_900
= F_92 ( V_103 ) ;
return 0 ;
}
if ( ( V_896 & V_699 ) &&
( V_701 != V_667 &&
V_701 != V_768 &&
V_701 != V_863 ) ) {
V_8 -> V_688 -> V_701 = V_702 ;
V_8 -> V_688 -> V_703 . V_704 = V_901 ;
V_8 -> V_688 -> V_703 . V_706 = 2 ;
V_8 -> V_688 -> V_703 . V_179 [ 0 ] = V_896 ;
V_8 -> V_688 -> V_703 . V_179 [ 1 ] = V_701 ;
return 0 ;
}
if ( F_98 ( ! F_52 () && V_72 -> V_630 &&
! ( F_111 ( V_8 ) && F_59 (
F_9 ( V_8 ) , V_8 ) ) ) ) {
if ( F_344 ( V_8 ) ) {
V_72 -> V_630 = 0 ;
} else if ( V_72 -> V_659 > 1000000000LL &&
V_8 -> V_110 . V_669 ) {
F_67 ( V_162 L_30
L_31 ,
V_478 , V_8 -> V_292 ) ;
V_72 -> V_630 = 0 ;
}
}
if ( V_701 < V_902
&& V_903 [ V_701 ] )
return V_903 [ V_701 ] ( V_8 ) ;
else {
V_8 -> V_688 -> V_701 = V_765 ;
V_8 -> V_688 -> V_766 . V_767 = V_701 ;
}
return 0 ;
}
static void V_435 ( struct V_7 * V_8 , int V_904 , int V_905 )
{
if ( V_905 == - 1 || V_904 < V_905 ) {
F_100 ( V_646 , 0 ) ;
return;
}
F_100 ( V_646 , V_905 ) ;
}
static void F_487 ( struct V_7 * V_8 , bool V_906 )
{
T_2 V_907 ;
if ( ! F_28 () ||
! F_307 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_907 = F_92 ( V_606 ) ;
if ( V_906 ) {
V_907 &= ~ V_35 ;
V_907 |= V_36 ;
} else {
V_907 &= ~ V_36 ;
V_907 |= V_35 ;
}
F_100 ( V_606 , V_907 ) ;
F_173 ( V_8 ) ;
}
static void F_488 ( struct V_17 * V_17 , int V_908 )
{
T_4 V_909 ;
T_6 V_392 ;
if ( ! F_307 ( V_17 ) )
return;
if ( V_908 == - 1 )
V_908 = 0 ;
V_909 = F_91 ( V_611 ) ;
V_392 = V_909 >> 8 ;
if ( V_908 != V_392 ) {
V_909 &= 0xff ;
V_909 |= V_908 << 8 ;
F_99 ( V_611 , V_909 ) ;
}
}
static void F_489 ( int V_4 )
{
T_4 V_909 ;
T_6 V_392 ;
V_909 = F_91 ( V_611 ) ;
V_392 = ( T_6 ) V_909 & 0xff ;
if ( ( T_6 ) V_4 != V_392 ) {
V_909 &= ~ 0xff ;
V_909 |= ( T_6 ) V_4 ;
F_99 ( V_611 , V_909 ) ;
}
}
static void F_490 ( struct V_7 * V_8 , int V_910 )
{
if ( V_910 == - 1 )
return;
F_489 ( V_910 ) ;
}
static void F_491 ( struct V_7 * V_8 , T_3 * V_911 )
{
if ( ! F_307 ( V_8 -> V_17 ) )
return;
F_101 ( V_607 , V_911 [ 0 ] ) ;
F_101 ( V_608 , V_911 [ 1 ] ) ;
F_101 ( V_609 , V_911 [ 2 ] ) ;
F_101 ( V_610 , V_911 [ 3 ] ) ;
}
static void F_492 ( struct V_6 * V_72 )
{
T_2 V_696 ;
if ( ! ( V_72 -> V_701 == V_888
|| V_72 -> V_701 == V_667 ) )
return;
V_72 -> V_696 = F_92 ( V_858 ) ;
V_696 = V_72 -> V_696 ;
if ( F_21 ( V_696 ) )
F_352 () ;
if ( ( V_696 & V_20 ) == V_663 &&
( V_696 & V_22 ) ) {
F_493 ( & V_72 -> V_8 ) ;
asm("int $2");
F_494 ( & V_72 -> V_8 ) ;
}
}
static void F_495 ( struct V_7 * V_8 )
{
T_2 V_696 = F_92 ( V_858 ) ;
if ( ( V_696 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_135 ;
T_16 * V_912 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
#ifdef F_94
unsigned long V_267 ;
#endif
V_4 = V_696 & V_21 ;
V_912 = ( T_16 * ) V_72 -> V_585 + V_4 ;
V_135 = F_496 ( * V_912 ) ;
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
static void F_497 ( struct V_6 * V_72 )
{
T_2 V_696 ;
bool V_913 ;
T_6 V_4 ;
bool V_914 ;
V_914 = V_72 -> V_695 & V_699 ;
if ( F_52 () ) {
if ( V_72 -> V_661 )
return;
V_696 = F_92 ( V_858 ) ;
V_913 = ( V_696 & V_915 ) != 0 ;
V_4 = V_696 & V_21 ;
if ( ( V_696 & V_22 ) && V_913 &&
V_4 != V_680 && ! V_914 )
F_103 ( V_244 ,
V_664 ) ;
else
V_72 -> V_661 =
! ( F_92 ( V_244 )
& V_664 ) ;
} else if ( F_98 ( V_72 -> V_630 ) )
V_72 -> V_659 +=
F_498 ( F_499 ( F_500 () , V_72 -> V_916 ) ) ;
}
static void F_501 ( struct V_7 * V_8 ,
T_2 V_695 ,
int V_917 ,
int V_918 )
{
T_6 V_4 ;
int type ;
bool V_914 ;
V_914 = V_695 & V_699 ;
V_8 -> V_110 . V_757 = false ;
F_421 ( V_8 ) ;
F_420 ( V_8 ) ;
if ( ! V_914 )
return;
F_143 ( V_566 , V_8 ) ;
V_4 = V_695 & V_754 ;
type = V_695 & V_755 ;
switch ( type ) {
case V_663 :
V_8 -> V_110 . V_757 = true ;
F_342 ( V_8 , false ) ;
break;
case V_263 :
V_8 -> V_110 . V_259 = F_92 ( V_917 ) ;
case V_23 :
if ( V_695 & V_758 ) {
T_2 V_727 = F_92 ( V_918 ) ;
F_195 ( V_8 , V_4 , V_727 ) ;
} else
F_351 ( V_8 , V_4 ) ;
break;
case V_658 :
V_8 -> V_110 . V_259 = F_92 ( V_917 ) ;
case V_27 :
F_502 ( V_8 , V_4 , type == V_658 ) ;
break;
default:
break;
}
}
static void F_503 ( struct V_6 * V_72 )
{
F_501 ( & V_72 -> V_8 , V_72 -> V_695 ,
V_251 ,
V_759 ) ;
}
static void F_504 ( struct V_7 * V_8 )
{
F_501 ( V_8 ,
F_92 ( V_264 ) ,
V_262 ,
V_256 ) ;
F_100 ( V_264 , 0 ) ;
}
static void F_505 ( struct V_6 * V_72 )
{
int V_74 , V_919 ;
struct V_920 * V_921 ;
V_921 = F_506 ( & V_919 ) ;
if ( ! V_921 )
return;
for ( V_74 = 0 ; V_74 < V_919 ; V_74 ++ )
if ( V_921 [ V_74 ] . V_150 == V_921 [ V_74 ] . V_149 )
F_113 ( V_72 , V_921 [ V_74 ] . V_73 ) ;
else
F_115 ( V_72 , V_921 [ V_74 ] . V_73 , V_921 [ V_74 ] . V_149 ,
V_921 [ V_74 ] . V_150 ) ;
}
static void T_17 F_507 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_922 ;
if ( F_98 ( ! F_52 () && V_72 -> V_630 ) )
V_72 -> V_916 = F_500 () ;
if ( V_72 -> F_238 )
return;
if ( V_72 -> V_13 . V_803 ) {
F_471 ( V_72 ) ;
V_72 -> V_13 . V_803 = false ;
}
if ( F_157 ( V_382 , ( unsigned long * ) & V_8 -> V_110 . V_486 ) )
F_97 ( V_384 , V_8 -> V_110 . V_383 [ V_382 ] ) ;
if ( F_157 ( V_385 , ( unsigned long * ) & V_8 -> V_110 . V_486 ) )
F_97 ( V_386 , V_8 -> V_110 . V_383 [ V_385 ] ) ;
if ( V_8 -> V_126 & V_675 )
F_161 ( V_8 , 0 ) ;
F_505 ( V_72 ) ;
V_922 = F_508 () ;
V_72 -> V_923 = V_72 -> V_89 -> V_91 ;
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
if ( V_922 )
F_509 ( V_922 ) ;
#ifndef F_94
F_134 ( V_198 , V_924 ) ;
F_134 ( V_200 , V_924 ) ;
#endif
V_8 -> V_110 . V_111 = ~ ( ( 1 << V_385 ) | ( 1 << V_382 )
| ( 1 << V_238 )
| ( 1 << V_459 )
| ( 1 << V_387 )
| ( 1 << V_112 )
| ( 1 << V_483 ) ) ;
V_8 -> V_110 . V_486 = 0 ;
V_72 -> V_695 = F_92 ( V_925 ) ;
V_72 -> V_89 -> V_91 = 1 ;
V_72 -> V_701 = F_92 ( V_926 ) ;
F_510 ( V_72 -> V_701 , V_8 , V_927 ) ;
F_492 ( V_72 ) ;
F_497 ( V_72 ) ;
F_503 ( V_72 ) ;
}
static void F_511 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_300 ( V_72 ) ;
F_454 ( V_72 ) ;
F_229 ( V_72 -> V_89 ) ;
F_444 ( V_72 -> V_77 ) ;
F_512 ( V_8 ) ;
F_513 ( V_928 , V_72 ) ;
}
static struct V_7 * F_514 ( struct V_17 * V_17 , unsigned int V_929 )
{
int V_727 ;
struct V_6 * V_72 = F_515 ( V_928 , V_427 ) ;
int V_90 ;
if ( ! V_72 )
return F_516 ( - V_428 ) ;
F_296 ( V_72 ) ;
V_727 = F_517 ( & V_72 -> V_8 , V_17 , V_929 ) ;
if ( V_727 )
goto V_930;
V_72 -> V_77 = F_443 ( V_417 , V_427 ) ;
V_727 = - V_428 ;
if ( ! V_72 -> V_77 ) {
goto V_931;
}
V_72 -> V_89 = & V_72 -> V_799 ;
V_72 -> V_89 -> V_86 = F_226 () ;
if ( ! V_72 -> V_89 -> V_86 )
goto V_932;
if ( ! V_214 )
F_142 ( F_66 ( F_80 ( V_213 , F_77 () ) ) ) ;
F_68 ( V_72 -> V_89 ) ;
if ( ! V_214 )
F_149 () ;
V_90 = F_518 () ;
F_141 ( & V_72 -> V_8 , V_90 ) ;
V_72 -> V_8 . V_90 = V_90 ;
V_727 = F_324 ( V_72 ) ;
F_148 ( & V_72 -> V_8 ) ;
F_519 () ;
if ( V_727 )
goto F_227;
if ( F_48 ( V_17 ) ) {
V_727 = F_291 ( V_17 ) ;
if ( V_727 )
goto F_227;
}
if ( V_100 ) {
if ( ! V_17 -> V_110 . V_507 )
V_17 -> V_110 . V_507 =
V_933 ;
V_727 = - V_428 ;
if ( F_295 ( V_17 ) != 0 )
goto F_227;
if ( ! F_288 ( V_17 ) )
goto F_227;
}
V_72 -> V_13 . V_792 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
return & V_72 -> V_8 ;
F_227:
F_229 ( V_72 -> V_89 ) ;
V_932:
F_444 ( V_72 -> V_77 ) ;
V_931:
F_512 ( & V_72 -> V_8 ) ;
V_930:
F_300 ( V_72 ) ;
F_513 ( V_928 , V_72 ) ;
return F_516 ( V_727 ) ;
}
static void T_11 F_520 ( void * V_934 )
{
struct V_29 V_404 ;
* ( int * ) V_934 = 0 ;
if ( F_220 ( & V_404 ) < 0 )
* ( int * ) V_934 = - V_403 ;
if ( memcmp ( & V_29 , & V_404 , sizeof( struct V_29 ) ) != 0 ) {
F_67 ( V_88 L_32 ,
F_521 () ) ;
* ( int * ) V_934 = - V_403 ;
}
}
static int F_522 ( void )
{
return V_501 + 1 ;
}
static T_3 F_523 ( struct V_7 * V_8 , T_13 V_935 , bool V_936 )
{
T_3 V_108 ;
if ( V_936 )
V_108 = V_937 << V_938 ;
else if ( V_8 -> V_17 -> V_110 . V_939 &&
! ( V_8 -> V_17 -> V_110 . V_940 & V_941 ) )
V_108 = F_524 ( V_8 , V_935 ) <<
V_938 ;
else
V_108 = ( V_942 << V_938 )
| V_943 ;
return V_108 ;
}
static int F_525 ( void )
{
if ( V_100 && ! F_38 () )
return V_944 ;
else
return V_945 ;
}
static void F_526 ( struct V_7 * V_8 )
{
struct V_295 * V_296 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_594 ;
V_72 -> V_279 = false ;
if ( F_170 () ) {
V_594 = F_92 ( V_606 ) ;
if ( V_594 & V_60 ) {
V_296 = F_188 ( V_8 , 0x80000001 , 0 ) ;
if ( V_296 && ( V_296 -> V_946 & V_68 ( V_947 ) ) )
V_72 -> V_279 = true ;
else {
V_594 &= ~ V_60 ;
F_100 ( V_606 ,
V_594 ) ;
}
}
}
V_296 = F_188 ( V_8 , 0x7 , 0 ) ;
if ( F_171 () &&
V_296 && ( V_296 -> V_948 & V_68 ( V_949 ) ) &&
F_527 ( V_8 ) ) {
V_594 = F_92 ( V_606 ) ;
V_594 |= V_61 ;
F_100 ( V_606 ,
V_594 ) ;
} else {
if ( F_26 () ) {
V_594 = F_92 ( V_606 ) ;
V_594 &= ~ V_61 ;
F_100 ( V_606 ,
V_594 ) ;
}
if ( V_296 )
V_296 -> V_948 &= ~ V_68 ( V_949 ) ;
}
}
static void F_528 ( T_2 V_950 , struct V_295 * V_135 )
{
if ( V_950 == 1 && V_13 )
V_135 -> V_297 |= V_68 ( V_298 ) ;
}
static void F_529 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_594 ;
F_99 ( V_951 , V_12 -> V_952 ) ;
F_99 ( V_634 , V_12 -> V_953 ) ;
F_99 ( V_954 , V_12 -> V_955 ) ;
F_99 ( V_956 , V_12 -> V_957 ) ;
F_99 ( V_958 , V_12 -> V_959 ) ;
F_99 ( V_960 , V_12 -> V_961 ) ;
F_99 ( V_637 , V_12 -> V_962 ) ;
F_99 ( V_636 , V_12 -> V_963 ) ;
F_100 ( V_964 , V_12 -> V_965 ) ;
F_100 ( V_966 , V_12 -> V_967 ) ;
F_100 ( V_968 , V_12 -> V_969 ) ;
F_100 ( V_970 , V_12 -> V_971 ) ;
F_100 ( V_972 , V_12 -> V_973 ) ;
F_100 ( V_974 , V_12 -> V_975 ) ;
F_100 ( V_639 , V_12 -> V_976 ) ;
F_100 ( V_472 , V_12 -> V_977 ) ;
F_100 ( V_520 , V_12 -> V_978 ) ;
F_100 ( V_518 , V_12 -> V_979 ) ;
F_100 ( V_980 , V_12 -> V_981 ) ;
F_100 ( V_982 , V_12 -> V_983 ) ;
F_100 ( V_984 , V_12 -> V_985 ) ;
F_100 ( V_986 , V_12 -> V_987 ) ;
F_100 ( V_988 , V_12 -> V_989 ) ;
F_100 ( V_990 , V_12 -> V_991 ) ;
F_100 ( V_640 , V_12 -> V_992 ) ;
F_100 ( V_474 , V_12 -> V_993 ) ;
F_97 ( V_994 , V_12 -> V_995 ) ;
F_97 ( V_635 , V_12 -> V_996 ) ;
F_97 ( V_997 , V_12 -> V_998 ) ;
F_97 ( V_999 , V_12 -> V_1000 ) ;
F_97 ( V_365 , V_12 -> V_1001 ) ;
F_97 ( V_366 , V_12 -> V_1002 ) ;
F_97 ( V_638 , V_12 -> V_1003 ) ;
F_97 ( V_471 , V_12 -> V_1004 ) ;
F_97 ( V_521 , V_12 -> V_1005 ) ;
F_97 ( V_519 , V_12 -> V_1006 ) ;
F_101 ( V_644 , V_12 -> V_1007 ) ;
F_100 ( V_264 ,
V_12 -> V_1008 ) ;
F_100 ( V_256 ,
V_12 -> V_1009 ) ;
F_100 ( V_262 ,
V_12 -> V_1010 ) ;
F_100 ( V_244 ,
V_12 -> V_1011 ) ;
F_100 ( V_369 , V_12 -> V_1012 ) ;
F_386 ( V_8 , 7 , V_12 -> V_1013 ) ;
F_97 ( V_239 , V_12 -> V_1014 ) ;
F_97 ( V_643 ,
V_12 -> V_1015 ) ;
F_97 ( V_372 , V_12 -> V_1016 ) ;
F_97 ( V_371 , V_12 -> V_1017 ) ;
F_101 ( V_604 , - 1ull ) ;
F_100 ( V_605 ,
( V_29 . V_39 |
V_12 -> V_71 ) ) ;
if ( V_12 -> V_71 & V_305 )
F_100 ( V_1018 ,
V_12 -> V_1019 ) ;
F_100 ( V_617 ,
V_100 ? V_12 -> V_1020 : 0 ) ;
F_100 ( V_618 ,
V_100 ? V_12 -> V_1021 : 0 ) ;
if ( F_26 () ) {
T_2 V_594 = F_321 ( V_72 ) ;
if ( ! V_72 -> V_279 )
V_594 &= ~ V_60 ;
V_594 &= ~ V_35 ;
if ( F_57 ( V_12 ,
V_33 ) )
V_594 |= V_12 -> V_70 ;
if ( V_594 & V_35 ) {
if ( V_72 -> V_13 . V_552 )
F_13 ( V_72 -> V_13 . V_552 ) ;
V_72 -> V_13 . V_552 =
F_10 ( V_8 , V_12 -> V_1022 ) ;
if ( ! V_72 -> V_13 . V_552 )
V_594 &=
~ V_35 ;
else
F_101 ( V_647 ,
F_332 ( V_72 -> V_13 . V_552 ) ) ;
}
F_100 ( V_606 , V_594 ) ;
}
F_314 ( V_72 ) ;
V_72 -> V_1023 = 0 ;
V_594 = F_320 ( V_72 ) ;
V_594 &= ~ V_319 ;
V_594 &= ~ V_652 ;
V_594 &= ~ V_32 ;
V_594 |= V_12 -> V_69 ;
V_594 &= ~ V_31 ;
V_594 &= ~ V_329 ;
V_594 |= V_328 ;
F_100 ( V_494 , V_594 ) ;
F_110 ( V_8 ) ;
V_8 -> V_110 . V_226 &= ~ V_12 -> V_227 ;
F_97 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
F_100 ( V_137 ,
V_12 -> V_1024 | V_29 . V_421 ) ;
F_100 ( V_136 , V_12 -> V_1025 |
( V_29 . V_376 & ~ V_315 ) ) ;
if ( V_12 -> V_1025 & V_314 )
F_101 ( V_377 , V_12 -> V_1026 ) ;
else if ( V_29 . V_376 & V_314 )
F_101 ( V_377 , V_72 -> V_8 . V_110 . V_378 ) ;
F_318 ( V_72 ) ;
if ( V_12 -> V_69 & V_291 )
F_101 ( V_283 ,
V_72 -> V_13 . V_284 + V_12 -> V_282 ) ;
else
F_101 ( V_283 , V_72 -> V_13 . V_284 ) ;
if ( V_430 ) {
F_99 ( V_648 , V_72 -> V_52 ) ;
F_252 ( V_8 ) ;
}
if ( V_12 -> V_1025 & V_142 )
V_8 -> V_110 . V_173 = V_12 -> V_1027 ;
else if ( V_12 -> V_1025 & V_315 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_248 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_263 ( V_8 , V_12 -> V_230 ) ;
F_97 ( V_235 , F_152 ( V_12 ) ) ;
F_261 ( V_8 , V_12 -> V_232 ) ;
F_97 ( V_458 , F_153 ( V_12 ) ) ;
F_376 ( V_8 , V_12 -> V_505 ) ;
F_247 ( V_8 ) ;
F_378 ( V_8 , V_382 , V_12 -> V_1028 ) ;
F_378 ( V_8 , V_385 , V_12 -> V_1029 ) ;
}
static int F_465 ( struct V_7 * V_8 , bool V_1030 )
{
struct V_12 * V_12 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_89 * V_795 ;
bool V_1031 ;
if ( ! F_450 ( V_8 ) ||
! F_473 ( V_8 ) )
return 1 ;
F_162 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_431 )
F_452 ( V_72 ) ;
if ( V_12 -> V_826 == V_1030 ) {
F_449 ( V_8 ,
V_1030 ? V_1032
: V_1033 ) ;
return 1 ;
}
if ( V_12 -> V_1034 != V_642 ) {
F_449 ( V_8 , V_1035 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_462 ( V_12 -> V_268 , V_417 ) ) {
F_449 ( V_8 , V_1035 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_462 ( V_12 -> V_1022 , V_417 ) ) {
F_449 ( V_8 , V_1035 ) ;
return 1 ;
}
if ( V_12 -> V_1036 > 0 ||
V_12 -> V_1037 > 0 ||
V_12 -> V_1038 > 0 ) {
F_530 ( L_33 ,
V_478 ) ;
F_449 ( V_8 , V_1035 ) ;
return 1 ;
}
if ( ! F_192 ( V_12 -> V_69 ,
V_317 , V_318 ) ||
! F_192 ( V_12 -> V_70 ,
V_335 , V_336 ) ||
! F_192 ( V_12 -> V_71 ,
V_300 , V_301 ) ||
! F_192 ( V_12 -> V_1024 ,
V_306 , V_308 ) ||
! F_192 ( V_12 -> V_1025 ,
V_311 , V_312 ) )
{
F_449 ( V_8 , V_1035 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1039 & F_196 ) != F_196 ) ||
( ( V_12 -> V_1040 & F_197 ) != F_197 ) ) {
F_449 ( V_8 ,
V_1041 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_230 & F_196 ) != F_196 ) ||
( ( V_12 -> V_232 & F_197 ) != F_197 ) ) {
F_531 ( V_8 , V_12 ,
V_884 , V_1042 ) ;
return 1 ;
}
if ( V_12 -> V_1043 != - 1ull ) {
F_531 ( V_8 , V_12 ,
V_884 , V_1044 ) ;
return 1 ;
}
if ( V_12 -> V_1025 & V_142 ) {
V_1031 = ( V_12 -> V_1025 & V_315 ) != 0 ;
if ( ! F_532 ( V_8 , V_12 -> V_1027 ) ||
V_1031 != ! ! ( V_12 -> V_1027 & V_176 ) ||
( ( V_12 -> V_230 & V_493 ) &&
V_1031 != ! ! ( V_12 -> V_1027 & V_177 ) ) ) {
F_531 ( V_8 , V_12 ,
V_884 , V_1042 ) ;
return 1 ;
}
}
if ( V_12 -> V_1024 & V_143 ) {
V_1031 = ( V_12 -> V_1024 &
V_309 ) != 0 ;
if ( ! F_532 ( V_8 , V_12 -> V_1045 ) ||
V_1031 != ! ! ( V_12 -> V_1045 & V_176 ) ||
V_1031 != ! ! ( V_12 -> V_1045 & V_177 ) ) {
F_531 ( V_8 , V_12 ,
V_884 , V_1042 ) ;
return 1 ;
}
}
V_795 = F_439 ( V_72 ) ;
if ( ! V_795 )
return - V_428 ;
F_533 ( V_8 ) ;
V_72 -> V_13 . V_284 = F_93 ( V_283 ) ;
V_90 = F_518 () ;
V_72 -> V_89 = V_795 ;
F_148 ( V_8 ) ;
F_141 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_519 () ;
F_104 ( V_72 ) ;
V_12 -> V_826 = 1 ;
F_529 ( V_8 , V_12 ) ;
return 1 ;
}
static inline unsigned long
F_534 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_90 ( V_223 ) & V_8 -> V_110 . V_226 ) |
( V_12 -> V_230 & V_12 -> V_227 ) |
( F_90 ( V_235 ) & ~ ( V_12 -> V_227 |
V_8 -> V_110 . V_226 ) ) ;
}
static inline unsigned long
F_535 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_90 ( V_456 ) & V_8 -> V_110 . V_484 ) |
( V_12 -> V_232 & V_12 -> V_233 ) |
( F_90 ( V_458 ) & ~ ( V_12 -> V_233 |
V_8 -> V_110 . V_484 ) ) ;
}
static void F_536 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1046 ;
unsigned int V_148 ;
if ( V_8 -> V_110 . V_714 . V_1047 ) {
V_148 = V_8 -> V_110 . V_714 . V_148 ;
V_1046 = V_148 | V_699 ;
if ( F_168 ( V_148 ) ) {
V_12 -> V_1048 =
V_8 -> V_110 . V_259 ;
V_1046 |= V_263 ;
} else
V_1046 |= V_23 ;
if ( V_8 -> V_110 . V_714 . V_252 ) {
V_1046 |= V_758 ;
V_12 -> V_1049 =
V_8 -> V_110 . V_714 . V_253 ;
}
V_12 -> V_1050 = V_1046 ;
} else if ( V_8 -> V_110 . V_669 ) {
V_12 -> V_1050 =
V_663 | V_22 | V_662 ;
} else if ( V_8 -> V_110 . V_655 . V_1047 ) {
V_148 = V_8 -> V_110 . V_655 . V_148 ;
V_1046 = V_148 | V_699 ;
if ( V_8 -> V_110 . V_655 . V_657 ) {
V_1046 |= V_658 ;
V_12 -> V_1010 =
V_8 -> V_110 . V_259 ;
} else
V_1046 |= V_27 ;
V_12 -> V_1050 = V_1046 ;
}
}
static void F_537 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
V_12 -> V_230 = F_534 ( V_8 , V_12 ) ;
V_12 -> V_232 = F_535 ( V_8 , V_12 ) ;
F_385 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1013 ) ;
V_12 -> V_1028 = F_373 ( V_8 , V_382 ) ;
V_12 -> V_1029 = F_373 ( V_8 , V_385 ) ;
V_12 -> V_1014 = F_90 ( V_239 ) ;
V_12 -> V_952 = F_91 ( V_951 ) ;
V_12 -> V_953 = F_91 ( V_634 ) ;
V_12 -> V_955 = F_91 ( V_954 ) ;
V_12 -> V_957 = F_91 ( V_956 ) ;
V_12 -> V_959 = F_91 ( V_958 ) ;
V_12 -> V_961 = F_91 ( V_960 ) ;
V_12 -> V_962 = F_91 ( V_637 ) ;
V_12 -> V_963 = F_91 ( V_636 ) ;
V_12 -> V_965 = F_92 ( V_964 ) ;
V_12 -> V_967 = F_92 ( V_966 ) ;
V_12 -> V_969 = F_92 ( V_968 ) ;
V_12 -> V_971 = F_92 ( V_970 ) ;
V_12 -> V_973 = F_92 ( V_972 ) ;
V_12 -> V_975 = F_92 ( V_974 ) ;
V_12 -> V_976 = F_92 ( V_639 ) ;
V_12 -> V_977 = F_92 ( V_472 ) ;
V_12 -> V_978 = F_92 ( V_520 ) ;
V_12 -> V_979 = F_92 ( V_518 ) ;
V_12 -> V_981 = F_92 ( V_980 ) ;
V_12 -> V_983 = F_92 ( V_982 ) ;
V_12 -> V_985 = F_92 ( V_984 ) ;
V_12 -> V_987 = F_92 ( V_986 ) ;
V_12 -> V_989 = F_92 ( V_988 ) ;
V_12 -> V_991 = F_92 ( V_990 ) ;
V_12 -> V_992 = F_92 ( V_640 ) ;
V_12 -> V_993 = F_92 ( V_474 ) ;
V_12 -> V_995 = F_90 ( V_994 ) ;
V_12 -> V_996 = F_90 ( V_635 ) ;
V_12 -> V_998 = F_90 ( V_997 ) ;
V_12 -> V_1000 = F_90 ( V_999 ) ;
V_12 -> V_1001 = F_90 ( V_365 ) ;
V_12 -> V_1002 = F_90 ( V_366 ) ;
V_12 -> V_1003 = F_90 ( V_638 ) ;
V_12 -> V_1004 = F_90 ( V_471 ) ;
V_12 -> V_1005 = F_90 ( V_521 ) ;
V_12 -> V_1006 = F_90 ( V_519 ) ;
V_12 -> V_1011 =
F_92 ( V_244 ) ;
V_12 -> V_1015 =
F_90 ( V_643 ) ;
V_12 -> V_1025 =
( V_12 -> V_1025 & ~ V_315 ) |
( F_92 ( V_136 ) & V_315 ) ;
V_12 -> V_1007 = F_93 ( V_644 ) ;
if ( V_12 -> V_1024 & V_414 )
V_12 -> V_1026 = F_93 ( V_377 ) ;
V_12 -> V_1012 = F_92 ( V_369 ) ;
V_12 -> V_1016 = F_90 ( V_372 ) ;
V_12 -> V_1017 = F_90 ( V_371 ) ;
V_12 -> V_666 = F_6 ( V_8 ) -> V_701 ;
V_12 -> V_719 = F_90 ( V_707 ) ;
V_12 -> V_668 = F_92 ( V_858 ) ;
if ( ( V_12 -> V_668 &
( V_22 | V_257 ) ) ==
( V_22 | V_257 ) )
V_12 -> V_1051 =
F_92 ( V_698 ) ;
V_12 -> V_1050 = 0 ;
V_12 -> V_1048 = F_92 ( V_251 ) ;
V_12 -> V_805 = F_92 ( V_823 ) ;
if ( ! ( V_12 -> V_666 & V_897 ) ) {
V_12 -> V_1008 &= ~ V_22 ;
F_536 ( V_8 , V_12 ) ;
}
V_8 -> V_110 . V_757 = false ;
F_421 ( V_8 ) ;
F_420 ( V_8 ) ;
}
static void F_538 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
if ( V_12 -> V_1024 & V_143 )
V_8 -> V_110 . V_173 = V_12 -> V_1045 ;
else if ( V_12 -> V_1024 & V_309 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_248 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_378 ( V_8 , V_382 , V_12 -> V_1023 ) ;
F_378 ( V_8 , V_385 , V_12 -> V_1052 ) ;
F_159 ( V_8 , V_1053 ) ;
F_368 ( V_8 , V_12 -> V_1039 ) ;
F_110 ( V_8 ) ;
V_8 -> V_110 . V_226 = ( V_8 -> V_132 ? V_224 : 0 ) ;
F_97 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
V_8 -> V_110 . V_484 = ~ F_90 ( V_593 ) ;
F_370 ( V_8 , V_12 -> V_1040 ) ;
F_376 ( V_8 , V_12 -> V_1054 ) ;
F_247 ( V_8 ) ;
if ( V_430 ) {
F_252 ( V_8 ) ;
}
F_100 ( V_369 , V_12 -> V_1055 ) ;
F_97 ( V_372 , V_12 -> V_1056 ) ;
F_97 ( V_371 , V_12 -> V_1057 ) ;
F_97 ( V_519 , V_12 -> V_1058 ) ;
F_97 ( V_521 , V_12 -> V_1059 ) ;
F_97 ( V_471 , V_12 -> V_1060 ) ;
F_97 ( V_366 , V_12 -> V_1061 ) ;
F_97 ( V_365 , V_12 -> V_1062 ) ;
F_99 ( V_951 , V_12 -> V_1063 ) ;
F_99 ( V_634 , V_12 -> V_1064 ) ;
F_99 ( V_954 , V_12 -> V_1065 ) ;
F_99 ( V_956 , V_12 -> V_1066 ) ;
F_99 ( V_958 , V_12 -> V_1067 ) ;
F_99 ( V_960 , V_12 -> V_1068 ) ;
F_99 ( V_636 , V_12 -> V_1069 ) ;
if ( V_12 -> V_1024 & V_415 )
F_101 ( V_377 , V_12 -> V_1070 ) ;
if ( V_12 -> V_1024 & V_147 )
F_101 ( V_159 ,
V_12 -> V_1071 ) ;
F_386 ( V_8 , 7 , 0x400 ) ;
F_101 ( V_644 , 0 ) ;
}
static void F_166 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_539 ( V_72 -> V_13 . V_255 ) ;
F_540 ( V_8 ) ;
F_537 ( V_8 , V_12 ) ;
V_90 = F_518 () ;
V_72 -> V_89 = & V_72 -> V_799 ;
F_148 ( V_8 ) ;
F_141 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_519 () ;
F_104 ( V_72 ) ;
if ( V_797 == 0 )
F_445 ( V_72 , V_72 -> V_13 . V_792 ) ;
F_538 ( V_8 , V_12 ) ;
F_101 ( V_283 , V_72 -> V_13 . V_284 ) ;
V_72 -> V_1023 = 0 ;
if ( V_72 -> V_13 . V_552 ) {
F_13 ( V_72 -> V_13 . V_552 ) ;
V_72 -> V_13 . V_552 = 0 ;
}
if ( F_98 ( V_72 -> V_859 ) ) {
V_72 -> V_859 = 0 ;
F_449 ( V_8 , F_92 ( V_103 ) ) ;
} else
F_457 ( V_8 ) ;
if ( V_431 )
V_72 -> V_13 . V_803 = true ;
}
static void F_531 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_751 , unsigned long V_1072 )
{
F_538 ( V_8 , V_12 ) ;
V_12 -> V_666 = V_751 | V_897 ;
V_12 -> V_719 = V_1072 ;
F_457 ( V_8 ) ;
if ( V_431 )
F_6 ( V_8 ) -> V_13 . V_803 = true ;
}
static int F_541 ( struct V_7 * V_8 ,
struct V_1073 * V_1074 ,
enum V_1075 V_1076 )
{
return V_1077 ;
}
static int T_11 F_542 ( void )
{
int V_533 , V_74 , V_73 ;
F_543 ( V_140 , & V_178 ) ;
for ( V_74 = 0 ; V_74 < V_626 ; ++ V_74 )
F_544 ( V_74 , V_76 [ V_74 ] ) ;
V_597 = ( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_597 )
return - V_428 ;
V_533 = - V_428 ;
V_599 = ( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_599 )
goto V_516;
V_273 = ( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_273 )
goto V_1078;
V_271 =
( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_271 )
goto V_1079;
V_272 = ( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_272 )
goto V_1080;
V_270 =
( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_270 )
goto V_1081;
V_601 = ( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_601 )
goto V_1082;
V_603 = ( unsigned long * ) F_545 ( V_427 ) ;
if ( ! V_603 )
goto V_1083;
memset ( V_601 , 0xff , V_417 ) ;
memset ( V_603 , 0xff , V_417 ) ;
for ( V_74 = 0 ; V_74 < V_835 ; V_74 ++ ) {
F_546 ( V_833 [ V_74 ] , V_603 ) ;
F_546 ( V_833 [ V_74 ] , V_601 ) ;
}
for ( V_74 = 0 ; V_74 < V_839 ; V_74 ++ )
F_546 ( V_836 [ V_74 ] , V_601 ) ;
memset ( V_597 , 0xff , V_417 ) ;
F_546 ( 0x80 , V_597 ) ;
memset ( V_599 , 0xff , V_417 ) ;
memset ( V_273 , 0xff , V_417 ) ;
memset ( V_272 , 0xff , V_417 ) ;
F_547 ( 0 , V_560 ) ;
V_533 = F_548 ( & V_1084 , sizeof( struct V_6 ) ,
F_549 ( struct V_6 ) , V_1085 ) ;
if ( V_533 )
goto V_1086;
#ifdef F_550
F_551 ( V_1087 ,
F_76 ) ;
#endif
F_303 ( V_203 , false ) ;
F_303 ( V_205 , false ) ;
F_303 ( V_206 , true ) ;
F_303 ( V_368 , false ) ;
F_303 ( V_220 , false ) ;
F_303 ( V_370 , false ) ;
memcpy ( V_271 ,
V_273 , V_417 ) ;
memcpy ( V_270 ,
V_272 , V_417 ) ;
if ( V_437 ) {
for ( V_73 = 0x800 ; V_73 <= 0x8ff ; V_73 ++ )
F_305 ( V_73 ) ;
F_304 ( 0x802 ) ;
F_304 ( 0x839 ) ;
F_306 ( 0x808 ) ;
F_306 ( 0x80b ) ;
F_306 ( 0x83f ) ;
}
if ( V_100 ) {
F_552 ( 0ull ,
( V_433 ) ? V_1088 : 0ull ,
( V_433 ) ? V_1089 : 0ull ,
0ull , V_1090 ) ;
F_322 () ;
F_553 () ;
} else
F_554 () ;
return 0 ;
V_1086:
F_555 ( ( unsigned long ) V_603 ) ;
V_1083:
F_555 ( ( unsigned long ) V_601 ) ;
V_1082:
F_555 ( ( unsigned long ) V_270 ) ;
V_1081:
F_555 ( ( unsigned long ) V_272 ) ;
V_1080:
F_555 ( ( unsigned long ) V_271 ) ;
V_1079:
F_555 ( ( unsigned long ) V_273 ) ;
V_1078:
F_555 ( ( unsigned long ) V_599 ) ;
V_516:
F_555 ( ( unsigned long ) V_597 ) ;
return V_533 ;
}
static void T_12 F_556 ( void )
{
F_555 ( ( unsigned long ) V_271 ) ;
F_555 ( ( unsigned long ) V_270 ) ;
F_555 ( ( unsigned long ) V_273 ) ;
F_555 ( ( unsigned long ) V_272 ) ;
F_555 ( ( unsigned long ) V_599 ) ;
F_555 ( ( unsigned long ) V_597 ) ;
F_555 ( ( unsigned long ) V_603 ) ;
F_555 ( ( unsigned long ) V_601 ) ;
#ifdef F_550
F_551 ( V_1087 , NULL ) ;
F_557 () ;
#endif
F_558 () ;
}
