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
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
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
V_38 [ 0 ] = V_37 . V_39 ;
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
int V_58 , T_3 V_52 , int error , int V_27 , void * V_59 )
{
struct V_28 * V_29 = V_60 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_30 = 0 ;
unsigned long * V_61 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_19 ( V_2 -> V_45 != V_46 && ! V_15 ) )
return;
V_52 |= V_62 [ V_58 & V_63 ] ;
V_52 |= F_24 ( V_58 , V_64 ) ;
V_52 |= F_24 ( V_58 , V_65 ) ;
V_52 |= F_24 ( V_58 , V_66 ) ;
V_52 |= F_24 ( V_58 , V_67 ) ;
V_52 |= F_24 ( V_58 , V_68 ) ;
V_52 |= F_24 ( V_58 , V_69 ) ;
V_3 = V_29 -> V_3 ;
if ( F_22 ( V_2 , V_52 , V_53 , V_3 ) )
return;
V_14 = F_25 () ;
if ( V_15 ) {
F_26 ( V_60 ) ;
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
V_61 = F_27 ( V_2 -> V_61 , V_14 ) ;
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> V_61 = ++ ( * V_61 ) ;
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
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_59 , V_27 ) ;
if ( V_15 ) {
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_17 ( V_30 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_70 ) ;
F_29 ( V_2 -> V_71 ) ;
F_30 ( V_2 -> V_21 ) ;
F_29 ( V_2 -> V_72 ) ;
F_31 ( V_2 -> V_61 ) ;
F_31 ( V_2 -> V_49 ) ;
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
if ( F_34 ( & V_73 ) )
F_35 () ;
}
int F_36 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_75 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_76 ;
if ( V_2 -> V_45 != V_46 )
F_33 ( V_2 ) ;
return 0 ;
}
static T_6 F_38 ( struct V_77 * V_78 , char T_7 * V_12 ,
T_2 V_79 , T_8 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
char V_44 [ 16 ] ;
snprintf ( V_44 , sizeof( V_44 ) , L_1 , F_39 ( & V_2 -> V_82 ) ) ;
return F_40 ( V_12 , V_79 , V_80 , V_44 , strlen ( V_44 ) ) ;
}
static T_6 F_41 ( struct V_77 * V_78 , const char T_7 * V_12 ,
T_2 V_79 , T_8 * V_80 )
{
char * V_83 ;
struct V_1 * V_2 ;
if ( V_79 >= V_50 )
return - V_76 ;
V_83 = F_42 ( V_79 + 1 , V_84 ) ;
if ( V_83 == NULL )
return - V_85 ;
if ( F_43 ( V_83 , V_12 , V_79 ) ) {
F_32 ( V_83 ) ;
return - V_86 ;
}
V_83 [ V_79 ] = '\0' ;
V_2 = V_78 -> V_81 ;
F_18 ( V_2 , L_2 , V_83 ) ;
F_32 ( V_83 ) ;
return V_79 ;
}
static int F_44 ( struct V_87 * V_44 , void * V_88 ,
void * V_89 , T_2 V_90 )
{
struct V_1 * V_2 ;
if ( ! F_45 ( V_44 ) )
return 1 ;
V_2 = V_44 -> V_91 -> V_81 ;
F_46 ( & V_2 -> V_82 ) ;
return 0 ;
}
static int F_47 ( struct V_92 * V_92 )
{
F_29 ( V_92 ) ;
return 0 ;
}
static struct V_92 * F_48 ( const char * V_93 ,
struct V_92 * V_94 ,
T_9 V_95 ,
struct V_87 * V_44 ,
int * V_96 )
{
return F_49 ( V_93 , V_95 , V_94 , V_44 ,
& V_97 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = NULL ;
if ( V_99 )
V_101 = V_99 -> V_102 ;
if ( V_101 ) {
V_2 -> V_55 = V_101 -> V_103 ;
V_2 -> V_56 = V_101 -> V_103 + V_101 -> V_104 ;
} else {
V_2 -> V_55 = 0 ;
V_2 -> V_56 = - 1ULL ;
}
}
int F_51 ( struct V_74 * V_75 , char * V_105 , T_10 V_26 ,
struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_108 , * V_2 = NULL ;
struct V_92 * V_72 = NULL ;
int V_109 , V_110 ;
if ( ! V_107 -> V_111 || ! V_107 -> V_112 )
return - V_76 ;
strncpy ( V_107 -> V_105 , V_105 , V_113 ) ;
V_107 -> V_105 [ V_113 - 1 ] = '\0' ;
for ( V_110 = 0 ; V_110 < strlen ( V_107 -> V_105 ) ; V_110 ++ )
if ( V_107 -> V_105 [ V_110 ] == '/' )
V_107 -> V_105 [ V_110 ] = '_' ;
V_2 = F_52 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_109 = - V_85 ;
V_2 -> V_61 = F_53 (unsigned long) ;
if ( ! V_2 -> V_61 )
goto V_114;
V_2 -> V_49 = F_54 ( V_50 , F_55 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_114;
V_109 = - V_115 ;
F_56 ( & V_116 ) ;
if ( ! V_117 ) {
V_117 = F_57 ( L_3 , NULL ) ;
if ( ! V_117 ) {
F_58 ( & V_116 ) ;
goto V_114;
}
}
F_58 ( & V_116 ) ;
V_72 = F_57 ( V_107 -> V_105 , V_117 ) ;
if ( ! V_72 )
goto V_114;
V_2 -> V_72 = V_72 ;
V_2 -> V_26 = V_26 ;
F_59 ( & V_2 -> V_82 , 0 ) ;
F_60 ( & V_2 -> V_118 ) ;
V_109 = - V_119 ;
V_2 -> V_71 = F_49 ( L_4 , 0444 , V_72 , V_2 ,
& V_120 ) ;
if ( ! V_2 -> V_71 )
goto V_114;
V_2 -> V_70 = F_49 ( L_5 , 0222 , V_72 , V_2 , & V_121 ) ;
if ( ! V_2 -> V_70 )
goto V_114;
V_2 -> V_21 = F_61 ( L_6 , V_72 , V_107 -> V_111 ,
V_107 -> V_112 , & V_122 , V_2 ) ;
if ( ! V_2 -> V_21 )
goto V_114;
V_2 -> V_47 = V_107 -> V_47 ;
if ( ! V_2 -> V_47 )
V_2 -> V_47 = ( V_123 ) - 1 ;
F_50 ( V_2 , V_99 ) ;
if ( V_107 -> V_55 )
V_2 -> V_55 = V_107 -> V_55 ;
if ( V_107 -> V_56 )
V_2 -> V_56 = V_107 -> V_56 ;
V_2 -> V_3 = V_107 -> V_3 ;
V_2 -> V_45 = V_124 ;
V_109 = - V_125 ;
V_108 = F_37 ( & V_75 -> V_1 , V_2 ) ;
if ( V_108 ) {
( void ) F_37 ( & V_75 -> V_1 , V_108 ) ;
goto V_114;
}
if ( F_62 ( & V_73 ) == 1 )
F_63 () ;
return 0 ;
V_114:
F_28 ( V_2 ) ;
return V_109 ;
}
int F_64 ( struct V_74 * V_75 , char * V_105 , T_10 V_26 ,
struct V_98 * V_99 ,
char T_7 * V_126 )
{
struct V_106 V_107 ;
int V_109 ;
V_109 = F_43 ( & V_107 , V_126 , sizeof( V_107 ) ) ;
if ( V_109 )
return - V_86 ;
V_109 = F_51 ( V_75 , V_105 , V_26 , V_99 , & V_107 ) ;
if ( V_109 )
return V_109 ;
if ( F_65 ( V_126 , & V_107 , sizeof( V_107 ) ) ) {
F_36 ( V_75 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_66 ( struct V_74 * V_75 , char * V_105 ,
T_10 V_26 , struct V_98 * V_99 ,
char T_7 * V_126 )
{
struct V_106 V_107 ;
struct V_127 V_128 ;
int V_109 ;
if ( F_43 ( & V_128 , V_126 , sizeof( V_128 ) ) )
return - V_86 ;
V_107 = (struct V_106 ) {
. V_47 = V_128 . V_47 ,
. V_111 = V_128 . V_111 ,
. V_112 = V_128 . V_112 ,
. V_55 = V_128 . V_55 ,
. V_56 = V_128 . V_56 ,
. V_3 = V_128 . V_3 ,
} ;
V_109 = F_51 ( V_75 , V_105 , V_26 , V_99 , & V_107 ) ;
if ( V_109 )
return V_109 ;
if ( F_65 ( V_126 , & V_107 . V_105 , F_67 ( V_107 . V_105 ) ) ) {
F_36 ( V_75 ) ;
return - V_86 ;
}
return 0 ;
}
int F_68 ( struct V_74 * V_75 , int V_129 )
{
int V_109 ;
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 == NULL )
return - V_76 ;
V_109 = - V_76 ;
if ( V_129 ) {
if ( V_2 -> V_45 == V_124 ||
V_2 -> V_45 == V_130 ) {
V_32 ++ ;
F_69 () ;
V_2 -> V_45 = V_46 ;
F_70 ( & V_33 ) ;
F_71 ( & V_2 -> V_118 , & V_131 ) ;
F_72 ( & V_33 ) ;
F_14 ( V_2 ) ;
V_109 = 0 ;
}
} else {
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_130 ;
F_70 ( & V_33 ) ;
F_73 ( & V_2 -> V_118 ) ;
F_72 ( & V_33 ) ;
F_74 ( V_2 -> V_21 ) ;
V_109 = 0 ;
}
}
return V_109 ;
}
int F_75 ( struct V_98 * V_99 , unsigned V_132 , char T_7 * V_126 )
{
struct V_74 * V_75 ;
int V_109 , V_129 = 0 ;
char V_133 [ V_134 ] ;
V_75 = F_76 ( V_99 ) ;
if ( ! V_75 )
return - V_135 ;
F_56 ( & V_99 -> V_136 ) ;
switch ( V_132 ) {
case V_137 :
F_77 ( V_99 , V_133 ) ;
V_109 = F_64 ( V_75 , V_133 , V_99 -> V_138 , V_99 , V_126 ) ;
break;
#if F_78 ( V_139 ) && F_78 ( V_140 )
case V_141 :
F_77 ( V_99 , V_133 ) ;
V_109 = F_66 ( V_75 , V_133 , V_99 -> V_138 , V_99 , V_126 ) ;
break;
#endif
case V_142 :
V_129 = 1 ;
case V_143 :
V_109 = F_68 ( V_75 , V_129 ) ;
break;
case V_144 :
V_109 = F_36 ( V_75 ) ;
break;
default:
V_109 = - V_145 ;
break;
}
F_58 ( & V_99 -> V_136 ) ;
return V_109 ;
}
void F_79 ( struct V_74 * V_75 )
{
if ( V_75 -> V_1 ) {
F_68 ( V_75 , 0 ) ;
F_36 ( V_75 ) ;
}
}
static void F_80 ( struct V_74 * V_75 , struct V_146 * V_147 ,
unsigned int V_148 , T_3 V_52 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return;
if ( V_147 -> V_149 == V_150 ) {
V_52 |= F_82 ( V_151 ) ;
F_23 ( V_2 , 0 , V_148 , V_147 -> V_152 ,
V_52 , V_147 -> V_153 , V_147 -> V_154 , V_147 -> V_132 ) ;
} else {
V_52 |= F_82 ( V_155 ) ;
F_23 ( V_2 , F_83 ( V_147 ) , V_148 ,
V_147 -> V_152 , V_52 , V_147 -> V_153 , 0 , NULL ) ;
}
}
static void F_84 ( void * V_156 ,
struct V_74 * V_75 , struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , F_85 ( V_147 ) , V_157 ) ;
}
static void F_86 ( void * V_156 ,
struct V_74 * V_75 , struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , F_85 ( V_147 ) , V_158 ) ;
}
static void F_87 ( void * V_156 ,
struct V_74 * V_75 , struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , F_85 ( V_147 ) , V_159 ) ;
}
static void F_88 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , F_85 ( V_147 ) , V_160 ) ;
}
static void F_89 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_146 * V_147 ,
unsigned int V_148 )
{
F_80 ( V_75 , V_147 , V_148 , V_161 ) ;
}
static void F_90 ( struct V_74 * V_75 , struct V_162 * V_162 ,
T_3 V_52 , int error )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return;
if ( ! error && ! F_91 ( V_162 , V_163 ) )
error = V_119 ;
F_23 ( V_2 , V_162 -> V_164 . V_165 , V_162 -> V_164 . V_166 ,
V_162 -> V_167 , V_52 , error , 0 , NULL ) ;
}
static void F_92 ( void * V_156 ,
struct V_74 * V_75 , struct V_162 * V_162 )
{
F_90 ( V_75 , V_162 , V_168 , 0 ) ;
}
static void F_93 ( void * V_156 ,
struct V_74 * V_75 , struct V_162 * V_162 ,
int error )
{
F_90 ( V_75 , V_162 , V_161 , error ) ;
}
static void F_94 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_146 * V_147 ,
struct V_162 * V_162 )
{
F_90 ( V_75 , V_162 , V_169 , 0 ) ;
}
static void F_95 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_146 * V_147 ,
struct V_162 * V_162 )
{
F_90 ( V_75 , V_162 , V_170 , 0 ) ;
}
static void F_96 ( void * V_156 ,
struct V_74 * V_75 , struct V_162 * V_162 )
{
F_90 ( V_75 , V_162 , V_171 , 0 ) ;
}
static void F_97 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_162 * V_162 , int V_58 )
{
if ( V_162 )
F_90 ( V_75 , V_162 , V_172 , 0 ) ;
else {
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_58 , V_172 , 0 , 0 , NULL ) ;
}
}
static void F_98 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_162 * V_162 , int V_58 )
{
if ( V_162 )
F_90 ( V_75 , V_162 , V_173 , 0 ) ;
else {
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_58 , V_173 ,
0 , 0 , NULL ) ;
}
}
static void F_99 ( void * V_156 , struct V_74 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , 0 , V_174 , 0 , 0 , NULL ) ;
}
static void F_100 ( void * V_156 , struct V_74 * V_75 ,
unsigned int V_175 , bool V_176 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 ) {
T_11 V_177 = F_101 ( V_175 ) ;
T_3 V_52 ;
if ( V_176 )
V_52 = V_178 ;
else
V_52 = V_179 ;
F_23 ( V_2 , 0 , 0 , 0 , V_52 , 0 , sizeof( V_177 ) , & V_177 ) ;
}
}
static void F_102 ( void * V_156 ,
struct V_74 * V_75 , struct V_162 * V_162 ,
unsigned int V_180 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 ) {
T_11 V_177 = F_101 ( V_180 ) ;
F_23 ( V_2 , V_162 -> V_164 . V_165 ,
V_162 -> V_164 . V_166 , V_162 -> V_167 , V_181 ,
! F_91 ( V_162 , V_163 ) ,
sizeof( V_177 ) , & V_177 ) ;
}
}
static void F_103 ( void * V_156 ,
struct V_74 * V_75 , struct V_162 * V_162 ,
T_10 V_26 , T_5 V_182 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
struct V_183 V_184 ;
if ( F_81 ( ! V_2 ) )
return;
V_184 . V_185 = F_104 ( V_26 ) ;
V_184 . V_186 = F_104 ( V_162 -> V_187 -> V_138 ) ;
V_184 . V_188 = F_101 ( V_182 ) ;
F_23 ( V_2 , V_162 -> V_164 . V_165 , V_162 -> V_164 . V_166 ,
V_162 -> V_167 , V_189 ,
! F_91 ( V_162 , V_163 ) , sizeof( V_184 ) , & V_184 ) ;
}
static void F_105 ( void * V_156 ,
struct V_74 * V_75 ,
struct V_146 * V_147 , T_10 V_26 ,
T_5 V_182 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
struct V_183 V_184 ;
if ( F_81 ( ! V_2 ) )
return;
V_184 . V_185 = F_104 ( V_26 ) ;
V_184 . V_186 = F_104 ( F_106 ( V_147 -> V_190 ) ) ;
V_184 . V_188 = F_101 ( V_182 ) ;
F_23 ( V_2 , F_83 ( V_147 ) , F_85 ( V_147 ) ,
F_107 ( V_147 ) , V_189 , ! ! V_147 -> V_153 ,
sizeof( V_184 ) , & V_184 ) ;
}
void F_108 ( struct V_74 * V_75 ,
struct V_146 * V_147 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return;
if ( V_147 -> V_149 == V_150 )
F_23 ( V_2 , 0 , F_85 ( V_147 ) , 0 ,
V_191 , V_147 -> V_153 , V_6 , V_5 ) ;
else
F_23 ( V_2 , F_83 ( V_147 ) , F_85 ( V_147 ) , 0 ,
V_191 , V_147 -> V_153 , V_6 , V_5 ) ;
}
static void F_63 ( void )
{
int V_109 ;
V_109 = F_109 ( F_84 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_111 ( F_86 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_112 ( F_87 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_113 ( F_88 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_114 ( F_89 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_115 ( F_92 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_116 ( F_93 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_117 ( F_94 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_118 ( F_95 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_119 ( F_96 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_120 ( F_97 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_121 ( F_98 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_122 ( F_99 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_123 ( F_100 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_124 ( F_102 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_125 ( F_103 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_126 ( F_105 , NULL ) ;
F_110 ( V_109 ) ;
}
static void F_35 ( void )
{
F_127 ( F_105 , NULL ) ;
F_128 ( F_103 , NULL ) ;
F_129 ( F_102 , NULL ) ;
F_130 ( F_100 , NULL ) ;
F_131 ( F_99 , NULL ) ;
F_132 ( F_98 , NULL ) ;
F_133 ( F_97 , NULL ) ;
F_134 ( F_96 , NULL ) ;
F_135 ( F_95 , NULL ) ;
F_136 ( F_94 , NULL ) ;
F_137 ( F_93 , NULL ) ;
F_138 ( F_92 , NULL ) ;
F_139 ( F_89 , NULL ) ;
F_140 ( F_88 , NULL ) ;
F_141 ( F_87 , NULL ) ;
F_142 ( F_86 , NULL ) ;
F_143 ( F_84 , NULL ) ;
F_144 () ;
}
static void F_145 ( char * V_192 , const struct V_7 * V_8 )
{
int V_110 = 0 ;
int V_193 = V_8 -> V_4 >> V_54 ;
if ( V_8 -> V_4 == V_51 ) {
V_192 [ V_110 ++ ] = 'N' ;
goto V_194;
}
if ( V_193 & V_195 )
V_192 [ V_110 ++ ] = 'F' ;
if ( V_193 & V_196 )
V_192 [ V_110 ++ ] = 'D' ;
else if ( V_193 & V_197 )
V_192 [ V_110 ++ ] = 'W' ;
else if ( V_8 -> V_57 )
V_192 [ V_110 ++ ] = 'R' ;
else
V_192 [ V_110 ++ ] = 'N' ;
if ( V_193 & V_198 )
V_192 [ V_110 ++ ] = 'F' ;
if ( V_193 & V_199 )
V_192 [ V_110 ++ ] = 'A' ;
if ( V_193 & V_200 )
V_192 [ V_110 ++ ] = 'S' ;
if ( V_193 & V_201 )
V_192 [ V_110 ++ ] = 'M' ;
V_194:
V_192 [ V_110 ] = '\0' ;
}
static inline
const struct V_7 * F_146 ( const struct V_202 * V_203 )
{
return ( const struct V_7 * ) V_203 ;
}
static inline const void * F_147 ( const struct V_202 * V_203 )
{
return F_146 ( V_203 ) + 1 ;
}
static inline T_3 F_148 ( const struct V_202 * V_203 )
{
return F_146 ( V_203 ) -> V_4 ;
}
static inline T_3 F_149 ( const struct V_202 * V_203 )
{
return F_146 ( V_203 ) -> V_57 ;
}
static inline T_3 F_150 ( const struct V_202 * V_203 )
{
return F_146 ( V_203 ) -> V_57 >> 9 ;
}
static inline unsigned long long F_151 ( const struct V_202 * V_203 )
{
return F_146 ( V_203 ) -> V_53 ;
}
static inline T_12 F_152 ( const struct V_202 * V_203 )
{
return F_146 ( V_203 ) -> error ;
}
static T_13 F_153 ( const struct V_202 * V_203 )
{
const T_13 * V_204 = F_147 ( V_203 ) ;
return F_154 ( * V_204 ) ;
}
static void F_155 ( const struct V_202 * V_203 ,
struct V_183 * V_184 )
{
const struct V_183 * V_205 = F_147 ( V_203 ) ;
T_13 V_188 = V_205 -> V_188 ;
V_184 -> V_185 = F_156 ( V_205 -> V_185 ) ;
V_184 -> V_186 = F_156 ( V_205 -> V_186 ) ;
V_184 -> V_188 = F_154 ( V_188 ) ;
}
static int F_157 ( struct V_206 * V_207 , const char * V_208 )
{
char V_192 [ V_209 ] ;
unsigned long long V_210 = V_207 -> V_210 ;
unsigned long V_211 = F_158 ( V_210 , V_212 ) ;
unsigned V_213 = ( unsigned long ) V_210 ;
const struct V_7 * V_8 = F_146 ( V_207 -> V_203 ) ;
F_145 ( V_192 , V_8 ) ;
return F_159 ( & V_207 -> V_214 ,
L_7 ,
F_160 ( V_8 -> V_25 ) , F_161 ( V_8 -> V_25 ) , V_207 -> V_14 ,
V_213 , V_211 , V_207 -> V_203 -> V_3 , V_208 , V_192 ) ;
}
static int F_162 ( struct V_206 * V_207 , const char * V_208 )
{
char V_192 [ V_209 ] ;
const struct V_7 * V_8 = F_146 ( V_207 -> V_203 ) ;
F_145 ( V_192 , V_8 ) ;
return F_159 ( & V_207 -> V_214 , L_8 ,
F_160 ( V_8 -> V_25 ) , F_161 ( V_8 -> V_25 ) , V_208 , V_192 ) ;
}
static int F_163 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
const unsigned char * V_217 ;
int V_27 ;
int V_110 , V_218 , V_109 ;
V_217 = F_147 ( V_203 ) ;
V_27 = F_146 ( V_203 ) -> V_27 ;
if ( ! V_27 )
return 1 ;
for ( V_218 = V_27 - 1 ; V_218 >= 0 ; V_218 -- )
if ( V_217 [ V_218 ] )
break;
V_218 ++ ;
if ( ! F_164 ( V_216 , '(' ) )
return 0 ;
for ( V_110 = 0 ; V_110 < V_27 ; V_110 ++ ) {
V_109 = F_159 ( V_216 , L_9 ,
V_110 == 0 ? L_10 : L_11 , V_217 [ V_110 ] ) ;
if ( ! V_109 )
return V_109 ;
if ( V_110 == V_218 && V_218 != V_27 - 1 )
return F_165 ( V_216 , L_12 ) ;
}
return F_165 ( V_216 , L_13 ) ;
}
static int F_166 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
char V_132 [ V_219 ] ;
F_167 ( V_203 -> V_3 , V_132 ) ;
if ( F_148 ( V_203 ) & F_82 ( V_151 ) ) {
int V_109 ;
V_109 = F_159 ( V_216 , L_14 , F_149 ( V_203 ) ) ;
if ( ! V_109 )
return 0 ;
V_109 = F_163 ( V_216 , V_203 ) ;
if ( ! V_109 )
return 0 ;
return F_159 ( V_216 , L_15 , V_132 ) ;
} else {
if ( F_150 ( V_203 ) )
return F_159 ( V_216 , L_16 ,
F_151 ( V_203 ) , F_150 ( V_203 ) , V_132 ) ;
return F_159 ( V_216 , L_15 , V_132 ) ;
}
}
static int F_168 ( struct V_215 * V_216 ,
const struct V_202 * V_203 )
{
if ( F_148 ( V_203 ) & F_82 ( V_151 ) ) {
int V_109 ;
V_109 = F_163 ( V_216 , V_203 ) ;
if ( V_109 )
return F_159 ( V_216 , L_17 , F_152 ( V_203 ) ) ;
return 0 ;
} else {
if ( F_150 ( V_203 ) )
return F_159 ( V_216 , L_18 ,
F_151 ( V_203 ) ,
F_150 ( V_203 ) , F_152 ( V_203 ) ) ;
return F_159 ( V_216 , L_19 ,
F_151 ( V_203 ) , F_152 ( V_203 ) ) ;
}
}
static int F_169 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
struct V_183 V_184 = { . V_185 = 0 , } ;
F_155 ( V_203 , & V_184 ) ;
return F_159 ( V_216 , L_20 ,
F_151 ( V_203 ) , F_150 ( V_203 ) ,
F_160 ( V_184 . V_185 ) , F_161 ( V_184 . V_185 ) ,
( unsigned long long ) V_184 . V_188 ) ;
}
static int F_170 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
char V_132 [ V_219 ] ;
F_167 ( V_203 -> V_3 , V_132 ) ;
return F_159 ( V_216 , L_15 , V_132 ) ;
}
static int F_171 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
char V_132 [ V_219 ] ;
F_167 ( V_203 -> V_3 , V_132 ) ;
return F_159 ( V_216 , L_21 , V_132 , F_153 ( V_203 ) ) ;
}
static int F_172 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
char V_132 [ V_219 ] ;
F_167 ( V_203 -> V_3 , V_132 ) ;
return F_159 ( V_216 , L_22 , F_151 ( V_203 ) ,
F_153 ( V_203 ) , V_132 ) ;
}
static int F_173 ( struct V_215 * V_216 , const struct V_202 * V_203 )
{
int V_109 ;
const struct V_7 * V_8 = F_146 ( V_203 ) ;
V_109 = F_174 ( V_216 , V_8 + 1 , V_8 -> V_27 ) ;
if ( V_109 )
return F_164 ( V_216 , '\n' ) ;
return V_109 ;
}
static void F_175 ( struct V_220 * V_221 )
{
if ( ! ( V_222 . V_204 & V_223 ) )
return;
F_176 ( V_221 , L_23
L_24 ) ;
}
static void F_177 ( struct V_224 * V_225 )
{
V_16 = true ;
}
static int F_178 ( struct V_224 * V_225 )
{
V_17 = V_225 ;
F_177 ( V_225 ) ;
return 0 ;
}
static void F_179 ( struct V_224 * V_225 )
{
V_16 = false ;
}
static void F_180 ( struct V_224 * V_225 )
{
F_179 ( V_225 ) ;
}
static enum V_226 F_181 ( struct V_206 * V_207 ,
bool V_227 )
{
struct V_215 * V_216 = & V_207 -> V_214 ;
const struct V_7 * V_8 ;
V_123 V_52 ;
int V_109 ;
bool V_228 ;
T_14 * V_229 ;
V_8 = F_146 ( V_207 -> V_203 ) ;
V_52 = V_8 -> V_4 & ( ( 1 << V_54 ) - 1 ) ;
V_228 = ! ! ( V_230 & V_231 ) ;
V_229 = V_227 ? & F_157 : & F_162 ;
if ( V_8 -> V_4 == V_51 ) {
V_109 = V_229 ( V_207 , V_228 ? L_25 : L_26 ) ;
if ( V_109 )
V_109 = F_173 ( V_216 , V_207 -> V_203 ) ;
goto V_194;
}
if ( F_19 ( V_52 == 0 || V_52 >= F_67 ( V_232 ) ) )
V_109 = F_159 ( V_216 , L_27 , V_52 ) ;
else {
V_109 = V_229 ( V_207 , V_232 [ V_52 ] . V_208 [ V_228 ] ) ;
if ( V_109 )
V_109 = V_232 [ V_52 ] . F_182 ( V_216 , V_207 -> V_203 ) ;
}
V_194:
return V_109 ? V_233 : V_234 ;
}
static enum V_226 F_183 ( struct V_206 * V_207 ,
int V_30 , struct V_235 * V_10 )
{
return F_181 ( V_207 , false ) ;
}
static int F_184 ( struct V_206 * V_207 )
{
struct V_215 * V_216 = & V_207 -> V_214 ;
struct V_7 * V_8 = (struct V_7 * ) V_207 -> V_203 ;
const int V_236 = F_185 ( struct V_7 , V_53 ) ;
struct V_7 V_237 = {
. V_22 = V_23 | V_24 ,
. time = V_207 -> V_210 ,
} ;
if ( ! F_174 ( V_216 , & V_237 , V_236 ) )
return 0 ;
return F_174 ( V_216 , & V_8 -> V_53 ,
sizeof( V_237 ) - V_236 + V_8 -> V_27 ) ;
}
static enum V_226
F_186 ( struct V_206 * V_207 , int V_30 ,
struct V_235 * V_10 )
{
return F_184 ( V_207 ) ?
V_233 : V_234 ;
}
static enum V_226 F_187 ( struct V_206 * V_207 )
{
if ( ! ( V_222 . V_204 & V_223 ) )
return V_238 ;
return F_181 ( V_207 , true ) ;
}
static int
F_188 ( struct V_224 * V_225 , T_3 V_239 , T_3 V_240 , int V_241 )
{
if ( V_240 == V_223 ) {
if ( V_241 )
V_230 &= ~ V_242 ;
else
V_230 |= V_242 ;
}
return 0 ;
}
static int T_15 F_189 ( void )
{
if ( ! F_190 ( & V_243 ) ) {
F_191 ( L_28 ) ;
return 1 ;
}
if ( F_192 ( & V_15 ) != 0 ) {
F_191 ( L_29 ) ;
F_193 ( & V_243 ) ;
return 1 ;
}
return 0 ;
}
static int F_194 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_75 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_76 ;
if ( F_34 ( & V_73 ) )
F_35 () ;
F_70 ( & V_33 ) ;
F_195 ( & V_2 -> V_118 ) ;
F_72 ( & V_33 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_196 ( struct V_74 * V_75 ,
struct V_98 * V_99 )
{
struct V_1 * V_108 , * V_2 = NULL ;
int V_109 = - V_85 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_49 = F_54 ( V_50 , F_55 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_244;
V_2 -> V_26 = V_99 -> V_138 ;
V_2 -> V_47 = ( V_123 ) - 1 ;
F_50 ( V_2 , V_99 ) ;
V_108 = F_37 ( & V_75 -> V_1 , V_2 ) ;
if ( V_108 != NULL ) {
( void ) F_37 ( & V_75 -> V_1 , V_108 ) ;
V_109 = - V_125 ;
goto V_244;
}
if ( F_62 ( & V_73 ) == 1 )
F_63 () ;
return 0 ;
V_244:
F_28 ( V_2 ) ;
return V_109 ;
}
static int F_197 ( const char * V_245 )
{
int V_110 ;
int V_246 = 0 ;
char * V_44 , * V_216 , * V_247 ;
V_44 = F_198 ( V_245 , V_84 ) ;
if ( V_44 == NULL )
return - V_85 ;
V_216 = F_199 ( V_44 ) ;
while ( 1 ) {
V_247 = F_200 ( & V_216 , L_30 ) ;
if ( V_247 == NULL )
break;
if ( * V_247 == '\0' )
continue;
for ( V_110 = 0 ; V_110 < F_67 ( V_248 ) ; V_110 ++ ) {
if ( strcasecmp ( V_247 , V_248 [ V_110 ] . V_245 ) == 0 ) {
V_246 |= V_248 [ V_110 ] . V_246 ;
break;
}
}
if ( V_110 == F_67 ( V_248 ) ) {
V_246 = - V_76 ;
break;
}
}
F_32 ( V_44 ) ;
return V_246 ;
}
static T_6 F_201 ( char * V_44 , int V_246 )
{
int V_110 ;
char * V_249 = V_44 ;
for ( V_110 = 0 ; V_110 < F_67 ( V_248 ) ; V_110 ++ ) {
if ( V_246 & V_248 [ V_110 ] . V_246 ) {
V_249 += sprintf ( V_249 , L_31 ,
( V_249 == V_44 ) ? L_10 : L_30 , V_248 [ V_110 ] . V_245 ) ;
}
}
* V_249 ++ = '\n' ;
return V_249 - V_44 ;
}
static struct V_74 * F_202 ( struct V_98 * V_99 )
{
if ( V_99 -> V_250 == NULL )
return NULL ;
return F_76 ( V_99 ) ;
}
static T_6 F_203 ( struct V_25 * V_26 ,
struct V_251 * V_252 ,
char * V_44 )
{
struct V_100 * V_249 = F_204 ( V_26 ) ;
struct V_74 * V_75 ;
struct V_98 * V_99 ;
T_6 V_109 = - V_135 ;
V_99 = F_205 ( F_206 ( V_249 ) ) ;
if ( V_99 == NULL )
goto V_194;
V_75 = F_202 ( V_99 ) ;
if ( V_75 == NULL )
goto V_253;
F_56 ( & V_99 -> V_136 ) ;
if ( V_252 == & V_254 ) {
V_109 = sprintf ( V_44 , L_1 , ! ! V_75 -> V_1 ) ;
goto V_255;
}
if ( V_75 -> V_1 == NULL )
V_109 = sprintf ( V_44 , L_32 ) ;
else if ( V_252 == & V_256 )
V_109 = F_201 ( V_44 , V_75 -> V_1 -> V_47 ) ;
else if ( V_252 == & V_257 )
V_109 = sprintf ( V_44 , L_1 , V_75 -> V_1 -> V_3 ) ;
else if ( V_252 == & V_258 )
V_109 = sprintf ( V_44 , L_33 , V_75 -> V_1 -> V_55 ) ;
else if ( V_252 == & V_259 )
V_109 = sprintf ( V_44 , L_33 , V_75 -> V_1 -> V_56 ) ;
V_255:
F_58 ( & V_99 -> V_136 ) ;
V_253:
F_207 ( V_99 ) ;
V_194:
return V_109 ;
}
static T_6 F_208 ( struct V_25 * V_26 ,
struct V_251 * V_252 ,
const char * V_44 , T_2 V_79 )
{
struct V_98 * V_99 ;
struct V_74 * V_75 ;
struct V_100 * V_249 ;
T_16 V_260 ;
T_6 V_109 = - V_76 ;
if ( V_79 == 0 )
goto V_194;
if ( V_252 == & V_256 ) {
if ( sscanf ( V_44 , L_34 , & V_260 ) != 1 ) {
V_109 = F_197 ( V_44 ) ;
if ( V_109 < 0 )
goto V_194;
V_260 = V_109 ;
}
} else if ( sscanf ( V_44 , L_35 , & V_260 ) != 1 )
goto V_194;
V_109 = - V_135 ;
V_249 = F_204 ( V_26 ) ;
V_99 = F_205 ( F_206 ( V_249 ) ) ;
if ( V_99 == NULL )
goto V_194;
V_75 = F_202 ( V_99 ) ;
if ( V_75 == NULL )
goto V_253;
F_56 ( & V_99 -> V_136 ) ;
if ( V_252 == & V_254 ) {
if ( V_260 )
V_109 = F_196 ( V_75 , V_99 ) ;
else
V_109 = F_194 ( V_75 ) ;
goto V_255;
}
V_109 = 0 ;
if ( V_75 -> V_1 == NULL )
V_109 = F_196 ( V_75 , V_99 ) ;
if ( V_109 == 0 ) {
if ( V_252 == & V_256 )
V_75 -> V_1 -> V_47 = V_260 ;
else if ( V_252 == & V_257 )
V_75 -> V_1 -> V_3 = V_260 ;
else if ( V_252 == & V_258 )
V_75 -> V_1 -> V_55 = V_260 ;
else if ( V_252 == & V_259 )
V_75 -> V_1 -> V_56 = V_260 ;
}
V_255:
F_58 ( & V_99 -> V_136 ) ;
V_253:
F_207 ( V_99 ) ;
V_194:
return V_109 ? V_109 : V_79 ;
}
int F_209 ( struct V_25 * V_26 )
{
return F_210 ( & V_26 -> V_261 , & V_262 ) ;
}
void F_211 ( struct V_25 * V_26 )
{
F_212 ( & V_26 -> V_261 , & V_262 ) ;
}
void F_213 ( char * V_44 , struct V_146 * V_147 )
{
int V_110 , V_218 ;
int V_6 = V_147 -> V_154 ;
unsigned char * V_132 = V_147 -> V_132 ;
if ( V_147 -> V_149 != V_150 ) {
V_44 [ 0 ] = '\0' ;
return;
}
for ( V_218 = V_6 - 1 ; V_218 >= 0 ; V_218 -- )
if ( V_132 [ V_218 ] )
break;
V_218 ++ ;
for ( V_110 = 0 ; V_110 < V_6 ; V_110 ++ ) {
V_44 += sprintf ( V_44 , L_9 , V_110 == 0 ? L_10 : L_11 , V_132 [ V_110 ] ) ;
if ( V_110 == V_218 && V_218 != V_6 - 1 ) {
sprintf ( V_44 , L_36 ) ;
break;
}
}
}
void F_214 ( char * V_192 , T_3 V_58 , int V_57 )
{
int V_110 = 0 ;
if ( V_58 & V_263 )
V_192 [ V_110 ++ ] = 'F' ;
if ( V_58 & V_63 )
V_192 [ V_110 ++ ] = 'W' ;
else if ( V_58 & V_264 )
V_192 [ V_110 ++ ] = 'D' ;
else if ( V_57 )
V_192 [ V_110 ++ ] = 'R' ;
else
V_192 [ V_110 ++ ] = 'N' ;
if ( V_58 & V_265 )
V_192 [ V_110 ++ ] = 'F' ;
if ( V_58 & V_266 )
V_192 [ V_110 ++ ] = 'A' ;
if ( V_58 & V_267 )
V_192 [ V_110 ++ ] = 'S' ;
if ( V_58 & V_268 )
V_192 [ V_110 ++ ] = 'M' ;
if ( V_58 & V_269 )
V_192 [ V_110 ++ ] = 'E' ;
V_192 [ V_110 ] = '\0' ;
}
