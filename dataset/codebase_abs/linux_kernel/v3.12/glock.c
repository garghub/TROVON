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
void F_15 ( struct V_14 * V_15 )
{
F_16 ( V_15 , F_17 ( & V_15 -> V_27 ) == 0 ) ;
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
F_18 ( & V_36 ) ;
F_24 ( & V_15 -> V_35 , & V_37 ) ;
F_25 ( V_38 , & V_15 -> V_39 ) ;
F_26 ( & V_34 ) ;
}
static void F_27 ( struct V_14 * V_15 )
{
if ( ! F_20 ( & V_15 -> V_35 ) ) {
F_23 ( & V_15 -> V_35 ) ;
F_28 ( & V_36 ) ;
F_29 ( V_38 , & V_15 -> V_39 ) ;
}
}
static void F_30 ( struct V_14 * V_15 )
{
F_22 ( & V_34 ) ;
F_27 ( V_15 ) ;
F_26 ( & V_34 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
if ( F_13 ( & V_15 -> V_27 ) )
F_16 ( V_15 , 1 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
if ( F_34 ( & V_15 -> V_27 , & V_34 ) ) {
F_27 ( V_15 ) ;
F_26 ( & V_34 ) ;
F_3 ( V_15 -> F_1 ) ;
F_35 ( & V_15 -> V_42 ) ;
F_5 ( V_15 -> F_1 ) ;
F_16 ( V_15 , ! F_20 ( & V_15 -> V_32 ) ) ;
F_16 ( V_15 , V_41 && V_41 -> V_43 ) ;
F_36 ( V_15 ) ;
V_2 -> V_44 . V_45 -> V_46 ( V_15 ) ;
}
}
static struct V_14 * F_37 ( unsigned int V_10 ,
const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_47 * V_5 ;
F_38 (gl, h, &gl_hash_table[hash], gl_list) {
if ( ! F_39 ( & V_15 -> V_48 , V_4 ) )
continue;
if ( V_15 -> V_24 != V_2 )
continue;
if ( F_40 ( & V_15 -> V_27 ) )
return V_15 ;
}
return NULL ;
}
static inline int F_41 ( const struct V_14 * V_15 , const struct V_49 * V_50 )
{
const struct V_49 * V_51 = F_42 ( V_15 -> V_32 . V_52 , const struct V_49 , V_53 ) ;
if ( ( V_50 -> V_54 == V_55 ||
V_51 -> V_54 == V_55 ) && V_50 != V_51 )
return 0 ;
if ( V_15 -> V_30 == V_50 -> V_54 )
return 1 ;
if ( V_50 -> V_56 & V_57 )
return 0 ;
if ( V_15 -> V_30 == V_55 ) {
if ( V_50 -> V_54 == V_58 && V_51 -> V_54 == V_58 )
return 1 ;
if ( V_50 -> V_54 == V_59 && V_51 -> V_54 == V_59 )
return 1 ;
}
if ( V_15 -> V_30 != V_31 && ( V_50 -> V_56 & V_60 ) )
return 1 ;
return 0 ;
}
static void F_43 ( struct V_49 * V_50 )
{
F_29 ( V_61 , & V_50 -> V_62 ) ;
F_44 () ;
F_45 ( & V_50 -> V_62 , V_61 ) ;
}
static inline void F_46 ( struct V_14 * V_15 , const int V_63 )
{
struct V_49 * V_50 , * V_64 ;
F_47 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_48 ( V_65 , & V_50 -> V_62 ) )
continue;
if ( V_63 & V_66 )
V_50 -> V_67 = - V_68 ;
else if ( V_50 -> V_56 & ( V_69 | V_70 ) )
V_50 -> V_67 = V_71 ;
else
continue;
F_23 ( & V_50 -> V_53 ) ;
F_49 ( V_50 , 0 ) ;
F_43 ( V_50 ) ;
}
}
static int F_50 ( struct V_14 * V_15 )
__releases( &gl->gl_spin
static inline struct V_49 * F_51 ( const struct V_14 * V_15 )
{
struct V_49 * V_50 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( ! F_48 ( V_65 , & V_50 -> V_62 ) )
return V_50 ;
}
return NULL ;
}
static void F_53 ( struct V_14 * V_15 , unsigned int V_72 )
{
int V_73 , V_74 ;
V_73 = ( V_15 -> V_30 != V_31 ) ;
V_74 = ( V_72 != V_31 ) ;
if ( V_73 != V_74 ) {
if ( V_74 )
F_15 ( V_15 ) ;
else
F_31 ( V_15 ) ;
}
if ( V_73 && V_74 && F_20 ( & V_15 -> V_32 ) )
F_29 ( V_75 , & V_15 -> V_39 ) ;
if ( V_72 != V_15 -> V_76 )
V_15 -> V_77 = F_54 ( V_15 -> V_77 - V_78 ,
V_79 ) ;
V_15 -> V_30 = V_72 ;
V_15 -> V_80 = V_81 ;
}
static void F_55 ( struct V_14 * V_15 )
{
V_15 -> V_82 = V_55 ;
F_29 ( V_83 , & V_15 -> V_39 ) ;
F_44 () ;
F_45 ( & V_15 -> V_39 , V_83 ) ;
}
static void F_56 ( struct V_14 * V_15 , unsigned int V_63 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
struct V_49 * V_50 ;
unsigned V_84 = V_63 & V_85 ;
int V_86 ;
F_22 ( & V_15 -> V_87 ) ;
F_57 ( V_15 , V_84 ) ;
F_53 ( V_15 , V_84 ) ;
V_50 = F_51 ( V_15 ) ;
if ( F_48 ( V_88 , & V_15 -> V_39 ) &&
V_84 != V_31 && V_15 -> V_82 == V_31 )
V_15 -> V_76 = V_31 ;
if ( F_58 ( V_84 != V_15 -> V_76 ) ) {
if ( V_50 && ! F_48 ( V_88 , & V_15 -> V_39 ) ) {
if ( V_63 & V_89 ) {
if ( ( V_50 -> V_56 & V_90 ) == 0 )
F_59 ( & V_50 -> V_53 , & V_15 -> V_32 ) ;
V_50 = F_51 ( V_15 ) ;
V_15 -> V_76 = V_50 -> V_54 ;
goto V_91;
}
if ( ( V_63 & V_66 ) ||
( V_50 -> V_56 & ( V_69 | V_70 ) ) ) {
V_15 -> V_76 = V_15 -> V_30 ;
F_46 ( V_15 , V_63 ) ;
goto V_92;
}
}
switch( V_84 ) {
case V_31 :
V_91:
F_60 ( V_15 , V_50 , V_15 -> V_76 ) ;
break;
case V_58 :
case V_59 :
F_60 ( V_15 , V_50 , V_31 ) ;
break;
default:
F_61 ( V_93 L_1 , V_15 -> V_76 , V_84 ) ;
F_16 ( V_15 , 1 ) ;
}
F_26 ( & V_15 -> V_87 ) ;
return;
}
if ( F_62 ( V_88 , & V_15 -> V_39 ) )
F_55 ( V_15 ) ;
if ( V_84 != V_31 ) {
if ( V_29 -> V_94 ) {
F_26 ( & V_15 -> V_87 ) ;
V_86 = V_29 -> V_94 ( V_15 , V_50 ) ;
F_22 ( & V_15 -> V_87 ) ;
if ( V_86 ) {
F_46 ( V_15 , V_86 ) ;
goto V_92;
}
}
V_86 = F_50 ( V_15 ) ;
if ( V_86 == 2 )
goto V_95;
}
V_92:
F_29 ( V_96 , & V_15 -> V_39 ) ;
V_95:
F_26 ( & V_15 -> V_87 ) ;
}
static void F_60 ( struct V_14 * V_15 , struct V_49 * V_50 , unsigned int V_97 )
__releases( &gl->gl_spin
static inline struct V_49 * F_63 ( const struct V_14 * V_15 )
{
struct V_49 * V_50 ;
if ( ! F_20 ( & V_15 -> V_32 ) ) {
V_50 = F_42 ( V_15 -> V_32 . V_52 , struct V_49 , V_53 ) ;
if ( F_48 ( V_65 , & V_50 -> V_62 ) )
return V_50 ;
}
return NULL ;
}
static void F_64 ( struct V_14 * V_15 , const int V_98 )
__releases( &gl->gl_spin
static void F_65 ( struct V_99 * V_100 )
{
struct V_14 * V_15 = F_8 ( V_100 , struct V_14 , V_101 ) ;
struct V_1 * V_2 = V_15 -> V_24 ;
struct V_102 * V_103 ;
struct V_104 * V_104 ;
V_7 V_105 = V_15 -> V_48 . V_6 ;
V_103 = V_15 -> V_106 ;
if ( V_103 )
V_104 = F_66 ( V_2 -> V_107 , V_105 , 1 ) ;
else
V_104 = F_67 ( V_2 , V_105 , NULL , V_108 ) ;
if ( V_104 && ! F_68 ( V_104 ) ) {
F_69 ( V_104 ) ;
F_70 ( V_104 ) ;
}
F_32 ( V_15 ) ;
}
static void F_71 ( struct V_99 * V_100 )
{
unsigned long V_109 = 0 ;
struct V_14 * V_15 = F_8 ( V_100 , struct V_14 , V_110 . V_100 ) ;
int V_111 = 0 ;
if ( F_62 ( V_112 , & V_15 -> V_39 ) ) {
F_56 ( V_15 , V_15 -> V_113 ) ;
V_111 = 1 ;
}
F_22 ( & V_15 -> V_87 ) ;
if ( F_48 ( V_114 , & V_15 -> V_39 ) &&
V_15 -> V_30 != V_31 &&
V_15 -> V_82 != V_55 ) {
unsigned long V_115 , V_116 = V_81 ;
V_115 = V_15 -> V_80 + V_15 -> V_77 ;
if ( F_72 ( V_116 , V_115 ) )
V_109 = V_115 - V_116 ;
if ( ! V_109 ) {
F_29 ( V_114 , & V_15 -> V_39 ) ;
F_25 ( V_83 , & V_15 -> V_39 ) ;
}
}
F_64 ( V_15 , 0 ) ;
F_26 ( & V_15 -> V_87 ) ;
if ( ! V_109 )
F_32 ( V_15 ) ;
else {
if ( V_15 -> V_48 . V_8 != V_117 )
V_109 = 0 ;
if ( F_73 ( V_118 , & V_15 -> V_110 , V_109 ) == 0 )
F_32 ( V_15 ) ;
}
if ( V_111 )
F_32 ( V_15 ) ;
}
int F_74 ( struct V_1 * V_2 , V_7 V_119 ,
const struct V_28 * V_29 , int V_120 ,
struct V_14 * * V_121 )
{
struct V_122 * V_123 = V_2 -> V_107 ;
struct V_3 V_4 = { . V_6 = V_119 , . V_8 = V_29 -> V_124 } ;
struct V_14 * V_15 , * V_64 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_40 * V_41 ;
struct V_125 * V_126 ;
F_75 () ;
V_15 = F_37 ( V_10 , V_2 , & V_4 ) ;
F_76 () ;
* V_121 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_120 )
return - V_127 ;
if ( V_29 -> V_18 & V_19 )
V_126 = V_20 ;
else
V_126 = V_23 ;
V_15 = F_77 ( V_126 , V_128 ) ;
if ( ! V_15 )
return - V_129 ;
memset ( & V_15 -> V_21 , 0 , sizeof( struct V_130 ) ) ;
if ( V_29 -> V_18 & V_131 ) {
V_15 -> V_21 . V_22 = F_78 ( V_132 , V_128 ) ;
if ( ! V_15 -> V_21 . V_22 ) {
F_9 ( V_126 , V_15 ) ;
return - V_129 ;
}
}
F_18 ( & V_2 -> V_25 ) ;
V_15 -> V_24 = V_2 ;
V_15 -> V_39 = 0 ;
V_15 -> V_48 = V_4 ;
F_79 ( & V_15 -> V_27 , 1 ) ;
V_15 -> V_30 = V_31 ;
V_15 -> V_76 = V_31 ;
V_15 -> V_82 = V_55 ;
V_15 -> F_1 = V_10 ;
V_15 -> V_17 = V_29 ;
V_15 -> V_133 = F_80 ( 0 , 0 ) ;
F_81 () ;
V_15 -> V_134 = F_82 ( V_2 -> V_135 ) -> V_136 [ V_29 -> V_124 ] ;
F_83 () ;
V_15 -> V_134 . V_137 [ V_138 ] = 0 ;
V_15 -> V_134 . V_137 [ V_139 ] = 0 ;
V_15 -> V_80 = V_81 ;
V_15 -> V_106 = NULL ;
V_15 -> V_77 = V_140 ;
F_84 ( & V_15 -> V_110 , F_71 ) ;
F_85 ( & V_15 -> V_101 , F_65 ) ;
V_41 = F_33 ( V_15 ) ;
if ( V_41 ) {
V_41 -> V_141 = & V_142 ;
V_41 -> V_143 = V_123 -> V_144 -> V_145 ;
V_41 -> V_146 = 0 ;
F_86 ( V_41 , V_147 ) ;
V_41 -> V_148 = NULL ;
V_41 -> V_149 = V_123 -> V_150 ;
V_41 -> V_151 = 0 ;
}
F_3 ( V_10 ) ;
V_64 = F_37 ( V_10 , V_2 , & V_4 ) ;
if ( V_64 ) {
F_5 ( V_10 ) ;
F_10 ( V_15 -> V_21 . V_22 ) ;
F_9 ( V_126 , V_15 ) ;
F_28 ( & V_2 -> V_25 ) ;
V_15 = V_64 ;
} else {
F_87 ( & V_15 -> V_42 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_121 = V_15 ;
return 0 ;
}
void F_88 ( struct V_14 * V_15 , unsigned int V_84 , unsigned V_146 ,
struct V_49 * V_50 )
{
F_89 ( & V_50 -> V_53 ) ;
V_50 -> V_152 = V_15 ;
V_50 -> V_153 = ( unsigned long ) F_90 ( 0 ) ;
V_50 -> V_154 = F_91 ( F_92 ( V_155 ) ) ;
V_50 -> V_54 = V_84 ;
V_50 -> V_56 = V_146 ;
V_50 -> V_67 = 0 ;
V_50 -> V_62 = 0 ;
F_15 ( V_15 ) ;
}
void F_93 ( unsigned int V_84 , unsigned V_146 , struct V_49 * V_50 )
{
V_50 -> V_54 = V_84 ;
V_50 -> V_56 = V_146 ;
V_50 -> V_62 = 0 ;
V_50 -> V_153 = ( unsigned long ) F_90 ( 0 ) ;
if ( V_50 -> V_154 )
F_94 ( V_50 -> V_154 ) ;
V_50 -> V_154 = F_91 ( F_92 ( V_155 ) ) ;
}
void F_95 ( struct V_49 * V_50 )
{
F_94 ( V_50 -> V_154 ) ;
F_32 ( V_50 -> V_152 ) ;
V_50 -> V_152 = NULL ;
V_50 -> V_153 = 0 ;
}
static int F_96 ( void * V_156 )
{
F_97 () ;
return 0 ;
}
static int F_98 ( void * V_156 )
{
F_97 () ;
return 0 ;
}
int F_99 ( struct V_49 * V_50 )
{
unsigned long V_157 = V_81 ;
F_100 () ;
F_101 ( & V_50 -> V_62 , V_61 , F_96 , V_158 ) ;
if ( F_102 ( V_81 , V_157 + V_159 ) )
V_50 -> V_152 -> V_77 = F_103 ( V_50 -> V_152 -> V_77 +
V_160 ,
V_161 ) ;
return V_50 -> V_67 ;
}
static void F_104 ( struct V_14 * V_15 , unsigned int V_84 ,
unsigned long V_109 , bool V_162 )
{
int V_163 = V_109 ? V_114 : V_83 ;
F_25 ( V_163 , & V_15 -> V_39 ) ;
if ( V_15 -> V_82 == V_55 ) {
V_15 -> V_82 = V_84 ;
V_15 -> V_164 = V_81 ;
} else if ( V_15 -> V_82 != V_31 &&
V_15 -> V_82 != V_84 ) {
V_15 -> V_82 = V_31 ;
}
if ( V_15 -> V_17 -> V_165 )
V_15 -> V_17 -> V_165 ( V_15 , V_162 ) ;
F_105 ( V_15 , V_162 ) ;
}
void F_106 ( struct V_166 * V_167 , const char * V_168 , ... )
{
struct V_169 V_170 ;
T_1 args ;
va_start ( args , V_168 ) ;
if ( V_167 ) {
F_107 ( V_167 , V_168 , args ) ;
} else {
V_170 . V_168 = V_168 ;
V_170 . V_171 = & args ;
F_61 ( V_93 L_2 , & V_170 ) ;
}
va_end ( args ) ;
}
static inline void F_108 ( struct V_49 * V_50 )
__releases( &gl->gl_spin
int F_109 ( struct V_49 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_152 ;
struct V_1 * V_2 = V_15 -> V_24 ;
int error = 0 ;
if ( F_58 ( F_48 ( V_172 , & V_2 -> V_173 ) ) )
return - V_68 ;
if ( F_48 ( V_38 , & V_15 -> V_39 ) )
F_30 ( V_15 ) ;
F_22 ( & V_15 -> V_87 ) ;
F_108 ( V_50 ) ;
if ( ( V_174 & V_50 -> V_56 ) &&
F_62 ( V_175 , & V_15 -> V_39 ) )
F_25 ( V_112 , & V_15 -> V_39 ) ;
F_64 ( V_15 , 1 ) ;
F_26 ( & V_15 -> V_87 ) ;
if ( ! ( V_50 -> V_56 & V_176 ) )
error = F_99 ( V_50 ) ;
return error ;
}
int F_110 ( struct V_49 * V_50 )
{
return F_48 ( V_61 , & V_50 -> V_62 ) ? 0 : 1 ;
}
void F_111 ( struct V_49 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_152 ;
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned V_109 = 0 ;
int V_177 = 0 ;
F_22 ( & V_15 -> V_87 ) ;
if ( V_50 -> V_56 & V_178 )
F_104 ( V_15 , V_31 , 0 , false ) ;
F_23 ( & V_50 -> V_53 ) ;
if ( F_63 ( V_15 ) == NULL ) {
if ( V_29 -> V_179 ) {
F_16 ( V_15 , F_112 ( V_96 , & V_15 -> V_39 ) ) ;
F_26 ( & V_15 -> V_87 ) ;
V_29 -> V_179 ( V_50 ) ;
F_22 ( & V_15 -> V_87 ) ;
F_29 ( V_96 , & V_15 -> V_39 ) ;
}
if ( F_20 ( & V_15 -> V_32 ) &&
! F_48 ( V_114 , & V_15 -> V_39 ) &&
! F_48 ( V_83 , & V_15 -> V_39 ) )
V_177 = 1 ;
}
if ( ! F_48 ( V_180 , & V_15 -> V_39 ) && F_19 ( V_15 ) )
F_21 ( V_15 ) ;
F_49 ( V_50 , 0 ) ;
F_26 ( & V_15 -> V_87 ) ;
if ( F_113 ( V_177 ) )
return;
F_15 ( V_15 ) ;
if ( F_48 ( V_114 , & V_15 -> V_39 ) &&
! F_48 ( V_83 , & V_15 -> V_39 ) &&
V_15 -> V_48 . V_8 == V_117 )
V_109 = V_15 -> V_77 ;
if ( F_73 ( V_118 , & V_15 -> V_110 , V_109 ) == 0 )
F_32 ( V_15 ) ;
}
void F_114 ( struct V_49 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_152 ;
F_111 ( V_50 ) ;
F_100 () ;
F_101 ( & V_15 -> V_39 , V_83 , F_98 , V_158 ) ;
}
void F_115 ( struct V_49 * V_50 )
{
F_111 ( V_50 ) ;
F_95 ( V_50 ) ;
}
int F_116 ( struct V_1 * V_2 , V_7 V_119 ,
const struct V_28 * V_29 ,
unsigned int V_84 , int V_146 , struct V_49 * V_50 )
{
struct V_14 * V_15 ;
int error ;
error = F_74 ( V_2 , V_119 , V_29 , V_181 , & V_15 ) ;
if ( ! error ) {
error = F_117 ( V_15 , V_84 , V_146 , V_50 ) ;
F_32 ( V_15 ) ;
}
return error ;
}
static int F_118 ( const void * V_182 , const void * V_183 )
{
const struct V_49 * V_184 = * ( const struct V_49 * * ) V_182 ;
const struct V_49 * V_185 = * ( const struct V_49 * * ) V_183 ;
const struct V_3 * V_186 = & V_184 -> V_152 -> V_48 ;
const struct V_3 * V_187 = & V_185 -> V_152 -> V_48 ;
if ( V_186 -> V_6 > V_187 -> V_6 )
return 1 ;
if ( V_186 -> V_6 < V_187 -> V_6 )
return - 1 ;
F_119 ( V_184 -> V_152 -> V_17 -> V_124 == V_185 -> V_152 -> V_17 -> V_124 ) ;
return 0 ;
}
static int F_120 ( unsigned int V_188 , struct V_49 * V_189 ,
struct V_49 * * V_190 )
{
unsigned int V_191 ;
int error = 0 ;
for ( V_191 = 0 ; V_191 < V_188 ; V_191 ++ )
V_190 [ V_191 ] = & V_189 [ V_191 ] ;
F_121 ( V_190 , V_188 , sizeof( struct V_49 * ) , F_118 , NULL ) ;
for ( V_191 = 0 ; V_191 < V_188 ; V_191 ++ ) {
V_190 [ V_191 ] -> V_56 &= ~ ( V_69 | V_176 ) ;
error = F_109 ( V_190 [ V_191 ] ) ;
if ( error ) {
while ( V_191 -- )
F_111 ( V_190 [ V_191 ] ) ;
break;
}
}
return error ;
}
int F_122 ( unsigned int V_188 , struct V_49 * V_189 )
{
struct V_49 * V_64 [ 4 ] ;
struct V_49 * * V_192 = V_64 ;
int error = 0 ;
switch( V_188 ) {
case 0 :
return 0 ;
case 1 :
V_189 -> V_56 &= ~ ( V_69 | V_176 ) ;
return F_109 ( V_189 ) ;
default:
if ( V_188 <= 4 )
break;
V_192 = F_123 ( V_188 * sizeof( struct V_49 * ) , V_147 ) ;
if ( ! V_192 )
return - V_129 ;
}
error = F_120 ( V_188 , V_189 , V_192 ) ;
if ( V_192 != V_64 )
F_10 ( V_192 ) ;
return error ;
}
void F_124 ( unsigned int V_188 , struct V_49 * V_189 )
{
while ( V_188 -- )
F_111 ( & V_189 [ V_188 ] ) ;
}
void F_125 ( struct V_14 * V_15 , unsigned int V_84 )
{
unsigned long V_109 = 0 ;
unsigned long V_115 ;
unsigned long V_116 = V_81 ;
F_15 ( V_15 ) ;
V_115 = V_15 -> V_80 + V_15 -> V_77 ;
if ( F_48 ( V_75 , & V_15 -> V_39 ) &&
V_15 -> V_48 . V_8 == V_117 ) {
if ( F_72 ( V_116 , V_115 ) )
V_109 = V_115 - V_116 ;
if ( F_48 ( V_112 , & V_15 -> V_39 ) )
V_109 = V_15 -> V_77 ;
}
F_22 ( & V_15 -> V_87 ) ;
F_104 ( V_15 , V_84 , V_109 , true ) ;
F_26 ( & V_15 -> V_87 ) ;
if ( F_73 ( V_118 , & V_15 -> V_110 , V_109 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_126 ( const struct V_14 * V_15 )
{
const struct V_49 * V_50 ;
if ( V_15 -> V_113 & ~ V_85 )
return 0 ;
if ( V_15 -> V_76 == V_31 )
return 0 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( F_48 ( V_65 , & V_50 -> V_62 ) )
continue;
if ( V_174 & V_50 -> V_56 )
return 0 ;
}
return 1 ;
}
void F_127 ( struct V_14 * V_15 , int V_63 )
{
struct V_193 * V_194 = & V_15 -> V_24 -> V_44 ;
F_22 ( & V_15 -> V_87 ) ;
V_15 -> V_113 = V_63 ;
if ( F_58 ( F_48 ( V_195 , & V_194 -> V_196 ) ) ) {
if ( F_126 ( V_15 ) ) {
F_25 ( V_175 , & V_15 -> V_39 ) ;
F_26 ( & V_15 -> V_87 ) ;
return;
}
}
F_26 ( & V_15 -> V_87 ) ;
F_25 ( V_112 , & V_15 -> V_39 ) ;
F_128 () ;
F_15 ( V_15 ) ;
if ( F_73 ( V_118 , & V_15 -> V_110 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_129 ( void * V_197 , struct V_198 * V_186 , struct V_198 * V_187 )
{
struct V_14 * V_199 , * V_200 ;
V_199 = F_42 ( V_186 , struct V_14 , V_35 ) ;
V_200 = F_42 ( V_187 , struct V_14 , V_35 ) ;
if ( V_199 -> V_48 . V_6 > V_200 -> V_48 . V_6 )
return 1 ;
if ( V_199 -> V_48 . V_6 < V_200 -> V_48 . V_6 )
return - 1 ;
return 0 ;
}
static void F_130 ( struct V_198 * V_201 )
__releases( &lru_lock
static long F_131 ( int V_202 )
{
struct V_14 * V_15 ;
F_132 ( V_203 ) ;
F_132 ( V_204 ) ;
long V_205 = 0 ;
F_22 ( & V_34 ) ;
while ( ( V_202 -- >= 0 ) && ! F_20 ( & V_37 ) ) {
V_15 = F_42 ( V_37 . V_52 , struct V_14 , V_35 ) ;
if ( ! F_112 ( V_96 , & V_15 -> V_39 ) ) {
F_133 ( & V_15 -> V_35 , & V_204 ) ;
F_28 ( & V_36 ) ;
V_205 ++ ;
continue;
}
F_133 ( & V_15 -> V_35 , & V_203 ) ;
}
F_134 ( & V_203 , & V_37 ) ;
if ( ! F_20 ( & V_204 ) )
F_130 ( & V_204 ) ;
F_26 ( & V_34 ) ;
return V_205 ;
}
static unsigned long F_135 ( struct V_206 * V_207 ,
struct V_208 * V_209 )
{
if ( ! ( V_209 -> V_210 & V_211 ) )
return V_212 ;
return F_131 ( V_209 -> V_213 ) ;
}
static unsigned long F_136 ( struct V_206 * V_207 ,
struct V_208 * V_209 )
{
return F_137 ( F_17 ( & V_36 ) ) ;
}
static void F_138 ( T_2 V_214 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_215 * V_216 = & V_11 [ V_10 ] ;
struct V_47 * V_217 ;
F_75 () ;
F_38 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_24 == V_2 ) && F_40 ( & V_15 -> V_27 ) )
V_214 ( V_15 ) ;
}
F_76 () ;
F_139 () ;
}
static void F_140 ( T_2 V_214 , const struct V_1 * V_2 )
{
unsigned V_191 ;
for ( V_191 = 0 ; V_191 < V_218 ; V_191 ++ )
F_138 ( V_214 , V_2 , V_191 ) ;
}
static void F_141 ( struct V_14 * V_15 )
{
if ( ! F_62 ( V_175 , & V_15 -> V_39 ) )
goto V_92;
F_25 ( V_112 , & V_15 -> V_39 ) ;
if ( F_73 ( V_118 , & V_15 -> V_110 , 0 ) == 0 ) {
V_92:
F_32 ( V_15 ) ;
}
}
static void F_142 ( struct V_14 * V_15 )
{
F_30 ( V_15 ) ;
F_22 ( & V_15 -> V_87 ) ;
if ( V_15 -> V_30 != V_31 )
F_104 ( V_15 , V_31 , 0 , false ) ;
F_26 ( & V_15 -> V_87 ) ;
if ( F_73 ( V_118 , & V_15 -> V_110 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
void F_143 ( struct V_1 * V_2 )
{
F_140 ( F_141 , V_2 ) ;
}
static int F_144 ( struct V_166 * V_167 , struct V_14 * V_15 )
{
int V_63 ;
F_22 ( & V_15 -> V_87 ) ;
V_63 = F_145 ( V_167 , V_15 ) ;
F_26 ( & V_15 -> V_87 ) ;
return V_63 ;
}
static void F_146 ( struct V_14 * V_15 )
{
F_144 ( NULL , V_15 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
F_25 ( V_219 , & V_2 -> V_173 ) ;
F_148 ( V_118 ) ;
F_140 ( F_142 , V_2 ) ;
F_148 ( V_118 ) ;
F_149 ( V_2 -> V_26 , F_17 ( & V_2 -> V_25 ) == 0 ) ;
F_140 ( F_146 , V_2 ) ;
}
void F_150 ( struct V_102 * V_103 )
{
struct V_14 * V_15 = V_103 -> V_220 ;
int V_63 ;
V_63 = F_151 ( V_103 ) ;
F_152 ( V_15 -> V_24 , V_63 == 0 ) ;
F_22 ( & V_15 -> V_87 ) ;
F_29 ( V_96 , & V_15 -> V_39 ) ;
F_64 ( V_15 , 1 ) ;
F_26 ( & V_15 -> V_87 ) ;
}
static const char * F_153 ( unsigned V_84 )
{
switch( V_84 ) {
case V_31 :
return L_3 ;
case V_58 :
return L_4 ;
case V_59 :
return L_5 ;
case V_55 :
return L_6 ;
}
return L_7 ;
}
static const char * F_154 ( char * V_221 , unsigned V_146 , unsigned long V_222 )
{
char * V_190 = V_221 ;
if ( V_146 & V_69 )
* V_190 ++ = 't' ;
if ( V_146 & V_70 )
* V_190 ++ = 'T' ;
if ( V_146 & V_174 )
* V_190 ++ = 'e' ;
if ( V_146 & V_60 )
* V_190 ++ = 'A' ;
if ( V_146 & V_90 )
* V_190 ++ = 'p' ;
if ( V_146 & V_176 )
* V_190 ++ = 'a' ;
if ( V_146 & V_57 )
* V_190 ++ = 'E' ;
if ( V_146 & V_178 )
* V_190 ++ = 'c' ;
if ( F_48 ( V_65 , & V_222 ) )
* V_190 ++ = 'H' ;
if ( F_48 ( V_61 , & V_222 ) )
* V_190 ++ = 'W' ;
if ( F_48 ( V_223 , & V_222 ) )
* V_190 ++ = 'F' ;
* V_190 = 0 ;
return V_221 ;
}
static int F_155 ( struct V_166 * V_167 , const struct V_49 * V_50 )
{
struct V_224 * V_225 = NULL ;
char V_226 [ 32 ] ;
if ( V_50 -> V_154 )
V_225 = F_156 ( V_50 -> V_154 , V_227 ) ;
F_106 ( V_167 , L_8 ,
F_153 ( V_50 -> V_54 ) ,
F_154 ( V_226 , V_50 -> V_56 , V_50 -> V_62 ) ,
V_50 -> V_67 ,
V_50 -> V_154 ? ( long ) F_157 ( V_50 -> V_154 ) : - 1 ,
V_225 ? V_225 -> V_228 : L_9 ,
( void * ) V_50 -> V_153 ) ;
return 0 ;
}
static const char * F_158 ( char * V_221 , const struct V_14 * V_15 )
{
const unsigned long * V_229 = & V_15 -> V_39 ;
char * V_190 = V_221 ;
if ( F_48 ( V_96 , V_229 ) )
* V_190 ++ = 'l' ;
if ( F_48 ( V_83 , V_229 ) )
* V_190 ++ = 'D' ;
if ( F_48 ( V_114 , V_229 ) )
* V_190 ++ = 'd' ;
if ( F_48 ( V_88 , V_229 ) )
* V_190 ++ = 'p' ;
if ( F_48 ( V_230 , V_229 ) )
* V_190 ++ = 'y' ;
if ( F_48 ( V_180 , V_229 ) )
* V_190 ++ = 'f' ;
if ( F_48 ( V_231 , V_229 ) )
* V_190 ++ = 'i' ;
if ( F_48 ( V_112 , V_229 ) )
* V_190 ++ = 'r' ;
if ( F_48 ( V_232 , V_229 ) )
* V_190 ++ = 'I' ;
if ( F_48 ( V_175 , V_229 ) )
* V_190 ++ = 'F' ;
if ( F_48 ( V_75 , V_229 ) )
* V_190 ++ = 'q' ;
if ( F_48 ( V_38 , V_229 ) )
* V_190 ++ = 'L' ;
if ( V_15 -> V_106 )
* V_190 ++ = 'o' ;
if ( F_48 ( V_233 , V_229 ) )
* V_190 ++ = 'b' ;
* V_190 = 0 ;
return V_221 ;
}
int F_145 ( struct V_166 * V_167 , const struct V_14 * V_15 )
{
const struct V_28 * V_29 = V_15 -> V_17 ;
unsigned long long V_234 ;
const struct V_49 * V_50 ;
char V_235 [ 32 ] ;
int error = 0 ;
V_234 = V_81 - V_15 -> V_164 ;
V_234 *= 1000000 / V_159 ;
if ( ! F_48 ( V_83 , & V_15 -> V_39 ) )
V_234 = 0 ;
F_106 ( V_167 , L_10 ,
F_153 ( V_15 -> V_30 ) ,
V_15 -> V_48 . V_8 ,
( unsigned long long ) V_15 -> V_48 . V_6 ,
F_158 ( V_235 , V_15 ) ,
F_153 ( V_15 -> V_76 ) ,
F_153 ( V_15 -> V_82 ) , V_234 ,
F_17 ( & V_15 -> V_236 ) ,
F_17 ( & V_15 -> V_237 ) ,
F_17 ( & V_15 -> V_27 ) , V_15 -> V_77 ) ;
F_52 (gh, &gl->gl_holders, gh_list) {
error = F_155 ( V_167 , V_50 ) ;
if ( error )
goto V_92;
}
if ( V_15 -> V_30 != V_31 && V_29 -> V_238 )
error = V_29 -> V_238 ( V_167 , V_15 ) ;
V_92:
return error ;
}
static int F_159 ( struct V_166 * V_167 , void * V_239 )
{
struct V_14 * V_15 = V_239 ;
F_160 ( V_167 , L_11 ,
V_15 -> V_48 . V_8 ,
( unsigned long long ) V_15 -> V_48 . V_6 ,
( long long ) V_15 -> V_134 . V_137 [ V_240 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_241 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_242 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_243 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_244 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_245 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_138 ] ,
( long long ) V_15 -> V_134 . V_137 [ V_139 ] ) ;
return 0 ;
}
static int F_161 ( struct V_166 * V_167 , void * V_239 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
struct V_1 * V_2 = V_247 -> V_2 ;
unsigned V_249 = V_247 -> V_10 >> 3 ;
unsigned V_250 = V_247 -> V_10 & 0x07 ;
T_3 V_251 ;
int V_252 ;
if ( V_249 == 0 && V_250 != 0 )
return 0 ;
F_160 ( V_167 , L_12 , V_253 [ V_249 ] ,
( V_249 == 0 ) ? L_13 : V_254 [ V_250 ] ) ;
F_162 (i) {
const struct V_255 * V_136 = F_163 ( V_2 -> V_135 , V_252 ) ;
if ( V_249 == 0 ) {
V_251 = V_252 ;
} else {
V_251 = V_136 -> V_136 [ V_249 - 1 ] . V_137 [ V_250 ] ;
}
F_160 ( V_167 , L_14 , ( long long ) V_251 ) ;
}
F_164 ( V_167 , '\n' ) ;
return 0 ;
}
int T_4 F_165 ( void )
{
unsigned V_252 ;
for( V_252 = 0 ; V_252 < V_218 ; V_252 ++ ) {
F_166 ( & V_11 [ V_252 ] ) ;
}
V_118 = F_167 ( L_15 , V_256 |
V_257 | V_258 , 0 ) ;
if ( ! V_118 )
return - V_129 ;
V_259 = F_167 ( L_16 ,
V_256 | V_258 ,
0 ) ;
if ( ! V_259 ) {
F_168 ( V_118 ) ;
return - V_129 ;
}
F_169 ( & V_260 ) ;
return 0 ;
}
void F_170 ( void )
{
F_171 ( & V_260 ) ;
F_168 ( V_118 ) ;
F_168 ( V_259 ) ;
}
static inline struct V_14 * F_172 ( unsigned V_10 )
{
return F_173 ( F_174 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_42 ) ;
}
static inline struct V_14 * F_175 ( struct V_14 * V_15 )
{
return F_173 ( F_176 ( V_15 -> V_42 . V_52 ) ,
struct V_14 , V_42 ) ;
}
static int F_177 ( struct V_246 * V_247 )
{
struct V_14 * V_15 ;
do {
V_15 = V_247 -> V_15 ;
if ( V_15 ) {
V_247 -> V_15 = F_175 ( V_15 ) ;
V_247 -> V_261 ++ ;
} else {
if ( V_247 -> V_10 >= V_218 ) {
F_76 () ;
return 1 ;
}
V_247 -> V_15 = F_172 ( V_247 -> V_10 ) ;
V_247 -> V_261 = 0 ;
}
while ( V_247 -> V_15 == NULL ) {
V_247 -> V_10 ++ ;
if ( V_247 -> V_10 >= V_218 ) {
F_76 () ;
return 1 ;
}
V_247 -> V_15 = F_172 ( V_247 -> V_10 ) ;
V_247 -> V_261 = 0 ;
}
} while ( V_247 -> V_2 != V_247 -> V_15 -> V_24 || F_17 ( & V_247 -> V_15 -> V_27 ) == 0 );
return 0 ;
}
static void * F_178 ( struct V_166 * V_167 , T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
T_5 V_262 = * V_217 ;
if ( V_247 -> V_263 <= * V_217 )
V_262 = V_247 -> V_261 + ( * V_217 - V_247 -> V_263 ) ;
else
V_247 -> V_10 = 0 ;
V_247 -> V_261 = 0 ;
F_75 () ;
do {
if ( F_177 ( V_247 ) )
return NULL ;
} while ( V_262 -- );
V_247 -> V_263 = * V_217 ;
return V_247 -> V_15 ;
}
static void * F_179 ( struct V_166 * V_167 , void * V_239 ,
T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
( * V_217 ) ++ ;
V_247 -> V_263 = * V_217 ;
if ( F_177 ( V_247 ) )
return NULL ;
return V_247 -> V_15 ;
}
static void F_180 ( struct V_166 * V_167 , void * V_239 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
if ( V_247 -> V_15 )
F_76 () ;
V_247 -> V_15 = NULL ;
}
static int F_181 ( struct V_166 * V_167 , void * V_239 )
{
return F_144 ( V_167 , V_239 ) ;
}
static void * F_182 ( struct V_166 * V_167 , T_5 * V_217 )
{
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_10 = * V_217 ;
if ( * V_217 >= V_264 )
return NULL ;
F_81 () ;
return V_265 ;
}
static void * F_183 ( struct V_166 * V_167 , void * V_239 ,
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
static void F_184 ( struct V_166 * V_167 , void * V_239 )
{
F_83 () ;
}
static int F_185 ( struct V_104 * V_104 , struct V_266 * V_266 )
{
int V_63 = F_186 ( V_266 , & V_267 ,
sizeof( struct V_246 ) ) ;
if ( V_63 == 0 ) {
struct V_166 * V_167 = V_266 -> V_148 ;
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_2 = V_104 -> V_268 ;
V_167 -> V_221 = F_123 ( V_269 , V_128 | V_270 ) ;
if ( V_167 -> V_221 )
V_167 -> V_271 = V_269 ;
}
return V_63 ;
}
static int F_187 ( struct V_104 * V_104 , struct V_266 * V_266 )
{
int V_63 = F_186 ( V_266 , & V_272 ,
sizeof( struct V_246 ) ) ;
if ( V_63 == 0 ) {
struct V_166 * V_167 = V_266 -> V_148 ;
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_2 = V_104 -> V_268 ;
V_167 -> V_221 = F_123 ( V_269 , V_128 | V_270 ) ;
if ( V_167 -> V_221 )
V_167 -> V_271 = V_269 ;
}
return V_63 ;
}
static int F_188 ( struct V_104 * V_104 , struct V_266 * V_266 )
{
int V_63 = F_186 ( V_266 , & V_273 ,
sizeof( struct V_246 ) ) ;
if ( V_63 == 0 ) {
struct V_166 * V_167 = V_266 -> V_148 ;
struct V_246 * V_247 = V_167 -> V_248 ;
V_247 -> V_2 = V_104 -> V_268 ;
}
return V_63 ;
}
int F_189 ( struct V_1 * V_2 )
{
V_2 -> V_274 = F_190 ( V_2 -> V_275 , V_276 ) ;
if ( ! V_2 -> V_274 )
return - V_129 ;
V_2 -> V_277 = F_191 ( L_17 ,
V_278 | V_279 ,
V_2 -> V_274 , V_2 ,
& V_280 ) ;
if ( ! V_2 -> V_277 )
goto V_281;
V_2 -> V_282 = F_191 ( L_18 ,
V_278 | V_279 ,
V_2 -> V_274 , V_2 ,
& V_283 ) ;
if ( ! V_2 -> V_282 )
goto V_281;
V_2 -> V_284 = F_191 ( L_19 ,
V_278 | V_279 ,
V_2 -> V_274 , V_2 ,
& V_285 ) ;
if ( ! V_2 -> V_284 )
goto V_281;
return 0 ;
V_281:
F_192 ( V_2 ) ;
return - V_129 ;
}
void F_192 ( struct V_1 * V_2 )
{
if ( V_2 -> V_274 ) {
if ( V_2 -> V_277 ) {
F_193 ( V_2 -> V_277 ) ;
V_2 -> V_277 = NULL ;
}
if ( V_2 -> V_282 ) {
F_193 ( V_2 -> V_282 ) ;
V_2 -> V_282 = NULL ;
}
if ( V_2 -> V_284 ) {
F_193 ( V_2 -> V_284 ) ;
V_2 -> V_284 = NULL ;
}
F_193 ( V_2 -> V_274 ) ;
V_2 -> V_274 = NULL ;
}
}
int F_194 ( void )
{
V_276 = F_190 ( L_20 , NULL ) ;
return V_276 ? 0 : - V_129 ;
}
void F_195 ( void )
{
F_193 ( V_276 ) ;
V_276 = NULL ;
}
