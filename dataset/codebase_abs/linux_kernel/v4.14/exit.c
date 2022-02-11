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
void F_54 ( struct V_59 * V_60 )
{
struct V_1 * V_57 ;
F_37 () ;
F_52 () ;
V_57 = F_50 ( V_60 -> V_57 ) ;
if ( V_57 )
F_16 ( V_57 ) ;
F_40 () ;
}
static int F_55 ( struct V_61 * V_62 ,
struct V_1 * V_63 )
{
struct V_1 * V_2 ;
F_56 (pgrp, PIDTYPE_PGID, p) {
if ( ( V_2 == V_63 ) ||
( V_2 -> V_52 && F_44 ( V_2 ) ) ||
F_57 ( V_2 -> V_64 ) )
continue;
if ( F_58 ( V_2 -> V_64 ) != V_62 &&
F_59 ( V_2 -> V_64 ) == F_59 ( V_2 ) )
return 0 ;
} F_60 ( V_62 , V_6 , V_2 ) ;
return 1 ;
}
int F_61 ( void )
{
int V_65 ;
F_62 ( & V_50 ) ;
V_65 = F_55 ( F_58 ( V_66 ) , NULL ) ;
F_63 ( & V_50 ) ;
return V_65 ;
}
static bool F_64 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
F_56 (pgrp, PIDTYPE_PGID, p) {
if ( V_2 -> signal -> V_67 & V_68 )
return true ;
} F_60 ( V_62 , V_6 , V_2 ) ;
return false ;
}
static void
F_65 ( struct V_1 * V_13 , struct V_1 * V_69 )
{
struct V_61 * V_62 = F_58 ( V_13 ) ;
struct V_1 * V_63 = V_13 ;
if ( ! V_69 )
V_69 = V_13 -> V_64 ;
else
V_63 = NULL ;
if ( F_58 ( V_69 ) != V_62 &&
F_59 ( V_69 ) == F_59 ( V_13 ) &&
F_55 ( V_62 , V_63 ) &&
F_64 ( V_62 ) ) {
F_66 ( V_70 , V_71 , V_62 ) ;
F_66 ( V_72 , V_71 , V_62 ) ;
}
}
void F_67 ( struct V_73 * V_74 )
{
struct V_1 * V_75 , * V_76 , * V_2 = V_66 ;
V_58:
if ( V_74 -> V_77 != V_2 )
return;
if ( F_68 ( & V_74 -> V_78 ) <= 1 ) {
V_74 -> V_77 = NULL ;
return;
}
F_62 ( & V_50 ) ;
F_69 (c, &p->children, sibling) {
if ( V_75 -> V_74 == V_74 )
goto V_79;
}
F_69 (c, &p->real_parent->children, sibling) {
if ( V_75 -> V_74 == V_74 )
goto V_79;
}
F_70 (g) {
if ( V_76 -> V_67 & V_80 )
continue;
F_71 (g, c) {
if ( V_75 -> V_74 == V_74 )
goto V_79;
if ( V_75 -> V_74 )
break;
}
}
F_63 ( & V_50 ) ;
V_74 -> V_77 = NULL ;
return;
V_79:
F_72 ( V_75 == V_2 ) ;
F_73 ( V_75 ) ;
F_74 ( V_75 ) ;
F_63 ( & V_50 ) ;
if ( V_75 -> V_74 != V_74 ) {
F_75 ( V_75 ) ;
F_35 ( V_75 ) ;
goto V_58;
}
V_74 -> V_77 = V_75 ;
F_75 ( V_75 ) ;
F_35 ( V_75 ) ;
}
static void F_76 ( void )
{
struct V_73 * V_74 = V_66 -> V_74 ;
struct V_81 * V_81 ;
F_77 ( V_66 , V_74 ) ;
if ( ! V_74 )
return;
F_78 ( V_74 ) ;
F_79 ( & V_74 -> V_82 ) ;
V_81 = V_74 -> V_81 ;
if ( V_81 ) {
struct V_83 V_84 ;
F_80 ( & V_74 -> V_82 ) ;
V_84 . V_57 = V_66 ;
V_84 . V_85 = F_81 ( & V_81 -> V_86 . V_85 , & V_84 ) ;
if ( F_82 ( & V_81 -> V_4 ) )
F_83 ( & V_81 -> V_87 ) ;
for (; ; ) {
F_84 ( V_88 ) ;
if ( ! V_84 . V_57 )
break;
F_85 () ;
}
F_86 ( V_89 ) ;
F_79 ( & V_74 -> V_82 ) ;
}
F_87 ( V_74 ) ;
F_72 ( V_74 != V_66 -> V_90 ) ;
F_74 ( V_66 ) ;
V_66 -> V_74 = NULL ;
F_80 ( & V_74 -> V_82 ) ;
F_88 ( V_74 , V_66 ) ;
F_75 ( V_66 ) ;
F_67 ( V_74 ) ;
F_89 ( V_74 ) ;
if ( F_90 ( V_91 ) )
F_91 () ;
}
static struct V_1 * F_92 ( struct V_1 * V_2 )
{
struct V_1 * V_92 ;
F_71 (p, t) {
if ( ! ( V_92 -> V_67 & V_93 ) )
return V_92 ;
}
return NULL ;
}
static struct V_1 * F_93 ( struct V_1 * V_94 )
__releases( &tasklist_lock
static struct V_1 * F_94 ( struct V_1 * V_94 ,
struct V_1 * V_95 )
{
struct V_1 * V_96 , * V_97 ;
V_96 = F_92 ( V_94 ) ;
if ( V_96 )
return V_96 ;
if ( V_94 -> signal -> V_98 ) {
unsigned int V_99 = F_95 ( V_94 ) -> V_100 ;
for ( V_97 = V_94 -> V_64 ;
F_95 ( V_97 ) -> V_100 == V_99 ;
V_97 = V_97 -> V_64 ) {
if ( V_97 == & V_101 )
break;
if ( ! V_97 -> signal -> V_102 )
continue;
V_96 = F_92 ( V_97 ) ;
if ( V_96 )
return V_96 ;
}
}
return V_95 ;
}
static void F_96 ( struct V_1 * V_94 , struct V_1 * V_2 ,
struct V_103 * V_104 )
{
if ( F_14 ( V_2 -> V_52 == V_55 ) )
return;
V_2 -> V_54 = V_105 ;
if ( ! V_2 -> V_106 &&
V_2 -> V_52 == V_53 && F_44 ( V_2 ) ) {
if ( F_45 ( V_2 , V_2 -> V_54 ) ) {
V_2 -> V_52 = V_55 ;
F_97 ( & V_2 -> V_107 , V_104 ) ;
}
}
F_65 ( V_2 , V_94 ) ;
}
static void F_98 ( struct V_1 * V_94 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 , * V_92 , * V_97 ;
if ( F_14 ( ! F_99 ( & V_94 -> V_108 ) ) )
F_100 ( V_94 , V_104 ) ;
V_97 = F_93 ( V_94 ) ;
if ( F_99 ( & V_94 -> V_109 ) )
return;
V_97 = F_94 ( V_94 , V_97 ) ;
F_69 (p, &father->children, sibling) {
F_71 (p, t) {
V_92 -> V_64 = V_97 ;
F_72 ( ( ! V_92 -> V_106 ) != ( V_92 -> V_69 == V_94 ) ) ;
if ( F_101 ( ! V_92 -> V_106 ) )
V_92 -> V_69 = V_92 -> V_64 ;
if ( V_92 -> V_110 )
F_102 ( V_92 -> V_110 ,
V_111 , V_92 ) ;
}
if ( ! F_103 ( V_97 , V_94 ) )
F_96 ( V_94 , V_2 , V_104 ) ;
}
F_104 ( & V_94 -> V_109 , & V_97 -> V_109 ) ;
}
static void F_105 ( struct V_1 * V_13 , int V_3 )
{
bool V_112 ;
struct V_1 * V_2 , * V_113 ;
F_106 ( V_104 ) ;
F_42 ( & V_50 ) ;
F_98 ( V_13 , & V_104 ) ;
if ( V_3 )
F_65 ( V_13 -> V_51 , NULL ) ;
if ( F_14 ( V_13 -> V_106 ) ) {
int V_15 = F_7 ( V_13 ) &&
F_44 ( V_13 ) &&
! F_107 ( V_13 ) ?
V_13 -> V_54 : V_105 ;
V_112 = F_45 ( V_13 , V_15 ) ;
} else if ( F_7 ( V_13 ) ) {
V_112 = F_44 ( V_13 ) &&
F_45 ( V_13 , V_13 -> V_54 ) ;
} else {
V_112 = true ;
}
V_13 -> V_52 = V_112 ? V_55 : V_53 ;
if ( V_13 -> V_52 == V_55 )
F_97 ( & V_13 -> V_107 , & V_104 ) ;
if ( F_14 ( V_13 -> signal -> V_24 < 0 ) )
F_16 ( V_13 -> signal -> V_25 ) ;
F_46 ( & V_50 ) ;
F_108 (p, n, &dead, ptrace_entry) {
F_4 ( & V_2 -> V_107 ) ;
F_36 ( V_2 ) ;
}
}
static void F_109 ( void )
{
static F_110 ( V_114 ) ;
static int V_115 = V_116 ;
unsigned long free ;
free = F_111 ( V_66 ) ;
if ( free >= V_115 )
return;
F_10 ( & V_114 ) ;
if ( free < V_115 ) {
F_112 ( L_1 ,
V_66 -> V_117 , F_113 ( V_66 ) , free ) ;
V_115 = free ;
}
F_27 ( & V_114 ) ;
}
static inline void F_109 ( void ) {}
void T_2 F_114 ( long V_118 )
{
struct V_1 * V_13 = V_66 ;
int V_3 ;
F_115 ( V_13 ) ;
F_116 ( V_13 ) ;
F_117 ( F_118 ( V_13 ) ) ;
if ( F_14 ( F_119 () ) )
F_120 ( L_2 ) ;
if ( F_14 ( ! V_13 -> V_61 ) )
F_120 ( L_3 ) ;
F_121 ( V_119 ) ;
F_122 ( V_120 , V_118 ) ;
F_123 ( V_13 ) ;
if ( F_14 ( V_13 -> V_67 & V_93 ) ) {
F_124 ( L_4 ) ;
V_13 -> V_67 |= V_121 ;
F_84 ( V_88 ) ;
F_125 () ;
}
F_126 ( V_13 ) ;
F_127 () ;
F_128 ( & V_13 -> V_122 ) ;
F_129 ( & V_13 -> V_122 ) ;
if ( F_14 ( F_130 () ) ) {
F_112 ( L_5 ,
V_66 -> V_117 , F_113 ( V_66 ) ,
F_131 () ) ;
F_132 ( V_123 ) ;
}
if ( V_13 -> V_74 )
F_78 ( V_13 -> V_74 ) ;
F_133 ( V_13 ) ;
V_3 = F_82 ( & V_13 -> signal -> V_124 ) ;
if ( V_3 ) {
#ifdef F_11
F_134 ( & V_13 -> signal -> V_125 ) ;
F_135 ( V_13 -> signal ) ;
#endif
if ( V_13 -> V_74 )
F_136 ( & V_13 -> signal -> V_126 , V_13 -> V_74 ) ;
}
F_137 ( V_118 , V_3 ) ;
if ( V_3 )
F_138 () ;
F_139 ( V_13 ) ;
V_13 -> V_127 = V_118 ;
F_140 ( V_13 , V_3 ) ;
F_76 () ;
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
F_155 () ;
F_105 ( V_13 , V_3 ) ;
F_156 ( V_13 ) ;
F_157 ( V_13 ) ;
#ifdef F_158
if ( F_14 ( V_66 -> V_128 ) )
F_159 ( V_66 -> V_128 ) ;
#endif
F_160 () ;
V_13 -> V_67 |= V_121 ;
if ( V_13 -> V_129 )
F_161 ( V_13 ) ;
if ( V_13 -> V_130 )
F_162 ( V_13 -> V_130 ) ;
if ( V_13 -> V_131 . V_132 )
F_163 ( V_13 -> V_131 . V_132 ) ;
F_123 ( V_13 ) ;
F_109 () ;
F_164 () ;
if ( V_13 -> V_133 )
F_165 ( V_134 , V_13 -> V_133 ) ;
F_166 () ;
F_167 () ;
F_168 ( V_13 ) ;
F_169 () ;
}
void F_170 ( struct V_135 * V_136 , long V_118 )
{
if ( V_136 )
F_83 ( V_136 ) ;
F_114 ( V_118 ) ;
}
void
F_171 ( int V_127 )
{
struct V_14 * V_15 = V_66 -> signal ;
F_72 ( V_127 & 0x80 ) ;
if ( F_172 ( V_15 ) )
V_127 = V_15 -> V_137 ;
else if ( ! F_44 ( V_66 ) ) {
struct V_16 * const V_17 = V_66 -> V_17 ;
F_173 ( & V_17 -> V_23 ) ;
if ( F_172 ( V_15 ) )
V_127 = V_15 -> V_137 ;
else {
V_15 -> V_137 = V_127 ;
V_15 -> V_67 = V_138 ;
F_174 ( V_66 ) ;
}
F_175 ( & V_17 -> V_23 ) ;
}
F_114 ( V_127 ) ;
}
static inline
struct V_61 * F_176 ( struct V_1 * V_57 , enum V_139 type )
{
if ( type != V_5 )
V_57 = V_57 -> V_51 ;
return V_57 -> V_140 [ type ] . V_61 ;
}
static int F_177 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
return V_142 -> V_143 == V_144 ||
F_176 ( V_2 , V_142 -> V_143 ) == V_142 -> V_145 ;
}
static int
F_178 ( struct V_141 * V_142 , bool V_106 , struct V_1 * V_2 )
{
if ( ! F_177 ( V_142 , V_2 ) )
return 0 ;
if ( V_106 || ( V_142 -> V_146 & V_147 ) )
return 1 ;
if ( ( V_2 -> V_54 != V_105 ) ^ ! ! ( V_142 -> V_146 & V_148 ) )
return 0 ;
return 1 ;
}
static int F_179 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
int V_149 , V_150 ;
T_3 V_61 = F_180 ( V_2 ) ;
T_4 V_151 = F_181 ( F_182 () , F_183 ( V_2 ) ) ;
struct V_152 * V_153 ;
if ( ! F_101 ( V_142 -> V_146 & V_154 ) )
return 0 ;
if ( F_14 ( V_142 -> V_146 & V_155 ) ) {
V_150 = V_2 -> V_127 ;
F_73 ( V_2 ) ;
F_63 ( & V_50 ) ;
F_184 () ;
if ( V_142 -> V_156 )
F_185 ( V_2 , V_157 , V_142 -> V_156 ) ;
F_35 ( V_2 ) ;
goto V_158;
}
V_149 = ( F_107 ( V_2 ) && F_7 ( V_2 ) ) ?
V_159 : V_55 ;
if ( F_186 ( & V_2 -> V_52 , V_53 , V_149 ) != V_53 )
return 0 ;
F_63 ( & V_50 ) ;
F_184 () ;
if ( V_149 == V_55 && F_7 ( V_2 ) ) {
struct V_14 * V_15 = V_2 -> signal ;
struct V_14 * V_160 = V_66 -> signal ;
unsigned long V_126 ;
T_1 V_161 , V_162 ;
F_187 ( V_2 , & V_161 , & V_162 ) ;
F_173 ( & V_66 -> V_17 -> V_23 ) ;
F_20 ( & V_160 -> V_29 ) ;
V_160 -> V_163 += V_161 + V_15 -> V_163 ;
V_160 -> V_164 += V_162 + V_15 -> V_164 ;
V_160 -> V_165 += F_21 ( V_2 ) + V_15 -> V_30 + V_15 -> V_165 ;
V_160 -> V_166 +=
V_2 -> V_31 + V_15 -> V_31 + V_15 -> V_166 ;
V_160 -> V_167 +=
V_2 -> V_32 + V_15 -> V_32 + V_15 -> V_167 ;
V_160 -> V_168 +=
V_2 -> V_33 + V_15 -> V_33 + V_15 -> V_168 ;
V_160 -> V_169 +=
V_2 -> V_34 + V_15 -> V_34 + V_15 -> V_169 ;
V_160 -> V_170 +=
F_22 ( V_2 ) +
V_15 -> V_35 + V_15 -> V_170 ;
V_160 -> V_171 +=
F_23 ( V_2 ) +
V_15 -> V_36 + V_15 -> V_171 ;
V_126 = F_188 ( V_15 -> V_126 , V_15 -> V_172 ) ;
if ( V_160 -> V_172 < V_126 )
V_160 -> V_172 = V_126 ;
F_24 ( & V_160 -> V_37 , & V_2 -> V_37 ) ;
F_24 ( & V_160 -> V_37 , & V_15 -> V_37 ) ;
F_25 ( & V_160 -> V_29 ) ;
F_175 ( & V_66 -> V_17 -> V_23 ) ;
}
if ( V_142 -> V_156 )
F_185 ( V_2 , V_157 , V_142 -> V_156 ) ;
V_150 = ( V_2 -> signal -> V_67 & V_138 )
? V_2 -> signal -> V_137 : V_2 -> V_127 ;
V_142 -> V_173 = V_150 ;
if ( V_149 == V_159 ) {
F_42 ( & V_50 ) ;
F_189 ( V_2 ) ;
V_149 = V_53 ;
if ( F_45 ( V_2 , V_2 -> V_54 ) )
V_149 = V_55 ;
V_2 -> V_52 = V_149 ;
F_46 ( & V_50 ) ;
}
if ( V_149 == V_55 )
F_36 ( V_2 ) ;
V_158:
V_153 = V_142 -> V_174 ;
if ( V_153 ) {
if ( ( V_150 & 0x7f ) == 0 ) {
V_153 -> V_175 = V_176 ;
V_153 -> V_150 = V_150 >> 8 ;
} else {
V_153 -> V_175 = ( V_150 & 0x80 ) ? V_177 : V_178 ;
V_153 -> V_150 = V_150 & 0x7f ;
}
V_153 -> V_61 = V_61 ;
V_153 -> V_151 = V_151 ;
}
return V_61 ;
}
static int * F_190 ( struct V_1 * V_2 , bool V_106 )
{
if ( V_106 ) {
if ( F_191 ( V_2 ) && ! ( V_2 -> V_179 & V_180 ) )
return & V_2 -> V_127 ;
} else {
if ( V_2 -> signal -> V_67 & V_68 )
return & V_2 -> signal -> V_137 ;
}
return NULL ;
}
static int F_192 ( struct V_141 * V_142 ,
int V_106 , struct V_1 * V_2 )
{
struct V_152 * V_153 ;
int V_127 , * V_181 , V_182 ;
T_4 V_151 = 0 ;
T_3 V_61 ;
if ( ! V_106 && ! ( V_142 -> V_146 & V_183 ) )
return 0 ;
if ( ! F_190 ( V_2 , V_106 ) )
return 0 ;
V_127 = 0 ;
F_173 ( & V_2 -> V_17 -> V_23 ) ;
V_181 = F_190 ( V_2 , V_106 ) ;
if ( F_14 ( ! V_181 ) )
goto V_184;
V_127 = * V_181 ;
if ( ! V_127 )
goto V_184;
if ( ! F_14 ( V_142 -> V_146 & V_155 ) )
* V_181 = 0 ;
V_151 = F_181 ( F_182 () , F_183 ( V_2 ) ) ;
V_184:
F_175 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! V_127 )
return 0 ;
F_73 ( V_2 ) ;
V_61 = F_180 ( V_2 ) ;
V_182 = V_106 ? V_185 : V_186 ;
F_63 ( & V_50 ) ;
F_184 () ;
if ( V_142 -> V_156 )
F_185 ( V_2 , V_157 , V_142 -> V_156 ) ;
F_35 ( V_2 ) ;
if ( F_101 ( ! ( V_142 -> V_146 & V_155 ) ) )
V_142 -> V_173 = ( V_127 << 8 ) | 0x7f ;
V_153 = V_142 -> V_174 ;
if ( V_153 ) {
V_153 -> V_175 = V_182 ;
V_153 -> V_150 = V_127 ;
V_153 -> V_61 = V_61 ;
V_153 -> V_151 = V_151 ;
}
return V_61 ;
}
static int F_193 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
struct V_152 * V_153 ;
T_3 V_61 ;
T_4 V_151 ;
if ( ! F_14 ( V_142 -> V_146 & V_187 ) )
return 0 ;
if ( ! ( V_2 -> signal -> V_67 & V_188 ) )
return 0 ;
F_173 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! ( V_2 -> signal -> V_67 & V_188 ) ) {
F_175 ( & V_2 -> V_17 -> V_23 ) ;
return 0 ;
}
if ( ! F_14 ( V_142 -> V_146 & V_155 ) )
V_2 -> signal -> V_67 &= ~ V_188 ;
V_151 = F_181 ( F_182 () , F_183 ( V_2 ) ) ;
F_175 ( & V_2 -> V_17 -> V_23 ) ;
V_61 = F_180 ( V_2 ) ;
F_73 ( V_2 ) ;
F_63 ( & V_50 ) ;
F_184 () ;
if ( V_142 -> V_156 )
F_185 ( V_2 , V_157 , V_142 -> V_156 ) ;
F_35 ( V_2 ) ;
V_153 = V_142 -> V_174 ;
if ( ! V_153 ) {
V_142 -> V_173 = 0xffff ;
} else {
V_153 -> V_175 = V_189 ;
V_153 -> V_61 = V_61 ;
V_153 -> V_151 = V_151 ;
V_153 -> V_150 = V_72 ;
}
return V_61 ;
}
static int F_194 ( struct V_141 * V_142 , int V_106 ,
struct V_1 * V_2 )
{
int V_52 = F_195 ( V_2 -> V_52 ) ;
int V_190 ;
if ( F_14 ( V_52 == V_55 ) )
return 0 ;
V_190 = F_178 ( V_142 , V_106 , V_2 ) ;
if ( ! V_190 )
return V_190 ;
if ( F_14 ( V_52 == V_159 ) ) {
if ( F_101 ( ! V_106 ) )
V_142 -> V_191 = 0 ;
return 0 ;
}
if ( F_101 ( ! V_106 ) && F_14 ( V_2 -> V_106 ) ) {
if ( ! F_107 ( V_2 ) )
V_106 = 1 ;
}
if ( V_52 == V_53 ) {
if ( ! F_196 ( V_2 ) ) {
if ( F_14 ( V_106 ) || F_101 ( ! V_2 -> V_106 ) )
return F_179 ( V_142 , V_2 ) ;
}
if ( F_101 ( ! V_106 ) || ( V_142 -> V_146 & ( V_187 | V_154 ) ) )
V_142 -> V_191 = 0 ;
} else {
V_142 -> V_191 = 0 ;
}
V_190 = F_192 ( V_142 , V_106 , V_2 ) ;
if ( V_190 )
return V_190 ;
return F_193 ( V_142 , V_2 ) ;
}
static int F_197 ( struct V_141 * V_142 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_69 (p, &tsk->children, sibling) {
int V_190 = F_194 ( V_142 , 0 , V_2 ) ;
if ( V_190 )
return V_190 ;
}
return 0 ;
}
static int F_198 ( struct V_141 * V_142 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_69 (p, &tsk->ptraced, ptrace_entry) {
int V_190 = F_194 ( V_142 , 1 , V_2 ) ;
if ( V_190 )
return V_190 ;
}
return 0 ;
}
static int F_199 ( T_5 * V_192 , unsigned V_193 ,
int V_194 , void * V_195 )
{
struct V_141 * V_142 = F_32 ( V_192 , struct V_141 ,
V_196 ) ;
struct V_1 * V_2 = V_195 ;
if ( ! F_177 ( V_142 , V_2 ) )
return 0 ;
if ( ( V_142 -> V_146 & V_197 ) && V_192 -> V_198 != V_2 -> V_69 )
return 0 ;
return F_200 ( V_192 , V_193 , V_194 , V_195 ) ;
}
void F_201 ( struct V_1 * V_2 , struct V_1 * V_69 )
{
F_202 ( & V_69 -> signal -> V_199 ,
V_200 , 1 , V_2 ) ;
}
static long F_203 ( struct V_141 * V_142 )
{
struct V_1 * V_13 ;
int V_65 ;
F_204 ( V_142 -> V_145 ) ;
F_205 ( & V_142 -> V_196 , F_199 ) ;
V_142 -> V_196 . V_198 = V_66 ;
F_206 ( & V_66 -> signal -> V_199 , & V_142 -> V_196 ) ;
V_47:
V_142 -> V_191 = - V_201 ;
if ( ( V_142 -> V_143 < V_144 ) &&
( ! V_142 -> V_145 || F_207 ( & V_142 -> V_145 -> V_8 [ V_142 -> V_143 ] ) ) )
goto V_202;
F_84 ( V_200 ) ;
F_62 ( & V_50 ) ;
V_13 = V_66 ;
do {
V_65 = F_197 ( V_142 , V_13 ) ;
if ( V_65 )
goto V_203;
V_65 = F_198 ( V_142 , V_13 ) ;
if ( V_65 )
goto V_203;
if ( V_142 -> V_146 & V_197 )
break;
} while_each_thread(current, tsk) ;
long F_208 ( int V_204 , T_3 V_205 , struct V_152 * V_153 ,
int V_206 , struct V_207 * V_208 )
{
struct V_141 V_142 ;
struct V_61 * V_61 = NULL ;
enum V_139 type ;
long V_190 ;
if ( V_206 & ~ ( V_209 | V_155 | V_154 | V_210 | V_187 |
V_197 | V_148 | V_147 ) )
return - V_211 ;
if ( ! ( V_206 & ( V_154 | V_210 | V_187 ) ) )
return - V_211 ;
switch ( V_204 ) {
case V_212 :
type = V_144 ;
break;
case V_213 :
type = V_5 ;
if ( V_205 <= 0 )
return - V_211 ;
break;
case V_214 :
type = V_6 ;
if ( V_205 <= 0 )
return - V_211 ;
break;
default:
return - V_211 ;
}
if ( type < V_144 )
V_61 = F_209 ( V_205 ) ;
V_142 . V_143 = type ;
V_142 . V_145 = V_61 ;
V_142 . V_146 = V_206 ;
V_142 . V_174 = V_153 ;
V_142 . V_156 = V_208 ;
V_190 = F_203 ( & V_142 ) ;
F_210 ( V_61 ) ;
return V_190 ;
}
long F_211 ( T_3 V_205 , int T_6 * V_215 , int V_206 ,
struct V_207 * V_208 )
{
struct V_141 V_142 ;
struct V_61 * V_61 = NULL ;
enum V_139 type ;
long V_190 ;
if ( V_206 & ~ ( V_209 | V_183 | V_187 |
V_197 | V_148 | V_147 ) )
return - V_211 ;
if ( V_205 == V_216 )
return - V_217 ;
if ( V_205 == - 1 )
type = V_144 ;
else if ( V_205 < 0 ) {
type = V_6 ;
V_61 = F_209 ( - V_205 ) ;
} else if ( V_205 == 0 ) {
type = V_6 ;
V_61 = F_212 ( V_66 , V_6 ) ;
} else {
type = V_5 ;
V_61 = F_209 ( V_205 ) ;
}
V_142 . V_143 = type ;
V_142 . V_145 = V_61 ;
V_142 . V_146 = V_206 | V_154 ;
V_142 . V_174 = NULL ;
V_142 . V_173 = 0 ;
V_142 . V_156 = V_208 ;
V_190 = F_203 ( & V_142 ) ;
F_210 ( V_61 ) ;
if ( V_190 > 0 && V_215 && F_213 ( V_142 . V_173 , V_215 ) )
V_190 = - V_218 ;
return V_190 ;
}
