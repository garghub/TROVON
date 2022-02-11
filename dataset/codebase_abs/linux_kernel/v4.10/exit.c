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
}
F_3 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_12 ) ;
}
static void F_6 ( struct V_1 * V_13 )
{
struct V_14 * V_15 = V_13 -> signal ;
bool V_3 = F_7 ( V_13 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 ( V_20 ) ;
T_1 V_21 , V_22 ;
V_17 = F_8 ( V_13 -> V_17 ,
F_9 () ) ;
F_10 ( & V_17 -> V_23 ) ;
#ifdef F_11
F_12 ( V_13 ) ;
if ( V_3 ) {
F_13 ( V_13 ) ;
} else {
if ( F_14 ( F_15 ( V_13 ) ) )
F_13 ( V_13 ) ;
}
#endif
if ( V_3 ) {
V_20 = V_15 -> V_20 ;
V_15 -> V_20 = NULL ;
} else {
if ( V_15 -> V_24 > 0 && ! -- V_15 -> V_24 )
F_16 ( V_15 -> V_25 ) ;
if ( V_13 == V_15 -> V_26 )
V_15 -> V_26 = F_17 ( V_13 ) ;
}
F_18 ( ( const void * ) & V_13 -> V_27 . V_28 ,
sizeof( unsigned long long ) ) ;
F_19 ( V_13 , & V_21 , & V_22 ) ;
F_20 ( & V_15 -> V_29 ) ;
V_15 -> V_21 += V_21 ;
V_15 -> V_22 += V_22 ;
V_15 -> V_30 += F_21 ( V_13 ) ;
V_15 -> V_31 += V_13 -> V_31 ;
V_15 -> V_32 += V_13 -> V_32 ;
V_15 -> V_33 += V_13 -> V_33 ;
V_15 -> V_34 += V_13 -> V_34 ;
V_15 -> V_35 += F_22 ( V_13 ) ;
V_15 -> V_36 += F_23 ( V_13 ) ;
F_24 ( & V_15 -> V_37 , & V_13 -> V_37 ) ;
V_15 -> V_38 += V_13 -> V_27 . V_28 ;
V_15 -> V_4 -- ;
F_1 ( V_13 , V_3 ) ;
F_25 ( & V_15 -> V_29 ) ;
F_26 ( & V_13 -> V_39 ) ;
V_13 -> V_17 = NULL ;
F_27 ( & V_17 -> V_23 ) ;
F_28 ( V_17 ) ;
F_29 ( V_13 , V_40 ) ;
if ( V_3 ) {
F_26 ( & V_15 -> V_41 ) ;
F_30 ( V_20 ) ;
}
}
static void F_31 ( struct V_42 * V_43 )
{
struct V_1 * V_13 = F_32 ( V_43 , struct V_1 , V_44 ) ;
F_33 ( V_13 ) ;
F_34 ( V_13 ) ;
F_35 ( V_13 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_1 * V_45 ;
int V_46 ;
V_47:
F_37 () ;
F_38 ( & F_39 ( V_2 ) -> V_48 -> V_49 ) ;
F_40 () ;
F_41 ( V_2 ) ;
F_42 ( & V_50 ) ;
F_43 ( V_2 ) ;
F_6 ( V_2 ) ;
V_46 = 0 ;
V_45 = V_2 -> V_51 ;
if ( V_45 != V_2 && F_44 ( V_45 )
&& V_45 -> V_52 == V_53 ) {
V_46 = F_45 ( V_45 , V_45 -> V_54 ) ;
if ( V_46 )
V_45 -> V_52 = V_55 ;
}
F_46 ( & V_50 ) ;
F_47 ( V_2 ) ;
F_48 ( & V_2 -> V_44 , F_31 ) ;
V_2 = V_45 ;
if ( F_14 ( V_46 ) )
goto V_47;
}
struct V_1 * F_49 ( struct V_1 * * V_56 )
{
struct V_16 * V_17 ;
struct V_1 * V_57 ;
V_58:
V_57 = F_50 ( * V_56 ) ;
if ( ! V_57 )
return NULL ;
F_51 ( & V_57 -> V_17 , V_17 ) ;
F_52 () ;
if ( F_14 ( V_57 != F_53 ( * V_56 ) ) )
goto V_58;
if ( ! V_17 )
return NULL ;
return V_57 ;
}
struct V_1 * F_54 ( struct V_1 * * V_56 )
{
struct V_1 * V_57 ;
F_37 () ;
V_57 = F_49 ( V_56 ) ;
if ( V_57 )
F_55 ( V_57 ) ;
F_40 () ;
return V_57 ;
}
static int F_56 ( struct V_59 * V_60 ,
struct V_1 * V_61 )
{
struct V_1 * V_2 ;
F_57 (pgrp, PIDTYPE_PGID, p) {
if ( ( V_2 == V_61 ) ||
( V_2 -> V_52 && F_44 ( V_2 ) ) ||
F_58 ( V_2 -> V_62 ) )
continue;
if ( F_59 ( V_2 -> V_62 ) != V_60 &&
F_60 ( V_2 -> V_62 ) == F_60 ( V_2 ) )
return 0 ;
} F_61 ( V_60 , V_6 , V_2 ) ;
return 1 ;
}
int F_62 ( void )
{
int V_63 ;
F_63 ( & V_50 ) ;
V_63 = F_56 ( F_59 ( V_64 ) , NULL ) ;
F_64 ( & V_50 ) ;
return V_63 ;
}
static bool F_65 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
F_57 (pgrp, PIDTYPE_PGID, p) {
if ( V_2 -> signal -> V_65 & V_66 )
return true ;
} F_61 ( V_60 , V_6 , V_2 ) ;
return false ;
}
static void
F_66 ( struct V_1 * V_13 , struct V_1 * V_67 )
{
struct V_59 * V_60 = F_59 ( V_13 ) ;
struct V_1 * V_61 = V_13 ;
if ( ! V_67 )
V_67 = V_13 -> V_62 ;
else
V_61 = NULL ;
if ( F_59 ( V_67 ) != V_60 &&
F_60 ( V_67 ) == F_60 ( V_13 ) &&
F_56 ( V_60 , V_61 ) &&
F_65 ( V_60 ) ) {
F_67 ( V_68 , V_69 , V_60 ) ;
F_67 ( V_70 , V_69 , V_60 ) ;
}
}
void F_68 ( struct V_71 * V_72 )
{
struct V_1 * V_73 , * V_74 , * V_2 = V_64 ;
V_58:
if ( V_72 -> V_75 != V_2 )
return;
if ( F_69 ( & V_72 -> V_76 ) <= 1 ) {
V_72 -> V_75 = NULL ;
return;
}
F_63 ( & V_50 ) ;
F_70 (c, &p->children, sibling) {
if ( V_73 -> V_72 == V_72 )
goto V_77;
}
F_70 (c, &p->real_parent->children, sibling) {
if ( V_73 -> V_72 == V_72 )
goto V_77;
}
F_71 (g) {
if ( V_74 -> V_65 & V_78 )
continue;
F_72 (g, c) {
if ( V_73 -> V_72 == V_72 )
goto V_77;
if ( V_73 -> V_72 )
break;
}
}
F_64 ( & V_50 ) ;
V_72 -> V_75 = NULL ;
return;
V_77:
F_73 ( V_73 == V_2 ) ;
F_55 ( V_73 ) ;
F_74 ( V_73 ) ;
F_64 ( & V_50 ) ;
if ( V_73 -> V_72 != V_72 ) {
F_75 ( V_73 ) ;
F_35 ( V_73 ) ;
goto V_58;
}
V_72 -> V_75 = V_73 ;
F_75 ( V_73 ) ;
F_35 ( V_73 ) ;
}
static void F_76 ( struct V_1 * V_13 )
{
struct V_71 * V_72 = V_13 -> V_72 ;
struct V_79 * V_79 ;
F_77 ( V_13 , V_72 ) ;
if ( ! V_72 )
return;
F_78 ( V_72 ) ;
F_79 ( & V_72 -> V_80 ) ;
V_79 = V_72 -> V_79 ;
if ( V_79 ) {
struct V_81 V_82 ;
F_80 ( & V_72 -> V_80 ) ;
V_82 . V_57 = V_13 ;
V_82 . V_83 = F_81 ( & V_79 -> V_84 . V_83 , & V_82 ) ;
if ( F_82 ( & V_79 -> V_4 ) )
F_83 ( & V_79 -> V_85 ) ;
for (; ; ) {
F_84 ( V_13 , V_86 ) ;
if ( ! V_82 . V_57 )
break;
F_85 () ;
}
F_86 ( V_13 , V_87 ) ;
F_79 ( & V_72 -> V_80 ) ;
}
F_87 ( & V_72 -> V_88 ) ;
F_73 ( V_72 != V_13 -> V_89 ) ;
F_74 ( V_13 ) ;
V_13 -> V_72 = NULL ;
F_80 ( & V_72 -> V_80 ) ;
F_88 ( V_72 , V_64 ) ;
F_75 ( V_13 ) ;
F_68 ( V_72 ) ;
F_89 ( V_72 ) ;
if ( F_90 ( V_90 ) )
F_91 () ;
}
static struct V_1 * F_92 ( struct V_1 * V_2 )
{
struct V_1 * V_91 ;
F_72 (p, t) {
if ( ! ( V_91 -> V_65 & V_92 ) )
return V_91 ;
}
return NULL ;
}
static struct V_1 * F_93 ( struct V_1 * V_93 )
__releases( &tasklist_lock
static struct V_1 * F_94 ( struct V_1 * V_93 ,
struct V_1 * V_94 )
{
struct V_1 * V_95 , * V_96 ;
V_95 = F_92 ( V_93 ) ;
if ( V_95 )
return V_95 ;
if ( V_93 -> signal -> V_97 ) {
for ( V_96 = V_93 ;
! F_95 ( V_96 , V_94 ) ;
V_96 = V_96 -> V_62 ) {
if ( V_96 == & V_98 )
break;
if ( ! V_96 -> signal -> V_99 )
continue;
V_95 = F_92 ( V_96 ) ;
if ( V_95 )
return V_95 ;
}
}
return V_94 ;
}
static void F_96 ( struct V_1 * V_93 , struct V_1 * V_2 ,
struct V_100 * V_101 )
{
if ( F_14 ( V_2 -> V_52 == V_55 ) )
return;
V_2 -> V_54 = V_102 ;
if ( ! V_2 -> V_103 &&
V_2 -> V_52 == V_53 && F_44 ( V_2 ) ) {
if ( F_45 ( V_2 , V_2 -> V_54 ) ) {
V_2 -> V_52 = V_55 ;
F_97 ( & V_2 -> V_104 , V_101 ) ;
}
}
F_66 ( V_2 , V_93 ) ;
}
static void F_98 ( struct V_1 * V_93 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 , * V_91 , * V_96 ;
if ( F_14 ( ! F_99 ( & V_93 -> V_105 ) ) )
F_100 ( V_93 , V_101 ) ;
V_96 = F_93 ( V_93 ) ;
if ( F_99 ( & V_93 -> V_106 ) )
return;
V_96 = F_94 ( V_93 , V_96 ) ;
F_70 (p, &father->children, sibling) {
F_72 (p, t) {
V_91 -> V_62 = V_96 ;
F_73 ( ( ! V_91 -> V_103 ) != ( V_91 -> V_67 == V_93 ) ) ;
if ( F_101 ( ! V_91 -> V_103 ) )
V_91 -> V_67 = V_91 -> V_62 ;
if ( V_91 -> V_107 )
F_102 ( V_91 -> V_107 ,
V_108 , V_91 ) ;
}
if ( ! F_95 ( V_96 , V_93 ) )
F_96 ( V_93 , V_2 , V_101 ) ;
}
F_103 ( & V_93 -> V_106 , & V_96 -> V_106 ) ;
}
static void F_104 ( struct V_1 * V_13 , int V_3 )
{
bool V_109 ;
struct V_1 * V_2 , * V_110 ;
F_105 ( V_101 ) ;
F_42 ( & V_50 ) ;
F_98 ( V_13 , & V_101 ) ;
if ( V_3 )
F_66 ( V_13 -> V_51 , NULL ) ;
if ( F_14 ( V_13 -> V_103 ) ) {
int V_15 = F_7 ( V_13 ) &&
F_44 ( V_13 ) &&
! F_106 ( V_13 ) ?
V_13 -> V_54 : V_102 ;
V_109 = F_45 ( V_13 , V_15 ) ;
} else if ( F_7 ( V_13 ) ) {
V_109 = F_44 ( V_13 ) &&
F_45 ( V_13 , V_13 -> V_54 ) ;
} else {
V_109 = true ;
}
V_13 -> V_52 = V_109 ? V_55 : V_53 ;
if ( V_13 -> V_52 == V_55 )
F_97 ( & V_13 -> V_104 , & V_101 ) ;
if ( F_14 ( V_13 -> signal -> V_24 < 0 ) )
F_16 ( V_13 -> signal -> V_25 ) ;
F_46 ( & V_50 ) ;
F_107 (p, n, &dead, ptrace_entry) {
F_4 ( & V_2 -> V_104 ) ;
F_36 ( V_2 ) ;
}
}
static void F_108 ( void )
{
static F_109 ( V_111 ) ;
static int V_112 = V_113 ;
unsigned long free ;
free = F_110 ( V_64 ) ;
if ( free >= V_112 )
return;
F_10 ( & V_111 ) ;
if ( free < V_112 ) {
F_111 ( L_1 ,
V_64 -> V_114 , F_112 ( V_64 ) , free ) ;
V_112 = free ;
}
F_27 ( & V_111 ) ;
}
static inline void F_108 ( void ) {}
void T_2 F_113 ( long V_115 )
{
struct V_1 * V_13 = V_64 ;
int V_3 ;
F_114 (int tasks_rcu_i) ;
F_115 ( V_13 ) ;
F_116 ( V_13 ) ;
F_117 ( F_118 ( V_13 ) ) ;
if ( F_14 ( F_119 () ) )
F_120 ( L_2 ) ;
if ( F_14 ( ! V_13 -> V_59 ) )
F_120 ( L_3 ) ;
F_121 ( V_116 ) ;
F_122 ( V_117 , V_115 ) ;
F_123 ( V_13 ) ;
if ( F_14 ( V_13 -> V_65 & V_92 ) ) {
F_124 ( L_4 ) ;
V_13 -> V_65 |= V_118 ;
F_125 ( V_86 ) ;
F_126 () ;
}
F_127 ( V_13 ) ;
F_128 () ;
F_129 ( & V_13 -> V_119 ) ;
if ( F_14 ( F_130 () ) ) {
F_111 ( L_5 ,
V_64 -> V_114 , F_112 ( V_64 ) ,
F_131 () ) ;
F_132 ( V_120 ) ;
}
if ( V_13 -> V_72 )
F_78 ( V_13 -> V_72 ) ;
F_133 ( V_13 ) ;
V_3 = F_82 ( & V_13 -> signal -> V_121 ) ;
if ( V_3 ) {
#ifdef F_11
F_134 ( & V_13 -> signal -> V_122 ) ;
F_135 ( V_13 -> signal ) ;
#endif
if ( V_13 -> V_72 )
F_136 ( & V_13 -> signal -> V_123 , V_13 -> V_72 ) ;
}
F_137 ( V_115 , V_3 ) ;
if ( V_3 )
F_138 () ;
F_139 ( V_13 ) ;
V_13 -> V_124 = V_115 ;
F_140 ( V_13 , V_3 ) ;
F_76 ( V_13 ) ;
if ( V_3 )
F_141 () ;
F_142 ( V_13 ) ;
F_143 ( V_13 ) ;
F_144 ( V_13 ) ;
F_145 ( V_13 ) ;
F_146 ( V_13 ) ;
if ( V_3 )
F_147 ( 1 ) ;
F_148 ( V_13 ) ;
F_149 ( V_13 ) ;
F_150 ( V_13 ) ;
F_151 ( V_13 ) ;
F_152 ( V_13 ) ;
F_153 ( V_13 ) ;
F_154 ( V_13 ) ;
F_114 ( F_155 () ) ;
F_114 ( V_125 = F_156 ( & V_126 ) ) ;
F_114 ( F_157 () ) ;
F_104 ( V_13 , V_3 ) ;
F_158 ( V_13 ) ;
F_159 ( V_13 ) ;
#ifdef F_160
if ( F_14 ( V_64 -> V_127 ) )
F_161 ( V_64 -> V_127 ) ;
#endif
F_162 () ;
V_13 -> V_65 |= V_118 ;
if ( V_13 -> V_128 )
F_163 ( V_13 ) ;
if ( V_13 -> V_129 )
F_164 ( V_13 -> V_129 ) ;
if ( V_13 -> V_130 . V_131 )
F_165 ( V_13 -> V_130 . V_131 ) ;
F_123 ( V_13 ) ;
F_108 () ;
F_155 () ;
if ( V_13 -> V_132 )
F_166 ( V_133 , V_13 -> V_132 ) ;
F_167 () ;
F_114 ( F_168 ( & V_126 , V_125 ) ) ;
F_169 () ;
}
void F_170 ( struct V_134 * V_135 , long V_115 )
{
if ( V_135 )
F_83 ( V_135 ) ;
F_113 ( V_115 ) ;
}
void
F_171 ( int V_124 )
{
struct V_14 * V_15 = V_64 -> signal ;
F_73 ( V_124 & 0x80 ) ;
if ( F_172 ( V_15 ) )
V_124 = V_15 -> V_136 ;
else if ( ! F_44 ( V_64 ) ) {
struct V_16 * const V_17 = V_64 -> V_17 ;
F_173 ( & V_17 -> V_23 ) ;
if ( F_172 ( V_15 ) )
V_124 = V_15 -> V_136 ;
else {
V_15 -> V_136 = V_124 ;
V_15 -> V_65 = V_137 ;
F_174 ( V_64 ) ;
}
F_175 ( & V_17 -> V_23 ) ;
}
F_113 ( V_124 ) ;
}
static inline
struct V_59 * F_176 ( struct V_1 * V_57 , enum V_138 type )
{
if ( type != V_5 )
V_57 = V_57 -> V_51 ;
return V_57 -> V_139 [ type ] . V_59 ;
}
static int F_177 ( struct V_140 * V_141 , struct V_1 * V_2 )
{
return V_141 -> V_142 == V_143 ||
F_176 ( V_2 , V_141 -> V_142 ) == V_141 -> V_144 ;
}
static int
F_178 ( struct V_140 * V_141 , bool V_103 , struct V_1 * V_2 )
{
if ( ! F_177 ( V_141 , V_2 ) )
return 0 ;
if ( V_103 || ( V_141 -> V_145 & V_146 ) )
return 1 ;
if ( ( V_2 -> V_54 != V_102 ) ^ ! ! ( V_141 -> V_145 & V_147 ) )
return 0 ;
return 1 ;
}
static int F_179 ( struct V_140 * V_141 , struct V_1 * V_2 ,
T_3 V_59 , T_4 V_148 , int V_149 , int V_150 )
{
struct V_151 T_5 * V_152 ;
int V_63 = V_141 -> V_153
? F_180 ( V_2 , V_154 , V_141 -> V_153 ) : 0 ;
F_35 ( V_2 ) ;
V_152 = V_141 -> V_155 ;
if ( V_152 ) {
if ( ! V_63 )
V_63 = F_181 ( V_102 , & V_152 -> V_156 ) ;
if ( ! V_63 )
V_63 = F_181 ( 0 , & V_152 -> V_157 ) ;
if ( ! V_63 )
V_63 = F_181 ( ( short ) V_149 , & V_152 -> V_158 ) ;
if ( ! V_63 )
V_63 = F_181 ( V_59 , & V_152 -> V_159 ) ;
if ( ! V_63 )
V_63 = F_181 ( V_148 , & V_152 -> V_160 ) ;
if ( ! V_63 )
V_63 = F_181 ( V_150 , & V_152 -> V_161 ) ;
}
if ( ! V_63 )
V_63 = V_59 ;
return V_63 ;
}
static int F_182 ( struct V_140 * V_141 , struct V_1 * V_2 )
{
int V_162 , V_63 , V_150 ;
T_3 V_59 = F_183 ( V_2 ) ;
T_4 V_148 = F_184 ( F_185 () , F_186 ( V_2 ) ) ;
struct V_151 T_5 * V_152 ;
if ( ! F_101 ( V_141 -> V_145 & V_163 ) )
return 0 ;
if ( F_14 ( V_141 -> V_145 & V_164 ) ) {
int V_124 = V_2 -> V_124 ;
int V_149 ;
F_55 ( V_2 ) ;
F_64 ( & V_50 ) ;
F_187 () ;
if ( ( V_124 & 0x7f ) == 0 ) {
V_149 = V_165 ;
V_150 = V_124 >> 8 ;
} else {
V_149 = ( V_124 & 0x80 ) ? V_166 : V_167 ;
V_150 = V_124 & 0x7f ;
}
return F_179 ( V_141 , V_2 , V_59 , V_148 , V_149 , V_150 ) ;
}
V_162 = ( F_106 ( V_2 ) && F_7 ( V_2 ) ) ?
V_168 : V_55 ;
if ( F_188 ( & V_2 -> V_52 , V_53 , V_162 ) != V_53 )
return 0 ;
F_64 ( & V_50 ) ;
F_187 () ;
if ( V_162 == V_55 && F_7 ( V_2 ) ) {
struct V_14 * V_15 = V_2 -> signal ;
struct V_14 * V_169 = V_64 -> signal ;
unsigned long V_123 ;
T_1 V_170 , V_171 ;
F_189 ( V_2 , & V_170 , & V_171 ) ;
F_173 ( & V_64 -> V_17 -> V_23 ) ;
F_20 ( & V_169 -> V_29 ) ;
V_169 -> V_172 += V_170 + V_15 -> V_172 ;
V_169 -> V_173 += V_171 + V_15 -> V_173 ;
V_169 -> V_174 += F_21 ( V_2 ) + V_15 -> V_30 + V_15 -> V_174 ;
V_169 -> V_175 +=
V_2 -> V_31 + V_15 -> V_31 + V_15 -> V_175 ;
V_169 -> V_176 +=
V_2 -> V_32 + V_15 -> V_32 + V_15 -> V_176 ;
V_169 -> V_177 +=
V_2 -> V_33 + V_15 -> V_33 + V_15 -> V_177 ;
V_169 -> V_178 +=
V_2 -> V_34 + V_15 -> V_34 + V_15 -> V_178 ;
V_169 -> V_179 +=
F_22 ( V_2 ) +
V_15 -> V_35 + V_15 -> V_179 ;
V_169 -> V_180 +=
F_23 ( V_2 ) +
V_15 -> V_36 + V_15 -> V_180 ;
V_123 = F_190 ( V_15 -> V_123 , V_15 -> V_181 ) ;
if ( V_169 -> V_181 < V_123 )
V_169 -> V_181 = V_123 ;
F_24 ( & V_169 -> V_37 , & V_2 -> V_37 ) ;
F_24 ( & V_169 -> V_37 , & V_15 -> V_37 ) ;
F_25 ( & V_169 -> V_29 ) ;
F_175 ( & V_64 -> V_17 -> V_23 ) ;
}
V_63 = V_141 -> V_153
? F_180 ( V_2 , V_154 , V_141 -> V_153 ) : 0 ;
V_150 = ( V_2 -> signal -> V_65 & V_137 )
? V_2 -> signal -> V_136 : V_2 -> V_124 ;
if ( ! V_63 && V_141 -> V_182 )
V_63 = F_181 ( V_150 , V_141 -> V_182 ) ;
V_152 = V_141 -> V_155 ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_102 , & V_152 -> V_156 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( 0 , & V_152 -> V_157 ) ;
if ( ! V_63 && V_152 ) {
int V_149 ;
if ( ( V_150 & 0x7f ) == 0 ) {
V_149 = V_165 ;
V_150 >>= 8 ;
} else {
V_149 = ( V_150 & 0x80 ) ? V_166 : V_167 ;
V_150 &= 0x7f ;
}
V_63 = F_181 ( ( short ) V_149 , & V_152 -> V_158 ) ;
if ( ! V_63 )
V_63 = F_181 ( V_150 , & V_152 -> V_161 ) ;
}
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_59 , & V_152 -> V_159 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_148 , & V_152 -> V_160 ) ;
if ( ! V_63 )
V_63 = V_59 ;
if ( V_162 == V_168 ) {
F_42 ( & V_50 ) ;
F_191 ( V_2 ) ;
V_162 = V_53 ;
if ( F_45 ( V_2 , V_2 -> V_54 ) )
V_162 = V_55 ;
V_2 -> V_52 = V_162 ;
F_46 ( & V_50 ) ;
}
if ( V_162 == V_55 )
F_36 ( V_2 ) ;
return V_63 ;
}
static int * F_192 ( struct V_1 * V_2 , bool V_103 )
{
if ( V_103 ) {
if ( F_193 ( V_2 ) && ! ( V_2 -> V_183 & V_184 ) )
return & V_2 -> V_124 ;
} else {
if ( V_2 -> signal -> V_65 & V_66 )
return & V_2 -> signal -> V_136 ;
}
return NULL ;
}
static int F_194 ( struct V_140 * V_141 ,
int V_103 , struct V_1 * V_2 )
{
struct V_151 T_5 * V_152 ;
int V_63 , V_124 , * V_185 , V_149 ;
T_4 V_148 = 0 ;
T_3 V_59 ;
if ( ! V_103 && ! ( V_141 -> V_145 & V_186 ) )
return 0 ;
if ( ! F_192 ( V_2 , V_103 ) )
return 0 ;
V_124 = 0 ;
F_173 ( & V_2 -> V_17 -> V_23 ) ;
V_185 = F_192 ( V_2 , V_103 ) ;
if ( F_14 ( ! V_185 ) )
goto V_187;
V_124 = * V_185 ;
if ( ! V_124 )
goto V_187;
if ( ! F_14 ( V_141 -> V_145 & V_164 ) )
* V_185 = 0 ;
V_148 = F_184 ( F_185 () , F_186 ( V_2 ) ) ;
V_187:
F_175 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! V_124 )
return 0 ;
F_55 ( V_2 ) ;
V_59 = F_183 ( V_2 ) ;
V_149 = V_103 ? V_188 : V_189 ;
F_64 ( & V_50 ) ;
F_187 () ;
if ( F_14 ( V_141 -> V_145 & V_164 ) )
return F_179 ( V_141 , V_2 , V_59 , V_148 , V_149 , V_124 ) ;
V_63 = V_141 -> V_153
? F_180 ( V_2 , V_154 , V_141 -> V_153 ) : 0 ;
if ( ! V_63 && V_141 -> V_182 )
V_63 = F_181 ( ( V_124 << 8 ) | 0x7f , V_141 -> V_182 ) ;
V_152 = V_141 -> V_155 ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_102 , & V_152 -> V_156 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( 0 , & V_152 -> V_157 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( ( short ) V_149 , & V_152 -> V_158 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_124 , & V_152 -> V_161 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_59 , & V_152 -> V_159 ) ;
if ( ! V_63 && V_152 )
V_63 = F_181 ( V_148 , & V_152 -> V_160 ) ;
if ( ! V_63 )
V_63 = V_59 ;
F_35 ( V_2 ) ;
F_73 ( ! V_63 ) ;
return V_63 ;
}
static int F_195 ( struct V_140 * V_141 , struct V_1 * V_2 )
{
int V_63 ;
T_3 V_59 ;
T_4 V_148 ;
if ( ! F_14 ( V_141 -> V_145 & V_190 ) )
return 0 ;
if ( ! ( V_2 -> signal -> V_65 & V_191 ) )
return 0 ;
F_173 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! ( V_2 -> signal -> V_65 & V_191 ) ) {
F_175 ( & V_2 -> V_17 -> V_23 ) ;
return 0 ;
}
if ( ! F_14 ( V_141 -> V_145 & V_164 ) )
V_2 -> signal -> V_65 &= ~ V_191 ;
V_148 = F_184 ( F_185 () , F_186 ( V_2 ) ) ;
F_175 ( & V_2 -> V_17 -> V_23 ) ;
V_59 = F_183 ( V_2 ) ;
F_55 ( V_2 ) ;
F_64 ( & V_50 ) ;
F_187 () ;
if ( ! V_141 -> V_155 ) {
V_63 = V_141 -> V_153
? F_180 ( V_2 , V_154 , V_141 -> V_153 ) : 0 ;
F_35 ( V_2 ) ;
if ( ! V_63 && V_141 -> V_182 )
V_63 = F_181 ( 0xffff , V_141 -> V_182 ) ;
if ( ! V_63 )
V_63 = V_59 ;
} else {
V_63 = F_179 ( V_141 , V_2 , V_59 , V_148 ,
V_192 , V_70 ) ;
F_73 ( V_63 == 0 ) ;
}
return V_63 ;
}
static int F_196 ( struct V_140 * V_141 , int V_103 ,
struct V_1 * V_2 )
{
int V_52 = F_197 ( V_2 -> V_52 ) ;
int V_193 ;
if ( F_14 ( V_52 == V_55 ) )
return 0 ;
V_193 = F_178 ( V_141 , V_103 , V_2 ) ;
if ( ! V_193 )
return V_193 ;
V_193 = F_198 ( V_2 ) ;
if ( F_14 ( V_193 < 0 ) ) {
if ( V_141 -> V_194 )
V_141 -> V_194 = V_193 ;
return 0 ;
}
if ( F_14 ( V_52 == V_168 ) ) {
if ( F_101 ( ! V_103 ) )
V_141 -> V_194 = 0 ;
return 0 ;
}
if ( F_101 ( ! V_103 ) && F_14 ( V_2 -> V_103 ) ) {
if ( ! F_106 ( V_2 ) )
V_103 = 1 ;
}
if ( V_52 == V_53 ) {
if ( ! F_199 ( V_2 ) ) {
if ( F_14 ( V_103 ) || F_101 ( ! V_2 -> V_103 ) )
return F_182 ( V_141 , V_2 ) ;
}
if ( F_101 ( ! V_103 ) || ( V_141 -> V_145 & ( V_190 | V_163 ) ) )
V_141 -> V_194 = 0 ;
} else {
V_141 -> V_194 = 0 ;
}
V_193 = F_194 ( V_141 , V_103 , V_2 ) ;
if ( V_193 )
return V_193 ;
return F_195 ( V_141 , V_2 ) ;
}
static int F_200 ( struct V_140 * V_141 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_70 (p, &tsk->children, sibling) {
int V_193 = F_196 ( V_141 , 0 , V_2 ) ;
if ( V_193 )
return V_193 ;
}
return 0 ;
}
static int F_201 ( struct V_140 * V_141 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_70 (p, &tsk->ptraced, ptrace_entry) {
int V_193 = F_196 ( V_141 , 1 , V_2 ) ;
if ( V_193 )
return V_193 ;
}
return 0 ;
}
static int F_202 ( T_6 * V_195 , unsigned V_196 ,
int V_197 , void * V_198 )
{
struct V_140 * V_141 = F_32 ( V_195 , struct V_140 ,
V_199 ) ;
struct V_1 * V_2 = V_198 ;
if ( ! F_177 ( V_141 , V_2 ) )
return 0 ;
if ( ( V_141 -> V_145 & V_200 ) && V_195 -> V_201 != V_2 -> V_67 )
return 0 ;
return F_203 ( V_195 , V_196 , V_197 , V_198 ) ;
}
void F_204 ( struct V_1 * V_2 , struct V_1 * V_67 )
{
F_205 ( & V_67 -> signal -> V_202 ,
V_203 , 1 , V_2 ) ;
}
static long F_206 ( struct V_140 * V_141 )
{
struct V_1 * V_13 ;
int V_63 ;
F_207 ( V_141 -> V_144 ) ;
F_208 ( & V_141 -> V_199 , F_202 ) ;
V_141 -> V_199 . V_201 = V_64 ;
F_209 ( & V_64 -> signal -> V_202 , & V_141 -> V_199 ) ;
V_47:
V_141 -> V_194 = - V_204 ;
if ( ( V_141 -> V_142 < V_143 ) &&
( ! V_141 -> V_144 || F_210 ( & V_141 -> V_144 -> V_8 [ V_141 -> V_142 ] ) ) )
goto V_205;
F_125 ( V_203 ) ;
F_63 ( & V_50 ) ;
V_13 = V_64 ;
do {
V_63 = F_200 ( V_141 , V_13 ) ;
if ( V_63 )
goto V_206;
V_63 = F_201 ( V_141 , V_13 ) ;
if ( V_63 )
goto V_206;
if ( V_141 -> V_145 & V_200 )
break;
} while_each_thread(current, tsk) ;
