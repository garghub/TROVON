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
static inline void F_105 ( struct V_6 * V_72 , T_2 V_105 )
{
F_101 ( V_106 , V_105 ) ;
V_72 -> V_107 = V_105 ;
}
static inline void F_106 ( struct V_6 * V_72 , T_2 V_105 )
{
if ( V_72 -> V_107 != V_105 )
F_105 ( V_72 , V_105 ) ;
}
static inline T_2 F_107 ( struct V_6 * V_72 )
{
return V_72 -> V_107 ;
}
static inline void F_108 ( struct V_6 * V_72 , T_2 V_105 )
{
F_106 ( V_72 , F_107 ( V_72 ) | V_105 ) ;
}
static inline void F_109 ( struct V_6 * V_72 , T_2 V_105 )
{
F_106 ( V_72 , F_107 ( V_72 ) & ~ V_105 ) ;
}
static inline void F_110 ( struct V_6 * V_72 , T_2 V_105 )
{
F_101 ( V_108 , V_105 ) ;
V_72 -> V_109 = V_105 ;
}
static inline void F_111 ( struct V_6 * V_72 , T_2 V_105 )
{
if ( V_72 -> V_109 != V_105 )
F_110 ( V_72 , V_105 ) ;
}
static inline T_2 F_112 ( struct V_6 * V_72 )
{
return V_72 -> V_109 ;
}
static inline void F_113 ( struct V_6 * V_72 , T_2 V_105 )
{
F_111 ( V_72 , F_112 ( V_72 ) | V_105 ) ;
}
static inline void F_114 ( struct V_6 * V_72 , T_2 V_105 )
{
F_111 ( V_72 , F_112 ( V_72 ) & ~ V_105 ) ;
}
static void F_115 ( struct V_6 * V_72 )
{
V_72 -> V_110 . V_111 = 0 ;
}
static bool F_116 ( struct V_6 * V_72 , unsigned V_112 ,
unsigned V_9 )
{
bool V_113 ;
T_2 V_104 = 1 << ( V_112 * V_114 + V_9 ) ;
if ( ! ( V_72 -> V_8 . V_115 . V_116 & ( 1 << V_117 ) ) ) {
V_72 -> V_8 . V_115 . V_116 |= ( 1 << V_117 ) ;
V_72 -> V_110 . V_111 = 0 ;
}
V_113 = V_72 -> V_110 . V_111 & V_104 ;
V_72 -> V_110 . V_111 |= V_104 ;
return V_113 ;
}
static T_4 F_117 ( struct V_6 * V_72 , unsigned V_112 )
{
T_4 * V_118 = & V_72 -> V_110 . V_112 [ V_112 ] . V_119 ;
if ( ! F_116 ( V_72 , V_112 , V_120 ) )
* V_118 = F_92 ( V_121 [ V_112 ] . V_119 ) ;
return * V_118 ;
}
static T_9 F_118 ( struct V_6 * V_72 , unsigned V_112 )
{
T_9 * V_118 = & V_72 -> V_110 . V_112 [ V_112 ] . V_122 ;
if ( ! F_116 ( V_72 , V_112 , V_123 ) )
* V_118 = F_91 ( V_121 [ V_112 ] . V_122 ) ;
return * V_118 ;
}
static T_2 F_119 ( struct V_6 * V_72 , unsigned V_112 )
{
T_2 * V_118 = & V_72 -> V_110 . V_112 [ V_112 ] . V_124 ;
if ( ! F_116 ( V_72 , V_112 , V_125 ) )
* V_118 = F_93 ( V_121 [ V_112 ] . V_124 ) ;
return * V_118 ;
}
static T_2 F_120 ( struct V_6 * V_72 , unsigned V_112 )
{
T_2 * V_118 = & V_72 -> V_110 . V_112 [ V_112 ] . V_126 ;
if ( ! F_116 ( V_72 , V_112 , V_127 ) )
* V_118 = F_93 ( V_121 [ V_112 ] . V_128 ) ;
return * V_118 ;
}
static void F_121 ( struct V_7 * V_8 )
{
T_2 V_129 ;
V_129 = ( 1u << V_24 ) | ( 1u << V_26 ) | ( 1u << V_28 ) |
( 1u << V_25 ) | ( 1u << V_130 ) ;
if ( ( V_8 -> V_131 &
( V_132 | V_133 ) ) ==
( V_132 | V_133 ) )
V_129 |= 1u << V_134 ;
if ( F_6 ( V_8 ) -> V_135 . V_136 )
V_129 = ~ 0 ;
if ( V_100 )
V_129 &= ~ ( 1u << V_24 ) ;
if ( V_8 -> V_137 )
V_129 &= ~ ( 1u << V_25 ) ;
if ( F_122 ( V_8 ) )
V_129 |= F_9 ( V_8 ) -> V_138 ;
F_101 ( V_139 , V_129 ) ;
}
static void F_123 ( struct V_6 * V_72 ,
unsigned long V_140 , unsigned long exit )
{
F_109 ( V_72 , V_140 ) ;
F_114 ( V_72 , exit ) ;
}
static void F_124 ( struct V_6 * V_72 , unsigned V_73 )
{
unsigned V_74 ;
struct V_141 * V_142 = & V_72 -> V_141 ;
switch ( V_73 ) {
case V_143 :
if ( V_144 ) {
F_123 ( V_72 ,
V_145 ,
V_146 ) ;
return;
}
break;
case V_147 :
if ( V_148 ) {
F_123 ( V_72 ,
V_149 ,
V_150 ) ;
return;
}
break;
}
for ( V_74 = 0 ; V_74 < V_142 -> V_151 ; ++ V_74 )
if ( V_142 -> V_152 [ V_74 ] . V_78 == V_73 )
break;
if ( V_74 == V_142 -> V_151 )
return;
-- V_142 -> V_151 ;
V_142 -> V_152 [ V_74 ] = V_142 -> V_152 [ V_142 -> V_151 ] ;
V_142 -> V_153 [ V_74 ] = V_142 -> V_153 [ V_142 -> V_151 ] ;
F_101 ( V_154 , V_142 -> V_151 ) ;
F_101 ( V_155 , V_142 -> V_151 ) ;
}
static void F_125 ( struct V_6 * V_72 ,
unsigned long V_140 , unsigned long exit ,
unsigned long V_156 , unsigned long V_157 ,
T_3 V_158 , T_3 V_159 )
{
F_102 ( V_156 , V_158 ) ;
F_102 ( V_157 , V_159 ) ;
F_108 ( V_72 , V_140 ) ;
F_113 ( V_72 , exit ) ;
}
static void F_126 ( struct V_6 * V_72 , unsigned V_73 ,
T_3 V_158 , T_3 V_159 )
{
unsigned V_74 ;
struct V_141 * V_142 = & V_72 -> V_141 ;
switch ( V_73 ) {
case V_143 :
if ( V_144 ) {
F_125 ( V_72 ,
V_145 ,
V_146 ,
V_160 ,
V_161 ,
V_158 , V_159 ) ;
return;
}
break;
case V_147 :
if ( V_148 ) {
F_125 ( V_72 ,
V_149 ,
V_150 ,
V_162 ,
V_163 ,
V_158 , V_159 ) ;
return;
}
break;
}
for ( V_74 = 0 ; V_74 < V_142 -> V_151 ; ++ V_74 )
if ( V_142 -> V_152 [ V_74 ] . V_78 == V_73 )
break;
if ( V_74 == V_164 ) {
F_127 ( V_165 L_4
L_5 , V_73 ) ;
return;
} else if ( V_74 == V_142 -> V_151 ) {
++ V_142 -> V_151 ;
F_101 ( V_154 , V_142 -> V_151 ) ;
F_101 ( V_155 , V_142 -> V_151 ) ;
}
V_142 -> V_152 [ V_74 ] . V_78 = V_73 ;
V_142 -> V_152 [ V_74 ] . V_102 = V_158 ;
V_142 -> V_153 [ V_74 ] . V_78 = V_73 ;
V_142 -> V_153 [ V_74 ] . V_102 = V_159 ;
}
static void F_128 ( void )
{
struct V_166 * V_167 = & F_129 ( V_168 ) ;
struct V_169 * V_170 ;
V_170 = ( void * ) V_167 -> V_171 ;
V_170 [ V_172 ] . type = 9 ;
F_130 () ;
}
static bool F_131 ( struct V_6 * V_72 , int V_173 )
{
T_3 V_174 ;
T_3 V_175 ;
V_174 = V_72 -> V_8 . V_115 . V_176 ;
V_175 = V_177 | V_178 ;
#ifdef F_95
V_175 |= V_179 | V_180 ;
if ( V_174 & V_179 )
V_175 &= ~ ( T_3 ) V_178 ;
#endif
V_174 &= ~ V_175 ;
V_174 |= V_181 & V_175 ;
V_72 -> V_77 [ V_173 ] . V_182 = V_174 ;
V_72 -> V_77 [ V_173 ] . V_104 = ~ V_175 ;
F_124 ( V_72 , V_143 ) ;
if ( V_100 && ( ( V_72 -> V_8 . V_115 . V_176 ^ V_181 ) & V_177 ) ) {
V_174 = V_72 -> V_8 . V_115 . V_176 ;
if ( ! ( V_174 & V_179 ) )
V_174 &= ~ V_180 ;
F_126 ( V_72 , V_143 , V_174 , V_181 ) ;
return false ;
}
return true ;
}
static unsigned long F_132 ( T_4 V_119 )
{
struct V_166 * V_167 = & F_129 ( V_168 ) ;
struct V_169 * V_183 ;
unsigned long V_184 ;
unsigned long V_93 ;
if ( ! ( V_119 & ~ 3 ) )
return 0 ;
V_184 = V_167 -> V_171 ;
if ( V_119 & 4 ) {
T_4 V_185 = F_133 () ;
if ( ! ( V_185 & ~ 3 ) )
return 0 ;
V_184 = F_132 ( V_185 ) ;
}
V_183 = (struct V_169 * ) ( V_184 + ( V_119 & ~ 7 ) ) ;
V_93 = F_134 ( V_183 ) ;
#ifdef F_95
if ( V_183 -> V_186 == 0 && ( V_183 -> type == 2 || V_183 -> type == 9 || V_183 -> type == 11 ) )
V_93 |= ( ( unsigned long ) ( (struct V_187 * ) V_183 ) -> V_188 ) << 32 ;
#endif
return V_93 ;
}
static inline unsigned long F_135 ( void )
{
T_4 V_189 ;
asm("str %0" : "=g"(tr));
return F_132 ( V_189 ) ;
}
static void F_136 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_74 ;
if ( V_72 -> V_190 . V_191 )
return;
V_72 -> V_190 . V_191 = 1 ;
V_72 -> V_190 . V_192 = F_133 () ;
V_72 -> V_190 . V_193 = V_72 -> V_190 . V_192 ;
F_137 ( V_194 , V_72 -> V_190 . V_195 ) ;
if ( ! ( V_72 -> V_190 . V_195 & 7 ) ) {
F_100 ( V_196 , V_72 -> V_190 . V_195 ) ;
V_72 -> V_190 . V_197 = 0 ;
} else {
F_100 ( V_196 , 0 ) ;
V_72 -> V_190 . V_197 = 1 ;
}
F_137 ( V_198 , V_72 -> V_190 . V_199 ) ;
if ( ! ( V_72 -> V_190 . V_199 & 7 ) )
F_100 ( V_200 , V_72 -> V_190 . V_199 ) ;
else {
F_100 ( V_200 , 0 ) ;
V_72 -> V_190 . V_193 = 1 ;
}
#ifdef F_95
F_137 ( V_201 , V_72 -> V_190 . V_202 ) ;
F_137 ( V_203 , V_72 -> V_190 . V_204 ) ;
#endif
#ifdef F_95
F_98 ( V_205 , F_138 ( V_206 ) ) ;
F_98 ( V_207 , F_138 ( V_208 ) ) ;
#else
F_98 ( V_205 , F_132 ( V_72 -> V_190 . V_195 ) ) ;
F_98 ( V_207 , F_132 ( V_72 -> V_190 . V_199 ) ) ;
#endif
#ifdef F_95
F_55 ( V_209 , V_72 -> V_210 ) ;
if ( F_139 ( & V_72 -> V_8 ) )
F_140 ( V_209 , V_72 -> V_211 ) ;
#endif
for ( V_74 = 0 ; V_74 < V_72 -> V_212 ; ++ V_74 )
F_141 ( V_72 -> V_77 [ V_74 ] . V_78 ,
V_72 -> V_77 [ V_74 ] . V_182 ,
V_72 -> V_77 [ V_74 ] . V_104 ) ;
}
static void F_142 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_190 . V_191 )
return;
++ V_72 -> V_8 . V_213 . V_214 ;
V_72 -> V_190 . V_191 = 0 ;
#ifdef F_95
if ( F_139 ( & V_72 -> V_8 ) )
F_55 ( V_209 , V_72 -> V_211 ) ;
#endif
if ( V_72 -> V_190 . V_193 ) {
F_143 ( V_72 -> V_190 . V_192 ) ;
#ifdef F_95
F_144 ( V_72 -> V_190 . V_199 ) ;
#else
F_145 ( V_198 , V_72 -> V_190 . V_199 ) ;
#endif
}
if ( V_72 -> V_190 . V_197 )
F_145 ( V_194 , V_72 -> V_190 . V_195 ) ;
#ifdef F_95
if ( F_99 ( V_72 -> V_190 . V_202 | V_72 -> V_190 . V_204 ) ) {
F_145 ( V_201 , V_72 -> V_190 . V_202 ) ;
F_145 ( V_203 , V_72 -> V_190 . V_204 ) ;
}
#endif
F_128 () ;
#ifdef F_95
F_140 ( V_209 , V_72 -> V_210 ) ;
#endif
if ( ! F_146 () && ! V_72 -> V_8 . V_215 )
F_147 () ;
F_148 ( & F_129 ( V_168 ) ) ;
}
static void F_149 ( struct V_6 * V_72 )
{
F_150 () ;
F_142 ( V_72 ) ;
F_151 () ;
}
static void F_152 ( struct V_7 * V_8 , int V_90 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_3 V_87 = F_67 ( F_81 ( V_216 , V_90 ) ) ;
if ( ! V_217 )
F_153 ( V_87 ) ;
else if ( V_72 -> V_89 -> V_90 != V_90 )
F_84 ( V_72 -> V_89 ) ;
if ( F_81 ( V_95 , V_90 ) != V_72 -> V_89 -> V_86 ) {
F_81 ( V_95 , V_90 ) = V_72 -> V_89 -> V_86 ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
if ( V_72 -> V_89 -> V_90 != V_90 ) {
struct V_166 * V_167 = & F_129 ( V_168 ) ;
unsigned long V_218 ;
F_154 ( V_219 , V_8 ) ;
F_155 () ;
F_73 ( V_90 ) ;
F_156 () ;
F_157 ( & V_72 -> V_89 -> V_96 ,
& F_81 ( V_220 , V_90 ) ) ;
F_71 ( V_90 ) ;
F_158 () ;
F_98 ( V_221 , F_135 () ) ;
F_98 ( V_222 , V_167 -> V_171 ) ;
F_55 ( V_223 , V_218 ) ;
F_98 ( V_224 , V_218 ) ;
V_72 -> V_89 -> V_90 = V_90 ;
}
}
static void F_159 ( struct V_7 * V_8 )
{
F_142 ( F_6 ( V_8 ) ) ;
if ( ! V_217 ) {
F_80 ( F_6 ( V_8 ) -> V_89 ) ;
V_8 -> V_90 = - 1 ;
F_160 () ;
}
}
static void F_161 ( struct V_7 * V_8 )
{
T_9 V_225 ;
if ( V_8 -> V_137 )
return;
V_8 -> V_137 = 1 ;
V_225 = F_91 ( V_226 ) ;
V_225 &= ~ ( V_227 | V_228 ) ;
V_225 |= F_162 ( V_8 , V_227 | V_228 ) ;
F_98 ( V_226 , V_225 ) ;
F_121 ( V_8 ) ;
V_8 -> V_115 . V_229 = V_227 ;
if ( F_122 ( V_8 ) )
V_8 -> V_115 . V_229 &=
~ F_9 ( V_8 ) -> V_230 ;
F_98 ( V_231 , ~ V_8 -> V_115 . V_229 ) ;
}
static inline unsigned long F_163 ( struct V_12 * V_232 )
{
return ( V_232 -> V_233 & ~ V_232 -> V_230 ) |
( V_232 -> V_234 & V_232 -> V_230 ) ;
}
static inline unsigned long F_164 ( struct V_12 * V_232 )
{
return ( V_232 -> V_235 & ~ V_232 -> V_236 ) |
( V_232 -> V_237 & V_232 -> V_236 ) ;
}
static void F_165 ( struct V_7 * V_8 )
{
F_166 ( V_8 ) ;
F_104 ( V_226 , V_227 | V_228 ) ;
F_121 ( V_8 ) ;
V_8 -> V_115 . V_229 = 0 ;
F_98 ( V_231 , ~ V_8 -> V_115 . V_229 ) ;
if ( F_122 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
V_12 -> V_233 = ( V_12 -> V_233 & ~ V_227 ) |
( V_8 -> V_115 . V_225 & V_227 ) ;
F_98 ( V_238 , F_163 ( V_12 ) ) ;
} else
F_98 ( V_238 , V_8 -> V_115 . V_225 ) ;
}
static unsigned long F_167 ( struct V_7 * V_8 )
{
unsigned long V_239 , V_240 ;
if ( ! F_168 ( V_241 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ) {
F_169 ( V_241 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ;
V_239 = F_91 ( V_242 ) ;
if ( F_6 ( V_8 ) -> V_135 . V_136 ) {
V_239 &= V_243 ;
V_240 = F_6 ( V_8 ) -> V_135 . V_240 ;
V_239 |= V_240 & ~ V_243 ;
}
F_6 ( V_8 ) -> V_239 = V_239 ;
}
return F_6 ( V_8 ) -> V_239 ;
}
static void F_170 ( struct V_7 * V_8 , unsigned long V_239 )
{
F_169 ( V_241 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ;
F_6 ( V_8 ) -> V_239 = V_239 ;
if ( F_6 ( V_8 ) -> V_135 . V_136 ) {
F_6 ( V_8 ) -> V_135 . V_240 = V_239 ;
V_239 |= V_244 | V_245 ;
}
F_98 ( V_242 , V_239 ) ;
}
static T_2 F_171 ( struct V_7 * V_8 , int V_104 )
{
T_2 V_246 = F_93 ( V_247 ) ;
int V_113 = 0 ;
if ( V_246 & V_248 )
V_113 |= V_249 ;
if ( V_246 & V_250 )
V_113 |= V_251 ;
return V_113 & V_104 ;
}
static void F_172 ( struct V_7 * V_8 , int V_104 )
{
T_2 V_252 = F_93 ( V_247 ) ;
T_2 V_246 = V_252 ;
V_246 &= ~ ( V_248 | V_250 ) ;
if ( V_104 & V_251 )
V_246 |= V_250 ;
else if ( V_104 & V_249 )
V_246 |= V_248 ;
if ( ( V_246 != V_252 ) )
F_101 ( V_247 , V_246 ) ;
}
static void F_173 ( struct V_7 * V_8 )
{
unsigned long V_253 ;
V_253 = F_174 ( V_8 ) ;
V_253 += F_93 ( V_254 ) ;
F_175 ( V_8 , V_253 ) ;
F_172 ( V_8 , 0 ) ;
}
static int F_176 ( struct V_7 * V_8 , unsigned V_151 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( ! ( V_12 -> V_138 & ( 1u << V_151 ) ) )
return 0 ;
F_177 ( V_8 , F_6 ( V_8 ) -> V_255 ,
F_93 ( V_256 ) ,
F_91 ( V_257 ) ) ;
return 1 ;
}
static void F_178 ( struct V_7 * V_8 , unsigned V_151 ,
bool V_258 , T_2 V_259 ,
bool V_260 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_19 = V_151 | V_22 ;
if ( ! V_260 && F_122 ( V_8 ) &&
F_176 ( V_8 , V_151 ) )
return;
if ( V_258 ) {
F_101 ( V_261 , V_259 ) ;
V_19 |= V_262 ;
}
if ( V_72 -> V_135 . V_136 ) {
int V_263 = 0 ;
if ( F_179 ( V_151 ) )
V_263 = V_8 -> V_115 . V_264 ;
if ( F_180 ( V_8 , V_151 , V_263 ) != V_265 )
F_154 ( V_266 , V_8 ) ;
return;
}
if ( F_179 ( V_151 ) ) {
F_101 ( V_267 ,
V_72 -> V_8 . V_115 . V_264 ) ;
V_19 |= V_268 ;
} else
V_19 |= V_23 ;
F_101 ( V_269 , V_19 ) ;
}
static bool F_181 ( void )
{
return F_50 () ;
}
static bool F_182 ( void )
{
return F_51 () && V_100 ;
}
static void F_183 ( struct V_6 * V_72 , int V_270 , int V_271 )
{
struct V_85 V_272 ;
V_272 = V_72 -> V_77 [ V_271 ] ;
V_72 -> V_77 [ V_271 ] = V_72 -> V_77 [ V_270 ] ;
V_72 -> V_77 [ V_270 ] = V_272 ;
}
static void F_184 ( struct V_7 * V_8 )
{
unsigned long * V_273 ;
if ( F_25 ( V_8 -> V_17 ) && F_185 ( V_8 -> V_115 . V_274 ) ) {
if ( F_139 ( V_8 ) )
V_273 = V_275 ;
else
V_273 = V_276 ;
} else {
if ( F_139 ( V_8 ) )
V_273 = V_277 ;
else
V_273 = V_278 ;
}
F_102 ( V_279 , F_67 ( V_273 ) ) ;
}
static void F_186 ( struct V_6 * V_72 )
{
int V_212 , V_78 ;
V_212 = 0 ;
#ifdef F_95
if ( F_139 ( & V_72 -> V_8 ) ) {
V_78 = F_62 ( V_72 , V_280 ) ;
if ( V_78 >= 0 )
F_183 ( V_72 , V_78 , V_212 ++ ) ;
V_78 = F_62 ( V_72 , V_281 ) ;
if ( V_78 >= 0 )
F_183 ( V_72 , V_78 , V_212 ++ ) ;
V_78 = F_62 ( V_72 , V_282 ) ;
if ( V_78 >= 0 )
F_183 ( V_72 , V_78 , V_212 ++ ) ;
V_78 = F_62 ( V_72 , V_283 ) ;
if ( V_78 >= 0 && V_72 -> V_284 )
F_183 ( V_72 , V_78 , V_212 ++ ) ;
V_78 = F_62 ( V_72 , V_285 ) ;
if ( ( V_78 >= 0 ) && ( V_72 -> V_8 . V_115 . V_176 & V_178 ) )
F_183 ( V_72 , V_78 , V_212 ++ ) ;
}
#endif
V_78 = F_62 ( V_72 , V_143 ) ;
if ( V_78 >= 0 && F_131 ( V_72 , V_78 ) )
F_183 ( V_72 , V_78 , V_212 ++ ) ;
V_72 -> V_212 = V_212 ;
if ( F_22 () )
F_184 ( & V_72 -> V_8 ) ;
}
static T_3 F_187 ( void )
{
T_3 V_286 , V_287 ;
F_188 ( V_286 ) ;
V_287 = F_94 ( V_288 ) ;
return V_286 + V_287 ;
}
T_3 F_189 ( struct V_7 * V_8 , T_3 V_286 )
{
T_3 V_287 ;
V_287 = F_122 ( V_8 ) ?
F_6 ( V_8 ) -> V_13 . V_289 :
F_94 ( V_288 ) ;
return V_286 + V_287 ;
}
static void F_190 ( struct V_7 * V_8 , T_2 V_290 , bool V_291 )
{
if ( ! V_291 )
return;
if ( V_290 > V_292 ) {
V_8 -> V_115 . V_293 = 1 ;
V_8 -> V_115 . V_294 = 1 ;
} else
F_191 ( 1 , L_6 ) ;
}
static T_3 F_192 ( struct V_7 * V_8 )
{
return F_94 ( V_288 ) ;
}
static void F_193 ( struct V_7 * V_8 , T_3 V_295 )
{
if ( F_122 ( V_8 ) ) {
struct V_12 * V_12 ;
F_6 ( V_8 ) -> V_13 . V_289 = V_295 ;
V_12 = F_9 ( V_8 ) ;
F_102 ( V_288 , V_295 +
( F_57 ( V_12 , V_296 ) ?
V_12 -> V_287 : 0 ) ) ;
} else {
F_194 ( V_8 -> V_297 ,
F_94 ( V_288 ) , V_295 ) ;
F_102 ( V_288 , V_295 ) ;
}
}
static void F_195 ( struct V_7 * V_8 , T_10 V_298 , bool V_153 )
{
T_3 V_295 = F_94 ( V_288 ) ;
F_102 ( V_288 , V_295 + V_298 ) ;
if ( F_122 ( V_8 ) ) {
F_6 ( V_8 ) -> V_13 . V_289 += V_298 ;
} else
F_194 ( V_8 -> V_297 , V_295 ,
V_295 + V_298 ) ;
}
static T_3 F_196 ( struct V_7 * V_8 , T_3 V_299 )
{
return V_299 - F_197 () ;
}
static bool F_198 ( struct V_7 * V_8 )
{
struct V_300 * V_301 = F_199 ( V_8 , 1 , 0 ) ;
return V_301 && ( V_301 -> V_302 & ( 1 << ( V_303 & 31 ) ) ) ;
}
static inline bool F_200 ( struct V_7 * V_8 )
{
return V_13 && F_198 ( V_8 ) ;
}
static T_11 void F_201 ( void )
{
F_202 ( V_304 ,
V_305 , V_306 ) ;
V_305 |= V_307 ;
V_306 &= V_308 |
V_309 | V_62 |
V_310 ;
V_306 |= V_307 ;
F_202 ( V_311 ,
V_312 , V_313 ) ;
V_312 = V_314 ;
V_313 &=
#ifdef F_95
V_315 |
#endif
V_316 | V_317 |
V_318 ;
if ( ! ( V_306 & V_310 ) ||
! ( V_313 & V_318 ) ) {
V_313 &= ~ V_318 ;
V_306 &= ~ V_310 ;
}
V_313 |= ( V_314 |
V_146 | V_319 ) ;
F_202 ( V_320 ,
V_321 , V_322 ) ;
V_321 = V_323 ;
V_322 &=
#ifdef F_95
V_324 |
#endif
V_325 ;
V_322 |= ( V_323 |
V_145 ) ;
F_202 ( V_326 ,
V_327 , V_328 ) ;
V_327 = 0 ;
V_328 &=
V_329 |
V_330 | V_296 |
V_331 | V_332 |
V_333 | V_334 |
V_335 |
#ifdef F_95
V_336 | V_337 |
#endif
V_338 | V_339 |
V_340 | V_341 |
V_342 | V_343 |
V_344 |
V_33 ;
V_328 |= V_31 ;
F_202 ( V_345 ,
V_346 , V_347 ) ;
V_346 = 0 ;
V_347 &=
V_35 |
V_56 |
V_63 ;
if ( V_100 ) {
V_347 |= V_55 ;
V_348 = V_48 |
V_45 | V_46 |
V_349 ;
V_348 &= V_41 . V_42 ;
V_348 |= V_51 |
V_50 ;
} else
V_348 = 0 ;
F_202 ( V_65 , V_350 , V_351 ) ;
V_350 &= V_352 |
V_353 ;
V_350 |= V_354 ;
V_351 = 0 ;
}
static inline bool F_203 ( T_2 V_3 , T_2 V_355 , T_2 V_356 )
{
return ( ( V_3 & V_356 ) | V_355 ) == V_3 ;
}
static inline T_3 F_204 ( T_2 V_355 , T_2 V_356 )
{
return V_355 | ( ( T_3 ) V_356 << 32 ) ;
}
static int F_205 ( struct V_7 * V_8 , T_2 V_357 , T_3 * V_358 )
{
switch ( V_357 ) {
case V_359 :
* V_358 = V_360 |
( ( T_3 ) V_361 << V_362 ) |
( V_363 << V_364 ) ;
break;
case V_365 :
case V_304 :
* V_358 = F_204 ( V_305 ,
V_306 ) ;
break;
case V_366 :
case V_326 :
* V_358 = F_204 ( V_327 ,
V_328 ) ;
break;
case V_367 :
case V_311 :
* V_358 = F_204 ( V_312 ,
V_313 ) ;
break;
case V_368 :
case V_320 :
* V_358 = F_204 ( V_321 ,
V_322 ) ;
break;
case V_65 :
* V_358 = F_204 ( V_350 ,
V_351 ) ;
break;
#define F_206 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_207 X86_CR4_VMXE
case V_369 :
* V_358 = F_206 ;
break;
case V_370 :
* V_358 = - 1ULL ;
break;
case V_371 :
* V_358 = F_207 ;
break;
case V_372 :
* V_358 = - 1ULL ;
break;
case V_373 :
* V_358 = 0x1f ;
break;
case V_345 :
* V_358 = F_204 ( V_346 ,
V_347 ) ;
break;
case V_374 :
* V_358 = V_348 ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_208 ( struct V_7 * V_8 , T_2 V_357 , T_3 * V_358 )
{
T_3 V_182 ;
struct V_85 * V_73 ;
if ( ! V_358 ) {
F_68 ( V_88 L_7 ) ;
return - V_375 ;
}
switch ( V_357 ) {
#ifdef F_95
case V_206 :
V_182 = F_91 ( V_376 ) ;
break;
case V_208 :
V_182 = F_91 ( V_377 ) ;
break;
case V_209 :
F_149 ( F_6 ( V_8 ) ) ;
V_182 = F_6 ( V_8 ) -> V_211 ;
break;
#endif
case V_143 :
return F_209 ( V_8 , V_357 , V_358 ) ;
case V_378 :
V_182 = F_187 () ;
break;
case V_379 :
V_182 = F_93 ( V_380 ) ;
break;
case V_381 :
V_182 = F_91 ( V_382 ) ;
break;
case V_223 :
V_182 = F_91 ( V_383 ) ;
break;
case V_384 :
if ( ! F_200 ( V_8 ) )
return 1 ;
V_182 = F_6 ( V_8 ) -> V_13 . V_385 ;
break;
case V_359 ... V_386 :
if ( ! F_200 ( V_8 ) )
return 1 ;
return F_205 ( V_8 , V_357 , V_358 ) ;
case V_283 :
if ( ! F_6 ( V_8 ) -> V_284 )
return 1 ;
default:
V_73 = F_65 ( F_6 ( V_8 ) , V_357 ) ;
if ( V_73 ) {
V_182 = V_73 -> V_182 ;
break;
}
return F_209 ( V_8 , V_357 , V_358 ) ;
}
* V_358 = V_182 ;
return 0 ;
}
static int F_210 ( struct V_7 * V_8 , struct V_387 * V_388 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 ;
int V_113 = 0 ;
T_2 V_357 = V_388 -> V_78 ;
T_3 V_182 = V_388 -> V_182 ;
switch ( V_357 ) {
case V_143 :
V_113 = F_211 ( V_8 , V_388 ) ;
break;
#ifdef F_95
case V_206 :
F_115 ( V_72 ) ;
F_98 ( V_376 , V_182 ) ;
break;
case V_208 :
F_115 ( V_72 ) ;
F_98 ( V_377 , V_182 ) ;
break;
case V_209 :
F_149 ( V_72 ) ;
V_72 -> V_211 = V_182 ;
break;
#endif
case V_379 :
F_101 ( V_380 , V_182 ) ;
break;
case V_381 :
F_98 ( V_382 , V_182 ) ;
break;
case V_223 :
F_98 ( V_383 , V_182 ) ;
break;
case V_378 :
F_212 ( V_8 , V_388 ) ;
break;
case V_389 :
if ( V_29 . V_390 & V_325 ) {
F_102 ( V_391 , V_182 ) ;
V_8 -> V_115 . V_392 = V_182 ;
break;
}
V_113 = F_211 ( V_8 , V_388 ) ;
break;
case V_393 :
V_113 = F_211 ( V_8 , V_388 ) ;
break;
case V_384 :
if ( ! F_200 ( V_8 ) ||
( F_6 ( V_8 ) -> V_13 . V_385 &
V_394 && ! V_388 -> V_395 ) )
return 1 ;
V_72 -> V_13 . V_385 = V_182 ;
if ( V_388 -> V_395 && V_182 == 0 )
F_213 ( V_8 ) ;
break;
case V_359 ... V_386 :
return 1 ;
case V_283 :
if ( ! V_72 -> V_284 )
return 1 ;
if ( ( V_182 >> 32 ) != 0 )
return 1 ;
default:
V_73 = F_65 ( V_72 , V_357 ) ;
if ( V_73 ) {
V_73 -> V_182 = V_182 ;
if ( V_73 - V_72 -> V_77 < V_72 -> V_212 ) {
F_150 () ;
F_141 ( V_73 -> V_78 , V_73 -> V_182 ,
V_73 -> V_104 ) ;
F_151 () ;
}
break;
}
V_113 = F_211 ( V_8 , V_388 ) ;
}
return V_113 ;
}
static void F_214 ( struct V_7 * V_8 , enum V_396 V_397 )
{
F_169 ( V_397 , ( unsigned long * ) & V_8 -> V_115 . V_116 ) ;
switch ( V_397 ) {
case V_398 :
V_8 -> V_115 . V_399 [ V_398 ] = F_91 ( V_400 ) ;
break;
case V_401 :
V_8 -> V_115 . V_399 [ V_401 ] = F_91 ( V_402 ) ;
break;
case V_403 :
if ( V_100 )
F_215 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_216 ( void )
{
return F_217 () ;
}
static T_11 int F_218 ( void )
{
T_3 V_73 ;
F_55 ( V_384 , V_73 ) ;
if ( V_73 & V_394 ) {
if ( ! ( V_73 & V_404 )
&& F_219 () )
return 1 ;
if ( ! ( V_73 & V_405 )
&& ( V_73 & V_404 )
&& ! F_219 () ) {
F_68 ( V_165 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_73 & V_405 )
&& ! F_219 () )
return 1 ;
}
return 0 ;
}
static void F_153 ( T_3 V_16 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_220 ( void * V_406 )
{
int V_90 = F_78 () ;
T_3 V_87 = F_67 ( F_81 ( V_216 , V_90 ) ) ;
T_3 V_407 , V_408 ;
if ( F_221 () & V_409 )
return - V_410 ;
F_222 ( & F_81 ( V_220 , V_90 ) ) ;
F_71 ( V_90 ) ;
F_55 ( V_384 , V_407 ) ;
V_408 = V_394 ;
V_408 |= V_405 ;
if ( F_219 () )
V_408 |= V_404 ;
if ( ( V_407 & V_408 ) != V_408 ) {
F_140 ( V_384 , V_407 | V_408 ) ;
}
F_223 ( F_221 () | V_409 ) ;
if ( V_217 ) {
F_153 ( V_87 ) ;
F_89 () ;
}
F_224 ( & F_129 ( V_168 ) ) ;
return 0 ;
}
static void F_225 ( void )
{
int V_90 = F_78 () ;
struct V_89 * V_93 , * V_411 ;
F_226 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_80 ( V_93 ) ;
}
static void F_160 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_227 ( void * V_406 )
{
if ( V_217 ) {
F_225 () ;
F_160 () ;
}
F_223 ( F_221 () & ~ V_409 ) ;
}
static T_11 int F_228 ( T_2 V_412 , T_2 V_413 ,
T_2 V_73 , T_2 * V_414 )
{
T_2 V_415 , V_416 ;
T_2 V_417 = V_412 | V_413 ;
F_202 ( V_73 , V_415 , V_416 ) ;
V_417 &= V_416 ;
V_417 |= V_415 ;
if ( V_412 & ~ V_417 )
return - V_418 ;
* V_414 = V_417 ;
return 0 ;
}
static T_11 bool F_229 ( T_2 V_73 , T_2 V_417 )
{
T_2 V_415 , V_416 ;
F_202 ( V_73 , V_415 , V_416 ) ;
return V_416 & V_417 ;
}
static T_11 int F_230 ( struct V_29 * V_419 )
{
T_2 V_415 , V_416 ;
T_2 V_420 , V_421 , V_422 , V_423 ;
T_2 V_424 = 0 ;
T_2 V_425 = 0 ;
T_2 V_426 = 0 ;
T_2 V_427 = 0 ;
T_2 V_428 = 0 ;
V_420 = V_331 |
#ifdef F_95
V_336 |
V_337 |
#endif
V_334 |
V_335 |
V_340 |
V_338 |
V_296 |
V_333 |
V_341 |
V_332 |
V_342 ;
V_421 = V_32 |
V_31 |
V_33 ;
if ( F_228 ( V_420 , V_421 , V_326 ,
& V_425 ) < 0 )
return - V_418 ;
#ifdef F_95
if ( ( V_425 & V_32 ) )
V_425 &= ~ V_336 &
~ V_337 ;
#endif
if ( V_425 & V_33 ) {
V_422 = 0 ;
V_423 = V_35 |
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
if ( F_228 ( V_422 , V_423 ,
V_345 ,
& V_426 ) < 0 )
return - V_418 ;
}
#ifndef F_95
if ( ! ( V_426 &
V_35 ) )
V_425 &= ~ V_32 ;
#endif
if ( ! ( V_425 & V_32 ) )
V_426 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_426 & V_55 ) {
V_425 &= ~ ( V_334 |
V_335 |
V_332 ) ;
F_202 ( V_374 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_420 = 0 ;
#ifdef F_95
V_420 |= V_315 ;
#endif
V_421 = V_317 | V_316 |
V_429 ;
if ( F_228 ( V_420 , V_421 , V_311 ,
& V_427 ) < 0 )
return - V_418 ;
V_420 = V_308 | V_309 ;
V_421 = V_62 | V_40 ;
if ( F_228 ( V_420 , V_421 , V_304 ,
& V_424 ) < 0 )
return - V_418 ;
if ( ! ( V_426 &
V_38 ) ||
! ( V_427 & V_429 ) )
V_424 &= ~ V_40 ;
V_420 = 0 ;
V_421 = V_325 ;
if ( F_228 ( V_420 , V_421 , V_320 ,
& V_428 ) < 0 )
return - V_418 ;
F_202 ( V_359 , V_415 , V_416 ) ;
if ( ( V_416 & 0x1fff ) > V_430 )
return - V_418 ;
#ifdef F_95
if ( V_416 & ( 1u << 16 ) )
return - V_418 ;
#endif
if ( ( ( V_416 >> 18 ) & 15 ) != 6 )
return - V_418 ;
V_419 -> V_431 = V_416 & 0x1fff ;
V_419 -> V_432 = F_231 ( V_29 . V_431 ) ;
V_419 -> V_433 = V_415 ;
V_419 -> V_39 = V_424 ;
V_419 -> V_30 = V_425 ;
V_419 -> V_34 = V_426 ;
V_419 -> V_434 = V_427 ;
V_419 -> V_390 = V_428 ;
V_144 =
F_229 ( V_320 ,
V_145 )
&& F_229 ( V_311 ,
V_146 ) ;
V_148 =
F_229 ( V_320 ,
V_149 )
&& F_229 ( V_311 ,
V_150 ) ;
if ( V_148 && V_435 . V_436 == 0x6 ) {
switch ( V_435 . V_437 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_148 = false ;
F_127 ( V_165 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_86 * F_232 ( int V_90 )
{
int V_438 = F_233 ( V_90 ) ;
struct V_15 * V_439 ;
struct V_86 * V_86 ;
V_439 = F_234 ( V_438 , V_440 , V_29 . V_432 ) ;
if ( ! V_439 )
return NULL ;
V_86 = F_235 ( V_439 ) ;
memset ( V_86 , 0 , V_29 . V_431 ) ;
V_86 -> V_433 = V_29 . V_433 ;
return V_86 ;
}
static struct V_86 * F_236 ( void )
{
return F_232 ( F_78 () ) ;
}
static void F_237 ( struct V_86 * V_86 )
{
F_238 ( ( unsigned long ) V_86 , V_29 . V_432 ) ;
}
static void F_239 ( struct V_89 * V_89 )
{
if ( ! V_89 -> V_86 )
return;
F_84 ( V_89 ) ;
F_237 ( V_89 -> V_86 ) ;
V_89 -> V_86 = NULL ;
}
static void F_240 ( void )
{
int V_90 ;
F_241 (cpu) {
F_237 ( F_81 ( V_216 , V_90 ) ) ;
F_81 ( V_216 , V_90 ) = NULL ;
}
}
static T_11 int F_242 ( void )
{
int V_90 ;
F_241 (cpu) {
struct V_86 * V_86 ;
V_86 = F_232 ( V_90 ) ;
if ( ! V_86 ) {
F_240 () ;
return - V_441 ;
}
F_81 ( V_216 , V_90 ) = V_86 ;
}
return 0 ;
}
static T_11 int F_243 ( void )
{
if ( F_230 ( & V_29 ) < 0 )
return - V_418 ;
if ( F_244 ( V_442 ) )
F_245 ( V_177 ) ;
if ( ! F_49 () )
V_443 = 0 ;
if ( ! F_54 () )
V_444 = 0 ;
if ( ! F_45 () ||
! F_39 () ) {
V_100 = 0 ;
V_445 = 0 ;
V_446 = 0 ;
}
if ( ! F_40 () )
V_446 = 0 ;
if ( ! F_46 () )
V_445 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_447 -> V_448 = NULL ;
if ( V_100 && ! F_37 () )
F_246 () ;
if ( ! F_47 () )
V_449 = 0 ;
if ( ! F_32 () )
V_450 = 0 ;
if ( V_450 )
V_447 -> V_448 = NULL ;
else {
V_447 -> V_451 = NULL ;
V_447 -> V_452 = NULL ;
V_447 -> V_453 = V_454 ;
}
if ( V_13 )
F_201 () ;
return F_242 () ;
}
static T_12 void F_247 ( void )
{
F_240 () ;
}
static bool F_248 ( struct V_7 * V_8 )
{
return V_455 && ! F_249 ( V_8 ) ;
}
static void F_250 ( struct V_7 * V_8 , int V_112 ,
struct V_456 * V_457 )
{
if ( ! V_455 ) {
if ( V_112 == V_458 || V_112 == V_459 )
V_457 -> V_119 &= ~ V_460 ;
V_457 -> V_461 = V_457 -> V_119 & V_460 ;
V_457 -> V_186 = 1 ;
}
F_251 ( V_8 , V_457 , V_112 ) ;
}
static void F_252 ( struct V_7 * V_8 )
{
unsigned long V_462 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_464 ] , V_464 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_465 ] , V_465 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_466 ] , V_466 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_467 ] , V_467 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_459 ] , V_459 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_458 ] , V_458 ) ;
V_72 -> V_135 . V_136 = 0 ;
F_115 ( V_72 ) ;
F_251 ( V_8 , & V_72 -> V_135 . V_463 [ V_468 ] , V_468 ) ;
V_462 = F_91 ( V_242 ) ;
V_462 &= V_243 ;
V_462 |= V_72 -> V_135 . V_240 & ~ V_243 ;
F_98 ( V_242 , V_462 ) ;
F_98 ( V_469 , ( F_91 ( V_469 ) & ~ V_470 ) |
( F_91 ( V_471 ) & V_470 ) ) ;
F_121 ( V_8 ) ;
F_250 ( V_8 , V_458 , & V_72 -> V_135 . V_463 [ V_458 ] ) ;
F_250 ( V_8 , V_459 , & V_72 -> V_135 . V_463 [ V_459 ] ) ;
F_250 ( V_8 , V_464 , & V_72 -> V_135 . V_463 [ V_464 ] ) ;
F_250 ( V_8 , V_465 , & V_72 -> V_135 . V_463 [ V_465 ] ) ;
F_250 ( V_8 , V_466 , & V_72 -> V_135 . V_463 [ V_466 ] ) ;
F_250 ( V_8 , V_467 , & V_72 -> V_135 . V_463 [ V_467 ] ) ;
F_169 ( V_472 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ;
V_72 -> V_473 = 0 ;
}
static void F_254 ( int V_112 , struct V_456 * V_457 )
{
const struct V_474 * V_475 = & V_121 [ V_112 ] ;
struct V_456 V_476 = * V_457 ;
V_476 . V_461 = 0x3 ;
if ( V_112 == V_458 )
V_476 . type = 0x3 ;
if ( ! V_455 ) {
V_476 . V_119 = V_476 . V_122 >> 4 ;
V_476 . V_122 = V_476 . V_122 & 0xffff0 ;
V_476 . V_124 = 0xffff ;
V_476 . V_477 = 0 ;
V_476 . V_478 = 0 ;
V_476 . V_479 = 1 ;
V_476 . V_186 = 1 ;
V_476 . V_480 = 0 ;
V_476 . V_481 = 0 ;
V_476 . type = 0x3 ;
V_476 . V_482 = 0 ;
if ( V_457 -> V_122 & 0xf )
F_127 ( V_165 L_12
L_13
L_14 , V_112 ) ;
}
F_100 ( V_475 -> V_119 , V_476 . V_119 ) ;
F_101 ( V_475 -> V_122 , V_476 . V_122 ) ;
F_101 ( V_475 -> V_124 , V_476 . V_124 ) ;
F_101 ( V_475 -> V_128 , F_255 ( & V_476 ) ) ;
}
static void F_256 ( struct V_7 * V_8 )
{
unsigned long V_462 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_468 ] , V_468 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_464 ] , V_464 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_465 ] , V_465 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_466 ] , V_466 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_467 ] , V_467 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_459 ] , V_459 ) ;
F_253 ( V_8 , & V_72 -> V_135 . V_463 [ V_458 ] , V_458 ) ;
V_72 -> V_135 . V_136 = 1 ;
if ( ! V_8 -> V_17 -> V_115 . V_483 )
F_127 ( V_165 L_15
L_16 ) ;
F_115 ( V_72 ) ;
F_98 ( V_484 , V_8 -> V_17 -> V_115 . V_483 ) ;
F_101 ( V_485 , V_486 - 1 ) ;
F_101 ( V_487 , 0x008b ) ;
V_462 = F_91 ( V_242 ) ;
V_72 -> V_135 . V_240 = V_462 ;
V_462 |= V_244 | V_245 ;
F_98 ( V_242 , V_462 ) ;
F_98 ( V_469 , F_91 ( V_469 ) | V_470 ) ;
F_121 ( V_8 ) ;
F_254 ( V_459 , & V_72 -> V_135 . V_463 [ V_459 ] ) ;
F_254 ( V_458 , & V_72 -> V_135 . V_463 [ V_458 ] ) ;
F_254 ( V_464 , & V_72 -> V_135 . V_463 [ V_464 ] ) ;
F_254 ( V_465 , & V_72 -> V_135 . V_463 [ V_465 ] ) ;
F_254 ( V_467 , & V_72 -> V_135 . V_463 [ V_467 ] ) ;
F_254 ( V_466 , & V_72 -> V_135 . V_463 [ V_466 ] ) ;
F_257 ( V_8 ) ;
}
static void F_258 ( struct V_7 * V_8 , T_3 V_176 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_85 * V_73 = F_65 ( V_72 , V_143 ) ;
if ( ! V_73 )
return;
F_149 ( F_6 ( V_8 ) ) ;
V_8 -> V_115 . V_176 = V_176 ;
if ( V_176 & V_179 ) {
F_108 ( F_6 ( V_8 ) , V_324 ) ;
V_73 -> V_182 = V_176 ;
} else {
F_109 ( F_6 ( V_8 ) , V_324 ) ;
V_73 -> V_182 = V_176 & ~ V_180 ;
}
F_186 ( V_72 ) ;
}
static void F_259 ( struct V_7 * V_8 )
{
T_2 V_488 ;
F_115 ( F_6 ( V_8 ) ) ;
V_488 = F_93 ( V_487 ) ;
if ( ( V_488 & V_489 ) != V_490 ) {
F_260 ( L_17 ,
V_491 ) ;
F_101 ( V_487 ,
( V_488 & ~ V_489 )
| V_490 ) ;
}
F_258 ( V_8 , V_8 -> V_115 . V_176 | V_179 ) ;
}
static void F_261 ( struct V_7 * V_8 )
{
F_109 ( F_6 ( V_8 ) , V_324 ) ;
F_258 ( V_8 , V_8 -> V_115 . V_176 & ~ V_179 ) ;
}
static void F_262 ( struct V_7 * V_8 )
{
F_88 ( F_6 ( V_8 ) ) ;
if ( V_100 ) {
if ( ! F_263 ( V_8 -> V_115 . V_492 . V_493 ) )
return;
F_90 ( F_264 ( V_8 -> V_115 . V_492 . V_493 ) ) ;
}
}
static void F_166 ( struct V_7 * V_8 )
{
T_9 V_229 = V_8 -> V_115 . V_229 ;
V_8 -> V_115 . V_225 &= ~ V_229 ;
V_8 -> V_115 . V_225 |= F_91 ( V_226 ) & V_229 ;
}
static void F_265 ( struct V_7 * V_8 )
{
if ( V_100 && F_266 ( V_8 ) )
V_8 -> V_115 . V_494 = F_91 ( V_495 ) ;
F_169 ( V_496 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ;
}
static void F_267 ( struct V_7 * V_8 )
{
T_9 V_497 = V_8 -> V_115 . V_497 ;
V_8 -> V_115 . V_498 &= ~ V_497 ;
V_8 -> V_115 . V_498 |= F_91 ( V_469 ) & V_497 ;
}
static void F_268 ( struct V_7 * V_8 )
{
struct V_499 * V_492 = V_8 -> V_115 . V_500 ;
if ( ! F_168 ( V_403 ,
( unsigned long * ) & V_8 -> V_115 . V_501 ) )
return;
if ( F_266 ( V_8 ) && F_269 ( V_8 ) && ! F_139 ( V_8 ) ) {
F_102 ( V_502 , V_492 -> V_503 [ 0 ] ) ;
F_102 ( V_504 , V_492 -> V_503 [ 1 ] ) ;
F_102 ( V_505 , V_492 -> V_503 [ 2 ] ) ;
F_102 ( V_506 , V_492 -> V_503 [ 3 ] ) ;
}
}
static void F_215 ( struct V_7 * V_8 )
{
struct V_499 * V_492 = V_8 -> V_115 . V_500 ;
if ( F_266 ( V_8 ) && F_269 ( V_8 ) && ! F_139 ( V_8 ) ) {
V_492 -> V_503 [ 0 ] = F_94 ( V_502 ) ;
V_492 -> V_503 [ 1 ] = F_94 ( V_504 ) ;
V_492 -> V_503 [ 2 ] = F_94 ( V_505 ) ;
V_492 -> V_503 [ 3 ] = F_94 ( V_506 ) ;
}
F_169 ( V_403 ,
( unsigned long * ) & V_8 -> V_115 . V_116 ) ;
F_169 ( V_403 ,
( unsigned long * ) & V_8 -> V_115 . V_501 ) ;
}
static void F_270 ( unsigned long * V_507 ,
unsigned long V_225 ,
struct V_7 * V_8 )
{
if ( ! F_168 ( V_496 , ( T_9 * ) & V_8 -> V_115 . V_116 ) )
F_265 ( V_8 ) ;
if ( ! ( V_225 & V_508 ) ) {
F_101 ( V_509 ,
F_93 ( V_509 ) |
( V_334 |
V_335 ) ) ;
V_8 -> V_115 . V_225 = V_225 ;
F_271 ( V_8 , F_272 ( V_8 ) ) ;
} else if ( ! F_266 ( V_8 ) ) {
F_101 ( V_509 ,
F_93 ( V_509 ) &
~ ( V_334 |
V_335 ) ) ;
V_8 -> V_115 . V_225 = V_225 ;
F_271 ( V_8 , F_272 ( V_8 ) ) ;
}
if ( ! ( V_225 & V_510 ) )
* V_507 &= ~ V_510 ;
}
static void F_273 ( struct V_7 * V_8 , unsigned long V_225 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_507 ;
V_507 = ( V_225 & ~ V_511 ) ;
if ( V_445 )
V_507 |= V_512 ;
else {
V_507 |= V_513 ;
if ( V_72 -> V_135 . V_136 && ( V_225 & V_514 ) )
F_252 ( V_8 ) ;
if ( ! V_72 -> V_135 . V_136 && ! ( V_225 & V_514 ) )
F_256 ( V_8 ) ;
}
#ifdef F_95
if ( V_8 -> V_115 . V_176 & V_180 ) {
if ( ! F_266 ( V_8 ) && ( V_225 & V_508 ) )
F_259 ( V_8 ) ;
if ( F_266 ( V_8 ) && ! ( V_225 & V_508 ) )
F_261 ( V_8 ) ;
}
#endif
if ( V_100 )
F_270 ( & V_507 , V_225 , V_8 ) ;
if ( ! V_8 -> V_137 )
V_507 |= V_227 | V_228 ;
F_98 ( V_238 , V_225 ) ;
F_98 ( V_226 , V_507 ) ;
V_8 -> V_115 . V_225 = V_225 ;
V_72 -> F_248 = F_248 ( V_8 ) ;
}
static T_3 F_264 ( unsigned long V_493 )
{
T_3 V_83 ;
V_83 = V_515 |
V_516 << V_517 ;
if ( V_446 )
V_83 |= V_518 ;
V_83 |= ( V_493 & V_519 ) ;
return V_83 ;
}
static void F_274 ( struct V_7 * V_8 , unsigned long V_494 )
{
unsigned long V_520 ;
T_3 V_83 ;
V_520 = V_494 ;
if ( V_100 ) {
V_83 = F_264 ( V_494 ) ;
F_102 ( V_521 , V_83 ) ;
if ( F_266 ( V_8 ) || F_122 ( V_8 ) )
V_520 = F_275 ( V_8 ) ;
else
V_520 = V_8 -> V_17 -> V_115 . V_522 ;
F_268 ( V_8 ) ;
}
F_262 ( V_8 ) ;
F_98 ( V_495 , V_520 ) ;
}
static int F_271 ( struct V_7 * V_8 , unsigned long V_498 )
{
unsigned long V_523 = V_498 | ( F_6 ( V_8 ) -> V_135 . V_136 ?
V_524 : V_525 ) ;
if ( V_498 & V_409 ) {
if ( ! F_200 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_526 &&
( ( V_498 & F_207 ) != F_207 ) )
return 1 ;
V_8 -> V_115 . V_498 = V_498 ;
if ( V_100 ) {
if ( ! F_266 ( V_8 ) ) {
V_523 &= ~ V_527 ;
V_523 |= V_528 ;
V_523 &= ~ V_529 ;
} else if ( ! ( V_498 & V_527 ) ) {
V_523 &= ~ V_527 ;
}
}
F_98 ( V_471 , V_498 ) ;
F_98 ( V_469 , V_523 ) ;
return 0 ;
}
static void F_253 ( struct V_7 * V_8 ,
struct V_456 * V_476 , int V_112 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_126 ;
if ( V_72 -> V_135 . V_136 && V_112 != V_530 ) {
* V_476 = V_72 -> V_135 . V_463 [ V_112 ] ;
if ( V_112 == V_468
|| V_476 -> V_119 == F_117 ( V_72 , V_112 ) )
return;
V_476 -> V_122 = F_118 ( V_72 , V_112 ) ;
V_476 -> V_119 = F_117 ( V_72 , V_112 ) ;
return;
}
V_476 -> V_122 = F_118 ( V_72 , V_112 ) ;
V_476 -> V_124 = F_119 ( V_72 , V_112 ) ;
V_476 -> V_119 = F_117 ( V_72 , V_112 ) ;
V_126 = F_120 ( V_72 , V_112 ) ;
V_476 -> V_481 = ( V_126 >> 16 ) & 1 ;
V_476 -> type = V_126 & 15 ;
V_476 -> V_186 = ( V_126 >> 4 ) & 1 ;
V_476 -> V_461 = ( V_126 >> 5 ) & 3 ;
V_476 -> V_479 = ! V_476 -> V_481 ;
V_476 -> V_482 = ( V_126 >> 12 ) & 1 ;
V_476 -> V_480 = ( V_126 >> 13 ) & 1 ;
V_476 -> V_478 = ( V_126 >> 14 ) & 1 ;
V_476 -> V_477 = ( V_126 >> 15 ) & 1 ;
}
static T_3 F_276 ( struct V_7 * V_8 , int V_112 )
{
struct V_456 V_186 ;
if ( F_6 ( V_8 ) -> V_135 . V_136 ) {
F_253 ( V_8 , & V_186 , V_112 ) ;
return V_186 . V_122 ;
}
return F_118 ( F_6 ( V_8 ) , V_112 ) ;
}
static int F_277 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_278 ( V_8 ) )
return 0 ;
if ( ! F_139 ( V_8 )
&& ( F_279 ( V_8 ) & V_245 ) )
return 3 ;
if ( ! F_168 ( V_472 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ) {
F_169 ( V_472 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ;
V_72 -> V_473 = F_117 ( V_72 , V_458 ) & 3 ;
}
return V_72 -> V_473 ;
}
static T_2 F_255 ( struct V_456 * V_476 )
{
T_2 V_126 ;
if ( V_476 -> V_481 || ! V_476 -> V_479 )
V_126 = 1 << 16 ;
else {
V_126 = V_476 -> type & 15 ;
V_126 |= ( V_476 -> V_186 & 1 ) << 4 ;
V_126 |= ( V_476 -> V_461 & 3 ) << 5 ;
V_126 |= ( V_476 -> V_479 & 1 ) << 7 ;
V_126 |= ( V_476 -> V_482 & 1 ) << 12 ;
V_126 |= ( V_476 -> V_480 & 1 ) << 13 ;
V_126 |= ( V_476 -> V_478 & 1 ) << 14 ;
V_126 |= ( V_476 -> V_477 & 1 ) << 15 ;
}
return V_126 ;
}
static void F_251 ( struct V_7 * V_8 ,
struct V_456 * V_476 , int V_112 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
const struct V_474 * V_475 = & V_121 [ V_112 ] ;
F_115 ( V_72 ) ;
if ( V_112 == V_458 )
F_280 ( V_472 , ( T_9 * ) & V_8 -> V_115 . V_116 ) ;
if ( V_72 -> V_135 . V_136 && V_112 != V_530 ) {
V_72 -> V_135 . V_463 [ V_112 ] = * V_476 ;
if ( V_112 == V_468 )
F_100 ( V_475 -> V_119 , V_476 -> V_119 ) ;
else if ( V_476 -> V_186 )
F_254 ( V_112 , & V_72 -> V_135 . V_463 [ V_112 ] ) ;
goto V_531;
}
F_98 ( V_475 -> V_122 , V_476 -> V_122 ) ;
F_101 ( V_475 -> V_124 , V_476 -> V_124 ) ;
F_100 ( V_475 -> V_119 , V_476 -> V_119 ) ;
if ( V_445 && ( V_112 != V_530 ) )
V_476 -> type |= 0x1 ;
F_101 ( V_475 -> V_128 , F_255 ( V_476 ) ) ;
V_531:
V_72 -> F_248 |= F_248 ( V_8 ) ;
}
static void F_281 ( struct V_7 * V_8 , int * V_478 , int * V_480 )
{
T_2 V_126 = F_120 ( F_6 ( V_8 ) , V_458 ) ;
* V_478 = ( V_126 >> 14 ) & 1 ;
* V_480 = ( V_126 >> 13 ) & 1 ;
}
static void F_282 ( struct V_7 * V_8 , struct V_166 * V_532 )
{
V_532 -> V_431 = F_93 ( V_533 ) ;
V_532 -> V_171 = F_91 ( V_534 ) ;
}
static void F_283 ( struct V_7 * V_8 , struct V_166 * V_532 )
{
F_101 ( V_533 , V_532 -> V_431 ) ;
F_98 ( V_534 , V_532 -> V_171 ) ;
}
static void F_284 ( struct V_7 * V_8 , struct V_166 * V_532 )
{
V_532 -> V_431 = F_93 ( V_535 ) ;
V_532 -> V_171 = F_91 ( V_536 ) ;
}
static void F_285 ( struct V_7 * V_8 , struct V_166 * V_532 )
{
F_101 ( V_535 , V_532 -> V_431 ) ;
F_98 ( V_536 , V_532 -> V_171 ) ;
}
static bool F_286 ( struct V_7 * V_8 , int V_112 )
{
struct V_456 V_476 ;
T_2 V_126 ;
F_253 ( V_8 , & V_476 , V_112 ) ;
V_476 . V_461 = 0x3 ;
if ( V_112 == V_458 )
V_476 . type = 0x3 ;
V_126 = F_255 ( & V_476 ) ;
if ( V_476 . V_122 != ( V_476 . V_119 << 4 ) )
return false ;
if ( V_476 . V_124 != 0xffff )
return false ;
if ( V_126 != 0xf3 )
return false ;
return true ;
}
static bool F_287 ( struct V_7 * V_8 )
{
struct V_456 V_537 ;
unsigned int V_538 ;
F_253 ( V_8 , & V_537 , V_458 ) ;
V_538 = V_537 . V_119 & V_460 ;
if ( V_537 . V_481 )
return false ;
if ( ~ V_537 . type & ( V_539 | V_540 ) )
return false ;
if ( ! V_537 . V_186 )
return false ;
if ( V_537 . type & V_541 ) {
if ( V_537 . V_461 > V_538 )
return false ;
} else {
if ( V_537 . V_461 != V_538 )
return false ;
}
if ( ! V_537 . V_479 )
return false ;
return true ;
}
static bool F_288 ( struct V_7 * V_8 )
{
struct V_456 V_542 ;
unsigned int V_543 ;
F_253 ( V_8 , & V_542 , V_459 ) ;
V_543 = V_542 . V_119 & V_460 ;
if ( V_542 . V_481 )
return true ;
if ( V_542 . type != 3 && V_542 . type != 7 )
return false ;
if ( ! V_542 . V_186 )
return false ;
if ( V_542 . V_461 != V_543 )
return false ;
if ( ! V_542 . V_479 )
return false ;
return true ;
}
static bool F_289 ( struct V_7 * V_8 , int V_112 )
{
struct V_456 V_476 ;
unsigned int V_544 ;
F_253 ( V_8 , & V_476 , V_112 ) ;
V_544 = V_476 . V_119 & V_460 ;
if ( V_476 . V_481 )
return true ;
if ( ! V_476 . V_186 )
return false ;
if ( ! V_476 . V_479 )
return false ;
if ( ~ V_476 . type & ( V_539 | V_541 ) ) {
if ( V_476 . V_461 < V_544 )
return false ;
}
return true ;
}
static bool F_290 ( struct V_7 * V_8 )
{
struct V_456 V_189 ;
F_253 ( V_8 , & V_189 , V_468 ) ;
if ( V_189 . V_481 )
return false ;
if ( V_189 . V_119 & V_545 )
return false ;
if ( V_189 . type != 3 && V_189 . type != 11 )
return false ;
if ( ! V_189 . V_479 )
return false ;
return true ;
}
static bool F_291 ( struct V_7 * V_8 )
{
struct V_456 V_546 ;
F_253 ( V_8 , & V_546 , V_530 ) ;
if ( V_546 . V_481 )
return true ;
if ( V_546 . V_119 & V_545 )
return false ;
if ( V_546 . type != 2 )
return false ;
if ( ! V_546 . V_479 )
return false ;
return true ;
}
static bool F_292 ( struct V_7 * V_8 )
{
struct V_456 V_537 , V_542 ;
F_253 ( V_8 , & V_537 , V_458 ) ;
F_253 ( V_8 , & V_542 , V_459 ) ;
return ( ( V_537 . V_119 & V_460 ) ==
( V_542 . V_119 & V_460 ) ) ;
}
static bool F_249 ( struct V_7 * V_8 )
{
if ( V_445 )
return true ;
if ( ! F_278 ( V_8 ) || ( F_167 ( V_8 ) & V_245 ) ) {
if ( ! F_286 ( V_8 , V_458 ) )
return false ;
if ( ! F_286 ( V_8 , V_459 ) )
return false ;
if ( ! F_286 ( V_8 , V_465 ) )
return false ;
if ( ! F_286 ( V_8 , V_464 ) )
return false ;
if ( ! F_286 ( V_8 , V_466 ) )
return false ;
if ( ! F_286 ( V_8 , V_467 ) )
return false ;
} else {
if ( ! F_292 ( V_8 ) )
return false ;
if ( ! F_287 ( V_8 ) )
return false ;
if ( ! F_288 ( V_8 ) )
return false ;
if ( ! F_289 ( V_8 , V_465 ) )
return false ;
if ( ! F_289 ( V_8 , V_464 ) )
return false ;
if ( ! F_289 ( V_8 , V_466 ) )
return false ;
if ( ! F_289 ( V_8 , V_467 ) )
return false ;
if ( ! F_290 ( V_8 ) )
return false ;
if ( ! F_291 ( V_8 ) )
return false ;
}
return true ;
}
static int F_293 ( struct V_17 * V_17 )
{
T_13 V_547 ;
T_4 V_182 = 0 ;
int V_548 , V_549 , V_113 = 0 ;
V_549 = F_294 ( & V_17 -> V_550 ) ;
V_547 = V_17 -> V_115 . V_483 >> V_18 ;
V_548 = F_295 ( V_17 , V_547 , 0 , V_430 ) ;
if ( V_548 < 0 )
goto V_531;
V_182 = V_551 + V_552 ;
V_548 = F_296 ( V_17 , V_547 ++ , & V_182 ,
V_553 , sizeof( T_4 ) ) ;
if ( V_548 < 0 )
goto V_531;
V_548 = F_295 ( V_17 , V_547 ++ , 0 , V_430 ) ;
if ( V_548 < 0 )
goto V_531;
V_548 = F_295 ( V_17 , V_547 , 0 , V_430 ) ;
if ( V_548 < 0 )
goto V_531;
V_182 = ~ 0 ;
V_548 = F_296 ( V_17 , V_547 , & V_182 ,
V_486 - 2 * V_430 - 1 ,
sizeof( T_6 ) ) ;
if ( V_548 < 0 )
goto V_531;
V_113 = 1 ;
V_531:
F_297 ( & V_17 -> V_550 , V_549 ) ;
return V_113 ;
}
static int F_298 ( struct V_17 * V_17 )
{
int V_74 , V_549 , V_548 , V_113 ;
T_14 V_554 ;
T_2 V_272 ;
if ( ! V_100 )
return 1 ;
if ( F_99 ( ! V_17 -> V_115 . V_555 ) ) {
F_68 ( V_88 L_18
L_19 ) ;
return 0 ;
}
if ( F_299 ( V_17 -> V_115 . V_556 ) )
return 1 ;
V_113 = 0 ;
V_554 = V_17 -> V_115 . V_522 >> V_18 ;
V_549 = F_294 ( & V_17 -> V_550 ) ;
V_548 = F_295 ( V_17 , V_554 , 0 , V_430 ) ;
if ( V_548 < 0 )
goto V_531;
for ( V_74 = 0 ; V_74 < V_557 ; V_74 ++ ) {
V_272 = ( V_74 << 22 ) + ( V_558 | V_559 | V_560 |
V_561 | V_562 | V_563 ) ;
V_548 = F_296 ( V_17 , V_554 ,
& V_272 , V_74 * sizeof( V_272 ) , sizeof( V_272 ) ) ;
if ( V_548 < 0 )
goto V_531;
}
V_17 -> V_115 . V_556 = true ;
V_113 = 1 ;
V_531:
F_297 ( & V_17 -> V_550 , V_549 ) ;
return V_113 ;
}
static void F_300 ( int V_112 )
{
const struct V_474 * V_475 = & V_121 [ V_112 ] ;
unsigned int V_126 ;
F_100 ( V_475 -> V_119 , 0 ) ;
F_98 ( V_475 -> V_122 , 0 ) ;
F_101 ( V_475 -> V_124 , 0xffff ) ;
V_126 = 0x93 ;
if ( V_112 == V_458 )
V_126 |= 0x08 ;
F_101 ( V_475 -> V_128 , V_126 ) ;
}
static int F_301 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_564 V_565 ;
int V_548 = 0 ;
F_302 ( & V_17 -> V_566 ) ;
if ( V_17 -> V_115 . V_567 )
goto V_531;
V_565 . V_568 = V_569 ;
V_565 . V_462 = 0 ;
V_565 . V_570 = 0xfee00000ULL ;
V_565 . V_571 = V_430 ;
V_548 = F_303 ( V_17 , & V_565 ) ;
if ( V_548 )
goto V_531;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_548 = - V_572 ;
goto V_531;
}
V_17 -> V_115 . V_567 = V_15 ;
V_531:
F_304 ( & V_17 -> V_566 ) ;
return V_548 ;
}
static int F_305 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_564 V_565 ;
int V_548 = 0 ;
F_302 ( & V_17 -> V_566 ) ;
if ( V_17 -> V_115 . V_555 )
goto V_531;
V_565 . V_568 = V_573 ;
V_565 . V_462 = 0 ;
V_565 . V_570 =
V_17 -> V_115 . V_522 ;
V_565 . V_571 = V_430 ;
V_548 = F_303 ( V_17 , & V_565 ) ;
if ( V_548 )
goto V_531;
V_15 = F_11 ( V_17 , V_17 -> V_115 . V_522 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_548 = - V_572 ;
goto V_531;
}
V_17 -> V_115 . V_555 = V_15 ;
V_531:
F_304 ( & V_17 -> V_566 ) ;
return V_548 ;
}
static void F_306 ( struct V_6 * V_72 )
{
int V_52 ;
V_72 -> V_52 = 0 ;
if ( ! V_443 )
return;
F_307 ( & V_574 ) ;
V_52 = F_308 ( V_575 , V_576 ) ;
if ( V_52 < V_576 ) {
V_72 -> V_52 = V_52 ;
F_169 ( V_52 , V_575 ) ;
}
F_309 ( & V_574 ) ;
}
static void F_310 ( struct V_6 * V_72 )
{
if ( ! V_443 )
return;
F_307 ( & V_574 ) ;
if ( V_72 -> V_52 != 0 )
F_280 ( V_72 -> V_52 , V_575 ) ;
F_309 ( & V_574 ) ;
}
static void F_311 ( unsigned long * V_273 ,
T_2 V_73 , int type )
{
int V_577 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_578 )
F_280 ( V_73 , V_273 + 0x000 / V_577 ) ;
if ( type & V_579 )
F_280 ( V_73 , V_273 + 0x800 / V_577 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_578 )
F_280 ( V_73 , V_273 + 0x400 / V_577 ) ;
if ( type & V_579 )
F_280 ( V_73 , V_273 + 0xc00 / V_577 ) ;
}
}
static void F_312 ( unsigned long * V_273 ,
T_2 V_73 , int type )
{
int V_577 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_73 <= 0x1fff ) {
if ( type & V_578 )
F_169 ( V_73 , V_273 + 0x000 / V_577 ) ;
if ( type & V_579 )
F_169 ( V_73 , V_273 + 0x800 / V_577 ) ;
} else if ( ( V_73 >= 0xc0000000 ) && ( V_73 <= 0xc0001fff ) ) {
V_73 &= 0x1fff ;
if ( type & V_578 )
F_169 ( V_73 , V_273 + 0x400 / V_577 ) ;
if ( type & V_579 )
F_169 ( V_73 , V_273 + 0xc00 / V_577 ) ;
}
}
static void F_313 ( T_2 V_73 , bool V_580 )
{
if ( ! V_580 )
F_311 ( V_278 ,
V_73 , V_578 | V_579 ) ;
F_311 ( V_277 ,
V_73 , V_578 | V_579 ) ;
}
static void F_314 ( T_2 V_73 )
{
F_312 ( V_276 ,
V_73 , V_578 ) ;
F_312 ( V_275 ,
V_73 , V_578 ) ;
}
static void F_315 ( T_2 V_73 )
{
F_311 ( V_276 ,
V_73 , V_578 ) ;
F_311 ( V_275 ,
V_73 , V_578 ) ;
}
static void F_316 ( T_2 V_73 )
{
F_311 ( V_276 ,
V_73 , V_579 ) ;
F_311 ( V_275 ,
V_73 , V_579 ) ;
}
static int F_317 ( struct V_17 * V_17 )
{
return V_450 && F_25 ( V_17 ) ;
}
static void F_318 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_548 ;
if ( F_5 ( V_4 , & V_72 -> V_1 ) )
return;
V_548 = F_1 ( & V_72 -> V_1 ) ;
F_154 ( V_581 , V_8 ) ;
#ifdef F_319
if ( ! V_548 && ( V_8 -> V_582 == V_583 ) )
V_274 -> V_584 ( F_320 ( V_8 -> V_90 ) ,
V_585 ) ;
else
#endif
F_321 ( V_8 ) ;
}
static void F_322 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_72 -> V_1 ) )
return;
F_323 ( V_8 , V_72 -> V_1 . V_5 ) ;
}
static void V_454 ( struct V_7 * V_8 )
{
return;
}
static void F_324 ( struct V_6 * V_72 )
{
T_2 V_586 , V_587 ;
unsigned long V_588 ;
struct V_166 V_532 ;
F_98 ( V_589 , F_325 () & ~ V_227 ) ;
F_98 ( V_590 , F_221 () ) ;
F_98 ( V_591 , F_326 () ) ;
F_100 ( V_592 , V_593 ) ;
#ifdef F_95
F_100 ( V_594 , 0 ) ;
F_100 ( V_595 , 0 ) ;
#else
F_100 ( V_594 , V_596 ) ;
F_100 ( V_595 , V_596 ) ;
#endif
F_100 ( V_597 , V_596 ) ;
F_100 ( V_598 , V_172 * 8 ) ;
F_327 ( & V_532 ) ;
F_98 ( V_599 , V_532 . V_171 ) ;
V_72 -> V_600 = V_532 . V_171 ;
F_98 ( V_601 , V_602 ) ;
F_202 ( V_379 , V_586 , V_587 ) ;
F_101 ( V_603 , V_586 ) ;
F_55 ( V_381 , V_588 ) ;
F_98 ( V_604 , V_588 ) ;
if ( V_29 . V_434 & V_316 ) {
F_202 ( V_389 , V_586 , V_587 ) ;
F_102 ( V_605 , V_586 | ( ( T_3 ) V_587 << 32 ) ) ;
}
}
static void F_328 ( struct V_6 * V_72 )
{
V_72 -> V_8 . V_115 . V_497 = V_606 ;
if ( V_100 )
V_72 -> V_8 . V_115 . V_497 |= V_607 ;
if ( F_122 ( & V_72 -> V_8 ) )
V_72 -> V_8 . V_115 . V_497 &=
~ F_9 ( & V_72 -> V_8 ) -> V_236 ;
F_98 ( V_608 , ~ V_72 -> V_8 . V_115 . V_497 ) ;
}
static T_2 F_329 ( struct V_6 * V_72 )
{
T_2 V_39 = V_29 . V_39 ;
if ( ! F_317 ( V_72 -> V_8 . V_17 ) )
V_39 &= ~ V_40 ;
return V_39 ;
}
static T_2 F_330 ( struct V_6 * V_72 )
{
T_2 V_609 = V_29 . V_30 ;
if ( ! F_24 ( V_72 -> V_8 . V_17 ) ) {
V_609 &= ~ V_32 ;
#ifdef F_95
V_609 |= V_337 |
V_336 ;
#endif
}
if ( ! V_100 )
V_609 |= V_335 |
V_334 |
V_332 ;
return V_609 ;
}
static T_2 F_331 ( struct V_6 * V_72 )
{
T_2 V_609 = V_29 . V_34 ;
if ( ! F_48 ( V_72 -> V_8 . V_17 ) )
V_609 &= ~ V_35 ;
if ( V_72 -> V_52 == 0 )
V_609 &= ~ V_59 ;
if ( ! V_100 ) {
V_609 &= ~ V_55 ;
V_445 = 0 ;
V_609 &= ~ V_61 ;
}
if ( ! V_445 )
V_609 &= ~ V_56 ;
if ( ! V_449 )
V_609 &= ~ V_57 ;
if ( ! F_317 ( V_72 -> V_8 . V_17 ) )
V_609 &= ~ ( V_37 |
V_38 ) ;
V_609 &= ~ V_36 ;
V_609 &= ~ V_67 ;
return V_609 ;
}
static void F_332 ( void )
{
F_333 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_334 ( struct V_6 * V_72 )
{
#ifdef F_95
unsigned long V_610 ;
#endif
int V_74 ;
F_102 ( V_611 , F_67 ( V_612 ) ) ;
F_102 ( V_613 , F_67 ( V_614 ) ) ;
if ( V_444 ) {
F_102 ( V_615 , F_67 ( V_616 ) ) ;
F_102 ( V_617 , F_67 ( V_618 ) ) ;
}
if ( F_22 () )
F_102 ( V_279 , F_67 ( V_278 ) ) ;
F_102 ( V_619 , - 1ull ) ;
F_101 ( V_620 , F_329 ( V_72 ) ) ;
F_101 ( V_509 , F_330 ( V_72 ) ) ;
if ( F_26 () ) {
F_101 ( V_621 ,
F_331 ( V_72 ) ) ;
}
if ( F_317 ( V_72 -> V_8 . V_17 ) ) {
F_102 ( V_622 , 0 ) ;
F_102 ( V_623 , 0 ) ;
F_102 ( V_624 , 0 ) ;
F_102 ( V_625 , 0 ) ;
F_100 ( V_626 , 0 ) ;
F_102 ( V_627 , V_585 ) ;
F_102 ( V_628 , F_67 ( ( & V_72 -> V_1 ) ) ) ;
}
if ( V_449 ) {
F_101 ( V_629 , V_449 ) ;
F_101 ( V_630 , V_631 ) ;
}
F_101 ( V_632 , 0 ) ;
F_101 ( V_633 , 0 ) ;
F_101 ( V_634 , 0 ) ;
F_100 ( V_196 , 0 ) ;
F_100 ( V_200 , 0 ) ;
F_324 ( V_72 ) ;
#ifdef F_95
F_55 ( V_206 , V_610 ) ;
F_98 ( V_205 , V_610 ) ;
F_55 ( V_208 , V_610 ) ;
F_98 ( V_207 , V_610 ) ;
#else
F_98 ( V_205 , 0 ) ;
F_98 ( V_207 , 0 ) ;
#endif
F_101 ( V_635 , 0 ) ;
F_101 ( V_155 , 0 ) ;
F_102 ( V_636 , F_67 ( V_72 -> V_141 . V_153 ) ) ;
F_101 ( V_154 , 0 ) ;
F_102 ( V_637 , F_67 ( V_72 -> V_141 . V_152 ) ) ;
if ( V_29 . V_390 & V_325 ) {
T_2 V_638 , V_639 ;
T_3 V_640 ;
F_202 ( V_389 , V_638 , V_639 ) ;
V_640 = V_638 | ( ( T_3 ) V_639 << 32 ) ;
F_102 ( V_391 , V_640 ) ;
V_72 -> V_8 . V_115 . V_392 = V_640 ;
}
for ( V_74 = 0 ; V_74 < V_641 ; ++ V_74 ) {
T_2 V_78 = V_76 [ V_74 ] ;
T_2 V_642 , V_643 ;
int V_644 = V_72 -> V_75 ;
if ( F_335 ( V_78 , & V_642 , & V_643 ) < 0 )
continue;
if ( F_336 ( V_78 , V_642 , V_643 ) < 0 )
continue;
V_72 -> V_77 [ V_644 ] . V_78 = V_74 ;
V_72 -> V_77 [ V_644 ] . V_182 = 0 ;
V_72 -> V_77 [ V_644 ] . V_104 = - 1ull ;
++ V_72 -> V_75 ;
}
F_110 ( V_72 , V_29 . V_434 ) ;
F_105 ( V_72 , V_29 . V_390 ) ;
F_98 ( V_231 , ~ 0UL ) ;
F_328 ( V_72 ) ;
return 0 ;
}
static void F_337 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_387 V_645 ;
V_72 -> V_135 . V_136 = 0 ;
V_72 -> V_646 = 0 ;
V_72 -> V_8 . V_115 . V_399 [ V_647 ] = F_338 () ;
F_339 ( & V_72 -> V_8 , 0 ) ;
V_645 . V_182 = 0xfee00000 | V_648 ;
if ( F_340 ( & V_72 -> V_8 ) )
V_645 . V_182 |= V_649 ;
V_645 . V_395 = true ;
F_341 ( & V_72 -> V_8 , & V_645 ) ;
F_115 ( V_72 ) ;
F_300 ( V_458 ) ;
F_100 ( V_650 , 0xf000 ) ;
F_101 ( V_651 , 0xffff0000 ) ;
F_300 ( V_465 ) ;
F_300 ( V_464 ) ;
F_300 ( V_466 ) ;
F_300 ( V_467 ) ;
F_300 ( V_459 ) ;
F_100 ( V_652 , 0 ) ;
F_98 ( V_484 , 0 ) ;
F_101 ( V_485 , 0xffff ) ;
F_101 ( V_487 , 0x008b ) ;
F_100 ( V_653 , 0 ) ;
F_98 ( V_654 , 0 ) ;
F_101 ( V_655 , 0xffff ) ;
F_101 ( V_656 , 0x00082 ) ;
F_101 ( V_380 , 0 ) ;
F_98 ( V_383 , 0 ) ;
F_98 ( V_382 , 0 ) ;
F_98 ( V_242 , 0x02 ) ;
F_175 ( V_8 , 0xfff0 ) ;
F_98 ( V_536 , 0 ) ;
F_101 ( V_535 , 0xffff ) ;
F_98 ( V_534 , 0 ) ;
F_101 ( V_533 , 0xffff ) ;
F_101 ( V_657 , V_658 ) ;
F_101 ( V_247 , 0 ) ;
F_101 ( V_659 , 0 ) ;
F_102 ( V_660 , 0 ) ;
F_186 ( V_72 ) ;
F_101 ( V_269 , 0 ) ;
if ( F_23 () ) {
F_102 ( V_661 , 0 ) ;
if ( F_24 ( V_72 -> V_8 . V_17 ) )
F_102 ( V_661 ,
F_67 ( V_72 -> V_8 . V_115 . V_274 -> V_399 ) ) ;
F_101 ( V_662 , 0 ) ;
}
if ( F_48 ( V_72 -> V_8 . V_17 ) )
F_102 ( V_663 ,
F_342 ( V_72 -> V_8 . V_17 -> V_115 . V_567 ) ) ;
if ( F_317 ( V_8 -> V_17 ) )
memset ( & V_72 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_72 -> V_52 != 0 )
F_100 ( V_664 , V_72 -> V_52 ) ;
V_72 -> V_8 . V_115 . V_225 = V_665 | V_666 | V_667 ;
F_273 ( & V_72 -> V_8 , F_343 ( V_8 ) ) ;
F_271 ( & V_72 -> V_8 , 0 ) ;
F_258 ( & V_72 -> V_8 , 0 ) ;
F_161 ( & V_72 -> V_8 ) ;
F_121 ( & V_72 -> V_8 ) ;
F_88 ( V_72 ) ;
}
static bool F_344 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_308 ;
}
static bool F_345 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_309 ;
}
static int F_346 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( F_122 ( V_8 ) && F_344 ( V_8 ) )
return - V_410 ;
V_69 = F_93 ( V_509 ) ;
V_69 |= V_329 ;
F_101 ( V_509 , V_69 ) ;
return 0 ;
}
static int F_347 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () )
return F_346 ( V_8 ) ;
if ( F_93 ( V_247 ) & V_248 )
return F_346 ( V_8 ) ;
V_69 = F_93 ( V_509 ) ;
V_69 |= V_330 ;
F_101 ( V_509 , V_69 ) ;
return 0 ;
}
static void F_348 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_15 V_668 ;
int V_669 = V_8 -> V_115 . V_670 . V_151 ;
F_349 ( V_669 ) ;
++ V_8 -> V_213 . V_671 ;
if ( V_72 -> V_135 . V_136 ) {
int V_263 = 0 ;
if ( V_8 -> V_115 . V_670 . V_672 )
V_263 = V_8 -> V_115 . V_264 ;
if ( F_180 ( V_8 , V_669 , V_263 ) != V_265 )
F_154 ( V_266 , V_8 ) ;
return;
}
V_668 = V_669 | V_22 ;
if ( V_8 -> V_115 . V_670 . V_672 ) {
V_668 |= V_673 ;
F_101 ( V_267 ,
V_72 -> V_8 . V_115 . V_264 ) ;
} else
V_668 |= V_27 ;
F_101 ( V_269 , V_668 ) ;
}
static void F_350 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( F_122 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_72 -> V_646 = 1 ;
V_72 -> V_674 = 0 ;
}
++ V_8 -> V_213 . V_675 ;
V_72 -> V_676 = false ;
if ( V_72 -> V_135 . V_136 ) {
if ( F_180 ( V_8 , V_677 , 0 ) != V_265 )
F_154 ( V_266 , V_8 ) ;
return;
}
F_101 ( V_269 ,
V_678 | V_22 | V_677 ) ;
}
static bool F_351 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_646 ;
if ( F_6 ( V_8 ) -> V_676 )
return false ;
return F_93 ( V_247 ) & V_679 ;
}
static void F_352 ( struct V_7 * V_8 , bool V_680 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_72 -> V_646 != V_680 ) {
V_72 -> V_646 = V_680 ;
V_72 -> V_674 = 0 ;
}
} else {
V_72 -> V_676 = ! V_680 ;
if ( V_680 )
F_104 ( V_247 ,
V_679 ) ;
else
F_103 ( V_247 ,
V_679 ) ;
}
}
static int F_353 ( struct V_7 * V_8 )
{
if ( F_122 ( V_8 ) ) {
if ( F_6 ( V_8 ) -> V_13 . V_681 )
return 0 ;
if ( F_345 ( V_8 ) ) {
F_177 ( V_8 , V_682 ,
V_677 | V_678 |
V_22 , 0 ) ;
V_8 -> V_115 . V_683 = 0 ;
F_352 ( V_8 , true ) ;
return 0 ;
}
}
if ( ! F_52 () && F_6 ( V_8 ) -> V_646 )
return 0 ;
return ! ( F_93 ( V_247 ) &
( V_250 | V_248
| V_679 ) ) ;
}
static int F_354 ( struct V_7 * V_8 )
{
if ( F_122 ( V_8 ) ) {
if ( F_6 ( V_8 ) -> V_13 . V_681 )
return 0 ;
if ( F_344 ( V_8 ) ) {
F_177 ( V_8 , V_684 ,
0 , 0 ) ;
}
}
return ( F_91 ( V_242 ) & V_685 ) &&
! ( F_93 ( V_247 ) &
( V_248 | V_250 ) ) ;
}
static int F_355 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_113 ;
struct V_564 V_686 = {
. V_568 = V_687 ,
. V_570 = V_16 ,
. V_571 = V_430 * 3 ,
. V_462 = 0 ,
} ;
V_113 = F_356 ( V_17 , & V_686 ) ;
if ( V_113 )
return V_113 ;
V_17 -> V_115 . V_483 = V_16 ;
if ( ! F_293 ( V_17 ) )
return - V_441 ;
return 0 ;
}
static bool F_357 ( struct V_7 * V_8 , int V_688 )
{
switch ( V_688 ) {
case V_134 :
F_6 ( V_8 ) -> V_8 . V_115 . V_264 =
F_93 ( V_254 ) ;
if ( V_8 -> V_131 & V_133 )
return false ;
case V_130 :
if ( V_8 -> V_131 &
( V_689 | V_690 ) )
return false ;
case V_691 :
case V_692 :
case V_693 :
case V_26 :
case V_694 :
case V_695 :
case V_696 :
case V_697 :
return true ;
break;
}
return false ;
}
static int F_358 ( struct V_7 * V_8 ,
int V_688 , T_2 V_698 )
{
if ( ( ( V_688 == V_696 ) || ( V_688 == V_695 ) ) && V_698 == 0 ) {
if ( F_359 ( V_8 , 0 ) == V_265 ) {
if ( V_8 -> V_115 . V_699 ) {
V_8 -> V_115 . V_699 = 0 ;
return F_360 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_361 ( V_8 , V_688 ) ;
return 1 ;
}
static void F_362 ( void )
{
#if F_363 ( V_700 ) && F_363 ( F_95 )
struct V_701 V_399 = {
. V_537 = 3 ,
. V_462 = V_685 ,
} ;
F_364 ( & V_399 , 0 ) ;
#endif
}
static int F_365 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_366 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_702 * V_702 = V_8 -> V_703 ;
T_2 V_19 , V_704 , V_259 ;
unsigned long V_705 , V_253 , V_706 ;
T_2 V_707 ;
enum V_708 V_709 ;
V_707 = V_72 -> V_710 ;
V_19 = V_72 -> V_711 ;
if ( F_21 ( V_19 ) )
return F_365 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_678 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_161 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_709 = F_359 ( V_8 , V_712 ) ;
if ( V_709 != V_265 )
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
V_259 = 0 ;
if ( V_19 & V_262 )
V_259 = F_93 ( V_713 ) ;
if ( ( V_707 & V_714 ) &&
! ( F_17 ( V_19 ) && ! ( V_259 & V_715 ) ) ) {
V_8 -> V_703 -> V_255 = V_716 ;
V_8 -> V_703 -> V_717 . V_718 = V_719 ;
V_8 -> V_703 -> V_717 . V_720 = 2 ;
V_8 -> V_703 -> V_717 . V_182 [ 0 ] = V_707 ;
V_8 -> V_703 -> V_717 . V_182 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_367 ( V_100 ) ;
V_705 = F_91 ( V_257 ) ;
F_368 ( V_705 , V_259 ) ;
if ( F_369 ( V_8 ) )
F_370 ( V_8 , V_705 ) ;
return F_371 ( V_8 , V_705 , V_259 , NULL , 0 ) ;
}
V_704 = V_19 & V_21 ;
if ( V_72 -> V_135 . V_136 && F_357 ( V_8 , V_704 ) )
return F_358 ( V_8 , V_704 , V_259 ) ;
switch ( V_704 ) {
case V_130 :
V_706 = F_91 ( V_257 ) ;
if ( ! ( V_8 -> V_131 &
( V_689 | V_690 ) ) ) {
V_8 -> V_115 . V_706 &= ~ 15 ;
V_8 -> V_115 . V_706 |= V_706 ;
F_361 ( V_8 , V_130 ) ;
return 1 ;
}
V_702 -> V_721 . V_115 . V_706 = V_706 | V_722 ;
V_702 -> V_721 . V_115 . V_723 = F_91 ( V_724 ) ;
case V_134 :
V_72 -> V_8 . V_115 . V_264 =
F_93 ( V_254 ) ;
V_702 -> V_255 = V_725 ;
V_253 = F_174 ( V_8 ) ;
V_702 -> V_721 . V_115 . V_726 = F_91 ( V_651 ) + V_253 ;
V_702 -> V_721 . V_115 . V_727 = V_704 ;
break;
default:
V_702 -> V_255 = V_728 ;
V_702 -> V_729 . V_727 = V_704 ;
V_702 -> V_729 . V_259 = V_259 ;
break;
}
return 0 ;
}
static int F_372 ( struct V_7 * V_8 )
{
++ V_8 -> V_213 . V_730 ;
return 1 ;
}
static int F_373 ( struct V_7 * V_8 )
{
V_8 -> V_703 -> V_255 = V_731 ;
return 0 ;
}
static int F_374 ( struct V_7 * V_8 )
{
unsigned long V_732 ;
int V_431 , V_733 , string ;
unsigned V_734 ;
V_732 = F_91 ( V_257 ) ;
string = ( V_732 & 16 ) != 0 ;
V_733 = ( V_732 & 8 ) != 0 ;
++ V_8 -> V_213 . V_735 ;
if ( string || V_733 )
return F_359 ( V_8 , 0 ) == V_265 ;
V_734 = V_732 >> 16 ;
V_431 = ( V_732 & 7 ) + 1 ;
F_173 ( V_8 ) ;
return F_375 ( V_8 , V_431 , V_734 ) ;
}
static void
F_376 ( struct V_7 * V_8 , unsigned char * V_736 )
{
V_736 [ 0 ] = 0x0f ;
V_736 [ 1 ] = 0x01 ;
V_736 [ 2 ] = 0xc1 ;
}
static bool F_377 ( struct V_12 * V_12 , unsigned long V_105 )
{
unsigned long V_737 = F_206 ;
if ( V_347 &
V_56 &&
F_58 ( V_12 , V_56 ) )
V_737 &= ~ ( V_514 | V_508 ) ;
return ( V_105 & V_737 ) == V_737 ;
}
static int F_378 ( struct V_7 * V_8 , unsigned long V_105 )
{
if ( F_122 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_738 = V_105 ;
V_105 = ( V_105 & ~ V_12 -> V_230 ) |
( V_12 -> V_233 & V_12 -> V_230 ) ;
if ( ! F_377 ( V_12 , V_105 ) )
return 1 ;
if ( F_379 ( V_8 , V_105 ) )
return 1 ;
F_98 ( V_238 , V_738 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_526 &&
( ( V_105 & F_206 ) != F_206 ) )
return 1 ;
return F_379 ( V_8 , V_105 ) ;
}
}
static int F_380 ( struct V_7 * V_8 , unsigned long V_105 )
{
if ( F_122 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_738 = V_105 ;
V_105 = ( V_105 & ~ V_12 -> V_236 ) |
( V_12 -> V_235 & V_12 -> V_236 ) ;
if ( F_381 ( V_8 , V_105 ) )
return 1 ;
F_98 ( V_471 , V_738 ) ;
return 0 ;
} else
return F_381 ( V_8 , V_105 ) ;
}
static void F_382 ( struct V_7 * V_8 )
{
if ( F_122 ( V_8 ) ) {
F_98 ( V_238 ,
F_91 ( V_238 ) & ~ V_227 ) ;
V_8 -> V_115 . V_225 &= ~ V_227 ;
} else
F_273 ( V_8 , F_162 ( V_8 , ~ V_227 ) ) ;
}
static int F_383 ( struct V_7 * V_8 )
{
unsigned long V_732 , V_105 ;
int V_739 ;
int V_397 ;
int V_740 ;
V_732 = F_91 ( V_257 ) ;
V_739 = V_732 & 15 ;
V_397 = ( V_732 >> 8 ) & 15 ;
switch ( ( V_732 >> 4 ) & 3 ) {
case 0 :
V_105 = F_384 ( V_8 , V_397 ) ;
F_385 ( V_739 , V_105 ) ;
switch ( V_739 ) {
case 0 :
V_740 = F_378 ( V_8 , V_105 ) ;
F_386 ( V_8 , V_740 ) ;
return 1 ;
case 3 :
V_740 = F_387 ( V_8 , V_105 ) ;
F_386 ( V_8 , V_740 ) ;
return 1 ;
case 4 :
V_740 = F_380 ( V_8 , V_105 ) ;
F_386 ( V_8 , V_740 ) ;
return 1 ;
case 8 : {
T_6 V_741 = F_388 ( V_8 ) ;
T_6 V_742 = F_384 ( V_8 , V_397 ) ;
V_740 = F_339 ( V_8 , V_742 ) ;
F_386 ( V_8 , V_740 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_741 <= V_742 )
return 1 ;
V_8 -> V_703 -> V_255 = V_743 ;
return 0 ;
}
}
break;
case 2 :
F_382 ( V_8 ) ;
F_385 ( 0 , F_343 ( V_8 ) ) ;
F_173 ( V_8 ) ;
F_161 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_739 ) {
case 3 :
V_105 = F_275 ( V_8 ) ;
F_389 ( V_8 , V_397 , V_105 ) ;
F_390 ( V_739 , V_105 ) ;
F_173 ( V_8 ) ;
return 1 ;
case 8 :
V_105 = F_388 ( V_8 ) ;
F_389 ( V_8 , V_397 , V_105 ) ;
F_390 ( V_739 , V_105 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_105 = ( V_732 >> V_744 ) & 0x0f ;
F_385 ( 0 , ( F_343 ( V_8 ) & ~ 0xful ) | V_105 ) ;
F_391 ( V_8 , V_105 ) ;
F_173 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_703 -> V_255 = 0 ;
F_392 ( V_8 , L_20 ,
( int ) ( V_732 >> 4 ) & 3 , V_739 ) ;
return 0 ;
}
static int F_393 ( struct V_7 * V_8 )
{
unsigned long V_732 ;
int V_745 , V_397 ;
if ( ! F_394 ( V_8 , 0 ) )
return 1 ;
V_745 = F_91 ( V_724 ) ;
if ( V_745 & V_746 ) {
if ( V_8 -> V_131 & V_690 ) {
V_8 -> V_703 -> V_721 . V_115 . V_706 = V_8 -> V_115 . V_706 ;
V_8 -> V_703 -> V_721 . V_115 . V_723 = V_745 ;
V_8 -> V_703 -> V_721 . V_115 . V_726 =
F_91 ( V_651 ) +
F_91 ( V_402 ) ;
V_8 -> V_703 -> V_721 . V_115 . V_727 = V_130 ;
V_8 -> V_703 -> V_255 = V_725 ;
return 0 ;
} else {
V_8 -> V_115 . V_723 &= ~ V_746 ;
V_8 -> V_115 . V_706 |= V_747 ;
F_98 ( V_724 , V_8 -> V_115 . V_723 ) ;
F_361 ( V_8 , V_130 ) ;
return 1 ;
}
}
V_732 = F_91 ( V_257 ) ;
V_745 = V_732 & V_748 ;
V_397 = F_395 ( V_732 ) ;
if ( V_732 & V_749 ) {
unsigned long V_105 ;
if ( F_396 ( V_8 , V_745 , & V_105 ) )
return 1 ;
F_389 ( V_8 , V_397 , V_105 ) ;
} else
if ( F_397 ( V_8 , V_745 , V_8 -> V_115 . V_399 [ V_397 ] ) )
return 1 ;
F_173 ( V_8 ) ;
return 1 ;
}
static T_3 F_398 ( struct V_7 * V_8 )
{
return V_8 -> V_115 . V_706 ;
}
static void F_399 ( struct V_7 * V_8 , unsigned long V_105 )
{
}
static void F_400 ( struct V_7 * V_8 , unsigned long V_105 )
{
F_98 ( V_724 , V_105 ) ;
}
static int F_401 ( struct V_7 * V_8 )
{
F_402 ( V_8 ) ;
return 1 ;
}
static int F_403 ( struct V_7 * V_8 )
{
T_2 V_302 = V_8 -> V_115 . V_399 [ V_750 ] ;
T_3 V_182 ;
if ( F_208 ( V_8 , V_302 , & V_182 ) ) {
F_404 ( V_302 ) ;
F_405 ( V_8 , 0 ) ;
return 1 ;
}
F_406 ( V_302 , V_182 ) ;
V_8 -> V_115 . V_399 [ V_751 ] = V_182 & - 1u ;
V_8 -> V_115 . V_399 [ V_647 ] = ( V_182 >> 32 ) & - 1u ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_407 ( struct V_7 * V_8 )
{
struct V_387 V_73 ;
T_2 V_302 = V_8 -> V_115 . V_399 [ V_750 ] ;
T_3 V_182 = ( V_8 -> V_115 . V_399 [ V_751 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_115 . V_399 [ V_647 ] & - 1u ) << 32 ) ;
V_73 . V_182 = V_182 ;
V_73 . V_78 = V_302 ;
V_73 . V_395 = false ;
if ( F_210 ( V_8 , & V_73 ) != 0 ) {
F_408 ( V_302 , V_182 ) ;
F_405 ( V_8 , 0 ) ;
return 1 ;
}
F_409 ( V_302 , V_182 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_410 ( struct V_7 * V_8 )
{
F_154 ( V_581 , V_8 ) ;
return 1 ;
}
static int F_411 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_93 ( V_509 ) ;
V_69 &= ~ V_329 ;
F_101 ( V_509 , V_69 ) ;
F_154 ( V_581 , V_8 ) ;
++ V_8 -> V_213 . V_752 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_703 -> V_753 &&
! F_412 ( V_8 ) ) {
V_8 -> V_703 -> V_255 = V_754 ;
return 0 ;
}
return 1 ;
}
static int F_413 ( struct V_7 * V_8 )
{
F_173 ( V_8 ) ;
return F_360 ( V_8 ) ;
}
static int F_414 ( struct V_7 * V_8 )
{
F_173 ( V_8 ) ;
F_415 ( V_8 ) ;
return 1 ;
}
static int F_416 ( struct V_7 * V_8 )
{
return F_359 ( V_8 , 0 ) == V_265 ;
}
static int F_417 ( struct V_7 * V_8 )
{
unsigned long V_732 = F_91 ( V_257 ) ;
F_418 ( V_8 , V_732 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_419 ( struct V_7 * V_8 )
{
int V_740 ;
V_740 = F_420 ( V_8 ) ;
F_386 ( V_8 , V_740 ) ;
return 1 ;
}
static int F_421 ( struct V_7 * V_8 )
{
F_173 ( V_8 ) ;
F_422 ( V_8 ) ;
return 1 ;
}
static int F_423 ( struct V_7 * V_8 )
{
T_3 V_755 = F_424 ( V_8 ) ;
T_2 V_78 = F_384 ( V_8 , V_750 ) ;
if ( F_425 ( V_8 , V_78 , V_755 ) == 0 )
F_173 ( V_8 ) ;
return 1 ;
}
static int F_426 ( struct V_7 * V_8 )
{
if ( F_299 ( V_756 ) ) {
unsigned long V_732 = F_91 ( V_257 ) ;
int V_757 , V_295 ;
V_757 = V_732 & V_758 ;
V_295 = V_732 & V_759 ;
if ( ( V_757 == V_760 ) &&
( V_295 == V_761 ) ) {
F_427 ( V_8 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
}
return F_359 ( V_8 , 0 ) == V_265 ;
}
static int F_428 ( struct V_7 * V_8 )
{
unsigned long V_732 = F_91 ( V_257 ) ;
int V_4 = V_732 & 0xff ;
F_429 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_430 ( struct V_7 * V_8 )
{
unsigned long V_732 = F_91 ( V_257 ) ;
T_2 V_295 = V_732 & 0xfff ;
F_431 ( V_8 , V_295 ) ;
return 1 ;
}
static int F_432 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_732 ;
bool V_258 = false ;
T_2 V_259 = 0 ;
T_4 V_762 ;
int V_763 , type , V_764 , V_765 ;
V_764 = ( V_72 -> V_710 & V_714 ) ;
V_765 = ( V_72 -> V_710 & V_766 ) ;
type = ( V_72 -> V_710 & V_767 ) ;
V_732 = F_91 ( V_257 ) ;
V_763 = ( T_2 ) V_732 >> 30 ;
if ( V_763 == V_768 && V_764 ) {
switch ( type ) {
case V_678 :
V_8 -> V_115 . V_769 = false ;
F_352 ( V_8 , true ) ;
break;
case V_27 :
case V_673 :
F_433 ( V_8 ) ;
break;
case V_23 :
if ( V_72 -> V_710 &
V_770 ) {
V_258 = true ;
V_259 =
F_93 ( V_771 ) ;
}
case V_268 :
F_434 ( V_8 ) ;
break;
default:
break;
}
}
V_762 = V_732 ;
if ( ! V_764 || ( type != V_23 &&
type != V_27 &&
type != V_678 ) )
F_173 ( V_8 ) ;
if ( F_435 ( V_8 , V_762 ,
type == V_673 ? V_765 : - 1 , V_763 ,
V_258 , V_259 ) == V_772 ) {
V_8 -> V_703 -> V_255 = V_716 ;
V_8 -> V_703 -> V_717 . V_718 = V_773 ;
V_8 -> V_703 -> V_717 . V_720 = 0 ;
return 0 ;
}
F_98 ( V_724 , F_91 ( V_724 ) & ~ 55 ) ;
return 1 ;
}
static int F_436 ( struct V_7 * V_8 )
{
unsigned long V_732 ;
T_1 V_84 ;
T_2 V_259 ;
int V_774 ;
V_732 = F_91 ( V_257 ) ;
V_774 = ( V_732 >> 7 ) & 0x3 ;
if ( V_774 != 0x3 && V_774 != 0x1 && V_774 != 0 ) {
F_68 ( V_88 L_21 ) ;
F_68 ( V_88 L_22 ,
( long unsigned int ) F_94 ( V_775 ) ,
F_91 ( V_776 ) ) ;
F_68 ( V_88 L_23 ,
( long unsigned int ) V_732 ) ;
V_8 -> V_703 -> V_255 = V_777 ;
V_8 -> V_703 -> V_778 . V_779 = V_780 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_710 & V_714 ) &&
F_52 () &&
( V_732 & V_781 ) )
F_104 ( V_247 , V_679 ) ;
V_84 = F_94 ( V_775 ) ;
F_368 ( V_84 , V_732 ) ;
V_259 = V_732 & ( 1U << 1 ) ;
V_259 |= ( V_732 & ( 1U << 2 ) ) << 2 ;
V_259 |= ( V_732 >> 3 ) & 0x1 ;
V_8 -> V_115 . V_732 = V_732 ;
return F_371 ( V_8 , V_84 , V_259 , NULL , 0 ) ;
}
static T_3 F_437 ( T_3 V_782 , int V_783 )
{
int V_74 ;
T_3 V_104 = 0 ;
for ( V_74 = 51 ; V_74 > V_435 . V_784 ; V_74 -- )
V_104 |= ( 1ULL << V_74 ) ;
if ( V_783 > 2 )
V_104 |= 0xf8 ;
else if ( V_783 == 2 ) {
if ( V_782 & ( 1ULL << 7 ) )
V_104 |= 0x1ff000 ;
else
V_104 |= 0x78 ;
}
return V_104 ;
}
static void F_438 ( struct V_7 * V_8 , T_3 V_782 ,
int V_783 )
{
F_68 ( V_88 L_24 , V_491 , V_782 , V_783 ) ;
F_439 ( ( V_782 & 0x7 ) == 0x2 ) ;
F_439 ( ( V_782 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_439 ( ( V_782 & 0x7 ) == 0x4 ) ;
if ( ( V_782 & 0x7 ) ) {
T_3 V_785 = V_782 & F_437 ( V_782 , V_783 ) ;
if ( V_785 != 0 ) {
F_68 ( V_88 L_25 ,
V_491 , V_785 ) ;
F_439 ( 1 ) ;
}
if ( V_783 == 1 || ( V_783 == 2 && ( V_782 & ( 1ULL << 7 ) ) ) ) {
T_3 V_786 = ( V_782 & 0x38 ) >> 3 ;
if ( V_786 == 2 || V_786 == 3 ||
V_786 == 7 ) {
F_68 ( V_88 L_26 ,
V_491 , V_786 ) ;
F_439 ( 1 ) ;
}
}
}
}
static int F_440 ( struct V_7 * V_8 )
{
T_3 V_787 [ 4 ] ;
int V_788 , V_74 , V_113 ;
T_1 V_84 ;
V_84 = F_94 ( V_775 ) ;
V_113 = F_441 ( V_8 , V_84 , true ) ;
if ( F_299 ( V_113 == V_789 ) )
return F_442 ( V_8 , V_84 , 0 , NULL , 0 ) ==
V_265 ;
if ( F_99 ( V_113 == V_790 ) )
return F_371 ( V_8 , V_84 , 0 , NULL , 0 ) ;
if ( F_99 ( V_113 == V_791 ) )
return 1 ;
F_68 ( V_88 L_27 ) ;
F_68 ( V_88 L_28 , V_84 ) ;
V_788 = F_443 ( V_8 , V_84 , V_787 ) ;
for ( V_74 = V_792 ; V_74 > V_792 - V_788 ; -- V_74 )
F_438 ( V_8 , V_787 [ V_74 - 1 ] , V_74 ) ;
V_8 -> V_703 -> V_255 = V_777 ;
V_8 -> V_703 -> V_778 . V_779 = V_793 ;
return 0 ;
}
static int F_444 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_93 ( V_509 ) ;
V_69 &= ~ V_330 ;
F_101 ( V_509 , V_69 ) ;
++ V_8 -> V_213 . V_794 ;
F_154 ( V_581 , V_8 ) ;
return 1 ;
}
static int F_445 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
enum V_708 V_740 = V_265 ;
int V_113 = 1 ;
T_2 V_795 ;
bool V_796 ;
unsigned V_797 = 130 ;
V_795 = F_93 ( V_509 ) ;
V_796 = V_795 & V_329 ;
while ( ! F_249 ( V_8 ) && V_797 -- != 0 ) {
if ( V_796 && F_354 ( V_8 ) )
return F_411 ( & V_72 -> V_8 ) ;
if ( F_168 ( V_581 , & V_8 -> V_798 ) )
return 1 ;
V_740 = F_359 ( V_8 , V_799 ) ;
if ( V_740 == V_800 ) {
++ V_8 -> V_213 . V_801 ;
V_113 = 0 ;
goto V_531;
}
if ( V_740 != V_265 ) {
V_8 -> V_703 -> V_255 = V_716 ;
V_8 -> V_703 -> V_717 . V_718 = V_773 ;
V_8 -> V_703 -> V_717 . V_720 = 0 ;
return 0 ;
}
if ( V_8 -> V_115 . V_699 ) {
V_8 -> V_115 . V_699 = 0 ;
V_113 = F_360 ( V_8 ) ;
goto V_531;
}
if ( F_446 ( V_802 ) )
goto V_531;
if ( F_447 () )
F_448 () ;
}
V_72 -> F_248 = F_248 ( V_8 ) ;
V_531:
return V_113 ;
}
static int F_449 ( struct V_7 * V_8 )
{
F_173 ( V_8 ) ;
F_450 ( V_8 ) ;
return 1 ;
}
static int F_451 ( struct V_7 * V_8 )
{
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
static struct V_89 * F_452 ( struct V_6 * V_72 )
{
struct V_803 * V_804 ;
F_79 (item, &vmx->nested.vmcs02_pool, list)
if ( V_804 -> V_805 == V_72 -> V_13 . V_806 ) {
F_453 ( & V_804 -> V_807 , & V_72 -> V_13 . V_808 ) ;
return & V_804 -> V_809 ;
}
if ( V_72 -> V_13 . V_810 >= F_454 ( V_811 , 1 ) ) {
V_804 = F_455 ( V_72 -> V_13 . V_808 . V_812 ,
struct V_803 , V_807 ) ;
V_804 -> V_805 = V_72 -> V_13 . V_806 ;
F_453 ( & V_804 -> V_807 , & V_72 -> V_13 . V_808 ) ;
return & V_804 -> V_809 ;
}
V_804 = F_456 ( sizeof( struct V_803 ) , V_440 ) ;
if ( ! V_804 )
return NULL ;
V_804 -> V_809 . V_86 = F_236 () ;
if ( ! V_804 -> V_809 . V_86 ) {
F_457 ( V_804 ) ;
return NULL ;
}
F_69 ( & V_804 -> V_809 ) ;
V_804 -> V_805 = V_72 -> V_13 . V_806 ;
F_157 ( & ( V_804 -> V_807 ) , & ( V_72 -> V_13 . V_808 ) ) ;
V_72 -> V_13 . V_810 ++ ;
return & V_804 -> V_809 ;
}
static void F_458 ( struct V_6 * V_72 , T_1 V_805 )
{
struct V_803 * V_804 ;
F_79 (item, &vmx->nested.vmcs02_pool, list)
if ( V_804 -> V_805 == V_805 ) {
F_239 ( & V_804 -> V_809 ) ;
F_82 ( & V_804 -> V_807 ) ;
F_457 ( V_804 ) ;
V_72 -> V_13 . V_810 -- ;
return;
}
}
static void F_459 ( struct V_6 * V_72 )
{
struct V_803 * V_804 , * V_411 ;
F_226 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_72 -> V_89 != & V_804 -> V_809 )
F_239 ( & V_804 -> V_809 ) ;
F_82 ( & V_804 -> V_807 ) ;
F_457 ( V_804 ) ;
}
V_72 -> V_13 . V_810 = 0 ;
if ( V_72 -> V_89 != & V_72 -> V_813 )
F_239 ( & V_72 -> V_813 ) ;
}
static void F_460 ( struct V_7 * V_8 )
{
F_170 ( V_8 , F_167 ( V_8 )
& ~ ( V_814 | V_815 | V_816 |
V_817 | V_818 | V_819 ) ) ;
}
static void F_461 ( struct V_7 * V_8 )
{
F_170 ( V_8 , ( F_167 ( V_8 )
& ~ ( V_815 | V_816 | V_817 |
V_818 | V_819 ) )
| V_814 ) ;
}
static void F_462 ( struct V_7 * V_8 ,
T_2 V_820 )
{
if ( F_6 ( V_8 ) -> V_13 . V_806 == - 1ull ) {
F_461 ( V_8 ) ;
return;
}
F_170 ( V_8 , ( F_167 ( V_8 )
& ~ ( V_814 | V_815 | V_816 |
V_818 | V_819 ) )
| V_817 ) ;
F_9 ( V_8 ) -> V_820 = V_820 ;
}
static int F_463 ( struct V_7 * V_8 )
{
struct V_456 V_537 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_86 * V_821 ;
const T_3 V_822 = V_394
| V_405 ;
if ( ! F_464 ( V_8 , V_409 ) ||
! F_162 ( V_8 , V_514 ) ||
( F_167 ( V_8 ) & V_245 ) ) {
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
F_253 ( V_8 , & V_537 , V_458 ) ;
if ( F_139 ( V_8 ) && ! V_537 . V_480 ) {
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_277 ( V_8 ) ) {
F_405 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_526 ) {
F_462 ( V_8 , V_823 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
if ( ( V_72 -> V_13 . V_385 & V_822 )
!= V_822 ) {
F_405 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_444 ) {
V_821 = F_236 () ;
if ( ! V_821 )
return - V_441 ;
V_821 -> V_433 |= ( 1u << 31 ) ;
F_66 ( V_821 ) ;
V_72 -> V_13 . V_824 = V_821 ;
}
F_222 ( & ( V_72 -> V_13 . V_808 ) ) ;
V_72 -> V_13 . V_810 = 0 ;
V_72 -> V_13 . V_526 = true ;
F_173 ( V_8 ) ;
F_460 ( V_8 ) ;
return 1 ;
}
static int F_465 ( struct V_7 * V_8 )
{
struct V_456 V_537 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( ! V_72 -> V_13 . V_526 ) {
F_361 ( V_8 , V_26 ) ;
return 0 ;
}
F_253 ( V_8 , & V_537 , V_458 ) ;
if ( ( F_167 ( V_8 ) & V_245 ) ||
( F_139 ( V_8 ) && ! V_537 . V_480 ) ) {
F_361 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_277 ( V_8 ) ) {
F_405 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_466 ( struct V_6 * V_72 )
{
T_2 V_609 ;
if ( V_444 ) {
if ( V_72 -> V_13 . V_14 != NULL ) {
F_467 ( V_72 ) ;
V_72 -> V_13 . V_825 = false ;
V_609 = F_93 ( V_621 ) ;
V_609 &= ~ V_67 ;
F_101 ( V_621 , V_609 ) ;
F_102 ( V_619 , - 1ull ) ;
}
}
F_468 ( V_72 -> V_13 . V_826 ) ;
F_13 ( V_72 -> V_13 . V_826 ) ;
}
static void F_469 ( struct V_6 * V_72 )
{
if ( ! V_72 -> V_13 . V_526 )
return;
V_72 -> V_13 . V_526 = false ;
if ( V_72 -> V_13 . V_806 != - 1ull ) {
F_466 ( V_72 ) ;
V_72 -> V_13 . V_806 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
if ( V_444 )
F_237 ( V_72 -> V_13 . V_824 ) ;
if ( V_72 -> V_13 . V_567 ) {
F_13 ( V_72 -> V_13 . V_567 ) ;
V_72 -> V_13 . V_567 = 0 ;
}
F_459 ( V_72 ) ;
}
static int F_470 ( struct V_7 * V_8 )
{
if ( ! F_465 ( V_8 ) )
return 1 ;
F_469 ( F_6 ( V_8 ) ) ;
F_173 ( V_8 ) ;
F_460 ( V_8 ) ;
return 1 ;
}
static int F_471 ( struct V_7 * V_8 ,
unsigned long V_732 ,
T_2 V_827 , T_5 * V_113 )
{
int V_828 = V_827 & 3 ;
int V_829 = ( V_827 >> 7 ) & 7 ;
bool V_830 = V_827 & ( 1u << 10 ) ;
int V_831 = ( V_827 >> 15 ) & 7 ;
int V_832 = ( V_827 >> 18 ) & 0xf ;
bool V_833 = ! ( V_827 & ( 1u << 22 ) ) ;
int V_834 = ( V_827 >> 23 ) & 0xf ;
bool V_835 = ! ( V_827 & ( 1u << 27 ) ) ;
if ( V_830 ) {
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
* V_113 = F_276 ( V_8 , V_831 ) ;
if ( V_835 )
* V_113 += F_384 ( V_8 , V_834 ) ;
if ( V_833 )
* V_113 += F_384 ( V_8 , V_832 ) << V_828 ;
* V_113 += V_732 ;
if ( V_829 == 1 )
* V_113 &= 0xffffffff ;
return 0 ;
}
static int F_472 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_805 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
struct V_836 V_837 ;
if ( ! F_465 ( V_8 ) )
return 1 ;
if ( F_471 ( V_8 , F_91 ( V_257 ) ,
F_93 ( V_838 ) , & V_80 ) )
return 1 ;
if ( F_473 ( & V_8 -> V_115 . V_839 , V_80 , & V_805 ,
sizeof( V_805 ) , & V_837 ) ) {
F_474 ( V_8 , & V_837 ) ;
return 1 ;
}
if ( ! F_475 ( V_805 , V_430 ) ) {
F_462 ( V_8 , V_840 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
if ( V_805 == V_72 -> V_13 . V_806 ) {
F_466 ( V_72 ) ;
V_72 -> V_13 . V_806 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
}
V_15 = F_10 ( V_8 , V_805 ) ;
if ( V_15 == NULL ) {
F_154 ( V_266 , V_8 ) ;
return 1 ;
}
V_12 = F_476 ( V_15 ) ;
V_12 -> V_841 = 0 ;
F_468 ( V_15 ) ;
F_13 ( V_15 ) ;
F_458 ( V_72 , V_805 ) ;
F_173 ( V_8 ) ;
F_460 ( V_8 ) ;
return 1 ;
}
static int F_477 ( struct V_7 * V_8 )
{
return F_478 ( V_8 , true ) ;
}
static int F_479 ( struct V_7 * V_8 )
{
return F_478 ( V_8 , false ) ;
}
static inline int F_480 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_842 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_481 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_482 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_113 )
{
short V_295 = F_8 ( V_9 ) ;
char * V_118 ;
if ( V_295 < 0 )
return 0 ;
V_118 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_295 ;
switch ( F_480 ( V_9 ) ) {
case V_843 :
* V_113 = * ( ( V_844 * ) V_118 ) ;
return 1 ;
case V_845 :
* V_113 = * ( ( T_4 * ) V_118 ) ;
return 1 ;
case V_842 :
* V_113 = * ( ( T_2 * ) V_118 ) ;
return 1 ;
case V_846 :
* V_113 = * ( ( T_3 * ) V_118 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_483 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_847 ) {
short V_295 = F_8 ( V_9 ) ;
char * V_118 = ( ( char * ) F_9 ( V_8 ) ) + V_295 ;
if ( V_295 < 0 )
return false ;
switch ( F_480 ( V_9 ) ) {
case V_845 :
* ( T_4 * ) V_118 = V_847 ;
return true ;
case V_842 :
* ( T_2 * ) V_118 = V_847 ;
return true ;
case V_846 :
* ( T_3 * ) V_118 = V_847 ;
return true ;
case V_843 :
* ( V_844 * ) V_118 = V_847 ;
return true ;
default:
return false ;
}
}
static void F_467 ( struct V_6 * V_72 )
{
int V_74 ;
unsigned long V_9 ;
T_3 V_847 ;
struct V_86 * V_821 = V_72 -> V_13 . V_824 ;
const unsigned long * V_232 = V_848 ;
const int V_849 = V_850 ;
F_70 ( V_821 ) ;
for ( V_74 = 0 ; V_74 < V_849 ; V_74 ++ ) {
V_9 = V_232 [ V_74 ] ;
switch ( F_480 ( V_9 ) ) {
case V_845 :
V_847 = F_92 ( V_9 ) ;
break;
case V_842 :
V_847 = F_93 ( V_9 ) ;
break;
case V_846 :
V_847 = F_94 ( V_9 ) ;
break;
case V_843 :
V_847 = F_91 ( V_9 ) ;
break;
}
F_483 ( & V_72 -> V_8 , V_9 , V_847 ) ;
}
F_66 ( V_821 ) ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
static void F_484 ( struct V_6 * V_72 )
{
const unsigned long * V_232 [] = {
V_848 ,
V_851
} ;
const int V_852 [] = {
V_850 ,
V_853
} ;
int V_74 , V_854 ;
unsigned long V_9 ;
T_3 V_847 = 0 ;
struct V_86 * V_821 = V_72 -> V_13 . V_824 ;
F_70 ( V_821 ) ;
for ( V_854 = 0 ; V_854 < F_485 ( V_232 ) ; V_854 ++ ) {
for ( V_74 = 0 ; V_74 < V_852 [ V_854 ] ; V_74 ++ ) {
V_9 = V_232 [ V_854 ] [ V_74 ] ;
F_482 ( & V_72 -> V_8 , V_9 , & V_847 ) ;
switch ( F_480 ( V_9 ) ) {
case V_845 :
F_100 ( V_9 , ( T_4 ) V_847 ) ;
break;
case V_842 :
F_101 ( V_9 , ( T_2 ) V_847 ) ;
break;
case V_846 :
F_102 ( V_9 , ( T_3 ) V_847 ) ;
break;
case V_843 :
F_98 ( V_9 , ( long ) V_847 ) ;
break;
}
}
}
F_66 ( V_821 ) ;
F_70 ( V_72 -> V_89 -> V_86 ) ;
}
static int F_486 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
if ( V_72 -> V_13 . V_806 == - 1ull ) {
F_461 ( V_8 ) ;
F_173 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_487 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_847 ;
unsigned long V_732 = F_91 ( V_257 ) ;
T_2 V_827 = F_93 ( V_838 ) ;
T_5 V_80 = 0 ;
if ( ! F_465 ( V_8 ) ||
! F_486 ( V_8 ) )
return 1 ;
V_9 = F_384 ( V_8 , ( ( ( V_827 ) >> 28 ) & 0xf ) ) ;
if ( ! F_482 ( V_8 , V_9 , & V_847 ) ) {
F_462 ( V_8 , V_855 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
if ( V_827 & ( 1u << 10 ) ) {
F_389 ( V_8 , ( ( ( V_827 ) >> 3 ) & 0xf ) ,
V_847 ) ;
} else {
if ( F_471 ( V_8 , V_732 ,
V_827 , & V_80 ) )
return 1 ;
F_488 ( & V_8 -> V_115 . V_839 , V_80 ,
& V_847 , ( F_139 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_460 ( V_8 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_489 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_80 ;
unsigned long V_732 = F_91 ( V_257 ) ;
T_2 V_827 = F_93 ( V_838 ) ;
T_3 V_847 = 0 ;
struct V_836 V_837 ;
if ( ! F_465 ( V_8 ) ||
! F_486 ( V_8 ) )
return 1 ;
if ( V_827 & ( 1u << 10 ) )
V_847 = F_384 ( V_8 ,
( ( ( V_827 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_471 ( V_8 , V_732 ,
V_827 , & V_80 ) )
return 1 ;
if ( F_473 ( & V_8 -> V_115 . V_839 , V_80 ,
& V_847 , ( F_139 ( V_8 ) ? 8 : 4 ) , & V_837 ) ) {
F_474 ( V_8 , & V_837 ) ;
return 1 ;
}
}
V_9 = F_384 ( V_8 , ( ( ( V_827 ) >> 28 ) & 0xf ) ) ;
if ( F_481 ( V_9 ) ) {
F_462 ( V_8 ,
V_856 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
if ( ! F_483 ( V_8 , V_9 , V_847 ) ) {
F_462 ( V_8 , V_855 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
F_460 ( V_8 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_490 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_5 V_80 ;
T_1 V_805 ;
struct V_836 V_837 ;
T_2 V_609 ;
if ( ! F_465 ( V_8 ) )
return 1 ;
if ( F_471 ( V_8 , F_91 ( V_257 ) ,
F_93 ( V_838 ) , & V_80 ) )
return 1 ;
if ( F_473 ( & V_8 -> V_115 . V_839 , V_80 , & V_805 ,
sizeof( V_805 ) , & V_837 ) ) {
F_474 ( V_8 , & V_837 ) ;
return 1 ;
}
if ( ! F_475 ( V_805 , V_430 ) ) {
F_462 ( V_8 , V_857 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_806 != V_805 ) {
struct V_12 * V_858 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_805 ) ;
if ( V_15 == NULL ) {
F_461 ( V_8 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
V_858 = F_476 ( V_15 ) ;
if ( V_858 -> V_433 != V_360 ) {
F_468 ( V_15 ) ;
F_15 ( V_15 ) ;
F_462 ( V_8 ,
V_859 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
if ( V_72 -> V_13 . V_806 != - 1ull )
F_466 ( V_72 ) ;
V_72 -> V_13 . V_806 = V_805 ;
V_72 -> V_13 . V_14 = V_858 ;
V_72 -> V_13 . V_826 = V_15 ;
if ( V_444 ) {
V_609 = F_93 ( V_621 ) ;
V_609 |= V_67 ;
F_101 ( V_621 , V_609 ) ;
F_102 ( V_619 ,
F_67 ( V_72 -> V_13 . V_824 ) ) ;
V_72 -> V_13 . V_825 = true ;
}
}
F_460 ( V_8 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_491 ( struct V_7 * V_8 )
{
unsigned long V_732 = F_91 ( V_257 ) ;
T_2 V_827 = F_93 ( V_838 ) ;
T_5 V_860 ;
struct V_836 V_837 ;
if ( ! F_465 ( V_8 ) )
return 1 ;
if ( F_471 ( V_8 , V_732 ,
V_827 , & V_860 ) )
return 1 ;
if ( F_488 ( & V_8 -> V_115 . V_839 , V_860 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_806 ,
sizeof( T_3 ) , & V_837 ) ) {
F_474 ( V_8 , & V_837 ) ;
return 1 ;
}
F_460 ( V_8 ) ;
F_173 ( V_8 ) ;
return 1 ;
}
static int F_492 ( struct V_7 * V_8 )
{
T_2 V_827 , V_861 ;
unsigned long type ;
T_5 V_80 ;
struct V_836 V_837 ;
struct {
T_3 V_83 , V_84 ;
} V_82 ;
T_3 V_862 = ( ( 1ull << 51 ) - 1 ) & V_519 ;
if ( ! ( V_347 & V_55 ) ||
! ( V_348 & V_349 ) ) {
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
if ( ! F_465 ( V_8 ) )
return 1 ;
if ( ! F_162 ( V_8 , V_514 ) ) {
F_361 ( V_8 , V_26 ) ;
return 1 ;
}
V_827 = F_93 ( V_838 ) ;
type = F_384 ( V_8 , ( V_827 >> 28 ) & 0xf ) ;
V_861 = ( V_348 >> V_863 ) & 6 ;
if ( ! ( V_861 & ( 1UL << type ) ) ) {
F_462 ( V_8 ,
V_864 ) ;
return 1 ;
}
if ( F_471 ( V_8 , F_91 ( V_257 ) ,
V_827 , & V_80 ) )
return 1 ;
if ( F_473 ( & V_8 -> V_115 . V_839 , V_80 , & V_82 ,
sizeof( V_82 ) , & V_837 ) ) {
F_474 ( V_8 , & V_837 ) ;
return 1 ;
}
switch ( type ) {
case V_101 :
if ( ( V_82 . V_83 & V_862 ) !=
( F_493 ( V_8 ) & V_862 ) )
break;
case V_99 :
F_494 ( V_8 ) ;
F_495 ( V_8 ) ;
F_460 ( V_8 ) ;
break;
default:
F_367 ( 1 ) ;
break;
}
F_173 ( V_8 ) ;
return 1 ;
}
static bool F_496 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_732 ;
T_1 V_865 , V_866 ;
unsigned int V_734 ;
int V_431 ;
T_6 V_867 ;
if ( ! F_57 ( V_12 , V_340 ) )
return F_57 ( V_12 , V_339 ) ;
V_732 = F_91 ( V_257 ) ;
V_734 = V_732 >> 16 ;
V_431 = ( V_732 & 7 ) + 1 ;
V_866 = ( T_1 ) - 1 ;
V_867 = - 1 ;
while ( V_431 > 0 ) {
if ( V_734 < 0x8000 )
V_865 = V_12 -> V_868 ;
else if ( V_734 < 0x10000 )
V_865 = V_12 -> V_869 ;
else
return 1 ;
V_865 += ( V_734 & 0x7fff ) / 8 ;
if ( V_866 != V_865 )
if ( F_497 ( V_8 -> V_17 , V_865 , & V_867 , 1 ) )
return 1 ;
if ( V_867 & ( 1 << ( V_734 & 7 ) ) )
return 1 ;
V_734 ++ ;
V_431 -- ;
V_866 = V_865 ;
}
return 0 ;
}
static bool F_498 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_255 )
{
T_2 V_357 = V_8 -> V_115 . V_399 [ V_750 ] ;
T_1 V_865 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_865 = V_12 -> V_273 ;
if ( V_255 == V_870 )
V_865 += 2048 ;
if ( V_357 >= 0xc0000000 ) {
V_357 -= 0xc0000000 ;
V_865 += 1024 ;
}
if ( V_357 < 1024 * 8 ) {
unsigned char V_867 ;
if ( F_497 ( V_8 -> V_17 , V_865 + V_357 / 8 , & V_867 , 1 ) )
return 1 ;
return 1 & ( V_867 >> ( V_357 & 7 ) ) ;
} else
return 1 ;
}
static bool F_499 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_732 = F_91 ( V_257 ) ;
int V_739 = V_732 & 15 ;
int V_397 = ( V_732 >> 8 ) & 15 ;
unsigned long V_105 = F_384 ( V_8 , V_397 ) ;
switch ( ( V_732 >> 4 ) & 3 ) {
case 0 :
switch ( V_739 ) {
case 0 :
if ( V_12 -> V_230 &
( V_105 ^ V_12 -> V_234 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_871 >= 1 &&
V_12 -> V_872 == V_105 ) ||
( V_12 -> V_871 >= 2 &&
V_12 -> V_873 == V_105 ) ||
( V_12 -> V_871 >= 3 &&
V_12 -> V_874 == V_105 ) ||
( V_12 -> V_871 >= 4 &&
V_12 -> V_875 == V_105 ) )
return 0 ;
if ( F_57 ( V_12 , V_334 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_236 &
( V_12 -> V_237 ^ V_105 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_336 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_12 -> V_230 & V_227 ) &&
( V_12 -> V_234 & V_227 ) )
return 1 ;
break;
case 1 :
switch ( V_739 ) {
case 3 :
if ( V_12 -> V_69 &
V_335 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_337 )
return 1 ;
break;
}
break;
case 3 :
if ( V_12 -> V_230 & 0xe &
( V_105 ^ V_12 -> V_234 ) )
return 1 ;
if ( ( V_12 -> V_230 & 0x1 ) &&
! ( V_12 -> V_234 & 0x1 ) &&
( V_105 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_500 ( struct V_7 * V_8 )
{
T_2 V_19 = F_93 ( V_256 ) ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_255 = V_72 -> V_255 ;
F_501 ( F_174 ( V_8 ) , V_255 ,
F_91 ( V_257 ) ,
V_72 -> V_710 ,
V_19 ,
F_93 ( V_713 ) ,
V_876 ) ;
if ( V_72 -> V_13 . V_681 )
return 0 ;
if ( F_99 ( V_72 -> V_877 ) ) {
F_502 ( L_29 , V_491 ,
F_93 ( V_103 ) ) ;
return 1 ;
}
switch ( V_255 ) {
case V_682 :
if ( ! F_61 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_100 ;
else if ( F_18 ( V_19 ) &&
! ( V_12 -> V_233 & V_227 ) )
return 0 ;
return V_12 -> V_138 &
( 1u << ( V_19 & V_21 ) ) ;
case V_684 :
return 0 ;
case V_878 :
return 1 ;
case V_879 :
return F_57 ( V_12 , V_329 ) ;
case V_880 :
return F_57 ( V_12 , V_330 ) ;
case V_881 :
return 1 ;
case V_882 :
return 1 ;
case V_883 :
return F_57 ( V_12 , V_331 ) ;
case V_884 :
return 1 ;
case V_885 :
return F_57 ( V_12 , V_332 ) ;
case V_886 :
return F_57 ( V_12 , V_342 ) ;
case V_887 :
return F_57 ( V_12 , V_343 ) ;
case V_888 : case V_889 :
case V_890 : case V_891 :
case V_892 : case V_893 :
case V_894 : case V_895 :
case V_896 : case V_897 :
case V_898 :
return 1 ;
case V_899 :
return F_499 ( V_8 , V_12 ) ;
case V_900 :
return F_57 ( V_12 , V_338 ) ;
case V_901 :
return F_496 ( V_8 , V_12 ) ;
case V_902 :
case V_870 :
return F_498 ( V_8 , V_12 , V_255 ) ;
case V_903 :
return 1 ;
case V_904 :
return F_57 ( V_12 , V_333 ) ;
case V_905 :
return F_57 ( V_12 , V_341 ) ;
case V_906 :
return F_57 ( V_12 , V_344 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_907 :
return 0 ;
case V_908 :
return 1 ;
case V_909 :
return F_58 ( V_12 ,
V_35 ) ;
case V_780 :
return 0 ;
case V_793 :
return 0 ;
case V_910 :
return V_12 -> V_71 &
V_310 ;
case V_911 :
return F_58 ( V_12 , V_63 ) ;
case V_912 :
return 1 ;
default:
return 1 ;
}
}
static void F_503 ( struct V_7 * V_8 , T_3 * V_913 , T_3 * V_914 )
{
* V_913 = F_91 ( V_257 ) ;
* V_914 = F_93 ( V_256 ) ;
}
static void F_504 ( struct V_7 * V_8 )
{
T_3 V_915 ;
T_2 V_916 , V_917 , V_918 ;
if ( ! ( F_9 ( V_8 ) -> V_71 &
V_310 ) )
return;
V_918 = F_505 ( V_65 ) &
V_919 ;
V_917 = F_93 ( V_920 ) ;
V_915 = F_189 ( V_8 , F_197 () )
- V_8 -> V_115 . V_921 ;
V_916 = V_915 >> V_918 ;
if ( V_917 <= V_916 )
V_917 = 0 ;
else
V_917 -= V_916 ;
F_101 ( V_920 , V_917 ) ;
}
static int F_506 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_255 = V_72 -> V_255 ;
T_2 V_922 = V_72 -> V_710 ;
if ( V_72 -> F_248 )
return F_445 ( V_8 ) ;
if ( F_122 ( V_8 ) && F_500 ( V_8 ) ) {
F_177 ( V_8 , V_255 ,
F_93 ( V_256 ) ,
F_91 ( V_257 ) ) ;
return 1 ;
}
if ( V_255 & V_923 ) {
V_8 -> V_703 -> V_255 = V_924 ;
V_8 -> V_703 -> V_925 . V_926
= V_255 ;
return 0 ;
}
if ( F_99 ( V_72 -> V_877 ) ) {
V_8 -> V_703 -> V_255 = V_924 ;
V_8 -> V_703 -> V_925 . V_926
= F_93 ( V_103 ) ;
return 0 ;
}
if ( ( V_922 & V_714 ) &&
( V_255 != V_682 &&
V_255 != V_780 &&
V_255 != V_881 ) ) {
V_8 -> V_703 -> V_255 = V_716 ;
V_8 -> V_703 -> V_717 . V_718 = V_927 ;
V_8 -> V_703 -> V_717 . V_720 = 2 ;
V_8 -> V_703 -> V_717 . V_182 [ 0 ] = V_922 ;
V_8 -> V_703 -> V_717 . V_182 [ 1 ] = V_255 ;
return 0 ;
}
if ( F_99 ( ! F_52 () && V_72 -> V_646 &&
! ( F_122 ( V_8 ) && F_59 (
F_9 ( V_8 ) ) ) ) ) {
if ( F_354 ( V_8 ) ) {
V_72 -> V_646 = 0 ;
} else if ( V_72 -> V_674 > 1000000000LL &&
V_8 -> V_115 . V_683 ) {
F_68 ( V_165 L_30
L_31 ,
V_491 , V_8 -> V_297 ) ;
V_72 -> V_646 = 0 ;
}
}
if ( V_255 < V_928
&& V_929 [ V_255 ] )
return V_929 [ V_255 ] ( V_8 ) ;
else {
V_8 -> V_703 -> V_255 = V_777 ;
V_8 -> V_703 -> V_778 . V_779 = V_255 ;
}
return 0 ;
}
static void V_448 ( struct V_7 * V_8 , int V_930 , int V_931 )
{
if ( V_931 == - 1 || V_930 < V_931 ) {
F_101 ( V_662 , 0 ) ;
return;
}
F_101 ( V_662 , V_931 ) ;
}
static void F_507 ( struct V_7 * V_8 , bool V_932 )
{
T_2 V_933 ;
if ( ! F_28 () ||
! F_317 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_933 = F_93 ( V_621 ) ;
if ( V_932 ) {
V_933 &= ~ V_35 ;
V_933 |= V_36 ;
} else {
V_933 &= ~ V_36 ;
V_933 |= V_35 ;
}
F_101 ( V_621 , V_933 ) ;
F_184 ( V_8 ) ;
}
static void F_508 ( struct V_17 * V_17 , int V_934 )
{
T_4 V_935 ;
T_6 V_407 ;
if ( ! F_317 ( V_17 ) )
return;
if ( V_934 == - 1 )
V_934 = 0 ;
V_935 = F_92 ( V_626 ) ;
V_407 = V_935 >> 8 ;
if ( V_934 != V_407 ) {
V_935 &= 0xff ;
V_935 |= V_934 << 8 ;
F_100 ( V_626 , V_935 ) ;
}
}
static void F_509 ( int V_4 )
{
T_4 V_935 ;
T_6 V_407 ;
V_935 = F_92 ( V_626 ) ;
V_407 = ( T_6 ) V_935 & 0xff ;
if ( ( T_6 ) V_4 != V_407 ) {
V_935 &= ~ 0xff ;
V_935 |= ( T_6 ) V_4 ;
F_100 ( V_626 , V_935 ) ;
}
}
static void F_510 ( struct V_7 * V_8 , int V_936 )
{
if ( V_936 == - 1 )
return;
F_509 ( V_936 ) ;
}
static void F_511 ( struct V_7 * V_8 , T_3 * V_937 )
{
if ( ! F_317 ( V_8 -> V_17 ) )
return;
F_102 ( V_622 , V_937 [ 0 ] ) ;
F_102 ( V_623 , V_937 [ 1 ] ) ;
F_102 ( V_624 , V_937 [ 2 ] ) ;
F_102 ( V_625 , V_937 [ 3 ] ) ;
}
static void F_512 ( struct V_6 * V_72 )
{
T_2 V_711 ;
if ( ! ( V_72 -> V_255 == V_907
|| V_72 -> V_255 == V_682 ) )
return;
V_72 -> V_711 = F_93 ( V_256 ) ;
V_711 = V_72 -> V_711 ;
if ( F_21 ( V_711 ) )
F_362 () ;
if ( ( V_711 & V_20 ) == V_678 &&
( V_711 & V_22 ) ) {
F_513 ( & V_72 -> V_8 ) ;
asm("int $2");
F_514 ( & V_72 -> V_8 ) ;
}
}
static void F_515 ( struct V_7 * V_8 )
{
T_2 V_711 = F_93 ( V_256 ) ;
if ( ( V_711 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_140 ;
T_16 * V_938 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
#ifdef F_95
unsigned long V_272 ;
#endif
V_4 = V_711 & V_21 ;
V_938 = ( T_16 * ) V_72 -> V_600 + V_4 ;
V_140 = F_516 ( * V_938 ) ;
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
F_158 () ;
}
static void F_517 ( struct V_6 * V_72 )
{
T_2 V_711 ;
bool V_939 ;
T_6 V_4 ;
bool V_940 ;
V_940 = V_72 -> V_710 & V_714 ;
if ( F_52 () ) {
if ( V_72 -> V_676 )
return;
V_711 = F_93 ( V_256 ) ;
V_939 = ( V_711 & V_781 ) != 0 ;
V_4 = V_711 & V_21 ;
if ( ( V_711 & V_22 ) && V_939 &&
V_4 != V_694 && ! V_940 )
F_104 ( V_247 ,
V_679 ) ;
else
V_72 -> V_676 =
! ( F_93 ( V_247 )
& V_679 ) ;
} else if ( F_99 ( V_72 -> V_646 ) )
V_72 -> V_674 +=
F_518 ( F_519 ( F_520 () , V_72 -> V_941 ) ) ;
}
static void F_521 ( struct V_7 * V_8 ,
T_2 V_710 ,
int V_942 ,
int V_943 )
{
T_6 V_4 ;
int type ;
bool V_940 ;
V_940 = V_710 & V_714 ;
V_8 -> V_115 . V_769 = false ;
F_434 ( V_8 ) ;
F_433 ( V_8 ) ;
if ( ! V_940 )
return;
F_154 ( V_581 , V_8 ) ;
V_4 = V_710 & V_766 ;
type = V_710 & V_767 ;
switch ( type ) {
case V_678 :
V_8 -> V_115 . V_769 = true ;
F_352 ( V_8 , false ) ;
break;
case V_268 :
V_8 -> V_115 . V_264 = F_93 ( V_942 ) ;
case V_23 :
if ( V_710 & V_770 ) {
T_2 V_740 = F_93 ( V_943 ) ;
F_522 ( V_8 , V_4 , V_740 ) ;
} else
F_523 ( V_8 , V_4 ) ;
break;
case V_673 :
V_8 -> V_115 . V_264 = F_93 ( V_942 ) ;
case V_27 :
F_524 ( V_8 , V_4 , type == V_673 ) ;
break;
default:
break;
}
}
static void F_525 ( struct V_6 * V_72 )
{
F_521 ( & V_72 -> V_8 , V_72 -> V_710 ,
V_254 ,
V_771 ) ;
}
static void F_526 ( struct V_7 * V_8 )
{
F_521 ( V_8 ,
F_93 ( V_269 ) ,
V_267 ,
V_261 ) ;
F_101 ( V_269 , 0 ) ;
}
static void F_527 ( struct V_6 * V_72 )
{
int V_74 , V_944 ;
struct V_945 * V_946 ;
V_946 = F_528 ( & V_944 ) ;
if ( ! V_946 )
return;
for ( V_74 = 0 ; V_74 < V_944 ; V_74 ++ )
if ( V_946 [ V_74 ] . V_153 == V_946 [ V_74 ] . V_152 )
F_124 ( V_72 , V_946 [ V_74 ] . V_73 ) ;
else
F_126 ( V_72 , V_946 [ V_74 ] . V_73 , V_946 [ V_74 ] . V_152 ,
V_946 [ V_74 ] . V_153 ) ;
}
static void T_17 F_529 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
unsigned long V_947 ;
if ( F_99 ( ! F_52 () && V_72 -> V_646 ) )
V_72 -> V_941 = F_520 () ;
if ( V_72 -> F_248 )
return;
if ( V_72 -> V_13 . V_825 ) {
F_484 ( V_72 ) ;
V_72 -> V_13 . V_825 = false ;
}
if ( F_168 ( V_398 , ( unsigned long * ) & V_8 -> V_115 . V_501 ) )
F_98 ( V_400 , V_8 -> V_115 . V_399 [ V_398 ] ) ;
if ( F_168 ( V_401 , ( unsigned long * ) & V_8 -> V_115 . V_501 ) )
F_98 ( V_402 , V_8 -> V_115 . V_399 [ V_401 ] ) ;
if ( V_8 -> V_131 & V_689 )
F_172 ( V_8 , 0 ) ;
F_527 ( V_72 ) ;
V_947 = F_530 () ;
if ( F_122 ( V_8 ) && ! V_72 -> V_13 . V_681 )
F_504 ( V_8 ) ;
V_72 -> V_948 = V_72 -> V_89 -> V_91 ;
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
if ( V_947 )
F_531 ( V_947 ) ;
#ifndef F_95
F_145 ( V_201 , V_949 ) ;
F_145 ( V_203 , V_949 ) ;
#endif
V_8 -> V_115 . V_116 = ~ ( ( 1 << V_401 ) | ( 1 << V_398 )
| ( 1 << V_241 )
| ( 1 << V_472 )
| ( 1 << V_403 )
| ( 1 << V_117 )
| ( 1 << V_496 ) ) ;
V_8 -> V_115 . V_501 = 0 ;
V_72 -> V_710 = F_93 ( V_950 ) ;
V_72 -> V_89 -> V_91 = 1 ;
V_72 -> V_255 = F_93 ( V_951 ) ;
F_532 ( V_72 -> V_255 , V_8 , V_876 ) ;
if ( V_72 -> V_13 . V_681 )
F_154 ( V_581 , V_8 ) ;
V_72 -> V_13 . V_681 = 0 ;
F_512 ( V_72 ) ;
F_517 ( V_72 ) ;
F_525 ( V_72 ) ;
}
static void F_533 ( struct V_7 * V_8 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
F_310 ( V_72 ) ;
F_239 ( V_72 -> V_89 ) ;
F_469 ( V_72 ) ;
F_457 ( V_72 -> V_77 ) ;
F_534 ( V_8 ) ;
F_535 ( V_952 , V_72 ) ;
}
static struct V_7 * F_536 ( struct V_17 * V_17 , unsigned int V_953 )
{
int V_740 ;
struct V_6 * V_72 = F_537 ( V_952 , V_440 ) ;
int V_90 ;
if ( ! V_72 )
return F_538 ( - V_441 ) ;
F_306 ( V_72 ) ;
V_740 = F_539 ( & V_72 -> V_8 , V_17 , V_953 ) ;
if ( V_740 )
goto V_954;
V_72 -> V_77 = F_456 ( V_430 , V_440 ) ;
V_740 = - V_441 ;
if ( ! V_72 -> V_77 ) {
goto V_955;
}
V_72 -> V_89 = & V_72 -> V_813 ;
V_72 -> V_89 -> V_86 = F_236 () ;
if ( ! V_72 -> V_89 -> V_86 )
goto V_956;
if ( ! V_217 )
F_153 ( F_67 ( F_81 ( V_216 , F_78 () ) ) ) ;
F_69 ( V_72 -> V_89 ) ;
if ( ! V_217 )
F_160 () ;
V_90 = F_540 () ;
F_152 ( & V_72 -> V_8 , V_90 ) ;
V_72 -> V_8 . V_90 = V_90 ;
V_740 = F_334 ( V_72 ) ;
F_159 ( & V_72 -> V_8 ) ;
F_541 () ;
if ( V_740 )
goto F_237;
if ( F_48 ( V_17 ) ) {
V_740 = F_301 ( V_17 ) ;
if ( V_740 )
goto F_237;
}
if ( V_100 ) {
if ( ! V_17 -> V_115 . V_522 )
V_17 -> V_115 . V_522 =
V_957 ;
V_740 = - V_441 ;
if ( F_305 ( V_17 ) != 0 )
goto F_237;
if ( ! F_298 ( V_17 ) )
goto F_237;
}
V_72 -> V_13 . V_806 = - 1ull ;
V_72 -> V_13 . V_14 = NULL ;
return & V_72 -> V_8 ;
F_237:
F_239 ( V_72 -> V_89 ) ;
V_956:
F_457 ( V_72 -> V_77 ) ;
V_955:
F_534 ( & V_72 -> V_8 ) ;
V_954:
F_310 ( V_72 ) ;
F_535 ( V_952 , V_72 ) ;
return F_538 ( V_740 ) ;
}
static void T_11 F_542 ( void * V_958 )
{
struct V_29 V_419 ;
* ( int * ) V_958 = 0 ;
if ( F_230 ( & V_419 ) < 0 )
* ( int * ) V_958 = - V_418 ;
if ( memcmp ( & V_29 , & V_419 , sizeof( struct V_29 ) ) != 0 ) {
F_68 ( V_88 L_32 ,
F_543 () ) ;
* ( int * ) V_958 = - V_418 ;
}
}
static int F_544 ( void )
{
return V_516 + 1 ;
}
static T_3 F_545 ( struct V_7 * V_8 , T_13 V_959 , bool V_960 )
{
T_3 V_113 ;
if ( V_960 )
V_113 = V_961 << V_962 ;
else if ( F_546 ( V_8 -> V_17 ) )
V_113 = F_547 ( V_8 , V_959 ) <<
V_962 ;
else
V_113 = ( V_963 << V_962 )
| V_964 ;
return V_113 ;
}
static int F_548 ( void )
{
if ( V_100 && ! F_38 () )
return V_965 ;
else
return V_966 ;
}
static void F_549 ( struct V_7 * V_8 )
{
struct V_300 * V_301 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_609 ;
V_72 -> V_284 = false ;
if ( F_181 () ) {
V_609 = F_93 ( V_621 ) ;
if ( V_609 & V_60 ) {
V_301 = F_199 ( V_8 , 0x80000001 , 0 ) ;
if ( V_301 && ( V_301 -> V_967 & V_68 ( V_968 ) ) )
V_72 -> V_284 = true ;
else {
V_609 &= ~ V_60 ;
F_101 ( V_621 ,
V_609 ) ;
}
}
}
V_301 = F_199 ( V_8 , 0x7 , 0 ) ;
if ( F_182 () &&
V_301 && ( V_301 -> V_969 & V_68 ( V_970 ) ) &&
F_550 ( V_8 ) ) {
V_609 = F_93 ( V_621 ) ;
V_609 |= V_61 ;
F_101 ( V_621 ,
V_609 ) ;
} else {
if ( F_26 () ) {
V_609 = F_93 ( V_621 ) ;
V_609 &= ~ V_61 ;
F_101 ( V_621 ,
V_609 ) ;
}
if ( V_301 )
V_301 -> V_969 &= ~ V_68 ( V_970 ) ;
}
}
static void F_551 ( T_2 V_971 , struct V_300 * V_140 )
{
if ( V_971 == 1 && V_13 )
V_140 -> V_302 |= V_68 ( V_303 ) ;
}
static void F_552 ( struct V_7 * V_8 ,
struct V_836 * V_972 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_255 ;
if ( V_972 -> V_259 & V_715 )
V_255 = V_793 ;
else
V_255 = V_780 ;
F_177 ( V_8 , V_255 , 0 , V_8 -> V_115 . V_732 ) ;
V_12 -> V_973 = V_972 -> V_171 ;
}
static unsigned long F_493 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_974 ;
}
static void F_553 ( struct V_7 * V_8 )
{
F_554 ( V_8 , & V_8 -> V_115 . V_492 ,
V_348 & V_43 ) ;
V_8 -> V_115 . V_492 . V_975 = F_274 ;
V_8 -> V_115 . V_492 . V_976 = F_493 ;
V_8 -> V_115 . V_492 . V_977 = F_552 ;
V_8 -> V_115 . V_500 = & V_8 -> V_115 . V_978 ;
}
static void F_555 ( struct V_7 * V_8 )
{
V_8 -> V_115 . V_500 = & V_8 -> V_115 . V_492 ;
}
static void F_556 ( struct V_7 * V_8 ,
struct V_836 * V_972 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_439 ( ! F_122 ( V_8 ) ) ;
if ( V_12 -> V_138 & ( 1u << V_24 ) )
F_177 ( V_8 , F_6 ( V_8 ) -> V_255 ,
F_93 ( V_256 ) ,
F_91 ( V_257 ) ) ;
else
F_474 ( V_8 , V_972 ) ;
}
static void F_557 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
T_2 V_609 ;
T_2 V_979 ;
F_100 ( V_980 , V_12 -> V_981 ) ;
F_100 ( V_650 , V_12 -> V_982 ) ;
F_100 ( V_983 , V_12 -> V_984 ) ;
F_100 ( V_985 , V_12 -> V_986 ) ;
F_100 ( V_987 , V_12 -> V_988 ) ;
F_100 ( V_989 , V_12 -> V_990 ) ;
F_100 ( V_653 , V_12 -> V_991 ) ;
F_100 ( V_652 , V_12 -> V_992 ) ;
F_101 ( V_993 , V_12 -> V_994 ) ;
F_101 ( V_995 , V_12 -> V_996 ) ;
F_101 ( V_997 , V_12 -> V_998 ) ;
F_101 ( V_999 , V_12 -> V_1000 ) ;
F_101 ( V_1001 , V_12 -> V_1002 ) ;
F_101 ( V_1003 , V_12 -> V_1004 ) ;
F_101 ( V_655 , V_12 -> V_1005 ) ;
F_101 ( V_485 , V_12 -> V_1006 ) ;
F_101 ( V_535 , V_12 -> V_1007 ) ;
F_101 ( V_533 , V_12 -> V_1008 ) ;
F_101 ( V_1009 , V_12 -> V_1010 ) ;
F_101 ( V_1011 , V_12 -> V_1012 ) ;
F_101 ( V_1013 , V_12 -> V_1014 ) ;
F_101 ( V_1015 , V_12 -> V_1016 ) ;
F_101 ( V_1017 , V_12 -> V_1018 ) ;
F_101 ( V_1019 , V_12 -> V_1020 ) ;
F_101 ( V_656 , V_12 -> V_1021 ) ;
F_101 ( V_487 , V_12 -> V_1022 ) ;
F_98 ( V_1023 , V_12 -> V_1024 ) ;
F_98 ( V_651 , V_12 -> V_1025 ) ;
F_98 ( V_1026 , V_12 -> V_1027 ) ;
F_98 ( V_1028 , V_12 -> V_1029 ) ;
F_98 ( V_376 , V_12 -> V_1030 ) ;
F_98 ( V_377 , V_12 -> V_1031 ) ;
F_98 ( V_654 , V_12 -> V_1032 ) ;
F_98 ( V_484 , V_12 -> V_1033 ) ;
F_98 ( V_536 , V_12 -> V_1034 ) ;
F_98 ( V_534 , V_12 -> V_1035 ) ;
F_102 ( V_660 , V_12 -> V_1036 ) ;
F_101 ( V_269 ,
V_12 -> V_1037 ) ;
F_101 ( V_261 ,
V_12 -> V_1038 ) ;
F_101 ( V_267 ,
V_12 -> V_1039 ) ;
F_101 ( V_247 ,
V_12 -> V_1040 ) ;
F_101 ( V_380 , V_12 -> V_1041 ) ;
F_397 ( V_8 , 7 , V_12 -> V_1042 ) ;
F_170 ( V_8 , V_12 -> V_1043 ) ;
F_98 ( V_659 ,
V_12 -> V_1044 ) ;
F_98 ( V_383 , V_12 -> V_1045 ) ;
F_98 ( V_382 , V_12 -> V_1046 ) ;
F_102 ( V_619 , - 1ull ) ;
F_101 ( V_620 ,
( V_29 . V_39 |
V_12 -> V_71 ) ) ;
if ( V_12 -> V_71 & V_310 )
F_101 ( V_920 ,
V_12 -> V_1047 ) ;
F_101 ( V_632 ,
V_100 ? V_12 -> V_1048 : 0 ) ;
F_101 ( V_633 ,
V_100 ? V_12 -> V_1049 : 0 ) ;
if ( F_26 () ) {
T_2 V_609 = F_331 ( V_72 ) ;
if ( ! V_72 -> V_284 )
V_609 &= ~ V_60 ;
V_609 &= ~ V_35 ;
if ( F_57 ( V_12 ,
V_33 ) )
V_609 |= V_12 -> V_70 ;
if ( V_609 & V_35 ) {
if ( V_72 -> V_13 . V_567 )
F_13 ( V_72 -> V_13 . V_567 ) ;
V_72 -> V_13 . V_567 =
F_10 ( V_8 , V_12 -> V_1050 ) ;
if ( ! V_72 -> V_13 . V_567 )
V_609 &=
~ V_35 ;
else
F_102 ( V_663 ,
F_342 ( V_72 -> V_13 . V_567 ) ) ;
} else if ( F_48 ( V_72 -> V_8 . V_17 ) ) {
V_609 |=
V_35 ;
F_102 ( V_663 ,
F_342 ( V_8 -> V_17 -> V_115 . V_567 ) ) ;
}
F_101 ( V_621 , V_609 ) ;
}
F_324 ( V_72 ) ;
V_72 -> V_1051 = 0 ;
V_609 = F_330 ( V_72 ) ;
V_609 &= ~ V_329 ;
V_609 &= ~ V_330 ;
V_609 &= ~ V_32 ;
V_609 |= V_12 -> V_69 ;
V_609 &= ~ V_31 ;
V_609 &= ~ V_340 ;
V_609 |= V_339 ;
F_101 ( V_509 , V_609 ) ;
F_121 ( V_8 ) ;
V_8 -> V_115 . V_229 &= ~ V_12 -> V_230 ;
F_98 ( V_231 , ~ V_8 -> V_115 . V_229 ) ;
V_979 = V_29 . V_434 ;
if ( V_12 -> V_71 & V_310 )
V_979 |= V_318 ;
F_110 ( V_72 , V_979 ) ;
F_105 ( V_72 ,
( V_12 -> V_1052 & ~ V_145 &
~ V_324 ) |
( V_29 . V_390 & ~ V_324 ) ) ;
if ( V_12 -> V_1052 & V_325 ) {
F_102 ( V_391 , V_12 -> V_1053 ) ;
V_8 -> V_115 . V_392 = V_12 -> V_1053 ;
} else if ( V_29 . V_390 & V_325 )
F_102 ( V_391 , V_72 -> V_8 . V_115 . V_392 ) ;
F_328 ( V_72 ) ;
if ( V_12 -> V_69 & V_296 )
F_102 ( V_288 ,
V_72 -> V_13 . V_289 + V_12 -> V_287 ) ;
else
F_102 ( V_288 , V_72 -> V_13 . V_289 ) ;
if ( V_443 ) {
F_100 ( V_664 , V_72 -> V_52 ) ;
F_262 ( V_8 ) ;
}
if ( F_60 ( V_12 ) ) {
F_558 ( V_8 ) ;
F_553 ( V_8 ) ;
}
if ( V_12 -> V_1052 & V_145 )
V_8 -> V_115 . V_176 = V_12 -> V_1054 ;
else if ( V_12 -> V_1052 & V_324 )
V_8 -> V_115 . V_176 |= ( V_179 | V_180 ) ;
else
V_8 -> V_115 . V_176 &= ~ ( V_179 | V_180 ) ;
F_258 ( V_8 , V_8 -> V_115 . V_176 ) ;
F_273 ( V_8 , V_12 -> V_233 ) ;
F_98 ( V_238 , F_163 ( V_12 ) ) ;
F_271 ( V_8 , V_12 -> V_235 ) ;
F_98 ( V_471 , F_164 ( V_12 ) ) ;
F_387 ( V_8 , V_12 -> V_520 ) ;
F_257 ( V_8 ) ;
if ( ! V_100 )
V_8 -> V_115 . V_500 -> V_977 = F_556 ;
if ( V_100 ) {
F_102 ( V_502 , V_12 -> V_1055 ) ;
F_102 ( V_504 , V_12 -> V_1056 ) ;
F_102 ( V_505 , V_12 -> V_1057 ) ;
F_102 ( V_506 , V_12 -> V_1058 ) ;
}
F_389 ( V_8 , V_398 , V_12 -> V_1059 ) ;
F_389 ( V_8 , V_401 , V_12 -> V_1060 ) ;
}
static int F_478 ( struct V_7 * V_8 , bool V_1061 )
{
struct V_12 * V_12 ;
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_89 * V_809 ;
bool V_1062 ;
if ( ! F_465 ( V_8 ) ||
! F_486 ( V_8 ) )
return 1 ;
F_173 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_444 )
F_467 ( V_72 ) ;
if ( V_12 -> V_841 == V_1061 ) {
F_462 ( V_8 ,
V_1061 ? V_1063
: V_1064 ) ;
return 1 ;
}
if ( V_12 -> V_1065 != V_658 &&
V_12 -> V_1065 != V_1066 ) {
F_462 ( V_8 , V_1067 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_475 ( V_12 -> V_273 , V_430 ) ) {
F_462 ( V_8 , V_1067 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_475 ( V_12 -> V_1050 , V_430 ) ) {
F_462 ( V_8 , V_1067 ) ;
return 1 ;
}
if ( V_12 -> V_1068 > 0 ||
V_12 -> V_1069 > 0 ||
V_12 -> V_1070 > 0 ) {
F_559 ( L_33 ,
V_491 ) ;
F_462 ( V_8 , V_1067 ) ;
return 1 ;
}
if ( ! F_203 ( V_12 -> V_69 ,
V_327 , V_328 ) ||
! F_203 ( V_12 -> V_70 ,
V_346 , V_347 ) ||
! F_203 ( V_12 -> V_71 ,
V_305 , V_306 ) ||
! F_203 ( V_12 -> V_1071 ,
V_312 , V_313 ) ||
! F_203 ( V_12 -> V_1052 ,
V_321 , V_322 ) )
{
F_462 ( V_8 , V_1067 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1072 & F_206 ) != F_206 ) ||
( ( V_12 -> V_1073 & F_207 ) != F_207 ) ) {
F_462 ( V_8 ,
V_1074 ) ;
return 1 ;
}
if ( ! F_377 ( V_12 , V_12 -> V_233 ) ||
( ( V_12 -> V_235 & F_207 ) != F_207 ) ) {
F_560 ( V_8 , V_12 ,
V_903 , V_1075 ) ;
return 1 ;
}
if ( V_12 -> V_1076 != - 1ull ) {
F_560 ( V_8 , V_12 ,
V_903 , V_1077 ) ;
return 1 ;
}
if ( V_12 -> V_1052 & V_145 ) {
V_1062 = ( V_12 -> V_1052 & V_324 ) != 0 ;
if ( ! F_561 ( V_8 , V_12 -> V_1054 ) ||
V_1062 != ! ! ( V_12 -> V_1054 & V_179 ) ||
( ( V_12 -> V_233 & V_508 ) &&
V_1062 != ! ! ( V_12 -> V_1054 & V_180 ) ) ) {
F_560 ( V_8 , V_12 ,
V_903 , V_1075 ) ;
return 1 ;
}
}
if ( V_12 -> V_1071 & V_146 ) {
V_1062 = ( V_12 -> V_1071 &
V_315 ) != 0 ;
if ( ! F_561 ( V_8 , V_12 -> V_1078 ) ||
V_1062 != ! ! ( V_12 -> V_1078 & V_179 ) ||
V_1062 != ! ! ( V_12 -> V_1078 & V_180 ) ) {
F_560 ( V_8 , V_12 ,
V_903 , V_1075 ) ;
return 1 ;
}
}
V_809 = F_452 ( V_72 ) ;
if ( ! V_809 )
return - V_441 ;
F_562 ( V_8 ) ;
V_72 -> V_13 . V_289 = F_94 ( V_288 ) ;
V_90 = F_540 () ;
V_72 -> V_89 = V_809 ;
F_159 ( V_8 ) ;
F_152 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_541 () ;
F_115 ( V_72 ) ;
V_12 -> V_841 = 1 ;
F_557 ( V_8 , V_12 ) ;
if ( V_12 -> V_1065 == V_1066 )
return F_360 ( V_8 ) ;
V_72 -> V_13 . V_681 = 1 ;
return 1 ;
}
static inline unsigned long
F_563 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_91 ( V_226 ) & V_8 -> V_115 . V_229 ) |
( V_12 -> V_233 & V_12 -> V_230 ) |
( F_91 ( V_238 ) & ~ ( V_12 -> V_230 |
V_8 -> V_115 . V_229 ) ) ;
}
static inline unsigned long
F_564 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_91 ( V_469 ) & V_8 -> V_115 . V_497 ) |
( V_12 -> V_235 & V_12 -> V_236 ) |
( F_91 ( V_471 ) & ~ ( V_12 -> V_236 |
V_8 -> V_115 . V_497 ) ) ;
}
static void F_565 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1079 ;
unsigned int V_151 ;
if ( V_8 -> V_115 . V_727 . V_1080 && V_8 -> V_115 . V_727 . V_260 ) {
V_151 = V_8 -> V_115 . V_727 . V_151 ;
V_1079 = V_151 | V_714 ;
if ( F_179 ( V_151 ) ) {
V_12 -> V_1081 =
V_8 -> V_115 . V_264 ;
V_1079 |= V_268 ;
} else
V_1079 |= V_23 ;
if ( V_8 -> V_115 . V_727 . V_258 ) {
V_1079 |= V_770 ;
V_12 -> V_1082 =
V_8 -> V_115 . V_727 . V_259 ;
}
V_12 -> V_1083 = V_1079 ;
} else if ( V_8 -> V_115 . V_769 ) {
V_12 -> V_1083 =
V_678 | V_22 | V_677 ;
} else if ( V_8 -> V_115 . V_670 . V_1080 ) {
V_151 = V_8 -> V_115 . V_670 . V_151 ;
V_1079 = V_151 | V_714 ;
if ( V_8 -> V_115 . V_670 . V_672 ) {
V_1079 |= V_673 ;
V_12 -> V_1039 =
V_8 -> V_115 . V_264 ;
} else
V_1079 |= V_27 ;
V_12 -> V_1083 = V_1079 ;
}
}
static void F_566 ( struct V_7 * V_8 , struct V_12 * V_12 ,
T_2 V_255 , T_2 V_711 ,
unsigned long V_732 )
{
V_12 -> V_233 = F_563 ( V_8 , V_12 ) ;
V_12 -> V_235 = F_564 ( V_8 , V_12 ) ;
F_396 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1042 ) ;
V_12 -> V_1059 = F_384 ( V_8 , V_398 ) ;
V_12 -> V_1060 = F_384 ( V_8 , V_401 ) ;
V_12 -> V_1043 = F_91 ( V_242 ) ;
V_12 -> V_981 = F_92 ( V_980 ) ;
V_12 -> V_982 = F_92 ( V_650 ) ;
V_12 -> V_984 = F_92 ( V_983 ) ;
V_12 -> V_986 = F_92 ( V_985 ) ;
V_12 -> V_988 = F_92 ( V_987 ) ;
V_12 -> V_990 = F_92 ( V_989 ) ;
V_12 -> V_991 = F_92 ( V_653 ) ;
V_12 -> V_992 = F_92 ( V_652 ) ;
V_12 -> V_994 = F_93 ( V_993 ) ;
V_12 -> V_996 = F_93 ( V_995 ) ;
V_12 -> V_998 = F_93 ( V_997 ) ;
V_12 -> V_1000 = F_93 ( V_999 ) ;
V_12 -> V_1002 = F_93 ( V_1001 ) ;
V_12 -> V_1004 = F_93 ( V_1003 ) ;
V_12 -> V_1005 = F_93 ( V_655 ) ;
V_12 -> V_1006 = F_93 ( V_485 ) ;
V_12 -> V_1007 = F_93 ( V_535 ) ;
V_12 -> V_1008 = F_93 ( V_533 ) ;
V_12 -> V_1010 = F_93 ( V_1009 ) ;
V_12 -> V_1012 = F_93 ( V_1011 ) ;
V_12 -> V_1014 = F_93 ( V_1013 ) ;
V_12 -> V_1016 = F_93 ( V_1015 ) ;
V_12 -> V_1018 = F_93 ( V_1017 ) ;
V_12 -> V_1020 = F_93 ( V_1019 ) ;
V_12 -> V_1021 = F_93 ( V_656 ) ;
V_12 -> V_1022 = F_93 ( V_487 ) ;
V_12 -> V_1024 = F_91 ( V_1023 ) ;
V_12 -> V_1025 = F_91 ( V_651 ) ;
V_12 -> V_1027 = F_91 ( V_1026 ) ;
V_12 -> V_1029 = F_91 ( V_1028 ) ;
V_12 -> V_1030 = F_91 ( V_376 ) ;
V_12 -> V_1031 = F_91 ( V_377 ) ;
V_12 -> V_1032 = F_91 ( V_654 ) ;
V_12 -> V_1033 = F_91 ( V_484 ) ;
V_12 -> V_1034 = F_91 ( V_536 ) ;
V_12 -> V_1035 = F_91 ( V_534 ) ;
V_12 -> V_1040 =
F_93 ( V_247 ) ;
V_12 -> V_1044 =
F_91 ( V_659 ) ;
if ( V_8 -> V_115 . V_1084 == V_1085 )
V_12 -> V_1065 = V_1066 ;
else
V_12 -> V_1065 = V_658 ;
if ( ( V_12 -> V_71 & V_310 ) &&
( V_12 -> V_1071 & V_318 ) )
V_12 -> V_1047 =
F_93 ( V_920 ) ;
if ( V_100 ) {
V_12 -> V_520 = F_94 ( V_495 ) ;
V_12 -> V_1055 = F_94 ( V_502 ) ;
V_12 -> V_1056 = F_94 ( V_504 ) ;
V_12 -> V_1057 = F_94 ( V_505 ) ;
V_12 -> V_1058 = F_94 ( V_506 ) ;
}
V_12 -> V_1052 =
( V_12 -> V_1052 & ~ V_324 ) |
( F_107 ( F_6 ( V_8 ) ) & V_324 ) ;
V_12 -> V_1036 = F_94 ( V_660 ) ;
if ( V_12 -> V_1071 & V_317 )
V_12 -> V_1053 = F_94 ( V_391 ) ;
if ( V_12 -> V_1071 & V_319 )
V_12 -> V_1054 = V_8 -> V_115 . V_176 ;
V_12 -> V_1041 = F_93 ( V_380 ) ;
V_12 -> V_1045 = F_91 ( V_383 ) ;
V_12 -> V_1046 = F_91 ( V_382 ) ;
V_12 -> V_1086 = V_255 ;
V_12 -> V_732 = V_732 ;
V_12 -> V_1087 = V_711 ;
if ( ( V_12 -> V_1087 &
( V_22 | V_262 ) ) ==
( V_22 | V_262 ) )
V_12 -> V_1088 =
F_93 ( V_713 ) ;
V_12 -> V_1083 = 0 ;
V_12 -> V_1081 = F_93 ( V_254 ) ;
V_12 -> V_827 = F_93 ( V_838 ) ;
if ( ! ( V_12 -> V_1086 & V_923 ) ) {
V_12 -> V_1037 &= ~ V_22 ;
F_565 ( V_8 , V_12 ) ;
}
V_8 -> V_115 . V_769 = false ;
F_434 ( V_8 ) ;
F_433 ( V_8 ) ;
}
static void F_567 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_456 V_112 ;
if ( V_12 -> V_1071 & V_146 )
V_8 -> V_115 . V_176 = V_12 -> V_1078 ;
else if ( V_12 -> V_1071 & V_315 )
V_8 -> V_115 . V_176 |= ( V_179 | V_180 ) ;
else
V_8 -> V_115 . V_176 &= ~ ( V_179 | V_180 ) ;
F_258 ( V_8 , V_8 -> V_115 . V_176 ) ;
F_389 ( V_8 , V_398 , V_12 -> V_1051 ) ;
F_389 ( V_8 , V_401 , V_12 -> V_1089 ) ;
F_170 ( V_8 , V_1090 ) ;
F_273 ( V_8 , V_12 -> V_1072 ) ;
F_121 ( V_8 ) ;
V_8 -> V_115 . V_229 = ( V_8 -> V_137 ? V_227 : 0 ) ;
F_98 ( V_231 , ~ V_8 -> V_115 . V_229 ) ;
V_8 -> V_115 . V_497 = ~ F_91 ( V_608 ) ;
F_381 ( V_8 , V_12 -> V_1073 ) ;
F_555 ( V_8 ) ;
F_387 ( V_8 , V_12 -> V_1091 ) ;
F_257 ( V_8 ) ;
if ( ! V_100 )
V_8 -> V_115 . V_500 -> V_977 = F_474 ;
if ( V_443 ) {
F_262 ( V_8 ) ;
}
F_101 ( V_380 , V_12 -> V_1092 ) ;
F_98 ( V_383 , V_12 -> V_1093 ) ;
F_98 ( V_382 , V_12 -> V_1094 ) ;
F_98 ( V_534 , V_12 -> V_1095 ) ;
F_98 ( V_536 , V_12 -> V_1096 ) ;
if ( V_12 -> V_1071 & V_316 ) {
F_102 ( V_391 , V_12 -> V_1097 ) ;
V_8 -> V_115 . V_392 = V_12 -> V_1097 ;
}
if ( V_12 -> V_1071 & V_150 )
F_102 ( V_162 ,
V_12 -> V_1098 ) ;
V_112 = (struct V_456 ) {
. V_122 = 0 ,
. V_124 = 0xFFFFFFFF ,
. V_119 = V_12 -> V_1099 ,
. type = 11 ,
. V_479 = 1 ,
. V_186 = 1 ,
. V_477 = 1
} ;
if ( V_12 -> V_1071 & V_315 )
V_112 . V_480 = 1 ;
else
V_112 . V_478 = 1 ;
F_251 ( V_8 , & V_112 , V_458 ) ;
V_112 = (struct V_456 ) {
. V_122 = 0 ,
. V_124 = 0xFFFFFFFF ,
. type = 3 ,
. V_479 = 1 ,
. V_186 = 1 ,
. V_478 = 1 ,
. V_477 = 1
} ;
V_112 . V_119 = V_12 -> V_1100 ;
F_251 ( V_8 , & V_112 , V_465 ) ;
V_112 . V_119 = V_12 -> V_1101 ;
F_251 ( V_8 , & V_112 , V_464 ) ;
V_112 . V_119 = V_12 -> V_1102 ;
F_251 ( V_8 , & V_112 , V_459 ) ;
V_112 . V_119 = V_12 -> V_1103 ;
V_112 . V_122 = V_12 -> V_1104 ;
F_251 ( V_8 , & V_112 , V_466 ) ;
V_112 . V_119 = V_12 -> V_1105 ;
V_112 . V_122 = V_12 -> V_1106 ;
F_251 ( V_8 , & V_112 , V_467 ) ;
V_112 = (struct V_456 ) {
. V_122 = V_12 -> V_1107 ,
. V_124 = 0x67 ,
. V_119 = V_12 -> V_1108 ,
. type = 11 ,
. V_479 = 1
} ;
F_251 ( V_8 , & V_112 , V_468 ) ;
F_397 ( V_8 , 7 , 0x400 ) ;
F_102 ( V_660 , 0 ) ;
}
static void F_177 ( struct V_7 * V_8 , T_2 V_255 ,
T_2 V_711 ,
unsigned long V_732 )
{
struct V_6 * V_72 = F_6 ( V_8 ) ;
int V_90 ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_568 ( V_72 -> V_13 . V_681 ) ;
F_569 ( V_8 ) ;
F_566 ( V_8 , V_12 , V_255 , V_711 ,
V_732 ) ;
F_570 ( V_12 -> V_1086 ,
V_12 -> V_732 ,
V_12 -> V_1083 ,
V_12 -> V_1087 ,
V_12 -> V_1088 ,
V_876 ) ;
V_90 = F_540 () ;
V_72 -> V_89 = & V_72 -> V_813 ;
F_159 ( V_8 ) ;
F_152 ( V_8 , V_90 ) ;
V_8 -> V_90 = V_90 ;
F_541 () ;
F_105 ( V_72 , F_93 ( V_106 ) ) ;
F_110 ( V_72 , F_93 ( V_108 ) ) ;
F_115 ( V_72 ) ;
if ( V_811 == 0 )
F_458 ( V_72 , V_72 -> V_13 . V_806 ) ;
F_567 ( V_8 , V_12 ) ;
F_102 ( V_288 , V_72 -> V_13 . V_289 ) ;
V_72 -> V_1051 = 0 ;
if ( V_72 -> V_13 . V_567 ) {
F_13 ( V_72 -> V_13 . V_567 ) ;
V_72 -> V_13 . V_567 = 0 ;
}
if ( F_99 ( V_72 -> V_877 ) ) {
V_72 -> V_877 = 0 ;
F_462 ( V_8 , F_93 ( V_103 ) ) ;
} else
F_460 ( V_8 ) ;
if ( V_444 )
V_72 -> V_13 . V_825 = true ;
}
static void F_213 ( struct V_7 * V_8 )
{
if ( F_122 ( V_8 ) )
F_177 ( V_8 , - 1 , 0 , 0 ) ;
F_469 ( F_6 ( V_8 ) ) ;
}
static void F_560 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_763 , unsigned long V_1109 )
{
F_567 ( V_8 , V_12 ) ;
V_12 -> V_1086 = V_763 | V_923 ;
V_12 -> V_732 = V_1109 ;
F_460 ( V_8 ) ;
if ( V_444 )
F_6 ( V_8 ) -> V_13 . V_825 = true ;
}
static int F_571 ( struct V_7 * V_8 ,
struct V_1110 * V_1111 ,
enum V_1112 V_1113 )
{
return V_1114 ;
}
static int T_11 F_572 ( void )
{
int V_548 , V_74 , V_73 ;
F_573 ( V_143 , & V_181 ) ;
for ( V_74 = 0 ; V_74 < V_641 ; ++ V_74 )
F_574 ( V_74 , V_76 [ V_74 ] ) ;
V_612 = ( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_612 )
return - V_441 ;
V_548 = - V_441 ;
V_614 = ( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_614 )
goto V_531;
V_278 = ( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_278 )
goto V_1115;
V_276 =
( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_276 )
goto V_1116;
V_277 = ( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_277 )
goto V_1117;
V_275 =
( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_275 )
goto V_1118;
V_616 = ( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_616 )
goto V_1119;
V_618 = ( unsigned long * ) F_575 ( V_440 ) ;
if ( ! V_618 )
goto V_1120;
memset ( V_616 , 0xff , V_430 ) ;
memset ( V_618 , 0xff , V_430 ) ;
for ( V_74 = 0 ; V_74 < V_850 ; V_74 ++ ) {
F_576 ( V_848 [ V_74 ] , V_618 ) ;
F_576 ( V_848 [ V_74 ] , V_616 ) ;
}
for ( V_74 = 0 ; V_74 < V_853 ; V_74 ++ )
F_576 ( V_851 [ V_74 ] , V_616 ) ;
memset ( V_612 , 0xff , V_430 ) ;
F_576 ( 0x80 , V_612 ) ;
memset ( V_614 , 0xff , V_430 ) ;
memset ( V_278 , 0xff , V_430 ) ;
memset ( V_277 , 0xff , V_430 ) ;
F_577 ( 0 , V_575 ) ;
V_548 = F_578 ( & V_1121 , sizeof( struct V_6 ) ,
F_579 ( struct V_6 ) , V_1122 ) ;
if ( V_548 )
goto V_1123;
#ifdef F_580
F_581 ( V_1124 ,
F_77 ) ;
#endif
F_313 ( V_206 , false ) ;
F_313 ( V_208 , false ) ;
F_313 ( V_209 , true ) ;
F_313 ( V_379 , false ) ;
F_313 ( V_223 , false ) ;
F_313 ( V_381 , false ) ;
memcpy ( V_276 ,
V_278 , V_430 ) ;
memcpy ( V_275 ,
V_277 , V_430 ) ;
if ( V_450 ) {
for ( V_73 = 0x800 ; V_73 <= 0x8ff ; V_73 ++ )
F_315 ( V_73 ) ;
F_314 ( 0x802 ) ;
F_314 ( 0x839 ) ;
F_316 ( 0x808 ) ;
F_316 ( 0x80b ) ;
F_316 ( 0x83f ) ;
}
if ( V_100 ) {
F_582 ( 0ull ,
( V_446 ) ? V_1125 : 0ull ,
( V_446 ) ? V_1126 : 0ull ,
0ull , V_1127 ) ;
F_332 () ;
F_583 () ;
} else
F_584 () ;
return 0 ;
V_1123:
F_585 ( ( unsigned long ) V_618 ) ;
V_1120:
F_585 ( ( unsigned long ) V_616 ) ;
V_1119:
F_585 ( ( unsigned long ) V_275 ) ;
V_1118:
F_585 ( ( unsigned long ) V_277 ) ;
V_1117:
F_585 ( ( unsigned long ) V_276 ) ;
V_1116:
F_585 ( ( unsigned long ) V_278 ) ;
V_1115:
F_585 ( ( unsigned long ) V_614 ) ;
V_531:
F_585 ( ( unsigned long ) V_612 ) ;
return V_548 ;
}
static void T_12 F_586 ( void )
{
F_585 ( ( unsigned long ) V_276 ) ;
F_585 ( ( unsigned long ) V_275 ) ;
F_585 ( ( unsigned long ) V_278 ) ;
F_585 ( ( unsigned long ) V_277 ) ;
F_585 ( ( unsigned long ) V_614 ) ;
F_585 ( ( unsigned long ) V_612 ) ;
F_585 ( ( unsigned long ) V_618 ) ;
F_585 ( ( unsigned long ) V_616 ) ;
#ifdef F_580
F_581 ( V_1124 , NULL ) ;
F_587 () ;
#endif
F_588 () ;
}
