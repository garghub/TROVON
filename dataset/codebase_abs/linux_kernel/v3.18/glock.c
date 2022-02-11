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
V_51 -> V_153 = V_154 ;
V_51 -> V_155 = F_90 ( F_91 ( V_156 ) ) ;
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_147 ;
V_51 -> V_68 = 0 ;
V_51 -> V_63 = 0 ;
F_15 ( V_15 ) ;
}
void F_92 ( unsigned int V_86 , unsigned V_147 , struct V_50 * V_51 )
{
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_147 ;
V_51 -> V_63 = 0 ;
V_51 -> V_153 = V_154 ;
if ( V_51 -> V_155 )
F_93 ( V_51 -> V_155 ) ;
V_51 -> V_155 = F_90 ( F_91 ( V_156 ) ) ;
}
void F_94 ( struct V_50 * V_51 )
{
F_93 ( V_51 -> V_155 ) ;
F_32 ( V_51 -> V_152 ) ;
V_51 -> V_152 = NULL ;
V_51 -> V_153 = 0 ;
}
int F_95 ( struct V_50 * V_51 )
{
unsigned long V_157 = V_83 ;
F_96 () ;
F_97 ( & V_51 -> V_63 , V_62 , V_158 ) ;
if ( F_98 ( V_83 , V_157 + V_159 ) )
V_51 -> V_152 -> V_79 = F_99 ( V_51 -> V_152 -> V_79 +
V_160 ,
V_161 ) ;
return V_51 -> V_68 ;
}
static void F_100 ( struct V_14 * V_15 , unsigned int V_86 ,
unsigned long V_110 , bool V_162 )
{
int V_163 = V_110 ? V_115 : V_85 ;
F_26 ( V_163 , & V_15 -> V_39 ) ;
if ( V_15 -> V_84 == V_56 ) {
V_15 -> V_84 = V_86 ;
V_15 -> V_164 = V_83 ;
} else if ( V_15 -> V_84 != V_31 &&
V_15 -> V_84 != V_86 ) {
V_15 -> V_84 = V_31 ;
}
if ( V_15 -> V_17 -> V_165 )
V_15 -> V_17 -> V_165 ( V_15 , V_162 ) ;
F_101 ( V_15 , V_162 ) ;
}
void F_102 ( struct V_166 * V_167 , const char * V_168 , ... )
{
struct V_169 V_170 ;
T_1 args ;
va_start ( args , V_168 ) ;
if ( V_167 ) {
F_103 ( V_167 , V_168 , args ) ;
} else {
V_170 . V_168 = V_168 ;
V_170 . V_171 = & args ;
F_62 ( L_2 , & V_170 ) ;
}
va_end ( args ) ;
}
static inline void F_104 ( struct V_50 * V_51 )
__releases( &gl->gl_spin
int F_105 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_152 ;
struct V_1 * V_2 = V_15 -> V_24 ;
int error = 0 ;
if ( F_59 ( F_49 ( V_172 , & V_2 -> V_173 ) ) )
return - V_69 ;
if ( F_49 ( V_38 , & V_15 -> V_39 ) )
F_31 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_104 ( V_51 ) ;
if ( F_59 ( ( V_174 & V_51 -> V_57 ) &&
F_63 ( V_175 , & V_15 -> V_39 ) ) ) {
F_26 ( V_113 , & V_15 -> V_39 ) ;
V_15 -> V_27 . V_76 ++ ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
V_15 -> V_27 . V_76 -- ;
}
F_65 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! ( V_51 -> V_57 & V_176 ) )
error = F_95 ( V_51 ) ;
return error ;
}
int F_106 ( struct V_50 * V_51 )
{
return F_49 ( V_62 , & V_51 -> V_63 ) ? 0 : 1 ;
}
void F_107 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_152 ;
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned V_110 = 0 ;
int V_177 = 0 ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_51 -> V_57 & V_178 )
F_100 ( V_15 , V_31 , 0 , false ) ;
F_23 ( & V_51 -> V_54 ) ;
if ( F_64 ( V_15 ) == NULL ) {
if ( V_29 -> V_179 ) {
F_16 ( V_15 , F_108 ( V_97 , & V_15 -> V_39 ) ) ;
F_27 ( & V_15 -> V_89 ) ;
V_29 -> V_179 ( V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_97 , & V_15 -> V_39 ) ;
}
if ( F_20 ( & V_15 -> V_32 ) &&
! F_49 ( V_115 , & V_15 -> V_39 ) &&
! F_49 ( V_85 , & V_15 -> V_39 ) )
V_177 = 1 ;
}
if ( ! F_49 ( V_180 , & V_15 -> V_39 ) && F_19 ( V_15 ) )
F_21 ( V_15 ) ;
F_50 ( V_51 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_109 ( V_177 ) )
return;
F_15 ( V_15 ) ;
if ( F_49 ( V_115 , & V_15 -> V_39 ) &&
! F_49 ( V_85 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_118 )
V_110 = V_15 -> V_79 ;
if ( F_74 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_32 ( V_15 ) ;
}
void F_110 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_152 ;
F_107 ( V_51 ) ;
F_96 () ;
F_97 ( & V_15 -> V_39 , V_85 , V_158 ) ;
}
void F_111 ( struct V_50 * V_51 )
{
F_107 ( V_51 ) ;
F_94 ( V_51 ) ;
}
int F_112 ( struct V_1 * V_2 , V_7 V_120 ,
const struct V_28 * V_29 ,
unsigned int V_86 , int V_147 , struct V_50 * V_51 )
{
struct V_14 * V_15 ;
int error ;
error = F_75 ( V_2 , V_120 , V_29 , V_181 , & V_15 ) ;
if ( ! error ) {
error = F_113 ( V_15 , V_86 , V_147 , V_51 ) ;
F_32 ( V_15 ) ;
}
return error ;
}
static int F_114 ( const void * V_182 , const void * V_183 )
{
const struct V_50 * V_184 = * ( const struct V_50 * * ) V_182 ;
const struct V_50 * V_185 = * ( const struct V_50 * * ) V_183 ;
const struct V_3 * V_186 = & V_184 -> V_152 -> V_49 ;
const struct V_3 * V_187 = & V_185 -> V_152 -> V_49 ;
if ( V_186 -> V_6 > V_187 -> V_6 )
return 1 ;
if ( V_186 -> V_6 < V_187 -> V_6 )
return - 1 ;
F_115 ( V_184 -> V_152 -> V_17 -> V_125 == V_185 -> V_152 -> V_17 -> V_125 ) ;
return 0 ;
}
static int F_116 ( unsigned int V_188 , struct V_50 * V_189 ,
struct V_50 * * V_190 )
{
unsigned int V_191 ;
int error = 0 ;
for ( V_191 = 0 ; V_191 < V_188 ; V_191 ++ )
V_190 [ V_191 ] = & V_189 [ V_191 ] ;
F_117 ( V_190 , V_188 , sizeof( struct V_50 * ) , F_114 , NULL ) ;
for ( V_191 = 0 ; V_191 < V_188 ; V_191 ++ ) {
V_190 [ V_191 ] -> V_57 &= ~ ( V_70 | V_176 ) ;
error = F_105 ( V_190 [ V_191 ] ) ;
if ( error ) {
while ( V_191 -- )
F_107 ( V_190 [ V_191 ] ) ;
break;
}
}
return error ;
}
int F_118 ( unsigned int V_188 , struct V_50 * V_189 )
{
struct V_50 * V_65 [ 4 ] ;
struct V_50 * * V_192 = V_65 ;
int error = 0 ;
switch( V_188 ) {
case 0 :
return 0 ;
case 1 :
V_189 -> V_57 &= ~ ( V_70 | V_176 ) ;
return F_105 ( V_189 ) ;
default:
if ( V_188 <= 4 )
break;
V_192 = F_119 ( V_188 * sizeof( struct V_50 * ) , V_129 ) ;
if ( ! V_192 )
return - V_130 ;
}
error = F_116 ( V_188 , V_189 , V_192 ) ;
if ( V_192 != V_65 )
F_10 ( V_192 ) ;
return error ;
}
void F_120 ( unsigned int V_188 , struct V_50 * V_189 )
{
while ( V_188 -- )
F_107 ( & V_189 [ V_188 ] ) ;
}
void F_121 ( struct V_14 * V_15 , unsigned int V_86 )
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
F_100 ( V_15 , V_86 , V_110 , true ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_122 ( const struct V_14 * V_15 )
{
const struct V_50 * V_51 ;
if ( V_15 -> V_114 & ~ V_87 )
return 0 ;
if ( V_15 -> V_78 == V_31 )
return 0 ;
F_53 (gh, &gl->gl_holders, gh_list) {
if ( F_49 ( V_66 , & V_51 -> V_63 ) )
continue;
if ( V_174 & V_51 -> V_57 )
return 0 ;
}
return 1 ;
}
void F_123 ( struct V_14 * V_15 , int V_64 )
{
struct V_193 * V_194 = & V_15 -> V_24 -> V_45 ;
F_22 ( & V_15 -> V_89 ) ;
V_15 -> V_114 = V_64 ;
if ( F_59 ( F_49 ( V_195 , & V_194 -> V_196 ) ) ) {
if ( F_122 ( V_15 ) ) {
F_26 ( V_175 , & V_15 -> V_39 ) ;
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
static int F_124 ( void * V_197 , struct V_198 * V_186 , struct V_198 * V_187 )
{
struct V_14 * V_199 , * V_200 ;
V_199 = F_43 ( V_186 , struct V_14 , V_35 ) ;
V_200 = F_43 ( V_187 , struct V_14 , V_35 ) ;
if ( V_199 -> V_49 . V_6 > V_200 -> V_49 . V_6 )
return 1 ;
if ( V_199 -> V_49 . V_6 < V_200 -> V_49 . V_6 )
return - 1 ;
return 0 ;
}
static void F_125 ( struct V_198 * V_201 )
__releases( &lru_lock
static long F_126 ( int V_202 )
{
struct V_14 * V_15 ;
F_127 ( V_203 ) ;
F_127 ( V_204 ) ;
long V_205 = 0 ;
F_22 ( & V_34 ) ;
while ( ( V_202 -- >= 0 ) && ! F_20 ( & V_37 ) ) {
V_15 = F_43 ( V_37 . V_53 , struct V_14 , V_35 ) ;
if ( ! F_49 ( V_97 , & V_15 -> V_39 ) ) {
F_128 ( & V_15 -> V_35 , & V_204 ) ;
F_29 ( & V_36 ) ;
V_205 ++ ;
continue;
}
F_128 ( & V_15 -> V_35 , & V_203 ) ;
}
F_129 ( & V_203 , & V_37 ) ;
if ( ! F_20 ( & V_204 ) )
F_125 ( & V_204 ) ;
F_27 ( & V_34 ) ;
return V_205 ;
}
static unsigned long F_130 ( struct V_206 * V_207 ,
struct V_208 * V_209 )
{
if ( ! ( V_209 -> V_210 & V_211 ) )
return V_212 ;
return F_126 ( V_209 -> V_213 ) ;
}
static unsigned long F_131 ( struct V_206 * V_207 ,
struct V_208 * V_209 )
{
return F_132 ( F_133 ( & V_36 ) ) ;
}
static void F_134 ( T_2 V_214 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_215 * V_216 = & V_11 [ V_10 ] ;
struct V_48 * V_217 ;
F_76 () ;
F_39 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_24 == V_2 ) && F_41 ( & V_15 -> V_27 ) )
V_214 ( V_15 ) ;
}
F_77 () ;
F_135 () ;
}
static void F_136 ( T_2 V_214 , const struct V_1 * V_2 )
{
unsigned V_191 ;
for ( V_191 = 0 ; V_191 < V_218 ; V_191 ++ )
F_134 ( V_214 , V_2 , V_191 ) ;
}
static void F_137 ( struct V_14 * V_15 )
{
if ( ! F_63 ( V_175 , & V_15 -> V_39 ) )
goto V_94;
F_26 ( V_113 , & V_15 -> V_39 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 ) {
V_94:
F_32 ( V_15 ) ;
}
}
static void F_138 ( struct V_14 * V_15 )
{
F_31 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_15 -> V_30 != V_31 )
F_100 ( V_15 , V_31 , 0 , false ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
void F_139 ( struct V_1 * V_2 )
{
F_136 ( F_137 , V_2 ) ;
}
static void F_140 ( struct V_166 * V_167 , struct V_14 * V_15 )
{
F_22 ( & V_15 -> V_89 ) ;
F_141 ( V_167 , V_15 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static void F_142 ( struct V_14 * V_15 )
{
F_140 ( NULL , V_15 ) ;
}
void F_143 ( struct V_1 * V_2 )
{
F_26 ( V_219 , & V_2 -> V_173 ) ;
F_144 ( V_119 ) ;
F_136 ( F_138 , V_2 ) ;
F_144 ( V_119 ) ;
F_145 ( V_2 -> V_26 , F_133 ( & V_2 -> V_25 ) == 0 ) ;
F_136 ( F_142 , V_2 ) ;
}
void F_146 ( struct V_103 * V_104 )
{
struct V_14 * V_15 = V_104 -> V_220 ;
int V_64 ;
V_64 = F_147 ( V_104 ) ;
F_148 ( V_15 -> V_24 , V_64 == 0 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_97 , & V_15 -> V_39 ) ;
F_65 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static const char * F_149 ( unsigned V_86 )
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
static const char * F_150 ( char * V_221 , unsigned V_147 , unsigned long V_222 )
{
char * V_190 = V_221 ;
if ( V_147 & V_70 )
* V_190 ++ = 't' ;
if ( V_147 & V_71 )
* V_190 ++ = 'T' ;
if ( V_147 & V_174 )
* V_190 ++ = 'e' ;
if ( V_147 & V_61 )
* V_190 ++ = 'A' ;
if ( V_147 & V_92 )
* V_190 ++ = 'p' ;
if ( V_147 & V_176 )
* V_190 ++ = 'a' ;
if ( V_147 & V_58 )
* V_190 ++ = 'E' ;
if ( V_147 & V_178 )
* V_190 ++ = 'c' ;
if ( F_49 ( V_66 , & V_222 ) )
* V_190 ++ = 'H' ;
if ( F_49 ( V_62 , & V_222 ) )
* V_190 ++ = 'W' ;
if ( F_49 ( V_223 , & V_222 ) )
* V_190 ++ = 'F' ;
* V_190 = 0 ;
return V_221 ;
}
static void F_151 ( struct V_166 * V_167 , const struct V_50 * V_51 )
{
struct V_224 * V_225 = NULL ;
char V_226 [ 32 ] ;
F_76 () ;
if ( V_51 -> V_155 )
V_225 = F_152 ( V_51 -> V_155 , V_227 ) ;
F_102 ( V_167 , L_8 ,
F_149 ( V_51 -> V_55 ) ,
F_150 ( V_226 , V_51 -> V_57 , V_51 -> V_63 ) ,
V_51 -> V_68 ,
V_51 -> V_155 ? ( long ) F_153 ( V_51 -> V_155 ) : - 1 ,
V_225 ? V_225 -> V_228 : L_9 ,
( void * ) V_51 -> V_153 ) ;
F_77 () ;
}
static const char * F_154 ( char * V_221 , const struct V_14 * V_15 )
{
const unsigned long * V_229 = & V_15 -> V_39 ;
char * V_190 = V_221 ;
if ( F_49 ( V_97 , V_229 ) )
* V_190 ++ = 'l' ;
if ( F_49 ( V_85 , V_229 ) )
* V_190 ++ = 'D' ;
if ( F_49 ( V_115 , V_229 ) )
* V_190 ++ = 'd' ;
if ( F_49 ( V_90 , V_229 ) )
* V_190 ++ = 'p' ;
if ( F_49 ( V_230 , V_229 ) )
* V_190 ++ = 'y' ;
if ( F_49 ( V_180 , V_229 ) )
* V_190 ++ = 'f' ;
if ( F_49 ( V_231 , V_229 ) )
* V_190 ++ = 'i' ;
if ( F_49 ( V_113 , V_229 ) )
* V_190 ++ = 'r' ;
if ( F_49 ( V_232 , V_229 ) )
* V_190 ++ = 'I' ;
if ( F_49 ( V_175 , V_229 ) )
* V_190 ++ = 'F' ;
if ( F_49 ( V_77 , V_229 ) )
* V_190 ++ = 'q' ;
if ( F_49 ( V_38 , V_229 ) )
* V_190 ++ = 'L' ;
if ( V_15 -> V_107 )
* V_190 ++ = 'o' ;
if ( F_49 ( V_233 , V_229 ) )
* V_190 ++ = 'b' ;
* V_190 = 0 ;
return V_221 ;
}
void F_141 ( struct V_166 * V_167 , const struct V_14 * V_15 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned long long V_234 ;
const struct V_50 * V_51 ;
char V_235 [ 32 ] ;
V_234 = V_83 - V_15 -> V_164 ;
V_234 *= 1000000 / V_159 ;
if ( ! F_49 ( V_85 , & V_15 -> V_39 ) )
V_234 = 0 ;
F_102 ( V_167 , L_10 ,
F_149 ( V_15 -> V_30 ) ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
F_154 ( V_235 , V_15 ) ,
F_149 ( V_15 -> V_78 ) ,
F_149 ( V_15 -> V_84 ) , V_234 ,
F_133 ( & V_15 -> V_236 ) ,
F_133 ( & V_15 -> V_237 ) ,
( int ) V_15 -> V_27 . V_76 , V_15 -> V_79 ) ;
F_53 (gh, &gl->gl_holders, gh_list)
F_151 ( V_167 , V_51 ) ;
if ( V_15 -> V_30 != V_31 && V_29 -> V_238 )
V_29 -> V_238 ( V_167 , V_15 ) ;
}
static int F_155 ( struct V_166 * V_167 , void * V_239 )
{
struct V_14 * V_15 = V_239 ;
F_156 ( V_167 , L_11 ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
( long long ) V_15 -> V_135 . V_138 [ V_240 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_241 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_242 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_243 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_244 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_245 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_139 ] ,
( long long ) V_15 -> V_135 . V_138 [ V_140 ] ) ;
return 0 ;
}
static int F_157 ( struct V_166 * V_167 , void * V_239 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
struct V_1 * V_2 = V_247 -> V_2 ;
unsigned V_249 = V_247 -> V_10 >> 3 ;
unsigned V_250 = V_247 -> V_10 & 0x07 ;
T_3 V_251 ;
int V_252 ;
if ( V_249 == 0 && V_250 != 0 )
return 0 ;
F_156 ( V_167 , L_12 , V_253 [ V_249 ] ,
( V_249 == 0 ) ? L_13 : V_254 [ V_250 ] ) ;
F_158 (i) {
const struct V_255 * V_137 = F_159 ( V_2 -> V_136 , V_252 ) ;
if ( V_249 == 0 ) {
V_251 = V_252 ;
} else {
V_251 = V_137 -> V_137 [ V_249 - 1 ] . V_138 [ V_250 ] ;
}
F_156 ( V_167 , L_14 , ( long long ) V_251 ) ;
}
F_160 ( V_167 , '\n' ) ;
return 0 ;
}
int T_4 F_161 ( void )
{
unsigned V_252 ;
for( V_252 = 0 ; V_252 < V_218 ; V_252 ++ ) {
F_162 ( & V_11 [ V_252 ] ) ;
}
V_119 = F_163 ( L_15 , V_256 |
V_257 | V_258 , 0 ) ;
if ( ! V_119 )
return - V_130 ;
V_259 = F_163 ( L_16 ,
V_256 | V_258 ,
0 ) ;
if ( ! V_259 ) {
F_164 ( V_119 ) ;
return - V_130 ;
}
F_165 ( & V_260 ) ;
return 0 ;
}
void F_166 ( void )
{
F_167 ( & V_260 ) ;
F_164 ( V_119 ) ;
F_164 ( V_259 ) ;
}
static inline struct V_14 * F_168 ( unsigned V_10 )
{
return F_169 ( F_170 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_43 ) ;
}
static inline struct V_14 * F_171 ( struct V_14 * V_15 )
{
return F_169 ( F_172 ( V_15 -> V_43 . V_53 ) ,
struct V_14 , V_43 ) ;
}
static int F_173 ( struct V_246 * V_247 )
{
struct V_14 * V_15 ;
do {
V_15 = V_247 -> V_15 ;
if ( V_15 ) {
V_247 -> V_15 = F_171 ( V_15 ) ;
V_247 -> V_261 ++ ;
} else {
if ( V_247 -> V_10 >= V_218 ) {
F_77 () ;
return 1 ;
}
V_247 -> V_15 = F_168 ( V_247 -> V_10 ) ;
V_247 -> V_261 = 0 ;
}
while ( V_247 -> V_15 == NULL ) {
V_247 -> V_10 ++ ;
if ( V_247 -> V_10 >= V_218 ) {
F_77 () ;
return 1 ;
}
V_247 -> V_15 = F_168 ( V_247 -> V_10 ) ;
V_247 -> V_261 = 0 ;
}
} while ( V_247 -> V_2 != V_247 -> V_15 -> V_24 ||
F_17 ( & V_247 -> V_15 -> V_27 ) );
return 0 ;
}
static void * F_174 ( struct V_166 * V_167 , T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
T_5 V_262 = * V_217 ;
if ( V_247 -> V_263 <= * V_217 )
V_262 = V_247 -> V_261 + ( * V_217 - V_247 -> V_263 ) ;
else
V_247 -> V_10 = 0 ;
V_247 -> V_261 = 0 ;
F_76 () ;
do {
if ( F_173 ( V_247 ) )
return NULL ;
} while ( V_262 -- );
V_247 -> V_263 = * V_217 ;
return V_247 -> V_15 ;
}
static void * F_175 ( struct V_166 * V_167 , void * V_239 ,
T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
( * V_217 ) ++ ;
V_247 -> V_263 = * V_217 ;
if ( F_173 ( V_247 ) )
return NULL ;
return V_247 -> V_15 ;
}
static void F_176 ( struct V_166 * V_167 , void * V_239 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
if ( V_247 -> V_15 )
F_77 () ;
V_247 -> V_15 = NULL ;
}
static int F_177 ( struct V_166 * V_167 , void * V_239 )
{
F_140 ( V_167 , V_239 ) ;
return 0 ;
}
static void * F_178 ( struct V_166 * V_167 , T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_10 = * V_217 ;
if ( * V_217 >= V_264 )
return NULL ;
F_81 () ;
return V_265 ;
}
static void * F_179 ( struct V_166 * V_167 , void * V_239 ,
T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
( * V_217 ) ++ ;
V_247 -> V_10 ++ ;
if ( V_247 -> V_10 >= V_264 ) {
F_83 () ;
return NULL ;
}
return V_265 ;
}
static void F_180 ( struct V_166 * V_167 , void * V_239 )
{
F_83 () ;
}
static int F_181 ( struct V_105 * V_105 , struct V_266 * V_266 )
{
int V_64 = F_182 ( V_266 , & V_267 ,
sizeof( struct V_246 ) ) ;
if ( V_64 == 0 ) {
struct V_166 * V_167 = V_266 -> V_148 ;
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_2 = V_105 -> V_268 ;
V_167 -> V_221 = F_119 ( V_269 , V_270 | V_271 ) ;
if ( V_167 -> V_221 )
V_167 -> V_272 = V_269 ;
}
return V_64 ;
}
static int F_183 ( struct V_105 * V_105 , struct V_266 * V_266 )
{
int V_64 = F_182 ( V_266 , & V_273 ,
sizeof( struct V_246 ) ) ;
if ( V_64 == 0 ) {
struct V_166 * V_167 = V_266 -> V_148 ;
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_2 = V_105 -> V_268 ;
V_167 -> V_221 = F_119 ( V_269 , V_270 | V_271 ) ;
if ( V_167 -> V_221 )
V_167 -> V_272 = V_269 ;
}
return V_64 ;
}
static int F_184 ( struct V_105 * V_105 , struct V_266 * V_266 )
{
int V_64 = F_182 ( V_266 , & V_274 ,
sizeof( struct V_246 ) ) ;
if ( V_64 == 0 ) {
struct V_166 * V_167 = V_266 -> V_148 ;
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_2 = V_105 -> V_268 ;
}
return V_64 ;
}
int F_185 ( struct V_1 * V_2 )
{
V_2 -> V_275 = F_186 ( V_2 -> V_276 , V_277 ) ;
if ( ! V_2 -> V_275 )
return - V_130 ;
V_2 -> V_278 = F_187 ( L_17 ,
V_279 | V_280 ,
V_2 -> V_275 , V_2 ,
& V_281 ) ;
if ( ! V_2 -> V_278 )
goto V_282;
V_2 -> V_283 = F_187 ( L_18 ,
V_279 | V_280 ,
V_2 -> V_275 , V_2 ,
& V_284 ) ;
if ( ! V_2 -> V_283 )
goto V_282;
V_2 -> V_285 = F_187 ( L_19 ,
V_279 | V_280 ,
V_2 -> V_275 , V_2 ,
& V_286 ) ;
if ( ! V_2 -> V_285 )
goto V_282;
return 0 ;
V_282:
F_188 ( V_2 ) ;
return - V_130 ;
}
void F_188 ( struct V_1 * V_2 )
{
if ( V_2 -> V_275 ) {
if ( V_2 -> V_278 ) {
F_189 ( V_2 -> V_278 ) ;
V_2 -> V_278 = NULL ;
}
if ( V_2 -> V_283 ) {
F_189 ( V_2 -> V_283 ) ;
V_2 -> V_283 = NULL ;
}
if ( V_2 -> V_285 ) {
F_189 ( V_2 -> V_285 ) ;
V_2 -> V_285 = NULL ;
}
F_189 ( V_2 -> V_275 ) ;
V_2 -> V_275 = NULL ;
}
}
int F_190 ( void )
{
V_277 = F_186 ( L_20 , NULL ) ;
return V_277 ? 0 : - V_130 ;
}
void F_191 ( void )
{
F_189 ( V_277 ) ;
V_277 = NULL ;
}
