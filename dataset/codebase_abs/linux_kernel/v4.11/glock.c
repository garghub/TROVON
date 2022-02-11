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
struct V_1 * V_2 , * V_54 = NULL ;
struct V_29 * V_30 ;
struct V_116 * V_117 ;
int V_53 , V_118 = 0 ;
F_62 () ;
V_2 = F_63 ( & V_32 , & V_114 , V_34 ) ;
if ( V_2 && ! F_64 ( & V_2 -> V_16 ) )
V_2 = NULL ;
F_65 () ;
* V_109 = V_2 ;
if ( V_2 )
return 0 ;
if ( ! V_108 )
return - V_119 ;
if ( V_18 -> V_8 & V_9 )
V_117 = V_10 ;
else
V_117 = V_13 ;
V_2 = F_66 ( V_117 , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
memset ( & V_2 -> V_11 , 0 , sizeof( struct V_122 ) ) ;
if ( V_18 -> V_8 & V_123 ) {
V_2 -> V_11 . V_12 = F_67 ( V_124 , V_120 ) ;
if ( ! V_2 -> V_11 . V_12 ) {
F_2 ( V_117 , V_2 ) ;
return - V_121 ;
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
V_2 -> V_125 = 0 ;
F_68 () ;
V_2 -> V_126 = F_69 ( V_4 -> V_127 ) -> V_128 [ V_18 -> V_115 ] ;
F_70 () ;
V_2 -> V_126 . V_129 [ V_130 ] = 0 ;
V_2 -> V_126 . V_129 [ V_131 ] = 0 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_132 = NULL ;
V_2 -> V_68 = V_133 ;
F_71 ( & V_2 -> V_97 , F_58 ) ;
F_72 ( & V_2 -> V_90 , F_52 ) ;
V_30 = F_23 ( V_2 ) ;
if ( V_30 ) {
V_30 -> V_134 = & V_135 ;
V_30 -> V_136 = V_111 -> V_137 -> V_138 ;
V_30 -> V_139 = 0 ;
F_73 ( V_30 , V_120 ) ;
V_30 -> V_140 = NULL ;
V_30 -> V_141 = 0 ;
}
V_142:
V_53 = F_74 ( & V_32 , & V_2 -> V_33 ,
V_34 ) ;
if ( V_53 == 0 ) {
* V_109 = V_2 ;
return 0 ;
}
if ( V_53 == - V_143 ) {
V_53 = 0 ;
F_62 () ;
V_54 = F_63 ( & V_32 , & V_114 , V_34 ) ;
if ( V_54 == NULL || ! F_64 ( & V_54 -> V_16 ) ) {
if ( ++ V_118 < 100 ) {
F_65 () ;
F_75 () ;
goto V_142;
}
V_54 = NULL ;
V_53 = - V_121 ;
}
F_65 () ;
} else {
F_76 ( V_53 ) ;
}
F_3 ( V_2 -> V_11 . V_12 ) ;
F_2 ( V_117 , V_2 ) ;
F_20 ( & V_4 -> V_14 ) ;
* V_109 = V_54 ;
return V_53 ;
}
void F_77 ( struct V_1 * V_2 , unsigned int V_75 , T_2 V_139 ,
struct V_39 * V_40 )
{
F_78 ( & V_40 -> V_43 ) ;
V_40 -> V_144 = V_2 ;
V_40 -> V_145 = V_146 ;
V_40 -> V_147 = F_79 ( F_80 ( V_148 ) ) ;
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_139 ;
V_40 -> V_57 = 0 ;
V_40 -> V_52 = 0 ;
F_6 ( V_2 ) ;
}
void F_81 ( unsigned int V_75 , T_2 V_139 , struct V_39 * V_40 )
{
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_139 ;
V_40 -> V_52 = 0 ;
V_40 -> V_145 = V_146 ;
F_82 ( V_40 -> V_147 ) ;
V_40 -> V_147 = F_79 ( F_80 ( V_148 ) ) ;
}
void F_83 ( struct V_39 * V_40 )
{
F_82 ( V_40 -> V_147 ) ;
F_22 ( V_40 -> V_144 ) ;
F_84 ( V_40 ) ;
V_40 -> V_145 = 0 ;
}
int F_85 ( struct V_39 * V_40 )
{
unsigned long V_149 = V_72 ;
F_86 () ;
F_87 ( & V_40 -> V_52 , V_51 , V_150 ) ;
if ( F_88 ( V_72 , V_149 + V_151 ) )
V_40 -> V_144 -> V_68 = F_89 ( V_40 -> V_144 -> V_68 +
V_152 ,
V_153 ) ;
return V_40 -> V_57 ;
}
static void F_90 ( struct V_1 * V_2 , unsigned int V_75 ,
unsigned long V_96 , bool V_154 )
{
int V_155 = V_96 ? V_101 : V_74 ;
F_17 ( V_155 , & V_2 -> V_28 ) ;
if ( V_2 -> V_73 == V_45 ) {
V_2 -> V_73 = V_75 ;
V_2 -> V_156 = V_72 ;
} else if ( V_2 -> V_73 != V_20 &&
V_2 -> V_73 != V_75 ) {
V_2 -> V_73 = V_20 ;
}
if ( V_2 -> V_7 -> V_157 )
V_2 -> V_7 -> V_157 ( V_2 , V_154 ) ;
F_91 ( V_2 , V_154 ) ;
}
void F_92 ( struct V_158 * V_159 , const char * V_160 , ... )
{
struct V_161 V_162 ;
T_3 args ;
va_start ( args , V_160 ) ;
if ( V_159 ) {
F_93 ( V_159 , V_160 , args ) ;
} else {
V_162 . V_160 = V_160 ;
V_162 . V_163 = & args ;
F_48 ( L_2 , & V_162 ) ;
}
va_end ( args ) ;
}
static inline void F_94 ( struct V_39 * V_40 )
__releases( &gl->gl_lockref.lock
int F_95 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_144 ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int error = 0 ;
if ( F_45 ( F_35 ( V_164 , & V_4 -> V_165 ) ) )
return - V_58 ;
if ( F_35 ( V_27 , & V_2 -> V_28 ) )
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_94 ( V_40 ) ;
if ( F_45 ( ( V_166 & V_40 -> V_46 ) &&
F_49 ( V_167 , & V_2 -> V_28 ) ) ) {
F_17 ( V_99 , & V_2 -> V_28 ) ;
V_2 -> V_16 . V_65 ++ ;
if ( F_60 ( V_106 , & V_2 -> V_97 , 0 ) == 0 )
V_2 -> V_16 . V_65 -- ;
}
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! ( V_40 -> V_46 & V_168 ) )
error = F_85 ( V_40 ) ;
return error ;
}
int F_96 ( struct V_39 * V_40 )
{
return F_35 ( V_51 , & V_40 -> V_52 ) ? 0 : 1 ;
}
void F_97 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_144 ;
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned V_96 = 0 ;
int V_169 = 0 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_40 -> V_46 & V_170 )
F_90 ( V_2 , V_20 , 0 , false ) ;
F_14 ( & V_40 -> V_43 ) ;
F_21 ( V_55 , & V_40 -> V_52 ) ;
if ( F_50 ( V_2 ) == NULL ) {
if ( V_18 -> V_171 ) {
F_7 ( V_2 , F_98 ( V_85 , & V_2 -> V_28 ) ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
V_18 -> V_171 ( V_40 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
}
if ( F_11 ( & V_2 -> V_21 ) &&
! F_35 ( V_101 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) )
V_169 = 1 ;
}
if ( ! F_35 ( V_172 , & V_2 -> V_28 ) && F_10 ( V_2 ) &&
( V_18 -> V_8 & V_173 ) )
F_12 ( V_2 ) ;
F_36 ( V_40 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_99 ( V_169 ) )
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
struct V_1 * V_2 = V_40 -> V_144 ;
F_97 ( V_40 ) ;
F_86 () ;
F_87 ( & V_2 -> V_28 , V_74 , V_150 ) ;
}
void F_101 ( struct V_39 * V_40 )
{
F_97 ( V_40 ) ;
F_83 ( V_40 ) ;
}
int F_102 ( struct V_3 * V_4 , T_1 V_107 ,
const struct V_17 * V_18 ,
unsigned int V_75 , T_2 V_139 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int error ;
error = F_61 ( V_4 , V_107 , V_18 , V_174 , & V_2 ) ;
if ( ! error ) {
error = F_103 ( V_2 , V_75 , V_139 , V_40 ) ;
F_22 ( V_2 ) ;
}
return error ;
}
static int F_104 ( const void * V_175 , const void * V_176 )
{
const struct V_39 * V_177 = * ( const struct V_39 * * ) V_175 ;
const struct V_39 * V_178 = * ( const struct V_39 * * ) V_176 ;
const struct V_113 * V_179 = & V_177 -> V_144 -> V_5 ;
const struct V_113 * V_180 = & V_178 -> V_144 -> V_5 ;
if ( V_179 -> V_93 > V_180 -> V_93 )
return 1 ;
if ( V_179 -> V_93 < V_180 -> V_93 )
return - 1 ;
F_105 ( V_177 -> V_144 -> V_7 -> V_115 == V_178 -> V_144 -> V_7 -> V_115 ) ;
return 0 ;
}
static int F_106 ( unsigned int V_181 , struct V_39 * V_182 ,
struct V_39 * * V_183 )
{
unsigned int V_184 ;
int error = 0 ;
for ( V_184 = 0 ; V_184 < V_181 ; V_184 ++ )
V_183 [ V_184 ] = & V_182 [ V_184 ] ;
F_107 ( V_183 , V_181 , sizeof( struct V_39 * ) , F_104 , NULL ) ;
for ( V_184 = 0 ; V_184 < V_181 ; V_184 ++ ) {
V_183 [ V_184 ] -> V_46 &= ~ ( V_59 | V_168 ) ;
error = F_95 ( V_183 [ V_184 ] ) ;
if ( error ) {
while ( V_184 -- )
F_97 ( V_183 [ V_184 ] ) ;
break;
}
}
return error ;
}
int F_108 ( unsigned int V_181 , struct V_39 * V_182 )
{
struct V_39 * V_54 [ 4 ] ;
struct V_39 * * V_185 = V_54 ;
int error = 0 ;
switch( V_181 ) {
case 0 :
return 0 ;
case 1 :
V_182 -> V_46 &= ~ ( V_59 | V_168 ) ;
return F_95 ( V_182 ) ;
default:
if ( V_181 <= 4 )
break;
V_185 = F_109 ( V_181 * sizeof( struct V_39 * ) , V_120 ) ;
if ( ! V_185 )
return - V_121 ;
}
error = F_106 ( V_181 , V_182 , V_185 ) ;
if ( V_185 != V_54 )
F_3 ( V_185 ) ;
return error ;
}
void F_110 ( unsigned int V_181 , struct V_39 * V_182 )
{
while ( V_181 -- )
F_97 ( & V_182 [ V_181 ] ) ;
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
if ( V_166 & V_40 -> V_46 )
return 0 ;
}
return 1 ;
}
void F_113 ( struct V_1 * V_2 , int V_53 )
{
struct V_186 * V_187 = & V_2 -> V_5 . V_6 -> V_36 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
V_2 -> V_100 = V_53 ;
if ( F_45 ( F_35 ( V_188 , & V_187 -> V_189 ) ) ) {
if ( F_112 ( V_2 ) ) {
F_17 ( V_167 , & V_2 -> V_28 ) ;
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
static int F_114 ( void * V_190 , struct V_191 * V_179 , struct V_191 * V_180 )
{
struct V_1 * V_192 , * V_193 ;
V_192 = F_29 ( V_179 , struct V_1 , V_24 ) ;
V_193 = F_29 ( V_180 , struct V_1 , V_24 ) ;
if ( V_192 -> V_5 . V_93 > V_193 -> V_5 . V_93 )
return 1 ;
if ( V_192 -> V_5 . V_93 < V_193 -> V_5 . V_93 )
return - 1 ;
return 0 ;
}
static void F_115 ( struct V_191 * V_194 )
__releases( &lru_lock
static long F_116 ( int V_195 )
{
struct V_1 * V_2 ;
F_117 ( V_196 ) ;
F_117 ( V_197 ) ;
long V_198 = 0 ;
F_13 ( & V_23 ) ;
while ( ( V_195 -- >= 0 ) && ! F_11 ( & V_26 ) ) {
V_2 = F_29 ( V_26 . V_42 , struct V_1 , V_24 ) ;
if ( ! F_35 ( V_85 , & V_2 -> V_28 ) ) {
F_118 ( & V_2 -> V_24 , & V_197 ) ;
F_20 ( & V_25 ) ;
V_198 ++ ;
continue;
}
F_118 ( & V_2 -> V_24 , & V_196 ) ;
}
F_119 ( & V_196 , & V_26 ) ;
if ( ! F_11 ( & V_197 ) )
F_115 ( & V_197 ) ;
F_18 ( & V_23 ) ;
return V_198 ;
}
static unsigned long F_120 ( struct V_199 * V_200 ,
struct V_201 * V_202 )
{
if ( ! ( V_202 -> V_203 & V_204 ) )
return V_205 ;
return F_116 ( V_202 -> V_206 ) ;
}
static unsigned long F_121 ( struct V_199 * V_200 ,
struct V_201 * V_202 )
{
return F_122 ( F_123 ( & V_25 ) ) ;
}
static void F_124 ( T_4 V_207 , const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_208 V_209 ;
F_125 ( & V_32 , & V_209 ) ;
do {
V_2 = F_126 ( F_127 ( & V_209 ) ) ;
if ( V_2 )
continue;
while ( ( V_2 = F_128 ( & V_209 ) ) && ! F_55 ( V_2 ) )
if ( ( V_2 -> V_5 . V_6 == V_4 ) &&
F_64 ( & V_2 -> V_16 ) )
V_207 ( V_2 ) ;
F_129 ( & V_209 ) ;
} while ( F_75 () , V_2 == F_126 ( - V_210 ) );
F_130 ( & V_209 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( ! F_49 ( V_167 , & V_2 -> V_28 ) )
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
static void F_134 ( struct V_158 * V_159 , struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_135 ( V_159 , V_2 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_134 ( NULL , V_2 ) ;
}
void F_137 ( struct V_3 * V_4 )
{
F_17 ( V_211 , & V_4 -> V_165 ) ;
F_138 ( V_106 ) ;
F_124 ( F_132 , V_4 ) ;
F_138 ( V_106 ) ;
F_139 ( V_4 -> V_15 ,
F_123 ( & V_4 -> V_14 ) == 0 ,
V_151 * 600 ) ;
F_124 ( F_136 , V_4 ) ;
}
void F_140 ( struct V_212 * V_213 )
{
struct V_1 * V_2 = V_213 -> V_214 ;
int V_53 ;
V_53 = F_141 ( V_213 ) ;
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
static const char * F_144 ( char * V_215 , T_2 V_139 , unsigned long V_216 )
{
char * V_183 = V_215 ;
if ( V_139 & V_59 )
* V_183 ++ = 't' ;
if ( V_139 & V_60 )
* V_183 ++ = 'T' ;
if ( V_139 & V_166 )
* V_183 ++ = 'e' ;
if ( V_139 & V_50 )
* V_183 ++ = 'A' ;
if ( V_139 & V_80 )
* V_183 ++ = 'p' ;
if ( V_139 & V_168 )
* V_183 ++ = 'a' ;
if ( V_139 & V_47 )
* V_183 ++ = 'E' ;
if ( V_139 & V_170 )
* V_183 ++ = 'c' ;
if ( F_35 ( V_55 , & V_216 ) )
* V_183 ++ = 'H' ;
if ( F_35 ( V_51 , & V_216 ) )
* V_183 ++ = 'W' ;
if ( F_35 ( V_217 , & V_216 ) )
* V_183 ++ = 'F' ;
* V_183 = 0 ;
return V_215 ;
}
static void F_145 ( struct V_158 * V_159 , const struct V_39 * V_40 )
{
struct V_218 * V_219 = NULL ;
char V_220 [ 32 ] ;
F_62 () ;
if ( V_40 -> V_147 )
V_219 = F_146 ( V_40 -> V_147 , V_221 ) ;
F_92 ( V_159 , L_8 ,
F_143 ( V_40 -> V_44 ) ,
F_144 ( V_220 , V_40 -> V_46 , V_40 -> V_52 ) ,
V_40 -> V_57 ,
V_40 -> V_147 ? ( long ) F_147 ( V_40 -> V_147 ) : - 1 ,
V_219 ? V_219 -> V_222 : L_9 ,
( void * ) V_40 -> V_145 ) ;
F_65 () ;
}
static const char * F_148 ( char * V_215 , const struct V_1 * V_2 )
{
const unsigned long * V_223 = & V_2 -> V_28 ;
char * V_183 = V_215 ;
if ( F_35 ( V_85 , V_223 ) )
* V_183 ++ = 'l' ;
if ( F_35 ( V_74 , V_223 ) )
* V_183 ++ = 'D' ;
if ( F_35 ( V_101 , V_223 ) )
* V_183 ++ = 'd' ;
if ( F_35 ( V_78 , V_223 ) )
* V_183 ++ = 'p' ;
if ( F_35 ( V_224 , V_223 ) )
* V_183 ++ = 'y' ;
if ( F_35 ( V_172 , V_223 ) )
* V_183 ++ = 'f' ;
if ( F_35 ( V_225 , V_223 ) )
* V_183 ++ = 'i' ;
if ( F_35 ( V_99 , V_223 ) )
* V_183 ++ = 'r' ;
if ( F_35 ( V_226 , V_223 ) )
* V_183 ++ = 'I' ;
if ( F_35 ( V_167 , V_223 ) )
* V_183 ++ = 'F' ;
if ( F_35 ( V_66 , V_223 ) )
* V_183 ++ = 'q' ;
if ( F_35 ( V_27 , V_223 ) )
* V_183 ++ = 'L' ;
if ( V_2 -> V_132 )
* V_183 ++ = 'o' ;
if ( F_35 ( V_227 , V_223 ) )
* V_183 ++ = 'b' ;
* V_183 = 0 ;
return V_215 ;
}
void F_135 ( struct V_158 * V_159 , const struct V_1 * V_2 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned long long V_228 ;
const struct V_39 * V_40 ;
char V_229 [ 32 ] ;
V_228 = V_72 - V_2 -> V_156 ;
V_228 *= 1000000 / V_151 ;
if ( ! F_35 ( V_74 , & V_2 -> V_28 ) )
V_228 = 0 ;
F_92 ( V_159 , L_10 ,
F_143 ( V_2 -> V_19 ) ,
V_2 -> V_5 . V_104 ,
( unsigned long long ) V_2 -> V_5 . V_93 ,
F_148 ( V_229 , V_2 ) ,
F_143 ( V_2 -> V_67 ) ,
F_143 ( V_2 -> V_73 ) , V_228 ,
F_123 ( & V_2 -> V_230 ) ,
F_123 ( & V_2 -> V_231 ) ,
( int ) V_2 -> V_16 . V_65 , V_2 -> V_68 ) ;
F_39 (gh, &gl->gl_holders, gh_list)
F_145 ( V_159 , V_40 ) ;
if ( V_2 -> V_19 != V_20 && V_18 -> V_232 )
V_18 -> V_232 ( V_159 , V_2 ) ;
}
static int F_149 ( struct V_158 * V_159 , void * V_233 )
{
struct V_1 * V_2 = V_233 ;
F_150 ( V_159 , L_11 ,
V_2 -> V_5 . V_104 ,
( unsigned long long ) V_2 -> V_5 . V_93 ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_234 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_235 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_236 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_237 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_238 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_239 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_130 ] ,
( unsigned long long ) V_2 -> V_126 . V_129 [ V_131 ] ) ;
return 0 ;
}
static int F_151 ( struct V_158 * V_159 , void * V_233 )
{
struct V_3 * V_4 = V_159 -> V_240 ;
T_5 V_241 = * ( T_5 * ) V_233 ;
unsigned V_242 = V_241 >> 3 ;
unsigned V_243 = V_241 & 0x07 ;
int V_244 ;
if ( V_242 == 0 && V_243 != 0 )
return 0 ;
F_150 ( V_159 , L_12 , V_245 [ V_242 ] ,
( V_242 == 0 ) ? L_13 : V_246 [ V_243 ] ) ;
F_152 (i) {
const struct V_247 * V_128 = F_153 ( V_4 -> V_127 , V_244 ) ;
if ( V_242 == 0 )
F_150 ( V_159 , L_14 , V_244 ) ;
else
F_150 ( V_159 , L_15 , ( unsigned long long ) V_128 ->
V_128 [ V_242 - 1 ] . V_129 [ V_243 ] ) ;
}
F_154 ( V_159 , '\n' ) ;
return 0 ;
}
int T_6 F_155 ( void )
{
int V_53 ;
V_53 = F_156 ( & V_32 , & V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
V_106 = F_157 ( L_16 , V_248 |
V_249 | V_250 , 0 ) ;
if ( ! V_106 ) {
F_158 ( & V_32 ) ;
return - V_121 ;
}
V_251 = F_157 ( L_17 ,
V_248 | V_250 ,
0 ) ;
if ( ! V_251 ) {
F_159 ( V_106 ) ;
F_158 ( & V_32 ) ;
return - V_121 ;
}
V_53 = F_160 ( & V_252 ) ;
if ( V_53 ) {
F_159 ( V_251 ) ;
F_159 ( V_106 ) ;
F_158 ( & V_32 ) ;
return V_53 ;
}
return 0 ;
}
void F_161 ( void )
{
F_162 ( & V_252 ) ;
F_158 ( & V_32 ) ;
F_159 ( V_106 ) ;
F_159 ( V_251 ) ;
}
static void F_163 ( struct V_253 * V_254 )
{
while ( ( V_254 -> V_2 = F_128 ( & V_254 -> V_255 ) ) ) {
if ( F_55 ( V_254 -> V_2 ) ) {
if ( F_164 ( V_254 -> V_2 ) == - V_210 )
continue;
V_254 -> V_2 = NULL ;
return;
}
if ( V_254 -> V_4 == V_254 -> V_2 -> V_5 . V_6 &&
! F_8 ( & V_254 -> V_2 -> V_16 ) )
return;
}
}
static void * F_165 ( struct V_158 * V_159 , T_5 * V_241 )
{
struct V_253 * V_254 = V_159 -> V_240 ;
T_5 V_256 = * V_241 ;
int V_53 ;
if ( V_254 -> V_257 <= * V_241 )
V_256 = ( * V_241 - V_254 -> V_257 ) ;
V_53 = F_127 ( & V_254 -> V_255 ) ;
if ( V_53 )
return NULL ;
do {
F_163 ( V_254 ) ;
} while ( V_254 -> V_2 && V_256 -- );
V_254 -> V_257 = * V_241 ;
return V_254 -> V_2 ;
}
static void * F_166 ( struct V_158 * V_159 , void * V_233 ,
T_5 * V_241 )
{
struct V_253 * V_254 = V_159 -> V_240 ;
( * V_241 ) ++ ;
V_254 -> V_257 = * V_241 ;
F_163 ( V_254 ) ;
return V_254 -> V_2 ;
}
static void F_167 ( struct V_158 * V_159 , void * V_233 )
{
struct V_253 * V_254 = V_159 -> V_240 ;
V_254 -> V_2 = NULL ;
F_129 ( & V_254 -> V_255 ) ;
}
static int F_168 ( struct V_158 * V_159 , void * V_233 )
{
F_134 ( V_159 , V_233 ) ;
return 0 ;
}
static void * F_169 ( struct V_158 * V_159 , T_5 * V_241 )
{
F_68 () ;
if ( * V_241 >= V_258 )
return NULL ;
return V_241 ;
}
static void * F_170 ( struct V_158 * V_159 , void * V_233 ,
T_5 * V_241 )
{
( * V_241 ) ++ ;
if ( * V_241 >= V_258 )
return NULL ;
return V_241 ;
}
static void F_171 ( struct V_158 * V_159 , void * V_233 )
{
F_70 () ;
}
static int F_172 ( struct V_91 * V_91 , struct V_259 * V_259 )
{
int V_53 = F_173 ( V_259 , & V_260 ,
sizeof( struct V_253 ) ) ;
if ( V_53 == 0 ) {
struct V_158 * V_159 = V_259 -> V_140 ;
struct V_253 * V_254 = V_159 -> V_240 ;
V_254 -> V_4 = V_91 -> V_261 ;
V_254 -> V_257 = 0 ;
V_159 -> V_215 = F_109 ( V_262 , V_263 | V_264 ) ;
if ( V_159 -> V_215 )
V_159 -> V_265 = V_262 ;
V_254 -> V_2 = NULL ;
V_53 = F_174 ( & V_32 , & V_254 -> V_255 , V_263 ) ;
}
return V_53 ;
}
static int F_175 ( struct V_91 * V_91 , struct V_259 * V_259 )
{
struct V_158 * V_159 = V_259 -> V_140 ;
struct V_253 * V_254 = V_159 -> V_240 ;
V_254 -> V_2 = NULL ;
F_130 ( & V_254 -> V_255 ) ;
return F_176 ( V_91 , V_259 ) ;
}
static int F_177 ( struct V_91 * V_91 , struct V_259 * V_259 )
{
int V_53 = F_173 ( V_259 , & V_266 ,
sizeof( struct V_253 ) ) ;
if ( V_53 == 0 ) {
struct V_158 * V_159 = V_259 -> V_140 ;
struct V_253 * V_254 = V_159 -> V_240 ;
V_254 -> V_4 = V_91 -> V_261 ;
V_254 -> V_257 = 0 ;
V_159 -> V_215 = F_109 ( V_262 , V_263 | V_264 ) ;
if ( V_159 -> V_215 )
V_159 -> V_265 = V_262 ;
V_254 -> V_2 = NULL ;
V_53 = F_174 ( & V_32 , & V_254 -> V_255 , V_263 ) ;
}
return V_53 ;
}
static int F_178 ( struct V_91 * V_91 , struct V_259 * V_259 )
{
int V_53 = F_179 ( V_259 , & V_267 ) ;
if ( V_53 == 0 ) {
struct V_158 * V_159 = V_259 -> V_140 ;
V_159 -> V_240 = V_91 -> V_261 ;
}
return V_53 ;
}
int F_180 ( struct V_3 * V_4 )
{
struct V_268 * V_269 ;
V_269 = F_181 ( V_4 -> V_270 , V_271 ) ;
if ( F_182 ( V_269 ) )
goto V_272;
V_4 -> V_273 = V_269 ;
V_269 = F_183 ( L_18 ,
V_274 | V_275 ,
V_4 -> V_273 , V_4 ,
& V_276 ) ;
if ( F_182 ( V_269 ) )
goto V_272;
V_4 -> V_277 = V_269 ;
V_269 = F_183 ( L_19 ,
V_274 | V_275 ,
V_4 -> V_273 , V_4 ,
& V_278 ) ;
if ( F_182 ( V_269 ) )
goto V_272;
V_4 -> V_279 = V_269 ;
V_269 = F_183 ( L_20 ,
V_274 | V_275 ,
V_4 -> V_273 , V_4 ,
& V_280 ) ;
if ( F_182 ( V_269 ) )
goto V_272;
V_4 -> V_281 = V_269 ;
return 0 ;
V_272:
F_184 ( V_4 ) ;
return V_269 ? F_164 ( V_269 ) : - V_121 ;
}
void F_184 ( struct V_3 * V_4 )
{
if ( V_4 -> V_273 ) {
if ( V_4 -> V_277 ) {
F_185 ( V_4 -> V_277 ) ;
V_4 -> V_277 = NULL ;
}
if ( V_4 -> V_279 ) {
F_185 ( V_4 -> V_279 ) ;
V_4 -> V_279 = NULL ;
}
if ( V_4 -> V_281 ) {
F_185 ( V_4 -> V_281 ) ;
V_4 -> V_281 = NULL ;
}
F_185 ( V_4 -> V_273 ) ;
V_4 -> V_273 = NULL ;
}
}
int F_186 ( void )
{
V_271 = F_181 ( L_21 , NULL ) ;
if ( F_55 ( V_271 ) )
return F_164 ( V_271 ) ;
return V_271 ? 0 : - V_121 ;
}
void F_187 ( void )
{
F_185 ( V_271 ) ;
V_271 = NULL ;
}
