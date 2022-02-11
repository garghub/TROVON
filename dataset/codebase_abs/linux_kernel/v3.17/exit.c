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
if ( V_44 != V_2 && F_40 ( V_44 )
&& V_44 -> V_51 == V_52 ) {
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
static int F_48 ( struct V_55 * V_56 ,
struct V_1 * V_58 )
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
F_82 ( V_89 ) ;
}
static struct V_1 * F_83 ( struct V_1 * V_90 )
__releases( &tasklist_lock
void F_84 ( struct V_1 * V_90 , struct V_1 * V_2 ,
struct V_91 * V_92 )
{
F_85 ( & V_2 -> V_9 , & V_2 -> V_59 -> V_93 ) ;
if ( V_2 -> V_51 == V_54 )
return;
if ( F_86 ( V_2 -> V_59 , V_90 ) )
return;
V_2 -> V_53 = V_94 ;
if ( ! V_2 -> V_95 &&
V_2 -> V_51 == V_52 && F_40 ( V_2 ) ) {
if ( F_41 ( V_2 , V_2 -> V_53 ) ) {
V_2 -> V_51 = V_54 ;
F_85 ( & V_2 -> V_9 , V_92 ) ;
}
}
F_57 ( V_2 , V_90 ) ;
}
static void F_87 ( struct V_1 * V_90 )
{
struct V_1 * V_2 , * V_96 , * V_97 ;
F_88 ( V_98 ) ;
F_38 ( & V_49 ) ;
F_89 ( V_90 ) ;
V_97 = F_83 ( V_90 ) ;
F_90 (p, n, &father->children, sibling) {
struct V_1 * V_99 = V_2 ;
do {
V_99 -> V_59 = V_97 ;
if ( V_99 -> V_64 == V_90 ) {
F_64 ( V_99 -> V_95 ) ;
V_99 -> V_64 = V_99 -> V_59 ;
}
if ( V_99 -> V_100 )
F_91 ( V_99 -> V_100 ,
V_101 , V_99 ) ;
} while_each_thread(p, t) ;
F_84 ( V_90 , V_2 , & V_98 ) ;
}
void F_92 ( struct V_1 * V_13 , int V_3 )
{
bool V_102 ;
F_87 ( V_13 ) ;
F_38 ( & V_49 ) ;
if ( V_3 )
F_57 ( V_13 -> V_50 , NULL ) ;
if ( F_13 ( V_13 -> V_95 ) ) {
int V_15 = F_7 ( V_13 ) &&
F_40 ( V_13 ) &&
! F_93 ( V_13 ) ?
V_13 -> V_53 : V_94 ;
V_102 = F_41 ( V_13 , V_15 ) ;
} else if ( F_7 ( V_13 ) ) {
V_102 = F_40 ( V_13 ) &&
F_41 ( V_13 , V_13 -> V_53 ) ;
} else {
V_102 = true ;
}
V_13 -> V_51 = V_102 ? V_54 : V_52 ;
if ( F_13 ( V_13 -> signal -> V_24 < 0 ) )
F_15 ( V_13 -> signal -> V_25 ) ;
F_42 ( & V_49 ) ;
if ( V_102 )
F_32 ( V_13 ) ;
}
static void F_94 ( void )
{
static F_95 ( V_103 ) ;
static int V_104 = V_105 ;
unsigned long free ;
free = F_96 ( V_61 ) ;
if ( free >= V_104 )
return;
F_10 ( & V_103 ) ;
if ( free < V_104 ) {
F_97 ( L_1 ,
V_61 -> V_106 , F_98 ( V_61 ) , free ) ;
V_104 = free ;
}
F_23 ( & V_103 ) ;
}
static inline void F_94 ( void ) {}
void F_99 ( long V_107 )
{
struct V_1 * V_13 = V_61 ;
int V_3 ;
F_100 ( V_13 ) ;
F_101 ( F_102 ( V_13 ) ) ;
if ( F_13 ( F_103 () ) )
F_104 ( L_2 ) ;
if ( F_13 ( ! V_13 -> V_55 ) )
F_104 ( L_3 ) ;
F_105 ( V_108 ) ;
F_106 ( V_109 , V_107 ) ;
F_107 ( V_13 ) ;
if ( F_13 ( V_13 -> V_62 & V_110 ) ) {
F_108 ( L_4 ) ;
V_13 -> V_62 |= V_111 ;
F_109 ( V_85 ) ;
F_110 () ;
}
F_111 ( V_13 ) ;
F_112 () ;
F_113 ( & V_13 -> V_112 ) ;
if ( F_13 ( F_114 () ) )
F_115 ( L_5 ,
V_61 -> V_106 , F_98 ( V_61 ) ,
F_116 () ) ;
F_117 ( V_13 ) ;
if ( V_13 -> V_69 )
F_70 ( V_13 -> V_69 ) ;
V_3 = F_74 ( & V_13 -> signal -> V_113 ) ;
if ( V_3 ) {
F_118 ( & V_13 -> signal -> V_114 ) ;
F_119 ( V_13 -> signal ) ;
if ( V_13 -> V_69 )
F_120 ( & V_13 -> signal -> V_115 , V_13 -> V_69 ) ;
}
F_121 ( V_107 , V_3 ) ;
if ( V_3 )
F_122 () ;
F_123 ( V_13 ) ;
V_13 -> V_116 = V_107 ;
F_124 ( V_13 , V_3 ) ;
F_68 ( V_13 ) ;
if ( V_3 )
F_125 () ;
F_126 ( V_13 ) ;
F_127 ( V_13 ) ;
F_128 ( V_13 ) ;
F_129 ( V_13 ) ;
F_130 ( V_13 ) ;
if ( V_3 )
F_131 ( 1 ) ;
F_132 ( V_13 ) ;
F_133 ( V_13 ) ;
F_134 () ;
F_135 ( V_13 ) ;
F_136 ( V_13 ) ;
F_137 ( F_138 ( V_13 ) -> V_117 -> V_118 ) ;
F_139 ( V_13 ) ;
F_92 ( V_13 , V_3 ) ;
F_140 ( V_13 ) ;
#ifdef F_141
F_66 ( V_13 ) ;
F_142 ( V_13 -> V_119 ) ;
V_13 -> V_119 = NULL ;
F_67 ( V_13 ) ;
#endif
#ifdef F_143
if ( F_13 ( V_61 -> V_120 ) )
F_144 ( V_61 -> V_120 ) ;
#endif
F_145 () ;
V_13 -> V_62 |= V_111 ;
if ( V_13 -> V_121 )
F_146 ( V_13 ) ;
if ( V_13 -> V_122 )
F_147 ( V_13 -> V_122 ) ;
if ( V_13 -> V_123 . V_124 )
F_148 ( V_13 -> V_123 . V_124 ) ;
F_107 ( V_13 ) ;
F_94 () ;
F_149 () ;
if ( V_13 -> V_125 )
F_150 ( V_126 , V_13 -> V_125 ) ;
F_151 () ;
F_112 () ;
F_113 ( & V_13 -> V_112 ) ;
V_13 -> V_127 = V_128 ;
V_13 -> V_62 |= V_129 ;
F_110 () ;
F_152 () ;
for (; ; )
F_153 () ;
}
void F_154 ( struct V_130 * V_131 , long V_107 )
{
if ( V_131 )
F_75 ( V_131 ) ;
F_99 ( V_107 ) ;
}
void
F_155 ( int V_116 )
{
struct V_14 * V_15 = V_61 -> signal ;
F_64 ( V_116 & 0x80 ) ;
if ( F_156 ( V_15 ) )
V_116 = V_15 -> V_132 ;
else if ( ! F_40 ( V_61 ) ) {
struct V_16 * const V_17 = V_61 -> V_17 ;
F_157 ( & V_17 -> V_23 ) ;
if ( F_156 ( V_15 ) )
V_116 = V_15 -> V_132 ;
else {
V_15 -> V_132 = V_116 ;
V_15 -> V_62 = V_133 ;
F_158 ( V_61 ) ;
}
F_159 ( & V_17 -> V_23 ) ;
}
F_99 ( V_116 ) ;
}
static inline
struct V_55 * F_160 ( struct V_1 * V_81 , enum V_134 type )
{
if ( type != V_5 )
V_81 = V_81 -> V_50 ;
return V_81 -> V_135 [ type ] . V_55 ;
}
static int F_161 ( struct V_136 * V_137 , struct V_1 * V_2 )
{
return V_137 -> V_138 == V_139 ||
F_160 ( V_2 , V_137 -> V_138 ) == V_137 -> V_140 ;
}
static int F_162 ( struct V_136 * V_137 , struct V_1 * V_2 )
{
if ( ! F_161 ( V_137 , V_2 ) )
return 0 ;
if ( ( ( V_2 -> V_53 != V_94 ) ^ ! ! ( V_137 -> V_141 & V_142 ) )
&& ! ( V_137 -> V_141 & V_143 ) )
return 0 ;
return 1 ;
}
static int F_163 ( struct V_136 * V_137 , struct V_1 * V_2 ,
T_2 V_55 , T_3 V_144 , int V_145 , int V_146 )
{
struct V_147 T_4 * V_148 ;
int V_60 = V_137 -> V_149
? F_164 ( V_2 , V_150 , V_137 -> V_149 ) : 0 ;
F_31 ( V_2 ) ;
V_148 = V_137 -> V_151 ;
if ( V_148 ) {
if ( ! V_60 )
V_60 = F_165 ( V_94 , & V_148 -> V_152 ) ;
if ( ! V_60 )
V_60 = F_165 ( 0 , & V_148 -> V_153 ) ;
if ( ! V_60 )
V_60 = F_165 ( ( short ) V_145 , & V_148 -> V_154 ) ;
if ( ! V_60 )
V_60 = F_165 ( V_55 , & V_148 -> V_155 ) ;
if ( ! V_60 )
V_60 = F_165 ( V_144 , & V_148 -> V_156 ) ;
if ( ! V_60 )
V_60 = F_165 ( V_146 , & V_148 -> V_157 ) ;
}
if ( ! V_60 )
V_60 = V_55 ;
return V_60 ;
}
static int F_166 ( struct V_136 * V_137 , struct V_1 * V_2 )
{
unsigned long V_127 ;
int V_60 , V_146 , V_158 ;
T_2 V_55 = F_167 ( V_2 ) ;
T_3 V_144 = F_168 ( F_169 () , F_170 ( V_2 ) ) ;
struct V_147 T_4 * V_148 ;
if ( ! F_171 ( V_137 -> V_141 & V_159 ) )
return 0 ;
if ( F_13 ( V_137 -> V_141 & V_160 ) ) {
int V_116 = V_2 -> V_116 ;
int V_145 ;
F_65 ( V_2 ) ;
F_55 ( & V_49 ) ;
if ( ( V_116 & 0x7f ) == 0 ) {
V_145 = V_161 ;
V_146 = V_116 >> 8 ;
} else {
V_145 = ( V_116 & 0x80 ) ? V_162 : V_163 ;
V_146 = V_116 & 0x7f ;
}
return F_163 ( V_137 , V_2 , V_55 , V_144 , V_145 , V_146 ) ;
}
V_158 = F_93 ( V_2 ) ;
V_127 = V_158 && F_7 ( V_2 ) ? V_164 : V_54 ;
if ( F_172 ( & V_2 -> V_51 , V_52 , V_127 ) != V_52 )
return 0 ;
if ( F_171 ( ! V_158 ) && F_7 ( V_2 ) ) {
struct V_14 * V_165 ;
struct V_14 * V_15 ;
unsigned long V_115 ;
T_1 V_166 , V_167 ;
F_173 ( V_2 , & V_166 , & V_167 ) ;
F_157 ( & V_2 -> V_59 -> V_17 -> V_23 ) ;
V_165 = V_2 -> V_59 -> signal ;
V_15 = V_2 -> signal ;
V_165 -> V_168 += V_166 + V_15 -> V_168 ;
V_165 -> V_169 += V_167 + V_15 -> V_169 ;
V_165 -> V_170 += F_18 ( V_2 ) + V_15 -> V_27 + V_15 -> V_170 ;
V_165 -> V_171 +=
V_2 -> V_28 + V_15 -> V_28 + V_15 -> V_171 ;
V_165 -> V_172 +=
V_2 -> V_29 + V_15 -> V_29 + V_15 -> V_172 ;
V_165 -> V_173 +=
V_2 -> V_30 + V_15 -> V_30 + V_15 -> V_173 ;
V_165 -> V_174 +=
V_2 -> V_31 + V_15 -> V_31 + V_15 -> V_174 ;
V_165 -> V_175 +=
F_19 ( V_2 ) +
V_15 -> V_32 + V_15 -> V_175 ;
V_165 -> V_176 +=
F_20 ( V_2 ) +
V_15 -> V_33 + V_15 -> V_176 ;
V_115 = F_174 ( V_15 -> V_115 , V_15 -> V_177 ) ;
if ( V_165 -> V_177 < V_115 )
V_165 -> V_177 = V_115 ;
F_21 ( & V_165 -> V_34 , & V_2 -> V_34 ) ;
F_21 ( & V_165 -> V_34 , & V_15 -> V_34 ) ;
F_159 ( & V_2 -> V_59 -> V_17 -> V_23 ) ;
}
F_55 ( & V_49 ) ;
V_60 = V_137 -> V_149
? F_164 ( V_2 , V_150 , V_137 -> V_149 ) : 0 ;
V_146 = ( V_2 -> signal -> V_62 & V_133 )
? V_2 -> signal -> V_132 : V_2 -> V_116 ;
if ( ! V_60 && V_137 -> V_178 )
V_60 = F_165 ( V_146 , V_137 -> V_178 ) ;
V_148 = V_137 -> V_151 ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_94 , & V_148 -> V_152 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( 0 , & V_148 -> V_153 ) ;
if ( ! V_60 && V_148 ) {
int V_145 ;
if ( ( V_146 & 0x7f ) == 0 ) {
V_145 = V_161 ;
V_146 >>= 8 ;
} else {
V_145 = ( V_146 & 0x80 ) ? V_162 : V_163 ;
V_146 &= 0x7f ;
}
V_60 = F_165 ( ( short ) V_145 , & V_148 -> V_154 ) ;
if ( ! V_60 )
V_60 = F_165 ( V_146 , & V_148 -> V_157 ) ;
}
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_55 , & V_148 -> V_155 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_144 , & V_148 -> V_156 ) ;
if ( ! V_60 )
V_60 = V_55 ;
if ( V_127 == V_164 ) {
F_38 ( & V_49 ) ;
F_175 ( V_2 ) ;
V_127 = V_52 ;
if ( F_41 ( V_2 , V_2 -> V_53 ) )
V_127 = V_54 ;
V_2 -> V_51 = V_127 ;
F_42 ( & V_49 ) ;
}
if ( V_127 == V_54 )
F_32 ( V_2 ) ;
return V_60 ;
}
static int * F_176 ( struct V_1 * V_2 , bool V_95 )
{
if ( V_95 ) {
if ( F_177 ( V_2 ) &&
! ( V_2 -> V_179 & V_180 ) )
return & V_2 -> V_116 ;
} else {
if ( V_2 -> signal -> V_62 & V_63 )
return & V_2 -> signal -> V_132 ;
}
return NULL ;
}
static int F_178 ( struct V_136 * V_137 ,
int V_95 , struct V_1 * V_2 )
{
struct V_147 T_4 * V_148 ;
int V_60 , V_116 , * V_181 , V_145 ;
T_3 V_144 = 0 ;
T_2 V_55 ;
if ( ! V_95 && ! ( V_137 -> V_141 & V_182 ) )
return 0 ;
if ( ! F_176 ( V_2 , V_95 ) )
return 0 ;
V_116 = 0 ;
F_157 ( & V_2 -> V_17 -> V_23 ) ;
V_181 = F_176 ( V_2 , V_95 ) ;
if ( F_13 ( ! V_181 ) )
goto V_183;
V_116 = * V_181 ;
if ( ! V_116 )
goto V_183;
if ( ! F_13 ( V_137 -> V_141 & V_160 ) )
* V_181 = 0 ;
V_144 = F_168 ( F_169 () , F_170 ( V_2 ) ) ;
V_183:
F_159 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! V_116 )
return 0 ;
F_65 ( V_2 ) ;
V_55 = F_167 ( V_2 ) ;
V_145 = V_95 ? V_184 : V_185 ;
F_55 ( & V_49 ) ;
if ( F_13 ( V_137 -> V_141 & V_160 ) )
return F_163 ( V_137 , V_2 , V_55 , V_144 , V_145 , V_116 ) ;
V_60 = V_137 -> V_149
? F_164 ( V_2 , V_150 , V_137 -> V_149 ) : 0 ;
if ( ! V_60 && V_137 -> V_178 )
V_60 = F_165 ( ( V_116 << 8 ) | 0x7f , V_137 -> V_178 ) ;
V_148 = V_137 -> V_151 ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_94 , & V_148 -> V_152 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( 0 , & V_148 -> V_153 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( ( short ) V_145 , & V_148 -> V_154 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_116 , & V_148 -> V_157 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_55 , & V_148 -> V_155 ) ;
if ( ! V_60 && V_148 )
V_60 = F_165 ( V_144 , & V_148 -> V_156 ) ;
if ( ! V_60 )
V_60 = V_55 ;
F_31 ( V_2 ) ;
F_64 ( ! V_60 ) ;
return V_60 ;
}
static int F_179 ( struct V_136 * V_137 , struct V_1 * V_2 )
{
int V_60 ;
T_2 V_55 ;
T_3 V_144 ;
if ( ! F_13 ( V_137 -> V_141 & V_186 ) )
return 0 ;
if ( ! ( V_2 -> signal -> V_62 & V_187 ) )
return 0 ;
F_157 ( & V_2 -> V_17 -> V_23 ) ;
if ( ! ( V_2 -> signal -> V_62 & V_187 ) ) {
F_159 ( & V_2 -> V_17 -> V_23 ) ;
return 0 ;
}
if ( ! F_13 ( V_137 -> V_141 & V_160 ) )
V_2 -> signal -> V_62 &= ~ V_187 ;
V_144 = F_168 ( F_169 () , F_170 ( V_2 ) ) ;
F_159 ( & V_2 -> V_17 -> V_23 ) ;
V_55 = F_167 ( V_2 ) ;
F_65 ( V_2 ) ;
F_55 ( & V_49 ) ;
if ( ! V_137 -> V_151 ) {
V_60 = V_137 -> V_149
? F_164 ( V_2 , V_150 , V_137 -> V_149 ) : 0 ;
F_31 ( V_2 ) ;
if ( ! V_60 && V_137 -> V_178 )
V_60 = F_165 ( 0xffff , V_137 -> V_178 ) ;
if ( ! V_60 )
V_60 = V_55 ;
} else {
V_60 = F_163 ( V_137 , V_2 , V_55 , V_144 ,
V_188 , V_67 ) ;
F_64 ( V_60 == 0 ) ;
}
return V_60 ;
}
static int F_180 ( struct V_136 * V_137 , int V_95 ,
struct V_1 * V_2 )
{
int V_189 ;
if ( F_13 ( V_2 -> V_51 == V_54 ) )
return 0 ;
V_189 = F_162 ( V_137 , V_2 ) ;
if ( ! V_189 )
return V_189 ;
V_189 = F_181 ( V_2 ) ;
if ( F_13 ( V_189 < 0 ) ) {
if ( V_137 -> V_190 )
V_137 -> V_190 = V_189 ;
return 0 ;
}
if ( F_13 ( V_2 -> V_51 == V_164 ) ) {
if ( F_171 ( ! V_95 ) )
V_137 -> V_190 = 0 ;
return 0 ;
}
if ( F_171 ( ! V_95 ) && F_13 ( V_2 -> V_95 ) ) {
if ( ! F_93 ( V_2 ) )
V_95 = 1 ;
}
if ( V_2 -> V_51 == V_52 ) {
if ( ! F_182 ( V_2 ) ) {
if ( F_13 ( V_95 ) || F_171 ( ! V_2 -> V_95 ) )
return F_166 ( V_137 , V_2 ) ;
}
if ( F_171 ( ! V_95 ) || ( V_137 -> V_141 & ( V_186 | V_159 ) ) )
V_137 -> V_190 = 0 ;
} else {
V_137 -> V_190 = 0 ;
}
V_189 = F_178 ( V_137 , V_95 , V_2 ) ;
if ( V_189 )
return V_189 ;
return F_179 ( V_137 , V_2 ) ;
}
static int F_183 ( struct V_136 * V_137 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_61 (p, &tsk->children, sibling) {
int V_189 = F_180 ( V_137 , 0 , V_2 ) ;
if ( V_189 )
return V_189 ;
}
return 0 ;
}
static int F_184 ( struct V_136 * V_137 , struct V_1 * V_13 )
{
struct V_1 * V_2 ;
F_61 (p, &tsk->ptraced, ptrace_entry) {
int V_189 = F_180 ( V_137 , 1 , V_2 ) ;
if ( V_189 )
return V_189 ;
}
return 0 ;
}
static int F_185 ( T_5 * V_191 , unsigned V_192 ,
int V_193 , void * V_194 )
{
struct V_136 * V_137 = F_28 ( V_191 , struct V_136 ,
V_195 ) ;
struct V_1 * V_2 = V_194 ;
if ( ! F_161 ( V_137 , V_2 ) )
return 0 ;
if ( ( V_137 -> V_141 & V_196 ) && V_191 -> V_197 != V_2 -> V_64 )
return 0 ;
return F_186 ( V_191 , V_192 , V_193 , V_194 ) ;
}
void F_187 ( struct V_1 * V_2 , struct V_1 * V_64 )
{
F_188 ( & V_64 -> signal -> V_198 ,
V_199 , 1 , V_2 ) ;
}
static long F_189 ( struct V_136 * V_137 )
{
struct V_1 * V_13 ;
int V_60 ;
F_190 ( V_137 -> V_140 ) ;
F_191 ( & V_137 -> V_195 , F_185 ) ;
V_137 -> V_195 . V_197 = V_61 ;
F_192 ( & V_61 -> signal -> V_198 , & V_137 -> V_195 ) ;
V_46:
V_137 -> V_190 = - V_200 ;
if ( ( V_137 -> V_138 < V_139 ) &&
( ! V_137 -> V_140 || F_193 ( & V_137 -> V_140 -> V_8 [ V_137 -> V_138 ] ) ) )
goto V_201;
F_109 ( V_199 ) ;
F_54 ( & V_49 ) ;
V_13 = V_61 ;
do {
V_60 = F_183 ( V_137 , V_13 ) ;
if ( V_60 )
goto V_202;
V_60 = F_184 ( V_137 , V_13 ) ;
if ( V_60 )
goto V_202;
if ( V_137 -> V_141 & V_196 )
break;
} while_each_thread(current, tsk) ;
