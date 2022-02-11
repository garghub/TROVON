static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
const void * V_5 , T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_13 = 0 ;
int V_14 = F_2 () ;
bool V_15 = V_16 ;
if ( V_15 ) {
V_12 = V_17 -> V_18 . V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_19 ,
sizeof( * V_8 ) + V_6 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_20;
}
if ( ! V_2 -> V_21 )
return;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_6 ) ;
if ( V_8 ) {
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_27 = V_6 ;
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_5 , V_6 ) ;
if ( V_15 )
F_9 ( V_17 , V_12 , V_10 , 0 , V_13 ) ;
}
}
static void F_10 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
struct V_1 * V_2 ;
V_29 -> V_31 = V_32 ;
F_11 ( & V_33 , V_30 ) ;
F_12 (bt, &running_trace_list, running_list) {
F_1 ( V_2 , V_29 -> V_3 , V_34 , V_29 -> V_35 ,
sizeof( V_29 -> V_35 ) ) ;
}
F_13 ( & V_33 , V_30 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_36 V_37 ;
unsigned long V_30 ;
T_3 V_38 [ 2 ] ;
F_15 ( & V_37 ) ;
V_38 [ 0 ] = ( T_3 ) V_37 . V_39 ;
V_38 [ 1 ] = V_37 . V_40 ;
F_16 ( V_30 ) ;
F_1 ( V_2 , 0 , V_41 , V_38 , sizeof( V_38 ) ) ;
F_17 ( V_30 ) ;
}
void F_18 ( struct V_1 * V_2 , const char * V_42 , ... )
{
int V_43 ;
T_4 args ;
unsigned long V_30 ;
char * V_44 ;
if ( F_19 ( V_2 -> V_45 != V_46 &&
! V_16 ) )
return;
if ( ! ( V_2 -> V_47 & V_48 ) )
return;
F_16 ( V_30 ) ;
V_44 = F_20 ( V_2 -> V_49 ) ;
va_start ( args , V_42 ) ;
V_43 = F_21 ( V_44 , V_50 , V_42 , args ) ;
va_end ( args ) ;
F_1 ( V_2 , 0 , V_51 , V_44 , V_43 ) ;
F_17 ( V_30 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_52 , T_5 V_53 ,
T_1 V_3 )
{
if ( ( ( V_2 -> V_47 << V_54 ) & V_52 ) == 0 )
return 1 ;
if ( V_53 && ( V_53 < V_2 -> V_55 || V_53 > V_2 -> V_56 ) )
return 1 ;
if ( V_2 -> V_3 && V_3 != V_2 -> V_3 )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_5 V_53 , int V_57 ,
int V_58 , int V_59 , T_3 V_52 , int error , int V_27 ,
void * V_60 )
{
struct V_28 * V_29 = V_61 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_30 = 0 ;
unsigned long * V_62 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_19 ( V_2 -> V_45 != V_46 && ! V_15 ) )
return;
V_52 |= V_63 [ F_24 ( V_58 ) ? V_64 : V_65 ] ;
V_52 |= F_25 ( V_59 , V_66 ) ;
V_52 |= F_25 ( V_59 , V_67 ) ;
V_52 |= F_25 ( V_59 , V_68 ) ;
V_52 |= F_25 ( V_59 , V_69 ) ;
V_52 |= F_25 ( V_59 , V_70 ) ;
if ( V_58 == V_71 || V_58 == V_72 )
V_52 |= F_26 ( V_73 ) ;
if ( V_58 == V_74 )
V_52 |= F_26 ( V_75 ) ;
V_3 = V_29 -> V_3 ;
if ( F_22 ( V_2 , V_52 , V_53 , V_3 ) )
return;
V_14 = F_27 () ;
if ( V_15 ) {
F_28 ( V_61 ) ;
V_12 = V_17 -> V_18 . V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_19 ,
sizeof( * V_8 ) + V_27 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_20;
}
if ( F_19 ( V_29 -> V_31 != V_32 ) )
F_10 ( V_29 ) ;
F_16 ( V_30 ) ;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_27 ) ;
if ( V_8 ) {
V_62 = F_29 ( V_2 -> V_62 , V_14 ) ;
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> V_62 = ++ ( * V_62 ) ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_14 = V_14 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_57 = V_57 ;
V_8 -> V_4 = V_52 ;
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> error = error ;
V_8 -> V_27 = V_27 ;
if ( V_27 )
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_60 , V_27 ) ;
if ( V_15 ) {
F_9 ( V_17 , V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_17 ( V_30 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_76 ) ;
F_31 ( V_2 -> V_77 ) ;
F_32 ( V_2 -> V_21 ) ;
F_31 ( V_2 -> V_78 ) ;
F_33 ( V_2 -> V_62 ) ;
F_33 ( V_2 -> V_49 ) ;
F_34 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
if ( F_36 ( & V_79 ) )
F_37 () ;
}
int F_38 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( & V_81 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_82 ;
if ( V_2 -> V_45 != V_46 )
F_35 ( V_2 ) ;
return 0 ;
}
static T_6 F_40 ( struct V_83 * V_84 , char T_7 * V_12 ,
T_2 V_85 , T_8 * V_86 )
{
struct V_1 * V_2 = V_84 -> V_87 ;
char V_44 [ 16 ] ;
snprintf ( V_44 , sizeof( V_44 ) , L_1 , F_41 ( & V_2 -> V_88 ) ) ;
return F_42 ( V_12 , V_85 , V_86 , V_44 , strlen ( V_44 ) ) ;
}
static T_6 F_43 ( struct V_83 * V_84 , const char T_7 * V_12 ,
T_2 V_85 , T_8 * V_86 )
{
char * V_89 ;
struct V_1 * V_2 ;
if ( V_85 >= V_50 )
return - V_82 ;
V_89 = F_44 ( V_12 , V_85 ) ;
if ( F_45 ( V_89 ) )
return F_46 ( V_89 ) ;
V_2 = V_84 -> V_87 ;
F_18 ( V_2 , L_2 , V_89 ) ;
F_34 ( V_89 ) ;
return V_85 ;
}
static int F_47 ( struct V_90 * V_44 , void * V_91 ,
void * V_92 , T_2 V_93 )
{
struct V_1 * V_2 ;
if ( ! F_48 ( V_44 ) )
return 1 ;
V_2 = V_44 -> V_94 -> V_87 ;
F_49 ( & V_2 -> V_88 ) ;
return 0 ;
}
static int F_50 ( struct V_95 * V_95 )
{
F_31 ( V_95 ) ;
return 0 ;
}
static struct V_95 * F_51 ( const char * V_96 ,
struct V_95 * V_97 ,
T_9 V_98 ,
struct V_90 * V_44 ,
int * V_99 )
{
return F_52 ( V_96 , V_98 , V_97 , V_44 ,
& V_100 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = NULL ;
if ( V_102 )
V_104 = V_102 -> V_105 ;
if ( V_104 ) {
V_2 -> V_55 = V_104 -> V_106 ;
V_2 -> V_56 = V_104 -> V_106 + V_104 -> V_107 ;
} else {
V_2 -> V_55 = 0 ;
V_2 -> V_56 = - 1ULL ;
}
}
int F_54 ( struct V_80 * V_81 , char * V_108 , T_10 V_26 ,
struct V_101 * V_102 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = NULL ;
struct V_95 * V_78 = NULL ;
int V_111 ;
if ( ! V_110 -> V_112 || ! V_110 -> V_113 )
return - V_82 ;
strncpy ( V_110 -> V_108 , V_108 , V_114 ) ;
V_110 -> V_108 [ V_114 - 1 ] = '\0' ;
F_55 ( V_110 -> V_108 , '/' , '_' ) ;
V_2 = F_56 ( sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_111 = - V_116 ;
V_2 -> V_62 = F_57 (unsigned long) ;
if ( ! V_2 -> V_62 )
goto V_117;
V_2 -> V_49 = F_58 ( V_50 , F_59 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_117;
V_111 = - V_118 ;
F_60 ( & V_119 ) ;
if ( ! V_120 ) {
V_120 = F_61 ( L_3 , NULL ) ;
if ( ! V_120 ) {
F_62 ( & V_119 ) ;
goto V_117;
}
}
F_62 ( & V_119 ) ;
V_78 = F_61 ( V_110 -> V_108 , V_120 ) ;
if ( ! V_78 )
goto V_117;
V_2 -> V_78 = V_78 ;
V_2 -> V_26 = V_26 ;
F_63 ( & V_2 -> V_88 , 0 ) ;
F_64 ( & V_2 -> V_121 ) ;
V_111 = - V_122 ;
V_2 -> V_77 = F_52 ( L_4 , 0444 , V_78 , V_2 ,
& V_123 ) ;
if ( ! V_2 -> V_77 )
goto V_117;
V_2 -> V_76 = F_52 ( L_5 , 0222 , V_78 , V_2 , & V_124 ) ;
if ( ! V_2 -> V_76 )
goto V_117;
V_2 -> V_21 = F_65 ( L_6 , V_78 , V_110 -> V_112 ,
V_110 -> V_113 , & V_125 , V_2 ) ;
if ( ! V_2 -> V_21 )
goto V_117;
V_2 -> V_47 = V_110 -> V_47 ;
if ( ! V_2 -> V_47 )
V_2 -> V_47 = ( V_126 ) - 1 ;
F_53 ( V_2 , V_102 ) ;
if ( V_110 -> V_55 )
V_2 -> V_55 = V_110 -> V_55 ;
if ( V_110 -> V_56 )
V_2 -> V_56 = V_110 -> V_56 ;
V_2 -> V_3 = V_110 -> V_3 ;
V_2 -> V_45 = V_127 ;
V_111 = - V_128 ;
if ( F_66 ( & V_81 -> V_1 , NULL , V_2 ) )
goto V_117;
if ( F_67 ( & V_79 ) == 1 )
F_68 () ;
return 0 ;
V_117:
F_30 ( V_2 ) ;
return V_111 ;
}
int F_69 ( struct V_80 * V_81 , char * V_108 , T_10 V_26 ,
struct V_101 * V_102 ,
char T_7 * V_129 )
{
struct V_109 V_110 ;
int V_111 ;
V_111 = F_70 ( & V_110 , V_129 , sizeof( V_110 ) ) ;
if ( V_111 )
return - V_130 ;
V_111 = F_54 ( V_81 , V_108 , V_26 , V_102 , & V_110 ) ;
if ( V_111 )
return V_111 ;
if ( F_71 ( V_129 , & V_110 , sizeof( V_110 ) ) ) {
F_38 ( V_81 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_72 ( struct V_80 * V_81 , char * V_108 ,
T_10 V_26 , struct V_101 * V_102 ,
char T_7 * V_129 )
{
struct V_109 V_110 ;
struct V_131 V_132 ;
int V_111 ;
if ( F_70 ( & V_132 , V_129 , sizeof( V_132 ) ) )
return - V_130 ;
V_110 = (struct V_109 ) {
. V_47 = V_132 . V_47 ,
. V_112 = V_132 . V_112 ,
. V_113 = V_132 . V_113 ,
. V_55 = V_132 . V_55 ,
. V_56 = V_132 . V_56 ,
. V_3 = V_132 . V_3 ,
} ;
V_111 = F_54 ( V_81 , V_108 , V_26 , V_102 , & V_110 ) ;
if ( V_111 )
return V_111 ;
if ( F_71 ( V_129 , & V_110 . V_108 , F_73 ( V_110 . V_108 ) ) ) {
F_38 ( V_81 ) ;
return - V_130 ;
}
return 0 ;
}
int F_74 ( struct V_80 * V_81 , int V_133 )
{
int V_111 ;
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 == NULL )
return - V_82 ;
V_111 = - V_82 ;
if ( V_133 ) {
if ( V_2 -> V_45 == V_127 ||
V_2 -> V_45 == V_134 ) {
V_32 ++ ;
F_75 () ;
V_2 -> V_45 = V_46 ;
F_76 ( & V_33 ) ;
F_77 ( & V_2 -> V_121 , & V_135 ) ;
F_78 ( & V_33 ) ;
F_14 ( V_2 ) ;
V_111 = 0 ;
}
} else {
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_134 ;
F_76 ( & V_33 ) ;
F_79 ( & V_2 -> V_121 ) ;
F_78 ( & V_33 ) ;
F_80 ( V_2 -> V_21 ) ;
V_111 = 0 ;
}
}
return V_111 ;
}
int F_81 ( struct V_101 * V_102 , unsigned V_136 , char T_7 * V_129 )
{
struct V_80 * V_81 ;
int V_111 , V_133 = 0 ;
char V_137 [ V_138 ] ;
V_81 = F_82 ( V_102 ) ;
if ( ! V_81 )
return - V_139 ;
F_60 ( & V_102 -> V_140 ) ;
switch ( V_136 ) {
case V_141 :
F_83 ( V_102 , V_137 ) ;
V_111 = F_69 ( V_81 , V_137 , V_102 -> V_142 , V_102 , V_129 ) ;
break;
#if F_84 ( V_143 ) && F_84 ( V_144 )
case V_145 :
F_83 ( V_102 , V_137 ) ;
V_111 = F_72 ( V_81 , V_137 , V_102 -> V_142 , V_102 , V_129 ) ;
break;
#endif
case V_146 :
V_133 = 1 ;
case V_147 :
V_111 = F_74 ( V_81 , V_133 ) ;
break;
case V_148 :
V_111 = F_38 ( V_81 ) ;
break;
default:
V_111 = - V_149 ;
break;
}
F_62 ( & V_102 -> V_140 ) ;
return V_111 ;
}
void F_85 ( struct V_80 * V_81 )
{
if ( V_81 -> V_1 ) {
F_74 ( V_81 , 0 ) ;
F_38 ( V_81 ) ;
}
}
static void F_86 ( struct V_80 * V_81 , struct V_150 * V_151 ,
unsigned int V_152 , T_3 V_52 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( F_87 ( ! V_2 ) )
return;
if ( V_151 -> V_153 == V_154 ) {
V_52 |= F_26 ( V_155 ) ;
F_23 ( V_2 , 0 , V_152 , F_88 ( V_151 ) , V_151 -> V_156 ,
V_52 , V_151 -> V_157 , V_151 -> V_158 , V_151 -> V_136 ) ;
} else {
V_52 |= F_26 ( V_159 ) ;
F_23 ( V_2 , F_89 ( V_151 ) , V_152 , F_88 ( V_151 ) ,
V_151 -> V_156 , V_52 , V_151 -> V_157 , 0 , NULL ) ;
}
}
static void F_90 ( void * V_160 ,
struct V_80 * V_81 , struct V_150 * V_151 )
{
F_86 ( V_81 , V_151 , F_91 ( V_151 ) , V_161 ) ;
}
static void F_92 ( void * V_160 ,
struct V_80 * V_81 , struct V_150 * V_151 )
{
F_86 ( V_81 , V_151 , F_91 ( V_151 ) , V_162 ) ;
}
static void F_93 ( void * V_160 ,
struct V_80 * V_81 , struct V_150 * V_151 )
{
F_86 ( V_81 , V_151 , F_91 ( V_151 ) , V_163 ) ;
}
static void F_94 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_150 * V_151 )
{
F_86 ( V_81 , V_151 , F_91 ( V_151 ) , V_164 ) ;
}
static void F_95 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_150 * V_151 ,
unsigned int V_152 )
{
F_86 ( V_81 , V_151 , V_152 , V_165 ) ;
}
static void F_96 ( struct V_80 * V_81 , struct V_166 * V_166 ,
T_3 V_52 , int error )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( F_87 ( ! V_2 ) )
return;
F_23 ( V_2 , V_166 -> V_167 . V_168 , V_166 -> V_167 . V_169 ,
F_97 ( V_166 ) , V_166 -> V_170 , V_52 , error , 0 , NULL ) ;
}
static void F_98 ( void * V_160 ,
struct V_80 * V_81 , struct V_166 * V_166 )
{
F_96 ( V_81 , V_166 , V_171 , 0 ) ;
}
static void F_99 ( void * V_160 ,
struct V_80 * V_81 , struct V_166 * V_166 ,
int error )
{
F_96 ( V_81 , V_166 , V_165 , error ) ;
}
static void F_100 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_150 * V_151 ,
struct V_166 * V_166 )
{
F_96 ( V_81 , V_166 , V_172 , 0 ) ;
}
static void F_101 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_150 * V_151 ,
struct V_166 * V_166 )
{
F_96 ( V_81 , V_166 , V_173 , 0 ) ;
}
static void F_102 ( void * V_160 ,
struct V_80 * V_81 , struct V_166 * V_166 )
{
F_96 ( V_81 , V_166 , V_174 , 0 ) ;
}
static void F_103 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_166 * V_166 , int V_175 )
{
if ( V_166 )
F_96 ( V_81 , V_166 , V_176 , 0 ) ;
else {
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_175 , 0 , V_176 , 0 , 0 ,
NULL ) ;
}
}
static void F_104 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_166 * V_166 , int V_175 )
{
if ( V_166 )
F_96 ( V_81 , V_166 , V_177 , 0 ) ;
else {
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_175 , 0 , V_177 ,
0 , 0 , NULL ) ;
}
}
static void F_105 ( void * V_160 , struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , 0 , 0 , V_178 , 0 , 0 , NULL ) ;
}
static void F_106 ( void * V_160 , struct V_80 * V_81 ,
unsigned int V_179 , bool V_180 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 ) {
T_11 V_181 = F_107 ( V_179 ) ;
T_3 V_52 ;
if ( V_180 )
V_52 = V_182 ;
else
V_52 = V_183 ;
F_23 ( V_2 , 0 , 0 , 0 , 0 , V_52 , 0 , sizeof( V_181 ) , & V_181 ) ;
}
}
static void F_108 ( void * V_160 ,
struct V_80 * V_81 , struct V_166 * V_166 ,
unsigned int V_184 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 ) {
T_11 V_181 = F_107 ( V_184 ) ;
F_23 ( V_2 , V_166 -> V_167 . V_168 ,
V_166 -> V_167 . V_169 , F_97 ( V_166 ) , V_166 -> V_170 ,
V_185 , V_166 -> V_186 , sizeof( V_181 ) ,
& V_181 ) ;
}
}
static void F_109 ( void * V_160 ,
struct V_80 * V_81 , struct V_166 * V_166 ,
T_10 V_26 , T_5 V_187 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
struct V_188 V_189 ;
if ( F_87 ( ! V_2 ) )
return;
V_189 . V_190 = F_110 ( V_26 ) ;
V_189 . V_191 = F_110 ( V_166 -> V_192 -> V_142 ) ;
V_189 . V_193 = F_107 ( V_187 ) ;
F_23 ( V_2 , V_166 -> V_167 . V_168 , V_166 -> V_167 . V_169 ,
F_97 ( V_166 ) , V_166 -> V_170 , V_194 , V_166 -> V_186 ,
sizeof( V_189 ) , & V_189 ) ;
}
static void F_111 ( void * V_160 ,
struct V_80 * V_81 ,
struct V_150 * V_151 , T_10 V_26 ,
T_5 V_187 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
struct V_188 V_189 ;
if ( F_87 ( ! V_2 ) )
return;
V_189 . V_190 = F_110 ( V_26 ) ;
V_189 . V_191 = F_110 ( F_112 ( V_151 -> V_195 ) ) ;
V_189 . V_193 = F_107 ( V_187 ) ;
F_23 ( V_2 , F_89 ( V_151 ) , F_91 ( V_151 ) ,
F_113 ( V_151 ) , 0 , V_194 , ! ! V_151 -> V_157 ,
sizeof( V_189 ) , & V_189 ) ;
}
void F_114 ( struct V_80 * V_81 ,
struct V_150 * V_151 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( F_87 ( ! V_2 ) )
return;
if ( V_151 -> V_153 == V_154 )
F_23 ( V_2 , 0 , F_91 ( V_151 ) , 0 , 0 ,
V_196 , V_151 -> V_157 , V_6 , V_5 ) ;
else
F_23 ( V_2 , F_89 ( V_151 ) , F_91 ( V_151 ) , 0 , 0 ,
V_196 , V_151 -> V_157 , V_6 , V_5 ) ;
}
static void F_68 ( void )
{
int V_111 ;
V_111 = F_115 ( F_90 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_117 ( F_92 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_118 ( F_93 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_119 ( F_94 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_120 ( F_95 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_121 ( F_98 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_122 ( F_99 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_123 ( F_100 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_124 ( F_101 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_125 ( F_102 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_126 ( F_103 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_127 ( F_104 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_128 ( F_105 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_129 ( F_106 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_130 ( F_108 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_131 ( F_109 , NULL ) ;
F_116 ( V_111 ) ;
V_111 = F_132 ( F_111 , NULL ) ;
F_116 ( V_111 ) ;
}
static void F_37 ( void )
{
F_133 ( F_111 , NULL ) ;
F_134 ( F_109 , NULL ) ;
F_135 ( F_108 , NULL ) ;
F_136 ( F_106 , NULL ) ;
F_137 ( F_105 , NULL ) ;
F_138 ( F_104 , NULL ) ;
F_139 ( F_103 , NULL ) ;
F_140 ( F_102 , NULL ) ;
F_141 ( F_101 , NULL ) ;
F_142 ( F_100 , NULL ) ;
F_143 ( F_99 , NULL ) ;
F_144 ( F_98 , NULL ) ;
F_145 ( F_95 , NULL ) ;
F_146 ( F_94 , NULL ) ;
F_147 ( F_93 , NULL ) ;
F_148 ( F_92 , NULL ) ;
F_149 ( F_90 , NULL ) ;
F_150 () ;
}
static void F_151 ( char * V_197 , const struct V_7 * V_8 )
{
int V_198 = 0 ;
int V_199 = V_8 -> V_4 >> V_54 ;
if ( V_8 -> V_4 == V_51 ) {
V_197 [ V_198 ++ ] = 'N' ;
goto V_200;
}
if ( V_199 & V_75 )
V_197 [ V_198 ++ ] = 'F' ;
if ( V_199 & V_73 )
V_197 [ V_198 ++ ] = 'D' ;
else if ( V_199 & V_201 )
V_197 [ V_198 ++ ] = 'W' ;
else if ( V_8 -> V_57 )
V_197 [ V_198 ++ ] = 'R' ;
else
V_197 [ V_198 ++ ] = 'N' ;
if ( V_199 & V_202 )
V_197 [ V_198 ++ ] = 'F' ;
if ( V_199 & V_203 )
V_197 [ V_198 ++ ] = 'A' ;
if ( V_199 & V_204 )
V_197 [ V_198 ++ ] = 'S' ;
if ( V_199 & V_205 )
V_197 [ V_198 ++ ] = 'M' ;
V_200:
V_197 [ V_198 ] = '\0' ;
}
static inline
const struct V_7 * F_152 ( const struct V_206 * V_207 )
{
return ( const struct V_7 * ) V_207 ;
}
static inline const void * F_153 ( const struct V_206 * V_207 )
{
return F_152 ( V_207 ) + 1 ;
}
static inline T_3 F_154 ( const struct V_206 * V_207 )
{
return F_152 ( V_207 ) -> V_4 ;
}
static inline T_3 F_155 ( const struct V_206 * V_207 )
{
return F_152 ( V_207 ) -> V_57 ;
}
static inline T_3 F_156 ( const struct V_206 * V_207 )
{
return F_152 ( V_207 ) -> V_57 >> 9 ;
}
static inline unsigned long long F_157 ( const struct V_206 * V_207 )
{
return F_152 ( V_207 ) -> V_53 ;
}
static inline T_12 F_158 ( const struct V_206 * V_207 )
{
return F_152 ( V_207 ) -> error ;
}
static T_13 F_159 ( const struct V_206 * V_207 )
{
const T_13 * V_208 = F_153 ( V_207 ) ;
return F_160 ( * V_208 ) ;
}
static void F_161 ( const struct V_206 * V_207 ,
struct V_188 * V_189 )
{
const struct V_188 * V_209 = F_153 ( V_207 ) ;
T_13 V_193 = V_209 -> V_193 ;
V_189 -> V_190 = F_162 ( V_209 -> V_190 ) ;
V_189 -> V_191 = F_162 ( V_209 -> V_191 ) ;
V_189 -> V_193 = F_160 ( V_193 ) ;
}
static void F_163 ( struct V_210 * V_211 , const char * V_212 )
{
char V_197 [ V_213 ] ;
unsigned long long V_214 = V_211 -> V_214 ;
unsigned long V_215 = F_164 ( V_214 , V_216 ) ;
unsigned V_217 = ( unsigned long ) V_214 ;
const struct V_7 * V_8 = F_152 ( V_211 -> V_207 ) ;
F_151 ( V_197 , V_8 ) ;
F_165 ( & V_211 -> V_218 ,
L_7 ,
F_166 ( V_8 -> V_25 ) , F_167 ( V_8 -> V_25 ) , V_211 -> V_14 ,
V_217 , V_215 , V_211 -> V_207 -> V_3 , V_212 , V_197 ) ;
}
static void F_168 ( struct V_210 * V_211 , const char * V_212 )
{
char V_197 [ V_213 ] ;
const struct V_7 * V_8 = F_152 ( V_211 -> V_207 ) ;
F_151 ( V_197 , V_8 ) ;
F_165 ( & V_211 -> V_218 , L_8 ,
F_166 ( V_8 -> V_25 ) , F_167 ( V_8 -> V_25 ) , V_212 , V_197 ) ;
}
static void F_169 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
const unsigned char * V_221 ;
int V_27 ;
int V_198 , V_222 ;
V_221 = F_153 ( V_207 ) ;
V_27 = F_152 ( V_207 ) -> V_27 ;
if ( ! V_27 )
return;
for ( V_222 = V_27 - 1 ; V_222 >= 0 ; V_222 -- )
if ( V_221 [ V_222 ] )
break;
V_222 ++ ;
F_170 ( V_220 , '(' ) ;
for ( V_198 = 0 ; V_198 < V_27 ; V_198 ++ ) {
F_165 ( V_220 , L_9 ,
V_198 == 0 ? L_10 : L_11 , V_221 [ V_198 ] ) ;
if ( V_198 == V_222 && V_222 != V_27 - 1 ) {
F_171 ( V_220 , L_12 ) ;
return;
}
}
F_171 ( V_220 , L_13 ) ;
}
static void F_172 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
char V_136 [ V_223 ] ;
F_173 ( V_207 -> V_3 , V_136 ) ;
if ( F_154 ( V_207 ) & F_26 ( V_155 ) ) {
F_165 ( V_220 , L_14 , F_155 ( V_207 ) ) ;
F_169 ( V_220 , V_207 ) ;
F_165 ( V_220 , L_15 , V_136 ) ;
} else {
if ( F_156 ( V_207 ) )
F_165 ( V_220 , L_16 ,
F_157 ( V_207 ) , F_156 ( V_207 ) , V_136 ) ;
else
F_165 ( V_220 , L_15 , V_136 ) ;
}
}
static void F_174 ( struct V_219 * V_220 ,
const struct V_206 * V_207 )
{
if ( F_154 ( V_207 ) & F_26 ( V_155 ) ) {
F_169 ( V_220 , V_207 ) ;
F_165 ( V_220 , L_17 , F_158 ( V_207 ) ) ;
} else {
if ( F_156 ( V_207 ) )
F_165 ( V_220 , L_18 ,
F_157 ( V_207 ) ,
F_156 ( V_207 ) , F_158 ( V_207 ) ) ;
else
F_165 ( V_220 , L_19 ,
F_157 ( V_207 ) , F_158 ( V_207 ) ) ;
}
}
static void F_175 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
struct V_188 V_189 = { . V_190 = 0 , } ;
F_161 ( V_207 , & V_189 ) ;
F_165 ( V_220 , L_20 ,
F_157 ( V_207 ) , F_156 ( V_207 ) ,
F_166 ( V_189 . V_190 ) , F_167 ( V_189 . V_190 ) ,
( unsigned long long ) V_189 . V_193 ) ;
}
static void F_176 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
char V_136 [ V_223 ] ;
F_173 ( V_207 -> V_3 , V_136 ) ;
F_165 ( V_220 , L_15 , V_136 ) ;
}
static void F_177 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
char V_136 [ V_223 ] ;
F_173 ( V_207 -> V_3 , V_136 ) ;
F_165 ( V_220 , L_21 , V_136 , F_159 ( V_207 ) ) ;
}
static void F_178 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
char V_136 [ V_223 ] ;
F_173 ( V_207 -> V_3 , V_136 ) ;
F_165 ( V_220 , L_22 , F_157 ( V_207 ) ,
F_159 ( V_207 ) , V_136 ) ;
}
static void F_179 ( struct V_219 * V_220 , const struct V_206 * V_207 )
{
const struct V_7 * V_8 = F_152 ( V_207 ) ;
F_180 ( V_220 , V_8 + 1 , V_8 -> V_27 ) ;
F_170 ( V_220 , '\n' ) ;
}
static void F_181 ( struct V_224 * V_225 )
{
if ( ! ( V_226 . V_208 & V_227 ) )
return;
F_182 ( V_225 , L_23
L_24 ) ;
}
static void F_183 ( struct V_228 * V_229 )
{
V_16 = true ;
}
static int F_184 ( struct V_228 * V_229 )
{
V_17 = V_229 ;
F_183 ( V_229 ) ;
return 0 ;
}
static void F_185 ( struct V_228 * V_229 )
{
V_16 = false ;
}
static void F_186 ( struct V_228 * V_229 )
{
F_185 ( V_229 ) ;
}
static enum V_230 F_187 ( struct V_210 * V_211 ,
bool V_231 )
{
struct V_228 * V_229 = V_211 -> V_229 ;
struct V_219 * V_220 = & V_211 -> V_218 ;
const struct V_7 * V_8 ;
V_126 V_52 ;
bool V_232 ;
T_14 * V_233 ;
V_8 = F_152 ( V_211 -> V_207 ) ;
V_52 = V_8 -> V_4 & ( ( 1 << V_54 ) - 1 ) ;
V_232 = ! ! ( V_229 -> V_234 & V_235 ) ;
V_233 = V_231 ? & F_163 : & F_168 ;
if ( V_8 -> V_4 == V_51 ) {
V_233 ( V_211 , V_232 ? L_25 : L_26 ) ;
F_179 ( V_220 , V_211 -> V_207 ) ;
return F_188 ( V_220 ) ;
}
if ( F_19 ( V_52 == 0 || V_52 >= F_73 ( V_236 ) ) )
F_165 ( V_220 , L_27 , V_52 ) ;
else {
V_233 ( V_211 , V_236 [ V_52 ] . V_212 [ V_232 ] ) ;
V_236 [ V_52 ] . F_189 ( V_220 , V_211 -> V_207 ) ;
}
return F_188 ( V_220 ) ;
}
static enum V_230 F_190 ( struct V_210 * V_211 ,
int V_30 , struct V_237 * V_10 )
{
return F_187 ( V_211 , false ) ;
}
static void F_191 ( struct V_210 * V_211 )
{
struct V_219 * V_220 = & V_211 -> V_218 ;
struct V_7 * V_8 = (struct V_7 * ) V_211 -> V_207 ;
const int V_238 = F_192 ( struct V_7 , V_53 ) ;
struct V_7 V_239 = {
. V_22 = V_23 | V_24 ,
. time = V_211 -> V_214 ,
} ;
F_180 ( V_220 , & V_239 , V_238 ) ;
F_180 ( V_220 , & V_8 -> V_53 ,
sizeof( V_239 ) - V_238 + V_8 -> V_27 ) ;
}
static enum V_230
F_193 ( struct V_210 * V_211 , int V_30 ,
struct V_237 * V_10 )
{
F_191 ( V_211 ) ;
return F_188 ( & V_211 -> V_218 ) ;
}
static enum V_230 F_194 ( struct V_210 * V_211 )
{
if ( ! ( V_226 . V_208 & V_227 ) )
return V_240 ;
return F_187 ( V_211 , true ) ;
}
static int
F_195 ( struct V_228 * V_229 , T_3 V_241 , T_3 V_242 , int V_243 )
{
if ( V_242 == V_227 ) {
if ( V_243 )
V_229 -> V_234 &= ~ V_244 ;
else
V_229 -> V_234 |= V_244 ;
}
return 0 ;
}
static int T_15 F_196 ( void )
{
if ( ! F_197 ( & V_245 ) ) {
F_198 ( L_28 ) ;
return 1 ;
}
if ( F_199 ( & V_15 ) != 0 ) {
F_198 ( L_29 ) ;
F_200 ( & V_245 ) ;
return 1 ;
}
return 0 ;
}
static int F_201 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( & V_81 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_82 ;
if ( F_36 ( & V_79 ) )
F_37 () ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_202 ( struct V_80 * V_81 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = NULL ;
int V_111 = - V_116 ;
V_2 = F_56 ( sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_2 -> V_49 = F_58 ( V_50 , F_59 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_246;
V_2 -> V_26 = V_102 -> V_142 ;
V_2 -> V_47 = ( V_126 ) - 1 ;
F_53 ( V_2 , V_102 ) ;
V_111 = - V_128 ;
if ( F_66 ( & V_81 -> V_1 , NULL , V_2 ) )
goto V_246;
if ( F_67 ( & V_79 ) == 1 )
F_68 () ;
return 0 ;
V_246:
F_30 ( V_2 ) ;
return V_111 ;
}
static int F_203 ( const char * V_247 )
{
int V_198 ;
int V_248 = 0 ;
char * V_44 , * V_220 , * V_249 ;
V_44 = F_204 ( V_247 , V_115 ) ;
if ( V_44 == NULL )
return - V_116 ;
V_220 = F_205 ( V_44 ) ;
while ( 1 ) {
V_249 = F_206 ( & V_220 , L_30 ) ;
if ( V_249 == NULL )
break;
if ( * V_249 == '\0' )
continue;
for ( V_198 = 0 ; V_198 < F_73 ( V_250 ) ; V_198 ++ ) {
if ( strcasecmp ( V_249 , V_250 [ V_198 ] . V_247 ) == 0 ) {
V_248 |= V_250 [ V_198 ] . V_248 ;
break;
}
}
if ( V_198 == F_73 ( V_250 ) ) {
V_248 = - V_82 ;
break;
}
}
F_34 ( V_44 ) ;
return V_248 ;
}
static T_6 F_207 ( char * V_44 , int V_248 )
{
int V_198 ;
char * V_251 = V_44 ;
for ( V_198 = 0 ; V_198 < F_73 ( V_250 ) ; V_198 ++ ) {
if ( V_248 & V_250 [ V_198 ] . V_248 ) {
V_251 += sprintf ( V_251 , L_31 ,
( V_251 == V_44 ) ? L_10 : L_30 , V_250 [ V_198 ] . V_247 ) ;
}
}
* V_251 ++ = '\n' ;
return V_251 - V_44 ;
}
static struct V_80 * F_208 ( struct V_101 * V_102 )
{
if ( V_102 -> V_252 == NULL )
return NULL ;
return F_82 ( V_102 ) ;
}
static T_6 F_209 ( struct V_25 * V_26 ,
struct V_253 * V_254 ,
char * V_44 )
{
struct V_103 * V_251 = F_210 ( V_26 ) ;
struct V_80 * V_81 ;
struct V_101 * V_102 ;
T_6 V_111 = - V_139 ;
V_102 = F_211 ( F_212 ( V_251 ) ) ;
if ( V_102 == NULL )
goto V_200;
V_81 = F_208 ( V_102 ) ;
if ( V_81 == NULL )
goto V_255;
F_60 ( & V_102 -> V_140 ) ;
if ( V_254 == & V_256 ) {
V_111 = sprintf ( V_44 , L_1 , ! ! V_81 -> V_1 ) ;
goto V_257;
}
if ( V_81 -> V_1 == NULL )
V_111 = sprintf ( V_44 , L_32 ) ;
else if ( V_254 == & V_258 )
V_111 = F_207 ( V_44 , V_81 -> V_1 -> V_47 ) ;
else if ( V_254 == & V_259 )
V_111 = sprintf ( V_44 , L_1 , V_81 -> V_1 -> V_3 ) ;
else if ( V_254 == & V_260 )
V_111 = sprintf ( V_44 , L_33 , V_81 -> V_1 -> V_55 ) ;
else if ( V_254 == & V_261 )
V_111 = sprintf ( V_44 , L_33 , V_81 -> V_1 -> V_56 ) ;
V_257:
F_62 ( & V_102 -> V_140 ) ;
V_255:
F_213 ( V_102 ) ;
V_200:
return V_111 ;
}
static T_6 F_214 ( struct V_25 * V_26 ,
struct V_253 * V_254 ,
const char * V_44 , T_2 V_85 )
{
struct V_101 * V_102 ;
struct V_80 * V_81 ;
struct V_103 * V_251 ;
T_16 V_262 ;
T_6 V_111 = - V_82 ;
if ( V_85 == 0 )
goto V_200;
if ( V_254 == & V_258 ) {
if ( sscanf ( V_44 , L_34 , & V_262 ) != 1 ) {
V_111 = F_203 ( V_44 ) ;
if ( V_111 < 0 )
goto V_200;
V_262 = V_111 ;
}
} else if ( sscanf ( V_44 , L_35 , & V_262 ) != 1 )
goto V_200;
V_111 = - V_139 ;
V_251 = F_210 ( V_26 ) ;
V_102 = F_211 ( F_212 ( V_251 ) ) ;
if ( V_102 == NULL )
goto V_200;
V_81 = F_208 ( V_102 ) ;
if ( V_81 == NULL )
goto V_255;
F_60 ( & V_102 -> V_140 ) ;
if ( V_254 == & V_256 ) {
if ( V_262 )
V_111 = F_202 ( V_81 , V_102 ) ;
else
V_111 = F_201 ( V_81 ) ;
goto V_257;
}
V_111 = 0 ;
if ( V_81 -> V_1 == NULL )
V_111 = F_202 ( V_81 , V_102 ) ;
if ( V_111 == 0 ) {
if ( V_254 == & V_258 )
V_81 -> V_1 -> V_47 = V_262 ;
else if ( V_254 == & V_259 )
V_81 -> V_1 -> V_3 = V_262 ;
else if ( V_254 == & V_260 )
V_81 -> V_1 -> V_55 = V_262 ;
else if ( V_254 == & V_261 )
V_81 -> V_1 -> V_56 = V_262 ;
}
V_257:
F_62 ( & V_102 -> V_140 ) ;
V_255:
F_213 ( V_102 ) ;
V_200:
return V_111 ? V_111 : V_85 ;
}
int F_215 ( struct V_25 * V_26 )
{
return F_216 ( & V_26 -> V_263 , & V_264 ) ;
}
void F_217 ( struct V_25 * V_26 )
{
F_218 ( & V_26 -> V_263 , & V_264 ) ;
}
void F_219 ( char * V_44 , struct V_150 * V_151 )
{
int V_198 , V_222 ;
int V_6 = V_151 -> V_158 ;
unsigned char * V_136 = V_151 -> V_136 ;
if ( V_151 -> V_153 != V_154 ) {
V_44 [ 0 ] = '\0' ;
return;
}
for ( V_222 = V_6 - 1 ; V_222 >= 0 ; V_222 -- )
if ( V_136 [ V_222 ] )
break;
V_222 ++ ;
for ( V_198 = 0 ; V_198 < V_6 ; V_198 ++ ) {
V_44 += sprintf ( V_44 , L_9 , V_198 == 0 ? L_10 : L_11 , V_136 [ V_198 ] ) ;
if ( V_198 == V_222 && V_222 != V_6 - 1 ) {
sprintf ( V_44 , L_36 ) ;
break;
}
}
}
void F_220 ( char * V_197 , int V_58 , T_3 V_175 , int V_57 )
{
int V_198 = 0 ;
if ( V_175 & V_265 )
V_197 [ V_198 ++ ] = 'F' ;
switch ( V_58 ) {
case V_266 :
case V_267 :
V_197 [ V_198 ++ ] = 'W' ;
break;
case V_71 :
V_197 [ V_198 ++ ] = 'D' ;
break;
case V_72 :
V_197 [ V_198 ++ ] = 'D' ;
V_197 [ V_198 ++ ] = 'E' ;
break;
case V_74 :
V_197 [ V_198 ++ ] = 'F' ;
break;
case V_268 :
V_197 [ V_198 ++ ] = 'R' ;
break;
default:
V_197 [ V_198 ++ ] = 'N' ;
}
if ( V_175 & V_269 )
V_197 [ V_198 ++ ] = 'F' ;
if ( V_175 & V_270 )
V_197 [ V_198 ++ ] = 'A' ;
if ( V_175 & V_271 )
V_197 [ V_198 ++ ] = 'S' ;
if ( V_175 & V_272 )
V_197 [ V_198 ++ ] = 'M' ;
V_197 [ V_198 ] = '\0' ;
}
