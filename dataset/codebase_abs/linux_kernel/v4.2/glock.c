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
F_22 ( & V_34 ) ;
if ( ! F_20 ( & V_15 -> V_35 ) ) {
F_23 ( & V_15 -> V_35 ) ;
F_29 ( & V_36 ) ;
F_30 ( V_38 , & V_15 -> V_39 ) ;
}
F_27 ( & V_34 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_40 * V_41 = F_32 ( V_15 ) ;
if ( F_33 ( & V_15 -> V_27 ) )
return;
F_34 ( & V_15 -> V_27 ) ;
F_28 ( V_15 ) ;
F_27 ( & V_15 -> V_27 . V_42 ) ;
F_3 ( V_15 -> F_1 ) ;
F_35 ( & V_15 -> V_43 ) ;
F_5 ( V_15 -> F_1 ) ;
F_16 ( V_15 , ! F_20 ( & V_15 -> V_32 ) ) ;
F_16 ( V_15 , V_41 && V_41 -> V_44 ) ;
F_36 ( V_15 ) ;
V_2 -> V_45 . V_46 -> V_47 ( V_15 ) ;
}
static struct V_14 * F_37 ( unsigned int V_10 ,
const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_48 * V_5 ;
F_38 (gl, h, &gl_hash_table[hash], gl_list) {
if ( ! F_39 ( & V_15 -> V_49 , V_4 ) )
continue;
if ( V_15 -> V_24 != V_2 )
continue;
if ( F_40 ( & V_15 -> V_27 ) )
return V_15 ;
}
return NULL ;
}
static inline int F_41 ( const struct V_14 * V_15 , const struct V_50 * V_51 )
{
const struct V_50 * V_52 = F_42 ( V_15 -> V_32 . V_53 , const struct V_50 , V_54 ) ;
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
static void F_43 ( struct V_50 * V_51 )
{
F_30 ( V_62 , & V_51 -> V_63 ) ;
F_44 () ;
F_45 ( & V_51 -> V_63 , V_62 ) ;
}
static inline void F_46 ( struct V_14 * V_15 , const int V_64 )
{
struct V_50 * V_51 , * V_65 ;
F_47 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_48 ( V_66 , & V_51 -> V_63 ) )
continue;
if ( V_64 & V_67 )
V_51 -> V_68 = - V_69 ;
else if ( V_51 -> V_57 & ( V_70 | V_71 ) )
V_51 -> V_68 = V_72 ;
else
continue;
F_23 ( & V_51 -> V_54 ) ;
F_49 ( V_51 , 0 ) ;
F_43 ( V_51 ) ;
}
}
static int F_50 ( struct V_14 * V_15 )
__releases( &gl->gl_spin
static inline struct V_50 * F_51 ( const struct V_14 * V_15 )
{
struct V_50 * V_51 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( ! F_48 ( V_66 , & V_51 -> V_63 ) )
return V_51 ;
}
return NULL ;
}
static void F_53 ( struct V_14 * V_15 , unsigned int V_73 )
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
V_15 -> V_79 = F_54 ( V_15 -> V_79 - V_80 ,
V_81 ) ;
V_15 -> V_30 = V_73 ;
V_15 -> V_82 = V_83 ;
}
static void F_55 ( struct V_14 * V_15 )
{
V_15 -> V_84 = V_56 ;
F_30 ( V_85 , & V_15 -> V_39 ) ;
F_44 () ;
F_45 ( & V_15 -> V_39 , V_85 ) ;
}
static void F_56 ( struct V_14 * V_15 , unsigned int V_64 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
struct V_50 * V_51 ;
unsigned V_86 = V_64 & V_87 ;
int V_88 ;
F_22 ( & V_15 -> V_89 ) ;
F_57 ( V_15 , V_86 ) ;
F_53 ( V_15 , V_86 ) ;
V_51 = F_51 ( V_15 ) ;
if ( F_48 ( V_90 , & V_15 -> V_39 ) &&
V_86 != V_31 && V_15 -> V_84 == V_31 )
V_15 -> V_78 = V_31 ;
if ( F_58 ( V_86 != V_15 -> V_78 ) ) {
if ( V_51 && ! F_48 ( V_90 , & V_15 -> V_39 ) ) {
if ( V_64 & V_91 ) {
if ( ( V_51 -> V_57 & V_92 ) == 0 )
F_59 ( & V_51 -> V_54 , & V_15 -> V_32 ) ;
V_51 = F_51 ( V_15 ) ;
V_15 -> V_78 = V_51 -> V_55 ;
goto V_93;
}
if ( ( V_64 & V_67 ) ||
( V_51 -> V_57 & ( V_70 | V_71 ) ) ) {
V_15 -> V_78 = V_15 -> V_30 ;
F_46 ( V_15 , V_64 ) ;
goto V_94;
}
}
switch( V_86 ) {
case V_31 :
V_93:
F_60 ( V_15 , V_51 , V_15 -> V_78 ) ;
break;
case V_59 :
case V_60 :
F_60 ( V_15 , V_51 , V_31 ) ;
break;
default:
F_61 ( L_1 , V_15 -> V_78 , V_86 ) ;
F_16 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_89 ) ;
return;
}
if ( F_62 ( V_90 , & V_15 -> V_39 ) )
F_55 ( V_15 ) ;
if ( V_86 != V_31 ) {
if ( V_29 -> V_95 ) {
F_27 ( & V_15 -> V_89 ) ;
V_88 = V_29 -> V_95 ( V_15 , V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_88 ) {
F_46 ( V_15 , V_88 ) ;
goto V_94;
}
}
V_88 = F_50 ( V_15 ) ;
if ( V_88 == 2 )
goto V_96;
}
V_94:
F_30 ( V_97 , & V_15 -> V_39 ) ;
V_96:
F_27 ( & V_15 -> V_89 ) ;
}
static void F_60 ( struct V_14 * V_15 , struct V_50 * V_51 , unsigned int V_98 )
__releases( &gl->gl_spin
static inline struct V_50 * F_63 ( const struct V_14 * V_15 )
{
struct V_50 * V_51 ;
if ( ! F_20 ( & V_15 -> V_32 ) ) {
V_51 = F_42 ( V_15 -> V_32 . V_53 , struct V_50 , V_54 ) ;
if ( F_48 ( V_66 , & V_51 -> V_63 ) )
return V_51 ;
}
return NULL ;
}
static void F_64 ( struct V_14 * V_15 , const int V_99 )
__releases( &gl->gl_spin
static void F_65 ( struct V_100 * V_101 )
{
struct V_14 * V_15 = F_8 ( V_101 , struct V_14 , V_102 ) ;
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_103 * V_104 ;
struct V_105 * V_105 ;
V_7 V_106 = V_15 -> V_49 . V_6 ;
V_104 = V_15 -> V_107 ;
if ( V_104 )
V_105 = F_66 ( V_2 -> V_108 , V_106 , 1 ) ;
else
V_105 = F_67 ( V_2 , V_106 , NULL , V_109 ) ;
if ( V_105 && ! F_68 ( V_105 ) ) {
F_69 ( V_105 ) ;
F_70 ( V_105 ) ;
}
F_31 ( V_15 ) ;
}
static void F_71 ( struct V_100 * V_101 )
{
unsigned long V_110 = 0 ;
struct V_14 * V_15 = F_8 ( V_101 , struct V_14 , V_111 . V_101 ) ;
int V_112 = 0 ;
if ( F_62 ( V_113 , & V_15 -> V_39 ) ) {
F_56 ( V_15 , V_15 -> V_114 ) ;
V_112 = 1 ;
}
F_22 ( & V_15 -> V_89 ) ;
if ( F_48 ( V_115 , & V_15 -> V_39 ) &&
V_15 -> V_30 != V_31 &&
V_15 -> V_84 != V_56 ) {
unsigned long V_116 , V_117 = V_83 ;
V_116 = V_15 -> V_82 + V_15 -> V_79 ;
if ( F_72 ( V_117 , V_116 ) )
V_110 = V_116 - V_117 ;
if ( ! V_110 ) {
F_30 ( V_115 , & V_15 -> V_39 ) ;
F_26 ( V_85 , & V_15 -> V_39 ) ;
}
}
F_64 ( V_15 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! V_110 )
F_31 ( V_15 ) ;
else {
if ( V_15 -> V_49 . V_8 != V_118 )
V_110 = 0 ;
if ( F_73 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_31 ( V_15 ) ;
}
if ( V_112 )
F_31 ( V_15 ) ;
}
int F_74 ( struct V_1 * V_2 , V_7 V_120 ,
const struct V_28 * V_29 , int V_121 ,
struct V_14 * * V_122 )
{
struct V_123 * V_124 = V_2 -> V_108 ;
struct V_3 V_4 = { . V_6 = V_120 , . V_8 = V_29 -> V_125 } ;
struct V_14 * V_15 , * V_65 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_40 * V_41 ;
struct V_126 * V_127 ;
F_75 () ;
V_15 = F_37 ( V_10 , V_2 , & V_4 ) ;
F_76 () ;
* V_122 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_121 )
return - V_128 ;
if ( V_29 -> V_18 & V_19 )
V_127 = V_20 ;
else
V_127 = V_23 ;
V_15 = F_77 ( V_127 , V_129 ) ;
if ( ! V_15 )
return - V_130 ;
memset ( & V_15 -> V_21 , 0 , sizeof( struct V_131 ) ) ;
if ( V_29 -> V_18 & V_132 ) {
V_15 -> V_21 . V_22 = F_78 ( V_133 , V_129 ) ;
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
V_15 -> V_134 = F_79 ( 0 , 0 ) ;
F_80 () ;
V_15 -> V_135 = F_81 ( V_2 -> V_136 ) -> V_137 [ V_29 -> V_125 ] ;
F_82 () ;
V_15 -> V_135 . V_138 [ V_139 ] = 0 ;
V_15 -> V_135 . V_138 [ V_140 ] = 0 ;
V_15 -> V_82 = V_83 ;
V_15 -> V_107 = NULL ;
V_15 -> V_79 = V_141 ;
F_83 ( & V_15 -> V_111 , F_71 ) ;
F_84 ( & V_15 -> V_102 , F_65 ) ;
V_41 = F_32 ( V_15 ) ;
if ( V_41 ) {
V_41 -> V_142 = & V_143 ;
V_41 -> V_144 = V_124 -> V_145 -> V_146 ;
V_41 -> V_147 = 0 ;
F_85 ( V_41 , V_129 ) ;
V_41 -> V_148 = NULL ;
V_41 -> V_149 = 0 ;
}
F_3 ( V_10 ) ;
V_65 = F_37 ( V_10 , V_2 , & V_4 ) ;
if ( V_65 ) {
F_5 ( V_10 ) ;
F_10 ( V_15 -> V_21 . V_22 ) ;
F_9 ( V_127 , V_15 ) ;
F_29 ( & V_2 -> V_25 ) ;
V_15 = V_65 ;
} else {
F_86 ( & V_15 -> V_43 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_122 = V_15 ;
return 0 ;
}
void F_87 ( struct V_14 * V_15 , unsigned int V_86 , unsigned V_147 ,
struct V_50 * V_51 )
{
F_88 ( & V_51 -> V_54 ) ;
V_51 -> V_150 = V_15 ;
V_51 -> V_151 = V_152 ;
V_51 -> V_153 = F_89 ( F_90 ( V_154 ) ) ;
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_147 ;
V_51 -> V_68 = 0 ;
V_51 -> V_63 = 0 ;
F_15 ( V_15 ) ;
}
void F_91 ( unsigned int V_86 , unsigned V_147 , struct V_50 * V_51 )
{
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_147 ;
V_51 -> V_63 = 0 ;
V_51 -> V_151 = V_152 ;
F_92 ( V_51 -> V_153 ) ;
V_51 -> V_153 = F_89 ( F_90 ( V_154 ) ) ;
}
void F_93 ( struct V_50 * V_51 )
{
F_92 ( V_51 -> V_153 ) ;
F_31 ( V_51 -> V_150 ) ;
V_51 -> V_150 = NULL ;
V_51 -> V_151 = 0 ;
}
int F_94 ( struct V_50 * V_51 )
{
unsigned long V_155 = V_83 ;
F_95 () ;
F_96 ( & V_51 -> V_63 , V_62 , V_156 ) ;
if ( F_97 ( V_83 , V_155 + V_157 ) )
V_51 -> V_150 -> V_79 = F_98 ( V_51 -> V_150 -> V_79 +
V_158 ,
V_159 ) ;
return V_51 -> V_68 ;
}
static void F_99 ( struct V_14 * V_15 , unsigned int V_86 ,
unsigned long V_110 , bool V_160 )
{
int V_161 = V_110 ? V_115 : V_85 ;
F_26 ( V_161 , & V_15 -> V_39 ) ;
if ( V_15 -> V_84 == V_56 ) {
V_15 -> V_84 = V_86 ;
V_15 -> V_162 = V_83 ;
} else if ( V_15 -> V_84 != V_31 &&
V_15 -> V_84 != V_86 ) {
V_15 -> V_84 = V_31 ;
}
if ( V_15 -> V_17 -> V_163 )
V_15 -> V_17 -> V_163 ( V_15 , V_160 ) ;
F_100 ( V_15 , V_160 ) ;
}
void F_101 ( struct V_164 * V_165 , const char * V_166 , ... )
{
struct V_167 V_168 ;
T_1 args ;
va_start ( args , V_166 ) ;
if ( V_165 ) {
F_102 ( V_165 , V_166 , args ) ;
} else {
V_168 . V_166 = V_166 ;
V_168 . V_169 = & args ;
F_61 ( L_2 , & V_168 ) ;
}
va_end ( args ) ;
}
static inline void F_103 ( struct V_50 * V_51 )
__releases( &gl->gl_spin
int F_104 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_150 ;
struct V_1 * V_2 = V_15 -> V_24 ;
int error = 0 ;
if ( F_58 ( F_48 ( V_170 , & V_2 -> V_171 ) ) )
return - V_69 ;
if ( F_48 ( V_38 , & V_15 -> V_39 ) )
F_28 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_103 ( V_51 ) ;
if ( F_58 ( ( V_172 & V_51 -> V_57 ) &&
F_62 ( V_173 , & V_15 -> V_39 ) ) ) {
F_26 ( V_113 , & V_15 -> V_39 ) ;
V_15 -> V_27 . V_76 ++ ;
if ( F_73 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
V_15 -> V_27 . V_76 -- ;
}
F_64 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! ( V_51 -> V_57 & V_174 ) )
error = F_94 ( V_51 ) ;
return error ;
}
int F_105 ( struct V_50 * V_51 )
{
return F_48 ( V_62 , & V_51 -> V_63 ) ? 0 : 1 ;
}
void F_106 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_150 ;
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned V_110 = 0 ;
int V_175 = 0 ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_51 -> V_57 & V_176 )
F_99 ( V_15 , V_31 , 0 , false ) ;
F_23 ( & V_51 -> V_54 ) ;
if ( F_63 ( V_15 ) == NULL ) {
if ( V_29 -> V_177 ) {
F_16 ( V_15 , F_107 ( V_97 , & V_15 -> V_39 ) ) ;
F_27 ( & V_15 -> V_89 ) ;
V_29 -> V_177 ( V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_97 , & V_15 -> V_39 ) ;
}
if ( F_20 ( & V_15 -> V_32 ) &&
! F_48 ( V_115 , & V_15 -> V_39 ) &&
! F_48 ( V_85 , & V_15 -> V_39 ) )
V_175 = 1 ;
}
if ( ! F_48 ( V_178 , & V_15 -> V_39 ) && F_19 ( V_15 ) &&
( V_29 -> V_18 & V_179 ) )
F_21 ( V_15 ) ;
F_49 ( V_51 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_108 ( V_175 ) )
return;
F_15 ( V_15 ) ;
if ( F_48 ( V_115 , & V_15 -> V_39 ) &&
! F_48 ( V_85 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_118 )
V_110 = V_15 -> V_79 ;
if ( F_73 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_31 ( V_15 ) ;
}
void F_109 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_150 ;
F_106 ( V_51 ) ;
F_95 () ;
F_96 ( & V_15 -> V_39 , V_85 , V_156 ) ;
}
void F_110 ( struct V_50 * V_51 )
{
F_106 ( V_51 ) ;
F_93 ( V_51 ) ;
}
int F_111 ( struct V_1 * V_2 , V_7 V_120 ,
const struct V_28 * V_29 ,
unsigned int V_86 , int V_147 , struct V_50 * V_51 )
{
struct V_14 * V_15 ;
int error ;
error = F_74 ( V_2 , V_120 , V_29 , V_180 , & V_15 ) ;
if ( ! error ) {
error = F_112 ( V_15 , V_86 , V_147 , V_51 ) ;
F_31 ( V_15 ) ;
}
return error ;
}
static int F_113 ( const void * V_181 , const void * V_182 )
{
const struct V_50 * V_183 = * ( const struct V_50 * * ) V_181 ;
const struct V_50 * V_184 = * ( const struct V_50 * * ) V_182 ;
const struct V_3 * V_185 = & V_183 -> V_150 -> V_49 ;
const struct V_3 * V_186 = & V_184 -> V_150 -> V_49 ;
if ( V_185 -> V_6 > V_186 -> V_6 )
return 1 ;
if ( V_185 -> V_6 < V_186 -> V_6 )
return - 1 ;
F_114 ( V_183 -> V_150 -> V_17 -> V_125 == V_184 -> V_150 -> V_17 -> V_125 ) ;
return 0 ;
}
static int F_115 ( unsigned int V_187 , struct V_50 * V_188 ,
struct V_50 * * V_189 )
{
unsigned int V_190 ;
int error = 0 ;
for ( V_190 = 0 ; V_190 < V_187 ; V_190 ++ )
V_189 [ V_190 ] = & V_188 [ V_190 ] ;
F_116 ( V_189 , V_187 , sizeof( struct V_50 * ) , F_113 , NULL ) ;
for ( V_190 = 0 ; V_190 < V_187 ; V_190 ++ ) {
V_189 [ V_190 ] -> V_57 &= ~ ( V_70 | V_174 ) ;
error = F_104 ( V_189 [ V_190 ] ) ;
if ( error ) {
while ( V_190 -- )
F_106 ( V_189 [ V_190 ] ) ;
break;
}
}
return error ;
}
int F_117 ( unsigned int V_187 , struct V_50 * V_188 )
{
struct V_50 * V_65 [ 4 ] ;
struct V_50 * * V_191 = V_65 ;
int error = 0 ;
switch( V_187 ) {
case 0 :
return 0 ;
case 1 :
V_188 -> V_57 &= ~ ( V_70 | V_174 ) ;
return F_104 ( V_188 ) ;
default:
if ( V_187 <= 4 )
break;
V_191 = F_118 ( V_187 * sizeof( struct V_50 * ) , V_129 ) ;
if ( ! V_191 )
return - V_130 ;
}
error = F_115 ( V_187 , V_188 , V_191 ) ;
if ( V_191 != V_65 )
F_10 ( V_191 ) ;
return error ;
}
void F_119 ( unsigned int V_187 , struct V_50 * V_188 )
{
while ( V_187 -- )
F_106 ( & V_188 [ V_187 ] ) ;
}
void F_120 ( struct V_14 * V_15 , unsigned int V_86 )
{
unsigned long V_110 = 0 ;
unsigned long V_116 ;
unsigned long V_117 = V_83 ;
F_15 ( V_15 ) ;
V_116 = V_15 -> V_82 + V_15 -> V_79 ;
if ( F_48 ( V_77 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_118 ) {
if ( F_72 ( V_117 , V_116 ) )
V_110 = V_116 - V_117 ;
if ( F_48 ( V_113 , & V_15 -> V_39 ) )
V_110 = V_15 -> V_79 ;
}
F_22 ( & V_15 -> V_89 ) ;
F_99 ( V_15 , V_86 , V_110 , true ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_73 ( V_119 , & V_15 -> V_111 , V_110 ) == 0 )
F_31 ( V_15 ) ;
}
static int F_121 ( const struct V_14 * V_15 )
{
const struct V_50 * V_51 ;
if ( V_15 -> V_114 & ~ V_87 )
return 0 ;
if ( V_15 -> V_78 == V_31 )
return 0 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( F_48 ( V_66 , & V_51 -> V_63 ) )
continue;
if ( V_172 & V_51 -> V_57 )
return 0 ;
}
return 1 ;
}
void F_122 ( struct V_14 * V_15 , int V_64 )
{
struct V_192 * V_193 = & V_15 -> V_24 -> V_45 ;
F_22 ( & V_15 -> V_89 ) ;
V_15 -> V_114 = V_64 ;
if ( F_58 ( F_48 ( V_194 , & V_193 -> V_195 ) ) ) {
if ( F_121 ( V_15 ) ) {
F_26 ( V_173 , & V_15 -> V_39 ) ;
F_27 ( & V_15 -> V_89 ) ;
return;
}
}
V_15 -> V_27 . V_76 ++ ;
F_26 ( V_113 , & V_15 -> V_39 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_73 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
F_31 ( V_15 ) ;
}
static int F_123 ( void * V_196 , struct V_197 * V_185 , struct V_197 * V_186 )
{
struct V_14 * V_198 , * V_199 ;
V_198 = F_42 ( V_185 , struct V_14 , V_35 ) ;
V_199 = F_42 ( V_186 , struct V_14 , V_35 ) ;
if ( V_198 -> V_49 . V_6 > V_199 -> V_49 . V_6 )
return 1 ;
if ( V_198 -> V_49 . V_6 < V_199 -> V_49 . V_6 )
return - 1 ;
return 0 ;
}
static void F_124 ( struct V_197 * V_200 )
__releases( &lru_lock
static long F_125 ( int V_201 )
{
struct V_14 * V_15 ;
F_126 ( V_202 ) ;
F_126 ( V_203 ) ;
long V_204 = 0 ;
F_22 ( & V_34 ) ;
while ( ( V_201 -- >= 0 ) && ! F_20 ( & V_37 ) ) {
V_15 = F_42 ( V_37 . V_53 , struct V_14 , V_35 ) ;
if ( ! F_48 ( V_97 , & V_15 -> V_39 ) ) {
F_127 ( & V_15 -> V_35 , & V_203 ) ;
F_29 ( & V_36 ) ;
V_204 ++ ;
continue;
}
F_127 ( & V_15 -> V_35 , & V_202 ) ;
}
F_128 ( & V_202 , & V_37 ) ;
if ( ! F_20 ( & V_203 ) )
F_124 ( & V_203 ) ;
F_27 ( & V_34 ) ;
return V_204 ;
}
static unsigned long F_129 ( struct V_205 * V_206 ,
struct V_207 * V_208 )
{
if ( ! ( V_208 -> V_209 & V_210 ) )
return V_211 ;
return F_125 ( V_208 -> V_212 ) ;
}
static unsigned long F_130 ( struct V_205 * V_206 ,
struct V_207 * V_208 )
{
return F_131 ( F_132 ( & V_36 ) ) ;
}
static void F_133 ( T_2 V_213 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_214 * V_215 = & V_11 [ V_10 ] ;
struct V_48 * V_216 ;
F_75 () ;
F_38 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_24 == V_2 ) && F_40 ( & V_15 -> V_27 ) )
V_213 ( V_15 ) ;
}
F_76 () ;
F_134 () ;
}
static void F_135 ( T_2 V_213 , const struct V_1 * V_2 )
{
unsigned V_190 ;
for ( V_190 = 0 ; V_190 < V_217 ; V_190 ++ )
F_133 ( V_213 , V_2 , V_190 ) ;
}
static void F_136 ( struct V_14 * V_15 )
{
if ( ! F_62 ( V_173 , & V_15 -> V_39 ) )
goto V_94;
F_26 ( V_113 , & V_15 -> V_39 ) ;
if ( F_73 ( V_119 , & V_15 -> V_111 , 0 ) == 0 ) {
V_94:
F_31 ( V_15 ) ;
}
}
static void F_137 ( struct V_14 * V_15 )
{
F_28 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_15 -> V_30 != V_31 )
F_99 ( V_15 , V_31 , 0 , false ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_73 ( V_119 , & V_15 -> V_111 , 0 ) == 0 )
F_31 ( V_15 ) ;
}
void F_138 ( struct V_1 * V_2 )
{
F_135 ( F_136 , V_2 ) ;
}
static void F_139 ( struct V_164 * V_165 , struct V_14 * V_15 )
{
F_22 ( & V_15 -> V_89 ) ;
F_140 ( V_165 , V_15 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static void F_141 ( struct V_14 * V_15 )
{
F_139 ( NULL , V_15 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
F_26 ( V_218 , & V_2 -> V_171 ) ;
F_143 ( V_119 ) ;
F_135 ( F_137 , V_2 ) ;
F_143 ( V_119 ) ;
F_144 ( V_2 -> V_26 , F_132 ( & V_2 -> V_25 ) == 0 ) ;
F_135 ( F_141 , V_2 ) ;
}
void F_145 ( struct V_103 * V_104 )
{
struct V_14 * V_15 = V_104 -> V_219 ;
int V_64 ;
V_64 = F_146 ( V_104 ) ;
F_147 ( V_15 -> V_24 , V_64 == 0 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_97 , & V_15 -> V_39 ) ;
F_64 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static const char * F_148 ( unsigned V_86 )
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
static const char * F_149 ( char * V_220 , unsigned V_147 , unsigned long V_221 )
{
char * V_189 = V_220 ;
if ( V_147 & V_70 )
* V_189 ++ = 't' ;
if ( V_147 & V_71 )
* V_189 ++ = 'T' ;
if ( V_147 & V_172 )
* V_189 ++ = 'e' ;
if ( V_147 & V_61 )
* V_189 ++ = 'A' ;
if ( V_147 & V_92 )
* V_189 ++ = 'p' ;
if ( V_147 & V_174 )
* V_189 ++ = 'a' ;
if ( V_147 & V_58 )
* V_189 ++ = 'E' ;
if ( V_147 & V_176 )
* V_189 ++ = 'c' ;
if ( F_48 ( V_66 , & V_221 ) )
* V_189 ++ = 'H' ;
if ( F_48 ( V_62 , & V_221 ) )
* V_189 ++ = 'W' ;
if ( F_48 ( V_222 , & V_221 ) )
* V_189 ++ = 'F' ;
* V_189 = 0 ;
return V_220 ;
}
static void F_150 ( struct V_164 * V_165 , const struct V_50 * V_51 )
{
struct V_223 * V_224 = NULL ;
char V_225 [ 32 ] ;
F_75 () ;
if ( V_51 -> V_153 )
V_224 = F_151 ( V_51 -> V_153 , V_226 ) ;
F_101 ( V_165 , L_8 ,
F_148 ( V_51 -> V_55 ) ,
F_149 ( V_225 , V_51 -> V_57 , V_51 -> V_63 ) ,
V_51 -> V_68 ,
V_51 -> V_153 ? ( long ) F_152 ( V_51 -> V_153 ) : - 1 ,
V_224 ? V_224 -> V_227 : L_9 ,
( void * ) V_51 -> V_151 ) ;
F_76 () ;
}
static const char * F_153 ( char * V_220 , const struct V_14 * V_15 )
{
const unsigned long * V_228 = & V_15 -> V_39 ;
char * V_189 = V_220 ;
if ( F_48 ( V_97 , V_228 ) )
* V_189 ++ = 'l' ;
if ( F_48 ( V_85 , V_228 ) )
* V_189 ++ = 'D' ;
if ( F_48 ( V_115 , V_228 ) )
* V_189 ++ = 'd' ;
if ( F_48 ( V_90 , V_228 ) )
* V_189 ++ = 'p' ;
if ( F_48 ( V_229 , V_228 ) )
* V_189 ++ = 'y' ;
if ( F_48 ( V_178 , V_228 ) )
* V_189 ++ = 'f' ;
if ( F_48 ( V_230 , V_228 ) )
* V_189 ++ = 'i' ;
if ( F_48 ( V_113 , V_228 ) )
* V_189 ++ = 'r' ;
if ( F_48 ( V_231 , V_228 ) )
* V_189 ++ = 'I' ;
if ( F_48 ( V_173 , V_228 ) )
* V_189 ++ = 'F' ;
if ( F_48 ( V_77 , V_228 ) )
* V_189 ++ = 'q' ;
if ( F_48 ( V_38 , V_228 ) )
* V_189 ++ = 'L' ;
if ( V_15 -> V_107 )
* V_189 ++ = 'o' ;
if ( F_48 ( V_232 , V_228 ) )
* V_189 ++ = 'b' ;
* V_189 = 0 ;
return V_220 ;
}
void F_140 ( struct V_164 * V_165 , const struct V_14 * V_15 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned long long V_233 ;
const struct V_50 * V_51 ;
char V_234 [ 32 ] ;
V_233 = V_83 - V_15 -> V_162 ;
V_233 *= 1000000 / V_157 ;
if ( ! F_48 ( V_85 , & V_15 -> V_39 ) )
V_233 = 0 ;
F_101 ( V_165 , L_10 ,
F_148 ( V_15 -> V_30 ) ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
F_153 ( V_234 , V_15 ) ,
F_148 ( V_15 -> V_78 ) ,
F_148 ( V_15 -> V_84 ) , V_233 ,
F_132 ( & V_15 -> V_235 ) ,
F_132 ( & V_15 -> V_236 ) ,
( int ) V_15 -> V_27 . V_76 , V_15 -> V_79 ) ;
F_52 (gh, &gl->gl_holders, gh_list)
F_150 ( V_165 , V_51 ) ;
if ( V_15 -> V_30 != V_31 && V_29 -> V_237 )
V_29 -> V_237 ( V_165 , V_15 ) ;
}
static int F_154 ( struct V_164 * V_165 , void * V_238 )
{
struct V_14 * V_15 = V_238 ;
F_155 ( V_165 , L_11 ,
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
static int F_156 ( struct V_164 * V_165 , void * V_238 )
{
struct V_245 * V_246 = V_165 -> V_247 ;
struct V_1 * V_2 = V_246 -> V_2 ;
unsigned V_248 = V_246 -> V_10 >> 3 ;
unsigned V_249 = V_246 -> V_10 & 0x07 ;
T_3 V_250 ;
int V_251 ;
if ( V_248 == 0 && V_249 != 0 )
return 0 ;
F_155 ( V_165 , L_12 , V_252 [ V_248 ] ,
( V_248 == 0 ) ? L_13 : V_253 [ V_249 ] ) ;
F_157 (i) {
const struct V_254 * V_137 = F_158 ( V_2 -> V_136 , V_251 ) ;
if ( V_248 == 0 ) {
V_250 = V_251 ;
} else {
V_250 = V_137 -> V_137 [ V_248 - 1 ] . V_138 [ V_249 ] ;
}
F_155 ( V_165 , L_14 , ( long long ) V_250 ) ;
}
F_159 ( V_165 , '\n' ) ;
return 0 ;
}
int T_4 F_160 ( void )
{
unsigned V_251 ;
for( V_251 = 0 ; V_251 < V_217 ; V_251 ++ ) {
F_161 ( & V_11 [ V_251 ] ) ;
}
V_119 = F_162 ( L_15 , V_255 |
V_256 | V_257 , 0 ) ;
if ( ! V_119 )
return - V_130 ;
V_258 = F_162 ( L_16 ,
V_255 | V_257 ,
0 ) ;
if ( ! V_258 ) {
F_163 ( V_119 ) ;
return - V_130 ;
}
F_164 ( & V_259 ) ;
return 0 ;
}
void F_165 ( void )
{
F_166 ( & V_259 ) ;
F_163 ( V_119 ) ;
F_163 ( V_258 ) ;
}
static inline struct V_14 * F_167 ( unsigned V_10 )
{
return F_168 ( F_169 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_43 ) ;
}
static inline struct V_14 * F_170 ( struct V_14 * V_15 )
{
return F_168 ( F_171 ( V_15 -> V_43 . V_53 ) ,
struct V_14 , V_43 ) ;
}
static int F_172 ( struct V_245 * V_246 )
{
struct V_14 * V_15 ;
do {
V_15 = V_246 -> V_15 ;
if ( V_15 ) {
V_246 -> V_15 = F_170 ( V_15 ) ;
V_246 -> V_260 ++ ;
} else {
if ( V_246 -> V_10 >= V_217 ) {
F_76 () ;
return 1 ;
}
V_246 -> V_15 = F_167 ( V_246 -> V_10 ) ;
V_246 -> V_260 = 0 ;
}
while ( V_246 -> V_15 == NULL ) {
V_246 -> V_10 ++ ;
if ( V_246 -> V_10 >= V_217 ) {
F_76 () ;
return 1 ;
}
V_246 -> V_15 = F_167 ( V_246 -> V_10 ) ;
V_246 -> V_260 = 0 ;
}
} while ( V_246 -> V_2 != V_246 -> V_15 -> V_24 ||
F_17 ( & V_246 -> V_15 -> V_27 ) );
return 0 ;
}
static void * F_173 ( struct V_164 * V_165 , T_5 * V_216 )
{
struct V_245 * V_246 = V_165 -> V_247 ;
T_5 V_261 = * V_216 ;
if ( V_246 -> V_262 <= * V_216 )
V_261 = V_246 -> V_260 + ( * V_216 - V_246 -> V_262 ) ;
else
V_246 -> V_10 = 0 ;
V_246 -> V_260 = 0 ;
F_75 () ;
do {
if ( F_172 ( V_246 ) )
return NULL ;
} while ( V_261 -- );
V_246 -> V_262 = * V_216 ;
return V_246 -> V_15 ;
}
static void * F_174 ( struct V_164 * V_165 , void * V_238 ,
T_5 * V_216 )
{
struct V_245 * V_246 = V_165 -> V_247 ;
( * V_216 ) ++ ;
V_246 -> V_262 = * V_216 ;
if ( F_172 ( V_246 ) )
return NULL ;
return V_246 -> V_15 ;
}
static void F_175 ( struct V_164 * V_165 , void * V_238 )
{
struct V_245 * V_246 = V_165 -> V_247 ;
if ( V_246 -> V_15 )
F_76 () ;
V_246 -> V_15 = NULL ;
}
static int F_176 ( struct V_164 * V_165 , void * V_238 )
{
F_139 ( V_165 , V_238 ) ;
return 0 ;
}
static void * F_177 ( struct V_164 * V_165 , T_5 * V_216 )
{
struct V_245 * V_246 = V_165 -> V_247 ;
V_246 -> V_10 = * V_216 ;
if ( * V_216 >= V_263 )
return NULL ;
F_80 () ;
return V_264 ;
}
static void * F_178 ( struct V_164 * V_165 , void * V_238 ,
T_5 * V_216 )
{
struct V_245 * V_246 = V_165 -> V_247 ;
( * V_216 ) ++ ;
V_246 -> V_10 ++ ;
if ( V_246 -> V_10 >= V_263 ) {
F_82 () ;
return NULL ;
}
return V_264 ;
}
static void F_179 ( struct V_164 * V_165 , void * V_238 )
{
F_82 () ;
}
static int F_180 ( struct V_105 * V_105 , struct V_265 * V_265 )
{
int V_64 = F_181 ( V_265 , & V_266 ,
sizeof( struct V_245 ) ) ;
if ( V_64 == 0 ) {
struct V_164 * V_165 = V_265 -> V_148 ;
struct V_245 * V_246 = V_165 -> V_247 ;
V_246 -> V_2 = V_105 -> V_267 ;
V_165 -> V_220 = F_118 ( V_268 , V_269 | V_270 ) ;
if ( V_165 -> V_220 )
V_165 -> V_271 = V_268 ;
}
return V_64 ;
}
static int F_182 ( struct V_105 * V_105 , struct V_265 * V_265 )
{
int V_64 = F_181 ( V_265 , & V_272 ,
sizeof( struct V_245 ) ) ;
if ( V_64 == 0 ) {
struct V_164 * V_165 = V_265 -> V_148 ;
struct V_245 * V_246 = V_165 -> V_247 ;
V_246 -> V_2 = V_105 -> V_267 ;
V_165 -> V_220 = F_118 ( V_268 , V_269 | V_270 ) ;
if ( V_165 -> V_220 )
V_165 -> V_271 = V_268 ;
}
return V_64 ;
}
static int F_183 ( struct V_105 * V_105 , struct V_265 * V_265 )
{
int V_64 = F_181 ( V_265 , & V_273 ,
sizeof( struct V_245 ) ) ;
if ( V_64 == 0 ) {
struct V_164 * V_165 = V_265 -> V_148 ;
struct V_245 * V_246 = V_165 -> V_247 ;
V_246 -> V_2 = V_105 -> V_267 ;
}
return V_64 ;
}
int F_184 ( struct V_1 * V_2 )
{
struct V_274 * V_275 ;
V_275 = F_185 ( V_2 -> V_276 , V_277 ) ;
if ( F_186 ( V_275 ) )
goto V_278;
V_2 -> V_279 = V_275 ;
V_275 = F_187 ( L_17 ,
V_280 | V_281 ,
V_2 -> V_279 , V_2 ,
& V_282 ) ;
if ( F_186 ( V_275 ) )
goto V_278;
V_2 -> V_283 = V_275 ;
V_275 = F_187 ( L_18 ,
V_280 | V_281 ,
V_2 -> V_279 , V_2 ,
& V_284 ) ;
if ( F_186 ( V_275 ) )
goto V_278;
V_2 -> V_285 = V_275 ;
V_275 = F_187 ( L_19 ,
V_280 | V_281 ,
V_2 -> V_279 , V_2 ,
& V_286 ) ;
if ( F_186 ( V_275 ) )
goto V_278;
V_2 -> V_287 = V_275 ;
return 0 ;
V_278:
F_188 ( V_2 ) ;
return V_275 ? F_189 ( V_275 ) : - V_130 ;
}
void F_188 ( struct V_1 * V_2 )
{
if ( V_2 -> V_279 ) {
if ( V_2 -> V_283 ) {
F_190 ( V_2 -> V_283 ) ;
V_2 -> V_283 = NULL ;
}
if ( V_2 -> V_285 ) {
F_190 ( V_2 -> V_285 ) ;
V_2 -> V_285 = NULL ;
}
if ( V_2 -> V_287 ) {
F_190 ( V_2 -> V_287 ) ;
V_2 -> V_287 = NULL ;
}
F_190 ( V_2 -> V_279 ) ;
V_2 -> V_279 = NULL ;
}
}
int F_191 ( void )
{
V_277 = F_185 ( L_20 , NULL ) ;
if ( F_68 ( V_277 ) )
return F_189 ( V_277 ) ;
return V_277 ? 0 : - V_130 ;
}
void F_192 ( void )
{
F_190 ( V_277 ) ;
V_277 = NULL ;
}
