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
F_9 ( F_10 ( V_10 ) > V_11 ) ;
if ( V_9 >= F_10 ( V_10 ) ||
V_10 [ V_9 ] == 0 )
return - V_12 ;
return V_10 [ V_9 ] ;
}
static inline struct V_13 * F_11 ( struct V_7 * V_8 )
{
return F_6 ( V_8 ) -> V_14 . V_15 ;
}
static struct V_16 * F_12 ( struct V_7 * V_8 , T_1 V_17 )
{
struct V_16 * V_16 = F_13 ( V_8 -> V_18 , V_17 >> V_19 ) ;
if ( F_14 ( V_16 ) )
return NULL ;
return V_16 ;
}
static void F_15 ( struct V_16 * V_16 )
{
F_16 ( V_16 ) ;
}
static void F_17 ( struct V_16 * V_16 )
{
F_18 ( V_16 ) ;
}
static inline bool F_19 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_22 |
V_23 ) ) ==
( V_24 | V_25 | V_23 ) ;
}
static inline bool F_20 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_22 |
V_23 ) ) ==
( V_24 | V_26 | V_23 ) ;
}
static inline bool F_21 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_22 |
V_23 ) ) ==
( V_24 | V_27 | V_23 ) ;
}
static inline bool F_22 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_23 ) )
== ( V_28 | V_23 ) ;
}
static inline bool F_23 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_22 |
V_23 ) ) ==
( V_24 | V_29 | V_23 ) ;
}
static inline bool F_24 ( void )
{
return V_30 . V_31 & V_32 ;
}
static inline bool F_25 ( void )
{
return V_30 . V_31 & V_33 ;
}
static inline bool F_26 ( struct V_18 * V_18 )
{
return ( F_25 () ) && ( F_27 ( V_18 ) ) ;
}
static inline bool F_28 ( void )
{
return V_30 . V_31 &
V_34 ;
}
static inline bool F_29 ( void )
{
return V_30 . V_35 &
V_36 ;
}
static inline bool F_30 ( void )
{
return V_30 . V_35 &
V_37 ;
}
static inline bool F_31 ( void )
{
return V_30 . V_35 &
V_38 ;
}
static inline bool F_32 ( void )
{
return V_30 . V_35 &
V_39 ;
}
static inline bool F_33 ( void )
{
return V_30 . V_40 & V_41 ;
}
static inline bool F_34 ( void )
{
return F_31 () &&
F_32 () &&
F_33 () ;
}
static inline bool F_35 ( void )
{
return F_25 () &&
F_29 () ;
}
static inline bool F_36 ( void )
{
return V_42 . V_43 & V_44 ;
}
static inline bool F_37 ( void )
{
return V_42 . V_43 & V_45 ;
}
static inline bool F_38 ( void )
{
return V_42 . V_43 & V_46 ;
}
static inline bool F_39 ( void )
{
return V_42 . V_43 & V_47 ;
}
static inline bool F_40 ( void )
{
return V_42 . V_43 & V_48 ;
}
static inline bool F_41 ( void )
{
return V_42 . V_43 & V_49 ;
}
static inline bool F_42 ( void )
{
return V_42 . V_43 & V_50 ;
}
static inline bool F_43 ( void )
{
return V_42 . V_43 & V_51 ;
}
static inline bool F_44 ( void )
{
return V_42 . V_43 & V_52 ;
}
static inline bool F_45 ( void )
{
return V_42 . V_53 & V_54 ;
}
static inline bool F_46 ( void )
{
return V_42 . V_53 & V_55 ;
}
static inline bool F_47 ( void )
{
return V_30 . V_35 &
V_56 ;
}
static inline bool F_48 ( void )
{
return V_30 . V_35 &
V_57 ;
}
static inline bool F_49 ( void )
{
return V_30 . V_35 &
V_58 ;
}
static inline bool F_50 ( struct V_18 * V_18 )
{
return V_59 && F_27 ( V_18 ) ;
}
static inline bool F_51 ( void )
{
return V_30 . V_35 &
V_60 ;
}
static inline bool F_52 ( void )
{
return V_30 . V_35 &
V_61 ;
}
static inline bool F_53 ( void )
{
return V_30 . V_35 &
V_62 ;
}
static inline bool F_54 ( void )
{
return V_30 . V_40 & V_63 ;
}
static inline bool F_55 ( void )
{
return V_30 . V_35 &
V_64 ;
}
static inline bool F_56 ( void )
{
T_3 V_65 ;
F_57 ( V_66 , V_65 ) ;
if ( ! ( V_65 & V_67 ) )
return false ;
return V_30 . V_35 &
V_68 ;
}
static inline bool F_58 ( void )
{
return V_59 ;
}
static inline bool F_59 ( struct V_13 * V_13 , T_2 V_69 )
{
return V_13 -> V_70 & V_69 ;
}
static inline bool F_60 ( struct V_13 * V_13 , T_2 V_69 )
{
return ( V_13 -> V_70 &
V_34 ) &&
( V_13 -> V_71 & V_69 ) ;
}
static inline bool F_61 ( struct V_13 * V_13 )
{
return V_13 -> V_72 & V_63 ;
}
static inline bool F_62 ( struct V_13 * V_13 )
{
return V_13 -> V_72 &
V_73 ;
}
static inline int F_63 ( struct V_13 * V_13 )
{
return F_60 ( V_13 , V_56 ) ;
}
static inline bool F_64 ( struct V_13 * V_13 )
{
return F_60 ( V_13 , V_74 ) &&
F_65 () ;
}
static inline bool F_66 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_23 ) )
== ( V_24 | V_23 ) ;
}
static int F_67 ( struct V_6 * V_75 , T_2 V_76 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_75 -> V_78 ; ++ V_77 )
if ( V_79 [ V_75 -> V_80 [ V_77 ] . V_81 ] == V_76 )
return V_77 ;
return - 1 ;
}
static inline void F_68 ( int V_82 , T_4 V_53 , T_5 V_83 )
{
struct {
T_3 V_53 : 16 ;
T_3 V_84 : 48 ;
T_3 V_83 ;
} V_85 = { V_53 , 0 , V_83 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_69 ( int V_82 , T_3 V_86 , T_1 V_87 )
{
struct {
T_3 V_86 , V_87 ;
} V_85 = { V_86 , V_87 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_88 * F_70 ( struct V_6 * V_75 , T_2 V_76 )
{
int V_77 ;
V_77 = F_67 ( V_75 , V_76 ) ;
if ( V_77 >= 0 )
return & V_75 -> V_80 [ V_77 ] ;
return NULL ;
}
static void F_71 ( struct V_89 * V_89 )
{
T_3 V_90 = F_72 ( V_89 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_73 ( V_91 L_1 ,
V_89 , V_90 ) ;
}
static inline void F_74 ( struct V_92 * V_92 )
{
F_71 ( V_92 -> V_89 ) ;
V_92 -> V_93 = - 1 ;
V_92 -> V_94 = 0 ;
}
static void F_75 ( struct V_89 * V_89 )
{
T_3 V_90 = F_72 ( V_89 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_73 ( V_91 L_2 ,
V_89 , V_90 ) ;
}
static inline void F_76 ( int V_93 )
{
F_77 ( V_93 , & V_95 ) ;
}
static inline void F_78 ( int V_93 )
{
F_79 ( V_93 , & V_95 ) ;
}
static inline int F_80 ( int V_93 )
{
return F_81 ( V_93 , & V_95 ) ;
}
static void F_82 ( void )
{
int V_93 = F_83 () ;
struct V_92 * V_96 ;
if ( ! F_80 ( V_93 ) )
return;
F_84 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_71 ( V_96 -> V_89 ) ;
}
static inline void F_76 ( int V_93 ) { }
static inline void F_78 ( int V_93 ) { }
static void F_85 ( void * V_97 )
{
struct V_92 * V_92 = V_97 ;
int V_93 = F_83 () ;
if ( V_92 -> V_93 != V_93 )
return;
if ( F_86 ( V_98 , V_93 ) == V_92 -> V_89 )
F_86 ( V_98 , V_93 ) = NULL ;
F_78 ( V_93 ) ;
F_87 ( & V_92 -> V_99 ) ;
F_88 () ;
F_74 ( V_92 ) ;
F_76 ( V_93 ) ;
}
static void F_89 ( struct V_92 * V_92 )
{
int V_93 = V_92 -> V_93 ;
if ( V_93 != - 1 )
F_90 ( V_93 ,
F_85 , V_92 , 1 ) ;
}
static inline void F_91 ( struct V_6 * V_75 )
{
if ( V_75 -> V_53 == 0 )
return;
if ( F_45 () )
F_68 ( V_100 , V_75 -> V_53 , 0 ) ;
}
static inline void F_92 ( void )
{
if ( F_46 () )
F_68 ( V_101 , 0 , 0 ) ;
}
static inline void F_93 ( struct V_6 * V_75 )
{
if ( F_45 () )
F_91 ( V_75 ) ;
else
F_92 () ;
}
static inline void F_94 ( void )
{
if ( F_44 () )
F_69 ( V_102 , 0 , 0 ) ;
}
static inline void F_95 ( T_3 V_86 )
{
if ( V_103 ) {
if ( F_43 () )
F_69 ( V_104 , V_86 , 0 ) ;
else
F_94 () ;
}
}
static T_7 unsigned long F_96 ( unsigned long V_9 )
{
unsigned long V_105 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_105 ;
}
static T_7 T_4 F_97 ( unsigned long V_9 )
{
return F_96 ( V_9 ) ;
}
static T_7 T_2 F_98 ( unsigned long V_9 )
{
return F_96 ( V_9 ) ;
}
static T_7 T_3 F_99 ( unsigned long V_9 )
{
#ifdef F_100
return F_96 ( V_9 ) ;
#else
return F_96 ( V_9 ) | ( ( T_3 ) F_96 ( V_9 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_101 ( unsigned long V_9 , unsigned long V_105 )
{
F_73 ( V_91 L_3 ,
V_9 , V_105 , F_98 ( V_106 ) ) ;
F_102 () ;
}
static void F_103 ( unsigned long V_9 , unsigned long V_105 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_104 ( error ) )
F_101 ( V_9 , V_105 ) ;
}
static void F_105 ( unsigned long V_9 , T_4 V_105 )
{
F_103 ( V_9 , V_105 ) ;
}
static void F_106 ( unsigned long V_9 , T_2 V_105 )
{
F_103 ( V_9 , V_105 ) ;
}
static void F_107 ( unsigned long V_9 , T_3 V_105 )
{
F_103 ( V_9 , V_105 ) ;
#ifndef F_100
asm volatile ("");
F_103 ( V_9 + 1 , V_105 >> 32 ) ;
#endif
}
static void F_108 ( unsigned long V_9 , T_2 V_107 )
{
F_103 ( V_9 , F_96 ( V_9 ) & ~ V_107 ) ;
}
static void F_109 ( unsigned long V_9 , T_2 V_107 )
{
F_103 ( V_9 , F_96 ( V_9 ) | V_107 ) ;
}
static inline void F_110 ( struct V_6 * V_75 , T_2 V_108 )
{
F_106 ( V_109 , V_108 ) ;
V_75 -> V_110 = V_108 ;
}
static inline void F_111 ( struct V_6 * V_75 , T_2 V_108 )
{
if ( V_75 -> V_110 != V_108 )
F_110 ( V_75 , V_108 ) ;
}
static inline T_2 F_112 ( struct V_6 * V_75 )
{
return V_75 -> V_110 ;
}
static inline void F_113 ( struct V_6 * V_75 , T_2 V_108 )
{
F_111 ( V_75 , F_112 ( V_75 ) | V_108 ) ;
}
static inline void F_114 ( struct V_6 * V_75 , T_2 V_108 )
{
F_111 ( V_75 , F_112 ( V_75 ) & ~ V_108 ) ;
}
static inline void F_115 ( struct V_6 * V_75 , T_2 V_108 )
{
F_106 ( V_111 , V_108 ) ;
V_75 -> V_112 = V_108 ;
}
static inline void F_116 ( struct V_6 * V_75 , T_2 V_108 )
{
if ( V_75 -> V_112 != V_108 )
F_115 ( V_75 , V_108 ) ;
}
static inline T_2 F_117 ( struct V_6 * V_75 )
{
return V_75 -> V_112 ;
}
static inline void F_118 ( struct V_6 * V_75 , T_2 V_108 )
{
F_116 ( V_75 , F_117 ( V_75 ) | V_108 ) ;
}
static inline void F_119 ( struct V_6 * V_75 , T_2 V_108 )
{
F_116 ( V_75 , F_117 ( V_75 ) & ~ V_108 ) ;
}
static void F_120 ( struct V_6 * V_75 )
{
V_75 -> V_113 . V_114 = 0 ;
}
static bool F_121 ( struct V_6 * V_75 , unsigned V_115 ,
unsigned V_9 )
{
bool V_116 ;
T_2 V_107 = 1 << ( V_115 * V_117 + V_9 ) ;
if ( ! ( V_75 -> V_8 . V_118 . V_119 & ( 1 << V_120 ) ) ) {
V_75 -> V_8 . V_118 . V_119 |= ( 1 << V_120 ) ;
V_75 -> V_113 . V_114 = 0 ;
}
V_116 = V_75 -> V_113 . V_114 & V_107 ;
V_75 -> V_113 . V_114 |= V_107 ;
return V_116 ;
}
static T_4 F_122 ( struct V_6 * V_75 , unsigned V_115 )
{
T_4 * V_121 = & V_75 -> V_113 . V_115 [ V_115 ] . V_122 ;
if ( ! F_121 ( V_75 , V_115 , V_123 ) )
* V_121 = F_97 ( V_124 [ V_115 ] . V_122 ) ;
return * V_121 ;
}
static T_9 F_123 ( struct V_6 * V_75 , unsigned V_115 )
{
T_9 * V_121 = & V_75 -> V_113 . V_115 [ V_115 ] . V_125 ;
if ( ! F_121 ( V_75 , V_115 , V_126 ) )
* V_121 = F_96 ( V_124 [ V_115 ] . V_125 ) ;
return * V_121 ;
}
static T_2 F_124 ( struct V_6 * V_75 , unsigned V_115 )
{
T_2 * V_121 = & V_75 -> V_113 . V_115 [ V_115 ] . V_127 ;
if ( ! F_121 ( V_75 , V_115 , V_128 ) )
* V_121 = F_98 ( V_124 [ V_115 ] . V_127 ) ;
return * V_121 ;
}
static T_2 F_125 ( struct V_6 * V_75 , unsigned V_115 )
{
T_2 * V_121 = & V_75 -> V_113 . V_115 [ V_115 ] . V_129 ;
if ( ! F_121 ( V_75 , V_115 , V_130 ) )
* V_121 = F_98 ( V_124 [ V_115 ] . V_131 ) ;
return * V_121 ;
}
static void F_126 ( struct V_7 * V_8 )
{
T_2 V_132 ;
V_132 = ( 1u << V_25 ) | ( 1u << V_27 ) | ( 1u << V_29 ) |
( 1u << V_26 ) | ( 1u << V_133 ) ;
if ( ( V_8 -> V_134 &
( V_135 | V_136 ) ) ==
( V_135 | V_136 ) )
V_132 |= 1u << V_137 ;
if ( F_6 ( V_8 ) -> V_138 . V_139 )
V_132 = ~ 0 ;
if ( V_103 )
V_132 &= ~ ( 1u << V_25 ) ;
if ( V_8 -> V_140 )
V_132 &= ~ ( 1u << V_26 ) ;
if ( F_127 ( V_8 ) )
V_132 |= F_11 ( V_8 ) -> V_141 ;
F_106 ( V_142 , V_132 ) ;
}
static void F_128 ( struct V_6 * V_75 ,
unsigned long V_143 , unsigned long exit )
{
F_114 ( V_75 , V_143 ) ;
F_119 ( V_75 , exit ) ;
}
static void F_129 ( struct V_6 * V_75 , unsigned V_76 )
{
unsigned V_77 ;
struct V_144 * V_145 = & V_75 -> V_144 ;
switch ( V_76 ) {
case V_146 :
if ( V_147 ) {
F_128 ( V_75 ,
V_148 ,
V_149 ) ;
return;
}
break;
case V_150 :
if ( V_151 ) {
F_128 ( V_75 ,
V_152 ,
V_153 ) ;
return;
}
break;
}
for ( V_77 = 0 ; V_77 < V_145 -> V_154 ; ++ V_77 )
if ( V_145 -> V_155 [ V_77 ] . V_81 == V_76 )
break;
if ( V_77 == V_145 -> V_154 )
return;
-- V_145 -> V_154 ;
V_145 -> V_155 [ V_77 ] = V_145 -> V_155 [ V_145 -> V_154 ] ;
V_145 -> V_156 [ V_77 ] = V_145 -> V_156 [ V_145 -> V_154 ] ;
F_106 ( V_157 , V_145 -> V_154 ) ;
F_106 ( V_158 , V_145 -> V_154 ) ;
}
static void F_130 ( struct V_6 * V_75 ,
unsigned long V_143 , unsigned long exit ,
unsigned long V_159 , unsigned long V_160 ,
T_3 V_161 , T_3 V_162 )
{
F_107 ( V_159 , V_161 ) ;
F_107 ( V_160 , V_162 ) ;
F_113 ( V_75 , V_143 ) ;
F_118 ( V_75 , exit ) ;
}
static void F_131 ( struct V_6 * V_75 , unsigned V_76 ,
T_3 V_161 , T_3 V_162 )
{
unsigned V_77 ;
struct V_144 * V_145 = & V_75 -> V_144 ;
switch ( V_76 ) {
case V_146 :
if ( V_147 ) {
F_130 ( V_75 ,
V_148 ,
V_149 ,
V_163 ,
V_164 ,
V_161 , V_162 ) ;
return;
}
break;
case V_150 :
if ( V_151 ) {
F_130 ( V_75 ,
V_152 ,
V_153 ,
V_165 ,
V_166 ,
V_161 , V_162 ) ;
return;
}
break;
}
for ( V_77 = 0 ; V_77 < V_145 -> V_154 ; ++ V_77 )
if ( V_145 -> V_155 [ V_77 ] . V_81 == V_76 )
break;
if ( V_77 == V_167 ) {
F_132 ( V_168 L_4
L_5 , V_76 ) ;
return;
} else if ( V_77 == V_145 -> V_154 ) {
++ V_145 -> V_154 ;
F_106 ( V_157 , V_145 -> V_154 ) ;
F_106 ( V_158 , V_145 -> V_154 ) ;
}
V_145 -> V_155 [ V_77 ] . V_81 = V_76 ;
V_145 -> V_155 [ V_77 ] . V_105 = V_161 ;
V_145 -> V_156 [ V_77 ] . V_81 = V_76 ;
V_145 -> V_156 [ V_77 ] . V_105 = V_162 ;
}
static void F_133 ( void )
{
struct V_169 * V_170 = F_134 ( & V_171 ) ;
struct V_172 * V_173 ;
V_173 = ( void * ) V_170 -> V_174 ;
V_173 [ V_175 ] . type = 9 ;
F_135 () ;
}
static bool F_136 ( struct V_6 * V_75 , int V_176 )
{
T_3 V_177 ;
T_3 V_178 ;
V_177 = V_75 -> V_8 . V_118 . V_179 ;
V_178 = V_180 | V_181 ;
#ifdef F_100
V_178 |= V_182 | V_183 ;
if ( V_177 & V_182 )
V_178 &= ~ ( T_3 ) V_181 ;
#endif
V_177 &= ~ V_178 ;
V_177 |= V_184 & V_178 ;
V_75 -> V_80 [ V_176 ] . V_185 = V_177 ;
V_75 -> V_80 [ V_176 ] . V_107 = ~ V_178 ;
F_129 ( V_75 , V_146 ) ;
if ( V_147 ||
( V_103 && ( ( V_75 -> V_8 . V_118 . V_179 ^ V_184 ) & V_180 ) ) ) {
V_177 = V_75 -> V_8 . V_118 . V_179 ;
if ( ! ( V_177 & V_182 ) )
V_177 &= ~ V_183 ;
if ( V_177 != V_184 )
F_131 ( V_75 , V_146 ,
V_177 , V_184 ) ;
return false ;
}
return true ;
}
static unsigned long F_137 ( T_4 V_122 )
{
struct V_169 * V_170 = F_134 ( & V_171 ) ;
struct V_172 * V_186 ;
unsigned long V_187 ;
unsigned long V_96 ;
if ( ! ( V_122 & ~ 3 ) )
return 0 ;
V_187 = V_170 -> V_174 ;
if ( V_122 & 4 ) {
T_4 V_188 = F_138 () ;
if ( ! ( V_188 & ~ 3 ) )
return 0 ;
V_187 = F_137 ( V_188 ) ;
}
V_186 = (struct V_172 * ) ( V_187 + ( V_122 & ~ 7 ) ) ;
V_96 = F_139 ( V_186 ) ;
#ifdef F_100
if ( V_186 -> V_189 == 0 && ( V_186 -> type == 2 || V_186 -> type == 9 || V_186 -> type == 11 ) )
V_96 |= ( ( unsigned long ) ( (struct V_190 * ) V_186 ) -> V_191 ) << 32 ;
#endif
return V_96 ;
}
static inline unsigned long F_140 ( void )
{
T_4 V_192 ;
asm("str %0" : "=g"(tr));
return F_137 ( V_192 ) ;
}
static void F_141 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_77 ;
if ( V_75 -> V_193 . V_194 )
return;
V_75 -> V_193 . V_194 = 1 ;
V_75 -> V_193 . V_195 = F_138 () ;
V_75 -> V_193 . V_196 = V_75 -> V_193 . V_195 ;
F_142 ( V_197 , V_75 -> V_193 . V_198 ) ;
if ( ! ( V_75 -> V_193 . V_198 & 7 ) ) {
F_105 ( V_199 , V_75 -> V_193 . V_198 ) ;
V_75 -> V_193 . V_200 = 0 ;
} else {
F_105 ( V_199 , 0 ) ;
V_75 -> V_193 . V_200 = 1 ;
}
F_142 ( V_201 , V_75 -> V_193 . V_202 ) ;
if ( ! ( V_75 -> V_193 . V_202 & 7 ) )
F_105 ( V_203 , V_75 -> V_193 . V_202 ) ;
else {
F_105 ( V_203 , 0 ) ;
V_75 -> V_193 . V_196 = 1 ;
}
#ifdef F_100
F_142 ( V_204 , V_75 -> V_193 . V_205 ) ;
F_142 ( V_206 , V_75 -> V_193 . V_207 ) ;
#endif
#ifdef F_100
F_103 ( V_208 , F_143 ( V_209 ) ) ;
F_103 ( V_210 , F_143 ( V_211 ) ) ;
#else
F_103 ( V_208 , F_137 ( V_75 -> V_193 . V_198 ) ) ;
F_103 ( V_210 , F_137 ( V_75 -> V_193 . V_202 ) ) ;
#endif
#ifdef F_100
F_57 ( V_212 , V_75 -> V_213 ) ;
if ( F_144 ( & V_75 -> V_8 ) )
F_145 ( V_212 , V_75 -> V_214 ) ;
#endif
if ( F_146 ( V_215 ) )
F_57 ( V_216 , V_75 -> V_193 . V_217 ) ;
for ( V_77 = 0 ; V_77 < V_75 -> V_218 ; ++ V_77 )
F_147 ( V_75 -> V_80 [ V_77 ] . V_81 ,
V_75 -> V_80 [ V_77 ] . V_185 ,
V_75 -> V_80 [ V_77 ] . V_107 ) ;
}
static void F_148 ( struct V_6 * V_75 )
{
if ( ! V_75 -> V_193 . V_194 )
return;
++ V_75 -> V_8 . V_219 . V_220 ;
V_75 -> V_193 . V_194 = 0 ;
#ifdef F_100
if ( F_144 ( & V_75 -> V_8 ) )
F_57 ( V_212 , V_75 -> V_214 ) ;
#endif
if ( V_75 -> V_193 . V_196 ) {
F_149 ( V_75 -> V_193 . V_195 ) ;
#ifdef F_100
F_150 ( V_75 -> V_193 . V_202 ) ;
#else
F_151 ( V_201 , V_75 -> V_193 . V_202 ) ;
#endif
}
if ( V_75 -> V_193 . V_200 )
F_151 ( V_197 , V_75 -> V_193 . V_198 ) ;
#ifdef F_100
if ( F_104 ( V_75 -> V_193 . V_205 | V_75 -> V_193 . V_207 ) ) {
F_151 ( V_204 , V_75 -> V_193 . V_205 ) ;
F_151 ( V_206 , V_75 -> V_193 . V_207 ) ;
}
#endif
F_133 () ;
#ifdef F_100
F_145 ( V_212 , V_75 -> V_213 ) ;
#endif
if ( V_75 -> V_193 . V_217 )
F_145 ( V_216 , V_75 -> V_193 . V_217 ) ;
if ( ! F_152 () && ! V_75 -> V_8 . V_221 )
F_153 () ;
F_154 ( F_134 ( & V_171 ) ) ;
}
static void F_155 ( struct V_6 * V_75 )
{
F_156 () ;
F_148 ( V_75 ) ;
F_157 () ;
}
static void F_158 ( struct V_7 * V_8 , int V_93 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_3 V_90 = F_72 ( F_86 ( V_222 , V_93 ) ) ;
if ( ! V_223 )
F_159 ( V_90 ) ;
else if ( V_75 -> V_92 -> V_93 != V_93 )
F_89 ( V_75 -> V_92 ) ;
if ( F_86 ( V_98 , V_93 ) != V_75 -> V_92 -> V_89 ) {
F_86 ( V_98 , V_93 ) = V_75 -> V_92 -> V_89 ;
F_75 ( V_75 -> V_92 -> V_89 ) ;
}
if ( V_75 -> V_92 -> V_93 != V_93 ) {
struct V_169 * V_170 = F_134 ( & V_171 ) ;
unsigned long V_224 ;
F_160 ( V_225 , V_8 ) ;
F_161 () ;
F_78 ( V_93 ) ;
F_162 () ;
F_163 ( & V_75 -> V_92 -> V_99 ,
& F_86 ( V_226 , V_93 ) ) ;
F_76 ( V_93 ) ;
F_164 () ;
F_103 ( V_227 , F_140 () ) ;
F_103 ( V_228 , V_170 -> V_174 ) ;
F_57 ( V_229 , V_224 ) ;
F_103 ( V_230 , V_224 ) ;
V_75 -> V_92 -> V_93 = V_93 ;
}
}
static void F_165 ( struct V_7 * V_8 )
{
F_148 ( F_6 ( V_8 ) ) ;
if ( ! V_223 ) {
F_85 ( F_6 ( V_8 ) -> V_92 ) ;
V_8 -> V_93 = - 1 ;
F_166 () ;
}
}
static void F_167 ( struct V_7 * V_8 )
{
T_9 V_231 ;
if ( V_8 -> V_140 )
return;
V_8 -> V_140 = 1 ;
V_231 = F_96 ( V_232 ) ;
V_231 &= ~ ( V_233 | V_234 ) ;
V_231 |= F_168 ( V_8 , V_233 | V_234 ) ;
F_103 ( V_232 , V_231 ) ;
F_126 ( V_8 ) ;
V_8 -> V_118 . V_235 = V_233 ;
if ( F_127 ( V_8 ) )
V_8 -> V_118 . V_235 &=
~ F_11 ( V_8 ) -> V_236 ;
F_103 ( V_237 , ~ V_8 -> V_118 . V_235 ) ;
}
static inline unsigned long F_169 ( struct V_13 * V_238 )
{
return ( V_238 -> V_239 & ~ V_238 -> V_236 ) |
( V_238 -> V_240 & V_238 -> V_236 ) ;
}
static inline unsigned long F_170 ( struct V_13 * V_238 )
{
return ( V_238 -> V_241 & ~ V_238 -> V_242 ) |
( V_238 -> V_243 & V_238 -> V_242 ) ;
}
static void F_171 ( struct V_7 * V_8 )
{
F_172 ( V_8 ) ;
F_109 ( V_232 , V_233 | V_234 ) ;
F_126 ( V_8 ) ;
V_8 -> V_118 . V_235 = 0 ;
F_103 ( V_237 , ~ V_8 -> V_118 . V_235 ) ;
if ( F_127 ( V_8 ) ) {
struct V_13 * V_13 = F_11 ( V_8 ) ;
V_13 -> V_239 = ( V_13 -> V_239 & ~ V_233 ) |
( V_8 -> V_118 . V_231 & V_233 ) ;
F_103 ( V_244 , F_169 ( V_13 ) ) ;
} else
F_103 ( V_244 , V_8 -> V_118 . V_231 ) ;
}
static unsigned long F_173 ( struct V_7 * V_8 )
{
unsigned long V_245 , V_246 ;
if ( ! F_174 ( V_247 , ( T_9 * ) & V_8 -> V_118 . V_119 ) ) {
F_175 ( V_247 , ( T_9 * ) & V_8 -> V_118 . V_119 ) ;
V_245 = F_96 ( V_248 ) ;
if ( F_6 ( V_8 ) -> V_138 . V_139 ) {
V_245 &= V_249 ;
V_246 = F_6 ( V_8 ) -> V_138 . V_246 ;
V_245 |= V_246 & ~ V_249 ;
}
F_6 ( V_8 ) -> V_245 = V_245 ;
}
return F_6 ( V_8 ) -> V_245 ;
}
static void F_176 ( struct V_7 * V_8 , unsigned long V_245 )
{
F_175 ( V_247 , ( T_9 * ) & V_8 -> V_118 . V_119 ) ;
F_6 ( V_8 ) -> V_245 = V_245 ;
if ( F_6 ( V_8 ) -> V_138 . V_139 ) {
F_6 ( V_8 ) -> V_138 . V_246 = V_245 ;
V_245 |= V_250 | V_251 ;
}
F_103 ( V_248 , V_245 ) ;
}
static T_2 F_177 ( struct V_7 * V_8 )
{
T_2 V_252 = F_98 ( V_253 ) ;
int V_116 = 0 ;
if ( V_252 & V_254 )
V_116 |= V_255 ;
if ( V_252 & V_256 )
V_116 |= V_257 ;
return V_116 ;
}
static void F_178 ( struct V_7 * V_8 , int V_107 )
{
T_2 V_258 = F_98 ( V_253 ) ;
T_2 V_252 = V_258 ;
V_252 &= ~ ( V_254 | V_256 ) ;
if ( V_107 & V_257 )
V_252 |= V_256 ;
else if ( V_107 & V_255 )
V_252 |= V_254 ;
if ( ( V_252 != V_258 ) )
F_106 ( V_253 , V_252 ) ;
}
static void F_179 ( struct V_7 * V_8 )
{
unsigned long V_259 ;
V_259 = F_180 ( V_8 ) ;
V_259 += F_98 ( V_260 ) ;
F_181 ( V_8 , V_259 ) ;
F_178 ( V_8 , 0 ) ;
}
static int F_182 ( struct V_7 * V_8 , unsigned V_154 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
if ( ! ( V_13 -> V_141 & ( 1u << V_154 ) ) )
return 0 ;
F_183 ( V_8 , F_6 ( V_8 ) -> V_261 ,
F_98 ( V_262 ) ,
F_96 ( V_263 ) ) ;
return 1 ;
}
static void F_184 ( struct V_7 * V_8 , unsigned V_154 ,
bool V_264 , T_2 V_265 ,
bool V_266 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_2 V_20 = V_154 | V_23 ;
if ( ! V_266 && F_127 ( V_8 ) &&
F_182 ( V_8 , V_154 ) )
return;
if ( V_264 ) {
F_106 ( V_267 , V_265 ) ;
V_20 |= V_268 ;
}
if ( V_75 -> V_138 . V_139 ) {
int V_269 = 0 ;
if ( F_185 ( V_154 ) )
V_269 = V_8 -> V_118 . V_270 ;
if ( F_186 ( V_8 , V_154 , V_269 ) != V_271 )
F_160 ( V_272 , V_8 ) ;
return;
}
if ( F_185 ( V_154 ) ) {
F_106 ( V_273 ,
V_75 -> V_8 . V_118 . V_270 ) ;
V_20 |= V_274 ;
} else
V_20 |= V_24 ;
F_106 ( V_275 , V_20 ) ;
}
static bool F_187 ( void )
{
return F_52 () ;
}
static bool F_188 ( void )
{
return F_53 () && V_103 ;
}
static void F_189 ( struct V_6 * V_75 , int V_276 , int V_277 )
{
struct V_88 V_278 ;
V_278 = V_75 -> V_80 [ V_277 ] ;
V_75 -> V_80 [ V_277 ] = V_75 -> V_80 [ V_276 ] ;
V_75 -> V_80 [ V_276 ] = V_278 ;
}
static void F_190 ( struct V_7 * V_8 )
{
unsigned long * V_279 ;
if ( F_27 ( V_8 -> V_18 ) && F_191 ( V_8 -> V_118 . V_280 ) ) {
if ( F_144 ( V_8 ) )
V_279 = V_281 ;
else
V_279 = V_282 ;
} else {
if ( F_144 ( V_8 ) )
V_279 = V_283 ;
else
V_279 = V_284 ;
}
F_107 ( V_285 , F_72 ( V_279 ) ) ;
}
static void F_192 ( struct V_6 * V_75 )
{
int V_218 , V_81 ;
V_218 = 0 ;
#ifdef F_100
if ( F_144 ( & V_75 -> V_8 ) ) {
V_81 = F_67 ( V_75 , V_286 ) ;
if ( V_81 >= 0 )
F_189 ( V_75 , V_81 , V_218 ++ ) ;
V_81 = F_67 ( V_75 , V_287 ) ;
if ( V_81 >= 0 )
F_189 ( V_75 , V_81 , V_218 ++ ) ;
V_81 = F_67 ( V_75 , V_288 ) ;
if ( V_81 >= 0 )
F_189 ( V_75 , V_81 , V_218 ++ ) ;
V_81 = F_67 ( V_75 , V_289 ) ;
if ( V_81 >= 0 && V_75 -> V_290 )
F_189 ( V_75 , V_81 , V_218 ++ ) ;
V_81 = F_67 ( V_75 , V_291 ) ;
if ( ( V_81 >= 0 ) && ( V_75 -> V_8 . V_118 . V_179 & V_181 ) )
F_189 ( V_75 , V_81 , V_218 ++ ) ;
}
#endif
V_81 = F_67 ( V_75 , V_146 ) ;
if ( V_81 >= 0 && F_136 ( V_75 , V_81 ) )
F_189 ( V_75 , V_81 , V_218 ++ ) ;
V_75 -> V_218 = V_218 ;
if ( F_24 () )
F_190 ( & V_75 -> V_8 ) ;
}
static T_3 F_193 ( void )
{
T_3 V_292 , V_293 ;
F_194 ( V_292 ) ;
V_293 = F_99 ( V_294 ) ;
return V_292 + V_293 ;
}
static T_3 F_195 ( struct V_7 * V_8 , T_3 V_292 )
{
T_3 V_293 ;
V_293 = F_127 ( V_8 ) ?
F_6 ( V_8 ) -> V_14 . V_295 :
F_99 ( V_294 ) ;
return V_292 + V_293 ;
}
static void F_196 ( struct V_7 * V_8 , T_2 V_296 , bool V_297 )
{
if ( ! V_297 )
return;
if ( V_296 > V_298 ) {
V_8 -> V_118 . V_299 = 1 ;
V_8 -> V_118 . V_300 = 1 ;
} else
F_197 ( 1 , L_6 ) ;
}
static T_3 F_198 ( struct V_7 * V_8 )
{
return F_99 ( V_294 ) ;
}
static void F_199 ( struct V_7 * V_8 , T_3 V_301 )
{
if ( F_127 ( V_8 ) ) {
struct V_13 * V_13 ;
F_6 ( V_8 ) -> V_14 . V_295 = V_301 ;
V_13 = F_11 ( V_8 ) ;
F_107 ( V_294 , V_301 +
( F_59 ( V_13 , V_302 ) ?
V_13 -> V_293 : 0 ) ) ;
} else {
F_200 ( V_8 -> V_303 ,
F_99 ( V_294 ) , V_301 ) ;
F_107 ( V_294 , V_301 ) ;
}
}
static void F_201 ( struct V_7 * V_8 , T_10 V_304 , bool V_156 )
{
T_3 V_301 = F_99 ( V_294 ) ;
F_107 ( V_294 , V_301 + V_304 ) ;
if ( F_127 ( V_8 ) ) {
F_6 ( V_8 ) -> V_14 . V_295 += V_304 ;
} else
F_200 ( V_8 -> V_303 , V_301 ,
V_301 + V_304 ) ;
}
static T_3 F_202 ( struct V_7 * V_8 , T_3 V_305 )
{
return V_305 - F_203 () ;
}
static bool F_204 ( struct V_7 * V_8 )
{
struct V_306 * V_307 = F_205 ( V_8 , 1 , 0 ) ;
return V_307 && ( V_307 -> V_308 & ( 1 << ( V_309 & 31 ) ) ) ;
}
static inline bool F_206 ( struct V_7 * V_8 )
{
return V_14 && F_204 ( V_8 ) ;
}
static T_11 void F_207 ( void )
{
F_208 ( V_310 ,
V_311 , V_312 ) ;
V_311 |= V_313 ;
V_312 &= V_314 |
V_315 | V_63 ;
V_312 |= V_313 |
V_73 ;
F_208 ( V_316 ,
V_317 , V_318 ) ;
V_317 = V_319 ;
V_318 &=
#ifdef F_100
V_320 |
#endif
V_321 | V_322 ;
V_318 |= V_319 |
V_149 | V_323 |
V_324 | V_325 ;
if ( F_209 () )
V_318 |= V_326 ;
V_327 = V_317 &
~ V_328 ;
F_208 ( V_329 ,
V_330 , V_331 ) ;
V_330 = V_332 ;
V_331 &=
#ifdef F_100
V_333 |
#endif
V_334 ;
V_331 |= ( V_332 |
V_148 ) ;
if ( F_209 () )
V_331 |= V_335 ;
V_336 = V_330 &
~ V_337 ;
F_208 ( V_338 ,
V_339 , V_340 ) ;
V_339 = V_341 ;
V_340 &=
V_342 |
V_343 | V_302 |
V_344 | V_345 |
V_346 | V_347 |
V_348 |
#ifdef F_100
V_349 | V_350 |
#endif
V_351 | V_352 |
V_353 | V_354 |
V_355 | V_356 |
V_357 | V_33 |
V_34 ;
V_340 |= V_341 |
V_32 ;
V_358 = V_339 &
~ ( V_347 | V_348 ) ;
F_208 ( V_359 ,
V_360 , V_361 ) ;
V_360 = 0 ;
V_361 &=
V_36 |
V_64 |
V_74 ;
if ( V_103 ) {
V_361 |= V_56 |
V_57 ;
V_362 = V_49 |
V_46 | V_47 |
V_363 ;
V_362 &= V_42 . V_43 ;
V_362 |= V_52 ;
} else
V_362 = 0 ;
F_208 ( V_66 , V_364 , V_365 ) ;
V_364 &= V_366 ;
V_364 |= V_367 |
V_368 ;
V_365 = 0 ;
}
static inline bool F_210 ( T_2 V_3 , T_2 V_369 , T_2 V_370 )
{
return ( ( V_3 & V_370 ) | V_369 ) == V_3 ;
}
static inline T_3 F_211 ( T_2 V_369 , T_2 V_370 )
{
return V_369 | ( ( T_3 ) V_370 << 32 ) ;
}
static int F_212 ( struct V_7 * V_8 , T_2 V_371 , T_3 * V_372 )
{
switch ( V_371 ) {
case V_373 :
* V_372 = V_374 | V_375 |
( ( T_3 ) V_376 << V_377 ) |
( V_378 << V_379 ) ;
break;
case V_380 :
case V_310 :
* V_372 = F_211 ( V_311 ,
V_312 ) ;
break;
case V_381 :
* V_372 = F_211 ( V_358 ,
V_340 ) ;
break;
case V_338 :
* V_372 = F_211 ( V_339 ,
V_340 ) ;
break;
case V_382 :
* V_372 = F_211 ( V_327 ,
V_318 ) ;
break;
case V_316 :
* V_372 = F_211 ( V_317 ,
V_318 ) ;
break;
case V_383 :
* V_372 = F_211 ( V_336 ,
V_331 ) ;
break;
case V_329 :
* V_372 = F_211 ( V_330 ,
V_331 ) ;
break;
case V_66 :
* V_372 = F_211 ( V_364 ,
V_365 ) ;
break;
#define F_213 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_214 X86_CR4_VMXE
case V_384 :
* V_372 = F_213 ;
break;
case V_385 :
* V_372 = - 1ULL ;
break;
case V_386 :
* V_372 = F_214 ;
break;
case V_387 :
* V_372 = - 1ULL ;
break;
case V_388 :
* V_372 = 0x2e ;
break;
case V_359 :
* V_372 = F_211 ( V_360 ,
V_361 ) ;
break;
case V_389 :
* V_372 = V_362 ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_215 ( struct V_7 * V_8 , T_2 V_371 , T_3 * V_372 )
{
T_3 V_185 ;
struct V_88 * V_76 ;
if ( ! V_372 ) {
F_73 ( V_91 L_7 ) ;
return - V_390 ;
}
switch ( V_371 ) {
#ifdef F_100
case V_209 :
V_185 = F_96 ( V_391 ) ;
break;
case V_211 :
V_185 = F_96 ( V_392 ) ;
break;
case V_212 :
F_155 ( F_6 ( V_8 ) ) ;
V_185 = F_6 ( V_8 ) -> V_214 ;
break;
#endif
case V_146 :
return F_216 ( V_8 , V_371 , V_372 ) ;
case V_393 :
V_185 = F_193 () ;
break;
case V_394 :
V_185 = F_98 ( V_395 ) ;
break;
case V_396 :
V_185 = F_96 ( V_397 ) ;
break;
case V_229 :
V_185 = F_96 ( V_398 ) ;
break;
case V_216 :
if ( ! F_209 () )
return 1 ;
V_185 = F_99 ( V_399 ) ;
break;
case V_400 :
if ( ! F_206 ( V_8 ) )
return 1 ;
V_185 = F_6 ( V_8 ) -> V_14 . V_401 ;
break;
case V_373 ... V_402 :
if ( ! F_206 ( V_8 ) )
return 1 ;
return F_212 ( V_8 , V_371 , V_372 ) ;
case V_403 :
if ( ! F_65 () )
return 1 ;
V_185 = V_8 -> V_118 . V_404 ;
break;
case V_289 :
if ( ! F_6 ( V_8 ) -> V_290 )
return 1 ;
default:
V_76 = F_70 ( F_6 ( V_8 ) , V_371 ) ;
if ( V_76 ) {
V_185 = V_76 -> V_185 ;
break;
}
return F_216 ( V_8 , V_371 , V_372 ) ;
}
* V_372 = V_185 ;
return 0 ;
}
static int F_217 ( struct V_7 * V_8 , struct V_405 * V_406 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_88 * V_76 ;
int V_116 = 0 ;
T_2 V_371 = V_406 -> V_81 ;
T_3 V_185 = V_406 -> V_185 ;
switch ( V_371 ) {
case V_146 :
V_116 = F_218 ( V_8 , V_406 ) ;
break;
#ifdef F_100
case V_209 :
F_120 ( V_75 ) ;
F_103 ( V_391 , V_185 ) ;
break;
case V_211 :
F_120 ( V_75 ) ;
F_103 ( V_392 , V_185 ) ;
break;
case V_212 :
F_155 ( V_75 ) ;
V_75 -> V_214 = V_185 ;
break;
#endif
case V_394 :
F_106 ( V_395 , V_185 ) ;
break;
case V_396 :
F_103 ( V_397 , V_185 ) ;
break;
case V_229 :
F_103 ( V_398 , V_185 ) ;
break;
case V_216 :
if ( ! F_209 () )
return 1 ;
F_107 ( V_399 , V_185 ) ;
break;
case V_393 :
F_219 ( V_8 , V_406 ) ;
break;
case V_407 :
if ( V_30 . V_408 & V_334 ) {
if ( ! F_220 ( V_8 , V_407 , V_185 ) )
return 1 ;
F_107 ( V_409 , V_185 ) ;
V_8 -> V_118 . V_410 = V_185 ;
break;
}
V_116 = F_218 ( V_8 , V_406 ) ;
break;
case V_411 :
V_116 = F_218 ( V_8 , V_406 ) ;
break;
case V_400 :
if ( ! F_206 ( V_8 ) ||
( F_6 ( V_8 ) -> V_14 . V_401 &
V_412 && ! V_406 -> V_413 ) )
return 1 ;
V_75 -> V_14 . V_401 = V_185 ;
if ( V_406 -> V_413 && V_185 == 0 )
F_221 ( V_8 ) ;
break;
case V_373 ... V_402 :
return 1 ;
case V_403 :
if ( ! F_65 () )
return 1 ;
if ( V_185 != 0 )
return 1 ;
V_8 -> V_118 . V_404 = V_185 ;
if ( V_8 -> V_118 . V_404 != V_414 )
F_131 ( V_75 , V_403 ,
V_8 -> V_118 . V_404 , V_414 ) ;
else
F_129 ( V_75 , V_403 ) ;
break;
case V_289 :
if ( ! V_75 -> V_290 )
return 1 ;
if ( ( V_185 >> 32 ) != 0 )
return 1 ;
default:
V_76 = F_70 ( V_75 , V_371 ) ;
if ( V_76 ) {
T_3 V_415 = V_76 -> V_185 ;
V_76 -> V_185 = V_185 ;
if ( V_76 - V_75 -> V_80 < V_75 -> V_218 ) {
F_156 () ;
V_116 = F_147 ( V_76 -> V_81 , V_76 -> V_185 ,
V_76 -> V_107 ) ;
F_157 () ;
if ( V_116 )
V_76 -> V_185 = V_415 ;
}
break;
}
V_116 = F_218 ( V_8 , V_406 ) ;
}
return V_116 ;
}
static void F_222 ( struct V_7 * V_8 , enum V_416 V_417 )
{
F_175 ( V_417 , ( unsigned long * ) & V_8 -> V_118 . V_119 ) ;
switch ( V_417 ) {
case V_418 :
V_8 -> V_118 . V_419 [ V_418 ] = F_96 ( V_420 ) ;
break;
case V_421 :
V_8 -> V_118 . V_419 [ V_421 ] = F_96 ( V_422 ) ;
break;
case V_423 :
if ( V_103 )
F_223 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_224 ( void )
{
return F_225 () ;
}
static T_11 int F_226 ( void )
{
T_3 V_76 ;
F_57 ( V_400 , V_76 ) ;
if ( V_76 & V_412 ) {
if ( ! ( V_76 & V_424 )
&& F_227 () )
return 1 ;
if ( ! ( V_76 & V_425 )
&& ( V_76 & V_424 )
&& ! F_227 () ) {
F_73 ( V_168 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_76 & V_425 )
&& ! F_227 () )
return 1 ;
}
return 0 ;
}
static void F_159 ( T_3 V_17 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_228 ( void )
{
int V_93 = F_83 () ;
T_3 V_90 = F_72 ( F_86 ( V_222 , V_93 ) ) ;
T_3 V_426 , V_427 ;
if ( F_229 () & V_428 )
return - V_429 ;
F_230 ( & F_86 ( V_226 , V_93 ) ) ;
F_76 ( V_93 ) ;
F_57 ( V_400 , V_426 ) ;
V_427 = V_412 ;
V_427 |= V_425 ;
if ( F_227 () )
V_427 |= V_424 ;
if ( ( V_426 & V_427 ) != V_427 ) {
F_145 ( V_400 , V_426 | V_427 ) ;
}
F_231 ( F_229 () | V_428 ) ;
if ( V_223 ) {
F_159 ( V_90 ) ;
F_94 () ;
}
F_232 ( F_134 ( & V_171 ) ) ;
return 0 ;
}
static void F_233 ( void )
{
int V_93 = F_83 () ;
struct V_92 * V_96 , * V_430 ;
F_234 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_85 ( V_96 ) ;
}
static void F_166 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_235 ( void )
{
if ( V_223 ) {
F_233 () ;
F_166 () ;
}
F_231 ( F_229 () & ~ V_428 ) ;
}
static T_11 int F_236 ( T_2 V_431 , T_2 V_432 ,
T_2 V_76 , T_2 * V_433 )
{
T_2 V_434 , V_435 ;
T_2 V_436 = V_431 | V_432 ;
F_208 ( V_76 , V_434 , V_435 ) ;
V_436 &= V_435 ;
V_436 |= V_434 ;
if ( V_431 & ~ V_436 )
return - V_437 ;
* V_433 = V_436 ;
return 0 ;
}
static T_11 bool F_237 ( T_2 V_76 , T_2 V_436 )
{
T_2 V_434 , V_435 ;
F_208 ( V_76 , V_434 , V_435 ) ;
return V_435 & V_436 ;
}
static T_11 int F_238 ( struct V_30 * V_438 )
{
T_2 V_434 , V_435 ;
T_2 V_439 , V_440 , V_441 , V_442 ;
T_2 V_443 = 0 ;
T_2 V_444 = 0 ;
T_2 V_445 = 0 ;
T_2 V_446 = 0 ;
T_2 V_447 = 0 ;
V_439 = V_344 |
#ifdef F_100
V_349 |
V_350 |
#endif
V_347 |
V_348 |
V_353 |
V_351 |
V_302 |
V_346 |
V_354 |
V_345 |
V_355 ;
V_440 = V_33 |
V_32 |
V_34 ;
if ( F_236 ( V_439 , V_440 , V_338 ,
& V_444 ) < 0 )
return - V_437 ;
#ifdef F_100
if ( ( V_444 & V_33 ) )
V_444 &= ~ V_349 &
~ V_350 ;
#endif
if ( V_444 & V_34 ) {
V_441 = 0 ;
V_442 = V_36 |
V_37 |
V_64 |
V_60 |
V_56 |
V_57 |
V_58 |
V_61 |
V_62 |
V_38 |
V_39 |
V_68 |
V_74 ;
if ( F_236 ( V_441 , V_442 ,
V_359 ,
& V_445 ) < 0 )
return - V_437 ;
}
#ifndef F_100
if ( ! ( V_445 &
V_36 ) )
V_444 &= ~ V_33 ;
#endif
if ( ! ( V_444 & V_33 ) )
V_445 &= ~ (
V_38 |
V_37 |
V_39 ) ;
if ( V_445 & V_56 ) {
V_444 &= ~ ( V_347 |
V_348 |
V_345 ) ;
F_208 ( V_389 ,
V_42 . V_43 , V_42 . V_53 ) ;
}
V_439 = V_328 ;
#ifdef F_100
V_439 |= V_320 ;
#endif
V_440 = V_322 | V_321 |
V_325 | V_326 ;
if ( F_236 ( V_439 , V_440 , V_316 ,
& V_446 ) < 0 )
return - V_437 ;
V_439 = V_314 | V_315 ;
V_440 = V_63 | V_41 ;
if ( F_236 ( V_439 , V_440 , V_310 ,
& V_443 ) < 0 )
return - V_437 ;
if ( ! ( V_445 &
V_39 ) ||
! ( V_446 & V_325 ) )
V_443 &= ~ V_41 ;
V_439 = V_337 ;
V_440 = V_334 | V_335 ;
if ( F_236 ( V_439 , V_440 , V_329 ,
& V_447 ) < 0 )
return - V_437 ;
F_208 ( V_373 , V_434 , V_435 ) ;
if ( ( V_435 & 0x1fff ) > V_448 )
return - V_437 ;
#ifdef F_100
if ( V_435 & ( 1u << 16 ) )
return - V_437 ;
#endif
if ( ( ( V_435 >> 18 ) & 15 ) != 6 )
return - V_437 ;
V_438 -> V_449 = V_435 & 0x1fff ;
V_438 -> V_450 = F_239 ( V_30 . V_449 ) ;
V_438 -> V_451 = V_434 ;
V_438 -> V_40 = V_443 ;
V_438 -> V_31 = V_444 ;
V_438 -> V_35 = V_445 ;
V_438 -> V_452 = V_446 ;
V_438 -> V_408 = V_447 ;
V_147 =
F_237 ( V_329 ,
V_148 )
&& F_237 ( V_316 ,
V_149 ) ;
V_151 =
F_237 ( V_329 ,
V_152 )
&& F_237 ( V_316 ,
V_153 ) ;
if ( V_151 && V_453 . V_454 == 0x6 ) {
switch ( V_453 . V_455 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_151 = false ;
F_132 ( V_168 L_10
L_11 ) ;
break;
default:
break;
}
}
if ( V_456 )
F_57 ( V_403 , V_414 ) ;
return 0 ;
}
static struct V_89 * F_240 ( int V_93 )
{
int V_457 = F_241 ( V_93 ) ;
struct V_16 * V_458 ;
struct V_89 * V_89 ;
V_458 = F_242 ( V_457 , V_459 , V_30 . V_450 ) ;
if ( ! V_458 )
return NULL ;
V_89 = F_243 ( V_458 ) ;
memset ( V_89 , 0 , V_30 . V_449 ) ;
V_89 -> V_451 = V_30 . V_451 ;
return V_89 ;
}
static struct V_89 * F_244 ( void )
{
return F_240 ( F_83 () ) ;
}
static void F_245 ( struct V_89 * V_89 )
{
F_246 ( ( unsigned long ) V_89 , V_30 . V_450 ) ;
}
static void F_247 ( struct V_92 * V_92 )
{
if ( ! V_92 -> V_89 )
return;
F_89 ( V_92 ) ;
F_245 ( V_92 -> V_89 ) ;
V_92 -> V_89 = NULL ;
}
static void F_248 ( void )
{
int V_93 ;
F_249 (cpu) {
F_245 ( F_86 ( V_222 , V_93 ) ) ;
F_86 ( V_222 , V_93 ) = NULL ;
}
}
static void F_250 ( void )
{
int V_77 , V_460 ;
for ( V_77 = V_460 = 0 ; V_77 < V_461 ; V_77 ++ ) {
switch ( V_462 [ V_77 ] ) {
case V_399 :
if ( ! F_209 () )
continue;
break;
default:
break;
}
if ( V_460 < V_77 )
V_462 [ V_460 ] =
V_462 [ V_77 ] ;
V_460 ++ ;
}
V_461 = V_460 ;
for ( V_77 = 0 ; V_77 < V_461 ; V_77 ++ ) {
F_251 ( V_462 [ V_77 ] ,
V_463 ) ;
F_251 ( V_462 [ V_77 ] ,
V_464 ) ;
}
for ( V_77 = 0 ; V_77 < V_465 ; V_77 ++ )
F_251 ( V_466 [ V_77 ] ,
V_464 ) ;
}
static T_11 int F_252 ( void )
{
int V_93 ;
F_249 (cpu) {
struct V_89 * V_89 ;
V_89 = F_240 ( V_93 ) ;
if ( ! V_89 ) {
F_248 () ;
return - V_467 ;
}
F_86 ( V_222 , V_93 ) = V_89 ;
}
return 0 ;
}
static bool F_253 ( struct V_7 * V_8 )
{
return V_468 && ! F_254 ( V_8 ) ;
}
static void F_255 ( struct V_7 * V_8 , int V_115 ,
struct V_469 * V_470 )
{
if ( ! V_468 ) {
if ( V_115 == V_471 || V_115 == V_472 )
V_470 -> V_122 &= ~ V_473 ;
V_470 -> V_474 = V_470 -> V_122 & V_473 ;
V_470 -> V_189 = 1 ;
}
F_256 ( V_8 , V_470 , V_115 ) ;
}
static void F_257 ( struct V_7 * V_8 )
{
unsigned long V_475 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_477 ] , V_477 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_478 ] , V_478 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_479 ] , V_479 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_480 ] , V_480 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_472 ] , V_472 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_471 ] , V_471 ) ;
V_75 -> V_138 . V_139 = 0 ;
F_120 ( V_75 ) ;
F_256 ( V_8 , & V_75 -> V_138 . V_476 [ V_481 ] , V_481 ) ;
V_475 = F_96 ( V_248 ) ;
V_475 &= V_249 ;
V_475 |= V_75 -> V_138 . V_246 & ~ V_249 ;
F_103 ( V_248 , V_475 ) ;
F_103 ( V_482 , ( F_96 ( V_482 ) & ~ V_483 ) |
( F_96 ( V_484 ) & V_483 ) ) ;
F_126 ( V_8 ) ;
F_255 ( V_8 , V_471 , & V_75 -> V_138 . V_476 [ V_471 ] ) ;
F_255 ( V_8 , V_472 , & V_75 -> V_138 . V_476 [ V_472 ] ) ;
F_255 ( V_8 , V_477 , & V_75 -> V_138 . V_476 [ V_477 ] ) ;
F_255 ( V_8 , V_478 , & V_75 -> V_138 . V_476 [ V_478 ] ) ;
F_255 ( V_8 , V_479 , & V_75 -> V_138 . V_476 [ V_479 ] ) ;
F_255 ( V_8 , V_480 , & V_75 -> V_138 . V_476 [ V_480 ] ) ;
}
static void F_259 ( int V_115 , struct V_469 * V_470 )
{
const struct V_485 * V_486 = & V_124 [ V_115 ] ;
struct V_469 V_487 = * V_470 ;
V_487 . V_474 = 0x3 ;
if ( V_115 == V_471 )
V_487 . type = 0x3 ;
if ( ! V_468 ) {
V_487 . V_122 = V_487 . V_125 >> 4 ;
V_487 . V_125 = V_487 . V_125 & 0xffff0 ;
V_487 . V_127 = 0xffff ;
V_487 . V_488 = 0 ;
V_487 . V_489 = 0 ;
V_487 . V_490 = 1 ;
V_487 . V_189 = 1 ;
V_487 . V_491 = 0 ;
V_487 . V_492 = 0 ;
V_487 . type = 0x3 ;
V_487 . V_493 = 0 ;
if ( V_470 -> V_125 & 0xf )
F_132 ( V_168 L_12
L_13
L_14 , V_115 ) ;
}
F_105 ( V_486 -> V_122 , V_487 . V_122 ) ;
F_106 ( V_486 -> V_125 , V_487 . V_125 ) ;
F_106 ( V_486 -> V_127 , V_487 . V_127 ) ;
F_106 ( V_486 -> V_131 , F_260 ( & V_487 ) ) ;
}
static void F_261 ( struct V_7 * V_8 )
{
unsigned long V_475 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_481 ] , V_481 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_477 ] , V_477 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_478 ] , V_478 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_479 ] , V_479 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_480 ] , V_480 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_472 ] , V_472 ) ;
F_258 ( V_8 , & V_75 -> V_138 . V_476 [ V_471 ] , V_471 ) ;
V_75 -> V_138 . V_139 = 1 ;
if ( ! V_8 -> V_18 -> V_118 . V_494 )
F_132 ( V_168 L_15
L_16 ) ;
F_120 ( V_75 ) ;
F_103 ( V_495 , V_8 -> V_18 -> V_118 . V_494 ) ;
F_106 ( V_496 , V_497 - 1 ) ;
F_106 ( V_498 , 0x008b ) ;
V_475 = F_96 ( V_248 ) ;
V_75 -> V_138 . V_246 = V_475 ;
V_475 |= V_250 | V_251 ;
F_103 ( V_248 , V_475 ) ;
F_103 ( V_482 , F_96 ( V_482 ) | V_483 ) ;
F_126 ( V_8 ) ;
F_259 ( V_472 , & V_75 -> V_138 . V_476 [ V_472 ] ) ;
F_259 ( V_471 , & V_75 -> V_138 . V_476 [ V_471 ] ) ;
F_259 ( V_477 , & V_75 -> V_138 . V_476 [ V_477 ] ) ;
F_259 ( V_478 , & V_75 -> V_138 . V_476 [ V_478 ] ) ;
F_259 ( V_480 , & V_75 -> V_138 . V_476 [ V_480 ] ) ;
F_259 ( V_479 , & V_75 -> V_138 . V_476 [ V_479 ] ) ;
F_262 ( V_8 ) ;
}
static void F_263 ( struct V_7 * V_8 , T_3 V_179 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_88 * V_76 = F_70 ( V_75 , V_146 ) ;
if ( ! V_76 )
return;
F_155 ( F_6 ( V_8 ) ) ;
V_8 -> V_118 . V_179 = V_179 ;
if ( V_179 & V_182 ) {
F_113 ( F_6 ( V_8 ) , V_333 ) ;
V_76 -> V_185 = V_179 ;
} else {
F_114 ( F_6 ( V_8 ) , V_333 ) ;
V_76 -> V_185 = V_179 & ~ V_183 ;
}
F_192 ( V_75 ) ;
}
static void F_264 ( struct V_7 * V_8 )
{
T_2 V_499 ;
F_120 ( F_6 ( V_8 ) ) ;
V_499 = F_98 ( V_498 ) ;
if ( ( V_499 & V_500 ) != V_501 ) {
F_265 ( L_17 ,
V_502 ) ;
F_106 ( V_498 ,
( V_499 & ~ V_500 )
| V_501 ) ;
}
F_263 ( V_8 , V_8 -> V_118 . V_179 | V_182 ) ;
}
static void F_266 ( struct V_7 * V_8 )
{
F_114 ( F_6 ( V_8 ) , V_333 ) ;
F_263 ( V_8 , V_8 -> V_118 . V_179 & ~ V_182 ) ;
}
static void F_267 ( struct V_7 * V_8 )
{
F_93 ( F_6 ( V_8 ) ) ;
if ( V_103 ) {
if ( ! F_268 ( V_8 -> V_118 . V_503 . V_504 ) )
return;
F_95 ( F_269 ( V_8 -> V_118 . V_503 . V_504 ) ) ;
}
}
static void F_172 ( struct V_7 * V_8 )
{
T_9 V_235 = V_8 -> V_118 . V_235 ;
V_8 -> V_118 . V_231 &= ~ V_235 ;
V_8 -> V_118 . V_231 |= F_96 ( V_232 ) & V_235 ;
}
static void F_270 ( struct V_7 * V_8 )
{
if ( V_103 && F_271 ( V_8 ) )
V_8 -> V_118 . V_505 = F_96 ( V_506 ) ;
F_175 ( V_507 , ( T_9 * ) & V_8 -> V_118 . V_119 ) ;
}
static void F_272 ( struct V_7 * V_8 )
{
T_9 V_508 = V_8 -> V_118 . V_508 ;
V_8 -> V_118 . V_509 &= ~ V_508 ;
V_8 -> V_118 . V_509 |= F_96 ( V_482 ) & V_508 ;
}
static void F_273 ( struct V_7 * V_8 )
{
struct V_510 * V_503 = V_8 -> V_118 . V_511 ;
if ( ! F_174 ( V_423 ,
( unsigned long * ) & V_8 -> V_118 . V_512 ) )
return;
if ( F_271 ( V_8 ) && F_274 ( V_8 ) && ! F_144 ( V_8 ) ) {
F_107 ( V_513 , V_503 -> V_514 [ 0 ] ) ;
F_107 ( V_515 , V_503 -> V_514 [ 1 ] ) ;
F_107 ( V_516 , V_503 -> V_514 [ 2 ] ) ;
F_107 ( V_517 , V_503 -> V_514 [ 3 ] ) ;
}
}
static void F_223 ( struct V_7 * V_8 )
{
struct V_510 * V_503 = V_8 -> V_118 . V_511 ;
if ( F_271 ( V_8 ) && F_274 ( V_8 ) && ! F_144 ( V_8 ) ) {
V_503 -> V_514 [ 0 ] = F_99 ( V_513 ) ;
V_503 -> V_514 [ 1 ] = F_99 ( V_515 ) ;
V_503 -> V_514 [ 2 ] = F_99 ( V_516 ) ;
V_503 -> V_514 [ 3 ] = F_99 ( V_517 ) ;
}
F_175 ( V_423 ,
( unsigned long * ) & V_8 -> V_118 . V_119 ) ;
F_175 ( V_423 ,
( unsigned long * ) & V_8 -> V_118 . V_512 ) ;
}
static void F_275 ( unsigned long * V_518 ,
unsigned long V_231 ,
struct V_7 * V_8 )
{
if ( ! F_174 ( V_507 , ( T_9 * ) & V_8 -> V_118 . V_119 ) )
F_270 ( V_8 ) ;
if ( ! ( V_231 & V_519 ) ) {
F_106 ( V_520 ,
F_98 ( V_520 ) |
( V_347 |
V_348 ) ) ;
V_8 -> V_118 . V_231 = V_231 ;
F_276 ( V_8 , F_277 ( V_8 ) ) ;
} else if ( ! F_271 ( V_8 ) ) {
F_106 ( V_520 ,
F_98 ( V_520 ) &
~ ( V_347 |
V_348 ) ) ;
V_8 -> V_118 . V_231 = V_231 ;
F_276 ( V_8 , F_277 ( V_8 ) ) ;
}
if ( ! ( V_231 & V_521 ) )
* V_518 &= ~ V_521 ;
}
static void F_278 ( struct V_7 * V_8 , unsigned long V_231 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
unsigned long V_518 ;
V_518 = ( V_231 & ~ V_522 ) ;
if ( V_523 )
V_518 |= V_524 ;
else {
V_518 |= V_525 ;
if ( V_75 -> V_138 . V_139 && ( V_231 & V_526 ) )
F_257 ( V_8 ) ;
if ( ! V_75 -> V_138 . V_139 && ! ( V_231 & V_526 ) )
F_261 ( V_8 ) ;
}
#ifdef F_100
if ( V_8 -> V_118 . V_179 & V_183 ) {
if ( ! F_271 ( V_8 ) && ( V_231 & V_519 ) )
F_264 ( V_8 ) ;
if ( F_271 ( V_8 ) && ! ( V_231 & V_519 ) )
F_266 ( V_8 ) ;
}
#endif
if ( V_103 )
F_275 ( & V_518 , V_231 , V_8 ) ;
if ( ! V_8 -> V_140 )
V_518 |= V_233 | V_234 ;
F_103 ( V_244 , V_231 ) ;
F_103 ( V_232 , V_518 ) ;
V_8 -> V_118 . V_231 = V_231 ;
V_75 -> F_253 = F_253 ( V_8 ) ;
}
static T_3 F_269 ( unsigned long V_504 )
{
T_3 V_86 ;
V_86 = V_527 |
V_528 << V_529 ;
if ( V_530 )
V_86 |= V_531 ;
V_86 |= ( V_504 & V_532 ) ;
return V_86 ;
}
static void F_279 ( struct V_7 * V_8 , unsigned long V_505 )
{
unsigned long V_533 ;
T_3 V_86 ;
V_533 = V_505 ;
if ( V_103 ) {
V_86 = F_269 ( V_505 ) ;
F_107 ( V_534 , V_86 ) ;
if ( F_271 ( V_8 ) || F_127 ( V_8 ) )
V_533 = F_280 ( V_8 ) ;
else
V_533 = V_8 -> V_18 -> V_118 . V_535 ;
F_273 ( V_8 ) ;
}
F_267 ( V_8 ) ;
F_103 ( V_506 , V_533 ) ;
}
static int F_276 ( struct V_7 * V_8 , unsigned long V_509 )
{
unsigned long V_536 = V_509 | ( F_6 ( V_8 ) -> V_138 . V_139 ?
V_537 : V_538 ) ;
if ( V_509 & V_428 ) {
if ( ! F_206 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_14 . V_539 &&
( ( V_509 & F_214 ) != F_214 ) )
return 1 ;
V_8 -> V_118 . V_509 = V_509 ;
if ( V_103 ) {
if ( ! F_271 ( V_8 ) ) {
V_536 &= ~ V_540 ;
V_536 |= V_541 ;
V_536 &= ~ ( V_542 | V_543 ) ;
} else if ( ! ( V_509 & V_540 ) ) {
V_536 &= ~ V_540 ;
}
}
F_103 ( V_484 , V_509 ) ;
F_103 ( V_482 , V_536 ) ;
return 0 ;
}
static void F_258 ( struct V_7 * V_8 ,
struct V_469 * V_487 , int V_115 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_2 V_129 ;
if ( V_75 -> V_138 . V_139 && V_115 != V_544 ) {
* V_487 = V_75 -> V_138 . V_476 [ V_115 ] ;
if ( V_115 == V_481
|| V_487 -> V_122 == F_122 ( V_75 , V_115 ) )
return;
V_487 -> V_125 = F_123 ( V_75 , V_115 ) ;
V_487 -> V_122 = F_122 ( V_75 , V_115 ) ;
return;
}
V_487 -> V_125 = F_123 ( V_75 , V_115 ) ;
V_487 -> V_127 = F_124 ( V_75 , V_115 ) ;
V_487 -> V_122 = F_122 ( V_75 , V_115 ) ;
V_129 = F_125 ( V_75 , V_115 ) ;
V_487 -> V_492 = ( V_129 >> 16 ) & 1 ;
V_487 -> type = V_129 & 15 ;
V_487 -> V_189 = ( V_129 >> 4 ) & 1 ;
V_487 -> V_474 = ( V_129 >> 5 ) & 3 ;
V_487 -> V_490 = ! V_487 -> V_492 ;
V_487 -> V_493 = ( V_129 >> 12 ) & 1 ;
V_487 -> V_491 = ( V_129 >> 13 ) & 1 ;
V_487 -> V_489 = ( V_129 >> 14 ) & 1 ;
V_487 -> V_488 = ( V_129 >> 15 ) & 1 ;
}
static T_3 F_281 ( struct V_7 * V_8 , int V_115 )
{
struct V_469 V_189 ;
if ( F_6 ( V_8 ) -> V_138 . V_139 ) {
F_258 ( V_8 , & V_189 , V_115 ) ;
return V_189 . V_125 ;
}
return F_123 ( F_6 ( V_8 ) , V_115 ) ;
}
static int F_282 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( F_104 ( V_75 -> V_138 . V_139 ) )
return 0 ;
else {
int V_129 = F_125 ( V_75 , V_472 ) ;
return F_283 ( V_129 ) ;
}
}
static T_2 F_260 ( struct V_469 * V_487 )
{
T_2 V_129 ;
if ( V_487 -> V_492 || ! V_487 -> V_490 )
V_129 = 1 << 16 ;
else {
V_129 = V_487 -> type & 15 ;
V_129 |= ( V_487 -> V_189 & 1 ) << 4 ;
V_129 |= ( V_487 -> V_474 & 3 ) << 5 ;
V_129 |= ( V_487 -> V_490 & 1 ) << 7 ;
V_129 |= ( V_487 -> V_493 & 1 ) << 12 ;
V_129 |= ( V_487 -> V_491 & 1 ) << 13 ;
V_129 |= ( V_487 -> V_489 & 1 ) << 14 ;
V_129 |= ( V_487 -> V_488 & 1 ) << 15 ;
}
return V_129 ;
}
static void F_256 ( struct V_7 * V_8 ,
struct V_469 * V_487 , int V_115 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
const struct V_485 * V_486 = & V_124 [ V_115 ] ;
F_120 ( V_75 ) ;
if ( V_75 -> V_138 . V_139 && V_115 != V_544 ) {
V_75 -> V_138 . V_476 [ V_115 ] = * V_487 ;
if ( V_115 == V_481 )
F_105 ( V_486 -> V_122 , V_487 -> V_122 ) ;
else if ( V_487 -> V_189 )
F_259 ( V_115 , & V_75 -> V_138 . V_476 [ V_115 ] ) ;
goto V_545;
}
F_103 ( V_486 -> V_125 , V_487 -> V_125 ) ;
F_106 ( V_486 -> V_127 , V_487 -> V_127 ) ;
F_105 ( V_486 -> V_122 , V_487 -> V_122 ) ;
if ( V_523 && ( V_115 != V_544 ) )
V_487 -> type |= 0x1 ;
F_106 ( V_486 -> V_131 , F_260 ( V_487 ) ) ;
V_545:
V_75 -> F_253 = F_253 ( V_8 ) ;
}
static void F_284 ( struct V_7 * V_8 , int * V_489 , int * V_491 )
{
T_2 V_129 = F_125 ( F_6 ( V_8 ) , V_471 ) ;
* V_489 = ( V_129 >> 14 ) & 1 ;
* V_491 = ( V_129 >> 13 ) & 1 ;
}
static void F_285 ( struct V_7 * V_8 , struct V_169 * V_546 )
{
V_546 -> V_449 = F_98 ( V_547 ) ;
V_546 -> V_174 = F_96 ( V_548 ) ;
}
static void F_286 ( struct V_7 * V_8 , struct V_169 * V_546 )
{
F_106 ( V_547 , V_546 -> V_449 ) ;
F_103 ( V_548 , V_546 -> V_174 ) ;
}
static void F_287 ( struct V_7 * V_8 , struct V_169 * V_546 )
{
V_546 -> V_449 = F_98 ( V_549 ) ;
V_546 -> V_174 = F_96 ( V_550 ) ;
}
static void F_288 ( struct V_7 * V_8 , struct V_169 * V_546 )
{
F_106 ( V_549 , V_546 -> V_449 ) ;
F_103 ( V_550 , V_546 -> V_174 ) ;
}
static bool F_289 ( struct V_7 * V_8 , int V_115 )
{
struct V_469 V_487 ;
T_2 V_129 ;
F_258 ( V_8 , & V_487 , V_115 ) ;
V_487 . V_474 = 0x3 ;
if ( V_115 == V_471 )
V_487 . type = 0x3 ;
V_129 = F_260 ( & V_487 ) ;
if ( V_487 . V_125 != ( V_487 . V_122 << 4 ) )
return false ;
if ( V_487 . V_127 != 0xffff )
return false ;
if ( V_129 != 0xf3 )
return false ;
return true ;
}
static bool F_290 ( struct V_7 * V_8 )
{
struct V_469 V_551 ;
unsigned int V_552 ;
F_258 ( V_8 , & V_551 , V_471 ) ;
V_552 = V_551 . V_122 & V_473 ;
if ( V_551 . V_492 )
return false ;
if ( ~ V_551 . type & ( V_553 | V_554 ) )
return false ;
if ( ! V_551 . V_189 )
return false ;
if ( V_551 . type & V_555 ) {
if ( V_551 . V_474 > V_552 )
return false ;
} else {
if ( V_551 . V_474 != V_552 )
return false ;
}
if ( ! V_551 . V_490 )
return false ;
return true ;
}
static bool F_291 ( struct V_7 * V_8 )
{
struct V_469 V_556 ;
unsigned int V_557 ;
F_258 ( V_8 , & V_556 , V_472 ) ;
V_557 = V_556 . V_122 & V_473 ;
if ( V_556 . V_492 )
return true ;
if ( V_556 . type != 3 && V_556 . type != 7 )
return false ;
if ( ! V_556 . V_189 )
return false ;
if ( V_556 . V_474 != V_557 )
return false ;
if ( ! V_556 . V_490 )
return false ;
return true ;
}
static bool F_292 ( struct V_7 * V_8 , int V_115 )
{
struct V_469 V_487 ;
unsigned int V_558 ;
F_258 ( V_8 , & V_487 , V_115 ) ;
V_558 = V_487 . V_122 & V_473 ;
if ( V_487 . V_492 )
return true ;
if ( ! V_487 . V_189 )
return false ;
if ( ! V_487 . V_490 )
return false ;
if ( ~ V_487 . type & ( V_553 | V_555 ) ) {
if ( V_487 . V_474 < V_558 )
return false ;
}
return true ;
}
static bool F_293 ( struct V_7 * V_8 )
{
struct V_469 V_192 ;
F_258 ( V_8 , & V_192 , V_481 ) ;
if ( V_192 . V_492 )
return false ;
if ( V_192 . V_122 & V_559 )
return false ;
if ( V_192 . type != 3 && V_192 . type != 11 )
return false ;
if ( ! V_192 . V_490 )
return false ;
return true ;
}
static bool F_294 ( struct V_7 * V_8 )
{
struct V_469 V_560 ;
F_258 ( V_8 , & V_560 , V_544 ) ;
if ( V_560 . V_492 )
return true ;
if ( V_560 . V_122 & V_559 )
return false ;
if ( V_560 . type != 2 )
return false ;
if ( ! V_560 . V_490 )
return false ;
return true ;
}
static bool F_295 ( struct V_7 * V_8 )
{
struct V_469 V_551 , V_556 ;
F_258 ( V_8 , & V_551 , V_471 ) ;
F_258 ( V_8 , & V_556 , V_472 ) ;
return ( ( V_551 . V_122 & V_473 ) ==
( V_556 . V_122 & V_473 ) ) ;
}
static bool F_254 ( struct V_7 * V_8 )
{
if ( V_523 )
return true ;
if ( ! F_296 ( V_8 ) || ( F_173 ( V_8 ) & V_251 ) ) {
if ( ! F_289 ( V_8 , V_471 ) )
return false ;
if ( ! F_289 ( V_8 , V_472 ) )
return false ;
if ( ! F_289 ( V_8 , V_478 ) )
return false ;
if ( ! F_289 ( V_8 , V_477 ) )
return false ;
if ( ! F_289 ( V_8 , V_479 ) )
return false ;
if ( ! F_289 ( V_8 , V_480 ) )
return false ;
} else {
if ( ! F_295 ( V_8 ) )
return false ;
if ( ! F_290 ( V_8 ) )
return false ;
if ( ! F_291 ( V_8 ) )
return false ;
if ( ! F_292 ( V_8 , V_478 ) )
return false ;
if ( ! F_292 ( V_8 , V_477 ) )
return false ;
if ( ! F_292 ( V_8 , V_479 ) )
return false ;
if ( ! F_292 ( V_8 , V_480 ) )
return false ;
if ( ! F_293 ( V_8 ) )
return false ;
if ( ! F_294 ( V_8 ) )
return false ;
}
return true ;
}
static int F_297 ( struct V_18 * V_18 )
{
T_12 V_561 ;
T_4 V_185 = 0 ;
int V_562 , V_563 ;
V_562 = F_298 ( & V_18 -> V_564 ) ;
V_561 = V_18 -> V_118 . V_494 >> V_19 ;
V_563 = F_299 ( V_18 , V_561 , 0 , V_448 ) ;
if ( V_563 < 0 )
goto V_545;
V_185 = V_565 + V_566 ;
V_563 = F_300 ( V_18 , V_561 ++ , & V_185 ,
V_567 , sizeof( T_4 ) ) ;
if ( V_563 < 0 )
goto V_545;
V_563 = F_299 ( V_18 , V_561 ++ , 0 , V_448 ) ;
if ( V_563 < 0 )
goto V_545;
V_563 = F_299 ( V_18 , V_561 , 0 , V_448 ) ;
if ( V_563 < 0 )
goto V_545;
V_185 = ~ 0 ;
V_563 = F_300 ( V_18 , V_561 , & V_185 ,
V_497 - 2 * V_448 - 1 ,
sizeof( T_6 ) ) ;
V_545:
F_301 ( & V_18 -> V_564 , V_562 ) ;
return V_563 ;
}
static int F_302 ( struct V_18 * V_18 )
{
int V_77 , V_562 , V_563 = 0 ;
T_13 V_568 ;
T_2 V_278 ;
if ( ! V_103 )
return 0 ;
F_303 ( & V_18 -> V_569 ) ;
if ( F_304 ( V_18 -> V_118 . V_570 ) )
goto V_571;
V_568 = V_18 -> V_118 . V_535 >> V_19 ;
V_563 = F_305 ( V_18 ) ;
if ( V_563 < 0 )
goto V_571;
V_562 = F_298 ( & V_18 -> V_564 ) ;
V_563 = F_299 ( V_18 , V_568 , 0 , V_448 ) ;
if ( V_563 < 0 )
goto V_545;
for ( V_77 = 0 ; V_77 < V_572 ; V_77 ++ ) {
V_278 = ( V_77 << 22 ) + ( V_573 | V_574 | V_575 |
V_576 | V_577 | V_578 ) ;
V_563 = F_300 ( V_18 , V_568 ,
& V_278 , V_77 * sizeof( V_278 ) , sizeof( V_278 ) ) ;
if ( V_563 < 0 )
goto V_545;
}
V_18 -> V_118 . V_570 = true ;
V_545:
F_301 ( & V_18 -> V_564 , V_562 ) ;
V_571:
F_306 ( & V_18 -> V_569 ) ;
return V_563 ;
}
static void F_307 ( int V_115 )
{
const struct V_485 * V_486 = & V_124 [ V_115 ] ;
unsigned int V_129 ;
F_105 ( V_486 -> V_122 , 0 ) ;
F_103 ( V_486 -> V_125 , 0 ) ;
F_106 ( V_486 -> V_127 , 0xffff ) ;
V_129 = 0x93 ;
if ( V_115 == V_471 )
V_129 |= 0x08 ;
F_106 ( V_486 -> V_131 , V_129 ) ;
}
static int F_308 ( struct V_18 * V_18 )
{
struct V_16 * V_16 ;
struct V_579 V_580 ;
int V_563 = 0 ;
F_303 ( & V_18 -> V_569 ) ;
if ( V_18 -> V_118 . V_581 )
goto V_545;
V_580 . V_582 = V_583 ;
V_580 . V_475 = 0 ;
V_580 . V_584 = V_585 ;
V_580 . V_586 = V_448 ;
V_563 = F_309 ( V_18 , & V_580 ) ;
if ( V_563 )
goto V_545;
V_16 = F_13 ( V_18 , V_585 >> V_19 ) ;
if ( F_14 ( V_16 ) ) {
V_563 = - V_587 ;
goto V_545;
}
F_310 ( V_16 ) ;
V_18 -> V_118 . V_581 = true ;
V_545:
F_306 ( & V_18 -> V_569 ) ;
return V_563 ;
}
static int F_305 ( struct V_18 * V_18 )
{
struct V_579 V_580 ;
int V_563 = 0 ;
F_311 ( V_18 -> V_118 . V_570 ) ;
V_580 . V_582 = V_588 ;
V_580 . V_475 = 0 ;
V_580 . V_584 =
V_18 -> V_118 . V_535 ;
V_580 . V_586 = V_448 ;
V_563 = F_309 ( V_18 , & V_580 ) ;
return V_563 ;
}
static void F_312 ( struct V_6 * V_75 )
{
int V_53 ;
V_75 -> V_53 = 0 ;
if ( ! V_589 )
return;
F_313 ( & V_590 ) ;
V_53 = F_314 ( V_591 , V_592 ) ;
if ( V_53 < V_592 ) {
V_75 -> V_53 = V_53 ;
F_175 ( V_53 , V_591 ) ;
}
F_315 ( & V_590 ) ;
}
static void F_316 ( struct V_6 * V_75 )
{
if ( ! V_589 )
return;
F_313 ( & V_590 ) ;
if ( V_75 -> V_53 != 0 )
F_317 ( V_75 -> V_53 , V_591 ) ;
F_315 ( & V_590 ) ;
}
static void F_318 ( unsigned long * V_279 ,
T_2 V_76 , int type )
{
int V_593 = sizeof( unsigned long ) ;
if ( ! F_24 () )
return;
if ( V_76 <= 0x1fff ) {
if ( type & V_594 )
F_317 ( V_76 , V_279 + 0x000 / V_593 ) ;
if ( type & V_595 )
F_317 ( V_76 , V_279 + 0x800 / V_593 ) ;
} else if ( ( V_76 >= 0xc0000000 ) && ( V_76 <= 0xc0001fff ) ) {
V_76 &= 0x1fff ;
if ( type & V_594 )
F_317 ( V_76 , V_279 + 0x400 / V_593 ) ;
if ( type & V_595 )
F_317 ( V_76 , V_279 + 0xc00 / V_593 ) ;
}
}
static void F_319 ( unsigned long * V_279 ,
T_2 V_76 , int type )
{
int V_593 = sizeof( unsigned long ) ;
if ( ! F_24 () )
return;
if ( V_76 <= 0x1fff ) {
if ( type & V_594 )
F_175 ( V_76 , V_279 + 0x000 / V_593 ) ;
if ( type & V_595 )
F_175 ( V_76 , V_279 + 0x800 / V_593 ) ;
} else if ( ( V_76 >= 0xc0000000 ) && ( V_76 <= 0xc0001fff ) ) {
V_76 &= 0x1fff ;
if ( type & V_594 )
F_175 ( V_76 , V_279 + 0x400 / V_593 ) ;
if ( type & V_595 )
F_175 ( V_76 , V_279 + 0xc00 / V_593 ) ;
}
}
static void F_320 ( T_2 V_76 , bool V_596 )
{
if ( ! V_596 )
F_318 ( V_284 ,
V_76 , V_594 | V_595 ) ;
F_318 ( V_283 ,
V_76 , V_594 | V_595 ) ;
}
static void F_321 ( T_2 V_76 )
{
F_319 ( V_282 ,
V_76 , V_594 ) ;
F_319 ( V_281 ,
V_76 , V_594 ) ;
}
static void F_322 ( T_2 V_76 )
{
F_318 ( V_282 ,
V_76 , V_594 ) ;
F_318 ( V_281 ,
V_76 , V_594 ) ;
}
static void F_323 ( T_2 V_76 )
{
F_318 ( V_282 ,
V_76 , V_595 ) ;
F_318 ( V_281 ,
V_76 , V_595 ) ;
}
static int F_324 ( struct V_18 * V_18 )
{
return V_597 && F_27 ( V_18 ) ;
}
static void F_325 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_563 ;
if ( F_5 ( V_4 , & V_75 -> V_1 ) )
return;
V_563 = F_1 ( & V_75 -> V_1 ) ;
F_160 ( V_598 , V_8 ) ;
#ifdef F_326
if ( ! V_563 && ( V_8 -> V_599 == V_600 ) )
V_280 -> V_601 ( F_327 ( V_8 -> V_93 ) ,
V_602 ) ;
else
#endif
F_328 ( V_8 ) ;
}
static void F_329 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_75 -> V_1 ) )
return;
F_330 ( V_8 , V_75 -> V_1 . V_5 ) ;
}
static void F_331 ( struct V_7 * V_8 )
{
return;
}
static void F_332 ( struct V_6 * V_75 )
{
T_2 V_603 , V_604 ;
unsigned long V_605 ;
struct V_169 V_546 ;
unsigned long V_509 ;
F_103 ( V_606 , F_333 () & ~ V_233 ) ;
F_103 ( V_607 , F_334 () ) ;
V_509 = F_229 () ;
F_103 ( V_608 , V_509 ) ;
V_75 -> V_193 . V_609 = V_509 ;
F_105 ( V_610 , V_611 ) ;
#ifdef F_100
F_105 ( V_612 , 0 ) ;
F_105 ( V_613 , 0 ) ;
#else
F_105 ( V_612 , V_614 ) ;
F_105 ( V_613 , V_614 ) ;
#endif
F_105 ( V_615 , V_614 ) ;
F_105 ( V_616 , V_175 * 8 ) ;
F_335 ( & V_546 ) ;
F_103 ( V_617 , V_546 . V_174 ) ;
V_75 -> V_618 = V_546 . V_174 ;
F_103 ( V_619 , V_620 ) ;
F_208 ( V_394 , V_603 , V_604 ) ;
F_106 ( V_621 , V_603 ) ;
F_57 ( V_396 , V_605 ) ;
F_103 ( V_622 , V_605 ) ;
if ( V_30 . V_452 & V_321 ) {
F_208 ( V_407 , V_603 , V_604 ) ;
F_107 ( V_623 , V_603 | ( ( T_3 ) V_604 << 32 ) ) ;
}
}
static void F_336 ( struct V_6 * V_75 )
{
V_75 -> V_8 . V_118 . V_508 = V_624 ;
if ( V_103 )
V_75 -> V_8 . V_118 . V_508 |= V_625 ;
if ( F_127 ( & V_75 -> V_8 ) )
V_75 -> V_8 . V_118 . V_508 &=
~ F_11 ( & V_75 -> V_8 ) -> V_242 ;
F_103 ( V_626 , ~ V_75 -> V_8 . V_118 . V_508 ) ;
}
static T_2 F_337 ( struct V_6 * V_75 )
{
T_2 V_40 = V_30 . V_40 ;
if ( ! F_324 ( V_75 -> V_8 . V_18 ) )
V_40 &= ~ V_41 ;
return V_40 ;
}
static T_2 F_338 ( struct V_6 * V_75 )
{
T_2 V_627 = V_30 . V_31 ;
if ( V_75 -> V_8 . V_118 . V_628 & V_629 )
V_627 &= ~ V_351 ;
if ( ! F_26 ( V_75 -> V_8 . V_18 ) ) {
V_627 &= ~ V_33 ;
#ifdef F_100
V_627 |= V_350 |
V_349 ;
#endif
}
if ( ! V_103 )
V_627 |= V_348 |
V_347 |
V_345 ;
return V_627 ;
}
static T_2 F_339 ( struct V_6 * V_75 )
{
T_2 V_627 = V_30 . V_35 ;
if ( ! F_50 ( V_75 -> V_8 . V_18 ) )
V_627 &= ~ V_36 ;
if ( V_75 -> V_53 == 0 )
V_627 &= ~ V_60 ;
if ( ! V_103 ) {
V_627 &= ~ V_56 ;
V_523 = 0 ;
V_627 &= ~ V_62 ;
}
if ( ! V_523 )
V_627 &= ~ V_57 ;
if ( ! V_630 )
V_627 &= ~ V_58 ;
if ( ! F_324 ( V_75 -> V_8 . V_18 ) )
V_627 &= ~ ( V_38 |
V_39 ) ;
V_627 &= ~ V_37 ;
V_627 &= ~ V_68 ;
return V_627 ;
}
static void F_340 ( void )
{
F_341 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_342 ( struct V_6 * V_75 )
{
#ifdef F_100
unsigned long V_631 ;
#endif
int V_77 ;
F_107 ( V_632 , F_72 ( V_633 ) ) ;
F_107 ( V_634 , F_72 ( V_635 ) ) ;
if ( V_636 ) {
F_107 ( V_637 , F_72 ( V_464 ) ) ;
F_107 ( V_638 , F_72 ( V_463 ) ) ;
}
if ( F_24 () )
F_107 ( V_285 , F_72 ( V_284 ) ) ;
F_107 ( V_639 , - 1ull ) ;
F_106 ( V_640 , F_337 ( V_75 ) ) ;
F_106 ( V_520 , F_338 ( V_75 ) ) ;
if ( F_28 () ) {
F_106 ( V_641 ,
F_339 ( V_75 ) ) ;
}
if ( F_324 ( V_75 -> V_8 . V_18 ) ) {
F_107 ( V_642 , 0 ) ;
F_107 ( V_643 , 0 ) ;
F_107 ( V_644 , 0 ) ;
F_107 ( V_645 , 0 ) ;
F_105 ( V_646 , 0 ) ;
F_107 ( V_647 , V_602 ) ;
F_107 ( V_648 , F_72 ( ( & V_75 -> V_1 ) ) ) ;
}
if ( V_630 ) {
F_106 ( V_649 , V_630 ) ;
V_75 -> V_650 = V_650 ;
V_75 -> V_651 = true ;
}
F_106 ( V_652 , 0 ) ;
F_106 ( V_653 , 0 ) ;
F_106 ( V_654 , 0 ) ;
F_105 ( V_199 , 0 ) ;
F_105 ( V_203 , 0 ) ;
F_332 ( V_75 ) ;
#ifdef F_100
F_57 ( V_209 , V_631 ) ;
F_103 ( V_208 , V_631 ) ;
F_57 ( V_211 , V_631 ) ;
F_103 ( V_210 , V_631 ) ;
#else
F_103 ( V_208 , 0 ) ;
F_103 ( V_210 , 0 ) ;
#endif
F_106 ( V_655 , 0 ) ;
F_106 ( V_158 , 0 ) ;
F_107 ( V_656 , F_72 ( V_75 -> V_144 . V_156 ) ) ;
F_106 ( V_157 , 0 ) ;
F_107 ( V_657 , F_72 ( V_75 -> V_144 . V_155 ) ) ;
if ( V_30 . V_408 & V_334 ) {
T_2 V_658 , V_659 ;
T_3 V_660 ;
F_208 ( V_407 , V_658 , V_659 ) ;
V_660 = V_658 | ( ( T_3 ) V_659 << 32 ) ;
F_107 ( V_409 , V_660 ) ;
V_75 -> V_8 . V_118 . V_410 = V_660 ;
}
for ( V_77 = 0 ; V_77 < F_10 ( V_79 ) ; ++ V_77 ) {
T_2 V_81 = V_79 [ V_77 ] ;
T_2 V_661 , V_662 ;
int V_460 = V_75 -> V_78 ;
if ( F_343 ( V_81 , & V_661 , & V_662 ) < 0 )
continue;
if ( F_344 ( V_81 , V_661 , V_662 ) < 0 )
continue;
V_75 -> V_80 [ V_460 ] . V_81 = V_77 ;
V_75 -> V_80 [ V_460 ] . V_185 = 0 ;
V_75 -> V_80 [ V_460 ] . V_107 = - 1ull ;
++ V_75 -> V_78 ;
}
F_115 ( V_75 , V_30 . V_452 ) ;
F_110 ( V_75 , V_30 . V_408 ) ;
F_103 ( V_237 , ~ 0UL ) ;
F_336 ( V_75 ) ;
if ( F_65 () )
F_107 ( V_663 , V_664 ) ;
return 0 ;
}
static void F_345 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_405 V_665 ;
V_75 -> V_138 . V_139 = 0 ;
V_75 -> V_666 = 0 ;
V_75 -> V_8 . V_118 . V_419 [ V_667 ] = F_346 () ;
F_347 ( & V_75 -> V_8 , 0 ) ;
V_665 . V_185 = V_585 | V_668 ;
if ( F_348 ( & V_75 -> V_8 ) )
V_665 . V_185 |= V_669 ;
V_665 . V_413 = true ;
F_349 ( & V_75 -> V_8 , & V_665 ) ;
F_120 ( V_75 ) ;
F_307 ( V_471 ) ;
F_105 ( V_670 , 0xf000 ) ;
F_106 ( V_671 , 0xffff0000 ) ;
F_307 ( V_478 ) ;
F_307 ( V_477 ) ;
F_307 ( V_479 ) ;
F_307 ( V_480 ) ;
F_307 ( V_472 ) ;
F_105 ( V_672 , 0 ) ;
F_103 ( V_495 , 0 ) ;
F_106 ( V_496 , 0xffff ) ;
F_106 ( V_498 , 0x008b ) ;
F_105 ( V_673 , 0 ) ;
F_103 ( V_674 , 0 ) ;
F_106 ( V_675 , 0xffff ) ;
F_106 ( V_676 , 0x00082 ) ;
F_106 ( V_395 , 0 ) ;
F_103 ( V_398 , 0 ) ;
F_103 ( V_397 , 0 ) ;
F_103 ( V_248 , 0x02 ) ;
F_181 ( V_8 , 0xfff0 ) ;
F_103 ( V_550 , 0 ) ;
F_106 ( V_549 , 0xffff ) ;
F_103 ( V_548 , 0 ) ;
F_106 ( V_547 , 0xffff ) ;
F_106 ( V_677 , V_678 ) ;
F_106 ( V_253 , 0 ) ;
F_106 ( V_679 , 0 ) ;
F_107 ( V_680 , 0 ) ;
F_192 ( V_75 ) ;
F_106 ( V_275 , 0 ) ;
if ( F_25 () ) {
F_107 ( V_681 , 0 ) ;
if ( F_26 ( V_75 -> V_8 . V_18 ) )
F_107 ( V_681 ,
F_72 ( V_75 -> V_8 . V_118 . V_280 -> V_419 ) ) ;
F_106 ( V_682 , 0 ) ;
}
F_160 ( V_683 , V_8 ) ;
if ( F_324 ( V_8 -> V_18 ) )
memset ( & V_75 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_75 -> V_53 != 0 )
F_105 ( V_684 , V_75 -> V_53 ) ;
V_75 -> V_8 . V_118 . V_231 = V_685 | V_686 | V_687 ;
F_278 ( & V_75 -> V_8 , F_350 ( V_8 ) ) ;
F_276 ( & V_75 -> V_8 , 0 ) ;
F_263 ( & V_75 -> V_8 , 0 ) ;
F_167 ( & V_75 -> V_8 ) ;
F_126 ( & V_75 -> V_8 ) ;
F_93 ( V_75 ) ;
}
static bool F_351 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_72 &
V_314 ;
}
static bool F_352 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_688 &
V_325 ;
}
static bool F_353 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_72 &
V_315 ;
}
static void F_354 ( struct V_7 * V_8 )
{
T_2 V_70 ;
V_70 = F_98 ( V_520 ) ;
V_70 |= V_342 ;
F_106 ( V_520 , V_70 ) ;
}
static void F_355 ( struct V_7 * V_8 )
{
T_2 V_70 ;
if ( ! F_54 () ||
F_98 ( V_253 ) & V_254 ) {
F_354 ( V_8 ) ;
return;
}
V_70 = F_98 ( V_520 ) ;
V_70 |= V_343 ;
F_106 ( V_520 , V_70 ) ;
}
static void F_356 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_14 V_689 ;
int V_690 = V_8 -> V_118 . V_691 . V_154 ;
F_357 ( V_690 ) ;
++ V_8 -> V_219 . V_692 ;
if ( V_75 -> V_138 . V_139 ) {
int V_269 = 0 ;
if ( V_8 -> V_118 . V_691 . V_693 )
V_269 = V_8 -> V_118 . V_270 ;
if ( F_186 ( V_8 , V_690 , V_269 ) != V_271 )
F_160 ( V_272 , V_8 ) ;
return;
}
V_689 = V_690 | V_23 ;
if ( V_8 -> V_118 . V_691 . V_693 ) {
V_689 |= V_694 ;
F_106 ( V_273 ,
V_75 -> V_8 . V_118 . V_270 ) ;
} else
V_689 |= V_28 ;
F_106 ( V_275 , V_689 ) ;
}
static void F_358 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( F_127 ( V_8 ) )
return;
if ( ! F_54 () ) {
V_75 -> V_666 = 1 ;
V_75 -> V_695 = 0 ;
}
++ V_8 -> V_219 . V_696 ;
V_75 -> V_697 = false ;
if ( V_75 -> V_138 . V_139 ) {
if ( F_186 ( V_8 , V_698 , 0 ) != V_271 )
F_160 ( V_272 , V_8 ) ;
return;
}
F_106 ( V_275 ,
V_699 | V_23 | V_698 ) ;
}
static bool F_359 ( struct V_7 * V_8 )
{
if ( ! F_54 () )
return F_6 ( V_8 ) -> V_666 ;
if ( F_6 ( V_8 ) -> V_697 )
return false ;
return F_98 ( V_253 ) & V_700 ;
}
static void F_360 ( struct V_7 * V_8 , bool V_701 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( ! F_54 () ) {
if ( V_75 -> V_666 != V_701 ) {
V_75 -> V_666 = V_701 ;
V_75 -> V_695 = 0 ;
}
} else {
V_75 -> V_697 = ! V_701 ;
if ( V_701 )
F_109 ( V_253 ,
V_700 ) ;
else
F_108 ( V_253 ,
V_700 ) ;
}
}
static int F_361 ( struct V_7 * V_8 )
{
if ( F_6 ( V_8 ) -> V_14 . V_702 )
return 0 ;
if ( ! F_54 () && F_6 ( V_8 ) -> V_666 )
return 0 ;
return ! ( F_98 ( V_253 ) &
( V_256 | V_254
| V_700 ) ) ;
}
static int F_362 ( struct V_7 * V_8 )
{
return ( ! F_6 ( V_8 ) -> V_14 . V_702 &&
F_96 ( V_248 ) & V_703 ) &&
! ( F_98 ( V_253 ) &
( V_254 | V_256 ) ) ;
}
static int F_363 ( struct V_18 * V_18 , unsigned int V_17 )
{
int V_116 ;
struct V_579 V_704 = {
. V_582 = V_705 ,
. V_584 = V_17 ,
. V_586 = V_448 * 3 ,
. V_475 = 0 ,
} ;
V_116 = F_364 ( V_18 , & V_704 ) ;
if ( V_116 )
return V_116 ;
V_18 -> V_118 . V_494 = V_17 ;
return F_297 ( V_18 ) ;
}
static bool F_365 ( struct V_7 * V_8 , int V_706 )
{
switch ( V_706 ) {
case V_137 :
F_6 ( V_8 ) -> V_8 . V_118 . V_270 =
F_98 ( V_260 ) ;
if ( V_8 -> V_134 & V_136 )
return false ;
case V_133 :
if ( V_8 -> V_134 &
( V_707 | V_708 ) )
return false ;
case V_709 :
case V_710 :
case V_711 :
case V_27 :
case V_712 :
case V_713 :
case V_714 :
case V_715 :
return true ;
break;
}
return false ;
}
static int F_366 ( struct V_7 * V_8 ,
int V_706 , T_2 V_716 )
{
if ( ( ( V_706 == V_714 ) || ( V_706 == V_713 ) ) && V_716 == 0 ) {
if ( F_367 ( V_8 , 0 ) == V_271 ) {
if ( V_8 -> V_118 . V_717 ) {
V_8 -> V_118 . V_717 = 0 ;
return F_368 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_369 ( V_8 , V_706 ) ;
return 1 ;
}
static void F_370 ( void )
{
#if F_371 ( V_718 ) && F_371 ( F_100 )
struct V_719 V_419 = {
. V_551 = 3 ,
. V_475 = V_703 ,
} ;
F_372 ( & V_419 , 0 ) ;
#endif
}
static int F_373 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_374 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_720 * V_720 = V_8 -> V_721 ;
T_2 V_20 , V_722 , V_265 ;
unsigned long V_723 , V_259 , V_724 ;
T_2 V_725 ;
enum V_726 V_727 ;
V_725 = V_75 -> V_728 ;
V_20 = V_75 -> V_729 ;
if ( F_23 ( V_20 ) )
return F_373 ( V_8 ) ;
if ( ( V_20 & V_21 ) == V_699 )
return 1 ;
if ( F_20 ( V_20 ) ) {
F_167 ( V_8 ) ;
return 1 ;
}
if ( F_21 ( V_20 ) ) {
V_727 = F_367 ( V_8 , V_730 ) ;
if ( V_727 != V_271 )
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
V_265 = 0 ;
if ( V_20 & V_268 )
V_265 = F_98 ( V_731 ) ;
if ( ( V_725 & V_732 ) &&
! ( F_19 ( V_20 ) && ! ( V_265 & V_733 ) ) ) {
V_8 -> V_721 -> V_261 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_737 ;
V_8 -> V_721 -> V_735 . V_738 = 2 ;
V_8 -> V_721 -> V_735 . V_185 [ 0 ] = V_725 ;
V_8 -> V_721 -> V_735 . V_185 [ 1 ] = V_20 ;
return 0 ;
}
if ( F_19 ( V_20 ) ) {
F_311 ( V_103 ) ;
V_723 = F_96 ( V_263 ) ;
F_375 ( V_723 , V_265 ) ;
if ( F_376 ( V_8 ) )
F_377 ( V_8 , V_723 ) ;
return F_378 ( V_8 , V_723 , V_265 , NULL , 0 ) ;
}
V_722 = V_20 & V_22 ;
if ( V_75 -> V_138 . V_139 && F_365 ( V_8 , V_722 ) )
return F_366 ( V_8 , V_722 , V_265 ) ;
switch ( V_722 ) {
case V_133 :
V_724 = F_96 ( V_263 ) ;
if ( ! ( V_8 -> V_134 &
( V_707 | V_708 ) ) ) {
V_8 -> V_118 . V_724 &= ~ 15 ;
V_8 -> V_118 . V_724 |= V_724 | V_739 ;
if ( ! ( V_724 & ~ V_740 ) )
F_179 ( V_8 ) ;
F_369 ( V_8 , V_133 ) ;
return 1 ;
}
V_720 -> V_741 . V_118 . V_724 = V_724 | V_742 ;
V_720 -> V_741 . V_118 . V_743 = F_96 ( V_744 ) ;
case V_137 :
V_75 -> V_8 . V_118 . V_270 =
F_98 ( V_260 ) ;
V_720 -> V_261 = V_745 ;
V_259 = F_180 ( V_8 ) ;
V_720 -> V_741 . V_118 . V_746 = F_96 ( V_671 ) + V_259 ;
V_720 -> V_741 . V_118 . V_747 = V_722 ;
break;
default:
V_720 -> V_261 = V_748 ;
V_720 -> V_749 . V_747 = V_722 ;
V_720 -> V_749 . V_265 = V_265 ;
break;
}
return 0 ;
}
static int F_379 ( struct V_7 * V_8 )
{
++ V_8 -> V_219 . V_750 ;
return 1 ;
}
static int F_380 ( struct V_7 * V_8 )
{
V_8 -> V_721 -> V_261 = V_751 ;
return 0 ;
}
static int F_381 ( struct V_7 * V_8 )
{
unsigned long V_752 ;
int V_449 , V_753 , string ;
unsigned V_754 ;
V_752 = F_96 ( V_263 ) ;
string = ( V_752 & 16 ) != 0 ;
V_753 = ( V_752 & 8 ) != 0 ;
++ V_8 -> V_219 . V_755 ;
if ( string || V_753 )
return F_367 ( V_8 , 0 ) == V_271 ;
V_754 = V_752 >> 16 ;
V_449 = ( V_752 & 7 ) + 1 ;
F_179 ( V_8 ) ;
return F_382 ( V_8 , V_449 , V_754 ) ;
}
static void
F_383 ( struct V_7 * V_8 , unsigned char * V_756 )
{
V_756 [ 0 ] = 0x0f ;
V_756 [ 1 ] = 0x01 ;
V_756 [ 2 ] = 0xc1 ;
}
static bool F_384 ( struct V_13 * V_13 , unsigned long V_108 )
{
unsigned long V_757 = F_213 ;
if ( V_361 &
V_57 &&
F_60 ( V_13 , V_57 ) )
V_757 &= ~ ( V_526 | V_519 ) ;
return ( V_108 & V_757 ) == V_757 ;
}
static int F_385 ( struct V_7 * V_8 , unsigned long V_108 )
{
if ( F_127 ( V_8 ) ) {
struct V_13 * V_13 = F_11 ( V_8 ) ;
unsigned long V_758 = V_108 ;
V_108 = ( V_108 & ~ V_13 -> V_236 ) |
( V_13 -> V_239 & V_13 -> V_236 ) ;
if ( ! F_384 ( V_13 , V_108 ) )
return 1 ;
if ( F_386 ( V_8 , V_108 ) )
return 1 ;
F_103 ( V_244 , V_758 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_14 . V_539 &&
( ( V_108 & F_213 ) != F_213 ) )
return 1 ;
return F_386 ( V_8 , V_108 ) ;
}
}
static int F_387 ( struct V_7 * V_8 , unsigned long V_108 )
{
if ( F_127 ( V_8 ) ) {
struct V_13 * V_13 = F_11 ( V_8 ) ;
unsigned long V_758 = V_108 ;
V_108 = ( V_108 & ~ V_13 -> V_242 ) |
( V_13 -> V_241 & V_13 -> V_242 ) ;
if ( F_388 ( V_8 , V_108 ) )
return 1 ;
F_103 ( V_484 , V_758 ) ;
return 0 ;
} else
return F_388 ( V_8 , V_108 ) ;
}
static void F_389 ( struct V_7 * V_8 )
{
if ( F_127 ( V_8 ) ) {
F_103 ( V_244 ,
F_96 ( V_244 ) & ~ V_233 ) ;
V_8 -> V_118 . V_231 &= ~ V_233 ;
} else
F_278 ( V_8 , F_168 ( V_8 , ~ V_233 ) ) ;
}
static int F_390 ( struct V_7 * V_8 )
{
unsigned long V_752 , V_108 ;
int V_759 ;
int V_417 ;
int V_760 ;
V_752 = F_96 ( V_263 ) ;
V_759 = V_752 & 15 ;
V_417 = ( V_752 >> 8 ) & 15 ;
switch ( ( V_752 >> 4 ) & 3 ) {
case 0 :
V_108 = F_391 ( V_8 , V_417 ) ;
F_392 ( V_759 , V_108 ) ;
switch ( V_759 ) {
case 0 :
V_760 = F_385 ( V_8 , V_108 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
case 3 :
V_760 = F_394 ( V_8 , V_108 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
case 4 :
V_760 = F_387 ( V_8 , V_108 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
case 8 : {
T_6 V_761 = F_395 ( V_8 ) ;
T_6 V_762 = ( T_6 ) V_108 ;
V_760 = F_347 ( V_8 , V_762 ) ;
F_393 ( V_8 , V_760 ) ;
if ( F_27 ( V_8 -> V_18 ) )
return 1 ;
if ( V_761 <= V_762 )
return 1 ;
V_8 -> V_721 -> V_261 = V_763 ;
return 0 ;
}
}
break;
case 2 :
F_389 ( V_8 ) ;
F_392 ( 0 , F_350 ( V_8 ) ) ;
F_179 ( V_8 ) ;
F_167 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_759 ) {
case 3 :
V_108 = F_280 ( V_8 ) ;
F_396 ( V_8 , V_417 , V_108 ) ;
F_397 ( V_759 , V_108 ) ;
F_179 ( V_8 ) ;
return 1 ;
case 8 :
V_108 = F_395 ( V_8 ) ;
F_396 ( V_8 , V_417 , V_108 ) ;
F_397 ( V_759 , V_108 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_108 = ( V_752 >> V_764 ) & 0x0f ;
F_392 ( 0 , ( F_350 ( V_8 ) & ~ 0xful ) | V_108 ) ;
F_398 ( V_8 , V_108 ) ;
F_179 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_721 -> V_261 = 0 ;
F_399 ( V_8 , L_18 ,
( int ) ( V_752 >> 4 ) & 3 , V_759 ) ;
return 0 ;
}
static int F_400 ( struct V_7 * V_8 )
{
unsigned long V_752 ;
int V_765 , V_743 , V_417 ;
V_752 = F_96 ( V_263 ) ;
V_765 = V_752 & V_766 ;
if ( ! F_401 ( V_8 , V_765 ) )
return 1 ;
if ( ! F_402 ( V_8 , 0 ) )
return 1 ;
V_743 = F_96 ( V_744 ) ;
if ( V_743 & V_767 ) {
if ( V_8 -> V_134 & V_708 ) {
V_8 -> V_721 -> V_741 . V_118 . V_724 = V_8 -> V_118 . V_724 ;
V_8 -> V_721 -> V_741 . V_118 . V_743 = V_743 ;
V_8 -> V_721 -> V_741 . V_118 . V_746 = F_403 ( V_8 ) ;
V_8 -> V_721 -> V_741 . V_118 . V_747 = V_133 ;
V_8 -> V_721 -> V_261 = V_745 ;
return 0 ;
} else {
V_8 -> V_118 . V_724 &= ~ 15 ;
V_8 -> V_118 . V_724 |= V_768 | V_739 ;
F_369 ( V_8 , V_133 ) ;
return 1 ;
}
}
if ( V_8 -> V_134 == 0 ) {
T_2 V_70 ;
V_70 = F_98 ( V_520 ) ;
V_70 &= ~ V_351 ;
F_106 ( V_520 , V_70 ) ;
V_8 -> V_118 . V_628 |= V_629 ;
return 1 ;
}
V_417 = F_404 ( V_752 ) ;
if ( V_752 & V_769 ) {
unsigned long V_108 ;
if ( F_405 ( V_8 , V_765 , & V_108 ) )
return 1 ;
F_396 ( V_8 , V_417 , V_108 ) ;
} else
if ( F_406 ( V_8 , V_765 , F_391 ( V_8 , V_417 ) ) )
return 1 ;
F_179 ( V_8 ) ;
return 1 ;
}
static T_3 F_407 ( struct V_7 * V_8 )
{
return V_8 -> V_118 . V_724 ;
}
static void F_408 ( struct V_7 * V_8 , unsigned long V_108 )
{
}
static void F_409 ( struct V_7 * V_8 )
{
T_2 V_70 ;
F_410 ( V_8 -> V_118 . V_489 [ 0 ] , 0 ) ;
F_410 ( V_8 -> V_118 . V_489 [ 1 ] , 1 ) ;
F_410 ( V_8 -> V_118 . V_489 [ 2 ] , 2 ) ;
F_410 ( V_8 -> V_118 . V_489 [ 3 ] , 3 ) ;
F_410 ( V_8 -> V_118 . V_724 , 6 ) ;
V_8 -> V_118 . V_743 = F_96 ( V_744 ) ;
V_8 -> V_118 . V_628 &= ~ V_629 ;
V_70 = F_98 ( V_520 ) ;
V_70 |= V_351 ;
F_106 ( V_520 , V_70 ) ;
}
static void F_411 ( struct V_7 * V_8 , unsigned long V_108 )
{
F_103 ( V_744 , V_108 ) ;
}
static int F_412 ( struct V_7 * V_8 )
{
F_413 ( V_8 ) ;
return 1 ;
}
static int F_414 ( struct V_7 * V_8 )
{
T_2 V_308 = V_8 -> V_118 . V_419 [ V_770 ] ;
T_3 V_185 ;
if ( F_215 ( V_8 , V_308 , & V_185 ) ) {
F_415 ( V_308 ) ;
F_416 ( V_8 , 0 ) ;
return 1 ;
}
F_417 ( V_308 , V_185 ) ;
V_8 -> V_118 . V_419 [ V_771 ] = V_185 & - 1u ;
V_8 -> V_118 . V_419 [ V_667 ] = ( V_185 >> 32 ) & - 1u ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_418 ( struct V_7 * V_8 )
{
struct V_405 V_76 ;
T_2 V_308 = V_8 -> V_118 . V_419 [ V_770 ] ;
T_3 V_185 = ( V_8 -> V_118 . V_419 [ V_771 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_118 . V_419 [ V_667 ] & - 1u ) << 32 ) ;
V_76 . V_185 = V_185 ;
V_76 . V_81 = V_308 ;
V_76 . V_413 = false ;
if ( F_419 ( V_8 , & V_76 ) != 0 ) {
F_420 ( V_308 , V_185 ) ;
F_416 ( V_8 , 0 ) ;
return 1 ;
}
F_421 ( V_308 , V_185 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_422 ( struct V_7 * V_8 )
{
F_160 ( V_598 , V_8 ) ;
return 1 ;
}
static int F_423 ( struct V_7 * V_8 )
{
T_2 V_70 ;
V_70 = F_98 ( V_520 ) ;
V_70 &= ~ V_342 ;
F_106 ( V_520 , V_70 ) ;
F_160 ( V_598 , V_8 ) ;
++ V_8 -> V_219 . V_772 ;
if ( ! F_27 ( V_8 -> V_18 ) &&
V_8 -> V_721 -> V_773 &&
! F_424 ( V_8 ) ) {
V_8 -> V_721 -> V_261 = V_774 ;
return 0 ;
}
return 1 ;
}
static int F_425 ( struct V_7 * V_8 )
{
F_179 ( V_8 ) ;
return F_368 ( V_8 ) ;
}
static int F_426 ( struct V_7 * V_8 )
{
F_179 ( V_8 ) ;
F_427 ( V_8 ) ;
return 1 ;
}
static int F_428 ( struct V_7 * V_8 )
{
return F_367 ( V_8 , 0 ) == V_271 ;
}
static int F_429 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_96 ( V_263 ) ;
F_430 ( V_8 , V_752 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_431 ( struct V_7 * V_8 )
{
int V_760 ;
V_760 = F_432 ( V_8 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
}
static int F_433 ( struct V_7 * V_8 )
{
F_179 ( V_8 ) ;
F_434 ( V_8 ) ;
return 1 ;
}
static int F_435 ( struct V_7 * V_8 )
{
T_3 V_775 = F_436 ( V_8 ) ;
T_2 V_81 = F_437 ( V_8 , V_770 ) ;
if ( F_438 ( V_8 , V_81 , V_775 ) == 0 )
F_179 ( V_8 ) ;
return 1 ;
}
static int F_439 ( struct V_7 * V_8 )
{
F_179 ( V_8 ) ;
F_197 ( 1 , L_19 ) ;
return 1 ;
}
static int F_440 ( struct V_7 * V_8 )
{
F_179 ( V_8 ) ;
F_197 ( 1 , L_19 ) ;
return 1 ;
}
static int F_441 ( struct V_7 * V_8 )
{
if ( F_304 ( V_776 ) ) {
unsigned long V_752 = F_96 ( V_263 ) ;
int V_777 , V_301 ;
V_777 = V_752 & V_778 ;
V_301 = V_752 & V_779 ;
if ( ( V_777 == V_780 ) &&
( V_301 == V_781 ) ) {
F_442 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
}
return F_367 ( V_8 , 0 ) == V_271 ;
}
static int F_443 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_96 ( V_263 ) ;
int V_4 = V_752 & 0xff ;
F_444 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_445 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_96 ( V_263 ) ;
T_2 V_301 = V_752 & 0xfff ;
F_446 ( V_8 , V_301 ) ;
return 1 ;
}
static int F_447 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
unsigned long V_752 ;
bool V_264 = false ;
T_2 V_265 = 0 ;
T_4 V_782 ;
int V_783 , type , V_784 , V_785 ;
V_784 = ( V_75 -> V_728 & V_732 ) ;
V_785 = ( V_75 -> V_728 & V_786 ) ;
type = ( V_75 -> V_728 & V_787 ) ;
V_752 = F_96 ( V_263 ) ;
V_783 = ( T_2 ) V_752 >> 30 ;
if ( V_783 == V_788 && V_784 ) {
switch ( type ) {
case V_699 :
V_8 -> V_118 . V_789 = false ;
F_360 ( V_8 , true ) ;
break;
case V_28 :
case V_694 :
F_448 ( V_8 ) ;
break;
case V_24 :
if ( V_75 -> V_728 &
V_790 ) {
V_264 = true ;
V_265 =
F_98 ( V_791 ) ;
}
case V_274 :
F_449 ( V_8 ) ;
break;
default:
break;
}
}
V_782 = V_752 ;
if ( ! V_784 || ( type != V_24 &&
type != V_28 &&
type != V_699 ) )
F_179 ( V_8 ) ;
if ( F_450 ( V_8 , V_782 ,
type == V_694 ? V_785 : - 1 , V_783 ,
V_264 , V_265 ) == V_792 ) {
V_8 -> V_721 -> V_261 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_793 ;
V_8 -> V_721 -> V_735 . V_738 = 0 ;
return 0 ;
}
F_103 ( V_744 , F_96 ( V_744 ) & ~ 0x155 ) ;
return 1 ;
}
static int F_451 ( struct V_7 * V_8 )
{
unsigned long V_752 ;
T_1 V_87 ;
T_2 V_265 ;
int V_794 ;
V_752 = F_96 ( V_263 ) ;
V_794 = ( V_752 >> 7 ) & 0x3 ;
if ( V_794 != 0x3 && V_794 != 0x1 && V_794 != 0 ) {
F_73 ( V_91 L_20 ) ;
F_73 ( V_91 L_21 ,
( long unsigned int ) F_99 ( V_795 ) ,
F_96 ( V_796 ) ) ;
F_73 ( V_91 L_22 ,
( long unsigned int ) V_752 ) ;
V_8 -> V_721 -> V_261 = V_797 ;
V_8 -> V_721 -> V_798 . V_799 = V_800 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_728 & V_732 ) &&
F_54 () &&
( V_752 & V_801 ) )
F_109 ( V_253 , V_700 ) ;
V_87 = F_99 ( V_795 ) ;
F_375 ( V_87 , V_752 ) ;
V_265 = V_752 & V_802 ;
V_265 |= ( V_752 << 2 ) & V_803 ;
V_265 |= ( V_752 >> 3 ) & V_804 ;
V_8 -> V_118 . V_752 = V_752 ;
return F_378 ( V_8 , V_87 , V_265 , NULL , 0 ) ;
}
static T_3 F_452 ( T_3 V_805 , int V_806 )
{
int V_77 ;
T_3 V_107 = 0 ;
for ( V_77 = 51 ; V_77 > V_453 . V_807 ; V_77 -- )
V_107 |= ( 1ULL << V_77 ) ;
if ( V_806 == 4 )
V_107 |= 0xf8 ;
else if ( V_805 & ( 1ULL << 7 ) )
V_107 |= ( V_448 << ( ( V_806 - 1 ) * 9 ) ) - V_448 ;
else if ( V_806 > 1 )
V_107 |= 0x78 ;
return V_107 ;
}
static void F_453 ( struct V_7 * V_8 , T_3 V_805 ,
int V_806 )
{
F_73 ( V_91 L_23 , V_502 , V_805 , V_806 ) ;
F_454 ( ( V_805 & 0x7 ) == 0x2 ) ;
F_454 ( ( V_805 & 0x7 ) == 0x6 ) ;
if ( ! F_36 () )
F_454 ( ( V_805 & 0x7 ) == 0x4 ) ;
if ( ( V_805 & 0x7 ) ) {
T_3 V_808 = V_805 & F_452 ( V_805 , V_806 ) ;
if ( V_808 != 0 ) {
F_73 ( V_91 L_24 ,
V_502 , V_808 ) ;
F_454 ( 1 ) ;
}
if ( ( V_808 & 0x38 ) == 0 ) {
T_3 V_809 = ( V_805 & 0x38 ) >> 3 ;
if ( V_809 == 2 || V_809 == 3 ||
V_809 == 7 ) {
F_73 ( V_91 L_25 ,
V_502 , V_809 ) ;
F_454 ( 1 ) ;
}
}
}
}
static int F_455 ( struct V_7 * V_8 )
{
T_3 V_810 [ 4 ] ;
int V_811 , V_77 , V_116 ;
T_1 V_87 ;
V_87 = F_99 ( V_795 ) ;
if ( ! F_456 ( V_8 -> V_18 , V_812 , V_87 , 0 , NULL ) ) {
F_179 ( V_8 ) ;
return 1 ;
}
V_116 = F_457 ( V_8 , V_87 , true ) ;
if ( F_304 ( V_116 == V_813 ) )
return F_458 ( V_8 , V_87 , 0 , NULL , 0 ) ==
V_271 ;
if ( F_104 ( V_116 == V_814 ) )
return F_378 ( V_8 , V_87 , 0 , NULL , 0 ) ;
if ( F_104 ( V_116 == V_815 ) )
return 1 ;
F_73 ( V_91 L_26 ) ;
F_73 ( V_91 L_27 , V_87 ) ;
V_811 = F_459 ( V_8 , V_87 , V_810 ) ;
for ( V_77 = V_816 ; V_77 > V_816 - V_811 ; -- V_77 )
F_453 ( V_8 , V_810 [ V_77 - 1 ] , V_77 ) ;
V_8 -> V_721 -> V_261 = V_797 ;
V_8 -> V_721 -> V_798 . V_799 = V_817 ;
return 0 ;
}
static int F_460 ( struct V_7 * V_8 )
{
T_2 V_70 ;
V_70 = F_98 ( V_520 ) ;
V_70 &= ~ V_343 ;
F_106 ( V_520 , V_70 ) ;
++ V_8 -> V_219 . V_818 ;
F_160 ( V_598 , V_8 ) ;
return 1 ;
}
static int F_461 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
enum V_726 V_760 = V_271 ;
int V_116 = 1 ;
T_2 V_819 ;
bool V_820 ;
unsigned V_821 = 130 ;
V_819 = F_98 ( V_520 ) ;
V_820 = V_819 & V_342 ;
while ( V_75 -> F_253 && V_821 -- != 0 ) {
if ( V_820 && F_362 ( V_8 ) )
return F_423 ( & V_75 -> V_8 ) ;
if ( F_174 ( V_598 , & V_8 -> V_822 ) )
return 1 ;
V_760 = F_367 ( V_8 , V_823 ) ;
if ( V_760 == V_824 ) {
++ V_8 -> V_219 . V_825 ;
V_116 = 0 ;
goto V_545;
}
if ( V_760 != V_271 ) {
V_8 -> V_721 -> V_261 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_793 ;
V_8 -> V_721 -> V_735 . V_738 = 0 ;
return 0 ;
}
if ( V_8 -> V_118 . V_717 ) {
V_8 -> V_118 . V_717 = 0 ;
V_116 = F_368 ( V_8 ) ;
goto V_545;
}
if ( F_462 ( V_826 ) )
goto V_545;
if ( F_463 () )
F_464 () ;
}
V_545:
return V_116 ;
}
static int F_465 ( int V_108 )
{
if ( V_827 < 1 )
return V_650 ;
V_108 = V_439 ( V_108 , V_828 ) ;
if ( V_827 < V_650 )
V_108 *= V_827 ;
else
V_108 += V_827 ;
return V_108 ;
}
static int F_466 ( int V_108 , int V_829 , int V_830 )
{
if ( V_829 < 1 )
return V_650 ;
if ( V_829 < V_650 )
V_108 /= V_829 ;
else
V_108 -= V_829 ;
return F_467 ( V_108 , V_830 ) ;
}
static void F_468 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_426 = V_75 -> V_650 ;
V_75 -> V_650 = F_465 ( V_426 ) ;
if ( V_75 -> V_650 != V_426 )
V_75 -> V_651 = true ;
F_469 ( V_8 -> V_303 , V_75 -> V_650 , V_426 ) ;
}
static void F_470 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_426 = V_75 -> V_650 ;
V_75 -> V_650 = F_466 ( V_426 ,
V_831 , V_650 ) ;
if ( V_75 -> V_650 != V_426 )
V_75 -> V_651 = true ;
F_471 ( V_8 -> V_303 , V_75 -> V_650 , V_426 ) ;
}
static void F_472 ( void )
{
V_828 =
F_466 ( F_467 ( V_832 , V_650 ) ,
V_827 , V_833 ) ;
}
static T_11 int F_473 ( void )
{
int V_563 = - V_467 , V_77 , V_76 ;
F_474 ( V_146 , & V_184 ) ;
for ( V_77 = 0 ; V_77 < F_10 ( V_79 ) ; ++ V_77 )
F_475 ( V_77 , V_79 [ V_77 ] ) ;
V_633 = ( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_633 )
return V_563 ;
V_635 = ( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_635 )
goto V_545;
V_284 = ( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_284 )
goto V_834;
V_282 =
( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_282 )
goto V_571;
V_283 = ( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_283 )
goto V_835;
V_281 =
( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_281 )
goto V_836;
V_464 = ( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_464 )
goto V_837;
V_463 = ( unsigned long * ) F_476 ( V_459 ) ;
if ( ! V_463 )
goto V_838;
memset ( V_464 , 0xff , V_448 ) ;
memset ( V_463 , 0xff , V_448 ) ;
memset ( V_633 , 0xff , V_448 ) ;
F_251 ( 0x80 , V_633 ) ;
memset ( V_635 , 0xff , V_448 ) ;
memset ( V_284 , 0xff , V_448 ) ;
memset ( V_283 , 0xff , V_448 ) ;
if ( F_238 ( & V_30 ) < 0 ) {
V_563 = - V_437 ;
goto V_839;
}
if ( F_146 ( V_840 ) )
F_477 ( V_180 ) ;
if ( ! F_51 () )
V_589 = 0 ;
if ( ! F_56 () )
V_636 = 0 ;
if ( V_636 )
F_250 () ;
if ( ! F_47 () ||
! F_41 () ) {
V_103 = 0 ;
V_523 = 0 ;
V_530 = 0 ;
}
if ( ! F_42 () )
V_530 = 0 ;
if ( ! F_48 () )
V_523 = 0 ;
if ( ! F_35 () ) {
V_59 = 0 ;
V_841 -> V_842 = NULL ;
}
if ( ! F_25 () )
V_841 -> V_843 = NULL ;
if ( V_103 && ! F_39 () )
F_478 () ;
if ( ! F_49 () )
V_630 = 0 ;
if ( ! F_34 () )
V_597 = 0 ;
if ( V_597 )
V_841 -> V_843 = NULL ;
else {
V_841 -> V_844 = NULL ;
V_841 -> V_845 = NULL ;
V_841 -> V_846 = F_331 ;
}
if ( V_14 )
F_207 () ;
F_320 ( V_209 , false ) ;
F_320 ( V_211 , false ) ;
F_320 ( V_212 , true ) ;
F_320 ( V_394 , false ) ;
F_320 ( V_229 , false ) ;
F_320 ( V_396 , false ) ;
F_320 ( V_216 , true ) ;
memcpy ( V_282 ,
V_284 , V_448 ) ;
memcpy ( V_281 ,
V_283 , V_448 ) ;
if ( V_597 ) {
for ( V_76 = 0x800 ; V_76 <= 0x8ff ; V_76 ++ )
F_322 ( V_76 ) ;
F_321 ( 0x802 ) ;
F_321 ( 0x839 ) ;
F_323 ( 0x808 ) ;
F_323 ( 0x80b ) ;
F_323 ( 0x83f ) ;
}
if ( V_103 ) {
F_479 ( 0ull ,
( V_530 ) ? V_847 : 0ull ,
( V_530 ) ? V_848 : 0ull ,
0ull , V_849 ) ;
F_340 () ;
F_480 () ;
} else
F_481 () ;
F_472 () ;
return F_252 () ;
V_839:
F_482 ( ( unsigned long ) V_463 ) ;
V_838:
F_482 ( ( unsigned long ) V_464 ) ;
V_837:
F_482 ( ( unsigned long ) V_281 ) ;
V_836:
F_482 ( ( unsigned long ) V_283 ) ;
V_835:
F_482 ( ( unsigned long ) V_282 ) ;
V_571:
F_482 ( ( unsigned long ) V_284 ) ;
V_834:
F_482 ( ( unsigned long ) V_635 ) ;
V_545:
F_482 ( ( unsigned long ) V_633 ) ;
return V_563 ;
}
static T_15 void F_483 ( void )
{
F_482 ( ( unsigned long ) V_282 ) ;
F_482 ( ( unsigned long ) V_281 ) ;
F_482 ( ( unsigned long ) V_284 ) ;
F_482 ( ( unsigned long ) V_283 ) ;
F_482 ( ( unsigned long ) V_635 ) ;
F_482 ( ( unsigned long ) V_633 ) ;
F_482 ( ( unsigned long ) V_463 ) ;
F_482 ( ( unsigned long ) V_464 ) ;
F_248 () ;
}
static int F_484 ( struct V_7 * V_8 )
{
if ( V_630 )
F_468 ( V_8 ) ;
F_179 ( V_8 ) ;
F_485 ( V_8 ) ;
return 1 ;
}
static int F_486 ( struct V_7 * V_8 )
{
F_179 ( V_8 ) ;
return 1 ;
}
static int F_487 ( struct V_7 * V_8 )
{
F_132 ( V_168 L_28 ) ;
return F_486 ( V_8 ) ;
}
static int F_488 ( struct V_7 * V_8 )
{
F_132 ( V_168 L_29 ) ;
return F_486 ( V_8 ) ;
}
static struct V_92 * F_489 ( struct V_6 * V_75 )
{
struct V_850 * V_851 ;
F_84 (item, &vmx->nested.vmcs02_pool, list)
if ( V_851 -> V_852 == V_75 -> V_14 . V_853 ) {
F_490 ( & V_851 -> V_854 , & V_75 -> V_14 . V_855 ) ;
return & V_851 -> V_856 ;
}
if ( V_75 -> V_14 . V_857 >= F_467 ( V_858 , 1 ) ) {
V_851 = F_491 ( V_75 -> V_14 . V_855 . V_859 ,
struct V_850 , V_854 ) ;
V_851 -> V_852 = V_75 -> V_14 . V_853 ;
F_490 ( & V_851 -> V_854 , & V_75 -> V_14 . V_855 ) ;
return & V_851 -> V_856 ;
}
V_851 = F_492 ( sizeof( struct V_850 ) , V_459 ) ;
if ( ! V_851 )
return NULL ;
V_851 -> V_856 . V_89 = F_244 () ;
if ( ! V_851 -> V_856 . V_89 ) {
F_493 ( V_851 ) ;
return NULL ;
}
F_74 ( & V_851 -> V_856 ) ;
V_851 -> V_852 = V_75 -> V_14 . V_853 ;
F_163 ( & ( V_851 -> V_854 ) , & ( V_75 -> V_14 . V_855 ) ) ;
V_75 -> V_14 . V_857 ++ ;
return & V_851 -> V_856 ;
}
static void F_494 ( struct V_6 * V_75 , T_1 V_852 )
{
struct V_850 * V_851 ;
F_84 (item, &vmx->nested.vmcs02_pool, list)
if ( V_851 -> V_852 == V_852 ) {
F_247 ( & V_851 -> V_856 ) ;
F_87 ( & V_851 -> V_854 ) ;
F_493 ( V_851 ) ;
V_75 -> V_14 . V_857 -- ;
return;
}
}
static void F_495 ( struct V_6 * V_75 )
{
struct V_850 * V_851 , * V_430 ;
F_454 ( V_75 -> V_92 != & V_75 -> V_860 ) ;
F_234 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_75 -> V_92 == & V_851 -> V_856 )
continue;
F_247 ( & V_851 -> V_856 ) ;
F_87 ( & V_851 -> V_854 ) ;
F_493 ( V_851 ) ;
V_75 -> V_14 . V_857 -- ;
}
}
static void F_496 ( struct V_7 * V_8 )
{
F_176 ( V_8 , F_173 ( V_8 )
& ~ ( V_861 | V_862 | V_863 |
V_864 | V_865 | V_866 ) ) ;
}
static void F_497 ( struct V_7 * V_8 )
{
F_176 ( V_8 , ( F_173 ( V_8 )
& ~ ( V_862 | V_863 | V_864 |
V_865 | V_866 ) )
| V_861 ) ;
}
static void F_498 ( struct V_7 * V_8 ,
T_2 V_867 )
{
if ( F_6 ( V_8 ) -> V_14 . V_853 == - 1ull ) {
F_497 ( V_8 ) ;
return;
}
F_176 ( V_8 , ( F_173 ( V_8 )
& ~ ( V_861 | V_862 | V_863 |
V_865 | V_866 ) )
| V_864 ) ;
F_11 ( V_8 ) -> V_867 = V_867 ;
}
static enum V_868 F_499 ( struct V_869 * V_870 )
{
struct V_6 * V_75 =
F_7 ( V_870 , struct V_6 , V_14 . V_871 ) ;
V_75 -> V_14 . V_872 = true ;
F_160 ( V_598 , & V_75 -> V_8 ) ;
F_328 ( & V_75 -> V_8 ) ;
return V_873 ;
}
static int F_500 ( struct V_7 * V_8 ,
unsigned long V_752 ,
T_2 V_874 , T_5 * V_116 )
{
int V_875 = V_874 & 3 ;
int V_876 = ( V_874 >> 7 ) & 7 ;
bool V_877 = V_874 & ( 1u << 10 ) ;
int V_878 = ( V_874 >> 15 ) & 7 ;
int V_879 = ( V_874 >> 18 ) & 0xf ;
bool V_880 = ! ( V_874 & ( 1u << 22 ) ) ;
int V_881 = ( V_874 >> 23 ) & 0xf ;
bool V_882 = ! ( V_874 & ( 1u << 27 ) ) ;
if ( V_877 ) {
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
* V_116 = F_281 ( V_8 , V_878 ) ;
if ( V_882 )
* V_116 += F_437 ( V_8 , V_881 ) ;
if ( V_880 )
* V_116 += F_437 ( V_8 , V_879 ) << V_875 ;
* V_116 += V_752 ;
if ( V_876 == 1 )
* V_116 &= 0xffffffff ;
return 0 ;
}
static int F_501 ( struct V_7 * V_8 , int V_261 ,
T_1 * V_883 )
{
T_5 V_83 ;
T_1 V_852 ;
struct V_884 V_885 ;
struct V_16 * V_16 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_886 = F_502 ( V_8 ) ;
if ( F_500 ( V_8 , F_96 ( V_263 ) ,
F_98 ( V_887 ) , & V_83 ) )
return 1 ;
if ( F_503 ( & V_8 -> V_118 . V_888 , V_83 , & V_852 ,
sizeof( V_852 ) , & V_885 ) ) {
F_504 ( V_8 , & V_885 ) ;
return 1 ;
}
switch ( V_261 ) {
case V_889 :
if ( ! F_505 ( V_852 ) || ( V_852 >> V_886 ) ) {
F_497 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
V_16 = F_12 ( V_8 , V_852 ) ;
if ( V_16 == NULL ||
* ( T_2 * ) F_506 ( V_16 ) != V_374 ) {
F_497 ( V_8 ) ;
F_507 ( V_16 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
F_507 ( V_16 ) ;
V_75 -> V_14 . V_890 = V_852 ;
break;
case V_891 :
if ( ! F_505 ( V_852 ) || ( V_852 >> V_886 ) ) {
F_498 ( V_8 ,
V_892 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
if ( V_852 == V_75 -> V_14 . V_890 ) {
F_498 ( V_8 ,
V_893 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
break;
case V_894 :
if ( ! F_505 ( V_852 ) || ( V_852 >> V_886 ) ) {
F_498 ( V_8 ,
V_895 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
if ( V_852 == V_75 -> V_14 . V_890 ) {
F_498 ( V_8 ,
V_893 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
break;
default:
return 1 ;
}
if ( V_883 )
* V_883 = V_852 ;
return 0 ;
}
static int F_508 ( struct V_7 * V_8 )
{
struct V_469 V_551 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_89 * V_896 ;
const T_3 V_897 = V_412
| V_425 ;
if ( ! F_509 ( V_8 , V_428 ) ||
! F_168 ( V_8 , V_526 ) ||
( F_173 ( V_8 ) & V_251 ) ) {
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
F_258 ( V_8 , & V_551 , V_471 ) ;
if ( F_144 ( V_8 ) && ! V_551 . V_491 ) {
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
if ( F_282 ( V_8 ) ) {
F_416 ( V_8 , 0 ) ;
return 1 ;
}
if ( F_501 ( V_8 , V_889 , NULL ) )
return 1 ;
if ( V_75 -> V_14 . V_539 ) {
F_498 ( V_8 , V_898 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
if ( ( V_75 -> V_14 . V_401 & V_897 )
!= V_897 ) {
F_416 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_636 ) {
V_896 = F_244 () ;
if ( ! V_896 )
return - V_467 ;
V_896 -> V_451 |= ( 1u << 31 ) ;
F_71 ( V_896 ) ;
V_75 -> V_14 . V_899 = V_896 ;
}
F_230 ( & ( V_75 -> V_14 . V_855 ) ) ;
V_75 -> V_14 . V_857 = 0 ;
F_510 ( & V_75 -> V_14 . V_871 , V_900 ,
V_901 ) ;
V_75 -> V_14 . V_871 . V_902 = F_499 ;
V_75 -> V_14 . V_539 = true ;
F_179 ( V_8 ) ;
F_496 ( V_8 ) ;
return 1 ;
}
static int F_511 ( struct V_7 * V_8 )
{
struct V_469 V_551 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( ! V_75 -> V_14 . V_539 ) {
F_369 ( V_8 , V_27 ) ;
return 0 ;
}
F_258 ( V_8 , & V_551 , V_471 ) ;
if ( ( F_173 ( V_8 ) & V_251 ) ||
( F_144 ( V_8 ) && ! V_551 . V_491 ) ) {
F_369 ( V_8 , V_27 ) ;
return 0 ;
}
if ( F_282 ( V_8 ) ) {
F_416 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_512 ( struct V_6 * V_75 )
{
T_2 V_627 ;
if ( V_75 -> V_14 . V_853 == - 1ull )
return;
if ( F_454 ( V_75 -> V_14 . V_15 == NULL ) )
return;
if ( V_636 ) {
F_513 ( V_75 ) ;
V_75 -> V_14 . V_903 = false ;
V_627 = F_98 ( V_641 ) ;
V_627 &= ~ V_68 ;
F_106 ( V_641 , V_627 ) ;
F_107 ( V_639 , - 1ull ) ;
}
F_507 ( V_75 -> V_14 . V_904 ) ;
F_15 ( V_75 -> V_14 . V_904 ) ;
V_75 -> V_14 . V_853 = - 1ull ;
V_75 -> V_14 . V_15 = NULL ;
}
static void F_514 ( struct V_6 * V_75 )
{
if ( ! V_75 -> V_14 . V_539 )
return;
V_75 -> V_14 . V_539 = false ;
F_512 ( V_75 ) ;
if ( V_636 )
F_245 ( V_75 -> V_14 . V_899 ) ;
if ( V_75 -> V_14 . V_905 ) {
F_15 ( V_75 -> V_14 . V_905 ) ;
V_75 -> V_14 . V_905 = NULL ;
}
if ( V_75 -> V_14 . V_906 ) {
F_15 ( V_75 -> V_14 . V_906 ) ;
V_75 -> V_14 . V_906 = NULL ;
}
F_495 ( V_75 ) ;
}
static int F_515 ( struct V_7 * V_8 )
{
if ( ! F_511 ( V_8 ) )
return 1 ;
F_514 ( F_6 ( V_8 ) ) ;
F_179 ( V_8 ) ;
F_496 ( V_8 ) ;
return 1 ;
}
static int F_516 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_1 V_852 ;
struct V_13 * V_13 ;
struct V_16 * V_16 ;
if ( ! F_511 ( V_8 ) )
return 1 ;
if ( F_501 ( V_8 , V_891 , & V_852 ) )
return 1 ;
if ( V_852 == V_75 -> V_14 . V_853 )
F_512 ( V_75 ) ;
V_16 = F_12 ( V_8 , V_852 ) ;
if ( V_16 == NULL ) {
F_160 ( V_272 , V_8 ) ;
return 1 ;
}
V_13 = F_506 ( V_16 ) ;
V_13 -> V_907 = 0 ;
F_507 ( V_16 ) ;
F_15 ( V_16 ) ;
F_494 ( V_75 , V_852 ) ;
F_179 ( V_8 ) ;
F_496 ( V_8 ) ;
return 1 ;
}
static int F_517 ( struct V_7 * V_8 )
{
return F_518 ( V_8 , true ) ;
}
static int F_519 ( struct V_7 * V_8 )
{
return F_518 ( V_8 , false ) ;
}
static inline int F_520 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_908 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_521 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline int F_522 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_116 )
{
short V_301 = F_8 ( V_9 ) ;
char * V_121 ;
if ( V_301 < 0 )
return V_301 ;
V_121 = ( ( char * ) ( F_11 ( V_8 ) ) ) + V_301 ;
switch ( F_520 ( V_9 ) ) {
case V_909 :
* V_116 = * ( ( V_910 * ) V_121 ) ;
return 0 ;
case V_911 :
* V_116 = * ( ( T_4 * ) V_121 ) ;
return 0 ;
case V_908 :
* V_116 = * ( ( T_2 * ) V_121 ) ;
return 0 ;
case V_912 :
* V_116 = * ( ( T_3 * ) V_121 ) ;
return 0 ;
default:
F_454 ( 1 ) ;
return - V_12 ;
}
}
static inline int F_523 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_913 ) {
short V_301 = F_8 ( V_9 ) ;
char * V_121 = ( ( char * ) F_11 ( V_8 ) ) + V_301 ;
if ( V_301 < 0 )
return V_301 ;
switch ( F_520 ( V_9 ) ) {
case V_911 :
* ( T_4 * ) V_121 = V_913 ;
return 0 ;
case V_908 :
* ( T_2 * ) V_121 = V_913 ;
return 0 ;
case V_912 :
* ( T_3 * ) V_121 = V_913 ;
return 0 ;
case V_909 :
* ( V_910 * ) V_121 = V_913 ;
return 0 ;
default:
F_454 ( 1 ) ;
return - V_12 ;
}
}
static void F_513 ( struct V_6 * V_75 )
{
int V_77 ;
unsigned long V_9 ;
T_3 V_913 ;
struct V_89 * V_896 = V_75 -> V_14 . V_899 ;
const unsigned long * V_238 = V_462 ;
const int V_914 = V_461 ;
F_156 () ;
F_75 ( V_896 ) ;
for ( V_77 = 0 ; V_77 < V_914 ; V_77 ++ ) {
V_9 = V_238 [ V_77 ] ;
switch ( F_520 ( V_9 ) ) {
case V_911 :
V_913 = F_97 ( V_9 ) ;
break;
case V_908 :
V_913 = F_98 ( V_9 ) ;
break;
case V_912 :
V_913 = F_99 ( V_9 ) ;
break;
case V_909 :
V_913 = F_96 ( V_9 ) ;
break;
default:
F_454 ( 1 ) ;
continue;
}
F_523 ( & V_75 -> V_8 , V_9 , V_913 ) ;
}
F_71 ( V_896 ) ;
F_75 ( V_75 -> V_92 -> V_89 ) ;
F_157 () ;
}
static void F_524 ( struct V_6 * V_75 )
{
const unsigned long * V_238 [] = {
V_462 ,
V_466
} ;
const int V_915 [] = {
V_461 ,
V_465
} ;
int V_77 , V_916 ;
unsigned long V_9 ;
T_3 V_913 = 0 ;
struct V_89 * V_896 = V_75 -> V_14 . V_899 ;
F_75 ( V_896 ) ;
for ( V_916 = 0 ; V_916 < F_10 ( V_238 ) ; V_916 ++ ) {
for ( V_77 = 0 ; V_77 < V_915 [ V_916 ] ; V_77 ++ ) {
V_9 = V_238 [ V_916 ] [ V_77 ] ;
F_522 ( & V_75 -> V_8 , V_9 , & V_913 ) ;
switch ( F_520 ( V_9 ) ) {
case V_911 :
F_105 ( V_9 , ( T_4 ) V_913 ) ;
break;
case V_908 :
F_106 ( V_9 , ( T_2 ) V_913 ) ;
break;
case V_912 :
F_107 ( V_9 , ( T_3 ) V_913 ) ;
break;
case V_909 :
F_103 ( V_9 , ( long ) V_913 ) ;
break;
default:
F_454 ( 1 ) ;
break;
}
}
}
F_71 ( V_896 ) ;
F_75 ( V_75 -> V_92 -> V_89 ) ;
}
static int F_525 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( V_75 -> V_14 . V_853 == - 1ull ) {
F_497 ( V_8 ) ;
F_179 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_526 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_913 ;
unsigned long V_752 = F_96 ( V_263 ) ;
T_2 V_874 = F_98 ( V_887 ) ;
T_5 V_83 = 0 ;
if ( ! F_511 ( V_8 ) ||
! F_525 ( V_8 ) )
return 1 ;
V_9 = F_391 ( V_8 , ( ( ( V_874 ) >> 28 ) & 0xf ) ) ;
if ( F_522 ( V_8 , V_9 , & V_913 ) < 0 ) {
F_498 ( V_8 , V_917 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
if ( V_874 & ( 1u << 10 ) ) {
F_527 ( V_8 , ( ( ( V_874 ) >> 3 ) & 0xf ) ,
V_913 ) ;
} else {
if ( F_500 ( V_8 , V_752 ,
V_874 , & V_83 ) )
return 1 ;
F_528 ( & V_8 -> V_118 . V_888 , V_83 ,
& V_913 , ( F_144 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_496 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_529 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_83 ;
unsigned long V_752 = F_96 ( V_263 ) ;
T_2 V_874 = F_98 ( V_887 ) ;
T_3 V_913 = 0 ;
struct V_884 V_885 ;
if ( ! F_511 ( V_8 ) ||
! F_525 ( V_8 ) )
return 1 ;
if ( V_874 & ( 1u << 10 ) )
V_913 = F_391 ( V_8 ,
( ( ( V_874 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_500 ( V_8 , V_752 ,
V_874 , & V_83 ) )
return 1 ;
if ( F_503 ( & V_8 -> V_118 . V_888 , V_83 ,
& V_913 , ( F_530 ( V_8 ) ? 8 : 4 ) , & V_885 ) ) {
F_504 ( V_8 , & V_885 ) ;
return 1 ;
}
}
V_9 = F_391 ( V_8 , ( ( ( V_874 ) >> 28 ) & 0xf ) ) ;
if ( F_521 ( V_9 ) ) {
F_498 ( V_8 ,
V_918 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
if ( F_523 ( V_8 , V_9 , V_913 ) < 0 ) {
F_498 ( V_8 , V_917 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
F_496 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_531 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_1 V_852 ;
T_2 V_627 ;
if ( ! F_511 ( V_8 ) )
return 1 ;
if ( F_501 ( V_8 , V_894 , & V_852 ) )
return 1 ;
if ( V_75 -> V_14 . V_853 != V_852 ) {
struct V_13 * V_919 ;
struct V_16 * V_16 ;
V_16 = F_12 ( V_8 , V_852 ) ;
if ( V_16 == NULL ) {
F_497 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
V_919 = F_506 ( V_16 ) ;
if ( V_919 -> V_451 != V_374 ) {
F_507 ( V_16 ) ;
F_17 ( V_16 ) ;
F_498 ( V_8 ,
V_920 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
F_512 ( V_75 ) ;
V_75 -> V_14 . V_853 = V_852 ;
V_75 -> V_14 . V_15 = V_919 ;
V_75 -> V_14 . V_904 = V_16 ;
if ( V_636 ) {
V_627 = F_98 ( V_641 ) ;
V_627 |= V_68 ;
F_106 ( V_641 , V_627 ) ;
F_107 ( V_639 ,
F_72 ( V_75 -> V_14 . V_899 ) ) ;
V_75 -> V_14 . V_903 = true ;
}
}
F_496 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_532 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_96 ( V_263 ) ;
T_2 V_874 = F_98 ( V_887 ) ;
T_5 V_921 ;
struct V_884 V_885 ;
if ( ! F_511 ( V_8 ) )
return 1 ;
if ( F_500 ( V_8 , V_752 ,
V_874 , & V_921 ) )
return 1 ;
if ( F_528 ( & V_8 -> V_118 . V_888 , V_921 ,
( void * ) & F_6 ( V_8 ) -> V_14 . V_853 ,
sizeof( T_3 ) , & V_885 ) ) {
F_504 ( V_8 , & V_885 ) ;
return 1 ;
}
F_496 ( V_8 ) ;
F_179 ( V_8 ) ;
return 1 ;
}
static int F_533 ( struct V_7 * V_8 )
{
T_2 V_874 , V_922 ;
unsigned long type ;
T_5 V_83 ;
struct V_884 V_885 ;
struct {
T_3 V_86 , V_87 ;
} V_85 ;
if ( ! ( V_361 & V_56 ) ||
! ( V_362 & V_363 ) ) {
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
if ( ! F_511 ( V_8 ) )
return 1 ;
if ( ! F_168 ( V_8 , V_526 ) ) {
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
V_874 = F_98 ( V_887 ) ;
type = F_391 ( V_8 , ( V_874 >> 28 ) & 0xf ) ;
V_922 = ( V_362 >> V_923 ) & 6 ;
if ( ! ( V_922 & ( 1UL << type ) ) ) {
F_498 ( V_8 ,
V_924 ) ;
return 1 ;
}
if ( F_500 ( V_8 , F_96 ( V_263 ) ,
V_874 , & V_83 ) )
return 1 ;
if ( F_503 ( & V_8 -> V_118 . V_888 , V_83 , & V_85 ,
sizeof( V_85 ) , & V_885 ) ) {
F_504 ( V_8 , & V_885 ) ;
return 1 ;
}
switch ( type ) {
case V_102 :
F_534 ( V_8 ) ;
F_160 ( V_225 , V_8 ) ;
F_496 ( V_8 ) ;
break;
default:
F_311 ( 1 ) ;
break;
}
F_179 ( V_8 ) ;
return 1 ;
}
static int F_535 ( struct V_7 * V_8 )
{
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
static bool F_536 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
unsigned long V_752 ;
T_1 V_925 , V_926 ;
unsigned int V_754 ;
int V_449 ;
T_6 V_927 ;
if ( ! F_59 ( V_13 , V_353 ) )
return F_59 ( V_13 , V_352 ) ;
V_752 = F_96 ( V_263 ) ;
V_754 = V_752 >> 16 ;
V_449 = ( V_752 & 7 ) + 1 ;
V_926 = ( T_1 ) - 1 ;
V_927 = - 1 ;
while ( V_449 > 0 ) {
if ( V_754 < 0x8000 )
V_925 = V_13 -> V_928 ;
else if ( V_754 < 0x10000 )
V_925 = V_13 -> V_929 ;
else
return 1 ;
V_925 += ( V_754 & 0x7fff ) / 8 ;
if ( V_926 != V_925 )
if ( F_537 ( V_8 -> V_18 , V_925 , & V_927 , 1 ) )
return 1 ;
if ( V_927 & ( 1 << ( V_754 & 7 ) ) )
return 1 ;
V_754 ++ ;
V_449 -- ;
V_926 = V_925 ;
}
return 0 ;
}
static bool F_538 ( struct V_7 * V_8 ,
struct V_13 * V_13 , T_2 V_261 )
{
T_2 V_371 = V_8 -> V_118 . V_419 [ V_770 ] ;
T_1 V_925 ;
if ( ! F_59 ( V_13 , V_32 ) )
return 1 ;
V_925 = V_13 -> V_279 ;
if ( V_261 == V_930 )
V_925 += 2048 ;
if ( V_371 >= 0xc0000000 ) {
V_371 -= 0xc0000000 ;
V_925 += 1024 ;
}
if ( V_371 < 1024 * 8 ) {
unsigned char V_927 ;
if ( F_537 ( V_8 -> V_18 , V_925 + V_371 / 8 , & V_927 , 1 ) )
return 1 ;
return 1 & ( V_927 >> ( V_371 & 7 ) ) ;
} else
return 1 ;
}
static bool F_539 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
unsigned long V_752 = F_96 ( V_263 ) ;
int V_759 = V_752 & 15 ;
int V_417 = ( V_752 >> 8 ) & 15 ;
unsigned long V_108 = F_391 ( V_8 , V_417 ) ;
switch ( ( V_752 >> 4 ) & 3 ) {
case 0 :
switch ( V_759 ) {
case 0 :
if ( V_13 -> V_236 &
( V_108 ^ V_13 -> V_240 ) )
return 1 ;
break;
case 3 :
if ( ( V_13 -> V_931 >= 1 &&
V_13 -> V_932 == V_108 ) ||
( V_13 -> V_931 >= 2 &&
V_13 -> V_933 == V_108 ) ||
( V_13 -> V_931 >= 3 &&
V_13 -> V_934 == V_108 ) ||
( V_13 -> V_931 >= 4 &&
V_13 -> V_935 == V_108 ) )
return 0 ;
if ( F_59 ( V_13 , V_347 ) )
return 1 ;
break;
case 4 :
if ( V_13 -> V_242 &
( V_13 -> V_243 ^ V_108 ) )
return 1 ;
break;
case 8 :
if ( F_59 ( V_13 , V_349 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_13 -> V_236 & V_233 ) &&
( V_13 -> V_240 & V_233 ) )
return 1 ;
break;
case 1 :
switch ( V_759 ) {
case 3 :
if ( V_13 -> V_70 &
V_348 )
return 1 ;
break;
case 8 :
if ( V_13 -> V_70 &
V_350 )
return 1 ;
break;
}
break;
case 3 :
if ( V_13 -> V_236 & 0xe &
( V_108 ^ V_13 -> V_240 ) )
return 1 ;
if ( ( V_13 -> V_236 & 0x1 ) &&
! ( V_13 -> V_240 & 0x1 ) &&
( V_108 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_540 ( struct V_7 * V_8 )
{
T_2 V_20 = F_98 ( V_262 ) ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_13 * V_13 = F_11 ( V_8 ) ;
T_2 V_261 = V_75 -> V_261 ;
F_541 ( F_180 ( V_8 ) , V_261 ,
F_96 ( V_263 ) ,
V_75 -> V_728 ,
V_20 ,
F_98 ( V_731 ) ,
V_936 ) ;
if ( V_75 -> V_14 . V_702 )
return 0 ;
if ( F_104 ( V_75 -> V_937 ) ) {
F_542 ( L_30 , V_502 ,
F_98 ( V_106 ) ) ;
return 1 ;
}
switch ( V_261 ) {
case V_938 :
if ( ! F_66 ( V_20 ) )
return 0 ;
else if ( F_19 ( V_20 ) )
return V_103 ;
else if ( F_20 ( V_20 ) &&
! ( V_13 -> V_239 & V_233 ) )
return 0 ;
return V_13 -> V_141 &
( 1u << ( V_20 & V_22 ) ) ;
case V_939 :
return 0 ;
case V_940 :
return 1 ;
case V_941 :
return F_59 ( V_13 , V_342 ) ;
case V_942 :
return F_59 ( V_13 , V_343 ) ;
case V_943 :
return 1 ;
case V_944 :
if ( F_437 ( V_8 , V_771 ) == 0xa )
return 0 ;
return 1 ;
case V_945 :
return F_59 ( V_13 , V_344 ) ;
case V_946 :
return 1 ;
case V_947 :
return F_59 ( V_13 , V_345 ) ;
case V_948 :
return F_59 ( V_13 , V_355 ) ;
case V_949 :
return F_59 ( V_13 , V_356 ) ;
case V_950 : case V_891 :
case V_951 : case V_894 :
case V_952 : case V_953 :
case V_954 : case V_955 :
case V_956 : case V_889 :
case V_957 : case V_958 :
return 1 ;
case V_959 :
return F_539 ( V_8 , V_13 ) ;
case V_960 :
return F_59 ( V_13 , V_351 ) ;
case V_961 :
return F_536 ( V_8 , V_13 ) ;
case V_962 :
case V_930 :
return F_538 ( V_8 , V_13 , V_261 ) ;
case V_963 :
return 1 ;
case V_964 :
return F_59 ( V_13 , V_346 ) ;
case V_965 :
return F_59 ( V_13 , V_354 ) ;
case V_966 :
return F_59 ( V_13 , V_357 ) ||
F_60 ( V_13 ,
V_58 ) ;
case V_967 :
return 0 ;
case V_968 :
return F_59 ( V_13 , V_33 ) ;
case V_969 :
return F_60 ( V_13 ,
V_36 ) ;
case V_800 :
return 0 ;
case V_817 :
return 0 ;
case V_970 :
return F_60 ( V_13 , V_64 ) ;
case V_971 :
return 1 ;
case V_972 : case V_973 :
return F_60 ( V_13 , V_74 ) ;
default:
return 1 ;
}
}
static void F_543 ( struct V_7 * V_8 , T_3 * V_974 , T_3 * V_975 )
{
* V_974 = F_96 ( V_263 ) ;
* V_975 = F_98 ( V_262 ) ;
}
static int F_544 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_2 V_261 = V_75 -> V_261 ;
T_2 V_976 = V_75 -> V_728 ;
if ( V_75 -> F_253 )
return F_461 ( V_8 ) ;
if ( F_127 ( V_8 ) && F_540 ( V_8 ) ) {
F_183 ( V_8 , V_261 ,
F_98 ( V_262 ) ,
F_96 ( V_263 ) ) ;
return 1 ;
}
if ( V_261 & V_977 ) {
V_8 -> V_721 -> V_261 = V_978 ;
V_8 -> V_721 -> V_979 . V_980
= V_261 ;
return 0 ;
}
if ( F_104 ( V_75 -> V_937 ) ) {
V_8 -> V_721 -> V_261 = V_978 ;
V_8 -> V_721 -> V_979 . V_980
= F_98 ( V_106 ) ;
return 0 ;
}
if ( ( V_976 & V_732 ) &&
( V_261 != V_938 &&
V_261 != V_800 &&
V_261 != V_943 ) ) {
V_8 -> V_721 -> V_261 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_981 ;
V_8 -> V_721 -> V_735 . V_738 = 2 ;
V_8 -> V_721 -> V_735 . V_185 [ 0 ] = V_976 ;
V_8 -> V_721 -> V_735 . V_185 [ 1 ] = V_261 ;
return 0 ;
}
if ( F_104 ( ! F_54 () && V_75 -> V_666 &&
! ( F_127 ( V_8 ) && F_61 (
F_11 ( V_8 ) ) ) ) ) {
if ( F_362 ( V_8 ) ) {
V_75 -> V_666 = 0 ;
} else if ( V_75 -> V_695 > 1000000000LL &&
V_8 -> V_118 . V_982 ) {
F_73 ( V_168 L_31
L_32 ,
V_502 , V_8 -> V_303 ) ;
V_75 -> V_666 = 0 ;
}
}
if ( V_261 < V_983
&& V_984 [ V_261 ] )
return V_984 [ V_261 ] ( V_8 ) ;
else {
F_545 ( 1 , L_33 , V_261 ) ;
F_369 ( V_8 , V_27 ) ;
return 1 ;
}
}
static void V_843 ( struct V_7 * V_8 , int V_985 , int V_986 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
if ( F_127 ( V_8 ) &&
F_59 ( V_13 , V_33 ) )
return;
if ( V_986 == - 1 || V_985 < V_986 ) {
F_106 ( V_682 , 0 ) ;
return;
}
F_106 ( V_682 , V_986 ) ;
}
static void F_546 ( struct V_7 * V_8 , bool V_987 )
{
T_2 V_988 ;
if ( ! F_30 () ||
! F_324 ( V_8 -> V_18 ) )
return;
if ( ! F_26 ( V_8 -> V_18 ) )
return;
V_988 = F_98 ( V_641 ) ;
if ( V_987 ) {
V_988 &= ~ V_36 ;
V_988 |= V_37 ;
} else {
V_988 &= ~ V_37 ;
V_988 |= V_36 ;
}
F_106 ( V_641 , V_988 ) ;
F_190 ( V_8 ) ;
}
static void F_547 ( struct V_7 * V_8 , T_16 V_989 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( ! F_127 ( V_8 ) ||
! F_60 ( V_75 -> V_14 . V_15 ,
V_36 ) )
F_107 ( V_990 , V_989 ) ;
}
static void F_548 ( struct V_18 * V_18 , int V_991 )
{
T_4 V_992 ;
T_6 V_426 ;
if ( ! F_324 ( V_18 ) )
return;
if ( V_991 == - 1 )
V_991 = 0 ;
V_992 = F_97 ( V_646 ) ;
V_426 = V_992 >> 8 ;
if ( V_991 != V_426 ) {
V_992 &= 0xff ;
V_992 |= V_991 << 8 ;
F_105 ( V_646 , V_992 ) ;
}
}
static void F_549 ( int V_4 )
{
T_4 V_992 ;
T_6 V_426 ;
if ( V_4 == - 1 )
V_4 = 0 ;
V_992 = F_97 ( V_646 ) ;
V_426 = ( T_6 ) V_992 & 0xff ;
if ( ( T_6 ) V_4 != V_426 ) {
V_992 &= ~ 0xff ;
V_992 |= ( T_6 ) V_4 ;
F_105 ( V_646 , V_992 ) ;
}
}
static void F_550 ( struct V_7 * V_8 , int V_993 )
{
if ( ! F_127 ( V_8 ) ) {
F_549 ( V_993 ) ;
return;
}
if ( V_993 == - 1 )
return;
if ( F_351 ( V_8 ) )
return;
if ( ! F_376 ( V_8 ) &&
F_362 ( V_8 ) ) {
F_551 ( V_8 , V_993 , false ) ;
F_356 ( V_8 ) ;
}
}
static void F_552 ( struct V_7 * V_8 , T_3 * V_994 )
{
if ( ! F_324 ( V_8 -> V_18 ) )
return;
F_107 ( V_642 , V_994 [ 0 ] ) ;
F_107 ( V_643 , V_994 [ 1 ] ) ;
F_107 ( V_644 , V_994 [ 2 ] ) ;
F_107 ( V_645 , V_994 [ 3 ] ) ;
}
static void F_553 ( struct V_6 * V_75 )
{
T_2 V_729 ;
if ( ! ( V_75 -> V_261 == V_967
|| V_75 -> V_261 == V_938 ) )
return;
V_75 -> V_729 = F_98 ( V_262 ) ;
V_729 = V_75 -> V_729 ;
if ( F_23 ( V_729 ) )
F_370 () ;
if ( ( V_729 & V_21 ) == V_699 &&
( V_729 & V_23 ) ) {
F_554 ( & V_75 -> V_8 ) ;
asm("int $2");
F_555 ( & V_75 -> V_8 ) ;
}
}
static void F_556 ( struct V_7 * V_8 )
{
T_2 V_729 = F_98 ( V_262 ) ;
if ( ( V_729 & ( V_23 | V_21 ) )
== ( V_23 | V_28 ) ) {
unsigned int V_4 ;
unsigned long V_143 ;
T_17 * V_995 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
#ifdef F_100
unsigned long V_278 ;
#endif
V_4 = V_729 & V_22 ;
V_995 = ( T_17 * ) V_75 -> V_618 + V_4 ;
V_143 = F_557 ( * V_995 ) ;
asm volatile(
#ifdef F_100
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
#ifdef F_100
[sp]"=&r"(tmp)
#endif
:
[entry]"r"(entry),
[ss]"i"(__KERNEL_DS),
[cs]"i"(__KERNEL_CS)
);
} else
F_164 () ;
}
static bool F_209 ( void )
{
return ( V_30 . V_452 & V_326 ) &&
( V_30 . V_408 & V_335 ) ;
}
static bool F_65 ( void )
{
return V_30 . V_35 &
V_74 ;
}
static void F_558 ( struct V_6 * V_75 )
{
T_2 V_729 ;
bool V_996 ;
T_6 V_4 ;
bool V_997 ;
V_997 = V_75 -> V_728 & V_732 ;
if ( F_54 () ) {
if ( V_75 -> V_697 )
return;
V_729 = F_98 ( V_262 ) ;
V_996 = ( V_729 & V_801 ) != 0 ;
V_4 = V_729 & V_22 ;
if ( ( V_729 & V_23 ) && V_996 &&
V_4 != V_712 && ! V_997 )
F_109 ( V_253 ,
V_700 ) ;
else
V_75 -> V_697 =
! ( F_98 ( V_253 )
& V_700 ) ;
} else if ( F_104 ( V_75 -> V_666 ) )
V_75 -> V_695 +=
F_559 ( F_560 ( F_561 () , V_75 -> V_998 ) ) ;
}
static void F_562 ( struct V_7 * V_8 ,
T_2 V_728 ,
int V_999 ,
int V_1000 )
{
T_6 V_4 ;
int type ;
bool V_997 ;
V_997 = V_728 & V_732 ;
V_8 -> V_118 . V_789 = false ;
F_449 ( V_8 ) ;
F_448 ( V_8 ) ;
if ( ! V_997 )
return;
F_160 ( V_598 , V_8 ) ;
V_4 = V_728 & V_786 ;
type = V_728 & V_787 ;
switch ( type ) {
case V_699 :
V_8 -> V_118 . V_789 = true ;
F_360 ( V_8 , false ) ;
break;
case V_274 :
V_8 -> V_118 . V_270 = F_98 ( V_999 ) ;
case V_24 :
if ( V_728 & V_790 ) {
T_2 V_760 = F_98 ( V_1000 ) ;
F_563 ( V_8 , V_4 , V_760 ) ;
} else
F_564 ( V_8 , V_4 ) ;
break;
case V_694 :
V_8 -> V_118 . V_270 = F_98 ( V_999 ) ;
case V_28 :
F_551 ( V_8 , V_4 , type == V_694 ) ;
break;
default:
break;
}
}
static void F_565 ( struct V_6 * V_75 )
{
F_562 ( & V_75 -> V_8 , V_75 -> V_728 ,
V_260 ,
V_791 ) ;
}
static void F_566 ( struct V_7 * V_8 )
{
F_562 ( V_8 ,
F_98 ( V_275 ) ,
V_273 ,
V_267 ) ;
F_106 ( V_275 , 0 ) ;
}
static void F_567 ( struct V_6 * V_75 )
{
int V_77 , V_1001 ;
struct V_1002 * V_1003 ;
V_1003 = F_568 ( & V_1001 ) ;
if ( ! V_1003 )
return;
for ( V_77 = 0 ; V_77 < V_1001 ; V_77 ++ )
if ( V_1003 [ V_77 ] . V_156 == V_1003 [ V_77 ] . V_155 )
F_129 ( V_75 , V_1003 [ V_77 ] . V_76 ) ;
else
F_131 ( V_75 , V_1003 [ V_77 ] . V_76 , V_1003 [ V_77 ] . V_155 ,
V_1003 [ V_77 ] . V_156 ) ;
}
static void T_18 F_569 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
unsigned long V_1004 , V_509 ;
if ( F_104 ( ! F_54 () && V_75 -> V_666 ) )
V_75 -> V_998 = F_561 () ;
if ( V_75 -> F_253 )
return;
if ( V_75 -> V_651 ) {
V_75 -> V_651 = false ;
F_106 ( V_1005 , V_75 -> V_650 ) ;
}
if ( V_75 -> V_14 . V_903 ) {
F_524 ( V_75 ) ;
V_75 -> V_14 . V_903 = false ;
}
if ( F_174 ( V_418 , ( unsigned long * ) & V_8 -> V_118 . V_512 ) )
F_103 ( V_420 , V_8 -> V_118 . V_419 [ V_418 ] ) ;
if ( F_174 ( V_421 , ( unsigned long * ) & V_8 -> V_118 . V_512 ) )
F_103 ( V_422 , V_8 -> V_118 . V_419 [ V_421 ] ) ;
V_509 = F_229 () ;
if ( F_104 ( V_509 != V_75 -> V_193 . V_609 ) ) {
F_103 ( V_608 , V_509 ) ;
V_75 -> V_193 . V_609 = V_509 ;
}
if ( V_8 -> V_134 & V_707 )
F_178 ( V_8 , 0 ) ;
F_567 ( V_75 ) ;
V_1004 = F_570 () ;
V_75 -> V_1006 = V_75 -> V_92 -> V_94 ;
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
#ifdef F_100
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
#ifdef F_100
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
#ifdef F_100
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
#ifdef F_100
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_1004 )
F_571 ( V_1004 ) ;
#ifndef F_100
F_151 ( V_204 , V_1007 ) ;
F_151 ( V_206 , V_1007 ) ;
#endif
V_8 -> V_118 . V_119 = ~ ( ( 1 << V_421 ) | ( 1 << V_418 )
| ( 1 << V_247 )
| ( 1 << V_423 )
| ( 1 << V_120 )
| ( 1 << V_507 ) ) ;
V_8 -> V_118 . V_512 = 0 ;
V_75 -> V_728 = F_98 ( V_1008 ) ;
V_75 -> V_92 -> V_94 = 1 ;
V_75 -> V_261 = F_98 ( V_1009 ) ;
F_572 ( V_75 -> V_261 , V_8 , V_936 ) ;
if ( V_75 -> V_14 . V_702 )
F_160 ( V_598 , V_8 ) ;
V_75 -> V_14 . V_702 = 0 ;
F_553 ( V_75 ) ;
F_558 ( V_75 ) ;
F_565 ( V_75 ) ;
}
static void F_573 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_93 ;
if ( V_75 -> V_92 == & V_75 -> V_860 )
return;
V_93 = F_574 () ;
V_75 -> V_92 = & V_75 -> V_860 ;
F_165 ( V_8 ) ;
F_158 ( V_8 , V_93 ) ;
V_8 -> V_93 = V_93 ;
F_575 () ;
}
static void F_576 ( struct V_7 * V_8 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
F_316 ( V_75 ) ;
F_577 ( V_8 ) ;
F_573 ( V_8 ) ;
F_514 ( V_75 ) ;
F_247 ( V_75 -> V_92 ) ;
F_493 ( V_75 -> V_80 ) ;
F_578 ( V_8 ) ;
F_579 ( V_1010 , V_75 ) ;
}
static struct V_7 * F_580 ( struct V_18 * V_18 , unsigned int V_1011 )
{
int V_760 ;
struct V_6 * V_75 = F_581 ( V_1010 , V_459 ) ;
int V_93 ;
if ( ! V_75 )
return F_582 ( - V_467 ) ;
F_312 ( V_75 ) ;
V_760 = F_583 ( & V_75 -> V_8 , V_18 , V_1011 ) ;
if ( V_760 )
goto V_1012;
V_75 -> V_80 = F_492 ( V_448 , V_459 ) ;
F_9 ( F_10 ( V_79 ) * sizeof( V_75 -> V_80 [ 0 ] )
> V_448 ) ;
V_760 = - V_467 ;
if ( ! V_75 -> V_80 ) {
goto V_1013;
}
V_75 -> V_92 = & V_75 -> V_860 ;
V_75 -> V_92 -> V_89 = F_244 () ;
if ( ! V_75 -> V_92 -> V_89 )
goto V_1014;
if ( ! V_223 )
F_159 ( F_72 ( F_86 ( V_222 , F_83 () ) ) ) ;
F_74 ( V_75 -> V_92 ) ;
if ( ! V_223 )
F_166 () ;
V_93 = F_574 () ;
F_158 ( & V_75 -> V_8 , V_93 ) ;
V_75 -> V_8 . V_93 = V_93 ;
V_760 = F_342 ( V_75 ) ;
F_165 ( & V_75 -> V_8 ) ;
F_575 () ;
if ( V_760 )
goto F_245;
if ( F_50 ( V_18 ) ) {
V_760 = F_308 ( V_18 ) ;
if ( V_760 )
goto F_245;
}
if ( V_103 ) {
if ( ! V_18 -> V_118 . V_535 )
V_18 -> V_118 . V_535 =
V_1015 ;
V_760 = F_302 ( V_18 ) ;
if ( V_760 )
goto F_245;
}
V_75 -> V_14 . V_853 = - 1ull ;
V_75 -> V_14 . V_15 = NULL ;
return & V_75 -> V_8 ;
F_245:
F_247 ( V_75 -> V_92 ) ;
V_1014:
F_493 ( V_75 -> V_80 ) ;
V_1013:
F_578 ( & V_75 -> V_8 ) ;
V_1012:
F_316 ( V_75 ) ;
F_579 ( V_1010 , V_75 ) ;
return F_582 ( V_760 ) ;
}
static void T_11 F_584 ( void * V_1016 )
{
struct V_30 V_438 ;
* ( int * ) V_1016 = 0 ;
if ( F_238 ( & V_438 ) < 0 )
* ( int * ) V_1016 = - V_437 ;
if ( memcmp ( & V_30 , & V_438 , sizeof( struct V_30 ) ) != 0 ) {
F_73 ( V_91 L_34 ,
F_585 () ) ;
* ( int * ) V_1016 = - V_437 ;
}
}
static int F_586 ( void )
{
return V_528 + 1 ;
}
static T_3 F_587 ( struct V_7 * V_8 , T_12 V_1017 , bool V_1018 )
{
T_3 V_116 ;
if ( V_1018 )
V_116 = V_1019 << V_1020 ;
else if ( F_588 ( V_8 -> V_18 ) )
V_116 = F_589 ( V_8 , V_1017 ) <<
V_1020 ;
else
V_116 = ( V_1021 << V_1020 )
| V_1022 ;
return V_116 ;
}
static int F_590 ( void )
{
if ( V_103 && ! F_40 () )
return V_1023 ;
else
return V_1024 ;
}
static void F_591 ( struct V_7 * V_8 )
{
struct V_306 * V_307 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_2 V_627 ;
V_75 -> V_290 = false ;
if ( F_187 () ) {
V_627 = F_98 ( V_641 ) ;
if ( V_627 & V_61 ) {
V_307 = F_205 ( V_8 , 0x80000001 , 0 ) ;
if ( V_307 && ( V_307 -> V_1025 & V_69 ( V_1026 ) ) )
V_75 -> V_290 = true ;
else {
V_627 &= ~ V_61 ;
F_106 ( V_641 ,
V_627 ) ;
}
}
}
V_307 = F_205 ( V_8 , 0x7 , 0 ) ;
if ( F_188 () &&
V_307 && ( V_307 -> V_1027 & V_69 ( V_1028 ) ) &&
F_592 ( V_8 ) ) {
V_627 = F_98 ( V_641 ) ;
V_627 |= V_62 ;
F_106 ( V_641 ,
V_627 ) ;
} else {
if ( F_28 () ) {
V_627 = F_98 ( V_641 ) ;
V_627 &= ~ V_62 ;
F_106 ( V_641 ,
V_627 ) ;
}
if ( V_307 )
V_307 -> V_1027 &= ~ V_69 ( V_1028 ) ;
}
}
static void F_593 ( T_2 V_1029 , struct V_306 * V_143 )
{
if ( V_1029 == 1 && V_14 )
V_143 -> V_308 |= V_69 ( V_309 ) ;
}
static void F_594 ( struct V_7 * V_8 ,
struct V_884 * V_1030 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
T_2 V_261 ;
if ( V_1030 -> V_265 & V_733 )
V_261 = V_817 ;
else
V_261 = V_800 ;
F_183 ( V_8 , V_261 , 0 , V_8 -> V_118 . V_752 ) ;
V_13 -> V_1031 = V_1030 -> V_174 ;
}
static unsigned long F_595 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_1032 ;
}
static void F_596 ( struct V_7 * V_8 )
{
F_597 ( V_8 , & V_8 -> V_118 . V_503 ,
V_362 & V_44 ) ;
V_8 -> V_118 . V_503 . V_1033 = F_279 ;
V_8 -> V_118 . V_503 . V_1034 = F_595 ;
V_8 -> V_118 . V_503 . V_1035 = F_594 ;
V_8 -> V_118 . V_511 = & V_8 -> V_118 . V_1036 ;
}
static void F_598 ( struct V_7 * V_8 )
{
V_8 -> V_118 . V_511 = & V_8 -> V_118 . V_503 ;
}
static void F_599 ( struct V_7 * V_8 ,
struct V_884 * V_1030 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
F_454 ( ! F_127 ( V_8 ) ) ;
if ( V_13 -> V_141 & ( 1u << V_25 ) )
F_183 ( V_8 , F_6 ( V_8 ) -> V_261 ,
F_98 ( V_262 ) ,
F_96 ( V_263 ) ) ;
else
F_504 ( V_8 , V_1030 ) ;
}
static bool F_600 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( F_60 ( V_13 , V_36 ) ) {
if ( ! F_505 ( V_13 -> V_1037 ) )
return false ;
if ( V_75 -> V_14 . V_905 )
F_15 ( V_75 -> V_14 . V_905 ) ;
V_75 -> V_14 . V_905 =
F_12 ( V_8 , V_13 -> V_1037 ) ;
}
if ( F_59 ( V_13 , V_33 ) ) {
if ( ! F_505 ( V_13 -> V_1038 ) )
return false ;
if ( V_75 -> V_14 . V_906 )
F_15 ( V_75 -> V_14 . V_906 ) ;
V_75 -> V_14 . V_906 =
F_12 ( V_8 , V_13 -> V_1038 ) ;
if ( ! V_75 -> V_14 . V_906 )
return false ;
}
return true ;
}
static void F_601 ( struct V_7 * V_8 )
{
T_3 V_1039 = F_11 ( V_8 ) -> V_1040 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( V_8 -> V_118 . V_1041 == 0 )
return;
if ( V_1039 <= 1 ) {
F_499 ( & V_75 -> V_14 . V_871 ) ;
return;
}
V_1039 <<= V_367 ;
V_1039 *= 1000000 ;
F_602 ( V_1039 , V_8 -> V_118 . V_1041 ) ;
F_603 ( & V_75 -> V_14 . V_871 ,
F_604 ( V_1039 ) , V_901 ) ;
}
static void F_605 ( struct V_7 * V_8 , struct V_13 * V_13 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
T_2 V_627 ;
F_105 ( V_1042 , V_13 -> V_1043 ) ;
F_105 ( V_670 , V_13 -> V_1044 ) ;
F_105 ( V_1045 , V_13 -> V_1046 ) ;
F_105 ( V_1047 , V_13 -> V_1048 ) ;
F_105 ( V_1049 , V_13 -> V_1050 ) ;
F_105 ( V_1051 , V_13 -> V_1052 ) ;
F_105 ( V_673 , V_13 -> V_1053 ) ;
F_105 ( V_672 , V_13 -> V_1054 ) ;
F_106 ( V_1055 , V_13 -> V_1056 ) ;
F_106 ( V_1057 , V_13 -> V_1058 ) ;
F_106 ( V_1059 , V_13 -> V_1060 ) ;
F_106 ( V_1061 , V_13 -> V_1062 ) ;
F_106 ( V_1063 , V_13 -> V_1064 ) ;
F_106 ( V_1065 , V_13 -> V_1066 ) ;
F_106 ( V_675 , V_13 -> V_1067 ) ;
F_106 ( V_496 , V_13 -> V_1068 ) ;
F_106 ( V_549 , V_13 -> V_1069 ) ;
F_106 ( V_547 , V_13 -> V_1070 ) ;
F_106 ( V_1071 , V_13 -> V_1072 ) ;
F_106 ( V_1073 , V_13 -> V_1074 ) ;
F_106 ( V_1075 , V_13 -> V_1076 ) ;
F_106 ( V_1077 , V_13 -> V_1078 ) ;
F_106 ( V_1079 , V_13 -> V_1080 ) ;
F_106 ( V_1081 , V_13 -> V_1082 ) ;
F_106 ( V_676 , V_13 -> V_1083 ) ;
F_106 ( V_498 , V_13 -> V_1084 ) ;
F_103 ( V_1085 , V_13 -> V_1086 ) ;
F_103 ( V_671 , V_13 -> V_1087 ) ;
F_103 ( V_1088 , V_13 -> V_1089 ) ;
F_103 ( V_1090 , V_13 -> V_1091 ) ;
F_103 ( V_391 , V_13 -> V_1092 ) ;
F_103 ( V_392 , V_13 -> V_1093 ) ;
F_103 ( V_674 , V_13 -> V_1094 ) ;
F_103 ( V_495 , V_13 -> V_1095 ) ;
F_103 ( V_550 , V_13 -> V_1096 ) ;
F_103 ( V_548 , V_13 -> V_1097 ) ;
if ( V_13 -> V_1098 & V_337 ) {
F_406 ( V_8 , 7 , V_13 -> V_1099 ) ;
F_107 ( V_680 , V_13 -> V_1100 ) ;
} else {
F_406 ( V_8 , 7 , V_8 -> V_118 . V_743 ) ;
F_107 ( V_680 , V_75 -> V_14 . V_1101 ) ;
}
F_106 ( V_275 ,
V_13 -> V_1102 ) ;
F_106 ( V_267 ,
V_13 -> V_1103 ) ;
F_106 ( V_273 ,
V_13 -> V_1104 ) ;
F_106 ( V_253 ,
V_13 -> V_1105 ) ;
F_106 ( V_395 , V_13 -> V_1106 ) ;
F_176 ( V_8 , V_13 -> V_1107 ) ;
F_103 ( V_679 ,
V_13 -> V_1108 ) ;
F_103 ( V_398 , V_13 -> V_1109 ) ;
F_103 ( V_397 , V_13 -> V_1110 ) ;
if ( F_64 ( V_13 ) )
F_107 ( V_663 , V_13 -> V_1111 ) ;
F_107 ( V_639 , - 1ull ) ;
V_627 = V_13 -> V_72 ;
V_627 |= V_30 . V_40 ;
V_627 &= ~ ( V_73 |
V_41 ) ;
F_106 ( V_640 , V_627 ) ;
V_75 -> V_14 . V_872 = false ;
if ( F_62 ( V_13 ) )
F_601 ( V_8 ) ;
F_106 ( V_652 ,
V_103 ? V_13 -> V_1112 : 0 ) ;
F_106 ( V_653 ,
V_103 ? V_13 -> V_1113 : 0 ) ;
if ( F_28 () ) {
V_627 = F_339 ( V_75 ) ;
if ( ! V_75 -> V_290 )
V_627 &= ~ V_61 ;
V_627 &= ~ ( V_36 |
V_39 |
V_38 ) ;
if ( F_59 ( V_13 ,
V_34 ) )
V_627 |= V_13 -> V_71 ;
if ( V_627 & V_36 ) {
if ( ! V_75 -> V_14 . V_905 )
V_627 &=
~ V_36 ;
else
F_107 ( V_990 ,
F_606 ( V_75 -> V_14 . V_905 ) ) ;
} else if ( F_50 ( V_75 -> V_8 . V_18 ) ) {
V_627 |=
V_36 ;
F_607 ( V_8 ) ;
}
F_106 ( V_641 , V_627 ) ;
}
F_332 ( V_75 ) ;
V_75 -> V_1114 = 0 ;
V_627 = F_338 ( V_75 ) ;
V_627 &= ~ V_342 ;
V_627 &= ~ V_343 ;
V_627 &= ~ V_33 ;
V_627 |= V_13 -> V_70 ;
if ( V_627 & V_33 ) {
F_107 ( V_681 ,
F_606 ( V_75 -> V_14 . V_906 ) ) ;
F_106 ( V_682 , V_13 -> V_1115 ) ;
}
V_627 &= ~ V_32 ;
V_627 &= ~ V_353 ;
V_627 |= V_352 ;
F_106 ( V_520 , V_627 ) ;
F_126 ( V_8 ) ;
V_8 -> V_118 . V_235 &= ~ V_13 -> V_236 ;
F_103 ( V_237 , ~ V_8 -> V_118 . V_235 ) ;
F_106 ( V_111 , V_30 . V_452 ) ;
F_110 ( V_75 ,
( V_13 -> V_1098 & ~ V_148 &
~ V_333 ) |
( V_30 . V_408 & ~ V_333 ) ) ;
if ( V_13 -> V_1098 & V_334 ) {
F_107 ( V_409 , V_13 -> V_1116 ) ;
V_8 -> V_118 . V_410 = V_13 -> V_1116 ;
} else if ( V_30 . V_408 & V_334 )
F_107 ( V_409 , V_75 -> V_8 . V_118 . V_410 ) ;
F_336 ( V_75 ) ;
if ( V_13 -> V_1098 & V_335 )
F_107 ( V_399 , V_13 -> V_1117 ) ;
if ( V_13 -> V_70 & V_302 )
F_107 ( V_294 ,
V_75 -> V_14 . V_295 + V_13 -> V_293 ) ;
else
F_107 ( V_294 , V_75 -> V_14 . V_295 ) ;
if ( V_589 ) {
F_105 ( V_684 , V_75 -> V_53 ) ;
F_267 ( V_8 ) ;
}
if ( F_63 ( V_13 ) ) {
F_608 ( V_8 ) ;
F_596 ( V_8 ) ;
}
if ( V_13 -> V_1098 & V_148 )
V_8 -> V_118 . V_179 = V_13 -> V_1118 ;
else if ( V_13 -> V_1098 & V_333 )
V_8 -> V_118 . V_179 |= ( V_182 | V_183 ) ;
else
V_8 -> V_118 . V_179 &= ~ ( V_182 | V_183 ) ;
F_263 ( V_8 , V_8 -> V_118 . V_179 ) ;
F_278 ( V_8 , V_13 -> V_239 ) ;
F_103 ( V_244 , F_169 ( V_13 ) ) ;
F_276 ( V_8 , V_13 -> V_241 ) ;
F_103 ( V_484 , F_170 ( V_13 ) ) ;
F_394 ( V_8 , V_13 -> V_533 ) ;
F_262 ( V_8 ) ;
if ( ! V_103 )
V_8 -> V_118 . V_511 -> V_1035 = F_599 ;
if ( V_103 ) {
F_107 ( V_513 , V_13 -> V_1119 ) ;
F_107 ( V_515 , V_13 -> V_1120 ) ;
F_107 ( V_516 , V_13 -> V_1121 ) ;
F_107 ( V_517 , V_13 -> V_1122 ) ;
}
F_396 ( V_8 , V_418 , V_13 -> V_1123 ) ;
F_396 ( V_8 , V_421 , V_13 -> V_1124 ) ;
}
static int F_518 ( struct V_7 * V_8 , bool V_1125 )
{
struct V_13 * V_13 ;
struct V_6 * V_75 = F_6 ( V_8 ) ;
int V_93 ;
struct V_92 * V_856 ;
bool V_1126 ;
if ( ! F_511 ( V_8 ) ||
! F_525 ( V_8 ) )
return 1 ;
F_179 ( V_8 ) ;
V_13 = F_11 ( V_8 ) ;
if ( V_636 )
F_513 ( V_75 ) ;
if ( V_13 -> V_907 == V_1125 ) {
F_498 ( V_8 ,
V_1125 ? V_1127
: V_1128 ) ;
return 1 ;
}
if ( V_13 -> V_1129 != V_678 &&
V_13 -> V_1129 != V_1130 ) {
F_498 ( V_8 , V_1131 ) ;
return 1 ;
}
if ( ( V_13 -> V_70 & V_32 ) &&
! F_505 ( V_13 -> V_279 ) ) {
F_498 ( V_8 , V_1131 ) ;
return 1 ;
}
if ( ! F_600 ( V_8 , V_13 ) ) {
F_498 ( V_8 , V_1131 ) ;
return 1 ;
}
if ( V_13 -> V_1132 > 0 ||
V_13 -> V_1133 > 0 ||
V_13 -> V_1134 > 0 ) {
F_609 ( L_35 ,
V_502 ) ;
F_498 ( V_8 , V_1131 ) ;
return 1 ;
}
if ( ! F_210 ( V_13 -> V_70 ,
V_358 ,
V_340 ) ||
! F_210 ( V_13 -> V_71 ,
V_360 , V_361 ) ||
! F_210 ( V_13 -> V_72 ,
V_311 , V_312 ) ||
! F_210 ( V_13 -> V_688 ,
V_327 ,
V_318 ) ||
! F_210 ( V_13 -> V_1098 ,
V_336 ,
V_331 ) )
{
F_498 ( V_8 , V_1131 ) ;
return 1 ;
}
if ( ( ( V_13 -> V_1135 & F_213 ) != F_213 ) ||
( ( V_13 -> V_1136 & F_214 ) != F_214 ) ) {
F_498 ( V_8 ,
V_1137 ) ;
return 1 ;
}
if ( ! F_384 ( V_13 , V_13 -> V_239 ) ||
( ( V_13 -> V_241 & F_214 ) != F_214 ) ) {
F_610 ( V_8 , V_13 ,
V_963 , V_1138 ) ;
return 1 ;
}
if ( V_13 -> V_1139 != - 1ull ) {
F_610 ( V_8 , V_13 ,
V_963 , V_1140 ) ;
return 1 ;
}
if ( V_13 -> V_1098 & V_148 ) {
V_1126 = ( V_13 -> V_1098 & V_333 ) != 0 ;
if ( ! F_611 ( V_8 , V_13 -> V_1118 ) ||
V_1126 != ! ! ( V_13 -> V_1118 & V_182 ) ||
( ( V_13 -> V_239 & V_519 ) &&
V_1126 != ! ! ( V_13 -> V_1118 & V_183 ) ) ) {
F_610 ( V_8 , V_13 ,
V_963 , V_1138 ) ;
return 1 ;
}
}
if ( V_13 -> V_688 & V_149 ) {
V_1126 = ( V_13 -> V_688 &
V_320 ) != 0 ;
if ( ! F_611 ( V_8 , V_13 -> V_1141 ) ||
V_1126 != ! ! ( V_13 -> V_1141 & V_182 ) ||
V_1126 != ! ! ( V_13 -> V_1141 & V_183 ) ) {
F_610 ( V_8 , V_13 ,
V_963 , V_1138 ) ;
return 1 ;
}
}
V_856 = F_489 ( V_75 ) ;
if ( ! V_856 )
return - V_467 ;
F_612 ( V_8 ) ;
V_75 -> V_14 . V_295 = F_99 ( V_294 ) ;
if ( ! ( V_13 -> V_1098 & V_337 ) )
V_75 -> V_14 . V_1101 = F_99 ( V_680 ) ;
V_93 = F_574 () ;
V_75 -> V_92 = V_856 ;
F_165 ( V_8 ) ;
F_158 ( V_8 , V_93 ) ;
V_8 -> V_93 = V_93 ;
F_575 () ;
F_120 ( V_75 ) ;
V_13 -> V_907 = 1 ;
F_605 ( V_8 , V_13 ) ;
if ( V_13 -> V_1129 == V_1130 )
return F_368 ( V_8 ) ;
V_75 -> V_14 . V_702 = 1 ;
return 1 ;
}
static inline unsigned long
F_613 ( struct V_7 * V_8 , struct V_13 * V_13 )
{
return
( F_96 ( V_232 ) & V_8 -> V_118 . V_235 ) |
( V_13 -> V_239 & V_13 -> V_236 ) |
( F_96 ( V_244 ) & ~ ( V_13 -> V_236 |
V_8 -> V_118 . V_235 ) ) ;
}
static inline unsigned long
F_614 ( struct V_7 * V_8 , struct V_13 * V_13 )
{
return
( F_96 ( V_482 ) & V_8 -> V_118 . V_508 ) |
( V_13 -> V_241 & V_13 -> V_242 ) |
( F_96 ( V_484 ) & ~ ( V_13 -> V_242 |
V_8 -> V_118 . V_508 ) ) ;
}
static void F_615 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
T_2 V_1142 ;
unsigned int V_154 ;
if ( V_8 -> V_118 . V_747 . V_1143 && V_8 -> V_118 . V_747 . V_266 ) {
V_154 = V_8 -> V_118 . V_747 . V_154 ;
V_1142 = V_154 | V_732 ;
if ( F_185 ( V_154 ) ) {
V_13 -> V_1144 =
V_8 -> V_118 . V_270 ;
V_1142 |= V_274 ;
} else
V_1142 |= V_24 ;
if ( V_8 -> V_118 . V_747 . V_264 ) {
V_1142 |= V_790 ;
V_13 -> V_1145 =
V_8 -> V_118 . V_747 . V_265 ;
}
V_13 -> V_1146 = V_1142 ;
} else if ( V_8 -> V_118 . V_789 ) {
V_13 -> V_1146 =
V_699 | V_23 | V_698 ;
} else if ( V_8 -> V_118 . V_691 . V_1143 ) {
V_154 = V_8 -> V_118 . V_691 . V_154 ;
V_1142 = V_154 | V_732 ;
if ( V_8 -> V_118 . V_691 . V_693 ) {
V_1142 |= V_694 ;
V_13 -> V_1104 =
V_8 -> V_118 . V_270 ;
} else
V_1142 |= V_28 ;
V_13 -> V_1146 = V_1142 ;
}
}
static int F_616 ( struct V_7 * V_8 , bool V_1147 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
if ( F_62 ( F_11 ( V_8 ) ) &&
V_75 -> V_14 . V_872 ) {
if ( V_75 -> V_14 . V_702 )
return - V_429 ;
F_183 ( V_8 , V_1148 , 0 , 0 ) ;
return 0 ;
}
if ( V_8 -> V_118 . V_982 && F_353 ( V_8 ) ) {
if ( V_75 -> V_14 . V_702 ||
V_8 -> V_118 . V_691 . V_1143 )
return - V_429 ;
F_183 ( V_8 , V_938 ,
V_698 | V_699 |
V_23 , 0 ) ;
V_8 -> V_118 . V_982 = 0 ;
F_360 ( V_8 , true ) ;
return 0 ;
}
if ( ( F_424 ( V_8 ) || V_1147 ) &&
F_351 ( V_8 ) ) {
if ( V_75 -> V_14 . V_702 )
return - V_429 ;
F_183 ( V_8 , V_939 , 0 , 0 ) ;
}
return 0 ;
}
static T_2 F_617 ( struct V_7 * V_8 )
{
T_19 V_1149 =
F_618 ( & F_6 ( V_8 ) -> V_14 . V_871 ) ;
T_3 V_105 ;
if ( F_559 ( V_1149 ) <= 0 )
return 0 ;
V_105 = F_559 ( V_1149 ) * V_8 -> V_118 . V_1041 ;
F_602 ( V_105 , 1000000 ) ;
return V_105 >> V_367 ;
}
static void F_619 ( struct V_7 * V_8 , struct V_13 * V_13 ,
T_2 V_261 , T_2 V_729 ,
unsigned long V_752 )
{
V_13 -> V_239 = F_613 ( V_8 , V_13 ) ;
V_13 -> V_241 = F_614 ( V_8 , V_13 ) ;
V_13 -> V_1123 = F_437 ( V_8 , V_418 ) ;
V_13 -> V_1124 = F_437 ( V_8 , V_421 ) ;
V_13 -> V_1107 = F_96 ( V_248 ) ;
V_13 -> V_1043 = F_97 ( V_1042 ) ;
V_13 -> V_1044 = F_97 ( V_670 ) ;
V_13 -> V_1046 = F_97 ( V_1045 ) ;
V_13 -> V_1048 = F_97 ( V_1047 ) ;
V_13 -> V_1050 = F_97 ( V_1049 ) ;
V_13 -> V_1052 = F_97 ( V_1051 ) ;
V_13 -> V_1053 = F_97 ( V_673 ) ;
V_13 -> V_1054 = F_97 ( V_672 ) ;
V_13 -> V_1056 = F_98 ( V_1055 ) ;
V_13 -> V_1058 = F_98 ( V_1057 ) ;
V_13 -> V_1060 = F_98 ( V_1059 ) ;
V_13 -> V_1062 = F_98 ( V_1061 ) ;
V_13 -> V_1064 = F_98 ( V_1063 ) ;
V_13 -> V_1066 = F_98 ( V_1065 ) ;
V_13 -> V_1067 = F_98 ( V_675 ) ;
V_13 -> V_1068 = F_98 ( V_496 ) ;
V_13 -> V_1069 = F_98 ( V_549 ) ;
V_13 -> V_1070 = F_98 ( V_547 ) ;
V_13 -> V_1072 = F_98 ( V_1071 ) ;
V_13 -> V_1074 = F_98 ( V_1073 ) ;
V_13 -> V_1076 = F_98 ( V_1075 ) ;
V_13 -> V_1078 = F_98 ( V_1077 ) ;
V_13 -> V_1080 = F_98 ( V_1079 ) ;
V_13 -> V_1082 = F_98 ( V_1081 ) ;
V_13 -> V_1083 = F_98 ( V_676 ) ;
V_13 -> V_1084 = F_98 ( V_498 ) ;
V_13 -> V_1086 = F_96 ( V_1085 ) ;
V_13 -> V_1087 = F_96 ( V_671 ) ;
V_13 -> V_1089 = F_96 ( V_1088 ) ;
V_13 -> V_1091 = F_96 ( V_1090 ) ;
V_13 -> V_1092 = F_96 ( V_391 ) ;
V_13 -> V_1093 = F_96 ( V_392 ) ;
V_13 -> V_1094 = F_96 ( V_674 ) ;
V_13 -> V_1095 = F_96 ( V_495 ) ;
V_13 -> V_1096 = F_96 ( V_550 ) ;
V_13 -> V_1097 = F_96 ( V_548 ) ;
V_13 -> V_1105 =
F_98 ( V_253 ) ;
V_13 -> V_1108 =
F_96 ( V_679 ) ;
if ( V_8 -> V_118 . V_1150 == V_1151 )
V_13 -> V_1129 = V_1130 ;
else
V_13 -> V_1129 = V_678 ;
if ( F_62 ( V_13 ) ) {
if ( V_13 -> V_688 &
V_324 )
V_13 -> V_1040 =
F_617 ( V_8 ) ;
F_620 ( & F_6 ( V_8 ) -> V_14 . V_871 ) ;
}
if ( V_103 ) {
V_13 -> V_533 = F_99 ( V_506 ) ;
V_13 -> V_1119 = F_99 ( V_513 ) ;
V_13 -> V_1120 = F_99 ( V_515 ) ;
V_13 -> V_1121 = F_99 ( V_516 ) ;
V_13 -> V_1122 = F_99 ( V_517 ) ;
}
V_13 -> V_1098 =
( V_13 -> V_1098 & ~ V_333 ) |
( F_112 ( F_6 ( V_8 ) ) & V_333 ) ;
if ( V_13 -> V_688 & V_328 ) {
F_405 ( V_8 , 7 , ( unsigned long * ) & V_13 -> V_1099 ) ;
V_13 -> V_1100 = F_99 ( V_680 ) ;
}
if ( V_13 -> V_688 & V_322 )
V_13 -> V_1116 = F_99 ( V_409 ) ;
if ( V_13 -> V_688 & V_323 )
V_13 -> V_1118 = V_8 -> V_118 . V_179 ;
V_13 -> V_1106 = F_98 ( V_395 ) ;
V_13 -> V_1109 = F_96 ( V_398 ) ;
V_13 -> V_1110 = F_96 ( V_397 ) ;
if ( F_209 () )
V_13 -> V_1117 = F_99 ( V_399 ) ;
if ( F_64 ( V_13 ) )
V_13 -> V_1111 = F_99 ( V_663 ) ;
V_13 -> V_1152 = V_261 ;
V_13 -> V_752 = V_752 ;
V_13 -> V_1153 = V_729 ;
if ( ( V_13 -> V_1153 &
( V_23 | V_268 ) ) ==
( V_23 | V_268 ) )
V_13 -> V_1154 =
F_98 ( V_731 ) ;
V_13 -> V_1146 = 0 ;
V_13 -> V_1144 = F_98 ( V_260 ) ;
V_13 -> V_874 = F_98 ( V_887 ) ;
if ( ! ( V_13 -> V_1152 & V_977 ) ) {
V_13 -> V_1102 &= ~ V_23 ;
F_615 ( V_8 , V_13 ) ;
}
V_8 -> V_118 . V_789 = false ;
F_449 ( V_8 ) ;
F_448 ( V_8 ) ;
}
static void F_621 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
struct V_469 V_115 ;
if ( V_13 -> V_688 & V_149 )
V_8 -> V_118 . V_179 = V_13 -> V_1141 ;
else if ( V_13 -> V_688 & V_320 )
V_8 -> V_118 . V_179 |= ( V_182 | V_183 ) ;
else
V_8 -> V_118 . V_179 &= ~ ( V_182 | V_183 ) ;
F_263 ( V_8 , V_8 -> V_118 . V_179 ) ;
F_396 ( V_8 , V_418 , V_13 -> V_1114 ) ;
F_396 ( V_8 , V_421 , V_13 -> V_1155 ) ;
F_176 ( V_8 , V_1156 ) ;
F_278 ( V_8 , V_13 -> V_1135 ) ;
F_126 ( V_8 ) ;
V_8 -> V_118 . V_235 = ( V_8 -> V_140 ? V_233 : 0 ) ;
F_103 ( V_237 , ~ V_8 -> V_118 . V_235 ) ;
V_8 -> V_118 . V_508 = ~ F_96 ( V_626 ) ;
F_388 ( V_8 , V_13 -> V_1136 ) ;
F_598 ( V_8 ) ;
F_394 ( V_8 , V_13 -> V_1157 ) ;
F_262 ( V_8 ) ;
if ( ! V_103 )
V_8 -> V_118 . V_511 -> V_1035 = F_504 ;
if ( V_589 ) {
F_267 ( V_8 ) ;
}
F_106 ( V_395 , V_13 -> V_1158 ) ;
F_103 ( V_398 , V_13 -> V_1159 ) ;
F_103 ( V_397 , V_13 -> V_1160 ) ;
F_103 ( V_548 , V_13 -> V_1161 ) ;
F_103 ( V_550 , V_13 -> V_1162 ) ;
if ( V_13 -> V_688 & V_326 )
F_107 ( V_399 , 0 ) ;
if ( V_13 -> V_688 & V_321 ) {
F_107 ( V_409 , V_13 -> V_1163 ) ;
V_8 -> V_118 . V_410 = V_13 -> V_1163 ;
}
if ( V_13 -> V_688 & V_153 )
F_107 ( V_165 ,
V_13 -> V_1164 ) ;
V_115 = (struct V_469 ) {
. V_125 = 0 ,
. V_127 = 0xFFFFFFFF ,
. V_122 = V_13 -> V_1165 ,
. type = 11 ,
. V_490 = 1 ,
. V_189 = 1 ,
. V_488 = 1
} ;
if ( V_13 -> V_688 & V_320 )
V_115 . V_491 = 1 ;
else
V_115 . V_489 = 1 ;
F_256 ( V_8 , & V_115 , V_471 ) ;
V_115 = (struct V_469 ) {
. V_125 = 0 ,
. V_127 = 0xFFFFFFFF ,
. type = 3 ,
. V_490 = 1 ,
. V_189 = 1 ,
. V_489 = 1 ,
. V_488 = 1
} ;
V_115 . V_122 = V_13 -> V_1166 ;
F_256 ( V_8 , & V_115 , V_478 ) ;
V_115 . V_122 = V_13 -> V_1167 ;
F_256 ( V_8 , & V_115 , V_477 ) ;
V_115 . V_122 = V_13 -> V_1168 ;
F_256 ( V_8 , & V_115 , V_472 ) ;
V_115 . V_122 = V_13 -> V_1169 ;
V_115 . V_125 = V_13 -> V_1170 ;
F_256 ( V_8 , & V_115 , V_479 ) ;
V_115 . V_122 = V_13 -> V_1171 ;
V_115 . V_125 = V_13 -> V_1172 ;
F_256 ( V_8 , & V_115 , V_480 ) ;
V_115 = (struct V_469 ) {
. V_125 = V_13 -> V_1173 ,
. V_127 = 0x67 ,
. V_122 = V_13 -> V_1174 ,
. type = 11 ,
. V_490 = 1
} ;
F_256 ( V_8 , & V_115 , V_481 ) ;
F_406 ( V_8 , 7 , 0x400 ) ;
F_107 ( V_680 , 0 ) ;
}
static void F_183 ( struct V_7 * V_8 , T_2 V_261 ,
T_2 V_729 ,
unsigned long V_752 )
{
struct V_6 * V_75 = F_6 ( V_8 ) ;
struct V_13 * V_13 = F_11 ( V_8 ) ;
F_622 ( V_75 -> V_14 . V_702 ) ;
F_577 ( V_8 ) ;
F_619 ( V_8 , V_13 , V_261 , V_729 ,
V_752 ) ;
F_573 ( V_8 ) ;
if ( ( V_261 == V_939 )
&& F_352 ( V_8 ) ) {
int V_690 = F_623 ( V_8 ) ;
F_454 ( V_690 < 0 ) ;
V_13 -> V_1153 = V_690 |
V_23 | V_28 ;
}
F_624 ( V_13 -> V_1152 ,
V_13 -> V_752 ,
V_13 -> V_1146 ,
V_13 -> V_1153 ,
V_13 -> V_1154 ,
V_936 ) ;
F_110 ( V_75 , F_98 ( V_109 ) ) ;
F_115 ( V_75 , F_98 ( V_111 ) ) ;
F_120 ( V_75 ) ;
if ( V_858 == 0 )
F_494 ( V_75 , V_75 -> V_14 . V_853 ) ;
F_621 ( V_8 , V_13 ) ;
F_107 ( V_294 , V_75 -> V_14 . V_295 ) ;
V_75 -> V_1114 = 0 ;
if ( V_75 -> V_14 . V_905 ) {
F_15 ( V_75 -> V_14 . V_905 ) ;
V_75 -> V_14 . V_905 = NULL ;
}
if ( V_75 -> V_14 . V_906 ) {
F_15 ( V_75 -> V_14 . V_906 ) ;
V_75 -> V_14 . V_906 = NULL ;
}
F_607 ( V_8 ) ;
if ( F_104 ( V_75 -> V_937 ) ) {
V_75 -> V_937 = 0 ;
F_498 ( V_8 , F_98 ( V_106 ) ) ;
} else
F_496 ( V_8 ) ;
if ( V_636 )
V_75 -> V_14 . V_903 = true ;
V_8 -> V_118 . V_1150 = V_1175 ;
}
static void F_221 ( struct V_7 * V_8 )
{
if ( F_127 ( V_8 ) )
F_183 ( V_8 , - 1 , 0 , 0 ) ;
F_514 ( F_6 ( V_8 ) ) ;
}
static void F_610 ( struct V_7 * V_8 ,
struct V_13 * V_13 ,
T_2 V_783 , unsigned long V_1176 )
{
F_621 ( V_8 , V_13 ) ;
V_13 -> V_1152 = V_783 | V_977 ;
V_13 -> V_752 = V_1176 ;
F_496 ( V_8 ) ;
if ( V_636 )
F_6 ( V_8 ) -> V_14 . V_903 = true ;
}
static int F_625 ( struct V_7 * V_8 ,
struct V_1177 * V_1178 ,
enum V_1179 V_1180 )
{
return V_1181 ;
}
static void F_626 ( struct V_7 * V_8 , int V_93 )
{
if ( V_630 )
F_470 ( V_8 ) ;
}
static int T_11 F_627 ( void )
{
int V_563 = F_628 ( & V_1182 , sizeof( struct V_6 ) ,
F_629 ( struct V_6 ) , V_1183 ) ;
if ( V_563 )
return V_563 ;
#ifdef F_630
F_631 ( V_1184 ,
F_82 ) ;
#endif
return 0 ;
}
static void T_15 F_632 ( void )
{
#ifdef F_630
F_633 ( V_1184 , NULL ) ;
F_634 () ;
#endif
F_635 () ;
}
