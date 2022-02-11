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
if ( F_115 () )
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
T_5 V_73 = F_53 ( F_59 ( V_194 , V_76 ) ) ;
if ( ! V_195 )
F_122 ( V_73 ) ;
else if ( V_58 -> V_75 -> V_76 != V_76 )
F_61 ( V_58 -> V_75 ) ;
if ( F_59 ( V_79 , V_76 ) != V_58 -> V_75 -> V_72 ) {
F_59 ( V_79 , V_76 ) = V_58 -> V_75 -> V_72 ;
F_56 ( V_58 -> V_75 -> V_72 ) ;
}
if ( V_58 -> V_75 -> V_76 != V_76 ) {
struct V_148 * V_149 = & F_97 ( V_150 ) ;
unsigned long V_196 ;
F_123 ( V_197 , V_3 ) ;
F_124 () ;
F_125 ( & V_58 -> V_75 -> V_80 ,
& F_59 ( V_198 , V_76 ) ) ;
F_126 () ;
F_76 ( V_199 , F_103 () ) ;
F_76 ( V_200 , V_149 -> V_153 ) ;
F_107 ( V_201 , V_196 ) ;
F_76 ( V_202 , V_196 ) ;
V_58 -> V_75 -> V_76 = V_76 ;
}
}
static void F_127 ( struct V_2 * V_3 )
{
F_111 ( F_1 ( V_3 ) ) ;
if ( ! V_195 ) {
F_57 ( F_1 ( V_3 ) -> V_75 ) ;
V_3 -> V_76 = - 1 ;
F_128 () ;
}
}
static void F_129 ( struct V_2 * V_3 )
{
T_9 V_203 ;
if ( V_3 -> V_117 )
return;
V_3 -> V_117 = 1 ;
V_203 = F_69 ( V_204 ) ;
V_203 &= ~ ( V_205 | V_206 ) ;
V_203 |= F_130 ( V_3 , V_205 | V_206 ) ;
F_76 ( V_204 , V_203 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_207 = V_205 ;
if ( F_90 ( V_3 ) )
V_3 -> V_95 . V_207 &=
~ F_4 ( V_3 ) -> V_208 ;
F_76 ( V_209 , ~ V_3 -> V_95 . V_207 ) ;
}
static inline unsigned long F_131 ( struct V_7 * V_210 )
{
return ( V_210 -> V_211 & ~ V_210 -> V_208 ) |
( V_210 -> V_212 & V_210 -> V_208 ) ;
}
static inline unsigned long F_132 ( struct V_7 * V_210 )
{
return ( V_210 -> V_213 & ~ V_210 -> V_214 ) |
( V_210 -> V_215 & V_210 -> V_214 ) ;
}
static void F_133 ( struct V_2 * V_3 )
{
F_134 ( V_3 ) ;
F_82 ( V_204 , V_205 | V_206 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_207 = 0 ;
F_76 ( V_209 , ~ V_3 -> V_95 . V_207 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_211 = ( V_7 -> V_211 & ~ V_205 ) |
( V_3 -> V_95 . V_203 & V_205 ) ;
F_76 ( V_216 , F_131 ( V_7 ) ) ;
} else
F_76 ( V_216 , V_3 -> V_95 . V_203 ) ;
}
static unsigned long F_135 ( struct V_2 * V_3 )
{
unsigned long V_217 , V_218 ;
if ( ! F_136 ( V_219 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_137 ( V_219 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
V_217 = F_69 ( V_220 ) ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
V_217 &= V_221 ;
V_218 = F_1 ( V_3 ) -> V_115 . V_218 ;
V_217 |= V_218 & ~ V_221 ;
}
F_1 ( V_3 ) -> V_217 = V_217 ;
}
return F_1 ( V_3 ) -> V_217 ;
}
static void F_138 ( struct V_2 * V_3 , unsigned long V_217 )
{
F_137 ( V_219 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_139 ( V_222 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_217 = V_217 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
F_1 ( V_3 ) -> V_115 . V_218 = V_217 ;
V_217 |= V_223 | V_224 ;
}
F_76 ( V_220 , V_217 ) ;
}
static T_2 F_140 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_225 = F_71 ( V_226 ) ;
int V_93 = 0 ;
if ( V_225 & V_227 )
V_93 |= V_228 ;
if ( V_225 & V_229 )
V_93 |= V_230 ;
return V_93 & V_89 ;
}
static void F_141 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_231 = F_71 ( V_226 ) ;
T_2 V_225 = V_231 ;
V_225 &= ~ ( V_227 | V_229 ) ;
if ( V_89 & V_230 )
V_225 |= V_229 ;
else if ( V_89 & V_228 )
V_225 |= V_227 ;
if ( ( V_225 != V_231 ) )
F_79 ( V_226 , V_225 ) ;
}
static void F_142 ( struct V_2 * V_3 )
{
unsigned long V_232 ;
V_232 = F_143 ( V_3 ) ;
V_232 += F_71 ( V_233 ) ;
F_144 ( V_3 , V_232 ) ;
F_141 ( V_3 , 0 ) ;
}
static int F_145 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( ! ( V_7 -> V_118 & ( 1u << V_19 ) ) )
return 0 ;
F_146 ( V_3 ) ;
return 1 ;
}
static void F_147 ( struct V_2 * V_3 , unsigned V_133 ,
bool V_234 , T_2 V_235 ,
bool V_236 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_14 = V_133 | V_17 ;
if ( V_133 == V_19 && F_90 ( V_3 ) &&
F_145 ( V_3 ) )
return;
if ( V_234 ) {
F_79 ( V_237 , V_235 ) ;
V_14 |= V_238 ;
}
if ( V_58 -> V_115 . V_116 ) {
int V_239 = 0 ;
if ( F_148 ( V_133 ) )
V_239 = V_3 -> V_95 . V_240 ;
if ( F_149 ( V_3 , V_133 , V_239 ) != V_241 )
F_123 ( V_242 , V_3 ) ;
return;
}
if ( F_148 ( V_133 ) ) {
F_79 ( V_243 ,
V_58 -> V_3 . V_95 . V_240 ) ;
V_14 |= V_244 ;
} else
V_14 |= V_18 ;
F_79 ( V_245 , V_14 ) ;
}
static bool F_150 ( void )
{
return F_40 () ;
}
static void F_151 ( struct V_1 * V_58 , int V_246 , int V_247 )
{
struct V_71 V_248 ;
V_248 = V_58 -> V_63 [ V_247 ] ;
V_58 -> V_63 [ V_247 ] = V_58 -> V_63 [ V_246 ] ;
V_58 -> V_63 [ V_246 ] = V_248 ;
}
static void F_152 ( struct V_1 * V_58 )
{
int V_191 , V_64 ;
unsigned long * V_249 ;
V_191 = 0 ;
#ifdef F_73
if ( F_108 ( & V_58 -> V_3 ) ) {
V_64 = F_48 ( V_58 , V_250 ) ;
if ( V_64 >= 0 )
F_151 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_251 ) ;
if ( V_64 >= 0 )
F_151 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_252 ) ;
if ( V_64 >= 0 )
F_151 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_253 ) ;
if ( V_64 >= 0 && V_58 -> V_254 )
F_151 ( V_58 , V_64 , V_191 ++ ) ;
V_64 = F_48 ( V_58 , V_255 ) ;
if ( ( V_64 >= 0 ) && ( V_58 -> V_3 . V_95 . V_158 & V_160 ) )
F_151 ( V_58 , V_64 , V_191 ++ ) ;
}
#endif
V_64 = F_48 ( V_58 , V_125 ) ;
if ( V_64 >= 0 && F_99 ( V_58 , V_64 ) )
F_151 ( V_58 , V_64 , V_191 ++ ) ;
V_58 -> V_191 = V_191 ;
if ( F_17 () ) {
if ( F_108 ( & V_58 -> V_3 ) )
V_249 = V_256 ;
else
V_249 = V_257 ;
F_80 ( V_258 , F_53 ( V_249 ) ) ;
}
}
static T_5 F_153 ( void )
{
T_5 V_259 , V_260 ;
F_154 ( V_259 ) ;
V_260 = F_72 ( V_261 ) ;
return V_259 + V_260 ;
}
T_5 F_155 ( struct V_2 * V_3 )
{
T_5 V_259 , V_260 ;
F_154 ( V_259 ) ;
V_260 = F_90 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_262 :
F_72 ( V_261 ) ;
return V_259 + V_260 ;
}
static void F_156 ( struct V_2 * V_3 , T_2 V_263 , bool V_264 )
{
if ( ! V_264 )
return;
if ( V_263 > V_265 ) {
V_3 -> V_95 . V_266 = 1 ;
V_3 -> V_95 . V_267 = 1 ;
} else
F_157 ( 1 , L_6 ) ;
}
static void F_158 ( struct V_2 * V_3 , T_5 V_268 )
{
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_262 = V_268 ;
V_7 = F_4 ( V_3 ) ;
F_80 ( V_261 , V_268 +
( F_44 ( V_7 , V_269 ) ?
V_7 -> V_260 : 0 ) ) ;
} else {
F_80 ( V_261 , V_268 ) ;
}
}
static void F_159 ( struct V_2 * V_3 , T_10 V_270 , bool V_135 )
{
T_5 V_268 = F_72 ( V_261 ) ;
F_80 ( V_261 , V_268 + V_270 ) ;
if ( F_90 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_262 += V_270 ;
}
}
static T_5 F_160 ( struct V_2 * V_3 , T_5 V_271 )
{
return V_271 - F_161 () ;
}
static bool F_162 ( struct V_2 * V_3 )
{
struct V_272 * V_273 = F_163 ( V_3 , 1 , 0 ) ;
return V_273 && ( V_273 -> V_274 & ( 1 << ( V_275 & 31 ) ) ) ;
}
static inline bool F_164 ( struct V_2 * V_3 )
{
return V_8 && F_162 ( V_3 ) ;
}
static T_11 void F_165 ( void )
{
V_276 = 0x16 ;
V_277 = 0x16 |
V_278 | V_279 |
V_52 ;
V_280 = 0 ;
#ifdef F_73
V_281 = V_282 ;
#else
V_281 = 0 ;
#endif
F_166 ( V_283 ,
V_284 , V_285 ) ;
V_284 = 0 ;
V_285 &=
V_286 | V_287 ;
F_166 ( V_288 ,
V_289 , V_290 ) ;
V_289 = 0 ;
V_290 &=
V_291 | V_269 |
V_292 | V_293 |
V_294 | V_295 |
V_296 |
#ifdef F_73
V_297 | V_298 |
#endif
V_299 | V_300 |
V_301 | V_302 |
V_303 |
V_28 ;
V_290 |= V_26 ;
F_166 ( V_304 ,
V_305 , V_306 ) ;
V_305 = 0 ;
V_306 &=
V_30 ;
}
static inline bool F_167 ( T_2 V_307 , T_2 V_308 , T_2 V_309 )
{
return ( ( V_307 & V_309 ) | V_308 ) == V_307 ;
}
static inline T_5 F_168 ( T_2 V_308 , T_2 V_309 )
{
return V_308 | ( ( T_5 ) V_309 << 32 ) ;
}
static int F_169 ( struct V_2 * V_3 , T_2 V_310 , T_5 * V_311 )
{
if ( ! F_164 ( V_3 ) && V_310 >= V_312 &&
V_310 <= V_313 ) {
F_170 ( V_3 , V_314 , 0 ) ;
return 1 ;
}
switch ( V_310 ) {
case V_315 :
* V_311 = 0 ;
break;
case V_312 :
* V_311 = V_316 |
( ( T_5 ) V_317 << V_318 ) |
( V_319 << V_320 ) ;
break;
case V_321 :
case V_322 :
* V_311 = F_168 ( V_276 ,
V_277 ) ;
break;
case V_323 :
case V_288 :
* V_311 = F_168 ( V_289 ,
V_290 ) ;
break;
case V_324 :
case V_325 :
* V_311 = F_168 ( V_280 ,
V_281 ) ;
break;
case V_313 :
case V_283 :
* V_311 = F_168 ( V_284 ,
V_285 ) ;
break;
case V_326 :
* V_311 = 0 ;
break;
#define F_171 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_172 X86_CR4_VMXE
case V_327 :
* V_311 = F_171 ;
break;
case V_328 :
* V_311 = - 1ULL ;
break;
case V_329 :
* V_311 = F_172 ;
break;
case V_330 :
* V_311 = - 1ULL ;
break;
case V_331 :
* V_311 = 0x1f ;
break;
case V_304 :
* V_311 = F_168 ( V_305 ,
V_306 ) ;
break;
case V_332 :
* V_311 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_173 ( struct V_2 * V_3 , T_2 V_310 , T_5 V_164 )
{
if ( ! F_164 ( V_3 ) )
return 0 ;
if ( V_310 == V_315 )
return 1 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_3 , T_2 V_310 , T_5 * V_311 )
{
T_5 V_164 ;
struct V_71 * V_59 ;
if ( ! V_311 ) {
F_54 ( V_74 L_7 ) ;
return - V_333 ;
}
switch ( V_310 ) {
#ifdef F_73
case V_185 :
V_164 = F_69 ( V_334 ) ;
break;
case V_187 :
V_164 = F_69 ( V_335 ) ;
break;
case V_188 :
F_118 ( F_1 ( V_3 ) ) ;
V_164 = F_1 ( V_3 ) -> V_190 ;
break;
#endif
case V_125 :
return F_175 ( V_3 , V_310 , V_311 ) ;
case V_336 :
V_164 = F_153 () ;
break;
case V_337 :
V_164 = F_71 ( V_338 ) ;
break;
case V_339 :
V_164 = F_69 ( V_340 ) ;
break;
case V_201 :
V_164 = F_69 ( V_341 ) ;
break;
case V_253 :
if ( ! F_1 ( V_3 ) -> V_254 )
return 1 ;
default:
if ( F_169 ( V_3 , V_310 , V_311 ) )
return 0 ;
V_59 = F_51 ( F_1 ( V_3 ) , V_310 ) ;
if ( V_59 ) {
V_164 = V_59 -> V_164 ;
break;
}
return F_175 ( V_3 , V_310 , V_311 ) ;
}
* V_311 = V_164 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , T_2 V_310 , T_5 V_164 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_71 * V_59 ;
int V_93 = 0 ;
switch ( V_310 ) {
case V_125 :
V_93 = F_177 ( V_3 , V_310 , V_164 ) ;
break;
#ifdef F_73
case V_185 :
F_83 ( V_58 ) ;
F_76 ( V_334 , V_164 ) ;
break;
case V_187 :
F_83 ( V_58 ) ;
F_76 ( V_335 , V_164 ) ;
break;
case V_188 :
F_118 ( V_58 ) ;
V_58 -> V_190 = V_164 ;
break;
#endif
case V_337 :
F_79 ( V_338 , V_164 ) ;
break;
case V_339 :
F_76 ( V_340 , V_164 ) ;
break;
case V_201 :
F_76 ( V_341 , V_164 ) ;
break;
case V_336 :
F_178 ( V_3 , V_164 ) ;
break;
case V_342 :
if ( V_24 . V_343 & V_286 ) {
F_80 ( V_344 , V_164 ) ;
V_3 -> V_95 . V_345 = V_164 ;
break;
}
V_93 = F_177 ( V_3 , V_310 , V_164 ) ;
break;
case V_253 :
if ( ! V_58 -> V_254 )
return 1 ;
if ( ( V_164 >> 32 ) != 0 )
return 1 ;
default:
if ( F_173 ( V_3 , V_310 , V_164 ) )
break;
V_59 = F_51 ( V_58 , V_310 ) ;
if ( V_59 ) {
V_59 -> V_164 = V_164 ;
if ( V_59 - V_58 -> V_63 < V_58 -> V_191 ) {
F_119 () ;
F_110 ( V_59 -> V_64 , V_59 -> V_164 ,
V_59 -> V_89 ) ;
F_120 () ;
}
break;
}
V_93 = F_177 ( V_3 , V_310 , V_164 ) ;
}
return V_93 ;
}
static void F_179 ( struct V_2 * V_3 , enum V_346 V_347 )
{
F_137 ( V_347 , ( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
switch ( V_347 ) {
case V_348 :
V_3 -> V_95 . V_349 [ V_348 ] = F_69 ( V_350 ) ;
break;
case V_351 :
V_3 -> V_95 . V_349 [ V_351 ] = F_69 ( V_352 ) ;
break;
case V_353 :
if ( V_84 )
F_180 ( V_3 ) ;
break;
default:
break;
}
}
static void F_181 ( struct V_2 * V_3 , struct V_354 * V_355 )
{
if ( V_3 -> V_111 & V_356 )
F_76 ( V_357 , V_355 -> V_95 . V_358 [ 7 ] ) ;
else
F_76 ( V_357 , V_3 -> V_95 . V_359 ) ;
F_89 ( V_3 ) ;
}
static T_11 int F_182 ( void )
{
return F_183 () ;
}
static T_11 int F_184 ( void )
{
T_5 V_59 ;
F_107 ( V_315 , V_59 ) ;
if ( V_59 & V_360 ) {
if ( ! ( V_59 & V_361 )
&& F_185 () )
return 1 ;
if ( ! ( V_59 & V_362 )
&& ( V_59 & V_361 )
&& ! F_185 () ) {
F_54 ( V_147 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_59 & V_362 )
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
static int F_186 ( void * V_363 )
{
int V_76 = F_58 () ;
T_5 V_73 = F_53 ( F_59 ( V_194 , V_76 ) ) ;
T_5 V_364 , V_365 ;
if ( F_187 () & V_366 )
return - V_367 ;
F_188 ( & F_59 ( V_198 , V_76 ) ) ;
F_107 ( V_315 , V_364 ) ;
V_365 = V_360 ;
V_365 |= V_362 ;
if ( F_185 () )
V_365 |= V_361 ;
if ( ( V_364 & V_365 ) != V_365 ) {
F_109 ( V_315 , V_364 | V_365 ) ;
}
F_189 ( F_187 () | V_366 ) ;
if ( V_195 ) {
F_122 ( V_73 ) ;
F_66 () ;
}
F_190 ( & F_97 ( V_150 ) ) ;
return 0 ;
}
static void F_191 ( void )
{
int V_76 = F_58 () ;
struct V_75 * V_167 , * V_368 ;
F_192 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_57 ( V_167 ) ;
}
static void F_128 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_193 ( void * V_363 )
{
if ( V_195 ) {
F_191 () ;
F_128 () ;
}
F_189 ( F_187 () & ~ V_366 ) ;
}
static T_11 int F_194 ( T_2 V_369 , T_2 V_370 ,
T_2 V_59 , T_2 * V_371 )
{
T_2 V_372 , V_373 ;
T_2 V_374 = V_369 | V_370 ;
F_166 ( V_59 , V_372 , V_373 ) ;
V_374 &= V_373 ;
V_374 |= V_372 ;
if ( V_369 & ~ V_374 )
return - V_375 ;
* V_371 = V_374 ;
return 0 ;
}
static T_11 bool F_195 ( T_2 V_59 , T_2 V_374 )
{
T_2 V_372 , V_373 ;
F_166 ( V_59 , V_372 , V_373 ) ;
return V_373 & V_374 ;
}
static T_11 int F_196 ( struct V_24 * V_376 )
{
T_2 V_372 , V_373 ;
T_2 V_377 , V_378 , V_379 , V_380 ;
T_2 V_381 = 0 ;
T_2 V_382 = 0 ;
T_2 V_383 = 0 ;
T_2 V_384 = 0 ;
T_2 V_385 = 0 ;
V_377 = V_278 | V_279 ;
V_378 = V_52 ;
if ( F_194 ( V_377 , V_378 , V_322 ,
& V_381 ) < 0 )
return - V_375 ;
V_377 = V_292 |
#ifdef F_73
V_297 |
V_298 |
#endif
V_295 |
V_296 |
V_301 |
V_299 |
V_269 |
V_294 |
V_302 |
V_293 |
V_303 ;
V_378 = V_27 |
V_26 |
V_28 ;
if ( F_194 ( V_377 , V_378 , V_288 ,
& V_382 ) < 0 )
return - V_375 ;
#ifdef F_73
if ( ( V_382 & V_27 ) )
V_382 &= ~ V_297 &
~ V_298 ;
#endif
if ( V_382 & V_28 ) {
V_379 = 0 ;
V_380 = V_30 |
V_53 |
V_49 |
V_45 |
V_46 |
V_47 |
V_50 ;
if ( F_194 ( V_379 , V_380 ,
V_304 ,
& V_383 ) < 0 )
return - V_375 ;
}
#ifndef F_73
if ( ! ( V_383 &
V_30 ) )
V_382 &= ~ V_27 ;
#endif
if ( V_383 & V_45 ) {
V_382 &= ~ ( V_295 |
V_296 |
V_293 ) ;
F_166 ( V_332 ,
V_31 . V_32 , V_31 . V_42 ) ;
}
V_377 = 0 ;
#ifdef F_73
V_377 |= V_282 ;
#endif
V_378 = V_386 | V_387 ;
if ( F_194 ( V_377 , V_378 , V_325 ,
& V_384 ) < 0 )
return - V_375 ;
V_377 = 0 ;
V_378 = V_286 ;
if ( F_194 ( V_377 , V_378 , V_283 ,
& V_385 ) < 0 )
return - V_375 ;
F_166 ( V_312 , V_372 , V_373 ) ;
if ( ( V_373 & 0x1fff ) > V_388 )
return - V_375 ;
#ifdef F_73
if ( V_373 & ( 1u << 16 ) )
return - V_375 ;
#endif
if ( ( ( V_373 >> 18 ) & 15 ) != 6 )
return - V_375 ;
V_376 -> V_389 = V_373 & 0x1fff ;
V_376 -> V_390 = F_197 ( V_24 . V_389 ) ;
V_376 -> V_391 = V_372 ;
V_376 -> V_51 = V_381 ;
V_376 -> V_25 = V_382 ;
V_376 -> V_29 = V_383 ;
V_376 -> V_392 = V_384 ;
V_376 -> V_343 = V_385 ;
V_126 =
F_195 ( V_283 ,
V_127 )
&& F_195 ( V_325 ,
V_128 ) ;
V_130 =
F_195 ( V_283 ,
V_131 )
&& F_195 ( V_325 ,
V_132 ) ;
if ( V_130 && V_393 . V_394 == 0x6 ) {
switch ( V_393 . V_395 ) {
case 26 :
case 30 :
case 37 :
case 44 :
case 46 :
V_130 = false ;
F_95 ( V_147 L_10
L_11 ) ;
break;
default:
break;
}
}
return 0 ;
}
static struct V_72 * F_198 ( int V_76 )
{
int V_396 = F_199 ( V_76 ) ;
struct V_10 * V_397 ;
struct V_72 * V_72 ;
V_397 = F_200 ( V_396 , V_398 , V_24 . V_390 ) ;
if ( ! V_397 )
return NULL ;
V_72 = F_201 ( V_397 ) ;
memset ( V_72 , 0 , V_24 . V_389 ) ;
V_72 -> V_391 = V_24 . V_391 ;
return V_72 ;
}
static struct V_72 * F_202 ( void )
{
return F_198 ( F_58 () ) ;
}
static void F_203 ( struct V_72 * V_72 )
{
F_204 ( ( unsigned long ) V_72 , V_24 . V_390 ) ;
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
F_203 ( F_59 ( V_194 , V_76 ) ) ;
F_59 ( V_194 , V_76 ) = NULL ;
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
return - V_399 ;
}
F_59 ( V_194 , V_76 ) = V_72 ;
}
return 0 ;
}
static T_11 int F_209 ( void )
{
if ( F_196 ( & V_24 ) < 0 )
return - V_375 ;
if ( F_210 ( V_400 ) )
F_211 ( V_159 ) ;
if ( ! F_39 () )
V_401 = 0 ;
if ( ! F_35 () ||
! F_29 () ) {
V_84 = 0 ;
V_402 = 0 ;
}
if ( ! F_36 () )
V_402 = 0 ;
if ( ! F_23 () )
V_48 = 0 ;
if ( ! F_18 () )
V_403 -> V_404 = NULL ;
if ( V_84 && ! F_27 () )
F_212 () ;
if ( ! F_37 () )
V_405 = 0 ;
if ( V_8 )
F_165 () ;
return F_208 () ;
}
static T_12 void F_213 ( void )
{
F_206 () ;
}
static void F_214 ( int V_92 , struct V_406 * V_407 )
{
struct V_408 * V_409 = & V_101 [ V_92 ] ;
if ( F_69 ( V_409 -> V_102 ) == V_407 -> V_102 && ( V_407 -> V_102 & V_410 ) ) {
F_78 ( V_409 -> V_99 , V_407 -> V_99 ) ;
F_76 ( V_409 -> V_102 , V_407 -> V_102 ) ;
F_79 ( V_409 -> V_104 , V_407 -> V_104 ) ;
F_79 ( V_409 -> V_108 , V_407 -> V_106 ) ;
} else {
T_2 V_411 = ( F_70 ( V_409 -> V_99 ) & V_412 )
<< V_413 ;
F_79 ( V_409 -> V_108 , 0x93 | V_411 ) ;
}
}
static void F_215 ( struct V_2 * V_3 )
{
unsigned long V_414 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
V_58 -> V_415 = 1 ;
V_58 -> V_115 . V_116 = 0 ;
F_83 ( V_58 ) ;
F_78 ( V_416 , V_58 -> V_115 . V_172 . V_99 ) ;
F_76 ( V_417 , V_58 -> V_115 . V_172 . V_102 ) ;
F_79 ( V_418 , V_58 -> V_115 . V_172 . V_104 ) ;
F_79 ( V_419 , V_58 -> V_115 . V_172 . V_106 ) ;
V_414 = F_69 ( V_220 ) ;
V_414 &= V_221 ;
V_414 |= V_58 -> V_115 . V_218 & ~ V_221 ;
F_76 ( V_220 , V_414 ) ;
F_76 ( V_420 , ( F_69 ( V_420 ) & ~ V_421 ) |
( F_69 ( V_422 ) & V_421 ) ) ;
F_89 ( V_3 ) ;
if ( V_423 )
return;
F_214 ( V_424 , & V_58 -> V_115 . V_425 ) ;
F_214 ( V_426 , & V_58 -> V_115 . V_427 ) ;
F_214 ( V_428 , & V_58 -> V_115 . V_181 ) ;
F_214 ( V_429 , & V_58 -> V_115 . V_177 ) ;
F_83 ( V_58 ) ;
F_78 ( V_430 , 0 ) ;
F_79 ( V_431 , 0x93 ) ;
F_78 ( V_432 ,
F_70 ( V_432 ) & ~ V_412 ) ;
F_79 ( V_433 , 0x9b ) ;
}
static T_4 F_216 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_95 . V_434 ) {
struct V_435 * V_436 ;
struct V_437 * V_438 ;
T_13 V_439 ;
V_436 = V_435 ( V_12 ) ;
V_438 = F_217 ( V_436 , 0 ) ;
V_439 = V_438 -> V_439 + V_438 -> V_440 - 3 ;
return V_439 << V_13 ;
}
return V_12 -> V_95 . V_434 ;
}
static void F_218 ( int V_92 , struct V_406 * V_407 )
{
struct V_408 * V_409 = & V_101 [ V_92 ] ;
V_407 -> V_99 = F_70 ( V_409 -> V_99 ) ;
V_407 -> V_102 = F_69 ( V_409 -> V_102 ) ;
V_407 -> V_104 = F_71 ( V_409 -> V_104 ) ;
V_407 -> V_106 = F_71 ( V_409 -> V_108 ) ;
F_78 ( V_409 -> V_99 , V_407 -> V_102 >> 4 ) ;
F_79 ( V_409 -> V_102 , V_407 -> V_102 & 0xffff0 ) ;
F_79 ( V_409 -> V_104 , 0xffff ) ;
F_79 ( V_409 -> V_108 , 0xf3 ) ;
if ( V_407 -> V_102 & 0xf )
F_95 ( V_147 L_12
L_13 ,
V_92 ) ;
}
static void F_219 ( struct V_2 * V_3 )
{
unsigned long V_414 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_402 )
return;
V_58 -> V_415 = 1 ;
V_58 -> V_115 . V_116 = 1 ;
if ( ! V_3 -> V_12 -> V_95 . V_434 ) {
F_95 ( V_147 L_14
L_15 ) ;
F_220 ( & V_3 -> V_12 -> V_441 , V_3 -> V_442 ) ;
F_221 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_442 = F_222 ( & V_3 -> V_12 -> V_441 ) ;
}
F_83 ( V_58 ) ;
V_58 -> V_115 . V_172 . V_99 = F_70 ( V_416 ) ;
V_58 -> V_115 . V_172 . V_102 = F_69 ( V_417 ) ;
F_76 ( V_417 , F_216 ( V_3 -> V_12 ) ) ;
V_58 -> V_115 . V_172 . V_104 = F_71 ( V_418 ) ;
F_79 ( V_418 , V_443 - 1 ) ;
V_58 -> V_115 . V_172 . V_106 = F_71 ( V_419 ) ;
F_79 ( V_419 , 0x008b ) ;
V_414 = F_69 ( V_220 ) ;
V_58 -> V_115 . V_218 = V_414 ;
V_414 |= V_223 | V_224 ;
F_76 ( V_220 , V_414 ) ;
F_76 ( V_420 , F_69 ( V_420 ) | V_421 ) ;
F_89 ( V_3 ) ;
if ( V_423 )
goto V_444;
F_78 ( V_430 , F_69 ( V_445 ) >> 4 ) ;
F_79 ( V_446 , 0xffff ) ;
F_79 ( V_431 , 0xf3 ) ;
F_79 ( V_433 , 0xf3 ) ;
F_79 ( V_447 , 0xffff ) ;
if ( F_69 ( V_448 ) == 0xffff0000 )
F_76 ( V_448 , 0xf0000 ) ;
F_78 ( V_432 , F_69 ( V_448 ) >> 4 ) ;
F_218 ( V_424 , & V_58 -> V_115 . V_425 ) ;
F_218 ( V_426 , & V_58 -> V_115 . V_427 ) ;
F_218 ( V_428 , & V_58 -> V_115 . V_181 ) ;
F_218 ( V_429 , & V_58 -> V_115 . V_177 ) ;
V_444:
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
V_287 ) ;
V_59 -> V_164 = V_158 ;
} else {
F_79 ( V_121 ,
F_71 ( V_121 ) &
~ V_287 ) ;
V_59 -> V_164 = V_158 & ~ V_162 ;
}
F_152 ( V_58 ) ;
}
static void F_225 ( struct V_2 * V_3 )
{
T_2 V_449 ;
F_83 ( F_1 ( V_3 ) ) ;
V_449 = F_71 ( V_419 ) ;
if ( ( V_449 & V_450 ) != V_451 ) {
F_226 ( L_16 ,
V_452 ) ;
F_79 ( V_419 ,
( V_449 & ~ V_450 )
| V_451 ) ;
}
F_224 ( V_3 , V_3 -> V_95 . V_158 | V_161 ) ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_79 ( V_121 ,
F_71 ( V_121 )
& ~ V_287 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 & ~ V_161 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_65 ( F_1 ( V_3 ) ) ;
if ( V_84 ) {
if ( ! F_229 ( V_3 -> V_95 . V_453 . V_454 ) )
return;
F_67 ( F_230 ( V_3 -> V_95 . V_453 . V_454 ) ) ;
}
}
static void F_134 ( struct V_2 * V_3 )
{
T_9 V_207 = V_3 -> V_95 . V_207 ;
V_3 -> V_95 . V_203 &= ~ V_207 ;
V_3 -> V_95 . V_203 |= F_69 ( V_204 ) & V_207 ;
}
static void F_231 ( struct V_2 * V_3 )
{
if ( V_84 && F_232 ( V_3 ) )
V_3 -> V_95 . V_455 = F_69 ( V_456 ) ;
F_137 ( V_457 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_233 ( struct V_2 * V_3 )
{
T_9 V_458 = V_3 -> V_95 . V_458 ;
V_3 -> V_95 . V_459 &= ~ V_458 ;
V_3 -> V_95 . V_459 |= F_69 ( V_420 ) & V_458 ;
}
static void F_234 ( struct V_2 * V_3 )
{
if ( ! F_136 ( V_353 ,
( unsigned long * ) & V_3 -> V_95 . V_460 ) )
return;
if ( F_232 ( V_3 ) && F_235 ( V_3 ) && ! F_108 ( V_3 ) ) {
F_80 ( V_461 , V_3 -> V_95 . V_453 . V_462 [ 0 ] ) ;
F_80 ( V_463 , V_3 -> V_95 . V_453 . V_462 [ 1 ] ) ;
F_80 ( V_464 , V_3 -> V_95 . V_453 . V_462 [ 2 ] ) ;
F_80 ( V_465 , V_3 -> V_95 . V_453 . V_462 [ 3 ] ) ;
}
}
static void F_180 ( struct V_2 * V_3 )
{
if ( F_232 ( V_3 ) && F_235 ( V_3 ) && ! F_108 ( V_3 ) ) {
V_3 -> V_95 . V_453 . V_462 [ 0 ] = F_72 ( V_461 ) ;
V_3 -> V_95 . V_453 . V_462 [ 1 ] = F_72 ( V_463 ) ;
V_3 -> V_95 . V_453 . V_462 [ 2 ] = F_72 ( V_464 ) ;
V_3 -> V_95 . V_453 . V_462 [ 3 ] = F_72 ( V_465 ) ;
}
F_137 ( V_353 ,
( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
F_137 ( V_353 ,
( unsigned long * ) & V_3 -> V_95 . V_460 ) ;
}
static void F_236 ( unsigned long * V_466 ,
unsigned long V_203 ,
struct V_2 * V_3 )
{
if ( ! F_136 ( V_457 , ( T_9 * ) & V_3 -> V_95 . V_96 ) )
F_231 ( V_3 ) ;
if ( ! ( V_203 & V_467 ) ) {
F_79 ( V_468 ,
F_71 ( V_468 ) |
( V_295 |
V_296 ) ) ;
V_3 -> V_95 . V_203 = V_203 ;
F_237 ( V_3 , F_238 ( V_3 ) ) ;
} else if ( ! F_232 ( V_3 ) ) {
F_79 ( V_468 ,
F_71 ( V_468 ) &
~ ( V_295 |
V_296 ) ) ;
V_3 -> V_95 . V_203 = V_203 ;
F_237 ( V_3 , F_238 ( V_3 ) ) ;
}
if ( ! ( V_203 & V_469 ) )
* V_466 &= ~ V_469 ;
}
static void F_239 ( struct V_2 * V_3 , unsigned long V_203 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_466 ;
if ( V_402 )
V_466 = ( V_203 & ~ V_470 )
| V_471 ;
else
V_466 = ( V_203 & ~ V_472 ) | V_473 ;
if ( V_58 -> V_115 . V_116 && ( V_203 & V_474 ) )
F_215 ( V_3 ) ;
if ( ! V_58 -> V_115 . V_116 && ! ( V_203 & V_474 ) )
F_219 ( V_3 ) ;
#ifdef F_73
if ( V_3 -> V_95 . V_158 & V_162 ) {
if ( ! F_232 ( V_3 ) && ( V_203 & V_467 ) )
F_225 ( V_3 ) ;
if ( F_232 ( V_3 ) && ! ( V_203 & V_467 ) )
F_227 ( V_3 ) ;
}
#endif
if ( V_84 )
F_236 ( & V_466 , V_203 , V_3 ) ;
if ( ! V_3 -> V_117 )
V_466 |= V_205 | V_206 ;
F_76 ( V_216 , V_203 ) ;
F_76 ( V_204 , V_466 ) ;
V_3 -> V_95 . V_203 = V_203 ;
F_139 ( V_222 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static T_5 F_230 ( unsigned long V_454 )
{
T_5 V_69 ;
V_69 = V_475 |
V_476 << V_477 ;
V_69 |= ( V_454 & V_478 ) ;
return V_69 ;
}
static void F_240 ( struct V_2 * V_3 , unsigned long V_455 )
{
unsigned long V_479 ;
T_5 V_69 ;
V_479 = V_455 ;
if ( V_84 ) {
V_69 = F_230 ( V_455 ) ;
F_80 ( V_480 , V_69 ) ;
V_479 = F_232 ( V_3 ) ? F_241 ( V_3 ) :
V_3 -> V_12 -> V_95 . V_481 ;
F_234 ( V_3 ) ;
}
F_228 ( V_3 ) ;
F_76 ( V_456 , V_479 ) ;
}
static int F_237 ( struct V_2 * V_3 , unsigned long V_459 )
{
unsigned long V_482 = V_459 | ( F_1 ( V_3 ) -> V_115 . V_116 ?
V_483 : V_484 ) ;
if ( V_459 & V_366 ) {
if ( ! F_164 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_485 )
return 1 ;
V_3 -> V_95 . V_459 = V_459 ;
if ( V_84 ) {
if ( ! F_232 ( V_3 ) ) {
V_482 &= ~ V_486 ;
V_482 |= V_487 ;
} else if ( ! ( V_459 & V_486 ) ) {
V_482 &= ~ V_486 ;
}
}
F_76 ( V_422 , V_459 ) ;
F_76 ( V_420 , V_482 ) ;
return 0 ;
}
static void F_242 ( struct V_2 * V_3 ,
struct V_488 * V_489 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_406 * V_407 ;
T_2 V_106 ;
if ( V_58 -> V_115 . V_116
&& ( V_92 == V_490 || V_92 == V_424
|| V_92 == V_426 || V_92 == V_429
|| V_92 == V_428 )
&& ! V_423 ) {
switch ( V_92 ) {
case V_490 : V_407 = & V_58 -> V_115 . V_172 ; break;
case V_424 : V_407 = & V_58 -> V_115 . V_425 ; break;
case V_426 : V_407 = & V_58 -> V_115 . V_427 ; break;
case V_429 : V_407 = & V_58 -> V_115 . V_177 ; break;
case V_428 : V_407 = & V_58 -> V_115 . V_181 ; break;
default: F_243 () ;
}
V_489 -> V_99 = V_407 -> V_99 ;
V_489 -> V_102 = V_407 -> V_102 ;
V_489 -> V_104 = V_407 -> V_104 ;
V_106 = V_407 -> V_106 ;
if ( V_92 == V_490
|| V_489 -> V_99 == F_85 ( V_58 , V_92 ) )
goto V_491;
}
V_489 -> V_102 = F_86 ( V_58 , V_92 ) ;
V_489 -> V_104 = F_87 ( V_58 , V_92 ) ;
V_489 -> V_99 = F_85 ( V_58 , V_92 ) ;
V_106 = F_88 ( V_58 , V_92 ) ;
V_491:
if ( ( V_106 & V_492 ) && ! V_423 )
V_106 = 0 ;
V_489 -> type = V_106 & 15 ;
V_489 -> V_169 = ( V_106 >> 4 ) & 1 ;
V_489 -> V_411 = ( V_106 >> 5 ) & 3 ;
V_489 -> V_493 = ( V_106 >> 7 ) & 1 ;
V_489 -> V_494 = ( V_106 >> 12 ) & 1 ;
V_489 -> V_495 = ( V_106 >> 13 ) & 1 ;
V_489 -> V_496 = ( V_106 >> 14 ) & 1 ;
V_489 -> V_497 = ( V_106 >> 15 ) & 1 ;
V_489 -> V_498 = ( V_106 >> 16 ) & 1 ;
}
static T_5 F_244 ( struct V_2 * V_3 , int V_92 )
{
struct V_488 V_169 ;
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
&& ( F_247 ( V_3 ) & V_224 ) )
return 3 ;
return F_85 ( F_1 ( V_3 ) , V_499 ) & 3 ;
}
static int F_248 ( struct V_2 * V_3 )
{
if ( ! F_136 ( V_222 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_137 ( V_222 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_500 = F_245 ( V_3 ) ;
}
return F_1 ( V_3 ) -> V_500 ;
}
static T_2 F_249 ( struct V_488 * V_489 )
{
T_2 V_106 ;
if ( V_489 -> V_498 )
V_106 = 1 << 16 ;
else {
V_106 = V_489 -> type & 15 ;
V_106 |= ( V_489 -> V_169 & 1 ) << 4 ;
V_106 |= ( V_489 -> V_411 & 3 ) << 5 ;
V_106 |= ( V_489 -> V_493 & 1 ) << 7 ;
V_106 |= ( V_489 -> V_494 & 1 ) << 12 ;
V_106 |= ( V_489 -> V_495 & 1 ) << 13 ;
V_106 |= ( V_489 -> V_496 & 1 ) << 14 ;
V_106 |= ( V_489 -> V_497 & 1 ) << 15 ;
}
if ( V_106 == 0 )
V_106 = V_492 ;
return V_106 ;
}
static void F_250 ( struct V_2 * V_3 ,
struct V_488 * V_489 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_408 * V_409 = & V_101 [ V_92 ] ;
T_2 V_106 ;
F_83 ( V_58 ) ;
if ( V_58 -> V_115 . V_116 && V_92 == V_490 ) {
F_78 ( V_409 -> V_99 , V_489 -> V_99 ) ;
V_58 -> V_115 . V_172 . V_99 = V_489 -> V_99 ;
V_58 -> V_115 . V_172 . V_102 = V_489 -> V_102 ;
V_58 -> V_115 . V_172 . V_104 = V_489 -> V_104 ;
V_58 -> V_115 . V_172 . V_106 = F_249 ( V_489 ) ;
return;
}
F_76 ( V_409 -> V_102 , V_489 -> V_102 ) ;
F_79 ( V_409 -> V_104 , V_489 -> V_104 ) ;
F_78 ( V_409 -> V_99 , V_489 -> V_99 ) ;
if ( V_58 -> V_115 . V_116 && V_489 -> V_169 ) {
if ( V_489 -> V_102 == 0xffff0000 && V_489 -> V_99 == 0xf000 )
F_76 ( V_409 -> V_102 , 0xf0000 ) ;
V_106 = 0xf3 ;
} else
V_106 = F_249 ( V_489 ) ;
if ( V_402 && ( V_92 != V_501 ) )
V_106 |= 0x1 ;
F_79 ( V_409 -> V_108 , V_106 ) ;
F_139 ( V_222 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_251 ( struct V_2 * V_3 , int * V_496 , int * V_495 )
{
T_2 V_106 = F_88 ( F_1 ( V_3 ) , V_499 ) ;
* V_496 = ( V_106 >> 14 ) & 1 ;
* V_495 = ( V_106 >> 13 ) & 1 ;
}
static void F_252 ( struct V_2 * V_3 , struct V_148 * V_502 )
{
V_502 -> V_389 = F_71 ( V_503 ) ;
V_502 -> V_153 = F_69 ( V_504 ) ;
}
static void F_253 ( struct V_2 * V_3 , struct V_148 * V_502 )
{
F_79 ( V_503 , V_502 -> V_389 ) ;
F_76 ( V_504 , V_502 -> V_153 ) ;
}
static void F_254 ( struct V_2 * V_3 , struct V_148 * V_502 )
{
V_502 -> V_389 = F_71 ( V_505 ) ;
V_502 -> V_153 = F_69 ( V_506 ) ;
}
static void F_255 ( struct V_2 * V_3 , struct V_148 * V_502 )
{
F_79 ( V_505 , V_502 -> V_389 ) ;
F_76 ( V_506 , V_502 -> V_153 ) ;
}
static bool F_256 ( struct V_2 * V_3 , int V_92 )
{
struct V_488 V_489 ;
T_2 V_106 ;
F_242 ( V_3 , & V_489 , V_92 ) ;
V_106 = F_249 ( & V_489 ) ;
if ( V_489 . V_102 != ( V_489 . V_99 << 4 ) )
return false ;
if ( V_489 . V_104 != 0xffff )
return false ;
if ( V_106 != 0xf3 )
return false ;
return true ;
}
static bool F_257 ( struct V_2 * V_3 )
{
struct V_488 V_507 ;
unsigned int V_508 ;
F_242 ( V_3 , & V_507 , V_499 ) ;
V_508 = V_507 . V_99 & V_412 ;
if ( V_507 . V_498 )
return false ;
if ( ~ V_507 . type & ( V_509 | V_510 ) )
return false ;
if ( ! V_507 . V_169 )
return false ;
if ( V_507 . type & V_511 ) {
if ( V_507 . V_411 > V_508 )
return false ;
} else {
if ( V_507 . V_411 != V_508 )
return false ;
}
if ( ! V_507 . V_493 )
return false ;
return true ;
}
static bool F_258 ( struct V_2 * V_3 )
{
struct V_488 V_512 ;
unsigned int V_513 ;
F_242 ( V_3 , & V_512 , V_514 ) ;
V_513 = V_512 . V_99 & V_412 ;
if ( V_512 . V_498 )
return true ;
if ( V_512 . type != 3 && V_512 . type != 7 )
return false ;
if ( ! V_512 . V_169 )
return false ;
if ( V_512 . V_411 != V_513 )
return false ;
if ( ! V_512 . V_493 )
return false ;
return true ;
}
static bool F_259 ( struct V_2 * V_3 , int V_92 )
{
struct V_488 V_489 ;
unsigned int V_515 ;
F_242 ( V_3 , & V_489 , V_92 ) ;
V_515 = V_489 . V_99 & V_412 ;
if ( V_489 . V_498 )
return true ;
if ( ! V_489 . V_169 )
return false ;
if ( ! V_489 . V_493 )
return false ;
if ( ~ V_489 . type & ( V_509 | V_511 ) ) {
if ( V_489 . V_411 < V_515 )
return false ;
}
return true ;
}
static bool F_260 ( struct V_2 * V_3 )
{
struct V_488 V_172 ;
F_242 ( V_3 , & V_172 , V_490 ) ;
if ( V_172 . V_498 )
return false ;
if ( V_172 . V_99 & V_516 )
return false ;
if ( V_172 . type != 3 && V_172 . type != 11 )
return false ;
if ( ! V_172 . V_493 )
return false ;
return true ;
}
static bool F_261 ( struct V_2 * V_3 )
{
struct V_488 V_517 ;
F_242 ( V_3 , & V_517 , V_501 ) ;
if ( V_517 . V_498 )
return true ;
if ( V_517 . V_99 & V_516 )
return false ;
if ( V_517 . type != 2 )
return false ;
if ( ! V_517 . V_493 )
return false ;
return true ;
}
static bool F_262 ( struct V_2 * V_3 )
{
struct V_488 V_507 , V_512 ;
F_242 ( V_3 , & V_507 , V_499 ) ;
F_242 ( V_3 , & V_512 , V_514 ) ;
return ( ( V_507 . V_99 & V_412 ) ==
( V_512 . V_99 & V_412 ) ) ;
}
static bool F_263 ( struct V_2 * V_3 )
{
if ( ! F_246 ( V_3 ) ) {
if ( ! F_256 ( V_3 , V_499 ) )
return false ;
if ( ! F_256 ( V_3 , V_514 ) )
return false ;
if ( ! F_256 ( V_3 , V_426 ) )
return false ;
if ( ! F_256 ( V_3 , V_424 ) )
return false ;
if ( ! F_256 ( V_3 , V_429 ) )
return false ;
if ( ! F_256 ( V_3 , V_428 ) )
return false ;
} else {
if ( ! F_262 ( V_3 ) )
return false ;
if ( ! F_257 ( V_3 ) )
return false ;
if ( ! F_258 ( V_3 ) )
return false ;
if ( ! F_259 ( V_3 , V_426 ) )
return false ;
if ( ! F_259 ( V_3 , V_424 ) )
return false ;
if ( ! F_259 ( V_3 , V_429 ) )
return false ;
if ( ! F_259 ( V_3 , V_428 ) )
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
T_13 V_518 ;
T_3 V_164 = 0 ;
int V_519 , V_520 , V_93 = 0 ;
V_520 = F_222 ( & V_12 -> V_441 ) ;
V_518 = F_216 ( V_12 ) >> V_13 ;
V_519 = F_265 ( V_12 , V_518 , 0 , V_388 ) ;
if ( V_519 < 0 )
goto V_521;
V_164 = V_522 + V_523 ;
V_519 = F_266 ( V_12 , V_518 ++ , & V_164 ,
V_524 , sizeof( T_3 ) ) ;
if ( V_519 < 0 )
goto V_521;
V_519 = F_265 ( V_12 , V_518 ++ , 0 , V_388 ) ;
if ( V_519 < 0 )
goto V_521;
V_519 = F_265 ( V_12 , V_518 , 0 , V_388 ) ;
if ( V_519 < 0 )
goto V_521;
V_164 = ~ 0 ;
V_519 = F_266 ( V_12 , V_518 , & V_164 ,
V_443 - 2 * V_388 - 1 ,
sizeof( T_6 ) ) ;
if ( V_519 < 0 )
goto V_521;
V_93 = 1 ;
V_521:
F_220 ( & V_12 -> V_441 , V_520 ) ;
return V_93 ;
}
static int F_267 ( struct V_12 * V_12 )
{
int V_60 , V_520 , V_519 , V_93 ;
T_14 V_525 ;
T_2 V_248 ;
if ( ! V_84 )
return 1 ;
if ( F_77 ( ! V_12 -> V_95 . V_526 ) ) {
F_54 ( V_74 L_17
L_18 ) ;
return 0 ;
}
if ( F_268 ( V_12 -> V_95 . V_527 ) )
return 1 ;
V_93 = 0 ;
V_525 = V_12 -> V_95 . V_481 >> V_13 ;
V_520 = F_222 ( & V_12 -> V_441 ) ;
V_519 = F_265 ( V_12 , V_525 , 0 , V_388 ) ;
if ( V_519 < 0 )
goto V_521;
for ( V_60 = 0 ; V_60 < V_528 ; V_60 ++ ) {
V_248 = ( V_60 << 22 ) + ( V_529 | V_530 | V_531 |
V_532 | V_533 | V_534 ) ;
V_519 = F_266 ( V_12 , V_525 ,
& V_248 , V_60 * sizeof( V_248 ) , sizeof( V_248 ) ) ;
if ( V_519 < 0 )
goto V_521;
}
V_12 -> V_95 . V_527 = true ;
V_93 = 1 ;
V_521:
F_220 ( & V_12 -> V_441 , V_520 ) ;
return V_93 ;
}
static void F_269 ( int V_92 )
{
struct V_408 * V_409 = & V_101 [ V_92 ] ;
unsigned int V_106 ;
F_78 ( V_409 -> V_99 , 0 ) ;
F_76 ( V_409 -> V_102 , 0 ) ;
F_79 ( V_409 -> V_104 , 0xffff ) ;
if ( V_402 ) {
V_106 = 0x93 ;
if ( V_92 == V_499 )
V_106 |= 0x08 ;
} else
V_106 = 0xf3 ;
F_79 ( V_409 -> V_108 , V_106 ) ;
}
static int F_270 ( struct V_12 * V_12 )
{
struct V_535 V_536 ;
int V_519 = 0 ;
F_271 ( & V_12 -> V_537 ) ;
if ( V_12 -> V_95 . V_538 )
goto V_521;
V_536 . V_438 = V_539 ;
V_536 . V_414 = 0 ;
V_536 . V_540 = 0xfee00000ULL ;
V_536 . V_541 = V_388 ;
V_519 = F_272 ( V_12 , & V_536 , 0 ) ;
if ( V_519 )
goto V_521;
V_12 -> V_95 . V_538 = F_6 ( V_12 , 0xfee00 ) ;
V_521:
F_273 ( & V_12 -> V_537 ) ;
return V_519 ;
}
static int F_274 ( struct V_12 * V_12 )
{
struct V_535 V_536 ;
int V_519 = 0 ;
F_271 ( & V_12 -> V_537 ) ;
if ( V_12 -> V_95 . V_526 )
goto V_521;
V_536 . V_438 = V_542 ;
V_536 . V_414 = 0 ;
V_536 . V_540 =
V_12 -> V_95 . V_481 ;
V_536 . V_541 = V_388 ;
V_519 = F_272 ( V_12 , & V_536 , 0 ) ;
if ( V_519 )
goto V_521;
V_12 -> V_95 . V_526 = F_6 ( V_12 ,
V_12 -> V_95 . V_481 >> V_13 ) ;
V_521:
F_273 ( & V_12 -> V_537 ) ;
return V_519 ;
}
static void F_275 ( struct V_1 * V_58 )
{
int V_42 ;
V_58 -> V_42 = 0 ;
if ( ! V_401 )
return;
F_276 ( & V_543 ) ;
V_42 = F_277 ( V_544 , V_545 ) ;
if ( V_42 < V_545 ) {
V_58 -> V_42 = V_42 ;
F_137 ( V_42 , V_544 ) ;
}
F_278 ( & V_543 ) ;
}
static void F_279 ( struct V_1 * V_58 )
{
if ( ! V_401 )
return;
F_276 ( & V_543 ) ;
if ( V_58 -> V_42 != 0 )
F_139 ( V_58 -> V_42 , V_544 ) ;
F_278 ( & V_543 ) ;
}
static void F_280 ( unsigned long * V_249 , T_2 V_59 )
{
int V_546 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_59 <= 0x1fff ) {
F_139 ( V_59 , V_249 + 0x000 / V_546 ) ;
F_139 ( V_59 , V_249 + 0x800 / V_546 ) ;
} else if ( ( V_59 >= 0xc0000000 ) && ( V_59 <= 0xc0001fff ) ) {
V_59 &= 0x1fff ;
F_139 ( V_59 , V_249 + 0x400 / V_546 ) ;
F_139 ( V_59 , V_249 + 0xc00 / V_546 ) ;
}
}
static void F_281 ( T_2 V_59 , bool V_547 )
{
if ( ! V_547 )
F_280 ( V_257 , V_59 ) ;
F_280 ( V_256 , V_59 ) ;
}
static void F_282 ( void )
{
T_2 V_548 , V_549 ;
unsigned long V_550 ;
struct V_148 V_502 ;
F_76 ( V_551 , F_283 () | V_205 ) ;
F_76 ( V_552 , F_187 () ) ;
F_76 ( V_553 , F_284 () ) ;
F_78 ( V_554 , V_555 ) ;
F_78 ( V_556 , V_557 ) ;
F_78 ( V_558 , V_557 ) ;
F_78 ( V_559 , V_557 ) ;
F_78 ( V_560 , V_154 * 8 ) ;
F_285 ( & V_502 ) ;
F_76 ( V_561 , V_502 . V_153 ) ;
asm("mov $.Lkvm_vmx_return, %0" : "=r"(tmpl));
F_76 ( V_562 , V_550 ) ;
F_166 ( V_337 , V_548 , V_549 ) ;
F_79 ( V_563 , V_548 ) ;
F_107 ( V_339 , V_550 ) ;
F_76 ( V_564 , V_550 ) ;
if ( V_24 . V_392 & V_387 ) {
F_166 ( V_342 , V_548 , V_549 ) ;
F_80 ( V_565 , V_548 | ( ( T_5 ) V_549 << 32 ) ) ;
}
}
static void F_286 ( struct V_1 * V_58 )
{
V_58 -> V_3 . V_95 . V_458 = V_566 ;
if ( V_84 )
V_58 -> V_3 . V_95 . V_458 |= V_567 ;
if ( F_90 ( & V_58 -> V_3 ) )
V_58 -> V_3 . V_95 . V_458 &=
~ F_4 ( & V_58 -> V_3 ) -> V_214 ;
F_76 ( V_568 , ~ V_58 -> V_3 . V_95 . V_458 ) ;
}
static T_2 F_287 ( struct V_1 * V_58 )
{
T_2 V_569 = V_24 . V_25 ;
if ( ! F_19 ( V_58 -> V_3 . V_12 ) ) {
V_569 &= ~ V_27 ;
#ifdef F_73
V_569 |= V_298 |
V_297 ;
#endif
}
if ( ! V_84 )
V_569 |= V_296 |
V_295 |
V_293 ;
return V_569 ;
}
static T_2 F_288 ( struct V_1 * V_58 )
{
T_2 V_569 = V_24 . V_29 ;
if ( ! F_38 ( V_58 -> V_3 . V_12 ) )
V_569 &= ~ V_30 ;
if ( V_58 -> V_42 == 0 )
V_569 &= ~ V_49 ;
if ( ! V_84 ) {
V_569 &= ~ V_45 ;
V_402 = 0 ;
}
if ( ! V_402 )
V_569 &= ~ V_46 ;
if ( ! V_405 )
V_569 &= ~ V_47 ;
return V_569 ;
}
static void F_289 ( void )
{
F_290 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_291 ( struct V_1 * V_58 )
{
#ifdef F_73
unsigned long V_570 ;
#endif
int V_60 ;
F_80 ( V_571 , F_53 ( V_572 ) ) ;
F_80 ( V_573 , F_53 ( V_574 ) ) ;
if ( F_17 () )
F_80 ( V_258 , F_53 ( V_257 ) ) ;
F_80 ( V_575 , - 1ull ) ;
F_79 ( V_576 ,
V_24 . V_51 ) ;
F_79 ( V_468 , F_287 ( V_58 ) ) ;
if ( F_21 () ) {
F_79 ( V_577 ,
F_288 ( V_58 ) ) ;
}
if ( V_405 ) {
F_79 ( V_578 , V_405 ) ;
F_79 ( V_579 , V_580 ) ;
}
F_79 ( V_581 , 0 ) ;
F_79 ( V_582 , 0 ) ;
F_79 ( V_583 , 0 ) ;
F_78 ( V_179 , 0 ) ;
F_78 ( V_183 , 0 ) ;
F_282 () ;
#ifdef F_73
F_107 ( V_185 , V_570 ) ;
F_76 ( V_184 , V_570 ) ;
F_107 ( V_187 , V_570 ) ;
F_76 ( V_186 , V_570 ) ;
#else
F_76 ( V_184 , 0 ) ;
F_76 ( V_186 , 0 ) ;
#endif
F_79 ( V_584 , 0 ) ;
F_79 ( V_137 , 0 ) ;
F_80 ( V_585 , F_53 ( V_58 -> V_123 . V_135 ) ) ;
F_79 ( V_136 , 0 ) ;
F_80 ( V_586 , F_53 ( V_58 -> V_123 . V_134 ) ) ;
if ( V_24 . V_343 & V_286 ) {
T_2 V_587 , V_588 ;
T_5 V_589 ;
F_166 ( V_342 , V_587 , V_588 ) ;
V_589 = V_587 | ( ( T_5 ) V_588 << 32 ) ;
F_80 ( V_344 , V_589 ) ;
V_58 -> V_3 . V_95 . V_345 = V_589 ;
}
for ( V_60 = 0 ; V_60 < V_590 ; ++ V_60 ) {
T_2 V_64 = V_62 [ V_60 ] ;
T_2 V_591 , V_592 ;
int V_593 = V_58 -> V_61 ;
if ( F_292 ( V_64 , & V_591 , & V_592 ) < 0 )
continue;
if ( F_293 ( V_64 , V_591 , V_592 ) < 0 )
continue;
V_58 -> V_63 [ V_593 ] . V_64 = V_60 ;
V_58 -> V_63 [ V_593 ] . V_164 = 0 ;
V_58 -> V_63 [ V_593 ] . V_89 = - 1ull ;
++ V_58 -> V_61 ;
}
F_79 ( V_122 , V_24 . V_392 ) ;
F_79 ( V_121 , V_24 . V_343 ) ;
F_76 ( V_209 , ~ 0UL ) ;
F_286 ( V_58 ) ;
F_178 ( & V_58 -> V_3 , 0 ) ;
return 0 ;
}
static int F_294 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_5 V_59 ;
int V_93 ;
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_351 ) | ( 1 << V_348 ) ) ;
V_58 -> V_115 . V_116 = 0 ;
V_58 -> V_594 = 0 ;
V_58 -> V_3 . V_95 . V_349 [ V_595 ] = F_295 () ;
F_296 ( & V_58 -> V_3 , 0 ) ;
V_59 = 0xfee00000 | V_596 ;
if ( F_297 ( & V_58 -> V_3 ) )
V_59 |= V_597 ;
F_298 ( & V_58 -> V_3 , V_59 ) ;
V_93 = F_299 ( & V_58 -> V_3 ) ;
if ( V_93 != 0 )
goto V_521;
F_83 ( V_58 ) ;
F_269 ( V_499 ) ;
if ( F_297 ( & V_58 -> V_3 ) ) {
F_78 ( V_432 , 0xf000 ) ;
F_76 ( V_448 , 0x000f0000 ) ;
} else {
F_78 ( V_432 , V_58 -> V_3 . V_95 . V_598 << 8 ) ;
F_76 ( V_448 , V_58 -> V_3 . V_95 . V_598 << 12 ) ;
}
F_269 ( V_426 ) ;
F_269 ( V_424 ) ;
F_269 ( V_429 ) ;
F_269 ( V_428 ) ;
F_269 ( V_514 ) ;
F_78 ( V_416 , 0 ) ;
F_76 ( V_417 , 0 ) ;
F_79 ( V_418 , 0xffff ) ;
F_79 ( V_419 , 0x008b ) ;
F_78 ( V_599 , 0 ) ;
F_76 ( V_600 , 0 ) ;
F_79 ( V_601 , 0xffff ) ;
F_79 ( V_602 , 0x00082 ) ;
F_79 ( V_338 , 0 ) ;
F_76 ( V_341 , 0 ) ;
F_76 ( V_340 , 0 ) ;
F_76 ( V_220 , 0x02 ) ;
if ( F_297 ( & V_58 -> V_3 ) )
F_144 ( V_3 , 0xfff0 ) ;
else
F_144 ( V_3 , 0 ) ;
F_300 ( V_3 , V_348 , 0 ) ;
F_76 ( V_357 , 0x400 ) ;
F_76 ( V_506 , 0 ) ;
F_79 ( V_505 , 0xffff ) ;
F_76 ( V_504 , 0 ) ;
F_79 ( V_503 , 0xffff ) ;
F_79 ( V_603 , V_604 ) ;
F_79 ( V_226 , 0 ) ;
F_79 ( V_605 , 0 ) ;
F_80 ( V_606 , 0 ) ;
F_152 ( V_58 ) ;
F_79 ( V_245 , 0 ) ;
if ( F_18 () ) {
F_80 ( V_607 , 0 ) ;
if ( F_19 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_607 ,
F_53 ( V_58 -> V_3 . V_95 . V_608 -> V_349 ) ) ;
F_79 ( V_609 , 0 ) ;
}
if ( F_38 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_610 ,
F_301 ( V_58 -> V_3 . V_12 -> V_95 . V_538 ) ) ;
if ( V_58 -> V_42 != 0 )
F_78 ( V_611 , V_58 -> V_42 ) ;
V_58 -> V_3 . V_95 . V_203 = V_612 | V_613 | V_614 ;
V_3 -> V_442 = F_222 ( & V_3 -> V_12 -> V_441 ) ;
F_239 ( & V_58 -> V_3 , F_302 ( V_3 ) ) ;
F_220 ( & V_3 -> V_12 -> V_441 , V_3 -> V_442 ) ;
F_237 ( & V_58 -> V_3 , 0 ) ;
F_224 ( & V_58 -> V_3 , 0 ) ;
F_129 ( & V_58 -> V_3 ) ;
F_89 ( & V_58 -> V_3 ) ;
F_65 ( V_58 ) ;
V_93 = 0 ;
V_58 -> V_415 = 0 ;
V_521:
return V_93 ;
}
static bool F_303 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_57 &
V_278 ;
}
static void F_304 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( F_90 ( V_3 ) && F_303 ( V_3 ) ) {
F_123 ( V_615 , V_3 ) ;
return;
}
V_55 = F_71 ( V_468 ) ;
V_55 |= V_291 ;
F_79 ( V_468 , V_55 ) ;
}
static void F_305 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( ! F_41 () ) {
F_304 ( V_3 ) ;
return;
}
if ( F_71 ( V_226 ) & V_227 ) {
F_304 ( V_3 ) ;
return;
}
V_55 = F_71 ( V_468 ) ;
V_55 |= V_616 ;
F_79 ( V_468 , V_55 ) ;
}
static void F_306 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_15 V_617 ;
int V_618 = V_3 -> V_95 . V_619 . V_133 ;
F_307 ( V_618 ) ;
++ V_3 -> V_192 . V_620 ;
if ( V_58 -> V_115 . V_116 ) {
int V_239 = 0 ;
if ( V_3 -> V_95 . V_619 . V_621 )
V_239 = V_3 -> V_95 . V_240 ;
if ( F_149 ( V_3 , V_618 , V_239 ) != V_241 )
F_123 ( V_242 , V_3 ) ;
return;
}
V_617 = V_618 | V_17 ;
if ( V_3 -> V_95 . V_619 . V_621 ) {
V_617 |= V_622 ;
F_79 ( V_243 ,
V_58 -> V_3 . V_95 . V_240 ) ;
} else
V_617 |= V_22 ;
F_79 ( V_245 , V_617 ) ;
}
static void F_308 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) )
return;
if ( ! F_41 () ) {
V_58 -> V_594 = 1 ;
V_58 -> V_623 = 0 ;
}
++ V_3 -> V_192 . V_624 ;
V_58 -> V_625 = false ;
if ( V_58 -> V_115 . V_116 ) {
if ( F_149 ( V_3 , V_626 , 0 ) != V_241 )
F_123 ( V_242 , V_3 ) ;
return;
}
F_79 ( V_245 ,
V_627 | V_17 | V_626 ) ;
}
static int F_309 ( struct V_2 * V_3 )
{
if ( ! F_41 () && F_1 ( V_3 ) -> V_594 )
return 0 ;
return ! ( F_71 ( V_226 ) &
( V_229 | V_227
| V_628 ) ) ;
}
static bool F_310 ( struct V_2 * V_3 )
{
if ( ! F_41 () )
return F_1 ( V_3 ) -> V_594 ;
if ( F_1 ( V_3 ) -> V_625 )
return false ;
return F_71 ( V_226 ) & V_628 ;
}
static void F_311 ( struct V_2 * V_3 , bool V_629 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_41 () ) {
if ( V_58 -> V_594 != V_629 ) {
V_58 -> V_594 = V_629 ;
V_58 -> V_623 = 0 ;
}
} else {
V_58 -> V_625 = ! V_629 ;
if ( V_629 )
F_82 ( V_226 ,
V_628 ) ;
else
F_81 ( V_226 ,
V_628 ) ;
}
}
static int F_312 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) && F_303 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_630 ||
( V_7 -> V_631 &
V_632 ) )
return 0 ;
F_146 ( V_3 ) ;
V_7 -> V_633 = V_634 ;
V_7 -> V_635 = 0 ;
}
return ( F_69 ( V_220 ) & V_636 ) &&
! ( F_71 ( V_226 ) &
( V_227 | V_229 ) ) ;
}
static int F_221 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_93 ;
struct V_535 V_637 = {
. V_438 = V_638 ,
. V_540 = V_11 ,
. V_541 = V_388 * 3 ,
. V_414 = 0 ,
} ;
V_93 = F_313 ( V_12 , & V_637 , 0 ) ;
if ( V_93 )
return V_93 ;
V_12 -> V_95 . V_434 = V_11 ;
if ( ! F_264 ( V_12 ) )
return - V_399 ;
return 0 ;
}
static int F_314 ( struct V_2 * V_3 ,
int V_639 , T_2 V_640 )
{
if ( ( ( V_639 == V_314 ) || ( V_639 == V_641 ) ) && V_640 == 0 )
if ( F_315 ( V_3 , 0 ) == V_241 )
return 1 ;
switch ( V_639 ) {
case V_110 :
if ( V_3 -> V_111 &
( V_642 | V_356 ) )
return 0 ;
F_316 ( V_3 , V_639 ) ;
return 1 ;
case V_114 :
F_1 ( V_3 ) -> V_3 . V_95 . V_240 =
F_71 ( V_233 ) ;
if ( V_3 -> V_111 & V_113 )
return 0 ;
case V_643 :
case V_644 :
case V_645 :
case V_21 :
case V_646 :
case V_641 :
case V_314 :
case V_647 :
F_316 ( V_3 , V_639 ) ;
return 1 ;
}
return 0 ;
}
static void F_317 ( void )
{
#if F_318 ( V_648 ) && F_318 ( F_73 )
struct V_649 V_349 = {
. V_507 = 3 ,
. V_414 = V_636 ,
} ;
F_319 ( & V_349 , 0 ) ;
#endif
}
static int F_320 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_321 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_650 * V_650 = V_3 -> V_651 ;
T_2 V_14 , V_652 , V_235 ;
unsigned long V_653 , V_232 , V_654 ;
T_2 V_655 ;
enum V_656 V_657 ;
V_655 = V_58 -> V_658 ;
V_14 = V_58 -> V_659 ;
if ( F_16 ( V_14 ) )
return F_320 ( V_3 ) ;
if ( ( V_655 & V_632 ) &&
! F_12 ( V_14 ) ) {
V_3 -> V_651 -> V_660 = V_661 ;
V_3 -> V_651 -> V_662 . V_663 = V_664 ;
V_3 -> V_651 -> V_662 . V_665 = 2 ;
V_3 -> V_651 -> V_662 . V_164 [ 0 ] = V_655 ;
V_3 -> V_651 -> V_662 . V_164 [ 1 ] = V_14 ;
return 0 ;
}
if ( ( V_14 & V_15 ) == V_627 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_129 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_657 = F_315 ( V_3 , V_666 ) ;
if ( V_657 != V_241 )
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
V_235 = 0 ;
if ( V_14 & V_238 )
V_235 = F_71 ( V_667 ) ;
if ( F_12 ( V_14 ) ) {
F_322 ( V_84 ) ;
V_653 = F_69 ( V_668 ) ;
F_323 ( V_653 , V_235 ) ;
if ( F_324 ( V_3 ) )
F_325 ( V_3 , V_653 ) ;
return F_326 ( V_3 , V_653 , V_235 , NULL , 0 ) ;
}
if ( V_58 -> V_115 . V_116 &&
F_314 ( V_3 , V_14 & V_16 ,
V_235 ) ) {
if ( V_3 -> V_95 . V_669 ) {
V_3 -> V_95 . V_669 = 0 ;
return F_327 ( V_3 ) ;
}
return 1 ;
}
V_652 = V_14 & V_16 ;
switch ( V_652 ) {
case V_110 :
V_654 = F_69 ( V_668 ) ;
if ( ! ( V_3 -> V_111 &
( V_642 | V_356 ) ) ) {
V_3 -> V_95 . V_654 = V_654 | V_670 ;
F_316 ( V_3 , V_110 ) ;
return 1 ;
}
V_650 -> V_671 . V_95 . V_654 = V_654 | V_670 ;
V_650 -> V_671 . V_95 . V_359 = F_69 ( V_357 ) ;
case V_114 :
V_58 -> V_3 . V_95 . V_240 =
F_71 ( V_233 ) ;
V_650 -> V_660 = V_672 ;
V_232 = F_143 ( V_3 ) ;
V_650 -> V_671 . V_95 . V_673 = F_69 ( V_448 ) + V_232 ;
V_650 -> V_671 . V_95 . V_674 = V_652 ;
break;
default:
V_650 -> V_660 = V_675 ;
V_650 -> V_676 . V_674 = V_652 ;
V_650 -> V_676 . V_235 = V_235 ;
break;
}
return 0 ;
}
static int F_328 ( struct V_2 * V_3 )
{
++ V_3 -> V_192 . V_677 ;
return 1 ;
}
static int F_329 ( struct V_2 * V_3 )
{
V_3 -> V_651 -> V_660 = V_678 ;
return 0 ;
}
static int F_330 ( struct V_2 * V_3 )
{
unsigned long V_679 ;
int V_389 , V_680 , string ;
unsigned V_681 ;
V_679 = F_69 ( V_668 ) ;
string = ( V_679 & 16 ) != 0 ;
V_680 = ( V_679 & 8 ) != 0 ;
++ V_3 -> V_192 . V_682 ;
if ( string || V_680 )
return F_315 ( V_3 , 0 ) == V_241 ;
V_681 = V_679 >> 16 ;
V_389 = ( V_679 & 7 ) + 1 ;
F_142 ( V_3 ) ;
return F_331 ( V_3 , V_389 , V_681 ) ;
}
static void
F_332 ( struct V_2 * V_3 , unsigned char * V_683 )
{
V_683 [ 0 ] = 0x0f ;
V_683 [ 1 ] = 0x01 ;
V_683 [ 2 ] = 0xc1 ;
}
static int F_333 ( struct V_2 * V_3 , unsigned long V_684 )
{
if ( F_1 ( V_3 ) -> V_8 . V_485 &&
( ( V_684 & F_171 ) != F_171 ) )
return 1 ;
if ( F_90 ( V_3 ) ) {
if ( F_334 ( V_3 , ( V_684 & V_3 -> V_95 . V_207 ) |
( V_3 -> V_95 . V_203 & ~ V_3 -> V_95 . V_207 ) ) )
return 1 ;
F_76 ( V_216 , V_684 ) ;
return 0 ;
} else
return F_334 ( V_3 , V_684 ) ;
}
static int F_335 ( struct V_2 * V_3 , unsigned long V_684 )
{
if ( F_90 ( V_3 ) ) {
if ( F_336 ( V_3 , ( V_684 & V_3 -> V_95 . V_458 ) |
( V_3 -> V_95 . V_459 & ~ V_3 -> V_95 . V_458 ) ) )
return 1 ;
F_76 ( V_422 , V_684 ) ;
return 0 ;
} else
return F_336 ( V_3 , V_684 ) ;
}
static void F_337 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) ) {
F_76 ( V_216 ,
F_69 ( V_216 ) & ~ V_205 ) ;
V_3 -> V_95 . V_203 &= ~ V_205 ;
} else
F_239 ( V_3 , F_130 ( V_3 , ~ V_205 ) ) ;
}
static int F_338 ( struct V_2 * V_3 )
{
unsigned long V_679 , V_684 ;
int V_685 ;
int V_347 ;
int V_686 ;
V_679 = F_69 ( V_668 ) ;
V_685 = V_679 & 15 ;
V_347 = ( V_679 >> 8 ) & 15 ;
switch ( ( V_679 >> 4 ) & 3 ) {
case 0 :
V_684 = F_339 ( V_3 , V_347 ) ;
F_340 ( V_685 , V_684 ) ;
switch ( V_685 ) {
case 0 :
V_686 = F_333 ( V_3 , V_684 ) ;
F_341 ( V_3 , V_686 ) ;
return 1 ;
case 3 :
V_686 = F_342 ( V_3 , V_684 ) ;
F_341 ( V_3 , V_686 ) ;
return 1 ;
case 4 :
V_686 = F_335 ( V_3 , V_684 ) ;
F_341 ( V_3 , V_686 ) ;
return 1 ;
case 8 : {
T_6 V_687 = F_343 ( V_3 ) ;
T_6 V_688 = F_339 ( V_3 , V_347 ) ;
V_686 = F_296 ( V_3 , V_688 ) ;
F_341 ( V_3 , V_686 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_687 <= V_688 )
return 1 ;
V_3 -> V_651 -> V_660 = V_689 ;
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
switch ( V_685 ) {
case 3 :
V_684 = F_241 ( V_3 ) ;
F_300 ( V_3 , V_347 , V_684 ) ;
F_344 ( V_685 , V_684 ) ;
F_142 ( V_3 ) ;
return 1 ;
case 8 :
V_684 = F_343 ( V_3 ) ;
F_300 ( V_3 , V_347 , V_684 ) ;
F_344 ( V_685 , V_684 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_684 = ( V_679 >> V_690 ) & 0x0f ;
F_340 ( 0 , ( F_302 ( V_3 ) & ~ 0xful ) | V_684 ) ;
F_345 ( V_3 , V_684 ) ;
F_142 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_651 -> V_660 = 0 ;
F_346 ( V_3 , L_19 ,
( int ) ( V_679 >> 4 ) & 3 , V_685 ) ;
return 0 ;
}
static int F_347 ( struct V_2 * V_3 )
{
unsigned long V_679 ;
int V_691 , V_347 ;
if ( ! F_348 ( V_3 , 0 ) )
return 1 ;
V_691 = F_69 ( V_357 ) ;
if ( V_691 & V_692 ) {
if ( V_3 -> V_111 & V_356 ) {
V_3 -> V_651 -> V_671 . V_95 . V_654 = V_3 -> V_95 . V_654 ;
V_3 -> V_651 -> V_671 . V_95 . V_359 = V_691 ;
V_3 -> V_651 -> V_671 . V_95 . V_673 =
F_69 ( V_448 ) +
F_69 ( V_352 ) ;
V_3 -> V_651 -> V_671 . V_95 . V_674 = V_110 ;
V_3 -> V_651 -> V_660 = V_672 ;
return 0 ;
} else {
V_3 -> V_95 . V_359 &= ~ V_692 ;
V_3 -> V_95 . V_654 |= V_693 ;
F_76 ( V_357 , V_3 -> V_95 . V_359 ) ;
F_316 ( V_3 , V_110 ) ;
return 1 ;
}
}
V_679 = F_69 ( V_668 ) ;
V_691 = V_679 & V_694 ;
V_347 = F_349 ( V_679 ) ;
if ( V_679 & V_695 ) {
unsigned long V_684 ;
if ( ! F_350 ( V_3 , V_691 , & V_684 ) )
F_300 ( V_3 , V_347 , V_684 ) ;
} else
F_351 ( V_3 , V_691 , V_3 -> V_95 . V_349 [ V_347 ] ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static void F_352 ( struct V_2 * V_3 , unsigned long V_684 )
{
F_76 ( V_357 , V_684 ) ;
}
static int F_353 ( struct V_2 * V_3 )
{
F_354 ( V_3 ) ;
return 1 ;
}
static int F_355 ( struct V_2 * V_3 )
{
T_2 V_274 = V_3 -> V_95 . V_349 [ V_696 ] ;
T_5 V_164 ;
if ( F_174 ( V_3 , V_274 , & V_164 ) ) {
F_356 ( V_274 ) ;
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_358 ( V_274 , V_164 ) ;
V_3 -> V_95 . V_349 [ V_697 ] = V_164 & - 1u ;
V_3 -> V_95 . V_349 [ V_595 ] = ( V_164 >> 32 ) & - 1u ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_359 ( struct V_2 * V_3 )
{
T_2 V_274 = V_3 -> V_95 . V_349 [ V_696 ] ;
T_5 V_164 = ( V_3 -> V_95 . V_349 [ V_697 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_95 . V_349 [ V_595 ] & - 1u ) << 32 ) ;
if ( F_176 ( V_3 , V_274 , V_164 ) != 0 ) {
F_360 ( V_274 , V_164 ) ;
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_361 ( V_274 , V_164 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_362 ( struct V_2 * V_3 )
{
F_123 ( V_698 , V_3 ) ;
return 1 ;
}
static int F_363 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_468 ) ;
V_55 &= ~ V_291 ;
F_79 ( V_468 , V_55 ) ;
F_123 ( V_698 , V_3 ) ;
++ V_3 -> V_192 . V_699 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_651 -> V_700 &&
! F_364 ( V_3 ) ) {
V_3 -> V_651 -> V_660 = V_701 ;
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
return F_315 ( V_3 , 0 ) == V_241 ;
}
static int F_369 ( struct V_2 * V_3 )
{
unsigned long V_679 = F_69 ( V_668 ) ;
F_370 ( V_3 , V_679 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_371 ( struct V_2 * V_3 )
{
int V_686 ;
V_686 = F_372 ( V_3 ) ;
F_341 ( V_3 , V_686 ) ;
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
T_5 V_702 = F_376 ( V_3 ) ;
T_2 V_64 = F_339 ( V_3 , V_696 ) ;
if ( F_377 ( V_3 , V_64 , V_702 ) == 0 )
F_142 ( V_3 ) ;
return 1 ;
}
static int F_378 ( struct V_2 * V_3 )
{
if ( F_268 ( V_703 ) ) {
unsigned long V_679 = F_69 ( V_668 ) ;
int V_704 , V_268 ;
V_704 = V_679 & V_705 ;
V_268 = V_679 & V_706 ;
if ( ( V_704 == V_707 ) &&
( V_268 == V_708 ) ) {
F_379 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
}
return F_315 ( V_3 , 0 ) == V_241 ;
}
static int F_380 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_679 ;
bool V_234 = false ;
T_2 V_235 = 0 ;
T_3 V_709 ;
int V_710 , type , V_711 , V_712 ;
V_711 = ( V_58 -> V_658 & V_632 ) ;
V_712 = ( V_58 -> V_658 & V_713 ) ;
type = ( V_58 -> V_658 & V_714 ) ;
V_679 = F_69 ( V_668 ) ;
V_710 = ( T_2 ) V_679 >> 30 ;
if ( V_710 == V_715 && V_711 ) {
switch ( type ) {
case V_627 :
V_3 -> V_95 . V_716 = false ;
F_311 ( V_3 , true ) ;
break;
case V_22 :
case V_622 :
F_381 ( V_3 ) ;
break;
case V_18 :
if ( V_58 -> V_658 &
V_717 ) {
V_234 = true ;
V_235 =
F_71 ( V_718 ) ;
}
case V_244 :
F_382 ( V_3 ) ;
break;
default:
break;
}
}
V_709 = V_679 ;
if ( ! V_711 || ( type != V_18 &&
type != V_22 &&
type != V_627 ) )
F_142 ( V_3 ) ;
if ( F_383 ( V_3 , V_709 ,
type == V_622 ? V_712 : - 1 , V_710 ,
V_234 , V_235 ) == V_719 ) {
V_3 -> V_651 -> V_660 = V_661 ;
V_3 -> V_651 -> V_662 . V_663 = V_720 ;
V_3 -> V_651 -> V_662 . V_665 = 0 ;
return 0 ;
}
F_76 ( V_357 , F_69 ( V_357 ) & ~ 55 ) ;
return 1 ;
}
static int F_384 ( struct V_2 * V_3 )
{
unsigned long V_679 ;
T_1 V_70 ;
int V_721 ;
V_679 = F_69 ( V_668 ) ;
if ( V_679 & ( 1 << 6 ) ) {
F_54 ( V_74 L_20 ) ;
return - V_333 ;
}
V_721 = ( V_679 >> 7 ) & 0x3 ;
if ( V_721 != 0x3 && V_721 != 0x1 && V_721 != 0 ) {
F_54 ( V_74 L_21 ) ;
F_54 ( V_74 L_22 ,
( long unsigned int ) F_72 ( V_722 ) ,
F_69 ( V_723 ) ) ;
F_54 ( V_74 L_23 ,
( long unsigned int ) V_679 ) ;
V_3 -> V_651 -> V_660 = V_724 ;
V_3 -> V_651 -> V_725 . V_726 = V_727 ;
return 0 ;
}
V_70 = F_72 ( V_722 ) ;
F_323 ( V_70 , V_679 ) ;
return F_326 ( V_3 , V_70 , V_679 & 0x3 , NULL , 0 ) ;
}
static T_5 F_385 ( T_5 V_728 , int V_729 )
{
int V_60 ;
T_5 V_89 = 0 ;
for ( V_60 = 51 ; V_60 > V_393 . V_730 ; V_60 -- )
V_89 |= ( 1ULL << V_60 ) ;
if ( V_729 > 2 )
V_89 |= 0xf8 ;
else if ( V_729 == 2 ) {
if ( V_728 & ( 1ULL << 7 ) )
V_89 |= 0x1ff000 ;
else
V_89 |= 0x78 ;
}
return V_89 ;
}
static void F_386 ( struct V_2 * V_3 , T_5 V_728 ,
int V_729 )
{
F_54 ( V_74 L_24 , V_452 , V_728 , V_729 ) ;
F_387 ( ( V_728 & 0x7 ) == 0x2 ) ;
F_387 ( ( V_728 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_387 ( ( V_728 & 0x7 ) == 0x4 ) ;
if ( ( V_728 & 0x7 ) ) {
T_5 V_731 = V_728 & F_385 ( V_728 , V_729 ) ;
if ( V_731 != 0 ) {
F_54 ( V_74 L_25 ,
V_452 , V_731 ) ;
F_387 ( 1 ) ;
}
if ( V_729 == 1 || ( V_729 == 2 && ( V_728 & ( 1ULL << 7 ) ) ) ) {
T_5 V_732 = ( V_728 & 0x38 ) >> 3 ;
if ( V_732 == 2 || V_732 == 3 ||
V_732 == 7 ) {
F_54 ( V_74 L_26 ,
V_452 , V_732 ) ;
F_387 ( 1 ) ;
}
}
}
}
static int F_388 ( struct V_2 * V_3 )
{
T_5 V_733 [ 4 ] ;
int V_734 , V_60 , V_93 ;
T_1 V_70 ;
V_70 = F_72 ( V_722 ) ;
V_93 = F_389 ( V_3 , V_70 , true ) ;
if ( F_268 ( V_93 == 1 ) )
return F_390 ( V_3 , V_70 , 0 , NULL , 0 ) ==
V_241 ;
if ( F_77 ( ! V_93 ) )
return 1 ;
F_54 ( V_74 L_27 ) ;
F_54 ( V_74 L_28 , V_70 ) ;
V_734 = F_391 ( V_3 , V_70 , V_733 ) ;
for ( V_60 = V_735 ; V_60 > V_735 - V_734 ; -- V_60 )
F_386 ( V_3 , V_733 [ V_60 - 1 ] , V_60 ) ;
V_3 -> V_651 -> V_660 = V_724 ;
V_3 -> V_651 -> V_725 . V_726 = V_736 ;
return 0 ;
}
static int F_392 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_468 ) ;
V_55 &= ~ V_616 ;
F_79 ( V_468 , V_55 ) ;
++ V_3 -> V_192 . V_737 ;
F_123 ( V_698 , V_3 ) ;
return 1 ;
}
static int F_393 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
enum V_656 V_686 = V_241 ;
int V_93 = 1 ;
T_2 V_738 ;
bool V_739 ;
V_738 = F_71 ( V_468 ) ;
V_739 = V_738 & V_291 ;
while ( ! F_263 ( V_3 ) ) {
if ( V_739
&& ( F_247 ( & V_58 -> V_3 ) & V_636 ) )
return F_363 ( & V_58 -> V_3 ) ;
V_686 = F_315 ( V_3 , 0 ) ;
if ( V_686 == V_740 ) {
V_93 = 0 ;
goto V_521;
}
if ( V_686 != V_241 )
return 0 ;
if ( F_394 ( V_741 ) )
goto V_521;
if ( F_395 () )
F_396 () ;
}
V_58 -> V_415 = 0 ;
V_521:
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
struct V_742 * V_743 ;
F_401 (item, &vmx->nested.vmcs02_pool, list)
if ( V_743 -> V_744 == V_58 -> V_8 . V_745 ) {
F_402 ( & V_743 -> V_746 , & V_58 -> V_8 . V_747 ) ;
return & V_743 -> V_748 ;
}
if ( V_58 -> V_8 . V_749 >= F_403 ( V_750 , 1 ) ) {
V_743 = F_404 ( V_58 -> V_8 . V_747 . V_751 ,
struct V_742 , V_746 ) ;
V_743 -> V_744 = V_58 -> V_8 . V_745 ;
F_402 ( & V_743 -> V_746 , & V_58 -> V_8 . V_747 ) ;
return & V_743 -> V_748 ;
}
V_743 = (struct V_742 * )
F_405 ( sizeof( struct V_742 ) , V_398 ) ;
if ( ! V_743 )
return NULL ;
V_743 -> V_748 . V_72 = F_202 () ;
if ( ! V_743 -> V_748 . V_72 ) {
F_406 ( V_743 ) ;
return NULL ;
}
F_55 ( & V_743 -> V_748 ) ;
V_743 -> V_744 = V_58 -> V_8 . V_745 ;
F_125 ( & ( V_743 -> V_746 ) , & ( V_58 -> V_8 . V_747 ) ) ;
V_58 -> V_8 . V_749 ++ ;
return & V_743 -> V_748 ;
}
static void F_407 ( struct V_1 * V_58 , T_1 V_744 )
{
struct V_742 * V_743 ;
F_401 (item, &vmx->nested.vmcs02_pool, list)
if ( V_743 -> V_744 == V_744 ) {
F_205 ( & V_743 -> V_748 ) ;
F_60 ( & V_743 -> V_746 ) ;
F_406 ( V_743 ) ;
V_58 -> V_8 . V_749 -- ;
return;
}
}
static void F_408 ( struct V_1 * V_58 )
{
struct V_742 * V_743 , * V_368 ;
F_192 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_58 -> V_75 != & V_743 -> V_748 )
F_205 ( & V_743 -> V_748 ) ;
F_60 ( & V_743 -> V_746 ) ;
F_406 ( V_743 ) ;
}
V_58 -> V_8 . V_749 = 0 ;
if ( V_58 -> V_75 != & V_58 -> V_752 )
F_205 ( & V_58 -> V_752 ) ;
}
static int F_409 ( struct V_2 * V_3 )
{
struct V_488 V_507 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_410 ( V_3 , V_366 ) ||
! F_130 ( V_3 , V_474 ) ||
( F_135 ( V_3 ) & V_224 ) ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
F_242 ( V_3 , & V_507 , V_499 ) ;
if ( F_108 ( V_3 ) && ! V_507 . V_495 ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_248 ( V_3 ) ) {
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_188 ( & ( V_58 -> V_8 . V_747 ) ) ;
V_58 -> V_8 . V_749 = 0 ;
V_58 -> V_8 . V_485 = true ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_411 ( struct V_2 * V_3 )
{
struct V_488 V_507 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! V_58 -> V_8 . V_485 ) {
F_316 ( V_3 , V_21 ) ;
return 0 ;
}
F_242 ( V_3 , & V_507 , V_499 ) ;
if ( ( F_135 ( V_3 ) & V_224 ) ||
( F_108 ( V_3 ) && ! V_507 . V_495 ) ) {
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
if ( ! V_58 -> V_8 . V_485 )
return;
V_58 -> V_8 . V_485 = false ;
if ( V_58 -> V_8 . V_745 != - 1ull ) {
F_413 ( V_58 -> V_8 . V_753 ) ;
F_9 ( V_58 -> V_8 . V_753 ) ;
V_58 -> V_8 . V_745 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
if ( V_58 -> V_8 . V_538 ) {
F_9 ( V_58 -> V_8 . V_538 ) ;
V_58 -> V_8 . V_538 = 0 ;
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
unsigned long V_679 ,
T_2 V_754 , T_4 * V_93 )
{
int V_755 = V_754 & 3 ;
int V_756 = ( V_754 >> 7 ) & 7 ;
bool V_757 = V_754 & ( 1u << 10 ) ;
int V_758 = ( V_754 >> 15 ) & 7 ;
int V_759 = ( V_754 >> 18 ) & 0xf ;
bool V_760 = ! ( V_754 & ( 1u << 22 ) ) ;
int V_761 = ( V_754 >> 23 ) & 0xf ;
bool V_762 = ! ( V_754 & ( 1u << 27 ) ) ;
if ( V_757 ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
* V_93 = F_244 ( V_3 , V_758 ) ;
if ( V_762 )
* V_93 += F_339 ( V_3 , V_761 ) ;
if ( V_760 )
* V_93 += F_339 ( V_3 , V_759 ) << V_755 ;
* V_93 += V_679 ;
if ( V_756 == 1 )
* V_93 &= 0xffffffff ;
return 0 ;
}
static void F_416 ( struct V_2 * V_3 )
{
F_138 ( V_3 , F_135 ( V_3 )
& ~ ( V_763 | V_764 | V_765 |
V_766 | V_767 | V_768 ) ) ;
}
static void F_417 ( struct V_2 * V_3 )
{
F_138 ( V_3 , ( F_135 ( V_3 )
& ~ ( V_764 | V_765 | V_766 |
V_767 | V_768 ) )
| V_763 ) ;
}
static void F_418 ( struct V_2 * V_3 ,
T_2 V_769 )
{
if ( F_1 ( V_3 ) -> V_8 . V_745 == - 1ull ) {
F_417 ( V_3 ) ;
return;
}
F_138 ( V_3 , ( F_135 ( V_3 )
& ~ ( V_763 | V_764 | V_765 |
V_767 | V_768 ) )
| V_766 ) ;
F_4 ( V_3 ) -> V_769 = V_769 ;
}
static int F_419 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_4 V_66 ;
T_1 V_744 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_770 V_771 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , F_69 ( V_668 ) ,
F_71 ( V_772 ) , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_773 , V_66 , & V_744 ,
sizeof( V_744 ) , & V_771 ) ) {
F_421 ( V_3 , & V_771 ) ;
return 1 ;
}
if ( ! F_422 ( V_744 , V_388 ) ) {
F_418 ( V_3 , V_774 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_744 == V_58 -> V_8 . V_745 ) {
F_413 ( V_58 -> V_8 . V_753 ) ;
F_9 ( V_58 -> V_8 . V_753 ) ;
V_58 -> V_8 . V_745 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_744 ) ;
if ( V_10 == NULL ) {
F_123 ( V_242 , V_3 ) ;
return 1 ;
}
V_7 = F_423 ( V_10 ) ;
V_7 -> V_775 = 0 ;
F_413 ( V_10 ) ;
F_9 ( V_10 ) ;
F_407 ( V_58 , V_744 ) ;
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
return V_776 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_428 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_429 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_93 )
{
short V_268 = F_3 ( V_4 ) ;
char * V_98 ;
if ( V_268 < 0 )
return 0 ;
V_98 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_268 ;
switch ( F_427 ( V_4 ) ) {
case V_777 :
* V_93 = * ( ( V_778 * ) V_98 ) ;
return 1 ;
case V_779 :
* V_93 = * ( ( T_3 * ) V_98 ) ;
return 1 ;
case V_776 :
* V_93 = * ( ( T_2 * ) V_98 ) ;
return 1 ;
case V_780 :
* V_93 = * ( ( T_5 * ) V_98 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_430 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_58 -> V_8 . V_745 == - 1ull ) {
F_417 ( V_3 ) ;
F_142 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_431 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_781 ;
unsigned long V_679 = F_69 ( V_668 ) ;
T_2 V_754 = F_71 ( V_772 ) ;
T_4 V_66 = 0 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
V_4 = F_339 ( V_3 , ( ( ( V_754 ) >> 28 ) & 0xf ) ) ;
if ( ! F_429 ( V_3 , V_4 , & V_781 ) ) {
F_418 ( V_3 , V_782 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_754 & ( 1u << 10 ) ) {
F_300 ( V_3 , ( ( ( V_754 ) >> 3 ) & 0xf ) ,
V_781 ) ;
} else {
if ( F_415 ( V_3 , V_679 ,
V_754 , & V_66 ) )
return 1 ;
F_432 ( & V_3 -> V_95 . V_773 , V_66 ,
& V_781 , ( F_108 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_433 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_66 ;
unsigned long V_679 = F_69 ( V_668 ) ;
T_2 V_754 = F_71 ( V_772 ) ;
char * V_98 ;
short V_268 ;
T_5 V_781 = 0 ;
struct V_770 V_771 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
if ( V_754 & ( 1u << 10 ) )
V_781 = F_339 ( V_3 ,
( ( ( V_754 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_415 ( V_3 , V_679 ,
V_754 , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_773 , V_66 ,
& V_781 , ( F_108 ( V_3 ) ? 8 : 4 ) , & V_771 ) ) {
F_421 ( V_3 , & V_771 ) ;
return 1 ;
}
}
V_4 = F_339 ( V_3 , ( ( ( V_754 ) >> 28 ) & 0xf ) ) ;
if ( F_428 ( V_4 ) ) {
F_418 ( V_3 ,
V_783 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_268 = F_3 ( V_4 ) ;
if ( V_268 < 0 ) {
F_418 ( V_3 , V_782 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_98 = ( ( char * ) F_4 ( V_3 ) ) + V_268 ;
switch ( F_427 ( V_4 ) ) {
case V_779 :
* ( T_3 * ) V_98 = V_781 ;
break;
case V_776 :
* ( T_2 * ) V_98 = V_781 ;
break;
case V_780 :
* ( T_5 * ) V_98 = V_781 ;
break;
case V_777 :
* ( V_778 * ) V_98 = V_781 ;
break;
default:
F_418 ( V_3 , V_782 ) ;
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
T_1 V_744 ;
struct V_770 V_771 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , F_69 ( V_668 ) ,
F_71 ( V_772 ) , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_773 , V_66 , & V_744 ,
sizeof( V_744 ) , & V_771 ) ) {
F_421 ( V_3 , & V_771 ) ;
return 1 ;
}
if ( ! F_422 ( V_744 , V_388 ) ) {
F_418 ( V_3 , V_784 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_745 != V_744 ) {
struct V_7 * V_785 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_744 ) ;
if ( V_10 == NULL ) {
F_417 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_785 = F_423 ( V_10 ) ;
if ( V_785 -> V_391 != V_316 ) {
F_413 ( V_10 ) ;
F_11 ( V_10 ) ;
F_418 ( V_3 ,
V_786 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_745 != - 1ull ) {
F_413 ( V_58 -> V_8 . V_753 ) ;
F_9 ( V_58 -> V_8 . V_753 ) ;
}
V_58 -> V_8 . V_745 = V_744 ;
V_58 -> V_8 . V_9 = V_785 ;
V_58 -> V_8 . V_753 = V_10 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_435 ( struct V_2 * V_3 )
{
unsigned long V_679 = F_69 ( V_668 ) ;
T_2 V_754 = F_71 ( V_772 ) ;
T_4 V_787 ;
struct V_770 V_771 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , V_679 ,
V_754 , & V_787 ) )
return 1 ;
if ( F_432 ( & V_3 -> V_95 . V_773 , V_787 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_745 ,
sizeof( T_5 ) , & V_771 ) ) {
F_421 ( V_3 , & V_771 ) ;
return 1 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static bool F_436 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_660 )
{
T_2 V_310 = V_3 -> V_95 . V_349 [ V_696 ] ;
T_1 V_788 ;
if ( ! F_44 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_788 = V_7 -> V_249 ;
if ( V_660 == V_789 )
V_788 += 2048 ;
if ( V_310 >= 0xc0000000 ) {
V_310 -= 0xc0000000 ;
V_788 += 1024 ;
}
if ( V_310 < 1024 * 8 ) {
unsigned char V_790 ;
F_437 ( V_3 -> V_12 , V_788 + V_310 / 8 , & V_790 , 1 ) ;
return 1 & ( V_790 >> ( V_310 & 7 ) ) ;
} else
return 1 ;
}
static bool F_438 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_679 = F_69 ( V_668 ) ;
int V_685 = V_679 & 15 ;
int V_347 = ( V_679 >> 8 ) & 15 ;
unsigned long V_684 = F_339 ( V_3 , V_347 ) ;
switch ( ( V_679 >> 4 ) & 3 ) {
case 0 :
switch ( V_685 ) {
case 0 :
if ( V_7 -> V_208 &
( V_684 ^ V_7 -> V_212 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_791 >= 1 &&
V_7 -> V_792 == V_684 ) ||
( V_7 -> V_791 >= 2 &&
V_7 -> V_793 == V_684 ) ||
( V_7 -> V_791 >= 3 &&
V_7 -> V_794 == V_684 ) ||
( V_7 -> V_791 >= 4 &&
V_7 -> V_795 == V_684 ) )
return 0 ;
if ( F_44 ( V_7 , V_295 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_214 &
( V_7 -> V_215 ^ V_684 ) )
return 1 ;
break;
case 8 :
if ( F_44 ( V_7 , V_297 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_208 & V_205 ) &&
( V_7 -> V_212 & V_205 ) )
return 1 ;
break;
case 1 :
switch ( V_685 ) {
case 3 :
if ( V_7 -> V_55 &
V_296 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_55 &
V_298 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_208 & 0xe &
( V_684 ^ V_7 -> V_212 ) )
return 1 ;
if ( ( V_7 -> V_208 & 0x1 ) &&
! ( V_7 -> V_212 & 0x1 ) &&
( V_684 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_439 ( struct V_2 * V_3 )
{
T_2 V_660 = F_71 ( V_796 ) ;
T_2 V_14 = F_71 ( V_797 ) ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_58 -> V_8 . V_630 )
return 0 ;
if ( F_77 ( V_58 -> V_798 ) ) {
F_440 ( L_29 , V_452 ,
F_71 ( V_88 ) ) ;
return 1 ;
}
switch ( V_660 ) {
case V_799 :
if ( ! F_47 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_84 ;
return V_7 -> V_118 &
( 1u << ( V_14 & V_16 ) ) ;
case V_634 :
return 0 ;
case V_800 :
return 1 ;
case V_801 :
case V_802 :
return 1 ;
case V_803 :
return 1 ;
case V_804 :
return 1 ;
case V_805 :
return F_44 ( V_7 , V_292 ) ;
case V_806 :
return 1 ;
case V_807 :
return F_44 ( V_7 , V_293 ) ;
case V_808 :
return F_44 ( V_7 , V_303 ) ;
case V_809 :
return F_44 ( V_7 , V_810 ) ;
case V_811 : case V_812 :
case V_813 : case V_814 :
case V_815 : case V_816 :
case V_817 : case V_818 :
case V_819 : case V_820 :
return 1 ;
case V_821 :
return F_438 ( V_3 , V_7 ) ;
case V_822 :
return F_44 ( V_7 , V_299 ) ;
case V_823 :
return 1 ;
case V_824 :
case V_789 :
return F_436 ( V_3 , V_7 , V_660 ) ;
case V_825 :
return 1 ;
case V_826 :
return F_44 ( V_7 , V_294 ) ;
case V_827 :
return F_44 ( V_7 , V_302 ) ;
case V_828 :
return F_44 ( V_7 , V_829 ) ||
F_45 ( V_7 ,
V_47 ) ;
case V_830 :
return 0 ;
case V_831 :
return 1 ;
case V_832 :
return F_45 ( V_7 ,
V_30 ) ;
case V_727 :
case V_736 :
return 0 ;
case V_833 :
return F_45 ( V_7 , V_53 ) ;
case V_834 :
return 1 ;
default:
return 1 ;
}
}
static void F_441 ( struct V_2 * V_3 , T_5 * V_835 , T_5 * V_836 )
{
* V_835 = F_69 ( V_668 ) ;
* V_836 = F_71 ( V_797 ) ;
}
static int F_442 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_660 = V_58 -> V_660 ;
T_2 V_837 = V_58 -> V_658 ;
if ( V_58 -> V_415 && V_423 )
return F_393 ( V_3 ) ;
if ( V_58 -> V_8 . V_630 )
F_123 ( V_698 , V_3 ) ;
if ( ! F_90 ( V_3 ) && ( V_660 == V_813 ||
V_660 == V_817 ) )
V_58 -> V_8 . V_630 = 1 ;
else
V_58 -> V_8 . V_630 = 0 ;
if ( F_90 ( V_3 ) && F_439 ( V_3 ) ) {
F_146 ( V_3 ) ;
return 1 ;
}
if ( V_660 & V_838 ) {
V_3 -> V_651 -> V_660 = V_839 ;
V_3 -> V_651 -> V_840 . V_841
= V_660 ;
return 0 ;
}
if ( F_77 ( V_58 -> V_798 ) ) {
V_3 -> V_651 -> V_660 = V_839 ;
V_3 -> V_651 -> V_840 . V_841
= F_71 ( V_88 ) ;
return 0 ;
}
if ( ( V_837 & V_632 ) &&
( V_660 != V_799 &&
V_660 != V_727 &&
V_660 != V_803 ) )
F_54 ( V_147 L_30
L_31 ,
V_452 , V_837 , V_660 ) ;
if ( F_77 ( ! F_41 () && V_58 -> V_594 &&
! ( F_90 ( V_3 ) && F_46 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_312 ( V_3 ) ) {
V_58 -> V_594 = 0 ;
} else if ( V_58 -> V_623 > 1000000000LL &&
V_3 -> V_95 . V_842 ) {
F_54 ( V_147 L_32
L_33 ,
V_452 , V_3 -> V_843 ) ;
V_58 -> V_594 = 0 ;
}
}
if ( V_660 < V_844
&& V_845 [ V_660 ] )
return V_845 [ V_660 ] ( V_3 ) ;
else {
V_3 -> V_651 -> V_660 = V_724 ;
V_3 -> V_651 -> V_725 . V_726 = V_660 ;
}
return 0 ;
}
static void V_404 ( struct V_2 * V_3 , int V_846 , int V_847 )
{
if ( V_847 == - 1 || V_846 < V_847 ) {
F_79 ( V_609 , 0 ) ;
return;
}
F_79 ( V_609 , V_847 ) ;
}
static void F_443 ( struct V_1 * V_58 )
{
T_2 V_659 ;
if ( ! ( V_58 -> V_660 == V_830
|| V_58 -> V_660 == V_799 ) )
return;
V_58 -> V_659 = F_71 ( V_797 ) ;
V_659 = V_58 -> V_659 ;
if ( F_16 ( V_659 ) )
F_317 () ;
if ( ( V_659 & V_15 ) == V_627 &&
( V_659 & V_17 ) ) {
F_444 ( & V_58 -> V_3 ) ;
asm("int $2");
F_445 ( & V_58 -> V_3 ) ;
}
}
static void F_446 ( struct V_1 * V_58 )
{
T_2 V_659 ;
bool V_848 ;
T_6 V_849 ;
bool V_850 ;
V_850 = V_58 -> V_658 & V_632 ;
if ( F_41 () ) {
if ( V_58 -> V_625 )
return;
V_659 = F_71 ( V_797 ) ;
V_848 = ( V_659 & V_851 ) != 0 ;
V_849 = V_659 & V_16 ;
if ( ( V_659 & V_17 ) && V_848 &&
V_849 != V_646 && ! V_850 )
F_82 ( V_226 ,
V_628 ) ;
else
V_58 -> V_625 =
! ( F_71 ( V_226 )
& V_628 ) ;
} else if ( F_77 ( V_58 -> V_594 ) )
V_58 -> V_623 +=
F_447 ( F_448 ( F_449 () , V_58 -> V_852 ) ) ;
}
static void F_450 ( struct V_1 * V_58 ,
T_2 V_658 ,
int V_853 ,
int V_854 )
{
T_6 V_849 ;
int type ;
bool V_850 ;
V_850 = V_658 & V_632 ;
V_58 -> V_3 . V_95 . V_716 = false ;
F_382 ( & V_58 -> V_3 ) ;
F_381 ( & V_58 -> V_3 ) ;
if ( ! V_850 )
return;
F_123 ( V_698 , & V_58 -> V_3 ) ;
V_849 = V_658 & V_713 ;
type = V_658 & V_714 ;
switch ( type ) {
case V_627 :
V_58 -> V_3 . V_95 . V_716 = true ;
F_311 ( & V_58 -> V_3 , false ) ;
break;
case V_244 :
V_58 -> V_3 . V_95 . V_240 =
F_71 ( V_853 ) ;
case V_18 :
if ( V_658 & V_717 ) {
T_2 V_686 = F_71 ( V_854 ) ;
F_170 ( & V_58 -> V_3 , V_849 , V_686 ) ;
} else
F_316 ( & V_58 -> V_3 , V_849 ) ;
break;
case V_622 :
V_58 -> V_3 . V_95 . V_240 =
F_71 ( V_853 ) ;
case V_22 :
F_451 ( & V_58 -> V_3 , V_849 ,
type == V_622 ) ;
break;
default:
break;
}
}
static void F_452 ( struct V_1 * V_58 )
{
if ( F_90 ( & V_58 -> V_3 ) )
return;
F_450 ( V_58 , V_58 -> V_658 ,
V_233 ,
V_718 ) ;
}
static void F_453 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) )
return;
F_450 ( F_1 ( V_3 ) ,
F_71 ( V_245 ) ,
V_243 ,
V_237 ) ;
F_79 ( V_245 , 0 ) ;
}
static void F_454 ( struct V_1 * V_58 )
{
int V_60 , V_855 ;
struct V_856 * V_857 ;
V_857 = F_455 ( & V_855 ) ;
if ( ! V_857 )
return;
for ( V_60 = 0 ; V_60 < V_855 ; V_60 ++ )
if ( V_857 [ V_60 ] . V_135 == V_857 [ V_60 ] . V_134 )
F_92 ( V_58 , V_857 [ V_60 ] . V_59 ) ;
else
F_94 ( V_58 , V_857 [ V_60 ] . V_59 , V_857 [ V_60 ] . V_134 ,
V_857 [ V_60 ] . V_135 ) ;
}
static void T_16 F_456 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) && ! V_58 -> V_8 . V_630 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_631 &
V_632 ) {
F_79 ( V_245 ,
V_7 -> V_631 ) ;
F_79 ( V_243 ,
V_7 -> V_858 ) ;
if ( V_7 -> V_631 &
V_717 )
F_79 ( V_237 ,
V_7 -> V_859 ) ;
}
}
if ( F_77 ( ! F_41 () && V_58 -> V_594 ) )
V_58 -> V_852 = F_449 () ;
if ( V_58 -> V_415 && V_423 )
return;
if ( F_136 ( V_348 , ( unsigned long * ) & V_3 -> V_95 . V_460 ) )
F_76 ( V_350 , V_3 -> V_95 . V_349 [ V_348 ] ) ;
if ( F_136 ( V_351 , ( unsigned long * ) & V_3 -> V_95 . V_460 ) )
F_76 ( V_352 , V_3 -> V_95 . V_349 [ V_351 ] ) ;
if ( V_3 -> V_111 & V_642 )
F_141 ( V_3 , 0 ) ;
F_454 ( V_58 ) ;
V_58 -> V_860 = V_58 -> V_75 -> V_77 ;
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
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_351 ) | ( 1 << V_348 )
| ( 1 << V_219 )
| ( 1 << V_222 )
| ( 1 << V_353 )
| ( 1 << V_97 )
| ( 1 << V_457 ) ) ;
V_3 -> V_95 . V_460 = 0 ;
V_58 -> V_658 = F_71 ( V_861 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_631 = V_58 -> V_658 ;
if ( V_58 -> V_658 & V_632 ) {
V_7 -> V_859 =
F_71 ( V_718 ) ;
V_7 -> V_858 =
F_71 ( V_233 ) ;
}
}
asm("mov %0, %%ds; mov %0, %%es" : : "r"(__USER_DS));
V_58 -> V_75 -> V_77 = 1 ;
V_58 -> V_660 = F_71 ( V_796 ) ;
F_457 ( V_58 -> V_660 , V_3 , V_862 ) ;
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
F_460 ( V_863 , V_58 ) ;
}
static struct V_2 * F_461 ( struct V_12 * V_12 , unsigned int V_864 )
{
int V_686 ;
struct V_1 * V_58 = F_462 ( V_863 , V_398 ) ;
int V_76 ;
if ( ! V_58 )
return F_463 ( - V_399 ) ;
F_275 ( V_58 ) ;
V_686 = F_464 ( & V_58 -> V_3 , V_12 , V_864 ) ;
if ( V_686 )
goto V_865;
V_58 -> V_63 = F_405 ( V_388 , V_398 ) ;
V_686 = - V_399 ;
if ( ! V_58 -> V_63 ) {
goto V_866;
}
V_58 -> V_75 = & V_58 -> V_752 ;
V_58 -> V_75 -> V_72 = F_202 () ;
if ( ! V_58 -> V_75 -> V_72 )
goto V_867;
if ( ! V_195 )
F_122 ( F_53 ( F_59 ( V_194 , F_58 () ) ) ) ;
F_55 ( V_58 -> V_75 ) ;
if ( ! V_195 )
F_128 () ;
V_76 = F_465 () ;
F_121 ( & V_58 -> V_3 , V_76 ) ;
V_58 -> V_3 . V_76 = V_76 ;
V_686 = F_291 ( V_58 ) ;
F_127 ( & V_58 -> V_3 ) ;
F_466 () ;
if ( V_686 )
goto F_203;
if ( F_38 ( V_12 ) )
V_686 = F_270 ( V_12 ) ;
if ( V_686 )
goto F_203;
if ( V_84 ) {
if ( ! V_12 -> V_95 . V_481 )
V_12 -> V_95 . V_481 =
V_868 ;
V_686 = - V_399 ;
if ( F_274 ( V_12 ) != 0 )
goto F_203;
if ( ! F_267 ( V_12 ) )
goto F_203;
}
V_58 -> V_8 . V_745 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
return & V_58 -> V_3 ;
F_203:
F_203 ( V_58 -> V_75 -> V_72 ) ;
V_867:
F_406 ( V_58 -> V_63 ) ;
V_866:
F_459 ( & V_58 -> V_3 ) ;
V_865:
F_279 ( V_58 ) ;
F_460 ( V_863 , V_58 ) ;
return F_463 ( V_686 ) ;
}
static void T_11 F_467 ( void * V_869 )
{
struct V_24 V_376 ;
* ( int * ) V_869 = 0 ;
if ( F_196 ( & V_376 ) < 0 )
* ( int * ) V_869 = - V_375 ;
if ( memcmp ( & V_24 , & V_376 , sizeof( struct V_24 ) ) != 0 ) {
F_54 ( V_74 L_34 ,
F_468 () ) ;
* ( int * ) V_869 = - V_375 ;
}
}
static int F_469 ( void )
{
return V_476 + 1 ;
}
static T_5 F_470 ( struct V_2 * V_3 , T_13 V_870 , bool V_871 )
{
T_5 V_93 ;
if ( V_871 )
V_93 = V_872 << V_873 ;
else if ( V_3 -> V_12 -> V_95 . V_874 &&
! ( V_3 -> V_12 -> V_95 . V_875 & V_876 ) )
V_93 = F_471 ( V_3 , V_870 ) <<
V_873 ;
else
V_93 = ( V_877 << V_873 )
| V_878 ;
return V_93 ;
}
static int F_472 ( void )
{
if ( V_84 && ! F_28 () )
return V_879 ;
else
return V_880 ;
}
static void F_473 ( struct V_2 * V_3 )
{
struct V_272 * V_273 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_569 ;
V_58 -> V_254 = false ;
if ( F_150 () ) {
V_569 = F_71 ( V_577 ) ;
if ( V_569 & V_50 ) {
V_273 = F_163 ( V_3 , 0x80000001 , 0 ) ;
if ( V_273 && ( V_273 -> V_881 & V_54 ( V_882 ) ) )
V_58 -> V_254 = true ;
else {
V_569 &= ~ V_50 ;
F_79 ( V_577 ,
V_569 ) ;
}
}
}
}
static void F_474 ( T_2 V_883 , struct V_272 * V_120 )
{
if ( V_883 == 1 && V_8 )
V_120 -> V_274 |= V_54 ( V_275 ) ;
}
static void F_475 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_569 ;
F_78 ( V_884 , V_7 -> V_885 ) ;
F_78 ( V_432 , V_7 -> V_886 ) ;
F_78 ( V_430 , V_7 -> V_887 ) ;
F_78 ( V_888 , V_7 -> V_889 ) ;
F_78 ( V_890 , V_7 -> V_891 ) ;
F_78 ( V_892 , V_7 -> V_893 ) ;
F_78 ( V_599 , V_7 -> V_894 ) ;
F_78 ( V_416 , V_7 -> V_895 ) ;
F_79 ( V_896 , V_7 -> V_897 ) ;
F_79 ( V_447 , V_7 -> V_898 ) ;
F_79 ( V_446 , V_7 -> V_899 ) ;
F_79 ( V_900 , V_7 -> V_901 ) ;
F_79 ( V_902 , V_7 -> V_903 ) ;
F_79 ( V_904 , V_7 -> V_905 ) ;
F_79 ( V_601 , V_7 -> V_906 ) ;
F_79 ( V_418 , V_7 -> V_907 ) ;
F_79 ( V_505 , V_7 -> V_908 ) ;
F_79 ( V_503 , V_7 -> V_909 ) ;
F_79 ( V_910 , V_7 -> V_911 ) ;
F_79 ( V_433 , V_7 -> V_912 ) ;
F_79 ( V_431 , V_7 -> V_913 ) ;
F_79 ( V_914 , V_7 -> V_915 ) ;
F_79 ( V_916 , V_7 -> V_917 ) ;
F_79 ( V_918 , V_7 -> V_919 ) ;
F_79 ( V_602 , V_7 -> V_920 ) ;
F_79 ( V_419 , V_7 -> V_921 ) ;
F_76 ( V_922 , V_7 -> V_923 ) ;
F_76 ( V_448 , V_7 -> V_924 ) ;
F_76 ( V_445 , V_7 -> V_925 ) ;
F_76 ( V_926 , V_7 -> V_927 ) ;
F_76 ( V_334 , V_7 -> V_928 ) ;
F_76 ( V_335 , V_7 -> V_929 ) ;
F_76 ( V_600 , V_7 -> V_930 ) ;
F_76 ( V_417 , V_7 -> V_931 ) ;
F_76 ( V_506 , V_7 -> V_932 ) ;
F_76 ( V_504 , V_7 -> V_933 ) ;
F_80 ( V_606 , V_7 -> V_934 ) ;
F_79 ( V_245 ,
V_7 -> V_935 ) ;
F_79 ( V_237 ,
V_7 -> V_936 ) ;
F_79 ( V_243 ,
V_7 -> V_937 ) ;
F_79 ( V_226 ,
V_7 -> V_938 ) ;
F_79 ( V_603 , V_7 -> V_939 ) ;
F_79 ( V_338 , V_7 -> V_940 ) ;
F_76 ( V_357 , V_7 -> V_941 ) ;
F_76 ( V_220 , V_7 -> V_942 ) ;
F_76 ( V_605 ,
V_7 -> V_943 ) ;
F_76 ( V_341 , V_7 -> V_944 ) ;
F_76 ( V_340 , V_7 -> V_945 ) ;
F_80 ( V_575 , - 1ull ) ;
F_79 ( V_576 ,
( V_24 . V_51 |
V_7 -> V_57 ) ) ;
F_79 ( V_581 ,
V_84 ? V_7 -> V_946 : 0 ) ;
F_79 ( V_582 ,
V_84 ? V_7 -> V_947 : 0 ) ;
if ( F_21 () ) {
T_2 V_569 = F_288 ( V_58 ) ;
if ( ! V_58 -> V_254 )
V_569 &= ~ V_50 ;
V_569 &= ~ V_30 ;
if ( F_44 ( V_7 ,
V_28 ) )
V_569 |= V_7 -> V_56 ;
if ( V_569 & V_30 ) {
if ( V_58 -> V_8 . V_538 )
F_9 ( V_58 -> V_8 . V_538 ) ;
V_58 -> V_8 . V_538 =
F_5 ( V_3 , V_7 -> V_948 ) ;
if ( ! V_58 -> V_8 . V_538 )
V_569 &=
~ V_30 ;
else
F_80 ( V_610 ,
F_301 ( V_58 -> V_8 . V_538 ) ) ;
}
F_79 ( V_577 , V_569 ) ;
}
F_282 () ;
V_58 -> V_949 = 0 ;
V_569 = F_287 ( V_58 ) ;
V_569 &= ~ V_291 ;
V_569 &= ~ V_616 ;
V_569 &= ~ V_27 ;
V_569 |= V_7 -> V_55 ;
V_569 &= ~ V_26 ;
V_569 &= ~ V_301 ;
V_569 |= V_300 ;
F_79 ( V_468 , V_569 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_207 &= ~ V_7 -> V_208 ;
F_76 ( V_209 , ~ V_3 -> V_95 . V_207 ) ;
F_79 ( V_122 ,
V_7 -> V_950 | V_24 . V_392 ) ;
F_79 ( V_121 , V_7 -> V_951 |
( V_24 . V_343 & ~ V_287 ) ) ;
if ( V_7 -> V_951 & V_286 )
F_80 ( V_344 , V_7 -> V_952 ) ;
else if ( V_24 . V_343 & V_286 )
F_80 ( V_344 , V_58 -> V_3 . V_95 . V_345 ) ;
F_286 ( V_58 ) ;
if ( V_7 -> V_55 & V_269 )
F_80 ( V_261 ,
V_58 -> V_8 . V_262 + V_7 -> V_260 ) ;
else
F_80 ( V_261 , V_58 -> V_8 . V_262 ) ;
if ( V_401 ) {
F_78 ( V_611 , V_58 -> V_42 ) ;
F_228 ( V_3 ) ;
}
if ( V_7 -> V_951 & V_127 )
V_3 -> V_95 . V_158 = V_7 -> V_953 ;
if ( V_7 -> V_951 & V_287 )
V_3 -> V_95 . V_158 |= ( V_161 | V_162 ) ;
else
V_3 -> V_95 . V_158 &= ~ ( V_161 | V_162 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 ) ;
F_239 ( V_3 , V_7 -> V_211 ) ;
F_76 ( V_216 , F_131 ( V_7 ) ) ;
F_237 ( V_3 , V_7 -> V_213 ) ;
F_76 ( V_422 , F_132 ( V_7 ) ) ;
F_342 ( V_3 , V_7 -> V_479 ) ;
F_223 ( V_3 ) ;
F_300 ( V_3 , V_348 , V_7 -> V_954 ) ;
F_300 ( V_3 , V_351 , V_7 -> V_955 ) ;
}
static int F_425 ( struct V_2 * V_3 , bool V_956 )
{
struct V_7 * V_7 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_75 * V_748 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
F_142 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_775 == V_956 ) {
F_418 ( V_3 ,
V_956 ? V_957
: V_958 ) ;
return 1 ;
}
if ( ( V_7 -> V_55 & V_26 ) &&
! F_422 ( V_7 -> V_249 , V_388 ) ) {
F_418 ( V_3 , V_959 ) ;
return 1 ;
}
if ( F_45 ( V_7 , V_30 ) &&
! F_422 ( V_7 -> V_948 , V_388 ) ) {
F_418 ( V_3 , V_959 ) ;
return 1 ;
}
if ( V_7 -> V_960 > 0 ||
V_7 -> V_961 > 0 ||
V_7 -> V_962 > 0 ) {
F_476 ( L_35 ,
V_452 ) ;
F_418 ( V_3 , V_959 ) ;
return 1 ;
}
if ( ! F_167 ( V_7 -> V_55 ,
V_289 , V_290 ) ||
! F_167 ( V_7 -> V_56 ,
V_305 , V_306 ) ||
! F_167 ( V_7 -> V_57 ,
V_276 , V_277 ) ||
! F_167 ( V_7 -> V_950 ,
V_280 , V_281 ) ||
! F_167 ( V_7 -> V_951 ,
V_284 , V_285 ) )
{
F_418 ( V_3 , V_959 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_963 & F_171 ) != F_171 ) ||
( ( V_7 -> V_964 & F_172 ) != F_172 ) ) {
F_418 ( V_3 ,
V_965 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_211 & F_171 ) != F_171 ) ||
( ( V_7 -> V_213 & F_172 ) != F_172 ) ) {
F_477 ( V_3 , V_7 ,
V_825 , V_966 ) ;
return 1 ;
}
if ( V_7 -> V_967 != - 1ull ) {
F_477 ( V_3 , V_7 ,
V_825 , V_968 ) ;
return 1 ;
}
V_748 = F_400 ( V_58 ) ;
if ( ! V_748 )
return - V_399 ;
F_478 ( V_3 ) ;
V_58 -> V_8 . V_262 = F_72 ( V_261 ) ;
V_76 = F_465 () ;
V_58 -> V_75 = V_748 ;
F_127 ( V_3 ) ;
F_121 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_466 () ;
V_7 -> V_775 = 1 ;
F_475 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_479 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_204 ) & V_3 -> V_95 . V_207 ) |
( V_7 -> V_211 & V_7 -> V_208 ) |
( F_69 ( V_216 ) & ~ ( V_7 -> V_208 |
V_3 -> V_95 . V_207 ) ) ;
}
static inline unsigned long
F_480 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_420 ) & V_3 -> V_95 . V_458 ) |
( V_7 -> V_213 & V_7 -> V_214 ) |
( F_69 ( V_422 ) & ~ ( V_7 -> V_214 |
V_3 -> V_95 . V_458 ) ) ;
}
void F_481 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_211 = F_479 ( V_3 , V_7 ) ;
V_7 -> V_213 = F_480 ( V_3 , V_7 ) ;
F_350 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_941 ) ;
V_7 -> V_954 = F_339 ( V_3 , V_348 ) ;
V_7 -> V_955 = F_339 ( V_3 , V_351 ) ;
V_7 -> V_942 = F_69 ( V_220 ) ;
V_7 -> V_885 = F_70 ( V_884 ) ;
V_7 -> V_886 = F_70 ( V_432 ) ;
V_7 -> V_887 = F_70 ( V_430 ) ;
V_7 -> V_889 = F_70 ( V_888 ) ;
V_7 -> V_891 = F_70 ( V_890 ) ;
V_7 -> V_893 = F_70 ( V_892 ) ;
V_7 -> V_894 = F_70 ( V_599 ) ;
V_7 -> V_895 = F_70 ( V_416 ) ;
V_7 -> V_897 = F_71 ( V_896 ) ;
V_7 -> V_898 = F_71 ( V_447 ) ;
V_7 -> V_899 = F_71 ( V_446 ) ;
V_7 -> V_901 = F_71 ( V_900 ) ;
V_7 -> V_903 = F_71 ( V_902 ) ;
V_7 -> V_905 = F_71 ( V_904 ) ;
V_7 -> V_906 = F_71 ( V_601 ) ;
V_7 -> V_907 = F_71 ( V_418 ) ;
V_7 -> V_908 = F_71 ( V_505 ) ;
V_7 -> V_909 = F_71 ( V_503 ) ;
V_7 -> V_911 = F_71 ( V_910 ) ;
V_7 -> V_912 = F_71 ( V_433 ) ;
V_7 -> V_913 = F_71 ( V_431 ) ;
V_7 -> V_915 = F_71 ( V_914 ) ;
V_7 -> V_917 = F_71 ( V_916 ) ;
V_7 -> V_919 = F_71 ( V_918 ) ;
V_7 -> V_920 = F_71 ( V_602 ) ;
V_7 -> V_921 = F_71 ( V_419 ) ;
V_7 -> V_923 = F_69 ( V_922 ) ;
V_7 -> V_924 = F_69 ( V_448 ) ;
V_7 -> V_925 = F_69 ( V_445 ) ;
V_7 -> V_927 = F_69 ( V_926 ) ;
V_7 -> V_928 = F_69 ( V_334 ) ;
V_7 -> V_929 = F_69 ( V_335 ) ;
V_7 -> V_930 = F_69 ( V_600 ) ;
V_7 -> V_931 = F_69 ( V_417 ) ;
V_7 -> V_932 = F_69 ( V_506 ) ;
V_7 -> V_933 = F_69 ( V_504 ) ;
V_7 -> V_939 = F_71 ( V_603 ) ;
V_7 -> V_938 =
F_71 ( V_226 ) ;
V_7 -> V_943 =
F_69 ( V_605 ) ;
V_7 -> V_934 = F_72 ( V_606 ) ;
if ( V_7 -> V_951 & V_386 )
V_7 -> V_952 = F_72 ( V_344 ) ;
V_7 -> V_940 = F_71 ( V_338 ) ;
V_7 -> V_944 = F_69 ( V_341 ) ;
V_7 -> V_945 = F_69 ( V_340 ) ;
V_7 -> V_633 = F_71 ( V_796 ) ;
V_7 -> V_679 = F_69 ( V_668 ) ;
V_7 -> V_635 = F_71 ( V_797 ) ;
V_7 -> V_969 = F_71 ( V_667 ) ;
V_7 -> V_631 =
F_71 ( V_861 ) ;
V_7 -> V_859 =
F_71 ( V_718 ) ;
V_7 -> V_858 = F_71 ( V_233 ) ;
V_7 -> V_754 = F_71 ( V_772 ) ;
if ( ! ( V_7 -> V_633 & V_838 ) )
V_7 -> V_935 &= ~ V_17 ;
}
void F_482 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_950 & V_128 )
V_3 -> V_95 . V_158 = V_7 -> V_970 ;
if ( V_7 -> V_950 & V_282 )
V_3 -> V_95 . V_158 |= ( V_161 | V_162 ) ;
else
V_3 -> V_95 . V_158 &= ~ ( V_161 | V_162 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 ) ;
F_300 ( V_3 , V_348 , V_7 -> V_949 ) ;
F_300 ( V_3 , V_351 , V_7 -> V_971 ) ;
F_334 ( V_3 , V_7 -> V_963 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_207 = ( V_3 -> V_117 ? V_205 : 0 ) ;
F_76 ( V_209 , ~ V_3 -> V_95 . V_207 ) ;
V_3 -> V_95 . V_458 = ~ F_69 ( V_568 ) ;
F_336 ( V_3 , V_7 -> V_964 ) ;
F_342 ( V_3 , V_7 -> V_972 ) ;
F_223 ( V_3 ) ;
if ( V_401 ) {
F_228 ( V_3 ) ;
}
F_79 ( V_338 , V_7 -> V_973 ) ;
F_76 ( V_341 , V_7 -> V_974 ) ;
F_76 ( V_340 , V_7 -> V_975 ) ;
F_76 ( V_504 , V_7 -> V_976 ) ;
F_76 ( V_506 , V_7 -> V_977 ) ;
F_76 ( V_417 , V_7 -> V_978 ) ;
F_76 ( V_335 , V_7 -> V_979 ) ;
F_76 ( V_334 , V_7 -> V_980 ) ;
F_78 ( V_884 , V_7 -> V_981 ) ;
F_78 ( V_432 , V_7 -> V_982 ) ;
F_78 ( V_430 , V_7 -> V_983 ) ;
F_78 ( V_888 , V_7 -> V_984 ) ;
F_78 ( V_890 , V_7 -> V_985 ) ;
F_78 ( V_892 , V_7 -> V_986 ) ;
F_78 ( V_416 , V_7 -> V_987 ) ;
if ( V_7 -> V_950 & V_387 )
F_80 ( V_344 , V_7 -> V_988 ) ;
if ( V_7 -> V_950 & V_132 )
F_80 ( V_144 ,
V_7 -> V_989 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_483 ( V_3 ) ;
F_481 ( V_3 , V_7 ) ;
V_76 = F_465 () ;
V_58 -> V_75 = & V_58 -> V_752 ;
F_127 ( V_3 ) ;
F_121 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_466 () ;
if ( V_750 == 0 )
F_407 ( V_58 , V_58 -> V_8 . V_745 ) ;
F_482 ( V_3 , V_7 ) ;
F_80 ( V_261 , V_58 -> V_8 . V_262 ) ;
V_58 -> V_949 = 0 ;
if ( V_58 -> V_8 . V_538 ) {
F_9 ( V_58 -> V_8 . V_538 ) ;
V_58 -> V_8 . V_538 = 0 ;
}
if ( F_77 ( V_58 -> V_798 ) ) {
V_58 -> V_798 = 0 ;
F_418 ( V_3 , F_71 ( V_88 ) ) ;
} else
F_416 ( V_3 ) ;
}
static void F_477 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_710 , unsigned long V_990 )
{
F_482 ( V_3 , V_7 ) ;
V_7 -> V_633 = V_710 | V_838 ;
V_7 -> V_679 = V_990 ;
F_416 ( V_3 ) ;
}
static int F_484 ( struct V_2 * V_3 ,
struct V_991 * V_992 ,
enum V_993 V_994 )
{
return V_995 ;
}
static int T_11 F_485 ( void )
{
int V_519 , V_60 ;
F_486 ( V_125 , & V_163 ) ;
for ( V_60 = 0 ; V_60 < V_590 ; ++ V_60 )
F_487 ( V_60 , V_62 [ V_60 ] ) ;
V_572 = ( unsigned long * ) F_488 ( V_398 ) ;
if ( ! V_572 )
return - V_399 ;
V_574 = ( unsigned long * ) F_488 ( V_398 ) ;
if ( ! V_574 ) {
V_519 = - V_399 ;
goto V_521;
}
V_257 = ( unsigned long * ) F_488 ( V_398 ) ;
if ( ! V_257 ) {
V_519 = - V_399 ;
goto V_996;
}
V_256 = ( unsigned long * ) F_488 ( V_398 ) ;
if ( ! V_256 ) {
V_519 = - V_399 ;
goto V_997;
}
memset ( V_572 , 0xff , V_388 ) ;
F_489 ( 0x80 , V_572 ) ;
memset ( V_574 , 0xff , V_388 ) ;
memset ( V_257 , 0xff , V_388 ) ;
memset ( V_256 , 0xff , V_388 ) ;
F_490 ( 0 , V_544 ) ;
V_519 = F_491 ( & V_998 , sizeof( struct V_1 ) ,
F_492 ( struct V_1 ) , V_999 ) ;
if ( V_519 )
goto V_1000;
F_281 ( V_185 , false ) ;
F_281 ( V_187 , false ) ;
F_281 ( V_188 , true ) ;
F_281 ( V_337 , false ) ;
F_281 ( V_201 , false ) ;
F_281 ( V_339 , false ) ;
if ( V_84 ) {
F_493 ( 0ull , 0ull , 0ull , 0ull ,
V_1001 ) ;
F_289 () ;
F_494 () ;
} else
F_495 () ;
return 0 ;
V_1000:
F_496 ( ( unsigned long ) V_256 ) ;
V_997:
F_496 ( ( unsigned long ) V_257 ) ;
V_996:
F_496 ( ( unsigned long ) V_574 ) ;
V_521:
F_496 ( ( unsigned long ) V_572 ) ;
return V_519 ;
}
static void T_12 F_497 ( void )
{
F_496 ( ( unsigned long ) V_257 ) ;
F_496 ( ( unsigned long ) V_256 ) ;
F_496 ( ( unsigned long ) V_574 ) ;
F_496 ( ( unsigned long ) V_572 ) ;
F_498 () ;
}
