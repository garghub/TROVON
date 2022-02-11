static unsigned int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( & V_4 -> V_6 , sizeof( V_7 ) , 0 ) ;
V_5 = F_2 ( & V_4 -> V_8 , sizeof( unsigned int ) , V_5 ) ;
V_5 = F_2 ( & V_2 , sizeof( struct V_1 * ) , V_5 ) ;
V_5 &= V_9 ;
return V_5 ;
}
static inline void F_3 ( unsigned int V_10 )
{
F_4 ( & V_11 [ V_10 ] ) ;
}
static inline void F_5 ( unsigned int V_10 )
{
F_6 ( & V_11 [ V_10 ] ) ;
}
static void F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 , struct V_14 , V_16 ) ;
if ( V_15 -> V_17 -> V_18 & V_19 ) {
F_9 ( V_20 , V_15 ) ;
} else {
F_10 ( V_15 -> V_21 . V_22 ) ;
F_9 ( V_23 , V_15 ) ;
}
}
void F_11 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_24 ;
F_12 ( & V_15 -> V_16 , F_7 ) ;
if ( F_13 ( & V_2 -> V_25 ) )
F_14 ( & V_2 -> V_26 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
F_16 ( V_15 , F_17 ( & V_15 -> V_27 ) ) ;
F_18 ( & V_15 -> V_27 ) ;
}
static int F_19 ( const struct V_14 * V_15 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
if ( V_15 -> V_30 == V_31 )
return 0 ;
if ( ! F_20 ( & V_15 -> V_32 ) )
return 0 ;
if ( V_29 -> V_33 )
return V_29 -> V_33 ( V_15 ) ;
return 1 ;
}
void F_21 ( struct V_14 * V_15 )
{
F_22 ( & V_34 ) ;
if ( ! F_20 ( & V_15 -> V_35 ) )
F_23 ( & V_15 -> V_35 ) ;
else
F_24 ( & V_36 ) ;
F_25 ( & V_15 -> V_35 , & V_37 ) ;
F_26 ( V_38 , & V_15 -> V_39 ) ;
F_27 ( & V_34 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
if ( ! F_20 ( & V_15 -> V_35 ) ) {
F_23 ( & V_15 -> V_35 ) ;
F_29 ( & V_36 ) ;
F_30 ( V_38 , & V_15 -> V_39 ) ;
}
}
static void F_31 ( struct V_14 * V_15 )
{
F_22 ( & V_34 ) ;
F_28 ( V_15 ) ;
F_27 ( & V_34 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
if ( F_34 ( & V_15 -> V_27 ) )
return;
F_35 ( & V_15 -> V_27 ) ;
F_22 ( & V_34 ) ;
F_28 ( V_15 ) ;
F_27 ( & V_34 ) ;
F_27 ( & V_15 -> V_27 . V_42 ) ;
F_3 ( V_15 -> F_1 ) ;
F_36 ( & V_15 -> V_43 ) ;
F_5 ( V_15 -> F_1 ) ;
F_16 ( V_15 , ! F_20 ( & V_15 -> V_32 ) ) ;
F_16 ( V_15 , V_41 && V_41 -> V_44 ) ;
F_37 ( V_15 ) ;
V_2 -> V_45 . V_46 -> V_47 ( V_15 ) ;
}
static struct V_14 * F_38 ( unsigned int V_10 ,
const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_48 * V_5 ;
F_39 (gl, h, &gl_hash_table[hash], gl_list) {
if ( ! F_40 ( & V_15 -> V_49 , V_4 ) )
continue;
if ( V_15 -> V_24 != V_2 )
continue;
if ( F_41 ( & V_15 -> V_27 ) )
return V_15 ;
}
return NULL ;
}
static inline int F_42 ( const struct V_14 * V_15 , const struct V_50 * V_51 )
{
const struct V_50 * V_52 = F_43 ( V_15 -> V_32 . V_53 , const struct V_50 , V_54 ) ;
if ( ( V_51 -> V_55 == V_56 ||
V_52 -> V_55 == V_56 ) && V_51 != V_52 )
return 0 ;
if ( V_15 -> V_30 == V_51 -> V_55 )
return 1 ;
if ( V_51 -> V_57 & V_58 )
return 0 ;
if ( V_15 -> V_30 == V_56 ) {
if ( V_51 -> V_55 == V_59 && V_52 -> V_55 == V_59 )
return 1 ;
if ( V_51 -> V_55 == V_60 && V_52 -> V_55 == V_60 )
return 1 ;
}
if ( V_15 -> V_30 != V_31 && ( V_51 -> V_57 & V_61 ) )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_50 * V_51 )
{
F_30 ( V_62 , & V_51 -> V_63 ) ;
F_45 () ;
F_46 ( & V_51 -> V_63 , V_62 ) ;
}
static inline void F_47 ( struct V_14 * V_15 , const int V_64 )
{
struct V_50 * V_51 , * V_65 ;
F_48 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_49 ( V_66 , & V_51 -> V_63 ) )
continue;
if ( V_64 & V_67 )
V_51 -> V_68 = - V_69 ;
else if ( V_51 -> V_57 & ( V_70 | V_71 ) )
V_51 -> V_68 = V_72 ;
else
continue;
F_23 ( & V_51 -> V_54 ) ;
F_50 ( V_51 , 0 ) ;
F_44 ( V_51 ) ;
}
}
static int F_51 ( struct V_14 * V_15 )
__releases( &gl->gl_spin
static inline struct V_50 * F_52 ( const struct V_14 * V_15 )
{
struct V_50 * V_51 ;
F_53 (gh, &gl->gl_holders, gh_list) {
if ( ! F_49 ( V_66 , & V_51 -> V_63 ) )
return V_51 ;
}
return NULL ;
}
static void F_54 ( struct V_14 * V_15 , unsigned int V_73 )
{
int V_74 , V_75 ;
V_74 = ( V_15 -> V_30 != V_31 ) ;
V_75 = ( V_73 != V_31 ) ;
if ( V_74 != V_75 ) {
F_16 ( V_15 , F_17 ( & V_15 -> V_27 ) ) ;
if ( V_75 )
V_15 -> V_27 . V_76 ++ ;
else
V_15 -> V_27 . V_76 -- ;
}
if ( V_74 && V_75 && F_20 ( & V_15 -> V_32 ) )
F_30 ( V_77 , & V_15 -> V_39 ) ;
if ( V_73 != V_15 -> V_78 )
V_15 -> V_79 = F_55 ( V_15 -> V_79 - V_80 ,
V_81 ) ;
V_15 -> V_30 = V_73 ;
V_15 -> V_82 = V_83 ;
}
static void F_56 ( struct V_14 * V_15 )
{
V_15 -> V_84 = V_56 ;
F_30 ( V_85 , & V_15 -> V_39 ) ;
F_45 () ;
F_46 ( & V_15 -> V_39 , V_85 ) ;
}
static void F_57 ( struct V_14 * V_15 , unsigned int V_64 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
struct V_50 * V_51 ;
unsigned V_86 = V_64 & V_87 ;
int V_88 ;
F_22 ( & V_15 -> V_89 ) ;
F_58 ( V_15 , V_86 ) ;
F_54 ( V_15 , V_86 ) ;
V_51 = F_52 ( V_15 ) ;
if ( F_49 ( V_90 , & V_15 -> V_39 ) &&
V_86 != V_31 && V_15 -> V_84 == V_31 )
V_15 -> V_78 = V_31 ;
if ( F_59 ( V_86 != V_15 -> V_78 ) ) {
if ( V_51 && ! F_49 ( V_90 , & V_15 -> V_39 ) ) {
if ( V_64 & V_91 ) {
if ( ( V_51 -> V_57 & V_92 ) == 0 )
F_60 ( & V_51 -> V_54 , & V_15 -> V_32 ) ;
V_51 = F_52 ( V_15 ) ;
V_15 -> V_78 = V_51 -> V_55 ;
goto V_93;
}
if ( ( V_64 & V_67 ) ||
( V_51 -> V_57 & ( V_70 | V_71 ) ) ) {
V_15 -> V_78 = V_15 -> V_30 ;
F_47 ( V_15 , V_64 ) ;
goto V_94;
}
}
switch( V_86 ) {
case V_31 :
V_93:
F_61 ( V_15 , V_51 , V_15 -> V_78 ) ;
break;
case V_59 :
case V_60 :
F_61 ( V_15 , V_51 , V_31 ) ;
break;
default:
F_62 ( L_1 , V_15 -> V_78 , V_86 ) ;
F_16 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_89 ) ;
return;
}
if ( F_63 ( V_90 , & V_15 -> V_39 ) )
F_56 ( V_15 ) ;
if ( V_86 != V_31 ) {
if ( V_29 -> V_95 ) {
F_27 ( & V_15 -> V_89 ) ;
V_88 = V_29 -> V_95 ( V_15 , V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_88 ) {
F_47 ( V_15 , V_88 ) ;
goto V_94;
}
}
V_88 = F_51 ( V_15 ) ;
if ( V_88 == 2 )
goto V_96;
}
V_94:
F_30 ( V_97 , & V_15 -> V_39 ) ;
V_96:
F_27 ( & V_15 -> V_89 ) ;
}
static void F_61 ( struct V_14 * V_15 , struct V_50 * V_51 , unsigned int V_98 )
__releases( &gl->gl_spin
static inline struct V_50 * F_64 ( const struct V_14 * V_15 )
{
struct V_50 * V_51 ;
if ( ! F_20 ( & V_15 -> V_32 ) ) {
V_51 = F_43 ( V_15 -> V_32 . V_53 , struct V_50 , V_54 ) ;
if ( F_49 ( V_66 , & V_51 -> V_63 ) )
return V_51 ;
}
return NULL ;
}
static void F_65 ( struct V_14 * V_15 , const int V_99 )
__releases( &gl->gl_spin
static void F_66 ( struct V_100 * V_101 )
{
struct V_14 * V_15 = F_8 ( V_101 , struct V_14 , V_102 ) ;
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_103 * V_104 ;
struct V_105 * V_105 ;
V_7 V_106 = V_15 -> V_49 . V_6 ;
V_104 = V_15 -> V_107 ;
if ( V_104 )
V_105 = F_67 ( V_2 -> V_108 , V_106 , 1 ) ;
else
V_105 = F_68 ( V_2 , V_106 , NULL , V_109 ) ;
if ( V_105 && ! F_69 ( V_105 ) ) {
F_70 ( V_105 ) ;
F_71 ( V_105 ) ;
}
F_32 ( V_15 ) ;
}
static void F_72 ( struct V_100 * V_101 )
{
unsigned long V_110 = 0 ;
struct V_14 * V_15 = F_8 ( V_101 , struct V_14 , V_111 . V_101 ) ;
int V_112 = 0 ;
if ( F_63 ( V_113 , & V_15 -> V_39 ) ) {
F_57 ( V_15 , V_15 -> V_114 ) ;
V_112 = 1 ;
}
F_22 ( & V_15 -> V_89 ) ;
if ( F_49 ( V_115 , & V_15 -> V_39 ) &&
V_15 -> V_30 != V_31 &&
V_15 -> V_84 != V_56 ) {
unsigned long V_116 , V_117 = V_83 ;
V_116 = V_15 -> V_82 + V_15 -> V_79 ;
if ( F_73 ( V_117 , V_116 ) )
V_110 = V_116 - V_117 ;
if ( ! V_110 ) {
F_30 ( V_115 , & V_15 -> V_39 ) ;
F_26 ( V_85 , & V_15 -> V_39 ) ;
}
}
F_65 ( V_15 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! V_110 )
F_32 ( V_15 ) ;
else {
if ( V_15 -> V_49 . V_8 != V_118 )
V_110 = 0 ;
if ( F_74 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_32 ( V_15 ) ;
}
if ( V_112 )
F_32 ( V_15 ) ;
}
int F_75 ( struct V_1 * V_2 , V_7 V_120 ,
const struct V_28 * V_29 , int V_121 ,
struct V_14 * * V_122 )
{
struct V_123 * V_124 = V_2 -> V_108 ;
struct V_3 V_4 = { . V_6 = V_120 , . V_8 = V_29 -> V_125 } ;
struct V_14 * V_15 , * V_65 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_40 * V_41 ;
struct V_126 * V_127 ;
F_76 () ;
V_15 = F_38 ( V_10 , V_2 , & V_4 ) ;
F_77 () ;
* V_122 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_121 )
return - V_128 ;
if ( V_29 -> V_18 & V_19 )
V_127 = V_20 ;
else
V_127 = V_23 ;
V_15 = F_78 ( V_127 , V_129 ) ;
if ( ! V_15 )
return - V_130 ;
memset ( & V_15 -> V_21 , 0 , sizeof( struct V_131 ) ) ;
if ( V_29 -> V_18 & V_132 ) {
V_15 -> V_21 . V_22 = F_79 ( V_133 , V_129 ) ;
if ( ! V_15 -> V_21 . V_22 ) {
F_9 ( V_127 , V_15 ) ;
return - V_130 ;
}
}
F_24 ( & V_2 -> V_25 ) ;
V_15 -> V_24 = V_2 ;
V_15 -> V_39 = 0 ;
V_15 -> V_49 = V_4 ;
V_15 -> V_27 . V_76 = 1 ;
V_15 -> V_30 = V_31 ;
V_15 -> V_78 = V_31 ;
V_15 -> V_84 = V_56 ;
V_15 -> F_1 = V_10 ;
V_15 -> V_17 = V_29 ;
V_15 -> V_134 = F_80 ( 0 , 0 ) ;
F_81 () ;
V_15 -> V_135 = F_82 ( V_2 -> V_136 ) -> V_137 [ V_29 -> V_125 ] ;
F_83 () ;
V_15 -> V_135 . V_138 [ V_139 ] = 0 ;
V_15 -> V_135 . V_138 [ V_140 ] = 0 ;
V_15 -> V_82 = V_83 ;
V_15 -> V_107 = NULL ;
V_15 -> V_79 = V_141 ;
F_84 ( & V_15 -> V_111 , F_72 ) ;
F_85 ( & V_15 -> V_102 , F_66 ) ;
V_41 = F_33 ( V_15 ) ;
if ( V_41 ) {
V_41 -> V_142 = & V_143 ;
V_41 -> V_144 = V_124 -> V_145 -> V_146 ;
V_41 -> V_147 = 0 ;
F_86 ( V_41 , V_129 ) ;
V_41 -> V_148 = NULL ;
V_41 -> V_149 = V_124 -> V_150 ;
V_41 -> V_151 = 0 ;
}
F_3 ( V_10 ) ;
V_65 = F_38 ( V_10 , V_2 , & V_4 ) ;
if ( V_65 ) {
F_5 ( V_10 ) ;
F_10 ( V_15 -> V_21 . V_22 ) ;
F_9 ( V_127 , V_15 ) ;
F_29 ( & V_2 -> V_25 ) ;
V_15 = V_65 ;
} else {
F_87 ( & V_15 -> V_43 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_122 = V_15 ;
return 0 ;
}
void F_88 ( struct V_14 * V_15 , unsigned int V_86 , unsigned V_147 ,
struct V_50 * V_51 )
{
F_89 ( & V_51 -> V_54 ) ;
V_51 -> V_152 = V_15 ;
V_51 -> V_153 = ( unsigned long ) F_90 ( 0 ) ;
V_51 -> V_154 = F_91 ( F_92 ( V_155 ) ) ;
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_147 ;
V_51 -> V_68 = 0 ;
V_51 -> V_63 = 0 ;
F_15 ( V_15 ) ;
}
void F_93 ( unsigned int V_86 , unsigned V_147 , struct V_50 * V_51 )
{
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_147 ;
V_51 -> V_63 = 0 ;
V_51 -> V_153 = ( unsigned long ) F_90 ( 0 ) ;
if ( V_51 -> V_154 )
F_94 ( V_51 -> V_154 ) ;
V_51 -> V_154 = F_91 ( F_92 ( V_155 ) ) ;
}
void F_95 ( struct V_50 * V_51 )
{
F_94 ( V_51 -> V_154 ) ;
F_32 ( V_51 -> V_152 ) ;
V_51 -> V_152 = NULL ;
V_51 -> V_153 = 0 ;
}
int F_96 ( struct V_50 * V_51 )
{
unsigned long V_156 = V_83 ;
F_97 () ;
F_98 ( & V_51 -> V_63 , V_62 , V_157 ) ;
if ( F_99 ( V_83 , V_156 + V_158 ) )
V_51 -> V_152 -> V_79 = F_100 ( V_51 -> V_152 -> V_79 +
V_159 ,
V_160 ) ;
return V_51 -> V_68 ;
}
static void F_101 ( struct V_14 * V_15 , unsigned int V_86 ,
unsigned long V_110 , bool V_161 )
{
int V_162 = V_110 ? V_115 : V_85 ;
F_26 ( V_162 , & V_15 -> V_39 ) ;
if ( V_15 -> V_84 == V_56 ) {
V_15 -> V_84 = V_86 ;
V_15 -> V_163 = V_83 ;
} else if ( V_15 -> V_84 != V_31 &&
V_15 -> V_84 != V_86 ) {
V_15 -> V_84 = V_31 ;
}
if ( V_15 -> V_17 -> V_164 )
V_15 -> V_17 -> V_164 ( V_15 , V_161 ) ;
F_102 ( V_15 , V_161 ) ;
}
void F_103 ( struct V_165 * V_166 , const char * V_167 , ... )
{
struct V_168 V_169 ;
T_1 args ;
va_start ( args , V_167 ) ;
if ( V_166 ) {
F_104 ( V_166 , V_167 , args ) ;
} else {
V_169 . V_167 = V_167 ;
V_169 . V_170 = & args ;
F_62 ( L_2 , & V_169 ) ;
}
va_end ( args ) ;
}
static inline void F_105 ( struct V_50 * V_51 )
__releases( &gl->gl_spin
int F_106 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_152 ;
struct V_1 * V_2 = V_15 -> V_24 ;
int error = 0 ;
if ( F_59 ( F_49 ( V_171 , & V_2 -> V_172 ) ) )
return - V_69 ;
if ( F_49 ( V_38 , & V_15 -> V_39 ) )
F_31 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_105 ( V_51 ) ;
if ( F_59 ( ( V_173 & V_51 -> V_57 ) &&
F_63 ( V_174 , & V_15 -> V_39 ) ) ) {
F_26 ( V_113 , & V_15 -> V_39 ) ;
V_15 -> V_27 . V_76 ++ ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
V_15 -> V_27 . V_76 -- ;
}
F_65 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! ( V_51 -> V_57 & V_175 ) )
error = F_96 ( V_51 ) ;
return error ;
}
int F_107 ( struct V_50 * V_51 )
{
return F_49 ( V_62 , & V_51 -> V_63 ) ? 0 : 1 ;
}
void F_108 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_152 ;
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned V_110 = 0 ;
int V_176 = 0 ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_51 -> V_57 & V_177 )
F_101 ( V_15 , V_31 , 0 , false ) ;
F_23 ( & V_51 -> V_54 ) ;
if ( F_64 ( V_15 ) == NULL ) {
if ( V_29 -> V_178 ) {
F_16 ( V_15 , F_109 ( V_97 , & V_15 -> V_39 ) ) ;
F_27 ( & V_15 -> V_89 ) ;
V_29 -> V_178 ( V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_97 , & V_15 -> V_39 ) ;
}
if ( F_20 ( & V_15 -> V_32 ) &&
! F_49 ( V_115 , & V_15 -> V_39 ) &&
! F_49 ( V_85 , & V_15 -> V_39 ) )
V_176 = 1 ;
}
if ( ! F_49 ( V_179 , & V_15 -> V_39 ) && F_19 ( V_15 ) )
F_21 ( V_15 ) ;
F_50 ( V_51 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_110 ( V_176 ) )
return;
F_15 ( V_15 ) ;
if ( F_49 ( V_115 , & V_15 -> V_39 ) &&
! F_49 ( V_85 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_118 )
V_110 = V_15 -> V_79 ;
if ( F_74 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_32 ( V_15 ) ;
}
void F_111 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_152 ;
F_108 ( V_51 ) ;
F_97 () ;
F_98 ( & V_15 -> V_39 , V_85 , V_157 ) ;
}
void F_112 ( struct V_50 * V_51 )
{
F_108 ( V_51 ) ;
F_95 ( V_51 ) ;
}
int F_113 ( struct V_1 * V_2 , V_7 V_120 ,
const struct V_28 * V_29 ,
unsigned int V_86 , int V_147 , struct V_50 * V_51 )
{
struct V_14 * V_15 ;
int error ;
error = F_75 ( V_2 , V_120 , V_29 , V_180 , & V_15 ) ;
if ( ! error ) {
error = F_114 ( V_15 , V_86 , V_147 , V_51 ) ;
F_32 ( V_15 ) ;
}
return error ;
}
static int F_115 ( const void * V_181 , const void * V_182 )
{
const struct V_50 * V_183 = * ( const struct V_50 * * ) V_181 ;
const struct V_50 * V_184 = * ( const struct V_50 * * ) V_182 ;
const struct V_3 * V_185 = & V_183 -> V_152 -> V_49 ;
const struct V_3 * V_186 = & V_184 -> V_152 -> V_49 ;
if ( V_185 -> V_6 > V_186 -> V_6 )
return 1 ;
if ( V_185 -> V_6 < V_186 -> V_6 )
return - 1 ;
F_116 ( V_183 -> V_152 -> V_17 -> V_125 == V_184 -> V_152 -> V_17 -> V_125 ) ;
return 0 ;
}
static int F_117 ( unsigned int V_187 , struct V_50 * V_188 ,
struct V_50 * * V_189 )
{
unsigned int V_190 ;
int error = 0 ;
for ( V_190 = 0 ; V_190 < V_187 ; V_190 ++ )
V_189 [ V_190 ] = & V_188 [ V_190 ] ;
F_118 ( V_189 , V_187 , sizeof( struct V_50 * ) , F_115 , NULL ) ;
for ( V_190 = 0 ; V_190 < V_187 ; V_190 ++ ) {
V_189 [ V_190 ] -> V_57 &= ~ ( V_70 | V_175 ) ;
error = F_106 ( V_189 [ V_190 ] ) ;
if ( error ) {
while ( V_190 -- )
F_108 ( V_189 [ V_190 ] ) ;
break;
}
}
return error ;
}
int F_119 ( unsigned int V_187 , struct V_50 * V_188 )
{
struct V_50 * V_65 [ 4 ] ;
struct V_50 * * V_191 = V_65 ;
int error = 0 ;
switch( V_187 ) {
case 0 :
return 0 ;
case 1 :
V_188 -> V_57 &= ~ ( V_70 | V_175 ) ;
return F_106 ( V_188 ) ;
default:
if ( V_187 <= 4 )
break;
V_191 = F_120 ( V_187 * sizeof( struct V_50 * ) , V_129 ) ;
if ( ! V_191 )
return - V_130 ;
}
error = F_117 ( V_187 , V_188 , V_191 ) ;
if ( V_191 != V_65 )
F_10 ( V_191 ) ;
return error ;
}
void F_121 ( unsigned int V_187 , struct V_50 * V_188 )
{
while ( V_187 -- )
F_108 ( & V_188 [ V_187 ] ) ;
}
void F_122 ( struct V_14 * V_15 , unsigned int V_86 )
{
unsigned long V_110 = 0 ;
unsigned long V_116 ;
unsigned long V_117 = V_83 ;
F_15 ( V_15 ) ;
V_116 = V_15 -> V_82 + V_15 -> V_79 ;
if ( F_49 ( V_77 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_118 ) {
if ( F_73 ( V_117 , V_116 ) )
V_110 = V_116 - V_117 ;
if ( F_49 ( V_113 , & V_15 -> V_39 ) )
V_110 = V_15 -> V_79 ;
}
F_22 ( & V_15 -> V_89 ) ;
F_101 ( V_15 , V_86 , V_110 , true ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_123 ( const struct V_14 * V_15 )
{
const struct V_50 * V_51 ;
if ( V_15 -> V_114 & ~ V_87 )
return 0 ;
if ( V_15 -> V_78 == V_31 )
return 0 ;
F_53 (gh, &gl->gl_holders, gh_list) {
if ( F_49 ( V_66 , & V_51 -> V_63 ) )
continue;
if ( V_173 & V_51 -> V_57 )
return 0 ;
}
return 1 ;
}
void F_124 ( struct V_14 * V_15 , int V_64 )
{
struct V_192 * V_193 = & V_15 -> V_24 -> V_45 ;
F_22 ( & V_15 -> V_89 ) ;
V_15 -> V_114 = V_64 ;
if ( F_59 ( F_49 ( V_194 , & V_193 -> V_195 ) ) ) {
if ( F_123 ( V_15 ) ) {
F_26 ( V_174 , & V_15 -> V_39 ) ;
F_27 ( & V_15 -> V_89 ) ;
return;
}
}
V_15 -> V_27 . V_76 ++ ;
F_26 ( V_113 , & V_15 -> V_39 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_125 ( void * V_196 , struct V_197 * V_185 , struct V_197 * V_186 )
{
struct V_14 * V_198 , * V_199 ;
V_198 = F_43 ( V_185 , struct V_14 , V_35 ) ;
V_199 = F_43 ( V_186 , struct V_14 , V_35 ) ;
if ( V_198 -> V_49 . V_6 > V_199 -> V_49 . V_6 )
return 1 ;
if ( V_198 -> V_49 . V_6 < V_199 -> V_49 . V_6 )
return - 1 ;
return 0 ;
}
static void F_126 ( struct V_197 * V_200 )
__releases( &lru_lock
static long F_127 ( int V_201 )
{
struct V_14 * V_15 ;
F_128 ( V_202 ) ;
F_128 ( V_203 ) ;
long V_204 = 0 ;
F_22 ( & V_34 ) ;
while ( ( V_201 -- >= 0 ) && ! F_20 ( & V_37 ) ) {
V_15 = F_43 ( V_37 . V_53 , struct V_14 , V_35 ) ;
if ( ! F_49 ( V_97 , & V_15 -> V_39 ) ) {
F_129 ( & V_15 -> V_35 , & V_203 ) ;
F_29 ( & V_36 ) ;
V_204 ++ ;
continue;
}
F_129 ( & V_15 -> V_35 , & V_202 ) ;
}
F_130 ( & V_202 , & V_37 ) ;
if ( ! F_20 ( & V_203 ) )
F_126 ( & V_203 ) ;
F_27 ( & V_34 ) ;
return V_204 ;
}
static unsigned long F_131 ( struct V_205 * V_206 ,
struct V_207 * V_208 )
{
if ( ! ( V_208 -> V_209 & V_210 ) )
return V_211 ;
return F_127 ( V_208 -> V_212 ) ;
}
static unsigned long F_132 ( struct V_205 * V_206 ,
struct V_207 * V_208 )
{
return F_133 ( F_134 ( & V_36 ) ) ;
}
static void F_135 ( T_2 V_213 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_214 * V_215 = & V_11 [ V_10 ] ;
struct V_48 * V_216 ;
F_76 () ;
F_39 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_24 == V_2 ) && F_41 ( & V_15 -> V_27 ) )
V_213 ( V_15 ) ;
}
F_77 () ;
F_136 () ;
}
static void F_137 ( T_2 V_213 , const struct V_1 * V_2 )
{
unsigned V_190 ;
for ( V_190 = 0 ; V_190 < V_217 ; V_190 ++ )
F_135 ( V_213 , V_2 , V_190 ) ;
}
static void F_138 ( struct V_14 * V_15 )
{
if ( ! F_63 ( V_174 , & V_15 -> V_39 ) )
goto V_94;
F_26 ( V_113 , & V_15 -> V_39 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 ) {
V_94:
F_32 ( V_15 ) ;
}
}
static void F_139 ( struct V_14 * V_15 )
{
F_31 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_15 -> V_30 != V_31 )
F_101 ( V_15 , V_31 , 0 , false ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
void F_140 ( struct V_1 * V_2 )
{
F_137 ( F_138 , V_2 ) ;
}
static void F_141 ( struct V_165 * V_166 , struct V_14 * V_15 )
{
F_22 ( & V_15 -> V_89 ) ;
F_142 ( V_166 , V_15 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static void F_143 ( struct V_14 * V_15 )
{
F_141 ( NULL , V_15 ) ;
}
void F_144 ( struct V_1 * V_2 )
{
F_26 ( V_218 , & V_2 -> V_172 ) ;
F_145 ( V_119 ) ;
F_137 ( F_139 , V_2 ) ;
F_145 ( V_119 ) ;
F_146 ( V_2 -> V_26 , F_134 ( & V_2 -> V_25 ) == 0 ) ;
F_137 ( F_143 , V_2 ) ;
}
void F_147 ( struct V_103 * V_104 )
{
struct V_14 * V_15 = V_104 -> V_219 ;
int V_64 ;
V_64 = F_148 ( V_104 ) ;
F_149 ( V_15 -> V_24 , V_64 == 0 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_97 , & V_15 -> V_39 ) ;
F_65 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static const char * F_150 ( unsigned V_86 )
{
switch( V_86 ) {
case V_31 :
return L_3 ;
case V_59 :
return L_4 ;
case V_60 :
return L_5 ;
case V_56 :
return L_6 ;
}
return L_7 ;
}
static const char * F_151 ( char * V_220 , unsigned V_147 , unsigned long V_221 )
{
char * V_189 = V_220 ;
if ( V_147 & V_70 )
* V_189 ++ = 't' ;
if ( V_147 & V_71 )
* V_189 ++ = 'T' ;
if ( V_147 & V_173 )
* V_189 ++ = 'e' ;
if ( V_147 & V_61 )
* V_189 ++ = 'A' ;
if ( V_147 & V_92 )
* V_189 ++ = 'p' ;
if ( V_147 & V_175 )
* V_189 ++ = 'a' ;
if ( V_147 & V_58 )
* V_189 ++ = 'E' ;
if ( V_147 & V_177 )
* V_189 ++ = 'c' ;
if ( F_49 ( V_66 , & V_221 ) )
* V_189 ++ = 'H' ;
if ( F_49 ( V_62 , & V_221 ) )
* V_189 ++ = 'W' ;
if ( F_49 ( V_222 , & V_221 ) )
* V_189 ++ = 'F' ;
* V_189 = 0 ;
return V_220 ;
}
static void F_152 ( struct V_165 * V_166 , const struct V_50 * V_51 )
{
struct V_223 * V_224 = NULL ;
char V_225 [ 32 ] ;
F_76 () ;
if ( V_51 -> V_154 )
V_224 = F_153 ( V_51 -> V_154 , V_226 ) ;
F_103 ( V_166 , L_8 ,
F_150 ( V_51 -> V_55 ) ,
F_151 ( V_225 , V_51 -> V_57 , V_51 -> V_63 ) ,
V_51 -> V_68 ,
V_51 -> V_154 ? ( long ) F_154 ( V_51 -> V_154 ) : - 1 ,
V_224 ? V_224 -> V_227 : L_9 ,
( void * ) V_51 -> V_153 ) ;
F_77 () ;
}
static const char * F_155 ( char * V_220 , const struct V_14 * V_15 )
{
const unsigned long * V_228 = & V_15 -> V_39 ;
char * V_189 = V_220 ;
if ( F_49 ( V_97 , V_228 ) )
* V_189 ++ = 'l' ;
if ( F_49 ( V_85 , V_228 ) )
* V_189 ++ = 'D' ;
if ( F_49 ( V_115 , V_228 ) )
* V_189 ++ = 'd' ;
if ( F_49 ( V_90 , V_228 ) )
* V_189 ++ = 'p' ;
if ( F_49 ( V_229 , V_228 ) )
* V_189 ++ = 'y' ;
if ( F_49 ( V_179 , V_228 ) )
* V_189 ++ = 'f' ;
if ( F_49 ( V_230 , V_228 ) )
* V_189 ++ = 'i' ;
if ( F_49 ( V_113 , V_228 ) )
* V_189 ++ = 'r' ;
if ( F_49 ( V_231 , V_228 ) )
* V_189 ++ = 'I' ;
if ( F_49 ( V_174 , V_228 ) )
* V_189 ++ = 'F' ;
if ( F_49 ( V_77 , V_228 ) )
* V_189 ++ = 'q' ;
if ( F_49 ( V_38 , V_228 ) )
* V_189 ++ = 'L' ;
if ( V_15 -> V_107 )
* V_189 ++ = 'o' ;
if ( F_49 ( V_232 , V_228 ) )
* V_189 ++ = 'b' ;
* V_189 = 0 ;
return V_220 ;
}
void F_142 ( struct V_165 * V_166 , const struct V_14 * V_15 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned long long V_233 ;
const struct V_50 * V_51 ;
char V_234 [ 32 ] ;
V_233 = V_83 - V_15 -> V_163 ;
V_233 *= 1000000 / V_158 ;
if ( ! F_49 ( V_85 , & V_15 -> V_39 ) )
V_233 = 0 ;
F_103 ( V_166 , L_10 ,
F_150 ( V_15 -> V_30 ) ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
F_155 ( V_234 , V_15 ) ,
F_150 ( V_15 -> V_78 ) ,
F_150 ( V_15 -> V_84 ) , V_233 ,
F_134 ( & V_15 -> V_235 ) ,
F_134 ( & V_15 -> V_236 ) ,
( int ) V_15 -> V_27 . V_76 , V_15 -> V_79 ) ;
F_53 (gh, &gl->gl_holders, gh_list)
F_152 ( V_166 , V_51 ) ;
if ( V_15 -> V_30 != V_31 && V_29 -> V_237 )
V_29 -> V_237 ( V_166 , V_15 ) ;
}
static int F_156 ( struct V_165 * V_166 , void * V_238 )
{
struct V_14 * V_15 = V_238 ;
F_157 ( V_166 , L_11 ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
( long long ) V_15 -> V_135 . V_138 [ V_239 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_240 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_241 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_242 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_243 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_244 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_139 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_140 ] ) ;
return 0 ;
}
static int F_158 ( struct V_165 * V_166 , void * V_238 )
{
struct V_245 * V_246 = V_166 -> V_247 ;
struct V_1 * V_2 = V_246 -> V_2 ;
unsigned V_248 = V_246 -> V_10 >> 3 ;
unsigned V_249 = V_246 -> V_10 & 0x07 ;
T_3 V_250 ;
int V_251 ;
if ( V_248 == 0 && V_249 != 0 )
return 0 ;
F_157 ( V_166 , L_12 , V_252 [ V_248 ] ,
( V_248 == 0 ) ? L_13 : V_253 [ V_249 ] ) ;
F_159 (i) {
const struct V_254 * V_137 = F_160 ( V_2 -> V_136 , V_251 ) ;
if ( V_248 == 0 ) {
V_250 = V_251 ;
} else {
V_250 = V_137 -> V_137 [ V_248 - 1 ] . V_138 [ V_249 ] ;
}
F_157 ( V_166 , L_14 , ( long long ) V_250 ) ;
}
F_161 ( V_166 , '\n' ) ;
return 0 ;
}
int T_4 F_162 ( void )
{
unsigned V_251 ;
for( V_251 = 0 ; V_251 < V_217 ; V_251 ++ ) {
F_163 ( & V_11 [ V_251 ] ) ;
}
V_119 = F_164 ( L_15 , V_255 |
V_256 | V_257 , 0 ) ;
if ( ! V_119 )
return - V_130 ;
V_258 = F_164 ( L_16 ,
V_255 | V_257 ,
0 ) ;
if ( ! V_258 ) {
F_165 ( V_119 ) ;
return - V_130 ;
}
F_166 ( & V_259 ) ;
return 0 ;
}
void F_167 ( void )
{
F_168 ( & V_259 ) ;
F_165 ( V_119 ) ;
F_165 ( V_258 ) ;
}
static inline struct V_14 * F_169 ( unsigned V_10 )
{
return F_170 ( F_171 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_43 ) ;
}
static inline struct V_14 * F_172 ( struct V_14 * V_15 )
{
return F_170 ( F_173 ( V_15 -> V_43 . V_53 ) ,
struct V_14 , V_43 ) ;
}
static int F_174 ( struct V_245 * V_246 )
{
struct V_14 * V_15 ;
do {
V_15 = V_246 -> V_15 ;
if ( V_15 ) {
V_246 -> V_15 = F_172 ( V_15 ) ;
V_246 -> V_260 ++ ;
} else {
if ( V_246 -> V_10 >= V_217 ) {
F_77 () ;
return 1 ;
}
V_246 -> V_15 = F_169 ( V_246 -> V_10 ) ;
V_246 -> V_260 = 0 ;
}
while ( V_246 -> V_15 == NULL ) {
V_246 -> V_10 ++ ;
if ( V_246 -> V_10 >= V_217 ) {
F_77 () ;
return 1 ;
}
V_246 -> V_15 = F_169 ( V_246 -> V_10 ) ;
V_246 -> V_260 = 0 ;
}
} while ( V_246 -> V_2 != V_246 -> V_15 -> V_24 ||
F_17 ( & V_246 -> V_15 -> V_27 ) );
return 0 ;
}
static void * F_175 ( struct V_165 * V_166 , T_5 * V_216 )
{
struct V_245 * V_246 = V_166 -> V_247 ;
T_5 V_261 = * V_216 ;
if ( V_246 -> V_262 <= * V_216 )
V_261 = V_246 -> V_260 + ( * V_216 - V_246 -> V_262 ) ;
else
V_246 -> V_10 = 0 ;
V_246 -> V_260 = 0 ;
F_76 () ;
do {
if ( F_174 ( V_246 ) )
return NULL ;
} while ( V_261 -- );
V_246 -> V_262 = * V_216 ;
return V_246 -> V_15 ;
}
static void * F_176 ( struct V_165 * V_166 , void * V_238 ,
T_5 * V_216 )
{
struct V_245 * V_246 = V_166 -> V_247 ;
( * V_216 ) ++ ;
V_246 -> V_262 = * V_216 ;
if ( F_174 ( V_246 ) )
return NULL ;
return V_246 -> V_15 ;
}
static void F_177 ( struct V_165 * V_166 , void * V_238 )
{
struct V_245 * V_246 = V_166 -> V_247 ;
if ( V_246 -> V_15 )
F_77 () ;
V_246 -> V_15 = NULL ;
}
static int F_178 ( struct V_165 * V_166 , void * V_238 )
{
F_141 ( V_166 , V_238 ) ;
return 0 ;
}
static void * F_179 ( struct V_165 * V_166 , T_5 * V_216 )
{
struct V_245 * V_246 = V_166 -> V_247 ;
V_246 -> V_10 = * V_216 ;
if ( * V_216 >= V_263 )
return NULL ;
F_81 () ;
return V_264 ;
}
static void * F_180 ( struct V_165 * V_166 , void * V_238 ,
T_5 * V_216 )
{
struct V_245 * V_246 = V_166 -> V_247 ;
( * V_216 ) ++ ;
V_246 -> V_10 ++ ;
if ( V_246 -> V_10 >= V_263 ) {
F_83 () ;
return NULL ;
}
return V_264 ;
}
static void F_181 ( struct V_165 * V_166 , void * V_238 )
{
F_83 () ;
}
static int F_182 ( struct V_105 * V_105 , struct V_265 * V_265 )
{
int V_64 = F_183 ( V_265 , & V_266 ,
sizeof( struct V_245 ) ) ;
if ( V_64 == 0 ) {
struct V_165 * V_166 = V_265 -> V_148 ;
struct V_245 * V_246 = V_166 -> V_247 ;
V_246 -> V_2 = V_105 -> V_267 ;
V_166 -> V_220 = F_120 ( V_268 , V_269 | V_270 ) ;
if ( V_166 -> V_220 )
V_166 -> V_271 = V_268 ;
}
return V_64 ;
}
static int F_184 ( struct V_105 * V_105 , struct V_265 * V_265 )
{
int V_64 = F_183 ( V_265 , & V_272 ,
sizeof( struct V_245 ) ) ;
if ( V_64 == 0 ) {
struct V_165 * V_166 = V_265 -> V_148 ;
struct V_245 * V_246 = V_166 -> V_247 ;
V_246 -> V_2 = V_105 -> V_267 ;
V_166 -> V_220 = F_120 ( V_268 , V_269 | V_270 ) ;
if ( V_166 -> V_220 )
V_166 -> V_271 = V_268 ;
}
return V_64 ;
}
static int F_185 ( struct V_105 * V_105 , struct V_265 * V_265 )
{
int V_64 = F_183 ( V_265 , & V_273 ,
sizeof( struct V_245 ) ) ;
if ( V_64 == 0 ) {
struct V_165 * V_166 = V_265 -> V_148 ;
struct V_245 * V_246 = V_166 -> V_247 ;
V_246 -> V_2 = V_105 -> V_267 ;
}
return V_64 ;
}
int F_186 ( struct V_1 * V_2 )
{
V_2 -> V_274 = F_187 ( V_2 -> V_275 , V_276 ) ;
if ( ! V_2 -> V_274 )
return - V_130 ;
V_2 -> V_277 = F_188 ( L_17 ,
V_278 | V_279 ,
V_2 -> V_274 , V_2 ,
& V_280 ) ;
if ( ! V_2 -> V_277 )
goto V_281;
V_2 -> V_282 = F_188 ( L_18 ,
V_278 | V_279 ,
V_2 -> V_274 , V_2 ,
& V_283 ) ;
if ( ! V_2 -> V_282 )
goto V_281;
V_2 -> V_284 = F_188 ( L_19 ,
V_278 | V_279 ,
V_2 -> V_274 , V_2 ,
& V_285 ) ;
if ( ! V_2 -> V_284 )
goto V_281;
return 0 ;
V_281:
F_189 ( V_2 ) ;
return - V_130 ;
}
void F_189 ( struct V_1 * V_2 )
{
if ( V_2 -> V_274 ) {
if ( V_2 -> V_277 ) {
F_190 ( V_2 -> V_277 ) ;
V_2 -> V_277 = NULL ;
}
if ( V_2 -> V_282 ) {
F_190 ( V_2 -> V_282 ) ;
V_2 -> V_282 = NULL ;
}
if ( V_2 -> V_284 ) {
F_190 ( V_2 -> V_284 ) ;
V_2 -> V_284 = NULL ;
}
F_190 ( V_2 -> V_274 ) ;
V_2 -> V_274 = NULL ;
}
}
int F_191 ( void )
{
V_276 = F_187 ( L_20 , NULL ) ;
return V_276 ? 0 : - V_130 ;
}
void F_192 ( void )
{
F_190 ( V_276 ) ;
V_276 = NULL ;
}
