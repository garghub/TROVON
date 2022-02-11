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
if ( V_15 -> V_17 -> V_18 & V_19 )
F_9 ( V_20 , V_15 ) ;
else
F_9 ( V_21 , V_15 ) ;
}
void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_22 ;
F_11 ( & V_15 -> V_16 , F_7 ) ;
if ( F_12 ( & V_2 -> V_23 ) )
F_13 ( & V_2 -> V_24 ) ;
}
void F_14 ( struct V_14 * V_15 )
{
F_15 ( V_15 , F_16 ( & V_15 -> V_25 ) == 0 ) ;
F_17 ( & V_15 -> V_25 ) ;
}
static int F_18 ( const struct V_14 * V_15 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
if ( V_15 -> V_28 == V_29 )
return 0 ;
if ( ! F_19 ( & V_15 -> V_30 ) )
return 0 ;
if ( V_27 -> V_31 )
return V_27 -> V_31 ( V_15 ) ;
return 1 ;
}
void F_20 ( struct V_14 * V_15 )
{
F_21 ( & V_32 ) ;
if ( ! F_19 ( & V_15 -> V_33 ) )
F_22 ( & V_15 -> V_33 ) ;
else
F_17 ( & V_34 ) ;
F_23 ( & V_15 -> V_33 , & V_35 ) ;
F_24 ( V_36 , & V_15 -> V_37 ) ;
F_25 ( & V_32 ) ;
}
static void F_26 ( struct V_14 * V_15 )
{
if ( ! F_19 ( & V_15 -> V_33 ) ) {
F_22 ( & V_15 -> V_33 ) ;
F_27 ( & V_34 ) ;
F_28 ( V_36 , & V_15 -> V_37 ) ;
}
}
static void F_29 ( struct V_14 * V_15 )
{
F_21 ( & V_32 ) ;
F_26 ( V_15 ) ;
F_25 ( & V_32 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
if ( F_18 ( V_15 ) )
F_20 ( V_15 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
if ( F_12 ( & V_15 -> V_25 ) )
F_15 ( V_15 , 1 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_22 ;
struct V_38 * V_39 = F_33 ( V_15 ) ;
if ( F_34 ( & V_15 -> V_25 , & V_32 ) ) {
F_26 ( V_15 ) ;
F_25 ( & V_32 ) ;
F_3 ( V_15 -> F_1 ) ;
F_35 ( & V_15 -> V_40 ) ;
F_5 ( V_15 -> F_1 ) ;
F_15 ( V_15 , ! F_19 ( & V_15 -> V_30 ) ) ;
F_15 ( V_15 , V_39 && V_39 -> V_41 ) ;
F_36 ( V_15 ) ;
V_2 -> V_42 . V_43 -> V_44 ( V_15 ) ;
}
}
static struct V_14 * F_37 ( unsigned int V_10 ,
const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_45 * V_5 ;
F_38 (gl, h, &gl_hash_table[hash], gl_list) {
if ( ! F_39 ( & V_15 -> V_46 , V_4 ) )
continue;
if ( V_15 -> V_22 != V_2 )
continue;
if ( F_40 ( & V_15 -> V_25 ) )
return V_15 ;
}
return NULL ;
}
static inline int F_41 ( const struct V_14 * V_15 , const struct V_47 * V_48 )
{
const struct V_47 * V_49 = F_42 ( V_15 -> V_30 . V_50 , const struct V_47 , V_51 ) ;
if ( ( V_48 -> V_52 == V_53 ||
V_49 -> V_52 == V_53 ) && V_48 != V_49 )
return 0 ;
if ( V_15 -> V_28 == V_48 -> V_52 )
return 1 ;
if ( V_48 -> V_54 & V_55 )
return 0 ;
if ( V_15 -> V_28 == V_53 ) {
if ( V_48 -> V_52 == V_56 && V_49 -> V_52 == V_56 )
return 1 ;
if ( V_48 -> V_52 == V_57 && V_49 -> V_52 == V_57 )
return 1 ;
}
if ( V_15 -> V_28 != V_29 && ( V_48 -> V_54 & V_58 ) )
return 1 ;
return 0 ;
}
static void F_43 ( struct V_47 * V_48 )
{
F_28 ( V_59 , & V_48 -> V_60 ) ;
F_44 () ;
F_45 ( & V_48 -> V_60 , V_59 ) ;
}
static inline void F_46 ( struct V_14 * V_15 , const int V_61 )
{
struct V_47 * V_48 , * V_62 ;
F_47 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_48 ( V_63 , & V_48 -> V_60 ) )
continue;
if ( V_61 & V_64 )
V_48 -> V_65 = - V_66 ;
else if ( V_48 -> V_54 & ( V_67 | V_68 ) )
V_48 -> V_65 = V_69 ;
else
continue;
F_22 ( & V_48 -> V_51 ) ;
F_49 ( V_48 , 0 ) ;
F_43 ( V_48 ) ;
}
}
static int F_50 ( struct V_14 * V_15 )
__releases( &gl->gl_spin
static inline struct V_47 * F_51 ( const struct V_14 * V_15 )
{
struct V_47 * V_48 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( ! F_48 ( V_63 , & V_48 -> V_60 ) )
return V_48 ;
}
return NULL ;
}
static void F_53 ( struct V_14 * V_15 , unsigned int V_70 )
{
int V_71 , V_72 ;
V_71 = ( V_15 -> V_28 != V_29 ) ;
V_72 = ( V_70 != V_29 ) ;
if ( V_71 != V_72 ) {
if ( V_72 )
F_14 ( V_15 ) ;
else
F_31 ( V_15 ) ;
}
if ( V_71 && V_72 && F_19 ( & V_15 -> V_30 ) )
F_28 ( V_73 , & V_15 -> V_37 ) ;
if ( V_70 != V_15 -> V_74 )
V_15 -> V_75 = F_54 ( V_15 -> V_75 - V_76 ,
V_77 ) ;
V_15 -> V_28 = V_70 ;
V_15 -> V_78 = V_79 ;
}
static void F_55 ( struct V_14 * V_15 )
{
V_15 -> V_80 = V_53 ;
F_28 ( V_81 , & V_15 -> V_37 ) ;
F_44 () ;
F_45 ( & V_15 -> V_37 , V_81 ) ;
}
static void F_56 ( struct V_14 * V_15 , unsigned int V_61 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
struct V_47 * V_48 ;
unsigned V_82 = V_61 & V_83 ;
int V_84 ;
F_21 ( & V_15 -> V_85 ) ;
F_57 ( V_15 , V_82 ) ;
F_53 ( V_15 , V_82 ) ;
V_48 = F_51 ( V_15 ) ;
if ( F_48 ( V_86 , & V_15 -> V_37 ) &&
V_82 != V_29 && V_15 -> V_80 == V_29 )
V_15 -> V_74 = V_29 ;
if ( F_58 ( V_82 != V_15 -> V_74 ) ) {
if ( V_48 && ! F_48 ( V_86 , & V_15 -> V_37 ) ) {
if ( V_61 & V_87 ) {
if ( ( V_48 -> V_54 & V_88 ) == 0 )
F_59 ( & V_48 -> V_51 , & V_15 -> V_30 ) ;
V_48 = F_51 ( V_15 ) ;
V_15 -> V_74 = V_48 -> V_52 ;
goto V_89;
}
if ( ( V_61 & V_64 ) ||
( V_48 -> V_54 & ( V_67 | V_68 ) ) ) {
V_15 -> V_74 = V_15 -> V_28 ;
F_46 ( V_15 , V_61 ) ;
goto V_90;
}
}
switch( V_82 ) {
case V_29 :
V_89:
F_60 ( V_15 , V_48 , V_15 -> V_74 ) ;
break;
case V_56 :
case V_57 :
F_60 ( V_15 , V_48 , V_29 ) ;
break;
default:
F_61 ( V_91 L_1 , V_15 -> V_74 , V_82 ) ;
F_15 ( V_15 , 1 ) ;
}
F_25 ( & V_15 -> V_85 ) ;
return;
}
if ( F_62 ( V_86 , & V_15 -> V_37 ) )
F_55 ( V_15 ) ;
if ( V_82 != V_29 ) {
if ( V_27 -> V_92 ) {
F_25 ( & V_15 -> V_85 ) ;
V_84 = V_27 -> V_92 ( V_15 , V_48 ) ;
F_21 ( & V_15 -> V_85 ) ;
if ( V_84 ) {
F_46 ( V_15 , V_84 ) ;
goto V_90;
}
}
V_84 = F_50 ( V_15 ) ;
if ( V_84 == 2 )
goto V_93;
}
V_90:
F_28 ( V_94 , & V_15 -> V_37 ) ;
V_93:
F_25 ( & V_15 -> V_85 ) ;
}
static void F_60 ( struct V_14 * V_15 , struct V_47 * V_48 , unsigned int V_95 )
__releases( &gl->gl_spin
static inline struct V_47 * F_63 ( const struct V_14 * V_15 )
{
struct V_47 * V_48 ;
if ( ! F_19 ( & V_15 -> V_30 ) ) {
V_48 = F_42 ( V_15 -> V_30 . V_50 , struct V_47 , V_51 ) ;
if ( F_48 ( V_63 , & V_48 -> V_60 ) )
return V_48 ;
}
return NULL ;
}
static void F_64 ( struct V_14 * V_15 , const int V_96 )
__releases( &gl->gl_spin
static void F_65 ( struct V_97 * V_98 )
{
struct V_14 * V_15 = F_8 ( V_98 , struct V_14 , V_99 ) ;
struct V_1 * V_2 = V_15 -> V_22 ;
struct V_100 * V_101 ;
struct V_102 * V_102 ;
V_7 V_103 = V_15 -> V_46 . V_6 ;
V_101 = V_15 -> V_104 ;
if ( V_101 )
V_102 = F_66 ( V_2 -> V_105 , V_103 , 1 ) ;
else
V_102 = F_67 ( V_2 , V_103 , NULL , V_106 ) ;
if ( V_102 && ! F_68 ( V_102 ) ) {
F_69 ( V_102 ) ;
F_70 ( V_102 ) ;
}
F_32 ( V_15 ) ;
}
static void F_71 ( struct V_97 * V_98 )
{
unsigned long V_107 = 0 ;
struct V_14 * V_15 = F_8 ( V_98 , struct V_14 , V_108 . V_98 ) ;
int V_109 = 0 ;
if ( F_62 ( V_110 , & V_15 -> V_37 ) ) {
F_56 ( V_15 , V_15 -> V_111 ) ;
V_109 = 1 ;
}
F_21 ( & V_15 -> V_85 ) ;
if ( F_48 ( V_112 , & V_15 -> V_37 ) &&
V_15 -> V_28 != V_29 &&
V_15 -> V_80 != V_53 ) {
unsigned long V_113 , V_114 = V_79 ;
V_113 = V_15 -> V_78 + V_15 -> V_75 ;
if ( F_72 ( V_114 , V_113 ) )
V_107 = V_113 - V_114 ;
if ( ! V_107 ) {
F_28 ( V_112 , & V_15 -> V_37 ) ;
F_24 ( V_81 , & V_15 -> V_37 ) ;
}
}
F_64 ( V_15 , 0 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( ! V_107 )
F_32 ( V_15 ) ;
else {
if ( V_15 -> V_46 . V_8 != V_115 )
V_107 = 0 ;
if ( F_73 ( V_116 , & V_15 -> V_108 , V_107 ) == 0 )
F_32 ( V_15 ) ;
}
if ( V_109 )
F_32 ( V_15 ) ;
}
int F_74 ( struct V_1 * V_2 , V_7 V_117 ,
const struct V_26 * V_27 , int V_118 ,
struct V_14 * * V_119 )
{
struct V_120 * V_121 = V_2 -> V_105 ;
struct V_3 V_4 = { . V_6 = V_117 , . V_8 = V_27 -> V_122 } ;
struct V_14 * V_15 , * V_62 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_38 * V_39 ;
struct V_123 * V_124 ;
F_75 () ;
V_15 = F_37 ( V_10 , V_2 , & V_4 ) ;
F_76 () ;
* V_119 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_118 )
return - V_125 ;
if ( V_27 -> V_18 & V_19 )
V_124 = V_20 ;
else
V_124 = V_21 ;
V_15 = F_77 ( V_124 , V_126 ) ;
if ( ! V_15 )
return - V_127 ;
F_17 ( & V_2 -> V_23 ) ;
V_15 -> V_22 = V_2 ;
V_15 -> V_37 = 0 ;
V_15 -> V_46 = V_4 ;
F_78 ( & V_15 -> V_25 , 1 ) ;
V_15 -> V_28 = V_29 ;
V_15 -> V_74 = V_29 ;
V_15 -> V_80 = V_53 ;
V_15 -> F_1 = V_10 ;
V_15 -> V_17 = V_27 ;
V_15 -> V_128 = F_79 ( 0 , 0 ) ;
F_80 () ;
V_15 -> V_129 = F_81 ( V_2 -> V_130 ) -> V_131 [ V_27 -> V_122 ] ;
F_82 () ;
V_15 -> V_129 . V_132 [ V_133 ] = 0 ;
V_15 -> V_129 . V_132 [ V_134 ] = 0 ;
memset ( & V_15 -> V_135 , 0 , sizeof( struct V_136 ) ) ;
V_15 -> V_135 . V_137 = V_15 -> V_138 ;
V_15 -> V_78 = V_79 ;
V_15 -> V_104 = NULL ;
V_15 -> V_75 = V_139 ;
F_83 ( & V_15 -> V_108 , F_71 ) ;
F_84 ( & V_15 -> V_99 , F_65 ) ;
V_39 = F_33 ( V_15 ) ;
if ( V_39 ) {
V_39 -> V_140 = & V_141 ;
V_39 -> V_142 = V_121 -> V_143 -> V_144 ;
V_39 -> V_145 = 0 ;
F_85 ( V_39 , V_146 ) ;
V_39 -> V_147 = NULL ;
V_39 -> V_148 = V_121 -> V_149 ;
V_39 -> V_150 = 0 ;
}
F_3 ( V_10 ) ;
V_62 = F_37 ( V_10 , V_2 , & V_4 ) ;
if ( V_62 ) {
F_5 ( V_10 ) ;
F_9 ( V_124 , V_15 ) ;
F_27 ( & V_2 -> V_23 ) ;
V_15 = V_62 ;
} else {
F_86 ( & V_15 -> V_40 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_119 = V_15 ;
return 0 ;
}
void F_87 ( struct V_14 * V_15 , unsigned int V_82 , unsigned V_145 ,
struct V_47 * V_48 )
{
F_88 ( & V_48 -> V_51 ) ;
V_48 -> V_151 = V_15 ;
V_48 -> V_152 = ( unsigned long ) F_89 ( 0 ) ;
V_48 -> V_153 = F_90 ( F_91 ( V_154 ) ) ;
V_48 -> V_52 = V_82 ;
V_48 -> V_54 = V_145 ;
V_48 -> V_65 = 0 ;
V_48 -> V_60 = 0 ;
F_14 ( V_15 ) ;
}
void F_92 ( unsigned int V_82 , unsigned V_145 , struct V_47 * V_48 )
{
V_48 -> V_52 = V_82 ;
V_48 -> V_54 = V_145 ;
V_48 -> V_60 = 0 ;
V_48 -> V_152 = ( unsigned long ) F_89 ( 0 ) ;
if ( V_48 -> V_153 )
F_93 ( V_48 -> V_153 ) ;
V_48 -> V_153 = F_90 ( F_91 ( V_154 ) ) ;
}
void F_94 ( struct V_47 * V_48 )
{
F_93 ( V_48 -> V_153 ) ;
F_32 ( V_48 -> V_151 ) ;
V_48 -> V_151 = NULL ;
V_48 -> V_152 = 0 ;
}
static int F_95 ( void * V_155 )
{
F_96 () ;
return 0 ;
}
static int F_97 ( void * V_155 )
{
F_96 () ;
return 0 ;
}
static void F_98 ( struct V_47 * V_48 )
{
unsigned long V_156 = V_79 ;
F_99 () ;
F_100 ( & V_48 -> V_60 , V_59 , F_95 , V_157 ) ;
if ( F_101 ( V_79 , V_156 + V_158 ) )
V_48 -> V_151 -> V_75 = F_102 ( V_48 -> V_151 -> V_75 +
V_159 ,
V_160 ) ;
}
static void F_103 ( struct V_14 * V_15 )
{
F_99 () ;
F_100 ( & V_15 -> V_37 , V_81 , F_97 , V_157 ) ;
}
static void F_104 ( struct V_14 * V_15 , unsigned int V_82 ,
unsigned long V_107 )
{
int V_161 = V_107 ? V_112 : V_81 ;
F_24 ( V_161 , & V_15 -> V_37 ) ;
if ( V_15 -> V_80 == V_53 ) {
V_15 -> V_80 = V_82 ;
V_15 -> V_162 = V_79 ;
} else if ( V_15 -> V_80 != V_29 &&
V_15 -> V_80 != V_82 ) {
V_15 -> V_80 = V_29 ;
}
if ( V_15 -> V_17 -> V_163 )
V_15 -> V_17 -> V_163 ( V_15 ) ;
F_105 ( V_15 ) ;
}
int F_106 ( struct V_47 * V_48 )
{
F_98 ( V_48 ) ;
return V_48 -> V_65 ;
}
void F_107 ( struct V_164 * V_165 , const char * V_166 , ... )
{
struct V_167 V_168 ;
T_1 args ;
va_start ( args , V_166 ) ;
if ( V_165 ) {
struct V_169 * V_170 = V_165 -> V_171 ;
vsprintf ( V_170 -> string , V_166 , args ) ;
F_108 ( V_165 , V_170 -> string ) ;
} else {
V_168 . V_166 = V_166 ;
V_168 . V_172 = & args ;
F_61 ( V_91 L_2 , & V_168 ) ;
}
va_end ( args ) ;
}
static inline void F_109 ( struct V_47 * V_48 )
__releases( &gl->gl_spin
int F_110 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_151 ;
struct V_1 * V_2 = V_15 -> V_22 ;
int error = 0 ;
if ( F_58 ( F_48 ( V_173 , & V_2 -> V_174 ) ) )
return - V_66 ;
if ( F_48 ( V_36 , & V_15 -> V_37 ) )
F_29 ( V_15 ) ;
F_21 ( & V_15 -> V_85 ) ;
F_109 ( V_48 ) ;
if ( ( V_175 & V_48 -> V_54 ) &&
F_62 ( V_176 , & V_15 -> V_37 ) )
F_24 ( V_110 , & V_15 -> V_37 ) ;
F_64 ( V_15 , 1 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( ! ( V_48 -> V_54 & V_177 ) )
error = F_106 ( V_48 ) ;
return error ;
}
int F_111 ( struct V_47 * V_48 )
{
return F_48 ( V_59 , & V_48 -> V_60 ) ? 0 : 1 ;
}
void F_112 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_151 ;
const struct V_26 * V_27 = V_15 -> V_17 ;
unsigned V_107 = 0 ;
int V_178 = 0 ;
F_21 ( & V_15 -> V_85 ) ;
if ( V_48 -> V_54 & V_179 )
F_104 ( V_15 , V_29 , 0 ) ;
F_22 ( & V_48 -> V_51 ) ;
if ( F_63 ( V_15 ) == NULL ) {
if ( V_27 -> V_180 ) {
F_15 ( V_15 , F_113 ( V_94 , & V_15 -> V_37 ) ) ;
F_25 ( & V_15 -> V_85 ) ;
V_27 -> V_180 ( V_48 ) ;
F_21 ( & V_15 -> V_85 ) ;
F_28 ( V_94 , & V_15 -> V_37 ) ;
}
if ( F_19 ( & V_15 -> V_30 ) &&
! F_48 ( V_112 , & V_15 -> V_37 ) &&
! F_48 ( V_81 , & V_15 -> V_37 ) )
V_178 = 1 ;
}
if ( ! F_48 ( V_181 , & V_15 -> V_37 ) )
F_30 ( V_15 ) ;
F_49 ( V_48 , 0 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( F_114 ( V_178 ) )
return;
F_14 ( V_15 ) ;
if ( F_48 ( V_112 , & V_15 -> V_37 ) &&
! F_48 ( V_81 , & V_15 -> V_37 ) &&
V_15 -> V_46 . V_8 == V_115 )
V_107 = V_15 -> V_75 ;
if ( F_73 ( V_116 , & V_15 -> V_108 , V_107 ) == 0 )
F_32 ( V_15 ) ;
}
void F_115 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_151 ;
F_112 ( V_48 ) ;
F_103 ( V_15 ) ;
}
void F_116 ( struct V_47 * V_48 )
{
F_112 ( V_48 ) ;
F_94 ( V_48 ) ;
}
int F_117 ( struct V_1 * V_2 , V_7 V_117 ,
const struct V_26 * V_27 ,
unsigned int V_82 , int V_145 , struct V_47 * V_48 )
{
struct V_14 * V_15 ;
int error ;
error = F_74 ( V_2 , V_117 , V_27 , V_182 , & V_15 ) ;
if ( ! error ) {
error = F_118 ( V_15 , V_82 , V_145 , V_48 ) ;
F_32 ( V_15 ) ;
}
return error ;
}
static int F_119 ( const void * V_183 , const void * V_184 )
{
const struct V_47 * V_185 = * ( const struct V_47 * * ) V_183 ;
const struct V_47 * V_186 = * ( const struct V_47 * * ) V_184 ;
const struct V_3 * V_187 = & V_185 -> V_151 -> V_46 ;
const struct V_3 * V_188 = & V_186 -> V_151 -> V_46 ;
if ( V_187 -> V_6 > V_188 -> V_6 )
return 1 ;
if ( V_187 -> V_6 < V_188 -> V_6 )
return - 1 ;
F_120 ( V_185 -> V_151 -> V_17 -> V_122 == V_186 -> V_151 -> V_17 -> V_122 ) ;
return 0 ;
}
static int F_121 ( unsigned int V_189 , struct V_47 * V_190 ,
struct V_47 * * V_191 )
{
unsigned int V_192 ;
int error = 0 ;
for ( V_192 = 0 ; V_192 < V_189 ; V_192 ++ )
V_191 [ V_192 ] = & V_190 [ V_192 ] ;
F_122 ( V_191 , V_189 , sizeof( struct V_47 * ) , F_119 , NULL ) ;
for ( V_192 = 0 ; V_192 < V_189 ; V_192 ++ ) {
V_191 [ V_192 ] -> V_54 &= ~ ( V_67 | V_177 ) ;
error = F_110 ( V_191 [ V_192 ] ) ;
if ( error ) {
while ( V_192 -- )
F_112 ( V_191 [ V_192 ] ) ;
break;
}
}
return error ;
}
int F_123 ( unsigned int V_189 , struct V_47 * V_190 )
{
struct V_47 * V_62 [ 4 ] ;
struct V_47 * * V_193 = V_62 ;
int error = 0 ;
switch( V_189 ) {
case 0 :
return 0 ;
case 1 :
V_190 -> V_54 &= ~ ( V_67 | V_177 ) ;
return F_110 ( V_190 ) ;
default:
if ( V_189 <= 4 )
break;
V_193 = F_124 ( V_189 * sizeof( struct V_47 * ) , V_146 ) ;
if ( ! V_193 )
return - V_127 ;
}
error = F_121 ( V_189 , V_190 , V_193 ) ;
if ( V_193 != V_62 )
F_125 ( V_193 ) ;
return error ;
}
void F_126 ( unsigned int V_189 , struct V_47 * V_190 )
{
while ( V_189 -- )
F_112 ( & V_190 [ V_189 ] ) ;
}
void F_127 ( unsigned int V_189 , struct V_47 * V_190 )
{
while ( V_189 -- )
F_116 ( & V_190 [ V_189 ] ) ;
}
void F_128 ( struct V_14 * V_15 , unsigned int V_82 )
{
unsigned long V_107 = 0 ;
unsigned long V_113 ;
unsigned long V_114 = V_79 ;
F_14 ( V_15 ) ;
V_113 = V_15 -> V_78 + V_15 -> V_75 ;
if ( F_48 ( V_73 , & V_15 -> V_37 ) &&
V_15 -> V_46 . V_8 == V_115 ) {
if ( F_72 ( V_114 , V_113 ) )
V_107 = V_113 - V_114 ;
if ( F_48 ( V_110 , & V_15 -> V_37 ) )
V_107 = V_15 -> V_75 ;
}
F_21 ( & V_15 -> V_85 ) ;
F_104 ( V_15 , V_82 , V_107 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , V_107 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_129 ( const struct V_14 * V_15 )
{
const struct V_47 * V_48 ;
if ( V_15 -> V_111 & ~ V_83 )
return 0 ;
if ( V_15 -> V_74 == V_29 )
return 0 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( F_48 ( V_63 , & V_48 -> V_60 ) )
continue;
if ( V_175 & V_48 -> V_54 )
return 0 ;
}
return 1 ;
}
void F_130 ( struct V_14 * V_15 , int V_61 )
{
struct V_194 * V_195 = & V_15 -> V_22 -> V_42 ;
F_21 ( & V_15 -> V_85 ) ;
V_15 -> V_111 = V_61 ;
if ( F_58 ( F_48 ( V_196 , & V_195 -> V_197 ) ) ) {
if ( F_129 ( V_15 ) ) {
F_24 ( V_176 , & V_15 -> V_37 ) ;
F_25 ( & V_15 -> V_85 ) ;
return;
}
}
F_25 ( & V_15 -> V_85 ) ;
F_24 ( V_110 , & V_15 -> V_37 ) ;
F_131 () ;
F_14 ( V_15 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_132 ( struct V_198 * V_199 ,
struct V_200 * V_201 )
{
struct V_14 * V_15 ;
int V_202 ;
int V_203 = 0 ;
int V_204 = V_201 -> V_205 ;
T_2 V_206 = V_201 -> V_206 ;
F_133 ( V_207 ) ;
if ( V_204 == 0 )
goto V_90;
if ( ! ( V_206 & V_208 ) )
return - 1 ;
F_21 ( & V_32 ) ;
while( V_204 && ! F_19 ( & V_35 ) ) {
V_15 = F_42 ( V_35 . V_50 , struct V_14 , V_33 ) ;
F_22 ( & V_15 -> V_33 ) ;
F_28 ( V_36 , & V_15 -> V_37 ) ;
F_27 ( & V_34 ) ;
if ( ! F_113 ( V_94 , & V_15 -> V_37 ) ) {
F_14 ( V_15 ) ;
F_25 ( & V_32 ) ;
F_21 ( & V_15 -> V_85 ) ;
V_202 = F_18 ( V_15 ) ;
if ( V_202 ) {
F_104 ( V_15 , V_29 , 0 ) ;
V_204 -- ;
}
F_28 ( V_94 , & V_15 -> V_37 ) ;
F_44 () ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_31 ( V_15 ) ;
F_25 ( & V_15 -> V_85 ) ;
F_21 ( & V_32 ) ;
continue;
}
V_203 ++ ;
F_134 ( & V_15 -> V_33 , & V_207 ) ;
F_24 ( V_36 , & V_15 -> V_37 ) ;
}
F_135 ( & V_207 , & V_35 ) ;
F_136 ( V_203 , & V_34 ) ;
F_25 ( & V_32 ) ;
V_90:
return ( F_16 ( & V_34 ) / 100 ) * V_209 ;
}
static void F_137 ( T_3 V_210 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_211 * V_212 = & V_11 [ V_10 ] ;
struct V_45 * V_213 ;
F_75 () ;
F_38 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_22 == V_2 ) && F_16 ( & V_15 -> V_25 ) )
V_210 ( V_15 ) ;
}
F_76 () ;
F_138 () ;
}
static void F_139 ( T_3 V_210 , const struct V_1 * V_2 )
{
unsigned V_192 ;
for ( V_192 = 0 ; V_192 < V_214 ; V_192 ++ )
F_137 ( V_210 , V_2 , V_192 ) ;
}
static void F_140 ( struct V_14 * V_15 )
{
if ( ! F_62 ( V_176 , & V_15 -> V_37 ) )
return;
F_24 ( V_110 , & V_15 -> V_37 ) ;
F_14 ( V_15 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static void F_141 ( struct V_14 * V_15 )
{
F_29 ( V_15 ) ;
F_21 ( & V_15 -> V_85 ) ;
if ( V_15 -> V_28 != V_29 )
F_104 ( V_15 , V_29 , 0 ) ;
F_25 ( & V_15 -> V_85 ) ;
F_14 ( V_15 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
F_139 ( F_140 , V_2 ) ;
}
static int F_143 ( struct V_164 * V_165 , struct V_14 * V_15 )
{
int V_61 ;
F_21 ( & V_15 -> V_85 ) ;
V_61 = F_144 ( V_165 , V_15 ) ;
F_25 ( & V_15 -> V_85 ) ;
return V_61 ;
}
static void F_145 ( struct V_14 * V_15 )
{
F_143 ( NULL , V_15 ) ;
}
void F_146 ( struct V_1 * V_2 )
{
F_139 ( F_141 , V_2 ) ;
F_147 ( V_116 ) ;
F_148 ( V_2 -> V_24 , F_16 ( & V_2 -> V_23 ) == 0 ) ;
F_139 ( F_145 , V_2 ) ;
}
void F_149 ( struct V_100 * V_101 )
{
struct V_14 * V_15 = V_101 -> V_215 ;
int V_61 ;
V_61 = F_150 ( V_101 ) ;
F_151 ( V_15 -> V_22 , V_61 == 0 ) ;
F_21 ( & V_15 -> V_85 ) ;
F_28 ( V_94 , & V_15 -> V_37 ) ;
F_64 ( V_15 , 1 ) ;
F_25 ( & V_15 -> V_85 ) ;
}
static const char * F_152 ( unsigned V_82 )
{
switch( V_82 ) {
case V_29 :
return L_3 ;
case V_56 :
return L_4 ;
case V_57 :
return L_5 ;
case V_53 :
return L_6 ;
}
return L_7 ;
}
static const char * F_153 ( char * V_216 , unsigned V_145 , unsigned long V_217 )
{
char * V_191 = V_216 ;
if ( V_145 & V_67 )
* V_191 ++ = 't' ;
if ( V_145 & V_68 )
* V_191 ++ = 'T' ;
if ( V_145 & V_175 )
* V_191 ++ = 'e' ;
if ( V_145 & V_58 )
* V_191 ++ = 'A' ;
if ( V_145 & V_88 )
* V_191 ++ = 'p' ;
if ( V_145 & V_177 )
* V_191 ++ = 'a' ;
if ( V_145 & V_55 )
* V_191 ++ = 'E' ;
if ( V_145 & V_179 )
* V_191 ++ = 'c' ;
if ( F_48 ( V_63 , & V_217 ) )
* V_191 ++ = 'H' ;
if ( F_48 ( V_59 , & V_217 ) )
* V_191 ++ = 'W' ;
if ( F_48 ( V_218 , & V_217 ) )
* V_191 ++ = 'F' ;
* V_191 = 0 ;
return V_216 ;
}
static int F_154 ( struct V_164 * V_165 , const struct V_47 * V_48 )
{
struct V_219 * V_220 = NULL ;
char V_221 [ 32 ] ;
if ( V_48 -> V_153 )
V_220 = F_155 ( V_48 -> V_153 , V_222 ) ;
F_107 ( V_165 , L_8 ,
F_152 ( V_48 -> V_52 ) ,
F_153 ( V_221 , V_48 -> V_54 , V_48 -> V_60 ) ,
V_48 -> V_65 ,
V_48 -> V_153 ? ( long ) F_156 ( V_48 -> V_153 ) : - 1 ,
V_220 ? V_220 -> V_223 : L_9 ,
( void * ) V_48 -> V_152 ) ;
return 0 ;
}
static const char * F_157 ( char * V_216 , const struct V_14 * V_15 )
{
const unsigned long * V_224 = & V_15 -> V_37 ;
char * V_191 = V_216 ;
if ( F_48 ( V_94 , V_224 ) )
* V_191 ++ = 'l' ;
if ( F_48 ( V_81 , V_224 ) )
* V_191 ++ = 'D' ;
if ( F_48 ( V_112 , V_224 ) )
* V_191 ++ = 'd' ;
if ( F_48 ( V_86 , V_224 ) )
* V_191 ++ = 'p' ;
if ( F_48 ( V_225 , V_224 ) )
* V_191 ++ = 'y' ;
if ( F_48 ( V_181 , V_224 ) )
* V_191 ++ = 'f' ;
if ( F_48 ( V_226 , V_224 ) )
* V_191 ++ = 'i' ;
if ( F_48 ( V_110 , V_224 ) )
* V_191 ++ = 'r' ;
if ( F_48 ( V_227 , V_224 ) )
* V_191 ++ = 'I' ;
if ( F_48 ( V_176 , V_224 ) )
* V_191 ++ = 'F' ;
if ( F_48 ( V_73 , V_224 ) )
* V_191 ++ = 'q' ;
if ( F_48 ( V_36 , V_224 ) )
* V_191 ++ = 'L' ;
if ( V_15 -> V_104 )
* V_191 ++ = 'o' ;
if ( F_48 ( V_228 , V_224 ) )
* V_191 ++ = 'b' ;
* V_191 = 0 ;
return V_216 ;
}
static int F_144 ( struct V_164 * V_165 , const struct V_14 * V_15 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
unsigned long long V_229 ;
const struct V_47 * V_48 ;
char V_230 [ 32 ] ;
int error = 0 ;
V_229 = V_79 - V_15 -> V_162 ;
V_229 *= 1000000 / V_158 ;
if ( ! F_48 ( V_81 , & V_15 -> V_37 ) )
V_229 = 0 ;
F_107 ( V_165 , L_10 ,
F_152 ( V_15 -> V_28 ) ,
V_15 -> V_46 . V_8 ,
( unsigned long long ) V_15 -> V_46 . V_6 ,
F_157 ( V_230 , V_15 ) ,
F_152 ( V_15 -> V_74 ) ,
F_152 ( V_15 -> V_80 ) , V_229 ,
F_16 ( & V_15 -> V_231 ) ,
F_16 ( & V_15 -> V_232 ) ,
F_16 ( & V_15 -> V_25 ) , V_15 -> V_75 ) ;
F_52 (gh, &gl->gl_holders, gh_list) {
error = F_154 ( V_165 , V_48 ) ;
if ( error )
goto V_90;
}
if ( V_15 -> V_28 != V_29 && V_27 -> V_233 )
error = V_27 -> V_233 ( V_165 , V_15 ) ;
V_90:
return error ;
}
static int F_158 ( struct V_164 * V_165 , void * V_234 )
{
struct V_14 * V_15 = V_234 ;
F_108 ( V_165 , L_11 ,
V_15 -> V_46 . V_8 ,
( unsigned long long ) V_15 -> V_46 . V_6 ,
( long long ) V_15 -> V_129 . V_132 [ V_235 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_236 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_237 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_238 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_239 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_240 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_133 ] ,
( long long ) V_15 -> V_129 . V_132 [ V_134 ] ) ;
return 0 ;
}
static int F_159 ( struct V_164 * V_165 , void * V_234 )
{
struct V_169 * V_170 = V_165 -> V_171 ;
struct V_1 * V_2 = V_170 -> V_2 ;
unsigned V_241 = V_170 -> V_10 >> 3 ;
unsigned V_242 = V_170 -> V_10 & 0x07 ;
T_4 V_243 ;
int V_244 ;
if ( V_241 == 0 && V_242 != 0 )
return 0 ;
F_108 ( V_165 , L_12 , V_245 [ V_241 ] ,
( V_241 == 0 ) ? L_13 : V_246 [ V_242 ] ) ;
F_160 (i) {
const struct V_247 * V_131 = F_161 ( V_2 -> V_130 , V_244 ) ;
if ( V_241 == 0 ) {
V_243 = V_244 ;
} else {
V_243 = V_131 -> V_131 [ V_241 - 1 ] . V_132 [ V_242 ] ;
}
F_108 ( V_165 , L_14 , ( long long ) V_243 ) ;
}
F_162 ( V_165 , '\n' ) ;
return 0 ;
}
int T_5 F_163 ( void )
{
unsigned V_244 ;
for( V_244 = 0 ; V_244 < V_214 ; V_244 ++ ) {
F_164 ( & V_11 [ V_244 ] ) ;
}
V_116 = F_165 ( L_15 , V_248 |
V_249 | V_250 , 0 ) ;
if ( F_68 ( V_116 ) )
return F_166 ( V_116 ) ;
V_251 = F_165 ( L_16 ,
V_248 | V_250 ,
0 ) ;
if ( F_68 ( V_251 ) ) {
F_167 ( V_116 ) ;
return F_166 ( V_251 ) ;
}
F_168 ( & V_252 ) ;
return 0 ;
}
void F_169 ( void )
{
F_170 ( & V_252 ) ;
F_167 ( V_116 ) ;
F_167 ( V_251 ) ;
}
static inline struct V_14 * F_171 ( unsigned V_10 )
{
return F_172 ( F_173 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_40 ) ;
}
static inline struct V_14 * F_174 ( struct V_14 * V_15 )
{
return F_172 ( F_175 ( V_15 -> V_40 . V_50 ) ,
struct V_14 , V_40 ) ;
}
static int F_176 ( struct V_169 * V_170 )
{
struct V_14 * V_15 ;
do {
V_15 = V_170 -> V_15 ;
if ( V_15 ) {
V_170 -> V_15 = F_174 ( V_15 ) ;
} else {
V_170 -> V_15 = F_171 ( V_170 -> V_10 ) ;
}
while ( V_170 -> V_15 == NULL ) {
V_170 -> V_10 ++ ;
if ( V_170 -> V_10 >= V_214 ) {
F_76 () ;
return 1 ;
}
V_170 -> V_15 = F_171 ( V_170 -> V_10 ) ;
}
} while ( V_170 -> V_2 != V_170 -> V_15 -> V_22 || F_16 ( & V_170 -> V_15 -> V_25 ) == 0 );
return 0 ;
}
static void * F_177 ( struct V_164 * V_165 , T_6 * V_213 )
{
struct V_169 * V_170 = V_165 -> V_171 ;
T_6 V_253 = * V_213 ;
V_170 -> V_10 = 0 ;
F_75 () ;
do {
if ( F_176 ( V_170 ) )
return NULL ;
} while ( V_253 -- );
return V_170 -> V_15 ;
}
static void * F_178 ( struct V_164 * V_165 , void * V_234 ,
T_6 * V_213 )
{
struct V_169 * V_170 = V_165 -> V_171 ;
( * V_213 ) ++ ;
if ( F_176 ( V_170 ) )
return NULL ;
return V_170 -> V_15 ;
}
static void F_179 ( struct V_164 * V_165 , void * V_234 )
{
struct V_169 * V_170 = V_165 -> V_171 ;
if ( V_170 -> V_15 )
F_76 () ;
V_170 -> V_15 = NULL ;
}
static int F_180 ( struct V_164 * V_165 , void * V_234 )
{
return F_143 ( V_165 , V_234 ) ;
}
static void * F_181 ( struct V_164 * V_165 , T_6 * V_213 )
{
struct V_169 * V_170 = V_165 -> V_171 ;
V_170 -> V_10 = * V_213 ;
if ( * V_213 >= V_254 )
return NULL ;
F_80 () ;
return V_255 ;
}
static void * F_182 ( struct V_164 * V_165 , void * V_234 ,
T_6 * V_213 )
{
struct V_169 * V_170 = V_165 -> V_171 ;
( * V_213 ) ++ ;
V_170 -> V_10 ++ ;
if ( V_170 -> V_10 >= V_254 ) {
F_82 () ;
return NULL ;
}
return V_255 ;
}
static void F_183 ( struct V_164 * V_165 , void * V_234 )
{
F_82 () ;
}
static int F_184 ( struct V_102 * V_102 , struct V_256 * V_256 )
{
int V_61 = F_185 ( V_256 , & V_257 ,
sizeof( struct V_169 ) ) ;
if ( V_61 == 0 ) {
struct V_164 * V_165 = V_256 -> V_258 ;
struct V_169 * V_170 = V_165 -> V_171 ;
V_170 -> V_2 = V_102 -> V_259 ;
}
return V_61 ;
}
static int F_186 ( struct V_102 * V_102 , struct V_256 * V_256 )
{
int V_61 = F_185 ( V_256 , & V_260 ,
sizeof( struct V_169 ) ) ;
if ( V_61 == 0 ) {
struct V_164 * V_165 = V_256 -> V_258 ;
struct V_169 * V_170 = V_165 -> V_171 ;
V_170 -> V_2 = V_102 -> V_259 ;
}
return V_61 ;
}
static int F_187 ( struct V_102 * V_102 , struct V_256 * V_256 )
{
int V_61 = F_185 ( V_256 , & V_261 ,
sizeof( struct V_169 ) ) ;
if ( V_61 == 0 ) {
struct V_164 * V_165 = V_256 -> V_258 ;
struct V_169 * V_170 = V_165 -> V_171 ;
V_170 -> V_2 = V_102 -> V_259 ;
}
return V_61 ;
}
int F_188 ( struct V_1 * V_2 )
{
V_2 -> V_262 = F_189 ( V_2 -> V_263 , V_264 ) ;
if ( ! V_2 -> V_262 )
return - V_127 ;
V_2 -> V_265 = F_190 ( L_17 ,
V_266 | V_267 ,
V_2 -> V_262 , V_2 ,
& V_268 ) ;
if ( ! V_2 -> V_265 )
goto V_269;
V_2 -> V_270 = F_190 ( L_18 ,
V_266 | V_267 ,
V_2 -> V_262 , V_2 ,
& V_271 ) ;
if ( ! V_2 -> V_270 )
goto V_269;
V_2 -> V_272 = F_190 ( L_19 ,
V_266 | V_267 ,
V_2 -> V_262 , V_2 ,
& V_273 ) ;
if ( ! V_2 -> V_272 )
goto V_269;
return 0 ;
V_269:
F_191 ( V_2 ) ;
return - V_127 ;
}
void F_191 ( struct V_1 * V_2 )
{
if ( V_2 -> V_262 ) {
if ( V_2 -> V_265 ) {
F_192 ( V_2 -> V_265 ) ;
V_2 -> V_265 = NULL ;
}
if ( V_2 -> V_270 ) {
F_192 ( V_2 -> V_270 ) ;
V_2 -> V_270 = NULL ;
}
if ( V_2 -> V_272 ) {
F_192 ( V_2 -> V_272 ) ;
V_2 -> V_272 = NULL ;
}
F_192 ( V_2 -> V_262 ) ;
V_2 -> V_262 = NULL ;
}
}
int F_193 ( void )
{
V_264 = F_189 ( L_20 , NULL ) ;
return V_264 ? 0 : - V_127 ;
}
void F_194 ( void )
{
F_192 ( V_264 ) ;
V_264 = NULL ;
}
