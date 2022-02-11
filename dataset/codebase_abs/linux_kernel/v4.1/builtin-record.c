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
T_3 V_21 = F_7 ( V_18 ) ;
T_3 V_22 = V_18 -> V_23 ;
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
if ( F_19 ( V_19 , & V_40 ) ) {
error ( L_3 ,
V_40 -> V_51 , F_20 ( V_40 ) , V_48 ,
F_21 ( V_48 , V_38 , sizeof( V_38 ) ) ) ;
V_28 = - 1 ;
goto V_31;
}
if ( F_22 ( V_19 , V_44 -> V_52 , false ) < 0 ) {
if ( V_48 == V_53 ) {
F_3 ( L_4
L_5
L_6
L_7
L_8 , V_44 -> V_52 ) ;
V_28 = - V_48 ;
} else {
F_3 ( L_9 , V_48 ,
F_21 ( V_48 , V_38 , sizeof( V_38 ) ) ) ;
V_28 = - V_48 ;
}
goto V_31;
}
V_5 -> V_19 = V_19 ;
F_23 ( V_5 ) ;
V_31:
return V_28 ;
}
static int F_24 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_39 * V_54 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_29 ++ ;
return F_25 ( V_9 , V_11 , T_2 , V_54 , V_14 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_55 * V_6 = & V_2 -> V_6 ;
struct V_42 * V_5 = V_2 -> V_5 ;
T_3 V_4 = F_27 ( F_28 ( V_6 ) , 0 , V_56 ) ;
if ( V_4 == 0 )
return 0 ;
V_6 -> V_4 = V_4 ;
V_57 . V_58 = true ;
return F_29 ( V_5 ) ;
}
static void F_30 ( struct V_14 * V_14 , void * V_24 )
{
int V_59 ;
struct V_8 * V_9 = V_24 ;
V_59 = F_31 ( V_9 , F_4 ,
V_14 ) ;
if ( V_59 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_60 ) ;
V_59 = F_32 ( V_9 , F_4 ,
V_14 ) ;
if ( V_59 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_60 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_61 ;
int V_28 = 0 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_19 -> V_62 ; V_61 ++ ) {
if ( V_2 -> V_19 -> V_20 [ V_61 ] . V_25 ) {
if ( F_6 ( V_2 , V_61 ) != 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
}
if ( V_7 != V_2 -> V_7 )
V_28 = F_1 ( V_2 , & V_63 , sizeof( V_63 ) ) ;
V_31:
return V_28 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_42 * V_5 = V_2 -> V_5 ;
int V_64 ;
for ( V_64 = V_65 ; V_64 < V_66 ; V_64 ++ )
F_35 ( & V_5 -> V_15 , V_64 ) ;
if ( V_2 -> V_67 )
F_36 ( & V_5 -> V_15 , V_68 ) ;
if ( ! F_37 ( & V_2 -> V_19 -> V_69 ) )
F_36 ( & V_5 -> V_15 , V_70 ) ;
if ( ! V_2 -> V_44 . V_71 )
F_36 ( & V_5 -> V_15 , V_72 ) ;
}
static void F_38 ( int T_4 V_13 ,
T_5 * V_73 ,
void * T_6 V_13 )
{
V_74 = V_73 -> V_75 . V_76 ;
V_36 = 1 ;
V_34 = 1 ;
}
static int F_39 ( struct V_1 * V_2 , int V_77 , const char * * V_78 )
{
int V_59 ;
int V_79 = 0 ;
unsigned long V_80 = 0 ;
const bool V_81 = V_77 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_43 * V_44 = & V_2 -> V_44 ;
struct V_55 * V_6 = & V_2 -> V_6 ;
struct V_42 * V_5 ;
bool V_82 = false , V_83 = false ;
int V_84 ;
V_2 -> V_85 = V_78 [ 0 ] ;
atexit ( F_10 ) ;
signal ( V_33 , F_9 ) ;
signal ( V_86 , F_9 ) ;
signal ( V_87 , F_9 ) ;
V_5 = F_40 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_12 ) ;
return - 1 ;
}
V_84 = F_28 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_34 ( V_2 ) ;
if ( V_81 ) {
V_59 = F_41 ( V_2 -> V_19 , & V_44 -> V_50 ,
V_78 , V_6 -> V_88 ,
F_38 ) ;
if ( V_59 < 0 ) {
F_3 ( L_13 ) ;
V_79 = V_59 ;
goto V_89;
}
}
if ( F_11 ( V_2 ) != 0 ) {
V_59 = - 1 ;
goto V_90;
}
if ( ! V_2 -> V_19 -> V_91 )
F_36 ( & V_5 -> V_15 , V_92 ) ;
if ( V_6 -> V_88 ) {
V_59 = F_42 ( V_84 ) ;
if ( V_59 < 0 )
goto V_90;
} else {
V_59 = F_43 ( V_5 , V_2 -> V_19 , V_84 , false ) ;
if ( V_59 < 0 )
goto V_90;
}
if ( ! V_2 -> V_67
&& ! F_44 ( & V_5 -> V_15 , V_68 ) ) {
F_3 ( L_14
L_15 ) ;
V_59 = - 1 ;
goto V_90;
}
V_14 = & V_5 -> V_93 . V_94 ;
if ( V_6 -> V_88 ) {
V_59 = F_45 ( V_9 , V_5 ,
F_4 ) ;
if ( V_59 < 0 ) {
F_3 ( L_16 ) ;
goto V_90;
}
if ( F_37 ( & V_2 -> V_19 -> V_69 ) ) {
V_59 = F_46 ( V_9 , V_84 , V_2 -> V_19 ,
F_4 ) ;
if ( V_59 <= 0 ) {
F_3 ( L_17 ) ;
goto V_90;
}
V_2 -> V_7 += V_59 ;
}
}
V_59 = F_32 ( V_9 , F_4 ,
V_14 ) ;
if ( V_59 < 0 )
F_3 ( L_18
L_19
L_20 ) ;
V_59 = F_31 ( V_9 , F_4 ,
V_14 ) ;
if ( V_59 < 0 )
F_3 ( L_21
L_19
L_22 ) ;
if ( V_95 ) {
F_47 ( & V_5 -> V_93 ,
F_30 , V_9 ) ;
}
V_59 = F_48 ( V_14 , V_9 , & V_44 -> V_50 , V_2 -> V_19 -> V_47 ,
F_4 , V_44 -> V_96 ) ;
if ( V_59 != 0 )
goto V_90;
if ( V_2 -> V_97 ) {
struct V_98 V_99 ;
V_99 . V_100 = V_2 -> V_97 ;
if ( F_49 ( 0 , V_101 , & V_99 ) ) {
F_3 ( L_23 ) ;
V_59 = - 1 ;
goto V_90;
}
}
if ( ! F_50 ( & V_44 -> V_50 ) && ! V_44 -> V_102 )
F_51 ( V_2 -> V_19 ) ;
if ( V_81 )
F_52 ( V_2 -> V_19 ) ;
if ( V_44 -> V_102 ) {
F_53 ( V_44 -> V_102 * 1000 ) ;
F_51 ( V_2 -> V_19 ) ;
}
for (; ; ) {
int V_103 = V_2 -> V_29 ;
if ( F_33 ( V_2 ) < 0 ) {
V_59 = - 1 ;
goto V_90;
}
if ( V_103 == V_2 -> V_29 ) {
if ( V_36 || V_83 )
break;
V_59 = F_54 ( V_2 -> V_19 , - 1 ) ;
if ( V_59 > 0 || ( V_59 < 0 && V_48 == V_104 ) )
V_59 = 0 ;
V_80 ++ ;
if ( F_55 ( V_2 -> V_19 , V_105 | V_106 ) == 0 )
V_83 = true ;
}
if ( V_36 && ! V_82 && ! F_50 ( & V_44 -> V_50 ) ) {
F_56 ( V_2 -> V_19 ) ;
V_82 = true ;
}
}
if ( V_81 && V_74 ) {
char V_38 [ V_107 ] ;
const char * V_108 = F_21 ( V_74 , V_38 , sizeof( V_38 ) ) ;
F_3 ( L_24 , V_108 ) ;
V_59 = - 1 ;
goto V_90;
}
if ( ! V_109 )
fprintf ( V_110 , L_25 , V_80 ) ;
V_90:
if ( V_81 ) {
int V_111 ;
if ( ! V_34 )
F_57 ( V_2 -> V_19 -> V_112 . V_60 , V_87 ) ;
F_58 ( & V_111 ) ;
if ( V_59 < 0 )
V_79 = V_59 ;
else if ( F_59 ( V_111 ) )
V_79 = F_60 ( V_111 ) ;
else if ( F_61 ( V_111 ) )
V_35 = F_62 ( V_111 ) ;
} else
V_79 = V_59 ;
V_2 -> V_29 = 0 ;
if ( ! V_59 && ! V_6 -> V_88 ) {
V_2 -> V_5 -> V_15 . V_113 += V_2 -> V_7 ;
if ( ! V_2 -> V_67 )
F_26 ( V_2 ) ;
F_43 ( V_2 -> V_5 , V_2 -> V_19 , V_84 , true ) ;
}
if ( ! V_59 && ! V_109 ) {
char V_29 [ 128 ] ;
if ( V_2 -> V_29 )
F_63 ( V_29 , sizeof( V_29 ) ,
L_26 V_114 L_27 , V_2 -> V_29 ) ;
else
V_29 [ 0 ] = '\0' ;
fprintf ( V_110 , L_28 ,
F_64 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_115 , V_29 ) ;
}
V_89:
F_65 ( V_5 ) ;
return V_79 ;
}
static int
F_66 ( const struct V_116 * V_117 , const char * V_118 , int V_119 )
{
#define F_67 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_7 * V_120 = ( T_7 * ) V_117 -> V_121 ;
const struct V_122 * V_123 ;
char * V_124 , * V_125 = NULL , * V_126 ;
int V_127 = - 1 ;
if ( V_119 )
return 0 ;
if ( * V_120 )
return - 1 ;
if ( V_118 ) {
V_124 = V_125 = F_68 ( V_118 ) ;
if ( ! V_124 )
return - 1 ;
for (; ; ) {
V_126 = strchr ( V_124 , ',' ) ;
if ( V_126 )
* V_126 = '\0' ;
for ( V_123 = V_128 ; V_123 -> V_129 ; V_123 ++ ) {
if ( ! strcasecmp ( V_124 , V_123 -> V_129 ) )
break;
}
if ( ! V_123 -> V_129 ) {
F_16 ( L_29
L_30 , V_124 ) ;
goto error;
}
* V_120 |= V_123 -> V_120 ;
if ( ! V_126 )
break;
V_124 = V_126 + 1 ;
}
}
V_127 = 0 ;
if ( ( * V_120 & ~ F_67 ) == 0 ) {
* V_120 = V_130 ;
}
error:
free ( V_125 ) ;
return V_127 ;
}
static void F_69 ( void )
{
static const char * V_118 [ V_131 ] = { L_31 , L_32 , L_33 , L_34 } ;
F_70 ( L_35 , V_118 [ V_132 . V_133 ] ) ;
if ( V_132 . V_133 == V_134 )
F_70 ( L_36 ,
V_132 . V_135 ) ;
}
int F_71 ( const struct V_116 * V_117 V_13 ,
const char * V_136 ,
int V_119 )
{
int V_127 ;
V_132 . V_137 = ! V_119 ;
if ( V_119 ) {
V_132 . V_133 = V_138 ;
F_70 ( L_37 ) ;
return 0 ;
}
V_127 = F_72 ( V_136 ) ;
if ( ! V_127 )
F_69 () ;
return V_127 ;
}
int F_73 ( const struct V_116 * V_117 V_13 ,
const char * V_136 V_13 ,
int V_119 V_13 )
{
V_132 . V_137 = true ;
if ( V_132 . V_133 == V_138 )
V_132 . V_133 = V_139 ;
F_69 () ;
return 0 ;
}
static int F_74 ( const char * V_140 , const char * V_121 , void * V_141 )
{
if ( ! strcmp ( V_140 , L_38 ) )
V_140 = L_39 ;
return F_75 ( V_140 , V_121 , V_141 ) ;
}
static int F_76 ( const struct V_116 * V_117 , const char * V_118 , int V_119 )
{
struct V_43 * V_44 = (struct V_43 * ) V_117 -> V_121 ;
const struct V_142 * V_143 ;
const char * V_144 = V_118 ;
if ( V_119 ) {
V_44 -> V_145 = 0 ;
return 0 ;
}
if ( ! V_118 )
return 0 ;
if ( V_44 -> V_145 )
return - 1 ;
V_44 -> V_145 = true ;
if ( sscanf ( V_118 , L_40 , & V_44 -> V_146 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_118 , L_41 , 6 ) )
V_118 += 6 ;
for ( V_143 = V_147 ; V_143 -> V_129 ; V_143 ++ ) {
if ( ! strcasecmp ( V_118 , V_143 -> V_129 ) ) {
V_44 -> V_146 = V_143 -> V_146 ;
return 0 ;
}
}
V_44 -> V_145 = false ;
F_16 ( L_42 , V_144 ) ;
return - 1 ;
}
int F_77 ( int V_77 , const char * * V_78 , const char * T_8 V_13 )
{
int V_59 = - V_148 ;
struct V_1 * V_2 = & V_1 ;
char V_149 [ V_150 ] ;
V_2 -> V_19 = F_78 () ;
if ( V_2 -> V_19 == NULL )
return - V_148 ;
F_79 ( F_74 , V_2 ) ;
V_77 = F_80 ( V_77 , V_78 , V_151 , V_152 ,
V_153 ) ;
if ( ! V_77 && F_50 ( & V_2 -> V_44 . V_50 ) )
F_81 ( V_152 , V_151 ) ;
if ( V_154 && ! V_2 -> V_44 . V_50 . V_155 ) {
F_18 ( L_43
L_44 ) ;
F_81 ( V_152 , V_151 ) ;
}
F_82 ( NULL ) ;
if ( V_57 . V_156 )
F_83 (
L_45
L_46
L_47
L_48
L_49
L_50
L_51 ) ;
if ( V_2 -> V_157 || V_2 -> V_67 )
F_84 () ;
if ( V_2 -> V_19 -> V_158 == 0 &&
F_85 ( V_2 -> V_19 ) < 0 ) {
F_3 ( L_52 ) ;
goto V_159;
}
if ( V_2 -> V_44 . V_50 . V_160 && ! V_2 -> V_44 . V_161 )
V_2 -> V_44 . V_162 = true ;
V_59 = F_86 ( & V_2 -> V_44 . V_50 ) ;
if ( V_59 ) {
F_87 ( & V_2 -> V_44 . V_50 , V_59 , V_149 , V_150 ) ;
F_16 ( L_53 , V_149 ) ;
}
V_59 = F_88 ( & V_2 -> V_44 . V_50 ) ;
if ( V_59 ) {
int V_163 = V_48 ;
F_87 ( & V_2 -> V_44 . V_50 , V_59 , V_149 , V_150 ) ;
F_18 ( L_53 , V_149 ) ;
V_59 = - V_163 ;
goto V_159;
}
V_59 = - V_148 ;
if ( F_89 ( V_2 -> V_19 , & V_2 -> V_44 . V_50 ) < 0 )
F_81 ( V_152 , V_151 ) ;
if ( F_90 ( & V_2 -> V_44 ) ) {
V_59 = - V_164 ;
goto V_159;
}
V_59 = F_39 ( & V_1 , V_77 , V_78 ) ;
V_159:
F_91 ( V_2 -> V_19 ) ;
F_92 () ;
return V_59 ;
}
