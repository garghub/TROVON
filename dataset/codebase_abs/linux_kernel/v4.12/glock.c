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
static void F_33 ( struct V_1 * V_2 , const int V_53 )
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
struct V_91 * V_91 ;
T_1 V_92 = V_2 -> V_5 . V_93 ;
if ( F_35 ( V_94 , & V_2 -> V_28 ) )
goto V_82;
V_91 = F_54 ( V_4 , V_92 , NULL , V_95 ) ;
if ( V_91 && ! F_55 ( V_91 ) ) {
F_56 ( V_91 ) ;
F_57 ( V_91 ) ;
}
V_82:
F_22 ( V_2 ) ;
}
static void F_58 ( struct V_88 * V_89 )
{
unsigned long V_96 = 0 ;
struct V_1 * V_2 = F_53 ( V_89 , struct V_1 , V_97 . V_89 ) ;
int V_98 = 0 ;
if ( F_49 ( V_99 , & V_2 -> V_28 ) ) {
F_43 ( V_2 , V_2 -> V_100 ) ;
V_98 = 1 ;
}
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( F_35 ( V_101 , & V_2 -> V_28 ) &&
V_2 -> V_19 != V_20 &&
V_2 -> V_73 != V_45 ) {
unsigned long V_102 , V_103 = V_72 ;
V_102 = V_2 -> V_71 + V_2 -> V_68 ;
if ( F_59 ( V_103 , V_102 ) )
V_96 = V_102 - V_103 ;
if ( ! V_96 ) {
F_21 ( V_101 , & V_2 -> V_28 ) ;
F_17 ( V_74 , & V_2 -> V_28 ) ;
}
}
F_51 ( V_2 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! V_96 )
F_22 ( V_2 ) ;
else {
if ( V_2 -> V_5 . V_104 != V_105 )
V_96 = 0 ;
if ( F_60 ( V_106 , & V_2 -> V_97 , V_96 ) == 0 )
F_22 ( V_2 ) ;
}
if ( V_98 )
F_22 ( V_2 ) ;
}
int F_61 ( struct V_3 * V_4 , T_1 V_107 ,
const struct V_17 * V_18 , int V_108 ,
struct V_1 * * V_109 )
{
struct V_110 * V_111 = V_4 -> V_112 ;
struct V_113 V_114 = { . V_93 = V_107 ,
. V_104 = V_18 -> V_115 ,
. V_6 = V_4 } ;
struct V_1 * V_2 , * V_54 ;
struct V_29 * V_30 ;
struct V_116 * V_117 ;
int V_53 = 0 ;
F_62 () ;
V_2 = F_63 ( & V_32 , & V_114 , V_34 ) ;
if ( V_2 && ! F_64 ( & V_2 -> V_16 ) )
V_2 = NULL ;
F_65 () ;
* V_109 = V_2 ;
if ( V_2 )
return 0 ;
if ( ! V_108 )
return - V_118 ;
if ( V_18 -> V_8 & V_9 )
V_117 = V_10 ;
else
V_117 = V_13 ;
V_2 = F_66 ( V_117 , V_119 ) ;
if ( ! V_2 )
return - V_120 ;
memset ( & V_2 -> V_11 , 0 , sizeof( struct V_121 ) ) ;
if ( V_18 -> V_8 & V_122 ) {
V_2 -> V_11 . V_12 = F_67 ( V_123 , V_119 ) ;
if ( ! V_2 -> V_11 . V_12 ) {
F_2 ( V_117 , V_2 ) ;
return - V_120 ;
}
}
F_15 ( & V_4 -> V_14 ) ;
V_2 -> V_33 . V_42 = NULL ;
V_2 -> V_28 = 0 ;
V_2 -> V_5 = V_114 ;
V_2 -> V_16 . V_65 = 1 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_67 = V_20 ;
V_2 -> V_73 = V_45 ;
V_2 -> V_7 = V_18 ;
V_2 -> V_124 = 0 ;
F_68 () ;
V_2 -> V_125 = F_69 ( V_4 -> V_126 ) -> V_127 [ V_18 -> V_115 ] ;
F_70 () ;
V_2 -> V_125 . V_128 [ V_129 ] = 0 ;
V_2 -> V_125 . V_128 [ V_130 ] = 0 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_131 = NULL ;
V_2 -> V_68 = V_132 ;
F_71 ( & V_2 -> V_97 , F_58 ) ;
F_72 ( & V_2 -> V_90 , F_52 ) ;
V_30 = F_23 ( V_2 ) ;
if ( V_30 ) {
V_30 -> V_133 = & V_134 ;
V_30 -> V_135 = V_111 -> V_136 -> V_137 ;
V_30 -> V_138 = 0 ;
F_73 ( V_30 , V_119 ) ;
V_30 -> V_139 = NULL ;
V_30 -> V_140 = 0 ;
}
V_141:
F_62 () ;
V_54 = F_74 ( & V_32 , & V_2 -> V_33 ,
V_34 ) ;
if ( ! V_54 ) {
* V_109 = V_2 ;
goto V_82;
}
if ( F_55 ( V_54 ) ) {
V_53 = F_75 ( V_54 ) ;
goto V_142;
}
if ( F_64 ( & V_54 -> V_16 ) ) {
* V_109 = V_54 ;
goto V_142;
}
F_65 () ;
F_76 () ;
goto V_141;
V_142:
F_3 ( V_2 -> V_11 . V_12 ) ;
F_2 ( V_117 , V_2 ) ;
F_20 ( & V_4 -> V_14 ) ;
V_82:
F_65 () ;
return V_53 ;
}
void F_77 ( struct V_1 * V_2 , unsigned int V_75 , T_2 V_138 ,
struct V_39 * V_40 )
{
F_78 ( & V_40 -> V_43 ) ;
V_40 -> V_143 = V_2 ;
V_40 -> V_144 = V_145 ;
V_40 -> V_146 = F_79 ( F_80 ( V_147 ) ) ;
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_138 ;
V_40 -> V_57 = 0 ;
V_40 -> V_52 = 0 ;
F_6 ( V_2 ) ;
}
void F_81 ( unsigned int V_75 , T_2 V_138 , struct V_39 * V_40 )
{
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_138 ;
V_40 -> V_52 = 0 ;
V_40 -> V_144 = V_145 ;
F_82 ( V_40 -> V_146 ) ;
V_40 -> V_146 = F_79 ( F_80 ( V_147 ) ) ;
}
void F_83 ( struct V_39 * V_40 )
{
F_82 ( V_40 -> V_146 ) ;
F_22 ( V_40 -> V_143 ) ;
F_84 ( V_40 ) ;
V_40 -> V_144 = 0 ;
}
int F_85 ( struct V_39 * V_40 )
{
unsigned long V_148 = V_72 ;
F_86 () ;
F_87 ( & V_40 -> V_52 , V_51 , V_149 ) ;
if ( F_88 ( V_72 , V_148 + V_150 ) )
V_40 -> V_143 -> V_68 = F_89 ( V_40 -> V_143 -> V_68 +
V_151 ,
V_152 ) ;
return V_40 -> V_57 ;
}
static void F_90 ( struct V_1 * V_2 , unsigned int V_75 ,
unsigned long V_96 , bool V_153 )
{
int V_154 = V_96 ? V_101 : V_74 ;
F_17 ( V_154 , & V_2 -> V_28 ) ;
if ( V_2 -> V_73 == V_45 ) {
V_2 -> V_73 = V_75 ;
V_2 -> V_155 = V_72 ;
} else if ( V_2 -> V_73 != V_20 &&
V_2 -> V_73 != V_75 ) {
V_2 -> V_73 = V_20 ;
}
if ( V_2 -> V_7 -> V_156 )
V_2 -> V_7 -> V_156 ( V_2 , V_153 ) ;
F_91 ( V_2 , V_153 ) ;
}
void F_92 ( struct V_157 * V_158 , const char * V_159 , ... )
{
struct V_160 V_161 ;
T_3 args ;
va_start ( args , V_159 ) ;
if ( V_158 ) {
F_93 ( V_158 , V_159 , args ) ;
} else {
V_161 . V_159 = V_159 ;
V_161 . V_162 = & args ;
F_48 ( L_2 , & V_161 ) ;
}
va_end ( args ) ;
}
static inline void F_94 ( struct V_39 * V_40 )
__releases( &gl->gl_lockref.lock
int F_95 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_143 ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int error = 0 ;
if ( F_45 ( F_35 ( V_163 , & V_4 -> V_164 ) ) )
return - V_58 ;
if ( F_35 ( V_27 , & V_2 -> V_28 ) )
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_94 ( V_40 ) ;
if ( F_45 ( ( V_165 & V_40 -> V_46 ) &&
F_49 ( V_166 , & V_2 -> V_28 ) ) ) {
F_17 ( V_99 , & V_2 -> V_28 ) ;
V_2 -> V_16 . V_65 ++ ;
if ( F_60 ( V_106 , & V_2 -> V_97 , 0 ) == 0 )
V_2 -> V_16 . V_65 -- ;
}
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! ( V_40 -> V_46 & V_167 ) )
error = F_85 ( V_40 ) ;
return error ;
}
int F_96 ( struct V_39 * V_40 )
{
return F_35 ( V_51 , & V_40 -> V_52 ) ? 0 : 1 ;
}
void F_97 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_143 ;
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned V_96 = 0 ;
int V_168 = 0 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_40 -> V_46 & V_169 )
F_90 ( V_2 , V_20 , 0 , false ) ;
F_14 ( & V_40 -> V_43 ) ;
F_21 ( V_55 , & V_40 -> V_52 ) ;
if ( F_50 ( V_2 ) == NULL ) {
if ( V_18 -> V_170 ) {
F_7 ( V_2 , F_98 ( V_85 , & V_2 -> V_28 ) ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
V_18 -> V_170 ( V_40 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
}
if ( F_11 ( & V_2 -> V_21 ) &&
! F_35 ( V_101 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) )
V_168 = 1 ;
}
if ( ! F_35 ( V_171 , & V_2 -> V_28 ) && F_10 ( V_2 ) &&
( V_18 -> V_8 & V_172 ) )
F_12 ( V_2 ) ;
F_36 ( V_40 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_99 ( V_168 ) )
return;
F_6 ( V_2 ) ;
if ( F_35 ( V_101 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) &&
V_2 -> V_5 . V_104 == V_105 )
V_96 = V_2 -> V_68 ;
if ( F_60 ( V_106 , & V_2 -> V_97 , V_96 ) == 0 )
F_22 ( V_2 ) ;
}
void F_100 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_143 ;
F_97 ( V_40 ) ;
F_86 () ;
F_87 ( & V_2 -> V_28 , V_74 , V_149 ) ;
}
void F_101 ( struct V_39 * V_40 )
{
F_97 ( V_40 ) ;
F_83 ( V_40 ) ;
}
int F_102 ( struct V_3 * V_4 , T_1 V_107 ,
const struct V_17 * V_18 ,
unsigned int V_75 , T_2 V_138 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int error ;
error = F_61 ( V_4 , V_107 , V_18 , V_173 , & V_2 ) ;
if ( ! error ) {
error = F_103 ( V_2 , V_75 , V_138 , V_40 ) ;
F_22 ( V_2 ) ;
}
return error ;
}
static int F_104 ( const void * V_174 , const void * V_175 )
{
const struct V_39 * V_176 = * ( const struct V_39 * * ) V_174 ;
const struct V_39 * V_177 = * ( const struct V_39 * * ) V_175 ;
const struct V_113 * V_178 = & V_176 -> V_143 -> V_5 ;
const struct V_113 * V_179 = & V_177 -> V_143 -> V_5 ;
if ( V_178 -> V_93 > V_179 -> V_93 )
return 1 ;
if ( V_178 -> V_93 < V_179 -> V_93 )
return - 1 ;
F_105 ( V_176 -> V_143 -> V_7 -> V_115 == V_177 -> V_143 -> V_7 -> V_115 ) ;
return 0 ;
}
static int F_106 ( unsigned int V_180 , struct V_39 * V_181 ,
struct V_39 * * V_182 )
{
unsigned int V_183 ;
int error = 0 ;
for ( V_183 = 0 ; V_183 < V_180 ; V_183 ++ )
V_182 [ V_183 ] = & V_181 [ V_183 ] ;
F_107 ( V_182 , V_180 , sizeof( struct V_39 * ) , F_104 , NULL ) ;
for ( V_183 = 0 ; V_183 < V_180 ; V_183 ++ ) {
V_182 [ V_183 ] -> V_46 &= ~ ( V_59 | V_167 ) ;
error = F_95 ( V_182 [ V_183 ] ) ;
if ( error ) {
while ( V_183 -- )
F_97 ( V_182 [ V_183 ] ) ;
break;
}
}
return error ;
}
int F_108 ( unsigned int V_180 , struct V_39 * V_181 )
{
struct V_39 * V_54 [ 4 ] ;
struct V_39 * * V_184 = V_54 ;
int error = 0 ;
switch( V_180 ) {
case 0 :
return 0 ;
case 1 :
V_181 -> V_46 &= ~ ( V_59 | V_167 ) ;
return F_95 ( V_181 ) ;
default:
if ( V_180 <= 4 )
break;
V_184 = F_109 ( V_180 * sizeof( struct V_39 * ) , V_119 ) ;
if ( ! V_184 )
return - V_120 ;
}
error = F_106 ( V_180 , V_181 , V_184 ) ;
if ( V_184 != V_54 )
F_3 ( V_184 ) ;
return error ;
}
void F_110 ( unsigned int V_180 , struct V_39 * V_181 )
{
while ( V_180 -- )
F_97 ( & V_181 [ V_180 ] ) ;
}
void F_111 ( struct V_1 * V_2 , unsigned int V_75 )
{
unsigned long V_96 = 0 ;
unsigned long V_102 ;
unsigned long V_103 = V_72 ;
F_6 ( V_2 ) ;
V_102 = V_2 -> V_71 + V_2 -> V_68 ;
if ( F_35 ( V_66 , & V_2 -> V_28 ) &&
V_2 -> V_5 . V_104 == V_105 ) {
if ( F_59 ( V_103 , V_102 ) )
V_96 = V_102 - V_103 ;
if ( F_35 ( V_99 , & V_2 -> V_28 ) )
V_96 = V_2 -> V_68 ;
}
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_90 ( V_2 , V_75 , V_96 , true ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_60 ( V_106 , & V_2 -> V_97 , V_96 ) == 0 )
F_22 ( V_2 ) ;
}
static int F_112 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 ;
if ( V_2 -> V_100 & ~ V_76 )
return 0 ;
if ( V_2 -> V_67 == V_20 )
return 0 ;
F_39 (gh, &gl->gl_holders, gh_list) {
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
continue;
if ( V_165 & V_40 -> V_46 )
return 0 ;
}
return 1 ;
}
void F_113 ( struct V_1 * V_2 , int V_53 )
{
struct V_185 * V_186 = & V_2 -> V_5 . V_6 -> V_36 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
V_2 -> V_100 = V_53 ;
if ( F_45 ( F_35 ( V_187 , & V_186 -> V_188 ) ) ) {
if ( F_112 ( V_2 ) ) {
F_17 ( V_166 , & V_2 -> V_28 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
return;
}
}
V_2 -> V_16 . V_65 ++ ;
F_17 ( V_99 , & V_2 -> V_28 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_60 ( V_106 , & V_2 -> V_97 , 0 ) == 0 )
F_22 ( V_2 ) ;
}
static int F_114 ( void * V_189 , struct V_190 * V_178 , struct V_190 * V_179 )
{
struct V_1 * V_191 , * V_192 ;
V_191 = F_29 ( V_178 , struct V_1 , V_24 ) ;
V_192 = F_29 ( V_179 , struct V_1 , V_24 ) ;
if ( V_191 -> V_5 . V_93 > V_192 -> V_5 . V_93 )
return 1 ;
if ( V_191 -> V_5 . V_93 < V_192 -> V_5 . V_93 )
return - 1 ;
return 0 ;
}
static void F_115 ( struct V_190 * V_193 )
__releases( &lru_lock
static long F_116 ( int V_194 )
{
struct V_1 * V_2 ;
F_117 ( V_195 ) ;
F_117 ( V_196 ) ;
long V_197 = 0 ;
F_13 ( & V_23 ) ;
while ( ( V_194 -- >= 0 ) && ! F_11 ( & V_26 ) ) {
V_2 = F_29 ( V_26 . V_42 , struct V_1 , V_24 ) ;
if ( ! F_35 ( V_85 , & V_2 -> V_28 ) ) {
F_118 ( & V_2 -> V_24 , & V_196 ) ;
F_20 ( & V_25 ) ;
V_197 ++ ;
continue;
}
F_118 ( & V_2 -> V_24 , & V_195 ) ;
}
F_119 ( & V_195 , & V_26 ) ;
if ( ! F_11 ( & V_196 ) )
F_115 ( & V_196 ) ;
F_18 ( & V_23 ) ;
return V_197 ;
}
static unsigned long F_120 ( struct V_198 * V_199 ,
struct V_200 * V_201 )
{
if ( ! ( V_201 -> V_202 & V_203 ) )
return V_204 ;
return F_116 ( V_201 -> V_205 ) ;
}
static unsigned long F_121 ( struct V_198 * V_199 ,
struct V_200 * V_201 )
{
return F_122 ( F_123 ( & V_25 ) ) ;
}
static void F_124 ( T_4 V_206 , const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_207 V_208 ;
F_125 ( & V_32 , & V_208 ) ;
do {
V_2 = F_126 ( F_127 ( & V_208 ) ) ;
if ( V_2 )
continue;
while ( ( V_2 = F_128 ( & V_208 ) ) && ! F_55 ( V_2 ) )
if ( ( V_2 -> V_5 . V_6 == V_4 ) &&
F_64 ( & V_2 -> V_16 ) )
V_206 ( V_2 ) ;
F_129 ( & V_208 ) ;
} while ( F_76 () , V_2 == F_126 ( - V_209 ) );
F_130 ( & V_208 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( ! F_49 ( V_166 , & V_2 -> V_28 ) )
goto V_82;
F_17 ( V_99 , & V_2 -> V_28 ) ;
if ( F_60 ( V_106 , & V_2 -> V_97 , 0 ) == 0 ) {
V_82:
F_22 ( V_2 ) ;
}
}
static void F_132 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_2 -> V_19 != V_20 )
F_90 ( V_2 , V_20 , 0 , false ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_60 ( V_106 , & V_2 -> V_97 , 0 ) == 0 )
F_22 ( V_2 ) ;
}
void F_133 ( struct V_3 * V_4 )
{
F_124 ( F_131 , V_4 ) ;
}
static void F_134 ( struct V_157 * V_158 , struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_135 ( V_158 , V_2 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_134 ( NULL , V_2 ) ;
}
void F_137 ( struct V_3 * V_4 )
{
F_17 ( V_210 , & V_4 -> V_164 ) ;
F_138 ( V_106 ) ;
F_124 ( F_132 , V_4 ) ;
F_138 ( V_106 ) ;
F_139 ( V_4 -> V_15 ,
F_123 ( & V_4 -> V_14 ) == 0 ,
V_150 * 600 ) ;
F_124 ( F_136 , V_4 ) ;
}
void F_140 ( struct V_211 * V_212 )
{
struct V_1 * V_2 = V_212 -> V_213 ;
int V_53 ;
V_53 = F_141 ( V_212 ) ;
F_142 ( V_2 -> V_5 . V_6 , V_53 == 0 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static const char * F_143 ( unsigned V_75 )
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
static const char * F_144 ( char * V_214 , T_2 V_138 , unsigned long V_215 )
{
char * V_182 = V_214 ;
if ( V_138 & V_59 )
* V_182 ++ = 't' ;
if ( V_138 & V_60 )
* V_182 ++ = 'T' ;
if ( V_138 & V_165 )
* V_182 ++ = 'e' ;
if ( V_138 & V_50 )
* V_182 ++ = 'A' ;
if ( V_138 & V_80 )
* V_182 ++ = 'p' ;
if ( V_138 & V_167 )
* V_182 ++ = 'a' ;
if ( V_138 & V_47 )
* V_182 ++ = 'E' ;
if ( V_138 & V_169 )
* V_182 ++ = 'c' ;
if ( F_35 ( V_55 , & V_215 ) )
* V_182 ++ = 'H' ;
if ( F_35 ( V_51 , & V_215 ) )
* V_182 ++ = 'W' ;
if ( F_35 ( V_216 , & V_215 ) )
* V_182 ++ = 'F' ;
* V_182 = 0 ;
return V_214 ;
}
static void F_145 ( struct V_157 * V_158 , const struct V_39 * V_40 )
{
struct V_217 * V_218 = NULL ;
char V_219 [ 32 ] ;
F_62 () ;
if ( V_40 -> V_146 )
V_218 = F_146 ( V_40 -> V_146 , V_220 ) ;
F_92 ( V_158 , L_8 ,
F_143 ( V_40 -> V_44 ) ,
F_144 ( V_219 , V_40 -> V_46 , V_40 -> V_52 ) ,
V_40 -> V_57 ,
V_40 -> V_146 ? ( long ) F_147 ( V_40 -> V_146 ) : - 1 ,
V_218 ? V_218 -> V_221 : L_9 ,
( void * ) V_40 -> V_144 ) ;
F_65 () ;
}
static const char * F_148 ( char * V_214 , const struct V_1 * V_2 )
{
const unsigned long * V_222 = & V_2 -> V_28 ;
char * V_182 = V_214 ;
if ( F_35 ( V_85 , V_222 ) )
* V_182 ++ = 'l' ;
if ( F_35 ( V_74 , V_222 ) )
* V_182 ++ = 'D' ;
if ( F_35 ( V_101 , V_222 ) )
* V_182 ++ = 'd' ;
if ( F_35 ( V_78 , V_222 ) )
* V_182 ++ = 'p' ;
if ( F_35 ( V_223 , V_222 ) )
* V_182 ++ = 'y' ;
if ( F_35 ( V_171 , V_222 ) )
* V_182 ++ = 'f' ;
if ( F_35 ( V_224 , V_222 ) )
* V_182 ++ = 'i' ;
if ( F_35 ( V_99 , V_222 ) )
* V_182 ++ = 'r' ;
if ( F_35 ( V_225 , V_222 ) )
* V_182 ++ = 'I' ;
if ( F_35 ( V_166 , V_222 ) )
* V_182 ++ = 'F' ;
if ( F_35 ( V_66 , V_222 ) )
* V_182 ++ = 'q' ;
if ( F_35 ( V_27 , V_222 ) )
* V_182 ++ = 'L' ;
if ( V_2 -> V_131 )
* V_182 ++ = 'o' ;
if ( F_35 ( V_226 , V_222 ) )
* V_182 ++ = 'b' ;
* V_182 = 0 ;
return V_214 ;
}
void F_135 ( struct V_157 * V_158 , const struct V_1 * V_2 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned long long V_227 ;
const struct V_39 * V_40 ;
char V_228 [ 32 ] ;
V_227 = V_72 - V_2 -> V_155 ;
V_227 *= 1000000 / V_150 ;
if ( ! F_35 ( V_74 , & V_2 -> V_28 ) )
V_227 = 0 ;
F_92 ( V_158 , L_10 ,
F_143 ( V_2 -> V_19 ) ,
V_2 -> V_5 . V_104 ,
( unsigned long long ) V_2 -> V_5 . V_93 ,
F_148 ( V_228 , V_2 ) ,
F_143 ( V_2 -> V_67 ) ,
F_143 ( V_2 -> V_73 ) , V_227 ,
F_123 ( & V_2 -> V_229 ) ,
F_123 ( & V_2 -> V_230 ) ,
( int ) V_2 -> V_16 . V_65 , V_2 -> V_68 ) ;
F_39 (gh, &gl->gl_holders, gh_list)
F_145 ( V_158 , V_40 ) ;
if ( V_2 -> V_19 != V_20 && V_18 -> V_231 )
V_18 -> V_231 ( V_158 , V_2 ) ;
}
static int F_149 ( struct V_157 * V_158 , void * V_232 )
{
struct V_1 * V_2 = V_232 ;
F_150 ( V_158 , L_11 ,
V_2 -> V_5 . V_104 ,
( unsigned long long ) V_2 -> V_5 . V_93 ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_233 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_234 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_235 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_236 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_237 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_238 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_129 ] ,
( unsigned long long ) V_2 -> V_125 . V_128 [ V_130 ] ) ;
return 0 ;
}
static int F_151 ( struct V_157 * V_158 , void * V_232 )
{
struct V_3 * V_4 = V_158 -> V_239 ;
T_5 V_240 = * ( T_5 * ) V_232 ;
unsigned V_241 = V_240 >> 3 ;
unsigned V_242 = V_240 & 0x07 ;
int V_243 ;
if ( V_241 == 0 && V_242 != 0 )
return 0 ;
F_150 ( V_158 , L_12 , V_244 [ V_241 ] ,
( V_241 == 0 ) ? L_13 : V_245 [ V_242 ] ) ;
F_152 (i) {
const struct V_246 * V_127 = F_153 ( V_4 -> V_126 , V_243 ) ;
if ( V_241 == 0 )
F_150 ( V_158 , L_14 , V_243 ) ;
else
F_150 ( V_158 , L_15 , ( unsigned long long ) V_127 ->
V_127 [ V_241 - 1 ] . V_128 [ V_242 ] ) ;
}
F_154 ( V_158 , '\n' ) ;
return 0 ;
}
int T_6 F_155 ( void )
{
int V_53 ;
V_53 = F_156 ( & V_32 , & V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
V_106 = F_157 ( L_16 , V_247 |
V_248 | V_249 , 0 ) ;
if ( ! V_106 ) {
F_158 ( & V_32 ) ;
return - V_120 ;
}
V_250 = F_157 ( L_17 ,
V_247 | V_249 ,
0 ) ;
if ( ! V_250 ) {
F_159 ( V_106 ) ;
F_158 ( & V_32 ) ;
return - V_120 ;
}
V_53 = F_160 ( & V_251 ) ;
if ( V_53 ) {
F_159 ( V_250 ) ;
F_159 ( V_106 ) ;
F_158 ( & V_32 ) ;
return V_53 ;
}
return 0 ;
}
void F_161 ( void )
{
F_162 ( & V_251 ) ;
F_158 ( & V_32 ) ;
F_159 ( V_106 ) ;
F_159 ( V_250 ) ;
}
static void F_163 ( struct V_252 * V_253 )
{
while ( ( V_253 -> V_2 = F_128 ( & V_253 -> V_254 ) ) ) {
if ( F_55 ( V_253 -> V_2 ) ) {
if ( F_75 ( V_253 -> V_2 ) == - V_209 )
continue;
V_253 -> V_2 = NULL ;
return;
}
if ( V_253 -> V_4 == V_253 -> V_2 -> V_5 . V_6 &&
! F_8 ( & V_253 -> V_2 -> V_16 ) )
return;
}
}
static void * F_164 ( struct V_157 * V_158 , T_5 * V_240 )
{
struct V_252 * V_253 = V_158 -> V_239 ;
T_5 V_255 = * V_240 ;
int V_53 ;
if ( V_253 -> V_256 <= * V_240 )
V_255 = ( * V_240 - V_253 -> V_256 ) ;
V_53 = F_127 ( & V_253 -> V_254 ) ;
if ( V_53 )
return NULL ;
do {
F_163 ( V_253 ) ;
} while ( V_253 -> V_2 && V_255 -- );
V_253 -> V_256 = * V_240 ;
return V_253 -> V_2 ;
}
static void * F_165 ( struct V_157 * V_158 , void * V_232 ,
T_5 * V_240 )
{
struct V_252 * V_253 = V_158 -> V_239 ;
( * V_240 ) ++ ;
V_253 -> V_256 = * V_240 ;
F_163 ( V_253 ) ;
return V_253 -> V_2 ;
}
static void F_166 ( struct V_157 * V_158 , void * V_232 )
{
struct V_252 * V_253 = V_158 -> V_239 ;
V_253 -> V_2 = NULL ;
F_129 ( & V_253 -> V_254 ) ;
}
static int F_167 ( struct V_157 * V_158 , void * V_232 )
{
F_134 ( V_158 , V_232 ) ;
return 0 ;
}
static void * F_168 ( struct V_157 * V_158 , T_5 * V_240 )
{
F_68 () ;
if ( * V_240 >= V_257 )
return NULL ;
return V_240 ;
}
static void * F_169 ( struct V_157 * V_158 , void * V_232 ,
T_5 * V_240 )
{
( * V_240 ) ++ ;
if ( * V_240 >= V_257 )
return NULL ;
return V_240 ;
}
static void F_170 ( struct V_157 * V_158 , void * V_232 )
{
F_70 () ;
}
static int F_171 ( struct V_91 * V_91 , struct V_258 * V_258 ,
const struct V_259 * V_260 )
{
int V_53 = F_172 ( V_258 , V_260 , sizeof( struct V_252 ) ) ;
if ( V_53 == 0 ) {
struct V_157 * V_158 = V_258 -> V_139 ;
struct V_252 * V_253 = V_158 -> V_239 ;
V_253 -> V_4 = V_91 -> V_261 ;
V_253 -> V_256 = 0 ;
V_158 -> V_214 = F_109 ( V_262 , V_263 | V_264 ) ;
if ( V_158 -> V_214 )
V_158 -> V_265 = V_262 ;
V_253 -> V_2 = NULL ;
F_125 ( & V_32 , & V_253 -> V_254 ) ;
}
return V_53 ;
}
static int F_173 ( struct V_91 * V_91 , struct V_258 * V_258 )
{
return F_171 ( V_91 , V_258 , & V_266 ) ;
}
static int F_174 ( struct V_91 * V_91 , struct V_258 * V_258 )
{
struct V_157 * V_158 = V_258 -> V_139 ;
struct V_252 * V_253 = V_158 -> V_239 ;
V_253 -> V_2 = NULL ;
F_130 ( & V_253 -> V_254 ) ;
return F_175 ( V_91 , V_258 ) ;
}
static int F_176 ( struct V_91 * V_91 , struct V_258 * V_258 )
{
return F_171 ( V_91 , V_258 , & V_267 ) ;
}
static int F_177 ( struct V_91 * V_91 , struct V_258 * V_258 )
{
int V_53 = F_178 ( V_258 , & V_268 ) ;
if ( V_53 == 0 ) {
struct V_157 * V_158 = V_258 -> V_139 ;
V_158 -> V_239 = V_91 -> V_261 ;
}
return V_53 ;
}
int F_179 ( struct V_3 * V_4 )
{
struct V_269 * V_270 ;
V_270 = F_180 ( V_4 -> V_271 , V_272 ) ;
if ( F_181 ( V_270 ) )
goto V_273;
V_4 -> V_274 = V_270 ;
V_270 = F_182 ( L_18 ,
V_275 | V_276 ,
V_4 -> V_274 , V_4 ,
& V_277 ) ;
if ( F_181 ( V_270 ) )
goto V_273;
V_4 -> V_278 = V_270 ;
V_270 = F_182 ( L_19 ,
V_275 | V_276 ,
V_4 -> V_274 , V_4 ,
& V_279 ) ;
if ( F_181 ( V_270 ) )
goto V_273;
V_4 -> V_280 = V_270 ;
V_270 = F_182 ( L_20 ,
V_275 | V_276 ,
V_4 -> V_274 , V_4 ,
& V_281 ) ;
if ( F_181 ( V_270 ) )
goto V_273;
V_4 -> V_282 = V_270 ;
return 0 ;
V_273:
F_183 ( V_4 ) ;
return V_270 ? F_75 ( V_270 ) : - V_120 ;
}
void F_183 ( struct V_3 * V_4 )
{
if ( V_4 -> V_274 ) {
if ( V_4 -> V_278 ) {
F_184 ( V_4 -> V_278 ) ;
V_4 -> V_278 = NULL ;
}
if ( V_4 -> V_280 ) {
F_184 ( V_4 -> V_280 ) ;
V_4 -> V_280 = NULL ;
}
if ( V_4 -> V_282 ) {
F_184 ( V_4 -> V_282 ) ;
V_4 -> V_282 = NULL ;
}
F_184 ( V_4 -> V_274 ) ;
V_4 -> V_274 = NULL ;
}
}
int F_185 ( void )
{
V_272 = F_180 ( L_21 , NULL ) ;
if ( F_55 ( V_272 ) )
return F_75 ( V_272 ) ;
return V_272 ? 0 : - V_120 ;
}
void F_186 ( void )
{
F_184 ( V_272 ) ;
V_272 = NULL ;
}
