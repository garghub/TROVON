static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( sizeof( struct V_4 ) ) ;
return V_2 -> V_3 == NULL ? - V_5 : 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
free ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static void F_4 ( struct V_6 * V_6 , T_1 V_7 )
{
double V_8 ;
V_6 -> V_9 ++ ;
V_8 = V_7 - V_6 -> V_10 ;
V_6 -> V_10 += V_8 / V_6 -> V_9 ;
V_6 -> V_11 += V_8 * ( V_7 - V_6 -> V_10 ) ;
}
static double F_5 ( struct V_6 * V_6 )
{
return V_6 -> V_10 ;
}
static double F_6 ( struct V_6 * V_6 )
{
double V_12 , V_13 ;
if ( ! V_6 -> V_9 )
return 0.0 ;
V_12 = V_6 -> V_11 / ( V_6 -> V_9 - 1 ) ;
V_13 = V_12 / V_6 -> V_9 ;
return sqrt ( V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_1 * V_14 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_17 * V_18 = NULL ;
bool V_19 = false ;
int V_20 ;
if ( V_21 && V_2 != V_14 )
V_18 = V_14 -> V_22 ;
if ( V_23 )
V_16 -> V_24 = V_25 |
V_26 ;
V_16 -> V_27 = ! V_28 ;
V_29:
if ( V_19 )
V_2 -> V_16 . V_30 = V_2 -> V_16 . V_31 = 0 ;
if ( V_32 ) {
V_20 = F_8 ( V_2 , V_33 -> V_34 ,
V_21 , V_18 ) ;
if ( V_20 )
goto V_35;
return 0 ;
}
if ( ! V_36 && ! V_37 && ( ! V_21 || V_2 == V_14 ) ) {
V_16 -> V_38 = 1 ;
V_16 -> V_39 = 1 ;
}
V_20 = F_9 ( V_2 , V_33 -> V_40 ,
V_21 , V_18 ) ;
if ( ! V_20 )
return 0 ;
V_35:
if ( V_20 && V_41 == V_42 ) {
if ( ! V_19 &&
( V_2 -> V_16 . V_30 || V_2 -> V_16 . V_31 ) ) {
F_10 ( L_1
L_2 ) ;
V_19 = true ;
goto V_29;
}
}
return V_20 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 , V_43 , V_44 ) ||
F_12 ( V_2 , V_43 , V_45 ) )
return 1 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_46 , T_1 * V_47 )
{
if ( F_12 ( V_46 , V_43 , V_45 ) )
F_4 ( & V_48 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_49 , V_50 ) )
F_4 ( & V_51 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_49 , V_52 ) )
F_4 ( & V_53 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_49 , V_54 ) )
F_4 ( & V_55 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_49 , V_56 ) )
F_4 ( & V_57 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_49 , V_58 ) )
F_4 ( & V_59 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_60 , V_61 ) )
F_4 ( & V_62 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_60 , V_63 ) )
F_4 ( & V_64 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_60 , V_65 ) )
F_4 ( & V_66 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_60 , V_67 ) )
F_4 ( & V_68 [ 0 ] , V_47 [ 0 ] ) ;
else if ( F_12 ( V_46 , V_60 , V_69 ) )
F_4 ( & V_70 [ 0 ] , V_47 [ 0 ] ) ;
}
static int F_14 ( struct V_1 * V_46 )
{
struct V_4 * V_71 = V_46 -> V_3 ;
T_1 * V_47 = V_46 -> V_72 -> V_73 . V_74 ;
int V_75 ;
if ( F_15 ( V_46 , V_33 -> V_34 -> V_76 ,
V_33 -> V_40 -> V_76 , V_23 ) < 0 )
return - 1 ;
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ )
F_4 ( & V_71 -> V_77 [ V_75 ] , V_47 [ V_75 ] ) ;
if ( V_78 ) {
fprintf ( V_79 , L_3 V_80 L_4 V_80 L_4 V_80 L_5 ,
F_16 ( V_46 ) , V_47 [ 0 ] , V_47 [ 1 ] , V_47 [ 2 ] ) ;
}
F_13 ( V_46 , V_47 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_46 )
{
T_1 * V_47 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_33 -> V_34 -> V_76 ; V_81 ++ ) {
if ( F_18 ( V_46 , V_81 , 0 , V_23 ) < 0 )
return - 1 ;
V_47 = V_46 -> V_72 -> V_81 [ V_81 ] . V_74 ;
F_13 ( V_46 , V_47 ) ;
}
return 0 ;
}
static int F_19 ( int T_2 V_82 , const char * * V_83 )
{
unsigned long long V_84 , V_85 ;
struct V_1 * V_46 , * V_14 ;
int V_86 = 0 ;
int V_87 [ 2 ] , V_88 [ 2 ] ;
const bool V_89 = ( T_2 > 0 ) ;
char V_90 ;
if ( V_89 && ( F_20 ( V_87 ) < 0 || F_20 ( V_88 ) < 0 ) ) {
perror ( L_6 ) ;
exit ( 1 ) ;
}
if ( V_89 ) {
if ( ( V_91 = F_21 () ) < 0 )
perror ( L_7 ) ;
if ( ! V_91 ) {
F_22 ( V_87 [ 0 ] ) ;
F_22 ( V_88 [ 1 ] ) ;
F_23 ( V_88 [ 0 ] , V_92 , V_93 ) ;
F_24 ( L_8 , ( char * * ) V_83 ) ;
F_22 ( V_87 [ 1 ] ) ;
if ( F_25 ( V_88 [ 0 ] , & V_90 , 1 ) == - 1 )
perror ( L_9 ) ;
F_24 ( V_83 [ 0 ] , ( char * * ) V_83 ) ;
perror ( V_83 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( ! V_37 && ! V_36 && ! V_32 )
V_33 -> V_40 -> V_94 [ 0 ] = V_91 ;
F_22 ( V_87 [ 1 ] ) ;
F_22 ( V_88 [ 0 ] ) ;
if ( F_25 ( V_87 [ 0 ] , & V_90 , 1 ) == - 1 )
perror ( L_9 ) ;
F_22 ( V_87 [ 0 ] ) ;
}
V_14 = F_26 ( V_33 -> V_95 . V_96 , struct V_1 , V_97 ) ;
F_27 (counter, &evsel_list->entries, node) {
if ( F_7 ( V_46 , V_14 ) < 0 ) {
if ( V_41 == V_42 || V_41 == V_98 ||
V_41 == V_99 || V_41 == V_100 ||
V_41 == V_101 ) {
if ( V_78 )
F_28 ( L_10 ,
F_16 ( V_46 ) ) ;
V_46 -> V_102 = false ;
continue;
}
if ( V_41 == V_103 || V_41 == V_104 ) {
error ( L_11
L_12
L_13 ,
V_32 ? L_14 : L_8 ) ;
} else {
error ( L_15
L_16 ,
V_41 , strerror ( V_41 ) ) ;
}
if ( V_91 != - 1 )
F_29 ( V_91 , V_105 ) ;
F_30 ( L_17 ) ;
return - 1 ;
}
V_46 -> V_102 = true ;
}
if ( F_31 ( V_33 ) ) {
error ( L_18 , V_41 ,
strerror ( V_41 ) ) ;
return - 1 ;
}
V_84 = F_32 () ;
if ( V_89 ) {
F_22 ( V_88 [ 1 ] ) ;
F_33 ( & V_86 ) ;
if ( F_34 ( V_86 ) )
F_35 ( F_36 ( V_86 ) , V_83 [ 0 ] ) ;
} else {
while( ! V_106 ) F_37 ( 1 ) ;
}
V_85 = F_32 () ;
F_4 ( & V_107 , V_85 - V_84 ) ;
if ( V_108 ) {
F_27 (counter, &evsel_list->entries, node) {
F_17 ( V_46 ) ;
F_38 ( V_46 , V_33 -> V_34 -> V_76 , 1 ) ;
}
} else {
F_27 (counter, &evsel_list->entries, node) {
F_14 ( V_46 ) ;
F_38 ( V_46 , V_33 -> V_34 -> V_76 ,
V_33 -> V_40 -> V_76 ) ;
}
}
return F_39 ( V_86 ) ;
}
static void F_40 ( double V_109 , double V_110 )
{
double V_111 = 0.0 ;
if ( V_110 )
V_111 = 100.0 * V_109 / V_110 ;
if ( V_112 )
fprintf ( V_79 , L_19 , V_113 , V_111 ) ;
else if ( V_111 )
fprintf ( V_79 , L_20 , V_111 ) ;
}
static void F_41 ( struct V_1 * V_2 , double V_110 )
{
struct V_4 * V_71 ;
if ( V_114 == 1 )
return;
V_71 = V_2 -> V_3 ;
F_40 ( F_6 ( & V_71 -> V_77 [ 0 ] ) , V_110 ) ;
}
static void F_42 ( int V_81 , struct V_1 * V_2 , double V_110 )
{
double V_115 = V_110 / 1e6 ;
char V_116 [ 16 ] = { '\0' , } ;
const char * V_117 = V_112 ? L_21 : L_22 ;
if ( V_108 )
sprintf ( V_116 , L_23 ,
V_112 ? 0 : - 4 ,
V_33 -> V_34 -> V_94 [ V_81 ] , V_113 ) ;
fprintf ( V_79 , V_117 , V_116 , V_115 , V_113 , F_16 ( V_2 ) ) ;
if ( V_2 -> V_118 )
fprintf ( V_79 , L_24 , V_113 , V_2 -> V_118 -> V_119 ) ;
if ( V_112 )
return;
if ( F_12 ( V_2 , V_43 , V_45 ) )
fprintf ( V_79 , L_25 ,
V_110 / F_5 ( & V_107 ) ) ;
else
fprintf ( V_79 , L_26 ) ;
}
static const char * F_43 ( enum V_120 type , double V_121 )
{
static const double V_122 [ V_123 ] [ 3 ] = {
[ V_124 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_125 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_126 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_127 = V_128 ;
if ( V_121 > V_122 [ type ] [ 0 ] )
V_127 = V_129 ;
else if ( V_121 > V_122 [ type ] [ 1 ] )
V_127 = V_130 ;
else if ( V_121 > V_122 [ type ] [ 2 ] )
V_127 = V_131 ;
return V_127 ;
}
static void F_44 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_51 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_124 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_29 ) ;
}
static void F_46 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_51 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_125 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_30 ) ;
}
static void F_47 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_57 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_126 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_31 ) ;
}
static void F_48 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_62 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_126 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_32 ) ;
}
static void F_49 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_64 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_126 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_33 ) ;
}
static void F_50 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_68 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_126 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_34 ) ;
}
static void F_51 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_70 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_126 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_35 ) ;
}
static void F_52 ( int V_81 , struct V_1 * V_2 V_82 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
const char * V_127 ;
V_109 = F_5 ( & V_66 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 * 100.0 ;
V_127 = F_43 ( V_126 , V_121 ) ;
fprintf ( V_79 , L_27 ) ;
F_45 ( V_79 , V_127 , L_28 , V_121 ) ;
fprintf ( V_79 , L_36 ) ;
}
static void F_53 ( int V_81 , struct V_1 * V_2 , double V_110 )
{
double V_109 , V_121 = 0.0 ;
char V_116 [ 16 ] = { '\0' , } ;
const char * V_117 ;
if ( V_112 )
V_117 = L_37 ;
else if ( V_132 )
V_117 = L_38 ;
else
V_117 = L_39 ;
if ( V_108 )
sprintf ( V_116 , L_23 ,
V_112 ? 0 : - 4 ,
V_33 -> V_34 -> V_94 [ V_81 ] , V_113 ) ;
else
V_81 = 0 ;
fprintf ( V_79 , V_117 , V_116 , V_110 , V_113 , F_16 ( V_2 ) ) ;
if ( V_2 -> V_118 )
fprintf ( V_79 , L_24 , V_113 , V_2 -> V_118 -> V_119 ) ;
if ( V_112 )
return;
if ( F_12 ( V_2 , V_49 , V_133 ) ) {
V_109 = F_5 ( & V_51 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 / V_109 ;
fprintf ( V_79 , L_40 , V_121 ) ;
V_109 = F_5 ( & V_53 [ V_81 ] ) ;
V_109 = F_54 ( V_109 , F_5 ( & V_55 [ V_81 ] ) ) ;
if ( V_109 && V_110 ) {
V_121 = V_109 / V_110 ;
fprintf ( V_79 , L_41 , V_121 ) ;
}
} else if ( F_12 ( V_2 , V_49 , V_134 ) &&
V_57 [ V_81 ] . V_9 != 0 ) {
F_47 ( V_81 , V_2 , V_110 ) ;
} else if (
V_2 -> V_16 . type == V_135 &&
V_2 -> V_16 . V_136 == ( V_137 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) &&
V_62 [ V_81 ] . V_9 != 0 ) {
F_48 ( V_81 , V_2 , V_110 ) ;
} else if (
V_2 -> V_16 . type == V_135 &&
V_2 -> V_16 . V_136 == ( V_140 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) &&
V_64 [ V_81 ] . V_9 != 0 ) {
F_49 ( V_81 , V_2 , V_110 ) ;
} else if (
V_2 -> V_16 . type == V_135 &&
V_2 -> V_16 . V_136 == ( V_141 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) &&
V_68 [ V_81 ] . V_9 != 0 ) {
F_50 ( V_81 , V_2 , V_110 ) ;
} else if (
V_2 -> V_16 . type == V_135 &&
V_2 -> V_16 . V_136 == ( V_142 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) &&
V_70 [ V_81 ] . V_9 != 0 ) {
F_51 ( V_81 , V_2 , V_110 ) ;
} else if (
V_2 -> V_16 . type == V_135 &&
V_2 -> V_16 . V_136 == ( V_143 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) &&
V_66 [ V_81 ] . V_9 != 0 ) {
F_52 ( V_81 , V_2 , V_110 ) ;
} else if ( F_12 ( V_2 , V_49 , V_144 ) &&
V_59 [ V_81 ] . V_9 != 0 ) {
V_109 = F_5 ( & V_59 [ V_81 ] ) ;
if ( V_109 )
V_121 = V_110 * 100 / V_109 ;
fprintf ( V_79 , L_42 , V_121 ) ;
} else if ( F_12 ( V_2 , V_49 , V_52 ) ) {
F_44 ( V_81 , V_2 , V_110 ) ;
} else if ( F_12 ( V_2 , V_49 , V_54 ) ) {
F_46 ( V_81 , V_2 , V_110 ) ;
} else if ( F_12 ( V_2 , V_49 , V_50 ) ) {
V_109 = F_5 ( & V_48 [ V_81 ] ) ;
if ( V_109 )
V_121 = 1.0 * V_110 / V_109 ;
fprintf ( V_79 , L_43 , V_121 ) ;
} else if ( V_48 [ V_81 ] . V_9 != 0 ) {
char V_145 = 'M' ;
V_109 = F_5 ( & V_48 [ V_81 ] ) ;
if ( V_109 )
V_121 = 1000.0 * V_110 / V_109 ;
if ( V_121 < 0.001 ) {
V_121 *= 1000 ;
V_145 = 'K' ;
}
fprintf ( V_79 , L_44 , V_121 , V_145 ) ;
} else {
fprintf ( V_79 , L_26 ) ;
}
}
static void F_55 ( struct V_1 * V_46 )
{
struct V_4 * V_71 = V_46 -> V_3 ;
double V_110 = F_5 ( & V_71 -> V_77 [ 0 ] ) ;
int V_146 = V_46 -> V_72 -> V_146 ;
if ( V_146 == - 1 ) {
fprintf ( V_79 , L_45 ,
V_112 ? 0 : 18 ,
V_46 -> V_102 ? V_147 : V_148 ,
V_113 ,
V_112 ? 0 : - 24 ,
F_16 ( V_46 ) ) ;
if ( V_46 -> V_118 )
fprintf ( V_79 , L_24 , V_113 , V_46 -> V_118 -> V_119 ) ;
fputc ( '\n' , V_79 ) ;
return;
}
if ( F_11 ( V_46 ) )
F_42 ( - 1 , V_46 , V_110 ) ;
else
F_53 ( - 1 , V_46 , V_110 ) ;
F_41 ( V_46 , V_110 ) ;
if ( V_112 ) {
fputc ( '\n' , V_79 ) ;
return;
}
if ( V_146 ) {
double V_149 , V_150 ;
V_149 = F_5 ( & V_71 -> V_77 [ 1 ] ) ;
V_150 = F_5 ( & V_71 -> V_77 [ 2 ] ) ;
fprintf ( V_79 , L_46 , 100 * V_150 / V_149 ) ;
}
fprintf ( V_79 , L_5 ) ;
}
static void F_56 ( struct V_1 * V_46 )
{
T_1 V_151 , V_152 , V_7 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_33 -> V_34 -> V_76 ; V_81 ++ ) {
V_7 = V_46 -> V_72 -> V_81 [ V_81 ] . V_7 ;
V_151 = V_46 -> V_72 -> V_81 [ V_81 ] . V_151 ;
V_152 = V_46 -> V_72 -> V_81 [ V_81 ] . V_152 ;
if ( V_152 == 0 || V_151 == 0 ) {
fprintf ( V_79 , L_47 ,
V_112 ? 0 : - 4 ,
V_33 -> V_34 -> V_94 [ V_81 ] , V_113 ,
V_112 ? 0 : 18 ,
V_46 -> V_102 ? V_147 : V_148 ,
V_113 ,
V_112 ? 0 : - 24 ,
F_16 ( V_46 ) ) ;
if ( V_46 -> V_118 )
fprintf ( V_79 , L_24 ,
V_113 , V_46 -> V_118 -> V_119 ) ;
fputc ( '\n' , V_79 ) ;
continue;
}
if ( F_11 ( V_46 ) )
F_42 ( V_81 , V_46 , V_7 ) ;
else
F_53 ( V_81 , V_46 , V_7 ) ;
if ( ! V_112 ) {
F_41 ( V_46 , 1.0 ) ;
if ( V_152 != V_151 )
fprintf ( V_79 , L_48 ,
100.0 * V_152 / V_151 ) ;
}
fputc ( '\n' , V_79 ) ;
}
}
static void F_57 ( int T_2 , const char * * V_83 )
{
struct V_1 * V_46 ;
int V_75 ;
fflush ( stdout ) ;
if ( ! V_112 ) {
fprintf ( V_79 , L_5 ) ;
fprintf ( V_79 , L_49 ) ;
if ( ! V_36 && ! V_37 ) {
fprintf ( V_79 , L_50 , V_83 [ 0 ] ) ;
for ( V_75 = 1 ; V_75 < T_2 ; V_75 ++ )
fprintf ( V_79 , L_51 , V_83 [ V_75 ] ) ;
} else if ( V_36 )
fprintf ( V_79 , L_52 , V_36 ) ;
else
fprintf ( V_79 , L_53 , V_37 ) ;
fprintf ( V_79 , L_54 ) ;
if ( V_114 > 1 )
fprintf ( V_79 , L_55 , V_114 ) ;
fprintf ( V_79 , L_56 ) ;
}
if ( V_108 ) {
F_27 (counter, &evsel_list->entries, node)
F_56 ( V_46 ) ;
} else {
F_27 (counter, &evsel_list->entries, node)
F_55 ( V_46 ) ;
}
if ( ! V_112 ) {
if ( ! V_153 )
fprintf ( V_79 , L_5 ) ;
fprintf ( V_79 , L_57 ,
F_5 ( & V_107 ) / 1e9 ) ;
if ( V_114 > 1 ) {
fprintf ( V_79 , L_58 ) ;
F_40 ( F_6 ( & V_107 ) ,
F_5 ( & V_107 ) ) ;
}
fprintf ( V_79 , L_59 ) ;
}
}
static void F_58 ( int V_154 )
{
if( V_91 == - 1 )
V_106 = 1 ;
V_155 = V_154 ;
}
static void F_59 ( void )
{
if ( V_91 != - 1 )
F_29 ( V_91 , V_105 ) ;
if ( V_155 == - 1 )
return;
signal ( V_155 , V_156 ) ;
F_29 ( F_60 () , V_155 ) ;
}
static int F_61 ( const struct V_157 * T_3 V_82 ,
const char * T_4 V_82 , int V_158 )
{
V_159 = V_158 ? 0 : 1 ;
return 0 ;
}
static int F_62 ( void )
{
if ( V_153 )
return 0 ;
if ( ! V_33 -> V_160 ) {
if ( F_63 ( V_33 , V_161 ) < 0 )
return - 1 ;
}
if ( V_162 < 1 )
return 0 ;
if ( F_63 ( V_33 , V_163 ) < 0 )
return - 1 ;
if ( V_162 < 2 )
return 0 ;
if ( F_63 ( V_33 , V_164 ) < 0 )
return - 1 ;
if ( V_162 < 3 )
return 0 ;
return F_63 ( V_33 , V_165 ) ;
}
int F_64 ( int T_2 , const char * * V_83 , const char * T_5 V_82 )
{
struct V_1 * V_166 ;
int V_86 = - V_5 ;
const char * V_167 ;
setlocale ( V_168 , L_8 ) ;
V_33 = F_65 ( NULL , NULL ) ;
if ( V_33 == NULL )
return - V_5 ;
T_2 = F_66 ( T_2 , V_83 , V_169 , V_170 ,
V_171 ) ;
V_79 = V_172 ;
if ( V_173 && strcmp ( V_173 , L_60 ) )
V_79 = NULL ;
if ( V_173 && V_174 ) {
fprintf ( V_172 , L_61 ) ;
F_67 ( V_170 , V_169 ) ;
}
if ( ! V_79 ) {
struct V_175 V_176 ;
V_167 = V_177 ? L_62 : L_63 ;
V_79 = fopen ( V_173 , V_167 ) ;
if ( ! V_79 ) {
perror ( L_64 ) ;
exit ( - 1 ) ;
}
F_68 ( V_178 , & V_176 ) ;
fprintf ( V_79 , L_65 , ctime ( & V_176 . V_179 ) ) ;
} else if ( V_174 != 2 ) {
V_167 = V_177 ? L_62 : L_63 ;
V_79 = fdopen ( V_174 , V_167 ) ;
if ( ! V_79 ) {
perror ( L_66 ) ;
return - V_41 ;
}
}
if ( V_113 ) {
V_112 = true ;
if ( ! strcmp ( V_113 , L_67 ) )
V_113 = L_68 ;
} else
V_113 = V_180 ;
if ( V_112 ) {
if ( V_159 == 1 ) {
fprintf ( V_172 , L_69 ) ;
F_67 ( V_170 , V_169 ) ;
} else
V_132 = false ;
} else if ( V_159 == 0 )
V_132 = false ;
if ( ! T_2 && ! V_36 && ! V_37 )
F_67 ( V_170 , V_169 ) ;
if ( V_114 <= 0 )
F_67 ( V_170 , V_169 ) ;
if ( ( V_108 || V_181 ) && ! V_32 ) {
fprintf ( V_172 , L_70
L_71 ) ;
F_67 ( V_170 , V_169 ) ;
}
if ( F_62 () )
goto V_182;
if ( V_36 )
V_37 = V_36 ;
V_33 -> V_40 = F_69 ( V_36 ,
V_37 , V_183 ) ;
if ( V_33 -> V_40 == NULL ) {
F_70 ( L_72 ) ;
F_67 ( V_170 , V_169 ) ;
}
if ( V_32 )
V_33 -> V_34 = F_71 ( V_184 ) ;
else
V_33 -> V_34 = F_72 () ;
if ( V_33 -> V_34 == NULL ) {
perror ( L_73 ) ;
F_67 ( V_170 , V_169 ) ;
return - 1 ;
}
F_27 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_166 ) < 0 ||
F_73 ( V_166 , V_33 -> V_34 -> V_76 ) < 0 )
goto V_185;
}
atexit ( F_59 ) ;
signal ( V_186 , F_58 ) ;
signal ( V_187 , F_58 ) ;
signal ( V_188 , F_58 ) ;
V_86 = 0 ;
for ( V_189 = 0 ; V_189 < V_114 ; V_189 ++ ) {
if ( V_114 != 1 && V_78 )
fprintf ( V_79 , L_74 ,
V_189 + 1 ) ;
if ( V_190 )
F_74 () ;
V_86 = F_19 ( T_2 , V_83 ) ;
}
if ( V_86 != - 1 )
F_57 ( T_2 , V_83 ) ;
V_185:
F_27 (pos, &evsel_list->entries, node)
F_3 ( V_166 ) ;
F_75 ( V_33 ) ;
V_182:
F_76 ( V_33 ) ;
return V_86 ;
}
