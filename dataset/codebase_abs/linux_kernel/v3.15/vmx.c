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
static inline bool F_60 ( struct V_12 * V_12 )
{
return V_12 -> V_71 &
V_72 ;
}
static inline int F_61 ( struct V_12 * V_12 )
{
return F_58 ( V_12 , V_55 ) ;
}
static inline bool F_62 ( T_2 V_19 )
{
return ( V_19 & ( V_20 | V_22 ) )
== ( V_23 | V_22 ) ;
}
static int F_63 ( struct V_6 * V_73 , T_2 V_74 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_73 -> V_76 ; ++ V_75 )
if ( V_77 [ V_73 -> V_78 [ V_75 ] . V_79 ] == V_74 )
return V_75 ;
return - 1 ;
}
static inline void F_64 ( int V_80 , T_4 V_52 , T_5 V_81 )
{
struct {
T_3 V_52 : 16 ;
T_3 V_82 : 48 ;
T_3 V_81 ;
} V_83 = { V_52 , 0 , V_81 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_65 ( int V_80 , T_3 V_84 , T_1 V_85 )
{
struct {
T_3 V_84 , V_85 ;
} V_83 = { V_84 , V_85 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_86 * F_66 ( struct V_6 * V_73 , T_2 V_74 )
{
int V_75 ;
V_75 = F_63 ( V_73 , V_74 ) ;
if ( V_75 >= 0 )
return & V_73 -> V_78 [ V_75 ] ;
return NULL ;
}
static void F_67 ( struct V_87 * V_87 )
{
T_3 V_88 = F_68 ( V_87 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_69 ( V_89 L_1 ,
V_87 , V_88 ) ;
}
static inline void F_70 ( struct V_90 * V_90 )
{
F_67 ( V_90 -> V_87 ) ;
V_90 -> V_91 = - 1 ;
V_90 -> V_92 = 0 ;
}
static void F_71 ( struct V_87 * V_87 )
{
T_3 V_88 = F_68 ( V_87 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_69 ( V_89 L_2 ,
V_87 , V_88 ) ;
}
static inline void F_72 ( int V_91 )
{
F_73 ( V_91 , & V_93 ) ;
}
static inline void F_74 ( int V_91 )
{
F_75 ( V_91 , & V_93 ) ;
}
static inline int F_76 ( int V_91 )
{
return F_77 ( V_91 , & V_93 ) ;
}
static void F_78 ( void )
{
int V_91 = F_79 () ;
struct V_90 * V_94 ;
if ( ! F_76 ( V_91 ) )
return;
F_80 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_67 ( V_94 -> V_87 ) ;
}
static inline void F_72 ( int V_91 ) { }
static inline void F_74 ( int V_91 ) { }
static void F_81 ( void * V_95 )
{
struct V_90 * V_90 = V_95 ;
int V_91 = F_79 () ;
if ( V_90 -> V_91 != V_91 )
return;
if ( F_82 ( V_96 , V_91 ) == V_90 -> V_87 )
F_82 ( V_96 , V_91 ) = NULL ;
F_74 ( V_91 ) ;
F_83 ( & V_90 -> V_97 ) ;
F_84 () ;
F_70 ( V_90 ) ;
F_72 ( V_91 ) ;
}
static void F_85 ( struct V_90 * V_90 )
{
int V_91 = V_90 -> V_91 ;
if ( V_91 != - 1 )
F_86 ( V_91 ,
F_81 , V_90 , 1 ) ;
}
static inline void F_87 ( struct V_6 * V_73 )
{
if ( V_73 -> V_52 == 0 )
return;
if ( F_43 () )
F_64 ( V_98 , V_73 -> V_52 , 0 ) ;
}
static inline void F_88 ( void )
{
if ( F_44 () )
F_64 ( V_99 , 0 , 0 ) ;
}
static inline void F_89 ( struct V_6 * V_73 )
{
if ( F_43 () )
F_87 ( V_73 ) ;
else
F_88 () ;
}
static inline void F_90 ( void )
{
if ( F_42 () )
F_65 ( V_100 , 0 , 0 ) ;
}
static inline void F_91 ( T_3 V_84 )
{
if ( V_101 ) {
if ( F_41 () )
F_65 ( V_102 , V_84 , 0 ) ;
else
F_90 () ;
}
}
static T_7 unsigned long F_92 ( unsigned long V_9 )
{
unsigned long V_103 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_103 ;
}
static T_7 T_4 F_93 ( unsigned long V_9 )
{
return F_92 ( V_9 ) ;
}
static T_7 T_2 F_94 ( unsigned long V_9 )
{
return F_92 ( V_9 ) ;
}
static T_7 T_3 F_95 ( unsigned long V_9 )
{
#ifdef F_96
return F_92 ( V_9 ) ;
#else
return F_92 ( V_9 ) | ( ( T_3 ) F_92 ( V_9 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_97 ( unsigned long V_9 , unsigned long V_103 )
{
F_69 ( V_89 L_3 ,
V_9 , V_103 , F_94 ( V_104 ) ) ;
F_98 () ;
}
static void F_99 ( unsigned long V_9 , unsigned long V_103 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_100 ( error ) )
F_97 ( V_9 , V_103 ) ;
}
static void F_101 ( unsigned long V_9 , T_4 V_103 )
{
F_99 ( V_9 , V_103 ) ;
}
static void F_102 ( unsigned long V_9 , T_2 V_103 )
{
F_99 ( V_9 , V_103 ) ;
}
static void F_103 ( unsigned long V_9 , T_3 V_103 )
{
F_99 ( V_9 , V_103 ) ;
#ifndef F_96
asm volatile ("");
F_99 ( V_9 + 1 , V_103 >> 32 ) ;
#endif
}
static void F_104 ( unsigned long V_9 , T_2 V_105 )
{
F_99 ( V_9 , F_92 ( V_9 ) & ~ V_105 ) ;
}
static void F_105 ( unsigned long V_9 , T_2 V_105 )
{
F_99 ( V_9 , F_92 ( V_9 ) | V_105 ) ;
}
static inline void F_106 ( struct V_6 * V_73 , T_2 V_106 )
{
F_102 ( V_107 , V_106 ) ;
V_73 -> V_108 = V_106 ;
}
static inline void F_107 ( struct V_6 * V_73 , T_2 V_106 )
{
if ( V_73 -> V_108 != V_106 )
F_106 ( V_73 , V_106 ) ;
}
static inline T_2 F_108 ( struct V_6 * V_73 )
{
return V_73 -> V_108 ;
}
static inline void F_109 ( struct V_6 * V_73 , T_2 V_106 )
{
F_107 ( V_73 , F_108 ( V_73 ) | V_106 ) ;
}
static inline void F_110 ( struct V_6 * V_73 , T_2 V_106 )
{
F_107 ( V_73 , F_108 ( V_73 ) & ~ V_106 ) ;
}
static inline void F_111 ( struct V_6 * V_73 , T_2 V_106 )
{
F_102 ( V_109 , V_106 ) ;
V_73 -> V_110 = V_106 ;
}
static inline void F_112 ( struct V_6 * V_73 , T_2 V_106 )
{
if ( V_73 -> V_110 != V_106 )
F_111 ( V_73 , V_106 ) ;
}
static inline T_2 F_113 ( struct V_6 * V_73 )
{
return V_73 -> V_110 ;
}
static inline void F_114 ( struct V_6 * V_73 , T_2 V_106 )
{
F_112 ( V_73 , F_113 ( V_73 ) | V_106 ) ;
}
static inline void F_115 ( struct V_6 * V_73 , T_2 V_106 )
{
F_112 ( V_73 , F_113 ( V_73 ) & ~ V_106 ) ;
}
static void F_116 ( struct V_6 * V_73 )
{
V_73 -> V_111 . V_112 = 0 ;
}
static bool F_117 ( struct V_6 * V_73 , unsigned V_113 ,
unsigned V_9 )
{
bool V_114 ;
T_2 V_105 = 1 << ( V_113 * V_115 + V_9 ) ;
if ( ! ( V_73 -> V_8 . V_116 . V_117 & ( 1 << V_118 ) ) ) {
V_73 -> V_8 . V_116 . V_117 |= ( 1 << V_118 ) ;
V_73 -> V_111 . V_112 = 0 ;
}
V_114 = V_73 -> V_111 . V_112 & V_105 ;
V_73 -> V_111 . V_112 |= V_105 ;
return V_114 ;
}
static T_4 F_118 ( struct V_6 * V_73 , unsigned V_113 )
{
T_4 * V_119 = & V_73 -> V_111 . V_113 [ V_113 ] . V_120 ;
if ( ! F_117 ( V_73 , V_113 , V_121 ) )
* V_119 = F_93 ( V_122 [ V_113 ] . V_120 ) ;
return * V_119 ;
}
static T_9 F_119 ( struct V_6 * V_73 , unsigned V_113 )
{
T_9 * V_119 = & V_73 -> V_111 . V_113 [ V_113 ] . V_123 ;
if ( ! F_117 ( V_73 , V_113 , V_124 ) )
* V_119 = F_92 ( V_122 [ V_113 ] . V_123 ) ;
return * V_119 ;
}
static T_2 F_120 ( struct V_6 * V_73 , unsigned V_113 )
{
T_2 * V_119 = & V_73 -> V_111 . V_113 [ V_113 ] . V_125 ;
if ( ! F_117 ( V_73 , V_113 , V_126 ) )
* V_119 = F_94 ( V_122 [ V_113 ] . V_125 ) ;
return * V_119 ;
}
static T_2 F_121 ( struct V_6 * V_73 , unsigned V_113 )
{
T_2 * V_119 = & V_73 -> V_111 . V_113 [ V_113 ] . V_127 ;
if ( ! F_117 ( V_73 , V_113 , V_128 ) )
* V_119 = F_94 ( V_122 [ V_113 ] . V_129 ) ;
return * V_119 ;
}
static void F_122 ( struct V_7 * V_8 )
{
T_2 V_130 ;
V_130 = ( 1u << V_24 ) | ( 1u << V_26 ) | ( 1u << V_28 ) |
( 1u << V_25 ) | ( 1u << V_131 ) ;
if ( ( V_8 -> V_132 &
( V_133 | V_134 ) ) ==
( V_133 | V_134 ) )
V_130 |= 1u << V_135 ;
if ( F_6 ( V_8 ) -> V_136 . V_137 )
V_130 = ~ 0 ;
if ( V_101 )
V_130 &= ~ ( 1u << V_24 ) ;
if ( V_8 -> V_138 )
V_130 &= ~ ( 1u << V_25 ) ;
if ( F_123 ( V_8 ) )
V_130 |= F_9 ( V_8 ) -> V_139 ;
F_102 ( V_140 , V_130 ) ;
}
static void F_124 ( struct V_6 * V_73 ,
unsigned long V_141 , unsigned long exit )
{
F_110 ( V_73 , V_141 ) ;
F_115 ( V_73 , exit ) ;
}
static void F_125 ( struct V_6 * V_73 , unsigned V_74 )
{
unsigned V_75 ;
struct V_142 * V_143 = & V_73 -> V_142 ;
switch ( V_74 ) {
case V_144 :
if ( V_145 ) {
F_124 ( V_73 ,
V_146 ,
V_147 ) ;
return;
}
break;
case V_148 :
if ( V_149 ) {
F_124 ( V_73 ,
V_150 ,
V_151 ) ;
return;
}
break;
}
for ( V_75 = 0 ; V_75 < V_143 -> V_152 ; ++ V_75 )
if ( V_143 -> V_153 [ V_75 ] . V_79 == V_74 )
break;
if ( V_75 == V_143 -> V_152 )
return;
-- V_143 -> V_152 ;
V_143 -> V_153 [ V_75 ] = V_143 -> V_153 [ V_143 -> V_152 ] ;
V_143 -> V_154 [ V_75 ] = V_143 -> V_154 [ V_143 -> V_152 ] ;
F_102 ( V_155 , V_143 -> V_152 ) ;
F_102 ( V_156 , V_143 -> V_152 ) ;
}
static void F_126 ( struct V_6 * V_73 ,
unsigned long V_141 , unsigned long exit ,
unsigned long V_157 , unsigned long V_158 ,
T_3 V_159 , T_3 V_160 )
{
F_103 ( V_157 , V_159 ) ;
F_103 ( V_158 , V_160 ) ;
F_109 ( V_73 , V_141 ) ;
F_114 ( V_73 , exit ) ;
}
static void F_127 ( struct V_6 * V_73 , unsigned V_74 ,
T_3 V_159 , T_3 V_160 )
{
unsigned V_75 ;
struct V_142 * V_143 = & V_73 -> V_142 ;
switch ( V_74 ) {
case V_144 :
if ( V_145 ) {
F_126 ( V_73 ,
V_146 ,
V_147 ,
V_161 ,
V_162 ,
V_159 , V_160 ) ;
return;
}
break;
case V_148 :
if ( V_149 ) {
F_126 ( V_73 ,
V_150 ,
V_151 ,
V_163 ,
V_164 ,
V_159 , V_160 ) ;
return;
}
break;
}
for ( V_75 = 0 ; V_75 < V_143 -> V_152 ; ++ V_75 )
if ( V_143 -> V_153 [ V_75 ] . V_79 == V_74 )
break;
if ( V_75 == V_165 ) {
F_128 ( V_166 L_4
L_5 , V_74 ) ;
return;
} else if ( V_75 == V_143 -> V_152 ) {
++ V_143 -> V_152 ;
F_102 ( V_155 , V_143 -> V_152 ) ;
F_102 ( V_156 , V_143 -> V_152 ) ;
}
V_143 -> V_153 [ V_75 ] . V_79 = V_74 ;
V_143 -> V_153 [ V_75 ] . V_103 = V_159 ;
V_143 -> V_154 [ V_75 ] . V_79 = V_74 ;
V_143 -> V_154 [ V_75 ] . V_103 = V_160 ;
}
static void F_129 ( void )
{
struct V_167 * V_168 = & F_130 ( V_169 ) ;
struct V_170 * V_171 ;
V_171 = ( void * ) V_168 -> V_172 ;
V_171 [ V_173 ] . type = 9 ;
F_131 () ;
}
static bool F_132 ( struct V_6 * V_73 , int V_174 )
{
T_3 V_175 ;
T_3 V_176 ;
V_175 = V_73 -> V_8 . V_116 . V_177 ;
V_176 = V_178 | V_179 ;
#ifdef F_96
V_176 |= V_180 | V_181 ;
if ( V_175 & V_180 )
V_176 &= ~ ( T_3 ) V_179 ;
#endif
V_175 &= ~ V_176 ;
V_175 |= V_182 & V_176 ;
V_73 -> V_78 [ V_174 ] . V_183 = V_175 ;
V_73 -> V_78 [ V_174 ] . V_105 = ~ V_176 ;
F_125 ( V_73 , V_144 ) ;
if ( V_101 && ( ( V_73 -> V_8 . V_116 . V_177 ^ V_182 ) & V_178 ) ) {
V_175 = V_73 -> V_8 . V_116 . V_177 ;
if ( ! ( V_175 & V_180 ) )
V_175 &= ~ V_181 ;
F_127 ( V_73 , V_144 , V_175 , V_182 ) ;
return false ;
}
return true ;
}
static unsigned long F_133 ( T_4 V_120 )
{
struct V_167 * V_168 = & F_130 ( V_169 ) ;
struct V_170 * V_184 ;
unsigned long V_185 ;
unsigned long V_94 ;
if ( ! ( V_120 & ~ 3 ) )
return 0 ;
V_185 = V_168 -> V_172 ;
if ( V_120 & 4 ) {
T_4 V_186 = F_134 () ;
if ( ! ( V_186 & ~ 3 ) )
return 0 ;
V_185 = F_133 ( V_186 ) ;
}
V_184 = (struct V_170 * ) ( V_185 + ( V_120 & ~ 7 ) ) ;
V_94 = F_135 ( V_184 ) ;
#ifdef F_96
if ( V_184 -> V_187 == 0 && ( V_184 -> type == 2 || V_184 -> type == 9 || V_184 -> type == 11 ) )
V_94 |= ( ( unsigned long ) ( (struct V_188 * ) V_184 ) -> V_189 ) << 32 ;
#endif
return V_94 ;
}
static inline unsigned long F_136 ( void )
{
T_4 V_190 ;
asm("str %0" : "=g"(tr));
return F_133 ( V_190 ) ;
}
static void F_137 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_75 ;
if ( V_73 -> V_191 . V_192 )
return;
V_73 -> V_191 . V_192 = 1 ;
V_73 -> V_191 . V_193 = F_134 () ;
V_73 -> V_191 . V_194 = V_73 -> V_191 . V_193 ;
F_138 ( V_195 , V_73 -> V_191 . V_196 ) ;
if ( ! ( V_73 -> V_191 . V_196 & 7 ) ) {
F_101 ( V_197 , V_73 -> V_191 . V_196 ) ;
V_73 -> V_191 . V_198 = 0 ;
} else {
F_101 ( V_197 , 0 ) ;
V_73 -> V_191 . V_198 = 1 ;
}
F_138 ( V_199 , V_73 -> V_191 . V_200 ) ;
if ( ! ( V_73 -> V_191 . V_200 & 7 ) )
F_101 ( V_201 , V_73 -> V_191 . V_200 ) ;
else {
F_101 ( V_201 , 0 ) ;
V_73 -> V_191 . V_194 = 1 ;
}
#ifdef F_96
F_138 ( V_202 , V_73 -> V_191 . V_203 ) ;
F_138 ( V_204 , V_73 -> V_191 . V_205 ) ;
#endif
#ifdef F_96
F_99 ( V_206 , F_139 ( V_207 ) ) ;
F_99 ( V_208 , F_139 ( V_209 ) ) ;
#else
F_99 ( V_206 , F_133 ( V_73 -> V_191 . V_196 ) ) ;
F_99 ( V_208 , F_133 ( V_73 -> V_191 . V_200 ) ) ;
#endif
#ifdef F_96
F_55 ( V_210 , V_73 -> V_211 ) ;
if ( F_140 ( & V_73 -> V_8 ) )
F_141 ( V_210 , V_73 -> V_212 ) ;
#endif
if ( F_142 ( V_213 ) )
F_55 ( V_214 , V_73 -> V_191 . V_215 ) ;
for ( V_75 = 0 ; V_75 < V_73 -> V_216 ; ++ V_75 )
F_143 ( V_73 -> V_78 [ V_75 ] . V_79 ,
V_73 -> V_78 [ V_75 ] . V_183 ,
V_73 -> V_78 [ V_75 ] . V_105 ) ;
}
static void F_144 ( struct V_6 * V_73 )
{
if ( ! V_73 -> V_191 . V_192 )
return;
++ V_73 -> V_8 . V_217 . V_218 ;
V_73 -> V_191 . V_192 = 0 ;
#ifdef F_96
if ( F_140 ( & V_73 -> V_8 ) )
F_55 ( V_210 , V_73 -> V_212 ) ;
#endif
if ( V_73 -> V_191 . V_194 ) {
F_145 ( V_73 -> V_191 . V_193 ) ;
#ifdef F_96
F_146 ( V_73 -> V_191 . V_200 ) ;
#else
F_147 ( V_199 , V_73 -> V_191 . V_200 ) ;
#endif
}
if ( V_73 -> V_191 . V_198 )
F_147 ( V_195 , V_73 -> V_191 . V_196 ) ;
#ifdef F_96
if ( F_100 ( V_73 -> V_191 . V_203 | V_73 -> V_191 . V_205 ) ) {
F_147 ( V_202 , V_73 -> V_191 . V_203 ) ;
F_147 ( V_204 , V_73 -> V_191 . V_205 ) ;
}
#endif
F_129 () ;
#ifdef F_96
F_141 ( V_210 , V_73 -> V_211 ) ;
#endif
if ( V_73 -> V_191 . V_215 )
F_141 ( V_214 , V_73 -> V_191 . V_215 ) ;
if ( ! F_148 () && ! V_73 -> V_8 . V_219 )
F_149 () ;
F_150 ( & F_130 ( V_169 ) ) ;
}
static void F_151 ( struct V_6 * V_73 )
{
F_152 () ;
F_144 ( V_73 ) ;
F_153 () ;
}
static void F_154 ( struct V_7 * V_8 , int V_91 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_3 V_88 = F_68 ( F_82 ( V_220 , V_91 ) ) ;
if ( ! V_221 )
F_155 ( V_88 ) ;
else if ( V_73 -> V_90 -> V_91 != V_91 )
F_85 ( V_73 -> V_90 ) ;
if ( F_82 ( V_96 , V_91 ) != V_73 -> V_90 -> V_87 ) {
F_82 ( V_96 , V_91 ) = V_73 -> V_90 -> V_87 ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
}
if ( V_73 -> V_90 -> V_91 != V_91 ) {
struct V_167 * V_168 = & F_130 ( V_169 ) ;
unsigned long V_222 ;
F_156 ( V_223 , V_8 ) ;
F_157 () ;
F_74 ( V_91 ) ;
F_158 () ;
F_159 ( & V_73 -> V_90 -> V_97 ,
& F_82 ( V_224 , V_91 ) ) ;
F_72 ( V_91 ) ;
F_160 () ;
F_99 ( V_225 , F_136 () ) ;
F_99 ( V_226 , V_168 -> V_172 ) ;
F_55 ( V_227 , V_222 ) ;
F_99 ( V_228 , V_222 ) ;
V_73 -> V_90 -> V_91 = V_91 ;
}
}
static void F_161 ( struct V_7 * V_8 )
{
F_144 ( F_6 ( V_8 ) ) ;
if ( ! V_221 ) {
F_81 ( F_6 ( V_8 ) -> V_90 ) ;
V_8 -> V_91 = - 1 ;
F_162 () ;
}
}
static void F_163 ( struct V_7 * V_8 )
{
T_9 V_229 ;
if ( V_8 -> V_138 )
return;
V_8 -> V_138 = 1 ;
V_229 = F_92 ( V_230 ) ;
V_229 &= ~ ( V_231 | V_232 ) ;
V_229 |= F_164 ( V_8 , V_231 | V_232 ) ;
F_99 ( V_230 , V_229 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 = V_231 ;
if ( F_123 ( V_8 ) )
V_8 -> V_116 . V_233 &=
~ F_9 ( V_8 ) -> V_234 ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
}
static inline unsigned long F_165 ( struct V_12 * V_236 )
{
return ( V_236 -> V_237 & ~ V_236 -> V_234 ) |
( V_236 -> V_238 & V_236 -> V_234 ) ;
}
static inline unsigned long F_166 ( struct V_12 * V_236 )
{
return ( V_236 -> V_239 & ~ V_236 -> V_240 ) |
( V_236 -> V_241 & V_236 -> V_240 ) ;
}
static void F_167 ( struct V_7 * V_8 )
{
F_168 ( V_8 ) ;
F_105 ( V_230 , V_231 | V_232 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 = 0 ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
V_12 -> V_237 = ( V_12 -> V_237 & ~ V_231 ) |
( V_8 -> V_116 . V_229 & V_231 ) ;
F_99 ( V_242 , F_165 ( V_12 ) ) ;
} else
F_99 ( V_242 , V_8 -> V_116 . V_229 ) ;
}
static unsigned long F_169 ( struct V_7 * V_8 )
{
unsigned long V_243 , V_244 ;
if ( ! F_170 ( V_245 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ) {
F_171 ( V_245 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
V_243 = F_92 ( V_246 ) ;
if ( F_6 ( V_8 ) -> V_136 . V_137 ) {
V_243 &= V_247 ;
V_244 = F_6 ( V_8 ) -> V_136 . V_244 ;
V_243 |= V_244 & ~ V_247 ;
}
F_6 ( V_8 ) -> V_243 = V_243 ;
}
return F_6 ( V_8 ) -> V_243 ;
}
static void F_172 ( struct V_7 * V_8 , unsigned long V_243 )
{
F_171 ( V_245 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
F_6 ( V_8 ) -> V_243 = V_243 ;
if ( F_6 ( V_8 ) -> V_136 . V_137 ) {
F_6 ( V_8 ) -> V_136 . V_244 = V_243 ;
V_243 |= V_248 | V_249 ;
}
F_99 ( V_246 , V_243 ) ;
}
static T_2 F_173 ( struct V_7 * V_8 , int V_105 )
{
T_2 V_250 = F_94 ( V_251 ) ;
int V_114 = 0 ;
if ( V_250 & V_252 )
V_114 |= V_253 ;
if ( V_250 & V_254 )
V_114 |= V_255 ;
return V_114 & V_105 ;
}
static void F_174 ( struct V_7 * V_8 , int V_105 )
{
T_2 V_256 = F_94 ( V_251 ) ;
T_2 V_250 = V_256 ;
V_250 &= ~ ( V_252 | V_254 ) ;
if ( V_105 & V_255 )
V_250 |= V_254 ;
else if ( V_105 & V_253 )
V_250 |= V_252 ;
if ( ( V_250 != V_256 ) )
F_102 ( V_251 , V_250 ) ;
}
static void F_175 ( struct V_7 * V_8 )
{
unsigned long V_257 ;
V_257 = F_176 ( V_8 ) ;
V_257 += F_94 ( V_258 ) ;
F_177 ( V_8 , V_257 ) ;
F_174 ( V_8 , 0 ) ;
}
static int F_178 ( struct V_7 * V_8 , unsigned V_152 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( ! ( V_12 -> V_139 & ( 1u << V_152 ) ) )
return 0 ;
F_179 ( V_8 , F_6 ( V_8 ) -> V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
return 1 ;
}
static void F_180 ( struct V_7 * V_8 , unsigned V_152 ,
bool V_262 , T_2 V_263 ,
bool V_264 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_19 = V_152 | V_22 ;
if ( ! V_264 && F_123 ( V_8 ) &&
F_178 ( V_8 , V_152 ) )
return;
if ( V_262 ) {
F_102 ( V_265 , V_263 ) ;
V_19 |= V_266 ;
}
if ( V_73 -> V_136 . V_137 ) {
int V_267 = 0 ;
if ( F_181 ( V_152 ) )
V_267 = V_8 -> V_116 . V_268 ;
if ( F_182 ( V_8 , V_152 , V_267 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
if ( F_181 ( V_152 ) ) {
F_102 ( V_271 ,
V_73 -> V_8 . V_116 . V_268 ) ;
V_19 |= V_272 ;
} else
V_19 |= V_23 ;
F_102 ( V_273 , V_19 ) ;
}
static bool F_183 ( void )
{
return F_50 () ;
}
static bool F_184 ( void )
{
return F_51 () && V_101 ;
}
static void F_185 ( struct V_6 * V_73 , int V_274 , int V_275 )
{
struct V_86 V_276 ;
V_276 = V_73 -> V_78 [ V_275 ] ;
V_73 -> V_78 [ V_275 ] = V_73 -> V_78 [ V_274 ] ;
V_73 -> V_78 [ V_274 ] = V_276 ;
}
static void F_186 ( struct V_7 * V_8 )
{
unsigned long * V_277 ;
if ( F_25 ( V_8 -> V_17 ) && F_187 ( V_8 -> V_116 . V_278 ) ) {
if ( F_140 ( V_8 ) )
V_277 = V_279 ;
else
V_277 = V_280 ;
} else {
if ( F_140 ( V_8 ) )
V_277 = V_281 ;
else
V_277 = V_282 ;
}
F_103 ( V_283 , F_68 ( V_277 ) ) ;
}
static void F_188 ( struct V_6 * V_73 )
{
int V_216 , V_79 ;
V_216 = 0 ;
#ifdef F_96
if ( F_140 ( & V_73 -> V_8 ) ) {
V_79 = F_63 ( V_73 , V_284 ) ;
if ( V_79 >= 0 )
F_185 ( V_73 , V_79 , V_216 ++ ) ;
V_79 = F_63 ( V_73 , V_285 ) ;
if ( V_79 >= 0 )
F_185 ( V_73 , V_79 , V_216 ++ ) ;
V_79 = F_63 ( V_73 , V_286 ) ;
if ( V_79 >= 0 )
F_185 ( V_73 , V_79 , V_216 ++ ) ;
V_79 = F_63 ( V_73 , V_287 ) ;
if ( V_79 >= 0 && V_73 -> V_288 )
F_185 ( V_73 , V_79 , V_216 ++ ) ;
V_79 = F_63 ( V_73 , V_289 ) ;
if ( ( V_79 >= 0 ) && ( V_73 -> V_8 . V_116 . V_177 & V_179 ) )
F_185 ( V_73 , V_79 , V_216 ++ ) ;
}
#endif
V_79 = F_63 ( V_73 , V_144 ) ;
if ( V_79 >= 0 && F_132 ( V_73 , V_79 ) )
F_185 ( V_73 , V_79 , V_216 ++ ) ;
V_73 -> V_216 = V_216 ;
if ( F_22 () )
F_186 ( & V_73 -> V_8 ) ;
}
static T_3 F_189 ( void )
{
T_3 V_290 , V_291 ;
F_190 ( V_290 ) ;
V_291 = F_95 ( V_292 ) ;
return V_290 + V_291 ;
}
T_3 F_191 ( struct V_7 * V_8 , T_3 V_290 )
{
T_3 V_291 ;
V_291 = F_123 ( V_8 ) ?
F_6 ( V_8 ) -> V_13 . V_293 :
F_95 ( V_292 ) ;
return V_290 + V_291 ;
}
static void F_192 ( struct V_7 * V_8 , T_2 V_294 , bool V_295 )
{
if ( ! V_295 )
return;
if ( V_294 > V_296 ) {
V_8 -> V_116 . V_297 = 1 ;
V_8 -> V_116 . V_298 = 1 ;
} else
F_193 ( 1 , L_6 ) ;
}
static T_3 F_194 ( struct V_7 * V_8 )
{
return F_95 ( V_292 ) ;
}
static void F_195 ( struct V_7 * V_8 , T_3 V_299 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 ;
F_6 ( V_8 ) -> V_13 . V_293 = V_299 ;
V_12 = F_9 ( V_8 ) ;
F_103 ( V_292 , V_299 +
( F_57 ( V_12 , V_300 ) ?
V_12 -> V_291 : 0 ) ) ;
} else {
F_196 ( V_8 -> V_301 ,
F_95 ( V_292 ) , V_299 ) ;
F_103 ( V_292 , V_299 ) ;
}
}
static void F_197 ( struct V_7 * V_8 , T_10 V_302 , bool V_154 )
{
T_3 V_299 = F_95 ( V_292 ) ;
F_103 ( V_292 , V_299 + V_302 ) ;
if ( F_123 ( V_8 ) ) {
F_6 ( V_8 ) -> V_13 . V_293 += V_302 ;
} else
F_196 ( V_8 -> V_301 , V_299 ,
V_299 + V_302 ) ;
}
static T_3 F_198 ( struct V_7 * V_8 , T_3 V_303 )
{
return V_303 - F_199 () ;
}
static bool F_200 ( struct V_7 * V_8 )
{
struct V_304 * V_305 = F_201 ( V_8 , 1 , 0 ) ;
return V_305 && ( V_305 -> V_306 & ( 1 << ( V_307 & 31 ) ) ) ;
}
static inline bool F_202 ( struct V_7 * V_8 )
{
return V_13 && F_200 ( V_8 ) ;
}
static T_11 void F_203 ( void )
{
F_204 ( V_308 ,
V_309 , V_310 ) ;
V_309 |= V_311 ;
V_310 &= V_312 |
V_313 | V_62 ;
V_310 |= V_311 |
V_72 ;
F_204 ( V_314 ,
V_315 , V_316 ) ;
V_315 = V_317 ;
V_316 &=
#ifdef F_96
V_318 |
#endif
V_319 | V_320 ;
V_316 |= V_317 |
V_147 | V_321 |
V_322 ;
if ( F_205 () )
V_316 |= V_323 ;
F_204 ( V_324 ,
V_325 , V_326 ) ;
V_325 = V_327 ;
V_326 &=
#ifdef F_96
V_328 |
#endif
V_329 ;
V_326 |= ( V_327 |
V_146 ) ;
if ( F_205 () )
V_326 |= V_330 ;
F_204 ( V_331 ,
V_332 , V_333 ) ;
V_332 = 0 ;
V_333 &=
V_334 |
V_335 | V_300 |
V_336 | V_337 |
V_338 | V_339 |
V_340 |
#ifdef F_96
V_341 | V_342 |
#endif
V_343 | V_344 |
V_345 | V_346 |
V_347 | V_348 |
V_349 |
V_33 ;
V_333 |= V_31 ;
F_204 ( V_350 ,
V_351 , V_352 ) ;
V_351 = 0 ;
V_352 &=
V_35 |
V_56 |
V_63 ;
if ( V_101 ) {
V_352 |= V_55 ;
V_353 = V_48 |
V_45 | V_46 |
V_354 ;
V_353 &= V_41 . V_42 ;
V_353 |= V_51 |
V_50 ;
} else
V_353 = 0 ;
F_204 ( V_65 , V_355 , V_356 ) ;
V_355 &= V_357 ;
V_355 |= V_358 |
V_359 ;
V_356 = 0 ;
}
static inline bool F_206 ( T_2 V_3 , T_2 V_360 , T_2 V_361 )
{
return ( ( V_3 & V_361 ) | V_360 ) == V_3 ;
}
static inline T_3 F_207 ( T_2 V_360 , T_2 V_361 )
{
return V_360 | ( ( T_3 ) V_361 << 32 ) ;
}
static int F_208 ( struct V_7 * V_8 , T_2 V_362 , T_3 * V_363 )
{
switch ( V_362 ) {
case V_364 :
* V_363 = V_365 |
( ( T_3 ) V_366 << V_367 ) |
( V_368 << V_369 ) ;
break;
case V_370 :
case V_308 :
* V_363 = F_207 ( V_309 ,
V_310 ) ;
break;
case V_371 :
case V_331 :
* V_363 = F_207 ( V_332 ,
V_333 ) ;
break;
case V_372 :
case V_314 :
* V_363 = F_207 ( V_315 ,
V_316 ) ;
break;
case V_373 :
case V_324 :
* V_363 = F_207 ( V_325 ,
V_326 ) ;
break;
case V_65 :
* V_363 = F_207 ( V_355 ,
V_356 ) ;
break;
#define F_209 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_210 X86_CR4_VMXE
case V_374 :
* V_363 = F_209 ;
break;
case V_375 :
* V_363 = - 1ULL ;
break;
case V_376 :
* V_363 = F_210 ;
break;
case V_377 :
* V_363 = - 1ULL ;
break;
case V_378 :
* V_363 = 0x1f ;
break;
case V_350 :
* V_363 = F_207 ( V_351 ,
V_352 ) ;
break;
case V_379 :
* V_363 = V_353 ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_211 ( struct V_7 * V_8 , T_2 V_362 , T_3 * V_363 )
{
T_3 V_183 ;
struct V_86 * V_74 ;
if ( ! V_363 ) {
F_69 ( V_89 L_7 ) ;
return - V_380 ;
}
switch ( V_362 ) {
#ifdef F_96
case V_207 :
V_183 = F_92 ( V_381 ) ;
break;
case V_209 :
V_183 = F_92 ( V_382 ) ;
break;
case V_210 :
F_151 ( F_6 ( V_8 ) ) ;
V_183 = F_6 ( V_8 ) -> V_212 ;
break;
#endif
case V_144 :
return F_212 ( V_8 , V_362 , V_363 ) ;
case V_383 :
V_183 = F_189 () ;
break;
case V_384 :
V_183 = F_94 ( V_385 ) ;
break;
case V_386 :
V_183 = F_92 ( V_387 ) ;
break;
case V_227 :
V_183 = F_92 ( V_388 ) ;
break;
case V_214 :
if ( ! F_205 () )
return 1 ;
V_183 = F_95 ( V_389 ) ;
break;
case V_390 :
if ( ! F_202 ( V_8 ) )
return 1 ;
V_183 = F_6 ( V_8 ) -> V_13 . V_391 ;
break;
case V_364 ... V_392 :
if ( ! F_202 ( V_8 ) )
return 1 ;
return F_208 ( V_8 , V_362 , V_363 ) ;
case V_287 :
if ( ! F_6 ( V_8 ) -> V_288 )
return 1 ;
default:
V_74 = F_66 ( F_6 ( V_8 ) , V_362 ) ;
if ( V_74 ) {
V_183 = V_74 -> V_183 ;
break;
}
return F_212 ( V_8 , V_362 , V_363 ) ;
}
* V_363 = V_183 ;
return 0 ;
}
static int F_213 ( struct V_7 * V_8 , struct V_393 * V_394 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_86 * V_74 ;
int V_114 = 0 ;
T_2 V_362 = V_394 -> V_79 ;
T_3 V_183 = V_394 -> V_183 ;
switch ( V_362 ) {
case V_144 :
V_114 = F_214 ( V_8 , V_394 ) ;
break;
#ifdef F_96
case V_207 :
F_116 ( V_73 ) ;
F_99 ( V_381 , V_183 ) ;
break;
case V_209 :
F_116 ( V_73 ) ;
F_99 ( V_382 , V_183 ) ;
break;
case V_210 :
F_151 ( V_73 ) ;
V_73 -> V_212 = V_183 ;
break;
#endif
case V_384 :
F_102 ( V_385 , V_183 ) ;
break;
case V_386 :
F_99 ( V_387 , V_183 ) ;
break;
case V_227 :
F_99 ( V_388 , V_183 ) ;
break;
case V_214 :
if ( ! F_205 () )
return 1 ;
F_103 ( V_389 , V_183 ) ;
break;
case V_383 :
F_215 ( V_8 , V_394 ) ;
break;
case V_395 :
if ( V_29 . V_396 & V_329 ) {
F_103 ( V_397 , V_183 ) ;
V_8 -> V_116 . V_398 = V_183 ;
break;
}
V_114 = F_214 ( V_8 , V_394 ) ;
break;
case V_399 :
V_114 = F_214 ( V_8 , V_394 ) ;
break;
case V_390 :
if ( ! F_202 ( V_8 ) ||
( F_6 ( V_8 ) -> V_13 . V_391 &
V_400 && ! V_394 -> V_401 ) )
return 1 ;
V_73 -> V_13 . V_391 = V_183 ;
if ( V_394 -> V_401 && V_183 == 0 )
F_216 ( V_8 ) ;
break;
case V_364 ... V_392 :
return 1 ;
case V_287 :
if ( ! V_73 -> V_288 )
return 1 ;
if ( ( V_183 >> 32 ) != 0 )
return 1 ;
default:
V_74 = F_66 ( V_73 , V_362 ) ;
if ( V_74 ) {
V_74 -> V_183 = V_183 ;
if ( V_74 - V_73 -> V_78 < V_73 -> V_216 ) {
F_152 () ;
F_143 ( V_74 -> V_79 , V_74 -> V_183 ,
V_74 -> V_105 ) ;
F_153 () ;
}
break;
}
V_114 = F_214 ( V_8 , V_394 ) ;
}
return V_114 ;
}
static void F_217 ( struct V_7 * V_8 , enum V_402 V_403 )
{
F_171 ( V_403 , ( unsigned long * ) & V_8 -> V_116 . V_117 ) ;
switch ( V_403 ) {
case V_404 :
V_8 -> V_116 . V_405 [ V_404 ] = F_92 ( V_406 ) ;
break;
case V_407 :
V_8 -> V_116 . V_405 [ V_407 ] = F_92 ( V_408 ) ;
break;
case V_409 :
if ( V_101 )
F_218 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_219 ( void )
{
return F_220 () ;
}
static T_11 int F_221 ( void )
{
T_3 V_74 ;
F_55 ( V_390 , V_74 ) ;
if ( V_74 & V_400 ) {
if ( ! ( V_74 & V_410 )
&& F_222 () )
return 1 ;
if ( ! ( V_74 & V_411 )
&& ( V_74 & V_410 )
&& ! F_222 () ) {
F_69 ( V_166 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_74 & V_411 )
&& ! F_222 () )
return 1 ;
}
return 0 ;
}
static void F_155 ( T_3 V_16 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_223 ( void * V_412 )
{
int V_91 = F_79 () ;
T_3 V_88 = F_68 ( F_82 ( V_220 , V_91 ) ) ;
T_3 V_413 , V_414 ;
if ( F_224 () & V_415 )
return - V_416 ;
F_225 ( & F_82 ( V_224 , V_91 ) ) ;
F_72 ( V_91 ) ;
F_55 ( V_390 , V_413 ) ;
V_414 = V_400 ;
V_414 |= V_411 ;
if ( F_222 () )
V_414 |= V_410 ;
if ( ( V_413 & V_414 ) != V_414 ) {
F_141 ( V_390 , V_413 | V_414 ) ;
}
F_226 ( F_224 () | V_415 ) ;
if ( V_221 ) {
F_155 ( V_88 ) ;
F_90 () ;
}
F_227 ( & F_130 ( V_169 ) ) ;
return 0 ;
}
static void F_228 ( void )
{
int V_91 = F_79 () ;
struct V_90 * V_94 , * V_417 ;
F_229 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_81 ( V_94 ) ;
}
static void F_162 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_230 ( void * V_412 )
{
if ( V_221 ) {
F_228 () ;
F_162 () ;
}
F_226 ( F_224 () & ~ V_415 ) ;
}
static T_11 int F_231 ( T_2 V_418 , T_2 V_419 ,
T_2 V_74 , T_2 * V_420 )
{
T_2 V_421 , V_422 ;
T_2 V_423 = V_418 | V_419 ;
F_204 ( V_74 , V_421 , V_422 ) ;
V_423 &= V_422 ;
V_423 |= V_421 ;
if ( V_418 & ~ V_423 )
return - V_424 ;
* V_420 = V_423 ;
return 0 ;
}
static T_11 bool F_232 ( T_2 V_74 , T_2 V_423 )
{
T_2 V_421 , V_422 ;
F_204 ( V_74 , V_421 , V_422 ) ;
return V_422 & V_423 ;
}
static T_11 int F_233 ( struct V_29 * V_425 )
{
T_2 V_421 , V_422 ;
T_2 V_426 , V_427 , V_428 , V_429 ;
T_2 V_430 = 0 ;
T_2 V_431 = 0 ;
T_2 V_432 = 0 ;
T_2 V_433 = 0 ;
T_2 V_434 = 0 ;
V_426 = V_336 |
#ifdef F_96
V_341 |
V_342 |
#endif
V_339 |
V_340 |
V_345 |
V_343 |
V_300 |
V_338 |
V_346 |
V_337 |
V_347 ;
V_427 = V_32 |
V_31 |
V_33 ;
if ( F_231 ( V_426 , V_427 , V_331 ,
& V_431 ) < 0 )
return - V_424 ;
#ifdef F_96
if ( ( V_431 & V_32 ) )
V_431 &= ~ V_341 &
~ V_342 ;
#endif
if ( V_431 & V_33 ) {
V_428 = 0 ;
V_429 = V_35 |
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
if ( F_231 ( V_428 , V_429 ,
V_350 ,
& V_432 ) < 0 )
return - V_424 ;
}
#ifndef F_96
if ( ! ( V_432 &
V_35 ) )
V_431 &= ~ V_32 ;
#endif
if ( ! ( V_431 & V_32 ) )
V_432 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_432 & V_55 ) {
V_431 &= ~ ( V_339 |
V_340 |
V_337 ) ;
F_204 ( V_379 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_426 = V_435 ;
#ifdef F_96
V_426 |= V_318 ;
#endif
V_427 = V_320 | V_319 |
V_436 | V_323 ;
if ( F_231 ( V_426 , V_427 , V_314 ,
& V_433 ) < 0 )
return - V_424 ;
V_426 = V_312 | V_313 ;
V_427 = V_62 | V_40 ;
if ( F_231 ( V_426 , V_427 , V_308 ,
& V_430 ) < 0 )
return - V_424 ;
if ( ! ( V_432 &
V_38 ) ||
! ( V_433 & V_436 ) )
V_430 &= ~ V_40 ;
V_426 = V_437 ;
V_427 = V_329 | V_330 ;
if ( F_231 ( V_426 , V_427 , V_324 ,
& V_434 ) < 0 )
return - V_424 ;
F_204 ( V_364 , V_421 , V_422 ) ;
if ( ( V_422 & 0x1fff ) > V_438 )
return - V_424 ;
#ifdef F_96
if ( V_422 & ( 1u << 16 ) )
return - V_424 ;
#endif
if ( ( ( V_422 >> 18 ) & 15 ) != 6 )
return - V_424 ;
V_425 -> V_439 = V_422 & 0x1fff ;
V_425 -> V_440 = F_234 ( V_29 . V_439 ) ;
V_425 -> V_441 = V_421 ;
V_425 -> V_39 = V_430 ;
V_425 -> V_30 = V_431 ;
V_425 -> V_34 = V_432 ;
V_425 -> V_442 = V_433 ;
V_425 -> V_396 = V_434 ;
V_145 =
F_232 ( V_324 ,
V_146 )
&& F_232 ( V_314 ,
V_147 ) ;
V_149 =
F_232 ( V_324 ,
V_150 )
&& F_232 ( V_314 ,
V_151 ) ;
if ( V_149 && V_443 . V_444 == 0x6 ) {
switch ( V_443 . V_445 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_149 = false ;
F_128 ( V_166 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_87 * F_235 ( int V_91 )
{
int V_446 = F_236 ( V_91 ) ;
struct V_15 * V_447 ;
struct V_87 * V_87 ;
V_447 = F_237 ( V_446 , V_448 , V_29 . V_440 ) ;
if ( ! V_447 )
return NULL ;
V_87 = F_238 ( V_447 ) ;
memset ( V_87 , 0 , V_29 . V_439 ) ;
V_87 -> V_441 = V_29 . V_441 ;
return V_87 ;
}
static struct V_87 * F_239 ( void )
{
return F_235 ( F_79 () ) ;
}
static void F_240 ( struct V_87 * V_87 )
{
F_241 ( ( unsigned long ) V_87 , V_29 . V_440 ) ;
}
static void F_242 ( struct V_90 * V_90 )
{
if ( ! V_90 -> V_87 )
return;
F_85 ( V_90 ) ;
F_240 ( V_90 -> V_87 ) ;
V_90 -> V_87 = NULL ;
}
static void F_243 ( void )
{
int V_91 ;
F_244 (cpu) {
F_240 ( F_82 ( V_220 , V_91 ) ) ;
F_82 ( V_220 , V_91 ) = NULL ;
}
}
static void F_245 ( void )
{
int V_75 , V_449 ;
for ( V_75 = V_449 = 0 ; V_75 < V_450 ; V_75 ++ ) {
switch ( V_451 [ V_75 ] ) {
case V_389 :
if ( ! F_205 () )
continue;
break;
default:
break;
}
if ( V_449 < V_75 )
V_451 [ V_449 ] =
V_451 [ V_75 ] ;
V_449 ++ ;
}
V_450 = V_449 ;
for ( V_75 = 0 ; V_75 < V_450 ; V_75 ++ ) {
F_246 ( V_451 [ V_75 ] ,
V_452 ) ;
F_246 ( V_451 [ V_75 ] ,
V_453 ) ;
}
for ( V_75 = 0 ; V_75 < V_454 ; V_75 ++ )
F_246 ( V_455 [ V_75 ] ,
V_453 ) ;
}
static T_11 int F_247 ( void )
{
int V_91 ;
F_244 (cpu) {
struct V_87 * V_87 ;
V_87 = F_235 ( V_91 ) ;
if ( ! V_87 ) {
F_243 () ;
return - V_456 ;
}
F_82 ( V_220 , V_91 ) = V_87 ;
}
return 0 ;
}
static T_11 int F_248 ( void )
{
if ( F_233 ( & V_29 ) < 0 )
return - V_424 ;
if ( F_142 ( V_457 ) )
F_249 ( V_178 ) ;
if ( ! F_49 () )
V_458 = 0 ;
if ( ! F_54 () )
V_459 = 0 ;
if ( V_459 )
F_245 () ;
if ( ! F_45 () ||
! F_39 () ) {
V_101 = 0 ;
V_460 = 0 ;
V_461 = 0 ;
}
if ( ! F_40 () )
V_461 = 0 ;
if ( ! F_46 () )
V_460 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_462 -> V_463 = NULL ;
if ( V_101 && ! F_37 () )
F_250 () ;
if ( ! F_47 () )
V_464 = 0 ;
if ( ! F_32 () )
V_465 = 0 ;
if ( V_465 )
V_462 -> V_463 = NULL ;
else {
V_462 -> V_466 = NULL ;
V_462 -> V_467 = NULL ;
V_462 -> V_468 = V_469 ;
}
if ( V_13 )
F_203 () ;
return F_247 () ;
}
static T_12 void F_251 ( void )
{
F_243 () ;
}
static bool F_252 ( struct V_7 * V_8 )
{
return V_470 && ! F_253 ( V_8 ) ;
}
static void F_254 ( struct V_7 * V_8 , int V_113 ,
struct V_471 * V_472 )
{
if ( ! V_470 ) {
if ( V_113 == V_473 || V_113 == V_474 )
V_472 -> V_120 &= ~ V_475 ;
V_472 -> V_476 = V_472 -> V_120 & V_475 ;
V_472 -> V_187 = 1 ;
}
F_255 ( V_8 , V_472 , V_113 ) ;
}
static void F_256 ( struct V_7 * V_8 )
{
unsigned long V_477 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_479 ] , V_479 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_480 ] , V_480 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_481 ] , V_481 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_482 ] , V_482 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_474 ] , V_474 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_473 ] , V_473 ) ;
V_73 -> V_136 . V_137 = 0 ;
F_116 ( V_73 ) ;
F_255 ( V_8 , & V_73 -> V_136 . V_478 [ V_483 ] , V_483 ) ;
V_477 = F_92 ( V_246 ) ;
V_477 &= V_247 ;
V_477 |= V_73 -> V_136 . V_244 & ~ V_247 ;
F_99 ( V_246 , V_477 ) ;
F_99 ( V_484 , ( F_92 ( V_484 ) & ~ V_485 ) |
( F_92 ( V_486 ) & V_485 ) ) ;
F_122 ( V_8 ) ;
F_254 ( V_8 , V_473 , & V_73 -> V_136 . V_478 [ V_473 ] ) ;
F_254 ( V_8 , V_474 , & V_73 -> V_136 . V_478 [ V_474 ] ) ;
F_254 ( V_8 , V_479 , & V_73 -> V_136 . V_478 [ V_479 ] ) ;
F_254 ( V_8 , V_480 , & V_73 -> V_136 . V_478 [ V_480 ] ) ;
F_254 ( V_8 , V_481 , & V_73 -> V_136 . V_478 [ V_481 ] ) ;
F_254 ( V_8 , V_482 , & V_73 -> V_136 . V_478 [ V_482 ] ) ;
F_171 ( V_487 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
V_73 -> V_488 = 0 ;
}
static void F_258 ( int V_113 , struct V_471 * V_472 )
{
const struct V_489 * V_490 = & V_122 [ V_113 ] ;
struct V_471 V_491 = * V_472 ;
V_491 . V_476 = 0x3 ;
if ( V_113 == V_473 )
V_491 . type = 0x3 ;
if ( ! V_470 ) {
V_491 . V_120 = V_491 . V_123 >> 4 ;
V_491 . V_123 = V_491 . V_123 & 0xffff0 ;
V_491 . V_125 = 0xffff ;
V_491 . V_492 = 0 ;
V_491 . V_493 = 0 ;
V_491 . V_494 = 1 ;
V_491 . V_187 = 1 ;
V_491 . V_495 = 0 ;
V_491 . V_496 = 0 ;
V_491 . type = 0x3 ;
V_491 . V_497 = 0 ;
if ( V_472 -> V_123 & 0xf )
F_128 ( V_166 L_12
L_13
L_14 , V_113 ) ;
}
F_101 ( V_490 -> V_120 , V_491 . V_120 ) ;
F_102 ( V_490 -> V_123 , V_491 . V_123 ) ;
F_102 ( V_490 -> V_125 , V_491 . V_125 ) ;
F_102 ( V_490 -> V_129 , F_259 ( & V_491 ) ) ;
}
static void F_260 ( struct V_7 * V_8 )
{
unsigned long V_477 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_483 ] , V_483 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_479 ] , V_479 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_480 ] , V_480 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_481 ] , V_481 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_482 ] , V_482 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_474 ] , V_474 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_478 [ V_473 ] , V_473 ) ;
V_73 -> V_136 . V_137 = 1 ;
if ( ! V_8 -> V_17 -> V_116 . V_498 )
F_128 ( V_166 L_15
L_16 ) ;
F_116 ( V_73 ) ;
F_99 ( V_499 , V_8 -> V_17 -> V_116 . V_498 ) ;
F_102 ( V_500 , V_501 - 1 ) ;
F_102 ( V_502 , 0x008b ) ;
V_477 = F_92 ( V_246 ) ;
V_73 -> V_136 . V_244 = V_477 ;
V_477 |= V_248 | V_249 ;
F_99 ( V_246 , V_477 ) ;
F_99 ( V_484 , F_92 ( V_484 ) | V_485 ) ;
F_122 ( V_8 ) ;
F_258 ( V_474 , & V_73 -> V_136 . V_478 [ V_474 ] ) ;
F_258 ( V_473 , & V_73 -> V_136 . V_478 [ V_473 ] ) ;
F_258 ( V_479 , & V_73 -> V_136 . V_478 [ V_479 ] ) ;
F_258 ( V_480 , & V_73 -> V_136 . V_478 [ V_480 ] ) ;
F_258 ( V_482 , & V_73 -> V_136 . V_478 [ V_482 ] ) ;
F_258 ( V_481 , & V_73 -> V_136 . V_478 [ V_481 ] ) ;
F_261 ( V_8 ) ;
}
static void F_262 ( struct V_7 * V_8 , T_3 V_177 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_86 * V_74 = F_66 ( V_73 , V_144 ) ;
if ( ! V_74 )
return;
F_151 ( F_6 ( V_8 ) ) ;
V_8 -> V_116 . V_177 = V_177 ;
if ( V_177 & V_180 ) {
F_109 ( F_6 ( V_8 ) , V_328 ) ;
V_74 -> V_183 = V_177 ;
} else {
F_110 ( F_6 ( V_8 ) , V_328 ) ;
V_74 -> V_183 = V_177 & ~ V_181 ;
}
F_188 ( V_73 ) ;
}
static void F_263 ( struct V_7 * V_8 )
{
T_2 V_503 ;
F_116 ( F_6 ( V_8 ) ) ;
V_503 = F_94 ( V_502 ) ;
if ( ( V_503 & V_504 ) != V_505 ) {
F_264 ( L_17 ,
V_506 ) ;
F_102 ( V_502 ,
( V_503 & ~ V_504 )
| V_505 ) ;
}
F_262 ( V_8 , V_8 -> V_116 . V_177 | V_180 ) ;
}
static void F_265 ( struct V_7 * V_8 )
{
F_110 ( F_6 ( V_8 ) , V_328 ) ;
F_262 ( V_8 , V_8 -> V_116 . V_177 & ~ V_180 ) ;
}
static void F_266 ( struct V_7 * V_8 )
{
F_89 ( F_6 ( V_8 ) ) ;
if ( V_101 ) {
if ( ! F_267 ( V_8 -> V_116 . V_507 . V_508 ) )
return;
F_91 ( F_268 ( V_8 -> V_116 . V_507 . V_508 ) ) ;
}
}
static void F_168 ( struct V_7 * V_8 )
{
T_9 V_233 = V_8 -> V_116 . V_233 ;
V_8 -> V_116 . V_229 &= ~ V_233 ;
V_8 -> V_116 . V_229 |= F_92 ( V_230 ) & V_233 ;
}
static void F_269 ( struct V_7 * V_8 )
{
if ( V_101 && F_270 ( V_8 ) )
V_8 -> V_116 . V_509 = F_92 ( V_510 ) ;
F_171 ( V_511 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
}
static void F_271 ( struct V_7 * V_8 )
{
T_9 V_512 = V_8 -> V_116 . V_512 ;
V_8 -> V_116 . V_513 &= ~ V_512 ;
V_8 -> V_116 . V_513 |= F_92 ( V_484 ) & V_512 ;
}
static void F_272 ( struct V_7 * V_8 )
{
struct V_514 * V_507 = V_8 -> V_116 . V_515 ;
if ( ! F_170 ( V_409 ,
( unsigned long * ) & V_8 -> V_116 . V_516 ) )
return;
if ( F_270 ( V_8 ) && F_273 ( V_8 ) && ! F_140 ( V_8 ) ) {
F_103 ( V_517 , V_507 -> V_518 [ 0 ] ) ;
F_103 ( V_519 , V_507 -> V_518 [ 1 ] ) ;
F_103 ( V_520 , V_507 -> V_518 [ 2 ] ) ;
F_103 ( V_521 , V_507 -> V_518 [ 3 ] ) ;
}
}
static void F_218 ( struct V_7 * V_8 )
{
struct V_514 * V_507 = V_8 -> V_116 . V_515 ;
if ( F_270 ( V_8 ) && F_273 ( V_8 ) && ! F_140 ( V_8 ) ) {
V_507 -> V_518 [ 0 ] = F_95 ( V_517 ) ;
V_507 -> V_518 [ 1 ] = F_95 ( V_519 ) ;
V_507 -> V_518 [ 2 ] = F_95 ( V_520 ) ;
V_507 -> V_518 [ 3 ] = F_95 ( V_521 ) ;
}
F_171 ( V_409 ,
( unsigned long * ) & V_8 -> V_116 . V_117 ) ;
F_171 ( V_409 ,
( unsigned long * ) & V_8 -> V_116 . V_516 ) ;
}
static void F_274 ( unsigned long * V_522 ,
unsigned long V_229 ,
struct V_7 * V_8 )
{
if ( ! F_170 ( V_511 , ( T_9 * ) & V_8 -> V_116 . V_117 ) )
F_269 ( V_8 ) ;
if ( ! ( V_229 & V_523 ) ) {
F_102 ( V_524 ,
F_94 ( V_524 ) |
( V_339 |
V_340 ) ) ;
V_8 -> V_116 . V_229 = V_229 ;
F_275 ( V_8 , F_276 ( V_8 ) ) ;
} else if ( ! F_270 ( V_8 ) ) {
F_102 ( V_524 ,
F_94 ( V_524 ) &
~ ( V_339 |
V_340 ) ) ;
V_8 -> V_116 . V_229 = V_229 ;
F_275 ( V_8 , F_276 ( V_8 ) ) ;
}
if ( ! ( V_229 & V_525 ) )
* V_522 &= ~ V_525 ;
}
static void F_277 ( struct V_7 * V_8 , unsigned long V_229 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_522 ;
V_522 = ( V_229 & ~ V_526 ) ;
if ( V_460 )
V_522 |= V_527 ;
else {
V_522 |= V_528 ;
if ( V_73 -> V_136 . V_137 && ( V_229 & V_529 ) )
F_256 ( V_8 ) ;
if ( ! V_73 -> V_136 . V_137 && ! ( V_229 & V_529 ) )
F_260 ( V_8 ) ;
}
#ifdef F_96
if ( V_8 -> V_116 . V_177 & V_181 ) {
if ( ! F_270 ( V_8 ) && ( V_229 & V_523 ) )
F_263 ( V_8 ) ;
if ( F_270 ( V_8 ) && ! ( V_229 & V_523 ) )
F_265 ( V_8 ) ;
}
#endif
if ( V_101 )
F_274 ( & V_522 , V_229 , V_8 ) ;
if ( ! V_8 -> V_138 )
V_522 |= V_231 | V_232 ;
F_99 ( V_242 , V_229 ) ;
F_99 ( V_230 , V_522 ) ;
V_8 -> V_116 . V_229 = V_229 ;
V_73 -> F_252 = F_252 ( V_8 ) ;
}
static T_3 F_268 ( unsigned long V_508 )
{
T_3 V_84 ;
V_84 = V_530 |
V_531 << V_532 ;
if ( V_461 )
V_84 |= V_533 ;
V_84 |= ( V_508 & V_534 ) ;
return V_84 ;
}
static void F_278 ( struct V_7 * V_8 , unsigned long V_509 )
{
unsigned long V_535 ;
T_3 V_84 ;
V_535 = V_509 ;
if ( V_101 ) {
V_84 = F_268 ( V_509 ) ;
F_103 ( V_536 , V_84 ) ;
if ( F_270 ( V_8 ) || F_123 ( V_8 ) )
V_535 = F_279 ( V_8 ) ;
else
V_535 = V_8 -> V_17 -> V_116 . V_537 ;
F_272 ( V_8 ) ;
}
F_266 ( V_8 ) ;
F_99 ( V_510 , V_535 ) ;
}
static int F_275 ( struct V_7 * V_8 , unsigned long V_513 )
{
unsigned long V_538 = V_513 | ( F_6 ( V_8 ) -> V_136 . V_137 ?
V_539 : V_540 ) ;
if ( V_513 & V_415 ) {
if ( ! F_202 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_541 &&
( ( V_513 & F_210 ) != F_210 ) )
return 1 ;
V_8 -> V_116 . V_513 = V_513 ;
if ( V_101 ) {
if ( ! F_270 ( V_8 ) ) {
V_538 &= ~ V_542 ;
V_538 |= V_543 ;
V_538 &= ~ ( V_544 | V_545 ) ;
} else if ( ! ( V_513 & V_542 ) ) {
V_538 &= ~ V_542 ;
}
}
F_99 ( V_486 , V_513 ) ;
F_99 ( V_484 , V_538 ) ;
return 0 ;
}
static void F_257 ( struct V_7 * V_8 ,
struct V_471 * V_491 , int V_113 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_127 ;
if ( V_73 -> V_136 . V_137 && V_113 != V_546 ) {
* V_491 = V_73 -> V_136 . V_478 [ V_113 ] ;
if ( V_113 == V_483
|| V_491 -> V_120 == F_118 ( V_73 , V_113 ) )
return;
V_491 -> V_123 = F_119 ( V_73 , V_113 ) ;
V_491 -> V_120 = F_118 ( V_73 , V_113 ) ;
return;
}
V_491 -> V_123 = F_119 ( V_73 , V_113 ) ;
V_491 -> V_125 = F_120 ( V_73 , V_113 ) ;
V_491 -> V_120 = F_118 ( V_73 , V_113 ) ;
V_127 = F_121 ( V_73 , V_113 ) ;
V_491 -> V_496 = ( V_127 >> 16 ) & 1 ;
V_491 -> type = V_127 & 15 ;
V_491 -> V_187 = ( V_127 >> 4 ) & 1 ;
V_491 -> V_476 = ( V_127 >> 5 ) & 3 ;
V_491 -> V_494 = ! V_491 -> V_496 ;
V_491 -> V_497 = ( V_127 >> 12 ) & 1 ;
V_491 -> V_495 = ( V_127 >> 13 ) & 1 ;
V_491 -> V_493 = ( V_127 >> 14 ) & 1 ;
V_491 -> V_492 = ( V_127 >> 15 ) & 1 ;
}
static T_3 F_280 ( struct V_7 * V_8 , int V_113 )
{
struct V_471 V_187 ;
if ( F_6 ( V_8 ) -> V_136 . V_137 ) {
F_257 ( V_8 , & V_187 , V_113 ) ;
return V_187 . V_123 ;
}
return F_119 ( F_6 ( V_8 ) , V_113 ) ;
}
static int F_281 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_282 ( V_8 ) )
return 0 ;
if ( ! F_140 ( V_8 )
&& ( F_283 ( V_8 ) & V_249 ) )
return 3 ;
if ( ! F_170 ( V_487 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ) {
F_171 ( V_487 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
V_73 -> V_488 = F_118 ( V_73 , V_473 ) & 3 ;
}
return V_73 -> V_488 ;
}
static T_2 F_259 ( struct V_471 * V_491 )
{
T_2 V_127 ;
if ( V_491 -> V_496 || ! V_491 -> V_494 )
V_127 = 1 << 16 ;
else {
V_127 = V_491 -> type & 15 ;
V_127 |= ( V_491 -> V_187 & 1 ) << 4 ;
V_127 |= ( V_491 -> V_476 & 3 ) << 5 ;
V_127 |= ( V_491 -> V_494 & 1 ) << 7 ;
V_127 |= ( V_491 -> V_497 & 1 ) << 12 ;
V_127 |= ( V_491 -> V_495 & 1 ) << 13 ;
V_127 |= ( V_491 -> V_493 & 1 ) << 14 ;
V_127 |= ( V_491 -> V_492 & 1 ) << 15 ;
}
return V_127 ;
}
static void F_255 ( struct V_7 * V_8 ,
struct V_471 * V_491 , int V_113 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
const struct V_489 * V_490 = & V_122 [ V_113 ] ;
F_116 ( V_73 ) ;
if ( V_113 == V_473 )
F_284 ( V_487 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
if ( V_73 -> V_136 . V_137 && V_113 != V_546 ) {
V_73 -> V_136 . V_478 [ V_113 ] = * V_491 ;
if ( V_113 == V_483 )
F_101 ( V_490 -> V_120 , V_491 -> V_120 ) ;
else if ( V_491 -> V_187 )
F_258 ( V_113 , & V_73 -> V_136 . V_478 [ V_113 ] ) ;
goto V_547;
}
F_99 ( V_490 -> V_123 , V_491 -> V_123 ) ;
F_102 ( V_490 -> V_125 , V_491 -> V_125 ) ;
F_101 ( V_490 -> V_120 , V_491 -> V_120 ) ;
if ( V_460 && ( V_113 != V_546 ) )
V_491 -> type |= 0x1 ;
F_102 ( V_490 -> V_129 , F_259 ( V_491 ) ) ;
V_547:
V_73 -> F_252 |= F_252 ( V_8 ) ;
}
static void F_285 ( struct V_7 * V_8 , int * V_493 , int * V_495 )
{
T_2 V_127 = F_121 ( F_6 ( V_8 ) , V_473 ) ;
* V_493 = ( V_127 >> 14 ) & 1 ;
* V_495 = ( V_127 >> 13 ) & 1 ;
}
static void F_286 ( struct V_7 * V_8 , struct V_167 * V_548 )
{
V_548 -> V_439 = F_94 ( V_549 ) ;
V_548 -> V_172 = F_92 ( V_550 ) ;
}
static void F_287 ( struct V_7 * V_8 , struct V_167 * V_548 )
{
F_102 ( V_549 , V_548 -> V_439 ) ;
F_99 ( V_550 , V_548 -> V_172 ) ;
}
static void F_288 ( struct V_7 * V_8 , struct V_167 * V_548 )
{
V_548 -> V_439 = F_94 ( V_551 ) ;
V_548 -> V_172 = F_92 ( V_552 ) ;
}
static void F_289 ( struct V_7 * V_8 , struct V_167 * V_548 )
{
F_102 ( V_551 , V_548 -> V_439 ) ;
F_99 ( V_552 , V_548 -> V_172 ) ;
}
static bool F_290 ( struct V_7 * V_8 , int V_113 )
{
struct V_471 V_491 ;
T_2 V_127 ;
F_257 ( V_8 , & V_491 , V_113 ) ;
V_491 . V_476 = 0x3 ;
if ( V_113 == V_473 )
V_491 . type = 0x3 ;
V_127 = F_259 ( & V_491 ) ;
if ( V_491 . V_123 != ( V_491 . V_120 << 4 ) )
return false ;
if ( V_491 . V_125 != 0xffff )
return false ;
if ( V_127 != 0xf3 )
return false ;
return true ;
}
static bool F_291 ( struct V_7 * V_8 )
{
struct V_471 V_553 ;
unsigned int V_554 ;
F_257 ( V_8 , & V_553 , V_473 ) ;
V_554 = V_553 . V_120 & V_475 ;
if ( V_553 . V_496 )
return false ;
if ( ~ V_553 . type & ( V_555 | V_556 ) )
return false ;
if ( ! V_553 . V_187 )
return false ;
if ( V_553 . type & V_557 ) {
if ( V_553 . V_476 > V_554 )
return false ;
} else {
if ( V_553 . V_476 != V_554 )
return false ;
}
if ( ! V_553 . V_494 )
return false ;
return true ;
}
static bool F_292 ( struct V_7 * V_8 )
{
struct V_471 V_558 ;
unsigned int V_559 ;
F_257 ( V_8 , & V_558 , V_474 ) ;
V_559 = V_558 . V_120 & V_475 ;
if ( V_558 . V_496 )
return true ;
if ( V_558 . type != 3 && V_558 . type != 7 )
return false ;
if ( ! V_558 . V_187 )
return false ;
if ( V_558 . V_476 != V_559 )
return false ;
if ( ! V_558 . V_494 )
return false ;
return true ;
}
static bool F_293 ( struct V_7 * V_8 , int V_113 )
{
struct V_471 V_491 ;
unsigned int V_560 ;
F_257 ( V_8 , & V_491 , V_113 ) ;
V_560 = V_491 . V_120 & V_475 ;
if ( V_491 . V_496 )
return true ;
if ( ! V_491 . V_187 )
return false ;
if ( ! V_491 . V_494 )
return false ;
if ( ~ V_491 . type & ( V_555 | V_557 ) ) {
if ( V_491 . V_476 < V_560 )
return false ;
}
return true ;
}
static bool F_294 ( struct V_7 * V_8 )
{
struct V_471 V_190 ;
F_257 ( V_8 , & V_190 , V_483 ) ;
if ( V_190 . V_496 )
return false ;
if ( V_190 . V_120 & V_561 )
return false ;
if ( V_190 . type != 3 && V_190 . type != 11 )
return false ;
if ( ! V_190 . V_494 )
return false ;
return true ;
}
static bool F_295 ( struct V_7 * V_8 )
{
struct V_471 V_562 ;
F_257 ( V_8 , & V_562 , V_546 ) ;
if ( V_562 . V_496 )
return true ;
if ( V_562 . V_120 & V_561 )
return false ;
if ( V_562 . type != 2 )
return false ;
if ( ! V_562 . V_494 )
return false ;
return true ;
}
static bool F_296 ( struct V_7 * V_8 )
{
struct V_471 V_553 , V_558 ;
F_257 ( V_8 , & V_553 , V_473 ) ;
F_257 ( V_8 , & V_558 , V_474 ) ;
return ( ( V_553 . V_120 & V_475 ) ==
( V_558 . V_120 & V_475 ) ) ;
}
static bool F_253 ( struct V_7 * V_8 )
{
if ( V_460 )
return true ;
if ( ! F_282 ( V_8 ) || ( F_169 ( V_8 ) & V_249 ) ) {
if ( ! F_290 ( V_8 , V_473 ) )
return false ;
if ( ! F_290 ( V_8 , V_474 ) )
return false ;
if ( ! F_290 ( V_8 , V_480 ) )
return false ;
if ( ! F_290 ( V_8 , V_479 ) )
return false ;
if ( ! F_290 ( V_8 , V_481 ) )
return false ;
if ( ! F_290 ( V_8 , V_482 ) )
return false ;
} else {
if ( ! F_296 ( V_8 ) )
return false ;
if ( ! F_291 ( V_8 ) )
return false ;
if ( ! F_292 ( V_8 ) )
return false ;
if ( ! F_293 ( V_8 , V_480 ) )
return false ;
if ( ! F_293 ( V_8 , V_479 ) )
return false ;
if ( ! F_293 ( V_8 , V_481 ) )
return false ;
if ( ! F_293 ( V_8 , V_482 ) )
return false ;
if ( ! F_294 ( V_8 ) )
return false ;
if ( ! F_295 ( V_8 ) )
return false ;
}
return true ;
}
static int F_297 ( struct V_17 * V_17 )
{
T_13 V_563 ;
T_4 V_183 = 0 ;
int V_564 , V_565 , V_114 = 0 ;
V_565 = F_298 ( & V_17 -> V_566 ) ;
V_563 = V_17 -> V_116 . V_498 >> V_18 ;
V_564 = F_299 ( V_17 , V_563 , 0 , V_438 ) ;
if ( V_564 < 0 )
goto V_547;
V_183 = V_567 + V_568 ;
V_564 = F_300 ( V_17 , V_563 ++ , & V_183 ,
V_569 , sizeof( T_4 ) ) ;
if ( V_564 < 0 )
goto V_547;
V_564 = F_299 ( V_17 , V_563 ++ , 0 , V_438 ) ;
if ( V_564 < 0 )
goto V_547;
V_564 = F_299 ( V_17 , V_563 , 0 , V_438 ) ;
if ( V_564 < 0 )
goto V_547;
V_183 = ~ 0 ;
V_564 = F_300 ( V_17 , V_563 , & V_183 ,
V_501 - 2 * V_438 - 1 ,
sizeof( T_6 ) ) ;
if ( V_564 < 0 )
goto V_547;
V_114 = 1 ;
V_547:
F_301 ( & V_17 -> V_566 , V_565 ) ;
return V_114 ;
}
static int F_302 ( struct V_17 * V_17 )
{
int V_75 , V_565 , V_564 , V_114 ;
T_14 V_570 ;
T_2 V_276 ;
if ( ! V_101 )
return 1 ;
if ( F_100 ( ! V_17 -> V_116 . V_571 ) ) {
F_69 ( V_89 L_18
L_19 ) ;
return 0 ;
}
if ( F_303 ( V_17 -> V_116 . V_572 ) )
return 1 ;
V_114 = 0 ;
V_570 = V_17 -> V_116 . V_537 >> V_18 ;
V_565 = F_298 ( & V_17 -> V_566 ) ;
V_564 = F_299 ( V_17 , V_570 , 0 , V_438 ) ;
if ( V_564 < 0 )
goto V_547;
for ( V_75 = 0 ; V_75 < V_573 ; V_75 ++ ) {
V_276 = ( V_75 << 22 ) + ( V_574 | V_575 | V_576 |
V_577 | V_578 | V_579 ) ;
V_564 = F_300 ( V_17 , V_570 ,
& V_276 , V_75 * sizeof( V_276 ) , sizeof( V_276 ) ) ;
if ( V_564 < 0 )
goto V_547;
}
V_17 -> V_116 . V_572 = true ;
V_114 = 1 ;
V_547:
F_301 ( & V_17 -> V_566 , V_565 ) ;
return V_114 ;
}
static void F_304 ( int V_113 )
{
const struct V_489 * V_490 = & V_122 [ V_113 ] ;
unsigned int V_127 ;
F_101 ( V_490 -> V_120 , 0 ) ;
F_99 ( V_490 -> V_123 , 0 ) ;
F_102 ( V_490 -> V_125 , 0xffff ) ;
V_127 = 0x93 ;
if ( V_113 == V_473 )
V_127 |= 0x08 ;
F_102 ( V_490 -> V_129 , V_127 ) ;
}
static int F_305 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_580 V_581 ;
int V_564 = 0 ;
F_306 ( & V_17 -> V_582 ) ;
if ( V_17 -> V_116 . V_583 )
goto V_547;
V_581 . V_584 = V_585 ;
V_581 . V_477 = 0 ;
V_581 . V_586 = 0xfee00000ULL ;
V_581 . V_587 = V_438 ;
V_564 = F_307 ( V_17 , & V_581 ) ;
if ( V_564 )
goto V_547;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_564 = - V_588 ;
goto V_547;
}
V_17 -> V_116 . V_583 = V_15 ;
V_547:
F_308 ( & V_17 -> V_582 ) ;
return V_564 ;
}
static int F_309 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_580 V_581 ;
int V_564 = 0 ;
F_306 ( & V_17 -> V_582 ) ;
if ( V_17 -> V_116 . V_571 )
goto V_547;
V_581 . V_584 = V_589 ;
V_581 . V_477 = 0 ;
V_581 . V_586 =
V_17 -> V_116 . V_537 ;
V_581 . V_587 = V_438 ;
V_564 = F_307 ( V_17 , & V_581 ) ;
if ( V_564 )
goto V_547;
V_15 = F_11 ( V_17 , V_17 -> V_116 . V_537 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_564 = - V_588 ;
goto V_547;
}
V_17 -> V_116 . V_571 = V_15 ;
V_547:
F_308 ( & V_17 -> V_582 ) ;
return V_564 ;
}
static void F_310 ( struct V_6 * V_73 )
{
int V_52 ;
V_73 -> V_52 = 0 ;
if ( ! V_458 )
return;
F_311 ( & V_590 ) ;
V_52 = F_312 ( V_591 , V_592 ) ;
if ( V_52 < V_592 ) {
V_73 -> V_52 = V_52 ;
F_171 ( V_52 , V_591 ) ;
}
F_313 ( & V_590 ) ;
}
static void F_314 ( struct V_6 * V_73 )
{
if ( ! V_458 )
return;
F_311 ( & V_590 ) ;
if ( V_73 -> V_52 != 0 )
F_284 ( V_73 -> V_52 , V_591 ) ;
F_313 ( & V_590 ) ;
}
static void F_315 ( unsigned long * V_277 ,
T_2 V_74 , int type )
{
int V_593 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_74 <= 0x1fff ) {
if ( type & V_594 )
F_284 ( V_74 , V_277 + 0x000 / V_593 ) ;
if ( type & V_595 )
F_284 ( V_74 , V_277 + 0x800 / V_593 ) ;
} else if ( ( V_74 >= 0xc0000000 ) && ( V_74 <= 0xc0001fff ) ) {
V_74 &= 0x1fff ;
if ( type & V_594 )
F_284 ( V_74 , V_277 + 0x400 / V_593 ) ;
if ( type & V_595 )
F_284 ( V_74 , V_277 + 0xc00 / V_593 ) ;
}
}
static void F_316 ( unsigned long * V_277 ,
T_2 V_74 , int type )
{
int V_593 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_74 <= 0x1fff ) {
if ( type & V_594 )
F_171 ( V_74 , V_277 + 0x000 / V_593 ) ;
if ( type & V_595 )
F_171 ( V_74 , V_277 + 0x800 / V_593 ) ;
} else if ( ( V_74 >= 0xc0000000 ) && ( V_74 <= 0xc0001fff ) ) {
V_74 &= 0x1fff ;
if ( type & V_594 )
F_171 ( V_74 , V_277 + 0x400 / V_593 ) ;
if ( type & V_595 )
F_171 ( V_74 , V_277 + 0xc00 / V_593 ) ;
}
}
static void F_317 ( T_2 V_74 , bool V_596 )
{
if ( ! V_596 )
F_315 ( V_282 ,
V_74 , V_594 | V_595 ) ;
F_315 ( V_281 ,
V_74 , V_594 | V_595 ) ;
}
static void F_318 ( T_2 V_74 )
{
F_316 ( V_280 ,
V_74 , V_594 ) ;
F_316 ( V_279 ,
V_74 , V_594 ) ;
}
static void F_319 ( T_2 V_74 )
{
F_315 ( V_280 ,
V_74 , V_594 ) ;
F_315 ( V_279 ,
V_74 , V_594 ) ;
}
static void F_320 ( T_2 V_74 )
{
F_315 ( V_280 ,
V_74 , V_595 ) ;
F_315 ( V_279 ,
V_74 , V_595 ) ;
}
static int F_321 ( struct V_17 * V_17 )
{
return V_465 && F_25 ( V_17 ) ;
}
static void F_322 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_564 ;
if ( F_5 ( V_4 , & V_73 -> V_1 ) )
return;
V_564 = F_1 ( & V_73 -> V_1 ) ;
F_156 ( V_597 , V_8 ) ;
#ifdef F_323
if ( ! V_564 && ( V_8 -> V_598 == V_599 ) )
V_278 -> V_600 ( F_324 ( V_8 -> V_91 ) ,
V_601 ) ;
else
#endif
F_325 ( V_8 ) ;
}
static void F_326 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_73 -> V_1 ) )
return;
F_327 ( V_8 , V_73 -> V_1 . V_5 ) ;
}
static void V_469 ( struct V_7 * V_8 )
{
return;
}
static void F_328 ( struct V_6 * V_73 )
{
T_2 V_602 , V_603 ;
unsigned long V_604 ;
struct V_167 V_548 ;
F_99 ( V_605 , F_329 () & ~ V_231 ) ;
F_99 ( V_606 , F_224 () ) ;
F_99 ( V_607 , F_330 () ) ;
F_101 ( V_608 , V_609 ) ;
#ifdef F_96
F_101 ( V_610 , 0 ) ;
F_101 ( V_611 , 0 ) ;
#else
F_101 ( V_610 , V_612 ) ;
F_101 ( V_611 , V_612 ) ;
#endif
F_101 ( V_613 , V_612 ) ;
F_101 ( V_614 , V_173 * 8 ) ;
F_331 ( & V_548 ) ;
F_99 ( V_615 , V_548 . V_172 ) ;
V_73 -> V_616 = V_548 . V_172 ;
F_99 ( V_617 , V_618 ) ;
F_204 ( V_384 , V_602 , V_603 ) ;
F_102 ( V_619 , V_602 ) ;
F_55 ( V_386 , V_604 ) ;
F_99 ( V_620 , V_604 ) ;
if ( V_29 . V_442 & V_319 ) {
F_204 ( V_395 , V_602 , V_603 ) ;
F_103 ( V_621 , V_602 | ( ( T_3 ) V_603 << 32 ) ) ;
}
}
static void F_332 ( struct V_6 * V_73 )
{
V_73 -> V_8 . V_116 . V_512 = V_622 ;
if ( V_101 )
V_73 -> V_8 . V_116 . V_512 |= V_623 ;
if ( F_123 ( & V_73 -> V_8 ) )
V_73 -> V_8 . V_116 . V_512 &=
~ F_9 ( & V_73 -> V_8 ) -> V_240 ;
F_99 ( V_624 , ~ V_73 -> V_8 . V_116 . V_512 ) ;
}
static T_2 F_333 ( struct V_6 * V_73 )
{
T_2 V_39 = V_29 . V_39 ;
if ( ! F_321 ( V_73 -> V_8 . V_17 ) )
V_39 &= ~ V_40 ;
return V_39 ;
}
static T_2 F_334 ( struct V_6 * V_73 )
{
T_2 V_625 = V_29 . V_30 ;
if ( V_73 -> V_8 . V_116 . V_626 & V_627 )
V_625 &= ~ V_343 ;
if ( ! F_24 ( V_73 -> V_8 . V_17 ) ) {
V_625 &= ~ V_32 ;
#ifdef F_96
V_625 |= V_342 |
V_341 ;
#endif
}
if ( ! V_101 )
V_625 |= V_340 |
V_339 |
V_337 ;
return V_625 ;
}
static T_2 F_335 ( struct V_6 * V_73 )
{
T_2 V_625 = V_29 . V_34 ;
if ( ! F_48 ( V_73 -> V_8 . V_17 ) )
V_625 &= ~ V_35 ;
if ( V_73 -> V_52 == 0 )
V_625 &= ~ V_59 ;
if ( ! V_101 ) {
V_625 &= ~ V_55 ;
V_460 = 0 ;
V_625 &= ~ V_61 ;
}
if ( ! V_460 )
V_625 &= ~ V_56 ;
if ( ! V_464 )
V_625 &= ~ V_57 ;
if ( ! F_321 ( V_73 -> V_8 . V_17 ) )
V_625 &= ~ ( V_37 |
V_38 ) ;
V_625 &= ~ V_36 ;
V_625 &= ~ V_67 ;
return V_625 ;
}
static void F_336 ( void )
{
F_337 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_338 ( struct V_6 * V_73 )
{
#ifdef F_96
unsigned long V_628 ;
#endif
int V_75 ;
F_103 ( V_629 , F_68 ( V_630 ) ) ;
F_103 ( V_631 , F_68 ( V_632 ) ) ;
if ( V_459 ) {
F_103 ( V_633 , F_68 ( V_453 ) ) ;
F_103 ( V_634 , F_68 ( V_452 ) ) ;
}
if ( F_22 () )
F_103 ( V_283 , F_68 ( V_282 ) ) ;
F_103 ( V_635 , - 1ull ) ;
F_102 ( V_636 , F_333 ( V_73 ) ) ;
F_102 ( V_524 , F_334 ( V_73 ) ) ;
if ( F_26 () ) {
F_102 ( V_637 ,
F_335 ( V_73 ) ) ;
}
if ( F_321 ( V_73 -> V_8 . V_17 ) ) {
F_103 ( V_638 , 0 ) ;
F_103 ( V_639 , 0 ) ;
F_103 ( V_640 , 0 ) ;
F_103 ( V_641 , 0 ) ;
F_101 ( V_642 , 0 ) ;
F_103 ( V_643 , V_601 ) ;
F_103 ( V_644 , F_68 ( ( & V_73 -> V_1 ) ) ) ;
}
if ( V_464 ) {
F_102 ( V_645 , V_464 ) ;
F_102 ( V_646 , V_647 ) ;
}
F_102 ( V_648 , 0 ) ;
F_102 ( V_649 , 0 ) ;
F_102 ( V_650 , 0 ) ;
F_101 ( V_197 , 0 ) ;
F_101 ( V_201 , 0 ) ;
F_328 ( V_73 ) ;
#ifdef F_96
F_55 ( V_207 , V_628 ) ;
F_99 ( V_206 , V_628 ) ;
F_55 ( V_209 , V_628 ) ;
F_99 ( V_208 , V_628 ) ;
#else
F_99 ( V_206 , 0 ) ;
F_99 ( V_208 , 0 ) ;
#endif
F_102 ( V_651 , 0 ) ;
F_102 ( V_156 , 0 ) ;
F_103 ( V_652 , F_68 ( V_73 -> V_142 . V_154 ) ) ;
F_102 ( V_155 , 0 ) ;
F_103 ( V_653 , F_68 ( V_73 -> V_142 . V_153 ) ) ;
if ( V_29 . V_396 & V_329 ) {
T_2 V_654 , V_655 ;
T_3 V_656 ;
F_204 ( V_395 , V_654 , V_655 ) ;
V_656 = V_654 | ( ( T_3 ) V_655 << 32 ) ;
F_103 ( V_397 , V_656 ) ;
V_73 -> V_8 . V_116 . V_398 = V_656 ;
}
for ( V_75 = 0 ; V_75 < V_657 ; ++ V_75 ) {
T_2 V_79 = V_77 [ V_75 ] ;
T_2 V_658 , V_659 ;
int V_449 = V_73 -> V_76 ;
if ( F_339 ( V_79 , & V_658 , & V_659 ) < 0 )
continue;
if ( F_340 ( V_79 , V_658 , V_659 ) < 0 )
continue;
V_73 -> V_78 [ V_449 ] . V_79 = V_75 ;
V_73 -> V_78 [ V_449 ] . V_183 = 0 ;
V_73 -> V_78 [ V_449 ] . V_105 = - 1ull ;
++ V_73 -> V_76 ;
}
F_111 ( V_73 , V_29 . V_442 ) ;
F_106 ( V_73 , V_29 . V_396 ) ;
F_99 ( V_235 , ~ 0UL ) ;
F_332 ( V_73 ) ;
return 0 ;
}
static void F_341 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_393 V_660 ;
V_73 -> V_136 . V_137 = 0 ;
V_73 -> V_661 = 0 ;
V_73 -> V_8 . V_116 . V_405 [ V_662 ] = F_342 () ;
F_343 ( & V_73 -> V_8 , 0 ) ;
V_660 . V_183 = 0xfee00000 | V_663 ;
if ( F_344 ( & V_73 -> V_8 ) )
V_660 . V_183 |= V_664 ;
V_660 . V_401 = true ;
F_345 ( & V_73 -> V_8 , & V_660 ) ;
F_116 ( V_73 ) ;
F_304 ( V_473 ) ;
F_101 ( V_665 , 0xf000 ) ;
F_102 ( V_666 , 0xffff0000 ) ;
F_304 ( V_480 ) ;
F_304 ( V_479 ) ;
F_304 ( V_481 ) ;
F_304 ( V_482 ) ;
F_304 ( V_474 ) ;
F_101 ( V_667 , 0 ) ;
F_99 ( V_499 , 0 ) ;
F_102 ( V_500 , 0xffff ) ;
F_102 ( V_502 , 0x008b ) ;
F_101 ( V_668 , 0 ) ;
F_99 ( V_669 , 0 ) ;
F_102 ( V_670 , 0xffff ) ;
F_102 ( V_671 , 0x00082 ) ;
F_102 ( V_385 , 0 ) ;
F_99 ( V_388 , 0 ) ;
F_99 ( V_387 , 0 ) ;
F_99 ( V_246 , 0x02 ) ;
F_177 ( V_8 , 0xfff0 ) ;
F_99 ( V_552 , 0 ) ;
F_102 ( V_551 , 0xffff ) ;
F_99 ( V_550 , 0 ) ;
F_102 ( V_549 , 0xffff ) ;
F_102 ( V_672 , V_673 ) ;
F_102 ( V_251 , 0 ) ;
F_102 ( V_674 , 0 ) ;
F_103 ( V_675 , 0 ) ;
F_188 ( V_73 ) ;
F_102 ( V_273 , 0 ) ;
if ( F_23 () ) {
F_103 ( V_676 , 0 ) ;
if ( F_24 ( V_73 -> V_8 . V_17 ) )
F_103 ( V_676 ,
F_68 ( V_73 -> V_8 . V_116 . V_278 -> V_405 ) ) ;
F_102 ( V_677 , 0 ) ;
}
if ( F_48 ( V_73 -> V_8 . V_17 ) )
F_103 ( V_678 ,
F_346 ( V_73 -> V_8 . V_17 -> V_116 . V_583 ) ) ;
if ( F_321 ( V_8 -> V_17 ) )
memset ( & V_73 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_73 -> V_52 != 0 )
F_101 ( V_679 , V_73 -> V_52 ) ;
V_73 -> V_8 . V_116 . V_229 = V_680 | V_681 | V_682 ;
F_277 ( & V_73 -> V_8 , F_347 ( V_8 ) ) ;
F_275 ( & V_73 -> V_8 , 0 ) ;
F_262 ( & V_73 -> V_8 , 0 ) ;
F_163 ( & V_73 -> V_8 ) ;
F_122 ( & V_73 -> V_8 ) ;
F_89 ( V_73 ) ;
}
static bool F_348 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_312 ;
}
static bool F_349 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_313 ;
}
static void F_350 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_524 ) ;
V_69 |= V_334 ;
F_102 ( V_524 , V_69 ) ;
}
static void F_351 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () ||
F_94 ( V_251 ) & V_252 ) {
F_350 ( V_8 ) ;
return;
}
V_69 = F_94 ( V_524 ) ;
V_69 |= V_335 ;
F_102 ( V_524 , V_69 ) ;
}
static void F_352 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_15 V_683 ;
int V_684 = V_8 -> V_116 . V_685 . V_152 ;
F_353 ( V_684 ) ;
++ V_8 -> V_217 . V_686 ;
if ( V_73 -> V_136 . V_137 ) {
int V_267 = 0 ;
if ( V_8 -> V_116 . V_685 . V_687 )
V_267 = V_8 -> V_116 . V_268 ;
if ( F_182 ( V_8 , V_684 , V_267 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
V_683 = V_684 | V_22 ;
if ( V_8 -> V_116 . V_685 . V_687 ) {
V_683 |= V_688 ;
F_102 ( V_271 ,
V_73 -> V_8 . V_116 . V_268 ) ;
} else
V_683 |= V_27 ;
F_102 ( V_273 , V_683 ) ;
}
static void F_354 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_123 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_73 -> V_661 = 1 ;
V_73 -> V_689 = 0 ;
}
++ V_8 -> V_217 . V_690 ;
V_73 -> V_691 = false ;
if ( V_73 -> V_136 . V_137 ) {
if ( F_182 ( V_8 , V_692 , 0 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
F_102 ( V_273 ,
V_693 | V_22 | V_692 ) ;
}
static bool F_355 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_661 ;
if ( F_6 ( V_8 ) -> V_691 )
return false ;
return F_94 ( V_251 ) & V_694 ;
}
static void F_356 ( struct V_7 * V_8 , bool V_695 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_73 -> V_661 != V_695 ) {
V_73 -> V_661 = V_695 ;
V_73 -> V_689 = 0 ;
}
} else {
V_73 -> V_691 = ! V_695 ;
if ( V_695 )
F_105 ( V_251 ,
V_694 ) ;
else
F_104 ( V_251 ,
V_694 ) ;
}
}
static int F_357 ( struct V_7 * V_8 )
{
if ( F_6 ( V_8 ) -> V_13 . V_696 )
return 0 ;
if ( ! F_52 () && F_6 ( V_8 ) -> V_661 )
return 0 ;
return ! ( F_94 ( V_251 ) &
( V_254 | V_252
| V_694 ) ) ;
}
static int F_358 ( struct V_7 * V_8 )
{
return ( ! F_6 ( V_8 ) -> V_13 . V_696 &&
F_92 ( V_246 ) & V_697 ) &&
! ( F_94 ( V_251 ) &
( V_252 | V_254 ) ) ;
}
static int F_359 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_114 ;
struct V_580 V_698 = {
. V_584 = V_699 ,
. V_586 = V_16 ,
. V_587 = V_438 * 3 ,
. V_477 = 0 ,
} ;
V_114 = F_360 ( V_17 , & V_698 ) ;
if ( V_114 )
return V_114 ;
V_17 -> V_116 . V_498 = V_16 ;
if ( ! F_297 ( V_17 ) )
return - V_456 ;
return 0 ;
}
static bool F_361 ( struct V_7 * V_8 , int V_700 )
{
switch ( V_700 ) {
case V_135 :
F_6 ( V_8 ) -> V_8 . V_116 . V_268 =
F_94 ( V_258 ) ;
if ( V_8 -> V_132 & V_134 )
return false ;
case V_131 :
if ( V_8 -> V_132 &
( V_701 | V_702 ) )
return false ;
case V_703 :
case V_704 :
case V_705 :
case V_26 :
case V_706 :
case V_707 :
case V_708 :
case V_709 :
return true ;
break;
}
return false ;
}
static int F_362 ( struct V_7 * V_8 ,
int V_700 , T_2 V_710 )
{
if ( ( ( V_700 == V_708 ) || ( V_700 == V_707 ) ) && V_710 == 0 ) {
if ( F_363 ( V_8 , 0 ) == V_269 ) {
if ( V_8 -> V_116 . V_711 ) {
V_8 -> V_116 . V_711 = 0 ;
return F_364 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_365 ( V_8 , V_700 ) ;
return 1 ;
}
static void F_366 ( void )
{
#if F_367 ( V_712 ) && F_367 ( F_96 )
struct V_713 V_405 = {
. V_553 = 3 ,
. V_477 = V_697 ,
} ;
F_368 ( & V_405 , 0 ) ;
#endif
}
static int F_369 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_370 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_714 * V_714 = V_8 -> V_715 ;
T_2 V_19 , V_716 , V_263 ;
unsigned long V_717 , V_257 , V_718 ;
T_2 V_719 ;
enum V_720 V_721 ;
V_719 = V_73 -> V_722 ;
V_19 = V_73 -> V_723 ;
if ( F_21 ( V_19 ) )
return F_369 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_693 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_163 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_721 = F_363 ( V_8 , V_724 ) ;
if ( V_721 != V_269 )
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
V_263 = 0 ;
if ( V_19 & V_266 )
V_263 = F_94 ( V_725 ) ;
if ( ( V_719 & V_726 ) &&
! ( F_17 ( V_19 ) && ! ( V_263 & V_727 ) ) ) {
V_8 -> V_715 -> V_259 = V_728 ;
V_8 -> V_715 -> V_729 . V_730 = V_731 ;
V_8 -> V_715 -> V_729 . V_732 = 2 ;
V_8 -> V_715 -> V_729 . V_183 [ 0 ] = V_719 ;
V_8 -> V_715 -> V_729 . V_183 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_371 ( V_101 ) ;
V_717 = F_92 ( V_261 ) ;
F_372 ( V_717 , V_263 ) ;
if ( F_373 ( V_8 ) )
F_374 ( V_8 , V_717 ) ;
return F_375 ( V_8 , V_717 , V_263 , NULL , 0 ) ;
}
V_716 = V_19 & V_21 ;
if ( V_73 -> V_136 . V_137 && F_361 ( V_8 , V_716 ) )
return F_362 ( V_8 , V_716 , V_263 ) ;
switch ( V_716 ) {
case V_131 :
V_718 = F_92 ( V_261 ) ;
if ( ! ( V_8 -> V_132 &
( V_701 | V_702 ) ) ) {
V_8 -> V_116 . V_718 &= ~ 15 ;
V_8 -> V_116 . V_718 |= V_718 ;
F_365 ( V_8 , V_131 ) ;
return 1 ;
}
V_714 -> V_733 . V_116 . V_718 = V_718 | V_734 ;
V_714 -> V_733 . V_116 . V_735 = F_92 ( V_736 ) ;
case V_135 :
V_73 -> V_8 . V_116 . V_268 =
F_94 ( V_258 ) ;
V_714 -> V_259 = V_737 ;
V_257 = F_176 ( V_8 ) ;
V_714 -> V_733 . V_116 . V_738 = F_92 ( V_666 ) + V_257 ;
V_714 -> V_733 . V_116 . V_739 = V_716 ;
break;
default:
V_714 -> V_259 = V_740 ;
V_714 -> V_741 . V_739 = V_716 ;
V_714 -> V_741 . V_263 = V_263 ;
break;
}
return 0 ;
}
static int F_376 ( struct V_7 * V_8 )
{
++ V_8 -> V_217 . V_742 ;
return 1 ;
}
static int F_377 ( struct V_7 * V_8 )
{
V_8 -> V_715 -> V_259 = V_743 ;
return 0 ;
}
static int F_378 ( struct V_7 * V_8 )
{
unsigned long V_744 ;
int V_439 , V_745 , string ;
unsigned V_746 ;
V_744 = F_92 ( V_261 ) ;
string = ( V_744 & 16 ) != 0 ;
V_745 = ( V_744 & 8 ) != 0 ;
++ V_8 -> V_217 . V_747 ;
if ( string || V_745 )
return F_363 ( V_8 , 0 ) == V_269 ;
V_746 = V_744 >> 16 ;
V_439 = ( V_744 & 7 ) + 1 ;
F_175 ( V_8 ) ;
return F_379 ( V_8 , V_439 , V_746 ) ;
}
static void
F_380 ( struct V_7 * V_8 , unsigned char * V_748 )
{
V_748 [ 0 ] = 0x0f ;
V_748 [ 1 ] = 0x01 ;
V_748 [ 2 ] = 0xc1 ;
}
static bool F_381 ( struct V_12 * V_12 , unsigned long V_106 )
{
unsigned long V_749 = F_209 ;
if ( V_352 &
V_56 &&
F_58 ( V_12 , V_56 ) )
V_749 &= ~ ( V_529 | V_523 ) ;
return ( V_106 & V_749 ) == V_749 ;
}
static int F_382 ( struct V_7 * V_8 , unsigned long V_106 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_750 = V_106 ;
V_106 = ( V_106 & ~ V_12 -> V_234 ) |
( V_12 -> V_237 & V_12 -> V_234 ) ;
if ( ! F_381 ( V_12 , V_106 ) )
return 1 ;
if ( F_383 ( V_8 , V_106 ) )
return 1 ;
F_99 ( V_242 , V_750 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_541 &&
( ( V_106 & F_209 ) != F_209 ) )
return 1 ;
return F_383 ( V_8 , V_106 ) ;
}
}
static int F_384 ( struct V_7 * V_8 , unsigned long V_106 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_750 = V_106 ;
V_106 = ( V_106 & ~ V_12 -> V_240 ) |
( V_12 -> V_239 & V_12 -> V_240 ) ;
if ( F_385 ( V_8 , V_106 ) )
return 1 ;
F_99 ( V_486 , V_750 ) ;
return 0 ;
} else
return F_385 ( V_8 , V_106 ) ;
}
static void F_386 ( struct V_7 * V_8 )
{
if ( F_123 ( V_8 ) ) {
F_99 ( V_242 ,
F_92 ( V_242 ) & ~ V_231 ) ;
V_8 -> V_116 . V_229 &= ~ V_231 ;
} else
F_277 ( V_8 , F_164 ( V_8 , ~ V_231 ) ) ;
}
static int F_387 ( struct V_7 * V_8 )
{
unsigned long V_744 , V_106 ;
int V_751 ;
int V_403 ;
int V_752 ;
V_744 = F_92 ( V_261 ) ;
V_751 = V_744 & 15 ;
V_403 = ( V_744 >> 8 ) & 15 ;
switch ( ( V_744 >> 4 ) & 3 ) {
case 0 :
V_106 = F_388 ( V_8 , V_403 ) ;
F_389 ( V_751 , V_106 ) ;
switch ( V_751 ) {
case 0 :
V_752 = F_382 ( V_8 , V_106 ) ;
F_390 ( V_8 , V_752 ) ;
return 1 ;
case 3 :
V_752 = F_391 ( V_8 , V_106 ) ;
F_390 ( V_8 , V_752 ) ;
return 1 ;
case 4 :
V_752 = F_384 ( V_8 , V_106 ) ;
F_390 ( V_8 , V_752 ) ;
return 1 ;
case 8 : {
T_6 V_753 = F_392 ( V_8 ) ;
T_6 V_754 = F_388 ( V_8 , V_403 ) ;
V_752 = F_343 ( V_8 , V_754 ) ;
F_390 ( V_8 , V_752 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_753 <= V_754 )
return 1 ;
V_8 -> V_715 -> V_259 = V_755 ;
return 0 ;
}
}
break;
case 2 :
F_386 ( V_8 ) ;
F_389 ( 0 , F_347 ( V_8 ) ) ;
F_175 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_751 ) {
case 3 :
V_106 = F_279 ( V_8 ) ;
F_393 ( V_8 , V_403 , V_106 ) ;
F_394 ( V_751 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
case 8 :
V_106 = F_392 ( V_8 ) ;
F_393 ( V_8 , V_403 , V_106 ) ;
F_394 ( V_751 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_106 = ( V_744 >> V_756 ) & 0x0f ;
F_389 ( 0 , ( F_347 ( V_8 ) & ~ 0xful ) | V_106 ) ;
F_395 ( V_8 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_715 -> V_259 = 0 ;
F_396 ( V_8 , L_20 ,
( int ) ( V_744 >> 4 ) & 3 , V_751 ) ;
return 0 ;
}
static int F_397 ( struct V_7 * V_8 )
{
unsigned long V_744 ;
int V_757 , V_403 ;
if ( ! F_398 ( V_8 , 0 ) )
return 1 ;
V_757 = F_92 ( V_736 ) ;
if ( V_757 & V_758 ) {
if ( V_8 -> V_132 & V_702 ) {
V_8 -> V_715 -> V_733 . V_116 . V_718 = V_8 -> V_116 . V_718 ;
V_8 -> V_715 -> V_733 . V_116 . V_735 = V_757 ;
V_8 -> V_715 -> V_733 . V_116 . V_738 =
F_92 ( V_666 ) +
F_92 ( V_408 ) ;
V_8 -> V_715 -> V_733 . V_116 . V_739 = V_131 ;
V_8 -> V_715 -> V_259 = V_737 ;
return 0 ;
} else {
V_8 -> V_116 . V_735 &= ~ V_758 ;
V_8 -> V_116 . V_718 |= V_759 ;
F_99 ( V_736 , V_8 -> V_116 . V_735 ) ;
F_365 ( V_8 , V_131 ) ;
return 1 ;
}
}
if ( V_8 -> V_132 == 0 ) {
T_2 V_69 ;
V_69 = F_94 ( V_524 ) ;
V_69 &= ~ V_343 ;
F_102 ( V_524 , V_69 ) ;
V_8 -> V_116 . V_626 |= V_627 ;
return 1 ;
}
V_744 = F_92 ( V_261 ) ;
V_757 = V_744 & V_760 ;
V_403 = F_399 ( V_744 ) ;
if ( V_744 & V_761 ) {
unsigned long V_106 ;
if ( F_400 ( V_8 , V_757 , & V_106 ) )
return 1 ;
F_393 ( V_8 , V_403 , V_106 ) ;
} else
if ( F_401 ( V_8 , V_757 , V_8 -> V_116 . V_405 [ V_403 ] ) )
return 1 ;
F_175 ( V_8 ) ;
return 1 ;
}
static T_3 F_402 ( struct V_7 * V_8 )
{
return V_8 -> V_116 . V_718 ;
}
static void F_403 ( struct V_7 * V_8 , unsigned long V_106 )
{
}
static void F_404 ( struct V_7 * V_8 )
{
T_2 V_69 ;
F_405 ( V_8 -> V_116 . V_493 [ 0 ] , 0 ) ;
F_405 ( V_8 -> V_116 . V_493 [ 1 ] , 1 ) ;
F_405 ( V_8 -> V_116 . V_493 [ 2 ] , 2 ) ;
F_405 ( V_8 -> V_116 . V_493 [ 3 ] , 3 ) ;
F_405 ( V_8 -> V_116 . V_718 , 6 ) ;
V_8 -> V_116 . V_735 = F_92 ( V_736 ) ;
V_8 -> V_116 . V_626 &= ~ V_627 ;
V_69 = F_94 ( V_524 ) ;
V_69 |= V_343 ;
F_102 ( V_524 , V_69 ) ;
}
static void F_406 ( struct V_7 * V_8 , unsigned long V_106 )
{
F_99 ( V_736 , V_106 ) ;
}
static int F_407 ( struct V_7 * V_8 )
{
F_408 ( V_8 ) ;
return 1 ;
}
static int F_409 ( struct V_7 * V_8 )
{
T_2 V_306 = V_8 -> V_116 . V_405 [ V_762 ] ;
T_3 V_183 ;
if ( F_211 ( V_8 , V_306 , & V_183 ) ) {
F_410 ( V_306 ) ;
F_411 ( V_8 , 0 ) ;
return 1 ;
}
F_412 ( V_306 , V_183 ) ;
V_8 -> V_116 . V_405 [ V_763 ] = V_183 & - 1u ;
V_8 -> V_116 . V_405 [ V_662 ] = ( V_183 >> 32 ) & - 1u ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_413 ( struct V_7 * V_8 )
{
struct V_393 V_74 ;
T_2 V_306 = V_8 -> V_116 . V_405 [ V_762 ] ;
T_3 V_183 = ( V_8 -> V_116 . V_405 [ V_763 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_116 . V_405 [ V_662 ] & - 1u ) << 32 ) ;
V_74 . V_183 = V_183 ;
V_74 . V_79 = V_306 ;
V_74 . V_401 = false ;
if ( F_213 ( V_8 , & V_74 ) != 0 ) {
F_414 ( V_306 , V_183 ) ;
F_411 ( V_8 , 0 ) ;
return 1 ;
}
F_415 ( V_306 , V_183 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_416 ( struct V_7 * V_8 )
{
F_156 ( V_597 , V_8 ) ;
return 1 ;
}
static int F_417 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_524 ) ;
V_69 &= ~ V_334 ;
F_102 ( V_524 , V_69 ) ;
F_156 ( V_597 , V_8 ) ;
++ V_8 -> V_217 . V_764 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_715 -> V_765 &&
! F_418 ( V_8 ) ) {
V_8 -> V_715 -> V_259 = V_766 ;
return 0 ;
}
return 1 ;
}
static int F_419 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
return F_364 ( V_8 ) ;
}
static int F_420 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_421 ( V_8 ) ;
return 1 ;
}
static int F_422 ( struct V_7 * V_8 )
{
return F_363 ( V_8 , 0 ) == V_269 ;
}
static int F_423 ( struct V_7 * V_8 )
{
unsigned long V_744 = F_92 ( V_261 ) ;
F_424 ( V_8 , V_744 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_425 ( struct V_7 * V_8 )
{
int V_752 ;
V_752 = F_426 ( V_8 ) ;
F_390 ( V_8 , V_752 ) ;
return 1 ;
}
static int F_427 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_428 ( V_8 ) ;
return 1 ;
}
static int F_429 ( struct V_7 * V_8 )
{
T_3 V_767 = F_430 ( V_8 ) ;
T_2 V_79 = F_388 ( V_8 , V_762 ) ;
if ( F_431 ( V_8 , V_79 , V_767 ) == 0 )
F_175 ( V_8 ) ;
return 1 ;
}
static int F_432 ( struct V_7 * V_8 )
{
if ( F_303 ( V_768 ) ) {
unsigned long V_744 = F_92 ( V_261 ) ;
int V_769 , V_299 ;
V_769 = V_744 & V_770 ;
V_299 = V_744 & V_771 ;
if ( ( V_769 == V_772 ) &&
( V_299 == V_773 ) ) {
F_433 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
}
return F_363 ( V_8 , 0 ) == V_269 ;
}
static int F_434 ( struct V_7 * V_8 )
{
unsigned long V_744 = F_92 ( V_261 ) ;
int V_4 = V_744 & 0xff ;
F_435 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_436 ( struct V_7 * V_8 )
{
unsigned long V_744 = F_92 ( V_261 ) ;
T_2 V_299 = V_744 & 0xfff ;
F_437 ( V_8 , V_299 ) ;
return 1 ;
}
static int F_438 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_744 ;
bool V_262 = false ;
T_2 V_263 = 0 ;
T_4 V_774 ;
int V_775 , type , V_776 , V_777 ;
V_776 = ( V_73 -> V_722 & V_726 ) ;
V_777 = ( V_73 -> V_722 & V_778 ) ;
type = ( V_73 -> V_722 & V_779 ) ;
V_744 = F_92 ( V_261 ) ;
V_775 = ( T_2 ) V_744 >> 30 ;
if ( V_775 == V_780 && V_776 ) {
switch ( type ) {
case V_693 :
V_8 -> V_116 . V_781 = false ;
F_356 ( V_8 , true ) ;
break;
case V_27 :
case V_688 :
F_439 ( V_8 ) ;
break;
case V_23 :
if ( V_73 -> V_722 &
V_782 ) {
V_262 = true ;
V_263 =
F_94 ( V_783 ) ;
}
case V_272 :
F_440 ( V_8 ) ;
break;
default:
break;
}
}
V_774 = V_744 ;
if ( ! V_776 || ( type != V_23 &&
type != V_27 &&
type != V_693 ) )
F_175 ( V_8 ) ;
if ( F_441 ( V_8 , V_774 ,
type == V_688 ? V_777 : - 1 , V_775 ,
V_262 , V_263 ) == V_784 ) {
V_8 -> V_715 -> V_259 = V_728 ;
V_8 -> V_715 -> V_729 . V_730 = V_785 ;
V_8 -> V_715 -> V_729 . V_732 = 0 ;
return 0 ;
}
F_99 ( V_736 , F_92 ( V_736 ) & ~ 55 ) ;
return 1 ;
}
static int F_442 ( struct V_7 * V_8 )
{
unsigned long V_744 ;
T_1 V_85 ;
T_2 V_263 ;
int V_786 ;
V_744 = F_92 ( V_261 ) ;
V_786 = ( V_744 >> 7 ) & 0x3 ;
if ( V_786 != 0x3 && V_786 != 0x1 && V_786 != 0 ) {
F_69 ( V_89 L_21 ) ;
F_69 ( V_89 L_22 ,
( long unsigned int ) F_95 ( V_787 ) ,
F_92 ( V_788 ) ) ;
F_69 ( V_89 L_23 ,
( long unsigned int ) V_744 ) ;
V_8 -> V_715 -> V_259 = V_789 ;
V_8 -> V_715 -> V_790 . V_791 = V_792 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_722 & V_726 ) &&
F_52 () &&
( V_744 & V_793 ) )
F_105 ( V_251 , V_694 ) ;
V_85 = F_95 ( V_787 ) ;
F_372 ( V_85 , V_744 ) ;
V_263 = V_744 & ( 1U << 1 ) ;
V_263 |= ( V_744 & ( 1U << 2 ) ) << 2 ;
V_263 |= ( V_744 >> 3 ) & 0x1 ;
V_8 -> V_116 . V_744 = V_744 ;
return F_375 ( V_8 , V_85 , V_263 , NULL , 0 ) ;
}
static T_3 F_443 ( T_3 V_794 , int V_795 )
{
int V_75 ;
T_3 V_105 = 0 ;
for ( V_75 = 51 ; V_75 > V_443 . V_796 ; V_75 -- )
V_105 |= ( 1ULL << V_75 ) ;
if ( V_795 > 2 )
V_105 |= 0xf8 ;
else if ( V_795 == 2 ) {
if ( V_794 & ( 1ULL << 7 ) )
V_105 |= 0x1ff000 ;
else
V_105 |= 0x78 ;
}
return V_105 ;
}
static void F_444 ( struct V_7 * V_8 , T_3 V_794 ,
int V_795 )
{
F_69 ( V_89 L_24 , V_506 , V_794 , V_795 ) ;
F_445 ( ( V_794 & 0x7 ) == 0x2 ) ;
F_445 ( ( V_794 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_445 ( ( V_794 & 0x7 ) == 0x4 ) ;
if ( ( V_794 & 0x7 ) ) {
T_3 V_797 = V_794 & F_443 ( V_794 , V_795 ) ;
if ( V_797 != 0 ) {
F_69 ( V_89 L_25 ,
V_506 , V_797 ) ;
F_445 ( 1 ) ;
}
if ( V_795 == 1 || ( V_795 == 2 && ( V_794 & ( 1ULL << 7 ) ) ) ) {
T_3 V_798 = ( V_794 & 0x38 ) >> 3 ;
if ( V_798 == 2 || V_798 == 3 ||
V_798 == 7 ) {
F_69 ( V_89 L_26 ,
V_506 , V_798 ) ;
F_445 ( 1 ) ;
}
}
}
}
static int F_446 ( struct V_7 * V_8 )
{
T_3 V_799 [ 4 ] ;
int V_800 , V_75 , V_114 ;
T_1 V_85 ;
V_85 = F_95 ( V_787 ) ;
V_114 = F_447 ( V_8 , V_85 , true ) ;
if ( F_303 ( V_114 == V_801 ) )
return F_448 ( V_8 , V_85 , 0 , NULL , 0 ) ==
V_269 ;
if ( F_100 ( V_114 == V_802 ) )
return F_375 ( V_8 , V_85 , 0 , NULL , 0 ) ;
if ( F_100 ( V_114 == V_803 ) )
return 1 ;
F_69 ( V_89 L_27 ) ;
F_69 ( V_89 L_28 , V_85 ) ;
V_800 = F_449 ( V_8 , V_85 , V_799 ) ;
for ( V_75 = V_804 ; V_75 > V_804 - V_800 ; -- V_75 )
F_444 ( V_8 , V_799 [ V_75 - 1 ] , V_75 ) ;
V_8 -> V_715 -> V_259 = V_789 ;
V_8 -> V_715 -> V_790 . V_791 = V_805 ;
return 0 ;
}
static int F_450 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_524 ) ;
V_69 &= ~ V_335 ;
F_102 ( V_524 , V_69 ) ;
++ V_8 -> V_217 . V_806 ;
F_156 ( V_597 , V_8 ) ;
return 1 ;
}
static int F_451 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
enum V_720 V_752 = V_269 ;
int V_114 = 1 ;
T_2 V_807 ;
bool V_808 ;
unsigned V_809 = 130 ;
V_807 = F_94 ( V_524 ) ;
V_808 = V_807 & V_334 ;
while ( ! F_253 ( V_8 ) && V_809 -- != 0 ) {
if ( V_808 && F_358 ( V_8 ) )
return F_417 ( & V_73 -> V_8 ) ;
if ( F_170 ( V_597 , & V_8 -> V_810 ) )
return 1 ;
V_752 = F_363 ( V_8 , V_811 ) ;
if ( V_752 == V_812 ) {
++ V_8 -> V_217 . V_813 ;
V_114 = 0 ;
goto V_547;
}
if ( V_752 != V_269 ) {
V_8 -> V_715 -> V_259 = V_728 ;
V_8 -> V_715 -> V_729 . V_730 = V_785 ;
V_8 -> V_715 -> V_729 . V_732 = 0 ;
return 0 ;
}
if ( V_8 -> V_116 . V_711 ) {
V_8 -> V_116 . V_711 = 0 ;
V_114 = F_364 ( V_8 ) ;
goto V_547;
}
if ( F_452 ( V_814 ) )
goto V_547;
if ( F_453 () )
F_454 () ;
}
V_73 -> F_252 = F_252 ( V_8 ) ;
V_547:
return V_114 ;
}
static int F_455 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_456 ( V_8 ) ;
return 1 ;
}
static int F_457 ( struct V_7 * V_8 )
{
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
static struct V_90 * F_458 ( struct V_6 * V_73 )
{
struct V_815 * V_816 ;
F_80 (item, &vmx->nested.vmcs02_pool, list)
if ( V_816 -> V_817 == V_73 -> V_13 . V_818 ) {
F_459 ( & V_816 -> V_819 , & V_73 -> V_13 . V_820 ) ;
return & V_816 -> V_821 ;
}
if ( V_73 -> V_13 . V_822 >= F_460 ( V_823 , 1 ) ) {
V_816 = F_461 ( V_73 -> V_13 . V_820 . V_824 ,
struct V_815 , V_819 ) ;
V_816 -> V_817 = V_73 -> V_13 . V_818 ;
F_459 ( & V_816 -> V_819 , & V_73 -> V_13 . V_820 ) ;
return & V_816 -> V_821 ;
}
V_816 = F_462 ( sizeof( struct V_815 ) , V_448 ) ;
if ( ! V_816 )
return NULL ;
V_816 -> V_821 . V_87 = F_239 () ;
if ( ! V_816 -> V_821 . V_87 ) {
F_463 ( V_816 ) ;
return NULL ;
}
F_70 ( & V_816 -> V_821 ) ;
V_816 -> V_817 = V_73 -> V_13 . V_818 ;
F_159 ( & ( V_816 -> V_819 ) , & ( V_73 -> V_13 . V_820 ) ) ;
V_73 -> V_13 . V_822 ++ ;
return & V_816 -> V_821 ;
}
static void F_464 ( struct V_6 * V_73 , T_1 V_817 )
{
struct V_815 * V_816 ;
F_80 (item, &vmx->nested.vmcs02_pool, list)
if ( V_816 -> V_817 == V_817 ) {
F_242 ( & V_816 -> V_821 ) ;
F_83 ( & V_816 -> V_819 ) ;
F_463 ( V_816 ) ;
V_73 -> V_13 . V_822 -- ;
return;
}
}
static void F_465 ( struct V_6 * V_73 )
{
struct V_815 * V_816 , * V_417 ;
F_229 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_73 -> V_90 != & V_816 -> V_821 )
F_242 ( & V_816 -> V_821 ) ;
F_83 ( & V_816 -> V_819 ) ;
F_463 ( V_816 ) ;
}
V_73 -> V_13 . V_822 = 0 ;
if ( V_73 -> V_90 != & V_73 -> V_825 )
F_242 ( & V_73 -> V_825 ) ;
}
static void F_466 ( struct V_7 * V_8 )
{
F_172 ( V_8 , F_169 ( V_8 )
& ~ ( V_826 | V_827 | V_828 |
V_829 | V_830 | V_831 ) ) ;
}
static void F_467 ( struct V_7 * V_8 )
{
F_172 ( V_8 , ( F_169 ( V_8 )
& ~ ( V_827 | V_828 | V_829 |
V_830 | V_831 ) )
| V_826 ) ;
}
static void F_468 ( struct V_7 * V_8 ,
T_2 V_832 )
{
if ( F_6 ( V_8 ) -> V_13 . V_818 == - 1ull ) {
F_467 ( V_8 ) ;
return;
}
F_172 ( V_8 , ( F_169 ( V_8 )
& ~ ( V_826 | V_827 | V_828 |
V_830 | V_831 ) )
| V_829 ) ;
F_9 ( V_8 ) -> V_832 = V_832 ;
}
static enum V_833 F_469 ( struct V_834 * V_835 )
{
struct V_6 * V_73 =
F_7 ( V_835 , struct V_6 , V_13 . V_836 ) ;
V_73 -> V_13 . V_837 = true ;
F_156 ( V_597 , & V_73 -> V_8 ) ;
F_325 ( & V_73 -> V_8 ) ;
return V_838 ;
}
static int F_470 ( struct V_7 * V_8 )
{
struct V_471 V_553 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_87 * V_839 ;
const T_3 V_840 = V_400
| V_411 ;
if ( ! F_471 ( V_8 , V_415 ) ||
! F_164 ( V_8 , V_529 ) ||
( F_169 ( V_8 ) & V_249 ) ) {
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
F_257 ( V_8 , & V_553 , V_473 ) ;
if ( F_140 ( V_8 ) && ! V_553 . V_495 ) {
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_281 ( V_8 ) ) {
F_411 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_73 -> V_13 . V_541 ) {
F_468 ( V_8 , V_841 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( ( V_73 -> V_13 . V_391 & V_840 )
!= V_840 ) {
F_411 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_459 ) {
V_839 = F_239 () ;
if ( ! V_839 )
return - V_456 ;
V_839 -> V_441 |= ( 1u << 31 ) ;
F_67 ( V_839 ) ;
V_73 -> V_13 . V_842 = V_839 ;
}
F_225 ( & ( V_73 -> V_13 . V_820 ) ) ;
V_73 -> V_13 . V_822 = 0 ;
F_472 ( & V_73 -> V_13 . V_836 , V_843 ,
V_844 ) ;
V_73 -> V_13 . V_836 . V_845 = F_469 ;
V_73 -> V_13 . V_541 = true ;
F_175 ( V_8 ) ;
F_466 ( V_8 ) ;
return 1 ;
}
static int F_473 ( struct V_7 * V_8 )
{
struct V_471 V_553 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! V_73 -> V_13 . V_541 ) {
F_365 ( V_8 , V_26 ) ;
return 0 ;
}
F_257 ( V_8 , & V_553 , V_473 ) ;
if ( ( F_169 ( V_8 ) & V_249 ) ||
( F_140 ( V_8 ) && ! V_553 . V_495 ) ) {
F_365 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_281 ( V_8 ) ) {
F_411 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_474 ( struct V_6 * V_73 )
{
T_2 V_625 ;
if ( V_459 ) {
if ( V_73 -> V_13 . V_14 != NULL ) {
F_475 ( V_73 ) ;
V_73 -> V_13 . V_846 = false ;
V_625 = F_94 ( V_637 ) ;
V_625 &= ~ V_67 ;
F_102 ( V_637 , V_625 ) ;
F_103 ( V_635 , - 1ull ) ;
}
}
F_476 ( V_73 -> V_13 . V_847 ) ;
F_13 ( V_73 -> V_13 . V_847 ) ;
}
static void F_477 ( struct V_6 * V_73 )
{
if ( ! V_73 -> V_13 . V_541 )
return;
V_73 -> V_13 . V_541 = false ;
if ( V_73 -> V_13 . V_818 != - 1ull ) {
F_474 ( V_73 ) ;
V_73 -> V_13 . V_818 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
}
if ( V_459 )
F_240 ( V_73 -> V_13 . V_842 ) ;
if ( V_73 -> V_13 . V_583 ) {
F_13 ( V_73 -> V_13 . V_583 ) ;
V_73 -> V_13 . V_583 = 0 ;
}
F_465 ( V_73 ) ;
}
static int F_478 ( struct V_7 * V_8 )
{
if ( ! F_473 ( V_8 ) )
return 1 ;
F_477 ( F_6 ( V_8 ) ) ;
F_175 ( V_8 ) ;
F_466 ( V_8 ) ;
return 1 ;
}
static int F_479 ( struct V_7 * V_8 ,
unsigned long V_744 ,
T_2 V_848 , T_5 * V_114 )
{
int V_849 = V_848 & 3 ;
int V_850 = ( V_848 >> 7 ) & 7 ;
bool V_851 = V_848 & ( 1u << 10 ) ;
int V_852 = ( V_848 >> 15 ) & 7 ;
int V_853 = ( V_848 >> 18 ) & 0xf ;
bool V_854 = ! ( V_848 & ( 1u << 22 ) ) ;
int V_855 = ( V_848 >> 23 ) & 0xf ;
bool V_856 = ! ( V_848 & ( 1u << 27 ) ) ;
if ( V_851 ) {
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
* V_114 = F_280 ( V_8 , V_852 ) ;
if ( V_856 )
* V_114 += F_388 ( V_8 , V_855 ) ;
if ( V_854 )
* V_114 += F_388 ( V_8 , V_853 ) << V_849 ;
* V_114 += V_744 ;
if ( V_850 == 1 )
* V_114 &= 0xffffffff ;
return 0 ;
}
static int F_480 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_5 V_81 ;
T_1 V_817 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
struct V_857 V_858 ;
if ( ! F_473 ( V_8 ) )
return 1 ;
if ( F_479 ( V_8 , F_92 ( V_261 ) ,
F_94 ( V_859 ) , & V_81 ) )
return 1 ;
if ( F_481 ( & V_8 -> V_116 . V_860 , V_81 , & V_817 ,
sizeof( V_817 ) , & V_858 ) ) {
F_482 ( V_8 , & V_858 ) ;
return 1 ;
}
if ( ! F_483 ( V_817 , V_438 ) ) {
F_468 ( V_8 , V_861 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_817 == V_73 -> V_13 . V_818 ) {
F_474 ( V_73 ) ;
V_73 -> V_13 . V_818 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
}
V_15 = F_10 ( V_8 , V_817 ) ;
if ( V_15 == NULL ) {
F_156 ( V_270 , V_8 ) ;
return 1 ;
}
V_12 = F_484 ( V_15 ) ;
V_12 -> V_862 = 0 ;
F_476 ( V_15 ) ;
F_13 ( V_15 ) ;
F_464 ( V_73 , V_817 ) ;
F_175 ( V_8 ) ;
F_466 ( V_8 ) ;
return 1 ;
}
static int F_485 ( struct V_7 * V_8 )
{
return F_486 ( V_8 , true ) ;
}
static int F_487 ( struct V_7 * V_8 )
{
return F_486 ( V_8 , false ) ;
}
static inline int F_488 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_863 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_489 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_490 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_114 )
{
short V_299 = F_8 ( V_9 ) ;
char * V_119 ;
if ( V_299 < 0 )
return 0 ;
V_119 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_299 ;
switch ( F_488 ( V_9 ) ) {
case V_864 :
* V_114 = * ( ( V_865 * ) V_119 ) ;
return 1 ;
case V_866 :
* V_114 = * ( ( T_4 * ) V_119 ) ;
return 1 ;
case V_863 :
* V_114 = * ( ( T_2 * ) V_119 ) ;
return 1 ;
case V_867 :
* V_114 = * ( ( T_3 * ) V_119 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_491 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_868 ) {
short V_299 = F_8 ( V_9 ) ;
char * V_119 = ( ( char * ) F_9 ( V_8 ) ) + V_299 ;
if ( V_299 < 0 )
return false ;
switch ( F_488 ( V_9 ) ) {
case V_866 :
* ( T_4 * ) V_119 = V_868 ;
return true ;
case V_863 :
* ( T_2 * ) V_119 = V_868 ;
return true ;
case V_867 :
* ( T_3 * ) V_119 = V_868 ;
return true ;
case V_864 :
* ( V_865 * ) V_119 = V_868 ;
return true ;
default:
return false ;
}
}
static void F_475 ( struct V_6 * V_73 )
{
int V_75 ;
unsigned long V_9 ;
T_3 V_868 ;
struct V_87 * V_839 = V_73 -> V_13 . V_842 ;
const unsigned long * V_236 = V_451 ;
const int V_869 = V_450 ;
F_71 ( V_839 ) ;
for ( V_75 = 0 ; V_75 < V_869 ; V_75 ++ ) {
V_9 = V_236 [ V_75 ] ;
switch ( F_488 ( V_9 ) ) {
case V_866 :
V_868 = F_93 ( V_9 ) ;
break;
case V_863 :
V_868 = F_94 ( V_9 ) ;
break;
case V_867 :
V_868 = F_95 ( V_9 ) ;
break;
case V_864 :
V_868 = F_92 ( V_9 ) ;
break;
}
F_491 ( & V_73 -> V_8 , V_9 , V_868 ) ;
}
F_67 ( V_839 ) ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
}
static void F_492 ( struct V_6 * V_73 )
{
const unsigned long * V_236 [] = {
V_451 ,
V_455
} ;
const int V_870 [] = {
V_450 ,
V_454
} ;
int V_75 , V_871 ;
unsigned long V_9 ;
T_3 V_868 = 0 ;
struct V_87 * V_839 = V_73 -> V_13 . V_842 ;
F_71 ( V_839 ) ;
for ( V_871 = 0 ; V_871 < F_493 ( V_236 ) ; V_871 ++ ) {
for ( V_75 = 0 ; V_75 < V_870 [ V_871 ] ; V_75 ++ ) {
V_9 = V_236 [ V_871 ] [ V_75 ] ;
F_490 ( & V_73 -> V_8 , V_9 , & V_868 ) ;
switch ( F_488 ( V_9 ) ) {
case V_866 :
F_101 ( V_9 , ( T_4 ) V_868 ) ;
break;
case V_863 :
F_102 ( V_9 , ( T_2 ) V_868 ) ;
break;
case V_867 :
F_103 ( V_9 , ( T_3 ) V_868 ) ;
break;
case V_864 :
F_99 ( V_9 , ( long ) V_868 ) ;
break;
}
}
}
F_67 ( V_839 ) ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
}
static int F_494 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( V_73 -> V_13 . V_818 == - 1ull ) {
F_467 ( V_8 ) ;
F_175 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_495 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_868 ;
unsigned long V_744 = F_92 ( V_261 ) ;
T_2 V_848 = F_94 ( V_859 ) ;
T_5 V_81 = 0 ;
if ( ! F_473 ( V_8 ) ||
! F_494 ( V_8 ) )
return 1 ;
V_9 = F_388 ( V_8 , ( ( ( V_848 ) >> 28 ) & 0xf ) ) ;
if ( ! F_490 ( V_8 , V_9 , & V_868 ) ) {
F_468 ( V_8 , V_872 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_848 & ( 1u << 10 ) ) {
F_393 ( V_8 , ( ( ( V_848 ) >> 3 ) & 0xf ) ,
V_868 ) ;
} else {
if ( F_479 ( V_8 , V_744 ,
V_848 , & V_81 ) )
return 1 ;
F_496 ( & V_8 -> V_116 . V_860 , V_81 ,
& V_868 , ( F_140 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_466 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_497 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_81 ;
unsigned long V_744 = F_92 ( V_261 ) ;
T_2 V_848 = F_94 ( V_859 ) ;
T_3 V_868 = 0 ;
struct V_857 V_858 ;
if ( ! F_473 ( V_8 ) ||
! F_494 ( V_8 ) )
return 1 ;
if ( V_848 & ( 1u << 10 ) )
V_868 = F_388 ( V_8 ,
( ( ( V_848 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_479 ( V_8 , V_744 ,
V_848 , & V_81 ) )
return 1 ;
if ( F_481 ( & V_8 -> V_116 . V_860 , V_81 ,
& V_868 , ( F_140 ( V_8 ) ? 8 : 4 ) , & V_858 ) ) {
F_482 ( V_8 , & V_858 ) ;
return 1 ;
}
}
V_9 = F_388 ( V_8 , ( ( ( V_848 ) >> 28 ) & 0xf ) ) ;
if ( F_489 ( V_9 ) ) {
F_468 ( V_8 ,
V_873 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( ! F_491 ( V_8 , V_9 , V_868 ) ) {
F_468 ( V_8 , V_872 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_466 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_498 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_5 V_81 ;
T_1 V_817 ;
struct V_857 V_858 ;
T_2 V_625 ;
if ( ! F_473 ( V_8 ) )
return 1 ;
if ( F_479 ( V_8 , F_92 ( V_261 ) ,
F_94 ( V_859 ) , & V_81 ) )
return 1 ;
if ( F_481 ( & V_8 -> V_116 . V_860 , V_81 , & V_817 ,
sizeof( V_817 ) , & V_858 ) ) {
F_482 ( V_8 , & V_858 ) ;
return 1 ;
}
if ( ! F_483 ( V_817 , V_438 ) ) {
F_468 ( V_8 , V_874 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_73 -> V_13 . V_818 != V_817 ) {
struct V_12 * V_875 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_817 ) ;
if ( V_15 == NULL ) {
F_467 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
V_875 = F_484 ( V_15 ) ;
if ( V_875 -> V_441 != V_365 ) {
F_476 ( V_15 ) ;
F_15 ( V_15 ) ;
F_468 ( V_8 ,
V_876 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_73 -> V_13 . V_818 != - 1ull )
F_474 ( V_73 ) ;
V_73 -> V_13 . V_818 = V_817 ;
V_73 -> V_13 . V_14 = V_875 ;
V_73 -> V_13 . V_847 = V_15 ;
if ( V_459 ) {
V_625 = F_94 ( V_637 ) ;
V_625 |= V_67 ;
F_102 ( V_637 , V_625 ) ;
F_103 ( V_635 ,
F_68 ( V_73 -> V_13 . V_842 ) ) ;
V_73 -> V_13 . V_846 = true ;
}
}
F_466 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_499 ( struct V_7 * V_8 )
{
unsigned long V_744 = F_92 ( V_261 ) ;
T_2 V_848 = F_94 ( V_859 ) ;
T_5 V_877 ;
struct V_857 V_858 ;
if ( ! F_473 ( V_8 ) )
return 1 ;
if ( F_479 ( V_8 , V_744 ,
V_848 , & V_877 ) )
return 1 ;
if ( F_496 ( & V_8 -> V_116 . V_860 , V_877 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_818 ,
sizeof( T_3 ) , & V_858 ) ) {
F_482 ( V_8 , & V_858 ) ;
return 1 ;
}
F_466 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_500 ( struct V_7 * V_8 )
{
T_2 V_848 , V_878 ;
unsigned long type ;
T_5 V_81 ;
struct V_857 V_858 ;
struct {
T_3 V_84 , V_85 ;
} V_83 ;
T_3 V_879 = ( ( 1ull << 51 ) - 1 ) & V_534 ;
if ( ! ( V_352 & V_55 ) ||
! ( V_353 & V_354 ) ) {
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
if ( ! F_473 ( V_8 ) )
return 1 ;
if ( ! F_164 ( V_8 , V_529 ) ) {
F_365 ( V_8 , V_26 ) ;
return 1 ;
}
V_848 = F_94 ( V_859 ) ;
type = F_388 ( V_8 , ( V_848 >> 28 ) & 0xf ) ;
V_878 = ( V_353 >> V_880 ) & 6 ;
if ( ! ( V_878 & ( 1UL << type ) ) ) {
F_468 ( V_8 ,
V_881 ) ;
return 1 ;
}
if ( F_479 ( V_8 , F_92 ( V_261 ) ,
V_848 , & V_81 ) )
return 1 ;
if ( F_481 ( & V_8 -> V_116 . V_860 , V_81 , & V_83 ,
sizeof( V_83 ) , & V_858 ) ) {
F_482 ( V_8 , & V_858 ) ;
return 1 ;
}
switch ( type ) {
case V_102 :
if ( ( V_83 . V_84 & V_879 ) !=
( F_501 ( V_8 ) & V_879 ) )
break;
case V_100 :
F_502 ( V_8 ) ;
F_503 ( V_8 ) ;
F_466 ( V_8 ) ;
break;
default:
F_371 ( 1 ) ;
break;
}
F_175 ( V_8 ) ;
return 1 ;
}
static bool F_504 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_744 ;
T_1 V_882 , V_883 ;
unsigned int V_746 ;
int V_439 ;
T_6 V_884 ;
if ( ! F_57 ( V_12 , V_345 ) )
return F_57 ( V_12 , V_344 ) ;
V_744 = F_92 ( V_261 ) ;
V_746 = V_744 >> 16 ;
V_439 = ( V_744 & 7 ) + 1 ;
V_883 = ( T_1 ) - 1 ;
V_884 = - 1 ;
while ( V_439 > 0 ) {
if ( V_746 < 0x8000 )
V_882 = V_12 -> V_885 ;
else if ( V_746 < 0x10000 )
V_882 = V_12 -> V_886 ;
else
return 1 ;
V_882 += ( V_746 & 0x7fff ) / 8 ;
if ( V_883 != V_882 )
if ( F_505 ( V_8 -> V_17 , V_882 , & V_884 , 1 ) )
return 1 ;
if ( V_884 & ( 1 << ( V_746 & 7 ) ) )
return 1 ;
V_746 ++ ;
V_439 -- ;
V_883 = V_882 ;
}
return 0 ;
}
static bool F_506 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_259 )
{
T_2 V_362 = V_8 -> V_116 . V_405 [ V_762 ] ;
T_1 V_882 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_882 = V_12 -> V_277 ;
if ( V_259 == V_887 )
V_882 += 2048 ;
if ( V_362 >= 0xc0000000 ) {
V_362 -= 0xc0000000 ;
V_882 += 1024 ;
}
if ( V_362 < 1024 * 8 ) {
unsigned char V_884 ;
if ( F_505 ( V_8 -> V_17 , V_882 + V_362 / 8 , & V_884 , 1 ) )
return 1 ;
return 1 & ( V_884 >> ( V_362 & 7 ) ) ;
} else
return 1 ;
}
static bool F_507 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_744 = F_92 ( V_261 ) ;
int V_751 = V_744 & 15 ;
int V_403 = ( V_744 >> 8 ) & 15 ;
unsigned long V_106 = F_388 ( V_8 , V_403 ) ;
switch ( ( V_744 >> 4 ) & 3 ) {
case 0 :
switch ( V_751 ) {
case 0 :
if ( V_12 -> V_234 &
( V_106 ^ V_12 -> V_238 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_888 >= 1 &&
V_12 -> V_889 == V_106 ) ||
( V_12 -> V_888 >= 2 &&
V_12 -> V_890 == V_106 ) ||
( V_12 -> V_888 >= 3 &&
V_12 -> V_891 == V_106 ) ||
( V_12 -> V_888 >= 4 &&
V_12 -> V_892 == V_106 ) )
return 0 ;
if ( F_57 ( V_12 , V_339 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_240 &
( V_12 -> V_241 ^ V_106 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_341 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_12 -> V_234 & V_231 ) &&
( V_12 -> V_238 & V_231 ) )
return 1 ;
break;
case 1 :
switch ( V_751 ) {
case 3 :
if ( V_12 -> V_69 &
V_340 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_342 )
return 1 ;
break;
}
break;
case 3 :
if ( V_12 -> V_234 & 0xe &
( V_106 ^ V_12 -> V_238 ) )
return 1 ;
if ( ( V_12 -> V_234 & 0x1 ) &&
! ( V_12 -> V_238 & 0x1 ) &&
( V_106 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_508 ( struct V_7 * V_8 )
{
T_2 V_19 = F_94 ( V_260 ) ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_259 = V_73 -> V_259 ;
F_509 ( F_176 ( V_8 ) , V_259 ,
F_92 ( V_261 ) ,
V_73 -> V_722 ,
V_19 ,
F_94 ( V_725 ) ,
V_893 ) ;
if ( V_73 -> V_13 . V_696 )
return 0 ;
if ( F_100 ( V_73 -> V_894 ) ) {
F_510 ( L_29 , V_506 ,
F_94 ( V_104 ) ) ;
return 1 ;
}
switch ( V_259 ) {
case V_895 :
if ( ! F_62 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_101 ;
else if ( F_18 ( V_19 ) &&
! ( V_12 -> V_237 & V_231 ) )
return 0 ;
return V_12 -> V_139 &
( 1u << ( V_19 & V_21 ) ) ;
case V_896 :
return 0 ;
case V_897 :
return 1 ;
case V_898 :
return F_57 ( V_12 , V_334 ) ;
case V_899 :
return F_57 ( V_12 , V_335 ) ;
case V_900 :
return 1 ;
case V_901 :
return 1 ;
case V_902 :
return F_57 ( V_12 , V_336 ) ;
case V_903 :
return 1 ;
case V_904 :
return F_57 ( V_12 , V_337 ) ;
case V_905 :
return F_57 ( V_12 , V_347 ) ;
case V_906 :
return F_57 ( V_12 , V_348 ) ;
case V_907 : case V_908 :
case V_909 : case V_910 :
case V_911 : case V_912 :
case V_913 : case V_914 :
case V_915 : case V_916 :
case V_917 :
return 1 ;
case V_918 :
return F_507 ( V_8 , V_12 ) ;
case V_919 :
return F_57 ( V_12 , V_343 ) ;
case V_920 :
return F_504 ( V_8 , V_12 ) ;
case V_921 :
case V_887 :
return F_506 ( V_8 , V_12 , V_259 ) ;
case V_922 :
return 1 ;
case V_923 :
return F_57 ( V_12 , V_338 ) ;
case V_924 :
return F_57 ( V_12 , V_346 ) ;
case V_925 :
return F_57 ( V_12 , V_349 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_926 :
return 0 ;
case V_927 :
return 1 ;
case V_928 :
return F_58 ( V_12 ,
V_35 ) ;
case V_792 :
return 0 ;
case V_805 :
return 0 ;
case V_929 :
return F_58 ( V_12 , V_63 ) ;
case V_930 :
return 1 ;
default:
return 1 ;
}
}
static void F_511 ( struct V_7 * V_8 , T_3 * V_931 , T_3 * V_932 )
{
* V_931 = F_92 ( V_261 ) ;
* V_932 = F_94 ( V_260 ) ;
}
static int F_512 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_259 = V_73 -> V_259 ;
T_2 V_933 = V_73 -> V_722 ;
if ( V_73 -> F_252 )
return F_451 ( V_8 ) ;
if ( F_123 ( V_8 ) && F_508 ( V_8 ) ) {
F_179 ( V_8 , V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
return 1 ;
}
if ( V_259 & V_934 ) {
V_8 -> V_715 -> V_259 = V_935 ;
V_8 -> V_715 -> V_936 . V_937
= V_259 ;
return 0 ;
}
if ( F_100 ( V_73 -> V_894 ) ) {
V_8 -> V_715 -> V_259 = V_935 ;
V_8 -> V_715 -> V_936 . V_937
= F_94 ( V_104 ) ;
return 0 ;
}
if ( ( V_933 & V_726 ) &&
( V_259 != V_895 &&
V_259 != V_792 &&
V_259 != V_900 ) ) {
V_8 -> V_715 -> V_259 = V_728 ;
V_8 -> V_715 -> V_729 . V_730 = V_938 ;
V_8 -> V_715 -> V_729 . V_732 = 2 ;
V_8 -> V_715 -> V_729 . V_183 [ 0 ] = V_933 ;
V_8 -> V_715 -> V_729 . V_183 [ 1 ] = V_259 ;
return 0 ;
}
if ( F_100 ( ! F_52 () && V_73 -> V_661 &&
! ( F_123 ( V_8 ) && F_59 (
F_9 ( V_8 ) ) ) ) ) {
if ( F_358 ( V_8 ) ) {
V_73 -> V_661 = 0 ;
} else if ( V_73 -> V_689 > 1000000000LL &&
V_8 -> V_116 . V_939 ) {
F_69 ( V_166 L_30
L_31 ,
V_506 , V_8 -> V_301 ) ;
V_73 -> V_661 = 0 ;
}
}
if ( V_259 < V_940
&& V_941 [ V_259 ] )
return V_941 [ V_259 ] ( V_8 ) ;
else {
V_8 -> V_715 -> V_259 = V_789 ;
V_8 -> V_715 -> V_790 . V_791 = V_259 ;
}
return 0 ;
}
static void V_463 ( struct V_7 * V_8 , int V_942 , int V_943 )
{
if ( V_943 == - 1 || V_942 < V_943 ) {
F_102 ( V_677 , 0 ) ;
return;
}
F_102 ( V_677 , V_943 ) ;
}
static void F_513 ( struct V_7 * V_8 , bool V_944 )
{
T_2 V_945 ;
if ( ! F_28 () ||
! F_321 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_945 = F_94 ( V_637 ) ;
if ( V_944 ) {
V_945 &= ~ V_35 ;
V_945 |= V_36 ;
} else {
V_945 &= ~ V_36 ;
V_945 |= V_35 ;
}
F_102 ( V_637 , V_945 ) ;
F_186 ( V_8 ) ;
}
static void F_514 ( struct V_17 * V_17 , int V_946 )
{
T_4 V_947 ;
T_6 V_413 ;
if ( ! F_321 ( V_17 ) )
return;
if ( V_946 == - 1 )
V_946 = 0 ;
V_947 = F_93 ( V_642 ) ;
V_413 = V_947 >> 8 ;
if ( V_946 != V_413 ) {
V_947 &= 0xff ;
V_947 |= V_946 << 8 ;
F_101 ( V_642 , V_947 ) ;
}
}
static void F_515 ( int V_4 )
{
T_4 V_947 ;
T_6 V_413 ;
V_947 = F_93 ( V_642 ) ;
V_413 = ( T_6 ) V_947 & 0xff ;
if ( ( T_6 ) V_4 != V_413 ) {
V_947 &= ~ 0xff ;
V_947 |= ( T_6 ) V_4 ;
F_101 ( V_642 , V_947 ) ;
}
}
static void F_516 ( struct V_7 * V_8 , int V_948 )
{
if ( V_948 == - 1 )
return;
F_515 ( V_948 ) ;
}
static void F_517 ( struct V_7 * V_8 , T_3 * V_949 )
{
if ( ! F_321 ( V_8 -> V_17 ) )
return;
F_103 ( V_638 , V_949 [ 0 ] ) ;
F_103 ( V_639 , V_949 [ 1 ] ) ;
F_103 ( V_640 , V_949 [ 2 ] ) ;
F_103 ( V_641 , V_949 [ 3 ] ) ;
}
static void F_518 ( struct V_6 * V_73 )
{
T_2 V_723 ;
if ( ! ( V_73 -> V_259 == V_926
|| V_73 -> V_259 == V_895 ) )
return;
V_73 -> V_723 = F_94 ( V_260 ) ;
V_723 = V_73 -> V_723 ;
if ( F_21 ( V_723 ) )
F_366 () ;
if ( ( V_723 & V_20 ) == V_693 &&
( V_723 & V_22 ) ) {
F_519 ( & V_73 -> V_8 ) ;
asm("int $2");
F_520 ( & V_73 -> V_8 ) ;
}
}
static void F_521 ( struct V_7 * V_8 )
{
T_2 V_723 = F_94 ( V_260 ) ;
if ( ( V_723 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_141 ;
T_16 * V_950 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
#ifdef F_96
unsigned long V_276 ;
#endif
V_4 = V_723 & V_21 ;
V_950 = ( T_16 * ) V_73 -> V_616 + V_4 ;
V_141 = F_522 ( * V_950 ) ;
asm volatile(
#ifdef F_96
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
#ifdef F_96
[sp]"=&r"(tmp)
#endif
:
[entry]"r"(entry),
[ss]"i"(__KERNEL_DS),
[cs]"i"(__KERNEL_CS)
);
} else
F_160 () ;
}
static bool F_205 ( void )
{
return ( V_29 . V_442 & V_323 ) &&
( V_29 . V_396 & V_330 ) ;
}
static void F_523 ( struct V_6 * V_73 )
{
T_2 V_723 ;
bool V_951 ;
T_6 V_4 ;
bool V_952 ;
V_952 = V_73 -> V_722 & V_726 ;
if ( F_52 () ) {
if ( V_73 -> V_691 )
return;
V_723 = F_94 ( V_260 ) ;
V_951 = ( V_723 & V_793 ) != 0 ;
V_4 = V_723 & V_21 ;
if ( ( V_723 & V_22 ) && V_951 &&
V_4 != V_706 && ! V_952 )
F_105 ( V_251 ,
V_694 ) ;
else
V_73 -> V_691 =
! ( F_94 ( V_251 )
& V_694 ) ;
} else if ( F_100 ( V_73 -> V_661 ) )
V_73 -> V_689 +=
F_524 ( F_525 ( F_526 () , V_73 -> V_953 ) ) ;
}
static void F_527 ( struct V_7 * V_8 ,
T_2 V_722 ,
int V_954 ,
int V_955 )
{
T_6 V_4 ;
int type ;
bool V_952 ;
V_952 = V_722 & V_726 ;
V_8 -> V_116 . V_781 = false ;
F_440 ( V_8 ) ;
F_439 ( V_8 ) ;
if ( ! V_952 )
return;
F_156 ( V_597 , V_8 ) ;
V_4 = V_722 & V_778 ;
type = V_722 & V_779 ;
switch ( type ) {
case V_693 :
V_8 -> V_116 . V_781 = true ;
F_356 ( V_8 , false ) ;
break;
case V_272 :
V_8 -> V_116 . V_268 = F_94 ( V_954 ) ;
case V_23 :
if ( V_722 & V_782 ) {
T_2 V_752 = F_94 ( V_955 ) ;
F_528 ( V_8 , V_4 , V_752 ) ;
} else
F_529 ( V_8 , V_4 ) ;
break;
case V_688 :
V_8 -> V_116 . V_268 = F_94 ( V_954 ) ;
case V_27 :
F_530 ( V_8 , V_4 , type == V_688 ) ;
break;
default:
break;
}
}
static void F_531 ( struct V_6 * V_73 )
{
F_527 ( & V_73 -> V_8 , V_73 -> V_722 ,
V_258 ,
V_783 ) ;
}
static void F_532 ( struct V_7 * V_8 )
{
F_527 ( V_8 ,
F_94 ( V_273 ) ,
V_271 ,
V_265 ) ;
F_102 ( V_273 , 0 ) ;
}
static void F_533 ( struct V_6 * V_73 )
{
int V_75 , V_956 ;
struct V_957 * V_958 ;
V_958 = F_534 ( & V_956 ) ;
if ( ! V_958 )
return;
for ( V_75 = 0 ; V_75 < V_956 ; V_75 ++ )
if ( V_958 [ V_75 ] . V_154 == V_958 [ V_75 ] . V_153 )
F_125 ( V_73 , V_958 [ V_75 ] . V_74 ) ;
else
F_127 ( V_73 , V_958 [ V_75 ] . V_74 , V_958 [ V_75 ] . V_153 ,
V_958 [ V_75 ] . V_154 ) ;
}
static void T_17 F_535 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_959 ;
if ( F_100 ( ! F_52 () && V_73 -> V_661 ) )
V_73 -> V_953 = F_526 () ;
if ( V_73 -> F_252 )
return;
if ( V_73 -> V_13 . V_846 ) {
F_492 ( V_73 ) ;
V_73 -> V_13 . V_846 = false ;
}
if ( F_170 ( V_404 , ( unsigned long * ) & V_8 -> V_116 . V_516 ) )
F_99 ( V_406 , V_8 -> V_116 . V_405 [ V_404 ] ) ;
if ( F_170 ( V_407 , ( unsigned long * ) & V_8 -> V_116 . V_516 ) )
F_99 ( V_408 , V_8 -> V_116 . V_405 [ V_407 ] ) ;
if ( V_8 -> V_132 & V_701 )
F_174 ( V_8 , 0 ) ;
F_533 ( V_73 ) ;
V_959 = F_536 () ;
V_73 -> V_960 = V_73 -> V_90 -> V_92 ;
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
#ifdef F_96
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
#ifdef F_96
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
#ifdef F_96
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
#ifdef F_96
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_959 )
F_537 ( V_959 ) ;
#ifndef F_96
F_147 ( V_202 , V_961 ) ;
F_147 ( V_204 , V_961 ) ;
#endif
V_8 -> V_116 . V_117 = ~ ( ( 1 << V_407 ) | ( 1 << V_404 )
| ( 1 << V_245 )
| ( 1 << V_487 )
| ( 1 << V_409 )
| ( 1 << V_118 )
| ( 1 << V_511 ) ) ;
V_8 -> V_116 . V_516 = 0 ;
V_73 -> V_722 = F_94 ( V_962 ) ;
V_73 -> V_90 -> V_92 = 1 ;
V_73 -> V_259 = F_94 ( V_963 ) ;
F_538 ( V_73 -> V_259 , V_8 , V_893 ) ;
if ( V_73 -> V_13 . V_696 )
F_156 ( V_597 , V_8 ) ;
V_73 -> V_13 . V_696 = 0 ;
F_518 ( V_73 ) ;
F_523 ( V_73 ) ;
F_531 ( V_73 ) ;
}
static void F_539 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_314 ( V_73 ) ;
F_242 ( V_73 -> V_90 ) ;
F_477 ( V_73 ) ;
F_463 ( V_73 -> V_78 ) ;
F_540 ( V_8 ) ;
F_541 ( V_964 , V_73 ) ;
}
static struct V_7 * F_542 ( struct V_17 * V_17 , unsigned int V_965 )
{
int V_752 ;
struct V_6 * V_73 = F_543 ( V_964 , V_448 ) ;
int V_91 ;
if ( ! V_73 )
return F_544 ( - V_456 ) ;
F_310 ( V_73 ) ;
V_752 = F_545 ( & V_73 -> V_8 , V_17 , V_965 ) ;
if ( V_752 )
goto V_966;
V_73 -> V_78 = F_462 ( V_438 , V_448 ) ;
V_752 = - V_456 ;
if ( ! V_73 -> V_78 ) {
goto V_967;
}
V_73 -> V_90 = & V_73 -> V_825 ;
V_73 -> V_90 -> V_87 = F_239 () ;
if ( ! V_73 -> V_90 -> V_87 )
goto V_968;
if ( ! V_221 )
F_155 ( F_68 ( F_82 ( V_220 , F_79 () ) ) ) ;
F_70 ( V_73 -> V_90 ) ;
if ( ! V_221 )
F_162 () ;
V_91 = F_546 () ;
F_154 ( & V_73 -> V_8 , V_91 ) ;
V_73 -> V_8 . V_91 = V_91 ;
V_752 = F_338 ( V_73 ) ;
F_161 ( & V_73 -> V_8 ) ;
F_547 () ;
if ( V_752 )
goto F_240;
if ( F_48 ( V_17 ) ) {
V_752 = F_305 ( V_17 ) ;
if ( V_752 )
goto F_240;
}
if ( V_101 ) {
if ( ! V_17 -> V_116 . V_537 )
V_17 -> V_116 . V_537 =
V_969 ;
V_752 = - V_456 ;
if ( F_309 ( V_17 ) != 0 )
goto F_240;
if ( ! F_302 ( V_17 ) )
goto F_240;
}
V_73 -> V_13 . V_818 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
return & V_73 -> V_8 ;
F_240:
F_242 ( V_73 -> V_90 ) ;
V_968:
F_463 ( V_73 -> V_78 ) ;
V_967:
F_540 ( & V_73 -> V_8 ) ;
V_966:
F_314 ( V_73 ) ;
F_541 ( V_964 , V_73 ) ;
return F_544 ( V_752 ) ;
}
static void T_11 F_548 ( void * V_970 )
{
struct V_29 V_425 ;
* ( int * ) V_970 = 0 ;
if ( F_233 ( & V_425 ) < 0 )
* ( int * ) V_970 = - V_424 ;
if ( memcmp ( & V_29 , & V_425 , sizeof( struct V_29 ) ) != 0 ) {
F_69 ( V_89 L_32 ,
F_549 () ) ;
* ( int * ) V_970 = - V_424 ;
}
}
static int F_550 ( void )
{
return V_531 + 1 ;
}
static T_3 F_551 ( struct V_7 * V_8 , T_13 V_971 , bool V_972 )
{
T_3 V_114 ;
if ( V_972 )
V_114 = V_973 << V_974 ;
else if ( F_552 ( V_8 -> V_17 ) )
V_114 = F_553 ( V_8 , V_971 ) <<
V_974 ;
else
V_114 = ( V_975 << V_974 )
| V_976 ;
return V_114 ;
}
static int F_554 ( void )
{
if ( V_101 && ! F_38 () )
return V_977 ;
else
return V_978 ;
}
static void F_555 ( struct V_7 * V_8 )
{
struct V_304 * V_305 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_625 ;
V_73 -> V_288 = false ;
if ( F_183 () ) {
V_625 = F_94 ( V_637 ) ;
if ( V_625 & V_60 ) {
V_305 = F_201 ( V_8 , 0x80000001 , 0 ) ;
if ( V_305 && ( V_305 -> V_979 & V_68 ( V_980 ) ) )
V_73 -> V_288 = true ;
else {
V_625 &= ~ V_60 ;
F_102 ( V_637 ,
V_625 ) ;
}
}
}
V_305 = F_201 ( V_8 , 0x7 , 0 ) ;
if ( F_184 () &&
V_305 && ( V_305 -> V_981 & V_68 ( V_982 ) ) &&
F_556 ( V_8 ) ) {
V_625 = F_94 ( V_637 ) ;
V_625 |= V_61 ;
F_102 ( V_637 ,
V_625 ) ;
} else {
if ( F_26 () ) {
V_625 = F_94 ( V_637 ) ;
V_625 &= ~ V_61 ;
F_102 ( V_637 ,
V_625 ) ;
}
if ( V_305 )
V_305 -> V_981 &= ~ V_68 ( V_982 ) ;
}
}
static void F_557 ( T_2 V_983 , struct V_304 * V_141 )
{
if ( V_983 == 1 && V_13 )
V_141 -> V_306 |= V_68 ( V_307 ) ;
}
static void F_558 ( struct V_7 * V_8 ,
struct V_857 * V_984 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_259 ;
if ( V_984 -> V_263 & V_727 )
V_259 = V_805 ;
else
V_259 = V_792 ;
F_179 ( V_8 , V_259 , 0 , V_8 -> V_116 . V_744 ) ;
V_12 -> V_985 = V_984 -> V_172 ;
}
static unsigned long F_501 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_986 ;
}
static void F_559 ( struct V_7 * V_8 )
{
F_560 ( V_8 , & V_8 -> V_116 . V_507 ,
V_353 & V_43 ) ;
V_8 -> V_116 . V_507 . V_987 = F_278 ;
V_8 -> V_116 . V_507 . V_988 = F_501 ;
V_8 -> V_116 . V_507 . V_989 = F_558 ;
V_8 -> V_116 . V_515 = & V_8 -> V_116 . V_990 ;
}
static void F_561 ( struct V_7 * V_8 )
{
V_8 -> V_116 . V_515 = & V_8 -> V_116 . V_507 ;
}
static void F_562 ( struct V_7 * V_8 ,
struct V_857 * V_984 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_445 ( ! F_123 ( V_8 ) ) ;
if ( V_12 -> V_139 & ( 1u << V_24 ) )
F_179 ( V_8 , F_6 ( V_8 ) -> V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
else
F_482 ( V_8 , V_984 ) ;
}
static void F_563 ( struct V_7 * V_8 )
{
T_3 V_991 = F_9 ( V_8 ) -> V_992 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( V_8 -> V_116 . V_993 == 0 )
return;
if ( V_991 <= 1 ) {
F_469 ( & V_73 -> V_13 . V_836 ) ;
return;
}
V_991 <<= V_358 ;
V_991 *= 1000000 ;
F_564 ( V_991 , V_8 -> V_116 . V_993 ) ;
F_565 ( & V_73 -> V_13 . V_836 ,
F_566 ( V_991 ) , V_844 ) ;
}
static void F_567 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_625 ;
F_101 ( V_994 , V_12 -> V_995 ) ;
F_101 ( V_665 , V_12 -> V_996 ) ;
F_101 ( V_997 , V_12 -> V_998 ) ;
F_101 ( V_999 , V_12 -> V_1000 ) ;
F_101 ( V_1001 , V_12 -> V_1002 ) ;
F_101 ( V_1003 , V_12 -> V_1004 ) ;
F_101 ( V_668 , V_12 -> V_1005 ) ;
F_101 ( V_667 , V_12 -> V_1006 ) ;
F_102 ( V_1007 , V_12 -> V_1008 ) ;
F_102 ( V_1009 , V_12 -> V_1010 ) ;
F_102 ( V_1011 , V_12 -> V_1012 ) ;
F_102 ( V_1013 , V_12 -> V_1014 ) ;
F_102 ( V_1015 , V_12 -> V_1016 ) ;
F_102 ( V_1017 , V_12 -> V_1018 ) ;
F_102 ( V_670 , V_12 -> V_1019 ) ;
F_102 ( V_500 , V_12 -> V_1020 ) ;
F_102 ( V_551 , V_12 -> V_1021 ) ;
F_102 ( V_549 , V_12 -> V_1022 ) ;
F_102 ( V_1023 , V_12 -> V_1024 ) ;
F_102 ( V_1025 , V_12 -> V_1026 ) ;
F_102 ( V_1027 , V_12 -> V_1028 ) ;
F_102 ( V_1029 , V_12 -> V_1030 ) ;
F_102 ( V_1031 , V_12 -> V_1032 ) ;
F_102 ( V_1033 , V_12 -> V_1034 ) ;
F_102 ( V_671 , V_12 -> V_1035 ) ;
F_102 ( V_502 , V_12 -> V_1036 ) ;
F_99 ( V_1037 , V_12 -> V_1038 ) ;
F_99 ( V_666 , V_12 -> V_1039 ) ;
F_99 ( V_1040 , V_12 -> V_1041 ) ;
F_99 ( V_1042 , V_12 -> V_1043 ) ;
F_99 ( V_381 , V_12 -> V_1044 ) ;
F_99 ( V_382 , V_12 -> V_1045 ) ;
F_99 ( V_669 , V_12 -> V_1046 ) ;
F_99 ( V_499 , V_12 -> V_1047 ) ;
F_99 ( V_552 , V_12 -> V_1048 ) ;
F_99 ( V_550 , V_12 -> V_1049 ) ;
F_103 ( V_675 , V_12 -> V_1050 ) ;
F_102 ( V_273 ,
V_12 -> V_1051 ) ;
F_102 ( V_265 ,
V_12 -> V_1052 ) ;
F_102 ( V_271 ,
V_12 -> V_1053 ) ;
F_102 ( V_251 ,
V_12 -> V_1054 ) ;
F_102 ( V_385 , V_12 -> V_1055 ) ;
F_401 ( V_8 , 7 , V_12 -> V_1056 ) ;
F_172 ( V_8 , V_12 -> V_1057 ) ;
F_99 ( V_674 ,
V_12 -> V_1058 ) ;
F_99 ( V_388 , V_12 -> V_1059 ) ;
F_99 ( V_387 , V_12 -> V_1060 ) ;
F_103 ( V_635 , - 1ull ) ;
V_625 = V_12 -> V_71 ;
V_625 |= V_29 . V_39 ;
V_625 &= ~ ( V_72 |
V_40 ) ;
F_102 ( V_636 , V_625 ) ;
V_73 -> V_13 . V_837 = false ;
if ( F_60 ( V_12 ) )
F_563 ( V_8 ) ;
F_102 ( V_648 ,
V_101 ? V_12 -> V_1061 : 0 ) ;
F_102 ( V_649 ,
V_101 ? V_12 -> V_1062 : 0 ) ;
if ( F_26 () ) {
V_625 = F_335 ( V_73 ) ;
if ( ! V_73 -> V_288 )
V_625 &= ~ V_60 ;
V_625 &= ~ ( V_35 |
V_38 |
V_37 ) ;
if ( F_57 ( V_12 ,
V_33 ) )
V_625 |= V_12 -> V_70 ;
if ( V_625 & V_35 ) {
if ( V_73 -> V_13 . V_583 )
F_13 ( V_73 -> V_13 . V_583 ) ;
V_73 -> V_13 . V_583 =
F_10 ( V_8 , V_12 -> V_1063 ) ;
if ( ! V_73 -> V_13 . V_583 )
V_625 &=
~ V_35 ;
else
F_103 ( V_678 ,
F_346 ( V_73 -> V_13 . V_583 ) ) ;
} else if ( F_48 ( V_73 -> V_8 . V_17 ) ) {
V_625 |=
V_35 ;
F_103 ( V_678 ,
F_346 ( V_8 -> V_17 -> V_116 . V_583 ) ) ;
}
F_102 ( V_637 , V_625 ) ;
}
F_328 ( V_73 ) ;
V_73 -> V_1064 = 0 ;
V_625 = F_334 ( V_73 ) ;
V_625 &= ~ V_334 ;
V_625 &= ~ V_335 ;
V_625 &= ~ V_32 ;
V_625 |= V_12 -> V_69 ;
V_625 &= ~ V_31 ;
V_625 &= ~ V_345 ;
V_625 |= V_344 ;
F_102 ( V_524 , V_625 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 &= ~ V_12 -> V_234 ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
F_102 ( V_109 , V_29 . V_442 ) ;
F_106 ( V_73 ,
( V_12 -> V_1065 & ~ V_146 &
~ V_328 ) |
( V_29 . V_396 & ~ V_328 ) ) ;
if ( V_12 -> V_1065 & V_329 ) {
F_103 ( V_397 , V_12 -> V_1066 ) ;
V_8 -> V_116 . V_398 = V_12 -> V_1066 ;
} else if ( V_29 . V_396 & V_329 )
F_103 ( V_397 , V_73 -> V_8 . V_116 . V_398 ) ;
F_332 ( V_73 ) ;
if ( V_12 -> V_1065 & V_330 )
F_103 ( V_389 , V_12 -> V_1067 ) ;
if ( V_12 -> V_69 & V_300 )
F_103 ( V_292 ,
V_73 -> V_13 . V_293 + V_12 -> V_291 ) ;
else
F_103 ( V_292 , V_73 -> V_13 . V_293 ) ;
if ( V_458 ) {
F_101 ( V_679 , V_73 -> V_52 ) ;
F_266 ( V_8 ) ;
}
if ( F_61 ( V_12 ) ) {
F_568 ( V_8 ) ;
F_559 ( V_8 ) ;
}
if ( V_12 -> V_1065 & V_146 )
V_8 -> V_116 . V_177 = V_12 -> V_1068 ;
else if ( V_12 -> V_1065 & V_328 )
V_8 -> V_116 . V_177 |= ( V_180 | V_181 ) ;
else
V_8 -> V_116 . V_177 &= ~ ( V_180 | V_181 ) ;
F_262 ( V_8 , V_8 -> V_116 . V_177 ) ;
F_277 ( V_8 , V_12 -> V_237 ) ;
F_99 ( V_242 , F_165 ( V_12 ) ) ;
F_275 ( V_8 , V_12 -> V_239 ) ;
F_99 ( V_486 , F_166 ( V_12 ) ) ;
F_391 ( V_8 , V_12 -> V_535 ) ;
F_261 ( V_8 ) ;
if ( ! V_101 )
V_8 -> V_116 . V_515 -> V_989 = F_562 ;
if ( V_101 ) {
F_103 ( V_517 , V_12 -> V_1069 ) ;
F_103 ( V_519 , V_12 -> V_1070 ) ;
F_103 ( V_520 , V_12 -> V_1071 ) ;
F_103 ( V_521 , V_12 -> V_1072 ) ;
}
F_393 ( V_8 , V_404 , V_12 -> V_1073 ) ;
F_393 ( V_8 , V_407 , V_12 -> V_1074 ) ;
}
static int F_486 ( struct V_7 * V_8 , bool V_1075 )
{
struct V_12 * V_12 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_91 ;
struct V_90 * V_821 ;
bool V_1076 ;
if ( ! F_473 ( V_8 ) ||
! F_494 ( V_8 ) )
return 1 ;
F_175 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_459 )
F_475 ( V_73 ) ;
if ( V_12 -> V_862 == V_1075 ) {
F_468 ( V_8 ,
V_1075 ? V_1077
: V_1078 ) ;
return 1 ;
}
if ( V_12 -> V_1079 != V_673 &&
V_12 -> V_1079 != V_1080 ) {
F_468 ( V_8 , V_1081 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_483 ( V_12 -> V_277 , V_438 ) ) {
F_468 ( V_8 , V_1081 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_483 ( V_12 -> V_1063 , V_438 ) ) {
F_468 ( V_8 , V_1081 ) ;
return 1 ;
}
if ( V_12 -> V_1082 > 0 ||
V_12 -> V_1083 > 0 ||
V_12 -> V_1084 > 0 ) {
F_569 ( L_33 ,
V_506 ) ;
F_468 ( V_8 , V_1081 ) ;
return 1 ;
}
if ( ! F_206 ( V_12 -> V_69 ,
V_332 , V_333 ) ||
! F_206 ( V_12 -> V_70 ,
V_351 , V_352 ) ||
! F_206 ( V_12 -> V_71 ,
V_309 , V_310 ) ||
! F_206 ( V_12 -> V_1085 ,
V_315 , V_316 ) ||
! F_206 ( V_12 -> V_1065 ,
V_325 , V_326 ) )
{
F_468 ( V_8 , V_1081 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1086 & F_209 ) != F_209 ) ||
( ( V_12 -> V_1087 & F_210 ) != F_210 ) ) {
F_468 ( V_8 ,
V_1088 ) ;
return 1 ;
}
if ( ! F_381 ( V_12 , V_12 -> V_237 ) ||
( ( V_12 -> V_239 & F_210 ) != F_210 ) ) {
F_570 ( V_8 , V_12 ,
V_922 , V_1089 ) ;
return 1 ;
}
if ( V_12 -> V_1090 != - 1ull ) {
F_570 ( V_8 , V_12 ,
V_922 , V_1091 ) ;
return 1 ;
}
if ( V_12 -> V_1065 & V_146 ) {
V_1076 = ( V_12 -> V_1065 & V_328 ) != 0 ;
if ( ! F_571 ( V_8 , V_12 -> V_1068 ) ||
V_1076 != ! ! ( V_12 -> V_1068 & V_180 ) ||
( ( V_12 -> V_237 & V_523 ) &&
V_1076 != ! ! ( V_12 -> V_1068 & V_181 ) ) ) {
F_570 ( V_8 , V_12 ,
V_922 , V_1089 ) ;
return 1 ;
}
}
if ( V_12 -> V_1085 & V_147 ) {
V_1076 = ( V_12 -> V_1085 &
V_318 ) != 0 ;
if ( ! F_571 ( V_8 , V_12 -> V_1092 ) ||
V_1076 != ! ! ( V_12 -> V_1092 & V_180 ) ||
V_1076 != ! ! ( V_12 -> V_1092 & V_181 ) ) {
F_570 ( V_8 , V_12 ,
V_922 , V_1089 ) ;
return 1 ;
}
}
V_821 = F_458 ( V_73 ) ;
if ( ! V_821 )
return - V_456 ;
F_572 ( V_8 ) ;
V_73 -> V_13 . V_293 = F_95 ( V_292 ) ;
V_91 = F_546 () ;
V_73 -> V_90 = V_821 ;
F_161 ( V_8 ) ;
F_154 ( V_8 , V_91 ) ;
V_8 -> V_91 = V_91 ;
F_547 () ;
F_116 ( V_73 ) ;
V_12 -> V_862 = 1 ;
F_567 ( V_8 , V_12 ) ;
if ( V_12 -> V_1079 == V_1080 )
return F_364 ( V_8 ) ;
V_73 -> V_13 . V_696 = 1 ;
return 1 ;
}
static inline unsigned long
F_573 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_92 ( V_230 ) & V_8 -> V_116 . V_233 ) |
( V_12 -> V_237 & V_12 -> V_234 ) |
( F_92 ( V_242 ) & ~ ( V_12 -> V_234 |
V_8 -> V_116 . V_233 ) ) ;
}
static inline unsigned long
F_574 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_92 ( V_484 ) & V_8 -> V_116 . V_512 ) |
( V_12 -> V_239 & V_12 -> V_240 ) |
( F_92 ( V_486 ) & ~ ( V_12 -> V_240 |
V_8 -> V_116 . V_512 ) ) ;
}
static void F_575 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1093 ;
unsigned int V_152 ;
if ( V_8 -> V_116 . V_739 . V_1094 && V_8 -> V_116 . V_739 . V_264 ) {
V_152 = V_8 -> V_116 . V_739 . V_152 ;
V_1093 = V_152 | V_726 ;
if ( F_181 ( V_152 ) ) {
V_12 -> V_1095 =
V_8 -> V_116 . V_268 ;
V_1093 |= V_272 ;
} else
V_1093 |= V_23 ;
if ( V_8 -> V_116 . V_739 . V_262 ) {
V_1093 |= V_782 ;
V_12 -> V_1096 =
V_8 -> V_116 . V_739 . V_263 ;
}
V_12 -> V_1097 = V_1093 ;
} else if ( V_8 -> V_116 . V_781 ) {
V_12 -> V_1097 =
V_693 | V_22 | V_692 ;
} else if ( V_8 -> V_116 . V_685 . V_1094 ) {
V_152 = V_8 -> V_116 . V_685 . V_152 ;
V_1093 = V_152 | V_726 ;
if ( V_8 -> V_116 . V_685 . V_687 ) {
V_1093 |= V_688 ;
V_12 -> V_1053 =
V_8 -> V_116 . V_268 ;
} else
V_1093 |= V_27 ;
V_12 -> V_1097 = V_1093 ;
}
}
static int F_576 ( struct V_7 * V_8 , bool V_1098 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_60 ( F_9 ( V_8 ) ) &&
V_73 -> V_13 . V_837 ) {
if ( V_73 -> V_13 . V_696 )
return - V_416 ;
F_179 ( V_8 , V_1099 , 0 , 0 ) ;
return 0 ;
}
if ( V_8 -> V_116 . V_939 && F_349 ( V_8 ) ) {
if ( V_73 -> V_13 . V_696 ||
V_8 -> V_116 . V_685 . V_1094 )
return - V_416 ;
F_179 ( V_8 , V_895 ,
V_692 | V_693 |
V_22 , 0 ) ;
V_8 -> V_116 . V_939 = 0 ;
F_356 ( V_8 , true ) ;
return 0 ;
}
if ( ( F_418 ( V_8 ) || V_1098 ) &&
F_348 ( V_8 ) ) {
if ( V_73 -> V_13 . V_696 )
return - V_416 ;
F_179 ( V_8 , V_896 , 0 , 0 ) ;
}
return 0 ;
}
static T_2 F_577 ( struct V_7 * V_8 )
{
T_18 V_1100 =
F_578 ( & F_6 ( V_8 ) -> V_13 . V_836 ) ;
T_3 V_103 ;
if ( F_524 ( V_1100 ) <= 0 )
return 0 ;
V_103 = F_524 ( V_1100 ) * V_8 -> V_116 . V_993 ;
F_564 ( V_103 , 1000000 ) ;
return V_103 >> V_358 ;
}
static void F_579 ( struct V_7 * V_8 , struct V_12 * V_12 ,
T_2 V_259 , T_2 V_723 ,
unsigned long V_744 )
{
V_12 -> V_237 = F_573 ( V_8 , V_12 ) ;
V_12 -> V_239 = F_574 ( V_8 , V_12 ) ;
F_400 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1056 ) ;
V_12 -> V_1073 = F_388 ( V_8 , V_404 ) ;
V_12 -> V_1074 = F_388 ( V_8 , V_407 ) ;
V_12 -> V_1057 = F_92 ( V_246 ) ;
V_12 -> V_995 = F_93 ( V_994 ) ;
V_12 -> V_996 = F_93 ( V_665 ) ;
V_12 -> V_998 = F_93 ( V_997 ) ;
V_12 -> V_1000 = F_93 ( V_999 ) ;
V_12 -> V_1002 = F_93 ( V_1001 ) ;
V_12 -> V_1004 = F_93 ( V_1003 ) ;
V_12 -> V_1005 = F_93 ( V_668 ) ;
V_12 -> V_1006 = F_93 ( V_667 ) ;
V_12 -> V_1008 = F_94 ( V_1007 ) ;
V_12 -> V_1010 = F_94 ( V_1009 ) ;
V_12 -> V_1012 = F_94 ( V_1011 ) ;
V_12 -> V_1014 = F_94 ( V_1013 ) ;
V_12 -> V_1016 = F_94 ( V_1015 ) ;
V_12 -> V_1018 = F_94 ( V_1017 ) ;
V_12 -> V_1019 = F_94 ( V_670 ) ;
V_12 -> V_1020 = F_94 ( V_500 ) ;
V_12 -> V_1021 = F_94 ( V_551 ) ;
V_12 -> V_1022 = F_94 ( V_549 ) ;
V_12 -> V_1024 = F_94 ( V_1023 ) ;
V_12 -> V_1026 = F_94 ( V_1025 ) ;
V_12 -> V_1028 = F_94 ( V_1027 ) ;
V_12 -> V_1030 = F_94 ( V_1029 ) ;
V_12 -> V_1032 = F_94 ( V_1031 ) ;
V_12 -> V_1034 = F_94 ( V_1033 ) ;
V_12 -> V_1035 = F_94 ( V_671 ) ;
V_12 -> V_1036 = F_94 ( V_502 ) ;
V_12 -> V_1038 = F_92 ( V_1037 ) ;
V_12 -> V_1039 = F_92 ( V_666 ) ;
V_12 -> V_1041 = F_92 ( V_1040 ) ;
V_12 -> V_1043 = F_92 ( V_1042 ) ;
V_12 -> V_1044 = F_92 ( V_381 ) ;
V_12 -> V_1045 = F_92 ( V_382 ) ;
V_12 -> V_1046 = F_92 ( V_669 ) ;
V_12 -> V_1047 = F_92 ( V_499 ) ;
V_12 -> V_1048 = F_92 ( V_552 ) ;
V_12 -> V_1049 = F_92 ( V_550 ) ;
V_12 -> V_1054 =
F_94 ( V_251 ) ;
V_12 -> V_1058 =
F_92 ( V_674 ) ;
if ( V_8 -> V_116 . V_1101 == V_1102 )
V_12 -> V_1079 = V_1080 ;
else
V_12 -> V_1079 = V_673 ;
if ( F_60 ( V_12 ) ) {
if ( V_12 -> V_1085 &
V_322 )
V_12 -> V_992 =
F_577 ( V_8 ) ;
F_580 ( & F_6 ( V_8 ) -> V_13 . V_836 ) ;
}
if ( V_101 ) {
V_12 -> V_535 = F_95 ( V_510 ) ;
V_12 -> V_1069 = F_95 ( V_517 ) ;
V_12 -> V_1070 = F_95 ( V_519 ) ;
V_12 -> V_1071 = F_95 ( V_520 ) ;
V_12 -> V_1072 = F_95 ( V_521 ) ;
}
V_12 -> V_1065 =
( V_12 -> V_1065 & ~ V_328 ) |
( F_108 ( F_6 ( V_8 ) ) & V_328 ) ;
V_12 -> V_1050 = F_95 ( V_675 ) ;
if ( V_12 -> V_1085 & V_320 )
V_12 -> V_1066 = F_95 ( V_397 ) ;
if ( V_12 -> V_1085 & V_321 )
V_12 -> V_1068 = V_8 -> V_116 . V_177 ;
V_12 -> V_1055 = F_94 ( V_385 ) ;
V_12 -> V_1059 = F_92 ( V_388 ) ;
V_12 -> V_1060 = F_92 ( V_387 ) ;
if ( F_205 () )
V_12 -> V_1067 = F_95 ( V_389 ) ;
V_12 -> V_1103 = V_259 ;
V_12 -> V_744 = V_744 ;
V_12 -> V_1104 = V_723 ;
if ( ( V_12 -> V_1104 &
( V_22 | V_266 ) ) ==
( V_22 | V_266 ) )
V_12 -> V_1105 =
F_94 ( V_725 ) ;
V_12 -> V_1097 = 0 ;
V_12 -> V_1095 = F_94 ( V_258 ) ;
V_12 -> V_848 = F_94 ( V_859 ) ;
if ( ! ( V_12 -> V_1103 & V_934 ) ) {
V_12 -> V_1051 &= ~ V_22 ;
F_575 ( V_8 , V_12 ) ;
}
V_8 -> V_116 . V_781 = false ;
F_440 ( V_8 ) ;
F_439 ( V_8 ) ;
}
static void F_581 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_471 V_113 ;
if ( V_12 -> V_1085 & V_147 )
V_8 -> V_116 . V_177 = V_12 -> V_1092 ;
else if ( V_12 -> V_1085 & V_318 )
V_8 -> V_116 . V_177 |= ( V_180 | V_181 ) ;
else
V_8 -> V_116 . V_177 &= ~ ( V_180 | V_181 ) ;
F_262 ( V_8 , V_8 -> V_116 . V_177 ) ;
F_393 ( V_8 , V_404 , V_12 -> V_1064 ) ;
F_393 ( V_8 , V_407 , V_12 -> V_1106 ) ;
F_172 ( V_8 , V_1107 ) ;
F_277 ( V_8 , V_12 -> V_1086 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 = ( V_8 -> V_138 ? V_231 : 0 ) ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
V_8 -> V_116 . V_512 = ~ F_92 ( V_624 ) ;
F_385 ( V_8 , V_12 -> V_1087 ) ;
F_561 ( V_8 ) ;
F_391 ( V_8 , V_12 -> V_1108 ) ;
F_261 ( V_8 ) ;
if ( ! V_101 )
V_8 -> V_116 . V_515 -> V_989 = F_482 ;
if ( V_458 ) {
F_266 ( V_8 ) ;
}
F_102 ( V_385 , V_12 -> V_1109 ) ;
F_99 ( V_388 , V_12 -> V_1110 ) ;
F_99 ( V_387 , V_12 -> V_1111 ) ;
F_99 ( V_550 , V_12 -> V_1112 ) ;
F_99 ( V_552 , V_12 -> V_1113 ) ;
if ( V_12 -> V_1085 & V_323 )
F_103 ( V_389 , 0 ) ;
if ( V_12 -> V_1085 & V_319 ) {
F_103 ( V_397 , V_12 -> V_1114 ) ;
V_8 -> V_116 . V_398 = V_12 -> V_1114 ;
}
if ( V_12 -> V_1085 & V_151 )
F_103 ( V_163 ,
V_12 -> V_1115 ) ;
V_113 = (struct V_471 ) {
. V_123 = 0 ,
. V_125 = 0xFFFFFFFF ,
. V_120 = V_12 -> V_1116 ,
. type = 11 ,
. V_494 = 1 ,
. V_187 = 1 ,
. V_492 = 1
} ;
if ( V_12 -> V_1085 & V_318 )
V_113 . V_495 = 1 ;
else
V_113 . V_493 = 1 ;
F_255 ( V_8 , & V_113 , V_473 ) ;
V_113 = (struct V_471 ) {
. V_123 = 0 ,
. V_125 = 0xFFFFFFFF ,
. type = 3 ,
. V_494 = 1 ,
. V_187 = 1 ,
. V_493 = 1 ,
. V_492 = 1
} ;
V_113 . V_120 = V_12 -> V_1117 ;
F_255 ( V_8 , & V_113 , V_480 ) ;
V_113 . V_120 = V_12 -> V_1118 ;
F_255 ( V_8 , & V_113 , V_479 ) ;
V_113 . V_120 = V_12 -> V_1119 ;
F_255 ( V_8 , & V_113 , V_474 ) ;
V_113 . V_120 = V_12 -> V_1120 ;
V_113 . V_123 = V_12 -> V_1121 ;
F_255 ( V_8 , & V_113 , V_481 ) ;
V_113 . V_120 = V_12 -> V_1122 ;
V_113 . V_123 = V_12 -> V_1123 ;
F_255 ( V_8 , & V_113 , V_482 ) ;
V_113 = (struct V_471 ) {
. V_123 = V_12 -> V_1124 ,
. V_125 = 0x67 ,
. V_120 = V_12 -> V_1125 ,
. type = 11 ,
. V_494 = 1
} ;
F_255 ( V_8 , & V_113 , V_483 ) ;
F_401 ( V_8 , 7 , 0x400 ) ;
F_103 ( V_675 , 0 ) ;
}
static void F_179 ( struct V_7 * V_8 , T_2 V_259 ,
T_2 V_723 ,
unsigned long V_744 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_91 ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_582 ( V_73 -> V_13 . V_696 ) ;
F_583 ( V_8 ) ;
F_579 ( V_8 , V_12 , V_259 , V_723 ,
V_744 ) ;
F_584 ( V_12 -> V_1103 ,
V_12 -> V_744 ,
V_12 -> V_1097 ,
V_12 -> V_1104 ,
V_12 -> V_1105 ,
V_893 ) ;
V_91 = F_546 () ;
V_73 -> V_90 = & V_73 -> V_825 ;
F_161 ( V_8 ) ;
F_154 ( V_8 , V_91 ) ;
V_8 -> V_91 = V_91 ;
F_547 () ;
F_106 ( V_73 , F_94 ( V_107 ) ) ;
F_111 ( V_73 , F_94 ( V_109 ) ) ;
F_116 ( V_73 ) ;
if ( V_823 == 0 )
F_464 ( V_73 , V_73 -> V_13 . V_818 ) ;
F_581 ( V_8 , V_12 ) ;
F_103 ( V_292 , V_73 -> V_13 . V_293 ) ;
V_73 -> V_1064 = 0 ;
if ( V_73 -> V_13 . V_583 ) {
F_13 ( V_73 -> V_13 . V_583 ) ;
V_73 -> V_13 . V_583 = 0 ;
}
if ( F_100 ( V_73 -> V_894 ) ) {
V_73 -> V_894 = 0 ;
F_468 ( V_8 , F_94 ( V_104 ) ) ;
} else
F_466 ( V_8 ) ;
if ( V_459 )
V_73 -> V_13 . V_846 = true ;
V_8 -> V_116 . V_1101 = V_1126 ;
}
static void F_216 ( struct V_7 * V_8 )
{
if ( F_123 ( V_8 ) )
F_179 ( V_8 , - 1 , 0 , 0 ) ;
F_477 ( F_6 ( V_8 ) ) ;
}
static void F_570 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_775 , unsigned long V_1127 )
{
F_581 ( V_8 , V_12 ) ;
V_12 -> V_1103 = V_775 | V_934 ;
V_12 -> V_744 = V_1127 ;
F_466 ( V_8 ) ;
if ( V_459 )
F_6 ( V_8 ) -> V_13 . V_846 = true ;
}
static int F_585 ( struct V_7 * V_8 ,
struct V_1128 * V_1129 ,
enum V_1130 V_1131 )
{
return V_1132 ;
}
static int T_11 F_586 ( void )
{
int V_564 , V_75 , V_74 ;
F_587 ( V_144 , & V_182 ) ;
for ( V_75 = 0 ; V_75 < V_657 ; ++ V_75 )
F_588 ( V_75 , V_77 [ V_75 ] ) ;
V_630 = ( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_630 )
return - V_456 ;
V_564 = - V_456 ;
V_632 = ( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_632 )
goto V_547;
V_282 = ( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_282 )
goto V_1133;
V_280 =
( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_280 )
goto V_1134;
V_281 = ( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_281 )
goto V_1135;
V_279 =
( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_279 )
goto V_1136;
V_453 = ( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_453 )
goto V_1137;
V_452 = ( unsigned long * ) F_589 ( V_448 ) ;
if ( ! V_452 )
goto V_1138;
memset ( V_453 , 0xff , V_438 ) ;
memset ( V_452 , 0xff , V_438 ) ;
memset ( V_630 , 0xff , V_438 ) ;
F_246 ( 0x80 , V_630 ) ;
memset ( V_632 , 0xff , V_438 ) ;
memset ( V_282 , 0xff , V_438 ) ;
memset ( V_281 , 0xff , V_438 ) ;
F_590 ( 0 , V_591 ) ;
V_564 = F_591 ( & V_1139 , sizeof( struct V_6 ) ,
F_592 ( struct V_6 ) , V_1140 ) ;
if ( V_564 )
goto V_1141;
#ifdef F_593
F_594 ( V_1142 ,
F_78 ) ;
#endif
F_317 ( V_207 , false ) ;
F_317 ( V_209 , false ) ;
F_317 ( V_210 , true ) ;
F_317 ( V_384 , false ) ;
F_317 ( V_227 , false ) ;
F_317 ( V_386 , false ) ;
F_317 ( V_214 , true ) ;
memcpy ( V_280 ,
V_282 , V_438 ) ;
memcpy ( V_279 ,
V_281 , V_438 ) ;
if ( V_465 ) {
for ( V_74 = 0x800 ; V_74 <= 0x8ff ; V_74 ++ )
F_319 ( V_74 ) ;
F_318 ( 0x802 ) ;
F_318 ( 0x839 ) ;
F_320 ( 0x808 ) ;
F_320 ( 0x80b ) ;
F_320 ( 0x83f ) ;
}
if ( V_101 ) {
F_595 ( 0ull ,
( V_461 ) ? V_1143 : 0ull ,
( V_461 ) ? V_1144 : 0ull ,
0ull , V_1145 ) ;
F_336 () ;
F_596 () ;
} else
F_597 () ;
return 0 ;
V_1141:
F_598 ( ( unsigned long ) V_452 ) ;
V_1138:
F_598 ( ( unsigned long ) V_453 ) ;
V_1137:
F_598 ( ( unsigned long ) V_279 ) ;
V_1136:
F_598 ( ( unsigned long ) V_281 ) ;
V_1135:
F_598 ( ( unsigned long ) V_280 ) ;
V_1134:
F_598 ( ( unsigned long ) V_282 ) ;
V_1133:
F_598 ( ( unsigned long ) V_632 ) ;
V_547:
F_598 ( ( unsigned long ) V_630 ) ;
return V_564 ;
}
static void T_12 F_599 ( void )
{
F_598 ( ( unsigned long ) V_280 ) ;
F_598 ( ( unsigned long ) V_279 ) ;
F_598 ( ( unsigned long ) V_282 ) ;
F_598 ( ( unsigned long ) V_281 ) ;
F_598 ( ( unsigned long ) V_632 ) ;
F_598 ( ( unsigned long ) V_630 ) ;
F_598 ( ( unsigned long ) V_452 ) ;
F_598 ( ( unsigned long ) V_453 ) ;
#ifdef F_593
F_594 ( V_1142 , NULL ) ;
F_600 () ;
#endif
F_601 () ;
}
