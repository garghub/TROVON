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
return V_24 . V_29 &
V_31 ;
}
static inline bool F_24 ( void )
{
return V_24 . V_29 &
V_32 ;
}
static inline bool F_25 ( void )
{
return V_24 . V_29 &
V_33 ;
}
static inline bool F_26 ( void )
{
return F_18 () &&
F_22 () ;
}
static inline bool F_27 ( void )
{
return V_34 . V_35 & V_36 ;
}
static inline bool F_28 ( void )
{
return V_34 . V_35 & V_37 ;
}
static inline bool F_29 ( void )
{
return V_34 . V_35 & V_38 ;
}
static inline bool F_30 ( void )
{
return V_34 . V_35 & V_39 ;
}
static inline bool F_31 ( void )
{
return V_34 . V_35 & V_40 ;
}
static inline bool F_32 ( void )
{
return V_34 . V_35 & V_41 ;
}
static inline bool F_33 ( void )
{
return V_34 . V_35 & V_42 ;
}
static inline bool F_34 ( void )
{
return V_34 . V_35 & V_43 ;
}
static inline bool F_35 ( void )
{
return V_34 . V_35 & V_44 ;
}
static inline bool F_36 ( void )
{
return V_34 . V_45 & V_46 ;
}
static inline bool F_37 ( void )
{
return V_34 . V_45 & V_47 ;
}
static inline bool F_38 ( void )
{
return V_24 . V_29 &
V_48 ;
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
static inline bool F_41 ( struct V_12 * V_12 )
{
return V_51 && F_20 ( V_12 ) ;
}
static inline bool F_42 ( void )
{
return V_24 . V_29 &
V_52 ;
}
static inline bool F_43 ( void )
{
return V_24 . V_29 &
V_53 ;
}
static inline bool F_44 ( void )
{
return V_24 . V_29 &
V_54 ;
}
static inline bool F_45 ( void )
{
return V_24 . V_55 & V_56 ;
}
static inline bool F_46 ( void )
{
return V_24 . V_29 &
V_57 ;
}
static inline bool F_47 ( void )
{
return V_51 ;
}
static inline bool F_48 ( struct V_7 * V_7 , T_2 V_58 )
{
return V_7 -> V_59 & V_58 ;
}
static inline bool F_49 ( struct V_7 * V_7 , T_2 V_58 )
{
return ( V_7 -> V_59 &
V_28 ) &&
( V_7 -> V_60 & V_58 ) ;
}
static inline bool F_50 ( struct V_7 * V_7 ,
struct V_2 * V_3 )
{
return V_7 -> V_61 & V_56 ;
}
static inline bool F_51 ( T_2 V_14 )
{
return ( V_14 & ( V_15 | V_17 ) )
== ( V_18 | V_17 ) ;
}
static int F_52 ( struct V_1 * V_62 , T_2 V_63 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_62 -> V_65 ; ++ V_64 )
if ( V_66 [ V_62 -> V_67 [ V_64 ] . V_68 ] == V_63 )
return V_64 ;
return - 1 ;
}
static inline void F_53 ( int V_69 , T_3 V_45 , T_4 V_70 )
{
struct {
T_5 V_45 : 16 ;
T_5 V_71 : 48 ;
T_5 V_70 ;
} V_72 = { V_45 , 0 , V_70 } ;
asm volatile (__ex(ASM_VMX_INVVPID)
"; ja 1f ; ud2 ; 1:"
: : "a"(&operand), "c"(ext) : "cc", "memory");
}
static inline void F_54 ( int V_69 , T_5 V_73 , T_1 V_74 )
{
struct {
T_5 V_73 , V_74 ;
} V_72 = { V_73 , V_74 } ;
asm volatile (__ex(ASM_VMX_INVEPT)
"; ja 1f ; ud2 ; 1:\n"
: : "a" (&operand), "c" (ext) : "cc", "memory");
}
static struct V_75 * F_55 ( struct V_1 * V_62 , T_2 V_63 )
{
int V_64 ;
V_64 = F_52 ( V_62 , V_63 ) ;
if ( V_64 >= 0 )
return & V_62 -> V_67 [ V_64 ] ;
return NULL ;
}
static void F_56 ( struct V_76 * V_76 )
{
T_5 V_77 = F_57 ( V_76 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMCLEAR_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_58 ( V_78 L_1 ,
V_76 , V_77 ) ;
}
static inline void F_59 ( struct V_79 * V_79 )
{
F_56 ( V_79 -> V_76 ) ;
V_79 -> V_80 = - 1 ;
V_79 -> V_81 = 0 ;
}
static void F_60 ( struct V_76 * V_76 )
{
T_5 V_77 = F_57 ( V_76 ) ;
T_6 error ;
asm volatile (__ex(ASM_VMX_VMPTRLD_RAX) "; setna %0"
: "=qm"(error) : "a"(&phys_addr), "m"(phys_addr)
: "cc", "memory");
if ( error )
F_58 ( V_78 L_2 ,
V_76 , V_77 ) ;
}
static inline void F_61 ( int V_80 )
{
F_62 ( V_80 , & V_82 ) ;
}
static inline void F_63 ( int V_80 )
{
F_64 ( V_80 , & V_82 ) ;
}
static inline int F_65 ( int V_80 )
{
return F_66 ( V_80 , & V_82 ) ;
}
static void F_67 ( void )
{
int V_80 = F_68 () ;
struct V_79 * V_83 ;
if ( ! F_65 ( V_80 ) )
return;
F_69 (v, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_56 ( V_83 -> V_76 ) ;
}
static inline void F_61 ( int V_80 ) { }
static inline void F_63 ( int V_80 ) { }
static void F_70 ( void * V_84 )
{
struct V_79 * V_79 = V_84 ;
int V_80 = F_68 () ;
if ( V_79 -> V_80 != V_80 )
return;
if ( F_71 ( V_85 , V_80 ) == V_79 -> V_76 )
F_71 ( V_85 , V_80 ) = NULL ;
F_63 ( V_80 ) ;
F_72 ( & V_79 -> V_86 ) ;
F_73 () ;
F_59 ( V_79 ) ;
F_61 ( V_80 ) ;
}
static void F_74 ( struct V_79 * V_79 )
{
int V_80 = V_79 -> V_80 ;
if ( V_80 != - 1 )
F_75 ( V_80 ,
F_70 , V_79 , 1 ) ;
}
static inline void F_76 ( struct V_1 * V_62 )
{
if ( V_62 -> V_45 == 0 )
return;
if ( F_36 () )
F_53 ( V_87 , V_62 -> V_45 , 0 ) ;
}
static inline void F_77 ( void )
{
if ( F_37 () )
F_53 ( V_88 , 0 , 0 ) ;
}
static inline void F_78 ( struct V_1 * V_62 )
{
if ( F_36 () )
F_76 ( V_62 ) ;
else
F_77 () ;
}
static inline void F_79 ( void )
{
if ( F_35 () )
F_54 ( V_89 , 0 , 0 ) ;
}
static inline void F_80 ( T_5 V_73 )
{
if ( V_90 ) {
if ( F_34 () )
F_54 ( V_91 , V_73 , 0 ) ;
else
F_79 () ;
}
}
static T_7 unsigned long F_81 ( unsigned long V_4 )
{
unsigned long V_92 ;
asm volatile (__ex_clear(ASM_VMX_VMREAD_RDX_RAX, "%0")
: "=a"(value) : "d"(field) : "cc");
return V_92 ;
}
static T_7 T_3 F_82 ( unsigned long V_4 )
{
return F_81 ( V_4 ) ;
}
static T_7 T_2 F_83 ( unsigned long V_4 )
{
return F_81 ( V_4 ) ;
}
static T_7 T_5 F_84 ( unsigned long V_4 )
{
#ifdef F_85
return F_81 ( V_4 ) ;
#else
return F_81 ( V_4 ) | ( ( T_5 ) F_81 ( V_4 + 1 ) << 32 ) ;
#endif
}
static T_8 void F_86 ( unsigned long V_4 , unsigned long V_92 )
{
F_58 ( V_78 L_3 ,
V_4 , V_92 , F_83 ( V_93 ) ) ;
F_87 () ;
}
static void F_88 ( unsigned long V_4 , unsigned long V_92 )
{
T_6 error ;
asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
: "=q"(error) : "a"(value), "d"(field) : "cc");
if ( F_89 ( error ) )
F_86 ( V_4 , V_92 ) ;
}
static void F_90 ( unsigned long V_4 , T_3 V_92 )
{
F_88 ( V_4 , V_92 ) ;
}
static void F_91 ( unsigned long V_4 , T_2 V_92 )
{
F_88 ( V_4 , V_92 ) ;
}
static void F_92 ( unsigned long V_4 , T_5 V_92 )
{
F_88 ( V_4 , V_92 ) ;
#ifndef F_85
asm volatile ("");
F_88 ( V_4 + 1 , V_92 >> 32 ) ;
#endif
}
static void F_93 ( unsigned long V_4 , T_2 V_94 )
{
F_88 ( V_4 , F_81 ( V_4 ) & ~ V_94 ) ;
}
static void F_94 ( unsigned long V_4 , T_2 V_94 )
{
F_88 ( V_4 , F_81 ( V_4 ) | V_94 ) ;
}
static void F_95 ( struct V_1 * V_62 )
{
V_62 -> V_95 . V_96 = 0 ;
}
static bool F_96 ( struct V_1 * V_62 , unsigned V_97 ,
unsigned V_4 )
{
bool V_98 ;
T_2 V_94 = 1 << ( V_97 * V_99 + V_4 ) ;
if ( ! ( V_62 -> V_3 . V_100 . V_101 & ( 1 << V_102 ) ) ) {
V_62 -> V_3 . V_100 . V_101 |= ( 1 << V_102 ) ;
V_62 -> V_95 . V_96 = 0 ;
}
V_98 = V_62 -> V_95 . V_96 & V_94 ;
V_62 -> V_95 . V_96 |= V_94 ;
return V_98 ;
}
static T_3 F_97 ( struct V_1 * V_62 , unsigned V_97 )
{
T_3 * V_103 = & V_62 -> V_95 . V_97 [ V_97 ] . V_104 ;
if ( ! F_96 ( V_62 , V_97 , V_105 ) )
* V_103 = F_82 ( V_106 [ V_97 ] . V_104 ) ;
return * V_103 ;
}
static T_9 F_98 ( struct V_1 * V_62 , unsigned V_97 )
{
T_9 * V_103 = & V_62 -> V_95 . V_97 [ V_97 ] . V_107 ;
if ( ! F_96 ( V_62 , V_97 , V_108 ) )
* V_103 = F_81 ( V_106 [ V_97 ] . V_107 ) ;
return * V_103 ;
}
static T_2 F_99 ( struct V_1 * V_62 , unsigned V_97 )
{
T_2 * V_103 = & V_62 -> V_95 . V_97 [ V_97 ] . V_109 ;
if ( ! F_96 ( V_62 , V_97 , V_110 ) )
* V_103 = F_83 ( V_106 [ V_97 ] . V_109 ) ;
return * V_103 ;
}
static T_2 F_100 ( struct V_1 * V_62 , unsigned V_97 )
{
T_2 * V_103 = & V_62 -> V_95 . V_97 [ V_97 ] . V_111 ;
if ( ! F_96 ( V_62 , V_97 , V_112 ) )
* V_103 = F_83 ( V_106 [ V_97 ] . V_113 ) ;
return * V_103 ;
}
static void F_101 ( struct V_2 * V_3 )
{
T_2 V_114 ;
V_114 = ( 1u << V_19 ) | ( 1u << V_21 ) | ( 1u << V_23 ) |
( 1u << V_20 ) | ( 1u << V_115 ) ;
if ( ( V_3 -> V_116 &
( V_117 | V_118 ) ) ==
( V_117 | V_118 ) )
V_114 |= 1u << V_119 ;
if ( F_1 ( V_3 ) -> V_120 . V_121 )
V_114 = ~ 0 ;
if ( V_90 )
V_114 &= ~ ( 1u << V_19 ) ;
if ( V_3 -> V_122 )
V_114 &= ~ ( 1u << V_20 ) ;
if ( F_102 ( V_3 ) )
V_114 |= F_4 ( V_3 ) -> V_123 ;
F_91 ( V_124 , V_114 ) ;
}
static void F_103 ( unsigned long V_125 ,
unsigned long exit )
{
F_93 ( V_126 , V_125 ) ;
F_93 ( V_127 , exit ) ;
}
static void F_104 ( struct V_1 * V_62 , unsigned V_63 )
{
unsigned V_64 ;
struct V_128 * V_129 = & V_62 -> V_128 ;
switch ( V_63 ) {
case V_130 :
if ( V_131 ) {
F_103 ( V_132 ,
V_133 ) ;
return;
}
break;
case V_134 :
if ( V_135 ) {
F_103 (
V_136 ,
V_137 ) ;
return;
}
break;
}
for ( V_64 = 0 ; V_64 < V_129 -> V_138 ; ++ V_64 )
if ( V_129 -> V_139 [ V_64 ] . V_68 == V_63 )
break;
if ( V_64 == V_129 -> V_138 )
return;
-- V_129 -> V_138 ;
V_129 -> V_139 [ V_64 ] = V_129 -> V_139 [ V_129 -> V_138 ] ;
V_129 -> V_140 [ V_64 ] = V_129 -> V_140 [ V_129 -> V_138 ] ;
F_91 ( V_141 , V_129 -> V_138 ) ;
F_91 ( V_142 , V_129 -> V_138 ) ;
}
static void F_105 ( unsigned long V_125 ,
unsigned long exit , unsigned long V_143 ,
unsigned long V_144 , T_5 V_145 , T_5 V_146 )
{
F_92 ( V_143 , V_145 ) ;
F_92 ( V_144 , V_146 ) ;
F_94 ( V_126 , V_125 ) ;
F_94 ( V_127 , exit ) ;
}
static void F_106 ( struct V_1 * V_62 , unsigned V_63 ,
T_5 V_145 , T_5 V_146 )
{
unsigned V_64 ;
struct V_128 * V_129 = & V_62 -> V_128 ;
switch ( V_63 ) {
case V_130 :
if ( V_131 ) {
F_105 ( V_132 ,
V_133 ,
V_147 ,
V_148 ,
V_145 , V_146 ) ;
return;
}
break;
case V_134 :
if ( V_135 ) {
F_105 (
V_136 ,
V_137 ,
V_149 ,
V_150 ,
V_145 , V_146 ) ;
return;
}
break;
}
for ( V_64 = 0 ; V_64 < V_129 -> V_138 ; ++ V_64 )
if ( V_129 -> V_139 [ V_64 ] . V_68 == V_63 )
break;
if ( V_64 == V_151 ) {
F_107 ( V_152 L_4
L_5 , V_63 ) ;
return;
} else if ( V_64 == V_129 -> V_138 ) {
++ V_129 -> V_138 ;
F_91 ( V_141 , V_129 -> V_138 ) ;
F_91 ( V_142 , V_129 -> V_138 ) ;
}
V_129 -> V_139 [ V_64 ] . V_68 = V_63 ;
V_129 -> V_139 [ V_64 ] . V_92 = V_145 ;
V_129 -> V_140 [ V_64 ] . V_68 = V_63 ;
V_129 -> V_140 [ V_64 ] . V_92 = V_146 ;
}
static void F_108 ( void )
{
struct V_153 * V_154 = & F_109 ( V_155 ) ;
struct V_156 * V_157 ;
V_157 = ( void * ) V_154 -> V_158 ;
V_157 [ V_159 ] . type = 9 ;
F_110 () ;
}
static bool F_111 ( struct V_1 * V_62 , int V_160 )
{
T_5 V_161 ;
T_5 V_162 ;
V_161 = V_62 -> V_3 . V_100 . V_163 ;
V_162 = V_164 | V_165 ;
#ifdef F_85
V_162 |= V_166 | V_167 ;
if ( V_161 & V_166 )
V_162 &= ~ ( T_5 ) V_165 ;
#endif
V_161 &= ~ V_162 ;
V_161 |= V_168 & V_162 ;
V_62 -> V_67 [ V_160 ] . V_169 = V_161 ;
V_62 -> V_67 [ V_160 ] . V_94 = ~ V_162 ;
F_104 ( V_62 , V_130 ) ;
if ( V_90 && ( ( V_62 -> V_3 . V_100 . V_163 ^ V_168 ) & V_164 ) ) {
V_161 = V_62 -> V_3 . V_100 . V_163 ;
if ( ! ( V_161 & V_166 ) )
V_161 &= ~ V_167 ;
F_106 ( V_62 , V_130 , V_161 , V_168 ) ;
return false ;
}
return true ;
}
static unsigned long F_112 ( T_3 V_104 )
{
struct V_153 * V_154 = & F_109 ( V_155 ) ;
struct V_156 * V_170 ;
unsigned long V_171 ;
unsigned long V_83 ;
if ( ! ( V_104 & ~ 3 ) )
return 0 ;
V_171 = V_154 -> V_158 ;
if ( V_104 & 4 ) {
T_3 V_172 = F_113 () ;
if ( ! ( V_172 & ~ 3 ) )
return 0 ;
V_171 = F_112 ( V_172 ) ;
}
V_170 = (struct V_156 * ) ( V_171 + ( V_104 & ~ 7 ) ) ;
V_83 = F_114 ( V_170 ) ;
#ifdef F_85
if ( V_170 -> V_173 == 0 && ( V_170 -> type == 2 || V_170 -> type == 9 || V_170 -> type == 11 ) )
V_83 |= ( ( unsigned long ) ( (struct V_174 * ) V_170 ) -> V_175 ) << 32 ;
#endif
return V_83 ;
}
static inline unsigned long F_115 ( void )
{
T_3 V_176 ;
asm("str %0" : "=g"(tr));
return F_112 ( V_176 ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
int V_64 ;
if ( V_62 -> V_177 . V_178 )
return;
V_62 -> V_177 . V_178 = 1 ;
V_62 -> V_177 . V_179 = F_113 () ;
V_62 -> V_177 . V_180 = V_62 -> V_177 . V_179 ;
F_117 ( V_181 , V_62 -> V_177 . V_182 ) ;
if ( ! ( V_62 -> V_177 . V_182 & 7 ) ) {
F_90 ( V_183 , V_62 -> V_177 . V_182 ) ;
V_62 -> V_177 . V_184 = 0 ;
} else {
F_90 ( V_183 , 0 ) ;
V_62 -> V_177 . V_184 = 1 ;
}
F_117 ( V_185 , V_62 -> V_177 . V_186 ) ;
if ( ! ( V_62 -> V_177 . V_186 & 7 ) )
F_90 ( V_187 , V_62 -> V_177 . V_186 ) ;
else {
F_90 ( V_187 , 0 ) ;
V_62 -> V_177 . V_180 = 1 ;
}
#ifdef F_85
F_117 ( V_188 , V_62 -> V_177 . V_189 ) ;
F_117 ( V_190 , V_62 -> V_177 . V_191 ) ;
#endif
#ifdef F_85
F_88 ( V_192 , F_118 ( V_193 ) ) ;
F_88 ( V_194 , F_118 ( V_195 ) ) ;
#else
F_88 ( V_192 , F_112 ( V_62 -> V_177 . V_182 ) ) ;
F_88 ( V_194 , F_112 ( V_62 -> V_177 . V_186 ) ) ;
#endif
#ifdef F_85
F_119 ( V_196 , V_62 -> V_197 ) ;
if ( F_120 ( & V_62 -> V_3 ) )
F_121 ( V_196 , V_62 -> V_198 ) ;
#endif
for ( V_64 = 0 ; V_64 < V_62 -> V_199 ; ++ V_64 )
F_122 ( V_62 -> V_67 [ V_64 ] . V_68 ,
V_62 -> V_67 [ V_64 ] . V_169 ,
V_62 -> V_67 [ V_64 ] . V_94 ) ;
}
static void F_123 ( struct V_1 * V_62 )
{
if ( ! V_62 -> V_177 . V_178 )
return;
++ V_62 -> V_3 . V_200 . V_201 ;
V_62 -> V_177 . V_178 = 0 ;
#ifdef F_85
if ( F_120 ( & V_62 -> V_3 ) )
F_119 ( V_196 , V_62 -> V_198 ) ;
#endif
if ( V_62 -> V_177 . V_180 ) {
F_124 ( V_62 -> V_177 . V_179 ) ;
#ifdef F_85
F_125 ( V_62 -> V_177 . V_186 ) ;
#else
F_126 ( V_185 , V_62 -> V_177 . V_186 ) ;
#endif
}
if ( V_62 -> V_177 . V_184 )
F_126 ( V_181 , V_62 -> V_177 . V_182 ) ;
#ifdef F_85
if ( F_89 ( V_62 -> V_177 . V_189 | V_62 -> V_177 . V_191 ) ) {
F_126 ( V_188 , V_62 -> V_177 . V_189 ) ;
F_126 ( V_190 , V_62 -> V_177 . V_191 ) ;
}
#endif
F_108 () ;
#ifdef F_85
F_121 ( V_196 , V_62 -> V_197 ) ;
#endif
if ( ! F_127 () && ! V_62 -> V_3 . V_202 )
F_128 () ;
F_129 ( & F_109 ( V_155 ) ) ;
}
static void F_130 ( struct V_1 * V_62 )
{
F_131 () ;
F_123 ( V_62 ) ;
F_132 () ;
}
static void F_133 ( struct V_2 * V_3 , int V_80 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_5 V_77 = F_57 ( F_71 ( V_203 , V_80 ) ) ;
if ( ! V_204 )
F_134 ( V_77 ) ;
else if ( V_62 -> V_79 -> V_80 != V_80 )
F_74 ( V_62 -> V_79 ) ;
if ( F_71 ( V_85 , V_80 ) != V_62 -> V_79 -> V_76 ) {
F_71 ( V_85 , V_80 ) = V_62 -> V_79 -> V_76 ;
F_60 ( V_62 -> V_79 -> V_76 ) ;
}
if ( V_62 -> V_79 -> V_80 != V_80 ) {
struct V_153 * V_154 = & F_109 ( V_155 ) ;
unsigned long V_205 ;
F_135 ( V_206 , V_3 ) ;
F_136 () ;
F_63 ( V_80 ) ;
F_137 () ;
F_138 ( & V_62 -> V_79 -> V_86 ,
& F_71 ( V_207 , V_80 ) ) ;
F_61 ( V_80 ) ;
F_139 () ;
F_88 ( V_208 , F_115 () ) ;
F_88 ( V_209 , V_154 -> V_158 ) ;
F_119 ( V_210 , V_205 ) ;
F_88 ( V_211 , V_205 ) ;
V_62 -> V_79 -> V_80 = V_80 ;
}
}
static void F_140 ( struct V_2 * V_3 )
{
F_123 ( F_1 ( V_3 ) ) ;
if ( ! V_204 ) {
F_70 ( F_1 ( V_3 ) -> V_79 ) ;
V_3 -> V_80 = - 1 ;
F_141 () ;
}
}
static void F_142 ( struct V_2 * V_3 )
{
T_9 V_212 ;
if ( V_3 -> V_122 )
return;
V_3 -> V_122 = 1 ;
V_212 = F_81 ( V_213 ) ;
V_212 &= ~ ( V_214 | V_215 ) ;
V_212 |= F_143 ( V_3 , V_214 | V_215 ) ;
F_88 ( V_213 , V_212 ) ;
F_101 ( V_3 ) ;
V_3 -> V_100 . V_216 = V_214 ;
if ( F_102 ( V_3 ) )
V_3 -> V_100 . V_216 &=
~ F_4 ( V_3 ) -> V_217 ;
F_88 ( V_218 , ~ V_3 -> V_100 . V_216 ) ;
}
static inline unsigned long F_144 ( struct V_7 * V_219 )
{
return ( V_219 -> V_220 & ~ V_219 -> V_217 ) |
( V_219 -> V_221 & V_219 -> V_217 ) ;
}
static inline unsigned long F_145 ( struct V_7 * V_219 )
{
return ( V_219 -> V_222 & ~ V_219 -> V_223 ) |
( V_219 -> V_224 & V_219 -> V_223 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
F_147 ( V_3 ) ;
F_94 ( V_213 , V_214 | V_215 ) ;
F_101 ( V_3 ) ;
V_3 -> V_100 . V_216 = 0 ;
F_88 ( V_218 , ~ V_3 -> V_100 . V_216 ) ;
if ( F_102 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_220 = ( V_7 -> V_220 & ~ V_214 ) |
( V_3 -> V_100 . V_212 & V_214 ) ;
F_88 ( V_225 , F_144 ( V_7 ) ) ;
} else
F_88 ( V_225 , V_3 -> V_100 . V_212 ) ;
}
static unsigned long F_148 ( struct V_2 * V_3 )
{
unsigned long V_226 , V_227 ;
if ( ! F_149 ( V_228 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ) {
F_150 ( V_228 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ;
V_226 = F_81 ( V_229 ) ;
if ( F_1 ( V_3 ) -> V_120 . V_121 ) {
V_226 &= V_230 ;
V_227 = F_1 ( V_3 ) -> V_120 . V_227 ;
V_226 |= V_227 & ~ V_230 ;
}
F_1 ( V_3 ) -> V_226 = V_226 ;
}
return F_1 ( V_3 ) -> V_226 ;
}
static void F_151 ( struct V_2 * V_3 , unsigned long V_226 )
{
F_150 ( V_228 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ;
F_1 ( V_3 ) -> V_226 = V_226 ;
if ( F_1 ( V_3 ) -> V_120 . V_121 ) {
F_1 ( V_3 ) -> V_120 . V_227 = V_226 ;
V_226 |= V_231 | V_232 ;
}
F_88 ( V_229 , V_226 ) ;
}
static T_2 F_152 ( struct V_2 * V_3 , int V_94 )
{
T_2 V_233 = F_83 ( V_234 ) ;
int V_98 = 0 ;
if ( V_233 & V_235 )
V_98 |= V_236 ;
if ( V_233 & V_237 )
V_98 |= V_238 ;
return V_98 & V_94 ;
}
static void F_153 ( struct V_2 * V_3 , int V_94 )
{
T_2 V_239 = F_83 ( V_234 ) ;
T_2 V_233 = V_239 ;
V_233 &= ~ ( V_235 | V_237 ) ;
if ( V_94 & V_238 )
V_233 |= V_237 ;
else if ( V_94 & V_236 )
V_233 |= V_235 ;
if ( ( V_233 != V_239 ) )
F_91 ( V_234 , V_233 ) ;
}
static void F_154 ( struct V_2 * V_3 )
{
unsigned long V_240 ;
V_240 = F_155 ( V_3 ) ;
V_240 += F_83 ( V_241 ) ;
F_156 ( V_3 , V_240 ) ;
F_153 ( V_3 , 0 ) ;
}
static int F_157 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( ! ( V_7 -> V_123 & ( 1u << V_19 ) ) )
return 0 ;
F_158 ( V_3 ) ;
return 1 ;
}
static void F_159 ( struct V_2 * V_3 , unsigned V_138 ,
bool V_242 , T_2 V_243 ,
bool V_244 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_2 V_14 = V_138 | V_17 ;
if ( V_138 == V_19 && F_102 ( V_3 ) &&
F_157 ( V_3 ) )
return;
if ( V_242 ) {
F_91 ( V_245 , V_243 ) ;
V_14 |= V_246 ;
}
if ( V_62 -> V_120 . V_121 ) {
int V_247 = 0 ;
if ( F_160 ( V_138 ) )
V_247 = V_3 -> V_100 . V_248 ;
if ( F_161 ( V_3 , V_138 , V_247 ) != V_249 )
F_135 ( V_250 , V_3 ) ;
return;
}
if ( F_160 ( V_138 ) ) {
F_91 ( V_251 ,
V_62 -> V_3 . V_100 . V_248 ) ;
V_14 |= V_252 ;
} else
V_14 |= V_18 ;
F_91 ( V_253 , V_14 ) ;
}
static bool F_162 ( void )
{
return F_43 () ;
}
static bool F_163 ( void )
{
return F_44 () && V_90 ;
}
static void F_164 ( struct V_1 * V_62 , int V_254 , int V_255 )
{
struct V_75 V_256 ;
V_256 = V_62 -> V_67 [ V_255 ] ;
V_62 -> V_67 [ V_255 ] = V_62 -> V_67 [ V_254 ] ;
V_62 -> V_67 [ V_254 ] = V_256 ;
}
static void F_165 ( struct V_2 * V_3 )
{
unsigned long * V_257 ;
if ( F_20 ( V_3 -> V_12 ) && F_166 ( V_3 -> V_100 . V_258 ) ) {
if ( F_120 ( V_3 ) )
V_257 = V_259 ;
else
V_257 = V_260 ;
} else {
if ( F_120 ( V_3 ) )
V_257 = V_261 ;
else
V_257 = V_262 ;
}
F_92 ( V_263 , F_57 ( V_257 ) ) ;
}
static void F_167 ( struct V_1 * V_62 )
{
int V_199 , V_68 ;
V_199 = 0 ;
#ifdef F_85
if ( F_120 ( & V_62 -> V_3 ) ) {
V_68 = F_52 ( V_62 , V_264 ) ;
if ( V_68 >= 0 )
F_164 ( V_62 , V_68 , V_199 ++ ) ;
V_68 = F_52 ( V_62 , V_265 ) ;
if ( V_68 >= 0 )
F_164 ( V_62 , V_68 , V_199 ++ ) ;
V_68 = F_52 ( V_62 , V_266 ) ;
if ( V_68 >= 0 )
F_164 ( V_62 , V_68 , V_199 ++ ) ;
V_68 = F_52 ( V_62 , V_267 ) ;
if ( V_68 >= 0 && V_62 -> V_268 )
F_164 ( V_62 , V_68 , V_199 ++ ) ;
V_68 = F_52 ( V_62 , V_269 ) ;
if ( ( V_68 >= 0 ) && ( V_62 -> V_3 . V_100 . V_163 & V_165 ) )
F_164 ( V_62 , V_68 , V_199 ++ ) ;
}
#endif
V_68 = F_52 ( V_62 , V_130 ) ;
if ( V_68 >= 0 && F_111 ( V_62 , V_68 ) )
F_164 ( V_62 , V_68 , V_199 ++ ) ;
V_62 -> V_199 = V_199 ;
if ( F_17 () )
F_165 ( & V_62 -> V_3 ) ;
}
static T_5 F_168 ( void )
{
T_5 V_270 , V_271 ;
F_169 ( V_270 ) ;
V_271 = F_84 ( V_272 ) ;
return V_270 + V_271 ;
}
T_5 F_170 ( struct V_2 * V_3 , T_5 V_270 )
{
T_5 V_271 ;
V_271 = F_102 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_273 :
F_84 ( V_272 ) ;
return V_270 + V_271 ;
}
static void F_171 ( struct V_2 * V_3 , T_2 V_274 , bool V_275 )
{
if ( ! V_275 )
return;
if ( V_274 > V_276 ) {
V_3 -> V_100 . V_277 = 1 ;
V_3 -> V_100 . V_278 = 1 ;
} else
F_172 ( 1 , L_6 ) ;
}
static T_5 F_173 ( struct V_2 * V_3 )
{
return F_84 ( V_272 ) ;
}
static void F_174 ( struct V_2 * V_3 , T_5 V_279 )
{
if ( F_102 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_273 = V_279 ;
V_7 = F_4 ( V_3 ) ;
F_92 ( V_272 , V_279 +
( F_48 ( V_7 , V_280 ) ?
V_7 -> V_271 : 0 ) ) ;
} else {
F_92 ( V_272 , V_279 ) ;
}
}
static void F_175 ( struct V_2 * V_3 , T_10 V_281 , bool V_140 )
{
T_5 V_279 = F_84 ( V_272 ) ;
F_92 ( V_272 , V_279 + V_281 ) ;
if ( F_102 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_273 += V_281 ;
}
}
static T_5 F_176 ( struct V_2 * V_3 , T_5 V_282 )
{
return V_282 - F_177 () ;
}
static bool F_178 ( struct V_2 * V_3 )
{
struct V_283 * V_284 = F_179 ( V_3 , 1 , 0 ) ;
return V_284 && ( V_284 -> V_285 & ( 1 << ( V_286 & 31 ) ) ) ;
}
static inline bool F_180 ( struct V_2 * V_3 )
{
return V_8 && F_178 ( V_3 ) ;
}
static T_11 void F_181 ( void )
{
V_287 = 0x16 ;
V_288 = 0x16 |
V_289 | V_290 |
V_56 ;
V_291 = 0 ;
#ifdef F_85
V_292 = V_293 ;
#else
V_292 = 0 ;
#endif
F_182 ( V_294 ,
V_295 , V_296 ) ;
V_295 = 0 ;
V_296 &=
V_297 | V_298 ;
F_182 ( V_299 ,
V_300 , V_301 ) ;
V_300 = 0 ;
V_301 &=
V_302 | V_280 |
V_303 | V_304 |
V_305 | V_306 |
V_307 |
#ifdef F_85
V_308 | V_309 |
#endif
V_310 | V_311 |
V_312 | V_313 |
V_314 | V_315 |
V_28 ;
V_301 |= V_26 ;
F_182 ( V_316 ,
V_317 , V_318 ) ;
V_317 = 0 ;
V_318 &=
V_30 ;
}
static inline bool F_183 ( T_2 V_319 , T_2 V_320 , T_2 V_321 )
{
return ( ( V_319 & V_321 ) | V_320 ) == V_319 ;
}
static inline T_5 F_184 ( T_2 V_320 , T_2 V_321 )
{
return V_320 | ( ( T_5 ) V_321 << 32 ) ;
}
static int F_185 ( struct V_2 * V_3 , T_2 V_322 , T_5 * V_323 )
{
if ( ! F_180 ( V_3 ) && V_322 >= V_324 &&
V_322 <= V_325 ) {
F_186 ( V_3 , V_326 , 0 ) ;
return 1 ;
}
switch ( V_322 ) {
case V_327 :
* V_323 = 0 ;
break;
case V_324 :
* V_323 = V_328 |
( ( T_5 ) V_329 << V_330 ) |
( V_331 << V_332 ) ;
break;
case V_333 :
case V_334 :
* V_323 = F_184 ( V_287 ,
V_288 ) ;
break;
case V_335 :
case V_299 :
* V_323 = F_184 ( V_300 ,
V_301 ) ;
break;
case V_336 :
case V_337 :
* V_323 = F_184 ( V_291 ,
V_292 ) ;
break;
case V_325 :
case V_294 :
* V_323 = F_184 ( V_295 ,
V_296 ) ;
break;
case V_338 :
* V_323 = 0 ;
break;
#define F_187 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_188 X86_CR4_VMXE
case V_339 :
* V_323 = F_187 ;
break;
case V_340 :
* V_323 = - 1ULL ;
break;
case V_341 :
* V_323 = F_188 ;
break;
case V_342 :
* V_323 = - 1ULL ;
break;
case V_343 :
* V_323 = 0x1f ;
break;
case V_316 :
* V_323 = F_184 ( V_317 ,
V_318 ) ;
break;
case V_344 :
* V_323 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_189 ( struct V_2 * V_3 , T_2 V_322 , T_5 V_169 )
{
if ( ! F_180 ( V_3 ) )
return 0 ;
if ( V_322 == V_327 )
return 1 ;
return 0 ;
}
static int F_190 ( struct V_2 * V_3 , T_2 V_322 , T_5 * V_323 )
{
T_5 V_169 ;
struct V_75 * V_63 ;
if ( ! V_323 ) {
F_58 ( V_78 L_7 ) ;
return - V_345 ;
}
switch ( V_322 ) {
#ifdef F_85
case V_193 :
V_169 = F_81 ( V_346 ) ;
break;
case V_195 :
V_169 = F_81 ( V_347 ) ;
break;
case V_196 :
F_130 ( F_1 ( V_3 ) ) ;
V_169 = F_1 ( V_3 ) -> V_198 ;
break;
#endif
case V_130 :
return F_191 ( V_3 , V_322 , V_323 ) ;
case V_348 :
V_169 = F_168 () ;
break;
case V_349 :
V_169 = F_83 ( V_350 ) ;
break;
case V_351 :
V_169 = F_81 ( V_352 ) ;
break;
case V_210 :
V_169 = F_81 ( V_353 ) ;
break;
case V_267 :
if ( ! F_1 ( V_3 ) -> V_268 )
return 1 ;
default:
if ( F_185 ( V_3 , V_322 , V_323 ) )
return 0 ;
V_63 = F_55 ( F_1 ( V_3 ) , V_322 ) ;
if ( V_63 ) {
V_169 = V_63 -> V_169 ;
break;
}
return F_191 ( V_3 , V_322 , V_323 ) ;
}
* V_323 = V_169 ;
return 0 ;
}
static int F_192 ( struct V_2 * V_3 , struct V_354 * V_355 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_75 * V_63 ;
int V_98 = 0 ;
T_2 V_322 = V_355 -> V_68 ;
T_5 V_169 = V_355 -> V_169 ;
switch ( V_322 ) {
case V_130 :
V_98 = F_193 ( V_3 , V_355 ) ;
break;
#ifdef F_85
case V_193 :
F_95 ( V_62 ) ;
F_88 ( V_346 , V_169 ) ;
break;
case V_195 :
F_95 ( V_62 ) ;
F_88 ( V_347 , V_169 ) ;
break;
case V_196 :
F_130 ( V_62 ) ;
V_62 -> V_198 = V_169 ;
break;
#endif
case V_349 :
F_91 ( V_350 , V_169 ) ;
break;
case V_351 :
F_88 ( V_352 , V_169 ) ;
break;
case V_210 :
F_88 ( V_353 , V_169 ) ;
break;
case V_348 :
F_194 ( V_3 , V_355 ) ;
break;
case V_356 :
if ( V_24 . V_357 & V_297 ) {
F_92 ( V_358 , V_169 ) ;
V_3 -> V_100 . V_359 = V_169 ;
break;
}
V_98 = F_193 ( V_3 , V_355 ) ;
break;
case V_360 :
V_98 = F_193 ( V_3 , V_355 ) ;
break;
case V_267 :
if ( ! V_62 -> V_268 )
return 1 ;
if ( ( V_169 >> 32 ) != 0 )
return 1 ;
default:
if ( F_189 ( V_3 , V_322 , V_169 ) )
break;
V_63 = F_55 ( V_62 , V_322 ) ;
if ( V_63 ) {
V_63 -> V_169 = V_169 ;
if ( V_63 - V_62 -> V_67 < V_62 -> V_199 ) {
F_131 () ;
F_122 ( V_63 -> V_68 , V_63 -> V_169 ,
V_63 -> V_94 ) ;
F_132 () ;
}
break;
}
V_98 = F_193 ( V_3 , V_355 ) ;
}
return V_98 ;
}
static void F_195 ( struct V_2 * V_3 , enum V_361 V_362 )
{
F_150 ( V_362 , ( unsigned long * ) & V_3 -> V_100 . V_101 ) ;
switch ( V_362 ) {
case V_363 :
V_3 -> V_100 . V_364 [ V_363 ] = F_81 ( V_365 ) ;
break;
case V_366 :
V_3 -> V_100 . V_364 [ V_366 ] = F_81 ( V_367 ) ;
break;
case V_368 :
if ( V_90 )
F_196 ( V_3 ) ;
break;
default:
break;
}
}
static T_11 int F_197 ( void )
{
return F_198 () ;
}
static T_11 int F_199 ( void )
{
T_5 V_63 ;
F_119 ( V_327 , V_63 ) ;
if ( V_63 & V_369 ) {
if ( ! ( V_63 & V_370 )
&& F_200 () )
return 1 ;
if ( ! ( V_63 & V_371 )
&& ( V_63 & V_370 )
&& ! F_200 () ) {
F_58 ( V_152 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_63 & V_371 )
&& ! F_200 () )
return 1 ;
}
return 0 ;
}
static void F_134 ( T_5 V_11 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_201 ( void * V_372 )
{
int V_80 = F_68 () ;
T_5 V_77 = F_57 ( F_71 ( V_203 , V_80 ) ) ;
T_5 V_373 , V_374 ;
if ( F_202 () & V_375 )
return - V_376 ;
F_203 ( & F_71 ( V_207 , V_80 ) ) ;
F_61 ( V_80 ) ;
F_119 ( V_327 , V_373 ) ;
V_374 = V_369 ;
V_374 |= V_371 ;
if ( F_200 () )
V_374 |= V_370 ;
if ( ( V_373 & V_374 ) != V_374 ) {
F_121 ( V_327 , V_373 | V_374 ) ;
}
F_204 ( F_202 () | V_375 ) ;
if ( V_204 ) {
F_134 ( V_77 ) ;
F_79 () ;
}
F_205 ( & F_109 ( V_155 ) ) ;
return 0 ;
}
static void F_206 ( void )
{
int V_80 = F_68 () ;
struct V_79 * V_83 , * V_377 ;
F_207 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_70 ( V_83 ) ;
}
static void F_141 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_208 ( void * V_372 )
{
if ( V_204 ) {
F_206 () ;
F_141 () ;
}
F_204 ( F_202 () & ~ V_375 ) ;
}
static T_11 int F_209 ( T_2 V_378 , T_2 V_379 ,
T_2 V_63 , T_2 * V_380 )
{
T_2 V_381 , V_382 ;
T_2 V_383 = V_378 | V_379 ;
F_182 ( V_63 , V_381 , V_382 ) ;
V_383 &= V_382 ;
V_383 |= V_381 ;
if ( V_378 & ~ V_383 )
return - V_384 ;
* V_380 = V_383 ;
return 0 ;
}
static T_11 bool F_210 ( T_2 V_63 , T_2 V_383 )
{
T_2 V_381 , V_382 ;
F_182 ( V_63 , V_381 , V_382 ) ;
return V_382 & V_383 ;
}
static T_11 int F_211 ( struct V_24 * V_385 )
{
T_2 V_381 , V_382 ;
T_2 V_386 , V_387 , V_388 , V_389 ;
T_2 V_390 = 0 ;
T_2 V_391 = 0 ;
T_2 V_392 = 0 ;
T_2 V_393 = 0 ;
T_2 V_394 = 0 ;
V_386 = V_289 | V_290 ;
V_387 = V_56 ;
if ( F_209 ( V_386 , V_387 , V_334 ,
& V_390 ) < 0 )
return - V_384 ;
V_386 = V_303 |
#ifdef F_85
V_308 |
V_309 |
#endif
V_306 |
V_307 |
V_312 |
V_310 |
V_280 |
V_305 |
V_313 |
V_304 |
V_314 ;
V_387 = V_27 |
V_26 |
V_28 ;
if ( F_209 ( V_386 , V_387 , V_299 ,
& V_391 ) < 0 )
return - V_384 ;
#ifdef F_85
if ( ( V_391 & V_27 ) )
V_391 &= ~ V_308 &
~ V_309 ;
#endif
if ( V_391 & V_28 ) {
V_388 = 0 ;
V_389 = V_30 |
V_31 |
V_57 |
V_52 |
V_48 |
V_49 |
V_50 |
V_53 |
V_54 |
V_32 |
V_33 ;
if ( F_209 ( V_388 , V_389 ,
V_316 ,
& V_392 ) < 0 )
return - V_384 ;
}
#ifndef F_85
if ( ! ( V_392 &
V_30 ) )
V_391 &= ~ V_27 ;
#endif
if ( ! ( V_391 & V_27 ) )
V_392 &= ~ (
V_32 |
V_31 |
V_33 ) ;
if ( V_392 & V_48 ) {
V_391 &= ~ ( V_306 |
V_307 |
V_304 ) ;
F_182 ( V_344 ,
V_34 . V_35 , V_34 . V_45 ) ;
}
V_386 = 0 ;
#ifdef F_85
V_386 |= V_293 ;
#endif
V_387 = V_395 | V_396 ;
if ( F_209 ( V_386 , V_387 , V_337 ,
& V_393 ) < 0 )
return - V_384 ;
V_386 = 0 ;
V_387 = V_297 ;
if ( F_209 ( V_386 , V_387 , V_294 ,
& V_394 ) < 0 )
return - V_384 ;
F_182 ( V_324 , V_381 , V_382 ) ;
if ( ( V_382 & 0x1fff ) > V_397 )
return - V_384 ;
#ifdef F_85
if ( V_382 & ( 1u << 16 ) )
return - V_384 ;
#endif
if ( ( ( V_382 >> 18 ) & 15 ) != 6 )
return - V_384 ;
V_385 -> V_398 = V_382 & 0x1fff ;
V_385 -> V_399 = F_212 ( V_24 . V_398 ) ;
V_385 -> V_400 = V_381 ;
V_385 -> V_55 = V_390 ;
V_385 -> V_25 = V_391 ;
V_385 -> V_29 = V_392 ;
V_385 -> V_401 = V_393 ;
V_385 -> V_357 = V_394 ;
V_131 =
F_210 ( V_294 ,
V_132 )
&& F_210 ( V_337 ,
V_133 ) ;
V_135 =
F_210 ( V_294 ,
V_136 )
&& F_210 ( V_337 ,
V_137 ) ;
if ( V_135 && V_402 . V_403 == 0x6 ) {
switch ( V_402 . V_404 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_135 = false ;
F_107 ( V_152 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_76 * F_213 ( int V_80 )
{
int V_405 = F_214 ( V_80 ) ;
struct V_10 * V_406 ;
struct V_76 * V_76 ;
V_406 = F_215 ( V_405 , V_407 , V_24 . V_399 ) ;
if ( ! V_406 )
return NULL ;
V_76 = F_216 ( V_406 ) ;
memset ( V_76 , 0 , V_24 . V_398 ) ;
V_76 -> V_400 = V_24 . V_400 ;
return V_76 ;
}
static struct V_76 * F_217 ( void )
{
return F_213 ( F_68 () ) ;
}
static void F_218 ( struct V_76 * V_76 )
{
F_219 ( ( unsigned long ) V_76 , V_24 . V_399 ) ;
}
static void F_220 ( struct V_79 * V_79 )
{
if ( ! V_79 -> V_76 )
return;
F_74 ( V_79 ) ;
F_218 ( V_79 -> V_76 ) ;
V_79 -> V_76 = NULL ;
}
static void F_221 ( void )
{
int V_80 ;
F_222 (cpu) {
F_218 ( F_71 ( V_203 , V_80 ) ) ;
F_71 ( V_203 , V_80 ) = NULL ;
}
}
static T_11 int F_223 ( void )
{
int V_80 ;
F_222 (cpu) {
struct V_76 * V_76 ;
V_76 = F_213 ( V_80 ) ;
if ( ! V_76 ) {
F_221 () ;
return - V_408 ;
}
F_71 ( V_203 , V_80 ) = V_76 ;
}
return 0 ;
}
static T_11 int F_224 ( void )
{
if ( F_211 ( & V_24 ) < 0 )
return - V_384 ;
if ( F_225 ( V_409 ) )
F_226 ( V_164 ) ;
if ( ! F_42 () )
V_410 = 0 ;
if ( ! F_38 () ||
! F_32 () ) {
V_90 = 0 ;
V_411 = 0 ;
V_412 = 0 ;
}
if ( ! F_33 () )
V_412 = 0 ;
if ( ! F_39 () )
V_411 = 0 ;
if ( ! F_26 () )
V_51 = 0 ;
if ( ! F_18 () )
V_413 -> V_414 = NULL ;
if ( V_90 && ! F_30 () )
F_227 () ;
if ( ! F_40 () )
V_415 = 0 ;
if ( ! F_24 () ||
! F_25 () )
V_416 = 0 ;
if ( V_416 )
V_413 -> V_414 = NULL ;
else
V_413 -> V_417 = NULL ;
if ( V_8 )
F_181 () ;
return F_223 () ;
}
static T_12 void F_228 ( void )
{
F_221 () ;
}
static bool F_229 ( struct V_2 * V_3 )
{
return V_418 && ! F_230 ( V_3 ) ;
}
static void F_231 ( struct V_2 * V_3 , int V_97 ,
struct V_419 * V_420 )
{
if ( ! V_418 ) {
if ( V_97 == V_421 || V_97 == V_422 )
V_420 -> V_104 &= ~ V_423 ;
V_420 -> V_424 = V_420 -> V_104 & V_423 ;
V_420 -> V_173 = 1 ;
}
F_232 ( V_3 , V_420 , V_97 ) ;
}
static void F_233 ( struct V_2 * V_3 )
{
unsigned long V_425 ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_427 ] , V_427 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_428 ] , V_428 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_429 ] , V_429 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_430 ] , V_430 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_422 ] , V_422 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_421 ] , V_421 ) ;
V_62 -> V_120 . V_121 = 0 ;
F_95 ( V_62 ) ;
F_232 ( V_3 , & V_62 -> V_120 . V_426 [ V_431 ] , V_431 ) ;
V_425 = F_81 ( V_229 ) ;
V_425 &= V_230 ;
V_425 |= V_62 -> V_120 . V_227 & ~ V_230 ;
F_88 ( V_229 , V_425 ) ;
F_88 ( V_432 , ( F_81 ( V_432 ) & ~ V_433 ) |
( F_81 ( V_434 ) & V_433 ) ) ;
F_101 ( V_3 ) ;
F_231 ( V_3 , V_421 , & V_62 -> V_120 . V_426 [ V_421 ] ) ;
F_231 ( V_3 , V_422 , & V_62 -> V_120 . V_426 [ V_422 ] ) ;
F_231 ( V_3 , V_427 , & V_62 -> V_120 . V_426 [ V_427 ] ) ;
F_231 ( V_3 , V_428 , & V_62 -> V_120 . V_426 [ V_428 ] ) ;
F_231 ( V_3 , V_429 , & V_62 -> V_120 . V_426 [ V_429 ] ) ;
F_231 ( V_3 , V_430 , & V_62 -> V_120 . V_426 [ V_430 ] ) ;
F_150 ( V_435 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ;
V_62 -> V_436 = 0 ;
}
static T_4 F_235 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_100 . V_437 ) {
struct V_438 * V_439 ;
struct V_440 * V_441 ;
T_13 V_442 ;
V_439 = V_438 ( V_12 ) ;
V_441 = F_236 ( V_439 , 0 ) ;
V_442 = V_441 -> V_442 + V_441 -> V_443 - 3 ;
return V_442 << V_13 ;
}
return V_12 -> V_100 . V_437 ;
}
static void F_237 ( int V_97 , struct V_419 * V_420 )
{
const struct V_444 * V_445 = & V_106 [ V_97 ] ;
struct V_419 V_446 = * V_420 ;
V_446 . V_424 = 0x3 ;
if ( V_97 == V_421 )
V_446 . type = 0x3 ;
if ( ! V_418 ) {
V_446 . V_104 = V_446 . V_107 >> 4 ;
V_446 . V_107 = V_446 . V_107 & 0xffff0 ;
V_446 . V_109 = 0xffff ;
V_446 . V_447 = 0 ;
V_446 . V_448 = 0 ;
V_446 . V_449 = 1 ;
V_446 . V_173 = 1 ;
V_446 . V_450 = 0 ;
V_446 . V_451 = 0 ;
V_446 . type = 0x3 ;
V_446 . V_452 = 0 ;
if ( V_420 -> V_107 & 0xf )
F_107 ( V_152 L_12
L_13
L_14 , V_97 ) ;
}
F_90 ( V_445 -> V_104 , V_446 . V_104 ) ;
F_91 ( V_445 -> V_107 , V_446 . V_107 ) ;
F_91 ( V_445 -> V_109 , V_446 . V_109 ) ;
F_91 ( V_445 -> V_113 , F_238 ( & V_446 ) ) ;
}
static void F_239 ( struct V_2 * V_3 )
{
unsigned long V_425 ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_431 ] , V_431 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_427 ] , V_427 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_428 ] , V_428 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_429 ] , V_429 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_430 ] , V_430 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_422 ] , V_422 ) ;
F_234 ( V_3 , & V_62 -> V_120 . V_426 [ V_421 ] , V_421 ) ;
V_62 -> V_120 . V_121 = 1 ;
if ( ! V_3 -> V_12 -> V_100 . V_437 ) {
F_107 ( V_152 L_15
L_16 ) ;
F_240 ( & V_3 -> V_12 -> V_453 , V_3 -> V_454 ) ;
F_241 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_454 = F_242 ( & V_3 -> V_12 -> V_453 ) ;
}
F_95 ( V_62 ) ;
F_88 ( V_455 , F_235 ( V_3 -> V_12 ) ) ;
F_91 ( V_456 , V_457 - 1 ) ;
F_91 ( V_458 , 0x008b ) ;
V_425 = F_81 ( V_229 ) ;
V_62 -> V_120 . V_227 = V_425 ;
V_425 |= V_231 | V_232 ;
F_88 ( V_229 , V_425 ) ;
F_88 ( V_432 , F_81 ( V_432 ) | V_433 ) ;
F_101 ( V_3 ) ;
F_237 ( V_422 , & V_62 -> V_120 . V_426 [ V_422 ] ) ;
F_237 ( V_421 , & V_62 -> V_120 . V_426 [ V_421 ] ) ;
F_237 ( V_427 , & V_62 -> V_120 . V_426 [ V_427 ] ) ;
F_237 ( V_428 , & V_62 -> V_120 . V_426 [ V_428 ] ) ;
F_237 ( V_430 , & V_62 -> V_120 . V_426 [ V_430 ] ) ;
F_237 ( V_429 , & V_62 -> V_120 . V_426 [ V_429 ] ) ;
F_243 ( V_3 ) ;
}
static void F_244 ( struct V_2 * V_3 , T_5 V_163 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_75 * V_63 = F_55 ( V_62 , V_130 ) ;
if ( ! V_63 )
return;
F_130 ( F_1 ( V_3 ) ) ;
V_3 -> V_100 . V_163 = V_163 ;
if ( V_163 & V_166 ) {
F_91 ( V_126 ,
F_83 ( V_126 ) |
V_298 ) ;
V_63 -> V_169 = V_163 ;
} else {
F_91 ( V_126 ,
F_83 ( V_126 ) &
~ V_298 ) ;
V_63 -> V_169 = V_163 & ~ V_167 ;
}
F_167 ( V_62 ) ;
}
static void F_245 ( struct V_2 * V_3 )
{
T_2 V_459 ;
F_95 ( F_1 ( V_3 ) ) ;
V_459 = F_83 ( V_458 ) ;
if ( ( V_459 & V_460 ) != V_461 ) {
F_246 ( L_17 ,
V_462 ) ;
F_91 ( V_458 ,
( V_459 & ~ V_460 )
| V_461 ) ;
}
F_244 ( V_3 , V_3 -> V_100 . V_163 | V_166 ) ;
}
static void F_247 ( struct V_2 * V_3 )
{
F_91 ( V_126 ,
F_83 ( V_126 )
& ~ V_298 ) ;
F_244 ( V_3 , V_3 -> V_100 . V_163 & ~ V_166 ) ;
}
static void F_248 ( struct V_2 * V_3 )
{
F_78 ( F_1 ( V_3 ) ) ;
if ( V_90 ) {
if ( ! F_249 ( V_3 -> V_100 . V_463 . V_464 ) )
return;
F_80 ( F_250 ( V_3 -> V_100 . V_463 . V_464 ) ) ;
}
}
static void F_147 ( struct V_2 * V_3 )
{
T_9 V_216 = V_3 -> V_100 . V_216 ;
V_3 -> V_100 . V_212 &= ~ V_216 ;
V_3 -> V_100 . V_212 |= F_81 ( V_213 ) & V_216 ;
}
static void F_251 ( struct V_2 * V_3 )
{
if ( V_90 && F_252 ( V_3 ) )
V_3 -> V_100 . V_465 = F_81 ( V_466 ) ;
F_150 ( V_467 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ;
}
static void F_253 ( struct V_2 * V_3 )
{
T_9 V_468 = V_3 -> V_100 . V_468 ;
V_3 -> V_100 . V_469 &= ~ V_468 ;
V_3 -> V_100 . V_469 |= F_81 ( V_432 ) & V_468 ;
}
static void F_254 ( struct V_2 * V_3 )
{
if ( ! F_149 ( V_368 ,
( unsigned long * ) & V_3 -> V_100 . V_470 ) )
return;
if ( F_252 ( V_3 ) && F_255 ( V_3 ) && ! F_120 ( V_3 ) ) {
F_92 ( V_471 , V_3 -> V_100 . V_463 . V_472 [ 0 ] ) ;
F_92 ( V_473 , V_3 -> V_100 . V_463 . V_472 [ 1 ] ) ;
F_92 ( V_474 , V_3 -> V_100 . V_463 . V_472 [ 2 ] ) ;
F_92 ( V_475 , V_3 -> V_100 . V_463 . V_472 [ 3 ] ) ;
}
}
static void F_196 ( struct V_2 * V_3 )
{
if ( F_252 ( V_3 ) && F_255 ( V_3 ) && ! F_120 ( V_3 ) ) {
V_3 -> V_100 . V_463 . V_472 [ 0 ] = F_84 ( V_471 ) ;
V_3 -> V_100 . V_463 . V_472 [ 1 ] = F_84 ( V_473 ) ;
V_3 -> V_100 . V_463 . V_472 [ 2 ] = F_84 ( V_474 ) ;
V_3 -> V_100 . V_463 . V_472 [ 3 ] = F_84 ( V_475 ) ;
}
F_150 ( V_368 ,
( unsigned long * ) & V_3 -> V_100 . V_101 ) ;
F_150 ( V_368 ,
( unsigned long * ) & V_3 -> V_100 . V_470 ) ;
}
static void F_256 ( unsigned long * V_476 ,
unsigned long V_212 ,
struct V_2 * V_3 )
{
if ( ! F_149 ( V_467 , ( T_9 * ) & V_3 -> V_100 . V_101 ) )
F_251 ( V_3 ) ;
if ( ! ( V_212 & V_477 ) ) {
F_91 ( V_478 ,
F_83 ( V_478 ) |
( V_306 |
V_307 ) ) ;
V_3 -> V_100 . V_212 = V_212 ;
F_257 ( V_3 , F_258 ( V_3 ) ) ;
} else if ( ! F_252 ( V_3 ) ) {
F_91 ( V_478 ,
F_83 ( V_478 ) &
~ ( V_306 |
V_307 ) ) ;
V_3 -> V_100 . V_212 = V_212 ;
F_257 ( V_3 , F_258 ( V_3 ) ) ;
}
if ( ! ( V_212 & V_479 ) )
* V_476 &= ~ V_479 ;
}
static void F_259 ( struct V_2 * V_3 , unsigned long V_212 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
unsigned long V_476 ;
V_476 = ( V_212 & ~ V_480 ) ;
if ( V_411 )
V_476 |= V_481 ;
else {
V_476 |= V_482 ;
if ( V_62 -> V_120 . V_121 && ( V_212 & V_483 ) )
F_233 ( V_3 ) ;
if ( ! V_62 -> V_120 . V_121 && ! ( V_212 & V_483 ) )
F_239 ( V_3 ) ;
}
#ifdef F_85
if ( V_3 -> V_100 . V_163 & V_167 ) {
if ( ! F_252 ( V_3 ) && ( V_212 & V_477 ) )
F_245 ( V_3 ) ;
if ( F_252 ( V_3 ) && ! ( V_212 & V_477 ) )
F_247 ( V_3 ) ;
}
#endif
if ( V_90 )
F_256 ( & V_476 , V_212 , V_3 ) ;
if ( ! V_3 -> V_122 )
V_476 |= V_214 | V_215 ;
F_88 ( V_225 , V_212 ) ;
F_88 ( V_213 , V_476 ) ;
V_3 -> V_100 . V_212 = V_212 ;
V_62 -> F_229 = F_229 ( V_3 ) ;
}
static T_5 F_250 ( unsigned long V_464 )
{
T_5 V_73 ;
V_73 = V_484 |
V_485 << V_486 ;
if ( V_412 )
V_73 |= V_487 ;
V_73 |= ( V_464 & V_488 ) ;
return V_73 ;
}
static void F_260 ( struct V_2 * V_3 , unsigned long V_465 )
{
unsigned long V_489 ;
T_5 V_73 ;
V_489 = V_465 ;
if ( V_90 ) {
V_73 = F_250 ( V_465 ) ;
F_92 ( V_490 , V_73 ) ;
V_489 = F_252 ( V_3 ) ? F_261 ( V_3 ) :
V_3 -> V_12 -> V_100 . V_491 ;
F_254 ( V_3 ) ;
}
F_248 ( V_3 ) ;
F_88 ( V_466 , V_489 ) ;
}
static int F_257 ( struct V_2 * V_3 , unsigned long V_469 )
{
unsigned long V_492 = V_469 | ( F_1 ( V_3 ) -> V_120 . V_121 ?
V_493 : V_494 ) ;
if ( V_469 & V_375 ) {
if ( ! F_180 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_495 )
return 1 ;
V_3 -> V_100 . V_469 = V_469 ;
if ( V_90 ) {
if ( ! F_252 ( V_3 ) ) {
V_492 &= ~ V_496 ;
V_492 |= V_497 ;
V_492 &= ~ V_498 ;
} else if ( ! ( V_469 & V_496 ) ) {
V_492 &= ~ V_496 ;
}
}
F_88 ( V_434 , V_469 ) ;
F_88 ( V_432 , V_492 ) ;
return 0 ;
}
static void F_234 ( struct V_2 * V_3 ,
struct V_419 * V_446 , int V_97 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_2 V_111 ;
if ( V_62 -> V_120 . V_121 && V_97 != V_499 ) {
* V_446 = V_62 -> V_120 . V_426 [ V_97 ] ;
if ( V_97 == V_431
|| V_446 -> V_104 == F_97 ( V_62 , V_97 ) )
return;
V_446 -> V_107 = F_98 ( V_62 , V_97 ) ;
V_446 -> V_104 = F_97 ( V_62 , V_97 ) ;
return;
}
V_446 -> V_107 = F_98 ( V_62 , V_97 ) ;
V_446 -> V_109 = F_99 ( V_62 , V_97 ) ;
V_446 -> V_104 = F_97 ( V_62 , V_97 ) ;
V_111 = F_100 ( V_62 , V_97 ) ;
V_446 -> type = V_111 & 15 ;
V_446 -> V_173 = ( V_111 >> 4 ) & 1 ;
V_446 -> V_424 = ( V_111 >> 5 ) & 3 ;
V_446 -> V_449 = ( V_111 >> 7 ) & 1 ;
V_446 -> V_452 = ( V_111 >> 12 ) & 1 ;
V_446 -> V_450 = ( V_111 >> 13 ) & 1 ;
V_446 -> V_448 = ( V_111 >> 14 ) & 1 ;
V_446 -> V_447 = ( V_111 >> 15 ) & 1 ;
V_446 -> V_451 = ( V_111 >> 16 ) & 1 ;
}
static T_5 F_262 ( struct V_2 * V_3 , int V_97 )
{
struct V_419 V_173 ;
if ( F_1 ( V_3 ) -> V_120 . V_121 ) {
F_234 ( V_3 , & V_173 , V_97 ) ;
return V_173 . V_107 ;
}
return F_98 ( F_1 ( V_3 ) , V_97 ) ;
}
static int F_263 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( ! F_264 ( V_3 ) )
return 0 ;
if ( ! F_120 ( V_3 )
&& ( F_265 ( V_3 ) & V_232 ) )
return 3 ;
if ( ! F_149 ( V_435 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ) {
F_150 ( V_435 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ;
V_62 -> V_436 = F_97 ( V_62 , V_421 ) & 3 ;
}
return V_62 -> V_436 ;
}
static T_2 F_238 ( struct V_419 * V_446 )
{
T_2 V_111 ;
if ( V_446 -> V_451 || ! V_446 -> V_449 )
V_111 = 1 << 16 ;
else {
V_111 = V_446 -> type & 15 ;
V_111 |= ( V_446 -> V_173 & 1 ) << 4 ;
V_111 |= ( V_446 -> V_424 & 3 ) << 5 ;
V_111 |= ( V_446 -> V_449 & 1 ) << 7 ;
V_111 |= ( V_446 -> V_452 & 1 ) << 12 ;
V_111 |= ( V_446 -> V_450 & 1 ) << 13 ;
V_111 |= ( V_446 -> V_448 & 1 ) << 14 ;
V_111 |= ( V_446 -> V_447 & 1 ) << 15 ;
}
return V_111 ;
}
static void F_232 ( struct V_2 * V_3 ,
struct V_419 * V_446 , int V_97 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
const struct V_444 * V_445 = & V_106 [ V_97 ] ;
F_95 ( V_62 ) ;
if ( V_97 == V_421 )
F_266 ( V_435 , ( T_9 * ) & V_3 -> V_100 . V_101 ) ;
if ( V_62 -> V_120 . V_121 && V_97 != V_499 ) {
V_62 -> V_120 . V_426 [ V_97 ] = * V_446 ;
if ( V_97 == V_431 )
F_90 ( V_445 -> V_104 , V_446 -> V_104 ) ;
else if ( V_446 -> V_173 )
F_237 ( V_97 , & V_62 -> V_120 . V_426 [ V_97 ] ) ;
goto V_500;
}
F_88 ( V_445 -> V_107 , V_446 -> V_107 ) ;
F_91 ( V_445 -> V_109 , V_446 -> V_109 ) ;
F_90 ( V_445 -> V_104 , V_446 -> V_104 ) ;
if ( V_411 && ( V_97 != V_499 ) )
V_446 -> type |= 0x1 ;
F_91 ( V_445 -> V_113 , F_238 ( V_446 ) ) ;
V_500:
V_62 -> F_229 |= F_229 ( V_3 ) ;
}
static void F_267 ( struct V_2 * V_3 , int * V_448 , int * V_450 )
{
T_2 V_111 = F_100 ( F_1 ( V_3 ) , V_421 ) ;
* V_448 = ( V_111 >> 14 ) & 1 ;
* V_450 = ( V_111 >> 13 ) & 1 ;
}
static void F_268 ( struct V_2 * V_3 , struct V_153 * V_501 )
{
V_501 -> V_398 = F_83 ( V_502 ) ;
V_501 -> V_158 = F_81 ( V_503 ) ;
}
static void F_269 ( struct V_2 * V_3 , struct V_153 * V_501 )
{
F_91 ( V_502 , V_501 -> V_398 ) ;
F_88 ( V_503 , V_501 -> V_158 ) ;
}
static void F_270 ( struct V_2 * V_3 , struct V_153 * V_501 )
{
V_501 -> V_398 = F_83 ( V_504 ) ;
V_501 -> V_158 = F_81 ( V_505 ) ;
}
static void F_271 ( struct V_2 * V_3 , struct V_153 * V_501 )
{
F_91 ( V_504 , V_501 -> V_398 ) ;
F_88 ( V_505 , V_501 -> V_158 ) ;
}
static bool F_272 ( struct V_2 * V_3 , int V_97 )
{
struct V_419 V_446 ;
T_2 V_111 ;
F_234 ( V_3 , & V_446 , V_97 ) ;
V_446 . V_424 = 0x3 ;
if ( V_97 == V_421 )
V_446 . type = 0x3 ;
V_111 = F_238 ( & V_446 ) ;
if ( V_446 . V_107 != ( V_446 . V_104 << 4 ) )
return false ;
if ( V_446 . V_109 != 0xffff )
return false ;
if ( V_111 != 0xf3 )
return false ;
return true ;
}
static bool F_273 ( struct V_2 * V_3 )
{
struct V_419 V_506 ;
unsigned int V_507 ;
F_234 ( V_3 , & V_506 , V_421 ) ;
V_507 = V_506 . V_104 & V_423 ;
if ( V_506 . V_451 )
return false ;
if ( ~ V_506 . type & ( V_508 | V_509 ) )
return false ;
if ( ! V_506 . V_173 )
return false ;
if ( V_506 . type & V_510 ) {
if ( V_506 . V_424 > V_507 )
return false ;
} else {
if ( V_506 . V_424 != V_507 )
return false ;
}
if ( ! V_506 . V_449 )
return false ;
return true ;
}
static bool F_274 ( struct V_2 * V_3 )
{
struct V_419 V_511 ;
unsigned int V_512 ;
F_234 ( V_3 , & V_511 , V_422 ) ;
V_512 = V_511 . V_104 & V_423 ;
if ( V_511 . V_451 )
return true ;
if ( V_511 . type != 3 && V_511 . type != 7 )
return false ;
if ( ! V_511 . V_173 )
return false ;
if ( V_511 . V_424 != V_512 )
return false ;
if ( ! V_511 . V_449 )
return false ;
return true ;
}
static bool F_275 ( struct V_2 * V_3 , int V_97 )
{
struct V_419 V_446 ;
unsigned int V_513 ;
F_234 ( V_3 , & V_446 , V_97 ) ;
V_513 = V_446 . V_104 & V_423 ;
if ( V_446 . V_451 )
return true ;
if ( ! V_446 . V_173 )
return false ;
if ( ! V_446 . V_449 )
return false ;
if ( ~ V_446 . type & ( V_508 | V_510 ) ) {
if ( V_446 . V_424 < V_513 )
return false ;
}
return true ;
}
static bool F_276 ( struct V_2 * V_3 )
{
struct V_419 V_176 ;
F_234 ( V_3 , & V_176 , V_431 ) ;
if ( V_176 . V_451 )
return false ;
if ( V_176 . V_104 & V_514 )
return false ;
if ( V_176 . type != 3 && V_176 . type != 11 )
return false ;
if ( ! V_176 . V_449 )
return false ;
return true ;
}
static bool F_277 ( struct V_2 * V_3 )
{
struct V_419 V_515 ;
F_234 ( V_3 , & V_515 , V_499 ) ;
if ( V_515 . V_451 )
return true ;
if ( V_515 . V_104 & V_514 )
return false ;
if ( V_515 . type != 2 )
return false ;
if ( ! V_515 . V_449 )
return false ;
return true ;
}
static bool F_278 ( struct V_2 * V_3 )
{
struct V_419 V_506 , V_511 ;
F_234 ( V_3 , & V_506 , V_421 ) ;
F_234 ( V_3 , & V_511 , V_422 ) ;
return ( ( V_506 . V_104 & V_423 ) ==
( V_511 . V_104 & V_423 ) ) ;
}
static bool F_230 ( struct V_2 * V_3 )
{
if ( V_411 )
return true ;
if ( ! F_264 ( V_3 ) ) {
if ( ! F_272 ( V_3 , V_421 ) )
return false ;
if ( ! F_272 ( V_3 , V_422 ) )
return false ;
if ( ! F_272 ( V_3 , V_428 ) )
return false ;
if ( ! F_272 ( V_3 , V_427 ) )
return false ;
if ( ! F_272 ( V_3 , V_429 ) )
return false ;
if ( ! F_272 ( V_3 , V_430 ) )
return false ;
} else {
if ( ! F_278 ( V_3 ) )
return false ;
if ( ! F_273 ( V_3 ) )
return false ;
if ( ! F_274 ( V_3 ) )
return false ;
if ( ! F_275 ( V_3 , V_428 ) )
return false ;
if ( ! F_275 ( V_3 , V_427 ) )
return false ;
if ( ! F_275 ( V_3 , V_429 ) )
return false ;
if ( ! F_275 ( V_3 , V_430 ) )
return false ;
if ( ! F_276 ( V_3 ) )
return false ;
if ( ! F_277 ( V_3 ) )
return false ;
}
return true ;
}
static int F_279 ( struct V_12 * V_12 )
{
T_13 V_516 ;
T_3 V_169 = 0 ;
int V_517 , V_518 , V_98 = 0 ;
V_518 = F_242 ( & V_12 -> V_453 ) ;
V_516 = F_235 ( V_12 ) >> V_13 ;
V_517 = F_280 ( V_12 , V_516 , 0 , V_397 ) ;
if ( V_517 < 0 )
goto V_500;
V_169 = V_519 + V_520 ;
V_517 = F_281 ( V_12 , V_516 ++ , & V_169 ,
V_521 , sizeof( T_3 ) ) ;
if ( V_517 < 0 )
goto V_500;
V_517 = F_280 ( V_12 , V_516 ++ , 0 , V_397 ) ;
if ( V_517 < 0 )
goto V_500;
V_517 = F_280 ( V_12 , V_516 , 0 , V_397 ) ;
if ( V_517 < 0 )
goto V_500;
V_169 = ~ 0 ;
V_517 = F_281 ( V_12 , V_516 , & V_169 ,
V_457 - 2 * V_397 - 1 ,
sizeof( T_6 ) ) ;
if ( V_517 < 0 )
goto V_500;
V_98 = 1 ;
V_500:
F_240 ( & V_12 -> V_453 , V_518 ) ;
return V_98 ;
}
static int F_282 ( struct V_12 * V_12 )
{
int V_64 , V_518 , V_517 , V_98 ;
T_14 V_522 ;
T_2 V_256 ;
if ( ! V_90 )
return 1 ;
if ( F_89 ( ! V_12 -> V_100 . V_523 ) ) {
F_58 ( V_78 L_18
L_19 ) ;
return 0 ;
}
if ( F_283 ( V_12 -> V_100 . V_524 ) )
return 1 ;
V_98 = 0 ;
V_522 = V_12 -> V_100 . V_491 >> V_13 ;
V_518 = F_242 ( & V_12 -> V_453 ) ;
V_517 = F_280 ( V_12 , V_522 , 0 , V_397 ) ;
if ( V_517 < 0 )
goto V_500;
for ( V_64 = 0 ; V_64 < V_525 ; V_64 ++ ) {
V_256 = ( V_64 << 22 ) + ( V_526 | V_527 | V_528 |
V_529 | V_530 | V_531 ) ;
V_517 = F_281 ( V_12 , V_522 ,
& V_256 , V_64 * sizeof( V_256 ) , sizeof( V_256 ) ) ;
if ( V_517 < 0 )
goto V_500;
}
V_12 -> V_100 . V_524 = true ;
V_98 = 1 ;
V_500:
F_240 ( & V_12 -> V_453 , V_518 ) ;
return V_98 ;
}
static void F_284 ( int V_97 )
{
const struct V_444 * V_445 = & V_106 [ V_97 ] ;
unsigned int V_111 ;
F_90 ( V_445 -> V_104 , 0 ) ;
F_88 ( V_445 -> V_107 , 0 ) ;
F_91 ( V_445 -> V_109 , 0xffff ) ;
V_111 = 0x93 ;
if ( V_97 == V_421 )
V_111 |= 0x08 ;
F_91 ( V_445 -> V_113 , V_111 ) ;
}
static int F_285 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_532 V_533 ;
int V_517 = 0 ;
F_286 ( & V_12 -> V_534 ) ;
if ( V_12 -> V_100 . V_535 )
goto V_500;
V_533 . V_441 = V_536 ;
V_533 . V_425 = 0 ;
V_533 . V_537 = 0xfee00000ULL ;
V_533 . V_538 = V_397 ;
V_517 = F_287 ( V_12 , & V_533 , false ) ;
if ( V_517 )
goto V_500;
V_10 = F_6 ( V_12 , 0xfee00 ) ;
if ( F_7 ( V_10 ) ) {
V_517 = - V_539 ;
goto V_500;
}
V_12 -> V_100 . V_535 = V_10 ;
V_500:
F_288 ( & V_12 -> V_534 ) ;
return V_517 ;
}
static int F_289 ( struct V_12 * V_12 )
{
struct V_10 * V_10 ;
struct V_532 V_533 ;
int V_517 = 0 ;
F_286 ( & V_12 -> V_534 ) ;
if ( V_12 -> V_100 . V_523 )
goto V_500;
V_533 . V_441 = V_540 ;
V_533 . V_425 = 0 ;
V_533 . V_537 =
V_12 -> V_100 . V_491 ;
V_533 . V_538 = V_397 ;
V_517 = F_287 ( V_12 , & V_533 , false ) ;
if ( V_517 )
goto V_500;
V_10 = F_6 ( V_12 , V_12 -> V_100 . V_491 >> V_13 ) ;
if ( F_7 ( V_10 ) ) {
V_517 = - V_539 ;
goto V_500;
}
V_12 -> V_100 . V_523 = V_10 ;
V_500:
F_288 ( & V_12 -> V_534 ) ;
return V_517 ;
}
static void F_290 ( struct V_1 * V_62 )
{
int V_45 ;
V_62 -> V_45 = 0 ;
if ( ! V_410 )
return;
F_291 ( & V_541 ) ;
V_45 = F_292 ( V_542 , V_543 ) ;
if ( V_45 < V_543 ) {
V_62 -> V_45 = V_45 ;
F_150 ( V_45 , V_542 ) ;
}
F_293 ( & V_541 ) ;
}
static void F_294 ( struct V_1 * V_62 )
{
if ( ! V_410 )
return;
F_291 ( & V_541 ) ;
if ( V_62 -> V_45 != 0 )
F_266 ( V_62 -> V_45 , V_542 ) ;
F_293 ( & V_541 ) ;
}
static void F_295 ( unsigned long * V_257 ,
T_2 V_63 , int type )
{
int V_544 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_63 <= 0x1fff ) {
if ( type & V_545 )
F_266 ( V_63 , V_257 + 0x000 / V_544 ) ;
if ( type & V_546 )
F_266 ( V_63 , V_257 + 0x800 / V_544 ) ;
} else if ( ( V_63 >= 0xc0000000 ) && ( V_63 <= 0xc0001fff ) ) {
V_63 &= 0x1fff ;
if ( type & V_545 )
F_266 ( V_63 , V_257 + 0x400 / V_544 ) ;
if ( type & V_546 )
F_266 ( V_63 , V_257 + 0xc00 / V_544 ) ;
}
}
static void F_296 ( unsigned long * V_257 ,
T_2 V_63 , int type )
{
int V_544 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_63 <= 0x1fff ) {
if ( type & V_545 )
F_150 ( V_63 , V_257 + 0x000 / V_544 ) ;
if ( type & V_546 )
F_150 ( V_63 , V_257 + 0x800 / V_544 ) ;
} else if ( ( V_63 >= 0xc0000000 ) && ( V_63 <= 0xc0001fff ) ) {
V_63 &= 0x1fff ;
if ( type & V_545 )
F_150 ( V_63 , V_257 + 0x400 / V_544 ) ;
if ( type & V_546 )
F_150 ( V_63 , V_257 + 0xc00 / V_544 ) ;
}
}
static void F_297 ( T_2 V_63 , bool V_547 )
{
if ( ! V_547 )
F_295 ( V_262 ,
V_63 , V_545 | V_546 ) ;
F_295 ( V_261 ,
V_63 , V_545 | V_546 ) ;
}
static void F_298 ( T_2 V_63 )
{
F_296 ( V_260 ,
V_63 , V_545 ) ;
F_296 ( V_259 ,
V_63 , V_545 ) ;
}
static void F_299 ( T_2 V_63 )
{
F_295 ( V_260 ,
V_63 , V_545 ) ;
F_295 ( V_259 ,
V_63 , V_545 ) ;
}
static void F_300 ( T_2 V_63 )
{
F_295 ( V_260 ,
V_63 , V_546 ) ;
F_295 ( V_259 ,
V_63 , V_546 ) ;
}
static void F_301 ( void )
{
T_2 V_548 , V_549 ;
unsigned long V_550 ;
struct V_153 V_501 ;
F_88 ( V_551 , F_302 () & ~ V_214 ) ;
F_88 ( V_552 , F_202 () ) ;
F_88 ( V_553 , F_303 () ) ;
F_90 ( V_554 , V_555 ) ;
#ifdef F_85
F_90 ( V_556 , 0 ) ;
F_90 ( V_557 , 0 ) ;
#else
F_90 ( V_556 , V_558 ) ;
F_90 ( V_557 , V_558 ) ;
#endif
F_90 ( V_559 , V_558 ) ;
F_90 ( V_560 , V_159 * 8 ) ;
F_304 ( & V_501 ) ;
F_88 ( V_561 , V_501 . V_158 ) ;
F_88 ( V_562 , V_563 ) ;
F_182 ( V_349 , V_548 , V_549 ) ;
F_91 ( V_564 , V_548 ) ;
F_119 ( V_351 , V_550 ) ;
F_88 ( V_565 , V_550 ) ;
if ( V_24 . V_401 & V_396 ) {
F_182 ( V_356 , V_548 , V_549 ) ;
F_92 ( V_566 , V_548 | ( ( T_5 ) V_549 << 32 ) ) ;
}
}
static void F_305 ( struct V_1 * V_62 )
{
V_62 -> V_3 . V_100 . V_468 = V_567 ;
if ( V_90 )
V_62 -> V_3 . V_100 . V_468 |= V_568 ;
if ( F_102 ( & V_62 -> V_3 ) )
V_62 -> V_3 . V_100 . V_468 &=
~ F_4 ( & V_62 -> V_3 ) -> V_223 ;
F_88 ( V_569 , ~ V_62 -> V_3 . V_100 . V_468 ) ;
}
static T_2 F_306 ( struct V_1 * V_62 )
{
T_2 V_570 = V_24 . V_25 ;
if ( ! F_19 ( V_62 -> V_3 . V_12 ) ) {
V_570 &= ~ V_27 ;
#ifdef F_85
V_570 |= V_309 |
V_308 ;
#endif
}
if ( ! V_90 )
V_570 |= V_307 |
V_306 |
V_304 ;
return V_570 ;
}
static int F_307 ( struct V_12 * V_12 )
{
return V_416 && F_20 ( V_12 ) ;
}
static T_2 F_308 ( struct V_1 * V_62 )
{
T_2 V_570 = V_24 . V_29 ;
if ( ! F_41 ( V_62 -> V_3 . V_12 ) )
V_570 &= ~ V_30 ;
if ( V_62 -> V_45 == 0 )
V_570 &= ~ V_52 ;
if ( ! V_90 ) {
V_570 &= ~ V_48 ;
V_411 = 0 ;
V_570 &= ~ V_54 ;
}
if ( ! V_411 )
V_570 &= ~ V_49 ;
if ( ! V_415 )
V_570 &= ~ V_50 ;
if ( ! F_307 ( V_62 -> V_3 . V_12 ) )
V_570 &= ~ ( V_32 |
V_33 ) ;
V_570 &= ~ V_31 ;
return V_570 ;
}
static void F_309 ( void )
{
F_310 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_311 ( struct V_1 * V_62 )
{
#ifdef F_85
unsigned long V_571 ;
#endif
int V_64 ;
F_92 ( V_572 , F_57 ( V_573 ) ) ;
F_92 ( V_574 , F_57 ( V_575 ) ) ;
if ( F_17 () )
F_92 ( V_263 , F_57 ( V_262 ) ) ;
F_92 ( V_576 , - 1ull ) ;
F_91 ( V_577 ,
V_24 . V_55 ) ;
F_91 ( V_478 , F_306 ( V_62 ) ) ;
if ( F_21 () ) {
F_91 ( V_578 ,
F_308 ( V_62 ) ) ;
}
if ( V_416 ) {
F_92 ( V_579 , 0 ) ;
F_92 ( V_580 , 0 ) ;
F_92 ( V_581 , 0 ) ;
F_92 ( V_582 , 0 ) ;
F_90 ( V_583 , 0 ) ;
}
if ( V_415 ) {
F_91 ( V_584 , V_415 ) ;
F_91 ( V_585 , V_586 ) ;
}
F_91 ( V_587 , 0 ) ;
F_91 ( V_588 , 0 ) ;
F_91 ( V_589 , 0 ) ;
F_90 ( V_183 , 0 ) ;
F_90 ( V_187 , 0 ) ;
F_301 () ;
#ifdef F_85
F_119 ( V_193 , V_571 ) ;
F_88 ( V_192 , V_571 ) ;
F_119 ( V_195 , V_571 ) ;
F_88 ( V_194 , V_571 ) ;
#else
F_88 ( V_192 , 0 ) ;
F_88 ( V_194 , 0 ) ;
#endif
F_91 ( V_590 , 0 ) ;
F_91 ( V_142 , 0 ) ;
F_92 ( V_591 , F_57 ( V_62 -> V_128 . V_140 ) ) ;
F_91 ( V_141 , 0 ) ;
F_92 ( V_592 , F_57 ( V_62 -> V_128 . V_139 ) ) ;
if ( V_24 . V_357 & V_297 ) {
T_2 V_593 , V_594 ;
T_5 V_595 ;
F_182 ( V_356 , V_593 , V_594 ) ;
V_595 = V_593 | ( ( T_5 ) V_594 << 32 ) ;
F_92 ( V_358 , V_595 ) ;
V_62 -> V_3 . V_100 . V_359 = V_595 ;
}
for ( V_64 = 0 ; V_64 < V_596 ; ++ V_64 ) {
T_2 V_68 = V_66 [ V_64 ] ;
T_2 V_597 , V_598 ;
int V_599 = V_62 -> V_65 ;
if ( F_312 ( V_68 , & V_597 , & V_598 ) < 0 )
continue;
if ( F_313 ( V_68 , V_597 , V_598 ) < 0 )
continue;
V_62 -> V_67 [ V_599 ] . V_68 = V_64 ;
V_62 -> V_67 [ V_599 ] . V_169 = 0 ;
V_62 -> V_67 [ V_599 ] . V_94 = - 1ull ;
++ V_62 -> V_65 ;
}
F_91 ( V_127 , V_24 . V_401 ) ;
F_91 ( V_126 , V_24 . V_357 ) ;
F_88 ( V_218 , ~ 0UL ) ;
F_305 ( V_62 ) ;
return 0 ;
}
static int F_314 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_5 V_63 ;
int V_98 ;
V_62 -> V_120 . V_121 = 0 ;
V_62 -> V_600 = 0 ;
V_62 -> V_3 . V_100 . V_364 [ V_601 ] = F_315 () ;
F_316 ( & V_62 -> V_3 , 0 ) ;
V_63 = 0xfee00000 | V_602 ;
if ( F_317 ( & V_62 -> V_3 ) )
V_63 |= V_603 ;
F_318 ( & V_62 -> V_3 , V_63 ) ;
F_95 ( V_62 ) ;
F_284 ( V_421 ) ;
if ( F_317 ( & V_62 -> V_3 ) )
F_90 ( V_604 , 0xf000 ) ;
else {
F_90 ( V_604 , V_62 -> V_3 . V_100 . V_605 << 8 ) ;
F_88 ( V_606 , V_62 -> V_3 . V_100 . V_605 << 12 ) ;
}
F_284 ( V_428 ) ;
F_284 ( V_427 ) ;
F_284 ( V_429 ) ;
F_284 ( V_430 ) ;
F_284 ( V_422 ) ;
F_90 ( V_607 , 0 ) ;
F_88 ( V_455 , 0 ) ;
F_91 ( V_456 , 0xffff ) ;
F_91 ( V_458 , 0x008b ) ;
F_90 ( V_608 , 0 ) ;
F_88 ( V_609 , 0 ) ;
F_91 ( V_610 , 0xffff ) ;
F_91 ( V_611 , 0x00082 ) ;
F_91 ( V_350 , 0 ) ;
F_88 ( V_353 , 0 ) ;
F_88 ( V_352 , 0 ) ;
F_88 ( V_229 , 0x02 ) ;
if ( F_317 ( & V_62 -> V_3 ) )
F_156 ( V_3 , 0xfff0 ) ;
else
F_156 ( V_3 , 0 ) ;
F_88 ( V_505 , 0 ) ;
F_91 ( V_504 , 0xffff ) ;
F_88 ( V_503 , 0 ) ;
F_91 ( V_502 , 0xffff ) ;
F_91 ( V_612 , V_613 ) ;
F_91 ( V_234 , 0 ) ;
F_91 ( V_614 , 0 ) ;
F_92 ( V_615 , 0 ) ;
F_167 ( V_62 ) ;
F_91 ( V_253 , 0 ) ;
if ( F_18 () ) {
F_92 ( V_616 , 0 ) ;
if ( F_19 ( V_62 -> V_3 . V_12 ) )
F_92 ( V_616 ,
F_57 ( V_62 -> V_3 . V_100 . V_258 -> V_364 ) ) ;
F_91 ( V_617 , 0 ) ;
}
if ( F_41 ( V_62 -> V_3 . V_12 ) )
F_92 ( V_618 ,
F_319 ( V_62 -> V_3 . V_12 -> V_100 . V_535 ) ) ;
if ( V_62 -> V_45 != 0 )
F_90 ( V_619 , V_62 -> V_45 ) ;
V_62 -> V_3 . V_100 . V_212 = V_620 | V_621 | V_622 ;
V_3 -> V_454 = F_242 ( & V_3 -> V_12 -> V_453 ) ;
F_259 ( & V_62 -> V_3 , F_320 ( V_3 ) ) ;
F_240 ( & V_3 -> V_12 -> V_453 , V_3 -> V_454 ) ;
F_257 ( & V_62 -> V_3 , 0 ) ;
F_244 ( & V_62 -> V_3 , 0 ) ;
F_142 ( & V_62 -> V_3 ) ;
F_101 ( & V_62 -> V_3 ) ;
F_78 ( V_62 ) ;
V_98 = 0 ;
return V_98 ;
}
static bool F_321 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_61 &
V_289 ;
}
static void F_322 ( struct V_2 * V_3 )
{
T_2 V_59 ;
if ( F_102 ( V_3 ) && F_321 ( V_3 ) ) {
F_135 ( V_623 , V_3 ) ;
return;
}
V_59 = F_83 ( V_478 ) ;
V_59 |= V_302 ;
F_91 ( V_478 , V_59 ) ;
}
static void F_323 ( struct V_2 * V_3 )
{
T_2 V_59 ;
if ( ! F_45 () ) {
F_322 ( V_3 ) ;
return;
}
if ( F_83 ( V_234 ) & V_235 ) {
F_322 ( V_3 ) ;
return;
}
V_59 = F_83 ( V_478 ) ;
V_59 |= V_624 ;
F_91 ( V_478 , V_59 ) ;
}
static void F_324 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_15 V_625 ;
int V_626 = V_3 -> V_100 . V_627 . V_138 ;
F_325 ( V_626 ) ;
++ V_3 -> V_200 . V_628 ;
if ( V_62 -> V_120 . V_121 ) {
int V_247 = 0 ;
if ( V_3 -> V_100 . V_627 . V_629 )
V_247 = V_3 -> V_100 . V_248 ;
if ( F_161 ( V_3 , V_626 , V_247 ) != V_249 )
F_135 ( V_250 , V_3 ) ;
return;
}
V_625 = V_626 | V_17 ;
if ( V_3 -> V_100 . V_627 . V_629 ) {
V_625 |= V_630 ;
F_91 ( V_251 ,
V_62 -> V_3 . V_100 . V_248 ) ;
} else
V_625 |= V_22 ;
F_91 ( V_253 , V_625 ) ;
}
static void F_326 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( F_102 ( V_3 ) )
return;
if ( ! F_45 () ) {
V_62 -> V_600 = 1 ;
V_62 -> V_631 = 0 ;
}
++ V_3 -> V_200 . V_632 ;
V_62 -> V_633 = false ;
if ( V_62 -> V_120 . V_121 ) {
if ( F_161 ( V_3 , V_634 , 0 ) != V_249 )
F_135 ( V_250 , V_3 ) ;
return;
}
F_91 ( V_253 ,
V_635 | V_17 | V_634 ) ;
}
static int F_327 ( struct V_2 * V_3 )
{
if ( ! F_45 () && F_1 ( V_3 ) -> V_600 )
return 0 ;
return ! ( F_83 ( V_234 ) &
( V_237 | V_235
| V_636 ) ) ;
}
static bool F_328 ( struct V_2 * V_3 )
{
if ( ! F_45 () )
return F_1 ( V_3 ) -> V_600 ;
if ( F_1 ( V_3 ) -> V_633 )
return false ;
return F_83 ( V_234 ) & V_636 ;
}
static void F_329 ( struct V_2 * V_3 , bool V_637 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( ! F_45 () ) {
if ( V_62 -> V_600 != V_637 ) {
V_62 -> V_600 = V_637 ;
V_62 -> V_631 = 0 ;
}
} else {
V_62 -> V_633 = ! V_637 ;
if ( V_637 )
F_94 ( V_234 ,
V_636 ) ;
else
F_93 ( V_234 ,
V_636 ) ;
}
}
static int F_330 ( struct V_2 * V_3 )
{
if ( F_102 ( V_3 ) && F_321 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_638 ||
( V_7 -> V_639 &
V_640 ) )
return 0 ;
F_158 ( V_3 ) ;
V_7 -> V_641 = V_642 ;
V_7 -> V_643 = 0 ;
}
return ( F_81 ( V_229 ) & V_644 ) &&
! ( F_83 ( V_234 ) &
( V_235 | V_237 ) ) ;
}
static int F_241 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_98 ;
struct V_532 V_645 = {
. V_441 = V_646 ,
. V_537 = V_11 ,
. V_538 = V_397 * 3 ,
. V_425 = 0 ,
} ;
V_98 = F_331 ( V_12 , & V_645 , false ) ;
if ( V_98 )
return V_98 ;
V_12 -> V_100 . V_437 = V_11 ;
if ( ! F_279 ( V_12 ) )
return - V_408 ;
return 0 ;
}
static bool F_332 ( struct V_2 * V_3 , int V_647 )
{
switch ( V_647 ) {
case V_119 :
F_1 ( V_3 ) -> V_3 . V_100 . V_248 =
F_83 ( V_241 ) ;
if ( V_3 -> V_116 & V_118 )
return false ;
case V_115 :
if ( V_3 -> V_116 &
( V_648 | V_649 ) )
return false ;
case V_650 :
case V_651 :
case V_652 :
case V_21 :
case V_653 :
case V_654 :
case V_326 :
case V_655 :
return true ;
break;
}
return false ;
}
static int F_333 ( struct V_2 * V_3 ,
int V_647 , T_2 V_656 )
{
if ( ( ( V_647 == V_326 ) || ( V_647 == V_654 ) ) && V_656 == 0 ) {
if ( F_334 ( V_3 , 0 ) == V_249 ) {
if ( V_3 -> V_100 . V_657 ) {
V_3 -> V_100 . V_657 = 0 ;
return F_335 ( V_3 ) ;
}
return 1 ;
}
return 0 ;
}
F_336 ( V_3 , V_647 ) ;
return 1 ;
}
static void F_337 ( void )
{
#if F_338 ( V_658 ) && F_338 ( F_85 )
struct V_659 V_364 = {
. V_506 = 3 ,
. V_425 = V_644 ,
} ;
F_339 ( & V_364 , 0 ) ;
#endif
}
static int F_340 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_341 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_660 * V_660 = V_3 -> V_661 ;
T_2 V_14 , V_662 , V_243 ;
unsigned long V_663 , V_240 , V_664 ;
T_2 V_665 ;
enum V_666 V_667 ;
V_665 = V_62 -> V_668 ;
V_14 = V_62 -> V_669 ;
if ( F_16 ( V_14 ) )
return F_340 ( V_3 ) ;
if ( ( V_14 & V_15 ) == V_635 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_142 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_667 = F_334 ( V_3 , V_670 ) ;
if ( V_667 != V_249 )
F_336 ( V_3 , V_21 ) ;
return 1 ;
}
V_243 = 0 ;
if ( V_14 & V_246 )
V_243 = F_83 ( V_671 ) ;
if ( ( V_665 & V_640 ) &&
! ( F_12 ( V_14 ) && ! ( V_243 & V_672 ) ) ) {
V_3 -> V_661 -> V_673 = V_674 ;
V_3 -> V_661 -> V_675 . V_676 = V_677 ;
V_3 -> V_661 -> V_675 . V_678 = 2 ;
V_3 -> V_661 -> V_675 . V_169 [ 0 ] = V_665 ;
V_3 -> V_661 -> V_675 . V_169 [ 1 ] = V_14 ;
return 0 ;
}
if ( F_12 ( V_14 ) ) {
F_342 ( V_90 ) ;
V_663 = F_81 ( V_679 ) ;
F_343 ( V_663 , V_243 ) ;
if ( F_344 ( V_3 ) )
F_345 ( V_3 , V_663 ) ;
return F_346 ( V_3 , V_663 , V_243 , NULL , 0 ) ;
}
V_662 = V_14 & V_16 ;
if ( V_62 -> V_120 . V_121 && F_332 ( V_3 , V_662 ) )
return F_333 ( V_3 , V_662 , V_243 ) ;
switch ( V_662 ) {
case V_115 :
V_664 = F_81 ( V_679 ) ;
if ( ! ( V_3 -> V_116 &
( V_648 | V_649 ) ) ) {
V_3 -> V_100 . V_664 = V_664 | V_680 ;
F_336 ( V_3 , V_115 ) ;
return 1 ;
}
V_660 -> V_681 . V_100 . V_664 = V_664 | V_680 ;
V_660 -> V_681 . V_100 . V_682 = F_81 ( V_683 ) ;
case V_119 :
V_62 -> V_3 . V_100 . V_248 =
F_83 ( V_241 ) ;
V_660 -> V_673 = V_684 ;
V_240 = F_155 ( V_3 ) ;
V_660 -> V_681 . V_100 . V_685 = F_81 ( V_606 ) + V_240 ;
V_660 -> V_681 . V_100 . V_686 = V_662 ;
break;
default:
V_660 -> V_673 = V_687 ;
V_660 -> V_688 . V_686 = V_662 ;
V_660 -> V_688 . V_243 = V_243 ;
break;
}
return 0 ;
}
static int F_347 ( struct V_2 * V_3 )
{
++ V_3 -> V_200 . V_689 ;
return 1 ;
}
static int F_348 ( struct V_2 * V_3 )
{
V_3 -> V_661 -> V_673 = V_690 ;
return 0 ;
}
static int F_349 ( struct V_2 * V_3 )
{
unsigned long V_691 ;
int V_398 , V_692 , string ;
unsigned V_693 ;
V_691 = F_81 ( V_679 ) ;
string = ( V_691 & 16 ) != 0 ;
V_692 = ( V_691 & 8 ) != 0 ;
++ V_3 -> V_200 . V_694 ;
if ( string || V_692 )
return F_334 ( V_3 , 0 ) == V_249 ;
V_693 = V_691 >> 16 ;
V_398 = ( V_691 & 7 ) + 1 ;
F_154 ( V_3 ) ;
return F_350 ( V_3 , V_398 , V_693 ) ;
}
static void
F_351 ( struct V_2 * V_3 , unsigned char * V_695 )
{
V_695 [ 0 ] = 0x0f ;
V_695 [ 1 ] = 0x01 ;
V_695 [ 2 ] = 0xc1 ;
}
static int F_352 ( struct V_2 * V_3 , unsigned long V_696 )
{
if ( F_1 ( V_3 ) -> V_8 . V_495 &&
( ( V_696 & F_187 ) != F_187 ) )
return 1 ;
if ( F_102 ( V_3 ) ) {
if ( F_353 ( V_3 , ( V_696 & V_3 -> V_100 . V_216 ) |
( V_3 -> V_100 . V_212 & ~ V_3 -> V_100 . V_216 ) ) )
return 1 ;
F_88 ( V_225 , V_696 ) ;
return 0 ;
} else
return F_353 ( V_3 , V_696 ) ;
}
static int F_354 ( struct V_2 * V_3 , unsigned long V_696 )
{
if ( F_102 ( V_3 ) ) {
if ( F_355 ( V_3 , ( V_696 & V_3 -> V_100 . V_468 ) |
( V_3 -> V_100 . V_469 & ~ V_3 -> V_100 . V_468 ) ) )
return 1 ;
F_88 ( V_434 , V_696 ) ;
return 0 ;
} else
return F_355 ( V_3 , V_696 ) ;
}
static void F_356 ( struct V_2 * V_3 )
{
if ( F_102 ( V_3 ) ) {
F_88 ( V_225 ,
F_81 ( V_225 ) & ~ V_214 ) ;
V_3 -> V_100 . V_212 &= ~ V_214 ;
} else
F_259 ( V_3 , F_143 ( V_3 , ~ V_214 ) ) ;
}
static int F_357 ( struct V_2 * V_3 )
{
unsigned long V_691 , V_696 ;
int V_697 ;
int V_362 ;
int V_698 ;
V_691 = F_81 ( V_679 ) ;
V_697 = V_691 & 15 ;
V_362 = ( V_691 >> 8 ) & 15 ;
switch ( ( V_691 >> 4 ) & 3 ) {
case 0 :
V_696 = F_358 ( V_3 , V_362 ) ;
F_359 ( V_697 , V_696 ) ;
switch ( V_697 ) {
case 0 :
V_698 = F_352 ( V_3 , V_696 ) ;
F_360 ( V_3 , V_698 ) ;
return 1 ;
case 3 :
V_698 = F_361 ( V_3 , V_696 ) ;
F_360 ( V_3 , V_698 ) ;
return 1 ;
case 4 :
V_698 = F_354 ( V_3 , V_696 ) ;
F_360 ( V_3 , V_698 ) ;
return 1 ;
case 8 : {
T_6 V_699 = F_362 ( V_3 ) ;
T_6 V_700 = F_358 ( V_3 , V_362 ) ;
V_698 = F_316 ( V_3 , V_700 ) ;
F_360 ( V_3 , V_698 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_699 <= V_700 )
return 1 ;
V_3 -> V_661 -> V_673 = V_701 ;
return 0 ;
}
}
break;
case 2 :
F_356 ( V_3 ) ;
F_359 ( 0 , F_320 ( V_3 ) ) ;
F_154 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_697 ) {
case 3 :
V_696 = F_261 ( V_3 ) ;
F_363 ( V_3 , V_362 , V_696 ) ;
F_364 ( V_697 , V_696 ) ;
F_154 ( V_3 ) ;
return 1 ;
case 8 :
V_696 = F_362 ( V_3 ) ;
F_363 ( V_3 , V_362 , V_696 ) ;
F_364 ( V_697 , V_696 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_696 = ( V_691 >> V_702 ) & 0x0f ;
F_359 ( 0 , ( F_320 ( V_3 ) & ~ 0xful ) | V_696 ) ;
F_365 ( V_3 , V_696 ) ;
F_154 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_661 -> V_673 = 0 ;
F_366 ( V_3 , L_20 ,
( int ) ( V_691 >> 4 ) & 3 , V_697 ) ;
return 0 ;
}
static int F_367 ( struct V_2 * V_3 )
{
unsigned long V_691 ;
int V_703 , V_362 ;
if ( ! F_368 ( V_3 , 0 ) )
return 1 ;
V_703 = F_81 ( V_683 ) ;
if ( V_703 & V_704 ) {
if ( V_3 -> V_116 & V_649 ) {
V_3 -> V_661 -> V_681 . V_100 . V_664 = V_3 -> V_100 . V_664 ;
V_3 -> V_661 -> V_681 . V_100 . V_682 = V_703 ;
V_3 -> V_661 -> V_681 . V_100 . V_685 =
F_81 ( V_606 ) +
F_81 ( V_367 ) ;
V_3 -> V_661 -> V_681 . V_100 . V_686 = V_115 ;
V_3 -> V_661 -> V_673 = V_684 ;
return 0 ;
} else {
V_3 -> V_100 . V_682 &= ~ V_704 ;
V_3 -> V_100 . V_664 |= V_705 ;
F_88 ( V_683 , V_3 -> V_100 . V_682 ) ;
F_336 ( V_3 , V_115 ) ;
return 1 ;
}
}
V_691 = F_81 ( V_679 ) ;
V_703 = V_691 & V_706 ;
V_362 = F_369 ( V_691 ) ;
if ( V_691 & V_707 ) {
unsigned long V_696 ;
if ( ! F_370 ( V_3 , V_703 , & V_696 ) )
F_363 ( V_3 , V_362 , V_696 ) ;
} else
F_371 ( V_3 , V_703 , V_3 -> V_100 . V_364 [ V_362 ] ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static void F_372 ( struct V_2 * V_3 , unsigned long V_696 )
{
F_88 ( V_683 , V_696 ) ;
}
static int F_373 ( struct V_2 * V_3 )
{
F_374 ( V_3 ) ;
return 1 ;
}
static int F_375 ( struct V_2 * V_3 )
{
T_2 V_285 = V_3 -> V_100 . V_364 [ V_708 ] ;
T_5 V_169 ;
if ( F_190 ( V_3 , V_285 , & V_169 ) ) {
F_376 ( V_285 ) ;
F_377 ( V_3 , 0 ) ;
return 1 ;
}
F_378 ( V_285 , V_169 ) ;
V_3 -> V_100 . V_364 [ V_709 ] = V_169 & - 1u ;
V_3 -> V_100 . V_364 [ V_601 ] = ( V_169 >> 32 ) & - 1u ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_379 ( struct V_2 * V_3 )
{
struct V_354 V_63 ;
T_2 V_285 = V_3 -> V_100 . V_364 [ V_708 ] ;
T_5 V_169 = ( V_3 -> V_100 . V_364 [ V_709 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_100 . V_364 [ V_601 ] & - 1u ) << 32 ) ;
V_63 . V_169 = V_169 ;
V_63 . V_68 = V_285 ;
V_63 . V_710 = false ;
if ( F_192 ( V_3 , & V_63 ) != 0 ) {
F_380 ( V_285 , V_169 ) ;
F_377 ( V_3 , 0 ) ;
return 1 ;
}
F_381 ( V_285 , V_169 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_382 ( struct V_2 * V_3 )
{
F_135 ( V_711 , V_3 ) ;
return 1 ;
}
static int F_383 ( struct V_2 * V_3 )
{
T_2 V_59 ;
V_59 = F_83 ( V_478 ) ;
V_59 &= ~ V_302 ;
F_91 ( V_478 , V_59 ) ;
F_135 ( V_711 , V_3 ) ;
++ V_3 -> V_200 . V_712 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_661 -> V_713 &&
! F_384 ( V_3 ) ) {
V_3 -> V_661 -> V_673 = V_714 ;
return 0 ;
}
return 1 ;
}
static int F_385 ( struct V_2 * V_3 )
{
F_154 ( V_3 ) ;
return F_335 ( V_3 ) ;
}
static int F_386 ( struct V_2 * V_3 )
{
F_154 ( V_3 ) ;
F_387 ( V_3 ) ;
return 1 ;
}
static int F_388 ( struct V_2 * V_3 )
{
return F_334 ( V_3 , 0 ) == V_249 ;
}
static int F_389 ( struct V_2 * V_3 )
{
unsigned long V_691 = F_81 ( V_679 ) ;
F_390 ( V_3 , V_691 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_391 ( struct V_2 * V_3 )
{
int V_698 ;
V_698 = F_392 ( V_3 ) ;
F_360 ( V_3 , V_698 ) ;
return 1 ;
}
static int F_393 ( struct V_2 * V_3 )
{
F_154 ( V_3 ) ;
F_394 ( V_3 ) ;
return 1 ;
}
static int F_395 ( struct V_2 * V_3 )
{
T_5 V_715 = F_396 ( V_3 ) ;
T_2 V_68 = F_358 ( V_3 , V_708 ) ;
if ( F_397 ( V_3 , V_68 , V_715 ) == 0 )
F_154 ( V_3 ) ;
return 1 ;
}
static int F_398 ( struct V_2 * V_3 )
{
if ( F_283 ( V_716 ) ) {
unsigned long V_691 = F_81 ( V_679 ) ;
int V_717 , V_279 ;
V_717 = V_691 & V_718 ;
V_279 = V_691 & V_719 ;
if ( ( V_717 == V_720 ) &&
( V_279 == V_721 ) ) {
F_399 ( V_3 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
}
return F_334 ( V_3 , 0 ) == V_249 ;
}
static int F_400 ( struct V_2 * V_3 )
{
unsigned long V_691 = F_81 ( V_679 ) ;
int V_722 = V_691 & 0xff ;
F_401 ( V_3 , V_722 ) ;
return 1 ;
}
static int F_402 ( struct V_2 * V_3 )
{
unsigned long V_691 = F_81 ( V_679 ) ;
T_2 V_279 = V_691 & 0xfff ;
F_403 ( V_3 , V_279 ) ;
return 1 ;
}
static int F_404 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
unsigned long V_691 ;
bool V_242 = false ;
T_2 V_243 = 0 ;
T_3 V_723 ;
int V_724 , type , V_725 , V_726 ;
V_725 = ( V_62 -> V_668 & V_640 ) ;
V_726 = ( V_62 -> V_668 & V_727 ) ;
type = ( V_62 -> V_668 & V_728 ) ;
V_691 = F_81 ( V_679 ) ;
V_724 = ( T_2 ) V_691 >> 30 ;
if ( V_724 == V_729 && V_725 ) {
switch ( type ) {
case V_635 :
V_3 -> V_100 . V_730 = false ;
F_329 ( V_3 , true ) ;
break;
case V_22 :
case V_630 :
F_405 ( V_3 ) ;
break;
case V_18 :
if ( V_62 -> V_668 &
V_731 ) {
V_242 = true ;
V_243 =
F_83 ( V_732 ) ;
}
case V_252 :
F_406 ( V_3 ) ;
break;
default:
break;
}
}
V_723 = V_691 ;
if ( ! V_725 || ( type != V_18 &&
type != V_22 &&
type != V_635 ) )
F_154 ( V_3 ) ;
if ( F_407 ( V_3 , V_723 ,
type == V_630 ? V_726 : - 1 , V_724 ,
V_242 , V_243 ) == V_733 ) {
V_3 -> V_661 -> V_673 = V_674 ;
V_3 -> V_661 -> V_675 . V_676 = V_734 ;
V_3 -> V_661 -> V_675 . V_678 = 0 ;
return 0 ;
}
F_88 ( V_683 , F_81 ( V_683 ) & ~ 55 ) ;
return 1 ;
}
static int F_408 ( struct V_2 * V_3 )
{
unsigned long V_691 ;
T_1 V_74 ;
T_2 V_243 ;
int V_735 ;
V_691 = F_81 ( V_679 ) ;
V_735 = ( V_691 >> 7 ) & 0x3 ;
if ( V_735 != 0x3 && V_735 != 0x1 && V_735 != 0 ) {
F_58 ( V_78 L_21 ) ;
F_58 ( V_78 L_22 ,
( long unsigned int ) F_84 ( V_736 ) ,
F_81 ( V_737 ) ) ;
F_58 ( V_78 L_23 ,
( long unsigned int ) V_691 ) ;
V_3 -> V_661 -> V_673 = V_738 ;
V_3 -> V_661 -> V_739 . V_740 = V_741 ;
return 0 ;
}
V_74 = F_84 ( V_736 ) ;
F_343 ( V_74 , V_691 ) ;
V_243 = V_691 & ( 1U << 1 ) ;
V_243 |= ( V_691 >> 3 ) & 0x1 ;
return F_346 ( V_3 , V_74 , V_243 , NULL , 0 ) ;
}
static T_5 F_409 ( T_5 V_742 , int V_743 )
{
int V_64 ;
T_5 V_94 = 0 ;
for ( V_64 = 51 ; V_64 > V_402 . V_744 ; V_64 -- )
V_94 |= ( 1ULL << V_64 ) ;
if ( V_743 > 2 )
V_94 |= 0xf8 ;
else if ( V_743 == 2 ) {
if ( V_742 & ( 1ULL << 7 ) )
V_94 |= 0x1ff000 ;
else
V_94 |= 0x78 ;
}
return V_94 ;
}
static void F_410 ( struct V_2 * V_3 , T_5 V_742 ,
int V_743 )
{
F_58 ( V_78 L_24 , V_462 , V_742 , V_743 ) ;
F_411 ( ( V_742 & 0x7 ) == 0x2 ) ;
F_411 ( ( V_742 & 0x7 ) == 0x6 ) ;
if ( ! F_27 () )
F_411 ( ( V_742 & 0x7 ) == 0x4 ) ;
if ( ( V_742 & 0x7 ) ) {
T_5 V_745 = V_742 & F_409 ( V_742 , V_743 ) ;
if ( V_745 != 0 ) {
F_58 ( V_78 L_25 ,
V_462 , V_745 ) ;
F_411 ( 1 ) ;
}
if ( V_743 == 1 || ( V_743 == 2 && ( V_742 & ( 1ULL << 7 ) ) ) ) {
T_5 V_746 = ( V_742 & 0x38 ) >> 3 ;
if ( V_746 == 2 || V_746 == 3 ||
V_746 == 7 ) {
F_58 ( V_78 L_26 ,
V_462 , V_746 ) ;
F_411 ( 1 ) ;
}
}
}
}
static int F_412 ( struct V_2 * V_3 )
{
T_5 V_747 [ 4 ] ;
int V_748 , V_64 , V_98 ;
T_1 V_74 ;
V_74 = F_84 ( V_736 ) ;
V_98 = F_413 ( V_3 , V_74 , true ) ;
if ( F_283 ( V_98 == 1 ) )
return F_414 ( V_3 , V_74 , 0 , NULL , 0 ) ==
V_249 ;
if ( F_89 ( ! V_98 ) )
return 1 ;
F_58 ( V_78 L_27 ) ;
F_58 ( V_78 L_28 , V_74 ) ;
V_748 = F_415 ( V_3 , V_74 , V_747 ) ;
for ( V_64 = V_749 ; V_64 > V_749 - V_748 ; -- V_64 )
F_410 ( V_3 , V_747 [ V_64 - 1 ] , V_64 ) ;
V_3 -> V_661 -> V_673 = V_738 ;
V_3 -> V_661 -> V_739 . V_740 = V_750 ;
return 0 ;
}
static int F_416 ( struct V_2 * V_3 )
{
T_2 V_59 ;
V_59 = F_83 ( V_478 ) ;
V_59 &= ~ V_624 ;
F_91 ( V_478 , V_59 ) ;
++ V_3 -> V_200 . V_751 ;
F_135 ( V_711 , V_3 ) ;
return 1 ;
}
static int F_417 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
enum V_666 V_698 = V_249 ;
int V_98 = 1 ;
T_2 V_752 ;
bool V_753 ;
unsigned V_754 = 130 ;
V_752 = F_83 ( V_478 ) ;
V_753 = V_752 & V_302 ;
while ( ! F_230 ( V_3 ) && V_754 -- != 0 ) {
if ( V_753 && F_330 ( V_3 ) )
return F_383 ( & V_62 -> V_3 ) ;
if ( F_149 ( V_711 , & V_3 -> V_755 ) )
return 1 ;
V_698 = F_334 ( V_3 , 0 ) ;
if ( V_698 == V_756 ) {
V_98 = 0 ;
goto V_500;
}
if ( V_698 != V_249 ) {
V_3 -> V_661 -> V_673 = V_674 ;
V_3 -> V_661 -> V_675 . V_676 = V_734 ;
V_3 -> V_661 -> V_675 . V_678 = 0 ;
return 0 ;
}
if ( F_418 ( V_757 ) )
goto V_500;
if ( F_419 () )
F_420 () ;
}
V_62 -> F_229 = F_229 ( V_3 ) ;
V_500:
return V_98 ;
}
static int F_421 ( struct V_2 * V_3 )
{
F_154 ( V_3 ) ;
F_422 ( V_3 ) ;
return 1 ;
}
static int F_423 ( struct V_2 * V_3 )
{
F_336 ( V_3 , V_21 ) ;
return 1 ;
}
static struct V_79 * F_424 ( struct V_1 * V_62 )
{
struct V_758 * V_759 ;
F_69 (item, &vmx->nested.vmcs02_pool, list)
if ( V_759 -> V_760 == V_62 -> V_8 . V_761 ) {
F_425 ( & V_759 -> V_762 , & V_62 -> V_8 . V_763 ) ;
return & V_759 -> V_764 ;
}
if ( V_62 -> V_8 . V_765 >= F_426 ( V_766 , 1 ) ) {
V_759 = F_427 ( V_62 -> V_8 . V_763 . V_767 ,
struct V_758 , V_762 ) ;
V_759 -> V_760 = V_62 -> V_8 . V_761 ;
F_425 ( & V_759 -> V_762 , & V_62 -> V_8 . V_763 ) ;
return & V_759 -> V_764 ;
}
V_759 = (struct V_758 * )
F_428 ( sizeof( struct V_758 ) , V_407 ) ;
if ( ! V_759 )
return NULL ;
V_759 -> V_764 . V_76 = F_217 () ;
if ( ! V_759 -> V_764 . V_76 ) {
F_429 ( V_759 ) ;
return NULL ;
}
F_59 ( & V_759 -> V_764 ) ;
V_759 -> V_760 = V_62 -> V_8 . V_761 ;
F_138 ( & ( V_759 -> V_762 ) , & ( V_62 -> V_8 . V_763 ) ) ;
V_62 -> V_8 . V_765 ++ ;
return & V_759 -> V_764 ;
}
static void F_430 ( struct V_1 * V_62 , T_1 V_760 )
{
struct V_758 * V_759 ;
F_69 (item, &vmx->nested.vmcs02_pool, list)
if ( V_759 -> V_760 == V_760 ) {
F_220 ( & V_759 -> V_764 ) ;
F_72 ( & V_759 -> V_762 ) ;
F_429 ( V_759 ) ;
V_62 -> V_8 . V_765 -- ;
return;
}
}
static void F_431 ( struct V_1 * V_62 )
{
struct V_758 * V_759 , * V_377 ;
F_207 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_62 -> V_79 != & V_759 -> V_764 )
F_220 ( & V_759 -> V_764 ) ;
F_72 ( & V_759 -> V_762 ) ;
F_429 ( V_759 ) ;
}
V_62 -> V_8 . V_765 = 0 ;
if ( V_62 -> V_79 != & V_62 -> V_768 )
F_220 ( & V_62 -> V_768 ) ;
}
static int F_432 ( struct V_2 * V_3 )
{
struct V_419 V_506 ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( ! F_433 ( V_3 , V_375 ) ||
! F_143 ( V_3 , V_483 ) ||
( F_148 ( V_3 ) & V_232 ) ) {
F_336 ( V_3 , V_21 ) ;
return 1 ;
}
F_234 ( V_3 , & V_506 , V_421 ) ;
if ( F_120 ( V_3 ) && ! V_506 . V_450 ) {
F_336 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_263 ( V_3 ) ) {
F_377 ( V_3 , 0 ) ;
return 1 ;
}
F_203 ( & ( V_62 -> V_8 . V_763 ) ) ;
V_62 -> V_8 . V_765 = 0 ;
V_62 -> V_8 . V_495 = true ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_434 ( struct V_2 * V_3 )
{
struct V_419 V_506 ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( ! V_62 -> V_8 . V_495 ) {
F_336 ( V_3 , V_21 ) ;
return 0 ;
}
F_234 ( V_3 , & V_506 , V_421 ) ;
if ( ( F_148 ( V_3 ) & V_232 ) ||
( F_120 ( V_3 ) && ! V_506 . V_450 ) ) {
F_336 ( V_3 , V_21 ) ;
return 0 ;
}
if ( F_263 ( V_3 ) ) {
F_377 ( V_3 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_435 ( struct V_1 * V_62 )
{
if ( ! V_62 -> V_8 . V_495 )
return;
V_62 -> V_8 . V_495 = false ;
if ( V_62 -> V_8 . V_761 != - 1ull ) {
F_436 ( V_62 -> V_8 . V_769 ) ;
F_8 ( V_62 -> V_8 . V_769 ) ;
V_62 -> V_8 . V_761 = - 1ull ;
V_62 -> V_8 . V_9 = NULL ;
}
if ( V_62 -> V_8 . V_535 ) {
F_8 ( V_62 -> V_8 . V_535 ) ;
V_62 -> V_8 . V_535 = 0 ;
}
F_431 ( V_62 ) ;
}
static int F_437 ( struct V_2 * V_3 )
{
if ( ! F_434 ( V_3 ) )
return 1 ;
F_435 ( F_1 ( V_3 ) ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_438 ( struct V_2 * V_3 ,
unsigned long V_691 ,
T_2 V_770 , T_4 * V_98 )
{
int V_771 = V_770 & 3 ;
int V_772 = ( V_770 >> 7 ) & 7 ;
bool V_773 = V_770 & ( 1u << 10 ) ;
int V_774 = ( V_770 >> 15 ) & 7 ;
int V_775 = ( V_770 >> 18 ) & 0xf ;
bool V_776 = ! ( V_770 & ( 1u << 22 ) ) ;
int V_777 = ( V_770 >> 23 ) & 0xf ;
bool V_778 = ! ( V_770 & ( 1u << 27 ) ) ;
if ( V_773 ) {
F_336 ( V_3 , V_21 ) ;
return 1 ;
}
* V_98 = F_262 ( V_3 , V_774 ) ;
if ( V_778 )
* V_98 += F_358 ( V_3 , V_777 ) ;
if ( V_776 )
* V_98 += F_358 ( V_3 , V_775 ) << V_771 ;
* V_98 += V_691 ;
if ( V_772 == 1 )
* V_98 &= 0xffffffff ;
return 0 ;
}
static void F_439 ( struct V_2 * V_3 )
{
F_151 ( V_3 , F_148 ( V_3 )
& ~ ( V_779 | V_780 | V_781 |
V_782 | V_783 | V_784 ) ) ;
}
static void F_440 ( struct V_2 * V_3 )
{
F_151 ( V_3 , ( F_148 ( V_3 )
& ~ ( V_780 | V_781 | V_782 |
V_783 | V_784 ) )
| V_779 ) ;
}
static void F_441 ( struct V_2 * V_3 ,
T_2 V_785 )
{
if ( F_1 ( V_3 ) -> V_8 . V_761 == - 1ull ) {
F_440 ( V_3 ) ;
return;
}
F_151 ( V_3 , ( F_148 ( V_3 )
& ~ ( V_779 | V_780 | V_781 |
V_783 | V_784 ) )
| V_782 ) ;
F_4 ( V_3 ) -> V_785 = V_785 ;
}
static int F_442 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_4 V_70 ;
T_1 V_760 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_786 V_787 ;
if ( ! F_434 ( V_3 ) )
return 1 ;
if ( F_438 ( V_3 , F_81 ( V_679 ) ,
F_83 ( V_788 ) , & V_70 ) )
return 1 ;
if ( F_443 ( & V_3 -> V_100 . V_789 , V_70 , & V_760 ,
sizeof( V_760 ) , & V_787 ) ) {
F_444 ( V_3 , & V_787 ) ;
return 1 ;
}
if ( ! F_445 ( V_760 , V_397 ) ) {
F_441 ( V_3 , V_790 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
if ( V_760 == V_62 -> V_8 . V_761 ) {
F_436 ( V_62 -> V_8 . V_769 ) ;
F_8 ( V_62 -> V_8 . V_769 ) ;
V_62 -> V_8 . V_761 = - 1ull ;
V_62 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_760 ) ;
if ( V_10 == NULL ) {
F_135 ( V_250 , V_3 ) ;
return 1 ;
}
V_7 = F_446 ( V_10 ) ;
V_7 -> V_791 = 0 ;
F_436 ( V_10 ) ;
F_8 ( V_10 ) ;
F_430 ( V_62 , V_760 ) ;
F_154 ( V_3 ) ;
F_439 ( V_3 ) ;
return 1 ;
}
static int F_447 ( struct V_2 * V_3 )
{
return F_448 ( V_3 , true ) ;
}
static int F_449 ( struct V_2 * V_3 )
{
return F_448 ( V_3 , false ) ;
}
static inline int F_450 ( unsigned long V_4 )
{
if ( 0x1 & V_4 )
return V_792 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_451 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_452 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_98 )
{
short V_279 = F_3 ( V_4 ) ;
char * V_103 ;
if ( V_279 < 0 )
return 0 ;
V_103 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_279 ;
switch ( F_450 ( V_4 ) ) {
case V_793 :
* V_98 = * ( ( V_794 * ) V_103 ) ;
return 1 ;
case V_795 :
* V_98 = * ( ( T_3 * ) V_103 ) ;
return 1 ;
case V_792 :
* V_98 = * ( ( T_2 * ) V_103 ) ;
return 1 ;
case V_796 :
* V_98 = * ( ( T_5 * ) V_103 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_453 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( V_62 -> V_8 . V_761 == - 1ull ) {
F_440 ( V_3 ) ;
F_154 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_454 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_797 ;
unsigned long V_691 = F_81 ( V_679 ) ;
T_2 V_770 = F_83 ( V_788 ) ;
T_4 V_70 = 0 ;
if ( ! F_434 ( V_3 ) ||
! F_453 ( V_3 ) )
return 1 ;
V_4 = F_358 ( V_3 , ( ( ( V_770 ) >> 28 ) & 0xf ) ) ;
if ( ! F_452 ( V_3 , V_4 , & V_797 ) ) {
F_441 ( V_3 , V_798 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
if ( V_770 & ( 1u << 10 ) ) {
F_363 ( V_3 , ( ( ( V_770 ) >> 3 ) & 0xf ) ,
V_797 ) ;
} else {
if ( F_438 ( V_3 , V_691 ,
V_770 , & V_70 ) )
return 1 ;
F_455 ( & V_3 -> V_100 . V_789 , V_70 ,
& V_797 , ( F_120 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_439 ( V_3 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_456 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_70 ;
unsigned long V_691 = F_81 ( V_679 ) ;
T_2 V_770 = F_83 ( V_788 ) ;
char * V_103 ;
short V_279 ;
T_5 V_797 = 0 ;
struct V_786 V_787 ;
if ( ! F_434 ( V_3 ) ||
! F_453 ( V_3 ) )
return 1 ;
if ( V_770 & ( 1u << 10 ) )
V_797 = F_358 ( V_3 ,
( ( ( V_770 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_438 ( V_3 , V_691 ,
V_770 , & V_70 ) )
return 1 ;
if ( F_443 ( & V_3 -> V_100 . V_789 , V_70 ,
& V_797 , ( F_120 ( V_3 ) ? 8 : 4 ) , & V_787 ) ) {
F_444 ( V_3 , & V_787 ) ;
return 1 ;
}
}
V_4 = F_358 ( V_3 , ( ( ( V_770 ) >> 28 ) & 0xf ) ) ;
if ( F_451 ( V_4 ) ) {
F_441 ( V_3 ,
V_799 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
V_279 = F_3 ( V_4 ) ;
if ( V_279 < 0 ) {
F_441 ( V_3 , V_798 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
V_103 = ( ( char * ) F_4 ( V_3 ) ) + V_279 ;
switch ( F_450 ( V_4 ) ) {
case V_795 :
* ( T_3 * ) V_103 = V_797 ;
break;
case V_792 :
* ( T_2 * ) V_103 = V_797 ;
break;
case V_796 :
* ( T_5 * ) V_103 = V_797 ;
break;
case V_793 :
* ( V_794 * ) V_103 = V_797 ;
break;
default:
F_441 ( V_3 , V_798 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
F_439 ( V_3 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_457 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_4 V_70 ;
T_1 V_760 ;
struct V_786 V_787 ;
if ( ! F_434 ( V_3 ) )
return 1 ;
if ( F_438 ( V_3 , F_81 ( V_679 ) ,
F_83 ( V_788 ) , & V_70 ) )
return 1 ;
if ( F_443 ( & V_3 -> V_100 . V_789 , V_70 , & V_760 ,
sizeof( V_760 ) , & V_787 ) ) {
F_444 ( V_3 , & V_787 ) ;
return 1 ;
}
if ( ! F_445 ( V_760 , V_397 ) ) {
F_441 ( V_3 , V_800 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
if ( V_62 -> V_8 . V_761 != V_760 ) {
struct V_7 * V_801 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_760 ) ;
if ( V_10 == NULL ) {
F_440 ( V_3 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
V_801 = F_446 ( V_10 ) ;
if ( V_801 -> V_400 != V_328 ) {
F_436 ( V_10 ) ;
F_10 ( V_10 ) ;
F_441 ( V_3 ,
V_802 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
if ( V_62 -> V_8 . V_761 != - 1ull ) {
F_436 ( V_62 -> V_8 . V_769 ) ;
F_8 ( V_62 -> V_8 . V_769 ) ;
}
V_62 -> V_8 . V_761 = V_760 ;
V_62 -> V_8 . V_9 = V_801 ;
V_62 -> V_8 . V_769 = V_10 ;
}
F_439 ( V_3 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static int F_458 ( struct V_2 * V_3 )
{
unsigned long V_691 = F_81 ( V_679 ) ;
T_2 V_770 = F_83 ( V_788 ) ;
T_4 V_803 ;
struct V_786 V_787 ;
if ( ! F_434 ( V_3 ) )
return 1 ;
if ( F_438 ( V_3 , V_691 ,
V_770 , & V_803 ) )
return 1 ;
if ( F_455 ( & V_3 -> V_100 . V_789 , V_803 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_761 ,
sizeof( T_5 ) , & V_787 ) ) {
F_444 ( V_3 , & V_787 ) ;
return 1 ;
}
F_439 ( V_3 ) ;
F_154 ( V_3 ) ;
return 1 ;
}
static bool F_459 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_673 )
{
T_2 V_322 = V_3 -> V_100 . V_364 [ V_708 ] ;
T_1 V_804 ;
if ( ! F_48 ( V_7 , V_26 ) )
return 1 ;
V_804 = V_7 -> V_257 ;
if ( V_673 == V_805 )
V_804 += 2048 ;
if ( V_322 >= 0xc0000000 ) {
V_322 -= 0xc0000000 ;
V_804 += 1024 ;
}
if ( V_322 < 1024 * 8 ) {
unsigned char V_806 ;
F_460 ( V_3 -> V_12 , V_804 + V_322 / 8 , & V_806 , 1 ) ;
return 1 & ( V_806 >> ( V_322 & 7 ) ) ;
} else
return 1 ;
}
static bool F_461 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_691 = F_81 ( V_679 ) ;
int V_697 = V_691 & 15 ;
int V_362 = ( V_691 >> 8 ) & 15 ;
unsigned long V_696 = F_358 ( V_3 , V_362 ) ;
switch ( ( V_691 >> 4 ) & 3 ) {
case 0 :
switch ( V_697 ) {
case 0 :
if ( V_7 -> V_217 &
( V_696 ^ V_7 -> V_221 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_807 >= 1 &&
V_7 -> V_808 == V_696 ) ||
( V_7 -> V_807 >= 2 &&
V_7 -> V_809 == V_696 ) ||
( V_7 -> V_807 >= 3 &&
V_7 -> V_810 == V_696 ) ||
( V_7 -> V_807 >= 4 &&
V_7 -> V_811 == V_696 ) )
return 0 ;
if ( F_48 ( V_7 , V_306 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_223 &
( V_7 -> V_224 ^ V_696 ) )
return 1 ;
break;
case 8 :
if ( F_48 ( V_7 , V_308 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_217 & V_214 ) &&
( V_7 -> V_221 & V_214 ) )
return 1 ;
break;
case 1 :
switch ( V_697 ) {
case 3 :
if ( V_7 -> V_59 &
V_307 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_59 &
V_309 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_217 & 0xe &
( V_696 ^ V_7 -> V_221 ) )
return 1 ;
if ( ( V_7 -> V_217 & 0x1 ) &&
! ( V_7 -> V_221 & 0x1 ) &&
( V_696 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_462 ( struct V_2 * V_3 )
{
T_2 V_673 = F_83 ( V_812 ) ;
T_2 V_14 = F_83 ( V_813 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_62 -> V_8 . V_638 )
return 0 ;
if ( F_89 ( V_62 -> V_814 ) ) {
F_463 ( L_29 , V_462 ,
F_83 ( V_93 ) ) ;
return 1 ;
}
switch ( V_673 ) {
case V_815 :
if ( ! F_51 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_90 ;
return V_7 -> V_123 &
( 1u << ( V_14 & V_16 ) ) ;
case V_642 :
return 0 ;
case V_816 :
return 1 ;
case V_817 :
case V_818 :
return 1 ;
case V_819 :
return 1 ;
case V_820 :
return 1 ;
case V_821 :
return F_48 ( V_7 , V_303 ) ;
case V_822 :
return 1 ;
case V_823 :
return F_48 ( V_7 , V_304 ) ;
case V_824 :
return F_48 ( V_7 , V_314 ) ;
case V_825 :
return F_48 ( V_7 , V_315 ) ;
case V_826 : case V_827 :
case V_828 : case V_829 :
case V_830 : case V_831 :
case V_832 : case V_833 :
case V_834 : case V_835 :
return 1 ;
case V_836 :
return F_461 ( V_3 , V_7 ) ;
case V_837 :
return F_48 ( V_7 , V_310 ) ;
case V_838 :
return 1 ;
case V_839 :
case V_805 :
return F_459 ( V_3 , V_7 , V_673 ) ;
case V_840 :
return 1 ;
case V_841 :
return F_48 ( V_7 , V_305 ) ;
case V_842 :
return F_48 ( V_7 , V_313 ) ;
case V_843 :
return F_48 ( V_7 , V_844 ) ||
F_49 ( V_7 ,
V_50 ) ;
case V_845 :
return 0 ;
case V_846 :
return 1 ;
case V_847 :
return F_49 ( V_7 ,
V_30 ) ;
case V_741 :
case V_750 :
return 0 ;
case V_848 :
return F_49 ( V_7 , V_57 ) ;
case V_849 :
return 1 ;
default:
return 1 ;
}
}
static void F_464 ( struct V_2 * V_3 , T_5 * V_850 , T_5 * V_851 )
{
* V_850 = F_81 ( V_679 ) ;
* V_851 = F_83 ( V_813 ) ;
}
static int F_465 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_2 V_673 = V_62 -> V_673 ;
T_2 V_852 = V_62 -> V_668 ;
if ( V_62 -> F_229 )
return F_417 ( V_3 ) ;
if ( V_62 -> V_8 . V_638 )
F_135 ( V_711 , V_3 ) ;
if ( ! F_102 ( V_3 ) && ( V_673 == V_828 ||
V_673 == V_832 ) )
V_62 -> V_8 . V_638 = 1 ;
else
V_62 -> V_8 . V_638 = 0 ;
if ( F_102 ( V_3 ) && F_462 ( V_3 ) ) {
F_158 ( V_3 ) ;
return 1 ;
}
if ( V_673 & V_853 ) {
V_3 -> V_661 -> V_673 = V_854 ;
V_3 -> V_661 -> V_855 . V_856
= V_673 ;
return 0 ;
}
if ( F_89 ( V_62 -> V_814 ) ) {
V_3 -> V_661 -> V_673 = V_854 ;
V_3 -> V_661 -> V_855 . V_856
= F_83 ( V_93 ) ;
return 0 ;
}
if ( ( V_852 & V_640 ) &&
( V_673 != V_815 &&
V_673 != V_741 &&
V_673 != V_819 ) ) {
V_3 -> V_661 -> V_673 = V_674 ;
V_3 -> V_661 -> V_675 . V_676 = V_857 ;
V_3 -> V_661 -> V_675 . V_678 = 2 ;
V_3 -> V_661 -> V_675 . V_169 [ 0 ] = V_852 ;
V_3 -> V_661 -> V_675 . V_169 [ 1 ] = V_673 ;
return 0 ;
}
if ( F_89 ( ! F_45 () && V_62 -> V_600 &&
! ( F_102 ( V_3 ) && F_50 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_330 ( V_3 ) ) {
V_62 -> V_600 = 0 ;
} else if ( V_62 -> V_631 > 1000000000LL &&
V_3 -> V_100 . V_858 ) {
F_58 ( V_152 L_30
L_31 ,
V_462 , V_3 -> V_859 ) ;
V_62 -> V_600 = 0 ;
}
}
if ( V_673 < V_860
&& V_861 [ V_673 ] )
return V_861 [ V_673 ] ( V_3 ) ;
else {
V_3 -> V_661 -> V_673 = V_738 ;
V_3 -> V_661 -> V_739 . V_740 = V_673 ;
}
return 0 ;
}
static void V_414 ( struct V_2 * V_3 , int V_862 , int V_863 )
{
if ( V_863 == - 1 || V_862 < V_863 ) {
F_91 ( V_617 , 0 ) ;
return;
}
F_91 ( V_617 , V_863 ) ;
}
static void F_466 ( struct V_2 * V_3 , bool V_864 )
{
T_2 V_865 ;
if ( ! F_23 () ||
! F_307 ( V_3 -> V_12 ) )
return;
if ( ! F_19 ( V_3 -> V_12 ) )
return;
V_865 = F_83 ( V_578 ) ;
if ( V_864 ) {
V_865 &= ~ V_30 ;
V_865 |= V_31 ;
} else {
V_865 &= ~ V_31 ;
V_865 |= V_30 ;
}
F_91 ( V_578 , V_865 ) ;
F_165 ( V_3 ) ;
}
static void F_467 ( struct V_12 * V_12 , int V_866 )
{
T_3 V_867 ;
T_6 V_373 ;
if ( ! F_307 ( V_12 ) )
return;
if ( V_866 == - 1 )
V_866 = 0 ;
V_867 = F_82 ( V_583 ) ;
V_373 = V_867 >> 8 ;
if ( V_866 != V_373 ) {
V_867 &= 0xff ;
V_867 |= V_866 << 8 ;
F_90 ( V_583 , V_867 ) ;
}
}
static void F_468 ( int V_722 )
{
T_3 V_867 ;
T_6 V_373 ;
V_867 = F_82 ( V_583 ) ;
V_373 = ( T_6 ) V_867 & 0xff ;
if ( ( T_6 ) V_722 != V_373 ) {
V_867 &= ~ 0xff ;
V_867 |= ( T_6 ) V_722 ;
F_90 ( V_583 , V_867 ) ;
}
}
static void F_469 ( struct V_2 * V_3 , int V_868 )
{
if ( V_868 == - 1 )
return;
F_468 ( V_868 ) ;
}
static void F_470 ( struct V_2 * V_3 , T_5 * V_869 )
{
F_92 ( V_579 , V_869 [ 0 ] ) ;
F_92 ( V_580 , V_869 [ 1 ] ) ;
F_92 ( V_581 , V_869 [ 2 ] ) ;
F_92 ( V_582 , V_869 [ 3 ] ) ;
}
static void F_471 ( struct V_1 * V_62 )
{
T_2 V_669 ;
if ( ! ( V_62 -> V_673 == V_845
|| V_62 -> V_673 == V_815 ) )
return;
V_62 -> V_669 = F_83 ( V_813 ) ;
V_669 = V_62 -> V_669 ;
if ( F_16 ( V_669 ) )
F_337 () ;
if ( ( V_669 & V_15 ) == V_635 &&
( V_669 & V_17 ) ) {
F_472 ( & V_62 -> V_3 ) ;
asm("int $2");
F_473 ( & V_62 -> V_3 ) ;
}
}
static void F_474 ( struct V_1 * V_62 )
{
T_2 V_669 ;
bool V_870 ;
T_6 V_722 ;
bool V_871 ;
V_871 = V_62 -> V_668 & V_640 ;
if ( F_45 () ) {
if ( V_62 -> V_633 )
return;
V_669 = F_83 ( V_813 ) ;
V_870 = ( V_669 & V_872 ) != 0 ;
V_722 = V_669 & V_16 ;
if ( ( V_669 & V_17 ) && V_870 &&
V_722 != V_653 && ! V_871 )
F_94 ( V_234 ,
V_636 ) ;
else
V_62 -> V_633 =
! ( F_83 ( V_234 )
& V_636 ) ;
} else if ( F_89 ( V_62 -> V_600 ) )
V_62 -> V_631 +=
F_475 ( F_476 ( F_477 () , V_62 -> V_873 ) ) ;
}
static void F_478 ( struct V_1 * V_62 ,
T_2 V_668 ,
int V_874 ,
int V_875 )
{
T_6 V_722 ;
int type ;
bool V_871 ;
V_871 = V_668 & V_640 ;
V_62 -> V_3 . V_100 . V_730 = false ;
F_406 ( & V_62 -> V_3 ) ;
F_405 ( & V_62 -> V_3 ) ;
if ( ! V_871 )
return;
F_135 ( V_711 , & V_62 -> V_3 ) ;
V_722 = V_668 & V_727 ;
type = V_668 & V_728 ;
switch ( type ) {
case V_635 :
V_62 -> V_3 . V_100 . V_730 = true ;
F_329 ( & V_62 -> V_3 , false ) ;
break;
case V_252 :
V_62 -> V_3 . V_100 . V_248 =
F_83 ( V_874 ) ;
case V_18 :
if ( V_668 & V_731 ) {
T_2 V_698 = F_83 ( V_875 ) ;
F_186 ( & V_62 -> V_3 , V_722 , V_698 ) ;
} else
F_336 ( & V_62 -> V_3 , V_722 ) ;
break;
case V_630 :
V_62 -> V_3 . V_100 . V_248 =
F_83 ( V_874 ) ;
case V_22 :
F_479 ( & V_62 -> V_3 , V_722 ,
type == V_630 ) ;
break;
default:
break;
}
}
static void F_480 ( struct V_1 * V_62 )
{
if ( F_102 ( & V_62 -> V_3 ) )
return;
F_478 ( V_62 , V_62 -> V_668 ,
V_241 ,
V_732 ) ;
}
static void F_481 ( struct V_2 * V_3 )
{
if ( F_102 ( V_3 ) )
return;
F_478 ( F_1 ( V_3 ) ,
F_83 ( V_253 ) ,
V_251 ,
V_245 ) ;
F_91 ( V_253 , 0 ) ;
}
static void F_482 ( struct V_1 * V_62 )
{
int V_64 , V_876 ;
struct V_877 * V_878 ;
V_878 = F_483 ( & V_876 ) ;
if ( ! V_878 )
return;
for ( V_64 = 0 ; V_64 < V_876 ; V_64 ++ )
if ( V_878 [ V_64 ] . V_140 == V_878 [ V_64 ] . V_139 )
F_104 ( V_62 , V_878 [ V_64 ] . V_63 ) ;
else
F_106 ( V_62 , V_878 [ V_64 ] . V_63 , V_878 [ V_64 ] . V_139 ,
V_878 [ V_64 ] . V_140 ) ;
}
static void T_16 F_484 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
unsigned long V_879 ;
if ( F_102 ( V_3 ) && ! V_62 -> V_8 . V_638 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_639 &
V_640 ) {
F_91 ( V_253 ,
V_7 -> V_639 ) ;
F_91 ( V_251 ,
V_7 -> V_880 ) ;
if ( V_7 -> V_639 &
V_731 )
F_91 ( V_245 ,
V_7 -> V_881 ) ;
}
}
if ( F_89 ( ! F_45 () && V_62 -> V_600 ) )
V_62 -> V_873 = F_477 () ;
if ( V_62 -> F_229 )
return;
if ( F_149 ( V_363 , ( unsigned long * ) & V_3 -> V_100 . V_470 ) )
F_88 ( V_365 , V_3 -> V_100 . V_364 [ V_363 ] ) ;
if ( F_149 ( V_366 , ( unsigned long * ) & V_3 -> V_100 . V_470 ) )
F_88 ( V_367 , V_3 -> V_100 . V_364 [ V_366 ] ) ;
if ( V_3 -> V_116 & V_648 )
F_153 ( V_3 , 0 ) ;
F_482 ( V_62 ) ;
V_879 = F_485 () ;
V_62 -> V_882 = V_62 -> V_79 -> V_81 ;
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
#ifdef F_85
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
#ifdef F_85
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
#ifdef F_85
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
#ifdef F_85
, "rax", "rbx", "rdi", "rsi"
, "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
#else
, "eax", "ebx", "edi", "esi"
#endif
);
if ( V_879 )
F_486 ( V_879 ) ;
#ifndef F_85
F_126 ( V_188 , V_883 ) ;
F_126 ( V_190 , V_883 ) ;
#endif
V_3 -> V_100 . V_101 = ~ ( ( 1 << V_366 ) | ( 1 << V_363 )
| ( 1 << V_228 )
| ( 1 << V_435 )
| ( 1 << V_368 )
| ( 1 << V_102 )
| ( 1 << V_467 ) ) ;
V_3 -> V_100 . V_470 = 0 ;
V_62 -> V_668 = F_83 ( V_884 ) ;
if ( F_102 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_639 = V_62 -> V_668 ;
if ( V_62 -> V_668 & V_640 ) {
V_7 -> V_881 =
F_83 ( V_732 ) ;
V_7 -> V_880 =
F_83 ( V_241 ) ;
}
}
V_62 -> V_79 -> V_81 = 1 ;
V_62 -> V_673 = F_83 ( V_812 ) ;
F_487 ( V_62 -> V_673 , V_3 , V_885 ) ;
F_471 ( V_62 ) ;
F_474 ( V_62 ) ;
F_480 ( V_62 ) ;
}
static void F_488 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
F_294 ( V_62 ) ;
F_435 ( V_62 ) ;
F_220 ( V_62 -> V_79 ) ;
F_429 ( V_62 -> V_67 ) ;
F_489 ( V_3 ) ;
F_490 ( V_886 , V_62 ) ;
}
static struct V_2 * F_491 ( struct V_12 * V_12 , unsigned int V_887 )
{
int V_698 ;
struct V_1 * V_62 = F_492 ( V_886 , V_407 ) ;
int V_80 ;
if ( ! V_62 )
return F_493 ( - V_408 ) ;
F_290 ( V_62 ) ;
V_698 = F_494 ( & V_62 -> V_3 , V_12 , V_887 ) ;
if ( V_698 )
goto V_888;
V_62 -> V_67 = F_428 ( V_397 , V_407 ) ;
V_698 = - V_408 ;
if ( ! V_62 -> V_67 ) {
goto V_889;
}
V_62 -> V_79 = & V_62 -> V_768 ;
V_62 -> V_79 -> V_76 = F_217 () ;
if ( ! V_62 -> V_79 -> V_76 )
goto V_890;
if ( ! V_204 )
F_134 ( F_57 ( F_71 ( V_203 , F_68 () ) ) ) ;
F_59 ( V_62 -> V_79 ) ;
if ( ! V_204 )
F_141 () ;
V_80 = F_495 () ;
F_133 ( & V_62 -> V_3 , V_80 ) ;
V_62 -> V_3 . V_80 = V_80 ;
V_698 = F_311 ( V_62 ) ;
F_140 ( & V_62 -> V_3 ) ;
F_496 () ;
if ( V_698 )
goto F_218;
if ( F_41 ( V_12 ) )
V_698 = F_285 ( V_12 ) ;
if ( V_698 )
goto F_218;
if ( V_90 ) {
if ( ! V_12 -> V_100 . V_491 )
V_12 -> V_100 . V_491 =
V_891 ;
V_698 = - V_408 ;
if ( F_289 ( V_12 ) != 0 )
goto F_218;
if ( ! F_282 ( V_12 ) )
goto F_218;
}
V_62 -> V_8 . V_761 = - 1ull ;
V_62 -> V_8 . V_9 = NULL ;
return & V_62 -> V_3 ;
F_218:
F_220 ( V_62 -> V_79 ) ;
V_890:
F_429 ( V_62 -> V_67 ) ;
V_889:
F_489 ( & V_62 -> V_3 ) ;
V_888:
F_294 ( V_62 ) ;
F_490 ( V_886 , V_62 ) ;
return F_493 ( V_698 ) ;
}
static void T_11 F_497 ( void * V_892 )
{
struct V_24 V_385 ;
* ( int * ) V_892 = 0 ;
if ( F_211 ( & V_385 ) < 0 )
* ( int * ) V_892 = - V_384 ;
if ( memcmp ( & V_24 , & V_385 , sizeof( struct V_24 ) ) != 0 ) {
F_58 ( V_78 L_32 ,
F_498 () ) ;
* ( int * ) V_892 = - V_384 ;
}
}
static int F_499 ( void )
{
return V_485 + 1 ;
}
static T_5 F_500 ( struct V_2 * V_3 , T_13 V_893 , bool V_894 )
{
T_5 V_98 ;
if ( V_894 )
V_98 = V_895 << V_896 ;
else if ( V_3 -> V_12 -> V_100 . V_897 &&
! ( V_3 -> V_12 -> V_100 . V_898 & V_899 ) )
V_98 = F_501 ( V_3 , V_893 ) <<
V_896 ;
else
V_98 = ( V_900 << V_896 )
| V_901 ;
return V_98 ;
}
static int F_502 ( void )
{
if ( V_90 && ! F_31 () )
return V_902 ;
else
return V_903 ;
}
static void F_503 ( struct V_2 * V_3 )
{
struct V_283 * V_284 ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_2 V_570 ;
V_62 -> V_268 = false ;
if ( F_162 () ) {
V_570 = F_83 ( V_578 ) ;
if ( V_570 & V_53 ) {
V_284 = F_179 ( V_3 , 0x80000001 , 0 ) ;
if ( V_284 && ( V_284 -> V_904 & V_58 ( V_905 ) ) )
V_62 -> V_268 = true ;
else {
V_570 &= ~ V_53 ;
F_91 ( V_578 ,
V_570 ) ;
}
}
}
V_284 = F_179 ( V_3 , 0x7 , 0 ) ;
if ( F_163 () &&
V_284 && ( V_284 -> V_906 & V_58 ( V_907 ) ) &&
F_504 ( V_3 ) ) {
V_570 = F_83 ( V_578 ) ;
V_570 |= V_54 ;
F_91 ( V_578 ,
V_570 ) ;
} else {
if ( F_21 () ) {
V_570 = F_83 ( V_578 ) ;
V_570 &= ~ V_54 ;
F_91 ( V_578 ,
V_570 ) ;
}
if ( V_284 )
V_284 -> V_906 &= ~ V_58 ( V_907 ) ;
}
}
static void F_505 ( T_2 V_908 , struct V_283 * V_125 )
{
if ( V_908 == 1 && V_8 )
V_125 -> V_285 |= V_58 ( V_286 ) ;
}
static void F_506 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
T_2 V_570 ;
F_90 ( V_909 , V_7 -> V_910 ) ;
F_90 ( V_604 , V_7 -> V_911 ) ;
F_90 ( V_912 , V_7 -> V_913 ) ;
F_90 ( V_914 , V_7 -> V_915 ) ;
F_90 ( V_916 , V_7 -> V_917 ) ;
F_90 ( V_918 , V_7 -> V_919 ) ;
F_90 ( V_608 , V_7 -> V_920 ) ;
F_90 ( V_607 , V_7 -> V_921 ) ;
F_91 ( V_922 , V_7 -> V_923 ) ;
F_91 ( V_924 , V_7 -> V_925 ) ;
F_91 ( V_926 , V_7 -> V_927 ) ;
F_91 ( V_928 , V_7 -> V_929 ) ;
F_91 ( V_930 , V_7 -> V_931 ) ;
F_91 ( V_932 , V_7 -> V_933 ) ;
F_91 ( V_610 , V_7 -> V_934 ) ;
F_91 ( V_456 , V_7 -> V_935 ) ;
F_91 ( V_504 , V_7 -> V_936 ) ;
F_91 ( V_502 , V_7 -> V_937 ) ;
F_91 ( V_938 , V_7 -> V_939 ) ;
F_91 ( V_940 , V_7 -> V_941 ) ;
F_91 ( V_942 , V_7 -> V_943 ) ;
F_91 ( V_944 , V_7 -> V_945 ) ;
F_91 ( V_946 , V_7 -> V_947 ) ;
F_91 ( V_948 , V_7 -> V_949 ) ;
F_91 ( V_611 , V_7 -> V_950 ) ;
F_91 ( V_458 , V_7 -> V_951 ) ;
F_88 ( V_952 , V_7 -> V_953 ) ;
F_88 ( V_606 , V_7 -> V_954 ) ;
F_88 ( V_955 , V_7 -> V_956 ) ;
F_88 ( V_957 , V_7 -> V_958 ) ;
F_88 ( V_346 , V_7 -> V_959 ) ;
F_88 ( V_347 , V_7 -> V_960 ) ;
F_88 ( V_609 , V_7 -> V_961 ) ;
F_88 ( V_455 , V_7 -> V_962 ) ;
F_88 ( V_505 , V_7 -> V_963 ) ;
F_88 ( V_503 , V_7 -> V_964 ) ;
F_92 ( V_615 , V_7 -> V_965 ) ;
F_91 ( V_253 ,
V_7 -> V_966 ) ;
F_91 ( V_245 ,
V_7 -> V_967 ) ;
F_91 ( V_251 ,
V_7 -> V_968 ) ;
F_91 ( V_234 ,
V_7 -> V_969 ) ;
F_91 ( V_612 , V_7 -> V_970 ) ;
F_91 ( V_350 , V_7 -> V_971 ) ;
F_88 ( V_683 , V_7 -> V_972 ) ;
F_88 ( V_229 , V_7 -> V_973 ) ;
F_88 ( V_614 ,
V_7 -> V_974 ) ;
F_88 ( V_353 , V_7 -> V_975 ) ;
F_88 ( V_352 , V_7 -> V_976 ) ;
F_92 ( V_576 , - 1ull ) ;
F_91 ( V_577 ,
( V_24 . V_55 |
V_7 -> V_61 ) ) ;
F_91 ( V_587 ,
V_90 ? V_7 -> V_977 : 0 ) ;
F_91 ( V_588 ,
V_90 ? V_7 -> V_978 : 0 ) ;
if ( F_21 () ) {
T_2 V_570 = F_308 ( V_62 ) ;
if ( ! V_62 -> V_268 )
V_570 &= ~ V_53 ;
V_570 &= ~ V_30 ;
if ( F_48 ( V_7 ,
V_28 ) )
V_570 |= V_7 -> V_60 ;
if ( V_570 & V_30 ) {
if ( V_62 -> V_8 . V_535 )
F_8 ( V_62 -> V_8 . V_535 ) ;
V_62 -> V_8 . V_535 =
F_5 ( V_3 , V_7 -> V_979 ) ;
if ( ! V_62 -> V_8 . V_535 )
V_570 &=
~ V_30 ;
else
F_92 ( V_618 ,
F_319 ( V_62 -> V_8 . V_535 ) ) ;
}
F_91 ( V_578 , V_570 ) ;
}
F_301 () ;
V_62 -> V_980 = 0 ;
V_570 = F_306 ( V_62 ) ;
V_570 &= ~ V_302 ;
V_570 &= ~ V_624 ;
V_570 &= ~ V_27 ;
V_570 |= V_7 -> V_59 ;
V_570 &= ~ V_26 ;
V_570 &= ~ V_312 ;
V_570 |= V_311 ;
F_91 ( V_478 , V_570 ) ;
F_101 ( V_3 ) ;
V_3 -> V_100 . V_216 &= ~ V_7 -> V_217 ;
F_88 ( V_218 , ~ V_3 -> V_100 . V_216 ) ;
F_91 ( V_127 ,
V_7 -> V_981 | V_24 . V_401 ) ;
F_91 ( V_126 , V_7 -> V_982 |
( V_24 . V_357 & ~ V_298 ) ) ;
if ( V_7 -> V_982 & V_297 )
F_92 ( V_358 , V_7 -> V_983 ) ;
else if ( V_24 . V_357 & V_297 )
F_92 ( V_358 , V_62 -> V_3 . V_100 . V_359 ) ;
F_305 ( V_62 ) ;
if ( V_7 -> V_59 & V_280 )
F_92 ( V_272 ,
V_62 -> V_8 . V_273 + V_7 -> V_271 ) ;
else
F_92 ( V_272 , V_62 -> V_8 . V_273 ) ;
if ( V_410 ) {
F_90 ( V_619 , V_62 -> V_45 ) ;
F_248 ( V_3 ) ;
}
if ( V_7 -> V_982 & V_132 )
V_3 -> V_100 . V_163 = V_7 -> V_984 ;
if ( V_7 -> V_982 & V_298 )
V_3 -> V_100 . V_163 |= ( V_166 | V_167 ) ;
else
V_3 -> V_100 . V_163 &= ~ ( V_166 | V_167 ) ;
F_244 ( V_3 , V_3 -> V_100 . V_163 ) ;
F_259 ( V_3 , V_7 -> V_220 ) ;
F_88 ( V_225 , F_144 ( V_7 ) ) ;
F_257 ( V_3 , V_7 -> V_222 ) ;
F_88 ( V_434 , F_145 ( V_7 ) ) ;
F_361 ( V_3 , V_7 -> V_489 ) ;
F_243 ( V_3 ) ;
F_363 ( V_3 , V_363 , V_7 -> V_985 ) ;
F_363 ( V_3 , V_366 , V_7 -> V_986 ) ;
}
static int F_448 ( struct V_2 * V_3 , bool V_987 )
{
struct V_7 * V_7 ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
int V_80 ;
struct V_79 * V_764 ;
if ( ! F_434 ( V_3 ) ||
! F_453 ( V_3 ) )
return 1 ;
F_154 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_791 == V_987 ) {
F_441 ( V_3 ,
V_987 ? V_988
: V_989 ) ;
return 1 ;
}
if ( ( V_7 -> V_59 & V_26 ) &&
! F_445 ( V_7 -> V_257 , V_397 ) ) {
F_441 ( V_3 , V_990 ) ;
return 1 ;
}
if ( F_49 ( V_7 , V_30 ) &&
! F_445 ( V_7 -> V_979 , V_397 ) ) {
F_441 ( V_3 , V_990 ) ;
return 1 ;
}
if ( V_7 -> V_991 > 0 ||
V_7 -> V_992 > 0 ||
V_7 -> V_993 > 0 ) {
F_507 ( L_33 ,
V_462 ) ;
F_441 ( V_3 , V_990 ) ;
return 1 ;
}
if ( ! F_183 ( V_7 -> V_59 ,
V_300 , V_301 ) ||
! F_183 ( V_7 -> V_60 ,
V_317 , V_318 ) ||
! F_183 ( V_7 -> V_61 ,
V_287 , V_288 ) ||
! F_183 ( V_7 -> V_981 ,
V_291 , V_292 ) ||
! F_183 ( V_7 -> V_982 ,
V_295 , V_296 ) )
{
F_441 ( V_3 , V_990 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_994 & F_187 ) != F_187 ) ||
( ( V_7 -> V_995 & F_188 ) != F_188 ) ) {
F_441 ( V_3 ,
V_996 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_220 & F_187 ) != F_187 ) ||
( ( V_7 -> V_222 & F_188 ) != F_188 ) ) {
F_508 ( V_3 , V_7 ,
V_840 , V_997 ) ;
return 1 ;
}
if ( V_7 -> V_998 != - 1ull ) {
F_508 ( V_3 , V_7 ,
V_840 , V_999 ) ;
return 1 ;
}
V_764 = F_424 ( V_62 ) ;
if ( ! V_764 )
return - V_408 ;
F_509 ( V_3 ) ;
V_62 -> V_8 . V_273 = F_84 ( V_272 ) ;
V_80 = F_495 () ;
V_62 -> V_79 = V_764 ;
F_140 ( V_3 ) ;
F_133 ( V_3 , V_80 ) ;
V_3 -> V_80 = V_80 ;
F_496 () ;
V_7 -> V_791 = 1 ;
F_506 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_510 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_81 ( V_213 ) & V_3 -> V_100 . V_216 ) |
( V_7 -> V_220 & V_7 -> V_217 ) |
( F_81 ( V_225 ) & ~ ( V_7 -> V_217 |
V_3 -> V_100 . V_216 ) ) ;
}
static inline unsigned long
F_511 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_81 ( V_432 ) & V_3 -> V_100 . V_468 ) |
( V_7 -> V_222 & V_7 -> V_223 ) |
( F_81 ( V_434 ) & ~ ( V_7 -> V_223 |
V_3 -> V_100 . V_468 ) ) ;
}
void F_512 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_220 = F_510 ( V_3 , V_7 ) ;
V_7 -> V_222 = F_511 ( V_3 , V_7 ) ;
F_370 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_972 ) ;
V_7 -> V_985 = F_358 ( V_3 , V_363 ) ;
V_7 -> V_986 = F_358 ( V_3 , V_366 ) ;
V_7 -> V_973 = F_81 ( V_229 ) ;
V_7 -> V_910 = F_82 ( V_909 ) ;
V_7 -> V_911 = F_82 ( V_604 ) ;
V_7 -> V_913 = F_82 ( V_912 ) ;
V_7 -> V_915 = F_82 ( V_914 ) ;
V_7 -> V_917 = F_82 ( V_916 ) ;
V_7 -> V_919 = F_82 ( V_918 ) ;
V_7 -> V_920 = F_82 ( V_608 ) ;
V_7 -> V_921 = F_82 ( V_607 ) ;
V_7 -> V_923 = F_83 ( V_922 ) ;
V_7 -> V_925 = F_83 ( V_924 ) ;
V_7 -> V_927 = F_83 ( V_926 ) ;
V_7 -> V_929 = F_83 ( V_928 ) ;
V_7 -> V_931 = F_83 ( V_930 ) ;
V_7 -> V_933 = F_83 ( V_932 ) ;
V_7 -> V_934 = F_83 ( V_610 ) ;
V_7 -> V_935 = F_83 ( V_456 ) ;
V_7 -> V_936 = F_83 ( V_504 ) ;
V_7 -> V_937 = F_83 ( V_502 ) ;
V_7 -> V_939 = F_83 ( V_938 ) ;
V_7 -> V_941 = F_83 ( V_940 ) ;
V_7 -> V_943 = F_83 ( V_942 ) ;
V_7 -> V_945 = F_83 ( V_944 ) ;
V_7 -> V_947 = F_83 ( V_946 ) ;
V_7 -> V_949 = F_83 ( V_948 ) ;
V_7 -> V_950 = F_83 ( V_611 ) ;
V_7 -> V_951 = F_83 ( V_458 ) ;
V_7 -> V_953 = F_81 ( V_952 ) ;
V_7 -> V_954 = F_81 ( V_606 ) ;
V_7 -> V_956 = F_81 ( V_955 ) ;
V_7 -> V_958 = F_81 ( V_957 ) ;
V_7 -> V_959 = F_81 ( V_346 ) ;
V_7 -> V_960 = F_81 ( V_347 ) ;
V_7 -> V_961 = F_81 ( V_609 ) ;
V_7 -> V_962 = F_81 ( V_455 ) ;
V_7 -> V_963 = F_81 ( V_505 ) ;
V_7 -> V_964 = F_81 ( V_503 ) ;
V_7 -> V_970 = F_83 ( V_612 ) ;
V_7 -> V_969 =
F_83 ( V_234 ) ;
V_7 -> V_974 =
F_81 ( V_614 ) ;
V_7 -> V_965 = F_84 ( V_615 ) ;
if ( V_7 -> V_982 & V_395 )
V_7 -> V_983 = F_84 ( V_358 ) ;
V_7 -> V_971 = F_83 ( V_350 ) ;
V_7 -> V_975 = F_81 ( V_353 ) ;
V_7 -> V_976 = F_81 ( V_352 ) ;
V_7 -> V_641 = F_83 ( V_812 ) ;
V_7 -> V_691 = F_81 ( V_679 ) ;
V_7 -> V_643 = F_83 ( V_813 ) ;
V_7 -> V_1000 = F_83 ( V_671 ) ;
V_7 -> V_639 =
F_83 ( V_884 ) ;
V_7 -> V_881 =
F_83 ( V_732 ) ;
V_7 -> V_880 = F_83 ( V_241 ) ;
V_7 -> V_770 = F_83 ( V_788 ) ;
if ( ! ( V_7 -> V_641 & V_853 ) )
V_7 -> V_966 &= ~ V_17 ;
}
void F_513 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_981 & V_133 )
V_3 -> V_100 . V_163 = V_7 -> V_1001 ;
if ( V_7 -> V_981 & V_293 )
V_3 -> V_100 . V_163 |= ( V_166 | V_167 ) ;
else
V_3 -> V_100 . V_163 &= ~ ( V_166 | V_167 ) ;
F_244 ( V_3 , V_3 -> V_100 . V_163 ) ;
F_363 ( V_3 , V_363 , V_7 -> V_980 ) ;
F_363 ( V_3 , V_366 , V_7 -> V_1002 ) ;
F_353 ( V_3 , V_7 -> V_994 ) ;
F_101 ( V_3 ) ;
V_3 -> V_100 . V_216 = ( V_3 -> V_122 ? V_214 : 0 ) ;
F_88 ( V_218 , ~ V_3 -> V_100 . V_216 ) ;
V_3 -> V_100 . V_468 = ~ F_81 ( V_569 ) ;
F_355 ( V_3 , V_7 -> V_995 ) ;
F_361 ( V_3 , V_7 -> V_1003 ) ;
F_243 ( V_3 ) ;
if ( V_410 ) {
F_248 ( V_3 ) ;
}
F_91 ( V_350 , V_7 -> V_1004 ) ;
F_88 ( V_353 , V_7 -> V_1005 ) ;
F_88 ( V_352 , V_7 -> V_1006 ) ;
F_88 ( V_503 , V_7 -> V_1007 ) ;
F_88 ( V_505 , V_7 -> V_1008 ) ;
F_88 ( V_455 , V_7 -> V_1009 ) ;
F_88 ( V_347 , V_7 -> V_1010 ) ;
F_88 ( V_346 , V_7 -> V_1011 ) ;
F_90 ( V_909 , V_7 -> V_1012 ) ;
F_90 ( V_604 , V_7 -> V_1013 ) ;
F_90 ( V_912 , V_7 -> V_1014 ) ;
F_90 ( V_914 , V_7 -> V_1015 ) ;
F_90 ( V_916 , V_7 -> V_1016 ) ;
F_90 ( V_918 , V_7 -> V_1017 ) ;
F_90 ( V_607 , V_7 -> V_1018 ) ;
if ( V_7 -> V_981 & V_396 )
F_92 ( V_358 , V_7 -> V_1019 ) ;
if ( V_7 -> V_981 & V_137 )
F_92 ( V_149 ,
V_7 -> V_1020 ) ;
}
static void F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
int V_80 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_514 ( V_3 ) ;
F_512 ( V_3 , V_7 ) ;
V_80 = F_495 () ;
V_62 -> V_79 = & V_62 -> V_768 ;
F_140 ( V_3 ) ;
F_133 ( V_3 , V_80 ) ;
V_3 -> V_80 = V_80 ;
F_496 () ;
if ( V_766 == 0 )
F_430 ( V_62 , V_62 -> V_8 . V_761 ) ;
F_513 ( V_3 , V_7 ) ;
F_92 ( V_272 , V_62 -> V_8 . V_273 ) ;
V_62 -> V_980 = 0 ;
if ( V_62 -> V_8 . V_535 ) {
F_8 ( V_62 -> V_8 . V_535 ) ;
V_62 -> V_8 . V_535 = 0 ;
}
if ( F_89 ( V_62 -> V_814 ) ) {
V_62 -> V_814 = 0 ;
F_441 ( V_3 , F_83 ( V_93 ) ) ;
} else
F_439 ( V_3 ) ;
}
static void F_508 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_724 , unsigned long V_1021 )
{
F_513 ( V_3 , V_7 ) ;
V_7 -> V_641 = V_724 | V_853 ;
V_7 -> V_691 = V_1021 ;
F_439 ( V_3 ) ;
}
static int F_515 ( struct V_2 * V_3 ,
struct V_1022 * V_1023 ,
enum V_1024 V_1025 )
{
return V_1026 ;
}
static int T_11 F_516 ( void )
{
int V_517 , V_64 , V_63 ;
F_517 ( V_130 , & V_168 ) ;
for ( V_64 = 0 ; V_64 < V_596 ; ++ V_64 )
F_518 ( V_64 , V_66 [ V_64 ] ) ;
V_573 = ( unsigned long * ) F_519 ( V_407 ) ;
if ( ! V_573 )
return - V_408 ;
V_517 = - V_408 ;
V_575 = ( unsigned long * ) F_519 ( V_407 ) ;
if ( ! V_575 )
goto V_500;
V_262 = ( unsigned long * ) F_519 ( V_407 ) ;
if ( ! V_262 )
goto V_1027;
V_260 =
( unsigned long * ) F_519 ( V_407 ) ;
if ( ! V_260 )
goto V_1028;
V_261 = ( unsigned long * ) F_519 ( V_407 ) ;
if ( ! V_261 )
goto V_1029;
V_259 =
( unsigned long * ) F_519 ( V_407 ) ;
if ( ! V_259 )
goto V_1030;
memset ( V_573 , 0xff , V_397 ) ;
F_520 ( 0x80 , V_573 ) ;
memset ( V_575 , 0xff , V_397 ) ;
memset ( V_262 , 0xff , V_397 ) ;
memset ( V_261 , 0xff , V_397 ) ;
F_521 ( 0 , V_542 ) ;
V_517 = F_522 ( & V_1031 , sizeof( struct V_1 ) ,
F_523 ( struct V_1 ) , V_1032 ) ;
if ( V_517 )
goto V_1029;
#ifdef F_524
F_525 ( V_1033 ,
F_67 ) ;
#endif
F_297 ( V_193 , false ) ;
F_297 ( V_195 , false ) ;
F_297 ( V_196 , true ) ;
F_297 ( V_349 , false ) ;
F_297 ( V_210 , false ) ;
F_297 ( V_351 , false ) ;
memcpy ( V_260 ,
V_262 , V_397 ) ;
memcpy ( V_259 ,
V_261 , V_397 ) ;
if ( V_416 ) {
for ( V_63 = 0x800 ; V_63 <= 0x8ff ; V_63 ++ )
F_299 ( V_63 ) ;
F_298 ( 0x802 ) ;
F_298 ( 0x839 ) ;
F_300 ( 0x808 ) ;
F_300 ( 0x80b ) ;
F_300 ( 0x83f ) ;
}
if ( V_90 ) {
F_526 ( 0ull ,
( V_412 ) ? V_1034 : 0ull ,
( V_412 ) ? V_1035 : 0ull ,
0ull , V_1036 ) ;
F_309 () ;
F_527 () ;
} else
F_528 () ;
return 0 ;
V_1030:
F_529 ( ( unsigned long ) V_261 ) ;
V_1029:
F_529 ( ( unsigned long ) V_260 ) ;
V_1028:
F_529 ( ( unsigned long ) V_262 ) ;
V_1027:
F_529 ( ( unsigned long ) V_575 ) ;
V_500:
F_529 ( ( unsigned long ) V_573 ) ;
return V_517 ;
}
static void T_12 F_530 ( void )
{
F_529 ( ( unsigned long ) V_260 ) ;
F_529 ( ( unsigned long ) V_259 ) ;
F_529 ( ( unsigned long ) V_262 ) ;
F_529 ( ( unsigned long ) V_261 ) ;
F_529 ( ( unsigned long ) V_575 ) ;
F_529 ( ( unsigned long ) V_573 ) ;
#ifdef F_524
F_525 ( V_1033 , NULL ) ;
F_531 () ;
#endif
F_532 () ;
}
