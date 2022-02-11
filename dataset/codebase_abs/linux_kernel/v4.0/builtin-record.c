static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
if ( F_2 ( V_2 -> V_5 -> V_6 , V_3 , V_4 ) < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
V_2 -> V_7 += V_4 ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 V_13 ,
struct V_14 * V_14 V_13 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
return F_1 ( V_2 , V_11 , V_11 -> V_15 . V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_19 -> V_20 [ V_16 ] ;
unsigned int V_21 = F_7 ( V_18 ) ;
unsigned int V_22 = V_18 -> V_23 ;
unsigned char * V_24 = V_18 -> V_25 + V_26 ;
unsigned long V_4 ;
void * V_27 ;
int V_28 = 0 ;
if ( V_22 == V_21 )
return 0 ;
V_2 -> V_29 ++ ;
V_4 = V_21 - V_22 ;
if ( ( V_22 & V_18 -> V_30 ) + V_4 != ( V_21 & V_18 -> V_30 ) ) {
V_27 = & V_24 [ V_22 & V_18 -> V_30 ] ;
V_4 = V_18 -> V_30 + 1 - ( V_22 & V_18 -> V_30 ) ;
V_22 += V_4 ;
if ( F_1 ( V_2 , V_27 , V_4 ) < 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
V_27 = & V_24 [ V_22 & V_18 -> V_30 ] ;
V_4 = V_21 - V_22 ;
V_22 += V_4 ;
if ( F_1 ( V_2 , V_27 , V_4 ) < 0 ) {
V_28 = - 1 ;
goto V_31;
}
V_18 -> V_23 = V_22 ;
F_8 ( V_2 -> V_19 , V_16 ) ;
V_31:
return V_28 ;
}
static void F_9 ( int V_32 )
{
if ( V_32 == V_33 )
V_34 = 1 ;
else
V_35 = V_32 ;
V_36 = 1 ;
}
static void F_10 ( void )
{
if ( V_35 == - 1 )
return;
signal ( V_35 , V_37 ) ;
raise ( V_35 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
char V_38 [ 512 ] ;
struct V_39 * V_40 ;
struct V_41 * V_19 = V_2 -> V_19 ;
struct V_42 * V_5 = V_2 -> V_5 ;
struct V_43 * V_44 = & V_2 -> V_44 ;
int V_28 = 0 ;
F_12 ( V_19 , V_44 ) ;
F_13 (evlist, pos) {
V_45:
if ( F_14 ( V_40 , V_19 -> V_46 , V_19 -> V_47 ) < 0 ) {
if ( F_15 ( V_40 , V_48 , V_38 , sizeof( V_38 ) ) ) {
if ( V_49 )
F_16 ( L_2 , V_38 ) ;
goto V_45;
}
V_28 = - V_48 ;
F_17 ( V_40 , & V_44 -> V_50 ,
V_48 , V_38 , sizeof( V_38 ) ) ;
F_18 ( L_2 , V_38 ) ;
goto V_31;
}
}
if ( F_19 ( V_19 ) ) {
error ( L_3 , V_48 ,
F_20 ( V_48 , V_38 , sizeof( V_38 ) ) ) ;
V_28 = - 1 ;
goto V_31;
}
if ( F_21 ( V_19 , V_44 -> V_51 , false ) < 0 ) {
if ( V_48 == V_52 ) {
F_3 ( L_4
L_5
L_6
L_7
L_8 , V_44 -> V_51 ) ;
V_28 = - V_48 ;
} else {
F_3 ( L_9 , V_48 ,
F_20 ( V_48 , V_38 , sizeof( V_38 ) ) ) ;
V_28 = - V_48 ;
}
goto V_31;
}
V_5 -> V_19 = V_19 ;
F_22 ( V_5 ) ;
V_31:
return V_28 ;
}
static int F_23 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_39 * V_53 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_29 ++ ;
return F_24 ( V_9 , V_11 , T_2 , V_53 , V_14 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_54 * V_6 = & V_2 -> V_6 ;
struct V_42 * V_5 = V_2 -> V_5 ;
T_3 V_4 = F_26 ( F_27 ( V_6 ) , 0 , V_55 ) ;
if ( V_4 == 0 )
return 0 ;
V_6 -> V_4 = V_4 ;
V_56 . V_57 = true ;
return F_28 ( V_5 , & V_2 -> V_9 ) ;
}
static void F_29 ( struct V_14 * V_14 , void * V_24 )
{
int V_58 ;
struct V_8 * V_9 = V_24 ;
V_58 = F_30 ( V_9 , F_4 ,
V_14 ) ;
if ( V_58 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_59 ) ;
V_58 = F_31 ( V_9 , F_4 ,
V_14 ) ;
if ( V_58 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_59 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_60 ;
int V_28 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_19 -> V_61 ; V_60 ++ ) {
if ( V_2 -> V_19 -> V_20 [ V_60 ] . V_25 ) {
if ( F_6 ( V_2 , V_60 ) != 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
}
if ( V_7 != V_2 -> V_7 )
V_28 = F_1 ( V_2 , & V_62 , sizeof( V_62 ) ) ;
V_31:
return V_28 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_42 * V_5 = V_2 -> V_5 ;
int V_63 ;
for ( V_63 = V_64 ; V_63 < V_65 ; V_63 ++ )
F_34 ( & V_5 -> V_15 , V_63 ) ;
if ( V_2 -> V_66 )
F_35 ( & V_5 -> V_15 , V_67 ) ;
if ( ! F_36 ( & V_2 -> V_19 -> V_68 ) )
F_35 ( & V_5 -> V_15 , V_69 ) ;
if ( ! V_2 -> V_44 . V_70 )
F_35 ( & V_5 -> V_15 , V_71 ) ;
}
static void F_37 ( int T_4 V_13 ,
T_5 * V_72 ,
void * T_6 V_13 )
{
V_73 = V_72 -> V_74 . V_75 ;
V_36 = 1 ;
V_34 = 1 ;
}
static int F_38 ( struct V_1 * V_2 , int V_76 , const char * * V_77 )
{
int V_58 ;
int V_78 = 0 ;
unsigned long V_79 = 0 ;
const bool V_80 = V_76 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_43 * V_44 = & V_2 -> V_44 ;
struct V_54 * V_6 = & V_2 -> V_6 ;
struct V_42 * V_5 ;
bool V_81 = false , V_82 = false ;
int V_83 ;
V_2 -> V_84 = V_77 [ 0 ] ;
atexit ( F_10 ) ;
signal ( V_33 , F_9 ) ;
signal ( V_85 , F_9 ) ;
signal ( V_86 , F_9 ) ;
V_5 = F_39 ( V_6 , false , NULL ) ;
if ( V_5 == NULL ) {
F_3 ( L_12 ) ;
return - 1 ;
}
V_83 = F_27 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_33 ( V_2 ) ;
if ( V_80 ) {
V_58 = F_40 ( V_2 -> V_19 , & V_44 -> V_50 ,
V_77 , V_6 -> V_87 ,
F_37 ) ;
if ( V_58 < 0 ) {
F_3 ( L_13 ) ;
V_78 = V_58 ;
goto V_88;
}
}
if ( F_11 ( V_2 ) != 0 ) {
V_58 = - 1 ;
goto V_89;
}
if ( ! V_2 -> V_19 -> V_90 )
F_35 ( & V_5 -> V_15 , V_91 ) ;
if ( V_6 -> V_87 ) {
V_58 = F_41 ( V_83 ) ;
if ( V_58 < 0 )
goto V_89;
} else {
V_58 = F_42 ( V_5 , V_2 -> V_19 , V_83 , false ) ;
if ( V_58 < 0 )
goto V_89;
}
if ( ! V_2 -> V_66
&& ! F_43 ( & V_5 -> V_15 , V_67 ) ) {
F_3 ( L_14
L_15 ) ;
V_58 = - 1 ;
goto V_89;
}
V_14 = & V_5 -> V_92 . V_93 ;
if ( V_6 -> V_87 ) {
V_58 = F_44 ( V_9 , V_5 ,
F_4 ) ;
if ( V_58 < 0 ) {
F_3 ( L_16 ) ;
goto V_89;
}
if ( F_36 ( & V_2 -> V_19 -> V_68 ) ) {
V_58 = F_45 ( V_9 , V_83 , V_2 -> V_19 ,
F_4 ) ;
if ( V_58 <= 0 ) {
F_3 ( L_17 ) ;
goto V_89;
}
V_2 -> V_7 += V_58 ;
}
}
V_58 = F_31 ( V_9 , F_4 ,
V_14 ) ;
if ( V_58 < 0 )
F_3 ( L_18
L_19
L_20 ) ;
V_58 = F_30 ( V_9 , F_4 ,
V_14 ) ;
if ( V_58 < 0 )
F_3 ( L_21
L_19
L_22 ) ;
if ( V_94 ) {
F_46 ( & V_5 -> V_92 ,
F_29 , V_9 ) ;
}
V_58 = F_47 ( V_14 , V_9 , & V_44 -> V_50 , V_2 -> V_19 -> V_47 ,
F_4 , V_44 -> V_95 ) ;
if ( V_58 != 0 )
goto V_89;
if ( V_2 -> V_96 ) {
struct V_97 V_98 ;
V_98 . V_99 = V_2 -> V_96 ;
if ( F_48 ( 0 , V_100 , & V_98 ) ) {
F_3 ( L_23 ) ;
V_58 = - 1 ;
goto V_89;
}
}
if ( ! F_49 ( & V_44 -> V_50 ) && ! V_44 -> V_101 )
F_50 ( V_2 -> V_19 ) ;
if ( V_80 )
F_51 ( V_2 -> V_19 ) ;
if ( V_44 -> V_101 ) {
F_52 ( V_44 -> V_101 * 1000 ) ;
F_50 ( V_2 -> V_19 ) ;
}
for (; ; ) {
int V_102 = V_2 -> V_29 ;
if ( F_32 ( V_2 ) < 0 ) {
V_58 = - 1 ;
goto V_89;
}
if ( V_102 == V_2 -> V_29 ) {
if ( V_36 || V_82 )
break;
V_58 = F_53 ( V_2 -> V_19 , - 1 ) ;
if ( V_58 > 0 || ( V_58 < 0 && V_48 == V_103 ) )
V_58 = 0 ;
V_79 ++ ;
if ( F_54 ( V_2 -> V_19 , V_104 | V_105 ) == 0 )
V_82 = true ;
}
if ( V_36 && ! V_81 && ! F_49 ( & V_44 -> V_50 ) ) {
F_55 ( V_2 -> V_19 ) ;
V_81 = true ;
}
}
if ( V_80 && V_73 ) {
char V_38 [ V_106 ] ;
const char * V_107 = F_20 ( V_73 , V_38 , sizeof( V_38 ) ) ;
F_3 ( L_24 , V_107 ) ;
V_58 = - 1 ;
goto V_89;
}
if ( ! V_108 )
fprintf ( V_109 , L_25 , V_79 ) ;
V_89:
if ( V_80 ) {
int V_110 ;
if ( ! V_34 )
F_56 ( V_2 -> V_19 -> V_111 . V_59 , V_86 ) ;
F_57 ( & V_110 ) ;
if ( V_58 < 0 )
V_78 = V_58 ;
else if ( F_58 ( V_110 ) )
V_78 = F_59 ( V_110 ) ;
else if ( F_60 ( V_110 ) )
V_35 = F_61 ( V_110 ) ;
} else
V_78 = V_58 ;
V_2 -> V_29 = 0 ;
if ( ! V_58 && ! V_6 -> V_87 ) {
V_2 -> V_5 -> V_15 . V_112 += V_2 -> V_7 ;
if ( ! V_2 -> V_66 )
F_25 ( V_2 ) ;
F_42 ( V_2 -> V_5 , V_2 -> V_19 , V_83 , true ) ;
}
if ( ! V_58 && ! V_108 ) {
char V_29 [ 128 ] ;
if ( V_2 -> V_29 )
F_62 ( V_29 , sizeof( V_29 ) ,
L_26 V_113 L_27 , V_2 -> V_29 ) ;
else
V_29 [ 0 ] = '\0' ;
fprintf ( V_109 , L_28 ,
F_63 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_114 , V_29 ) ;
}
V_88:
F_64 ( V_5 ) ;
return V_78 ;
}
static int
F_65 ( const struct V_115 * V_116 , const char * V_117 , int V_118 )
{
#define F_66 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_7 * V_119 = ( T_7 * ) V_116 -> V_120 ;
const struct V_121 * V_122 ;
char * V_123 , * V_124 = NULL , * V_125 ;
int V_126 = - 1 ;
if ( V_118 )
return 0 ;
if ( * V_119 )
return - 1 ;
if ( V_117 ) {
V_123 = V_124 = F_67 ( V_117 ) ;
if ( ! V_123 )
return - 1 ;
for (; ; ) {
V_125 = strchr ( V_123 , ',' ) ;
if ( V_125 )
* V_125 = '\0' ;
for ( V_122 = V_127 ; V_122 -> V_128 ; V_122 ++ ) {
if ( ! strcasecmp ( V_123 , V_122 -> V_128 ) )
break;
}
if ( ! V_122 -> V_128 ) {
F_16 ( L_29
L_30 , V_123 ) ;
goto error;
}
* V_119 |= V_122 -> V_119 ;
if ( ! V_125 )
break;
V_123 = V_125 + 1 ;
}
}
V_126 = 0 ;
if ( ( * V_119 & ~ F_66 ) == 0 ) {
* V_119 = V_129 ;
}
error:
free ( V_124 ) ;
return V_126 ;
}
static void F_68 ( void )
{
static const char * V_117 [ V_130 ] = { L_31 , L_32 , L_33 } ;
F_69 ( L_34 , V_117 [ V_131 . V_132 ] ) ;
if ( V_131 . V_132 == V_133 )
F_69 ( L_35 ,
V_131 . V_134 ) ;
}
int F_70 ( const struct V_115 * V_116 V_13 ,
const char * V_135 ,
int V_118 )
{
int V_126 ;
V_131 . V_136 = ! V_118 ;
if ( V_118 ) {
V_131 . V_132 = V_137 ;
F_69 ( L_36 ) ;
return 0 ;
}
V_126 = F_71 ( V_135 ) ;
if ( ! V_126 )
F_68 () ;
return V_126 ;
}
int F_72 ( const struct V_115 * V_116 V_13 ,
const char * V_135 V_13 ,
int V_118 V_13 )
{
V_131 . V_136 = true ;
if ( V_131 . V_132 == V_137 )
V_131 . V_132 = V_138 ;
F_68 () ;
return 0 ;
}
static int F_73 ( const char * V_139 , const char * V_120 , void * V_140 )
{
if ( ! strcmp ( V_139 , L_37 ) )
V_139 = L_38 ;
return F_74 ( V_139 , V_120 , V_140 ) ;
}
int F_75 ( int V_76 , const char * * V_77 , const char * T_8 V_13 )
{
int V_58 = - V_141 ;
struct V_1 * V_2 = & V_1 ;
char V_142 [ V_143 ] ;
V_2 -> V_19 = F_76 () ;
if ( V_2 -> V_19 == NULL )
return - V_141 ;
F_77 ( F_73 , V_2 ) ;
V_76 = F_78 ( V_76 , V_77 , V_144 , V_145 ,
V_146 ) ;
if ( ! V_76 && F_49 ( & V_2 -> V_44 . V_50 ) )
F_79 ( V_145 , V_144 ) ;
if ( V_147 && ! V_2 -> V_44 . V_50 . V_148 ) {
F_18 ( L_39
L_40 ) ;
F_79 ( V_145 , V_144 ) ;
}
F_80 ( NULL ) ;
if ( V_56 . V_149 )
F_81 (
L_41
L_42
L_43
L_44
L_45
L_46
L_47 ) ;
if ( V_2 -> V_150 || V_2 -> V_66 )
F_82 () ;
if ( V_2 -> V_19 -> V_151 == 0 &&
F_83 ( V_2 -> V_19 ) < 0 ) {
F_3 ( L_48 ) ;
goto V_152;
}
if ( V_2 -> V_44 . V_50 . V_153 && ! V_2 -> V_44 . V_154 )
V_2 -> V_44 . V_155 = true ;
V_58 = F_84 ( & V_2 -> V_44 . V_50 ) ;
if ( V_58 ) {
F_85 ( & V_2 -> V_44 . V_50 , V_58 , V_142 , V_143 ) ;
F_16 ( L_49 , V_142 ) ;
}
V_58 = F_86 ( & V_2 -> V_44 . V_50 ) ;
if ( V_58 ) {
int V_156 = V_48 ;
F_85 ( & V_2 -> V_44 . V_50 , V_58 , V_142 , V_143 ) ;
F_18 ( L_49 , V_142 ) ;
V_58 = - V_156 ;
goto V_152;
}
V_58 = - V_141 ;
if ( F_87 ( V_2 -> V_19 , & V_2 -> V_44 . V_50 ) < 0 )
F_79 ( V_145 , V_144 ) ;
if ( F_88 ( & V_2 -> V_44 ) ) {
V_58 = - V_157 ;
goto V_152;
}
V_58 = F_38 ( & V_1 , V_76 , V_77 ) ;
V_152:
F_89 ( V_2 -> V_19 ) ;
F_90 () ;
return V_58 ;
}
