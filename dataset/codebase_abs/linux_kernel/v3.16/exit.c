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
F_17 ( V_13 , & V_21 , & V_22 ) ;
V_15 -> V_21 += V_21 ;
V_15 -> V_22 += V_22 ;
V_15 -> V_27 += F_18 ( V_13 ) ;
V_15 -> V_28 += V_13 -> V_28 ;
V_15 -> V_29 += V_13 -> V_29 ;
V_15 -> V_30 += V_13 -> V_30 ;
V_15 -> V_31 += V_13 -> V_31 ;
V_15 -> V_32 += F_19 ( V_13 ) ;
V_15 -> V_33 += F_20 ( V_13 ) ;
F_21 ( & V_15 -> V_34 , & V_13 -> V_34 ) ;
V_15 -> V_35 += V_13 -> V_36 . V_37 ;
}
V_15 -> V_4 -- ;
F_1 ( V_13 , V_3 ) ;
F_22 ( & V_13 -> V_38 ) ;
V_13 -> V_17 = NULL ;
F_23 ( & V_17 -> V_23 ) ;
F_24 ( V_17 ) ;
F_25 ( V_13 , V_39 ) ;
if ( V_3 ) {
F_22 ( & V_15 -> V_40 ) ;
F_26 ( V_20 ) ;
}
}
static void F_27 ( struct V_41 * V_42 )
{
struct V_1 * V_13 = F_28 ( V_42 , struct V_1 , V_43 ) ;
F_29 ( V_13 ) ;
F_30 ( V_13 ) ;
F_31 ( V_13 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_1 * V_44 ;
int V_45 ;
V_46:
F_33 () ;
F_34 ( & F_35 ( V_2 ) -> V_47 -> V_48 ) ;
F_36 () ;
F_37 ( V_2 ) ;
F_38 ( & V_49 ) ;
F_39 ( V_2 ) ;
F_6 ( V_2 ) ;
V_45 = 0 ;
V_44 = V_2 -> V_50 ;
if ( V_44 != V_2 && F_40 ( V_44 ) && V_44 -> V_51 == V_52 ) {
V_45 = F_41 ( V_44 , V_44 -> V_53 ) ;
if ( V_45 )
V_44 -> V_51 = V_54 ;
}
F_42 ( & V_49 ) ;
F_43 ( V_2 ) ;
F_44 ( & V_2 -> V_43 , F_27 ) ;
V_2 = V_44 ;
if ( F_13 ( V_45 ) )
goto V_46;
}
struct V_55 * F_45 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_55 * V_57 = NULL ;
V_2 = F_46 ( V_56 , V_6 ) ;
if ( V_2 == NULL )
V_2 = F_46 ( V_56 , V_5 ) ;
if ( V_2 != NULL )
V_57 = F_47 ( V_2 ) ;
return V_57 ;
}
static int F_48 ( struct V_55 * V_56 , struct V_1 * V_58 )
{
struct V_1 * V_2 ;
F_49 (pgrp, PIDTYPE_PGID, p) {
if ( ( V_2 == V_58 ) ||
( V_2 -> V_51 && F_40 ( V_2 ) ) ||
F_50 ( V_2 -> V_59 ) )
continue;
if ( F_51 ( V_2 -> V_59 ) != V_56 &&
F_47 ( V_2 -> V_59 ) == F_47 ( V_2 ) )
return 0 ;
} F_52 ( V_56 , V_6 , V_2 ) ;
return 1 ;
}
int F_53 ( void )
{
int V_60 ;
F_54 ( & V_49 ) ;
V_60 = F_48 ( F_51 ( V_61 ) , NULL ) ;
F_55 ( & V_49 ) ;
return V_60 ;
}
static bool F_56 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
F_49 (pgrp, PIDTYPE_PGID, p) {
if ( V_2 -> signal -> V_62 & V_63 )
return true ;
} F_52 ( V_56 , V_6 , V_2 ) ;
return false ;
}
static void
F_57 ( struct V_1 * V_13 , struct V_1 * V_64 )
{
struct V_55 * V_56 = F_51 ( V_13 ) ;
struct V_1 * V_58 = V_13 ;
if ( ! V_64 )
V_64 = V_13 -> V_59 ;
else
V_58 = NULL ;
if ( F_51 ( V_64 ) != V_56 &&
F_47 ( V_64 ) == F_47 ( V_13 ) &&
F_48 ( V_56 , V_58 ) &&
F_56 ( V_56 ) ) {
F_58 ( V_65 , V_66 , V_56 ) ;
F_58 ( V_67 , V_66 , V_56 ) ;
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
F_54 ( & V_49 ) ;
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
F_55 ( & V_49 ) ;
V_69 -> V_73 = NULL ;
return;
V_75:
F_64 ( V_70 == V_2 ) ;
F_65 ( V_70 ) ;
F_66 ( V_70 ) ;
F_55 ( & V_49 ) ;
if ( V_70 -> V_69 != V_69 ) {
F_67 ( V_70 ) ;
F_31 ( V_70 ) ;
goto V_72;
}
V_69 -> V_73 = V_70 ;
F_67 ( V_70 ) ;
F_31 ( V_70 ) ;
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
}
static struct V_1 * F_82 ( struct V_1 * V_89 )
__releases( &tasklist_lock
void F_83 ( struct V_1 * V_89 , struct V_1 * V_2 ,
struct V_90 * V_91 )
{
F_84 ( & V_2 -> V_9 , & V_2 -> V_59 -> V_92 ) ;
if ( V_2 -> V_51 == V_54 )
return;
if ( F_85 ( V_2 -> V_59 , V_89 ) )
return;
V_2 -> V_53 = V_93 ;
if ( ! V_2 -> V_94 &&
V_2 -> V_51 == V_52 && F_40 ( V_2 ) ) {
if ( F_41 ( V_2 , V_2 -> V_53 ) ) {
V_2 -> V_51 = V_54 ;
F_84 ( & V_2 -> V_9 , V_91 ) ;
}
}
F_57 ( V_2 , V_89 ) ;
}
static void F_86 ( struct V_1 * V_89 )
{
struct V_1 * V_2 , * V_95 , * V_96 ;
F_87 ( V_97 ) ;
F_38 ( & V_49 ) ;
F_88 ( V_89 ) ;
V_96 = F_82 ( V_89 ) ;
F_89 (p, n, &father->children, sibling) {
struct V_1 * V_98 = V_2 ;
do {
V_98 -> V_59 = V_96 ;
if ( V_98 -> V_64 == V_89 ) {
F_64 ( V_98 -> V_94 ) ;
V_98 -> V_64 = V_98 -> V_59 ;
}
if ( V_98 -> V_99 )
F_90 ( V_98 -> V_99 ,
V_100 , V_98 ) ;
} while_each_thread(p, t) ;
F_83 ( V_89 , V_2 , & V_97 ) ;
}
void F_91 ( struct V_1 * V_13 , int V_3 )
{
bool V_101 ;
F_86 ( V_13 ) ;
F_38 ( & V_49 ) ;
if ( V_3 )
F_57 ( V_13 -> V_50 , NULL ) ;
if ( F_13 ( V_13 -> V_94 ) ) {
int V_15 = F_7 ( V_13 ) &&
F_40 ( V_13 ) &&
! F_92 ( V_13 ) ?
V_13 -> V_53 : V_93 ;
V_101 = F_41 ( V_13 , V_15 ) ;
} else if ( F_7 ( V_13 ) ) {
V_101 = F_40 ( V_13 ) &&
F_41 ( V_13 , V_13 -> V_53 ) ;
} else {
V_101 = true ;
}
V_13 -> V_51 = V_101 ? V_54 : V_52 ;
if ( F_13 ( V_13 -> signal -> V_24 < 0 ) )
F_15 ( V_13 -> signal -> V_25 ) ;
F_42 ( & V_49 ) ;
if ( V_101 )
F_32 ( V_13 ) ;
}
static void F_93 ( void )
{
static F_94 ( V_102 ) ;
static int V_103 = V_104 ;
unsigned long free ;
free = F_95 ( V_61 ) ;
if ( free >= V_103 )
return;
F_10 ( & V_102 ) ;
if ( free < V_103 ) {
F_96 ( V_105 L_1
L_2 ,
V_61 -> V_106 , F_97 ( V_61 ) , free ) ;
V_103 = free ;
}
F_23 ( & V_102 ) ;
}
static inline void F_93 ( void ) {}
void F_98 ( long V_107 )
{
struct V_1 * V_13 = V_61 ;
int V_3 ;
F_99 ( V_13 ) ;
F_100 ( F_101 ( V_13 ) ) ;
if ( F_13 ( F_102 () ) )
F_103 ( L_3 ) ;
if ( F_13 ( ! V_13 -> V_55 ) )
F_103 ( L_4 ) ;
F_104 ( V_108 ) ;
F_105 ( V_109 , V_107 ) ;
F_106 ( V_13 ) ;
if ( F_13 ( V_13 -> V_62 & V_110 ) ) {
F_96 ( V_111
L_5 ) ;
V_13 -> V_62 |= V_112 ;
F_107 ( V_85 ) ;
F_108 () ;
}
F_109 ( V_13 ) ;
F_110 () ;
F_111 ( & V_13 -> V_113 ) ;
if ( F_13 ( F_112 () ) )
F_96 ( V_114 L_6 ,
V_61 -> V_106 , F_97 ( V_61 ) ,
F_113 () ) ;
F_114 ( V_13 ) ;
if ( V_13 -> V_69 )
F_70 ( V_13 -> V_69 ) ;
V_3 = F_74 ( & V_13 -> signal -> V_115 ) ;
if ( V_3 ) {
F_115 ( & V_13 -> signal -> V_116 ) ;
F_116 ( V_13 -> signal ) ;
if ( V_13 -> V_69 )
F_117 ( & V_13 -> signal -> V_117 , V_13 -> V_69 ) ;
}
F_118 ( V_107 , V_3 ) ;
if ( V_3 )
F_119 () ;
F_120 ( V_13 ) ;
V_13 -> V_118 = V_107 ;
F_121 ( V_13 , V_3 ) ;
F_68 ( V_13 ) ;
if ( V_3 )
F_122 () ;
F_123 ( V_13 ) ;
F_124 ( V_13 ) ;
F_125 ( V_13 ) ;
F_126 ( V_13 ) ;
F_127 ( V_13 ) ;
if ( V_3 )
F_128 ( 1 ) ;
F_129 ( V_13 ) ;
F_130 ( V_13 ) ;
F_131 () ;
F_132 ( V_13 ) ;
F_133 ( V_13 ) ;
F_134 ( F_135 ( V_13 ) -> V_119 -> V_120 ) ;
F_136 ( V_13 ) ;
F_91 ( V_13 , V_3 ) ;
F_137 ( V_13 ) ;
#ifdef F_138
F_66 ( V_13 ) ;
F_139 ( V_13 -> V_121 ) ;
V_13 -> V_121 = NULL ;
F_67 ( V_13 ) ;
#endif
#ifdef F_140
if ( F_13 ( V_61 -> V_122 ) )
F_141 ( V_61 -> V_122 ) ;
#endif
F_142 () ;
V_13 -> V_62 |= V_112 ;
if ( V_13 -> V_123 )
F_143 ( V_13 ) ;
if ( V_13 -> V_124 )
F_144 ( V_13 -> V_124 ) ;
if ( V_13 -> V_125 . V_126 )
F_145 ( V_13 -> V_125 . V_126 ) ;
F_106 ( V_13 ) ;
F_93 () ;
F_146 () ;
if ( V_13 -> V_127 )
F_147 ( V_128 , V_13 -> V_127 ) ;
F_148 () ;
F_110 () ;
F_111 ( & V_13 -> V_113 ) ;
V_13 -> V_129 = V_130 ;
V_13 -> V_62 |= V_131 ;
F_108 () ;
F_149 () ;
for (; ; )
F_150 () ;
}
void F_151 ( struct V_132 * V_133 , long V_107 )
{
if ( V_133 )
F_75 ( V_133 ) ;
F_98 ( V_107 ) ;
}
void
F_152 ( int V_118 )
{
struct V_14 * V_15 = V_61 -> signal ;
F_64 ( V_118 & 0x80 ) ;
if ( F_153 ( V_15 ) )
V_118 = V_15 -> V_134 ;
else if ( ! F_40 ( V_61 ) ) {
struct V_16 * const V_17 = V_61 -> V_17 ;
F_154 ( & V_17 -> V_23 ) ;
if ( F_153 ( V_15 ) )
V_118 = V_15 -> V_134 ;
else {
V_15 -> V_134 = V_118 ;
V_15 -> V_62 = V_135 ;
F_155 ( V_61 ) ;
}
F_156 ( & V_17 -> V_23 ) ;
}
F_98 ( V_118 ) ;
}
static inline
struct V_55 * F_157 ( struct V_1 * V_81 , enum V_136 type )
{
if ( type != V_5 )
V_81 = V_81 -> V_50 ;
return V_81 -> V_137 [ type ] . V_55 ;
}
static int F_158 ( struct V_138 * V_139 , struct V_1 * V_2 )
{
return V_139 -> V_140 == V_141 ||
F_157 ( V_2 , V_139 -> V_140 ) == V_139 -> V_142 ;
}
static int F_159 ( struct V_138 * V_139 , struct V_1 * V_2 )
{
if ( ! F_158 ( V_139 , V_2 ) )
return 0 ;
if ( ( ( V_2 -> V_53 != V_93 ) ^ ! ! ( V_139 -> V_143 & V_144 ) )
&& ! ( V_139 -> V_143 & V_145 ) )
return 0 ;
return 1 ;
}
static int F_160 ( struct V_138 * V_139 , struct V_1 * V_2 ,
T_2 V_55 , T_3 V_146 , int V_147 , int V_148 )
{
struct V_149 T_4 * V_150 ;
int V_60 = V_139 -> V_151
? F_161 ( V_2 , V_152 , V_139 -> V_151 ) : 0 ;
F_31 ( V_2 ) ;
V_150 = V_139 -> V_153 ;
if ( V_150 ) {
if ( ! V_60 )
V_60 = F_162 ( V_93 , & V_150 -> V_154 ) ;
if ( ! V_60 )
V_60 = F_162 ( 0 , & V_150 -> V_155 ) ;
if ( ! V_60 )
V_60 = F_162 ( ( short ) V_147 , & V_150 -> V_156 ) ;
if ( ! V_60 )
V_60 = F_162 ( V_55 , & V_150 -> V_157 ) ;
if ( ! V_60 )
V_60 = F_162 ( V_146 , & V_150 -> V_158 ) ;
if ( ! V_60 )
V_60 = F_162 ( V_148 , & V_150 -> V_159 ) ;
}
if ( ! V_60 )
V_60 = V_55 ;
return V_60 ;
}
static int F_163 ( struct V_138 * V_139 , struct V_1 * V_2 )
{
unsigned long V_129 ;
int V_60 , V_148 , V_160 ;
T_2 V_55 = F_164 ( V_2 ) ;
T_3 V_146 = F_165 ( F_166 () , F_167 ( V_2 ) ) ;
struct V_149 T_4 * V_150 ;
if ( ! F_168 ( V_139 -> V_143 & V_161 ) )
return 0 ;
if ( F_13 ( V_139 -> V_143 & V_162 ) ) {
int V_118 = V_2 -> V_118 ;
int V_147 ;
F_65 ( V_2 ) ;
F_55 ( & V_49 ) ;
if ( ( V_118 & 0x7f ) == 0 ) {
V_147 = V_163 ;
V_148 = V_118 >> 8 ;
} else {
V_147 = ( V_118 & 0x80 ) ? V_164 : V_165 ;
V_148 = V_118 & 0x7f ;
}
return F_160 ( V_139 , V_2 , V_55 , V_146 , V_147 , V_148 ) ;
}
V_160 = F_92 ( V_2 ) ;
V_129 = V_160 && F_7 ( V_2 ) ? V_166 : V_54 ;
if ( F_169 ( & V_2 -> V_51 , V_52 , V_129 ) != V_52 )
return 0 ;
if ( F_168 ( ! V_160 ) && F_7 ( V_2 ) ) {
struct V_14 * V_167 ;
struct V_14 * V_15 ;
unsigned long V_117 ;
T_1 V_168 , V_169 ;
F_170 ( V_2 , & V_168 , & V_169 ) ;
F_154 ( & V_2 -> V_59 -> V_17 -> V_23 ) ;
V_167 = V_2 -> V_59 -> signal ;
V_15 = V_2 -> signal ;
V_167 -> V_170 += V_168 + V_15 -> V_170 ;
V_167 -> V_171 += V_169 + V_15 -> V_171 ;
V_167 -> V_172 += F_18 ( V_2 ) + V_15 -> V_27 + V_15 -> V_172 ;
V_167 -> V_173 +=
V_2 -> V_28 + V_15 -> V_28 + V_15 -> V_173 ;
V_167 -> V_174 +=
V_2 -> V_29 + V_15 -> V_29 + V_15 -> V_174 ;
V_167 -> V_175 +=
V_2 -> V_30 + V_15 -> V_30 + V_15 -> V_175 ;
V_167 -> V_176 +=
V_2 -> V_31 + V_15 -> V_31 + V_15 -> V_176 ;
V_167 -> V_177 +=
F_19 ( V_2 ) +
V_15 -> V_32 + V_15 -> V_177 ;
V_167 -> V_178 +=
F_20 ( V_2 ) +
V_15 -> V_33 + V_15 -> V_178 ;
V_117 = F_171 ( V_15 -> V_117 , V_15 -> V_179 ) ;
if ( V_167 -> V_179 < V_117 )
V_167 -> V_179 = V_117 ;
F_21 ( & V_167 -> V_34 , & V_2 -> V_34 ) ;
F_21 ( & V_167 -> V_34 , & V_15 -> V_34 ) ;
F_156 ( & V_2 -> V_59 -> V_17 -> V_23 ) ;
}
F_55 ( & V_49 ) ;
V_60 = V_139 -> V_151
? F_161 ( V_2 , V_152 , V_139 -> V_151 ) : 0 ;
V_148 = ( V_2 -> signal -> V_62 & V_135 )
? V_2 -> signal -> V_134 : V_2 -> V_118 ;
if ( ! V_60 && V_139 -> V_180 )
V_60 = F_162 ( V_148 , V_139 -> V_180 ) ;
V_150 = V_139 -> V_153 ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_93 , & V_150 -> V_154 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( 0 , & V_150 -> V_155 ) ;
if ( ! V_60 && V_150 ) {
int V_147 ;
if ( ( V_148 & 0x7f ) == 0 ) {
V_147 = V_163 ;
V_148 >>= 8 ;
} else {
V_147 = ( V_148 & 0x80 ) ? V_164 : V_165 ;
V_148 &= 0x7f ;
}
V_60 = F_162 ( ( short ) V_147 , & V_150 -> V_156 ) ;
if ( ! V_60 )
V_60 = F_162 ( V_148 , & V_150 -> V_159 ) ;
}
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_55 , & V_150 -> V_157 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_146 , & V_150 -> V_158 ) ;
if ( ! V_60 )
V_60 = V_55 ;
if ( V_129 == V_166 ) {
F_38 ( & V_49 ) ;
F_172 ( V_2 ) ;
V_129 = V_52 ;
if ( F_41 ( V_2 , V_2 -> V_53 ) )
V_129 = V_54 ;
V_2 -> V_51 = V_129 ;
F_42 ( & V_49 ) ;
}
if ( V_129 == V_54 )
F_32 ( V_2 ) ;
return V_60 ;
}
static int * F_173 ( struct V_1 * V_2 , bool V_94 )
{
if ( V_94 ) {
if ( F_174 ( V_2 ) &&
! ( V_2 -> V_181 & V_182 ) )
return & V_2 -> V_118 ;
} else {
if ( V_2 -> signal -> V_62 & V_63 )
return & V_2 -> signal -> V_134 ;
}
return NULL ;
}
static int F_175 ( struct V_138 * V_139 ,
int V_94 , struct V_1 * V_2 )
{
struct V_149 T_4 * V_150 ;
int V_60 , V_118 , * V_183 , V_147 ;
T_3 V_146 = 0 ;
T_2 V_55 ;
if ( ! V_94 && ! ( V_139 -> V_143 & V_184 ) )
return 0 ;
if ( ! F_173 ( V_2 , V_94 ) )
return 0 ;
V_118 = 0 ;
F_154 ( & V_2 -> V_17 -> V_23 ) ;
V_183 = F_173 ( V_2 , V_94 ) ;
if ( F_13 ( ! V_183 ) )
goto V_185;
V_118 = * V_183 ;
if ( ! V_118 )
goto V_185;
if ( ! F_13 ( V_139 -> V_143 & V_162 ) )
* V_183 = 0 ;
V_146 = F_165 ( F_166 () , F_167 ( V_2 ) ) ;
V_185:
F_156 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! V_118 )
return 0 ;
F_65 ( V_2 ) ;
V_55 = F_164 ( V_2 ) ;
V_147 = V_94 ? V_186 : V_187 ;
F_55 ( & V_49 ) ;
if ( F_13 ( V_139 -> V_143 & V_162 ) )
return F_160 ( V_139 , V_2 , V_55 , V_146 , V_147 , V_118 ) ;
V_60 = V_139 -> V_151
? F_161 ( V_2 , V_152 , V_139 -> V_151 ) : 0 ;
if ( ! V_60 && V_139 -> V_180 )
V_60 = F_162 ( ( V_118 << 8 ) | 0x7f , V_139 -> V_180 ) ;
V_150 = V_139 -> V_153 ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_93 , & V_150 -> V_154 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( 0 , & V_150 -> V_155 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( ( short ) V_147 , & V_150 -> V_156 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_118 , & V_150 -> V_159 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_55 , & V_150 -> V_157 ) ;
if ( ! V_60 && V_150 )
V_60 = F_162 ( V_146 , & V_150 -> V_158 ) ;
if ( ! V_60 )
V_60 = V_55 ;
F_31 ( V_2 ) ;
F_64 ( ! V_60 ) ;
return V_60 ;
}
static int F_176 ( struct V_138 * V_139 , struct V_1 * V_2 )
{
int V_60 ;
T_2 V_55 ;
T_3 V_146 ;
if ( ! F_13 ( V_139 -> V_143 & V_188 ) )
return 0 ;
if ( ! ( V_2 -> signal -> V_62 & V_189 ) )
return 0 ;
F_154 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! ( V_2 -> signal -> V_62 & V_189 ) ) {
F_156 ( & V_2 -> V_17 -> V_23 ) ;
return 0 ;
}
if ( ! F_13 ( V_139 -> V_143 & V_162 ) )
V_2 -> signal -> V_62 &= ~ V_189 ;
V_146 = F_165 ( F_166 () , F_167 ( V_2 ) ) ;
F_156 ( & V_2 -> V_17 -> V_23 ) ;
V_55 = F_164 ( V_2 ) ;
F_65 ( V_2 ) ;
F_55 ( & V_49 ) ;
if ( ! V_139 -> V_153 ) {
V_60 = V_139 -> V_151
? F_161 ( V_2 , V_152 , V_139 -> V_151 ) : 0 ;
F_31 ( V_2 ) ;
if ( ! V_60 && V_139 -> V_180 )
V_60 = F_162 ( 0xffff , V_139 -> V_180 ) ;
if ( ! V_60 )
V_60 = V_55 ;
} else {
V_60 = F_160 ( V_139 , V_2 , V_55 , V_146 ,
V_190 , V_67 ) ;
F_64 ( V_60 == 0 ) ;
}
return V_60 ;
}
static int F_177 ( struct V_138 * V_139 , int V_94 ,
struct V_1 * V_2 )
{
int V_191 ;
if ( F_13 ( V_2 -> V_51 == V_54 ) )
return 0 ;
V_191 = F_159 ( V_139 , V_2 ) ;
if ( ! V_191 )
return V_191 ;
V_191 = F_178 ( V_2 ) ;
if ( F_13 ( V_191 < 0 ) ) {
if ( V_139 -> V_192 )
V_139 -> V_192 = V_191 ;
return 0 ;
}
if ( F_13 ( V_2 -> V_51 == V_166 ) ) {
if ( F_168 ( ! V_94 ) )
V_139 -> V_192 = 0 ;
return 0 ;
}
if ( F_168 ( ! V_94 ) && F_13 ( V_2 -> V_94 ) ) {
if ( ! F_92 ( V_2 ) )
V_94 = 1 ;
}
if ( V_2 -> V_51 == V_52 ) {
if ( ! F_179 ( V_2 ) ) {
if ( F_13 ( V_94 ) || F_168 ( ! V_2 -> V_94 ) )
return F_163 ( V_139 , V_2 ) ;
}
if ( F_168 ( ! V_94 ) || ( V_139 -> V_143 & ( V_188 | V_161 ) ) )
V_139 -> V_192 = 0 ;
} else {
V_139 -> V_192 = 0 ;
}
V_191 = F_175 ( V_139 , V_94 , V_2 ) ;
if ( V_191 )
return V_191 ;
return F_176 ( V_139 , V_2 ) ;
}
static int F_180 ( struct V_138 * V_139 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_61 (p, &tsk->children, sibling) {
int V_191 = F_177 ( V_139 , 0 , V_2 ) ;
if ( V_191 )
return V_191 ;
}
return 0 ;
}
static int F_181 ( struct V_138 * V_139 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_61 (p, &tsk->ptraced, ptrace_entry) {
int V_191 = F_177 ( V_139 , 1 , V_2 ) ;
if ( V_191 )
return V_191 ;
}
return 0 ;
}
static int F_182 ( T_5 * V_193 , unsigned V_194 ,
int V_195 , void * V_196 )
{
struct V_138 * V_139 = F_28 ( V_193 , struct V_138 ,
V_197 ) ;
struct V_1 * V_2 = V_196 ;
if ( ! F_158 ( V_139 , V_2 ) )
return 0 ;
if ( ( V_139 -> V_143 & V_198 ) && V_193 -> V_199 != V_2 -> V_64 )
return 0 ;
return F_183 ( V_193 , V_194 , V_195 , V_196 ) ;
}
void F_184 ( struct V_1 * V_2 , struct V_1 * V_64 )
{
F_185 ( & V_64 -> signal -> V_200 ,
V_201 , 1 , V_2 ) ;
}
static long F_186 ( struct V_138 * V_139 )
{
struct V_1 * V_13 ;
int V_60 ;
F_187 ( V_139 -> V_142 ) ;
F_188 ( & V_139 -> V_197 , F_182 ) ;
V_139 -> V_197 . V_199 = V_61 ;
F_189 ( & V_61 -> signal -> V_200 , & V_139 -> V_197 ) ;
V_46:
V_139 -> V_192 = - V_202 ;
if ( ( V_139 -> V_140 < V_141 ) &&
( ! V_139 -> V_142 || F_190 ( & V_139 -> V_142 -> V_8 [ V_139 -> V_140 ] ) ) )
goto V_203;
F_107 ( V_201 ) ;
F_54 ( & V_49 ) ;
V_13 = V_61 ;
do {
V_60 = F_180 ( V_139 , V_13 ) ;
if ( V_60 )
goto V_204;
V_60 = F_181 ( V_139 , V_13 ) ;
if ( V_60 )
goto V_204;
if ( V_139 -> V_143 & V_198 )
break;
} while_each_thread(current, tsk) ;
