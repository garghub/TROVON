void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
if ( V_2 -> V_7 -> V_8 & V_9 ) {
F_2 ( V_10 , V_2 ) ;
} else {
F_3 ( V_2 -> V_11 . V_12 ) ;
F_2 ( V_13 , V_2 ) ;
}
if ( F_4 ( & V_4 -> V_14 ) )
F_5 ( & V_4 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , F_8 ( & V_2 -> V_16 ) ) ;
F_9 ( & V_2 -> V_16 ) ;
}
static int F_10 ( const struct V_1 * V_2 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
if ( V_2 -> V_19 == V_20 )
return 0 ;
if ( ! F_11 ( & V_2 -> V_21 ) )
return 0 ;
if ( V_18 -> V_22 )
return V_18 -> V_22 ( V_2 ) ;
return 1 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_23 ) ;
if ( ! F_11 ( & V_2 -> V_24 ) )
F_14 ( & V_2 -> V_24 ) ;
else
F_15 ( & V_25 ) ;
F_16 ( & V_2 -> V_24 , & V_26 ) ;
F_17 ( V_27 , & V_2 -> V_28 ) ;
F_18 ( & V_23 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_13 ( & V_23 ) ;
if ( ! F_11 ( & V_2 -> V_24 ) ) {
F_14 ( & V_2 -> V_24 ) ;
F_20 ( & V_25 ) ;
F_21 ( V_27 , & V_2 -> V_28 ) ;
}
F_18 ( & V_23 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_29 * V_30 = F_23 ( V_2 ) ;
if ( F_24 ( & V_2 -> V_16 ) )
return;
F_25 ( & V_2 -> V_16 ) ;
F_19 ( V_2 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
F_26 ( & V_32 , & V_2 -> V_33 , V_34 ) ;
F_7 ( V_2 , ! F_11 ( & V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_30 && V_30 -> V_35 ) ;
F_27 ( V_2 ) ;
V_4 -> V_36 . V_37 -> V_38 ( V_2 ) ;
}
static inline int F_28 ( const struct V_1 * V_2 , const struct V_39 * V_40 )
{
const struct V_39 * V_41 = F_29 ( V_2 -> V_21 . V_42 , const struct V_39 , V_43 ) ;
if ( ( V_40 -> V_44 == V_45 ||
V_41 -> V_44 == V_45 ) && V_40 != V_41 )
return 0 ;
if ( V_2 -> V_19 == V_40 -> V_44 )
return 1 ;
if ( V_40 -> V_46 & V_47 )
return 0 ;
if ( V_2 -> V_19 == V_45 ) {
if ( V_40 -> V_44 == V_48 && V_41 -> V_44 == V_48 )
return 1 ;
if ( V_40 -> V_44 == V_49 && V_41 -> V_44 == V_49 )
return 1 ;
}
if ( V_2 -> V_19 != V_20 && ( V_40 -> V_46 & V_50 ) )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_39 * V_40 )
{
F_21 ( V_51 , & V_40 -> V_52 ) ;
F_31 () ;
F_32 ( & V_40 -> V_52 , V_51 ) ;
}
static inline void F_33 ( struct V_1 * V_2 , const int V_53 )
{
struct V_39 * V_40 , * V_54 ;
F_34 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
continue;
if ( V_53 & V_56 )
V_40 -> V_57 = - V_58 ;
else if ( V_40 -> V_46 & ( V_59 | V_60 ) )
V_40 -> V_57 = V_61 ;
else
continue;
F_14 ( & V_40 -> V_43 ) ;
F_36 ( V_40 , 0 ) ;
F_30 ( V_40 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
__releases( &gl->gl_lockref.lock
static inline struct V_39 * F_38 ( const struct V_1 * V_2 )
{
struct V_39 * V_40 ;
F_39 (gh, &gl->gl_holders, gh_list) {
if ( ! F_35 ( V_55 , & V_40 -> V_52 ) )
return V_40 ;
}
return NULL ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_62 )
{
int V_63 , V_64 ;
V_63 = ( V_2 -> V_19 != V_20 ) ;
V_64 = ( V_62 != V_20 ) ;
if ( V_63 != V_64 ) {
F_7 ( V_2 , F_8 ( & V_2 -> V_16 ) ) ;
if ( V_64 )
V_2 -> V_16 . V_65 ++ ;
else
V_2 -> V_16 . V_65 -- ;
}
if ( V_63 && V_64 && F_11 ( & V_2 -> V_21 ) )
F_21 ( V_66 , & V_2 -> V_28 ) ;
if ( V_62 != V_2 -> V_67 )
V_2 -> V_68 = F_41 ( V_2 -> V_68 - V_69 ,
V_70 ) ;
V_2 -> V_19 = V_62 ;
V_2 -> V_71 = V_72 ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_73 = V_45 ;
F_21 ( V_74 , & V_2 -> V_28 ) ;
F_31 () ;
F_32 ( & V_2 -> V_28 , V_74 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_53 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
struct V_39 * V_40 ;
unsigned V_75 = V_53 & V_76 ;
int V_77 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_44 ( V_2 , V_75 ) ;
F_40 ( V_2 , V_75 ) ;
V_40 = F_38 ( V_2 ) ;
if ( F_35 ( V_78 , & V_2 -> V_28 ) &&
V_75 != V_20 && V_2 -> V_73 == V_20 )
V_2 -> V_67 = V_20 ;
if ( F_45 ( V_75 != V_2 -> V_67 ) ) {
if ( V_40 && ! F_35 ( V_78 , & V_2 -> V_28 ) ) {
if ( V_53 & V_79 ) {
if ( ( V_40 -> V_46 & V_80 ) == 0 )
F_46 ( & V_40 -> V_43 , & V_2 -> V_21 ) ;
V_40 = F_38 ( V_2 ) ;
V_2 -> V_67 = V_40 -> V_44 ;
goto V_81;
}
if ( ( V_53 & V_56 ) ||
( V_40 -> V_46 & ( V_59 | V_60 ) ) ) {
V_2 -> V_67 = V_2 -> V_19 ;
F_33 ( V_2 , V_53 ) ;
goto V_82;
}
}
switch( V_75 ) {
case V_20 :
V_81:
F_47 ( V_2 , V_40 , V_2 -> V_67 ) ;
break;
case V_48 :
case V_49 :
F_47 ( V_2 , V_40 , V_20 ) ;
break;
default:
F_48 ( L_1 , V_2 -> V_67 , V_75 ) ;
F_7 ( V_2 , 1 ) ;
}
F_18 ( & V_2 -> V_16 . V_31 ) ;
return;
}
if ( F_49 ( V_78 , & V_2 -> V_28 ) )
F_42 ( V_2 ) ;
if ( V_75 != V_20 ) {
if ( V_18 -> V_83 ) {
F_18 ( & V_2 -> V_16 . V_31 ) ;
V_77 = V_18 -> V_83 ( V_2 , V_40 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_77 ) {
F_33 ( V_2 , V_77 ) ;
goto V_82;
}
}
V_77 = F_37 ( V_2 ) ;
if ( V_77 == 2 )
goto V_84;
}
V_82:
F_21 ( V_85 , & V_2 -> V_28 ) ;
V_84:
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_39 * V_40 , unsigned int V_86 )
__releases( &gl->gl_lockref.lock
static inline struct V_39 * F_50 ( const struct V_1 * V_2 )
{
struct V_39 * V_40 ;
if ( ! F_11 ( & V_2 -> V_21 ) ) {
V_40 = F_29 ( V_2 -> V_21 . V_42 , struct V_39 , V_43 ) ;
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
return V_40 ;
}
return NULL ;
}
static void F_51 ( struct V_1 * V_2 , const int V_87 )
__releases( &gl->gl_lockref.lock
static void F_52 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_53 ( V_89 , struct V_1 , V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_91 * V_92 ;
struct V_93 * V_93 ;
T_1 V_94 = V_2 -> V_5 . V_95 ;
V_92 = V_2 -> V_96 ;
if ( V_92 )
V_93 = F_54 ( V_4 -> V_97 , V_94 , 1 ) ;
else
V_93 = F_55 ( V_4 , V_94 , NULL , V_98 ) ;
if ( V_93 && ! F_56 ( V_93 ) ) {
F_57 ( V_93 ) ;
F_58 ( V_93 ) ;
}
F_22 ( V_2 ) ;
}
static void F_59 ( struct V_88 * V_89 )
{
unsigned long V_99 = 0 ;
struct V_1 * V_2 = F_53 ( V_89 , struct V_1 , V_100 . V_89 ) ;
int V_101 = 0 ;
if ( F_49 ( V_102 , & V_2 -> V_28 ) ) {
F_43 ( V_2 , V_2 -> V_103 ) ;
V_101 = 1 ;
}
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( F_35 ( V_104 , & V_2 -> V_28 ) &&
V_2 -> V_19 != V_20 &&
V_2 -> V_73 != V_45 ) {
unsigned long V_105 , V_106 = V_72 ;
V_105 = V_2 -> V_71 + V_2 -> V_68 ;
if ( F_60 ( V_106 , V_105 ) )
V_99 = V_105 - V_106 ;
if ( ! V_99 ) {
F_21 ( V_104 , & V_2 -> V_28 ) ;
F_17 ( V_74 , & V_2 -> V_28 ) ;
}
}
F_51 ( V_2 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! V_99 )
F_22 ( V_2 ) ;
else {
if ( V_2 -> V_5 . V_107 != V_108 )
V_99 = 0 ;
if ( F_61 ( V_109 , & V_2 -> V_100 , V_99 ) == 0 )
F_22 ( V_2 ) ;
}
if ( V_101 )
F_22 ( V_2 ) ;
}
int F_62 ( struct V_3 * V_4 , T_1 V_110 ,
const struct V_17 * V_18 , int V_111 ,
struct V_1 * * V_112 )
{
struct V_113 * V_114 = V_4 -> V_97 ;
struct V_115 V_116 = { . V_95 = V_110 ,
. V_107 = V_18 -> V_117 ,
. V_6 = V_4 } ;
struct V_1 * V_2 , * V_54 = NULL ;
struct V_29 * V_30 ;
struct V_118 * V_119 ;
int V_53 , V_120 = 0 ;
V_2 = F_63 ( & V_32 , & V_116 , V_34 ) ;
if ( V_2 && ! F_64 ( & V_2 -> V_16 ) )
V_2 = NULL ;
* V_112 = V_2 ;
if ( V_2 )
return 0 ;
if ( ! V_111 )
return - V_121 ;
if ( V_18 -> V_8 & V_9 )
V_119 = V_10 ;
else
V_119 = V_13 ;
V_2 = F_65 ( V_119 , V_122 ) ;
if ( ! V_2 )
return - V_123 ;
memset ( & V_2 -> V_11 , 0 , sizeof( struct V_124 ) ) ;
if ( V_18 -> V_8 & V_125 ) {
V_2 -> V_11 . V_12 = F_66 ( V_126 , V_122 ) ;
if ( ! V_2 -> V_11 . V_12 ) {
F_2 ( V_119 , V_2 ) ;
return - V_123 ;
}
}
F_15 ( & V_4 -> V_14 ) ;
V_2 -> V_33 . V_42 = NULL ;
V_2 -> V_28 = 0 ;
V_2 -> V_5 = V_116 ;
V_2 -> V_16 . V_65 = 1 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_67 = V_20 ;
V_2 -> V_73 = V_45 ;
V_2 -> V_7 = V_18 ;
V_2 -> V_127 = F_67 ( 0 , 0 ) ;
F_68 () ;
V_2 -> V_128 = F_69 ( V_4 -> V_129 ) -> V_130 [ V_18 -> V_117 ] ;
F_70 () ;
V_2 -> V_128 . V_131 [ V_132 ] = 0 ;
V_2 -> V_128 . V_131 [ V_133 ] = 0 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_96 = NULL ;
V_2 -> V_68 = V_134 ;
F_71 ( & V_2 -> V_100 , F_59 ) ;
F_72 ( & V_2 -> V_90 , F_52 ) ;
V_30 = F_23 ( V_2 ) ;
if ( V_30 ) {
V_30 -> V_135 = & V_136 ;
V_30 -> V_137 = V_114 -> V_138 -> V_139 ;
V_30 -> V_140 = 0 ;
F_73 ( V_30 , V_122 ) ;
V_30 -> V_141 = NULL ;
V_30 -> V_142 = 0 ;
}
V_143:
V_53 = F_74 ( & V_32 , & V_2 -> V_33 ,
V_34 ) ;
if ( V_53 == 0 ) {
* V_112 = V_2 ;
return 0 ;
}
if ( V_53 == - V_144 ) {
V_53 = 0 ;
V_54 = F_63 ( & V_32 , & V_116 , V_34 ) ;
if ( V_54 == NULL || ! F_64 ( & V_54 -> V_16 ) ) {
if ( ++ V_120 < 100 ) {
F_75 () ;
goto V_143;
}
V_54 = NULL ;
V_53 = - V_123 ;
}
} else {
F_76 ( V_53 ) ;
}
F_3 ( V_2 -> V_11 . V_12 ) ;
F_2 ( V_119 , V_2 ) ;
F_20 ( & V_4 -> V_14 ) ;
* V_112 = V_54 ;
return V_53 ;
}
void F_77 ( struct V_1 * V_2 , unsigned int V_75 , unsigned V_140 ,
struct V_39 * V_40 )
{
F_78 ( & V_40 -> V_43 ) ;
V_40 -> V_145 = V_2 ;
V_40 -> V_146 = V_147 ;
V_40 -> V_148 = F_79 ( F_80 ( V_149 ) ) ;
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_140 ;
V_40 -> V_57 = 0 ;
V_40 -> V_52 = 0 ;
F_6 ( V_2 ) ;
}
void F_81 ( unsigned int V_75 , unsigned V_140 , struct V_39 * V_40 )
{
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_140 ;
V_40 -> V_52 = 0 ;
V_40 -> V_146 = V_147 ;
F_82 ( V_40 -> V_148 ) ;
V_40 -> V_148 = F_79 ( F_80 ( V_149 ) ) ;
}
void F_83 ( struct V_39 * V_40 )
{
F_82 ( V_40 -> V_148 ) ;
F_22 ( V_40 -> V_145 ) ;
V_40 -> V_145 = NULL ;
V_40 -> V_146 = 0 ;
}
int F_84 ( struct V_39 * V_40 )
{
unsigned long V_150 = V_72 ;
F_85 () ;
F_86 ( & V_40 -> V_52 , V_51 , V_151 ) ;
if ( F_87 ( V_72 , V_150 + V_152 ) )
V_40 -> V_145 -> V_68 = F_88 ( V_40 -> V_145 -> V_68 +
V_153 ,
V_154 ) ;
return V_40 -> V_57 ;
}
static void F_89 ( struct V_1 * V_2 , unsigned int V_75 ,
unsigned long V_99 , bool V_155 )
{
int V_156 = V_99 ? V_104 : V_74 ;
F_17 ( V_156 , & V_2 -> V_28 ) ;
if ( V_2 -> V_73 == V_45 ) {
V_2 -> V_73 = V_75 ;
V_2 -> V_157 = V_72 ;
} else if ( V_2 -> V_73 != V_20 &&
V_2 -> V_73 != V_75 ) {
V_2 -> V_73 = V_20 ;
}
if ( V_2 -> V_7 -> V_158 )
V_2 -> V_7 -> V_158 ( V_2 , V_155 ) ;
F_90 ( V_2 , V_155 ) ;
}
void F_91 ( struct V_159 * V_160 , const char * V_161 , ... )
{
struct V_162 V_163 ;
T_2 args ;
va_start ( args , V_161 ) ;
if ( V_160 ) {
F_92 ( V_160 , V_161 , args ) ;
} else {
V_163 . V_161 = V_161 ;
V_163 . V_164 = & args ;
F_48 ( L_2 , & V_163 ) ;
}
va_end ( args ) ;
}
static inline void F_93 ( struct V_39 * V_40 )
__releases( &gl->gl_lockref.lock
int F_94 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_145 ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int error = 0 ;
if ( F_45 ( F_35 ( V_165 , & V_4 -> V_166 ) ) )
return - V_58 ;
if ( F_35 ( V_27 , & V_2 -> V_28 ) )
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_93 ( V_40 ) ;
if ( F_45 ( ( V_167 & V_40 -> V_46 ) &&
F_49 ( V_168 , & V_2 -> V_28 ) ) ) {
F_17 ( V_102 , & V_2 -> V_28 ) ;
V_2 -> V_16 . V_65 ++ ;
if ( F_61 ( V_109 , & V_2 -> V_100 , 0 ) == 0 )
V_2 -> V_16 . V_65 -- ;
}
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! ( V_40 -> V_46 & V_169 ) )
error = F_84 ( V_40 ) ;
return error ;
}
int F_95 ( struct V_39 * V_40 )
{
return F_35 ( V_51 , & V_40 -> V_52 ) ? 0 : 1 ;
}
void F_96 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_145 ;
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned V_99 = 0 ;
int V_170 = 0 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_40 -> V_46 & V_171 )
F_89 ( V_2 , V_20 , 0 , false ) ;
F_14 ( & V_40 -> V_43 ) ;
if ( F_50 ( V_2 ) == NULL ) {
if ( V_18 -> V_172 ) {
F_7 ( V_2 , F_97 ( V_85 , & V_2 -> V_28 ) ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
V_18 -> V_172 ( V_40 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
}
if ( F_11 ( & V_2 -> V_21 ) &&
! F_35 ( V_104 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) )
V_170 = 1 ;
}
if ( ! F_35 ( V_173 , & V_2 -> V_28 ) && F_10 ( V_2 ) &&
( V_18 -> V_8 & V_174 ) )
F_12 ( V_2 ) ;
F_36 ( V_40 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_98 ( V_170 ) )
return;
F_6 ( V_2 ) ;
if ( F_35 ( V_104 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) &&
V_2 -> V_5 . V_107 == V_108 )
V_99 = V_2 -> V_68 ;
if ( F_61 ( V_109 , & V_2 -> V_100 , V_99 ) == 0 )
F_22 ( V_2 ) ;
}
void F_99 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_145 ;
F_96 ( V_40 ) ;
F_85 () ;
F_86 ( & V_2 -> V_28 , V_74 , V_151 ) ;
}
void F_100 ( struct V_39 * V_40 )
{
F_96 ( V_40 ) ;
F_83 ( V_40 ) ;
}
int F_101 ( struct V_3 * V_4 , T_1 V_110 ,
const struct V_17 * V_18 ,
unsigned int V_75 , int V_140 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int error ;
error = F_62 ( V_4 , V_110 , V_18 , V_175 , & V_2 ) ;
if ( ! error ) {
error = F_102 ( V_2 , V_75 , V_140 , V_40 ) ;
F_22 ( V_2 ) ;
}
return error ;
}
static int F_103 ( const void * V_176 , const void * V_177 )
{
const struct V_39 * V_178 = * ( const struct V_39 * * ) V_176 ;
const struct V_39 * V_179 = * ( const struct V_39 * * ) V_177 ;
const struct V_115 * V_180 = & V_178 -> V_145 -> V_5 ;
const struct V_115 * V_181 = & V_179 -> V_145 -> V_5 ;
if ( V_180 -> V_95 > V_181 -> V_95 )
return 1 ;
if ( V_180 -> V_95 < V_181 -> V_95 )
return - 1 ;
F_104 ( V_178 -> V_145 -> V_7 -> V_117 == V_179 -> V_145 -> V_7 -> V_117 ) ;
return 0 ;
}
static int F_105 ( unsigned int V_182 , struct V_39 * V_183 ,
struct V_39 * * V_184 )
{
unsigned int V_185 ;
int error = 0 ;
for ( V_185 = 0 ; V_185 < V_182 ; V_185 ++ )
V_184 [ V_185 ] = & V_183 [ V_185 ] ;
F_106 ( V_184 , V_182 , sizeof( struct V_39 * ) , F_103 , NULL ) ;
for ( V_185 = 0 ; V_185 < V_182 ; V_185 ++ ) {
V_184 [ V_185 ] -> V_46 &= ~ ( V_59 | V_169 ) ;
error = F_94 ( V_184 [ V_185 ] ) ;
if ( error ) {
while ( V_185 -- )
F_96 ( V_184 [ V_185 ] ) ;
break;
}
}
return error ;
}
int F_107 ( unsigned int V_182 , struct V_39 * V_183 )
{
struct V_39 * V_54 [ 4 ] ;
struct V_39 * * V_186 = V_54 ;
int error = 0 ;
switch( V_182 ) {
case 0 :
return 0 ;
case 1 :
V_183 -> V_46 &= ~ ( V_59 | V_169 ) ;
return F_94 ( V_183 ) ;
default:
if ( V_182 <= 4 )
break;
V_186 = F_108 ( V_182 * sizeof( struct V_39 * ) , V_122 ) ;
if ( ! V_186 )
return - V_123 ;
}
error = F_105 ( V_182 , V_183 , V_186 ) ;
if ( V_186 != V_54 )
F_3 ( V_186 ) ;
return error ;
}
void F_109 ( unsigned int V_182 , struct V_39 * V_183 )
{
while ( V_182 -- )
F_96 ( & V_183 [ V_182 ] ) ;
}
void F_110 ( struct V_1 * V_2 , unsigned int V_75 )
{
unsigned long V_99 = 0 ;
unsigned long V_105 ;
unsigned long V_106 = V_72 ;
F_6 ( V_2 ) ;
V_105 = V_2 -> V_71 + V_2 -> V_68 ;
if ( F_35 ( V_66 , & V_2 -> V_28 ) &&
V_2 -> V_5 . V_107 == V_108 ) {
if ( F_60 ( V_106 , V_105 ) )
V_99 = V_105 - V_106 ;
if ( F_35 ( V_102 , & V_2 -> V_28 ) )
V_99 = V_2 -> V_68 ;
}
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_89 ( V_2 , V_75 , V_99 , true ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_61 ( V_109 , & V_2 -> V_100 , V_99 ) == 0 )
F_22 ( V_2 ) ;
}
static int F_111 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 ;
if ( V_2 -> V_103 & ~ V_76 )
return 0 ;
if ( V_2 -> V_67 == V_20 )
return 0 ;
F_39 (gh, &gl->gl_holders, gh_list) {
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
continue;
if ( V_167 & V_40 -> V_46 )
return 0 ;
}
return 1 ;
}
void F_112 ( struct V_1 * V_2 , int V_53 )
{
struct V_187 * V_188 = & V_2 -> V_5 . V_6 -> V_36 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
V_2 -> V_103 = V_53 ;
if ( F_45 ( F_35 ( V_189 , & V_188 -> V_190 ) ) ) {
if ( F_111 ( V_2 ) ) {
F_17 ( V_168 , & V_2 -> V_28 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
return;
}
}
V_2 -> V_16 . V_65 ++ ;
F_17 ( V_102 , & V_2 -> V_28 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_61 ( V_109 , & V_2 -> V_100 , 0 ) == 0 )
F_22 ( V_2 ) ;
}
static int F_113 ( void * V_191 , struct V_192 * V_180 , struct V_192 * V_181 )
{
struct V_1 * V_193 , * V_194 ;
V_193 = F_29 ( V_180 , struct V_1 , V_24 ) ;
V_194 = F_29 ( V_181 , struct V_1 , V_24 ) ;
if ( V_193 -> V_5 . V_95 > V_194 -> V_5 . V_95 )
return 1 ;
if ( V_193 -> V_5 . V_95 < V_194 -> V_5 . V_95 )
return - 1 ;
return 0 ;
}
static void F_114 ( struct V_192 * V_195 )
__releases( &lru_lock
static long F_115 ( int V_196 )
{
struct V_1 * V_2 ;
F_116 ( V_197 ) ;
F_116 ( V_198 ) ;
long V_199 = 0 ;
F_13 ( & V_23 ) ;
while ( ( V_196 -- >= 0 ) && ! F_11 ( & V_26 ) ) {
V_2 = F_29 ( V_26 . V_42 , struct V_1 , V_24 ) ;
if ( ! F_35 ( V_85 , & V_2 -> V_28 ) ) {
F_117 ( & V_2 -> V_24 , & V_198 ) ;
F_20 ( & V_25 ) ;
V_199 ++ ;
continue;
}
F_117 ( & V_2 -> V_24 , & V_197 ) ;
}
F_118 ( & V_197 , & V_26 ) ;
if ( ! F_11 ( & V_198 ) )
F_114 ( & V_198 ) ;
F_18 ( & V_23 ) ;
return V_199 ;
}
static unsigned long F_119 ( struct V_200 * V_201 ,
struct V_202 * V_203 )
{
if ( ! ( V_203 -> V_204 & V_205 ) )
return V_206 ;
return F_115 ( V_203 -> V_207 ) ;
}
static unsigned long F_120 ( struct V_200 * V_201 ,
struct V_202 * V_203 )
{
return F_121 ( F_122 ( & V_25 ) ) ;
}
static void F_123 ( T_3 V_208 , const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_209 * V_210 , * V_42 ;
const struct V_211 * V_212 ;
int V_213 ;
F_124 () ;
V_212 = F_125 ( V_32 . V_212 , & V_32 ) ;
for ( V_213 = 0 ; V_213 < V_212 -> V_214 ; V_213 ++ ) {
F_126 (gl, pos, next, tbl, i, gl_node) {
if ( ( V_2 -> V_5 . V_6 == V_4 ) &&
F_64 ( & V_2 -> V_16 ) )
V_208 ( V_2 ) ;
}
}
F_127 () ;
F_75 () ;
}
static void F_128 ( struct V_1 * V_2 )
{
if ( ! F_49 ( V_168 , & V_2 -> V_28 ) )
goto V_82;
F_17 ( V_102 , & V_2 -> V_28 ) ;
if ( F_61 ( V_109 , & V_2 -> V_100 , 0 ) == 0 ) {
V_82:
F_22 ( V_2 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_2 -> V_19 != V_20 )
F_89 ( V_2 , V_20 , 0 , false ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_61 ( V_109 , & V_2 -> V_100 , 0 ) == 0 )
F_22 ( V_2 ) ;
}
void F_130 ( struct V_3 * V_4 )
{
F_123 ( F_128 , V_4 ) ;
}
static void F_131 ( struct V_159 * V_160 , struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_132 ( V_160 , V_2 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_131 ( NULL , V_2 ) ;
}
void F_134 ( struct V_3 * V_4 )
{
F_17 ( V_215 , & V_4 -> V_166 ) ;
F_135 ( V_109 ) ;
F_123 ( F_129 , V_4 ) ;
F_135 ( V_109 ) ;
F_136 ( V_4 -> V_15 , F_122 ( & V_4 -> V_14 ) == 0 ) ;
F_123 ( F_133 , V_4 ) ;
}
void F_137 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_216 ;
int V_53 ;
V_53 = F_138 ( V_92 ) ;
F_139 ( V_2 -> V_5 . V_6 , V_53 == 0 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static const char * F_140 ( unsigned V_75 )
{
switch( V_75 ) {
case V_20 :
return L_3 ;
case V_48 :
return L_4 ;
case V_49 :
return L_5 ;
case V_45 :
return L_6 ;
}
return L_7 ;
}
static const char * F_141 ( char * V_217 , unsigned V_140 , unsigned long V_218 )
{
char * V_184 = V_217 ;
if ( V_140 & V_59 )
* V_184 ++ = 't' ;
if ( V_140 & V_60 )
* V_184 ++ = 'T' ;
if ( V_140 & V_167 )
* V_184 ++ = 'e' ;
if ( V_140 & V_50 )
* V_184 ++ = 'A' ;
if ( V_140 & V_80 )
* V_184 ++ = 'p' ;
if ( V_140 & V_169 )
* V_184 ++ = 'a' ;
if ( V_140 & V_47 )
* V_184 ++ = 'E' ;
if ( V_140 & V_171 )
* V_184 ++ = 'c' ;
if ( F_35 ( V_55 , & V_218 ) )
* V_184 ++ = 'H' ;
if ( F_35 ( V_51 , & V_218 ) )
* V_184 ++ = 'W' ;
if ( F_35 ( V_219 , & V_218 ) )
* V_184 ++ = 'F' ;
* V_184 = 0 ;
return V_217 ;
}
static void F_142 ( struct V_159 * V_160 , const struct V_39 * V_40 )
{
struct V_220 * V_221 = NULL ;
char V_222 [ 32 ] ;
F_124 () ;
if ( V_40 -> V_148 )
V_221 = F_143 ( V_40 -> V_148 , V_223 ) ;
F_91 ( V_160 , L_8 ,
F_140 ( V_40 -> V_44 ) ,
F_141 ( V_222 , V_40 -> V_46 , V_40 -> V_52 ) ,
V_40 -> V_57 ,
V_40 -> V_148 ? ( long ) F_144 ( V_40 -> V_148 ) : - 1 ,
V_221 ? V_221 -> V_224 : L_9 ,
( void * ) V_40 -> V_146 ) ;
F_127 () ;
}
static const char * F_145 ( char * V_217 , const struct V_1 * V_2 )
{
const unsigned long * V_225 = & V_2 -> V_28 ;
char * V_184 = V_217 ;
if ( F_35 ( V_85 , V_225 ) )
* V_184 ++ = 'l' ;
if ( F_35 ( V_74 , V_225 ) )
* V_184 ++ = 'D' ;
if ( F_35 ( V_104 , V_225 ) )
* V_184 ++ = 'd' ;
if ( F_35 ( V_78 , V_225 ) )
* V_184 ++ = 'p' ;
if ( F_35 ( V_226 , V_225 ) )
* V_184 ++ = 'y' ;
if ( F_35 ( V_173 , V_225 ) )
* V_184 ++ = 'f' ;
if ( F_35 ( V_227 , V_225 ) )
* V_184 ++ = 'i' ;
if ( F_35 ( V_102 , V_225 ) )
* V_184 ++ = 'r' ;
if ( F_35 ( V_228 , V_225 ) )
* V_184 ++ = 'I' ;
if ( F_35 ( V_168 , V_225 ) )
* V_184 ++ = 'F' ;
if ( F_35 ( V_66 , V_225 ) )
* V_184 ++ = 'q' ;
if ( F_35 ( V_27 , V_225 ) )
* V_184 ++ = 'L' ;
if ( V_2 -> V_96 )
* V_184 ++ = 'o' ;
if ( F_35 ( V_229 , V_225 ) )
* V_184 ++ = 'b' ;
* V_184 = 0 ;
return V_217 ;
}
void F_132 ( struct V_159 * V_160 , const struct V_1 * V_2 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned long long V_230 ;
const struct V_39 * V_40 ;
char V_231 [ 32 ] ;
V_230 = V_72 - V_2 -> V_157 ;
V_230 *= 1000000 / V_152 ;
if ( ! F_35 ( V_74 , & V_2 -> V_28 ) )
V_230 = 0 ;
F_91 ( V_160 , L_10 ,
F_140 ( V_2 -> V_19 ) ,
V_2 -> V_5 . V_107 ,
( unsigned long long ) V_2 -> V_5 . V_95 ,
F_145 ( V_231 , V_2 ) ,
F_140 ( V_2 -> V_67 ) ,
F_140 ( V_2 -> V_73 ) , V_230 ,
F_122 ( & V_2 -> V_232 ) ,
F_122 ( & V_2 -> V_233 ) ,
( int ) V_2 -> V_16 . V_65 , V_2 -> V_68 ) ;
F_39 (gh, &gl->gl_holders, gh_list)
F_142 ( V_160 , V_40 ) ;
if ( V_2 -> V_19 != V_20 && V_18 -> V_234 )
V_18 -> V_234 ( V_160 , V_2 ) ;
}
static int F_146 ( struct V_159 * V_160 , void * V_235 )
{
struct V_1 * V_2 = V_235 ;
F_147 ( V_160 , L_11 ,
V_2 -> V_5 . V_107 ,
( unsigned long long ) V_2 -> V_5 . V_95 ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_236 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_237 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_238 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_239 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_240 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_241 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_132 ] ,
( unsigned long long ) V_2 -> V_128 . V_131 [ V_133 ] ) ;
return 0 ;
}
static int F_148 ( struct V_159 * V_160 , void * V_235 )
{
struct V_3 * V_4 = V_160 -> V_242 ;
T_4 V_210 = * ( T_4 * ) V_235 ;
unsigned V_243 = V_210 >> 3 ;
unsigned V_244 = V_210 & 0x07 ;
int V_213 ;
if ( V_243 == 0 && V_244 != 0 )
return 0 ;
F_147 ( V_160 , L_12 , V_245 [ V_243 ] ,
( V_243 == 0 ) ? L_13 : V_246 [ V_244 ] ) ;
F_149 (i) {
const struct V_247 * V_130 = F_150 ( V_4 -> V_129 , V_213 ) ;
if ( V_243 == 0 )
F_147 ( V_160 , L_14 , V_213 ) ;
else
F_147 ( V_160 , L_15 , ( unsigned long long ) V_130 ->
V_130 [ V_243 - 1 ] . V_131 [ V_244 ] ) ;
}
F_151 ( V_160 , '\n' ) ;
return 0 ;
}
int T_5 F_152 ( void )
{
int V_53 ;
V_53 = F_153 ( & V_32 , & V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
V_109 = F_154 ( L_16 , V_248 |
V_249 | V_250 , 0 ) ;
if ( ! V_109 ) {
F_155 ( & V_32 ) ;
return - V_123 ;
}
V_251 = F_154 ( L_17 ,
V_248 | V_250 ,
0 ) ;
if ( ! V_251 ) {
F_156 ( V_109 ) ;
F_155 ( & V_32 ) ;
return - V_123 ;
}
F_157 ( & V_252 ) ;
return 0 ;
}
void F_158 ( void )
{
F_159 ( & V_252 ) ;
F_155 ( & V_32 ) ;
F_156 ( V_109 ) ;
F_156 ( V_251 ) ;
}
static void F_160 ( struct V_253 * V_254 )
{
do {
V_254 -> V_2 = F_161 ( & V_254 -> V_255 ) ;
if ( F_56 ( V_254 -> V_2 ) ) {
if ( F_162 ( V_254 -> V_2 ) == - V_256 )
continue;
V_254 -> V_2 = NULL ;
}
} while ( ( V_254 -> V_2 ) && ( ( V_254 -> V_4 != V_254 -> V_2 -> V_5 . V_6 ) ||
F_8 ( & V_254 -> V_2 -> V_16 ) ) );
}
static void * F_163 ( struct V_159 * V_160 , T_4 * V_210 )
{
struct V_253 * V_254 = V_160 -> V_242 ;
T_4 V_257 = * V_210 ;
int V_53 ;
if ( V_254 -> V_258 <= * V_210 )
V_257 = ( * V_210 - V_254 -> V_258 ) ;
V_53 = F_164 ( & V_254 -> V_255 ) ;
if ( V_53 )
return NULL ;
do {
F_160 ( V_254 ) ;
} while ( V_254 -> V_2 && V_257 -- );
V_254 -> V_258 = * V_210 ;
return V_254 -> V_2 ;
}
static void * F_165 ( struct V_159 * V_160 , void * V_235 ,
T_4 * V_210 )
{
struct V_253 * V_254 = V_160 -> V_242 ;
( * V_210 ) ++ ;
V_254 -> V_258 = * V_210 ;
F_160 ( V_254 ) ;
return V_254 -> V_2 ;
}
static void F_166 ( struct V_159 * V_160 , void * V_235 )
{
struct V_253 * V_254 = V_160 -> V_242 ;
V_254 -> V_2 = NULL ;
F_167 ( & V_254 -> V_255 ) ;
}
static int F_168 ( struct V_159 * V_160 , void * V_235 )
{
F_131 ( V_160 , V_235 ) ;
return 0 ;
}
static void * F_169 ( struct V_159 * V_160 , T_4 * V_210 )
{
F_68 () ;
if ( * V_210 >= V_259 )
return NULL ;
return V_210 ;
}
static void * F_170 ( struct V_159 * V_160 , void * V_235 ,
T_4 * V_210 )
{
( * V_210 ) ++ ;
if ( * V_210 >= V_259 )
return NULL ;
return V_210 ;
}
static void F_171 ( struct V_159 * V_160 , void * V_235 )
{
F_70 () ;
}
static int F_172 ( struct V_93 * V_93 , struct V_260 * V_260 )
{
int V_53 = F_173 ( V_260 , & V_261 ,
sizeof( struct V_253 ) ) ;
if ( V_53 == 0 ) {
struct V_159 * V_160 = V_260 -> V_141 ;
struct V_253 * V_254 = V_160 -> V_242 ;
V_254 -> V_4 = V_93 -> V_262 ;
V_254 -> V_258 = 0 ;
V_160 -> V_217 = F_108 ( V_263 , V_264 | V_265 ) ;
if ( V_160 -> V_217 )
V_160 -> V_214 = V_263 ;
V_254 -> V_2 = NULL ;
V_53 = F_174 ( & V_32 , & V_254 -> V_255 ) ;
}
return V_53 ;
}
static int F_175 ( struct V_93 * V_93 , struct V_260 * V_260 )
{
struct V_159 * V_160 = V_260 -> V_141 ;
struct V_253 * V_254 = V_160 -> V_242 ;
V_254 -> V_2 = NULL ;
F_176 ( & V_254 -> V_255 ) ;
return F_177 ( V_93 , V_260 ) ;
}
static int F_178 ( struct V_93 * V_93 , struct V_260 * V_260 )
{
int V_53 = F_173 ( V_260 , & V_266 ,
sizeof( struct V_253 ) ) ;
if ( V_53 == 0 ) {
struct V_159 * V_160 = V_260 -> V_141 ;
struct V_253 * V_254 = V_160 -> V_242 ;
V_254 -> V_4 = V_93 -> V_262 ;
V_254 -> V_258 = 0 ;
V_160 -> V_217 = F_108 ( V_263 , V_264 | V_265 ) ;
if ( V_160 -> V_217 )
V_160 -> V_214 = V_263 ;
V_254 -> V_2 = NULL ;
V_53 = F_174 ( & V_32 , & V_254 -> V_255 ) ;
}
return V_53 ;
}
static int F_179 ( struct V_93 * V_93 , struct V_260 * V_260 )
{
int V_53 = F_180 ( V_260 , & V_267 ) ;
if ( V_53 == 0 ) {
struct V_159 * V_160 = V_260 -> V_141 ;
V_160 -> V_242 = V_93 -> V_262 ;
}
return V_53 ;
}
int F_181 ( struct V_3 * V_4 )
{
struct V_268 * V_269 ;
V_269 = F_182 ( V_4 -> V_270 , V_271 ) ;
if ( F_183 ( V_269 ) )
goto V_272;
V_4 -> V_273 = V_269 ;
V_269 = F_184 ( L_18 ,
V_274 | V_275 ,
V_4 -> V_273 , V_4 ,
& V_276 ) ;
if ( F_183 ( V_269 ) )
goto V_272;
V_4 -> V_277 = V_269 ;
V_269 = F_184 ( L_19 ,
V_274 | V_275 ,
V_4 -> V_273 , V_4 ,
& V_278 ) ;
if ( F_183 ( V_269 ) )
goto V_272;
V_4 -> V_279 = V_269 ;
V_269 = F_184 ( L_20 ,
V_274 | V_275 ,
V_4 -> V_273 , V_4 ,
& V_280 ) ;
if ( F_183 ( V_269 ) )
goto V_272;
V_4 -> V_281 = V_269 ;
return 0 ;
V_272:
F_185 ( V_4 ) ;
return V_269 ? F_162 ( V_269 ) : - V_123 ;
}
void F_185 ( struct V_3 * V_4 )
{
if ( V_4 -> V_273 ) {
if ( V_4 -> V_277 ) {
F_186 ( V_4 -> V_277 ) ;
V_4 -> V_277 = NULL ;
}
if ( V_4 -> V_279 ) {
F_186 ( V_4 -> V_279 ) ;
V_4 -> V_279 = NULL ;
}
if ( V_4 -> V_281 ) {
F_186 ( V_4 -> V_281 ) ;
V_4 -> V_281 = NULL ;
}
F_186 ( V_4 -> V_273 ) ;
V_4 -> V_273 = NULL ;
}
}
int F_187 ( void )
{
V_271 = F_182 ( L_21 , NULL ) ;
if ( F_56 ( V_271 ) )
return F_162 ( V_271 ) ;
return V_271 ? 0 : - V_123 ;
}
void F_188 ( void )
{
F_186 ( V_271 ) ;
V_271 = NULL ;
}
