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
static T_2 F_173 ( struct V_7 * V_8 )
{
T_2 V_250 = F_94 ( V_251 ) ;
int V_114 = 0 ;
if ( V_250 & V_252 )
V_114 |= V_253 ;
if ( V_250 & V_254 )
V_114 |= V_255 ;
return V_114 ;
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
V_322 | V_323 ;
if ( F_205 () )
V_316 |= V_324 ;
V_325 = V_315 &
~ V_326 ;
F_204 ( V_327 ,
V_328 , V_329 ) ;
V_328 = V_330 ;
V_329 &=
#ifdef F_96
V_331 |
#endif
V_332 ;
V_329 |= ( V_330 |
V_146 ) ;
if ( F_205 () )
V_329 |= V_333 ;
V_334 = V_328 &
~ V_335 ;
F_204 ( V_336 ,
V_337 , V_338 ) ;
V_337 = V_339 ;
V_338 &=
V_340 |
V_341 | V_300 |
V_342 | V_343 |
V_344 | V_345 |
V_346 |
#ifdef F_96
V_347 | V_348 |
#endif
V_349 | V_350 |
V_351 | V_352 |
V_353 | V_354 |
V_355 |
V_33 ;
V_338 |= V_339 |
V_31 ;
V_356 = V_337 &
~ ( V_345 | V_346 ) ;
F_204 ( V_357 ,
V_358 , V_359 ) ;
V_358 = 0 ;
V_359 &=
V_35 |
V_56 |
V_63 ;
if ( V_101 ) {
V_359 |= V_55 ;
V_360 = V_48 |
V_45 | V_46 |
V_361 ;
V_360 &= V_41 . V_42 ;
V_360 |= V_51 ;
} else
V_360 = 0 ;
F_204 ( V_65 , V_362 , V_363 ) ;
V_362 &= V_364 ;
V_362 |= V_365 |
V_366 ;
V_363 = 0 ;
}
static inline bool F_206 ( T_2 V_3 , T_2 V_367 , T_2 V_368 )
{
return ( ( V_3 & V_368 ) | V_367 ) == V_3 ;
}
static inline T_3 F_207 ( T_2 V_367 , T_2 V_368 )
{
return V_367 | ( ( T_3 ) V_368 << 32 ) ;
}
static int F_208 ( struct V_7 * V_8 , T_2 V_369 , T_3 * V_370 )
{
switch ( V_369 ) {
case V_371 :
* V_370 = V_372 | V_373 |
( ( T_3 ) V_374 << V_375 ) |
( V_376 << V_377 ) ;
break;
case V_378 :
case V_308 :
* V_370 = F_207 ( V_309 ,
V_310 ) ;
break;
case V_379 :
* V_370 = F_207 ( V_356 ,
V_338 ) ;
break;
case V_336 :
* V_370 = F_207 ( V_337 ,
V_338 ) ;
break;
case V_380 :
* V_370 = F_207 ( V_325 ,
V_316 ) ;
break;
case V_314 :
* V_370 = F_207 ( V_315 ,
V_316 ) ;
break;
case V_381 :
* V_370 = F_207 ( V_334 ,
V_329 ) ;
break;
case V_327 :
* V_370 = F_207 ( V_328 ,
V_329 ) ;
break;
case V_65 :
* V_370 = F_207 ( V_362 ,
V_363 ) ;
break;
#define F_209 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_210 X86_CR4_VMXE
case V_382 :
* V_370 = F_209 ;
break;
case V_383 :
* V_370 = - 1ULL ;
break;
case V_384 :
* V_370 = F_210 ;
break;
case V_385 :
* V_370 = - 1ULL ;
break;
case V_386 :
* V_370 = 0x2e ;
break;
case V_357 :
* V_370 = F_207 ( V_358 ,
V_359 ) ;
break;
case V_387 :
* V_370 = V_360 ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_211 ( struct V_7 * V_8 , T_2 V_369 , T_3 * V_370 )
{
T_3 V_183 ;
struct V_86 * V_74 ;
if ( ! V_370 ) {
F_69 ( V_89 L_7 ) ;
return - V_388 ;
}
switch ( V_369 ) {
#ifdef F_96
case V_207 :
V_183 = F_92 ( V_389 ) ;
break;
case V_209 :
V_183 = F_92 ( V_390 ) ;
break;
case V_210 :
F_151 ( F_6 ( V_8 ) ) ;
V_183 = F_6 ( V_8 ) -> V_212 ;
break;
#endif
case V_144 :
return F_212 ( V_8 , V_369 , V_370 ) ;
case V_391 :
V_183 = F_189 () ;
break;
case V_392 :
V_183 = F_94 ( V_393 ) ;
break;
case V_394 :
V_183 = F_92 ( V_395 ) ;
break;
case V_227 :
V_183 = F_92 ( V_396 ) ;
break;
case V_214 :
if ( ! F_205 () )
return 1 ;
V_183 = F_95 ( V_397 ) ;
break;
case V_398 :
if ( ! F_202 ( V_8 ) )
return 1 ;
V_183 = F_6 ( V_8 ) -> V_13 . V_399 ;
break;
case V_371 ... V_400 :
if ( ! F_202 ( V_8 ) )
return 1 ;
return F_208 ( V_8 , V_369 , V_370 ) ;
case V_287 :
if ( ! F_6 ( V_8 ) -> V_288 )
return 1 ;
default:
V_74 = F_66 ( F_6 ( V_8 ) , V_369 ) ;
if ( V_74 ) {
V_183 = V_74 -> V_183 ;
break;
}
return F_212 ( V_8 , V_369 , V_370 ) ;
}
* V_370 = V_183 ;
return 0 ;
}
static int F_213 ( struct V_7 * V_8 , struct V_401 * V_402 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_86 * V_74 ;
int V_114 = 0 ;
T_2 V_369 = V_402 -> V_79 ;
T_3 V_183 = V_402 -> V_183 ;
switch ( V_369 ) {
case V_144 :
V_114 = F_214 ( V_8 , V_402 ) ;
break;
#ifdef F_96
case V_207 :
F_116 ( V_73 ) ;
F_99 ( V_389 , V_183 ) ;
break;
case V_209 :
F_116 ( V_73 ) ;
F_99 ( V_390 , V_183 ) ;
break;
case V_210 :
F_151 ( V_73 ) ;
V_73 -> V_212 = V_183 ;
break;
#endif
case V_392 :
F_102 ( V_393 , V_183 ) ;
break;
case V_394 :
F_99 ( V_395 , V_183 ) ;
break;
case V_227 :
F_99 ( V_396 , V_183 ) ;
break;
case V_214 :
if ( ! F_205 () )
return 1 ;
F_103 ( V_397 , V_183 ) ;
break;
case V_391 :
F_215 ( V_8 , V_402 ) ;
break;
case V_403 :
if ( V_29 . V_404 & V_332 ) {
F_103 ( V_405 , V_183 ) ;
V_8 -> V_116 . V_406 = V_183 ;
break;
}
V_114 = F_214 ( V_8 , V_402 ) ;
break;
case V_407 :
V_114 = F_214 ( V_8 , V_402 ) ;
break;
case V_398 :
if ( ! F_202 ( V_8 ) ||
( F_6 ( V_8 ) -> V_13 . V_399 &
V_408 && ! V_402 -> V_409 ) )
return 1 ;
V_73 -> V_13 . V_399 = V_183 ;
if ( V_402 -> V_409 && V_183 == 0 )
F_216 ( V_8 ) ;
break;
case V_371 ... V_400 :
return 1 ;
case V_287 :
if ( ! V_73 -> V_288 )
return 1 ;
if ( ( V_183 >> 32 ) != 0 )
return 1 ;
default:
V_74 = F_66 ( V_73 , V_369 ) ;
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
V_114 = F_214 ( V_8 , V_402 ) ;
}
return V_114 ;
}
static void F_217 ( struct V_7 * V_8 , enum V_410 V_411 )
{
F_171 ( V_411 , ( unsigned long * ) & V_8 -> V_116 . V_117 ) ;
switch ( V_411 ) {
case V_412 :
V_8 -> V_116 . V_413 [ V_412 ] = F_92 ( V_414 ) ;
break;
case V_415 :
V_8 -> V_116 . V_413 [ V_415 ] = F_92 ( V_416 ) ;
break;
case V_417 :
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
F_55 ( V_398 , V_74 ) ;
if ( V_74 & V_408 ) {
if ( ! ( V_74 & V_418 )
&& F_222 () )
return 1 ;
if ( ! ( V_74 & V_419 )
&& ( V_74 & V_418 )
&& ! F_222 () ) {
F_69 ( V_166 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_74 & V_419 )
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
static int F_223 ( void * V_420 )
{
int V_91 = F_79 () ;
T_3 V_88 = F_68 ( F_82 ( V_220 , V_91 ) ) ;
T_3 V_421 , V_422 ;
if ( F_224 () & V_423 )
return - V_424 ;
F_225 ( & F_82 ( V_224 , V_91 ) ) ;
F_72 ( V_91 ) ;
F_55 ( V_398 , V_421 ) ;
V_422 = V_408 ;
V_422 |= V_419 ;
if ( F_222 () )
V_422 |= V_418 ;
if ( ( V_421 & V_422 ) != V_422 ) {
F_141 ( V_398 , V_421 | V_422 ) ;
}
F_226 ( F_224 () | V_423 ) ;
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
struct V_90 * V_94 , * V_425 ;
F_229 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_81 ( V_94 ) ;
}
static void F_162 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_230 ( void * V_420 )
{
if ( V_221 ) {
F_228 () ;
F_162 () ;
}
F_226 ( F_224 () & ~ V_423 ) ;
}
static T_11 int F_231 ( T_2 V_426 , T_2 V_427 ,
T_2 V_74 , T_2 * V_428 )
{
T_2 V_429 , V_430 ;
T_2 V_431 = V_426 | V_427 ;
F_204 ( V_74 , V_429 , V_430 ) ;
V_431 &= V_430 ;
V_431 |= V_429 ;
if ( V_426 & ~ V_431 )
return - V_432 ;
* V_428 = V_431 ;
return 0 ;
}
static T_11 bool F_232 ( T_2 V_74 , T_2 V_431 )
{
T_2 V_429 , V_430 ;
F_204 ( V_74 , V_429 , V_430 ) ;
return V_430 & V_431 ;
}
static T_11 int F_233 ( struct V_29 * V_433 )
{
T_2 V_429 , V_430 ;
T_2 V_434 , V_435 , V_436 , V_437 ;
T_2 V_438 = 0 ;
T_2 V_439 = 0 ;
T_2 V_440 = 0 ;
T_2 V_441 = 0 ;
T_2 V_442 = 0 ;
V_434 = V_342 |
#ifdef F_96
V_347 |
V_348 |
#endif
V_345 |
V_346 |
V_351 |
V_349 |
V_300 |
V_344 |
V_352 |
V_343 |
V_353 ;
V_435 = V_32 |
V_31 |
V_33 ;
if ( F_231 ( V_434 , V_435 , V_336 ,
& V_439 ) < 0 )
return - V_432 ;
#ifdef F_96
if ( ( V_439 & V_32 ) )
V_439 &= ~ V_347 &
~ V_348 ;
#endif
if ( V_439 & V_33 ) {
V_436 = 0 ;
V_437 = V_35 |
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
if ( F_231 ( V_436 , V_437 ,
V_357 ,
& V_440 ) < 0 )
return - V_432 ;
}
#ifndef F_96
if ( ! ( V_440 &
V_35 ) )
V_439 &= ~ V_32 ;
#endif
if ( ! ( V_439 & V_32 ) )
V_440 &= ~ (
V_37 |
V_36 |
V_38 ) ;
if ( V_440 & V_55 ) {
V_439 &= ~ ( V_345 |
V_346 |
V_343 ) ;
F_204 ( V_387 ,
V_41 . V_42 , V_41 . V_52 ) ;
}
V_434 = V_326 ;
#ifdef F_96
V_434 |= V_318 ;
#endif
V_435 = V_320 | V_319 |
V_323 | V_324 ;
if ( F_231 ( V_434 , V_435 , V_314 ,
& V_441 ) < 0 )
return - V_432 ;
V_434 = V_312 | V_313 ;
V_435 = V_62 | V_40 ;
if ( F_231 ( V_434 , V_435 , V_308 ,
& V_438 ) < 0 )
return - V_432 ;
if ( ! ( V_440 &
V_38 ) ||
! ( V_441 & V_323 ) )
V_438 &= ~ V_40 ;
V_434 = V_335 ;
V_435 = V_332 | V_333 ;
if ( F_231 ( V_434 , V_435 , V_327 ,
& V_442 ) < 0 )
return - V_432 ;
F_204 ( V_371 , V_429 , V_430 ) ;
if ( ( V_430 & 0x1fff ) > V_443 )
return - V_432 ;
#ifdef F_96
if ( V_430 & ( 1u << 16 ) )
return - V_432 ;
#endif
if ( ( ( V_430 >> 18 ) & 15 ) != 6 )
return - V_432 ;
V_433 -> V_444 = V_430 & 0x1fff ;
V_433 -> V_445 = F_234 ( V_29 . V_444 ) ;
V_433 -> V_446 = V_429 ;
V_433 -> V_39 = V_438 ;
V_433 -> V_30 = V_439 ;
V_433 -> V_34 = V_440 ;
V_433 -> V_447 = V_441 ;
V_433 -> V_404 = V_442 ;
V_145 =
F_232 ( V_327 ,
V_146 )
&& F_232 ( V_314 ,
V_147 ) ;
V_149 =
F_232 ( V_327 ,
V_150 )
&& F_232 ( V_314 ,
V_151 ) ;
if ( V_149 && V_448 . V_449 == 0x6 ) {
switch ( V_448 . V_450 ) {
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
int V_451 = F_236 ( V_91 ) ;
struct V_15 * V_452 ;
struct V_87 * V_87 ;
V_452 = F_237 ( V_451 , V_453 , V_29 . V_445 ) ;
if ( ! V_452 )
return NULL ;
V_87 = F_238 ( V_452 ) ;
memset ( V_87 , 0 , V_29 . V_444 ) ;
V_87 -> V_446 = V_29 . V_446 ;
return V_87 ;
}
static struct V_87 * F_239 ( void )
{
return F_235 ( F_79 () ) ;
}
static void F_240 ( struct V_87 * V_87 )
{
F_241 ( ( unsigned long ) V_87 , V_29 . V_445 ) ;
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
int V_75 , V_454 ;
for ( V_75 = V_454 = 0 ; V_75 < V_455 ; V_75 ++ ) {
switch ( V_456 [ V_75 ] ) {
case V_397 :
if ( ! F_205 () )
continue;
break;
default:
break;
}
if ( V_454 < V_75 )
V_456 [ V_454 ] =
V_456 [ V_75 ] ;
V_454 ++ ;
}
V_455 = V_454 ;
for ( V_75 = 0 ; V_75 < V_455 ; V_75 ++ ) {
F_246 ( V_456 [ V_75 ] ,
V_457 ) ;
F_246 ( V_456 [ V_75 ] ,
V_458 ) ;
}
for ( V_75 = 0 ; V_75 < V_459 ; V_75 ++ )
F_246 ( V_460 [ V_75 ] ,
V_458 ) ;
}
static T_11 int F_247 ( void )
{
int V_91 ;
F_244 (cpu) {
struct V_87 * V_87 ;
V_87 = F_235 ( V_91 ) ;
if ( ! V_87 ) {
F_243 () ;
return - V_461 ;
}
F_82 ( V_220 , V_91 ) = V_87 ;
}
return 0 ;
}
static T_11 int F_248 ( void )
{
if ( F_233 ( & V_29 ) < 0 )
return - V_432 ;
if ( F_142 ( V_462 ) )
F_249 ( V_178 ) ;
if ( ! F_49 () )
V_463 = 0 ;
if ( ! F_54 () )
V_464 = 0 ;
if ( V_464 )
F_245 () ;
if ( ! F_45 () ||
! F_39 () ) {
V_101 = 0 ;
V_465 = 0 ;
V_466 = 0 ;
}
if ( ! F_40 () )
V_466 = 0 ;
if ( ! F_46 () )
V_465 = 0 ;
if ( ! F_33 () )
V_58 = 0 ;
if ( ! F_23 () )
V_467 -> V_468 = NULL ;
if ( V_101 && ! F_37 () )
F_250 () ;
if ( ! F_47 () )
V_469 = 0 ;
if ( ! F_32 () )
V_470 = 0 ;
if ( V_470 )
V_467 -> V_468 = NULL ;
else {
V_467 -> V_471 = NULL ;
V_467 -> V_472 = NULL ;
V_467 -> V_473 = V_474 ;
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
return V_475 && ! F_253 ( V_8 ) ;
}
static void F_254 ( struct V_7 * V_8 , int V_113 ,
struct V_476 * V_477 )
{
if ( ! V_475 ) {
if ( V_113 == V_478 || V_113 == V_479 )
V_477 -> V_120 &= ~ V_480 ;
V_477 -> V_481 = V_477 -> V_120 & V_480 ;
V_477 -> V_187 = 1 ;
}
F_255 ( V_8 , V_477 , V_113 ) ;
}
static void F_256 ( struct V_7 * V_8 )
{
unsigned long V_482 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_484 ] , V_484 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_485 ] , V_485 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_486 ] , V_486 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_487 ] , V_487 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_479 ] , V_479 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_478 ] , V_478 ) ;
V_73 -> V_136 . V_137 = 0 ;
F_116 ( V_73 ) ;
F_255 ( V_8 , & V_73 -> V_136 . V_483 [ V_488 ] , V_488 ) ;
V_482 = F_92 ( V_246 ) ;
V_482 &= V_247 ;
V_482 |= V_73 -> V_136 . V_244 & ~ V_247 ;
F_99 ( V_246 , V_482 ) ;
F_99 ( V_489 , ( F_92 ( V_489 ) & ~ V_490 ) |
( F_92 ( V_491 ) & V_490 ) ) ;
F_122 ( V_8 ) ;
F_254 ( V_8 , V_478 , & V_73 -> V_136 . V_483 [ V_478 ] ) ;
F_254 ( V_8 , V_479 , & V_73 -> V_136 . V_483 [ V_479 ] ) ;
F_254 ( V_8 , V_484 , & V_73 -> V_136 . V_483 [ V_484 ] ) ;
F_254 ( V_8 , V_485 , & V_73 -> V_136 . V_483 [ V_485 ] ) ;
F_254 ( V_8 , V_486 , & V_73 -> V_136 . V_483 [ V_486 ] ) ;
F_254 ( V_8 , V_487 , & V_73 -> V_136 . V_483 [ V_487 ] ) ;
}
static void F_258 ( int V_113 , struct V_476 * V_477 )
{
const struct V_492 * V_493 = & V_122 [ V_113 ] ;
struct V_476 V_494 = * V_477 ;
V_494 . V_481 = 0x3 ;
if ( V_113 == V_478 )
V_494 . type = 0x3 ;
if ( ! V_475 ) {
V_494 . V_120 = V_494 . V_123 >> 4 ;
V_494 . V_123 = V_494 . V_123 & 0xffff0 ;
V_494 . V_125 = 0xffff ;
V_494 . V_495 = 0 ;
V_494 . V_496 = 0 ;
V_494 . V_497 = 1 ;
V_494 . V_187 = 1 ;
V_494 . V_498 = 0 ;
V_494 . V_499 = 0 ;
V_494 . type = 0x3 ;
V_494 . V_500 = 0 ;
if ( V_477 -> V_123 & 0xf )
F_128 ( V_166 L_12
L_13
L_14 , V_113 ) ;
}
F_101 ( V_493 -> V_120 , V_494 . V_120 ) ;
F_102 ( V_493 -> V_123 , V_494 . V_123 ) ;
F_102 ( V_493 -> V_125 , V_494 . V_125 ) ;
F_102 ( V_493 -> V_129 , F_259 ( & V_494 ) ) ;
}
static void F_260 ( struct V_7 * V_8 )
{
unsigned long V_482 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_488 ] , V_488 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_484 ] , V_484 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_485 ] , V_485 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_486 ] , V_486 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_487 ] , V_487 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_479 ] , V_479 ) ;
F_257 ( V_8 , & V_73 -> V_136 . V_483 [ V_478 ] , V_478 ) ;
V_73 -> V_136 . V_137 = 1 ;
if ( ! V_8 -> V_17 -> V_116 . V_501 )
F_128 ( V_166 L_15
L_16 ) ;
F_116 ( V_73 ) ;
F_99 ( V_502 , V_8 -> V_17 -> V_116 . V_501 ) ;
F_102 ( V_503 , V_504 - 1 ) ;
F_102 ( V_505 , 0x008b ) ;
V_482 = F_92 ( V_246 ) ;
V_73 -> V_136 . V_244 = V_482 ;
V_482 |= V_248 | V_249 ;
F_99 ( V_246 , V_482 ) ;
F_99 ( V_489 , F_92 ( V_489 ) | V_490 ) ;
F_122 ( V_8 ) ;
F_258 ( V_479 , & V_73 -> V_136 . V_483 [ V_479 ] ) ;
F_258 ( V_478 , & V_73 -> V_136 . V_483 [ V_478 ] ) ;
F_258 ( V_484 , & V_73 -> V_136 . V_483 [ V_484 ] ) ;
F_258 ( V_485 , & V_73 -> V_136 . V_483 [ V_485 ] ) ;
F_258 ( V_487 , & V_73 -> V_136 . V_483 [ V_487 ] ) ;
F_258 ( V_486 , & V_73 -> V_136 . V_483 [ V_486 ] ) ;
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
F_109 ( F_6 ( V_8 ) , V_331 ) ;
V_74 -> V_183 = V_177 ;
} else {
F_110 ( F_6 ( V_8 ) , V_331 ) ;
V_74 -> V_183 = V_177 & ~ V_181 ;
}
F_188 ( V_73 ) ;
}
static void F_263 ( struct V_7 * V_8 )
{
T_2 V_506 ;
F_116 ( F_6 ( V_8 ) ) ;
V_506 = F_94 ( V_505 ) ;
if ( ( V_506 & V_507 ) != V_508 ) {
F_264 ( L_17 ,
V_509 ) ;
F_102 ( V_505 ,
( V_506 & ~ V_507 )
| V_508 ) ;
}
F_262 ( V_8 , V_8 -> V_116 . V_177 | V_180 ) ;
}
static void F_265 ( struct V_7 * V_8 )
{
F_110 ( F_6 ( V_8 ) , V_331 ) ;
F_262 ( V_8 , V_8 -> V_116 . V_177 & ~ V_180 ) ;
}
static void F_266 ( struct V_7 * V_8 )
{
F_89 ( F_6 ( V_8 ) ) ;
if ( V_101 ) {
if ( ! F_267 ( V_8 -> V_116 . V_510 . V_511 ) )
return;
F_91 ( F_268 ( V_8 -> V_116 . V_510 . V_511 ) ) ;
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
V_8 -> V_116 . V_512 = F_92 ( V_513 ) ;
F_171 ( V_514 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
}
static void F_271 ( struct V_7 * V_8 )
{
T_9 V_515 = V_8 -> V_116 . V_515 ;
V_8 -> V_116 . V_516 &= ~ V_515 ;
V_8 -> V_116 . V_516 |= F_92 ( V_489 ) & V_515 ;
}
static void F_272 ( struct V_7 * V_8 )
{
struct V_517 * V_510 = V_8 -> V_116 . V_518 ;
if ( ! F_170 ( V_417 ,
( unsigned long * ) & V_8 -> V_116 . V_519 ) )
return;
if ( F_270 ( V_8 ) && F_273 ( V_8 ) && ! F_140 ( V_8 ) ) {
F_103 ( V_520 , V_510 -> V_521 [ 0 ] ) ;
F_103 ( V_522 , V_510 -> V_521 [ 1 ] ) ;
F_103 ( V_523 , V_510 -> V_521 [ 2 ] ) ;
F_103 ( V_524 , V_510 -> V_521 [ 3 ] ) ;
}
}
static void F_218 ( struct V_7 * V_8 )
{
struct V_517 * V_510 = V_8 -> V_116 . V_518 ;
if ( F_270 ( V_8 ) && F_273 ( V_8 ) && ! F_140 ( V_8 ) ) {
V_510 -> V_521 [ 0 ] = F_95 ( V_520 ) ;
V_510 -> V_521 [ 1 ] = F_95 ( V_522 ) ;
V_510 -> V_521 [ 2 ] = F_95 ( V_523 ) ;
V_510 -> V_521 [ 3 ] = F_95 ( V_524 ) ;
}
F_171 ( V_417 ,
( unsigned long * ) & V_8 -> V_116 . V_117 ) ;
F_171 ( V_417 ,
( unsigned long * ) & V_8 -> V_116 . V_519 ) ;
}
static void F_274 ( unsigned long * V_525 ,
unsigned long V_229 ,
struct V_7 * V_8 )
{
if ( ! F_170 ( V_514 , ( T_9 * ) & V_8 -> V_116 . V_117 ) )
F_269 ( V_8 ) ;
if ( ! ( V_229 & V_526 ) ) {
F_102 ( V_527 ,
F_94 ( V_527 ) |
( V_345 |
V_346 ) ) ;
V_8 -> V_116 . V_229 = V_229 ;
F_275 ( V_8 , F_276 ( V_8 ) ) ;
} else if ( ! F_270 ( V_8 ) ) {
F_102 ( V_527 ,
F_94 ( V_527 ) &
~ ( V_345 |
V_346 ) ) ;
V_8 -> V_116 . V_229 = V_229 ;
F_275 ( V_8 , F_276 ( V_8 ) ) ;
}
if ( ! ( V_229 & V_528 ) )
* V_525 &= ~ V_528 ;
}
static void F_277 ( struct V_7 * V_8 , unsigned long V_229 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_525 ;
V_525 = ( V_229 & ~ V_529 ) ;
if ( V_465 )
V_525 |= V_530 ;
else {
V_525 |= V_531 ;
if ( V_73 -> V_136 . V_137 && ( V_229 & V_532 ) )
F_256 ( V_8 ) ;
if ( ! V_73 -> V_136 . V_137 && ! ( V_229 & V_532 ) )
F_260 ( V_8 ) ;
}
#ifdef F_96
if ( V_8 -> V_116 . V_177 & V_181 ) {
if ( ! F_270 ( V_8 ) && ( V_229 & V_526 ) )
F_263 ( V_8 ) ;
if ( F_270 ( V_8 ) && ! ( V_229 & V_526 ) )
F_265 ( V_8 ) ;
}
#endif
if ( V_101 )
F_274 ( & V_525 , V_229 , V_8 ) ;
if ( ! V_8 -> V_138 )
V_525 |= V_231 | V_232 ;
F_99 ( V_242 , V_229 ) ;
F_99 ( V_230 , V_525 ) ;
V_8 -> V_116 . V_229 = V_229 ;
V_73 -> F_252 = F_252 ( V_8 ) ;
}
static T_3 F_268 ( unsigned long V_511 )
{
T_3 V_84 ;
V_84 = V_533 |
V_534 << V_535 ;
if ( V_466 )
V_84 |= V_536 ;
V_84 |= ( V_511 & V_537 ) ;
return V_84 ;
}
static void F_278 ( struct V_7 * V_8 , unsigned long V_512 )
{
unsigned long V_538 ;
T_3 V_84 ;
V_538 = V_512 ;
if ( V_101 ) {
V_84 = F_268 ( V_512 ) ;
F_103 ( V_539 , V_84 ) ;
if ( F_270 ( V_8 ) || F_123 ( V_8 ) )
V_538 = F_279 ( V_8 ) ;
else
V_538 = V_8 -> V_17 -> V_116 . V_540 ;
F_272 ( V_8 ) ;
}
F_266 ( V_8 ) ;
F_99 ( V_513 , V_538 ) ;
}
static int F_275 ( struct V_7 * V_8 , unsigned long V_516 )
{
unsigned long V_541 = V_516 | ( F_6 ( V_8 ) -> V_136 . V_137 ?
V_542 : V_543 ) ;
if ( V_516 & V_423 ) {
if ( ! F_202 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_544 &&
( ( V_516 & F_210 ) != F_210 ) )
return 1 ;
V_8 -> V_116 . V_516 = V_516 ;
if ( V_101 ) {
if ( ! F_270 ( V_8 ) ) {
V_541 &= ~ V_545 ;
V_541 |= V_546 ;
V_541 &= ~ ( V_547 | V_548 ) ;
} else if ( ! ( V_516 & V_545 ) ) {
V_541 &= ~ V_545 ;
}
}
F_99 ( V_491 , V_516 ) ;
F_99 ( V_489 , V_541 ) ;
return 0 ;
}
static void F_257 ( struct V_7 * V_8 ,
struct V_476 * V_494 , int V_113 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_127 ;
if ( V_73 -> V_136 . V_137 && V_113 != V_549 ) {
* V_494 = V_73 -> V_136 . V_483 [ V_113 ] ;
if ( V_113 == V_488
|| V_494 -> V_120 == F_118 ( V_73 , V_113 ) )
return;
V_494 -> V_123 = F_119 ( V_73 , V_113 ) ;
V_494 -> V_120 = F_118 ( V_73 , V_113 ) ;
return;
}
V_494 -> V_123 = F_119 ( V_73 , V_113 ) ;
V_494 -> V_125 = F_120 ( V_73 , V_113 ) ;
V_494 -> V_120 = F_118 ( V_73 , V_113 ) ;
V_127 = F_121 ( V_73 , V_113 ) ;
V_494 -> V_499 = ( V_127 >> 16 ) & 1 ;
V_494 -> type = V_127 & 15 ;
V_494 -> V_187 = ( V_127 >> 4 ) & 1 ;
V_494 -> V_481 = ( V_127 >> 5 ) & 3 ;
V_494 -> V_497 = ! V_494 -> V_499 ;
V_494 -> V_500 = ( V_127 >> 12 ) & 1 ;
V_494 -> V_498 = ( V_127 >> 13 ) & 1 ;
V_494 -> V_496 = ( V_127 >> 14 ) & 1 ;
V_494 -> V_495 = ( V_127 >> 15 ) & 1 ;
}
static T_3 F_280 ( struct V_7 * V_8 , int V_113 )
{
struct V_476 V_187 ;
if ( F_6 ( V_8 ) -> V_136 . V_137 ) {
F_257 ( V_8 , & V_187 , V_113 ) ;
return V_187 . V_123 ;
}
return F_119 ( F_6 ( V_8 ) , V_113 ) ;
}
static int F_281 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_100 ( V_73 -> V_136 . V_137 ) )
return 0 ;
else {
int V_127 = F_121 ( V_73 , V_479 ) ;
return F_282 ( V_127 ) ;
}
}
static T_2 F_259 ( struct V_476 * V_494 )
{
T_2 V_127 ;
if ( V_494 -> V_499 || ! V_494 -> V_497 )
V_127 = 1 << 16 ;
else {
V_127 = V_494 -> type & 15 ;
V_127 |= ( V_494 -> V_187 & 1 ) << 4 ;
V_127 |= ( V_494 -> V_481 & 3 ) << 5 ;
V_127 |= ( V_494 -> V_497 & 1 ) << 7 ;
V_127 |= ( V_494 -> V_500 & 1 ) << 12 ;
V_127 |= ( V_494 -> V_498 & 1 ) << 13 ;
V_127 |= ( V_494 -> V_496 & 1 ) << 14 ;
V_127 |= ( V_494 -> V_495 & 1 ) << 15 ;
}
return V_127 ;
}
static void F_255 ( struct V_7 * V_8 ,
struct V_476 * V_494 , int V_113 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
const struct V_492 * V_493 = & V_122 [ V_113 ] ;
F_116 ( V_73 ) ;
if ( V_73 -> V_136 . V_137 && V_113 != V_549 ) {
V_73 -> V_136 . V_483 [ V_113 ] = * V_494 ;
if ( V_113 == V_488 )
F_101 ( V_493 -> V_120 , V_494 -> V_120 ) ;
else if ( V_494 -> V_187 )
F_258 ( V_113 , & V_73 -> V_136 . V_483 [ V_113 ] ) ;
goto V_550;
}
F_99 ( V_493 -> V_123 , V_494 -> V_123 ) ;
F_102 ( V_493 -> V_125 , V_494 -> V_125 ) ;
F_101 ( V_493 -> V_120 , V_494 -> V_120 ) ;
if ( V_465 && ( V_113 != V_549 ) )
V_494 -> type |= 0x1 ;
F_102 ( V_493 -> V_129 , F_259 ( V_494 ) ) ;
V_550:
V_73 -> F_252 = F_252 ( V_8 ) ;
}
static void F_283 ( struct V_7 * V_8 , int * V_496 , int * V_498 )
{
T_2 V_127 = F_121 ( F_6 ( V_8 ) , V_478 ) ;
* V_496 = ( V_127 >> 14 ) & 1 ;
* V_498 = ( V_127 >> 13 ) & 1 ;
}
static void F_284 ( struct V_7 * V_8 , struct V_167 * V_551 )
{
V_551 -> V_444 = F_94 ( V_552 ) ;
V_551 -> V_172 = F_92 ( V_553 ) ;
}
static void F_285 ( struct V_7 * V_8 , struct V_167 * V_551 )
{
F_102 ( V_552 , V_551 -> V_444 ) ;
F_99 ( V_553 , V_551 -> V_172 ) ;
}
static void F_286 ( struct V_7 * V_8 , struct V_167 * V_551 )
{
V_551 -> V_444 = F_94 ( V_554 ) ;
V_551 -> V_172 = F_92 ( V_555 ) ;
}
static void F_287 ( struct V_7 * V_8 , struct V_167 * V_551 )
{
F_102 ( V_554 , V_551 -> V_444 ) ;
F_99 ( V_555 , V_551 -> V_172 ) ;
}
static bool F_288 ( struct V_7 * V_8 , int V_113 )
{
struct V_476 V_494 ;
T_2 V_127 ;
F_257 ( V_8 , & V_494 , V_113 ) ;
V_494 . V_481 = 0x3 ;
if ( V_113 == V_478 )
V_494 . type = 0x3 ;
V_127 = F_259 ( & V_494 ) ;
if ( V_494 . V_123 != ( V_494 . V_120 << 4 ) )
return false ;
if ( V_494 . V_125 != 0xffff )
return false ;
if ( V_127 != 0xf3 )
return false ;
return true ;
}
static bool F_289 ( struct V_7 * V_8 )
{
struct V_476 V_556 ;
unsigned int V_557 ;
F_257 ( V_8 , & V_556 , V_478 ) ;
V_557 = V_556 . V_120 & V_480 ;
if ( V_556 . V_499 )
return false ;
if ( ~ V_556 . type & ( V_558 | V_559 ) )
return false ;
if ( ! V_556 . V_187 )
return false ;
if ( V_556 . type & V_560 ) {
if ( V_556 . V_481 > V_557 )
return false ;
} else {
if ( V_556 . V_481 != V_557 )
return false ;
}
if ( ! V_556 . V_497 )
return false ;
return true ;
}
static bool F_290 ( struct V_7 * V_8 )
{
struct V_476 V_561 ;
unsigned int V_562 ;
F_257 ( V_8 , & V_561 , V_479 ) ;
V_562 = V_561 . V_120 & V_480 ;
if ( V_561 . V_499 )
return true ;
if ( V_561 . type != 3 && V_561 . type != 7 )
return false ;
if ( ! V_561 . V_187 )
return false ;
if ( V_561 . V_481 != V_562 )
return false ;
if ( ! V_561 . V_497 )
return false ;
return true ;
}
static bool F_291 ( struct V_7 * V_8 , int V_113 )
{
struct V_476 V_494 ;
unsigned int V_563 ;
F_257 ( V_8 , & V_494 , V_113 ) ;
V_563 = V_494 . V_120 & V_480 ;
if ( V_494 . V_499 )
return true ;
if ( ! V_494 . V_187 )
return false ;
if ( ! V_494 . V_497 )
return false ;
if ( ~ V_494 . type & ( V_558 | V_560 ) ) {
if ( V_494 . V_481 < V_563 )
return false ;
}
return true ;
}
static bool F_292 ( struct V_7 * V_8 )
{
struct V_476 V_190 ;
F_257 ( V_8 , & V_190 , V_488 ) ;
if ( V_190 . V_499 )
return false ;
if ( V_190 . V_120 & V_564 )
return false ;
if ( V_190 . type != 3 && V_190 . type != 11 )
return false ;
if ( ! V_190 . V_497 )
return false ;
return true ;
}
static bool F_293 ( struct V_7 * V_8 )
{
struct V_476 V_565 ;
F_257 ( V_8 , & V_565 , V_549 ) ;
if ( V_565 . V_499 )
return true ;
if ( V_565 . V_120 & V_564 )
return false ;
if ( V_565 . type != 2 )
return false ;
if ( ! V_565 . V_497 )
return false ;
return true ;
}
static bool F_294 ( struct V_7 * V_8 )
{
struct V_476 V_556 , V_561 ;
F_257 ( V_8 , & V_556 , V_478 ) ;
F_257 ( V_8 , & V_561 , V_479 ) ;
return ( ( V_556 . V_120 & V_480 ) ==
( V_561 . V_120 & V_480 ) ) ;
}
static bool F_253 ( struct V_7 * V_8 )
{
if ( V_465 )
return true ;
if ( ! F_295 ( V_8 ) || ( F_169 ( V_8 ) & V_249 ) ) {
if ( ! F_288 ( V_8 , V_478 ) )
return false ;
if ( ! F_288 ( V_8 , V_479 ) )
return false ;
if ( ! F_288 ( V_8 , V_485 ) )
return false ;
if ( ! F_288 ( V_8 , V_484 ) )
return false ;
if ( ! F_288 ( V_8 , V_486 ) )
return false ;
if ( ! F_288 ( V_8 , V_487 ) )
return false ;
} else {
if ( ! F_294 ( V_8 ) )
return false ;
if ( ! F_289 ( V_8 ) )
return false ;
if ( ! F_290 ( V_8 ) )
return false ;
if ( ! F_291 ( V_8 , V_485 ) )
return false ;
if ( ! F_291 ( V_8 , V_484 ) )
return false ;
if ( ! F_291 ( V_8 , V_486 ) )
return false ;
if ( ! F_291 ( V_8 , V_487 ) )
return false ;
if ( ! F_292 ( V_8 ) )
return false ;
if ( ! F_293 ( V_8 ) )
return false ;
}
return true ;
}
static int F_296 ( struct V_17 * V_17 )
{
T_13 V_566 ;
T_4 V_183 = 0 ;
int V_567 , V_568 , V_114 = 0 ;
V_568 = F_297 ( & V_17 -> V_569 ) ;
V_566 = V_17 -> V_116 . V_501 >> V_18 ;
V_567 = F_298 ( V_17 , V_566 , 0 , V_443 ) ;
if ( V_567 < 0 )
goto V_550;
V_183 = V_570 + V_571 ;
V_567 = F_299 ( V_17 , V_566 ++ , & V_183 ,
V_572 , sizeof( T_4 ) ) ;
if ( V_567 < 0 )
goto V_550;
V_567 = F_298 ( V_17 , V_566 ++ , 0 , V_443 ) ;
if ( V_567 < 0 )
goto V_550;
V_567 = F_298 ( V_17 , V_566 , 0 , V_443 ) ;
if ( V_567 < 0 )
goto V_550;
V_183 = ~ 0 ;
V_567 = F_299 ( V_17 , V_566 , & V_183 ,
V_504 - 2 * V_443 - 1 ,
sizeof( T_6 ) ) ;
if ( V_567 < 0 )
goto V_550;
V_114 = 1 ;
V_550:
F_300 ( & V_17 -> V_569 , V_568 ) ;
return V_114 ;
}
static int F_301 ( struct V_17 * V_17 )
{
int V_75 , V_568 , V_567 , V_114 ;
T_14 V_573 ;
T_2 V_276 ;
if ( ! V_101 )
return 1 ;
if ( F_100 ( ! V_17 -> V_116 . V_574 ) ) {
F_69 ( V_89 L_18
L_19 ) ;
return 0 ;
}
if ( F_302 ( V_17 -> V_116 . V_575 ) )
return 1 ;
V_114 = 0 ;
V_573 = V_17 -> V_116 . V_540 >> V_18 ;
V_568 = F_297 ( & V_17 -> V_569 ) ;
V_567 = F_298 ( V_17 , V_573 , 0 , V_443 ) ;
if ( V_567 < 0 )
goto V_550;
for ( V_75 = 0 ; V_75 < V_576 ; V_75 ++ ) {
V_276 = ( V_75 << 22 ) + ( V_577 | V_578 | V_579 |
V_580 | V_581 | V_582 ) ;
V_567 = F_299 ( V_17 , V_573 ,
& V_276 , V_75 * sizeof( V_276 ) , sizeof( V_276 ) ) ;
if ( V_567 < 0 )
goto V_550;
}
V_17 -> V_116 . V_575 = true ;
V_114 = 1 ;
V_550:
F_300 ( & V_17 -> V_569 , V_568 ) ;
return V_114 ;
}
static void F_303 ( int V_113 )
{
const struct V_492 * V_493 = & V_122 [ V_113 ] ;
unsigned int V_127 ;
F_101 ( V_493 -> V_120 , 0 ) ;
F_99 ( V_493 -> V_123 , 0 ) ;
F_102 ( V_493 -> V_125 , 0xffff ) ;
V_127 = 0x93 ;
if ( V_113 == V_478 )
V_127 |= 0x08 ;
F_102 ( V_493 -> V_129 , V_127 ) ;
}
static int F_304 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_583 V_584 ;
int V_567 = 0 ;
F_305 ( & V_17 -> V_585 ) ;
if ( V_17 -> V_116 . V_586 )
goto V_550;
V_584 . V_587 = V_588 ;
V_584 . V_482 = 0 ;
V_584 . V_589 = 0xfee00000ULL ;
V_584 . V_590 = V_443 ;
V_567 = F_306 ( V_17 , & V_584 ) ;
if ( V_567 )
goto V_550;
V_15 = F_11 ( V_17 , 0xfee00 ) ;
if ( F_12 ( V_15 ) ) {
V_567 = - V_591 ;
goto V_550;
}
V_17 -> V_116 . V_586 = V_15 ;
V_550:
F_307 ( & V_17 -> V_585 ) ;
return V_567 ;
}
static int F_308 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_583 V_584 ;
int V_567 = 0 ;
F_305 ( & V_17 -> V_585 ) ;
if ( V_17 -> V_116 . V_574 )
goto V_550;
V_584 . V_587 = V_592 ;
V_584 . V_482 = 0 ;
V_584 . V_589 =
V_17 -> V_116 . V_540 ;
V_584 . V_590 = V_443 ;
V_567 = F_306 ( V_17 , & V_584 ) ;
if ( V_567 )
goto V_550;
V_15 = F_11 ( V_17 , V_17 -> V_116 . V_540 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_567 = - V_591 ;
goto V_550;
}
V_17 -> V_116 . V_574 = V_15 ;
V_550:
F_307 ( & V_17 -> V_585 ) ;
return V_567 ;
}
static void F_309 ( struct V_6 * V_73 )
{
int V_52 ;
V_73 -> V_52 = 0 ;
if ( ! V_463 )
return;
F_310 ( & V_593 ) ;
V_52 = F_311 ( V_594 , V_595 ) ;
if ( V_52 < V_595 ) {
V_73 -> V_52 = V_52 ;
F_171 ( V_52 , V_594 ) ;
}
F_312 ( & V_593 ) ;
}
static void F_313 ( struct V_6 * V_73 )
{
if ( ! V_463 )
return;
F_310 ( & V_593 ) ;
if ( V_73 -> V_52 != 0 )
F_314 ( V_73 -> V_52 , V_594 ) ;
F_312 ( & V_593 ) ;
}
static void F_315 ( unsigned long * V_277 ,
T_2 V_74 , int type )
{
int V_596 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_74 <= 0x1fff ) {
if ( type & V_597 )
F_314 ( V_74 , V_277 + 0x000 / V_596 ) ;
if ( type & V_598 )
F_314 ( V_74 , V_277 + 0x800 / V_596 ) ;
} else if ( ( V_74 >= 0xc0000000 ) && ( V_74 <= 0xc0001fff ) ) {
V_74 &= 0x1fff ;
if ( type & V_597 )
F_314 ( V_74 , V_277 + 0x400 / V_596 ) ;
if ( type & V_598 )
F_314 ( V_74 , V_277 + 0xc00 / V_596 ) ;
}
}
static void F_316 ( unsigned long * V_277 ,
T_2 V_74 , int type )
{
int V_596 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_74 <= 0x1fff ) {
if ( type & V_597 )
F_171 ( V_74 , V_277 + 0x000 / V_596 ) ;
if ( type & V_598 )
F_171 ( V_74 , V_277 + 0x800 / V_596 ) ;
} else if ( ( V_74 >= 0xc0000000 ) && ( V_74 <= 0xc0001fff ) ) {
V_74 &= 0x1fff ;
if ( type & V_597 )
F_171 ( V_74 , V_277 + 0x400 / V_596 ) ;
if ( type & V_598 )
F_171 ( V_74 , V_277 + 0xc00 / V_596 ) ;
}
}
static void F_317 ( T_2 V_74 , bool V_599 )
{
if ( ! V_599 )
F_315 ( V_282 ,
V_74 , V_597 | V_598 ) ;
F_315 ( V_281 ,
V_74 , V_597 | V_598 ) ;
}
static void F_318 ( T_2 V_74 )
{
F_316 ( V_280 ,
V_74 , V_597 ) ;
F_316 ( V_279 ,
V_74 , V_597 ) ;
}
static void F_319 ( T_2 V_74 )
{
F_315 ( V_280 ,
V_74 , V_597 ) ;
F_315 ( V_279 ,
V_74 , V_597 ) ;
}
static void F_320 ( T_2 V_74 )
{
F_315 ( V_280 ,
V_74 , V_598 ) ;
F_315 ( V_279 ,
V_74 , V_598 ) ;
}
static int F_321 ( struct V_17 * V_17 )
{
return V_470 && F_25 ( V_17 ) ;
}
static void F_322 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_567 ;
if ( F_5 ( V_4 , & V_73 -> V_1 ) )
return;
V_567 = F_1 ( & V_73 -> V_1 ) ;
F_156 ( V_600 , V_8 ) ;
#ifdef F_323
if ( ! V_567 && ( V_8 -> V_601 == V_602 ) )
V_278 -> V_603 ( F_324 ( V_8 -> V_91 ) ,
V_604 ) ;
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
static void V_474 ( struct V_7 * V_8 )
{
return;
}
static void F_328 ( struct V_6 * V_73 )
{
T_2 V_605 , V_606 ;
unsigned long V_607 ;
struct V_167 V_551 ;
F_99 ( V_608 , F_329 () & ~ V_231 ) ;
F_99 ( V_609 , F_224 () ) ;
F_99 ( V_610 , F_330 () ) ;
F_101 ( V_611 , V_612 ) ;
#ifdef F_96
F_101 ( V_613 , 0 ) ;
F_101 ( V_614 , 0 ) ;
#else
F_101 ( V_613 , V_615 ) ;
F_101 ( V_614 , V_615 ) ;
#endif
F_101 ( V_616 , V_615 ) ;
F_101 ( V_617 , V_173 * 8 ) ;
F_331 ( & V_551 ) ;
F_99 ( V_618 , V_551 . V_172 ) ;
V_73 -> V_619 = V_551 . V_172 ;
F_99 ( V_620 , V_621 ) ;
F_204 ( V_392 , V_605 , V_606 ) ;
F_102 ( V_622 , V_605 ) ;
F_55 ( V_394 , V_607 ) ;
F_99 ( V_623 , V_607 ) ;
if ( V_29 . V_447 & V_319 ) {
F_204 ( V_403 , V_605 , V_606 ) ;
F_103 ( V_624 , V_605 | ( ( T_3 ) V_606 << 32 ) ) ;
}
}
static void F_332 ( struct V_6 * V_73 )
{
V_73 -> V_8 . V_116 . V_515 = V_625 ;
if ( V_101 )
V_73 -> V_8 . V_116 . V_515 |= V_626 ;
if ( F_123 ( & V_73 -> V_8 ) )
V_73 -> V_8 . V_116 . V_515 &=
~ F_9 ( & V_73 -> V_8 ) -> V_240 ;
F_99 ( V_627 , ~ V_73 -> V_8 . V_116 . V_515 ) ;
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
T_2 V_628 = V_29 . V_30 ;
if ( V_73 -> V_8 . V_116 . V_629 & V_630 )
V_628 &= ~ V_349 ;
if ( ! F_24 ( V_73 -> V_8 . V_17 ) ) {
V_628 &= ~ V_32 ;
#ifdef F_96
V_628 |= V_348 |
V_347 ;
#endif
}
if ( ! V_101 )
V_628 |= V_346 |
V_345 |
V_343 ;
return V_628 ;
}
static T_2 F_335 ( struct V_6 * V_73 )
{
T_2 V_628 = V_29 . V_34 ;
if ( ! F_48 ( V_73 -> V_8 . V_17 ) )
V_628 &= ~ V_35 ;
if ( V_73 -> V_52 == 0 )
V_628 &= ~ V_59 ;
if ( ! V_101 ) {
V_628 &= ~ V_55 ;
V_465 = 0 ;
V_628 &= ~ V_61 ;
}
if ( ! V_465 )
V_628 &= ~ V_56 ;
if ( ! V_469 )
V_628 &= ~ V_57 ;
if ( ! F_321 ( V_73 -> V_8 . V_17 ) )
V_628 &= ~ ( V_37 |
V_38 ) ;
V_628 &= ~ V_36 ;
V_628 &= ~ V_67 ;
return V_628 ;
}
static void F_336 ( void )
{
F_337 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_338 ( struct V_6 * V_73 )
{
#ifdef F_96
unsigned long V_631 ;
#endif
int V_75 ;
F_103 ( V_632 , F_68 ( V_633 ) ) ;
F_103 ( V_634 , F_68 ( V_635 ) ) ;
if ( V_464 ) {
F_103 ( V_636 , F_68 ( V_458 ) ) ;
F_103 ( V_637 , F_68 ( V_457 ) ) ;
}
if ( F_22 () )
F_103 ( V_283 , F_68 ( V_282 ) ) ;
F_103 ( V_638 , - 1ull ) ;
F_102 ( V_639 , F_333 ( V_73 ) ) ;
F_102 ( V_527 , F_334 ( V_73 ) ) ;
if ( F_26 () ) {
F_102 ( V_640 ,
F_335 ( V_73 ) ) ;
}
if ( F_321 ( V_73 -> V_8 . V_17 ) ) {
F_103 ( V_641 , 0 ) ;
F_103 ( V_642 , 0 ) ;
F_103 ( V_643 , 0 ) ;
F_103 ( V_644 , 0 ) ;
F_101 ( V_645 , 0 ) ;
F_103 ( V_646 , V_604 ) ;
F_103 ( V_647 , F_68 ( ( & V_73 -> V_1 ) ) ) ;
}
if ( V_469 ) {
F_102 ( V_648 , V_469 ) ;
F_102 ( V_649 , V_650 ) ;
}
F_102 ( V_651 , 0 ) ;
F_102 ( V_652 , 0 ) ;
F_102 ( V_653 , 0 ) ;
F_101 ( V_197 , 0 ) ;
F_101 ( V_201 , 0 ) ;
F_328 ( V_73 ) ;
#ifdef F_96
F_55 ( V_207 , V_631 ) ;
F_99 ( V_206 , V_631 ) ;
F_55 ( V_209 , V_631 ) ;
F_99 ( V_208 , V_631 ) ;
#else
F_99 ( V_206 , 0 ) ;
F_99 ( V_208 , 0 ) ;
#endif
F_102 ( V_654 , 0 ) ;
F_102 ( V_156 , 0 ) ;
F_103 ( V_655 , F_68 ( V_73 -> V_142 . V_154 ) ) ;
F_102 ( V_155 , 0 ) ;
F_103 ( V_656 , F_68 ( V_73 -> V_142 . V_153 ) ) ;
if ( V_29 . V_404 & V_332 ) {
T_2 V_657 , V_658 ;
T_3 V_659 ;
F_204 ( V_403 , V_657 , V_658 ) ;
V_659 = V_657 | ( ( T_3 ) V_658 << 32 ) ;
F_103 ( V_405 , V_659 ) ;
V_73 -> V_8 . V_116 . V_406 = V_659 ;
}
for ( V_75 = 0 ; V_75 < F_339 ( V_77 ) ; ++ V_75 ) {
T_2 V_79 = V_77 [ V_75 ] ;
T_2 V_660 , V_661 ;
int V_454 = V_73 -> V_76 ;
if ( F_340 ( V_79 , & V_660 , & V_661 ) < 0 )
continue;
if ( F_341 ( V_79 , V_660 , V_661 ) < 0 )
continue;
V_73 -> V_78 [ V_454 ] . V_79 = V_75 ;
V_73 -> V_78 [ V_454 ] . V_183 = 0 ;
V_73 -> V_78 [ V_454 ] . V_105 = - 1ull ;
++ V_73 -> V_76 ;
}
F_111 ( V_73 , V_29 . V_447 ) ;
F_106 ( V_73 , V_29 . V_404 ) ;
F_99 ( V_235 , ~ 0UL ) ;
F_332 ( V_73 ) ;
return 0 ;
}
static void F_342 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_401 V_662 ;
V_73 -> V_136 . V_137 = 0 ;
V_73 -> V_663 = 0 ;
V_73 -> V_8 . V_116 . V_413 [ V_664 ] = F_343 () ;
F_344 ( & V_73 -> V_8 , 0 ) ;
V_662 . V_183 = 0xfee00000 | V_665 ;
if ( F_345 ( & V_73 -> V_8 ) )
V_662 . V_183 |= V_666 ;
V_662 . V_409 = true ;
F_346 ( & V_73 -> V_8 , & V_662 ) ;
F_116 ( V_73 ) ;
F_303 ( V_478 ) ;
F_101 ( V_667 , 0xf000 ) ;
F_102 ( V_668 , 0xffff0000 ) ;
F_303 ( V_485 ) ;
F_303 ( V_484 ) ;
F_303 ( V_486 ) ;
F_303 ( V_487 ) ;
F_303 ( V_479 ) ;
F_101 ( V_669 , 0 ) ;
F_99 ( V_502 , 0 ) ;
F_102 ( V_503 , 0xffff ) ;
F_102 ( V_505 , 0x008b ) ;
F_101 ( V_670 , 0 ) ;
F_99 ( V_671 , 0 ) ;
F_102 ( V_672 , 0xffff ) ;
F_102 ( V_673 , 0x00082 ) ;
F_102 ( V_393 , 0 ) ;
F_99 ( V_396 , 0 ) ;
F_99 ( V_395 , 0 ) ;
F_99 ( V_246 , 0x02 ) ;
F_177 ( V_8 , 0xfff0 ) ;
F_99 ( V_555 , 0 ) ;
F_102 ( V_554 , 0xffff ) ;
F_99 ( V_553 , 0 ) ;
F_102 ( V_552 , 0xffff ) ;
F_102 ( V_674 , V_675 ) ;
F_102 ( V_251 , 0 ) ;
F_102 ( V_676 , 0 ) ;
F_103 ( V_677 , 0 ) ;
F_188 ( V_73 ) ;
F_102 ( V_273 , 0 ) ;
if ( F_23 () ) {
F_103 ( V_678 , 0 ) ;
if ( F_24 ( V_73 -> V_8 . V_17 ) )
F_103 ( V_678 ,
F_68 ( V_73 -> V_8 . V_116 . V_278 -> V_413 ) ) ;
F_102 ( V_679 , 0 ) ;
}
if ( F_48 ( V_73 -> V_8 . V_17 ) )
F_103 ( V_680 ,
F_347 ( V_73 -> V_8 . V_17 -> V_116 . V_586 ) ) ;
if ( F_321 ( V_8 -> V_17 ) )
memset ( & V_73 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_73 -> V_52 != 0 )
F_101 ( V_681 , V_73 -> V_52 ) ;
V_73 -> V_8 . V_116 . V_229 = V_682 | V_683 | V_684 ;
F_277 ( & V_73 -> V_8 , F_348 ( V_8 ) ) ;
F_275 ( & V_73 -> V_8 , 0 ) ;
F_262 ( & V_73 -> V_8 , 0 ) ;
F_163 ( & V_73 -> V_8 ) ;
F_122 ( & V_73 -> V_8 ) ;
F_89 ( V_73 ) ;
}
static bool F_349 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_312 ;
}
static bool F_350 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_685 &
V_323 ;
}
static bool F_351 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_313 ;
}
static void F_352 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_527 ) ;
V_69 |= V_340 ;
F_102 ( V_527 , V_69 ) ;
}
static void F_353 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () ||
F_94 ( V_251 ) & V_252 ) {
F_352 ( V_8 ) ;
return;
}
V_69 = F_94 ( V_527 ) ;
V_69 |= V_341 ;
F_102 ( V_527 , V_69 ) ;
}
static void F_354 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_15 V_686 ;
int V_687 = V_8 -> V_116 . V_688 . V_152 ;
F_355 ( V_687 ) ;
++ V_8 -> V_217 . V_689 ;
if ( V_73 -> V_136 . V_137 ) {
int V_267 = 0 ;
if ( V_8 -> V_116 . V_688 . V_690 )
V_267 = V_8 -> V_116 . V_268 ;
if ( F_182 ( V_8 , V_687 , V_267 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
V_686 = V_687 | V_22 ;
if ( V_8 -> V_116 . V_688 . V_690 ) {
V_686 |= V_691 ;
F_102 ( V_271 ,
V_73 -> V_8 . V_116 . V_268 ) ;
} else
V_686 |= V_27 ;
F_102 ( V_273 , V_686 ) ;
}
static void F_356 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_123 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_73 -> V_663 = 1 ;
V_73 -> V_692 = 0 ;
}
++ V_8 -> V_217 . V_693 ;
V_73 -> V_694 = false ;
if ( V_73 -> V_136 . V_137 ) {
if ( F_182 ( V_8 , V_695 , 0 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
F_102 ( V_273 ,
V_696 | V_22 | V_695 ) ;
}
static bool F_357 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_663 ;
if ( F_6 ( V_8 ) -> V_694 )
return false ;
return F_94 ( V_251 ) & V_697 ;
}
static void F_358 ( struct V_7 * V_8 , bool V_698 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_73 -> V_663 != V_698 ) {
V_73 -> V_663 = V_698 ;
V_73 -> V_692 = 0 ;
}
} else {
V_73 -> V_694 = ! V_698 ;
if ( V_698 )
F_105 ( V_251 ,
V_697 ) ;
else
F_104 ( V_251 ,
V_697 ) ;
}
}
static int F_359 ( struct V_7 * V_8 )
{
if ( F_6 ( V_8 ) -> V_13 . V_699 )
return 0 ;
if ( ! F_52 () && F_6 ( V_8 ) -> V_663 )
return 0 ;
return ! ( F_94 ( V_251 ) &
( V_254 | V_252
| V_697 ) ) ;
}
static int F_360 ( struct V_7 * V_8 )
{
return ( ! F_6 ( V_8 ) -> V_13 . V_699 &&
F_92 ( V_246 ) & V_700 ) &&
! ( F_94 ( V_251 ) &
( V_252 | V_254 ) ) ;
}
static int F_361 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_114 ;
struct V_583 V_701 = {
. V_587 = V_702 ,
. V_589 = V_16 ,
. V_590 = V_443 * 3 ,
. V_482 = 0 ,
} ;
V_114 = F_362 ( V_17 , & V_701 ) ;
if ( V_114 )
return V_114 ;
V_17 -> V_116 . V_501 = V_16 ;
if ( ! F_296 ( V_17 ) )
return - V_461 ;
return 0 ;
}
static bool F_363 ( struct V_7 * V_8 , int V_703 )
{
switch ( V_703 ) {
case V_135 :
F_6 ( V_8 ) -> V_8 . V_116 . V_268 =
F_94 ( V_258 ) ;
if ( V_8 -> V_132 & V_134 )
return false ;
case V_131 :
if ( V_8 -> V_132 &
( V_704 | V_705 ) )
return false ;
case V_706 :
case V_707 :
case V_708 :
case V_26 :
case V_709 :
case V_710 :
case V_711 :
case V_712 :
return true ;
break;
}
return false ;
}
static int F_364 ( struct V_7 * V_8 ,
int V_703 , T_2 V_713 )
{
if ( ( ( V_703 == V_711 ) || ( V_703 == V_710 ) ) && V_713 == 0 ) {
if ( F_365 ( V_8 , 0 ) == V_269 ) {
if ( V_8 -> V_116 . V_714 ) {
V_8 -> V_116 . V_714 = 0 ;
return F_366 ( V_8 ) ;
}
return 1 ;
}
return 0 ;
}
F_367 ( V_8 , V_703 ) ;
return 1 ;
}
static void F_368 ( void )
{
#if F_369 ( V_715 ) && F_369 ( F_96 )
struct V_716 V_413 = {
. V_556 = 3 ,
. V_482 = V_700 ,
} ;
F_370 ( & V_413 , 0 ) ;
#endif
}
static int F_371 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_372 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_717 * V_717 = V_8 -> V_718 ;
T_2 V_19 , V_719 , V_263 ;
unsigned long V_720 , V_257 , V_721 ;
T_2 V_722 ;
enum V_723 V_724 ;
V_722 = V_73 -> V_725 ;
V_19 = V_73 -> V_726 ;
if ( F_21 ( V_19 ) )
return F_371 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_696 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_163 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_724 = F_365 ( V_8 , V_727 ) ;
if ( V_724 != V_269 )
F_367 ( V_8 , V_26 ) ;
return 1 ;
}
V_263 = 0 ;
if ( V_19 & V_266 )
V_263 = F_94 ( V_728 ) ;
if ( ( V_722 & V_729 ) &&
! ( F_17 ( V_19 ) && ! ( V_263 & V_730 ) ) ) {
V_8 -> V_718 -> V_259 = V_731 ;
V_8 -> V_718 -> V_732 . V_733 = V_734 ;
V_8 -> V_718 -> V_732 . V_735 = 2 ;
V_8 -> V_718 -> V_732 . V_183 [ 0 ] = V_722 ;
V_8 -> V_718 -> V_732 . V_183 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_373 ( V_101 ) ;
V_720 = F_92 ( V_261 ) ;
F_374 ( V_720 , V_263 ) ;
if ( F_375 ( V_8 ) )
F_376 ( V_8 , V_720 ) ;
return F_377 ( V_8 , V_720 , V_263 , NULL , 0 ) ;
}
V_719 = V_19 & V_21 ;
if ( V_73 -> V_136 . V_137 && F_363 ( V_8 , V_719 ) )
return F_364 ( V_8 , V_719 , V_263 ) ;
switch ( V_719 ) {
case V_131 :
V_721 = F_92 ( V_261 ) ;
if ( ! ( V_8 -> V_132 &
( V_704 | V_705 ) ) ) {
V_8 -> V_116 . V_721 &= ~ 15 ;
V_8 -> V_116 . V_721 |= V_721 | V_736 ;
if ( ! ( V_721 & ~ V_737 ) )
F_175 ( V_8 ) ;
F_367 ( V_8 , V_131 ) ;
return 1 ;
}
V_717 -> V_738 . V_116 . V_721 = V_721 | V_739 ;
V_717 -> V_738 . V_116 . V_740 = F_92 ( V_741 ) ;
case V_135 :
V_73 -> V_8 . V_116 . V_268 =
F_94 ( V_258 ) ;
V_717 -> V_259 = V_742 ;
V_257 = F_176 ( V_8 ) ;
V_717 -> V_738 . V_116 . V_743 = F_92 ( V_668 ) + V_257 ;
V_717 -> V_738 . V_116 . V_744 = V_719 ;
break;
default:
V_717 -> V_259 = V_745 ;
V_717 -> V_746 . V_744 = V_719 ;
V_717 -> V_746 . V_263 = V_263 ;
break;
}
return 0 ;
}
static int F_378 ( struct V_7 * V_8 )
{
++ V_8 -> V_217 . V_747 ;
return 1 ;
}
static int F_379 ( struct V_7 * V_8 )
{
V_8 -> V_718 -> V_259 = V_748 ;
return 0 ;
}
static int F_380 ( struct V_7 * V_8 )
{
unsigned long V_749 ;
int V_444 , V_750 , string ;
unsigned V_751 ;
V_749 = F_92 ( V_261 ) ;
string = ( V_749 & 16 ) != 0 ;
V_750 = ( V_749 & 8 ) != 0 ;
++ V_8 -> V_217 . V_752 ;
if ( string || V_750 )
return F_365 ( V_8 , 0 ) == V_269 ;
V_751 = V_749 >> 16 ;
V_444 = ( V_749 & 7 ) + 1 ;
F_175 ( V_8 ) ;
return F_381 ( V_8 , V_444 , V_751 ) ;
}
static void
F_382 ( struct V_7 * V_8 , unsigned char * V_753 )
{
V_753 [ 0 ] = 0x0f ;
V_753 [ 1 ] = 0x01 ;
V_753 [ 2 ] = 0xc1 ;
}
static bool F_383 ( struct V_12 * V_12 , unsigned long V_106 )
{
unsigned long V_754 = F_209 ;
if ( V_359 &
V_56 &&
F_58 ( V_12 , V_56 ) )
V_754 &= ~ ( V_532 | V_526 ) ;
return ( V_106 & V_754 ) == V_754 ;
}
static int F_384 ( struct V_7 * V_8 , unsigned long V_106 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_755 = V_106 ;
V_106 = ( V_106 & ~ V_12 -> V_234 ) |
( V_12 -> V_237 & V_12 -> V_234 ) ;
if ( ! F_383 ( V_12 , V_106 ) )
return 1 ;
if ( F_385 ( V_8 , V_106 ) )
return 1 ;
F_99 ( V_242 , V_755 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_544 &&
( ( V_106 & F_209 ) != F_209 ) )
return 1 ;
return F_385 ( V_8 , V_106 ) ;
}
}
static int F_386 ( struct V_7 * V_8 , unsigned long V_106 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_755 = V_106 ;
V_106 = ( V_106 & ~ V_12 -> V_240 ) |
( V_12 -> V_239 & V_12 -> V_240 ) ;
if ( F_387 ( V_8 , V_106 ) )
return 1 ;
F_99 ( V_491 , V_755 ) ;
return 0 ;
} else
return F_387 ( V_8 , V_106 ) ;
}
static void F_388 ( struct V_7 * V_8 )
{
if ( F_123 ( V_8 ) ) {
F_99 ( V_242 ,
F_92 ( V_242 ) & ~ V_231 ) ;
V_8 -> V_116 . V_229 &= ~ V_231 ;
} else
F_277 ( V_8 , F_164 ( V_8 , ~ V_231 ) ) ;
}
static int F_389 ( struct V_7 * V_8 )
{
unsigned long V_749 , V_106 ;
int V_756 ;
int V_411 ;
int V_757 ;
V_749 = F_92 ( V_261 ) ;
V_756 = V_749 & 15 ;
V_411 = ( V_749 >> 8 ) & 15 ;
switch ( ( V_749 >> 4 ) & 3 ) {
case 0 :
V_106 = F_390 ( V_8 , V_411 ) ;
F_391 ( V_756 , V_106 ) ;
switch ( V_756 ) {
case 0 :
V_757 = F_384 ( V_8 , V_106 ) ;
F_392 ( V_8 , V_757 ) ;
return 1 ;
case 3 :
V_757 = F_393 ( V_8 , V_106 ) ;
F_392 ( V_8 , V_757 ) ;
return 1 ;
case 4 :
V_757 = F_386 ( V_8 , V_106 ) ;
F_392 ( V_8 , V_757 ) ;
return 1 ;
case 8 : {
T_6 V_758 = F_394 ( V_8 ) ;
T_6 V_759 = ( T_6 ) V_106 ;
V_757 = F_344 ( V_8 , V_759 ) ;
F_392 ( V_8 , V_757 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_758 <= V_759 )
return 1 ;
V_8 -> V_718 -> V_259 = V_760 ;
return 0 ;
}
}
break;
case 2 :
F_388 ( V_8 ) ;
F_391 ( 0 , F_348 ( V_8 ) ) ;
F_175 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_756 ) {
case 3 :
V_106 = F_279 ( V_8 ) ;
F_395 ( V_8 , V_411 , V_106 ) ;
F_396 ( V_756 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
case 8 :
V_106 = F_394 ( V_8 ) ;
F_395 ( V_8 , V_411 , V_106 ) ;
F_396 ( V_756 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_106 = ( V_749 >> V_761 ) & 0x0f ;
F_391 ( 0 , ( F_348 ( V_8 ) & ~ 0xful ) | V_106 ) ;
F_397 ( V_8 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_718 -> V_259 = 0 ;
F_398 ( V_8 , L_20 ,
( int ) ( V_749 >> 4 ) & 3 , V_756 ) ;
return 0 ;
}
static int F_399 ( struct V_7 * V_8 )
{
unsigned long V_749 ;
int V_762 , V_411 ;
if ( ! F_400 ( V_8 , 0 ) )
return 1 ;
V_762 = F_92 ( V_741 ) ;
if ( V_762 & V_763 ) {
if ( V_8 -> V_132 & V_705 ) {
V_8 -> V_718 -> V_738 . V_116 . V_721 = V_8 -> V_116 . V_721 ;
V_8 -> V_718 -> V_738 . V_116 . V_740 = V_762 ;
V_8 -> V_718 -> V_738 . V_116 . V_743 =
F_92 ( V_668 ) +
F_92 ( V_416 ) ;
V_8 -> V_718 -> V_738 . V_116 . V_744 = V_131 ;
V_8 -> V_718 -> V_259 = V_742 ;
return 0 ;
} else {
V_8 -> V_116 . V_740 &= ~ V_763 ;
V_8 -> V_116 . V_721 |= V_764 | V_736 ;
F_99 ( V_741 , V_8 -> V_116 . V_740 ) ;
F_367 ( V_8 , V_131 ) ;
return 1 ;
}
}
if ( V_8 -> V_132 == 0 ) {
T_2 V_69 ;
V_69 = F_94 ( V_527 ) ;
V_69 &= ~ V_349 ;
F_102 ( V_527 , V_69 ) ;
V_8 -> V_116 . V_629 |= V_630 ;
return 1 ;
}
V_749 = F_92 ( V_261 ) ;
V_762 = V_749 & V_765 ;
V_411 = F_401 ( V_749 ) ;
if ( V_749 & V_766 ) {
unsigned long V_106 ;
if ( F_402 ( V_8 , V_762 , & V_106 ) )
return 1 ;
F_395 ( V_8 , V_411 , V_106 ) ;
} else
if ( F_403 ( V_8 , V_762 , F_390 ( V_8 , V_411 ) ) )
return 1 ;
F_175 ( V_8 ) ;
return 1 ;
}
static T_3 F_404 ( struct V_7 * V_8 )
{
return V_8 -> V_116 . V_721 ;
}
static void F_405 ( struct V_7 * V_8 , unsigned long V_106 )
{
}
static void F_406 ( struct V_7 * V_8 )
{
T_2 V_69 ;
F_407 ( V_8 -> V_116 . V_496 [ 0 ] , 0 ) ;
F_407 ( V_8 -> V_116 . V_496 [ 1 ] , 1 ) ;
F_407 ( V_8 -> V_116 . V_496 [ 2 ] , 2 ) ;
F_407 ( V_8 -> V_116 . V_496 [ 3 ] , 3 ) ;
F_407 ( V_8 -> V_116 . V_721 , 6 ) ;
V_8 -> V_116 . V_740 = F_92 ( V_741 ) ;
V_8 -> V_116 . V_629 &= ~ V_630 ;
V_69 = F_94 ( V_527 ) ;
V_69 |= V_349 ;
F_102 ( V_527 , V_69 ) ;
}
static void F_408 ( struct V_7 * V_8 , unsigned long V_106 )
{
F_99 ( V_741 , V_106 ) ;
}
static int F_409 ( struct V_7 * V_8 )
{
F_410 ( V_8 ) ;
return 1 ;
}
static int F_411 ( struct V_7 * V_8 )
{
T_2 V_306 = V_8 -> V_116 . V_413 [ V_767 ] ;
T_3 V_183 ;
if ( F_211 ( V_8 , V_306 , & V_183 ) ) {
F_412 ( V_306 ) ;
F_413 ( V_8 , 0 ) ;
return 1 ;
}
F_414 ( V_306 , V_183 ) ;
V_8 -> V_116 . V_413 [ V_768 ] = V_183 & - 1u ;
V_8 -> V_116 . V_413 [ V_664 ] = ( V_183 >> 32 ) & - 1u ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_415 ( struct V_7 * V_8 )
{
struct V_401 V_74 ;
T_2 V_306 = V_8 -> V_116 . V_413 [ V_767 ] ;
T_3 V_183 = ( V_8 -> V_116 . V_413 [ V_768 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_116 . V_413 [ V_664 ] & - 1u ) << 32 ) ;
V_74 . V_183 = V_183 ;
V_74 . V_79 = V_306 ;
V_74 . V_409 = false ;
if ( F_213 ( V_8 , & V_74 ) != 0 ) {
F_416 ( V_306 , V_183 ) ;
F_413 ( V_8 , 0 ) ;
return 1 ;
}
F_417 ( V_306 , V_183 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_418 ( struct V_7 * V_8 )
{
F_156 ( V_600 , V_8 ) ;
return 1 ;
}
static int F_419 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_527 ) ;
V_69 &= ~ V_340 ;
F_102 ( V_527 , V_69 ) ;
F_156 ( V_600 , V_8 ) ;
++ V_8 -> V_217 . V_769 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_718 -> V_770 &&
! F_420 ( V_8 ) ) {
V_8 -> V_718 -> V_259 = V_771 ;
return 0 ;
}
return 1 ;
}
static int F_421 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
return F_366 ( V_8 ) ;
}
static int F_422 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_423 ( V_8 ) ;
return 1 ;
}
static int F_424 ( struct V_7 * V_8 )
{
return F_365 ( V_8 , 0 ) == V_269 ;
}
static int F_425 ( struct V_7 * V_8 )
{
unsigned long V_749 = F_92 ( V_261 ) ;
F_426 ( V_8 , V_749 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_427 ( struct V_7 * V_8 )
{
int V_757 ;
V_757 = F_428 ( V_8 ) ;
F_392 ( V_8 , V_757 ) ;
return 1 ;
}
static int F_429 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_430 ( V_8 ) ;
return 1 ;
}
static int F_431 ( struct V_7 * V_8 )
{
T_3 V_772 = F_432 ( V_8 ) ;
T_2 V_79 = F_433 ( V_8 , V_767 ) ;
if ( F_434 ( V_8 , V_79 , V_772 ) == 0 )
F_175 ( V_8 ) ;
return 1 ;
}
static int F_435 ( struct V_7 * V_8 )
{
if ( F_302 ( V_773 ) ) {
unsigned long V_749 = F_92 ( V_261 ) ;
int V_774 , V_299 ;
V_774 = V_749 & V_775 ;
V_299 = V_749 & V_776 ;
if ( ( V_774 == V_777 ) &&
( V_299 == V_778 ) ) {
F_436 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
}
return F_365 ( V_8 , 0 ) == V_269 ;
}
static int F_437 ( struct V_7 * V_8 )
{
unsigned long V_749 = F_92 ( V_261 ) ;
int V_4 = V_749 & 0xff ;
F_438 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_439 ( struct V_7 * V_8 )
{
unsigned long V_749 = F_92 ( V_261 ) ;
T_2 V_299 = V_749 & 0xfff ;
F_440 ( V_8 , V_299 ) ;
return 1 ;
}
static int F_441 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_749 ;
bool V_262 = false ;
T_2 V_263 = 0 ;
T_4 V_779 ;
int V_780 , type , V_781 , V_782 ;
V_781 = ( V_73 -> V_725 & V_729 ) ;
V_782 = ( V_73 -> V_725 & V_783 ) ;
type = ( V_73 -> V_725 & V_784 ) ;
V_749 = F_92 ( V_261 ) ;
V_780 = ( T_2 ) V_749 >> 30 ;
if ( V_780 == V_785 && V_781 ) {
switch ( type ) {
case V_696 :
V_8 -> V_116 . V_786 = false ;
F_358 ( V_8 , true ) ;
break;
case V_27 :
case V_691 :
F_442 ( V_8 ) ;
break;
case V_23 :
if ( V_73 -> V_725 &
V_787 ) {
V_262 = true ;
V_263 =
F_94 ( V_788 ) ;
}
case V_272 :
F_443 ( V_8 ) ;
break;
default:
break;
}
}
V_779 = V_749 ;
if ( ! V_781 || ( type != V_23 &&
type != V_27 &&
type != V_696 ) )
F_175 ( V_8 ) ;
if ( F_444 ( V_8 , V_779 ,
type == V_691 ? V_782 : - 1 , V_780 ,
V_262 , V_263 ) == V_789 ) {
V_8 -> V_718 -> V_259 = V_731 ;
V_8 -> V_718 -> V_732 . V_733 = V_790 ;
V_8 -> V_718 -> V_732 . V_735 = 0 ;
return 0 ;
}
F_99 ( V_741 , F_92 ( V_741 ) & ~ 0x55 ) ;
return 1 ;
}
static int F_445 ( struct V_7 * V_8 )
{
unsigned long V_749 ;
T_1 V_85 ;
T_2 V_263 ;
int V_791 ;
V_749 = F_92 ( V_261 ) ;
V_791 = ( V_749 >> 7 ) & 0x3 ;
if ( V_791 != 0x3 && V_791 != 0x1 && V_791 != 0 ) {
F_69 ( V_89 L_21 ) ;
F_69 ( V_89 L_22 ,
( long unsigned int ) F_95 ( V_792 ) ,
F_92 ( V_793 ) ) ;
F_69 ( V_89 L_23 ,
( long unsigned int ) V_749 ) ;
V_8 -> V_718 -> V_259 = V_794 ;
V_8 -> V_718 -> V_795 . V_796 = V_797 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_725 & V_729 ) &&
F_52 () &&
( V_749 & V_798 ) )
F_105 ( V_251 , V_697 ) ;
V_85 = F_95 ( V_792 ) ;
F_374 ( V_85 , V_749 ) ;
V_263 = V_749 & ( 1U << 1 ) ;
V_263 |= ( V_749 & ( 1U << 2 ) ) << 2 ;
V_263 |= ( V_749 >> 3 ) & 0x1 ;
V_8 -> V_116 . V_749 = V_749 ;
return F_377 ( V_8 , V_85 , V_263 , NULL , 0 ) ;
}
static T_3 F_446 ( T_3 V_799 , int V_800 )
{
int V_75 ;
T_3 V_105 = 0 ;
for ( V_75 = 51 ; V_75 > V_448 . V_801 ; V_75 -- )
V_105 |= ( 1ULL << V_75 ) ;
if ( V_800 > 2 )
V_105 |= 0xf8 ;
else if ( V_800 == 2 ) {
if ( V_799 & ( 1ULL << 7 ) )
V_105 |= 0x1ff000 ;
else
V_105 |= 0x78 ;
}
return V_105 ;
}
static void F_447 ( struct V_7 * V_8 , T_3 V_799 ,
int V_800 )
{
F_69 ( V_89 L_24 , V_509 , V_799 , V_800 ) ;
F_448 ( ( V_799 & 0x7 ) == 0x2 ) ;
F_448 ( ( V_799 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_448 ( ( V_799 & 0x7 ) == 0x4 ) ;
if ( ( V_799 & 0x7 ) ) {
T_3 V_802 = V_799 & F_446 ( V_799 , V_800 ) ;
if ( V_802 != 0 ) {
F_69 ( V_89 L_25 ,
V_509 , V_802 ) ;
F_448 ( 1 ) ;
}
if ( V_800 == 1 || ( V_800 == 2 && ( V_799 & ( 1ULL << 7 ) ) ) ) {
T_3 V_803 = ( V_799 & 0x38 ) >> 3 ;
if ( V_803 == 2 || V_803 == 3 ||
V_803 == 7 ) {
F_69 ( V_89 L_26 ,
V_509 , V_803 ) ;
F_448 ( 1 ) ;
}
}
}
}
static int F_449 ( struct V_7 * V_8 )
{
T_3 V_804 [ 4 ] ;
int V_805 , V_75 , V_114 ;
T_1 V_85 ;
V_85 = F_95 ( V_792 ) ;
if ( ! F_450 ( V_8 -> V_17 , V_806 , V_85 , 0 , NULL ) ) {
F_175 ( V_8 ) ;
return 1 ;
}
V_114 = F_451 ( V_8 , V_85 , true ) ;
if ( F_302 ( V_114 == V_807 ) )
return F_452 ( V_8 , V_85 , 0 , NULL , 0 ) ==
V_269 ;
if ( F_100 ( V_114 == V_808 ) )
return F_377 ( V_8 , V_85 , 0 , NULL , 0 ) ;
if ( F_100 ( V_114 == V_809 ) )
return 1 ;
F_69 ( V_89 L_27 ) ;
F_69 ( V_89 L_28 , V_85 ) ;
V_805 = F_453 ( V_8 , V_85 , V_804 ) ;
for ( V_75 = V_810 ; V_75 > V_810 - V_805 ; -- V_75 )
F_447 ( V_8 , V_804 [ V_75 - 1 ] , V_75 ) ;
V_8 -> V_718 -> V_259 = V_794 ;
V_8 -> V_718 -> V_795 . V_796 = V_811 ;
return 0 ;
}
static int F_454 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_527 ) ;
V_69 &= ~ V_341 ;
F_102 ( V_527 , V_69 ) ;
++ V_8 -> V_217 . V_812 ;
F_156 ( V_600 , V_8 ) ;
return 1 ;
}
static int F_455 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
enum V_723 V_757 = V_269 ;
int V_114 = 1 ;
T_2 V_813 ;
bool V_814 ;
unsigned V_815 = 130 ;
V_813 = F_94 ( V_527 ) ;
V_814 = V_813 & V_340 ;
while ( V_73 -> F_252 && V_815 -- != 0 ) {
if ( V_814 && F_360 ( V_8 ) )
return F_419 ( & V_73 -> V_8 ) ;
if ( F_170 ( V_600 , & V_8 -> V_816 ) )
return 1 ;
V_757 = F_365 ( V_8 , V_817 ) ;
if ( V_757 == V_818 ) {
++ V_8 -> V_217 . V_819 ;
V_114 = 0 ;
goto V_550;
}
if ( V_757 != V_269 ) {
V_8 -> V_718 -> V_259 = V_731 ;
V_8 -> V_718 -> V_732 . V_733 = V_790 ;
V_8 -> V_718 -> V_732 . V_735 = 0 ;
return 0 ;
}
if ( V_8 -> V_116 . V_714 ) {
V_8 -> V_116 . V_714 = 0 ;
V_114 = F_366 ( V_8 ) ;
goto V_550;
}
if ( F_456 ( V_820 ) )
goto V_550;
if ( F_457 () )
F_458 () ;
}
V_550:
return V_114 ;
}
static int F_459 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_460 ( V_8 ) ;
return 1 ;
}
static int F_461 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
return 1 ;
}
static int F_462 ( struct V_7 * V_8 )
{
F_128 ( V_166 L_29 ) ;
return F_461 ( V_8 ) ;
}
static int F_463 ( struct V_7 * V_8 )
{
F_128 ( V_166 L_30 ) ;
return F_461 ( V_8 ) ;
}
static struct V_90 * F_464 ( struct V_6 * V_73 )
{
struct V_821 * V_822 ;
F_80 (item, &vmx->nested.vmcs02_pool, list)
if ( V_822 -> V_823 == V_73 -> V_13 . V_824 ) {
F_465 ( & V_822 -> V_825 , & V_73 -> V_13 . V_826 ) ;
return & V_822 -> V_827 ;
}
if ( V_73 -> V_13 . V_828 >= F_466 ( V_829 , 1 ) ) {
V_822 = F_467 ( V_73 -> V_13 . V_826 . V_830 ,
struct V_821 , V_825 ) ;
V_822 -> V_823 = V_73 -> V_13 . V_824 ;
F_465 ( & V_822 -> V_825 , & V_73 -> V_13 . V_826 ) ;
return & V_822 -> V_827 ;
}
V_822 = F_468 ( sizeof( struct V_821 ) , V_453 ) ;
if ( ! V_822 )
return NULL ;
V_822 -> V_827 . V_87 = F_239 () ;
if ( ! V_822 -> V_827 . V_87 ) {
F_469 ( V_822 ) ;
return NULL ;
}
F_70 ( & V_822 -> V_827 ) ;
V_822 -> V_823 = V_73 -> V_13 . V_824 ;
F_159 ( & ( V_822 -> V_825 ) , & ( V_73 -> V_13 . V_826 ) ) ;
V_73 -> V_13 . V_828 ++ ;
return & V_822 -> V_827 ;
}
static void F_470 ( struct V_6 * V_73 , T_1 V_823 )
{
struct V_821 * V_822 ;
F_80 (item, &vmx->nested.vmcs02_pool, list)
if ( V_822 -> V_823 == V_823 ) {
F_242 ( & V_822 -> V_827 ) ;
F_83 ( & V_822 -> V_825 ) ;
F_469 ( V_822 ) ;
V_73 -> V_13 . V_828 -- ;
return;
}
}
static void F_471 ( struct V_6 * V_73 )
{
struct V_821 * V_822 , * V_425 ;
F_448 ( V_73 -> V_90 != & V_73 -> V_831 ) ;
F_229 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_73 -> V_90 == & V_822 -> V_827 )
continue;
F_242 ( & V_822 -> V_827 ) ;
F_83 ( & V_822 -> V_825 ) ;
F_469 ( V_822 ) ;
V_73 -> V_13 . V_828 -- ;
}
}
static void F_472 ( struct V_7 * V_8 )
{
F_172 ( V_8 , F_169 ( V_8 )
& ~ ( V_832 | V_833 | V_834 |
V_835 | V_836 | V_837 ) ) ;
}
static void F_473 ( struct V_7 * V_8 )
{
F_172 ( V_8 , ( F_169 ( V_8 )
& ~ ( V_833 | V_834 | V_835 |
V_836 | V_837 ) )
| V_832 ) ;
}
static void F_474 ( struct V_7 * V_8 ,
T_2 V_838 )
{
if ( F_6 ( V_8 ) -> V_13 . V_824 == - 1ull ) {
F_473 ( V_8 ) ;
return;
}
F_172 ( V_8 , ( F_169 ( V_8 )
& ~ ( V_832 | V_833 | V_834 |
V_836 | V_837 ) )
| V_835 ) ;
F_9 ( V_8 ) -> V_838 = V_838 ;
}
static enum V_839 F_475 ( struct V_840 * V_841 )
{
struct V_6 * V_73 =
F_7 ( V_841 , struct V_6 , V_13 . V_842 ) ;
V_73 -> V_13 . V_843 = true ;
F_156 ( V_600 , & V_73 -> V_8 ) ;
F_325 ( & V_73 -> V_8 ) ;
return V_844 ;
}
static int F_476 ( struct V_7 * V_8 ,
unsigned long V_749 ,
T_2 V_845 , T_5 * V_114 )
{
int V_846 = V_845 & 3 ;
int V_847 = ( V_845 >> 7 ) & 7 ;
bool V_848 = V_845 & ( 1u << 10 ) ;
int V_849 = ( V_845 >> 15 ) & 7 ;
int V_850 = ( V_845 >> 18 ) & 0xf ;
bool V_851 = ! ( V_845 & ( 1u << 22 ) ) ;
int V_852 = ( V_845 >> 23 ) & 0xf ;
bool V_853 = ! ( V_845 & ( 1u << 27 ) ) ;
if ( V_848 ) {
F_367 ( V_8 , V_26 ) ;
return 1 ;
}
* V_114 = F_280 ( V_8 , V_849 ) ;
if ( V_853 )
* V_114 += F_433 ( V_8 , V_852 ) ;
if ( V_851 )
* V_114 += F_433 ( V_8 , V_850 ) << V_846 ;
* V_114 += V_749 ;
if ( V_847 == 1 )
* V_114 &= 0xffffffff ;
return 0 ;
}
static int F_477 ( struct V_7 * V_8 , int V_259 ,
T_1 * V_854 )
{
T_5 V_81 ;
T_1 V_823 ;
struct V_855 V_856 ;
struct V_15 * V_15 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_857 = F_478 ( V_8 ) ;
if ( F_476 ( V_8 , F_92 ( V_261 ) ,
F_94 ( V_858 ) , & V_81 ) )
return 1 ;
if ( F_479 ( & V_8 -> V_116 . V_859 , V_81 , & V_823 ,
sizeof( V_823 ) , & V_856 ) ) {
F_480 ( V_8 , & V_856 ) ;
return 1 ;
}
switch ( V_259 ) {
case V_860 :
if ( ! F_481 ( V_823 ) || ( V_823 >> V_857 ) ) {
F_473 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
V_15 = F_10 ( V_8 , V_823 ) ;
if ( V_15 == NULL ||
* ( T_2 * ) F_482 ( V_15 ) != V_372 ) {
F_473 ( V_8 ) ;
F_483 ( V_15 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_483 ( V_15 ) ;
V_73 -> V_13 . V_861 = V_823 ;
break;
case V_862 :
if ( ! F_481 ( V_823 ) || ( V_823 >> V_857 ) ) {
F_474 ( V_8 ,
V_863 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_823 == V_73 -> V_13 . V_861 ) {
F_474 ( V_8 ,
V_864 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
case V_865 :
if ( ! F_481 ( V_823 ) || ( V_823 >> V_857 ) ) {
F_474 ( V_8 ,
V_866 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_823 == V_73 -> V_13 . V_861 ) {
F_474 ( V_8 ,
V_864 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
default:
return 1 ;
}
if ( V_854 )
* V_854 = V_823 ;
return 0 ;
}
static int F_484 ( struct V_7 * V_8 )
{
struct V_476 V_556 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_87 * V_867 ;
const T_3 V_868 = V_408
| V_419 ;
if ( ! F_485 ( V_8 , V_423 ) ||
! F_164 ( V_8 , V_532 ) ||
( F_169 ( V_8 ) & V_249 ) ) {
F_367 ( V_8 , V_26 ) ;
return 1 ;
}
F_257 ( V_8 , & V_556 , V_478 ) ;
if ( F_140 ( V_8 ) && ! V_556 . V_498 ) {
F_367 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_281 ( V_8 ) ) {
F_413 ( V_8 , 0 ) ;
return 1 ;
}
if ( F_477 ( V_8 , V_860 , NULL ) )
return 1 ;
if ( V_73 -> V_13 . V_544 ) {
F_474 ( V_8 , V_869 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( ( V_73 -> V_13 . V_399 & V_868 )
!= V_868 ) {
F_413 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_464 ) {
V_867 = F_239 () ;
if ( ! V_867 )
return - V_461 ;
V_867 -> V_446 |= ( 1u << 31 ) ;
F_67 ( V_867 ) ;
V_73 -> V_13 . V_870 = V_867 ;
}
F_225 ( & ( V_73 -> V_13 . V_826 ) ) ;
V_73 -> V_13 . V_828 = 0 ;
F_486 ( & V_73 -> V_13 . V_842 , V_871 ,
V_872 ) ;
V_73 -> V_13 . V_842 . V_873 = F_475 ;
V_73 -> V_13 . V_544 = true ;
F_175 ( V_8 ) ;
F_472 ( V_8 ) ;
return 1 ;
}
static int F_487 ( struct V_7 * V_8 )
{
struct V_476 V_556 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! V_73 -> V_13 . V_544 ) {
F_367 ( V_8 , V_26 ) ;
return 0 ;
}
F_257 ( V_8 , & V_556 , V_478 ) ;
if ( ( F_169 ( V_8 ) & V_249 ) ||
( F_140 ( V_8 ) && ! V_556 . V_498 ) ) {
F_367 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_281 ( V_8 ) ) {
F_413 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_488 ( struct V_6 * V_73 )
{
T_2 V_628 ;
if ( V_73 -> V_13 . V_824 == - 1ull )
return;
if ( F_448 ( V_73 -> V_13 . V_14 == NULL ) )
return;
if ( V_464 ) {
F_489 ( V_73 ) ;
V_73 -> V_13 . V_874 = false ;
V_628 = F_94 ( V_640 ) ;
V_628 &= ~ V_67 ;
F_102 ( V_640 , V_628 ) ;
F_103 ( V_638 , - 1ull ) ;
}
F_483 ( V_73 -> V_13 . V_875 ) ;
F_13 ( V_73 -> V_13 . V_875 ) ;
V_73 -> V_13 . V_824 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
}
static void F_490 ( struct V_6 * V_73 )
{
if ( ! V_73 -> V_13 . V_544 )
return;
V_73 -> V_13 . V_544 = false ;
F_488 ( V_73 ) ;
if ( V_464 )
F_240 ( V_73 -> V_13 . V_870 ) ;
if ( V_73 -> V_13 . V_586 ) {
F_13 ( V_73 -> V_13 . V_586 ) ;
V_73 -> V_13 . V_586 = 0 ;
}
F_471 ( V_73 ) ;
}
static int F_491 ( struct V_7 * V_8 )
{
if ( ! F_487 ( V_8 ) )
return 1 ;
F_490 ( F_6 ( V_8 ) ) ;
F_175 ( V_8 ) ;
F_472 ( V_8 ) ;
return 1 ;
}
static int F_492 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_1 V_823 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
if ( ! F_487 ( V_8 ) )
return 1 ;
if ( F_477 ( V_8 , V_862 , & V_823 ) )
return 1 ;
if ( V_823 == V_73 -> V_13 . V_824 )
F_488 ( V_73 ) ;
V_15 = F_10 ( V_8 , V_823 ) ;
if ( V_15 == NULL ) {
F_156 ( V_270 , V_8 ) ;
return 1 ;
}
V_12 = F_482 ( V_15 ) ;
V_12 -> V_876 = 0 ;
F_483 ( V_15 ) ;
F_13 ( V_15 ) ;
F_470 ( V_73 , V_823 ) ;
F_175 ( V_8 ) ;
F_472 ( V_8 ) ;
return 1 ;
}
static int F_493 ( struct V_7 * V_8 )
{
return F_494 ( V_8 , true ) ;
}
static int F_495 ( struct V_7 * V_8 )
{
return F_494 ( V_8 , false ) ;
}
static inline int F_496 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_877 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_497 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_498 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_114 )
{
short V_299 = F_8 ( V_9 ) ;
char * V_119 ;
if ( V_299 < 0 )
return 0 ;
V_119 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_299 ;
switch ( F_496 ( V_9 ) ) {
case V_878 :
* V_114 = * ( ( V_879 * ) V_119 ) ;
return 1 ;
case V_880 :
* V_114 = * ( ( T_4 * ) V_119 ) ;
return 1 ;
case V_877 :
* V_114 = * ( ( T_2 * ) V_119 ) ;
return 1 ;
case V_881 :
* V_114 = * ( ( T_3 * ) V_119 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_499 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_882 ) {
short V_299 = F_8 ( V_9 ) ;
char * V_119 = ( ( char * ) F_9 ( V_8 ) ) + V_299 ;
if ( V_299 < 0 )
return false ;
switch ( F_496 ( V_9 ) ) {
case V_880 :
* ( T_4 * ) V_119 = V_882 ;
return true ;
case V_877 :
* ( T_2 * ) V_119 = V_882 ;
return true ;
case V_881 :
* ( T_3 * ) V_119 = V_882 ;
return true ;
case V_878 :
* ( V_879 * ) V_119 = V_882 ;
return true ;
default:
return false ;
}
}
static void F_489 ( struct V_6 * V_73 )
{
int V_75 ;
unsigned long V_9 ;
T_3 V_882 ;
struct V_87 * V_867 = V_73 -> V_13 . V_870 ;
const unsigned long * V_236 = V_456 ;
const int V_883 = V_455 ;
F_71 ( V_867 ) ;
for ( V_75 = 0 ; V_75 < V_883 ; V_75 ++ ) {
V_9 = V_236 [ V_75 ] ;
switch ( F_496 ( V_9 ) ) {
case V_880 :
V_882 = F_93 ( V_9 ) ;
break;
case V_877 :
V_882 = F_94 ( V_9 ) ;
break;
case V_881 :
V_882 = F_95 ( V_9 ) ;
break;
case V_878 :
V_882 = F_92 ( V_9 ) ;
break;
}
F_499 ( & V_73 -> V_8 , V_9 , V_882 ) ;
}
F_67 ( V_867 ) ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
}
static void F_500 ( struct V_6 * V_73 )
{
const unsigned long * V_236 [] = {
V_456 ,
V_460
} ;
const int V_884 [] = {
V_455 ,
V_459
} ;
int V_75 , V_885 ;
unsigned long V_9 ;
T_3 V_882 = 0 ;
struct V_87 * V_867 = V_73 -> V_13 . V_870 ;
F_71 ( V_867 ) ;
for ( V_885 = 0 ; V_885 < F_339 ( V_236 ) ; V_885 ++ ) {
for ( V_75 = 0 ; V_75 < V_884 [ V_885 ] ; V_75 ++ ) {
V_9 = V_236 [ V_885 ] [ V_75 ] ;
F_498 ( & V_73 -> V_8 , V_9 , & V_882 ) ;
switch ( F_496 ( V_9 ) ) {
case V_880 :
F_101 ( V_9 , ( T_4 ) V_882 ) ;
break;
case V_877 :
F_102 ( V_9 , ( T_2 ) V_882 ) ;
break;
case V_881 :
F_103 ( V_9 , ( T_3 ) V_882 ) ;
break;
case V_878 :
F_99 ( V_9 , ( long ) V_882 ) ;
break;
}
}
}
F_67 ( V_867 ) ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
}
static int F_501 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( V_73 -> V_13 . V_824 == - 1ull ) {
F_473 ( V_8 ) ;
F_175 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_502 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_882 ;
unsigned long V_749 = F_92 ( V_261 ) ;
T_2 V_845 = F_94 ( V_858 ) ;
T_5 V_81 = 0 ;
if ( ! F_487 ( V_8 ) ||
! F_501 ( V_8 ) )
return 1 ;
V_9 = F_390 ( V_8 , ( ( ( V_845 ) >> 28 ) & 0xf ) ) ;
if ( ! F_498 ( V_8 , V_9 , & V_882 ) ) {
F_474 ( V_8 , V_886 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_845 & ( 1u << 10 ) ) {
F_503 ( V_8 , ( ( ( V_845 ) >> 3 ) & 0xf ) ,
V_882 ) ;
} else {
if ( F_476 ( V_8 , V_749 ,
V_845 , & V_81 ) )
return 1 ;
F_504 ( & V_8 -> V_116 . V_859 , V_81 ,
& V_882 , ( F_140 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_472 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_505 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_81 ;
unsigned long V_749 = F_92 ( V_261 ) ;
T_2 V_845 = F_94 ( V_858 ) ;
T_3 V_882 = 0 ;
struct V_855 V_856 ;
if ( ! F_487 ( V_8 ) ||
! F_501 ( V_8 ) )
return 1 ;
if ( V_845 & ( 1u << 10 ) )
V_882 = F_390 ( V_8 ,
( ( ( V_845 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_476 ( V_8 , V_749 ,
V_845 , & V_81 ) )
return 1 ;
if ( F_479 ( & V_8 -> V_116 . V_859 , V_81 ,
& V_882 , ( F_506 ( V_8 ) ? 8 : 4 ) , & V_856 ) ) {
F_480 ( V_8 , & V_856 ) ;
return 1 ;
}
}
V_9 = F_390 ( V_8 , ( ( ( V_845 ) >> 28 ) & 0xf ) ) ;
if ( F_497 ( V_9 ) ) {
F_474 ( V_8 ,
V_887 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( ! F_499 ( V_8 , V_9 , V_882 ) ) {
F_474 ( V_8 , V_886 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_472 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_507 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_1 V_823 ;
T_2 V_628 ;
if ( ! F_487 ( V_8 ) )
return 1 ;
if ( F_477 ( V_8 , V_865 , & V_823 ) )
return 1 ;
if ( V_73 -> V_13 . V_824 != V_823 ) {
struct V_12 * V_888 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_823 ) ;
if ( V_15 == NULL ) {
F_473 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
V_888 = F_482 ( V_15 ) ;
if ( V_888 -> V_446 != V_372 ) {
F_483 ( V_15 ) ;
F_15 ( V_15 ) ;
F_474 ( V_8 ,
V_889 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_488 ( V_73 ) ;
V_73 -> V_13 . V_824 = V_823 ;
V_73 -> V_13 . V_14 = V_888 ;
V_73 -> V_13 . V_875 = V_15 ;
if ( V_464 ) {
V_628 = F_94 ( V_640 ) ;
V_628 |= V_67 ;
F_102 ( V_640 , V_628 ) ;
F_103 ( V_638 ,
F_68 ( V_73 -> V_13 . V_870 ) ) ;
V_73 -> V_13 . V_874 = true ;
}
}
F_472 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_508 ( struct V_7 * V_8 )
{
unsigned long V_749 = F_92 ( V_261 ) ;
T_2 V_845 = F_94 ( V_858 ) ;
T_5 V_890 ;
struct V_855 V_856 ;
if ( ! F_487 ( V_8 ) )
return 1 ;
if ( F_476 ( V_8 , V_749 ,
V_845 , & V_890 ) )
return 1 ;
if ( F_504 ( & V_8 -> V_116 . V_859 , V_890 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_824 ,
sizeof( T_3 ) , & V_856 ) ) {
F_480 ( V_8 , & V_856 ) ;
return 1 ;
}
F_472 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_509 ( struct V_7 * V_8 )
{
T_2 V_845 , V_891 ;
unsigned long type ;
T_5 V_81 ;
struct V_855 V_856 ;
struct {
T_3 V_84 , V_85 ;
} V_83 ;
if ( ! ( V_359 & V_55 ) ||
! ( V_360 & V_361 ) ) {
F_367 ( V_8 , V_26 ) ;
return 1 ;
}
if ( ! F_487 ( V_8 ) )
return 1 ;
if ( ! F_164 ( V_8 , V_532 ) ) {
F_367 ( V_8 , V_26 ) ;
return 1 ;
}
V_845 = F_94 ( V_858 ) ;
type = F_390 ( V_8 , ( V_845 >> 28 ) & 0xf ) ;
V_891 = ( V_360 >> V_892 ) & 6 ;
if ( ! ( V_891 & ( 1UL << type ) ) ) {
F_474 ( V_8 ,
V_893 ) ;
return 1 ;
}
if ( F_476 ( V_8 , F_92 ( V_261 ) ,
V_845 , & V_81 ) )
return 1 ;
if ( F_479 ( & V_8 -> V_116 . V_859 , V_81 , & V_83 ,
sizeof( V_83 ) , & V_856 ) ) {
F_480 ( V_8 , & V_856 ) ;
return 1 ;
}
switch ( type ) {
case V_100 :
F_510 ( V_8 ) ;
F_511 ( V_8 ) ;
F_472 ( V_8 ) ;
break;
default:
F_373 ( 1 ) ;
break;
}
F_175 ( V_8 ) ;
return 1 ;
}
static bool F_512 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_749 ;
T_1 V_894 , V_895 ;
unsigned int V_751 ;
int V_444 ;
T_6 V_896 ;
if ( ! F_57 ( V_12 , V_351 ) )
return F_57 ( V_12 , V_350 ) ;
V_749 = F_92 ( V_261 ) ;
V_751 = V_749 >> 16 ;
V_444 = ( V_749 & 7 ) + 1 ;
V_895 = ( T_1 ) - 1 ;
V_896 = - 1 ;
while ( V_444 > 0 ) {
if ( V_751 < 0x8000 )
V_894 = V_12 -> V_897 ;
else if ( V_751 < 0x10000 )
V_894 = V_12 -> V_898 ;
else
return 1 ;
V_894 += ( V_751 & 0x7fff ) / 8 ;
if ( V_895 != V_894 )
if ( F_513 ( V_8 -> V_17 , V_894 , & V_896 , 1 ) )
return 1 ;
if ( V_896 & ( 1 << ( V_751 & 7 ) ) )
return 1 ;
V_751 ++ ;
V_444 -- ;
V_895 = V_894 ;
}
return 0 ;
}
static bool F_514 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_259 )
{
T_2 V_369 = V_8 -> V_116 . V_413 [ V_767 ] ;
T_1 V_894 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_894 = V_12 -> V_277 ;
if ( V_259 == V_899 )
V_894 += 2048 ;
if ( V_369 >= 0xc0000000 ) {
V_369 -= 0xc0000000 ;
V_894 += 1024 ;
}
if ( V_369 < 1024 * 8 ) {
unsigned char V_896 ;
if ( F_513 ( V_8 -> V_17 , V_894 + V_369 / 8 , & V_896 , 1 ) )
return 1 ;
return 1 & ( V_896 >> ( V_369 & 7 ) ) ;
} else
return 1 ;
}
static bool F_515 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_749 = F_92 ( V_261 ) ;
int V_756 = V_749 & 15 ;
int V_411 = ( V_749 >> 8 ) & 15 ;
unsigned long V_106 = F_390 ( V_8 , V_411 ) ;
switch ( ( V_749 >> 4 ) & 3 ) {
case 0 :
switch ( V_756 ) {
case 0 :
if ( V_12 -> V_234 &
( V_106 ^ V_12 -> V_238 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_900 >= 1 &&
V_12 -> V_901 == V_106 ) ||
( V_12 -> V_900 >= 2 &&
V_12 -> V_902 == V_106 ) ||
( V_12 -> V_900 >= 3 &&
V_12 -> V_903 == V_106 ) ||
( V_12 -> V_900 >= 4 &&
V_12 -> V_904 == V_106 ) )
return 0 ;
if ( F_57 ( V_12 , V_345 ) )
return 1 ;
break;
case 4 :
if ( V_12 -> V_240 &
( V_12 -> V_241 ^ V_106 ) )
return 1 ;
break;
case 8 :
if ( F_57 ( V_12 , V_347 ) )
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
switch ( V_756 ) {
case 3 :
if ( V_12 -> V_69 &
V_346 )
return 1 ;
break;
case 8 :
if ( V_12 -> V_69 &
V_348 )
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
static bool F_516 ( struct V_7 * V_8 )
{
T_2 V_19 = F_94 ( V_260 ) ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_259 = V_73 -> V_259 ;
F_517 ( F_176 ( V_8 ) , V_259 ,
F_92 ( V_261 ) ,
V_73 -> V_725 ,
V_19 ,
F_94 ( V_728 ) ,
V_905 ) ;
if ( V_73 -> V_13 . V_699 )
return 0 ;
if ( F_100 ( V_73 -> V_906 ) ) {
F_518 ( L_31 , V_509 ,
F_94 ( V_104 ) ) ;
return 1 ;
}
switch ( V_259 ) {
case V_907 :
if ( ! F_62 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_101 ;
else if ( F_18 ( V_19 ) &&
! ( V_12 -> V_237 & V_231 ) )
return 0 ;
return V_12 -> V_139 &
( 1u << ( V_19 & V_21 ) ) ;
case V_908 :
return 0 ;
case V_909 :
return 1 ;
case V_910 :
return F_57 ( V_12 , V_340 ) ;
case V_911 :
return F_57 ( V_12 , V_341 ) ;
case V_912 :
return 1 ;
case V_913 :
return 1 ;
case V_914 :
return F_57 ( V_12 , V_342 ) ;
case V_915 :
return 1 ;
case V_916 :
return F_57 ( V_12 , V_343 ) ;
case V_917 :
return F_57 ( V_12 , V_353 ) ;
case V_918 :
return F_57 ( V_12 , V_354 ) ;
case V_919 : case V_862 :
case V_920 : case V_865 :
case V_921 : case V_922 :
case V_923 : case V_924 :
case V_925 : case V_860 :
case V_926 :
return 1 ;
case V_927 :
return F_515 ( V_8 , V_12 ) ;
case V_928 :
return F_57 ( V_12 , V_349 ) ;
case V_929 :
return F_512 ( V_8 , V_12 ) ;
case V_930 :
case V_899 :
return F_514 ( V_8 , V_12 , V_259 ) ;
case V_931 :
return 1 ;
case V_932 :
return F_57 ( V_12 , V_344 ) ;
case V_933 :
return F_57 ( V_12 , V_352 ) ;
case V_934 :
return F_57 ( V_12 , V_355 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_935 :
return 0 ;
case V_936 :
return 1 ;
case V_937 :
return F_58 ( V_12 ,
V_35 ) ;
case V_797 :
return 0 ;
case V_811 :
return 0 ;
case V_938 :
return F_58 ( V_12 , V_63 ) ;
case V_939 :
return 1 ;
default:
return 1 ;
}
}
static void F_519 ( struct V_7 * V_8 , T_3 * V_940 , T_3 * V_941 )
{
* V_940 = F_92 ( V_261 ) ;
* V_941 = F_94 ( V_260 ) ;
}
static int F_520 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_259 = V_73 -> V_259 ;
T_2 V_942 = V_73 -> V_725 ;
if ( V_73 -> F_252 )
return F_455 ( V_8 ) ;
if ( F_123 ( V_8 ) && F_516 ( V_8 ) ) {
F_179 ( V_8 , V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
return 1 ;
}
if ( V_259 & V_943 ) {
V_8 -> V_718 -> V_259 = V_944 ;
V_8 -> V_718 -> V_945 . V_946
= V_259 ;
return 0 ;
}
if ( F_100 ( V_73 -> V_906 ) ) {
V_8 -> V_718 -> V_259 = V_944 ;
V_8 -> V_718 -> V_945 . V_946
= F_94 ( V_104 ) ;
return 0 ;
}
if ( ( V_942 & V_729 ) &&
( V_259 != V_907 &&
V_259 != V_797 &&
V_259 != V_912 ) ) {
V_8 -> V_718 -> V_259 = V_731 ;
V_8 -> V_718 -> V_732 . V_733 = V_947 ;
V_8 -> V_718 -> V_732 . V_735 = 2 ;
V_8 -> V_718 -> V_732 . V_183 [ 0 ] = V_942 ;
V_8 -> V_718 -> V_732 . V_183 [ 1 ] = V_259 ;
return 0 ;
}
if ( F_100 ( ! F_52 () && V_73 -> V_663 &&
! ( F_123 ( V_8 ) && F_59 (
F_9 ( V_8 ) ) ) ) ) {
if ( F_360 ( V_8 ) ) {
V_73 -> V_663 = 0 ;
} else if ( V_73 -> V_692 > 1000000000LL &&
V_8 -> V_116 . V_948 ) {
F_69 ( V_166 L_32
L_33 ,
V_509 , V_8 -> V_301 ) ;
V_73 -> V_663 = 0 ;
}
}
if ( V_259 < V_949
&& V_950 [ V_259 ] )
return V_950 [ V_259 ] ( V_8 ) ;
else {
V_8 -> V_718 -> V_259 = V_794 ;
V_8 -> V_718 -> V_795 . V_796 = V_259 ;
}
return 0 ;
}
static void V_468 ( struct V_7 * V_8 , int V_951 , int V_952 )
{
if ( V_952 == - 1 || V_951 < V_952 ) {
F_102 ( V_679 , 0 ) ;
return;
}
F_102 ( V_679 , V_952 ) ;
}
static void F_521 ( struct V_7 * V_8 , bool V_953 )
{
T_2 V_954 ;
if ( ! F_28 () ||
! F_321 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_954 = F_94 ( V_640 ) ;
if ( V_953 ) {
V_954 &= ~ V_35 ;
V_954 |= V_36 ;
} else {
V_954 &= ~ V_36 ;
V_954 |= V_35 ;
}
F_102 ( V_640 , V_954 ) ;
F_186 ( V_8 ) ;
}
static void F_522 ( struct V_17 * V_17 , int V_955 )
{
T_4 V_956 ;
T_6 V_421 ;
if ( ! F_321 ( V_17 ) )
return;
if ( V_955 == - 1 )
V_955 = 0 ;
V_956 = F_93 ( V_645 ) ;
V_421 = V_956 >> 8 ;
if ( V_955 != V_421 ) {
V_956 &= 0xff ;
V_956 |= V_955 << 8 ;
F_101 ( V_645 , V_956 ) ;
}
}
static void F_523 ( int V_4 )
{
T_4 V_956 ;
T_6 V_421 ;
V_956 = F_93 ( V_645 ) ;
V_421 = ( T_6 ) V_956 & 0xff ;
if ( ( T_6 ) V_4 != V_421 ) {
V_956 &= ~ 0xff ;
V_956 |= ( T_6 ) V_4 ;
F_101 ( V_645 , V_956 ) ;
}
}
static void F_524 ( struct V_7 * V_8 , int V_957 )
{
if ( V_957 == - 1 )
return;
if ( F_123 ( V_8 ) && F_349 ( V_8 ) )
return;
if ( ! F_123 ( V_8 ) ) {
F_523 ( V_957 ) ;
return;
}
if ( ! F_375 ( V_8 ) &&
F_360 ( V_8 ) ) {
F_525 ( V_8 , V_957 , false ) ;
F_354 ( V_8 ) ;
}
}
static void F_526 ( struct V_7 * V_8 , T_3 * V_958 )
{
if ( ! F_321 ( V_8 -> V_17 ) )
return;
F_103 ( V_641 , V_958 [ 0 ] ) ;
F_103 ( V_642 , V_958 [ 1 ] ) ;
F_103 ( V_643 , V_958 [ 2 ] ) ;
F_103 ( V_644 , V_958 [ 3 ] ) ;
}
static void F_527 ( struct V_6 * V_73 )
{
T_2 V_726 ;
if ( ! ( V_73 -> V_259 == V_935
|| V_73 -> V_259 == V_907 ) )
return;
V_73 -> V_726 = F_94 ( V_260 ) ;
V_726 = V_73 -> V_726 ;
if ( F_21 ( V_726 ) )
F_368 () ;
if ( ( V_726 & V_20 ) == V_696 &&
( V_726 & V_22 ) ) {
F_528 ( & V_73 -> V_8 ) ;
asm("int $2");
F_529 ( & V_73 -> V_8 ) ;
}
}
static void F_530 ( struct V_7 * V_8 )
{
T_2 V_726 = F_94 ( V_260 ) ;
if ( ( V_726 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_141 ;
T_16 * V_959 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
#ifdef F_96
unsigned long V_276 ;
#endif
V_4 = V_726 & V_21 ;
V_959 = ( T_16 * ) V_73 -> V_619 + V_4 ;
V_141 = F_531 ( * V_959 ) ;
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
return ( V_29 . V_447 & V_324 ) &&
( V_29 . V_404 & V_333 ) ;
}
static void F_532 ( struct V_6 * V_73 )
{
T_2 V_726 ;
bool V_960 ;
T_6 V_4 ;
bool V_961 ;
V_961 = V_73 -> V_725 & V_729 ;
if ( F_52 () ) {
if ( V_73 -> V_694 )
return;
V_726 = F_94 ( V_260 ) ;
V_960 = ( V_726 & V_798 ) != 0 ;
V_4 = V_726 & V_21 ;
if ( ( V_726 & V_22 ) && V_960 &&
V_4 != V_709 && ! V_961 )
F_105 ( V_251 ,
V_697 ) ;
else
V_73 -> V_694 =
! ( F_94 ( V_251 )
& V_697 ) ;
} else if ( F_100 ( V_73 -> V_663 ) )
V_73 -> V_692 +=
F_533 ( F_534 ( F_535 () , V_73 -> V_962 ) ) ;
}
static void F_536 ( struct V_7 * V_8 ,
T_2 V_725 ,
int V_963 ,
int V_964 )
{
T_6 V_4 ;
int type ;
bool V_961 ;
V_961 = V_725 & V_729 ;
V_8 -> V_116 . V_786 = false ;
F_443 ( V_8 ) ;
F_442 ( V_8 ) ;
if ( ! V_961 )
return;
F_156 ( V_600 , V_8 ) ;
V_4 = V_725 & V_783 ;
type = V_725 & V_784 ;
switch ( type ) {
case V_696 :
V_8 -> V_116 . V_786 = true ;
F_358 ( V_8 , false ) ;
break;
case V_272 :
V_8 -> V_116 . V_268 = F_94 ( V_963 ) ;
case V_23 :
if ( V_725 & V_787 ) {
T_2 V_757 = F_94 ( V_964 ) ;
F_537 ( V_8 , V_4 , V_757 ) ;
} else
F_538 ( V_8 , V_4 ) ;
break;
case V_691 :
V_8 -> V_116 . V_268 = F_94 ( V_963 ) ;
case V_27 :
F_525 ( V_8 , V_4 , type == V_691 ) ;
break;
default:
break;
}
}
static void F_539 ( struct V_6 * V_73 )
{
F_536 ( & V_73 -> V_8 , V_73 -> V_725 ,
V_258 ,
V_788 ) ;
}
static void F_540 ( struct V_7 * V_8 )
{
F_536 ( V_8 ,
F_94 ( V_273 ) ,
V_271 ,
V_265 ) ;
F_102 ( V_273 , 0 ) ;
}
static void F_541 ( struct V_6 * V_73 )
{
int V_75 , V_965 ;
struct V_966 * V_967 ;
V_967 = F_542 ( & V_965 ) ;
if ( ! V_967 )
return;
for ( V_75 = 0 ; V_75 < V_965 ; V_75 ++ )
if ( V_967 [ V_75 ] . V_154 == V_967 [ V_75 ] . V_153 )
F_125 ( V_73 , V_967 [ V_75 ] . V_74 ) ;
else
F_127 ( V_73 , V_967 [ V_75 ] . V_74 , V_967 [ V_75 ] . V_153 ,
V_967 [ V_75 ] . V_154 ) ;
}
static void T_17 F_543 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_968 ;
if ( F_100 ( ! F_52 () && V_73 -> V_663 ) )
V_73 -> V_962 = F_535 () ;
if ( V_73 -> F_252 )
return;
if ( V_73 -> V_13 . V_874 ) {
F_500 ( V_73 ) ;
V_73 -> V_13 . V_874 = false ;
}
if ( F_170 ( V_412 , ( unsigned long * ) & V_8 -> V_116 . V_519 ) )
F_99 ( V_414 , V_8 -> V_116 . V_413 [ V_412 ] ) ;
if ( F_170 ( V_415 , ( unsigned long * ) & V_8 -> V_116 . V_519 ) )
F_99 ( V_416 , V_8 -> V_116 . V_413 [ V_415 ] ) ;
if ( V_8 -> V_132 & V_704 )
F_174 ( V_8 , 0 ) ;
F_541 ( V_73 ) ;
V_968 = F_544 () ;
V_73 -> V_969 = V_73 -> V_90 -> V_92 ;
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
if ( V_968 )
F_545 ( V_968 ) ;
#ifndef F_96
F_147 ( V_202 , V_970 ) ;
F_147 ( V_204 , V_970 ) ;
#endif
V_8 -> V_116 . V_117 = ~ ( ( 1 << V_415 ) | ( 1 << V_412 )
| ( 1 << V_245 )
| ( 1 << V_417 )
| ( 1 << V_118 )
| ( 1 << V_514 ) ) ;
V_8 -> V_116 . V_519 = 0 ;
V_73 -> V_725 = F_94 ( V_971 ) ;
V_73 -> V_90 -> V_92 = 1 ;
V_73 -> V_259 = F_94 ( V_972 ) ;
F_546 ( V_73 -> V_259 , V_8 , V_905 ) ;
if ( V_73 -> V_13 . V_699 )
F_156 ( V_600 , V_8 ) ;
V_73 -> V_13 . V_699 = 0 ;
F_527 ( V_73 ) ;
F_532 ( V_73 ) ;
F_539 ( V_73 ) ;
}
static void F_547 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_91 ;
if ( V_73 -> V_90 == & V_73 -> V_831 )
return;
V_91 = F_548 () ;
V_73 -> V_90 = & V_73 -> V_831 ;
F_161 ( V_8 ) ;
F_154 ( V_8 , V_91 ) ;
V_8 -> V_91 = V_91 ;
F_549 () ;
}
static void F_550 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_313 ( V_73 ) ;
F_551 ( V_8 ) ;
F_547 ( V_8 ) ;
F_490 ( V_73 ) ;
F_242 ( V_73 -> V_90 ) ;
F_469 ( V_73 -> V_78 ) ;
F_552 ( V_8 ) ;
F_553 ( V_973 , V_73 ) ;
}
static struct V_7 * F_554 ( struct V_17 * V_17 , unsigned int V_974 )
{
int V_757 ;
struct V_6 * V_73 = F_555 ( V_973 , V_453 ) ;
int V_91 ;
if ( ! V_73 )
return F_556 ( - V_461 ) ;
F_309 ( V_73 ) ;
V_757 = F_557 ( & V_73 -> V_8 , V_17 , V_974 ) ;
if ( V_757 )
goto V_975;
V_73 -> V_78 = F_468 ( V_443 , V_453 ) ;
F_558 ( F_339 ( V_77 ) * sizeof( V_73 -> V_78 [ 0 ] )
> V_443 ) ;
V_757 = - V_461 ;
if ( ! V_73 -> V_78 ) {
goto V_976;
}
V_73 -> V_90 = & V_73 -> V_831 ;
V_73 -> V_90 -> V_87 = F_239 () ;
if ( ! V_73 -> V_90 -> V_87 )
goto V_977;
if ( ! V_221 )
F_155 ( F_68 ( F_82 ( V_220 , F_79 () ) ) ) ;
F_70 ( V_73 -> V_90 ) ;
if ( ! V_221 )
F_162 () ;
V_91 = F_548 () ;
F_154 ( & V_73 -> V_8 , V_91 ) ;
V_73 -> V_8 . V_91 = V_91 ;
V_757 = F_338 ( V_73 ) ;
F_161 ( & V_73 -> V_8 ) ;
F_549 () ;
if ( V_757 )
goto F_240;
if ( F_48 ( V_17 ) ) {
V_757 = F_304 ( V_17 ) ;
if ( V_757 )
goto F_240;
}
if ( V_101 ) {
if ( ! V_17 -> V_116 . V_540 )
V_17 -> V_116 . V_540 =
V_978 ;
V_757 = - V_461 ;
if ( F_308 ( V_17 ) != 0 )
goto F_240;
if ( ! F_301 ( V_17 ) )
goto F_240;
}
V_73 -> V_13 . V_824 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
return & V_73 -> V_8 ;
F_240:
F_242 ( V_73 -> V_90 ) ;
V_977:
F_469 ( V_73 -> V_78 ) ;
V_976:
F_552 ( & V_73 -> V_8 ) ;
V_975:
F_313 ( V_73 ) ;
F_553 ( V_973 , V_73 ) ;
return F_556 ( V_757 ) ;
}
static void T_11 F_559 ( void * V_979 )
{
struct V_29 V_433 ;
* ( int * ) V_979 = 0 ;
if ( F_233 ( & V_433 ) < 0 )
* ( int * ) V_979 = - V_432 ;
if ( memcmp ( & V_29 , & V_433 , sizeof( struct V_29 ) ) != 0 ) {
F_69 ( V_89 L_34 ,
F_560 () ) ;
* ( int * ) V_979 = - V_432 ;
}
}
static int F_561 ( void )
{
return V_534 + 1 ;
}
static T_3 F_562 ( struct V_7 * V_8 , T_13 V_980 , bool V_981 )
{
T_3 V_114 ;
if ( V_981 )
V_114 = V_982 << V_983 ;
else if ( F_563 ( V_8 -> V_17 ) )
V_114 = F_564 ( V_8 , V_980 ) <<
V_983 ;
else
V_114 = ( V_984 << V_983 )
| V_985 ;
return V_114 ;
}
static int F_565 ( void )
{
if ( V_101 && ! F_38 () )
return V_986 ;
else
return V_987 ;
}
static void F_566 ( struct V_7 * V_8 )
{
struct V_304 * V_305 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_628 ;
V_73 -> V_288 = false ;
if ( F_183 () ) {
V_628 = F_94 ( V_640 ) ;
if ( V_628 & V_60 ) {
V_305 = F_201 ( V_8 , 0x80000001 , 0 ) ;
if ( V_305 && ( V_305 -> V_988 & V_68 ( V_989 ) ) )
V_73 -> V_288 = true ;
else {
V_628 &= ~ V_60 ;
F_102 ( V_640 ,
V_628 ) ;
}
}
}
V_305 = F_201 ( V_8 , 0x7 , 0 ) ;
if ( F_184 () &&
V_305 && ( V_305 -> V_990 & V_68 ( V_991 ) ) &&
F_567 ( V_8 ) ) {
V_628 = F_94 ( V_640 ) ;
V_628 |= V_61 ;
F_102 ( V_640 ,
V_628 ) ;
} else {
if ( F_26 () ) {
V_628 = F_94 ( V_640 ) ;
V_628 &= ~ V_61 ;
F_102 ( V_640 ,
V_628 ) ;
}
if ( V_305 )
V_305 -> V_990 &= ~ V_68 ( V_991 ) ;
}
}
static void F_568 ( T_2 V_992 , struct V_304 * V_141 )
{
if ( V_992 == 1 && V_13 )
V_141 -> V_306 |= V_68 ( V_307 ) ;
}
static void F_569 ( struct V_7 * V_8 ,
struct V_855 * V_993 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_259 ;
if ( V_993 -> V_263 & V_730 )
V_259 = V_811 ;
else
V_259 = V_797 ;
F_179 ( V_8 , V_259 , 0 , V_8 -> V_116 . V_749 ) ;
V_12 -> V_994 = V_993 -> V_172 ;
}
static unsigned long F_570 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_995 ;
}
static void F_571 ( struct V_7 * V_8 )
{
F_572 ( V_8 , & V_8 -> V_116 . V_510 ,
V_360 & V_43 ) ;
V_8 -> V_116 . V_510 . V_996 = F_278 ;
V_8 -> V_116 . V_510 . V_997 = F_570 ;
V_8 -> V_116 . V_510 . V_998 = F_569 ;
V_8 -> V_116 . V_518 = & V_8 -> V_116 . V_999 ;
}
static void F_573 ( struct V_7 * V_8 )
{
V_8 -> V_116 . V_518 = & V_8 -> V_116 . V_510 ;
}
static void F_574 ( struct V_7 * V_8 ,
struct V_855 * V_993 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_448 ( ! F_123 ( V_8 ) ) ;
if ( V_12 -> V_139 & ( 1u << V_24 ) )
F_179 ( V_8 , F_6 ( V_8 ) -> V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
else
F_480 ( V_8 , V_993 ) ;
}
static void F_575 ( struct V_7 * V_8 )
{
T_3 V_1000 = F_9 ( V_8 ) -> V_1001 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( V_8 -> V_116 . V_1002 == 0 )
return;
if ( V_1000 <= 1 ) {
F_475 ( & V_73 -> V_13 . V_842 ) ;
return;
}
V_1000 <<= V_365 ;
V_1000 *= 1000000 ;
F_576 ( V_1000 , V_8 -> V_116 . V_1002 ) ;
F_577 ( & V_73 -> V_13 . V_842 ,
F_578 ( V_1000 ) , V_872 ) ;
}
static void F_579 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_628 ;
F_101 ( V_1003 , V_12 -> V_1004 ) ;
F_101 ( V_667 , V_12 -> V_1005 ) ;
F_101 ( V_1006 , V_12 -> V_1007 ) ;
F_101 ( V_1008 , V_12 -> V_1009 ) ;
F_101 ( V_1010 , V_12 -> V_1011 ) ;
F_101 ( V_1012 , V_12 -> V_1013 ) ;
F_101 ( V_670 , V_12 -> V_1014 ) ;
F_101 ( V_669 , V_12 -> V_1015 ) ;
F_102 ( V_1016 , V_12 -> V_1017 ) ;
F_102 ( V_1018 , V_12 -> V_1019 ) ;
F_102 ( V_1020 , V_12 -> V_1021 ) ;
F_102 ( V_1022 , V_12 -> V_1023 ) ;
F_102 ( V_1024 , V_12 -> V_1025 ) ;
F_102 ( V_1026 , V_12 -> V_1027 ) ;
F_102 ( V_672 , V_12 -> V_1028 ) ;
F_102 ( V_503 , V_12 -> V_1029 ) ;
F_102 ( V_554 , V_12 -> V_1030 ) ;
F_102 ( V_552 , V_12 -> V_1031 ) ;
F_102 ( V_1032 , V_12 -> V_1033 ) ;
F_102 ( V_1034 , V_12 -> V_1035 ) ;
F_102 ( V_1036 , V_12 -> V_1037 ) ;
F_102 ( V_1038 , V_12 -> V_1039 ) ;
F_102 ( V_1040 , V_12 -> V_1041 ) ;
F_102 ( V_1042 , V_12 -> V_1043 ) ;
F_102 ( V_673 , V_12 -> V_1044 ) ;
F_102 ( V_505 , V_12 -> V_1045 ) ;
F_99 ( V_1046 , V_12 -> V_1047 ) ;
F_99 ( V_668 , V_12 -> V_1048 ) ;
F_99 ( V_1049 , V_12 -> V_1050 ) ;
F_99 ( V_1051 , V_12 -> V_1052 ) ;
F_99 ( V_389 , V_12 -> V_1053 ) ;
F_99 ( V_390 , V_12 -> V_1054 ) ;
F_99 ( V_671 , V_12 -> V_1055 ) ;
F_99 ( V_502 , V_12 -> V_1056 ) ;
F_99 ( V_555 , V_12 -> V_1057 ) ;
F_99 ( V_553 , V_12 -> V_1058 ) ;
if ( V_12 -> V_1059 & V_335 ) {
F_403 ( V_8 , 7 , V_12 -> V_1060 ) ;
F_103 ( V_677 , V_12 -> V_1061 ) ;
} else {
F_403 ( V_8 , 7 , V_8 -> V_116 . V_740 ) ;
F_103 ( V_677 , V_73 -> V_13 . V_1062 ) ;
}
F_102 ( V_273 ,
V_12 -> V_1063 ) ;
F_102 ( V_265 ,
V_12 -> V_1064 ) ;
F_102 ( V_271 ,
V_12 -> V_1065 ) ;
F_102 ( V_251 ,
V_12 -> V_1066 ) ;
F_102 ( V_393 , V_12 -> V_1067 ) ;
F_172 ( V_8 , V_12 -> V_1068 ) ;
F_99 ( V_676 ,
V_12 -> V_1069 ) ;
F_99 ( V_396 , V_12 -> V_1070 ) ;
F_99 ( V_395 , V_12 -> V_1071 ) ;
F_103 ( V_638 , - 1ull ) ;
V_628 = V_12 -> V_71 ;
V_628 |= V_29 . V_39 ;
V_628 &= ~ ( V_72 |
V_40 ) ;
F_102 ( V_639 , V_628 ) ;
V_73 -> V_13 . V_843 = false ;
if ( F_60 ( V_12 ) )
F_575 ( V_8 ) ;
F_102 ( V_651 ,
V_101 ? V_12 -> V_1072 : 0 ) ;
F_102 ( V_652 ,
V_101 ? V_12 -> V_1073 : 0 ) ;
if ( F_26 () ) {
V_628 = F_335 ( V_73 ) ;
if ( ! V_73 -> V_288 )
V_628 &= ~ V_60 ;
V_628 &= ~ ( V_35 |
V_38 |
V_37 ) ;
if ( F_57 ( V_12 ,
V_33 ) )
V_628 |= V_12 -> V_70 ;
if ( V_628 & V_35 ) {
if ( V_73 -> V_13 . V_586 )
F_13 ( V_73 -> V_13 . V_586 ) ;
V_73 -> V_13 . V_586 =
F_10 ( V_8 , V_12 -> V_1074 ) ;
if ( ! V_73 -> V_13 . V_586 )
V_628 &=
~ V_35 ;
else
F_103 ( V_680 ,
F_347 ( V_73 -> V_13 . V_586 ) ) ;
} else if ( F_48 ( V_73 -> V_8 . V_17 ) ) {
V_628 |=
V_35 ;
F_103 ( V_680 ,
F_347 ( V_8 -> V_17 -> V_116 . V_586 ) ) ;
}
F_102 ( V_640 , V_628 ) ;
}
F_328 ( V_73 ) ;
V_73 -> V_1075 = 0 ;
V_628 = F_334 ( V_73 ) ;
V_628 &= ~ V_340 ;
V_628 &= ~ V_341 ;
V_628 &= ~ V_32 ;
V_628 |= V_12 -> V_69 ;
V_628 &= ~ V_31 ;
V_628 &= ~ V_351 ;
V_628 |= V_350 ;
F_102 ( V_527 , V_628 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 &= ~ V_12 -> V_234 ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
F_102 ( V_109 , V_29 . V_447 ) ;
F_106 ( V_73 ,
( V_12 -> V_1059 & ~ V_146 &
~ V_331 ) |
( V_29 . V_404 & ~ V_331 ) ) ;
if ( V_12 -> V_1059 & V_332 ) {
F_103 ( V_405 , V_12 -> V_1076 ) ;
V_8 -> V_116 . V_406 = V_12 -> V_1076 ;
} else if ( V_29 . V_404 & V_332 )
F_103 ( V_405 , V_73 -> V_8 . V_116 . V_406 ) ;
F_332 ( V_73 ) ;
if ( V_12 -> V_1059 & V_333 )
F_103 ( V_397 , V_12 -> V_1077 ) ;
if ( V_12 -> V_69 & V_300 )
F_103 ( V_292 ,
V_73 -> V_13 . V_293 + V_12 -> V_291 ) ;
else
F_103 ( V_292 , V_73 -> V_13 . V_293 ) ;
if ( V_463 ) {
F_101 ( V_681 , V_73 -> V_52 ) ;
F_266 ( V_8 ) ;
}
if ( F_61 ( V_12 ) ) {
F_580 ( V_8 ) ;
F_571 ( V_8 ) ;
}
if ( V_12 -> V_1059 & V_146 )
V_8 -> V_116 . V_177 = V_12 -> V_1078 ;
else if ( V_12 -> V_1059 & V_331 )
V_8 -> V_116 . V_177 |= ( V_180 | V_181 ) ;
else
V_8 -> V_116 . V_177 &= ~ ( V_180 | V_181 ) ;
F_262 ( V_8 , V_8 -> V_116 . V_177 ) ;
F_277 ( V_8 , V_12 -> V_237 ) ;
F_99 ( V_242 , F_165 ( V_12 ) ) ;
F_275 ( V_8 , V_12 -> V_239 ) ;
F_99 ( V_491 , F_166 ( V_12 ) ) ;
F_393 ( V_8 , V_12 -> V_538 ) ;
F_261 ( V_8 ) ;
if ( ! V_101 )
V_8 -> V_116 . V_518 -> V_998 = F_574 ;
if ( V_101 ) {
F_103 ( V_520 , V_12 -> V_1079 ) ;
F_103 ( V_522 , V_12 -> V_1080 ) ;
F_103 ( V_523 , V_12 -> V_1081 ) ;
F_103 ( V_524 , V_12 -> V_1082 ) ;
}
F_395 ( V_8 , V_412 , V_12 -> V_1083 ) ;
F_395 ( V_8 , V_415 , V_12 -> V_1084 ) ;
}
static int F_494 ( struct V_7 * V_8 , bool V_1085 )
{
struct V_12 * V_12 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_91 ;
struct V_90 * V_827 ;
bool V_1086 ;
if ( ! F_487 ( V_8 ) ||
! F_501 ( V_8 ) )
return 1 ;
F_175 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_464 )
F_489 ( V_73 ) ;
if ( V_12 -> V_876 == V_1085 ) {
F_474 ( V_8 ,
V_1085 ? V_1087
: V_1088 ) ;
return 1 ;
}
if ( V_12 -> V_1089 != V_675 &&
V_12 -> V_1089 != V_1090 ) {
F_474 ( V_8 , V_1091 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_481 ( V_12 -> V_277 ) ) {
F_474 ( V_8 , V_1091 ) ;
return 1 ;
}
if ( F_58 ( V_12 , V_35 ) &&
! F_481 ( V_12 -> V_1074 ) ) {
F_474 ( V_8 , V_1091 ) ;
return 1 ;
}
if ( V_12 -> V_1092 > 0 ||
V_12 -> V_1093 > 0 ||
V_12 -> V_1094 > 0 ) {
F_581 ( L_35 ,
V_509 ) ;
F_474 ( V_8 , V_1091 ) ;
return 1 ;
}
if ( ! F_206 ( V_12 -> V_69 ,
V_356 ,
V_338 ) ||
! F_206 ( V_12 -> V_70 ,
V_358 , V_359 ) ||
! F_206 ( V_12 -> V_71 ,
V_309 , V_310 ) ||
! F_206 ( V_12 -> V_685 ,
V_325 ,
V_316 ) ||
! F_206 ( V_12 -> V_1059 ,
V_334 ,
V_329 ) )
{
F_474 ( V_8 , V_1091 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1095 & F_209 ) != F_209 ) ||
( ( V_12 -> V_1096 & F_210 ) != F_210 ) ) {
F_474 ( V_8 ,
V_1097 ) ;
return 1 ;
}
if ( ! F_383 ( V_12 , V_12 -> V_237 ) ||
( ( V_12 -> V_239 & F_210 ) != F_210 ) ) {
F_582 ( V_8 , V_12 ,
V_931 , V_1098 ) ;
return 1 ;
}
if ( V_12 -> V_1099 != - 1ull ) {
F_582 ( V_8 , V_12 ,
V_931 , V_1100 ) ;
return 1 ;
}
if ( V_12 -> V_1059 & V_146 ) {
V_1086 = ( V_12 -> V_1059 & V_331 ) != 0 ;
if ( ! F_583 ( V_8 , V_12 -> V_1078 ) ||
V_1086 != ! ! ( V_12 -> V_1078 & V_180 ) ||
( ( V_12 -> V_237 & V_526 ) &&
V_1086 != ! ! ( V_12 -> V_1078 & V_181 ) ) ) {
F_582 ( V_8 , V_12 ,
V_931 , V_1098 ) ;
return 1 ;
}
}
if ( V_12 -> V_685 & V_147 ) {
V_1086 = ( V_12 -> V_685 &
V_318 ) != 0 ;
if ( ! F_583 ( V_8 , V_12 -> V_1101 ) ||
V_1086 != ! ! ( V_12 -> V_1101 & V_180 ) ||
V_1086 != ! ! ( V_12 -> V_1101 & V_181 ) ) {
F_582 ( V_8 , V_12 ,
V_931 , V_1098 ) ;
return 1 ;
}
}
V_827 = F_464 ( V_73 ) ;
if ( ! V_827 )
return - V_461 ;
F_584 ( V_8 ) ;
V_73 -> V_13 . V_293 = F_95 ( V_292 ) ;
if ( ! ( V_12 -> V_1059 & V_335 ) )
V_73 -> V_13 . V_1062 = F_95 ( V_677 ) ;
V_91 = F_548 () ;
V_73 -> V_90 = V_827 ;
F_161 ( V_8 ) ;
F_154 ( V_8 , V_91 ) ;
V_8 -> V_91 = V_91 ;
F_549 () ;
F_116 ( V_73 ) ;
V_12 -> V_876 = 1 ;
F_579 ( V_8 , V_12 ) ;
if ( V_12 -> V_1089 == V_1090 )
return F_366 ( V_8 ) ;
V_73 -> V_13 . V_699 = 1 ;
return 1 ;
}
static inline unsigned long
F_585 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_92 ( V_230 ) & V_8 -> V_116 . V_233 ) |
( V_12 -> V_237 & V_12 -> V_234 ) |
( F_92 ( V_242 ) & ~ ( V_12 -> V_234 |
V_8 -> V_116 . V_233 ) ) ;
}
static inline unsigned long
F_586 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_92 ( V_489 ) & V_8 -> V_116 . V_515 ) |
( V_12 -> V_239 & V_12 -> V_240 ) |
( F_92 ( V_491 ) & ~ ( V_12 -> V_240 |
V_8 -> V_116 . V_515 ) ) ;
}
static void F_587 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1102 ;
unsigned int V_152 ;
if ( V_8 -> V_116 . V_744 . V_1103 && V_8 -> V_116 . V_744 . V_264 ) {
V_152 = V_8 -> V_116 . V_744 . V_152 ;
V_1102 = V_152 | V_729 ;
if ( F_181 ( V_152 ) ) {
V_12 -> V_1104 =
V_8 -> V_116 . V_268 ;
V_1102 |= V_272 ;
} else
V_1102 |= V_23 ;
if ( V_8 -> V_116 . V_744 . V_262 ) {
V_1102 |= V_787 ;
V_12 -> V_1105 =
V_8 -> V_116 . V_744 . V_263 ;
}
V_12 -> V_1106 = V_1102 ;
} else if ( V_8 -> V_116 . V_786 ) {
V_12 -> V_1106 =
V_696 | V_22 | V_695 ;
} else if ( V_8 -> V_116 . V_688 . V_1103 ) {
V_152 = V_8 -> V_116 . V_688 . V_152 ;
V_1102 = V_152 | V_729 ;
if ( V_8 -> V_116 . V_688 . V_690 ) {
V_1102 |= V_691 ;
V_12 -> V_1065 =
V_8 -> V_116 . V_268 ;
} else
V_1102 |= V_27 ;
V_12 -> V_1106 = V_1102 ;
}
}
static int F_588 ( struct V_7 * V_8 , bool V_1107 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_60 ( F_9 ( V_8 ) ) &&
V_73 -> V_13 . V_843 ) {
if ( V_73 -> V_13 . V_699 )
return - V_424 ;
F_179 ( V_8 , V_1108 , 0 , 0 ) ;
return 0 ;
}
if ( V_8 -> V_116 . V_948 && F_351 ( V_8 ) ) {
if ( V_73 -> V_13 . V_699 ||
V_8 -> V_116 . V_688 . V_1103 )
return - V_424 ;
F_179 ( V_8 , V_907 ,
V_695 | V_696 |
V_22 , 0 ) ;
V_8 -> V_116 . V_948 = 0 ;
F_358 ( V_8 , true ) ;
return 0 ;
}
if ( ( F_420 ( V_8 ) || V_1107 ) &&
F_349 ( V_8 ) ) {
if ( V_73 -> V_13 . V_699 )
return - V_424 ;
F_179 ( V_8 , V_908 , 0 , 0 ) ;
}
return 0 ;
}
static T_2 F_589 ( struct V_7 * V_8 )
{
T_18 V_1109 =
F_590 ( & F_6 ( V_8 ) -> V_13 . V_842 ) ;
T_3 V_103 ;
if ( F_533 ( V_1109 ) <= 0 )
return 0 ;
V_103 = F_533 ( V_1109 ) * V_8 -> V_116 . V_1002 ;
F_576 ( V_103 , 1000000 ) ;
return V_103 >> V_365 ;
}
static void F_591 ( struct V_7 * V_8 , struct V_12 * V_12 ,
T_2 V_259 , T_2 V_726 ,
unsigned long V_749 )
{
V_12 -> V_237 = F_585 ( V_8 , V_12 ) ;
V_12 -> V_239 = F_586 ( V_8 , V_12 ) ;
V_12 -> V_1083 = F_433 ( V_8 , V_412 ) ;
V_12 -> V_1084 = F_433 ( V_8 , V_415 ) ;
V_12 -> V_1068 = F_92 ( V_246 ) ;
V_12 -> V_1004 = F_93 ( V_1003 ) ;
V_12 -> V_1005 = F_93 ( V_667 ) ;
V_12 -> V_1007 = F_93 ( V_1006 ) ;
V_12 -> V_1009 = F_93 ( V_1008 ) ;
V_12 -> V_1011 = F_93 ( V_1010 ) ;
V_12 -> V_1013 = F_93 ( V_1012 ) ;
V_12 -> V_1014 = F_93 ( V_670 ) ;
V_12 -> V_1015 = F_93 ( V_669 ) ;
V_12 -> V_1017 = F_94 ( V_1016 ) ;
V_12 -> V_1019 = F_94 ( V_1018 ) ;
V_12 -> V_1021 = F_94 ( V_1020 ) ;
V_12 -> V_1023 = F_94 ( V_1022 ) ;
V_12 -> V_1025 = F_94 ( V_1024 ) ;
V_12 -> V_1027 = F_94 ( V_1026 ) ;
V_12 -> V_1028 = F_94 ( V_672 ) ;
V_12 -> V_1029 = F_94 ( V_503 ) ;
V_12 -> V_1030 = F_94 ( V_554 ) ;
V_12 -> V_1031 = F_94 ( V_552 ) ;
V_12 -> V_1033 = F_94 ( V_1032 ) ;
V_12 -> V_1035 = F_94 ( V_1034 ) ;
V_12 -> V_1037 = F_94 ( V_1036 ) ;
V_12 -> V_1039 = F_94 ( V_1038 ) ;
V_12 -> V_1041 = F_94 ( V_1040 ) ;
V_12 -> V_1043 = F_94 ( V_1042 ) ;
V_12 -> V_1044 = F_94 ( V_673 ) ;
V_12 -> V_1045 = F_94 ( V_505 ) ;
V_12 -> V_1047 = F_92 ( V_1046 ) ;
V_12 -> V_1048 = F_92 ( V_668 ) ;
V_12 -> V_1050 = F_92 ( V_1049 ) ;
V_12 -> V_1052 = F_92 ( V_1051 ) ;
V_12 -> V_1053 = F_92 ( V_389 ) ;
V_12 -> V_1054 = F_92 ( V_390 ) ;
V_12 -> V_1055 = F_92 ( V_671 ) ;
V_12 -> V_1056 = F_92 ( V_502 ) ;
V_12 -> V_1057 = F_92 ( V_555 ) ;
V_12 -> V_1058 = F_92 ( V_553 ) ;
V_12 -> V_1066 =
F_94 ( V_251 ) ;
V_12 -> V_1069 =
F_92 ( V_676 ) ;
if ( V_8 -> V_116 . V_1110 == V_1111 )
V_12 -> V_1089 = V_1090 ;
else
V_12 -> V_1089 = V_675 ;
if ( F_60 ( V_12 ) ) {
if ( V_12 -> V_685 &
V_322 )
V_12 -> V_1001 =
F_589 ( V_8 ) ;
F_592 ( & F_6 ( V_8 ) -> V_13 . V_842 ) ;
}
if ( V_101 ) {
V_12 -> V_538 = F_95 ( V_513 ) ;
V_12 -> V_1079 = F_95 ( V_520 ) ;
V_12 -> V_1080 = F_95 ( V_522 ) ;
V_12 -> V_1081 = F_95 ( V_523 ) ;
V_12 -> V_1082 = F_95 ( V_524 ) ;
}
V_12 -> V_1059 =
( V_12 -> V_1059 & ~ V_331 ) |
( F_108 ( F_6 ( V_8 ) ) & V_331 ) ;
if ( V_12 -> V_685 & V_326 ) {
F_402 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1060 ) ;
V_12 -> V_1061 = F_95 ( V_677 ) ;
}
if ( V_12 -> V_685 & V_320 )
V_12 -> V_1076 = F_95 ( V_405 ) ;
if ( V_12 -> V_685 & V_321 )
V_12 -> V_1078 = V_8 -> V_116 . V_177 ;
V_12 -> V_1067 = F_94 ( V_393 ) ;
V_12 -> V_1070 = F_92 ( V_396 ) ;
V_12 -> V_1071 = F_92 ( V_395 ) ;
if ( F_205 () )
V_12 -> V_1077 = F_95 ( V_397 ) ;
V_12 -> V_1112 = V_259 ;
V_12 -> V_749 = V_749 ;
V_12 -> V_1113 = V_726 ;
if ( ( V_12 -> V_1113 &
( V_22 | V_266 ) ) ==
( V_22 | V_266 ) )
V_12 -> V_1114 =
F_94 ( V_728 ) ;
V_12 -> V_1106 = 0 ;
V_12 -> V_1104 = F_94 ( V_258 ) ;
V_12 -> V_845 = F_94 ( V_858 ) ;
if ( ! ( V_12 -> V_1112 & V_943 ) ) {
V_12 -> V_1063 &= ~ V_22 ;
F_587 ( V_8 , V_12 ) ;
}
V_8 -> V_116 . V_786 = false ;
F_443 ( V_8 ) ;
F_442 ( V_8 ) ;
}
static void F_593 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_476 V_113 ;
if ( V_12 -> V_685 & V_147 )
V_8 -> V_116 . V_177 = V_12 -> V_1101 ;
else if ( V_12 -> V_685 & V_318 )
V_8 -> V_116 . V_177 |= ( V_180 | V_181 ) ;
else
V_8 -> V_116 . V_177 &= ~ ( V_180 | V_181 ) ;
F_262 ( V_8 , V_8 -> V_116 . V_177 ) ;
F_395 ( V_8 , V_412 , V_12 -> V_1075 ) ;
F_395 ( V_8 , V_415 , V_12 -> V_1115 ) ;
F_172 ( V_8 , V_1116 ) ;
F_277 ( V_8 , V_12 -> V_1095 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 = ( V_8 -> V_138 ? V_231 : 0 ) ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
V_8 -> V_116 . V_515 = ~ F_92 ( V_627 ) ;
F_387 ( V_8 , V_12 -> V_1096 ) ;
F_573 ( V_8 ) ;
F_393 ( V_8 , V_12 -> V_1117 ) ;
F_261 ( V_8 ) ;
if ( ! V_101 )
V_8 -> V_116 . V_518 -> V_998 = F_480 ;
if ( V_463 ) {
F_266 ( V_8 ) ;
}
F_102 ( V_393 , V_12 -> V_1118 ) ;
F_99 ( V_396 , V_12 -> V_1119 ) ;
F_99 ( V_395 , V_12 -> V_1120 ) ;
F_99 ( V_553 , V_12 -> V_1121 ) ;
F_99 ( V_555 , V_12 -> V_1122 ) ;
if ( V_12 -> V_685 & V_324 )
F_103 ( V_397 , 0 ) ;
if ( V_12 -> V_685 & V_319 ) {
F_103 ( V_405 , V_12 -> V_1123 ) ;
V_8 -> V_116 . V_406 = V_12 -> V_1123 ;
}
if ( V_12 -> V_685 & V_151 )
F_103 ( V_163 ,
V_12 -> V_1124 ) ;
V_113 = (struct V_476 ) {
. V_123 = 0 ,
. V_125 = 0xFFFFFFFF ,
. V_120 = V_12 -> V_1125 ,
. type = 11 ,
. V_497 = 1 ,
. V_187 = 1 ,
. V_495 = 1
} ;
if ( V_12 -> V_685 & V_318 )
V_113 . V_498 = 1 ;
else
V_113 . V_496 = 1 ;
F_255 ( V_8 , & V_113 , V_478 ) ;
V_113 = (struct V_476 ) {
. V_123 = 0 ,
. V_125 = 0xFFFFFFFF ,
. type = 3 ,
. V_497 = 1 ,
. V_187 = 1 ,
. V_496 = 1 ,
. V_495 = 1
} ;
V_113 . V_120 = V_12 -> V_1126 ;
F_255 ( V_8 , & V_113 , V_485 ) ;
V_113 . V_120 = V_12 -> V_1127 ;
F_255 ( V_8 , & V_113 , V_484 ) ;
V_113 . V_120 = V_12 -> V_1128 ;
F_255 ( V_8 , & V_113 , V_479 ) ;
V_113 . V_120 = V_12 -> V_1129 ;
V_113 . V_123 = V_12 -> V_1130 ;
F_255 ( V_8 , & V_113 , V_486 ) ;
V_113 . V_120 = V_12 -> V_1131 ;
V_113 . V_123 = V_12 -> V_1132 ;
F_255 ( V_8 , & V_113 , V_487 ) ;
V_113 = (struct V_476 ) {
. V_123 = V_12 -> V_1133 ,
. V_125 = 0x67 ,
. V_120 = V_12 -> V_1134 ,
. type = 11 ,
. V_497 = 1
} ;
F_255 ( V_8 , & V_113 , V_488 ) ;
F_403 ( V_8 , 7 , 0x400 ) ;
F_103 ( V_677 , 0 ) ;
}
static void F_179 ( struct V_7 * V_8 , T_2 V_259 ,
T_2 V_726 ,
unsigned long V_749 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_594 ( V_73 -> V_13 . V_699 ) ;
F_551 ( V_8 ) ;
F_591 ( V_8 , V_12 , V_259 , V_726 ,
V_749 ) ;
F_547 ( V_8 ) ;
if ( ( V_259 == V_908 )
&& F_350 ( V_8 ) ) {
int V_687 = F_595 ( V_8 ) ;
F_448 ( V_687 < 0 ) ;
V_12 -> V_1113 = V_687 |
V_22 | V_27 ;
}
F_596 ( V_12 -> V_1112 ,
V_12 -> V_749 ,
V_12 -> V_1106 ,
V_12 -> V_1113 ,
V_12 -> V_1114 ,
V_905 ) ;
F_106 ( V_73 , F_94 ( V_107 ) ) ;
F_111 ( V_73 , F_94 ( V_109 ) ) ;
F_116 ( V_73 ) ;
if ( V_829 == 0 )
F_470 ( V_73 , V_73 -> V_13 . V_824 ) ;
F_593 ( V_8 , V_12 ) ;
F_103 ( V_292 , V_73 -> V_13 . V_293 ) ;
V_73 -> V_1075 = 0 ;
if ( V_73 -> V_13 . V_586 ) {
F_13 ( V_73 -> V_13 . V_586 ) ;
V_73 -> V_13 . V_586 = 0 ;
}
if ( F_100 ( V_73 -> V_906 ) ) {
V_73 -> V_906 = 0 ;
F_474 ( V_8 , F_94 ( V_104 ) ) ;
} else
F_472 ( V_8 ) ;
if ( V_464 )
V_73 -> V_13 . V_874 = true ;
V_8 -> V_116 . V_1110 = V_1135 ;
}
static void F_216 ( struct V_7 * V_8 )
{
if ( F_123 ( V_8 ) )
F_179 ( V_8 , - 1 , 0 , 0 ) ;
F_490 ( F_6 ( V_8 ) ) ;
}
static void F_582 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_780 , unsigned long V_1136 )
{
F_593 ( V_8 , V_12 ) ;
V_12 -> V_1112 = V_780 | V_943 ;
V_12 -> V_749 = V_1136 ;
F_472 ( V_8 ) ;
if ( V_464 )
F_6 ( V_8 ) -> V_13 . V_874 = true ;
}
static int F_597 ( struct V_7 * V_8 ,
struct V_1137 * V_1138 ,
enum V_1139 V_1140 )
{
return V_1141 ;
}
static int T_11 F_598 ( void )
{
int V_567 , V_75 , V_74 ;
F_599 ( V_144 , & V_182 ) ;
for ( V_75 = 0 ; V_75 < F_339 ( V_77 ) ; ++ V_75 )
F_600 ( V_75 , V_77 [ V_75 ] ) ;
V_633 = ( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_633 )
return - V_461 ;
V_567 = - V_461 ;
V_635 = ( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_635 )
goto V_550;
V_282 = ( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_282 )
goto V_1142;
V_280 =
( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_280 )
goto V_1143;
V_281 = ( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_281 )
goto V_1144;
V_279 =
( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_279 )
goto V_1145;
V_458 = ( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_458 )
goto V_1146;
V_457 = ( unsigned long * ) F_601 ( V_453 ) ;
if ( ! V_457 )
goto V_1147;
memset ( V_458 , 0xff , V_443 ) ;
memset ( V_457 , 0xff , V_443 ) ;
memset ( V_633 , 0xff , V_443 ) ;
F_246 ( 0x80 , V_633 ) ;
memset ( V_635 , 0xff , V_443 ) ;
memset ( V_282 , 0xff , V_443 ) ;
memset ( V_281 , 0xff , V_443 ) ;
F_602 ( 0 , V_594 ) ;
V_567 = F_603 ( & V_1148 , sizeof( struct V_6 ) ,
F_604 ( struct V_6 ) , V_1149 ) ;
if ( V_567 )
goto V_1150;
#ifdef F_605
F_606 ( V_1151 ,
F_78 ) ;
#endif
F_317 ( V_207 , false ) ;
F_317 ( V_209 , false ) ;
F_317 ( V_210 , true ) ;
F_317 ( V_392 , false ) ;
F_317 ( V_227 , false ) ;
F_317 ( V_394 , false ) ;
F_317 ( V_214 , true ) ;
memcpy ( V_280 ,
V_282 , V_443 ) ;
memcpy ( V_279 ,
V_281 , V_443 ) ;
if ( V_470 ) {
for ( V_74 = 0x800 ; V_74 <= 0x8ff ; V_74 ++ )
F_319 ( V_74 ) ;
F_318 ( 0x802 ) ;
F_318 ( 0x839 ) ;
F_320 ( 0x808 ) ;
F_320 ( 0x80b ) ;
F_320 ( 0x83f ) ;
}
if ( V_101 ) {
F_607 ( 0ull ,
( V_466 ) ? V_1152 : 0ull ,
( V_466 ) ? V_1153 : 0ull ,
0ull , V_1154 ) ;
F_336 () ;
F_608 () ;
} else
F_609 () ;
return 0 ;
V_1150:
F_610 ( ( unsigned long ) V_457 ) ;
V_1147:
F_610 ( ( unsigned long ) V_458 ) ;
V_1146:
F_610 ( ( unsigned long ) V_279 ) ;
V_1145:
F_610 ( ( unsigned long ) V_281 ) ;
V_1144:
F_610 ( ( unsigned long ) V_280 ) ;
V_1143:
F_610 ( ( unsigned long ) V_282 ) ;
V_1142:
F_610 ( ( unsigned long ) V_635 ) ;
V_550:
F_610 ( ( unsigned long ) V_633 ) ;
return V_567 ;
}
static void T_12 F_611 ( void )
{
F_610 ( ( unsigned long ) V_280 ) ;
F_610 ( ( unsigned long ) V_279 ) ;
F_610 ( ( unsigned long ) V_282 ) ;
F_610 ( ( unsigned long ) V_281 ) ;
F_610 ( ( unsigned long ) V_635 ) ;
F_610 ( ( unsigned long ) V_633 ) ;
F_610 ( ( unsigned long ) V_457 ) ;
F_610 ( ( unsigned long ) V_458 ) ;
#ifdef F_605
F_606 ( V_1151 , NULL ) ;
F_612 () ;
#endif
F_613 () ;
}
