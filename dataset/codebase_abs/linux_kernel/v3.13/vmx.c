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
static int F_166 ( struct V_7 * V_8 , unsigned V_148 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( ! ( V_12 -> V_133 & ( 1u << V_148 ) ) )
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
if ( ! V_254 && F_112 ( V_8 ) &&
F_166 ( V_8 , V_148 ) )
return;
if ( V_252 ) {
F_101 ( V_255 , V_253 ) ;
V_19 |= V_256 ;
}
if ( V_72 -> V_130 . V_131 ) {
int V_257 = 0 ;
if ( F_169 ( V_148 ) )
V_257 = V_8 -> V_110 . V_258 ;
if ( F_170 ( V_8 , V_148 , V_257 ) != V_259 )
F_144 ( V_260 , V_8 ) ;
return;
}
if ( F_169 ( V_148 ) ) {
F_101 ( V_261 ,
V_72 -> V_8 . V_110 . V_258 ) ;
V_19 |= V_262 ;
} else
V_19 |= V_23 ;
F_101 ( V_263 , V_19 ) ;
}
static bool F_171 ( void )
{
return F_50 () ;
}
static bool F_172 ( void )
{
return F_51 () && V_100 ;
}
static void F_173 ( struct V_6 * V_72 , int V_264 , int V_265 )
{
struct V_85 V_266 ;
V_266 = V_72 -> V_77 [ V_265 ] ;
V_72 -> V_77 [ V_265 ] = V_72 -> V_77 [ V_264 ] ;
V_72 -> V_77 [ V_264 ] = V_266 ;
}
static void F_174 ( struct V_7 * V_8 )
{
unsigned long * V_267 ;
if ( F_25 ( V_8 -> V_17 ) && F_175 ( V_8 -> V_110 . V_268 ) ) {
if ( F_129 ( V_8 ) )
V_267 = V_269 ;
else
V_267 = V_270 ;
} else {
if ( F_129 ( V_8 ) )
V_267 = V_271 ;
else
V_267 = V_272 ;
}
F_102 ( V_273 , F_67 ( V_267 ) ) ;
}
static void F_176 ( struct V_6 * V_72 )
{
int V_209 , V_78 ;
V_209 = 0 ;
#ifdef F_95
if ( F_129 ( & V_72 -> V_8 ) ) {
V_78 = F_62 ( V_72 , V_274 ) ;
if ( V_78 >= 0 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_275 ) ;
if ( V_78 >= 0 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_276 ) ;
if ( V_78 >= 0 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_277 ) ;
if ( V_78 >= 0 && V_72 -> V_278 )
F_173 ( V_72 , V_78 , V_209 ++ ) ;
V_78 = F_62 ( V_72 , V_279 ) ;
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
T_3 V_280 , V_281 ;
F_178 ( V_280 ) ;
V_281 = F_94 ( V_282 ) ;
return V_280 + V_281 ;
}
T_3 F_179 ( struct V_7 * V_8 , T_3 V_280 )
{
T_3 V_281 ;
V_281 = F_112 ( V_8 ) ?
F_6 ( V_8 ) -> V_13 . V_283 :
F_94 ( V_282 ) ;
return V_280 + V_281 ;
}
static void F_180 ( struct V_7 * V_8 , T_2 V_284 , bool V_285 )
{
if ( ! V_285 )
return;
if ( V_284 > V_286 ) {
V_8 -> V_110 . V_287 = 1 ;
V_8 -> V_110 . V_288 = 1 ;
} else
F_181 ( 1 , L_6 ) ;
}
static T_3 F_182 ( struct V_7 * V_8 )
{
return F_94 ( V_282 ) ;
}
static void F_183 ( struct V_7 * V_8 , T_3 V_289 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 ;
F_6 ( V_8 ) -> V_13 . V_283 = V_289 ;
V_12 = F_9 ( V_8 ) ;
F_102 ( V_282 , V_289 +
( F_57 ( V_12 , V_290 ) ?
V_12 -> V_281 : 0 ) ) ;
} else {
F_184 ( V_8 -> V_291 ,
F_94 ( V_282 ) , V_289 ) ;
F_102 ( V_282 , V_289 ) ;
}
}
static void F_185 ( struct V_7 * V_8 , T_10 V_292 , bool V_150 )
{
T_3 V_289 = F_94 ( V_282 ) ;
F_102 ( V_282 , V_289 + V_292 ) ;
if ( F_112 ( V_8 ) ) {
F_6 ( V_8 ) -> V_13 . V_283 += V_292 ;
} else
F_184 ( V_8 -> V_291 , V_289 ,
V_289 + V_292 ) ;
}
static T_3 F_186 ( struct V_7 * V_8 , T_3 V_293 )
{
return V_293 - F_187 () ;
}
static bool F_188 ( struct V_7 * V_8 )
{
struct V_294 * V_295 = F_189 ( V_8 , 1 , 0 ) ;
return V_295 && ( V_295 -> V_296 & ( 1 << ( V_297 & 31 ) ) ) ;
}
static inline bool F_190 ( struct V_7 * V_8 )
{
return V_13 && F_188 ( V_8 ) ;
}
static T_11 void F_191 ( void )
{
F_192 ( V_298 ,
V_299 , V_300 ) ;
V_299 |= V_301 ;
V_300 &= V_302 |
V_303 | V_62 |
V_304 ;
V_300 |= V_301 ;
F_192 ( V_305 ,
V_306 , V_307 ) ;
V_306 = V_308 ;
V_307 &=
#ifdef F_95
V_309 |
#endif
V_310 | V_311 |
V_312 ;
if ( ! ( V_300 & V_304 ) ||
! ( V_307 & V_312 ) ) {
V_307 &= ~ V_312 ;
V_300 &= ~ V_304 ;
}
V_307 |= ( V_308 |
V_143 | V_313 ) ;
F_192 ( V_314 ,
V_315 , V_316 ) ;
V_315 = V_317 ;
V_316 &=
#ifdef F_95
V_318 |
#endif
V_319 ;
V_316 |= ( V_317 |
V_142 ) ;
F_192 ( V_320 ,
V_321 , V_322 ) ;
V_321 = 0 ;
V_322 &=
V_323 |
V_324 | V_290 |
V_325 | V_326 |
V_327 | V_328 |
V_329 |
#ifdef F_95
V_330 | V_331 |
#endif
V_332 | V_333 |
V_334 | V_335 |
V_336 | V_337 |
V_338 |
V_33 ;
V_322 |= V_31 ;
F_192 ( V_339 ,
V_340 , V_341 ) ;
V_340 = 0 ;
V_341 &=
V_35 |
V_56 |
V_63 ;
if ( V_100 ) {
V_341 |= V_55 ;
V_342 = V_48 |
V_45 | V_46 |
V_343 ;
V_342 &= V_41 . V_42 ;
V_342 |= V_51 |
V_50 ;
} else
V_342 = 0 ;
F_192 ( V_65 , V_344 , V_345 ) ;
V_344 &= V_346 |
V_347 ;
V_345 = 0 ;
}
static inline bool F_193 ( T_2 V_3 , T_2 V_348 , T_2 V_349 )
{
return ( ( V_3 & V_349 ) | V_348 ) == V_3 ;
}
static inline T_3 F_194 ( T_2 V_348 , T_2 V_349 )
{
return V_348 | ( ( T_3 ) V_349 << 32 ) ;
}
static int F_195 ( struct V_7 * V_8 , T_2 V_350 , T_3 * V_351 )
{
if ( ! F_190 ( V_8 ) && V_350 >= V_352 &&
V_350 <= V_353 ) {
F_196 ( V_8 , V_354 , 0 ) ;
return 1 ;
}
switch ( V_350 ) {
case V_355 :
if ( F_190 ( V_8 ) ) {
* V_351 = F_6 ( V_8 ) -> V_13 . V_356 ;
break;
}
return 0 ;
case V_352 :
* V_351 = V_357 |
( ( T_3 ) V_358 << V_359 ) |
( V_360 << V_361 ) ;
break;
case V_362 :
case V_298 :
* V_351 = F_194 ( V_299 ,
V_300 ) ;
break;
case V_363 :
case V_320 :
* V_351 = F_194 ( V_321 ,
V_322 ) ;
break;
case V_364 :
case V_305 :
* V_351 = F_194 ( V_306 ,
V_307 ) ;
break;
case V_353 :
case V_314 :
* V_351 = F_194 ( V_315 ,
V_316 ) ;
break;
case V_65 :
* V_351 = F_194 ( V_344 ,
V_345 ) ;
break;
#define F_197 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_198 X86_CR4_VMXE
case V_365 :
* V_351 = F_197 ;
break;
case V_366 :
* V_351 = - 1ULL ;
break;
case V_367 :
* V_351 = F_198 ;
break;
case V_368 :
* V_351 = - 1ULL ;
break;
case V_369 :
* V_351 = 0x1f ;
break;
case V_339 :
* V_351 = F_194 ( V_340 ,
V_341 ) ;
break;
case V_370 :
* V_351 = V_342 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_199 ( struct V_7 * V_8 , struct V_371 * V_372 )
{
T_2 V_350 = V_372 -> V_78 ;
T_3 V_179 = V_372 -> V_179 ;
bool V_373 = V_372 -> V_374 ;
if ( ! F_190 ( V_8 ) )
return 0 ;
if ( V_350 == V_355 ) {
if ( ! V_373 &&
F_6 ( V_8 ) -> V_13 . V_356
& V_375 )
return 0 ;
F_6 ( V_8 ) -> V_13 . V_356 = V_179 ;
return 1 ;
}
return 0 ;
}
static int F_200 ( struct V_7 * V_8 , T_2 V_350 , T_3 * V_351 )
{
T_3 V_179 ;
struct V_85 * V_73 ;
if ( ! V_351 ) {
F_68 ( V_88 L_7 ) ;
return - V_376 ;
}
switch ( V_350 ) {
#ifdef F_95
case V_203 :
V_179 = F_91 ( V_377 ) ;
break;
case V_205 :
V_179 = F_91 ( V_378 ) ;
break;
case V_206 :
F_139 ( F_6 ( V_8 ) ) ;
V_179 = F_6 ( V_8 ) -> V_208 ;
break;
#endif
case V_140 :
return F_201 ( V_8 , V_350 , V_351 ) ;
case V_379 :
V_179 = F_177 () ;
break;
case V_380 :
V_179 = F_93 ( V_381 ) ;
break;
case V_382 :
V_179 = F_91 ( V_383 ) ;
break;
case V_220 :
V_179 = F_91 ( V_384 ) ;
break;
case V_277 :
if ( ! F_6 ( V_8 ) -> V_278 )
return 1 ;
default:
if ( F_195 ( V_8 , V_350 , V_351 ) )
return 0 ;
V_73 = F_65 ( F_6 ( V_8 ) , V_350 ) ;
if ( V_73 ) {
V_179 = V_73 -> V_179 ;
break;
}
return F_201 ( V_8 , V_350 , V_351 ) ;
}
* V_351 = V_179 ;
return 0 ;
}
static int F_202 ( struct V_7 * V_8 , struct V_371 * V_372 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 ;
int V_108 = 0 ;
T_2 V_350 = V_372 -> V_78 ;
T_3 V_179 = V_372 -> V_179 ;
switch ( V_350 ) {
case V_140 :
V_108 = F_203 ( V_8 , V_372 ) ;
break;
#ifdef F_95
case V_203 :
F_105 ( V_72 ) ;
F_98 ( V_377 , V_179 ) ;
break;
case V_205 :
F_105 ( V_72 ) ;
F_98 ( V_378 , V_179 ) ;
break;
case V_206 :
F_139 ( V_72 ) ;
V_72 -> V_208 = V_179 ;
break;
#endif
case V_380 :
F_101 ( V_381 , V_179 ) ;
break;
case V_382 :
F_98 ( V_383 , V_179 ) ;
break;
case V_220 :
F_98 ( V_384 , V_179 ) ;
break;
case V_379 :
F_204 ( V_8 , V_372 ) ;
break;
case V_385 :
if ( V_29 . V_386 & V_319 ) {
F_102 ( V_387 , V_179 ) ;
V_8 -> V_110 . V_388 = V_179 ;
break;
}
V_108 = F_203 ( V_8 , V_372 ) ;
break;
case V_389 :
V_108 = F_203 ( V_8 , V_372 ) ;
break;
case V_277 :
if ( ! V_72 -> V_278 )
return 1 ;
if ( ( V_179 >> 32 ) != 0 )
return 1 ;
default:
if ( F_199 ( V_8 , V_372 ) )
break;
V_73 = F_65 ( V_72 , V_350 ) ;
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
V_108 = F_203 ( V_8 , V_372 ) ;
}
return V_108 ;
}
static void F_205 ( struct V_7 * V_8 , enum V_390 V_391 )
{
F_159 ( V_391 , ( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
switch ( V_391 ) {
case V_392 :
V_8 -> V_110 . V_393 [ V_392 ] = F_91 ( V_394 ) ;
break;
case V_395 :
V_8 -> V_110 . V_393 [ V_395 ] = F_91 ( V_396 ) ;
break;
case V_397 :
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
F_55 ( V_355 , V_73 ) ;
if ( V_73 & V_375 ) {
if ( ! ( V_73 & V_398 )
&& F_210 () )
return 1 ;
if ( ! ( V_73 & V_399 )
&& ( V_73 & V_398 )
&& ! F_210 () ) {
F_68 ( V_162 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_73 & V_399 )
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
static int F_211 ( void * V_400 )
{
int V_90 = F_78 () ;
T_3 V_87 = F_67 ( F_81 ( V_213 , V_90 ) ) ;
T_3 V_401 , V_402 ;
if ( F_212 () & V_403 )
return - V_404 ;
F_213 ( & F_81 ( V_217 , V_90 ) ) ;
F_71 ( V_90 ) ;
F_55 ( V_355 , V_401 ) ;
V_402 = V_375 ;
V_402 |= V_399 ;
if ( F_210 () )
V_402 |= V_398 ;
if ( ( V_401 & V_402 ) != V_402 ) {
F_130 ( V_355 , V_401 | V_402 ) ;
}
F_214 ( F_212 () | V_403 ) ;
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
struct V_89 * V_93 , * V_405 ;
F_217 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_80 ( V_93 ) ;
}
static void F_150 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_218 ( void * V_400 )
{
if ( V_214 ) {
F_216 () ;
F_150 () ;
}
F_214 ( F_212 () & ~ V_403 ) ;
}
static T_11 int F_219 ( T_2 V_406 , T_2 V_407 ,
T_2 V_73 , T_2 * V_408 )
{
T_2 V_409 , V_410 ;
T_2 V_411 = V_406 | V_407 ;
F_192 ( V_73 , V_409 , V_410 ) ;
V_411 &= V_410 ;
V_411 |= V_409 ;
if ( V_406 & ~ V_411 )
return - V_412 ;
* V_408 = V_411 ;
return 0 ;
}
static T_11 bool F_220 ( T_2 V_73 , T_2 V_411 )
{
T_2 V_409 , V_410 ;
F_192 ( V_73 , V_409 , V_410 ) ;
return V_410 & V_411 ;
}
static T_11 int F_221 ( struct V_29 * V_413 )
{
T_2 V_409 , V_410 ;
T_2 V_414 , V_415 , V_416 , V_417 ;
T_2 V_418 = 0 ;
T_2 V_419 = 0 ;
T_2 V_420 = 0 ;
T_2 V_421 = 0 ;
T_2 V_422 = 0 ;
V_414 = V_325 |
#ifdef F_95
V_330 |
V_331 |
#endif
V_328 |
V_329 |
V_334 |
V_332 |
V_290 |
V_327 |
V_335 |
V_326 |
V_336 ;
V_415 = V_32 |
V_31 |
V_33 ;
if ( F_219 ( V_414 , V_415 , V_320 ,
& V_419 ) < 0 )
return - V_412 ;
#ifdef F_95
if ( ( V_419 & V_32 ) )
V_419 &= ~ V_330 &
~ V_331 ;
#endif
if ( V_419 & V_33 ) {
V_416 = 0 ;
V_417 = V_35 |
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
if ( F_219 ( V_416 , V_417 ,
V_339 ,
& V_420 ) < 0 )
return - V_412 ;
}
#ifndef F_95
if ( ! ( V_420 &
V_35 ) )
V_419 &= ~ V_32 ;
#endif
if ( ! ( V_419 & V_32 ) )
V_420 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_420 & V_55 ) {
V_419 &= ~ ( V_328 |
V_329 |
V_326 ) ;
F_192 ( V_370 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_414 = 0 ;
#ifdef F_95
V_414 |= V_309 ;
#endif
V_415 = V_311 | V_310 |
V_423 ;
if ( F_219 ( V_414 , V_415 , V_305 ,
& V_421 ) < 0 )
return - V_412 ;
V_414 = V_302 | V_303 ;
V_415 = V_62 | V_40 ;
if ( F_219 ( V_414 , V_415 , V_298 ,
& V_418 ) < 0 )
return - V_412 ;
if ( ! ( V_420 &
V_38 ) ||
! ( V_421 & V_423 ) )
V_418 &= ~ V_40 ;
V_414 = 0 ;
V_415 = V_319 ;
if ( F_219 ( V_414 , V_415 , V_314 ,
& V_422 ) < 0 )
return - V_412 ;
F_192 ( V_352 , V_409 , V_410 ) ;
if ( ( V_410 & 0x1fff ) > V_424 )
return - V_412 ;
#ifdef F_95
if ( V_410 & ( 1u << 16 ) )
return - V_412 ;
#endif
if ( ( ( V_410 >> 18 ) & 15 ) != 6 )
return - V_412 ;
V_413 -> V_425 = V_410 & 0x1fff ;
V_413 -> V_426 = F_222 ( V_29 . V_425 ) ;
V_413 -> V_427 = V_409 ;
V_413 -> V_39 = V_418 ;
V_413 -> V_30 = V_419 ;
V_413 -> V_34 = V_420 ;
V_413 -> V_428 = V_421 ;
V_413 -> V_386 = V_422 ;
V_141 =
F_220 ( V_314 ,
V_142 )
&& F_220 ( V_305 ,
V_143 ) ;
V_145 =
F_220 ( V_314 ,
V_146 )
&& F_220 ( V_305 ,
V_147 ) ;
if ( V_145 && V_429 . V_430 == 0x6 ) {
switch ( V_429 . V_431 ) {
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
int V_432 = F_224 ( V_90 ) ;
struct V_15 * V_433 ;
struct V_86 * V_86 ;
V_433 = F_225 ( V_432 , V_434 , V_29 . V_426 ) ;
if ( ! V_433 )
return NULL ;
V_86 = F_226 ( V_433 ) ;
memset ( V_86 , 0 , V_29 . V_425 ) ;
V_86 -> V_427 = V_29 . V_427 ;
return V_86 ;
}
static struct V_86 * F_227 ( void )
{
return F_223 ( F_78 () ) ;
}
static void F_228 ( struct V_86 * V_86 )
{
F_229 ( ( unsigned long ) V_86 , V_29 . V_426 ) ;
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
return - V_435 ;
}
F_81 ( V_213 , V_90 ) = V_86 ;
}
return 0 ;
}
static T_11 int F_234 ( void )
{
if ( F_221 ( & V_29 ) < 0 )
return - V_412 ;
if ( F_235 ( V_436 ) )
F_236 ( V_174 ) ;
if ( ! F_49 () )
V_437 = 0 ;
if ( ! F_54 () )
V_438 = 0 ;
if ( ! F_45 () ||
! F_39 () ) {
V_100 = 0 ;
V_439 = 0 ;
V_440 = 0 ;
}
if ( ! F_40 () )
V_440 = 0 ;
if ( ! F_46 () )
V_439 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_441 -> V_442 = NULL ;
if ( V_100 && ! F_37 () )
F_237 () ;
if ( ! F_47 () )
V_443 = 0 ;
if ( ! F_32 () )
V_444 = 0 ;
if ( V_444 )
V_441 -> V_442 = NULL ;
else {
V_441 -> V_445 = NULL ;
V_441 -> V_446 = NULL ;
V_441 -> V_447 = V_448 ;
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
return V_449 && ! F_240 ( V_8 ) ;
}
static void F_241 ( struct V_7 * V_8 , int V_107 ,
struct V_450 * V_451 )
{
if ( ! V_449 ) {
if ( V_107 == V_452 || V_107 == V_453 )
V_451 -> V_114 &= ~ V_454 ;
V_451 -> V_455 = V_451 -> V_114 & V_454 ;
V_451 -> V_183 = 1 ;
}
F_242 ( V_8 , V_451 , V_107 ) ;
}
static void F_243 ( struct V_7 * V_8 )
{
unsigned long V_456 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_458 ] , V_458 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_459 ] , V_459 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_460 ] , V_460 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_461 ] , V_461 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_453 ] , V_453 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_452 ] , V_452 ) ;
V_72 -> V_130 . V_131 = 0 ;
F_105 ( V_72 ) ;
F_242 ( V_8 , & V_72 -> V_130 . V_457 [ V_462 ] , V_462 ) ;
V_456 = F_91 ( V_239 ) ;
V_456 &= V_240 ;
V_456 |= V_72 -> V_130 . V_237 & ~ V_240 ;
F_98 ( V_239 , V_456 ) ;
F_98 ( V_463 , ( F_91 ( V_463 ) & ~ V_464 ) |
( F_91 ( V_465 ) & V_464 ) ) ;
F_111 ( V_8 ) ;
F_241 ( V_8 , V_452 , & V_72 -> V_130 . V_457 [ V_452 ] ) ;
F_241 ( V_8 , V_453 , & V_72 -> V_130 . V_457 [ V_453 ] ) ;
F_241 ( V_8 , V_458 , & V_72 -> V_130 . V_457 [ V_458 ] ) ;
F_241 ( V_8 , V_459 , & V_72 -> V_130 . V_457 [ V_459 ] ) ;
F_241 ( V_8 , V_460 , & V_72 -> V_130 . V_457 [ V_460 ] ) ;
F_241 ( V_8 , V_461 , & V_72 -> V_130 . V_457 [ V_461 ] ) ;
F_159 ( V_466 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_467 = 0 ;
}
static void F_245 ( int V_107 , struct V_450 * V_451 )
{
const struct V_468 * V_469 = & V_116 [ V_107 ] ;
struct V_450 V_470 = * V_451 ;
V_470 . V_455 = 0x3 ;
if ( V_107 == V_452 )
V_470 . type = 0x3 ;
if ( ! V_449 ) {
V_470 . V_114 = V_470 . V_117 >> 4 ;
V_470 . V_117 = V_470 . V_117 & 0xffff0 ;
V_470 . V_119 = 0xffff ;
V_470 . V_471 = 0 ;
V_470 . V_472 = 0 ;
V_470 . V_473 = 1 ;
V_470 . V_183 = 1 ;
V_470 . V_474 = 0 ;
V_470 . V_475 = 0 ;
V_470 . type = 0x3 ;
V_470 . V_476 = 0 ;
if ( V_451 -> V_117 & 0xf )
F_117 ( V_162 L_12
L_13
L_14 , V_107 ) ;
}
F_100 ( V_469 -> V_114 , V_470 . V_114 ) ;
F_101 ( V_469 -> V_117 , V_470 . V_117 ) ;
F_101 ( V_469 -> V_119 , V_470 . V_119 ) ;
F_101 ( V_469 -> V_123 , F_246 ( & V_470 ) ) ;
}
static void F_247 ( struct V_7 * V_8 )
{
unsigned long V_456 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_462 ] , V_462 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_458 ] , V_458 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_459 ] , V_459 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_460 ] , V_460 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_461 ] , V_461 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_453 ] , V_453 ) ;
F_244 ( V_8 , & V_72 -> V_130 . V_457 [ V_452 ] , V_452 ) ;
V_72 -> V_130 . V_131 = 1 ;
if ( ! V_8 -> V_17 -> V_110 . V_477 )
F_117 ( V_162 L_15
L_16 ) ;
F_105 ( V_72 ) ;
F_98 ( V_478 , V_8 -> V_17 -> V_110 . V_477 ) ;
F_101 ( V_479 , V_480 - 1 ) ;
F_101 ( V_481 , 0x008b ) ;
V_456 = F_91 ( V_239 ) ;
V_72 -> V_130 . V_237 = V_456 ;
V_456 |= V_241 | V_242 ;
F_98 ( V_239 , V_456 ) ;
F_98 ( V_463 , F_91 ( V_463 ) | V_464 ) ;
F_111 ( V_8 ) ;
F_245 ( V_453 , & V_72 -> V_130 . V_457 [ V_453 ] ) ;
F_245 ( V_452 , & V_72 -> V_130 . V_457 [ V_452 ] ) ;
F_245 ( V_458 , & V_72 -> V_130 . V_457 [ V_458 ] ) ;
F_245 ( V_459 , & V_72 -> V_130 . V_457 [ V_459 ] ) ;
F_245 ( V_461 , & V_72 -> V_130 . V_457 [ V_461 ] ) ;
F_245 ( V_460 , & V_72 -> V_130 . V_457 [ V_460 ] ) ;
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
V_318 ) ;
V_73 -> V_179 = V_173 ;
} else {
F_101 ( V_136 ,
F_93 ( V_136 ) &
~ V_318 ) ;
V_73 -> V_179 = V_173 & ~ V_177 ;
}
F_176 ( V_72 ) ;
}
static void F_250 ( struct V_7 * V_8 )
{
T_2 V_482 ;
F_105 ( F_6 ( V_8 ) ) ;
V_482 = F_93 ( V_481 ) ;
if ( ( V_482 & V_483 ) != V_484 ) {
F_251 ( L_17 ,
V_485 ) ;
F_101 ( V_481 ,
( V_482 & ~ V_483 )
| V_484 ) ;
}
F_249 ( V_8 , V_8 -> V_110 . V_173 | V_176 ) ;
}
static void F_252 ( struct V_7 * V_8 )
{
F_101 ( V_136 ,
F_93 ( V_136 )
& ~ V_318 ) ;
F_249 ( V_8 , V_8 -> V_110 . V_173 & ~ V_176 ) ;
}
static void F_253 ( struct V_7 * V_8 )
{
F_88 ( F_6 ( V_8 ) ) ;
if ( V_100 ) {
if ( ! F_254 ( V_8 -> V_110 . V_486 . V_487 ) )
return;
F_90 ( F_255 ( V_8 -> V_110 . V_486 . V_487 ) ) ;
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
V_8 -> V_110 . V_488 = F_91 ( V_489 ) ;
F_159 ( V_490 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
}
static void F_258 ( struct V_7 * V_8 )
{
T_9 V_491 = V_8 -> V_110 . V_491 ;
V_8 -> V_110 . V_492 &= ~ V_491 ;
V_8 -> V_110 . V_492 |= F_91 ( V_463 ) & V_491 ;
}
static void F_259 ( struct V_7 * V_8 )
{
struct V_493 * V_486 = V_8 -> V_110 . V_494 ;
if ( ! F_158 ( V_397 ,
( unsigned long * ) & V_8 -> V_110 . V_495 ) )
return;
if ( F_257 ( V_8 ) && F_260 ( V_8 ) && ! F_129 ( V_8 ) ) {
F_102 ( V_496 , V_486 -> V_497 [ 0 ] ) ;
F_102 ( V_498 , V_486 -> V_497 [ 1 ] ) ;
F_102 ( V_499 , V_486 -> V_497 [ 2 ] ) ;
F_102 ( V_500 , V_486 -> V_497 [ 3 ] ) ;
}
}
static void F_206 ( struct V_7 * V_8 )
{
struct V_493 * V_486 = V_8 -> V_110 . V_494 ;
if ( F_257 ( V_8 ) && F_260 ( V_8 ) && ! F_129 ( V_8 ) ) {
V_486 -> V_497 [ 0 ] = F_94 ( V_496 ) ;
V_486 -> V_497 [ 1 ] = F_94 ( V_498 ) ;
V_486 -> V_497 [ 2 ] = F_94 ( V_499 ) ;
V_486 -> V_497 [ 3 ] = F_94 ( V_500 ) ;
}
F_159 ( V_397 ,
( unsigned long * ) & V_8 -> V_110 . V_111 ) ;
F_159 ( V_397 ,
( unsigned long * ) & V_8 -> V_110 . V_495 ) ;
}
static void F_261 ( unsigned long * V_501 ,
unsigned long V_222 ,
struct V_7 * V_8 )
{
if ( ! F_158 ( V_490 , ( T_9 * ) & V_8 -> V_110 . V_111 ) )
F_256 ( V_8 ) ;
if ( ! ( V_222 & V_502 ) ) {
F_101 ( V_503 ,
F_93 ( V_503 ) |
( V_328 |
V_329 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_262 ( V_8 , F_263 ( V_8 ) ) ;
} else if ( ! F_257 ( V_8 ) ) {
F_101 ( V_503 ,
F_93 ( V_503 ) &
~ ( V_328 |
V_329 ) ) ;
V_8 -> V_110 . V_222 = V_222 ;
F_262 ( V_8 , F_263 ( V_8 ) ) ;
}
if ( ! ( V_222 & V_504 ) )
* V_501 &= ~ V_504 ;
}
static void F_264 ( struct V_7 * V_8 , unsigned long V_222 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_501 ;
V_501 = ( V_222 & ~ V_505 ) ;
if ( V_439 )
V_501 |= V_506 ;
else {
V_501 |= V_507 ;
if ( V_72 -> V_130 . V_131 && ( V_222 & V_508 ) )
F_243 ( V_8 ) ;
if ( ! V_72 -> V_130 . V_131 && ! ( V_222 & V_508 ) )
F_247 ( V_8 ) ;
}
#ifdef F_95
if ( V_8 -> V_110 . V_173 & V_177 ) {
if ( ! F_257 ( V_8 ) && ( V_222 & V_502 ) )
F_250 ( V_8 ) ;
if ( F_257 ( V_8 ) && ! ( V_222 & V_502 ) )
F_252 ( V_8 ) ;
}
#endif
if ( V_100 )
F_261 ( & V_501 , V_222 , V_8 ) ;
if ( ! V_8 -> V_132 )
V_501 |= V_224 | V_225 ;
F_98 ( V_235 , V_222 ) ;
F_98 ( V_223 , V_501 ) ;
V_8 -> V_110 . V_222 = V_222 ;
V_72 -> F_239 = F_239 ( V_8 ) ;
}
static T_3 F_255 ( unsigned long V_487 )
{
T_3 V_83 ;
V_83 = V_509 |
V_510 << V_511 ;
if ( V_440 )
V_83 |= V_512 ;
V_83 |= ( V_487 & V_513 ) ;
return V_83 ;
}
static void F_265 ( struct V_7 * V_8 , unsigned long V_488 )
{
unsigned long V_514 ;
T_3 V_83 ;
V_514 = V_488 ;
if ( V_100 ) {
V_83 = F_255 ( V_488 ) ;
F_102 ( V_515 , V_83 ) ;
if ( F_257 ( V_8 ) || F_112 ( V_8 ) )
V_514 = F_266 ( V_8 ) ;
else
V_514 = V_8 -> V_17 -> V_110 . V_516 ;
F_259 ( V_8 ) ;
}
F_253 ( V_8 ) ;
F_98 ( V_489 , V_514 ) ;
}
static int F_262 ( struct V_7 * V_8 , unsigned long V_492 )
{
unsigned long V_517 = V_492 | ( F_6 ( V_8 ) -> V_130 . V_131 ?
V_518 : V_519 ) ;
if ( V_492 & V_403 ) {
if ( ! F_190 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_520 &&
( ( V_492 & F_198 ) != F_198 ) )
return 1 ;
V_8 -> V_110 . V_492 = V_492 ;
if ( V_100 ) {
if ( ! F_257 ( V_8 ) ) {
V_517 &= ~ V_521 ;
V_517 |= V_522 ;
V_517 &= ~ V_523 ;
} else if ( ! ( V_492 & V_521 ) ) {
V_517 &= ~ V_521 ;
}
}
F_98 ( V_465 , V_492 ) ;
F_98 ( V_463 , V_517 ) ;
return 0 ;
}
static void F_244 ( struct V_7 * V_8 ,
struct V_450 * V_470 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_121 ;
if ( V_72 -> V_130 . V_131 && V_107 != V_524 ) {
* V_470 = V_72 -> V_130 . V_457 [ V_107 ] ;
if ( V_107 == V_462
|| V_470 -> V_114 == F_107 ( V_72 , V_107 ) )
return;
V_470 -> V_117 = F_108 ( V_72 , V_107 ) ;
V_470 -> V_114 = F_107 ( V_72 , V_107 ) ;
return;
}
V_470 -> V_117 = F_108 ( V_72 , V_107 ) ;
V_470 -> V_119 = F_109 ( V_72 , V_107 ) ;
V_470 -> V_114 = F_107 ( V_72 , V_107 ) ;
V_121 = F_110 ( V_72 , V_107 ) ;
V_470 -> V_475 = ( V_121 >> 16 ) & 1 ;
V_470 -> type = V_121 & 15 ;
V_470 -> V_183 = ( V_121 >> 4 ) & 1 ;
V_470 -> V_455 = ( V_121 >> 5 ) & 3 ;
V_470 -> V_473 = ! V_470 -> V_475 ;
V_470 -> V_476 = ( V_121 >> 12 ) & 1 ;
V_470 -> V_474 = ( V_121 >> 13 ) & 1 ;
V_470 -> V_472 = ( V_121 >> 14 ) & 1 ;
V_470 -> V_471 = ( V_121 >> 15 ) & 1 ;
}
static T_3 F_267 ( struct V_7 * V_8 , int V_107 )
{
struct V_450 V_183 ;
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
if ( ! F_158 ( V_466 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ) {
F_159 ( V_466 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
V_72 -> V_467 = F_107 ( V_72 , V_452 ) & 3 ;
}
return V_72 -> V_467 ;
}
static T_2 F_246 ( struct V_450 * V_470 )
{
T_2 V_121 ;
if ( V_470 -> V_475 || ! V_470 -> V_473 )
V_121 = 1 << 16 ;
else {
V_121 = V_470 -> type & 15 ;
V_121 |= ( V_470 -> V_183 & 1 ) << 4 ;
V_121 |= ( V_470 -> V_455 & 3 ) << 5 ;
V_121 |= ( V_470 -> V_473 & 1 ) << 7 ;
V_121 |= ( V_470 -> V_476 & 1 ) << 12 ;
V_121 |= ( V_470 -> V_474 & 1 ) << 13 ;
V_121 |= ( V_470 -> V_472 & 1 ) << 14 ;
V_121 |= ( V_470 -> V_471 & 1 ) << 15 ;
}
return V_121 ;
}
static void F_242 ( struct V_7 * V_8 ,
struct V_450 * V_470 , int V_107 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
const struct V_468 * V_469 = & V_116 [ V_107 ] ;
F_105 ( V_72 ) ;
if ( V_107 == V_452 )
F_271 ( V_466 , ( T_9 * ) & V_8 -> V_110 . V_111 ) ;
if ( V_72 -> V_130 . V_131 && V_107 != V_524 ) {
V_72 -> V_130 . V_457 [ V_107 ] = * V_470 ;
if ( V_107 == V_462 )
F_100 ( V_469 -> V_114 , V_470 -> V_114 ) ;
else if ( V_470 -> V_183 )
F_245 ( V_107 , & V_72 -> V_130 . V_457 [ V_107 ] ) ;
goto V_525;
}
F_98 ( V_469 -> V_117 , V_470 -> V_117 ) ;
F_101 ( V_469 -> V_119 , V_470 -> V_119 ) ;
F_100 ( V_469 -> V_114 , V_470 -> V_114 ) ;
if ( V_439 && ( V_107 != V_524 ) )
V_470 -> type |= 0x1 ;
F_101 ( V_469 -> V_123 , F_246 ( V_470 ) ) ;
V_525:
V_72 -> F_239 |= F_239 ( V_8 ) ;
}
static void F_272 ( struct V_7 * V_8 , int * V_472 , int * V_474 )
{
T_2 V_121 = F_110 ( F_6 ( V_8 ) , V_452 ) ;
* V_472 = ( V_121 >> 14 ) & 1 ;
* V_474 = ( V_121 >> 13 ) & 1 ;
}
static void F_273 ( struct V_7 * V_8 , struct V_163 * V_526 )
{
V_526 -> V_425 = F_93 ( V_527 ) ;
V_526 -> V_168 = F_91 ( V_528 ) ;
}
static void F_274 ( struct V_7 * V_8 , struct V_163 * V_526 )
{
F_101 ( V_527 , V_526 -> V_425 ) ;
F_98 ( V_528 , V_526 -> V_168 ) ;
}
static void F_275 ( struct V_7 * V_8 , struct V_163 * V_526 )
{
V_526 -> V_425 = F_93 ( V_529 ) ;
V_526 -> V_168 = F_91 ( V_530 ) ;
}
static void F_276 ( struct V_7 * V_8 , struct V_163 * V_526 )
{
F_101 ( V_529 , V_526 -> V_425 ) ;
F_98 ( V_530 , V_526 -> V_168 ) ;
}
static bool F_277 ( struct V_7 * V_8 , int V_107 )
{
struct V_450 V_470 ;
T_2 V_121 ;
F_244 ( V_8 , & V_470 , V_107 ) ;
V_470 . V_455 = 0x3 ;
if ( V_107 == V_452 )
V_470 . type = 0x3 ;
V_121 = F_246 ( & V_470 ) ;
if ( V_470 . V_117 != ( V_470 . V_114 << 4 ) )
return false ;
if ( V_470 . V_119 != 0xffff )
return false ;
if ( V_121 != 0xf3 )
return false ;
return true ;
}
static bool F_278 ( struct V_7 * V_8 )
{
struct V_450 V_531 ;
unsigned int V_532 ;
F_244 ( V_8 , & V_531 , V_452 ) ;
V_532 = V_531 . V_114 & V_454 ;
if ( V_531 . V_475 )
return false ;
if ( ~ V_531 . type & ( V_533 | V_534 ) )
return false ;
if ( ! V_531 . V_183 )
return false ;
if ( V_531 . type & V_535 ) {
if ( V_531 . V_455 > V_532 )
return false ;
} else {
if ( V_531 . V_455 != V_532 )
return false ;
}
if ( ! V_531 . V_473 )
return false ;
return true ;
}
static bool F_279 ( struct V_7 * V_8 )
{
struct V_450 V_536 ;
unsigned int V_537 ;
F_244 ( V_8 , & V_536 , V_453 ) ;
V_537 = V_536 . V_114 & V_454 ;
if ( V_536 . V_475 )
return true ;
if ( V_536 . type != 3 && V_536 . type != 7 )
return false ;
if ( ! V_536 . V_183 )
return false ;
if ( V_536 . V_455 != V_537 )
return false ;
if ( ! V_536 . V_473 )
return false ;
return true ;
}
static bool F_280 ( struct V_7 * V_8 , int V_107 )
{
struct V_450 V_470 ;
unsigned int V_538 ;
F_244 ( V_8 , & V_470 , V_107 ) ;
V_538 = V_470 . V_114 & V_454 ;
if ( V_470 . V_475 )
return true ;
if ( ! V_470 . V_183 )
return false ;
if ( ! V_470 . V_473 )
return false ;
if ( ~ V_470 . type & ( V_533 | V_535 ) ) {
if ( V_470 . V_455 < V_538 )
return false ;
}
return true ;
}
static bool F_281 ( struct V_7 * V_8 )
{
struct V_450 V_186 ;
F_244 ( V_8 , & V_186 , V_462 ) ;
if ( V_186 . V_475 )
return false ;
if ( V_186 . V_114 & V_539 )
return false ;
if ( V_186 . type != 3 && V_186 . type != 11 )
return false ;
if ( ! V_186 . V_473 )
return false ;
return true ;
}
static bool F_282 ( struct V_7 * V_8 )
{
struct V_450 V_540 ;
F_244 ( V_8 , & V_540 , V_524 ) ;
if ( V_540 . V_475 )
return true ;
if ( V_540 . V_114 & V_539 )
return false ;
if ( V_540 . type != 2 )
return false ;
if ( ! V_540 . V_473 )
return false ;
return true ;
}
static bool F_283 ( struct V_7 * V_8 )
{
struct V_450 V_531 , V_536 ;
F_244 ( V_8 , & V_531 , V_452 ) ;
F_244 ( V_8 , & V_536 , V_453 ) ;
return ( ( V_531 . V_114 & V_454 ) ==
( V_536 . V_114 & V_454 ) ) ;
}
static bool F_240 ( struct V_7 * V_8 )
{
if ( V_439 )
return true ;
if ( ! F_269 ( V_8 ) || ( F_157 ( V_8 ) & V_242 ) ) {
if ( ! F_277 ( V_8 , V_452 ) )
return false ;
if ( ! F_277 ( V_8 , V_453 ) )
return false ;
if ( ! F_277 ( V_8 , V_459 ) )
return false ;
if ( ! F_277 ( V_8 , V_458 ) )
return false ;
if ( ! F_277 ( V_8 , V_460 ) )
return false ;
if ( ! F_277 ( V_8 , V_461 ) )
return false ;
} else {
if ( ! F_283 ( V_8 ) )
return false ;
if ( ! F_278 ( V_8 ) )
return false ;
if ( ! F_279 ( V_8 ) )
return false ;
if ( ! F_280 ( V_8 , V_459 ) )
return false ;
if ( ! F_280 ( V_8 , V_458 ) )
return false ;
if ( ! F_280 ( V_8 , V_460 ) )
return false ;
if ( ! F_280 ( V_8 , V_461 ) )
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
T_13 V_541 ;
T_4 V_179 = 0 ;
int V_542 , V_543 , V_108 = 0 ;
V_543 = F_285 ( & V_17 -> V_544 ) ;
V_541 = V_17 -> V_110 . V_477 >> V_18 ;
V_542 = F_286 ( V_17 , V_541 , 0 , V_424 ) ;
if ( V_542 < 0 )
goto V_525;
V_179 = V_545 + V_546 ;
V_542 = F_287 ( V_17 , V_541 ++ , & V_179 ,
V_547 , sizeof( T_4 ) ) ;
if ( V_542 < 0 )
goto V_525;
V_542 = F_286 ( V_17 , V_541 ++ , 0 , V_424 ) ;
if ( V_542 < 0 )
goto V_525;
V_542 = F_286 ( V_17 , V_541 , 0 , V_424 ) ;
if ( V_542 < 0 )
goto V_525;
V_179 = ~ 0 ;
V_542 = F_287 ( V_17 , V_541 , & V_179 ,
V_480 - 2 * V_424 - 1 ,
sizeof( T_6 ) ) ;
if ( V_542 < 0 )
goto V_525;
V_108 = 1 ;
V_525:
F_288 ( & V_17 -> V_544 , V_543 ) ;
return V_108 ;
}
static int F_289 ( struct V_17 * V_17 )
{
int V_74 , V_543 , V_542 , V_108 ;
T_14 V_548 ;
T_2 V_266 ;
if ( ! V_100 )
return 1 ;
if ( F_99 ( ! V_17 -> V_110 . V_549 ) ) {
F_68 ( V_88 L_18
L_19 ) ;
return 0 ;
}
if ( F_290 ( V_17 -> V_110 . V_550 ) )
return 1 ;
V_108 = 0 ;
V_548 = V_17 -> V_110 . V_516 >> V_18 ;
V_543 = F_285 ( & V_17 -> V_544 ) ;
V_542 = F_286 ( V_17 , V_548 , 0 , V_424 ) ;
if ( V_542 < 0 )
goto V_525;
for ( V_74 = 0 ; V_74 < V_551 ; V_74 ++ ) {
V_266 = ( V_74 << 22 ) + ( V_552 | V_553 | V_554 |
V_555 | V_556 | V_557 ) ;
V_542 = F_287 ( V_17 , V_548 ,
& V_266 , V_74 * sizeof( V_266 ) , sizeof( V_266 ) ) ;
if ( V_542 < 0 )
goto V_525;
}
V_17 -> V_110 . V_550 = true ;
V_108 = 1 ;
V_525:
F_288 ( & V_17 -> V_544 , V_543 ) ;
return V_108 ;
}
static void F_291 ( int V_107 )
{
const struct V_468 * V_469 = & V_116 [ V_107 ] ;
unsigned int V_121 ;
F_100 ( V_469 -> V_114 , 0 ) ;
F_98 ( V_469 -> V_117 , 0 ) ;
F_101 ( V_469 -> V_119 , 0xffff ) ;
V_121 = 0x93 ;
if ( V_107 == V_452 )
V_121 |= 0x08 ;
F_101 ( V_469 -> V_123 , V_121 ) ;
}
static int F_292 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_558 V_559 ;
int V_542 = 0 ;
F_293 ( & V_17 -> V_560 ) ;
if ( V_17 -> V_110 . V_561 )
goto V_525;
V_559 . V_562 = V_563 ;
V_559 . V_456 = 0 ;
V_559 . V_564 = 0xfee00000ULL ;
V_559 . V_565 = V_424 ;
V_542 = F_294 ( V_17 , & V_559 ) ;
if ( V_542 )
goto V_525;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_542 = - V_566 ;
goto V_525;
}
V_17 -> V_110 . V_561 = V_15 ;
V_525:
F_295 ( & V_17 -> V_560 ) ;
return V_542 ;
}
static int F_296 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_558 V_559 ;
int V_542 = 0 ;
F_293 ( & V_17 -> V_560 ) ;
if ( V_17 -> V_110 . V_549 )
goto V_525;
V_559 . V_562 = V_567 ;
V_559 . V_456 = 0 ;
V_559 . V_564 =
V_17 -> V_110 . V_516 ;
V_559 . V_565 = V_424 ;
V_542 = F_294 ( V_17 , & V_559 ) ;
if ( V_542 )
goto V_525;
V_15 = F_11 ( V_17 , V_17 -> V_110 . V_516 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_542 = - V_566 ;
goto V_525;
}
V_17 -> V_110 . V_549 = V_15 ;
V_525:
F_295 ( & V_17 -> V_560 ) ;
return V_542 ;
}
static void F_297 ( struct V_6 * V_72 )
{
int V_52 ;
V_72 -> V_52 = 0 ;
if ( ! V_437 )
return;
F_298 ( & V_568 ) ;
V_52 = F_299 ( V_569 , V_570 ) ;
if ( V_52 < V_570 ) {
V_72 -> V_52 = V_52 ;
F_159 ( V_52 , V_569 ) ;
}
F_300 ( & V_568 ) ;
}
static void F_301 ( struct V_6 * V_72 )
{
if ( ! V_437 )
return;
F_298 ( & V_568 ) ;
if ( V_72 -> V_52 != 0 )
F_271 ( V_72 -> V_52 , V_569 ) ;
F_300 ( & V_568 ) ;
}
static void F_302 ( unsigned long * V_267 ,
T_2 V_73 , int type )
{
int V_571 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_572 )
F_271 ( V_73 , V_267 + 0x000 / V_571 ) ;
if ( type & V_573 )
F_271 ( V_73 , V_267 + 0x800 / V_571 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_572 )
F_271 ( V_73 , V_267 + 0x400 / V_571 ) ;
if ( type & V_573 )
F_271 ( V_73 , V_267 + 0xc00 / V_571 ) ;
}
}
static void F_303 ( unsigned long * V_267 ,
T_2 V_73 , int type )
{
int V_571 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_572 )
F_159 ( V_73 , V_267 + 0x000 / V_571 ) ;
if ( type & V_573 )
F_159 ( V_73 , V_267 + 0x800 / V_571 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_572 )
F_159 ( V_73 , V_267 + 0x400 / V_571 ) ;
if ( type & V_573 )
F_159 ( V_73 , V_267 + 0xc00 / V_571 ) ;
}
}
static void F_304 ( T_2 V_73 , bool V_574 )
{
if ( ! V_574 )
F_302 ( V_272 ,
V_73 , V_572 | V_573 ) ;
F_302 ( V_271 ,
V_73 , V_572 | V_573 ) ;
}
static void F_305 ( T_2 V_73 )
{
F_303 ( V_270 ,
V_73 , V_572 ) ;
F_303 ( V_269 ,
V_73 , V_572 ) ;
}
static void F_306 ( T_2 V_73 )
{
F_302 ( V_270 ,
V_73 , V_572 ) ;
F_302 ( V_269 ,
V_73 , V_572 ) ;
}
static void F_307 ( T_2 V_73 )
{
F_302 ( V_270 ,
V_73 , V_573 ) ;
F_302 ( V_269 ,
V_73 , V_573 ) ;
}
static int F_308 ( struct V_17 * V_17 )
{
return V_444 && F_25 ( V_17 ) ;
}
static void F_309 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_542 ;
if ( F_5 ( V_4 , & V_72 -> V_1 ) )
return;
V_542 = F_1 ( & V_72 -> V_1 ) ;
F_144 ( V_575 , V_8 ) ;
#ifdef F_310
if ( ! V_542 && ( V_8 -> V_576 == V_577 ) )
V_268 -> V_578 ( F_311 ( V_8 -> V_90 ) ,
V_579 ) ;
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
static void V_448 ( struct V_7 * V_8 )
{
return;
}
static void F_315 ( struct V_6 * V_72 )
{
T_2 V_580 , V_581 ;
unsigned long V_582 ;
struct V_163 V_526 ;
F_98 ( V_583 , F_316 () & ~ V_224 ) ;
F_98 ( V_584 , F_212 () ) ;
F_98 ( V_585 , F_317 () ) ;
F_100 ( V_586 , V_587 ) ;
#ifdef F_95
F_100 ( V_588 , 0 ) ;
F_100 ( V_589 , 0 ) ;
#else
F_100 ( V_588 , V_590 ) ;
F_100 ( V_589 , V_590 ) ;
#endif
F_100 ( V_591 , V_590 ) ;
F_100 ( V_592 , V_169 * 8 ) ;
F_318 ( & V_526 ) ;
F_98 ( V_593 , V_526 . V_168 ) ;
V_72 -> V_594 = V_526 . V_168 ;
F_98 ( V_595 , V_596 ) ;
F_192 ( V_380 , V_580 , V_581 ) ;
F_101 ( V_597 , V_580 ) ;
F_55 ( V_382 , V_582 ) ;
F_98 ( V_598 , V_582 ) ;
if ( V_29 . V_428 & V_310 ) {
F_192 ( V_385 , V_580 , V_581 ) ;
F_102 ( V_599 , V_580 | ( ( T_3 ) V_581 << 32 ) ) ;
}
}
static void F_319 ( struct V_6 * V_72 )
{
V_72 -> V_8 . V_110 . V_491 = V_600 ;
if ( V_100 )
V_72 -> V_8 . V_110 . V_491 |= V_601 ;
if ( F_112 ( & V_72 -> V_8 ) )
V_72 -> V_8 . V_110 . V_491 &=
~ F_9 ( & V_72 -> V_8 ) -> V_233 ;
F_98 ( V_602 , ~ V_72 -> V_8 . V_110 . V_491 ) ;
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
T_2 V_603 = V_29 . V_30 ;
if ( ! F_24 ( V_72 -> V_8 . V_17 ) ) {
V_603 &= ~ V_32 ;
#ifdef F_95
V_603 |= V_331 |
V_330 ;
#endif
}
if ( ! V_100 )
V_603 |= V_329 |
V_328 |
V_326 ;
return V_603 ;
}
static T_2 F_322 ( struct V_6 * V_72 )
{
T_2 V_603 = V_29 . V_34 ;
if ( ! F_48 ( V_72 -> V_8 . V_17 ) )
V_603 &= ~ V_35 ;
if ( V_72 -> V_52 == 0 )
V_603 &= ~ V_59 ;
if ( ! V_100 ) {
V_603 &= ~ V_55 ;
V_439 = 0 ;
V_603 &= ~ V_61 ;
}
if ( ! V_439 )
V_603 &= ~ V_56 ;
if ( ! V_443 )
V_603 &= ~ V_57 ;
if ( ! F_308 ( V_72 -> V_8 . V_17 ) )
V_603 &= ~ ( V_37 |
V_38 ) ;
V_603 &= ~ V_36 ;
V_603 &= ~ V_67 ;
return V_603 ;
}
static void F_323 ( void )
{
F_324 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_325 ( struct V_6 * V_72 )
{
#ifdef F_95
unsigned long V_604 ;
#endif
int V_74 ;
F_102 ( V_605 , F_67 ( V_606 ) ) ;
F_102 ( V_607 , F_67 ( V_608 ) ) ;
if ( V_438 ) {
F_102 ( V_609 , F_67 ( V_610 ) ) ;
F_102 ( V_611 , F_67 ( V_612 ) ) ;
}
if ( F_22 () )
F_102 ( V_273 , F_67 ( V_272 ) ) ;
F_102 ( V_613 , - 1ull ) ;
F_101 ( V_614 , F_320 ( V_72 ) ) ;
F_101 ( V_503 , F_321 ( V_72 ) ) ;
if ( F_26 () ) {
F_101 ( V_615 ,
F_322 ( V_72 ) ) ;
}
if ( F_308 ( V_72 -> V_8 . V_17 ) ) {
F_102 ( V_616 , 0 ) ;
F_102 ( V_617 , 0 ) ;
F_102 ( V_618 , 0 ) ;
F_102 ( V_619 , 0 ) ;
F_100 ( V_620 , 0 ) ;
F_102 ( V_621 , V_579 ) ;
F_102 ( V_622 , F_67 ( ( & V_72 -> V_1 ) ) ) ;
}
if ( V_443 ) {
F_101 ( V_623 , V_443 ) ;
F_101 ( V_624 , V_625 ) ;
}
F_101 ( V_626 , 0 ) ;
F_101 ( V_627 , 0 ) ;
F_101 ( V_628 , 0 ) ;
F_100 ( V_193 , 0 ) ;
F_100 ( V_197 , 0 ) ;
F_315 ( V_72 ) ;
#ifdef F_95
F_55 ( V_203 , V_604 ) ;
F_98 ( V_202 , V_604 ) ;
F_55 ( V_205 , V_604 ) ;
F_98 ( V_204 , V_604 ) ;
#else
F_98 ( V_202 , 0 ) ;
F_98 ( V_204 , 0 ) ;
#endif
F_101 ( V_629 , 0 ) ;
F_101 ( V_152 , 0 ) ;
F_102 ( V_630 , F_67 ( V_72 -> V_138 . V_150 ) ) ;
F_101 ( V_151 , 0 ) ;
F_102 ( V_631 , F_67 ( V_72 -> V_138 . V_149 ) ) ;
if ( V_29 . V_386 & V_319 ) {
T_2 V_632 , V_633 ;
T_3 V_634 ;
F_192 ( V_385 , V_632 , V_633 ) ;
V_634 = V_632 | ( ( T_3 ) V_633 << 32 ) ;
F_102 ( V_387 , V_634 ) ;
V_72 -> V_8 . V_110 . V_388 = V_634 ;
}
for ( V_74 = 0 ; V_74 < V_635 ; ++ V_74 ) {
T_2 V_78 = V_76 [ V_74 ] ;
T_2 V_636 , V_637 ;
int V_638 = V_72 -> V_75 ;
if ( F_326 ( V_78 , & V_636 , & V_637 ) < 0 )
continue;
if ( F_327 ( V_78 , V_636 , V_637 ) < 0 )
continue;
V_72 -> V_77 [ V_638 ] . V_78 = V_74 ;
V_72 -> V_77 [ V_638 ] . V_179 = 0 ;
V_72 -> V_77 [ V_638 ] . V_104 = - 1ull ;
++ V_72 -> V_75 ;
}
F_101 ( V_137 , V_29 . V_428 ) ;
F_101 ( V_136 , V_29 . V_386 ) ;
F_98 ( V_228 , ~ 0UL ) ;
F_319 ( V_72 ) ;
return 0 ;
}
static void F_328 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_73 ;
V_72 -> V_130 . V_131 = 0 ;
V_72 -> V_639 = 0 ;
V_72 -> V_8 . V_110 . V_393 [ V_640 ] = F_329 () ;
F_330 ( & V_72 -> V_8 , 0 ) ;
V_73 = 0xfee00000 | V_641 ;
if ( F_331 ( & V_72 -> V_8 ) )
V_73 |= V_642 ;
F_332 ( & V_72 -> V_8 , V_73 ) ;
F_105 ( V_72 ) ;
F_291 ( V_452 ) ;
F_100 ( V_643 , 0xf000 ) ;
F_101 ( V_644 , 0xffff0000 ) ;
F_291 ( V_459 ) ;
F_291 ( V_458 ) ;
F_291 ( V_460 ) ;
F_291 ( V_461 ) ;
F_291 ( V_453 ) ;
F_100 ( V_645 , 0 ) ;
F_98 ( V_478 , 0 ) ;
F_101 ( V_479 , 0xffff ) ;
F_101 ( V_481 , 0x008b ) ;
F_100 ( V_646 , 0 ) ;
F_98 ( V_647 , 0 ) ;
F_101 ( V_648 , 0xffff ) ;
F_101 ( V_649 , 0x00082 ) ;
F_101 ( V_381 , 0 ) ;
F_98 ( V_384 , 0 ) ;
F_98 ( V_383 , 0 ) ;
F_98 ( V_239 , 0x02 ) ;
F_165 ( V_8 , 0xfff0 ) ;
F_98 ( V_530 , 0 ) ;
F_101 ( V_529 , 0xffff ) ;
F_98 ( V_528 , 0 ) ;
F_101 ( V_527 , 0xffff ) ;
F_101 ( V_650 , V_651 ) ;
F_101 ( V_244 , 0 ) ;
F_101 ( V_652 , 0 ) ;
F_102 ( V_653 , 0 ) ;
F_176 ( V_72 ) ;
F_101 ( V_263 , 0 ) ;
if ( F_23 () ) {
F_102 ( V_654 , 0 ) ;
if ( F_24 ( V_72 -> V_8 . V_17 ) )
F_102 ( V_654 ,
F_67 ( V_72 -> V_8 . V_110 . V_268 -> V_393 ) ) ;
F_101 ( V_655 , 0 ) ;
}
if ( F_48 ( V_72 -> V_8 . V_17 ) )
F_102 ( V_656 ,
F_333 ( V_72 -> V_8 . V_17 -> V_110 . V_561 ) ) ;
if ( F_308 ( V_8 -> V_17 ) )
memset ( & V_72 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_72 -> V_52 != 0 )
F_100 ( V_657 , V_72 -> V_52 ) ;
V_72 -> V_8 . V_110 . V_222 = V_658 | V_659 | V_660 ;
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
V_302 ;
}
static bool F_336 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_303 ;
}
static int F_337 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( F_112 ( V_8 ) && F_335 ( V_8 ) )
return - V_404 ;
V_69 = F_93 ( V_503 ) ;
V_69 |= V_323 ;
F_101 ( V_503 , V_69 ) ;
return 0 ;
}
static int F_338 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () )
return F_337 ( V_8 ) ;
if ( F_93 ( V_244 ) & V_245 )
return F_337 ( V_8 ) ;
V_69 = F_93 ( V_503 ) ;
V_69 |= V_324 ;
F_101 ( V_503 , V_69 ) ;
return 0 ;
}
static void F_339 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_15 V_661 ;
int V_662 = V_8 -> V_110 . V_663 . V_148 ;
F_340 ( V_662 ) ;
++ V_8 -> V_210 . V_664 ;
if ( V_72 -> V_130 . V_131 ) {
int V_257 = 0 ;
if ( V_8 -> V_110 . V_663 . V_665 )
V_257 = V_8 -> V_110 . V_258 ;
if ( F_170 ( V_8 , V_662 , V_257 ) != V_259 )
F_144 ( V_260 , V_8 ) ;
return;
}
V_661 = V_662 | V_22 ;
if ( V_8 -> V_110 . V_663 . V_665 ) {
V_661 |= V_666 ;
F_101 ( V_261 ,
V_72 -> V_8 . V_110 . V_258 ) ;
} else
V_661 |= V_27 ;
F_101 ( V_263 , V_661 ) ;
}
static void F_341 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( F_112 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_72 -> V_639 = 1 ;
V_72 -> V_667 = 0 ;
}
++ V_8 -> V_210 . V_668 ;
V_72 -> V_669 = false ;
if ( V_72 -> V_130 . V_131 ) {
if ( F_170 ( V_8 , V_670 , 0 ) != V_259 )
F_144 ( V_260 , V_8 ) ;
return;
}
F_101 ( V_263 ,
V_671 | V_22 | V_670 ) ;
}
static bool F_342 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_639 ;
if ( F_6 ( V_8 ) -> V_669 )
return false ;
return F_93 ( V_244 ) & V_672 ;
}
static void F_343 ( struct V_7 * V_8 , bool V_673 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_72 -> V_639 != V_673 ) {
V_72 -> V_639 = V_673 ;
V_72 -> V_667 = 0 ;
}
} else {
V_72 -> V_669 = ! V_673 ;
if ( V_673 )
F_104 ( V_244 ,
V_672 ) ;
else
F_103 ( V_244 ,
V_672 ) ;
}
}
static int F_344 ( struct V_7 * V_8 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_674 )
return 0 ;
if ( F_336 ( V_8 ) ) {
F_167 ( V_8 ) ;
V_12 -> V_675 = V_676 ;
V_12 -> V_677 = V_670 |
V_671 | V_22 ;
V_8 -> V_110 . V_678 = 0 ;
F_343 ( V_8 , true ) ;
return 0 ;
}
}
if ( ! F_52 () && F_6 ( V_8 ) -> V_639 )
return 0 ;
return ! ( F_93 ( V_244 ) &
( V_247 | V_245
| V_672 ) ) ;
}
static int F_345 ( struct V_7 * V_8 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_13 . V_674 )
return 0 ;
if ( F_335 ( V_8 ) ) {
F_167 ( V_8 ) ;
V_12 -> V_675 =
V_679 ;
V_12 -> V_677 = 0 ;
}
}
return ( F_91 ( V_239 ) & V_680 ) &&
! ( F_93 ( V_244 ) &
( V_245 | V_247 ) ) ;
}
static int F_346 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_108 ;
struct V_558 V_681 = {
. V_562 = V_682 ,
. V_564 = V_16 ,
. V_565 = V_424 * 3 ,
. V_456 = 0 ,
} ;
V_108 = F_347 ( V_17 , & V_681 ) ;
if ( V_108 )
return V_108 ;
V_17 -> V_110 . V_477 = V_16 ;
if ( ! F_284 ( V_17 ) )
return - V_435 ;
return 0 ;
}
static bool F_348 ( struct V_7 * V_8 , int V_683 )
{
switch ( V_683 ) {
case V_129 :
F_6 ( V_8 ) -> V_8 . V_110 . V_258 =
F_93 ( V_251 ) ;
if ( V_8 -> V_126 & V_128 )
return false ;
case V_125 :
if ( V_8 -> V_126 &
( V_684 | V_685 ) )
return false ;
case V_686 :
case V_687 :
case V_688 :
case V_26 :
case V_689 :
case V_690 :
case V_354 :
case V_691 :
return true ;
break;
}
return false ;
}
static int F_349 ( struct V_7 * V_8 ,
int V_683 , T_2 V_692 )
{
if ( ( ( V_683 == V_354 ) || ( V_683 == V_690 ) ) && V_692 == 0 ) {
if ( F_350 ( V_8 , 0 ) == V_259 ) {
if ( V_8 -> V_110 . V_693 ) {
V_8 -> V_110 . V_693 = 0 ;
return F_351 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_352 ( V_8 , V_683 ) ;
return 1 ;
}
static void F_353 ( void )
{
#if F_354 ( V_694 ) && F_354 ( F_95 )
struct V_695 V_393 = {
. V_531 = 3 ,
. V_456 = V_680 ,
} ;
F_355 ( & V_393 , 0 ) ;
#endif
}
static int F_356 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_357 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_696 * V_696 = V_8 -> V_697 ;
T_2 V_19 , V_698 , V_253 ;
unsigned long V_699 , V_250 , V_700 ;
T_2 V_701 ;
enum V_702 V_703 ;
V_701 = V_72 -> V_704 ;
V_19 = V_72 -> V_705 ;
if ( F_21 ( V_19 ) )
return F_356 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_671 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_151 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_703 = F_350 ( V_8 , V_706 ) ;
if ( V_703 != V_259 )
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
V_253 = 0 ;
if ( V_19 & V_256 )
V_253 = F_93 ( V_707 ) ;
if ( ( V_701 & V_708 ) &&
! ( F_17 ( V_19 ) && ! ( V_253 & V_709 ) ) ) {
V_8 -> V_697 -> V_710 = V_711 ;
V_8 -> V_697 -> V_712 . V_713 = V_714 ;
V_8 -> V_697 -> V_712 . V_715 = 2 ;
V_8 -> V_697 -> V_712 . V_179 [ 0 ] = V_701 ;
V_8 -> V_697 -> V_712 . V_179 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_358 ( V_100 ) ;
V_699 = F_91 ( V_716 ) ;
F_359 ( V_699 , V_253 ) ;
if ( F_360 ( V_8 ) )
F_361 ( V_8 , V_699 ) ;
return F_362 ( V_8 , V_699 , V_253 , NULL , 0 ) ;
}
V_698 = V_19 & V_21 ;
if ( V_72 -> V_130 . V_131 && F_348 ( V_8 , V_698 ) )
return F_349 ( V_8 , V_698 , V_253 ) ;
switch ( V_698 ) {
case V_125 :
V_700 = F_91 ( V_716 ) ;
if ( ! ( V_8 -> V_126 &
( V_684 | V_685 ) ) ) {
V_8 -> V_110 . V_700 = V_700 | V_717 ;
F_352 ( V_8 , V_125 ) ;
return 1 ;
}
V_696 -> V_718 . V_110 . V_700 = V_700 | V_717 ;
V_696 -> V_718 . V_110 . V_719 = F_91 ( V_720 ) ;
case V_129 :
V_72 -> V_8 . V_110 . V_258 =
F_93 ( V_251 ) ;
V_696 -> V_710 = V_721 ;
V_250 = F_164 ( V_8 ) ;
V_696 -> V_718 . V_110 . V_722 = F_91 ( V_644 ) + V_250 ;
V_696 -> V_718 . V_110 . V_723 = V_698 ;
break;
default:
V_696 -> V_710 = V_724 ;
V_696 -> V_725 . V_723 = V_698 ;
V_696 -> V_725 . V_253 = V_253 ;
break;
}
return 0 ;
}
static int F_363 ( struct V_7 * V_8 )
{
++ V_8 -> V_210 . V_726 ;
return 1 ;
}
static int F_364 ( struct V_7 * V_8 )
{
V_8 -> V_697 -> V_710 = V_727 ;
return 0 ;
}
static int F_365 ( struct V_7 * V_8 )
{
unsigned long V_728 ;
int V_425 , V_729 , string ;
unsigned V_730 ;
V_728 = F_91 ( V_716 ) ;
string = ( V_728 & 16 ) != 0 ;
V_729 = ( V_728 & 8 ) != 0 ;
++ V_8 -> V_210 . V_731 ;
if ( string || V_729 )
return F_350 ( V_8 , 0 ) == V_259 ;
V_730 = V_728 >> 16 ;
V_425 = ( V_728 & 7 ) + 1 ;
F_163 ( V_8 ) ;
return F_366 ( V_8 , V_425 , V_730 ) ;
}
static void
F_367 ( struct V_7 * V_8 , unsigned char * V_732 )
{
V_732 [ 0 ] = 0x0f ;
V_732 [ 1 ] = 0x01 ;
V_732 [ 2 ] = 0xc1 ;
}
static bool F_368 ( struct V_12 * V_12 , unsigned long V_733 )
{
unsigned long V_734 = F_197 ;
if ( V_341 &
V_56 &&
F_58 ( V_12 , V_56 ) )
V_734 &= ~ ( V_508 | V_502 ) ;
return ( V_733 & V_734 ) == V_734 ;
}
static int F_369 ( struct V_7 * V_8 , unsigned long V_733 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_735 = V_733 ;
V_733 = ( V_733 & ~ V_12 -> V_227 ) |
( V_12 -> V_230 & V_12 -> V_227 ) ;
if ( ! F_368 ( V_12 , V_733 ) )
return 1 ;
if ( F_370 ( V_8 , V_733 ) )
return 1 ;
F_98 ( V_235 , V_735 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_520 &&
( ( V_733 & F_197 ) != F_197 ) )
return 1 ;
return F_370 ( V_8 , V_733 ) ;
}
}
static int F_371 ( struct V_7 * V_8 , unsigned long V_733 )
{
if ( F_112 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_735 = V_733 ;
V_733 = ( V_733 & ~ V_12 -> V_233 ) |
( V_12 -> V_232 & V_12 -> V_233 ) ;
if ( F_372 ( V_8 , V_733 ) )
return 1 ;
F_98 ( V_465 , V_735 ) ;
return 0 ;
} else
return F_372 ( V_8 , V_733 ) ;
}
static void F_373 ( struct V_7 * V_8 )
{
if ( F_112 ( V_8 ) ) {
F_98 ( V_235 ,
F_91 ( V_235 ) & ~ V_224 ) ;
V_8 -> V_110 . V_222 &= ~ V_224 ;
} else
F_264 ( V_8 , F_152 ( V_8 , ~ V_224 ) ) ;
}
static int F_374 ( struct V_7 * V_8 )
{
unsigned long V_728 , V_733 ;
int V_736 ;
int V_391 ;
int V_737 ;
V_728 = F_91 ( V_716 ) ;
V_736 = V_728 & 15 ;
V_391 = ( V_728 >> 8 ) & 15 ;
switch ( ( V_728 >> 4 ) & 3 ) {
case 0 :
V_733 = F_375 ( V_8 , V_391 ) ;
F_376 ( V_736 , V_733 ) ;
switch ( V_736 ) {
case 0 :
V_737 = F_369 ( V_8 , V_733 ) ;
F_377 ( V_8 , V_737 ) ;
return 1 ;
case 3 :
V_737 = F_378 ( V_8 , V_733 ) ;
F_377 ( V_8 , V_737 ) ;
return 1 ;
case 4 :
V_737 = F_371 ( V_8 , V_733 ) ;
F_377 ( V_8 , V_737 ) ;
return 1 ;
case 8 : {
T_6 V_738 = F_379 ( V_8 ) ;
T_6 V_739 = F_375 ( V_8 , V_391 ) ;
V_737 = F_330 ( V_8 , V_739 ) ;
F_377 ( V_8 , V_737 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_738 <= V_739 )
return 1 ;
V_8 -> V_697 -> V_710 = V_740 ;
return 0 ;
}
}
break;
case 2 :
F_373 ( V_8 ) ;
F_376 ( 0 , F_334 ( V_8 ) ) ;
F_163 ( V_8 ) ;
F_151 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_736 ) {
case 3 :
V_733 = F_266 ( V_8 ) ;
F_380 ( V_8 , V_391 , V_733 ) ;
F_381 ( V_736 , V_733 ) ;
F_163 ( V_8 ) ;
return 1 ;
case 8 :
V_733 = F_379 ( V_8 ) ;
F_380 ( V_8 , V_391 , V_733 ) ;
F_381 ( V_736 , V_733 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_733 = ( V_728 >> V_741 ) & 0x0f ;
F_376 ( 0 , ( F_334 ( V_8 ) & ~ 0xful ) | V_733 ) ;
F_382 ( V_8 , V_733 ) ;
F_163 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_697 -> V_710 = 0 ;
F_383 ( V_8 , L_20 ,
( int ) ( V_728 >> 4 ) & 3 , V_736 ) ;
return 0 ;
}
static int F_384 ( struct V_7 * V_8 )
{
unsigned long V_728 ;
int V_742 , V_391 ;
if ( ! F_385 ( V_8 , 0 ) )
return 1 ;
V_742 = F_91 ( V_720 ) ;
if ( V_742 & V_743 ) {
if ( V_8 -> V_126 & V_685 ) {
V_8 -> V_697 -> V_718 . V_110 . V_700 = V_8 -> V_110 . V_700 ;
V_8 -> V_697 -> V_718 . V_110 . V_719 = V_742 ;
V_8 -> V_697 -> V_718 . V_110 . V_722 =
F_91 ( V_644 ) +
F_91 ( V_396 ) ;
V_8 -> V_697 -> V_718 . V_110 . V_723 = V_125 ;
V_8 -> V_697 -> V_710 = V_721 ;
return 0 ;
} else {
V_8 -> V_110 . V_719 &= ~ V_743 ;
V_8 -> V_110 . V_700 |= V_744 ;
F_98 ( V_720 , V_8 -> V_110 . V_719 ) ;
F_352 ( V_8 , V_125 ) ;
return 1 ;
}
}
V_728 = F_91 ( V_716 ) ;
V_742 = V_728 & V_745 ;
V_391 = F_386 ( V_728 ) ;
if ( V_728 & V_746 ) {
unsigned long V_733 ;
if ( ! F_387 ( V_8 , V_742 , & V_733 ) )
F_380 ( V_8 , V_391 , V_733 ) ;
} else
F_388 ( V_8 , V_742 , V_8 -> V_110 . V_393 [ V_391 ] ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static void F_389 ( struct V_7 * V_8 , unsigned long V_733 )
{
F_98 ( V_720 , V_733 ) ;
}
static int F_390 ( struct V_7 * V_8 )
{
F_391 ( V_8 ) ;
return 1 ;
}
static int F_392 ( struct V_7 * V_8 )
{
T_2 V_296 = V_8 -> V_110 . V_393 [ V_747 ] ;
T_3 V_179 ;
if ( F_200 ( V_8 , V_296 , & V_179 ) ) {
F_393 ( V_296 ) ;
F_394 ( V_8 , 0 ) ;
return 1 ;
}
F_395 ( V_296 , V_179 ) ;
V_8 -> V_110 . V_393 [ V_748 ] = V_179 & - 1u ;
V_8 -> V_110 . V_393 [ V_640 ] = ( V_179 >> 32 ) & - 1u ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_396 ( struct V_7 * V_8 )
{
struct V_371 V_73 ;
T_2 V_296 = V_8 -> V_110 . V_393 [ V_747 ] ;
T_3 V_179 = ( V_8 -> V_110 . V_393 [ V_748 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_110 . V_393 [ V_640 ] & - 1u ) << 32 ) ;
V_73 . V_179 = V_179 ;
V_73 . V_78 = V_296 ;
V_73 . V_374 = false ;
if ( F_202 ( V_8 , & V_73 ) != 0 ) {
F_397 ( V_296 , V_179 ) ;
F_394 ( V_8 , 0 ) ;
return 1 ;
}
F_398 ( V_296 , V_179 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_399 ( struct V_7 * V_8 )
{
F_144 ( V_575 , V_8 ) ;
return 1 ;
}
static int F_400 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_93 ( V_503 ) ;
V_69 &= ~ V_323 ;
F_101 ( V_503 , V_69 ) ;
F_144 ( V_575 , V_8 ) ;
++ V_8 -> V_210 . V_749 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_697 -> V_750 &&
! F_401 ( V_8 ) ) {
V_8 -> V_697 -> V_710 = V_751 ;
return 0 ;
}
return 1 ;
}
static int F_402 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
return F_351 ( V_8 ) ;
}
static int F_403 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
F_404 ( V_8 ) ;
return 1 ;
}
static int F_405 ( struct V_7 * V_8 )
{
return F_350 ( V_8 , 0 ) == V_259 ;
}
static int F_406 ( struct V_7 * V_8 )
{
unsigned long V_728 = F_91 ( V_716 ) ;
F_407 ( V_8 , V_728 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_408 ( struct V_7 * V_8 )
{
int V_737 ;
V_737 = F_409 ( V_8 ) ;
F_377 ( V_8 , V_737 ) ;
return 1 ;
}
static int F_410 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
F_411 ( V_8 ) ;
return 1 ;
}
static int F_412 ( struct V_7 * V_8 )
{
T_3 V_752 = F_413 ( V_8 ) ;
T_2 V_78 = F_375 ( V_8 , V_747 ) ;
if ( F_414 ( V_8 , V_78 , V_752 ) == 0 )
F_163 ( V_8 ) ;
return 1 ;
}
static int F_415 ( struct V_7 * V_8 )
{
if ( F_290 ( V_753 ) ) {
unsigned long V_728 = F_91 ( V_716 ) ;
int V_754 , V_289 ;
V_754 = V_728 & V_755 ;
V_289 = V_728 & V_756 ;
if ( ( V_754 == V_757 ) &&
( V_289 == V_758 ) ) {
F_416 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
}
return F_350 ( V_8 , 0 ) == V_259 ;
}
static int F_417 ( struct V_7 * V_8 )
{
unsigned long V_728 = F_91 ( V_716 ) ;
int V_4 = V_728 & 0xff ;
F_418 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_419 ( struct V_7 * V_8 )
{
unsigned long V_728 = F_91 ( V_716 ) ;
T_2 V_289 = V_728 & 0xfff ;
F_420 ( V_8 , V_289 ) ;
return 1 ;
}
static int F_421 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_728 ;
bool V_252 = false ;
T_2 V_253 = 0 ;
T_4 V_759 ;
int V_760 , type , V_761 , V_762 ;
V_761 = ( V_72 -> V_704 & V_708 ) ;
V_762 = ( V_72 -> V_704 & V_763 ) ;
type = ( V_72 -> V_704 & V_764 ) ;
V_728 = F_91 ( V_716 ) ;
V_760 = ( T_2 ) V_728 >> 30 ;
if ( V_760 == V_765 && V_761 ) {
switch ( type ) {
case V_671 :
V_8 -> V_110 . V_766 = false ;
F_343 ( V_8 , true ) ;
break;
case V_27 :
case V_666 :
F_422 ( V_8 ) ;
break;
case V_23 :
if ( V_72 -> V_704 &
V_767 ) {
V_252 = true ;
V_253 =
F_93 ( V_768 ) ;
}
case V_262 :
F_423 ( V_8 ) ;
break;
default:
break;
}
}
V_759 = V_728 ;
if ( ! V_761 || ( type != V_23 &&
type != V_27 &&
type != V_671 ) )
F_163 ( V_8 ) ;
if ( F_424 ( V_8 , V_759 ,
type == V_666 ? V_762 : - 1 , V_760 ,
V_252 , V_253 ) == V_769 ) {
V_8 -> V_697 -> V_710 = V_711 ;
V_8 -> V_697 -> V_712 . V_713 = V_770 ;
V_8 -> V_697 -> V_712 . V_715 = 0 ;
return 0 ;
}
F_98 ( V_720 , F_91 ( V_720 ) & ~ 55 ) ;
return 1 ;
}
static int F_425 ( struct V_7 * V_8 )
{
unsigned long V_728 ;
T_1 V_84 ;
T_2 V_253 ;
int V_771 ;
V_728 = F_91 ( V_716 ) ;
V_771 = ( V_728 >> 7 ) & 0x3 ;
if ( V_771 != 0x3 && V_771 != 0x1 && V_771 != 0 ) {
F_68 ( V_88 L_21 ) ;
F_68 ( V_88 L_22 ,
( long unsigned int ) F_94 ( V_772 ) ,
F_91 ( V_773 ) ) ;
F_68 ( V_88 L_23 ,
( long unsigned int ) V_728 ) ;
V_8 -> V_697 -> V_710 = V_774 ;
V_8 -> V_697 -> V_775 . V_776 = V_777 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_704 & V_708 ) &&
F_52 () &&
( V_728 & V_778 ) )
F_104 ( V_244 , V_672 ) ;
V_84 = F_94 ( V_772 ) ;
F_359 ( V_84 , V_728 ) ;
V_253 = V_728 & ( 1U << 1 ) ;
V_253 |= ( V_728 & ( 1U << 2 ) ) << 2 ;
V_253 |= ( V_728 >> 3 ) & 0x1 ;
V_8 -> V_110 . V_728 = V_728 ;
return F_362 ( V_8 , V_84 , V_253 , NULL , 0 ) ;
}
static T_3 F_426 ( T_3 V_779 , int V_780 )
{
int V_74 ;
T_3 V_104 = 0 ;
for ( V_74 = 51 ; V_74 > V_429 . V_781 ; V_74 -- )
V_104 |= ( 1ULL << V_74 ) ;
if ( V_780 > 2 )
V_104 |= 0xf8 ;
else if ( V_780 == 2 ) {
if ( V_779 & ( 1ULL << 7 ) )
V_104 |= 0x1ff000 ;
else
V_104 |= 0x78 ;
}
return V_104 ;
}
static void F_427 ( struct V_7 * V_8 , T_3 V_779 ,
int V_780 )
{
F_68 ( V_88 L_24 , V_485 , V_779 , V_780 ) ;
F_428 ( ( V_779 & 0x7 ) == 0x2 ) ;
F_428 ( ( V_779 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_428 ( ( V_779 & 0x7 ) == 0x4 ) ;
if ( ( V_779 & 0x7 ) ) {
T_3 V_782 = V_779 & F_426 ( V_779 , V_780 ) ;
if ( V_782 != 0 ) {
F_68 ( V_88 L_25 ,
V_485 , V_782 ) ;
F_428 ( 1 ) ;
}
if ( V_780 == 1 || ( V_780 == 2 && ( V_779 & ( 1ULL << 7 ) ) ) ) {
T_3 V_783 = ( V_779 & 0x38 ) >> 3 ;
if ( V_783 == 2 || V_783 == 3 ||
V_783 == 7 ) {
F_68 ( V_88 L_26 ,
V_485 , V_783 ) ;
F_428 ( 1 ) ;
}
}
}
}
static int F_429 ( struct V_7 * V_8 )
{
T_3 V_784 [ 4 ] ;
int V_785 , V_74 , V_108 ;
T_1 V_84 ;
V_84 = F_94 ( V_772 ) ;
V_108 = F_430 ( V_8 , V_84 , true ) ;
if ( F_290 ( V_108 == V_786 ) )
return F_431 ( V_8 , V_84 , 0 , NULL , 0 ) ==
V_259 ;
if ( F_99 ( V_108 == V_787 ) )
return F_362 ( V_8 , V_84 , 0 , NULL , 0 ) ;
if ( F_99 ( V_108 == V_788 ) )
return 1 ;
F_68 ( V_88 L_27 ) ;
F_68 ( V_88 L_28 , V_84 ) ;
V_785 = F_432 ( V_8 , V_84 , V_784 ) ;
for ( V_74 = V_789 ; V_74 > V_789 - V_785 ; -- V_74 )
F_427 ( V_8 , V_784 [ V_74 - 1 ] , V_74 ) ;
V_8 -> V_697 -> V_710 = V_774 ;
V_8 -> V_697 -> V_775 . V_776 = V_790 ;
return 0 ;
}
static int F_433 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_93 ( V_503 ) ;
V_69 &= ~ V_324 ;
F_101 ( V_503 , V_69 ) ;
++ V_8 -> V_210 . V_791 ;
F_144 ( V_575 , V_8 ) ;
return 1 ;
}
static int F_434 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
enum V_702 V_737 = V_259 ;
int V_108 = 1 ;
T_2 V_792 ;
bool V_793 ;
unsigned V_794 = 130 ;
V_792 = F_93 ( V_503 ) ;
V_793 = V_792 & V_323 ;
while ( ! F_240 ( V_8 ) && V_794 -- != 0 ) {
if ( V_793 && F_345 ( V_8 ) )
return F_400 ( & V_72 -> V_8 ) ;
if ( F_158 ( V_575 , & V_8 -> V_795 ) )
return 1 ;
V_737 = F_350 ( V_8 , V_796 ) ;
if ( V_737 == V_797 ) {
++ V_8 -> V_210 . V_798 ;
V_108 = 0 ;
goto V_525;
}
if ( V_737 != V_259 ) {
V_8 -> V_697 -> V_710 = V_711 ;
V_8 -> V_697 -> V_712 . V_713 = V_770 ;
V_8 -> V_697 -> V_712 . V_715 = 0 ;
return 0 ;
}
if ( V_8 -> V_110 . V_693 ) {
V_8 -> V_110 . V_693 = 0 ;
V_108 = F_351 ( V_8 ) ;
goto V_525;
}
if ( F_435 ( V_799 ) )
goto V_525;
if ( F_436 () )
F_437 () ;
}
V_72 -> F_239 = F_239 ( V_8 ) ;
V_525:
return V_108 ;
}
static int F_438 ( struct V_7 * V_8 )
{
F_163 ( V_8 ) ;
F_439 ( V_8 ) ;
return 1 ;
}
static int F_440 ( struct V_7 * V_8 )
{
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
static struct V_89 * F_441 ( struct V_6 * V_72 )
{
struct V_800 * V_801 ;
F_79 (item, &vmx->nested.vmcs02_pool, list)
if ( V_801 -> V_802 == V_72 -> V_13 . V_803 ) {
F_442 ( & V_801 -> V_804 , & V_72 -> V_13 . V_805 ) ;
return & V_801 -> V_806 ;
}
if ( V_72 -> V_13 . V_807 >= F_443 ( V_808 , 1 ) ) {
V_801 = F_444 ( V_72 -> V_13 . V_805 . V_809 ,
struct V_800 , V_804 ) ;
V_801 -> V_802 = V_72 -> V_13 . V_803 ;
F_442 ( & V_801 -> V_804 , & V_72 -> V_13 . V_805 ) ;
return & V_801 -> V_806 ;
}
V_801 = F_445 ( sizeof( struct V_800 ) , V_434 ) ;
if ( ! V_801 )
return NULL ;
V_801 -> V_806 . V_86 = F_227 () ;
if ( ! V_801 -> V_806 . V_86 ) {
F_446 ( V_801 ) ;
return NULL ;
}
F_69 ( & V_801 -> V_806 ) ;
V_801 -> V_802 = V_72 -> V_13 . V_803 ;
F_147 ( & ( V_801 -> V_804 ) , & ( V_72 -> V_13 . V_805 ) ) ;
V_72 -> V_13 . V_807 ++ ;
return & V_801 -> V_806 ;
}
static void F_447 ( struct V_6 * V_72 , T_1 V_802 )
{
struct V_800 * V_801 ;
F_79 (item, &vmx->nested.vmcs02_pool, list)
if ( V_801 -> V_802 == V_802 ) {
F_230 ( & V_801 -> V_806 ) ;
F_82 ( & V_801 -> V_804 ) ;
F_446 ( V_801 ) ;
V_72 -> V_13 . V_807 -- ;
return;
}
}
static void F_448 ( struct V_6 * V_72 )
{
struct V_800 * V_801 , * V_405 ;
F_217 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_72 -> V_89 != & V_801 -> V_806 )
F_230 ( & V_801 -> V_806 ) ;
F_82 ( & V_801 -> V_804 ) ;
F_446 ( V_801 ) ;
}
V_72 -> V_13 . V_807 = 0 ;
if ( V_72 -> V_89 != & V_72 -> V_810 )
F_230 ( & V_72 -> V_810 ) ;
}
static void F_449 ( struct V_7 * V_8 )
{
F_160 ( V_8 , F_157 ( V_8 )
& ~ ( V_811 | V_812 | V_813 |
V_814 | V_815 | V_816 ) ) ;
}
static void F_450 ( struct V_7 * V_8 )
{
F_160 ( V_8 , ( F_157 ( V_8 )
& ~ ( V_812 | V_813 | V_814 |
V_815 | V_816 ) )
| V_811 ) ;
}
static void F_451 ( struct V_7 * V_8 ,
T_2 V_817 )
{
if ( F_6 ( V_8 ) -> V_13 . V_803 == - 1ull ) {
F_450 ( V_8 ) ;
return;
}
F_160 ( V_8 , ( F_157 ( V_8 )
& ~ ( V_811 | V_812 | V_813 |
V_815 | V_816 ) )
| V_814 ) ;
F_9 ( V_8 ) -> V_817 = V_817 ;
}
static int F_452 ( struct V_7 * V_8 )
{
struct V_450 V_531 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_86 * V_818 ;
const T_3 V_819 = V_375
| V_399 ;
if ( ! F_453 ( V_8 , V_403 ) ||
! F_152 ( V_8 , V_508 ) ||
( F_157 ( V_8 ) & V_242 ) ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
F_244 ( V_8 , & V_531 , V_452 ) ;
if ( F_129 ( V_8 ) && ! V_531 . V_474 ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_268 ( V_8 ) ) {
F_394 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_520 ) {
F_451 ( V_8 , V_820 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( ( V_72 -> V_13 . V_356 & V_819 )
!= V_819 ) {
F_394 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_438 ) {
V_818 = F_227 () ;
if ( ! V_818 )
return - V_435 ;
V_818 -> V_427 |= ( 1u << 31 ) ;
F_66 ( V_818 ) ;
V_72 -> V_13 . V_821 = V_818 ;
}
F_213 ( & ( V_72 -> V_13 . V_805 ) ) ;
V_72 -> V_13 . V_807 = 0 ;
V_72 -> V_13 . V_520 = true ;
F_163 ( V_8 ) ;
F_449 ( V_8 ) ;
return 1 ;
}
static int F_454 ( struct V_7 * V_8 )
{
struct V_450 V_531 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! V_72 -> V_13 . V_520 ) {
F_352 ( V_8 , V_26 ) ;
return 0 ;
}
F_244 ( V_8 , & V_531 , V_452 ) ;
if ( ( F_157 ( V_8 ) & V_242 ) ||
( F_129 ( V_8 ) && ! V_531 . V_474 ) ) {
F_352 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_268 ( V_8 ) ) {
F_394 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_455 ( struct V_6 * V_72 )
{
T_2 V_603 ;
if ( V_438 ) {
if ( V_72 -> V_13 . V_14 != NULL ) {
F_456 ( V_72 ) ;
V_72 -> V_13 . V_822 = false ;
V_603 = F_93 ( V_615 ) ;
V_603 &= ~ V_67 ;
F_101 ( V_615 , V_603 ) ;
F_102 ( V_613 , - 1ull ) ;
}
}
F_457 ( V_72 -> V_13 . V_823 ) ;
F_13 ( V_72 -> V_13 . V_823 ) ;
}
static void F_458 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_13 . V_520 )
return;
V_72 -> V_13 . V_520 = false ;
if ( V_72 -> V_13 . V_803 != - 1ull ) {
F_455 ( V_72 ) ;
V_72 -> V_13 . V_803 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
if ( V_438 )
F_228 ( V_72 -> V_13 . V_821 ) ;
if ( V_72 -> V_13 . V_561 ) {
F_13 ( V_72 -> V_13 . V_561 ) ;
V_72 -> V_13 . V_561 = 0 ;
}
F_448 ( V_72 ) ;
}
static int F_459 ( struct V_7 * V_8 )
{
if ( ! F_454 ( V_8 ) )
return 1 ;
F_458 ( F_6 ( V_8 ) ) ;
F_163 ( V_8 ) ;
F_449 ( V_8 ) ;
return 1 ;
}
static int F_460 ( struct V_7 * V_8 ,
unsigned long V_728 ,
T_2 V_824 , T_5 * V_108 )
{
int V_825 = V_824 & 3 ;
int V_826 = ( V_824 >> 7 ) & 7 ;
bool V_827 = V_824 & ( 1u << 10 ) ;
int V_828 = ( V_824 >> 15 ) & 7 ;
int V_829 = ( V_824 >> 18 ) & 0xf ;
bool V_830 = ! ( V_824 & ( 1u << 22 ) ) ;
int V_831 = ( V_824 >> 23 ) & 0xf ;
bool V_832 = ! ( V_824 & ( 1u << 27 ) ) ;
if ( V_827 ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
* V_108 = F_267 ( V_8 , V_828 ) ;
if ( V_832 )
* V_108 += F_375 ( V_8 , V_831 ) ;
if ( V_830 )
* V_108 += F_375 ( V_8 , V_829 ) << V_825 ;
* V_108 += V_728 ;
if ( V_826 == 1 )
* V_108 &= 0xffffffff ;
return 0 ;
}
static int F_461 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_802 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
struct V_833 V_834 ;
if ( ! F_454 ( V_8 ) )
return 1 ;
if ( F_460 ( V_8 , F_91 ( V_716 ) ,
F_93 ( V_835 ) , & V_80 ) )
return 1 ;
if ( F_462 ( & V_8 -> V_110 . V_836 , V_80 , & V_802 ,
sizeof( V_802 ) , & V_834 ) ) {
F_463 ( V_8 , & V_834 ) ;
return 1 ;
}
if ( ! F_464 ( V_802 , V_424 ) ) {
F_451 ( V_8 , V_837 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_802 == V_72 -> V_13 . V_803 ) {
F_455 ( V_72 ) ;
V_72 -> V_13 . V_803 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
V_15 = F_10 ( V_8 , V_802 ) ;
if ( V_15 == NULL ) {
F_144 ( V_260 , V_8 ) ;
return 1 ;
}
V_12 = F_465 ( V_15 ) ;
V_12 -> V_838 = 0 ;
F_457 ( V_15 ) ;
F_13 ( V_15 ) ;
F_447 ( V_72 , V_802 ) ;
F_163 ( V_8 ) ;
F_449 ( V_8 ) ;
return 1 ;
}
static int F_466 ( struct V_7 * V_8 )
{
return F_467 ( V_8 , true ) ;
}
static int F_468 ( struct V_7 * V_8 )
{
return F_467 ( V_8 , false ) ;
}
static inline int F_469 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_839 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_470 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_471 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_108 )
{
short V_289 = F_8 ( V_9 ) ;
char * V_113 ;
if ( V_289 < 0 )
return 0 ;
V_113 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_289 ;
switch ( F_469 ( V_9 ) ) {
case V_840 :
* V_108 = * ( ( V_841 * ) V_113 ) ;
return 1 ;
case V_842 :
* V_108 = * ( ( T_4 * ) V_113 ) ;
return 1 ;
case V_839 :
* V_108 = * ( ( T_2 * ) V_113 ) ;
return 1 ;
case V_843 :
* V_108 = * ( ( T_3 * ) V_113 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_472 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_844 ) {
short V_289 = F_8 ( V_9 ) ;
char * V_113 = ( ( char * ) F_9 ( V_8 ) ) + V_289 ;
if ( V_289 < 0 )
return false ;
switch ( F_469 ( V_9 ) ) {
case V_842 :
* ( T_4 * ) V_113 = V_844 ;
return true ;
case V_839 :
* ( T_2 * ) V_113 = V_844 ;
return true ;
case V_843 :
* ( T_3 * ) V_113 = V_844 ;
return true ;
case V_840 :
* ( V_841 * ) V_113 = V_844 ;
return true ;
default:
return false ;
}
}
static void F_456 ( struct V_6 * V_72 )
{
int V_74 ;
unsigned long V_9 ;
T_3 V_844 ;
struct V_86 * V_818 = V_72 -> V_13 . V_821 ;
const unsigned long * V_229 = V_845 ;
const int V_846 = V_847 ;
F_70 ( V_818 ) ;
for ( V_74 = 0 ; V_74 < V_846 ; V_74 ++ ) {
V_9 = V_229 [ V_74 ] ;
switch ( F_469 ( V_9 ) ) {
case V_842 :
V_844 = F_92 ( V_9 ) ;
break;
case V_839 :
V_844 = F_93 ( V_9 ) ;
break;
case V_843 :
V_844 = F_94 ( V_9 ) ;
break;
case V_840 :
V_844 = F_91 ( V_9 ) ;
break;
}
F_472 ( & V_72 -> V_8 , V_9 , V_844 ) ;
}
F_66 ( V_818 ) ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
static void F_473 ( struct V_6 * V_72 )
{
const unsigned long * V_229 [] = {
V_845 ,
V_848
} ;
const int V_849 [] = {
V_847 ,
V_850
} ;
int V_74 , V_851 ;
unsigned long V_9 ;
T_3 V_844 = 0 ;
struct V_86 * V_818 = V_72 -> V_13 . V_821 ;
F_70 ( V_818 ) ;
for ( V_851 = 0 ; V_851 < F_474 ( V_229 ) ; V_851 ++ ) {
for ( V_74 = 0 ; V_74 < V_849 [ V_851 ] ; V_74 ++ ) {
V_9 = V_229 [ V_851 ] [ V_74 ] ;
F_471 ( & V_72 -> V_8 , V_9 , & V_844 ) ;
switch ( F_469 ( V_9 ) ) {
case V_842 :
F_100 ( V_9 , ( T_4 ) V_844 ) ;
break;
case V_839 :
F_101 ( V_9 , ( T_2 ) V_844 ) ;
break;
case V_843 :
F_102 ( V_9 , ( T_3 ) V_844 ) ;
break;
case V_840 :
F_98 ( V_9 , ( long ) V_844 ) ;
break;
}
}
}
F_66 ( V_818 ) ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
static int F_475 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( V_72 -> V_13 . V_803 == - 1ull ) {
F_450 ( V_8 ) ;
F_163 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_476 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_844 ;
unsigned long V_728 = F_91 ( V_716 ) ;
T_2 V_824 = F_93 ( V_835 ) ;
T_5 V_80 = 0 ;
if ( ! F_454 ( V_8 ) ||
! F_475 ( V_8 ) )
return 1 ;
V_9 = F_375 ( V_8 , ( ( ( V_824 ) >> 28 ) & 0xf ) ) ;
if ( ! F_471 ( V_8 , V_9 , & V_844 ) ) {
F_451 ( V_8 , V_852 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_824 & ( 1u << 10 ) ) {
F_380 ( V_8 , ( ( ( V_824 ) >> 3 ) & 0xf ) ,
V_844 ) ;
} else {
if ( F_460 ( V_8 , V_728 ,
V_824 , & V_80 ) )
return 1 ;
F_477 ( & V_8 -> V_110 . V_836 , V_80 ,
& V_844 , ( F_129 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_449 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_478 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_80 ;
unsigned long V_728 = F_91 ( V_716 ) ;
T_2 V_824 = F_93 ( V_835 ) ;
T_3 V_844 = 0 ;
struct V_833 V_834 ;
if ( ! F_454 ( V_8 ) ||
! F_475 ( V_8 ) )
return 1 ;
if ( V_824 & ( 1u << 10 ) )
V_844 = F_375 ( V_8 ,
( ( ( V_824 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_460 ( V_8 , V_728 ,
V_824 , & V_80 ) )
return 1 ;
if ( F_462 ( & V_8 -> V_110 . V_836 , V_80 ,
& V_844 , ( F_129 ( V_8 ) ? 8 : 4 ) , & V_834 ) ) {
F_463 ( V_8 , & V_834 ) ;
return 1 ;
}
}
V_9 = F_375 ( V_8 , ( ( ( V_824 ) >> 28 ) & 0xf ) ) ;
if ( F_470 ( V_9 ) ) {
F_451 ( V_8 ,
V_853 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( ! F_472 ( V_8 , V_9 , V_844 ) ) {
F_451 ( V_8 , V_852 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
F_449 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_479 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_802 ;
struct V_833 V_834 ;
T_2 V_603 ;
if ( ! F_454 ( V_8 ) )
return 1 ;
if ( F_460 ( V_8 , F_91 ( V_716 ) ,
F_93 ( V_835 ) , & V_80 ) )
return 1 ;
if ( F_462 ( & V_8 -> V_110 . V_836 , V_80 , & V_802 ,
sizeof( V_802 ) , & V_834 ) ) {
F_463 ( V_8 , & V_834 ) ;
return 1 ;
}
if ( ! F_464 ( V_802 , V_424 ) ) {
F_451 ( V_8 , V_854 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_803 != V_802 ) {
struct V_12 * V_855 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_802 ) ;
if ( V_15 == NULL ) {
F_450 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
V_855 = F_465 ( V_15 ) ;
if ( V_855 -> V_427 != V_357 ) {
F_457 ( V_15 ) ;
F_15 ( V_15 ) ;
F_451 ( V_8 ,
V_856 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_803 != - 1ull )
F_455 ( V_72 ) ;
V_72 -> V_13 . V_803 = V_802 ;
V_72 -> V_13 . V_14 = V_855 ;
V_72 -> V_13 . V_823 = V_15 ;
if ( V_438 ) {
V_603 = F_93 ( V_615 ) ;
V_603 |= V_67 ;
F_101 ( V_615 , V_603 ) ;
F_102 ( V_613 ,
F_67 ( V_72 -> V_13 . V_821 ) ) ;
V_72 -> V_13 . V_822 = true ;
}
}
F_449 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_480 ( struct V_7 * V_8 )
{
unsigned long V_728 = F_91 ( V_716 ) ;
T_2 V_824 = F_93 ( V_835 ) ;
T_5 V_857 ;
struct V_833 V_834 ;
if ( ! F_454 ( V_8 ) )
return 1 ;
if ( F_460 ( V_8 , V_728 ,
V_824 , & V_857 ) )
return 1 ;
if ( F_477 ( & V_8 -> V_110 . V_836 , V_857 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_803 ,
sizeof( T_3 ) , & V_834 ) ) {
F_463 ( V_8 , & V_834 ) ;
return 1 ;
}
F_449 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
}
static int F_481 ( struct V_7 * V_8 )
{
T_2 V_824 , V_858 ;
unsigned long type ;
T_5 V_80 ;
struct V_833 V_834 ;
struct {
T_3 V_83 , V_84 ;
} V_82 ;
T_3 V_859 = ( ( 1ull << 51 ) - 1 ) & V_513 ;
if ( ! ( V_341 & V_55 ) ||
! ( V_342 & V_343 ) ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
if ( ! F_454 ( V_8 ) )
return 1 ;
if ( ! F_152 ( V_8 , V_508 ) ) {
F_352 ( V_8 , V_26 ) ;
return 1 ;
}
V_824 = F_93 ( V_835 ) ;
type = F_375 ( V_8 , ( V_824 >> 28 ) & 0xf ) ;
V_858 = ( V_342 >> V_860 ) & 6 ;
if ( ! ( V_858 & ( 1UL << type ) ) ) {
F_451 ( V_8 ,
V_861 ) ;
return 1 ;
}
if ( F_460 ( V_8 , F_91 ( V_716 ) ,
V_824 , & V_80 ) )
return 1 ;
if ( F_462 ( & V_8 -> V_110 . V_836 , V_80 , & V_82 ,
sizeof( V_82 ) , & V_834 ) ) {
F_463 ( V_8 , & V_834 ) ;
return 1 ;
}
switch ( type ) {
case V_101 :
if ( ( V_82 . V_83 & V_859 ) !=
( F_482 ( V_8 ) & V_859 ) )
break;
case V_99 :
F_483 ( V_8 ) ;
F_484 ( V_8 ) ;
F_449 ( V_8 ) ;
break;
default:
F_358 ( 1 ) ;
break;
}
F_163 ( V_8 ) ;
return 1 ;
}
static bool F_485 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_728 ;
T_1 V_862 , V_863 ;
unsigned int V_730 ;
int V_425 ;
T_6 V_864 ;
if ( F_57 ( V_12 , V_333 ) )
return 1 ;
if ( ! F_57 ( V_12 , V_334 ) )
return 0 ;
V_728 = F_91 ( V_716 ) ;
V_730 = V_728 >> 16 ;
V_425 = ( V_728 & 7 ) + 1 ;
V_863 = ( T_1 ) - 1 ;
V_864 = - 1 ;
while ( V_425 > 0 ) {
if ( V_730 < 0x8000 )
V_862 = V_12 -> V_865 ;
else if ( V_730 < 0x10000 )
V_862 = V_12 -> V_866 ;
else
return 1 ;
V_862 += ( V_730 & 0x7fff ) / 8 ;
if ( V_863 != V_862 )
if ( F_486 ( V_8 -> V_17 , V_862 , & V_864 , 1 ) )
return 1 ;
if ( V_864 & ( 1 << ( V_730 & 7 ) ) )
return 1 ;
V_730 ++ ;
V_425 -- ;
V_863 = V_862 ;
}
return 0 ;
}
static bool F_487 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_710 )
{
T_2 V_350 = V_8 -> V_110 . V_393 [ V_747 ] ;
T_1 V_862 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_862 = V_12 -> V_267 ;
if ( V_710 == V_867 )
V_862 += 2048 ;
if ( V_350 >= 0xc0000000 ) {
V_350 -= 0xc0000000 ;
V_862 += 1024 ;
}
if ( V_350 < 1024 * 8 ) {
unsigned char V_864 ;
if ( F_486 ( V_8 -> V_17 , V_862 + V_350 / 8 , & V_864 , 1 ) )
return 1 ;
return 1 & ( V_864 >> ( V_350 & 7 ) ) ;
} else
return 1 ;
}
static bool F_488 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_728 = F_91 ( V_716 ) ;
int V_736 = V_728 & 15 ;
int V_391 = ( V_728 >> 8 ) & 15 ;
unsigned long V_733 = F_375 ( V_8 , V_391 ) ;
switch ( ( V_728 >> 4 ) & 3 ) {
case 0 :
switch ( V_736 ) {
case 0 :
if ( V_12 -> V_227 &
( V_733 ^ V_12 -> V_231 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_868 >= 1 &&
V_12 -> V_869 == V_733 ) ||
( V_12 -> V_868 >= 2 &&
V_12 -> V_870 == V_733 ) ||
( V_12 -> V_868 >= 3 &&
V_12 -> V_871 == V_733 ) ||
( V_12 -> V_868 >= 4 &&
V_12 -> V_872 == V_733 ) )
return 0 ;
if ( F_57 ( V_12 , V_328 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_233 &
( V_12 -> V_234 ^ V_733 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_330 ) )
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
switch ( V_736 ) {
case 3 :
if ( V_12 -> V_69 &
V_329 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_331 )
return 1 ;
break;
}
break;
case 3 :
if ( V_12 -> V_227 & 0xe &
( V_733 ^ V_12 -> V_231 ) )
return 1 ;
if ( ( V_12 -> V_227 & 0x1 ) &&
! ( V_12 -> V_231 & 0x1 ) &&
( V_733 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_489 ( struct V_7 * V_8 )
{
T_2 V_19 = F_93 ( V_873 ) ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_710 = V_72 -> V_710 ;
if ( V_72 -> V_13 . V_674 )
return 0 ;
if ( F_99 ( V_72 -> V_874 ) ) {
F_490 ( L_29 , V_485 ,
F_93 ( V_103 ) ) ;
return 1 ;
}
switch ( V_710 ) {
case V_676 :
if ( ! F_61 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_100 ;
else if ( F_18 ( V_19 ) &&
! ( F_153 ( V_12 ) & V_224 ) )
return 0 ;
return V_12 -> V_133 &
( 1u << ( V_19 & V_21 ) ) ;
case V_679 :
return 0 ;
case V_875 :
return 1 ;
case V_876 :
return F_57 ( V_12 , V_323 ) ;
case V_877 :
return F_57 ( V_12 , V_324 ) ;
case V_878 :
return 1 ;
case V_879 :
return 1 ;
case V_880 :
return F_57 ( V_12 , V_325 ) ;
case V_881 :
return 1 ;
case V_882 :
return F_57 ( V_12 , V_326 ) ;
case V_883 :
return F_57 ( V_12 , V_336 ) ;
case V_884 :
return F_57 ( V_12 , V_337 ) ;
case V_885 : case V_886 :
case V_887 : case V_888 :
case V_889 : case V_890 :
case V_891 : case V_892 :
case V_893 : case V_894 :
case V_895 :
return 1 ;
case V_896 :
return F_488 ( V_8 , V_12 ) ;
case V_897 :
return F_57 ( V_12 , V_332 ) ;
case V_898 :
return F_485 ( V_8 , V_12 ) ;
case V_899 :
case V_867 :
return F_487 ( V_8 , V_12 , V_710 ) ;
case V_900 :
return 1 ;
case V_901 :
return F_57 ( V_12 , V_327 ) ;
case V_902 :
return F_57 ( V_12 , V_335 ) ;
case V_903 :
return F_57 ( V_12 , V_338 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_904 :
return 0 ;
case V_905 :
return 1 ;
case V_906 :
return F_58 ( V_12 ,
V_35 ) ;
case V_777 :
return 0 ;
case V_790 :
return 0 ;
case V_907 :
return V_12 -> V_71 &
V_304 ;
case V_908 :
return F_58 ( V_12 , V_63 ) ;
case V_909 :
return 1 ;
default:
return 1 ;
}
}
static void F_491 ( struct V_7 * V_8 , T_3 * V_910 , T_3 * V_911 )
{
* V_910 = F_91 ( V_716 ) ;
* V_911 = F_93 ( V_873 ) ;
}
static void F_492 ( struct V_7 * V_8 )
{
T_3 V_912 ;
T_2 V_913 , V_914 , V_915 ;
if ( ! ( F_9 ( V_8 ) -> V_71 &
V_304 ) )
return;
V_915 = F_493 ( V_65 ) &
V_916 ;
V_914 = F_93 ( V_917 ) ;
V_912 = F_179 ( V_8 , F_187 () )
- V_8 -> V_110 . V_918 ;
V_913 = V_912 >> V_915 ;
if ( V_914 <= V_913 )
V_914 = 0 ;
else
V_914 -= V_913 ;
F_101 ( V_917 , V_914 ) ;
}
static int F_494 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_710 = V_72 -> V_710 ;
T_2 V_919 = V_72 -> V_704 ;
if ( V_72 -> F_239 )
return F_434 ( V_8 ) ;
if ( F_112 ( V_8 ) && F_489 ( V_8 ) ) {
F_167 ( V_8 ) ;
return 1 ;
}
if ( V_710 & V_920 ) {
V_8 -> V_697 -> V_710 = V_921 ;
V_8 -> V_697 -> V_922 . V_923
= V_710 ;
return 0 ;
}
if ( F_99 ( V_72 -> V_874 ) ) {
V_8 -> V_697 -> V_710 = V_921 ;
V_8 -> V_697 -> V_922 . V_923
= F_93 ( V_103 ) ;
return 0 ;
}
if ( ( V_919 & V_708 ) &&
( V_710 != V_676 &&
V_710 != V_777 &&
V_710 != V_878 ) ) {
V_8 -> V_697 -> V_710 = V_711 ;
V_8 -> V_697 -> V_712 . V_713 = V_924 ;
V_8 -> V_697 -> V_712 . V_715 = 2 ;
V_8 -> V_697 -> V_712 . V_179 [ 0 ] = V_919 ;
V_8 -> V_697 -> V_712 . V_179 [ 1 ] = V_710 ;
return 0 ;
}
if ( F_99 ( ! F_52 () && V_72 -> V_639 &&
! ( F_112 ( V_8 ) && F_59 (
F_9 ( V_8 ) ) ) ) ) {
if ( F_345 ( V_8 ) ) {
V_72 -> V_639 = 0 ;
} else if ( V_72 -> V_667 > 1000000000LL &&
V_8 -> V_110 . V_678 ) {
F_68 ( V_162 L_30
L_31 ,
V_485 , V_8 -> V_291 ) ;
V_72 -> V_639 = 0 ;
}
}
if ( V_710 < V_925
&& V_926 [ V_710 ] )
return V_926 [ V_710 ] ( V_8 ) ;
else {
V_8 -> V_697 -> V_710 = V_774 ;
V_8 -> V_697 -> V_775 . V_776 = V_710 ;
}
return 0 ;
}
static void V_442 ( struct V_7 * V_8 , int V_927 , int V_928 )
{
if ( V_928 == - 1 || V_927 < V_928 ) {
F_101 ( V_655 , 0 ) ;
return;
}
F_101 ( V_655 , V_928 ) ;
}
static void F_495 ( struct V_7 * V_8 , bool V_929 )
{
T_2 V_930 ;
if ( ! F_28 () ||
! F_308 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_930 = F_93 ( V_615 ) ;
if ( V_929 ) {
V_930 &= ~ V_35 ;
V_930 |= V_36 ;
} else {
V_930 &= ~ V_36 ;
V_930 |= V_35 ;
}
F_101 ( V_615 , V_930 ) ;
F_174 ( V_8 ) ;
}
static void F_496 ( struct V_17 * V_17 , int V_931 )
{
T_4 V_932 ;
T_6 V_401 ;
if ( ! F_308 ( V_17 ) )
return;
if ( V_931 == - 1 )
V_931 = 0 ;
V_932 = F_92 ( V_620 ) ;
V_401 = V_932 >> 8 ;
if ( V_931 != V_401 ) {
V_932 &= 0xff ;
V_932 |= V_931 << 8 ;
F_100 ( V_620 , V_932 ) ;
}
}
static void F_497 ( int V_4 )
{
T_4 V_932 ;
T_6 V_401 ;
V_932 = F_92 ( V_620 ) ;
V_401 = ( T_6 ) V_932 & 0xff ;
if ( ( T_6 ) V_4 != V_401 ) {
V_932 &= ~ 0xff ;
V_932 |= ( T_6 ) V_4 ;
F_100 ( V_620 , V_932 ) ;
}
}
static void F_498 ( struct V_7 * V_8 , int V_933 )
{
if ( V_933 == - 1 )
return;
F_497 ( V_933 ) ;
}
static void F_499 ( struct V_7 * V_8 , T_3 * V_934 )
{
if ( ! F_308 ( V_8 -> V_17 ) )
return;
F_102 ( V_616 , V_934 [ 0 ] ) ;
F_102 ( V_617 , V_934 [ 1 ] ) ;
F_102 ( V_618 , V_934 [ 2 ] ) ;
F_102 ( V_619 , V_934 [ 3 ] ) ;
}
static void F_500 ( struct V_6 * V_72 )
{
T_2 V_705 ;
if ( ! ( V_72 -> V_710 == V_904
|| V_72 -> V_710 == V_676 ) )
return;
V_72 -> V_705 = F_93 ( V_873 ) ;
V_705 = V_72 -> V_705 ;
if ( F_21 ( V_705 ) )
F_353 () ;
if ( ( V_705 & V_20 ) == V_671 &&
( V_705 & V_22 ) ) {
F_501 ( & V_72 -> V_8 ) ;
asm("int $2");
F_502 ( & V_72 -> V_8 ) ;
}
}
static void F_503 ( struct V_7 * V_8 )
{
T_2 V_705 = F_93 ( V_873 ) ;
if ( ( V_705 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_135 ;
T_16 * V_935 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
#ifdef F_95
unsigned long V_266 ;
#endif
V_4 = V_705 & V_21 ;
V_935 = ( T_16 * ) V_72 -> V_594 + V_4 ;
V_135 = F_504 ( * V_935 ) ;
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
static void F_505 ( struct V_6 * V_72 )
{
T_2 V_705 ;
bool V_936 ;
T_6 V_4 ;
bool V_937 ;
V_937 = V_72 -> V_704 & V_708 ;
if ( F_52 () ) {
if ( V_72 -> V_669 )
return;
V_705 = F_93 ( V_873 ) ;
V_936 = ( V_705 & V_778 ) != 0 ;
V_4 = V_705 & V_21 ;
if ( ( V_705 & V_22 ) && V_936 &&
V_4 != V_689 && ! V_937 )
F_104 ( V_244 ,
V_672 ) ;
else
V_72 -> V_669 =
! ( F_93 ( V_244 )
& V_672 ) ;
} else if ( F_99 ( V_72 -> V_639 ) )
V_72 -> V_667 +=
F_506 ( F_507 ( F_508 () , V_72 -> V_938 ) ) ;
}
static void F_509 ( struct V_7 * V_8 ,
T_2 V_704 ,
int V_939 ,
int V_940 )
{
T_6 V_4 ;
int type ;
bool V_937 ;
V_937 = V_704 & V_708 ;
V_8 -> V_110 . V_766 = false ;
F_423 ( V_8 ) ;
F_422 ( V_8 ) ;
if ( ! V_937 )
return;
F_144 ( V_575 , V_8 ) ;
V_4 = V_704 & V_763 ;
type = V_704 & V_764 ;
switch ( type ) {
case V_671 :
V_8 -> V_110 . V_766 = true ;
F_343 ( V_8 , false ) ;
break;
case V_262 :
V_8 -> V_110 . V_258 = F_93 ( V_939 ) ;
case V_23 :
if ( V_704 & V_767 ) {
T_2 V_737 = F_93 ( V_940 ) ;
F_510 ( V_8 , V_4 , V_737 ) ;
} else
F_511 ( V_8 , V_4 ) ;
break;
case V_666 :
V_8 -> V_110 . V_258 = F_93 ( V_939 ) ;
case V_27 :
F_512 ( V_8 , V_4 , type == V_666 ) ;
break;
default:
break;
}
}
static void F_513 ( struct V_6 * V_72 )
{
F_509 ( & V_72 -> V_8 , V_72 -> V_704 ,
V_251 ,
V_768 ) ;
}
static void F_514 ( struct V_7 * V_8 )
{
F_509 ( V_8 ,
F_93 ( V_263 ) ,
V_261 ,
V_255 ) ;
F_101 ( V_263 , 0 ) ;
}
static void F_515 ( struct V_6 * V_72 )
{
int V_74 , V_941 ;
struct V_942 * V_943 ;
V_943 = F_516 ( & V_941 ) ;
if ( ! V_943 )
return;
for ( V_74 = 0 ; V_74 < V_941 ; V_74 ++ )
if ( V_943 [ V_74 ] . V_150 == V_943 [ V_74 ] . V_149 )
F_114 ( V_72 , V_943 [ V_74 ] . V_73 ) ;
else
F_116 ( V_72 , V_943 [ V_74 ] . V_73 , V_943 [ V_74 ] . V_149 ,
V_943 [ V_74 ] . V_150 ) ;
}
static void T_17 F_517 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_944 ;
if ( F_99 ( ! F_52 () && V_72 -> V_639 ) )
V_72 -> V_938 = F_508 () ;
if ( V_72 -> F_239 )
return;
if ( V_72 -> V_13 . V_822 ) {
F_473 ( V_72 ) ;
V_72 -> V_13 . V_822 = false ;
}
if ( F_158 ( V_392 , ( unsigned long * ) & V_8 -> V_110 . V_495 ) )
F_98 ( V_394 , V_8 -> V_110 . V_393 [ V_392 ] ) ;
if ( F_158 ( V_395 , ( unsigned long * ) & V_8 -> V_110 . V_495 ) )
F_98 ( V_396 , V_8 -> V_110 . V_393 [ V_395 ] ) ;
if ( V_8 -> V_126 & V_684 )
F_162 ( V_8 , 0 ) ;
F_515 ( V_72 ) ;
V_944 = F_518 () ;
if ( F_112 ( V_8 ) && ! V_72 -> V_13 . V_674 )
F_492 ( V_8 ) ;
V_72 -> V_945 = V_72 -> V_89 -> V_91 ;
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
if ( V_944 )
F_519 ( V_944 ) ;
#ifndef F_95
F_135 ( V_198 , V_946 ) ;
F_135 ( V_200 , V_946 ) ;
#endif
V_8 -> V_110 . V_111 = ~ ( ( 1 << V_395 ) | ( 1 << V_392 )
| ( 1 << V_238 )
| ( 1 << V_466 )
| ( 1 << V_397 )
| ( 1 << V_112 )
| ( 1 << V_490 ) ) ;
V_8 -> V_110 . V_495 = 0 ;
V_72 -> V_704 = F_93 ( V_947 ) ;
V_72 -> V_89 -> V_91 = 1 ;
V_72 -> V_710 = F_93 ( V_948 ) ;
F_520 ( V_72 -> V_710 , V_8 , V_949 ) ;
if ( V_72 -> V_13 . V_674 )
F_144 ( V_575 , V_8 ) ;
V_72 -> V_13 . V_674 = 0 ;
F_500 ( V_72 ) ;
F_505 ( V_72 ) ;
F_513 ( V_72 ) ;
}
static void F_521 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_301 ( V_72 ) ;
F_458 ( V_72 ) ;
F_230 ( V_72 -> V_89 ) ;
F_446 ( V_72 -> V_77 ) ;
F_522 ( V_8 ) ;
F_523 ( V_950 , V_72 ) ;
}
static struct V_7 * F_524 ( struct V_17 * V_17 , unsigned int V_951 )
{
int V_737 ;
struct V_6 * V_72 = F_525 ( V_950 , V_434 ) ;
int V_90 ;
if ( ! V_72 )
return F_526 ( - V_435 ) ;
F_297 ( V_72 ) ;
V_737 = F_527 ( & V_72 -> V_8 , V_17 , V_951 ) ;
if ( V_737 )
goto V_952;
V_72 -> V_77 = F_445 ( V_424 , V_434 ) ;
V_737 = - V_435 ;
if ( ! V_72 -> V_77 ) {
goto V_953;
}
V_72 -> V_89 = & V_72 -> V_810 ;
V_72 -> V_89 -> V_86 = F_227 () ;
if ( ! V_72 -> V_89 -> V_86 )
goto V_954;
if ( ! V_214 )
F_143 ( F_67 ( F_81 ( V_213 , F_78 () ) ) ) ;
F_69 ( V_72 -> V_89 ) ;
if ( ! V_214 )
F_150 () ;
V_90 = F_528 () ;
F_142 ( & V_72 -> V_8 , V_90 ) ;
V_72 -> V_8 . V_90 = V_90 ;
V_737 = F_325 ( V_72 ) ;
F_149 ( & V_72 -> V_8 ) ;
F_529 () ;
if ( V_737 )
goto F_228;
if ( F_48 ( V_17 ) ) {
V_737 = F_292 ( V_17 ) ;
if ( V_737 )
goto F_228;
}
if ( V_100 ) {
if ( ! V_17 -> V_110 . V_516 )
V_17 -> V_110 . V_516 =
V_955 ;
V_737 = - V_435 ;
if ( F_296 ( V_17 ) != 0 )
goto F_228;
if ( ! F_289 ( V_17 ) )
goto F_228;
}
V_72 -> V_13 . V_803 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
return & V_72 -> V_8 ;
F_228:
F_230 ( V_72 -> V_89 ) ;
V_954:
F_446 ( V_72 -> V_77 ) ;
V_953:
F_522 ( & V_72 -> V_8 ) ;
V_952:
F_301 ( V_72 ) ;
F_523 ( V_950 , V_72 ) ;
return F_526 ( V_737 ) ;
}
static void T_11 F_530 ( void * V_956 )
{
struct V_29 V_413 ;
* ( int * ) V_956 = 0 ;
if ( F_221 ( & V_413 ) < 0 )
* ( int * ) V_956 = - V_412 ;
if ( memcmp ( & V_29 , & V_413 , sizeof( struct V_29 ) ) != 0 ) {
F_68 ( V_88 L_32 ,
F_531 () ) ;
* ( int * ) V_956 = - V_412 ;
}
}
static int F_532 ( void )
{
return V_510 + 1 ;
}
static T_3 F_533 ( struct V_7 * V_8 , T_13 V_957 , bool V_958 )
{
T_3 V_108 ;
if ( V_958 )
V_108 = V_959 << V_960 ;
else if ( F_534 ( V_8 -> V_17 ) )
V_108 = F_535 ( V_8 , V_957 ) <<
V_960 ;
else
V_108 = ( V_961 << V_960 )
| V_962 ;
return V_108 ;
}
static int F_536 ( void )
{
if ( V_100 && ! F_38 () )
return V_963 ;
else
return V_964 ;
}
static void F_537 ( struct V_7 * V_8 )
{
struct V_294 * V_295 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_603 ;
V_72 -> V_278 = false ;
if ( F_171 () ) {
V_603 = F_93 ( V_615 ) ;
if ( V_603 & V_60 ) {
V_295 = F_189 ( V_8 , 0x80000001 , 0 ) ;
if ( V_295 && ( V_295 -> V_965 & V_68 ( V_966 ) ) )
V_72 -> V_278 = true ;
else {
V_603 &= ~ V_60 ;
F_101 ( V_615 ,
V_603 ) ;
}
}
}
V_295 = F_189 ( V_8 , 0x7 , 0 ) ;
if ( F_172 () &&
V_295 && ( V_295 -> V_967 & V_68 ( V_968 ) ) &&
F_538 ( V_8 ) ) {
V_603 = F_93 ( V_615 ) ;
V_603 |= V_61 ;
F_101 ( V_615 ,
V_603 ) ;
} else {
if ( F_26 () ) {
V_603 = F_93 ( V_615 ) ;
V_603 &= ~ V_61 ;
F_101 ( V_615 ,
V_603 ) ;
}
if ( V_295 )
V_295 -> V_967 &= ~ V_68 ( V_968 ) ;
}
}
static void F_539 ( T_2 V_969 , struct V_294 * V_135 )
{
if ( V_969 == 1 && V_13 )
V_135 -> V_296 |= V_68 ( V_297 ) ;
}
static void F_540 ( struct V_7 * V_8 ,
struct V_833 * V_970 )
{
struct V_12 * V_12 ;
F_167 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_970 -> V_253 & V_709 )
V_12 -> V_675 = V_790 ;
else
V_12 -> V_675 = V_777 ;
V_12 -> V_728 = V_8 -> V_110 . V_728 ;
V_12 -> V_971 = V_970 -> V_168 ;
}
static unsigned long F_482 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_972 ;
}
static void F_541 ( struct V_7 * V_8 )
{
F_542 ( V_8 , & V_8 -> V_110 . V_486 ,
V_342 & V_43 ) ;
V_8 -> V_110 . V_486 . V_973 = F_265 ;
V_8 -> V_110 . V_486 . V_974 = F_482 ;
V_8 -> V_110 . V_486 . V_975 = F_540 ;
V_8 -> V_110 . V_494 = & V_8 -> V_110 . V_976 ;
}
static void F_543 ( struct V_7 * V_8 )
{
V_8 -> V_110 . V_494 = & V_8 -> V_110 . V_486 ;
}
static void F_544 ( struct V_7 * V_8 ,
struct V_833 * V_970 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_428 ( ! F_112 ( V_8 ) ) ;
if ( V_12 -> V_133 & ( 1u << V_24 ) )
F_167 ( V_8 ) ;
else
F_463 ( V_8 , V_970 ) ;
}
static void F_545 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_603 ;
T_2 V_977 ;
F_100 ( V_978 , V_12 -> V_979 ) ;
F_100 ( V_643 , V_12 -> V_980 ) ;
F_100 ( V_981 , V_12 -> V_982 ) ;
F_100 ( V_983 , V_12 -> V_984 ) ;
F_100 ( V_985 , V_12 -> V_986 ) ;
F_100 ( V_987 , V_12 -> V_988 ) ;
F_100 ( V_646 , V_12 -> V_989 ) ;
F_100 ( V_645 , V_12 -> V_990 ) ;
F_101 ( V_991 , V_12 -> V_992 ) ;
F_101 ( V_993 , V_12 -> V_994 ) ;
F_101 ( V_995 , V_12 -> V_996 ) ;
F_101 ( V_997 , V_12 -> V_998 ) ;
F_101 ( V_999 , V_12 -> V_1000 ) ;
F_101 ( V_1001 , V_12 -> V_1002 ) ;
F_101 ( V_648 , V_12 -> V_1003 ) ;
F_101 ( V_479 , V_12 -> V_1004 ) ;
F_101 ( V_529 , V_12 -> V_1005 ) ;
F_101 ( V_527 , V_12 -> V_1006 ) ;
F_101 ( V_1007 , V_12 -> V_1008 ) ;
F_101 ( V_1009 , V_12 -> V_1010 ) ;
F_101 ( V_1011 , V_12 -> V_1012 ) ;
F_101 ( V_1013 , V_12 -> V_1014 ) ;
F_101 ( V_1015 , V_12 -> V_1016 ) ;
F_101 ( V_1017 , V_12 -> V_1018 ) ;
F_101 ( V_649 , V_12 -> V_1019 ) ;
F_101 ( V_481 , V_12 -> V_1020 ) ;
F_98 ( V_1021 , V_12 -> V_1022 ) ;
F_98 ( V_644 , V_12 -> V_1023 ) ;
F_98 ( V_1024 , V_12 -> V_1025 ) ;
F_98 ( V_1026 , V_12 -> V_1027 ) ;
F_98 ( V_377 , V_12 -> V_1028 ) ;
F_98 ( V_378 , V_12 -> V_1029 ) ;
F_98 ( V_647 , V_12 -> V_1030 ) ;
F_98 ( V_478 , V_12 -> V_1031 ) ;
F_98 ( V_530 , V_12 -> V_1032 ) ;
F_98 ( V_528 , V_12 -> V_1033 ) ;
F_102 ( V_653 , V_12 -> V_1034 ) ;
F_101 ( V_263 ,
V_12 -> V_1035 ) ;
F_101 ( V_255 ,
V_12 -> V_1036 ) ;
F_101 ( V_261 ,
V_12 -> V_1037 ) ;
F_101 ( V_244 ,
V_12 -> V_1038 ) ;
F_101 ( V_381 , V_12 -> V_1039 ) ;
F_388 ( V_8 , 7 , V_12 -> V_1040 ) ;
F_160 ( V_8 , V_12 -> V_1041 ) ;
F_98 ( V_652 ,
V_12 -> V_1042 ) ;
F_98 ( V_384 , V_12 -> V_1043 ) ;
F_98 ( V_383 , V_12 -> V_1044 ) ;
F_102 ( V_613 , - 1ull ) ;
F_101 ( V_614 ,
( V_29 . V_39 |
V_12 -> V_71 ) ) ;
if ( V_12 -> V_71 & V_304 )
F_101 ( V_917 ,
V_12 -> V_1045 ) ;
F_101 ( V_626 ,
V_100 ? V_12 -> V_1046 : 0 ) ;
F_101 ( V_627 ,
V_100 ? V_12 -> V_1047 : 0 ) ;
if ( F_26 () ) {
T_2 V_603 = F_322 ( V_72 ) ;
if ( ! V_72 -> V_278 )
V_603 &= ~ V_60 ;
V_603 &= ~ V_35 ;
if ( F_57 ( V_12 ,
V_33 ) )
V_603 |= V_12 -> V_70 ;
if ( V_603 & V_35 ) {
if ( V_72 -> V_13 . V_561 )
F_13 ( V_72 -> V_13 . V_561 ) ;
V_72 -> V_13 . V_561 =
F_10 ( V_8 , V_12 -> V_1048 ) ;
if ( ! V_72 -> V_13 . V_561 )
V_603 &=
~ V_35 ;
else
F_102 ( V_656 ,
F_333 ( V_72 -> V_13 . V_561 ) ) ;
}
F_101 ( V_615 , V_603 ) ;
}
F_315 ( V_72 ) ;
V_72 -> V_1049 = 0 ;
V_603 = F_321 ( V_72 ) ;
V_603 &= ~ V_323 ;
V_603 &= ~ V_324 ;
V_603 &= ~ V_32 ;
V_603 |= V_12 -> V_69 ;
V_603 &= ~ V_31 ;
V_603 &= ~ V_334 ;
V_603 |= V_333 ;
F_101 ( V_503 , V_603 ) ;
F_111 ( V_8 ) ;
V_8 -> V_110 . V_226 &= ~ V_12 -> V_227 ;
F_98 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
V_977 = V_29 . V_428 ;
if ( V_12 -> V_71 & V_304 )
V_977 |= V_312 ;
F_101 ( V_137 , V_977 ) ;
F_101 ( V_136 ,
( V_12 -> V_1050 & ~ V_142 &
~ V_318 ) |
( V_29 . V_386 & ~ V_318 ) ) ;
if ( V_12 -> V_1050 & V_319 ) {
F_102 ( V_387 , V_12 -> V_1051 ) ;
V_8 -> V_110 . V_388 = V_12 -> V_1051 ;
} else if ( V_29 . V_386 & V_319 )
F_102 ( V_387 , V_72 -> V_8 . V_110 . V_388 ) ;
F_319 ( V_72 ) ;
if ( V_12 -> V_69 & V_290 )
F_102 ( V_282 ,
V_72 -> V_13 . V_283 + V_12 -> V_281 ) ;
else
F_102 ( V_282 , V_72 -> V_13 . V_283 ) ;
if ( V_437 ) {
F_100 ( V_657 , V_72 -> V_52 ) ;
F_253 ( V_8 ) ;
}
if ( F_60 ( V_12 ) ) {
F_546 ( V_8 ) ;
F_541 ( V_8 ) ;
}
if ( V_12 -> V_1050 & V_142 )
V_8 -> V_110 . V_173 = V_12 -> V_1052 ;
else if ( V_12 -> V_1050 & V_318 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_249 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_264 ( V_8 , V_12 -> V_230 ) ;
F_98 ( V_235 , F_153 ( V_12 ) ) ;
F_262 ( V_8 , V_12 -> V_232 ) ;
F_98 ( V_465 , F_154 ( V_12 ) ) ;
F_378 ( V_8 , V_12 -> V_514 ) ;
F_248 ( V_8 ) ;
if ( ! V_100 )
V_8 -> V_110 . V_494 -> V_975 = F_544 ;
if ( V_100 ) {
F_102 ( V_496 , V_12 -> V_1053 ) ;
F_102 ( V_498 , V_12 -> V_1054 ) ;
F_102 ( V_499 , V_12 -> V_1055 ) ;
F_102 ( V_500 , V_12 -> V_1056 ) ;
}
F_380 ( V_8 , V_392 , V_12 -> V_1057 ) ;
F_380 ( V_8 , V_395 , V_12 -> V_1058 ) ;
}
static int F_467 ( struct V_7 * V_8 , bool V_1059 )
{
struct V_12 * V_12 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_89 * V_806 ;
bool V_1060 ;
if ( ! F_454 ( V_8 ) ||
! F_475 ( V_8 ) )
return 1 ;
F_163 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_438 )
F_456 ( V_72 ) ;
if ( V_12 -> V_838 == V_1059 ) {
F_451 ( V_8 ,
V_1059 ? V_1061
: V_1062 ) ;
return 1 ;
}
if ( V_12 -> V_1063 != V_651 ) {
F_451 ( V_8 , V_1064 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_464 ( V_12 -> V_267 , V_424 ) ) {
F_451 ( V_8 , V_1064 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_464 ( V_12 -> V_1048 , V_424 ) ) {
F_451 ( V_8 , V_1064 ) ;
return 1 ;
}
if ( V_12 -> V_1065 > 0 ||
V_12 -> V_1066 > 0 ||
V_12 -> V_1067 > 0 ) {
F_547 ( L_33 ,
V_485 ) ;
F_451 ( V_8 , V_1064 ) ;
return 1 ;
}
if ( ! F_193 ( V_12 -> V_69 ,
V_321 , V_322 ) ||
! F_193 ( V_12 -> V_70 ,
V_340 , V_341 ) ||
! F_193 ( V_12 -> V_71 ,
V_299 , V_300 ) ||
! F_193 ( V_12 -> V_1068 ,
V_306 , V_307 ) ||
! F_193 ( V_12 -> V_1050 ,
V_315 , V_316 ) )
{
F_451 ( V_8 , V_1064 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1069 & F_197 ) != F_197 ) ||
( ( V_12 -> V_1070 & F_198 ) != F_198 ) ) {
F_451 ( V_8 ,
V_1071 ) ;
return 1 ;
}
if ( ! F_368 ( V_12 , V_12 -> V_230 ) ||
( ( V_12 -> V_232 & F_198 ) != F_198 ) ) {
F_548 ( V_8 , V_12 ,
V_900 , V_1072 ) ;
return 1 ;
}
if ( V_12 -> V_1073 != - 1ull ) {
F_548 ( V_8 , V_12 ,
V_900 , V_1074 ) ;
return 1 ;
}
if ( V_12 -> V_1050 & V_142 ) {
V_1060 = ( V_12 -> V_1050 & V_318 ) != 0 ;
if ( ! F_549 ( V_8 , V_12 -> V_1052 ) ||
V_1060 != ! ! ( V_12 -> V_1052 & V_176 ) ||
( ( V_12 -> V_230 & V_502 ) &&
V_1060 != ! ! ( V_12 -> V_1052 & V_177 ) ) ) {
F_548 ( V_8 , V_12 ,
V_900 , V_1072 ) ;
return 1 ;
}
}
if ( V_12 -> V_1068 & V_143 ) {
V_1060 = ( V_12 -> V_1068 &
V_309 ) != 0 ;
if ( ! F_549 ( V_8 , V_12 -> V_1075 ) ||
V_1060 != ! ! ( V_12 -> V_1075 & V_176 ) ||
V_1060 != ! ! ( V_12 -> V_1075 & V_177 ) ) {
F_548 ( V_8 , V_12 ,
V_900 , V_1072 ) ;
return 1 ;
}
}
V_806 = F_441 ( V_72 ) ;
if ( ! V_806 )
return - V_435 ;
F_550 ( V_8 ) ;
V_72 -> V_13 . V_674 = 1 ;
V_72 -> V_13 . V_283 = F_94 ( V_282 ) ;
V_90 = F_528 () ;
V_72 -> V_89 = V_806 ;
F_149 ( V_8 ) ;
F_142 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_529 () ;
F_105 ( V_72 ) ;
V_12 -> V_838 = 1 ;
F_545 ( V_8 , V_12 ) ;
return 1 ;
}
static inline unsigned long
F_551 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_91 ( V_223 ) & V_8 -> V_110 . V_226 ) |
( V_12 -> V_230 & V_12 -> V_227 ) |
( F_91 ( V_235 ) & ~ ( V_12 -> V_227 |
V_8 -> V_110 . V_226 ) ) ;
}
static inline unsigned long
F_552 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_91 ( V_463 ) & V_8 -> V_110 . V_491 ) |
( V_12 -> V_232 & V_12 -> V_233 ) |
( F_91 ( V_465 ) & ~ ( V_12 -> V_233 |
V_8 -> V_110 . V_491 ) ) ;
}
static void F_553 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1076 ;
unsigned int V_148 ;
if ( V_8 -> V_110 . V_723 . V_1077 && V_8 -> V_110 . V_723 . V_254 ) {
V_148 = V_8 -> V_110 . V_723 . V_148 ;
V_1076 = V_148 | V_708 ;
if ( F_169 ( V_148 ) ) {
V_12 -> V_1078 =
V_8 -> V_110 . V_258 ;
V_1076 |= V_262 ;
} else
V_1076 |= V_23 ;
if ( V_8 -> V_110 . V_723 . V_252 ) {
V_1076 |= V_767 ;
V_12 -> V_1079 =
V_8 -> V_110 . V_723 . V_253 ;
}
V_12 -> V_1080 = V_1076 ;
} else if ( V_8 -> V_110 . V_766 ) {
V_12 -> V_1080 =
V_671 | V_22 | V_670 ;
} else if ( V_8 -> V_110 . V_663 . V_1077 ) {
V_148 = V_8 -> V_110 . V_663 . V_148 ;
V_1076 = V_148 | V_708 ;
if ( V_8 -> V_110 . V_663 . V_665 ) {
V_1076 |= V_666 ;
V_12 -> V_1037 =
V_8 -> V_110 . V_258 ;
} else
V_1076 |= V_27 ;
V_12 -> V_1080 = V_1076 ;
}
}
static void F_554 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
V_12 -> V_230 = F_551 ( V_8 , V_12 ) ;
V_12 -> V_232 = F_552 ( V_8 , V_12 ) ;
F_387 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1040 ) ;
V_12 -> V_1057 = F_375 ( V_8 , V_392 ) ;
V_12 -> V_1058 = F_375 ( V_8 , V_395 ) ;
V_12 -> V_1041 = F_91 ( V_239 ) ;
V_12 -> V_979 = F_92 ( V_978 ) ;
V_12 -> V_980 = F_92 ( V_643 ) ;
V_12 -> V_982 = F_92 ( V_981 ) ;
V_12 -> V_984 = F_92 ( V_983 ) ;
V_12 -> V_986 = F_92 ( V_985 ) ;
V_12 -> V_988 = F_92 ( V_987 ) ;
V_12 -> V_989 = F_92 ( V_646 ) ;
V_12 -> V_990 = F_92 ( V_645 ) ;
V_12 -> V_992 = F_93 ( V_991 ) ;
V_12 -> V_994 = F_93 ( V_993 ) ;
V_12 -> V_996 = F_93 ( V_995 ) ;
V_12 -> V_998 = F_93 ( V_997 ) ;
V_12 -> V_1000 = F_93 ( V_999 ) ;
V_12 -> V_1002 = F_93 ( V_1001 ) ;
V_12 -> V_1003 = F_93 ( V_648 ) ;
V_12 -> V_1004 = F_93 ( V_479 ) ;
V_12 -> V_1005 = F_93 ( V_529 ) ;
V_12 -> V_1006 = F_93 ( V_527 ) ;
V_12 -> V_1008 = F_93 ( V_1007 ) ;
V_12 -> V_1010 = F_93 ( V_1009 ) ;
V_12 -> V_1012 = F_93 ( V_1011 ) ;
V_12 -> V_1014 = F_93 ( V_1013 ) ;
V_12 -> V_1016 = F_93 ( V_1015 ) ;
V_12 -> V_1018 = F_93 ( V_1017 ) ;
V_12 -> V_1019 = F_93 ( V_649 ) ;
V_12 -> V_1020 = F_93 ( V_481 ) ;
V_12 -> V_1022 = F_91 ( V_1021 ) ;
V_12 -> V_1023 = F_91 ( V_644 ) ;
V_12 -> V_1025 = F_91 ( V_1024 ) ;
V_12 -> V_1027 = F_91 ( V_1026 ) ;
V_12 -> V_1028 = F_91 ( V_377 ) ;
V_12 -> V_1029 = F_91 ( V_378 ) ;
V_12 -> V_1030 = F_91 ( V_647 ) ;
V_12 -> V_1031 = F_91 ( V_478 ) ;
V_12 -> V_1032 = F_91 ( V_530 ) ;
V_12 -> V_1033 = F_91 ( V_528 ) ;
V_12 -> V_1038 =
F_93 ( V_244 ) ;
V_12 -> V_1042 =
F_91 ( V_652 ) ;
if ( ( V_12 -> V_71 & V_304 ) &&
( V_12 -> V_1068 & V_312 ) )
V_12 -> V_1045 =
F_93 ( V_917 ) ;
if ( V_100 ) {
V_12 -> V_514 = F_94 ( V_489 ) ;
V_12 -> V_1053 = F_94 ( V_496 ) ;
V_12 -> V_1054 = F_94 ( V_498 ) ;
V_12 -> V_1055 = F_94 ( V_499 ) ;
V_12 -> V_1056 = F_94 ( V_500 ) ;
}
V_12 -> V_1050 =
( V_12 -> V_1050 & ~ V_318 ) |
( F_93 ( V_136 ) & V_318 ) ;
V_12 -> V_1034 = F_94 ( V_653 ) ;
if ( V_12 -> V_1068 & V_311 )
V_12 -> V_1051 = F_94 ( V_387 ) ;
if ( V_12 -> V_1068 & V_313 )
V_12 -> V_1052 = V_8 -> V_110 . V_173 ;
V_12 -> V_1039 = F_93 ( V_381 ) ;
V_12 -> V_1043 = F_91 ( V_384 ) ;
V_12 -> V_1044 = F_91 ( V_383 ) ;
V_12 -> V_675 = F_6 ( V_8 ) -> V_710 ;
V_12 -> V_728 = F_91 ( V_716 ) ;
V_12 -> V_677 = F_93 ( V_873 ) ;
if ( ( V_12 -> V_677 &
( V_22 | V_256 ) ) ==
( V_22 | V_256 ) )
V_12 -> V_1081 =
F_93 ( V_707 ) ;
V_12 -> V_1080 = 0 ;
V_12 -> V_1078 = F_93 ( V_251 ) ;
V_12 -> V_824 = F_93 ( V_835 ) ;
if ( ! ( V_12 -> V_675 & V_920 ) ) {
V_12 -> V_1035 &= ~ V_22 ;
F_553 ( V_8 , V_12 ) ;
}
V_8 -> V_110 . V_766 = false ;
F_423 ( V_8 ) ;
F_422 ( V_8 ) ;
}
static void F_555 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_450 V_107 ;
if ( V_12 -> V_1068 & V_143 )
V_8 -> V_110 . V_173 = V_12 -> V_1075 ;
else if ( V_12 -> V_1068 & V_309 )
V_8 -> V_110 . V_173 |= ( V_176 | V_177 ) ;
else
V_8 -> V_110 . V_173 &= ~ ( V_176 | V_177 ) ;
F_249 ( V_8 , V_8 -> V_110 . V_173 ) ;
F_380 ( V_8 , V_392 , V_12 -> V_1049 ) ;
F_380 ( V_8 , V_395 , V_12 -> V_1082 ) ;
F_160 ( V_8 , V_1083 ) ;
F_264 ( V_8 , V_12 -> V_1069 ) ;
F_111 ( V_8 ) ;
V_8 -> V_110 . V_226 = ( V_8 -> V_132 ? V_224 : 0 ) ;
F_98 ( V_228 , ~ V_8 -> V_110 . V_226 ) ;
V_8 -> V_110 . V_491 = ~ F_91 ( V_602 ) ;
F_372 ( V_8 , V_12 -> V_1070 ) ;
F_543 ( V_8 ) ;
F_378 ( V_8 , V_12 -> V_1084 ) ;
F_248 ( V_8 ) ;
if ( ! V_100 )
V_8 -> V_110 . V_494 -> V_975 = F_463 ;
if ( V_437 ) {
F_253 ( V_8 ) ;
}
F_101 ( V_381 , V_12 -> V_1085 ) ;
F_98 ( V_384 , V_12 -> V_1086 ) ;
F_98 ( V_383 , V_12 -> V_1087 ) ;
F_98 ( V_528 , V_12 -> V_1088 ) ;
F_98 ( V_530 , V_12 -> V_1089 ) ;
if ( V_12 -> V_1068 & V_310 ) {
F_102 ( V_387 , V_12 -> V_1090 ) ;
V_8 -> V_110 . V_388 = V_12 -> V_1090 ;
}
if ( V_12 -> V_1068 & V_147 )
F_102 ( V_159 ,
V_12 -> V_1091 ) ;
V_107 = (struct V_450 ) {
. V_117 = 0 ,
. V_119 = 0xFFFFFFFF ,
. V_114 = V_12 -> V_1092 ,
. type = 11 ,
. V_473 = 1 ,
. V_183 = 1 ,
. V_471 = 1
} ;
if ( V_12 -> V_1068 & V_309 )
V_107 . V_474 = 1 ;
else
V_107 . V_472 = 1 ;
F_242 ( V_8 , & V_107 , V_452 ) ;
V_107 = (struct V_450 ) {
. V_117 = 0 ,
. V_119 = 0xFFFFFFFF ,
. type = 3 ,
. V_473 = 1 ,
. V_183 = 1 ,
. V_472 = 1 ,
. V_471 = 1
} ;
V_107 . V_114 = V_12 -> V_1093 ;
F_242 ( V_8 , & V_107 , V_459 ) ;
V_107 . V_114 = V_12 -> V_1094 ;
F_242 ( V_8 , & V_107 , V_458 ) ;
V_107 . V_114 = V_12 -> V_1095 ;
F_242 ( V_8 , & V_107 , V_453 ) ;
V_107 . V_114 = V_12 -> V_1096 ;
V_107 . V_117 = V_12 -> V_1097 ;
F_242 ( V_8 , & V_107 , V_460 ) ;
V_107 . V_114 = V_12 -> V_1098 ;
V_107 . V_117 = V_12 -> V_1099 ;
F_242 ( V_8 , & V_107 , V_461 ) ;
V_107 = (struct V_450 ) {
. V_117 = V_12 -> V_1100 ,
. V_119 = 0x67 ,
. V_114 = V_12 -> V_1101 ,
. type = 11 ,
. V_473 = 1
} ;
F_242 ( V_8 , & V_107 , V_462 ) ;
F_388 ( V_8 , 7 , 0x400 ) ;
F_102 ( V_653 , 0 ) ;
}
static void F_167 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_556 ( V_72 -> V_13 . V_674 ) ;
F_557 ( V_8 ) ;
F_554 ( V_8 , V_12 ) ;
V_90 = F_528 () ;
V_72 -> V_89 = & V_72 -> V_810 ;
F_149 ( V_8 ) ;
F_142 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_529 () ;
F_105 ( V_72 ) ;
if ( V_808 == 0 )
F_447 ( V_72 , V_72 -> V_13 . V_803 ) ;
F_555 ( V_8 , V_12 ) ;
F_102 ( V_282 , V_72 -> V_13 . V_283 ) ;
V_72 -> V_1049 = 0 ;
if ( V_72 -> V_13 . V_561 ) {
F_13 ( V_72 -> V_13 . V_561 ) ;
V_72 -> V_13 . V_561 = 0 ;
}
if ( F_99 ( V_72 -> V_874 ) ) {
V_72 -> V_874 = 0 ;
F_451 ( V_8 , F_93 ( V_103 ) ) ;
} else
F_449 ( V_8 ) ;
if ( V_438 )
V_72 -> V_13 . V_822 = true ;
}
static void F_548 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_760 , unsigned long V_1102 )
{
F_555 ( V_8 , V_12 ) ;
V_12 -> V_675 = V_760 | V_920 ;
V_12 -> V_728 = V_1102 ;
F_449 ( V_8 ) ;
if ( V_438 )
F_6 ( V_8 ) -> V_13 . V_822 = true ;
}
static int F_558 ( struct V_7 * V_8 ,
struct V_1103 * V_1104 ,
enum V_1105 V_1106 )
{
return V_1107 ;
}
static int T_11 F_559 ( void )
{
int V_542 , V_74 , V_73 ;
F_560 ( V_140 , & V_178 ) ;
for ( V_74 = 0 ; V_74 < V_635 ; ++ V_74 )
F_561 ( V_74 , V_76 [ V_74 ] ) ;
V_606 = ( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_606 )
return - V_435 ;
V_542 = - V_435 ;
V_608 = ( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_608 )
goto V_525;
V_272 = ( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_272 )
goto V_1108;
V_270 =
( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_270 )
goto V_1109;
V_271 = ( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_271 )
goto V_1110;
V_269 =
( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_269 )
goto V_1111;
V_610 = ( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_610 )
goto V_1112;
V_612 = ( unsigned long * ) F_562 ( V_434 ) ;
if ( ! V_612 )
goto V_1113;
memset ( V_610 , 0xff , V_424 ) ;
memset ( V_612 , 0xff , V_424 ) ;
for ( V_74 = 0 ; V_74 < V_847 ; V_74 ++ ) {
F_563 ( V_845 [ V_74 ] , V_612 ) ;
F_563 ( V_845 [ V_74 ] , V_610 ) ;
}
for ( V_74 = 0 ; V_74 < V_850 ; V_74 ++ )
F_563 ( V_848 [ V_74 ] , V_610 ) ;
memset ( V_606 , 0xff , V_424 ) ;
F_563 ( 0x80 , V_606 ) ;
memset ( V_608 , 0xff , V_424 ) ;
memset ( V_272 , 0xff , V_424 ) ;
memset ( V_271 , 0xff , V_424 ) ;
F_564 ( 0 , V_569 ) ;
V_542 = F_565 ( & V_1114 , sizeof( struct V_6 ) ,
F_566 ( struct V_6 ) , V_1115 ) ;
if ( V_542 )
goto V_1116;
#ifdef F_567
F_568 ( V_1117 ,
F_77 ) ;
#endif
F_304 ( V_203 , false ) ;
F_304 ( V_205 , false ) ;
F_304 ( V_206 , true ) ;
F_304 ( V_380 , false ) ;
F_304 ( V_220 , false ) ;
F_304 ( V_382 , false ) ;
memcpy ( V_270 ,
V_272 , V_424 ) ;
memcpy ( V_269 ,
V_271 , V_424 ) ;
if ( V_444 ) {
for ( V_73 = 0x800 ; V_73 <= 0x8ff ; V_73 ++ )
F_306 ( V_73 ) ;
F_305 ( 0x802 ) ;
F_305 ( 0x839 ) ;
F_307 ( 0x808 ) ;
F_307 ( 0x80b ) ;
F_307 ( 0x83f ) ;
}
if ( V_100 ) {
F_569 ( 0ull ,
( V_440 ) ? V_1118 : 0ull ,
( V_440 ) ? V_1119 : 0ull ,
0ull , V_1120 ) ;
F_323 () ;
F_570 () ;
} else
F_571 () ;
return 0 ;
V_1116:
F_572 ( ( unsigned long ) V_612 ) ;
V_1113:
F_572 ( ( unsigned long ) V_610 ) ;
V_1112:
F_572 ( ( unsigned long ) V_269 ) ;
V_1111:
F_572 ( ( unsigned long ) V_271 ) ;
V_1110:
F_572 ( ( unsigned long ) V_270 ) ;
V_1109:
F_572 ( ( unsigned long ) V_272 ) ;
V_1108:
F_572 ( ( unsigned long ) V_608 ) ;
V_525:
F_572 ( ( unsigned long ) V_606 ) ;
return V_542 ;
}
static void T_12 F_573 ( void )
{
F_572 ( ( unsigned long ) V_270 ) ;
F_572 ( ( unsigned long ) V_269 ) ;
F_572 ( ( unsigned long ) V_272 ) ;
F_572 ( ( unsigned long ) V_271 ) ;
F_572 ( ( unsigned long ) V_608 ) ;
F_572 ( ( unsigned long ) V_606 ) ;
F_572 ( ( unsigned long ) V_612 ) ;
F_572 ( ( unsigned long ) V_610 ) ;
#ifdef F_567
F_568 ( V_1117 , NULL ) ;
F_574 () ;
#endif
F_575 () ;
}
