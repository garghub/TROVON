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
static int F_23 ( struct V_1 * V_2 )
{
struct V_53 * V_6 = & V_2 -> V_6 ;
struct V_42 * V_5 = V_2 -> V_5 ;
T_3 V_54 = V_5 -> V_15 . V_55 ;
T_3 V_4 = F_24 ( V_6 -> V_56 , 0 , V_57 ) ;
if ( V_4 == 0 )
return 0 ;
V_58 . V_59 = true ;
return F_25 ( V_5 , V_54 ,
V_4 - V_54 ,
V_4 , & V_60 ) ;
}
static void F_26 ( struct V_14 * V_14 , void * V_24 )
{
int V_61 ;
struct V_8 * V_9 = V_24 ;
V_61 = F_27 ( V_9 , F_4 ,
V_14 ) ;
if ( V_61 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_62 ) ;
V_61 = F_28 ( V_9 , F_4 ,
V_14 ) ;
if ( V_61 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_62 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_63 ;
int V_28 = 0 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_19 -> V_64 ; V_63 ++ ) {
if ( V_2 -> V_19 -> V_20 [ V_63 ] . V_25 ) {
if ( F_6 ( V_2 , V_63 ) != 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
}
if ( V_7 != V_2 -> V_7 )
V_28 = F_1 ( V_2 , & V_65 , sizeof( V_65 ) ) ;
V_31:
return V_28 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_42 * V_5 = V_2 -> V_5 ;
int V_66 ;
for ( V_66 = V_67 ; V_66 < V_68 ; V_66 ++ )
F_31 ( & V_5 -> V_15 , V_66 ) ;
if ( V_2 -> V_69 )
F_32 ( & V_5 -> V_15 , V_70 ) ;
if ( ! F_33 ( & V_2 -> V_19 -> V_71 ) )
F_32 ( & V_5 -> V_15 , V_72 ) ;
if ( ! V_2 -> V_44 . V_73 )
F_32 ( & V_5 -> V_15 , V_74 ) ;
}
static void F_34 ( int T_4 V_13 ,
T_5 * V_75 ,
void * T_6 V_13 )
{
V_76 = V_75 -> V_77 . V_78 ;
V_36 = 1 ;
V_34 = 1 ;
}
static int F_35 ( struct V_1 * V_2 , int V_79 , const char * * V_80 )
{
int V_61 ;
int V_81 = 0 ;
unsigned long V_82 = 0 ;
const bool V_83 = V_79 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_43 * V_44 = & V_2 -> V_44 ;
struct V_53 * V_6 = & V_2 -> V_6 ;
struct V_42 * V_5 ;
bool V_84 = false , V_85 = false ;
V_2 -> V_86 = V_80 [ 0 ] ;
atexit ( F_10 ) ;
signal ( V_33 , F_9 ) ;
signal ( V_87 , F_9 ) ;
signal ( V_88 , F_9 ) ;
V_5 = F_36 ( V_6 , false , NULL ) ;
if ( V_5 == NULL ) {
F_3 ( L_12 ) ;
return - 1 ;
}
V_2 -> V_5 = V_5 ;
F_30 ( V_2 ) ;
if ( V_83 ) {
V_61 = F_37 ( V_2 -> V_19 , & V_44 -> V_50 ,
V_80 , V_6 -> V_89 ,
F_34 ) ;
if ( V_61 < 0 ) {
F_3 ( L_13 ) ;
V_81 = V_61 ;
goto V_90;
}
}
if ( F_11 ( V_2 ) != 0 ) {
V_61 = - 1 ;
goto V_91;
}
if ( ! V_2 -> V_19 -> V_92 )
F_32 ( & V_5 -> V_15 , V_93 ) ;
if ( V_6 -> V_89 ) {
V_61 = F_38 ( V_6 -> V_56 ) ;
if ( V_61 < 0 )
goto V_91;
} else {
V_61 = F_39 ( V_5 , V_2 -> V_19 ,
V_6 -> V_56 , false ) ;
if ( V_61 < 0 )
goto V_91;
}
if ( ! V_2 -> V_69
&& ! F_40 ( & V_5 -> V_15 , V_70 ) ) {
F_3 ( L_14
L_15 ) ;
V_61 = - 1 ;
goto V_91;
}
V_14 = & V_5 -> V_94 . V_95 ;
if ( V_6 -> V_89 ) {
V_61 = F_41 ( V_9 , V_5 ,
F_4 ) ;
if ( V_61 < 0 ) {
F_3 ( L_16 ) ;
goto V_91;
}
if ( F_33 ( & V_2 -> V_19 -> V_71 ) ) {
V_61 = F_42 ( V_9 , V_6 -> V_56 , V_2 -> V_19 ,
F_4 ) ;
if ( V_61 <= 0 ) {
F_3 ( L_17 ) ;
goto V_91;
}
V_2 -> V_7 += V_61 ;
}
}
V_61 = F_28 ( V_9 , F_4 ,
V_14 ) ;
if ( V_61 < 0 )
F_3 ( L_18
L_19
L_20 ) ;
V_61 = F_27 ( V_9 , F_4 ,
V_14 ) ;
if ( V_61 < 0 )
F_3 ( L_21
L_19
L_22 ) ;
if ( V_96 ) {
F_43 ( & V_5 -> V_94 ,
F_26 , V_9 ) ;
}
V_61 = F_44 ( V_14 , V_9 , & V_44 -> V_50 , V_2 -> V_19 -> V_47 ,
F_4 , V_44 -> V_97 ) ;
if ( V_61 != 0 )
goto V_91;
if ( V_2 -> V_98 ) {
struct V_99 V_100 ;
V_100 . V_101 = V_2 -> V_98 ;
if ( F_45 ( 0 , V_102 , & V_100 ) ) {
F_3 ( L_23 ) ;
V_61 = - 1 ;
goto V_91;
}
}
if ( ! F_46 ( & V_44 -> V_50 ) && ! V_44 -> V_103 )
F_47 ( V_2 -> V_19 ) ;
if ( V_83 )
F_48 ( V_2 -> V_19 ) ;
if ( V_44 -> V_103 ) {
F_49 ( V_44 -> V_103 * 1000 ) ;
F_47 ( V_2 -> V_19 ) ;
}
for (; ; ) {
int V_104 = V_2 -> V_29 ;
if ( F_29 ( V_2 ) < 0 ) {
V_61 = - 1 ;
goto V_91;
}
if ( V_104 == V_2 -> V_29 ) {
if ( V_36 || V_85 )
break;
V_61 = F_50 ( V_2 -> V_19 , - 1 ) ;
if ( V_61 > 0 || ( V_61 < 0 && V_48 == V_105 ) )
V_61 = 0 ;
V_82 ++ ;
if ( F_51 ( V_2 -> V_19 , V_106 | V_107 ) == 0 )
V_85 = true ;
}
if ( V_36 && ! V_84 && ! F_46 ( & V_44 -> V_50 ) ) {
F_52 ( V_2 -> V_19 ) ;
V_84 = true ;
}
}
if ( V_83 && V_76 ) {
char V_38 [ V_108 ] ;
const char * V_109 = F_20 ( V_76 , V_38 , sizeof( V_38 ) ) ;
F_3 ( L_24 , V_109 ) ;
V_61 = - 1 ;
goto V_91;
}
if ( ! V_110 ) {
fprintf ( V_111 , L_25 , V_82 ) ;
fprintf ( V_111 ,
L_26 V_112 L_27 ,
( double ) V_2 -> V_7 / 1024.0 / 1024.0 ,
V_6 -> V_113 ,
V_2 -> V_7 / 24 ) ;
}
V_91:
if ( V_83 ) {
int V_114 ;
if ( ! V_34 )
F_53 ( V_2 -> V_19 -> V_115 . V_62 , V_88 ) ;
F_54 ( & V_114 ) ;
if ( V_61 < 0 )
V_81 = V_61 ;
else if ( F_55 ( V_114 ) )
V_81 = F_56 ( V_114 ) ;
else if ( F_57 ( V_114 ) )
V_35 = F_58 ( V_114 ) ;
} else
V_81 = V_61 ;
if ( ! V_61 && ! V_6 -> V_89 ) {
V_2 -> V_5 -> V_15 . V_116 += V_2 -> V_7 ;
if ( ! V_2 -> V_69 )
F_23 ( V_2 ) ;
F_39 ( V_2 -> V_5 , V_2 -> V_19 ,
V_6 -> V_56 , true ) ;
}
V_90:
F_59 ( V_5 ) ;
return V_81 ;
}
static int
F_60 ( const struct V_117 * V_118 , const char * V_119 , int V_120 )
{
#define F_61 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_7 * V_121 = ( T_7 * ) V_118 -> V_122 ;
const struct V_123 * V_124 ;
char * V_125 , * V_126 = NULL , * V_127 ;
int V_128 = - 1 ;
if ( V_120 )
return 0 ;
if ( * V_121 )
return - 1 ;
if ( V_119 ) {
V_125 = V_126 = F_62 ( V_119 ) ;
if ( ! V_125 )
return - 1 ;
for (; ; ) {
V_127 = strchr ( V_125 , ',' ) ;
if ( V_127 )
* V_127 = '\0' ;
for ( V_124 = V_129 ; V_124 -> V_130 ; V_124 ++ ) {
if ( ! strcasecmp ( V_125 , V_124 -> V_130 ) )
break;
}
if ( ! V_124 -> V_130 ) {
F_16 ( L_28
L_29 , V_125 ) ;
goto error;
}
* V_121 |= V_124 -> V_121 ;
if ( ! V_127 )
break;
V_125 = V_127 + 1 ;
}
}
V_128 = 0 ;
if ( ( * V_121 & ~ F_61 ) == 0 ) {
* V_121 = V_131 ;
}
error:
free ( V_126 ) ;
return V_128 ;
}
static void F_63 ( void )
{
static const char * V_119 [ V_132 ] = { L_30 , L_31 , L_32 } ;
F_64 ( L_33 , V_119 [ V_133 . V_134 ] ) ;
if ( V_133 . V_134 == V_135 )
F_64 ( L_34 ,
V_133 . V_136 ) ;
}
int F_65 ( const struct V_117 * V_118 V_13 ,
const char * V_137 ,
int V_120 )
{
int V_128 ;
V_133 . V_138 = ! V_120 ;
if ( V_120 ) {
V_133 . V_134 = V_139 ;
F_64 ( L_35 ) ;
return 0 ;
}
V_128 = F_66 ( V_137 ) ;
if ( ! V_128 )
F_63 () ;
return V_128 ;
}
int F_67 ( const struct V_117 * V_118 V_13 ,
const char * V_137 V_13 ,
int V_120 V_13 )
{
V_133 . V_138 = true ;
if ( V_133 . V_134 == V_139 )
V_133 . V_134 = V_140 ;
F_63 () ;
return 0 ;
}
static int F_68 ( const char * V_141 , const char * V_122 , void * V_142 )
{
if ( ! strcmp ( V_141 , L_36 ) )
V_141 = L_37 ;
return F_69 ( V_141 , V_122 , V_142 ) ;
}
int F_70 ( int V_79 , const char * * V_80 , const char * T_8 V_13 )
{
int V_61 = - V_143 ;
struct V_1 * V_2 = & V_1 ;
char V_144 [ V_145 ] ;
V_2 -> V_19 = F_71 () ;
if ( V_2 -> V_19 == NULL )
return - V_143 ;
F_72 ( F_68 , V_2 ) ;
V_79 = F_73 ( V_79 , V_80 , V_146 , V_147 ,
V_148 ) ;
if ( ! V_79 && F_46 ( & V_2 -> V_44 . V_50 ) )
F_74 ( V_147 , V_146 ) ;
if ( V_149 && ! V_2 -> V_44 . V_50 . V_150 ) {
F_18 ( L_38
L_39 ) ;
F_74 ( V_147 , V_146 ) ;
}
F_75 ( NULL ) ;
if ( V_58 . V_151 )
F_76 (
L_40
L_41
L_42
L_43
L_44
L_45
L_46 ) ;
if ( V_2 -> V_152 || V_2 -> V_69 )
F_77 () ;
if ( V_2 -> V_19 -> V_153 == 0 &&
F_78 ( V_2 -> V_19 ) < 0 ) {
F_3 ( L_47 ) ;
goto V_154;
}
if ( V_2 -> V_44 . V_50 . V_155 && ! V_2 -> V_44 . V_156 )
V_2 -> V_44 . V_157 = true ;
V_61 = F_79 ( & V_2 -> V_44 . V_50 ) ;
if ( V_61 ) {
F_80 ( & V_2 -> V_44 . V_50 , V_61 , V_144 , V_145 ) ;
F_16 ( L_48 , V_144 ) ;
}
V_61 = F_81 ( & V_2 -> V_44 . V_50 ) ;
if ( V_61 ) {
int V_158 = V_48 ;
F_80 ( & V_2 -> V_44 . V_50 , V_61 , V_144 , V_145 ) ;
F_18 ( L_48 , V_144 ) ;
V_61 = - V_158 ;
goto V_154;
}
V_61 = - V_143 ;
if ( F_82 ( V_2 -> V_19 , & V_2 -> V_44 . V_50 ) < 0 )
F_74 ( V_147 , V_146 ) ;
if ( F_83 ( & V_2 -> V_44 ) ) {
V_61 = - V_159 ;
goto V_154;
}
V_61 = F_35 ( & V_1 , V_79 , V_80 ) ;
V_154:
F_84 ( V_2 -> V_19 ) ;
F_85 () ;
return V_61 ;
}
