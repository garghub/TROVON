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
if ( F_7 ( V_10 ) )
return NULL ;
return V_10 ;
}
static void F_8 ( struct V_10 * V_10 )
{
F_9 ( V_10 ) ;
}
static void F_10 ( struct V_10 * V_10 )
{
F_11 ( V_10 ) ;
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
return V_24 . V_29 &
V_51 ;
}
static inline bool F_42 ( void )
{
return V_24 . V_52 & V_53 ;
}
static inline bool F_43 ( void )
{
return V_24 . V_29 &
V_54 ;
}
static inline bool F_44 ( void )
{
return V_48 ;
}
static inline bool F_45 ( struct V_7 * V_7 , T_2 V_55 )
{
return V_7 -> V_56 & V_55 ;
}
static inline bool F_46 ( struct V_7 * V_7 , T_2 V_55 )
{
return ( V_7 -> V_56 &
V_28 ) &&
( V_7 -> V_57 & V_55 ) ;
}
static inline bool F_47 ( struct V_7 * V_7 ,
struct V_2 * V_3 )
{
return V_7 -> V_58 & V_53 ;
}
static inline bool F_48 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_17 ) )
== ( V_18 | V_17 ) ;
}
static int F_49 ( struct V_1 * V_59 , T_2 V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_59 -> V_62 ; ++ V_61 )
if ( V_63 [ V_59 -> V_64 [ V_61 ] . V_65 ] == V_60 )
return V_61 ;
return - 1 ;
}
static inline void F_50 ( int V_66 , T_3 V_42 , T_4 V_67 )
{
struct {
T_5 V_42 : 16 ;
T_5 V_68 : 48 ;
T_5 V_67 ;
} V_69 = { V_42 , 0 , V_67 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_51 ( int V_66 , T_5 V_70 , T_1 V_71 )
{
struct {
T_5 V_70 , V_71 ;
} V_69 = { V_70 , V_71 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_72 * F_52 ( struct V_1 * V_59 , T_2 V_60 )
{
int V_61 ;
V_61 = F_49 ( V_59 , V_60 ) ;
if ( V_61 >= 0 )
return & V_59 -> V_64 [ V_61 ] ;
return NULL ;
}
static void F_53 ( struct V_73 * V_73 )
{
T_5 V_74 = F_54 ( V_73 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_55 ( V_75 L_1 ,
V_73 , V_74 ) ;
}
static inline void F_56 ( struct V_76 * V_76 )
{
F_53 ( V_76 -> V_73 ) ;
V_76 -> V_77 = - 1 ;
V_76 -> V_78 = 0 ;
}
static void F_57 ( struct V_73 * V_73 )
{
T_5 V_74 = F_54 ( V_73 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_55 ( V_75 L_2 ,
V_73 , V_74 ) ;
}
static inline void F_58 ( int V_77 )
{
F_59 ( V_77 , & V_79 ) ;
}
static inline void F_60 ( int V_77 )
{
F_61 ( V_77 , & V_79 ) ;
}
static inline int F_62 ( int V_77 )
{
return F_63 ( V_77 , & V_79 ) ;
}
static void F_64 ( void )
{
int V_77 = F_65 () ;
struct V_76 * V_80 ;
if ( ! F_62 ( V_77 ) )
return;
F_66 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_53 ( V_80 -> V_73 ) ;
}
static inline void F_58 ( int V_77 ) { }
static inline void F_60 ( int V_77 ) { }
static void F_67 ( void * V_81 )
{
struct V_76 * V_76 = V_81 ;
int V_77 = F_65 () ;
if ( V_76 -> V_77 != V_77 )
return;
if ( F_68 ( V_82 , V_77 ) == V_76 -> V_73 )
F_68 ( V_82 , V_77 ) = NULL ;
F_60 ( V_77 ) ;
F_69 ( & V_76 -> V_83 ) ;
F_70 () ;
F_56 ( V_76 ) ;
F_58 ( V_77 ) ;
}
static void F_71 ( struct V_76 * V_76 )
{
int V_77 = V_76 -> V_77 ;
if ( V_77 != - 1 )
F_72 ( V_77 ,
F_67 , V_76 , 1 ) ;
}
static inline void F_73 ( struct V_1 * V_59 )
{
if ( V_59 -> V_42 == 0 )
return;
if ( F_33 () )
F_50 ( V_84 , V_59 -> V_42 , 0 ) ;
}
static inline void F_74 ( void )
{
if ( F_34 () )
F_50 ( V_85 , 0 , 0 ) ;
}
static inline void F_75 ( struct V_1 * V_59 )
{
if ( F_33 () )
F_73 ( V_59 ) ;
else
F_74 () ;
}
static inline void F_76 ( void )
{
if ( F_32 () )
F_51 ( V_86 , 0 , 0 ) ;
}
static inline void F_77 ( T_5 V_70 )
{
if ( V_87 ) {
if ( F_31 () )
F_51 ( V_88 , V_70 , 0 ) ;
else
F_76 () ;
}
}
static T_7 unsigned long F_78 ( unsigned long V_4 )
{
unsigned long V_89 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_89 ;
}
static T_7 T_3 F_79 ( unsigned long V_4 )
{
return F_78 ( V_4 ) ;
}
static T_7 T_2 F_80 ( unsigned long V_4 )
{
return F_78 ( V_4 ) ;
}
static T_7 T_5 F_81 ( unsigned long V_4 )
{
#ifdef F_82
return F_78 ( V_4 ) ;
#else
return F_78 ( V_4 ) | ( ( T_5 ) F_78 ( V_4 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_83 ( unsigned long V_4 , unsigned long V_89 )
{
F_55 ( V_75 L_3 ,
V_4 , V_89 , F_80 ( V_90 ) ) ;
F_84 () ;
}
static void F_85 ( unsigned long V_4 , unsigned long V_89 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_86 ( error ) )
F_83 ( V_4 , V_89 ) ;
}
static void F_87 ( unsigned long V_4 , T_3 V_89 )
{
F_85 ( V_4 , V_89 ) ;
}
static void F_88 ( unsigned long V_4 , T_2 V_89 )
{
F_85 ( V_4 , V_89 ) ;
}
static void F_89 ( unsigned long V_4 , T_5 V_89 )
{
F_85 ( V_4 , V_89 ) ;
#ifndef F_82
asm volatile ("");
F_85 ( V_4 + 1 , V_89 >> 32 ) ;
#endif
}
static void F_90 ( unsigned long V_4 , T_2 V_91 )
{
F_85 ( V_4 , F_78 ( V_4 ) & ~ V_91 ) ;
}
static void F_91 ( unsigned long V_4 , T_2 V_91 )
{
F_85 ( V_4 , F_78 ( V_4 ) | V_91 ) ;
}
static void F_92 ( struct V_1 * V_59 )
{
V_59 -> V_92 . V_93 = 0 ;
}
static bool F_93 ( struct V_1 * V_59 , unsigned V_94 ,
unsigned V_4 )
{
bool V_95 ;
T_2 V_91 = 1 << ( V_94 * V_96 + V_4 ) ;
if ( ! ( V_59 -> V_3 . V_97 . V_98 & ( 1 << V_99 ) ) ) {
V_59 -> V_3 . V_97 . V_98 |= ( 1 << V_99 ) ;
V_59 -> V_92 . V_93 = 0 ;
}
V_95 = V_59 -> V_92 . V_93 & V_91 ;
V_59 -> V_92 . V_93 |= V_91 ;
return V_95 ;
}
static T_3 F_94 ( struct V_1 * V_59 , unsigned V_94 )
{
T_3 * V_100 = & V_59 -> V_92 . V_94 [ V_94 ] . V_101 ;
if ( ! F_93 ( V_59 , V_94 , V_102 ) )
* V_100 = F_79 ( V_103 [ V_94 ] . V_101 ) ;
return * V_100 ;
}
static T_9 F_95 ( struct V_1 * V_59 , unsigned V_94 )
{
T_9 * V_100 = & V_59 -> V_92 . V_94 [ V_94 ] . V_104 ;
if ( ! F_93 ( V_59 , V_94 , V_105 ) )
* V_100 = F_78 ( V_103 [ V_94 ] . V_104 ) ;
return * V_100 ;
}
static T_2 F_96 ( struct V_1 * V_59 , unsigned V_94 )
{
T_2 * V_100 = & V_59 -> V_92 . V_94 [ V_94 ] . V_106 ;
if ( ! F_93 ( V_59 , V_94 , V_107 ) )
* V_100 = F_80 ( V_103 [ V_94 ] . V_106 ) ;
return * V_100 ;
}
static T_2 F_97 ( struct V_1 * V_59 , unsigned V_94 )
{
T_2 * V_100 = & V_59 -> V_92 . V_94 [ V_94 ] . V_108 ;
if ( ! F_93 ( V_59 , V_94 , V_109 ) )
* V_100 = F_80 ( V_103 [ V_94 ] . V_110 ) ;
return * V_100 ;
}
static void F_98 ( struct V_2 * V_3 )
{
T_2 V_111 ;
V_111 = ( 1u << V_19 ) | ( 1u << V_21 ) | ( 1u << V_23 ) |
( 1u << V_20 ) | ( 1u << V_112 ) ;
if ( ( V_3 -> V_113 &
( V_114 | V_115 ) ) ==
( V_114 | V_115 ) )
V_111 |= 1u << V_116 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 )
V_111 = ~ 0 ;
if ( V_87 )
V_111 &= ~ ( 1u << V_19 ) ;
if ( V_3 -> V_119 )
V_111 &= ~ ( 1u << V_20 ) ;
if ( F_99 ( V_3 ) )
V_111 |= F_4 ( V_3 ) -> V_120 ;
F_88 ( V_121 , V_111 ) ;
}
static void F_100 ( unsigned long V_122 ,
unsigned long exit )
{
F_90 ( V_123 , V_122 ) ;
F_90 ( V_124 , exit ) ;
}
static void F_101 ( struct V_1 * V_59 , unsigned V_60 )
{
unsigned V_61 ;
struct V_125 * V_126 = & V_59 -> V_125 ;
switch ( V_60 ) {
case V_127 :
if ( V_128 ) {
F_100 ( V_129 ,
V_130 ) ;
return;
}
break;
case V_131 :
if ( V_132 ) {
F_100 (
V_133 ,
V_134 ) ;
return;
}
break;
}
for ( V_61 = 0 ; V_61 < V_126 -> V_135 ; ++ V_61 )
if ( V_126 -> V_136 [ V_61 ] . V_65 == V_60 )
break;
if ( V_61 == V_126 -> V_135 )
return;
-- V_126 -> V_135 ;
V_126 -> V_136 [ V_61 ] = V_126 -> V_136 [ V_126 -> V_135 ] ;
V_126 -> V_137 [ V_61 ] = V_126 -> V_137 [ V_126 -> V_135 ] ;
F_88 ( V_138 , V_126 -> V_135 ) ;
F_88 ( V_139 , V_126 -> V_135 ) ;
}
static void F_102 ( unsigned long V_122 ,
unsigned long exit , unsigned long V_140 ,
unsigned long V_141 , T_5 V_142 , T_5 V_143 )
{
F_89 ( V_140 , V_142 ) ;
F_89 ( V_141 , V_143 ) ;
F_91 ( V_123 , V_122 ) ;
F_91 ( V_124 , exit ) ;
}
static void F_103 ( struct V_1 * V_59 , unsigned V_60 ,
T_5 V_142 , T_5 V_143 )
{
unsigned V_61 ;
struct V_125 * V_126 = & V_59 -> V_125 ;
switch ( V_60 ) {
case V_127 :
if ( V_128 ) {
F_102 ( V_129 ,
V_130 ,
V_144 ,
V_145 ,
V_142 , V_143 ) ;
return;
}
break;
case V_131 :
if ( V_132 ) {
F_102 (
V_133 ,
V_134 ,
V_146 ,
V_147 ,
V_142 , V_143 ) ;
return;
}
break;
}
for ( V_61 = 0 ; V_61 < V_126 -> V_135 ; ++ V_61 )
if ( V_126 -> V_136 [ V_61 ] . V_65 == V_60 )
break;
if ( V_61 == V_148 ) {
F_104 ( V_149 L_4
L_5 , V_60 ) ;
return;
} else if ( V_61 == V_126 -> V_135 ) {
++ V_126 -> V_135 ;
F_88 ( V_138 , V_126 -> V_135 ) ;
F_88 ( V_139 , V_126 -> V_135 ) ;
}
V_126 -> V_136 [ V_61 ] . V_65 = V_60 ;
V_126 -> V_136 [ V_61 ] . V_89 = V_142 ;
V_126 -> V_137 [ V_61 ] . V_65 = V_60 ;
V_126 -> V_137 [ V_61 ] . V_89 = V_143 ;
}
static void F_105 ( void )
{
struct V_150 * V_151 = & F_106 ( V_152 ) ;
struct V_153 * V_154 ;
V_154 = ( void * ) V_151 -> V_155 ;
V_154 [ V_156 ] . type = 9 ;
F_107 () ;
}
static bool F_108 ( struct V_1 * V_59 , int V_157 )
{
T_5 V_158 ;
T_5 V_159 ;
V_158 = V_59 -> V_3 . V_97 . V_160 ;
V_159 = V_161 | V_162 ;
#ifdef F_82
V_159 |= V_163 | V_164 ;
if ( V_158 & V_163 )
V_159 &= ~ ( T_5 ) V_162 ;
#endif
V_158 &= ~ V_159 ;
V_158 |= V_165 & V_159 ;
V_59 -> V_64 [ V_157 ] . V_166 = V_158 ;
V_59 -> V_64 [ V_157 ] . V_91 = ~ V_159 ;
F_101 ( V_59 , V_127 ) ;
if ( V_87 && ( ( V_59 -> V_3 . V_97 . V_160 ^ V_165 ) & V_161 ) ) {
V_158 = V_59 -> V_3 . V_97 . V_160 ;
if ( ! ( V_158 & V_163 ) )
V_158 &= ~ V_164 ;
F_103 ( V_59 , V_127 , V_158 , V_165 ) ;
return false ;
}
return true ;
}
static unsigned long F_109 ( T_3 V_101 )
{
struct V_150 * V_151 = & F_106 ( V_152 ) ;
struct V_153 * V_167 ;
unsigned long V_168 ;
unsigned long V_80 ;
if ( ! ( V_101 & ~ 3 ) )
return 0 ;
V_168 = V_151 -> V_155 ;
if ( V_101 & 4 ) {
T_3 V_169 = F_110 () ;
if ( ! ( V_169 & ~ 3 ) )
return 0 ;
V_168 = F_109 ( V_169 ) ;
}
V_167 = (struct V_153 * ) ( V_168 + ( V_101 & ~ 7 ) ) ;
V_80 = F_111 ( V_167 ) ;
#ifdef F_82
if ( V_167 -> V_170 == 0 && ( V_167 -> type == 2 || V_167 -> type == 9 || V_167 -> type == 11 ) )
V_80 |= ( ( unsigned long ) ( (struct V_171 * ) V_167 ) -> V_172 ) << 32 ;
#endif
return V_80 ;
}
static inline unsigned long F_112 ( void )
{
T_3 V_173 ;
asm("str %0" : "=g"(tr));
return F_109 ( V_173 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
int V_61 ;
if ( V_59 -> V_174 . V_175 )
return;
V_59 -> V_174 . V_175 = 1 ;
V_59 -> V_174 . V_176 = F_110 () ;
V_59 -> V_174 . V_177 = V_59 -> V_174 . V_176 ;
F_114 ( V_178 , V_59 -> V_174 . V_179 ) ;
if ( ! ( V_59 -> V_174 . V_179 & 7 ) ) {
F_87 ( V_180 , V_59 -> V_174 . V_179 ) ;
V_59 -> V_174 . V_181 = 0 ;
} else {
F_87 ( V_180 , 0 ) ;
V_59 -> V_174 . V_181 = 1 ;
}
F_114 ( V_182 , V_59 -> V_174 . V_183 ) ;
if ( ! ( V_59 -> V_174 . V_183 & 7 ) )
F_87 ( V_184 , V_59 -> V_174 . V_183 ) ;
else {
F_87 ( V_184 , 0 ) ;
V_59 -> V_174 . V_177 = 1 ;
}
#ifdef F_82
F_114 ( V_185 , V_59 -> V_174 . V_186 ) ;
F_114 ( V_187 , V_59 -> V_174 . V_188 ) ;
#endif
#ifdef F_82
F_85 ( V_189 , F_115 ( V_190 ) ) ;
F_85 ( V_191 , F_115 ( V_192 ) ) ;
#else
F_85 ( V_189 , F_109 ( V_59 -> V_174 . V_179 ) ) ;
F_85 ( V_191 , F_109 ( V_59 -> V_174 . V_183 ) ) ;
#endif
#ifdef F_82
F_116 ( V_193 , V_59 -> V_194 ) ;
if ( F_117 ( & V_59 -> V_3 ) )
F_118 ( V_193 , V_59 -> V_195 ) ;
#endif
for ( V_61 = 0 ; V_61 < V_59 -> V_196 ; ++ V_61 )
F_119 ( V_59 -> V_64 [ V_61 ] . V_65 ,
V_59 -> V_64 [ V_61 ] . V_166 ,
V_59 -> V_64 [ V_61 ] . V_91 ) ;
}
static void F_120 ( struct V_1 * V_59 )
{
if ( ! V_59 -> V_174 . V_175 )
return;
++ V_59 -> V_3 . V_197 . V_198 ;
V_59 -> V_174 . V_175 = 0 ;
#ifdef F_82
if ( F_117 ( & V_59 -> V_3 ) )
F_116 ( V_193 , V_59 -> V_195 ) ;
#endif
if ( V_59 -> V_174 . V_177 ) {
F_121 ( V_59 -> V_174 . V_176 ) ;
#ifdef F_82
F_122 ( V_59 -> V_174 . V_183 ) ;
#else
F_123 ( V_182 , V_59 -> V_174 . V_183 ) ;
#endif
}
if ( V_59 -> V_174 . V_181 )
F_123 ( V_178 , V_59 -> V_174 . V_179 ) ;
#ifdef F_82
if ( F_86 ( V_59 -> V_174 . V_186 | V_59 -> V_174 . V_188 ) ) {
F_123 ( V_185 , V_59 -> V_174 . V_186 ) ;
F_123 ( V_187 , V_59 -> V_174 . V_188 ) ;
}
#endif
F_105 () ;
#ifdef F_82
F_118 ( V_193 , V_59 -> V_194 ) ;
#endif
if ( ! F_124 () && ! V_59 -> V_3 . V_199 )
F_125 () ;
F_126 ( & F_106 ( V_152 ) ) ;
}
static void F_127 ( struct V_1 * V_59 )
{
F_128 () ;
F_120 ( V_59 ) ;
F_129 () ;
}
static void F_130 ( struct V_2 * V_3 , int V_77 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_5 V_74 = F_54 ( F_68 ( V_200 , V_77 ) ) ;
if ( ! V_201 )
F_131 ( V_74 ) ;
else if ( V_59 -> V_76 -> V_77 != V_77 )
F_71 ( V_59 -> V_76 ) ;
if ( F_68 ( V_82 , V_77 ) != V_59 -> V_76 -> V_73 ) {
F_68 ( V_82 , V_77 ) = V_59 -> V_76 -> V_73 ;
F_57 ( V_59 -> V_76 -> V_73 ) ;
}
if ( V_59 -> V_76 -> V_77 != V_77 ) {
struct V_150 * V_151 = & F_106 ( V_152 ) ;
unsigned long V_202 ;
F_132 ( V_203 , V_3 ) ;
F_133 () ;
F_60 ( V_77 ) ;
F_134 () ;
F_135 ( & V_59 -> V_76 -> V_83 ,
& F_68 ( V_204 , V_77 ) ) ;
F_58 ( V_77 ) ;
F_136 () ;
F_85 ( V_205 , F_112 () ) ;
F_85 ( V_206 , V_151 -> V_155 ) ;
F_116 ( V_207 , V_202 ) ;
F_85 ( V_208 , V_202 ) ;
V_59 -> V_76 -> V_77 = V_77 ;
}
}
static void F_137 ( struct V_2 * V_3 )
{
F_120 ( F_1 ( V_3 ) ) ;
if ( ! V_201 ) {
F_67 ( F_1 ( V_3 ) -> V_76 ) ;
V_3 -> V_77 = - 1 ;
F_138 () ;
}
}
static void F_139 ( struct V_2 * V_3 )
{
T_9 V_209 ;
if ( V_3 -> V_119 )
return;
V_3 -> V_119 = 1 ;
V_209 = F_78 ( V_210 ) ;
V_209 &= ~ ( V_211 | V_212 ) ;
V_209 |= F_140 ( V_3 , V_211 | V_212 ) ;
F_85 ( V_210 , V_209 ) ;
F_98 ( V_3 ) ;
V_3 -> V_97 . V_213 = V_211 ;
if ( F_99 ( V_3 ) )
V_3 -> V_97 . V_213 &=
~ F_4 ( V_3 ) -> V_214 ;
F_85 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
}
static inline unsigned long F_141 ( struct V_7 * V_216 )
{
return ( V_216 -> V_217 & ~ V_216 -> V_214 ) |
( V_216 -> V_218 & V_216 -> V_214 ) ;
}
static inline unsigned long F_142 ( struct V_7 * V_216 )
{
return ( V_216 -> V_219 & ~ V_216 -> V_220 ) |
( V_216 -> V_221 & V_216 -> V_220 ) ;
}
static void F_143 ( struct V_2 * V_3 )
{
F_144 ( V_3 ) ;
F_91 ( V_210 , V_211 | V_212 ) ;
F_98 ( V_3 ) ;
V_3 -> V_97 . V_213 = 0 ;
F_85 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
if ( F_99 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_217 = ( V_7 -> V_217 & ~ V_211 ) |
( V_3 -> V_97 . V_209 & V_211 ) ;
F_85 ( V_222 , F_141 ( V_7 ) ) ;
} else
F_85 ( V_222 , V_3 -> V_97 . V_209 ) ;
}
static unsigned long F_145 ( struct V_2 * V_3 )
{
unsigned long V_223 , V_224 ;
if ( ! F_146 ( V_225 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ) {
F_147 ( V_225 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
V_223 = F_78 ( V_226 ) ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
V_223 &= V_227 ;
V_224 = F_1 ( V_3 ) -> V_117 . V_224 ;
V_223 |= V_224 & ~ V_227 ;
}
F_1 ( V_3 ) -> V_223 = V_223 ;
}
return F_1 ( V_3 ) -> V_223 ;
}
static void F_148 ( struct V_2 * V_3 , unsigned long V_223 )
{
F_147 ( V_225 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
F_149 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
F_1 ( V_3 ) -> V_223 = V_223 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
F_1 ( V_3 ) -> V_117 . V_224 = V_223 ;
V_223 |= V_229 | V_230 ;
}
F_85 ( V_226 , V_223 ) ;
}
static T_2 F_150 ( struct V_2 * V_3 , int V_91 )
{
T_2 V_231 = F_80 ( V_232 ) ;
int V_95 = 0 ;
if ( V_231 & V_233 )
V_95 |= V_234 ;
if ( V_231 & V_235 )
V_95 |= V_236 ;
return V_95 & V_91 ;
}
static void F_151 ( struct V_2 * V_3 , int V_91 )
{
T_2 V_237 = F_80 ( V_232 ) ;
T_2 V_231 = V_237 ;
V_231 &= ~ ( V_233 | V_235 ) ;
if ( V_91 & V_236 )
V_231 |= V_235 ;
else if ( V_91 & V_234 )
V_231 |= V_233 ;
if ( ( V_231 != V_237 ) )
F_88 ( V_232 , V_231 ) ;
}
static void F_152 ( struct V_2 * V_3 )
{
unsigned long V_238 ;
V_238 = F_153 ( V_3 ) ;
V_238 += F_80 ( V_239 ) ;
F_154 ( V_3 , V_238 ) ;
F_151 ( V_3 , 0 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( ! ( V_7 -> V_120 & ( 1u << V_19 ) ) )
return 0 ;
F_156 ( V_3 ) ;
return 1 ;
}
static void F_157 ( struct V_2 * V_3 , unsigned V_135 ,
bool V_240 , T_2 V_241 ,
bool V_242 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_2 V_14 = V_135 | V_17 ;
if ( V_135 == V_19 && F_99 ( V_3 ) &&
F_155 ( V_3 ) )
return;
if ( V_240 ) {
F_88 ( V_243 , V_241 ) ;
V_14 |= V_244 ;
}
if ( V_59 -> V_117 . V_118 ) {
int V_245 = 0 ;
if ( F_158 ( V_135 ) )
V_245 = V_3 -> V_97 . V_246 ;
if ( F_159 ( V_3 , V_135 , V_245 ) != V_247 )
F_132 ( V_248 , V_3 ) ;
return;
}
if ( F_158 ( V_135 ) ) {
F_88 ( V_249 ,
V_59 -> V_3 . V_97 . V_246 ) ;
V_14 |= V_250 ;
} else
V_14 |= V_18 ;
F_88 ( V_251 , V_14 ) ;
}
static bool F_160 ( void )
{
return F_40 () ;
}
static bool F_161 ( void )
{
return F_41 () && V_87 ;
}
static void F_162 ( struct V_1 * V_59 , int V_252 , int V_253 )
{
struct V_72 V_254 ;
V_254 = V_59 -> V_64 [ V_253 ] ;
V_59 -> V_64 [ V_253 ] = V_59 -> V_64 [ V_252 ] ;
V_59 -> V_64 [ V_252 ] = V_254 ;
}
static void F_163 ( struct V_1 * V_59 )
{
int V_196 , V_65 ;
unsigned long * V_255 ;
V_196 = 0 ;
#ifdef F_82
if ( F_117 ( & V_59 -> V_3 ) ) {
V_65 = F_49 ( V_59 , V_256 ) ;
if ( V_65 >= 0 )
F_162 ( V_59 , V_65 , V_196 ++ ) ;
V_65 = F_49 ( V_59 , V_257 ) ;
if ( V_65 >= 0 )
F_162 ( V_59 , V_65 , V_196 ++ ) ;
V_65 = F_49 ( V_59 , V_258 ) ;
if ( V_65 >= 0 )
F_162 ( V_59 , V_65 , V_196 ++ ) ;
V_65 = F_49 ( V_59 , V_259 ) ;
if ( V_65 >= 0 && V_59 -> V_260 )
F_162 ( V_59 , V_65 , V_196 ++ ) ;
V_65 = F_49 ( V_59 , V_261 ) ;
if ( ( V_65 >= 0 ) && ( V_59 -> V_3 . V_97 . V_160 & V_162 ) )
F_162 ( V_59 , V_65 , V_196 ++ ) ;
}
#endif
V_65 = F_49 ( V_59 , V_127 ) ;
if ( V_65 >= 0 && F_108 ( V_59 , V_65 ) )
F_162 ( V_59 , V_65 , V_196 ++ ) ;
V_59 -> V_196 = V_196 ;
if ( F_17 () ) {
if ( F_117 ( & V_59 -> V_3 ) )
V_255 = V_262 ;
else
V_255 = V_263 ;
F_89 ( V_264 , F_54 ( V_255 ) ) ;
}
}
static T_5 F_164 ( void )
{
T_5 V_265 , V_266 ;
F_165 ( V_265 ) ;
V_266 = F_81 ( V_267 ) ;
return V_265 + V_266 ;
}
T_5 F_166 ( struct V_2 * V_3 , T_5 V_265 )
{
T_5 V_266 ;
V_266 = F_99 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_268 :
F_81 ( V_267 ) ;
return V_265 + V_266 ;
}
static void F_167 ( struct V_2 * V_3 , T_2 V_269 , bool V_270 )
{
if ( ! V_270 )
return;
if ( V_269 > V_271 ) {
V_3 -> V_97 . V_272 = 1 ;
V_3 -> V_97 . V_273 = 1 ;
} else
F_168 ( 1 , L_6 ) ;
}
static T_5 F_169 ( struct V_2 * V_3 )
{
return F_81 ( V_267 ) ;
}
static void F_170 ( struct V_2 * V_3 , T_5 V_274 )
{
if ( F_99 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_268 = V_274 ;
V_7 = F_4 ( V_3 ) ;
F_89 ( V_267 , V_274 +
( F_45 ( V_7 , V_275 ) ?
V_7 -> V_266 : 0 ) ) ;
} else {
F_89 ( V_267 , V_274 ) ;
}
}
static void F_171 ( struct V_2 * V_3 , T_10 V_276 , bool V_137 )
{
T_5 V_274 = F_81 ( V_267 ) ;
F_89 ( V_267 , V_274 + V_276 ) ;
if ( F_99 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_268 += V_276 ;
}
}
static T_5 F_172 ( struct V_2 * V_3 , T_5 V_277 )
{
return V_277 - F_173 () ;
}
static bool F_174 ( struct V_2 * V_3 )
{
struct V_278 * V_279 = F_175 ( V_3 , 1 , 0 ) ;
return V_279 && ( V_279 -> V_280 & ( 1 << ( V_281 & 31 ) ) ) ;
}
static inline bool F_176 ( struct V_2 * V_3 )
{
return V_8 && F_174 ( V_3 ) ;
}
static T_11 void F_177 ( void )
{
V_282 = 0x16 ;
V_283 = 0x16 |
V_284 | V_285 |
V_53 ;
V_286 = 0 ;
#ifdef F_82
V_287 = V_288 ;
#else
V_287 = 0 ;
#endif
F_178 ( V_289 ,
V_290 , V_291 ) ;
V_290 = 0 ;
V_291 &=
V_292 | V_293 ;
F_178 ( V_294 ,
V_295 , V_296 ) ;
V_295 = 0 ;
V_296 &=
V_297 | V_275 |
V_298 | V_299 |
V_300 | V_301 |
V_302 |
#ifdef F_82
V_303 | V_304 |
#endif
V_305 | V_306 |
V_307 | V_308 |
V_309 | V_310 |
V_28 ;
V_296 |= V_26 ;
F_178 ( V_311 ,
V_312 , V_313 ) ;
V_312 = 0 ;
V_313 &=
V_30 ;
}
static inline bool F_179 ( T_2 V_314 , T_2 V_315 , T_2 V_316 )
{
return ( ( V_314 & V_316 ) | V_315 ) == V_314 ;
}
static inline T_5 F_180 ( T_2 V_315 , T_2 V_316 )
{
return V_315 | ( ( T_5 ) V_316 << 32 ) ;
}
static int F_181 ( struct V_2 * V_3 , T_2 V_317 , T_5 * V_318 )
{
if ( ! F_176 ( V_3 ) && V_317 >= V_319 &&
V_317 <= V_320 ) {
F_182 ( V_3 , V_321 , 0 ) ;
return 1 ;
}
switch ( V_317 ) {
case V_322 :
* V_318 = 0 ;
break;
case V_319 :
* V_318 = V_323 |
( ( T_5 ) V_324 << V_325 ) |
( V_326 << V_327 ) ;
break;
case V_328 :
case V_329 :
* V_318 = F_180 ( V_282 ,
V_283 ) ;
break;
case V_330 :
case V_294 :
* V_318 = F_180 ( V_295 ,
V_296 ) ;
break;
case V_331 :
case V_332 :
* V_318 = F_180 ( V_286 ,
V_287 ) ;
break;
case V_320 :
case V_289 :
* V_318 = F_180 ( V_290 ,
V_291 ) ;
break;
case V_333 :
* V_318 = 0 ;
break;
#define F_183 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_184 X86_CR4_VMXE
case V_334 :
* V_318 = F_183 ;
break;
case V_335 :
* V_318 = - 1ULL ;
break;
case V_336 :
* V_318 = F_184 ;
break;
case V_337 :
* V_318 = - 1ULL ;
break;
case V_338 :
* V_318 = 0x1f ;
break;
case V_311 :
* V_318 = F_180 ( V_312 ,
V_313 ) ;
break;
case V_339 :
* V_318 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_185 ( struct V_2 * V_3 , T_2 V_317 , T_5 V_166 )
{
if ( ! F_176 ( V_3 ) )
return 0 ;
if ( V_317 == V_322 )
return 1 ;
return 0 ;
}
static int F_186 ( struct V_2 * V_3 , T_2 V_317 , T_5 * V_318 )
{
T_5 V_166 ;
struct V_72 * V_60 ;
if ( ! V_318 ) {
F_55 ( V_75 L_7 ) ;
return - V_340 ;
}
switch ( V_317 ) {
#ifdef F_82
case V_190 :
V_166 = F_78 ( V_341 ) ;
break;
case V_192 :
V_166 = F_78 ( V_342 ) ;
break;
case V_193 :
F_127 ( F_1 ( V_3 ) ) ;
V_166 = F_1 ( V_3 ) -> V_195 ;
break;
#endif
case V_127 :
return F_187 ( V_3 , V_317 , V_318 ) ;
case V_343 :
V_166 = F_164 () ;
break;
case V_344 :
V_166 = F_80 ( V_345 ) ;
break;
case V_346 :
V_166 = F_78 ( V_347 ) ;
break;
case V_207 :
V_166 = F_78 ( V_348 ) ;
break;
case V_259 :
if ( ! F_1 ( V_3 ) -> V_260 )
return 1 ;
default:
if ( F_181 ( V_3 , V_317 , V_318 ) )
return 0 ;
V_60 = F_52 ( F_1 ( V_3 ) , V_317 ) ;
if ( V_60 ) {
V_166 = V_60 -> V_166 ;
break;
}
return F_187 ( V_3 , V_317 , V_318 ) ;
}
* V_318 = V_166 ;
return 0 ;
}
static int F_188 ( struct V_2 * V_3 , struct V_349 * V_350 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_72 * V_60 ;
int V_95 = 0 ;
T_2 V_317 = V_350 -> V_65 ;
T_5 V_166 = V_350 -> V_166 ;
switch ( V_317 ) {
case V_127 :
V_95 = F_189 ( V_3 , V_350 ) ;
break;
#ifdef F_82
case V_190 :
F_92 ( V_59 ) ;
F_85 ( V_341 , V_166 ) ;
break;
case V_192 :
F_92 ( V_59 ) ;
F_85 ( V_342 , V_166 ) ;
break;
case V_193 :
F_127 ( V_59 ) ;
V_59 -> V_195 = V_166 ;
break;
#endif
case V_344 :
F_88 ( V_345 , V_166 ) ;
break;
case V_346 :
F_85 ( V_347 , V_166 ) ;
break;
case V_207 :
F_85 ( V_348 , V_166 ) ;
break;
case V_343 :
F_190 ( V_3 , V_350 ) ;
break;
case V_351 :
if ( V_24 . V_352 & V_292 ) {
F_89 ( V_353 , V_166 ) ;
V_3 -> V_97 . V_354 = V_166 ;
break;
}
V_95 = F_189 ( V_3 , V_350 ) ;
break;
case V_355 :
V_95 = F_189 ( V_3 , V_350 ) ;
break;
case V_259 :
if ( ! V_59 -> V_260 )
return 1 ;
if ( ( V_166 >> 32 ) != 0 )
return 1 ;
default:
if ( F_185 ( V_3 , V_317 , V_166 ) )
break;
V_60 = F_52 ( V_59 , V_317 ) ;
if ( V_60 ) {
V_60 -> V_166 = V_166 ;
if ( V_60 - V_59 -> V_64 < V_59 -> V_196 ) {
F_128 () ;
F_119 ( V_60 -> V_65 , V_60 -> V_166 ,
V_60 -> V_91 ) ;
F_129 () ;
}
break;
}
V_95 = F_189 ( V_3 , V_350 ) ;
}
return V_95 ;
}
static void F_191 ( struct V_2 * V_3 , enum V_356 V_357 )
{
F_147 ( V_357 , ( unsigned long * ) & V_3 -> V_97 . V_98 ) ;
switch ( V_357 ) {
case V_358 :
V_3 -> V_97 . V_359 [ V_358 ] = F_78 ( V_360 ) ;
break;
case V_361 :
V_3 -> V_97 . V_359 [ V_361 ] = F_78 ( V_362 ) ;
break;
case V_363 :
if ( V_87 )
F_192 ( V_3 ) ;
break;
default:
break;
}
}
static T_11 int F_193 ( void )
{
return F_194 () ;
}
static T_11 int F_195 ( void )
{
T_5 V_60 ;
F_116 ( V_322 , V_60 ) ;
if ( V_60 & V_364 ) {
if ( ! ( V_60 & V_365 )
&& F_196 () )
return 1 ;
if ( ! ( V_60 & V_366 )
&& ( V_60 & V_365 )
&& ! F_196 () ) {
F_55 ( V_149 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_60 & V_366 )
&& ! F_196 () )
return 1 ;
}
return 0 ;
}
static void F_131 ( T_5 V_11 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_197 ( void * V_367 )
{
int V_77 = F_65 () ;
T_5 V_74 = F_54 ( F_68 ( V_200 , V_77 ) ) ;
T_5 V_368 , V_369 ;
if ( F_198 () & V_370 )
return - V_371 ;
F_199 ( & F_68 ( V_204 , V_77 ) ) ;
F_58 ( V_77 ) ;
F_116 ( V_322 , V_368 ) ;
V_369 = V_364 ;
V_369 |= V_366 ;
if ( F_196 () )
V_369 |= V_365 ;
if ( ( V_368 & V_369 ) != V_369 ) {
F_118 ( V_322 , V_368 | V_369 ) ;
}
F_200 ( F_198 () | V_370 ) ;
if ( V_201 ) {
F_131 ( V_74 ) ;
F_76 () ;
}
F_201 ( & F_106 ( V_152 ) ) ;
return 0 ;
}
static void F_202 ( void )
{
int V_77 = F_65 () ;
struct V_76 * V_80 , * V_372 ;
F_203 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_67 ( V_80 ) ;
}
static void F_138 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_204 ( void * V_367 )
{
if ( V_201 ) {
F_202 () ;
F_138 () ;
}
F_200 ( F_198 () & ~ V_370 ) ;
}
static T_11 int F_205 ( T_2 V_373 , T_2 V_374 ,
T_2 V_60 , T_2 * V_375 )
{
T_2 V_376 , V_377 ;
T_2 V_378 = V_373 | V_374 ;
F_178 ( V_60 , V_376 , V_377 ) ;
V_378 &= V_377 ;
V_378 |= V_376 ;
if ( V_373 & ~ V_378 )
return - V_379 ;
* V_375 = V_378 ;
return 0 ;
}
static T_11 bool F_206 ( T_2 V_60 , T_2 V_378 )
{
T_2 V_376 , V_377 ;
F_178 ( V_60 , V_376 , V_377 ) ;
return V_377 & V_378 ;
}
static T_11 int F_207 ( struct V_24 * V_380 )
{
T_2 V_376 , V_377 ;
T_2 V_381 , V_382 , V_383 , V_384 ;
T_2 V_385 = 0 ;
T_2 V_386 = 0 ;
T_2 V_387 = 0 ;
T_2 V_388 = 0 ;
T_2 V_389 = 0 ;
V_381 = V_284 | V_285 ;
V_382 = V_53 ;
if ( F_205 ( V_381 , V_382 , V_329 ,
& V_385 ) < 0 )
return - V_379 ;
V_381 = V_298 |
#ifdef F_82
V_303 |
V_304 |
#endif
V_301 |
V_302 |
V_307 |
V_305 |
V_275 |
V_300 |
V_308 |
V_299 |
V_309 ;
V_382 = V_27 |
V_26 |
V_28 ;
if ( F_205 ( V_381 , V_382 , V_294 ,
& V_386 ) < 0 )
return - V_379 ;
#ifdef F_82
if ( ( V_386 & V_27 ) )
V_386 &= ~ V_303 &
~ V_304 ;
#endif
if ( V_386 & V_28 ) {
V_383 = 0 ;
V_384 = V_30 |
V_54 |
V_49 |
V_45 |
V_46 |
V_47 |
V_50 |
V_51 ;
if ( F_205 ( V_383 , V_384 ,
V_311 ,
& V_387 ) < 0 )
return - V_379 ;
}
#ifndef F_82
if ( ! ( V_387 &
V_30 ) )
V_386 &= ~ V_27 ;
#endif
if ( V_387 & V_45 ) {
V_386 &= ~ ( V_301 |
V_302 |
V_299 ) ;
F_178 ( V_339 ,
V_31 . V_32 , V_31 . V_42 ) ;
}
V_381 = 0 ;
#ifdef F_82
V_381 |= V_288 ;
#endif
V_382 = V_390 | V_391 ;
if ( F_205 ( V_381 , V_382 , V_332 ,
& V_388 ) < 0 )
return - V_379 ;
V_381 = 0 ;
V_382 = V_292 ;
if ( F_205 ( V_381 , V_382 , V_289 ,
& V_389 ) < 0 )
return - V_379 ;
F_178 ( V_319 , V_376 , V_377 ) ;
if ( ( V_377 & 0x1fff ) > V_392 )
return - V_379 ;
#ifdef F_82
if ( V_377 & ( 1u << 16 ) )
return - V_379 ;
#endif
if ( ( ( V_377 >> 18 ) & 15 ) != 6 )
return - V_379 ;
V_380 -> V_393 = V_377 & 0x1fff ;
V_380 -> V_394 = F_208 ( V_24 . V_393 ) ;
V_380 -> V_395 = V_376 ;
V_380 -> V_52 = V_385 ;
V_380 -> V_25 = V_386 ;
V_380 -> V_29 = V_387 ;
V_380 -> V_396 = V_388 ;
V_380 -> V_352 = V_389 ;
V_128 =
F_206 ( V_289 ,
V_129 )
&& F_206 ( V_332 ,
V_130 ) ;
V_132 =
F_206 ( V_289 ,
V_133 )
&& F_206 ( V_332 ,
V_134 ) ;
if ( V_132 && V_397 . V_398 == 0x6 ) {
switch ( V_397 . V_399 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_132 = false ;
F_104 ( V_149 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_73 * F_209 ( int V_77 )
{
int V_400 = F_210 ( V_77 ) ;
struct V_10 * V_401 ;
struct V_73 * V_73 ;
V_401 = F_211 ( V_400 , V_402 , V_24 . V_394 ) ;
if ( ! V_401 )
return NULL ;
V_73 = F_212 ( V_401 ) ;
memset ( V_73 , 0 , V_24 . V_393 ) ;
V_73 -> V_395 = V_24 . V_395 ;
return V_73 ;
}
static struct V_73 * F_213 ( void )
{
return F_209 ( F_65 () ) ;
}
static void F_214 ( struct V_73 * V_73 )
{
F_215 ( ( unsigned long ) V_73 , V_24 . V_394 ) ;
}
static void F_216 ( struct V_76 * V_76 )
{
if ( ! V_76 -> V_73 )
return;
F_71 ( V_76 ) ;
F_214 ( V_76 -> V_73 ) ;
V_76 -> V_73 = NULL ;
}
static void F_217 ( void )
{
int V_77 ;
F_218 (cpu) {
F_214 ( F_68 ( V_200 , V_77 ) ) ;
F_68 ( V_200 , V_77 ) = NULL ;
}
}
static T_11 int F_219 ( void )
{
int V_77 ;
F_218 (cpu) {
struct V_73 * V_73 ;
V_73 = F_209 ( V_77 ) ;
if ( ! V_73 ) {
F_217 () ;
return - V_403 ;
}
F_68 ( V_200 , V_77 ) = V_73 ;
}
return 0 ;
}
static T_11 int F_220 ( void )
{
if ( F_207 ( & V_24 ) < 0 )
return - V_379 ;
if ( F_221 ( V_404 ) )
F_222 ( V_161 ) ;
if ( ! F_39 () )
V_405 = 0 ;
if ( ! F_35 () ||
! F_29 () ) {
V_87 = 0 ;
V_406 = 0 ;
V_407 = 0 ;
}
if ( ! F_30 () )
V_407 = 0 ;
if ( ! F_36 () )
V_406 = 0 ;
if ( ! F_23 () )
V_48 = 0 ;
if ( ! F_18 () )
V_408 -> V_409 = NULL ;
if ( V_87 && ! F_27 () )
F_223 () ;
if ( ! F_37 () )
V_410 = 0 ;
if ( V_8 )
F_177 () ;
return F_219 () ;
}
static T_12 void F_224 ( void )
{
F_217 () ;
}
static void F_225 ( struct V_2 * V_3 , int V_94 , struct V_411 * V_412 )
{
const struct V_413 * V_414 = & V_103 [ V_94 ] ;
struct V_411 V_254 = * V_412 ;
if ( ! ( F_78 ( V_414 -> V_104 ) == V_254 . V_104 && V_254 . V_170 ) ) {
V_254 . V_104 = F_78 ( V_414 -> V_104 ) ;
V_254 . V_101 = F_79 ( V_414 -> V_101 ) ;
V_254 . V_415 = V_254 . V_101 & V_416 ;
V_254 . V_170 = 1 ;
}
F_226 ( V_3 , & V_254 , V_94 ) ;
}
static void F_227 ( struct V_2 * V_3 )
{
unsigned long V_417 ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
V_59 -> V_418 = 1 ;
V_59 -> V_117 . V_118 = 0 ;
F_92 ( V_59 ) ;
F_226 ( V_3 , & V_59 -> V_117 . V_419 [ V_420 ] , V_420 ) ;
V_417 = F_78 ( V_226 ) ;
V_417 &= V_227 ;
V_417 |= V_59 -> V_117 . V_224 & ~ V_227 ;
F_85 ( V_226 , V_417 ) ;
F_85 ( V_421 , ( F_78 ( V_421 ) & ~ V_422 ) |
( F_78 ( V_423 ) & V_422 ) ) ;
F_98 ( V_3 ) ;
if ( V_424 )
return;
F_225 ( V_3 , V_425 , & V_59 -> V_117 . V_419 [ V_425 ] ) ;
F_225 ( V_3 , V_426 , & V_59 -> V_117 . V_419 [ V_426 ] ) ;
F_225 ( V_3 , V_427 , & V_59 -> V_117 . V_419 [ V_427 ] ) ;
F_225 ( V_3 , V_428 , & V_59 -> V_117 . V_419 [ V_428 ] ) ;
F_92 ( V_59 ) ;
F_87 ( V_429 , 0 ) ;
F_88 ( V_430 , 0x93 ) ;
F_87 ( V_431 ,
F_79 ( V_431 ) & ~ V_416 ) ;
F_88 ( V_432 , 0x9b ) ;
}
static T_4 F_228 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_97 . V_433 ) {
struct V_434 * V_435 ;
struct V_436 * V_437 ;
T_13 V_438 ;
V_435 = V_434 ( V_12 ) ;
V_437 = F_229 ( V_435 , 0 ) ;
V_438 = V_437 -> V_438 + V_437 -> V_439 - 3 ;
return V_438 << V_13 ;
}
return V_12 -> V_97 . V_433 ;
}
static void F_230 ( int V_94 , struct V_411 * V_412 )
{
const struct V_413 * V_414 = & V_103 [ V_94 ] ;
F_87 ( V_414 -> V_101 , V_412 -> V_104 >> 4 ) ;
F_88 ( V_414 -> V_104 , V_412 -> V_104 & 0xffff0 ) ;
F_88 ( V_414 -> V_106 , 0xffff ) ;
F_88 ( V_414 -> V_110 , 0xf3 ) ;
if ( V_412 -> V_104 & 0xf )
F_104 ( V_149 L_12
L_13 ,
V_94 ) ;
}
static void F_231 ( struct V_2 * V_3 )
{
unsigned long V_417 ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_411 V_440 ;
if ( V_406 )
return;
F_232 ( V_3 , & V_59 -> V_117 . V_419 [ V_420 ] , V_420 ) ;
F_232 ( V_3 , & V_59 -> V_117 . V_419 [ V_425 ] , V_425 ) ;
F_232 ( V_3 , & V_59 -> V_117 . V_419 [ V_426 ] , V_426 ) ;
F_232 ( V_3 , & V_59 -> V_117 . V_419 [ V_427 ] , V_427 ) ;
F_232 ( V_3 , & V_59 -> V_117 . V_419 [ V_428 ] , V_428 ) ;
V_59 -> V_418 = 1 ;
V_59 -> V_117 . V_118 = 1 ;
if ( ! V_3 -> V_12 -> V_97 . V_433 ) {
F_104 ( V_149 L_14
L_15 ) ;
F_233 ( & V_3 -> V_12 -> V_441 , V_3 -> V_442 ) ;
F_234 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_442 = F_235 ( & V_3 -> V_12 -> V_441 ) ;
}
F_92 ( V_59 ) ;
F_85 ( V_443 , F_228 ( V_3 -> V_12 ) ) ;
F_88 ( V_444 , V_445 - 1 ) ;
F_88 ( V_446 , 0x008b ) ;
V_417 = F_78 ( V_226 ) ;
V_59 -> V_117 . V_224 = V_417 ;
V_417 |= V_229 | V_230 ;
F_85 ( V_226 , V_417 ) ;
F_85 ( V_421 , F_78 ( V_421 ) | V_422 ) ;
F_98 ( V_3 ) ;
if ( V_424 )
goto V_447;
F_232 ( V_3 , & V_440 , V_448 ) ;
F_226 ( V_3 , & V_440 , V_448 ) ;
F_232 ( V_3 , & V_440 , V_449 ) ;
F_226 ( V_3 , & V_440 , V_449 ) ;
F_232 ( V_3 , & V_440 , V_425 ) ;
F_226 ( V_3 , & V_440 , V_425 ) ;
F_232 ( V_3 , & V_440 , V_426 ) ;
F_226 ( V_3 , & V_440 , V_426 ) ;
F_232 ( V_3 , & V_440 , V_428 ) ;
F_226 ( V_3 , & V_440 , V_428 ) ;
F_232 ( V_3 , & V_440 , V_427 ) ;
F_226 ( V_3 , & V_440 , V_427 ) ;
V_447:
F_236 ( V_3 ) ;
}
static void F_237 ( struct V_2 * V_3 , T_5 V_160 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_72 * V_60 = F_52 ( V_59 , V_127 ) ;
if ( ! V_60 )
return;
F_127 ( F_1 ( V_3 ) ) ;
V_3 -> V_97 . V_160 = V_160 ;
if ( V_160 & V_163 ) {
F_88 ( V_123 ,
F_80 ( V_123 ) |
V_293 ) ;
V_60 -> V_166 = V_160 ;
} else {
F_88 ( V_123 ,
F_80 ( V_123 ) &
~ V_293 ) ;
V_60 -> V_166 = V_160 & ~ V_164 ;
}
F_163 ( V_59 ) ;
}
static void F_238 ( struct V_2 * V_3 )
{
T_2 V_450 ;
F_92 ( F_1 ( V_3 ) ) ;
V_450 = F_80 ( V_446 ) ;
if ( ( V_450 & V_451 ) != V_452 ) {
F_239 ( L_16 ,
V_453 ) ;
F_88 ( V_446 ,
( V_450 & ~ V_451 )
| V_452 ) ;
}
F_237 ( V_3 , V_3 -> V_97 . V_160 | V_163 ) ;
}
static void F_240 ( struct V_2 * V_3 )
{
F_88 ( V_123 ,
F_80 ( V_123 )
& ~ V_293 ) ;
F_237 ( V_3 , V_3 -> V_97 . V_160 & ~ V_163 ) ;
}
static void F_241 ( struct V_2 * V_3 )
{
F_75 ( F_1 ( V_3 ) ) ;
if ( V_87 ) {
if ( ! F_242 ( V_3 -> V_97 . V_454 . V_455 ) )
return;
F_77 ( F_243 ( V_3 -> V_97 . V_454 . V_455 ) ) ;
}
}
static void F_144 ( struct V_2 * V_3 )
{
T_9 V_213 = V_3 -> V_97 . V_213 ;
V_3 -> V_97 . V_209 &= ~ V_213 ;
V_3 -> V_97 . V_209 |= F_78 ( V_210 ) & V_213 ;
}
static void F_244 ( struct V_2 * V_3 )
{
if ( V_87 && F_245 ( V_3 ) )
V_3 -> V_97 . V_456 = F_78 ( V_457 ) ;
F_147 ( V_458 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
}
static void F_246 ( struct V_2 * V_3 )
{
T_9 V_459 = V_3 -> V_97 . V_459 ;
V_3 -> V_97 . V_460 &= ~ V_459 ;
V_3 -> V_97 . V_460 |= F_78 ( V_421 ) & V_459 ;
}
static void F_247 ( struct V_2 * V_3 )
{
if ( ! F_146 ( V_363 ,
( unsigned long * ) & V_3 -> V_97 . V_461 ) )
return;
if ( F_245 ( V_3 ) && F_248 ( V_3 ) && ! F_117 ( V_3 ) ) {
F_89 ( V_462 , V_3 -> V_97 . V_454 . V_463 [ 0 ] ) ;
F_89 ( V_464 , V_3 -> V_97 . V_454 . V_463 [ 1 ] ) ;
F_89 ( V_465 , V_3 -> V_97 . V_454 . V_463 [ 2 ] ) ;
F_89 ( V_466 , V_3 -> V_97 . V_454 . V_463 [ 3 ] ) ;
}
}
static void F_192 ( struct V_2 * V_3 )
{
if ( F_245 ( V_3 ) && F_248 ( V_3 ) && ! F_117 ( V_3 ) ) {
V_3 -> V_97 . V_454 . V_463 [ 0 ] = F_81 ( V_462 ) ;
V_3 -> V_97 . V_454 . V_463 [ 1 ] = F_81 ( V_464 ) ;
V_3 -> V_97 . V_454 . V_463 [ 2 ] = F_81 ( V_465 ) ;
V_3 -> V_97 . V_454 . V_463 [ 3 ] = F_81 ( V_466 ) ;
}
F_147 ( V_363 ,
( unsigned long * ) & V_3 -> V_97 . V_98 ) ;
F_147 ( V_363 ,
( unsigned long * ) & V_3 -> V_97 . V_461 ) ;
}
static void F_249 ( unsigned long * V_467 ,
unsigned long V_209 ,
struct V_2 * V_3 )
{
if ( ! F_146 ( V_458 , ( T_9 * ) & V_3 -> V_97 . V_98 ) )
F_244 ( V_3 ) ;
if ( ! ( V_209 & V_468 ) ) {
F_88 ( V_469 ,
F_80 ( V_469 ) |
( V_301 |
V_302 ) ) ;
V_3 -> V_97 . V_209 = V_209 ;
F_250 ( V_3 , F_251 ( V_3 ) ) ;
} else if ( ! F_245 ( V_3 ) ) {
F_88 ( V_469 ,
F_80 ( V_469 ) &
~ ( V_301 |
V_302 ) ) ;
V_3 -> V_97 . V_209 = V_209 ;
F_250 ( V_3 , F_251 ( V_3 ) ) ;
}
if ( ! ( V_209 & V_470 ) )
* V_467 &= ~ V_470 ;
}
static void F_252 ( struct V_2 * V_3 , unsigned long V_209 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
unsigned long V_467 ;
if ( V_406 )
V_467 = ( V_209 & ~ V_471 )
| V_472 ;
else
V_467 = ( V_209 & ~ V_473 ) | V_474 ;
if ( V_59 -> V_117 . V_118 && ( V_209 & V_475 ) )
F_227 ( V_3 ) ;
if ( ! V_59 -> V_117 . V_118 && ! ( V_209 & V_475 ) )
F_231 ( V_3 ) ;
#ifdef F_82
if ( V_3 -> V_97 . V_160 & V_164 ) {
if ( ! F_245 ( V_3 ) && ( V_209 & V_468 ) )
F_238 ( V_3 ) ;
if ( F_245 ( V_3 ) && ! ( V_209 & V_468 ) )
F_240 ( V_3 ) ;
}
#endif
if ( V_87 )
F_249 ( & V_467 , V_209 , V_3 ) ;
if ( ! V_3 -> V_119 )
V_467 |= V_211 | V_212 ;
F_85 ( V_222 , V_209 ) ;
F_85 ( V_210 , V_467 ) ;
V_3 -> V_97 . V_209 = V_209 ;
F_149 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
}
static T_5 F_243 ( unsigned long V_455 )
{
T_5 V_70 ;
V_70 = V_476 |
V_477 << V_478 ;
if ( V_407 )
V_70 |= V_479 ;
V_70 |= ( V_455 & V_480 ) ;
return V_70 ;
}
static void F_253 ( struct V_2 * V_3 , unsigned long V_456 )
{
unsigned long V_481 ;
T_5 V_70 ;
V_481 = V_456 ;
if ( V_87 ) {
V_70 = F_243 ( V_456 ) ;
F_89 ( V_482 , V_70 ) ;
V_481 = F_245 ( V_3 ) ? F_254 ( V_3 ) :
V_3 -> V_12 -> V_97 . V_483 ;
F_247 ( V_3 ) ;
}
F_241 ( V_3 ) ;
F_85 ( V_457 , V_481 ) ;
}
static int F_250 ( struct V_2 * V_3 , unsigned long V_460 )
{
unsigned long V_484 = V_460 | ( F_1 ( V_3 ) -> V_117 . V_118 ?
V_485 : V_486 ) ;
if ( V_460 & V_370 ) {
if ( ! F_176 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_487 )
return 1 ;
V_3 -> V_97 . V_460 = V_460 ;
if ( V_87 ) {
if ( ! F_245 ( V_3 ) ) {
V_484 &= ~ V_488 ;
V_484 |= V_489 ;
} else if ( ! ( V_460 & V_488 ) ) {
V_484 &= ~ V_488 ;
}
}
F_85 ( V_423 , V_460 ) ;
F_85 ( V_421 , V_484 ) ;
return 0 ;
}
static void F_232 ( struct V_2 * V_3 ,
struct V_411 * V_440 , int V_94 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_2 V_108 ;
if ( V_59 -> V_117 . V_118
&& ( V_94 == V_420 || V_94 == V_425
|| V_94 == V_426 || V_94 == V_427
|| V_94 == V_428 ) ) {
* V_440 = V_59 -> V_117 . V_419 [ V_94 ] ;
if ( V_94 == V_420
|| V_440 -> V_101 == F_94 ( V_59 , V_94 ) )
return;
V_440 -> V_104 = F_95 ( V_59 , V_94 ) ;
V_440 -> V_101 = F_94 ( V_59 , V_94 ) ;
return;
}
V_440 -> V_104 = F_95 ( V_59 , V_94 ) ;
V_440 -> V_106 = F_96 ( V_59 , V_94 ) ;
V_440 -> V_101 = F_94 ( V_59 , V_94 ) ;
V_108 = F_97 ( V_59 , V_94 ) ;
if ( ( V_108 & V_490 ) && ! V_424 )
V_108 = 0 ;
V_440 -> type = V_108 & 15 ;
V_440 -> V_170 = ( V_108 >> 4 ) & 1 ;
V_440 -> V_415 = ( V_108 >> 5 ) & 3 ;
V_440 -> V_491 = ( V_108 >> 7 ) & 1 ;
V_440 -> V_492 = ( V_108 >> 12 ) & 1 ;
V_440 -> V_493 = ( V_108 >> 13 ) & 1 ;
V_440 -> V_494 = ( V_108 >> 14 ) & 1 ;
V_440 -> V_495 = ( V_108 >> 15 ) & 1 ;
V_440 -> V_496 = ( V_108 >> 16 ) & 1 ;
}
static T_5 F_255 ( struct V_2 * V_3 , int V_94 )
{
struct V_411 V_170 ;
if ( F_1 ( V_3 ) -> V_117 . V_118 ) {
F_232 ( V_3 , & V_170 , V_94 ) ;
return V_170 . V_104 ;
}
return F_95 ( F_1 ( V_3 ) , V_94 ) ;
}
static int F_256 ( struct V_2 * V_3 )
{
if ( ! F_257 ( V_3 ) )
return 0 ;
if ( ! F_117 ( V_3 )
&& ( F_258 ( V_3 ) & V_230 ) )
return 3 ;
return F_94 ( F_1 ( V_3 ) , V_449 ) & 3 ;
}
static int F_259 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
if ( F_86 ( V_59 -> V_418 && V_424 ) ) {
return V_59 -> V_497 ;
}
if ( ! F_146 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ) {
F_147 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
V_59 -> V_497 = F_256 ( V_3 ) ;
}
return V_59 -> V_497 ;
}
static T_2 F_260 ( struct V_411 * V_440 )
{
T_2 V_108 ;
if ( V_440 -> V_496 || ! V_440 -> V_491 )
V_108 = 1 << 16 ;
else {
V_108 = V_440 -> type & 15 ;
V_108 |= ( V_440 -> V_170 & 1 ) << 4 ;
V_108 |= ( V_440 -> V_415 & 3 ) << 5 ;
V_108 |= ( V_440 -> V_491 & 1 ) << 7 ;
V_108 |= ( V_440 -> V_492 & 1 ) << 12 ;
V_108 |= ( V_440 -> V_493 & 1 ) << 13 ;
V_108 |= ( V_440 -> V_494 & 1 ) << 14 ;
V_108 |= ( V_440 -> V_495 & 1 ) << 15 ;
}
return V_108 ;
}
static void F_226 ( struct V_2 * V_3 ,
struct V_411 * V_440 , int V_94 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
const struct V_413 * V_414 = & V_103 [ V_94 ] ;
T_2 V_108 ;
F_92 ( V_59 ) ;
if ( V_59 -> V_117 . V_118 && V_94 == V_420 ) {
F_87 ( V_414 -> V_101 , V_440 -> V_101 ) ;
V_59 -> V_117 . V_419 [ V_420 ] = * V_440 ;
return;
}
F_85 ( V_414 -> V_104 , V_440 -> V_104 ) ;
F_88 ( V_414 -> V_106 , V_440 -> V_106 ) ;
F_87 ( V_414 -> V_101 , V_440 -> V_101 ) ;
if ( V_59 -> V_117 . V_118 && V_440 -> V_170 ) {
V_59 -> V_117 . V_419 [ V_94 ] = * V_440 ;
if ( V_440 -> V_104 == 0xffff0000 && V_440 -> V_101 == 0xf000 )
F_85 ( V_414 -> V_104 , 0xf0000 ) ;
V_108 = 0xf3 ;
} else
V_108 = F_260 ( V_440 ) ;
if ( V_406 && ( V_94 != V_498 ) )
V_108 |= 0x1 ;
F_88 ( V_414 -> V_110 , V_108 ) ;
F_149 ( V_228 , ( T_9 * ) & V_3 -> V_97 . V_98 ) ;
if ( V_59 -> V_117 . V_118 ) {
switch ( V_94 ) {
case V_449 :
F_88 ( V_432 , 0xf3 ) ;
F_88 ( V_499 , 0xffff ) ;
if ( F_78 ( V_500 ) == 0xffff0000 )
F_85 ( V_500 , 0xf0000 ) ;
F_87 ( V_431 ,
F_78 ( V_500 ) >> 4 ) ;
break;
case V_425 :
case V_426 :
case V_428 :
case V_427 :
F_230 ( V_94 , & V_59 -> V_117 . V_419 [ V_94 ] ) ;
break;
case V_448 :
F_87 ( V_429 ,
F_78 ( V_501 ) >> 4 ) ;
F_88 ( V_502 , 0xffff ) ;
F_88 ( V_430 , 0xf3 ) ;
break;
}
}
}
static void F_261 ( struct V_2 * V_3 , int * V_494 , int * V_493 )
{
T_2 V_108 = F_97 ( F_1 ( V_3 ) , V_449 ) ;
* V_494 = ( V_108 >> 14 ) & 1 ;
* V_493 = ( V_108 >> 13 ) & 1 ;
}
static void F_262 ( struct V_2 * V_3 , struct V_150 * V_503 )
{
V_503 -> V_393 = F_80 ( V_504 ) ;
V_503 -> V_155 = F_78 ( V_505 ) ;
}
static void F_263 ( struct V_2 * V_3 , struct V_150 * V_503 )
{
F_88 ( V_504 , V_503 -> V_393 ) ;
F_85 ( V_505 , V_503 -> V_155 ) ;
}
static void F_264 ( struct V_2 * V_3 , struct V_150 * V_503 )
{
V_503 -> V_393 = F_80 ( V_506 ) ;
V_503 -> V_155 = F_78 ( V_507 ) ;
}
static void F_265 ( struct V_2 * V_3 , struct V_150 * V_503 )
{
F_88 ( V_506 , V_503 -> V_393 ) ;
F_85 ( V_507 , V_503 -> V_155 ) ;
}
static bool F_266 ( struct V_2 * V_3 , int V_94 )
{
struct V_411 V_440 ;
T_2 V_108 ;
F_232 ( V_3 , & V_440 , V_94 ) ;
V_108 = F_260 ( & V_440 ) ;
if ( V_440 . V_104 != ( V_440 . V_101 << 4 ) )
return false ;
if ( V_440 . V_106 < 0xffff )
return false ;
if ( ( ( V_108 | ( 3 << V_508 ) ) & ~ ( V_509 | V_510 ) ) != 0xf3 )
return false ;
return true ;
}
static bool F_267 ( struct V_2 * V_3 )
{
struct V_411 V_511 ;
unsigned int V_512 ;
F_232 ( V_3 , & V_511 , V_449 ) ;
V_512 = V_511 . V_101 & V_416 ;
if ( V_511 . V_496 )
return false ;
if ( ~ V_511 . type & ( V_513 | V_514 ) )
return false ;
if ( ! V_511 . V_170 )
return false ;
if ( V_511 . type & V_515 ) {
if ( V_511 . V_415 > V_512 )
return false ;
} else {
if ( V_511 . V_415 != V_512 )
return false ;
}
if ( ! V_511 . V_491 )
return false ;
return true ;
}
static bool F_268 ( struct V_2 * V_3 )
{
struct V_411 V_516 ;
unsigned int V_517 ;
F_232 ( V_3 , & V_516 , V_448 ) ;
V_517 = V_516 . V_101 & V_416 ;
if ( V_516 . V_496 )
return true ;
if ( V_516 . type != 3 && V_516 . type != 7 )
return false ;
if ( ! V_516 . V_170 )
return false ;
if ( V_516 . V_415 != V_517 )
return false ;
if ( ! V_516 . V_491 )
return false ;
return true ;
}
static bool F_269 ( struct V_2 * V_3 , int V_94 )
{
struct V_411 V_440 ;
unsigned int V_518 ;
F_232 ( V_3 , & V_440 , V_94 ) ;
V_518 = V_440 . V_101 & V_416 ;
if ( V_440 . V_496 )
return true ;
if ( ! V_440 . V_170 )
return false ;
if ( ! V_440 . V_491 )
return false ;
if ( ~ V_440 . type & ( V_513 | V_515 ) ) {
if ( V_440 . V_415 < V_518 )
return false ;
}
return true ;
}
static bool F_270 ( struct V_2 * V_3 )
{
struct V_411 V_173 ;
F_232 ( V_3 , & V_173 , V_420 ) ;
if ( V_173 . V_496 )
return false ;
if ( V_173 . V_101 & V_519 )
return false ;
if ( V_173 . type != 3 && V_173 . type != 11 )
return false ;
if ( ! V_173 . V_491 )
return false ;
return true ;
}
static bool F_271 ( struct V_2 * V_3 )
{
struct V_411 V_520 ;
F_232 ( V_3 , & V_520 , V_498 ) ;
if ( V_520 . V_496 )
return true ;
if ( V_520 . V_101 & V_519 )
return false ;
if ( V_520 . type != 2 )
return false ;
if ( ! V_520 . V_491 )
return false ;
return true ;
}
static bool F_272 ( struct V_2 * V_3 )
{
struct V_411 V_511 , V_516 ;
F_232 ( V_3 , & V_511 , V_449 ) ;
F_232 ( V_3 , & V_516 , V_448 ) ;
return ( ( V_511 . V_101 & V_416 ) ==
( V_516 . V_101 & V_416 ) ) ;
}
static bool F_273 ( struct V_2 * V_3 )
{
if ( ! F_257 ( V_3 ) ) {
if ( ! F_266 ( V_3 , V_449 ) )
return false ;
if ( ! F_266 ( V_3 , V_448 ) )
return false ;
if ( ! F_266 ( V_3 , V_426 ) )
return false ;
if ( ! F_266 ( V_3 , V_425 ) )
return false ;
if ( ! F_266 ( V_3 , V_427 ) )
return false ;
if ( ! F_266 ( V_3 , V_428 ) )
return false ;
} else {
if ( ! F_272 ( V_3 ) )
return false ;
if ( ! F_267 ( V_3 ) )
return false ;
if ( ! F_268 ( V_3 ) )
return false ;
if ( ! F_269 ( V_3 , V_426 ) )
return false ;
if ( ! F_269 ( V_3 , V_425 ) )
return false ;
if ( ! F_269 ( V_3 , V_427 ) )
return false ;
if ( ! F_269 ( V_3 , V_428 ) )
return false ;
if ( ! F_270 ( V_3 ) )
return false ;
if ( ! F_271 ( V_3 ) )
return false ;
}
return true ;
}
static int F_274 ( struct V_12 * V_12 )
{
T_13 V_521 ;
T_3 V_166 = 0 ;
int V_522 , V_523 , V_95 = 0 ;
V_523 = F_235 ( & V_12 -> V_441 ) ;
V_521 = F_228 ( V_12 ) >> V_13 ;
V_522 = F_275 ( V_12 , V_521 , 0 , V_392 ) ;
if ( V_522 < 0 )
goto V_524;
V_166 = V_525 + V_526 ;
V_522 = F_276 ( V_12 , V_521 ++ , & V_166 ,
V_527 , sizeof( T_3 ) ) ;
if ( V_522 < 0 )
goto V_524;
V_522 = F_275 ( V_12 , V_521 ++ , 0 , V_392 ) ;
if ( V_522 < 0 )
goto V_524;
V_522 = F_275 ( V_12 , V_521 , 0 , V_392 ) ;
if ( V_522 < 0 )
goto V_524;
V_166 = ~ 0 ;
V_522 = F_276 ( V_12 , V_521 , & V_166 ,
V_445 - 2 * V_392 - 1 ,
sizeof( T_6 ) ) ;
if ( V_522 < 0 )
goto V_524;
V_95 = 1 ;
V_524:
F_233 ( & V_12 -> V_441 , V_523 ) ;
return V_95 ;
}
static int F_277 ( struct V_12 * V_12 )
{
int V_61 , V_523 , V_522 , V_95 ;
T_14 V_528 ;
T_2 V_254 ;
if ( ! V_87 )
return 1 ;
if ( F_86 ( ! V_12 -> V_97 . V_529 ) ) {
F_55 ( V_75 L_17
L_18 ) ;
return 0 ;
}
if ( F_278 ( V_12 -> V_97 . V_530 ) )
return 1 ;
V_95 = 0 ;
V_528 = V_12 -> V_97 . V_483 >> V_13 ;
V_523 = F_235 ( & V_12 -> V_441 ) ;
V_522 = F_275 ( V_12 , V_528 , 0 , V_392 ) ;
if ( V_522 < 0 )
goto V_524;
for ( V_61 = 0 ; V_61 < V_531 ; V_61 ++ ) {
V_254 = ( V_61 << 22 ) + ( V_532 | V_533 | V_534 |
V_535 | V_536 | V_537 ) ;
V_522 = F_276 ( V_12 , V_528 ,
& V_254 , V_61 * sizeof( V_254 ) , sizeof( V_254 ) ) ;
if ( V_522 < 0 )
goto V_524;
}
V_12 -> V_97 . V_530 = true ;
V_95 = 1 ;
V_524:
F_233 ( & V_12 -> V_441 , V_523 ) ;
return V_95 ;
}
static void F_279 ( int V_94 )
{
const struct V_413 * V_414 = & V_103 [ V_94 ] ;
unsigned int V_108 ;
F_87 ( V_414 -> V_101 , 0 ) ;
F_85 ( V_414 -> V_104 , 0 ) ;
F_88 ( V_414 -> V_106 , 0xffff ) ;
if ( V_406 ) {
V_108 = 0x93 ;
if ( V_94 == V_449 )
V_108 |= 0x08 ;
} else
V_108 = 0xf3 ;
F_88 ( V_414 -> V_110 , V_108 ) ;
}
static int F_280 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_538 V_539 ;
int V_522 = 0 ;
F_281 ( & V_12 -> V_540 ) ;
if ( V_12 -> V_97 . V_541 )
goto V_524;
V_539 . V_437 = V_542 ;
V_539 . V_417 = 0 ;
V_539 . V_543 = 0xfee00000ULL ;
V_539 . V_544 = V_392 ;
V_522 = F_282 ( V_12 , & V_539 , 0 ) ;
if ( V_522 )
goto V_524;
V_10 = F_6 ( V_12 , 0xfee00 ) ;
if ( F_7 ( V_10 ) ) {
V_522 = - V_545 ;
goto V_524;
}
V_12 -> V_97 . V_541 = V_10 ;
V_524:
F_283 ( & V_12 -> V_540 ) ;
return V_522 ;
}
static int F_284 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_538 V_539 ;
int V_522 = 0 ;
F_281 ( & V_12 -> V_540 ) ;
if ( V_12 -> V_97 . V_529 )
goto V_524;
V_539 . V_437 = V_546 ;
V_539 . V_417 = 0 ;
V_539 . V_543 =
V_12 -> V_97 . V_483 ;
V_539 . V_544 = V_392 ;
V_522 = F_282 ( V_12 , & V_539 , 0 ) ;
if ( V_522 )
goto V_524;
V_10 = F_6 ( V_12 , V_12 -> V_97 . V_483 >> V_13 ) ;
if ( F_7 ( V_10 ) ) {
V_522 = - V_545 ;
goto V_524;
}
V_12 -> V_97 . V_529 = V_10 ;
V_524:
F_283 ( & V_12 -> V_540 ) ;
return V_522 ;
}
static void F_285 ( struct V_1 * V_59 )
{
int V_42 ;
V_59 -> V_42 = 0 ;
if ( ! V_405 )
return;
F_286 ( & V_547 ) ;
V_42 = F_287 ( V_548 , V_549 ) ;
if ( V_42 < V_549 ) {
V_59 -> V_42 = V_42 ;
F_147 ( V_42 , V_548 ) ;
}
F_288 ( & V_547 ) ;
}
static void F_289 ( struct V_1 * V_59 )
{
if ( ! V_405 )
return;
F_286 ( & V_547 ) ;
if ( V_59 -> V_42 != 0 )
F_149 ( V_59 -> V_42 , V_548 ) ;
F_288 ( & V_547 ) ;
}
static void F_290 ( unsigned long * V_255 , T_2 V_60 )
{
int V_550 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_60 <= 0x1fff ) {
F_149 ( V_60 , V_255 + 0x000 / V_550 ) ;
F_149 ( V_60 , V_255 + 0x800 / V_550 ) ;
} else if ( ( V_60 >= 0xc0000000 ) && ( V_60 <= 0xc0001fff ) ) {
V_60 &= 0x1fff ;
F_149 ( V_60 , V_255 + 0x400 / V_550 ) ;
F_149 ( V_60 , V_255 + 0xc00 / V_550 ) ;
}
}
static void F_291 ( T_2 V_60 , bool V_551 )
{
if ( ! V_551 )
F_290 ( V_263 , V_60 ) ;
F_290 ( V_262 , V_60 ) ;
}
static void F_292 ( void )
{
T_2 V_552 , V_553 ;
unsigned long V_554 ;
struct V_150 V_503 ;
F_85 ( V_555 , F_293 () & ~ V_211 ) ;
F_85 ( V_556 , F_198 () ) ;
F_85 ( V_557 , F_294 () ) ;
F_87 ( V_558 , V_559 ) ;
#ifdef F_82
F_87 ( V_560 , 0 ) ;
F_87 ( V_561 , 0 ) ;
#else
F_87 ( V_560 , V_562 ) ;
F_87 ( V_561 , V_562 ) ;
#endif
F_87 ( V_563 , V_562 ) ;
F_87 ( V_564 , V_156 * 8 ) ;
F_295 ( & V_503 ) ;
F_85 ( V_565 , V_503 . V_155 ) ;
F_85 ( V_566 , V_567 ) ;
F_178 ( V_344 , V_552 , V_553 ) ;
F_88 ( V_568 , V_552 ) ;
F_116 ( V_346 , V_554 ) ;
F_85 ( V_569 , V_554 ) ;
if ( V_24 . V_396 & V_391 ) {
F_178 ( V_351 , V_552 , V_553 ) ;
F_89 ( V_570 , V_552 | ( ( T_5 ) V_553 << 32 ) ) ;
}
}
static void F_296 ( struct V_1 * V_59 )
{
V_59 -> V_3 . V_97 . V_459 = V_571 ;
if ( V_87 )
V_59 -> V_3 . V_97 . V_459 |= V_572 ;
if ( F_99 ( & V_59 -> V_3 ) )
V_59 -> V_3 . V_97 . V_459 &=
~ F_4 ( & V_59 -> V_3 ) -> V_220 ;
F_85 ( V_573 , ~ V_59 -> V_3 . V_97 . V_459 ) ;
}
static T_2 F_297 ( struct V_1 * V_59 )
{
T_2 V_574 = V_24 . V_25 ;
if ( ! F_19 ( V_59 -> V_3 . V_12 ) ) {
V_574 &= ~ V_27 ;
#ifdef F_82
V_574 |= V_304 |
V_303 ;
#endif
}
if ( ! V_87 )
V_574 |= V_302 |
V_301 |
V_299 ;
return V_574 ;
}
static T_2 F_298 ( struct V_1 * V_59 )
{
T_2 V_574 = V_24 . V_29 ;
if ( ! F_38 ( V_59 -> V_3 . V_12 ) )
V_574 &= ~ V_30 ;
if ( V_59 -> V_42 == 0 )
V_574 &= ~ V_49 ;
if ( ! V_87 ) {
V_574 &= ~ V_45 ;
V_406 = 0 ;
V_574 &= ~ V_51 ;
}
if ( ! V_406 )
V_574 &= ~ V_46 ;
if ( ! V_410 )
V_574 &= ~ V_47 ;
return V_574 ;
}
static void F_299 ( void )
{
F_300 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_301 ( struct V_1 * V_59 )
{
#ifdef F_82
unsigned long V_575 ;
#endif
int V_61 ;
F_89 ( V_576 , F_54 ( V_577 ) ) ;
F_89 ( V_578 , F_54 ( V_579 ) ) ;
if ( F_17 () )
F_89 ( V_264 , F_54 ( V_263 ) ) ;
F_89 ( V_580 , - 1ull ) ;
F_88 ( V_581 ,
V_24 . V_52 ) ;
F_88 ( V_469 , F_297 ( V_59 ) ) ;
if ( F_21 () ) {
F_88 ( V_582 ,
F_298 ( V_59 ) ) ;
}
if ( V_410 ) {
F_88 ( V_583 , V_410 ) ;
F_88 ( V_584 , V_585 ) ;
}
F_88 ( V_586 , 0 ) ;
F_88 ( V_587 , 0 ) ;
F_88 ( V_588 , 0 ) ;
F_87 ( V_180 , 0 ) ;
F_87 ( V_184 , 0 ) ;
F_292 () ;
#ifdef F_82
F_116 ( V_190 , V_575 ) ;
F_85 ( V_189 , V_575 ) ;
F_116 ( V_192 , V_575 ) ;
F_85 ( V_191 , V_575 ) ;
#else
F_85 ( V_189 , 0 ) ;
F_85 ( V_191 , 0 ) ;
#endif
F_88 ( V_589 , 0 ) ;
F_88 ( V_139 , 0 ) ;
F_89 ( V_590 , F_54 ( V_59 -> V_125 . V_137 ) ) ;
F_88 ( V_138 , 0 ) ;
F_89 ( V_591 , F_54 ( V_59 -> V_125 . V_136 ) ) ;
if ( V_24 . V_352 & V_292 ) {
T_2 V_592 , V_593 ;
T_5 V_594 ;
F_178 ( V_351 , V_592 , V_593 ) ;
V_594 = V_592 | ( ( T_5 ) V_593 << 32 ) ;
F_89 ( V_353 , V_594 ) ;
V_59 -> V_3 . V_97 . V_354 = V_594 ;
}
for ( V_61 = 0 ; V_61 < V_595 ; ++ V_61 ) {
T_2 V_65 = V_63 [ V_61 ] ;
T_2 V_596 , V_597 ;
int V_598 = V_59 -> V_62 ;
if ( F_302 ( V_65 , & V_596 , & V_597 ) < 0 )
continue;
if ( F_303 ( V_65 , V_596 , V_597 ) < 0 )
continue;
V_59 -> V_64 [ V_598 ] . V_65 = V_61 ;
V_59 -> V_64 [ V_598 ] . V_166 = 0 ;
V_59 -> V_64 [ V_598 ] . V_91 = - 1ull ;
++ V_59 -> V_62 ;
}
F_88 ( V_124 , V_24 . V_396 ) ;
F_88 ( V_123 , V_24 . V_352 ) ;
F_85 ( V_215 , ~ 0UL ) ;
F_296 ( V_59 ) ;
return 0 ;
}
static int F_304 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_5 V_60 ;
int V_95 ;
V_59 -> V_117 . V_118 = 0 ;
V_59 -> V_599 = 0 ;
V_59 -> V_3 . V_97 . V_359 [ V_600 ] = F_305 () ;
F_306 ( & V_59 -> V_3 , 0 ) ;
V_60 = 0xfee00000 | V_601 ;
if ( F_307 ( & V_59 -> V_3 ) )
V_60 |= V_602 ;
F_308 ( & V_59 -> V_3 , V_60 ) ;
F_92 ( V_59 ) ;
F_279 ( V_449 ) ;
if ( F_307 ( & V_59 -> V_3 ) ) {
F_87 ( V_431 , 0xf000 ) ;
F_85 ( V_500 , 0x000f0000 ) ;
} else {
F_87 ( V_431 , V_59 -> V_3 . V_97 . V_603 << 8 ) ;
F_85 ( V_500 , V_59 -> V_3 . V_97 . V_603 << 12 ) ;
}
F_279 ( V_426 ) ;
F_279 ( V_425 ) ;
F_279 ( V_427 ) ;
F_279 ( V_428 ) ;
F_279 ( V_448 ) ;
F_87 ( V_604 , 0 ) ;
F_85 ( V_443 , 0 ) ;
F_88 ( V_444 , 0xffff ) ;
F_88 ( V_446 , 0x008b ) ;
F_87 ( V_605 , 0 ) ;
F_85 ( V_606 , 0 ) ;
F_88 ( V_607 , 0xffff ) ;
F_88 ( V_608 , 0x00082 ) ;
F_88 ( V_345 , 0 ) ;
F_85 ( V_348 , 0 ) ;
F_85 ( V_347 , 0 ) ;
F_85 ( V_226 , 0x02 ) ;
if ( F_307 ( & V_59 -> V_3 ) )
F_154 ( V_3 , 0xfff0 ) ;
else
F_154 ( V_3 , 0 ) ;
F_85 ( V_507 , 0 ) ;
F_88 ( V_506 , 0xffff ) ;
F_85 ( V_505 , 0 ) ;
F_88 ( V_504 , 0xffff ) ;
F_88 ( V_609 , V_610 ) ;
F_88 ( V_232 , 0 ) ;
F_88 ( V_611 , 0 ) ;
F_89 ( V_612 , 0 ) ;
F_163 ( V_59 ) ;
F_88 ( V_251 , 0 ) ;
if ( F_18 () ) {
F_89 ( V_613 , 0 ) ;
if ( F_19 ( V_59 -> V_3 . V_12 ) )
F_89 ( V_613 ,
F_54 ( V_59 -> V_3 . V_97 . V_614 -> V_359 ) ) ;
F_88 ( V_615 , 0 ) ;
}
if ( F_38 ( V_59 -> V_3 . V_12 ) )
F_89 ( V_616 ,
F_309 ( V_59 -> V_3 . V_12 -> V_97 . V_541 ) ) ;
if ( V_59 -> V_42 != 0 )
F_87 ( V_617 , V_59 -> V_42 ) ;
V_59 -> V_3 . V_97 . V_209 = V_618 | V_619 | V_620 ;
V_3 -> V_442 = F_235 ( & V_3 -> V_12 -> V_441 ) ;
F_252 ( & V_59 -> V_3 , F_310 ( V_3 ) ) ;
F_233 ( & V_3 -> V_12 -> V_441 , V_3 -> V_442 ) ;
F_250 ( & V_59 -> V_3 , 0 ) ;
F_237 ( & V_59 -> V_3 , 0 ) ;
F_139 ( & V_59 -> V_3 ) ;
F_98 ( & V_59 -> V_3 ) ;
F_75 ( V_59 ) ;
V_95 = 0 ;
V_59 -> V_418 = 0 ;
return V_95 ;
}
static bool F_311 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_58 &
V_284 ;
}
static void F_312 ( struct V_2 * V_3 )
{
T_2 V_56 ;
if ( F_99 ( V_3 ) && F_311 ( V_3 ) ) {
F_132 ( V_621 , V_3 ) ;
return;
}
V_56 = F_80 ( V_469 ) ;
V_56 |= V_297 ;
F_88 ( V_469 , V_56 ) ;
}
static void F_313 ( struct V_2 * V_3 )
{
T_2 V_56 ;
if ( ! F_42 () ) {
F_312 ( V_3 ) ;
return;
}
if ( F_80 ( V_232 ) & V_233 ) {
F_312 ( V_3 ) ;
return;
}
V_56 = F_80 ( V_469 ) ;
V_56 |= V_622 ;
F_88 ( V_469 , V_56 ) ;
}
static void F_314 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_15 V_623 ;
int V_624 = V_3 -> V_97 . V_625 . V_135 ;
F_315 ( V_624 ) ;
++ V_3 -> V_197 . V_626 ;
if ( V_59 -> V_117 . V_118 ) {
int V_245 = 0 ;
if ( V_3 -> V_97 . V_625 . V_627 )
V_245 = V_3 -> V_97 . V_246 ;
if ( F_159 ( V_3 , V_624 , V_245 ) != V_247 )
F_132 ( V_248 , V_3 ) ;
return;
}
V_623 = V_624 | V_17 ;
if ( V_3 -> V_97 . V_625 . V_627 ) {
V_623 |= V_628 ;
F_88 ( V_249 ,
V_59 -> V_3 . V_97 . V_246 ) ;
} else
V_623 |= V_22 ;
F_88 ( V_251 , V_623 ) ;
}
static void F_316 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
if ( F_99 ( V_3 ) )
return;
if ( ! F_42 () ) {
V_59 -> V_599 = 1 ;
V_59 -> V_629 = 0 ;
}
++ V_3 -> V_197 . V_630 ;
V_59 -> V_631 = false ;
if ( V_59 -> V_117 . V_118 ) {
if ( F_159 ( V_3 , V_632 , 0 ) != V_247 )
F_132 ( V_248 , V_3 ) ;
return;
}
F_88 ( V_251 ,
V_633 | V_17 | V_632 ) ;
}
static int F_317 ( struct V_2 * V_3 )
{
if ( ! F_42 () && F_1 ( V_3 ) -> V_599 )
return 0 ;
return ! ( F_80 ( V_232 ) &
( V_235 | V_233
| V_634 ) ) ;
}
static bool F_318 ( struct V_2 * V_3 )
{
if ( ! F_42 () )
return F_1 ( V_3 ) -> V_599 ;
if ( F_1 ( V_3 ) -> V_631 )
return false ;
return F_80 ( V_232 ) & V_634 ;
}
static void F_319 ( struct V_2 * V_3 , bool V_635 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
if ( ! F_42 () ) {
if ( V_59 -> V_599 != V_635 ) {
V_59 -> V_599 = V_635 ;
V_59 -> V_629 = 0 ;
}
} else {
V_59 -> V_631 = ! V_635 ;
if ( V_635 )
F_91 ( V_232 ,
V_634 ) ;
else
F_90 ( V_232 ,
V_634 ) ;
}
}
static int F_320 ( struct V_2 * V_3 )
{
if ( F_99 ( V_3 ) && F_311 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_636 ||
( V_7 -> V_637 &
V_638 ) )
return 0 ;
F_156 ( V_3 ) ;
V_7 -> V_639 = V_640 ;
V_7 -> V_641 = 0 ;
}
return ( F_78 ( V_226 ) & V_642 ) &&
! ( F_80 ( V_232 ) &
( V_233 | V_235 ) ) ;
}
static int F_234 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_95 ;
struct V_538 V_643 = {
. V_437 = V_644 ,
. V_543 = V_11 ,
. V_544 = V_392 * 3 ,
. V_417 = 0 ,
} ;
V_95 = F_321 ( V_12 , & V_643 , 0 ) ;
if ( V_95 )
return V_95 ;
V_12 -> V_97 . V_433 = V_11 ;
if ( ! F_274 ( V_12 ) )
return - V_403 ;
return 0 ;
}
static int F_322 ( struct V_2 * V_3 ,
int V_645 , T_2 V_646 )
{
if ( ( ( V_645 == V_321 ) || ( V_645 == V_647 ) ) && V_646 == 0 )
if ( F_323 ( V_3 , 0 ) == V_247 )
return 1 ;
switch ( V_645 ) {
case V_112 :
if ( V_3 -> V_113 &
( V_648 | V_649 ) )
return 0 ;
F_324 ( V_3 , V_645 ) ;
return 1 ;
case V_116 :
F_1 ( V_3 ) -> V_3 . V_97 . V_246 =
F_80 ( V_239 ) ;
if ( V_3 -> V_113 & V_115 )
return 0 ;
case V_650 :
case V_651 :
case V_652 :
case V_21 :
case V_653 :
case V_647 :
case V_321 :
case V_654 :
F_324 ( V_3 , V_645 ) ;
return 1 ;
}
return 0 ;
}
static void F_325 ( void )
{
#if F_326 ( V_655 ) && F_326 ( F_82 )
struct V_656 V_359 = {
. V_511 = 3 ,
. V_417 = V_642 ,
} ;
F_327 ( & V_359 , 0 ) ;
#endif
}
static int F_328 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_329 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_657 * V_657 = V_3 -> V_658 ;
T_2 V_14 , V_659 , V_241 ;
unsigned long V_660 , V_238 , V_661 ;
T_2 V_662 ;
enum V_663 V_664 ;
V_662 = V_59 -> V_665 ;
V_14 = V_59 -> V_666 ;
if ( F_16 ( V_14 ) )
return F_328 ( V_3 ) ;
if ( ( V_14 & V_15 ) == V_633 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_139 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_664 = F_323 ( V_3 , V_667 ) ;
if ( V_664 != V_247 )
F_324 ( V_3 , V_21 ) ;
return 1 ;
}
V_241 = 0 ;
if ( V_14 & V_244 )
V_241 = F_80 ( V_668 ) ;
if ( ( V_662 & V_638 ) &&
! ( F_12 ( V_14 ) && ! ( V_241 & V_669 ) ) ) {
V_3 -> V_658 -> V_670 = V_671 ;
V_3 -> V_658 -> V_672 . V_673 = V_674 ;
V_3 -> V_658 -> V_672 . V_675 = 2 ;
V_3 -> V_658 -> V_672 . V_166 [ 0 ] = V_662 ;
V_3 -> V_658 -> V_672 . V_166 [ 1 ] = V_14 ;
return 0 ;
}
if ( F_12 ( V_14 ) ) {
F_330 ( V_87 ) ;
V_660 = F_78 ( V_676 ) ;
F_331 ( V_660 , V_241 ) ;
if ( F_332 ( V_3 ) )
F_333 ( V_3 , V_660 ) ;
return F_334 ( V_3 , V_660 , V_241 , NULL , 0 ) ;
}
if ( V_59 -> V_117 . V_118 &&
F_322 ( V_3 , V_14 & V_16 ,
V_241 ) ) {
if ( V_3 -> V_97 . V_677 ) {
V_3 -> V_97 . V_677 = 0 ;
return F_335 ( V_3 ) ;
}
return 1 ;
}
V_659 = V_14 & V_16 ;
switch ( V_659 ) {
case V_112 :
V_661 = F_78 ( V_676 ) ;
if ( ! ( V_3 -> V_113 &
( V_648 | V_649 ) ) ) {
V_3 -> V_97 . V_661 = V_661 | V_678 ;
F_324 ( V_3 , V_112 ) ;
return 1 ;
}
V_657 -> V_679 . V_97 . V_661 = V_661 | V_678 ;
V_657 -> V_679 . V_97 . V_680 = F_78 ( V_681 ) ;
case V_116 :
V_59 -> V_3 . V_97 . V_246 =
F_80 ( V_239 ) ;
V_657 -> V_670 = V_682 ;
V_238 = F_153 ( V_3 ) ;
V_657 -> V_679 . V_97 . V_683 = F_78 ( V_500 ) + V_238 ;
V_657 -> V_679 . V_97 . V_684 = V_659 ;
break;
default:
V_657 -> V_670 = V_685 ;
V_657 -> V_686 . V_684 = V_659 ;
V_657 -> V_686 . V_241 = V_241 ;
break;
}
return 0 ;
}
static int F_336 ( struct V_2 * V_3 )
{
++ V_3 -> V_197 . V_687 ;
return 1 ;
}
static int F_337 ( struct V_2 * V_3 )
{
V_3 -> V_658 -> V_670 = V_688 ;
return 0 ;
}
static int F_338 ( struct V_2 * V_3 )
{
unsigned long V_689 ;
int V_393 , V_690 , string ;
unsigned V_691 ;
V_689 = F_78 ( V_676 ) ;
string = ( V_689 & 16 ) != 0 ;
V_690 = ( V_689 & 8 ) != 0 ;
++ V_3 -> V_197 . V_692 ;
if ( string || V_690 )
return F_323 ( V_3 , 0 ) == V_247 ;
V_691 = V_689 >> 16 ;
V_393 = ( V_689 & 7 ) + 1 ;
F_152 ( V_3 ) ;
return F_339 ( V_3 , V_393 , V_691 ) ;
}
static void
F_340 ( struct V_2 * V_3 , unsigned char * V_693 )
{
V_693 [ 0 ] = 0x0f ;
V_693 [ 1 ] = 0x01 ;
V_693 [ 2 ] = 0xc1 ;
}
static int F_341 ( struct V_2 * V_3 , unsigned long V_694 )
{
if ( F_1 ( V_3 ) -> V_8 . V_487 &&
( ( V_694 & F_183 ) != F_183 ) )
return 1 ;
if ( F_99 ( V_3 ) ) {
if ( F_342 ( V_3 , ( V_694 & V_3 -> V_97 . V_213 ) |
( V_3 -> V_97 . V_209 & ~ V_3 -> V_97 . V_213 ) ) )
return 1 ;
F_85 ( V_222 , V_694 ) ;
return 0 ;
} else
return F_342 ( V_3 , V_694 ) ;
}
static int F_343 ( struct V_2 * V_3 , unsigned long V_694 )
{
if ( F_99 ( V_3 ) ) {
if ( F_344 ( V_3 , ( V_694 & V_3 -> V_97 . V_459 ) |
( V_3 -> V_97 . V_460 & ~ V_3 -> V_97 . V_459 ) ) )
return 1 ;
F_85 ( V_423 , V_694 ) ;
return 0 ;
} else
return F_344 ( V_3 , V_694 ) ;
}
static void F_345 ( struct V_2 * V_3 )
{
if ( F_99 ( V_3 ) ) {
F_85 ( V_222 ,
F_78 ( V_222 ) & ~ V_211 ) ;
V_3 -> V_97 . V_209 &= ~ V_211 ;
} else
F_252 ( V_3 , F_140 ( V_3 , ~ V_211 ) ) ;
}
static int F_346 ( struct V_2 * V_3 )
{
unsigned long V_689 , V_694 ;
int V_695 ;
int V_357 ;
int V_696 ;
V_689 = F_78 ( V_676 ) ;
V_695 = V_689 & 15 ;
V_357 = ( V_689 >> 8 ) & 15 ;
switch ( ( V_689 >> 4 ) & 3 ) {
case 0 :
V_694 = F_347 ( V_3 , V_357 ) ;
F_348 ( V_695 , V_694 ) ;
switch ( V_695 ) {
case 0 :
V_696 = F_341 ( V_3 , V_694 ) ;
F_349 ( V_3 , V_696 ) ;
return 1 ;
case 3 :
V_696 = F_350 ( V_3 , V_694 ) ;
F_349 ( V_3 , V_696 ) ;
return 1 ;
case 4 :
V_696 = F_343 ( V_3 , V_694 ) ;
F_349 ( V_3 , V_696 ) ;
return 1 ;
case 8 : {
T_6 V_697 = F_351 ( V_3 ) ;
T_6 V_698 = F_347 ( V_3 , V_357 ) ;
V_696 = F_306 ( V_3 , V_698 ) ;
F_349 ( V_3 , V_696 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_697 <= V_698 )
return 1 ;
V_3 -> V_658 -> V_670 = V_699 ;
return 0 ;
}
}
break;
case 2 :
F_345 ( V_3 ) ;
F_348 ( 0 , F_310 ( V_3 ) ) ;
F_152 ( V_3 ) ;
F_139 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_695 ) {
case 3 :
V_694 = F_254 ( V_3 ) ;
F_352 ( V_3 , V_357 , V_694 ) ;
F_353 ( V_695 , V_694 ) ;
F_152 ( V_3 ) ;
return 1 ;
case 8 :
V_694 = F_351 ( V_3 ) ;
F_352 ( V_3 , V_357 , V_694 ) ;
F_353 ( V_695 , V_694 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_694 = ( V_689 >> V_700 ) & 0x0f ;
F_348 ( 0 , ( F_310 ( V_3 ) & ~ 0xful ) | V_694 ) ;
F_354 ( V_3 , V_694 ) ;
F_152 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_658 -> V_670 = 0 ;
F_355 ( V_3 , L_19 ,
( int ) ( V_689 >> 4 ) & 3 , V_695 ) ;
return 0 ;
}
static int F_356 ( struct V_2 * V_3 )
{
unsigned long V_689 ;
int V_701 , V_357 ;
if ( ! F_357 ( V_3 , 0 ) )
return 1 ;
V_701 = F_78 ( V_681 ) ;
if ( V_701 & V_702 ) {
if ( V_3 -> V_113 & V_649 ) {
V_3 -> V_658 -> V_679 . V_97 . V_661 = V_3 -> V_97 . V_661 ;
V_3 -> V_658 -> V_679 . V_97 . V_680 = V_701 ;
V_3 -> V_658 -> V_679 . V_97 . V_683 =
F_78 ( V_500 ) +
F_78 ( V_362 ) ;
V_3 -> V_658 -> V_679 . V_97 . V_684 = V_112 ;
V_3 -> V_658 -> V_670 = V_682 ;
return 0 ;
} else {
V_3 -> V_97 . V_680 &= ~ V_702 ;
V_3 -> V_97 . V_661 |= V_703 ;
F_85 ( V_681 , V_3 -> V_97 . V_680 ) ;
F_324 ( V_3 , V_112 ) ;
return 1 ;
}
}
V_689 = F_78 ( V_676 ) ;
V_701 = V_689 & V_704 ;
V_357 = F_358 ( V_689 ) ;
if ( V_689 & V_705 ) {
unsigned long V_694 ;
if ( ! F_359 ( V_3 , V_701 , & V_694 ) )
F_352 ( V_3 , V_357 , V_694 ) ;
} else
F_360 ( V_3 , V_701 , V_3 -> V_97 . V_359 [ V_357 ] ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static void F_361 ( struct V_2 * V_3 , unsigned long V_694 )
{
F_85 ( V_681 , V_694 ) ;
}
static int F_362 ( struct V_2 * V_3 )
{
F_363 ( V_3 ) ;
return 1 ;
}
static int F_364 ( struct V_2 * V_3 )
{
T_2 V_280 = V_3 -> V_97 . V_359 [ V_706 ] ;
T_5 V_166 ;
if ( F_186 ( V_3 , V_280 , & V_166 ) ) {
F_365 ( V_280 ) ;
F_366 ( V_3 , 0 ) ;
return 1 ;
}
F_367 ( V_280 , V_166 ) ;
V_3 -> V_97 . V_359 [ V_707 ] = V_166 & - 1u ;
V_3 -> V_97 . V_359 [ V_600 ] = ( V_166 >> 32 ) & - 1u ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_368 ( struct V_2 * V_3 )
{
struct V_349 V_60 ;
T_2 V_280 = V_3 -> V_97 . V_359 [ V_706 ] ;
T_5 V_166 = ( V_3 -> V_97 . V_359 [ V_707 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_97 . V_359 [ V_600 ] & - 1u ) << 32 ) ;
V_60 . V_166 = V_166 ;
V_60 . V_65 = V_280 ;
V_60 . V_708 = false ;
if ( F_188 ( V_3 , & V_60 ) != 0 ) {
F_369 ( V_280 , V_166 ) ;
F_366 ( V_3 , 0 ) ;
return 1 ;
}
F_370 ( V_280 , V_166 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_371 ( struct V_2 * V_3 )
{
F_132 ( V_709 , V_3 ) ;
return 1 ;
}
static int F_372 ( struct V_2 * V_3 )
{
T_2 V_56 ;
V_56 = F_80 ( V_469 ) ;
V_56 &= ~ V_297 ;
F_88 ( V_469 , V_56 ) ;
F_132 ( V_709 , V_3 ) ;
++ V_3 -> V_197 . V_710 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_658 -> V_711 &&
! F_373 ( V_3 ) ) {
V_3 -> V_658 -> V_670 = V_712 ;
return 0 ;
}
return 1 ;
}
static int F_374 ( struct V_2 * V_3 )
{
F_152 ( V_3 ) ;
return F_335 ( V_3 ) ;
}
static int F_375 ( struct V_2 * V_3 )
{
F_152 ( V_3 ) ;
F_376 ( V_3 ) ;
return 1 ;
}
static int F_377 ( struct V_2 * V_3 )
{
return F_323 ( V_3 , 0 ) == V_247 ;
}
static int F_378 ( struct V_2 * V_3 )
{
unsigned long V_689 = F_78 ( V_676 ) ;
F_379 ( V_3 , V_689 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_380 ( struct V_2 * V_3 )
{
int V_696 ;
V_696 = F_381 ( V_3 ) ;
F_349 ( V_3 , V_696 ) ;
return 1 ;
}
static int F_382 ( struct V_2 * V_3 )
{
F_152 ( V_3 ) ;
F_383 ( V_3 ) ;
return 1 ;
}
static int F_384 ( struct V_2 * V_3 )
{
T_5 V_713 = F_385 ( V_3 ) ;
T_2 V_65 = F_347 ( V_3 , V_706 ) ;
if ( F_386 ( V_3 , V_65 , V_713 ) == 0 )
F_152 ( V_3 ) ;
return 1 ;
}
static int F_387 ( struct V_2 * V_3 )
{
if ( F_278 ( V_714 ) ) {
unsigned long V_689 = F_78 ( V_676 ) ;
int V_715 , V_274 ;
V_715 = V_689 & V_716 ;
V_274 = V_689 & V_717 ;
if ( ( V_715 == V_718 ) &&
( V_274 == V_719 ) ) {
F_388 ( V_3 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
}
return F_323 ( V_3 , 0 ) == V_247 ;
}
static int F_389 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
unsigned long V_689 ;
bool V_240 = false ;
T_2 V_241 = 0 ;
T_3 V_720 ;
int V_721 , type , V_722 , V_723 ;
V_722 = ( V_59 -> V_665 & V_638 ) ;
V_723 = ( V_59 -> V_665 & V_724 ) ;
type = ( V_59 -> V_665 & V_725 ) ;
V_689 = F_78 ( V_676 ) ;
V_721 = ( T_2 ) V_689 >> 30 ;
if ( V_721 == V_726 && V_722 ) {
switch ( type ) {
case V_633 :
V_3 -> V_97 . V_727 = false ;
F_319 ( V_3 , true ) ;
break;
case V_22 :
case V_628 :
F_390 ( V_3 ) ;
break;
case V_18 :
if ( V_59 -> V_665 &
V_728 ) {
V_240 = true ;
V_241 =
F_80 ( V_729 ) ;
}
case V_250 :
F_391 ( V_3 ) ;
break;
default:
break;
}
}
V_720 = V_689 ;
if ( ! V_722 || ( type != V_18 &&
type != V_22 &&
type != V_633 ) )
F_152 ( V_3 ) ;
if ( F_392 ( V_3 , V_720 ,
type == V_628 ? V_723 : - 1 , V_721 ,
V_240 , V_241 ) == V_730 ) {
V_3 -> V_658 -> V_670 = V_671 ;
V_3 -> V_658 -> V_672 . V_673 = V_731 ;
V_3 -> V_658 -> V_672 . V_675 = 0 ;
return 0 ;
}
F_85 ( V_681 , F_78 ( V_681 ) & ~ 55 ) ;
return 1 ;
}
static int F_393 ( struct V_2 * V_3 )
{
unsigned long V_689 ;
T_1 V_71 ;
T_2 V_241 ;
int V_732 ;
V_689 = F_78 ( V_676 ) ;
V_732 = ( V_689 >> 7 ) & 0x3 ;
if ( V_732 != 0x3 && V_732 != 0x1 && V_732 != 0 ) {
F_55 ( V_75 L_20 ) ;
F_55 ( V_75 L_21 ,
( long unsigned int ) F_81 ( V_733 ) ,
F_78 ( V_734 ) ) ;
F_55 ( V_75 L_22 ,
( long unsigned int ) V_689 ) ;
V_3 -> V_658 -> V_670 = V_735 ;
V_3 -> V_658 -> V_736 . V_737 = V_738 ;
return 0 ;
}
V_71 = F_81 ( V_733 ) ;
F_331 ( V_71 , V_689 ) ;
V_241 = V_689 & ( 1U << 1 ) ;
V_241 |= ( V_689 >> 3 ) & 0x1 ;
return F_334 ( V_3 , V_71 , V_241 , NULL , 0 ) ;
}
static T_5 F_394 ( T_5 V_739 , int V_740 )
{
int V_61 ;
T_5 V_91 = 0 ;
for ( V_61 = 51 ; V_61 > V_397 . V_741 ; V_61 -- )
V_91 |= ( 1ULL << V_61 ) ;
if ( V_740 > 2 )
V_91 |= 0xf8 ;
else if ( V_740 == 2 ) {
if ( V_739 & ( 1ULL << 7 ) )
V_91 |= 0x1ff000 ;
else
V_91 |= 0x78 ;
}
return V_91 ;
}
static void F_395 ( struct V_2 * V_3 , T_5 V_739 ,
int V_740 )
{
F_55 ( V_75 L_23 , V_453 , V_739 , V_740 ) ;
F_396 ( ( V_739 & 0x7 ) == 0x2 ) ;
F_396 ( ( V_739 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_396 ( ( V_739 & 0x7 ) == 0x4 ) ;
if ( ( V_739 & 0x7 ) ) {
T_5 V_742 = V_739 & F_394 ( V_739 , V_740 ) ;
if ( V_742 != 0 ) {
F_55 ( V_75 L_24 ,
V_453 , V_742 ) ;
F_396 ( 1 ) ;
}
if ( V_740 == 1 || ( V_740 == 2 && ( V_739 & ( 1ULL << 7 ) ) ) ) {
T_5 V_743 = ( V_739 & 0x38 ) >> 3 ;
if ( V_743 == 2 || V_743 == 3 ||
V_743 == 7 ) {
F_55 ( V_75 L_25 ,
V_453 , V_743 ) ;
F_396 ( 1 ) ;
}
}
}
}
static int F_397 ( struct V_2 * V_3 )
{
T_5 V_744 [ 4 ] ;
int V_745 , V_61 , V_95 ;
T_1 V_71 ;
V_71 = F_81 ( V_733 ) ;
V_95 = F_398 ( V_3 , V_71 , true ) ;
if ( F_278 ( V_95 == 1 ) )
return F_399 ( V_3 , V_71 , 0 , NULL , 0 ) ==
V_247 ;
if ( F_86 ( ! V_95 ) )
return 1 ;
F_55 ( V_75 L_26 ) ;
F_55 ( V_75 L_27 , V_71 ) ;
V_745 = F_400 ( V_3 , V_71 , V_744 ) ;
for ( V_61 = V_746 ; V_61 > V_746 - V_745 ; -- V_61 )
F_395 ( V_3 , V_744 [ V_61 - 1 ] , V_61 ) ;
V_3 -> V_658 -> V_670 = V_735 ;
V_3 -> V_658 -> V_736 . V_737 = V_747 ;
return 0 ;
}
static int F_401 ( struct V_2 * V_3 )
{
T_2 V_56 ;
V_56 = F_80 ( V_469 ) ;
V_56 &= ~ V_622 ;
F_88 ( V_469 , V_56 ) ;
++ V_3 -> V_197 . V_748 ;
F_132 ( V_709 , V_3 ) ;
return 1 ;
}
static int F_402 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
enum V_663 V_696 = V_247 ;
int V_95 = 1 ;
T_2 V_749 ;
bool V_750 ;
unsigned V_751 = 130 ;
V_749 = F_80 ( V_469 ) ;
V_750 = V_749 & V_297 ;
while ( ! F_273 ( V_3 ) && V_751 -- != 0 ) {
if ( V_750 && F_320 ( V_3 ) )
return F_372 ( & V_59 -> V_3 ) ;
if ( F_146 ( V_709 , & V_3 -> V_752 ) )
return 1 ;
V_696 = F_323 ( V_3 , 0 ) ;
if ( V_696 == V_753 ) {
V_95 = 0 ;
goto V_524;
}
if ( V_696 != V_247 ) {
V_3 -> V_658 -> V_670 = V_671 ;
V_3 -> V_658 -> V_672 . V_673 = V_731 ;
V_3 -> V_658 -> V_672 . V_675 = 0 ;
return 0 ;
}
if ( F_403 ( V_754 ) )
goto V_524;
if ( F_404 () )
F_405 () ;
}
V_59 -> V_418 = ! F_273 ( V_3 ) ;
V_524:
return V_95 ;
}
static int F_406 ( struct V_2 * V_3 )
{
F_152 ( V_3 ) ;
F_407 ( V_3 ) ;
return 1 ;
}
static int F_408 ( struct V_2 * V_3 )
{
F_324 ( V_3 , V_21 ) ;
return 1 ;
}
static struct V_76 * F_409 ( struct V_1 * V_59 )
{
struct V_755 * V_756 ;
F_66 (item, &vmx->nested.vmcs02_pool, list)
if ( V_756 -> V_757 == V_59 -> V_8 . V_758 ) {
F_410 ( & V_756 -> V_759 , & V_59 -> V_8 . V_760 ) ;
return & V_756 -> V_761 ;
}
if ( V_59 -> V_8 . V_762 >= F_411 ( V_763 , 1 ) ) {
V_756 = F_412 ( V_59 -> V_8 . V_760 . V_764 ,
struct V_755 , V_759 ) ;
V_756 -> V_757 = V_59 -> V_8 . V_758 ;
F_410 ( & V_756 -> V_759 , & V_59 -> V_8 . V_760 ) ;
return & V_756 -> V_761 ;
}
V_756 = (struct V_755 * )
F_413 ( sizeof( struct V_755 ) , V_402 ) ;
if ( ! V_756 )
return NULL ;
V_756 -> V_761 . V_73 = F_213 () ;
if ( ! V_756 -> V_761 . V_73 ) {
F_414 ( V_756 ) ;
return NULL ;
}
F_56 ( & V_756 -> V_761 ) ;
V_756 -> V_757 = V_59 -> V_8 . V_758 ;
F_135 ( & ( V_756 -> V_759 ) , & ( V_59 -> V_8 . V_760 ) ) ;
V_59 -> V_8 . V_762 ++ ;
return & V_756 -> V_761 ;
}
static void F_415 ( struct V_1 * V_59 , T_1 V_757 )
{
struct V_755 * V_756 ;
F_66 (item, &vmx->nested.vmcs02_pool, list)
if ( V_756 -> V_757 == V_757 ) {
F_216 ( & V_756 -> V_761 ) ;
F_69 ( & V_756 -> V_759 ) ;
F_414 ( V_756 ) ;
V_59 -> V_8 . V_762 -- ;
return;
}
}
static void F_416 ( struct V_1 * V_59 )
{
struct V_755 * V_756 , * V_372 ;
F_203 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_59 -> V_76 != & V_756 -> V_761 )
F_216 ( & V_756 -> V_761 ) ;
F_69 ( & V_756 -> V_759 ) ;
F_414 ( V_756 ) ;
}
V_59 -> V_8 . V_762 = 0 ;
if ( V_59 -> V_76 != & V_59 -> V_765 )
F_216 ( & V_59 -> V_765 ) ;
}
static int F_417 ( struct V_2 * V_3 )
{
struct V_411 V_511 ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
if ( ! F_418 ( V_3 , V_370 ) ||
! F_140 ( V_3 , V_475 ) ||
( F_145 ( V_3 ) & V_230 ) ) {
F_324 ( V_3 , V_21 ) ;
return 1 ;
}
F_232 ( V_3 , & V_511 , V_449 ) ;
if ( F_117 ( V_3 ) && ! V_511 . V_493 ) {
F_324 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_259 ( V_3 ) ) {
F_366 ( V_3 , 0 ) ;
return 1 ;
}
F_199 ( & ( V_59 -> V_8 . V_760 ) ) ;
V_59 -> V_8 . V_762 = 0 ;
V_59 -> V_8 . V_487 = true ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_419 ( struct V_2 * V_3 )
{
struct V_411 V_511 ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
if ( ! V_59 -> V_8 . V_487 ) {
F_324 ( V_3 , V_21 ) ;
return 0 ;
}
F_232 ( V_3 , & V_511 , V_449 ) ;
if ( ( F_145 ( V_3 ) & V_230 ) ||
( F_117 ( V_3 ) && ! V_511 . V_493 ) ) {
F_324 ( V_3 , V_21 ) ;
return 0 ;
}
if ( F_259 ( V_3 ) ) {
F_366 ( V_3 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_420 ( struct V_1 * V_59 )
{
if ( ! V_59 -> V_8 . V_487 )
return;
V_59 -> V_8 . V_487 = false ;
if ( V_59 -> V_8 . V_758 != - 1ull ) {
F_421 ( V_59 -> V_8 . V_766 ) ;
F_8 ( V_59 -> V_8 . V_766 ) ;
V_59 -> V_8 . V_758 = - 1ull ;
V_59 -> V_8 . V_9 = NULL ;
}
if ( V_59 -> V_8 . V_541 ) {
F_8 ( V_59 -> V_8 . V_541 ) ;
V_59 -> V_8 . V_541 = 0 ;
}
F_416 ( V_59 ) ;
}
static int F_422 ( struct V_2 * V_3 )
{
if ( ! F_419 ( V_3 ) )
return 1 ;
F_420 ( F_1 ( V_3 ) ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_423 ( struct V_2 * V_3 ,
unsigned long V_689 ,
T_2 V_767 , T_4 * V_95 )
{
int V_768 = V_767 & 3 ;
int V_769 = ( V_767 >> 7 ) & 7 ;
bool V_770 = V_767 & ( 1u << 10 ) ;
int V_771 = ( V_767 >> 15 ) & 7 ;
int V_772 = ( V_767 >> 18 ) & 0xf ;
bool V_773 = ! ( V_767 & ( 1u << 22 ) ) ;
int V_774 = ( V_767 >> 23 ) & 0xf ;
bool V_775 = ! ( V_767 & ( 1u << 27 ) ) ;
if ( V_770 ) {
F_324 ( V_3 , V_21 ) ;
return 1 ;
}
* V_95 = F_255 ( V_3 , V_771 ) ;
if ( V_775 )
* V_95 += F_347 ( V_3 , V_774 ) ;
if ( V_773 )
* V_95 += F_347 ( V_3 , V_772 ) << V_768 ;
* V_95 += V_689 ;
if ( V_769 == 1 )
* V_95 &= 0xffffffff ;
return 0 ;
}
static void F_424 ( struct V_2 * V_3 )
{
F_148 ( V_3 , F_145 ( V_3 )
& ~ ( V_776 | V_777 | V_778 |
V_779 | V_780 | V_781 ) ) ;
}
static void F_425 ( struct V_2 * V_3 )
{
F_148 ( V_3 , ( F_145 ( V_3 )
& ~ ( V_777 | V_778 | V_779 |
V_780 | V_781 ) )
| V_776 ) ;
}
static void F_426 ( struct V_2 * V_3 ,
T_2 V_782 )
{
if ( F_1 ( V_3 ) -> V_8 . V_758 == - 1ull ) {
F_425 ( V_3 ) ;
return;
}
F_148 ( V_3 , ( F_145 ( V_3 )
& ~ ( V_776 | V_777 | V_778 |
V_780 | V_781 ) )
| V_779 ) ;
F_4 ( V_3 ) -> V_782 = V_782 ;
}
static int F_427 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_4 V_67 ;
T_1 V_757 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_783 V_784 ;
if ( ! F_419 ( V_3 ) )
return 1 ;
if ( F_423 ( V_3 , F_78 ( V_676 ) ,
F_80 ( V_785 ) , & V_67 ) )
return 1 ;
if ( F_428 ( & V_3 -> V_97 . V_786 , V_67 , & V_757 ,
sizeof( V_757 ) , & V_784 ) ) {
F_429 ( V_3 , & V_784 ) ;
return 1 ;
}
if ( ! F_430 ( V_757 , V_392 ) ) {
F_426 ( V_3 , V_787 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
if ( V_757 == V_59 -> V_8 . V_758 ) {
F_421 ( V_59 -> V_8 . V_766 ) ;
F_8 ( V_59 -> V_8 . V_766 ) ;
V_59 -> V_8 . V_758 = - 1ull ;
V_59 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_757 ) ;
if ( V_10 == NULL ) {
F_132 ( V_248 , V_3 ) ;
return 1 ;
}
V_7 = F_431 ( V_10 ) ;
V_7 -> V_788 = 0 ;
F_421 ( V_10 ) ;
F_8 ( V_10 ) ;
F_415 ( V_59 , V_757 ) ;
F_152 ( V_3 ) ;
F_424 ( V_3 ) ;
return 1 ;
}
static int F_432 ( struct V_2 * V_3 )
{
return F_433 ( V_3 , true ) ;
}
static int F_434 ( struct V_2 * V_3 )
{
return F_433 ( V_3 , false ) ;
}
static inline int F_435 ( unsigned long V_4 )
{
if ( 0x1 & V_4 )
return V_789 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_436 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_437 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_95 )
{
short V_274 = F_3 ( V_4 ) ;
char * V_100 ;
if ( V_274 < 0 )
return 0 ;
V_100 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_274 ;
switch ( F_435 ( V_4 ) ) {
case V_790 :
* V_95 = * ( ( V_791 * ) V_100 ) ;
return 1 ;
case V_792 :
* V_95 = * ( ( T_3 * ) V_100 ) ;
return 1 ;
case V_789 :
* V_95 = * ( ( T_2 * ) V_100 ) ;
return 1 ;
case V_793 :
* V_95 = * ( ( T_5 * ) V_100 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_438 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
if ( V_59 -> V_8 . V_758 == - 1ull ) {
F_425 ( V_3 ) ;
F_152 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_439 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_794 ;
unsigned long V_689 = F_78 ( V_676 ) ;
T_2 V_767 = F_80 ( V_785 ) ;
T_4 V_67 = 0 ;
if ( ! F_419 ( V_3 ) ||
! F_438 ( V_3 ) )
return 1 ;
V_4 = F_347 ( V_3 , ( ( ( V_767 ) >> 28 ) & 0xf ) ) ;
if ( ! F_437 ( V_3 , V_4 , & V_794 ) ) {
F_426 ( V_3 , V_795 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
if ( V_767 & ( 1u << 10 ) ) {
F_352 ( V_3 , ( ( ( V_767 ) >> 3 ) & 0xf ) ,
V_794 ) ;
} else {
if ( F_423 ( V_3 , V_689 ,
V_767 , & V_67 ) )
return 1 ;
F_440 ( & V_3 -> V_97 . V_786 , V_67 ,
& V_794 , ( F_117 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_424 ( V_3 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_441 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_67 ;
unsigned long V_689 = F_78 ( V_676 ) ;
T_2 V_767 = F_80 ( V_785 ) ;
char * V_100 ;
short V_274 ;
T_5 V_794 = 0 ;
struct V_783 V_784 ;
if ( ! F_419 ( V_3 ) ||
! F_438 ( V_3 ) )
return 1 ;
if ( V_767 & ( 1u << 10 ) )
V_794 = F_347 ( V_3 ,
( ( ( V_767 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_423 ( V_3 , V_689 ,
V_767 , & V_67 ) )
return 1 ;
if ( F_428 ( & V_3 -> V_97 . V_786 , V_67 ,
& V_794 , ( F_117 ( V_3 ) ? 8 : 4 ) , & V_784 ) ) {
F_429 ( V_3 , & V_784 ) ;
return 1 ;
}
}
V_4 = F_347 ( V_3 , ( ( ( V_767 ) >> 28 ) & 0xf ) ) ;
if ( F_436 ( V_4 ) ) {
F_426 ( V_3 ,
V_796 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
V_274 = F_3 ( V_4 ) ;
if ( V_274 < 0 ) {
F_426 ( V_3 , V_795 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
V_100 = ( ( char * ) F_4 ( V_3 ) ) + V_274 ;
switch ( F_435 ( V_4 ) ) {
case V_792 :
* ( T_3 * ) V_100 = V_794 ;
break;
case V_789 :
* ( T_2 * ) V_100 = V_794 ;
break;
case V_793 :
* ( T_5 * ) V_100 = V_794 ;
break;
case V_790 :
* ( V_791 * ) V_100 = V_794 ;
break;
default:
F_426 ( V_3 , V_795 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
F_424 ( V_3 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_442 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_4 V_67 ;
T_1 V_757 ;
struct V_783 V_784 ;
if ( ! F_419 ( V_3 ) )
return 1 ;
if ( F_423 ( V_3 , F_78 ( V_676 ) ,
F_80 ( V_785 ) , & V_67 ) )
return 1 ;
if ( F_428 ( & V_3 -> V_97 . V_786 , V_67 , & V_757 ,
sizeof( V_757 ) , & V_784 ) ) {
F_429 ( V_3 , & V_784 ) ;
return 1 ;
}
if ( ! F_430 ( V_757 , V_392 ) ) {
F_426 ( V_3 , V_797 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
if ( V_59 -> V_8 . V_758 != V_757 ) {
struct V_7 * V_798 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_757 ) ;
if ( V_10 == NULL ) {
F_425 ( V_3 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
V_798 = F_431 ( V_10 ) ;
if ( V_798 -> V_395 != V_323 ) {
F_421 ( V_10 ) ;
F_10 ( V_10 ) ;
F_426 ( V_3 ,
V_799 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
if ( V_59 -> V_8 . V_758 != - 1ull ) {
F_421 ( V_59 -> V_8 . V_766 ) ;
F_8 ( V_59 -> V_8 . V_766 ) ;
}
V_59 -> V_8 . V_758 = V_757 ;
V_59 -> V_8 . V_9 = V_798 ;
V_59 -> V_8 . V_766 = V_10 ;
}
F_424 ( V_3 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static int F_443 ( struct V_2 * V_3 )
{
unsigned long V_689 = F_78 ( V_676 ) ;
T_2 V_767 = F_80 ( V_785 ) ;
T_4 V_800 ;
struct V_783 V_784 ;
if ( ! F_419 ( V_3 ) )
return 1 ;
if ( F_423 ( V_3 , V_689 ,
V_767 , & V_800 ) )
return 1 ;
if ( F_440 ( & V_3 -> V_97 . V_786 , V_800 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_758 ,
sizeof( T_5 ) , & V_784 ) ) {
F_429 ( V_3 , & V_784 ) ;
return 1 ;
}
F_424 ( V_3 ) ;
F_152 ( V_3 ) ;
return 1 ;
}
static bool F_444 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_670 )
{
T_2 V_317 = V_3 -> V_97 . V_359 [ V_706 ] ;
T_1 V_801 ;
if ( ! F_45 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_801 = V_7 -> V_255 ;
if ( V_670 == V_802 )
V_801 += 2048 ;
if ( V_317 >= 0xc0000000 ) {
V_317 -= 0xc0000000 ;
V_801 += 1024 ;
}
if ( V_317 < 1024 * 8 ) {
unsigned char V_803 ;
F_445 ( V_3 -> V_12 , V_801 + V_317 / 8 , & V_803 , 1 ) ;
return 1 & ( V_803 >> ( V_317 & 7 ) ) ;
} else
return 1 ;
}
static bool F_446 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_689 = F_78 ( V_676 ) ;
int V_695 = V_689 & 15 ;
int V_357 = ( V_689 >> 8 ) & 15 ;
unsigned long V_694 = F_347 ( V_3 , V_357 ) ;
switch ( ( V_689 >> 4 ) & 3 ) {
case 0 :
switch ( V_695 ) {
case 0 :
if ( V_7 -> V_214 &
( V_694 ^ V_7 -> V_218 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_804 >= 1 &&
V_7 -> V_805 == V_694 ) ||
( V_7 -> V_804 >= 2 &&
V_7 -> V_806 == V_694 ) ||
( V_7 -> V_804 >= 3 &&
V_7 -> V_807 == V_694 ) ||
( V_7 -> V_804 >= 4 &&
V_7 -> V_808 == V_694 ) )
return 0 ;
if ( F_45 ( V_7 , V_301 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_220 &
( V_7 -> V_221 ^ V_694 ) )
return 1 ;
break;
case 8 :
if ( F_45 ( V_7 , V_303 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_214 & V_211 ) &&
( V_7 -> V_218 & V_211 ) )
return 1 ;
break;
case 1 :
switch ( V_695 ) {
case 3 :
if ( V_7 -> V_56 &
V_302 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_56 &
V_304 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_214 & 0xe &
( V_694 ^ V_7 -> V_218 ) )
return 1 ;
if ( ( V_7 -> V_214 & 0x1 ) &&
! ( V_7 -> V_218 & 0x1 ) &&
( V_694 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_447 ( struct V_2 * V_3 )
{
T_2 V_670 = F_80 ( V_809 ) ;
T_2 V_14 = F_80 ( V_810 ) ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_59 -> V_8 . V_636 )
return 0 ;
if ( F_86 ( V_59 -> V_811 ) ) {
F_448 ( L_28 , V_453 ,
F_80 ( V_90 ) ) ;
return 1 ;
}
switch ( V_670 ) {
case V_812 :
if ( ! F_48 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_87 ;
return V_7 -> V_120 &
( 1u << ( V_14 & V_16 ) ) ;
case V_640 :
return 0 ;
case V_813 :
return 1 ;
case V_814 :
case V_815 :
return 1 ;
case V_816 :
return 1 ;
case V_817 :
return 1 ;
case V_818 :
return F_45 ( V_7 , V_298 ) ;
case V_819 :
return 1 ;
case V_820 :
return F_45 ( V_7 , V_299 ) ;
case V_821 :
return F_45 ( V_7 , V_309 ) ;
case V_822 :
return F_45 ( V_7 , V_310 ) ;
case V_823 : case V_824 :
case V_825 : case V_826 :
case V_827 : case V_828 :
case V_829 : case V_830 :
case V_831 : case V_832 :
return 1 ;
case V_833 :
return F_446 ( V_3 , V_7 ) ;
case V_834 :
return F_45 ( V_7 , V_305 ) ;
case V_835 :
return 1 ;
case V_836 :
case V_802 :
return F_444 ( V_3 , V_7 , V_670 ) ;
case V_837 :
return 1 ;
case V_838 :
return F_45 ( V_7 , V_300 ) ;
case V_839 :
return F_45 ( V_7 , V_308 ) ;
case V_840 :
return F_45 ( V_7 , V_841 ) ||
F_46 ( V_7 ,
V_47 ) ;
case V_842 :
return 0 ;
case V_843 :
return 1 ;
case V_844 :
return F_46 ( V_7 ,
V_30 ) ;
case V_738 :
case V_747 :
return 0 ;
case V_845 :
return F_46 ( V_7 , V_54 ) ;
case V_846 :
return 1 ;
default:
return 1 ;
}
}
static void F_449 ( struct V_2 * V_3 , T_5 * V_847 , T_5 * V_848 )
{
* V_847 = F_78 ( V_676 ) ;
* V_848 = F_80 ( V_810 ) ;
}
static int F_450 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_2 V_670 = V_59 -> V_670 ;
T_2 V_849 = V_59 -> V_665 ;
if ( V_59 -> V_418 && V_424 )
return F_402 ( V_3 ) ;
if ( V_59 -> V_8 . V_636 )
F_132 ( V_709 , V_3 ) ;
if ( ! F_99 ( V_3 ) && ( V_670 == V_825 ||
V_670 == V_829 ) )
V_59 -> V_8 . V_636 = 1 ;
else
V_59 -> V_8 . V_636 = 0 ;
if ( F_99 ( V_3 ) && F_447 ( V_3 ) ) {
F_156 ( V_3 ) ;
return 1 ;
}
if ( V_670 & V_850 ) {
V_3 -> V_658 -> V_670 = V_851 ;
V_3 -> V_658 -> V_852 . V_853
= V_670 ;
return 0 ;
}
if ( F_86 ( V_59 -> V_811 ) ) {
V_3 -> V_658 -> V_670 = V_851 ;
V_3 -> V_658 -> V_852 . V_853
= F_80 ( V_90 ) ;
return 0 ;
}
if ( ( V_849 & V_638 ) &&
( V_670 != V_812 &&
V_670 != V_738 &&
V_670 != V_816 ) ) {
V_3 -> V_658 -> V_670 = V_671 ;
V_3 -> V_658 -> V_672 . V_673 = V_854 ;
V_3 -> V_658 -> V_672 . V_675 = 2 ;
V_3 -> V_658 -> V_672 . V_166 [ 0 ] = V_849 ;
V_3 -> V_658 -> V_672 . V_166 [ 1 ] = V_670 ;
return 0 ;
}
if ( F_86 ( ! F_42 () && V_59 -> V_599 &&
! ( F_99 ( V_3 ) && F_47 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_320 ( V_3 ) ) {
V_59 -> V_599 = 0 ;
} else if ( V_59 -> V_629 > 1000000000LL &&
V_3 -> V_97 . V_855 ) {
F_55 ( V_149 L_29
L_30 ,
V_453 , V_3 -> V_856 ) ;
V_59 -> V_599 = 0 ;
}
}
if ( V_670 < V_857
&& V_858 [ V_670 ] )
return V_858 [ V_670 ] ( V_3 ) ;
else {
V_3 -> V_658 -> V_670 = V_735 ;
V_3 -> V_658 -> V_736 . V_737 = V_670 ;
}
return 0 ;
}
static void V_409 ( struct V_2 * V_3 , int V_859 , int V_860 )
{
if ( V_860 == - 1 || V_859 < V_860 ) {
F_88 ( V_615 , 0 ) ;
return;
}
F_88 ( V_615 , V_860 ) ;
}
static void F_451 ( struct V_1 * V_59 )
{
T_2 V_666 ;
if ( ! ( V_59 -> V_670 == V_842
|| V_59 -> V_670 == V_812 ) )
return;
V_59 -> V_666 = F_80 ( V_810 ) ;
V_666 = V_59 -> V_666 ;
if ( F_16 ( V_666 ) )
F_325 () ;
if ( ( V_666 & V_15 ) == V_633 &&
( V_666 & V_17 ) ) {
F_452 ( & V_59 -> V_3 ) ;
asm("int $2");
F_453 ( & V_59 -> V_3 ) ;
}
}
static void F_454 ( struct V_1 * V_59 )
{
T_2 V_666 ;
bool V_861 ;
T_6 V_862 ;
bool V_863 ;
V_863 = V_59 -> V_665 & V_638 ;
if ( F_42 () ) {
if ( V_59 -> V_631 )
return;
V_666 = F_80 ( V_810 ) ;
V_861 = ( V_666 & V_864 ) != 0 ;
V_862 = V_666 & V_16 ;
if ( ( V_666 & V_17 ) && V_861 &&
V_862 != V_653 && ! V_863 )
F_91 ( V_232 ,
V_634 ) ;
else
V_59 -> V_631 =
! ( F_80 ( V_232 )
& V_634 ) ;
} else if ( F_86 ( V_59 -> V_599 ) )
V_59 -> V_629 +=
F_455 ( F_456 ( F_457 () , V_59 -> V_865 ) ) ;
}
static void F_458 ( struct V_1 * V_59 ,
T_2 V_665 ,
int V_866 ,
int V_867 )
{
T_6 V_862 ;
int type ;
bool V_863 ;
V_863 = V_665 & V_638 ;
V_59 -> V_3 . V_97 . V_727 = false ;
F_391 ( & V_59 -> V_3 ) ;
F_390 ( & V_59 -> V_3 ) ;
if ( ! V_863 )
return;
F_132 ( V_709 , & V_59 -> V_3 ) ;
V_862 = V_665 & V_724 ;
type = V_665 & V_725 ;
switch ( type ) {
case V_633 :
V_59 -> V_3 . V_97 . V_727 = true ;
F_319 ( & V_59 -> V_3 , false ) ;
break;
case V_250 :
V_59 -> V_3 . V_97 . V_246 =
F_80 ( V_866 ) ;
case V_18 :
if ( V_665 & V_728 ) {
T_2 V_696 = F_80 ( V_867 ) ;
F_182 ( & V_59 -> V_3 , V_862 , V_696 ) ;
} else
F_324 ( & V_59 -> V_3 , V_862 ) ;
break;
case V_628 :
V_59 -> V_3 . V_97 . V_246 =
F_80 ( V_866 ) ;
case V_22 :
F_459 ( & V_59 -> V_3 , V_862 ,
type == V_628 ) ;
break;
default:
break;
}
}
static void F_460 ( struct V_1 * V_59 )
{
if ( F_99 ( & V_59 -> V_3 ) )
return;
F_458 ( V_59 , V_59 -> V_665 ,
V_239 ,
V_729 ) ;
}
static void F_461 ( struct V_2 * V_3 )
{
if ( F_99 ( V_3 ) )
return;
F_458 ( F_1 ( V_3 ) ,
F_80 ( V_251 ) ,
V_249 ,
V_243 ) ;
F_88 ( V_251 , 0 ) ;
}
static void F_462 ( struct V_1 * V_59 )
{
int V_61 , V_868 ;
struct V_869 * V_870 ;
V_870 = F_463 ( & V_868 ) ;
if ( ! V_870 )
return;
for ( V_61 = 0 ; V_61 < V_868 ; V_61 ++ )
if ( V_870 [ V_61 ] . V_137 == V_870 [ V_61 ] . V_136 )
F_101 ( V_59 , V_870 [ V_61 ] . V_60 ) ;
else
F_103 ( V_59 , V_870 [ V_61 ] . V_60 , V_870 [ V_61 ] . V_136 ,
V_870 [ V_61 ] . V_137 ) ;
}
static void T_16 F_464 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
unsigned long V_871 ;
if ( F_99 ( V_3 ) && ! V_59 -> V_8 . V_636 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_637 &
V_638 ) {
F_88 ( V_251 ,
V_7 -> V_637 ) ;
F_88 ( V_249 ,
V_7 -> V_872 ) ;
if ( V_7 -> V_637 &
V_728 )
F_88 ( V_243 ,
V_7 -> V_873 ) ;
}
}
if ( F_86 ( ! F_42 () && V_59 -> V_599 ) )
V_59 -> V_865 = F_457 () ;
if ( V_59 -> V_418 && V_424 )
return;
if ( F_146 ( V_358 , ( unsigned long * ) & V_3 -> V_97 . V_461 ) )
F_85 ( V_360 , V_3 -> V_97 . V_359 [ V_358 ] ) ;
if ( F_146 ( V_361 , ( unsigned long * ) & V_3 -> V_97 . V_461 ) )
F_85 ( V_362 , V_3 -> V_97 . V_359 [ V_361 ] ) ;
if ( V_3 -> V_113 & V_648 )
F_151 ( V_3 , 0 ) ;
F_462 ( V_59 ) ;
V_871 = F_465 () ;
V_59 -> V_874 = V_59 -> V_76 -> V_78 ;
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
#ifdef F_82
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
#ifdef F_82
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
#ifdef F_82
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
#ifdef F_82
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_871 )
F_466 ( V_871 ) ;
#ifndef F_82
F_123 ( V_185 , V_875 ) ;
F_123 ( V_187 , V_875 ) ;
#endif
V_3 -> V_97 . V_98 = ~ ( ( 1 << V_361 ) | ( 1 << V_358 )
| ( 1 << V_225 )
| ( 1 << V_228 )
| ( 1 << V_363 )
| ( 1 << V_99 )
| ( 1 << V_458 ) ) ;
V_3 -> V_97 . V_461 = 0 ;
V_59 -> V_665 = F_80 ( V_876 ) ;
if ( F_99 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_637 = V_59 -> V_665 ;
if ( V_59 -> V_665 & V_638 ) {
V_7 -> V_873 =
F_80 ( V_729 ) ;
V_7 -> V_872 =
F_80 ( V_239 ) ;
}
}
V_59 -> V_76 -> V_78 = 1 ;
V_59 -> V_670 = F_80 ( V_809 ) ;
F_467 ( V_59 -> V_670 , V_3 , V_877 ) ;
F_451 ( V_59 ) ;
F_454 ( V_59 ) ;
F_460 ( V_59 ) ;
}
static void F_468 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
F_289 ( V_59 ) ;
F_420 ( V_59 ) ;
F_216 ( V_59 -> V_76 ) ;
F_414 ( V_59 -> V_64 ) ;
F_469 ( V_3 ) ;
F_470 ( V_878 , V_59 ) ;
}
static struct V_2 * F_471 ( struct V_12 * V_12 , unsigned int V_879 )
{
int V_696 ;
struct V_1 * V_59 = F_472 ( V_878 , V_402 ) ;
int V_77 ;
if ( ! V_59 )
return F_473 ( - V_403 ) ;
F_285 ( V_59 ) ;
V_696 = F_474 ( & V_59 -> V_3 , V_12 , V_879 ) ;
if ( V_696 )
goto V_880;
V_59 -> V_64 = F_413 ( V_392 , V_402 ) ;
V_696 = - V_403 ;
if ( ! V_59 -> V_64 ) {
goto V_881;
}
V_59 -> V_76 = & V_59 -> V_765 ;
V_59 -> V_76 -> V_73 = F_213 () ;
if ( ! V_59 -> V_76 -> V_73 )
goto V_882;
if ( ! V_201 )
F_131 ( F_54 ( F_68 ( V_200 , F_65 () ) ) ) ;
F_56 ( V_59 -> V_76 ) ;
if ( ! V_201 )
F_138 () ;
V_77 = F_475 () ;
F_130 ( & V_59 -> V_3 , V_77 ) ;
V_59 -> V_3 . V_77 = V_77 ;
V_696 = F_301 ( V_59 ) ;
F_137 ( & V_59 -> V_3 ) ;
F_476 () ;
if ( V_696 )
goto F_214;
if ( F_38 ( V_12 ) )
V_696 = F_280 ( V_12 ) ;
if ( V_696 )
goto F_214;
if ( V_87 ) {
if ( ! V_12 -> V_97 . V_483 )
V_12 -> V_97 . V_483 =
V_883 ;
V_696 = - V_403 ;
if ( F_284 ( V_12 ) != 0 )
goto F_214;
if ( ! F_277 ( V_12 ) )
goto F_214;
}
V_59 -> V_8 . V_758 = - 1ull ;
V_59 -> V_8 . V_9 = NULL ;
return & V_59 -> V_3 ;
F_214:
F_216 ( V_59 -> V_76 ) ;
V_882:
F_414 ( V_59 -> V_64 ) ;
V_881:
F_469 ( & V_59 -> V_3 ) ;
V_880:
F_289 ( V_59 ) ;
F_470 ( V_878 , V_59 ) ;
return F_473 ( V_696 ) ;
}
static void T_11 F_477 ( void * V_884 )
{
struct V_24 V_380 ;
* ( int * ) V_884 = 0 ;
if ( F_207 ( & V_380 ) < 0 )
* ( int * ) V_884 = - V_379 ;
if ( memcmp ( & V_24 , & V_380 , sizeof( struct V_24 ) ) != 0 ) {
F_55 ( V_75 L_31 ,
F_478 () ) ;
* ( int * ) V_884 = - V_379 ;
}
}
static int F_479 ( void )
{
return V_477 + 1 ;
}
static T_5 F_480 ( struct V_2 * V_3 , T_13 V_885 , bool V_886 )
{
T_5 V_95 ;
if ( V_886 )
V_95 = V_887 << V_888 ;
else if ( V_3 -> V_12 -> V_97 . V_889 &&
! ( V_3 -> V_12 -> V_97 . V_890 & V_891 ) )
V_95 = F_481 ( V_3 , V_885 ) <<
V_888 ;
else
V_95 = ( V_892 << V_888 )
| V_893 ;
return V_95 ;
}
static int F_482 ( void )
{
if ( V_87 && ! F_28 () )
return V_894 ;
else
return V_895 ;
}
static void F_483 ( struct V_2 * V_3 )
{
struct V_278 * V_279 ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_2 V_574 ;
V_59 -> V_260 = false ;
if ( F_160 () ) {
V_574 = F_80 ( V_582 ) ;
if ( V_574 & V_50 ) {
V_279 = F_175 ( V_3 , 0x80000001 , 0 ) ;
if ( V_279 && ( V_279 -> V_896 & V_55 ( V_897 ) ) )
V_59 -> V_260 = true ;
else {
V_574 &= ~ V_50 ;
F_88 ( V_582 ,
V_574 ) ;
}
}
}
V_279 = F_175 ( V_3 , 0x7 , 0 ) ;
if ( F_161 () &&
V_279 && ( V_279 -> V_898 & V_55 ( V_899 ) ) &&
F_484 ( V_3 ) ) {
V_574 = F_80 ( V_582 ) ;
V_574 |= V_51 ;
F_88 ( V_582 ,
V_574 ) ;
} else {
if ( F_21 () ) {
V_574 = F_80 ( V_582 ) ;
V_574 &= ~ V_51 ;
F_88 ( V_582 ,
V_574 ) ;
}
if ( V_279 )
V_279 -> V_898 &= ~ V_55 ( V_899 ) ;
}
}
static void F_485 ( T_2 V_900 , struct V_278 * V_122 )
{
if ( V_900 == 1 && V_8 )
V_122 -> V_280 |= V_55 ( V_281 ) ;
}
static void F_486 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
T_2 V_574 ;
F_87 ( V_901 , V_7 -> V_902 ) ;
F_87 ( V_431 , V_7 -> V_903 ) ;
F_87 ( V_429 , V_7 -> V_904 ) ;
F_87 ( V_905 , V_7 -> V_906 ) ;
F_87 ( V_907 , V_7 -> V_908 ) ;
F_87 ( V_909 , V_7 -> V_910 ) ;
F_87 ( V_605 , V_7 -> V_911 ) ;
F_87 ( V_604 , V_7 -> V_912 ) ;
F_88 ( V_913 , V_7 -> V_914 ) ;
F_88 ( V_499 , V_7 -> V_915 ) ;
F_88 ( V_502 , V_7 -> V_916 ) ;
F_88 ( V_917 , V_7 -> V_918 ) ;
F_88 ( V_919 , V_7 -> V_920 ) ;
F_88 ( V_921 , V_7 -> V_922 ) ;
F_88 ( V_607 , V_7 -> V_923 ) ;
F_88 ( V_444 , V_7 -> V_924 ) ;
F_88 ( V_506 , V_7 -> V_925 ) ;
F_88 ( V_504 , V_7 -> V_926 ) ;
F_88 ( V_927 , V_7 -> V_928 ) ;
F_88 ( V_432 , V_7 -> V_929 ) ;
F_88 ( V_430 , V_7 -> V_930 ) ;
F_88 ( V_931 , V_7 -> V_932 ) ;
F_88 ( V_933 , V_7 -> V_934 ) ;
F_88 ( V_935 , V_7 -> V_936 ) ;
F_88 ( V_608 , V_7 -> V_937 ) ;
F_88 ( V_446 , V_7 -> V_938 ) ;
F_85 ( V_939 , V_7 -> V_940 ) ;
F_85 ( V_500 , V_7 -> V_941 ) ;
F_85 ( V_501 , V_7 -> V_942 ) ;
F_85 ( V_943 , V_7 -> V_944 ) ;
F_85 ( V_341 , V_7 -> V_945 ) ;
F_85 ( V_342 , V_7 -> V_946 ) ;
F_85 ( V_606 , V_7 -> V_947 ) ;
F_85 ( V_443 , V_7 -> V_948 ) ;
F_85 ( V_507 , V_7 -> V_949 ) ;
F_85 ( V_505 , V_7 -> V_950 ) ;
F_89 ( V_612 , V_7 -> V_951 ) ;
F_88 ( V_251 ,
V_7 -> V_952 ) ;
F_88 ( V_243 ,
V_7 -> V_953 ) ;
F_88 ( V_249 ,
V_7 -> V_954 ) ;
F_88 ( V_232 ,
V_7 -> V_955 ) ;
F_88 ( V_609 , V_7 -> V_956 ) ;
F_88 ( V_345 , V_7 -> V_957 ) ;
F_85 ( V_681 , V_7 -> V_958 ) ;
F_85 ( V_226 , V_7 -> V_959 ) ;
F_85 ( V_611 ,
V_7 -> V_960 ) ;
F_85 ( V_348 , V_7 -> V_961 ) ;
F_85 ( V_347 , V_7 -> V_962 ) ;
F_89 ( V_580 , - 1ull ) ;
F_88 ( V_581 ,
( V_24 . V_52 |
V_7 -> V_58 ) ) ;
F_88 ( V_586 ,
V_87 ? V_7 -> V_963 : 0 ) ;
F_88 ( V_587 ,
V_87 ? V_7 -> V_964 : 0 ) ;
if ( F_21 () ) {
T_2 V_574 = F_298 ( V_59 ) ;
if ( ! V_59 -> V_260 )
V_574 &= ~ V_50 ;
V_574 &= ~ V_30 ;
if ( F_45 ( V_7 ,
V_28 ) )
V_574 |= V_7 -> V_57 ;
if ( V_574 & V_30 ) {
if ( V_59 -> V_8 . V_541 )
F_8 ( V_59 -> V_8 . V_541 ) ;
V_59 -> V_8 . V_541 =
F_5 ( V_3 , V_7 -> V_965 ) ;
if ( ! V_59 -> V_8 . V_541 )
V_574 &=
~ V_30 ;
else
F_89 ( V_616 ,
F_309 ( V_59 -> V_8 . V_541 ) ) ;
}
F_88 ( V_582 , V_574 ) ;
}
F_292 () ;
V_59 -> V_966 = 0 ;
V_574 = F_297 ( V_59 ) ;
V_574 &= ~ V_297 ;
V_574 &= ~ V_622 ;
V_574 &= ~ V_27 ;
V_574 |= V_7 -> V_56 ;
V_574 &= ~ V_26 ;
V_574 &= ~ V_307 ;
V_574 |= V_306 ;
F_88 ( V_469 , V_574 ) ;
F_98 ( V_3 ) ;
V_3 -> V_97 . V_213 &= ~ V_7 -> V_214 ;
F_85 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
F_88 ( V_124 ,
V_7 -> V_967 | V_24 . V_396 ) ;
F_88 ( V_123 , V_7 -> V_968 |
( V_24 . V_352 & ~ V_293 ) ) ;
if ( V_7 -> V_968 & V_292 )
F_89 ( V_353 , V_7 -> V_969 ) ;
else if ( V_24 . V_352 & V_292 )
F_89 ( V_353 , V_59 -> V_3 . V_97 . V_354 ) ;
F_296 ( V_59 ) ;
if ( V_7 -> V_56 & V_275 )
F_89 ( V_267 ,
V_59 -> V_8 . V_268 + V_7 -> V_266 ) ;
else
F_89 ( V_267 , V_59 -> V_8 . V_268 ) ;
if ( V_405 ) {
F_87 ( V_617 , V_59 -> V_42 ) ;
F_241 ( V_3 ) ;
}
if ( V_7 -> V_968 & V_129 )
V_3 -> V_97 . V_160 = V_7 -> V_970 ;
if ( V_7 -> V_968 & V_293 )
V_3 -> V_97 . V_160 |= ( V_163 | V_164 ) ;
else
V_3 -> V_97 . V_160 &= ~ ( V_163 | V_164 ) ;
F_237 ( V_3 , V_3 -> V_97 . V_160 ) ;
F_252 ( V_3 , V_7 -> V_217 ) ;
F_85 ( V_222 , F_141 ( V_7 ) ) ;
F_250 ( V_3 , V_7 -> V_219 ) ;
F_85 ( V_423 , F_142 ( V_7 ) ) ;
F_350 ( V_3 , V_7 -> V_481 ) ;
F_236 ( V_3 ) ;
F_352 ( V_3 , V_358 , V_7 -> V_971 ) ;
F_352 ( V_3 , V_361 , V_7 -> V_972 ) ;
}
static int F_433 ( struct V_2 * V_3 , bool V_973 )
{
struct V_7 * V_7 ;
struct V_1 * V_59 = F_1 ( V_3 ) ;
int V_77 ;
struct V_76 * V_761 ;
if ( ! F_419 ( V_3 ) ||
! F_438 ( V_3 ) )
return 1 ;
F_152 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_788 == V_973 ) {
F_426 ( V_3 ,
V_973 ? V_974
: V_975 ) ;
return 1 ;
}
if ( ( V_7 -> V_56 & V_26 ) &&
! F_430 ( V_7 -> V_255 , V_392 ) ) {
F_426 ( V_3 , V_976 ) ;
return 1 ;
}
if ( F_46 ( V_7 , V_30 ) &&
! F_430 ( V_7 -> V_965 , V_392 ) ) {
F_426 ( V_3 , V_976 ) ;
return 1 ;
}
if ( V_7 -> V_977 > 0 ||
V_7 -> V_978 > 0 ||
V_7 -> V_979 > 0 ) {
F_487 ( L_32 ,
V_453 ) ;
F_426 ( V_3 , V_976 ) ;
return 1 ;
}
if ( ! F_179 ( V_7 -> V_56 ,
V_295 , V_296 ) ||
! F_179 ( V_7 -> V_57 ,
V_312 , V_313 ) ||
! F_179 ( V_7 -> V_58 ,
V_282 , V_283 ) ||
! F_179 ( V_7 -> V_967 ,
V_286 , V_287 ) ||
! F_179 ( V_7 -> V_968 ,
V_290 , V_291 ) )
{
F_426 ( V_3 , V_976 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_980 & F_183 ) != F_183 ) ||
( ( V_7 -> V_981 & F_184 ) != F_184 ) ) {
F_426 ( V_3 ,
V_982 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_217 & F_183 ) != F_183 ) ||
( ( V_7 -> V_219 & F_184 ) != F_184 ) ) {
F_488 ( V_3 , V_7 ,
V_837 , V_983 ) ;
return 1 ;
}
if ( V_7 -> V_984 != - 1ull ) {
F_488 ( V_3 , V_7 ,
V_837 , V_985 ) ;
return 1 ;
}
V_761 = F_409 ( V_59 ) ;
if ( ! V_761 )
return - V_403 ;
F_489 ( V_3 ) ;
V_59 -> V_8 . V_268 = F_81 ( V_267 ) ;
V_77 = F_475 () ;
V_59 -> V_76 = V_761 ;
F_137 ( V_3 ) ;
F_130 ( V_3 , V_77 ) ;
V_3 -> V_77 = V_77 ;
F_476 () ;
V_7 -> V_788 = 1 ;
F_486 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_490 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_78 ( V_210 ) & V_3 -> V_97 . V_213 ) |
( V_7 -> V_217 & V_7 -> V_214 ) |
( F_78 ( V_222 ) & ~ ( V_7 -> V_214 |
V_3 -> V_97 . V_213 ) ) ;
}
static inline unsigned long
F_491 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_78 ( V_421 ) & V_3 -> V_97 . V_459 ) |
( V_7 -> V_219 & V_7 -> V_220 ) |
( F_78 ( V_423 ) & ~ ( V_7 -> V_220 |
V_3 -> V_97 . V_459 ) ) ;
}
void F_492 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_217 = F_490 ( V_3 , V_7 ) ;
V_7 -> V_219 = F_491 ( V_3 , V_7 ) ;
F_359 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_958 ) ;
V_7 -> V_971 = F_347 ( V_3 , V_358 ) ;
V_7 -> V_972 = F_347 ( V_3 , V_361 ) ;
V_7 -> V_959 = F_78 ( V_226 ) ;
V_7 -> V_902 = F_79 ( V_901 ) ;
V_7 -> V_903 = F_79 ( V_431 ) ;
V_7 -> V_904 = F_79 ( V_429 ) ;
V_7 -> V_906 = F_79 ( V_905 ) ;
V_7 -> V_908 = F_79 ( V_907 ) ;
V_7 -> V_910 = F_79 ( V_909 ) ;
V_7 -> V_911 = F_79 ( V_605 ) ;
V_7 -> V_912 = F_79 ( V_604 ) ;
V_7 -> V_914 = F_80 ( V_913 ) ;
V_7 -> V_915 = F_80 ( V_499 ) ;
V_7 -> V_916 = F_80 ( V_502 ) ;
V_7 -> V_918 = F_80 ( V_917 ) ;
V_7 -> V_920 = F_80 ( V_919 ) ;
V_7 -> V_922 = F_80 ( V_921 ) ;
V_7 -> V_923 = F_80 ( V_607 ) ;
V_7 -> V_924 = F_80 ( V_444 ) ;
V_7 -> V_925 = F_80 ( V_506 ) ;
V_7 -> V_926 = F_80 ( V_504 ) ;
V_7 -> V_928 = F_80 ( V_927 ) ;
V_7 -> V_929 = F_80 ( V_432 ) ;
V_7 -> V_930 = F_80 ( V_430 ) ;
V_7 -> V_932 = F_80 ( V_931 ) ;
V_7 -> V_934 = F_80 ( V_933 ) ;
V_7 -> V_936 = F_80 ( V_935 ) ;
V_7 -> V_937 = F_80 ( V_608 ) ;
V_7 -> V_938 = F_80 ( V_446 ) ;
V_7 -> V_940 = F_78 ( V_939 ) ;
V_7 -> V_941 = F_78 ( V_500 ) ;
V_7 -> V_942 = F_78 ( V_501 ) ;
V_7 -> V_944 = F_78 ( V_943 ) ;
V_7 -> V_945 = F_78 ( V_341 ) ;
V_7 -> V_946 = F_78 ( V_342 ) ;
V_7 -> V_947 = F_78 ( V_606 ) ;
V_7 -> V_948 = F_78 ( V_443 ) ;
V_7 -> V_949 = F_78 ( V_507 ) ;
V_7 -> V_950 = F_78 ( V_505 ) ;
V_7 -> V_956 = F_80 ( V_609 ) ;
V_7 -> V_955 =
F_80 ( V_232 ) ;
V_7 -> V_960 =
F_78 ( V_611 ) ;
V_7 -> V_951 = F_81 ( V_612 ) ;
if ( V_7 -> V_968 & V_390 )
V_7 -> V_969 = F_81 ( V_353 ) ;
V_7 -> V_957 = F_80 ( V_345 ) ;
V_7 -> V_961 = F_78 ( V_348 ) ;
V_7 -> V_962 = F_78 ( V_347 ) ;
V_7 -> V_639 = F_80 ( V_809 ) ;
V_7 -> V_689 = F_78 ( V_676 ) ;
V_7 -> V_641 = F_80 ( V_810 ) ;
V_7 -> V_986 = F_80 ( V_668 ) ;
V_7 -> V_637 =
F_80 ( V_876 ) ;
V_7 -> V_873 =
F_80 ( V_729 ) ;
V_7 -> V_872 = F_80 ( V_239 ) ;
V_7 -> V_767 = F_80 ( V_785 ) ;
if ( ! ( V_7 -> V_639 & V_850 ) )
V_7 -> V_952 &= ~ V_17 ;
}
void F_493 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_967 & V_130 )
V_3 -> V_97 . V_160 = V_7 -> V_987 ;
if ( V_7 -> V_967 & V_288 )
V_3 -> V_97 . V_160 |= ( V_163 | V_164 ) ;
else
V_3 -> V_97 . V_160 &= ~ ( V_163 | V_164 ) ;
F_237 ( V_3 , V_3 -> V_97 . V_160 ) ;
F_352 ( V_3 , V_358 , V_7 -> V_966 ) ;
F_352 ( V_3 , V_361 , V_7 -> V_988 ) ;
F_342 ( V_3 , V_7 -> V_980 ) ;
F_98 ( V_3 ) ;
V_3 -> V_97 . V_213 = ( V_3 -> V_119 ? V_211 : 0 ) ;
F_85 ( V_215 , ~ V_3 -> V_97 . V_213 ) ;
V_3 -> V_97 . V_459 = ~ F_78 ( V_573 ) ;
F_344 ( V_3 , V_7 -> V_981 ) ;
F_350 ( V_3 , V_7 -> V_989 ) ;
F_236 ( V_3 ) ;
if ( V_405 ) {
F_241 ( V_3 ) ;
}
F_88 ( V_345 , V_7 -> V_990 ) ;
F_85 ( V_348 , V_7 -> V_991 ) ;
F_85 ( V_347 , V_7 -> V_992 ) ;
F_85 ( V_505 , V_7 -> V_993 ) ;
F_85 ( V_507 , V_7 -> V_994 ) ;
F_85 ( V_443 , V_7 -> V_995 ) ;
F_85 ( V_342 , V_7 -> V_996 ) ;
F_85 ( V_341 , V_7 -> V_997 ) ;
F_87 ( V_901 , V_7 -> V_998 ) ;
F_87 ( V_431 , V_7 -> V_999 ) ;
F_87 ( V_429 , V_7 -> V_1000 ) ;
F_87 ( V_905 , V_7 -> V_1001 ) ;
F_87 ( V_907 , V_7 -> V_1002 ) ;
F_87 ( V_909 , V_7 -> V_1003 ) ;
F_87 ( V_604 , V_7 -> V_1004 ) ;
if ( V_7 -> V_967 & V_391 )
F_89 ( V_353 , V_7 -> V_1005 ) ;
if ( V_7 -> V_967 & V_134 )
F_89 ( V_146 ,
V_7 -> V_1006 ) ;
}
static void F_156 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
int V_77 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_494 ( V_3 ) ;
F_492 ( V_3 , V_7 ) ;
V_77 = F_475 () ;
V_59 -> V_76 = & V_59 -> V_765 ;
F_137 ( V_3 ) ;
F_130 ( V_3 , V_77 ) ;
V_3 -> V_77 = V_77 ;
F_476 () ;
if ( V_763 == 0 )
F_415 ( V_59 , V_59 -> V_8 . V_758 ) ;
F_493 ( V_3 , V_7 ) ;
F_89 ( V_267 , V_59 -> V_8 . V_268 ) ;
V_59 -> V_966 = 0 ;
if ( V_59 -> V_8 . V_541 ) {
F_8 ( V_59 -> V_8 . V_541 ) ;
V_59 -> V_8 . V_541 = 0 ;
}
if ( F_86 ( V_59 -> V_811 ) ) {
V_59 -> V_811 = 0 ;
F_426 ( V_3 , F_80 ( V_90 ) ) ;
} else
F_424 ( V_3 ) ;
}
static void F_488 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_721 , unsigned long V_1007 )
{
F_493 ( V_3 , V_7 ) ;
V_7 -> V_639 = V_721 | V_850 ;
V_7 -> V_689 = V_1007 ;
F_424 ( V_3 ) ;
}
static int F_495 ( struct V_2 * V_3 ,
struct V_1008 * V_1009 ,
enum V_1010 V_1011 )
{
return V_1012 ;
}
static int T_11 F_496 ( void )
{
int V_522 , V_61 ;
F_497 ( V_127 , & V_165 ) ;
for ( V_61 = 0 ; V_61 < V_595 ; ++ V_61 )
F_498 ( V_61 , V_63 [ V_61 ] ) ;
V_577 = ( unsigned long * ) F_499 ( V_402 ) ;
if ( ! V_577 )
return - V_403 ;
V_522 = - V_403 ;
V_579 = ( unsigned long * ) F_499 ( V_402 ) ;
if ( ! V_579 )
goto V_524;
V_263 = ( unsigned long * ) F_499 ( V_402 ) ;
if ( ! V_263 )
goto V_1013;
V_262 = ( unsigned long * ) F_499 ( V_402 ) ;
if ( ! V_262 )
goto V_1014;
memset ( V_577 , 0xff , V_392 ) ;
F_500 ( 0x80 , V_577 ) ;
memset ( V_579 , 0xff , V_392 ) ;
memset ( V_263 , 0xff , V_392 ) ;
memset ( V_262 , 0xff , V_392 ) ;
F_501 ( 0 , V_548 ) ;
V_522 = F_502 ( & V_1015 , sizeof( struct V_1 ) ,
F_503 ( struct V_1 ) , V_1016 ) ;
if ( V_522 )
goto V_1017;
#ifdef F_504
F_505 ( V_1018 ,
F_64 ) ;
#endif
F_291 ( V_190 , false ) ;
F_291 ( V_192 , false ) ;
F_291 ( V_193 , true ) ;
F_291 ( V_344 , false ) ;
F_291 ( V_207 , false ) ;
F_291 ( V_346 , false ) ;
if ( V_87 ) {
F_506 ( 0ull ,
( V_407 ) ? V_1019 : 0ull ,
( V_407 ) ? V_1020 : 0ull ,
0ull , V_1021 ) ;
F_299 () ;
F_507 () ;
} else
F_508 () ;
return 0 ;
V_1017:
F_509 ( ( unsigned long ) V_262 ) ;
V_1014:
F_509 ( ( unsigned long ) V_263 ) ;
V_1013:
F_509 ( ( unsigned long ) V_579 ) ;
V_524:
F_509 ( ( unsigned long ) V_577 ) ;
return V_522 ;
}
static void T_12 F_510 ( void )
{
F_509 ( ( unsigned long ) V_263 ) ;
F_509 ( ( unsigned long ) V_262 ) ;
F_509 ( ( unsigned long ) V_579 ) ;
F_509 ( ( unsigned long ) V_577 ) ;
#ifdef F_504
F_505 ( V_1018 , NULL ) ;
F_511 () ;
#endif
F_512 () ;
}
