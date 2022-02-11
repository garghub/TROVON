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
static void F_91 ( unsigned long V_120 ,
unsigned long exit )
{
F_81 ( V_121 , V_120 ) ;
F_81 ( V_122 , exit ) ;
}
static void F_92 ( struct V_1 * V_58 , unsigned V_59 )
{
unsigned V_60 ;
struct V_123 * V_124 = & V_58 -> V_123 ;
switch ( V_59 ) {
case V_125 :
if ( V_126 ) {
F_91 ( V_127 ,
V_128 ) ;
return;
}
break;
case V_129 :
if ( V_130 ) {
F_91 (
V_131 ,
V_132 ) ;
return;
}
break;
}
for ( V_60 = 0 ; V_60 < V_124 -> V_133 ; ++ V_60 )
if ( V_124 -> V_134 [ V_60 ] . V_64 == V_59 )
break;
if ( V_60 == V_124 -> V_133 )
return;
-- V_124 -> V_133 ;
V_124 -> V_134 [ V_60 ] = V_124 -> V_134 [ V_124 -> V_133 ] ;
V_124 -> V_135 [ V_60 ] = V_124 -> V_135 [ V_124 -> V_133 ] ;
F_79 ( V_136 , V_124 -> V_133 ) ;
F_79 ( V_137 , V_124 -> V_133 ) ;
}
static void F_93 ( unsigned long V_120 ,
unsigned long exit , unsigned long V_138 ,
unsigned long V_139 , T_5 V_140 , T_5 V_141 )
{
F_80 ( V_138 , V_140 ) ;
F_80 ( V_139 , V_141 ) ;
F_82 ( V_121 , V_120 ) ;
F_82 ( V_122 , exit ) ;
}
static void F_94 ( struct V_1 * V_58 , unsigned V_59 ,
T_5 V_140 , T_5 V_141 )
{
unsigned V_60 ;
struct V_123 * V_124 = & V_58 -> V_123 ;
switch ( V_59 ) {
case V_125 :
if ( V_126 ) {
F_93 ( V_127 ,
V_128 ,
V_142 ,
V_143 ,
V_140 , V_141 ) ;
return;
}
break;
case V_129 :
if ( V_130 ) {
F_93 (
V_131 ,
V_132 ,
V_144 ,
V_145 ,
V_140 , V_141 ) ;
return;
}
break;
}
for ( V_60 = 0 ; V_60 < V_124 -> V_133 ; ++ V_60 )
if ( V_124 -> V_134 [ V_60 ] . V_64 == V_59 )
break;
if ( V_60 == V_146 ) {
F_95 ( V_147 L_4
L_5 , V_59 ) ;
return;
} else if ( V_60 == V_124 -> V_133 ) {
++ V_124 -> V_133 ;
F_79 ( V_136 , V_124 -> V_133 ) ;
F_79 ( V_137 , V_124 -> V_133 ) ;
}
V_124 -> V_134 [ V_60 ] . V_64 = V_59 ;
V_124 -> V_134 [ V_60 ] . V_87 = V_140 ;
V_124 -> V_135 [ V_60 ] . V_64 = V_59 ;
V_124 -> V_135 [ V_60 ] . V_87 = V_141 ;
}
static void F_96 ( void )
{
struct V_148 * V_149 = & F_97 ( V_150 ) ;
struct V_151 * V_152 ;
V_152 = ( void * ) V_149 -> V_153 ;
V_152 [ V_154 ] . type = 9 ;
F_98 () ;
}
static bool F_99 ( struct V_1 * V_58 , int V_155 )
{
T_5 V_156 ;
T_5 V_157 ;
V_156 = V_58 -> V_3 . V_95 . V_158 ;
V_157 = V_159 | V_160 ;
#ifdef F_73
V_157 |= V_161 | V_162 ;
if ( V_156 & V_161 )
V_157 &= ~ ( T_5 ) V_160 ;
#endif
V_156 &= ~ V_157 ;
V_156 |= V_163 & V_157 ;
V_58 -> V_63 [ V_155 ] . V_164 = V_156 ;
V_58 -> V_63 [ V_155 ] . V_89 = ~ V_157 ;
F_92 ( V_58 , V_125 ) ;
if ( V_84 && ( ( V_58 -> V_3 . V_95 . V_158 ^ V_163 ) & V_159 ) ) {
V_156 = V_58 -> V_3 . V_95 . V_158 ;
if ( ! ( V_156 & V_161 ) )
V_156 &= ~ V_162 ;
F_94 ( V_58 , V_125 , V_156 , V_163 ) ;
return false ;
}
return true ;
}
static unsigned long F_100 ( T_3 V_99 )
{
struct V_148 * V_149 = & F_97 ( V_150 ) ;
struct V_151 * V_165 ;
unsigned long V_166 ;
unsigned long V_167 ;
if ( ! ( V_99 & ~ 3 ) )
return 0 ;
V_166 = V_149 -> V_153 ;
if ( V_99 & 4 ) {
T_3 V_168 = F_101 () ;
if ( ! ( V_168 & ~ 3 ) )
return 0 ;
V_166 = F_100 ( V_168 ) ;
}
V_165 = (struct V_151 * ) ( V_166 + ( V_99 & ~ 7 ) ) ;
V_167 = F_102 ( V_165 ) ;
#ifdef F_73
if ( V_165 -> V_169 == 0 && ( V_165 -> type == 2 || V_165 -> type == 9 || V_165 -> type == 11 ) )
V_167 |= ( ( unsigned long ) ( (struct V_170 * ) V_165 ) -> V_171 ) << 32 ;
#endif
return V_167 ;
}
static inline unsigned long F_103 ( void )
{
T_3 V_172 ;
asm("str %0" : "=g"(tr));
return F_100 ( V_172 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_60 ;
if ( V_58 -> V_173 . V_174 )
return;
V_58 -> V_173 . V_174 = 1 ;
V_58 -> V_173 . V_175 = F_101 () ;
V_58 -> V_173 . V_176 = V_58 -> V_173 . V_175 ;
F_105 ( V_177 , V_58 -> V_173 . V_178 ) ;
if ( ! ( V_58 -> V_173 . V_178 & 7 ) ) {
F_78 ( V_179 , V_58 -> V_173 . V_178 ) ;
V_58 -> V_173 . V_180 = 0 ;
} else {
F_78 ( V_179 , 0 ) ;
V_58 -> V_173 . V_180 = 1 ;
}
F_105 ( V_181 , V_58 -> V_173 . V_182 ) ;
if ( ! ( V_58 -> V_173 . V_182 & 7 ) )
F_78 ( V_183 , V_58 -> V_173 . V_182 ) ;
else {
F_78 ( V_183 , 0 ) ;
V_58 -> V_173 . V_176 = 1 ;
}
#ifdef F_73
F_76 ( V_184 , F_106 ( V_185 ) ) ;
F_76 ( V_186 , F_106 ( V_187 ) ) ;
#else
F_76 ( V_184 , F_100 ( V_58 -> V_173 . V_178 ) ) ;
F_76 ( V_186 , F_100 ( V_58 -> V_173 . V_182 ) ) ;
#endif
#ifdef F_73
F_107 ( V_188 , V_58 -> V_189 ) ;
if ( F_108 ( & V_58 -> V_3 ) )
F_109 ( V_188 , V_58 -> V_190 ) ;
#endif
for ( V_60 = 0 ; V_60 < V_58 -> V_191 ; ++ V_60 )
F_110 ( V_58 -> V_63 [ V_60 ] . V_64 ,
V_58 -> V_63 [ V_60 ] . V_164 ,
V_58 -> V_63 [ V_60 ] . V_89 ) ;
}
static void F_111 ( struct V_1 * V_58 )
{
if ( ! V_58 -> V_173 . V_174 )
return;
++ V_58 -> V_3 . V_192 . V_193 ;
V_58 -> V_173 . V_174 = 0 ;
#ifdef F_73
if ( F_108 ( & V_58 -> V_3 ) )
F_107 ( V_188 , V_58 -> V_190 ) ;
#endif
if ( V_58 -> V_173 . V_176 ) {
F_112 ( V_58 -> V_173 . V_175 ) ;
#ifdef F_73
F_113 ( V_58 -> V_173 . V_182 ) ;
#else
F_114 ( V_181 , V_58 -> V_173 . V_182 ) ;
#endif
}
if ( V_58 -> V_173 . V_180 )
F_114 ( V_177 , V_58 -> V_173 . V_178 ) ;
F_96 () ;
#ifdef F_73
F_109 ( V_188 , V_58 -> V_189 ) ;
#endif
if ( F_115 ( V_194 ) )
F_116 () ;
F_117 ( & F_97 ( V_150 ) ) ;
}
static void F_118 ( struct V_1 * V_58 )
{
F_119 () ;
F_111 ( V_58 ) ;
F_120 () ;
}
static void F_121 ( struct V_2 * V_3 , int V_76 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_5 V_73 = F_53 ( F_59 ( V_195 , V_76 ) ) ;
if ( ! V_196 )
F_122 ( V_73 ) ;
else if ( V_58 -> V_75 -> V_76 != V_76 )
F_61 ( V_58 -> V_75 ) ;
if ( F_59 ( V_79 , V_76 ) != V_58 -> V_75 -> V_72 ) {
F_59 ( V_79 , V_76 ) = V_58 -> V_75 -> V_72 ;
F_56 ( V_58 -> V_75 -> V_72 ) ;
}
if ( V_58 -> V_75 -> V_76 != V_76 ) {
struct V_148 * V_149 = & F_97 ( V_150 ) ;
unsigned long V_197 ;
F_123 ( V_198 , V_3 ) ;
F_124 () ;
F_125 ( & V_58 -> V_75 -> V_80 ,
& F_59 ( V_199 , V_76 ) ) ;
F_126 () ;
F_76 ( V_200 , F_103 () ) ;
F_76 ( V_201 , V_149 -> V_153 ) ;
F_107 ( V_202 , V_197 ) ;
F_76 ( V_203 , V_197 ) ;
V_58 -> V_75 -> V_76 = V_76 ;
}
}
static void F_127 ( struct V_2 * V_3 )
{
F_111 ( F_1 ( V_3 ) ) ;
if ( ! V_196 ) {
F_57 ( F_1 ( V_3 ) -> V_75 ) ;
V_3 -> V_76 = - 1 ;
F_128 () ;
}
}
static void F_129 ( struct V_2 * V_3 )
{
T_9 V_204 ;
if ( V_3 -> V_117 )
return;
V_3 -> V_117 = 1 ;
V_204 = F_69 ( V_205 ) ;
V_204 &= ~ ( V_206 | V_207 ) ;
V_204 |= F_130 ( V_3 , V_206 | V_207 ) ;
F_76 ( V_205 , V_204 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_208 = V_206 ;
if ( F_90 ( V_3 ) )
V_3 -> V_95 . V_208 &=
~ F_4 ( V_3 ) -> V_209 ;
F_76 ( V_210 , ~ V_3 -> V_95 . V_208 ) ;
}
static inline unsigned long F_131 ( struct V_7 * V_211 )
{
return ( V_211 -> V_212 & ~ V_211 -> V_209 ) |
( V_211 -> V_213 & V_211 -> V_209 ) ;
}
static inline unsigned long F_132 ( struct V_7 * V_211 )
{
return ( V_211 -> V_214 & ~ V_211 -> V_215 ) |
( V_211 -> V_216 & V_211 -> V_215 ) ;
}
static void F_133 ( struct V_2 * V_3 )
{
F_134 ( V_3 ) ;
F_82 ( V_205 , V_206 | V_207 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_208 = 0 ;
F_76 ( V_210 , ~ V_3 -> V_95 . V_208 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_212 = ( V_7 -> V_212 & ~ V_206 ) |
( V_3 -> V_95 . V_204 & V_206 ) ;
F_76 ( V_217 , F_131 ( V_7 ) ) ;
} else
F_76 ( V_217 , V_3 -> V_95 . V_204 ) ;
}
static unsigned long F_135 ( struct V_2 * V_3 )
{
unsigned long V_218 , V_219 ;
if ( ! F_136 ( V_220 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_137 ( V_220 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
V_218 = F_69 ( V_221 ) ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
V_218 &= V_222 ;
V_219 = F_1 ( V_3 ) -> V_115 . V_219 ;
V_218 |= V_219 & ~ V_222 ;
}
F_1 ( V_3 ) -> V_218 = V_218 ;
}
return F_1 ( V_3 ) -> V_218 ;
}
static void F_138 ( struct V_2 * V_3 , unsigned long V_218 )
{
F_137 ( V_220 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_139 ( V_223 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_218 = V_218 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
F_1 ( V_3 ) -> V_115 . V_219 = V_218 ;
V_218 |= V_224 | V_225 ;
}
F_76 ( V_221 , V_218 ) ;
}
static T_2 F_140 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_226 = F_71 ( V_227 ) ;
int V_93 = 0 ;
if ( V_226 & V_228 )
V_93 |= V_229 ;
if ( V_226 & V_230 )
V_93 |= V_231 ;
return V_93 & V_89 ;
}
static void F_141 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_232 = F_71 ( V_227 ) ;
T_2 V_226 = V_232 ;
V_226 &= ~ ( V_228 | V_230 ) ;
if ( V_89 & V_231 )
V_226 |= V_230 ;
else if ( V_89 & V_229 )
V_226 |= V_228 ;
if ( ( V_226 != V_232 ) )
F_79 ( V_227 , V_226 ) ;
}
static void F_142 ( struct V_2 * V_3 )
{
unsigned long V_233 ;
V_233 = F_143 ( V_3 ) ;
V_233 += F_71 ( V_234 ) ;
F_144 ( V_3 , V_233 ) ;
F_141 ( V_3 , 0 ) ;
}
static void F_145 ( struct V_2 * V_3 )
{
if ( ! V_235 &&
F_71 ( V_236 ) == V_237 )
F_79 ( V_236 , V_238 ) ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( ! ( V_7 -> V_118 & V_19 ) )
return 0 ;
F_147 ( V_3 ) ;
return 1 ;
}
static void F_148 ( struct V_2 * V_3 , unsigned V_133 ,
bool V_239 , T_2 V_240 ,
bool V_241 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_14 = V_133 | V_17 ;
if ( V_133 == V_19 && F_90 ( V_3 ) &&
F_146 ( V_3 ) )
return;
if ( V_239 ) {
F_79 ( V_242 , V_240 ) ;
V_14 |= V_243 ;
}
if ( V_58 -> V_115 . V_116 ) {
int V_244 = 0 ;
if ( F_149 ( V_133 ) )
V_244 = V_3 -> V_95 . V_245 ;
if ( F_150 ( V_3 , V_133 , V_244 ) != V_246 )
F_123 ( V_247 , V_3 ) ;
return;
}
if ( F_149 ( V_133 ) ) {
F_79 ( V_248 ,
V_58 -> V_3 . V_95 . V_245 ) ;
V_14 |= V_249 ;
} else
V_14 |= V_18 ;
F_79 ( V_250 , V_14 ) ;
F_145 ( V_3 ) ;
}
static bool F_151 ( void )
{
return F_40 () ;
}
static void F_152 ( struct V_1 * V_58 , int V_251 , int V_252 )
{
struct V_71 V_253 ;
V_253 = V_58 -> V_63 [ V_252 ] ;
V_58 -> V_63 [ V_252 ] = V_58 -> V_63 [ V_251 ] ;
V_58 -> V_63 [ V_251 ] = V_253 ;
}
static void F_153 ( struct V_1 * V_58 )
{
int V_191 , V_64 ;
unsigned long * V_254 ;
V_191 = 0 ;
#ifdef F_73
if ( F_108 ( & V_58 -> V_3 ) ) {
V_64 = F_48 ( V_58 , V_255 ) ;
if ( V_64 >= 0 )
F_152 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_256 ) ;
if ( V_64 >= 0 )
F_152 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_257 ) ;
if ( V_64 >= 0 )
F_152 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_258 ) ;
if ( V_64 >= 0 && V_58 -> V_259 )
F_152 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_260 ) ;
if ( ( V_64 >= 0 ) && ( V_58 -> V_3 . V_95 . V_158 & V_160 ) )
F_152 ( V_58 , V_64 , V_191 ++ ) ;
}
#endif
V_64 = F_48 ( V_58 , V_125 ) ;
if ( V_64 >= 0 && F_99 ( V_58 , V_64 ) )
F_152 ( V_58 , V_64 , V_191 ++ ) ;
V_58 -> V_191 = V_191 ;
if ( F_17 () ) {
if ( F_108 ( & V_58 -> V_3 ) )
V_254 = V_261 ;
else
V_254 = V_262 ;
F_80 ( V_263 , F_53 ( V_254 ) ) ;
}
}
static T_5 F_154 ( void )
{
T_5 V_264 , V_265 ;
F_155 ( V_264 ) ;
V_265 = F_72 ( V_266 ) ;
return V_264 + V_265 ;
}
T_5 F_156 ( struct V_2 * V_3 )
{
T_5 V_264 , V_265 ;
F_155 ( V_264 ) ;
V_265 = F_90 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_267 :
F_72 ( V_266 ) ;
return V_264 + V_265 ;
}
static void F_157 ( struct V_2 * V_3 , T_2 V_268 )
{
}
static void F_158 ( struct V_2 * V_3 , T_5 V_269 )
{
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_267 = V_269 ;
V_7 = F_4 ( V_3 ) ;
F_80 ( V_266 , V_269 +
( F_44 ( V_7 , V_270 ) ?
V_7 -> V_265 : 0 ) ) ;
} else {
F_80 ( V_266 , V_269 ) ;
}
}
static void F_159 ( struct V_2 * V_3 , T_10 V_271 )
{
T_5 V_269 = F_72 ( V_266 ) ;
F_80 ( V_266 , V_269 + V_271 ) ;
if ( F_90 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_267 += V_271 ;
}
}
static T_5 F_160 ( struct V_2 * V_3 , T_5 V_272 )
{
return V_272 - F_161 () ;
}
static bool F_162 ( struct V_2 * V_3 )
{
struct V_273 * V_274 = F_163 ( V_3 , 1 , 0 ) ;
return V_274 && ( V_274 -> V_275 & ( 1 << ( V_276 & 31 ) ) ) ;
}
static inline bool F_164 ( struct V_2 * V_3 )
{
return V_8 && F_162 ( V_3 ) ;
}
static T_11 void F_165 ( void )
{
V_277 = 0x16 ;
V_278 = 0x16 |
V_279 | V_280 |
V_52 ;
V_281 = 0 ;
#ifdef F_73
V_282 = V_283 ;
#else
V_282 = 0 ;
#endif
F_166 ( V_284 ,
V_285 , V_286 ) ;
V_285 = 0 ;
V_286 &=
V_287 | V_288 ;
F_166 ( V_289 ,
V_290 , V_291 ) ;
V_290 = 0 ;
V_291 &=
V_292 | V_270 |
V_293 | V_294 |
V_295 | V_296 |
V_297 |
#ifdef F_73
V_298 | V_299 |
#endif
V_300 | V_301 |
V_302 | V_303 |
V_304 |
V_28 ;
V_291 |= V_26 ;
F_166 ( V_305 ,
V_306 , V_307 ) ;
V_306 = 0 ;
V_307 &=
V_30 ;
}
static inline bool F_167 ( T_2 V_308 , T_2 V_309 , T_2 V_310 )
{
return ( ( V_308 & V_310 ) | V_309 ) == V_308 ;
}
static inline T_5 F_168 ( T_2 V_309 , T_2 V_310 )
{
return V_309 | ( ( T_5 ) V_310 << 32 ) ;
}
static int F_169 ( struct V_2 * V_3 , T_2 V_311 , T_5 * V_312 )
{
if ( ! F_164 ( V_3 ) && V_311 >= V_313 &&
V_311 <= V_314 ) {
F_170 ( V_3 , V_315 , 0 ) ;
return 1 ;
}
switch ( V_311 ) {
case V_316 :
* V_312 = 0 ;
break;
case V_313 :
* V_312 = V_317 |
( ( T_5 ) V_318 << V_319 ) |
( V_320 << V_321 ) ;
break;
case V_322 :
case V_323 :
* V_312 = F_168 ( V_277 ,
V_278 ) ;
break;
case V_324 :
case V_289 :
* V_312 = F_168 ( V_290 ,
V_291 ) ;
break;
case V_325 :
case V_326 :
* V_312 = F_168 ( V_281 ,
V_282 ) ;
break;
case V_314 :
case V_284 :
* V_312 = F_168 ( V_285 ,
V_286 ) ;
break;
case V_327 :
* V_312 = 0 ;
break;
#define F_171 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_172 X86_CR4_VMXE
case V_328 :
* V_312 = F_171 ;
break;
case V_329 :
* V_312 = - 1ULL ;
break;
case V_330 :
* V_312 = F_172 ;
break;
case V_331 :
* V_312 = - 1ULL ;
break;
case V_332 :
* V_312 = 0x1f ;
break;
case V_305 :
* V_312 = F_168 ( V_306 ,
V_307 ) ;
break;
case V_333 :
* V_312 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_173 ( struct V_2 * V_3 , T_2 V_311 , T_5 V_164 )
{
if ( ! F_164 ( V_3 ) )
return 0 ;
if ( V_311 == V_316 )
return 1 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_3 , T_2 V_311 , T_5 * V_312 )
{
T_5 V_164 ;
struct V_71 * V_59 ;
if ( ! V_312 ) {
F_54 ( V_74 L_6 ) ;
return - V_334 ;
}
switch ( V_311 ) {
#ifdef F_73
case V_185 :
V_164 = F_69 ( V_335 ) ;
break;
case V_187 :
V_164 = F_69 ( V_336 ) ;
break;
case V_188 :
F_118 ( F_1 ( V_3 ) ) ;
V_164 = F_1 ( V_3 ) -> V_190 ;
break;
#endif
case V_125 :
return F_175 ( V_3 , V_311 , V_312 ) ;
case V_337 :
V_164 = F_154 () ;
break;
case V_338 :
V_164 = F_71 ( V_339 ) ;
break;
case V_340 :
V_164 = F_69 ( V_341 ) ;
break;
case V_202 :
V_164 = F_69 ( V_342 ) ;
break;
case V_258 :
if ( ! F_1 ( V_3 ) -> V_259 )
return 1 ;
default:
if ( F_169 ( V_3 , V_311 , V_312 ) )
return 0 ;
V_59 = F_51 ( F_1 ( V_3 ) , V_311 ) ;
if ( V_59 ) {
V_164 = V_59 -> V_164 ;
break;
}
return F_175 ( V_3 , V_311 , V_312 ) ;
}
* V_312 = V_164 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , T_2 V_311 , T_5 V_164 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_71 * V_59 ;
int V_93 = 0 ;
switch ( V_311 ) {
case V_125 :
V_93 = F_177 ( V_3 , V_311 , V_164 ) ;
break;
#ifdef F_73
case V_185 :
F_83 ( V_58 ) ;
F_76 ( V_335 , V_164 ) ;
break;
case V_187 :
F_83 ( V_58 ) ;
F_76 ( V_336 , V_164 ) ;
break;
case V_188 :
F_118 ( V_58 ) ;
V_58 -> V_190 = V_164 ;
break;
#endif
case V_338 :
F_79 ( V_339 , V_164 ) ;
break;
case V_340 :
F_76 ( V_341 , V_164 ) ;
break;
case V_202 :
F_76 ( V_342 , V_164 ) ;
break;
case V_337 :
F_178 ( V_3 , V_164 ) ;
break;
case V_343 :
if ( V_24 . V_344 & V_287 ) {
F_80 ( V_345 , V_164 ) ;
V_3 -> V_95 . V_346 = V_164 ;
break;
}
V_93 = F_177 ( V_3 , V_311 , V_164 ) ;
break;
case V_258 :
if ( ! V_58 -> V_259 )
return 1 ;
if ( ( V_164 >> 32 ) != 0 )
return 1 ;
default:
if ( F_173 ( V_3 , V_311 , V_164 ) )
break;
V_59 = F_51 ( V_58 , V_311 ) ;
if ( V_59 ) {
V_59 -> V_164 = V_164 ;
break;
}
V_93 = F_177 ( V_3 , V_311 , V_164 ) ;
}
return V_93 ;
}
static void F_179 ( struct V_2 * V_3 , enum V_347 V_348 )
{
F_137 ( V_348 , ( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
switch ( V_348 ) {
case V_349 :
V_3 -> V_95 . V_350 [ V_349 ] = F_69 ( V_351 ) ;
break;
case V_352 :
V_3 -> V_95 . V_350 [ V_352 ] = F_69 ( V_353 ) ;
break;
case V_354 :
if ( V_84 )
F_180 ( V_3 ) ;
break;
default:
break;
}
}
static void F_181 ( struct V_2 * V_3 , struct V_355 * V_356 )
{
if ( V_3 -> V_111 & V_357 )
F_76 ( V_358 , V_356 -> V_95 . V_359 [ 7 ] ) ;
else
F_76 ( V_358 , V_3 -> V_95 . V_360 ) ;
F_89 ( V_3 ) ;
}
static T_11 int F_182 ( void )
{
return F_183 () ;
}
static T_11 int F_184 ( void )
{
T_5 V_59 ;
F_107 ( V_316 , V_59 ) ;
if ( V_59 & V_361 ) {
if ( ! ( V_59 & V_362 )
&& F_185 () )
return 1 ;
if ( ! ( V_59 & V_363 )
&& ( V_59 & V_362 )
&& ! F_185 () ) {
F_54 ( V_147 L_7
L_8 ) ;
return 1 ;
}
if ( ! ( V_59 & V_363 )
&& ! F_185 () )
return 1 ;
}
return 0 ;
}
static void F_122 ( T_5 V_11 )
{
asm volatile (ASM_VMX_VMXON_RAX
: : "a"(&addr), "m"(addr)
: "memory", "cc");
}
static int F_186 ( void * V_364 )
{
int V_76 = F_58 () ;
T_5 V_73 = F_53 ( F_59 ( V_195 , V_76 ) ) ;
T_5 V_365 , V_366 ;
if ( F_187 () & V_367 )
return - V_368 ;
F_188 ( & F_59 ( V_199 , V_76 ) ) ;
F_107 ( V_316 , V_365 ) ;
V_366 = V_361 ;
V_366 |= V_363 ;
if ( F_185 () )
V_366 |= V_362 ;
if ( ( V_365 & V_366 ) != V_366 ) {
F_109 ( V_316 , V_365 | V_366 ) ;
}
F_189 ( F_187 () | V_367 ) ;
if ( V_196 ) {
F_122 ( V_73 ) ;
F_66 () ;
}
F_190 ( & F_97 ( V_150 ) ) ;
return 0 ;
}
static void F_191 ( void )
{
int V_76 = F_58 () ;
struct V_75 * V_167 , * V_369 ;
F_192 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_57 ( V_167 ) ;
}
static void F_128 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_193 ( void * V_364 )
{
if ( V_196 ) {
F_191 () ;
F_128 () ;
}
F_189 ( F_187 () & ~ V_367 ) ;
}
static T_11 int F_194 ( T_2 V_370 , T_2 V_371 ,
T_2 V_59 , T_2 * V_372 )
{
T_2 V_373 , V_374 ;
T_2 V_375 = V_370 | V_371 ;
F_166 ( V_59 , V_373 , V_374 ) ;
V_375 &= V_374 ;
V_375 |= V_373 ;
if ( V_370 & ~ V_375 )
return - V_376 ;
* V_372 = V_375 ;
return 0 ;
}
static T_11 bool F_195 ( T_2 V_59 , T_2 V_375 )
{
T_2 V_373 , V_374 ;
F_166 ( V_59 , V_373 , V_374 ) ;
return V_374 & V_375 ;
}
static T_11 int F_196 ( struct V_24 * V_377 )
{
T_2 V_373 , V_374 ;
T_2 V_378 , V_379 , V_380 , V_381 ;
T_2 V_382 = 0 ;
T_2 V_383 = 0 ;
T_2 V_384 = 0 ;
T_2 V_385 = 0 ;
T_2 V_386 = 0 ;
V_378 = V_279 | V_280 ;
V_379 = V_52 ;
if ( F_194 ( V_378 , V_379 , V_323 ,
& V_382 ) < 0 )
return - V_376 ;
V_378 =
#ifdef F_73
V_298 |
V_299 |
#endif
V_296 |
V_297 |
V_302 |
V_300 |
V_270 |
V_295 |
V_303 |
V_294 |
V_304 ;
if ( V_235 )
V_378 |= V_293 ;
V_379 = V_27 |
V_26 |
V_28 ;
if ( F_194 ( V_378 , V_379 , V_289 ,
& V_383 ) < 0 )
return - V_376 ;
#ifdef F_73
if ( ( V_383 & V_27 ) )
V_383 &= ~ V_298 &
~ V_299 ;
#endif
if ( V_383 & V_28 ) {
V_380 = 0 ;
V_381 = V_30 |
V_53 |
V_49 |
V_45 |
V_46 |
V_47 |
V_50 ;
if ( F_194 ( V_380 , V_381 ,
V_305 ,
& V_384 ) < 0 )
return - V_376 ;
}
#ifndef F_73
if ( ! ( V_384 &
V_30 ) )
V_383 &= ~ V_27 ;
#endif
if ( V_384 & V_45 ) {
V_383 &= ~ ( V_296 |
V_297 |
V_294 ) ;
F_166 ( V_333 ,
V_31 . V_32 , V_31 . V_42 ) ;
}
V_378 = 0 ;
#ifdef F_73
V_378 |= V_283 ;
#endif
V_379 = V_387 | V_388 ;
if ( F_194 ( V_378 , V_379 , V_326 ,
& V_385 ) < 0 )
return - V_376 ;
V_378 = 0 ;
V_379 = V_287 ;
if ( F_194 ( V_378 , V_379 , V_284 ,
& V_386 ) < 0 )
return - V_376 ;
F_166 ( V_313 , V_373 , V_374 ) ;
if ( ( V_374 & 0x1fff ) > V_389 )
return - V_376 ;
#ifdef F_73
if ( V_374 & ( 1u << 16 ) )
return - V_376 ;
#endif
if ( ( ( V_374 >> 18 ) & 15 ) != 6 )
return - V_376 ;
V_377 -> V_390 = V_374 & 0x1fff ;
V_377 -> V_391 = F_197 ( V_24 . V_390 ) ;
V_377 -> V_392 = V_373 ;
V_377 -> V_51 = V_382 ;
V_377 -> V_25 = V_383 ;
V_377 -> V_29 = V_384 ;
V_377 -> V_393 = V_385 ;
V_377 -> V_344 = V_386 ;
V_126 =
F_195 ( V_284 ,
V_127 )
&& F_195 ( V_326 ,
V_128 ) ;
V_130 =
F_195 ( V_284 ,
V_131 )
&& F_195 ( V_326 ,
V_132 ) ;
if ( V_130 && V_394 . V_395 == 0x6 ) {
switch ( V_394 . V_396 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_130 = false ;
F_95 ( V_147 L_9
L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_72 * F_198 ( int V_76 )
{
int V_397 = F_199 ( V_76 ) ;
struct V_10 * V_398 ;
struct V_72 * V_72 ;
V_398 = F_200 ( V_397 , V_399 , V_24 . V_391 ) ;
if ( ! V_398 )
return NULL ;
V_72 = F_201 ( V_398 ) ;
memset ( V_72 , 0 , V_24 . V_390 ) ;
V_72 -> V_392 = V_24 . V_392 ;
return V_72 ;
}
static struct V_72 * F_202 ( void )
{
return F_198 ( F_58 () ) ;
}
static void F_203 ( struct V_72 * V_72 )
{
F_204 ( ( unsigned long ) V_72 , V_24 . V_391 ) ;
}
static void F_205 ( struct V_75 * V_75 )
{
if ( ! V_75 -> V_72 )
return;
F_61 ( V_75 ) ;
F_203 ( V_75 -> V_72 ) ;
V_75 -> V_72 = NULL ;
}
static void F_206 ( void )
{
int V_76 ;
F_207 (cpu) {
F_203 ( F_59 ( V_195 , V_76 ) ) ;
F_59 ( V_195 , V_76 ) = NULL ;
}
}
static T_11 int F_208 ( void )
{
int V_76 ;
F_207 (cpu) {
struct V_72 * V_72 ;
V_72 = F_198 ( V_76 ) ;
if ( ! V_72 ) {
F_206 () ;
return - V_400 ;
}
F_59 ( V_195 , V_76 ) = V_72 ;
}
return 0 ;
}
static T_11 int F_209 ( void )
{
if ( F_196 ( & V_24 ) < 0 )
return - V_376 ;
if ( F_210 ( V_401 ) )
F_211 ( V_159 ) ;
if ( ! F_39 () )
V_402 = 0 ;
if ( ! F_35 () ||
! F_29 () ) {
V_84 = 0 ;
V_403 = 0 ;
}
if ( ! F_36 () )
V_403 = 0 ;
if ( ! F_23 () )
V_48 = 0 ;
if ( ! F_18 () )
V_404 -> V_405 = NULL ;
if ( V_84 && ! F_27 () )
F_212 () ;
if ( ! F_37 () )
V_406 = 0 ;
if ( V_8 )
F_165 () ;
return F_208 () ;
}
static T_12 void F_213 ( void )
{
F_206 () ;
}
static void F_214 ( int V_92 , struct V_407 * V_408 )
{
struct V_409 * V_410 = & V_101 [ V_92 ] ;
if ( F_69 ( V_410 -> V_102 ) == V_408 -> V_102 && ( V_408 -> V_102 & V_411 ) ) {
F_78 ( V_410 -> V_99 , V_408 -> V_99 ) ;
F_76 ( V_410 -> V_102 , V_408 -> V_102 ) ;
F_79 ( V_410 -> V_104 , V_408 -> V_104 ) ;
F_79 ( V_410 -> V_108 , V_408 -> V_106 ) ;
} else {
T_2 V_412 = ( F_70 ( V_410 -> V_99 ) & V_413 )
<< V_414 ;
F_79 ( V_410 -> V_108 , 0x93 | V_412 ) ;
}
}
static void F_215 ( struct V_2 * V_3 )
{
unsigned long V_415 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
V_58 -> V_416 = 1 ;
V_58 -> V_115 . V_116 = 0 ;
F_83 ( V_58 ) ;
F_78 ( V_417 , V_58 -> V_115 . V_172 . V_99 ) ;
F_76 ( V_418 , V_58 -> V_115 . V_172 . V_102 ) ;
F_79 ( V_419 , V_58 -> V_115 . V_172 . V_104 ) ;
F_79 ( V_420 , V_58 -> V_115 . V_172 . V_106 ) ;
V_415 = F_69 ( V_221 ) ;
V_415 &= V_222 ;
V_415 |= V_58 -> V_115 . V_219 & ~ V_222 ;
F_76 ( V_221 , V_415 ) ;
F_76 ( V_421 , ( F_69 ( V_421 ) & ~ V_422 ) |
( F_69 ( V_423 ) & V_422 ) ) ;
F_89 ( V_3 ) ;
if ( V_424 )
return;
F_214 ( V_425 , & V_58 -> V_115 . V_426 ) ;
F_214 ( V_427 , & V_58 -> V_115 . V_428 ) ;
F_214 ( V_429 , & V_58 -> V_115 . V_181 ) ;
F_214 ( V_430 , & V_58 -> V_115 . V_177 ) ;
F_83 ( V_58 ) ;
F_78 ( V_431 , 0 ) ;
F_79 ( V_432 , 0x93 ) ;
F_78 ( V_433 ,
F_70 ( V_433 ) & ~ V_413 ) ;
F_79 ( V_434 , 0x9b ) ;
}
static T_4 F_216 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_95 . V_435 ) {
struct V_436 * V_437 ;
struct V_438 * V_439 ;
T_13 V_440 ;
V_437 = V_436 ( V_12 ) ;
V_439 = F_217 ( V_437 , 0 ) ;
V_440 = V_439 -> V_440 + V_439 -> V_441 - 3 ;
return V_440 << V_13 ;
}
return V_12 -> V_95 . V_435 ;
}
static void F_218 ( int V_92 , struct V_407 * V_408 )
{
struct V_409 * V_410 = & V_101 [ V_92 ] ;
V_408 -> V_99 = F_70 ( V_410 -> V_99 ) ;
V_408 -> V_102 = F_69 ( V_410 -> V_102 ) ;
V_408 -> V_104 = F_71 ( V_410 -> V_104 ) ;
V_408 -> V_106 = F_71 ( V_410 -> V_108 ) ;
F_78 ( V_410 -> V_99 , V_408 -> V_102 >> 4 ) ;
F_79 ( V_410 -> V_102 , V_408 -> V_102 & 0xffff0 ) ;
F_79 ( V_410 -> V_104 , 0xffff ) ;
F_79 ( V_410 -> V_108 , 0xf3 ) ;
if ( V_408 -> V_102 & 0xf )
F_95 ( V_147 L_11
L_12 ,
V_92 ) ;
}
static void F_219 ( struct V_2 * V_3 )
{
unsigned long V_415 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_403 )
return;
V_58 -> V_416 = 1 ;
V_58 -> V_115 . V_116 = 1 ;
if ( ! V_3 -> V_12 -> V_95 . V_435 ) {
F_95 ( V_147 L_13
L_14 ) ;
F_220 ( & V_3 -> V_12 -> V_442 , V_3 -> V_443 ) ;
F_221 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_443 = F_222 ( & V_3 -> V_12 -> V_442 ) ;
}
F_83 ( V_58 ) ;
V_58 -> V_115 . V_172 . V_99 = F_70 ( V_417 ) ;
V_58 -> V_115 . V_172 . V_102 = F_69 ( V_418 ) ;
F_76 ( V_418 , F_216 ( V_3 -> V_12 ) ) ;
V_58 -> V_115 . V_172 . V_104 = F_71 ( V_419 ) ;
F_79 ( V_419 , V_444 - 1 ) ;
V_58 -> V_115 . V_172 . V_106 = F_71 ( V_420 ) ;
F_79 ( V_420 , 0x008b ) ;
V_415 = F_69 ( V_221 ) ;
V_58 -> V_115 . V_219 = V_415 ;
V_415 |= V_224 | V_225 ;
F_76 ( V_221 , V_415 ) ;
F_76 ( V_421 , F_69 ( V_421 ) | V_422 ) ;
F_89 ( V_3 ) ;
if ( V_424 )
goto V_445;
F_78 ( V_431 , F_69 ( V_446 ) >> 4 ) ;
F_79 ( V_447 , 0xffff ) ;
F_79 ( V_432 , 0xf3 ) ;
F_79 ( V_434 , 0xf3 ) ;
F_79 ( V_448 , 0xffff ) ;
if ( F_69 ( V_449 ) == 0xffff0000 )
F_76 ( V_449 , 0xf0000 ) ;
F_78 ( V_433 , F_69 ( V_449 ) >> 4 ) ;
F_218 ( V_425 , & V_58 -> V_115 . V_426 ) ;
F_218 ( V_427 , & V_58 -> V_115 . V_428 ) ;
F_218 ( V_429 , & V_58 -> V_115 . V_181 ) ;
F_218 ( V_430 , & V_58 -> V_115 . V_177 ) ;
V_445:
F_223 ( V_3 ) ;
}
static void F_224 ( struct V_2 * V_3 , T_5 V_158 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_71 * V_59 = F_51 ( V_58 , V_125 ) ;
if ( ! V_59 )
return;
F_118 ( F_1 ( V_3 ) ) ;
V_3 -> V_95 . V_158 = V_158 ;
if ( V_158 & V_161 ) {
F_79 ( V_121 ,
F_71 ( V_121 ) |
V_288 ) ;
V_59 -> V_164 = V_158 ;
} else {
F_79 ( V_121 ,
F_71 ( V_121 ) &
~ V_288 ) ;
V_59 -> V_164 = V_158 & ~ V_162 ;
}
F_153 ( V_58 ) ;
}
static void F_225 ( struct V_2 * V_3 )
{
T_2 V_450 ;
F_83 ( F_1 ( V_3 ) ) ;
V_450 = F_71 ( V_420 ) ;
if ( ( V_450 & V_451 ) != V_452 ) {
F_226 ( L_15 ,
V_453 ) ;
F_79 ( V_420 ,
( V_450 & ~ V_451 )
| V_452 ) ;
}
F_224 ( V_3 , V_3 -> V_95 . V_158 | V_161 ) ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_79 ( V_121 ,
F_71 ( V_121 )
& ~ V_288 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 & ~ V_161 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_65 ( F_1 ( V_3 ) ) ;
if ( V_84 ) {
if ( ! F_229 ( V_3 -> V_95 . V_454 . V_455 ) )
return;
F_67 ( F_230 ( V_3 -> V_95 . V_454 . V_455 ) ) ;
}
}
static void F_134 ( struct V_2 * V_3 )
{
T_9 V_208 = V_3 -> V_95 . V_208 ;
V_3 -> V_95 . V_204 &= ~ V_208 ;
V_3 -> V_95 . V_204 |= F_69 ( V_205 ) & V_208 ;
}
static void F_231 ( struct V_2 * V_3 )
{
if ( V_84 && F_232 ( V_3 ) )
V_3 -> V_95 . V_456 = F_69 ( V_457 ) ;
F_137 ( V_458 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_233 ( struct V_2 * V_3 )
{
T_9 V_459 = V_3 -> V_95 . V_459 ;
V_3 -> V_95 . V_460 &= ~ V_459 ;
V_3 -> V_95 . V_460 |= F_69 ( V_421 ) & V_459 ;
}
static void F_234 ( struct V_2 * V_3 )
{
if ( ! F_136 ( V_354 ,
( unsigned long * ) & V_3 -> V_95 . V_461 ) )
return;
if ( F_232 ( V_3 ) && F_235 ( V_3 ) && ! F_108 ( V_3 ) ) {
F_80 ( V_462 , V_3 -> V_95 . V_454 . V_463 [ 0 ] ) ;
F_80 ( V_464 , V_3 -> V_95 . V_454 . V_463 [ 1 ] ) ;
F_80 ( V_465 , V_3 -> V_95 . V_454 . V_463 [ 2 ] ) ;
F_80 ( V_466 , V_3 -> V_95 . V_454 . V_463 [ 3 ] ) ;
}
}
static void F_180 ( struct V_2 * V_3 )
{
if ( F_232 ( V_3 ) && F_235 ( V_3 ) && ! F_108 ( V_3 ) ) {
V_3 -> V_95 . V_454 . V_463 [ 0 ] = F_72 ( V_462 ) ;
V_3 -> V_95 . V_454 . V_463 [ 1 ] = F_72 ( V_464 ) ;
V_3 -> V_95 . V_454 . V_463 [ 2 ] = F_72 ( V_465 ) ;
V_3 -> V_95 . V_454 . V_463 [ 3 ] = F_72 ( V_466 ) ;
}
F_137 ( V_354 ,
( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
F_137 ( V_354 ,
( unsigned long * ) & V_3 -> V_95 . V_461 ) ;
}
static void F_236 ( unsigned long * V_467 ,
unsigned long V_204 ,
struct V_2 * V_3 )
{
if ( ! F_136 ( V_458 , ( T_9 * ) & V_3 -> V_95 . V_96 ) )
F_231 ( V_3 ) ;
if ( ! ( V_204 & V_468 ) ) {
F_79 ( V_469 ,
F_71 ( V_469 ) |
( V_296 |
V_297 ) ) ;
V_3 -> V_95 . V_204 = V_204 ;
F_237 ( V_3 , F_238 ( V_3 ) ) ;
} else if ( ! F_232 ( V_3 ) ) {
F_79 ( V_469 ,
F_71 ( V_469 ) &
~ ( V_296 |
V_297 ) ) ;
V_3 -> V_95 . V_204 = V_204 ;
F_237 ( V_3 , F_238 ( V_3 ) ) ;
}
if ( ! ( V_204 & V_470 ) )
* V_467 &= ~ V_470 ;
}
static void F_239 ( struct V_2 * V_3 , unsigned long V_204 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_467 ;
if ( V_403 )
V_467 = ( V_204 & ~ V_471 )
| V_472 ;
else
V_467 = ( V_204 & ~ V_473 ) | V_474 ;
if ( V_58 -> V_115 . V_116 && ( V_204 & V_475 ) )
F_215 ( V_3 ) ;
if ( ! V_58 -> V_115 . V_116 && ! ( V_204 & V_475 ) )
F_219 ( V_3 ) ;
#ifdef F_73
if ( V_3 -> V_95 . V_158 & V_162 ) {
if ( ! F_232 ( V_3 ) && ( V_204 & V_468 ) )
F_225 ( V_3 ) ;
if ( F_232 ( V_3 ) && ! ( V_204 & V_468 ) )
F_227 ( V_3 ) ;
}
#endif
if ( V_84 )
F_236 ( & V_467 , V_204 , V_3 ) ;
if ( ! V_3 -> V_117 )
V_467 |= V_206 | V_207 ;
F_76 ( V_217 , V_204 ) ;
F_76 ( V_205 , V_467 ) ;
V_3 -> V_95 . V_204 = V_204 ;
F_139 ( V_223 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static T_5 F_230 ( unsigned long V_455 )
{
T_5 V_69 ;
V_69 = V_476 |
V_477 << V_478 ;
V_69 |= ( V_455 & V_479 ) ;
return V_69 ;
}
static void F_240 ( struct V_2 * V_3 , unsigned long V_456 )
{
unsigned long V_480 ;
T_5 V_69 ;
V_480 = V_456 ;
if ( V_84 ) {
V_69 = F_230 ( V_456 ) ;
F_80 ( V_481 , V_69 ) ;
V_480 = F_232 ( V_3 ) ? F_241 ( V_3 ) :
V_3 -> V_12 -> V_95 . V_482 ;
F_234 ( V_3 ) ;
}
F_228 ( V_3 ) ;
F_76 ( V_457 , V_480 ) ;
}
static int F_237 ( struct V_2 * V_3 , unsigned long V_460 )
{
unsigned long V_483 = V_460 | ( F_1 ( V_3 ) -> V_115 . V_116 ?
V_484 : V_485 ) ;
if ( V_460 & V_367 ) {
if ( ! F_164 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_486 )
return 1 ;
V_3 -> V_95 . V_460 = V_460 ;
if ( V_84 ) {
if ( ! F_232 ( V_3 ) ) {
V_483 &= ~ V_487 ;
V_483 |= V_488 ;
} else if ( ! ( V_460 & V_487 ) ) {
V_483 &= ~ V_487 ;
}
}
F_76 ( V_423 , V_460 ) ;
F_76 ( V_421 , V_483 ) ;
return 0 ;
}
static void F_242 ( struct V_2 * V_3 ,
struct V_489 * V_490 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_407 * V_408 ;
T_2 V_106 ;
if ( V_58 -> V_115 . V_116
&& ( V_92 == V_491 || V_92 == V_425
|| V_92 == V_427 || V_92 == V_430
|| V_92 == V_429 )
&& ! V_424 ) {
switch ( V_92 ) {
case V_491 : V_408 = & V_58 -> V_115 . V_172 ; break;
case V_425 : V_408 = & V_58 -> V_115 . V_426 ; break;
case V_427 : V_408 = & V_58 -> V_115 . V_428 ; break;
case V_430 : V_408 = & V_58 -> V_115 . V_177 ; break;
case V_429 : V_408 = & V_58 -> V_115 . V_181 ; break;
default: F_243 () ;
}
V_490 -> V_99 = V_408 -> V_99 ;
V_490 -> V_102 = V_408 -> V_102 ;
V_490 -> V_104 = V_408 -> V_104 ;
V_106 = V_408 -> V_106 ;
if ( V_92 == V_491
|| V_490 -> V_99 == F_85 ( V_58 , V_92 ) )
goto V_492;
}
V_490 -> V_102 = F_86 ( V_58 , V_92 ) ;
V_490 -> V_104 = F_87 ( V_58 , V_92 ) ;
V_490 -> V_99 = F_85 ( V_58 , V_92 ) ;
V_106 = F_88 ( V_58 , V_92 ) ;
V_492:
if ( ( V_106 & V_493 ) && ! V_424 )
V_106 = 0 ;
V_490 -> type = V_106 & 15 ;
V_490 -> V_169 = ( V_106 >> 4 ) & 1 ;
V_490 -> V_412 = ( V_106 >> 5 ) & 3 ;
V_490 -> V_494 = ( V_106 >> 7 ) & 1 ;
V_490 -> V_495 = ( V_106 >> 12 ) & 1 ;
V_490 -> V_496 = ( V_106 >> 13 ) & 1 ;
V_490 -> V_497 = ( V_106 >> 14 ) & 1 ;
V_490 -> V_498 = ( V_106 >> 15 ) & 1 ;
V_490 -> V_499 = ( V_106 >> 16 ) & 1 ;
}
static T_5 F_244 ( struct V_2 * V_3 , int V_92 )
{
struct V_489 V_169 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
F_242 ( V_3 , & V_169 , V_92 ) ;
return V_169 . V_102 ;
}
return F_86 ( F_1 ( V_3 ) , V_92 ) ;
}
static int F_245 ( struct V_2 * V_3 )
{
if ( ! F_246 ( V_3 ) )
return 0 ;
if ( ! F_108 ( V_3 )
&& ( F_247 ( V_3 ) & V_225 ) )
return 3 ;
return F_85 ( F_1 ( V_3 ) , V_500 ) & 3 ;
}
static int F_248 ( struct V_2 * V_3 )
{
if ( ! F_136 ( V_223 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_137 ( V_223 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_501 = F_245 ( V_3 ) ;
}
return F_1 ( V_3 ) -> V_501 ;
}
static T_2 F_249 ( struct V_489 * V_490 )
{
T_2 V_106 ;
if ( V_490 -> V_499 )
V_106 = 1 << 16 ;
else {
V_106 = V_490 -> type & 15 ;
V_106 |= ( V_490 -> V_169 & 1 ) << 4 ;
V_106 |= ( V_490 -> V_412 & 3 ) << 5 ;
V_106 |= ( V_490 -> V_494 & 1 ) << 7 ;
V_106 |= ( V_490 -> V_495 & 1 ) << 12 ;
V_106 |= ( V_490 -> V_496 & 1 ) << 13 ;
V_106 |= ( V_490 -> V_497 & 1 ) << 14 ;
V_106 |= ( V_490 -> V_498 & 1 ) << 15 ;
}
if ( V_106 == 0 )
V_106 = V_493 ;
return V_106 ;
}
static void F_250 ( struct V_2 * V_3 ,
struct V_489 * V_490 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_409 * V_410 = & V_101 [ V_92 ] ;
T_2 V_106 ;
F_83 ( V_58 ) ;
if ( V_58 -> V_115 . V_116 && V_92 == V_491 ) {
F_78 ( V_410 -> V_99 , V_490 -> V_99 ) ;
V_58 -> V_115 . V_172 . V_99 = V_490 -> V_99 ;
V_58 -> V_115 . V_172 . V_102 = V_490 -> V_102 ;
V_58 -> V_115 . V_172 . V_104 = V_490 -> V_104 ;
V_58 -> V_115 . V_172 . V_106 = F_249 ( V_490 ) ;
return;
}
F_76 ( V_410 -> V_102 , V_490 -> V_102 ) ;
F_79 ( V_410 -> V_104 , V_490 -> V_104 ) ;
F_78 ( V_410 -> V_99 , V_490 -> V_99 ) ;
if ( V_58 -> V_115 . V_116 && V_490 -> V_169 ) {
if ( V_490 -> V_102 == 0xffff0000 && V_490 -> V_99 == 0xf000 )
F_76 ( V_410 -> V_102 , 0xf0000 ) ;
V_106 = 0xf3 ;
} else
V_106 = F_249 ( V_490 ) ;
if ( V_403 && ( V_92 != V_502 ) )
V_106 |= 0x1 ;
F_79 ( V_410 -> V_108 , V_106 ) ;
F_139 ( V_223 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_251 ( struct V_2 * V_3 , int * V_497 , int * V_496 )
{
T_2 V_106 = F_88 ( F_1 ( V_3 ) , V_500 ) ;
* V_497 = ( V_106 >> 14 ) & 1 ;
* V_496 = ( V_106 >> 13 ) & 1 ;
}
static void F_252 ( struct V_2 * V_3 , struct V_148 * V_503 )
{
V_503 -> V_390 = F_71 ( V_504 ) ;
V_503 -> V_153 = F_69 ( V_505 ) ;
}
static void F_253 ( struct V_2 * V_3 , struct V_148 * V_503 )
{
F_79 ( V_504 , V_503 -> V_390 ) ;
F_76 ( V_505 , V_503 -> V_153 ) ;
}
static void F_254 ( struct V_2 * V_3 , struct V_148 * V_503 )
{
V_503 -> V_390 = F_71 ( V_506 ) ;
V_503 -> V_153 = F_69 ( V_507 ) ;
}
static void F_255 ( struct V_2 * V_3 , struct V_148 * V_503 )
{
F_79 ( V_506 , V_503 -> V_390 ) ;
F_76 ( V_507 , V_503 -> V_153 ) ;
}
static bool F_256 ( struct V_2 * V_3 , int V_92 )
{
struct V_489 V_490 ;
T_2 V_106 ;
F_242 ( V_3 , & V_490 , V_92 ) ;
V_106 = F_249 ( & V_490 ) ;
if ( V_490 . V_102 != ( V_490 . V_99 << 4 ) )
return false ;
if ( V_490 . V_104 != 0xffff )
return false ;
if ( V_106 != 0xf3 )
return false ;
return true ;
}
static bool F_257 ( struct V_2 * V_3 )
{
struct V_489 V_508 ;
unsigned int V_509 ;
F_242 ( V_3 , & V_508 , V_500 ) ;
V_509 = V_508 . V_99 & V_413 ;
if ( V_508 . V_499 )
return false ;
if ( ~ V_508 . type & ( V_510 | V_511 ) )
return false ;
if ( ! V_508 . V_169 )
return false ;
if ( V_508 . type & V_512 ) {
if ( V_508 . V_412 > V_509 )
return false ;
} else {
if ( V_508 . V_412 != V_509 )
return false ;
}
if ( ! V_508 . V_494 )
return false ;
return true ;
}
static bool F_258 ( struct V_2 * V_3 )
{
struct V_489 V_513 ;
unsigned int V_514 ;
F_242 ( V_3 , & V_513 , V_515 ) ;
V_514 = V_513 . V_99 & V_413 ;
if ( V_513 . V_499 )
return true ;
if ( V_513 . type != 3 && V_513 . type != 7 )
return false ;
if ( ! V_513 . V_169 )
return false ;
if ( V_513 . V_412 != V_514 )
return false ;
if ( ! V_513 . V_494 )
return false ;
return true ;
}
static bool F_259 ( struct V_2 * V_3 , int V_92 )
{
struct V_489 V_490 ;
unsigned int V_516 ;
F_242 ( V_3 , & V_490 , V_92 ) ;
V_516 = V_490 . V_99 & V_413 ;
if ( V_490 . V_499 )
return true ;
if ( ! V_490 . V_169 )
return false ;
if ( ! V_490 . V_494 )
return false ;
if ( ~ V_490 . type & ( V_510 | V_512 ) ) {
if ( V_490 . V_412 < V_516 )
return false ;
}
return true ;
}
static bool F_260 ( struct V_2 * V_3 )
{
struct V_489 V_172 ;
F_242 ( V_3 , & V_172 , V_491 ) ;
if ( V_172 . V_499 )
return false ;
if ( V_172 . V_99 & V_517 )
return false ;
if ( V_172 . type != 3 && V_172 . type != 11 )
return false ;
if ( ! V_172 . V_494 )
return false ;
return true ;
}
static bool F_261 ( struct V_2 * V_3 )
{
struct V_489 V_518 ;
F_242 ( V_3 , & V_518 , V_502 ) ;
if ( V_518 . V_499 )
return true ;
if ( V_518 . V_99 & V_517 )
return false ;
if ( V_518 . type != 2 )
return false ;
if ( ! V_518 . V_494 )
return false ;
return true ;
}
static bool F_262 ( struct V_2 * V_3 )
{
struct V_489 V_508 , V_513 ;
F_242 ( V_3 , & V_508 , V_500 ) ;
F_242 ( V_3 , & V_513 , V_515 ) ;
return ( ( V_508 . V_99 & V_413 ) ==
( V_513 . V_99 & V_413 ) ) ;
}
static bool F_263 ( struct V_2 * V_3 )
{
if ( ! F_246 ( V_3 ) ) {
if ( ! F_256 ( V_3 , V_500 ) )
return false ;
if ( ! F_256 ( V_3 , V_515 ) )
return false ;
if ( ! F_256 ( V_3 , V_427 ) )
return false ;
if ( ! F_256 ( V_3 , V_425 ) )
return false ;
if ( ! F_256 ( V_3 , V_430 ) )
return false ;
if ( ! F_256 ( V_3 , V_429 ) )
return false ;
} else {
if ( ! F_262 ( V_3 ) )
return false ;
if ( ! F_257 ( V_3 ) )
return false ;
if ( ! F_258 ( V_3 ) )
return false ;
if ( ! F_259 ( V_3 , V_427 ) )
return false ;
if ( ! F_259 ( V_3 , V_425 ) )
return false ;
if ( ! F_259 ( V_3 , V_430 ) )
return false ;
if ( ! F_259 ( V_3 , V_429 ) )
return false ;
if ( ! F_260 ( V_3 ) )
return false ;
if ( ! F_261 ( V_3 ) )
return false ;
}
return true ;
}
static int F_264 ( struct V_12 * V_12 )
{
T_13 V_519 ;
T_3 V_164 = 0 ;
int V_520 , V_521 , V_93 = 0 ;
V_521 = F_222 ( & V_12 -> V_442 ) ;
V_519 = F_216 ( V_12 ) >> V_13 ;
V_520 = F_265 ( V_12 , V_519 , 0 , V_389 ) ;
if ( V_520 < 0 )
goto V_522;
V_164 = V_523 + V_524 ;
V_520 = F_266 ( V_12 , V_519 ++ , & V_164 ,
V_525 , sizeof( T_3 ) ) ;
if ( V_520 < 0 )
goto V_522;
V_520 = F_265 ( V_12 , V_519 ++ , 0 , V_389 ) ;
if ( V_520 < 0 )
goto V_522;
V_520 = F_265 ( V_12 , V_519 , 0 , V_389 ) ;
if ( V_520 < 0 )
goto V_522;
V_164 = ~ 0 ;
V_520 = F_266 ( V_12 , V_519 , & V_164 ,
V_444 - 2 * V_389 - 1 ,
sizeof( T_6 ) ) ;
if ( V_520 < 0 )
goto V_522;
V_93 = 1 ;
V_522:
F_220 ( & V_12 -> V_442 , V_521 ) ;
return V_93 ;
}
static int F_267 ( struct V_12 * V_12 )
{
int V_60 , V_521 , V_520 , V_93 ;
T_14 V_526 ;
T_2 V_253 ;
if ( ! V_84 )
return 1 ;
if ( F_77 ( ! V_12 -> V_95 . V_527 ) ) {
F_54 ( V_74 L_16
L_17 ) ;
return 0 ;
}
if ( F_268 ( V_12 -> V_95 . V_528 ) )
return 1 ;
V_93 = 0 ;
V_526 = V_12 -> V_95 . V_482 >> V_13 ;
V_521 = F_222 ( & V_12 -> V_442 ) ;
V_520 = F_265 ( V_12 , V_526 , 0 , V_389 ) ;
if ( V_520 < 0 )
goto V_522;
for ( V_60 = 0 ; V_60 < V_529 ; V_60 ++ ) {
V_253 = ( V_60 << 22 ) + ( V_530 | V_531 | V_532 |
V_533 | V_534 | V_535 ) ;
V_520 = F_266 ( V_12 , V_526 ,
& V_253 , V_60 * sizeof( V_253 ) , sizeof( V_253 ) ) ;
if ( V_520 < 0 )
goto V_522;
}
V_12 -> V_95 . V_528 = true ;
V_93 = 1 ;
V_522:
F_220 ( & V_12 -> V_442 , V_521 ) ;
return V_93 ;
}
static void F_269 ( int V_92 )
{
struct V_409 * V_410 = & V_101 [ V_92 ] ;
unsigned int V_106 ;
F_78 ( V_410 -> V_99 , 0 ) ;
F_76 ( V_410 -> V_102 , 0 ) ;
F_79 ( V_410 -> V_104 , 0xffff ) ;
if ( V_403 ) {
V_106 = 0x93 ;
if ( V_92 == V_500 )
V_106 |= 0x08 ;
} else
V_106 = 0xf3 ;
F_79 ( V_410 -> V_108 , V_106 ) ;
}
static int F_270 ( struct V_12 * V_12 )
{
struct V_536 V_537 ;
int V_520 = 0 ;
F_271 ( & V_12 -> V_538 ) ;
if ( V_12 -> V_95 . V_539 )
goto V_522;
V_537 . V_439 = V_540 ;
V_537 . V_415 = 0 ;
V_537 . V_541 = 0xfee00000ULL ;
V_537 . V_542 = V_389 ;
V_520 = F_272 ( V_12 , & V_537 , 0 ) ;
if ( V_520 )
goto V_522;
V_12 -> V_95 . V_539 = F_6 ( V_12 , 0xfee00 ) ;
V_522:
F_273 ( & V_12 -> V_538 ) ;
return V_520 ;
}
static int F_274 ( struct V_12 * V_12 )
{
struct V_536 V_537 ;
int V_520 = 0 ;
F_271 ( & V_12 -> V_538 ) ;
if ( V_12 -> V_95 . V_527 )
goto V_522;
V_537 . V_439 = V_543 ;
V_537 . V_415 = 0 ;
V_537 . V_541 =
V_12 -> V_95 . V_482 ;
V_537 . V_542 = V_389 ;
V_520 = F_272 ( V_12 , & V_537 , 0 ) ;
if ( V_520 )
goto V_522;
V_12 -> V_95 . V_527 = F_6 ( V_12 ,
V_12 -> V_95 . V_482 >> V_13 ) ;
V_522:
F_273 ( & V_12 -> V_538 ) ;
return V_520 ;
}
static void F_275 ( struct V_1 * V_58 )
{
int V_42 ;
V_58 -> V_42 = 0 ;
if ( ! V_402 )
return;
F_276 ( & V_544 ) ;
V_42 = F_277 ( V_545 , V_546 ) ;
if ( V_42 < V_546 ) {
V_58 -> V_42 = V_42 ;
F_137 ( V_42 , V_545 ) ;
}
F_278 ( & V_544 ) ;
}
static void F_279 ( struct V_1 * V_58 )
{
if ( ! V_402 )
return;
F_276 ( & V_544 ) ;
if ( V_58 -> V_42 != 0 )
F_139 ( V_58 -> V_42 , V_545 ) ;
F_278 ( & V_544 ) ;
}
static void F_280 ( unsigned long * V_254 , T_2 V_59 )
{
int V_547 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_59 <= 0x1fff ) {
F_139 ( V_59 , V_254 + 0x000 / V_547 ) ;
F_139 ( V_59 , V_254 + 0x800 / V_547 ) ;
} else if ( ( V_59 >= 0xc0000000 ) && ( V_59 <= 0xc0001fff ) ) {
V_59 &= 0x1fff ;
F_139 ( V_59 , V_254 + 0x400 / V_547 ) ;
F_139 ( V_59 , V_254 + 0xc00 / V_547 ) ;
}
}
static void F_281 ( T_2 V_59 , bool V_548 )
{
if ( ! V_548 )
F_280 ( V_262 , V_59 ) ;
F_280 ( V_261 , V_59 ) ;
}
static void F_282 ( void )
{
T_2 V_549 , V_550 ;
unsigned long V_551 ;
struct V_148 V_503 ;
F_76 ( V_552 , F_283 () | V_206 ) ;
F_76 ( V_553 , F_187 () ) ;
F_76 ( V_554 , F_284 () ) ;
F_78 ( V_555 , V_556 ) ;
F_78 ( V_557 , V_558 ) ;
F_78 ( V_559 , V_558 ) ;
F_78 ( V_560 , V_558 ) ;
F_78 ( V_561 , V_154 * 8 ) ;
F_285 ( & V_503 ) ;
F_76 ( V_562 , V_503 . V_153 ) ;
asm("mov $.Lkvm_vmx_return, %0" : "=r"(tmpl));
F_76 ( V_563 , V_551 ) ;
F_166 ( V_338 , V_549 , V_550 ) ;
F_79 ( V_564 , V_549 ) ;
F_107 ( V_340 , V_551 ) ;
F_76 ( V_565 , V_551 ) ;
if ( V_24 . V_393 & V_388 ) {
F_166 ( V_343 , V_549 , V_550 ) ;
F_80 ( V_566 , V_549 | ( ( T_5 ) V_550 << 32 ) ) ;
}
}
static void F_286 ( struct V_1 * V_58 )
{
V_58 -> V_3 . V_95 . V_459 = V_567 ;
if ( V_84 )
V_58 -> V_3 . V_95 . V_459 |= V_568 ;
if ( F_90 ( & V_58 -> V_3 ) )
V_58 -> V_3 . V_95 . V_459 &=
~ F_4 ( & V_58 -> V_3 ) -> V_215 ;
F_76 ( V_569 , ~ V_58 -> V_3 . V_95 . V_459 ) ;
}
static T_2 F_287 ( struct V_1 * V_58 )
{
T_2 V_570 = V_24 . V_25 ;
if ( ! F_19 ( V_58 -> V_3 . V_12 ) ) {
V_570 &= ~ V_27 ;
#ifdef F_73
V_570 |= V_299 |
V_298 ;
#endif
}
if ( ! V_84 )
V_570 |= V_297 |
V_296 |
V_294 ;
return V_570 ;
}
static T_2 F_288 ( struct V_1 * V_58 )
{
T_2 V_570 = V_24 . V_29 ;
if ( ! F_38 ( V_58 -> V_3 . V_12 ) )
V_570 &= ~ V_30 ;
if ( V_58 -> V_42 == 0 )
V_570 &= ~ V_49 ;
if ( ! V_84 ) {
V_570 &= ~ V_45 ;
V_403 = 0 ;
}
if ( ! V_403 )
V_570 &= ~ V_46 ;
if ( ! V_406 )
V_570 &= ~ V_47 ;
return V_570 ;
}
static void F_289 ( void )
{
F_290 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_291 ( struct V_1 * V_58 )
{
#ifdef F_73
unsigned long V_571 ;
#endif
int V_60 ;
F_80 ( V_572 , F_53 ( V_573 ) ) ;
F_80 ( V_574 , F_53 ( V_575 ) ) ;
if ( F_17 () )
F_80 ( V_263 , F_53 ( V_262 ) ) ;
F_80 ( V_576 , - 1ull ) ;
F_79 ( V_577 ,
V_24 . V_51 ) ;
F_79 ( V_469 , F_287 ( V_58 ) ) ;
if ( F_21 () ) {
F_79 ( V_578 ,
F_288 ( V_58 ) ) ;
}
if ( V_406 ) {
F_79 ( V_579 , V_406 ) ;
F_79 ( V_580 , V_581 ) ;
}
F_79 ( V_582 , 0 ) ;
F_79 ( V_583 , 0 ) ;
F_79 ( V_584 , 0 ) ;
F_78 ( V_179 , 0 ) ;
F_78 ( V_183 , 0 ) ;
F_282 () ;
#ifdef F_73
F_107 ( V_185 , V_571 ) ;
F_76 ( V_184 , V_571 ) ;
F_107 ( V_187 , V_571 ) ;
F_76 ( V_186 , V_571 ) ;
#else
F_76 ( V_184 , 0 ) ;
F_76 ( V_186 , 0 ) ;
#endif
F_79 ( V_585 , 0 ) ;
F_79 ( V_137 , 0 ) ;
F_80 ( V_586 , F_53 ( V_58 -> V_123 . V_135 ) ) ;
F_79 ( V_136 , 0 ) ;
F_80 ( V_587 , F_53 ( V_58 -> V_123 . V_134 ) ) ;
if ( V_24 . V_344 & V_287 ) {
T_2 V_588 , V_589 ;
T_5 V_590 ;
F_166 ( V_343 , V_588 , V_589 ) ;
V_590 = V_588 | ( ( T_5 ) V_589 << 32 ) ;
F_80 ( V_345 , V_590 ) ;
V_58 -> V_3 . V_95 . V_346 = V_590 ;
}
for ( V_60 = 0 ; V_60 < V_591 ; ++ V_60 ) {
T_2 V_64 = V_62 [ V_60 ] ;
T_2 V_592 , V_593 ;
int V_594 = V_58 -> V_61 ;
if ( F_292 ( V_64 , & V_592 , & V_593 ) < 0 )
continue;
if ( F_293 ( V_64 , V_592 , V_593 ) < 0 )
continue;
V_58 -> V_63 [ V_594 ] . V_64 = V_60 ;
V_58 -> V_63 [ V_594 ] . V_164 = 0 ;
V_58 -> V_63 [ V_594 ] . V_89 = - 1ull ;
++ V_58 -> V_61 ;
}
F_79 ( V_122 , V_24 . V_393 ) ;
F_79 ( V_121 , V_24 . V_344 ) ;
F_76 ( V_210 , ~ 0UL ) ;
F_286 ( V_58 ) ;
F_178 ( & V_58 -> V_3 , 0 ) ;
return 0 ;
}
static int F_294 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_5 V_59 ;
int V_93 ;
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_352 ) | ( 1 << V_349 ) ) ;
V_58 -> V_115 . V_116 = 0 ;
V_58 -> V_595 = 0 ;
V_58 -> V_3 . V_95 . V_350 [ V_596 ] = F_295 () ;
F_296 ( & V_58 -> V_3 , 0 ) ;
V_59 = 0xfee00000 | V_597 ;
if ( F_297 ( & V_58 -> V_3 ) )
V_59 |= V_598 ;
F_298 ( & V_58 -> V_3 , V_59 ) ;
V_93 = F_299 ( & V_58 -> V_3 ) ;
if ( V_93 != 0 )
goto V_522;
F_83 ( V_58 ) ;
F_269 ( V_500 ) ;
if ( F_297 ( & V_58 -> V_3 ) ) {
F_78 ( V_433 , 0xf000 ) ;
F_76 ( V_449 , 0x000f0000 ) ;
} else {
F_78 ( V_433 , V_58 -> V_3 . V_95 . V_599 << 8 ) ;
F_76 ( V_449 , V_58 -> V_3 . V_95 . V_599 << 12 ) ;
}
F_269 ( V_427 ) ;
F_269 ( V_425 ) ;
F_269 ( V_430 ) ;
F_269 ( V_429 ) ;
F_269 ( V_515 ) ;
F_78 ( V_417 , 0 ) ;
F_76 ( V_418 , 0 ) ;
F_79 ( V_419 , 0xffff ) ;
F_79 ( V_420 , 0x008b ) ;
F_78 ( V_600 , 0 ) ;
F_76 ( V_601 , 0 ) ;
F_79 ( V_602 , 0xffff ) ;
F_79 ( V_603 , 0x00082 ) ;
F_79 ( V_339 , 0 ) ;
F_76 ( V_342 , 0 ) ;
F_76 ( V_341 , 0 ) ;
F_76 ( V_221 , 0x02 ) ;
if ( F_297 ( & V_58 -> V_3 ) )
F_144 ( V_3 , 0xfff0 ) ;
else
F_144 ( V_3 , 0 ) ;
F_300 ( V_3 , V_349 , 0 ) ;
F_76 ( V_358 , 0x400 ) ;
F_76 ( V_507 , 0 ) ;
F_79 ( V_506 , 0xffff ) ;
F_76 ( V_505 , 0 ) ;
F_79 ( V_504 , 0xffff ) ;
F_79 ( V_236 , V_238 ) ;
F_79 ( V_227 , 0 ) ;
F_79 ( V_604 , 0 ) ;
F_80 ( V_605 , 0 ) ;
F_153 ( V_58 ) ;
F_79 ( V_250 , 0 ) ;
if ( F_18 () ) {
F_80 ( V_606 , 0 ) ;
if ( F_19 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_606 ,
F_53 ( V_58 -> V_3 . V_95 . V_607 -> V_350 ) ) ;
F_79 ( V_608 , 0 ) ;
}
if ( F_38 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_609 ,
F_301 ( V_58 -> V_3 . V_12 -> V_95 . V_539 ) ) ;
if ( V_58 -> V_42 != 0 )
F_78 ( V_610 , V_58 -> V_42 ) ;
V_58 -> V_3 . V_95 . V_204 = V_611 | V_612 | V_613 ;
F_239 ( & V_58 -> V_3 , F_302 ( V_3 ) ) ;
F_237 ( & V_58 -> V_3 , 0 ) ;
F_224 ( & V_58 -> V_3 , 0 ) ;
F_129 ( & V_58 -> V_3 ) ;
F_89 ( & V_58 -> V_3 ) ;
F_65 ( V_58 ) ;
V_93 = 0 ;
V_58 -> V_416 = 0 ;
V_522:
return V_93 ;
}
static bool F_303 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_57 &
V_279 ;
}
static void F_304 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( F_90 ( V_3 ) && F_303 ( V_3 ) ) {
F_123 ( V_614 , V_3 ) ;
return;
}
V_55 = F_71 ( V_469 ) ;
V_55 |= V_292 ;
F_79 ( V_469 , V_55 ) ;
}
static void F_305 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( ! F_41 () ) {
F_304 ( V_3 ) ;
return;
}
if ( F_71 ( V_227 ) & V_228 ) {
F_304 ( V_3 ) ;
return;
}
V_55 = F_71 ( V_469 ) ;
V_55 |= V_615 ;
F_79 ( V_469 , V_55 ) ;
}
static void F_306 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_15 V_616 ;
int V_617 = V_3 -> V_95 . V_618 . V_133 ;
F_307 ( V_617 ) ;
++ V_3 -> V_192 . V_619 ;
if ( V_58 -> V_115 . V_116 ) {
int V_244 = 0 ;
if ( V_3 -> V_95 . V_618 . V_620 )
V_244 = V_3 -> V_95 . V_245 ;
if ( F_150 ( V_3 , V_617 , V_244 ) != V_246 )
F_123 ( V_247 , V_3 ) ;
return;
}
V_616 = V_617 | V_17 ;
if ( V_3 -> V_95 . V_618 . V_620 ) {
V_616 |= V_621 ;
F_79 ( V_248 ,
V_58 -> V_3 . V_95 . V_245 ) ;
} else
V_616 |= V_22 ;
F_79 ( V_250 , V_616 ) ;
F_145 ( V_3 ) ;
}
static void F_308 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) )
return;
if ( ! F_41 () ) {
V_58 -> V_595 = 1 ;
V_58 -> V_622 = 0 ;
}
++ V_3 -> V_192 . V_623 ;
V_58 -> V_624 = false ;
if ( V_58 -> V_115 . V_116 ) {
if ( F_150 ( V_3 , V_625 , 0 ) != V_246 )
F_123 ( V_247 , V_3 ) ;
return;
}
F_79 ( V_250 ,
V_626 | V_17 | V_625 ) ;
F_145 ( V_3 ) ;
}
static int F_309 ( struct V_2 * V_3 )
{
if ( ! F_41 () && F_1 ( V_3 ) -> V_595 )
return 0 ;
return ! ( F_71 ( V_227 ) &
( V_230 | V_228
| V_627 ) ) ;
}
static bool F_310 ( struct V_2 * V_3 )
{
if ( ! F_41 () )
return F_1 ( V_3 ) -> V_595 ;
if ( F_1 ( V_3 ) -> V_624 )
return false ;
return F_71 ( V_227 ) & V_627 ;
}
static void F_311 ( struct V_2 * V_3 , bool V_628 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_41 () ) {
if ( V_58 -> V_595 != V_628 ) {
V_58 -> V_595 = V_628 ;
V_58 -> V_622 = 0 ;
}
} else {
V_58 -> V_624 = ! V_628 ;
if ( V_628 )
F_82 ( V_227 ,
V_627 ) ;
else
F_81 ( V_227 ,
V_627 ) ;
}
}
static int F_312 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) && F_303 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_629 ||
( V_7 -> V_630 &
V_631 ) )
return 0 ;
F_147 ( V_3 ) ;
V_7 -> V_632 = V_633 ;
V_7 -> V_634 = 0 ;
}
return ( F_69 ( V_221 ) & V_635 ) &&
! ( F_71 ( V_227 ) &
( V_228 | V_230 ) ) ;
}
static int F_221 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_93 ;
struct V_536 V_636 = {
. V_439 = V_637 ,
. V_541 = V_11 ,
. V_542 = V_389 * 3 ,
. V_415 = 0 ,
} ;
V_93 = F_313 ( V_12 , & V_636 , 0 ) ;
if ( V_93 )
return V_93 ;
V_12 -> V_95 . V_435 = V_11 ;
if ( ! F_264 ( V_12 ) )
return - V_400 ;
return 0 ;
}
static int F_314 ( struct V_2 * V_3 ,
int V_638 , T_2 V_639 )
{
if ( ( ( V_638 == V_315 ) || ( V_638 == V_640 ) ) && V_639 == 0 )
if ( F_315 ( V_3 , 0 ) == V_246 )
return 1 ;
switch ( V_638 ) {
case V_110 :
if ( V_3 -> V_111 &
( V_641 | V_357 ) )
return 0 ;
F_316 ( V_3 , V_638 ) ;
return 1 ;
case V_114 :
F_1 ( V_3 ) -> V_3 . V_95 . V_245 =
F_71 ( V_234 ) ;
if ( V_3 -> V_111 & V_113 )
return 0 ;
case V_642 :
case V_643 :
case V_644 :
case V_21 :
case V_645 :
case V_640 :
case V_315 :
case V_646 :
F_316 ( V_3 , V_638 ) ;
return 1 ;
}
return 0 ;
}
static void F_317 ( void )
{
#if F_318 ( V_647 ) && F_318 ( F_73 )
struct V_648 V_350 = {
. V_508 = 3 ,
. V_415 = V_635 ,
} ;
F_319 ( & V_350 , 0 ) ;
#endif
}
static int F_320 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_321 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_649 * V_649 = V_3 -> V_650 ;
T_2 V_14 , V_651 , V_240 ;
unsigned long V_652 , V_233 , V_653 ;
T_2 V_654 ;
enum V_655 V_656 ;
V_654 = V_58 -> V_657 ;
V_14 = V_58 -> V_658 ;
if ( F_16 ( V_14 ) )
return F_320 ( V_3 ) ;
if ( ( V_654 & V_631 ) &&
! F_12 ( V_14 ) ) {
V_3 -> V_650 -> V_659 = V_660 ;
V_3 -> V_650 -> V_661 . V_662 = V_663 ;
V_3 -> V_650 -> V_661 . V_664 = 2 ;
V_3 -> V_650 -> V_661 . V_164 [ 0 ] = V_654 ;
V_3 -> V_650 -> V_661 . V_164 [ 1 ] = V_14 ;
return 0 ;
}
if ( ( V_14 & V_15 ) == V_626 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_129 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_656 = F_315 ( V_3 , V_665 ) ;
if ( V_656 != V_246 )
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
V_240 = 0 ;
if ( V_14 & V_243 )
V_240 = F_71 ( V_666 ) ;
if ( F_12 ( V_14 ) ) {
F_322 ( V_84 ) ;
V_652 = F_69 ( V_667 ) ;
F_323 ( V_652 , V_240 ) ;
if ( F_324 ( V_3 ) )
F_325 ( V_3 , V_652 ) ;
return F_326 ( V_3 , V_652 , V_240 , NULL , 0 ) ;
}
if ( V_58 -> V_115 . V_116 &&
F_314 ( V_3 , V_14 & V_16 ,
V_240 ) ) {
if ( V_3 -> V_95 . V_668 ) {
V_3 -> V_95 . V_668 = 0 ;
return F_327 ( V_3 ) ;
}
return 1 ;
}
V_651 = V_14 & V_16 ;
switch ( V_651 ) {
case V_110 :
V_653 = F_69 ( V_667 ) ;
if ( ! ( V_3 -> V_111 &
( V_641 | V_357 ) ) ) {
V_3 -> V_95 . V_653 = V_653 | V_669 ;
F_316 ( V_3 , V_110 ) ;
return 1 ;
}
V_649 -> V_670 . V_95 . V_653 = V_653 | V_669 ;
V_649 -> V_670 . V_95 . V_360 = F_69 ( V_358 ) ;
case V_114 :
V_58 -> V_3 . V_95 . V_245 =
F_71 ( V_234 ) ;
V_649 -> V_659 = V_671 ;
V_233 = F_143 ( V_3 ) ;
V_649 -> V_670 . V_95 . V_672 = F_69 ( V_449 ) + V_233 ;
V_649 -> V_670 . V_95 . V_673 = V_651 ;
break;
default:
V_649 -> V_659 = V_674 ;
V_649 -> V_675 . V_673 = V_651 ;
V_649 -> V_675 . V_240 = V_240 ;
break;
}
return 0 ;
}
static int F_328 ( struct V_2 * V_3 )
{
++ V_3 -> V_192 . V_676 ;
return 1 ;
}
static int F_329 ( struct V_2 * V_3 )
{
V_3 -> V_650 -> V_659 = V_677 ;
return 0 ;
}
static int F_330 ( struct V_2 * V_3 )
{
unsigned long V_678 ;
int V_390 , V_679 , string ;
unsigned V_680 ;
V_678 = F_69 ( V_667 ) ;
string = ( V_678 & 16 ) != 0 ;
V_679 = ( V_678 & 8 ) != 0 ;
++ V_3 -> V_192 . V_681 ;
if ( string || V_679 )
return F_315 ( V_3 , 0 ) == V_246 ;
V_680 = V_678 >> 16 ;
V_390 = ( V_678 & 7 ) + 1 ;
F_142 ( V_3 ) ;
return F_331 ( V_3 , V_390 , V_680 ) ;
}
static void
F_332 ( struct V_2 * V_3 , unsigned char * V_682 )
{
V_682 [ 0 ] = 0x0f ;
V_682 [ 1 ] = 0x01 ;
V_682 [ 2 ] = 0xc1 ;
}
static int F_333 ( struct V_2 * V_3 , unsigned long V_683 )
{
if ( F_1 ( V_3 ) -> V_8 . V_486 &&
( ( V_683 & F_171 ) != F_171 ) )
return 1 ;
if ( F_90 ( V_3 ) ) {
if ( F_334 ( V_3 , ( V_683 & V_3 -> V_95 . V_208 ) |
( V_3 -> V_95 . V_204 & ~ V_3 -> V_95 . V_208 ) ) )
return 1 ;
F_76 ( V_217 , V_683 ) ;
return 0 ;
} else
return F_334 ( V_3 , V_683 ) ;
}
static int F_335 ( struct V_2 * V_3 , unsigned long V_683 )
{
if ( F_90 ( V_3 ) ) {
if ( F_336 ( V_3 , ( V_683 & V_3 -> V_95 . V_459 ) |
( V_3 -> V_95 . V_460 & ~ V_3 -> V_95 . V_459 ) ) )
return 1 ;
F_76 ( V_423 , V_683 ) ;
return 0 ;
} else
return F_336 ( V_3 , V_683 ) ;
}
static void F_337 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) ) {
F_76 ( V_217 ,
F_69 ( V_217 ) & ~ V_206 ) ;
V_3 -> V_95 . V_204 &= ~ V_206 ;
} else
F_239 ( V_3 , F_130 ( V_3 , ~ V_206 ) ) ;
}
static int F_338 ( struct V_2 * V_3 )
{
unsigned long V_678 , V_683 ;
int V_684 ;
int V_348 ;
int V_685 ;
V_678 = F_69 ( V_667 ) ;
V_684 = V_678 & 15 ;
V_348 = ( V_678 >> 8 ) & 15 ;
switch ( ( V_678 >> 4 ) & 3 ) {
case 0 :
V_683 = F_339 ( V_3 , V_348 ) ;
F_340 ( V_684 , V_683 ) ;
switch ( V_684 ) {
case 0 :
V_685 = F_333 ( V_3 , V_683 ) ;
F_341 ( V_3 , V_685 ) ;
return 1 ;
case 3 :
V_685 = F_342 ( V_3 , V_683 ) ;
F_341 ( V_3 , V_685 ) ;
return 1 ;
case 4 :
V_685 = F_335 ( V_3 , V_683 ) ;
F_341 ( V_3 , V_685 ) ;
return 1 ;
case 8 : {
T_6 V_686 = F_343 ( V_3 ) ;
T_6 V_687 = F_339 ( V_3 , V_348 ) ;
V_685 = F_296 ( V_3 , V_687 ) ;
F_341 ( V_3 , V_685 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_686 <= V_687 )
return 1 ;
V_3 -> V_650 -> V_659 = V_688 ;
return 0 ;
}
} ;
break;
case 2 :
F_337 ( V_3 ) ;
F_340 ( 0 , F_302 ( V_3 ) ) ;
F_142 ( V_3 ) ;
F_129 ( V_3 ) ;
return 1 ;
case 1 :
switch ( V_684 ) {
case 3 :
V_683 = F_241 ( V_3 ) ;
F_300 ( V_3 , V_348 , V_683 ) ;
F_344 ( V_684 , V_683 ) ;
F_142 ( V_3 ) ;
return 1 ;
case 8 :
V_683 = F_343 ( V_3 ) ;
F_300 ( V_3 , V_348 , V_683 ) ;
F_344 ( V_684 , V_683 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_683 = ( V_678 >> V_689 ) & 0x0f ;
F_340 ( 0 , ( F_302 ( V_3 ) & ~ 0xful ) | V_683 ) ;
F_345 ( V_3 , V_683 ) ;
F_142 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_650 -> V_659 = 0 ;
F_346 ( V_3 , L_18 ,
( int ) ( V_678 >> 4 ) & 3 , V_684 ) ;
return 0 ;
}
static int F_347 ( struct V_2 * V_3 )
{
unsigned long V_678 ;
int V_690 , V_348 ;
if ( ! F_348 ( V_3 , 0 ) )
return 1 ;
V_690 = F_69 ( V_358 ) ;
if ( V_690 & V_691 ) {
if ( V_3 -> V_111 & V_357 ) {
V_3 -> V_650 -> V_670 . V_95 . V_653 = V_3 -> V_95 . V_653 ;
V_3 -> V_650 -> V_670 . V_95 . V_360 = V_690 ;
V_3 -> V_650 -> V_670 . V_95 . V_672 =
F_69 ( V_449 ) +
F_69 ( V_353 ) ;
V_3 -> V_650 -> V_670 . V_95 . V_673 = V_110 ;
V_3 -> V_650 -> V_659 = V_671 ;
return 0 ;
} else {
V_3 -> V_95 . V_360 &= ~ V_691 ;
V_3 -> V_95 . V_653 |= V_692 ;
F_76 ( V_358 , V_3 -> V_95 . V_360 ) ;
F_316 ( V_3 , V_110 ) ;
return 1 ;
}
}
V_678 = F_69 ( V_667 ) ;
V_690 = V_678 & V_693 ;
V_348 = F_349 ( V_678 ) ;
if ( V_678 & V_694 ) {
unsigned long V_683 ;
if ( ! F_350 ( V_3 , V_690 , & V_683 ) )
F_300 ( V_3 , V_348 , V_683 ) ;
} else
F_351 ( V_3 , V_690 , V_3 -> V_95 . V_350 [ V_348 ] ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static void F_352 ( struct V_2 * V_3 , unsigned long V_683 )
{
F_76 ( V_358 , V_683 ) ;
}
static int F_353 ( struct V_2 * V_3 )
{
F_354 ( V_3 ) ;
return 1 ;
}
static int F_355 ( struct V_2 * V_3 )
{
T_2 V_275 = V_3 -> V_95 . V_350 [ V_695 ] ;
T_5 V_164 ;
if ( F_174 ( V_3 , V_275 , & V_164 ) ) {
F_356 ( V_275 ) ;
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_358 ( V_275 , V_164 ) ;
V_3 -> V_95 . V_350 [ V_696 ] = V_164 & - 1u ;
V_3 -> V_95 . V_350 [ V_596 ] = ( V_164 >> 32 ) & - 1u ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_359 ( struct V_2 * V_3 )
{
T_2 V_275 = V_3 -> V_95 . V_350 [ V_695 ] ;
T_5 V_164 = ( V_3 -> V_95 . V_350 [ V_696 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_95 . V_350 [ V_596 ] & - 1u ) << 32 ) ;
if ( F_176 ( V_3 , V_275 , V_164 ) != 0 ) {
F_360 ( V_275 , V_164 ) ;
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_361 ( V_275 , V_164 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_362 ( struct V_2 * V_3 )
{
F_123 ( V_697 , V_3 ) ;
return 1 ;
}
static int F_363 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_469 ) ;
V_55 &= ~ V_292 ;
F_79 ( V_469 , V_55 ) ;
F_123 ( V_697 , V_3 ) ;
++ V_3 -> V_192 . V_698 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_650 -> V_699 &&
! F_364 ( V_3 ) ) {
V_3 -> V_650 -> V_659 = V_700 ;
return 0 ;
}
return 1 ;
}
static int F_365 ( struct V_2 * V_3 )
{
F_142 ( V_3 ) ;
return F_327 ( V_3 ) ;
}
static int F_366 ( struct V_2 * V_3 )
{
F_142 ( V_3 ) ;
F_367 ( V_3 ) ;
return 1 ;
}
static int F_368 ( struct V_2 * V_3 )
{
return F_315 ( V_3 , 0 ) == V_246 ;
}
static int F_369 ( struct V_2 * V_3 )
{
unsigned long V_678 = F_69 ( V_667 ) ;
F_370 ( V_3 , V_678 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_371 ( struct V_2 * V_3 )
{
int V_685 ;
V_685 = F_372 ( V_3 ) ;
F_341 ( V_3 , V_685 ) ;
return 1 ;
}
static int F_373 ( struct V_2 * V_3 )
{
F_142 ( V_3 ) ;
F_374 ( V_3 ) ;
return 1 ;
}
static int F_375 ( struct V_2 * V_3 )
{
T_5 V_701 = F_376 ( V_3 ) ;
T_2 V_64 = F_339 ( V_3 , V_695 ) ;
if ( F_377 ( V_3 , V_64 , V_701 ) == 0 )
F_142 ( V_3 ) ;
return 1 ;
}
static int F_378 ( struct V_2 * V_3 )
{
if ( F_268 ( V_702 ) ) {
unsigned long V_678 = F_69 ( V_667 ) ;
int V_703 , V_269 ;
V_703 = V_678 & V_704 ;
V_269 = V_678 & V_705 ;
if ( ( V_703 == V_706 ) &&
( V_269 == V_707 ) ) {
F_379 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
}
return F_315 ( V_3 , 0 ) == V_246 ;
}
static int F_380 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_678 ;
bool V_239 = false ;
T_2 V_240 = 0 ;
T_3 V_708 ;
int V_709 , type , V_710 ;
V_710 = ( V_58 -> V_657 & V_631 ) ;
type = ( V_58 -> V_657 & V_711 ) ;
V_678 = F_69 ( V_667 ) ;
V_709 = ( T_2 ) V_678 >> 30 ;
if ( V_709 == V_712 && V_710 ) {
switch ( type ) {
case V_626 :
V_3 -> V_95 . V_713 = false ;
F_311 ( V_3 , true ) ;
break;
case V_22 :
case V_621 :
F_381 ( V_3 ) ;
break;
case V_18 :
if ( V_58 -> V_657 &
V_714 ) {
V_239 = true ;
V_240 =
F_71 ( V_715 ) ;
}
case V_249 :
F_382 ( V_3 ) ;
break;
default:
break;
}
}
V_708 = V_678 ;
if ( ! V_710 || ( type != V_18 &&
type != V_22 &&
type != V_626 ) )
F_142 ( V_3 ) ;
if ( F_383 ( V_3 , V_708 , V_709 ,
V_239 , V_240 ) == V_716 ) {
V_3 -> V_650 -> V_659 = V_660 ;
V_3 -> V_650 -> V_661 . V_662 = V_717 ;
V_3 -> V_650 -> V_661 . V_664 = 0 ;
return 0 ;
}
F_76 ( V_358 , F_69 ( V_358 ) & ~ 55 ) ;
return 1 ;
}
static int F_384 ( struct V_2 * V_3 )
{
unsigned long V_678 ;
T_1 V_70 ;
int V_718 ;
V_678 = F_69 ( V_667 ) ;
if ( V_678 & ( 1 << 6 ) ) {
F_54 ( V_74 L_19 ) ;
return - V_334 ;
}
V_718 = ( V_678 >> 7 ) & 0x3 ;
if ( V_718 != 0x3 && V_718 != 0x1 && V_718 != 0 ) {
F_54 ( V_74 L_20 ) ;
F_54 ( V_74 L_21 ,
( long unsigned int ) F_72 ( V_719 ) ,
F_69 ( V_720 ) ) ;
F_54 ( V_74 L_22 ,
( long unsigned int ) V_678 ) ;
V_3 -> V_650 -> V_659 = V_721 ;
V_3 -> V_650 -> V_722 . V_723 = V_724 ;
return 0 ;
}
V_70 = F_72 ( V_719 ) ;
F_323 ( V_70 , V_678 ) ;
return F_326 ( V_3 , V_70 , V_678 & 0x3 , NULL , 0 ) ;
}
static T_5 F_385 ( T_5 V_725 , int V_726 )
{
int V_60 ;
T_5 V_89 = 0 ;
for ( V_60 = 51 ; V_60 > V_394 . V_727 ; V_60 -- )
V_89 |= ( 1ULL << V_60 ) ;
if ( V_726 > 2 )
V_89 |= 0xf8 ;
else if ( V_726 == 2 ) {
if ( V_725 & ( 1ULL << 7 ) )
V_89 |= 0x1ff000 ;
else
V_89 |= 0x78 ;
}
return V_89 ;
}
static void F_386 ( struct V_2 * V_3 , T_5 V_725 ,
int V_726 )
{
F_54 ( V_74 L_23 , V_453 , V_725 , V_726 ) ;
F_387 ( ( V_725 & 0x7 ) == 0x2 ) ;
F_387 ( ( V_725 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_387 ( ( V_725 & 0x7 ) == 0x4 ) ;
if ( ( V_725 & 0x7 ) ) {
T_5 V_728 = V_725 & F_385 ( V_725 , V_726 ) ;
if ( V_728 != 0 ) {
F_54 ( V_74 L_24 ,
V_453 , V_728 ) ;
F_387 ( 1 ) ;
}
if ( V_726 == 1 || ( V_726 == 2 && ( V_725 & ( 1ULL << 7 ) ) ) ) {
T_5 V_729 = ( V_725 & 0x38 ) >> 3 ;
if ( V_729 == 2 || V_729 == 3 ||
V_729 == 7 ) {
F_54 ( V_74 L_25 ,
V_453 , V_729 ) ;
F_387 ( 1 ) ;
}
}
}
}
static int F_388 ( struct V_2 * V_3 )
{
T_5 V_730 [ 4 ] ;
int V_731 , V_60 , V_93 ;
T_1 V_70 ;
V_70 = F_72 ( V_719 ) ;
V_93 = F_389 ( V_3 , V_70 , true ) ;
if ( F_268 ( V_93 == 1 ) )
return F_390 ( V_3 , V_70 , 0 , NULL , 0 ) ==
V_246 ;
if ( F_77 ( ! V_93 ) )
return 1 ;
F_54 ( V_74 L_26 ) ;
F_54 ( V_74 L_27 , V_70 ) ;
V_731 = F_391 ( V_3 , V_70 , V_730 ) ;
for ( V_60 = V_732 ; V_60 > V_732 - V_731 ; -- V_60 )
F_386 ( V_3 , V_730 [ V_60 - 1 ] , V_60 ) ;
V_3 -> V_650 -> V_659 = V_721 ;
V_3 -> V_650 -> V_722 . V_723 = V_733 ;
return 0 ;
}
static int F_392 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_469 ) ;
V_55 &= ~ V_615 ;
F_79 ( V_469 , V_55 ) ;
++ V_3 -> V_192 . V_734 ;
F_123 ( V_697 , V_3 ) ;
return 1 ;
}
static int F_393 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
enum V_655 V_685 = V_246 ;
int V_93 = 1 ;
T_2 V_735 ;
bool V_736 ;
V_735 = F_71 ( V_469 ) ;
V_736 = V_735 & V_292 ;
while ( ! F_263 ( V_3 ) ) {
if ( V_736
&& ( F_247 ( & V_58 -> V_3 ) & V_635 ) )
return F_363 ( & V_58 -> V_3 ) ;
V_685 = F_315 ( V_3 , 0 ) ;
if ( V_685 == V_737 ) {
V_93 = 0 ;
goto V_522;
}
if ( V_685 != V_246 )
return 0 ;
if ( F_394 ( V_194 ) )
goto V_522;
if ( F_395 () )
F_396 () ;
}
V_58 -> V_416 = 0 ;
V_522:
return V_93 ;
}
static int F_397 ( struct V_2 * V_3 )
{
F_142 ( V_3 ) ;
F_398 ( V_3 ) ;
return 1 ;
}
static int F_399 ( struct V_2 * V_3 )
{
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
static struct V_75 * F_400 ( struct V_1 * V_58 )
{
struct V_738 * V_739 ;
F_401 (item, &vmx->nested.vmcs02_pool, list)
if ( V_739 -> V_740 == V_58 -> V_8 . V_741 ) {
F_402 ( & V_739 -> V_742 , & V_58 -> V_8 . V_743 ) ;
return & V_739 -> V_744 ;
}
if ( V_58 -> V_8 . V_745 >= F_403 ( V_746 , 1 ) ) {
V_739 = F_404 ( V_58 -> V_8 . V_743 . V_747 ,
struct V_738 , V_742 ) ;
V_739 -> V_740 = V_58 -> V_8 . V_741 ;
F_402 ( & V_739 -> V_742 , & V_58 -> V_8 . V_743 ) ;
return & V_739 -> V_744 ;
}
V_739 = (struct V_738 * )
F_405 ( sizeof( struct V_738 ) , V_399 ) ;
if ( ! V_739 )
return NULL ;
V_739 -> V_744 . V_72 = F_202 () ;
if ( ! V_739 -> V_744 . V_72 ) {
F_406 ( V_739 ) ;
return NULL ;
}
F_55 ( & V_739 -> V_744 ) ;
V_739 -> V_740 = V_58 -> V_8 . V_741 ;
F_125 ( & ( V_739 -> V_742 ) , & ( V_58 -> V_8 . V_743 ) ) ;
V_58 -> V_8 . V_745 ++ ;
return & V_739 -> V_744 ;
}
static void F_407 ( struct V_1 * V_58 , T_1 V_740 )
{
struct V_738 * V_739 ;
F_401 (item, &vmx->nested.vmcs02_pool, list)
if ( V_739 -> V_740 == V_740 ) {
F_205 ( & V_739 -> V_744 ) ;
F_60 ( & V_739 -> V_742 ) ;
F_406 ( V_739 ) ;
V_58 -> V_8 . V_745 -- ;
return;
}
}
static void F_408 ( struct V_1 * V_58 )
{
struct V_738 * V_739 , * V_369 ;
F_192 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_58 -> V_75 != & V_739 -> V_744 )
F_205 ( & V_739 -> V_744 ) ;
F_60 ( & V_739 -> V_742 ) ;
F_406 ( V_739 ) ;
}
V_58 -> V_8 . V_745 = 0 ;
if ( V_58 -> V_75 != & V_58 -> V_748 )
F_205 ( & V_58 -> V_748 ) ;
}
static int F_409 ( struct V_2 * V_3 )
{
struct V_489 V_508 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_410 ( V_3 , V_367 ) ||
! F_130 ( V_3 , V_475 ) ||
( F_135 ( V_3 ) & V_225 ) ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
F_242 ( V_3 , & V_508 , V_500 ) ;
if ( F_108 ( V_3 ) && ! V_508 . V_496 ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_248 ( V_3 ) ) {
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_188 ( & ( V_58 -> V_8 . V_743 ) ) ;
V_58 -> V_8 . V_745 = 0 ;
V_58 -> V_8 . V_486 = true ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_411 ( struct V_2 * V_3 )
{
struct V_489 V_508 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! V_58 -> V_8 . V_486 ) {
F_316 ( V_3 , V_21 ) ;
return 0 ;
}
F_242 ( V_3 , & V_508 , V_500 ) ;
if ( ( F_135 ( V_3 ) & V_225 ) ||
( F_108 ( V_3 ) && ! V_508 . V_496 ) ) {
F_316 ( V_3 , V_21 ) ;
return 0 ;
}
if ( F_248 ( V_3 ) ) {
F_357 ( V_3 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_412 ( struct V_1 * V_58 )
{
if ( ! V_58 -> V_8 . V_486 )
return;
V_58 -> V_8 . V_486 = false ;
if ( V_58 -> V_8 . V_741 != - 1ull ) {
F_413 ( V_58 -> V_8 . V_749 ) ;
F_9 ( V_58 -> V_8 . V_749 ) ;
V_58 -> V_8 . V_741 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
if ( V_58 -> V_8 . V_539 ) {
F_9 ( V_58 -> V_8 . V_539 ) ;
V_58 -> V_8 . V_539 = 0 ;
}
F_408 ( V_58 ) ;
}
static int F_414 ( struct V_2 * V_3 )
{
if ( ! F_411 ( V_3 ) )
return 1 ;
F_412 ( F_1 ( V_3 ) ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_415 ( struct V_2 * V_3 ,
unsigned long V_678 ,
T_2 V_750 , T_4 * V_93 )
{
int V_751 = V_750 & 3 ;
int V_752 = ( V_750 >> 7 ) & 7 ;
bool V_753 = V_750 & ( 1u << 10 ) ;
int V_754 = ( V_750 >> 15 ) & 7 ;
int V_755 = ( V_750 >> 18 ) & 0xf ;
bool V_756 = ! ( V_750 & ( 1u << 22 ) ) ;
int V_757 = ( V_750 >> 23 ) & 0xf ;
bool V_758 = ! ( V_750 & ( 1u << 27 ) ) ;
if ( V_753 ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
* V_93 = F_244 ( V_3 , V_754 ) ;
if ( V_758 )
* V_93 += F_339 ( V_3 , V_757 ) ;
if ( V_756 )
* V_93 += F_339 ( V_3 , V_755 ) << V_751 ;
* V_93 += V_678 ;
if ( V_752 == 1 )
* V_93 &= 0xffffffff ;
return 0 ;
}
static void F_416 ( struct V_2 * V_3 )
{
F_138 ( V_3 , F_135 ( V_3 )
& ~ ( V_759 | V_760 | V_761 |
V_762 | V_763 | V_764 ) ) ;
}
static void F_417 ( struct V_2 * V_3 )
{
F_138 ( V_3 , ( F_135 ( V_3 )
& ~ ( V_760 | V_761 | V_762 |
V_763 | V_764 ) )
| V_759 ) ;
}
static void F_418 ( struct V_2 * V_3 ,
T_2 V_765 )
{
if ( F_1 ( V_3 ) -> V_8 . V_741 == - 1ull ) {
F_417 ( V_3 ) ;
return;
}
F_138 ( V_3 , ( F_135 ( V_3 )
& ~ ( V_759 | V_760 | V_761 |
V_763 | V_764 ) )
| V_762 ) ;
F_4 ( V_3 ) -> V_765 = V_765 ;
}
static int F_419 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_4 V_66 ;
T_1 V_740 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_766 V_767 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , F_69 ( V_667 ) ,
F_71 ( V_768 ) , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_769 , V_66 , & V_740 ,
sizeof( V_740 ) , & V_767 ) ) {
F_421 ( V_3 , & V_767 ) ;
return 1 ;
}
if ( ! F_422 ( V_740 , V_389 ) ) {
F_418 ( V_3 , V_770 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_740 == V_58 -> V_8 . V_741 ) {
F_413 ( V_58 -> V_8 . V_749 ) ;
F_9 ( V_58 -> V_8 . V_749 ) ;
V_58 -> V_8 . V_741 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_740 ) ;
if ( V_10 == NULL ) {
F_123 ( V_247 , V_3 ) ;
return 1 ;
}
V_7 = F_423 ( V_10 ) ;
V_7 -> V_771 = 0 ;
F_413 ( V_10 ) ;
F_9 ( V_10 ) ;
F_407 ( V_58 , V_740 ) ;
F_142 ( V_3 ) ;
F_416 ( V_3 ) ;
return 1 ;
}
static int F_424 ( struct V_2 * V_3 )
{
return F_425 ( V_3 , true ) ;
}
static int F_426 ( struct V_2 * V_3 )
{
return F_425 ( V_3 , false ) ;
}
static inline int F_427 ( unsigned long V_4 )
{
if ( 0x1 & V_4 )
return V_772 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_428 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_429 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_93 )
{
short V_269 = F_3 ( V_4 ) ;
char * V_98 ;
if ( V_269 < 0 )
return 0 ;
V_98 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_269 ;
switch ( F_427 ( V_4 ) ) {
case V_773 :
* V_93 = * ( ( V_774 * ) V_98 ) ;
return 1 ;
case V_775 :
* V_93 = * ( ( T_3 * ) V_98 ) ;
return 1 ;
case V_772 :
* V_93 = * ( ( T_2 * ) V_98 ) ;
return 1 ;
case V_776 :
* V_93 = * ( ( T_5 * ) V_98 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_430 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_58 -> V_8 . V_741 == - 1ull ) {
F_417 ( V_3 ) ;
F_142 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_431 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_777 ;
unsigned long V_678 = F_69 ( V_667 ) ;
T_2 V_750 = F_71 ( V_768 ) ;
T_4 V_66 = 0 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
V_4 = F_339 ( V_3 , ( ( ( V_750 ) >> 28 ) & 0xf ) ) ;
if ( ! F_429 ( V_3 , V_4 , & V_777 ) ) {
F_418 ( V_3 , V_778 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_750 & ( 1u << 10 ) ) {
F_300 ( V_3 , ( ( ( V_750 ) >> 3 ) & 0xf ) ,
V_777 ) ;
} else {
if ( F_415 ( V_3 , V_678 ,
V_750 , & V_66 ) )
return 1 ;
F_432 ( & V_3 -> V_95 . V_769 , V_66 ,
& V_777 , ( F_108 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_433 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_66 ;
unsigned long V_678 = F_69 ( V_667 ) ;
T_2 V_750 = F_71 ( V_768 ) ;
char * V_98 ;
short V_269 ;
T_5 V_777 = 0 ;
struct V_766 V_767 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
if ( V_750 & ( 1u << 10 ) )
V_777 = F_339 ( V_3 ,
( ( ( V_750 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_415 ( V_3 , V_678 ,
V_750 , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_769 , V_66 ,
& V_777 , ( F_108 ( V_3 ) ? 8 : 4 ) , & V_767 ) ) {
F_421 ( V_3 , & V_767 ) ;
return 1 ;
}
}
V_4 = F_339 ( V_3 , ( ( ( V_750 ) >> 28 ) & 0xf ) ) ;
if ( F_428 ( V_4 ) ) {
F_418 ( V_3 ,
V_779 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_269 = F_3 ( V_4 ) ;
if ( V_269 < 0 ) {
F_418 ( V_3 , V_778 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_98 = ( ( char * ) F_4 ( V_3 ) ) + V_269 ;
switch ( F_427 ( V_4 ) ) {
case V_775 :
* ( T_3 * ) V_98 = V_777 ;
break;
case V_772 :
* ( T_2 * ) V_98 = V_777 ;
break;
case V_776 :
* ( T_5 * ) V_98 = V_777 ;
break;
case V_773 :
* ( V_774 * ) V_98 = V_777 ;
break;
default:
F_418 ( V_3 , V_778 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_434 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_4 V_66 ;
T_1 V_740 ;
struct V_766 V_767 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , F_69 ( V_667 ) ,
F_71 ( V_768 ) , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_769 , V_66 , & V_740 ,
sizeof( V_740 ) , & V_767 ) ) {
F_421 ( V_3 , & V_767 ) ;
return 1 ;
}
if ( ! F_422 ( V_740 , V_389 ) ) {
F_418 ( V_3 , V_780 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_741 != V_740 ) {
struct V_7 * V_781 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_740 ) ;
if ( V_10 == NULL ) {
F_417 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_781 = F_423 ( V_10 ) ;
if ( V_781 -> V_392 != V_317 ) {
F_413 ( V_10 ) ;
F_11 ( V_10 ) ;
F_418 ( V_3 ,
V_782 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_741 != - 1ull ) {
F_413 ( V_58 -> V_8 . V_749 ) ;
F_9 ( V_58 -> V_8 . V_749 ) ;
}
V_58 -> V_8 . V_741 = V_740 ;
V_58 -> V_8 . V_9 = V_781 ;
V_58 -> V_8 . V_749 = V_10 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_435 ( struct V_2 * V_3 )
{
unsigned long V_678 = F_69 ( V_667 ) ;
T_2 V_750 = F_71 ( V_768 ) ;
T_4 V_783 ;
struct V_766 V_767 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , V_678 ,
V_750 , & V_783 ) )
return 1 ;
if ( F_432 ( & V_3 -> V_95 . V_769 , V_783 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_741 ,
sizeof( T_5 ) , & V_767 ) ) {
F_421 ( V_3 , & V_767 ) ;
return 1 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static bool F_436 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_659 )
{
T_2 V_311 = V_3 -> V_95 . V_350 [ V_695 ] ;
T_1 V_784 ;
if ( ! F_44 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_784 = V_7 -> V_254 ;
if ( V_659 == V_785 )
V_784 += 2048 ;
if ( V_311 >= 0xc0000000 ) {
V_311 -= 0xc0000000 ;
V_784 += 1024 ;
}
if ( V_311 < 1024 * 8 ) {
unsigned char V_786 ;
F_437 ( V_3 -> V_12 , V_784 + V_311 / 8 , & V_786 , 1 ) ;
return 1 & ( V_786 >> ( V_311 & 7 ) ) ;
} else
return 1 ;
}
static bool F_438 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_678 = F_69 ( V_667 ) ;
int V_684 = V_678 & 15 ;
int V_348 = ( V_678 >> 8 ) & 15 ;
unsigned long V_683 = F_339 ( V_3 , V_348 ) ;
switch ( ( V_678 >> 4 ) & 3 ) {
case 0 :
switch ( V_684 ) {
case 0 :
if ( V_7 -> V_209 &
( V_683 ^ V_7 -> V_213 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_787 >= 1 &&
V_7 -> V_788 == V_683 ) ||
( V_7 -> V_787 >= 2 &&
V_7 -> V_789 == V_683 ) ||
( V_7 -> V_787 >= 3 &&
V_7 -> V_790 == V_683 ) ||
( V_7 -> V_787 >= 4 &&
V_7 -> V_791 == V_683 ) )
return 0 ;
if ( F_44 ( V_7 , V_296 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_215 &
( V_7 -> V_216 ^ V_683 ) )
return 1 ;
break;
case 8 :
if ( F_44 ( V_7 , V_298 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_209 & V_206 ) &&
( V_7 -> V_213 & V_206 ) )
return 1 ;
break;
case 1 :
switch ( V_684 ) {
case 3 :
if ( V_7 -> V_55 &
V_297 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_55 &
V_299 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_209 & 0xe &
( V_683 ^ V_7 -> V_213 ) )
return 1 ;
if ( ( V_7 -> V_209 & 0x1 ) &&
! ( V_7 -> V_213 & 0x1 ) &&
( V_683 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_439 ( struct V_2 * V_3 )
{
T_2 V_659 = F_71 ( V_792 ) ;
T_2 V_14 = F_71 ( V_793 ) ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_58 -> V_8 . V_629 )
return 0 ;
if ( F_77 ( V_58 -> V_794 ) ) {
F_440 ( L_28 , V_453 ,
F_71 ( V_88 ) ) ;
return 1 ;
}
switch ( V_659 ) {
case V_795 :
if ( ! F_47 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_84 ;
return V_7 -> V_118 &
( 1u << ( V_14 & V_16 ) ) ;
case V_633 :
return 0 ;
case V_796 :
return 1 ;
case V_797 :
case V_798 :
return 1 ;
case V_799 :
return 1 ;
case V_800 :
return 1 ;
case V_801 :
return F_44 ( V_7 , V_293 ) ;
case V_802 :
return 1 ;
case V_803 :
return F_44 ( V_7 , V_294 ) ;
case V_804 :
return F_44 ( V_7 , V_304 ) ;
case V_805 :
return F_44 ( V_7 , V_806 ) ;
case V_807 : case V_808 :
case V_809 : case V_810 :
case V_811 : case V_812 :
case V_813 : case V_814 :
case V_815 : case V_816 :
return 1 ;
case V_817 :
return F_438 ( V_3 , V_7 ) ;
case V_818 :
return F_44 ( V_7 , V_300 ) ;
case V_819 :
return 1 ;
case V_820 :
case V_785 :
return F_436 ( V_3 , V_7 , V_659 ) ;
case V_821 :
return 1 ;
case V_822 :
return F_44 ( V_7 , V_295 ) ;
case V_823 :
return F_44 ( V_7 , V_303 ) ;
case V_824 :
return F_44 ( V_7 , V_825 ) ||
F_45 ( V_7 ,
V_47 ) ;
case V_826 :
return 0 ;
case V_827 :
return 1 ;
case V_828 :
return F_45 ( V_7 ,
V_30 ) ;
case V_724 :
case V_733 :
return 0 ;
case V_829 :
return F_45 ( V_7 , V_53 ) ;
case V_830 :
return 1 ;
default:
return 1 ;
}
}
static void F_441 ( struct V_2 * V_3 , T_5 * V_831 , T_5 * V_832 )
{
* V_831 = F_69 ( V_667 ) ;
* V_832 = F_71 ( V_793 ) ;
}
static int F_442 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_659 = V_58 -> V_659 ;
T_2 V_833 = V_58 -> V_657 ;
if ( V_58 -> V_416 && V_424 )
return F_393 ( V_3 ) ;
if ( V_58 -> V_8 . V_629 )
F_123 ( V_697 , V_3 ) ;
if ( ! F_90 ( V_3 ) && ( V_659 == V_809 ||
V_659 == V_813 ) )
V_58 -> V_8 . V_629 = 1 ;
else
V_58 -> V_8 . V_629 = 0 ;
if ( F_90 ( V_3 ) && F_439 ( V_3 ) ) {
F_147 ( V_3 ) ;
return 1 ;
}
if ( V_659 & V_834 ) {
V_3 -> V_650 -> V_659 = V_835 ;
V_3 -> V_650 -> V_836 . V_837
= V_659 ;
return 0 ;
}
if ( F_77 ( V_58 -> V_794 ) ) {
V_3 -> V_650 -> V_659 = V_835 ;
V_3 -> V_650 -> V_836 . V_837
= F_71 ( V_88 ) ;
return 0 ;
}
if ( ( V_833 & V_631 ) &&
( V_659 != V_795 &&
V_659 != V_724 &&
V_659 != V_799 ) )
F_54 ( V_147 L_29
L_30 ,
V_453 , V_833 , V_659 ) ;
if ( F_77 ( ! F_41 () && V_58 -> V_595 &&
! ( F_90 ( V_3 ) && F_46 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_312 ( V_3 ) ) {
V_58 -> V_595 = 0 ;
} else if ( V_58 -> V_622 > 1000000000LL &&
V_3 -> V_95 . V_838 ) {
F_54 ( V_147 L_31
L_32 ,
V_453 , V_3 -> V_839 ) ;
V_58 -> V_595 = 0 ;
}
}
if ( V_659 < V_840
&& V_841 [ V_659 ] )
return V_841 [ V_659 ] ( V_3 ) ;
else {
V_3 -> V_650 -> V_659 = V_721 ;
V_3 -> V_650 -> V_722 . V_723 = V_659 ;
}
return 0 ;
}
static void V_405 ( struct V_2 * V_3 , int V_842 , int V_843 )
{
if ( V_843 == - 1 || V_842 < V_843 ) {
F_79 ( V_608 , 0 ) ;
return;
}
F_79 ( V_608 , V_843 ) ;
}
static void F_443 ( struct V_1 * V_58 )
{
T_2 V_658 ;
if ( ! ( V_58 -> V_659 == V_826
|| V_58 -> V_659 == V_795 ) )
return;
V_58 -> V_658 = F_71 ( V_793 ) ;
V_658 = V_58 -> V_658 ;
if ( F_16 ( V_658 ) )
F_317 () ;
if ( ( V_658 & V_15 ) == V_626 &&
( V_658 & V_17 ) ) {
F_444 ( & V_58 -> V_3 ) ;
asm("int $2");
F_445 ( & V_58 -> V_3 ) ;
}
}
static void F_446 ( struct V_1 * V_58 )
{
T_2 V_658 ;
bool V_844 ;
T_6 V_845 ;
bool V_846 ;
V_846 = V_58 -> V_657 & V_631 ;
if ( F_41 () ) {
if ( V_58 -> V_624 )
return;
V_658 = F_71 ( V_793 ) ;
V_844 = ( V_658 & V_847 ) != 0 ;
V_845 = V_658 & V_16 ;
if ( ( V_658 & V_17 ) && V_844 &&
V_845 != V_645 && ! V_846 )
F_82 ( V_227 ,
V_627 ) ;
else
V_58 -> V_624 =
! ( F_71 ( V_227 )
& V_627 ) ;
} else if ( F_77 ( V_58 -> V_595 ) )
V_58 -> V_622 +=
F_447 ( F_448 ( F_449 () , V_58 -> V_848 ) ) ;
}
static void F_450 ( struct V_1 * V_58 ,
T_2 V_657 ,
int V_849 ,
int V_850 )
{
T_6 V_845 ;
int type ;
bool V_846 ;
V_846 = V_657 & V_631 ;
V_58 -> V_3 . V_95 . V_713 = false ;
F_382 ( & V_58 -> V_3 ) ;
F_381 ( & V_58 -> V_3 ) ;
if ( ! V_846 )
return;
F_123 ( V_697 , & V_58 -> V_3 ) ;
V_845 = V_657 & V_851 ;
type = V_657 & V_711 ;
switch ( type ) {
case V_626 :
V_58 -> V_3 . V_95 . V_713 = true ;
F_311 ( & V_58 -> V_3 , false ) ;
break;
case V_249 :
V_58 -> V_3 . V_95 . V_245 =
F_71 ( V_849 ) ;
case V_18 :
if ( V_657 & V_714 ) {
T_2 V_685 = F_71 ( V_850 ) ;
F_170 ( & V_58 -> V_3 , V_845 , V_685 ) ;
} else
F_316 ( & V_58 -> V_3 , V_845 ) ;
break;
case V_621 :
V_58 -> V_3 . V_95 . V_245 =
F_71 ( V_849 ) ;
case V_22 :
F_451 ( & V_58 -> V_3 , V_845 ,
type == V_621 ) ;
break;
default:
break;
}
}
static void F_452 ( struct V_1 * V_58 )
{
if ( F_90 ( & V_58 -> V_3 ) )
return;
F_450 ( V_58 , V_58 -> V_657 ,
V_234 ,
V_715 ) ;
}
static void F_453 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) )
return;
F_450 ( F_1 ( V_3 ) ,
F_71 ( V_250 ) ,
V_248 ,
V_242 ) ;
F_79 ( V_250 , 0 ) ;
}
static void F_454 ( struct V_1 * V_58 )
{
int V_60 , V_852 ;
struct V_853 * V_854 ;
V_854 = F_455 ( & V_852 ) ;
if ( ! V_854 )
return;
for ( V_60 = 0 ; V_60 < V_852 ; V_60 ++ )
if ( V_854 [ V_60 ] . V_135 == V_854 [ V_60 ] . V_134 )
F_92 ( V_58 , V_854 [ V_60 ] . V_59 ) ;
else
F_94 ( V_58 , V_854 [ V_60 ] . V_59 , V_854 [ V_60 ] . V_134 ,
V_854 [ V_60 ] . V_135 ) ;
}
static void T_16 F_456 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) && ! V_58 -> V_8 . V_629 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_630 &
V_631 ) {
F_79 ( V_250 ,
V_7 -> V_630 ) ;
F_79 ( V_248 ,
V_7 -> V_855 ) ;
if ( V_7 -> V_630 &
V_714 )
F_79 ( V_242 ,
V_7 -> V_856 ) ;
}
}
if ( F_77 ( ! F_41 () && V_58 -> V_595 ) )
V_58 -> V_848 = F_449 () ;
if ( V_58 -> V_416 && V_424 )
return;
if ( F_136 ( V_349 , ( unsigned long * ) & V_3 -> V_95 . V_461 ) )
F_76 ( V_351 , V_3 -> V_95 . V_350 [ V_349 ] ) ;
if ( F_136 ( V_352 , ( unsigned long * ) & V_3 -> V_95 . V_461 ) )
F_76 ( V_353 , V_3 -> V_95 . V_350 [ V_352 ] ) ;
if ( V_3 -> V_111 & V_641 )
F_141 ( V_3 , 0 ) ;
F_454 ( V_58 ) ;
V_58 -> V_857 = V_58 -> V_75 -> V_77 ;
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
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_352 ) | ( 1 << V_349 )
| ( 1 << V_220 )
| ( 1 << V_223 )
| ( 1 << V_354 )
| ( 1 << V_97 )
| ( 1 << V_458 ) ) ;
V_3 -> V_95 . V_461 = 0 ;
V_58 -> V_657 = F_71 ( V_858 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_630 = V_58 -> V_657 ;
if ( V_58 -> V_657 & V_631 ) {
V_7 -> V_856 =
F_71 ( V_715 ) ;
V_7 -> V_855 =
F_71 ( V_234 ) ;
}
}
asm("mov %0, %%ds; mov %0, %%es" : : "r"(__USER_DS));
V_58 -> V_75 -> V_77 = 1 ;
V_58 -> V_659 = F_71 ( V_792 ) ;
F_457 ( V_58 -> V_659 , V_3 , V_859 ) ;
F_443 ( V_58 ) ;
F_446 ( V_58 ) ;
F_452 ( V_58 ) ;
}
static void F_458 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
F_279 ( V_58 ) ;
F_412 ( V_58 ) ;
F_205 ( V_58 -> V_75 ) ;
F_406 ( V_58 -> V_63 ) ;
F_459 ( V_3 ) ;
F_460 ( V_860 , V_58 ) ;
}
static struct V_2 * F_461 ( struct V_12 * V_12 , unsigned int V_861 )
{
int V_685 ;
struct V_1 * V_58 = F_462 ( V_860 , V_399 ) ;
int V_76 ;
if ( ! V_58 )
return F_463 ( - V_400 ) ;
F_275 ( V_58 ) ;
V_685 = F_464 ( & V_58 -> V_3 , V_12 , V_861 ) ;
if ( V_685 )
goto V_862;
V_58 -> V_63 = F_405 ( V_389 , V_399 ) ;
V_685 = - V_400 ;
if ( ! V_58 -> V_63 ) {
goto V_863;
}
V_58 -> V_75 = & V_58 -> V_748 ;
V_58 -> V_75 -> V_72 = F_202 () ;
if ( ! V_58 -> V_75 -> V_72 )
goto V_864;
if ( ! V_196 )
F_122 ( F_53 ( F_59 ( V_195 , F_58 () ) ) ) ;
F_55 ( V_58 -> V_75 ) ;
if ( ! V_196 )
F_128 () ;
V_76 = F_465 () ;
F_121 ( & V_58 -> V_3 , V_76 ) ;
V_58 -> V_3 . V_76 = V_76 ;
V_685 = F_291 ( V_58 ) ;
F_127 ( & V_58 -> V_3 ) ;
F_466 () ;
if ( V_685 )
goto F_203;
if ( F_38 ( V_12 ) )
V_685 = F_270 ( V_12 ) ;
if ( V_685 )
goto F_203;
if ( V_84 ) {
if ( ! V_12 -> V_95 . V_482 )
V_12 -> V_95 . V_482 =
V_865 ;
V_685 = - V_400 ;
if ( F_274 ( V_12 ) != 0 )
goto F_203;
if ( ! F_267 ( V_12 ) )
goto F_203;
}
V_58 -> V_8 . V_741 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
return & V_58 -> V_3 ;
F_203:
F_203 ( V_58 -> V_75 -> V_72 ) ;
V_864:
F_406 ( V_58 -> V_63 ) ;
V_863:
F_459 ( & V_58 -> V_3 ) ;
V_862:
F_279 ( V_58 ) ;
F_460 ( V_860 , V_58 ) ;
return F_463 ( V_685 ) ;
}
static void T_11 F_467 ( void * V_866 )
{
struct V_24 V_377 ;
* ( int * ) V_866 = 0 ;
if ( F_196 ( & V_377 ) < 0 )
* ( int * ) V_866 = - V_376 ;
if ( memcmp ( & V_24 , & V_377 , sizeof( struct V_24 ) ) != 0 ) {
F_54 ( V_74 L_33 ,
F_468 () ) ;
* ( int * ) V_866 = - V_376 ;
}
}
static int F_469 ( void )
{
return V_477 + 1 ;
}
static T_5 F_470 ( struct V_2 * V_3 , T_13 V_867 , bool V_868 )
{
T_5 V_93 ;
if ( V_868 )
V_93 = V_869 << V_870 ;
else if ( V_3 -> V_12 -> V_95 . V_871 &&
! ( V_3 -> V_12 -> V_95 . V_872 & V_873 ) )
V_93 = F_471 ( V_3 , V_867 ) <<
V_870 ;
else
V_93 = ( V_874 << V_870 )
| V_875 ;
return V_93 ;
}
static int F_472 ( void )
{
if ( V_84 && ! F_28 () )
return V_876 ;
else
return V_877 ;
}
static void F_473 ( struct V_2 * V_3 )
{
struct V_273 * V_274 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_570 ;
V_58 -> V_259 = false ;
if ( F_151 () ) {
V_570 = F_71 ( V_578 ) ;
if ( V_570 & V_50 ) {
V_274 = F_163 ( V_3 , 0x80000001 , 0 ) ;
if ( V_274 && ( V_274 -> V_878 & V_54 ( V_879 ) ) )
V_58 -> V_259 = true ;
else {
V_570 &= ~ V_50 ;
F_79 ( V_578 ,
V_570 ) ;
}
}
}
}
static void F_474 ( T_2 V_880 , struct V_273 * V_120 )
{
if ( V_880 == 1 && V_8 )
V_120 -> V_275 |= V_54 ( V_276 ) ;
}
static void F_475 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_570 ;
F_78 ( V_881 , V_7 -> V_882 ) ;
F_78 ( V_433 , V_7 -> V_883 ) ;
F_78 ( V_431 , V_7 -> V_884 ) ;
F_78 ( V_885 , V_7 -> V_886 ) ;
F_78 ( V_887 , V_7 -> V_888 ) ;
F_78 ( V_889 , V_7 -> V_890 ) ;
F_78 ( V_600 , V_7 -> V_891 ) ;
F_78 ( V_417 , V_7 -> V_892 ) ;
F_79 ( V_893 , V_7 -> V_894 ) ;
F_79 ( V_448 , V_7 -> V_895 ) ;
F_79 ( V_447 , V_7 -> V_896 ) ;
F_79 ( V_897 , V_7 -> V_898 ) ;
F_79 ( V_899 , V_7 -> V_900 ) ;
F_79 ( V_901 , V_7 -> V_902 ) ;
F_79 ( V_602 , V_7 -> V_903 ) ;
F_79 ( V_419 , V_7 -> V_904 ) ;
F_79 ( V_506 , V_7 -> V_905 ) ;
F_79 ( V_504 , V_7 -> V_906 ) ;
F_79 ( V_907 , V_7 -> V_908 ) ;
F_79 ( V_434 , V_7 -> V_909 ) ;
F_79 ( V_432 , V_7 -> V_910 ) ;
F_79 ( V_911 , V_7 -> V_912 ) ;
F_79 ( V_913 , V_7 -> V_914 ) ;
F_79 ( V_915 , V_7 -> V_916 ) ;
F_79 ( V_603 , V_7 -> V_917 ) ;
F_79 ( V_420 , V_7 -> V_918 ) ;
F_76 ( V_919 , V_7 -> V_920 ) ;
F_76 ( V_449 , V_7 -> V_921 ) ;
F_76 ( V_446 , V_7 -> V_922 ) ;
F_76 ( V_923 , V_7 -> V_924 ) ;
F_76 ( V_335 , V_7 -> V_925 ) ;
F_76 ( V_336 , V_7 -> V_926 ) ;
F_76 ( V_601 , V_7 -> V_927 ) ;
F_76 ( V_418 , V_7 -> V_928 ) ;
F_76 ( V_507 , V_7 -> V_929 ) ;
F_76 ( V_505 , V_7 -> V_930 ) ;
F_80 ( V_605 , V_7 -> V_931 ) ;
F_79 ( V_250 ,
V_7 -> V_932 ) ;
F_79 ( V_242 ,
V_7 -> V_933 ) ;
F_79 ( V_248 ,
V_7 -> V_934 ) ;
F_79 ( V_227 ,
V_7 -> V_935 ) ;
F_79 ( V_236 , V_7 -> V_936 ) ;
F_79 ( V_339 , V_7 -> V_937 ) ;
F_76 ( V_358 , V_7 -> V_938 ) ;
F_76 ( V_221 , V_7 -> V_939 ) ;
F_76 ( V_604 ,
V_7 -> V_940 ) ;
F_76 ( V_342 , V_7 -> V_941 ) ;
F_76 ( V_341 , V_7 -> V_942 ) ;
F_80 ( V_576 , - 1ull ) ;
F_79 ( V_577 ,
( V_24 . V_51 |
V_7 -> V_57 ) ) ;
F_79 ( V_582 ,
V_84 ? V_7 -> V_943 : 0 ) ;
F_79 ( V_583 ,
V_84 ? V_7 -> V_944 : 0 ) ;
if ( F_21 () ) {
T_2 V_570 = F_288 ( V_58 ) ;
if ( ! V_58 -> V_259 )
V_570 &= ~ V_50 ;
V_570 &= ~ V_30 ;
if ( F_44 ( V_7 ,
V_28 ) )
V_570 |= V_7 -> V_56 ;
if ( V_570 & V_30 ) {
if ( V_58 -> V_8 . V_539 )
F_9 ( V_58 -> V_8 . V_539 ) ;
V_58 -> V_8 . V_539 =
F_5 ( V_3 , V_7 -> V_945 ) ;
if ( ! V_58 -> V_8 . V_539 )
V_570 &=
~ V_30 ;
else
F_80 ( V_609 ,
F_301 ( V_58 -> V_8 . V_539 ) ) ;
}
F_79 ( V_578 , V_570 ) ;
}
F_282 () ;
V_58 -> V_946 = 0 ;
V_570 = F_287 ( V_58 ) ;
V_570 &= ~ V_292 ;
V_570 &= ~ V_615 ;
V_570 &= ~ V_27 ;
V_570 |= V_7 -> V_55 ;
V_570 &= ~ V_26 ;
V_570 &= ~ V_302 ;
V_570 |= V_301 ;
F_79 ( V_469 , V_570 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_208 &= ~ V_7 -> V_209 ;
F_76 ( V_210 , ~ V_3 -> V_95 . V_208 ) ;
F_79 ( V_122 ,
V_7 -> V_947 | V_24 . V_393 ) ;
F_79 ( V_121 , V_7 -> V_948 |
( V_24 . V_344 & ~ V_288 ) ) ;
if ( V_7 -> V_948 & V_287 )
F_80 ( V_345 , V_7 -> V_949 ) ;
else if ( V_24 . V_344 & V_287 )
F_80 ( V_345 , V_58 -> V_3 . V_95 . V_346 ) ;
F_286 ( V_58 ) ;
if ( V_7 -> V_55 & V_270 )
F_80 ( V_266 ,
V_58 -> V_8 . V_267 + V_7 -> V_265 ) ;
else
F_80 ( V_266 , V_58 -> V_8 . V_267 ) ;
if ( V_402 ) {
F_78 ( V_610 , V_58 -> V_42 ) ;
F_228 ( V_3 ) ;
}
if ( V_7 -> V_948 & V_127 )
V_3 -> V_95 . V_158 = V_7 -> V_950 ;
if ( V_7 -> V_948 & V_288 )
V_3 -> V_95 . V_158 |= ( V_161 | V_162 ) ;
else
V_3 -> V_95 . V_158 &= ~ ( V_161 | V_162 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 ) ;
F_239 ( V_3 , V_7 -> V_212 ) ;
F_76 ( V_217 , F_131 ( V_7 ) ) ;
F_237 ( V_3 , V_7 -> V_214 ) ;
F_76 ( V_423 , F_132 ( V_7 ) ) ;
F_342 ( V_3 , V_7 -> V_480 ) ;
F_223 ( V_3 ) ;
F_300 ( V_3 , V_349 , V_7 -> V_951 ) ;
F_300 ( V_3 , V_352 , V_7 -> V_952 ) ;
}
static int F_425 ( struct V_2 * V_3 , bool V_953 )
{
struct V_7 * V_7 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_75 * V_744 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
F_142 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_771 == V_953 ) {
F_418 ( V_3 ,
V_953 ? V_954
: V_955 ) ;
return 1 ;
}
if ( ( V_7 -> V_55 & V_26 ) &&
! F_422 ( V_7 -> V_254 , V_389 ) ) {
F_418 ( V_3 , V_956 ) ;
return 1 ;
}
if ( F_45 ( V_7 , V_30 ) &&
! F_422 ( V_7 -> V_945 , V_389 ) ) {
F_418 ( V_3 , V_956 ) ;
return 1 ;
}
if ( V_7 -> V_957 > 0 ||
V_7 -> V_958 > 0 ||
V_7 -> V_959 > 0 ) {
F_476 ( L_34 ,
V_453 ) ;
F_418 ( V_3 , V_956 ) ;
return 1 ;
}
if ( ! F_167 ( V_7 -> V_55 ,
V_290 , V_291 ) ||
! F_167 ( V_7 -> V_56 ,
V_306 , V_307 ) ||
! F_167 ( V_7 -> V_57 ,
V_277 , V_278 ) ||
! F_167 ( V_7 -> V_947 ,
V_281 , V_282 ) ||
! F_167 ( V_7 -> V_948 ,
V_285 , V_286 ) )
{
F_418 ( V_3 , V_956 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_960 & F_171 ) != F_171 ) ||
( ( V_7 -> V_961 & F_172 ) != F_172 ) ) {
F_418 ( V_3 ,
V_962 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_212 & F_171 ) != F_171 ) ||
( ( V_7 -> V_214 & F_172 ) != F_172 ) ) {
F_477 ( V_3 , V_7 ,
V_821 , V_963 ) ;
return 1 ;
}
if ( V_7 -> V_964 != - 1ull ) {
F_477 ( V_3 , V_7 ,
V_821 , V_965 ) ;
return 1 ;
}
V_744 = F_400 ( V_58 ) ;
if ( ! V_744 )
return - V_400 ;
F_478 ( V_3 ) ;
V_58 -> V_8 . V_267 = F_72 ( V_266 ) ;
V_76 = F_465 () ;
V_58 -> V_75 = V_744 ;
F_127 ( V_3 ) ;
F_121 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_466 () ;
V_7 -> V_771 = 1 ;
F_475 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_479 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_205 ) & V_3 -> V_95 . V_208 ) |
( V_7 -> V_212 & V_7 -> V_209 ) |
( F_69 ( V_217 ) & ~ ( V_7 -> V_209 |
V_3 -> V_95 . V_208 ) ) ;
}
static inline unsigned long
F_480 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_421 ) & V_3 -> V_95 . V_459 ) |
( V_7 -> V_214 & V_7 -> V_215 ) |
( F_69 ( V_423 ) & ~ ( V_7 -> V_215 |
V_3 -> V_95 . V_459 ) ) ;
}
void F_481 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_212 = F_479 ( V_3 , V_7 ) ;
V_7 -> V_214 = F_480 ( V_3 , V_7 ) ;
F_350 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_938 ) ;
V_7 -> V_951 = F_339 ( V_3 , V_349 ) ;
V_7 -> V_952 = F_339 ( V_3 , V_352 ) ;
V_7 -> V_939 = F_69 ( V_221 ) ;
V_7 -> V_882 = F_70 ( V_881 ) ;
V_7 -> V_883 = F_70 ( V_433 ) ;
V_7 -> V_884 = F_70 ( V_431 ) ;
V_7 -> V_886 = F_70 ( V_885 ) ;
V_7 -> V_888 = F_70 ( V_887 ) ;
V_7 -> V_890 = F_70 ( V_889 ) ;
V_7 -> V_891 = F_70 ( V_600 ) ;
V_7 -> V_892 = F_70 ( V_417 ) ;
V_7 -> V_894 = F_71 ( V_893 ) ;
V_7 -> V_895 = F_71 ( V_448 ) ;
V_7 -> V_896 = F_71 ( V_447 ) ;
V_7 -> V_898 = F_71 ( V_897 ) ;
V_7 -> V_900 = F_71 ( V_899 ) ;
V_7 -> V_902 = F_71 ( V_901 ) ;
V_7 -> V_903 = F_71 ( V_602 ) ;
V_7 -> V_904 = F_71 ( V_419 ) ;
V_7 -> V_905 = F_71 ( V_506 ) ;
V_7 -> V_906 = F_71 ( V_504 ) ;
V_7 -> V_908 = F_71 ( V_907 ) ;
V_7 -> V_909 = F_71 ( V_434 ) ;
V_7 -> V_910 = F_71 ( V_432 ) ;
V_7 -> V_912 = F_71 ( V_911 ) ;
V_7 -> V_914 = F_71 ( V_913 ) ;
V_7 -> V_916 = F_71 ( V_915 ) ;
V_7 -> V_917 = F_71 ( V_603 ) ;
V_7 -> V_918 = F_71 ( V_420 ) ;
V_7 -> V_920 = F_69 ( V_919 ) ;
V_7 -> V_921 = F_69 ( V_449 ) ;
V_7 -> V_922 = F_69 ( V_446 ) ;
V_7 -> V_924 = F_69 ( V_923 ) ;
V_7 -> V_925 = F_69 ( V_335 ) ;
V_7 -> V_926 = F_69 ( V_336 ) ;
V_7 -> V_927 = F_69 ( V_601 ) ;
V_7 -> V_928 = F_69 ( V_418 ) ;
V_7 -> V_929 = F_69 ( V_507 ) ;
V_7 -> V_930 = F_69 ( V_505 ) ;
V_7 -> V_936 = F_71 ( V_236 ) ;
V_7 -> V_935 =
F_71 ( V_227 ) ;
V_7 -> V_940 =
F_69 ( V_604 ) ;
V_7 -> V_931 = F_72 ( V_605 ) ;
if ( V_7 -> V_948 & V_387 )
V_7 -> V_949 = F_72 ( V_345 ) ;
V_7 -> V_937 = F_71 ( V_339 ) ;
V_7 -> V_941 = F_69 ( V_342 ) ;
V_7 -> V_942 = F_69 ( V_341 ) ;
V_7 -> V_632 = F_71 ( V_792 ) ;
V_7 -> V_678 = F_69 ( V_667 ) ;
V_7 -> V_634 = F_71 ( V_793 ) ;
V_7 -> V_966 = F_71 ( V_666 ) ;
V_7 -> V_630 =
F_71 ( V_858 ) ;
V_7 -> V_856 =
F_71 ( V_715 ) ;
V_7 -> V_855 = F_71 ( V_234 ) ;
V_7 -> V_750 = F_71 ( V_768 ) ;
if ( ! ( V_7 -> V_632 & V_834 ) )
V_7 -> V_932 &= ~ V_17 ;
}
void F_482 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_947 & V_128 )
V_3 -> V_95 . V_158 = V_7 -> V_967 ;
if ( V_7 -> V_947 & V_283 )
V_3 -> V_95 . V_158 |= ( V_161 | V_162 ) ;
else
V_3 -> V_95 . V_158 &= ~ ( V_161 | V_162 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 ) ;
F_300 ( V_3 , V_349 , V_7 -> V_946 ) ;
F_300 ( V_3 , V_352 , V_7 -> V_968 ) ;
F_334 ( V_3 , V_7 -> V_960 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_208 = ( V_3 -> V_117 ? V_206 : 0 ) ;
F_76 ( V_210 , ~ V_3 -> V_95 . V_208 ) ;
V_3 -> V_95 . V_459 = ~ F_69 ( V_569 ) ;
F_336 ( V_3 , V_7 -> V_961 ) ;
F_342 ( V_3 , V_7 -> V_969 ) ;
F_223 ( V_3 ) ;
if ( V_402 ) {
F_228 ( V_3 ) ;
}
F_79 ( V_339 , V_7 -> V_970 ) ;
F_76 ( V_342 , V_7 -> V_971 ) ;
F_76 ( V_341 , V_7 -> V_972 ) ;
F_76 ( V_505 , V_7 -> V_973 ) ;
F_76 ( V_507 , V_7 -> V_974 ) ;
F_76 ( V_418 , V_7 -> V_975 ) ;
F_76 ( V_336 , V_7 -> V_976 ) ;
F_76 ( V_335 , V_7 -> V_977 ) ;
F_78 ( V_881 , V_7 -> V_978 ) ;
F_78 ( V_433 , V_7 -> V_979 ) ;
F_78 ( V_431 , V_7 -> V_980 ) ;
F_78 ( V_885 , V_7 -> V_981 ) ;
F_78 ( V_887 , V_7 -> V_982 ) ;
F_78 ( V_889 , V_7 -> V_983 ) ;
F_78 ( V_417 , V_7 -> V_984 ) ;
if ( V_7 -> V_947 & V_388 )
F_80 ( V_345 , V_7 -> V_985 ) ;
if ( V_7 -> V_947 & V_132 )
F_80 ( V_144 ,
V_7 -> V_986 ) ;
}
static void F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_483 ( V_3 ) ;
F_481 ( V_3 , V_7 ) ;
V_76 = F_465 () ;
V_58 -> V_75 = & V_58 -> V_748 ;
F_127 ( V_3 ) ;
F_121 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_466 () ;
if ( V_746 == 0 )
F_407 ( V_58 , V_58 -> V_8 . V_741 ) ;
F_482 ( V_3 , V_7 ) ;
F_80 ( V_266 , V_58 -> V_8 . V_267 ) ;
V_58 -> V_946 = 0 ;
if ( V_58 -> V_8 . V_539 ) {
F_9 ( V_58 -> V_8 . V_539 ) ;
V_58 -> V_8 . V_539 = 0 ;
}
if ( F_77 ( V_58 -> V_794 ) ) {
V_58 -> V_794 = 0 ;
F_418 ( V_3 , F_71 ( V_88 ) ) ;
} else
F_416 ( V_3 ) ;
}
static void F_477 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_709 , unsigned long V_987 )
{
F_482 ( V_3 , V_7 ) ;
V_7 -> V_632 = V_709 | V_834 ;
V_7 -> V_678 = V_987 ;
F_416 ( V_3 ) ;
}
static int F_484 ( struct V_2 * V_3 ,
struct V_988 * V_989 ,
enum V_990 V_991 )
{
return V_992 ;
}
static int T_11 F_485 ( void )
{
int V_520 , V_60 ;
F_486 ( V_125 , & V_163 ) ;
for ( V_60 = 0 ; V_60 < V_591 ; ++ V_60 )
F_487 ( V_60 , V_62 [ V_60 ] ) ;
V_573 = ( unsigned long * ) F_488 ( V_399 ) ;
if ( ! V_573 )
return - V_400 ;
V_575 = ( unsigned long * ) F_488 ( V_399 ) ;
if ( ! V_575 ) {
V_520 = - V_400 ;
goto V_522;
}
V_262 = ( unsigned long * ) F_488 ( V_399 ) ;
if ( ! V_262 ) {
V_520 = - V_400 ;
goto V_993;
}
V_261 = ( unsigned long * ) F_488 ( V_399 ) ;
if ( ! V_261 ) {
V_520 = - V_400 ;
goto V_994;
}
memset ( V_573 , 0xff , V_389 ) ;
F_489 ( 0x80 , V_573 ) ;
memset ( V_575 , 0xff , V_389 ) ;
memset ( V_262 , 0xff , V_389 ) ;
memset ( V_261 , 0xff , V_389 ) ;
F_490 ( 0 , V_545 ) ;
V_520 = F_491 ( & V_995 , sizeof( struct V_1 ) ,
F_492 ( struct V_1 ) , V_996 ) ;
if ( V_520 )
goto V_997;
F_281 ( V_185 , false ) ;
F_281 ( V_187 , false ) ;
F_281 ( V_188 , true ) ;
F_281 ( V_338 , false ) ;
F_281 ( V_202 , false ) ;
F_281 ( V_340 , false ) ;
if ( V_84 ) {
F_493 ( 0ull , 0ull , 0ull , 0ull ,
V_998 ) ;
F_289 () ;
F_494 () ;
} else
F_495 () ;
return 0 ;
V_997:
F_496 ( ( unsigned long ) V_261 ) ;
V_994:
F_496 ( ( unsigned long ) V_262 ) ;
V_993:
F_496 ( ( unsigned long ) V_575 ) ;
V_522:
F_496 ( ( unsigned long ) V_573 ) ;
return V_520 ;
}
static void T_12 F_497 ( void )
{
F_496 ( ( unsigned long ) V_262 ) ;
F_496 ( ( unsigned long ) V_261 ) ;
F_496 ( ( unsigned long ) V_575 ) ;
F_496 ( ( unsigned long ) V_573 ) ;
F_498 () ;
}
