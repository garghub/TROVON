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
F_105 ( V_184 , V_58 -> V_173 . V_185 ) ;
F_105 ( V_186 , V_58 -> V_173 . V_187 ) ;
#endif
#ifdef F_73
F_76 ( V_188 , F_106 ( V_189 ) ) ;
F_76 ( V_190 , F_106 ( V_191 ) ) ;
#else
F_76 ( V_188 , F_100 ( V_58 -> V_173 . V_178 ) ) ;
F_76 ( V_190 , F_100 ( V_58 -> V_173 . V_182 ) ) ;
#endif
#ifdef F_73
F_107 ( V_192 , V_58 -> V_193 ) ;
if ( F_108 ( & V_58 -> V_3 ) )
F_109 ( V_192 , V_58 -> V_194 ) ;
#endif
for ( V_60 = 0 ; V_60 < V_58 -> V_195 ; ++ V_60 )
F_110 ( V_58 -> V_63 [ V_60 ] . V_64 ,
V_58 -> V_63 [ V_60 ] . V_164 ,
V_58 -> V_63 [ V_60 ] . V_89 ) ;
}
static void F_111 ( struct V_1 * V_58 )
{
if ( ! V_58 -> V_173 . V_174 )
return;
++ V_58 -> V_3 . V_196 . V_197 ;
V_58 -> V_173 . V_174 = 0 ;
#ifdef F_73
if ( F_108 ( & V_58 -> V_3 ) )
F_107 ( V_192 , V_58 -> V_194 ) ;
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
#ifdef F_73
if ( F_77 ( V_58 -> V_173 . V_185 | V_58 -> V_173 . V_187 ) ) {
F_114 ( V_184 , V_58 -> V_173 . V_185 ) ;
F_114 ( V_186 , V_58 -> V_173 . V_187 ) ;
}
#else
F_114 ( V_184 , V_198 ) ;
F_114 ( V_186 , V_198 ) ;
#endif
F_96 () ;
#ifdef F_73
F_109 ( V_192 , V_58 -> V_193 ) ;
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
T_5 V_73 = F_53 ( F_59 ( V_199 , V_76 ) ) ;
if ( ! V_200 )
F_122 ( V_73 ) ;
else if ( V_58 -> V_75 -> V_76 != V_76 )
F_61 ( V_58 -> V_75 ) ;
if ( F_59 ( V_79 , V_76 ) != V_58 -> V_75 -> V_72 ) {
F_59 ( V_79 , V_76 ) = V_58 -> V_75 -> V_72 ;
F_56 ( V_58 -> V_75 -> V_72 ) ;
}
if ( V_58 -> V_75 -> V_76 != V_76 ) {
struct V_148 * V_149 = & F_97 ( V_150 ) ;
unsigned long V_201 ;
F_123 ( V_202 , V_3 ) ;
F_124 () ;
F_125 ( & V_58 -> V_75 -> V_80 ,
& F_59 ( V_203 , V_76 ) ) ;
F_126 () ;
F_76 ( V_204 , F_103 () ) ;
F_76 ( V_205 , V_149 -> V_153 ) ;
F_107 ( V_206 , V_201 ) ;
F_76 ( V_207 , V_201 ) ;
V_58 -> V_75 -> V_76 = V_76 ;
}
}
static void F_127 ( struct V_2 * V_3 )
{
F_111 ( F_1 ( V_3 ) ) ;
if ( ! V_200 ) {
F_57 ( F_1 ( V_3 ) -> V_75 ) ;
V_3 -> V_76 = - 1 ;
F_128 () ;
}
}
static void F_129 ( struct V_2 * V_3 )
{
T_9 V_208 ;
if ( V_3 -> V_117 )
return;
V_3 -> V_117 = 1 ;
V_208 = F_69 ( V_209 ) ;
V_208 &= ~ ( V_210 | V_211 ) ;
V_208 |= F_130 ( V_3 , V_210 | V_211 ) ;
F_76 ( V_209 , V_208 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_212 = V_210 ;
if ( F_90 ( V_3 ) )
V_3 -> V_95 . V_212 &=
~ F_4 ( V_3 ) -> V_213 ;
F_76 ( V_214 , ~ V_3 -> V_95 . V_212 ) ;
}
static inline unsigned long F_131 ( struct V_7 * V_215 )
{
return ( V_215 -> V_216 & ~ V_215 -> V_213 ) |
( V_215 -> V_217 & V_215 -> V_213 ) ;
}
static inline unsigned long F_132 ( struct V_7 * V_215 )
{
return ( V_215 -> V_218 & ~ V_215 -> V_219 ) |
( V_215 -> V_220 & V_215 -> V_219 ) ;
}
static void F_133 ( struct V_2 * V_3 )
{
F_134 ( V_3 ) ;
F_82 ( V_209 , V_210 | V_211 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_212 = 0 ;
F_76 ( V_214 , ~ V_3 -> V_95 . V_212 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_216 = ( V_7 -> V_216 & ~ V_210 ) |
( V_3 -> V_95 . V_208 & V_210 ) ;
F_76 ( V_221 , F_131 ( V_7 ) ) ;
} else
F_76 ( V_221 , V_3 -> V_95 . V_208 ) ;
}
static unsigned long F_135 ( struct V_2 * V_3 )
{
unsigned long V_222 , V_223 ;
if ( ! F_136 ( V_224 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_137 ( V_224 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
V_222 = F_69 ( V_225 ) ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
V_222 &= V_226 ;
V_223 = F_1 ( V_3 ) -> V_115 . V_223 ;
V_222 |= V_223 & ~ V_226 ;
}
F_1 ( V_3 ) -> V_222 = V_222 ;
}
return F_1 ( V_3 ) -> V_222 ;
}
static void F_138 ( struct V_2 * V_3 , unsigned long V_222 )
{
F_137 ( V_224 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_139 ( V_227 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_222 = V_222 ;
if ( F_1 ( V_3 ) -> V_115 . V_116 ) {
F_1 ( V_3 ) -> V_115 . V_223 = V_222 ;
V_222 |= V_228 | V_229 ;
}
F_76 ( V_225 , V_222 ) ;
}
static T_2 F_140 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_230 = F_71 ( V_231 ) ;
int V_93 = 0 ;
if ( V_230 & V_232 )
V_93 |= V_233 ;
if ( V_230 & V_234 )
V_93 |= V_235 ;
return V_93 & V_89 ;
}
static void F_141 ( struct V_2 * V_3 , int V_89 )
{
T_2 V_236 = F_71 ( V_231 ) ;
T_2 V_230 = V_236 ;
V_230 &= ~ ( V_232 | V_234 ) ;
if ( V_89 & V_235 )
V_230 |= V_234 ;
else if ( V_89 & V_233 )
V_230 |= V_232 ;
if ( ( V_230 != V_236 ) )
F_79 ( V_231 , V_230 ) ;
}
static void F_142 ( struct V_2 * V_3 )
{
unsigned long V_237 ;
V_237 = F_143 ( V_3 ) ;
V_237 += F_71 ( V_238 ) ;
F_144 ( V_3 , V_237 ) ;
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
bool V_239 , T_2 V_240 ,
bool V_241 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_14 = V_133 | V_17 ;
if ( V_133 == V_19 && F_90 ( V_3 ) &&
F_145 ( V_3 ) )
return;
if ( V_239 ) {
F_79 ( V_242 , V_240 ) ;
V_14 |= V_243 ;
}
if ( V_58 -> V_115 . V_116 ) {
int V_244 = 0 ;
if ( F_148 ( V_133 ) )
V_244 = V_3 -> V_95 . V_245 ;
if ( F_149 ( V_3 , V_133 , V_244 ) != V_246 )
F_123 ( V_247 , V_3 ) ;
return;
}
if ( F_148 ( V_133 ) ) {
F_79 ( V_248 ,
V_58 -> V_3 . V_95 . V_245 ) ;
V_14 |= V_249 ;
} else
V_14 |= V_18 ;
F_79 ( V_250 , V_14 ) ;
}
static bool F_150 ( void )
{
return F_40 () ;
}
static void F_151 ( struct V_1 * V_58 , int V_251 , int V_252 )
{
struct V_71 V_253 ;
V_253 = V_58 -> V_63 [ V_252 ] ;
V_58 -> V_63 [ V_252 ] = V_58 -> V_63 [ V_251 ] ;
V_58 -> V_63 [ V_251 ] = V_253 ;
}
static void F_152 ( struct V_1 * V_58 )
{
int V_195 , V_64 ;
unsigned long * V_254 ;
V_195 = 0 ;
#ifdef F_73
if ( F_108 ( & V_58 -> V_3 ) ) {
V_64 = F_48 ( V_58 , V_255 ) ;
if ( V_64 >= 0 )
F_151 ( V_58 , V_64 , V_195 ++ ) ;
V_64 = F_48 ( V_58 , V_256 ) ;
if ( V_64 >= 0 )
F_151 ( V_58 , V_64 , V_195 ++ ) ;
V_64 = F_48 ( V_58 , V_257 ) ;
if ( V_64 >= 0 )
F_151 ( V_58 , V_64 , V_195 ++ ) ;
V_64 = F_48 ( V_58 , V_258 ) ;
if ( V_64 >= 0 && V_58 -> V_259 )
F_151 ( V_58 , V_64 , V_195 ++ ) ;
V_64 = F_48 ( V_58 , V_260 ) ;
if ( ( V_64 >= 0 ) && ( V_58 -> V_3 . V_95 . V_158 & V_160 ) )
F_151 ( V_58 , V_64 , V_195 ++ ) ;
}
#endif
V_64 = F_48 ( V_58 , V_125 ) ;
if ( V_64 >= 0 && F_99 ( V_58 , V_64 ) )
F_151 ( V_58 , V_64 , V_195 ++ ) ;
V_58 -> V_195 = V_195 ;
if ( F_17 () ) {
if ( F_108 ( & V_58 -> V_3 ) )
V_254 = V_261 ;
else
V_254 = V_262 ;
F_80 ( V_263 , F_53 ( V_254 ) ) ;
}
}
static T_5 F_153 ( void )
{
T_5 V_264 , V_265 ;
F_154 ( V_264 ) ;
V_265 = F_72 ( V_266 ) ;
return V_264 + V_265 ;
}
T_5 F_155 ( struct V_2 * V_3 )
{
T_5 V_264 , V_265 ;
F_154 ( V_264 ) ;
V_265 = F_90 ( V_3 ) ?
F_1 ( V_3 ) -> V_8 . V_267 :
F_72 ( V_266 ) ;
return V_264 + V_265 ;
}
static void F_156 ( struct V_2 * V_3 , T_2 V_268 , bool V_269 )
{
if ( ! V_269 )
return;
if ( V_268 > V_270 ) {
V_3 -> V_95 . V_271 = 1 ;
V_3 -> V_95 . V_272 = 1 ;
} else
F_157 ( 1 , L_6 ) ;
}
static void F_158 ( struct V_2 * V_3 , T_5 V_273 )
{
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 ;
F_1 ( V_3 ) -> V_8 . V_267 = V_273 ;
V_7 = F_4 ( V_3 ) ;
F_80 ( V_266 , V_273 +
( F_44 ( V_7 , V_274 ) ?
V_7 -> V_265 : 0 ) ) ;
} else {
F_80 ( V_266 , V_273 ) ;
}
}
static void F_159 ( struct V_2 * V_3 , T_10 V_275 , bool V_135 )
{
T_5 V_273 = F_72 ( V_266 ) ;
F_80 ( V_266 , V_273 + V_275 ) ;
if ( F_90 ( V_3 ) ) {
F_1 ( V_3 ) -> V_8 . V_267 += V_275 ;
}
}
static T_5 F_160 ( struct V_2 * V_3 , T_5 V_276 )
{
return V_276 - F_161 () ;
}
static bool F_162 ( struct V_2 * V_3 )
{
struct V_277 * V_278 = F_163 ( V_3 , 1 , 0 ) ;
return V_278 && ( V_278 -> V_279 & ( 1 << ( V_280 & 31 ) ) ) ;
}
static inline bool F_164 ( struct V_2 * V_3 )
{
return V_8 && F_162 ( V_3 ) ;
}
static T_11 void F_165 ( void )
{
V_281 = 0x16 ;
V_282 = 0x16 |
V_283 | V_284 |
V_52 ;
V_285 = 0 ;
#ifdef F_73
V_286 = V_287 ;
#else
V_286 = 0 ;
#endif
F_166 ( V_288 ,
V_289 , V_290 ) ;
V_289 = 0 ;
V_290 &=
V_291 | V_292 ;
F_166 ( V_293 ,
V_294 , V_295 ) ;
V_294 = 0 ;
V_295 &=
V_296 | V_274 |
V_297 | V_298 |
V_299 | V_300 |
V_301 |
#ifdef F_73
V_302 | V_303 |
#endif
V_304 | V_305 |
V_306 | V_307 |
V_308 |
V_28 ;
V_295 |= V_26 ;
F_166 ( V_309 ,
V_310 , V_311 ) ;
V_310 = 0 ;
V_311 &=
V_30 ;
}
static inline bool F_167 ( T_2 V_312 , T_2 V_313 , T_2 V_314 )
{
return ( ( V_312 & V_314 ) | V_313 ) == V_312 ;
}
static inline T_5 F_168 ( T_2 V_313 , T_2 V_314 )
{
return V_313 | ( ( T_5 ) V_314 << 32 ) ;
}
static int F_169 ( struct V_2 * V_3 , T_2 V_315 , T_5 * V_316 )
{
if ( ! F_164 ( V_3 ) && V_315 >= V_317 &&
V_315 <= V_318 ) {
F_170 ( V_3 , V_319 , 0 ) ;
return 1 ;
}
switch ( V_315 ) {
case V_320 :
* V_316 = 0 ;
break;
case V_317 :
* V_316 = V_321 |
( ( T_5 ) V_322 << V_323 ) |
( V_324 << V_325 ) ;
break;
case V_326 :
case V_327 :
* V_316 = F_168 ( V_281 ,
V_282 ) ;
break;
case V_328 :
case V_293 :
* V_316 = F_168 ( V_294 ,
V_295 ) ;
break;
case V_329 :
case V_330 :
* V_316 = F_168 ( V_285 ,
V_286 ) ;
break;
case V_318 :
case V_288 :
* V_316 = F_168 ( V_289 ,
V_290 ) ;
break;
case V_331 :
* V_316 = 0 ;
break;
#define F_171 (X86_CR0_PE | X86_CR0_PG | X86_CR0_NE)
#define F_172 X86_CR4_VMXE
case V_332 :
* V_316 = F_171 ;
break;
case V_333 :
* V_316 = - 1ULL ;
break;
case V_334 :
* V_316 = F_172 ;
break;
case V_335 :
* V_316 = - 1ULL ;
break;
case V_336 :
* V_316 = 0x1f ;
break;
case V_309 :
* V_316 = F_168 ( V_310 ,
V_311 ) ;
break;
case V_337 :
* V_316 = 0 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_173 ( struct V_2 * V_3 , T_2 V_315 , T_5 V_164 )
{
if ( ! F_164 ( V_3 ) )
return 0 ;
if ( V_315 == V_320 )
return 1 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_3 , T_2 V_315 , T_5 * V_316 )
{
T_5 V_164 ;
struct V_71 * V_59 ;
if ( ! V_316 ) {
F_54 ( V_74 L_7 ) ;
return - V_338 ;
}
switch ( V_315 ) {
#ifdef F_73
case V_189 :
V_164 = F_69 ( V_339 ) ;
break;
case V_191 :
V_164 = F_69 ( V_340 ) ;
break;
case V_192 :
F_118 ( F_1 ( V_3 ) ) ;
V_164 = F_1 ( V_3 ) -> V_194 ;
break;
#endif
case V_125 :
return F_175 ( V_3 , V_315 , V_316 ) ;
case V_341 :
V_164 = F_153 () ;
break;
case V_342 :
V_164 = F_71 ( V_343 ) ;
break;
case V_344 :
V_164 = F_69 ( V_345 ) ;
break;
case V_206 :
V_164 = F_69 ( V_346 ) ;
break;
case V_258 :
if ( ! F_1 ( V_3 ) -> V_259 )
return 1 ;
default:
if ( F_169 ( V_3 , V_315 , V_316 ) )
return 0 ;
V_59 = F_51 ( F_1 ( V_3 ) , V_315 ) ;
if ( V_59 ) {
V_164 = V_59 -> V_164 ;
break;
}
return F_175 ( V_3 , V_315 , V_316 ) ;
}
* V_316 = V_164 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , T_2 V_315 , T_5 V_164 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_71 * V_59 ;
int V_93 = 0 ;
switch ( V_315 ) {
case V_125 :
V_93 = F_177 ( V_3 , V_315 , V_164 ) ;
break;
#ifdef F_73
case V_189 :
F_83 ( V_58 ) ;
F_76 ( V_339 , V_164 ) ;
break;
case V_191 :
F_83 ( V_58 ) ;
F_76 ( V_340 , V_164 ) ;
break;
case V_192 :
F_118 ( V_58 ) ;
V_58 -> V_194 = V_164 ;
break;
#endif
case V_342 :
F_79 ( V_343 , V_164 ) ;
break;
case V_344 :
F_76 ( V_345 , V_164 ) ;
break;
case V_206 :
F_76 ( V_346 , V_164 ) ;
break;
case V_341 :
F_178 ( V_3 , V_164 ) ;
break;
case V_347 :
if ( V_24 . V_348 & V_291 ) {
F_80 ( V_349 , V_164 ) ;
V_3 -> V_95 . V_350 = V_164 ;
break;
}
V_93 = F_177 ( V_3 , V_315 , V_164 ) ;
break;
case V_258 :
if ( ! V_58 -> V_259 )
return 1 ;
if ( ( V_164 >> 32 ) != 0 )
return 1 ;
default:
if ( F_173 ( V_3 , V_315 , V_164 ) )
break;
V_59 = F_51 ( V_58 , V_315 ) ;
if ( V_59 ) {
V_59 -> V_164 = V_164 ;
if ( V_59 - V_58 -> V_63 < V_58 -> V_195 ) {
F_119 () ;
F_110 ( V_59 -> V_64 , V_59 -> V_164 ,
V_59 -> V_89 ) ;
F_120 () ;
}
break;
}
V_93 = F_177 ( V_3 , V_315 , V_164 ) ;
}
return V_93 ;
}
static void F_179 ( struct V_2 * V_3 , enum V_351 V_352 )
{
F_137 ( V_352 , ( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
switch ( V_352 ) {
case V_353 :
V_3 -> V_95 . V_354 [ V_353 ] = F_69 ( V_355 ) ;
break;
case V_356 :
V_3 -> V_95 . V_354 [ V_356 ] = F_69 ( V_357 ) ;
break;
case V_358 :
if ( V_84 )
F_180 ( V_3 ) ;
break;
default:
break;
}
}
static void F_181 ( struct V_2 * V_3 , struct V_359 * V_360 )
{
if ( V_3 -> V_111 & V_361 )
F_76 ( V_362 , V_360 -> V_95 . V_363 [ 7 ] ) ;
else
F_76 ( V_362 , V_3 -> V_95 . V_364 ) ;
F_89 ( V_3 ) ;
}
static T_11 int F_182 ( void )
{
return F_183 () ;
}
static T_11 int F_184 ( void )
{
T_5 V_59 ;
F_107 ( V_320 , V_59 ) ;
if ( V_59 & V_365 ) {
if ( ! ( V_59 & V_366 )
&& F_185 () )
return 1 ;
if ( ! ( V_59 & V_367 )
&& ( V_59 & V_366 )
&& ! F_185 () ) {
F_54 ( V_147 L_8
L_9 ) ;
return 1 ;
}
if ( ! ( V_59 & V_367 )
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
static int F_186 ( void * V_368 )
{
int V_76 = F_58 () ;
T_5 V_73 = F_53 ( F_59 ( V_199 , V_76 ) ) ;
T_5 V_369 , V_370 ;
if ( F_187 () & V_371 )
return - V_372 ;
F_188 ( & F_59 ( V_203 , V_76 ) ) ;
F_107 ( V_320 , V_369 ) ;
V_370 = V_365 ;
V_370 |= V_367 ;
if ( F_185 () )
V_370 |= V_366 ;
if ( ( V_369 & V_370 ) != V_370 ) {
F_109 ( V_320 , V_369 | V_370 ) ;
}
F_189 ( F_187 () | V_371 ) ;
if ( V_200 ) {
F_122 ( V_73 ) ;
F_66 () ;
}
F_190 ( & F_97 ( V_150 ) ) ;
return 0 ;
}
static void F_191 ( void )
{
int V_76 = F_58 () ;
struct V_75 * V_167 , * V_373 ;
F_192 (v, n, &per_cpu(loaded_vmcss_on_cpu, cpu),
loaded_vmcss_on_cpu_link)
F_57 ( V_167 ) ;
}
static void F_128 ( void )
{
asm volatile (__ex(ASM_VMX_VMXOFF) : : : "cc");
}
static void F_193 ( void * V_368 )
{
if ( V_200 ) {
F_191 () ;
F_128 () ;
}
F_189 ( F_187 () & ~ V_371 ) ;
}
static T_11 int F_194 ( T_2 V_374 , T_2 V_375 ,
T_2 V_59 , T_2 * V_376 )
{
T_2 V_377 , V_378 ;
T_2 V_379 = V_374 | V_375 ;
F_166 ( V_59 , V_377 , V_378 ) ;
V_379 &= V_378 ;
V_379 |= V_377 ;
if ( V_374 & ~ V_379 )
return - V_380 ;
* V_376 = V_379 ;
return 0 ;
}
static T_11 bool F_195 ( T_2 V_59 , T_2 V_379 )
{
T_2 V_377 , V_378 ;
F_166 ( V_59 , V_377 , V_378 ) ;
return V_378 & V_379 ;
}
static T_11 int F_196 ( struct V_24 * V_381 )
{
T_2 V_377 , V_378 ;
T_2 V_382 , V_383 , V_384 , V_385 ;
T_2 V_386 = 0 ;
T_2 V_387 = 0 ;
T_2 V_388 = 0 ;
T_2 V_389 = 0 ;
T_2 V_390 = 0 ;
V_382 = V_283 | V_284 ;
V_383 = V_52 ;
if ( F_194 ( V_382 , V_383 , V_327 ,
& V_386 ) < 0 )
return - V_380 ;
V_382 = V_297 |
#ifdef F_73
V_302 |
V_303 |
#endif
V_300 |
V_301 |
V_306 |
V_304 |
V_274 |
V_299 |
V_307 |
V_298 |
V_308 ;
V_383 = V_27 |
V_26 |
V_28 ;
if ( F_194 ( V_382 , V_383 , V_293 ,
& V_387 ) < 0 )
return - V_380 ;
#ifdef F_73
if ( ( V_387 & V_27 ) )
V_387 &= ~ V_302 &
~ V_303 ;
#endif
if ( V_387 & V_28 ) {
V_384 = 0 ;
V_385 = V_30 |
V_53 |
V_49 |
V_45 |
V_46 |
V_47 |
V_50 ;
if ( F_194 ( V_384 , V_385 ,
V_309 ,
& V_388 ) < 0 )
return - V_380 ;
}
#ifndef F_73
if ( ! ( V_388 &
V_30 ) )
V_387 &= ~ V_27 ;
#endif
if ( V_388 & V_45 ) {
V_387 &= ~ ( V_300 |
V_301 |
V_298 ) ;
F_166 ( V_337 ,
V_31 . V_32 , V_31 . V_42 ) ;
}
V_382 = 0 ;
#ifdef F_73
V_382 |= V_287 ;
#endif
V_383 = V_391 | V_392 ;
if ( F_194 ( V_382 , V_383 , V_330 ,
& V_389 ) < 0 )
return - V_380 ;
V_382 = 0 ;
V_383 = V_291 ;
if ( F_194 ( V_382 , V_383 , V_288 ,
& V_390 ) < 0 )
return - V_380 ;
F_166 ( V_317 , V_377 , V_378 ) ;
if ( ( V_378 & 0x1fff ) > V_393 )
return - V_380 ;
#ifdef F_73
if ( V_378 & ( 1u << 16 ) )
return - V_380 ;
#endif
if ( ( ( V_378 >> 18 ) & 15 ) != 6 )
return - V_380 ;
V_381 -> V_394 = V_378 & 0x1fff ;
V_381 -> V_395 = F_197 ( V_24 . V_394 ) ;
V_381 -> V_396 = V_377 ;
V_381 -> V_51 = V_386 ;
V_381 -> V_25 = V_387 ;
V_381 -> V_29 = V_388 ;
V_381 -> V_397 = V_389 ;
V_381 -> V_348 = V_390 ;
V_126 =
F_195 ( V_288 ,
V_127 )
&& F_195 ( V_330 ,
V_128 ) ;
V_130 =
F_195 ( V_288 ,
V_131 )
&& F_195 ( V_330 ,
V_132 ) ;
if ( V_130 && V_398 . V_399 == 0x6 ) {
switch ( V_398 . V_400 ) {
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
int V_401 = F_199 ( V_76 ) ;
struct V_10 * V_402 ;
struct V_72 * V_72 ;
V_402 = F_200 ( V_401 , V_403 , V_24 . V_395 ) ;
if ( ! V_402 )
return NULL ;
V_72 = F_201 ( V_402 ) ;
memset ( V_72 , 0 , V_24 . V_394 ) ;
V_72 -> V_396 = V_24 . V_396 ;
return V_72 ;
}
static struct V_72 * F_202 ( void )
{
return F_198 ( F_58 () ) ;
}
static void F_203 ( struct V_72 * V_72 )
{
F_204 ( ( unsigned long ) V_72 , V_24 . V_395 ) ;
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
F_203 ( F_59 ( V_199 , V_76 ) ) ;
F_59 ( V_199 , V_76 ) = NULL ;
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
return - V_404 ;
}
F_59 ( V_199 , V_76 ) = V_72 ;
}
return 0 ;
}
static T_11 int F_209 ( void )
{
if ( F_196 ( & V_24 ) < 0 )
return - V_380 ;
if ( F_210 ( V_405 ) )
F_211 ( V_159 ) ;
if ( ! F_39 () )
V_406 = 0 ;
if ( ! F_35 () ||
! F_29 () ) {
V_84 = 0 ;
V_407 = 0 ;
}
if ( ! F_36 () )
V_407 = 0 ;
if ( ! F_23 () )
V_48 = 0 ;
if ( ! F_18 () )
V_408 -> V_409 = NULL ;
if ( V_84 && ! F_27 () )
F_212 () ;
if ( ! F_37 () )
V_410 = 0 ;
if ( V_8 )
F_165 () ;
return F_208 () ;
}
static T_12 void F_213 ( void )
{
F_206 () ;
}
static void F_214 ( int V_92 , struct V_411 * V_412 )
{
struct V_413 * V_414 = & V_101 [ V_92 ] ;
if ( F_69 ( V_414 -> V_102 ) == V_412 -> V_102 && ( V_412 -> V_102 & V_415 ) ) {
F_78 ( V_414 -> V_99 , V_412 -> V_99 ) ;
F_76 ( V_414 -> V_102 , V_412 -> V_102 ) ;
F_79 ( V_414 -> V_104 , V_412 -> V_104 ) ;
F_79 ( V_414 -> V_108 , V_412 -> V_106 ) ;
} else {
T_2 V_416 = ( F_70 ( V_414 -> V_99 ) & V_417 )
<< V_418 ;
F_79 ( V_414 -> V_108 , 0x93 | V_416 ) ;
}
}
static void F_215 ( struct V_2 * V_3 )
{
unsigned long V_419 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
V_58 -> V_420 = 1 ;
V_58 -> V_115 . V_116 = 0 ;
F_83 ( V_58 ) ;
F_78 ( V_421 , V_58 -> V_115 . V_172 . V_99 ) ;
F_76 ( V_422 , V_58 -> V_115 . V_172 . V_102 ) ;
F_79 ( V_423 , V_58 -> V_115 . V_172 . V_104 ) ;
F_79 ( V_424 , V_58 -> V_115 . V_172 . V_106 ) ;
V_419 = F_69 ( V_225 ) ;
V_419 &= V_226 ;
V_419 |= V_58 -> V_115 . V_223 & ~ V_226 ;
F_76 ( V_225 , V_419 ) ;
F_76 ( V_425 , ( F_69 ( V_425 ) & ~ V_426 ) |
( F_69 ( V_427 ) & V_426 ) ) ;
F_89 ( V_3 ) ;
if ( V_428 )
return;
F_214 ( V_429 , & V_58 -> V_115 . V_186 ) ;
F_214 ( V_430 , & V_58 -> V_115 . V_184 ) ;
F_214 ( V_431 , & V_58 -> V_115 . V_181 ) ;
F_214 ( V_432 , & V_58 -> V_115 . V_177 ) ;
F_83 ( V_58 ) ;
F_78 ( V_433 , 0 ) ;
F_79 ( V_434 , 0x93 ) ;
F_78 ( V_435 ,
F_70 ( V_435 ) & ~ V_417 ) ;
F_79 ( V_436 , 0x9b ) ;
}
static T_4 F_216 ( struct V_12 * V_12 )
{
if ( ! V_12 -> V_95 . V_437 ) {
struct V_438 * V_439 ;
struct V_440 * V_441 ;
T_13 V_442 ;
V_439 = V_438 ( V_12 ) ;
V_441 = F_217 ( V_439 , 0 ) ;
V_442 = V_441 -> V_442 + V_441 -> V_443 - 3 ;
return V_442 << V_13 ;
}
return V_12 -> V_95 . V_437 ;
}
static void F_218 ( int V_92 , struct V_411 * V_412 )
{
struct V_413 * V_414 = & V_101 [ V_92 ] ;
V_412 -> V_99 = F_70 ( V_414 -> V_99 ) ;
V_412 -> V_102 = F_69 ( V_414 -> V_102 ) ;
V_412 -> V_104 = F_71 ( V_414 -> V_104 ) ;
V_412 -> V_106 = F_71 ( V_414 -> V_108 ) ;
F_78 ( V_414 -> V_99 , V_412 -> V_102 >> 4 ) ;
F_79 ( V_414 -> V_102 , V_412 -> V_102 & 0xffff0 ) ;
F_79 ( V_414 -> V_104 , 0xffff ) ;
F_79 ( V_414 -> V_108 , 0xf3 ) ;
if ( V_412 -> V_102 & 0xf )
F_95 ( V_147 L_12
L_13 ,
V_92 ) ;
}
static void F_219 ( struct V_2 * V_3 )
{
unsigned long V_419 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_407 )
return;
V_58 -> V_420 = 1 ;
V_58 -> V_115 . V_116 = 1 ;
if ( ! V_3 -> V_12 -> V_95 . V_437 ) {
F_95 ( V_147 L_14
L_15 ) ;
F_220 ( & V_3 -> V_12 -> V_444 , V_3 -> V_445 ) ;
F_221 ( V_3 -> V_12 , 0xfeffd000 ) ;
V_3 -> V_445 = F_222 ( & V_3 -> V_12 -> V_444 ) ;
}
F_83 ( V_58 ) ;
V_58 -> V_115 . V_172 . V_99 = F_70 ( V_421 ) ;
V_58 -> V_115 . V_172 . V_102 = F_69 ( V_422 ) ;
F_76 ( V_422 , F_216 ( V_3 -> V_12 ) ) ;
V_58 -> V_115 . V_172 . V_104 = F_71 ( V_423 ) ;
F_79 ( V_423 , V_446 - 1 ) ;
V_58 -> V_115 . V_172 . V_106 = F_71 ( V_424 ) ;
F_79 ( V_424 , 0x008b ) ;
V_419 = F_69 ( V_225 ) ;
V_58 -> V_115 . V_223 = V_419 ;
V_419 |= V_228 | V_229 ;
F_76 ( V_225 , V_419 ) ;
F_76 ( V_425 , F_69 ( V_425 ) | V_426 ) ;
F_89 ( V_3 ) ;
if ( V_428 )
goto V_447;
F_78 ( V_433 , F_69 ( V_448 ) >> 4 ) ;
F_79 ( V_449 , 0xffff ) ;
F_79 ( V_434 , 0xf3 ) ;
F_79 ( V_436 , 0xf3 ) ;
F_79 ( V_450 , 0xffff ) ;
if ( F_69 ( V_451 ) == 0xffff0000 )
F_76 ( V_451 , 0xf0000 ) ;
F_78 ( V_435 , F_69 ( V_451 ) >> 4 ) ;
F_218 ( V_429 , & V_58 -> V_115 . V_186 ) ;
F_218 ( V_430 , & V_58 -> V_115 . V_184 ) ;
F_218 ( V_431 , & V_58 -> V_115 . V_181 ) ;
F_218 ( V_432 , & V_58 -> V_115 . V_177 ) ;
V_447:
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
V_292 ) ;
V_59 -> V_164 = V_158 ;
} else {
F_79 ( V_121 ,
F_71 ( V_121 ) &
~ V_292 ) ;
V_59 -> V_164 = V_158 & ~ V_162 ;
}
F_152 ( V_58 ) ;
}
static void F_225 ( struct V_2 * V_3 )
{
T_2 V_452 ;
F_83 ( F_1 ( V_3 ) ) ;
V_452 = F_71 ( V_424 ) ;
if ( ( V_452 & V_453 ) != V_454 ) {
F_226 ( L_16 ,
V_455 ) ;
F_79 ( V_424 ,
( V_452 & ~ V_453 )
| V_454 ) ;
}
F_224 ( V_3 , V_3 -> V_95 . V_158 | V_161 ) ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_79 ( V_121 ,
F_71 ( V_121 )
& ~ V_292 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 & ~ V_161 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_65 ( F_1 ( V_3 ) ) ;
if ( V_84 ) {
if ( ! F_229 ( V_3 -> V_95 . V_456 . V_457 ) )
return;
F_67 ( F_230 ( V_3 -> V_95 . V_456 . V_457 ) ) ;
}
}
static void F_134 ( struct V_2 * V_3 )
{
T_9 V_212 = V_3 -> V_95 . V_212 ;
V_3 -> V_95 . V_208 &= ~ V_212 ;
V_3 -> V_95 . V_208 |= F_69 ( V_209 ) & V_212 ;
}
static void F_231 ( struct V_2 * V_3 )
{
if ( V_84 && F_232 ( V_3 ) )
V_3 -> V_95 . V_458 = F_69 ( V_459 ) ;
F_137 ( V_460 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_233 ( struct V_2 * V_3 )
{
T_9 V_461 = V_3 -> V_95 . V_461 ;
V_3 -> V_95 . V_462 &= ~ V_461 ;
V_3 -> V_95 . V_462 |= F_69 ( V_425 ) & V_461 ;
}
static void F_234 ( struct V_2 * V_3 )
{
if ( ! F_136 ( V_358 ,
( unsigned long * ) & V_3 -> V_95 . V_463 ) )
return;
if ( F_232 ( V_3 ) && F_235 ( V_3 ) && ! F_108 ( V_3 ) ) {
F_80 ( V_464 , V_3 -> V_95 . V_456 . V_465 [ 0 ] ) ;
F_80 ( V_466 , V_3 -> V_95 . V_456 . V_465 [ 1 ] ) ;
F_80 ( V_467 , V_3 -> V_95 . V_456 . V_465 [ 2 ] ) ;
F_80 ( V_468 , V_3 -> V_95 . V_456 . V_465 [ 3 ] ) ;
}
}
static void F_180 ( struct V_2 * V_3 )
{
if ( F_232 ( V_3 ) && F_235 ( V_3 ) && ! F_108 ( V_3 ) ) {
V_3 -> V_95 . V_456 . V_465 [ 0 ] = F_72 ( V_464 ) ;
V_3 -> V_95 . V_456 . V_465 [ 1 ] = F_72 ( V_466 ) ;
V_3 -> V_95 . V_456 . V_465 [ 2 ] = F_72 ( V_467 ) ;
V_3 -> V_95 . V_456 . V_465 [ 3 ] = F_72 ( V_468 ) ;
}
F_137 ( V_358 ,
( unsigned long * ) & V_3 -> V_95 . V_96 ) ;
F_137 ( V_358 ,
( unsigned long * ) & V_3 -> V_95 . V_463 ) ;
}
static void F_236 ( unsigned long * V_469 ,
unsigned long V_208 ,
struct V_2 * V_3 )
{
if ( ! F_136 ( V_460 , ( T_9 * ) & V_3 -> V_95 . V_96 ) )
F_231 ( V_3 ) ;
if ( ! ( V_208 & V_470 ) ) {
F_79 ( V_471 ,
F_71 ( V_471 ) |
( V_300 |
V_301 ) ) ;
V_3 -> V_95 . V_208 = V_208 ;
F_237 ( V_3 , F_238 ( V_3 ) ) ;
} else if ( ! F_232 ( V_3 ) ) {
F_79 ( V_471 ,
F_71 ( V_471 ) &
~ ( V_300 |
V_301 ) ) ;
V_3 -> V_95 . V_208 = V_208 ;
F_237 ( V_3 , F_238 ( V_3 ) ) ;
}
if ( ! ( V_208 & V_472 ) )
* V_469 &= ~ V_472 ;
}
static void F_239 ( struct V_2 * V_3 , unsigned long V_208 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
unsigned long V_469 ;
if ( V_407 )
V_469 = ( V_208 & ~ V_473 )
| V_474 ;
else
V_469 = ( V_208 & ~ V_475 ) | V_476 ;
if ( V_58 -> V_115 . V_116 && ( V_208 & V_477 ) )
F_215 ( V_3 ) ;
if ( ! V_58 -> V_115 . V_116 && ! ( V_208 & V_477 ) )
F_219 ( V_3 ) ;
#ifdef F_73
if ( V_3 -> V_95 . V_158 & V_162 ) {
if ( ! F_232 ( V_3 ) && ( V_208 & V_470 ) )
F_225 ( V_3 ) ;
if ( F_232 ( V_3 ) && ! ( V_208 & V_470 ) )
F_227 ( V_3 ) ;
}
#endif
if ( V_84 )
F_236 ( & V_469 , V_208 , V_3 ) ;
if ( ! V_3 -> V_117 )
V_469 |= V_210 | V_211 ;
F_76 ( V_221 , V_208 ) ;
F_76 ( V_209 , V_469 ) ;
V_3 -> V_95 . V_208 = V_208 ;
F_139 ( V_227 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static T_5 F_230 ( unsigned long V_457 )
{
T_5 V_69 ;
V_69 = V_478 |
V_479 << V_480 ;
V_69 |= ( V_457 & V_481 ) ;
return V_69 ;
}
static void F_240 ( struct V_2 * V_3 , unsigned long V_458 )
{
unsigned long V_482 ;
T_5 V_69 ;
V_482 = V_458 ;
if ( V_84 ) {
V_69 = F_230 ( V_458 ) ;
F_80 ( V_483 , V_69 ) ;
V_482 = F_232 ( V_3 ) ? F_241 ( V_3 ) :
V_3 -> V_12 -> V_95 . V_484 ;
F_234 ( V_3 ) ;
}
F_228 ( V_3 ) ;
F_76 ( V_459 , V_482 ) ;
}
static int F_237 ( struct V_2 * V_3 , unsigned long V_462 )
{
unsigned long V_485 = V_462 | ( F_1 ( V_3 ) -> V_115 . V_116 ?
V_486 : V_487 ) ;
if ( V_462 & V_371 ) {
if ( ! F_164 ( V_3 ) )
return 1 ;
} else if ( F_1 ( V_3 ) -> V_8 . V_488 )
return 1 ;
V_3 -> V_95 . V_462 = V_462 ;
if ( V_84 ) {
if ( ! F_232 ( V_3 ) ) {
V_485 &= ~ V_489 ;
V_485 |= V_490 ;
} else if ( ! ( V_462 & V_489 ) ) {
V_485 &= ~ V_489 ;
}
}
F_76 ( V_427 , V_462 ) ;
F_76 ( V_425 , V_485 ) ;
return 0 ;
}
static void F_242 ( struct V_2 * V_3 ,
struct V_491 * V_492 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_411 * V_412 ;
T_2 V_106 ;
if ( V_58 -> V_115 . V_116
&& ( V_92 == V_493 || V_92 == V_429
|| V_92 == V_430 || V_92 == V_432
|| V_92 == V_431 )
&& ! V_428 ) {
switch ( V_92 ) {
case V_493 : V_412 = & V_58 -> V_115 . V_172 ; break;
case V_429 : V_412 = & V_58 -> V_115 . V_186 ; break;
case V_430 : V_412 = & V_58 -> V_115 . V_184 ; break;
case V_432 : V_412 = & V_58 -> V_115 . V_177 ; break;
case V_431 : V_412 = & V_58 -> V_115 . V_181 ; break;
default: F_243 () ;
}
V_492 -> V_99 = V_412 -> V_99 ;
V_492 -> V_102 = V_412 -> V_102 ;
V_492 -> V_104 = V_412 -> V_104 ;
V_106 = V_412 -> V_106 ;
if ( V_92 == V_493
|| V_492 -> V_99 == F_85 ( V_58 , V_92 ) )
goto V_494;
}
V_492 -> V_102 = F_86 ( V_58 , V_92 ) ;
V_492 -> V_104 = F_87 ( V_58 , V_92 ) ;
V_492 -> V_99 = F_85 ( V_58 , V_92 ) ;
V_106 = F_88 ( V_58 , V_92 ) ;
V_494:
if ( ( V_106 & V_495 ) && ! V_428 )
V_106 = 0 ;
V_492 -> type = V_106 & 15 ;
V_492 -> V_169 = ( V_106 >> 4 ) & 1 ;
V_492 -> V_416 = ( V_106 >> 5 ) & 3 ;
V_492 -> V_496 = ( V_106 >> 7 ) & 1 ;
V_492 -> V_497 = ( V_106 >> 12 ) & 1 ;
V_492 -> V_498 = ( V_106 >> 13 ) & 1 ;
V_492 -> V_499 = ( V_106 >> 14 ) & 1 ;
V_492 -> V_500 = ( V_106 >> 15 ) & 1 ;
V_492 -> V_501 = ( V_106 >> 16 ) & 1 ;
}
static T_5 F_244 ( struct V_2 * V_3 , int V_92 )
{
struct V_491 V_169 ;
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
&& ( F_247 ( V_3 ) & V_229 ) )
return 3 ;
return F_85 ( F_1 ( V_3 ) , V_502 ) & 3 ;
}
static int F_248 ( struct V_2 * V_3 )
{
if ( ! F_136 ( V_227 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ) {
F_137 ( V_227 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
F_1 ( V_3 ) -> V_503 = F_245 ( V_3 ) ;
}
return F_1 ( V_3 ) -> V_503 ;
}
static T_2 F_249 ( struct V_491 * V_492 )
{
T_2 V_106 ;
if ( V_492 -> V_501 )
V_106 = 1 << 16 ;
else {
V_106 = V_492 -> type & 15 ;
V_106 |= ( V_492 -> V_169 & 1 ) << 4 ;
V_106 |= ( V_492 -> V_416 & 3 ) << 5 ;
V_106 |= ( V_492 -> V_496 & 1 ) << 7 ;
V_106 |= ( V_492 -> V_497 & 1 ) << 12 ;
V_106 |= ( V_492 -> V_498 & 1 ) << 13 ;
V_106 |= ( V_492 -> V_499 & 1 ) << 14 ;
V_106 |= ( V_492 -> V_500 & 1 ) << 15 ;
}
if ( V_106 == 0 )
V_106 = V_495 ;
return V_106 ;
}
static void F_250 ( struct V_2 * V_3 ,
struct V_491 * V_492 , int V_92 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_413 * V_414 = & V_101 [ V_92 ] ;
T_2 V_106 ;
F_83 ( V_58 ) ;
if ( V_58 -> V_115 . V_116 && V_92 == V_493 ) {
F_78 ( V_414 -> V_99 , V_492 -> V_99 ) ;
V_58 -> V_115 . V_172 . V_99 = V_492 -> V_99 ;
V_58 -> V_115 . V_172 . V_102 = V_492 -> V_102 ;
V_58 -> V_115 . V_172 . V_104 = V_492 -> V_104 ;
V_58 -> V_115 . V_172 . V_106 = F_249 ( V_492 ) ;
return;
}
F_76 ( V_414 -> V_102 , V_492 -> V_102 ) ;
F_79 ( V_414 -> V_104 , V_492 -> V_104 ) ;
F_78 ( V_414 -> V_99 , V_492 -> V_99 ) ;
if ( V_58 -> V_115 . V_116 && V_492 -> V_169 ) {
if ( V_492 -> V_102 == 0xffff0000 && V_492 -> V_99 == 0xf000 )
F_76 ( V_414 -> V_102 , 0xf0000 ) ;
V_106 = 0xf3 ;
} else
V_106 = F_249 ( V_492 ) ;
if ( V_407 && ( V_92 != V_504 ) )
V_106 |= 0x1 ;
F_79 ( V_414 -> V_108 , V_106 ) ;
F_139 ( V_227 , ( T_9 * ) & V_3 -> V_95 . V_96 ) ;
}
static void F_251 ( struct V_2 * V_3 , int * V_499 , int * V_498 )
{
T_2 V_106 = F_88 ( F_1 ( V_3 ) , V_502 ) ;
* V_499 = ( V_106 >> 14 ) & 1 ;
* V_498 = ( V_106 >> 13 ) & 1 ;
}
static void F_252 ( struct V_2 * V_3 , struct V_148 * V_505 )
{
V_505 -> V_394 = F_71 ( V_506 ) ;
V_505 -> V_153 = F_69 ( V_507 ) ;
}
static void F_253 ( struct V_2 * V_3 , struct V_148 * V_505 )
{
F_79 ( V_506 , V_505 -> V_394 ) ;
F_76 ( V_507 , V_505 -> V_153 ) ;
}
static void F_254 ( struct V_2 * V_3 , struct V_148 * V_505 )
{
V_505 -> V_394 = F_71 ( V_508 ) ;
V_505 -> V_153 = F_69 ( V_509 ) ;
}
static void F_255 ( struct V_2 * V_3 , struct V_148 * V_505 )
{
F_79 ( V_508 , V_505 -> V_394 ) ;
F_76 ( V_509 , V_505 -> V_153 ) ;
}
static bool F_256 ( struct V_2 * V_3 , int V_92 )
{
struct V_491 V_492 ;
T_2 V_106 ;
F_242 ( V_3 , & V_492 , V_92 ) ;
V_106 = F_249 ( & V_492 ) ;
if ( V_492 . V_102 != ( V_492 . V_99 << 4 ) )
return false ;
if ( V_492 . V_104 != 0xffff )
return false ;
if ( V_106 != 0xf3 )
return false ;
return true ;
}
static bool F_257 ( struct V_2 * V_3 )
{
struct V_491 V_510 ;
unsigned int V_511 ;
F_242 ( V_3 , & V_510 , V_502 ) ;
V_511 = V_510 . V_99 & V_417 ;
if ( V_510 . V_501 )
return false ;
if ( ~ V_510 . type & ( V_512 | V_513 ) )
return false ;
if ( ! V_510 . V_169 )
return false ;
if ( V_510 . type & V_514 ) {
if ( V_510 . V_416 > V_511 )
return false ;
} else {
if ( V_510 . V_416 != V_511 )
return false ;
}
if ( ! V_510 . V_496 )
return false ;
return true ;
}
static bool F_258 ( struct V_2 * V_3 )
{
struct V_491 V_515 ;
unsigned int V_516 ;
F_242 ( V_3 , & V_515 , V_517 ) ;
V_516 = V_515 . V_99 & V_417 ;
if ( V_515 . V_501 )
return true ;
if ( V_515 . type != 3 && V_515 . type != 7 )
return false ;
if ( ! V_515 . V_169 )
return false ;
if ( V_515 . V_416 != V_516 )
return false ;
if ( ! V_515 . V_496 )
return false ;
return true ;
}
static bool F_259 ( struct V_2 * V_3 , int V_92 )
{
struct V_491 V_492 ;
unsigned int V_518 ;
F_242 ( V_3 , & V_492 , V_92 ) ;
V_518 = V_492 . V_99 & V_417 ;
if ( V_492 . V_501 )
return true ;
if ( ! V_492 . V_169 )
return false ;
if ( ! V_492 . V_496 )
return false ;
if ( ~ V_492 . type & ( V_512 | V_514 ) ) {
if ( V_492 . V_416 < V_518 )
return false ;
}
return true ;
}
static bool F_260 ( struct V_2 * V_3 )
{
struct V_491 V_172 ;
F_242 ( V_3 , & V_172 , V_493 ) ;
if ( V_172 . V_501 )
return false ;
if ( V_172 . V_99 & V_519 )
return false ;
if ( V_172 . type != 3 && V_172 . type != 11 )
return false ;
if ( ! V_172 . V_496 )
return false ;
return true ;
}
static bool F_261 ( struct V_2 * V_3 )
{
struct V_491 V_520 ;
F_242 ( V_3 , & V_520 , V_504 ) ;
if ( V_520 . V_501 )
return true ;
if ( V_520 . V_99 & V_519 )
return false ;
if ( V_520 . type != 2 )
return false ;
if ( ! V_520 . V_496 )
return false ;
return true ;
}
static bool F_262 ( struct V_2 * V_3 )
{
struct V_491 V_510 , V_515 ;
F_242 ( V_3 , & V_510 , V_502 ) ;
F_242 ( V_3 , & V_515 , V_517 ) ;
return ( ( V_510 . V_99 & V_417 ) ==
( V_515 . V_99 & V_417 ) ) ;
}
static bool F_263 ( struct V_2 * V_3 )
{
if ( ! F_246 ( V_3 ) ) {
if ( ! F_256 ( V_3 , V_502 ) )
return false ;
if ( ! F_256 ( V_3 , V_517 ) )
return false ;
if ( ! F_256 ( V_3 , V_430 ) )
return false ;
if ( ! F_256 ( V_3 , V_429 ) )
return false ;
if ( ! F_256 ( V_3 , V_432 ) )
return false ;
if ( ! F_256 ( V_3 , V_431 ) )
return false ;
} else {
if ( ! F_262 ( V_3 ) )
return false ;
if ( ! F_257 ( V_3 ) )
return false ;
if ( ! F_258 ( V_3 ) )
return false ;
if ( ! F_259 ( V_3 , V_430 ) )
return false ;
if ( ! F_259 ( V_3 , V_429 ) )
return false ;
if ( ! F_259 ( V_3 , V_432 ) )
return false ;
if ( ! F_259 ( V_3 , V_431 ) )
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
T_13 V_521 ;
T_3 V_164 = 0 ;
int V_522 , V_523 , V_93 = 0 ;
V_523 = F_222 ( & V_12 -> V_444 ) ;
V_521 = F_216 ( V_12 ) >> V_13 ;
V_522 = F_265 ( V_12 , V_521 , 0 , V_393 ) ;
if ( V_522 < 0 )
goto V_524;
V_164 = V_525 + V_526 ;
V_522 = F_266 ( V_12 , V_521 ++ , & V_164 ,
V_527 , sizeof( T_3 ) ) ;
if ( V_522 < 0 )
goto V_524;
V_522 = F_265 ( V_12 , V_521 ++ , 0 , V_393 ) ;
if ( V_522 < 0 )
goto V_524;
V_522 = F_265 ( V_12 , V_521 , 0 , V_393 ) ;
if ( V_522 < 0 )
goto V_524;
V_164 = ~ 0 ;
V_522 = F_266 ( V_12 , V_521 , & V_164 ,
V_446 - 2 * V_393 - 1 ,
sizeof( T_6 ) ) ;
if ( V_522 < 0 )
goto V_524;
V_93 = 1 ;
V_524:
F_220 ( & V_12 -> V_444 , V_523 ) ;
return V_93 ;
}
static int F_267 ( struct V_12 * V_12 )
{
int V_60 , V_523 , V_522 , V_93 ;
T_14 V_528 ;
T_2 V_253 ;
if ( ! V_84 )
return 1 ;
if ( F_77 ( ! V_12 -> V_95 . V_529 ) ) {
F_54 ( V_74 L_17
L_18 ) ;
return 0 ;
}
if ( F_268 ( V_12 -> V_95 . V_530 ) )
return 1 ;
V_93 = 0 ;
V_528 = V_12 -> V_95 . V_484 >> V_13 ;
V_523 = F_222 ( & V_12 -> V_444 ) ;
V_522 = F_265 ( V_12 , V_528 , 0 , V_393 ) ;
if ( V_522 < 0 )
goto V_524;
for ( V_60 = 0 ; V_60 < V_531 ; V_60 ++ ) {
V_253 = ( V_60 << 22 ) + ( V_532 | V_533 | V_534 |
V_535 | V_536 | V_537 ) ;
V_522 = F_266 ( V_12 , V_528 ,
& V_253 , V_60 * sizeof( V_253 ) , sizeof( V_253 ) ) ;
if ( V_522 < 0 )
goto V_524;
}
V_12 -> V_95 . V_530 = true ;
V_93 = 1 ;
V_524:
F_220 ( & V_12 -> V_444 , V_523 ) ;
return V_93 ;
}
static void F_269 ( int V_92 )
{
struct V_413 * V_414 = & V_101 [ V_92 ] ;
unsigned int V_106 ;
F_78 ( V_414 -> V_99 , 0 ) ;
F_76 ( V_414 -> V_102 , 0 ) ;
F_79 ( V_414 -> V_104 , 0xffff ) ;
if ( V_407 ) {
V_106 = 0x93 ;
if ( V_92 == V_502 )
V_106 |= 0x08 ;
} else
V_106 = 0xf3 ;
F_79 ( V_414 -> V_108 , V_106 ) ;
}
static int F_270 ( struct V_12 * V_12 )
{
struct V_538 V_539 ;
int V_522 = 0 ;
F_271 ( & V_12 -> V_540 ) ;
if ( V_12 -> V_95 . V_541 )
goto V_524;
V_539 . V_441 = V_542 ;
V_539 . V_419 = 0 ;
V_539 . V_543 = 0xfee00000ULL ;
V_539 . V_544 = V_393 ;
V_522 = F_272 ( V_12 , & V_539 , 0 ) ;
if ( V_522 )
goto V_524;
V_12 -> V_95 . V_541 = F_6 ( V_12 , 0xfee00 ) ;
V_524:
F_273 ( & V_12 -> V_540 ) ;
return V_522 ;
}
static int F_274 ( struct V_12 * V_12 )
{
struct V_538 V_539 ;
int V_522 = 0 ;
F_271 ( & V_12 -> V_540 ) ;
if ( V_12 -> V_95 . V_529 )
goto V_524;
V_539 . V_441 = V_545 ;
V_539 . V_419 = 0 ;
V_539 . V_543 =
V_12 -> V_95 . V_484 ;
V_539 . V_544 = V_393 ;
V_522 = F_272 ( V_12 , & V_539 , 0 ) ;
if ( V_522 )
goto V_524;
V_12 -> V_95 . V_529 = F_6 ( V_12 ,
V_12 -> V_95 . V_484 >> V_13 ) ;
V_524:
F_273 ( & V_12 -> V_540 ) ;
return V_522 ;
}
static void F_275 ( struct V_1 * V_58 )
{
int V_42 ;
V_58 -> V_42 = 0 ;
if ( ! V_406 )
return;
F_276 ( & V_546 ) ;
V_42 = F_277 ( V_547 , V_548 ) ;
if ( V_42 < V_548 ) {
V_58 -> V_42 = V_42 ;
F_137 ( V_42 , V_547 ) ;
}
F_278 ( & V_546 ) ;
}
static void F_279 ( struct V_1 * V_58 )
{
if ( ! V_406 )
return;
F_276 ( & V_546 ) ;
if ( V_58 -> V_42 != 0 )
F_139 ( V_58 -> V_42 , V_547 ) ;
F_278 ( & V_546 ) ;
}
static void F_280 ( unsigned long * V_254 , T_2 V_59 )
{
int V_549 = sizeof( unsigned long ) ;
if ( ! F_17 () )
return;
if ( V_59 <= 0x1fff ) {
F_139 ( V_59 , V_254 + 0x000 / V_549 ) ;
F_139 ( V_59 , V_254 + 0x800 / V_549 ) ;
} else if ( ( V_59 >= 0xc0000000 ) && ( V_59 <= 0xc0001fff ) ) {
V_59 &= 0x1fff ;
F_139 ( V_59 , V_254 + 0x400 / V_549 ) ;
F_139 ( V_59 , V_254 + 0xc00 / V_549 ) ;
}
}
static void F_281 ( T_2 V_59 , bool V_550 )
{
if ( ! V_550 )
F_280 ( V_262 , V_59 ) ;
F_280 ( V_261 , V_59 ) ;
}
static void F_282 ( void )
{
T_2 V_551 , V_552 ;
unsigned long V_553 ;
struct V_148 V_505 ;
F_76 ( V_554 , F_283 () | V_210 ) ;
F_76 ( V_555 , F_187 () ) ;
F_76 ( V_556 , F_284 () ) ;
F_78 ( V_557 , V_558 ) ;
#ifdef F_73
F_78 ( V_559 , 0 ) ;
F_78 ( V_560 , 0 ) ;
#else
F_78 ( V_559 , V_561 ) ;
F_78 ( V_560 , V_561 ) ;
#endif
F_78 ( V_562 , V_561 ) ;
F_78 ( V_563 , V_154 * 8 ) ;
F_285 ( & V_505 ) ;
F_76 ( V_564 , V_505 . V_153 ) ;
asm("mov $.Lkvm_vmx_return, %0" : "=r"(tmpl));
F_76 ( V_565 , V_553 ) ;
F_166 ( V_342 , V_551 , V_552 ) ;
F_79 ( V_566 , V_551 ) ;
F_107 ( V_344 , V_553 ) ;
F_76 ( V_567 , V_553 ) ;
if ( V_24 . V_397 & V_392 ) {
F_166 ( V_347 , V_551 , V_552 ) ;
F_80 ( V_568 , V_551 | ( ( T_5 ) V_552 << 32 ) ) ;
}
}
static void F_286 ( struct V_1 * V_58 )
{
V_58 -> V_3 . V_95 . V_461 = V_569 ;
if ( V_84 )
V_58 -> V_3 . V_95 . V_461 |= V_570 ;
if ( F_90 ( & V_58 -> V_3 ) )
V_58 -> V_3 . V_95 . V_461 &=
~ F_4 ( & V_58 -> V_3 ) -> V_219 ;
F_76 ( V_571 , ~ V_58 -> V_3 . V_95 . V_461 ) ;
}
static T_2 F_287 ( struct V_1 * V_58 )
{
T_2 V_572 = V_24 . V_25 ;
if ( ! F_19 ( V_58 -> V_3 . V_12 ) ) {
V_572 &= ~ V_27 ;
#ifdef F_73
V_572 |= V_303 |
V_302 ;
#endif
}
if ( ! V_84 )
V_572 |= V_301 |
V_300 |
V_298 ;
return V_572 ;
}
static T_2 F_288 ( struct V_1 * V_58 )
{
T_2 V_572 = V_24 . V_29 ;
if ( ! F_38 ( V_58 -> V_3 . V_12 ) )
V_572 &= ~ V_30 ;
if ( V_58 -> V_42 == 0 )
V_572 &= ~ V_49 ;
if ( ! V_84 ) {
V_572 &= ~ V_45 ;
V_407 = 0 ;
}
if ( ! V_407 )
V_572 &= ~ V_46 ;
if ( ! V_410 )
V_572 &= ~ V_47 ;
return V_572 ;
}
static void F_289 ( void )
{
F_290 ( 0xffull << 49 | 0x6ull ) ;
}
static int F_291 ( struct V_1 * V_58 )
{
#ifdef F_73
unsigned long V_573 ;
#endif
int V_60 ;
F_80 ( V_574 , F_53 ( V_575 ) ) ;
F_80 ( V_576 , F_53 ( V_577 ) ) ;
if ( F_17 () )
F_80 ( V_263 , F_53 ( V_262 ) ) ;
F_80 ( V_578 , - 1ull ) ;
F_79 ( V_579 ,
V_24 . V_51 ) ;
F_79 ( V_471 , F_287 ( V_58 ) ) ;
if ( F_21 () ) {
F_79 ( V_580 ,
F_288 ( V_58 ) ) ;
}
if ( V_410 ) {
F_79 ( V_581 , V_410 ) ;
F_79 ( V_582 , V_583 ) ;
}
F_79 ( V_584 , 0 ) ;
F_79 ( V_585 , 0 ) ;
F_79 ( V_586 , 0 ) ;
F_78 ( V_179 , 0 ) ;
F_78 ( V_183 , 0 ) ;
F_282 () ;
#ifdef F_73
F_107 ( V_189 , V_573 ) ;
F_76 ( V_188 , V_573 ) ;
F_107 ( V_191 , V_573 ) ;
F_76 ( V_190 , V_573 ) ;
#else
F_76 ( V_188 , 0 ) ;
F_76 ( V_190 , 0 ) ;
#endif
F_79 ( V_587 , 0 ) ;
F_79 ( V_137 , 0 ) ;
F_80 ( V_588 , F_53 ( V_58 -> V_123 . V_135 ) ) ;
F_79 ( V_136 , 0 ) ;
F_80 ( V_589 , F_53 ( V_58 -> V_123 . V_134 ) ) ;
if ( V_24 . V_348 & V_291 ) {
T_2 V_590 , V_591 ;
T_5 V_592 ;
F_166 ( V_347 , V_590 , V_591 ) ;
V_592 = V_590 | ( ( T_5 ) V_591 << 32 ) ;
F_80 ( V_349 , V_592 ) ;
V_58 -> V_3 . V_95 . V_350 = V_592 ;
}
for ( V_60 = 0 ; V_60 < V_593 ; ++ V_60 ) {
T_2 V_64 = V_62 [ V_60 ] ;
T_2 V_594 , V_595 ;
int V_596 = V_58 -> V_61 ;
if ( F_292 ( V_64 , & V_594 , & V_595 ) < 0 )
continue;
if ( F_293 ( V_64 , V_594 , V_595 ) < 0 )
continue;
V_58 -> V_63 [ V_596 ] . V_64 = V_60 ;
V_58 -> V_63 [ V_596 ] . V_164 = 0 ;
V_58 -> V_63 [ V_596 ] . V_89 = - 1ull ;
++ V_58 -> V_61 ;
}
F_79 ( V_122 , V_24 . V_397 ) ;
F_79 ( V_121 , V_24 . V_348 ) ;
F_76 ( V_214 , ~ 0UL ) ;
F_286 ( V_58 ) ;
F_178 ( & V_58 -> V_3 , 0 ) ;
return 0 ;
}
static int F_294 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_5 V_59 ;
int V_93 ;
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_356 ) | ( 1 << V_353 ) ) ;
V_58 -> V_115 . V_116 = 0 ;
V_58 -> V_597 = 0 ;
V_58 -> V_3 . V_95 . V_354 [ V_598 ] = F_295 () ;
F_296 ( & V_58 -> V_3 , 0 ) ;
V_59 = 0xfee00000 | V_599 ;
if ( F_297 ( & V_58 -> V_3 ) )
V_59 |= V_600 ;
F_298 ( & V_58 -> V_3 , V_59 ) ;
V_93 = F_299 ( & V_58 -> V_3 ) ;
if ( V_93 != 0 )
goto V_524;
F_83 ( V_58 ) ;
F_269 ( V_502 ) ;
if ( F_297 ( & V_58 -> V_3 ) ) {
F_78 ( V_435 , 0xf000 ) ;
F_76 ( V_451 , 0x000f0000 ) ;
} else {
F_78 ( V_435 , V_58 -> V_3 . V_95 . V_601 << 8 ) ;
F_76 ( V_451 , V_58 -> V_3 . V_95 . V_601 << 12 ) ;
}
F_269 ( V_430 ) ;
F_269 ( V_429 ) ;
F_269 ( V_432 ) ;
F_269 ( V_431 ) ;
F_269 ( V_517 ) ;
F_78 ( V_421 , 0 ) ;
F_76 ( V_422 , 0 ) ;
F_79 ( V_423 , 0xffff ) ;
F_79 ( V_424 , 0x008b ) ;
F_78 ( V_602 , 0 ) ;
F_76 ( V_603 , 0 ) ;
F_79 ( V_604 , 0xffff ) ;
F_79 ( V_605 , 0x00082 ) ;
F_79 ( V_343 , 0 ) ;
F_76 ( V_346 , 0 ) ;
F_76 ( V_345 , 0 ) ;
F_76 ( V_225 , 0x02 ) ;
if ( F_297 ( & V_58 -> V_3 ) )
F_144 ( V_3 , 0xfff0 ) ;
else
F_144 ( V_3 , 0 ) ;
F_300 ( V_3 , V_353 , 0 ) ;
F_76 ( V_362 , 0x400 ) ;
F_76 ( V_509 , 0 ) ;
F_79 ( V_508 , 0xffff ) ;
F_76 ( V_507 , 0 ) ;
F_79 ( V_506 , 0xffff ) ;
F_79 ( V_606 , V_607 ) ;
F_79 ( V_231 , 0 ) ;
F_79 ( V_608 , 0 ) ;
F_80 ( V_609 , 0 ) ;
F_152 ( V_58 ) ;
F_79 ( V_250 , 0 ) ;
if ( F_18 () ) {
F_80 ( V_610 , 0 ) ;
if ( F_19 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_610 ,
F_53 ( V_58 -> V_3 . V_95 . V_611 -> V_354 ) ) ;
F_79 ( V_612 , 0 ) ;
}
if ( F_38 ( V_58 -> V_3 . V_12 ) )
F_80 ( V_613 ,
F_301 ( V_58 -> V_3 . V_12 -> V_95 . V_541 ) ) ;
if ( V_58 -> V_42 != 0 )
F_78 ( V_614 , V_58 -> V_42 ) ;
V_58 -> V_3 . V_95 . V_208 = V_615 | V_616 | V_617 ;
V_3 -> V_445 = F_222 ( & V_3 -> V_12 -> V_444 ) ;
F_239 ( & V_58 -> V_3 , F_302 ( V_3 ) ) ;
F_220 ( & V_3 -> V_12 -> V_444 , V_3 -> V_445 ) ;
F_237 ( & V_58 -> V_3 , 0 ) ;
F_224 ( & V_58 -> V_3 , 0 ) ;
F_129 ( & V_58 -> V_3 ) ;
F_89 ( & V_58 -> V_3 ) ;
F_65 ( V_58 ) ;
V_93 = 0 ;
V_58 -> V_420 = 0 ;
V_524:
return V_93 ;
}
static bool F_303 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) -> V_57 &
V_283 ;
}
static void F_304 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( F_90 ( V_3 ) && F_303 ( V_3 ) ) {
F_123 ( V_618 , V_3 ) ;
return;
}
V_55 = F_71 ( V_471 ) ;
V_55 |= V_296 ;
F_79 ( V_471 , V_55 ) ;
}
static void F_305 ( struct V_2 * V_3 )
{
T_2 V_55 ;
if ( ! F_41 () ) {
F_304 ( V_3 ) ;
return;
}
if ( F_71 ( V_231 ) & V_232 ) {
F_304 ( V_3 ) ;
return;
}
V_55 = F_71 ( V_471 ) ;
V_55 |= V_619 ;
F_79 ( V_471 , V_55 ) ;
}
static void F_306 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_15 V_620 ;
int V_621 = V_3 -> V_95 . V_622 . V_133 ;
F_307 ( V_621 ) ;
++ V_3 -> V_196 . V_623 ;
if ( V_58 -> V_115 . V_116 ) {
int V_244 = 0 ;
if ( V_3 -> V_95 . V_622 . V_624 )
V_244 = V_3 -> V_95 . V_245 ;
if ( F_149 ( V_3 , V_621 , V_244 ) != V_246 )
F_123 ( V_247 , V_3 ) ;
return;
}
V_620 = V_621 | V_17 ;
if ( V_3 -> V_95 . V_622 . V_624 ) {
V_620 |= V_625 ;
F_79 ( V_248 ,
V_58 -> V_3 . V_95 . V_245 ) ;
} else
V_620 |= V_22 ;
F_79 ( V_250 , V_620 ) ;
}
static void F_308 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) )
return;
if ( ! F_41 () ) {
V_58 -> V_597 = 1 ;
V_58 -> V_626 = 0 ;
}
++ V_3 -> V_196 . V_627 ;
V_58 -> V_628 = false ;
if ( V_58 -> V_115 . V_116 ) {
if ( F_149 ( V_3 , V_629 , 0 ) != V_246 )
F_123 ( V_247 , V_3 ) ;
return;
}
F_79 ( V_250 ,
V_630 | V_17 | V_629 ) ;
}
static int F_309 ( struct V_2 * V_3 )
{
if ( ! F_41 () && F_1 ( V_3 ) -> V_597 )
return 0 ;
return ! ( F_71 ( V_231 ) &
( V_234 | V_232
| V_631 ) ) ;
}
static bool F_310 ( struct V_2 * V_3 )
{
if ( ! F_41 () )
return F_1 ( V_3 ) -> V_597 ;
if ( F_1 ( V_3 ) -> V_628 )
return false ;
return F_71 ( V_231 ) & V_631 ;
}
static void F_311 ( struct V_2 * V_3 , bool V_632 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_41 () ) {
if ( V_58 -> V_597 != V_632 ) {
V_58 -> V_597 = V_632 ;
V_58 -> V_626 = 0 ;
}
} else {
V_58 -> V_628 = ! V_632 ;
if ( V_632 )
F_82 ( V_231 ,
V_631 ) ;
else
F_81 ( V_231 ,
V_631 ) ;
}
}
static int F_312 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) && F_303 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( F_1 ( V_3 ) -> V_8 . V_633 ||
( V_7 -> V_634 &
V_635 ) )
return 0 ;
F_146 ( V_3 ) ;
V_7 -> V_636 = V_637 ;
V_7 -> V_638 = 0 ;
}
return ( F_69 ( V_225 ) & V_639 ) &&
! ( F_71 ( V_231 ) &
( V_232 | V_234 ) ) ;
}
static int F_221 ( struct V_12 * V_12 , unsigned int V_11 )
{
int V_93 ;
struct V_538 V_640 = {
. V_441 = V_641 ,
. V_543 = V_11 ,
. V_544 = V_393 * 3 ,
. V_419 = 0 ,
} ;
V_93 = F_313 ( V_12 , & V_640 , 0 ) ;
if ( V_93 )
return V_93 ;
V_12 -> V_95 . V_437 = V_11 ;
if ( ! F_264 ( V_12 ) )
return - V_404 ;
return 0 ;
}
static int F_314 ( struct V_2 * V_3 ,
int V_642 , T_2 V_643 )
{
if ( ( ( V_642 == V_319 ) || ( V_642 == V_644 ) ) && V_643 == 0 )
if ( F_315 ( V_3 , 0 ) == V_246 )
return 1 ;
switch ( V_642 ) {
case V_110 :
if ( V_3 -> V_111 &
( V_645 | V_361 ) )
return 0 ;
F_316 ( V_3 , V_642 ) ;
return 1 ;
case V_114 :
F_1 ( V_3 ) -> V_3 . V_95 . V_245 =
F_71 ( V_238 ) ;
if ( V_3 -> V_111 & V_113 )
return 0 ;
case V_646 :
case V_647 :
case V_648 :
case V_21 :
case V_649 :
case V_644 :
case V_319 :
case V_650 :
F_316 ( V_3 , V_642 ) ;
return 1 ;
}
return 0 ;
}
static void F_317 ( void )
{
#if F_318 ( V_651 ) && F_318 ( F_73 )
struct V_652 V_354 = {
. V_510 = 3 ,
. V_419 = V_639 ,
} ;
F_319 ( & V_354 , 0 ) ;
#endif
}
static int F_320 ( struct V_2 * V_3 )
{
return 1 ;
}
static int F_321 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_653 * V_653 = V_3 -> V_654 ;
T_2 V_14 , V_655 , V_240 ;
unsigned long V_656 , V_237 , V_657 ;
T_2 V_658 ;
enum V_659 V_660 ;
V_658 = V_58 -> V_661 ;
V_14 = V_58 -> V_662 ;
if ( F_16 ( V_14 ) )
return F_320 ( V_3 ) ;
if ( ( V_658 & V_635 ) &&
! F_12 ( V_14 ) ) {
V_3 -> V_654 -> V_663 = V_664 ;
V_3 -> V_654 -> V_665 . V_666 = V_667 ;
V_3 -> V_654 -> V_665 . V_668 = 2 ;
V_3 -> V_654 -> V_665 . V_164 [ 0 ] = V_658 ;
V_3 -> V_654 -> V_665 . V_164 [ 1 ] = V_14 ;
return 0 ;
}
if ( ( V_14 & V_15 ) == V_630 )
return 1 ;
if ( F_13 ( V_14 ) ) {
F_129 ( V_3 ) ;
return 1 ;
}
if ( F_14 ( V_14 ) ) {
V_660 = F_315 ( V_3 , V_669 ) ;
if ( V_660 != V_246 )
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
V_240 = 0 ;
if ( V_14 & V_243 )
V_240 = F_71 ( V_670 ) ;
if ( F_12 ( V_14 ) ) {
F_322 ( V_84 ) ;
V_656 = F_69 ( V_671 ) ;
F_323 ( V_656 , V_240 ) ;
if ( F_324 ( V_3 ) )
F_325 ( V_3 , V_656 ) ;
return F_326 ( V_3 , V_656 , V_240 , NULL , 0 ) ;
}
if ( V_58 -> V_115 . V_116 &&
F_314 ( V_3 , V_14 & V_16 ,
V_240 ) ) {
if ( V_3 -> V_95 . V_672 ) {
V_3 -> V_95 . V_672 = 0 ;
return F_327 ( V_3 ) ;
}
return 1 ;
}
V_655 = V_14 & V_16 ;
switch ( V_655 ) {
case V_110 :
V_657 = F_69 ( V_671 ) ;
if ( ! ( V_3 -> V_111 &
( V_645 | V_361 ) ) ) {
V_3 -> V_95 . V_657 = V_657 | V_673 ;
F_316 ( V_3 , V_110 ) ;
return 1 ;
}
V_653 -> V_674 . V_95 . V_657 = V_657 | V_673 ;
V_653 -> V_674 . V_95 . V_364 = F_69 ( V_362 ) ;
case V_114 :
V_58 -> V_3 . V_95 . V_245 =
F_71 ( V_238 ) ;
V_653 -> V_663 = V_675 ;
V_237 = F_143 ( V_3 ) ;
V_653 -> V_674 . V_95 . V_676 = F_69 ( V_451 ) + V_237 ;
V_653 -> V_674 . V_95 . V_677 = V_655 ;
break;
default:
V_653 -> V_663 = V_678 ;
V_653 -> V_679 . V_677 = V_655 ;
V_653 -> V_679 . V_240 = V_240 ;
break;
}
return 0 ;
}
static int F_328 ( struct V_2 * V_3 )
{
++ V_3 -> V_196 . V_680 ;
return 1 ;
}
static int F_329 ( struct V_2 * V_3 )
{
V_3 -> V_654 -> V_663 = V_681 ;
return 0 ;
}
static int F_330 ( struct V_2 * V_3 )
{
unsigned long V_682 ;
int V_394 , V_683 , string ;
unsigned V_684 ;
V_682 = F_69 ( V_671 ) ;
string = ( V_682 & 16 ) != 0 ;
V_683 = ( V_682 & 8 ) != 0 ;
++ V_3 -> V_196 . V_685 ;
if ( string || V_683 )
return F_315 ( V_3 , 0 ) == V_246 ;
V_684 = V_682 >> 16 ;
V_394 = ( V_682 & 7 ) + 1 ;
F_142 ( V_3 ) ;
return F_331 ( V_3 , V_394 , V_684 ) ;
}
static void
F_332 ( struct V_2 * V_3 , unsigned char * V_686 )
{
V_686 [ 0 ] = 0x0f ;
V_686 [ 1 ] = 0x01 ;
V_686 [ 2 ] = 0xc1 ;
}
static int F_333 ( struct V_2 * V_3 , unsigned long V_687 )
{
if ( F_1 ( V_3 ) -> V_8 . V_488 &&
( ( V_687 & F_171 ) != F_171 ) )
return 1 ;
if ( F_90 ( V_3 ) ) {
if ( F_334 ( V_3 , ( V_687 & V_3 -> V_95 . V_212 ) |
( V_3 -> V_95 . V_208 & ~ V_3 -> V_95 . V_212 ) ) )
return 1 ;
F_76 ( V_221 , V_687 ) ;
return 0 ;
} else
return F_334 ( V_3 , V_687 ) ;
}
static int F_335 ( struct V_2 * V_3 , unsigned long V_687 )
{
if ( F_90 ( V_3 ) ) {
if ( F_336 ( V_3 , ( V_687 & V_3 -> V_95 . V_461 ) |
( V_3 -> V_95 . V_462 & ~ V_3 -> V_95 . V_461 ) ) )
return 1 ;
F_76 ( V_427 , V_687 ) ;
return 0 ;
} else
return F_336 ( V_3 , V_687 ) ;
}
static void F_337 ( struct V_2 * V_3 )
{
if ( F_90 ( V_3 ) ) {
F_76 ( V_221 ,
F_69 ( V_221 ) & ~ V_210 ) ;
V_3 -> V_95 . V_208 &= ~ V_210 ;
} else
F_239 ( V_3 , F_130 ( V_3 , ~ V_210 ) ) ;
}
static int F_338 ( struct V_2 * V_3 )
{
unsigned long V_682 , V_687 ;
int V_688 ;
int V_352 ;
int V_689 ;
V_682 = F_69 ( V_671 ) ;
V_688 = V_682 & 15 ;
V_352 = ( V_682 >> 8 ) & 15 ;
switch ( ( V_682 >> 4 ) & 3 ) {
case 0 :
V_687 = F_339 ( V_3 , V_352 ) ;
F_340 ( V_688 , V_687 ) ;
switch ( V_688 ) {
case 0 :
V_689 = F_333 ( V_3 , V_687 ) ;
F_341 ( V_3 , V_689 ) ;
return 1 ;
case 3 :
V_689 = F_342 ( V_3 , V_687 ) ;
F_341 ( V_3 , V_689 ) ;
return 1 ;
case 4 :
V_689 = F_335 ( V_3 , V_687 ) ;
F_341 ( V_3 , V_689 ) ;
return 1 ;
case 8 : {
T_6 V_690 = F_343 ( V_3 ) ;
T_6 V_691 = F_339 ( V_3 , V_352 ) ;
V_689 = F_296 ( V_3 , V_691 ) ;
F_341 ( V_3 , V_689 ) ;
if ( F_20 ( V_3 -> V_12 ) )
return 1 ;
if ( V_690 <= V_691 )
return 1 ;
V_3 -> V_654 -> V_663 = V_692 ;
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
switch ( V_688 ) {
case 3 :
V_687 = F_241 ( V_3 ) ;
F_300 ( V_3 , V_352 , V_687 ) ;
F_344 ( V_688 , V_687 ) ;
F_142 ( V_3 ) ;
return 1 ;
case 8 :
V_687 = F_343 ( V_3 ) ;
F_300 ( V_3 , V_352 , V_687 ) ;
F_344 ( V_688 , V_687 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
break;
case 3 :
V_687 = ( V_682 >> V_693 ) & 0x0f ;
F_340 ( 0 , ( F_302 ( V_3 ) & ~ 0xful ) | V_687 ) ;
F_345 ( V_3 , V_687 ) ;
F_142 ( V_3 ) ;
return 1 ;
default:
break;
}
V_3 -> V_654 -> V_663 = 0 ;
F_346 ( V_3 , L_19 ,
( int ) ( V_682 >> 4 ) & 3 , V_688 ) ;
return 0 ;
}
static int F_347 ( struct V_2 * V_3 )
{
unsigned long V_682 ;
int V_694 , V_352 ;
if ( ! F_348 ( V_3 , 0 ) )
return 1 ;
V_694 = F_69 ( V_362 ) ;
if ( V_694 & V_695 ) {
if ( V_3 -> V_111 & V_361 ) {
V_3 -> V_654 -> V_674 . V_95 . V_657 = V_3 -> V_95 . V_657 ;
V_3 -> V_654 -> V_674 . V_95 . V_364 = V_694 ;
V_3 -> V_654 -> V_674 . V_95 . V_676 =
F_69 ( V_451 ) +
F_69 ( V_357 ) ;
V_3 -> V_654 -> V_674 . V_95 . V_677 = V_110 ;
V_3 -> V_654 -> V_663 = V_675 ;
return 0 ;
} else {
V_3 -> V_95 . V_364 &= ~ V_695 ;
V_3 -> V_95 . V_657 |= V_696 ;
F_76 ( V_362 , V_3 -> V_95 . V_364 ) ;
F_316 ( V_3 , V_110 ) ;
return 1 ;
}
}
V_682 = F_69 ( V_671 ) ;
V_694 = V_682 & V_697 ;
V_352 = F_349 ( V_682 ) ;
if ( V_682 & V_698 ) {
unsigned long V_687 ;
if ( ! F_350 ( V_3 , V_694 , & V_687 ) )
F_300 ( V_3 , V_352 , V_687 ) ;
} else
F_351 ( V_3 , V_694 , V_3 -> V_95 . V_354 [ V_352 ] ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static void F_352 ( struct V_2 * V_3 , unsigned long V_687 )
{
F_76 ( V_362 , V_687 ) ;
}
static int F_353 ( struct V_2 * V_3 )
{
F_354 ( V_3 ) ;
return 1 ;
}
static int F_355 ( struct V_2 * V_3 )
{
T_2 V_279 = V_3 -> V_95 . V_354 [ V_699 ] ;
T_5 V_164 ;
if ( F_174 ( V_3 , V_279 , & V_164 ) ) {
F_356 ( V_279 ) ;
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_358 ( V_279 , V_164 ) ;
V_3 -> V_95 . V_354 [ V_700 ] = V_164 & - 1u ;
V_3 -> V_95 . V_354 [ V_598 ] = ( V_164 >> 32 ) & - 1u ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_359 ( struct V_2 * V_3 )
{
T_2 V_279 = V_3 -> V_95 . V_354 [ V_699 ] ;
T_5 V_164 = ( V_3 -> V_95 . V_354 [ V_700 ] & - 1u )
| ( ( T_5 ) ( V_3 -> V_95 . V_354 [ V_598 ] & - 1u ) << 32 ) ;
if ( F_176 ( V_3 , V_279 , V_164 ) != 0 ) {
F_360 ( V_279 , V_164 ) ;
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_361 ( V_279 , V_164 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_362 ( struct V_2 * V_3 )
{
F_123 ( V_701 , V_3 ) ;
return 1 ;
}
static int F_363 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_471 ) ;
V_55 &= ~ V_296 ;
F_79 ( V_471 , V_55 ) ;
F_123 ( V_701 , V_3 ) ;
++ V_3 -> V_196 . V_702 ;
if ( ! F_20 ( V_3 -> V_12 ) &&
V_3 -> V_654 -> V_703 &&
! F_364 ( V_3 ) ) {
V_3 -> V_654 -> V_663 = V_704 ;
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
unsigned long V_682 = F_69 ( V_671 ) ;
F_370 ( V_3 , V_682 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_371 ( struct V_2 * V_3 )
{
int V_689 ;
V_689 = F_372 ( V_3 ) ;
F_341 ( V_3 , V_689 ) ;
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
T_5 V_705 = F_376 ( V_3 ) ;
T_2 V_64 = F_339 ( V_3 , V_699 ) ;
if ( F_377 ( V_3 , V_64 , V_705 ) == 0 )
F_142 ( V_3 ) ;
return 1 ;
}
static int F_378 ( struct V_2 * V_3 )
{
if ( F_268 ( V_706 ) ) {
unsigned long V_682 = F_69 ( V_671 ) ;
int V_707 , V_273 ;
V_707 = V_682 & V_708 ;
V_273 = V_682 & V_709 ;
if ( ( V_707 == V_710 ) &&
( V_273 == V_711 ) ) {
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
unsigned long V_682 ;
bool V_239 = false ;
T_2 V_240 = 0 ;
T_3 V_712 ;
int V_713 , type , V_714 , V_715 ;
V_714 = ( V_58 -> V_661 & V_635 ) ;
V_715 = ( V_58 -> V_661 & V_716 ) ;
type = ( V_58 -> V_661 & V_717 ) ;
V_682 = F_69 ( V_671 ) ;
V_713 = ( T_2 ) V_682 >> 30 ;
if ( V_713 == V_718 && V_714 ) {
switch ( type ) {
case V_630 :
V_3 -> V_95 . V_719 = false ;
F_311 ( V_3 , true ) ;
break;
case V_22 :
case V_625 :
F_381 ( V_3 ) ;
break;
case V_18 :
if ( V_58 -> V_661 &
V_720 ) {
V_239 = true ;
V_240 =
F_71 ( V_721 ) ;
}
case V_249 :
F_382 ( V_3 ) ;
break;
default:
break;
}
}
V_712 = V_682 ;
if ( ! V_714 || ( type != V_18 &&
type != V_22 &&
type != V_630 ) )
F_142 ( V_3 ) ;
if ( F_383 ( V_3 , V_712 ,
type == V_625 ? V_715 : - 1 , V_713 ,
V_239 , V_240 ) == V_722 ) {
V_3 -> V_654 -> V_663 = V_664 ;
V_3 -> V_654 -> V_665 . V_666 = V_723 ;
V_3 -> V_654 -> V_665 . V_668 = 0 ;
return 0 ;
}
F_76 ( V_362 , F_69 ( V_362 ) & ~ 55 ) ;
return 1 ;
}
static int F_384 ( struct V_2 * V_3 )
{
unsigned long V_682 ;
T_1 V_70 ;
int V_724 ;
V_682 = F_69 ( V_671 ) ;
if ( V_682 & ( 1 << 6 ) ) {
F_54 ( V_74 L_20 ) ;
return - V_338 ;
}
V_724 = ( V_682 >> 7 ) & 0x3 ;
if ( V_724 != 0x3 && V_724 != 0x1 && V_724 != 0 ) {
F_54 ( V_74 L_21 ) ;
F_54 ( V_74 L_22 ,
( long unsigned int ) F_72 ( V_725 ) ,
F_69 ( V_726 ) ) ;
F_54 ( V_74 L_23 ,
( long unsigned int ) V_682 ) ;
V_3 -> V_654 -> V_663 = V_727 ;
V_3 -> V_654 -> V_728 . V_729 = V_730 ;
return 0 ;
}
V_70 = F_72 ( V_725 ) ;
F_323 ( V_70 , V_682 ) ;
return F_326 ( V_3 , V_70 , V_682 & 0x3 , NULL , 0 ) ;
}
static T_5 F_385 ( T_5 V_731 , int V_732 )
{
int V_60 ;
T_5 V_89 = 0 ;
for ( V_60 = 51 ; V_60 > V_398 . V_733 ; V_60 -- )
V_89 |= ( 1ULL << V_60 ) ;
if ( V_732 > 2 )
V_89 |= 0xf8 ;
else if ( V_732 == 2 ) {
if ( V_731 & ( 1ULL << 7 ) )
V_89 |= 0x1ff000 ;
else
V_89 |= 0x78 ;
}
return V_89 ;
}
static void F_386 ( struct V_2 * V_3 , T_5 V_731 ,
int V_732 )
{
F_54 ( V_74 L_24 , V_455 , V_731 , V_732 ) ;
F_387 ( ( V_731 & 0x7 ) == 0x2 ) ;
F_387 ( ( V_731 & 0x7 ) == 0x6 ) ;
if ( ! F_24 () )
F_387 ( ( V_731 & 0x7 ) == 0x4 ) ;
if ( ( V_731 & 0x7 ) ) {
T_5 V_734 = V_731 & F_385 ( V_731 , V_732 ) ;
if ( V_734 != 0 ) {
F_54 ( V_74 L_25 ,
V_455 , V_734 ) ;
F_387 ( 1 ) ;
}
if ( V_732 == 1 || ( V_732 == 2 && ( V_731 & ( 1ULL << 7 ) ) ) ) {
T_5 V_735 = ( V_731 & 0x38 ) >> 3 ;
if ( V_735 == 2 || V_735 == 3 ||
V_735 == 7 ) {
F_54 ( V_74 L_26 ,
V_455 , V_735 ) ;
F_387 ( 1 ) ;
}
}
}
}
static int F_388 ( struct V_2 * V_3 )
{
T_5 V_736 [ 4 ] ;
int V_737 , V_60 , V_93 ;
T_1 V_70 ;
V_70 = F_72 ( V_725 ) ;
V_93 = F_389 ( V_3 , V_70 , true ) ;
if ( F_268 ( V_93 == 1 ) )
return F_390 ( V_3 , V_70 , 0 , NULL , 0 ) ==
V_246 ;
if ( F_77 ( ! V_93 ) )
return 1 ;
F_54 ( V_74 L_27 ) ;
F_54 ( V_74 L_28 , V_70 ) ;
V_737 = F_391 ( V_3 , V_70 , V_736 ) ;
for ( V_60 = V_738 ; V_60 > V_738 - V_737 ; -- V_60 )
F_386 ( V_3 , V_736 [ V_60 - 1 ] , V_60 ) ;
V_3 -> V_654 -> V_663 = V_727 ;
V_3 -> V_654 -> V_728 . V_729 = V_739 ;
return 0 ;
}
static int F_392 ( struct V_2 * V_3 )
{
T_2 V_55 ;
V_55 = F_71 ( V_471 ) ;
V_55 &= ~ V_619 ;
F_79 ( V_471 , V_55 ) ;
++ V_3 -> V_196 . V_740 ;
F_123 ( V_701 , V_3 ) ;
return 1 ;
}
static int F_393 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
enum V_659 V_689 = V_246 ;
int V_93 = 1 ;
T_2 V_741 ;
bool V_742 ;
V_741 = F_71 ( V_471 ) ;
V_742 = V_741 & V_296 ;
while ( ! F_263 ( V_3 ) ) {
if ( V_742
&& ( F_247 ( & V_58 -> V_3 ) & V_639 ) )
return F_363 ( & V_58 -> V_3 ) ;
V_689 = F_315 ( V_3 , 0 ) ;
if ( V_689 == V_743 ) {
V_93 = 0 ;
goto V_524;
}
if ( V_689 != V_246 )
return 0 ;
if ( F_394 ( V_744 ) )
goto V_524;
if ( F_395 () )
F_396 () ;
}
V_58 -> V_420 = 0 ;
V_524:
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
struct V_745 * V_746 ;
F_401 (item, &vmx->nested.vmcs02_pool, list)
if ( V_746 -> V_747 == V_58 -> V_8 . V_748 ) {
F_402 ( & V_746 -> V_749 , & V_58 -> V_8 . V_750 ) ;
return & V_746 -> V_751 ;
}
if ( V_58 -> V_8 . V_752 >= F_403 ( V_753 , 1 ) ) {
V_746 = F_404 ( V_58 -> V_8 . V_750 . V_754 ,
struct V_745 , V_749 ) ;
V_746 -> V_747 = V_58 -> V_8 . V_748 ;
F_402 ( & V_746 -> V_749 , & V_58 -> V_8 . V_750 ) ;
return & V_746 -> V_751 ;
}
V_746 = (struct V_745 * )
F_405 ( sizeof( struct V_745 ) , V_403 ) ;
if ( ! V_746 )
return NULL ;
V_746 -> V_751 . V_72 = F_202 () ;
if ( ! V_746 -> V_751 . V_72 ) {
F_406 ( V_746 ) ;
return NULL ;
}
F_55 ( & V_746 -> V_751 ) ;
V_746 -> V_747 = V_58 -> V_8 . V_748 ;
F_125 ( & ( V_746 -> V_749 ) , & ( V_58 -> V_8 . V_750 ) ) ;
V_58 -> V_8 . V_752 ++ ;
return & V_746 -> V_751 ;
}
static void F_407 ( struct V_1 * V_58 , T_1 V_747 )
{
struct V_745 * V_746 ;
F_401 (item, &vmx->nested.vmcs02_pool, list)
if ( V_746 -> V_747 == V_747 ) {
F_205 ( & V_746 -> V_751 ) ;
F_60 ( & V_746 -> V_749 ) ;
F_406 ( V_746 ) ;
V_58 -> V_8 . V_752 -- ;
return;
}
}
static void F_408 ( struct V_1 * V_58 )
{
struct V_745 * V_746 , * V_373 ;
F_192 (item, n, &vmx->nested.vmcs02_pool, list) {
if ( V_58 -> V_75 != & V_746 -> V_751 )
F_205 ( & V_746 -> V_751 ) ;
F_60 ( & V_746 -> V_749 ) ;
F_406 ( V_746 ) ;
}
V_58 -> V_8 . V_752 = 0 ;
if ( V_58 -> V_75 != & V_58 -> V_755 )
F_205 ( & V_58 -> V_755 ) ;
}
static int F_409 ( struct V_2 * V_3 )
{
struct V_491 V_510 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! F_410 ( V_3 , V_371 ) ||
! F_130 ( V_3 , V_477 ) ||
( F_135 ( V_3 ) & V_229 ) ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
F_242 ( V_3 , & V_510 , V_502 ) ;
if ( F_108 ( V_3 ) && ! V_510 . V_498 ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
if ( F_248 ( V_3 ) ) {
F_357 ( V_3 , 0 ) ;
return 1 ;
}
F_188 ( & ( V_58 -> V_8 . V_750 ) ) ;
V_58 -> V_8 . V_752 = 0 ;
V_58 -> V_8 . V_488 = true ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_411 ( struct V_2 * V_3 )
{
struct V_491 V_510 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( ! V_58 -> V_8 . V_488 ) {
F_316 ( V_3 , V_21 ) ;
return 0 ;
}
F_242 ( V_3 , & V_510 , V_502 ) ;
if ( ( F_135 ( V_3 ) & V_229 ) ||
( F_108 ( V_3 ) && ! V_510 . V_498 ) ) {
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
if ( ! V_58 -> V_8 . V_488 )
return;
V_58 -> V_8 . V_488 = false ;
if ( V_58 -> V_8 . V_748 != - 1ull ) {
F_413 ( V_58 -> V_8 . V_756 ) ;
F_9 ( V_58 -> V_8 . V_756 ) ;
V_58 -> V_8 . V_748 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
if ( V_58 -> V_8 . V_541 ) {
F_9 ( V_58 -> V_8 . V_541 ) ;
V_58 -> V_8 . V_541 = 0 ;
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
unsigned long V_682 ,
T_2 V_757 , T_4 * V_93 )
{
int V_758 = V_757 & 3 ;
int V_759 = ( V_757 >> 7 ) & 7 ;
bool V_760 = V_757 & ( 1u << 10 ) ;
int V_761 = ( V_757 >> 15 ) & 7 ;
int V_762 = ( V_757 >> 18 ) & 0xf ;
bool V_763 = ! ( V_757 & ( 1u << 22 ) ) ;
int V_764 = ( V_757 >> 23 ) & 0xf ;
bool V_765 = ! ( V_757 & ( 1u << 27 ) ) ;
if ( V_760 ) {
F_316 ( V_3 , V_21 ) ;
return 1 ;
}
* V_93 = F_244 ( V_3 , V_761 ) ;
if ( V_765 )
* V_93 += F_339 ( V_3 , V_764 ) ;
if ( V_763 )
* V_93 += F_339 ( V_3 , V_762 ) << V_758 ;
* V_93 += V_682 ;
if ( V_759 == 1 )
* V_93 &= 0xffffffff ;
return 0 ;
}
static void F_416 ( struct V_2 * V_3 )
{
F_138 ( V_3 , F_135 ( V_3 )
& ~ ( V_766 | V_767 | V_768 |
V_769 | V_770 | V_771 ) ) ;
}
static void F_417 ( struct V_2 * V_3 )
{
F_138 ( V_3 , ( F_135 ( V_3 )
& ~ ( V_767 | V_768 | V_769 |
V_770 | V_771 ) )
| V_766 ) ;
}
static void F_418 ( struct V_2 * V_3 ,
T_2 V_772 )
{
if ( F_1 ( V_3 ) -> V_8 . V_748 == - 1ull ) {
F_417 ( V_3 ) ;
return;
}
F_138 ( V_3 , ( F_135 ( V_3 )
& ~ ( V_766 | V_767 | V_768 |
V_770 | V_771 ) )
| V_769 ) ;
F_4 ( V_3 ) -> V_772 = V_772 ;
}
static int F_419 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_4 V_66 ;
T_1 V_747 ;
struct V_7 * V_7 ;
struct V_10 * V_10 ;
struct V_773 V_774 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , F_69 ( V_671 ) ,
F_71 ( V_775 ) , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_776 , V_66 , & V_747 ,
sizeof( V_747 ) , & V_774 ) ) {
F_421 ( V_3 , & V_774 ) ;
return 1 ;
}
if ( ! F_422 ( V_747 , V_393 ) ) {
F_418 ( V_3 , V_777 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_747 == V_58 -> V_8 . V_748 ) {
F_413 ( V_58 -> V_8 . V_756 ) ;
F_9 ( V_58 -> V_8 . V_756 ) ;
V_58 -> V_8 . V_748 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
}
V_10 = F_5 ( V_3 , V_747 ) ;
if ( V_10 == NULL ) {
F_123 ( V_247 , V_3 ) ;
return 1 ;
}
V_7 = F_423 ( V_10 ) ;
V_7 -> V_778 = 0 ;
F_413 ( V_10 ) ;
F_9 ( V_10 ) ;
F_407 ( V_58 , V_747 ) ;
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
return V_779 ;
return ( V_4 >> 13 ) & 0x3 ;
}
static inline int F_428 ( unsigned long V_4 )
{
return ( ( ( V_4 >> 10 ) & 0x3 ) == 1 ) ;
}
static inline bool F_429 ( struct V_2 * V_3 ,
unsigned long V_4 , T_5 * V_93 )
{
short V_273 = F_3 ( V_4 ) ;
char * V_98 ;
if ( V_273 < 0 )
return 0 ;
V_98 = ( ( char * ) ( F_4 ( V_3 ) ) ) + V_273 ;
switch ( F_427 ( V_4 ) ) {
case V_780 :
* V_93 = * ( ( V_781 * ) V_98 ) ;
return 1 ;
case V_782 :
* V_93 = * ( ( T_3 * ) V_98 ) ;
return 1 ;
case V_779 :
* V_93 = * ( ( T_2 * ) V_98 ) ;
return 1 ;
case V_783 :
* V_93 = * ( ( T_5 * ) V_98 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_430 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( V_58 -> V_8 . V_748 == - 1ull ) {
F_417 ( V_3 ) ;
F_142 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_431 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_5 V_784 ;
unsigned long V_682 = F_69 ( V_671 ) ;
T_2 V_757 = F_71 ( V_775 ) ;
T_4 V_66 = 0 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
V_4 = F_339 ( V_3 , ( ( ( V_757 ) >> 28 ) & 0xf ) ) ;
if ( ! F_429 ( V_3 , V_4 , & V_784 ) ) {
F_418 ( V_3 , V_785 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_757 & ( 1u << 10 ) ) {
F_300 ( V_3 , ( ( ( V_757 ) >> 3 ) & 0xf ) ,
V_784 ) ;
} else {
if ( F_415 ( V_3 , V_682 ,
V_757 , & V_66 ) )
return 1 ;
F_432 ( & V_3 -> V_95 . V_776 , V_66 ,
& V_784 , ( F_108 ( V_3 ) ? 8 : 4 ) , NULL ) ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_433 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_4 V_66 ;
unsigned long V_682 = F_69 ( V_671 ) ;
T_2 V_757 = F_71 ( V_775 ) ;
char * V_98 ;
short V_273 ;
T_5 V_784 = 0 ;
struct V_773 V_774 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
if ( V_757 & ( 1u << 10 ) )
V_784 = F_339 ( V_3 ,
( ( ( V_757 ) >> 3 ) & 0xf ) ) ;
else {
if ( F_415 ( V_3 , V_682 ,
V_757 , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_776 , V_66 ,
& V_784 , ( F_108 ( V_3 ) ? 8 : 4 ) , & V_774 ) ) {
F_421 ( V_3 , & V_774 ) ;
return 1 ;
}
}
V_4 = F_339 ( V_3 , ( ( ( V_757 ) >> 28 ) & 0xf ) ) ;
if ( F_428 ( V_4 ) ) {
F_418 ( V_3 ,
V_786 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_273 = F_3 ( V_4 ) ;
if ( V_273 < 0 ) {
F_418 ( V_3 , V_785 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_98 = ( ( char * ) F_4 ( V_3 ) ) + V_273 ;
switch ( F_427 ( V_4 ) ) {
case V_782 :
* ( T_3 * ) V_98 = V_784 ;
break;
case V_779 :
* ( T_2 * ) V_98 = V_784 ;
break;
case V_783 :
* ( T_5 * ) V_98 = V_784 ;
break;
case V_780 :
* ( V_781 * ) V_98 = V_784 ;
break;
default:
F_418 ( V_3 , V_785 ) ;
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
T_1 V_747 ;
struct V_773 V_774 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , F_69 ( V_671 ) ,
F_71 ( V_775 ) , & V_66 ) )
return 1 ;
if ( F_420 ( & V_3 -> V_95 . V_776 , V_66 , & V_747 ,
sizeof( V_747 ) , & V_774 ) ) {
F_421 ( V_3 , & V_774 ) ;
return 1 ;
}
if ( ! F_422 ( V_747 , V_393 ) ) {
F_418 ( V_3 , V_787 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_748 != V_747 ) {
struct V_7 * V_788 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_3 , V_747 ) ;
if ( V_10 == NULL ) {
F_417 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
V_788 = F_423 ( V_10 ) ;
if ( V_788 -> V_396 != V_321 ) {
F_413 ( V_10 ) ;
F_11 ( V_10 ) ;
F_418 ( V_3 ,
V_789 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
if ( V_58 -> V_8 . V_748 != - 1ull ) {
F_413 ( V_58 -> V_8 . V_756 ) ;
F_9 ( V_58 -> V_8 . V_756 ) ;
}
V_58 -> V_8 . V_748 = V_747 ;
V_58 -> V_8 . V_9 = V_788 ;
V_58 -> V_8 . V_756 = V_10 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static int F_435 ( struct V_2 * V_3 )
{
unsigned long V_682 = F_69 ( V_671 ) ;
T_2 V_757 = F_71 ( V_775 ) ;
T_4 V_790 ;
struct V_773 V_774 ;
if ( ! F_411 ( V_3 ) )
return 1 ;
if ( F_415 ( V_3 , V_682 ,
V_757 , & V_790 ) )
return 1 ;
if ( F_432 ( & V_3 -> V_95 . V_776 , V_790 ,
( void * ) & F_1 ( V_3 ) -> V_8 . V_748 ,
sizeof( T_5 ) , & V_774 ) ) {
F_421 ( V_3 , & V_774 ) ;
return 1 ;
}
F_416 ( V_3 ) ;
F_142 ( V_3 ) ;
return 1 ;
}
static bool F_436 ( struct V_2 * V_3 ,
struct V_7 * V_7 , T_2 V_663 )
{
T_2 V_315 = V_3 -> V_95 . V_354 [ V_699 ] ;
T_1 V_791 ;
if ( ! F_44 ( F_4 ( V_3 ) , V_26 ) )
return 1 ;
V_791 = V_7 -> V_254 ;
if ( V_663 == V_792 )
V_791 += 2048 ;
if ( V_315 >= 0xc0000000 ) {
V_315 -= 0xc0000000 ;
V_791 += 1024 ;
}
if ( V_315 < 1024 * 8 ) {
unsigned char V_793 ;
F_437 ( V_3 -> V_12 , V_791 + V_315 / 8 , & V_793 , 1 ) ;
return 1 & ( V_793 >> ( V_315 & 7 ) ) ;
} else
return 1 ;
}
static bool F_438 ( struct V_2 * V_3 ,
struct V_7 * V_7 )
{
unsigned long V_682 = F_69 ( V_671 ) ;
int V_688 = V_682 & 15 ;
int V_352 = ( V_682 >> 8 ) & 15 ;
unsigned long V_687 = F_339 ( V_3 , V_352 ) ;
switch ( ( V_682 >> 4 ) & 3 ) {
case 0 :
switch ( V_688 ) {
case 0 :
if ( V_7 -> V_213 &
( V_687 ^ V_7 -> V_217 ) )
return 1 ;
break;
case 3 :
if ( ( V_7 -> V_794 >= 1 &&
V_7 -> V_795 == V_687 ) ||
( V_7 -> V_794 >= 2 &&
V_7 -> V_796 == V_687 ) ||
( V_7 -> V_794 >= 3 &&
V_7 -> V_797 == V_687 ) ||
( V_7 -> V_794 >= 4 &&
V_7 -> V_798 == V_687 ) )
return 0 ;
if ( F_44 ( V_7 , V_300 ) )
return 1 ;
break;
case 4 :
if ( V_7 -> V_219 &
( V_7 -> V_220 ^ V_687 ) )
return 1 ;
break;
case 8 :
if ( F_44 ( V_7 , V_302 ) )
return 1 ;
break;
}
break;
case 2 :
if ( ( V_7 -> V_213 & V_210 ) &&
( V_7 -> V_217 & V_210 ) )
return 1 ;
break;
case 1 :
switch ( V_688 ) {
case 3 :
if ( V_7 -> V_55 &
V_301 )
return 1 ;
break;
case 8 :
if ( V_7 -> V_55 &
V_303 )
return 1 ;
break;
}
break;
case 3 :
if ( V_7 -> V_213 & 0xe &
( V_687 ^ V_7 -> V_217 ) )
return 1 ;
if ( ( V_7 -> V_213 & 0x1 ) &&
! ( V_7 -> V_217 & 0x1 ) &&
( V_687 & 0x1 ) )
return 1 ;
break;
}
return 0 ;
}
static bool F_439 ( struct V_2 * V_3 )
{
T_2 V_663 = F_71 ( V_799 ) ;
T_2 V_14 = F_71 ( V_800 ) ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_58 -> V_8 . V_633 )
return 0 ;
if ( F_77 ( V_58 -> V_801 ) ) {
F_440 ( L_29 , V_455 ,
F_71 ( V_88 ) ) ;
return 1 ;
}
switch ( V_663 ) {
case V_802 :
if ( ! F_47 ( V_14 ) )
return 0 ;
else if ( F_12 ( V_14 ) )
return V_84 ;
return V_7 -> V_118 &
( 1u << ( V_14 & V_16 ) ) ;
case V_637 :
return 0 ;
case V_803 :
return 1 ;
case V_804 :
case V_805 :
return 1 ;
case V_806 :
return 1 ;
case V_807 :
return 1 ;
case V_808 :
return F_44 ( V_7 , V_297 ) ;
case V_809 :
return 1 ;
case V_810 :
return F_44 ( V_7 , V_298 ) ;
case V_811 :
return F_44 ( V_7 , V_308 ) ;
case V_812 :
return F_44 ( V_7 , V_813 ) ;
case V_814 : case V_815 :
case V_816 : case V_817 :
case V_818 : case V_819 :
case V_820 : case V_821 :
case V_822 : case V_823 :
return 1 ;
case V_824 :
return F_438 ( V_3 , V_7 ) ;
case V_825 :
return F_44 ( V_7 , V_304 ) ;
case V_826 :
return 1 ;
case V_827 :
case V_792 :
return F_436 ( V_3 , V_7 , V_663 ) ;
case V_828 :
return 1 ;
case V_829 :
return F_44 ( V_7 , V_299 ) ;
case V_830 :
return F_44 ( V_7 , V_307 ) ;
case V_831 :
return F_44 ( V_7 , V_832 ) ||
F_45 ( V_7 ,
V_47 ) ;
case V_833 :
return 0 ;
case V_834 :
return 1 ;
case V_835 :
return F_45 ( V_7 ,
V_30 ) ;
case V_730 :
case V_739 :
return 0 ;
case V_836 :
return F_45 ( V_7 , V_53 ) ;
case V_837 :
return 1 ;
default:
return 1 ;
}
}
static void F_441 ( struct V_2 * V_3 , T_5 * V_838 , T_5 * V_839 )
{
* V_838 = F_69 ( V_671 ) ;
* V_839 = F_71 ( V_800 ) ;
}
static int F_442 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_663 = V_58 -> V_663 ;
T_2 V_840 = V_58 -> V_661 ;
if ( V_58 -> V_420 && V_428 )
return F_393 ( V_3 ) ;
if ( V_58 -> V_8 . V_633 )
F_123 ( V_701 , V_3 ) ;
if ( ! F_90 ( V_3 ) && ( V_663 == V_816 ||
V_663 == V_820 ) )
V_58 -> V_8 . V_633 = 1 ;
else
V_58 -> V_8 . V_633 = 0 ;
if ( F_90 ( V_3 ) && F_439 ( V_3 ) ) {
F_146 ( V_3 ) ;
return 1 ;
}
if ( V_663 & V_841 ) {
V_3 -> V_654 -> V_663 = V_842 ;
V_3 -> V_654 -> V_843 . V_844
= V_663 ;
return 0 ;
}
if ( F_77 ( V_58 -> V_801 ) ) {
V_3 -> V_654 -> V_663 = V_842 ;
V_3 -> V_654 -> V_843 . V_844
= F_71 ( V_88 ) ;
return 0 ;
}
if ( ( V_840 & V_635 ) &&
( V_663 != V_802 &&
V_663 != V_730 &&
V_663 != V_806 ) )
F_54 ( V_147 L_30
L_31 ,
V_455 , V_840 , V_663 ) ;
if ( F_77 ( ! F_41 () && V_58 -> V_597 &&
! ( F_90 ( V_3 ) && F_46 (
F_4 ( V_3 ) , V_3 ) ) ) ) {
if ( F_312 ( V_3 ) ) {
V_58 -> V_597 = 0 ;
} else if ( V_58 -> V_626 > 1000000000LL &&
V_3 -> V_95 . V_845 ) {
F_54 ( V_147 L_32
L_33 ,
V_455 , V_3 -> V_846 ) ;
V_58 -> V_597 = 0 ;
}
}
if ( V_663 < V_847
&& V_848 [ V_663 ] )
return V_848 [ V_663 ] ( V_3 ) ;
else {
V_3 -> V_654 -> V_663 = V_727 ;
V_3 -> V_654 -> V_728 . V_729 = V_663 ;
}
return 0 ;
}
static void V_409 ( struct V_2 * V_3 , int V_849 , int V_850 )
{
if ( V_850 == - 1 || V_849 < V_850 ) {
F_79 ( V_612 , 0 ) ;
return;
}
F_79 ( V_612 , V_850 ) ;
}
static void F_443 ( struct V_1 * V_58 )
{
T_2 V_662 ;
if ( ! ( V_58 -> V_663 == V_833
|| V_58 -> V_663 == V_802 ) )
return;
V_58 -> V_662 = F_71 ( V_800 ) ;
V_662 = V_58 -> V_662 ;
if ( F_16 ( V_662 ) )
F_317 () ;
if ( ( V_662 & V_15 ) == V_630 &&
( V_662 & V_17 ) ) {
F_444 ( & V_58 -> V_3 ) ;
asm("int $2");
F_445 ( & V_58 -> V_3 ) ;
}
}
static void F_446 ( struct V_1 * V_58 )
{
T_2 V_662 ;
bool V_851 ;
T_6 V_852 ;
bool V_853 ;
V_853 = V_58 -> V_661 & V_635 ;
if ( F_41 () ) {
if ( V_58 -> V_628 )
return;
V_662 = F_71 ( V_800 ) ;
V_851 = ( V_662 & V_854 ) != 0 ;
V_852 = V_662 & V_16 ;
if ( ( V_662 & V_17 ) && V_851 &&
V_852 != V_649 && ! V_853 )
F_82 ( V_231 ,
V_631 ) ;
else
V_58 -> V_628 =
! ( F_71 ( V_231 )
& V_631 ) ;
} else if ( F_77 ( V_58 -> V_597 ) )
V_58 -> V_626 +=
F_447 ( F_448 ( F_449 () , V_58 -> V_855 ) ) ;
}
static void F_450 ( struct V_1 * V_58 ,
T_2 V_661 ,
int V_856 ,
int V_857 )
{
T_6 V_852 ;
int type ;
bool V_853 ;
V_853 = V_661 & V_635 ;
V_58 -> V_3 . V_95 . V_719 = false ;
F_382 ( & V_58 -> V_3 ) ;
F_381 ( & V_58 -> V_3 ) ;
if ( ! V_853 )
return;
F_123 ( V_701 , & V_58 -> V_3 ) ;
V_852 = V_661 & V_716 ;
type = V_661 & V_717 ;
switch ( type ) {
case V_630 :
V_58 -> V_3 . V_95 . V_719 = true ;
F_311 ( & V_58 -> V_3 , false ) ;
break;
case V_249 :
V_58 -> V_3 . V_95 . V_245 =
F_71 ( V_856 ) ;
case V_18 :
if ( V_661 & V_720 ) {
T_2 V_689 = F_71 ( V_857 ) ;
F_170 ( & V_58 -> V_3 , V_852 , V_689 ) ;
} else
F_316 ( & V_58 -> V_3 , V_852 ) ;
break;
case V_625 :
V_58 -> V_3 . V_95 . V_245 =
F_71 ( V_856 ) ;
case V_22 :
F_451 ( & V_58 -> V_3 , V_852 ,
type == V_625 ) ;
break;
default:
break;
}
}
static void F_452 ( struct V_1 * V_58 )
{
if ( F_90 ( & V_58 -> V_3 ) )
return;
F_450 ( V_58 , V_58 -> V_661 ,
V_238 ,
V_721 ) ;
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
int V_60 , V_858 ;
struct V_859 * V_860 ;
V_860 = F_455 ( & V_858 ) ;
if ( ! V_860 )
return;
for ( V_60 = 0 ; V_60 < V_858 ; V_60 ++ )
if ( V_860 [ V_60 ] . V_135 == V_860 [ V_60 ] . V_134 )
F_92 ( V_58 , V_860 [ V_60 ] . V_59 ) ;
else
F_94 ( V_58 , V_860 [ V_60 ] . V_59 , V_860 [ V_60 ] . V_134 ,
V_860 [ V_60 ] . V_135 ) ;
}
static void T_16 F_456 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
if ( F_90 ( V_3 ) && ! V_58 -> V_8 . V_633 ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_634 &
V_635 ) {
F_79 ( V_250 ,
V_7 -> V_634 ) ;
F_79 ( V_248 ,
V_7 -> V_861 ) ;
if ( V_7 -> V_634 &
V_720 )
F_79 ( V_242 ,
V_7 -> V_862 ) ;
}
}
if ( F_77 ( ! F_41 () && V_58 -> V_597 ) )
V_58 -> V_855 = F_449 () ;
if ( V_58 -> V_420 && V_428 )
return;
if ( F_136 ( V_353 , ( unsigned long * ) & V_3 -> V_95 . V_463 ) )
F_76 ( V_355 , V_3 -> V_95 . V_354 [ V_353 ] ) ;
if ( F_136 ( V_356 , ( unsigned long * ) & V_3 -> V_95 . V_463 ) )
F_76 ( V_357 , V_3 -> V_95 . V_354 [ V_356 ] ) ;
if ( V_3 -> V_111 & V_645 )
F_141 ( V_3 , 0 ) ;
F_454 ( V_58 ) ;
V_58 -> V_863 = V_58 -> V_75 -> V_77 ;
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
V_3 -> V_95 . V_96 = ~ ( ( 1 << V_356 ) | ( 1 << V_353 )
| ( 1 << V_224 )
| ( 1 << V_227 )
| ( 1 << V_358 )
| ( 1 << V_97 )
| ( 1 << V_460 ) ) ;
V_3 -> V_95 . V_463 = 0 ;
V_58 -> V_661 = F_71 ( V_864 ) ;
if ( F_90 ( V_3 ) ) {
struct V_7 * V_7 = F_4 ( V_3 ) ;
V_7 -> V_634 = V_58 -> V_661 ;
if ( V_58 -> V_661 & V_635 ) {
V_7 -> V_862 =
F_71 ( V_721 ) ;
V_7 -> V_861 =
F_71 ( V_238 ) ;
}
}
V_58 -> V_75 -> V_77 = 1 ;
V_58 -> V_663 = F_71 ( V_799 ) ;
F_457 ( V_58 -> V_663 , V_3 , V_865 ) ;
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
F_460 ( V_866 , V_58 ) ;
}
static struct V_2 * F_461 ( struct V_12 * V_12 , unsigned int V_867 )
{
int V_689 ;
struct V_1 * V_58 = F_462 ( V_866 , V_403 ) ;
int V_76 ;
if ( ! V_58 )
return F_463 ( - V_404 ) ;
F_275 ( V_58 ) ;
V_689 = F_464 ( & V_58 -> V_3 , V_12 , V_867 ) ;
if ( V_689 )
goto V_868;
V_58 -> V_63 = F_405 ( V_393 , V_403 ) ;
V_689 = - V_404 ;
if ( ! V_58 -> V_63 ) {
goto V_869;
}
V_58 -> V_75 = & V_58 -> V_755 ;
V_58 -> V_75 -> V_72 = F_202 () ;
if ( ! V_58 -> V_75 -> V_72 )
goto V_870;
if ( ! V_200 )
F_122 ( F_53 ( F_59 ( V_199 , F_58 () ) ) ) ;
F_55 ( V_58 -> V_75 ) ;
if ( ! V_200 )
F_128 () ;
V_76 = F_465 () ;
F_121 ( & V_58 -> V_3 , V_76 ) ;
V_58 -> V_3 . V_76 = V_76 ;
V_689 = F_291 ( V_58 ) ;
F_127 ( & V_58 -> V_3 ) ;
F_466 () ;
if ( V_689 )
goto F_203;
if ( F_38 ( V_12 ) )
V_689 = F_270 ( V_12 ) ;
if ( V_689 )
goto F_203;
if ( V_84 ) {
if ( ! V_12 -> V_95 . V_484 )
V_12 -> V_95 . V_484 =
V_871 ;
V_689 = - V_404 ;
if ( F_274 ( V_12 ) != 0 )
goto F_203;
if ( ! F_267 ( V_12 ) )
goto F_203;
}
V_58 -> V_8 . V_748 = - 1ull ;
V_58 -> V_8 . V_9 = NULL ;
return & V_58 -> V_3 ;
F_203:
F_205 ( V_58 -> V_75 ) ;
V_870:
F_406 ( V_58 -> V_63 ) ;
V_869:
F_459 ( & V_58 -> V_3 ) ;
V_868:
F_279 ( V_58 ) ;
F_460 ( V_866 , V_58 ) ;
return F_463 ( V_689 ) ;
}
static void T_11 F_467 ( void * V_872 )
{
struct V_24 V_381 ;
* ( int * ) V_872 = 0 ;
if ( F_196 ( & V_381 ) < 0 )
* ( int * ) V_872 = - V_380 ;
if ( memcmp ( & V_24 , & V_381 , sizeof( struct V_24 ) ) != 0 ) {
F_54 ( V_74 L_34 ,
F_468 () ) ;
* ( int * ) V_872 = - V_380 ;
}
}
static int F_469 ( void )
{
return V_479 + 1 ;
}
static T_5 F_470 ( struct V_2 * V_3 , T_13 V_873 , bool V_874 )
{
T_5 V_93 ;
if ( V_874 )
V_93 = V_875 << V_876 ;
else if ( V_3 -> V_12 -> V_95 . V_877 &&
! ( V_3 -> V_12 -> V_95 . V_878 & V_879 ) )
V_93 = F_471 ( V_3 , V_873 ) <<
V_876 ;
else
V_93 = ( V_880 << V_876 )
| V_881 ;
return V_93 ;
}
static int F_472 ( void )
{
if ( V_84 && ! F_28 () )
return V_882 ;
else
return V_883 ;
}
static void F_473 ( struct V_2 * V_3 )
{
struct V_277 * V_278 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_572 ;
V_58 -> V_259 = false ;
if ( F_150 () ) {
V_572 = F_71 ( V_580 ) ;
if ( V_572 & V_50 ) {
V_278 = F_163 ( V_3 , 0x80000001 , 0 ) ;
if ( V_278 && ( V_278 -> V_884 & V_54 ( V_885 ) ) )
V_58 -> V_259 = true ;
else {
V_572 &= ~ V_50 ;
F_79 ( V_580 ,
V_572 ) ;
}
}
}
}
static void F_474 ( T_2 V_886 , struct V_277 * V_120 )
{
if ( V_886 == 1 && V_8 )
V_120 -> V_279 |= V_54 ( V_280 ) ;
}
static void F_475 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
T_2 V_572 ;
F_78 ( V_887 , V_7 -> V_888 ) ;
F_78 ( V_435 , V_7 -> V_889 ) ;
F_78 ( V_433 , V_7 -> V_890 ) ;
F_78 ( V_891 , V_7 -> V_892 ) ;
F_78 ( V_893 , V_7 -> V_894 ) ;
F_78 ( V_895 , V_7 -> V_896 ) ;
F_78 ( V_602 , V_7 -> V_897 ) ;
F_78 ( V_421 , V_7 -> V_898 ) ;
F_79 ( V_899 , V_7 -> V_900 ) ;
F_79 ( V_450 , V_7 -> V_901 ) ;
F_79 ( V_449 , V_7 -> V_902 ) ;
F_79 ( V_903 , V_7 -> V_904 ) ;
F_79 ( V_905 , V_7 -> V_906 ) ;
F_79 ( V_907 , V_7 -> V_908 ) ;
F_79 ( V_604 , V_7 -> V_909 ) ;
F_79 ( V_423 , V_7 -> V_910 ) ;
F_79 ( V_508 , V_7 -> V_911 ) ;
F_79 ( V_506 , V_7 -> V_912 ) ;
F_79 ( V_913 , V_7 -> V_914 ) ;
F_79 ( V_436 , V_7 -> V_915 ) ;
F_79 ( V_434 , V_7 -> V_916 ) ;
F_79 ( V_917 , V_7 -> V_918 ) ;
F_79 ( V_919 , V_7 -> V_920 ) ;
F_79 ( V_921 , V_7 -> V_922 ) ;
F_79 ( V_605 , V_7 -> V_923 ) ;
F_79 ( V_424 , V_7 -> V_924 ) ;
F_76 ( V_925 , V_7 -> V_926 ) ;
F_76 ( V_451 , V_7 -> V_927 ) ;
F_76 ( V_448 , V_7 -> V_928 ) ;
F_76 ( V_929 , V_7 -> V_930 ) ;
F_76 ( V_339 , V_7 -> V_931 ) ;
F_76 ( V_340 , V_7 -> V_932 ) ;
F_76 ( V_603 , V_7 -> V_933 ) ;
F_76 ( V_422 , V_7 -> V_934 ) ;
F_76 ( V_509 , V_7 -> V_935 ) ;
F_76 ( V_507 , V_7 -> V_936 ) ;
F_80 ( V_609 , V_7 -> V_937 ) ;
F_79 ( V_250 ,
V_7 -> V_938 ) ;
F_79 ( V_242 ,
V_7 -> V_939 ) ;
F_79 ( V_248 ,
V_7 -> V_940 ) ;
F_79 ( V_231 ,
V_7 -> V_941 ) ;
F_79 ( V_606 , V_7 -> V_942 ) ;
F_79 ( V_343 , V_7 -> V_943 ) ;
F_76 ( V_362 , V_7 -> V_944 ) ;
F_76 ( V_225 , V_7 -> V_945 ) ;
F_76 ( V_608 ,
V_7 -> V_946 ) ;
F_76 ( V_346 , V_7 -> V_947 ) ;
F_76 ( V_345 , V_7 -> V_948 ) ;
F_80 ( V_578 , - 1ull ) ;
F_79 ( V_579 ,
( V_24 . V_51 |
V_7 -> V_57 ) ) ;
F_79 ( V_584 ,
V_84 ? V_7 -> V_949 : 0 ) ;
F_79 ( V_585 ,
V_84 ? V_7 -> V_950 : 0 ) ;
if ( F_21 () ) {
T_2 V_572 = F_288 ( V_58 ) ;
if ( ! V_58 -> V_259 )
V_572 &= ~ V_50 ;
V_572 &= ~ V_30 ;
if ( F_44 ( V_7 ,
V_28 ) )
V_572 |= V_7 -> V_56 ;
if ( V_572 & V_30 ) {
if ( V_58 -> V_8 . V_541 )
F_9 ( V_58 -> V_8 . V_541 ) ;
V_58 -> V_8 . V_541 =
F_5 ( V_3 , V_7 -> V_951 ) ;
if ( ! V_58 -> V_8 . V_541 )
V_572 &=
~ V_30 ;
else
F_80 ( V_613 ,
F_301 ( V_58 -> V_8 . V_541 ) ) ;
}
F_79 ( V_580 , V_572 ) ;
}
F_282 () ;
V_58 -> V_952 = 0 ;
V_572 = F_287 ( V_58 ) ;
V_572 &= ~ V_296 ;
V_572 &= ~ V_619 ;
V_572 &= ~ V_27 ;
V_572 |= V_7 -> V_55 ;
V_572 &= ~ V_26 ;
V_572 &= ~ V_306 ;
V_572 |= V_305 ;
F_79 ( V_471 , V_572 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_212 &= ~ V_7 -> V_213 ;
F_76 ( V_214 , ~ V_3 -> V_95 . V_212 ) ;
F_79 ( V_122 ,
V_7 -> V_953 | V_24 . V_397 ) ;
F_79 ( V_121 , V_7 -> V_954 |
( V_24 . V_348 & ~ V_292 ) ) ;
if ( V_7 -> V_954 & V_291 )
F_80 ( V_349 , V_7 -> V_955 ) ;
else if ( V_24 . V_348 & V_291 )
F_80 ( V_349 , V_58 -> V_3 . V_95 . V_350 ) ;
F_286 ( V_58 ) ;
if ( V_7 -> V_55 & V_274 )
F_80 ( V_266 ,
V_58 -> V_8 . V_267 + V_7 -> V_265 ) ;
else
F_80 ( V_266 , V_58 -> V_8 . V_267 ) ;
if ( V_406 ) {
F_78 ( V_614 , V_58 -> V_42 ) ;
F_228 ( V_3 ) ;
}
if ( V_7 -> V_954 & V_127 )
V_3 -> V_95 . V_158 = V_7 -> V_956 ;
if ( V_7 -> V_954 & V_292 )
V_3 -> V_95 . V_158 |= ( V_161 | V_162 ) ;
else
V_3 -> V_95 . V_158 &= ~ ( V_161 | V_162 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 ) ;
F_239 ( V_3 , V_7 -> V_216 ) ;
F_76 ( V_221 , F_131 ( V_7 ) ) ;
F_237 ( V_3 , V_7 -> V_218 ) ;
F_76 ( V_427 , F_132 ( V_7 ) ) ;
F_342 ( V_3 , V_7 -> V_482 ) ;
F_223 ( V_3 ) ;
F_300 ( V_3 , V_353 , V_7 -> V_957 ) ;
F_300 ( V_3 , V_356 , V_7 -> V_958 ) ;
}
static int F_425 ( struct V_2 * V_3 , bool V_959 )
{
struct V_7 * V_7 ;
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_75 * V_751 ;
if ( ! F_411 ( V_3 ) ||
! F_430 ( V_3 ) )
return 1 ;
F_142 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 -> V_778 == V_959 ) {
F_418 ( V_3 ,
V_959 ? V_960
: V_961 ) ;
return 1 ;
}
if ( ( V_7 -> V_55 & V_26 ) &&
! F_422 ( V_7 -> V_254 , V_393 ) ) {
F_418 ( V_3 , V_962 ) ;
return 1 ;
}
if ( F_45 ( V_7 , V_30 ) &&
! F_422 ( V_7 -> V_951 , V_393 ) ) {
F_418 ( V_3 , V_962 ) ;
return 1 ;
}
if ( V_7 -> V_963 > 0 ||
V_7 -> V_964 > 0 ||
V_7 -> V_965 > 0 ) {
F_476 ( L_35 ,
V_455 ) ;
F_418 ( V_3 , V_962 ) ;
return 1 ;
}
if ( ! F_167 ( V_7 -> V_55 ,
V_294 , V_295 ) ||
! F_167 ( V_7 -> V_56 ,
V_310 , V_311 ) ||
! F_167 ( V_7 -> V_57 ,
V_281 , V_282 ) ||
! F_167 ( V_7 -> V_953 ,
V_285 , V_286 ) ||
! F_167 ( V_7 -> V_954 ,
V_289 , V_290 ) )
{
F_418 ( V_3 , V_962 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_966 & F_171 ) != F_171 ) ||
( ( V_7 -> V_967 & F_172 ) != F_172 ) ) {
F_418 ( V_3 ,
V_968 ) ;
return 1 ;
}
if ( ( ( V_7 -> V_216 & F_171 ) != F_171 ) ||
( ( V_7 -> V_218 & F_172 ) != F_172 ) ) {
F_477 ( V_3 , V_7 ,
V_828 , V_969 ) ;
return 1 ;
}
if ( V_7 -> V_970 != - 1ull ) {
F_477 ( V_3 , V_7 ,
V_828 , V_971 ) ;
return 1 ;
}
V_751 = F_400 ( V_58 ) ;
if ( ! V_751 )
return - V_404 ;
F_478 ( V_3 ) ;
V_58 -> V_8 . V_267 = F_72 ( V_266 ) ;
V_76 = F_465 () ;
V_58 -> V_75 = V_751 ;
F_127 ( V_3 ) ;
F_121 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_466 () ;
V_7 -> V_778 = 1 ;
F_475 ( V_3 , V_7 ) ;
return 1 ;
}
static inline unsigned long
F_479 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_209 ) & V_3 -> V_95 . V_212 ) |
( V_7 -> V_216 & V_7 -> V_213 ) |
( F_69 ( V_221 ) & ~ ( V_7 -> V_213 |
V_3 -> V_95 . V_212 ) ) ;
}
static inline unsigned long
F_480 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
return
( F_69 ( V_425 ) & V_3 -> V_95 . V_461 ) |
( V_7 -> V_218 & V_7 -> V_219 ) |
( F_69 ( V_427 ) & ~ ( V_7 -> V_219 |
V_3 -> V_95 . V_461 ) ) ;
}
void F_481 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
V_7 -> V_216 = F_479 ( V_3 , V_7 ) ;
V_7 -> V_218 = F_480 ( V_3 , V_7 ) ;
F_350 ( V_3 , 7 , ( unsigned long * ) & V_7 -> V_944 ) ;
V_7 -> V_957 = F_339 ( V_3 , V_353 ) ;
V_7 -> V_958 = F_339 ( V_3 , V_356 ) ;
V_7 -> V_945 = F_69 ( V_225 ) ;
V_7 -> V_888 = F_70 ( V_887 ) ;
V_7 -> V_889 = F_70 ( V_435 ) ;
V_7 -> V_890 = F_70 ( V_433 ) ;
V_7 -> V_892 = F_70 ( V_891 ) ;
V_7 -> V_894 = F_70 ( V_893 ) ;
V_7 -> V_896 = F_70 ( V_895 ) ;
V_7 -> V_897 = F_70 ( V_602 ) ;
V_7 -> V_898 = F_70 ( V_421 ) ;
V_7 -> V_900 = F_71 ( V_899 ) ;
V_7 -> V_901 = F_71 ( V_450 ) ;
V_7 -> V_902 = F_71 ( V_449 ) ;
V_7 -> V_904 = F_71 ( V_903 ) ;
V_7 -> V_906 = F_71 ( V_905 ) ;
V_7 -> V_908 = F_71 ( V_907 ) ;
V_7 -> V_909 = F_71 ( V_604 ) ;
V_7 -> V_910 = F_71 ( V_423 ) ;
V_7 -> V_911 = F_71 ( V_508 ) ;
V_7 -> V_912 = F_71 ( V_506 ) ;
V_7 -> V_914 = F_71 ( V_913 ) ;
V_7 -> V_915 = F_71 ( V_436 ) ;
V_7 -> V_916 = F_71 ( V_434 ) ;
V_7 -> V_918 = F_71 ( V_917 ) ;
V_7 -> V_920 = F_71 ( V_919 ) ;
V_7 -> V_922 = F_71 ( V_921 ) ;
V_7 -> V_923 = F_71 ( V_605 ) ;
V_7 -> V_924 = F_71 ( V_424 ) ;
V_7 -> V_926 = F_69 ( V_925 ) ;
V_7 -> V_927 = F_69 ( V_451 ) ;
V_7 -> V_928 = F_69 ( V_448 ) ;
V_7 -> V_930 = F_69 ( V_929 ) ;
V_7 -> V_931 = F_69 ( V_339 ) ;
V_7 -> V_932 = F_69 ( V_340 ) ;
V_7 -> V_933 = F_69 ( V_603 ) ;
V_7 -> V_934 = F_69 ( V_422 ) ;
V_7 -> V_935 = F_69 ( V_509 ) ;
V_7 -> V_936 = F_69 ( V_507 ) ;
V_7 -> V_942 = F_71 ( V_606 ) ;
V_7 -> V_941 =
F_71 ( V_231 ) ;
V_7 -> V_946 =
F_69 ( V_608 ) ;
V_7 -> V_937 = F_72 ( V_609 ) ;
if ( V_7 -> V_954 & V_391 )
V_7 -> V_955 = F_72 ( V_349 ) ;
V_7 -> V_943 = F_71 ( V_343 ) ;
V_7 -> V_947 = F_69 ( V_346 ) ;
V_7 -> V_948 = F_69 ( V_345 ) ;
V_7 -> V_636 = F_71 ( V_799 ) ;
V_7 -> V_682 = F_69 ( V_671 ) ;
V_7 -> V_638 = F_71 ( V_800 ) ;
V_7 -> V_972 = F_71 ( V_670 ) ;
V_7 -> V_634 =
F_71 ( V_864 ) ;
V_7 -> V_862 =
F_71 ( V_721 ) ;
V_7 -> V_861 = F_71 ( V_238 ) ;
V_7 -> V_757 = F_71 ( V_775 ) ;
if ( ! ( V_7 -> V_636 & V_841 ) )
V_7 -> V_938 &= ~ V_17 ;
}
void F_482 ( struct V_2 * V_3 , struct V_7 * V_7 )
{
if ( V_7 -> V_953 & V_128 )
V_3 -> V_95 . V_158 = V_7 -> V_973 ;
if ( V_7 -> V_953 & V_287 )
V_3 -> V_95 . V_158 |= ( V_161 | V_162 ) ;
else
V_3 -> V_95 . V_158 &= ~ ( V_161 | V_162 ) ;
F_224 ( V_3 , V_3 -> V_95 . V_158 ) ;
F_300 ( V_3 , V_353 , V_7 -> V_952 ) ;
F_300 ( V_3 , V_356 , V_7 -> V_974 ) ;
F_334 ( V_3 , V_7 -> V_966 ) ;
F_89 ( V_3 ) ;
V_3 -> V_95 . V_212 = ( V_3 -> V_117 ? V_210 : 0 ) ;
F_76 ( V_214 , ~ V_3 -> V_95 . V_212 ) ;
V_3 -> V_95 . V_461 = ~ F_69 ( V_571 ) ;
F_336 ( V_3 , V_7 -> V_967 ) ;
F_342 ( V_3 , V_7 -> V_975 ) ;
F_223 ( V_3 ) ;
if ( V_406 ) {
F_228 ( V_3 ) ;
}
F_79 ( V_343 , V_7 -> V_976 ) ;
F_76 ( V_346 , V_7 -> V_977 ) ;
F_76 ( V_345 , V_7 -> V_978 ) ;
F_76 ( V_507 , V_7 -> V_979 ) ;
F_76 ( V_509 , V_7 -> V_980 ) ;
F_76 ( V_422 , V_7 -> V_981 ) ;
F_76 ( V_340 , V_7 -> V_982 ) ;
F_76 ( V_339 , V_7 -> V_983 ) ;
F_78 ( V_887 , V_7 -> V_984 ) ;
F_78 ( V_435 , V_7 -> V_985 ) ;
F_78 ( V_433 , V_7 -> V_986 ) ;
F_78 ( V_891 , V_7 -> V_987 ) ;
F_78 ( V_893 , V_7 -> V_988 ) ;
F_78 ( V_895 , V_7 -> V_989 ) ;
F_78 ( V_421 , V_7 -> V_990 ) ;
if ( V_7 -> V_953 & V_392 )
F_80 ( V_349 , V_7 -> V_991 ) ;
if ( V_7 -> V_953 & V_132 )
F_80 ( V_144 ,
V_7 -> V_992 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
int V_76 ;
struct V_7 * V_7 = F_4 ( V_3 ) ;
F_483 ( V_3 ) ;
F_481 ( V_3 , V_7 ) ;
V_76 = F_465 () ;
V_58 -> V_75 = & V_58 -> V_755 ;
F_127 ( V_3 ) ;
F_121 ( V_3 , V_76 ) ;
V_3 -> V_76 = V_76 ;
F_466 () ;
if ( V_753 == 0 )
F_407 ( V_58 , V_58 -> V_8 . V_748 ) ;
F_482 ( V_3 , V_7 ) ;
F_80 ( V_266 , V_58 -> V_8 . V_267 ) ;
V_58 -> V_952 = 0 ;
if ( V_58 -> V_8 . V_541 ) {
F_9 ( V_58 -> V_8 . V_541 ) ;
V_58 -> V_8 . V_541 = 0 ;
}
if ( F_77 ( V_58 -> V_801 ) ) {
V_58 -> V_801 = 0 ;
F_418 ( V_3 , F_71 ( V_88 ) ) ;
} else
F_416 ( V_3 ) ;
}
static void F_477 ( struct V_2 * V_3 ,
struct V_7 * V_7 ,
T_2 V_713 , unsigned long V_993 )
{
F_482 ( V_3 , V_7 ) ;
V_7 -> V_636 = V_713 | V_841 ;
V_7 -> V_682 = V_993 ;
F_416 ( V_3 ) ;
}
static int F_484 ( struct V_2 * V_3 ,
struct V_994 * V_995 ,
enum V_996 V_997 )
{
return V_998 ;
}
static int T_11 F_485 ( void )
{
int V_522 , V_60 ;
F_486 ( V_125 , & V_163 ) ;
for ( V_60 = 0 ; V_60 < V_593 ; ++ V_60 )
F_487 ( V_60 , V_62 [ V_60 ] ) ;
V_575 = ( unsigned long * ) F_488 ( V_403 ) ;
if ( ! V_575 )
return - V_404 ;
V_577 = ( unsigned long * ) F_488 ( V_403 ) ;
if ( ! V_577 ) {
V_522 = - V_404 ;
goto V_524;
}
V_262 = ( unsigned long * ) F_488 ( V_403 ) ;
if ( ! V_262 ) {
V_522 = - V_404 ;
goto V_999;
}
V_261 = ( unsigned long * ) F_488 ( V_403 ) ;
if ( ! V_261 ) {
V_522 = - V_404 ;
goto V_1000;
}
memset ( V_575 , 0xff , V_393 ) ;
F_489 ( 0x80 , V_575 ) ;
memset ( V_577 , 0xff , V_393 ) ;
memset ( V_262 , 0xff , V_393 ) ;
memset ( V_261 , 0xff , V_393 ) ;
F_490 ( 0 , V_547 ) ;
V_522 = F_491 ( & V_1001 , sizeof( struct V_1 ) ,
F_492 ( struct V_1 ) , V_1002 ) ;
if ( V_522 )
goto V_1003;
F_281 ( V_189 , false ) ;
F_281 ( V_191 , false ) ;
F_281 ( V_192 , true ) ;
F_281 ( V_342 , false ) ;
F_281 ( V_206 , false ) ;
F_281 ( V_344 , false ) ;
if ( V_84 ) {
F_493 ( 0ull , 0ull , 0ull , 0ull ,
V_1004 ) ;
F_289 () ;
F_494 () ;
} else
F_495 () ;
return 0 ;
V_1003:
F_496 ( ( unsigned long ) V_261 ) ;
V_1000:
F_496 ( ( unsigned long ) V_262 ) ;
V_999:
F_496 ( ( unsigned long ) V_577 ) ;
V_524:
F_496 ( ( unsigned long ) V_575 ) ;
return V_522 ;
}
static void T_12 F_497 ( void )
{
F_496 ( ( unsigned long ) V_262 ) ;
F_496 ( ( unsigned long ) V_261 ) ;
F_496 ( ( unsigned long ) V_577 ) ;
F_496 ( ( unsigned long ) V_575 ) ;
F_498 () ;
}
