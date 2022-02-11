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
static inline bool F_59 ( struct V_12 * V_12 )
{
return V_12 -> V_71 & V_62 ;
}
static inline int F_60 ( struct V_12 * V_12 )
{
return F_58 ( V_12 , V_55 ) ;
}
static inline bool F_61 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_22 ) )
== ( V_23 | V_22 ) ;
}
static int F_62 ( struct V_6 * V_72 , T_2 V_73 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 -> V_75 ; ++ V_74 )
if ( V_76 [ V_72 -> V_77 [ V_74 ] . V_78 ] == V_73 )
return V_74 ;
return - 1 ;
}
static inline void F_63 ( int V_79 , T_4 V_52 , T_5 V_80 )
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
static inline void F_64 ( int V_79 , T_3 V_83 , T_1 V_84 )
{
struct {
T_3 V_83 , V_84 ;
} V_82 = { V_83 , V_84 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_85 * F_65 ( struct V_6 * V_72 , T_2 V_73 )
{
int V_74 ;
V_74 = F_62 ( V_72 , V_73 ) ;
if ( V_74 >= 0 )
return & V_72 -> V_77 [ V_74 ] ;
return NULL ;
}
static void F_66 ( struct V_86 * V_86 )
{
T_3 V_87 = F_67 ( V_86 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_68 ( V_88 L_1 ,
V_86 , V_87 ) ;
}
static inline void F_69 ( struct V_89 * V_89 )
{
F_66 ( V_89 -> V_86 ) ;
V_89 -> V_90 = - 1 ;
V_89 -> V_91 = 0 ;
}
static void F_70 ( struct V_86 * V_86 )
{
T_3 V_87 = F_67 ( V_86 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_68 ( V_88 L_2 ,
V_86 , V_87 ) ;
}
static inline void F_71 ( int V_90 )
{
F_72 ( V_90 , & V_92 ) ;
}
static inline void F_73 ( int V_90 )
{
F_74 ( V_90 , & V_92 ) ;
}
static inline int F_75 ( int V_90 )
{
return F_76 ( V_90 , & V_92 ) ;
}
static void F_77 ( void )
{
int V_90 = F_78 () ;
struct V_89 * V_93 ;
if ( ! F_75 ( V_90 ) )
return;
F_79 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_66 ( V_93 -> V_86 ) ;
}
static inline void F_71 ( int V_90 ) { }
static inline void F_73 ( int V_90 ) { }
static void F_80 ( void * V_94 )
{
struct V_89 * V_89 = V_94 ;
int V_90 = F_78 () ;
if ( V_89 -> V_90 != V_90 )
return;
if ( F_81 ( V_95 , V_90 ) == V_89 -> V_86 )
F_81 ( V_95 , V_90 ) = NULL ;
F_73 ( V_90 ) ;
F_82 ( & V_89 -> V_96 ) ;
F_83 () ;
F_69 ( V_89 ) ;
F_71 ( V_90 ) ;
}
static void F_84 ( struct V_89 * V_89 )
{
int V_90 = V_89 -> V_90 ;
if ( V_90 != - 1 )
F_85 ( V_90 ,
F_80 , V_89 , 1 ) ;
}
static inline void F_86 ( struct V_6 * V_72 )
{
if ( V_72 -> V_52 == 0 )
return;
if ( F_43 () )
F_63 ( V_97 , V_72 -> V_52 , 0 ) ;
}
static inline void F_87 ( void )
{
if ( F_44 () )
F_63 ( V_98 , 0 , 0 ) ;
}
static inline void F_88 ( struct V_6 * V_72 )
{
if ( F_43 () )
F_86 ( V_72 ) ;
else
F_87 () ;
}
static inline void F_89 ( void )
{
if ( F_42 () )
F_64 ( V_99 , 0 , 0 ) ;
}
static inline void F_90 ( T_3 V_83 )
{
if ( V_100 ) {
if ( F_41 () )
F_64 ( V_101 , V_83 , 0 ) ;
else
F_89 () ;
}
}
static T_7 unsigned long F_91 ( unsigned long V_9 )
{
unsigned long V_102 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_102 ;
}
static T_7 T_4 F_92 ( unsigned long V_9 )
{
return F_91 ( V_9 ) ;
}
static T_7 T_2 F_93 ( unsigned long V_9 )
{
return F_91 ( V_9 ) ;
}
static T_7 T_3 F_94 ( unsigned long V_9 )
{
#ifdef F_95
return F_91 ( V_9 ) ;
#else
return F_91 ( V_9 ) | ( ( T_3 ) F_91 ( V_9 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_96 ( unsigned long V_9 , unsigned long V_102 )
{
F_68 ( V_88 L_3 ,
V_9 , V_102 , F_93 ( V_103 ) ) ;
F_97 () ;
}
static void F_98 ( unsigned long V_9 , unsigned long V_102 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_99 ( error ) )
F_96 ( V_9 , V_102 ) ;
}
static void F_100 ( unsigned long V_9 , T_4 V_102 )
{
F_98 ( V_9 , V_102 ) ;
}
static void F_101 ( unsigned long V_9 , T_2 V_102 )
{
F_98 ( V_9 , V_102 ) ;
}
static void F_102 ( unsigned long V_9 , T_3 V_102 )
{
F_98 ( V_9 , V_102 ) ;
#ifndef F_95
asm volatile ("");
F_98 ( V_9 + 1 , V_102 >> 32 ) ;
#endif
}
static void F_103 ( unsigned long V_9 , T_2 V_104 )
{
F_98 ( V_9 , F_91 ( V_9 ) & ~ V_104 ) ;
}
static void F_104 ( unsigned long V_9 , T_2 V_104 )
{
F_98 ( V_9 , F_91 ( V_9 ) | V_104 ) ;
}
static void F_105 ( struct V_6 * V_72 )
{
V_72 -> V_105 . V_106 = 0 ;
}
static bool F_106 ( struct V_6 * V_72 , unsigned V_107 ,
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
static T_4 F_107 ( struct V_6 * V_72 , unsigned V_107 )
{
T_4 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_114 ;
if ( ! F_106 ( V_72 , V_107 , V_115 ) )
* V_113 = F_92 ( V_116 [ V_107 ] . V_114 ) ;
return * V_113 ;
}
static T_9 F_108 ( struct V_6 * V_72 , unsigned V_107 )
{
T_9 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_117 ;
if ( ! F_106 ( V_72 , V_107 , V_118 ) )
* V_113 = F_91 ( V_116 [ V_107 ] . V_117 ) ;
return * V_113 ;
}
static T_2 F_109 ( struct V_6 * V_72 , unsigned V_107 )
{
T_2 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_119 ;
if ( ! F_106 ( V_72 , V_107 , V_120 ) )
* V_113 = F_93 ( V_116 [ V_107 ] . V_119 ) ;
return * V_113 ;
}
static T_2 F_110 ( struct V_6 * V_72 , unsigned V_107 )
{
T_2 * V_113 = & V_72 -> V_105 . V_107 [ V_107 ] . V_121 ;
if ( ! F_106 ( V_72 , V_107 , V_122 ) )
* V_113 = F_93 ( V_116 [ V_107 ] . V_123 ) ;
return * V_113 ;
}
static void F_111 ( struct V_7 * V_8 )
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
if ( F_112 ( V_8 ) )
V_124 |= F_9 ( V_8 ) -> V_133 ;
F_101 ( V_134 , V_124 ) ;
}
static void F_113 ( unsigned long V_135 ,
unsigned long exit )
{
F_103 ( V_136 , V_135 ) ;
F_103 ( V_137 , exit ) ;
}
static void F_114 ( struct V_6 * V_72 , unsigned V_73 )
{
unsigned V_74 ;
struct V_138 * V_139 = & V_72 -> V_138 ;
switch ( V_73 ) {
case V_140 :
if ( V_141 ) {
F_113 ( V_142 ,
V_143 ) ;
return;
}
break;
case V_144 :
if ( V_145 ) {
F_113 (
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
F_101 ( V_151 , V_139 -> V_148 ) ;
F_101 ( V_152 , V_139 -> V_148 ) ;
}
static void F_115 ( unsigned long V_135 ,
unsigned long exit , unsigned long V_153 ,
unsigned long V_154 , T_3 V_155 , T_3 V_156 )
{
F_102 ( V_153 , V_155 ) ;
F_102 ( V_154 , V_156 ) ;
F_104 ( V_136 , V_135 ) ;
F_104 ( V_137 , exit ) ;
}
static void F_116 ( struct V_6 * V_72 , unsigned V_73 ,
T_3 V_155 , T_3 V_156 )
{
unsigned V_74 ;
struct V_138 * V_139 = & V_72 -> V_138 ;
switch ( V_73 ) {
case V_140 :
if ( V_141 ) {
F_115 ( V_142 ,
V_143 ,
V_157 ,
V_158 ,
V_155 , V_156 ) ;
return;
}
break;
case V_144 :
if ( V_145 ) {
F_115 (
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
F_117 ( V_162 L_4
L_5 , V_73 ) ;
return;
} else if ( V_74 == V_139 -> V_148 ) {
++ V_139 -> V_148 ;
F_101 ( V_151 , V_139 -> V_148 ) ;
F_101 ( V_152 , V_139 -> V_148 ) ;
}
V_139 -> V_149 [ V_74 ] . V_78 = V_73 ;
V_139 -> V_149 [ V_74 ] . V_102 = V_155 ;
V_139 -> V_150 [ V_74 ] . V_78 = V_73 ;
V_139 -> V_150 [ V_74 ] . V_102 = V_156 ;
}
static void F_118 ( void )
{
struct V_163 * V_164 = & F_119 ( V_165 ) ;
struct V_166 * V_167 ;
V_167 = ( void * ) V_164 -> V_168 ;
V_167 [ V_169 ] . type = 9 ;
F_120 () ;
}
static bool F_121 ( struct V_6 * V_72 , int V_170 )
{
T_3 V_171 ;
T_3 V_172 ;
V_171 = V_72 -> V_8 . V_110 . V_173 ;
V_172 = V_174 | V_175 ;
#ifdef F_95
V_172 |= V_176 | V_177 ;
if ( V_171 & V_176 )
V_172 &= ~ ( T_3 ) V_175 ;
#endif
V_171 &= ~ V_172 ;
V_171 |= V_178 & V_172 ;
V_72 -> V_77 [ V_170 ] . V_179 = V_171 ;
V_72 -> V_77 [ V_170 ] . V_104 = ~ V_172 ;
F_114 ( V_72 , V_140 ) ;
if ( V_100 && ( ( V_72 -> V_8 . V_110 . V_173 ^ V_178 ) & V_174 ) ) {
V_171 = V_72 -> V_8 . V_110 . V_173 ;
if ( ! ( V_171 & V_176 ) )
V_171 &= ~ V_177 ;
F_116 ( V_72 , V_140 , V_171 , V_178 ) ;
return false ;
}
return true ;
}
static unsigned long F_122 ( T_4 V_114 )
{
struct V_163 * V_164 = & F_119 ( V_165 ) ;
struct V_166 * V_180 ;
unsigned long V_181 ;
unsigned long V_93 ;
if ( ! ( V_114 & ~ 3 ) )
return 0 ;
V_181 = V_164 -> V_168 ;
if ( V_114 & 4 ) {
T_4 V_182 = F_123 () ;
if ( ! ( V_182 & ~ 3 ) )
return 0 ;
V_181 = F_122 ( V_182 ) ;
}
V_180 = (struct V_166 * ) ( V_181 + ( V_114 & ~ 7 ) ) ;
V_93 = F_124 ( V_180 ) ;
#ifdef F_95
if ( V_180 -> V_183 == 0 && ( V_180 -> type == 2 || V_180 -> type == 9 || V_180 -> type == 11 ) )
V_93 |= ( ( unsigned long ) ( (struct V_184 * ) V_180 ) -> V_185 ) << 32 ;
#endif
return V_93 ;
}
static inline unsigned long F_125 ( void )
{
T_4 V_186 ;
asm("str %0" : "=g"(tr));
return F_122 ( V_186 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_74 ;
if ( V_72 -> V_187 . V_188 )
return;
V_72 -> V_187 . V_188 = 1 ;
V_72 -> V_187 . V_189 = F_123 () ;
V_72 -> V_187 . V_190 = V_72 -> V_187 . V_189 ;
F_127 ( V_191 , V_72 -> V_187 . V_192 ) ;
if ( ! ( V_72 -> V_187 . V_192 & 7 ) ) {
F_100 ( V_193 , V_72 -> V_187 . V_192 ) ;
V_72 -> V_187 . V_194 = 0 ;
} else {
F_100 ( V_193 , 0 ) ;
V_72 -> V_187 . V_194 = 1 ;
}
F_127 ( V_195 , V_72 -> V_187 . V_196 ) ;
if ( ! ( V_72 -> V_187 . V_196 & 7 ) )
F_100 ( V_197 , V_72 -> V_187 . V_196 ) ;
else {
F_100 ( V_197 , 0 ) ;
V_72 -> V_187 . V_190 = 1 ;
}
#ifdef F_95
F_127 ( V_198 , V_72 -> V_187 . V_199 ) ;
F_127 ( V_200 , V_72 -> V_187 . V_201 ) ;
#endif
#ifdef F_95
F_98 ( V_202 , F_128 ( V_203 ) ) ;
F_98 ( V_204 , F_128 ( V_205 ) ) ;
#else
F_98 ( V_202 , F_122 ( V_72 -> V_187 . V_192 ) ) ;
F_98 ( V_204 , F_122 ( V_72 -> V_187 . V_196 ) ) ;
#endif
#ifdef F_95
F_55 ( V_206 , V_72 -> V_207 ) ;
if ( F_129 ( & V_72 -> V_8 ) )
F_130 ( V_206 , V_72 -> V_208 ) ;
#endif
for ( V_74 = 0 ; V_74 < V_72 -> V_209 ; ++ V_74 )
F_131 ( V_72 -> V_77 [ V_74 ] . V_78 ,
V_72 -> V_77 [ V_74 ] . V_179 ,
V_72 -> V_77 [ V_74 ] . V_104 ) ;
}
static void F_132 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_187 . V_188 )
return;
++ V_72 -> V_8 . V_210 . V_211 ;
V_72 -> V_187 . V_188 = 0 ;
#ifdef F_95
if ( F_129 ( & V_72 -> V_8 ) )
F_55 ( V_206 , V_72 -> V_208 ) ;
#endif
if ( V_72 -> V_187 . V_190 ) {
F_133 ( V_72 -> V_187 . V_189 ) ;
#ifdef F_95
F_134 ( V_72 -> V_187 . V_196 ) ;
#else
F_135 ( V_195 , V_72 -> V_187 . V_196 ) ;
#endif
}
if ( V_72 -> V_187 . V_194 )
F_135 ( V_191 , V_72 -> V_187 . V_192 ) ;
#ifdef F_95
if ( F_99 ( V_72 -> V_187 . V_199 | V_72 -> V_187 . V_201 ) ) {
F_135 ( V_198 , V_72 -> V_187 . V_199 ) ;
F_135 ( V_200 , V_72 -> V_187 . V_201 ) ;
}
#endif
F_118 () ;
#ifdef F_95
F_130 ( V_206 , V_72 -> V_207 ) ;
#endif
if ( ! F_136 () && ! V_72 -> V_8 . V_212 )
F_137 () ;
F_138 ( & F_119 ( V_165 ) ) ;
}
static void F_139 ( struct V_6 * V_72 )
{
F_140 () ;
F_132 ( V_72 ) ;
F_141 () ;
}
static void F_142 ( struct V_7 * V_8 , int V_90 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_87 = F_67 ( F_81 ( V_213 , V_90 ) ) ;
if ( ! V_214 )
F_143 ( V_87 ) ;
else if ( V_72 -> V_89 -> V_90 != V_90 )
F_84 ( V_72 -> V_89 ) ;
if ( F_81 ( V_95 , V_90 ) != V_72 -> V_89 -> V_86 ) {
F_81 ( V_95 , V_90 ) = V_72 -> V_89 -> V_86 ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
if ( V_72 -> V_89 -> V_90 != V_90 ) {
struct V_163 * V_164 = & F_119 ( V_165 ) ;
unsigned long V_215 ;
F_144 ( V_216 , V_8 ) ;
F_145 () ;
F_73 ( V_90 ) ;
F_146 () ;
F_147 ( & V_72 -> V_89 -> V_96 ,
& F_81 ( V_217 , V_90 ) ) ;
F_71 ( V_90 ) ;
F_148 () ;
F_98 ( V_218 , F_125 () ) ;
F_98 ( V_219 , V_164 -> V_168 ) ;
F_55 ( V_220 , V_215 ) ;
F_98 ( V_221 , V_215 ) ;
V_72 -> V_89 -> V_90 = V_90 ;
}
}
static void F_149 ( struct V_7 * V_8 )
{
F_132 ( F_6 ( V_8 ) ) ;
if ( ! V_214 ) {
F_80 ( F_6 ( V_8 ) -> V_89 ) ;
V_8 -> V_90 = - 1 ;
F_150 () ;
}
}
static void F_151 ( struct V_7 * V_8 )
{
T_9 V_222 ;
if ( V_8 -> V_132 )
return;
V_8 -> V_132 = 1 ;
V_222 = F_91 ( V_223 ) ;
V_222 &= ~ ( V_224 | V_225 ) ;
V_222 |= F_152 ( V_8 , V_224 | V_225 ) ;
F_98 ( V_223 , V_222 ) ;
F_111 ( V_8 ) ;
V_8 -> V_110 . V_226 = V_224 ;
if ( F_112 ( V_8 ) )
V_8 -> V_110 . V_226 &=
~ F_9 ( V_8 ) -> V_227 ;
F_98 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
}
static inline unsigned long F_153 ( struct V_12 * V_229 )
{
return ( V_229 -> V_230 & ~ V_229 -> V_227 ) |
( V_229 -> V_231 & V_229 -> V_227 ) ;
}
static inline unsigned long F_154 ( struct V_12 * V_229 )
{
return ( V_229 -> V_232 & ~ V_229 -> V_233 ) |
( V_229 -> V_234 & V_229 -> V_233 ) ;
}
static void F_155 ( struct V_7 * V_8 )
{
F_156 ( V_8 ) ;
F_104 ( V_223 , V_224 | V_225 ) ;
F_111 ( V_8 ) ;
V_8 -> V_110 . V_226 = 0 ;
F_98 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
V_12 -> V_230 = ( V_12 -> V_230 & ~ V_224 ) |
( V_8 -> V_110 . V_222 & V_224 ) ;
F_98 ( V_235 , F_153 ( V_12 ) ) ;
} else
F_98 ( V_235 , V_8 -> V_110 . V_222 ) ;
}
static unsigned long F_157 ( struct V_7 * V_8 )
{
unsigned long V_236 , V_237 ;
if ( ! F_158 ( V_238 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ) {
F_159 ( V_238 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_236 = F_91 ( V_239 ) ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
V_236 &= V_240 ;
V_237 = F_6 ( V_8 ) -> V_130 . V_237 ;
V_236 |= V_237 & ~ V_240 ;
}
F_6 ( V_8 ) -> V_236 = V_236 ;
}
return F_6 ( V_8 ) -> V_236 ;
}
static void F_160 ( struct V_7 * V_8 , unsigned long V_236 )
{
F_159 ( V_238 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
F_6 ( V_8 ) -> V_236 = V_236 ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
F_6 ( V_8 ) -> V_130 . V_237 = V_236 ;
V_236 |= V_241 | V_242 ;
}
F_98 ( V_239 , V_236 ) ;
}
static T_2 F_161 ( struct V_7 * V_8 , int V_104 )
{
T_2 V_243 = F_93 ( V_244 ) ;
int V_108 = 0 ;
if ( V_243 & V_245 )
V_108 |= V_246 ;
if ( V_243 & V_247 )
V_108 |= V_248 ;
return V_108 & V_104 ;
}
static void F_162 ( struct V_7 * V_8 , int V_104 )
{
T_2 V_249 = F_93 ( V_244 ) ;
T_2 V_243 = V_249 ;
V_243 &= ~ ( V_245 | V_247 ) ;
if ( V_104 & V_248 )
V_243 |= V_247 ;
else if ( V_104 & V_246 )
V_243 |= V_245 ;
if ( ( V_243 != V_249 ) )
F_101 ( V_244 , V_243 ) ;
}
static void F_163 ( struct V_7 * V_8 )
{
unsigned long V_250 ;
V_250 = F_164 ( V_8 ) ;
V_250 += F_93 ( V_251 ) ;
F_165 ( V_8 , V_250 ) ;
F_162 ( V_8 , 0 ) ;
}
static int F_166 ( struct V_7 * V_8 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( ! ( V_12 -> V_133 & ( 1u << V_24 ) ) )
return 0 ;
F_167 ( V_8 ) ;
return 1 ;
}
static void F_168 ( struct V_7 * V_8 , unsigned V_148 ,
bool V_252 , T_2 V_253 ,
bool V_254 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_19 = V_148 | V_22 ;
if ( V_148 == V_24 && F_112 ( V_8 ) &&
! V_72 -> V_13 . V_255 && F_166 ( V_8 ) )
return;
if ( V_252 ) {
F_101 ( V_256 , V_253 ) ;
V_19 |= V_257 ;
}
if ( V_72 -> V_130 . V_131 ) {
int V_258 = 0 ;
if ( F_169 ( V_148 ) )
V_258 = V_8 -> V_110 . V_259 ;
if ( F_170 ( V_8 , V_148 , V_258 ) != V_260 )
F_144 ( V_261 , V_8 ) ;
return;
}
if ( F_169 ( V_148 ) ) {
F_101 ( V_262 ,
V_72 -> V_8 . V_110 . V_259 ) ;
V_19 |= V_263 ;
} else
V_19 |= V_23 ;
F_101 ( V_264 , V_19 ) ;
}
static bool F_171 ( void )
{
return F_50 () ;
}
static bool F_172 ( void )
{
return F_51 () && V_100 ;
}
static void F_173 ( struct V_6 * V_72 , int V_265 , int V_266 )
{
struct V_85 V_267 ;
V_267 = V_72 -> V_77 [ V_266 ] ;
V_72 -> V_77 [ V_266 ] = V_72 -> V_77 [ V_265 ] ;
V_72 -> V_77 [ V_265 ] = V_267 ;
}
static void F_174 ( struct V_7 * V_8 )
{
unsigned long * V_268 ;
if ( F_25 ( V_8 -> V_17 ) && F_175 ( V_8 -> V_110 . V_269 ) ) {
if ( F_129 ( V_8 ) )
V_268 = V_270 ;
else
V_268 = V_271 ;
} else {
if ( F_129 ( V_8 ) )
V_268 = V_272 ;
else
V_268 = V_273 ;
}
F_102 ( V_274 , F_67 ( V_268 ) ) ;
}
static void F_176 ( struct V_6 * V_72 )
{
int V_209 , V_78 ;
V_209 = 0 ;
#ifdef F_95
if ( F_129 ( & V_72 -> V_8 ) ) {
V_78 = F_62 ( V_72 , V_275 ) ;
if ( V_78 >= 0 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_276 ) ;
if ( V_78 >= 0 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_277 ) ;
if ( V_78 >= 0 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_278 ) ;
if ( V_78 >= 0 && V_72 -> V_279 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_280 ) ;
if ( ( V_78 >= 0 ) && ( V_72 -> V_8 . V_110 . V_173 & V_175 ) )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
}
#endif
V_78 = F_62 ( V_72 , V_140 ) ;
if ( V_78 >= 0 && F_121 ( V_72 , V_78 ) )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_72 -> V_209 = V_209 ;
if ( F_22 () )
F_174 ( & V_72 -> V_8 ) ;
}
static T_3 F_177 ( void )
{
T_3 V_281 , V_282 ;
F_178 ( V_281 ) ;
V_282 = F_94 ( V_283 ) ;
return V_281 + V_282 ;
}
T_3 F_179 ( struct V_7 * V_8 , T_3 V_281 )
{
T_3 V_282 ;
V_282 = F_112 ( V_8 ) ?
F_6 ( V_8 ) -> V_13 . V_284 :
F_94 ( V_283 ) ;
return V_281 + V_282 ;
}
static void F_180 ( struct V_7 * V_8 , T_2 V_285 , bool V_286 )
{
if ( ! V_286 )
return;
if ( V_285 > V_287 ) {
V_8 -> V_110 . V_288 = 1 ;
V_8 -> V_110 . V_289 = 1 ;
} else
F_181 ( 1 , L_6 ) ;
}
static T_3 F_182 ( struct V_7 * V_8 )
{
return F_94 ( V_283 ) ;
}
static void F_183 ( struct V_7 * V_8 , T_3 V_290 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 ;
F_6 ( V_8 ) -> V_13 . V_284 = V_290 ;
V_12 = F_9 ( V_8 ) ;
F_102 ( V_283 , V_290 +
( F_57 ( V_12 , V_291 ) ?
V_12 -> V_282 : 0 ) ) ;
} else {
F_184 ( V_8 -> V_292 ,
F_94 ( V_283 ) , V_290 ) ;
F_102 ( V_283 , V_290 ) ;
}
}
static void F_185 ( struct V_7 * V_8 , T_10 V_293 , bool V_150 )
{
T_3 V_290 = F_94 ( V_283 ) ;
F_102 ( V_283 , V_290 + V_293 ) ;
if ( F_112 ( V_8 ) ) {
F_6 ( V_8 ) -> V_13 . V_284 += V_293 ;
} else
F_184 ( V_8 -> V_292 , V_290 ,
V_290 + V_293 ) ;
}
static T_3 F_186 ( struct V_7 * V_8 , T_3 V_294 )
{
return V_294 - F_187 () ;
}
static bool F_188 ( struct V_7 * V_8 )
{
struct V_295 * V_296 = F_189 ( V_8 , 1 , 0 ) ;
return V_296 && ( V_296 -> V_297 & ( 1 << ( V_298 & 31 ) ) ) ;
}
static inline bool F_190 ( struct V_7 * V_8 )
{
return V_13 && F_188 ( V_8 ) ;
}
static T_11 void F_191 ( void )
{
F_192 ( V_299 ,
V_300 , V_301 ) ;
V_300 |= V_302 ;
V_301 &= V_303 |
V_304 | V_62 |
V_305 ;
V_301 |= V_302 ;
F_192 ( V_306 ,
V_307 , V_308 ) ;
V_307 = V_309 ;
V_308 &=
#ifdef F_95
V_310 |
#endif
V_311 | V_312 ;
V_308 |= ( V_309 |
V_143 ) ;
F_192 ( V_313 ,
V_314 , V_315 ) ;
V_314 = V_316 ;
V_315 &=
#ifdef F_95
V_317 |
#endif
V_318 ;
V_315 |= ( V_316 |
V_142 ) ;
F_192 ( V_319 ,
V_320 , V_321 ) ;
V_320 = 0 ;
V_321 &=
V_322 | V_291 |
V_323 | V_324 |
V_325 | V_326 |
V_327 |
#ifdef F_95
V_328 | V_329 |
#endif
V_330 | V_331 |
V_332 | V_333 |
V_334 | V_335 |
V_336 |
V_33 ;
V_321 |= V_31 ;
F_192 ( V_337 ,
V_338 , V_339 ) ;
V_338 = 0 ;
V_339 &=
V_35 |
V_63 ;
if ( V_100 ) {
V_339 |= V_55 ;
V_340 = V_48 |
V_45 | V_341 ;
V_340 &= V_41 . V_42 ;
V_340 |= V_51 |
V_50 ;
} else
V_340 = 0 ;
F_192 ( V_65 , V_342 , V_343 ) ;
V_342 &= V_344 |
V_345 ;
V_343 = 0 ;
}
static inline bool F_193 ( T_2 V_3 , T_2 V_346 , T_2 V_347 )
{
return ( ( V_3 & V_347 ) | V_346 ) == V_3 ;
}
static inline T_3 F_194 ( T_2 V_346 , T_2 V_347 )
{
return V_346 | ( ( T_3 ) V_347 << 32 ) ;
}
static int F_195 ( struct V_7 * V_8 , T_2 V_348 , T_3 * V_349 )
{
if ( ! F_190 ( V_8 ) && V_348 >= V_350 &&
V_348 <= V_351 ) {
F_196 ( V_8 , V_352 , 0 ) ;
return 1 ;
}
switch ( V_348 ) {
case V_353 :
if ( F_190 ( V_8 ) ) {
* V_349 = F_6 ( V_8 ) -> V_13 . V_354 ;
break;
}
return 0 ;
case V_350 :
* V_349 = V_355 |
( ( T_3 ) V_356 << V_357 ) |
( V_358 << V_359 ) ;
break;
case V_360 :
case V_299 :
* V_349 = F_194 ( V_300 ,
V_301 ) ;
break;
case V_361 :
case V_319 :
* V_349 = F_194 ( V_320 ,
V_321 ) ;
break;
case V_362 :
case V_306 :
* V_349 = F_194 ( V_307 ,
V_308 ) ;
break;
case V_351 :
case V_313 :
* V_349 = F_194 ( V_314 ,
V_315 ) ;
break;
case V_65 :
* V_349 = F_194 ( V_342 ,
V_343 ) ;
break;
#define F_197 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_198 X86_CR4_VMXE
case V_363 :
* V_349 = F_197 ;
break;
case V_364 :
* V_349 = - 1ULL ;
break;
case V_365 :
* V_349 = F_198 ;
break;
case V_366 :
* V_349 = - 1ULL ;
break;
case V_367 :
* V_349 = 0x1f ;
break;
case V_337 :
* V_349 = F_194 ( V_338 ,
V_339 ) ;
break;
case V_368 :
* V_349 = V_340 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_199 ( struct V_7 * V_8 , struct V_369 * V_370 )
{
T_2 V_348 = V_370 -> V_78 ;
T_3 V_179 = V_370 -> V_179 ;
bool V_371 = V_370 -> V_372 ;
if ( ! F_190 ( V_8 ) )
return 0 ;
if ( V_348 == V_353 ) {
if ( ! V_371 &&
F_6 ( V_8 ) -> V_13 . V_354
& V_373 )
return 0 ;
F_6 ( V_8 ) -> V_13 . V_354 = V_179 ;
return 1 ;
}
return 0 ;
}
static int F_200 ( struct V_7 * V_8 , T_2 V_348 , T_3 * V_349 )
{
T_3 V_179 ;
struct V_85 * V_73 ;
if ( ! V_349 ) {
F_68 ( V_88 L_7 ) ;
return - V_374 ;
}
switch ( V_348 ) {
#ifdef F_95
case V_203 :
V_179 = F_91 ( V_375 ) ;
break;
case V_205 :
V_179 = F_91 ( V_376 ) ;
break;
case V_206 :
F_139 ( F_6 ( V_8 ) ) ;
V_179 = F_6 ( V_8 ) -> V_208 ;
break;
#endif
case V_140 :
return F_201 ( V_8 , V_348 , V_349 ) ;
case V_377 :
V_179 = F_177 () ;
break;
case V_378 :
V_179 = F_93 ( V_379 ) ;
break;
case V_380 :
V_179 = F_91 ( V_381 ) ;
break;
case V_220 :
V_179 = F_91 ( V_382 ) ;
break;
case V_278 :
if ( ! F_6 ( V_8 ) -> V_279 )
return 1 ;
default:
if ( F_195 ( V_8 , V_348 , V_349 ) )
return 0 ;
V_73 = F_65 ( F_6 ( V_8 ) , V_348 ) ;
if ( V_73 ) {
V_179 = V_73 -> V_179 ;
break;
}
return F_201 ( V_8 , V_348 , V_349 ) ;
}
* V_349 = V_179 ;
return 0 ;
}
static int F_202 ( struct V_7 * V_8 , struct V_369 * V_370 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 ;
int V_108 = 0 ;
T_2 V_348 = V_370 -> V_78 ;
T_3 V_179 = V_370 -> V_179 ;
switch ( V_348 ) {
case V_140 :
V_108 = F_203 ( V_8 , V_370 ) ;
break;
#ifdef F_95
case V_203 :
F_105 ( V_72 ) ;
F_98 ( V_375 , V_179 ) ;
break;
case V_205 :
F_105 ( V_72 ) ;
F_98 ( V_376 , V_179 ) ;
break;
case V_206 :
F_139 ( V_72 ) ;
V_72 -> V_208 = V_179 ;
break;
#endif
case V_378 :
F_101 ( V_379 , V_179 ) ;
break;
case V_380 :
F_98 ( V_381 , V_179 ) ;
break;
case V_220 :
F_98 ( V_382 , V_179 ) ;
break;
case V_377 :
F_204 ( V_8 , V_370 ) ;
break;
case V_383 :
if ( V_29 . V_384 & V_318 ) {
F_102 ( V_385 , V_179 ) ;
V_8 -> V_110 . V_386 = V_179 ;
break;
}
V_108 = F_203 ( V_8 , V_370 ) ;
break;
case V_387 :
V_108 = F_203 ( V_8 , V_370 ) ;
break;
case V_278 :
if ( ! V_72 -> V_279 )
return 1 ;
if ( ( V_179 >> 32 ) != 0 )
return 1 ;
default:
if ( F_199 ( V_8 , V_370 ) )
break;
V_73 = F_65 ( V_72 , V_348 ) ;
if ( V_73 ) {
V_73 -> V_179 = V_179 ;
if ( V_73 - V_72 -> V_77 < V_72 -> V_209 ) {
F_140 () ;
F_131 ( V_73 -> V_78 , V_73 -> V_179 ,
V_73 -> V_104 ) ;
F_141 () ;
}
break;
}
V_108 = F_203 ( V_8 , V_370 ) ;
}
return V_108 ;
}
static void F_205 ( struct V_7 * V_8 , enum V_388 V_389 )
{
F_159 ( V_389 , ( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
switch ( V_389 ) {
case V_390 :
V_8 -> V_110 . V_391 [ V_390 ] = F_91 ( V_392 ) ;
break;
case V_393 :
V_8 -> V_110 . V_391 [ V_393 ] = F_91 ( V_394 ) ;
break;
case V_395 :
if ( V_100 )
F_206 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_207 ( void )
{
return F_208 () ;
}
static T_11 int F_209 ( void )
{
T_3 V_73 ;
F_55 ( V_353 , V_73 ) ;
if ( V_73 & V_373 ) {
if ( ! ( V_73 & V_396 )
&& F_210 () )
return 1 ;
if ( ! ( V_73 & V_397 )
&& ( V_73 & V_396 )
&& ! F_210 () ) {
F_68 ( V_162 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_73 & V_397 )
&& ! F_210 () )
return 1 ;
}
return 0 ;
}
static void F_143 ( T_3 V_16 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_211 ( void * V_398 )
{
int V_90 = F_78 () ;
T_3 V_87 = F_67 ( F_81 ( V_213 , V_90 ) ) ;
T_3 V_399 , V_400 ;
if ( F_212 () & V_401 )
return - V_402 ;
F_213 ( & F_81 ( V_217 , V_90 ) ) ;
F_71 ( V_90 ) ;
F_55 ( V_353 , V_399 ) ;
V_400 = V_373 ;
V_400 |= V_397 ;
if ( F_210 () )
V_400 |= V_396 ;
if ( ( V_399 & V_400 ) != V_400 ) {
F_130 ( V_353 , V_399 | V_400 ) ;
}
F_214 ( F_212 () | V_401 ) ;
if ( V_214 ) {
F_143 ( V_87 ) ;
F_89 () ;
}
F_215 ( & F_119 ( V_165 ) ) ;
return 0 ;
}
static void F_216 ( void )
{
int V_90 = F_78 () ;
struct V_89 * V_93 , * V_403 ;
F_217 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_80 ( V_93 ) ;
}
static void F_150 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_218 ( void * V_398 )
{
if ( V_214 ) {
F_216 () ;
F_150 () ;
}
F_214 ( F_212 () & ~ V_401 ) ;
}
static T_11 int F_219 ( T_2 V_404 , T_2 V_405 ,
T_2 V_73 , T_2 * V_406 )
{
T_2 V_407 , V_408 ;
T_2 V_409 = V_404 | V_405 ;
F_192 ( V_73 , V_407 , V_408 ) ;
V_409 &= V_408 ;
V_409 |= V_407 ;
if ( V_404 & ~ V_409 )
return - V_410 ;
* V_406 = V_409 ;
return 0 ;
}
static T_11 bool F_220 ( T_2 V_73 , T_2 V_409 )
{
T_2 V_407 , V_408 ;
F_192 ( V_73 , V_407 , V_408 ) ;
return V_408 & V_409 ;
}
static T_11 int F_221 ( struct V_29 * V_411 )
{
T_2 V_407 , V_408 ;
T_2 V_412 , V_413 , V_414 , V_415 ;
T_2 V_416 = 0 ;
T_2 V_417 = 0 ;
T_2 V_418 = 0 ;
T_2 V_419 = 0 ;
T_2 V_420 = 0 ;
V_412 = V_323 |
#ifdef F_95
V_328 |
V_329 |
#endif
V_326 |
V_327 |
V_332 |
V_330 |
V_291 |
V_325 |
V_333 |
V_324 |
V_334 ;
V_413 = V_32 |
V_31 |
V_33 ;
if ( F_219 ( V_412 , V_413 , V_319 ,
& V_417 ) < 0 )
return - V_410 ;
#ifdef F_95
if ( ( V_417 & V_32 ) )
V_417 &= ~ V_328 &
~ V_329 ;
#endif
if ( V_417 & V_33 ) {
V_414 = 0 ;
V_415 = V_35 |
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
if ( F_219 ( V_414 , V_415 ,
V_337 ,
& V_418 ) < 0 )
return - V_410 ;
}
#ifndef F_95
if ( ! ( V_418 &
V_35 ) )
V_417 &= ~ V_32 ;
#endif
if ( ! ( V_417 & V_32 ) )
V_418 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_418 & V_55 ) {
V_417 &= ~ ( V_326 |
V_327 |
V_324 ) ;
F_192 ( V_368 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_412 = 0 ;
#ifdef F_95
V_412 |= V_310 ;
#endif
V_413 = V_312 | V_311 |
V_421 ;
if ( F_219 ( V_412 , V_413 , V_306 ,
& V_419 ) < 0 )
return - V_410 ;
V_412 = V_303 | V_304 ;
V_413 = V_62 | V_40 ;
if ( F_219 ( V_412 , V_413 , V_299 ,
& V_416 ) < 0 )
return - V_410 ;
if ( ! ( V_418 &
V_38 ) ||
! ( V_419 & V_421 ) )
V_416 &= ~ V_40 ;
V_412 = 0 ;
V_413 = V_318 ;
if ( F_219 ( V_412 , V_413 , V_313 ,
& V_420 ) < 0 )
return - V_410 ;
F_192 ( V_350 , V_407 , V_408 ) ;
if ( ( V_408 & 0x1fff ) > V_422 )
return - V_410 ;
#ifdef F_95
if ( V_408 & ( 1u << 16 ) )
return - V_410 ;
#endif
if ( ( ( V_408 >> 18 ) & 15 ) != 6 )
return - V_410 ;
V_411 -> V_423 = V_408 & 0x1fff ;
V_411 -> V_424 = F_222 ( V_29 . V_423 ) ;
V_411 -> V_425 = V_407 ;
V_411 -> V_39 = V_416 ;
V_411 -> V_30 = V_417 ;
V_411 -> V_34 = V_418 ;
V_411 -> V_426 = V_419 ;
V_411 -> V_384 = V_420 ;
V_141 =
F_220 ( V_313 ,
V_142 )
&& F_220 ( V_306 ,
V_143 ) ;
V_145 =
F_220 ( V_313 ,
V_146 )
&& F_220 ( V_306 ,
V_147 ) ;
if ( V_145 && V_427 . V_428 == 0x6 ) {
switch ( V_427 . V_429 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_145 = false ;
F_117 ( V_162 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_86 * F_223 ( int V_90 )
{
int V_430 = F_224 ( V_90 ) ;
struct V_15 * V_431 ;
struct V_86 * V_86 ;
V_431 = F_225 ( V_430 , V_432 , V_29 . V_424 ) ;
if ( ! V_431 )
return NULL ;
V_86 = F_226 ( V_431 ) ;
memset ( V_86 , 0 , V_29 . V_423 ) ;
V_86 -> V_425 = V_29 . V_425 ;
return V_86 ;
}
static struct V_86 * F_227 ( void )
{
return F_223 ( F_78 () ) ;
}
static void F_228 ( struct V_86 * V_86 )
{
F_229 ( ( unsigned long ) V_86 , V_29 . V_424 ) ;
}
static void F_230 ( struct V_89 * V_89 )
{
if ( ! V_89 -> V_86 )
return;
F_84 ( V_89 ) ;
F_228 ( V_89 -> V_86 ) ;
V_89 -> V_86 = NULL ;
}
static void F_231 ( void )
{
int V_90 ;
F_232 (cpu) {
F_228 ( F_81 ( V_213 , V_90 ) ) ;
F_81 ( V_213 , V_90 ) = NULL ;
}
}
static T_11 int F_233 ( void )
{
int V_90 ;
F_232 (cpu) {
struct V_86 * V_86 ;
V_86 = F_223 ( V_90 ) ;
if ( ! V_86 ) {
F_231 () ;
return - V_433 ;
}
F_81 ( V_213 , V_90 ) = V_86 ;
}
return 0 ;
}
static T_11 int F_234 ( void )
{
if ( F_221 ( & V_29 ) < 0 )
return - V_410 ;
if ( F_235 ( V_434 ) )
F_236 ( V_174 ) ;
if ( ! F_49 () )
V_435 = 0 ;
if ( ! F_54 () )
V_436 = 0 ;
if ( ! F_45 () ||
! F_39 () ) {
V_100 = 0 ;
V_437 = 0 ;
V_438 = 0 ;
}
if ( ! F_40 () )
V_438 = 0 ;
if ( ! F_46 () )
V_437 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_439 -> V_440 = NULL ;
if ( V_100 && ! F_37 () )
F_237 () ;
if ( ! F_47 () )
V_441 = 0 ;
if ( ! F_32 () )
V_442 = 0 ;
if ( V_442 )
V_439 -> V_440 = NULL ;
else {
V_439 -> V_443 = NULL ;
V_439 -> V_444 = NULL ;
V_439 -> V_445 = V_446 ;
}
if ( V_13 )
F_191 () ;
return F_233 () ;
}
static T_12 void F_238 ( void )
{
F_231 () ;
}
static bool F_239 ( struct V_7 * V_8 )
{
return V_447 && ! F_240 ( V_8 ) ;
}
static void F_241 ( struct V_7 * V_8 , int V_107 ,
struct V_448 * V_449 )
{
if ( ! V_447 ) {
if ( V_107 == V_450 || V_107 == V_451 )
V_449 -> V_114 &= ~ V_452 ;
V_449 -> V_453 = V_449 -> V_114 & V_452 ;
V_449 -> V_183 = 1 ;
}
F_242 ( V_8 , V_449 , V_107 ) ;
}
static void F_243 ( struct V_7 * V_8 )
{
unsigned long V_454 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_456 ] , V_456 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_457 ] , V_457 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_458 ] , V_458 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_459 ] , V_459 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_451 ] , V_451 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_450 ] , V_450 ) ;
V_72 -> V_130 . V_131 = 0 ;
F_105 ( V_72 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_455 [ V_460 ] , V_460 ) ;
V_454 = F_91 ( V_239 ) ;
V_454 &= V_240 ;
V_454 |= V_72 -> V_130 . V_237 & ~ V_240 ;
F_98 ( V_239 , V_454 ) ;
F_98 ( V_461 , ( F_91 ( V_461 ) & ~ V_462 ) |
( F_91 ( V_463 ) & V_462 ) ) ;
F_111 ( V_8 ) ;
F_241 ( V_8 , V_450 , & V_72 -> V_130 . V_455 [ V_450 ] ) ;
F_241 ( V_8 , V_451 , & V_72 -> V_130 . V_455 [ V_451 ] ) ;
F_241 ( V_8 , V_456 , & V_72 -> V_130 . V_455 [ V_456 ] ) ;
F_241 ( V_8 , V_457 , & V_72 -> V_130 . V_455 [ V_457 ] ) ;
F_241 ( V_8 , V_458 , & V_72 -> V_130 . V_455 [ V_458 ] ) ;
F_241 ( V_8 , V_459 , & V_72 -> V_130 . V_455 [ V_459 ] ) ;
F_159 ( V_464 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_465 = 0 ;
}
static void F_245 ( int V_107 , struct V_448 * V_449 )
{
const struct V_466 * V_467 = & V_116 [ V_107 ] ;
struct V_448 V_468 = * V_449 ;
V_468 . V_453 = 0x3 ;
if ( V_107 == V_450 )
V_468 . type = 0x3 ;
if ( ! V_447 ) {
V_468 . V_114 = V_468 . V_117 >> 4 ;
V_468 . V_117 = V_468 . V_117 & 0xffff0 ;
V_468 . V_119 = 0xffff ;
V_468 . V_469 = 0 ;
V_468 . V_470 = 0 ;
V_468 . V_471 = 1 ;
V_468 . V_183 = 1 ;
V_468 . V_472 = 0 ;
V_468 . V_473 = 0 ;
V_468 . type = 0x3 ;
V_468 . V_474 = 0 ;
if ( V_449 -> V_117 & 0xf )
F_117 ( V_162 L_12
L_13
L_14 , V_107 ) ;
}
F_100 ( V_467 -> V_114 , V_468 . V_114 ) ;
F_101 ( V_467 -> V_117 , V_468 . V_117 ) ;
F_101 ( V_467 -> V_119 , V_468 . V_119 ) ;
F_101 ( V_467 -> V_123 , F_246 ( & V_468 ) ) ;
}
static void F_247 ( struct V_7 * V_8 )
{
unsigned long V_454 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_460 ] , V_460 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_456 ] , V_456 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_457 ] , V_457 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_458 ] , V_458 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_459 ] , V_459 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_451 ] , V_451 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_455 [ V_450 ] , V_450 ) ;
V_72 -> V_130 . V_131 = 1 ;
if ( ! V_8 -> V_17 -> V_110 . V_475 )
F_117 ( V_162 L_15
L_16 ) ;
F_105 ( V_72 ) ;
F_98 ( V_476 , V_8 -> V_17 -> V_110 . V_475 ) ;
F_101 ( V_477 , V_478 - 1 ) ;
F_101 ( V_479 , 0x008b ) ;
V_454 = F_91 ( V_239 ) ;
V_72 -> V_130 . V_237 = V_454 ;
V_454 |= V_241 | V_242 ;
F_98 ( V_239 , V_454 ) ;
F_98 ( V_461 , F_91 ( V_461 ) | V_462 ) ;
F_111 ( V_8 ) ;
F_245 ( V_451 , & V_72 -> V_130 . V_455 [ V_451 ] ) ;
F_245 ( V_450 , & V_72 -> V_130 . V_455 [ V_450 ] ) ;
F_245 ( V_456 , & V_72 -> V_130 . V_455 [ V_456 ] ) ;
F_245 ( V_457 , & V_72 -> V_130 . V_455 [ V_457 ] ) ;
F_245 ( V_459 , & V_72 -> V_130 . V_455 [ V_459 ] ) ;
F_245 ( V_458 , & V_72 -> V_130 . V_455 [ V_458 ] ) ;
F_248 ( V_8 ) ;
}
static void F_249 ( struct V_7 * V_8 , T_3 V_173 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 = F_65 ( V_72 , V_140 ) ;
if ( ! V_73 )
return;
F_139 ( F_6 ( V_8 ) ) ;
V_8 -> V_110 . V_173 = V_173 ;
if ( V_173 & V_176 ) {
F_101 ( V_136 ,
F_93 ( V_136 ) |
V_317 ) ;
V_73 -> V_179 = V_173 ;
} else {
F_101 ( V_136 ,
F_93 ( V_136 ) &
~ V_317 ) ;
V_73 -> V_179 = V_173 & ~ V_177 ;
}
F_176 ( V_72 ) ;
}
static void F_250 ( struct V_7 * V_8 )
{
T_2 V_480 ;
F_105 ( F_6 ( V_8 ) ) ;
V_480 = F_93 ( V_479 ) ;
if ( ( V_480 & V_481 ) != V_482 ) {
F_251 ( L_17 ,
V_483 ) ;
F_101 ( V_479 ,
( V_480 & ~ V_481 )
| V_482 ) ;
}
F_249 ( V_8 , V_8 -> V_110 . V_173 | V_176 ) ;
}
static void F_252 ( struct V_7 * V_8 )
{
F_101 ( V_136 ,
F_93 ( V_136 )
& ~ V_317 ) ;
F_249 ( V_8 , V_8 -> V_110 . V_173 & ~ V_176 ) ;
}
static void F_253 ( struct V_7 * V_8 )
{
F_88 ( F_6 ( V_8 ) ) ;
if ( V_100 ) {
if ( ! F_254 ( V_8 -> V_110 . V_484 . V_485 ) )
return;
F_90 ( F_255 ( V_8 -> V_110 . V_484 . V_485 ) ) ;
}
}
static void F_156 ( struct V_7 * V_8 )
{
T_9 V_226 = V_8 -> V_110 . V_226 ;
V_8 -> V_110 . V_222 &= ~ V_226 ;
V_8 -> V_110 . V_222 |= F_91 ( V_223 ) & V_226 ;
}
static void F_256 ( struct V_7 * V_8 )
{
if ( V_100 && F_257 ( V_8 ) )
V_8 -> V_110 . V_486 = F_91 ( V_487 ) ;
F_159 ( V_488 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
}
static void F_258 ( struct V_7 * V_8 )
{
T_9 V_489 = V_8 -> V_110 . V_489 ;
V_8 -> V_110 . V_490 &= ~ V_489 ;
V_8 -> V_110 . V_490 |= F_91 ( V_461 ) & V_489 ;
}
static void F_259 ( struct V_7 * V_8 )
{
struct V_491 * V_484 = V_8 -> V_110 . V_492 ;
if ( ! F_158 ( V_395 ,
( unsigned long * ) & V_8 -> V_110 . V_493 ) )
return;
if ( F_257 ( V_8 ) && F_260 ( V_8 ) && ! F_129 ( V_8 ) ) {
F_102 ( V_494 , V_484 -> V_495 [ 0 ] ) ;
F_102 ( V_496 , V_484 -> V_495 [ 1 ] ) ;
F_102 ( V_497 , V_484 -> V_495 [ 2 ] ) ;
F_102 ( V_498 , V_484 -> V_495 [ 3 ] ) ;
}
}
static void F_206 ( struct V_7 * V_8 )
{
struct V_491 * V_484 = V_8 -> V_110 . V_492 ;
if ( F_257 ( V_8 ) && F_260 ( V_8 ) && ! F_129 ( V_8 ) ) {
V_484 -> V_495 [ 0 ] = F_94 ( V_494 ) ;
V_484 -> V_495 [ 1 ] = F_94 ( V_496 ) ;
V_484 -> V_495 [ 2 ] = F_94 ( V_497 ) ;
V_484 -> V_495 [ 3 ] = F_94 ( V_498 ) ;
}
F_159 ( V_395 ,
( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
F_159 ( V_395 ,
( unsigned long * ) & V_8 -> V_110 . V_493 ) ;
}
static void F_261 ( unsigned long * V_499 ,
unsigned long V_222 ,
struct V_7 * V_8 )
{
if ( ! F_158 ( V_488 , ( T_9 * ) & V_8 -> V_110 . V_111 ) )
F_256 ( V_8 ) ;
if ( ! ( V_222 & V_500 ) ) {
F_101 ( V_501 ,
F_93 ( V_501 ) |
( V_326 |
V_327 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_262 ( V_8 , F_263 ( V_8 ) ) ;
} else if ( ! F_257 ( V_8 ) ) {
F_101 ( V_501 ,
F_93 ( V_501 ) &
~ ( V_326 |
V_327 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_262 ( V_8 , F_263 ( V_8 ) ) ;
}
if ( ! ( V_222 & V_502 ) )
* V_499 &= ~ V_502 ;
}
static void F_264 ( struct V_7 * V_8 , unsigned long V_222 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_499 ;
V_499 = ( V_222 & ~ V_503 ) ;
if ( V_437 )
V_499 |= V_504 ;
else {
V_499 |= V_505 ;
if ( V_72 -> V_130 . V_131 && ( V_222 & V_506 ) )
F_243 ( V_8 ) ;
if ( ! V_72 -> V_130 . V_131 && ! ( V_222 & V_506 ) )
F_247 ( V_8 ) ;
}
#ifdef F_95
if ( V_8 -> V_110 . V_173 & V_177 ) {
if ( ! F_257 ( V_8 ) && ( V_222 & V_500 ) )
F_250 ( V_8 ) ;
if ( F_257 ( V_8 ) && ! ( V_222 & V_500 ) )
F_252 ( V_8 ) ;
}
#endif
if ( V_100 )
F_261 ( & V_499 , V_222 , V_8 ) ;
if ( ! V_8 -> V_132 )
V_499 |= V_224 | V_225 ;
F_98 ( V_235 , V_222 ) ;
F_98 ( V_223 , V_499 ) ;
V_8 -> V_110 . V_222 = V_222 ;
V_72 -> F_239 = F_239 ( V_8 ) ;
}
static T_3 F_255 ( unsigned long V_485 )
{
T_3 V_83 ;
V_83 = V_507 |
V_508 << V_509 ;
if ( V_438 )
V_83 |= V_510 ;
V_83 |= ( V_485 & V_511 ) ;
return V_83 ;
}
static void F_265 ( struct V_7 * V_8 , unsigned long V_486 )
{
unsigned long V_512 ;
T_3 V_83 ;
V_512 = V_486 ;
if ( V_100 ) {
V_83 = F_255 ( V_486 ) ;
F_102 ( V_513 , V_83 ) ;
V_512 = F_257 ( V_8 ) ? F_266 ( V_8 ) :
V_8 -> V_17 -> V_110 . V_514 ;
F_259 ( V_8 ) ;
}
F_253 ( V_8 ) ;
F_98 ( V_487 , V_512 ) ;
}
static int F_262 ( struct V_7 * V_8 , unsigned long V_490 )
{
unsigned long V_515 = V_490 | ( F_6 ( V_8 ) -> V_130 . V_131 ?
V_516 : V_517 ) ;
if ( V_490 & V_401 ) {
if ( ! F_190 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_518 &&
( ( V_490 & F_198 ) != F_198 ) )
return 1 ;
V_8 -> V_110 . V_490 = V_490 ;
if ( V_100 ) {
if ( ! F_257 ( V_8 ) ) {
V_515 &= ~ V_519 ;
V_515 |= V_520 ;
V_515 &= ~ V_521 ;
} else if ( ! ( V_490 & V_519 ) ) {
V_515 &= ~ V_519 ;
}
}
F_98 ( V_463 , V_490 ) ;
F_98 ( V_461 , V_515 ) ;
return 0 ;
}
static void F_244 ( struct V_7 * V_8 ,
struct V_448 * V_468 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_121 ;
if ( V_72 -> V_130 . V_131 && V_107 != V_522 ) {
* V_468 = V_72 -> V_130 . V_455 [ V_107 ] ;
if ( V_107 == V_460
|| V_468 -> V_114 == F_107 ( V_72 , V_107 ) )
return;
V_468 -> V_117 = F_108 ( V_72 , V_107 ) ;
V_468 -> V_114 = F_107 ( V_72 , V_107 ) ;
return;
}
V_468 -> V_117 = F_108 ( V_72 , V_107 ) ;
V_468 -> V_119 = F_109 ( V_72 , V_107 ) ;
V_468 -> V_114 = F_107 ( V_72 , V_107 ) ;
V_121 = F_110 ( V_72 , V_107 ) ;
V_468 -> V_473 = ( V_121 >> 16 ) & 1 ;
V_468 -> type = V_121 & 15 ;
V_468 -> V_183 = ( V_121 >> 4 ) & 1 ;
V_468 -> V_453 = ( V_121 >> 5 ) & 3 ;
V_468 -> V_471 = ! V_468 -> V_473 ;
V_468 -> V_474 = ( V_121 >> 12 ) & 1 ;
V_468 -> V_472 = ( V_121 >> 13 ) & 1 ;
V_468 -> V_470 = ( V_121 >> 14 ) & 1 ;
V_468 -> V_469 = ( V_121 >> 15 ) & 1 ;
}
static T_3 F_267 ( struct V_7 * V_8 , int V_107 )
{
struct V_448 V_183 ;
if ( F_6 ( V_8 ) -> V_130 . V_131 ) {
F_244 ( V_8 , & V_183 , V_107 ) ;
return V_183 . V_117 ;
}
return F_108 ( F_6 ( V_8 ) , V_107 ) ;
}
static int F_268 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_269 ( V_8 ) )
return 0 ;
if ( ! F_129 ( V_8 )
&& ( F_270 ( V_8 ) & V_242 ) )
return 3 ;
if ( ! F_158 ( V_464 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ) {
F_159 ( V_464 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_465 = F_107 ( V_72 , V_450 ) & 3 ;
}
return V_72 -> V_465 ;
}
static T_2 F_246 ( struct V_448 * V_468 )
{
T_2 V_121 ;
if ( V_468 -> V_473 || ! V_468 -> V_471 )
V_121 = 1 << 16 ;
else {
V_121 = V_468 -> type & 15 ;
V_121 |= ( V_468 -> V_183 & 1 ) << 4 ;
V_121 |= ( V_468 -> V_453 & 3 ) << 5 ;
V_121 |= ( V_468 -> V_471 & 1 ) << 7 ;
V_121 |= ( V_468 -> V_474 & 1 ) << 12 ;
V_121 |= ( V_468 -> V_472 & 1 ) << 13 ;
V_121 |= ( V_468 -> V_470 & 1 ) << 14 ;
V_121 |= ( V_468 -> V_469 & 1 ) << 15 ;
}
return V_121 ;
}
static void F_242 ( struct V_7 * V_8 ,
struct V_448 * V_468 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
const struct V_466 * V_467 = & V_116 [ V_107 ] ;
F_105 ( V_72 ) ;
if ( V_107 == V_450 )
F_271 ( V_464 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
if ( V_72 -> V_130 . V_131 && V_107 != V_522 ) {
V_72 -> V_130 . V_455 [ V_107 ] = * V_468 ;
if ( V_107 == V_460 )
F_100 ( V_467 -> V_114 , V_468 -> V_114 ) ;
else if ( V_468 -> V_183 )
F_245 ( V_107 , & V_72 -> V_130 . V_455 [ V_107 ] ) ;
goto V_523;
}
F_98 ( V_467 -> V_117 , V_468 -> V_117 ) ;
F_101 ( V_467 -> V_119 , V_468 -> V_119 ) ;
F_100 ( V_467 -> V_114 , V_468 -> V_114 ) ;
if ( V_437 && ( V_107 != V_522 ) )
V_468 -> type |= 0x1 ;
F_101 ( V_467 -> V_123 , F_246 ( V_468 ) ) ;
V_523:
V_72 -> F_239 |= F_239 ( V_8 ) ;
}
static void F_272 ( struct V_7 * V_8 , int * V_470 , int * V_472 )
{
T_2 V_121 = F_110 ( F_6 ( V_8 ) , V_450 ) ;
* V_470 = ( V_121 >> 14 ) & 1 ;
* V_472 = ( V_121 >> 13 ) & 1 ;
}
static void F_273 ( struct V_7 * V_8 , struct V_163 * V_524 )
{
V_524 -> V_423 = F_93 ( V_525 ) ;
V_524 -> V_168 = F_91 ( V_526 ) ;
}
static void F_274 ( struct V_7 * V_8 , struct V_163 * V_524 )
{
F_101 ( V_525 , V_524 -> V_423 ) ;
F_98 ( V_526 , V_524 -> V_168 ) ;
}
static void F_275 ( struct V_7 * V_8 , struct V_163 * V_524 )
{
V_524 -> V_423 = F_93 ( V_527 ) ;
V_524 -> V_168 = F_91 ( V_528 ) ;
}
static void F_276 ( struct V_7 * V_8 , struct V_163 * V_524 )
{
F_101 ( V_527 , V_524 -> V_423 ) ;
F_98 ( V_528 , V_524 -> V_168 ) ;
}
static bool F_277 ( struct V_7 * V_8 , int V_107 )
{
struct V_448 V_468 ;
T_2 V_121 ;
F_244 ( V_8 , & V_468 , V_107 ) ;
V_468 . V_453 = 0x3 ;
if ( V_107 == V_450 )
V_468 . type = 0x3 ;
V_121 = F_246 ( & V_468 ) ;
if ( V_468 . V_117 != ( V_468 . V_114 << 4 ) )
return false ;
if ( V_468 . V_119 != 0xffff )
return false ;
if ( V_121 != 0xf3 )
return false ;
return true ;
}
static bool F_278 ( struct V_7 * V_8 )
{
struct V_448 V_529 ;
unsigned int V_530 ;
F_244 ( V_8 , & V_529 , V_450 ) ;
V_530 = V_529 . V_114 & V_452 ;
if ( V_529 . V_473 )
return false ;
if ( ~ V_529 . type & ( V_531 | V_532 ) )
return false ;
if ( ! V_529 . V_183 )
return false ;
if ( V_529 . type & V_533 ) {
if ( V_529 . V_453 > V_530 )
return false ;
} else {
if ( V_529 . V_453 != V_530 )
return false ;
}
if ( ! V_529 . V_471 )
return false ;
return true ;
}
static bool F_279 ( struct V_7 * V_8 )
{
struct V_448 V_534 ;
unsigned int V_535 ;
F_244 ( V_8 , & V_534 , V_451 ) ;
V_535 = V_534 . V_114 & V_452 ;
if ( V_534 . V_473 )
return true ;
if ( V_534 . type != 3 && V_534 . type != 7 )
return false ;
if ( ! V_534 . V_183 )
return false ;
if ( V_534 . V_453 != V_535 )
return false ;
if ( ! V_534 . V_471 )
return false ;
return true ;
}
static bool F_280 ( struct V_7 * V_8 , int V_107 )
{
struct V_448 V_468 ;
unsigned int V_536 ;
F_244 ( V_8 , & V_468 , V_107 ) ;
V_536 = V_468 . V_114 & V_452 ;
if ( V_468 . V_473 )
return true ;
if ( ! V_468 . V_183 )
return false ;
if ( ! V_468 . V_471 )
return false ;
if ( ~ V_468 . type & ( V_531 | V_533 ) ) {
if ( V_468 . V_453 < V_536 )
return false ;
}
return true ;
}
static bool F_281 ( struct V_7 * V_8 )
{
struct V_448 V_186 ;
F_244 ( V_8 , & V_186 , V_460 ) ;
if ( V_186 . V_473 )
return false ;
if ( V_186 . V_114 & V_537 )
return false ;
if ( V_186 . type != 3 && V_186 . type != 11 )
return false ;
if ( ! V_186 . V_471 )
return false ;
return true ;
}
static bool F_282 ( struct V_7 * V_8 )
{
struct V_448 V_538 ;
F_244 ( V_8 , & V_538 , V_522 ) ;
if ( V_538 . V_473 )
return true ;
if ( V_538 . V_114 & V_537 )
return false ;
if ( V_538 . type != 2 )
return false ;
if ( ! V_538 . V_471 )
return false ;
return true ;
}
static bool F_283 ( struct V_7 * V_8 )
{
struct V_448 V_529 , V_534 ;
F_244 ( V_8 , & V_529 , V_450 ) ;
F_244 ( V_8 , & V_534 , V_451 ) ;
return ( ( V_529 . V_114 & V_452 ) ==
( V_534 . V_114 & V_452 ) ) ;
}
static bool F_240 ( struct V_7 * V_8 )
{
if ( V_437 )
return true ;
if ( ! F_269 ( V_8 ) || ( F_157 ( V_8 ) & V_242 ) ) {
if ( ! F_277 ( V_8 , V_450 ) )
return false ;
if ( ! F_277 ( V_8 , V_451 ) )
return false ;
if ( ! F_277 ( V_8 , V_457 ) )
return false ;
if ( ! F_277 ( V_8 , V_456 ) )
return false ;
if ( ! F_277 ( V_8 , V_458 ) )
return false ;
if ( ! F_277 ( V_8 , V_459 ) )
return false ;
} else {
if ( ! F_283 ( V_8 ) )
return false ;
if ( ! F_278 ( V_8 ) )
return false ;
if ( ! F_279 ( V_8 ) )
return false ;
if ( ! F_280 ( V_8 , V_457 ) )
return false ;
if ( ! F_280 ( V_8 , V_456 ) )
return false ;
if ( ! F_280 ( V_8 , V_458 ) )
return false ;
if ( ! F_280 ( V_8 , V_459 ) )
return false ;
if ( ! F_281 ( V_8 ) )
return false ;
if ( ! F_282 ( V_8 ) )
return false ;
}
return true ;
}
static int F_284 ( struct V_17 * V_17 )
{
T_13 V_539 ;
T_4 V_179 = 0 ;
int V_540 , V_541 , V_108 = 0 ;
V_541 = F_285 ( & V_17 -> V_542 ) ;
V_539 = V_17 -> V_110 . V_475 >> V_18 ;
V_540 = F_286 ( V_17 , V_539 , 0 , V_422 ) ;
if ( V_540 < 0 )
goto V_523;
V_179 = V_543 + V_544 ;
V_540 = F_287 ( V_17 , V_539 ++ , & V_179 ,
V_545 , sizeof( T_4 ) ) ;
if ( V_540 < 0 )
goto V_523;
V_540 = F_286 ( V_17 , V_539 ++ , 0 , V_422 ) ;
if ( V_540 < 0 )
goto V_523;
V_540 = F_286 ( V_17 , V_539 , 0 , V_422 ) ;
if ( V_540 < 0 )
goto V_523;
V_179 = ~ 0 ;
V_540 = F_287 ( V_17 , V_539 , & V_179 ,
V_478 - 2 * V_422 - 1 ,
sizeof( T_6 ) ) ;
if ( V_540 < 0 )
goto V_523;
V_108 = 1 ;
V_523:
F_288 ( & V_17 -> V_542 , V_541 ) ;
return V_108 ;
}
static int F_289 ( struct V_17 * V_17 )
{
int V_74 , V_541 , V_540 , V_108 ;
T_14 V_546 ;
T_2 V_267 ;
if ( ! V_100 )
return 1 ;
if ( F_99 ( ! V_17 -> V_110 . V_547 ) ) {
F_68 ( V_88 L_18
L_19 ) ;
return 0 ;
}
if ( F_290 ( V_17 -> V_110 . V_548 ) )
return 1 ;
V_108 = 0 ;
V_546 = V_17 -> V_110 . V_514 >> V_18 ;
V_541 = F_285 ( & V_17 -> V_542 ) ;
V_540 = F_286 ( V_17 , V_546 , 0 , V_422 ) ;
if ( V_540 < 0 )
goto V_523;
for ( V_74 = 0 ; V_74 < V_549 ; V_74 ++ ) {
V_267 = ( V_74 << 22 ) + ( V_550 | V_551 | V_552 |
V_553 | V_554 | V_555 ) ;
V_540 = F_287 ( V_17 , V_546 ,
& V_267 , V_74 * sizeof( V_267 ) , sizeof( V_267 ) ) ;
if ( V_540 < 0 )
goto V_523;
}
V_17 -> V_110 . V_548 = true ;
V_108 = 1 ;
V_523:
F_288 ( & V_17 -> V_542 , V_541 ) ;
return V_108 ;
}
static void F_291 ( int V_107 )
{
const struct V_466 * V_467 = & V_116 [ V_107 ] ;
unsigned int V_121 ;
F_100 ( V_467 -> V_114 , 0 ) ;
F_98 ( V_467 -> V_117 , 0 ) ;
F_101 ( V_467 -> V_119 , 0xffff ) ;
V_121 = 0x93 ;
if ( V_107 == V_450 )
V_121 |= 0x08 ;
F_101 ( V_467 -> V_123 , V_121 ) ;
}
static int F_292 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_556 V_557 ;
int V_540 = 0 ;
F_293 ( & V_17 -> V_558 ) ;
if ( V_17 -> V_110 . V_559 )
goto V_523;
V_557 . V_560 = V_561 ;
V_557 . V_454 = 0 ;
V_557 . V_562 = 0xfee00000ULL ;
V_557 . V_563 = V_422 ;
V_540 = F_294 ( V_17 , & V_557 ) ;
if ( V_540 )
goto V_523;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_540 = - V_564 ;
goto V_523;
}
V_17 -> V_110 . V_559 = V_15 ;
V_523:
F_295 ( & V_17 -> V_558 ) ;
return V_540 ;
}
static int F_296 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_556 V_557 ;
int V_540 = 0 ;
F_293 ( & V_17 -> V_558 ) ;
if ( V_17 -> V_110 . V_547 )
goto V_523;
V_557 . V_560 = V_565 ;
V_557 . V_454 = 0 ;
V_557 . V_562 =
V_17 -> V_110 . V_514 ;
V_557 . V_563 = V_422 ;
V_540 = F_294 ( V_17 , & V_557 ) ;
if ( V_540 )
goto V_523;
V_15 = F_11 ( V_17 , V_17 -> V_110 . V_514 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_540 = - V_564 ;
goto V_523;
}
V_17 -> V_110 . V_547 = V_15 ;
V_523:
F_295 ( & V_17 -> V_558 ) ;
return V_540 ;
}
static void F_297 ( struct V_6 * V_72 )
{
int V_52 ;
V_72 -> V_52 = 0 ;
if ( ! V_435 )
return;
F_298 ( & V_566 ) ;
V_52 = F_299 ( V_567 , V_568 ) ;
if ( V_52 < V_568 ) {
V_72 -> V_52 = V_52 ;
F_159 ( V_52 , V_567 ) ;
}
F_300 ( & V_566 ) ;
}
static void F_301 ( struct V_6 * V_72 )
{
if ( ! V_435 )
return;
F_298 ( & V_566 ) ;
if ( V_72 -> V_52 != 0 )
F_271 ( V_72 -> V_52 , V_567 ) ;
F_300 ( & V_566 ) ;
}
static void F_302 ( unsigned long * V_268 ,
T_2 V_73 , int type )
{
int V_569 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_570 )
F_271 ( V_73 , V_268 + 0x000 / V_569 ) ;
if ( type & V_571 )
F_271 ( V_73 , V_268 + 0x800 / V_569 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_570 )
F_271 ( V_73 , V_268 + 0x400 / V_569 ) ;
if ( type & V_571 )
F_271 ( V_73 , V_268 + 0xc00 / V_569 ) ;
}
}
static void F_303 ( unsigned long * V_268 ,
T_2 V_73 , int type )
{
int V_569 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_570 )
F_159 ( V_73 , V_268 + 0x000 / V_569 ) ;
if ( type & V_571 )
F_159 ( V_73 , V_268 + 0x800 / V_569 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_570 )
F_159 ( V_73 , V_268 + 0x400 / V_569 ) ;
if ( type & V_571 )
F_159 ( V_73 , V_268 + 0xc00 / V_569 ) ;
}
}
static void F_304 ( T_2 V_73 , bool V_572 )
{
if ( ! V_572 )
F_302 ( V_273 ,
V_73 , V_570 | V_571 ) ;
F_302 ( V_272 ,
V_73 , V_570 | V_571 ) ;
}
static void F_305 ( T_2 V_73 )
{
F_303 ( V_271 ,
V_73 , V_570 ) ;
F_303 ( V_270 ,
V_73 , V_570 ) ;
}
static void F_306 ( T_2 V_73 )
{
F_302 ( V_271 ,
V_73 , V_570 ) ;
F_302 ( V_270 ,
V_73 , V_570 ) ;
}
static void F_307 ( T_2 V_73 )
{
F_302 ( V_271 ,
V_73 , V_571 ) ;
F_302 ( V_270 ,
V_73 , V_571 ) ;
}
static int F_308 ( struct V_17 * V_17 )
{
return V_442 && F_25 ( V_17 ) ;
}
static void F_309 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_540 ;
if ( F_5 ( V_4 , & V_72 -> V_1 ) )
return;
V_540 = F_1 ( & V_72 -> V_1 ) ;
F_144 ( V_573 , V_8 ) ;
#ifdef F_310
if ( ! V_540 && ( V_8 -> V_574 == V_575 ) )
V_269 -> V_576 ( F_311 ( V_8 -> V_90 ) ,
V_577 ) ;
else
#endif
F_312 ( V_8 ) ;
}
static void F_313 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_72 -> V_1 ) )
return;
F_314 ( V_8 , V_72 -> V_1 . V_5 ) ;
}
static void V_446 ( struct V_7 * V_8 )
{
return;
}
static void F_315 ( struct V_6 * V_72 )
{
T_2 V_578 , V_579 ;
unsigned long V_580 ;
struct V_163 V_524 ;
F_98 ( V_581 , F_316 () & ~ V_224 ) ;
F_98 ( V_582 , F_212 () ) ;
F_98 ( V_583 , F_317 () ) ;
F_100 ( V_584 , V_585 ) ;
#ifdef F_95
F_100 ( V_586 , 0 ) ;
F_100 ( V_587 , 0 ) ;
#else
F_100 ( V_586 , V_588 ) ;
F_100 ( V_587 , V_588 ) ;
#endif
F_100 ( V_589 , V_588 ) ;
F_100 ( V_590 , V_169 * 8 ) ;
F_318 ( & V_524 ) ;
F_98 ( V_591 , V_524 . V_168 ) ;
V_72 -> V_592 = V_524 . V_168 ;
F_98 ( V_593 , V_594 ) ;
F_192 ( V_378 , V_578 , V_579 ) ;
F_101 ( V_595 , V_578 ) ;
F_55 ( V_380 , V_580 ) ;
F_98 ( V_596 , V_580 ) ;
if ( V_29 . V_426 & V_311 ) {
F_192 ( V_383 , V_578 , V_579 ) ;
F_102 ( V_597 , V_578 | ( ( T_3 ) V_579 << 32 ) ) ;
}
}
static void F_319 ( struct V_6 * V_72 )
{
V_72 -> V_8 . V_110 . V_489 = V_598 ;
if ( V_100 )
V_72 -> V_8 . V_110 . V_489 |= V_599 ;
if ( F_112 ( & V_72 -> V_8 ) )
V_72 -> V_8 . V_110 . V_489 &=
~ F_9 ( & V_72 -> V_8 ) -> V_233 ;
F_98 ( V_600 , ~ V_72 -> V_8 . V_110 . V_489 ) ;
}
static T_2 F_320 ( struct V_6 * V_72 )
{
T_2 V_39 = V_29 . V_39 ;
if ( ! F_308 ( V_72 -> V_8 . V_17 ) )
V_39 &= ~ V_40 ;
return V_39 ;
}
static T_2 F_321 ( struct V_6 * V_72 )
{
T_2 V_601 = V_29 . V_30 ;
if ( ! F_24 ( V_72 -> V_8 . V_17 ) ) {
V_601 &= ~ V_32 ;
#ifdef F_95
V_601 |= V_329 |
V_328 ;
#endif
}
if ( ! V_100 )
V_601 |= V_327 |
V_326 |
V_324 ;
return V_601 ;
}
static T_2 F_322 ( struct V_6 * V_72 )
{
T_2 V_601 = V_29 . V_34 ;
if ( ! F_48 ( V_72 -> V_8 . V_17 ) )
V_601 &= ~ V_35 ;
if ( V_72 -> V_52 == 0 )
V_601 &= ~ V_59 ;
if ( ! V_100 ) {
V_601 &= ~ V_55 ;
V_437 = 0 ;
V_601 &= ~ V_61 ;
}
if ( ! V_437 )
V_601 &= ~ V_56 ;
if ( ! V_441 )
V_601 &= ~ V_57 ;
if ( ! F_308 ( V_72 -> V_8 . V_17 ) )
V_601 &= ~ ( V_37 |
V_38 ) ;
V_601 &= ~ V_36 ;
V_601 &= ~ V_67 ;
return V_601 ;
}
static void F_323 ( void )
{
F_324 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_325 ( struct V_6 * V_72 )
{
#ifdef F_95
unsigned long V_602 ;
#endif
int V_74 ;
F_102 ( V_603 , F_67 ( V_604 ) ) ;
F_102 ( V_605 , F_67 ( V_606 ) ) ;
if ( V_436 ) {
F_102 ( V_607 , F_67 ( V_608 ) ) ;
F_102 ( V_609 , F_67 ( V_610 ) ) ;
}
if ( F_22 () )
F_102 ( V_274 , F_67 ( V_273 ) ) ;
F_102 ( V_611 , - 1ull ) ;
F_101 ( V_612 , F_320 ( V_72 ) ) ;
F_101 ( V_501 , F_321 ( V_72 ) ) ;
if ( F_26 () ) {
F_101 ( V_613 ,
F_322 ( V_72 ) ) ;
}
if ( F_308 ( V_72 -> V_8 . V_17 ) ) {
F_102 ( V_614 , 0 ) ;
F_102 ( V_615 , 0 ) ;
F_102 ( V_616 , 0 ) ;
F_102 ( V_617 , 0 ) ;
F_100 ( V_618 , 0 ) ;
F_102 ( V_619 , V_577 ) ;
F_102 ( V_620 , F_67 ( ( & V_72 -> V_1 ) ) ) ;
}
if ( V_441 ) {
F_101 ( V_621 , V_441 ) ;
F_101 ( V_622 , V_623 ) ;
}
F_101 ( V_624 , 0 ) ;
F_101 ( V_625 , 0 ) ;
F_101 ( V_626 , 0 ) ;
F_100 ( V_193 , 0 ) ;
F_100 ( V_197 , 0 ) ;
F_315 ( V_72 ) ;
#ifdef F_95
F_55 ( V_203 , V_602 ) ;
F_98 ( V_202 , V_602 ) ;
F_55 ( V_205 , V_602 ) ;
F_98 ( V_204 , V_602 ) ;
#else
F_98 ( V_202 , 0 ) ;
F_98 ( V_204 , 0 ) ;
#endif
F_101 ( V_627 , 0 ) ;
F_101 ( V_152 , 0 ) ;
F_102 ( V_628 , F_67 ( V_72 -> V_138 . V_150 ) ) ;
F_101 ( V_151 , 0 ) ;
F_102 ( V_629 , F_67 ( V_72 -> V_138 . V_149 ) ) ;
if ( V_29 . V_384 & V_318 ) {
T_2 V_630 , V_631 ;
T_3 V_632 ;
F_192 ( V_383 , V_630 , V_631 ) ;
V_632 = V_630 | ( ( T_3 ) V_631 << 32 ) ;
F_102 ( V_385 , V_632 ) ;
V_72 -> V_8 . V_110 . V_386 = V_632 ;
}
for ( V_74 = 0 ; V_74 < V_633 ; ++ V_74 ) {
T_2 V_78 = V_76 [ V_74 ] ;
T_2 V_634 , V_635 ;
int V_636 = V_72 -> V_75 ;
if ( F_326 ( V_78 , & V_634 , & V_635 ) < 0 )
continue;
if ( F_327 ( V_78 , V_634 , V_635 ) < 0 )
continue;
V_72 -> V_77 [ V_636 ] . V_78 = V_74 ;
V_72 -> V_77 [ V_636 ] . V_179 = 0 ;
V_72 -> V_77 [ V_636 ] . V_104 = - 1ull ;
++ V_72 -> V_75 ;
}
F_101 ( V_137 , V_29 . V_426 ) ;
F_101 ( V_136 , V_29 . V_384 ) ;
F_98 ( V_228 , ~ 0UL ) ;
F_319 ( V_72 ) ;
return 0 ;
}
static void F_328 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_73 ;
V_72 -> V_130 . V_131 = 0 ;
V_72 -> V_637 = 0 ;
V_72 -> V_8 . V_110 . V_391 [ V_638 ] = F_329 () ;
F_330 ( & V_72 -> V_8 , 0 ) ;
V_73 = 0xfee00000 | V_639 ;
if ( F_331 ( & V_72 -> V_8 ) )
V_73 |= V_640 ;
F_332 ( & V_72 -> V_8 , V_73 ) ;
F_105 ( V_72 ) ;
F_291 ( V_450 ) ;
F_100 ( V_641 , 0xf000 ) ;
F_101 ( V_642 , 0xffff0000 ) ;
F_291 ( V_457 ) ;
F_291 ( V_456 ) ;
F_291 ( V_458 ) ;
F_291 ( V_459 ) ;
F_291 ( V_451 ) ;
F_100 ( V_643 , 0 ) ;
F_98 ( V_476 , 0 ) ;
F_101 ( V_477 , 0xffff ) ;
F_101 ( V_479 , 0x008b ) ;
F_100 ( V_644 , 0 ) ;
F_98 ( V_645 , 0 ) ;
F_101 ( V_646 , 0xffff ) ;
F_101 ( V_647 , 0x00082 ) ;
F_101 ( V_379 , 0 ) ;
F_98 ( V_382 , 0 ) ;
F_98 ( V_381 , 0 ) ;
F_98 ( V_239 , 0x02 ) ;
F_165 ( V_8 , 0xfff0 ) ;
F_98 ( V_528 , 0 ) ;
F_101 ( V_527 , 0xffff ) ;
F_98 ( V_526 , 0 ) ;
F_101 ( V_525 , 0xffff ) ;
F_101 ( V_648 , V_649 ) ;
F_101 ( V_244 , 0 ) ;
F_101 ( V_650 , 0 ) ;
F_102 ( V_651 , 0 ) ;
F_176 ( V_72 ) ;
F_101 ( V_264 , 0 ) ;
if ( F_23 () ) {
F_102 ( V_652 , 0 ) ;
if ( F_24 ( V_72 -> V_8 . V_17 ) )
F_102 ( V_652 ,
F_67 ( V_72 -> V_8 . V_110 . V_269 -> V_391 ) ) ;
F_101 ( V_653 , 0 ) ;
}
if ( F_48 ( V_72 -> V_8 . V_17 ) )
F_102 ( V_654 ,
F_333 ( V_72 -> V_8 . V_17 -> V_110 . V_559 ) ) ;
if ( F_308 ( V_8 -> V_17 ) )
memset ( & V_72 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_72 -> V_52 != 0 )
F_100 ( V_655 , V_72 -> V_52 ) ;
V_72 -> V_8 . V_110 . V_222 = V_656 | V_657 | V_658 ;
F_264 ( & V_72 -> V_8 , F_334 ( V_8 ) ) ;
F_262 ( & V_72 -> V_8 , 0 ) ;
F_249 ( & V_72 -> V_8 , 0 ) ;
F_151 ( & V_72 -> V_8 ) ;
F_111 ( & V_72 -> V_8 ) ;
F_88 ( V_72 ) ;
}
static bool F_335 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_303 ;
}
static bool F_336 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_304 ;
}
static int F_337 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( F_112 ( V_8 ) && F_335 ( V_8 ) )
return - V_402 ;
V_69 = F_93 ( V_501 ) ;
V_69 |= V_322 ;
F_101 ( V_501 , V_69 ) ;
return 0 ;
}
static int F_338 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () )
return F_337 ( V_8 ) ;
if ( F_93 ( V_244 ) & V_245 )
return F_337 ( V_8 ) ;
V_69 = F_93 ( V_501 ) ;
V_69 |= V_659 ;
F_101 ( V_501 , V_69 ) ;
return 0 ;
}
static void F_339 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_15 V_660 ;
int V_661 = V_8 -> V_110 . V_662 . V_148 ;
F_340 ( V_661 ) ;
++ V_8 -> V_210 . V_663 ;
if ( V_72 -> V_130 . V_131 ) {
int V_258 = 0 ;
if ( V_8 -> V_110 . V_662 . V_664 )
V_258 = V_8 -> V_110 . V_259 ;
if ( F_170 ( V_8 , V_661 , V_258 ) != V_260 )
F_144 ( V_261 , V_8 ) ;
return;
}
V_660 = V_661 | V_22 ;
if ( V_8 -> V_110 . V_662 . V_664 ) {
V_660 |= V_665 ;
F_101 ( V_262 ,
V_72 -> V_8 . V_110 . V_259 ) ;
} else
V_660 |= V_27 ;
F_101 ( V_264 , V_660 ) ;
}
static void F_341 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( F_112 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_72 -> V_637 = 1 ;
V_72 -> V_666 = 0 ;
}
++ V_8 -> V_210 . V_667 ;
V_72 -> V_668 = false ;
if ( V_72 -> V_130 . V_131 ) {
if ( F_170 ( V_8 , V_669 , 0 ) != V_260 )
F_144 ( V_261 , V_8 ) ;
return;
}
F_101 ( V_264 ,
V_670 | V_22 | V_669 ) ;
}
static bool F_342 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_637 ;
if ( F_6 ( V_8 ) -> V_668 )
return false ;
return F_93 ( V_244 ) & V_671 ;
}
static void F_343 ( struct V_7 * V_8 , bool V_672 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_72 -> V_637 != V_672 ) {
V_72 -> V_637 = V_672 ;
V_72 -> V_666 = 0 ;
}
} else {
V_72 -> V_668 = ! V_672 ;
if ( V_672 )
F_104 ( V_244 ,
V_671 ) ;
else
F_103 ( V_244 ,
V_671 ) ;
}
}
static int F_344 ( struct V_7 * V_8 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_255 )
return 0 ;
if ( F_336 ( V_8 ) ) {
F_167 ( V_8 ) ;
V_12 -> V_673 = V_674 ;
V_12 -> V_675 = V_669 |
V_670 | V_22 ;
V_8 -> V_110 . V_676 = 0 ;
F_343 ( V_8 , true ) ;
return 0 ;
}
}
if ( ! F_52 () && F_6 ( V_8 ) -> V_637 )
return 0 ;
return ! ( F_93 ( V_244 ) &
( V_247 | V_245
| V_671 ) ) ;
}
static int F_345 ( struct V_7 * V_8 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_255 )
return 0 ;
if ( F_335 ( V_8 ) ) {
F_167 ( V_8 ) ;
V_12 -> V_673 =
V_677 ;
V_12 -> V_675 = 0 ;
}
}
return ( F_91 ( V_239 ) & V_678 ) &&
! ( F_93 ( V_244 ) &
( V_245 | V_247 ) ) ;
}
static int F_346 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_108 ;
struct V_556 V_679 = {
. V_560 = V_680 ,
. V_562 = V_16 ,
. V_563 = V_422 * 3 ,
. V_454 = 0 ,
} ;
V_108 = F_347 ( V_17 , & V_679 ) ;
if ( V_108 )
return V_108 ;
V_17 -> V_110 . V_475 = V_16 ;
if ( ! F_284 ( V_17 ) )
return - V_433 ;
return 0 ;
}
static bool F_348 ( struct V_7 * V_8 , int V_681 )
{
switch ( V_681 ) {
case V_129 :
F_6 ( V_8 ) -> V_8 . V_110 . V_259 =
F_93 ( V_251 ) ;
if ( V_8 -> V_126 & V_128 )
return false ;
case V_125 :
if ( V_8 -> V_126 &
( V_682 | V_683 ) )
return false ;
case V_684 :
case V_685 :
case V_686 :
case V_26 :
case V_687 :
case V_688 :
case V_352 :
case V_689 :
return true ;
break;
}
return false ;
}
static int F_349 ( struct V_7 * V_8 ,
int V_681 , T_2 V_690 )
{
if ( ( ( V_681 == V_352 ) || ( V_681 == V_688 ) ) && V_690 == 0 ) {
if ( F_350 ( V_8 , 0 ) == V_260 ) {
if ( V_8 -> V_110 . V_691 ) {
V_8 -> V_110 . V_691 = 0 ;
return F_351 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_352 ( V_8 , V_681 ) ;
return 1 ;
}
static void F_353 ( void )
{
#if F_354 ( V_692 ) && F_354 ( F_95 )
struct V_693 V_391 = {
. V_529 = 3 ,
. V_454 = V_678 ,
} ;
F_355 ( & V_391 , 0 ) ;
#endif
}
static int F_356 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_357 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_694 * V_694 = V_8 -> V_695 ;
T_2 V_19 , V_696 , V_253 ;
unsigned long V_697 , V_250 , V_698 ;
T_2 V_699 ;
enum V_700 V_701 ;
V_699 = V_72 -> V_702 ;
V_19 = V_72 -> V_703 ;
if ( F_21 ( V_19 ) )
return F_356 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_670 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_151 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_701 = F_350 ( V_8 , V_704 ) ;
if ( V_701 != V_260 )
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
V_253 = 0 ;
if ( V_19 & V_257 )
V_253 = F_93 ( V_705 ) ;
if ( ( V_699 & V_706 ) &&
! ( F_17 ( V_19 ) && ! ( V_253 & V_707 ) ) ) {
V_8 -> V_695 -> V_708 = V_709 ;
V_8 -> V_695 -> V_710 . V_711 = V_712 ;
V_8 -> V_695 -> V_710 . V_713 = 2 ;
V_8 -> V_695 -> V_710 . V_179 [ 0 ] = V_699 ;
V_8 -> V_695 -> V_710 . V_179 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_358 ( V_100 ) ;
V_697 = F_91 ( V_714 ) ;
F_359 ( V_697 , V_253 ) ;
if ( F_360 ( V_8 ) )
F_361 ( V_8 , V_697 ) ;
return F_362 ( V_8 , V_697 , V_253 , NULL , 0 ) ;
}
V_696 = V_19 & V_21 ;
if ( V_72 -> V_130 . V_131 && F_348 ( V_8 , V_696 ) )
return F_349 ( V_8 , V_696 , V_253 ) ;
switch ( V_696 ) {
case V_125 :
V_698 = F_91 ( V_714 ) ;
if ( ! ( V_8 -> V_126 &
( V_682 | V_683 ) ) ) {
V_8 -> V_110 . V_698 = V_698 | V_715 ;
F_352 ( V_8 , V_125 ) ;
return 1 ;
}
V_694 -> V_716 . V_110 . V_698 = V_698 | V_715 ;
V_694 -> V_716 . V_110 . V_717 = F_91 ( V_718 ) ;
case V_129 :
V_72 -> V_8 . V_110 . V_259 =
F_93 ( V_251 ) ;
V_694 -> V_708 = V_719 ;
V_250 = F_164 ( V_8 ) ;
V_694 -> V_716 . V_110 . V_720 = F_91 ( V_642 ) + V_250 ;
V_694 -> V_716 . V_110 . V_721 = V_696 ;
break;
default:
V_694 -> V_708 = V_722 ;
V_694 -> V_723 . V_721 = V_696 ;
V_694 -> V_723 . V_253 = V_253 ;
break;
}
return 0 ;
}
static int F_363 ( struct V_7 * V_8 )
{
++ V_8 -> V_210 . V_724 ;
return 1 ;
}
static int F_364 ( struct V_7 * V_8 )
{
V_8 -> V_695 -> V_708 = V_725 ;
return 0 ;
}
static int F_365 ( struct V_7 * V_8 )
{
unsigned long V_726 ;
int V_423 , V_727 , string ;
unsigned V_728 ;
V_726 = F_91 ( V_714 ) ;
string = ( V_726 & 16 ) != 0 ;
V_727 = ( V_726 & 8 ) != 0 ;
++ V_8 -> V_210 . V_729 ;
if ( string || V_727 )
return F_350 ( V_8 , 0 ) == V_260 ;
V_728 = V_726 >> 16 ;
V_423 = ( V_726 & 7 ) + 1 ;
F_163 ( V_8 ) ;
return F_366 ( V_8 , V_423 , V_728 ) ;
}
static void
F_367 ( struct V_7 * V_8 , unsigned char * V_730 )
{
V_730 [ 0 ] = 0x0f ;
V_730 [ 1 ] = 0x01 ;
V_730 [ 2 ] = 0xc1 ;
}
static int F_368 ( struct V_7 * V_8 , unsigned long V_731 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_732 = V_731 ;
V_731 = ( V_731 & ~ V_12 -> V_227 ) |
( V_12 -> V_230 & V_12 -> V_227 ) ;
if ( ( V_731 & F_197 ) != F_197 )
return 1 ;
if ( F_369 ( V_8 , V_731 ) )
return 1 ;
F_98 ( V_235 , V_732 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_518 &&
( ( V_731 & F_197 ) != F_197 ) )
return 1 ;
return F_369 ( V_8 , V_731 ) ;
}
}
static int F_370 ( struct V_7 * V_8 , unsigned long V_731 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_732 = V_731 ;
V_731 = ( V_731 & ~ V_12 -> V_233 ) |
( V_12 -> V_232 & V_12 -> V_233 ) ;
if ( F_371 ( V_8 , V_731 ) )
return 1 ;
F_98 ( V_463 , V_732 ) ;
return 0 ;
} else
return F_371 ( V_8 , V_731 ) ;
}
static void F_372 ( struct V_7 * V_8 )
{
if ( F_112 ( V_8 ) ) {
F_98 ( V_235 ,
F_91 ( V_235 ) & ~ V_224 ) ;
V_8 -> V_110 . V_222 &= ~ V_224 ;
} else
F_264 ( V_8 , F_152 ( V_8 , ~ V_224 ) ) ;
}
static int F_373 ( struct V_7 * V_8 )
{
unsigned long V_726 , V_731 ;
int V_733 ;
int V_389 ;
int V_734 ;
V_726 = F_91 ( V_714 ) ;
V_733 = V_726 & 15 ;
V_389 = ( V_726 >> 8 ) & 15 ;
switch ( ( V_726 >> 4 ) & 3 ) {
case 0 :
V_731 = F_374 ( V_8 , V_389 ) ;
F_375 ( V_733 , V_731 ) ;
switch ( V_733 ) {
case 0 :
V_734 = F_368 ( V_8 , V_731 ) ;
F_376 ( V_8 , V_734 ) ;
return 1 ;
case 3 :
V_734 = F_377 ( V_8 , V_731 ) ;
F_376 ( V_8 , V_734 ) ;
return 1 ;
case 4 :
V_734 = F_370 ( V_8 , V_731 ) ;
F_376 ( V_8 , V_734 ) ;
return 1 ;
case 8 : {
T_6 V_735 = F_378 ( V_8 ) ;
T_6 V_736 = F_374 ( V_8 , V_389 ) ;
V_734 = F_330 ( V_8 , V_736 ) ;
F_376 ( V_8 , V_734 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_735 <= V_736 )
return 1 ;
V_8 -> V_695 -> V_708 = V_737 ;
return 0 ;
}
}
break;
case 2 :
F_372 ( V_8 ) ;
F_375 ( 0 , F_334 ( V_8 ) ) ;
F_163 ( V_8 ) ;
F_151 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_733 ) {
case 3 :
V_731 = F_266 ( V_8 ) ;
F_379 ( V_8 , V_389 , V_731 ) ;
F_380 ( V_733 , V_731 ) ;
F_163 ( V_8 ) ;
return 1 ;
case 8 :
V_731 = F_378 ( V_8 ) ;
F_379 ( V_8 , V_389 , V_731 ) ;
F_380 ( V_733 , V_731 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_731 = ( V_726 >> V_738 ) & 0x0f ;
F_375 ( 0 , ( F_334 ( V_8 ) & ~ 0xful ) | V_731 ) ;
F_381 ( V_8 , V_731 ) ;
F_163 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_695 -> V_708 = 0 ;
F_382 ( V_8 , L_20 ,
( int ) ( V_726 >> 4 ) & 3 , V_733 ) ;
return 0 ;
}
static int F_383 ( struct V_7 * V_8 )
{
unsigned long V_726 ;
int V_739 , V_389 ;
if ( ! F_384 ( V_8 , 0 ) )
return 1 ;
V_739 = F_91 ( V_718 ) ;
if ( V_739 & V_740 ) {
if ( V_8 -> V_126 & V_683 ) {
V_8 -> V_695 -> V_716 . V_110 . V_698 = V_8 -> V_110 . V_698 ;
V_8 -> V_695 -> V_716 . V_110 . V_717 = V_739 ;
V_8 -> V_695 -> V_716 . V_110 . V_720 =
F_91 ( V_642 ) +
F_91 ( V_394 ) ;
V_8 -> V_695 -> V_716 . V_110 . V_721 = V_125 ;
V_8 -> V_695 -> V_708 = V_719 ;
return 0 ;
} else {
V_8 -> V_110 . V_717 &= ~ V_740 ;
V_8 -> V_110 . V_698 |= V_741 ;
F_98 ( V_718 , V_8 -> V_110 . V_717 ) ;
F_352 ( V_8 , V_125 ) ;
return 1 ;
}
}
V_726 = F_91 ( V_714 ) ;
V_739 = V_726 & V_742 ;
V_389 = F_385 ( V_726 ) ;
if ( V_726 & V_743 ) {
unsigned long V_731 ;
if ( ! F_386 ( V_8 , V_739 , & V_731 ) )
F_379 ( V_8 , V_389 , V_731 ) ;
} else
F_387 ( V_8 , V_739 , V_8 -> V_110 . V_391 [ V_389 ] ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static void F_388 ( struct V_7 * V_8 , unsigned long V_731 )
{
F_98 ( V_718 , V_731 ) ;
}
static int F_389 ( struct V_7 * V_8 )
{
F_390 ( V_8 ) ;
return 1 ;
}
static int F_391 ( struct V_7 * V_8 )
{
T_2 V_297 = V_8 -> V_110 . V_391 [ V_744 ] ;
T_3 V_179 ;
if ( F_200 ( V_8 , V_297 , & V_179 ) ) {
F_392 ( V_297 ) ;
F_393 ( V_8 , 0 ) ;
return 1 ;
}
F_394 ( V_297 , V_179 ) ;
V_8 -> V_110 . V_391 [ V_745 ] = V_179 & - 1u ;
V_8 -> V_110 . V_391 [ V_638 ] = ( V_179 >> 32 ) & - 1u ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_395 ( struct V_7 * V_8 )
{
struct V_369 V_73 ;
T_2 V_297 = V_8 -> V_110 . V_391 [ V_744 ] ;
T_3 V_179 = ( V_8 -> V_110 . V_391 [ V_745 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_110 . V_391 [ V_638 ] & - 1u ) << 32 ) ;
V_73 . V_179 = V_179 ;
V_73 . V_78 = V_297 ;
V_73 . V_372 = false ;
if ( F_202 ( V_8 , & V_73 ) != 0 ) {
F_396 ( V_297 , V_179 ) ;
F_393 ( V_8 , 0 ) ;
return 1 ;
}
F_397 ( V_297 , V_179 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_398 ( struct V_7 * V_8 )
{
F_144 ( V_573 , V_8 ) ;
return 1 ;
}
static int F_399 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_93 ( V_501 ) ;
V_69 &= ~ V_322 ;
F_101 ( V_501 , V_69 ) ;
F_144 ( V_573 , V_8 ) ;
++ V_8 -> V_210 . V_746 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_695 -> V_747 &&
! F_400 ( V_8 ) ) {
V_8 -> V_695 -> V_708 = V_748 ;
return 0 ;
}
return 1 ;
}
static int F_401 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
return F_351 ( V_8 ) ;
}
static int F_402 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
F_403 ( V_8 ) ;
return 1 ;
}
static int F_404 ( struct V_7 * V_8 )
{
return F_350 ( V_8 , 0 ) == V_260 ;
}
static int F_405 ( struct V_7 * V_8 )
{
unsigned long V_726 = F_91 ( V_714 ) ;
F_406 ( V_8 , V_726 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_407 ( struct V_7 * V_8 )
{
int V_734 ;
V_734 = F_408 ( V_8 ) ;
F_376 ( V_8 , V_734 ) ;
return 1 ;
}
static int F_409 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
F_410 ( V_8 ) ;
return 1 ;
}
static int F_411 ( struct V_7 * V_8 )
{
T_3 V_749 = F_412 ( V_8 ) ;
T_2 V_78 = F_374 ( V_8 , V_744 ) ;
if ( F_413 ( V_8 , V_78 , V_749 ) == 0 )
F_163 ( V_8 ) ;
return 1 ;
}
static int F_414 ( struct V_7 * V_8 )
{
if ( F_290 ( V_750 ) ) {
unsigned long V_726 = F_91 ( V_714 ) ;
int V_751 , V_290 ;
V_751 = V_726 & V_752 ;
V_290 = V_726 & V_753 ;
if ( ( V_751 == V_754 ) &&
( V_290 == V_755 ) ) {
F_415 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
}
return F_350 ( V_8 , 0 ) == V_260 ;
}
static int F_416 ( struct V_7 * V_8 )
{
unsigned long V_726 = F_91 ( V_714 ) ;
int V_4 = V_726 & 0xff ;
F_417 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_418 ( struct V_7 * V_8 )
{
unsigned long V_726 = F_91 ( V_714 ) ;
T_2 V_290 = V_726 & 0xfff ;
F_419 ( V_8 , V_290 ) ;
return 1 ;
}
static int F_420 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_726 ;
bool V_252 = false ;
T_2 V_253 = 0 ;
T_4 V_756 ;
int V_757 , type , V_758 , V_759 ;
V_758 = ( V_72 -> V_702 & V_706 ) ;
V_759 = ( V_72 -> V_702 & V_760 ) ;
type = ( V_72 -> V_702 & V_761 ) ;
V_726 = F_91 ( V_714 ) ;
V_757 = ( T_2 ) V_726 >> 30 ;
if ( V_757 == V_762 && V_758 ) {
switch ( type ) {
case V_670 :
V_8 -> V_110 . V_763 = false ;
F_343 ( V_8 , true ) ;
break;
case V_27 :
case V_665 :
F_421 ( V_8 ) ;
break;
case V_23 :
if ( V_72 -> V_702 &
V_764 ) {
V_252 = true ;
V_253 =
F_93 ( V_765 ) ;
}
case V_263 :
F_422 ( V_8 ) ;
break;
default:
break;
}
}
V_756 = V_726 ;
if ( ! V_758 || ( type != V_23 &&
type != V_27 &&
type != V_670 ) )
F_163 ( V_8 ) ;
if ( F_423 ( V_8 , V_756 ,
type == V_665 ? V_759 : - 1 , V_757 ,
V_252 , V_253 ) == V_766 ) {
V_8 -> V_695 -> V_708 = V_709 ;
V_8 -> V_695 -> V_710 . V_711 = V_767 ;
V_8 -> V_695 -> V_710 . V_713 = 0 ;
return 0 ;
}
F_98 ( V_718 , F_91 ( V_718 ) & ~ 55 ) ;
return 1 ;
}
static int F_424 ( struct V_7 * V_8 )
{
unsigned long V_726 ;
T_1 V_84 ;
T_2 V_253 ;
int V_768 ;
V_726 = F_91 ( V_714 ) ;
V_768 = ( V_726 >> 7 ) & 0x3 ;
if ( V_768 != 0x3 && V_768 != 0x1 && V_768 != 0 ) {
F_68 ( V_88 L_21 ) ;
F_68 ( V_88 L_22 ,
( long unsigned int ) F_94 ( V_769 ) ,
F_91 ( V_770 ) ) ;
F_68 ( V_88 L_23 ,
( long unsigned int ) V_726 ) ;
V_8 -> V_695 -> V_708 = V_771 ;
V_8 -> V_695 -> V_772 . V_773 = V_774 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_702 & V_706 ) &&
F_52 () &&
( V_726 & V_775 ) )
F_104 ( V_244 , V_671 ) ;
V_84 = F_94 ( V_769 ) ;
F_359 ( V_84 , V_726 ) ;
V_253 = V_726 & ( 1U << 1 ) ;
V_253 |= ( V_726 & ( 1U << 2 ) ) << 2 ;
V_253 |= ( V_726 >> 3 ) & 0x1 ;
V_8 -> V_110 . V_726 = V_726 ;
return F_362 ( V_8 , V_84 , V_253 , NULL , 0 ) ;
}
static T_3 F_425 ( T_3 V_776 , int V_777 )
{
int V_74 ;
T_3 V_104 = 0 ;
for ( V_74 = 51 ; V_74 > V_427 . V_778 ; V_74 -- )
V_104 |= ( 1ULL << V_74 ) ;
if ( V_777 > 2 )
V_104 |= 0xf8 ;
else if ( V_777 == 2 ) {
if ( V_776 & ( 1ULL << 7 ) )
V_104 |= 0x1ff000 ;
else
V_104 |= 0x78 ;
}
return V_104 ;
}
static void F_426 ( struct V_7 * V_8 , T_3 V_776 ,
int V_777 )
{
F_68 ( V_88 L_24 , V_483 , V_776 , V_777 ) ;
F_427 ( ( V_776 & 0x7 ) == 0x2 ) ;
F_427 ( ( V_776 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_427 ( ( V_776 & 0x7 ) == 0x4 ) ;
if ( ( V_776 & 0x7 ) ) {
T_3 V_779 = V_776 & F_425 ( V_776 , V_777 ) ;
if ( V_779 != 0 ) {
F_68 ( V_88 L_25 ,
V_483 , V_779 ) ;
F_427 ( 1 ) ;
}
if ( V_777 == 1 || ( V_777 == 2 && ( V_776 & ( 1ULL << 7 ) ) ) ) {
T_3 V_780 = ( V_776 & 0x38 ) >> 3 ;
if ( V_780 == 2 || V_780 == 3 ||
V_780 == 7 ) {
F_68 ( V_88 L_26 ,
V_483 , V_780 ) ;
F_427 ( 1 ) ;
}
}
}
}
static int F_428 ( struct V_7 * V_8 )
{
T_3 V_781 [ 4 ] ;
int V_782 , V_74 , V_108 ;
T_1 V_84 ;
V_84 = F_94 ( V_769 ) ;
V_108 = F_429 ( V_8 , V_84 , true ) ;
if ( F_290 ( V_108 == V_783 ) )
return F_430 ( V_8 , V_84 , 0 , NULL , 0 ) ==
V_260 ;
if ( F_99 ( V_108 == V_784 ) )
return F_362 ( V_8 , V_84 , 0 , NULL , 0 ) ;
if ( F_99 ( V_108 == V_785 ) )
return 1 ;
F_68 ( V_88 L_27 ) ;
F_68 ( V_88 L_28 , V_84 ) ;
V_782 = F_431 ( V_8 , V_84 , V_781 ) ;
for ( V_74 = V_786 ; V_74 > V_786 - V_782 ; -- V_74 )
F_426 ( V_8 , V_781 [ V_74 - 1 ] , V_74 ) ;
V_8 -> V_695 -> V_708 = V_771 ;
V_8 -> V_695 -> V_772 . V_773 = V_787 ;
return 0 ;
}
static int F_432 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_93 ( V_501 ) ;
V_69 &= ~ V_659 ;
F_101 ( V_501 , V_69 ) ;
++ V_8 -> V_210 . V_788 ;
F_144 ( V_573 , V_8 ) ;
return 1 ;
}
static int F_433 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
enum V_700 V_734 = V_260 ;
int V_108 = 1 ;
T_2 V_789 ;
bool V_790 ;
unsigned V_791 = 130 ;
V_789 = F_93 ( V_501 ) ;
V_790 = V_789 & V_322 ;
while ( ! F_240 ( V_8 ) && V_791 -- != 0 ) {
if ( V_790 && F_345 ( V_8 ) )
return F_399 ( & V_72 -> V_8 ) ;
if ( F_158 ( V_573 , & V_8 -> V_792 ) )
return 1 ;
V_734 = F_350 ( V_8 , V_793 ) ;
if ( V_734 == V_794 ) {
++ V_8 -> V_210 . V_795 ;
V_108 = 0 ;
goto V_523;
}
if ( V_734 != V_260 ) {
V_8 -> V_695 -> V_708 = V_709 ;
V_8 -> V_695 -> V_710 . V_711 = V_767 ;
V_8 -> V_695 -> V_710 . V_713 = 0 ;
return 0 ;
}
if ( V_8 -> V_110 . V_691 ) {
V_8 -> V_110 . V_691 = 0 ;
V_108 = F_351 ( V_8 ) ;
goto V_523;
}
if ( F_434 ( V_796 ) )
goto V_523;
if ( F_435 () )
F_436 () ;
}
V_72 -> F_239 = F_239 ( V_8 ) ;
V_523:
return V_108 ;
}
static int F_437 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
F_438 ( V_8 ) ;
return 1 ;
}
static int F_439 ( struct V_7 * V_8 )
{
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
static struct V_89 * F_440 ( struct V_6 * V_72 )
{
struct V_797 * V_798 ;
F_79 (item, &vmx->nested.vmcs02_pool, list)
if ( V_798 -> V_799 == V_72 -> V_13 . V_800 ) {
F_441 ( & V_798 -> V_801 , & V_72 -> V_13 . V_802 ) ;
return & V_798 -> V_803 ;
}
if ( V_72 -> V_13 . V_804 >= F_442 ( V_805 , 1 ) ) {
V_798 = F_443 ( V_72 -> V_13 . V_802 . V_806 ,
struct V_797 , V_801 ) ;
V_798 -> V_799 = V_72 -> V_13 . V_800 ;
F_441 ( & V_798 -> V_801 , & V_72 -> V_13 . V_802 ) ;
return & V_798 -> V_803 ;
}
V_798 = F_444 ( sizeof( struct V_797 ) , V_432 ) ;
if ( ! V_798 )
return NULL ;
V_798 -> V_803 . V_86 = F_227 () ;
if ( ! V_798 -> V_803 . V_86 ) {
F_445 ( V_798 ) ;
return NULL ;
}
F_69 ( & V_798 -> V_803 ) ;
V_798 -> V_799 = V_72 -> V_13 . V_800 ;
F_147 ( & ( V_798 -> V_801 ) , & ( V_72 -> V_13 . V_802 ) ) ;
V_72 -> V_13 . V_804 ++ ;
return & V_798 -> V_803 ;
}
static void F_446 ( struct V_6 * V_72 , T_1 V_799 )
{
struct V_797 * V_798 ;
F_79 (item, &vmx->nested.vmcs02_pool, list)
if ( V_798 -> V_799 == V_799 ) {
F_230 ( & V_798 -> V_803 ) ;
F_82 ( & V_798 -> V_801 ) ;
F_445 ( V_798 ) ;
V_72 -> V_13 . V_804 -- ;
return;
}
}
static void F_447 ( struct V_6 * V_72 )
{
struct V_797 * V_798 , * V_403 ;
F_217 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_72 -> V_89 != & V_798 -> V_803 )
F_230 ( & V_798 -> V_803 ) ;
F_82 ( & V_798 -> V_801 ) ;
F_445 ( V_798 ) ;
}
V_72 -> V_13 . V_804 = 0 ;
if ( V_72 -> V_89 != & V_72 -> V_807 )
F_230 ( & V_72 -> V_807 ) ;
}
static void F_448 ( struct V_7 * V_8 )
{
F_160 ( V_8 , F_157 ( V_8 )
& ~ ( V_808 | V_809 | V_810 |
V_811 | V_812 | V_813 ) ) ;
}
static void F_449 ( struct V_7 * V_8 )
{
F_160 ( V_8 , ( F_157 ( V_8 )
& ~ ( V_809 | V_810 | V_811 |
V_812 | V_813 ) )
| V_808 ) ;
}
static void F_450 ( struct V_7 * V_8 ,
T_2 V_814 )
{
if ( F_6 ( V_8 ) -> V_13 . V_800 == - 1ull ) {
F_449 ( V_8 ) ;
return;
}
F_160 ( V_8 , ( F_157 ( V_8 )
& ~ ( V_808 | V_809 | V_810 |
V_812 | V_813 ) )
| V_811 ) ;
F_9 ( V_8 ) -> V_814 = V_814 ;
}
static int F_451 ( struct V_7 * V_8 )
{
struct V_448 V_529 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_86 * V_815 ;
const T_3 V_816 = V_373
| V_397 ;
if ( ! F_452 ( V_8 , V_401 ) ||
! F_152 ( V_8 , V_506 ) ||
( F_157 ( V_8 ) & V_242 ) ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
F_244 ( V_8 , & V_529 , V_450 ) ;
if ( F_129 ( V_8 ) && ! V_529 . V_472 ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_268 ( V_8 ) ) {
F_393 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_518 ) {
F_450 ( V_8 , V_817 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( ( V_72 -> V_13 . V_354 & V_816 )
!= V_816 ) {
F_393 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_436 ) {
V_815 = F_227 () ;
if ( ! V_815 )
return - V_433 ;
V_815 -> V_425 |= ( 1u << 31 ) ;
F_66 ( V_815 ) ;
V_72 -> V_13 . V_818 = V_815 ;
}
F_213 ( & ( V_72 -> V_13 . V_802 ) ) ;
V_72 -> V_13 . V_804 = 0 ;
V_72 -> V_13 . V_518 = true ;
F_163 ( V_8 ) ;
F_448 ( V_8 ) ;
return 1 ;
}
static int F_453 ( struct V_7 * V_8 )
{
struct V_448 V_529 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! V_72 -> V_13 . V_518 ) {
F_352 ( V_8 , V_26 ) ;
return 0 ;
}
F_244 ( V_8 , & V_529 , V_450 ) ;
if ( ( F_157 ( V_8 ) & V_242 ) ||
( F_129 ( V_8 ) && ! V_529 . V_472 ) ) {
F_352 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_268 ( V_8 ) ) {
F_393 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_454 ( struct V_6 * V_72 )
{
T_2 V_601 ;
if ( V_436 ) {
if ( V_72 -> V_13 . V_14 != NULL ) {
F_455 ( V_72 ) ;
V_72 -> V_13 . V_819 = false ;
V_601 = F_93 ( V_613 ) ;
V_601 &= ~ V_67 ;
F_101 ( V_613 , V_601 ) ;
F_102 ( V_611 , - 1ull ) ;
}
}
F_456 ( V_72 -> V_13 . V_820 ) ;
F_13 ( V_72 -> V_13 . V_820 ) ;
}
static void F_457 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_13 . V_518 )
return;
V_72 -> V_13 . V_518 = false ;
if ( V_72 -> V_13 . V_800 != - 1ull ) {
F_454 ( V_72 ) ;
V_72 -> V_13 . V_800 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
if ( V_436 )
F_228 ( V_72 -> V_13 . V_818 ) ;
if ( V_72 -> V_13 . V_559 ) {
F_13 ( V_72 -> V_13 . V_559 ) ;
V_72 -> V_13 . V_559 = 0 ;
}
F_447 ( V_72 ) ;
}
static int F_458 ( struct V_7 * V_8 )
{
if ( ! F_453 ( V_8 ) )
return 1 ;
F_457 ( F_6 ( V_8 ) ) ;
F_163 ( V_8 ) ;
F_448 ( V_8 ) ;
return 1 ;
}
static int F_459 ( struct V_7 * V_8 ,
unsigned long V_726 ,
T_2 V_821 , T_5 * V_108 )
{
int V_822 = V_821 & 3 ;
int V_823 = ( V_821 >> 7 ) & 7 ;
bool V_824 = V_821 & ( 1u << 10 ) ;
int V_825 = ( V_821 >> 15 ) & 7 ;
int V_826 = ( V_821 >> 18 ) & 0xf ;
bool V_827 = ! ( V_821 & ( 1u << 22 ) ) ;
int V_828 = ( V_821 >> 23 ) & 0xf ;
bool V_829 = ! ( V_821 & ( 1u << 27 ) ) ;
if ( V_824 ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
* V_108 = F_267 ( V_8 , V_825 ) ;
if ( V_829 )
* V_108 += F_374 ( V_8 , V_828 ) ;
if ( V_827 )
* V_108 += F_374 ( V_8 , V_826 ) << V_822 ;
* V_108 += V_726 ;
if ( V_823 == 1 )
* V_108 &= 0xffffffff ;
return 0 ;
}
static int F_460 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_799 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
struct V_830 V_831 ;
if ( ! F_453 ( V_8 ) )
return 1 ;
if ( F_459 ( V_8 , F_91 ( V_714 ) ,
F_93 ( V_832 ) , & V_80 ) )
return 1 ;
if ( F_461 ( & V_8 -> V_110 . V_833 , V_80 , & V_799 ,
sizeof( V_799 ) , & V_831 ) ) {
F_462 ( V_8 , & V_831 ) ;
return 1 ;
}
if ( ! F_463 ( V_799 , V_422 ) ) {
F_450 ( V_8 , V_834 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_799 == V_72 -> V_13 . V_800 ) {
F_454 ( V_72 ) ;
V_72 -> V_13 . V_800 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
V_15 = F_10 ( V_8 , V_799 ) ;
if ( V_15 == NULL ) {
F_144 ( V_261 , V_8 ) ;
return 1 ;
}
V_12 = F_464 ( V_15 ) ;
V_12 -> V_835 = 0 ;
F_456 ( V_15 ) ;
F_13 ( V_15 ) ;
F_446 ( V_72 , V_799 ) ;
F_163 ( V_8 ) ;
F_448 ( V_8 ) ;
return 1 ;
}
static int F_465 ( struct V_7 * V_8 )
{
return F_466 ( V_8 , true ) ;
}
static int F_467 ( struct V_7 * V_8 )
{
return F_466 ( V_8 , false ) ;
}
static inline int F_468 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_836 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_469 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_470 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_108 )
{
short V_290 = F_8 ( V_9 ) ;
char * V_113 ;
if ( V_290 < 0 )
return 0 ;
V_113 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_290 ;
switch ( F_468 ( V_9 ) ) {
case V_837 :
* V_108 = * ( ( V_838 * ) V_113 ) ;
return 1 ;
case V_839 :
* V_108 = * ( ( T_4 * ) V_113 ) ;
return 1 ;
case V_836 :
* V_108 = * ( ( T_2 * ) V_113 ) ;
return 1 ;
case V_840 :
* V_108 = * ( ( T_3 * ) V_113 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_471 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_841 ) {
short V_290 = F_8 ( V_9 ) ;
char * V_113 = ( ( char * ) F_9 ( V_8 ) ) + V_290 ;
if ( V_290 < 0 )
return false ;
switch ( F_468 ( V_9 ) ) {
case V_839 :
* ( T_4 * ) V_113 = V_841 ;
return true ;
case V_836 :
* ( T_2 * ) V_113 = V_841 ;
return true ;
case V_840 :
* ( T_3 * ) V_113 = V_841 ;
return true ;
case V_837 :
* ( V_838 * ) V_113 = V_841 ;
return true ;
default:
return false ;
}
}
static void F_455 ( struct V_6 * V_72 )
{
int V_74 ;
unsigned long V_9 ;
T_3 V_841 ;
struct V_86 * V_815 = V_72 -> V_13 . V_818 ;
const unsigned long * V_229 = V_842 ;
const int V_843 = V_844 ;
F_70 ( V_815 ) ;
for ( V_74 = 0 ; V_74 < V_843 ; V_74 ++ ) {
V_9 = V_229 [ V_74 ] ;
switch ( F_468 ( V_9 ) ) {
case V_839 :
V_841 = F_92 ( V_9 ) ;
break;
case V_836 :
V_841 = F_93 ( V_9 ) ;
break;
case V_840 :
V_841 = F_94 ( V_9 ) ;
break;
case V_837 :
V_841 = F_91 ( V_9 ) ;
break;
}
F_471 ( & V_72 -> V_8 , V_9 , V_841 ) ;
}
F_66 ( V_815 ) ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
static void F_472 ( struct V_6 * V_72 )
{
const unsigned long * V_229 [] = {
V_842 ,
V_845
} ;
const int V_846 [] = {
V_844 ,
V_847
} ;
int V_74 , V_848 ;
unsigned long V_9 ;
T_3 V_841 = 0 ;
struct V_86 * V_815 = V_72 -> V_13 . V_818 ;
F_70 ( V_815 ) ;
for ( V_848 = 0 ; V_848 < F_473 ( V_229 ) ; V_848 ++ ) {
for ( V_74 = 0 ; V_74 < V_846 [ V_848 ] ; V_74 ++ ) {
V_9 = V_229 [ V_848 ] [ V_74 ] ;
F_470 ( & V_72 -> V_8 , V_9 , & V_841 ) ;
switch ( F_468 ( V_9 ) ) {
case V_839 :
F_100 ( V_9 , ( T_4 ) V_841 ) ;
break;
case V_836 :
F_101 ( V_9 , ( T_2 ) V_841 ) ;
break;
case V_840 :
F_102 ( V_9 , ( T_3 ) V_841 ) ;
break;
case V_837 :
F_98 ( V_9 , ( long ) V_841 ) ;
break;
}
}
}
F_66 ( V_815 ) ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
static int F_474 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( V_72 -> V_13 . V_800 == - 1ull ) {
F_449 ( V_8 ) ;
F_163 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_475 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_841 ;
unsigned long V_726 = F_91 ( V_714 ) ;
T_2 V_821 = F_93 ( V_832 ) ;
T_5 V_80 = 0 ;
if ( ! F_453 ( V_8 ) ||
! F_474 ( V_8 ) )
return 1 ;
V_9 = F_374 ( V_8 , ( ( ( V_821 ) >> 28 ) & 0xf ) ) ;
if ( ! F_470 ( V_8 , V_9 , & V_841 ) ) {
F_450 ( V_8 , V_849 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_821 & ( 1u << 10 ) ) {
F_379 ( V_8 , ( ( ( V_821 ) >> 3 ) & 0xf ) ,
V_841 ) ;
} else {
if ( F_459 ( V_8 , V_726 ,
V_821 , & V_80 ) )
return 1 ;
F_476 ( & V_8 -> V_110 . V_833 , V_80 ,
& V_841 , ( F_129 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_448 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_477 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_80 ;
unsigned long V_726 = F_91 ( V_714 ) ;
T_2 V_821 = F_93 ( V_832 ) ;
T_3 V_841 = 0 ;
struct V_830 V_831 ;
if ( ! F_453 ( V_8 ) ||
! F_474 ( V_8 ) )
return 1 ;
if ( V_821 & ( 1u << 10 ) )
V_841 = F_374 ( V_8 ,
( ( ( V_821 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_459 ( V_8 , V_726 ,
V_821 , & V_80 ) )
return 1 ;
if ( F_461 ( & V_8 -> V_110 . V_833 , V_80 ,
& V_841 , ( F_129 ( V_8 ) ? 8 : 4 ) , & V_831 ) ) {
F_462 ( V_8 , & V_831 ) ;
return 1 ;
}
}
V_9 = F_374 ( V_8 , ( ( ( V_821 ) >> 28 ) & 0xf ) ) ;
if ( F_469 ( V_9 ) ) {
F_450 ( V_8 ,
V_850 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( ! F_471 ( V_8 , V_9 , V_841 ) ) {
F_450 ( V_8 , V_849 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
F_448 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_478 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_799 ;
struct V_830 V_831 ;
T_2 V_601 ;
if ( ! F_453 ( V_8 ) )
return 1 ;
if ( F_459 ( V_8 , F_91 ( V_714 ) ,
F_93 ( V_832 ) , & V_80 ) )
return 1 ;
if ( F_461 ( & V_8 -> V_110 . V_833 , V_80 , & V_799 ,
sizeof( V_799 ) , & V_831 ) ) {
F_462 ( V_8 , & V_831 ) ;
return 1 ;
}
if ( ! F_463 ( V_799 , V_422 ) ) {
F_450 ( V_8 , V_851 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_800 != V_799 ) {
struct V_12 * V_852 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_799 ) ;
if ( V_15 == NULL ) {
F_449 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
V_852 = F_464 ( V_15 ) ;
if ( V_852 -> V_425 != V_355 ) {
F_456 ( V_15 ) ;
F_15 ( V_15 ) ;
F_450 ( V_8 ,
V_853 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_800 != - 1ull )
F_454 ( V_72 ) ;
V_72 -> V_13 . V_800 = V_799 ;
V_72 -> V_13 . V_14 = V_852 ;
V_72 -> V_13 . V_820 = V_15 ;
if ( V_436 ) {
V_601 = F_93 ( V_613 ) ;
V_601 |= V_67 ;
F_101 ( V_613 , V_601 ) ;
F_102 ( V_611 ,
F_67 ( V_72 -> V_13 . V_818 ) ) ;
V_72 -> V_13 . V_819 = true ;
}
}
F_448 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_479 ( struct V_7 * V_8 )
{
unsigned long V_726 = F_91 ( V_714 ) ;
T_2 V_821 = F_93 ( V_832 ) ;
T_5 V_854 ;
struct V_830 V_831 ;
if ( ! F_453 ( V_8 ) )
return 1 ;
if ( F_459 ( V_8 , V_726 ,
V_821 , & V_854 ) )
return 1 ;
if ( F_476 ( & V_8 -> V_110 . V_833 , V_854 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_800 ,
sizeof( T_3 ) , & V_831 ) ) {
F_462 ( V_8 , & V_831 ) ;
return 1 ;
}
F_448 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_480 ( struct V_7 * V_8 )
{
T_2 V_821 , V_855 ;
unsigned long type ;
T_5 V_80 ;
struct V_830 V_831 ;
struct {
T_3 V_83 , V_84 ;
} V_82 ;
T_3 V_856 = ( ( 1ull << 51 ) - 1 ) & V_511 ;
if ( ! ( V_339 & V_55 ) ||
! ( V_340 & V_341 ) ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
if ( ! F_453 ( V_8 ) )
return 1 ;
if ( ! F_152 ( V_8 , V_506 ) ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
V_821 = F_93 ( V_832 ) ;
type = F_374 ( V_8 , ( V_821 >> 28 ) & 0xf ) ;
V_855 = ( V_340 >> V_857 ) & 6 ;
if ( ! ( V_855 & ( 1UL << type ) ) ) {
F_450 ( V_8 ,
V_858 ) ;
return 1 ;
}
if ( F_459 ( V_8 , F_91 ( V_714 ) ,
V_821 , & V_80 ) )
return 1 ;
if ( F_461 ( & V_8 -> V_110 . V_833 , V_80 , & V_82 ,
sizeof( V_82 ) , & V_831 ) ) {
F_462 ( V_8 , & V_831 ) ;
return 1 ;
}
switch ( type ) {
case V_101 :
if ( ( V_82 . V_83 & V_856 ) !=
( F_481 ( V_8 ) & V_856 ) )
break;
case V_99 :
F_482 ( V_8 ) ;
F_483 ( V_8 ) ;
F_448 ( V_8 ) ;
break;
default:
F_358 ( 1 ) ;
break;
}
F_163 ( V_8 ) ;
return 1 ;
}
static bool F_484 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_726 ;
T_1 V_859 , V_860 ;
unsigned int V_728 ;
int V_423 ;
T_6 V_861 ;
if ( F_57 ( V_12 , V_331 ) )
return 1 ;
if ( ! F_57 ( V_12 , V_332 ) )
return 0 ;
V_726 = F_91 ( V_714 ) ;
V_728 = V_726 >> 16 ;
V_423 = ( V_726 & 7 ) + 1 ;
V_860 = ( T_1 ) - 1 ;
V_861 = - 1 ;
while ( V_423 > 0 ) {
if ( V_728 < 0x8000 )
V_859 = V_12 -> V_862 ;
else if ( V_728 < 0x10000 )
V_859 = V_12 -> V_863 ;
else
return 1 ;
V_859 += ( V_728 & 0x7fff ) / 8 ;
if ( V_860 != V_859 )
if ( F_485 ( V_8 -> V_17 , V_859 , & V_861 , 1 ) )
return 1 ;
if ( V_861 & ( 1 << ( V_728 & 7 ) ) )
return 1 ;
V_728 ++ ;
V_423 -- ;
V_860 = V_859 ;
}
return 0 ;
}
static bool F_486 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_708 )
{
T_2 V_348 = V_8 -> V_110 . V_391 [ V_744 ] ;
T_1 V_859 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_859 = V_12 -> V_268 ;
if ( V_708 == V_864 )
V_859 += 2048 ;
if ( V_348 >= 0xc0000000 ) {
V_348 -= 0xc0000000 ;
V_859 += 1024 ;
}
if ( V_348 < 1024 * 8 ) {
unsigned char V_861 ;
if ( F_485 ( V_8 -> V_17 , V_859 + V_348 / 8 , & V_861 , 1 ) )
return 1 ;
return 1 & ( V_861 >> ( V_348 & 7 ) ) ;
} else
return 1 ;
}
static bool F_487 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_726 = F_91 ( V_714 ) ;
int V_733 = V_726 & 15 ;
int V_389 = ( V_726 >> 8 ) & 15 ;
unsigned long V_731 = F_374 ( V_8 , V_389 ) ;
switch ( ( V_726 >> 4 ) & 3 ) {
case 0 :
switch ( V_733 ) {
case 0 :
if ( V_12 -> V_227 &
( V_731 ^ V_12 -> V_231 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_865 >= 1 &&
V_12 -> V_866 == V_731 ) ||
( V_12 -> V_865 >= 2 &&
V_12 -> V_867 == V_731 ) ||
( V_12 -> V_865 >= 3 &&
V_12 -> V_868 == V_731 ) ||
( V_12 -> V_865 >= 4 &&
V_12 -> V_869 == V_731 ) )
return 0 ;
if ( F_57 ( V_12 , V_326 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_233 &
( V_12 -> V_234 ^ V_731 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_328 ) )
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
switch ( V_733 ) {
case 3 :
if ( V_12 -> V_69 &
V_327 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_329 )
return 1 ;
break;
}
break;
case 3 :
if ( V_12 -> V_227 & 0xe &
( V_731 ^ V_12 -> V_231 ) )
return 1 ;
if ( ( V_12 -> V_227 & 0x1 ) &&
! ( V_12 -> V_231 & 0x1 ) &&
( V_731 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_488 ( struct V_7 * V_8 )
{
T_2 V_19 = F_93 ( V_870 ) ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_708 = V_72 -> V_708 ;
if ( V_72 -> V_13 . V_255 )
return 0 ;
if ( F_99 ( V_72 -> V_871 ) ) {
F_489 ( L_29 , V_483 ,
F_93 ( V_103 ) ) ;
return 1 ;
}
switch ( V_708 ) {
case V_674 :
if ( ! F_61 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_100 ;
return V_12 -> V_133 &
( 1u << ( V_19 & V_21 ) ) ;
case V_677 :
return 0 ;
case V_872 :
return 1 ;
case V_873 :
return F_57 ( V_12 , V_322 ) ;
case V_874 :
return F_57 ( V_12 , V_659 ) ;
case V_875 :
return 1 ;
case V_876 :
return 1 ;
case V_877 :
return F_57 ( V_12 , V_323 ) ;
case V_878 :
return 1 ;
case V_879 :
return F_57 ( V_12 , V_324 ) ;
case V_880 :
return F_57 ( V_12 , V_334 ) ;
case V_881 :
return F_57 ( V_12 , V_335 ) ;
case V_882 : case V_883 :
case V_884 : case V_885 :
case V_886 : case V_887 :
case V_888 : case V_889 :
case V_890 : case V_891 :
case V_892 :
return 1 ;
case V_893 :
return F_487 ( V_8 , V_12 ) ;
case V_894 :
return F_57 ( V_12 , V_330 ) ;
case V_895 :
return F_484 ( V_8 , V_12 ) ;
case V_896 :
case V_864 :
return F_486 ( V_8 , V_12 , V_708 ) ;
case V_897 :
return 1 ;
case V_898 :
return F_57 ( V_12 , V_325 ) ;
case V_899 :
return F_57 ( V_12 , V_333 ) ;
case V_900 :
return F_57 ( V_12 , V_336 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_901 :
return 0 ;
case V_902 :
return 1 ;
case V_903 :
return F_58 ( V_12 ,
V_35 ) ;
case V_774 :
return 0 ;
case V_787 :
return 0 ;
case V_904 :
return V_12 -> V_71 &
V_305 ;
case V_905 :
return F_58 ( V_12 , V_63 ) ;
case V_906 :
return 1 ;
default:
return 1 ;
}
}
static void F_490 ( struct V_7 * V_8 , T_3 * V_907 , T_3 * V_908 )
{
* V_907 = F_91 ( V_714 ) ;
* V_908 = F_93 ( V_870 ) ;
}
static int F_491 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_708 = V_72 -> V_708 ;
T_2 V_909 = V_72 -> V_702 ;
if ( V_72 -> F_239 )
return F_433 ( V_8 ) ;
if ( V_72 -> V_13 . V_255 )
F_144 ( V_573 , V_8 ) ;
if ( ! F_112 ( V_8 ) && ( V_708 == V_884 ||
V_708 == V_888 ) )
V_72 -> V_13 . V_255 = 1 ;
else
V_72 -> V_13 . V_255 = 0 ;
if ( F_112 ( V_8 ) && F_488 ( V_8 ) ) {
F_167 ( V_8 ) ;
return 1 ;
}
if ( V_708 & V_910 ) {
V_8 -> V_695 -> V_708 = V_911 ;
V_8 -> V_695 -> V_912 . V_913
= V_708 ;
return 0 ;
}
if ( F_99 ( V_72 -> V_871 ) ) {
V_8 -> V_695 -> V_708 = V_911 ;
V_8 -> V_695 -> V_912 . V_913
= F_93 ( V_103 ) ;
return 0 ;
}
if ( ( V_909 & V_706 ) &&
( V_708 != V_674 &&
V_708 != V_774 &&
V_708 != V_875 ) ) {
V_8 -> V_695 -> V_708 = V_709 ;
V_8 -> V_695 -> V_710 . V_711 = V_914 ;
V_8 -> V_695 -> V_710 . V_713 = 2 ;
V_8 -> V_695 -> V_710 . V_179 [ 0 ] = V_909 ;
V_8 -> V_695 -> V_710 . V_179 [ 1 ] = V_708 ;
return 0 ;
}
if ( F_99 ( ! F_52 () && V_72 -> V_637 &&
! ( F_112 ( V_8 ) && F_59 (
F_9 ( V_8 ) ) ) ) ) {
if ( F_345 ( V_8 ) ) {
V_72 -> V_637 = 0 ;
} else if ( V_72 -> V_666 > 1000000000LL &&
V_8 -> V_110 . V_676 ) {
F_68 ( V_162 L_30
L_31 ,
V_483 , V_8 -> V_292 ) ;
V_72 -> V_637 = 0 ;
}
}
if ( V_708 < V_915
&& V_916 [ V_708 ] )
return V_916 [ V_708 ] ( V_8 ) ;
else {
V_8 -> V_695 -> V_708 = V_771 ;
V_8 -> V_695 -> V_772 . V_773 = V_708 ;
}
return 0 ;
}
static void V_440 ( struct V_7 * V_8 , int V_917 , int V_918 )
{
if ( V_918 == - 1 || V_917 < V_918 ) {
F_101 ( V_653 , 0 ) ;
return;
}
F_101 ( V_653 , V_918 ) ;
}
static void F_492 ( struct V_7 * V_8 , bool V_919 )
{
T_2 V_920 ;
if ( ! F_28 () ||
! F_308 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_920 = F_93 ( V_613 ) ;
if ( V_919 ) {
V_920 &= ~ V_35 ;
V_920 |= V_36 ;
} else {
V_920 &= ~ V_36 ;
V_920 |= V_35 ;
}
F_101 ( V_613 , V_920 ) ;
F_174 ( V_8 ) ;
}
static void F_493 ( struct V_17 * V_17 , int V_921 )
{
T_4 V_922 ;
T_6 V_399 ;
if ( ! F_308 ( V_17 ) )
return;
if ( V_921 == - 1 )
V_921 = 0 ;
V_922 = F_92 ( V_618 ) ;
V_399 = V_922 >> 8 ;
if ( V_921 != V_399 ) {
V_922 &= 0xff ;
V_922 |= V_921 << 8 ;
F_100 ( V_618 , V_922 ) ;
}
}
static void F_494 ( int V_4 )
{
T_4 V_922 ;
T_6 V_399 ;
V_922 = F_92 ( V_618 ) ;
V_399 = ( T_6 ) V_922 & 0xff ;
if ( ( T_6 ) V_4 != V_399 ) {
V_922 &= ~ 0xff ;
V_922 |= ( T_6 ) V_4 ;
F_100 ( V_618 , V_922 ) ;
}
}
static void F_495 ( struct V_7 * V_8 , int V_923 )
{
if ( V_923 == - 1 )
return;
F_494 ( V_923 ) ;
}
static void F_496 ( struct V_7 * V_8 , T_3 * V_924 )
{
if ( ! F_308 ( V_8 -> V_17 ) )
return;
F_102 ( V_614 , V_924 [ 0 ] ) ;
F_102 ( V_615 , V_924 [ 1 ] ) ;
F_102 ( V_616 , V_924 [ 2 ] ) ;
F_102 ( V_617 , V_924 [ 3 ] ) ;
}
static void F_497 ( struct V_6 * V_72 )
{
T_2 V_703 ;
if ( ! ( V_72 -> V_708 == V_901
|| V_72 -> V_708 == V_674 ) )
return;
V_72 -> V_703 = F_93 ( V_870 ) ;
V_703 = V_72 -> V_703 ;
if ( F_21 ( V_703 ) )
F_353 () ;
if ( ( V_703 & V_20 ) == V_670 &&
( V_703 & V_22 ) ) {
F_498 ( & V_72 -> V_8 ) ;
asm("int $2");
F_499 ( & V_72 -> V_8 ) ;
}
}
static void F_500 ( struct V_7 * V_8 )
{
T_2 V_703 = F_93 ( V_870 ) ;
if ( ( V_703 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_135 ;
T_16 * V_925 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
#ifdef F_95
unsigned long V_267 ;
#endif
V_4 = V_703 & V_21 ;
V_925 = ( T_16 * ) V_72 -> V_592 + V_4 ;
V_135 = F_501 ( * V_925 ) ;
asm volatile(
#ifdef F_95
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
#ifdef F_95
[sp]"=&r"(tmp)
#endif
:
[entry]"r"(entry),
[ss]"i"(__KERNEL_DS),
[cs]"i"(__KERNEL_CS)
);
} else
F_148 () ;
}
static void F_502 ( struct V_6 * V_72 )
{
T_2 V_703 ;
bool V_926 ;
T_6 V_4 ;
bool V_927 ;
V_927 = V_72 -> V_702 & V_706 ;
if ( F_52 () ) {
if ( V_72 -> V_668 )
return;
V_703 = F_93 ( V_870 ) ;
V_926 = ( V_703 & V_775 ) != 0 ;
V_4 = V_703 & V_21 ;
if ( ( V_703 & V_22 ) && V_926 &&
V_4 != V_687 && ! V_927 )
F_104 ( V_244 ,
V_671 ) ;
else
V_72 -> V_668 =
! ( F_93 ( V_244 )
& V_671 ) ;
} else if ( F_99 ( V_72 -> V_637 ) )
V_72 -> V_666 +=
F_503 ( F_504 ( F_505 () , V_72 -> V_928 ) ) ;
}
static void F_506 ( struct V_7 * V_8 ,
T_2 V_702 ,
int V_929 ,
int V_930 )
{
T_6 V_4 ;
int type ;
bool V_927 ;
V_927 = V_702 & V_706 ;
V_8 -> V_110 . V_763 = false ;
F_422 ( V_8 ) ;
F_421 ( V_8 ) ;
if ( ! V_927 )
return;
F_144 ( V_573 , V_8 ) ;
V_4 = V_702 & V_760 ;
type = V_702 & V_761 ;
switch ( type ) {
case V_670 :
V_8 -> V_110 . V_763 = true ;
F_343 ( V_8 , false ) ;
break;
case V_263 :
V_8 -> V_110 . V_259 = F_93 ( V_929 ) ;
case V_23 :
if ( V_702 & V_764 ) {
T_2 V_734 = F_93 ( V_930 ) ;
F_196 ( V_8 , V_4 , V_734 ) ;
} else
F_352 ( V_8 , V_4 ) ;
break;
case V_665 :
V_8 -> V_110 . V_259 = F_93 ( V_929 ) ;
case V_27 :
F_507 ( V_8 , V_4 , type == V_665 ) ;
break;
default:
break;
}
}
static void F_508 ( struct V_6 * V_72 )
{
F_506 ( & V_72 -> V_8 , V_72 -> V_702 ,
V_251 ,
V_765 ) ;
}
static void F_509 ( struct V_7 * V_8 )
{
F_506 ( V_8 ,
F_93 ( V_264 ) ,
V_262 ,
V_256 ) ;
F_101 ( V_264 , 0 ) ;
}
static void F_510 ( struct V_6 * V_72 )
{
int V_74 , V_931 ;
struct V_932 * V_933 ;
V_933 = F_511 ( & V_931 ) ;
if ( ! V_933 )
return;
for ( V_74 = 0 ; V_74 < V_931 ; V_74 ++ )
if ( V_933 [ V_74 ] . V_150 == V_933 [ V_74 ] . V_149 )
F_114 ( V_72 , V_933 [ V_74 ] . V_73 ) ;
else
F_116 ( V_72 , V_933 [ V_74 ] . V_73 , V_933 [ V_74 ] . V_149 ,
V_933 [ V_74 ] . V_150 ) ;
}
static void T_17 F_512 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_934 ;
if ( F_99 ( ! F_52 () && V_72 -> V_637 ) )
V_72 -> V_928 = F_505 () ;
if ( V_72 -> F_239 )
return;
if ( V_72 -> V_13 . V_819 ) {
F_472 ( V_72 ) ;
V_72 -> V_13 . V_819 = false ;
}
if ( F_158 ( V_390 , ( unsigned long * ) & V_8 -> V_110 . V_493 ) )
F_98 ( V_392 , V_8 -> V_110 . V_391 [ V_390 ] ) ;
if ( F_158 ( V_393 , ( unsigned long * ) & V_8 -> V_110 . V_493 ) )
F_98 ( V_394 , V_8 -> V_110 . V_391 [ V_393 ] ) ;
if ( V_8 -> V_126 & V_682 )
F_162 ( V_8 , 0 ) ;
F_510 ( V_72 ) ;
V_934 = F_513 () ;
V_72 -> V_935 = V_72 -> V_89 -> V_91 ;
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
#ifdef F_95
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
#ifdef F_95
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
#ifdef F_95
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
#ifdef F_95
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_934 )
F_514 ( V_934 ) ;
#ifndef F_95
F_135 ( V_198 , V_936 ) ;
F_135 ( V_200 , V_936 ) ;
#endif
V_8 -> V_110 . V_111 = ~ ( ( 1 << V_393 ) | ( 1 << V_390 )
| ( 1 << V_238 )
| ( 1 << V_464 )
| ( 1 << V_395 )
| ( 1 << V_112 )
| ( 1 << V_488 ) ) ;
V_8 -> V_110 . V_493 = 0 ;
V_72 -> V_702 = F_93 ( V_937 ) ;
V_72 -> V_89 -> V_91 = 1 ;
V_72 -> V_708 = F_93 ( V_938 ) ;
F_515 ( V_72 -> V_708 , V_8 , V_939 ) ;
F_497 ( V_72 ) ;
F_502 ( V_72 ) ;
F_508 ( V_72 ) ;
}
static void F_516 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_301 ( V_72 ) ;
F_457 ( V_72 ) ;
F_230 ( V_72 -> V_89 ) ;
F_445 ( V_72 -> V_77 ) ;
F_517 ( V_8 ) ;
F_518 ( V_940 , V_72 ) ;
}
static struct V_7 * F_519 ( struct V_17 * V_17 , unsigned int V_941 )
{
int V_734 ;
struct V_6 * V_72 = F_520 ( V_940 , V_432 ) ;
int V_90 ;
if ( ! V_72 )
return F_521 ( - V_433 ) ;
F_297 ( V_72 ) ;
V_734 = F_522 ( & V_72 -> V_8 , V_17 , V_941 ) ;
if ( V_734 )
goto V_942;
V_72 -> V_77 = F_444 ( V_422 , V_432 ) ;
V_734 = - V_433 ;
if ( ! V_72 -> V_77 ) {
goto V_943;
}
V_72 -> V_89 = & V_72 -> V_807 ;
V_72 -> V_89 -> V_86 = F_227 () ;
if ( ! V_72 -> V_89 -> V_86 )
goto V_944;
if ( ! V_214 )
F_143 ( F_67 ( F_81 ( V_213 , F_78 () ) ) ) ;
F_69 ( V_72 -> V_89 ) ;
if ( ! V_214 )
F_150 () ;
V_90 = F_523 () ;
F_142 ( & V_72 -> V_8 , V_90 ) ;
V_72 -> V_8 . V_90 = V_90 ;
V_734 = F_325 ( V_72 ) ;
F_149 ( & V_72 -> V_8 ) ;
F_524 () ;
if ( V_734 )
goto F_228;
if ( F_48 ( V_17 ) ) {
V_734 = F_292 ( V_17 ) ;
if ( V_734 )
goto F_228;
}
if ( V_100 ) {
if ( ! V_17 -> V_110 . V_514 )
V_17 -> V_110 . V_514 =
V_945 ;
V_734 = - V_433 ;
if ( F_296 ( V_17 ) != 0 )
goto F_228;
if ( ! F_289 ( V_17 ) )
goto F_228;
}
V_72 -> V_13 . V_800 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
return & V_72 -> V_8 ;
F_228:
F_230 ( V_72 -> V_89 ) ;
V_944:
F_445 ( V_72 -> V_77 ) ;
V_943:
F_517 ( & V_72 -> V_8 ) ;
V_942:
F_301 ( V_72 ) ;
F_518 ( V_940 , V_72 ) ;
return F_521 ( V_734 ) ;
}
static void T_11 F_525 ( void * V_946 )
{
struct V_29 V_411 ;
* ( int * ) V_946 = 0 ;
if ( F_221 ( & V_411 ) < 0 )
* ( int * ) V_946 = - V_410 ;
if ( memcmp ( & V_29 , & V_411 , sizeof( struct V_29 ) ) != 0 ) {
F_68 ( V_88 L_32 ,
F_526 () ) ;
* ( int * ) V_946 = - V_410 ;
}
}
static int F_527 ( void )
{
return V_508 + 1 ;
}
static T_3 F_528 ( struct V_7 * V_8 , T_13 V_947 , bool V_948 )
{
T_3 V_108 ;
if ( V_948 )
V_108 = V_949 << V_950 ;
else if ( V_8 -> V_17 -> V_110 . V_951 &&
! ( V_8 -> V_17 -> V_110 . V_952 & V_953 ) )
V_108 = F_529 ( V_8 , V_947 ) <<
V_950 ;
else
V_108 = ( V_954 << V_950 )
| V_955 ;
return V_108 ;
}
static int F_530 ( void )
{
if ( V_100 && ! F_38 () )
return V_956 ;
else
return V_957 ;
}
static void F_531 ( struct V_7 * V_8 )
{
struct V_295 * V_296 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_601 ;
V_72 -> V_279 = false ;
if ( F_171 () ) {
V_601 = F_93 ( V_613 ) ;
if ( V_601 & V_60 ) {
V_296 = F_189 ( V_8 , 0x80000001 , 0 ) ;
if ( V_296 && ( V_296 -> V_958 & V_68 ( V_959 ) ) )
V_72 -> V_279 = true ;
else {
V_601 &= ~ V_60 ;
F_101 ( V_613 ,
V_601 ) ;
}
}
}
V_296 = F_189 ( V_8 , 0x7 , 0 ) ;
if ( F_172 () &&
V_296 && ( V_296 -> V_960 & V_68 ( V_961 ) ) &&
F_532 ( V_8 ) ) {
V_601 = F_93 ( V_613 ) ;
V_601 |= V_61 ;
F_101 ( V_613 ,
V_601 ) ;
} else {
if ( F_26 () ) {
V_601 = F_93 ( V_613 ) ;
V_601 &= ~ V_61 ;
F_101 ( V_613 ,
V_601 ) ;
}
if ( V_296 )
V_296 -> V_960 &= ~ V_68 ( V_961 ) ;
}
}
static void F_533 ( T_2 V_962 , struct V_295 * V_135 )
{
if ( V_962 == 1 && V_13 )
V_135 -> V_297 |= V_68 ( V_298 ) ;
}
static void F_534 ( struct V_7 * V_8 ,
struct V_830 * V_963 )
{
struct V_12 * V_12 ;
F_167 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_963 -> V_253 & V_707 )
V_12 -> V_673 = V_787 ;
else
V_12 -> V_673 = V_774 ;
V_12 -> V_726 = V_8 -> V_110 . V_726 ;
V_12 -> V_964 = V_963 -> V_168 ;
}
static unsigned long F_481 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_965 ;
}
static int F_535 ( struct V_7 * V_8 )
{
int V_540 = F_536 ( V_8 , & V_8 -> V_110 . V_484 ,
V_340 & V_43 ) ;
V_8 -> V_110 . V_484 . V_966 = F_265 ;
V_8 -> V_110 . V_484 . V_967 = F_481 ;
V_8 -> V_110 . V_484 . V_968 = F_534 ;
V_8 -> V_110 . V_492 = & V_8 -> V_110 . V_969 ;
return V_540 ;
}
static void F_537 ( struct V_7 * V_8 )
{
V_8 -> V_110 . V_492 = & V_8 -> V_110 . V_484 ;
}
static void F_538 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_601 ;
F_100 ( V_970 , V_12 -> V_971 ) ;
F_100 ( V_641 , V_12 -> V_972 ) ;
F_100 ( V_973 , V_12 -> V_974 ) ;
F_100 ( V_975 , V_12 -> V_976 ) ;
F_100 ( V_977 , V_12 -> V_978 ) ;
F_100 ( V_979 , V_12 -> V_980 ) ;
F_100 ( V_644 , V_12 -> V_981 ) ;
F_100 ( V_643 , V_12 -> V_982 ) ;
F_101 ( V_983 , V_12 -> V_984 ) ;
F_101 ( V_985 , V_12 -> V_986 ) ;
F_101 ( V_987 , V_12 -> V_988 ) ;
F_101 ( V_989 , V_12 -> V_990 ) ;
F_101 ( V_991 , V_12 -> V_992 ) ;
F_101 ( V_993 , V_12 -> V_994 ) ;
F_101 ( V_646 , V_12 -> V_995 ) ;
F_101 ( V_477 , V_12 -> V_996 ) ;
F_101 ( V_527 , V_12 -> V_997 ) ;
F_101 ( V_525 , V_12 -> V_998 ) ;
F_101 ( V_999 , V_12 -> V_1000 ) ;
F_101 ( V_1001 , V_12 -> V_1002 ) ;
F_101 ( V_1003 , V_12 -> V_1004 ) ;
F_101 ( V_1005 , V_12 -> V_1006 ) ;
F_101 ( V_1007 , V_12 -> V_1008 ) ;
F_101 ( V_1009 , V_12 -> V_1010 ) ;
F_101 ( V_647 , V_12 -> V_1011 ) ;
F_101 ( V_479 , V_12 -> V_1012 ) ;
F_98 ( V_1013 , V_12 -> V_1014 ) ;
F_98 ( V_642 , V_12 -> V_1015 ) ;
F_98 ( V_1016 , V_12 -> V_1017 ) ;
F_98 ( V_1018 , V_12 -> V_1019 ) ;
F_98 ( V_375 , V_12 -> V_1020 ) ;
F_98 ( V_376 , V_12 -> V_1021 ) ;
F_98 ( V_645 , V_12 -> V_1022 ) ;
F_98 ( V_476 , V_12 -> V_1023 ) ;
F_98 ( V_528 , V_12 -> V_1024 ) ;
F_98 ( V_526 , V_12 -> V_1025 ) ;
F_102 ( V_651 , V_12 -> V_1026 ) ;
F_101 ( V_264 ,
V_12 -> V_1027 ) ;
F_101 ( V_256 ,
V_12 -> V_1028 ) ;
F_101 ( V_262 ,
V_12 -> V_1029 ) ;
F_101 ( V_244 ,
V_12 -> V_1030 ) ;
F_101 ( V_379 , V_12 -> V_1031 ) ;
F_387 ( V_8 , 7 , V_12 -> V_1032 ) ;
F_160 ( V_8 , V_12 -> V_1033 ) ;
F_98 ( V_650 ,
V_12 -> V_1034 ) ;
F_98 ( V_382 , V_12 -> V_1035 ) ;
F_98 ( V_381 , V_12 -> V_1036 ) ;
F_102 ( V_611 , - 1ull ) ;
F_101 ( V_612 ,
( V_29 . V_39 |
V_12 -> V_71 ) ) ;
if ( V_12 -> V_71 & V_305 )
F_101 ( V_1037 ,
V_12 -> V_1038 ) ;
F_101 ( V_624 ,
V_100 ? V_12 -> V_1039 : 0 ) ;
F_101 ( V_625 ,
V_100 ? V_12 -> V_1040 : 0 ) ;
if ( F_26 () ) {
T_2 V_601 = F_322 ( V_72 ) ;
if ( ! V_72 -> V_279 )
V_601 &= ~ V_60 ;
V_601 &= ~ V_35 ;
if ( F_57 ( V_12 ,
V_33 ) )
V_601 |= V_12 -> V_70 ;
if ( V_601 & V_35 ) {
if ( V_72 -> V_13 . V_559 )
F_13 ( V_72 -> V_13 . V_559 ) ;
V_72 -> V_13 . V_559 =
F_10 ( V_8 , V_12 -> V_1041 ) ;
if ( ! V_72 -> V_13 . V_559 )
V_601 &=
~ V_35 ;
else
F_102 ( V_654 ,
F_333 ( V_72 -> V_13 . V_559 ) ) ;
}
F_101 ( V_613 , V_601 ) ;
}
F_315 ( V_72 ) ;
V_72 -> V_1042 = 0 ;
V_601 = F_321 ( V_72 ) ;
V_601 &= ~ V_322 ;
V_601 &= ~ V_659 ;
V_601 &= ~ V_32 ;
V_601 |= V_12 -> V_69 ;
V_601 &= ~ V_31 ;
V_601 &= ~ V_332 ;
V_601 |= V_331 ;
F_101 ( V_501 , V_601 ) ;
F_111 ( V_8 ) ;
V_8 -> V_110 . V_226 &= ~ V_12 -> V_227 ;
F_98 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
F_101 ( V_137 , V_29 . V_426 ) ;
F_101 ( V_136 ,
( V_12 -> V_1043 & ~ V_142 &
~ V_317 ) |
( V_29 . V_384 & ~ V_317 ) ) ;
if ( V_12 -> V_1043 & V_318 ) {
F_102 ( V_385 , V_12 -> V_1044 ) ;
V_8 -> V_110 . V_386 = V_12 -> V_1044 ;
} else if ( V_29 . V_384 & V_318 )
F_102 ( V_385 , V_72 -> V_8 . V_110 . V_386 ) ;
F_319 ( V_72 ) ;
if ( V_12 -> V_69 & V_291 )
F_102 ( V_283 ,
V_72 -> V_13 . V_284 + V_12 -> V_282 ) ;
else
F_102 ( V_283 , V_72 -> V_13 . V_284 ) ;
if ( V_435 ) {
F_100 ( V_655 , V_72 -> V_52 ) ;
F_253 ( V_8 ) ;
}
if ( F_60 ( V_12 ) ) {
F_539 ( V_8 ) ;
F_535 ( V_8 ) ;
}
if ( V_12 -> V_1043 & V_142 )
V_8 -> V_110 . V_173 = V_12 -> V_1045 ;
else if ( V_12 -> V_1043 & V_317 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_249 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_264 ( V_8 , V_12 -> V_230 ) ;
F_98 ( V_235 , F_153 ( V_12 ) ) ;
F_262 ( V_8 , V_12 -> V_232 ) ;
F_98 ( V_463 , F_154 ( V_12 ) ) ;
F_377 ( V_8 , V_12 -> V_512 ) ;
F_248 ( V_8 ) ;
if ( V_100 ) {
F_102 ( V_494 , V_12 -> V_1046 ) ;
F_102 ( V_496 , V_12 -> V_1047 ) ;
F_102 ( V_497 , V_12 -> V_1048 ) ;
F_102 ( V_498 , V_12 -> V_1049 ) ;
}
F_379 ( V_8 , V_390 , V_12 -> V_1050 ) ;
F_379 ( V_8 , V_393 , V_12 -> V_1051 ) ;
}
static int F_466 ( struct V_7 * V_8 , bool V_1052 )
{
struct V_12 * V_12 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_89 * V_803 ;
bool V_1053 ;
if ( ! F_453 ( V_8 ) ||
! F_474 ( V_8 ) )
return 1 ;
F_163 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_436 )
F_455 ( V_72 ) ;
if ( V_12 -> V_835 == V_1052 ) {
F_450 ( V_8 ,
V_1052 ? V_1054
: V_1055 ) ;
return 1 ;
}
if ( V_12 -> V_1056 != V_649 ) {
F_450 ( V_8 , V_1057 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_463 ( V_12 -> V_268 , V_422 ) ) {
F_450 ( V_8 , V_1057 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_463 ( V_12 -> V_1041 , V_422 ) ) {
F_450 ( V_8 , V_1057 ) ;
return 1 ;
}
if ( V_12 -> V_1058 > 0 ||
V_12 -> V_1059 > 0 ||
V_12 -> V_1060 > 0 ) {
F_540 ( L_33 ,
V_483 ) ;
F_450 ( V_8 , V_1057 ) ;
return 1 ;
}
if ( ! F_193 ( V_12 -> V_69 ,
V_320 , V_321 ) ||
! F_193 ( V_12 -> V_70 ,
V_338 , V_339 ) ||
! F_193 ( V_12 -> V_71 ,
V_300 , V_301 ) ||
! F_193 ( V_12 -> V_1061 ,
V_307 , V_308 ) ||
! F_193 ( V_12 -> V_1043 ,
V_314 , V_315 ) )
{
F_450 ( V_8 , V_1057 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1062 & F_197 ) != F_197 ) ||
( ( V_12 -> V_1063 & F_198 ) != F_198 ) ) {
F_450 ( V_8 ,
V_1064 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_230 & F_197 ) != F_197 ) ||
( ( V_12 -> V_232 & F_198 ) != F_198 ) ) {
F_541 ( V_8 , V_12 ,
V_897 , V_1065 ) ;
return 1 ;
}
if ( V_12 -> V_1066 != - 1ull ) {
F_541 ( V_8 , V_12 ,
V_897 , V_1067 ) ;
return 1 ;
}
if ( V_12 -> V_1043 & V_142 ) {
V_1053 = ( V_12 -> V_1043 & V_317 ) != 0 ;
if ( ! F_542 ( V_8 , V_12 -> V_1045 ) ||
V_1053 != ! ! ( V_12 -> V_1045 & V_176 ) ||
( ( V_12 -> V_230 & V_500 ) &&
V_1053 != ! ! ( V_12 -> V_1045 & V_177 ) ) ) {
F_541 ( V_8 , V_12 ,
V_897 , V_1065 ) ;
return 1 ;
}
}
if ( V_12 -> V_1061 & V_143 ) {
V_1053 = ( V_12 -> V_1061 &
V_310 ) != 0 ;
if ( ! F_542 ( V_8 , V_12 -> V_1068 ) ||
V_1053 != ! ! ( V_12 -> V_1068 & V_176 ) ||
V_1053 != ! ! ( V_12 -> V_1068 & V_177 ) ) {
F_541 ( V_8 , V_12 ,
V_897 , V_1065 ) ;
return 1 ;
}
}
V_803 = F_440 ( V_72 ) ;
if ( ! V_803 )
return - V_433 ;
F_543 ( V_8 ) ;
V_72 -> V_13 . V_284 = F_94 ( V_283 ) ;
V_90 = F_523 () ;
V_72 -> V_89 = V_803 ;
F_149 ( V_8 ) ;
F_142 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_524 () ;
F_105 ( V_72 ) ;
V_12 -> V_835 = 1 ;
F_538 ( V_8 , V_12 ) ;
return 1 ;
}
static inline unsigned long
F_544 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_91 ( V_223 ) & V_8 -> V_110 . V_226 ) |
( V_12 -> V_230 & V_12 -> V_227 ) |
( F_91 ( V_235 ) & ~ ( V_12 -> V_227 |
V_8 -> V_110 . V_226 ) ) ;
}
static inline unsigned long
F_545 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_91 ( V_461 ) & V_8 -> V_110 . V_489 ) |
( V_12 -> V_232 & V_12 -> V_233 ) |
( F_91 ( V_463 ) & ~ ( V_12 -> V_233 |
V_8 -> V_110 . V_489 ) ) ;
}
static void F_546 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1069 ;
unsigned int V_148 ;
if ( V_8 -> V_110 . V_721 . V_1070 ) {
V_148 = V_8 -> V_110 . V_721 . V_148 ;
V_1069 = V_148 | V_706 ;
if ( F_169 ( V_148 ) ) {
V_12 -> V_1071 =
V_8 -> V_110 . V_259 ;
V_1069 |= V_263 ;
} else
V_1069 |= V_23 ;
if ( V_8 -> V_110 . V_721 . V_252 ) {
V_1069 |= V_764 ;
V_12 -> V_1072 =
V_8 -> V_110 . V_721 . V_253 ;
}
V_12 -> V_1073 = V_1069 ;
} else if ( V_8 -> V_110 . V_676 ) {
V_12 -> V_1073 =
V_670 | V_22 | V_669 ;
} else if ( V_8 -> V_110 . V_662 . V_1070 ) {
V_148 = V_8 -> V_110 . V_662 . V_148 ;
V_1069 = V_148 | V_706 ;
if ( V_8 -> V_110 . V_662 . V_664 ) {
V_1069 |= V_665 ;
V_12 -> V_1029 =
V_8 -> V_110 . V_259 ;
} else
V_1069 |= V_27 ;
V_12 -> V_1073 = V_1069 ;
}
}
static void F_547 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
V_12 -> V_230 = F_544 ( V_8 , V_12 ) ;
V_12 -> V_232 = F_545 ( V_8 , V_12 ) ;
F_386 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1032 ) ;
V_12 -> V_1050 = F_374 ( V_8 , V_390 ) ;
V_12 -> V_1051 = F_374 ( V_8 , V_393 ) ;
V_12 -> V_1033 = F_91 ( V_239 ) ;
V_12 -> V_971 = F_92 ( V_970 ) ;
V_12 -> V_972 = F_92 ( V_641 ) ;
V_12 -> V_974 = F_92 ( V_973 ) ;
V_12 -> V_976 = F_92 ( V_975 ) ;
V_12 -> V_978 = F_92 ( V_977 ) ;
V_12 -> V_980 = F_92 ( V_979 ) ;
V_12 -> V_981 = F_92 ( V_644 ) ;
V_12 -> V_982 = F_92 ( V_643 ) ;
V_12 -> V_984 = F_93 ( V_983 ) ;
V_12 -> V_986 = F_93 ( V_985 ) ;
V_12 -> V_988 = F_93 ( V_987 ) ;
V_12 -> V_990 = F_93 ( V_989 ) ;
V_12 -> V_992 = F_93 ( V_991 ) ;
V_12 -> V_994 = F_93 ( V_993 ) ;
V_12 -> V_995 = F_93 ( V_646 ) ;
V_12 -> V_996 = F_93 ( V_477 ) ;
V_12 -> V_997 = F_93 ( V_527 ) ;
V_12 -> V_998 = F_93 ( V_525 ) ;
V_12 -> V_1000 = F_93 ( V_999 ) ;
V_12 -> V_1002 = F_93 ( V_1001 ) ;
V_12 -> V_1004 = F_93 ( V_1003 ) ;
V_12 -> V_1006 = F_93 ( V_1005 ) ;
V_12 -> V_1008 = F_93 ( V_1007 ) ;
V_12 -> V_1010 = F_93 ( V_1009 ) ;
V_12 -> V_1011 = F_93 ( V_647 ) ;
V_12 -> V_1012 = F_93 ( V_479 ) ;
V_12 -> V_1014 = F_91 ( V_1013 ) ;
V_12 -> V_1015 = F_91 ( V_642 ) ;
V_12 -> V_1017 = F_91 ( V_1016 ) ;
V_12 -> V_1019 = F_91 ( V_1018 ) ;
V_12 -> V_1020 = F_91 ( V_375 ) ;
V_12 -> V_1021 = F_91 ( V_376 ) ;
V_12 -> V_1022 = F_91 ( V_645 ) ;
V_12 -> V_1023 = F_91 ( V_476 ) ;
V_12 -> V_1024 = F_91 ( V_528 ) ;
V_12 -> V_1025 = F_91 ( V_526 ) ;
V_12 -> V_1030 =
F_93 ( V_244 ) ;
V_12 -> V_1034 =
F_91 ( V_650 ) ;
if ( V_100 ) {
V_12 -> V_512 = F_94 ( V_487 ) ;
V_12 -> V_1046 = F_94 ( V_494 ) ;
V_12 -> V_1047 = F_94 ( V_496 ) ;
V_12 -> V_1048 = F_94 ( V_497 ) ;
V_12 -> V_1049 = F_94 ( V_498 ) ;
}
V_12 -> V_1043 =
( V_12 -> V_1043 & ~ V_317 ) |
( F_93 ( V_136 ) & V_317 ) ;
V_12 -> V_1026 = F_94 ( V_651 ) ;
if ( V_12 -> V_1061 & V_312 )
V_12 -> V_1044 = F_94 ( V_385 ) ;
V_12 -> V_1031 = F_93 ( V_379 ) ;
V_12 -> V_1035 = F_91 ( V_382 ) ;
V_12 -> V_1036 = F_91 ( V_381 ) ;
V_12 -> V_673 = F_6 ( V_8 ) -> V_708 ;
V_12 -> V_726 = F_91 ( V_714 ) ;
V_12 -> V_675 = F_93 ( V_870 ) ;
if ( ( V_12 -> V_675 &
( V_22 | V_257 ) ) ==
( V_22 | V_257 ) )
V_12 -> V_1074 =
F_93 ( V_705 ) ;
V_12 -> V_1073 = 0 ;
V_12 -> V_1071 = F_93 ( V_251 ) ;
V_12 -> V_821 = F_93 ( V_832 ) ;
if ( ! ( V_12 -> V_673 & V_910 ) ) {
V_12 -> V_1027 &= ~ V_22 ;
F_546 ( V_8 , V_12 ) ;
}
V_8 -> V_110 . V_763 = false ;
F_422 ( V_8 ) ;
F_421 ( V_8 ) ;
}
static void F_548 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_448 V_107 ;
if ( V_12 -> V_1061 & V_143 )
V_8 -> V_110 . V_173 = V_12 -> V_1068 ;
else if ( V_12 -> V_1061 & V_310 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_249 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_379 ( V_8 , V_390 , V_12 -> V_1042 ) ;
F_379 ( V_8 , V_393 , V_12 -> V_1075 ) ;
F_160 ( V_8 , V_1076 ) ;
F_369 ( V_8 , V_12 -> V_1062 ) ;
F_111 ( V_8 ) ;
V_8 -> V_110 . V_226 = ( V_8 -> V_132 ? V_224 : 0 ) ;
F_98 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
V_8 -> V_110 . V_489 = ~ F_91 ( V_600 ) ;
F_371 ( V_8 , V_12 -> V_1063 ) ;
if ( F_60 ( V_12 ) )
F_537 ( V_8 ) ;
F_377 ( V_8 , V_12 -> V_1077 ) ;
F_248 ( V_8 ) ;
if ( V_435 ) {
F_253 ( V_8 ) ;
}
F_101 ( V_379 , V_12 -> V_1078 ) ;
F_98 ( V_382 , V_12 -> V_1079 ) ;
F_98 ( V_381 , V_12 -> V_1080 ) ;
F_98 ( V_526 , V_12 -> V_1081 ) ;
F_98 ( V_528 , V_12 -> V_1082 ) ;
if ( V_12 -> V_1061 & V_311 ) {
F_102 ( V_385 , V_12 -> V_1083 ) ;
V_8 -> V_110 . V_386 = V_12 -> V_1083 ;
}
if ( V_12 -> V_1061 & V_147 )
F_102 ( V_159 ,
V_12 -> V_1084 ) ;
V_107 = (struct V_448 ) {
. V_117 = 0 ,
. V_119 = 0xFFFFFFFF ,
. V_114 = V_12 -> V_1085 ,
. type = 11 ,
. V_471 = 1 ,
. V_183 = 1 ,
. V_469 = 1
} ;
if ( V_12 -> V_1061 & V_310 )
V_107 . V_472 = 1 ;
else
V_107 . V_470 = 1 ;
F_242 ( V_8 , & V_107 , V_450 ) ;
V_107 = (struct V_448 ) {
. V_117 = 0 ,
. V_119 = 0xFFFFFFFF ,
. type = 3 ,
. V_471 = 1 ,
. V_183 = 1 ,
. V_470 = 1 ,
. V_469 = 1
} ;
V_107 . V_114 = V_12 -> V_1086 ;
F_242 ( V_8 , & V_107 , V_457 ) ;
V_107 . V_114 = V_12 -> V_1087 ;
F_242 ( V_8 , & V_107 , V_456 ) ;
V_107 . V_114 = V_12 -> V_1088 ;
F_242 ( V_8 , & V_107 , V_451 ) ;
V_107 . V_114 = V_12 -> V_1089 ;
V_107 . V_117 = V_12 -> V_1090 ;
F_242 ( V_8 , & V_107 , V_458 ) ;
V_107 . V_114 = V_12 -> V_1091 ;
V_107 . V_117 = V_12 -> V_1092 ;
F_242 ( V_8 , & V_107 , V_459 ) ;
V_107 = (struct V_448 ) {
. V_117 = V_12 -> V_1093 ,
. V_119 = 0x67 ,
. V_114 = V_12 -> V_1094 ,
. type = 11 ,
. V_471 = 1
} ;
F_242 ( V_8 , & V_107 , V_460 ) ;
F_387 ( V_8 , 7 , 0x400 ) ;
F_102 ( V_651 , 0 ) ;
}
static void F_167 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_549 ( V_72 -> V_13 . V_255 ) ;
F_550 ( V_8 ) ;
F_547 ( V_8 , V_12 ) ;
V_90 = F_523 () ;
V_72 -> V_89 = & V_72 -> V_807 ;
F_149 ( V_8 ) ;
F_142 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_524 () ;
F_105 ( V_72 ) ;
if ( V_805 == 0 )
F_446 ( V_72 , V_72 -> V_13 . V_800 ) ;
F_548 ( V_8 , V_12 ) ;
F_102 ( V_283 , V_72 -> V_13 . V_284 ) ;
V_72 -> V_1042 = 0 ;
if ( V_72 -> V_13 . V_559 ) {
F_13 ( V_72 -> V_13 . V_559 ) ;
V_72 -> V_13 . V_559 = 0 ;
}
if ( F_99 ( V_72 -> V_871 ) ) {
V_72 -> V_871 = 0 ;
F_450 ( V_8 , F_93 ( V_103 ) ) ;
} else
F_448 ( V_8 ) ;
if ( V_436 )
V_72 -> V_13 . V_819 = true ;
}
static void F_541 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_757 , unsigned long V_1095 )
{
F_548 ( V_8 , V_12 ) ;
V_12 -> V_673 = V_757 | V_910 ;
V_12 -> V_726 = V_1095 ;
F_448 ( V_8 ) ;
if ( V_436 )
F_6 ( V_8 ) -> V_13 . V_819 = true ;
}
static int F_551 ( struct V_7 * V_8 ,
struct V_1096 * V_1097 ,
enum V_1098 V_1099 )
{
return V_1100 ;
}
static int T_11 F_552 ( void )
{
int V_540 , V_74 , V_73 ;
F_553 ( V_140 , & V_178 ) ;
for ( V_74 = 0 ; V_74 < V_633 ; ++ V_74 )
F_554 ( V_74 , V_76 [ V_74 ] ) ;
V_604 = ( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_604 )
return - V_433 ;
V_540 = - V_433 ;
V_606 = ( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_606 )
goto V_523;
V_273 = ( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_273 )
goto V_1101;
V_271 =
( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_271 )
goto V_1102;
V_272 = ( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_272 )
goto V_1103;
V_270 =
( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_270 )
goto V_1104;
V_608 = ( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_608 )
goto V_1105;
V_610 = ( unsigned long * ) F_555 ( V_432 ) ;
if ( ! V_610 )
goto V_1106;
memset ( V_608 , 0xff , V_422 ) ;
memset ( V_610 , 0xff , V_422 ) ;
for ( V_74 = 0 ; V_74 < V_844 ; V_74 ++ ) {
F_556 ( V_842 [ V_74 ] , V_610 ) ;
F_556 ( V_842 [ V_74 ] , V_608 ) ;
}
for ( V_74 = 0 ; V_74 < V_847 ; V_74 ++ )
F_556 ( V_845 [ V_74 ] , V_608 ) ;
memset ( V_604 , 0xff , V_422 ) ;
F_556 ( 0x80 , V_604 ) ;
memset ( V_606 , 0xff , V_422 ) ;
memset ( V_273 , 0xff , V_422 ) ;
memset ( V_272 , 0xff , V_422 ) ;
F_557 ( 0 , V_567 ) ;
V_540 = F_558 ( & V_1107 , sizeof( struct V_6 ) ,
F_559 ( struct V_6 ) , V_1108 ) ;
if ( V_540 )
goto V_1109;
#ifdef F_560
F_561 ( V_1110 ,
F_77 ) ;
#endif
F_304 ( V_203 , false ) ;
F_304 ( V_205 , false ) ;
F_304 ( V_206 , true ) ;
F_304 ( V_378 , false ) ;
F_304 ( V_220 , false ) ;
F_304 ( V_380 , false ) ;
memcpy ( V_271 ,
V_273 , V_422 ) ;
memcpy ( V_270 ,
V_272 , V_422 ) ;
if ( V_442 ) {
for ( V_73 = 0x800 ; V_73 <= 0x8ff ; V_73 ++ )
F_306 ( V_73 ) ;
F_305 ( 0x802 ) ;
F_305 ( 0x839 ) ;
F_307 ( 0x808 ) ;
F_307 ( 0x80b ) ;
F_307 ( 0x83f ) ;
}
if ( V_100 ) {
F_562 ( 0ull ,
( V_438 ) ? V_1111 : 0ull ,
( V_438 ) ? V_1112 : 0ull ,
0ull , V_1113 ) ;
F_323 () ;
F_563 () ;
} else
F_564 () ;
return 0 ;
V_1109:
F_565 ( ( unsigned long ) V_610 ) ;
V_1106:
F_565 ( ( unsigned long ) V_608 ) ;
V_1105:
F_565 ( ( unsigned long ) V_270 ) ;
V_1104:
F_565 ( ( unsigned long ) V_272 ) ;
V_1103:
F_565 ( ( unsigned long ) V_271 ) ;
V_1102:
F_565 ( ( unsigned long ) V_273 ) ;
V_1101:
F_565 ( ( unsigned long ) V_606 ) ;
V_523:
F_565 ( ( unsigned long ) V_604 ) ;
return V_540 ;
}
static void T_12 F_566 ( void )
{
F_565 ( ( unsigned long ) V_271 ) ;
F_565 ( ( unsigned long ) V_270 ) ;
F_565 ( ( unsigned long ) V_273 ) ;
F_565 ( ( unsigned long ) V_272 ) ;
F_565 ( ( unsigned long ) V_606 ) ;
F_565 ( ( unsigned long ) V_604 ) ;
F_565 ( ( unsigned long ) V_610 ) ;
F_565 ( ( unsigned long ) V_608 ) ;
#ifdef F_560
F_561 ( V_1110 , NULL ) ;
F_567 () ;
#endif
F_568 () ;
}
