static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
V_4 -- ;
F_2 ( V_2 , V_5 ) ;
if ( V_3 ) {
F_2 ( V_2 , V_6 ) ;
F_2 ( V_2 , V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( V_10 ) ;
if ( F_6 ( V_11 ) ) {
struct V_1 * V_12 = V_2 -> V_13 ;
if ( ( F_7 ( V_12 ) -> V_14 == V_12 ) &&
F_8 ( & V_12 -> V_15 ) &&
( V_12 -> V_16 & V_17 ) )
F_9 ( V_12 ) ;
}
}
F_3 ( & V_2 -> V_18 ) ;
}
static void F_10 ( struct V_1 * V_19 )
{
struct V_20 * V_21 = V_19 -> signal ;
bool V_3 = F_11 ( V_19 ) ;
struct V_22 * V_23 ;
struct V_24 * V_25 ( V_26 ) ;
V_23 = F_12 ( V_19 -> V_23 ,
F_13 () ) ;
F_14 ( & V_23 -> V_27 ) ;
F_15 ( V_19 ) ;
if ( V_3 ) {
F_16 ( V_19 ) ;
V_26 = V_21 -> V_26 ;
V_21 -> V_26 = NULL ;
} else {
if ( F_17 ( F_18 ( V_19 ) ) )
F_16 ( V_19 ) ;
if ( V_21 -> V_28 > 0 && ! -- V_21 -> V_28 )
F_9 ( V_21 -> V_29 ) ;
if ( V_19 == V_21 -> V_30 )
V_21 -> V_30 = F_19 ( V_19 ) ;
V_21 -> V_31 += V_19 -> V_31 ;
V_21 -> V_32 += V_19 -> V_32 ;
V_21 -> V_33 += V_19 -> V_33 ;
V_21 -> V_34 += V_19 -> V_34 ;
V_21 -> V_35 += V_19 -> V_35 ;
V_21 -> V_36 += V_19 -> V_36 ;
V_21 -> V_37 += V_19 -> V_37 ;
V_21 -> V_38 += F_20 ( V_19 ) ;
V_21 -> V_39 += F_21 ( V_19 ) ;
F_22 ( & V_21 -> V_40 , & V_19 -> V_40 ) ;
V_21 -> V_41 += V_19 -> V_42 . V_43 ;
}
V_21 -> V_4 -- ;
F_1 ( V_19 , V_3 ) ;
F_23 ( & V_19 -> V_44 ) ;
V_19 -> V_23 = NULL ;
F_24 ( & V_23 -> V_27 ) ;
F_25 ( V_23 ) ;
F_26 ( V_19 , V_45 ) ;
if ( V_3 ) {
F_23 ( & V_21 -> V_46 ) ;
F_27 ( V_26 ) ;
}
}
static void F_28 ( struct V_47 * V_48 )
{
struct V_1 * V_19 = F_29 ( V_48 , struct V_1 , V_49 ) ;
F_30 ( V_19 ) ;
F_31 ( V_19 ) ;
F_32 ( V_19 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_1 * V_50 ;
int V_51 ;
V_52:
F_34 () ;
F_35 ( & F_36 ( V_2 ) -> V_53 -> V_54 ) ;
F_37 () ;
F_38 ( V_2 ) ;
F_39 ( & V_55 ) ;
F_40 ( V_2 ) ;
F_10 ( V_2 ) ;
V_51 = 0 ;
V_50 = V_2 -> V_56 ;
if ( V_50 != V_2 && F_41 ( V_50 ) && V_50 -> V_57 == V_58 ) {
V_51 = F_42 ( V_50 , V_50 -> V_59 ) ;
if ( V_51 )
V_50 -> V_57 = V_60 ;
}
F_43 ( & V_55 ) ;
F_44 ( V_2 ) ;
F_45 ( & V_2 -> V_49 , F_28 ) ;
V_2 = V_50 ;
if ( F_17 ( V_51 ) )
goto V_52;
}
struct V_61 * F_46 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
struct V_61 * V_63 = NULL ;
V_2 = F_47 ( V_62 , V_6 ) ;
if ( V_2 == NULL )
V_2 = F_47 ( V_62 , V_5 ) ;
if ( V_2 != NULL )
V_63 = F_48 ( V_2 ) ;
return V_63 ;
}
static int F_49 ( struct V_61 * V_62 , struct V_1 * V_64 )
{
struct V_1 * V_2 ;
F_50 (pgrp, PIDTYPE_PGID, p) {
if ( ( V_2 == V_64 ) ||
( V_2 -> V_57 && F_41 ( V_2 ) ) ||
F_51 ( V_2 -> V_13 ) )
continue;
if ( F_52 ( V_2 -> V_13 ) != V_62 &&
F_48 ( V_2 -> V_13 ) == F_48 ( V_2 ) )
return 0 ;
} F_53 ( V_62 , V_6 , V_2 ) ;
return 1 ;
}
int F_54 ( void )
{
int V_65 ;
F_55 ( & V_55 ) ;
V_65 = F_49 ( F_52 ( V_66 ) , NULL ) ;
F_56 ( & V_55 ) ;
return V_65 ;
}
static bool F_57 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
F_50 (pgrp, PIDTYPE_PGID, p) {
if ( V_2 -> signal -> V_16 & V_67 )
return true ;
} F_53 ( V_62 , V_6 , V_2 ) ;
return false ;
}
static void
F_58 ( struct V_1 * V_19 , struct V_1 * V_12 )
{
struct V_61 * V_62 = F_52 ( V_19 ) ;
struct V_1 * V_64 = V_19 ;
if ( ! V_12 )
V_12 = V_19 -> V_13 ;
else
V_64 = NULL ;
if ( F_52 ( V_12 ) != V_62 &&
F_48 ( V_12 ) == F_48 ( V_19 ) &&
F_49 ( V_62 , V_64 ) &&
F_57 ( V_62 ) ) {
F_59 ( V_68 , V_69 , V_62 ) ;
F_59 ( V_70 , V_69 , V_62 ) ;
}
}
static void F_60 ( void )
{
F_39 ( & V_55 ) ;
F_61 ( V_66 ) ;
V_66 -> V_13 = V_66 -> V_12 = V_71 ;
F_62 ( & V_66 -> V_9 , & V_66 -> V_13 -> V_15 ) ;
V_66 -> V_59 = V_72 ;
if ( F_63 ( V_66 ) < 0 )
F_64 ( V_66 , 0 ) ;
memcpy ( V_66 -> signal -> V_73 , V_74 . signal -> V_73 ,
sizeof( V_66 -> signal -> V_73 ) ) ;
F_65 ( & V_75 . V_76 ) ;
F_66 ( & V_75 ) ;
F_43 ( & V_55 ) ;
}
void F_67 ( struct V_61 * V_61 )
{
struct V_1 * V_77 = V_66 -> V_56 ;
if ( F_48 ( V_77 ) != V_61 )
F_68 ( V_77 , V_7 , V_61 ) ;
if ( F_52 ( V_77 ) != V_61 )
F_68 ( V_77 , V_6 , V_61 ) ;
}
static void F_69 ( struct V_61 * V_61 )
{
F_39 ( & V_55 ) ;
F_67 ( V_61 ) ;
F_43 ( & V_55 ) ;
}
int F_70 ( int V_21 )
{
if ( ! F_71 ( V_21 ) || V_21 < 1 )
return - V_78 ;
F_72 ( & V_66 -> V_23 -> V_27 ) ;
F_73 ( & V_66 -> V_79 , V_21 ) ;
V_66 -> V_23 -> V_80 [ ( V_21 ) - 1 ] . V_81 . V_82 = ( void V_83 * ) 2 ;
F_74 () ;
F_75 ( & V_66 -> V_23 -> V_27 ) ;
return 0 ;
}
int F_76 ( int V_21 )
{
if ( ! F_71 ( V_21 ) || V_21 < 1 )
return - V_78 ;
F_72 ( & V_66 -> V_23 -> V_27 ) ;
V_66 -> V_23 -> V_80 [ ( V_21 ) - 1 ] . V_81 . V_82 = V_84 ;
F_74 () ;
F_75 ( & V_66 -> V_23 -> V_27 ) ;
return 0 ;
}
void F_77 ( const char * V_85 , ... )
{
T_1 args ;
T_2 V_79 ;
va_start ( args , V_85 ) ;
vsnprintf ( V_66 -> V_86 , sizeof( V_66 -> V_86 ) , V_85 , args ) ;
va_end ( args ) ;
F_78 ( V_66 ) ;
V_66 -> V_16 |= ( V_87 | V_88 ) ;
if ( V_66 -> V_89 != & V_90 ) {
F_79 ( & V_90 ) ;
F_80 ( V_66 , & V_90 ) ;
}
F_69 ( & V_91 ) ;
F_81 ( V_66 ) ;
F_82 ( & V_79 ) ;
F_83 ( V_92 , & V_79 , NULL ) ;
F_84 ( V_66 ) ;
F_85 () ;
F_86 ( V_66 ) ;
V_66 -> V_93 = V_74 . V_93 ;
F_65 ( & V_66 -> V_93 -> V_94 ) ;
F_60 () ;
}
static void F_87 ( struct V_95 * V_93 )
{
int V_96 , V_97 ;
struct V_98 * V_99 ;
V_97 = 0 ;
F_34 () ;
V_99 = F_88 ( V_93 ) ;
F_37 () ;
for (; ; ) {
unsigned long V_100 ;
V_96 = V_97 * V_101 ;
if ( V_96 >= V_99 -> V_102 )
break;
V_100 = V_99 -> V_103 [ V_97 ++ ] ;
while ( V_100 ) {
if ( V_100 & 1 ) {
struct V_104 * V_104 = F_89 ( & V_99 -> V_105 [ V_96 ] , NULL ) ;
if ( V_104 ) {
F_90 ( V_104 , V_93 ) ;
F_91 () ;
}
}
V_96 ++ ;
V_100 >>= 1 ;
}
}
}
struct V_95 * F_92 ( struct V_1 * V_106 )
{
struct V_95 * V_93 ;
F_93 ( V_106 ) ;
V_93 = V_106 -> V_93 ;
if ( V_93 )
F_65 ( & V_93 -> V_94 ) ;
F_94 ( V_106 ) ;
return V_93 ;
}
void F_95 ( struct V_95 * V_93 )
{
struct V_98 * V_99 ;
if ( F_96 ( & V_93 -> V_94 ) ) {
F_87 ( V_93 ) ;
F_34 () ;
V_99 = F_88 ( V_93 ) ;
if ( V_99 != & V_93 -> V_107 )
F_97 ( V_108 , V_93 ) ;
F_98 ( V_99 ) ;
F_37 () ;
}
}
void F_99 ( struct V_95 * V_93 )
{
struct V_1 * V_19 = V_66 ;
struct V_95 * V_109 ;
V_109 = V_19 -> V_93 ;
F_93 ( V_19 ) ;
V_19 -> V_93 = V_93 ;
F_94 ( V_19 ) ;
F_95 ( V_109 ) ;
}
void F_86 ( struct V_1 * V_19 )
{
struct V_95 * V_93 = V_19 -> V_93 ;
if ( V_93 ) {
F_93 ( V_19 ) ;
V_19 -> V_93 = NULL ;
F_94 ( V_19 ) ;
F_95 ( V_93 ) ;
}
}
void F_100 ( struct V_110 * V_111 )
{
struct V_1 * V_112 , * V_113 , * V_2 = V_66 ;
V_114:
if ( V_111 -> V_115 != V_2 )
return;
if ( F_101 ( & V_111 -> V_116 ) <= 1 ) {
V_111 -> V_115 = NULL ;
return;
}
F_55 ( & V_55 ) ;
F_102 (c, &p->children, sibling) {
if ( V_112 -> V_111 == V_111 )
goto V_117;
}
F_102 (c, &p->real_parent->children, sibling) {
if ( V_112 -> V_111 == V_111 )
goto V_117;
}
F_103 (g, c) {
if ( V_112 -> V_111 == V_111 )
goto V_117;
} F_104 ( V_113 , V_112 ) ;
F_56 ( & V_55 ) ;
V_111 -> V_115 = NULL ;
return;
V_117:
F_105 ( V_112 == V_2 ) ;
F_106 ( V_112 ) ;
F_93 ( V_112 ) ;
F_56 ( & V_55 ) ;
if ( V_112 -> V_111 != V_111 ) {
F_94 ( V_112 ) ;
F_32 ( V_112 ) ;
goto V_114;
}
V_111 -> V_115 = V_112 ;
F_94 ( V_112 ) ;
F_32 ( V_112 ) ;
}
static void F_78 ( struct V_1 * V_19 )
{
struct V_110 * V_111 = V_19 -> V_111 ;
struct V_118 * V_118 ;
F_107 ( V_19 , V_111 ) ;
if ( ! V_111 )
return;
F_108 ( V_111 ) ;
F_109 ( & V_111 -> V_119 ) ;
V_118 = V_111 -> V_118 ;
if ( V_118 ) {
struct V_120 V_121 ;
F_110 ( & V_111 -> V_119 ) ;
V_121 . V_106 = V_19 ;
V_121 . V_122 = F_89 ( & V_118 -> V_123 . V_122 , & V_121 ) ;
if ( F_96 ( & V_118 -> V_4 ) )
F_111 ( & V_118 -> V_124 ) ;
for (; ; ) {
F_112 ( V_19 , V_125 ) ;
if ( ! V_121 . V_106 )
break;
F_113 () ;
}
F_114 ( V_19 , V_126 ) ;
F_109 ( & V_111 -> V_119 ) ;
}
F_65 ( & V_111 -> V_127 ) ;
F_105 ( V_111 != V_19 -> V_128 ) ;
F_93 ( V_19 ) ;
V_19 -> V_111 = NULL ;
F_110 ( & V_111 -> V_119 ) ;
F_115 ( V_111 , V_66 ) ;
F_94 ( V_19 ) ;
F_100 ( V_111 ) ;
F_116 ( V_111 ) ;
}
static struct V_1 * F_117 ( struct V_1 * V_129 )
__releases( &tasklist_lock
void F_118 ( struct V_1 * V_129 , struct V_1 * V_2 ,
struct V_130 * V_131 )
{
F_62 ( & V_2 -> V_9 , & V_2 -> V_13 -> V_15 ) ;
if ( V_2 -> V_57 == V_60 )
return;
if ( F_119 ( V_2 -> V_13 , V_129 ) )
return;
V_2 -> V_59 = V_72 ;
if ( ! V_2 -> V_132 &&
V_2 -> V_57 == V_58 && F_41 ( V_2 ) ) {
if ( F_42 ( V_2 , V_2 -> V_59 ) ) {
V_2 -> V_57 = V_60 ;
F_62 ( & V_2 -> V_9 , V_131 ) ;
}
}
F_58 ( V_2 , V_129 ) ;
}
static void F_120 ( struct V_1 * V_129 )
{
struct V_1 * V_2 , * V_133 , * V_134 ;
F_121 ( V_135 ) ;
F_39 ( & V_55 ) ;
F_122 ( V_129 ) ;
V_134 = F_117 ( V_129 ) ;
F_123 (p, n, &father->children, sibling) {
struct V_1 * V_136 = V_2 ;
do {
V_136 -> V_13 = V_134 ;
if ( V_136 -> V_12 == V_129 ) {
F_105 ( V_136 -> V_132 ) ;
V_136 -> V_12 = V_136 -> V_13 ;
}
if ( V_136 -> V_137 )
F_124 ( V_136 -> V_137 ,
V_138 , V_136 ) ;
} while_each_thread(p, t) ;
F_118 ( V_129 , V_2 , & V_135 ) ;
}
void F_125 ( struct V_1 * V_19 , int V_3 )
{
bool V_139 ;
F_120 ( V_19 ) ;
F_126 ( V_19 ) ;
F_39 ( & V_55 ) ;
if ( V_3 )
F_58 ( V_19 -> V_56 , NULL ) ;
if ( F_17 ( V_19 -> V_132 ) ) {
int V_21 = F_11 ( V_19 ) &&
F_41 ( V_19 ) &&
! F_127 ( V_19 ) ?
V_19 -> V_59 : V_72 ;
V_139 = F_42 ( V_19 , V_21 ) ;
} else if ( F_11 ( V_19 ) ) {
V_139 = F_41 ( V_19 ) &&
F_42 ( V_19 , V_19 -> V_59 ) ;
} else {
V_139 = true ;
}
V_19 -> V_57 = V_139 ? V_60 : V_58 ;
if ( F_17 ( V_19 -> signal -> V_28 < 0 ) )
F_9 ( V_19 -> signal -> V_29 ) ;
F_43 ( & V_55 ) ;
if ( V_139 )
F_33 ( V_19 ) ;
}
static void F_128 ( void )
{
static F_129 ( V_140 ) ;
static int V_141 = V_142 ;
unsigned long free ;
free = F_130 ( V_66 ) ;
if ( free >= V_141 )
return;
F_14 ( & V_140 ) ;
if ( free < V_141 ) {
F_131 ( V_143 L_1
L_2 ,
V_66 -> V_86 , F_132 ( V_66 ) , free ) ;
V_141 = free ;
}
F_24 ( & V_140 ) ;
}
static inline void F_128 ( void ) {}
void F_133 ( long V_144 )
{
struct V_1 * V_19 = V_66 ;
int V_3 ;
F_134 ( V_19 ) ;
F_135 ( F_136 ( V_19 ) ) ;
if ( F_17 ( F_137 () ) )
F_138 ( L_3 ) ;
if ( F_17 ( ! V_19 -> V_61 ) )
F_138 ( L_4 ) ;
F_139 ( V_145 ) ;
F_140 ( V_146 , V_144 ) ;
F_141 ( V_19 ) ;
if ( F_17 ( V_19 -> V_16 & V_17 ) ) {
F_131 ( V_147
L_5 ) ;
V_19 -> V_16 |= V_148 ;
F_142 ( V_125 ) ;
F_113 () ;
}
F_143 ( V_19 ) ;
F_144 () ;
F_145 ( & V_19 -> V_149 ) ;
if ( F_17 ( F_146 () ) )
F_131 ( V_150 L_6 ,
V_66 -> V_86 , F_132 ( V_66 ) ,
F_147 () ) ;
F_148 ( V_19 ) ;
if ( V_19 -> V_111 )
F_108 ( V_19 -> V_111 ) ;
V_3 = F_96 ( & V_19 -> signal -> V_151 ) ;
if ( V_3 ) {
F_149 ( & V_19 -> signal -> V_152 ) ;
F_150 ( V_19 -> signal ) ;
if ( V_19 -> V_111 )
F_151 ( & V_19 -> signal -> V_153 , V_19 -> V_111 ) ;
}
F_152 ( V_144 , V_3 ) ;
if ( V_3 )
F_153 () ;
F_154 ( V_19 ) ;
V_19 -> V_154 = V_144 ;
F_155 ( V_19 , V_3 ) ;
F_78 ( V_19 ) ;
if ( V_3 )
F_156 () ;
F_157 ( V_19 ) ;
F_158 ( V_19 ) ;
F_159 ( V_19 ) ;
F_86 ( V_19 ) ;
F_160 ( V_19 ) ;
F_161 ( V_19 ) ;
F_128 () ;
F_162 () ;
F_163 ( V_19 ) ;
F_164 ( V_19 , 1 ) ;
if ( V_3 )
F_165 ( 1 ) ;
F_166 ( F_167 ( V_19 ) -> V_155 -> V_156 ) ;
F_168 ( V_19 ) ;
F_169 ( V_19 ) ;
F_125 ( V_19 , V_3 ) ;
#ifdef F_170
F_93 ( V_19 ) ;
F_171 ( V_19 -> V_157 ) ;
V_19 -> V_157 = NULL ;
F_94 ( V_19 ) ;
#endif
#ifdef F_172
if ( F_17 ( V_66 -> V_158 ) )
F_173 ( V_66 -> V_158 ) ;
#endif
F_174 ( V_19 ) ;
V_19 -> V_16 |= V_148 ;
if ( V_19 -> V_159 )
F_175 ( V_19 ) ;
if ( V_19 -> V_160 )
F_176 ( V_19 -> V_160 ) ;
F_141 ( V_19 ) ;
F_177 () ;
if ( V_19 -> V_161 )
F_178 ( V_162 , V_19 -> V_161 ) ;
F_179 () ;
F_144 () ;
F_145 ( & V_19 -> V_149 ) ;
V_19 -> V_163 = V_164 ;
V_19 -> V_16 |= V_87 ;
F_113 () ;
F_180 () ;
for (; ; )
F_181 () ;
}
void F_182 ( struct V_165 * V_166 , long V_144 )
{
if ( V_166 )
F_111 ( V_166 ) ;
F_133 ( V_144 ) ;
}
void
F_183 ( int V_154 )
{
struct V_20 * V_21 = V_66 -> signal ;
F_105 ( V_154 & 0x80 ) ;
if ( F_184 ( V_21 ) )
V_154 = V_21 -> V_167 ;
else if ( ! F_41 ( V_66 ) ) {
struct V_22 * const V_23 = V_66 -> V_23 ;
F_72 ( & V_23 -> V_27 ) ;
if ( F_184 ( V_21 ) )
V_154 = V_21 -> V_167 ;
else {
V_21 -> V_167 = V_154 ;
V_21 -> V_16 = V_168 ;
F_185 ( V_66 ) ;
}
F_75 ( & V_23 -> V_27 ) ;
}
F_133 ( V_154 ) ;
}
static inline
struct V_61 * F_186 ( struct V_1 * V_106 , enum V_169 type )
{
if ( type != V_5 )
V_106 = V_106 -> V_56 ;
return V_106 -> V_170 [ type ] . V_61 ;
}
static int F_187 ( struct V_171 * V_172 , struct V_1 * V_2 )
{
return V_172 -> V_173 == V_174 ||
F_186 ( V_2 , V_172 -> V_173 ) == V_172 -> V_175 ;
}
static int F_188 ( struct V_171 * V_172 , struct V_1 * V_2 )
{
if ( ! F_187 ( V_172 , V_2 ) )
return 0 ;
if ( ( ( V_2 -> V_59 != V_72 ) ^ ! ! ( V_172 -> V_176 & V_177 ) )
&& ! ( V_172 -> V_176 & V_178 ) )
return 0 ;
return 1 ;
}
static int F_189 ( struct V_171 * V_172 , struct V_1 * V_2 ,
T_3 V_61 , T_4 V_179 , int V_180 , int V_181 )
{
struct V_182 V_83 * V_183 ;
int V_65 = V_172 -> V_184
? F_190 ( V_2 , V_185 , V_172 -> V_184 ) : 0 ;
F_32 ( V_2 ) ;
V_183 = V_172 -> V_186 ;
if ( V_183 ) {
if ( ! V_65 )
V_65 = F_191 ( V_72 , & V_183 -> V_187 ) ;
if ( ! V_65 )
V_65 = F_191 ( 0 , & V_183 -> V_188 ) ;
if ( ! V_65 )
V_65 = F_191 ( ( short ) V_180 , & V_183 -> V_189 ) ;
if ( ! V_65 )
V_65 = F_191 ( V_61 , & V_183 -> V_190 ) ;
if ( ! V_65 )
V_65 = F_191 ( V_179 , & V_183 -> V_191 ) ;
if ( ! V_65 )
V_65 = F_191 ( V_181 , & V_183 -> V_192 ) ;
}
if ( ! V_65 )
V_65 = V_61 ;
return V_65 ;
}
static int F_192 ( struct V_171 * V_172 , struct V_1 * V_2 )
{
unsigned long V_163 ;
int V_65 , V_181 , V_193 ;
T_3 V_61 = F_193 ( V_2 ) ;
T_4 V_179 = F_194 ( F_195 () , F_196 ( V_2 ) ) ;
struct V_182 V_83 * V_183 ;
if ( ! F_197 ( V_172 -> V_176 & V_194 ) )
return 0 ;
if ( F_17 ( V_172 -> V_176 & V_195 ) ) {
int V_154 = V_2 -> V_154 ;
int V_180 ;
F_106 ( V_2 ) ;
F_56 ( & V_55 ) ;
if ( ( V_154 & 0x7f ) == 0 ) {
V_180 = V_196 ;
V_181 = V_154 >> 8 ;
} else {
V_180 = ( V_154 & 0x80 ) ? V_197 : V_198 ;
V_181 = V_154 & 0x7f ;
}
return F_189 ( V_172 , V_2 , V_61 , V_179 , V_180 , V_181 ) ;
}
V_163 = F_89 ( & V_2 -> V_57 , V_60 ) ;
if ( V_163 != V_58 ) {
F_105 ( V_163 != V_60 ) ;
return 0 ;
}
V_193 = F_127 ( V_2 ) ;
if ( F_197 ( ! V_193 ) && F_11 ( V_2 ) ) {
struct V_20 * V_199 ;
struct V_20 * V_21 ;
unsigned long V_153 ;
T_5 V_200 , V_201 ;
F_198 ( V_2 , & V_200 , & V_201 ) ;
F_72 ( & V_2 -> V_13 -> V_23 -> V_27 ) ;
V_199 = V_2 -> V_13 -> signal ;
V_21 = V_2 -> signal ;
V_199 -> V_202 += V_200 + V_21 -> V_202 ;
V_199 -> V_203 += V_201 + V_21 -> V_203 ;
V_199 -> V_204 += V_2 -> V_33 + V_21 -> V_33 + V_21 -> V_204 ;
V_199 -> V_205 +=
V_2 -> V_34 + V_21 -> V_34 + V_21 -> V_205 ;
V_199 -> V_206 +=
V_2 -> V_35 + V_21 -> V_35 + V_21 -> V_206 ;
V_199 -> V_207 +=
V_2 -> V_36 + V_21 -> V_36 + V_21 -> V_207 ;
V_199 -> V_208 +=
V_2 -> V_37 + V_21 -> V_37 + V_21 -> V_208 ;
V_199 -> V_209 +=
F_20 ( V_2 ) +
V_21 -> V_38 + V_21 -> V_209 ;
V_199 -> V_210 +=
F_21 ( V_2 ) +
V_21 -> V_39 + V_21 -> V_210 ;
V_153 = F_199 ( V_21 -> V_153 , V_21 -> V_211 ) ;
if ( V_199 -> V_211 < V_153 )
V_199 -> V_211 = V_153 ;
F_22 ( & V_199 -> V_40 , & V_2 -> V_40 ) ;
F_22 ( & V_199 -> V_40 , & V_21 -> V_40 ) ;
F_75 ( & V_2 -> V_13 -> V_23 -> V_27 ) ;
}
F_56 ( & V_55 ) ;
V_65 = V_172 -> V_184
? F_190 ( V_2 , V_185 , V_172 -> V_184 ) : 0 ;
V_181 = ( V_2 -> signal -> V_16 & V_168 )
? V_2 -> signal -> V_167 : V_2 -> V_154 ;
if ( ! V_65 && V_172 -> V_212 )
V_65 = F_191 ( V_181 , V_172 -> V_212 ) ;
V_183 = V_172 -> V_186 ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_72 , & V_183 -> V_187 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( 0 , & V_183 -> V_188 ) ;
if ( ! V_65 && V_183 ) {
int V_180 ;
if ( ( V_181 & 0x7f ) == 0 ) {
V_180 = V_196 ;
V_181 >>= 8 ;
} else {
V_180 = ( V_181 & 0x80 ) ? V_197 : V_198 ;
V_181 &= 0x7f ;
}
V_65 = F_191 ( ( short ) V_180 , & V_183 -> V_189 ) ;
if ( ! V_65 )
V_65 = F_191 ( V_181 , & V_183 -> V_192 ) ;
}
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_61 , & V_183 -> V_190 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_179 , & V_183 -> V_191 ) ;
if ( ! V_65 )
V_65 = V_61 ;
if ( V_193 ) {
F_39 ( & V_55 ) ;
F_61 ( V_2 ) ;
if ( F_11 ( V_2 ) &&
! F_42 ( V_2 , V_2 -> V_59 ) ) {
V_2 -> V_57 = V_58 ;
V_2 = NULL ;
}
F_43 ( & V_55 ) ;
}
if ( V_2 != NULL )
F_33 ( V_2 ) ;
return V_65 ;
}
static int * F_200 ( struct V_1 * V_2 , bool V_132 )
{
if ( V_132 ) {
if ( F_201 ( V_2 ) &&
! ( V_2 -> V_213 & V_214 ) )
return & V_2 -> V_154 ;
} else {
if ( V_2 -> signal -> V_16 & V_67 )
return & V_2 -> signal -> V_167 ;
}
return NULL ;
}
static int F_202 ( struct V_171 * V_172 ,
int V_132 , struct V_1 * V_2 )
{
struct V_182 V_83 * V_183 ;
int V_65 , V_154 , * V_215 , V_180 ;
T_4 V_179 = 0 ;
T_3 V_61 ;
if ( ! V_132 && ! ( V_172 -> V_176 & V_216 ) )
return 0 ;
if ( ! F_200 ( V_2 , V_132 ) )
return 0 ;
V_154 = 0 ;
F_72 ( & V_2 -> V_23 -> V_27 ) ;
V_215 = F_200 ( V_2 , V_132 ) ;
if ( F_17 ( ! V_215 ) )
goto V_217;
V_154 = * V_215 ;
if ( ! V_154 )
goto V_217;
if ( ! F_17 ( V_172 -> V_176 & V_195 ) )
* V_215 = 0 ;
V_179 = F_194 ( F_195 () , F_196 ( V_2 ) ) ;
V_217:
F_75 ( & V_2 -> V_23 -> V_27 ) ;
if ( ! V_154 )
return 0 ;
F_106 ( V_2 ) ;
V_61 = F_193 ( V_2 ) ;
V_180 = V_132 ? V_218 : V_219 ;
F_56 ( & V_55 ) ;
if ( F_17 ( V_172 -> V_176 & V_195 ) )
return F_189 ( V_172 , V_2 , V_61 , V_179 , V_180 , V_154 ) ;
V_65 = V_172 -> V_184
? F_190 ( V_2 , V_185 , V_172 -> V_184 ) : 0 ;
if ( ! V_65 && V_172 -> V_212 )
V_65 = F_191 ( ( V_154 << 8 ) | 0x7f , V_172 -> V_212 ) ;
V_183 = V_172 -> V_186 ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_72 , & V_183 -> V_187 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( 0 , & V_183 -> V_188 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( ( short ) V_180 , & V_183 -> V_189 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_154 , & V_183 -> V_192 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_61 , & V_183 -> V_190 ) ;
if ( ! V_65 && V_183 )
V_65 = F_191 ( V_179 , & V_183 -> V_191 ) ;
if ( ! V_65 )
V_65 = V_61 ;
F_32 ( V_2 ) ;
F_105 ( ! V_65 ) ;
return V_65 ;
}
static int F_203 ( struct V_171 * V_172 , struct V_1 * V_2 )
{
int V_65 ;
T_3 V_61 ;
T_4 V_179 ;
if ( ! F_17 ( V_172 -> V_176 & V_220 ) )
return 0 ;
if ( ! ( V_2 -> signal -> V_16 & V_221 ) )
return 0 ;
F_72 ( & V_2 -> V_23 -> V_27 ) ;
if ( ! ( V_2 -> signal -> V_16 & V_221 ) ) {
F_75 ( & V_2 -> V_23 -> V_27 ) ;
return 0 ;
}
if ( ! F_17 ( V_172 -> V_176 & V_195 ) )
V_2 -> signal -> V_16 &= ~ V_221 ;
V_179 = F_194 ( F_195 () , F_196 ( V_2 ) ) ;
F_75 ( & V_2 -> V_23 -> V_27 ) ;
V_61 = F_193 ( V_2 ) ;
F_106 ( V_2 ) ;
F_56 ( & V_55 ) ;
if ( ! V_172 -> V_186 ) {
V_65 = V_172 -> V_184
? F_190 ( V_2 , V_185 , V_172 -> V_184 ) : 0 ;
F_32 ( V_2 ) ;
if ( ! V_65 && V_172 -> V_212 )
V_65 = F_191 ( 0xffff , V_172 -> V_212 ) ;
if ( ! V_65 )
V_65 = V_61 ;
} else {
V_65 = F_189 ( V_172 , V_2 , V_61 , V_179 ,
V_222 , V_70 ) ;
F_105 ( V_65 == 0 ) ;
}
return V_65 ;
}
static int F_204 ( struct V_171 * V_172 , int V_132 ,
struct V_1 * V_2 )
{
int V_223 = F_188 ( V_172 , V_2 ) ;
if ( ! V_223 )
return V_223 ;
V_223 = F_205 ( V_2 ) ;
if ( F_17 ( V_223 < 0 ) ) {
if ( V_172 -> V_224 )
V_172 -> V_224 = V_223 ;
return 0 ;
}
if ( F_17 ( V_2 -> V_57 == V_60 ) ) {
if ( F_197 ( ! V_132 ) && F_17 ( F_127 ( V_2 ) ) )
V_172 -> V_224 = 0 ;
return 0 ;
}
if ( V_2 -> V_57 == V_58 ) {
if ( F_197 ( ! V_132 ) && F_17 ( V_2 -> V_132 ) ) {
V_172 -> V_224 = 0 ;
return 0 ;
}
if ( ! F_206 ( V_2 ) )
return F_192 ( V_172 , V_2 ) ;
if ( F_197 ( ! V_132 ) || ( V_172 -> V_176 & ( V_220 | V_194 ) ) )
V_172 -> V_224 = 0 ;
} else {
if ( F_197 ( ! V_132 ) && V_2 -> V_132 && ! F_127 ( V_2 ) )
return 0 ;
V_172 -> V_224 = 0 ;
}
V_223 = F_202 ( V_172 , V_132 , V_2 ) ;
if ( V_223 )
return V_223 ;
return F_203 ( V_172 , V_2 ) ;
}
static int F_207 ( struct V_171 * V_172 , struct V_1 * V_19 )
{
struct V_1 * V_2 ;
F_102 (p, &tsk->children, sibling) {
int V_223 = F_204 ( V_172 , 0 , V_2 ) ;
if ( V_223 )
return V_223 ;
}
return 0 ;
}
static int F_208 ( struct V_171 * V_172 , struct V_1 * V_19 )
{
struct V_1 * V_2 ;
F_102 (p, &tsk->ptraced, ptrace_entry) {
int V_223 = F_204 ( V_172 , 1 , V_2 ) ;
if ( V_223 )
return V_223 ;
}
return 0 ;
}
static int F_209 ( T_6 * V_225 , unsigned V_226 ,
int V_227 , void * V_228 )
{
struct V_171 * V_172 = F_29 ( V_225 , struct V_171 ,
V_229 ) ;
struct V_1 * V_2 = V_228 ;
if ( ! F_187 ( V_172 , V_2 ) )
return 0 ;
if ( ( V_172 -> V_176 & V_230 ) && V_225 -> V_231 != V_2 -> V_12 )
return 0 ;
return F_210 ( V_225 , V_226 , V_227 , V_228 ) ;
}
void F_211 ( struct V_1 * V_2 , struct V_1 * V_12 )
{
F_212 ( & V_12 -> signal -> V_232 ,
V_233 , 1 , V_2 ) ;
}
static long F_213 ( struct V_171 * V_172 )
{
struct V_1 * V_19 ;
int V_65 ;
F_214 ( V_172 -> V_175 ) ;
F_215 ( & V_172 -> V_229 , F_209 ) ;
V_172 -> V_229 . V_231 = V_66 ;
F_216 ( & V_66 -> signal -> V_232 , & V_172 -> V_229 ) ;
V_52:
V_172 -> V_224 = - V_234 ;
if ( ( V_172 -> V_173 < V_174 ) &&
( ! V_172 -> V_175 || F_217 ( & V_172 -> V_175 -> V_8 [ V_172 -> V_173 ] ) ) )
goto V_235;
F_142 ( V_233 ) ;
F_55 ( & V_55 ) ;
V_19 = V_66 ;
do {
V_65 = F_207 ( V_172 , V_19 ) ;
if ( V_65 )
goto V_236;
V_65 = F_208 ( V_172 , V_19 ) ;
if ( V_65 )
goto V_236;
if ( V_172 -> V_176 & V_230 )
break;
} while_each_thread(current, tsk) ;
