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
static int F_54 ( struct V_80 * V_81 , char * V_108 , T_10 V_26 ,
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
if ( ! V_119 )
goto V_117;
V_78 = F_60 ( V_110 -> V_108 , V_119 ) ;
if ( ! V_78 )
V_2 -> V_78 = V_78 = F_61 ( V_110 -> V_108 , V_119 ) ;
if ( ! V_78 )
goto V_117;
V_2 -> V_26 = V_26 ;
F_62 ( & V_2 -> V_88 , 0 ) ;
F_63 ( & V_2 -> V_120 ) ;
V_111 = - V_121 ;
V_2 -> V_77 = F_52 ( L_3 , 0444 , V_78 , V_2 ,
& V_122 ) ;
if ( ! V_2 -> V_77 )
goto V_117;
V_2 -> V_76 = F_52 ( L_4 , 0222 , V_78 , V_2 , & V_123 ) ;
if ( ! V_2 -> V_76 )
goto V_117;
V_2 -> V_21 = F_64 ( L_5 , V_78 , V_110 -> V_112 ,
V_110 -> V_113 , & V_124 , V_2 ) ;
if ( ! V_2 -> V_21 )
goto V_117;
V_2 -> V_47 = V_110 -> V_47 ;
if ( ! V_2 -> V_47 )
V_2 -> V_47 = ( V_125 ) - 1 ;
F_53 ( V_2 , V_102 ) ;
if ( V_110 -> V_55 )
V_2 -> V_55 = V_110 -> V_55 ;
if ( V_110 -> V_56 )
V_2 -> V_56 = V_110 -> V_56 ;
V_2 -> V_3 = V_110 -> V_3 ;
V_2 -> V_45 = V_126 ;
V_111 = - V_127 ;
if ( F_65 ( & V_81 -> V_1 , NULL , V_2 ) )
goto V_117;
if ( F_66 ( & V_79 ) == 1 )
F_67 () ;
V_111 = 0 ;
V_117:
if ( V_78 && ! V_2 -> V_78 )
F_68 ( V_78 ) ;
if ( V_111 )
F_30 ( V_2 ) ;
return V_111 ;
}
int F_69 ( struct V_80 * V_81 , char * V_108 , T_10 V_26 ,
struct V_101 * V_102 ,
char T_7 * V_128 )
{
struct V_109 V_110 ;
int V_111 ;
V_111 = F_70 ( & V_110 , V_128 , sizeof( V_110 ) ) ;
if ( V_111 )
return - V_129 ;
V_111 = F_54 ( V_81 , V_108 , V_26 , V_102 , & V_110 ) ;
if ( V_111 )
return V_111 ;
if ( F_71 ( V_128 , & V_110 , sizeof( V_110 ) ) ) {
F_38 ( V_81 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_72 ( struct V_80 * V_81 , char * V_108 ,
T_10 V_26 , struct V_101 * V_102 ,
char T_7 * V_128 )
{
struct V_109 V_110 ;
struct V_130 V_131 ;
int V_111 ;
if ( F_70 ( & V_131 , V_128 , sizeof( V_131 ) ) )
return - V_129 ;
V_110 = (struct V_109 ) {
. V_47 = V_131 . V_47 ,
. V_112 = V_131 . V_112 ,
. V_113 = V_131 . V_113 ,
. V_55 = V_131 . V_55 ,
. V_56 = V_131 . V_56 ,
. V_3 = V_131 . V_3 ,
} ;
V_111 = F_54 ( V_81 , V_108 , V_26 , V_102 , & V_110 ) ;
if ( V_111 )
return V_111 ;
if ( F_71 ( V_128 , & V_110 . V_108 , F_73 ( V_110 . V_108 ) ) ) {
F_38 ( V_81 ) ;
return - V_129 ;
}
return 0 ;
}
int F_74 ( struct V_80 * V_81 , int V_132 )
{
int V_111 ;
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 == NULL )
return - V_82 ;
V_111 = - V_82 ;
if ( V_132 ) {
if ( V_2 -> V_45 == V_126 ||
V_2 -> V_45 == V_133 ) {
V_32 ++ ;
F_75 () ;
V_2 -> V_45 = V_46 ;
F_76 ( & V_33 ) ;
F_77 ( & V_2 -> V_120 , & V_134 ) ;
F_78 ( & V_33 ) ;
F_14 ( V_2 ) ;
V_111 = 0 ;
}
} else {
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_133 ;
F_76 ( & V_33 ) ;
F_79 ( & V_2 -> V_120 ) ;
F_78 ( & V_33 ) ;
F_80 ( V_2 -> V_21 ) ;
V_111 = 0 ;
}
}
return V_111 ;
}
int F_81 ( struct V_101 * V_102 , unsigned V_135 , char T_7 * V_128 )
{
struct V_80 * V_81 ;
int V_111 , V_132 = 0 ;
char V_136 [ V_137 ] ;
V_81 = F_82 ( V_102 ) ;
if ( ! V_81 )
return - V_138 ;
F_83 ( & V_102 -> V_139 ) ;
switch ( V_135 ) {
case V_140 :
F_84 ( V_102 , V_136 ) ;
V_111 = F_69 ( V_81 , V_136 , V_102 -> V_141 , V_102 , V_128 ) ;
break;
#if F_85 ( V_142 ) && F_85 ( V_143 )
case V_144 :
F_84 ( V_102 , V_136 ) ;
V_111 = F_72 ( V_81 , V_136 , V_102 -> V_141 , V_102 , V_128 ) ;
break;
#endif
case V_145 :
V_132 = 1 ;
case V_146 :
V_111 = F_74 ( V_81 , V_132 ) ;
break;
case V_147 :
V_111 = F_38 ( V_81 ) ;
break;
default:
V_111 = - V_148 ;
break;
}
F_86 ( & V_102 -> V_139 ) ;
return V_111 ;
}
void F_87 ( struct V_80 * V_81 )
{
if ( V_81 -> V_1 ) {
F_74 ( V_81 , 0 ) ;
F_38 ( V_81 ) ;
}
}
static void F_88 ( struct V_149 * V_150 , int error ,
unsigned int V_151 , T_3 V_52 )
{
struct V_1 * V_2 = V_150 -> V_81 -> V_1 ;
if ( F_89 ( ! V_2 ) )
return;
if ( F_90 ( V_150 ) )
V_52 |= F_26 ( V_152 ) ;
else
V_52 |= F_26 ( V_153 ) ;
F_23 ( V_2 , F_91 ( V_150 ) , V_151 , F_92 ( V_150 ) ,
V_150 -> V_154 , V_52 , error , 0 , NULL ) ;
}
static void F_93 ( void * V_155 ,
struct V_80 * V_81 , struct V_149 * V_150 )
{
F_88 ( V_150 , 0 , F_94 ( V_150 ) , V_156 ) ;
}
static void F_95 ( void * V_155 ,
struct V_80 * V_81 , struct V_149 * V_150 )
{
F_88 ( V_150 , 0 , F_94 ( V_150 ) , V_157 ) ;
}
static void F_96 ( void * V_155 ,
struct V_80 * V_81 ,
struct V_149 * V_150 )
{
F_88 ( V_150 , 0 , F_94 ( V_150 ) , V_158 ) ;
}
static void F_97 ( void * V_155 , struct V_149 * V_150 ,
int error , unsigned int V_151 )
{
F_88 ( V_150 , error , V_151 , V_159 ) ;
}
static void F_98 ( struct V_80 * V_81 , struct V_160 * V_160 ,
T_3 V_52 , int error )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( F_89 ( ! V_2 ) )
return;
F_23 ( V_2 , V_160 -> V_161 . V_162 , V_160 -> V_161 . V_163 ,
F_99 ( V_160 ) , V_160 -> V_164 , V_52 , error , 0 , NULL ) ;
}
static void F_100 ( void * V_155 ,
struct V_80 * V_81 , struct V_160 * V_160 )
{
F_98 ( V_81 , V_160 , V_165 , 0 ) ;
}
static void F_101 ( void * V_155 ,
struct V_80 * V_81 , struct V_160 * V_160 ,
int error )
{
F_98 ( V_81 , V_160 , V_159 , error ) ;
}
static void F_102 ( void * V_155 ,
struct V_80 * V_81 ,
struct V_149 * V_150 ,
struct V_160 * V_160 )
{
F_98 ( V_81 , V_160 , V_166 , 0 ) ;
}
static void F_103 ( void * V_155 ,
struct V_80 * V_81 ,
struct V_149 * V_150 ,
struct V_160 * V_160 )
{
F_98 ( V_81 , V_160 , V_167 , 0 ) ;
}
static void F_104 ( void * V_155 ,
struct V_80 * V_81 , struct V_160 * V_160 )
{
F_98 ( V_81 , V_160 , V_168 , 0 ) ;
}
static void F_105 ( void * V_155 ,
struct V_80 * V_81 ,
struct V_160 * V_160 , int V_169 )
{
if ( V_160 )
F_98 ( V_81 , V_160 , V_170 , 0 ) ;
else {
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_169 , 0 , V_170 , 0 , 0 ,
NULL ) ;
}
}
static void F_106 ( void * V_155 ,
struct V_80 * V_81 ,
struct V_160 * V_160 , int V_169 )
{
if ( V_160 )
F_98 ( V_81 , V_160 , V_171 , 0 ) ;
else {
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_169 , 0 , V_171 ,
0 , 0 , NULL ) ;
}
}
static void F_107 ( void * V_155 , struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , 0 , 0 , V_172 , 0 , 0 , NULL ) ;
}
static void F_108 ( void * V_155 , struct V_80 * V_81 ,
unsigned int V_173 , bool V_174 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 ) {
T_11 V_175 = F_109 ( V_173 ) ;
T_3 V_52 ;
if ( V_174 )
V_52 = V_176 ;
else
V_52 = V_177 ;
F_23 ( V_2 , 0 , 0 , 0 , 0 , V_52 , 0 , sizeof( V_175 ) , & V_175 ) ;
}
}
static void F_110 ( void * V_155 ,
struct V_80 * V_81 , struct V_160 * V_160 ,
unsigned int V_178 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( V_2 ) {
T_11 V_175 = F_109 ( V_178 ) ;
F_23 ( V_2 , V_160 -> V_161 . V_162 ,
V_160 -> V_161 . V_163 , F_99 ( V_160 ) , V_160 -> V_164 ,
V_179 , V_160 -> V_180 , sizeof( V_175 ) ,
& V_175 ) ;
}
}
static void F_111 ( void * V_155 ,
struct V_80 * V_81 , struct V_160 * V_160 ,
T_10 V_26 , T_5 V_181 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
struct V_182 V_183 ;
if ( F_89 ( ! V_2 ) )
return;
V_183 . V_184 = F_112 ( V_26 ) ;
V_183 . V_185 = F_112 ( V_160 -> V_186 -> V_141 ) ;
V_183 . V_187 = F_109 ( V_181 ) ;
F_23 ( V_2 , V_160 -> V_161 . V_162 , V_160 -> V_161 . V_163 ,
F_99 ( V_160 ) , V_160 -> V_164 , V_188 , V_160 -> V_180 ,
sizeof( V_183 ) , & V_183 ) ;
}
static void F_113 ( void * V_155 ,
struct V_80 * V_81 ,
struct V_149 * V_150 , T_10 V_26 ,
T_5 V_181 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
struct V_182 V_183 ;
if ( F_89 ( ! V_2 ) )
return;
V_183 . V_184 = F_112 ( V_26 ) ;
V_183 . V_185 = F_112 ( F_114 ( V_150 -> V_189 ) ) ;
V_183 . V_187 = F_109 ( V_181 ) ;
F_23 ( V_2 , F_115 ( V_150 ) , F_94 ( V_150 ) ,
F_116 ( V_150 ) , 0 , V_188 , 0 ,
sizeof( V_183 ) , & V_183 ) ;
}
void F_117 ( struct V_80 * V_81 ,
struct V_149 * V_150 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
if ( F_89 ( ! V_2 ) )
return;
F_23 ( V_2 , F_91 ( V_150 ) , F_94 ( V_150 ) , 0 , 0 ,
V_190 , 0 , V_6 , V_5 ) ;
}
static void F_67 ( void )
{
int V_111 ;
V_111 = F_118 ( F_93 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_120 ( F_95 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_121 ( F_96 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_122 ( F_97 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_123 ( F_100 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_124 ( F_101 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_125 ( F_102 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_126 ( F_103 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_127 ( F_104 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_128 ( F_105 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_129 ( F_106 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_130 ( F_107 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_131 ( F_108 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_132 ( F_110 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_133 ( F_111 , NULL ) ;
F_119 ( V_111 ) ;
V_111 = F_134 ( F_113 , NULL ) ;
F_119 ( V_111 ) ;
}
static void F_37 ( void )
{
F_135 ( F_113 , NULL ) ;
F_136 ( F_111 , NULL ) ;
F_137 ( F_110 , NULL ) ;
F_138 ( F_108 , NULL ) ;
F_139 ( F_107 , NULL ) ;
F_140 ( F_106 , NULL ) ;
F_141 ( F_105 , NULL ) ;
F_142 ( F_104 , NULL ) ;
F_143 ( F_103 , NULL ) ;
F_144 ( F_102 , NULL ) ;
F_145 ( F_101 , NULL ) ;
F_146 ( F_100 , NULL ) ;
F_147 ( F_97 , NULL ) ;
F_148 ( F_96 , NULL ) ;
F_149 ( F_95 , NULL ) ;
F_150 ( F_93 , NULL ) ;
F_151 () ;
}
static void F_152 ( char * V_191 , const struct V_7 * V_8 )
{
int V_192 = 0 ;
int V_193 = V_8 -> V_4 >> V_54 ;
if ( V_8 -> V_4 == V_51 ) {
V_191 [ V_192 ++ ] = 'N' ;
goto V_194;
}
if ( V_193 & V_75 )
V_191 [ V_192 ++ ] = 'F' ;
if ( V_193 & V_73 )
V_191 [ V_192 ++ ] = 'D' ;
else if ( V_193 & V_195 )
V_191 [ V_192 ++ ] = 'W' ;
else if ( V_8 -> V_57 )
V_191 [ V_192 ++ ] = 'R' ;
else
V_191 [ V_192 ++ ] = 'N' ;
if ( V_193 & V_196 )
V_191 [ V_192 ++ ] = 'F' ;
if ( V_193 & V_197 )
V_191 [ V_192 ++ ] = 'A' ;
if ( V_193 & V_198 )
V_191 [ V_192 ++ ] = 'S' ;
if ( V_193 & V_199 )
V_191 [ V_192 ++ ] = 'M' ;
V_194:
V_191 [ V_192 ] = '\0' ;
}
static inline
const struct V_7 * F_153 ( const struct V_200 * V_201 )
{
return ( const struct V_7 * ) V_201 ;
}
static inline const void * F_154 ( const struct V_200 * V_201 )
{
return F_153 ( V_201 ) + 1 ;
}
static inline T_3 F_155 ( const struct V_200 * V_201 )
{
return F_153 ( V_201 ) -> V_4 ;
}
static inline T_3 F_156 ( const struct V_200 * V_201 )
{
return F_153 ( V_201 ) -> V_57 ;
}
static inline T_3 F_157 ( const struct V_200 * V_201 )
{
return F_153 ( V_201 ) -> V_57 >> 9 ;
}
static inline unsigned long long F_158 ( const struct V_200 * V_201 )
{
return F_153 ( V_201 ) -> V_53 ;
}
static inline T_12 F_159 ( const struct V_200 * V_201 )
{
return F_153 ( V_201 ) -> error ;
}
static T_13 F_160 ( const struct V_200 * V_201 )
{
const T_13 * V_202 = F_154 ( V_201 ) ;
return F_161 ( * V_202 ) ;
}
static void F_162 ( const struct V_200 * V_201 ,
struct V_182 * V_183 )
{
const struct V_182 * V_203 = F_154 ( V_201 ) ;
T_13 V_187 = V_203 -> V_187 ;
V_183 -> V_184 = F_163 ( V_203 -> V_184 ) ;
V_183 -> V_185 = F_163 ( V_203 -> V_185 ) ;
V_183 -> V_187 = F_161 ( V_187 ) ;
}
static void F_164 ( struct V_204 * V_205 , const char * V_206 )
{
char V_191 [ V_207 ] ;
unsigned long long V_208 = V_205 -> V_208 ;
unsigned long V_209 = F_165 ( V_208 , V_210 ) ;
unsigned V_211 = ( unsigned long ) V_208 ;
const struct V_7 * V_8 = F_153 ( V_205 -> V_201 ) ;
F_152 ( V_191 , V_8 ) ;
F_166 ( & V_205 -> V_212 ,
L_6 ,
F_167 ( V_8 -> V_25 ) , F_168 ( V_8 -> V_25 ) , V_205 -> V_14 ,
V_211 , V_209 , V_205 -> V_201 -> V_3 , V_206 , V_191 ) ;
}
static void F_169 ( struct V_204 * V_205 , const char * V_206 )
{
char V_191 [ V_207 ] ;
const struct V_7 * V_8 = F_153 ( V_205 -> V_201 ) ;
F_152 ( V_191 , V_8 ) ;
F_166 ( & V_205 -> V_212 , L_7 ,
F_167 ( V_8 -> V_25 ) , F_168 ( V_8 -> V_25 ) , V_206 , V_191 ) ;
}
static void F_170 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
const unsigned char * V_215 ;
int V_27 ;
int V_192 , V_216 ;
V_215 = F_154 ( V_201 ) ;
V_27 = F_153 ( V_201 ) -> V_27 ;
if ( ! V_27 )
return;
for ( V_216 = V_27 - 1 ; V_216 >= 0 ; V_216 -- )
if ( V_215 [ V_216 ] )
break;
V_216 ++ ;
F_171 ( V_214 , '(' ) ;
for ( V_192 = 0 ; V_192 < V_27 ; V_192 ++ ) {
F_166 ( V_214 , L_8 ,
V_192 == 0 ? L_9 : L_10 , V_215 [ V_192 ] ) ;
if ( V_192 == V_216 && V_216 != V_27 - 1 ) {
F_172 ( V_214 , L_11 ) ;
return;
}
}
F_172 ( V_214 , L_12 ) ;
}
static void F_173 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_135 [ V_217 ] ;
F_174 ( V_201 -> V_3 , V_135 ) ;
if ( F_155 ( V_201 ) & F_26 ( V_152 ) ) {
F_166 ( V_214 , L_13 , F_156 ( V_201 ) ) ;
F_170 ( V_214 , V_201 ) ;
F_166 ( V_214 , L_14 , V_135 ) ;
} else {
if ( F_157 ( V_201 ) )
F_166 ( V_214 , L_15 ,
F_158 ( V_201 ) , F_157 ( V_201 ) , V_135 ) ;
else
F_166 ( V_214 , L_14 , V_135 ) ;
}
}
static void F_175 ( struct V_213 * V_214 ,
const struct V_200 * V_201 )
{
if ( F_155 ( V_201 ) & F_26 ( V_152 ) ) {
F_170 ( V_214 , V_201 ) ;
F_166 ( V_214 , L_16 , F_159 ( V_201 ) ) ;
} else {
if ( F_157 ( V_201 ) )
F_166 ( V_214 , L_17 ,
F_158 ( V_201 ) ,
F_157 ( V_201 ) , F_159 ( V_201 ) ) ;
else
F_166 ( V_214 , L_18 ,
F_158 ( V_201 ) , F_159 ( V_201 ) ) ;
}
}
static void F_176 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
struct V_182 V_183 = { . V_184 = 0 , } ;
F_162 ( V_201 , & V_183 ) ;
F_166 ( V_214 , L_19 ,
F_158 ( V_201 ) , F_157 ( V_201 ) ,
F_167 ( V_183 . V_184 ) , F_168 ( V_183 . V_184 ) ,
( unsigned long long ) V_183 . V_187 ) ;
}
static void F_177 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_135 [ V_217 ] ;
F_174 ( V_201 -> V_3 , V_135 ) ;
F_166 ( V_214 , L_14 , V_135 ) ;
}
static void F_178 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_135 [ V_217 ] ;
F_174 ( V_201 -> V_3 , V_135 ) ;
F_166 ( V_214 , L_20 , V_135 , F_160 ( V_201 ) ) ;
}
static void F_179 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_135 [ V_217 ] ;
F_174 ( V_201 -> V_3 , V_135 ) ;
F_166 ( V_214 , L_21 , F_158 ( V_201 ) ,
F_160 ( V_201 ) , V_135 ) ;
}
static void F_180 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
const struct V_7 * V_8 = F_153 ( V_201 ) ;
F_181 ( V_214 , V_8 + 1 , V_8 -> V_27 ) ;
F_171 ( V_214 , '\n' ) ;
}
static void F_182 ( struct V_218 * V_219 )
{
if ( ! ( V_220 . V_202 & V_221 ) )
return;
F_183 ( V_219 , L_22
L_23 ) ;
}
static void F_184 ( struct V_222 * V_223 )
{
V_16 = true ;
}
static int F_185 ( struct V_222 * V_223 )
{
V_17 = V_223 ;
F_184 ( V_223 ) ;
return 0 ;
}
static void F_186 ( struct V_222 * V_223 )
{
V_16 = false ;
}
static void F_187 ( struct V_222 * V_223 )
{
F_186 ( V_223 ) ;
}
static enum V_224 F_188 ( struct V_204 * V_205 ,
bool V_225 )
{
struct V_222 * V_223 = V_205 -> V_223 ;
struct V_213 * V_214 = & V_205 -> V_212 ;
const struct V_7 * V_8 ;
V_125 V_52 ;
bool V_226 ;
T_14 * V_227 ;
V_8 = F_153 ( V_205 -> V_201 ) ;
V_52 = V_8 -> V_4 & ( ( 1 << V_54 ) - 1 ) ;
V_226 = ! ! ( V_223 -> V_228 & V_229 ) ;
V_227 = V_225 ? & F_164 : & F_169 ;
if ( V_8 -> V_4 == V_51 ) {
V_227 ( V_205 , V_226 ? L_24 : L_25 ) ;
F_180 ( V_214 , V_205 -> V_201 ) ;
return F_189 ( V_214 ) ;
}
if ( F_19 ( V_52 == 0 || V_52 >= F_73 ( V_230 ) ) )
F_166 ( V_214 , L_26 , V_52 ) ;
else {
V_227 ( V_205 , V_230 [ V_52 ] . V_206 [ V_226 ] ) ;
V_230 [ V_52 ] . F_190 ( V_214 , V_205 -> V_201 ) ;
}
return F_189 ( V_214 ) ;
}
static enum V_224 F_191 ( struct V_204 * V_205 ,
int V_30 , struct V_231 * V_10 )
{
return F_188 ( V_205 , false ) ;
}
static void F_192 ( struct V_204 * V_205 )
{
struct V_213 * V_214 = & V_205 -> V_212 ;
struct V_7 * V_8 = (struct V_7 * ) V_205 -> V_201 ;
const int V_232 = F_193 ( struct V_7 , V_53 ) ;
struct V_7 V_233 = {
. V_22 = V_23 | V_24 ,
. time = V_205 -> V_208 ,
} ;
F_181 ( V_214 , & V_233 , V_232 ) ;
F_181 ( V_214 , & V_8 -> V_53 ,
sizeof( V_233 ) - V_232 + V_8 -> V_27 ) ;
}
static enum V_224
F_194 ( struct V_204 * V_205 , int V_30 ,
struct V_231 * V_10 )
{
F_192 ( V_205 ) ;
return F_189 ( & V_205 -> V_212 ) ;
}
static enum V_224 F_195 ( struct V_204 * V_205 )
{
if ( ! ( V_220 . V_202 & V_221 ) )
return V_234 ;
return F_188 ( V_205 , true ) ;
}
static int
F_196 ( struct V_222 * V_223 , T_3 V_235 , T_3 V_236 , int V_237 )
{
if ( V_236 == V_221 ) {
if ( V_237 )
V_223 -> V_228 &= ~ V_238 ;
else
V_223 -> V_228 |= V_238 ;
}
return 0 ;
}
static int T_15 F_197 ( void )
{
if ( ! F_198 ( & V_239 ) ) {
F_199 ( L_27 ) ;
return 1 ;
}
if ( F_200 ( & V_15 ) != 0 ) {
F_199 ( L_28 ) ;
F_201 ( & V_239 ) ;
return 1 ;
}
return 0 ;
}
static int F_202 ( struct V_80 * V_81 )
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
static int F_203 ( struct V_80 * V_81 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = NULL ;
int V_111 = - V_116 ;
V_2 = F_56 ( sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_2 -> V_49 = F_58 ( V_50 , F_59 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_240;
V_2 -> V_26 = V_102 -> V_141 ;
V_2 -> V_47 = ( V_125 ) - 1 ;
F_53 ( V_2 , V_102 ) ;
V_111 = - V_127 ;
if ( F_65 ( & V_81 -> V_1 , NULL , V_2 ) )
goto V_240;
if ( F_66 ( & V_79 ) == 1 )
F_67 () ;
return 0 ;
V_240:
F_30 ( V_2 ) ;
return V_111 ;
}
static int F_204 ( const char * V_241 )
{
int V_192 ;
int V_242 = 0 ;
char * V_44 , * V_214 , * V_243 ;
V_44 = F_205 ( V_241 , V_115 ) ;
if ( V_44 == NULL )
return - V_116 ;
V_214 = F_206 ( V_44 ) ;
while ( 1 ) {
V_243 = F_207 ( & V_214 , L_29 ) ;
if ( V_243 == NULL )
break;
if ( * V_243 == '\0' )
continue;
for ( V_192 = 0 ; V_192 < F_73 ( V_244 ) ; V_192 ++ ) {
if ( strcasecmp ( V_243 , V_244 [ V_192 ] . V_241 ) == 0 ) {
V_242 |= V_244 [ V_192 ] . V_242 ;
break;
}
}
if ( V_192 == F_73 ( V_244 ) ) {
V_242 = - V_82 ;
break;
}
}
F_34 ( V_44 ) ;
return V_242 ;
}
static T_6 F_208 ( char * V_44 , int V_242 )
{
int V_192 ;
char * V_245 = V_44 ;
for ( V_192 = 0 ; V_192 < F_73 ( V_244 ) ; V_192 ++ ) {
if ( V_242 & V_244 [ V_192 ] . V_242 ) {
V_245 += sprintf ( V_245 , L_30 ,
( V_245 == V_44 ) ? L_9 : L_29 , V_244 [ V_192 ] . V_241 ) ;
}
}
* V_245 ++ = '\n' ;
return V_245 - V_44 ;
}
static struct V_80 * F_209 ( struct V_101 * V_102 )
{
if ( V_102 -> V_246 == NULL )
return NULL ;
return F_82 ( V_102 ) ;
}
static T_6 F_210 ( struct V_25 * V_26 ,
struct V_247 * V_248 ,
char * V_44 )
{
struct V_103 * V_245 = F_211 ( V_26 ) ;
struct V_80 * V_81 ;
struct V_101 * V_102 ;
T_6 V_111 = - V_138 ;
V_102 = F_212 ( F_213 ( V_245 ) ) ;
if ( V_102 == NULL )
goto V_194;
V_81 = F_209 ( V_102 ) ;
if ( V_81 == NULL )
goto V_249;
F_83 ( & V_102 -> V_139 ) ;
if ( V_248 == & V_250 ) {
V_111 = sprintf ( V_44 , L_1 , ! ! V_81 -> V_1 ) ;
goto V_251;
}
if ( V_81 -> V_1 == NULL )
V_111 = sprintf ( V_44 , L_31 ) ;
else if ( V_248 == & V_252 )
V_111 = F_208 ( V_44 , V_81 -> V_1 -> V_47 ) ;
else if ( V_248 == & V_253 )
V_111 = sprintf ( V_44 , L_1 , V_81 -> V_1 -> V_3 ) ;
else if ( V_248 == & V_254 )
V_111 = sprintf ( V_44 , L_32 , V_81 -> V_1 -> V_55 ) ;
else if ( V_248 == & V_255 )
V_111 = sprintf ( V_44 , L_32 , V_81 -> V_1 -> V_56 ) ;
V_251:
F_86 ( & V_102 -> V_139 ) ;
V_249:
F_214 ( V_102 ) ;
V_194:
return V_111 ;
}
static T_6 F_215 ( struct V_25 * V_26 ,
struct V_247 * V_248 ,
const char * V_44 , T_2 V_85 )
{
struct V_101 * V_102 ;
struct V_80 * V_81 ;
struct V_103 * V_245 ;
T_16 V_256 ;
T_6 V_111 = - V_82 ;
if ( V_85 == 0 )
goto V_194;
if ( V_248 == & V_252 ) {
if ( F_216 ( V_44 , 0 , & V_256 ) ) {
V_111 = F_204 ( V_44 ) ;
if ( V_111 < 0 )
goto V_194;
V_256 = V_111 ;
}
} else if ( F_216 ( V_44 , 0 , & V_256 ) )
goto V_194;
V_111 = - V_138 ;
V_245 = F_211 ( V_26 ) ;
V_102 = F_212 ( F_213 ( V_245 ) ) ;
if ( V_102 == NULL )
goto V_194;
V_81 = F_209 ( V_102 ) ;
if ( V_81 == NULL )
goto V_249;
F_83 ( & V_102 -> V_139 ) ;
if ( V_248 == & V_250 ) {
if ( V_256 )
V_111 = F_203 ( V_81 , V_102 ) ;
else
V_111 = F_202 ( V_81 ) ;
goto V_251;
}
V_111 = 0 ;
if ( V_81 -> V_1 == NULL )
V_111 = F_203 ( V_81 , V_102 ) ;
if ( V_111 == 0 ) {
if ( V_248 == & V_252 )
V_81 -> V_1 -> V_47 = V_256 ;
else if ( V_248 == & V_253 )
V_81 -> V_1 -> V_3 = V_256 ;
else if ( V_248 == & V_254 )
V_81 -> V_1 -> V_55 = V_256 ;
else if ( V_248 == & V_255 )
V_81 -> V_1 -> V_56 = V_256 ;
}
V_251:
F_86 ( & V_102 -> V_139 ) ;
V_249:
F_214 ( V_102 ) ;
V_194:
return V_111 ? V_111 : V_85 ;
}
int F_217 ( struct V_25 * V_26 )
{
return F_218 ( & V_26 -> V_257 , & V_258 ) ;
}
void F_219 ( struct V_25 * V_26 )
{
F_220 ( & V_26 -> V_257 , & V_258 ) ;
}
void F_221 ( char * V_191 , unsigned int V_58 , int V_57 )
{
int V_192 = 0 ;
if ( V_58 & V_259 )
V_191 [ V_192 ++ ] = 'F' ;
switch ( V_58 & V_260 ) {
case V_261 :
case V_262 :
V_191 [ V_192 ++ ] = 'W' ;
break;
case V_71 :
V_191 [ V_192 ++ ] = 'D' ;
break;
case V_72 :
V_191 [ V_192 ++ ] = 'D' ;
V_191 [ V_192 ++ ] = 'E' ;
break;
case V_74 :
V_191 [ V_192 ++ ] = 'F' ;
break;
case V_263 :
V_191 [ V_192 ++ ] = 'R' ;
break;
default:
V_191 [ V_192 ++ ] = 'N' ;
}
if ( V_58 & V_264 )
V_191 [ V_192 ++ ] = 'F' ;
if ( V_58 & V_265 )
V_191 [ V_192 ++ ] = 'A' ;
if ( V_58 & V_266 )
V_191 [ V_192 ++ ] = 'S' ;
if ( V_58 & V_267 )
V_191 [ V_192 ++ ] = 'M' ;
V_191 [ V_192 ] = '\0' ;
}
