static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline bool F_3 ( T_1 V_4 )
{
return ( V_4 & ( V_5 | V_6 |
V_7 ) ) ==
( V_8 | V_9 | V_7 ) ;
}
static inline bool F_4 ( T_1 V_4 )
{
return ( V_4 & ( V_5 | V_6 |
V_7 ) ) ==
( V_8 | V_10 | V_7 ) ;
}
static inline bool F_5 ( T_1 V_4 )
{
return ( V_4 & ( V_5 | V_6 |
V_7 ) ) ==
( V_8 | V_11 | V_7 ) ;
}
static inline bool F_6 ( T_1 V_4 )
{
return ( V_4 & ( V_5 | V_7 ) )
== ( V_12 | V_7 ) ;
}
static inline bool F_7 ( T_1 V_4 )
{
return ( V_4 & ( V_5 | V_6 |
V_7 ) ) ==
( V_8 | V_13 | V_7 ) ;
}
static inline bool F_8 ( void )
{
return V_14 . V_15 & V_16 ;
}
static inline bool F_9 ( void )
{
return V_14 . V_15 & V_17 ;
}
static inline bool F_10 ( struct V_18 * V_18 )
{
return ( F_9 () ) && ( F_11 ( V_18 ) ) ;
}
static inline bool F_12 ( void )
{
return V_14 . V_15 &
V_19 ;
}
static inline bool F_13 ( void )
{
return V_14 . V_20 &
V_21 ;
}
static inline bool F_14 ( void )
{
return F_9 () &&
F_13 () ;
}
static inline bool F_15 ( void )
{
return V_22 . V_23 & V_24 ;
}
static inline bool F_16 ( void )
{
return V_22 . V_23 & V_25 ;
}
static inline bool F_17 ( void )
{
return V_22 . V_23 & V_26 ;
}
static inline bool F_18 ( void )
{
return V_22 . V_23 & V_27 ;
}
static inline bool F_19 ( void )
{
return V_22 . V_23 & V_28 ;
}
static inline bool F_20 ( void )
{
return V_22 . V_23 & V_29 ;
}
static inline bool F_21 ( void )
{
return V_22 . V_23 & V_30 ;
}
static inline bool F_22 ( void )
{
return V_22 . V_23 & V_31 ;
}
static inline bool F_23 ( void )
{
return V_22 . V_23 & V_32 ;
}
static inline bool F_24 ( void )
{
return V_22 . V_33 & V_34 ;
}
static inline bool F_25 ( void )
{
return V_22 . V_33 & V_35 ;
}
static inline bool F_26 ( void )
{
return V_14 . V_20 &
V_36 ;
}
static inline bool F_27 ( void )
{
return V_14 . V_20 &
V_37 ;
}
static inline bool F_28 ( void )
{
return V_14 . V_20 &
V_38 ;
}
static inline bool F_29 ( struct V_18 * V_18 )
{
return V_39 && F_11 ( V_18 ) ;
}
static inline bool F_30 ( void )
{
return V_14 . V_20 &
V_40 ;
}
static inline bool F_31 ( void )
{
return V_14 . V_20 &
V_41 ;
}
static inline bool F_32 ( void )
{
return V_14 . V_42 & V_43 ;
}
static inline bool F_33 ( void )
{
return V_14 . V_20 &
V_44 ;
}
static inline bool F_34 ( void )
{
return V_39 ;
}
static int F_35 ( struct V_1 * V_45 , T_1 V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_45 -> V_48 ; ++ V_47 )
if ( V_49 [ V_45 -> V_50 [ V_47 ] . V_51 ] == V_46 )
return V_47 ;
return - 1 ;
}
static inline void F_36 ( int V_52 , T_2 V_33 , T_3 V_53 )
{
struct {
T_4 V_33 : 16 ;
T_4 V_54 : 48 ;
T_4 V_53 ;
} V_55 = { V_33 , 0 , V_53 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_37 ( int V_52 , T_4 V_56 , T_5 V_57 )
{
struct {
T_4 V_56 , V_57 ;
} V_55 = { V_56 , V_57 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_58 * F_38 ( struct V_1 * V_45 , T_1 V_46 )
{
int V_47 ;
V_47 = F_35 ( V_45 , V_46 ) ;
if ( V_47 >= 0 )
return & V_45 -> V_50 [ V_47 ] ;
return NULL ;
}
static void F_39 ( struct V_59 * V_59 )
{
T_4 V_60 = F_40 ( V_59 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_41 ( V_61 L_1 ,
V_59 , V_60 ) ;
}
static void F_42 ( struct V_59 * V_59 )
{
T_4 V_60 = F_40 ( V_59 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_41 ( V_61 L_2 ,
V_59 , V_60 ) ;
}
static void F_43 ( void * V_62 )
{
struct V_1 * V_45 = V_62 ;
int V_63 = F_44 () ;
if ( V_45 -> V_3 . V_63 == V_63 )
F_39 ( V_45 -> V_59 ) ;
if ( F_45 ( V_64 , V_63 ) == V_45 -> V_59 )
F_45 ( V_64 , V_63 ) = NULL ;
F_46 ( & V_45 -> V_65 ) ;
V_45 -> V_3 . V_63 = - 1 ;
V_45 -> V_66 = 0 ;
}
static void F_47 ( struct V_1 * V_45 )
{
if ( V_45 -> V_3 . V_63 == - 1 )
return;
F_48 ( V_45 -> V_3 . V_63 , F_43 , V_45 , 1 ) ;
}
static inline void F_49 ( struct V_1 * V_45 )
{
if ( V_45 -> V_33 == 0 )
return;
if ( F_24 () )
F_36 ( V_67 , V_45 -> V_33 , 0 ) ;
}
static inline void F_50 ( void )
{
if ( F_25 () )
F_36 ( V_68 , 0 , 0 ) ;
}
static inline void F_51 ( struct V_1 * V_45 )
{
if ( F_24 () )
F_49 ( V_45 ) ;
else
F_50 () ;
}
static inline void F_52 ( void )
{
if ( F_23 () )
F_37 ( V_69 , 0 , 0 ) ;
}
static inline void F_53 ( T_4 V_56 )
{
if ( V_70 ) {
if ( F_22 () )
F_37 ( V_71 , V_56 , 0 ) ;
else
F_52 () ;
}
}
static inline void F_54 ( T_4 V_56 , T_5 V_57 )
{
if ( V_70 ) {
if ( F_21 () )
F_37 ( V_72 ,
V_56 , V_57 ) ;
else
F_53 ( V_56 ) ;
}
}
static unsigned long F_55 ( unsigned long V_73 )
{
unsigned long V_74 = 0 ;
asm volatile (__ex(ASM_VMX_VMREAD_RDX_RAX)
: "+a"(value) : "d"(field) : "cc");
return V_74 ;
}
static T_2 F_56 ( unsigned long V_73 )
{
return F_55 ( V_73 ) ;
}
static T_1 F_57 ( unsigned long V_73 )
{
return F_55 ( V_73 ) ;
}
static T_4 F_58 ( unsigned long V_73 )
{
#ifdef F_59
return F_55 ( V_73 ) ;
#else
return F_55 ( V_73 ) | ( ( T_4 ) F_55 ( V_73 + 1 ) << 32 ) ;
#endif
}
static T_7 void F_60 ( unsigned long V_73 , unsigned long V_74 )
{
F_41 ( V_61 L_3 ,
V_73 , V_74 , F_57 ( V_75 ) ) ;
F_61 () ;
}
static void F_62 ( unsigned long V_73 , unsigned long V_74 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_63 ( error ) )
F_60 ( V_73 , V_74 ) ;
}
static void F_64 ( unsigned long V_73 , T_2 V_74 )
{
F_62 ( V_73 , V_74 ) ;
}
static void F_65 ( unsigned long V_73 , T_1 V_74 )
{
F_62 ( V_73 , V_74 ) ;
}
static void F_66 ( unsigned long V_73 , T_4 V_74 )
{
F_62 ( V_73 , V_74 ) ;
#ifndef F_59
asm volatile ("");
F_62 ( V_73 + 1 , V_74 >> 32 ) ;
#endif
}
static void F_67 ( unsigned long V_73 , T_1 V_76 )
{
F_62 ( V_73 , F_55 ( V_73 ) & ~ V_76 ) ;
}
static void F_68 ( unsigned long V_73 , T_1 V_76 )
{
F_62 ( V_73 , F_55 ( V_73 ) | V_76 ) ;
}
static void F_69 ( struct V_1 * V_45 )
{
V_45 -> V_77 . V_78 = 0 ;
}
static bool F_70 ( struct V_1 * V_45 , unsigned V_79 ,
unsigned V_73 )
{
bool V_80 ;
T_1 V_76 = 1 << ( V_79 * V_81 + V_73 ) ;
if ( ! ( V_45 -> V_3 . V_82 . V_83 & ( 1 << V_84 ) ) ) {
V_45 -> V_3 . V_82 . V_83 |= ( 1 << V_84 ) ;
V_45 -> V_77 . V_78 = 0 ;
}
V_80 = V_45 -> V_77 . V_78 & V_76 ;
V_45 -> V_77 . V_78 |= V_76 ;
return V_80 ;
}
static T_2 F_71 ( struct V_1 * V_45 , unsigned V_79 )
{
T_2 * V_85 = & V_45 -> V_77 . V_79 [ V_79 ] . V_86 ;
if ( ! F_70 ( V_45 , V_79 , V_87 ) )
* V_85 = F_56 ( V_88 [ V_79 ] . V_86 ) ;
return * V_85 ;
}
static T_8 F_72 ( struct V_1 * V_45 , unsigned V_79 )
{
T_8 * V_85 = & V_45 -> V_77 . V_79 [ V_79 ] . V_89 ;
if ( ! F_70 ( V_45 , V_79 , V_90 ) )
* V_85 = F_55 ( V_88 [ V_79 ] . V_89 ) ;
return * V_85 ;
}
static T_1 F_73 ( struct V_1 * V_45 , unsigned V_79 )
{
T_1 * V_85 = & V_45 -> V_77 . V_79 [ V_79 ] . V_91 ;
if ( ! F_70 ( V_45 , V_79 , V_92 ) )
* V_85 = F_57 ( V_88 [ V_79 ] . V_91 ) ;
return * V_85 ;
}
static T_1 F_74 ( struct V_1 * V_45 , unsigned V_79 )
{
T_1 * V_85 = & V_45 -> V_77 . V_79 [ V_79 ] . V_93 ;
if ( ! F_70 ( V_45 , V_79 , V_94 ) )
* V_85 = F_57 ( V_88 [ V_79 ] . V_95 ) ;
return * V_85 ;
}
static void F_75 ( struct V_2 * V_3 )
{
T_1 V_96 ;
V_96 = ( 1u << V_9 ) | ( 1u << V_11 ) | ( 1u << V_13 ) |
( 1u << V_10 ) | ( 1u << V_97 ) ;
if ( ( V_3 -> V_98 &
( V_99 | V_100 ) ) ==
( V_99 | V_100 ) )
V_96 |= 1u << V_101 ;
if ( F_1 ( V_3 ) -> V_102 . V_103 )
V_96 = ~ 0 ;
if ( V_70 )
V_96 &= ~ ( 1u << V_9 ) ;
if ( V_3 -> V_104 )
V_96 &= ~ ( 1u << V_10 ) ;
F_65 ( V_105 , V_96 ) ;
}
static void F_76 ( struct V_1 * V_45 , unsigned V_46 )
{
unsigned V_47 ;
struct V_106 * V_107 = & V_45 -> V_106 ;
if ( V_46 == V_108 && V_109 ) {
F_67 ( V_110 , V_111 ) ;
F_67 ( V_112 , V_113 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_107 -> V_114 ; ++ V_47 )
if ( V_107 -> V_115 [ V_47 ] . V_51 == V_46 )
break;
if ( V_47 == V_107 -> V_114 )
return;
-- V_107 -> V_114 ;
V_107 -> V_115 [ V_47 ] = V_107 -> V_115 [ V_107 -> V_114 ] ;
V_107 -> V_116 [ V_47 ] = V_107 -> V_116 [ V_107 -> V_114 ] ;
F_65 ( V_117 , V_107 -> V_114 ) ;
F_65 ( V_118 , V_107 -> V_114 ) ;
}
static void F_77 ( struct V_1 * V_45 , unsigned V_46 ,
T_4 V_119 , T_4 V_120 )
{
unsigned V_47 ;
struct V_106 * V_107 = & V_45 -> V_106 ;
if ( V_46 == V_108 && V_109 ) {
F_66 ( V_121 , V_119 ) ;
F_66 ( V_122 , V_120 ) ;
F_68 ( V_110 , V_111 ) ;
F_68 ( V_112 , V_113 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_107 -> V_114 ; ++ V_47 )
if ( V_107 -> V_115 [ V_47 ] . V_51 == V_46 )
break;
if ( V_47 == V_107 -> V_114 ) {
++ V_107 -> V_114 ;
F_65 ( V_117 , V_107 -> V_114 ) ;
F_65 ( V_118 , V_107 -> V_114 ) ;
}
V_107 -> V_115 [ V_47 ] . V_51 = V_46 ;
V_107 -> V_115 [ V_47 ] . V_74 = V_119 ;
V_107 -> V_116 [ V_47 ] . V_51 = V_46 ;
V_107 -> V_116 [ V_47 ] . V_74 = V_120 ;
}
static void F_78 ( void )
{
struct V_123 * V_124 = & F_79 ( V_125 ) ;
struct V_126 * V_127 ;
V_127 = ( void * ) V_124 -> V_128 ;
V_127 [ V_129 ] . type = 9 ;
F_80 () ;
}
static bool F_81 ( struct V_1 * V_45 , int V_130 )
{
T_4 V_131 ;
T_4 V_132 ;
V_131 = V_45 -> V_3 . V_82 . V_133 ;
V_132 = V_134 | V_135 ;
#ifdef F_59
V_132 |= V_136 | V_137 ;
if ( V_131 & V_136 )
V_132 &= ~ ( T_4 ) V_135 ;
#endif
V_131 &= ~ V_132 ;
V_131 |= V_138 & V_132 ;
V_45 -> V_50 [ V_130 ] . V_139 = V_131 ;
V_45 -> V_50 [ V_130 ] . V_76 = ~ V_132 ;
F_76 ( V_45 , V_108 ) ;
if ( V_70 && ( ( V_45 -> V_3 . V_82 . V_133 ^ V_138 ) & V_134 ) ) {
V_131 = V_45 -> V_3 . V_82 . V_133 ;
if ( ! ( V_131 & V_136 ) )
V_131 &= ~ V_137 ;
F_77 ( V_45 , V_108 , V_131 , V_138 ) ;
return false ;
}
return true ;
}
static unsigned long F_82 ( T_2 V_86 )
{
struct V_123 * V_124 = & F_79 ( V_125 ) ;
struct V_126 * V_140 ;
unsigned long V_141 ;
unsigned long V_142 ;
if ( ! ( V_86 & ~ 3 ) )
return 0 ;
V_141 = V_124 -> V_128 ;
if ( V_86 & 4 ) {
T_2 V_143 = F_83 () ;
if ( ! ( V_143 & ~ 3 ) )
return 0 ;
V_141 = F_82 ( V_143 ) ;
}
V_140 = (struct V_126 * ) ( V_141 + ( V_86 & ~ 7 ) ) ;
V_142 = F_84 ( V_140 ) ;
#ifdef F_59
if ( V_140 -> V_144 == 0 && ( V_140 -> type == 2 || V_140 -> type == 9 || V_140 -> type == 11 ) )
V_142 |= ( ( unsigned long ) ( (struct V_145 * ) V_140 ) -> V_146 ) << 32 ;
#endif
return V_142 ;
}
static inline unsigned long F_85 ( void )
{
T_2 V_147 ;
asm("str %0" : "=g"(tr));
return F_82 ( V_147 ) ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
int V_47 ;
if ( V_45 -> V_148 . V_149 )
return;
V_45 -> V_148 . V_149 = 1 ;
V_45 -> V_148 . V_150 = F_83 () ;
V_45 -> V_148 . V_151 = V_45 -> V_148 . V_150 ;
F_87 ( V_152 , V_45 -> V_148 . V_153 ) ;
if ( ! ( V_45 -> V_148 . V_153 & 7 ) ) {
F_64 ( V_154 , V_45 -> V_148 . V_153 ) ;
V_45 -> V_148 . V_155 = 0 ;
} else {
F_64 ( V_154 , 0 ) ;
V_45 -> V_148 . V_155 = 1 ;
}
F_87 ( V_156 , V_45 -> V_148 . V_157 ) ;
if ( ! ( V_45 -> V_148 . V_157 & 7 ) )
F_64 ( V_158 , V_45 -> V_148 . V_157 ) ;
else {
F_64 ( V_158 , 0 ) ;
V_45 -> V_148 . V_151 = 1 ;
}
#ifdef F_59
F_62 ( V_159 , F_88 ( V_160 ) ) ;
F_62 ( V_161 , F_88 ( V_162 ) ) ;
#else
F_62 ( V_159 , F_82 ( V_45 -> V_148 . V_153 ) ) ;
F_62 ( V_161 , F_82 ( V_45 -> V_148 . V_157 ) ) ;
#endif
#ifdef F_59
F_89 ( V_163 , V_45 -> V_164 ) ;
if ( F_90 ( & V_45 -> V_3 ) )
F_91 ( V_163 , V_45 -> V_165 ) ;
#endif
for ( V_47 = 0 ; V_47 < V_45 -> V_166 ; ++ V_47 )
F_92 ( V_45 -> V_50 [ V_47 ] . V_51 ,
V_45 -> V_50 [ V_47 ] . V_139 ,
V_45 -> V_50 [ V_47 ] . V_76 ) ;
}
static void F_93 ( struct V_1 * V_45 )
{
if ( ! V_45 -> V_148 . V_149 )
return;
++ V_45 -> V_3 . V_167 . V_168 ;
V_45 -> V_148 . V_149 = 0 ;
#ifdef F_59
if ( F_90 ( & V_45 -> V_3 ) )
F_89 ( V_163 , V_45 -> V_165 ) ;
#endif
if ( V_45 -> V_148 . V_151 ) {
F_94 ( V_45 -> V_148 . V_150 ) ;
#ifdef F_59
F_95 ( V_45 -> V_148 . V_157 ) ;
#else
F_96 ( V_156 , V_45 -> V_148 . V_157 ) ;
#endif
}
if ( V_45 -> V_148 . V_155 )
F_96 ( V_152 , V_45 -> V_148 . V_153 ) ;
F_78 () ;
#ifdef F_59
F_91 ( V_163 , V_45 -> V_164 ) ;
#endif
if ( F_97 () -> V_169 & V_170 )
F_98 () ;
F_99 ( & F_79 ( V_125 ) ) ;
}
static void F_100 ( struct V_1 * V_45 )
{
F_101 () ;
F_93 ( V_45 ) ;
F_102 () ;
}
static void F_103 ( struct V_2 * V_3 , int V_63 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_4 V_60 = F_40 ( F_45 ( V_171 , V_63 ) ) ;
if ( ! V_172 )
F_104 ( V_60 ) ;
else if ( V_3 -> V_63 != V_63 )
F_47 ( V_45 ) ;
if ( F_45 ( V_64 , V_63 ) != V_45 -> V_59 ) {
F_45 ( V_64 , V_63 ) = V_45 -> V_59 ;
F_42 ( V_45 -> V_59 ) ;
}
if ( V_3 -> V_63 != V_63 ) {
struct V_123 * V_124 = & F_79 ( V_125 ) ;
unsigned long V_173 ;
F_105 ( V_174 , V_3 ) ;
F_106 () ;
F_107 ( & V_45 -> V_65 ,
& F_45 ( V_175 , V_63 ) ) ;
F_108 () ;
F_62 ( V_176 , F_85 () ) ;
F_62 ( V_177 , V_124 -> V_128 ) ;
F_89 ( V_178 , V_173 ) ;
F_62 ( V_179 , V_173 ) ;
}
}
static void F_109 ( struct V_2 * V_3 )
{
F_93 ( F_1 ( V_3 ) ) ;
if ( ! V_172 ) {
F_43 ( F_1 ( V_3 ) ) ;
F_110 () ;
}
}
static void F_111 ( struct V_2 * V_3 )
{
T_8 V_180 ;
if ( V_3 -> V_104 )
return;
V_3 -> V_104 = 1 ;
V_180 = F_55 ( V_181 ) ;
V_180 &= ~ ( V_182 | V_183 ) ;
V_180 |= F_112 ( V_3 , V_182 | V_183 ) ;
F_62 ( V_181 , V_180 ) ;
F_75 ( V_3 ) ;
V_3 -> V_82 . V_184 = V_182 ;
F_62 ( V_185 , ~ V_3 -> V_82 . V_184 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
F_114 ( V_3 ) ;
F_68 ( V_181 , V_182 | V_183 ) ;
F_75 ( V_3 ) ;
V_3 -> V_82 . V_184 = 0 ;
F_62 ( V_185 , ~ V_3 -> V_82 . V_184 ) ;
F_62 ( V_186 , V_3 -> V_82 . V_180 ) ;
}
static unsigned long F_115 ( struct V_2 * V_3 )
{
unsigned long V_187 , V_188 ;
if ( ! F_116 ( V_189 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ) {
F_117 ( V_189 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
V_187 = F_55 ( V_190 ) ;
if ( F_1 ( V_3 ) -> V_102 . V_103 ) {
V_187 &= V_191 ;
V_188 = F_1 ( V_3 ) -> V_102 . V_188 ;
V_187 |= V_188 & ~ V_191 ;
}
F_1 ( V_3 ) -> V_187 = V_187 ;
}
return F_1 ( V_3 ) -> V_187 ;
}
static void F_118 ( struct V_2 * V_3 , unsigned long V_187 )
{
F_117 ( V_189 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
F_119 ( V_192 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
F_1 ( V_3 ) -> V_187 = V_187 ;
if ( F_1 ( V_3 ) -> V_102 . V_103 ) {
F_1 ( V_3 ) -> V_102 . V_188 = V_187 ;
V_187 |= V_193 | V_194 ;
}
F_62 ( V_190 , V_187 ) ;
}
static T_1 F_120 ( struct V_2 * V_3 , int V_76 )
{
T_1 V_195 = F_57 ( V_196 ) ;
int V_80 = 0 ;
if ( V_195 & V_197 )
V_80 |= V_198 ;
if ( V_195 & V_199 )
V_80 |= V_200 ;
return V_80 & V_76 ;
}
static void F_121 ( struct V_2 * V_3 , int V_76 )
{
T_1 V_201 = F_57 ( V_196 ) ;
T_1 V_195 = V_201 ;
V_195 &= ~ ( V_197 | V_199 ) ;
if ( V_76 & V_200 )
V_195 |= V_199 ;
else if ( V_76 & V_198 )
V_195 |= V_197 ;
if ( ( V_195 != V_201 ) )
F_65 ( V_196 , V_195 ) ;
}
static void F_122 ( struct V_2 * V_3 )
{
unsigned long V_202 ;
V_202 = F_123 ( V_3 ) ;
V_202 += F_57 ( V_203 ) ;
F_124 ( V_3 , V_202 ) ;
F_121 ( V_3 , 0 ) ;
}
static void F_125 ( struct V_2 * V_3 )
{
if ( ! V_204 &&
F_57 ( V_205 ) == V_206 )
F_65 ( V_205 , V_207 ) ;
}
static void F_126 ( struct V_2 * V_3 , unsigned V_114 ,
bool V_208 , T_1 V_209 ,
bool V_210 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_1 V_4 = V_114 | V_7 ;
if ( V_208 ) {
F_65 ( V_211 , V_209 ) ;
V_4 |= V_212 ;
}
if ( V_45 -> V_102 . V_103 ) {
int V_213 = 0 ;
if ( F_127 ( V_114 ) )
V_213 = V_3 -> V_82 . V_214 ;
if ( F_128 ( V_3 , V_114 , V_213 ) != V_215 )
F_105 ( V_216 , V_3 ) ;
return;
}
if ( F_127 ( V_114 ) ) {
F_65 ( V_217 ,
V_45 -> V_3 . V_82 . V_214 ) ;
V_4 |= V_218 ;
} else
V_4 |= V_8 ;
F_65 ( V_219 , V_4 ) ;
F_125 ( V_3 ) ;
}
static bool F_129 ( void )
{
return F_31 () ;
}
static void F_130 ( struct V_1 * V_45 , int V_220 , int V_221 )
{
struct V_58 V_222 ;
V_222 = V_45 -> V_50 [ V_221 ] ;
V_45 -> V_50 [ V_221 ] = V_45 -> V_50 [ V_220 ] ;
V_45 -> V_50 [ V_220 ] = V_222 ;
}
static void F_131 ( struct V_1 * V_45 )
{
int V_166 , V_51 ;
unsigned long * V_223 ;
F_100 ( V_45 ) ;
V_166 = 0 ;
#ifdef F_59
if ( F_90 ( & V_45 -> V_3 ) ) {
V_51 = F_35 ( V_45 , V_224 ) ;
if ( V_51 >= 0 )
F_130 ( V_45 , V_51 , V_166 ++ ) ;
V_51 = F_35 ( V_45 , V_225 ) ;
if ( V_51 >= 0 )
F_130 ( V_45 , V_51 , V_166 ++ ) ;
V_51 = F_35 ( V_45 , V_226 ) ;
if ( V_51 >= 0 )
F_130 ( V_45 , V_51 , V_166 ++ ) ;
V_51 = F_35 ( V_45 , V_227 ) ;
if ( V_51 >= 0 && V_45 -> V_228 )
F_130 ( V_45 , V_51 , V_166 ++ ) ;
V_51 = F_35 ( V_45 , V_229 ) ;
if ( ( V_51 >= 0 ) && ( V_45 -> V_3 . V_82 . V_133 & V_135 ) )
F_130 ( V_45 , V_51 , V_166 ++ ) ;
}
#endif
V_51 = F_35 ( V_45 , V_108 ) ;
if ( V_51 >= 0 && F_81 ( V_45 , V_51 ) )
F_130 ( V_45 , V_51 , V_166 ++ ) ;
V_45 -> V_166 = V_166 ;
if ( F_8 () ) {
if ( F_90 ( & V_45 -> V_3 ) )
V_223 = V_230 ;
else
V_223 = V_231 ;
F_66 ( V_232 , F_40 ( V_223 ) ) ;
}
}
static T_4 F_132 ( void )
{
T_4 V_233 , V_234 ;
F_133 ( V_233 ) ;
V_234 = F_58 ( V_235 ) ;
return V_233 + V_234 ;
}
static void F_134 ( struct V_2 * V_3 , T_1 V_236 )
{
}
static void F_135 ( struct V_2 * V_3 , T_4 V_237 )
{
F_66 ( V_235 , V_237 ) ;
}
static void F_136 ( struct V_2 * V_3 , T_9 V_238 )
{
T_4 V_237 = F_58 ( V_235 ) ;
F_66 ( V_235 , V_237 + V_238 ) ;
}
static T_4 F_137 ( struct V_2 * V_3 , T_4 V_239 )
{
return V_239 - F_138 () ;
}
static int F_139 ( struct V_2 * V_3 , T_1 V_240 , T_4 * V_241 )
{
T_4 V_139 ;
struct V_58 * V_46 ;
if ( ! V_241 ) {
F_41 ( V_61 L_4 ) ;
return - V_242 ;
}
switch ( V_240 ) {
#ifdef F_59
case V_160 :
V_139 = F_55 ( V_243 ) ;
break;
case V_162 :
V_139 = F_55 ( V_244 ) ;
break;
case V_163 :
F_100 ( F_1 ( V_3 ) ) ;
V_139 = F_1 ( V_3 ) -> V_165 ;
break;
#endif
case V_108 :
return F_140 ( V_3 , V_240 , V_241 ) ;
case V_245 :
V_139 = F_132 () ;
break;
case V_246 :
V_139 = F_57 ( V_247 ) ;
break;
case V_248 :
V_139 = F_55 ( V_249 ) ;
break;
case V_178 :
V_139 = F_55 ( V_250 ) ;
break;
case V_227 :
if ( ! F_1 ( V_3 ) -> V_228 )
return 1 ;
default:
F_100 ( F_1 ( V_3 ) ) ;
V_46 = F_38 ( F_1 ( V_3 ) , V_240 ) ;
if ( V_46 ) {
F_100 ( F_1 ( V_3 ) ) ;
V_139 = V_46 -> V_139 ;
break;
}
return F_140 ( V_3 , V_240 , V_241 ) ;
}
* V_241 = V_139 ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 , T_1 V_240 , T_4 V_139 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_58 * V_46 ;
int V_80 = 0 ;
switch ( V_240 ) {
case V_108 :
F_100 ( V_45 ) ;
V_80 = F_142 ( V_3 , V_240 , V_139 ) ;
break;
#ifdef F_59
case V_160 :
F_69 ( V_45 ) ;
F_62 ( V_243 , V_139 ) ;
break;
case V_162 :
F_69 ( V_45 ) ;
F_62 ( V_244 , V_139 ) ;
break;
case V_163 :
F_100 ( V_45 ) ;
V_45 -> V_165 = V_139 ;
break;
#endif
case V_246 :
F_65 ( V_247 , V_139 ) ;
break;
case V_248 :
F_62 ( V_249 , V_139 ) ;
break;
case V_178 :
F_62 ( V_250 , V_139 ) ;
break;
case V_245 :
F_143 ( V_3 , V_139 ) ;
break;
case V_251 :
if ( V_14 . V_252 & V_253 ) {
F_66 ( V_254 , V_139 ) ;
V_3 -> V_82 . V_255 = V_139 ;
break;
}
V_80 = F_142 ( V_3 , V_240 , V_139 ) ;
break;
case V_227 :
if ( ! V_45 -> V_228 )
return 1 ;
if ( ( V_139 >> 32 ) != 0 )
return 1 ;
default:
V_46 = F_38 ( V_45 , V_240 ) ;
if ( V_46 ) {
F_100 ( V_45 ) ;
V_46 -> V_139 = V_139 ;
break;
}
V_80 = F_142 ( V_3 , V_240 , V_139 ) ;
}
return V_80 ;
}
static void F_144 ( struct V_2 * V_3 , enum V_256 V_257 )
{
F_117 ( V_257 , ( unsigned long * ) & V_3 -> V_82 . V_83 ) ;
switch ( V_257 ) {
case V_258 :
V_3 -> V_82 . V_259 [ V_258 ] = F_55 ( V_260 ) ;
break;
case V_261 :
V_3 -> V_82 . V_259 [ V_261 ] = F_55 ( V_262 ) ;
break;
case V_263 :
if ( V_70 )
F_145 ( V_3 ) ;
break;
default:
break;
}
}
static void F_146 ( struct V_2 * V_3 , struct V_264 * V_265 )
{
if ( V_3 -> V_98 & V_266 )
F_62 ( V_267 , V_265 -> V_82 . V_268 [ 7 ] ) ;
else
F_62 ( V_267 , V_3 -> V_82 . V_269 ) ;
F_75 ( V_3 ) ;
}
static T_10 int F_147 ( void )
{
return F_148 () ;
}
static T_10 int F_149 ( void )
{
T_4 V_46 ;
F_89 ( V_270 , V_46 ) ;
if ( V_46 & V_271 ) {
if ( ! ( V_46 & V_272 )
&& F_150 () )
return 1 ;
if ( ! ( V_46 & V_273 )
&& ( V_46 & V_272 )
&& ! F_150 () ) {
F_41 ( V_274 L_5
L_6 ) ;
return 1 ;
}
if ( ! ( V_46 & V_273 )
&& ! F_150 () )
return 1 ;
}
return 0 ;
}
static void F_104 ( T_4 V_275 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_151 ( void * V_276 )
{
int V_63 = F_44 () ;
T_4 V_60 = F_40 ( F_45 ( V_171 , V_63 ) ) ;
T_4 V_277 , V_278 ;
if ( F_152 () & V_279 )
return - V_280 ;
F_153 ( & F_45 ( V_175 , V_63 ) ) ;
F_89 ( V_270 , V_277 ) ;
V_278 = V_271 ;
V_278 |= V_273 ;
if ( F_150 () )
V_278 |= V_272 ;
if ( ( V_277 & V_278 ) != V_278 ) {
F_91 ( V_270 , V_277 | V_278 ) ;
}
F_154 ( F_152 () | V_279 ) ;
if ( V_172 ) {
F_104 ( V_60 ) ;
F_52 () ;
}
F_155 ( & F_79 ( V_125 ) ) ;
return 0 ;
}
static void F_156 ( void )
{
int V_63 = F_44 () ;
struct V_1 * V_45 , * V_281 ;
F_157 (vmx, n, &per_cpu(vcpus_on_cpu, cpu),
local_vcpus_link)
F_43 ( V_45 ) ;
}
static void F_110 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_158 ( void * V_276 )
{
if ( V_172 ) {
F_156 () ;
F_110 () ;
}
F_154 ( F_152 () & ~ V_279 ) ;
}
static T_10 int F_159 ( T_1 V_282 , T_1 V_283 ,
T_1 V_46 , T_1 * V_284 )
{
T_1 V_285 , V_286 ;
T_1 V_287 = V_282 | V_283 ;
F_160 ( V_46 , V_285 , V_286 ) ;
V_287 &= V_286 ;
V_287 |= V_285 ;
if ( V_282 & ~ V_287 )
return - V_288 ;
* V_284 = V_287 ;
return 0 ;
}
static T_10 bool F_161 ( T_1 V_46 , T_1 V_287 )
{
T_1 V_285 , V_286 ;
F_160 ( V_46 , V_285 , V_286 ) ;
return V_286 & V_287 ;
}
static T_10 int F_162 ( struct V_14 * V_289 )
{
T_1 V_285 , V_286 ;
T_1 V_290 , V_291 , V_292 , V_293 ;
T_1 V_294 = 0 ;
T_1 V_295 = 0 ;
T_1 V_296 = 0 ;
T_1 V_297 = 0 ;
T_1 V_298 = 0 ;
V_290 = V_299 | V_300 ;
V_291 = V_43 ;
if ( F_159 ( V_290 , V_291 , V_301 ,
& V_294 ) < 0 )
return - V_288 ;
V_290 =
#ifdef F_59
V_302 |
V_303 |
#endif
V_304 |
V_305 |
V_306 |
V_307 |
V_308 |
V_309 |
V_310 |
V_311 ;
if ( V_204 )
V_290 |= V_312 ;
V_291 = V_17 |
V_16 |
V_19 ;
if ( F_159 ( V_290 , V_291 , V_313 ,
& V_295 ) < 0 )
return - V_288 ;
#ifdef F_59
if ( ( V_295 & V_17 ) )
V_295 &= ~ V_302 &
~ V_303 ;
#endif
if ( V_295 & V_19 ) {
V_292 = 0 ;
V_293 = V_21 |
V_44 |
V_40 |
V_36 |
V_37 |
V_38 |
V_41 ;
if ( F_159 ( V_292 , V_293 ,
V_314 ,
& V_296 ) < 0 )
return - V_288 ;
}
#ifndef F_59
if ( ! ( V_296 &
V_21 ) )
V_295 &= ~ V_17 ;
#endif
if ( V_296 & V_36 ) {
V_295 &= ~ ( V_304 |
V_305 |
V_311 ) ;
F_160 ( V_315 ,
V_22 . V_23 , V_22 . V_33 ) ;
}
V_290 = 0 ;
#ifdef F_59
V_290 |= V_316 ;
#endif
V_291 = V_317 | V_318 ;
if ( F_159 ( V_290 , V_291 , V_319 ,
& V_297 ) < 0 )
return - V_288 ;
V_290 = 0 ;
V_291 = V_253 ;
if ( F_159 ( V_290 , V_291 , V_320 ,
& V_298 ) < 0 )
return - V_288 ;
F_160 ( V_321 , V_285 , V_286 ) ;
if ( ( V_286 & 0x1fff ) > V_322 )
return - V_288 ;
#ifdef F_59
if ( V_286 & ( 1u << 16 ) )
return - V_288 ;
#endif
if ( ( ( V_286 >> 18 ) & 15 ) != 6 )
return - V_288 ;
V_289 -> V_323 = V_286 & 0x1fff ;
V_289 -> V_324 = F_163 ( V_14 . V_323 ) ;
V_289 -> V_325 = V_285 ;
V_289 -> V_42 = V_294 ;
V_289 -> V_15 = V_295 ;
V_289 -> V_20 = V_296 ;
V_289 -> V_326 = V_297 ;
V_289 -> V_252 = V_298 ;
V_109 =
F_161 ( V_320 ,
V_111 )
&& F_161 ( V_319 ,
V_113 ) ;
return 0 ;
}
static struct V_59 * F_164 ( int V_63 )
{
int V_327 = F_165 ( V_63 ) ;
struct V_328 * V_329 ;
struct V_59 * V_59 ;
V_329 = F_166 ( V_327 , V_330 , V_14 . V_324 ) ;
if ( ! V_329 )
return NULL ;
V_59 = F_167 ( V_329 ) ;
memset ( V_59 , 0 , V_14 . V_323 ) ;
V_59 -> V_325 = V_14 . V_325 ;
return V_59 ;
}
static struct V_59 * F_168 ( void )
{
return F_164 ( F_44 () ) ;
}
static void F_169 ( struct V_59 * V_59 )
{
F_170 ( ( unsigned long ) V_59 , V_14 . V_324 ) ;
}
static void F_171 ( void )
{
int V_63 ;
F_172 (cpu) {
F_169 ( F_45 ( V_171 , V_63 ) ) ;
F_45 ( V_171 , V_63 ) = NULL ;
}
}
static T_10 int F_173 ( void )
{
int V_63 ;
F_172 (cpu) {
struct V_59 * V_59 ;
V_59 = F_164 ( V_63 ) ;
if ( ! V_59 ) {
F_171 () ;
return - V_331 ;
}
F_45 ( V_171 , V_63 ) = V_59 ;
}
return 0 ;
}
static T_10 int F_174 ( void )
{
if ( F_162 ( & V_14 ) < 0 )
return - V_288 ;
if ( F_175 ( V_332 ) )
F_176 ( V_134 ) ;
if ( ! F_30 () )
V_333 = 0 ;
if ( ! F_26 () ||
! F_20 () ) {
V_70 = 0 ;
V_334 = 0 ;
}
if ( ! F_27 () )
V_334 = 0 ;
if ( ! F_14 () )
V_39 = 0 ;
if ( ! F_9 () )
V_335 -> V_336 = NULL ;
if ( V_70 && ! F_18 () )
F_177 () ;
if ( ! F_28 () )
V_337 = 0 ;
return F_173 () ;
}
static T_11 void F_178 ( void )
{
F_171 () ;
}
static void F_179 ( int V_79 , struct V_338 * V_339 )
{
struct V_340 * V_341 = & V_88 [ V_79 ] ;
if ( F_55 ( V_341 -> V_89 ) == V_339 -> V_89 && ( V_339 -> V_89 & V_342 ) ) {
F_64 ( V_341 -> V_86 , V_339 -> V_86 ) ;
F_62 ( V_341 -> V_89 , V_339 -> V_89 ) ;
F_65 ( V_341 -> V_91 , V_339 -> V_91 ) ;
F_65 ( V_341 -> V_95 , V_339 -> V_93 ) ;
} else {
T_1 V_343 = ( F_56 ( V_341 -> V_86 ) & V_344 )
<< V_345 ;
F_65 ( V_341 -> V_95 , 0x93 | V_343 ) ;
}
}
static void F_180 ( struct V_2 * V_3 )
{
unsigned long V_346 ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
V_45 -> V_347 = 1 ;
V_45 -> V_102 . V_103 = 0 ;
F_69 ( V_45 ) ;
F_64 ( V_348 , V_45 -> V_102 . V_147 . V_86 ) ;
F_62 ( V_349 , V_45 -> V_102 . V_147 . V_89 ) ;
F_65 ( V_350 , V_45 -> V_102 . V_147 . V_91 ) ;
F_65 ( V_351 , V_45 -> V_102 . V_147 . V_93 ) ;
V_346 = F_55 ( V_190 ) ;
V_346 &= V_191 ;
V_346 |= V_45 -> V_102 . V_188 & ~ V_191 ;
F_62 ( V_190 , V_346 ) ;
F_62 ( V_352 , ( F_55 ( V_352 ) & ~ V_353 ) |
( F_55 ( V_354 ) & V_353 ) ) ;
F_75 ( V_3 ) ;
if ( V_355 )
return;
F_179 ( V_356 , & V_45 -> V_102 . V_357 ) ;
F_179 ( V_358 , & V_45 -> V_102 . V_359 ) ;
F_179 ( V_360 , & V_45 -> V_102 . V_156 ) ;
F_179 ( V_361 , & V_45 -> V_102 . V_152 ) ;
F_69 ( V_45 ) ;
F_64 ( V_362 , 0 ) ;
F_65 ( V_363 , 0x93 ) ;
F_64 ( V_364 ,
F_56 ( V_364 ) & ~ V_344 ) ;
F_65 ( V_365 , 0x9b ) ;
}
static T_3 F_181 ( struct V_18 * V_18 )
{
if ( ! V_18 -> V_82 . V_366 ) {
struct V_367 * V_368 ;
T_12 V_369 ;
V_368 = V_367 ( V_18 ) ;
V_369 = V_368 -> V_370 [ 0 ] . V_369 +
V_18 -> V_370 -> V_370 [ 0 ] . V_371 - 3 ;
return V_369 << V_372 ;
}
return V_18 -> V_82 . V_366 ;
}
static void F_182 ( int V_79 , struct V_338 * V_339 )
{
struct V_340 * V_341 = & V_88 [ V_79 ] ;
V_339 -> V_86 = F_56 ( V_341 -> V_86 ) ;
V_339 -> V_89 = F_55 ( V_341 -> V_89 ) ;
V_339 -> V_91 = F_57 ( V_341 -> V_91 ) ;
V_339 -> V_93 = F_57 ( V_341 -> V_95 ) ;
F_64 ( V_341 -> V_86 , V_339 -> V_89 >> 4 ) ;
F_65 ( V_341 -> V_89 , V_339 -> V_89 & 0xffff0 ) ;
F_65 ( V_341 -> V_91 , 0xffff ) ;
F_65 ( V_341 -> V_95 , 0xf3 ) ;
if ( V_339 -> V_89 & 0xf )
F_183 ( V_274 L_7
L_8 ,
V_79 ) ;
}
static void F_184 ( struct V_2 * V_3 )
{
unsigned long V_346 ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
if ( V_334 )
return;
V_45 -> V_347 = 1 ;
V_45 -> V_102 . V_103 = 1 ;
if ( ! V_3 -> V_18 -> V_82 . V_366 ) {
F_183 ( V_274 L_9
L_10 ) ;
F_185 ( & V_3 -> V_18 -> V_373 , V_3 -> V_374 ) ;
F_186 ( V_3 -> V_18 , 0xfeffd000 ) ;
V_3 -> V_374 = F_187 ( & V_3 -> V_18 -> V_373 ) ;
}
F_69 ( V_45 ) ;
V_45 -> V_102 . V_147 . V_86 = F_56 ( V_348 ) ;
V_45 -> V_102 . V_147 . V_89 = F_55 ( V_349 ) ;
F_62 ( V_349 , F_181 ( V_3 -> V_18 ) ) ;
V_45 -> V_102 . V_147 . V_91 = F_57 ( V_350 ) ;
F_65 ( V_350 , V_375 - 1 ) ;
V_45 -> V_102 . V_147 . V_93 = F_57 ( V_351 ) ;
F_65 ( V_351 , 0x008b ) ;
V_346 = F_55 ( V_190 ) ;
V_45 -> V_102 . V_188 = V_346 ;
V_346 |= V_193 | V_194 ;
F_62 ( V_190 , V_346 ) ;
F_62 ( V_352 , F_55 ( V_352 ) | V_353 ) ;
F_75 ( V_3 ) ;
if ( V_355 )
goto V_376;
F_64 ( V_362 , F_55 ( V_377 ) >> 4 ) ;
F_65 ( V_378 , 0xffff ) ;
F_65 ( V_363 , 0xf3 ) ;
F_65 ( V_365 , 0xf3 ) ;
F_65 ( V_379 , 0xffff ) ;
if ( F_55 ( V_380 ) == 0xffff0000 )
F_62 ( V_380 , 0xf0000 ) ;
F_64 ( V_364 , F_55 ( V_380 ) >> 4 ) ;
F_182 ( V_356 , & V_45 -> V_102 . V_357 ) ;
F_182 ( V_358 , & V_45 -> V_102 . V_359 ) ;
F_182 ( V_360 , & V_45 -> V_102 . V_156 ) ;
F_182 ( V_361 , & V_45 -> V_102 . V_152 ) ;
V_376:
F_188 ( V_3 ) ;
}
static void F_189 ( struct V_2 * V_3 , T_4 V_133 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_58 * V_46 = F_38 ( V_45 , V_108 ) ;
if ( ! V_46 )
return;
F_100 ( F_1 ( V_3 ) ) ;
V_3 -> V_82 . V_133 = V_133 ;
if ( V_133 & V_136 ) {
F_65 ( V_110 ,
F_57 ( V_110 ) |
V_381 ) ;
V_46 -> V_139 = V_133 ;
} else {
F_65 ( V_110 ,
F_57 ( V_110 ) &
~ V_381 ) ;
V_46 -> V_139 = V_133 & ~ V_137 ;
}
F_131 ( V_45 ) ;
}
static void F_190 ( struct V_2 * V_3 )
{
T_1 V_382 ;
F_69 ( F_1 ( V_3 ) ) ;
V_382 = F_57 ( V_351 ) ;
if ( ( V_382 & V_383 ) != V_384 ) {
F_41 ( V_385 L_11 ,
V_386 ) ;
F_65 ( V_351 ,
( V_382 & ~ V_383 )
| V_384 ) ;
}
F_189 ( V_3 , V_3 -> V_82 . V_133 | V_136 ) ;
}
static void F_191 ( struct V_2 * V_3 )
{
F_65 ( V_110 ,
F_57 ( V_110 )
& ~ V_381 ) ;
F_189 ( V_3 , V_3 -> V_82 . V_133 & ~ V_136 ) ;
}
static void F_192 ( struct V_2 * V_3 )
{
F_51 ( F_1 ( V_3 ) ) ;
if ( V_70 ) {
if ( ! F_193 ( V_3 -> V_82 . V_387 . V_388 ) )
return;
F_53 ( F_194 ( V_3 -> V_82 . V_387 . V_388 ) ) ;
}
}
static void F_114 ( struct V_2 * V_3 )
{
T_8 V_184 = V_3 -> V_82 . V_184 ;
V_3 -> V_82 . V_180 &= ~ V_184 ;
V_3 -> V_82 . V_180 |= F_55 ( V_181 ) & V_184 ;
}
static void F_195 ( struct V_2 * V_3 )
{
if ( V_70 && F_196 ( V_3 ) )
V_3 -> V_82 . V_389 = F_55 ( V_390 ) ;
F_117 ( V_391 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
}
static void F_197 ( struct V_2 * V_3 )
{
T_8 V_392 = V_3 -> V_82 . V_392 ;
V_3 -> V_82 . V_393 &= ~ V_392 ;
V_3 -> V_82 . V_393 |= F_55 ( V_352 ) & V_392 ;
}
static void F_198 ( struct V_2 * V_3 )
{
if ( ! F_116 ( V_263 ,
( unsigned long * ) & V_3 -> V_82 . V_394 ) )
return;
if ( F_196 ( V_3 ) && F_199 ( V_3 ) && ! F_90 ( V_3 ) ) {
F_66 ( V_395 , V_3 -> V_82 . V_387 . V_396 [ 0 ] ) ;
F_66 ( V_397 , V_3 -> V_82 . V_387 . V_396 [ 1 ] ) ;
F_66 ( V_398 , V_3 -> V_82 . V_387 . V_396 [ 2 ] ) ;
F_66 ( V_399 , V_3 -> V_82 . V_387 . V_396 [ 3 ] ) ;
}
}
static void F_145 ( struct V_2 * V_3 )
{
if ( F_196 ( V_3 ) && F_199 ( V_3 ) && ! F_90 ( V_3 ) ) {
V_3 -> V_82 . V_387 . V_396 [ 0 ] = F_58 ( V_395 ) ;
V_3 -> V_82 . V_387 . V_396 [ 1 ] = F_58 ( V_397 ) ;
V_3 -> V_82 . V_387 . V_396 [ 2 ] = F_58 ( V_398 ) ;
V_3 -> V_82 . V_387 . V_396 [ 3 ] = F_58 ( V_399 ) ;
}
F_117 ( V_263 ,
( unsigned long * ) & V_3 -> V_82 . V_83 ) ;
F_117 ( V_263 ,
( unsigned long * ) & V_3 -> V_82 . V_394 ) ;
}
static void F_200 ( unsigned long * V_400 ,
unsigned long V_180 ,
struct V_2 * V_3 )
{
if ( ! F_116 ( V_391 , ( T_8 * ) & V_3 -> V_82 . V_83 ) )
F_195 ( V_3 ) ;
if ( ! ( V_180 & V_401 ) ) {
F_65 ( V_402 ,
F_57 ( V_402 ) |
( V_304 |
V_305 ) ) ;
V_3 -> V_82 . V_180 = V_180 ;
F_201 ( V_3 , F_202 ( V_3 ) ) ;
} else if ( ! F_196 ( V_3 ) ) {
F_65 ( V_402 ,
F_57 ( V_402 ) &
~ ( V_304 |
V_305 ) ) ;
V_3 -> V_82 . V_180 = V_180 ;
F_201 ( V_3 , F_202 ( V_3 ) ) ;
}
if ( ! ( V_180 & V_403 ) )
* V_400 &= ~ V_403 ;
}
static void F_203 ( struct V_2 * V_3 , unsigned long V_180 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
unsigned long V_400 ;
if ( V_334 )
V_400 = ( V_180 & ~ V_404 )
| V_405 ;
else
V_400 = ( V_180 & ~ V_406 ) | V_407 ;
if ( V_45 -> V_102 . V_103 && ( V_180 & V_408 ) )
F_180 ( V_3 ) ;
if ( ! V_45 -> V_102 . V_103 && ! ( V_180 & V_408 ) )
F_184 ( V_3 ) ;
#ifdef F_59
if ( V_3 -> V_82 . V_133 & V_137 ) {
if ( ! F_196 ( V_3 ) && ( V_180 & V_401 ) )
F_190 ( V_3 ) ;
if ( F_196 ( V_3 ) && ! ( V_180 & V_401 ) )
F_191 ( V_3 ) ;
}
#endif
if ( V_70 )
F_200 ( & V_400 , V_180 , V_3 ) ;
if ( ! V_3 -> V_104 )
V_400 |= V_182 | V_183 ;
F_62 ( V_186 , V_180 ) ;
F_62 ( V_181 , V_400 ) ;
V_3 -> V_82 . V_180 = V_180 ;
F_119 ( V_192 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
}
static T_4 F_194 ( unsigned long V_388 )
{
T_4 V_56 ;
V_56 = V_409 |
V_410 << V_411 ;
V_56 |= ( V_388 & V_412 ) ;
return V_56 ;
}
static void F_204 ( struct V_2 * V_3 , unsigned long V_389 )
{
unsigned long V_413 ;
T_4 V_56 ;
V_413 = V_389 ;
if ( V_70 ) {
V_56 = F_194 ( V_389 ) ;
F_66 ( V_414 , V_56 ) ;
V_413 = F_196 ( V_3 ) ? F_205 ( V_3 ) :
V_3 -> V_18 -> V_82 . V_415 ;
F_198 ( V_3 ) ;
}
F_192 ( V_3 ) ;
F_62 ( V_390 , V_413 ) ;
}
static void F_201 ( struct V_2 * V_3 , unsigned long V_393 )
{
unsigned long V_416 = V_393 | ( F_1 ( V_3 ) -> V_102 . V_103 ?
V_417 : V_418 ) ;
V_3 -> V_82 . V_393 = V_393 ;
if ( V_70 ) {
if ( ! F_196 ( V_3 ) ) {
V_416 &= ~ V_419 ;
V_416 |= V_420 ;
} else if ( ! ( V_393 & V_419 ) ) {
V_416 &= ~ V_419 ;
}
}
F_62 ( V_354 , V_393 ) ;
F_62 ( V_352 , V_416 ) ;
}
static void F_206 ( struct V_2 * V_3 ,
struct V_421 * V_422 , int V_79 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_338 * V_339 ;
T_1 V_93 ;
if ( V_45 -> V_102 . V_103
&& ( V_79 == V_423 || V_79 == V_356
|| V_79 == V_358 || V_79 == V_361
|| V_79 == V_360 )
&& ! V_355 ) {
switch ( V_79 ) {
case V_423 : V_339 = & V_45 -> V_102 . V_147 ; break;
case V_356 : V_339 = & V_45 -> V_102 . V_357 ; break;
case V_358 : V_339 = & V_45 -> V_102 . V_359 ; break;
case V_361 : V_339 = & V_45 -> V_102 . V_152 ; break;
case V_360 : V_339 = & V_45 -> V_102 . V_156 ; break;
default: F_207 () ;
}
V_422 -> V_86 = V_339 -> V_86 ;
V_422 -> V_89 = V_339 -> V_89 ;
V_422 -> V_91 = V_339 -> V_91 ;
V_93 = V_339 -> V_93 ;
if ( V_79 == V_423
|| V_422 -> V_86 == F_71 ( V_45 , V_79 ) )
goto V_424;
}
V_422 -> V_89 = F_72 ( V_45 , V_79 ) ;
V_422 -> V_91 = F_73 ( V_45 , V_79 ) ;
V_422 -> V_86 = F_71 ( V_45 , V_79 ) ;
V_93 = F_74 ( V_45 , V_79 ) ;
V_424:
if ( ( V_93 & V_425 ) && ! V_355 )
V_93 = 0 ;
V_422 -> type = V_93 & 15 ;
V_422 -> V_144 = ( V_93 >> 4 ) & 1 ;
V_422 -> V_343 = ( V_93 >> 5 ) & 3 ;
V_422 -> V_426 = ( V_93 >> 7 ) & 1 ;
V_422 -> V_427 = ( V_93 >> 12 ) & 1 ;
V_422 -> V_428 = ( V_93 >> 13 ) & 1 ;
V_422 -> V_429 = ( V_93 >> 14 ) & 1 ;
V_422 -> V_430 = ( V_93 >> 15 ) & 1 ;
V_422 -> V_431 = ( V_93 >> 16 ) & 1 ;
}
static T_4 F_208 ( struct V_2 * V_3 , int V_79 )
{
struct V_421 V_144 ;
if ( F_1 ( V_3 ) -> V_102 . V_103 ) {
F_206 ( V_3 , & V_144 , V_79 ) ;
return V_144 . V_89 ;
}
return F_72 ( F_1 ( V_3 ) , V_79 ) ;
}
static int F_209 ( struct V_2 * V_3 )
{
if ( ! F_210 ( V_3 ) )
return 0 ;
if ( ! F_90 ( V_3 )
&& ( F_211 ( V_3 ) & V_194 ) )
return 3 ;
return F_71 ( F_1 ( V_3 ) , V_432 ) & 3 ;
}
static int F_212 ( struct V_2 * V_3 )
{
if ( ! F_116 ( V_192 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ) {
F_117 ( V_192 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
F_1 ( V_3 ) -> V_433 = F_209 ( V_3 ) ;
}
return F_1 ( V_3 ) -> V_433 ;
}
static T_1 F_213 ( struct V_421 * V_422 )
{
T_1 V_93 ;
if ( V_422 -> V_431 )
V_93 = 1 << 16 ;
else {
V_93 = V_422 -> type & 15 ;
V_93 |= ( V_422 -> V_144 & 1 ) << 4 ;
V_93 |= ( V_422 -> V_343 & 3 ) << 5 ;
V_93 |= ( V_422 -> V_426 & 1 ) << 7 ;
V_93 |= ( V_422 -> V_427 & 1 ) << 12 ;
V_93 |= ( V_422 -> V_428 & 1 ) << 13 ;
V_93 |= ( V_422 -> V_429 & 1 ) << 14 ;
V_93 |= ( V_422 -> V_430 & 1 ) << 15 ;
}
if ( V_93 == 0 )
V_93 = V_425 ;
return V_93 ;
}
static void F_214 ( struct V_2 * V_3 ,
struct V_421 * V_422 , int V_79 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_340 * V_341 = & V_88 [ V_79 ] ;
T_1 V_93 ;
F_69 ( V_45 ) ;
if ( V_45 -> V_102 . V_103 && V_79 == V_423 ) {
F_64 ( V_341 -> V_86 , V_422 -> V_86 ) ;
V_45 -> V_102 . V_147 . V_86 = V_422 -> V_86 ;
V_45 -> V_102 . V_147 . V_89 = V_422 -> V_89 ;
V_45 -> V_102 . V_147 . V_91 = V_422 -> V_91 ;
V_45 -> V_102 . V_147 . V_93 = F_213 ( V_422 ) ;
return;
}
F_62 ( V_341 -> V_89 , V_422 -> V_89 ) ;
F_65 ( V_341 -> V_91 , V_422 -> V_91 ) ;
F_64 ( V_341 -> V_86 , V_422 -> V_86 ) ;
if ( V_45 -> V_102 . V_103 && V_422 -> V_144 ) {
if ( V_422 -> V_89 == 0xffff0000 && V_422 -> V_86 == 0xf000 )
F_62 ( V_341 -> V_89 , 0xf0000 ) ;
V_93 = 0xf3 ;
} else
V_93 = F_213 ( V_422 ) ;
if ( V_334 && ( V_79 != V_434 ) )
V_93 |= 0x1 ;
F_65 ( V_341 -> V_95 , V_93 ) ;
F_119 ( V_192 , ( T_8 * ) & V_3 -> V_82 . V_83 ) ;
}
static void F_215 ( struct V_2 * V_3 , int * V_429 , int * V_428 )
{
T_1 V_93 = F_74 ( F_1 ( V_3 ) , V_432 ) ;
* V_429 = ( V_93 >> 14 ) & 1 ;
* V_428 = ( V_93 >> 13 ) & 1 ;
}
static void F_216 ( struct V_2 * V_3 , struct V_123 * V_435 )
{
V_435 -> V_323 = F_57 ( V_436 ) ;
V_435 -> V_128 = F_55 ( V_437 ) ;
}
static void F_217 ( struct V_2 * V_3 , struct V_123 * V_435 )
{
F_65 ( V_436 , V_435 -> V_323 ) ;
F_62 ( V_437 , V_435 -> V_128 ) ;
}
static void F_218 ( struct V_2 * V_3 , struct V_123 * V_435 )
{
V_435 -> V_323 = F_57 ( V_438 ) ;
V_435 -> V_128 = F_55 ( V_439 ) ;
}
static void F_219 ( struct V_2 * V_3 , struct V_123 * V_435 )
{
F_65 ( V_438 , V_435 -> V_323 ) ;
F_62 ( V_439 , V_435 -> V_128 ) ;
}
static bool F_220 ( struct V_2 * V_3 , int V_79 )
{
struct V_421 V_422 ;
T_1 V_93 ;
F_206 ( V_3 , & V_422 , V_79 ) ;
V_93 = F_213 ( & V_422 ) ;
if ( V_422 . V_89 != ( V_422 . V_86 << 4 ) )
return false ;
if ( V_422 . V_91 != 0xffff )
return false ;
if ( V_93 != 0xf3 )
return false ;
return true ;
}
static bool F_221 ( struct V_2 * V_3 )
{
struct V_421 V_440 ;
unsigned int V_441 ;
F_206 ( V_3 , & V_440 , V_432 ) ;
V_441 = V_440 . V_86 & V_344 ;
if ( V_440 . V_431 )
return false ;
if ( ~ V_440 . type & ( V_442 | V_443 ) )
return false ;
if ( ! V_440 . V_144 )
return false ;
if ( V_440 . type & V_444 ) {
if ( V_440 . V_343 > V_441 )
return false ;
} else {
if ( V_440 . V_343 != V_441 )
return false ;
}
if ( ! V_440 . V_426 )
return false ;
return true ;
}
static bool F_222 ( struct V_2 * V_3 )
{
struct V_421 V_445 ;
unsigned int V_446 ;
F_206 ( V_3 , & V_445 , V_447 ) ;
V_446 = V_445 . V_86 & V_344 ;
if ( V_445 . V_431 )
return true ;
if ( V_445 . type != 3 && V_445 . type != 7 )
return false ;
if ( ! V_445 . V_144 )
return false ;
if ( V_445 . V_343 != V_446 )
return false ;
if ( ! V_445 . V_426 )
return false ;
return true ;
}
static bool F_223 ( struct V_2 * V_3 , int V_79 )
{
struct V_421 V_422 ;
unsigned int V_448 ;
F_206 ( V_3 , & V_422 , V_79 ) ;
V_448 = V_422 . V_86 & V_344 ;
if ( V_422 . V_431 )
return true ;
if ( ! V_422 . V_144 )
return false ;
if ( ! V_422 . V_426 )
return false ;
if ( ~ V_422 . type & ( V_442 | V_444 ) ) {
if ( V_422 . V_343 < V_448 )
return false ;
}
return true ;
}
static bool F_224 ( struct V_2 * V_3 )
{
struct V_421 V_147 ;
F_206 ( V_3 , & V_147 , V_423 ) ;
if ( V_147 . V_431 )
return false ;
if ( V_147 . V_86 & V_449 )
return false ;
if ( V_147 . type != 3 && V_147 . type != 11 )
return false ;
if ( ! V_147 . V_426 )
return false ;
return true ;
}
static bool F_225 ( struct V_2 * V_3 )
{
struct V_421 V_450 ;
F_206 ( V_3 , & V_450 , V_434 ) ;
if ( V_450 . V_431 )
return true ;
if ( V_450 . V_86 & V_449 )
return false ;
if ( V_450 . type != 2 )
return false ;
if ( ! V_450 . V_426 )
return false ;
return true ;
}
static bool F_226 ( struct V_2 * V_3 )
{
struct V_421 V_440 , V_445 ;
F_206 ( V_3 , & V_440 , V_432 ) ;
F_206 ( V_3 , & V_445 , V_447 ) ;
return ( ( V_440 . V_86 & V_344 ) ==
( V_445 . V_86 & V_344 ) ) ;
}
static bool F_227 ( struct V_2 * V_3 )
{
if ( ! F_210 ( V_3 ) ) {
if ( ! F_220 ( V_3 , V_432 ) )
return false ;
if ( ! F_220 ( V_3 , V_447 ) )
return false ;
if ( ! F_220 ( V_3 , V_358 ) )
return false ;
if ( ! F_220 ( V_3 , V_356 ) )
return false ;
if ( ! F_220 ( V_3 , V_361 ) )
return false ;
if ( ! F_220 ( V_3 , V_360 ) )
return false ;
} else {
if ( ! F_226 ( V_3 ) )
return false ;
if ( ! F_221 ( V_3 ) )
return false ;
if ( ! F_222 ( V_3 ) )
return false ;
if ( ! F_223 ( V_3 , V_358 ) )
return false ;
if ( ! F_223 ( V_3 , V_356 ) )
return false ;
if ( ! F_223 ( V_3 , V_361 ) )
return false ;
if ( ! F_223 ( V_3 , V_360 ) )
return false ;
if ( ! F_224 ( V_3 ) )
return false ;
if ( ! F_225 ( V_3 ) )
return false ;
}
return true ;
}
static int F_228 ( struct V_18 * V_18 )
{
T_12 V_451 ;
T_2 V_139 = 0 ;
int V_452 , V_453 , V_80 = 0 ;
V_453 = F_187 ( & V_18 -> V_373 ) ;
V_451 = F_181 ( V_18 ) >> V_372 ;
V_452 = F_229 ( V_18 , V_451 , 0 , V_322 ) ;
if ( V_452 < 0 )
goto V_454;
V_139 = V_455 + V_456 ;
V_452 = F_230 ( V_18 , V_451 ++ , & V_139 ,
V_457 , sizeof( T_2 ) ) ;
if ( V_452 < 0 )
goto V_454;
V_452 = F_229 ( V_18 , V_451 ++ , 0 , V_322 ) ;
if ( V_452 < 0 )
goto V_454;
V_452 = F_229 ( V_18 , V_451 , 0 , V_322 ) ;
if ( V_452 < 0 )
goto V_454;
V_139 = ~ 0 ;
V_452 = F_230 ( V_18 , V_451 , & V_139 ,
V_375 - 2 * V_322 - 1 ,
sizeof( T_6 ) ) ;
if ( V_452 < 0 )
goto V_454;
V_80 = 1 ;
V_454:
F_185 ( & V_18 -> V_373 , V_453 ) ;
return V_80 ;
}
static int F_231 ( struct V_18 * V_18 )
{
int V_47 , V_453 , V_452 , V_80 ;
T_13 V_458 ;
T_1 V_222 ;
if ( ! V_70 )
return 1 ;
if ( F_63 ( ! V_18 -> V_82 . V_459 ) ) {
F_41 ( V_61 L_12
L_13 ) ;
return 0 ;
}
if ( F_232 ( V_18 -> V_82 . V_460 ) )
return 1 ;
V_80 = 0 ;
V_458 = V_18 -> V_82 . V_415 >> V_372 ;
V_453 = F_187 ( & V_18 -> V_373 ) ;
V_452 = F_229 ( V_18 , V_458 , 0 , V_322 ) ;
if ( V_452 < 0 )
goto V_454;
for ( V_47 = 0 ; V_47 < V_461 ; V_47 ++ ) {
V_222 = ( V_47 << 22 ) + ( V_462 | V_463 | V_464 |
V_465 | V_466 | V_467 ) ;
V_452 = F_230 ( V_18 , V_458 ,
& V_222 , V_47 * sizeof( V_222 ) , sizeof( V_222 ) ) ;
if ( V_452 < 0 )
goto V_454;
}
V_18 -> V_82 . V_460 = true ;
V_80 = 1 ;
V_454:
F_185 ( & V_18 -> V_373 , V_453 ) ;
return V_80 ;
}
static void F_233 ( int V_79 )
{
struct V_340 * V_341 = & V_88 [ V_79 ] ;
unsigned int V_93 ;
F_64 ( V_341 -> V_86 , 0 ) ;
F_62 ( V_341 -> V_89 , 0 ) ;
F_65 ( V_341 -> V_91 , 0xffff ) ;
if ( V_334 ) {
V_93 = 0x93 ;
if ( V_79 == V_432 )
V_93 |= 0x08 ;
} else
V_93 = 0xf3 ;
F_65 ( V_341 -> V_95 , V_93 ) ;
}
static int F_234 ( struct V_18 * V_18 )
{
struct V_468 V_469 ;
int V_452 = 0 ;
F_235 ( & V_18 -> V_470 ) ;
if ( V_18 -> V_82 . V_471 )
goto V_454;
V_469 . V_472 = V_473 ;
V_469 . V_346 = 0 ;
V_469 . V_474 = 0xfee00000ULL ;
V_469 . V_475 = V_322 ;
V_452 = F_236 ( V_18 , & V_469 , 0 ) ;
if ( V_452 )
goto V_454;
V_18 -> V_82 . V_471 = F_237 ( V_18 , 0xfee00 ) ;
V_454:
F_238 ( & V_18 -> V_470 ) ;
return V_452 ;
}
static int F_239 ( struct V_18 * V_18 )
{
struct V_468 V_469 ;
int V_452 = 0 ;
F_235 ( & V_18 -> V_470 ) ;
if ( V_18 -> V_82 . V_459 )
goto V_454;
V_469 . V_472 = V_476 ;
V_469 . V_346 = 0 ;
V_469 . V_474 =
V_18 -> V_82 . V_415 ;
V_469 . V_475 = V_322 ;
V_452 = F_236 ( V_18 , & V_469 , 0 ) ;
if ( V_452 )
goto V_454;
V_18 -> V_82 . V_459 = F_237 ( V_18 ,
V_18 -> V_82 . V_415 >> V_372 ) ;
V_454:
F_238 ( & V_18 -> V_470 ) ;
return V_452 ;
}
static void F_240 ( struct V_1 * V_45 )
{
int V_33 ;
V_45 -> V_33 = 0 ;
if ( ! V_333 )
return;
F_241 ( & V_477 ) ;
V_33 = F_242 ( V_478 , V_479 ) ;
if ( V_33 < V_479 ) {
V_45 -> V_33 = V_33 ;
F_117 ( V_33 , V_478 ) ;
}
F_243 ( & V_477 ) ;
}
static void F_244 ( struct V_1 * V_45 )
{
if ( ! V_333 )
return;
F_241 ( & V_477 ) ;
if ( V_45 -> V_33 != 0 )
F_119 ( V_45 -> V_33 , V_478 ) ;
F_243 ( & V_477 ) ;
}
static void F_245 ( unsigned long * V_223 , T_1 V_46 )
{
int V_480 = sizeof( unsigned long ) ;
if ( ! F_8 () )
return;
if ( V_46 <= 0x1fff ) {
F_119 ( V_46 , V_223 + 0x000 / V_480 ) ;
F_119 ( V_46 , V_223 + 0x800 / V_480 ) ;
} else if ( ( V_46 >= 0xc0000000 ) && ( V_46 <= 0xc0001fff ) ) {
V_46 &= 0x1fff ;
F_119 ( V_46 , V_223 + 0x400 / V_480 ) ;
F_119 ( V_46 , V_223 + 0xc00 / V_480 ) ;
}
}
static void F_246 ( T_1 V_46 , bool V_481 )
{
if ( ! V_481 )
F_245 ( V_231 , V_46 ) ;
F_245 ( V_230 , V_46 ) ;
}
static int F_247 ( struct V_1 * V_45 )
{
T_1 V_482 , V_483 , V_484 ;
T_1 V_485 ;
T_4 V_486 ;
unsigned long V_487 ;
struct V_123 V_435 ;
int V_47 ;
unsigned long V_488 ;
T_1 V_489 ;
F_66 ( V_490 , F_40 ( V_491 ) ) ;
F_66 ( V_492 , F_40 ( V_493 ) ) ;
if ( F_8 () )
F_66 ( V_232 , F_40 ( V_231 ) ) ;
F_66 ( V_494 , - 1ull ) ;
F_65 ( V_495 ,
V_14 . V_42 ) ;
V_489 = V_14 . V_15 ;
if ( ! F_10 ( V_45 -> V_3 . V_18 ) ) {
V_489 &= ~ V_17 ;
#ifdef F_59
V_489 |= V_303 |
V_302 ;
#endif
}
if ( ! V_70 )
V_489 |= V_305 |
V_304 |
V_311 ;
F_65 ( V_402 , V_489 ) ;
if ( F_12 () ) {
V_489 = V_14 . V_20 ;
if ( ! F_29 ( V_45 -> V_3 . V_18 ) )
V_489 &=
~ V_21 ;
if ( V_45 -> V_33 == 0 )
V_489 &= ~ V_40 ;
if ( ! V_70 ) {
V_489 &= ~ V_36 ;
V_334 = 0 ;
}
if ( ! V_334 )
V_489 &= ~ V_37 ;
if ( ! V_337 )
V_489 &= ~ V_38 ;
F_65 ( V_496 , V_489 ) ;
}
if ( V_337 ) {
F_65 ( V_497 , V_337 ) ;
F_65 ( V_498 , V_499 ) ;
}
F_65 ( V_500 , ! ! V_501 ) ;
F_65 ( V_502 , ! ! V_501 ) ;
F_65 ( V_503 , 0 ) ;
F_62 ( V_504 , F_248 () | V_182 ) ;
F_62 ( V_505 , F_152 () ) ;
F_62 ( V_506 , F_249 () ) ;
F_64 ( V_507 , V_508 ) ;
F_64 ( V_509 , V_510 ) ;
F_64 ( V_511 , V_510 ) ;
F_64 ( V_154 , 0 ) ;
F_64 ( V_158 , 0 ) ;
F_64 ( V_512 , V_510 ) ;
#ifdef F_59
F_89 ( V_160 , V_487 ) ;
F_62 ( V_159 , V_487 ) ;
F_89 ( V_162 , V_487 ) ;
F_62 ( V_161 , V_487 ) ;
#else
F_62 ( V_159 , 0 ) ;
F_62 ( V_161 , 0 ) ;
#endif
F_64 ( V_513 , V_129 * 8 ) ;
F_250 ( & V_435 ) ;
F_62 ( V_514 , V_435 . V_128 ) ;
asm("mov $.Lkvm_vmx_return, %0" : "=r"(kvm_vmx_return));
F_62 ( V_515 , V_488 ) ;
F_65 ( V_516 , 0 ) ;
F_65 ( V_118 , 0 ) ;
F_66 ( V_517 , F_40 ( V_45 -> V_106 . V_116 ) ) ;
F_65 ( V_117 , 0 ) ;
F_66 ( V_518 , F_40 ( V_45 -> V_106 . V_115 ) ) ;
F_160 ( V_246 , V_482 , V_485 ) ;
F_65 ( V_519 , V_482 ) ;
F_89 ( V_178 , V_487 ) ;
F_62 ( V_179 , V_487 ) ;
F_89 ( V_248 , V_487 ) ;
F_62 ( V_520 , V_487 ) ;
if ( V_14 . V_326 & V_318 ) {
F_160 ( V_251 , V_483 , V_484 ) ;
V_486 = V_483 | ( ( T_4 ) V_484 << 32 ) ;
F_66 ( V_521 , V_486 ) ;
}
if ( V_14 . V_252 & V_253 ) {
F_160 ( V_251 , V_483 , V_484 ) ;
V_486 = V_483 | ( ( T_4 ) V_484 << 32 ) ;
F_66 ( V_254 , V_486 ) ;
V_45 -> V_3 . V_82 . V_255 = V_486 ;
}
for ( V_47 = 0 ; V_47 < V_522 ; ++ V_47 ) {
T_1 V_51 = V_49 [ V_47 ] ;
T_1 V_523 , V_524 ;
int V_525 = V_45 -> V_48 ;
if ( F_251 ( V_51 , & V_523 , & V_524 ) < 0 )
continue;
if ( F_252 ( V_51 , V_523 , V_524 ) < 0 )
continue;
V_45 -> V_50 [ V_525 ] . V_51 = V_47 ;
V_45 -> V_50 [ V_525 ] . V_139 = 0 ;
V_45 -> V_50 [ V_525 ] . V_76 = - 1ull ;
++ V_45 -> V_48 ;
}
F_65 ( V_112 , V_14 . V_326 ) ;
F_65 ( V_110 , V_14 . V_252 ) ;
F_62 ( V_185 , ~ 0UL ) ;
V_45 -> V_3 . V_82 . V_392 = V_526 ;
if ( V_70 )
V_45 -> V_3 . V_82 . V_392 |= V_527 ;
F_62 ( V_528 , ~ V_45 -> V_3 . V_82 . V_392 ) ;
F_143 ( & V_45 -> V_3 , 0 ) ;
return 0 ;
}
static int F_253 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_4 V_46 ;
int V_80 ;
V_3 -> V_82 . V_83 = ~ ( ( 1 << V_261 ) | ( 1 << V_258 ) ) ;
V_45 -> V_102 . V_103 = 0 ;
V_45 -> V_529 = 0 ;
V_45 -> V_3 . V_82 . V_259 [ V_530 ] = F_254 () ;
F_255 ( & V_45 -> V_3 , 0 ) ;
V_46 = 0xfee00000 | V_531 ;
if ( F_256 ( & V_45 -> V_3 ) )
V_46 |= V_532 ;
F_257 ( & V_45 -> V_3 , V_46 ) ;
V_80 = F_258 ( & V_45 -> V_3 ) ;
if ( V_80 != 0 )
goto V_454;
F_69 ( V_45 ) ;
F_233 ( V_432 ) ;
if ( F_256 ( & V_45 -> V_3 ) ) {
F_64 ( V_364 , 0xf000 ) ;
F_62 ( V_380 , 0x000f0000 ) ;
} else {
F_64 ( V_364 , V_45 -> V_3 . V_82 . V_533 << 8 ) ;
F_62 ( V_380 , V_45 -> V_3 . V_82 . V_533 << 12 ) ;
}
F_233 ( V_358 ) ;
F_233 ( V_356 ) ;
F_233 ( V_361 ) ;
F_233 ( V_360 ) ;
F_233 ( V_447 ) ;
F_64 ( V_348 , 0 ) ;
F_62 ( V_349 , 0 ) ;
F_65 ( V_350 , 0xffff ) ;
F_65 ( V_351 , 0x008b ) ;
F_64 ( V_534 , 0 ) ;
F_62 ( V_535 , 0 ) ;
F_65 ( V_536 , 0xffff ) ;
F_65 ( V_537 , 0x00082 ) ;
F_65 ( V_247 , 0 ) ;
F_62 ( V_250 , 0 ) ;
F_62 ( V_249 , 0 ) ;
F_62 ( V_190 , 0x02 ) ;
if ( F_256 ( & V_45 -> V_3 ) )
F_124 ( V_3 , 0xfff0 ) ;
else
F_124 ( V_3 , 0 ) ;
F_259 ( V_3 , V_258 , 0 ) ;
F_62 ( V_267 , 0x400 ) ;
F_62 ( V_439 , 0 ) ;
F_65 ( V_438 , 0xffff ) ;
F_62 ( V_437 , 0 ) ;
F_65 ( V_436 , 0xffff ) ;
F_65 ( V_205 , V_207 ) ;
F_65 ( V_196 , 0 ) ;
F_65 ( V_538 , 0 ) ;
F_66 ( V_539 , 0 ) ;
F_131 ( V_45 ) ;
F_65 ( V_219 , 0 ) ;
if ( F_9 () ) {
F_66 ( V_540 , 0 ) ;
if ( F_10 ( V_45 -> V_3 . V_18 ) )
F_66 ( V_540 ,
F_40 ( V_45 -> V_3 . V_82 . V_541 -> V_259 ) ) ;
F_65 ( V_542 , 0 ) ;
}
if ( F_29 ( V_45 -> V_3 . V_18 ) )
F_66 ( V_543 ,
F_260 ( V_45 -> V_3 . V_18 -> V_82 . V_471 ) ) ;
if ( V_45 -> V_33 != 0 )
F_64 ( V_544 , V_45 -> V_33 ) ;
V_45 -> V_3 . V_82 . V_180 = V_545 | V_546 | V_547 ;
F_203 ( & V_45 -> V_3 , F_261 ( V_3 ) ) ;
F_201 ( & V_45 -> V_3 , 0 ) ;
F_189 ( & V_45 -> V_3 , 0 ) ;
F_111 ( & V_45 -> V_3 ) ;
F_75 ( & V_45 -> V_3 ) ;
F_51 ( V_45 ) ;
V_80 = 0 ;
V_45 -> V_347 = 0 ;
V_454:
return V_80 ;
}
static void F_262 ( struct V_2 * V_3 )
{
T_1 V_548 ;
V_548 = F_57 ( V_402 ) ;
V_548 |= V_549 ;
F_65 ( V_402 , V_548 ) ;
}
static void F_263 ( struct V_2 * V_3 )
{
T_1 V_548 ;
if ( ! F_32 () ) {
F_262 ( V_3 ) ;
return;
}
if ( F_57 ( V_196 ) & V_197 ) {
F_262 ( V_3 ) ;
return;
}
V_548 = F_57 ( V_402 ) ;
V_548 |= V_550 ;
F_65 ( V_402 , V_548 ) ;
}
static void F_264 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_14 V_551 ;
int V_552 = V_3 -> V_82 . V_553 . V_114 ;
F_265 ( V_552 ) ;
++ V_3 -> V_167 . V_554 ;
if ( V_45 -> V_102 . V_103 ) {
int V_213 = 0 ;
if ( V_3 -> V_82 . V_553 . V_555 )
V_213 = V_3 -> V_82 . V_214 ;
if ( F_128 ( V_3 , V_552 , V_213 ) != V_215 )
F_105 ( V_216 , V_3 ) ;
return;
}
V_551 = V_552 | V_7 ;
if ( V_3 -> V_82 . V_553 . V_555 ) {
V_551 |= V_556 ;
F_65 ( V_217 ,
V_45 -> V_3 . V_82 . V_214 ) ;
} else
V_551 |= V_12 ;
F_65 ( V_219 , V_551 ) ;
F_125 ( V_3 ) ;
}
static void F_266 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
if ( ! F_32 () ) {
V_45 -> V_529 = 1 ;
V_45 -> V_557 = 0 ;
}
++ V_3 -> V_167 . V_558 ;
V_45 -> V_559 = false ;
if ( V_45 -> V_102 . V_103 ) {
if ( F_128 ( V_3 , V_560 , 0 ) != V_215 )
F_105 ( V_216 , V_3 ) ;
return;
}
F_65 ( V_219 ,
V_561 | V_7 | V_560 ) ;
F_125 ( V_3 ) ;
}
static int F_267 ( struct V_2 * V_3 )
{
if ( ! F_32 () && F_1 ( V_3 ) -> V_529 )
return 0 ;
return ! ( F_57 ( V_196 ) &
( V_199 | V_197
| V_562 ) ) ;
}
static bool F_268 ( struct V_2 * V_3 )
{
if ( ! F_32 () )
return F_1 ( V_3 ) -> V_529 ;
if ( F_1 ( V_3 ) -> V_559 )
return false ;
return F_57 ( V_196 ) & V_562 ;
}
static void F_269 ( struct V_2 * V_3 , bool V_563 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
if ( ! F_32 () ) {
if ( V_45 -> V_529 != V_563 ) {
V_45 -> V_529 = V_563 ;
V_45 -> V_557 = 0 ;
}
} else {
V_45 -> V_559 = ! V_563 ;
if ( V_563 )
F_68 ( V_196 ,
V_562 ) ;
else
F_67 ( V_196 ,
V_562 ) ;
}
}
static int F_270 ( struct V_2 * V_3 )
{
return ( F_55 ( V_190 ) & V_564 ) &&
! ( F_57 ( V_196 ) &
( V_197 | V_199 ) ) ;
}
static int F_186 ( struct V_18 * V_18 , unsigned int V_275 )
{
int V_80 ;
struct V_468 V_565 = {
. V_472 = V_566 ,
. V_474 = V_275 ,
. V_475 = V_322 * 3 ,
. V_346 = 0 ,
} ;
V_80 = F_271 ( V_18 , & V_565 , 0 ) ;
if ( V_80 )
return V_80 ;
V_18 -> V_82 . V_366 = V_275 ;
if ( ! F_228 ( V_18 ) )
return - V_331 ;
return 0 ;
}
static int F_272 ( struct V_2 * V_3 ,
int V_567 , T_1 V_568 )
{
if ( ( ( V_567 == V_569 ) || ( V_567 == V_570 ) ) && V_568 == 0 )
if ( F_273 ( V_3 , 0 ) == V_215 )
return 1 ;
switch ( V_567 ) {
case V_97 :
if ( V_3 -> V_98 &
( V_571 | V_266 ) )
return 0 ;
F_274 ( V_3 , V_567 ) ;
return 1 ;
case V_101 :
F_1 ( V_3 ) -> V_3 . V_82 . V_214 =
F_57 ( V_203 ) ;
if ( V_3 -> V_98 & V_100 )
return 0 ;
case V_572 :
case V_573 :
case V_574 :
case V_11 :
case V_575 :
case V_570 :
case V_569 :
case V_576 :
F_274 ( V_3 , V_567 ) ;
return 1 ;
}
return 0 ;
}
static void F_275 ( void )
{
#if F_276 ( V_577 ) && F_276 ( F_59 )
struct V_578 V_259 = {
. V_440 = 3 ,
. V_346 = V_564 ,
} ;
F_277 ( & V_259 , 0 ) ;
#endif
}
static int F_278 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_279 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_579 * V_579 = V_3 -> V_580 ;
T_1 V_4 , V_581 , V_209 ;
unsigned long V_582 , V_202 , V_583 ;
T_1 V_584 ;
enum V_585 V_586 ;
V_584 = V_45 -> V_587 ;
V_4 = V_45 -> V_588 ;
if ( F_7 ( V_4 ) )
return F_278 ( V_3 ) ;
if ( ( V_584 & V_589 ) &&
! F_3 ( V_4 ) ) {
V_3 -> V_580 -> V_590 = V_591 ;
V_3 -> V_580 -> V_592 . V_593 = V_594 ;
V_3 -> V_580 -> V_592 . V_595 = 2 ;
V_3 -> V_580 -> V_592 . V_139 [ 0 ] = V_584 ;
V_3 -> V_580 -> V_592 . V_139 [ 1 ] = V_4 ;
return 0 ;
}
if ( ( V_4 & V_5 ) == V_561 )
return 1 ;
if ( F_4 ( V_4 ) ) {
F_111 ( V_3 ) ;
return 1 ;
}
if ( F_5 ( V_4 ) ) {
V_586 = F_273 ( V_3 , V_596 ) ;
if ( V_586 != V_215 )
F_274 ( V_3 , V_11 ) ;
return 1 ;
}
V_209 = 0 ;
if ( V_4 & V_212 )
V_209 = F_57 ( V_597 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_70 )
F_207 () ;
V_582 = F_55 ( V_598 ) ;
F_280 ( V_582 , V_209 ) ;
if ( F_281 ( V_3 ) )
F_282 ( V_3 , V_582 ) ;
return F_283 ( V_3 , V_582 , V_209 , NULL , 0 ) ;
}
if ( V_45 -> V_102 . V_103 &&
F_272 ( V_3 , V_4 & V_6 ,
V_209 ) ) {
if ( V_3 -> V_82 . V_599 ) {
V_3 -> V_82 . V_599 = 0 ;
return F_284 ( V_3 ) ;
}
return 1 ;
}
V_581 = V_4 & V_6 ;
switch ( V_581 ) {
case V_97 :
V_583 = F_55 ( V_598 ) ;
if ( ! ( V_3 -> V_98 &
( V_571 | V_266 ) ) ) {
V_3 -> V_82 . V_583 = V_583 | V_600 ;
F_274 ( V_3 , V_97 ) ;
return 1 ;
}
V_579 -> V_601 . V_82 . V_583 = V_583 | V_600 ;
V_579 -> V_601 . V_82 . V_269 = F_55 ( V_267 ) ;
case V_101 :
V_45 -> V_3 . V_82 . V_214 =
F_57 ( V_203 ) ;
V_579 -> V_590 = V_602 ;
V_202 = F_123 ( V_3 ) ;
V_579 -> V_601 . V_82 . V_603 = F_55 ( V_380 ) + V_202 ;
V_579 -> V_601 . V_82 . V_604 = V_581 ;
break;
default:
V_579 -> V_590 = V_605 ;
V_579 -> V_606 . V_604 = V_581 ;
V_579 -> V_606 . V_209 = V_209 ;
break;
}
return 0 ;
}
static int F_285 ( struct V_2 * V_3 )
{
++ V_3 -> V_167 . V_607 ;
return 1 ;
}
static int F_286 ( struct V_2 * V_3 )
{
V_3 -> V_580 -> V_590 = V_608 ;
return 0 ;
}
static int F_287 ( struct V_2 * V_3 )
{
unsigned long V_609 ;
int V_323 , V_610 , string ;
unsigned V_611 ;
V_609 = F_55 ( V_598 ) ;
string = ( V_609 & 16 ) != 0 ;
V_610 = ( V_609 & 8 ) != 0 ;
++ V_3 -> V_167 . V_612 ;
if ( string || V_610 )
return F_273 ( V_3 , 0 ) == V_215 ;
V_611 = V_609 >> 16 ;
V_323 = ( V_609 & 7 ) + 1 ;
F_122 ( V_3 ) ;
return F_288 ( V_3 , V_323 , V_611 ) ;
}
static void
F_289 ( struct V_2 * V_3 , unsigned char * V_613 )
{
V_613 [ 0 ] = 0x0f ;
V_613 [ 1 ] = 0x01 ;
V_613 [ 2 ] = 0xc1 ;
}
static int F_290 ( struct V_2 * V_3 )
{
unsigned long V_609 , V_614 ;
int V_615 ;
int V_257 ;
int V_616 ;
V_609 = F_55 ( V_598 ) ;
V_615 = V_609 & 15 ;
V_257 = ( V_609 >> 8 ) & 15 ;
switch ( ( V_609 >> 4 ) & 3 ) {
case 0 :
V_614 = F_291 ( V_3 , V_257 ) ;
F_292 ( V_615 , V_614 ) ;
switch ( V_615 ) {
case 0 :
V_616 = F_293 ( V_3 , V_614 ) ;
F_294 ( V_3 , V_616 ) ;
return 1 ;
case 3 :
V_616 = F_295 ( V_3 , V_614 ) ;
F_294 ( V_3 , V_616 ) ;
return 1 ;
case 4 :
V_616 = F_296 ( V_3 , V_614 ) ;
F_294 ( V_3 , V_616 ) ;
return 1 ;
case 8 : {
T_6 V_617 = F_297 ( V_3 ) ;
T_6 V_618 = F_291 ( V_3 , V_257 ) ;
V_616 = F_255 ( V_3 , V_618 ) ;
F_294 ( V_3 , V_616 ) ;
if ( F_11 ( V_3 -> V_18 ) )
return 1 ;
if ( V_617 <= V_618 )
return 1 ;
V_3 -> V_580 -> V_590 = V_619 ;
return 0 ;
}
} ;
break;
case 2 :
F_203 ( V_3 , F_112 ( V_3 , ~ V_182 ) ) ;
F_292 ( 0 , F_261 ( V_3 ) ) ;
F_122 ( V_3 ) ;
F_111 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_615 ) {
case 3 :
V_614 = F_205 ( V_3 ) ;
F_259 ( V_3 , V_257 , V_614 ) ;
F_298 ( V_615 , V_614 ) ;
F_122 ( V_3 ) ;
return 1 ;
case 8 :
V_614 = F_297 ( V_3 ) ;
F_259 ( V_3 , V_257 , V_614 ) ;
F_298 ( V_615 , V_614 ) ;
F_122 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_614 = ( V_609 >> V_620 ) & 0x0f ;
F_292 ( 0 , ( F_261 ( V_3 ) & ~ 0xful ) | V_614 ) ;
F_299 ( V_3 , V_614 ) ;
F_122 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_580 -> V_590 = 0 ;
F_300 ( V_3 , L_14 ,
( int ) ( V_609 >> 4 ) & 3 , V_615 ) ;
return 0 ;
}
static int F_301 ( struct V_2 * V_3 )
{
unsigned long V_609 ;
int V_621 , V_257 ;
if ( ! F_302 ( V_3 , 0 ) )
return 1 ;
V_621 = F_55 ( V_267 ) ;
if ( V_621 & V_622 ) {
if ( V_3 -> V_98 & V_266 ) {
V_3 -> V_580 -> V_601 . V_82 . V_583 = V_3 -> V_82 . V_583 ;
V_3 -> V_580 -> V_601 . V_82 . V_269 = V_621 ;
V_3 -> V_580 -> V_601 . V_82 . V_603 =
F_55 ( V_380 ) +
F_55 ( V_262 ) ;
V_3 -> V_580 -> V_601 . V_82 . V_604 = V_97 ;
V_3 -> V_580 -> V_590 = V_602 ;
return 0 ;
} else {
V_3 -> V_82 . V_269 &= ~ V_622 ;
V_3 -> V_82 . V_583 |= V_623 ;
F_62 ( V_267 , V_3 -> V_82 . V_269 ) ;
F_274 ( V_3 , V_97 ) ;
return 1 ;
}
}
V_609 = F_55 ( V_598 ) ;
V_621 = V_609 & V_624 ;
V_257 = F_303 ( V_609 ) ;
if ( V_609 & V_625 ) {
unsigned long V_614 ;
if ( ! F_304 ( V_3 , V_621 , & V_614 ) )
F_259 ( V_3 , V_257 , V_614 ) ;
} else
F_305 ( V_3 , V_621 , V_3 -> V_82 . V_259 [ V_257 ] ) ;
F_122 ( V_3 ) ;
return 1 ;
}
static void F_306 ( struct V_2 * V_3 , unsigned long V_614 )
{
F_62 ( V_267 , V_614 ) ;
}
static int F_307 ( struct V_2 * V_3 )
{
F_308 ( V_3 ) ;
return 1 ;
}
static int F_309 ( struct V_2 * V_3 )
{
T_1 V_626 = V_3 -> V_82 . V_259 [ V_627 ] ;
T_4 V_139 ;
if ( F_139 ( V_3 , V_626 , & V_139 ) ) {
F_310 ( V_626 ) ;
F_311 ( V_3 , 0 ) ;
return 1 ;
}
F_312 ( V_626 , V_139 ) ;
V_3 -> V_82 . V_259 [ V_628 ] = V_139 & - 1u ;
V_3 -> V_82 . V_259 [ V_530 ] = ( V_139 >> 32 ) & - 1u ;
F_122 ( V_3 ) ;
return 1 ;
}
static int F_313 ( struct V_2 * V_3 )
{
T_1 V_626 = V_3 -> V_82 . V_259 [ V_627 ] ;
T_4 V_139 = ( V_3 -> V_82 . V_259 [ V_628 ] & - 1u )
| ( ( T_4 ) ( V_3 -> V_82 . V_259 [ V_530 ] & - 1u ) << 32 ) ;
if ( F_141 ( V_3 , V_626 , V_139 ) != 0 ) {
F_314 ( V_626 , V_139 ) ;
F_311 ( V_3 , 0 ) ;
return 1 ;
}
F_315 ( V_626 , V_139 ) ;
F_122 ( V_3 ) ;
return 1 ;
}
static int F_316 ( struct V_2 * V_3 )
{
F_105 ( V_629 , V_3 ) ;
return 1 ;
}
static int F_317 ( struct V_2 * V_3 )
{
T_1 V_548 ;
V_548 = F_57 ( V_402 ) ;
V_548 &= ~ V_549 ;
F_65 ( V_402 , V_548 ) ;
F_105 ( V_629 , V_3 ) ;
++ V_3 -> V_167 . V_630 ;
if ( ! F_11 ( V_3 -> V_18 ) &&
V_3 -> V_580 -> V_631 &&
! F_318 ( V_3 ) ) {
V_3 -> V_580 -> V_590 = V_632 ;
return 0 ;
}
return 1 ;
}
static int F_319 ( struct V_2 * V_3 )
{
F_122 ( V_3 ) ;
return F_284 ( V_3 ) ;
}
static int F_320 ( struct V_2 * V_3 )
{
F_122 ( V_3 ) ;
F_321 ( V_3 ) ;
return 1 ;
}
static int F_322 ( struct V_2 * V_3 )
{
F_274 ( V_3 , V_11 ) ;
return 1 ;
}
static int F_323 ( struct V_2 * V_3 )
{
return F_273 ( V_3 , 0 ) == V_215 ;
}
static int F_324 ( struct V_2 * V_3 )
{
unsigned long V_609 = F_55 ( V_598 ) ;
F_325 ( V_3 , V_609 ) ;
F_122 ( V_3 ) ;
return 1 ;
}
static int F_326 ( struct V_2 * V_3 )
{
F_122 ( V_3 ) ;
F_327 ( V_3 ) ;
return 1 ;
}
static int F_328 ( struct V_2 * V_3 )
{
T_4 V_633 = F_329 ( V_3 ) ;
T_1 V_51 = F_291 ( V_3 , V_627 ) ;
if ( F_330 ( V_3 , V_51 , V_633 ) == 0 )
F_122 ( V_3 ) ;
return 1 ;
}
static int F_331 ( struct V_2 * V_3 )
{
return F_273 ( V_3 , 0 ) == V_215 ;
}
static int F_332 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
unsigned long V_609 ;
bool V_208 = false ;
T_1 V_209 = 0 ;
T_2 V_634 ;
int V_635 , type , V_636 ;
V_636 = ( V_45 -> V_587 & V_589 ) ;
type = ( V_45 -> V_587 & V_637 ) ;
V_609 = F_55 ( V_598 ) ;
V_635 = ( T_1 ) V_609 >> 30 ;
if ( V_635 == V_638 && V_636 ) {
switch ( type ) {
case V_561 :
V_3 -> V_82 . V_639 = false ;
F_269 ( V_3 , true ) ;
break;
case V_12 :
case V_556 :
F_333 ( V_3 ) ;
break;
case V_8 :
if ( V_45 -> V_587 &
V_640 ) {
V_208 = true ;
V_209 =
F_57 ( V_641 ) ;
}
case V_218 :
F_334 ( V_3 ) ;
break;
default:
break;
}
}
V_634 = V_609 ;
if ( ! V_636 || ( type != V_8 &&
type != V_12 &&
type != V_561 ) )
F_122 ( V_3 ) ;
if ( F_335 ( V_3 , V_634 , V_635 ,
V_208 , V_209 ) == V_642 ) {
V_3 -> V_580 -> V_590 = V_591 ;
V_3 -> V_580 -> V_592 . V_593 = V_643 ;
V_3 -> V_580 -> V_592 . V_595 = 0 ;
return 0 ;
}
F_62 ( V_267 , F_55 ( V_267 ) & ~ 55 ) ;
return 1 ;
}
static int F_336 ( struct V_2 * V_3 )
{
unsigned long V_609 ;
T_5 V_57 ;
int V_644 ;
V_609 = F_55 ( V_598 ) ;
if ( V_609 & ( 1 << 6 ) ) {
F_41 ( V_61 L_15 ) ;
return - V_242 ;
}
V_644 = ( V_609 >> 7 ) & 0x3 ;
if ( V_644 != 0x3 && V_644 != 0x1 && V_644 != 0 ) {
F_41 ( V_61 L_16 ) ;
F_41 ( V_61 L_17 ,
( long unsigned int ) F_58 ( V_645 ) ,
F_55 ( V_646 ) ) ;
F_41 ( V_61 L_18 ,
( long unsigned int ) V_609 ) ;
V_3 -> V_580 -> V_590 = V_647 ;
V_3 -> V_580 -> V_648 . V_649 = V_650 ;
return 0 ;
}
V_57 = F_58 ( V_645 ) ;
F_280 ( V_57 , V_609 ) ;
return F_283 ( V_3 , V_57 , V_609 & 0x3 , NULL , 0 ) ;
}
static T_4 F_337 ( T_4 V_651 , int V_652 )
{
int V_47 ;
T_4 V_76 = 0 ;
for ( V_47 = 51 ; V_47 > V_653 . V_654 ; V_47 -- )
V_76 |= ( 1ULL << V_47 ) ;
if ( V_652 > 2 )
V_76 |= 0xf8 ;
else if ( V_652 == 2 ) {
if ( V_651 & ( 1ULL << 7 ) )
V_76 |= 0x1ff000 ;
else
V_76 |= 0x78 ;
}
return V_76 ;
}
static void F_338 ( struct V_2 * V_3 , T_4 V_651 ,
int V_652 )
{
F_41 ( V_61 L_19 , V_386 , V_651 , V_652 ) ;
F_339 ( ( V_651 & 0x7 ) == 0x2 ) ;
F_339 ( ( V_651 & 0x7 ) == 0x6 ) ;
if ( ! F_15 () )
F_339 ( ( V_651 & 0x7 ) == 0x4 ) ;
if ( ( V_651 & 0x7 ) ) {
T_4 V_655 = V_651 & F_337 ( V_651 , V_652 ) ;
if ( V_655 != 0 ) {
F_41 ( V_61 L_20 ,
V_386 , V_655 ) ;
F_339 ( 1 ) ;
}
if ( V_652 == 1 || ( V_652 == 2 && ( V_651 & ( 1ULL << 7 ) ) ) ) {
T_4 V_656 = ( V_651 & 0x38 ) >> 3 ;
if ( V_656 == 2 || V_656 == 3 ||
V_656 == 7 ) {
F_41 ( V_61 L_21 ,
V_386 , V_656 ) ;
F_339 ( 1 ) ;
}
}
}
}
static int F_340 ( struct V_2 * V_3 )
{
T_4 V_657 [ 4 ] ;
int V_658 , V_47 ;
T_5 V_57 ;
V_57 = F_58 ( V_645 ) ;
F_41 ( V_61 L_22 ) ;
F_41 ( V_61 L_23 , V_57 ) ;
V_658 = F_341 ( V_3 , V_57 , V_657 ) ;
for ( V_47 = V_659 ; V_47 > V_659 - V_658 ; -- V_47 )
F_338 ( V_3 , V_657 [ V_47 - 1 ] , V_47 ) ;
V_3 -> V_580 -> V_590 = V_647 ;
V_3 -> V_580 -> V_648 . V_649 = V_660 ;
return 0 ;
}
static int F_342 ( struct V_2 * V_3 )
{
T_1 V_548 ;
V_548 = F_57 ( V_402 ) ;
V_548 &= ~ V_550 ;
F_65 ( V_402 , V_548 ) ;
++ V_3 -> V_167 . V_661 ;
F_105 ( V_629 , V_3 ) ;
return 1 ;
}
static int F_343 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
enum V_585 V_616 = V_215 ;
int V_80 = 1 ;
T_1 V_662 ;
bool V_663 ;
V_662 = F_57 ( V_402 ) ;
V_663 = V_662 & V_549 ;
while ( ! F_227 ( V_3 ) ) {
if ( V_663
&& ( F_211 ( & V_45 -> V_3 ) & V_564 ) )
return F_317 ( & V_45 -> V_3 ) ;
V_616 = F_273 ( V_3 , 0 ) ;
if ( V_616 == V_664 ) {
V_80 = 0 ;
goto V_454;
}
if ( V_616 != V_215 )
return 0 ;
if ( F_344 ( V_665 ) )
goto V_454;
if ( F_345 () )
F_346 () ;
}
V_45 -> V_347 = 0 ;
V_454:
return V_80 ;
}
static int F_347 ( struct V_2 * V_3 )
{
F_122 ( V_3 ) ;
F_348 ( V_3 ) ;
return 1 ;
}
static int F_349 ( struct V_2 * V_3 )
{
F_274 ( V_3 , V_11 ) ;
return 1 ;
}
static void F_350 ( struct V_2 * V_3 , T_4 * V_666 , T_4 * V_667 )
{
* V_666 = F_55 ( V_598 ) ;
* V_667 = F_57 ( V_668 ) ;
}
static int F_351 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_1 V_590 = V_45 -> V_590 ;
T_1 V_669 = V_45 -> V_587 ;
F_352 ( V_590 , V_3 , V_670 ) ;
if ( V_45 -> V_347 && V_355 )
return F_343 ( V_3 ) ;
if ( V_590 & V_671 ) {
V_3 -> V_580 -> V_590 = V_672 ;
V_3 -> V_580 -> V_673 . V_674
= V_590 ;
return 0 ;
}
if ( F_63 ( V_45 -> V_675 ) ) {
V_3 -> V_580 -> V_590 = V_672 ;
V_3 -> V_580 -> V_673 . V_674
= F_57 ( V_75 ) ;
return 0 ;
}
if ( ( V_669 & V_589 ) &&
( V_590 != V_676 &&
V_590 != V_650 &&
V_590 != V_677 ) )
F_41 ( V_274 L_24
L_25 ,
V_386 , V_669 , V_590 ) ;
if ( F_63 ( ! F_32 () && V_45 -> V_529 ) ) {
if ( F_270 ( V_3 ) ) {
V_45 -> V_529 = 0 ;
} else if ( V_45 -> V_557 > 1000000000LL &&
V_3 -> V_82 . V_678 ) {
F_41 ( V_274 L_26
L_27 ,
V_386 , V_3 -> V_679 ) ;
V_45 -> V_529 = 0 ;
}
}
if ( V_590 < V_680
&& V_681 [ V_590 ] )
return V_681 [ V_590 ] ( V_3 ) ;
else {
V_3 -> V_580 -> V_590 = V_647 ;
V_3 -> V_580 -> V_648 . V_649 = V_590 ;
}
return 0 ;
}
static void V_336 ( struct V_2 * V_3 , int V_682 , int V_683 )
{
if ( V_683 == - 1 || V_682 < V_683 ) {
F_65 ( V_542 , 0 ) ;
return;
}
F_65 ( V_542 , V_683 ) ;
}
static void F_353 ( struct V_1 * V_45 )
{
T_1 V_588 ;
if ( ! ( V_45 -> V_590 == V_684
|| V_45 -> V_590 == V_676 ) )
return;
V_45 -> V_588 = F_57 ( V_668 ) ;
V_588 = V_45 -> V_588 ;
if ( F_7 ( V_588 ) )
F_275 () ;
if ( ( V_588 & V_5 ) == V_561 &&
( V_588 & V_7 ) ) {
F_354 ( & V_45 -> V_3 ) ;
asm("int $2");
F_355 ( & V_45 -> V_3 ) ;
}
}
static void F_356 ( struct V_1 * V_45 )
{
T_1 V_588 ;
bool V_685 ;
T_6 V_686 ;
bool V_687 ;
V_687 = V_45 -> V_587 & V_589 ;
if ( F_32 () ) {
if ( V_45 -> V_559 )
return;
V_588 = F_57 ( V_668 ) ;
V_685 = ( V_588 & V_688 ) != 0 ;
V_686 = V_588 & V_6 ;
if ( ( V_588 & V_7 ) && V_685 &&
V_686 != V_575 && ! V_687 )
F_68 ( V_196 ,
V_562 ) ;
else
V_45 -> V_559 =
! ( F_57 ( V_196 )
& V_562 ) ;
} else if ( F_63 ( V_45 -> V_529 ) )
V_45 -> V_557 +=
F_357 ( F_358 ( F_359 () , V_45 -> V_689 ) ) ;
}
static void F_360 ( struct V_1 * V_45 ,
T_1 V_587 ,
int V_690 ,
int V_691 )
{
T_6 V_686 ;
int type ;
bool V_687 ;
V_687 = V_587 & V_589 ;
V_45 -> V_3 . V_82 . V_639 = false ;
F_334 ( & V_45 -> V_3 ) ;
F_333 ( & V_45 -> V_3 ) ;
if ( ! V_687 )
return;
F_105 ( V_629 , & V_45 -> V_3 ) ;
V_686 = V_587 & V_692 ;
type = V_587 & V_637 ;
switch ( type ) {
case V_561 :
V_45 -> V_3 . V_82 . V_639 = true ;
F_269 ( & V_45 -> V_3 , false ) ;
break;
case V_218 :
V_45 -> V_3 . V_82 . V_214 =
F_57 ( V_690 ) ;
case V_8 :
if ( V_587 & V_640 ) {
T_1 V_616 = F_57 ( V_691 ) ;
F_361 ( & V_45 -> V_3 , V_686 , V_616 ) ;
} else
F_274 ( & V_45 -> V_3 , V_686 ) ;
break;
case V_556 :
V_45 -> V_3 . V_82 . V_214 =
F_57 ( V_690 ) ;
case V_12 :
F_362 ( & V_45 -> V_3 , V_686 ,
type == V_556 ) ;
break;
default:
break;
}
}
static void F_363 ( struct V_1 * V_45 )
{
F_360 ( V_45 , V_45 -> V_587 ,
V_203 ,
V_641 ) ;
}
static void F_364 ( struct V_2 * V_3 )
{
F_360 ( F_1 ( V_3 ) ,
F_57 ( V_219 ) ,
V_217 ,
V_211 ) ;
F_65 ( V_219 , 0 ) ;
}
static void T_15 F_365 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
if ( F_63 ( ! F_32 () && V_45 -> V_529 ) )
V_45 -> V_689 = F_359 () ;
if ( V_45 -> V_347 && V_355 )
return;
if ( F_116 ( V_258 , ( unsigned long * ) & V_3 -> V_82 . V_394 ) )
F_62 ( V_260 , V_3 -> V_82 . V_259 [ V_258 ] ) ;
if ( F_116 ( V_261 , ( unsigned long * ) & V_3 -> V_82 . V_394 ) )
F_62 ( V_262 , V_3 -> V_82 . V_259 [ V_261 ] ) ;
if ( V_3 -> V_98 & V_571 )
F_121 ( V_3 , 0 ) ;
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
#ifdef F_59
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
#ifdef F_59
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
[launched]"i"(offsetof(struct vcpu_vmx, launched)),
[fail]"i"(offsetof(struct vcpu_vmx, fail)),
[host_rsp]"i"(offsetof(struct vcpu_vmx, host_rsp)),
[rax]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RAX])),
[rbx]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RBX])),
[rcx]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RCX])),
[rdx]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RDX])),
[rsi]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RSI])),
[rdi]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RDI])),
[rbp]"i"(offsetof(struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RBP])),
#ifdef F_59
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
#ifdef F_59
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#endif
);
V_3 -> V_82 . V_83 = ~ ( ( 1 << V_261 ) | ( 1 << V_258 )
| ( 1 << V_189 )
| ( 1 << V_192 )
| ( 1 << V_263 )
| ( 1 << V_84 )
| ( 1 << V_391 ) ) ;
V_3 -> V_82 . V_394 = 0 ;
V_45 -> V_587 = F_57 ( V_693 ) ;
asm("mov %0, %%ds; mov %0, %%es" : : "r"(__USER_DS));
V_45 -> V_66 = 1 ;
V_45 -> V_590 = F_57 ( V_694 ) ;
F_353 ( V_45 ) ;
F_356 ( V_45 ) ;
F_363 ( V_45 ) ;
}
static void F_366 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
if ( V_45 -> V_59 ) {
F_47 ( V_45 ) ;
F_169 ( V_45 -> V_59 ) ;
V_45 -> V_59 = NULL ;
}
}
static void F_367 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
F_244 ( V_45 ) ;
F_366 ( V_3 ) ;
F_368 ( V_45 -> V_50 ) ;
F_369 ( V_3 ) ;
F_370 ( V_695 , V_45 ) ;
}
static inline void F_371 ( struct V_59 * V_59 )
{
T_4 V_60 = F_40 ( F_45 ( V_171 , F_44 () ) ) ;
if ( ! V_172 )
F_104 ( V_60 ) ;
F_39 ( V_59 ) ;
if ( ! V_172 )
F_110 () ;
}
static struct V_2 * F_372 ( struct V_18 * V_18 , unsigned int V_696 )
{
int V_616 ;
struct V_1 * V_45 = F_373 ( V_695 , V_330 ) ;
int V_63 ;
if ( ! V_45 )
return F_374 ( - V_331 ) ;
F_240 ( V_45 ) ;
V_616 = F_375 ( & V_45 -> V_3 , V_18 , V_696 ) ;
if ( V_616 )
goto V_697;
V_45 -> V_50 = F_376 ( V_322 , V_330 ) ;
V_616 = - V_331 ;
if ( ! V_45 -> V_50 ) {
goto V_698;
}
V_45 -> V_59 = F_168 () ;
if ( ! V_45 -> V_59 )
goto V_699;
F_371 ( V_45 -> V_59 ) ;
V_63 = F_377 () ;
F_103 ( & V_45 -> V_3 , V_63 ) ;
V_45 -> V_3 . V_63 = V_63 ;
V_616 = F_247 ( V_45 ) ;
F_109 ( & V_45 -> V_3 ) ;
F_378 () ;
if ( V_616 )
goto F_169;
if ( F_29 ( V_18 ) )
V_616 = F_234 ( V_18 ) ;
if ( V_616 )
goto F_169;
if ( V_70 ) {
if ( ! V_18 -> V_82 . V_415 )
V_18 -> V_82 . V_415 =
V_700 ;
V_616 = - V_331 ;
if ( F_239 ( V_18 ) != 0 )
goto F_169;
if ( ! F_231 ( V_18 ) )
goto F_169;
}
return & V_45 -> V_3 ;
F_169:
F_169 ( V_45 -> V_59 ) ;
V_699:
F_368 ( V_45 -> V_50 ) ;
V_698:
F_369 ( & V_45 -> V_3 ) ;
V_697:
F_244 ( V_45 ) ;
F_370 ( V_695 , V_45 ) ;
return F_374 ( V_616 ) ;
}
static void T_10 F_379 ( void * V_701 )
{
struct V_14 V_289 ;
* ( int * ) V_701 = 0 ;
if ( F_162 ( & V_289 ) < 0 )
* ( int * ) V_701 = - V_288 ;
if ( memcmp ( & V_14 , & V_289 , sizeof( struct V_14 ) ) != 0 ) {
F_41 ( V_61 L_28 ,
F_380 () ) ;
* ( int * ) V_701 = - V_288 ;
}
}
static int F_381 ( void )
{
return V_410 + 1 ;
}
static T_4 F_382 ( struct V_2 * V_3 , T_12 V_702 , bool V_703 )
{
T_4 V_80 ;
if ( V_703 )
V_80 = V_704 << V_705 ;
else if ( V_3 -> V_18 -> V_82 . V_706 &&
! ( V_3 -> V_18 -> V_82 . V_707 & V_708 ) )
V_80 = F_383 ( V_3 , V_702 ) <<
V_705 ;
else
V_80 = ( V_709 << V_705 )
| V_710 ;
return V_80 ;
}
static int F_384 ( void )
{
if ( V_70 && ! F_19 () )
return V_711 ;
else
return V_712 ;
}
static void F_385 ( struct V_2 * V_3 )
{
struct V_713 * V_714 ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_1 V_489 ;
V_45 -> V_228 = false ;
if ( F_129 () ) {
V_489 = F_57 ( V_496 ) ;
if ( V_489 & V_41 ) {
V_714 = F_386 ( V_3 , 0x80000001 , 0 ) ;
if ( V_714 && ( V_714 -> V_715 & F_387 ( V_716 ) ) )
V_45 -> V_228 = true ;
else {
V_489 &= ~ V_41 ;
F_65 ( V_496 ,
V_489 ) ;
}
}
}
}
static void F_388 ( T_1 V_717 , struct V_713 * V_718 )
{
}
static int F_389 ( struct V_2 * V_3 ,
struct V_719 * V_720 ,
enum V_721 V_722 )
{
return V_723 ;
}
static int T_10 F_390 ( void )
{
int V_452 , V_47 ;
F_391 ( V_108 , & V_138 ) ;
for ( V_47 = 0 ; V_47 < V_522 ; ++ V_47 )
F_392 ( V_47 , V_49 [ V_47 ] ) ;
V_491 = ( unsigned long * ) F_393 ( V_330 ) ;
if ( ! V_491 )
return - V_331 ;
V_493 = ( unsigned long * ) F_393 ( V_330 ) ;
if ( ! V_493 ) {
V_452 = - V_331 ;
goto V_454;
}
V_231 = ( unsigned long * ) F_393 ( V_330 ) ;
if ( ! V_231 ) {
V_452 = - V_331 ;
goto V_724;
}
V_230 = ( unsigned long * ) F_393 ( V_330 ) ;
if ( ! V_230 ) {
V_452 = - V_331 ;
goto V_725;
}
memset ( V_491 , 0xff , V_322 ) ;
F_394 ( 0x80 , V_491 ) ;
memset ( V_493 , 0xff , V_322 ) ;
memset ( V_231 , 0xff , V_322 ) ;
memset ( V_230 , 0xff , V_322 ) ;
F_395 ( 0 , V_478 ) ;
V_452 = F_396 ( & V_726 , sizeof( struct V_1 ) ,
F_397 ( struct V_1 ) , V_727 ) ;
if ( V_452 )
goto V_728;
F_246 ( V_160 , false ) ;
F_246 ( V_162 , false ) ;
F_246 ( V_163 , true ) ;
F_246 ( V_246 , false ) ;
F_246 ( V_178 , false ) ;
F_246 ( V_248 , false ) ;
if ( V_70 ) {
V_501 = 0 ;
F_398 ( 0ull , 0ull , 0ull , 0ull ,
V_729 ) ;
F_399 () ;
} else
F_400 () ;
if ( V_501 )
F_401 ( ~ 0xffeull , 0ull ) ;
return 0 ;
V_728:
F_402 ( ( unsigned long ) V_230 ) ;
V_725:
F_402 ( ( unsigned long ) V_231 ) ;
V_724:
F_402 ( ( unsigned long ) V_493 ) ;
V_454:
F_402 ( ( unsigned long ) V_491 ) ;
return V_452 ;
}
static void T_11 F_403 ( void )
{
F_402 ( ( unsigned long ) V_231 ) ;
F_402 ( ( unsigned long ) V_230 ) ;
F_402 ( ( unsigned long ) V_493 ) ;
F_402 ( ( unsigned long ) V_491 ) ;
F_404 () ;
}
