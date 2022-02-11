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
return V_42 . V_51 & V_52 ;
}
static inline bool F_44 ( void )
{
return V_42 . V_51 & V_53 ;
}
static inline bool F_45 ( void )
{
return V_30 . V_35 &
V_54 ;
}
static inline bool F_46 ( void )
{
return V_30 . V_35 &
V_55 ;
}
static inline bool F_47 ( void )
{
return V_30 . V_35 &
V_56 ;
}
static inline bool F_48 ( struct V_18 * V_18 )
{
return V_57 && F_27 ( V_18 ) ;
}
static inline bool F_49 ( void )
{
return V_30 . V_35 &
V_58 ;
}
static inline bool F_50 ( void )
{
return V_30 . V_35 &
V_59 ;
}
static inline bool F_51 ( void )
{
return V_30 . V_35 &
V_60 ;
}
static inline bool F_52 ( void )
{
return V_30 . V_40 & V_61 ;
}
static inline bool F_53 ( void )
{
return V_30 . V_35 &
V_62 ;
}
static inline bool F_54 ( void )
{
T_3 V_63 ;
F_55 ( V_64 , V_63 ) ;
if ( ! ( V_63 & V_65 ) )
return false ;
return V_30 . V_35 &
V_66 ;
}
static inline bool F_56 ( void )
{
return V_30 . V_35 & V_67 ;
}
static inline bool F_57 ( void )
{
return V_57 ;
}
static inline bool F_58 ( struct V_13 * V_13 , T_2 V_68 )
{
return V_13 -> V_69 & V_68 ;
}
static inline bool F_59 ( struct V_13 * V_13 , T_2 V_68 )
{
return ( V_13 -> V_69 &
V_34 ) &&
( V_13 -> V_70 & V_68 ) ;
}
static inline bool F_60 ( struct V_13 * V_13 )
{
return V_13 -> V_71 & V_61 ;
}
static inline bool F_61 ( struct V_13 * V_13 )
{
return V_13 -> V_71 &
V_72 ;
}
static inline int F_62 ( struct V_13 * V_13 )
{
return F_59 ( V_13 , V_54 ) ;
}
static inline bool F_63 ( struct V_13 * V_13 )
{
return F_59 ( V_13 , V_73 ) &&
F_64 () ;
}
static inline bool F_65 ( struct V_13 * V_13 )
{
return F_59 ( V_13 , V_37 ) ;
}
static inline bool F_66 ( struct V_13 * V_13 )
{
return F_59 ( V_13 , V_38 ) ;
}
static inline bool F_67 ( struct V_13 * V_13 )
{
return F_59 ( V_13 , V_39 ) ;
}
static inline bool F_68 ( struct V_13 * V_13 )
{
return V_13 -> V_71 & V_41 ;
}
static inline bool F_69 ( T_2 V_20 )
{
return ( V_20 & ( V_21 | V_23 ) )
== ( V_24 | V_23 ) ;
}
static int F_70 ( struct V_6 * V_74 , T_2 V_75 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_74 -> V_77 ; ++ V_76 )
if ( V_78 [ V_74 -> V_79 [ V_76 ] . V_80 ] == V_75 )
return V_76 ;
return - 1 ;
}
static inline void F_71 ( int V_81 , T_4 V_51 , T_5 V_82 )
{
struct {
T_3 V_51 : 16 ;
T_3 V_83 : 48 ;
T_3 V_82 ;
} V_84 = { V_51 , 0 , V_82 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_72 ( int V_81 , T_3 V_85 , T_1 V_86 )
{
struct {
T_3 V_85 , V_86 ;
} V_84 = { V_85 , V_86 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_87 * F_73 ( struct V_6 * V_74 , T_2 V_75 )
{
int V_76 ;
V_76 = F_70 ( V_74 , V_75 ) ;
if ( V_76 >= 0 )
return & V_74 -> V_79 [ V_76 ] ;
return NULL ;
}
static void F_74 ( struct V_88 * V_88 )
{
T_3 V_89 = F_75 ( V_88 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_76 ( V_90 L_1 ,
V_88 , V_89 ) ;
}
static inline void F_77 ( struct V_91 * V_91 )
{
F_74 ( V_91 -> V_88 ) ;
V_91 -> V_92 = - 1 ;
V_91 -> V_93 = 0 ;
}
static void F_78 ( struct V_88 * V_88 )
{
T_3 V_89 = F_75 ( V_88 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_76 ( V_90 L_2 ,
V_88 , V_89 ) ;
}
static inline void F_79 ( int V_92 )
{
F_80 ( V_92 , & V_94 ) ;
}
static inline void F_81 ( int V_92 )
{
F_82 ( V_92 , & V_94 ) ;
}
static inline int F_83 ( int V_92 )
{
return F_84 ( V_92 , & V_94 ) ;
}
static void F_85 ( void )
{
int V_92 = F_86 () ;
struct V_91 * V_95 ;
if ( ! F_83 ( V_92 ) )
return;
F_87 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_74 ( V_95 -> V_88 ) ;
}
static inline void F_79 ( int V_92 ) { }
static inline void F_81 ( int V_92 ) { }
static void F_88 ( void * V_96 )
{
struct V_91 * V_91 = V_96 ;
int V_92 = F_86 () ;
if ( V_91 -> V_92 != V_92 )
return;
if ( F_89 ( V_97 , V_92 ) == V_91 -> V_88 )
F_89 ( V_97 , V_92 ) = NULL ;
F_81 ( V_92 ) ;
F_90 ( & V_91 -> V_98 ) ;
F_91 () ;
F_77 ( V_91 ) ;
F_79 ( V_92 ) ;
}
static void F_92 ( struct V_91 * V_91 )
{
int V_92 = V_91 -> V_92 ;
if ( V_92 != - 1 )
F_93 ( V_92 ,
F_88 , V_91 , 1 ) ;
}
static inline void F_94 ( struct V_6 * V_74 )
{
if ( V_74 -> V_51 == 0 )
return;
if ( F_43 () )
F_71 ( V_99 , V_74 -> V_51 , 0 ) ;
}
static inline void F_95 ( void )
{
if ( F_44 () )
F_71 ( V_100 , 0 , 0 ) ;
}
static inline void F_96 ( struct V_6 * V_74 )
{
if ( F_43 () )
F_94 ( V_74 ) ;
else
F_95 () ;
}
static inline void F_97 ( void )
{
if ( F_42 () )
F_72 ( V_101 , 0 , 0 ) ;
}
static inline void F_98 ( T_3 V_85 )
{
if ( V_102 ) {
if ( F_41 () )
F_72 ( V_103 , V_85 , 0 ) ;
else
F_97 () ;
}
}
static T_7 unsigned long F_99 ( unsigned long V_9 )
{
unsigned long V_104 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_104 ;
}
static T_7 T_4 F_100 ( unsigned long V_9 )
{
return F_99 ( V_9 ) ;
}
static T_7 T_2 F_101 ( unsigned long V_9 )
{
return F_99 ( V_9 ) ;
}
static T_7 T_3 F_102 ( unsigned long V_9 )
{
#ifdef F_103
return F_99 ( V_9 ) ;
#else
return F_99 ( V_9 ) | ( ( T_3 ) F_99 ( V_9 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_104 ( unsigned long V_9 , unsigned long V_104 )
{
F_76 ( V_90 L_3 ,
V_9 , V_104 , F_101 ( V_105 ) ) ;
F_105 () ;
}
static void F_106 ( unsigned long V_9 , unsigned long V_104 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_107 ( error ) )
F_104 ( V_9 , V_104 ) ;
}
static void F_108 ( unsigned long V_9 , T_4 V_104 )
{
F_106 ( V_9 , V_104 ) ;
}
static void F_109 ( unsigned long V_9 , T_2 V_104 )
{
F_106 ( V_9 , V_104 ) ;
}
static void F_110 ( unsigned long V_9 , T_3 V_104 )
{
F_106 ( V_9 , V_104 ) ;
#ifndef F_103
asm volatile ("");
F_106 ( V_9 + 1 , V_104 >> 32 ) ;
#endif
}
static void F_111 ( unsigned long V_9 , T_2 V_106 )
{
F_106 ( V_9 , F_99 ( V_9 ) & ~ V_106 ) ;
}
static void F_112 ( unsigned long V_9 , T_2 V_106 )
{
F_106 ( V_9 , F_99 ( V_9 ) | V_106 ) ;
}
static inline void F_113 ( struct V_6 * V_74 , T_2 V_107 )
{
F_109 ( V_108 , V_107 ) ;
V_74 -> V_109 = V_107 ;
}
static inline void F_114 ( struct V_6 * V_74 , T_2 V_107 )
{
if ( V_74 -> V_109 != V_107 )
F_113 ( V_74 , V_107 ) ;
}
static inline T_2 F_115 ( struct V_6 * V_74 )
{
return V_74 -> V_109 ;
}
static inline void F_116 ( struct V_6 * V_74 , T_2 V_107 )
{
F_114 ( V_74 , F_115 ( V_74 ) | V_107 ) ;
}
static inline void F_117 ( struct V_6 * V_74 , T_2 V_107 )
{
F_114 ( V_74 , F_115 ( V_74 ) & ~ V_107 ) ;
}
static inline void F_118 ( struct V_6 * V_74 , T_2 V_107 )
{
F_109 ( V_110 , V_107 ) ;
V_74 -> V_111 = V_107 ;
}
static inline void F_119 ( struct V_6 * V_74 , T_2 V_107 )
{
if ( V_74 -> V_111 != V_107 )
F_118 ( V_74 , V_107 ) ;
}
static inline T_2 F_120 ( struct V_6 * V_74 )
{
return V_74 -> V_111 ;
}
static inline void F_121 ( struct V_6 * V_74 , T_2 V_107 )
{
F_119 ( V_74 , F_120 ( V_74 ) | V_107 ) ;
}
static inline void F_122 ( struct V_6 * V_74 , T_2 V_107 )
{
F_119 ( V_74 , F_120 ( V_74 ) & ~ V_107 ) ;
}
static void F_123 ( struct V_6 * V_74 )
{
V_74 -> V_112 . V_113 = 0 ;
}
static bool F_124 ( struct V_6 * V_74 , unsigned V_114 ,
unsigned V_9 )
{
bool V_115 ;
T_2 V_106 = 1 << ( V_114 * V_116 + V_9 ) ;
if ( ! ( V_74 -> V_8 . V_117 . V_118 & ( 1 << V_119 ) ) ) {
V_74 -> V_8 . V_117 . V_118 |= ( 1 << V_119 ) ;
V_74 -> V_112 . V_113 = 0 ;
}
V_115 = V_74 -> V_112 . V_113 & V_106 ;
V_74 -> V_112 . V_113 |= V_106 ;
return V_115 ;
}
static T_4 F_125 ( struct V_6 * V_74 , unsigned V_114 )
{
T_4 * V_120 = & V_74 -> V_112 . V_114 [ V_114 ] . V_121 ;
if ( ! F_124 ( V_74 , V_114 , V_122 ) )
* V_120 = F_100 ( V_123 [ V_114 ] . V_121 ) ;
return * V_120 ;
}
static T_9 F_126 ( struct V_6 * V_74 , unsigned V_114 )
{
T_9 * V_120 = & V_74 -> V_112 . V_114 [ V_114 ] . V_124 ;
if ( ! F_124 ( V_74 , V_114 , V_125 ) )
* V_120 = F_99 ( V_123 [ V_114 ] . V_124 ) ;
return * V_120 ;
}
static T_2 F_127 ( struct V_6 * V_74 , unsigned V_114 )
{
T_2 * V_120 = & V_74 -> V_112 . V_114 [ V_114 ] . V_126 ;
if ( ! F_124 ( V_74 , V_114 , V_127 ) )
* V_120 = F_101 ( V_123 [ V_114 ] . V_126 ) ;
return * V_120 ;
}
static T_2 F_128 ( struct V_6 * V_74 , unsigned V_114 )
{
T_2 * V_120 = & V_74 -> V_112 . V_114 [ V_114 ] . V_128 ;
if ( ! F_124 ( V_74 , V_114 , V_129 ) )
* V_120 = F_101 ( V_123 [ V_114 ] . V_130 ) ;
return * V_120 ;
}
static void F_129 ( struct V_7 * V_8 )
{
T_2 V_131 ;
V_131 = ( 1u << V_25 ) | ( 1u << V_27 ) | ( 1u << V_29 ) |
( 1u << V_26 ) | ( 1u << V_132 ) ;
if ( ( V_8 -> V_133 &
( V_134 | V_135 ) ) ==
( V_134 | V_135 ) )
V_131 |= 1u << V_136 ;
if ( F_6 ( V_8 ) -> V_137 . V_138 )
V_131 = ~ 0 ;
if ( V_102 )
V_131 &= ~ ( 1u << V_25 ) ;
if ( V_8 -> V_139 )
V_131 &= ~ ( 1u << V_26 ) ;
if ( F_130 ( V_8 ) )
V_131 |= F_11 ( V_8 ) -> V_140 ;
F_109 ( V_141 , V_131 ) ;
}
static void F_131 ( struct V_6 * V_74 ,
unsigned long V_142 , unsigned long exit )
{
F_117 ( V_74 , V_142 ) ;
F_122 ( V_74 , exit ) ;
}
static void F_132 ( struct V_6 * V_74 , unsigned V_75 )
{
unsigned V_76 ;
struct V_143 * V_144 = & V_74 -> V_143 ;
switch ( V_75 ) {
case V_145 :
if ( V_146 ) {
F_131 ( V_74 ,
V_147 ,
V_148 ) ;
return;
}
break;
case V_149 :
if ( V_150 ) {
F_131 ( V_74 ,
V_151 ,
V_152 ) ;
return;
}
break;
}
for ( V_76 = 0 ; V_76 < V_144 -> V_153 ; ++ V_76 )
if ( V_144 -> V_154 [ V_76 ] . V_80 == V_75 )
break;
if ( V_76 == V_144 -> V_153 )
return;
-- V_144 -> V_153 ;
V_144 -> V_154 [ V_76 ] = V_144 -> V_154 [ V_144 -> V_153 ] ;
V_144 -> V_155 [ V_76 ] = V_144 -> V_155 [ V_144 -> V_153 ] ;
F_109 ( V_156 , V_144 -> V_153 ) ;
F_109 ( V_157 , V_144 -> V_153 ) ;
}
static void F_133 ( struct V_6 * V_74 ,
unsigned long V_142 , unsigned long exit ,
unsigned long V_158 , unsigned long V_159 ,
T_3 V_160 , T_3 V_161 )
{
F_110 ( V_158 , V_160 ) ;
F_110 ( V_159 , V_161 ) ;
F_116 ( V_74 , V_142 ) ;
F_121 ( V_74 , exit ) ;
}
static void F_134 ( struct V_6 * V_74 , unsigned V_75 ,
T_3 V_160 , T_3 V_161 )
{
unsigned V_76 ;
struct V_143 * V_144 = & V_74 -> V_143 ;
switch ( V_75 ) {
case V_145 :
if ( V_146 ) {
F_133 ( V_74 ,
V_147 ,
V_148 ,
V_162 ,
V_163 ,
V_160 , V_161 ) ;
return;
}
break;
case V_149 :
if ( V_150 ) {
F_133 ( V_74 ,
V_151 ,
V_152 ,
V_164 ,
V_165 ,
V_160 , V_161 ) ;
return;
}
break;
}
for ( V_76 = 0 ; V_76 < V_144 -> V_153 ; ++ V_76 )
if ( V_144 -> V_154 [ V_76 ] . V_80 == V_75 )
break;
if ( V_76 == V_166 ) {
F_135 ( V_167 L_4
L_5 , V_75 ) ;
return;
} else if ( V_76 == V_144 -> V_153 ) {
++ V_144 -> V_153 ;
F_109 ( V_156 , V_144 -> V_153 ) ;
F_109 ( V_157 , V_144 -> V_153 ) ;
}
V_144 -> V_154 [ V_76 ] . V_80 = V_75 ;
V_144 -> V_154 [ V_76 ] . V_104 = V_160 ;
V_144 -> V_155 [ V_76 ] . V_80 = V_75 ;
V_144 -> V_155 [ V_76 ] . V_104 = V_161 ;
}
static void F_136 ( void )
{
struct V_168 * V_169 = F_137 ( & V_170 ) ;
struct V_171 * V_172 ;
V_172 = ( void * ) V_169 -> V_173 ;
V_172 [ V_174 ] . type = 9 ;
F_138 () ;
}
static bool F_139 ( struct V_6 * V_74 , int V_175 )
{
T_3 V_176 ;
T_3 V_177 ;
V_176 = V_74 -> V_8 . V_117 . V_178 ;
V_177 = V_179 | V_180 ;
#ifdef F_103
V_177 |= V_181 | V_182 ;
if ( V_176 & V_181 )
V_177 &= ~ ( T_3 ) V_180 ;
#endif
V_176 &= ~ V_177 ;
V_176 |= V_183 & V_177 ;
V_74 -> V_79 [ V_175 ] . V_184 = V_176 ;
V_74 -> V_79 [ V_175 ] . V_106 = ~ V_177 ;
F_132 ( V_74 , V_145 ) ;
if ( V_146 ||
( V_102 && ( ( V_74 -> V_8 . V_117 . V_178 ^ V_183 ) & V_179 ) ) ) {
V_176 = V_74 -> V_8 . V_117 . V_178 ;
if ( ! ( V_176 & V_181 ) )
V_176 &= ~ V_182 ;
if ( V_176 != V_183 )
F_134 ( V_74 , V_145 ,
V_176 , V_183 ) ;
return false ;
}
return true ;
}
static unsigned long F_140 ( T_4 V_121 )
{
struct V_168 * V_169 = F_137 ( & V_170 ) ;
struct V_171 * V_185 ;
unsigned long V_186 ;
unsigned long V_95 ;
if ( ! ( V_121 & ~ 3 ) )
return 0 ;
V_186 = V_169 -> V_173 ;
if ( V_121 & 4 ) {
T_4 V_187 = F_141 () ;
if ( ! ( V_187 & ~ 3 ) )
return 0 ;
V_186 = F_140 ( V_187 ) ;
}
V_185 = (struct V_171 * ) ( V_186 + ( V_121 & ~ 7 ) ) ;
V_95 = F_142 ( V_185 ) ;
#ifdef F_103
if ( V_185 -> V_188 == 0 && ( V_185 -> type == 2 || V_185 -> type == 9 || V_185 -> type == 11 ) )
V_95 |= ( ( unsigned long ) ( (struct V_189 * ) V_185 ) -> V_190 ) << 32 ;
#endif
return V_95 ;
}
static inline unsigned long F_143 ( void )
{
T_4 V_191 ;
asm("str %0" : "=g"(tr));
return F_140 ( V_191 ) ;
}
static void F_144 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_76 ;
if ( V_74 -> V_192 . V_193 )
return;
V_74 -> V_192 . V_193 = 1 ;
V_74 -> V_192 . V_194 = F_141 () ;
V_74 -> V_192 . V_195 = V_74 -> V_192 . V_194 ;
F_145 ( V_196 , V_74 -> V_192 . V_197 ) ;
if ( ! ( V_74 -> V_192 . V_197 & 7 ) ) {
F_108 ( V_198 , V_74 -> V_192 . V_197 ) ;
V_74 -> V_192 . V_199 = 0 ;
} else {
F_108 ( V_198 , 0 ) ;
V_74 -> V_192 . V_199 = 1 ;
}
F_145 ( V_200 , V_74 -> V_192 . V_201 ) ;
if ( ! ( V_74 -> V_192 . V_201 & 7 ) )
F_108 ( V_202 , V_74 -> V_192 . V_201 ) ;
else {
F_108 ( V_202 , 0 ) ;
V_74 -> V_192 . V_195 = 1 ;
}
#ifdef F_103
F_145 ( V_203 , V_74 -> V_192 . V_204 ) ;
F_145 ( V_205 , V_74 -> V_192 . V_206 ) ;
#endif
#ifdef F_103
F_106 ( V_207 , F_146 ( V_208 ) ) ;
F_106 ( V_209 , F_146 ( V_210 ) ) ;
#else
F_106 ( V_207 , F_140 ( V_74 -> V_192 . V_197 ) ) ;
F_106 ( V_209 , F_140 ( V_74 -> V_192 . V_201 ) ) ;
#endif
#ifdef F_103
F_55 ( V_211 , V_74 -> V_212 ) ;
if ( F_147 ( & V_74 -> V_8 ) )
F_148 ( V_211 , V_74 -> V_213 ) ;
#endif
if ( F_149 ( V_214 ) )
F_55 ( V_215 , V_74 -> V_192 . V_216 ) ;
for ( V_76 = 0 ; V_76 < V_74 -> V_217 ; ++ V_76 )
F_150 ( V_74 -> V_79 [ V_76 ] . V_80 ,
V_74 -> V_79 [ V_76 ] . V_184 ,
V_74 -> V_79 [ V_76 ] . V_106 ) ;
}
static void F_151 ( struct V_6 * V_74 )
{
if ( ! V_74 -> V_192 . V_193 )
return;
++ V_74 -> V_8 . V_218 . V_219 ;
V_74 -> V_192 . V_193 = 0 ;
#ifdef F_103
if ( F_147 ( & V_74 -> V_8 ) )
F_55 ( V_211 , V_74 -> V_213 ) ;
#endif
if ( V_74 -> V_192 . V_195 ) {
F_152 ( V_74 -> V_192 . V_194 ) ;
#ifdef F_103
F_153 ( V_74 -> V_192 . V_201 ) ;
#else
F_154 ( V_200 , V_74 -> V_192 . V_201 ) ;
#endif
}
if ( V_74 -> V_192 . V_199 )
F_154 ( V_196 , V_74 -> V_192 . V_197 ) ;
#ifdef F_103
if ( F_107 ( V_74 -> V_192 . V_204 | V_74 -> V_192 . V_206 ) ) {
F_154 ( V_203 , V_74 -> V_192 . V_204 ) ;
F_154 ( V_205 , V_74 -> V_192 . V_206 ) ;
}
#endif
F_136 () ;
#ifdef F_103
F_148 ( V_211 , V_74 -> V_212 ) ;
#endif
if ( V_74 -> V_192 . V_216 )
F_148 ( V_215 , V_74 -> V_192 . V_216 ) ;
if ( ! F_155 () && ! V_74 -> V_8 . V_220 )
F_156 () ;
F_157 ( F_137 ( & V_170 ) ) ;
}
static void F_158 ( struct V_6 * V_74 )
{
F_159 () ;
F_151 ( V_74 ) ;
F_160 () ;
}
static void F_161 ( struct V_7 * V_8 , int V_92 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_3 V_89 = F_75 ( F_89 ( V_221 , V_92 ) ) ;
if ( ! V_222 )
F_162 ( V_89 ) ;
else if ( V_74 -> V_91 -> V_92 != V_92 )
F_92 ( V_74 -> V_91 ) ;
if ( F_89 ( V_97 , V_92 ) != V_74 -> V_91 -> V_88 ) {
F_89 ( V_97 , V_92 ) = V_74 -> V_91 -> V_88 ;
F_78 ( V_74 -> V_91 -> V_88 ) ;
}
if ( V_74 -> V_91 -> V_92 != V_92 ) {
struct V_168 * V_169 = F_137 ( & V_170 ) ;
unsigned long V_223 ;
F_163 ( V_224 , V_8 ) ;
F_164 () ;
F_81 ( V_92 ) ;
F_165 () ;
F_166 ( & V_74 -> V_91 -> V_98 ,
& F_89 ( V_225 , V_92 ) ) ;
F_79 ( V_92 ) ;
F_167 () ;
F_106 ( V_226 , F_143 () ) ;
F_106 ( V_227 , V_169 -> V_173 ) ;
F_55 ( V_228 , V_223 ) ;
F_106 ( V_229 , V_223 ) ;
V_74 -> V_91 -> V_92 = V_92 ;
}
}
static void F_168 ( struct V_7 * V_8 )
{
F_151 ( F_6 ( V_8 ) ) ;
if ( ! V_222 ) {
F_88 ( F_6 ( V_8 ) -> V_91 ) ;
V_8 -> V_92 = - 1 ;
F_169 () ;
}
}
static void F_170 ( struct V_7 * V_8 )
{
T_9 V_230 ;
if ( V_8 -> V_139 )
return;
V_8 -> V_139 = 1 ;
V_230 = F_99 ( V_231 ) ;
V_230 &= ~ ( V_232 | V_233 ) ;
V_230 |= F_171 ( V_8 , V_232 | V_233 ) ;
F_106 ( V_231 , V_230 ) ;
F_129 ( V_8 ) ;
V_8 -> V_117 . V_234 = V_232 ;
if ( F_130 ( V_8 ) )
V_8 -> V_117 . V_234 &=
~ F_11 ( V_8 ) -> V_235 ;
F_106 ( V_236 , ~ V_8 -> V_117 . V_234 ) ;
}
static inline unsigned long F_172 ( struct V_13 * V_237 )
{
return ( V_237 -> V_238 & ~ V_237 -> V_235 ) |
( V_237 -> V_239 & V_237 -> V_235 ) ;
}
static inline unsigned long F_173 ( struct V_13 * V_237 )
{
return ( V_237 -> V_240 & ~ V_237 -> V_241 ) |
( V_237 -> V_242 & V_237 -> V_241 ) ;
}
static void F_174 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_112 ( V_231 , V_232 | V_233 ) ;
F_129 ( V_8 ) ;
V_8 -> V_117 . V_234 = 0 ;
F_106 ( V_236 , ~ V_8 -> V_117 . V_234 ) ;
if ( F_130 ( V_8 ) ) {
struct V_13 * V_13 = F_11 ( V_8 ) ;
V_13 -> V_238 = ( V_13 -> V_238 & ~ V_232 ) |
( V_8 -> V_117 . V_230 & V_232 ) ;
F_106 ( V_243 , F_172 ( V_13 ) ) ;
} else
F_106 ( V_243 , V_8 -> V_117 . V_230 ) ;
}
static unsigned long F_176 ( struct V_7 * V_8 )
{
unsigned long V_244 , V_245 ;
if ( ! F_177 ( V_246 , ( T_9 * ) & V_8 -> V_117 . V_118 ) ) {
F_178 ( V_246 , ( T_9 * ) & V_8 -> V_117 . V_118 ) ;
V_244 = F_99 ( V_247 ) ;
if ( F_6 ( V_8 ) -> V_137 . V_138 ) {
V_244 &= V_248 ;
V_245 = F_6 ( V_8 ) -> V_137 . V_245 ;
V_244 |= V_245 & ~ V_248 ;
}
F_6 ( V_8 ) -> V_244 = V_244 ;
}
return F_6 ( V_8 ) -> V_244 ;
}
static void F_179 ( struct V_7 * V_8 , unsigned long V_244 )
{
F_178 ( V_246 , ( T_9 * ) & V_8 -> V_117 . V_118 ) ;
F_6 ( V_8 ) -> V_244 = V_244 ;
if ( F_6 ( V_8 ) -> V_137 . V_138 ) {
F_6 ( V_8 ) -> V_137 . V_245 = V_244 ;
V_244 |= V_249 | V_250 ;
}
F_106 ( V_247 , V_244 ) ;
}
static T_2 F_180 ( struct V_7 * V_8 )
{
T_2 V_251 = F_101 ( V_252 ) ;
int V_115 = 0 ;
if ( V_251 & V_253 )
V_115 |= V_254 ;
if ( V_251 & V_255 )
V_115 |= V_256 ;
return V_115 ;
}
static void F_181 ( struct V_7 * V_8 , int V_106 )
{
T_2 V_257 = F_101 ( V_252 ) ;
T_2 V_251 = V_257 ;
V_251 &= ~ ( V_253 | V_255 ) ;
if ( V_106 & V_256 )
V_251 |= V_255 ;
else if ( V_106 & V_254 )
V_251 |= V_253 ;
if ( ( V_251 != V_257 ) )
F_109 ( V_252 , V_251 ) ;
}
static void F_182 ( struct V_7 * V_8 )
{
unsigned long V_258 ;
V_258 = F_183 ( V_8 ) ;
V_258 += F_101 ( V_259 ) ;
F_184 ( V_8 , V_258 ) ;
F_181 ( V_8 , 0 ) ;
}
static int F_185 ( struct V_7 * V_8 , unsigned V_153 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
if ( ! ( V_13 -> V_140 & ( 1u << V_153 ) ) )
return 0 ;
F_186 ( V_8 , F_6 ( V_8 ) -> V_260 ,
F_101 ( V_261 ) ,
F_99 ( V_262 ) ) ;
return 1 ;
}
static void F_187 ( struct V_7 * V_8 , unsigned V_153 ,
bool V_263 , T_2 V_264 ,
bool V_265 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_2 V_20 = V_153 | V_23 ;
if ( ! V_265 && F_130 ( V_8 ) &&
F_185 ( V_8 , V_153 ) )
return;
if ( V_263 ) {
F_109 ( V_266 , V_264 ) ;
V_20 |= V_267 ;
}
if ( V_74 -> V_137 . V_138 ) {
int V_268 = 0 ;
if ( F_188 ( V_153 ) )
V_268 = V_8 -> V_117 . V_269 ;
if ( F_189 ( V_8 , V_153 , V_268 ) != V_270 )
F_163 ( V_271 , V_8 ) ;
return;
}
if ( F_188 ( V_153 ) ) {
F_109 ( V_272 ,
V_74 -> V_8 . V_117 . V_269 ) ;
V_20 |= V_273 ;
} else
V_20 |= V_24 ;
F_109 ( V_274 , V_20 ) ;
}
static bool F_190 ( void )
{
return F_50 () ;
}
static bool F_191 ( void )
{
return F_51 () && V_102 ;
}
static void F_192 ( struct V_6 * V_74 , int V_275 , int V_276 )
{
struct V_87 V_277 ;
V_277 = V_74 -> V_79 [ V_276 ] ;
V_74 -> V_79 [ V_276 ] = V_74 -> V_79 [ V_275 ] ;
V_74 -> V_79 [ V_275 ] = V_277 ;
}
static void F_193 ( struct V_7 * V_8 )
{
unsigned long * V_278 ;
if ( F_130 ( V_8 ) )
V_278 = V_279 ;
else if ( F_27 ( V_8 -> V_18 ) &&
F_194 ( V_8 -> V_117 . V_280 ) ) {
if ( F_147 ( V_8 ) )
V_278 = V_281 ;
else
V_278 = V_282 ;
} else {
if ( F_147 ( V_8 ) )
V_278 = V_283 ;
else
V_278 = V_284 ;
}
F_110 ( V_285 , F_75 ( V_278 ) ) ;
}
static void F_195 ( struct V_6 * V_74 )
{
int V_217 , V_80 ;
V_217 = 0 ;
#ifdef F_103
if ( F_147 ( & V_74 -> V_8 ) ) {
V_80 = F_70 ( V_74 , V_286 ) ;
if ( V_80 >= 0 )
F_192 ( V_74 , V_80 , V_217 ++ ) ;
V_80 = F_70 ( V_74 , V_287 ) ;
if ( V_80 >= 0 )
F_192 ( V_74 , V_80 , V_217 ++ ) ;
V_80 = F_70 ( V_74 , V_288 ) ;
if ( V_80 >= 0 )
F_192 ( V_74 , V_80 , V_217 ++ ) ;
V_80 = F_70 ( V_74 , V_289 ) ;
if ( V_80 >= 0 && V_74 -> V_290 )
F_192 ( V_74 , V_80 , V_217 ++ ) ;
V_80 = F_70 ( V_74 , V_291 ) ;
if ( ( V_80 >= 0 ) && ( V_74 -> V_8 . V_117 . V_178 & V_180 ) )
F_192 ( V_74 , V_80 , V_217 ++ ) ;
}
#endif
V_80 = F_70 ( V_74 , V_145 ) ;
if ( V_80 >= 0 && F_139 ( V_74 , V_80 ) )
F_192 ( V_74 , V_80 , V_217 ++ ) ;
V_74 -> V_217 = V_217 ;
if ( F_24 () )
F_193 ( & V_74 -> V_8 ) ;
}
static T_3 F_196 ( void )
{
T_3 V_292 , V_293 ;
F_197 ( V_292 ) ;
V_293 = F_102 ( V_294 ) ;
return V_292 + V_293 ;
}
static T_3 F_198 ( struct V_7 * V_8 , T_3 V_292 )
{
T_3 V_293 ;
V_293 = F_130 ( V_8 ) ?
F_6 ( V_8 ) -> V_14 . V_295 :
F_102 ( V_294 ) ;
return V_292 + V_293 ;
}
static void F_199 ( struct V_7 * V_8 , T_2 V_296 , bool V_297 )
{
if ( ! V_297 )
return;
if ( V_296 > V_298 ) {
V_8 -> V_117 . V_299 = 1 ;
V_8 -> V_117 . V_300 = 1 ;
} else
F_200 ( 1 , L_6 ) ;
}
static T_3 F_201 ( struct V_7 * V_8 )
{
return F_102 ( V_294 ) ;
}
static void F_202 ( struct V_7 * V_8 , T_3 V_301 )
{
if ( F_130 ( V_8 ) ) {
struct V_13 * V_13 ;
F_6 ( V_8 ) -> V_14 . V_295 = V_301 ;
V_13 = F_11 ( V_8 ) ;
F_110 ( V_294 , V_301 +
( F_58 ( V_13 , V_302 ) ?
V_13 -> V_293 : 0 ) ) ;
} else {
F_203 ( V_8 -> V_303 ,
F_102 ( V_294 ) , V_301 ) ;
F_110 ( V_294 , V_301 ) ;
}
}
static void F_204 ( struct V_7 * V_8 , T_10 V_304 , bool V_155 )
{
T_3 V_301 = F_102 ( V_294 ) ;
F_110 ( V_294 , V_301 + V_304 ) ;
if ( F_130 ( V_8 ) ) {
F_6 ( V_8 ) -> V_14 . V_295 += V_304 ;
} else
F_203 ( V_8 -> V_303 , V_301 ,
V_301 + V_304 ) ;
}
static T_3 F_205 ( struct V_7 * V_8 , T_3 V_305 )
{
return V_305 - F_206 () ;
}
static bool F_207 ( struct V_7 * V_8 )
{
struct V_306 * V_307 = F_208 ( V_8 , 1 , 0 ) ;
return V_307 && ( V_307 -> V_308 & ( 1 << ( V_309 & 31 ) ) ) ;
}
static inline bool F_209 ( struct V_7 * V_8 )
{
return V_14 && F_207 ( V_8 ) ;
}
static void F_210 ( struct V_6 * V_74 )
{
F_211 ( V_310 ,
V_74 -> V_14 . V_311 ,
V_74 -> V_14 . V_312 ) ;
V_74 -> V_14 . V_311 |=
V_313 ;
V_74 -> V_14 . V_312 &=
V_314 |
V_315 |
V_61 ;
V_74 -> V_14 . V_312 |=
V_313 |
V_72 ;
if ( F_212 ( V_74 -> V_8 . V_18 ) )
V_74 -> V_14 . V_312 |=
V_41 ;
F_211 ( V_316 ,
V_74 -> V_14 . V_317 ,
V_74 -> V_14 . V_318 ) ;
V_74 -> V_14 . V_317 =
V_319 ;
V_74 -> V_14 . V_318 &=
#ifdef F_103
V_320 |
#endif
V_321 | V_322 ;
V_74 -> V_14 . V_318 |=
V_319 |
V_148 | V_323 |
V_324 | V_325 ;
if ( F_213 () )
V_74 -> V_14 . V_318 |= V_326 ;
V_74 -> V_14 . V_327 =
V_74 -> V_14 . V_317 &
~ V_328 ;
F_211 ( V_329 ,
V_74 -> V_14 . V_330 ,
V_74 -> V_14 . V_331 ) ;
V_74 -> V_14 . V_330 =
V_332 ;
V_74 -> V_14 . V_331 &=
#ifdef F_103
V_333 |
#endif
V_334 ;
V_74 -> V_14 . V_331 |=
( V_332 | V_147 ) ;
if ( F_213 () )
V_74 -> V_14 . V_331 |= V_335 ;
V_74 -> V_14 . V_336 =
V_74 -> V_14 . V_330 &
~ V_337 ;
F_211 ( V_338 ,
V_74 -> V_14 . V_339 ,
V_74 -> V_14 . V_340 ) ;
V_74 -> V_14 . V_339 =
V_341 ;
V_74 -> V_14 . V_340 &=
V_342 |
V_343 | V_302 |
V_344 | V_345 |
V_346 | V_347 |
V_348 |
#ifdef F_103
V_349 | V_350 |
#endif
V_351 | V_352 |
V_353 | V_354 |
V_355 | V_356 |
V_357 | V_33 |
V_34 ;
V_74 -> V_14 . V_340 |=
V_341 |
V_32 ;
V_74 -> V_14 . V_358 =
V_74 -> V_14 . V_339 &
~ ( V_347 | V_348 ) ;
F_211 ( V_359 ,
V_74 -> V_14 . V_360 ,
V_74 -> V_14 . V_361 ) ;
V_74 -> V_14 . V_360 = 0 ;
V_74 -> V_14 . V_361 &=
V_36 |
V_37 |
V_38 |
V_39 |
V_62 |
V_73 ;
if ( V_102 ) {
V_74 -> V_14 . V_361 |=
V_54 ;
V_74 -> V_14 . V_362 = V_47 |
V_363 | V_45 |
V_364 ;
V_74 -> V_14 . V_362 &= V_42 . V_43 ;
V_74 -> V_14 . V_362 |= V_50 ;
} else
V_74 -> V_14 . V_362 = 0 ;
if ( V_365 )
V_74 -> V_14 . V_361 |=
V_55 ;
F_211 ( V_64 ,
V_74 -> V_14 . V_366 ,
V_74 -> V_14 . V_367 ) ;
V_74 -> V_14 . V_366 &= V_368 ;
V_74 -> V_14 . V_366 |=
V_369 |
V_370 ;
V_74 -> V_14 . V_367 = 0 ;
}
static inline bool F_214 ( T_2 V_3 , T_2 V_371 , T_2 V_372 )
{
return ( ( V_3 & V_372 ) | V_371 ) == V_3 ;
}
static inline T_3 F_215 ( T_2 V_371 , T_2 V_372 )
{
return V_371 | ( ( T_3 ) V_372 << 32 ) ;
}
static int F_216 ( struct V_7 * V_8 , T_2 V_373 , T_3 * V_374 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
switch ( V_373 ) {
case V_375 :
* V_374 = V_376 | V_377 |
( ( T_3 ) V_378 << V_379 ) |
( V_380 << V_381 ) ;
break;
case V_382 :
case V_310 :
* V_374 = F_215 (
V_74 -> V_14 . V_311 ,
V_74 -> V_14 . V_312 ) ;
break;
case V_383 :
* V_374 = F_215 (
V_74 -> V_14 . V_358 ,
V_74 -> V_14 . V_340 ) ;
break;
case V_338 :
* V_374 = F_215 (
V_74 -> V_14 . V_339 ,
V_74 -> V_14 . V_340 ) ;
break;
case V_384 :
* V_374 = F_215 (
V_74 -> V_14 . V_327 ,
V_74 -> V_14 . V_318 ) ;
break;
case V_316 :
* V_374 = F_215 (
V_74 -> V_14 . V_317 ,
V_74 -> V_14 . V_318 ) ;
break;
case V_385 :
* V_374 = F_215 (
V_74 -> V_14 . V_336 ,
V_74 -> V_14 . V_331 ) ;
break;
case V_329 :
* V_374 = F_215 (
V_74 -> V_14 . V_330 ,
V_74 -> V_14 . V_331 ) ;
break;
case V_64 :
* V_374 = F_215 (
V_74 -> V_14 . V_366 ,
V_74 -> V_14 . V_367 ) ;
break;
#define F_217 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_218 X86_CR4_VMXE
case V_386 :
* V_374 = F_217 ;
break;
case V_387 :
* V_374 = - 1ULL ;
break;
case V_388 :
* V_374 = F_218 ;
break;
case V_389 :
* V_374 = - 1ULL ;
break;
case V_390 :
* V_374 = 0x2e ;
break;
case V_359 :
* V_374 = F_215 (
V_74 -> V_14 . V_360 ,
V_74 -> V_14 . V_361 ) ;
break;
case V_391 :
* V_374 = V_74 -> V_14 . V_362 ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_219 ( struct V_7 * V_8 , T_2 V_373 , T_3 * V_374 )
{
T_3 V_184 ;
struct V_87 * V_75 ;
if ( ! V_374 ) {
F_76 ( V_90 L_7 ) ;
return - V_392 ;
}
switch ( V_373 ) {
#ifdef F_103
case V_208 :
V_184 = F_99 ( V_393 ) ;
break;
case V_210 :
V_184 = F_99 ( V_394 ) ;
break;
case V_211 :
F_158 ( F_6 ( V_8 ) ) ;
V_184 = F_6 ( V_8 ) -> V_213 ;
break;
#endif
case V_145 :
return F_220 ( V_8 , V_373 , V_374 ) ;
case V_395 :
V_184 = F_196 () ;
break;
case V_396 :
V_184 = F_101 ( V_397 ) ;
break;
case V_398 :
V_184 = F_99 ( V_399 ) ;
break;
case V_228 :
V_184 = F_99 ( V_400 ) ;
break;
case V_215 :
if ( ! F_213 () )
return 1 ;
V_184 = F_102 ( V_401 ) ;
break;
case V_402 :
if ( ! F_209 ( V_8 ) )
return 1 ;
V_184 = F_6 ( V_8 ) -> V_14 . V_403 ;
break;
case V_375 ... V_404 :
if ( ! F_209 ( V_8 ) )
return 1 ;
return F_216 ( V_8 , V_373 , V_374 ) ;
case V_405 :
if ( ! F_64 () )
return 1 ;
V_184 = V_8 -> V_117 . V_406 ;
break;
case V_289 :
if ( ! F_6 ( V_8 ) -> V_290 )
return 1 ;
default:
V_75 = F_73 ( F_6 ( V_8 ) , V_373 ) ;
if ( V_75 ) {
V_184 = V_75 -> V_184 ;
break;
}
return F_220 ( V_8 , V_373 , V_374 ) ;
}
* V_374 = V_184 ;
return 0 ;
}
static int F_221 ( struct V_7 * V_8 , struct V_407 * V_408 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_87 * V_75 ;
int V_115 = 0 ;
T_2 V_373 = V_408 -> V_80 ;
T_3 V_184 = V_408 -> V_184 ;
switch ( V_373 ) {
case V_145 :
V_115 = F_222 ( V_8 , V_408 ) ;
break;
#ifdef F_103
case V_208 :
F_123 ( V_74 ) ;
F_106 ( V_393 , V_184 ) ;
break;
case V_210 :
F_123 ( V_74 ) ;
F_106 ( V_394 , V_184 ) ;
break;
case V_211 :
F_158 ( V_74 ) ;
V_74 -> V_213 = V_184 ;
break;
#endif
case V_396 :
F_109 ( V_397 , V_184 ) ;
break;
case V_398 :
F_106 ( V_399 , V_184 ) ;
break;
case V_228 :
F_106 ( V_400 , V_184 ) ;
break;
case V_215 :
if ( ! F_213 () )
return 1 ;
F_110 ( V_401 , V_184 ) ;
break;
case V_395 :
F_223 ( V_8 , V_408 ) ;
break;
case V_409 :
if ( V_30 . V_410 & V_334 ) {
if ( ! F_224 ( V_8 , V_409 , V_184 ) )
return 1 ;
F_110 ( V_411 , V_184 ) ;
V_8 -> V_117 . V_412 = V_184 ;
break;
}
V_115 = F_222 ( V_8 , V_408 ) ;
break;
case V_413 :
V_115 = F_222 ( V_8 , V_408 ) ;
break;
case V_402 :
if ( ! F_209 ( V_8 ) ||
( F_6 ( V_8 ) -> V_14 . V_403 &
V_414 && ! V_408 -> V_415 ) )
return 1 ;
V_74 -> V_14 . V_403 = V_184 ;
if ( V_408 -> V_415 && V_184 == 0 )
F_225 ( V_8 ) ;
break;
case V_375 ... V_404 :
return 1 ;
case V_405 :
if ( ! F_64 () )
return 1 ;
if ( V_184 != 0 )
return 1 ;
V_8 -> V_117 . V_406 = V_184 ;
if ( V_8 -> V_117 . V_406 != V_416 )
F_134 ( V_74 , V_405 ,
V_8 -> V_117 . V_406 , V_416 ) ;
else
F_132 ( V_74 , V_405 ) ;
break;
case V_289 :
if ( ! V_74 -> V_290 )
return 1 ;
if ( ( V_184 >> 32 ) != 0 )
return 1 ;
default:
V_75 = F_73 ( V_74 , V_373 ) ;
if ( V_75 ) {
T_3 V_417 = V_75 -> V_184 ;
V_75 -> V_184 = V_184 ;
if ( V_75 - V_74 -> V_79 < V_74 -> V_217 ) {
F_159 () ;
V_115 = F_150 ( V_75 -> V_80 , V_75 -> V_184 ,
V_75 -> V_106 ) ;
F_160 () ;
if ( V_115 )
V_75 -> V_184 = V_417 ;
}
break;
}
V_115 = F_222 ( V_8 , V_408 ) ;
}
return V_115 ;
}
static void F_226 ( struct V_7 * V_8 , enum V_418 V_419 )
{
F_178 ( V_419 , ( unsigned long * ) & V_8 -> V_117 . V_118 ) ;
switch ( V_419 ) {
case V_420 :
V_8 -> V_117 . V_421 [ V_420 ] = F_99 ( V_422 ) ;
break;
case V_423 :
V_8 -> V_117 . V_421 [ V_423 ] = F_99 ( V_424 ) ;
break;
case V_425 :
if ( V_102 )
F_227 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_228 ( void )
{
return F_229 () ;
}
static T_11 int F_230 ( void )
{
T_3 V_75 ;
F_55 ( V_402 , V_75 ) ;
if ( V_75 & V_414 ) {
if ( ! ( V_75 & V_426 )
&& F_231 () )
return 1 ;
if ( ! ( V_75 & V_427 )
&& ( V_75 & V_426 )
&& ! F_231 () ) {
F_76 ( V_167 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_75 & V_427 )
&& ! F_231 () )
return 1 ;
}
return 0 ;
}
static void F_162 ( T_3 V_17 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_232 ( void )
{
int V_92 = F_86 () ;
T_3 V_89 = F_75 ( F_89 ( V_221 , V_92 ) ) ;
T_3 V_428 , V_429 ;
if ( V_242 () & V_430 )
return - V_431 ;
F_233 ( & F_89 ( V_225 , V_92 ) ) ;
F_79 ( V_92 ) ;
F_55 ( V_402 , V_428 ) ;
V_429 = V_414 ;
V_429 |= V_427 ;
if ( F_231 () )
V_429 |= V_426 ;
if ( ( V_428 & V_429 ) != V_429 ) {
F_148 ( V_402 , V_428 | V_429 ) ;
}
F_234 ( V_430 ) ;
if ( V_222 ) {
F_162 ( V_89 ) ;
F_97 () ;
}
F_235 ( F_137 ( & V_170 ) ) ;
return 0 ;
}
static void F_236 ( void )
{
int V_92 = F_86 () ;
struct V_91 * V_95 , * V_432 ;
F_237 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_88 ( V_95 ) ;
}
static void F_169 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_238 ( void )
{
if ( V_222 ) {
F_236 () ;
F_169 () ;
}
F_239 ( V_430 ) ;
}
static T_11 int F_240 ( T_2 V_433 , T_2 V_434 ,
T_2 V_75 , T_2 * V_435 )
{
T_2 V_436 , V_437 ;
T_2 V_438 = V_433 | V_434 ;
F_211 ( V_75 , V_436 , V_437 ) ;
V_438 &= V_437 ;
V_438 |= V_436 ;
if ( V_433 & ~ V_438 )
return - V_439 ;
* V_435 = V_438 ;
return 0 ;
}
static T_11 bool F_241 ( T_2 V_75 , T_2 V_438 )
{
T_2 V_436 , V_437 ;
F_211 ( V_75 , V_436 , V_437 ) ;
return V_437 & V_438 ;
}
static T_11 int F_242 ( struct V_30 * V_440 )
{
T_2 V_436 , V_437 ;
T_2 V_441 , V_442 , V_443 , V_444 ;
T_2 V_445 = 0 ;
T_2 V_446 = 0 ;
T_2 V_447 = 0 ;
T_2 V_448 = 0 ;
T_2 V_449 = 0 ;
V_441 = V_344 |
#ifdef F_103
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
V_442 = V_33 |
V_32 |
V_34 ;
if ( F_240 ( V_441 , V_442 , V_338 ,
& V_446 ) < 0 )
return - V_439 ;
#ifdef F_103
if ( ( V_446 & V_33 ) )
V_446 &= ~ V_349 &
~ V_350 ;
#endif
if ( V_446 & V_34 ) {
V_443 = 0 ;
V_444 = V_36 |
V_37 |
V_62 |
V_58 |
V_54 |
V_55 |
V_56 |
V_59 |
V_60 |
V_38 |
V_39 |
V_66 |
V_73 |
V_67 ;
if ( F_240 ( V_443 , V_444 ,
V_359 ,
& V_447 ) < 0 )
return - V_439 ;
}
#ifndef F_103
if ( ! ( V_447 &
V_36 ) )
V_446 &= ~ V_33 ;
#endif
if ( ! ( V_446 & V_33 ) )
V_447 &= ~ (
V_38 |
V_37 |
V_39 ) ;
if ( V_447 & V_54 ) {
V_446 &= ~ ( V_347 |
V_348 |
V_345 ) ;
F_211 ( V_391 ,
V_42 . V_43 , V_42 . V_51 ) ;
}
V_441 = V_328 ;
#ifdef F_103
V_441 |= V_320 ;
#endif
V_442 = V_322 | V_321 |
V_325 | V_326 ;
if ( F_240 ( V_441 , V_442 , V_316 ,
& V_448 ) < 0 )
return - V_439 ;
V_441 = V_314 | V_315 ;
V_442 = V_61 | V_41 ;
if ( F_240 ( V_441 , V_442 , V_310 ,
& V_445 ) < 0 )
return - V_439 ;
if ( ! ( V_447 &
V_39 ) ||
! ( V_448 & V_325 ) )
V_445 &= ~ V_41 ;
V_441 = V_337 ;
V_442 = V_334 | V_335 ;
if ( F_240 ( V_441 , V_442 , V_329 ,
& V_449 ) < 0 )
return - V_439 ;
F_211 ( V_375 , V_436 , V_437 ) ;
if ( ( V_437 & 0x1fff ) > V_450 )
return - V_439 ;
#ifdef F_103
if ( V_437 & ( 1u << 16 ) )
return - V_439 ;
#endif
if ( ( ( V_437 >> 18 ) & 15 ) != 6 )
return - V_439 ;
V_440 -> V_451 = V_437 & 0x1fff ;
V_440 -> V_452 = F_243 ( V_30 . V_451 ) ;
V_440 -> V_453 = V_436 ;
V_440 -> V_40 = V_445 ;
V_440 -> V_31 = V_446 ;
V_440 -> V_35 = V_447 ;
V_440 -> V_454 = V_448 ;
V_440 -> V_410 = V_449 ;
V_146 =
F_241 ( V_329 ,
V_147 )
&& F_241 ( V_316 ,
V_148 ) ;
V_150 =
F_241 ( V_329 ,
V_151 )
&& F_241 ( V_316 ,
V_152 ) ;
if ( V_150 && V_455 . V_456 == 0x6 ) {
switch ( V_455 . V_457 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_150 = false ;
F_135 ( V_167 L_10
L_11 ) ;
break;
default:
break;
}
}
if ( V_458 )
F_55 ( V_405 , V_416 ) ;
return 0 ;
}
static struct V_88 * F_244 ( int V_92 )
{
int V_459 = F_245 ( V_92 ) ;
struct V_16 * V_460 ;
struct V_88 * V_88 ;
V_460 = F_246 ( V_459 , V_461 , V_30 . V_452 ) ;
if ( ! V_460 )
return NULL ;
V_88 = F_247 ( V_460 ) ;
memset ( V_88 , 0 , V_30 . V_451 ) ;
V_88 -> V_453 = V_30 . V_453 ;
return V_88 ;
}
static struct V_88 * F_248 ( void )
{
return F_244 ( F_86 () ) ;
}
static void F_249 ( struct V_88 * V_88 )
{
F_250 ( ( unsigned long ) V_88 , V_30 . V_452 ) ;
}
static void F_251 ( struct V_91 * V_91 )
{
if ( ! V_91 -> V_88 )
return;
F_92 ( V_91 ) ;
F_249 ( V_91 -> V_88 ) ;
V_91 -> V_88 = NULL ;
}
static void F_252 ( void )
{
int V_92 ;
F_253 (cpu) {
F_249 ( F_89 ( V_221 , V_92 ) ) ;
F_89 ( V_221 , V_92 ) = NULL ;
}
}
static void F_254 ( void )
{
int V_76 , V_462 ;
for ( V_76 = V_462 = 0 ; V_76 < V_463 ; V_76 ++ ) {
switch ( V_464 [ V_76 ] ) {
case V_401 :
if ( ! F_213 () )
continue;
break;
default:
break;
}
if ( V_462 < V_76 )
V_464 [ V_462 ] =
V_464 [ V_76 ] ;
V_462 ++ ;
}
V_463 = V_462 ;
for ( V_76 = 0 ; V_76 < V_463 ; V_76 ++ ) {
F_255 ( V_464 [ V_76 ] ,
V_465 ) ;
F_255 ( V_464 [ V_76 ] ,
V_466 ) ;
}
for ( V_76 = 0 ; V_76 < V_467 ; V_76 ++ )
F_255 ( V_468 [ V_76 ] ,
V_466 ) ;
}
static T_11 int F_256 ( void )
{
int V_92 ;
F_253 (cpu) {
struct V_88 * V_88 ;
V_88 = F_244 ( V_92 ) ;
if ( ! V_88 ) {
F_252 () ;
return - V_469 ;
}
F_89 ( V_221 , V_92 ) = V_88 ;
}
return 0 ;
}
static bool F_257 ( struct V_7 * V_8 )
{
return V_470 && ! F_258 ( V_8 ) ;
}
static void F_259 ( struct V_7 * V_8 , int V_114 ,
struct V_471 * V_472 )
{
if ( ! V_470 ) {
if ( V_114 == V_473 || V_114 == V_474 )
V_472 -> V_121 &= ~ V_475 ;
V_472 -> V_476 = V_472 -> V_121 & V_475 ;
V_472 -> V_188 = 1 ;
}
F_260 ( V_8 , V_472 , V_114 ) ;
}
static void F_261 ( struct V_7 * V_8 )
{
unsigned long V_477 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_479 ] , V_479 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_480 ] , V_480 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_481 ] , V_481 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_482 ] , V_482 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_474 ] , V_474 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_473 ] , V_473 ) ;
V_74 -> V_137 . V_138 = 0 ;
F_123 ( V_74 ) ;
F_260 ( V_8 , & V_74 -> V_137 . V_478 [ V_483 ] , V_483 ) ;
V_477 = F_99 ( V_247 ) ;
V_477 &= V_248 ;
V_477 |= V_74 -> V_137 . V_245 & ~ V_248 ;
F_106 ( V_247 , V_477 ) ;
F_106 ( V_484 , ( F_99 ( V_484 ) & ~ V_485 ) |
( F_99 ( V_486 ) & V_485 ) ) ;
F_129 ( V_8 ) ;
F_259 ( V_8 , V_473 , & V_74 -> V_137 . V_478 [ V_473 ] ) ;
F_259 ( V_8 , V_474 , & V_74 -> V_137 . V_478 [ V_474 ] ) ;
F_259 ( V_8 , V_479 , & V_74 -> V_137 . V_478 [ V_479 ] ) ;
F_259 ( V_8 , V_480 , & V_74 -> V_137 . V_478 [ V_480 ] ) ;
F_259 ( V_8 , V_481 , & V_74 -> V_137 . V_478 [ V_481 ] ) ;
F_259 ( V_8 , V_482 , & V_74 -> V_137 . V_478 [ V_482 ] ) ;
}
static void F_263 ( int V_114 , struct V_471 * V_472 )
{
const struct V_487 * V_488 = & V_123 [ V_114 ] ;
struct V_471 V_489 = * V_472 ;
V_489 . V_476 = 0x3 ;
if ( V_114 == V_473 )
V_489 . type = 0x3 ;
if ( ! V_470 ) {
V_489 . V_121 = V_489 . V_124 >> 4 ;
V_489 . V_124 = V_489 . V_124 & 0xffff0 ;
V_489 . V_126 = 0xffff ;
V_489 . V_490 = 0 ;
V_489 . V_491 = 0 ;
V_489 . V_492 = 1 ;
V_489 . V_188 = 1 ;
V_489 . V_493 = 0 ;
V_489 . V_494 = 0 ;
V_489 . type = 0x3 ;
V_489 . V_495 = 0 ;
if ( V_472 -> V_124 & 0xf )
F_135 ( V_167 L_12
L_13
L_14 , V_114 ) ;
}
F_108 ( V_488 -> V_121 , V_489 . V_121 ) ;
F_109 ( V_488 -> V_124 , V_489 . V_124 ) ;
F_109 ( V_488 -> V_126 , V_489 . V_126 ) ;
F_109 ( V_488 -> V_130 , F_264 ( & V_489 ) ) ;
}
static void F_265 ( struct V_7 * V_8 )
{
unsigned long V_477 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_483 ] , V_483 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_479 ] , V_479 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_480 ] , V_480 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_481 ] , V_481 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_482 ] , V_482 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_474 ] , V_474 ) ;
F_262 ( V_8 , & V_74 -> V_137 . V_478 [ V_473 ] , V_473 ) ;
V_74 -> V_137 . V_138 = 1 ;
if ( ! V_8 -> V_18 -> V_117 . V_496 )
F_135 ( V_167 L_15
L_16 ) ;
F_123 ( V_74 ) ;
F_106 ( V_497 , V_8 -> V_18 -> V_117 . V_496 ) ;
F_109 ( V_498 , V_499 - 1 ) ;
F_109 ( V_500 , 0x008b ) ;
V_477 = F_99 ( V_247 ) ;
V_74 -> V_137 . V_245 = V_477 ;
V_477 |= V_249 | V_250 ;
F_106 ( V_247 , V_477 ) ;
F_106 ( V_484 , F_99 ( V_484 ) | V_485 ) ;
F_129 ( V_8 ) ;
F_263 ( V_474 , & V_74 -> V_137 . V_478 [ V_474 ] ) ;
F_263 ( V_473 , & V_74 -> V_137 . V_478 [ V_473 ] ) ;
F_263 ( V_479 , & V_74 -> V_137 . V_478 [ V_479 ] ) ;
F_263 ( V_480 , & V_74 -> V_137 . V_478 [ V_480 ] ) ;
F_263 ( V_482 , & V_74 -> V_137 . V_478 [ V_482 ] ) ;
F_263 ( V_481 , & V_74 -> V_137 . V_478 [ V_481 ] ) ;
F_266 ( V_8 ) ;
}
static void F_267 ( struct V_7 * V_8 , T_3 V_178 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_87 * V_75 = F_73 ( V_74 , V_145 ) ;
if ( ! V_75 )
return;
F_158 ( F_6 ( V_8 ) ) ;
V_8 -> V_117 . V_178 = V_178 ;
if ( V_178 & V_181 ) {
F_116 ( F_6 ( V_8 ) , V_333 ) ;
V_75 -> V_184 = V_178 ;
} else {
F_117 ( F_6 ( V_8 ) , V_333 ) ;
V_75 -> V_184 = V_178 & ~ V_182 ;
}
F_195 ( V_74 ) ;
}
static void F_268 ( struct V_7 * V_8 )
{
T_2 V_501 ;
F_123 ( F_6 ( V_8 ) ) ;
V_501 = F_101 ( V_500 ) ;
if ( ( V_501 & V_502 ) != V_503 ) {
F_269 ( L_17 ,
V_504 ) ;
F_109 ( V_500 ,
( V_501 & ~ V_502 )
| V_503 ) ;
}
F_267 ( V_8 , V_8 -> V_117 . V_178 | V_181 ) ;
}
static void F_270 ( struct V_7 * V_8 )
{
F_117 ( F_6 ( V_8 ) , V_333 ) ;
F_267 ( V_8 , V_8 -> V_117 . V_178 & ~ V_181 ) ;
}
static void F_271 ( struct V_7 * V_8 )
{
F_96 ( F_6 ( V_8 ) ) ;
if ( V_102 ) {
if ( ! F_272 ( V_8 -> V_117 . V_505 . V_506 ) )
return;
F_98 ( F_273 ( V_8 -> V_117 . V_505 . V_506 ) ) ;
}
}
static void F_175 ( struct V_7 * V_8 )
{
T_9 V_234 = V_8 -> V_117 . V_234 ;
V_8 -> V_117 . V_230 &= ~ V_234 ;
V_8 -> V_117 . V_230 |= F_99 ( V_231 ) & V_234 ;
}
static void F_274 ( struct V_7 * V_8 )
{
if ( V_102 && F_275 ( V_8 ) )
V_8 -> V_117 . V_507 = F_99 ( V_508 ) ;
F_178 ( V_509 , ( T_9 * ) & V_8 -> V_117 . V_118 ) ;
}
static void F_276 ( struct V_7 * V_8 )
{
T_9 V_510 = V_8 -> V_117 . V_510 ;
V_8 -> V_117 . V_511 &= ~ V_510 ;
V_8 -> V_117 . V_511 |= F_99 ( V_484 ) & V_510 ;
}
static void F_277 ( struct V_7 * V_8 )
{
struct V_512 * V_505 = V_8 -> V_117 . V_513 ;
if ( ! F_177 ( V_425 ,
( unsigned long * ) & V_8 -> V_117 . V_514 ) )
return;
if ( F_275 ( V_8 ) && F_278 ( V_8 ) && ! F_147 ( V_8 ) ) {
F_110 ( V_515 , V_505 -> V_516 [ 0 ] ) ;
F_110 ( V_517 , V_505 -> V_516 [ 1 ] ) ;
F_110 ( V_518 , V_505 -> V_516 [ 2 ] ) ;
F_110 ( V_519 , V_505 -> V_516 [ 3 ] ) ;
}
}
static void F_227 ( struct V_7 * V_8 )
{
struct V_512 * V_505 = V_8 -> V_117 . V_513 ;
if ( F_275 ( V_8 ) && F_278 ( V_8 ) && ! F_147 ( V_8 ) ) {
V_505 -> V_516 [ 0 ] = F_102 ( V_515 ) ;
V_505 -> V_516 [ 1 ] = F_102 ( V_517 ) ;
V_505 -> V_516 [ 2 ] = F_102 ( V_518 ) ;
V_505 -> V_516 [ 3 ] = F_102 ( V_519 ) ;
}
F_178 ( V_425 ,
( unsigned long * ) & V_8 -> V_117 . V_118 ) ;
F_178 ( V_425 ,
( unsigned long * ) & V_8 -> V_117 . V_514 ) ;
}
static void F_279 ( unsigned long * V_520 ,
unsigned long V_230 ,
struct V_7 * V_8 )
{
if ( ! F_177 ( V_509 , ( T_9 * ) & V_8 -> V_117 . V_118 ) )
F_274 ( V_8 ) ;
if ( ! ( V_230 & V_521 ) ) {
F_109 ( V_522 ,
F_101 ( V_522 ) |
( V_347 |
V_348 ) ) ;
V_8 -> V_117 . V_230 = V_230 ;
F_280 ( V_8 , F_281 ( V_8 ) ) ;
} else if ( ! F_275 ( V_8 ) ) {
F_109 ( V_522 ,
F_101 ( V_522 ) &
~ ( V_347 |
V_348 ) ) ;
V_8 -> V_117 . V_230 = V_230 ;
F_280 ( V_8 , F_281 ( V_8 ) ) ;
}
if ( ! ( V_230 & V_523 ) )
* V_520 &= ~ V_523 ;
}
static void F_282 ( struct V_7 * V_8 , unsigned long V_230 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
unsigned long V_520 ;
V_520 = ( V_230 & ~ V_524 ) ;
if ( V_365 )
V_520 |= V_525 ;
else {
V_520 |= V_526 ;
if ( V_74 -> V_137 . V_138 && ( V_230 & V_527 ) )
F_261 ( V_8 ) ;
if ( ! V_74 -> V_137 . V_138 && ! ( V_230 & V_527 ) )
F_265 ( V_8 ) ;
}
#ifdef F_103
if ( V_8 -> V_117 . V_178 & V_182 ) {
if ( ! F_275 ( V_8 ) && ( V_230 & V_521 ) )
F_268 ( V_8 ) ;
if ( F_275 ( V_8 ) && ! ( V_230 & V_521 ) )
F_270 ( V_8 ) ;
}
#endif
if ( V_102 )
F_279 ( & V_520 , V_230 , V_8 ) ;
if ( ! V_8 -> V_139 )
V_520 |= V_232 | V_233 ;
F_106 ( V_243 , V_230 ) ;
F_106 ( V_231 , V_520 ) ;
V_8 -> V_117 . V_230 = V_230 ;
V_74 -> F_257 = F_257 ( V_8 ) ;
}
static T_3 F_273 ( unsigned long V_506 )
{
T_3 V_85 ;
V_85 = V_528 |
V_529 << V_530 ;
if ( V_531 )
V_85 |= V_532 ;
V_85 |= ( V_506 & V_533 ) ;
return V_85 ;
}
static void F_283 ( struct V_7 * V_8 , unsigned long V_507 )
{
unsigned long V_534 ;
T_3 V_85 ;
V_534 = V_507 ;
if ( V_102 ) {
V_85 = F_273 ( V_507 ) ;
F_110 ( V_535 , V_85 ) ;
if ( F_275 ( V_8 ) || F_130 ( V_8 ) )
V_534 = F_284 ( V_8 ) ;
else
V_534 = V_8 -> V_18 -> V_117 . V_536 ;
F_277 ( V_8 ) ;
}
F_271 ( V_8 ) ;
F_106 ( V_508 , V_534 ) ;
}
static int F_280 ( struct V_7 * V_8 , unsigned long V_511 )
{
unsigned long V_537 = V_511 | ( F_6 ( V_8 ) -> V_137 . V_138 ?
V_538 : V_539 ) ;
if ( V_511 & V_430 ) {
if ( ! F_209 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_14 . V_540 &&
( ( V_511 & F_218 ) != F_218 ) )
return 1 ;
V_8 -> V_117 . V_511 = V_511 ;
if ( V_102 ) {
if ( ! F_275 ( V_8 ) ) {
V_537 &= ~ V_541 ;
V_537 |= V_542 ;
V_537 &= ~ ( V_543 | V_544 ) ;
} else if ( ! ( V_511 & V_541 ) ) {
V_537 &= ~ V_541 ;
}
}
F_106 ( V_486 , V_511 ) ;
F_106 ( V_484 , V_537 ) ;
return 0 ;
}
static void F_262 ( struct V_7 * V_8 ,
struct V_471 * V_489 , int V_114 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_2 V_128 ;
if ( V_74 -> V_137 . V_138 && V_114 != V_545 ) {
* V_489 = V_74 -> V_137 . V_478 [ V_114 ] ;
if ( V_114 == V_483
|| V_489 -> V_121 == F_125 ( V_74 , V_114 ) )
return;
V_489 -> V_124 = F_126 ( V_74 , V_114 ) ;
V_489 -> V_121 = F_125 ( V_74 , V_114 ) ;
return;
}
V_489 -> V_124 = F_126 ( V_74 , V_114 ) ;
V_489 -> V_126 = F_127 ( V_74 , V_114 ) ;
V_489 -> V_121 = F_125 ( V_74 , V_114 ) ;
V_128 = F_128 ( V_74 , V_114 ) ;
V_489 -> V_494 = ( V_128 >> 16 ) & 1 ;
V_489 -> type = V_128 & 15 ;
V_489 -> V_188 = ( V_128 >> 4 ) & 1 ;
V_489 -> V_476 = ( V_128 >> 5 ) & 3 ;
V_489 -> V_492 = ! V_489 -> V_494 ;
V_489 -> V_495 = ( V_128 >> 12 ) & 1 ;
V_489 -> V_493 = ( V_128 >> 13 ) & 1 ;
V_489 -> V_491 = ( V_128 >> 14 ) & 1 ;
V_489 -> V_490 = ( V_128 >> 15 ) & 1 ;
}
static T_3 F_285 ( struct V_7 * V_8 , int V_114 )
{
struct V_471 V_188 ;
if ( F_6 ( V_8 ) -> V_137 . V_138 ) {
F_262 ( V_8 , & V_188 , V_114 ) ;
return V_188 . V_124 ;
}
return F_126 ( F_6 ( V_8 ) , V_114 ) ;
}
static int F_286 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( F_107 ( V_74 -> V_137 . V_138 ) )
return 0 ;
else {
int V_128 = F_128 ( V_74 , V_474 ) ;
return F_287 ( V_128 ) ;
}
}
static T_2 F_264 ( struct V_471 * V_489 )
{
T_2 V_128 ;
if ( V_489 -> V_494 || ! V_489 -> V_492 )
V_128 = 1 << 16 ;
else {
V_128 = V_489 -> type & 15 ;
V_128 |= ( V_489 -> V_188 & 1 ) << 4 ;
V_128 |= ( V_489 -> V_476 & 3 ) << 5 ;
V_128 |= ( V_489 -> V_492 & 1 ) << 7 ;
V_128 |= ( V_489 -> V_495 & 1 ) << 12 ;
V_128 |= ( V_489 -> V_493 & 1 ) << 13 ;
V_128 |= ( V_489 -> V_491 & 1 ) << 14 ;
V_128 |= ( V_489 -> V_490 & 1 ) << 15 ;
}
return V_128 ;
}
static void F_260 ( struct V_7 * V_8 ,
struct V_471 * V_489 , int V_114 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
const struct V_487 * V_488 = & V_123 [ V_114 ] ;
F_123 ( V_74 ) ;
if ( V_74 -> V_137 . V_138 && V_114 != V_545 ) {
V_74 -> V_137 . V_478 [ V_114 ] = * V_489 ;
if ( V_114 == V_483 )
F_108 ( V_488 -> V_121 , V_489 -> V_121 ) ;
else if ( V_489 -> V_188 )
F_263 ( V_114 , & V_74 -> V_137 . V_478 [ V_114 ] ) ;
goto V_546;
}
F_106 ( V_488 -> V_124 , V_489 -> V_124 ) ;
F_109 ( V_488 -> V_126 , V_489 -> V_126 ) ;
F_108 ( V_488 -> V_121 , V_489 -> V_121 ) ;
if ( V_365 && ( V_114 != V_545 ) )
V_489 -> type |= 0x1 ;
F_109 ( V_488 -> V_130 , F_264 ( V_489 ) ) ;
V_546:
V_74 -> F_257 = F_257 ( V_8 ) ;
}
static void F_288 ( struct V_7 * V_8 , int * V_491 , int * V_493 )
{
T_2 V_128 = F_128 ( F_6 ( V_8 ) , V_473 ) ;
* V_491 = ( V_128 >> 14 ) & 1 ;
* V_493 = ( V_128 >> 13 ) & 1 ;
}
static void F_289 ( struct V_7 * V_8 , struct V_168 * V_547 )
{
V_547 -> V_451 = F_101 ( V_548 ) ;
V_547 -> V_173 = F_99 ( V_549 ) ;
}
static void F_290 ( struct V_7 * V_8 , struct V_168 * V_547 )
{
F_109 ( V_548 , V_547 -> V_451 ) ;
F_106 ( V_549 , V_547 -> V_173 ) ;
}
static void F_291 ( struct V_7 * V_8 , struct V_168 * V_547 )
{
V_547 -> V_451 = F_101 ( V_550 ) ;
V_547 -> V_173 = F_99 ( V_551 ) ;
}
static void F_292 ( struct V_7 * V_8 , struct V_168 * V_547 )
{
F_109 ( V_550 , V_547 -> V_451 ) ;
F_106 ( V_551 , V_547 -> V_173 ) ;
}
static bool F_293 ( struct V_7 * V_8 , int V_114 )
{
struct V_471 V_489 ;
T_2 V_128 ;
F_262 ( V_8 , & V_489 , V_114 ) ;
V_489 . V_476 = 0x3 ;
if ( V_114 == V_473 )
V_489 . type = 0x3 ;
V_128 = F_264 ( & V_489 ) ;
if ( V_489 . V_124 != ( V_489 . V_121 << 4 ) )
return false ;
if ( V_489 . V_126 != 0xffff )
return false ;
if ( V_128 != 0xf3 )
return false ;
return true ;
}
static bool F_294 ( struct V_7 * V_8 )
{
struct V_471 V_552 ;
unsigned int V_553 ;
F_262 ( V_8 , & V_552 , V_473 ) ;
V_553 = V_552 . V_121 & V_475 ;
if ( V_552 . V_494 )
return false ;
if ( ~ V_552 . type & ( V_554 | V_555 ) )
return false ;
if ( ! V_552 . V_188 )
return false ;
if ( V_552 . type & V_556 ) {
if ( V_552 . V_476 > V_553 )
return false ;
} else {
if ( V_552 . V_476 != V_553 )
return false ;
}
if ( ! V_552 . V_492 )
return false ;
return true ;
}
static bool F_295 ( struct V_7 * V_8 )
{
struct V_471 V_557 ;
unsigned int V_558 ;
F_262 ( V_8 , & V_557 , V_474 ) ;
V_558 = V_557 . V_121 & V_475 ;
if ( V_557 . V_494 )
return true ;
if ( V_557 . type != 3 && V_557 . type != 7 )
return false ;
if ( ! V_557 . V_188 )
return false ;
if ( V_557 . V_476 != V_558 )
return false ;
if ( ! V_557 . V_492 )
return false ;
return true ;
}
static bool F_296 ( struct V_7 * V_8 , int V_114 )
{
struct V_471 V_489 ;
unsigned int V_559 ;
F_262 ( V_8 , & V_489 , V_114 ) ;
V_559 = V_489 . V_121 & V_475 ;
if ( V_489 . V_494 )
return true ;
if ( ! V_489 . V_188 )
return false ;
if ( ! V_489 . V_492 )
return false ;
if ( ~ V_489 . type & ( V_554 | V_556 ) ) {
if ( V_489 . V_476 < V_559 )
return false ;
}
return true ;
}
static bool F_297 ( struct V_7 * V_8 )
{
struct V_471 V_191 ;
F_262 ( V_8 , & V_191 , V_483 ) ;
if ( V_191 . V_494 )
return false ;
if ( V_191 . V_121 & V_560 )
return false ;
if ( V_191 . type != 3 && V_191 . type != 11 )
return false ;
if ( ! V_191 . V_492 )
return false ;
return true ;
}
static bool F_298 ( struct V_7 * V_8 )
{
struct V_471 V_561 ;
F_262 ( V_8 , & V_561 , V_545 ) ;
if ( V_561 . V_494 )
return true ;
if ( V_561 . V_121 & V_560 )
return false ;
if ( V_561 . type != 2 )
return false ;
if ( ! V_561 . V_492 )
return false ;
return true ;
}
static bool F_299 ( struct V_7 * V_8 )
{
struct V_471 V_552 , V_557 ;
F_262 ( V_8 , & V_552 , V_473 ) ;
F_262 ( V_8 , & V_557 , V_474 ) ;
return ( ( V_552 . V_121 & V_475 ) ==
( V_557 . V_121 & V_475 ) ) ;
}
static bool F_258 ( struct V_7 * V_8 )
{
if ( V_365 )
return true ;
if ( ! F_300 ( V_8 ) || ( F_176 ( V_8 ) & V_250 ) ) {
if ( ! F_293 ( V_8 , V_473 ) )
return false ;
if ( ! F_293 ( V_8 , V_474 ) )
return false ;
if ( ! F_293 ( V_8 , V_480 ) )
return false ;
if ( ! F_293 ( V_8 , V_479 ) )
return false ;
if ( ! F_293 ( V_8 , V_481 ) )
return false ;
if ( ! F_293 ( V_8 , V_482 ) )
return false ;
} else {
if ( ! F_299 ( V_8 ) )
return false ;
if ( ! F_294 ( V_8 ) )
return false ;
if ( ! F_295 ( V_8 ) )
return false ;
if ( ! F_296 ( V_8 , V_480 ) )
return false ;
if ( ! F_296 ( V_8 , V_479 ) )
return false ;
if ( ! F_296 ( V_8 , V_481 ) )
return false ;
if ( ! F_296 ( V_8 , V_482 ) )
return false ;
if ( ! F_297 ( V_8 ) )
return false ;
if ( ! F_298 ( V_8 ) )
return false ;
}
return true ;
}
static int F_301 ( struct V_18 * V_18 )
{
T_12 V_562 ;
T_4 V_184 = 0 ;
int V_563 , V_564 ;
V_563 = F_302 ( & V_18 -> V_565 ) ;
V_562 = V_18 -> V_117 . V_496 >> V_19 ;
V_564 = F_303 ( V_18 , V_562 , 0 , V_450 ) ;
if ( V_564 < 0 )
goto V_546;
V_184 = V_566 + V_567 ;
V_564 = F_304 ( V_18 , V_562 ++ , & V_184 ,
V_568 , sizeof( T_4 ) ) ;
if ( V_564 < 0 )
goto V_546;
V_564 = F_303 ( V_18 , V_562 ++ , 0 , V_450 ) ;
if ( V_564 < 0 )
goto V_546;
V_564 = F_303 ( V_18 , V_562 , 0 , V_450 ) ;
if ( V_564 < 0 )
goto V_546;
V_184 = ~ 0 ;
V_564 = F_304 ( V_18 , V_562 , & V_184 ,
V_499 - 2 * V_450 - 1 ,
sizeof( T_6 ) ) ;
V_546:
F_305 ( & V_18 -> V_565 , V_563 ) ;
return V_564 ;
}
static int F_306 ( struct V_18 * V_18 )
{
int V_76 , V_563 , V_564 = 0 ;
T_13 V_569 ;
T_2 V_277 ;
if ( ! V_102 )
return 0 ;
F_307 ( & V_18 -> V_570 ) ;
if ( F_308 ( V_18 -> V_117 . V_571 ) )
goto V_572;
V_569 = V_18 -> V_117 . V_536 >> V_19 ;
V_564 = F_309 ( V_18 ) ;
if ( V_564 < 0 )
goto V_572;
V_563 = F_302 ( & V_18 -> V_565 ) ;
V_564 = F_303 ( V_18 , V_569 , 0 , V_450 ) ;
if ( V_564 < 0 )
goto V_546;
for ( V_76 = 0 ; V_76 < V_573 ; V_76 ++ ) {
V_277 = ( V_76 << 22 ) + ( V_574 | V_575 | V_576 |
V_577 | V_578 | V_579 ) ;
V_564 = F_304 ( V_18 , V_569 ,
& V_277 , V_76 * sizeof( V_277 ) , sizeof( V_277 ) ) ;
if ( V_564 < 0 )
goto V_546;
}
V_18 -> V_117 . V_571 = true ;
V_546:
F_305 ( & V_18 -> V_565 , V_563 ) ;
V_572:
F_310 ( & V_18 -> V_570 ) ;
return V_564 ;
}
static void F_311 ( int V_114 )
{
const struct V_487 * V_488 = & V_123 [ V_114 ] ;
unsigned int V_128 ;
F_108 ( V_488 -> V_121 , 0 ) ;
F_106 ( V_488 -> V_124 , 0 ) ;
F_109 ( V_488 -> V_126 , 0xffff ) ;
V_128 = 0x93 ;
if ( V_114 == V_473 )
V_128 |= 0x08 ;
F_109 ( V_488 -> V_130 , V_128 ) ;
}
static int F_312 ( struct V_18 * V_18 )
{
struct V_16 * V_16 ;
struct V_580 V_581 ;
int V_564 = 0 ;
F_307 ( & V_18 -> V_570 ) ;
if ( V_18 -> V_117 . V_582 )
goto V_546;
V_581 . V_583 = V_584 ;
V_581 . V_477 = 0 ;
V_581 . V_585 = V_586 ;
V_581 . V_587 = V_450 ;
V_564 = F_313 ( V_18 , & V_581 ) ;
if ( V_564 )
goto V_546;
V_16 = F_13 ( V_18 , V_586 >> V_19 ) ;
if ( F_14 ( V_16 ) ) {
V_564 = - V_588 ;
goto V_546;
}
F_314 ( V_16 ) ;
V_18 -> V_117 . V_582 = true ;
V_546:
F_310 ( & V_18 -> V_570 ) ;
return V_564 ;
}
static int F_309 ( struct V_18 * V_18 )
{
struct V_580 V_581 ;
int V_564 = 0 ;
F_315 ( V_18 -> V_117 . V_571 ) ;
V_581 . V_583 = V_589 ;
V_581 . V_477 = 0 ;
V_581 . V_585 =
V_18 -> V_117 . V_536 ;
V_581 . V_587 = V_450 ;
V_564 = F_313 ( V_18 , & V_581 ) ;
return V_564 ;
}
static void F_316 ( struct V_6 * V_74 )
{
int V_51 ;
V_74 -> V_51 = 0 ;
if ( ! V_590 )
return;
F_317 ( & V_591 ) ;
V_51 = F_318 ( V_592 , V_593 ) ;
if ( V_51 < V_593 ) {
V_74 -> V_51 = V_51 ;
F_178 ( V_51 , V_592 ) ;
}
F_319 ( & V_591 ) ;
}
static void F_320 ( struct V_6 * V_74 )
{
if ( ! V_590 )
return;
F_317 ( & V_591 ) ;
if ( V_74 -> V_51 != 0 )
F_321 ( V_74 -> V_51 , V_592 ) ;
F_319 ( & V_591 ) ;
}
static void F_322 ( unsigned long * V_278 ,
T_2 V_75 , int type )
{
int V_594 = sizeof( unsigned long ) ;
if ( ! F_24 () )
return;
if ( V_75 <= 0x1fff ) {
if ( type & V_595 )
F_321 ( V_75 , V_278 + 0x000 / V_594 ) ;
if ( type & V_596 )
F_321 ( V_75 , V_278 + 0x800 / V_594 ) ;
} else if ( ( V_75 >= 0xc0000000 ) && ( V_75 <= 0xc0001fff ) ) {
V_75 &= 0x1fff ;
if ( type & V_595 )
F_321 ( V_75 , V_278 + 0x400 / V_594 ) ;
if ( type & V_596 )
F_321 ( V_75 , V_278 + 0xc00 / V_594 ) ;
}
}
static void F_323 ( unsigned long * V_278 ,
T_2 V_75 , int type )
{
int V_594 = sizeof( unsigned long ) ;
if ( ! F_24 () )
return;
if ( V_75 <= 0x1fff ) {
if ( type & V_595 )
F_178 ( V_75 , V_278 + 0x000 / V_594 ) ;
if ( type & V_596 )
F_178 ( V_75 , V_278 + 0x800 / V_594 ) ;
} else if ( ( V_75 >= 0xc0000000 ) && ( V_75 <= 0xc0001fff ) ) {
V_75 &= 0x1fff ;
if ( type & V_595 )
F_178 ( V_75 , V_278 + 0x400 / V_594 ) ;
if ( type & V_596 )
F_178 ( V_75 , V_278 + 0xc00 / V_594 ) ;
}
}
static void F_324 ( unsigned long * V_597 ,
unsigned long * V_598 ,
T_2 V_75 , int type )
{
int V_594 = sizeof( unsigned long ) ;
if ( ! F_24 () ) {
F_325 ( 1 ) ;
return;
}
if ( V_75 <= 0x1fff ) {
if ( type & V_595 &&
! F_177 ( V_75 , V_597 + 0x000 / V_594 ) )
F_321 ( V_75 , V_598 + 0x000 / V_594 ) ;
if ( type & V_596 &&
! F_177 ( V_75 , V_597 + 0x800 / V_594 ) )
F_321 ( V_75 , V_598 + 0x800 / V_594 ) ;
} else if ( ( V_75 >= 0xc0000000 ) && ( V_75 <= 0xc0001fff ) ) {
V_75 &= 0x1fff ;
if ( type & V_595 &&
! F_177 ( V_75 , V_597 + 0x400 / V_594 ) )
F_321 ( V_75 , V_598 + 0x400 / V_594 ) ;
if ( type & V_596 &&
! F_177 ( V_75 , V_597 + 0xc00 / V_594 ) )
F_321 ( V_75 , V_598 + 0xc00 / V_594 ) ;
}
}
static void F_326 ( T_2 V_75 , bool V_599 )
{
if ( ! V_599 )
F_322 ( V_284 ,
V_75 , V_595 | V_596 ) ;
F_322 ( V_283 ,
V_75 , V_595 | V_596 ) ;
}
static void F_327 ( T_2 V_75 )
{
F_323 ( V_282 ,
V_75 , V_595 ) ;
F_323 ( V_281 ,
V_75 , V_595 ) ;
}
static void F_328 ( T_2 V_75 )
{
F_322 ( V_282 ,
V_75 , V_595 ) ;
F_322 ( V_281 ,
V_75 , V_595 ) ;
}
static void F_329 ( T_2 V_75 )
{
F_322 ( V_282 ,
V_75 , V_596 ) ;
F_322 ( V_281 ,
V_75 , V_596 ) ;
}
static int F_212 ( struct V_18 * V_18 )
{
return V_600 && F_27 ( V_18 ) ;
}
static int F_330 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_601 ;
void * V_602 ;
T_4 V_603 ;
if ( V_74 -> V_14 . V_1 &&
V_74 -> V_14 . V_604 ) {
V_74 -> V_14 . V_604 = false ;
if ( ! F_3 ( V_74 -> V_14 . V_1 ) )
return 0 ;
V_601 = F_331 (
( unsigned long * ) V_74 -> V_14 . V_1 -> V_5 , 256 ) ;
if ( V_601 == 256 )
return 0 ;
V_602 = F_332 ( V_74 -> V_14 . V_605 ) ;
if ( ! V_602 ) {
F_325 ( 1 ) ;
return - V_469 ;
}
F_333 ( V_74 -> V_14 . V_1 -> V_5 , V_602 ) ;
F_334 ( V_74 -> V_14 . V_605 ) ;
V_603 = F_100 ( V_606 ) ;
if ( ( T_6 ) V_601 > ( ( T_6 ) V_603 & 0xff ) ) {
V_603 &= ~ 0xff ;
V_603 |= ( T_6 ) V_601 ;
F_108 ( V_606 , V_603 ) ;
}
}
return 0 ;
}
static inline bool F_335 ( struct V_7 * V_8 )
{
#ifdef F_336
if ( V_8 -> V_607 == V_608 ) {
V_280 -> V_609 ( F_337 ( V_8 -> V_92 ) ,
V_610 ) ;
return true ;
}
#endif
return false ;
}
static int F_338 ( struct V_7 * V_8 ,
int V_4 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( F_130 ( V_8 ) &&
V_4 == V_74 -> V_14 . V_611 ) {
F_335 ( V_8 ) ;
V_74 -> V_14 . V_604 = true ;
F_163 ( V_612 , V_8 ) ;
return 0 ;
}
return - 1 ;
}
static void F_339 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_564 ;
V_564 = F_338 ( V_8 , V_4 ) ;
if ( ! V_564 )
return;
if ( F_5 ( V_4 , & V_74 -> V_1 ) )
return;
V_564 = F_1 ( & V_74 -> V_1 ) ;
F_163 ( V_612 , V_8 ) ;
if ( V_564 || ! F_335 ( V_8 ) )
F_340 ( V_8 ) ;
}
static void F_341 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_74 -> V_1 ) )
return;
F_342 ( V_8 , V_74 -> V_1 . V_5 ) ;
}
static void F_343 ( struct V_7 * V_8 )
{
return;
}
static void F_344 ( struct V_6 * V_74 )
{
T_2 V_613 , V_614 ;
unsigned long V_615 ;
struct V_168 V_547 ;
unsigned long V_511 ;
F_106 ( V_616 , F_345 () & ~ V_232 ) ;
F_106 ( V_617 , F_346 () ) ;
V_511 = V_242 () ;
F_106 ( V_618 , V_511 ) ;
V_74 -> V_192 . V_619 = V_511 ;
F_108 ( V_620 , V_621 ) ;
#ifdef F_103
F_108 ( V_622 , 0 ) ;
F_108 ( V_623 , 0 ) ;
#else
F_108 ( V_622 , V_624 ) ;
F_108 ( V_623 , V_624 ) ;
#endif
F_108 ( V_625 , V_624 ) ;
F_108 ( V_626 , V_174 * 8 ) ;
F_347 ( & V_547 ) ;
F_106 ( V_627 , V_547 . V_173 ) ;
V_74 -> V_628 = V_547 . V_173 ;
F_106 ( V_629 , V_630 ) ;
F_211 ( V_396 , V_613 , V_614 ) ;
F_109 ( V_631 , V_613 ) ;
F_55 ( V_398 , V_615 ) ;
F_106 ( V_632 , V_615 ) ;
if ( V_30 . V_454 & V_321 ) {
F_211 ( V_409 , V_613 , V_614 ) ;
F_110 ( V_633 , V_613 | ( ( T_3 ) V_614 << 32 ) ) ;
}
}
static void F_348 ( struct V_6 * V_74 )
{
V_74 -> V_8 . V_117 . V_510 = V_634 ;
if ( V_102 )
V_74 -> V_8 . V_117 . V_510 |= V_635 ;
if ( F_130 ( & V_74 -> V_8 ) )
V_74 -> V_8 . V_117 . V_510 &=
~ F_11 ( & V_74 -> V_8 ) -> V_241 ;
F_106 ( V_636 , ~ V_74 -> V_8 . V_117 . V_510 ) ;
}
static T_2 F_349 ( struct V_6 * V_74 )
{
T_2 V_40 = V_30 . V_40 ;
if ( ! F_212 ( V_74 -> V_8 . V_18 ) )
V_40 &= ~ V_41 ;
return V_40 ;
}
static T_2 F_350 ( struct V_6 * V_74 )
{
T_2 V_637 = V_30 . V_31 ;
if ( V_74 -> V_8 . V_117 . V_638 & V_639 )
V_637 &= ~ V_351 ;
if ( ! F_26 ( V_74 -> V_8 . V_18 ) ) {
V_637 &= ~ V_33 ;
#ifdef F_103
V_637 |= V_350 |
V_349 ;
#endif
}
if ( ! V_102 )
V_637 |= V_348 |
V_347 |
V_345 ;
return V_637 ;
}
static T_2 F_351 ( struct V_6 * V_74 )
{
T_2 V_637 = V_30 . V_35 ;
if ( ! F_48 ( V_74 -> V_8 . V_18 ) )
V_637 &= ~ V_36 ;
if ( V_74 -> V_51 == 0 )
V_637 &= ~ V_58 ;
if ( ! V_102 ) {
V_637 &= ~ V_54 ;
V_365 = 0 ;
V_637 &= ~ V_60 ;
}
if ( ! V_365 )
V_637 &= ~ V_55 ;
if ( ! V_640 )
V_637 &= ~ V_56 ;
if ( ! F_212 ( V_74 -> V_8 . V_18 ) )
V_637 &= ~ ( V_38 |
V_39 ) ;
V_637 &= ~ V_37 ;
V_637 &= ~ V_66 ;
V_637 &= ~ V_67 ;
return V_637 ;
}
static void F_352 ( void )
{
F_353 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_354 ( struct V_6 * V_74 )
{
#ifdef F_103
unsigned long V_641 ;
#endif
int V_76 ;
F_110 ( V_642 , F_75 ( V_643 ) ) ;
F_110 ( V_644 , F_75 ( V_645 ) ) ;
if ( V_646 ) {
F_110 ( V_647 , F_75 ( V_466 ) ) ;
F_110 ( V_648 , F_75 ( V_465 ) ) ;
}
if ( F_24 () )
F_110 ( V_285 , F_75 ( V_284 ) ) ;
F_110 ( V_649 , - 1ull ) ;
F_109 ( V_650 , F_349 ( V_74 ) ) ;
F_109 ( V_522 , F_350 ( V_74 ) ) ;
if ( F_28 () ) {
F_109 ( V_651 ,
F_351 ( V_74 ) ) ;
}
if ( F_212 ( V_74 -> V_8 . V_18 ) ) {
F_110 ( V_652 , 0 ) ;
F_110 ( V_653 , 0 ) ;
F_110 ( V_654 , 0 ) ;
F_110 ( V_655 , 0 ) ;
F_108 ( V_606 , 0 ) ;
F_110 ( V_656 , V_610 ) ;
F_110 ( V_657 , F_75 ( ( & V_74 -> V_1 ) ) ) ;
}
if ( V_640 ) {
F_109 ( V_658 , V_640 ) ;
V_74 -> V_659 = V_659 ;
V_74 -> V_660 = true ;
}
F_109 ( V_661 , 0 ) ;
F_109 ( V_662 , 0 ) ;
F_109 ( V_663 , 0 ) ;
F_108 ( V_198 , 0 ) ;
F_108 ( V_202 , 0 ) ;
F_344 ( V_74 ) ;
#ifdef F_103
F_55 ( V_208 , V_641 ) ;
F_106 ( V_207 , V_641 ) ;
F_55 ( V_210 , V_641 ) ;
F_106 ( V_209 , V_641 ) ;
#else
F_106 ( V_207 , 0 ) ;
F_106 ( V_209 , 0 ) ;
#endif
F_109 ( V_664 , 0 ) ;
F_109 ( V_157 , 0 ) ;
F_110 ( V_665 , F_75 ( V_74 -> V_143 . V_155 ) ) ;
F_109 ( V_156 , 0 ) ;
F_110 ( V_666 , F_75 ( V_74 -> V_143 . V_154 ) ) ;
if ( V_30 . V_410 & V_334 ) {
T_2 V_667 , V_668 ;
T_3 V_669 ;
F_211 ( V_409 , V_667 , V_668 ) ;
V_669 = V_667 | ( ( T_3 ) V_668 << 32 ) ;
F_110 ( V_411 , V_669 ) ;
V_74 -> V_8 . V_117 . V_412 = V_669 ;
}
for ( V_76 = 0 ; V_76 < F_10 ( V_78 ) ; ++ V_76 ) {
T_2 V_80 = V_78 [ V_76 ] ;
T_2 V_670 , V_671 ;
int V_462 = V_74 -> V_77 ;
if ( F_355 ( V_80 , & V_670 , & V_671 ) < 0 )
continue;
if ( F_356 ( V_80 , V_670 , V_671 ) < 0 )
continue;
V_74 -> V_79 [ V_462 ] . V_80 = V_76 ;
V_74 -> V_79 [ V_462 ] . V_184 = 0 ;
V_74 -> V_79 [ V_462 ] . V_106 = - 1ull ;
++ V_74 -> V_77 ;
}
F_118 ( V_74 , V_30 . V_454 ) ;
F_113 ( V_74 , V_30 . V_410 ) ;
F_106 ( V_236 , ~ 0UL ) ;
F_348 ( V_74 ) ;
if ( F_64 () )
F_110 ( V_672 , V_673 ) ;
return 0 ;
}
static void F_357 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_407 V_674 ;
V_74 -> V_137 . V_138 = 0 ;
V_74 -> V_675 = 0 ;
V_74 -> V_8 . V_117 . V_421 [ V_676 ] = F_358 () ;
F_359 ( & V_74 -> V_8 , 0 ) ;
V_674 . V_184 = V_586 | V_677 ;
if ( F_360 ( & V_74 -> V_8 ) )
V_674 . V_184 |= V_678 ;
V_674 . V_415 = true ;
F_361 ( & V_74 -> V_8 , & V_674 ) ;
F_123 ( V_74 ) ;
F_311 ( V_473 ) ;
F_108 ( V_679 , 0xf000 ) ;
F_109 ( V_680 , 0xffff0000 ) ;
F_311 ( V_480 ) ;
F_311 ( V_479 ) ;
F_311 ( V_481 ) ;
F_311 ( V_482 ) ;
F_311 ( V_474 ) ;
F_108 ( V_681 , 0 ) ;
F_106 ( V_497 , 0 ) ;
F_109 ( V_498 , 0xffff ) ;
F_109 ( V_500 , 0x008b ) ;
F_108 ( V_682 , 0 ) ;
F_106 ( V_683 , 0 ) ;
F_109 ( V_684 , 0xffff ) ;
F_109 ( V_685 , 0x00082 ) ;
F_109 ( V_397 , 0 ) ;
F_106 ( V_400 , 0 ) ;
F_106 ( V_399 , 0 ) ;
F_106 ( V_247 , 0x02 ) ;
F_184 ( V_8 , 0xfff0 ) ;
F_106 ( V_551 , 0 ) ;
F_109 ( V_550 , 0xffff ) ;
F_106 ( V_549 , 0 ) ;
F_109 ( V_548 , 0xffff ) ;
F_109 ( V_686 , V_687 ) ;
F_109 ( V_252 , 0 ) ;
F_109 ( V_688 , 0 ) ;
F_110 ( V_689 , 0 ) ;
F_195 ( V_74 ) ;
F_109 ( V_274 , 0 ) ;
if ( F_25 () ) {
F_110 ( V_690 , 0 ) ;
if ( F_26 ( V_74 -> V_8 . V_18 ) )
F_110 ( V_690 ,
F_75 ( V_74 -> V_8 . V_117 . V_280 -> V_421 ) ) ;
F_109 ( V_691 , 0 ) ;
}
F_163 ( V_692 , V_8 ) ;
if ( F_212 ( V_8 -> V_18 ) )
memset ( & V_74 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_74 -> V_51 != 0 )
F_108 ( V_693 , V_74 -> V_51 ) ;
V_74 -> V_8 . V_117 . V_230 = V_694 | V_695 | V_696 ;
F_282 ( & V_74 -> V_8 , F_362 ( V_8 ) ) ;
F_280 ( & V_74 -> V_8 , 0 ) ;
F_267 ( & V_74 -> V_8 , 0 ) ;
F_170 ( & V_74 -> V_8 ) ;
F_129 ( & V_74 -> V_8 ) ;
F_96 ( V_74 ) ;
}
static bool F_363 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_71 &
V_314 ;
}
static bool F_364 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_697 &
V_325 ;
}
static bool F_365 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_71 &
V_315 ;
}
static void F_366 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_101 ( V_522 ) ;
V_69 |= V_342 ;
F_109 ( V_522 , V_69 ) ;
}
static void F_367 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () ||
F_101 ( V_252 ) & V_253 ) {
F_366 ( V_8 ) ;
return;
}
V_69 = F_101 ( V_522 ) ;
V_69 |= V_343 ;
F_109 ( V_522 , V_69 ) ;
}
static void F_368 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_14 V_698 ;
int V_699 = V_8 -> V_117 . V_700 . V_153 ;
F_369 ( V_699 ) ;
++ V_8 -> V_218 . V_701 ;
if ( V_74 -> V_137 . V_138 ) {
int V_268 = 0 ;
if ( V_8 -> V_117 . V_700 . V_702 )
V_268 = V_8 -> V_117 . V_269 ;
if ( F_189 ( V_8 , V_699 , V_268 ) != V_270 )
F_163 ( V_271 , V_8 ) ;
return;
}
V_698 = V_699 | V_23 ;
if ( V_8 -> V_117 . V_700 . V_702 ) {
V_698 |= V_703 ;
F_109 ( V_272 ,
V_74 -> V_8 . V_117 . V_269 ) ;
} else
V_698 |= V_28 ;
F_109 ( V_274 , V_698 ) ;
}
static void F_370 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( F_130 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_74 -> V_675 = 1 ;
V_74 -> V_704 = 0 ;
}
++ V_8 -> V_218 . V_705 ;
V_74 -> V_706 = false ;
if ( V_74 -> V_137 . V_138 ) {
if ( F_189 ( V_8 , V_707 , 0 ) != V_270 )
F_163 ( V_271 , V_8 ) ;
return;
}
F_109 ( V_274 ,
V_708 | V_23 | V_707 ) ;
}
static bool F_371 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_675 ;
if ( F_6 ( V_8 ) -> V_706 )
return false ;
return F_101 ( V_252 ) & V_709 ;
}
static void F_372 ( struct V_7 * V_8 , bool V_710 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_74 -> V_675 != V_710 ) {
V_74 -> V_675 = V_710 ;
V_74 -> V_704 = 0 ;
}
} else {
V_74 -> V_706 = ! V_710 ;
if ( V_710 )
F_112 ( V_252 ,
V_709 ) ;
else
F_111 ( V_252 ,
V_709 ) ;
}
}
static int F_373 ( struct V_7 * V_8 )
{
if ( F_6 ( V_8 ) -> V_14 . V_711 )
return 0 ;
if ( ! F_52 () && F_6 ( V_8 ) -> V_675 )
return 0 ;
return ! ( F_101 ( V_252 ) &
( V_255 | V_253
| V_709 ) ) ;
}
static int F_374 ( struct V_7 * V_8 )
{
return ( ! F_6 ( V_8 ) -> V_14 . V_711 &&
F_99 ( V_247 ) & V_712 ) &&
! ( F_101 ( V_252 ) &
( V_253 | V_255 ) ) ;
}
static int F_375 ( struct V_18 * V_18 , unsigned int V_17 )
{
int V_115 ;
struct V_580 V_713 = {
. V_583 = V_714 ,
. V_585 = V_17 ,
. V_587 = V_450 * 3 ,
. V_477 = 0 ,
} ;
V_115 = F_376 ( V_18 , & V_713 ) ;
if ( V_115 )
return V_115 ;
V_18 -> V_117 . V_496 = V_17 ;
return F_301 ( V_18 ) ;
}
static bool F_377 ( struct V_7 * V_8 , int V_715 )
{
switch ( V_715 ) {
case V_136 :
F_6 ( V_8 ) -> V_8 . V_117 . V_269 =
F_101 ( V_259 ) ;
if ( V_8 -> V_133 & V_135 )
return false ;
case V_132 :
if ( V_8 -> V_133 &
( V_716 | V_717 ) )
return false ;
case V_718 :
case V_719 :
case V_720 :
case V_27 :
case V_721 :
case V_722 :
case V_723 :
case V_724 :
return true ;
break;
}
return false ;
}
static int F_378 ( struct V_7 * V_8 ,
int V_715 , T_2 V_725 )
{
if ( ( ( V_715 == V_723 ) || ( V_715 == V_722 ) ) && V_725 == 0 ) {
if ( F_379 ( V_8 , 0 ) == V_270 ) {
if ( V_8 -> V_117 . V_726 ) {
V_8 -> V_117 . V_726 = 0 ;
return F_380 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_381 ( V_8 , V_715 ) ;
return 1 ;
}
static void F_382 ( void )
{
#if F_383 ( V_727 ) && F_383 ( F_103 )
struct V_728 V_421 = {
. V_552 = 3 ,
. V_477 = V_712 ,
} ;
F_384 ( & V_421 , 0 ) ;
#endif
}
static int F_385 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_386 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_729 * V_729 = V_8 -> V_730 ;
T_2 V_20 , V_731 , V_264 ;
unsigned long V_732 , V_258 , V_733 ;
T_2 V_734 ;
enum V_735 V_736 ;
V_734 = V_74 -> V_737 ;
V_20 = V_74 -> V_738 ;
if ( F_23 ( V_20 ) )
return F_385 ( V_8 ) ;
if ( ( V_20 & V_21 ) == V_708 )
return 1 ;
if ( F_20 ( V_20 ) ) {
F_170 ( V_8 ) ;
return 1 ;
}
if ( F_21 ( V_20 ) ) {
V_736 = F_379 ( V_8 , V_739 ) ;
if ( V_736 != V_270 )
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
V_264 = 0 ;
if ( V_20 & V_267 )
V_264 = F_101 ( V_740 ) ;
if ( ( V_734 & V_741 ) &&
! ( F_19 ( V_20 ) && ! ( V_264 & V_742 ) ) ) {
V_8 -> V_730 -> V_260 = V_743 ;
V_8 -> V_730 -> V_744 . V_745 = V_746 ;
V_8 -> V_730 -> V_744 . V_747 = 2 ;
V_8 -> V_730 -> V_744 . V_184 [ 0 ] = V_734 ;
V_8 -> V_730 -> V_744 . V_184 [ 1 ] = V_20 ;
return 0 ;
}
if ( F_19 ( V_20 ) ) {
F_315 ( V_102 ) ;
V_732 = F_99 ( V_262 ) ;
F_387 ( V_732 , V_264 ) ;
if ( F_388 ( V_8 ) )
F_389 ( V_8 , V_732 ) ;
return F_390 ( V_8 , V_732 , V_264 , NULL , 0 ) ;
}
V_731 = V_20 & V_22 ;
if ( V_74 -> V_137 . V_138 && F_377 ( V_8 , V_731 ) )
return F_378 ( V_8 , V_731 , V_264 ) ;
switch ( V_731 ) {
case V_132 :
V_733 = F_99 ( V_262 ) ;
if ( ! ( V_8 -> V_133 &
( V_716 | V_717 ) ) ) {
V_8 -> V_117 . V_733 &= ~ 15 ;
V_8 -> V_117 . V_733 |= V_733 | V_748 ;
if ( ! ( V_733 & ~ V_749 ) )
F_182 ( V_8 ) ;
F_381 ( V_8 , V_132 ) ;
return 1 ;
}
V_729 -> V_750 . V_117 . V_733 = V_733 | V_751 ;
V_729 -> V_750 . V_117 . V_752 = F_99 ( V_753 ) ;
case V_136 :
V_74 -> V_8 . V_117 . V_269 =
F_101 ( V_259 ) ;
V_729 -> V_260 = V_754 ;
V_258 = F_183 ( V_8 ) ;
V_729 -> V_750 . V_117 . V_755 = F_99 ( V_680 ) + V_258 ;
V_729 -> V_750 . V_117 . V_756 = V_731 ;
break;
default:
V_729 -> V_260 = V_757 ;
V_729 -> V_758 . V_756 = V_731 ;
V_729 -> V_758 . V_264 = V_264 ;
break;
}
return 0 ;
}
static int F_391 ( struct V_7 * V_8 )
{
++ V_8 -> V_218 . V_759 ;
return 1 ;
}
static int F_392 ( struct V_7 * V_8 )
{
V_8 -> V_730 -> V_260 = V_760 ;
return 0 ;
}
static int F_393 ( struct V_7 * V_8 )
{
unsigned long V_761 ;
int V_451 , V_762 , string ;
unsigned V_763 ;
V_761 = F_99 ( V_262 ) ;
string = ( V_761 & 16 ) != 0 ;
V_762 = ( V_761 & 8 ) != 0 ;
++ V_8 -> V_218 . V_764 ;
if ( string || V_762 )
return F_379 ( V_8 , 0 ) == V_270 ;
V_763 = V_761 >> 16 ;
V_451 = ( V_761 & 7 ) + 1 ;
F_182 ( V_8 ) ;
return F_394 ( V_8 , V_451 , V_763 ) ;
}
static void
F_395 ( struct V_7 * V_8 , unsigned char * V_765 )
{
V_765 [ 0 ] = 0x0f ;
V_765 [ 1 ] = 0x01 ;
V_765 [ 2 ] = 0xc1 ;
}
static bool F_396 ( struct V_7 * V_8 , unsigned long V_107 )
{
unsigned long V_766 = F_217 ;
struct V_13 * V_13 = F_11 ( V_8 ) ;
if ( F_6 ( V_8 ) -> V_14 . V_361 &
V_55 &&
F_59 ( V_13 , V_55 ) )
V_766 &= ~ ( V_527 | V_521 ) ;
return ( V_107 & V_766 ) == V_766 ;
}
static int F_397 ( struct V_7 * V_8 , unsigned long V_107 )
{
if ( F_130 ( V_8 ) ) {
struct V_13 * V_13 = F_11 ( V_8 ) ;
unsigned long V_767 = V_107 ;
V_107 = ( V_107 & ~ V_13 -> V_235 ) |
( V_13 -> V_238 & V_13 -> V_235 ) ;
if ( ! F_396 ( V_8 , V_107 ) )
return 1 ;
if ( F_398 ( V_8 , V_107 ) )
return 1 ;
F_106 ( V_243 , V_767 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_14 . V_540 &&
( ( V_107 & F_217 ) != F_217 ) )
return 1 ;
return F_398 ( V_8 , V_107 ) ;
}
}
static int F_399 ( struct V_7 * V_8 , unsigned long V_107 )
{
if ( F_130 ( V_8 ) ) {
struct V_13 * V_13 = F_11 ( V_8 ) ;
unsigned long V_767 = V_107 ;
V_107 = ( V_107 & ~ V_13 -> V_241 ) |
( V_13 -> V_240 & V_13 -> V_241 ) ;
if ( F_400 ( V_8 , V_107 ) )
return 1 ;
F_106 ( V_486 , V_767 ) ;
return 0 ;
} else
return F_400 ( V_8 , V_107 ) ;
}
static void F_401 ( struct V_7 * V_8 )
{
if ( F_130 ( V_8 ) ) {
F_106 ( V_243 ,
F_99 ( V_243 ) & ~ V_232 ) ;
V_8 -> V_117 . V_230 &= ~ V_232 ;
} else
F_282 ( V_8 , F_171 ( V_8 , ~ V_232 ) ) ;
}
static int F_402 ( struct V_7 * V_8 )
{
unsigned long V_761 , V_107 ;
int V_768 ;
int V_419 ;
int V_769 ;
V_761 = F_99 ( V_262 ) ;
V_768 = V_761 & 15 ;
V_419 = ( V_761 >> 8 ) & 15 ;
switch ( ( V_761 >> 4 ) & 3 ) {
case 0 :
V_107 = F_403 ( V_8 , V_419 ) ;
F_404 ( V_768 , V_107 ) ;
switch ( V_768 ) {
case 0 :
V_769 = F_397 ( V_8 , V_107 ) ;
F_405 ( V_8 , V_769 ) ;
return 1 ;
case 3 :
V_769 = F_406 ( V_8 , V_107 ) ;
F_405 ( V_8 , V_769 ) ;
return 1 ;
case 4 :
V_769 = F_399 ( V_8 , V_107 ) ;
F_405 ( V_8 , V_769 ) ;
return 1 ;
case 8 : {
T_6 V_770 = F_407 ( V_8 ) ;
T_6 V_771 = ( T_6 ) V_107 ;
V_769 = F_359 ( V_8 , V_771 ) ;
F_405 ( V_8 , V_769 ) ;
if ( F_27 ( V_8 -> V_18 ) )
return 1 ;
if ( V_770 <= V_771 )
return 1 ;
V_8 -> V_730 -> V_260 = V_772 ;
return 0 ;
}
}
break;
case 2 :
F_401 ( V_8 ) ;
F_404 ( 0 , F_362 ( V_8 ) ) ;
F_182 ( V_8 ) ;
F_170 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_768 ) {
case 3 :
V_107 = F_284 ( V_8 ) ;
F_408 ( V_8 , V_419 , V_107 ) ;
F_409 ( V_768 , V_107 ) ;
F_182 ( V_8 ) ;
return 1 ;
case 8 :
V_107 = F_407 ( V_8 ) ;
F_408 ( V_8 , V_419 , V_107 ) ;
F_409 ( V_768 , V_107 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_107 = ( V_761 >> V_773 ) & 0x0f ;
F_404 ( 0 , ( F_362 ( V_8 ) & ~ 0xful ) | V_107 ) ;
F_410 ( V_8 , V_107 ) ;
F_182 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_730 -> V_260 = 0 ;
F_411 ( V_8 , L_18 ,
( int ) ( V_761 >> 4 ) & 3 , V_768 ) ;
return 0 ;
}
static int F_412 ( struct V_7 * V_8 )
{
unsigned long V_761 ;
int V_774 , V_752 , V_419 ;
V_761 = F_99 ( V_262 ) ;
V_774 = V_761 & V_775 ;
if ( ! F_413 ( V_8 , V_774 ) )
return 1 ;
if ( ! F_414 ( V_8 , 0 ) )
return 1 ;
V_752 = F_99 ( V_753 ) ;
if ( V_752 & V_776 ) {
if ( V_8 -> V_133 & V_717 ) {
V_8 -> V_730 -> V_750 . V_117 . V_733 = V_8 -> V_117 . V_733 ;
V_8 -> V_730 -> V_750 . V_117 . V_752 = V_752 ;
V_8 -> V_730 -> V_750 . V_117 . V_755 = F_415 ( V_8 ) ;
V_8 -> V_730 -> V_750 . V_117 . V_756 = V_132 ;
V_8 -> V_730 -> V_260 = V_754 ;
return 0 ;
} else {
V_8 -> V_117 . V_733 &= ~ 15 ;
V_8 -> V_117 . V_733 |= V_777 | V_748 ;
F_381 ( V_8 , V_132 ) ;
return 1 ;
}
}
if ( V_8 -> V_133 == 0 ) {
T_2 V_69 ;
V_69 = F_101 ( V_522 ) ;
V_69 &= ~ V_351 ;
F_109 ( V_522 , V_69 ) ;
V_8 -> V_117 . V_638 |= V_639 ;
return 1 ;
}
V_419 = F_416 ( V_761 ) ;
if ( V_761 & V_778 ) {
unsigned long V_107 ;
if ( F_417 ( V_8 , V_774 , & V_107 ) )
return 1 ;
F_408 ( V_8 , V_419 , V_107 ) ;
} else
if ( F_418 ( V_8 , V_774 , F_403 ( V_8 , V_419 ) ) )
return 1 ;
F_182 ( V_8 ) ;
return 1 ;
}
static T_3 F_419 ( struct V_7 * V_8 )
{
return V_8 -> V_117 . V_733 ;
}
static void F_420 ( struct V_7 * V_8 , unsigned long V_107 )
{
}
static void F_421 ( struct V_7 * V_8 )
{
T_2 V_69 ;
F_422 ( V_8 -> V_117 . V_491 [ 0 ] , 0 ) ;
F_422 ( V_8 -> V_117 . V_491 [ 1 ] , 1 ) ;
F_422 ( V_8 -> V_117 . V_491 [ 2 ] , 2 ) ;
F_422 ( V_8 -> V_117 . V_491 [ 3 ] , 3 ) ;
F_422 ( V_8 -> V_117 . V_733 , 6 ) ;
V_8 -> V_117 . V_752 = F_99 ( V_753 ) ;
V_8 -> V_117 . V_638 &= ~ V_639 ;
V_69 = F_101 ( V_522 ) ;
V_69 |= V_351 ;
F_109 ( V_522 , V_69 ) ;
}
static void F_423 ( struct V_7 * V_8 , unsigned long V_107 )
{
F_106 ( V_753 , V_107 ) ;
}
static int F_424 ( struct V_7 * V_8 )
{
F_425 ( V_8 ) ;
return 1 ;
}
static int F_426 ( struct V_7 * V_8 )
{
T_2 V_308 = V_8 -> V_117 . V_421 [ V_779 ] ;
T_3 V_184 ;
if ( F_219 ( V_8 , V_308 , & V_184 ) ) {
F_427 ( V_308 ) ;
F_428 ( V_8 , 0 ) ;
return 1 ;
}
F_429 ( V_308 , V_184 ) ;
V_8 -> V_117 . V_421 [ V_780 ] = V_184 & - 1u ;
V_8 -> V_117 . V_421 [ V_676 ] = ( V_184 >> 32 ) & - 1u ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_430 ( struct V_7 * V_8 )
{
struct V_407 V_75 ;
T_2 V_308 = V_8 -> V_117 . V_421 [ V_779 ] ;
T_3 V_184 = ( V_8 -> V_117 . V_421 [ V_780 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_117 . V_421 [ V_676 ] & - 1u ) << 32 ) ;
V_75 . V_184 = V_184 ;
V_75 . V_80 = V_308 ;
V_75 . V_415 = false ;
if ( F_431 ( V_8 , & V_75 ) != 0 ) {
F_432 ( V_308 , V_184 ) ;
F_428 ( V_8 , 0 ) ;
return 1 ;
}
F_433 ( V_308 , V_184 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_434 ( struct V_7 * V_8 )
{
F_163 ( V_612 , V_8 ) ;
return 1 ;
}
static int F_435 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_101 ( V_522 ) ;
V_69 &= ~ V_342 ;
F_109 ( V_522 , V_69 ) ;
F_163 ( V_612 , V_8 ) ;
++ V_8 -> V_218 . V_781 ;
if ( ! F_27 ( V_8 -> V_18 ) &&
V_8 -> V_730 -> V_782 &&
! F_436 ( V_8 ) ) {
V_8 -> V_730 -> V_260 = V_783 ;
return 0 ;
}
return 1 ;
}
static int F_437 ( struct V_7 * V_8 )
{
F_182 ( V_8 ) ;
return F_380 ( V_8 ) ;
}
static int F_438 ( struct V_7 * V_8 )
{
F_182 ( V_8 ) ;
F_439 ( V_8 ) ;
return 1 ;
}
static int F_440 ( struct V_7 * V_8 )
{
return F_379 ( V_8 , 0 ) == V_270 ;
}
static int F_441 ( struct V_7 * V_8 )
{
unsigned long V_761 = F_99 ( V_262 ) ;
F_442 ( V_8 , V_761 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_443 ( struct V_7 * V_8 )
{
int V_769 ;
V_769 = F_444 ( V_8 ) ;
F_405 ( V_8 , V_769 ) ;
return 1 ;
}
static int F_445 ( struct V_7 * V_8 )
{
F_182 ( V_8 ) ;
F_446 ( V_8 ) ;
return 1 ;
}
static int F_447 ( struct V_7 * V_8 )
{
T_3 V_784 = F_448 ( V_8 ) ;
T_2 V_80 = F_449 ( V_8 , V_779 ) ;
if ( F_450 ( V_8 , V_80 , V_784 ) == 0 )
F_182 ( V_8 ) ;
return 1 ;
}
static int F_451 ( struct V_7 * V_8 )
{
F_182 ( V_8 ) ;
F_200 ( 1 , L_19 ) ;
return 1 ;
}
static int F_452 ( struct V_7 * V_8 )
{
F_182 ( V_8 ) ;
F_200 ( 1 , L_19 ) ;
return 1 ;
}
static int F_453 ( struct V_7 * V_8 )
{
if ( F_308 ( V_785 ) ) {
unsigned long V_761 = F_99 ( V_262 ) ;
int V_786 , V_301 ;
V_786 = V_761 & V_787 ;
V_301 = V_761 & V_788 ;
if ( ( V_786 == V_789 ) &&
( V_301 == V_790 ) ) {
F_454 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
}
return F_379 ( V_8 , 0 ) == V_270 ;
}
static int F_455 ( struct V_7 * V_8 )
{
unsigned long V_761 = F_99 ( V_262 ) ;
int V_4 = V_761 & 0xff ;
F_456 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_457 ( struct V_7 * V_8 )
{
unsigned long V_761 = F_99 ( V_262 ) ;
T_2 V_301 = V_761 & 0xfff ;
F_458 ( V_8 , V_301 ) ;
return 1 ;
}
static int F_459 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
unsigned long V_761 ;
bool V_263 = false ;
T_2 V_264 = 0 ;
T_4 V_791 ;
int V_792 , type , V_793 , V_794 ;
V_793 = ( V_74 -> V_737 & V_741 ) ;
V_794 = ( V_74 -> V_737 & V_795 ) ;
type = ( V_74 -> V_737 & V_796 ) ;
V_761 = F_99 ( V_262 ) ;
V_792 = ( T_2 ) V_761 >> 30 ;
if ( V_792 == V_797 && V_793 ) {
switch ( type ) {
case V_708 :
V_8 -> V_117 . V_798 = false ;
F_372 ( V_8 , true ) ;
break;
case V_28 :
case V_703 :
F_460 ( V_8 ) ;
break;
case V_24 :
if ( V_74 -> V_737 &
V_799 ) {
V_263 = true ;
V_264 =
F_101 ( V_800 ) ;
}
case V_273 :
F_461 ( V_8 ) ;
break;
default:
break;
}
}
V_791 = V_761 ;
if ( ! V_793 || ( type != V_24 &&
type != V_28 &&
type != V_708 ) )
F_182 ( V_8 ) ;
if ( F_462 ( V_8 , V_791 ,
type == V_703 ? V_794 : - 1 , V_792 ,
V_263 , V_264 ) == V_801 ) {
V_8 -> V_730 -> V_260 = V_743 ;
V_8 -> V_730 -> V_744 . V_745 = V_802 ;
V_8 -> V_730 -> V_744 . V_747 = 0 ;
return 0 ;
}
F_106 ( V_753 , F_99 ( V_753 ) & ~ 0x155 ) ;
return 1 ;
}
static int F_463 ( struct V_7 * V_8 )
{
unsigned long V_761 ;
T_1 V_86 ;
T_2 V_264 ;
int V_803 ;
V_761 = F_99 ( V_262 ) ;
V_803 = ( V_761 >> 7 ) & 0x3 ;
if ( V_803 != 0x3 && V_803 != 0x1 && V_803 != 0 ) {
F_76 ( V_90 L_20 ) ;
F_76 ( V_90 L_21 ,
( long unsigned int ) F_102 ( V_804 ) ,
F_99 ( V_805 ) ) ;
F_76 ( V_90 L_22 ,
( long unsigned int ) V_761 ) ;
V_8 -> V_730 -> V_260 = V_806 ;
V_8 -> V_730 -> V_807 . V_808 = V_809 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_737 & V_741 ) &&
F_52 () &&
( V_761 & V_810 ) )
F_112 ( V_252 , V_709 ) ;
V_86 = F_102 ( V_804 ) ;
F_387 ( V_86 , V_761 ) ;
V_264 = V_761 & V_811 ;
V_264 |= ( V_761 << 2 ) & V_812 ;
V_264 |= ( V_761 >> 3 ) & V_813 ;
V_8 -> V_117 . V_761 = V_761 ;
return F_390 ( V_8 , V_86 , V_264 , NULL , 0 ) ;
}
static T_3 F_464 ( T_3 V_814 , int V_815 )
{
int V_76 ;
T_3 V_106 = 0 ;
for ( V_76 = 51 ; V_76 > V_455 . V_816 ; V_76 -- )
V_106 |= ( 1ULL << V_76 ) ;
if ( V_815 == 4 )
V_106 |= 0xf8 ;
else if ( V_814 & ( 1ULL << 7 ) )
V_106 |= ( V_450 << ( ( V_815 - 1 ) * 9 ) ) - V_450 ;
else if ( V_815 > 1 )
V_106 |= 0x78 ;
return V_106 ;
}
static void F_465 ( struct V_7 * V_8 , T_3 V_814 ,
int V_815 )
{
F_76 ( V_90 L_23 , V_504 , V_814 , V_815 ) ;
F_325 ( ( V_814 & 0x7 ) == 0x2 ) ;
F_325 ( ( V_814 & 0x7 ) == 0x6 ) ;
if ( ! F_36 () )
F_325 ( ( V_814 & 0x7 ) == 0x4 ) ;
if ( ( V_814 & 0x7 ) ) {
T_3 V_817 = V_814 & F_464 ( V_814 , V_815 ) ;
if ( V_817 != 0 ) {
F_76 ( V_90 L_24 ,
V_504 , V_817 ) ;
F_325 ( 1 ) ;
}
if ( ( V_817 & 0x38 ) == 0 ) {
T_3 V_818 = ( V_814 & 0x38 ) >> 3 ;
if ( V_818 == 2 || V_818 == 3 ||
V_818 == 7 ) {
F_76 ( V_90 L_25 ,
V_504 , V_818 ) ;
F_325 ( 1 ) ;
}
}
}
}
static int F_466 ( struct V_7 * V_8 )
{
T_3 V_819 [ 4 ] ;
int V_820 , V_76 , V_115 ;
T_1 V_86 ;
V_86 = F_102 ( V_804 ) ;
if ( ! F_467 ( V_8 -> V_18 , V_821 , V_86 , 0 , NULL ) ) {
F_182 ( V_8 ) ;
return 1 ;
}
V_115 = F_468 ( V_8 , V_86 , true ) ;
if ( F_308 ( V_115 == V_822 ) )
return F_469 ( V_8 , V_86 , 0 , NULL , 0 ) ==
V_270 ;
if ( F_107 ( V_115 == V_823 ) )
return F_390 ( V_8 , V_86 , 0 , NULL , 0 ) ;
if ( F_107 ( V_115 == V_824 ) )
return 1 ;
F_76 ( V_90 L_26 ) ;
F_76 ( V_90 L_27 , V_86 ) ;
V_820 = F_470 ( V_8 , V_86 , V_819 ) ;
for ( V_76 = V_825 ; V_76 > V_825 - V_820 ; -- V_76 )
F_465 ( V_8 , V_819 [ V_76 - 1 ] , V_76 ) ;
V_8 -> V_730 -> V_260 = V_806 ;
V_8 -> V_730 -> V_807 . V_808 = V_826 ;
return 0 ;
}
static int F_471 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_101 ( V_522 ) ;
V_69 &= ~ V_343 ;
F_109 ( V_522 , V_69 ) ;
++ V_8 -> V_218 . V_827 ;
F_163 ( V_612 , V_8 ) ;
return 1 ;
}
static int F_472 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
enum V_735 V_769 = V_270 ;
int V_115 = 1 ;
T_2 V_828 ;
bool V_829 ;
unsigned V_830 = 130 ;
V_828 = F_101 ( V_522 ) ;
V_829 = V_828 & V_342 ;
while ( V_74 -> F_257 && V_830 -- != 0 ) {
if ( V_829 && F_374 ( V_8 ) )
return F_435 ( & V_74 -> V_8 ) ;
if ( F_177 ( V_612 , & V_8 -> V_831 ) )
return 1 ;
V_769 = F_379 ( V_8 , V_832 ) ;
if ( V_769 == V_833 ) {
++ V_8 -> V_218 . V_834 ;
V_115 = 0 ;
goto V_546;
}
if ( V_769 != V_270 ) {
V_8 -> V_730 -> V_260 = V_743 ;
V_8 -> V_730 -> V_744 . V_745 = V_802 ;
V_8 -> V_730 -> V_744 . V_747 = 0 ;
return 0 ;
}
if ( V_8 -> V_117 . V_726 ) {
V_8 -> V_117 . V_726 = 0 ;
V_115 = F_380 ( V_8 ) ;
goto V_546;
}
if ( F_473 ( V_835 ) )
goto V_546;
if ( F_474 () )
F_475 () ;
}
V_546:
return V_115 ;
}
static int F_476 ( int V_107 )
{
if ( V_836 < 1 )
return V_659 ;
V_107 = V_441 ( V_107 , V_837 ) ;
if ( V_836 < V_659 )
V_107 *= V_836 ;
else
V_107 += V_836 ;
return V_107 ;
}
static int F_477 ( int V_107 , int V_838 , int V_839 )
{
if ( V_838 < 1 )
return V_659 ;
if ( V_838 < V_659 )
V_107 /= V_838 ;
else
V_107 -= V_838 ;
return F_478 ( V_107 , V_839 ) ;
}
static void F_479 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_428 = V_74 -> V_659 ;
V_74 -> V_659 = F_476 ( V_428 ) ;
if ( V_74 -> V_659 != V_428 )
V_74 -> V_660 = true ;
F_480 ( V_8 -> V_303 , V_74 -> V_659 , V_428 ) ;
}
static void F_481 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_428 = V_74 -> V_659 ;
V_74 -> V_659 = F_477 ( V_428 ,
V_840 , V_659 ) ;
if ( V_74 -> V_659 != V_428 )
V_74 -> V_660 = true ;
F_482 ( V_8 -> V_303 , V_74 -> V_659 , V_428 ) ;
}
static void F_483 ( void )
{
V_837 =
F_477 ( F_478 ( V_841 , V_659 ) ,
V_836 , V_842 ) ;
}
static T_11 int F_484 ( void )
{
int V_564 = - V_469 , V_76 , V_75 ;
F_485 ( V_145 , & V_183 ) ;
for ( V_76 = 0 ; V_76 < F_10 ( V_78 ) ; ++ V_76 )
F_486 ( V_76 , V_78 [ V_76 ] ) ;
V_643 = ( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_643 )
return V_564 ;
V_645 = ( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_645 )
goto V_546;
V_284 = ( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_284 )
goto V_843;
V_282 =
( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_282 )
goto V_572;
V_283 = ( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_283 )
goto V_844;
V_281 =
( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_281 )
goto V_845;
if ( V_14 ) {
V_279 =
( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_279 )
goto V_846;
}
V_466 = ( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_466 )
goto V_847;
V_465 = ( unsigned long * ) F_487 ( V_461 ) ;
if ( ! V_465 )
goto V_848;
memset ( V_466 , 0xff , V_450 ) ;
memset ( V_465 , 0xff , V_450 ) ;
memset ( V_643 , 0xff , V_450 ) ;
F_255 ( 0x80 , V_643 ) ;
memset ( V_645 , 0xff , V_450 ) ;
memset ( V_284 , 0xff , V_450 ) ;
memset ( V_283 , 0xff , V_450 ) ;
if ( V_14 )
memset ( V_279 , 0xff , V_450 ) ;
if ( F_242 ( & V_30 ) < 0 ) {
V_564 = - V_439 ;
goto V_849;
}
if ( F_149 ( V_850 ) )
F_488 ( V_179 ) ;
if ( ! F_49 () )
V_590 = 0 ;
if ( ! F_54 () )
V_646 = 0 ;
if ( V_646 )
F_254 () ;
if ( ! F_45 () ||
! F_39 () ) {
V_102 = 0 ;
V_365 = 0 ;
V_531 = 0 ;
}
if ( ! F_40 () )
V_531 = 0 ;
if ( ! F_46 () )
V_365 = 0 ;
if ( ! F_35 () )
V_57 = 0 ;
if ( ! V_57 )
V_851 -> V_852 = NULL ;
if ( ! F_25 () )
V_851 -> V_853 = NULL ;
if ( V_102 && ! F_37 () )
F_489 () ;
if ( ! F_47 () )
V_640 = 0 ;
if ( ! F_34 () )
V_600 = 0 ;
if ( V_600 )
V_851 -> V_853 = NULL ;
else {
V_851 -> V_854 = NULL ;
V_851 -> V_855 = NULL ;
V_851 -> V_856 = NULL ;
V_851 -> V_857 = F_343 ;
}
F_326 ( V_208 , false ) ;
F_326 ( V_210 , false ) ;
F_326 ( V_211 , true ) ;
F_326 ( V_396 , false ) ;
F_326 ( V_228 , false ) ;
F_326 ( V_398 , false ) ;
F_326 ( V_215 , true ) ;
memcpy ( V_282 ,
V_284 , V_450 ) ;
memcpy ( V_281 ,
V_283 , V_450 ) ;
if ( V_600 ) {
for ( V_75 = 0x800 ; V_75 <= 0x8ff ; V_75 ++ )
F_328 ( V_75 ) ;
F_327 ( 0x802 ) ;
F_327 ( 0x839 ) ;
F_329 ( 0x808 ) ;
F_329 ( 0x80b ) ;
F_329 ( 0x83f ) ;
}
if ( V_102 ) {
F_490 ( 0ull ,
( V_531 ) ? V_858 : 0ull ,
( V_531 ) ? V_859 : 0ull ,
0ull , V_860 ) ;
F_352 () ;
F_491 () ;
} else
F_492 () ;
F_483 () ;
if ( ! V_102 || ! V_531 || ! F_56 () )
V_861 = 0 ;
if ( ! V_861 ) {
V_851 -> V_862 = NULL ;
V_851 -> V_863 = NULL ;
V_851 -> V_864 = NULL ;
V_851 -> V_865 = NULL ;
}
return F_256 () ;
V_849:
F_493 ( ( unsigned long ) V_465 ) ;
V_848:
F_493 ( ( unsigned long ) V_466 ) ;
V_847:
if ( V_14 )
F_493 ( ( unsigned long ) V_279 ) ;
V_846:
F_493 ( ( unsigned long ) V_281 ) ;
V_845:
F_493 ( ( unsigned long ) V_283 ) ;
V_844:
F_493 ( ( unsigned long ) V_282 ) ;
V_572:
F_493 ( ( unsigned long ) V_284 ) ;
V_843:
F_493 ( ( unsigned long ) V_645 ) ;
V_546:
F_493 ( ( unsigned long ) V_643 ) ;
return V_564 ;
}
static T_15 void F_494 ( void )
{
F_493 ( ( unsigned long ) V_282 ) ;
F_493 ( ( unsigned long ) V_281 ) ;
F_493 ( ( unsigned long ) V_284 ) ;
F_493 ( ( unsigned long ) V_283 ) ;
F_493 ( ( unsigned long ) V_645 ) ;
F_493 ( ( unsigned long ) V_643 ) ;
F_493 ( ( unsigned long ) V_465 ) ;
F_493 ( ( unsigned long ) V_466 ) ;
if ( V_14 )
F_493 ( ( unsigned long ) V_279 ) ;
F_252 () ;
}
static int F_495 ( struct V_7 * V_8 )
{
if ( V_640 )
F_479 ( V_8 ) ;
F_182 ( V_8 ) ;
F_496 ( V_8 ) ;
return 1 ;
}
static int F_497 ( struct V_7 * V_8 )
{
F_182 ( V_8 ) ;
return 1 ;
}
static int F_498 ( struct V_7 * V_8 )
{
F_135 ( V_167 L_28 ) ;
return F_497 ( V_8 ) ;
}
static int F_499 ( struct V_7 * V_8 )
{
F_135 ( V_167 L_29 ) ;
return F_497 ( V_8 ) ;
}
static struct V_91 * F_500 ( struct V_6 * V_74 )
{
struct V_866 * V_867 ;
F_87 (item, &vmx->nested.vmcs02_pool, list)
if ( V_867 -> V_868 == V_74 -> V_14 . V_869 ) {
F_501 ( & V_867 -> V_870 , & V_74 -> V_14 . V_871 ) ;
return & V_867 -> V_872 ;
}
if ( V_74 -> V_14 . V_873 >= F_478 ( V_874 , 1 ) ) {
V_867 = F_502 ( V_74 -> V_14 . V_871 . V_875 ,
struct V_866 , V_870 ) ;
V_867 -> V_868 = V_74 -> V_14 . V_869 ;
F_501 ( & V_867 -> V_870 , & V_74 -> V_14 . V_871 ) ;
return & V_867 -> V_872 ;
}
V_867 = F_503 ( sizeof( struct V_866 ) , V_461 ) ;
if ( ! V_867 )
return NULL ;
V_867 -> V_872 . V_88 = F_248 () ;
if ( ! V_867 -> V_872 . V_88 ) {
F_504 ( V_867 ) ;
return NULL ;
}
F_77 ( & V_867 -> V_872 ) ;
V_867 -> V_868 = V_74 -> V_14 . V_869 ;
F_166 ( & ( V_867 -> V_870 ) , & ( V_74 -> V_14 . V_871 ) ) ;
V_74 -> V_14 . V_873 ++ ;
return & V_867 -> V_872 ;
}
static void F_505 ( struct V_6 * V_74 , T_1 V_868 )
{
struct V_866 * V_867 ;
F_87 (item, &vmx->nested.vmcs02_pool, list)
if ( V_867 -> V_868 == V_868 ) {
F_251 ( & V_867 -> V_872 ) ;
F_90 ( & V_867 -> V_870 ) ;
F_504 ( V_867 ) ;
V_74 -> V_14 . V_873 -- ;
return;
}
}
static void F_506 ( struct V_6 * V_74 )
{
struct V_866 * V_867 , * V_432 ;
F_325 ( V_74 -> V_91 != & V_74 -> V_876 ) ;
F_237 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_74 -> V_91 == & V_867 -> V_872 )
continue;
F_251 ( & V_867 -> V_872 ) ;
F_90 ( & V_867 -> V_870 ) ;
F_504 ( V_867 ) ;
V_74 -> V_14 . V_873 -- ;
}
}
static void F_507 ( struct V_7 * V_8 )
{
F_179 ( V_8 , F_176 ( V_8 )
& ~ ( V_877 | V_878 | V_879 |
V_880 | V_881 | V_882 ) ) ;
}
static void F_508 ( struct V_7 * V_8 )
{
F_179 ( V_8 , ( F_176 ( V_8 )
& ~ ( V_878 | V_879 | V_880 |
V_881 | V_882 ) )
| V_877 ) ;
}
static void F_509 ( struct V_7 * V_8 ,
T_2 V_883 )
{
if ( F_6 ( V_8 ) -> V_14 . V_869 == - 1ull ) {
F_508 ( V_8 ) ;
return;
}
F_179 ( V_8 , ( F_176 ( V_8 )
& ~ ( V_877 | V_878 | V_879 |
V_881 | V_882 ) )
| V_880 ) ;
F_11 ( V_8 ) -> V_883 = V_883 ;
}
static void F_510 ( struct V_7 * V_8 , T_2 V_884 )
{
F_163 ( V_271 , V_8 ) ;
F_511 ( L_30 , V_884 ) ;
}
static enum V_885 F_512 ( struct V_886 * V_887 )
{
struct V_6 * V_74 =
F_7 ( V_887 , struct V_6 , V_14 . V_888 ) ;
V_74 -> V_14 . V_889 = true ;
F_163 ( V_612 , & V_74 -> V_8 ) ;
F_340 ( & V_74 -> V_8 ) ;
return V_890 ;
}
static int F_513 ( struct V_7 * V_8 ,
unsigned long V_761 ,
T_2 V_891 , T_5 * V_115 )
{
int V_892 = V_891 & 3 ;
int V_893 = ( V_891 >> 7 ) & 7 ;
bool V_894 = V_891 & ( 1u << 10 ) ;
int V_895 = ( V_891 >> 15 ) & 7 ;
int V_896 = ( V_891 >> 18 ) & 0xf ;
bool V_897 = ! ( V_891 & ( 1u << 22 ) ) ;
int V_898 = ( V_891 >> 23 ) & 0xf ;
bool V_899 = ! ( V_891 & ( 1u << 27 ) ) ;
if ( V_894 ) {
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
* V_115 = F_285 ( V_8 , V_895 ) ;
if ( V_899 )
* V_115 += F_449 ( V_8 , V_898 ) ;
if ( V_897 )
* V_115 += F_449 ( V_8 , V_896 ) << V_892 ;
* V_115 += V_761 ;
if ( V_893 == 1 )
* V_115 &= 0xffffffff ;
return 0 ;
}
static int F_514 ( struct V_7 * V_8 , int V_260 ,
T_1 * V_900 )
{
T_5 V_82 ;
T_1 V_868 ;
struct V_901 V_902 ;
struct V_16 * V_16 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_903 = F_515 ( V_8 ) ;
if ( F_513 ( V_8 , F_99 ( V_262 ) ,
F_101 ( V_904 ) , & V_82 ) )
return 1 ;
if ( F_516 ( & V_8 -> V_117 . V_905 , V_82 , & V_868 ,
sizeof( V_868 ) , & V_902 ) ) {
F_517 ( V_8 , & V_902 ) ;
return 1 ;
}
switch ( V_260 ) {
case V_906 :
if ( ! F_518 ( V_868 ) || ( V_868 >> V_903 ) ) {
F_508 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
V_16 = F_12 ( V_8 , V_868 ) ;
if ( V_16 == NULL ||
* ( T_2 * ) F_332 ( V_16 ) != V_376 ) {
F_508 ( V_8 ) ;
F_334 ( V_16 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
F_334 ( V_16 ) ;
V_74 -> V_14 . V_907 = V_868 ;
break;
case V_908 :
if ( ! F_518 ( V_868 ) || ( V_868 >> V_903 ) ) {
F_509 ( V_8 ,
V_909 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
if ( V_868 == V_74 -> V_14 . V_907 ) {
F_509 ( V_8 ,
V_910 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
break;
case V_911 :
if ( ! F_518 ( V_868 ) || ( V_868 >> V_903 ) ) {
F_509 ( V_8 ,
V_912 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
if ( V_868 == V_74 -> V_14 . V_907 ) {
F_509 ( V_8 ,
V_910 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
break;
default:
return 1 ;
}
if ( V_900 )
* V_900 = V_868 ;
return 0 ;
}
static int F_519 ( struct V_7 * V_8 )
{
struct V_471 V_552 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_88 * V_913 ;
const T_3 V_914 = V_414
| V_427 ;
if ( ! F_520 ( V_8 , V_430 ) ||
! F_171 ( V_8 , V_527 ) ||
( F_176 ( V_8 ) & V_250 ) ) {
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
F_262 ( V_8 , & V_552 , V_473 ) ;
if ( F_147 ( V_8 ) && ! V_552 . V_493 ) {
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
if ( F_286 ( V_8 ) ) {
F_428 ( V_8 , 0 ) ;
return 1 ;
}
if ( F_514 ( V_8 , V_906 , NULL ) )
return 1 ;
if ( V_74 -> V_14 . V_540 ) {
F_509 ( V_8 , V_915 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
if ( ( V_74 -> V_14 . V_403 & V_914 )
!= V_914 ) {
F_428 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_646 ) {
V_913 = F_248 () ;
if ( ! V_913 )
return - V_469 ;
V_913 -> V_453 |= ( 1u << 31 ) ;
F_74 ( V_913 ) ;
V_74 -> V_14 . V_916 = V_913 ;
}
F_233 ( & ( V_74 -> V_14 . V_871 ) ) ;
V_74 -> V_14 . V_873 = 0 ;
F_521 ( & V_74 -> V_14 . V_888 , V_917 ,
V_918 ) ;
V_74 -> V_14 . V_888 . V_919 = F_512 ;
V_74 -> V_14 . V_540 = true ;
F_182 ( V_8 ) ;
F_507 ( V_8 ) ;
return 1 ;
}
static int F_522 ( struct V_7 * V_8 )
{
struct V_471 V_552 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( ! V_74 -> V_14 . V_540 ) {
F_381 ( V_8 , V_27 ) ;
return 0 ;
}
F_262 ( V_8 , & V_552 , V_473 ) ;
if ( ( F_176 ( V_8 ) & V_250 ) ||
( F_147 ( V_8 ) && ! V_552 . V_493 ) ) {
F_381 ( V_8 , V_27 ) ;
return 0 ;
}
if ( F_286 ( V_8 ) ) {
F_428 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_523 ( struct V_6 * V_74 )
{
T_2 V_637 ;
if ( V_74 -> V_14 . V_869 == - 1ull )
return;
if ( F_325 ( V_74 -> V_14 . V_15 == NULL ) )
return;
if ( V_646 ) {
F_524 ( V_74 ) ;
V_74 -> V_14 . V_920 = false ;
V_637 = F_101 ( V_651 ) ;
V_637 &= ~ V_66 ;
F_109 ( V_651 , V_637 ) ;
F_110 ( V_649 , - 1ull ) ;
}
V_74 -> V_14 . V_611 = - 1 ;
F_334 ( V_74 -> V_14 . V_921 ) ;
F_15 ( V_74 -> V_14 . V_921 ) ;
V_74 -> V_14 . V_869 = - 1ull ;
V_74 -> V_14 . V_15 = NULL ;
}
static void F_525 ( struct V_6 * V_74 )
{
if ( ! V_74 -> V_14 . V_540 )
return;
V_74 -> V_14 . V_540 = false ;
F_523 ( V_74 ) ;
if ( V_646 )
F_249 ( V_74 -> V_14 . V_916 ) ;
if ( V_74 -> V_14 . V_922 ) {
F_15 ( V_74 -> V_14 . V_922 ) ;
V_74 -> V_14 . V_922 = NULL ;
}
if ( V_74 -> V_14 . V_605 ) {
F_15 ( V_74 -> V_14 . V_605 ) ;
V_74 -> V_14 . V_605 = NULL ;
}
if ( V_74 -> V_14 . V_923 ) {
F_334 ( V_74 -> V_14 . V_923 ) ;
F_15 ( V_74 -> V_14 . V_923 ) ;
V_74 -> V_14 . V_923 = NULL ;
V_74 -> V_14 . V_1 = NULL ;
}
F_506 ( V_74 ) ;
}
static int F_526 ( struct V_7 * V_8 )
{
if ( ! F_522 ( V_8 ) )
return 1 ;
F_525 ( F_6 ( V_8 ) ) ;
F_182 ( V_8 ) ;
F_507 ( V_8 ) ;
return 1 ;
}
static int F_527 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_1 V_868 ;
struct V_13 * V_13 ;
struct V_16 * V_16 ;
if ( ! F_522 ( V_8 ) )
return 1 ;
if ( F_514 ( V_8 , V_908 , & V_868 ) )
return 1 ;
if ( V_868 == V_74 -> V_14 . V_869 )
F_523 ( V_74 ) ;
V_16 = F_12 ( V_8 , V_868 ) ;
if ( V_16 == NULL ) {
F_163 ( V_271 , V_8 ) ;
return 1 ;
}
V_13 = F_332 ( V_16 ) ;
V_13 -> V_924 = 0 ;
F_334 ( V_16 ) ;
F_15 ( V_16 ) ;
F_505 ( V_74 , V_868 ) ;
F_182 ( V_8 ) ;
F_507 ( V_8 ) ;
return 1 ;
}
static int F_528 ( struct V_7 * V_8 )
{
return F_529 ( V_8 , true ) ;
}
static int F_530 ( struct V_7 * V_8 )
{
return F_529 ( V_8 , false ) ;
}
static inline int F_531 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_925 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_532 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline int F_533 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_115 )
{
short V_301 = F_8 ( V_9 ) ;
char * V_120 ;
if ( V_301 < 0 )
return V_301 ;
V_120 = ( ( char * ) ( F_11 ( V_8 ) ) ) + V_301 ;
switch ( F_531 ( V_9 ) ) {
case V_926 :
* V_115 = * ( ( V_927 * ) V_120 ) ;
return 0 ;
case V_928 :
* V_115 = * ( ( T_4 * ) V_120 ) ;
return 0 ;
case V_925 :
* V_115 = * ( ( T_2 * ) V_120 ) ;
return 0 ;
case V_929 :
* V_115 = * ( ( T_3 * ) V_120 ) ;
return 0 ;
default:
F_325 ( 1 ) ;
return - V_12 ;
}
}
static inline int F_534 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_930 ) {
short V_301 = F_8 ( V_9 ) ;
char * V_120 = ( ( char * ) F_11 ( V_8 ) ) + V_301 ;
if ( V_301 < 0 )
return V_301 ;
switch ( F_531 ( V_9 ) ) {
case V_928 :
* ( T_4 * ) V_120 = V_930 ;
return 0 ;
case V_925 :
* ( T_2 * ) V_120 = V_930 ;
return 0 ;
case V_929 :
* ( T_3 * ) V_120 = V_930 ;
return 0 ;
case V_926 :
* ( V_927 * ) V_120 = V_930 ;
return 0 ;
default:
F_325 ( 1 ) ;
return - V_12 ;
}
}
static void F_524 ( struct V_6 * V_74 )
{
int V_76 ;
unsigned long V_9 ;
T_3 V_930 ;
struct V_88 * V_913 = V_74 -> V_14 . V_916 ;
const unsigned long * V_237 = V_464 ;
const int V_931 = V_463 ;
F_159 () ;
F_78 ( V_913 ) ;
for ( V_76 = 0 ; V_76 < V_931 ; V_76 ++ ) {
V_9 = V_237 [ V_76 ] ;
switch ( F_531 ( V_9 ) ) {
case V_928 :
V_930 = F_100 ( V_9 ) ;
break;
case V_925 :
V_930 = F_101 ( V_9 ) ;
break;
case V_929 :
V_930 = F_102 ( V_9 ) ;
break;
case V_926 :
V_930 = F_99 ( V_9 ) ;
break;
default:
F_325 ( 1 ) ;
continue;
}
F_534 ( & V_74 -> V_8 , V_9 , V_930 ) ;
}
F_74 ( V_913 ) ;
F_78 ( V_74 -> V_91 -> V_88 ) ;
F_160 () ;
}
static void F_535 ( struct V_6 * V_74 )
{
const unsigned long * V_237 [] = {
V_464 ,
V_468
} ;
const int V_932 [] = {
V_463 ,
V_467
} ;
int V_76 , V_933 ;
unsigned long V_9 ;
T_3 V_930 = 0 ;
struct V_88 * V_913 = V_74 -> V_14 . V_916 ;
F_78 ( V_913 ) ;
for ( V_933 = 0 ; V_933 < F_10 ( V_237 ) ; V_933 ++ ) {
for ( V_76 = 0 ; V_76 < V_932 [ V_933 ] ; V_76 ++ ) {
V_9 = V_237 [ V_933 ] [ V_76 ] ;
F_533 ( & V_74 -> V_8 , V_9 , & V_930 ) ;
switch ( F_531 ( V_9 ) ) {
case V_928 :
F_108 ( V_9 , ( T_4 ) V_930 ) ;
break;
case V_925 :
F_109 ( V_9 , ( T_2 ) V_930 ) ;
break;
case V_929 :
F_110 ( V_9 , ( T_3 ) V_930 ) ;
break;
case V_926 :
F_106 ( V_9 , ( long ) V_930 ) ;
break;
default:
F_325 ( 1 ) ;
break;
}
}
}
F_74 ( V_913 ) ;
F_78 ( V_74 -> V_91 -> V_88 ) ;
}
static int F_536 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( V_74 -> V_14 . V_869 == - 1ull ) {
F_508 ( V_8 ) ;
F_182 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_537 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_930 ;
unsigned long V_761 = F_99 ( V_262 ) ;
T_2 V_891 = F_101 ( V_904 ) ;
T_5 V_82 = 0 ;
if ( ! F_522 ( V_8 ) ||
! F_536 ( V_8 ) )
return 1 ;
V_9 = F_403 ( V_8 , ( ( ( V_891 ) >> 28 ) & 0xf ) ) ;
if ( F_533 ( V_8 , V_9 , & V_930 ) < 0 ) {
F_509 ( V_8 , V_934 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
if ( V_891 & ( 1u << 10 ) ) {
F_538 ( V_8 , ( ( ( V_891 ) >> 3 ) & 0xf ) ,
V_930 ) ;
} else {
if ( F_513 ( V_8 , V_761 ,
V_891 , & V_82 ) )
return 1 ;
F_539 ( & V_8 -> V_117 . V_905 , V_82 ,
& V_930 , ( F_147 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_507 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_540 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_82 ;
unsigned long V_761 = F_99 ( V_262 ) ;
T_2 V_891 = F_101 ( V_904 ) ;
T_3 V_930 = 0 ;
struct V_901 V_902 ;
if ( ! F_522 ( V_8 ) ||
! F_536 ( V_8 ) )
return 1 ;
if ( V_891 & ( 1u << 10 ) )
V_930 = F_403 ( V_8 ,
( ( ( V_891 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_513 ( V_8 , V_761 ,
V_891 , & V_82 ) )
return 1 ;
if ( F_516 ( & V_8 -> V_117 . V_905 , V_82 ,
& V_930 , ( F_541 ( V_8 ) ? 8 : 4 ) , & V_902 ) ) {
F_517 ( V_8 , & V_902 ) ;
return 1 ;
}
}
V_9 = F_403 ( V_8 , ( ( ( V_891 ) >> 28 ) & 0xf ) ) ;
if ( F_532 ( V_9 ) ) {
F_509 ( V_8 ,
V_935 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
if ( F_534 ( V_8 , V_9 , V_930 ) < 0 ) {
F_509 ( V_8 , V_934 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
F_507 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_542 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_1 V_868 ;
T_2 V_637 ;
if ( ! F_522 ( V_8 ) )
return 1 ;
if ( F_514 ( V_8 , V_911 , & V_868 ) )
return 1 ;
if ( V_74 -> V_14 . V_869 != V_868 ) {
struct V_13 * V_936 ;
struct V_16 * V_16 ;
V_16 = F_12 ( V_8 , V_868 ) ;
if ( V_16 == NULL ) {
F_508 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
V_936 = F_332 ( V_16 ) ;
if ( V_936 -> V_453 != V_376 ) {
F_334 ( V_16 ) ;
F_17 ( V_16 ) ;
F_509 ( V_8 ,
V_937 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
F_523 ( V_74 ) ;
V_74 -> V_14 . V_869 = V_868 ;
V_74 -> V_14 . V_15 = V_936 ;
V_74 -> V_14 . V_921 = V_16 ;
if ( V_646 ) {
V_637 = F_101 ( V_651 ) ;
V_637 |= V_66 ;
F_109 ( V_651 , V_637 ) ;
F_110 ( V_649 ,
F_75 ( V_74 -> V_14 . V_916 ) ) ;
V_74 -> V_14 . V_920 = true ;
}
}
F_507 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_543 ( struct V_7 * V_8 )
{
unsigned long V_761 = F_99 ( V_262 ) ;
T_2 V_891 = F_101 ( V_904 ) ;
T_5 V_938 ;
struct V_901 V_902 ;
if ( ! F_522 ( V_8 ) )
return 1 ;
if ( F_513 ( V_8 , V_761 ,
V_891 , & V_938 ) )
return 1 ;
if ( F_539 ( & V_8 -> V_117 . V_905 , V_938 ,
( void * ) & F_6 ( V_8 ) -> V_14 . V_869 ,
sizeof( T_3 ) , & V_902 ) ) {
F_517 ( V_8 , & V_902 ) ;
return 1 ;
}
F_507 ( V_8 ) ;
F_182 ( V_8 ) ;
return 1 ;
}
static int F_544 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_2 V_891 , V_939 ;
unsigned long type ;
T_5 V_82 ;
struct V_901 V_902 ;
struct {
T_3 V_85 , V_86 ;
} V_84 ;
if ( ! ( V_74 -> V_14 . V_361 &
V_54 ) ||
! ( V_74 -> V_14 . V_362 & V_364 ) ) {
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
if ( ! F_522 ( V_8 ) )
return 1 ;
if ( ! F_171 ( V_8 , V_527 ) ) {
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
V_891 = F_101 ( V_904 ) ;
type = F_403 ( V_8 , ( V_891 >> 28 ) & 0xf ) ;
V_939 = ( V_74 -> V_14 . V_362 >> V_940 ) & 6 ;
if ( ! ( V_939 & ( 1UL << type ) ) ) {
F_509 ( V_8 ,
V_941 ) ;
return 1 ;
}
if ( F_513 ( V_8 , F_99 ( V_262 ) ,
V_891 , & V_82 ) )
return 1 ;
if ( F_516 ( & V_8 -> V_117 . V_905 , V_82 , & V_84 ,
sizeof( V_84 ) , & V_902 ) ) {
F_517 ( V_8 , & V_902 ) ;
return 1 ;
}
switch ( type ) {
case V_101 :
F_545 ( V_8 ) ;
F_163 ( V_224 , V_8 ) ;
F_507 ( V_8 ) ;
break;
default:
F_315 ( 1 ) ;
break;
}
F_182 ( V_8 ) ;
return 1 ;
}
static int F_546 ( struct V_7 * V_8 )
{
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
static int F_547 ( struct V_7 * V_8 )
{
unsigned long V_761 ;
F_548 ( V_8 -> V_303 ) ;
V_761 = F_99 ( V_262 ) ;
if ( ! ( F_6 ( V_8 ) -> V_737 & V_741 ) &&
F_52 () &&
( V_761 & V_810 ) )
F_112 ( V_252 ,
V_709 ) ;
return 1 ;
}
static bool F_549 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
unsigned long V_761 ;
T_1 V_942 , V_943 ;
unsigned int V_763 ;
int V_451 ;
T_6 V_944 ;
if ( ! F_58 ( V_13 , V_353 ) )
return F_58 ( V_13 , V_352 ) ;
V_761 = F_99 ( V_262 ) ;
V_763 = V_761 >> 16 ;
V_451 = ( V_761 & 7 ) + 1 ;
V_943 = ( T_1 ) - 1 ;
V_944 = - 1 ;
while ( V_451 > 0 ) {
if ( V_763 < 0x8000 )
V_942 = V_13 -> V_945 ;
else if ( V_763 < 0x10000 )
V_942 = V_13 -> V_946 ;
else
return 1 ;
V_942 += ( V_763 & 0x7fff ) / 8 ;
if ( V_943 != V_942 )
if ( F_550 ( V_8 -> V_18 , V_942 , & V_944 , 1 ) )
return 1 ;
if ( V_944 & ( 1 << ( V_763 & 7 ) ) )
return 1 ;
V_763 ++ ;
V_451 -- ;
V_943 = V_942 ;
}
return 0 ;
}
static bool F_551 ( struct V_7 * V_8 ,
struct V_13 * V_13 , T_2 V_260 )
{
T_2 V_373 = V_8 -> V_117 . V_421 [ V_779 ] ;
T_1 V_942 ;
if ( ! F_58 ( V_13 , V_32 ) )
return 1 ;
V_942 = V_13 -> V_278 ;
if ( V_260 == V_947 )
V_942 += 2048 ;
if ( V_373 >= 0xc0000000 ) {
V_373 -= 0xc0000000 ;
V_942 += 1024 ;
}
if ( V_373 < 1024 * 8 ) {
unsigned char V_944 ;
if ( F_550 ( V_8 -> V_18 , V_942 + V_373 / 8 , & V_944 , 1 ) )
return 1 ;
return 1 & ( V_944 >> ( V_373 & 7 ) ) ;
} else
return 1 ;
}
static bool F_552 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
unsigned long V_761 = F_99 ( V_262 ) ;
int V_768 = V_761 & 15 ;
int V_419 = ( V_761 >> 8 ) & 15 ;
unsigned long V_107 = F_403 ( V_8 , V_419 ) ;
switch ( ( V_761 >> 4 ) & 3 ) {
case 0 :
switch ( V_768 ) {
case 0 :
if ( V_13 -> V_235 &
( V_107 ^ V_13 -> V_239 ) )
return 1 ;
break;
case 3 :
if ( ( V_13 -> V_948 >= 1 &&
V_13 -> V_949 == V_107 ) ||
( V_13 -> V_948 >= 2 &&
V_13 -> V_950 == V_107 ) ||
( V_13 -> V_948 >= 3 &&
V_13 -> V_951 == V_107 ) ||
( V_13 -> V_948 >= 4 &&
V_13 -> V_952 == V_107 ) )
return 0 ;
if ( F_58 ( V_13 , V_347 ) )
return 1 ;
break;
case 4 :
if ( V_13 -> V_241 &
( V_13 -> V_242 ^ V_107 ) )
return 1 ;
break;
case 8 :
if ( F_58 ( V_13 , V_349 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_13 -> V_235 & V_232 ) &&
( V_13 -> V_239 & V_232 ) )
return 1 ;
break;
case 1 :
switch ( V_768 ) {
case 3 :
if ( V_13 -> V_69 &
V_348 )
return 1 ;
break;
case 8 :
if ( V_13 -> V_69 &
V_350 )
return 1 ;
break;
}
break;
case 3 :
if ( V_13 -> V_235 & 0xe &
( V_107 ^ V_13 -> V_239 ) )
return 1 ;
if ( ( V_13 -> V_235 & 0x1 ) &&
! ( V_13 -> V_239 & 0x1 ) &&
( V_107 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_553 ( struct V_7 * V_8 )
{
T_2 V_20 = F_101 ( V_261 ) ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_13 * V_13 = F_11 ( V_8 ) ;
T_2 V_260 = V_74 -> V_260 ;
F_554 ( F_183 ( V_8 ) , V_260 ,
F_99 ( V_262 ) ,
V_74 -> V_737 ,
V_20 ,
F_101 ( V_740 ) ,
V_953 ) ;
if ( V_74 -> V_14 . V_711 )
return 0 ;
if ( F_107 ( V_74 -> V_954 ) ) {
F_555 ( L_31 , V_504 ,
F_101 ( V_105 ) ) ;
return 1 ;
}
switch ( V_260 ) {
case V_955 :
if ( ! F_69 ( V_20 ) )
return 0 ;
else if ( F_19 ( V_20 ) )
return V_102 ;
else if ( F_20 ( V_20 ) &&
! ( V_13 -> V_238 & V_232 ) )
return 0 ;
return V_13 -> V_140 &
( 1u << ( V_20 & V_22 ) ) ;
case V_956 :
return 0 ;
case V_957 :
return 1 ;
case V_958 :
return F_58 ( V_13 , V_342 ) ;
case V_959 :
return F_58 ( V_13 , V_343 ) ;
case V_960 :
return 1 ;
case V_961 :
if ( F_449 ( V_8 , V_780 ) == 0xa )
return 0 ;
return 1 ;
case V_962 :
return F_58 ( V_13 , V_344 ) ;
case V_963 :
return 1 ;
case V_964 :
return F_58 ( V_13 , V_345 ) ;
case V_965 :
return F_58 ( V_13 , V_355 ) ;
case V_966 :
return F_58 ( V_13 , V_356 ) ;
case V_967 : case V_908 :
case V_968 : case V_911 :
case V_969 : case V_970 :
case V_971 : case V_972 :
case V_973 : case V_906 :
case V_974 : case V_975 :
return 1 ;
case V_976 :
return F_552 ( V_8 , V_13 ) ;
case V_977 :
return F_58 ( V_13 , V_351 ) ;
case V_978 :
return F_549 ( V_8 , V_13 ) ;
case V_979 :
case V_947 :
return F_551 ( V_8 , V_13 , V_260 ) ;
case V_980 :
return 1 ;
case V_981 :
return F_58 ( V_13 , V_346 ) ;
case V_982 :
return F_58 ( V_13 , V_354 ) ;
case V_983 :
return F_58 ( V_13 , V_357 ) ||
F_59 ( V_13 ,
V_56 ) ;
case V_984 :
return 0 ;
case V_985 :
return F_58 ( V_13 , V_33 ) ;
case V_986 :
return F_59 ( V_13 ,
V_36 ) ;
case V_987 :
case V_988 :
return 1 ;
case V_809 :
return 0 ;
case V_826 :
return 0 ;
case V_989 :
return F_59 ( V_13 , V_62 ) ;
case V_990 :
return 1 ;
case V_991 : case V_992 :
return F_59 ( V_13 , V_73 ) ;
default:
return 1 ;
}
}
static void F_556 ( struct V_7 * V_8 , T_3 * V_993 , T_3 * V_994 )
{
* V_993 = F_99 ( V_262 ) ;
* V_994 = F_101 ( V_261 ) ;
}
static int F_557 ( struct V_6 * V_74 )
{
struct V_16 * V_995 ;
T_2 V_637 ;
V_995 = F_558 ( V_461 | V_996 ) ;
if ( ! V_995 )
return - V_469 ;
V_74 -> V_995 = V_995 ;
F_110 ( V_997 , F_559 ( V_74 -> V_995 ) ) ;
F_108 ( V_998 , V_999 - 1 ) ;
V_637 = F_101 ( V_651 ) ;
V_637 |= V_67 ;
F_109 ( V_651 , V_637 ) ;
return 0 ;
}
static void F_560 ( struct V_6 * V_74 )
{
T_2 V_637 ;
ASSERT ( V_74 -> V_995 ) ;
F_561 ( V_74 -> V_995 ) ;
V_74 -> V_995 = NULL ;
V_637 = F_101 ( V_651 ) ;
V_637 &= ~ V_67 ;
F_109 ( V_651 , V_637 ) ;
}
static void F_562 ( struct V_6 * V_74 )
{
struct V_18 * V_18 = V_74 -> V_8 . V_18 ;
T_3 * V_1000 ;
T_4 V_1001 ;
V_1001 = F_100 ( V_998 ) ;
if ( V_1001 == ( V_999 - 1 ) )
return;
if ( V_1001 >= V_999 )
V_1001 = 0 ;
else
V_1001 ++ ;
V_1000 = F_247 ( V_74 -> V_995 ) ;
for (; V_1001 < V_999 ; V_1001 ++ ) {
T_3 V_86 ;
V_86 = V_1000 [ V_1001 ] ;
F_325 ( V_86 & ( V_450 - 1 ) ) ;
F_563 ( V_18 , V_86 >> V_19 ) ;
}
F_108 ( V_998 , V_999 - 1 ) ;
}
static void F_564 ( struct V_18 * V_18 )
{
int V_76 ;
struct V_7 * V_8 ;
F_565 (i, vcpu, kvm)
F_340 ( V_8 ) ;
}
static int F_566 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_2 V_260 = V_74 -> V_260 ;
T_2 V_1002 = V_74 -> V_737 ;
if ( V_861 )
F_562 ( V_74 ) ;
if ( V_74 -> F_257 )
return F_472 ( V_8 ) ;
if ( F_130 ( V_8 ) && F_553 ( V_8 ) ) {
F_186 ( V_8 , V_260 ,
F_101 ( V_261 ) ,
F_99 ( V_262 ) ) ;
return 1 ;
}
if ( V_260 & V_1003 ) {
V_8 -> V_730 -> V_260 = V_1004 ;
V_8 -> V_730 -> V_1005 . V_1006
= V_260 ;
return 0 ;
}
if ( F_107 ( V_74 -> V_954 ) ) {
V_8 -> V_730 -> V_260 = V_1004 ;
V_8 -> V_730 -> V_1005 . V_1006
= F_101 ( V_105 ) ;
return 0 ;
}
if ( ( V_1002 & V_741 ) &&
( V_260 != V_955 &&
V_260 != V_809 &&
V_260 != V_960 ) ) {
V_8 -> V_730 -> V_260 = V_743 ;
V_8 -> V_730 -> V_744 . V_745 = V_1007 ;
V_8 -> V_730 -> V_744 . V_747 = 2 ;
V_8 -> V_730 -> V_744 . V_184 [ 0 ] = V_1002 ;
V_8 -> V_730 -> V_744 . V_184 [ 1 ] = V_260 ;
return 0 ;
}
if ( F_107 ( ! F_52 () && V_74 -> V_675 &&
! ( F_130 ( V_8 ) && F_60 (
F_11 ( V_8 ) ) ) ) ) {
if ( F_374 ( V_8 ) ) {
V_74 -> V_675 = 0 ;
} else if ( V_74 -> V_704 > 1000000000LL &&
V_8 -> V_117 . V_1008 ) {
F_76 ( V_167 L_32
L_33 ,
V_504 , V_8 -> V_303 ) ;
V_74 -> V_675 = 0 ;
}
}
if ( V_260 < V_1009
&& V_1010 [ V_260 ] )
return V_1010 [ V_260 ] ( V_8 ) ;
else {
F_567 ( 1 , L_34 , V_260 ) ;
F_381 ( V_8 , V_27 ) ;
return 1 ;
}
}
static void V_853 ( struct V_7 * V_8 , int V_1011 , int V_1012 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
if ( F_130 ( V_8 ) &&
F_58 ( V_13 , V_33 ) )
return;
if ( V_1012 == - 1 || V_1011 < V_1012 ) {
F_109 ( V_691 , 0 ) ;
return;
}
F_109 ( V_691 , V_1012 ) ;
}
static void F_568 ( struct V_7 * V_8 , bool V_1013 )
{
T_2 V_1014 ;
if ( ! F_30 () ||
! F_212 ( V_8 -> V_18 ) )
return;
if ( ! F_26 ( V_8 -> V_18 ) )
return;
V_1014 = F_101 ( V_651 ) ;
if ( V_1013 ) {
V_1014 &= ~ V_36 ;
V_1014 |= V_37 ;
} else {
V_1014 &= ~ V_37 ;
V_1014 |= V_36 ;
}
F_109 ( V_651 , V_1014 ) ;
F_193 ( V_8 ) ;
}
static void F_569 ( struct V_7 * V_8 , T_16 V_1015 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( ! F_130 ( V_8 ) ||
! F_59 ( V_74 -> V_14 . V_15 ,
V_36 ) )
F_110 ( V_1016 , V_1015 ) ;
}
static void F_570 ( struct V_18 * V_18 , int V_1017 )
{
T_4 V_603 ;
T_6 V_428 ;
if ( V_1017 == - 1 )
V_1017 = 0 ;
V_603 = F_100 ( V_606 ) ;
V_428 = V_603 >> 8 ;
if ( V_1017 != V_428 ) {
V_603 &= 0xff ;
V_603 |= V_1017 << 8 ;
F_108 ( V_606 , V_603 ) ;
}
}
static void F_571 ( int V_4 )
{
T_4 V_603 ;
T_6 V_428 ;
if ( V_4 == - 1 )
V_4 = 0 ;
V_603 = F_100 ( V_606 ) ;
V_428 = ( T_6 ) V_603 & 0xff ;
if ( ( T_6 ) V_4 != V_428 ) {
V_603 &= ~ 0xff ;
V_603 |= ( T_6 ) V_4 ;
F_108 ( V_606 , V_603 ) ;
}
}
static void F_572 ( struct V_7 * V_8 , int V_601 )
{
if ( ! F_130 ( V_8 ) ) {
F_571 ( V_601 ) ;
return;
}
if ( V_601 == - 1 )
return;
if ( F_363 ( V_8 ) )
return;
if ( ! F_388 ( V_8 ) &&
F_374 ( V_8 ) ) {
F_573 ( V_8 , V_601 , false ) ;
F_368 ( V_8 ) ;
}
}
static void F_574 ( struct V_7 * V_8 , T_3 * V_1018 )
{
if ( ! F_212 ( V_8 -> V_18 ) )
return;
F_110 ( V_652 , V_1018 [ 0 ] ) ;
F_110 ( V_653 , V_1018 [ 1 ] ) ;
F_110 ( V_654 , V_1018 [ 2 ] ) ;
F_110 ( V_655 , V_1018 [ 3 ] ) ;
}
static void F_575 ( struct V_6 * V_74 )
{
T_2 V_738 ;
if ( ! ( V_74 -> V_260 == V_984
|| V_74 -> V_260 == V_955 ) )
return;
V_74 -> V_738 = F_101 ( V_261 ) ;
V_738 = V_74 -> V_738 ;
if ( F_23 ( V_738 ) )
F_382 () ;
if ( ( V_738 & V_21 ) == V_708 &&
( V_738 & V_23 ) ) {
F_576 ( & V_74 -> V_8 ) ;
asm("int $2");
F_577 ( & V_74 -> V_8 ) ;
}
}
static void F_578 ( struct V_7 * V_8 )
{
T_2 V_738 = F_101 ( V_261 ) ;
if ( ( V_738 & ( V_23 | V_21 ) )
== ( V_23 | V_28 ) ) {
unsigned int V_4 ;
unsigned long V_142 ;
T_17 * V_1019 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
#ifdef F_103
unsigned long V_277 ;
#endif
V_4 = V_738 & V_22 ;
V_1019 = ( T_17 * ) V_74 -> V_628 + V_4 ;
V_142 = F_579 ( * V_1019 ) ;
asm volatile(
#ifdef F_103
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
#ifdef F_103
[sp]"=&r"(tmp)
#endif
:
[entry]"r"(entry),
[ss]"i"(__KERNEL_DS),
[cs]"i"(__KERNEL_CS)
);
} else
F_167 () ;
}
static bool F_213 ( void )
{
return ( V_30 . V_454 & V_326 ) &&
( V_30 . V_410 & V_335 ) ;
}
static bool F_64 ( void )
{
return V_30 . V_35 &
V_73 ;
}
static void F_580 ( struct V_6 * V_74 )
{
T_2 V_738 ;
bool V_1020 ;
T_6 V_4 ;
bool V_1021 ;
V_1021 = V_74 -> V_737 & V_741 ;
if ( F_52 () ) {
if ( V_74 -> V_706 )
return;
V_738 = F_101 ( V_261 ) ;
V_1020 = ( V_738 & V_810 ) != 0 ;
V_4 = V_738 & V_22 ;
if ( ( V_738 & V_23 ) && V_1020 &&
V_4 != V_721 && ! V_1021 )
F_112 ( V_252 ,
V_709 ) ;
else
V_74 -> V_706 =
! ( F_101 ( V_252 )
& V_709 ) ;
} else if ( F_107 ( V_74 -> V_675 ) )
V_74 -> V_704 +=
F_581 ( F_582 ( F_583 () , V_74 -> V_1022 ) ) ;
}
static void F_584 ( struct V_7 * V_8 ,
T_2 V_737 ,
int V_1023 ,
int V_1024 )
{
T_6 V_4 ;
int type ;
bool V_1021 ;
V_1021 = V_737 & V_741 ;
V_8 -> V_117 . V_798 = false ;
F_461 ( V_8 ) ;
F_460 ( V_8 ) ;
if ( ! V_1021 )
return;
F_163 ( V_612 , V_8 ) ;
V_4 = V_737 & V_795 ;
type = V_737 & V_796 ;
switch ( type ) {
case V_708 :
V_8 -> V_117 . V_798 = true ;
F_372 ( V_8 , false ) ;
break;
case V_273 :
V_8 -> V_117 . V_269 = F_101 ( V_1023 ) ;
case V_24 :
if ( V_737 & V_799 ) {
T_2 V_769 = F_101 ( V_1024 ) ;
F_585 ( V_8 , V_4 , V_769 ) ;
} else
F_586 ( V_8 , V_4 ) ;
break;
case V_703 :
V_8 -> V_117 . V_269 = F_101 ( V_1023 ) ;
case V_28 :
F_573 ( V_8 , V_4 , type == V_703 ) ;
break;
default:
break;
}
}
static void F_587 ( struct V_6 * V_74 )
{
F_584 ( & V_74 -> V_8 , V_74 -> V_737 ,
V_259 ,
V_800 ) ;
}
static void F_588 ( struct V_7 * V_8 )
{
F_584 ( V_8 ,
F_101 ( V_274 ) ,
V_272 ,
V_266 ) ;
F_109 ( V_274 , 0 ) ;
}
static void F_589 ( struct V_6 * V_74 )
{
int V_76 , V_1025 ;
struct V_1026 * V_1027 ;
V_1027 = F_590 ( & V_1025 ) ;
if ( ! V_1027 )
return;
for ( V_76 = 0 ; V_76 < V_1025 ; V_76 ++ )
if ( V_1027 [ V_76 ] . V_155 == V_1027 [ V_76 ] . V_154 )
F_132 ( V_74 , V_1027 [ V_76 ] . V_75 ) ;
else
F_134 ( V_74 , V_1027 [ V_76 ] . V_75 , V_1027 [ V_76 ] . V_154 ,
V_1027 [ V_76 ] . V_155 ) ;
}
static void T_18 F_591 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
unsigned long V_1028 , V_511 ;
if ( F_107 ( ! F_52 () && V_74 -> V_675 ) )
V_74 -> V_1022 = F_583 () ;
if ( V_74 -> F_257 )
return;
if ( V_74 -> V_660 ) {
V_74 -> V_660 = false ;
F_109 ( V_1029 , V_74 -> V_659 ) ;
}
if ( V_74 -> V_14 . V_920 ) {
F_535 ( V_74 ) ;
V_74 -> V_14 . V_920 = false ;
}
if ( F_177 ( V_420 , ( unsigned long * ) & V_8 -> V_117 . V_514 ) )
F_106 ( V_422 , V_8 -> V_117 . V_421 [ V_420 ] ) ;
if ( F_177 ( V_423 , ( unsigned long * ) & V_8 -> V_117 . V_514 ) )
F_106 ( V_424 , V_8 -> V_117 . V_421 [ V_423 ] ) ;
V_511 = V_242 () ;
if ( F_107 ( V_511 != V_74 -> V_192 . V_619 ) ) {
F_106 ( V_618 , V_511 ) ;
V_74 -> V_192 . V_619 = V_511 ;
}
if ( V_8 -> V_133 & V_716 )
F_181 ( V_8 , 0 ) ;
F_589 ( V_74 ) ;
V_1028 = F_592 () ;
V_74 -> V_1030 = V_74 -> V_91 -> V_93 ;
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
#ifdef F_103
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
#ifdef F_103
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
#ifdef F_103
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
#ifdef F_103
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_1028 )
F_593 ( V_1028 ) ;
#ifndef F_103
F_154 ( V_203 , V_1031 ) ;
F_154 ( V_205 , V_1031 ) ;
#endif
V_8 -> V_117 . V_118 = ~ ( ( 1 << V_423 ) | ( 1 << V_420 )
| ( 1 << V_246 )
| ( 1 << V_425 )
| ( 1 << V_119 )
| ( 1 << V_509 ) ) ;
V_8 -> V_117 . V_514 = 0 ;
V_74 -> V_737 = F_101 ( V_1032 ) ;
V_74 -> V_91 -> V_93 = 1 ;
V_74 -> V_260 = F_101 ( V_1033 ) ;
F_594 ( V_74 -> V_260 , V_8 , V_953 ) ;
if ( V_74 -> V_14 . V_711 )
F_163 ( V_612 , V_8 ) ;
V_74 -> V_14 . V_711 = 0 ;
F_575 ( V_74 ) ;
F_580 ( V_74 ) ;
F_587 ( V_74 ) ;
}
static void F_595 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_92 ;
if ( V_74 -> V_91 == & V_74 -> V_876 )
return;
V_92 = F_596 () ;
V_74 -> V_91 = & V_74 -> V_876 ;
F_168 ( V_8 ) ;
F_161 ( V_8 , V_92 ) ;
V_8 -> V_92 = V_92 ;
F_597 () ;
}
static void F_598 ( struct V_7 * V_8 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( V_861 )
F_560 ( V_74 ) ;
F_320 ( V_74 ) ;
F_599 ( V_8 ) ;
F_595 ( V_8 ) ;
F_525 ( V_74 ) ;
F_251 ( V_74 -> V_91 ) ;
F_504 ( V_74 -> V_79 ) ;
F_600 ( V_8 ) ;
F_601 ( V_1034 , V_74 ) ;
}
static struct V_7 * F_602 ( struct V_18 * V_18 , unsigned int V_1035 )
{
int V_769 ;
struct V_6 * V_74 = F_603 ( V_1034 , V_461 ) ;
int V_92 ;
if ( ! V_74 )
return F_604 ( - V_469 ) ;
F_316 ( V_74 ) ;
V_769 = F_605 ( & V_74 -> V_8 , V_18 , V_1035 ) ;
if ( V_769 )
goto V_1036;
V_74 -> V_79 = F_503 ( V_450 , V_461 ) ;
F_9 ( F_10 ( V_78 ) * sizeof( V_74 -> V_79 [ 0 ] )
> V_450 ) ;
V_769 = - V_469 ;
if ( ! V_74 -> V_79 ) {
goto V_1037;
}
V_74 -> V_91 = & V_74 -> V_876 ;
V_74 -> V_91 -> V_88 = F_248 () ;
if ( ! V_74 -> V_91 -> V_88 )
goto V_1038;
if ( ! V_222 )
F_162 ( F_75 ( F_89 ( V_221 , F_86 () ) ) ) ;
F_77 ( V_74 -> V_91 ) ;
if ( ! V_222 )
F_169 () ;
V_92 = F_596 () ;
F_161 ( & V_74 -> V_8 , V_92 ) ;
V_74 -> V_8 . V_92 = V_92 ;
V_769 = F_354 ( V_74 ) ;
F_168 ( & V_74 -> V_8 ) ;
F_597 () ;
if ( V_769 )
goto F_249;
if ( F_48 ( V_18 ) ) {
V_769 = F_312 ( V_18 ) ;
if ( V_769 )
goto F_249;
}
if ( V_102 ) {
if ( ! V_18 -> V_117 . V_536 )
V_18 -> V_117 . V_536 =
V_1039 ;
V_769 = F_306 ( V_18 ) ;
if ( V_769 )
goto F_249;
}
if ( V_14 )
F_210 ( V_74 ) ;
V_74 -> V_14 . V_611 = - 1 ;
V_74 -> V_14 . V_869 = - 1ull ;
V_74 -> V_14 . V_15 = NULL ;
if ( V_861 ) {
V_769 = F_557 ( V_74 ) ;
if ( V_769 )
goto F_249;
}
return & V_74 -> V_8 ;
F_249:
F_251 ( V_74 -> V_91 ) ;
V_1038:
F_504 ( V_74 -> V_79 ) ;
V_1037:
F_600 ( & V_74 -> V_8 ) ;
V_1036:
F_320 ( V_74 ) ;
F_601 ( V_1034 , V_74 ) ;
return F_604 ( V_769 ) ;
}
static void T_11 F_606 ( void * V_1040 )
{
struct V_30 V_440 ;
* ( int * ) V_1040 = 0 ;
if ( F_242 ( & V_440 ) < 0 )
* ( int * ) V_1040 = - V_439 ;
if ( memcmp ( & V_30 , & V_440 , sizeof( struct V_30 ) ) != 0 ) {
F_76 ( V_90 L_35 ,
F_607 () ) ;
* ( int * ) V_1040 = - V_439 ;
}
}
static int F_608 ( void )
{
return V_529 + 1 ;
}
static T_3 F_609 ( struct V_7 * V_8 , T_12 V_1041 , bool V_1042 )
{
T_3 V_115 ;
if ( V_1042 )
V_115 = V_1043 << V_1044 ;
else if ( F_610 ( V_8 -> V_18 ) )
V_115 = F_611 ( V_8 , V_1041 ) <<
V_1044 ;
else
V_115 = ( V_1045 << V_1044 )
| V_1046 ;
return V_115 ;
}
static int F_612 ( void )
{
if ( V_102 && ! F_38 () )
return V_1047 ;
else
return V_1048 ;
}
static void F_613 ( struct V_7 * V_8 )
{
struct V_306 * V_307 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_2 V_637 ;
V_74 -> V_290 = false ;
if ( F_190 () ) {
V_637 = F_101 ( V_651 ) ;
if ( V_637 & V_59 ) {
V_307 = F_208 ( V_8 , 0x80000001 , 0 ) ;
if ( V_307 && ( V_307 -> V_1049 & V_68 ( V_1050 ) ) )
V_74 -> V_290 = true ;
else {
V_637 &= ~ V_59 ;
F_109 ( V_651 ,
V_637 ) ;
}
}
}
V_307 = F_208 ( V_8 , 0x7 , 0 ) ;
if ( F_191 () &&
V_307 && ( V_307 -> V_1051 & V_68 ( V_1052 ) ) &&
F_614 ( V_8 ) ) {
V_637 = F_101 ( V_651 ) ;
V_637 |= V_60 ;
F_109 ( V_651 ,
V_637 ) ;
} else {
if ( F_28 () ) {
V_637 = F_101 ( V_651 ) ;
V_637 &= ~ V_60 ;
F_109 ( V_651 ,
V_637 ) ;
}
if ( V_307 )
V_307 -> V_1051 &= ~ V_68 ( V_1052 ) ;
}
}
static void F_615 ( T_2 V_1053 , struct V_306 * V_142 )
{
if ( V_1053 == 1 && V_14 )
V_142 -> V_308 |= V_68 ( V_309 ) ;
}
static void F_616 ( struct V_7 * V_8 ,
struct V_901 * V_1054 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
T_2 V_260 ;
if ( V_1054 -> V_264 & V_742 )
V_260 = V_826 ;
else
V_260 = V_809 ;
F_186 ( V_8 , V_260 , 0 , V_8 -> V_117 . V_761 ) ;
V_13 -> V_1055 = V_1054 -> V_173 ;
}
static unsigned long F_617 ( struct V_7 * V_8 )
{
return F_11 ( V_8 ) -> V_1056 ;
}
static void F_618 ( struct V_7 * V_8 )
{
F_325 ( F_619 ( V_8 ) ) ;
F_620 ( V_8 ,
F_6 ( V_8 ) -> V_14 . V_362 &
V_44 ) ;
V_8 -> V_117 . V_505 . V_1057 = F_283 ;
V_8 -> V_117 . V_505 . V_1058 = F_617 ;
V_8 -> V_117 . V_505 . V_1059 = F_616 ;
V_8 -> V_117 . V_513 = & V_8 -> V_117 . V_1060 ;
}
static void F_621 ( struct V_7 * V_8 )
{
V_8 -> V_117 . V_513 = & V_8 -> V_117 . V_505 ;
}
static bool F_622 ( struct V_13 * V_13 ,
T_4 V_264 )
{
bool V_1061 , V_68 ;
V_68 = ( V_13 -> V_140 & ( 1u << V_25 ) ) != 0 ;
V_1061 =
( V_264 & V_13 -> V_1062 ) !=
V_13 -> V_1063 ;
return V_1061 ^ V_68 ;
}
static void F_623 ( struct V_7 * V_8 ,
struct V_901 * V_1054 )
{
struct V_13 * V_13 = F_11 ( V_8 ) ;
F_325 ( ! F_130 ( V_8 ) ) ;
if ( F_622 ( V_13 , V_1054 -> V_264 ) )
F_186 ( V_8 , F_6 ( V_8 ) -> V_260 ,
F_101 ( V_261 ) ,
F_99 ( V_262 ) ) ;
else
F_517 ( V_8 , V_1054 ) ;
}
static bool F_624 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( F_59 ( V_13 , V_36 ) ) {
if ( ! F_518 ( V_13 -> V_1064 ) )
return false ;
if ( V_74 -> V_14 . V_922 )
F_15 ( V_74 -> V_14 . V_922 ) ;
V_74 -> V_14 . V_922 =
F_12 ( V_8 , V_13 -> V_1064 ) ;
}
if ( F_58 ( V_13 , V_33 ) ) {
if ( ! F_518 ( V_13 -> V_1065 ) )
return false ;
if ( V_74 -> V_14 . V_605 )
F_15 ( V_74 -> V_14 . V_605 ) ;
V_74 -> V_14 . V_605 =
F_12 ( V_8 , V_13 -> V_1065 ) ;
if ( ! V_74 -> V_14 . V_605 )
return false ;
}
if ( F_68 ( V_13 ) ) {
if ( ! F_625 ( V_13 -> V_1066 , 64 ) )
return false ;
if ( V_74 -> V_14 . V_923 ) {
F_334 ( V_74 -> V_14 . V_923 ) ;
F_15 ( V_74 -> V_14 . V_923 ) ;
}
V_74 -> V_14 . V_923 =
F_12 ( V_8 , V_13 -> V_1066 ) ;
if ( ! V_74 -> V_14 . V_923 )
return false ;
V_74 -> V_14 . V_1 =
(struct V_1 * ) F_332 ( V_74 -> V_14 . V_923 ) ;
if ( ! V_74 -> V_14 . V_1 ) {
F_17 ( V_74 -> V_14 . V_923 ) ;
return false ;
}
V_74 -> V_14 . V_1 =
(struct V_1 * ) ( ( void * ) V_74 -> V_14 . V_1 +
( unsigned long ) ( V_13 -> V_1066 &
( V_450 - 1 ) ) ) ;
}
return true ;
}
static void F_626 ( struct V_7 * V_8 )
{
T_3 V_1067 = F_11 ( V_8 ) -> V_1068 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( V_8 -> V_117 . V_1069 == 0 )
return;
if ( V_1067 <= 1 ) {
F_512 ( & V_74 -> V_14 . V_888 ) ;
return;
}
V_1067 <<= V_369 ;
V_1067 *= 1000000 ;
F_627 ( V_1067 , V_8 -> V_117 . V_1069 ) ;
F_628 ( & V_74 -> V_14 . V_888 ,
F_629 ( V_1067 ) , V_918 ) ;
}
static int F_630 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
int V_903 ;
T_3 V_17 ;
if ( ! F_58 ( V_13 , V_32 ) )
return 0 ;
if ( F_533 ( V_8 , V_285 , & V_17 ) ) {
F_325 ( 1 ) ;
return - V_392 ;
}
V_903 = F_515 ( V_8 ) ;
if ( ! F_518 ( V_13 -> V_278 ) ||
( ( V_17 + V_450 ) >> V_903 ) )
return - V_392 ;
return 0 ;
}
static inline bool F_631 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
int V_75 ;
struct V_16 * V_16 ;
unsigned long * V_278 ;
if ( ! F_65 ( V_13 ) )
return false ;
V_16 = F_12 ( V_8 , V_13 -> V_278 ) ;
if ( ! V_16 ) {
F_325 ( 1 ) ;
return false ;
}
V_278 = ( unsigned long * ) F_332 ( V_16 ) ;
if ( ! V_278 ) {
F_17 ( V_16 ) ;
F_325 ( 1 ) ;
return false ;
}
if ( F_65 ( V_13 ) ) {
if ( F_66 ( V_13 ) )
for ( V_75 = 0x800 ; V_75 <= 0x8ff ; V_75 ++ )
F_324 (
V_278 ,
V_279 ,
V_75 , V_595 ) ;
F_324 ( V_278 ,
V_279 ,
V_1070 + ( V_1071 >> 4 ) ,
V_595 | V_596 ) ;
if ( F_67 ( V_13 ) ) {
F_324 (
V_278 ,
V_279 ,
V_1070 + ( V_790 >> 4 ) ,
V_596 ) ;
F_324 (
V_278 ,
V_279 ,
V_1070 + ( V_1072 >> 4 ) ,
V_596 ) ;
}
} else {
for ( V_75 = 0x800 ; V_75 <= 0x8ff ; V_75 ++ )
F_323 (
V_279 ,
V_75 ,
V_595 ) ;
F_323 (
V_279 ,
V_1070 + ( V_1071 >> 4 ) ,
V_596 ) ;
F_323 (
V_279 ,
V_1070 + ( V_790 >> 4 ) ,
V_596 ) ;
F_323 (
V_279 ,
V_1070 + ( V_1072 >> 4 ) ,
V_596 ) ;
}
F_334 ( V_16 ) ;
F_17 ( V_16 ) ;
return true ;
}
static int F_632 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
if ( ! F_65 ( V_13 ) &&
! F_66 ( V_13 ) &&
! F_67 ( V_13 ) &&
! F_68 ( V_13 ) )
return 0 ;
if ( F_65 ( V_13 ) &&
F_59 ( V_13 , V_36 ) )
return - V_392 ;
if ( F_67 ( V_13 ) &&
! F_363 ( V_8 ) )
return - V_392 ;
if ( F_68 ( V_13 ) &&
( ! F_67 ( V_13 ) ||
! F_364 ( V_8 ) ||
V_13 -> V_611 & 0xff00 ) )
return - V_392 ;
if ( ! F_58 ( V_13 , V_33 ) )
return - V_392 ;
return 0 ;
}
static int F_633 ( struct V_7 * V_8 ,
unsigned long V_1073 ,
unsigned long V_1074 ,
int V_903 )
{
T_3 V_830 , V_17 ;
if ( F_533 ( V_8 , V_1073 , & V_830 ) ||
F_533 ( V_8 , V_1074 , & V_17 ) ) {
F_325 ( 1 ) ;
return - V_392 ;
}
if ( V_830 == 0 )
return 0 ;
if ( ! F_625 ( V_17 , 16 ) || V_17 >> V_903 ||
( V_17 + V_830 * sizeof( struct V_1075 ) - 1 ) >> V_903 ) {
F_634 (
L_36 ,
V_1074 , V_903 , V_830 , V_17 ) ;
return - V_392 ;
}
return 0 ;
}
static int F_635 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
int V_903 ;
if ( V_13 -> V_1076 == 0 &&
V_13 -> V_1077 == 0 &&
V_13 -> V_1078 == 0 )
return 0 ;
V_903 = F_515 ( V_8 ) ;
if ( F_633 ( V_8 , V_157 ,
V_665 , V_903 ) ||
F_633 ( V_8 , V_664 ,
V_1079 , V_903 ) ||
F_633 ( V_8 , V_156 ,
V_666 , V_903 ) )
return - V_392 ;
return 0 ;
}
static int F_636 ( struct V_7 * V_8 ,
struct V_1075 * V_902 )
{
if ( F_194 ( V_8 -> V_117 . V_280 ) && V_902 -> V_80 >> 8 == 0x8 )
return - V_392 ;
if ( V_902 -> V_80 == V_1080 ||
V_902 -> V_80 == V_1081 )
return - V_392 ;
if ( V_902 -> V_1082 != 0 )
return - V_392 ;
return 0 ;
}
static int F_637 ( struct V_7 * V_8 ,
struct V_1075 * V_902 )
{
if ( V_902 -> V_80 == V_208 ||
V_902 -> V_80 == V_210 ||
V_902 -> V_80 == V_1083 ||
F_636 ( V_8 , V_902 ) )
return - V_392 ;
return 0 ;
}
static int F_638 ( struct V_7 * V_8 ,
struct V_1075 * V_902 )
{
if ( V_902 -> V_80 == V_1084 ||
F_636 ( V_8 , V_902 ) )
return - V_392 ;
return 0 ;
}
static T_2 F_639 ( struct V_7 * V_8 , T_3 V_86 , T_2 V_830 )
{
T_2 V_76 ;
struct V_1075 V_902 ;
struct V_407 V_75 ;
V_75 . V_415 = false ;
for ( V_76 = 0 ; V_76 < V_830 ; V_76 ++ ) {
if ( F_550 ( V_8 -> V_18 , V_86 + V_76 * sizeof( V_902 ) ,
& V_902 , sizeof( V_902 ) ) ) {
F_634 (
L_37 ,
V_504 , V_76 , V_86 + V_76 * sizeof( V_902 ) ) ;
goto V_954;
}
if ( F_637 ( V_8 , & V_902 ) ) {
F_634 (
L_38 ,
V_504 , V_76 , V_902 . V_80 , V_902 . V_1082 ) ;
goto V_954;
}
V_75 . V_80 = V_902 . V_80 ;
V_75 . V_184 = V_902 . V_104 ;
if ( F_431 ( V_8 , & V_75 ) ) {
F_634 (
L_39 ,
V_504 , V_76 , V_902 . V_80 , V_902 . V_104 ) ;
goto V_954;
}
}
return 0 ;
V_954:
return V_76 + 1 ;
}
static int F_640 ( struct V_7 * V_8 , T_3 V_86 , T_2 V_830 )
{
T_2 V_76 ;
struct V_1075 V_902 ;
for ( V_76 = 0 ; V_76 < V_830 ; V_76 ++ ) {
if ( F_550 ( V_8 -> V_18 ,
V_86 + V_76 * sizeof( V_902 ) ,
& V_902 , 2 * sizeof( T_2 ) ) ) {
F_634 (
L_37 ,
V_504 , V_76 , V_86 + V_76 * sizeof( V_902 ) ) ;
return - V_392 ;
}
if ( F_638 ( V_8 , & V_902 ) ) {
F_634 (
L_38 ,
V_504 , V_76 , V_902 . V_80 , V_902 . V_1082 ) ;
return - V_392 ;
}
if ( F_641 ( V_8 , V_902 . V_80 , & V_902 . V_104 ) ) {
F_634 (
L_40 ,
V_504 , V_76 , V_902 . V_80 ) ;
return - V_392 ;
}
if ( F_642 ( V_8 -> V_18 ,
V_86 + V_76 * sizeof( V_902 ) +
F_643 ( struct V_1075 , V_104 ) ,
& V_902 . V_104 , sizeof( V_902 . V_104 ) ) ) {
F_634 (
L_39 ,
V_504 , V_76 , V_902 . V_80 , V_902 . V_104 ) ;
return - V_392 ;
}
}
return 0 ;
}
static void F_644 ( struct V_7 * V_8 , struct V_13 * V_13 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
T_2 V_637 ;
F_108 ( V_1085 , V_13 -> V_1086 ) ;
F_108 ( V_679 , V_13 -> V_1087 ) ;
F_108 ( V_1088 , V_13 -> V_1089 ) ;
F_108 ( V_1090 , V_13 -> V_1091 ) ;
F_108 ( V_1092 , V_13 -> V_1093 ) ;
F_108 ( V_1094 , V_13 -> V_1095 ) ;
F_108 ( V_682 , V_13 -> V_1096 ) ;
F_108 ( V_681 , V_13 -> V_1097 ) ;
F_109 ( V_1098 , V_13 -> V_1099 ) ;
F_109 ( V_1100 , V_13 -> V_1101 ) ;
F_109 ( V_1102 , V_13 -> V_1103 ) ;
F_109 ( V_1104 , V_13 -> V_1105 ) ;
F_109 ( V_1106 , V_13 -> V_1107 ) ;
F_109 ( V_1108 , V_13 -> V_1109 ) ;
F_109 ( V_684 , V_13 -> V_1110 ) ;
F_109 ( V_498 , V_13 -> V_1111 ) ;
F_109 ( V_550 , V_13 -> V_1112 ) ;
F_109 ( V_548 , V_13 -> V_1113 ) ;
F_109 ( V_1114 , V_13 -> V_1115 ) ;
F_109 ( V_1116 , V_13 -> V_1117 ) ;
F_109 ( V_1118 , V_13 -> V_1119 ) ;
F_109 ( V_1120 , V_13 -> V_1121 ) ;
F_109 ( V_1122 , V_13 -> V_1123 ) ;
F_109 ( V_1124 , V_13 -> V_1125 ) ;
F_109 ( V_685 , V_13 -> V_1126 ) ;
F_109 ( V_500 , V_13 -> V_1127 ) ;
F_106 ( V_1128 , V_13 -> V_1129 ) ;
F_106 ( V_680 , V_13 -> V_1130 ) ;
F_106 ( V_1131 , V_13 -> V_1132 ) ;
F_106 ( V_1133 , V_13 -> V_1134 ) ;
F_106 ( V_393 , V_13 -> V_1135 ) ;
F_106 ( V_394 , V_13 -> V_1136 ) ;
F_106 ( V_683 , V_13 -> V_1137 ) ;
F_106 ( V_497 , V_13 -> V_1138 ) ;
F_106 ( V_551 , V_13 -> V_1139 ) ;
F_106 ( V_549 , V_13 -> V_1140 ) ;
if ( V_13 -> V_1141 & V_337 ) {
F_418 ( V_8 , 7 , V_13 -> V_1142 ) ;
F_110 ( V_689 , V_13 -> V_1143 ) ;
} else {
F_418 ( V_8 , 7 , V_8 -> V_117 . V_752 ) ;
F_110 ( V_689 , V_74 -> V_14 . V_1144 ) ;
}
F_109 ( V_274 ,
V_13 -> V_1145 ) ;
F_109 ( V_266 ,
V_13 -> V_1146 ) ;
F_109 ( V_272 ,
V_13 -> V_1147 ) ;
F_109 ( V_252 ,
V_13 -> V_1148 ) ;
F_109 ( V_397 , V_13 -> V_1149 ) ;
F_179 ( V_8 , V_13 -> V_1150 ) ;
F_106 ( V_688 ,
V_13 -> V_1151 ) ;
F_106 ( V_400 , V_13 -> V_1152 ) ;
F_106 ( V_399 , V_13 -> V_1153 ) ;
if ( F_63 ( V_13 ) )
F_110 ( V_672 , V_13 -> V_1154 ) ;
F_110 ( V_649 , - 1ull ) ;
V_637 = V_13 -> V_71 ;
V_637 |= V_30 . V_40 ;
V_637 &= ~ V_72 ;
if ( F_68 ( V_13 ) ) {
V_74 -> V_14 . V_611 = V_13 -> V_611 ;
V_74 -> V_14 . V_604 = false ;
F_110 ( V_656 , V_610 ) ;
F_110 ( V_657 ,
F_559 ( V_74 -> V_14 . V_923 ) +
( unsigned long ) ( V_13 -> V_1066 &
( V_450 - 1 ) ) ) ;
} else
V_637 &= ~ V_41 ;
F_109 ( V_650 , V_637 ) ;
V_74 -> V_14 . V_889 = false ;
if ( F_61 ( V_13 ) )
F_626 ( V_8 ) ;
F_109 ( V_661 ,
V_102 ? V_13 -> V_1062 : 0 ) ;
F_109 ( V_662 ,
V_102 ? V_13 -> V_1063 : 0 ) ;
if ( F_28 () ) {
V_637 = F_351 ( V_74 ) ;
if ( ! V_74 -> V_290 )
V_637 &= ~ V_59 ;
V_637 &= ~ ( V_36 |
V_39 |
V_38 ) ;
if ( F_58 ( V_13 ,
V_34 ) )
V_637 |= V_13 -> V_70 ;
if ( V_637 & V_36 ) {
if ( ! V_74 -> V_14 . V_922 )
V_637 &=
~ V_36 ;
else
F_110 ( V_1016 ,
F_559 ( V_74 -> V_14 . V_922 ) ) ;
} else if ( ! ( F_65 ( V_13 ) ) &&
( F_48 ( V_74 -> V_8 . V_18 ) ) ) {
V_637 |=
V_36 ;
F_645 ( V_8 ) ;
}
if ( V_637 & V_39 ) {
F_110 ( V_652 ,
V_13 -> V_1155 ) ;
F_110 ( V_653 ,
V_13 -> V_1156 ) ;
F_110 ( V_654 ,
V_13 -> V_1157 ) ;
F_110 ( V_655 ,
V_13 -> V_1158 ) ;
F_108 ( V_606 ,
V_13 -> V_1159 ) ;
}
F_109 ( V_651 , V_637 ) ;
}
F_344 ( V_74 ) ;
V_74 -> V_1160 = 0 ;
V_637 = F_350 ( V_74 ) ;
V_637 &= ~ V_342 ;
V_637 &= ~ V_343 ;
V_637 &= ~ V_33 ;
V_637 |= V_13 -> V_69 ;
if ( V_637 & V_33 ) {
F_110 ( V_690 ,
F_559 ( V_74 -> V_14 . V_605 ) ) ;
F_109 ( V_691 , V_13 -> V_1161 ) ;
}
if ( F_24 () &&
V_637 & V_32 ) {
F_631 ( V_8 , V_13 ) ;
} else
V_637 &= ~ V_32 ;
V_637 &= ~ V_353 ;
V_637 |= V_352 ;
F_109 ( V_522 , V_637 ) ;
F_129 ( V_8 ) ;
V_8 -> V_117 . V_234 &= ~ V_13 -> V_235 ;
F_106 ( V_236 , ~ V_8 -> V_117 . V_234 ) ;
F_109 ( V_110 , V_30 . V_454 ) ;
F_113 ( V_74 ,
( V_13 -> V_1141 & ~ V_147 &
~ V_333 ) |
( V_30 . V_410 & ~ V_333 ) ) ;
if ( V_13 -> V_1141 & V_334 ) {
F_110 ( V_411 , V_13 -> V_1162 ) ;
V_8 -> V_117 . V_412 = V_13 -> V_1162 ;
} else if ( V_30 . V_410 & V_334 )
F_110 ( V_411 , V_74 -> V_8 . V_117 . V_412 ) ;
F_348 ( V_74 ) ;
if ( V_13 -> V_1141 & V_335 )
F_110 ( V_401 , V_13 -> V_1163 ) ;
if ( V_13 -> V_69 & V_302 )
F_110 ( V_294 ,
V_74 -> V_14 . V_295 + V_13 -> V_293 ) ;
else
F_110 ( V_294 , V_74 -> V_14 . V_295 ) ;
if ( V_590 ) {
F_108 ( V_693 , V_74 -> V_51 ) ;
F_271 ( V_8 ) ;
}
if ( F_62 ( V_13 ) ) {
F_646 ( V_8 ) ;
F_618 ( V_8 ) ;
}
if ( V_13 -> V_1141 & V_147 )
V_8 -> V_117 . V_178 = V_13 -> V_1164 ;
else if ( V_13 -> V_1141 & V_333 )
V_8 -> V_117 . V_178 |= ( V_181 | V_182 ) ;
else
V_8 -> V_117 . V_178 &= ~ ( V_181 | V_182 ) ;
F_267 ( V_8 , V_8 -> V_117 . V_178 ) ;
F_282 ( V_8 , V_13 -> V_238 ) ;
F_106 ( V_243 , F_172 ( V_13 ) ) ;
F_280 ( V_8 , V_13 -> V_240 ) ;
F_106 ( V_486 , F_173 ( V_13 ) ) ;
F_406 ( V_8 , V_13 -> V_534 ) ;
F_266 ( V_8 ) ;
if ( ! V_102 )
V_8 -> V_117 . V_513 -> V_1059 = F_623 ;
if ( V_102 ) {
F_110 ( V_515 , V_13 -> V_1165 ) ;
F_110 ( V_517 , V_13 -> V_1166 ) ;
F_110 ( V_518 , V_13 -> V_1167 ) ;
F_110 ( V_519 , V_13 -> V_1168 ) ;
}
F_408 ( V_8 , V_420 , V_13 -> V_1169 ) ;
F_408 ( V_8 , V_423 , V_13 -> V_1170 ) ;
}
static int F_529 ( struct V_7 * V_8 , bool V_1171 )
{
struct V_13 * V_13 ;
struct V_6 * V_74 = F_6 ( V_8 ) ;
int V_92 ;
struct V_91 * V_872 ;
bool V_1172 ;
T_2 V_1173 ;
if ( ! F_522 ( V_8 ) ||
! F_536 ( V_8 ) )
return 1 ;
F_182 ( V_8 ) ;
V_13 = F_11 ( V_8 ) ;
if ( V_646 )
F_524 ( V_74 ) ;
if ( V_13 -> V_924 == V_1171 ) {
F_509 ( V_8 ,
V_1171 ? V_1174
: V_1175 ) ;
return 1 ;
}
if ( V_13 -> V_1176 != V_687 &&
V_13 -> V_1176 != V_1177 ) {
F_509 ( V_8 , V_1178 ) ;
return 1 ;
}
if ( ! F_624 ( V_8 , V_13 ) ) {
F_509 ( V_8 , V_1178 ) ;
return 1 ;
}
if ( F_630 ( V_8 , V_13 ) ) {
F_509 ( V_8 , V_1178 ) ;
return 1 ;
}
if ( F_632 ( V_8 , V_13 ) ) {
F_509 ( V_8 , V_1178 ) ;
return 1 ;
}
if ( F_635 ( V_8 , V_13 ) ) {
F_509 ( V_8 , V_1178 ) ;
return 1 ;
}
if ( ! F_214 ( V_13 -> V_69 ,
V_74 -> V_14 . V_358 ,
V_74 -> V_14 . V_340 ) ||
! F_214 ( V_13 -> V_70 ,
V_74 -> V_14 . V_360 ,
V_74 -> V_14 . V_361 ) ||
! F_214 ( V_13 -> V_71 ,
V_74 -> V_14 . V_311 ,
V_74 -> V_14 . V_312 ) ||
! F_214 ( V_13 -> V_697 ,
V_74 -> V_14 . V_327 ,
V_74 -> V_14 . V_318 ) ||
! F_214 ( V_13 -> V_1141 ,
V_74 -> V_14 . V_336 ,
V_74 -> V_14 . V_331 ) )
{
F_509 ( V_8 , V_1178 ) ;
return 1 ;
}
if ( ( ( V_13 -> V_1179 & F_217 ) != F_217 ) ||
( ( V_13 -> V_1180 & F_218 ) != F_218 ) ) {
F_509 ( V_8 ,
V_1181 ) ;
return 1 ;
}
if ( ! F_396 ( V_8 , V_13 -> V_238 ) ||
( ( V_13 -> V_240 & F_218 ) != F_218 ) ) {
F_647 ( V_8 , V_13 ,
V_980 , V_1182 ) ;
return 1 ;
}
if ( V_13 -> V_1183 != - 1ull ) {
F_647 ( V_8 , V_13 ,
V_980 , V_1184 ) ;
return 1 ;
}
if ( V_13 -> V_1141 & V_147 ) {
V_1172 = ( V_13 -> V_1141 & V_333 ) != 0 ;
if ( ! F_648 ( V_8 , V_13 -> V_1164 ) ||
V_1172 != ! ! ( V_13 -> V_1164 & V_181 ) ||
( ( V_13 -> V_238 & V_521 ) &&
V_1172 != ! ! ( V_13 -> V_1164 & V_182 ) ) ) {
F_647 ( V_8 , V_13 ,
V_980 , V_1182 ) ;
return 1 ;
}
}
if ( V_13 -> V_697 & V_148 ) {
V_1172 = ( V_13 -> V_697 &
V_320 ) != 0 ;
if ( ! F_648 ( V_8 , V_13 -> V_1185 ) ||
V_1172 != ! ! ( V_13 -> V_1185 & V_181 ) ||
V_1172 != ! ! ( V_13 -> V_1185 & V_182 ) ) {
F_647 ( V_8 , V_13 ,
V_980 , V_1182 ) ;
return 1 ;
}
}
V_872 = F_500 ( V_74 ) ;
if ( ! V_872 )
return - V_469 ;
F_649 ( V_8 ) ;
V_74 -> V_14 . V_295 = F_102 ( V_294 ) ;
if ( ! ( V_13 -> V_1141 & V_337 ) )
V_74 -> V_14 . V_1144 = F_102 ( V_689 ) ;
V_92 = F_596 () ;
V_74 -> V_91 = V_872 ;
F_168 ( V_8 ) ;
F_161 ( V_8 , V_92 ) ;
V_8 -> V_92 = V_92 ;
F_597 () ;
F_123 ( V_74 ) ;
F_644 ( V_8 , V_13 ) ;
V_1173 = F_639 ( V_8 ,
V_13 -> V_1186 ,
V_13 -> V_1078 ) ;
if ( V_1173 ) {
F_599 ( V_8 ) ;
F_595 ( V_8 ) ;
F_647 ( V_8 , V_13 ,
V_1187 , V_1173 ) ;
return 1 ;
}
V_13 -> V_924 = 1 ;
if ( V_13 -> V_1176 == V_1177 )
return F_380 ( V_8 ) ;
V_74 -> V_14 . V_711 = 1 ;
return 1 ;
}
static inline unsigned long
F_650 ( struct V_7 * V_8 , struct V_13 * V_13 )
{
return
( F_99 ( V_231 ) & V_8 -> V_117 . V_234 ) |
( V_13 -> V_238 & V_13 -> V_235 ) |
( F_99 ( V_243 ) & ~ ( V_13 -> V_235 |
V_8 -> V_117 . V_234 ) ) ;
}
static inline unsigned long
F_651 ( struct V_7 * V_8 , struct V_13 * V_13 )
{
return
( F_99 ( V_484 ) & V_8 -> V_117 . V_510 ) |
( V_13 -> V_240 & V_13 -> V_241 ) |
( F_99 ( V_486 ) & ~ ( V_13 -> V_241 |
V_8 -> V_117 . V_510 ) ) ;
}
static void F_652 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
T_2 V_1188 ;
unsigned int V_153 ;
if ( V_8 -> V_117 . V_756 . V_1189 && V_8 -> V_117 . V_756 . V_265 ) {
V_153 = V_8 -> V_117 . V_756 . V_153 ;
V_1188 = V_153 | V_741 ;
if ( F_188 ( V_153 ) ) {
V_13 -> V_1190 =
V_8 -> V_117 . V_269 ;
V_1188 |= V_273 ;
} else
V_1188 |= V_24 ;
if ( V_8 -> V_117 . V_756 . V_263 ) {
V_1188 |= V_799 ;
V_13 -> V_1191 =
V_8 -> V_117 . V_756 . V_264 ;
}
V_13 -> V_1192 = V_1188 ;
} else if ( V_8 -> V_117 . V_798 ) {
V_13 -> V_1192 =
V_708 | V_23 | V_707 ;
} else if ( V_8 -> V_117 . V_700 . V_1189 ) {
V_153 = V_8 -> V_117 . V_700 . V_153 ;
V_1188 = V_153 | V_741 ;
if ( V_8 -> V_117 . V_700 . V_702 ) {
V_1188 |= V_703 ;
V_13 -> V_1147 =
V_8 -> V_117 . V_269 ;
} else
V_1188 |= V_28 ;
V_13 -> V_1192 = V_1188 ;
}
}
static int F_653 ( struct V_7 * V_8 , bool V_1193 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
if ( F_61 ( F_11 ( V_8 ) ) &&
V_74 -> V_14 . V_889 ) {
if ( V_74 -> V_14 . V_711 )
return - V_431 ;
F_186 ( V_8 , V_1194 , 0 , 0 ) ;
return 0 ;
}
if ( V_8 -> V_117 . V_1008 && F_365 ( V_8 ) ) {
if ( V_74 -> V_14 . V_711 ||
V_8 -> V_117 . V_700 . V_1189 )
return - V_431 ;
F_186 ( V_8 , V_955 ,
V_707 | V_708 |
V_23 , 0 ) ;
V_8 -> V_117 . V_1008 = 0 ;
F_372 ( V_8 , true ) ;
return 0 ;
}
if ( ( F_436 ( V_8 ) || V_1193 ) &&
F_363 ( V_8 ) ) {
if ( V_74 -> V_14 . V_711 )
return - V_431 ;
F_186 ( V_8 , V_956 , 0 , 0 ) ;
return 0 ;
}
return F_330 ( V_8 ) ;
}
static T_2 F_654 ( struct V_7 * V_8 )
{
T_19 V_1195 =
F_655 ( & F_6 ( V_8 ) -> V_14 . V_888 ) ;
T_3 V_104 ;
if ( F_581 ( V_1195 ) <= 0 )
return 0 ;
V_104 = F_581 ( V_1195 ) * V_8 -> V_117 . V_1069 ;
F_627 ( V_104 , 1000000 ) ;
return V_104 >> V_369 ;
}
static void F_656 ( struct V_7 * V_8 , struct V_13 * V_13 ,
T_2 V_260 , T_2 V_738 ,
unsigned long V_761 )
{
V_13 -> V_238 = F_650 ( V_8 , V_13 ) ;
V_13 -> V_240 = F_651 ( V_8 , V_13 ) ;
V_13 -> V_1169 = F_449 ( V_8 , V_420 ) ;
V_13 -> V_1170 = F_449 ( V_8 , V_423 ) ;
V_13 -> V_1150 = F_99 ( V_247 ) ;
V_13 -> V_1086 = F_100 ( V_1085 ) ;
V_13 -> V_1087 = F_100 ( V_679 ) ;
V_13 -> V_1089 = F_100 ( V_1088 ) ;
V_13 -> V_1091 = F_100 ( V_1090 ) ;
V_13 -> V_1093 = F_100 ( V_1092 ) ;
V_13 -> V_1095 = F_100 ( V_1094 ) ;
V_13 -> V_1096 = F_100 ( V_682 ) ;
V_13 -> V_1097 = F_100 ( V_681 ) ;
V_13 -> V_1099 = F_101 ( V_1098 ) ;
V_13 -> V_1101 = F_101 ( V_1100 ) ;
V_13 -> V_1103 = F_101 ( V_1102 ) ;
V_13 -> V_1105 = F_101 ( V_1104 ) ;
V_13 -> V_1107 = F_101 ( V_1106 ) ;
V_13 -> V_1109 = F_101 ( V_1108 ) ;
V_13 -> V_1110 = F_101 ( V_684 ) ;
V_13 -> V_1111 = F_101 ( V_498 ) ;
V_13 -> V_1112 = F_101 ( V_550 ) ;
V_13 -> V_1113 = F_101 ( V_548 ) ;
V_13 -> V_1115 = F_101 ( V_1114 ) ;
V_13 -> V_1117 = F_101 ( V_1116 ) ;
V_13 -> V_1119 = F_101 ( V_1118 ) ;
V_13 -> V_1121 = F_101 ( V_1120 ) ;
V_13 -> V_1123 = F_101 ( V_1122 ) ;
V_13 -> V_1125 = F_101 ( V_1124 ) ;
V_13 -> V_1126 = F_101 ( V_685 ) ;
V_13 -> V_1127 = F_101 ( V_500 ) ;
V_13 -> V_1129 = F_99 ( V_1128 ) ;
V_13 -> V_1130 = F_99 ( V_680 ) ;
V_13 -> V_1132 = F_99 ( V_1131 ) ;
V_13 -> V_1134 = F_99 ( V_1133 ) ;
V_13 -> V_1135 = F_99 ( V_393 ) ;
V_13 -> V_1136 = F_99 ( V_394 ) ;
V_13 -> V_1137 = F_99 ( V_683 ) ;
V_13 -> V_1138 = F_99 ( V_497 ) ;
V_13 -> V_1139 = F_99 ( V_551 ) ;
V_13 -> V_1140 = F_99 ( V_549 ) ;
V_13 -> V_1148 =
F_101 ( V_252 ) ;
V_13 -> V_1151 =
F_99 ( V_688 ) ;
if ( V_8 -> V_117 . V_1196 == V_1197 )
V_13 -> V_1176 = V_1177 ;
else
V_13 -> V_1176 = V_687 ;
if ( F_61 ( V_13 ) ) {
if ( V_13 -> V_697 &
V_324 )
V_13 -> V_1068 =
F_654 ( V_8 ) ;
F_657 ( & F_6 ( V_8 ) -> V_14 . V_888 ) ;
}
if ( V_102 ) {
V_13 -> V_534 = F_102 ( V_508 ) ;
V_13 -> V_1165 = F_102 ( V_515 ) ;
V_13 -> V_1166 = F_102 ( V_517 ) ;
V_13 -> V_1167 = F_102 ( V_518 ) ;
V_13 -> V_1168 = F_102 ( V_519 ) ;
}
if ( F_67 ( V_13 ) )
V_13 -> V_1159 = F_100 ( V_606 ) ;
V_13 -> V_1141 =
( V_13 -> V_1141 & ~ V_333 ) |
( F_115 ( F_6 ( V_8 ) ) & V_333 ) ;
if ( V_13 -> V_697 & V_328 ) {
F_417 ( V_8 , 7 , ( unsigned long * ) & V_13 -> V_1142 ) ;
V_13 -> V_1143 = F_102 ( V_689 ) ;
}
if ( V_13 -> V_697 & V_322 )
V_13 -> V_1162 = F_102 ( V_411 ) ;
if ( V_13 -> V_697 & V_323 )
V_13 -> V_1164 = V_8 -> V_117 . V_178 ;
V_13 -> V_1149 = F_101 ( V_397 ) ;
V_13 -> V_1152 = F_99 ( V_400 ) ;
V_13 -> V_1153 = F_99 ( V_399 ) ;
if ( F_213 () )
V_13 -> V_1163 = F_102 ( V_401 ) ;
if ( F_63 ( V_13 ) )
V_13 -> V_1154 = F_102 ( V_672 ) ;
V_13 -> V_1198 = V_260 ;
V_13 -> V_761 = V_761 ;
V_13 -> V_1199 = V_738 ;
if ( ( V_13 -> V_1199 &
( V_23 | V_267 ) ) ==
( V_23 | V_267 ) )
V_13 -> V_1200 =
F_101 ( V_740 ) ;
V_13 -> V_1192 = 0 ;
V_13 -> V_1190 = F_101 ( V_259 ) ;
V_13 -> V_891 = F_101 ( V_904 ) ;
if ( ! ( V_13 -> V_1198 & V_1003 ) ) {
V_13 -> V_1145 &= ~ V_23 ;
F_652 ( V_8 , V_13 ) ;
}
V_8 -> V_117 . V_798 = false ;
F_461 ( V_8 ) ;
F_460 ( V_8 ) ;
}
static void F_658 ( struct V_7 * V_8 ,
struct V_13 * V_13 )
{
struct V_471 V_114 ;
if ( V_13 -> V_697 & V_148 )
V_8 -> V_117 . V_178 = V_13 -> V_1185 ;
else if ( V_13 -> V_697 & V_320 )
V_8 -> V_117 . V_178 |= ( V_181 | V_182 ) ;
else
V_8 -> V_117 . V_178 &= ~ ( V_181 | V_182 ) ;
F_267 ( V_8 , V_8 -> V_117 . V_178 ) ;
F_408 ( V_8 , V_420 , V_13 -> V_1160 ) ;
F_408 ( V_8 , V_423 , V_13 -> V_1201 ) ;
F_179 ( V_8 , V_1202 ) ;
F_282 ( V_8 , V_13 -> V_1179 ) ;
F_129 ( V_8 ) ;
V_8 -> V_117 . V_234 = ( V_8 -> V_139 ? V_232 : 0 ) ;
F_106 ( V_236 , ~ V_8 -> V_117 . V_234 ) ;
V_8 -> V_117 . V_510 = ~ F_99 ( V_636 ) ;
F_400 ( V_8 , V_13 -> V_1180 ) ;
F_621 ( V_8 ) ;
F_406 ( V_8 , V_13 -> V_1203 ) ;
F_266 ( V_8 ) ;
if ( ! V_102 )
V_8 -> V_117 . V_513 -> V_1059 = F_517 ;
if ( V_590 ) {
F_271 ( V_8 ) ;
}
F_109 ( V_397 , V_13 -> V_1204 ) ;
F_106 ( V_400 , V_13 -> V_1205 ) ;
F_106 ( V_399 , V_13 -> V_1206 ) ;
F_106 ( V_549 , V_13 -> V_1207 ) ;
F_106 ( V_551 , V_13 -> V_1208 ) ;
if ( V_13 -> V_697 & V_326 )
F_110 ( V_401 , 0 ) ;
if ( V_13 -> V_697 & V_321 ) {
F_110 ( V_411 , V_13 -> V_1209 ) ;
V_8 -> V_117 . V_412 = V_13 -> V_1209 ;
}
if ( V_13 -> V_697 & V_152 )
F_110 ( V_164 ,
V_13 -> V_1210 ) ;
V_114 = (struct V_471 ) {
. V_124 = 0 ,
. V_126 = 0xFFFFFFFF ,
. V_121 = V_13 -> V_1211 ,
. type = 11 ,
. V_492 = 1 ,
. V_188 = 1 ,
. V_490 = 1
} ;
if ( V_13 -> V_697 & V_320 )
V_114 . V_493 = 1 ;
else
V_114 . V_491 = 1 ;
F_260 ( V_8 , & V_114 , V_473 ) ;
V_114 = (struct V_471 ) {
. V_124 = 0 ,
. V_126 = 0xFFFFFFFF ,
. type = 3 ,
. V_492 = 1 ,
. V_188 = 1 ,
. V_491 = 1 ,
. V_490 = 1
} ;
V_114 . V_121 = V_13 -> V_1212 ;
F_260 ( V_8 , & V_114 , V_480 ) ;
V_114 . V_121 = V_13 -> V_1213 ;
F_260 ( V_8 , & V_114 , V_479 ) ;
V_114 . V_121 = V_13 -> V_1214 ;
F_260 ( V_8 , & V_114 , V_474 ) ;
V_114 . V_121 = V_13 -> V_1215 ;
V_114 . V_124 = V_13 -> V_1216 ;
F_260 ( V_8 , & V_114 , V_481 ) ;
V_114 . V_121 = V_13 -> V_1217 ;
V_114 . V_124 = V_13 -> V_1218 ;
F_260 ( V_8 , & V_114 , V_482 ) ;
V_114 = (struct V_471 ) {
. V_124 = V_13 -> V_1219 ,
. V_126 = 0x67 ,
. V_121 = V_13 -> V_1220 ,
. type = 11 ,
. V_492 = 1
} ;
F_260 ( V_8 , & V_114 , V_483 ) ;
F_418 ( V_8 , 7 , 0x400 ) ;
F_110 ( V_689 , 0 ) ;
if ( F_24 () )
F_193 ( V_8 ) ;
if ( F_639 ( V_8 , V_13 -> V_1221 ,
V_13 -> V_1076 ) )
F_510 ( V_8 , V_1222 ) ;
}
static void F_186 ( struct V_7 * V_8 , T_2 V_260 ,
T_2 V_738 ,
unsigned long V_761 )
{
struct V_6 * V_74 = F_6 ( V_8 ) ;
struct V_13 * V_13 = F_11 ( V_8 ) ;
F_659 ( V_74 -> V_14 . V_711 ) ;
F_599 ( V_8 ) ;
F_656 ( V_8 , V_13 , V_260 , V_738 ,
V_761 ) ;
if ( F_640 ( V_8 , V_13 -> V_1223 ,
V_13 -> V_1077 ) )
F_510 ( V_8 , V_1224 ) ;
F_595 ( V_8 ) ;
if ( ( V_260 == V_956 )
&& F_364 ( V_8 ) ) {
int V_699 = F_660 ( V_8 ) ;
F_325 ( V_699 < 0 ) ;
V_13 -> V_1199 = V_699 |
V_23 | V_28 ;
}
F_661 ( V_13 -> V_1198 ,
V_13 -> V_761 ,
V_13 -> V_1192 ,
V_13 -> V_1199 ,
V_13 -> V_1200 ,
V_953 ) ;
F_113 ( V_74 , F_101 ( V_108 ) ) ;
F_118 ( V_74 , F_101 ( V_110 ) ) ;
F_123 ( V_74 ) ;
if ( V_874 == 0 )
F_505 ( V_74 , V_74 -> V_14 . V_869 ) ;
F_658 ( V_8 , V_13 ) ;
F_110 ( V_294 , V_74 -> V_14 . V_295 ) ;
V_74 -> V_1160 = 0 ;
if ( V_74 -> V_14 . V_922 ) {
F_15 ( V_74 -> V_14 . V_922 ) ;
V_74 -> V_14 . V_922 = NULL ;
}
if ( V_74 -> V_14 . V_605 ) {
F_15 ( V_74 -> V_14 . V_605 ) ;
V_74 -> V_14 . V_605 = NULL ;
}
if ( V_74 -> V_14 . V_923 ) {
F_334 ( V_74 -> V_14 . V_923 ) ;
F_15 ( V_74 -> V_14 . V_923 ) ;
V_74 -> V_14 . V_923 = NULL ;
V_74 -> V_14 . V_1 = NULL ;
}
F_645 ( V_8 ) ;
if ( F_107 ( V_74 -> V_954 ) ) {
V_74 -> V_954 = 0 ;
F_509 ( V_8 , F_101 ( V_105 ) ) ;
} else
F_507 ( V_8 ) ;
if ( V_646 )
V_74 -> V_14 . V_920 = true ;
V_8 -> V_117 . V_1196 = V_1225 ;
}
static void F_225 ( struct V_7 * V_8 )
{
if ( F_130 ( V_8 ) )
F_186 ( V_8 , - 1 , 0 , 0 ) ;
F_525 ( F_6 ( V_8 ) ) ;
}
static void F_647 ( struct V_7 * V_8 ,
struct V_13 * V_13 ,
T_2 V_792 , unsigned long V_1226 )
{
F_658 ( V_8 , V_13 ) ;
V_13 -> V_1198 = V_792 | V_1003 ;
V_13 -> V_761 = V_1226 ;
F_507 ( V_8 ) ;
if ( V_646 )
F_6 ( V_8 ) -> V_14 . V_920 = true ;
}
static int F_662 ( struct V_7 * V_8 ,
struct V_1227 * V_1228 ,
enum V_1229 V_1230 )
{
return V_1231 ;
}
static void F_663 ( struct V_7 * V_8 , int V_92 )
{
if ( V_640 )
F_481 ( V_8 ) ;
}
static void F_664 ( struct V_18 * V_18 ,
struct V_1232 * V_583 )
{
F_665 ( V_18 , V_583 ) ;
F_666 ( V_18 , V_583 ) ;
}
static void F_667 ( struct V_18 * V_18 ,
struct V_1232 * V_583 )
{
F_668 ( V_18 , V_583 ) ;
}
static void F_669 ( struct V_18 * V_18 )
{
F_564 ( V_18 ) ;
}
static void F_670 ( struct V_18 * V_18 ,
struct V_1232 * V_1233 ,
T_12 V_301 , unsigned long V_106 )
{
F_671 ( V_18 , V_1233 , V_301 , V_106 ) ;
}
static int T_11 F_672 ( void )
{
int V_564 = F_673 ( & V_1234 , sizeof( struct V_6 ) ,
F_674 ( struct V_6 ) , V_1235 ) ;
if ( V_564 )
return V_564 ;
#ifdef F_675
F_676 ( V_1236 ,
F_85 ) ;
#endif
return 0 ;
}
static void T_15 F_677 ( void )
{
#ifdef F_675
F_678 ( V_1236 , NULL ) ;
F_679 () ;
#endif
F_680 () ;
}
