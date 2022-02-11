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
F_62 ( V_95 L_1 , V_15 -> V_78 , V_86 ) ;
F_16 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_89 ) ;
return;
}
if ( F_63 ( V_90 , & V_15 -> V_39 ) )
F_56 ( V_15 ) ;
if ( V_86 != V_31 ) {
if ( V_29 -> V_96 ) {
F_27 ( & V_15 -> V_89 ) ;
V_88 = V_29 -> V_96 ( V_15 , V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_88 ) {
F_47 ( V_15 , V_88 ) ;
goto V_94;
}
}
V_88 = F_51 ( V_15 ) ;
if ( V_88 == 2 )
goto V_97;
}
V_94:
F_30 ( V_98 , & V_15 -> V_39 ) ;
V_97:
F_27 ( & V_15 -> V_89 ) ;
}
static void F_61 ( struct V_14 * V_15 , struct V_50 * V_51 , unsigned int V_99 )
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
static void F_65 ( struct V_14 * V_15 , const int V_100 )
__releases( &gl->gl_spin
static void F_66 ( struct V_101 * V_102 )
{
struct V_14 * V_15 = F_8 ( V_102 , struct V_14 , V_103 ) ;
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_104 * V_105 ;
struct V_106 * V_106 ;
V_7 V_107 = V_15 -> V_49 . V_6 ;
V_105 = V_15 -> V_108 ;
if ( V_105 )
V_106 = F_67 ( V_2 -> V_109 , V_107 , 1 ) ;
else
V_106 = F_68 ( V_2 , V_107 , NULL , V_110 ) ;
if ( V_106 && ! F_69 ( V_106 ) ) {
F_70 ( V_106 ) ;
F_71 ( V_106 ) ;
}
F_32 ( V_15 ) ;
}
static void F_72 ( struct V_101 * V_102 )
{
unsigned long V_111 = 0 ;
struct V_14 * V_15 = F_8 ( V_102 , struct V_14 , V_112 . V_102 ) ;
int V_113 = 0 ;
if ( F_63 ( V_114 , & V_15 -> V_39 ) ) {
F_57 ( V_15 , V_15 -> V_115 ) ;
V_113 = 1 ;
}
F_22 ( & V_15 -> V_89 ) ;
if ( F_49 ( V_116 , & V_15 -> V_39 ) &&
V_15 -> V_30 != V_31 &&
V_15 -> V_84 != V_56 ) {
unsigned long V_117 , V_118 = V_83 ;
V_117 = V_15 -> V_82 + V_15 -> V_79 ;
if ( F_73 ( V_118 , V_117 ) )
V_111 = V_117 - V_118 ;
if ( ! V_111 ) {
F_30 ( V_116 , & V_15 -> V_39 ) ;
F_26 ( V_85 , & V_15 -> V_39 ) ;
}
}
F_65 ( V_15 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! V_111 )
F_32 ( V_15 ) ;
else {
if ( V_15 -> V_49 . V_8 != V_119 )
V_111 = 0 ;
if ( F_74 ( V_120 , & V_15 -> V_112 , V_111 ) == 0 )
F_32 ( V_15 ) ;
}
if ( V_113 )
F_32 ( V_15 ) ;
}
int F_75 ( struct V_1 * V_2 , V_7 V_121 ,
const struct V_28 * V_29 , int V_122 ,
struct V_14 * * V_123 )
{
struct V_124 * V_125 = V_2 -> V_109 ;
struct V_3 V_4 = { . V_6 = V_121 , . V_8 = V_29 -> V_126 } ;
struct V_14 * V_15 , * V_65 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_40 * V_41 ;
struct V_127 * V_128 ;
F_76 () ;
V_15 = F_38 ( V_10 , V_2 , & V_4 ) ;
F_77 () ;
* V_123 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_122 )
return - V_129 ;
if ( V_29 -> V_18 & V_19 )
V_128 = V_20 ;
else
V_128 = V_23 ;
V_15 = F_78 ( V_128 , V_130 ) ;
if ( ! V_15 )
return - V_131 ;
memset ( & V_15 -> V_21 , 0 , sizeof( struct V_132 ) ) ;
if ( V_29 -> V_18 & V_133 ) {
V_15 -> V_21 . V_22 = F_79 ( V_134 , V_130 ) ;
if ( ! V_15 -> V_21 . V_22 ) {
F_9 ( V_128 , V_15 ) ;
return - V_131 ;
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
V_15 -> V_135 = F_80 ( 0 , 0 ) ;
F_81 () ;
V_15 -> V_136 = F_82 ( V_2 -> V_137 ) -> V_138 [ V_29 -> V_126 ] ;
F_83 () ;
V_15 -> V_136 . V_139 [ V_140 ] = 0 ;
V_15 -> V_136 . V_139 [ V_141 ] = 0 ;
V_15 -> V_82 = V_83 ;
V_15 -> V_108 = NULL ;
V_15 -> V_79 = V_142 ;
F_84 ( & V_15 -> V_112 , F_72 ) ;
F_85 ( & V_15 -> V_103 , F_66 ) ;
V_41 = F_33 ( V_15 ) ;
if ( V_41 ) {
V_41 -> V_143 = & V_144 ;
V_41 -> V_145 = V_125 -> V_146 -> V_147 ;
V_41 -> V_148 = 0 ;
F_86 ( V_41 , V_149 ) ;
V_41 -> V_150 = NULL ;
V_41 -> V_151 = V_125 -> V_152 ;
V_41 -> V_153 = 0 ;
}
F_3 ( V_10 ) ;
V_65 = F_38 ( V_10 , V_2 , & V_4 ) ;
if ( V_65 ) {
F_5 ( V_10 ) ;
F_10 ( V_15 -> V_21 . V_22 ) ;
F_9 ( V_128 , V_15 ) ;
F_29 ( & V_2 -> V_25 ) ;
V_15 = V_65 ;
} else {
F_87 ( & V_15 -> V_43 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_123 = V_15 ;
return 0 ;
}
void F_88 ( struct V_14 * V_15 , unsigned int V_86 , unsigned V_148 ,
struct V_50 * V_51 )
{
F_89 ( & V_51 -> V_54 ) ;
V_51 -> V_154 = V_15 ;
V_51 -> V_155 = ( unsigned long ) F_90 ( 0 ) ;
V_51 -> V_156 = F_91 ( F_92 ( V_157 ) ) ;
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_148 ;
V_51 -> V_68 = 0 ;
V_51 -> V_63 = 0 ;
F_15 ( V_15 ) ;
}
void F_93 ( unsigned int V_86 , unsigned V_148 , struct V_50 * V_51 )
{
V_51 -> V_55 = V_86 ;
V_51 -> V_57 = V_148 ;
V_51 -> V_63 = 0 ;
V_51 -> V_155 = ( unsigned long ) F_90 ( 0 ) ;
if ( V_51 -> V_156 )
F_94 ( V_51 -> V_156 ) ;
V_51 -> V_156 = F_91 ( F_92 ( V_157 ) ) ;
}
void F_95 ( struct V_50 * V_51 )
{
F_94 ( V_51 -> V_156 ) ;
F_32 ( V_51 -> V_154 ) ;
V_51 -> V_154 = NULL ;
V_51 -> V_155 = 0 ;
}
static int F_96 ( void * V_158 )
{
F_97 () ;
return 0 ;
}
static int F_98 ( void * V_158 )
{
F_97 () ;
return 0 ;
}
int F_99 ( struct V_50 * V_51 )
{
unsigned long V_159 = V_83 ;
F_100 () ;
F_101 ( & V_51 -> V_63 , V_62 , F_96 , V_160 ) ;
if ( F_102 ( V_83 , V_159 + V_161 ) )
V_51 -> V_154 -> V_79 = F_103 ( V_51 -> V_154 -> V_79 +
V_162 ,
V_163 ) ;
return V_51 -> V_68 ;
}
static void F_104 ( struct V_14 * V_15 , unsigned int V_86 ,
unsigned long V_111 , bool V_164 )
{
int V_165 = V_111 ? V_116 : V_85 ;
F_26 ( V_165 , & V_15 -> V_39 ) ;
if ( V_15 -> V_84 == V_56 ) {
V_15 -> V_84 = V_86 ;
V_15 -> V_166 = V_83 ;
} else if ( V_15 -> V_84 != V_31 &&
V_15 -> V_84 != V_86 ) {
V_15 -> V_84 = V_31 ;
}
if ( V_15 -> V_17 -> V_167 )
V_15 -> V_17 -> V_167 ( V_15 , V_164 ) ;
F_105 ( V_15 , V_164 ) ;
}
void F_106 ( struct V_168 * V_169 , const char * V_170 , ... )
{
struct V_171 V_172 ;
T_1 args ;
va_start ( args , V_170 ) ;
if ( V_169 ) {
F_107 ( V_169 , V_170 , args ) ;
} else {
V_172 . V_170 = V_170 ;
V_172 . V_173 = & args ;
F_62 ( V_95 L_2 , & V_172 ) ;
}
va_end ( args ) ;
}
static inline void F_108 ( struct V_50 * V_51 )
__releases( &gl->gl_spin
int F_109 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_154 ;
struct V_1 * V_2 = V_15 -> V_24 ;
int error = 0 ;
if ( F_59 ( F_49 ( V_174 , & V_2 -> V_175 ) ) )
return - V_69 ;
if ( F_49 ( V_38 , & V_15 -> V_39 ) )
F_31 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_108 ( V_51 ) ;
if ( ( V_176 & V_51 -> V_57 ) &&
F_63 ( V_177 , & V_15 -> V_39 ) )
F_26 ( V_114 , & V_15 -> V_39 ) ;
F_65 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( ! ( V_51 -> V_57 & V_178 ) )
error = F_99 ( V_51 ) ;
return error ;
}
int F_110 ( struct V_50 * V_51 )
{
return F_49 ( V_62 , & V_51 -> V_63 ) ? 0 : 1 ;
}
void F_111 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_154 ;
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned V_111 = 0 ;
int V_179 = 0 ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_51 -> V_57 & V_180 )
F_104 ( V_15 , V_31 , 0 , false ) ;
F_23 ( & V_51 -> V_54 ) ;
if ( F_64 ( V_15 ) == NULL ) {
if ( V_29 -> V_181 ) {
F_16 ( V_15 , F_112 ( V_98 , & V_15 -> V_39 ) ) ;
F_27 ( & V_15 -> V_89 ) ;
V_29 -> V_181 ( V_51 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_98 , & V_15 -> V_39 ) ;
}
if ( F_20 ( & V_15 -> V_32 ) &&
! F_49 ( V_116 , & V_15 -> V_39 ) &&
! F_49 ( V_85 , & V_15 -> V_39 ) )
V_179 = 1 ;
}
if ( ! F_49 ( V_182 , & V_15 -> V_39 ) && F_19 ( V_15 ) )
F_21 ( V_15 ) ;
F_50 ( V_51 , 0 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_113 ( V_179 ) )
return;
F_15 ( V_15 ) ;
if ( F_49 ( V_116 , & V_15 -> V_39 ) &&
! F_49 ( V_85 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_119 )
V_111 = V_15 -> V_79 ;
if ( F_74 ( V_120 , & V_15 -> V_112 , V_111 ) == 0 )
F_32 ( V_15 ) ;
}
void F_114 ( struct V_50 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_154 ;
F_111 ( V_51 ) ;
F_100 () ;
F_101 ( & V_15 -> V_39 , V_85 , F_98 , V_160 ) ;
}
void F_115 ( struct V_50 * V_51 )
{
F_111 ( V_51 ) ;
F_95 ( V_51 ) ;
}
int F_116 ( struct V_1 * V_2 , V_7 V_121 ,
const struct V_28 * V_29 ,
unsigned int V_86 , int V_148 , struct V_50 * V_51 )
{
struct V_14 * V_15 ;
int error ;
error = F_75 ( V_2 , V_121 , V_29 , V_183 , & V_15 ) ;
if ( ! error ) {
error = F_117 ( V_15 , V_86 , V_148 , V_51 ) ;
F_32 ( V_15 ) ;
}
return error ;
}
static int F_118 ( const void * V_184 , const void * V_185 )
{
const struct V_50 * V_186 = * ( const struct V_50 * * ) V_184 ;
const struct V_50 * V_187 = * ( const struct V_50 * * ) V_185 ;
const struct V_3 * V_188 = & V_186 -> V_154 -> V_49 ;
const struct V_3 * V_189 = & V_187 -> V_154 -> V_49 ;
if ( V_188 -> V_6 > V_189 -> V_6 )
return 1 ;
if ( V_188 -> V_6 < V_189 -> V_6 )
return - 1 ;
F_119 ( V_186 -> V_154 -> V_17 -> V_126 == V_187 -> V_154 -> V_17 -> V_126 ) ;
return 0 ;
}
static int F_120 ( unsigned int V_190 , struct V_50 * V_191 ,
struct V_50 * * V_192 )
{
unsigned int V_193 ;
int error = 0 ;
for ( V_193 = 0 ; V_193 < V_190 ; V_193 ++ )
V_192 [ V_193 ] = & V_191 [ V_193 ] ;
F_121 ( V_192 , V_190 , sizeof( struct V_50 * ) , F_118 , NULL ) ;
for ( V_193 = 0 ; V_193 < V_190 ; V_193 ++ ) {
V_192 [ V_193 ] -> V_57 &= ~ ( V_70 | V_178 ) ;
error = F_109 ( V_192 [ V_193 ] ) ;
if ( error ) {
while ( V_193 -- )
F_111 ( V_192 [ V_193 ] ) ;
break;
}
}
return error ;
}
int F_122 ( unsigned int V_190 , struct V_50 * V_191 )
{
struct V_50 * V_65 [ 4 ] ;
struct V_50 * * V_194 = V_65 ;
int error = 0 ;
switch( V_190 ) {
case 0 :
return 0 ;
case 1 :
V_191 -> V_57 &= ~ ( V_70 | V_178 ) ;
return F_109 ( V_191 ) ;
default:
if ( V_190 <= 4 )
break;
V_194 = F_123 ( V_190 * sizeof( struct V_50 * ) , V_149 ) ;
if ( ! V_194 )
return - V_131 ;
}
error = F_120 ( V_190 , V_191 , V_194 ) ;
if ( V_194 != V_65 )
F_10 ( V_194 ) ;
return error ;
}
void F_124 ( unsigned int V_190 , struct V_50 * V_191 )
{
while ( V_190 -- )
F_111 ( & V_191 [ V_190 ] ) ;
}
void F_125 ( struct V_14 * V_15 , unsigned int V_86 )
{
unsigned long V_111 = 0 ;
unsigned long V_117 ;
unsigned long V_118 = V_83 ;
F_15 ( V_15 ) ;
V_117 = V_15 -> V_82 + V_15 -> V_79 ;
if ( F_49 ( V_77 , & V_15 -> V_39 ) &&
V_15 -> V_49 . V_8 == V_119 ) {
if ( F_73 ( V_118 , V_117 ) )
V_111 = V_117 - V_118 ;
if ( F_49 ( V_114 , & V_15 -> V_39 ) )
V_111 = V_15 -> V_79 ;
}
F_22 ( & V_15 -> V_89 ) ;
F_104 ( V_15 , V_86 , V_111 , true ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_120 , & V_15 -> V_112 , V_111 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_126 ( const struct V_14 * V_15 )
{
const struct V_50 * V_51 ;
if ( V_15 -> V_115 & ~ V_87 )
return 0 ;
if ( V_15 -> V_78 == V_31 )
return 0 ;
F_53 (gh, &gl->gl_holders, gh_list) {
if ( F_49 ( V_66 , & V_51 -> V_63 ) )
continue;
if ( V_176 & V_51 -> V_57 )
return 0 ;
}
return 1 ;
}
void F_127 ( struct V_14 * V_15 , int V_64 )
{
struct V_195 * V_196 = & V_15 -> V_24 -> V_45 ;
F_22 ( & V_15 -> V_89 ) ;
V_15 -> V_115 = V_64 ;
if ( F_59 ( F_49 ( V_197 , & V_196 -> V_198 ) ) ) {
if ( F_126 ( V_15 ) ) {
F_26 ( V_177 , & V_15 -> V_39 ) ;
F_27 ( & V_15 -> V_89 ) ;
return;
}
}
V_15 -> V_27 . V_76 ++ ;
F_26 ( V_114 , & V_15 -> V_39 ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_120 , & V_15 -> V_112 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_128 ( void * V_199 , struct V_200 * V_188 , struct V_200 * V_189 )
{
struct V_14 * V_201 , * V_202 ;
V_201 = F_43 ( V_188 , struct V_14 , V_35 ) ;
V_202 = F_43 ( V_189 , struct V_14 , V_35 ) ;
if ( V_201 -> V_49 . V_6 > V_202 -> V_49 . V_6 )
return 1 ;
if ( V_201 -> V_49 . V_6 < V_202 -> V_49 . V_6 )
return - 1 ;
return 0 ;
}
static void F_129 ( struct V_200 * V_203 )
__releases( &lru_lock
static long F_130 ( int V_204 )
{
struct V_14 * V_15 ;
F_131 ( V_205 ) ;
F_131 ( V_206 ) ;
long V_207 = 0 ;
F_22 ( & V_34 ) ;
while ( ( V_204 -- >= 0 ) && ! F_20 ( & V_37 ) ) {
V_15 = F_43 ( V_37 . V_53 , struct V_14 , V_35 ) ;
if ( ! F_112 ( V_98 , & V_15 -> V_39 ) ) {
F_132 ( & V_15 -> V_35 , & V_206 ) ;
F_29 ( & V_36 ) ;
V_207 ++ ;
continue;
}
F_132 ( & V_15 -> V_35 , & V_205 ) ;
}
F_133 ( & V_205 , & V_37 ) ;
if ( ! F_20 ( & V_206 ) )
F_129 ( & V_206 ) ;
F_27 ( & V_34 ) ;
return V_207 ;
}
static unsigned long F_134 ( struct V_208 * V_209 ,
struct V_210 * V_211 )
{
if ( ! ( V_211 -> V_212 & V_213 ) )
return V_214 ;
return F_130 ( V_211 -> V_215 ) ;
}
static unsigned long F_135 ( struct V_208 * V_209 ,
struct V_210 * V_211 )
{
return F_136 ( F_137 ( & V_36 ) ) ;
}
static void F_138 ( T_2 V_216 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_217 * V_218 = & V_11 [ V_10 ] ;
struct V_48 * V_219 ;
F_76 () ;
F_39 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_24 == V_2 ) && F_41 ( & V_15 -> V_27 ) )
V_216 ( V_15 ) ;
}
F_77 () ;
F_139 () ;
}
static void F_140 ( T_2 V_216 , const struct V_1 * V_2 )
{
unsigned V_193 ;
for ( V_193 = 0 ; V_193 < V_220 ; V_193 ++ )
F_138 ( V_216 , V_2 , V_193 ) ;
}
static void F_141 ( struct V_14 * V_15 )
{
if ( ! F_63 ( V_177 , & V_15 -> V_39 ) )
goto V_94;
F_26 ( V_114 , & V_15 -> V_39 ) ;
if ( F_74 ( V_120 , & V_15 -> V_112 , 0 ) == 0 ) {
V_94:
F_32 ( V_15 ) ;
}
}
static void F_142 ( struct V_14 * V_15 )
{
F_31 ( V_15 ) ;
F_22 ( & V_15 -> V_89 ) ;
if ( V_15 -> V_30 != V_31 )
F_104 ( V_15 , V_31 , 0 , false ) ;
F_27 ( & V_15 -> V_89 ) ;
if ( F_74 ( V_120 , & V_15 -> V_112 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
void F_143 ( struct V_1 * V_2 )
{
F_140 ( F_141 , V_2 ) ;
}
static void F_144 ( struct V_168 * V_169 , struct V_14 * V_15 )
{
F_22 ( & V_15 -> V_89 ) ;
F_145 ( V_169 , V_15 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static void F_146 ( struct V_14 * V_15 )
{
F_144 ( NULL , V_15 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
F_26 ( V_221 , & V_2 -> V_175 ) ;
F_148 ( V_120 ) ;
F_140 ( F_142 , V_2 ) ;
F_148 ( V_120 ) ;
F_149 ( V_2 -> V_26 , F_137 ( & V_2 -> V_25 ) == 0 ) ;
F_140 ( F_146 , V_2 ) ;
}
void F_150 ( struct V_104 * V_105 )
{
struct V_14 * V_15 = V_105 -> V_222 ;
int V_64 ;
V_64 = F_151 ( V_105 ) ;
F_152 ( V_15 -> V_24 , V_64 == 0 ) ;
F_22 ( & V_15 -> V_89 ) ;
F_30 ( V_98 , & V_15 -> V_39 ) ;
F_65 ( V_15 , 1 ) ;
F_27 ( & V_15 -> V_89 ) ;
}
static const char * F_153 ( unsigned V_86 )
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
static const char * F_154 ( char * V_223 , unsigned V_148 , unsigned long V_224 )
{
char * V_192 = V_223 ;
if ( V_148 & V_70 )
* V_192 ++ = 't' ;
if ( V_148 & V_71 )
* V_192 ++ = 'T' ;
if ( V_148 & V_176 )
* V_192 ++ = 'e' ;
if ( V_148 & V_61 )
* V_192 ++ = 'A' ;
if ( V_148 & V_92 )
* V_192 ++ = 'p' ;
if ( V_148 & V_178 )
* V_192 ++ = 'a' ;
if ( V_148 & V_58 )
* V_192 ++ = 'E' ;
if ( V_148 & V_180 )
* V_192 ++ = 'c' ;
if ( F_49 ( V_66 , & V_224 ) )
* V_192 ++ = 'H' ;
if ( F_49 ( V_62 , & V_224 ) )
* V_192 ++ = 'W' ;
if ( F_49 ( V_225 , & V_224 ) )
* V_192 ++ = 'F' ;
* V_192 = 0 ;
return V_223 ;
}
static void F_155 ( struct V_168 * V_169 , const struct V_50 * V_51 )
{
struct V_226 * V_227 = NULL ;
char V_228 [ 32 ] ;
F_76 () ;
if ( V_51 -> V_156 )
V_227 = F_156 ( V_51 -> V_156 , V_229 ) ;
F_106 ( V_169 , L_8 ,
F_153 ( V_51 -> V_55 ) ,
F_154 ( V_228 , V_51 -> V_57 , V_51 -> V_63 ) ,
V_51 -> V_68 ,
V_51 -> V_156 ? ( long ) F_157 ( V_51 -> V_156 ) : - 1 ,
V_227 ? V_227 -> V_230 : L_9 ,
( void * ) V_51 -> V_155 ) ;
F_77 () ;
}
static const char * F_158 ( char * V_223 , const struct V_14 * V_15 )
{
const unsigned long * V_231 = & V_15 -> V_39 ;
char * V_192 = V_223 ;
if ( F_49 ( V_98 , V_231 ) )
* V_192 ++ = 'l' ;
if ( F_49 ( V_85 , V_231 ) )
* V_192 ++ = 'D' ;
if ( F_49 ( V_116 , V_231 ) )
* V_192 ++ = 'd' ;
if ( F_49 ( V_90 , V_231 ) )
* V_192 ++ = 'p' ;
if ( F_49 ( V_232 , V_231 ) )
* V_192 ++ = 'y' ;
if ( F_49 ( V_182 , V_231 ) )
* V_192 ++ = 'f' ;
if ( F_49 ( V_233 , V_231 ) )
* V_192 ++ = 'i' ;
if ( F_49 ( V_114 , V_231 ) )
* V_192 ++ = 'r' ;
if ( F_49 ( V_234 , V_231 ) )
* V_192 ++ = 'I' ;
if ( F_49 ( V_177 , V_231 ) )
* V_192 ++ = 'F' ;
if ( F_49 ( V_77 , V_231 ) )
* V_192 ++ = 'q' ;
if ( F_49 ( V_38 , V_231 ) )
* V_192 ++ = 'L' ;
if ( V_15 -> V_108 )
* V_192 ++ = 'o' ;
if ( F_49 ( V_235 , V_231 ) )
* V_192 ++ = 'b' ;
* V_192 = 0 ;
return V_223 ;
}
void F_145 ( struct V_168 * V_169 , const struct V_14 * V_15 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned long long V_236 ;
const struct V_50 * V_51 ;
char V_237 [ 32 ] ;
V_236 = V_83 - V_15 -> V_166 ;
V_236 *= 1000000 / V_161 ;
if ( ! F_49 ( V_85 , & V_15 -> V_39 ) )
V_236 = 0 ;
F_106 ( V_169 , L_10 ,
F_153 ( V_15 -> V_30 ) ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
F_158 ( V_237 , V_15 ) ,
F_153 ( V_15 -> V_78 ) ,
F_153 ( V_15 -> V_84 ) , V_236 ,
F_137 ( & V_15 -> V_238 ) ,
F_137 ( & V_15 -> V_239 ) ,
( int ) V_15 -> V_27 . V_76 , V_15 -> V_79 ) ;
F_53 (gh, &gl->gl_holders, gh_list)
F_155 ( V_169 , V_51 ) ;
if ( V_15 -> V_30 != V_31 && V_29 -> V_240 )
V_29 -> V_240 ( V_169 , V_15 ) ;
}
static int F_159 ( struct V_168 * V_169 , void * V_241 )
{
struct V_14 * V_15 = V_241 ;
F_160 ( V_169 , L_11 ,
V_15 -> V_49 . V_8 ,
( unsigned long long ) V_15 -> V_49 . V_6 ,
( long long ) V_15 -> V_136 . V_139 [ V_242 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_243 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_244 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_245 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_246 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_247 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_140 ] ,
( long long ) V_15 -> V_136 . V_139 [ V_141 ] ) ;
return 0 ;
}
static int F_161 ( struct V_168 * V_169 , void * V_241 )
{
struct V_248 * V_249 = V_169 -> V_250 ;
struct V_1 * V_2 = V_249 -> V_2 ;
unsigned V_251 = V_249 -> V_10 >> 3 ;
unsigned V_252 = V_249 -> V_10 & 0x07 ;
T_3 V_253 ;
int V_254 ;
if ( V_251 == 0 && V_252 != 0 )
return 0 ;
F_160 ( V_169 , L_12 , V_255 [ V_251 ] ,
( V_251 == 0 ) ? L_13 : V_256 [ V_252 ] ) ;
F_162 (i) {
const struct V_257 * V_138 = F_163 ( V_2 -> V_137 , V_254 ) ;
if ( V_251 == 0 ) {
V_253 = V_254 ;
} else {
V_253 = V_138 -> V_138 [ V_251 - 1 ] . V_139 [ V_252 ] ;
}
F_160 ( V_169 , L_14 , ( long long ) V_253 ) ;
}
F_164 ( V_169 , '\n' ) ;
return 0 ;
}
int T_4 F_165 ( void )
{
unsigned V_254 ;
for( V_254 = 0 ; V_254 < V_220 ; V_254 ++ ) {
F_166 ( & V_11 [ V_254 ] ) ;
}
V_120 = F_167 ( L_15 , V_258 |
V_259 | V_260 , 0 ) ;
if ( ! V_120 )
return - V_131 ;
V_261 = F_167 ( L_16 ,
V_258 | V_260 ,
0 ) ;
if ( ! V_261 ) {
F_168 ( V_120 ) ;
return - V_131 ;
}
F_169 ( & V_262 ) ;
return 0 ;
}
void F_170 ( void )
{
F_171 ( & V_262 ) ;
F_168 ( V_120 ) ;
F_168 ( V_261 ) ;
}
static inline struct V_14 * F_172 ( unsigned V_10 )
{
return F_173 ( F_174 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_43 ) ;
}
static inline struct V_14 * F_175 ( struct V_14 * V_15 )
{
return F_173 ( F_176 ( V_15 -> V_43 . V_53 ) ,
struct V_14 , V_43 ) ;
}
static int F_177 ( struct V_248 * V_249 )
{
struct V_14 * V_15 ;
do {
V_15 = V_249 -> V_15 ;
if ( V_15 ) {
V_249 -> V_15 = F_175 ( V_15 ) ;
V_249 -> V_263 ++ ;
} else {
if ( V_249 -> V_10 >= V_220 ) {
F_77 () ;
return 1 ;
}
V_249 -> V_15 = F_172 ( V_249 -> V_10 ) ;
V_249 -> V_263 = 0 ;
}
while ( V_249 -> V_15 == NULL ) {
V_249 -> V_10 ++ ;
if ( V_249 -> V_10 >= V_220 ) {
F_77 () ;
return 1 ;
}
V_249 -> V_15 = F_172 ( V_249 -> V_10 ) ;
V_249 -> V_263 = 0 ;
}
} while ( V_249 -> V_2 != V_249 -> V_15 -> V_24 ||
F_17 ( & V_249 -> V_15 -> V_27 ) );
return 0 ;
}
static void * F_178 ( struct V_168 * V_169 , T_5 * V_219 )
{
struct V_248 * V_249 = V_169 -> V_250 ;
T_5 V_264 = * V_219 ;
if ( V_249 -> V_265 <= * V_219 )
V_264 = V_249 -> V_263 + ( * V_219 - V_249 -> V_265 ) ;
else
V_249 -> V_10 = 0 ;
V_249 -> V_263 = 0 ;
F_76 () ;
do {
if ( F_177 ( V_249 ) )
return NULL ;
} while ( V_264 -- );
V_249 -> V_265 = * V_219 ;
return V_249 -> V_15 ;
}
static void * F_179 ( struct V_168 * V_169 , void * V_241 ,
T_5 * V_219 )
{
struct V_248 * V_249 = V_169 -> V_250 ;
( * V_219 ) ++ ;
V_249 -> V_265 = * V_219 ;
if ( F_177 ( V_249 ) )
return NULL ;
return V_249 -> V_15 ;
}
static void F_180 ( struct V_168 * V_169 , void * V_241 )
{
struct V_248 * V_249 = V_169 -> V_250 ;
if ( V_249 -> V_15 )
F_77 () ;
V_249 -> V_15 = NULL ;
}
static int F_181 ( struct V_168 * V_169 , void * V_241 )
{
F_144 ( V_169 , V_241 ) ;
return 0 ;
}
static void * F_182 ( struct V_168 * V_169 , T_5 * V_219 )
{
struct V_248 * V_249 = V_169 -> V_250 ;
V_249 -> V_10 = * V_219 ;
if ( * V_219 >= V_266 )
return NULL ;
F_81 () ;
return V_267 ;
}
static void * F_183 ( struct V_168 * V_169 , void * V_241 ,
T_5 * V_219 )
{
struct V_248 * V_249 = V_169 -> V_250 ;
( * V_219 ) ++ ;
V_249 -> V_10 ++ ;
if ( V_249 -> V_10 >= V_266 ) {
F_83 () ;
return NULL ;
}
return V_267 ;
}
static void F_184 ( struct V_168 * V_169 , void * V_241 )
{
F_83 () ;
}
static int F_185 ( struct V_106 * V_106 , struct V_268 * V_268 )
{
int V_64 = F_186 ( V_268 , & V_269 ,
sizeof( struct V_248 ) ) ;
if ( V_64 == 0 ) {
struct V_168 * V_169 = V_268 -> V_150 ;
struct V_248 * V_249 = V_169 -> V_250 ;
V_249 -> V_2 = V_106 -> V_270 ;
V_169 -> V_223 = F_123 ( V_271 , V_130 | V_272 ) ;
if ( V_169 -> V_223 )
V_169 -> V_273 = V_271 ;
}
return V_64 ;
}
static int F_187 ( struct V_106 * V_106 , struct V_268 * V_268 )
{
int V_64 = F_186 ( V_268 , & V_274 ,
sizeof( struct V_248 ) ) ;
if ( V_64 == 0 ) {
struct V_168 * V_169 = V_268 -> V_150 ;
struct V_248 * V_249 = V_169 -> V_250 ;
V_249 -> V_2 = V_106 -> V_270 ;
V_169 -> V_223 = F_123 ( V_271 , V_130 | V_272 ) ;
if ( V_169 -> V_223 )
V_169 -> V_273 = V_271 ;
}
return V_64 ;
}
static int F_188 ( struct V_106 * V_106 , struct V_268 * V_268 )
{
int V_64 = F_186 ( V_268 , & V_275 ,
sizeof( struct V_248 ) ) ;
if ( V_64 == 0 ) {
struct V_168 * V_169 = V_268 -> V_150 ;
struct V_248 * V_249 = V_169 -> V_250 ;
V_249 -> V_2 = V_106 -> V_270 ;
}
return V_64 ;
}
int F_189 ( struct V_1 * V_2 )
{
V_2 -> V_276 = F_190 ( V_2 -> V_277 , V_278 ) ;
if ( ! V_2 -> V_276 )
return - V_131 ;
V_2 -> V_279 = F_191 ( L_17 ,
V_280 | V_281 ,
V_2 -> V_276 , V_2 ,
& V_282 ) ;
if ( ! V_2 -> V_279 )
goto V_283;
V_2 -> V_284 = F_191 ( L_18 ,
V_280 | V_281 ,
V_2 -> V_276 , V_2 ,
& V_285 ) ;
if ( ! V_2 -> V_284 )
goto V_283;
V_2 -> V_286 = F_191 ( L_19 ,
V_280 | V_281 ,
V_2 -> V_276 , V_2 ,
& V_287 ) ;
if ( ! V_2 -> V_286 )
goto V_283;
return 0 ;
V_283:
F_192 ( V_2 ) ;
return - V_131 ;
}
void F_192 ( struct V_1 * V_2 )
{
if ( V_2 -> V_276 ) {
if ( V_2 -> V_279 ) {
F_193 ( V_2 -> V_279 ) ;
V_2 -> V_279 = NULL ;
}
if ( V_2 -> V_284 ) {
F_193 ( V_2 -> V_284 ) ;
V_2 -> V_284 = NULL ;
}
if ( V_2 -> V_286 ) {
F_193 ( V_2 -> V_286 ) ;
V_2 -> V_286 = NULL ;
}
F_193 ( V_2 -> V_276 ) ;
V_2 -> V_276 = NULL ;
}
}
int F_194 ( void )
{
V_278 = F_190 ( L_20 , NULL ) ;
return V_278 ? 0 : - V_131 ;
}
void F_195 ( void )
{
F_193 ( V_278 ) ;
V_278 = NULL ;
}
