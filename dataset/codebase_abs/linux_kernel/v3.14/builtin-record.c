static int F_1 ( T_1 V_1 , void * V_2 )
{
if ( V_3 == V_4 )
return - V_5 ;
else if ( V_3 == 0 )
atexit ( V_6 ) ;
V_7 [ V_3 ] = V_1 ;
V_8 [ V_3 ++ ] = V_2 ;
return 0 ;
}
static void V_6 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ )
V_7 [ V_9 ] ( V_10 , V_8 [ V_9 ] ) ;
}
static int F_2 ( struct V_11 * V_12 , void * V_13 , T_2 V_14 )
{
if ( F_3 ( V_12 -> V_15 -> V_16 , V_13 , V_14 ) < 0 ) {
F_4 ( L_1 ) ;
return - 1 ;
}
V_12 -> V_17 += V_14 ;
return 0 ;
}
static int F_5 ( struct V_18 * V_19 ,
union V_20 * V_21 ,
struct V_22 * T_3 V_23 ,
struct V_24 * V_24 V_23 )
{
struct V_11 * V_12 = F_6 ( V_19 , struct V_11 , V_19 ) ;
return F_2 ( V_12 , V_21 , V_21 -> V_25 . V_14 ) ;
}
static int F_7 ( struct V_11 * V_12 , struct V_26 * V_27 )
{
unsigned int V_28 = F_8 ( V_27 ) ;
unsigned int V_29 = V_27 -> V_30 ;
unsigned char * V_31 = V_27 -> V_32 + V_33 ;
unsigned long V_14 ;
void * V_34 ;
int V_35 = 0 ;
if ( V_29 == V_28 )
return 0 ;
V_12 -> V_36 ++ ;
V_14 = V_28 - V_29 ;
if ( ( V_29 & V_27 -> V_37 ) + V_14 != ( V_28 & V_27 -> V_37 ) ) {
V_34 = & V_31 [ V_29 & V_27 -> V_37 ] ;
V_14 = V_27 -> V_37 + 1 - ( V_29 & V_27 -> V_37 ) ;
V_29 += V_14 ;
if ( F_2 ( V_12 , V_34 , V_14 ) < 0 ) {
V_35 = - 1 ;
goto V_38;
}
}
V_34 = & V_31 [ V_29 & V_27 -> V_37 ] ;
V_14 = V_28 - V_29 ;
V_29 += V_14 ;
if ( F_2 ( V_12 , V_34 , V_14 ) < 0 ) {
V_35 = - 1 ;
goto V_38;
}
V_27 -> V_30 = V_29 ;
F_9 ( V_27 , V_29 ) ;
V_38:
return V_35 ;
}
static void F_10 ( int V_39 )
{
if ( V_39 == V_40 )
V_41 = 1 ;
V_42 = 1 ;
V_43 = V_39 ;
}
static void F_11 ( int T_4 V_23 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
int V_44 ;
if ( V_12 -> V_45 -> V_46 . V_47 > 0 ) {
if ( ! V_41 )
F_12 ( V_12 -> V_45 -> V_46 . V_47 , V_48 ) ;
F_13 ( & V_44 ) ;
if ( F_14 ( V_44 ) )
F_15 ( F_16 ( V_44 ) , V_12 -> V_49 ) ;
}
if ( V_43 == - 1 || V_43 == V_50 )
return;
signal ( V_43 , V_51 ) ;
}
static int F_17 ( struct V_11 * V_12 )
{
char V_52 [ 512 ] ;
struct V_53 * V_54 ;
struct V_55 * V_45 = V_12 -> V_45 ;
struct V_56 * V_15 = V_12 -> V_15 ;
struct V_57 * V_58 = & V_12 -> V_58 ;
int V_35 = 0 ;
F_18 ( V_45 , V_58 ) ;
F_19 (evlist, pos) {
V_59:
if ( F_20 ( V_54 , V_45 -> V_60 , V_45 -> V_61 ) < 0 ) {
if ( F_21 ( V_54 , V_62 , V_52 , sizeof( V_52 ) ) ) {
if ( V_63 )
F_22 ( L_2 , V_52 ) ;
goto V_59;
}
V_35 = - V_62 ;
F_23 ( V_54 , & V_58 -> V_64 ,
V_62 , V_52 , sizeof( V_52 ) ) ;
F_24 ( L_2 , V_52 ) ;
goto V_38;
}
}
if ( F_25 ( V_45 ) ) {
error ( L_3 , V_62 ,
strerror ( V_62 ) ) ;
V_35 = - 1 ;
goto V_38;
}
if ( F_26 ( V_45 , V_58 -> V_65 , false ) < 0 ) {
if ( V_62 == V_66 ) {
F_4 ( L_4
L_5
L_6
L_7
L_8 , V_58 -> V_65 ) ;
V_35 = - V_62 ;
} else {
F_4 ( L_9 , V_62 , strerror ( V_62 ) ) ;
V_35 = - V_62 ;
}
goto V_38;
}
V_15 -> V_45 = V_45 ;
F_27 ( V_15 ) ;
V_38:
return V_35 ;
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_67 * V_16 = & V_12 -> V_16 ;
struct V_56 * V_15 = V_12 -> V_15 ;
T_5 V_68 = V_15 -> V_25 . V_69 ;
T_5 V_14 = F_29 ( V_16 -> V_70 , 0 , V_71 ) ;
if ( V_14 == 0 )
return 0 ;
return F_30 ( V_15 , V_68 ,
V_14 - V_68 ,
V_14 , & V_72 ) ;
}
static void F_31 ( int V_44 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
struct V_67 * V_16 = & V_12 -> V_16 ;
if ( V_44 != 0 )
return;
if ( ! V_16 -> V_73 ) {
V_12 -> V_15 -> V_25 . V_74 += V_12 -> V_17 ;
if ( ! V_12 -> V_75 )
F_28 ( V_12 ) ;
F_32 ( V_12 -> V_15 , V_12 -> V_45 ,
V_16 -> V_70 , true ) ;
F_33 ( V_12 -> V_15 ) ;
F_34 ( V_12 -> V_45 ) ;
F_35 () ;
}
}
static void F_36 ( struct V_24 * V_24 , void * V_31 )
{
int V_76 ;
struct V_18 * V_19 = V_31 ;
V_76 = F_37 ( V_19 , F_5 ,
V_24 ) ;
if ( V_76 < 0 )
F_4 ( L_10
L_11 , V_24 -> V_47 ) ;
V_76 = F_38 ( V_19 , F_5 ,
V_24 ) ;
if ( V_76 < 0 )
F_4 ( L_10
L_11 , V_24 -> V_47 ) ;
}
static int F_39 ( struct V_11 * V_12 )
{
int V_9 ;
int V_35 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 -> V_45 -> V_77 ; V_9 ++ ) {
if ( V_12 -> V_45 -> V_78 [ V_9 ] . V_32 ) {
if ( F_7 ( V_12 , & V_12 -> V_45 -> V_78 [ V_9 ] ) != 0 ) {
V_35 = - 1 ;
goto V_38;
}
}
}
if ( F_40 ( & V_12 -> V_15 -> V_25 , V_79 ) )
V_35 = F_2 ( V_12 , & V_80 , sizeof( V_80 ) ) ;
V_38:
return V_35 ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_56 * V_15 = V_12 -> V_15 ;
int V_81 ;
for ( V_81 = V_82 ; V_81 < V_83 ; V_81 ++ )
F_42 ( & V_15 -> V_25 , V_81 ) ;
if ( V_12 -> V_75 )
F_43 ( & V_15 -> V_25 , V_84 ) ;
if ( ! F_44 ( & V_12 -> V_45 -> V_85 ) )
F_43 ( & V_15 -> V_25 , V_79 ) ;
if ( ! V_12 -> V_58 . V_86 )
F_43 ( & V_15 -> V_25 , V_87 ) ;
}
static void F_45 ( int V_88 , T_6 * V_89 ,
void * T_7 V_23 )
{
V_90 = V_89 -> V_91 . V_92 ;
V_42 = 1 ;
V_43 = V_88 ;
V_41 = 1 ;
}
static int F_46 ( struct V_11 * V_12 , int V_93 , const char * * V_94 )
{
int V_76 ;
unsigned long V_95 = 0 ;
const bool V_96 = V_93 > 0 ;
struct V_24 * V_24 ;
struct V_18 * V_19 = & V_12 -> V_19 ;
struct V_57 * V_58 = & V_12 -> V_58 ;
struct V_67 * V_16 = & V_12 -> V_16 ;
struct V_56 * V_15 ;
bool V_97 = false ;
V_12 -> V_49 = V_94 [ 0 ] ;
F_1 ( F_11 , V_12 ) ;
signal ( V_40 , F_10 ) ;
signal ( V_98 , F_10 ) ;
signal ( V_48 , F_10 ) ;
V_15 = F_47 ( V_16 , false , NULL ) ;
if ( V_15 == NULL ) {
F_4 ( L_12 ) ;
return - 1 ;
}
V_12 -> V_15 = V_15 ;
F_41 ( V_12 ) ;
if ( V_96 ) {
V_76 = F_48 ( V_12 -> V_45 , & V_58 -> V_64 ,
V_94 , V_16 -> V_73 ,
F_45 ) ;
if ( V_76 < 0 ) {
F_4 ( L_13 ) ;
goto V_99;
}
}
if ( F_17 ( V_12 ) != 0 ) {
V_76 = - 1 ;
goto V_99;
}
if ( ! V_12 -> V_45 -> V_100 )
F_43 ( & V_15 -> V_25 , V_101 ) ;
F_1 ( F_31 , V_12 ) ;
if ( V_16 -> V_73 ) {
V_76 = F_49 ( V_16 -> V_70 ) ;
if ( V_76 < 0 )
goto V_99;
} else {
V_76 = F_32 ( V_15 , V_12 -> V_45 ,
V_16 -> V_70 , false ) ;
if ( V_76 < 0 )
goto V_99;
}
if ( ! V_12 -> V_75
&& ! F_40 ( & V_15 -> V_25 , V_84 ) ) {
F_4 ( L_14
L_15 ) ;
V_76 = - 1 ;
goto V_99;
}
V_24 = & V_15 -> V_102 . V_103 ;
if ( V_16 -> V_73 ) {
V_76 = F_50 ( V_19 , V_15 ,
F_5 ) ;
if ( V_76 < 0 ) {
F_4 ( L_16 ) ;
goto V_99;
}
if ( F_44 ( & V_12 -> V_45 -> V_85 ) ) {
V_76 = F_51 ( V_19 , V_16 -> V_70 , V_12 -> V_45 ,
F_5 ) ;
if ( V_76 <= 0 ) {
F_4 ( L_17 ) ;
goto V_99;
}
V_12 -> V_17 += V_76 ;
}
}
V_76 = F_38 ( V_19 , F_5 ,
V_24 ) ;
if ( V_76 < 0 )
F_4 ( L_18
L_19
L_20 ) ;
V_76 = F_37 ( V_19 , F_5 ,
V_24 ) ;
if ( V_76 < 0 )
F_4 ( L_21
L_19
L_22 ) ;
if ( V_104 ) {
F_52 ( & V_15 -> V_102 ,
F_36 , V_19 ) ;
}
V_76 = F_53 ( V_24 , V_19 , & V_58 -> V_64 , V_12 -> V_45 -> V_61 ,
F_5 , V_58 -> V_105 ) ;
if ( V_76 != 0 )
goto V_99;
if ( V_12 -> V_106 ) {
struct V_107 V_108 ;
V_108 . V_109 = V_12 -> V_106 ;
if ( F_54 ( 0 , V_110 , & V_108 ) ) {
F_4 ( L_23 ) ;
V_76 = - 1 ;
goto V_99;
}
}
if ( ! F_55 ( & V_58 -> V_64 ) && ! V_58 -> V_111 )
F_56 ( V_12 -> V_45 ) ;
if ( V_96 )
F_57 ( V_12 -> V_45 ) ;
if ( V_58 -> V_111 ) {
F_58 ( V_58 -> V_111 * 1000 ) ;
F_56 ( V_12 -> V_45 ) ;
}
for (; ; ) {
int V_112 = V_12 -> V_36 ;
if ( F_39 ( V_12 ) < 0 ) {
V_76 = - 1 ;
goto V_99;
}
if ( V_112 == V_12 -> V_36 ) {
if ( V_42 )
break;
V_76 = F_59 ( V_12 -> V_45 -> V_113 , V_12 -> V_45 -> V_114 , - 1 ) ;
V_95 ++ ;
}
if ( V_42 && ! V_97 && ! F_55 ( & V_58 -> V_64 ) ) {
F_60 ( V_12 -> V_45 ) ;
V_97 = true ;
}
}
if ( V_96 && V_90 ) {
char V_52 [ 512 ] ;
const char * V_115 = F_61 ( V_90 , V_52 , sizeof( V_52 ) ) ;
F_4 ( L_24 , V_115 ) ;
V_76 = - 1 ;
goto V_99;
}
if ( V_116 || V_43 == V_50 )
return 0 ;
fprintf ( V_117 , L_25 , V_95 ) ;
fprintf ( V_117 ,
L_26 V_118 L_27 ,
( double ) V_12 -> V_17 / 1024.0 / 1024.0 ,
V_16 -> V_119 ,
V_12 -> V_17 / 24 ) ;
return 0 ;
V_99:
F_33 ( V_15 ) ;
return V_76 ;
}
static int
F_62 ( const struct V_120 * V_121 , const char * V_122 , int V_123 )
{
#define F_63 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_8 * V_124 = ( T_8 * ) V_121 -> V_125 ;
const struct V_126 * V_127 ;
char * V_128 , * V_129 = NULL , * V_130 ;
int V_131 = - 1 ;
if ( V_123 )
return 0 ;
if ( * V_124 )
return - 1 ;
if ( V_122 ) {
V_128 = V_129 = F_64 ( V_122 ) ;
if ( ! V_128 )
return - 1 ;
for (; ; ) {
V_130 = strchr ( V_128 , ',' ) ;
if ( V_130 )
* V_130 = '\0' ;
for ( V_127 = V_132 ; V_127 -> V_133 ; V_127 ++ ) {
if ( ! strcasecmp ( V_128 , V_127 -> V_133 ) )
break;
}
if ( ! V_127 -> V_133 ) {
F_22 ( L_28
L_29 , V_128 ) ;
goto error;
}
* V_124 |= V_127 -> V_124 ;
if ( ! V_130 )
break;
V_128 = V_130 + 1 ;
}
}
V_131 = 0 ;
if ( ( * V_124 & ~ F_63 ) == 0 ) {
* V_124 = V_134 ;
}
error:
free ( V_129 ) ;
return V_131 ;
}
static int F_65 ( char * V_122 , unsigned long * V_135 )
{
char * V_136 ;
unsigned long V_14 ;
unsigned long V_137 = F_66 ( V_138 , sizeof( T_5 ) ) ;
V_14 = strtoul ( V_122 , & V_136 , 0 ) ;
do {
if ( * V_136 )
break;
V_14 = F_67 ( V_14 , sizeof( T_5 ) ) ;
if ( ! V_14 || V_14 > V_137 )
break;
* V_135 = V_14 ;
return 0 ;
} while ( 0 );
F_4 ( L_30 ,
V_137 , V_122 ) ;
return - 1 ;
}
int F_68 ( const char * V_2 , struct V_57 * V_58 )
{
char * V_139 , * V_133 , * V_140 = NULL ;
char * V_34 ;
int V_131 = - 1 ;
V_34 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( ! V_34 )
return - V_5 ;
strcpy ( V_34 , V_2 ) ;
V_139 = strtok_r ( ( char * ) V_34 , L_31 , & V_140 ) ;
V_133 = V_139 ? : ( char * ) V_34 ;
do {
if ( ! strncmp ( V_133 , L_32 , sizeof( L_32 ) ) ) {
if ( ! strtok_r ( NULL , L_31 , & V_140 ) ) {
V_58 -> V_141 = V_142 ;
V_131 = 0 ;
} else
F_4 ( L_33
L_34 ) ;
break;
#ifdef F_69
} else if ( ! strncmp ( V_133 , L_35 , sizeof( L_35 ) ) ) {
const unsigned long V_143 = 8192 ;
V_131 = 0 ;
V_58 -> V_141 = V_144 ;
V_58 -> V_145 = V_143 ;
V_139 = strtok_r ( NULL , L_31 , & V_140 ) ;
if ( V_139 ) {
unsigned long V_14 = 0 ;
V_131 = F_65 ( V_139 , & V_14 ) ;
V_58 -> V_145 = V_14 ;
}
#endif
} else {
F_4 ( L_36
L_37 , V_2 ) ;
break;
}
} while ( 0 );
free ( V_34 ) ;
return V_131 ;
}
static void F_70 ( struct V_57 * V_58 )
{
F_71 ( L_38 , V_58 -> V_141 ) ;
if ( V_58 -> V_141 == V_144 )
F_71 ( L_39 ,
V_58 -> V_145 ) ;
}
int F_72 ( const struct V_120 * V_121 ,
const char * V_2 ,
int V_123 )
{
struct V_57 * V_58 = V_121 -> V_125 ;
int V_131 ;
if ( V_123 ) {
V_58 -> V_141 = V_146 ;
F_71 ( L_40 ) ;
return 0 ;
}
V_131 = F_68 ( V_2 , V_58 ) ;
if ( ! V_131 )
F_70 ( V_58 ) ;
return V_131 ;
}
int F_73 ( const struct V_120 * V_121 ,
const char * V_2 V_23 ,
int V_123 V_23 )
{
struct V_57 * V_58 = V_121 -> V_125 ;
if ( V_58 -> V_141 == V_146 )
V_58 -> V_141 = V_142 ;
F_70 ( V_58 ) ;
return 0 ;
}
int F_74 ( int V_93 , const char * * V_94 , const char * T_9 V_23 )
{
int V_76 = - V_5 ;
struct V_11 * V_12 = & V_11 ;
char V_147 [ V_148 ] ;
V_12 -> V_45 = F_75 () ;
if ( V_12 -> V_45 == NULL )
return - V_5 ;
V_93 = F_76 ( V_93 , V_94 , V_149 , V_150 ,
V_151 ) ;
if ( ! V_93 && F_55 ( & V_12 -> V_58 . V_64 ) )
F_77 ( V_150 , V_149 ) ;
if ( V_152 && ! V_12 -> V_58 . V_64 . V_153 ) {
F_24 ( L_41
L_42 ) ;
F_77 ( V_150 , V_149 ) ;
}
F_78 () ;
if ( V_154 . V_155 )
F_79 (
L_43
L_44
L_45
L_46
L_47
L_48
L_49 ) ;
if ( V_12 -> V_156 || V_12 -> V_75 )
F_80 () ;
if ( V_12 -> V_45 -> V_157 == 0 &&
F_81 ( V_12 -> V_45 ) < 0 ) {
F_4 ( L_50 ) ;
goto V_158;
}
if ( V_12 -> V_58 . V_64 . V_159 && ! V_12 -> V_58 . V_160 )
V_12 -> V_58 . V_161 = true ;
V_76 = F_82 ( & V_12 -> V_58 . V_64 ) ;
if ( V_76 ) {
F_83 ( & V_12 -> V_58 . V_64 , V_76 , V_147 , V_148 ) ;
F_22 ( L_51 , V_147 ) ;
}
V_76 = F_84 ( & V_12 -> V_58 . V_64 ) ;
if ( V_76 ) {
int V_162 = V_62 ;
F_83 ( & V_12 -> V_58 . V_64 , V_76 , V_147 , V_148 ) ;
F_24 ( L_51 , V_147 ) ;
V_76 = - V_162 ;
goto V_158;
}
V_76 = - V_5 ;
if ( F_85 ( V_12 -> V_45 , & V_12 -> V_58 . V_64 ) < 0 )
F_77 ( V_150 , V_149 ) ;
if ( F_86 ( & V_12 -> V_58 ) ) {
V_76 = - V_163 ;
goto V_158;
}
V_76 = F_46 ( & V_11 , V_93 , V_94 ) ;
V_158:
F_35 () ;
return V_76 ;
}
