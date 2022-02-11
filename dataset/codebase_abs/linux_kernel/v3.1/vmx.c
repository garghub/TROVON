static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline short F_3 ( unsigned long V_4 )
{
if ( V_4 >= V_5 || V_6 [ V_4 ] == 0 )
return - 1 ;
return V_6 [ V_4 ] ;
}
static inline struct V_7 * F_4 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_8 . V_9 ;
}
static struct V_10 * F_5 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_10 * V_10 = F_6 ( V_3 -> V_12 , V_11 >> V_13 ) ;
if ( F_7 ( V_10 ) ) {
F_8 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
static void F_9 ( struct V_10 * V_10 )
{
F_10 ( V_10 ) ;
}
static void F_11 ( struct V_10 * V_10 )
{
F_8 ( V_10 ) ;
}
static inline bool F_12 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_19 | V_17 ) ;
}
static inline bool F_13 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_20 | V_17 ) ;
}
static inline bool F_14 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_21 | V_17 ) ;
}
static inline bool F_15 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_17 ) )
== ( V_22 | V_17 ) ;
}
static inline bool F_16 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_16 |
V_17 ) ) ==
( V_18 | V_23 | V_17 ) ;
}
static inline bool F_17 ( void )
{
return V_24 . V_25 & V_26 ;
}
static inline bool F_18 ( void )
{
return V_24 . V_25 & V_27 ;
}
static inline bool F_19 ( struct V_12 * V_12 )
{
return ( F_18 () ) && ( F_20 ( V_12 ) ) ;
}
static inline bool F_21 ( void )
{
return V_24 . V_25 &
V_28 ;
}
static inline bool F_22 ( void )
{
return V_24 . V_29 &
V_30 ;
}
static inline bool F_23 ( void )
{
return F_18 () &&
F_22 () ;
}
static inline bool F_24 ( void )
{
return V_31 . V_32 & V_33 ;
}
static inline bool F_25 ( void )
{
return V_31 . V_32 & V_34 ;
}
static inline bool F_26 ( void )
{
return V_31 . V_32 & V_35 ;
}
static inline bool F_27 ( void )
{
return V_31 . V_32 & V_36 ;
}
static inline bool F_28 ( void )
{
return V_31 . V_32 & V_37 ;
}
static inline bool F_29 ( void )
{
return V_31 . V_32 & V_38 ;
}
static inline bool F_30 ( void )
{
return V_31 . V_32 & V_39 ;
}
static inline bool F_31 ( void )
{
return V_31 . V_32 & V_40 ;
}
static inline bool F_32 ( void )
{
return V_31 . V_32 & V_41 ;
}
static inline bool F_33 ( void )
{
return V_31 . V_42 & V_43 ;
}
static inline bool F_34 ( void )
{
return V_31 . V_42 & V_44 ;
}
static inline bool F_35 ( void )
{
return V_24 . V_29 &
V_45 ;
}
static inline bool F_36 ( void )
{
return V_24 . V_29 &
V_46 ;
}
static inline bool F_37 ( void )
{
return V_24 . V_29 &
V_47 ;
}
static inline bool F_38 ( struct V_12 * V_12 )
{
return V_48 && F_20 ( V_12 ) ;
}
static inline bool F_39 ( void )
{
return V_24 . V_29 &
V_49 ;
}
static inline bool F_40 ( void )
{
return V_24 . V_29 &
V_50 ;
}
static inline bool F_41 ( void )
{
return V_24 . V_51 & V_52 ;
}
static inline bool F_42 ( void )
{
return V_24 . V_29 &
V_53 ;
}
static inline bool F_43 ( void )
{
return V_48 ;
}
static inline bool F_44 ( struct V_7 * V_7 , T_2 V_54 )
{
return V_7 -> V_55 & V_54 ;
}
static inline bool F_45 ( struct V_7 * V_7 , T_2 V_54 )
{
return ( V_7 -> V_55 &
V_28 ) &&
( V_7 -> V_56 & V_54 ) ;
}
static inline bool F_46 ( struct V_7 * V_7 ,
struct V_2 * V_3 )
{
return V_7 -> V_57 & V_52 ;
}
static inline bool F_47 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_17 ) )
== ( V_18 | V_17 ) ;
}
static int F_48 ( struct V_1 * V_58 , T_2 V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_61 ; ++ V_60 )
if ( V_62 [ V_58 -> V_63 [ V_60 ] . V_64 ] == V_59 )
return V_60 ;
return - 1 ;
}
static inline void F_49 ( int V_65 , T_3 V_42 , T_4 V_66 )
{
struct {
T_5 V_42 : 16 ;
T_5 V_67 : 48 ;
T_5 V_66 ;
} V_68 = { V_42 , 0 , V_66 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_50 ( int V_65 , T_5 V_69 , T_1 V_70 )
{
struct {
T_5 V_69 , V_70 ;
} V_68 = { V_69 , V_70 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_71 * F_51 ( struct V_1 * V_58 , T_2 V_59 )
{
int V_60 ;
V_60 = F_48 ( V_58 , V_59 ) ;
if ( V_60 >= 0 )
return & V_58 -> V_63 [ V_60 ] ;
return NULL ;
}
static void F_52 ( struct V_72 * V_72 )
{
T_5 V_73 = F_53 ( V_72 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_54 ( V_74 L_1 ,
V_72 , V_73 ) ;
}
static inline void F_55 ( struct V_75 * V_75 )
{
F_52 ( V_75 -> V_72 ) ;
V_75 -> V_76 = - 1 ;
V_75 -> V_77 = 0 ;
}
static void F_56 ( struct V_72 * V_72 )
{
T_5 V_73 = F_53 ( V_72 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_54 ( V_74 L_2 ,
V_72 , V_73 ) ;
}
static void F_57 ( void * V_78 )
{
struct V_75 * V_75 = V_78 ;
int V_76 = F_58 () ;
if ( V_75 -> V_76 != V_76 )
return;
if ( F_59 ( V_79 , V_76 ) == V_75 -> V_72 )
F_59 ( V_79 , V_76 ) = NULL ;
F_60 ( & V_75 -> V_80 ) ;
F_55 ( V_75 ) ;
}
static void F_61 ( struct V_75 * V_75 )
{
if ( V_75 -> V_76 != - 1 )
F_62 (
V_75 -> V_76 , F_57 , V_75 , 1 ) ;
}
static inline void F_63 ( struct V_1 * V_58 )
{
if ( V_58 -> V_42 == 0 )
return;
if ( F_33 () )
F_49 ( V_81 , V_58 -> V_42 , 0 ) ;
}
static inline void F_64 ( void )
{
if ( F_34 () )
F_49 ( V_82 , 0 , 0 ) ;
}
static inline void F_65 ( struct V_1 * V_58 )
{
if ( F_33 () )
F_63 ( V_58 ) ;
else
F_64 () ;
}
static inline void F_66 ( void )
{
if ( F_32 () )
F_50 ( V_83 , 0 , 0 ) ;
}
static inline void F_67 ( T_5 V_69 )
{
if ( V_84 ) {
if ( F_31 () )
F_50 ( V_85 , V_69 , 0 ) ;
else
F_66 () ;
}
}
static inline void F_68 ( T_5 V_69 , T_1 V_70 )
{
if ( V_84 ) {
if ( F_30 () )
F_50 ( V_86 ,
V_69 , V_70 ) ;
else
F_67 ( V_69 ) ;
}
}
static T_7 unsigned long F_69 ( unsigned long V_4 )
{
unsigned long V_87 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_87 ;
}
static T_7 T_3 F_70 ( unsigned long V_4 )
{
return F_69 ( V_4 ) ;
}
static T_7 T_2 F_71 ( unsigned long V_4 )
{
return F_69 ( V_4 ) ;
}
static T_7 T_5 F_72 ( unsigned long V_4 )
{
#ifdef F_73
return F_69 ( V_4 ) ;
#else
return F_69 ( V_4 ) | ( ( T_5 ) F_69 ( V_4 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_74 ( unsigned long V_4 , unsigned long V_87 )
{
F_54 ( V_74 L_3 ,
V_4 , V_87 , F_71 ( V_88 ) ) ;
F_75 () ;
}
static void F_76 ( unsigned long V_4 , unsigned long V_87 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_77 ( error ) )
F_74 ( V_4 , V_87 ) ;
}
static void F_78 ( unsigned long V_4 , T_3 V_87 )
{
F_76 ( V_4 , V_87 ) ;
}
static void F_79 ( unsigned long V_4 , T_2 V_87 )
{
F_76 ( V_4 , V_87 ) ;
}
static void F_80 ( unsigned long V_4 , T_5 V_87 )
{
F_76 ( V_4 , V_87 ) ;
#ifndef F_73
asm volatile ("");
F_76 ( V_4 + 1 , V_87 >> 32 ) ;
#endif
}
static void F_81 ( unsigned long V_4 , T_2 V_89 )
{
F_76 ( V_4 , F_69 ( V_4 ) & ~ V_89 ) ;
}
static void F_82 ( unsigned long V_4 , T_2 V_89 )
{
F_76 ( V_4 , F_69 ( V_4 ) | V_89 ) ;
}
static void F_83 ( struct V_1 * V_58 )
{
V_58 -> V_90 . V_91 = 0 ;
}
static bool F_84 ( struct V_1 * V_58 , unsigned V_92 ,
unsigned V_4 )
{
bool V_93 ;
T_2 V_89 = 1 << ( V_92 * V_94 + V_4 ) ;
if ( ! ( V_58 -> V_3 . V_95 . V_96 & ( 1 << V_97 ) ) ) {
V_58 -> V_3 . V_95 . V_96 |= ( 1 << V_97 ) ;
V_58 -> V_90 . V_91 = 0 ;
}
V_93 = V_58 -> V_90 . V_91 & V_89 ;
V_58 -> V_90 . V_91 |= V_89 ;
return V_93 ;
}
static T_3 F_85 ( struct V_1 * V_58 , unsigned V_92 )
{
T_3 * V_98 = & V_58 -> V_90 . V_92 [ V_92 ] . V_99 ;
if ( ! F_84 ( V_58 , V_92 , V_100 ) )
* V_98 = F_70 ( V_101 [ V_92 ] . V_99 ) ;
return * V_98 ;
}
static T_9 F_86 ( struct V_1 * V_58 , unsigned V_92 )
{
T_9 * V_98 = & V_58 -> V_90 . V_92 [ V_92 ] . V_102 ;
if ( ! F_84 ( V_58 , V_92 , V_103 ) )
* V_98 = F_69 ( V_101 [ V_92 ] . V_102 ) ;
return * V_98 ;
}
static T_2 F_87 ( struct V_1 * V_58 , unsigned V_92 )
{
T_2 * V_98 = & V_58 -> V_90 . V_92 [ V_92 ] . V_104 ;
if ( ! F_84 ( V_58 , V_92 , V_105 ) )
* V_98 = F_71 ( V_101 [ V_92 ] . V_104 ) ;
return * V_98 ;
}
static T_2 F_88 ( struct V_1 * V_58 , unsigned V_92 )
{
T_2 * V_98 = & V_58 -> V_90 . V_92 [ V_92 ] . V_106 ;
if ( ! F_84 ( V_58 , V_92 , V_107 ) )
* V_98 = F_71 ( V_101 [ V_92 ] . V_108 ) ;
return * V_98 ;
}
static void F_89 ( struct V_2 * V_3 )
{
T_2 V_109 ;
V_109 = ( 1u << V_19 ) | ( 1u << V_21 ) | ( 1u << V_23 ) |
( 1u << V_20 ) | ( 1u << V_110 ) ;
if ( ( V_3 -> V_111 &
( V_112 | V_113 ) ) ==
( V_112 | V_113 ) )
V_109 |= 1u << V_114 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 )
V_109 = ~ 0 ;
if ( V_84 )
V_109 &= ~ ( 1u << V_19 ) ;
if ( V_3 -> V_117 )
V_109 &= ~ ( 1u << V_20 ) ;
if ( F_90 ( V_3 ) )
V_109 |= F_4 ( V_3 ) -> V_118 ;
F_79 ( V_119 , V_109 ) ;
}
static void F_91 ( struct V_1 * V_58 , unsigned V_59 )
{
unsigned V_60 ;
struct V_120 * V_121 = & V_58 -> V_120 ;
if ( V_59 == V_122 && V_123 ) {
F_81 ( V_124 , V_125 ) ;
F_81 ( V_126 , V_127 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_121 -> V_128 ; ++ V_60 )
if ( V_121 -> V_129 [ V_60 ] . V_64 == V_59 )
break;
if ( V_60 == V_121 -> V_128 )
return;
-- V_121 -> V_128 ;
V_121 -> V_129 [ V_60 ] = V_121 -> V_129 [ V_121 -> V_128 ] ;
V_121 -> V_130 [ V_60 ] = V_121 -> V_130 [ V_121 -> V_128 ] ;
F_79 ( V_131 , V_121 -> V_128 ) ;
F_79 ( V_132 , V_121 -> V_128 ) ;
}
static void F_92 ( struct V_1 * V_58 , unsigned V_59 ,
T_5 V_133 , T_5 V_134 )
{
unsigned V_60 ;
struct V_120 * V_121 = & V_58 -> V_120 ;
if ( V_59 == V_122 && V_123 ) {
F_80 ( V_135 , V_133 ) ;
F_80 ( V_136 , V_134 ) ;
F_82 ( V_124 , V_125 ) ;
F_82 ( V_126 , V_127 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_121 -> V_128 ; ++ V_60 )
if ( V_121 -> V_129 [ V_60 ] . V_64 == V_59 )
break;
if ( V_60 == V_121 -> V_128 ) {
++ V_121 -> V_128 ;
F_79 ( V_131 , V_121 -> V_128 ) ;
F_79 ( V_132 , V_121 -> V_128 ) ;
}
V_121 -> V_129 [ V_60 ] . V_64 = V_59 ;
V_121 -> V_129 [ V_60 ] . V_87 = V_133 ;
V_121 -> V_130 [ V_60 ] . V_64 = V_59 ;
V_121 -> V_130 [ V_60 ] . V_87 = V_134 ;
}
static void F_93 ( void )
{
struct V_137 * V_138 = & F_94 ( V_139 ) ;
struct V_140 * V_141 ;
V_141 = ( void * ) V_138 -> V_142 ;
V_141 [ V_143 ] . type = 9 ;
F_95 () ;
}
static bool F_96 ( struct V_1 * V_58 , int V_144 )
{
T_5 V_145 ;
T_5 V_146 ;
V_145 = V_58 -> V_3 . V_95 . V_147 ;
V_146 = V_148 | V_149 ;
#ifdef F_73
V_146 |= V_150 | V_151 ;
if ( V_145 & V_150 )
V_146 &= ~ ( T_5 ) V_149 ;
#endif
V_145 &= ~ V_146 ;
V_145 |= V_152 & V_146 ;
V_58 -> V_63 [ V_144 ] . V_153 = V_145 ;
V_58 -> V_63 [ V_144 ] . V_89 = ~ V_146 ;
F_91 ( V_58 , V_122 ) ;
if ( V_84 && ( ( V_58 -> V_3 . V_95 . V_147 ^ V_152 ) & V_148 ) ) {
V_145 = V_58 -> V_3 . V_95 . V_147 ;
if ( ! ( V_145 & V_150 ) )
V_145 &= ~ V_151 ;
F_92 ( V_58 , V_122 , V_145 , V_152 ) ;
return false ;
}
return true ;
}
static unsigned long F_97 ( T_3 V_99 )
{
struct V_137 * V_138 = & F_94 ( V_139 ) ;
struct V_140 * V_154 ;
unsigned long V_155 ;
unsigned long V_156 ;
if ( ! ( V_99 & ~ 3 ) )
return 0 ;
V_155 = V_138 -> V_142 ;
if ( V_99 & 4 ) {
T_3 V_157 = F_98 () ;
if ( ! ( V_157 & ~ 3 ) )
return 0 ;
V_155 = F_97 ( V_157 ) ;
}
V_154 = (struct V_140 * ) ( V_155 + ( V_99 & ~ 7 ) ) ;
V_156 = F_99 ( V_154 ) ;
#ifdef F_73
if ( V_154 -> V_158 == 0 && ( V_154 -> type == 2 || V_154 -> type == 9 || V_154 -> type == 11 ) )
V_156 |= ( ( unsigned long ) ( (struct V_159 * ) V_154 ) -> V_160 ) << 32 ;
#endif
return V_156 ;
}
static inline unsigned long F_100 ( void )
{
T_3 V_161 ;
asm("str %0" : "=g"(tr));
return F_97 ( V_161 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_60 ;
if ( V_58 -> V_162 . V_163 )
return;
V_58 -> V_162 . V_163 = 1 ;
V_58 -> V_162 . V_164 = F_98 () ;
V_58 -> V_162 . V_165 = V_58 -> V_162 . V_164 ;
F_102 ( V_166 , V_58 -> V_162 . V_167 ) ;
if ( ! ( V_58 -> V_162 . V_167 & 7 ) ) {
F_78 ( V_168 , V_58 -> V_162 . V_167 ) ;
V_58 -> V_162 . V_169 = 0 ;
} else {
F_78 ( V_168 , 0 ) ;
V_58 -> V_162 . V_169 = 1 ;
}
F_102 ( V_170 , V_58 -> V_162 . V_171 ) ;
if ( ! ( V_58 -> V_162 . V_171 & 7 ) )
F_78 ( V_172 , V_58 -> V_162 . V_171 ) ;
else {
F_78 ( V_172 , 0 ) ;
V_58 -> V_162 . V_165 = 1 ;
}
#ifdef F_73
F_76 ( V_173 , F_103 ( V_174 ) ) ;
F_76 ( V_175 , F_103 ( V_176 ) ) ;
#else
F_76 ( V_173 , F_97 ( V_58 -> V_162 . V_167 ) ) ;
F_76 ( V_175 , F_97 ( V_58 -> V_162 . V_171 ) ) ;
#endif
#ifdef F_73
F_104 ( V_177 , V_58 -> V_178 ) ;
if ( F_105 ( & V_58 -> V_3 ) )
F_106 ( V_177 , V_58 -> V_179 ) ;
#endif
for ( V_60 = 0 ; V_60 < V_58 -> V_180 ; ++ V_60 )
F_107 ( V_58 -> V_63 [ V_60 ] . V_64 ,
V_58 -> V_63 [ V_60 ] . V_153 ,
V_58 -> V_63 [ V_60 ] . V_89 ) ;
}
static void F_108 ( struct V_1 * V_58 )
{
if ( ! V_58 -> V_162 . V_163 )
return;
++ V_58 -> V_3 . V_181 . V_182 ;
V_58 -> V_162 . V_163 = 0 ;
#ifdef F_73
if ( F_105 ( & V_58 -> V_3 ) )
F_104 ( V_177 , V_58 -> V_179 ) ;
#endif
if ( V_58 -> V_162 . V_165 ) {
F_109 ( V_58 -> V_162 . V_164 ) ;
#ifdef F_73
F_110 ( V_58 -> V_162 . V_171 ) ;
#else
F_111 ( V_170 , V_58 -> V_162 . V_171 ) ;
#endif
}
if ( V_58 -> V_162 . V_169 )
F_111 ( V_166 , V_58 -> V_162 . V_167 ) ;
F_93 () ;
#ifdef F_73
F_106 ( V_177 , V_58 -> V_178 ) ;
#endif
if ( F_112 () -> V_183 & V_184 )
F_113 () ;
F_114 ( & F_94 ( V_139 ) ) ;
}
static void F_115 ( struct V_1 * V_58 )
{
F_116 () ;
F_108 ( V_58 ) ;
F_117 () ;
}
static void F_118 ( struct V_2 * V_3 , int V_76 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_5 V_73 = F_53 ( F_59 ( V_185 , V_76 ) ) ;
if ( ! V_186 )
F_119 ( V_73 ) ;
else if ( V_58 -> V_75 -> V_76 != V_76 )
F_61 ( V_58 -> V_75 ) ;
if ( F_59 ( V_79 , V_76 ) != V_58 -> V_75 -> V_72 ) {
F_59 ( V_79 , V_76 ) = V_58 -> V_75 -> V_72 ;
F_56 ( V_58 -> V_75 -> V_72 ) ;
}
if ( V_58 -> V_75 -> V_76 != V_76 ) {
struct V_137 * V_138 = & F_94 ( V_139 ) ;
unsigned long V_187 ;
F_120 ( V_188 , V_3 ) ;
F_121 () ;
F_122 ( & V_58 -> V_75 -> V_80 ,
& F_59 ( V_189 , V_76 ) ) ;
F_123 () ;
F_76 ( V_190 , F_100 () ) ;
F_76 ( V_191 , V_138 -> V_142 ) ;
F_104 ( V_192 , V_187 ) ;
F_76 ( V_193 , V_187 ) ;
V_58 -> V_75 -> V_76 = V_76 ;
}
}
static void F_124 ( struct V_2 * V_3 )
{
F_108 ( F_1 ( V_3 ) ) ;
if ( ! V_186 ) {
F_57 ( F_1 ( V_3 ) -> V_75 ) ;
V_3 -> V_76 = - 1 ;
F_125 () ;
}
}
static void F_126 ( struct V_2 * V_3 )
{
T_9 V_194 ;
if ( V_3 -> V_117 )
return;
V_3 -> V_117 = 1 ;
V_194 = F_69 ( V_195 ) ;
V_194 &= ~ ( V_196 | V_197 ) ;
V_194 |= F_127 ( V_3 , V_196 | V_197 ) ;
F_76 ( V_195 , V_194 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_198 = V_196 ;
if ( F_90 ( V_3 ) )
V_3 -> V_95 . V_198 &=
~ F_4 ( V_3 ) -> V_199 ;
F_76 ( V_200 , ~ V_3 -> V_95 . V_198 ) ;
}
static inline unsigned long F_128 ( struct V_7 * V_201 )
{
return ( V_201 -> V_202 & ~ V_201 -> V_199 ) |
( V_201 -> V_203 & V_201 -> V_199 ) ;
}
static inline unsigned long F_129 ( struct V_7 * V_201 )
{
return ( V_201 -> V_204 & ~ V_201 -> V_205 ) |
( V_201 -> V_206 & V_201 -> V_205 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
F_131 ( V_3 ) ;
F_82 ( V_195 , V_196 | V_197 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_198 = 0 ;
F_76 ( V_200 , ~ V_3 -> V_95 . V_198 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_202 = ( V_7 -> V_202 & ~ V_196 ) |
( V_3 -> V_95 . V_194 & V_196 ) ;
F_76 ( V_207 , F_128 ( V_7 ) ) ;
} else
F_76 ( V_207 , V_3 -> V_95 . V_194 ) ;
}
static unsigned long F_132 ( struct V_2 * V_3 )
{
unsigned long V_208 , V_209 ;
if ( ! F_133 ( V_210 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_134 ( V_210 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
V_208 = F_69 ( V_211 ) ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
V_208 &= V_212 ;
V_209 = F_1 ( V_3 ) -> V_115 . V_209 ;
V_208 |= V_209 & ~ V_212 ;
}
F_1 ( V_3 ) -> V_208 = V_208 ;
}
return F_1 ( V_3 ) -> V_208 ;
}
static void F_135 ( struct V_2 * V_3 , unsigned long V_208 )
{
F_134 ( V_210 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_136 ( V_213 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_208 = V_208 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
F_1 ( V_3 ) -> V_115 . V_209 = V_208 ;
V_208 |= V_214 | V_215 ;
}
F_76 ( V_211 , V_208 ) ;
}
static T_2 F_137 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_216 = F_71 ( V_217 ) ;
int V_93 = 0 ;
if ( V_216 & V_218 )
V_93 |= V_219 ;
if ( V_216 & V_220 )
V_93 |= V_221 ;
return V_93 & V_89 ;
}
static void F_138 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_222 = F_71 ( V_217 ) ;
T_2 V_216 = V_222 ;
V_216 &= ~ ( V_218 | V_220 ) ;
if ( V_89 & V_221 )
V_216 |= V_220 ;
else if ( V_89 & V_219 )
V_216 |= V_218 ;
if ( ( V_216 != V_222 ) )
F_79 ( V_217 , V_216 ) ;
}
static void F_139 ( struct V_2 * V_3 )
{
unsigned long V_223 ;
V_223 = F_140 ( V_3 ) ;
V_223 += F_71 ( V_224 ) ;
F_141 ( V_3 , V_223 ) ;
F_138 ( V_3 , 0 ) ;
}
static void F_142 ( struct V_2 * V_3 )
{
if ( ! V_225 &&
F_71 ( V_226 ) == V_227 )
F_79 ( V_226 , V_228 ) ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( ! ( V_7 -> V_118 & V_19 ) )
return 0 ;
F_144 ( V_3 ) ;
return 1 ;
}
static void F_145 ( struct V_2 * V_3 , unsigned V_128 ,
bool V_229 , T_2 V_230 ,
bool V_231 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_14 = V_128 | V_17 ;
if ( V_128 == V_19 && F_90 ( V_3 ) &&
F_143 ( V_3 ) )
return;
if ( V_229 ) {
F_79 ( V_232 , V_230 ) ;
V_14 |= V_233 ;
}
if ( V_58 -> V_115 . V_116 ) {
int V_234 = 0 ;
if ( F_146 ( V_128 ) )
V_234 = V_3 -> V_95 . V_235 ;
if ( F_147 ( V_3 , V_128 , V_234 ) != V_236 )
F_120 ( V_237 , V_3 ) ;
return;
}
if ( F_146 ( V_128 ) ) {
F_79 ( V_238 ,
V_58 -> V_3 . V_95 . V_235 ) ;
V_14 |= V_239 ;
} else
V_14 |= V_18 ;
F_79 ( V_240 , V_14 ) ;
F_142 ( V_3 ) ;
}
static bool F_148 ( void )
{
return F_40 () ;
}
static void F_149 ( struct V_1 * V_58 , int V_241 , int V_242 )
{
struct V_71 V_243 ;
V_243 = V_58 -> V_63 [ V_242 ] ;
V_58 -> V_63 [ V_242 ] = V_58 -> V_63 [ V_241 ] ;
V_58 -> V_63 [ V_241 ] = V_243 ;
}
static void F_150 ( struct V_1 * V_58 )
{
int V_180 , V_64 ;
unsigned long * V_244 ;
F_115 ( V_58 ) ;
V_180 = 0 ;
#ifdef F_73
if ( F_105 ( & V_58 -> V_3 ) ) {
V_64 = F_48 ( V_58 , V_245 ) ;
if ( V_64 >= 0 )
F_149 ( V_58 , V_64 , V_180 ++ ) ;
V_64 = F_48 ( V_58 , V_246 ) ;
if ( V_64 >= 0 )
F_149 ( V_58 , V_64 , V_180 ++ ) ;
V_64 = F_48 ( V_58 , V_247 ) ;
if ( V_64 >= 0 )
F_149 ( V_58 , V_64 , V_180 ++ ) ;
V_64 = F_48 ( V_58 , V_248 ) ;
if ( V_64 >= 0 && V_58 -> V_249 )
F_149 ( V_58 , V_64 , V_180 ++ ) ;
V_64 = F_48 ( V_58 , V_250 ) ;
if ( ( V_64 >= 0 ) && ( V_58 -> V_3 . V_95 . V_147 & V_149 ) )
F_149 ( V_58 , V_64 , V_180 ++ ) ;
}
#endif
V_64 = F_48 ( V_58 , V_122 ) ;
if ( V_64 >= 0 && F_96 ( V_58 , V_64 ) )
F_149 ( V_58 , V_64 , V_180 ++ ) ;
V_58 -> V_180 = V_180 ;
if ( F_17 () ) {
if ( F_105 ( & V_58 -> V_3 ) )
V_244 = V_251 ;
else
V_244 = V_252 ;
F_80 ( V_253 , F_53 ( V_244 ) ) ;
}
}
static T_5 F_151 ( void )
{
T_5 V_254 , V_255 ;
F_152 ( V_254 ) ;
V_255 = F_72 ( V_256 ) ;
return V_254 + V_255 ;
}
static void F_153 ( struct V_2 * V_3 , T_2 V_257 )
{
}
static void F_154 ( struct V_2 * V_3 , T_5 V_258 )
{
F_80 ( V_256 , V_258 ) ;
if ( F_90 ( V_3 ) )
F_4 ( V_3 ) -> V_255 = V_258 -
F_1 ( V_3 ) -> V_8 . V_259 ;
}
static void F_155 ( struct V_2 * V_3 , T_10 V_260 )
{
T_5 V_258 = F_72 ( V_256 ) ;
F_80 ( V_256 , V_258 + V_260 ) ;
if ( F_90 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_259 += V_260 ;
}
}
static T_5 F_156 ( struct V_2 * V_3 , T_5 V_261 )
{
return V_261 - F_157 () ;
}
static bool F_158 ( struct V_2 * V_3 )
{
struct V_262 * V_263 = F_159 ( V_3 , 1 , 0 ) ;
return V_263 && ( V_263 -> V_264 & ( 1 << ( V_265 & 31 ) ) ) ;
}
static inline bool F_160 ( struct V_2 * V_3 )
{
return V_8 && F_158 ( V_3 ) ;
}
static T_11 void F_161 ( void )
{
V_266 = 0x16 ;
V_267 = 0x16 |
V_268 | V_269 |
V_52 ;
V_270 = 0 ;
#ifdef F_73
V_271 = V_272 ;
#else
V_271 = 0 ;
#endif
F_162 ( V_273 ,
V_274 , V_275 ) ;
V_274 = 0 ;
V_275 &=
V_276 | V_277 ;
F_162 ( V_278 ,
V_279 , V_280 ) ;
V_279 = 0 ;
V_280 &=
V_281 | V_282 |
V_283 | V_284 |
V_285 | V_286 |
V_287 |
#ifdef F_73
V_288 | V_289 |
#endif
V_290 | V_291 |
V_292 | V_293 |
V_28 ;
V_280 |= V_26 ;
F_162 ( V_294 ,
V_295 , V_296 ) ;
V_295 = 0 ;
V_296 &=
V_30 ;
}
static inline bool F_163 ( T_2 V_297 , T_2 V_298 , T_2 V_299 )
{
return ( ( V_297 & V_299 ) | V_298 ) == V_297 ;
}
static inline T_5 F_164 ( T_2 V_298 , T_2 V_299 )
{
return V_298 | ( ( T_5 ) V_299 << 32 ) ;
}
static int F_165 ( struct V_2 * V_3 , T_2 V_300 , T_5 * V_301 )
{
if ( ! F_160 ( V_3 ) && V_300 >= V_302 &&
V_300 <= V_303 ) {
F_166 ( V_3 , V_304 , 0 ) ;
return 1 ;
}
switch ( V_300 ) {
case V_305 :
* V_301 = 0 ;
break;
case V_302 :
* V_301 = V_306 |
( ( T_5 ) V_307 << V_308 ) |
( V_309 << V_310 ) ;
break;
case V_311 :
case V_312 :
* V_301 = F_164 ( V_266 ,
V_267 ) ;
break;
case V_313 :
case V_278 :
* V_301 = F_164 ( V_279 ,
V_280 ) ;
break;
case V_314 :
case V_315 :
* V_301 = F_164 ( V_270 ,
V_271 ) ;
break;
case V_303 :
case V_273 :
* V_301 = F_164 ( V_274 ,
V_275 ) ;
break;
case V_316 :
* V_301 = 0 ;
break;
#define F_167 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_168 X86_CR4_VMXE
case V_317 :
* V_301 = F_167 ;
break;
case V_318 :
* V_301 = - 1ULL ;
break;
case V_319 :
* V_301 = F_168 ;
break;
case V_320 :
* V_301 = - 1ULL ;
break;
case V_321 :
* V_301 = 0x1f ;
break;
case V_294 :
* V_301 = F_164 ( V_295 ,
V_296 ) ;
break;
case V_322 :
* V_301 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_169 ( struct V_2 * V_3 , T_2 V_300 , T_5 V_153 )
{
if ( ! F_160 ( V_3 ) )
return 0 ;
if ( V_300 == V_305 )
return 1 ;
return 0 ;
}
static int F_170 ( struct V_2 * V_3 , T_2 V_300 , T_5 * V_301 )
{
T_5 V_153 ;
struct V_71 * V_59 ;
if ( ! V_301 ) {
F_54 ( V_74 L_4 ) ;
return - V_323 ;
}
switch ( V_300 ) {
#ifdef F_73
case V_174 :
V_153 = F_69 ( V_324 ) ;
break;
case V_176 :
V_153 = F_69 ( V_325 ) ;
break;
case V_177 :
F_115 ( F_1 ( V_3 ) ) ;
V_153 = F_1 ( V_3 ) -> V_179 ;
break;
#endif
case V_122 :
return F_171 ( V_3 , V_300 , V_301 ) ;
case V_326 :
V_153 = F_151 () ;
break;
case V_327 :
V_153 = F_71 ( V_328 ) ;
break;
case V_329 :
V_153 = F_69 ( V_330 ) ;
break;
case V_192 :
V_153 = F_69 ( V_331 ) ;
break;
case V_248 :
if ( ! F_1 ( V_3 ) -> V_249 )
return 1 ;
default:
F_115 ( F_1 ( V_3 ) ) ;
if ( F_165 ( V_3 , V_300 , V_301 ) )
return 0 ;
V_59 = F_51 ( F_1 ( V_3 ) , V_300 ) ;
if ( V_59 ) {
F_115 ( F_1 ( V_3 ) ) ;
V_153 = V_59 -> V_153 ;
break;
}
return F_171 ( V_3 , V_300 , V_301 ) ;
}
* V_301 = V_153 ;
return 0 ;
}
static int F_172 ( struct V_2 * V_3 , T_2 V_300 , T_5 V_153 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_71 * V_59 ;
int V_93 = 0 ;
switch ( V_300 ) {
case V_122 :
F_115 ( V_58 ) ;
V_93 = F_173 ( V_3 , V_300 , V_153 ) ;
break;
#ifdef F_73
case V_174 :
F_83 ( V_58 ) ;
F_76 ( V_324 , V_153 ) ;
break;
case V_176 :
F_83 ( V_58 ) ;
F_76 ( V_325 , V_153 ) ;
break;
case V_177 :
F_115 ( V_58 ) ;
V_58 -> V_179 = V_153 ;
break;
#endif
case V_327 :
F_79 ( V_328 , V_153 ) ;
break;
case V_329 :
F_76 ( V_330 , V_153 ) ;
break;
case V_192 :
F_76 ( V_331 , V_153 ) ;
break;
case V_326 :
F_174 ( V_3 , V_153 ) ;
break;
case V_332 :
if ( V_24 . V_333 & V_276 ) {
F_80 ( V_334 , V_153 ) ;
V_3 -> V_95 . V_335 = V_153 ;
break;
}
V_93 = F_173 ( V_3 , V_300 , V_153 ) ;
break;
case V_248 :
if ( ! V_58 -> V_249 )
return 1 ;
if ( ( V_153 >> 32 ) != 0 )
return 1 ;
default:
if ( F_169 ( V_3 , V_300 , V_153 ) )
break;
V_59 = F_51 ( V_58 , V_300 ) ;
if ( V_59 ) {
F_115 ( V_58 ) ;
V_59 -> V_153 = V_153 ;
break;
}
V_93 = F_173 ( V_3 , V_300 , V_153 ) ;
}
return V_93 ;
}
static void F_175 ( struct V_2 * V_3 , enum V_336 V_337 )
{
F_134 ( V_337 , ( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
switch ( V_337 ) {
case V_338 :
V_3 -> V_95 . V_339 [ V_338 ] = F_69 ( V_340 ) ;
break;
case V_341 :
V_3 -> V_95 . V_339 [ V_341 ] = F_69 ( V_342 ) ;
break;
case V_343 :
if ( V_84 )
F_176 ( V_3 ) ;
break;
default:
break;
}
}
static void F_177 ( struct V_2 * V_3 , struct V_344 * V_345 )
{
if ( V_3 -> V_111 & V_346 )
F_76 ( V_347 , V_345 -> V_95 . V_348 [ 7 ] ) ;
else
F_76 ( V_347 , V_3 -> V_95 . V_349 ) ;
F_89 ( V_3 ) ;
}
static T_11 int F_178 ( void )
{
return F_179 () ;
}
static T_11 int F_180 ( void )
{
T_5 V_59 ;
F_104 ( V_305 , V_59 ) ;
if ( V_59 & V_350 ) {
if ( ! ( V_59 & V_351 )
&& F_181 () )
return 1 ;
if ( ! ( V_59 & V_352 )
&& ( V_59 & V_351 )
&& ! F_181 () ) {
F_54 ( V_353 L_5
L_6 ) ;
return 1 ;
}
if ( ! ( V_59 & V_352 )
&& ! F_181 () )
return 1 ;
}
return 0 ;
}
static void F_119 ( T_5 V_11 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_182 ( void * V_354 )
{
int V_76 = F_58 () ;
T_5 V_73 = F_53 ( F_59 ( V_185 , V_76 ) ) ;
T_5 V_355 , V_356 ;
if ( F_183 () & V_357 )
return - V_358 ;
F_184 ( & F_59 ( V_189 , V_76 ) ) ;
F_104 ( V_305 , V_355 ) ;
V_356 = V_350 ;
V_356 |= V_352 ;
if ( F_181 () )
V_356 |= V_351 ;
if ( ( V_355 & V_356 ) != V_356 ) {
F_106 ( V_305 , V_355 | V_356 ) ;
}
F_185 ( F_183 () | V_357 ) ;
if ( V_186 ) {
F_119 ( V_73 ) ;
F_66 () ;
}
F_186 ( & F_94 ( V_139 ) ) ;
return 0 ;
}
static void F_187 ( void )
{
int V_76 = F_58 () ;
struct V_75 * V_156 , * V_359 ;
F_188 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_57 ( V_156 ) ;
}
static void F_125 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_189 ( void * V_354 )
{
if ( V_186 ) {
F_187 () ;
F_125 () ;
}
F_185 ( F_183 () & ~ V_357 ) ;
}
static T_11 int F_190 ( T_2 V_360 , T_2 V_361 ,
T_2 V_59 , T_2 * V_362 )
{
T_2 V_363 , V_364 ;
T_2 V_365 = V_360 | V_361 ;
F_162 ( V_59 , V_363 , V_364 ) ;
V_365 &= V_364 ;
V_365 |= V_363 ;
if ( V_360 & ~ V_365 )
return - V_366 ;
* V_362 = V_365 ;
return 0 ;
}
static T_11 bool F_191 ( T_2 V_59 , T_2 V_365 )
{
T_2 V_363 , V_364 ;
F_162 ( V_59 , V_363 , V_364 ) ;
return V_364 & V_365 ;
}
static T_11 int F_192 ( struct V_24 * V_367 )
{
T_2 V_363 , V_364 ;
T_2 V_368 , V_369 , V_370 , V_371 ;
T_2 V_372 = 0 ;
T_2 V_373 = 0 ;
T_2 V_374 = 0 ;
T_2 V_375 = 0 ;
T_2 V_376 = 0 ;
V_368 = V_268 | V_269 ;
V_369 = V_52 ;
if ( F_190 ( V_368 , V_369 , V_312 ,
& V_372 ) < 0 )
return - V_366 ;
V_368 =
#ifdef F_73
V_288 |
V_289 |
#endif
V_286 |
V_287 |
V_292 |
V_290 |
V_282 |
V_285 |
V_293 |
V_284 ;
if ( V_225 )
V_368 |= V_283 ;
V_369 = V_27 |
V_26 |
V_28 ;
if ( F_190 ( V_368 , V_369 , V_278 ,
& V_373 ) < 0 )
return - V_366 ;
#ifdef F_73
if ( ( V_373 & V_27 ) )
V_373 &= ~ V_288 &
~ V_289 ;
#endif
if ( V_373 & V_28 ) {
V_370 = 0 ;
V_371 = V_30 |
V_53 |
V_49 |
V_45 |
V_46 |
V_47 |
V_50 ;
if ( F_190 ( V_370 , V_371 ,
V_294 ,
& V_374 ) < 0 )
return - V_366 ;
}
#ifndef F_73
if ( ! ( V_374 &
V_30 ) )
V_373 &= ~ V_27 ;
#endif
if ( V_374 & V_45 ) {
V_373 &= ~ ( V_286 |
V_287 |
V_284 ) ;
F_162 ( V_322 ,
V_31 . V_32 , V_31 . V_42 ) ;
}
V_368 = 0 ;
#ifdef F_73
V_368 |= V_272 ;
#endif
V_369 = V_377 | V_378 ;
if ( F_190 ( V_368 , V_369 , V_315 ,
& V_375 ) < 0 )
return - V_366 ;
V_368 = 0 ;
V_369 = V_276 ;
if ( F_190 ( V_368 , V_369 , V_273 ,
& V_376 ) < 0 )
return - V_366 ;
F_162 ( V_302 , V_363 , V_364 ) ;
if ( ( V_364 & 0x1fff ) > V_379 )
return - V_366 ;
#ifdef F_73
if ( V_364 & ( 1u << 16 ) )
return - V_366 ;
#endif
if ( ( ( V_364 >> 18 ) & 15 ) != 6 )
return - V_366 ;
V_367 -> V_380 = V_364 & 0x1fff ;
V_367 -> V_381 = F_193 ( V_24 . V_380 ) ;
V_367 -> V_382 = V_363 ;
V_367 -> V_51 = V_372 ;
V_367 -> V_25 = V_373 ;
V_367 -> V_29 = V_374 ;
V_367 -> V_383 = V_375 ;
V_367 -> V_333 = V_376 ;
V_123 =
F_191 ( V_273 ,
V_125 )
&& F_191 ( V_315 ,
V_127 ) ;
return 0 ;
}
static struct V_72 * F_194 ( int V_76 )
{
int V_384 = F_195 ( V_76 ) ;
struct V_10 * V_385 ;
struct V_72 * V_72 ;
V_385 = F_196 ( V_384 , V_386 , V_24 . V_381 ) ;
if ( ! V_385 )
return NULL ;
V_72 = F_197 ( V_385 ) ;
memset ( V_72 , 0 , V_24 . V_380 ) ;
V_72 -> V_382 = V_24 . V_382 ;
return V_72 ;
}
static struct V_72 * F_198 ( void )
{
return F_194 ( F_58 () ) ;
}
static void F_199 ( struct V_72 * V_72 )
{
F_200 ( ( unsigned long ) V_72 , V_24 . V_381 ) ;
}
static void F_201 ( struct V_75 * V_75 )
{
if ( ! V_75 -> V_72 )
return;
F_61 ( V_75 ) ;
F_199 ( V_75 -> V_72 ) ;
V_75 -> V_72 = NULL ;
}
static void F_202 ( void )
{
int V_76 ;
F_203 (cpu) {
F_199 ( F_59 ( V_185 , V_76 ) ) ;
F_59 ( V_185 , V_76 ) = NULL ;
}
}
static T_11 int F_204 ( void )
{
int V_76 ;
F_203 (cpu) {
struct V_72 * V_72 ;
V_72 = F_194 ( V_76 ) ;
if ( ! V_72 ) {
F_202 () ;
return - V_387 ;
}
F_59 ( V_185 , V_76 ) = V_72 ;
}
return 0 ;
}
static T_11 int F_205 ( void )
{
if ( F_192 ( & V_24 ) < 0 )
return - V_366 ;
if ( F_206 ( V_388 ) )
F_207 ( V_148 ) ;
if ( ! F_39 () )
V_389 = 0 ;
if ( ! F_35 () ||
! F_29 () ) {
V_84 = 0 ;
V_390 = 0 ;
}
if ( ! F_36 () )
V_390 = 0 ;
if ( ! F_23 () )
V_48 = 0 ;
if ( ! F_18 () )
V_391 -> V_392 = NULL ;
if ( V_84 && ! F_27 () )
F_208 () ;
if ( ! F_37 () )
V_393 = 0 ;
if ( V_8 )
F_161 () ;
return F_204 () ;
}
static T_12 void F_209 ( void )
{
F_202 () ;
}
static void F_210 ( int V_92 , struct V_394 * V_395 )
{
struct V_396 * V_397 = & V_101 [ V_92 ] ;
if ( F_69 ( V_397 -> V_102 ) == V_395 -> V_102 && ( V_395 -> V_102 & V_398 ) ) {
F_78 ( V_397 -> V_99 , V_395 -> V_99 ) ;
F_76 ( V_397 -> V_102 , V_395 -> V_102 ) ;
F_79 ( V_397 -> V_104 , V_395 -> V_104 ) ;
F_79 ( V_397 -> V_108 , V_395 -> V_106 ) ;
} else {
T_2 V_399 = ( F_70 ( V_397 -> V_99 ) & V_400 )
<< V_401 ;
F_79 ( V_397 -> V_108 , 0x93 | V_399 ) ;
}
}
static void F_211 ( struct V_2 * V_3 )
{
unsigned long V_402 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
V_58 -> V_403 = 1 ;
V_58 -> V_115 . V_116 = 0 ;
F_83 ( V_58 ) ;
F_78 ( V_404 , V_58 -> V_115 . V_161 . V_99 ) ;
F_76 ( V_405 , V_58 -> V_115 . V_161 . V_102 ) ;
F_79 ( V_406 , V_58 -> V_115 . V_161 . V_104 ) ;
F_79 ( V_407 , V_58 -> V_115 . V_161 . V_106 ) ;
V_402 = F_69 ( V_211 ) ;
V_402 &= V_212 ;
V_402 |= V_58 -> V_115 . V_209 & ~ V_212 ;
F_76 ( V_211 , V_402 ) ;
F_76 ( V_408 , ( F_69 ( V_408 ) & ~ V_409 ) |
( F_69 ( V_410 ) & V_409 ) ) ;
F_89 ( V_3 ) ;
if ( V_411 )
return;
F_210 ( V_412 , & V_58 -> V_115 . V_413 ) ;
F_210 ( V_414 , & V_58 -> V_115 . V_415 ) ;
F_210 ( V_416 , & V_58 -> V_115 . V_170 ) ;
F_210 ( V_417 , & V_58 -> V_115 . V_166 ) ;
F_83 ( V_58 ) ;
F_78 ( V_418 , 0 ) ;
F_79 ( V_419 , 0x93 ) ;
F_78 ( V_420 ,
F_70 ( V_420 ) & ~ V_400 ) ;
F_79 ( V_421 , 0x9b ) ;
}
static T_4 F_212 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_95 . V_422 ) {
struct V_423 * V_424 ;
T_13 V_425 ;
V_424 = V_423 ( V_12 ) ;
V_425 = V_424 -> V_426 [ 0 ] . V_425 +
V_12 -> V_426 -> V_426 [ 0 ] . V_427 - 3 ;
return V_425 << V_13 ;
}
return V_12 -> V_95 . V_422 ;
}
static void F_213 ( int V_92 , struct V_394 * V_395 )
{
struct V_396 * V_397 = & V_101 [ V_92 ] ;
V_395 -> V_99 = F_70 ( V_397 -> V_99 ) ;
V_395 -> V_102 = F_69 ( V_397 -> V_102 ) ;
V_395 -> V_104 = F_71 ( V_397 -> V_104 ) ;
V_395 -> V_106 = F_71 ( V_397 -> V_108 ) ;
F_78 ( V_397 -> V_99 , V_395 -> V_102 >> 4 ) ;
F_79 ( V_397 -> V_102 , V_395 -> V_102 & 0xffff0 ) ;
F_79 ( V_397 -> V_104 , 0xffff ) ;
F_79 ( V_397 -> V_108 , 0xf3 ) ;
if ( V_395 -> V_102 & 0xf )
F_214 ( V_353 L_7
L_8 ,
V_92 ) ;
}
static void F_215 ( struct V_2 * V_3 )
{
unsigned long V_402 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_390 )
return;
V_58 -> V_403 = 1 ;
V_58 -> V_115 . V_116 = 1 ;
if ( ! V_3 -> V_12 -> V_95 . V_422 ) {
F_214 ( V_353 L_9
L_10 ) ;
F_216 ( & V_3 -> V_12 -> V_428 , V_3 -> V_429 ) ;
F_217 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_429 = F_218 ( & V_3 -> V_12 -> V_428 ) ;
}
F_83 ( V_58 ) ;
V_58 -> V_115 . V_161 . V_99 = F_70 ( V_404 ) ;
V_58 -> V_115 . V_161 . V_102 = F_69 ( V_405 ) ;
F_76 ( V_405 , F_212 ( V_3 -> V_12 ) ) ;
V_58 -> V_115 . V_161 . V_104 = F_71 ( V_406 ) ;
F_79 ( V_406 , V_430 - 1 ) ;
V_58 -> V_115 . V_161 . V_106 = F_71 ( V_407 ) ;
F_79 ( V_407 , 0x008b ) ;
V_402 = F_69 ( V_211 ) ;
V_58 -> V_115 . V_209 = V_402 ;
V_402 |= V_214 | V_215 ;
F_76 ( V_211 , V_402 ) ;
F_76 ( V_408 , F_69 ( V_408 ) | V_409 ) ;
F_89 ( V_3 ) ;
if ( V_411 )
goto V_431;
F_78 ( V_418 , F_69 ( V_432 ) >> 4 ) ;
F_79 ( V_433 , 0xffff ) ;
F_79 ( V_419 , 0xf3 ) ;
F_79 ( V_421 , 0xf3 ) ;
F_79 ( V_434 , 0xffff ) ;
if ( F_69 ( V_435 ) == 0xffff0000 )
F_76 ( V_435 , 0xf0000 ) ;
F_78 ( V_420 , F_69 ( V_435 ) >> 4 ) ;
F_213 ( V_412 , & V_58 -> V_115 . V_413 ) ;
F_213 ( V_414 , & V_58 -> V_115 . V_415 ) ;
F_213 ( V_416 , & V_58 -> V_115 . V_170 ) ;
F_213 ( V_417 , & V_58 -> V_115 . V_166 ) ;
V_431:
F_219 ( V_3 ) ;
}
static void F_220 ( struct V_2 * V_3 , T_5 V_147 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_71 * V_59 = F_51 ( V_58 , V_122 ) ;
if ( ! V_59 )
return;
F_115 ( F_1 ( V_3 ) ) ;
V_3 -> V_95 . V_147 = V_147 ;
if ( V_147 & V_150 ) {
F_79 ( V_124 ,
F_71 ( V_124 ) |
V_277 ) ;
V_59 -> V_153 = V_147 ;
} else {
F_79 ( V_124 ,
F_71 ( V_124 ) &
~ V_277 ) ;
V_59 -> V_153 = V_147 & ~ V_151 ;
}
F_150 ( V_58 ) ;
}
static void F_221 ( struct V_2 * V_3 )
{
T_2 V_436 ;
F_83 ( F_1 ( V_3 ) ) ;
V_436 = F_71 ( V_407 ) ;
if ( ( V_436 & V_437 ) != V_438 ) {
F_54 ( V_439 L_11 ,
V_440 ) ;
F_79 ( V_407 ,
( V_436 & ~ V_437 )
| V_438 ) ;
}
F_220 ( V_3 , V_3 -> V_95 . V_147 | V_150 ) ;
}
static void F_222 ( struct V_2 * V_3 )
{
F_79 ( V_124 ,
F_71 ( V_124 )
& ~ V_277 ) ;
F_220 ( V_3 , V_3 -> V_95 . V_147 & ~ V_150 ) ;
}
static void F_223 ( struct V_2 * V_3 )
{
F_65 ( F_1 ( V_3 ) ) ;
if ( V_84 ) {
if ( ! F_224 ( V_3 -> V_95 . V_441 . V_442 ) )
return;
F_67 ( F_225 ( V_3 -> V_95 . V_441 . V_442 ) ) ;
}
}
static void F_131 ( struct V_2 * V_3 )
{
T_9 V_198 = V_3 -> V_95 . V_198 ;
V_3 -> V_95 . V_194 &= ~ V_198 ;
V_3 -> V_95 . V_194 |= F_69 ( V_195 ) & V_198 ;
}
static void F_226 ( struct V_2 * V_3 )
{
if ( V_84 && F_227 ( V_3 ) )
V_3 -> V_95 . V_443 = F_69 ( V_444 ) ;
F_134 ( V_445 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
T_9 V_446 = V_3 -> V_95 . V_446 ;
V_3 -> V_95 . V_447 &= ~ V_446 ;
V_3 -> V_95 . V_447 |= F_69 ( V_408 ) & V_446 ;
}
static void F_229 ( struct V_2 * V_3 )
{
if ( ! F_133 ( V_343 ,
( unsigned long * ) & V_3 -> V_95 . V_448 ) )
return;
if ( F_227 ( V_3 ) && F_230 ( V_3 ) && ! F_105 ( V_3 ) ) {
F_80 ( V_449 , V_3 -> V_95 . V_441 . V_450 [ 0 ] ) ;
F_80 ( V_451 , V_3 -> V_95 . V_441 . V_450 [ 1 ] ) ;
F_80 ( V_452 , V_3 -> V_95 . V_441 . V_450 [ 2 ] ) ;
F_80 ( V_453 , V_3 -> V_95 . V_441 . V_450 [ 3 ] ) ;
}
}
static void F_176 ( struct V_2 * V_3 )
{
if ( F_227 ( V_3 ) && F_230 ( V_3 ) && ! F_105 ( V_3 ) ) {
V_3 -> V_95 . V_441 . V_450 [ 0 ] = F_72 ( V_449 ) ;
V_3 -> V_95 . V_441 . V_450 [ 1 ] = F_72 ( V_451 ) ;
V_3 -> V_95 . V_441 . V_450 [ 2 ] = F_72 ( V_452 ) ;
V_3 -> V_95 . V_441 . V_450 [ 3 ] = F_72 ( V_453 ) ;
}
F_134 ( V_343 ,
( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
F_134 ( V_343 ,
( unsigned long * ) & V_3 -> V_95 . V_448 ) ;
}
static void F_231 ( unsigned long * V_454 ,
unsigned long V_194 ,
struct V_2 * V_3 )
{
if ( ! F_133 ( V_445 , ( T_9 * ) & V_3 -> V_95 . V_96 ) )
F_226 ( V_3 ) ;
if ( ! ( V_194 & V_455 ) ) {
F_79 ( V_456 ,
F_71 ( V_456 ) |
( V_286 |
V_287 ) ) ;
V_3 -> V_95 . V_194 = V_194 ;
F_232 ( V_3 , F_233 ( V_3 ) ) ;
} else if ( ! F_227 ( V_3 ) ) {
F_79 ( V_456 ,
F_71 ( V_456 ) &
~ ( V_286 |
V_287 ) ) ;
V_3 -> V_95 . V_194 = V_194 ;
F_232 ( V_3 , F_233 ( V_3 ) ) ;
}
if ( ! ( V_194 & V_457 ) )
* V_454 &= ~ V_457 ;
}
static void F_234 ( struct V_2 * V_3 , unsigned long V_194 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_454 ;
if ( V_390 )
V_454 = ( V_194 & ~ V_458 )
| V_459 ;
else
V_454 = ( V_194 & ~ V_460 ) | V_461 ;
if ( V_58 -> V_115 . V_116 && ( V_194 & V_462 ) )
F_211 ( V_3 ) ;
if ( ! V_58 -> V_115 . V_116 && ! ( V_194 & V_462 ) )
F_215 ( V_3 ) ;
#ifdef F_73
if ( V_3 -> V_95 . V_147 & V_151 ) {
if ( ! F_227 ( V_3 ) && ( V_194 & V_455 ) )
F_221 ( V_3 ) ;
if ( F_227 ( V_3 ) && ! ( V_194 & V_455 ) )
F_222 ( V_3 ) ;
}
#endif
if ( V_84 )
F_231 ( & V_454 , V_194 , V_3 ) ;
if ( ! V_3 -> V_117 )
V_454 |= V_196 | V_197 ;
F_76 ( V_207 , V_194 ) ;
F_76 ( V_195 , V_454 ) ;
V_3 -> V_95 . V_194 = V_194 ;
F_136 ( V_213 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static T_5 F_225 ( unsigned long V_442 )
{
T_5 V_69 ;
V_69 = V_463 |
V_464 << V_465 ;
V_69 |= ( V_442 & V_466 ) ;
return V_69 ;
}
static void F_235 ( struct V_2 * V_3 , unsigned long V_443 )
{
unsigned long V_467 ;
T_5 V_69 ;
V_467 = V_443 ;
if ( V_84 ) {
V_69 = F_225 ( V_443 ) ;
F_80 ( V_468 , V_69 ) ;
V_467 = F_227 ( V_3 ) ? F_236 ( V_3 ) :
V_3 -> V_12 -> V_95 . V_469 ;
F_229 ( V_3 ) ;
}
F_223 ( V_3 ) ;
F_76 ( V_444 , V_467 ) ;
}
static int F_232 ( struct V_2 * V_3 , unsigned long V_447 )
{
unsigned long V_470 = V_447 | ( F_1 ( V_3 ) -> V_115 . V_116 ?
V_471 : V_472 ) ;
if ( V_447 & V_357 ) {
if ( ! F_160 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_473 )
return 1 ;
V_3 -> V_95 . V_447 = V_447 ;
if ( V_84 ) {
if ( ! F_227 ( V_3 ) ) {
V_470 &= ~ V_474 ;
V_470 |= V_475 ;
} else if ( ! ( V_447 & V_474 ) ) {
V_470 &= ~ V_474 ;
}
}
F_76 ( V_410 , V_447 ) ;
F_76 ( V_408 , V_470 ) ;
return 0 ;
}
static void F_237 ( struct V_2 * V_3 ,
struct V_476 * V_477 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_394 * V_395 ;
T_2 V_106 ;
if ( V_58 -> V_115 . V_116
&& ( V_92 == V_478 || V_92 == V_412
|| V_92 == V_414 || V_92 == V_417
|| V_92 == V_416 )
&& ! V_411 ) {
switch ( V_92 ) {
case V_478 : V_395 = & V_58 -> V_115 . V_161 ; break;
case V_412 : V_395 = & V_58 -> V_115 . V_413 ; break;
case V_414 : V_395 = & V_58 -> V_115 . V_415 ; break;
case V_417 : V_395 = & V_58 -> V_115 . V_166 ; break;
case V_416 : V_395 = & V_58 -> V_115 . V_170 ; break;
default: F_238 () ;
}
V_477 -> V_99 = V_395 -> V_99 ;
V_477 -> V_102 = V_395 -> V_102 ;
V_477 -> V_104 = V_395 -> V_104 ;
V_106 = V_395 -> V_106 ;
if ( V_92 == V_478
|| V_477 -> V_99 == F_85 ( V_58 , V_92 ) )
goto V_479;
}
V_477 -> V_102 = F_86 ( V_58 , V_92 ) ;
V_477 -> V_104 = F_87 ( V_58 , V_92 ) ;
V_477 -> V_99 = F_85 ( V_58 , V_92 ) ;
V_106 = F_88 ( V_58 , V_92 ) ;
V_479:
if ( ( V_106 & V_480 ) && ! V_411 )
V_106 = 0 ;
V_477 -> type = V_106 & 15 ;
V_477 -> V_158 = ( V_106 >> 4 ) & 1 ;
V_477 -> V_399 = ( V_106 >> 5 ) & 3 ;
V_477 -> V_481 = ( V_106 >> 7 ) & 1 ;
V_477 -> V_482 = ( V_106 >> 12 ) & 1 ;
V_477 -> V_483 = ( V_106 >> 13 ) & 1 ;
V_477 -> V_484 = ( V_106 >> 14 ) & 1 ;
V_477 -> V_485 = ( V_106 >> 15 ) & 1 ;
V_477 -> V_486 = ( V_106 >> 16 ) & 1 ;
}
static T_5 F_239 ( struct V_2 * V_3 , int V_92 )
{
struct V_476 V_158 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
F_237 ( V_3 , & V_158 , V_92 ) ;
return V_158 . V_102 ;
}
return F_86 ( F_1 ( V_3 ) , V_92 ) ;
}
static int F_240 ( struct V_2 * V_3 )
{
if ( ! F_241 ( V_3 ) )
return 0 ;
if ( ! F_105 ( V_3 )
&& ( F_242 ( V_3 ) & V_215 ) )
return 3 ;
return F_85 ( F_1 ( V_3 ) , V_487 ) & 3 ;
}
static int F_243 ( struct V_2 * V_3 )
{
if ( ! F_133 ( V_213 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_134 ( V_213 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_488 = F_240 ( V_3 ) ;
}
return F_1 ( V_3 ) -> V_488 ;
}
static T_2 F_244 ( struct V_476 * V_477 )
{
T_2 V_106 ;
if ( V_477 -> V_486 )
V_106 = 1 << 16 ;
else {
V_106 = V_477 -> type & 15 ;
V_106 |= ( V_477 -> V_158 & 1 ) << 4 ;
V_106 |= ( V_477 -> V_399 & 3 ) << 5 ;
V_106 |= ( V_477 -> V_481 & 1 ) << 7 ;
V_106 |= ( V_477 -> V_482 & 1 ) << 12 ;
V_106 |= ( V_477 -> V_483 & 1 ) << 13 ;
V_106 |= ( V_477 -> V_484 & 1 ) << 14 ;
V_106 |= ( V_477 -> V_485 & 1 ) << 15 ;
}
if ( V_106 == 0 )
V_106 = V_480 ;
return V_106 ;
}
static void F_245 ( struct V_2 * V_3 ,
struct V_476 * V_477 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_396 * V_397 = & V_101 [ V_92 ] ;
T_2 V_106 ;
F_83 ( V_58 ) ;
if ( V_58 -> V_115 . V_116 && V_92 == V_478 ) {
F_78 ( V_397 -> V_99 , V_477 -> V_99 ) ;
V_58 -> V_115 . V_161 . V_99 = V_477 -> V_99 ;
V_58 -> V_115 . V_161 . V_102 = V_477 -> V_102 ;
V_58 -> V_115 . V_161 . V_104 = V_477 -> V_104 ;
V_58 -> V_115 . V_161 . V_106 = F_244 ( V_477 ) ;
return;
}
F_76 ( V_397 -> V_102 , V_477 -> V_102 ) ;
F_79 ( V_397 -> V_104 , V_477 -> V_104 ) ;
F_78 ( V_397 -> V_99 , V_477 -> V_99 ) ;
if ( V_58 -> V_115 . V_116 && V_477 -> V_158 ) {
if ( V_477 -> V_102 == 0xffff0000 && V_477 -> V_99 == 0xf000 )
F_76 ( V_397 -> V_102 , 0xf0000 ) ;
V_106 = 0xf3 ;
} else
V_106 = F_244 ( V_477 ) ;
if ( V_390 && ( V_92 != V_489 ) )
V_106 |= 0x1 ;
F_79 ( V_397 -> V_108 , V_106 ) ;
F_136 ( V_213 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_246 ( struct V_2 * V_3 , int * V_484 , int * V_483 )
{
T_2 V_106 = F_88 ( F_1 ( V_3 ) , V_487 ) ;
* V_484 = ( V_106 >> 14 ) & 1 ;
* V_483 = ( V_106 >> 13 ) & 1 ;
}
static void F_247 ( struct V_2 * V_3 , struct V_137 * V_490 )
{
V_490 -> V_380 = F_71 ( V_491 ) ;
V_490 -> V_142 = F_69 ( V_492 ) ;
}
static void F_248 ( struct V_2 * V_3 , struct V_137 * V_490 )
{
F_79 ( V_491 , V_490 -> V_380 ) ;
F_76 ( V_492 , V_490 -> V_142 ) ;
}
static void F_249 ( struct V_2 * V_3 , struct V_137 * V_490 )
{
V_490 -> V_380 = F_71 ( V_493 ) ;
V_490 -> V_142 = F_69 ( V_494 ) ;
}
static void F_250 ( struct V_2 * V_3 , struct V_137 * V_490 )
{
F_79 ( V_493 , V_490 -> V_380 ) ;
F_76 ( V_494 , V_490 -> V_142 ) ;
}
static bool F_251 ( struct V_2 * V_3 , int V_92 )
{
struct V_476 V_477 ;
T_2 V_106 ;
F_237 ( V_3 , & V_477 , V_92 ) ;
V_106 = F_244 ( & V_477 ) ;
if ( V_477 . V_102 != ( V_477 . V_99 << 4 ) )
return false ;
if ( V_477 . V_104 != 0xffff )
return false ;
if ( V_106 != 0xf3 )
return false ;
return true ;
}
static bool F_252 ( struct V_2 * V_3 )
{
struct V_476 V_495 ;
unsigned int V_496 ;
F_237 ( V_3 , & V_495 , V_487 ) ;
V_496 = V_495 . V_99 & V_400 ;
if ( V_495 . V_486 )
return false ;
if ( ~ V_495 . type & ( V_497 | V_498 ) )
return false ;
if ( ! V_495 . V_158 )
return false ;
if ( V_495 . type & V_499 ) {
if ( V_495 . V_399 > V_496 )
return false ;
} else {
if ( V_495 . V_399 != V_496 )
return false ;
}
if ( ! V_495 . V_481 )
return false ;
return true ;
}
static bool F_253 ( struct V_2 * V_3 )
{
struct V_476 V_500 ;
unsigned int V_501 ;
F_237 ( V_3 , & V_500 , V_502 ) ;
V_501 = V_500 . V_99 & V_400 ;
if ( V_500 . V_486 )
return true ;
if ( V_500 . type != 3 && V_500 . type != 7 )
return false ;
if ( ! V_500 . V_158 )
return false ;
if ( V_500 . V_399 != V_501 )
return false ;
if ( ! V_500 . V_481 )
return false ;
return true ;
}
static bool F_254 ( struct V_2 * V_3 , int V_92 )
{
struct V_476 V_477 ;
unsigned int V_503 ;
F_237 ( V_3 , & V_477 , V_92 ) ;
V_503 = V_477 . V_99 & V_400 ;
if ( V_477 . V_486 )
return true ;
if ( ! V_477 . V_158 )
return false ;
if ( ! V_477 . V_481 )
return false ;
if ( ~ V_477 . type & ( V_497 | V_499 ) ) {
if ( V_477 . V_399 < V_503 )
return false ;
}
return true ;
}
static bool F_255 ( struct V_2 * V_3 )
{
struct V_476 V_161 ;
F_237 ( V_3 , & V_161 , V_478 ) ;
if ( V_161 . V_486 )
return false ;
if ( V_161 . V_99 & V_504 )
return false ;
if ( V_161 . type != 3 && V_161 . type != 11 )
return false ;
if ( ! V_161 . V_481 )
return false ;
return true ;
}
static bool F_256 ( struct V_2 * V_3 )
{
struct V_476 V_505 ;
F_237 ( V_3 , & V_505 , V_489 ) ;
if ( V_505 . V_486 )
return true ;
if ( V_505 . V_99 & V_504 )
return false ;
if ( V_505 . type != 2 )
return false ;
if ( ! V_505 . V_481 )
return false ;
return true ;
}
static bool F_257 ( struct V_2 * V_3 )
{
struct V_476 V_495 , V_500 ;
F_237 ( V_3 , & V_495 , V_487 ) ;
F_237 ( V_3 , & V_500 , V_502 ) ;
return ( ( V_495 . V_99 & V_400 ) ==
( V_500 . V_99 & V_400 ) ) ;
}
static bool F_258 ( struct V_2 * V_3 )
{
if ( ! F_241 ( V_3 ) ) {
if ( ! F_251 ( V_3 , V_487 ) )
return false ;
if ( ! F_251 ( V_3 , V_502 ) )
return false ;
if ( ! F_251 ( V_3 , V_414 ) )
return false ;
if ( ! F_251 ( V_3 , V_412 ) )
return false ;
if ( ! F_251 ( V_3 , V_417 ) )
return false ;
if ( ! F_251 ( V_3 , V_416 ) )
return false ;
} else {
if ( ! F_257 ( V_3 ) )
return false ;
if ( ! F_252 ( V_3 ) )
return false ;
if ( ! F_253 ( V_3 ) )
return false ;
if ( ! F_254 ( V_3 , V_414 ) )
return false ;
if ( ! F_254 ( V_3 , V_412 ) )
return false ;
if ( ! F_254 ( V_3 , V_417 ) )
return false ;
if ( ! F_254 ( V_3 , V_416 ) )
return false ;
if ( ! F_255 ( V_3 ) )
return false ;
if ( ! F_256 ( V_3 ) )
return false ;
}
return true ;
}
static int F_259 ( struct V_12 * V_12 )
{
T_13 V_506 ;
T_3 V_153 = 0 ;
int V_507 , V_508 , V_93 = 0 ;
V_508 = F_218 ( & V_12 -> V_428 ) ;
V_506 = F_212 ( V_12 ) >> V_13 ;
V_507 = F_260 ( V_12 , V_506 , 0 , V_379 ) ;
if ( V_507 < 0 )
goto V_509;
V_153 = V_510 + V_511 ;
V_507 = F_261 ( V_12 , V_506 ++ , & V_153 ,
V_512 , sizeof( T_3 ) ) ;
if ( V_507 < 0 )
goto V_509;
V_507 = F_260 ( V_12 , V_506 ++ , 0 , V_379 ) ;
if ( V_507 < 0 )
goto V_509;
V_507 = F_260 ( V_12 , V_506 , 0 , V_379 ) ;
if ( V_507 < 0 )
goto V_509;
V_153 = ~ 0 ;
V_507 = F_261 ( V_12 , V_506 , & V_153 ,
V_430 - 2 * V_379 - 1 ,
sizeof( T_6 ) ) ;
if ( V_507 < 0 )
goto V_509;
V_93 = 1 ;
V_509:
F_216 ( & V_12 -> V_428 , V_508 ) ;
return V_93 ;
}
static int F_262 ( struct V_12 * V_12 )
{
int V_60 , V_508 , V_507 , V_93 ;
T_14 V_513 ;
T_2 V_243 ;
if ( ! V_84 )
return 1 ;
if ( F_77 ( ! V_12 -> V_95 . V_514 ) ) {
F_54 ( V_74 L_12
L_13 ) ;
return 0 ;
}
if ( F_263 ( V_12 -> V_95 . V_515 ) )
return 1 ;
V_93 = 0 ;
V_513 = V_12 -> V_95 . V_469 >> V_13 ;
V_508 = F_218 ( & V_12 -> V_428 ) ;
V_507 = F_260 ( V_12 , V_513 , 0 , V_379 ) ;
if ( V_507 < 0 )
goto V_509;
for ( V_60 = 0 ; V_60 < V_516 ; V_60 ++ ) {
V_243 = ( V_60 << 22 ) + ( V_517 | V_518 | V_519 |
V_520 | V_521 | V_522 ) ;
V_507 = F_261 ( V_12 , V_513 ,
& V_243 , V_60 * sizeof( V_243 ) , sizeof( V_243 ) ) ;
if ( V_507 < 0 )
goto V_509;
}
V_12 -> V_95 . V_515 = true ;
V_93 = 1 ;
V_509:
F_216 ( & V_12 -> V_428 , V_508 ) ;
return V_93 ;
}
static void F_264 ( int V_92 )
{
struct V_396 * V_397 = & V_101 [ V_92 ] ;
unsigned int V_106 ;
F_78 ( V_397 -> V_99 , 0 ) ;
F_76 ( V_397 -> V_102 , 0 ) ;
F_79 ( V_397 -> V_104 , 0xffff ) ;
if ( V_390 ) {
V_106 = 0x93 ;
if ( V_92 == V_487 )
V_106 |= 0x08 ;
} else
V_106 = 0xf3 ;
F_79 ( V_397 -> V_108 , V_106 ) ;
}
static int F_265 ( struct V_12 * V_12 )
{
struct V_523 V_524 ;
int V_507 = 0 ;
F_266 ( & V_12 -> V_525 ) ;
if ( V_12 -> V_95 . V_526 )
goto V_509;
V_524 . V_527 = V_528 ;
V_524 . V_402 = 0 ;
V_524 . V_529 = 0xfee00000ULL ;
V_524 . V_530 = V_379 ;
V_507 = F_267 ( V_12 , & V_524 , 0 ) ;
if ( V_507 )
goto V_509;
V_12 -> V_95 . V_526 = F_6 ( V_12 , 0xfee00 ) ;
V_509:
F_268 ( & V_12 -> V_525 ) ;
return V_507 ;
}
static int F_269 ( struct V_12 * V_12 )
{
struct V_523 V_524 ;
int V_507 = 0 ;
F_266 ( & V_12 -> V_525 ) ;
if ( V_12 -> V_95 . V_514 )
goto V_509;
V_524 . V_527 = V_531 ;
V_524 . V_402 = 0 ;
V_524 . V_529 =
V_12 -> V_95 . V_469 ;
V_524 . V_530 = V_379 ;
V_507 = F_267 ( V_12 , & V_524 , 0 ) ;
if ( V_507 )
goto V_509;
V_12 -> V_95 . V_514 = F_6 ( V_12 ,
V_12 -> V_95 . V_469 >> V_13 ) ;
V_509:
F_268 ( & V_12 -> V_525 ) ;
return V_507 ;
}
static void F_270 ( struct V_1 * V_58 )
{
int V_42 ;
V_58 -> V_42 = 0 ;
if ( ! V_389 )
return;
F_271 ( & V_532 ) ;
V_42 = F_272 ( V_533 , V_534 ) ;
if ( V_42 < V_534 ) {
V_58 -> V_42 = V_42 ;
F_134 ( V_42 , V_533 ) ;
}
F_273 ( & V_532 ) ;
}
static void F_274 ( struct V_1 * V_58 )
{
if ( ! V_389 )
return;
F_271 ( & V_532 ) ;
if ( V_58 -> V_42 != 0 )
F_136 ( V_58 -> V_42 , V_533 ) ;
F_273 ( & V_532 ) ;
}
static void F_275 ( unsigned long * V_244 , T_2 V_59 )
{
int V_535 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_59 <= 0x1fff ) {
F_136 ( V_59 , V_244 + 0x000 / V_535 ) ;
F_136 ( V_59 , V_244 + 0x800 / V_535 ) ;
} else if ( ( V_59 >= 0xc0000000 ) && ( V_59 <= 0xc0001fff ) ) {
V_59 &= 0x1fff ;
F_136 ( V_59 , V_244 + 0x400 / V_535 ) ;
F_136 ( V_59 , V_244 + 0xc00 / V_535 ) ;
}
}
static void F_276 ( T_2 V_59 , bool V_536 )
{
if ( ! V_536 )
F_275 ( V_252 , V_59 ) ;
F_275 ( V_251 , V_59 ) ;
}
static void F_277 ( void )
{
T_2 V_537 , V_538 ;
unsigned long V_539 ;
struct V_137 V_490 ;
F_76 ( V_540 , F_278 () | V_196 ) ;
F_76 ( V_541 , F_183 () ) ;
F_76 ( V_542 , F_279 () ) ;
F_78 ( V_543 , V_544 ) ;
F_78 ( V_545 , V_546 ) ;
F_78 ( V_547 , V_546 ) ;
F_78 ( V_548 , V_546 ) ;
F_78 ( V_549 , V_143 * 8 ) ;
F_280 ( & V_490 ) ;
F_76 ( V_550 , V_490 . V_142 ) ;
asm("mov $.Lkvm_vmx_return, %0" : "=r"(tmpl));
F_76 ( V_551 , V_539 ) ;
F_162 ( V_327 , V_537 , V_538 ) ;
F_79 ( V_552 , V_537 ) ;
F_104 ( V_329 , V_539 ) ;
F_76 ( V_553 , V_539 ) ;
if ( V_24 . V_383 & V_378 ) {
F_162 ( V_332 , V_537 , V_538 ) ;
F_80 ( V_554 , V_537 | ( ( T_5 ) V_538 << 32 ) ) ;
}
}
static void F_281 ( struct V_1 * V_58 )
{
V_58 -> V_3 . V_95 . V_446 = V_555 ;
if ( V_84 )
V_58 -> V_3 . V_95 . V_446 |= V_556 ;
if ( F_90 ( & V_58 -> V_3 ) )
V_58 -> V_3 . V_95 . V_446 &=
~ F_4 ( & V_58 -> V_3 ) -> V_205 ;
F_76 ( V_557 , ~ V_58 -> V_3 . V_95 . V_446 ) ;
}
static T_2 F_282 ( struct V_1 * V_58 )
{
T_2 V_558 = V_24 . V_25 ;
if ( ! F_19 ( V_58 -> V_3 . V_12 ) ) {
V_558 &= ~ V_27 ;
#ifdef F_73
V_558 |= V_289 |
V_288 ;
#endif
}
if ( ! V_84 )
V_558 |= V_287 |
V_286 |
V_284 ;
return V_558 ;
}
static T_2 F_283 ( struct V_1 * V_58 )
{
T_2 V_558 = V_24 . V_29 ;
if ( ! F_38 ( V_58 -> V_3 . V_12 ) )
V_558 &= ~ V_30 ;
if ( V_58 -> V_42 == 0 )
V_558 &= ~ V_49 ;
if ( ! V_84 ) {
V_558 &= ~ V_45 ;
V_390 = 0 ;
}
if ( ! V_390 )
V_558 &= ~ V_46 ;
if ( ! V_393 )
V_558 &= ~ V_47 ;
return V_558 ;
}
static void F_284 ( void )
{
F_285 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_286 ( struct V_1 * V_58 )
{
#ifdef F_73
unsigned long V_559 ;
#endif
int V_60 ;
F_80 ( V_560 , F_53 ( V_561 ) ) ;
F_80 ( V_562 , F_53 ( V_563 ) ) ;
if ( F_17 () )
F_80 ( V_253 , F_53 ( V_252 ) ) ;
F_80 ( V_564 , - 1ull ) ;
F_79 ( V_565 ,
V_24 . V_51 ) ;
F_79 ( V_456 , F_282 ( V_58 ) ) ;
if ( F_21 () ) {
F_79 ( V_566 ,
F_283 ( V_58 ) ) ;
}
if ( V_393 ) {
F_79 ( V_567 , V_393 ) ;
F_79 ( V_568 , V_569 ) ;
}
F_79 ( V_570 , 0 ) ;
F_79 ( V_571 , 0 ) ;
F_79 ( V_572 , 0 ) ;
F_78 ( V_168 , 0 ) ;
F_78 ( V_172 , 0 ) ;
F_277 () ;
#ifdef F_73
F_104 ( V_174 , V_559 ) ;
F_76 ( V_173 , V_559 ) ;
F_104 ( V_176 , V_559 ) ;
F_76 ( V_175 , V_559 ) ;
#else
F_76 ( V_173 , 0 ) ;
F_76 ( V_175 , 0 ) ;
#endif
F_79 ( V_573 , 0 ) ;
F_79 ( V_132 , 0 ) ;
F_80 ( V_574 , F_53 ( V_58 -> V_120 . V_130 ) ) ;
F_79 ( V_131 , 0 ) ;
F_80 ( V_575 , F_53 ( V_58 -> V_120 . V_129 ) ) ;
if ( V_24 . V_333 & V_276 ) {
T_2 V_576 , V_577 ;
T_5 V_578 ;
F_162 ( V_332 , V_576 , V_577 ) ;
V_578 = V_576 | ( ( T_5 ) V_577 << 32 ) ;
F_80 ( V_334 , V_578 ) ;
V_58 -> V_3 . V_95 . V_335 = V_578 ;
}
for ( V_60 = 0 ; V_60 < V_579 ; ++ V_60 ) {
T_2 V_64 = V_62 [ V_60 ] ;
T_2 V_580 , V_581 ;
int V_582 = V_58 -> V_61 ;
if ( F_287 ( V_64 , & V_580 , & V_581 ) < 0 )
continue;
if ( F_288 ( V_64 , V_580 , V_581 ) < 0 )
continue;
V_58 -> V_63 [ V_582 ] . V_64 = V_60 ;
V_58 -> V_63 [ V_582 ] . V_153 = 0 ;
V_58 -> V_63 [ V_582 ] . V_89 = - 1ull ;
++ V_58 -> V_61 ;
}
F_79 ( V_126 , V_24 . V_383 ) ;
F_79 ( V_124 , V_24 . V_333 ) ;
F_76 ( V_200 , ~ 0UL ) ;
F_281 ( V_58 ) ;
F_174 ( & V_58 -> V_3 , 0 ) ;
return 0 ;
}
static int F_289 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_5 V_59 ;
int V_93 ;
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_341 ) | ( 1 << V_338 ) ) ;
V_58 -> V_115 . V_116 = 0 ;
V_58 -> V_583 = 0 ;
V_58 -> V_3 . V_95 . V_339 [ V_584 ] = F_290 () ;
F_291 ( & V_58 -> V_3 , 0 ) ;
V_59 = 0xfee00000 | V_585 ;
if ( F_292 ( & V_58 -> V_3 ) )
V_59 |= V_586 ;
F_293 ( & V_58 -> V_3 , V_59 ) ;
V_93 = F_294 ( & V_58 -> V_3 ) ;
if ( V_93 != 0 )
goto V_509;
F_83 ( V_58 ) ;
F_264 ( V_487 ) ;
if ( F_292 ( & V_58 -> V_3 ) ) {
F_78 ( V_420 , 0xf000 ) ;
F_76 ( V_435 , 0x000f0000 ) ;
} else {
F_78 ( V_420 , V_58 -> V_3 . V_95 . V_587 << 8 ) ;
F_76 ( V_435 , V_58 -> V_3 . V_95 . V_587 << 12 ) ;
}
F_264 ( V_414 ) ;
F_264 ( V_412 ) ;
F_264 ( V_417 ) ;
F_264 ( V_416 ) ;
F_264 ( V_502 ) ;
F_78 ( V_404 , 0 ) ;
F_76 ( V_405 , 0 ) ;
F_79 ( V_406 , 0xffff ) ;
F_79 ( V_407 , 0x008b ) ;
F_78 ( V_588 , 0 ) ;
F_76 ( V_589 , 0 ) ;
F_79 ( V_590 , 0xffff ) ;
F_79 ( V_591 , 0x00082 ) ;
F_79 ( V_328 , 0 ) ;
F_76 ( V_331 , 0 ) ;
F_76 ( V_330 , 0 ) ;
F_76 ( V_211 , 0x02 ) ;
if ( F_292 ( & V_58 -> V_3 ) )
F_141 ( V_3 , 0xfff0 ) ;
else
F_141 ( V_3 , 0 ) ;
F_295 ( V_3 , V_338 , 0 ) ;
F_76 ( V_347 , 0x400 ) ;
F_76 ( V_494 , 0 ) ;
F_79 ( V_493 , 0xffff ) ;
F_76 ( V_492 , 0 ) ;
F_79 ( V_491 , 0xffff ) ;
F_79 ( V_226 , V_228 ) ;
F_79 ( V_217 , 0 ) ;
F_79 ( V_592 , 0 ) ;
F_80 ( V_593 , 0 ) ;
F_150 ( V_58 ) ;
F_79 ( V_240 , 0 ) ;
if ( F_18 () ) {
F_80 ( V_594 , 0 ) ;
if ( F_19 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_594 ,
F_53 ( V_58 -> V_3 . V_95 . V_595 -> V_339 ) ) ;
F_79 ( V_596 , 0 ) ;
}
if ( F_38 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_597 ,
F_296 ( V_58 -> V_3 . V_12 -> V_95 . V_526 ) ) ;
if ( V_58 -> V_42 != 0 )
F_78 ( V_598 , V_58 -> V_42 ) ;
V_58 -> V_3 . V_95 . V_194 = V_599 | V_600 | V_601 ;
F_234 ( & V_58 -> V_3 , F_297 ( V_3 ) ) ;
F_232 ( & V_58 -> V_3 , 0 ) ;
F_220 ( & V_58 -> V_3 , 0 ) ;
F_126 ( & V_58 -> V_3 ) ;
F_89 ( & V_58 -> V_3 ) ;
F_65 ( V_58 ) ;
V_93 = 0 ;
V_58 -> V_403 = 0 ;
V_509:
return V_93 ;
}
static bool F_298 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_57 &
V_268 ;
}
static void F_299 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( F_90 ( V_3 ) && F_298 ( V_3 ) )
return;
V_55 = F_71 ( V_456 ) ;
V_55 |= V_281 ;
F_79 ( V_456 , V_55 ) ;
}
static void F_300 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( ! F_41 () ) {
F_299 ( V_3 ) ;
return;
}
if ( F_71 ( V_217 ) & V_218 ) {
F_299 ( V_3 ) ;
return;
}
V_55 = F_71 ( V_456 ) ;
V_55 |= V_602 ;
F_79 ( V_456 , V_55 ) ;
}
static void F_301 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_15 V_603 ;
int V_604 = V_3 -> V_95 . V_605 . V_128 ;
F_302 ( V_604 ) ;
++ V_3 -> V_181 . V_606 ;
if ( V_58 -> V_115 . V_116 ) {
int V_234 = 0 ;
if ( V_3 -> V_95 . V_605 . V_607 )
V_234 = V_3 -> V_95 . V_235 ;
if ( F_147 ( V_3 , V_604 , V_234 ) != V_236 )
F_120 ( V_237 , V_3 ) ;
return;
}
V_603 = V_604 | V_17 ;
if ( V_3 -> V_95 . V_605 . V_607 ) {
V_603 |= V_608 ;
F_79 ( V_238 ,
V_58 -> V_3 . V_95 . V_235 ) ;
} else
V_603 |= V_22 ;
F_79 ( V_240 , V_603 ) ;
F_142 ( V_3 ) ;
}
static void F_303 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) )
return;
if ( ! F_41 () ) {
V_58 -> V_583 = 1 ;
V_58 -> V_609 = 0 ;
}
++ V_3 -> V_181 . V_610 ;
V_58 -> V_611 = false ;
if ( V_58 -> V_115 . V_116 ) {
if ( F_147 ( V_3 , V_612 , 0 ) != V_236 )
F_120 ( V_237 , V_3 ) ;
return;
}
F_79 ( V_240 ,
V_613 | V_17 | V_612 ) ;
F_142 ( V_3 ) ;
}
static int F_304 ( struct V_2 * V_3 )
{
if ( ! F_41 () && F_1 ( V_3 ) -> V_583 )
return 0 ;
return ! ( F_71 ( V_217 ) &
( V_220 | V_218
| V_614 ) ) ;
}
static bool F_305 ( struct V_2 * V_3 )
{
if ( ! F_41 () )
return F_1 ( V_3 ) -> V_583 ;
if ( F_1 ( V_3 ) -> V_611 )
return false ;
return F_71 ( V_217 ) & V_614 ;
}
static void F_306 ( struct V_2 * V_3 , bool V_615 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_41 () ) {
if ( V_58 -> V_583 != V_615 ) {
V_58 -> V_583 = V_615 ;
V_58 -> V_609 = 0 ;
}
} else {
V_58 -> V_611 = ! V_615 ;
if ( V_615 )
F_82 ( V_217 ,
V_614 ) ;
else
F_81 ( V_217 ,
V_614 ) ;
}
}
static int F_307 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) && F_298 ( V_3 ) ) {
struct V_7 * V_7 ;
if ( F_1 ( V_3 ) -> V_8 . V_616 )
return 0 ;
F_144 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
V_7 -> V_617 = V_618 ;
V_7 -> V_619 = 0 ;
}
return ( F_69 ( V_211 ) & V_620 ) &&
! ( F_71 ( V_217 ) &
( V_218 | V_220 ) ) ;
}
static int F_217 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_93 ;
struct V_523 V_621 = {
. V_527 = V_622 ,
. V_529 = V_11 ,
. V_530 = V_379 * 3 ,
. V_402 = 0 ,
} ;
V_93 = F_308 ( V_12 , & V_621 , 0 ) ;
if ( V_93 )
return V_93 ;
V_12 -> V_95 . V_422 = V_11 ;
if ( ! F_259 ( V_12 ) )
return - V_387 ;
return 0 ;
}
static int F_309 ( struct V_2 * V_3 ,
int V_623 , T_2 V_624 )
{
if ( ( ( V_623 == V_304 ) || ( V_623 == V_625 ) ) && V_624 == 0 )
if ( F_310 ( V_3 , 0 ) == V_236 )
return 1 ;
switch ( V_623 ) {
case V_110 :
if ( V_3 -> V_111 &
( V_626 | V_346 ) )
return 0 ;
F_311 ( V_3 , V_623 ) ;
return 1 ;
case V_114 :
F_1 ( V_3 ) -> V_3 . V_95 . V_235 =
F_71 ( V_224 ) ;
if ( V_3 -> V_111 & V_113 )
return 0 ;
case V_627 :
case V_628 :
case V_629 :
case V_21 :
case V_630 :
case V_625 :
case V_304 :
case V_631 :
F_311 ( V_3 , V_623 ) ;
return 1 ;
}
return 0 ;
}
static void F_312 ( void )
{
#if F_313 ( V_632 ) && F_313 ( F_73 )
struct V_633 V_339 = {
. V_495 = 3 ,
. V_402 = V_620 ,
} ;
F_314 ( & V_339 , 0 ) ;
#endif
}
static int F_315 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_316 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_634 * V_634 = V_3 -> V_635 ;
T_2 V_14 , V_636 , V_230 ;
unsigned long V_637 , V_223 , V_638 ;
T_2 V_639 ;
enum V_640 V_641 ;
V_639 = V_58 -> V_642 ;
V_14 = V_58 -> V_643 ;
if ( F_16 ( V_14 ) )
return F_315 ( V_3 ) ;
if ( ( V_639 & V_644 ) &&
! F_12 ( V_14 ) ) {
V_3 -> V_635 -> V_645 = V_646 ;
V_3 -> V_635 -> V_647 . V_648 = V_649 ;
V_3 -> V_635 -> V_647 . V_650 = 2 ;
V_3 -> V_635 -> V_647 . V_153 [ 0 ] = V_639 ;
V_3 -> V_635 -> V_647 . V_153 [ 1 ] = V_14 ;
return 0 ;
}
if ( ( V_14 & V_15 ) == V_613 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_126 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_641 = F_310 ( V_3 , V_651 ) ;
if ( V_641 != V_236 )
F_311 ( V_3 , V_21 ) ;
return 1 ;
}
V_230 = 0 ;
if ( V_14 & V_233 )
V_230 = F_71 ( V_652 ) ;
if ( F_12 ( V_14 ) ) {
if ( V_84 )
F_238 () ;
V_637 = F_69 ( V_653 ) ;
F_317 ( V_637 , V_230 ) ;
if ( F_318 ( V_3 ) )
F_319 ( V_3 , V_637 ) ;
return F_320 ( V_3 , V_637 , V_230 , NULL , 0 ) ;
}
if ( V_58 -> V_115 . V_116 &&
F_309 ( V_3 , V_14 & V_16 ,
V_230 ) ) {
if ( V_3 -> V_95 . V_654 ) {
V_3 -> V_95 . V_654 = 0 ;
return F_321 ( V_3 ) ;
}
return 1 ;
}
V_636 = V_14 & V_16 ;
switch ( V_636 ) {
case V_110 :
V_638 = F_69 ( V_653 ) ;
if ( ! ( V_3 -> V_111 &
( V_626 | V_346 ) ) ) {
V_3 -> V_95 . V_638 = V_638 | V_655 ;
F_311 ( V_3 , V_110 ) ;
return 1 ;
}
V_634 -> V_656 . V_95 . V_638 = V_638 | V_655 ;
V_634 -> V_656 . V_95 . V_349 = F_69 ( V_347 ) ;
case V_114 :
V_58 -> V_3 . V_95 . V_235 =
F_71 ( V_224 ) ;
V_634 -> V_645 = V_657 ;
V_223 = F_140 ( V_3 ) ;
V_634 -> V_656 . V_95 . V_658 = F_69 ( V_435 ) + V_223 ;
V_634 -> V_656 . V_95 . V_659 = V_636 ;
break;
default:
V_634 -> V_645 = V_660 ;
V_634 -> V_661 . V_659 = V_636 ;
V_634 -> V_661 . V_230 = V_230 ;
break;
}
return 0 ;
}
static int F_322 ( struct V_2 * V_3 )
{
++ V_3 -> V_181 . V_662 ;
return 1 ;
}
static int F_323 ( struct V_2 * V_3 )
{
V_3 -> V_635 -> V_645 = V_663 ;
return 0 ;
}
static int F_324 ( struct V_2 * V_3 )
{
unsigned long V_664 ;
int V_380 , V_665 , string ;
unsigned V_666 ;
V_664 = F_69 ( V_653 ) ;
string = ( V_664 & 16 ) != 0 ;
V_665 = ( V_664 & 8 ) != 0 ;
++ V_3 -> V_181 . V_667 ;
if ( string || V_665 )
return F_310 ( V_3 , 0 ) == V_236 ;
V_666 = V_664 >> 16 ;
V_380 = ( V_664 & 7 ) + 1 ;
F_139 ( V_3 ) ;
return F_325 ( V_3 , V_380 , V_666 ) ;
}
static void
F_326 ( struct V_2 * V_3 , unsigned char * V_668 )
{
V_668 [ 0 ] = 0x0f ;
V_668 [ 1 ] = 0x01 ;
V_668 [ 2 ] = 0xc1 ;
}
static int F_327 ( struct V_2 * V_3 , unsigned long V_669 )
{
if ( F_1 ( V_3 ) -> V_8 . V_473 &&
( ( V_669 & F_167 ) != F_167 ) )
return 1 ;
if ( F_90 ( V_3 ) ) {
if ( F_328 ( V_3 , ( V_669 & V_3 -> V_95 . V_198 ) |
( V_3 -> V_95 . V_194 & ~ V_3 -> V_95 . V_198 ) ) )
return 1 ;
F_76 ( V_207 , V_669 ) ;
return 0 ;
} else
return F_328 ( V_3 , V_669 ) ;
}
static int F_329 ( struct V_2 * V_3 , unsigned long V_669 )
{
if ( F_90 ( V_3 ) ) {
if ( F_330 ( V_3 , ( V_669 & V_3 -> V_95 . V_446 ) |
( V_3 -> V_95 . V_447 & ~ V_3 -> V_95 . V_446 ) ) )
return 1 ;
F_76 ( V_410 , V_669 ) ;
return 0 ;
} else
return F_330 ( V_3 , V_669 ) ;
}
static void F_331 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) ) {
F_76 ( V_207 ,
F_69 ( V_207 ) & ~ V_196 ) ;
V_3 -> V_95 . V_194 &= ~ V_196 ;
} else
F_234 ( V_3 , F_127 ( V_3 , ~ V_196 ) ) ;
}
static int F_332 ( struct V_2 * V_3 )
{
unsigned long V_664 , V_669 ;
int V_670 ;
int V_337 ;
int V_671 ;
V_664 = F_69 ( V_653 ) ;
V_670 = V_664 & 15 ;
V_337 = ( V_664 >> 8 ) & 15 ;
switch ( ( V_664 >> 4 ) & 3 ) {
case 0 :
V_669 = F_333 ( V_3 , V_337 ) ;
F_334 ( V_670 , V_669 ) ;
switch ( V_670 ) {
case 0 :
V_671 = F_327 ( V_3 , V_669 ) ;
F_335 ( V_3 , V_671 ) ;
return 1 ;
case 3 :
V_671 = F_336 ( V_3 , V_669 ) ;
F_335 ( V_3 , V_671 ) ;
return 1 ;
case 4 :
V_671 = F_329 ( V_3 , V_669 ) ;
F_335 ( V_3 , V_671 ) ;
return 1 ;
case 8 : {
T_6 V_672 = F_337 ( V_3 ) ;
T_6 V_673 = F_333 ( V_3 , V_337 ) ;
V_671 = F_291 ( V_3 , V_673 ) ;
F_335 ( V_3 , V_671 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_672 <= V_673 )
return 1 ;
V_3 -> V_635 -> V_645 = V_674 ;
return 0 ;
}
} ;
break;
case 2 :
F_331 ( V_3 ) ;
F_334 ( 0 , F_297 ( V_3 ) ) ;
F_139 ( V_3 ) ;
F_126 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_670 ) {
case 3 :
V_669 = F_236 ( V_3 ) ;
F_295 ( V_3 , V_337 , V_669 ) ;
F_338 ( V_670 , V_669 ) ;
F_139 ( V_3 ) ;
return 1 ;
case 8 :
V_669 = F_337 ( V_3 ) ;
F_295 ( V_3 , V_337 , V_669 ) ;
F_338 ( V_670 , V_669 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_669 = ( V_664 >> V_675 ) & 0x0f ;
F_334 ( 0 , ( F_297 ( V_3 ) & ~ 0xful ) | V_669 ) ;
F_339 ( V_3 , V_669 ) ;
F_139 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_635 -> V_645 = 0 ;
F_340 ( V_3 , L_14 ,
( int ) ( V_664 >> 4 ) & 3 , V_670 ) ;
return 0 ;
}
static int F_341 ( struct V_2 * V_3 )
{
unsigned long V_664 ;
int V_676 , V_337 ;
if ( ! F_342 ( V_3 , 0 ) )
return 1 ;
V_676 = F_69 ( V_347 ) ;
if ( V_676 & V_677 ) {
if ( V_3 -> V_111 & V_346 ) {
V_3 -> V_635 -> V_656 . V_95 . V_638 = V_3 -> V_95 . V_638 ;
V_3 -> V_635 -> V_656 . V_95 . V_349 = V_676 ;
V_3 -> V_635 -> V_656 . V_95 . V_658 =
F_69 ( V_435 ) +
F_69 ( V_342 ) ;
V_3 -> V_635 -> V_656 . V_95 . V_659 = V_110 ;
V_3 -> V_635 -> V_645 = V_657 ;
return 0 ;
} else {
V_3 -> V_95 . V_349 &= ~ V_677 ;
V_3 -> V_95 . V_638 |= V_678 ;
F_76 ( V_347 , V_3 -> V_95 . V_349 ) ;
F_311 ( V_3 , V_110 ) ;
return 1 ;
}
}
V_664 = F_69 ( V_653 ) ;
V_676 = V_664 & V_679 ;
V_337 = F_343 ( V_664 ) ;
if ( V_664 & V_680 ) {
unsigned long V_669 ;
if ( ! F_344 ( V_3 , V_676 , & V_669 ) )
F_295 ( V_3 , V_337 , V_669 ) ;
} else
F_345 ( V_3 , V_676 , V_3 -> V_95 . V_339 [ V_337 ] ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static void F_346 ( struct V_2 * V_3 , unsigned long V_669 )
{
F_76 ( V_347 , V_669 ) ;
}
static int F_347 ( struct V_2 * V_3 )
{
F_348 ( V_3 ) ;
return 1 ;
}
static int F_349 ( struct V_2 * V_3 )
{
T_2 V_264 = V_3 -> V_95 . V_339 [ V_681 ] ;
T_5 V_153 ;
if ( F_170 ( V_3 , V_264 , & V_153 ) ) {
F_350 ( V_264 ) ;
F_351 ( V_3 , 0 ) ;
return 1 ;
}
F_352 ( V_264 , V_153 ) ;
V_3 -> V_95 . V_339 [ V_682 ] = V_153 & - 1u ;
V_3 -> V_95 . V_339 [ V_584 ] = ( V_153 >> 32 ) & - 1u ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_353 ( struct V_2 * V_3 )
{
T_2 V_264 = V_3 -> V_95 . V_339 [ V_681 ] ;
T_5 V_153 = ( V_3 -> V_95 . V_339 [ V_682 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_95 . V_339 [ V_584 ] & - 1u ) << 32 ) ;
if ( F_172 ( V_3 , V_264 , V_153 ) != 0 ) {
F_354 ( V_264 , V_153 ) ;
F_351 ( V_3 , 0 ) ;
return 1 ;
}
F_355 ( V_264 , V_153 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_356 ( struct V_2 * V_3 )
{
F_120 ( V_683 , V_3 ) ;
return 1 ;
}
static int F_357 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_456 ) ;
V_55 &= ~ V_281 ;
F_79 ( V_456 , V_55 ) ;
F_120 ( V_683 , V_3 ) ;
++ V_3 -> V_181 . V_684 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_635 -> V_685 &&
! F_358 ( V_3 ) ) {
V_3 -> V_635 -> V_645 = V_686 ;
return 0 ;
}
return 1 ;
}
static int F_359 ( struct V_2 * V_3 )
{
F_139 ( V_3 ) ;
return F_321 ( V_3 ) ;
}
static int F_360 ( struct V_2 * V_3 )
{
F_139 ( V_3 ) ;
F_361 ( V_3 ) ;
return 1 ;
}
static int F_362 ( struct V_2 * V_3 )
{
return F_310 ( V_3 , 0 ) == V_236 ;
}
static int F_363 ( struct V_2 * V_3 )
{
unsigned long V_664 = F_69 ( V_653 ) ;
F_364 ( V_3 , V_664 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_365 ( struct V_2 * V_3 )
{
F_139 ( V_3 ) ;
F_366 ( V_3 ) ;
return 1 ;
}
static int F_367 ( struct V_2 * V_3 )
{
T_5 V_687 = F_368 ( V_3 ) ;
T_2 V_64 = F_333 ( V_3 , V_681 ) ;
if ( F_369 ( V_3 , V_64 , V_687 ) == 0 )
F_139 ( V_3 ) ;
return 1 ;
}
static int F_370 ( struct V_2 * V_3 )
{
return F_310 ( V_3 , 0 ) == V_236 ;
}
static int F_371 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_664 ;
bool V_229 = false ;
T_2 V_230 = 0 ;
T_3 V_688 ;
int V_689 , type , V_690 ;
V_690 = ( V_58 -> V_642 & V_644 ) ;
type = ( V_58 -> V_642 & V_691 ) ;
V_664 = F_69 ( V_653 ) ;
V_689 = ( T_2 ) V_664 >> 30 ;
if ( V_689 == V_692 && V_690 ) {
switch ( type ) {
case V_613 :
V_3 -> V_95 . V_693 = false ;
F_306 ( V_3 , true ) ;
break;
case V_22 :
case V_608 :
F_372 ( V_3 ) ;
break;
case V_18 :
if ( V_58 -> V_642 &
V_694 ) {
V_229 = true ;
V_230 =
F_71 ( V_695 ) ;
}
case V_239 :
F_373 ( V_3 ) ;
break;
default:
break;
}
}
V_688 = V_664 ;
if ( ! V_690 || ( type != V_18 &&
type != V_22 &&
type != V_613 ) )
F_139 ( V_3 ) ;
if ( F_374 ( V_3 , V_688 , V_689 ,
V_229 , V_230 ) == V_696 ) {
V_3 -> V_635 -> V_645 = V_646 ;
V_3 -> V_635 -> V_647 . V_648 = V_697 ;
V_3 -> V_635 -> V_647 . V_650 = 0 ;
return 0 ;
}
F_76 ( V_347 , F_69 ( V_347 ) & ~ 55 ) ;
return 1 ;
}
static int F_375 ( struct V_2 * V_3 )
{
unsigned long V_664 ;
T_1 V_70 ;
int V_698 ;
V_664 = F_69 ( V_653 ) ;
if ( V_664 & ( 1 << 6 ) ) {
F_54 ( V_74 L_15 ) ;
return - V_323 ;
}
V_698 = ( V_664 >> 7 ) & 0x3 ;
if ( V_698 != 0x3 && V_698 != 0x1 && V_698 != 0 ) {
F_54 ( V_74 L_16 ) ;
F_54 ( V_74 L_17 ,
( long unsigned int ) F_72 ( V_699 ) ,
F_69 ( V_700 ) ) ;
F_54 ( V_74 L_18 ,
( long unsigned int ) V_664 ) ;
V_3 -> V_635 -> V_645 = V_701 ;
V_3 -> V_635 -> V_702 . V_703 = V_704 ;
return 0 ;
}
V_70 = F_72 ( V_699 ) ;
F_317 ( V_70 , V_664 ) ;
return F_320 ( V_3 , V_70 , V_664 & 0x3 , NULL , 0 ) ;
}
static T_5 F_376 ( T_5 V_705 , int V_706 )
{
int V_60 ;
T_5 V_89 = 0 ;
for ( V_60 = 51 ; V_60 > V_707 . V_708 ; V_60 -- )
V_89 |= ( 1ULL << V_60 ) ;
if ( V_706 > 2 )
V_89 |= 0xf8 ;
else if ( V_706 == 2 ) {
if ( V_705 & ( 1ULL << 7 ) )
V_89 |= 0x1ff000 ;
else
V_89 |= 0x78 ;
}
return V_89 ;
}
static void F_377 ( struct V_2 * V_3 , T_5 V_705 ,
int V_706 )
{
F_54 ( V_74 L_19 , V_440 , V_705 , V_706 ) ;
F_378 ( ( V_705 & 0x7 ) == 0x2 ) ;
F_378 ( ( V_705 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_378 ( ( V_705 & 0x7 ) == 0x4 ) ;
if ( ( V_705 & 0x7 ) ) {
T_5 V_709 = V_705 & F_376 ( V_705 , V_706 ) ;
if ( V_709 != 0 ) {
F_54 ( V_74 L_20 ,
V_440 , V_709 ) ;
F_378 ( 1 ) ;
}
if ( V_706 == 1 || ( V_706 == 2 && ( V_705 & ( 1ULL << 7 ) ) ) ) {
T_5 V_710 = ( V_705 & 0x38 ) >> 3 ;
if ( V_710 == 2 || V_710 == 3 ||
V_710 == 7 ) {
F_54 ( V_74 L_21 ,
V_440 , V_710 ) ;
F_378 ( 1 ) ;
}
}
}
}
static int F_379 ( struct V_2 * V_3 )
{
T_5 V_711 [ 4 ] ;
int V_712 , V_60 , V_93 ;
T_1 V_70 ;
V_70 = F_72 ( V_699 ) ;
V_93 = F_380 ( V_3 , V_70 , true ) ;
if ( F_263 ( V_93 == 1 ) )
return F_381 ( V_3 , V_70 , 0 , NULL , 0 ) ==
V_236 ;
if ( F_77 ( ! V_93 ) )
return 1 ;
F_54 ( V_74 L_22 ) ;
F_54 ( V_74 L_23 , V_70 ) ;
V_712 = F_382 ( V_3 , V_70 , V_711 ) ;
for ( V_60 = V_713 ; V_60 > V_713 - V_712 ; -- V_60 )
F_377 ( V_3 , V_711 [ V_60 - 1 ] , V_60 ) ;
V_3 -> V_635 -> V_645 = V_701 ;
V_3 -> V_635 -> V_702 . V_703 = V_714 ;
return 0 ;
}
static int F_383 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_456 ) ;
V_55 &= ~ V_602 ;
F_79 ( V_456 , V_55 ) ;
++ V_3 -> V_181 . V_715 ;
F_120 ( V_683 , V_3 ) ;
return 1 ;
}
static int F_384 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
enum V_640 V_671 = V_236 ;
int V_93 = 1 ;
T_2 V_716 ;
bool V_717 ;
V_716 = F_71 ( V_456 ) ;
V_717 = V_716 & V_281 ;
while ( ! F_258 ( V_3 ) ) {
if ( V_717
&& ( F_242 ( & V_58 -> V_3 ) & V_620 ) )
return F_357 ( & V_58 -> V_3 ) ;
V_671 = F_310 ( V_3 , 0 ) ;
if ( V_671 == V_718 ) {
V_93 = 0 ;
goto V_509;
}
if ( V_671 != V_236 )
return 0 ;
if ( F_385 ( V_719 ) )
goto V_509;
if ( F_386 () )
F_387 () ;
}
V_58 -> V_403 = 0 ;
V_509:
return V_93 ;
}
static int F_388 ( struct V_2 * V_3 )
{
F_139 ( V_3 ) ;
F_389 ( V_3 ) ;
return 1 ;
}
static int F_390 ( struct V_2 * V_3 )
{
F_311 ( V_3 , V_21 ) ;
return 1 ;
}
static struct V_75 * F_391 ( struct V_1 * V_58 )
{
struct V_720 * V_721 ;
F_392 (item, &vmx->nested.vmcs02_pool, list)
if ( V_721 -> V_722 == V_58 -> V_8 . V_723 ) {
F_393 ( & V_721 -> V_724 , & V_58 -> V_8 . V_725 ) ;
return & V_721 -> V_726 ;
}
if ( V_58 -> V_8 . V_727 >= F_394 ( V_728 , 1 ) ) {
V_721 = F_395 ( V_58 -> V_8 . V_725 . V_729 ,
struct V_720 , V_724 ) ;
V_721 -> V_722 = V_58 -> V_8 . V_723 ;
F_393 ( & V_721 -> V_724 , & V_58 -> V_8 . V_725 ) ;
return & V_721 -> V_726 ;
}
V_721 = (struct V_720 * )
F_396 ( sizeof( struct V_720 ) , V_386 ) ;
if ( ! V_721 )
return NULL ;
V_721 -> V_726 . V_72 = F_198 () ;
if ( ! V_721 -> V_726 . V_72 ) {
F_397 ( V_721 ) ;
return NULL ;
}
F_55 ( & V_721 -> V_726 ) ;
V_721 -> V_722 = V_58 -> V_8 . V_723 ;
F_122 ( & ( V_721 -> V_724 ) , & ( V_58 -> V_8 . V_725 ) ) ;
V_58 -> V_8 . V_727 ++ ;
return & V_721 -> V_726 ;
}
static void F_398 ( struct V_1 * V_58 , T_1 V_722 )
{
struct V_720 * V_721 ;
F_392 (item, &vmx->nested.vmcs02_pool, list)
if ( V_721 -> V_722 == V_722 ) {
F_201 ( & V_721 -> V_726 ) ;
F_60 ( & V_721 -> V_724 ) ;
F_397 ( V_721 ) ;
V_58 -> V_8 . V_727 -- ;
return;
}
}
static void F_399 ( struct V_1 * V_58 )
{
struct V_720 * V_721 , * V_359 ;
F_188 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_58 -> V_75 != & V_721 -> V_726 )
F_201 ( & V_721 -> V_726 ) ;
F_60 ( & V_721 -> V_724 ) ;
F_397 ( V_721 ) ;
}
V_58 -> V_8 . V_727 = 0 ;
if ( V_58 -> V_75 != & V_58 -> V_730 )
F_201 ( & V_58 -> V_730 ) ;
}
static int F_400 ( struct V_2 * V_3 )
{
struct V_476 V_495 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_401 ( V_3 , V_357 ) ||
! F_127 ( V_3 , V_462 ) ||
( F_132 ( V_3 ) & V_215 ) ) {
F_311 ( V_3 , V_21 ) ;
return 1 ;
}
F_237 ( V_3 , & V_495 , V_487 ) ;
if ( F_105 ( V_3 ) && ! V_495 . V_483 ) {
F_311 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_243 ( V_3 ) ) {
F_351 ( V_3 , 0 ) ;
return 1 ;
}
F_184 ( & ( V_58 -> V_8 . V_725 ) ) ;
V_58 -> V_8 . V_727 = 0 ;
V_58 -> V_8 . V_473 = true ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_402 ( struct V_2 * V_3 )
{
struct V_476 V_495 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! V_58 -> V_8 . V_473 ) {
F_311 ( V_3 , V_21 ) ;
return 0 ;
}
F_237 ( V_3 , & V_495 , V_487 ) ;
if ( ( F_132 ( V_3 ) & V_215 ) ||
( F_105 ( V_3 ) && ! V_495 . V_483 ) ) {
F_311 ( V_3 , V_21 ) ;
return 0 ;
}
if ( F_243 ( V_3 ) ) {
F_351 ( V_3 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_403 ( struct V_1 * V_58 )
{
if ( ! V_58 -> V_8 . V_473 )
return;
V_58 -> V_8 . V_473 = false ;
if ( V_58 -> V_8 . V_723 != - 1ull ) {
F_404 ( V_58 -> V_8 . V_731 ) ;
F_9 ( V_58 -> V_8 . V_731 ) ;
V_58 -> V_8 . V_723 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
if ( V_58 -> V_8 . V_526 ) {
F_9 ( V_58 -> V_8 . V_526 ) ;
V_58 -> V_8 . V_526 = 0 ;
}
F_399 ( V_58 ) ;
}
static int F_405 ( struct V_2 * V_3 )
{
if ( ! F_402 ( V_3 ) )
return 1 ;
F_403 ( F_1 ( V_3 ) ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_406 ( struct V_2 * V_3 ,
unsigned long V_664 ,
T_2 V_732 , T_4 * V_93 )
{
int V_733 = V_732 & 3 ;
int V_734 = ( V_732 >> 7 ) & 7 ;
bool V_735 = V_732 & ( 1u << 10 ) ;
int V_736 = ( V_732 >> 15 ) & 7 ;
int V_737 = ( V_732 >> 18 ) & 0xf ;
bool V_738 = ! ( V_732 & ( 1u << 22 ) ) ;
int V_739 = ( V_732 >> 23 ) & 0xf ;
bool V_740 = ! ( V_732 & ( 1u << 27 ) ) ;
if ( V_735 ) {
F_311 ( V_3 , V_21 ) ;
return 1 ;
}
* V_93 = F_239 ( V_3 , V_736 ) ;
if ( V_740 )
* V_93 += F_333 ( V_3 , V_739 ) ;
if ( V_738 )
* V_93 += F_333 ( V_3 , V_737 ) << V_733 ;
* V_93 += V_664 ;
if ( V_734 == 1 )
* V_93 &= 0xffffffff ;
return 0 ;
}
static void F_407 ( struct V_2 * V_3 )
{
F_135 ( V_3 , F_132 ( V_3 )
& ~ ( V_741 | V_742 | V_743 |
V_744 | V_745 | V_746 ) ) ;
}
static void F_408 ( struct V_2 * V_3 )
{
F_135 ( V_3 , ( F_132 ( V_3 )
& ~ ( V_742 | V_743 | V_744 |
V_745 | V_746 ) )
| V_741 ) ;
}
static void F_409 ( struct V_2 * V_3 ,
T_2 V_747 )
{
if ( F_1 ( V_3 ) -> V_8 . V_723 == - 1ull ) {
F_408 ( V_3 ) ;
return;
}
F_135 ( V_3 , ( F_132 ( V_3 )
& ~ ( V_741 | V_742 | V_743 |
V_745 | V_746 ) )
| V_744 ) ;
F_4 ( V_3 ) -> V_747 = V_747 ;
}
static int F_410 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_4 V_66 ;
T_1 V_722 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_748 V_749 ;
if ( ! F_402 ( V_3 ) )
return 1 ;
if ( F_406 ( V_3 , F_69 ( V_653 ) ,
F_71 ( V_750 ) , & V_66 ) )
return 1 ;
if ( F_411 ( & V_3 -> V_95 . V_751 , V_66 , & V_722 ,
sizeof( V_722 ) , & V_749 ) ) {
F_412 ( V_3 , & V_749 ) ;
return 1 ;
}
if ( ! F_413 ( V_722 , V_379 ) ) {
F_409 ( V_3 , V_752 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
if ( V_722 == V_58 -> V_8 . V_723 ) {
F_404 ( V_58 -> V_8 . V_731 ) ;
F_9 ( V_58 -> V_8 . V_731 ) ;
V_58 -> V_8 . V_723 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_722 ) ;
if ( V_10 == NULL ) {
F_120 ( V_237 , V_3 ) ;
return 1 ;
}
V_7 = F_414 ( V_10 ) ;
V_7 -> V_753 = 0 ;
F_404 ( V_10 ) ;
F_9 ( V_10 ) ;
F_398 ( V_58 , V_722 ) ;
F_139 ( V_3 ) ;
F_407 ( V_3 ) ;
return 1 ;
}
static int F_415 ( struct V_2 * V_3 )
{
return F_416 ( V_3 , true ) ;
}
static int F_417 ( struct V_2 * V_3 )
{
return F_416 ( V_3 , false ) ;
}
static inline int F_418 ( unsigned long V_4 )
{
if ( 0x1 & V_4 )
return V_754 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_419 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_420 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_93 )
{
short V_258 = F_3 ( V_4 ) ;
char * V_98 ;
if ( V_258 < 0 )
return 0 ;
V_98 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_258 ;
switch ( F_418 ( V_4 ) ) {
case V_755 :
* V_93 = * ( ( V_756 * ) V_98 ) ;
return 1 ;
case V_757 :
* V_93 = * ( ( T_3 * ) V_98 ) ;
return 1 ;
case V_754 :
* V_93 = * ( ( T_2 * ) V_98 ) ;
return 1 ;
case V_758 :
* V_93 = * ( ( T_5 * ) V_98 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_421 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_58 -> V_8 . V_723 == - 1ull ) {
F_408 ( V_3 ) ;
F_139 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_422 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_759 ;
unsigned long V_664 = F_69 ( V_653 ) ;
T_2 V_732 = F_71 ( V_750 ) ;
T_4 V_66 = 0 ;
if ( ! F_402 ( V_3 ) ||
! F_421 ( V_3 ) )
return 1 ;
V_4 = F_333 ( V_3 , ( ( ( V_732 ) >> 28 ) & 0xf ) ) ;
if ( ! F_420 ( V_3 , V_4 , & V_759 ) ) {
F_409 ( V_3 , V_760 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
if ( V_732 & ( 1u << 10 ) ) {
F_295 ( V_3 , ( ( ( V_732 ) >> 3 ) & 0xf ) ,
V_759 ) ;
} else {
if ( F_406 ( V_3 , V_664 ,
V_732 , & V_66 ) )
return 1 ;
F_423 ( & V_3 -> V_95 . V_751 , V_66 ,
& V_759 , ( F_105 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_407 ( V_3 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_424 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_66 ;
unsigned long V_664 = F_69 ( V_653 ) ;
T_2 V_732 = F_71 ( V_750 ) ;
char * V_98 ;
short V_258 ;
T_5 V_759 = 0 ;
struct V_748 V_749 ;
if ( ! F_402 ( V_3 ) ||
! F_421 ( V_3 ) )
return 1 ;
if ( V_732 & ( 1u << 10 ) )
V_759 = F_333 ( V_3 ,
( ( ( V_732 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_406 ( V_3 , V_664 ,
V_732 , & V_66 ) )
return 1 ;
if ( F_411 ( & V_3 -> V_95 . V_751 , V_66 ,
& V_759 , ( F_105 ( V_3 ) ? 8 : 4 ) , & V_749 ) ) {
F_412 ( V_3 , & V_749 ) ;
return 1 ;
}
}
V_4 = F_333 ( V_3 , ( ( ( V_732 ) >> 28 ) & 0xf ) ) ;
if ( F_419 ( V_4 ) ) {
F_409 ( V_3 ,
V_761 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
V_258 = F_3 ( V_4 ) ;
if ( V_258 < 0 ) {
F_409 ( V_3 , V_760 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
V_98 = ( ( char * ) F_4 ( V_3 ) ) + V_258 ;
switch ( F_418 ( V_4 ) ) {
case V_757 :
* ( T_3 * ) V_98 = V_759 ;
break;
case V_754 :
* ( T_2 * ) V_98 = V_759 ;
break;
case V_758 :
* ( T_5 * ) V_98 = V_759 ;
break;
case V_755 :
* ( V_756 * ) V_98 = V_759 ;
break;
default:
F_409 ( V_3 , V_760 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
F_407 ( V_3 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_425 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_4 V_66 ;
T_1 V_722 ;
struct V_748 V_749 ;
if ( ! F_402 ( V_3 ) )
return 1 ;
if ( F_406 ( V_3 , F_69 ( V_653 ) ,
F_71 ( V_750 ) , & V_66 ) )
return 1 ;
if ( F_411 ( & V_3 -> V_95 . V_751 , V_66 , & V_722 ,
sizeof( V_722 ) , & V_749 ) ) {
F_412 ( V_3 , & V_749 ) ;
return 1 ;
}
if ( ! F_413 ( V_722 , V_379 ) ) {
F_409 ( V_3 , V_762 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_723 != V_722 ) {
struct V_7 * V_763 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_722 ) ;
if ( V_10 == NULL ) {
F_408 ( V_3 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
V_763 = F_414 ( V_10 ) ;
if ( V_763 -> V_382 != V_306 ) {
F_404 ( V_10 ) ;
F_11 ( V_10 ) ;
F_409 ( V_3 ,
V_764 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_723 != - 1ull ) {
F_404 ( V_58 -> V_8 . V_731 ) ;
F_9 ( V_58 -> V_8 . V_731 ) ;
}
V_58 -> V_8 . V_723 = V_722 ;
V_58 -> V_8 . V_9 = V_763 ;
V_58 -> V_8 . V_731 = V_10 ;
}
F_407 ( V_3 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static int F_426 ( struct V_2 * V_3 )
{
unsigned long V_664 = F_69 ( V_653 ) ;
T_2 V_732 = F_71 ( V_750 ) ;
T_4 V_765 ;
struct V_748 V_749 ;
if ( ! F_402 ( V_3 ) )
return 1 ;
if ( F_406 ( V_3 , V_664 ,
V_732 , & V_765 ) )
return 1 ;
if ( F_423 ( & V_3 -> V_95 . V_751 , V_765 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_723 ,
sizeof( T_5 ) , & V_749 ) ) {
F_412 ( V_3 , & V_749 ) ;
return 1 ;
}
F_407 ( V_3 ) ;
F_139 ( V_3 ) ;
return 1 ;
}
static bool F_427 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_645 )
{
T_2 V_300 = V_3 -> V_95 . V_339 [ V_681 ] ;
T_1 V_766 ;
if ( ! F_44 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_766 = V_7 -> V_244 ;
if ( V_645 == V_767 )
V_766 += 2048 ;
if ( V_300 >= 0xc0000000 ) {
V_300 -= 0xc0000000 ;
V_766 += 1024 ;
}
if ( V_300 < 1024 * 8 ) {
unsigned char V_768 ;
F_428 ( V_3 -> V_12 , V_766 + V_300 / 8 , & V_768 , 1 ) ;
return 1 & ( V_768 >> ( V_300 & 7 ) ) ;
} else
return 1 ;
}
static bool F_429 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_664 = F_69 ( V_653 ) ;
int V_670 = V_664 & 15 ;
int V_337 = ( V_664 >> 8 ) & 15 ;
unsigned long V_669 = F_333 ( V_3 , V_337 ) ;
switch ( ( V_664 >> 4 ) & 3 ) {
case 0 :
switch ( V_670 ) {
case 0 :
if ( V_7 -> V_199 &
( V_669 ^ V_7 -> V_203 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_769 >= 1 &&
V_7 -> V_770 == V_669 ) ||
( V_7 -> V_769 >= 2 &&
V_7 -> V_771 == V_669 ) ||
( V_7 -> V_769 >= 3 &&
V_7 -> V_772 == V_669 ) ||
( V_7 -> V_769 >= 4 &&
V_7 -> V_773 == V_669 ) )
return 0 ;
if ( F_44 ( V_7 , V_286 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_205 &
( V_7 -> V_206 ^ V_669 ) )
return 1 ;
break;
case 8 :
if ( F_44 ( V_7 , V_288 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_199 & V_196 ) &&
( V_7 -> V_203 & V_196 ) )
return 1 ;
break;
case 1 :
switch ( V_670 ) {
case 3 :
if ( V_7 -> V_55 &
V_287 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_55 &
V_289 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_199 & 0xe &
( V_669 ^ V_7 -> V_203 ) )
return 1 ;
if ( ( V_7 -> V_199 & 0x1 ) &&
! ( V_7 -> V_203 & 0x1 ) &&
( V_669 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_430 ( struct V_2 * V_3 )
{
T_2 V_645 = F_71 ( V_774 ) ;
T_2 V_14 = F_71 ( V_775 ) ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_58 -> V_8 . V_616 )
return 0 ;
if ( F_77 ( V_58 -> V_776 ) ) {
F_54 ( V_777 L_24 ,
V_440 , F_71 ( V_88 ) ) ;
return 1 ;
}
switch ( V_645 ) {
case V_778 :
if ( ! F_47 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_84 ;
return V_7 -> V_118 &
( 1u << ( V_14 & V_16 ) ) ;
case V_618 :
return 0 ;
case V_779 :
return 1 ;
case V_780 :
case V_781 :
return 1 ;
case V_782 :
return 1 ;
case V_783 :
return 1 ;
case V_784 :
return F_44 ( V_7 , V_283 ) ;
case V_785 :
return 1 ;
case V_786 :
return F_44 ( V_7 , V_284 ) ;
case V_787 :
return F_44 ( V_7 , V_788 ) ;
case V_789 :
return F_44 ( V_7 , V_790 ) ;
case V_791 : case V_792 :
case V_793 : case V_794 :
case V_795 : case V_796 :
case V_797 : case V_798 :
case V_799 : case V_800 :
return 1 ;
case V_801 :
return F_429 ( V_3 , V_7 ) ;
case V_802 :
return F_44 ( V_7 , V_290 ) ;
case V_803 :
return 1 ;
case V_804 :
case V_767 :
return F_427 ( V_3 , V_7 , V_645 ) ;
case V_805 :
return 1 ;
case V_806 :
return F_44 ( V_7 , V_285 ) ;
case V_807 :
return F_44 ( V_7 , V_293 ) ;
case V_808 :
return F_44 ( V_7 , V_809 ) ||
F_45 ( V_7 ,
V_47 ) ;
case V_810 :
return 0 ;
case V_811 :
return 1 ;
case V_812 :
return F_45 ( V_7 ,
V_30 ) ;
case V_704 :
case V_714 :
return 0 ;
case V_813 :
return F_45 ( V_7 , V_53 ) ;
case V_814 :
return 1 ;
default:
return 1 ;
}
}
static void F_431 ( struct V_2 * V_3 , T_5 * V_815 , T_5 * V_816 )
{
* V_815 = F_69 ( V_653 ) ;
* V_816 = F_71 ( V_775 ) ;
}
static int F_432 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_645 = V_58 -> V_645 ;
T_2 V_817 = V_58 -> V_642 ;
F_433 ( V_645 , V_3 , V_818 ) ;
if ( V_58 -> V_403 && V_411 )
return F_384 ( V_3 ) ;
if ( V_58 -> V_8 . V_616 )
F_120 ( V_683 , V_3 ) ;
if ( ! F_90 ( V_3 ) && ( V_645 == V_793 ||
V_645 == V_797 ) )
V_58 -> V_8 . V_616 = 1 ;
else
V_58 -> V_8 . V_616 = 0 ;
if ( F_90 ( V_3 ) && F_430 ( V_3 ) ) {
F_144 ( V_3 ) ;
return 1 ;
}
if ( V_645 & V_819 ) {
V_3 -> V_635 -> V_645 = V_820 ;
V_3 -> V_635 -> V_821 . V_822
= V_645 ;
return 0 ;
}
if ( F_77 ( V_58 -> V_776 ) ) {
V_3 -> V_635 -> V_645 = V_820 ;
V_3 -> V_635 -> V_821 . V_822
= F_71 ( V_88 ) ;
return 0 ;
}
if ( ( V_817 & V_644 ) &&
( V_645 != V_778 &&
V_645 != V_704 &&
V_645 != V_782 ) )
F_54 ( V_353 L_25
L_26 ,
V_440 , V_817 , V_645 ) ;
if ( F_77 ( ! F_41 () && V_58 -> V_583 &&
! ( F_90 ( V_3 ) && F_46 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_307 ( V_3 ) ) {
V_58 -> V_583 = 0 ;
} else if ( V_58 -> V_609 > 1000000000LL &&
V_3 -> V_95 . V_823 ) {
F_54 ( V_353 L_27
L_28 ,
V_440 , V_3 -> V_824 ) ;
V_58 -> V_583 = 0 ;
}
}
if ( V_645 < V_825
&& V_826 [ V_645 ] )
return V_826 [ V_645 ] ( V_3 ) ;
else {
V_3 -> V_635 -> V_645 = V_701 ;
V_3 -> V_635 -> V_702 . V_703 = V_645 ;
}
return 0 ;
}
static void V_392 ( struct V_2 * V_3 , int V_827 , int V_828 )
{
if ( V_828 == - 1 || V_827 < V_828 ) {
F_79 ( V_596 , 0 ) ;
return;
}
F_79 ( V_596 , V_828 ) ;
}
static void F_434 ( struct V_1 * V_58 )
{
T_2 V_643 ;
if ( ! ( V_58 -> V_645 == V_810
|| V_58 -> V_645 == V_778 ) )
return;
V_58 -> V_643 = F_71 ( V_775 ) ;
V_643 = V_58 -> V_643 ;
if ( F_16 ( V_643 ) )
F_312 () ;
if ( ( V_643 & V_15 ) == V_613 &&
( V_643 & V_17 ) ) {
F_435 ( & V_58 -> V_3 ) ;
asm("int $2");
F_436 ( & V_58 -> V_3 ) ;
}
}
static void F_437 ( struct V_1 * V_58 )
{
T_2 V_643 ;
bool V_829 ;
T_6 V_830 ;
bool V_831 ;
V_831 = V_58 -> V_642 & V_644 ;
if ( F_41 () ) {
if ( V_58 -> V_611 )
return;
V_643 = F_71 ( V_775 ) ;
V_829 = ( V_643 & V_832 ) != 0 ;
V_830 = V_643 & V_16 ;
if ( ( V_643 & V_17 ) && V_829 &&
V_830 != V_630 && ! V_831 )
F_82 ( V_217 ,
V_614 ) ;
else
V_58 -> V_611 =
! ( F_71 ( V_217 )
& V_614 ) ;
} else if ( F_77 ( V_58 -> V_583 ) )
V_58 -> V_609 +=
F_438 ( F_439 ( F_440 () , V_58 -> V_833 ) ) ;
}
static void F_441 ( struct V_1 * V_58 ,
T_2 V_642 ,
int V_834 ,
int V_835 )
{
T_6 V_830 ;
int type ;
bool V_831 ;
V_831 = V_642 & V_644 ;
V_58 -> V_3 . V_95 . V_693 = false ;
F_373 ( & V_58 -> V_3 ) ;
F_372 ( & V_58 -> V_3 ) ;
if ( ! V_831 )
return;
F_120 ( V_683 , & V_58 -> V_3 ) ;
V_830 = V_642 & V_836 ;
type = V_642 & V_691 ;
switch ( type ) {
case V_613 :
V_58 -> V_3 . V_95 . V_693 = true ;
F_306 ( & V_58 -> V_3 , false ) ;
break;
case V_239 :
V_58 -> V_3 . V_95 . V_235 =
F_71 ( V_834 ) ;
case V_18 :
if ( V_642 & V_694 ) {
T_2 V_671 = F_71 ( V_835 ) ;
F_166 ( & V_58 -> V_3 , V_830 , V_671 ) ;
} else
F_311 ( & V_58 -> V_3 , V_830 ) ;
break;
case V_608 :
V_58 -> V_3 . V_95 . V_235 =
F_71 ( V_834 ) ;
case V_22 :
F_442 ( & V_58 -> V_3 , V_830 ,
type == V_608 ) ;
break;
default:
break;
}
}
static void F_443 ( struct V_1 * V_58 )
{
if ( F_90 ( & V_58 -> V_3 ) )
return;
F_441 ( V_58 , V_58 -> V_642 ,
V_224 ,
V_695 ) ;
}
static void F_444 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) )
return;
F_441 ( F_1 ( V_3 ) ,
F_71 ( V_240 ) ,
V_238 ,
V_232 ) ;
F_79 ( V_240 , 0 ) ;
}
static void T_16 F_445 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) && ! V_58 -> V_8 . V_616 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_837 &
V_644 ) {
F_79 ( V_240 ,
V_7 -> V_837 ) ;
F_79 ( V_238 ,
V_7 -> V_838 ) ;
if ( V_7 -> V_837 &
V_694 )
F_79 ( V_232 ,
V_7 -> V_839 ) ;
}
}
if ( F_77 ( ! F_41 () && V_58 -> V_583 ) )
V_58 -> V_833 = F_440 () ;
if ( V_58 -> V_403 && V_411 )
return;
if ( F_133 ( V_338 , ( unsigned long * ) & V_3 -> V_95 . V_448 ) )
F_76 ( V_340 , V_3 -> V_95 . V_339 [ V_338 ] ) ;
if ( F_133 ( V_341 , ( unsigned long * ) & V_3 -> V_95 . V_448 ) )
F_76 ( V_342 , V_3 -> V_95 . V_339 [ V_341 ] ) ;
if ( V_3 -> V_111 & V_626 )
F_138 ( V_3 , 0 ) ;
V_58 -> V_840 = V_58 -> V_75 -> V_77 ;
asm(
"push %%"R"dx; push %%"R"bp;"
"push %%"R"cx \n\t"
"push %%"R"cx \n\t"
"cmp %%"R"sp, %c[host_rsp](%0) \n\t"
"je 1f \n\t"
"mov %%"R"sp, %c[host_rsp](%0) \n\t"
__ex(ASM_VMX_VMWRITE_RSP_RDX) "\n\t"
"1: \n\t"
"mov %c[cr2](%0), %%"R"ax \n\t"
"mov %%cr2, %%"R"dx \n\t"
"cmp %%"R"ax, %%"R"dx \n\t"
"je 2f \n\t"
"mov %%"R"ax, %%cr2 \n\t"
"2: \n\t"
"cmpl $0, %c[launched](%0) \n\t"
"mov %c[rax](%0), %%"R"ax \n\t"
"mov %c[rbx](%0), %%"R"bx \n\t"
"mov %c[rdx](%0), %%"R"dx \n\t"
"mov %c[rsi](%0), %%"R"si \n\t"
"mov %c[rdi](%0), %%"R"di \n\t"
"mov %c[rbp](%0), %%"R"bp \n\t"
#ifdef F_73
"mov %c[r8](%0), %%r8 \n\t"
"mov %c[r9](%0), %%r9 \n\t"
"mov %c[r10](%0), %%r10 \n\t"
"mov %c[r11](%0), %%r11 \n\t"
"mov %c[r12](%0), %%r12 \n\t"
"mov %c[r13](%0), %%r13 \n\t"
"mov %c[r14](%0), %%r14 \n\t"
"mov %c[r15](%0), %%r15 \n\t"
#endif
"mov %c[rcx](%0), %%"R"cx \n\t"
"jne .Llaunched \n\t"
__ex(ASM_VMX_VMLAUNCH) "\n\t"
"jmp .Lkvm_vmx_return \n\t"
".Llaunched: " __ex(ASM_VMX_VMRESUME) "\n\t"
".Lkvm_vmx_return: "
"mov %0, %c[wordsize](%%"R"sp) \n\t"
"pop %0 \n\t"
"mov %%"R"ax, %c[rax](%0) \n\t"
"mov %%"R"bx, %c[rbx](%0) \n\t"
"pop"Q" %c[rcx](%0) \n\t"
"mov %%"R"dx, %c[rdx](%0) \n\t"
"mov %%"R"si, %c[rsi](%0) \n\t"
"mov %%"R"di, %c[rdi](%0) \n\t"
"mov %%"R"bp, %c[rbp](%0) \n\t"
#ifdef F_73
"mov %%r8, %c[r8](%0) \n\t"
"mov %%r9, %c[r9](%0) \n\t"
"mov %%r10, %c[r10](%0) \n\t"
"mov %%r11, %c[r11](%0) \n\t"
"mov %%r12, %c[r12](%0) \n\t"
"mov %%r13, %c[r13](%0) \n\t"
"mov %%r14, %c[r14](%0) \n\t"
"mov %%r15, %c[r15](%0) \n\t"
#endif
"mov %%cr2, %%"R"ax \n\t"
"mov %%"R"ax, %c[cr2](%0) \n\t"
"pop %%"R"bp; pop %%"R"dx \n\t"
"setbe %c[fail](%0) \n\t"
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
#ifdef F_73
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
, R"ax", R"bx", R"di", R"si"
#ifdef F_73
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#endif
);
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_341 ) | ( 1 << V_338 )
| ( 1 << V_210 )
| ( 1 << V_213 )
| ( 1 << V_343 )
| ( 1 << V_97 )
| ( 1 << V_445 ) ) ;
V_3 -> V_95 . V_448 = 0 ;
V_58 -> V_642 = F_71 ( V_841 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_837 = V_58 -> V_642 ;
if ( V_58 -> V_642 & V_644 ) {
V_7 -> V_839 =
F_71 ( V_695 ) ;
V_7 -> V_838 =
F_71 ( V_224 ) ;
}
}
asm("mov %0, %%ds; mov %0, %%es" : : "r"(__USER_DS));
V_58 -> V_75 -> V_77 = 1 ;
V_58 -> V_645 = F_71 ( V_774 ) ;
F_434 ( V_58 ) ;
F_437 ( V_58 ) ;
F_443 ( V_58 ) ;
}
static void F_446 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
F_274 ( V_58 ) ;
F_403 ( V_58 ) ;
F_201 ( V_58 -> V_75 ) ;
F_397 ( V_58 -> V_63 ) ;
F_447 ( V_3 ) ;
F_448 ( V_842 , V_58 ) ;
}
static struct V_2 * F_449 ( struct V_12 * V_12 , unsigned int V_843 )
{
int V_671 ;
struct V_1 * V_58 = F_450 ( V_842 , V_386 ) ;
int V_76 ;
if ( ! V_58 )
return F_451 ( - V_387 ) ;
F_270 ( V_58 ) ;
V_671 = F_452 ( & V_58 -> V_3 , V_12 , V_843 ) ;
if ( V_671 )
goto V_844;
V_58 -> V_63 = F_396 ( V_379 , V_386 ) ;
V_671 = - V_387 ;
if ( ! V_58 -> V_63 ) {
goto V_845;
}
V_58 -> V_75 = & V_58 -> V_730 ;
V_58 -> V_75 -> V_72 = F_198 () ;
if ( ! V_58 -> V_75 -> V_72 )
goto V_846;
if ( ! V_186 )
F_119 ( F_53 ( F_59 ( V_185 , F_58 () ) ) ) ;
F_55 ( V_58 -> V_75 ) ;
if ( ! V_186 )
F_125 () ;
V_76 = F_453 () ;
F_118 ( & V_58 -> V_3 , V_76 ) ;
V_58 -> V_3 . V_76 = V_76 ;
V_671 = F_286 ( V_58 ) ;
F_124 ( & V_58 -> V_3 ) ;
F_454 () ;
if ( V_671 )
goto F_199;
if ( F_38 ( V_12 ) )
V_671 = F_265 ( V_12 ) ;
if ( V_671 )
goto F_199;
if ( V_84 ) {
if ( ! V_12 -> V_95 . V_469 )
V_12 -> V_95 . V_469 =
V_847 ;
V_671 = - V_387 ;
if ( F_269 ( V_12 ) != 0 )
goto F_199;
if ( ! F_262 ( V_12 ) )
goto F_199;
}
V_58 -> V_8 . V_723 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
return & V_58 -> V_3 ;
F_199:
F_199 ( V_58 -> V_75 -> V_72 ) ;
V_846:
F_397 ( V_58 -> V_63 ) ;
V_845:
F_447 ( & V_58 -> V_3 ) ;
V_844:
F_274 ( V_58 ) ;
F_448 ( V_842 , V_58 ) ;
return F_451 ( V_671 ) ;
}
static void T_11 F_455 ( void * V_848 )
{
struct V_24 V_367 ;
* ( int * ) V_848 = 0 ;
if ( F_192 ( & V_367 ) < 0 )
* ( int * ) V_848 = - V_366 ;
if ( memcmp ( & V_24 , & V_367 , sizeof( struct V_24 ) ) != 0 ) {
F_54 ( V_74 L_29 ,
F_456 () ) ;
* ( int * ) V_848 = - V_366 ;
}
}
static int F_457 ( void )
{
return V_464 + 1 ;
}
static T_5 F_458 ( struct V_2 * V_3 , T_13 V_849 , bool V_850 )
{
T_5 V_93 ;
if ( V_850 )
V_93 = V_851 << V_852 ;
else if ( V_3 -> V_12 -> V_95 . V_853 &&
! ( V_3 -> V_12 -> V_95 . V_854 & V_855 ) )
V_93 = F_459 ( V_3 , V_849 ) <<
V_852 ;
else
V_93 = ( V_856 << V_852 )
| V_857 ;
return V_93 ;
}
static int F_460 ( void )
{
if ( V_84 && ! F_28 () )
return V_858 ;
else
return V_859 ;
}
static void F_461 ( struct V_2 * V_3 )
{
struct V_262 * V_263 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_558 ;
V_58 -> V_249 = false ;
if ( F_148 () ) {
V_558 = F_71 ( V_566 ) ;
if ( V_558 & V_50 ) {
V_263 = F_159 ( V_3 , 0x80000001 , 0 ) ;
if ( V_263 && ( V_263 -> V_860 & V_54 ( V_861 ) ) )
V_58 -> V_249 = true ;
else {
V_558 &= ~ V_50 ;
F_79 ( V_566 ,
V_558 ) ;
}
}
}
}
static void F_462 ( T_2 V_862 , struct V_262 * V_863 )
{
if ( V_862 == 1 && V_8 )
V_863 -> V_264 |= V_54 ( V_265 ) ;
}
static void F_463 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_558 ;
F_78 ( V_864 , V_7 -> V_865 ) ;
F_78 ( V_420 , V_7 -> V_866 ) ;
F_78 ( V_418 , V_7 -> V_867 ) ;
F_78 ( V_868 , V_7 -> V_869 ) ;
F_78 ( V_870 , V_7 -> V_871 ) ;
F_78 ( V_872 , V_7 -> V_873 ) ;
F_78 ( V_588 , V_7 -> V_874 ) ;
F_78 ( V_404 , V_7 -> V_875 ) ;
F_79 ( V_876 , V_7 -> V_877 ) ;
F_79 ( V_434 , V_7 -> V_878 ) ;
F_79 ( V_433 , V_7 -> V_879 ) ;
F_79 ( V_880 , V_7 -> V_881 ) ;
F_79 ( V_882 , V_7 -> V_883 ) ;
F_79 ( V_884 , V_7 -> V_885 ) ;
F_79 ( V_590 , V_7 -> V_886 ) ;
F_79 ( V_406 , V_7 -> V_887 ) ;
F_79 ( V_493 , V_7 -> V_888 ) ;
F_79 ( V_491 , V_7 -> V_889 ) ;
F_79 ( V_890 , V_7 -> V_891 ) ;
F_79 ( V_421 , V_7 -> V_892 ) ;
F_79 ( V_419 , V_7 -> V_893 ) ;
F_79 ( V_894 , V_7 -> V_895 ) ;
F_79 ( V_896 , V_7 -> V_897 ) ;
F_79 ( V_898 , V_7 -> V_899 ) ;
F_79 ( V_591 , V_7 -> V_900 ) ;
F_79 ( V_407 , V_7 -> V_901 ) ;
F_76 ( V_902 , V_7 -> V_903 ) ;
F_76 ( V_435 , V_7 -> V_904 ) ;
F_76 ( V_432 , V_7 -> V_905 ) ;
F_76 ( V_906 , V_7 -> V_907 ) ;
F_76 ( V_324 , V_7 -> V_908 ) ;
F_76 ( V_325 , V_7 -> V_909 ) ;
F_76 ( V_589 , V_7 -> V_910 ) ;
F_76 ( V_405 , V_7 -> V_911 ) ;
F_76 ( V_494 , V_7 -> V_912 ) ;
F_76 ( V_492 , V_7 -> V_913 ) ;
F_80 ( V_593 , V_7 -> V_914 ) ;
F_79 ( V_240 ,
V_7 -> V_915 ) ;
F_79 ( V_232 ,
V_7 -> V_916 ) ;
F_79 ( V_238 ,
V_7 -> V_917 ) ;
F_79 ( V_217 ,
V_7 -> V_918 ) ;
F_79 ( V_226 , V_7 -> V_919 ) ;
F_79 ( V_328 , V_7 -> V_920 ) ;
F_76 ( V_347 , V_7 -> V_921 ) ;
F_76 ( V_211 , V_7 -> V_922 ) ;
F_76 ( V_592 ,
V_7 -> V_923 ) ;
F_76 ( V_331 , V_7 -> V_924 ) ;
F_76 ( V_330 , V_7 -> V_925 ) ;
F_80 ( V_564 , - 1ull ) ;
F_79 ( V_565 ,
( V_24 . V_51 |
V_7 -> V_57 ) ) ;
F_79 ( V_570 ,
V_84 ? V_7 -> V_926 : 0 ) ;
F_79 ( V_571 ,
V_84 ? V_7 -> V_927 : 0 ) ;
if ( F_21 () ) {
T_2 V_558 = F_283 ( V_58 ) ;
if ( ! V_58 -> V_249 )
V_558 &= ~ V_50 ;
V_558 &= ~ V_30 ;
if ( F_44 ( V_7 ,
V_28 ) )
V_558 |= V_7 -> V_56 ;
if ( V_558 & V_30 ) {
if ( V_58 -> V_8 . V_526 )
F_9 ( V_58 -> V_8 . V_526 ) ;
V_58 -> V_8 . V_526 =
F_5 ( V_3 , V_7 -> V_928 ) ;
if ( ! V_58 -> V_8 . V_526 )
V_558 &=
~ V_30 ;
else
F_80 ( V_597 ,
F_296 ( V_58 -> V_8 . V_526 ) ) ;
}
F_79 ( V_566 , V_558 ) ;
}
F_277 () ;
V_58 -> V_929 = 0 ;
V_558 = F_282 ( V_58 ) ;
V_558 &= ~ V_281 ;
V_558 &= ~ V_602 ;
V_558 &= ~ V_27 ;
V_558 |= V_7 -> V_55 ;
V_558 &= ~ V_26 ;
V_558 &= ~ V_292 ;
V_558 |= V_291 ;
F_79 ( V_456 , V_558 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_198 &= ~ V_7 -> V_199 ;
F_76 ( V_200 , ~ V_3 -> V_95 . V_198 ) ;
F_79 ( V_126 ,
V_7 -> V_930 | V_24 . V_383 ) ;
F_79 ( V_124 , V_7 -> V_931 |
( V_24 . V_333 & ~ V_277 ) ) ;
if ( V_7 -> V_931 & V_276 )
F_80 ( V_334 , V_7 -> V_932 ) ;
else if ( V_24 . V_333 & V_276 )
F_80 ( V_334 , V_58 -> V_3 . V_95 . V_335 ) ;
F_281 ( V_58 ) ;
F_80 ( V_256 ,
V_58 -> V_8 . V_259 + V_7 -> V_255 ) ;
if ( V_389 ) {
F_78 ( V_598 , V_58 -> V_42 ) ;
F_223 ( V_3 ) ;
}
if ( V_7 -> V_931 & V_125 )
V_3 -> V_95 . V_147 = V_7 -> V_933 ;
if ( V_7 -> V_931 & V_277 )
V_3 -> V_95 . V_147 |= ( V_150 | V_151 ) ;
else
V_3 -> V_95 . V_147 &= ~ ( V_150 | V_151 ) ;
F_220 ( V_3 , V_3 -> V_95 . V_147 ) ;
F_234 ( V_3 , V_7 -> V_202 ) ;
F_76 ( V_207 , F_128 ( V_7 ) ) ;
F_232 ( V_3 , V_7 -> V_204 ) ;
F_76 ( V_410 , F_129 ( V_7 ) ) ;
F_336 ( V_3 , V_7 -> V_467 ) ;
F_219 ( V_3 ) ;
F_295 ( V_3 , V_338 , V_7 -> V_934 ) ;
F_295 ( V_3 , V_341 , V_7 -> V_935 ) ;
}
static int F_416 ( struct V_2 * V_3 , bool V_936 )
{
struct V_7 * V_7 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_75 * V_726 ;
if ( ! F_402 ( V_3 ) ||
! F_421 ( V_3 ) )
return 1 ;
F_139 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_753 == V_936 ) {
F_409 ( V_3 ,
V_936 ? V_937
: V_938 ) ;
return 1 ;
}
if ( ( V_7 -> V_55 & V_26 ) &&
! F_413 ( V_7 -> V_244 , V_379 ) ) {
F_409 ( V_3 , V_939 ) ;
return 1 ;
}
if ( F_45 ( V_7 , V_30 ) &&
! F_413 ( V_7 -> V_928 , V_379 ) ) {
F_409 ( V_3 , V_939 ) ;
return 1 ;
}
if ( V_7 -> V_940 > 0 ||
V_7 -> V_941 > 0 ||
V_7 -> V_942 > 0 ) {
if ( F_464 () )
F_54 ( V_353
L_30 , V_440 ) ;
F_409 ( V_3 , V_939 ) ;
return 1 ;
}
if ( ! F_163 ( V_7 -> V_55 ,
V_279 , V_280 ) ||
! F_163 ( V_7 -> V_56 ,
V_295 , V_296 ) ||
! F_163 ( V_7 -> V_57 ,
V_266 , V_267 ) ||
! F_163 ( V_7 -> V_930 ,
V_270 , V_271 ) ||
! F_163 ( V_7 -> V_931 ,
V_274 , V_275 ) )
{
F_409 ( V_3 , V_939 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_943 & F_167 ) != F_167 ) ||
( ( V_7 -> V_944 & F_168 ) != F_168 ) ) {
F_409 ( V_3 ,
V_945 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_202 & F_167 ) != F_167 ) ||
( ( V_7 -> V_204 & F_168 ) != F_168 ) ) {
F_465 ( V_3 , V_7 ,
V_805 , V_946 ) ;
return 1 ;
}
if ( V_7 -> V_947 != - 1ull ) {
F_465 ( V_3 , V_7 ,
V_805 , V_948 ) ;
return 1 ;
}
V_726 = F_391 ( V_58 ) ;
if ( ! V_726 )
return - V_387 ;
F_466 ( V_3 ) ;
V_58 -> V_8 . V_259 = F_72 ( V_256 ) ;
V_76 = F_453 () ;
V_58 -> V_75 = V_726 ;
F_124 ( V_3 ) ;
F_118 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_454 () ;
V_7 -> V_753 = 1 ;
F_463 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_467 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_195 ) & V_3 -> V_95 . V_198 ) |
( V_7 -> V_202 & V_7 -> V_199 ) |
( F_69 ( V_207 ) & ~ ( V_7 -> V_199 |
V_3 -> V_95 . V_198 ) ) ;
}
static inline unsigned long
F_468 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_408 ) & V_3 -> V_95 . V_446 ) |
( V_7 -> V_204 & V_7 -> V_205 ) |
( F_69 ( V_410 ) & ~ ( V_7 -> V_205 |
V_3 -> V_95 . V_446 ) ) ;
}
void F_469 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_202 = F_467 ( V_3 , V_7 ) ;
V_7 -> V_204 = F_468 ( V_3 , V_7 ) ;
F_344 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_921 ) ;
V_7 -> V_934 = F_333 ( V_3 , V_338 ) ;
V_7 -> V_935 = F_333 ( V_3 , V_341 ) ;
V_7 -> V_922 = F_69 ( V_211 ) ;
V_7 -> V_865 = F_70 ( V_864 ) ;
V_7 -> V_866 = F_70 ( V_420 ) ;
V_7 -> V_867 = F_70 ( V_418 ) ;
V_7 -> V_869 = F_70 ( V_868 ) ;
V_7 -> V_871 = F_70 ( V_870 ) ;
V_7 -> V_873 = F_70 ( V_872 ) ;
V_7 -> V_874 = F_70 ( V_588 ) ;
V_7 -> V_875 = F_70 ( V_404 ) ;
V_7 -> V_877 = F_71 ( V_876 ) ;
V_7 -> V_878 = F_71 ( V_434 ) ;
V_7 -> V_879 = F_71 ( V_433 ) ;
V_7 -> V_881 = F_71 ( V_880 ) ;
V_7 -> V_883 = F_71 ( V_882 ) ;
V_7 -> V_885 = F_71 ( V_884 ) ;
V_7 -> V_886 = F_71 ( V_590 ) ;
V_7 -> V_887 = F_71 ( V_406 ) ;
V_7 -> V_888 = F_71 ( V_493 ) ;
V_7 -> V_889 = F_71 ( V_491 ) ;
V_7 -> V_891 = F_71 ( V_890 ) ;
V_7 -> V_892 = F_71 ( V_421 ) ;
V_7 -> V_893 = F_71 ( V_419 ) ;
V_7 -> V_895 = F_71 ( V_894 ) ;
V_7 -> V_897 = F_71 ( V_896 ) ;
V_7 -> V_899 = F_71 ( V_898 ) ;
V_7 -> V_900 = F_71 ( V_591 ) ;
V_7 -> V_901 = F_71 ( V_407 ) ;
V_7 -> V_903 = F_69 ( V_902 ) ;
V_7 -> V_904 = F_69 ( V_435 ) ;
V_7 -> V_905 = F_69 ( V_432 ) ;
V_7 -> V_907 = F_69 ( V_906 ) ;
V_7 -> V_908 = F_69 ( V_324 ) ;
V_7 -> V_909 = F_69 ( V_325 ) ;
V_7 -> V_910 = F_69 ( V_589 ) ;
V_7 -> V_911 = F_69 ( V_405 ) ;
V_7 -> V_912 = F_69 ( V_494 ) ;
V_7 -> V_913 = F_69 ( V_492 ) ;
V_7 -> V_919 = F_71 ( V_226 ) ;
V_7 -> V_918 =
F_71 ( V_217 ) ;
V_7 -> V_923 =
F_69 ( V_592 ) ;
V_7 -> V_914 = F_72 ( V_593 ) ;
if ( V_7 -> V_931 & V_377 )
V_7 -> V_932 = F_72 ( V_334 ) ;
V_7 -> V_920 = F_71 ( V_328 ) ;
V_7 -> V_924 = F_69 ( V_331 ) ;
V_7 -> V_925 = F_69 ( V_330 ) ;
V_7 -> V_617 = F_71 ( V_774 ) ;
V_7 -> V_664 = F_69 ( V_653 ) ;
V_7 -> V_619 = F_71 ( V_775 ) ;
V_7 -> V_949 = F_71 ( V_652 ) ;
V_7 -> V_837 =
F_71 ( V_841 ) ;
V_7 -> V_839 =
F_71 ( V_695 ) ;
V_7 -> V_838 = F_71 ( V_224 ) ;
V_7 -> V_732 = F_71 ( V_750 ) ;
if ( ! ( V_7 -> V_617 & V_819 ) )
V_7 -> V_915 &= ~ V_17 ;
}
void F_470 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_930 & V_127 )
V_3 -> V_95 . V_147 = V_7 -> V_950 ;
if ( V_7 -> V_930 & V_272 )
V_3 -> V_95 . V_147 |= ( V_150 | V_151 ) ;
else
V_3 -> V_95 . V_147 &= ~ ( V_150 | V_151 ) ;
F_220 ( V_3 , V_3 -> V_95 . V_147 ) ;
F_295 ( V_3 , V_338 , V_7 -> V_929 ) ;
F_295 ( V_3 , V_341 , V_7 -> V_951 ) ;
F_328 ( V_3 , V_7 -> V_943 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_198 = ( V_3 -> V_117 ? V_196 : 0 ) ;
F_76 ( V_200 , ~ V_3 -> V_95 . V_198 ) ;
V_3 -> V_95 . V_446 = ~ F_69 ( V_557 ) ;
F_330 ( V_3 , V_7 -> V_944 ) ;
F_336 ( V_3 , V_7 -> V_952 ) ;
F_219 ( V_3 ) ;
if ( V_389 ) {
F_223 ( V_3 ) ;
}
F_79 ( V_328 , V_7 -> V_953 ) ;
F_76 ( V_331 , V_7 -> V_954 ) ;
F_76 ( V_330 , V_7 -> V_955 ) ;
F_76 ( V_492 , V_7 -> V_956 ) ;
F_76 ( V_494 , V_7 -> V_957 ) ;
F_76 ( V_405 , V_7 -> V_958 ) ;
F_76 ( V_325 , V_7 -> V_959 ) ;
F_76 ( V_324 , V_7 -> V_960 ) ;
F_78 ( V_864 , V_7 -> V_961 ) ;
F_78 ( V_420 , V_7 -> V_962 ) ;
F_78 ( V_418 , V_7 -> V_963 ) ;
F_78 ( V_868 , V_7 -> V_964 ) ;
F_78 ( V_870 , V_7 -> V_965 ) ;
F_78 ( V_872 , V_7 -> V_966 ) ;
F_78 ( V_404 , V_7 -> V_967 ) ;
if ( V_7 -> V_930 & V_378 )
F_80 ( V_334 , V_7 -> V_968 ) ;
if ( V_7 -> V_930 & V_969 )
F_80 ( V_970 ,
V_7 -> V_971 ) ;
}
static void F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_471 ( V_3 ) ;
F_469 ( V_3 , V_7 ) ;
V_76 = F_453 () ;
V_58 -> V_75 = & V_58 -> V_730 ;
F_124 ( V_3 ) ;
F_118 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_454 () ;
if ( V_728 == 0 )
F_398 ( V_58 , V_58 -> V_8 . V_723 ) ;
F_470 ( V_3 , V_7 ) ;
F_80 ( V_256 , V_58 -> V_8 . V_259 ) ;
V_58 -> V_929 = 0 ;
if ( V_58 -> V_8 . V_526 ) {
F_9 ( V_58 -> V_8 . V_526 ) ;
V_58 -> V_8 . V_526 = 0 ;
}
if ( F_77 ( V_58 -> V_776 ) ) {
V_58 -> V_776 = 0 ;
F_409 ( V_3 , F_71 ( V_88 ) ) ;
} else
F_407 ( V_3 ) ;
}
static void F_465 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_689 , unsigned long V_972 )
{
F_470 ( V_3 , V_7 ) ;
V_7 -> V_617 = V_689 | V_819 ;
V_7 -> V_664 = V_972 ;
F_407 ( V_3 ) ;
}
static int F_472 ( struct V_2 * V_3 ,
struct V_973 * V_974 ,
enum V_975 V_976 )
{
return V_977 ;
}
static int T_11 F_473 ( void )
{
int V_507 , V_60 ;
F_474 ( V_122 , & V_152 ) ;
for ( V_60 = 0 ; V_60 < V_579 ; ++ V_60 )
F_475 ( V_60 , V_62 [ V_60 ] ) ;
V_561 = ( unsigned long * ) F_476 ( V_386 ) ;
if ( ! V_561 )
return - V_387 ;
V_563 = ( unsigned long * ) F_476 ( V_386 ) ;
if ( ! V_563 ) {
V_507 = - V_387 ;
goto V_509;
}
V_252 = ( unsigned long * ) F_476 ( V_386 ) ;
if ( ! V_252 ) {
V_507 = - V_387 ;
goto V_978;
}
V_251 = ( unsigned long * ) F_476 ( V_386 ) ;
if ( ! V_251 ) {
V_507 = - V_387 ;
goto V_979;
}
memset ( V_561 , 0xff , V_379 ) ;
F_477 ( 0x80 , V_561 ) ;
memset ( V_563 , 0xff , V_379 ) ;
memset ( V_252 , 0xff , V_379 ) ;
memset ( V_251 , 0xff , V_379 ) ;
F_478 ( 0 , V_533 ) ;
V_507 = F_479 ( & V_980 , sizeof( struct V_1 ) ,
F_480 ( struct V_1 ) , V_981 ) ;
if ( V_507 )
goto V_982;
F_276 ( V_174 , false ) ;
F_276 ( V_176 , false ) ;
F_276 ( V_177 , true ) ;
F_276 ( V_327 , false ) ;
F_276 ( V_192 , false ) ;
F_276 ( V_329 , false ) ;
if ( V_84 ) {
F_481 ( 0ull , 0ull , 0ull , 0ull ,
V_983 ) ;
F_284 () ;
F_482 () ;
} else
F_483 () ;
return 0 ;
V_982:
F_484 ( ( unsigned long ) V_251 ) ;
V_979:
F_484 ( ( unsigned long ) V_252 ) ;
V_978:
F_484 ( ( unsigned long ) V_563 ) ;
V_509:
F_484 ( ( unsigned long ) V_561 ) ;
return V_507 ;
}
static void T_12 F_485 ( void )
{
F_484 ( ( unsigned long ) V_252 ) ;
F_484 ( ( unsigned long ) V_251 ) ;
F_484 ( ( unsigned long ) V_563 ) ;
F_484 ( ( unsigned long ) V_561 ) ;
F_486 () ;
}
