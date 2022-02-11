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
F_11 ( V_13 ) ;
if ( V_3 ) {
F_12 ( V_13 ) ;
V_20 = V_15 -> V_20 ;
V_15 -> V_20 = NULL ;
} else {
if ( F_13 ( F_14 ( V_13 ) ) )
F_12 ( V_13 ) ;
if ( V_15 -> V_24 > 0 && ! -- V_15 -> V_24 )
F_15 ( V_15 -> V_25 ) ;
if ( V_13 == V_15 -> V_26 )
V_15 -> V_26 = F_16 ( V_13 ) ;
}
F_17 ( V_13 , & V_21 , & V_22 ) ;
F_18 ( & V_15 -> V_27 ) ;
V_15 -> V_21 += V_21 ;
V_15 -> V_22 += V_22 ;
V_15 -> V_28 += F_19 ( V_13 ) ;
V_15 -> V_29 += V_13 -> V_29 ;
V_15 -> V_30 += V_13 -> V_30 ;
V_15 -> V_31 += V_13 -> V_31 ;
V_15 -> V_32 += V_13 -> V_32 ;
V_15 -> V_33 += F_20 ( V_13 ) ;
V_15 -> V_34 += F_21 ( V_13 ) ;
F_22 ( & V_15 -> V_35 , & V_13 -> V_35 ) ;
V_15 -> V_36 += V_13 -> V_37 . V_38 ;
V_15 -> V_4 -- ;
F_1 ( V_13 , V_3 ) ;
F_23 ( & V_15 -> V_27 ) ;
F_24 ( & V_13 -> V_39 ) ;
V_13 -> V_17 = NULL ;
F_25 ( & V_17 -> V_23 ) ;
F_26 ( V_17 ) ;
F_27 ( V_13 , V_40 ) ;
if ( V_3 ) {
F_24 ( & V_15 -> V_41 ) ;
F_28 ( V_20 ) ;
}
}
static void F_29 ( struct V_42 * V_43 )
{
struct V_1 * V_13 = F_30 ( V_43 , struct V_1 , V_44 ) ;
F_31 ( V_13 ) ;
F_32 ( V_13 ) ;
F_33 ( V_13 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_1 * V_45 ;
int V_46 ;
V_47:
F_35 () ;
F_36 ( & F_37 ( V_2 ) -> V_48 -> V_49 ) ;
F_38 () ;
F_39 ( V_2 ) ;
F_40 ( & V_50 ) ;
F_41 ( V_2 ) ;
F_6 ( V_2 ) ;
V_46 = 0 ;
V_45 = V_2 -> V_51 ;
if ( V_45 != V_2 && F_42 ( V_45 )
&& V_45 -> V_52 == V_53 ) {
V_46 = F_43 ( V_45 , V_45 -> V_54 ) ;
if ( V_46 )
V_45 -> V_52 = V_55 ;
}
F_44 ( & V_50 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_44 , F_29 ) ;
V_2 = V_45 ;
if ( F_13 ( V_46 ) )
goto V_47;
}
static int F_47 ( struct V_56 * V_57 ,
struct V_1 * V_58 )
{
struct V_1 * V_2 ;
F_48 (pgrp, PIDTYPE_PGID, p) {
if ( ( V_2 == V_58 ) ||
( V_2 -> V_52 && F_42 ( V_2 ) ) ||
F_49 ( V_2 -> V_59 ) )
continue;
if ( F_50 ( V_2 -> V_59 ) != V_57 &&
F_51 ( V_2 -> V_59 ) == F_51 ( V_2 ) )
return 0 ;
} F_52 ( V_57 , V_6 , V_2 ) ;
return 1 ;
}
int F_53 ( void )
{
int V_60 ;
F_54 ( & V_50 ) ;
V_60 = F_47 ( F_50 ( V_61 ) , NULL ) ;
F_55 ( & V_50 ) ;
return V_60 ;
}
static bool F_56 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
F_48 (pgrp, PIDTYPE_PGID, p) {
if ( V_2 -> signal -> V_62 & V_63 )
return true ;
} F_52 ( V_57 , V_6 , V_2 ) ;
return false ;
}
static void
F_57 ( struct V_1 * V_13 , struct V_1 * V_64 )
{
struct V_56 * V_57 = F_50 ( V_13 ) ;
struct V_1 * V_58 = V_13 ;
if ( ! V_64 )
V_64 = V_13 -> V_59 ;
else
V_58 = NULL ;
if ( F_50 ( V_64 ) != V_57 &&
F_51 ( V_64 ) == F_51 ( V_13 ) &&
F_47 ( V_57 , V_58 ) &&
F_56 ( V_57 ) ) {
F_58 ( V_65 , V_66 , V_57 ) ;
F_58 ( V_67 , V_66 , V_57 ) ;
}
}
void F_59 ( struct V_68 * V_69 )
{
struct V_1 * V_70 , * V_71 , * V_2 = V_61 ;
V_72:
if ( V_69 -> V_73 != V_2 )
return;
if ( F_60 ( & V_69 -> V_74 ) <= 1 ) {
V_69 -> V_73 = NULL ;
return;
}
F_54 ( & V_50 ) ;
F_61 (c, &p->children, sibling) {
if ( V_70 -> V_69 == V_69 )
goto V_75;
}
F_61 (c, &p->real_parent->children, sibling) {
if ( V_70 -> V_69 == V_69 )
goto V_75;
}
F_62 (g) {
if ( V_71 -> V_62 & V_76 )
continue;
F_63 (g, c) {
if ( V_70 -> V_69 == V_69 )
goto V_75;
if ( V_70 -> V_69 )
break;
}
}
F_55 ( & V_50 ) ;
V_69 -> V_73 = NULL ;
return;
V_75:
F_64 ( V_70 == V_2 ) ;
F_65 ( V_70 ) ;
F_66 ( V_70 ) ;
F_55 ( & V_50 ) ;
if ( V_70 -> V_69 != V_69 ) {
F_67 ( V_70 ) ;
F_33 ( V_70 ) ;
goto V_72;
}
V_69 -> V_73 = V_70 ;
F_67 ( V_70 ) ;
F_33 ( V_70 ) ;
}
static void F_68 ( struct V_1 * V_13 )
{
struct V_68 * V_69 = V_13 -> V_69 ;
struct V_77 * V_77 ;
F_69 ( V_13 , V_69 ) ;
if ( ! V_69 )
return;
F_70 ( V_69 ) ;
F_71 ( & V_69 -> V_78 ) ;
V_77 = V_69 -> V_77 ;
if ( V_77 ) {
struct V_79 V_80 ;
F_72 ( & V_69 -> V_78 ) ;
V_80 . V_81 = V_13 ;
V_80 . V_82 = F_73 ( & V_77 -> V_83 . V_82 , & V_80 ) ;
if ( F_74 ( & V_77 -> V_4 ) )
F_75 ( & V_77 -> V_84 ) ;
for (; ; ) {
F_76 ( V_13 , V_85 ) ;
if ( ! V_80 . V_81 )
break;
F_77 () ;
}
F_78 ( V_13 , V_86 ) ;
F_71 ( & V_69 -> V_78 ) ;
}
F_79 ( & V_69 -> V_87 ) ;
F_64 ( V_69 != V_13 -> V_88 ) ;
F_66 ( V_13 ) ;
V_13 -> V_69 = NULL ;
F_72 ( & V_69 -> V_78 ) ;
F_80 ( V_69 , V_61 ) ;
F_67 ( V_13 ) ;
F_59 ( V_69 ) ;
F_81 ( V_69 ) ;
if ( F_82 ( V_89 ) )
F_83 () ;
}
static struct V_1 * F_84 ( struct V_1 * V_2 )
{
struct V_1 * V_90 ;
F_63 (p, t) {
if ( ! ( V_90 -> V_62 & V_91 ) )
return V_90 ;
}
return NULL ;
}
static struct V_1 * F_85 ( struct V_1 * V_92 )
__releases( &tasklist_lock
static struct V_1 * F_86 ( struct V_1 * V_92 ,
struct V_1 * V_93 )
{
struct V_1 * V_94 , * V_95 ;
V_94 = F_84 ( V_92 ) ;
if ( V_94 )
return V_94 ;
if ( V_92 -> signal -> V_96 ) {
for ( V_95 = V_92 ;
! F_87 ( V_95 , V_93 ) ;
V_95 = V_95 -> V_59 ) {
if ( V_95 == & V_97 )
break;
if ( ! V_95 -> signal -> V_98 )
continue;
V_94 = F_84 ( V_95 ) ;
if ( V_94 )
return V_94 ;
}
}
return V_93 ;
}
static void F_88 ( struct V_1 * V_92 , struct V_1 * V_2 ,
struct V_99 * V_100 )
{
if ( F_13 ( V_2 -> V_52 == V_55 ) )
return;
V_2 -> V_54 = V_101 ;
if ( ! V_2 -> V_102 &&
V_2 -> V_52 == V_53 && F_42 ( V_2 ) ) {
if ( F_43 ( V_2 , V_2 -> V_54 ) ) {
V_2 -> V_52 = V_55 ;
F_89 ( & V_2 -> V_103 , V_100 ) ;
}
}
F_57 ( V_2 , V_92 ) ;
}
static void F_90 ( struct V_1 * V_92 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 , * V_90 , * V_95 ;
if ( F_13 ( ! F_91 ( & V_92 -> V_104 ) ) )
F_92 ( V_92 , V_100 ) ;
V_95 = F_85 ( V_92 ) ;
if ( F_91 ( & V_92 -> V_105 ) )
return;
V_95 = F_86 ( V_92 , V_95 ) ;
F_61 (p, &father->children, sibling) {
F_63 (p, t) {
V_90 -> V_59 = V_95 ;
F_64 ( ( ! V_90 -> V_102 ) != ( V_90 -> V_64 == V_92 ) ) ;
if ( F_93 ( ! V_90 -> V_102 ) )
V_90 -> V_64 = V_90 -> V_59 ;
if ( V_90 -> V_106 )
F_94 ( V_90 -> V_106 ,
V_107 , V_90 ) ;
}
if ( ! F_87 ( V_95 , V_92 ) )
F_88 ( V_92 , V_2 , V_100 ) ;
}
F_95 ( & V_92 -> V_105 , & V_95 -> V_105 ) ;
}
static void F_96 ( struct V_1 * V_13 , int V_3 )
{
bool V_108 ;
struct V_1 * V_2 , * V_109 ;
F_97 ( V_100 ) ;
F_40 ( & V_50 ) ;
F_90 ( V_13 , & V_100 ) ;
if ( V_3 )
F_57 ( V_13 -> V_51 , NULL ) ;
if ( F_13 ( V_13 -> V_102 ) ) {
int V_15 = F_7 ( V_13 ) &&
F_42 ( V_13 ) &&
! F_98 ( V_13 ) ?
V_13 -> V_54 : V_101 ;
V_108 = F_43 ( V_13 , V_15 ) ;
} else if ( F_7 ( V_13 ) ) {
V_108 = F_42 ( V_13 ) &&
F_43 ( V_13 , V_13 -> V_54 ) ;
} else {
V_108 = true ;
}
V_13 -> V_52 = V_108 ? V_55 : V_53 ;
if ( V_13 -> V_52 == V_55 )
F_89 ( & V_13 -> V_103 , & V_100 ) ;
if ( F_13 ( V_13 -> signal -> V_24 < 0 ) )
F_15 ( V_13 -> signal -> V_25 ) ;
F_44 ( & V_50 ) ;
F_99 (p, n, &dead, ptrace_entry) {
F_4 ( & V_2 -> V_103 ) ;
F_34 ( V_2 ) ;
}
}
static void F_100 ( void )
{
static F_101 ( V_110 ) ;
static int V_111 = V_112 ;
unsigned long free ;
free = F_102 ( V_61 ) ;
if ( free >= V_111 )
return;
F_10 ( & V_110 ) ;
if ( free < V_111 ) {
F_103 ( L_1 ,
V_61 -> V_113 , F_104 ( V_61 ) , free ) ;
V_111 = free ;
}
F_25 ( & V_110 ) ;
}
static inline void F_100 ( void ) {}
void F_105 ( long V_114 )
{
struct V_1 * V_13 = V_61 ;
int V_3 ;
F_106 (int tasks_rcu_i) ;
F_107 ( V_13 ) ;
F_108 ( F_109 ( V_13 ) ) ;
if ( F_13 ( F_110 () ) )
F_111 ( L_2 ) ;
if ( F_13 ( ! V_13 -> V_56 ) )
F_111 ( L_3 ) ;
F_112 ( V_115 ) ;
F_113 ( V_116 , V_114 ) ;
F_114 ( V_13 ) ;
if ( F_13 ( V_13 -> V_62 & V_91 ) ) {
F_115 ( L_4 ) ;
V_13 -> V_62 |= V_117 ;
F_116 ( V_85 ) ;
F_117 () ;
}
F_118 ( V_13 ) ;
F_119 () ;
F_120 ( & V_13 -> V_118 ) ;
if ( F_13 ( F_121 () ) )
F_122 ( L_5 ,
V_61 -> V_113 , F_104 ( V_61 ) ,
F_123 () ) ;
F_124 ( V_13 ) ;
if ( V_13 -> V_69 )
F_70 ( V_13 -> V_69 ) ;
V_3 = F_74 ( & V_13 -> signal -> V_119 ) ;
if ( V_3 ) {
F_125 ( & V_13 -> signal -> V_120 ) ;
F_126 ( V_13 -> signal ) ;
if ( V_13 -> V_69 )
F_127 ( & V_13 -> signal -> V_121 , V_13 -> V_69 ) ;
}
F_128 ( V_114 , V_3 ) ;
if ( V_3 )
F_129 () ;
F_130 ( V_13 ) ;
V_13 -> V_122 = V_114 ;
F_131 ( V_13 , V_3 ) ;
F_68 ( V_13 ) ;
if ( V_3 )
F_132 () ;
F_133 ( V_13 ) ;
F_134 ( V_13 ) ;
F_135 ( V_13 ) ;
F_136 ( V_13 ) ;
F_137 ( V_13 ) ;
if ( V_3 )
F_138 ( 1 ) ;
F_139 ( V_13 ) ;
F_140 ( V_13 ) ;
F_141 () ;
F_142 ( V_13 ) ;
F_143 ( V_13 ) ;
F_144 ( V_13 ) ;
F_106 ( V_123 = F_145 ( & V_124 ) ) ;
F_96 ( V_13 , V_3 ) ;
F_146 ( V_13 ) ;
#ifdef F_147
F_66 ( V_13 ) ;
F_148 ( V_13 -> V_125 ) ;
V_13 -> V_125 = NULL ;
F_67 ( V_13 ) ;
#endif
#ifdef F_149
if ( F_13 ( V_61 -> V_126 ) )
F_150 ( V_61 -> V_126 ) ;
#endif
F_151 () ;
V_13 -> V_62 |= V_117 ;
if ( V_13 -> V_127 )
F_152 ( V_13 ) ;
if ( V_13 -> V_128 )
F_153 ( V_13 -> V_128 ) ;
if ( V_13 -> V_129 . V_130 )
F_154 ( V_13 -> V_129 . V_130 ) ;
F_114 ( V_13 ) ;
F_100 () ;
F_155 () ;
if ( V_13 -> V_131 )
F_156 ( V_132 , V_13 -> V_131 ) ;
F_157 () ;
F_106 ( F_158 ( & V_124 , V_123 ) ) ;
F_119 () ;
F_120 ( & V_13 -> V_118 ) ;
V_13 -> V_133 = V_134 ;
V_13 -> V_62 |= V_135 ;
F_117 () ;
F_159 () ;
for (; ; )
F_160 () ;
}
void F_161 ( struct V_136 * V_137 , long V_114 )
{
if ( V_137 )
F_75 ( V_137 ) ;
F_105 ( V_114 ) ;
}
void
F_162 ( int V_122 )
{
struct V_14 * V_15 = V_61 -> signal ;
F_64 ( V_122 & 0x80 ) ;
if ( F_163 ( V_15 ) )
V_122 = V_15 -> V_138 ;
else if ( ! F_42 ( V_61 ) ) {
struct V_16 * const V_17 = V_61 -> V_17 ;
F_164 ( & V_17 -> V_23 ) ;
if ( F_163 ( V_15 ) )
V_122 = V_15 -> V_138 ;
else {
V_15 -> V_138 = V_122 ;
V_15 -> V_62 = V_139 ;
F_165 ( V_61 ) ;
}
F_166 ( & V_17 -> V_23 ) ;
}
F_105 ( V_122 ) ;
}
static inline
struct V_56 * F_167 ( struct V_1 * V_81 , enum V_140 type )
{
if ( type != V_5 )
V_81 = V_81 -> V_51 ;
return V_81 -> V_141 [ type ] . V_56 ;
}
static int F_168 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
return V_143 -> V_144 == V_145 ||
F_167 ( V_2 , V_143 -> V_144 ) == V_143 -> V_146 ;
}
static int F_169 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
if ( ! F_168 ( V_143 , V_2 ) )
return 0 ;
if ( ( ( V_2 -> V_54 != V_101 ) ^ ! ! ( V_143 -> V_147 & V_148 ) )
&& ! ( V_143 -> V_147 & V_149 ) )
return 0 ;
return 1 ;
}
static int F_170 ( struct V_142 * V_143 , struct V_1 * V_2 ,
T_2 V_56 , T_3 V_150 , int V_151 , int V_152 )
{
struct V_153 T_4 * V_154 ;
int V_60 = V_143 -> V_155
? F_171 ( V_2 , V_156 , V_143 -> V_155 ) : 0 ;
F_33 ( V_2 ) ;
V_154 = V_143 -> V_157 ;
if ( V_154 ) {
if ( ! V_60 )
V_60 = F_172 ( V_101 , & V_154 -> V_158 ) ;
if ( ! V_60 )
V_60 = F_172 ( 0 , & V_154 -> V_159 ) ;
if ( ! V_60 )
V_60 = F_172 ( ( short ) V_151 , & V_154 -> V_160 ) ;
if ( ! V_60 )
V_60 = F_172 ( V_56 , & V_154 -> V_161 ) ;
if ( ! V_60 )
V_60 = F_172 ( V_150 , & V_154 -> V_162 ) ;
if ( ! V_60 )
V_60 = F_172 ( V_152 , & V_154 -> V_163 ) ;
}
if ( ! V_60 )
V_60 = V_56 ;
return V_60 ;
}
static int F_173 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
int V_133 , V_60 , V_152 ;
T_2 V_56 = F_174 ( V_2 ) ;
T_3 V_150 = F_175 ( F_176 () , F_177 ( V_2 ) ) ;
struct V_153 T_4 * V_154 ;
if ( ! F_93 ( V_143 -> V_147 & V_164 ) )
return 0 ;
if ( F_13 ( V_143 -> V_147 & V_165 ) ) {
int V_122 = V_2 -> V_122 ;
int V_151 ;
F_65 ( V_2 ) ;
F_55 ( & V_50 ) ;
F_178 () ;
if ( ( V_122 & 0x7f ) == 0 ) {
V_151 = V_166 ;
V_152 = V_122 >> 8 ;
} else {
V_151 = ( V_122 & 0x80 ) ? V_167 : V_168 ;
V_152 = V_122 & 0x7f ;
}
return F_170 ( V_143 , V_2 , V_56 , V_150 , V_151 , V_152 ) ;
}
V_133 = ( F_98 ( V_2 ) && F_7 ( V_2 ) ) ?
V_169 : V_55 ;
if ( F_179 ( & V_2 -> V_52 , V_53 , V_133 ) != V_53 )
return 0 ;
F_55 ( & V_50 ) ;
F_178 () ;
if ( V_133 == V_55 && F_7 ( V_2 ) ) {
struct V_14 * V_15 = V_2 -> signal ;
struct V_14 * V_170 = V_61 -> signal ;
unsigned long V_121 ;
T_1 V_171 , V_172 ;
F_180 ( V_2 , & V_171 , & V_172 ) ;
F_164 ( & V_61 -> V_17 -> V_23 ) ;
F_18 ( & V_170 -> V_27 ) ;
V_170 -> V_173 += V_171 + V_15 -> V_173 ;
V_170 -> V_174 += V_172 + V_15 -> V_174 ;
V_170 -> V_175 += F_19 ( V_2 ) + V_15 -> V_28 + V_15 -> V_175 ;
V_170 -> V_176 +=
V_2 -> V_29 + V_15 -> V_29 + V_15 -> V_176 ;
V_170 -> V_177 +=
V_2 -> V_30 + V_15 -> V_30 + V_15 -> V_177 ;
V_170 -> V_178 +=
V_2 -> V_31 + V_15 -> V_31 + V_15 -> V_178 ;
V_170 -> V_179 +=
V_2 -> V_32 + V_15 -> V_32 + V_15 -> V_179 ;
V_170 -> V_180 +=
F_20 ( V_2 ) +
V_15 -> V_33 + V_15 -> V_180 ;
V_170 -> V_181 +=
F_21 ( V_2 ) +
V_15 -> V_34 + V_15 -> V_181 ;
V_121 = F_181 ( V_15 -> V_121 , V_15 -> V_182 ) ;
if ( V_170 -> V_182 < V_121 )
V_170 -> V_182 = V_121 ;
F_22 ( & V_170 -> V_35 , & V_2 -> V_35 ) ;
F_22 ( & V_170 -> V_35 , & V_15 -> V_35 ) ;
F_23 ( & V_170 -> V_27 ) ;
F_166 ( & V_61 -> V_17 -> V_23 ) ;
}
V_60 = V_143 -> V_155
? F_171 ( V_2 , V_156 , V_143 -> V_155 ) : 0 ;
V_152 = ( V_2 -> signal -> V_62 & V_139 )
? V_2 -> signal -> V_138 : V_2 -> V_122 ;
if ( ! V_60 && V_143 -> V_183 )
V_60 = F_172 ( V_152 , V_143 -> V_183 ) ;
V_154 = V_143 -> V_157 ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_101 , & V_154 -> V_158 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( 0 , & V_154 -> V_159 ) ;
if ( ! V_60 && V_154 ) {
int V_151 ;
if ( ( V_152 & 0x7f ) == 0 ) {
V_151 = V_166 ;
V_152 >>= 8 ;
} else {
V_151 = ( V_152 & 0x80 ) ? V_167 : V_168 ;
V_152 &= 0x7f ;
}
V_60 = F_172 ( ( short ) V_151 , & V_154 -> V_160 ) ;
if ( ! V_60 )
V_60 = F_172 ( V_152 , & V_154 -> V_163 ) ;
}
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_56 , & V_154 -> V_161 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_150 , & V_154 -> V_162 ) ;
if ( ! V_60 )
V_60 = V_56 ;
if ( V_133 == V_169 ) {
F_40 ( & V_50 ) ;
F_182 ( V_2 ) ;
V_133 = V_53 ;
if ( F_43 ( V_2 , V_2 -> V_54 ) )
V_133 = V_55 ;
V_2 -> V_52 = V_133 ;
F_44 ( & V_50 ) ;
}
if ( V_133 == V_55 )
F_34 ( V_2 ) ;
return V_60 ;
}
static int * F_183 ( struct V_1 * V_2 , bool V_102 )
{
if ( V_102 ) {
if ( F_184 ( V_2 ) &&
! ( V_2 -> V_184 & V_185 ) )
return & V_2 -> V_122 ;
} else {
if ( V_2 -> signal -> V_62 & V_63 )
return & V_2 -> signal -> V_138 ;
}
return NULL ;
}
static int F_185 ( struct V_142 * V_143 ,
int V_102 , struct V_1 * V_2 )
{
struct V_153 T_4 * V_154 ;
int V_60 , V_122 , * V_186 , V_151 ;
T_3 V_150 = 0 ;
T_2 V_56 ;
if ( ! V_102 && ! ( V_143 -> V_147 & V_187 ) )
return 0 ;
if ( ! F_183 ( V_2 , V_102 ) )
return 0 ;
V_122 = 0 ;
F_164 ( & V_2 -> V_17 -> V_23 ) ;
V_186 = F_183 ( V_2 , V_102 ) ;
if ( F_13 ( ! V_186 ) )
goto V_188;
V_122 = * V_186 ;
if ( ! V_122 )
goto V_188;
if ( ! F_13 ( V_143 -> V_147 & V_165 ) )
* V_186 = 0 ;
V_150 = F_175 ( F_176 () , F_177 ( V_2 ) ) ;
V_188:
F_166 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! V_122 )
return 0 ;
F_65 ( V_2 ) ;
V_56 = F_174 ( V_2 ) ;
V_151 = V_102 ? V_189 : V_190 ;
F_55 ( & V_50 ) ;
F_178 () ;
if ( F_13 ( V_143 -> V_147 & V_165 ) )
return F_170 ( V_143 , V_2 , V_56 , V_150 , V_151 , V_122 ) ;
V_60 = V_143 -> V_155
? F_171 ( V_2 , V_156 , V_143 -> V_155 ) : 0 ;
if ( ! V_60 && V_143 -> V_183 )
V_60 = F_172 ( ( V_122 << 8 ) | 0x7f , V_143 -> V_183 ) ;
V_154 = V_143 -> V_157 ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_101 , & V_154 -> V_158 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( 0 , & V_154 -> V_159 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( ( short ) V_151 , & V_154 -> V_160 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_122 , & V_154 -> V_163 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_56 , & V_154 -> V_161 ) ;
if ( ! V_60 && V_154 )
V_60 = F_172 ( V_150 , & V_154 -> V_162 ) ;
if ( ! V_60 )
V_60 = V_56 ;
F_33 ( V_2 ) ;
F_64 ( ! V_60 ) ;
return V_60 ;
}
static int F_186 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
int V_60 ;
T_2 V_56 ;
T_3 V_150 ;
if ( ! F_13 ( V_143 -> V_147 & V_191 ) )
return 0 ;
if ( ! ( V_2 -> signal -> V_62 & V_192 ) )
return 0 ;
F_164 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! ( V_2 -> signal -> V_62 & V_192 ) ) {
F_166 ( & V_2 -> V_17 -> V_23 ) ;
return 0 ;
}
if ( ! F_13 ( V_143 -> V_147 & V_165 ) )
V_2 -> signal -> V_62 &= ~ V_192 ;
V_150 = F_175 ( F_176 () , F_177 ( V_2 ) ) ;
F_166 ( & V_2 -> V_17 -> V_23 ) ;
V_56 = F_174 ( V_2 ) ;
F_65 ( V_2 ) ;
F_55 ( & V_50 ) ;
F_178 () ;
if ( ! V_143 -> V_157 ) {
V_60 = V_143 -> V_155
? F_171 ( V_2 , V_156 , V_143 -> V_155 ) : 0 ;
F_33 ( V_2 ) ;
if ( ! V_60 && V_143 -> V_183 )
V_60 = F_172 ( 0xffff , V_143 -> V_183 ) ;
if ( ! V_60 )
V_60 = V_56 ;
} else {
V_60 = F_170 ( V_143 , V_2 , V_56 , V_150 ,
V_193 , V_67 ) ;
F_64 ( V_60 == 0 ) ;
}
return V_60 ;
}
static int F_187 ( struct V_142 * V_143 , int V_102 ,
struct V_1 * V_2 )
{
int V_52 = F_188 ( V_2 -> V_52 ) ;
int V_194 ;
if ( F_13 ( V_52 == V_55 ) )
return 0 ;
V_194 = F_169 ( V_143 , V_2 ) ;
if ( ! V_194 )
return V_194 ;
V_194 = F_189 ( V_2 ) ;
if ( F_13 ( V_194 < 0 ) ) {
if ( V_143 -> V_195 )
V_143 -> V_195 = V_194 ;
return 0 ;
}
if ( F_13 ( V_52 == V_169 ) ) {
if ( F_93 ( ! V_102 ) )
V_143 -> V_195 = 0 ;
return 0 ;
}
if ( F_93 ( ! V_102 ) && F_13 ( V_2 -> V_102 ) ) {
if ( ! F_98 ( V_2 ) )
V_102 = 1 ;
}
if ( V_52 == V_53 ) {
if ( ! F_190 ( V_2 ) ) {
if ( F_13 ( V_102 ) || F_93 ( ! V_2 -> V_102 ) )
return F_173 ( V_143 , V_2 ) ;
}
if ( F_93 ( ! V_102 ) || ( V_143 -> V_147 & ( V_191 | V_164 ) ) )
V_143 -> V_195 = 0 ;
} else {
V_143 -> V_195 = 0 ;
}
V_194 = F_185 ( V_143 , V_102 , V_2 ) ;
if ( V_194 )
return V_194 ;
return F_186 ( V_143 , V_2 ) ;
}
static int F_191 ( struct V_142 * V_143 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_61 (p, &tsk->children, sibling) {
int V_194 = F_187 ( V_143 , 0 , V_2 ) ;
if ( V_194 )
return V_194 ;
}
return 0 ;
}
static int F_192 ( struct V_142 * V_143 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_61 (p, &tsk->ptraced, ptrace_entry) {
int V_194 = F_187 ( V_143 , 1 , V_2 ) ;
if ( V_194 )
return V_194 ;
}
return 0 ;
}
static int F_193 ( T_5 * V_196 , unsigned V_197 ,
int V_198 , void * V_199 )
{
struct V_142 * V_143 = F_30 ( V_196 , struct V_142 ,
V_200 ) ;
struct V_1 * V_2 = V_199 ;
if ( ! F_168 ( V_143 , V_2 ) )
return 0 ;
if ( ( V_143 -> V_147 & V_201 ) && V_196 -> V_202 != V_2 -> V_64 )
return 0 ;
return F_194 ( V_196 , V_197 , V_198 , V_199 ) ;
}
void F_195 ( struct V_1 * V_2 , struct V_1 * V_64 )
{
F_196 ( & V_64 -> signal -> V_203 ,
V_204 , 1 , V_2 ) ;
}
static long F_197 ( struct V_142 * V_143 )
{
struct V_1 * V_13 ;
int V_60 ;
F_198 ( V_143 -> V_146 ) ;
F_199 ( & V_143 -> V_200 , F_193 ) ;
V_143 -> V_200 . V_202 = V_61 ;
F_200 ( & V_61 -> signal -> V_203 , & V_143 -> V_200 ) ;
V_47:
V_143 -> V_195 = - V_205 ;
if ( ( V_143 -> V_144 < V_145 ) &&
( ! V_143 -> V_146 || F_201 ( & V_143 -> V_146 -> V_8 [ V_143 -> V_144 ] ) ) )
goto V_206;
F_116 ( V_204 ) ;
F_54 ( & V_50 ) ;
V_13 = V_61 ;
do {
V_60 = F_191 ( V_143 , V_13 ) ;
if ( V_60 )
goto V_207;
V_60 = F_192 ( V_143 , V_13 ) ;
if ( V_60 )
goto V_207;
if ( V_143 -> V_147 & V_201 )
break;
} while_each_thread(current, tsk) ;
