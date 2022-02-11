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
struct V_167 * V_168 = F_130 ( & V_169 ) ;
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
struct V_167 * V_168 = F_130 ( & V_169 ) ;
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
F_150 ( F_130 ( & V_169 ) ) ;
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
struct V_167 * V_168 = F_130 ( & V_169 ) ;
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
static T_3 F_191 ( struct V_7 * V_8 , T_3 V_290 )
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
V_355 | V_32 |
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
if ( ! F_216 ( V_8 , V_403 , V_183 ) )
return 1 ;
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
F_217 ( V_8 ) ;
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
T_3 V_410 = V_74 -> V_183 ;
V_74 -> V_183 = V_183 ;
if ( V_74 - V_73 -> V_78 < V_73 -> V_216 ) {
F_152 () ;
V_114 = F_143 ( V_74 -> V_79 , V_74 -> V_183 ,
V_74 -> V_105 ) ;
F_153 () ;
if ( V_114 )
V_74 -> V_183 = V_410 ;
}
break;
}
V_114 = F_214 ( V_8 , V_402 ) ;
}
return V_114 ;
}
static void F_218 ( struct V_7 * V_8 , enum V_411 V_412 )
{
F_171 ( V_412 , ( unsigned long * ) & V_8 -> V_116 . V_117 ) ;
switch ( V_412 ) {
case V_413 :
V_8 -> V_116 . V_414 [ V_413 ] = F_92 ( V_415 ) ;
break;
case V_416 :
V_8 -> V_116 . V_414 [ V_416 ] = F_92 ( V_417 ) ;
break;
case V_418 :
if ( V_101 )
F_219 ( V_8 ) ;
break;
default:
break;
}
}
static T_11 int F_220 ( void )
{
return F_221 () ;
}
static T_11 int F_222 ( void )
{
T_3 V_74 ;
F_55 ( V_398 , V_74 ) ;
if ( V_74 & V_408 ) {
if ( ! ( V_74 & V_419 )
&& F_223 () )
return 1 ;
if ( ! ( V_74 & V_420 )
&& ( V_74 & V_419 )
&& ! F_223 () ) {
F_69 ( V_166 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_74 & V_420 )
&& ! F_223 () )
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
static int F_224 ( void )
{
int V_91 = F_79 () ;
T_3 V_88 = F_68 ( F_82 ( V_220 , V_91 ) ) ;
T_3 V_421 , V_422 ;
if ( F_225 () & V_423 )
return - V_424 ;
F_226 ( & F_82 ( V_224 , V_91 ) ) ;
F_72 ( V_91 ) ;
F_55 ( V_398 , V_421 ) ;
V_422 = V_408 ;
V_422 |= V_420 ;
if ( F_223 () )
V_422 |= V_419 ;
if ( ( V_421 & V_422 ) != V_422 ) {
F_141 ( V_398 , V_421 | V_422 ) ;
}
F_227 ( F_225 () | V_423 ) ;
if ( V_221 ) {
F_155 ( V_88 ) ;
F_90 () ;
}
F_228 ( F_130 ( & V_169 ) ) ;
return 0 ;
}
static void F_229 ( void )
{
int V_91 = F_79 () ;
struct V_90 * V_94 , * V_425 ;
F_230 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_81 ( V_94 ) ;
}
static void F_162 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_231 ( void )
{
if ( V_221 ) {
F_229 () ;
F_162 () ;
}
F_227 ( F_225 () & ~ V_423 ) ;
}
static T_11 int F_232 ( T_2 V_426 , T_2 V_427 ,
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
static T_11 bool F_233 ( T_2 V_74 , T_2 V_431 )
{
T_2 V_429 , V_430 ;
F_204 ( V_74 , V_429 , V_430 ) ;
return V_430 & V_431 ;
}
static T_11 int F_234 ( struct V_29 * V_433 )
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
if ( F_232 ( V_434 , V_435 , V_336 ,
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
if ( F_232 ( V_436 , V_437 ,
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
if ( F_232 ( V_434 , V_435 , V_314 ,
& V_441 ) < 0 )
return - V_432 ;
V_434 = V_312 | V_313 ;
V_435 = V_62 | V_40 ;
if ( F_232 ( V_434 , V_435 , V_308 ,
& V_438 ) < 0 )
return - V_432 ;
if ( ! ( V_440 &
V_38 ) ||
! ( V_441 & V_323 ) )
V_438 &= ~ V_40 ;
V_434 = V_335 ;
V_435 = V_332 | V_333 ;
if ( F_232 ( V_434 , V_435 , V_327 ,
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
V_433 -> V_445 = F_235 ( V_29 . V_444 ) ;
V_433 -> V_446 = V_429 ;
V_433 -> V_39 = V_438 ;
V_433 -> V_30 = V_439 ;
V_433 -> V_34 = V_440 ;
V_433 -> V_447 = V_441 ;
V_433 -> V_404 = V_442 ;
V_145 =
F_233 ( V_327 ,
V_146 )
&& F_233 ( V_314 ,
V_147 ) ;
V_149 =
F_233 ( V_327 ,
V_150 )
&& F_233 ( V_314 ,
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
static struct V_87 * F_236 ( int V_91 )
{
int V_451 = F_237 ( V_91 ) ;
struct V_15 * V_452 ;
struct V_87 * V_87 ;
V_452 = F_238 ( V_451 , V_453 , V_29 . V_445 ) ;
if ( ! V_452 )
return NULL ;
V_87 = F_239 ( V_452 ) ;
memset ( V_87 , 0 , V_29 . V_444 ) ;
V_87 -> V_446 = V_29 . V_446 ;
return V_87 ;
}
static struct V_87 * F_240 ( void )
{
return F_236 ( F_79 () ) ;
}
static void F_241 ( struct V_87 * V_87 )
{
F_242 ( ( unsigned long ) V_87 , V_29 . V_445 ) ;
}
static void F_243 ( struct V_90 * V_90 )
{
if ( ! V_90 -> V_87 )
return;
F_85 ( V_90 ) ;
F_241 ( V_90 -> V_87 ) ;
V_90 -> V_87 = NULL ;
}
static void F_244 ( void )
{
int V_91 ;
F_245 (cpu) {
F_241 ( F_82 ( V_220 , V_91 ) ) ;
F_82 ( V_220 , V_91 ) = NULL ;
}
}
static void F_246 ( void )
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
F_247 ( V_456 [ V_75 ] ,
V_457 ) ;
F_247 ( V_456 [ V_75 ] ,
V_458 ) ;
}
for ( V_75 = 0 ; V_75 < V_459 ; V_75 ++ )
F_247 ( V_460 [ V_75 ] ,
V_458 ) ;
}
static T_11 int F_248 ( void )
{
int V_91 ;
F_245 (cpu) {
struct V_87 * V_87 ;
V_87 = F_236 ( V_91 ) ;
if ( ! V_87 ) {
F_244 () ;
return - V_461 ;
}
F_82 ( V_220 , V_91 ) = V_87 ;
}
return 0 ;
}
static T_11 int F_249 ( void )
{
if ( F_234 ( & V_29 ) < 0 )
return - V_432 ;
if ( F_142 ( V_462 ) )
F_250 ( V_178 ) ;
if ( ! F_49 () )
V_463 = 0 ;
if ( ! F_54 () )
V_464 = 0 ;
if ( V_464 )
F_246 () ;
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
if ( ! F_33 () ) {
V_58 = 0 ;
V_467 -> V_468 = NULL ;
}
if ( ! F_23 () )
V_467 -> V_469 = NULL ;
if ( V_101 && ! F_37 () )
F_251 () ;
if ( ! F_47 () )
V_470 = 0 ;
if ( ! F_32 () )
V_471 = 0 ;
if ( V_471 )
V_467 -> V_469 = NULL ;
else {
V_467 -> V_472 = NULL ;
V_467 -> V_473 = NULL ;
V_467 -> V_474 = V_475 ;
}
if ( V_13 )
F_203 () ;
return F_248 () ;
}
static T_12 void F_252 ( void )
{
F_244 () ;
}
static bool F_253 ( struct V_7 * V_8 )
{
return V_476 && ! F_254 ( V_8 ) ;
}
static void F_255 ( struct V_7 * V_8 , int V_113 ,
struct V_477 * V_478 )
{
if ( ! V_476 ) {
if ( V_113 == V_479 || V_113 == V_480 )
V_478 -> V_120 &= ~ V_481 ;
V_478 -> V_482 = V_478 -> V_120 & V_481 ;
V_478 -> V_187 = 1 ;
}
F_256 ( V_8 , V_478 , V_113 ) ;
}
static void F_257 ( struct V_7 * V_8 )
{
unsigned long V_483 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_485 ] , V_485 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_486 ] , V_486 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_487 ] , V_487 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_488 ] , V_488 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_480 ] , V_480 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_479 ] , V_479 ) ;
V_73 -> V_136 . V_137 = 0 ;
F_116 ( V_73 ) ;
F_256 ( V_8 , & V_73 -> V_136 . V_484 [ V_489 ] , V_489 ) ;
V_483 = F_92 ( V_246 ) ;
V_483 &= V_247 ;
V_483 |= V_73 -> V_136 . V_244 & ~ V_247 ;
F_99 ( V_246 , V_483 ) ;
F_99 ( V_490 , ( F_92 ( V_490 ) & ~ V_491 ) |
( F_92 ( V_492 ) & V_491 ) ) ;
F_122 ( V_8 ) ;
F_255 ( V_8 , V_479 , & V_73 -> V_136 . V_484 [ V_479 ] ) ;
F_255 ( V_8 , V_480 , & V_73 -> V_136 . V_484 [ V_480 ] ) ;
F_255 ( V_8 , V_485 , & V_73 -> V_136 . V_484 [ V_485 ] ) ;
F_255 ( V_8 , V_486 , & V_73 -> V_136 . V_484 [ V_486 ] ) ;
F_255 ( V_8 , V_487 , & V_73 -> V_136 . V_484 [ V_487 ] ) ;
F_255 ( V_8 , V_488 , & V_73 -> V_136 . V_484 [ V_488 ] ) ;
}
static void F_259 ( int V_113 , struct V_477 * V_478 )
{
const struct V_493 * V_494 = & V_122 [ V_113 ] ;
struct V_477 V_495 = * V_478 ;
V_495 . V_482 = 0x3 ;
if ( V_113 == V_479 )
V_495 . type = 0x3 ;
if ( ! V_476 ) {
V_495 . V_120 = V_495 . V_123 >> 4 ;
V_495 . V_123 = V_495 . V_123 & 0xffff0 ;
V_495 . V_125 = 0xffff ;
V_495 . V_496 = 0 ;
V_495 . V_497 = 0 ;
V_495 . V_498 = 1 ;
V_495 . V_187 = 1 ;
V_495 . V_499 = 0 ;
V_495 . V_500 = 0 ;
V_495 . type = 0x3 ;
V_495 . V_501 = 0 ;
if ( V_478 -> V_123 & 0xf )
F_128 ( V_166 L_12
L_13
L_14 , V_113 ) ;
}
F_101 ( V_494 -> V_120 , V_495 . V_120 ) ;
F_102 ( V_494 -> V_123 , V_495 . V_123 ) ;
F_102 ( V_494 -> V_125 , V_495 . V_125 ) ;
F_102 ( V_494 -> V_129 , F_260 ( & V_495 ) ) ;
}
static void F_261 ( struct V_7 * V_8 )
{
unsigned long V_483 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_489 ] , V_489 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_485 ] , V_485 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_486 ] , V_486 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_487 ] , V_487 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_488 ] , V_488 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_480 ] , V_480 ) ;
F_258 ( V_8 , & V_73 -> V_136 . V_484 [ V_479 ] , V_479 ) ;
V_73 -> V_136 . V_137 = 1 ;
if ( ! V_8 -> V_17 -> V_116 . V_502 )
F_128 ( V_166 L_15
L_16 ) ;
F_116 ( V_73 ) ;
F_99 ( V_503 , V_8 -> V_17 -> V_116 . V_502 ) ;
F_102 ( V_504 , V_505 - 1 ) ;
F_102 ( V_506 , 0x008b ) ;
V_483 = F_92 ( V_246 ) ;
V_73 -> V_136 . V_244 = V_483 ;
V_483 |= V_248 | V_249 ;
F_99 ( V_246 , V_483 ) ;
F_99 ( V_490 , F_92 ( V_490 ) | V_491 ) ;
F_122 ( V_8 ) ;
F_259 ( V_480 , & V_73 -> V_136 . V_484 [ V_480 ] ) ;
F_259 ( V_479 , & V_73 -> V_136 . V_484 [ V_479 ] ) ;
F_259 ( V_485 , & V_73 -> V_136 . V_484 [ V_485 ] ) ;
F_259 ( V_486 , & V_73 -> V_136 . V_484 [ V_486 ] ) ;
F_259 ( V_488 , & V_73 -> V_136 . V_484 [ V_488 ] ) ;
F_259 ( V_487 , & V_73 -> V_136 . V_484 [ V_487 ] ) ;
F_262 ( V_8 ) ;
}
static void F_263 ( struct V_7 * V_8 , T_3 V_177 )
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
static void F_264 ( struct V_7 * V_8 )
{
T_2 V_507 ;
F_116 ( F_6 ( V_8 ) ) ;
V_507 = F_94 ( V_506 ) ;
if ( ( V_507 & V_508 ) != V_509 ) {
F_265 ( L_17 ,
V_510 ) ;
F_102 ( V_506 ,
( V_507 & ~ V_508 )
| V_509 ) ;
}
F_263 ( V_8 , V_8 -> V_116 . V_177 | V_180 ) ;
}
static void F_266 ( struct V_7 * V_8 )
{
F_110 ( F_6 ( V_8 ) , V_331 ) ;
F_263 ( V_8 , V_8 -> V_116 . V_177 & ~ V_180 ) ;
}
static void F_267 ( struct V_7 * V_8 )
{
F_89 ( F_6 ( V_8 ) ) ;
if ( V_101 ) {
if ( ! F_268 ( V_8 -> V_116 . V_511 . V_512 ) )
return;
F_91 ( F_269 ( V_8 -> V_116 . V_511 . V_512 ) ) ;
}
}
static void F_168 ( struct V_7 * V_8 )
{
T_9 V_233 = V_8 -> V_116 . V_233 ;
V_8 -> V_116 . V_229 &= ~ V_233 ;
V_8 -> V_116 . V_229 |= F_92 ( V_230 ) & V_233 ;
}
static void F_270 ( struct V_7 * V_8 )
{
if ( V_101 && F_271 ( V_8 ) )
V_8 -> V_116 . V_513 = F_92 ( V_514 ) ;
F_171 ( V_515 , ( T_9 * ) & V_8 -> V_116 . V_117 ) ;
}
static void F_272 ( struct V_7 * V_8 )
{
T_9 V_516 = V_8 -> V_116 . V_516 ;
V_8 -> V_116 . V_517 &= ~ V_516 ;
V_8 -> V_116 . V_517 |= F_92 ( V_490 ) & V_516 ;
}
static void F_273 ( struct V_7 * V_8 )
{
struct V_518 * V_511 = V_8 -> V_116 . V_519 ;
if ( ! F_170 ( V_418 ,
( unsigned long * ) & V_8 -> V_116 . V_520 ) )
return;
if ( F_271 ( V_8 ) && F_274 ( V_8 ) && ! F_140 ( V_8 ) ) {
F_103 ( V_521 , V_511 -> V_522 [ 0 ] ) ;
F_103 ( V_523 , V_511 -> V_522 [ 1 ] ) ;
F_103 ( V_524 , V_511 -> V_522 [ 2 ] ) ;
F_103 ( V_525 , V_511 -> V_522 [ 3 ] ) ;
}
}
static void F_219 ( struct V_7 * V_8 )
{
struct V_518 * V_511 = V_8 -> V_116 . V_519 ;
if ( F_271 ( V_8 ) && F_274 ( V_8 ) && ! F_140 ( V_8 ) ) {
V_511 -> V_522 [ 0 ] = F_95 ( V_521 ) ;
V_511 -> V_522 [ 1 ] = F_95 ( V_523 ) ;
V_511 -> V_522 [ 2 ] = F_95 ( V_524 ) ;
V_511 -> V_522 [ 3 ] = F_95 ( V_525 ) ;
}
F_171 ( V_418 ,
( unsigned long * ) & V_8 -> V_116 . V_117 ) ;
F_171 ( V_418 ,
( unsigned long * ) & V_8 -> V_116 . V_520 ) ;
}
static void F_275 ( unsigned long * V_526 ,
unsigned long V_229 ,
struct V_7 * V_8 )
{
if ( ! F_170 ( V_515 , ( T_9 * ) & V_8 -> V_116 . V_117 ) )
F_270 ( V_8 ) ;
if ( ! ( V_229 & V_527 ) ) {
F_102 ( V_528 ,
F_94 ( V_528 ) |
( V_345 |
V_346 ) ) ;
V_8 -> V_116 . V_229 = V_229 ;
F_276 ( V_8 , F_277 ( V_8 ) ) ;
} else if ( ! F_271 ( V_8 ) ) {
F_102 ( V_528 ,
F_94 ( V_528 ) &
~ ( V_345 |
V_346 ) ) ;
V_8 -> V_116 . V_229 = V_229 ;
F_276 ( V_8 , F_277 ( V_8 ) ) ;
}
if ( ! ( V_229 & V_529 ) )
* V_526 &= ~ V_529 ;
}
static void F_278 ( struct V_7 * V_8 , unsigned long V_229 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_526 ;
V_526 = ( V_229 & ~ V_530 ) ;
if ( V_465 )
V_526 |= V_531 ;
else {
V_526 |= V_532 ;
if ( V_73 -> V_136 . V_137 && ( V_229 & V_533 ) )
F_257 ( V_8 ) ;
if ( ! V_73 -> V_136 . V_137 && ! ( V_229 & V_533 ) )
F_261 ( V_8 ) ;
}
#ifdef F_96
if ( V_8 -> V_116 . V_177 & V_181 ) {
if ( ! F_271 ( V_8 ) && ( V_229 & V_527 ) )
F_264 ( V_8 ) ;
if ( F_271 ( V_8 ) && ! ( V_229 & V_527 ) )
F_266 ( V_8 ) ;
}
#endif
if ( V_101 )
F_275 ( & V_526 , V_229 , V_8 ) ;
if ( ! V_8 -> V_138 )
V_526 |= V_231 | V_232 ;
F_99 ( V_242 , V_229 ) ;
F_99 ( V_230 , V_526 ) ;
V_8 -> V_116 . V_229 = V_229 ;
V_73 -> F_253 = F_253 ( V_8 ) ;
}
static T_3 F_269 ( unsigned long V_512 )
{
T_3 V_84 ;
V_84 = V_534 |
V_535 << V_536 ;
if ( V_466 )
V_84 |= V_537 ;
V_84 |= ( V_512 & V_538 ) ;
return V_84 ;
}
static void F_279 ( struct V_7 * V_8 , unsigned long V_513 )
{
unsigned long V_539 ;
T_3 V_84 ;
V_539 = V_513 ;
if ( V_101 ) {
V_84 = F_269 ( V_513 ) ;
F_103 ( V_540 , V_84 ) ;
if ( F_271 ( V_8 ) || F_123 ( V_8 ) )
V_539 = F_280 ( V_8 ) ;
else
V_539 = V_8 -> V_17 -> V_116 . V_541 ;
F_273 ( V_8 ) ;
}
F_267 ( V_8 ) ;
F_99 ( V_514 , V_539 ) ;
}
static int F_276 ( struct V_7 * V_8 , unsigned long V_517 )
{
unsigned long V_542 = V_517 | ( F_6 ( V_8 ) -> V_136 . V_137 ?
V_543 : V_544 ) ;
if ( V_517 & V_423 ) {
if ( ! F_202 ( V_8 ) )
return 1 ;
}
if ( F_6 ( V_8 ) -> V_13 . V_545 &&
( ( V_517 & F_210 ) != F_210 ) )
return 1 ;
V_8 -> V_116 . V_517 = V_517 ;
if ( V_101 ) {
if ( ! F_271 ( V_8 ) ) {
V_542 &= ~ V_546 ;
V_542 |= V_547 ;
V_542 &= ~ ( V_548 | V_549 ) ;
} else if ( ! ( V_517 & V_546 ) ) {
V_542 &= ~ V_546 ;
}
}
F_99 ( V_492 , V_517 ) ;
F_99 ( V_490 , V_542 ) ;
return 0 ;
}
static void F_258 ( struct V_7 * V_8 ,
struct V_477 * V_495 , int V_113 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_127 ;
if ( V_73 -> V_136 . V_137 && V_113 != V_550 ) {
* V_495 = V_73 -> V_136 . V_484 [ V_113 ] ;
if ( V_113 == V_489
|| V_495 -> V_120 == F_118 ( V_73 , V_113 ) )
return;
V_495 -> V_123 = F_119 ( V_73 , V_113 ) ;
V_495 -> V_120 = F_118 ( V_73 , V_113 ) ;
return;
}
V_495 -> V_123 = F_119 ( V_73 , V_113 ) ;
V_495 -> V_125 = F_120 ( V_73 , V_113 ) ;
V_495 -> V_120 = F_118 ( V_73 , V_113 ) ;
V_127 = F_121 ( V_73 , V_113 ) ;
V_495 -> V_500 = ( V_127 >> 16 ) & 1 ;
V_495 -> type = V_127 & 15 ;
V_495 -> V_187 = ( V_127 >> 4 ) & 1 ;
V_495 -> V_482 = ( V_127 >> 5 ) & 3 ;
V_495 -> V_498 = ! V_495 -> V_500 ;
V_495 -> V_501 = ( V_127 >> 12 ) & 1 ;
V_495 -> V_499 = ( V_127 >> 13 ) & 1 ;
V_495 -> V_497 = ( V_127 >> 14 ) & 1 ;
V_495 -> V_496 = ( V_127 >> 15 ) & 1 ;
}
static T_3 F_281 ( struct V_7 * V_8 , int V_113 )
{
struct V_477 V_187 ;
if ( F_6 ( V_8 ) -> V_136 . V_137 ) {
F_258 ( V_8 , & V_187 , V_113 ) ;
return V_187 . V_123 ;
}
return F_119 ( F_6 ( V_8 ) , V_113 ) ;
}
static int F_282 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_100 ( V_73 -> V_136 . V_137 ) )
return 0 ;
else {
int V_127 = F_121 ( V_73 , V_480 ) ;
return F_283 ( V_127 ) ;
}
}
static T_2 F_260 ( struct V_477 * V_495 )
{
T_2 V_127 ;
if ( V_495 -> V_500 || ! V_495 -> V_498 )
V_127 = 1 << 16 ;
else {
V_127 = V_495 -> type & 15 ;
V_127 |= ( V_495 -> V_187 & 1 ) << 4 ;
V_127 |= ( V_495 -> V_482 & 3 ) << 5 ;
V_127 |= ( V_495 -> V_498 & 1 ) << 7 ;
V_127 |= ( V_495 -> V_501 & 1 ) << 12 ;
V_127 |= ( V_495 -> V_499 & 1 ) << 13 ;
V_127 |= ( V_495 -> V_497 & 1 ) << 14 ;
V_127 |= ( V_495 -> V_496 & 1 ) << 15 ;
}
return V_127 ;
}
static void F_256 ( struct V_7 * V_8 ,
struct V_477 * V_495 , int V_113 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
const struct V_493 * V_494 = & V_122 [ V_113 ] ;
F_116 ( V_73 ) ;
if ( V_73 -> V_136 . V_137 && V_113 != V_550 ) {
V_73 -> V_136 . V_484 [ V_113 ] = * V_495 ;
if ( V_113 == V_489 )
F_101 ( V_494 -> V_120 , V_495 -> V_120 ) ;
else if ( V_495 -> V_187 )
F_259 ( V_113 , & V_73 -> V_136 . V_484 [ V_113 ] ) ;
goto V_551;
}
F_99 ( V_494 -> V_123 , V_495 -> V_123 ) ;
F_102 ( V_494 -> V_125 , V_495 -> V_125 ) ;
F_101 ( V_494 -> V_120 , V_495 -> V_120 ) ;
if ( V_465 && ( V_113 != V_550 ) )
V_495 -> type |= 0x1 ;
F_102 ( V_494 -> V_129 , F_260 ( V_495 ) ) ;
V_551:
V_73 -> F_253 = F_253 ( V_8 ) ;
}
static void F_284 ( struct V_7 * V_8 , int * V_497 , int * V_499 )
{
T_2 V_127 = F_121 ( F_6 ( V_8 ) , V_479 ) ;
* V_497 = ( V_127 >> 14 ) & 1 ;
* V_499 = ( V_127 >> 13 ) & 1 ;
}
static void F_285 ( struct V_7 * V_8 , struct V_167 * V_552 )
{
V_552 -> V_444 = F_94 ( V_553 ) ;
V_552 -> V_172 = F_92 ( V_554 ) ;
}
static void F_286 ( struct V_7 * V_8 , struct V_167 * V_552 )
{
F_102 ( V_553 , V_552 -> V_444 ) ;
F_99 ( V_554 , V_552 -> V_172 ) ;
}
static void F_287 ( struct V_7 * V_8 , struct V_167 * V_552 )
{
V_552 -> V_444 = F_94 ( V_555 ) ;
V_552 -> V_172 = F_92 ( V_556 ) ;
}
static void F_288 ( struct V_7 * V_8 , struct V_167 * V_552 )
{
F_102 ( V_555 , V_552 -> V_444 ) ;
F_99 ( V_556 , V_552 -> V_172 ) ;
}
static bool F_289 ( struct V_7 * V_8 , int V_113 )
{
struct V_477 V_495 ;
T_2 V_127 ;
F_258 ( V_8 , & V_495 , V_113 ) ;
V_495 . V_482 = 0x3 ;
if ( V_113 == V_479 )
V_495 . type = 0x3 ;
V_127 = F_260 ( & V_495 ) ;
if ( V_495 . V_123 != ( V_495 . V_120 << 4 ) )
return false ;
if ( V_495 . V_125 != 0xffff )
return false ;
if ( V_127 != 0xf3 )
return false ;
return true ;
}
static bool F_290 ( struct V_7 * V_8 )
{
struct V_477 V_557 ;
unsigned int V_558 ;
F_258 ( V_8 , & V_557 , V_479 ) ;
V_558 = V_557 . V_120 & V_481 ;
if ( V_557 . V_500 )
return false ;
if ( ~ V_557 . type & ( V_559 | V_560 ) )
return false ;
if ( ! V_557 . V_187 )
return false ;
if ( V_557 . type & V_561 ) {
if ( V_557 . V_482 > V_558 )
return false ;
} else {
if ( V_557 . V_482 != V_558 )
return false ;
}
if ( ! V_557 . V_498 )
return false ;
return true ;
}
static bool F_291 ( struct V_7 * V_8 )
{
struct V_477 V_562 ;
unsigned int V_563 ;
F_258 ( V_8 , & V_562 , V_480 ) ;
V_563 = V_562 . V_120 & V_481 ;
if ( V_562 . V_500 )
return true ;
if ( V_562 . type != 3 && V_562 . type != 7 )
return false ;
if ( ! V_562 . V_187 )
return false ;
if ( V_562 . V_482 != V_563 )
return false ;
if ( ! V_562 . V_498 )
return false ;
return true ;
}
static bool F_292 ( struct V_7 * V_8 , int V_113 )
{
struct V_477 V_495 ;
unsigned int V_564 ;
F_258 ( V_8 , & V_495 , V_113 ) ;
V_564 = V_495 . V_120 & V_481 ;
if ( V_495 . V_500 )
return true ;
if ( ! V_495 . V_187 )
return false ;
if ( ! V_495 . V_498 )
return false ;
if ( ~ V_495 . type & ( V_559 | V_561 ) ) {
if ( V_495 . V_482 < V_564 )
return false ;
}
return true ;
}
static bool F_293 ( struct V_7 * V_8 )
{
struct V_477 V_190 ;
F_258 ( V_8 , & V_190 , V_489 ) ;
if ( V_190 . V_500 )
return false ;
if ( V_190 . V_120 & V_565 )
return false ;
if ( V_190 . type != 3 && V_190 . type != 11 )
return false ;
if ( ! V_190 . V_498 )
return false ;
return true ;
}
static bool F_294 ( struct V_7 * V_8 )
{
struct V_477 V_566 ;
F_258 ( V_8 , & V_566 , V_550 ) ;
if ( V_566 . V_500 )
return true ;
if ( V_566 . V_120 & V_565 )
return false ;
if ( V_566 . type != 2 )
return false ;
if ( ! V_566 . V_498 )
return false ;
return true ;
}
static bool F_295 ( struct V_7 * V_8 )
{
struct V_477 V_557 , V_562 ;
F_258 ( V_8 , & V_557 , V_479 ) ;
F_258 ( V_8 , & V_562 , V_480 ) ;
return ( ( V_557 . V_120 & V_481 ) ==
( V_562 . V_120 & V_481 ) ) ;
}
static bool F_254 ( struct V_7 * V_8 )
{
if ( V_465 )
return true ;
if ( ! F_296 ( V_8 ) || ( F_169 ( V_8 ) & V_249 ) ) {
if ( ! F_289 ( V_8 , V_479 ) )
return false ;
if ( ! F_289 ( V_8 , V_480 ) )
return false ;
if ( ! F_289 ( V_8 , V_486 ) )
return false ;
if ( ! F_289 ( V_8 , V_485 ) )
return false ;
if ( ! F_289 ( V_8 , V_487 ) )
return false ;
if ( ! F_289 ( V_8 , V_488 ) )
return false ;
} else {
if ( ! F_295 ( V_8 ) )
return false ;
if ( ! F_290 ( V_8 ) )
return false ;
if ( ! F_291 ( V_8 ) )
return false ;
if ( ! F_292 ( V_8 , V_486 ) )
return false ;
if ( ! F_292 ( V_8 , V_485 ) )
return false ;
if ( ! F_292 ( V_8 , V_487 ) )
return false ;
if ( ! F_292 ( V_8 , V_488 ) )
return false ;
if ( ! F_293 ( V_8 ) )
return false ;
if ( ! F_294 ( V_8 ) )
return false ;
}
return true ;
}
static int F_297 ( struct V_17 * V_17 )
{
T_13 V_567 ;
T_4 V_183 = 0 ;
int V_568 , V_569 ;
V_568 = F_298 ( & V_17 -> V_570 ) ;
V_567 = V_17 -> V_116 . V_502 >> V_18 ;
V_569 = F_299 ( V_17 , V_567 , 0 , V_443 ) ;
if ( V_569 < 0 )
goto V_551;
V_183 = V_571 + V_572 ;
V_569 = F_300 ( V_17 , V_567 ++ , & V_183 ,
V_573 , sizeof( T_4 ) ) ;
if ( V_569 < 0 )
goto V_551;
V_569 = F_299 ( V_17 , V_567 ++ , 0 , V_443 ) ;
if ( V_569 < 0 )
goto V_551;
V_569 = F_299 ( V_17 , V_567 , 0 , V_443 ) ;
if ( V_569 < 0 )
goto V_551;
V_183 = ~ 0 ;
V_569 = F_300 ( V_17 , V_567 , & V_183 ,
V_505 - 2 * V_443 - 1 ,
sizeof( T_6 ) ) ;
V_551:
F_301 ( & V_17 -> V_570 , V_568 ) ;
return V_569 ;
}
static int F_302 ( struct V_17 * V_17 )
{
int V_75 , V_568 , V_569 = 0 ;
T_14 V_574 ;
T_2 V_276 ;
if ( ! V_101 )
return 0 ;
F_303 ( & V_17 -> V_575 ) ;
if ( F_304 ( V_17 -> V_116 . V_576 ) )
goto V_577;
V_574 = V_17 -> V_116 . V_541 >> V_18 ;
V_569 = F_305 ( V_17 ) ;
if ( V_569 < 0 )
goto V_577;
V_568 = F_298 ( & V_17 -> V_570 ) ;
V_569 = F_299 ( V_17 , V_574 , 0 , V_443 ) ;
if ( V_569 < 0 )
goto V_551;
for ( V_75 = 0 ; V_75 < V_578 ; V_75 ++ ) {
V_276 = ( V_75 << 22 ) + ( V_579 | V_580 | V_581 |
V_582 | V_583 | V_584 ) ;
V_569 = F_300 ( V_17 , V_574 ,
& V_276 , V_75 * sizeof( V_276 ) , sizeof( V_276 ) ) ;
if ( V_569 < 0 )
goto V_551;
}
V_17 -> V_116 . V_576 = true ;
V_551:
F_301 ( & V_17 -> V_570 , V_568 ) ;
V_577:
F_306 ( & V_17 -> V_575 ) ;
return V_569 ;
}
static void F_307 ( int V_113 )
{
const struct V_493 * V_494 = & V_122 [ V_113 ] ;
unsigned int V_127 ;
F_101 ( V_494 -> V_120 , 0 ) ;
F_99 ( V_494 -> V_123 , 0 ) ;
F_102 ( V_494 -> V_125 , 0xffff ) ;
V_127 = 0x93 ;
if ( V_113 == V_479 )
V_127 |= 0x08 ;
F_102 ( V_494 -> V_129 , V_127 ) ;
}
static int F_308 ( struct V_17 * V_17 )
{
struct V_15 * V_15 ;
struct V_585 V_586 ;
int V_569 = 0 ;
F_303 ( & V_17 -> V_575 ) ;
if ( V_17 -> V_116 . V_587 )
goto V_551;
V_586 . V_588 = V_589 ;
V_586 . V_483 = 0 ;
V_586 . V_590 = V_591 ;
V_586 . V_592 = V_443 ;
V_569 = F_309 ( V_17 , & V_586 ) ;
if ( V_569 )
goto V_551;
V_15 = F_11 ( V_17 , V_591 >> V_18 ) ;
if ( F_12 ( V_15 ) ) {
V_569 = - V_593 ;
goto V_551;
}
F_310 ( V_15 ) ;
V_17 -> V_116 . V_587 = true ;
V_551:
F_306 ( & V_17 -> V_575 ) ;
return V_569 ;
}
static int F_305 ( struct V_17 * V_17 )
{
struct V_585 V_586 ;
int V_569 = 0 ;
F_311 ( V_17 -> V_116 . V_576 ) ;
V_586 . V_588 = V_594 ;
V_586 . V_483 = 0 ;
V_586 . V_590 =
V_17 -> V_116 . V_541 ;
V_586 . V_592 = V_443 ;
V_569 = F_309 ( V_17 , & V_586 ) ;
return V_569 ;
}
static void F_312 ( struct V_6 * V_73 )
{
int V_52 ;
V_73 -> V_52 = 0 ;
if ( ! V_463 )
return;
F_313 ( & V_595 ) ;
V_52 = F_314 ( V_596 , V_597 ) ;
if ( V_52 < V_597 ) {
V_73 -> V_52 = V_52 ;
F_171 ( V_52 , V_596 ) ;
}
F_315 ( & V_595 ) ;
}
static void F_316 ( struct V_6 * V_73 )
{
if ( ! V_463 )
return;
F_313 ( & V_595 ) ;
if ( V_73 -> V_52 != 0 )
F_317 ( V_73 -> V_52 , V_596 ) ;
F_315 ( & V_595 ) ;
}
static void F_318 ( unsigned long * V_277 ,
T_2 V_74 , int type )
{
int V_598 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_74 <= 0x1fff ) {
if ( type & V_599 )
F_317 ( V_74 , V_277 + 0x000 / V_598 ) ;
if ( type & V_600 )
F_317 ( V_74 , V_277 + 0x800 / V_598 ) ;
} else if ( ( V_74 >= 0xc0000000 ) && ( V_74 <= 0xc0001fff ) ) {
V_74 &= 0x1fff ;
if ( type & V_599 )
F_317 ( V_74 , V_277 + 0x400 / V_598 ) ;
if ( type & V_600 )
F_317 ( V_74 , V_277 + 0xc00 / V_598 ) ;
}
}
static void F_319 ( unsigned long * V_277 ,
T_2 V_74 , int type )
{
int V_598 = sizeof( unsigned long ) ;
if ( ! F_22 () )
return;
if ( V_74 <= 0x1fff ) {
if ( type & V_599 )
F_171 ( V_74 , V_277 + 0x000 / V_598 ) ;
if ( type & V_600 )
F_171 ( V_74 , V_277 + 0x800 / V_598 ) ;
} else if ( ( V_74 >= 0xc0000000 ) && ( V_74 <= 0xc0001fff ) ) {
V_74 &= 0x1fff ;
if ( type & V_599 )
F_171 ( V_74 , V_277 + 0x400 / V_598 ) ;
if ( type & V_600 )
F_171 ( V_74 , V_277 + 0xc00 / V_598 ) ;
}
}
static void F_320 ( T_2 V_74 , bool V_601 )
{
if ( ! V_601 )
F_318 ( V_282 ,
V_74 , V_599 | V_600 ) ;
F_318 ( V_281 ,
V_74 , V_599 | V_600 ) ;
}
static void F_321 ( T_2 V_74 )
{
F_319 ( V_280 ,
V_74 , V_599 ) ;
F_319 ( V_279 ,
V_74 , V_599 ) ;
}
static void F_322 ( T_2 V_74 )
{
F_318 ( V_280 ,
V_74 , V_599 ) ;
F_318 ( V_279 ,
V_74 , V_599 ) ;
}
static void F_323 ( T_2 V_74 )
{
F_318 ( V_280 ,
V_74 , V_600 ) ;
F_318 ( V_279 ,
V_74 , V_600 ) ;
}
static int F_324 ( struct V_17 * V_17 )
{
return V_471 && F_25 ( V_17 ) ;
}
static void F_325 ( struct V_7 * V_8 , int V_4 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_569 ;
if ( F_5 ( V_4 , & V_73 -> V_1 ) )
return;
V_569 = F_1 ( & V_73 -> V_1 ) ;
F_156 ( V_602 , V_8 ) ;
#ifdef F_326
if ( ! V_569 && ( V_8 -> V_603 == V_604 ) )
V_278 -> V_605 ( F_327 ( V_8 -> V_91 ) ,
V_606 ) ;
else
#endif
F_328 ( V_8 ) ;
}
static void F_329 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_3 ( & V_73 -> V_1 ) )
return;
F_330 ( V_8 , V_73 -> V_1 . V_5 ) ;
}
static void V_475 ( struct V_7 * V_8 )
{
return;
}
static void F_331 ( struct V_6 * V_73 )
{
T_2 V_607 , V_608 ;
unsigned long V_609 ;
struct V_167 V_552 ;
unsigned long V_517 ;
F_99 ( V_610 , F_332 () & ~ V_231 ) ;
F_99 ( V_611 , F_333 () ) ;
V_517 = F_225 () ;
F_99 ( V_612 , V_517 ) ;
V_73 -> V_191 . V_613 = V_517 ;
F_101 ( V_614 , V_615 ) ;
#ifdef F_96
F_101 ( V_616 , 0 ) ;
F_101 ( V_617 , 0 ) ;
#else
F_101 ( V_616 , V_618 ) ;
F_101 ( V_617 , V_618 ) ;
#endif
F_101 ( V_619 , V_618 ) ;
F_101 ( V_620 , V_173 * 8 ) ;
F_334 ( & V_552 ) ;
F_99 ( V_621 , V_552 . V_172 ) ;
V_73 -> V_622 = V_552 . V_172 ;
F_99 ( V_623 , V_624 ) ;
F_204 ( V_392 , V_607 , V_608 ) ;
F_102 ( V_625 , V_607 ) ;
F_55 ( V_394 , V_609 ) ;
F_99 ( V_626 , V_609 ) ;
if ( V_29 . V_447 & V_319 ) {
F_204 ( V_403 , V_607 , V_608 ) ;
F_103 ( V_627 , V_607 | ( ( T_3 ) V_608 << 32 ) ) ;
}
}
static void F_335 ( struct V_6 * V_73 )
{
V_73 -> V_8 . V_116 . V_516 = V_628 ;
if ( V_101 )
V_73 -> V_8 . V_116 . V_516 |= V_629 ;
if ( F_123 ( & V_73 -> V_8 ) )
V_73 -> V_8 . V_116 . V_516 &=
~ F_9 ( & V_73 -> V_8 ) -> V_240 ;
F_99 ( V_630 , ~ V_73 -> V_8 . V_116 . V_516 ) ;
}
static T_2 F_336 ( struct V_6 * V_73 )
{
T_2 V_39 = V_29 . V_39 ;
if ( ! F_324 ( V_73 -> V_8 . V_17 ) )
V_39 &= ~ V_40 ;
return V_39 ;
}
static T_2 F_337 ( struct V_6 * V_73 )
{
T_2 V_631 = V_29 . V_30 ;
if ( V_73 -> V_8 . V_116 . V_632 & V_633 )
V_631 &= ~ V_349 ;
if ( ! F_24 ( V_73 -> V_8 . V_17 ) ) {
V_631 &= ~ V_32 ;
#ifdef F_96
V_631 |= V_348 |
V_347 ;
#endif
}
if ( ! V_101 )
V_631 |= V_346 |
V_345 |
V_343 ;
return V_631 ;
}
static T_2 F_338 ( struct V_6 * V_73 )
{
T_2 V_631 = V_29 . V_34 ;
if ( ! F_48 ( V_73 -> V_8 . V_17 ) )
V_631 &= ~ V_35 ;
if ( V_73 -> V_52 == 0 )
V_631 &= ~ V_59 ;
if ( ! V_101 ) {
V_631 &= ~ V_55 ;
V_465 = 0 ;
V_631 &= ~ V_61 ;
}
if ( ! V_465 )
V_631 &= ~ V_56 ;
if ( ! V_470 )
V_631 &= ~ V_57 ;
if ( ! F_324 ( V_73 -> V_8 . V_17 ) )
V_631 &= ~ ( V_37 |
V_38 ) ;
V_631 &= ~ V_36 ;
V_631 &= ~ V_67 ;
return V_631 ;
}
static void F_339 ( void )
{
F_340 ( ( 0x3ull << 62 ) | 0x6ull ) ;
}
static int F_341 ( struct V_6 * V_73 )
{
#ifdef F_96
unsigned long V_634 ;
#endif
int V_75 ;
F_103 ( V_635 , F_68 ( V_636 ) ) ;
F_103 ( V_637 , F_68 ( V_638 ) ) ;
if ( V_464 ) {
F_103 ( V_639 , F_68 ( V_458 ) ) ;
F_103 ( V_640 , F_68 ( V_457 ) ) ;
}
if ( F_22 () )
F_103 ( V_283 , F_68 ( V_282 ) ) ;
F_103 ( V_641 , - 1ull ) ;
F_102 ( V_642 , F_336 ( V_73 ) ) ;
F_102 ( V_528 , F_337 ( V_73 ) ) ;
if ( F_26 () ) {
F_102 ( V_643 ,
F_338 ( V_73 ) ) ;
}
if ( F_324 ( V_73 -> V_8 . V_17 ) ) {
F_103 ( V_644 , 0 ) ;
F_103 ( V_645 , 0 ) ;
F_103 ( V_646 , 0 ) ;
F_103 ( V_647 , 0 ) ;
F_101 ( V_648 , 0 ) ;
F_103 ( V_649 , V_606 ) ;
F_103 ( V_650 , F_68 ( ( & V_73 -> V_1 ) ) ) ;
}
if ( V_470 ) {
F_102 ( V_651 , V_470 ) ;
V_73 -> V_652 = V_652 ;
V_73 -> V_653 = true ;
}
F_102 ( V_654 , 0 ) ;
F_102 ( V_655 , 0 ) ;
F_102 ( V_656 , 0 ) ;
F_101 ( V_197 , 0 ) ;
F_101 ( V_201 , 0 ) ;
F_331 ( V_73 ) ;
#ifdef F_96
F_55 ( V_207 , V_634 ) ;
F_99 ( V_206 , V_634 ) ;
F_55 ( V_209 , V_634 ) ;
F_99 ( V_208 , V_634 ) ;
#else
F_99 ( V_206 , 0 ) ;
F_99 ( V_208 , 0 ) ;
#endif
F_102 ( V_657 , 0 ) ;
F_102 ( V_156 , 0 ) ;
F_103 ( V_658 , F_68 ( V_73 -> V_142 . V_154 ) ) ;
F_102 ( V_155 , 0 ) ;
F_103 ( V_659 , F_68 ( V_73 -> V_142 . V_153 ) ) ;
if ( V_29 . V_404 & V_332 ) {
T_2 V_660 , V_661 ;
T_3 V_662 ;
F_204 ( V_403 , V_660 , V_661 ) ;
V_662 = V_660 | ( ( T_3 ) V_661 << 32 ) ;
F_103 ( V_405 , V_662 ) ;
V_73 -> V_8 . V_116 . V_406 = V_662 ;
}
for ( V_75 = 0 ; V_75 < F_342 ( V_77 ) ; ++ V_75 ) {
T_2 V_79 = V_77 [ V_75 ] ;
T_2 V_663 , V_664 ;
int V_454 = V_73 -> V_76 ;
if ( F_343 ( V_79 , & V_663 , & V_664 ) < 0 )
continue;
if ( F_344 ( V_79 , V_663 , V_664 ) < 0 )
continue;
V_73 -> V_78 [ V_454 ] . V_79 = V_75 ;
V_73 -> V_78 [ V_454 ] . V_183 = 0 ;
V_73 -> V_78 [ V_454 ] . V_105 = - 1ull ;
++ V_73 -> V_76 ;
}
F_111 ( V_73 , V_29 . V_447 ) ;
F_106 ( V_73 , V_29 . V_404 ) ;
F_99 ( V_235 , ~ 0UL ) ;
F_335 ( V_73 ) ;
return 0 ;
}
static void F_345 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_401 V_665 ;
V_73 -> V_136 . V_137 = 0 ;
V_73 -> V_666 = 0 ;
V_73 -> V_8 . V_116 . V_414 [ V_667 ] = F_346 () ;
F_347 ( & V_73 -> V_8 , 0 ) ;
V_665 . V_183 = V_591 | V_668 ;
if ( F_348 ( & V_73 -> V_8 ) )
V_665 . V_183 |= V_669 ;
V_665 . V_409 = true ;
F_349 ( & V_73 -> V_8 , & V_665 ) ;
F_116 ( V_73 ) ;
F_307 ( V_479 ) ;
F_101 ( V_670 , 0xf000 ) ;
F_102 ( V_671 , 0xffff0000 ) ;
F_307 ( V_486 ) ;
F_307 ( V_485 ) ;
F_307 ( V_487 ) ;
F_307 ( V_488 ) ;
F_307 ( V_480 ) ;
F_101 ( V_672 , 0 ) ;
F_99 ( V_503 , 0 ) ;
F_102 ( V_504 , 0xffff ) ;
F_102 ( V_506 , 0x008b ) ;
F_101 ( V_673 , 0 ) ;
F_99 ( V_674 , 0 ) ;
F_102 ( V_675 , 0xffff ) ;
F_102 ( V_676 , 0x00082 ) ;
F_102 ( V_393 , 0 ) ;
F_99 ( V_396 , 0 ) ;
F_99 ( V_395 , 0 ) ;
F_99 ( V_246 , 0x02 ) ;
F_177 ( V_8 , 0xfff0 ) ;
F_99 ( V_556 , 0 ) ;
F_102 ( V_555 , 0xffff ) ;
F_99 ( V_554 , 0 ) ;
F_102 ( V_553 , 0xffff ) ;
F_102 ( V_677 , V_678 ) ;
F_102 ( V_251 , 0 ) ;
F_102 ( V_679 , 0 ) ;
F_103 ( V_680 , 0 ) ;
F_188 ( V_73 ) ;
F_102 ( V_273 , 0 ) ;
if ( F_23 () ) {
F_103 ( V_681 , 0 ) ;
if ( F_24 ( V_73 -> V_8 . V_17 ) )
F_103 ( V_681 ,
F_68 ( V_73 -> V_8 . V_116 . V_278 -> V_414 ) ) ;
F_102 ( V_682 , 0 ) ;
}
F_156 ( V_683 , V_8 ) ;
if ( F_324 ( V_8 -> V_17 ) )
memset ( & V_73 -> V_1 , 0 , sizeof( struct V_1 ) ) ;
if ( V_73 -> V_52 != 0 )
F_101 ( V_684 , V_73 -> V_52 ) ;
V_73 -> V_8 . V_116 . V_229 = V_685 | V_686 | V_687 ;
F_278 ( & V_73 -> V_8 , F_350 ( V_8 ) ) ;
F_276 ( & V_73 -> V_8 , 0 ) ;
F_263 ( & V_73 -> V_8 , 0 ) ;
F_163 ( & V_73 -> V_8 ) ;
F_122 ( & V_73 -> V_8 ) ;
F_89 ( V_73 ) ;
}
static bool F_351 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_312 ;
}
static bool F_352 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_688 &
V_323 ;
}
static bool F_353 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_71 &
V_313 ;
}
static void F_354 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_528 ) ;
V_69 |= V_340 ;
F_102 ( V_528 , V_69 ) ;
}
static void F_355 ( struct V_7 * V_8 )
{
T_2 V_69 ;
if ( ! F_52 () ||
F_94 ( V_251 ) & V_252 ) {
F_354 ( V_8 ) ;
return;
}
V_69 = F_94 ( V_528 ) ;
V_69 |= V_341 ;
F_102 ( V_528 , V_69 ) ;
}
static void F_356 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_15 V_689 ;
int V_690 = V_8 -> V_116 . V_691 . V_152 ;
F_357 ( V_690 ) ;
++ V_8 -> V_217 . V_692 ;
if ( V_73 -> V_136 . V_137 ) {
int V_267 = 0 ;
if ( V_8 -> V_116 . V_691 . V_693 )
V_267 = V_8 -> V_116 . V_268 ;
if ( F_182 ( V_8 , V_690 , V_267 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
V_689 = V_690 | V_22 ;
if ( V_8 -> V_116 . V_691 . V_693 ) {
V_689 |= V_694 ;
F_102 ( V_271 ,
V_73 -> V_8 . V_116 . V_268 ) ;
} else
V_689 |= V_27 ;
F_102 ( V_273 , V_689 ) ;
}
static void F_358 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_123 ( V_8 ) )
return;
if ( ! F_52 () ) {
V_73 -> V_666 = 1 ;
V_73 -> V_695 = 0 ;
}
++ V_8 -> V_217 . V_696 ;
V_73 -> V_697 = false ;
if ( V_73 -> V_136 . V_137 ) {
if ( F_182 ( V_8 , V_698 , 0 ) != V_269 )
F_156 ( V_270 , V_8 ) ;
return;
}
F_102 ( V_273 ,
V_699 | V_22 | V_698 ) ;
}
static bool F_359 ( struct V_7 * V_8 )
{
if ( ! F_52 () )
return F_6 ( V_8 ) -> V_666 ;
if ( F_6 ( V_8 ) -> V_697 )
return false ;
return F_94 ( V_251 ) & V_700 ;
}
static void F_360 ( struct V_7 * V_8 , bool V_701 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_52 () ) {
if ( V_73 -> V_666 != V_701 ) {
V_73 -> V_666 = V_701 ;
V_73 -> V_695 = 0 ;
}
} else {
V_73 -> V_697 = ! V_701 ;
if ( V_701 )
F_105 ( V_251 ,
V_700 ) ;
else
F_104 ( V_251 ,
V_700 ) ;
}
}
static int F_361 ( struct V_7 * V_8 )
{
if ( F_6 ( V_8 ) -> V_13 . V_702 )
return 0 ;
if ( ! F_52 () && F_6 ( V_8 ) -> V_666 )
return 0 ;
return ! ( F_94 ( V_251 ) &
( V_254 | V_252
| V_700 ) ) ;
}
static int F_362 ( struct V_7 * V_8 )
{
return ( ! F_6 ( V_8 ) -> V_13 . V_702 &&
F_92 ( V_246 ) & V_703 ) &&
! ( F_94 ( V_251 ) &
( V_252 | V_254 ) ) ;
}
static int F_363 ( struct V_17 * V_17 , unsigned int V_16 )
{
int V_114 ;
struct V_585 V_704 = {
. V_588 = V_705 ,
. V_590 = V_16 ,
. V_592 = V_443 * 3 ,
. V_483 = 0 ,
} ;
V_114 = F_364 ( V_17 , & V_704 ) ;
if ( V_114 )
return V_114 ;
V_17 -> V_116 . V_502 = V_16 ;
return F_297 ( V_17 ) ;
}
static bool F_365 ( struct V_7 * V_8 , int V_706 )
{
switch ( V_706 ) {
case V_135 :
F_6 ( V_8 ) -> V_8 . V_116 . V_268 =
F_94 ( V_258 ) ;
if ( V_8 -> V_132 & V_134 )
return false ;
case V_131 :
if ( V_8 -> V_132 &
( V_707 | V_708 ) )
return false ;
case V_709 :
case V_710 :
case V_711 :
case V_26 :
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
if ( F_367 ( V_8 , 0 ) == V_269 ) {
if ( V_8 -> V_116 . V_717 ) {
V_8 -> V_116 . V_717 = 0 ;
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
#if F_371 ( V_718 ) && F_371 ( F_96 )
struct V_719 V_414 = {
. V_557 = 3 ,
. V_483 = V_703 ,
} ;
F_372 ( & V_414 , 0 ) ;
#endif
}
static int F_373 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_374 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_720 * V_720 = V_8 -> V_721 ;
T_2 V_19 , V_722 , V_263 ;
unsigned long V_723 , V_257 , V_724 ;
T_2 V_725 ;
enum V_726 V_727 ;
V_725 = V_73 -> V_728 ;
V_19 = V_73 -> V_729 ;
if ( F_21 ( V_19 ) )
return F_373 ( V_8 ) ;
if ( ( V_19 & V_20 ) == V_699 )
return 1 ;
if ( F_18 ( V_19 ) ) {
F_163 ( V_8 ) ;
return 1 ;
}
if ( F_19 ( V_19 ) ) {
V_727 = F_367 ( V_8 , V_730 ) ;
if ( V_727 != V_269 )
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
V_263 = 0 ;
if ( V_19 & V_266 )
V_263 = F_94 ( V_731 ) ;
if ( ( V_725 & V_732 ) &&
! ( F_17 ( V_19 ) && ! ( V_263 & V_733 ) ) ) {
V_8 -> V_721 -> V_259 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_737 ;
V_8 -> V_721 -> V_735 . V_738 = 2 ;
V_8 -> V_721 -> V_735 . V_183 [ 0 ] = V_725 ;
V_8 -> V_721 -> V_735 . V_183 [ 1 ] = V_19 ;
return 0 ;
}
if ( F_17 ( V_19 ) ) {
F_311 ( V_101 ) ;
V_723 = F_92 ( V_261 ) ;
F_375 ( V_723 , V_263 ) ;
if ( F_376 ( V_8 ) )
F_377 ( V_8 , V_723 ) ;
return F_378 ( V_8 , V_723 , V_263 , NULL , 0 ) ;
}
V_722 = V_19 & V_21 ;
if ( V_73 -> V_136 . V_137 && F_365 ( V_8 , V_722 ) )
return F_366 ( V_8 , V_722 , V_263 ) ;
switch ( V_722 ) {
case V_131 :
V_724 = F_92 ( V_261 ) ;
if ( ! ( V_8 -> V_132 &
( V_707 | V_708 ) ) ) {
V_8 -> V_116 . V_724 &= ~ 15 ;
V_8 -> V_116 . V_724 |= V_724 | V_739 ;
if ( ! ( V_724 & ~ V_740 ) )
F_175 ( V_8 ) ;
F_369 ( V_8 , V_131 ) ;
return 1 ;
}
V_720 -> V_741 . V_116 . V_724 = V_724 | V_742 ;
V_720 -> V_741 . V_116 . V_743 = F_92 ( V_744 ) ;
case V_135 :
V_73 -> V_8 . V_116 . V_268 =
F_94 ( V_258 ) ;
V_720 -> V_259 = V_745 ;
V_257 = F_176 ( V_8 ) ;
V_720 -> V_741 . V_116 . V_746 = F_92 ( V_671 ) + V_257 ;
V_720 -> V_741 . V_116 . V_747 = V_722 ;
break;
default:
V_720 -> V_259 = V_748 ;
V_720 -> V_749 . V_747 = V_722 ;
V_720 -> V_749 . V_263 = V_263 ;
break;
}
return 0 ;
}
static int F_379 ( struct V_7 * V_8 )
{
++ V_8 -> V_217 . V_750 ;
return 1 ;
}
static int F_380 ( struct V_7 * V_8 )
{
V_8 -> V_721 -> V_259 = V_751 ;
return 0 ;
}
static int F_381 ( struct V_7 * V_8 )
{
unsigned long V_752 ;
int V_444 , V_753 , string ;
unsigned V_754 ;
V_752 = F_92 ( V_261 ) ;
string = ( V_752 & 16 ) != 0 ;
V_753 = ( V_752 & 8 ) != 0 ;
++ V_8 -> V_217 . V_755 ;
if ( string || V_753 )
return F_367 ( V_8 , 0 ) == V_269 ;
V_754 = V_752 >> 16 ;
V_444 = ( V_752 & 7 ) + 1 ;
F_175 ( V_8 ) ;
return F_382 ( V_8 , V_444 , V_754 ) ;
}
static void
F_383 ( struct V_7 * V_8 , unsigned char * V_756 )
{
V_756 [ 0 ] = 0x0f ;
V_756 [ 1 ] = 0x01 ;
V_756 [ 2 ] = 0xc1 ;
}
static bool F_384 ( struct V_12 * V_12 , unsigned long V_106 )
{
unsigned long V_757 = F_209 ;
if ( V_359 &
V_56 &&
F_58 ( V_12 , V_56 ) )
V_757 &= ~ ( V_533 | V_527 ) ;
return ( V_106 & V_757 ) == V_757 ;
}
static int F_385 ( struct V_7 * V_8 , unsigned long V_106 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_758 = V_106 ;
V_106 = ( V_106 & ~ V_12 -> V_234 ) |
( V_12 -> V_237 & V_12 -> V_234 ) ;
if ( ! F_384 ( V_12 , V_106 ) )
return 1 ;
if ( F_386 ( V_8 , V_106 ) )
return 1 ;
F_99 ( V_242 , V_758 ) ;
return 0 ;
} else {
if ( F_6 ( V_8 ) -> V_13 . V_545 &&
( ( V_106 & F_209 ) != F_209 ) )
return 1 ;
return F_386 ( V_8 , V_106 ) ;
}
}
static int F_387 ( struct V_7 * V_8 , unsigned long V_106 )
{
if ( F_123 ( V_8 ) ) {
struct V_12 * V_12 = F_9 ( V_8 ) ;
unsigned long V_758 = V_106 ;
V_106 = ( V_106 & ~ V_12 -> V_240 ) |
( V_12 -> V_239 & V_12 -> V_240 ) ;
if ( F_388 ( V_8 , V_106 ) )
return 1 ;
F_99 ( V_492 , V_758 ) ;
return 0 ;
} else
return F_388 ( V_8 , V_106 ) ;
}
static void F_389 ( struct V_7 * V_8 )
{
if ( F_123 ( V_8 ) ) {
F_99 ( V_242 ,
F_92 ( V_242 ) & ~ V_231 ) ;
V_8 -> V_116 . V_229 &= ~ V_231 ;
} else
F_278 ( V_8 , F_164 ( V_8 , ~ V_231 ) ) ;
}
static int F_390 ( struct V_7 * V_8 )
{
unsigned long V_752 , V_106 ;
int V_759 ;
int V_412 ;
int V_760 ;
V_752 = F_92 ( V_261 ) ;
V_759 = V_752 & 15 ;
V_412 = ( V_752 >> 8 ) & 15 ;
switch ( ( V_752 >> 4 ) & 3 ) {
case 0 :
V_106 = F_391 ( V_8 , V_412 ) ;
F_392 ( V_759 , V_106 ) ;
switch ( V_759 ) {
case 0 :
V_760 = F_385 ( V_8 , V_106 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
case 3 :
V_760 = F_394 ( V_8 , V_106 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
case 4 :
V_760 = F_387 ( V_8 , V_106 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
case 8 : {
T_6 V_761 = F_395 ( V_8 ) ;
T_6 V_762 = ( T_6 ) V_106 ;
V_760 = F_347 ( V_8 , V_762 ) ;
F_393 ( V_8 , V_760 ) ;
if ( F_25 ( V_8 -> V_17 ) )
return 1 ;
if ( V_761 <= V_762 )
return 1 ;
V_8 -> V_721 -> V_259 = V_763 ;
return 0 ;
}
}
break;
case 2 :
F_389 ( V_8 ) ;
F_392 ( 0 , F_350 ( V_8 ) ) ;
F_175 ( V_8 ) ;
F_163 ( V_8 ) ;
return 1 ;
case 1 :
switch ( V_759 ) {
case 3 :
V_106 = F_280 ( V_8 ) ;
F_396 ( V_8 , V_412 , V_106 ) ;
F_397 ( V_759 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
case 8 :
V_106 = F_395 ( V_8 ) ;
F_396 ( V_8 , V_412 , V_106 ) ;
F_397 ( V_759 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
case 3 :
V_106 = ( V_752 >> V_764 ) & 0x0f ;
F_392 ( 0 , ( F_350 ( V_8 ) & ~ 0xful ) | V_106 ) ;
F_398 ( V_8 , V_106 ) ;
F_175 ( V_8 ) ;
return 1 ;
default:
break;
}
V_8 -> V_721 -> V_259 = 0 ;
F_399 ( V_8 , L_18 ,
( int ) ( V_752 >> 4 ) & 3 , V_759 ) ;
return 0 ;
}
static int F_400 ( struct V_7 * V_8 )
{
unsigned long V_752 ;
int V_765 , V_412 ;
if ( ! F_401 ( V_8 , 0 ) )
return 1 ;
V_765 = F_92 ( V_744 ) ;
if ( V_765 & V_766 ) {
if ( V_8 -> V_132 & V_708 ) {
V_8 -> V_721 -> V_741 . V_116 . V_724 = V_8 -> V_116 . V_724 ;
V_8 -> V_721 -> V_741 . V_116 . V_743 = V_765 ;
V_8 -> V_721 -> V_741 . V_116 . V_746 =
F_92 ( V_671 ) +
F_92 ( V_417 ) ;
V_8 -> V_721 -> V_741 . V_116 . V_747 = V_131 ;
V_8 -> V_721 -> V_259 = V_745 ;
return 0 ;
} else {
V_8 -> V_116 . V_743 &= ~ V_766 ;
V_8 -> V_116 . V_724 |= V_767 | V_739 ;
F_99 ( V_744 , V_8 -> V_116 . V_743 ) ;
F_369 ( V_8 , V_131 ) ;
return 1 ;
}
}
if ( V_8 -> V_132 == 0 ) {
T_2 V_69 ;
V_69 = F_94 ( V_528 ) ;
V_69 &= ~ V_349 ;
F_102 ( V_528 , V_69 ) ;
V_8 -> V_116 . V_632 |= V_633 ;
return 1 ;
}
V_752 = F_92 ( V_261 ) ;
V_765 = V_752 & V_768 ;
V_412 = F_402 ( V_752 ) ;
if ( V_752 & V_769 ) {
unsigned long V_106 ;
if ( F_403 ( V_8 , V_765 , & V_106 ) )
return 1 ;
F_396 ( V_8 , V_412 , V_106 ) ;
} else
if ( F_404 ( V_8 , V_765 , F_391 ( V_8 , V_412 ) ) )
return 1 ;
F_175 ( V_8 ) ;
return 1 ;
}
static T_3 F_405 ( struct V_7 * V_8 )
{
return V_8 -> V_116 . V_724 ;
}
static void F_406 ( struct V_7 * V_8 , unsigned long V_106 )
{
}
static void F_407 ( struct V_7 * V_8 )
{
T_2 V_69 ;
F_408 ( V_8 -> V_116 . V_497 [ 0 ] , 0 ) ;
F_408 ( V_8 -> V_116 . V_497 [ 1 ] , 1 ) ;
F_408 ( V_8 -> V_116 . V_497 [ 2 ] , 2 ) ;
F_408 ( V_8 -> V_116 . V_497 [ 3 ] , 3 ) ;
F_408 ( V_8 -> V_116 . V_724 , 6 ) ;
V_8 -> V_116 . V_743 = F_92 ( V_744 ) ;
V_8 -> V_116 . V_632 &= ~ V_633 ;
V_69 = F_94 ( V_528 ) ;
V_69 |= V_349 ;
F_102 ( V_528 , V_69 ) ;
}
static void F_409 ( struct V_7 * V_8 , unsigned long V_106 )
{
F_99 ( V_744 , V_106 ) ;
}
static int F_410 ( struct V_7 * V_8 )
{
F_411 ( V_8 ) ;
return 1 ;
}
static int F_412 ( struct V_7 * V_8 )
{
T_2 V_306 = V_8 -> V_116 . V_414 [ V_770 ] ;
T_3 V_183 ;
if ( F_211 ( V_8 , V_306 , & V_183 ) ) {
F_413 ( V_306 ) ;
F_414 ( V_8 , 0 ) ;
return 1 ;
}
F_415 ( V_306 , V_183 ) ;
V_8 -> V_116 . V_414 [ V_771 ] = V_183 & - 1u ;
V_8 -> V_116 . V_414 [ V_667 ] = ( V_183 >> 32 ) & - 1u ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_416 ( struct V_7 * V_8 )
{
struct V_401 V_74 ;
T_2 V_306 = V_8 -> V_116 . V_414 [ V_770 ] ;
T_3 V_183 = ( V_8 -> V_116 . V_414 [ V_771 ] & - 1u )
| ( ( T_3 ) ( V_8 -> V_116 . V_414 [ V_667 ] & - 1u ) << 32 ) ;
V_74 . V_183 = V_183 ;
V_74 . V_79 = V_306 ;
V_74 . V_409 = false ;
if ( F_417 ( V_8 , & V_74 ) != 0 ) {
F_418 ( V_306 , V_183 ) ;
F_414 ( V_8 , 0 ) ;
return 1 ;
}
F_419 ( V_306 , V_183 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_420 ( struct V_7 * V_8 )
{
F_156 ( V_602 , V_8 ) ;
return 1 ;
}
static int F_421 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_528 ) ;
V_69 &= ~ V_340 ;
F_102 ( V_528 , V_69 ) ;
F_156 ( V_602 , V_8 ) ;
++ V_8 -> V_217 . V_772 ;
if ( ! F_25 ( V_8 -> V_17 ) &&
V_8 -> V_721 -> V_773 &&
! F_422 ( V_8 ) ) {
V_8 -> V_721 -> V_259 = V_774 ;
return 0 ;
}
return 1 ;
}
static int F_423 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
return F_368 ( V_8 ) ;
}
static int F_424 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_425 ( V_8 ) ;
return 1 ;
}
static int F_426 ( struct V_7 * V_8 )
{
return F_367 ( V_8 , 0 ) == V_269 ;
}
static int F_427 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_92 ( V_261 ) ;
F_428 ( V_8 , V_752 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_429 ( struct V_7 * V_8 )
{
int V_760 ;
V_760 = F_430 ( V_8 ) ;
F_393 ( V_8 , V_760 ) ;
return 1 ;
}
static int F_431 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
F_432 ( V_8 ) ;
return 1 ;
}
static int F_433 ( struct V_7 * V_8 )
{
T_3 V_775 = F_434 ( V_8 ) ;
T_2 V_79 = F_435 ( V_8 , V_770 ) ;
if ( F_436 ( V_8 , V_79 , V_775 ) == 0 )
F_175 ( V_8 ) ;
return 1 ;
}
static int F_437 ( struct V_7 * V_8 )
{
if ( F_304 ( V_776 ) ) {
unsigned long V_752 = F_92 ( V_261 ) ;
int V_777 , V_299 ;
V_777 = V_752 & V_778 ;
V_299 = V_752 & V_779 ;
if ( ( V_777 == V_780 ) &&
( V_299 == V_781 ) ) {
F_438 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
}
return F_367 ( V_8 , 0 ) == V_269 ;
}
static int F_439 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_92 ( V_261 ) ;
int V_4 = V_752 & 0xff ;
F_440 ( V_8 , V_4 ) ;
return 1 ;
}
static int F_441 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_92 ( V_261 ) ;
T_2 V_299 = V_752 & 0xfff ;
F_442 ( V_8 , V_299 ) ;
return 1 ;
}
static int F_443 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_752 ;
bool V_262 = false ;
T_2 V_263 = 0 ;
T_4 V_782 ;
int V_783 , type , V_784 , V_785 ;
V_784 = ( V_73 -> V_728 & V_732 ) ;
V_785 = ( V_73 -> V_728 & V_786 ) ;
type = ( V_73 -> V_728 & V_787 ) ;
V_752 = F_92 ( V_261 ) ;
V_783 = ( T_2 ) V_752 >> 30 ;
if ( V_783 == V_788 && V_784 ) {
switch ( type ) {
case V_699 :
V_8 -> V_116 . V_789 = false ;
F_360 ( V_8 , true ) ;
break;
case V_27 :
case V_694 :
F_444 ( V_8 ) ;
break;
case V_23 :
if ( V_73 -> V_728 &
V_790 ) {
V_262 = true ;
V_263 =
F_94 ( V_791 ) ;
}
case V_272 :
F_445 ( V_8 ) ;
break;
default:
break;
}
}
V_782 = V_752 ;
if ( ! V_784 || ( type != V_23 &&
type != V_27 &&
type != V_699 ) )
F_175 ( V_8 ) ;
if ( F_446 ( V_8 , V_782 ,
type == V_694 ? V_785 : - 1 , V_783 ,
V_262 , V_263 ) == V_792 ) {
V_8 -> V_721 -> V_259 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_793 ;
V_8 -> V_721 -> V_735 . V_738 = 0 ;
return 0 ;
}
F_99 ( V_744 , F_92 ( V_744 ) & ~ 0x55 ) ;
return 1 ;
}
static int F_447 ( struct V_7 * V_8 )
{
unsigned long V_752 ;
T_1 V_85 ;
T_2 V_263 ;
int V_794 ;
V_752 = F_92 ( V_261 ) ;
V_794 = ( V_752 >> 7 ) & 0x3 ;
if ( V_794 != 0x3 && V_794 != 0x1 && V_794 != 0 ) {
F_69 ( V_89 L_19 ) ;
F_69 ( V_89 L_20 ,
( long unsigned int ) F_95 ( V_795 ) ,
F_92 ( V_796 ) ) ;
F_69 ( V_89 L_21 ,
( long unsigned int ) V_752 ) ;
V_8 -> V_721 -> V_259 = V_797 ;
V_8 -> V_721 -> V_798 . V_799 = V_800 ;
return 0 ;
}
if ( ! ( F_6 ( V_8 ) -> V_728 & V_732 ) &&
F_52 () &&
( V_752 & V_801 ) )
F_105 ( V_251 , V_700 ) ;
V_85 = F_95 ( V_795 ) ;
F_375 ( V_85 , V_752 ) ;
V_263 = V_752 & ( 1U << 1 ) ;
V_263 |= ( V_752 & ( 1U << 2 ) ) << 2 ;
V_263 |= ( V_752 >> 3 ) & 0x1 ;
V_8 -> V_116 . V_752 = V_752 ;
return F_378 ( V_8 , V_85 , V_263 , NULL , 0 ) ;
}
static T_3 F_448 ( T_3 V_802 , int V_803 )
{
int V_75 ;
T_3 V_105 = 0 ;
for ( V_75 = 51 ; V_75 > V_448 . V_804 ; V_75 -- )
V_105 |= ( 1ULL << V_75 ) ;
if ( V_803 == 4 )
V_105 |= 0xf8 ;
else if ( V_802 & ( 1ULL << 7 ) )
V_105 |= ( V_443 << ( ( V_803 - 1 ) * 9 ) ) - V_443 ;
else if ( V_803 > 1 )
V_105 |= 0x78 ;
return V_105 ;
}
static void F_449 ( struct V_7 * V_8 , T_3 V_802 ,
int V_803 )
{
F_69 ( V_89 L_22 , V_510 , V_802 , V_803 ) ;
F_450 ( ( V_802 & 0x7 ) == 0x2 ) ;
F_450 ( ( V_802 & 0x7 ) == 0x6 ) ;
if ( ! F_34 () )
F_450 ( ( V_802 & 0x7 ) == 0x4 ) ;
if ( ( V_802 & 0x7 ) ) {
T_3 V_805 = V_802 & F_448 ( V_802 , V_803 ) ;
if ( V_805 != 0 ) {
F_69 ( V_89 L_23 ,
V_510 , V_805 ) ;
F_450 ( 1 ) ;
}
if ( ( V_805 & 0x38 ) == 0 ) {
T_3 V_806 = ( V_802 & 0x38 ) >> 3 ;
if ( V_806 == 2 || V_806 == 3 ||
V_806 == 7 ) {
F_69 ( V_89 L_24 ,
V_510 , V_806 ) ;
F_450 ( 1 ) ;
}
}
}
}
static int F_451 ( struct V_7 * V_8 )
{
T_3 V_807 [ 4 ] ;
int V_808 , V_75 , V_114 ;
T_1 V_85 ;
V_85 = F_95 ( V_795 ) ;
if ( ! F_452 ( V_8 -> V_17 , V_809 , V_85 , 0 , NULL ) ) {
F_175 ( V_8 ) ;
return 1 ;
}
V_114 = F_453 ( V_8 , V_85 , true ) ;
if ( F_304 ( V_114 == V_810 ) )
return F_454 ( V_8 , V_85 , 0 , NULL , 0 ) ==
V_269 ;
if ( F_100 ( V_114 == V_811 ) )
return F_378 ( V_8 , V_85 , 0 , NULL , 0 ) ;
if ( F_100 ( V_114 == V_812 ) )
return 1 ;
F_69 ( V_89 L_25 ) ;
F_69 ( V_89 L_26 , V_85 ) ;
V_808 = F_455 ( V_8 , V_85 , V_807 ) ;
for ( V_75 = V_813 ; V_75 > V_813 - V_808 ; -- V_75 )
F_449 ( V_8 , V_807 [ V_75 - 1 ] , V_75 ) ;
V_8 -> V_721 -> V_259 = V_797 ;
V_8 -> V_721 -> V_798 . V_799 = V_814 ;
return 0 ;
}
static int F_456 ( struct V_7 * V_8 )
{
T_2 V_69 ;
V_69 = F_94 ( V_528 ) ;
V_69 &= ~ V_341 ;
F_102 ( V_528 , V_69 ) ;
++ V_8 -> V_217 . V_815 ;
F_156 ( V_602 , V_8 ) ;
return 1 ;
}
static int F_457 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
enum V_726 V_760 = V_269 ;
int V_114 = 1 ;
T_2 V_816 ;
bool V_817 ;
unsigned V_818 = 130 ;
V_816 = F_94 ( V_528 ) ;
V_817 = V_816 & V_340 ;
while ( V_73 -> F_253 && V_818 -- != 0 ) {
if ( V_817 && F_362 ( V_8 ) )
return F_421 ( & V_73 -> V_8 ) ;
if ( F_170 ( V_602 , & V_8 -> V_819 ) )
return 1 ;
V_760 = F_367 ( V_8 , V_820 ) ;
if ( V_760 == V_821 ) {
++ V_8 -> V_217 . V_822 ;
V_114 = 0 ;
goto V_551;
}
if ( V_760 != V_269 ) {
V_8 -> V_721 -> V_259 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_793 ;
V_8 -> V_721 -> V_735 . V_738 = 0 ;
return 0 ;
}
if ( V_8 -> V_116 . V_717 ) {
V_8 -> V_116 . V_717 = 0 ;
V_114 = F_368 ( V_8 ) ;
goto V_551;
}
if ( F_458 ( V_823 ) )
goto V_551;
if ( F_459 () )
F_460 () ;
}
V_551:
return V_114 ;
}
static int F_461 ( int V_106 )
{
if ( V_824 < 1 )
return V_652 ;
V_106 = V_434 ( V_106 , V_825 ) ;
if ( V_824 < V_652 )
V_106 *= V_824 ;
else
V_106 += V_824 ;
return V_106 ;
}
static int F_462 ( int V_106 , int V_826 , int V_827 )
{
if ( V_826 < 1 )
return V_652 ;
if ( V_826 < V_652 )
V_106 /= V_826 ;
else
V_106 -= V_826 ;
return F_463 ( V_106 , V_827 ) ;
}
static void F_464 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_421 = V_73 -> V_652 ;
V_73 -> V_652 = F_461 ( V_421 ) ;
if ( V_73 -> V_652 != V_421 )
V_73 -> V_653 = true ;
F_465 ( V_8 -> V_301 , V_73 -> V_652 , V_421 ) ;
}
static void F_466 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_421 = V_73 -> V_652 ;
V_73 -> V_652 = F_462 ( V_421 ,
V_828 , V_652 ) ;
if ( V_73 -> V_652 != V_421 )
V_73 -> V_653 = true ;
F_467 ( V_8 -> V_301 , V_73 -> V_652 , V_421 ) ;
}
static void F_468 ( void )
{
V_825 =
F_462 ( F_463 ( V_829 , V_652 ) ,
V_824 , V_830 ) ;
}
static int F_469 ( struct V_7 * V_8 )
{
if ( V_470 )
F_464 ( V_8 ) ;
F_175 ( V_8 ) ;
F_470 ( V_8 ) ;
return 1 ;
}
static int F_471 ( struct V_7 * V_8 )
{
F_175 ( V_8 ) ;
return 1 ;
}
static int F_472 ( struct V_7 * V_8 )
{
F_128 ( V_166 L_27 ) ;
return F_471 ( V_8 ) ;
}
static int F_473 ( struct V_7 * V_8 )
{
F_128 ( V_166 L_28 ) ;
return F_471 ( V_8 ) ;
}
static struct V_90 * F_474 ( struct V_6 * V_73 )
{
struct V_831 * V_832 ;
F_80 (item, &vmx->nested.vmcs02_pool, list)
if ( V_832 -> V_833 == V_73 -> V_13 . V_834 ) {
F_475 ( & V_832 -> V_835 , & V_73 -> V_13 . V_836 ) ;
return & V_832 -> V_837 ;
}
if ( V_73 -> V_13 . V_838 >= F_463 ( V_839 , 1 ) ) {
V_832 = F_476 ( V_73 -> V_13 . V_836 . V_840 ,
struct V_831 , V_835 ) ;
V_832 -> V_833 = V_73 -> V_13 . V_834 ;
F_475 ( & V_832 -> V_835 , & V_73 -> V_13 . V_836 ) ;
return & V_832 -> V_837 ;
}
V_832 = F_477 ( sizeof( struct V_831 ) , V_453 ) ;
if ( ! V_832 )
return NULL ;
V_832 -> V_837 . V_87 = F_240 () ;
if ( ! V_832 -> V_837 . V_87 ) {
F_478 ( V_832 ) ;
return NULL ;
}
F_70 ( & V_832 -> V_837 ) ;
V_832 -> V_833 = V_73 -> V_13 . V_834 ;
F_159 ( & ( V_832 -> V_835 ) , & ( V_73 -> V_13 . V_836 ) ) ;
V_73 -> V_13 . V_838 ++ ;
return & V_832 -> V_837 ;
}
static void F_479 ( struct V_6 * V_73 , T_1 V_833 )
{
struct V_831 * V_832 ;
F_80 (item, &vmx->nested.vmcs02_pool, list)
if ( V_832 -> V_833 == V_833 ) {
F_243 ( & V_832 -> V_837 ) ;
F_83 ( & V_832 -> V_835 ) ;
F_478 ( V_832 ) ;
V_73 -> V_13 . V_838 -- ;
return;
}
}
static void F_480 ( struct V_6 * V_73 )
{
struct V_831 * V_832 , * V_425 ;
F_450 ( V_73 -> V_90 != & V_73 -> V_841 ) ;
F_230 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_73 -> V_90 == & V_832 -> V_837 )
continue;
F_243 ( & V_832 -> V_837 ) ;
F_83 ( & V_832 -> V_835 ) ;
F_478 ( V_832 ) ;
V_73 -> V_13 . V_838 -- ;
}
}
static void F_481 ( struct V_7 * V_8 )
{
F_172 ( V_8 , F_169 ( V_8 )
& ~ ( V_842 | V_843 | V_844 |
V_845 | V_846 | V_847 ) ) ;
}
static void F_482 ( struct V_7 * V_8 )
{
F_172 ( V_8 , ( F_169 ( V_8 )
& ~ ( V_843 | V_844 | V_845 |
V_846 | V_847 ) )
| V_842 ) ;
}
static void F_483 ( struct V_7 * V_8 ,
T_2 V_848 )
{
if ( F_6 ( V_8 ) -> V_13 . V_834 == - 1ull ) {
F_482 ( V_8 ) ;
return;
}
F_172 ( V_8 , ( F_169 ( V_8 )
& ~ ( V_842 | V_843 | V_844 |
V_846 | V_847 ) )
| V_845 ) ;
F_9 ( V_8 ) -> V_848 = V_848 ;
}
static enum V_849 F_484 ( struct V_850 * V_851 )
{
struct V_6 * V_73 =
F_7 ( V_851 , struct V_6 , V_13 . V_852 ) ;
V_73 -> V_13 . V_853 = true ;
F_156 ( V_602 , & V_73 -> V_8 ) ;
F_328 ( & V_73 -> V_8 ) ;
return V_854 ;
}
static int F_485 ( struct V_7 * V_8 ,
unsigned long V_752 ,
T_2 V_855 , T_5 * V_114 )
{
int V_856 = V_855 & 3 ;
int V_857 = ( V_855 >> 7 ) & 7 ;
bool V_858 = V_855 & ( 1u << 10 ) ;
int V_859 = ( V_855 >> 15 ) & 7 ;
int V_860 = ( V_855 >> 18 ) & 0xf ;
bool V_861 = ! ( V_855 & ( 1u << 22 ) ) ;
int V_862 = ( V_855 >> 23 ) & 0xf ;
bool V_863 = ! ( V_855 & ( 1u << 27 ) ) ;
if ( V_858 ) {
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
* V_114 = F_281 ( V_8 , V_859 ) ;
if ( V_863 )
* V_114 += F_435 ( V_8 , V_862 ) ;
if ( V_861 )
* V_114 += F_435 ( V_8 , V_860 ) << V_856 ;
* V_114 += V_752 ;
if ( V_857 == 1 )
* V_114 &= 0xffffffff ;
return 0 ;
}
static int F_486 ( struct V_7 * V_8 , int V_259 ,
T_1 * V_864 )
{
T_5 V_81 ;
T_1 V_833 ;
struct V_865 V_866 ;
struct V_15 * V_15 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_867 = F_487 ( V_8 ) ;
if ( F_485 ( V_8 , F_92 ( V_261 ) ,
F_94 ( V_868 ) , & V_81 ) )
return 1 ;
if ( F_488 ( & V_8 -> V_116 . V_869 , V_81 , & V_833 ,
sizeof( V_833 ) , & V_866 ) ) {
F_489 ( V_8 , & V_866 ) ;
return 1 ;
}
switch ( V_259 ) {
case V_870 :
if ( ! F_490 ( V_833 ) || ( V_833 >> V_867 ) ) {
F_482 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
V_15 = F_10 ( V_8 , V_833 ) ;
if ( V_15 == NULL ||
* ( T_2 * ) F_491 ( V_15 ) != V_372 ) {
F_482 ( V_8 ) ;
F_492 ( V_15 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_492 ( V_15 ) ;
V_73 -> V_13 . V_871 = V_833 ;
break;
case V_872 :
if ( ! F_490 ( V_833 ) || ( V_833 >> V_867 ) ) {
F_483 ( V_8 ,
V_873 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_833 == V_73 -> V_13 . V_871 ) {
F_483 ( V_8 ,
V_874 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
case V_875 :
if ( ! F_490 ( V_833 ) || ( V_833 >> V_867 ) ) {
F_483 ( V_8 ,
V_876 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_833 == V_73 -> V_13 . V_871 ) {
F_483 ( V_8 ,
V_874 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
break;
default:
return 1 ;
}
if ( V_864 )
* V_864 = V_833 ;
return 0 ;
}
static int F_493 ( struct V_7 * V_8 )
{
struct V_477 V_557 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_87 * V_877 ;
const T_3 V_878 = V_408
| V_420 ;
if ( ! F_494 ( V_8 , V_423 ) ||
! F_164 ( V_8 , V_533 ) ||
( F_169 ( V_8 ) & V_249 ) ) {
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
F_258 ( V_8 , & V_557 , V_479 ) ;
if ( F_140 ( V_8 ) && ! V_557 . V_499 ) {
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
if ( F_282 ( V_8 ) ) {
F_414 ( V_8 , 0 ) ;
return 1 ;
}
if ( F_486 ( V_8 , V_870 , NULL ) )
return 1 ;
if ( V_73 -> V_13 . V_545 ) {
F_483 ( V_8 , V_879 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( ( V_73 -> V_13 . V_399 & V_878 )
!= V_878 ) {
F_414 ( V_8 , 0 ) ;
return 1 ;
}
if ( V_464 ) {
V_877 = F_240 () ;
if ( ! V_877 )
return - V_461 ;
V_877 -> V_446 |= ( 1u << 31 ) ;
F_67 ( V_877 ) ;
V_73 -> V_13 . V_880 = V_877 ;
}
F_226 ( & ( V_73 -> V_13 . V_836 ) ) ;
V_73 -> V_13 . V_838 = 0 ;
F_495 ( & V_73 -> V_13 . V_852 , V_881 ,
V_882 ) ;
V_73 -> V_13 . V_852 . V_883 = F_484 ;
V_73 -> V_13 . V_545 = true ;
F_175 ( V_8 ) ;
F_481 ( V_8 ) ;
return 1 ;
}
static int F_496 ( struct V_7 * V_8 )
{
struct V_477 V_557 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! V_73 -> V_13 . V_545 ) {
F_369 ( V_8 , V_26 ) ;
return 0 ;
}
F_258 ( V_8 , & V_557 , V_479 ) ;
if ( ( F_169 ( V_8 ) & V_249 ) ||
( F_140 ( V_8 ) && ! V_557 . V_499 ) ) {
F_369 ( V_8 , V_26 ) ;
return 0 ;
}
if ( F_282 ( V_8 ) ) {
F_414 ( V_8 , 0 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_497 ( struct V_6 * V_73 )
{
T_2 V_631 ;
if ( V_73 -> V_13 . V_834 == - 1ull )
return;
if ( F_450 ( V_73 -> V_13 . V_14 == NULL ) )
return;
if ( V_464 ) {
F_498 ( V_73 ) ;
V_73 -> V_13 . V_884 = false ;
V_631 = F_94 ( V_643 ) ;
V_631 &= ~ V_67 ;
F_102 ( V_643 , V_631 ) ;
F_103 ( V_641 , - 1ull ) ;
}
F_492 ( V_73 -> V_13 . V_885 ) ;
F_13 ( V_73 -> V_13 . V_885 ) ;
V_73 -> V_13 . V_834 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
}
static void F_499 ( struct V_6 * V_73 )
{
if ( ! V_73 -> V_13 . V_545 )
return;
V_73 -> V_13 . V_545 = false ;
F_497 ( V_73 ) ;
if ( V_464 )
F_241 ( V_73 -> V_13 . V_880 ) ;
if ( V_73 -> V_13 . V_886 ) {
F_13 ( V_73 -> V_13 . V_886 ) ;
V_73 -> V_13 . V_886 = NULL ;
}
if ( V_73 -> V_13 . V_887 ) {
F_13 ( V_73 -> V_13 . V_887 ) ;
V_73 -> V_13 . V_887 = NULL ;
}
F_480 ( V_73 ) ;
}
static int F_500 ( struct V_7 * V_8 )
{
if ( ! F_496 ( V_8 ) )
return 1 ;
F_499 ( F_6 ( V_8 ) ) ;
F_175 ( V_8 ) ;
F_481 ( V_8 ) ;
return 1 ;
}
static int F_501 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_1 V_833 ;
struct V_12 * V_12 ;
struct V_15 * V_15 ;
if ( ! F_496 ( V_8 ) )
return 1 ;
if ( F_486 ( V_8 , V_872 , & V_833 ) )
return 1 ;
if ( V_833 == V_73 -> V_13 . V_834 )
F_497 ( V_73 ) ;
V_15 = F_10 ( V_8 , V_833 ) ;
if ( V_15 == NULL ) {
F_156 ( V_270 , V_8 ) ;
return 1 ;
}
V_12 = F_491 ( V_15 ) ;
V_12 -> V_888 = 0 ;
F_492 ( V_15 ) ;
F_13 ( V_15 ) ;
F_479 ( V_73 , V_833 ) ;
F_175 ( V_8 ) ;
F_481 ( V_8 ) ;
return 1 ;
}
static int F_502 ( struct V_7 * V_8 )
{
return F_503 ( V_8 , true ) ;
}
static int F_504 ( struct V_7 * V_8 )
{
return F_503 ( V_8 , false ) ;
}
static inline int F_505 ( unsigned long V_9 )
{
if ( 0x1 & V_9 )
return V_889 ;
return ( V_9 >> 13 ) & 0x3 ;
}
static inline int F_506 ( unsigned long V_9 )
{
return ( ( ( V_9 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_507 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 * V_114 )
{
short V_299 = F_8 ( V_9 ) ;
char * V_119 ;
if ( V_299 < 0 )
return 0 ;
V_119 = ( ( char * ) ( F_9 ( V_8 ) ) ) + V_299 ;
switch ( F_505 ( V_9 ) ) {
case V_890 :
* V_114 = * ( ( V_891 * ) V_119 ) ;
return 1 ;
case V_892 :
* V_114 = * ( ( T_4 * ) V_119 ) ;
return 1 ;
case V_889 :
* V_114 = * ( ( T_2 * ) V_119 ) ;
return 1 ;
case V_893 :
* V_114 = * ( ( T_3 * ) V_119 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline bool F_508 ( struct V_7 * V_8 ,
unsigned long V_9 , T_3 V_894 ) {
short V_299 = F_8 ( V_9 ) ;
char * V_119 = ( ( char * ) F_9 ( V_8 ) ) + V_299 ;
if ( V_299 < 0 )
return false ;
switch ( F_505 ( V_9 ) ) {
case V_892 :
* ( T_4 * ) V_119 = V_894 ;
return true ;
case V_889 :
* ( T_2 * ) V_119 = V_894 ;
return true ;
case V_893 :
* ( T_3 * ) V_119 = V_894 ;
return true ;
case V_890 :
* ( V_891 * ) V_119 = V_894 ;
return true ;
default:
return false ;
}
}
static void F_498 ( struct V_6 * V_73 )
{
int V_75 ;
unsigned long V_9 ;
T_3 V_894 ;
struct V_87 * V_877 = V_73 -> V_13 . V_880 ;
const unsigned long * V_236 = V_456 ;
const int V_895 = V_455 ;
F_152 () ;
F_71 ( V_877 ) ;
for ( V_75 = 0 ; V_75 < V_895 ; V_75 ++ ) {
V_9 = V_236 [ V_75 ] ;
switch ( F_505 ( V_9 ) ) {
case V_892 :
V_894 = F_93 ( V_9 ) ;
break;
case V_889 :
V_894 = F_94 ( V_9 ) ;
break;
case V_893 :
V_894 = F_95 ( V_9 ) ;
break;
case V_890 :
V_894 = F_92 ( V_9 ) ;
break;
}
F_508 ( & V_73 -> V_8 , V_9 , V_894 ) ;
}
F_67 ( V_877 ) ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
F_153 () ;
}
static void F_509 ( struct V_6 * V_73 )
{
const unsigned long * V_236 [] = {
V_456 ,
V_460
} ;
const int V_896 [] = {
V_455 ,
V_459
} ;
int V_75 , V_897 ;
unsigned long V_9 ;
T_3 V_894 = 0 ;
struct V_87 * V_877 = V_73 -> V_13 . V_880 ;
F_71 ( V_877 ) ;
for ( V_897 = 0 ; V_897 < F_342 ( V_236 ) ; V_897 ++ ) {
for ( V_75 = 0 ; V_75 < V_896 [ V_897 ] ; V_75 ++ ) {
V_9 = V_236 [ V_897 ] [ V_75 ] ;
F_507 ( & V_73 -> V_8 , V_9 , & V_894 ) ;
switch ( F_505 ( V_9 ) ) {
case V_892 :
F_101 ( V_9 , ( T_4 ) V_894 ) ;
break;
case V_889 :
F_102 ( V_9 , ( T_2 ) V_894 ) ;
break;
case V_893 :
F_103 ( V_9 , ( T_3 ) V_894 ) ;
break;
case V_890 :
F_99 ( V_9 , ( long ) V_894 ) ;
break;
}
}
}
F_67 ( V_877 ) ;
F_71 ( V_73 -> V_90 -> V_87 ) ;
}
static int F_510 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( V_73 -> V_13 . V_834 == - 1ull ) {
F_482 ( V_8 ) ;
F_175 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_511 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_3 V_894 ;
unsigned long V_752 = F_92 ( V_261 ) ;
T_2 V_855 = F_94 ( V_868 ) ;
T_5 V_81 = 0 ;
if ( ! F_496 ( V_8 ) ||
! F_510 ( V_8 ) )
return 1 ;
V_9 = F_391 ( V_8 , ( ( ( V_855 ) >> 28 ) & 0xf ) ) ;
if ( ! F_507 ( V_8 , V_9 , & V_894 ) ) {
F_483 ( V_8 , V_898 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( V_855 & ( 1u << 10 ) ) {
F_512 ( V_8 , ( ( ( V_855 ) >> 3 ) & 0xf ) ,
V_894 ) ;
} else {
if ( F_485 ( V_8 , V_752 ,
V_855 , & V_81 ) )
return 1 ;
F_513 ( & V_8 -> V_116 . V_869 , V_81 ,
& V_894 , ( F_140 ( V_8 ) ? 8 : 4 ) , NULL ) ;
}
F_481 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_514 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
T_5 V_81 ;
unsigned long V_752 = F_92 ( V_261 ) ;
T_2 V_855 = F_94 ( V_868 ) ;
T_3 V_894 = 0 ;
struct V_865 V_866 ;
if ( ! F_496 ( V_8 ) ||
! F_510 ( V_8 ) )
return 1 ;
if ( V_855 & ( 1u << 10 ) )
V_894 = F_391 ( V_8 ,
( ( ( V_855 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_485 ( V_8 , V_752 ,
V_855 , & V_81 ) )
return 1 ;
if ( F_488 ( & V_8 -> V_116 . V_869 , V_81 ,
& V_894 , ( F_515 ( V_8 ) ? 8 : 4 ) , & V_866 ) ) {
F_489 ( V_8 , & V_866 ) ;
return 1 ;
}
}
V_9 = F_391 ( V_8 , ( ( ( V_855 ) >> 28 ) & 0xf ) ) ;
if ( F_506 ( V_9 ) ) {
F_483 ( V_8 ,
V_899 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
if ( ! F_508 ( V_8 , V_9 , V_894 ) ) {
F_483 ( V_8 , V_898 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_481 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_516 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_1 V_833 ;
T_2 V_631 ;
if ( ! F_496 ( V_8 ) )
return 1 ;
if ( F_486 ( V_8 , V_875 , & V_833 ) )
return 1 ;
if ( V_73 -> V_13 . V_834 != V_833 ) {
struct V_12 * V_900 ;
struct V_15 * V_15 ;
V_15 = F_10 ( V_8 , V_833 ) ;
if ( V_15 == NULL ) {
F_482 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
V_900 = F_491 ( V_15 ) ;
if ( V_900 -> V_446 != V_372 ) {
F_492 ( V_15 ) ;
F_15 ( V_15 ) ;
F_483 ( V_8 ,
V_901 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
F_497 ( V_73 ) ;
V_73 -> V_13 . V_834 = V_833 ;
V_73 -> V_13 . V_14 = V_900 ;
V_73 -> V_13 . V_885 = V_15 ;
if ( V_464 ) {
V_631 = F_94 ( V_643 ) ;
V_631 |= V_67 ;
F_102 ( V_643 , V_631 ) ;
F_103 ( V_641 ,
F_68 ( V_73 -> V_13 . V_880 ) ) ;
V_73 -> V_13 . V_884 = true ;
}
}
F_481 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_517 ( struct V_7 * V_8 )
{
unsigned long V_752 = F_92 ( V_261 ) ;
T_2 V_855 = F_94 ( V_868 ) ;
T_5 V_902 ;
struct V_865 V_866 ;
if ( ! F_496 ( V_8 ) )
return 1 ;
if ( F_485 ( V_8 , V_752 ,
V_855 , & V_902 ) )
return 1 ;
if ( F_513 ( & V_8 -> V_116 . V_869 , V_902 ,
( void * ) & F_6 ( V_8 ) -> V_13 . V_834 ,
sizeof( T_3 ) , & V_866 ) ) {
F_489 ( V_8 , & V_866 ) ;
return 1 ;
}
F_481 ( V_8 ) ;
F_175 ( V_8 ) ;
return 1 ;
}
static int F_518 ( struct V_7 * V_8 )
{
T_2 V_855 , V_903 ;
unsigned long type ;
T_5 V_81 ;
struct V_865 V_866 ;
struct {
T_3 V_84 , V_85 ;
} V_83 ;
if ( ! ( V_359 & V_55 ) ||
! ( V_360 & V_361 ) ) {
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
if ( ! F_496 ( V_8 ) )
return 1 ;
if ( ! F_164 ( V_8 , V_533 ) ) {
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
V_855 = F_94 ( V_868 ) ;
type = F_391 ( V_8 , ( V_855 >> 28 ) & 0xf ) ;
V_903 = ( V_360 >> V_904 ) & 6 ;
if ( ! ( V_903 & ( 1UL << type ) ) ) {
F_483 ( V_8 ,
V_905 ) ;
return 1 ;
}
if ( F_485 ( V_8 , F_92 ( V_261 ) ,
V_855 , & V_81 ) )
return 1 ;
if ( F_488 ( & V_8 -> V_116 . V_869 , V_81 , & V_83 ,
sizeof( V_83 ) , & V_866 ) ) {
F_489 ( V_8 , & V_866 ) ;
return 1 ;
}
switch ( type ) {
case V_100 :
F_519 ( V_8 ) ;
F_156 ( V_223 , V_8 ) ;
F_481 ( V_8 ) ;
break;
default:
F_311 ( 1 ) ;
break;
}
F_175 ( V_8 ) ;
return 1 ;
}
static int F_520 ( struct V_7 * V_8 )
{
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
static bool F_521 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_752 ;
T_1 V_906 , V_907 ;
unsigned int V_754 ;
int V_444 ;
T_6 V_908 ;
if ( ! F_57 ( V_12 , V_351 ) )
return F_57 ( V_12 , V_350 ) ;
V_752 = F_92 ( V_261 ) ;
V_754 = V_752 >> 16 ;
V_444 = ( V_752 & 7 ) + 1 ;
V_907 = ( T_1 ) - 1 ;
V_908 = - 1 ;
while ( V_444 > 0 ) {
if ( V_754 < 0x8000 )
V_906 = V_12 -> V_909 ;
else if ( V_754 < 0x10000 )
V_906 = V_12 -> V_910 ;
else
return 1 ;
V_906 += ( V_754 & 0x7fff ) / 8 ;
if ( V_907 != V_906 )
if ( F_522 ( V_8 -> V_17 , V_906 , & V_908 , 1 ) )
return 1 ;
if ( V_908 & ( 1 << ( V_754 & 7 ) ) )
return 1 ;
V_754 ++ ;
V_444 -- ;
V_907 = V_906 ;
}
return 0 ;
}
static bool F_523 ( struct V_7 * V_8 ,
struct V_12 * V_12 , T_2 V_259 )
{
T_2 V_369 = V_8 -> V_116 . V_414 [ V_770 ] ;
T_1 V_906 ;
if ( ! F_57 ( V_12 , V_31 ) )
return 1 ;
V_906 = V_12 -> V_277 ;
if ( V_259 == V_911 )
V_906 += 2048 ;
if ( V_369 >= 0xc0000000 ) {
V_369 -= 0xc0000000 ;
V_906 += 1024 ;
}
if ( V_369 < 1024 * 8 ) {
unsigned char V_908 ;
if ( F_522 ( V_8 -> V_17 , V_906 + V_369 / 8 , & V_908 , 1 ) )
return 1 ;
return 1 & ( V_908 >> ( V_369 & 7 ) ) ;
} else
return 1 ;
}
static bool F_524 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
unsigned long V_752 = F_92 ( V_261 ) ;
int V_759 = V_752 & 15 ;
int V_412 = ( V_752 >> 8 ) & 15 ;
unsigned long V_106 = F_391 ( V_8 , V_412 ) ;
switch ( ( V_752 >> 4 ) & 3 ) {
case 0 :
switch ( V_759 ) {
case 0 :
if ( V_12 -> V_234 &
( V_106 ^ V_12 -> V_238 ) )
return 1 ;
break;
case 3 :
if ( ( V_12 -> V_912 >= 1 &&
V_12 -> V_913 == V_106 ) ||
( V_12 -> V_912 >= 2 &&
V_12 -> V_914 == V_106 ) ||
( V_12 -> V_912 >= 3 &&
V_12 -> V_915 == V_106 ) ||
( V_12 -> V_912 >= 4 &&
V_12 -> V_916 == V_106 ) )
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
switch ( V_759 ) {
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
static bool F_525 ( struct V_7 * V_8 )
{
T_2 V_19 = F_94 ( V_260 ) ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_259 = V_73 -> V_259 ;
F_526 ( F_176 ( V_8 ) , V_259 ,
F_92 ( V_261 ) ,
V_73 -> V_728 ,
V_19 ,
F_94 ( V_731 ) ,
V_917 ) ;
if ( V_73 -> V_13 . V_702 )
return 0 ;
if ( F_100 ( V_73 -> V_918 ) ) {
F_527 ( L_29 , V_510 ,
F_94 ( V_104 ) ) ;
return 1 ;
}
switch ( V_259 ) {
case V_919 :
if ( ! F_62 ( V_19 ) )
return 0 ;
else if ( F_17 ( V_19 ) )
return V_101 ;
else if ( F_18 ( V_19 ) &&
! ( V_12 -> V_237 & V_231 ) )
return 0 ;
return V_12 -> V_139 &
( 1u << ( V_19 & V_21 ) ) ;
case V_920 :
return 0 ;
case V_921 :
return 1 ;
case V_922 :
return F_57 ( V_12 , V_340 ) ;
case V_923 :
return F_57 ( V_12 , V_341 ) ;
case V_924 :
return 1 ;
case V_925 :
if ( F_435 ( V_8 , V_771 ) == 0xa )
return 0 ;
return 1 ;
case V_926 :
return F_57 ( V_12 , V_342 ) ;
case V_927 :
return 1 ;
case V_928 :
return F_57 ( V_12 , V_343 ) ;
case V_929 :
return F_57 ( V_12 , V_353 ) ;
case V_930 :
return F_57 ( V_12 , V_354 ) ;
case V_931 : case V_872 :
case V_932 : case V_875 :
case V_933 : case V_934 :
case V_935 : case V_936 :
case V_937 : case V_870 :
case V_938 : case V_939 :
return 1 ;
case V_940 :
return F_524 ( V_8 , V_12 ) ;
case V_941 :
return F_57 ( V_12 , V_349 ) ;
case V_942 :
return F_521 ( V_8 , V_12 ) ;
case V_943 :
case V_911 :
return F_523 ( V_8 , V_12 , V_259 ) ;
case V_944 :
return 1 ;
case V_945 :
return F_57 ( V_12 , V_344 ) ;
case V_946 :
return F_57 ( V_12 , V_352 ) ;
case V_947 :
return F_57 ( V_12 , V_355 ) ||
F_58 ( V_12 ,
V_57 ) ;
case V_948 :
return 0 ;
case V_949 :
return F_57 ( V_12 , V_32 ) ;
case V_950 :
return F_58 ( V_12 ,
V_35 ) ;
case V_800 :
return 0 ;
case V_814 :
return 0 ;
case V_951 :
return F_58 ( V_12 , V_63 ) ;
case V_952 :
return 1 ;
default:
return 1 ;
}
}
static void F_528 ( struct V_7 * V_8 , T_3 * V_953 , T_3 * V_954 )
{
* V_953 = F_92 ( V_261 ) ;
* V_954 = F_94 ( V_260 ) ;
}
static int F_529 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_259 = V_73 -> V_259 ;
T_2 V_955 = V_73 -> V_728 ;
if ( V_73 -> F_253 )
return F_457 ( V_8 ) ;
if ( F_123 ( V_8 ) && F_525 ( V_8 ) ) {
F_179 ( V_8 , V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
return 1 ;
}
if ( V_259 & V_956 ) {
V_8 -> V_721 -> V_259 = V_957 ;
V_8 -> V_721 -> V_958 . V_959
= V_259 ;
return 0 ;
}
if ( F_100 ( V_73 -> V_918 ) ) {
V_8 -> V_721 -> V_259 = V_957 ;
V_8 -> V_721 -> V_958 . V_959
= F_94 ( V_104 ) ;
return 0 ;
}
if ( ( V_955 & V_732 ) &&
( V_259 != V_919 &&
V_259 != V_800 &&
V_259 != V_924 ) ) {
V_8 -> V_721 -> V_259 = V_734 ;
V_8 -> V_721 -> V_735 . V_736 = V_960 ;
V_8 -> V_721 -> V_735 . V_738 = 2 ;
V_8 -> V_721 -> V_735 . V_183 [ 0 ] = V_955 ;
V_8 -> V_721 -> V_735 . V_183 [ 1 ] = V_259 ;
return 0 ;
}
if ( F_100 ( ! F_52 () && V_73 -> V_666 &&
! ( F_123 ( V_8 ) && F_59 (
F_9 ( V_8 ) ) ) ) ) {
if ( F_362 ( V_8 ) ) {
V_73 -> V_666 = 0 ;
} else if ( V_73 -> V_695 > 1000000000LL &&
V_8 -> V_116 . V_961 ) {
F_69 ( V_166 L_30
L_31 ,
V_510 , V_8 -> V_301 ) ;
V_73 -> V_666 = 0 ;
}
}
if ( V_259 < V_962
&& V_963 [ V_259 ] )
return V_963 [ V_259 ] ( V_8 ) ;
else {
F_530 ( 1 , L_32 , V_259 ) ;
F_369 ( V_8 , V_26 ) ;
return 1 ;
}
}
static void V_469 ( struct V_7 * V_8 , int V_964 , int V_965 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
if ( F_123 ( V_8 ) &&
F_57 ( V_12 , V_32 ) )
return;
if ( V_965 == - 1 || V_964 < V_965 ) {
F_102 ( V_682 , 0 ) ;
return;
}
F_102 ( V_682 , V_965 ) ;
}
static void F_531 ( struct V_7 * V_8 , bool V_966 )
{
T_2 V_967 ;
if ( ! F_28 () ||
! F_324 ( V_8 -> V_17 ) )
return;
if ( ! F_24 ( V_8 -> V_17 ) )
return;
V_967 = F_94 ( V_643 ) ;
if ( V_966 ) {
V_967 &= ~ V_35 ;
V_967 |= V_36 ;
} else {
V_967 &= ~ V_36 ;
V_967 |= V_35 ;
}
F_102 ( V_643 , V_967 ) ;
F_186 ( V_8 ) ;
}
static void F_532 ( struct V_7 * V_8 , T_16 V_968 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( ! F_123 ( V_8 ) ||
! F_58 ( V_73 -> V_13 . V_14 ,
V_35 ) )
F_103 ( V_969 , V_968 ) ;
}
static void F_533 ( struct V_17 * V_17 , int V_970 )
{
T_4 V_971 ;
T_6 V_421 ;
if ( ! F_324 ( V_17 ) )
return;
if ( V_970 == - 1 )
V_970 = 0 ;
V_971 = F_93 ( V_648 ) ;
V_421 = V_971 >> 8 ;
if ( V_970 != V_421 ) {
V_971 &= 0xff ;
V_971 |= V_970 << 8 ;
F_101 ( V_648 , V_971 ) ;
}
}
static void F_534 ( int V_4 )
{
T_4 V_971 ;
T_6 V_421 ;
V_971 = F_93 ( V_648 ) ;
V_421 = ( T_6 ) V_971 & 0xff ;
if ( ( T_6 ) V_4 != V_421 ) {
V_971 &= ~ 0xff ;
V_971 |= ( T_6 ) V_4 ;
F_101 ( V_648 , V_971 ) ;
}
}
static void F_535 ( struct V_7 * V_8 , int V_972 )
{
if ( V_972 == - 1 )
return;
if ( F_123 ( V_8 ) && F_351 ( V_8 ) )
return;
if ( ! F_123 ( V_8 ) ) {
F_534 ( V_972 ) ;
return;
}
if ( ! F_376 ( V_8 ) &&
F_362 ( V_8 ) ) {
F_536 ( V_8 , V_972 , false ) ;
F_356 ( V_8 ) ;
}
}
static void F_537 ( struct V_7 * V_8 , T_3 * V_973 )
{
if ( ! F_324 ( V_8 -> V_17 ) )
return;
F_103 ( V_644 , V_973 [ 0 ] ) ;
F_103 ( V_645 , V_973 [ 1 ] ) ;
F_103 ( V_646 , V_973 [ 2 ] ) ;
F_103 ( V_647 , V_973 [ 3 ] ) ;
}
static void F_538 ( struct V_6 * V_73 )
{
T_2 V_729 ;
if ( ! ( V_73 -> V_259 == V_948
|| V_73 -> V_259 == V_919 ) )
return;
V_73 -> V_729 = F_94 ( V_260 ) ;
V_729 = V_73 -> V_729 ;
if ( F_21 ( V_729 ) )
F_370 () ;
if ( ( V_729 & V_20 ) == V_699 &&
( V_729 & V_22 ) ) {
F_539 ( & V_73 -> V_8 ) ;
asm("int $2");
F_540 ( & V_73 -> V_8 ) ;
}
}
static void F_541 ( struct V_7 * V_8 )
{
T_2 V_729 = F_94 ( V_260 ) ;
if ( ( V_729 & ( V_22 | V_20 ) )
== ( V_22 | V_27 ) ) {
unsigned int V_4 ;
unsigned long V_141 ;
T_17 * V_974 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
#ifdef F_96
unsigned long V_276 ;
#endif
V_4 = V_729 & V_21 ;
V_974 = ( T_17 * ) V_73 -> V_622 + V_4 ;
V_141 = F_542 ( * V_974 ) ;
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
static void F_543 ( struct V_6 * V_73 )
{
T_2 V_729 ;
bool V_975 ;
T_6 V_4 ;
bool V_976 ;
V_976 = V_73 -> V_728 & V_732 ;
if ( F_52 () ) {
if ( V_73 -> V_697 )
return;
V_729 = F_94 ( V_260 ) ;
V_975 = ( V_729 & V_801 ) != 0 ;
V_4 = V_729 & V_21 ;
if ( ( V_729 & V_22 ) && V_975 &&
V_4 != V_712 && ! V_976 )
F_105 ( V_251 ,
V_700 ) ;
else
V_73 -> V_697 =
! ( F_94 ( V_251 )
& V_700 ) ;
} else if ( F_100 ( V_73 -> V_666 ) )
V_73 -> V_695 +=
F_544 ( F_545 ( F_546 () , V_73 -> V_977 ) ) ;
}
static void F_547 ( struct V_7 * V_8 ,
T_2 V_728 ,
int V_978 ,
int V_979 )
{
T_6 V_4 ;
int type ;
bool V_976 ;
V_976 = V_728 & V_732 ;
V_8 -> V_116 . V_789 = false ;
F_445 ( V_8 ) ;
F_444 ( V_8 ) ;
if ( ! V_976 )
return;
F_156 ( V_602 , V_8 ) ;
V_4 = V_728 & V_786 ;
type = V_728 & V_787 ;
switch ( type ) {
case V_699 :
V_8 -> V_116 . V_789 = true ;
F_360 ( V_8 , false ) ;
break;
case V_272 :
V_8 -> V_116 . V_268 = F_94 ( V_978 ) ;
case V_23 :
if ( V_728 & V_790 ) {
T_2 V_760 = F_94 ( V_979 ) ;
F_548 ( V_8 , V_4 , V_760 ) ;
} else
F_549 ( V_8 , V_4 ) ;
break;
case V_694 :
V_8 -> V_116 . V_268 = F_94 ( V_978 ) ;
case V_27 :
F_536 ( V_8 , V_4 , type == V_694 ) ;
break;
default:
break;
}
}
static void F_550 ( struct V_6 * V_73 )
{
F_547 ( & V_73 -> V_8 , V_73 -> V_728 ,
V_258 ,
V_791 ) ;
}
static void F_551 ( struct V_7 * V_8 )
{
F_547 ( V_8 ,
F_94 ( V_273 ) ,
V_271 ,
V_265 ) ;
F_102 ( V_273 , 0 ) ;
}
static void F_552 ( struct V_6 * V_73 )
{
int V_75 , V_980 ;
struct V_981 * V_982 ;
V_982 = F_553 ( & V_980 ) ;
if ( ! V_982 )
return;
for ( V_75 = 0 ; V_75 < V_980 ; V_75 ++ )
if ( V_982 [ V_75 ] . V_154 == V_982 [ V_75 ] . V_153 )
F_125 ( V_73 , V_982 [ V_75 ] . V_74 ) ;
else
F_127 ( V_73 , V_982 [ V_75 ] . V_74 , V_982 [ V_75 ] . V_153 ,
V_982 [ V_75 ] . V_154 ) ;
}
static void T_18 F_554 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
unsigned long V_983 , V_517 ;
if ( F_100 ( ! F_52 () && V_73 -> V_666 ) )
V_73 -> V_977 = F_546 () ;
if ( V_73 -> F_253 )
return;
if ( V_73 -> V_653 ) {
V_73 -> V_653 = false ;
F_102 ( V_984 , V_73 -> V_652 ) ;
}
if ( V_73 -> V_13 . V_884 ) {
F_509 ( V_73 ) ;
V_73 -> V_13 . V_884 = false ;
}
if ( F_170 ( V_413 , ( unsigned long * ) & V_8 -> V_116 . V_520 ) )
F_99 ( V_415 , V_8 -> V_116 . V_414 [ V_413 ] ) ;
if ( F_170 ( V_416 , ( unsigned long * ) & V_8 -> V_116 . V_520 ) )
F_99 ( V_417 , V_8 -> V_116 . V_414 [ V_416 ] ) ;
V_517 = F_225 () ;
if ( F_100 ( V_517 != V_73 -> V_191 . V_613 ) ) {
F_99 ( V_612 , V_517 ) ;
V_73 -> V_191 . V_613 = V_517 ;
}
if ( V_8 -> V_132 & V_707 )
F_174 ( V_8 , 0 ) ;
F_552 ( V_73 ) ;
V_983 = F_555 () ;
V_73 -> V_985 = V_73 -> V_90 -> V_92 ;
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
if ( V_983 )
F_556 ( V_983 ) ;
#ifndef F_96
F_147 ( V_202 , V_986 ) ;
F_147 ( V_204 , V_986 ) ;
#endif
V_8 -> V_116 . V_117 = ~ ( ( 1 << V_416 ) | ( 1 << V_413 )
| ( 1 << V_245 )
| ( 1 << V_418 )
| ( 1 << V_118 )
| ( 1 << V_515 ) ) ;
V_8 -> V_116 . V_520 = 0 ;
V_73 -> V_728 = F_94 ( V_987 ) ;
V_73 -> V_90 -> V_92 = 1 ;
V_73 -> V_259 = F_94 ( V_988 ) ;
F_557 ( V_73 -> V_259 , V_8 , V_917 ) ;
if ( V_73 -> V_13 . V_702 )
F_156 ( V_602 , V_8 ) ;
V_73 -> V_13 . V_702 = 0 ;
F_538 ( V_73 ) ;
F_543 ( V_73 ) ;
F_550 ( V_73 ) ;
}
static void F_558 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_91 ;
if ( V_73 -> V_90 == & V_73 -> V_841 )
return;
V_91 = F_559 () ;
V_73 -> V_90 = & V_73 -> V_841 ;
F_161 ( V_8 ) ;
F_154 ( V_8 , V_91 ) ;
V_8 -> V_91 = V_91 ;
F_560 () ;
}
static void F_561 ( struct V_7 * V_8 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
F_316 ( V_73 ) ;
F_562 ( V_8 ) ;
F_558 ( V_8 ) ;
F_499 ( V_73 ) ;
F_243 ( V_73 -> V_90 ) ;
F_478 ( V_73 -> V_78 ) ;
F_563 ( V_8 ) ;
F_564 ( V_989 , V_73 ) ;
}
static struct V_7 * F_565 ( struct V_17 * V_17 , unsigned int V_990 )
{
int V_760 ;
struct V_6 * V_73 = F_566 ( V_989 , V_453 ) ;
int V_91 ;
if ( ! V_73 )
return F_567 ( - V_461 ) ;
F_312 ( V_73 ) ;
V_760 = F_568 ( & V_73 -> V_8 , V_17 , V_990 ) ;
if ( V_760 )
goto V_991;
V_73 -> V_78 = F_477 ( V_443 , V_453 ) ;
F_569 ( F_342 ( V_77 ) * sizeof( V_73 -> V_78 [ 0 ] )
> V_443 ) ;
V_760 = - V_461 ;
if ( ! V_73 -> V_78 ) {
goto V_992;
}
V_73 -> V_90 = & V_73 -> V_841 ;
V_73 -> V_90 -> V_87 = F_240 () ;
if ( ! V_73 -> V_90 -> V_87 )
goto V_993;
if ( ! V_221 )
F_155 ( F_68 ( F_82 ( V_220 , F_79 () ) ) ) ;
F_70 ( V_73 -> V_90 ) ;
if ( ! V_221 )
F_162 () ;
V_91 = F_559 () ;
F_154 ( & V_73 -> V_8 , V_91 ) ;
V_73 -> V_8 . V_91 = V_91 ;
V_760 = F_341 ( V_73 ) ;
F_161 ( & V_73 -> V_8 ) ;
F_560 () ;
if ( V_760 )
goto F_241;
if ( F_48 ( V_17 ) ) {
V_760 = F_308 ( V_17 ) ;
if ( V_760 )
goto F_241;
}
if ( V_101 ) {
if ( ! V_17 -> V_116 . V_541 )
V_17 -> V_116 . V_541 =
V_994 ;
V_760 = F_302 ( V_17 ) ;
if ( V_760 )
goto F_241;
}
V_73 -> V_13 . V_834 = - 1ull ;
V_73 -> V_13 . V_14 = NULL ;
return & V_73 -> V_8 ;
F_241:
F_243 ( V_73 -> V_90 ) ;
V_993:
F_478 ( V_73 -> V_78 ) ;
V_992:
F_563 ( & V_73 -> V_8 ) ;
V_991:
F_316 ( V_73 ) ;
F_564 ( V_989 , V_73 ) ;
return F_567 ( V_760 ) ;
}
static void T_11 F_570 ( void * V_995 )
{
struct V_29 V_433 ;
* ( int * ) V_995 = 0 ;
if ( F_234 ( & V_433 ) < 0 )
* ( int * ) V_995 = - V_432 ;
if ( memcmp ( & V_29 , & V_433 , sizeof( struct V_29 ) ) != 0 ) {
F_69 ( V_89 L_33 ,
F_571 () ) ;
* ( int * ) V_995 = - V_432 ;
}
}
static int F_572 ( void )
{
return V_535 + 1 ;
}
static T_3 F_573 ( struct V_7 * V_8 , T_13 V_996 , bool V_997 )
{
T_3 V_114 ;
if ( V_997 )
V_114 = V_998 << V_999 ;
else if ( F_574 ( V_8 -> V_17 ) )
V_114 = F_575 ( V_8 , V_996 ) <<
V_999 ;
else
V_114 = ( V_1000 << V_999 )
| V_1001 ;
return V_114 ;
}
static int F_576 ( void )
{
if ( V_101 && ! F_38 () )
return V_1002 ;
else
return V_1003 ;
}
static void F_577 ( struct V_7 * V_8 )
{
struct V_304 * V_305 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_631 ;
V_73 -> V_288 = false ;
if ( F_183 () ) {
V_631 = F_94 ( V_643 ) ;
if ( V_631 & V_60 ) {
V_305 = F_201 ( V_8 , 0x80000001 , 0 ) ;
if ( V_305 && ( V_305 -> V_1004 & V_68 ( V_1005 ) ) )
V_73 -> V_288 = true ;
else {
V_631 &= ~ V_60 ;
F_102 ( V_643 ,
V_631 ) ;
}
}
}
V_305 = F_201 ( V_8 , 0x7 , 0 ) ;
if ( F_184 () &&
V_305 && ( V_305 -> V_1006 & V_68 ( V_1007 ) ) &&
F_578 ( V_8 ) ) {
V_631 = F_94 ( V_643 ) ;
V_631 |= V_61 ;
F_102 ( V_643 ,
V_631 ) ;
} else {
if ( F_26 () ) {
V_631 = F_94 ( V_643 ) ;
V_631 &= ~ V_61 ;
F_102 ( V_643 ,
V_631 ) ;
}
if ( V_305 )
V_305 -> V_1006 &= ~ V_68 ( V_1007 ) ;
}
}
static void F_579 ( T_2 V_1008 , struct V_304 * V_141 )
{
if ( V_1008 == 1 && V_13 )
V_141 -> V_306 |= V_68 ( V_307 ) ;
}
static void F_580 ( struct V_7 * V_8 ,
struct V_865 * V_1009 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
T_2 V_259 ;
if ( V_1009 -> V_263 & V_733 )
V_259 = V_814 ;
else
V_259 = V_800 ;
F_179 ( V_8 , V_259 , 0 , V_8 -> V_116 . V_752 ) ;
V_12 -> V_1010 = V_1009 -> V_172 ;
}
static unsigned long F_581 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) -> V_1011 ;
}
static void F_582 ( struct V_7 * V_8 )
{
F_583 ( V_8 , & V_8 -> V_116 . V_511 ,
V_360 & V_43 ) ;
V_8 -> V_116 . V_511 . V_1012 = F_279 ;
V_8 -> V_116 . V_511 . V_1013 = F_581 ;
V_8 -> V_116 . V_511 . V_1014 = F_580 ;
V_8 -> V_116 . V_519 = & V_8 -> V_116 . V_1015 ;
}
static void F_584 ( struct V_7 * V_8 )
{
V_8 -> V_116 . V_519 = & V_8 -> V_116 . V_511 ;
}
static void F_585 ( struct V_7 * V_8 ,
struct V_865 * V_1009 )
{
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_450 ( ! F_123 ( V_8 ) ) ;
if ( V_12 -> V_139 & ( 1u << V_24 ) )
F_179 ( V_8 , F_6 ( V_8 ) -> V_259 ,
F_94 ( V_260 ) ,
F_92 ( V_261 ) ) ;
else
F_489 ( V_8 , V_1009 ) ;
}
static bool F_586 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_58 ( V_12 , V_35 ) ) {
if ( ! F_490 ( V_12 -> V_1016 ) )
return false ;
if ( V_73 -> V_13 . V_886 )
F_13 ( V_73 -> V_13 . V_886 ) ;
V_73 -> V_13 . V_886 =
F_10 ( V_8 , V_12 -> V_1016 ) ;
}
if ( F_57 ( V_12 , V_32 ) ) {
if ( ! F_490 ( V_12 -> V_1017 ) )
return false ;
if ( V_73 -> V_13 . V_887 )
F_13 ( V_73 -> V_13 . V_887 ) ;
V_73 -> V_13 . V_887 =
F_10 ( V_8 , V_12 -> V_1017 ) ;
if ( ! V_73 -> V_13 . V_887 )
return false ;
}
return true ;
}
static void F_587 ( struct V_7 * V_8 )
{
T_3 V_1018 = F_9 ( V_8 ) -> V_1019 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( V_8 -> V_116 . V_1020 == 0 )
return;
if ( V_1018 <= 1 ) {
F_484 ( & V_73 -> V_13 . V_852 ) ;
return;
}
V_1018 <<= V_365 ;
V_1018 *= 1000000 ;
F_588 ( V_1018 , V_8 -> V_116 . V_1020 ) ;
F_589 ( & V_73 -> V_13 . V_852 ,
F_590 ( V_1018 ) , V_882 ) ;
}
static void F_591 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
T_2 V_631 ;
F_101 ( V_1021 , V_12 -> V_1022 ) ;
F_101 ( V_670 , V_12 -> V_1023 ) ;
F_101 ( V_1024 , V_12 -> V_1025 ) ;
F_101 ( V_1026 , V_12 -> V_1027 ) ;
F_101 ( V_1028 , V_12 -> V_1029 ) ;
F_101 ( V_1030 , V_12 -> V_1031 ) ;
F_101 ( V_673 , V_12 -> V_1032 ) ;
F_101 ( V_672 , V_12 -> V_1033 ) ;
F_102 ( V_1034 , V_12 -> V_1035 ) ;
F_102 ( V_1036 , V_12 -> V_1037 ) ;
F_102 ( V_1038 , V_12 -> V_1039 ) ;
F_102 ( V_1040 , V_12 -> V_1041 ) ;
F_102 ( V_1042 , V_12 -> V_1043 ) ;
F_102 ( V_1044 , V_12 -> V_1045 ) ;
F_102 ( V_675 , V_12 -> V_1046 ) ;
F_102 ( V_504 , V_12 -> V_1047 ) ;
F_102 ( V_555 , V_12 -> V_1048 ) ;
F_102 ( V_553 , V_12 -> V_1049 ) ;
F_102 ( V_1050 , V_12 -> V_1051 ) ;
F_102 ( V_1052 , V_12 -> V_1053 ) ;
F_102 ( V_1054 , V_12 -> V_1055 ) ;
F_102 ( V_1056 , V_12 -> V_1057 ) ;
F_102 ( V_1058 , V_12 -> V_1059 ) ;
F_102 ( V_1060 , V_12 -> V_1061 ) ;
F_102 ( V_676 , V_12 -> V_1062 ) ;
F_102 ( V_506 , V_12 -> V_1063 ) ;
F_99 ( V_1064 , V_12 -> V_1065 ) ;
F_99 ( V_671 , V_12 -> V_1066 ) ;
F_99 ( V_1067 , V_12 -> V_1068 ) ;
F_99 ( V_1069 , V_12 -> V_1070 ) ;
F_99 ( V_389 , V_12 -> V_1071 ) ;
F_99 ( V_390 , V_12 -> V_1072 ) ;
F_99 ( V_674 , V_12 -> V_1073 ) ;
F_99 ( V_503 , V_12 -> V_1074 ) ;
F_99 ( V_556 , V_12 -> V_1075 ) ;
F_99 ( V_554 , V_12 -> V_1076 ) ;
if ( V_12 -> V_1077 & V_335 ) {
F_404 ( V_8 , 7 , V_12 -> V_1078 ) ;
F_103 ( V_680 , V_12 -> V_1079 ) ;
} else {
F_404 ( V_8 , 7 , V_8 -> V_116 . V_743 ) ;
F_103 ( V_680 , V_73 -> V_13 . V_1080 ) ;
}
F_102 ( V_273 ,
V_12 -> V_1081 ) ;
F_102 ( V_265 ,
V_12 -> V_1082 ) ;
F_102 ( V_271 ,
V_12 -> V_1083 ) ;
F_102 ( V_251 ,
V_12 -> V_1084 ) ;
F_102 ( V_393 , V_12 -> V_1085 ) ;
F_172 ( V_8 , V_12 -> V_1086 ) ;
F_99 ( V_679 ,
V_12 -> V_1087 ) ;
F_99 ( V_396 , V_12 -> V_1088 ) ;
F_99 ( V_395 , V_12 -> V_1089 ) ;
F_103 ( V_641 , - 1ull ) ;
V_631 = V_12 -> V_71 ;
V_631 |= V_29 . V_39 ;
V_631 &= ~ ( V_72 |
V_40 ) ;
F_102 ( V_642 , V_631 ) ;
V_73 -> V_13 . V_853 = false ;
if ( F_60 ( V_12 ) )
F_587 ( V_8 ) ;
F_102 ( V_654 ,
V_101 ? V_12 -> V_1090 : 0 ) ;
F_102 ( V_655 ,
V_101 ? V_12 -> V_1091 : 0 ) ;
if ( F_26 () ) {
V_631 = F_338 ( V_73 ) ;
if ( ! V_73 -> V_288 )
V_631 &= ~ V_60 ;
V_631 &= ~ ( V_35 |
V_38 |
V_37 ) ;
if ( F_57 ( V_12 ,
V_33 ) )
V_631 |= V_12 -> V_70 ;
if ( V_631 & V_35 ) {
if ( ! V_73 -> V_13 . V_886 )
V_631 &=
~ V_35 ;
else
F_103 ( V_969 ,
F_592 ( V_73 -> V_13 . V_886 ) ) ;
} else if ( F_48 ( V_73 -> V_8 . V_17 ) ) {
V_631 |=
V_35 ;
F_593 ( V_8 ) ;
}
F_102 ( V_643 , V_631 ) ;
}
F_331 ( V_73 ) ;
V_73 -> V_1092 = 0 ;
V_631 = F_337 ( V_73 ) ;
V_631 &= ~ V_340 ;
V_631 &= ~ V_341 ;
V_631 &= ~ V_32 ;
V_631 |= V_12 -> V_69 ;
if ( V_631 & V_32 ) {
F_103 ( V_681 ,
F_592 ( V_73 -> V_13 . V_887 ) ) ;
F_102 ( V_682 , V_12 -> V_1093 ) ;
}
V_631 &= ~ V_31 ;
V_631 &= ~ V_351 ;
V_631 |= V_350 ;
F_102 ( V_528 , V_631 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 &= ~ V_12 -> V_234 ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
F_102 ( V_109 , V_29 . V_447 ) ;
F_106 ( V_73 ,
( V_12 -> V_1077 & ~ V_146 &
~ V_331 ) |
( V_29 . V_404 & ~ V_331 ) ) ;
if ( V_12 -> V_1077 & V_332 ) {
F_103 ( V_405 , V_12 -> V_1094 ) ;
V_8 -> V_116 . V_406 = V_12 -> V_1094 ;
} else if ( V_29 . V_404 & V_332 )
F_103 ( V_405 , V_73 -> V_8 . V_116 . V_406 ) ;
F_335 ( V_73 ) ;
if ( V_12 -> V_1077 & V_333 )
F_103 ( V_397 , V_12 -> V_1095 ) ;
if ( V_12 -> V_69 & V_300 )
F_103 ( V_292 ,
V_73 -> V_13 . V_293 + V_12 -> V_291 ) ;
else
F_103 ( V_292 , V_73 -> V_13 . V_293 ) ;
if ( V_463 ) {
F_101 ( V_684 , V_73 -> V_52 ) ;
F_267 ( V_8 ) ;
}
if ( F_61 ( V_12 ) ) {
F_594 ( V_8 ) ;
F_582 ( V_8 ) ;
}
if ( V_12 -> V_1077 & V_146 )
V_8 -> V_116 . V_177 = V_12 -> V_1096 ;
else if ( V_12 -> V_1077 & V_331 )
V_8 -> V_116 . V_177 |= ( V_180 | V_181 ) ;
else
V_8 -> V_116 . V_177 &= ~ ( V_180 | V_181 ) ;
F_263 ( V_8 , V_8 -> V_116 . V_177 ) ;
F_278 ( V_8 , V_12 -> V_237 ) ;
F_99 ( V_242 , F_165 ( V_12 ) ) ;
F_276 ( V_8 , V_12 -> V_239 ) ;
F_99 ( V_492 , F_166 ( V_12 ) ) ;
F_394 ( V_8 , V_12 -> V_539 ) ;
F_262 ( V_8 ) ;
if ( ! V_101 )
V_8 -> V_116 . V_519 -> V_1014 = F_585 ;
if ( V_101 ) {
F_103 ( V_521 , V_12 -> V_1097 ) ;
F_103 ( V_523 , V_12 -> V_1098 ) ;
F_103 ( V_524 , V_12 -> V_1099 ) ;
F_103 ( V_525 , V_12 -> V_1100 ) ;
}
F_396 ( V_8 , V_413 , V_12 -> V_1101 ) ;
F_396 ( V_8 , V_416 , V_12 -> V_1102 ) ;
}
static int F_503 ( struct V_7 * V_8 , bool V_1103 )
{
struct V_12 * V_12 ;
struct V_6 * V_73 = F_6 ( V_8 ) ;
int V_91 ;
struct V_90 * V_837 ;
bool V_1104 ;
if ( ! F_496 ( V_8 ) ||
! F_510 ( V_8 ) )
return 1 ;
F_175 ( V_8 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_464 )
F_498 ( V_73 ) ;
if ( V_12 -> V_888 == V_1103 ) {
F_483 ( V_8 ,
V_1103 ? V_1105
: V_1106 ) ;
return 1 ;
}
if ( V_12 -> V_1107 != V_678 &&
V_12 -> V_1107 != V_1108 ) {
F_483 ( V_8 , V_1109 ) ;
return 1 ;
}
if ( ( V_12 -> V_69 & V_31 ) &&
! F_490 ( V_12 -> V_277 ) ) {
F_483 ( V_8 , V_1109 ) ;
return 1 ;
}
if ( ! F_586 ( V_8 , V_12 ) ) {
F_483 ( V_8 , V_1109 ) ;
return 1 ;
}
if ( V_12 -> V_1110 > 0 ||
V_12 -> V_1111 > 0 ||
V_12 -> V_1112 > 0 ) {
F_595 ( L_34 ,
V_510 ) ;
F_483 ( V_8 , V_1109 ) ;
return 1 ;
}
if ( ! F_206 ( V_12 -> V_69 ,
V_356 ,
V_338 ) ||
! F_206 ( V_12 -> V_70 ,
V_358 , V_359 ) ||
! F_206 ( V_12 -> V_71 ,
V_309 , V_310 ) ||
! F_206 ( V_12 -> V_688 ,
V_325 ,
V_316 ) ||
! F_206 ( V_12 -> V_1077 ,
V_334 ,
V_329 ) )
{
F_483 ( V_8 , V_1109 ) ;
return 1 ;
}
if ( ( ( V_12 -> V_1113 & F_209 ) != F_209 ) ||
( ( V_12 -> V_1114 & F_210 ) != F_210 ) ) {
F_483 ( V_8 ,
V_1115 ) ;
return 1 ;
}
if ( ! F_384 ( V_12 , V_12 -> V_237 ) ||
( ( V_12 -> V_239 & F_210 ) != F_210 ) ) {
F_596 ( V_8 , V_12 ,
V_944 , V_1116 ) ;
return 1 ;
}
if ( V_12 -> V_1117 != - 1ull ) {
F_596 ( V_8 , V_12 ,
V_944 , V_1118 ) ;
return 1 ;
}
if ( V_12 -> V_1077 & V_146 ) {
V_1104 = ( V_12 -> V_1077 & V_331 ) != 0 ;
if ( ! F_597 ( V_8 , V_12 -> V_1096 ) ||
V_1104 != ! ! ( V_12 -> V_1096 & V_180 ) ||
( ( V_12 -> V_237 & V_527 ) &&
V_1104 != ! ! ( V_12 -> V_1096 & V_181 ) ) ) {
F_596 ( V_8 , V_12 ,
V_944 , V_1116 ) ;
return 1 ;
}
}
if ( V_12 -> V_688 & V_147 ) {
V_1104 = ( V_12 -> V_688 &
V_318 ) != 0 ;
if ( ! F_597 ( V_8 , V_12 -> V_1119 ) ||
V_1104 != ! ! ( V_12 -> V_1119 & V_180 ) ||
V_1104 != ! ! ( V_12 -> V_1119 & V_181 ) ) {
F_596 ( V_8 , V_12 ,
V_944 , V_1116 ) ;
return 1 ;
}
}
V_837 = F_474 ( V_73 ) ;
if ( ! V_837 )
return - V_461 ;
F_598 ( V_8 ) ;
V_73 -> V_13 . V_293 = F_95 ( V_292 ) ;
if ( ! ( V_12 -> V_1077 & V_335 ) )
V_73 -> V_13 . V_1080 = F_95 ( V_680 ) ;
V_91 = F_559 () ;
V_73 -> V_90 = V_837 ;
F_161 ( V_8 ) ;
F_154 ( V_8 , V_91 ) ;
V_8 -> V_91 = V_91 ;
F_560 () ;
F_116 ( V_73 ) ;
V_12 -> V_888 = 1 ;
F_591 ( V_8 , V_12 ) ;
if ( V_12 -> V_1107 == V_1108 )
return F_368 ( V_8 ) ;
V_73 -> V_13 . V_702 = 1 ;
return 1 ;
}
static inline unsigned long
F_599 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_92 ( V_230 ) & V_8 -> V_116 . V_233 ) |
( V_12 -> V_237 & V_12 -> V_234 ) |
( F_92 ( V_242 ) & ~ ( V_12 -> V_234 |
V_8 -> V_116 . V_233 ) ) ;
}
static inline unsigned long
F_600 ( struct V_7 * V_8 , struct V_12 * V_12 )
{
return
( F_92 ( V_490 ) & V_8 -> V_116 . V_516 ) |
( V_12 -> V_239 & V_12 -> V_240 ) |
( F_92 ( V_492 ) & ~ ( V_12 -> V_240 |
V_8 -> V_116 . V_516 ) ) ;
}
static void F_601 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
T_2 V_1120 ;
unsigned int V_152 ;
if ( V_8 -> V_116 . V_747 . V_1121 && V_8 -> V_116 . V_747 . V_264 ) {
V_152 = V_8 -> V_116 . V_747 . V_152 ;
V_1120 = V_152 | V_732 ;
if ( F_181 ( V_152 ) ) {
V_12 -> V_1122 =
V_8 -> V_116 . V_268 ;
V_1120 |= V_272 ;
} else
V_1120 |= V_23 ;
if ( V_8 -> V_116 . V_747 . V_262 ) {
V_1120 |= V_790 ;
V_12 -> V_1123 =
V_8 -> V_116 . V_747 . V_263 ;
}
V_12 -> V_1124 = V_1120 ;
} else if ( V_8 -> V_116 . V_789 ) {
V_12 -> V_1124 =
V_699 | V_22 | V_698 ;
} else if ( V_8 -> V_116 . V_691 . V_1121 ) {
V_152 = V_8 -> V_116 . V_691 . V_152 ;
V_1120 = V_152 | V_732 ;
if ( V_8 -> V_116 . V_691 . V_693 ) {
V_1120 |= V_694 ;
V_12 -> V_1083 =
V_8 -> V_116 . V_268 ;
} else
V_1120 |= V_27 ;
V_12 -> V_1124 = V_1120 ;
}
}
static int F_602 ( struct V_7 * V_8 , bool V_1125 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
if ( F_60 ( F_9 ( V_8 ) ) &&
V_73 -> V_13 . V_853 ) {
if ( V_73 -> V_13 . V_702 )
return - V_424 ;
F_179 ( V_8 , V_1126 , 0 , 0 ) ;
return 0 ;
}
if ( V_8 -> V_116 . V_961 && F_353 ( V_8 ) ) {
if ( V_73 -> V_13 . V_702 ||
V_8 -> V_116 . V_691 . V_1121 )
return - V_424 ;
F_179 ( V_8 , V_919 ,
V_698 | V_699 |
V_22 , 0 ) ;
V_8 -> V_116 . V_961 = 0 ;
F_360 ( V_8 , true ) ;
return 0 ;
}
if ( ( F_422 ( V_8 ) || V_1125 ) &&
F_351 ( V_8 ) ) {
if ( V_73 -> V_13 . V_702 )
return - V_424 ;
F_179 ( V_8 , V_920 , 0 , 0 ) ;
}
return 0 ;
}
static T_2 F_603 ( struct V_7 * V_8 )
{
T_19 V_1127 =
F_604 ( & F_6 ( V_8 ) -> V_13 . V_852 ) ;
T_3 V_103 ;
if ( F_544 ( V_1127 ) <= 0 )
return 0 ;
V_103 = F_544 ( V_1127 ) * V_8 -> V_116 . V_1020 ;
F_588 ( V_103 , 1000000 ) ;
return V_103 >> V_365 ;
}
static void F_605 ( struct V_7 * V_8 , struct V_12 * V_12 ,
T_2 V_259 , T_2 V_729 ,
unsigned long V_752 )
{
V_12 -> V_237 = F_599 ( V_8 , V_12 ) ;
V_12 -> V_239 = F_600 ( V_8 , V_12 ) ;
V_12 -> V_1101 = F_435 ( V_8 , V_413 ) ;
V_12 -> V_1102 = F_435 ( V_8 , V_416 ) ;
V_12 -> V_1086 = F_92 ( V_246 ) ;
V_12 -> V_1022 = F_93 ( V_1021 ) ;
V_12 -> V_1023 = F_93 ( V_670 ) ;
V_12 -> V_1025 = F_93 ( V_1024 ) ;
V_12 -> V_1027 = F_93 ( V_1026 ) ;
V_12 -> V_1029 = F_93 ( V_1028 ) ;
V_12 -> V_1031 = F_93 ( V_1030 ) ;
V_12 -> V_1032 = F_93 ( V_673 ) ;
V_12 -> V_1033 = F_93 ( V_672 ) ;
V_12 -> V_1035 = F_94 ( V_1034 ) ;
V_12 -> V_1037 = F_94 ( V_1036 ) ;
V_12 -> V_1039 = F_94 ( V_1038 ) ;
V_12 -> V_1041 = F_94 ( V_1040 ) ;
V_12 -> V_1043 = F_94 ( V_1042 ) ;
V_12 -> V_1045 = F_94 ( V_1044 ) ;
V_12 -> V_1046 = F_94 ( V_675 ) ;
V_12 -> V_1047 = F_94 ( V_504 ) ;
V_12 -> V_1048 = F_94 ( V_555 ) ;
V_12 -> V_1049 = F_94 ( V_553 ) ;
V_12 -> V_1051 = F_94 ( V_1050 ) ;
V_12 -> V_1053 = F_94 ( V_1052 ) ;
V_12 -> V_1055 = F_94 ( V_1054 ) ;
V_12 -> V_1057 = F_94 ( V_1056 ) ;
V_12 -> V_1059 = F_94 ( V_1058 ) ;
V_12 -> V_1061 = F_94 ( V_1060 ) ;
V_12 -> V_1062 = F_94 ( V_676 ) ;
V_12 -> V_1063 = F_94 ( V_506 ) ;
V_12 -> V_1065 = F_92 ( V_1064 ) ;
V_12 -> V_1066 = F_92 ( V_671 ) ;
V_12 -> V_1068 = F_92 ( V_1067 ) ;
V_12 -> V_1070 = F_92 ( V_1069 ) ;
V_12 -> V_1071 = F_92 ( V_389 ) ;
V_12 -> V_1072 = F_92 ( V_390 ) ;
V_12 -> V_1073 = F_92 ( V_674 ) ;
V_12 -> V_1074 = F_92 ( V_503 ) ;
V_12 -> V_1075 = F_92 ( V_556 ) ;
V_12 -> V_1076 = F_92 ( V_554 ) ;
V_12 -> V_1084 =
F_94 ( V_251 ) ;
V_12 -> V_1087 =
F_92 ( V_679 ) ;
if ( V_8 -> V_116 . V_1128 == V_1129 )
V_12 -> V_1107 = V_1108 ;
else
V_12 -> V_1107 = V_678 ;
if ( F_60 ( V_12 ) ) {
if ( V_12 -> V_688 &
V_322 )
V_12 -> V_1019 =
F_603 ( V_8 ) ;
F_606 ( & F_6 ( V_8 ) -> V_13 . V_852 ) ;
}
if ( V_101 ) {
V_12 -> V_539 = F_95 ( V_514 ) ;
V_12 -> V_1097 = F_95 ( V_521 ) ;
V_12 -> V_1098 = F_95 ( V_523 ) ;
V_12 -> V_1099 = F_95 ( V_524 ) ;
V_12 -> V_1100 = F_95 ( V_525 ) ;
}
V_12 -> V_1077 =
( V_12 -> V_1077 & ~ V_331 ) |
( F_108 ( F_6 ( V_8 ) ) & V_331 ) ;
if ( V_12 -> V_688 & V_326 ) {
F_403 ( V_8 , 7 , ( unsigned long * ) & V_12 -> V_1078 ) ;
V_12 -> V_1079 = F_95 ( V_680 ) ;
}
if ( V_12 -> V_688 & V_320 )
V_12 -> V_1094 = F_95 ( V_405 ) ;
if ( V_12 -> V_688 & V_321 )
V_12 -> V_1096 = V_8 -> V_116 . V_177 ;
V_12 -> V_1085 = F_94 ( V_393 ) ;
V_12 -> V_1088 = F_92 ( V_396 ) ;
V_12 -> V_1089 = F_92 ( V_395 ) ;
if ( F_205 () )
V_12 -> V_1095 = F_95 ( V_397 ) ;
V_12 -> V_1130 = V_259 ;
V_12 -> V_752 = V_752 ;
V_12 -> V_1131 = V_729 ;
if ( ( V_12 -> V_1131 &
( V_22 | V_266 ) ) ==
( V_22 | V_266 ) )
V_12 -> V_1132 =
F_94 ( V_731 ) ;
V_12 -> V_1124 = 0 ;
V_12 -> V_1122 = F_94 ( V_258 ) ;
V_12 -> V_855 = F_94 ( V_868 ) ;
if ( ! ( V_12 -> V_1130 & V_956 ) ) {
V_12 -> V_1081 &= ~ V_22 ;
F_601 ( V_8 , V_12 ) ;
}
V_8 -> V_116 . V_789 = false ;
F_445 ( V_8 ) ;
F_444 ( V_8 ) ;
}
static void F_607 ( struct V_7 * V_8 ,
struct V_12 * V_12 )
{
struct V_477 V_113 ;
if ( V_12 -> V_688 & V_147 )
V_8 -> V_116 . V_177 = V_12 -> V_1119 ;
else if ( V_12 -> V_688 & V_318 )
V_8 -> V_116 . V_177 |= ( V_180 | V_181 ) ;
else
V_8 -> V_116 . V_177 &= ~ ( V_180 | V_181 ) ;
F_263 ( V_8 , V_8 -> V_116 . V_177 ) ;
F_396 ( V_8 , V_413 , V_12 -> V_1092 ) ;
F_396 ( V_8 , V_416 , V_12 -> V_1133 ) ;
F_172 ( V_8 , V_1134 ) ;
F_278 ( V_8 , V_12 -> V_1113 ) ;
F_122 ( V_8 ) ;
V_8 -> V_116 . V_233 = ( V_8 -> V_138 ? V_231 : 0 ) ;
F_99 ( V_235 , ~ V_8 -> V_116 . V_233 ) ;
V_8 -> V_116 . V_516 = ~ F_92 ( V_630 ) ;
F_388 ( V_8 , V_12 -> V_1114 ) ;
F_584 ( V_8 ) ;
F_394 ( V_8 , V_12 -> V_1135 ) ;
F_262 ( V_8 ) ;
if ( ! V_101 )
V_8 -> V_116 . V_519 -> V_1014 = F_489 ;
if ( V_463 ) {
F_267 ( V_8 ) ;
}
F_102 ( V_393 , V_12 -> V_1136 ) ;
F_99 ( V_396 , V_12 -> V_1137 ) ;
F_99 ( V_395 , V_12 -> V_1138 ) ;
F_99 ( V_554 , V_12 -> V_1139 ) ;
F_99 ( V_556 , V_12 -> V_1140 ) ;
if ( V_12 -> V_688 & V_324 )
F_103 ( V_397 , 0 ) ;
if ( V_12 -> V_688 & V_319 ) {
F_103 ( V_405 , V_12 -> V_1141 ) ;
V_8 -> V_116 . V_406 = V_12 -> V_1141 ;
}
if ( V_12 -> V_688 & V_151 )
F_103 ( V_163 ,
V_12 -> V_1142 ) ;
V_113 = (struct V_477 ) {
. V_123 = 0 ,
. V_125 = 0xFFFFFFFF ,
. V_120 = V_12 -> V_1143 ,
. type = 11 ,
. V_498 = 1 ,
. V_187 = 1 ,
. V_496 = 1
} ;
if ( V_12 -> V_688 & V_318 )
V_113 . V_499 = 1 ;
else
V_113 . V_497 = 1 ;
F_256 ( V_8 , & V_113 , V_479 ) ;
V_113 = (struct V_477 ) {
. V_123 = 0 ,
. V_125 = 0xFFFFFFFF ,
. type = 3 ,
. V_498 = 1 ,
. V_187 = 1 ,
. V_497 = 1 ,
. V_496 = 1
} ;
V_113 . V_120 = V_12 -> V_1144 ;
F_256 ( V_8 , & V_113 , V_486 ) ;
V_113 . V_120 = V_12 -> V_1145 ;
F_256 ( V_8 , & V_113 , V_485 ) ;
V_113 . V_120 = V_12 -> V_1146 ;
F_256 ( V_8 , & V_113 , V_480 ) ;
V_113 . V_120 = V_12 -> V_1147 ;
V_113 . V_123 = V_12 -> V_1148 ;
F_256 ( V_8 , & V_113 , V_487 ) ;
V_113 . V_120 = V_12 -> V_1149 ;
V_113 . V_123 = V_12 -> V_1150 ;
F_256 ( V_8 , & V_113 , V_488 ) ;
V_113 = (struct V_477 ) {
. V_123 = V_12 -> V_1151 ,
. V_125 = 0x67 ,
. V_120 = V_12 -> V_1152 ,
. type = 11 ,
. V_498 = 1
} ;
F_256 ( V_8 , & V_113 , V_489 ) ;
F_404 ( V_8 , 7 , 0x400 ) ;
F_103 ( V_680 , 0 ) ;
}
static void F_179 ( struct V_7 * V_8 , T_2 V_259 ,
T_2 V_729 ,
unsigned long V_752 )
{
struct V_6 * V_73 = F_6 ( V_8 ) ;
struct V_12 * V_12 = F_9 ( V_8 ) ;
F_608 ( V_73 -> V_13 . V_702 ) ;
F_562 ( V_8 ) ;
F_605 ( V_8 , V_12 , V_259 , V_729 ,
V_752 ) ;
F_558 ( V_8 ) ;
if ( ( V_259 == V_920 )
&& F_352 ( V_8 ) ) {
int V_690 = F_609 ( V_8 ) ;
F_450 ( V_690 < 0 ) ;
V_12 -> V_1131 = V_690 |
V_22 | V_27 ;
}
F_610 ( V_12 -> V_1130 ,
V_12 -> V_752 ,
V_12 -> V_1124 ,
V_12 -> V_1131 ,
V_12 -> V_1132 ,
V_917 ) ;
F_106 ( V_73 , F_94 ( V_107 ) ) ;
F_111 ( V_73 , F_94 ( V_109 ) ) ;
F_116 ( V_73 ) ;
if ( V_839 == 0 )
F_479 ( V_73 , V_73 -> V_13 . V_834 ) ;
F_607 ( V_8 , V_12 ) ;
F_103 ( V_292 , V_73 -> V_13 . V_293 ) ;
V_73 -> V_1092 = 0 ;
if ( V_73 -> V_13 . V_886 ) {
F_13 ( V_73 -> V_13 . V_886 ) ;
V_73 -> V_13 . V_886 = NULL ;
}
if ( V_73 -> V_13 . V_887 ) {
F_13 ( V_73 -> V_13 . V_887 ) ;
V_73 -> V_13 . V_887 = NULL ;
}
F_593 ( V_8 ) ;
if ( F_100 ( V_73 -> V_918 ) ) {
V_73 -> V_918 = 0 ;
F_483 ( V_8 , F_94 ( V_104 ) ) ;
} else
F_481 ( V_8 ) ;
if ( V_464 )
V_73 -> V_13 . V_884 = true ;
V_8 -> V_116 . V_1128 = V_1153 ;
}
static void F_217 ( struct V_7 * V_8 )
{
if ( F_123 ( V_8 ) )
F_179 ( V_8 , - 1 , 0 , 0 ) ;
F_499 ( F_6 ( V_8 ) ) ;
}
static void F_596 ( struct V_7 * V_8 ,
struct V_12 * V_12 ,
T_2 V_783 , unsigned long V_1154 )
{
F_607 ( V_8 , V_12 ) ;
V_12 -> V_1130 = V_783 | V_956 ;
V_12 -> V_752 = V_1154 ;
F_481 ( V_8 ) ;
if ( V_464 )
F_6 ( V_8 ) -> V_13 . V_884 = true ;
}
static int F_611 ( struct V_7 * V_8 ,
struct V_1155 * V_1156 ,
enum V_1157 V_1158 )
{
return V_1159 ;
}
static void F_612 ( struct V_7 * V_8 , int V_91 )
{
if ( V_470 )
F_466 ( V_8 ) ;
}
static int T_11 F_613 ( void )
{
int V_569 , V_75 , V_74 ;
F_614 ( V_144 , & V_182 ) ;
for ( V_75 = 0 ; V_75 < F_342 ( V_77 ) ; ++ V_75 )
F_615 ( V_75 , V_77 [ V_75 ] ) ;
V_636 = ( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_636 )
return - V_461 ;
V_569 = - V_461 ;
V_638 = ( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_638 )
goto V_551;
V_282 = ( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_282 )
goto V_1160;
V_280 =
( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_280 )
goto V_577;
V_281 = ( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_281 )
goto V_1161;
V_279 =
( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_279 )
goto V_1162;
V_458 = ( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_458 )
goto V_1163;
V_457 = ( unsigned long * ) F_616 ( V_453 ) ;
if ( ! V_457 )
goto V_1164;
memset ( V_458 , 0xff , V_443 ) ;
memset ( V_457 , 0xff , V_443 ) ;
memset ( V_636 , 0xff , V_443 ) ;
F_247 ( 0x80 , V_636 ) ;
memset ( V_638 , 0xff , V_443 ) ;
memset ( V_282 , 0xff , V_443 ) ;
memset ( V_281 , 0xff , V_443 ) ;
F_617 ( 0 , V_596 ) ;
V_569 = F_618 ( & V_1165 , sizeof( struct V_6 ) ,
F_619 ( struct V_6 ) , V_1166 ) ;
if ( V_569 )
goto V_1167;
#ifdef F_620
F_621 ( V_1168 ,
F_78 ) ;
#endif
F_320 ( V_207 , false ) ;
F_320 ( V_209 , false ) ;
F_320 ( V_210 , true ) ;
F_320 ( V_392 , false ) ;
F_320 ( V_227 , false ) ;
F_320 ( V_394 , false ) ;
F_320 ( V_214 , true ) ;
memcpy ( V_280 ,
V_282 , V_443 ) ;
memcpy ( V_279 ,
V_281 , V_443 ) ;
if ( V_471 ) {
for ( V_74 = 0x800 ; V_74 <= 0x8ff ; V_74 ++ )
F_322 ( V_74 ) ;
F_321 ( 0x802 ) ;
F_321 ( 0x839 ) ;
F_323 ( 0x808 ) ;
F_323 ( 0x80b ) ;
F_323 ( 0x83f ) ;
}
if ( V_101 ) {
F_622 ( 0ull ,
( V_466 ) ? V_1169 : 0ull ,
( V_466 ) ? V_1170 : 0ull ,
0ull , V_1171 ) ;
F_339 () ;
F_623 () ;
} else
F_624 () ;
F_468 () ;
return 0 ;
V_1167:
F_625 ( ( unsigned long ) V_457 ) ;
V_1164:
F_625 ( ( unsigned long ) V_458 ) ;
V_1163:
F_625 ( ( unsigned long ) V_279 ) ;
V_1162:
F_625 ( ( unsigned long ) V_281 ) ;
V_1161:
F_625 ( ( unsigned long ) V_280 ) ;
V_577:
F_625 ( ( unsigned long ) V_282 ) ;
V_1160:
F_625 ( ( unsigned long ) V_638 ) ;
V_551:
F_625 ( ( unsigned long ) V_636 ) ;
return V_569 ;
}
static void T_12 F_626 ( void )
{
F_625 ( ( unsigned long ) V_280 ) ;
F_625 ( ( unsigned long ) V_279 ) ;
F_625 ( ( unsigned long ) V_282 ) ;
F_625 ( ( unsigned long ) V_281 ) ;
F_625 ( ( unsigned long ) V_638 ) ;
F_625 ( ( unsigned long ) V_636 ) ;
F_625 ( ( unsigned long ) V_457 ) ;
F_625 ( ( unsigned long ) V_458 ) ;
#ifdef F_620
F_627 ( V_1168 , NULL ) ;
F_628 () ;
#endif
F_629 () ;
}
