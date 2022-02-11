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
if ( F_8 ( & V_32 ) ) {
V_20 = F_9 ( V_2 , V_33 -> V_34 ,
V_21 , V_18 ) ;
if ( V_20 )
goto V_35;
return 0 ;
}
if ( ! F_10 ( & V_32 ) && ( ! V_21 || V_2 == V_14 ) ) {
V_16 -> V_36 = 1 ;
V_16 -> V_37 = 1 ;
}
V_20 = F_11 ( V_2 , V_33 -> V_38 ,
V_21 , V_18 ) ;
if ( ! V_20 )
return 0 ;
V_35:
if ( V_20 && V_39 == V_40 ) {
if ( ! V_19 &&
( V_2 -> V_16 . V_30 || V_2 -> V_16 . V_31 ) ) {
F_12 ( L_1
L_2 ) ;
V_19 = true ;
goto V_29;
}
}
return V_20 ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 , V_41 , V_42 ) ||
F_14 ( V_2 , V_41 , V_43 ) )
return 1 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_44 , T_1 * V_45 )
{
if ( F_14 ( V_44 , V_41 , V_43 ) )
F_4 ( & V_46 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_47 , V_48 ) )
F_4 ( & V_49 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_47 , V_50 ) )
F_4 ( & V_51 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_47 , V_52 ) )
F_4 ( & V_53 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_47 , V_54 ) )
F_4 ( & V_55 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_47 , V_56 ) )
F_4 ( & V_57 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_58 , V_59 ) )
F_4 ( & V_60 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_58 , V_61 ) )
F_4 ( & V_62 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_58 , V_63 ) )
F_4 ( & V_64 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_58 , V_65 ) )
F_4 ( & V_66 [ 0 ] , V_45 [ 0 ] ) ;
else if ( F_14 ( V_44 , V_58 , V_67 ) )
F_4 ( & V_68 [ 0 ] , V_45 [ 0 ] ) ;
}
static int F_16 ( struct V_1 * V_44 )
{
struct V_4 * V_69 = V_44 -> V_3 ;
T_1 * V_45 = V_44 -> V_70 -> V_71 . V_72 ;
int V_73 ;
if ( F_17 ( V_44 , V_33 -> V_34 -> V_74 ,
V_33 -> V_38 -> V_74 , V_23 ) < 0 )
return - 1 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ )
F_4 ( & V_69 -> V_75 [ V_73 ] , V_45 [ V_73 ] ) ;
if ( V_76 ) {
fprintf ( V_77 , L_3 V_78 L_4 V_78 L_4 V_78 L_5 ,
F_18 ( V_44 ) , V_45 [ 0 ] , V_45 [ 1 ] , V_45 [ 2 ] ) ;
}
F_15 ( V_44 , V_45 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_44 )
{
T_1 * V_45 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_33 -> V_34 -> V_74 ; V_79 ++ ) {
if ( F_20 ( V_44 , V_79 , 0 , V_23 ) < 0 )
return - 1 ;
V_45 = V_44 -> V_70 -> V_79 [ V_79 ] . V_72 ;
F_15 ( V_44 , V_45 ) ;
}
return 0 ;
}
static int F_21 ( int T_2 V_80 , const char * * V_81 )
{
unsigned long long V_82 , V_83 ;
struct V_1 * V_44 , * V_14 ;
int V_84 = 0 ;
int V_85 [ 2 ] , V_86 [ 2 ] ;
const bool V_87 = ( T_2 > 0 ) ;
char V_88 ;
if ( V_87 && ( F_22 ( V_85 ) < 0 || F_22 ( V_86 ) < 0 ) ) {
perror ( L_6 ) ;
exit ( 1 ) ;
}
if ( V_87 ) {
if ( ( V_89 = F_23 () ) < 0 )
perror ( L_7 ) ;
if ( ! V_89 ) {
F_24 ( V_85 [ 0 ] ) ;
F_24 ( V_86 [ 1 ] ) ;
F_25 ( V_86 [ 0 ] , V_90 , V_91 ) ;
F_26 ( L_8 , ( char * * ) V_81 ) ;
F_24 ( V_85 [ 1 ] ) ;
if ( F_27 ( V_86 [ 0 ] , & V_88 , 1 ) == - 1 )
perror ( L_9 ) ;
F_26 ( V_81 [ 0 ] , ( char * * ) V_81 ) ;
perror ( V_81 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_28 ( & V_32 ) )
V_33 -> V_38 -> V_92 [ 0 ] = V_89 ;
F_24 ( V_85 [ 1 ] ) ;
F_24 ( V_86 [ 0 ] ) ;
if ( F_27 ( V_85 [ 0 ] , & V_88 , 1 ) == - 1 )
perror ( L_9 ) ;
F_24 ( V_85 [ 0 ] ) ;
}
V_14 = F_29 ( V_33 -> V_93 . V_94 , struct V_1 , V_95 ) ;
F_30 (counter, &evsel_list->entries, node) {
if ( F_7 ( V_44 , V_14 ) < 0 ) {
if ( V_39 == V_40 || V_39 == V_96 ||
V_39 == V_97 || V_39 == V_98 ||
V_39 == V_99 ) {
if ( V_76 )
F_31 ( L_10 ,
F_18 ( V_44 ) ) ;
V_44 -> V_100 = false ;
continue;
}
if ( V_39 == V_101 || V_39 == V_102 ) {
error ( L_11
L_12
L_13 ,
V_32 . V_103 ? L_14 : L_8 ) ;
} else {
error ( L_15
L_16 ,
V_39 , strerror ( V_39 ) ) ;
}
if ( V_89 != - 1 )
F_32 ( V_89 , V_104 ) ;
F_33 ( L_17 ) ;
return - 1 ;
}
V_44 -> V_100 = true ;
}
if ( F_34 ( V_33 ) ) {
error ( L_18 , V_39 ,
strerror ( V_39 ) ) ;
return - 1 ;
}
V_82 = F_35 () ;
if ( V_87 ) {
F_24 ( V_86 [ 1 ] ) ;
F_36 ( & V_84 ) ;
if ( F_37 ( V_84 ) )
F_38 ( F_39 ( V_84 ) , V_81 [ 0 ] ) ;
} else {
while( ! V_105 ) F_40 ( 1 ) ;
}
V_83 = F_35 () ;
F_4 ( & V_106 , V_83 - V_82 ) ;
if ( V_107 ) {
F_30 (counter, &evsel_list->entries, node) {
F_19 ( V_44 ) ;
F_41 ( V_44 , V_33 -> V_34 -> V_74 , 1 ) ;
}
} else {
F_30 (counter, &evsel_list->entries, node) {
F_16 ( V_44 ) ;
F_41 ( V_44 , V_33 -> V_34 -> V_74 ,
V_33 -> V_38 -> V_74 ) ;
}
}
return F_42 ( V_84 ) ;
}
static void F_43 ( double V_108 , double V_109 )
{
double V_110 = 0.0 ;
if ( V_109 )
V_110 = 100.0 * V_108 / V_109 ;
if ( V_111 )
fprintf ( V_77 , L_19 , V_112 , V_110 ) ;
else if ( V_110 )
fprintf ( V_77 , L_20 , V_110 ) ;
}
static void F_44 ( struct V_1 * V_2 , double V_109 )
{
struct V_4 * V_69 ;
if ( V_113 == 1 )
return;
V_69 = V_2 -> V_3 ;
F_43 ( F_6 ( & V_69 -> V_75 [ 0 ] ) , V_109 ) ;
}
static void F_45 ( int V_79 , struct V_1 * V_2 , double V_109 )
{
double V_114 = V_109 / 1e6 ;
char V_115 [ 16 ] = { '\0' , } ;
const char * V_116 = V_111 ? L_21 : L_22 ;
if ( V_107 )
sprintf ( V_115 , L_23 ,
V_111 ? 0 : - 4 ,
V_33 -> V_34 -> V_92 [ V_79 ] , V_112 ) ;
fprintf ( V_77 , V_116 , V_115 , V_114 , V_112 , F_18 ( V_2 ) ) ;
if ( V_2 -> V_117 )
fprintf ( V_77 , L_24 , V_112 , V_2 -> V_117 -> V_118 ) ;
if ( V_111 )
return;
if ( F_14 ( V_2 , V_41 , V_43 ) )
fprintf ( V_77 , L_25 ,
V_109 / F_5 ( & V_106 ) ) ;
else
fprintf ( V_77 , L_26 ) ;
}
static const char * F_46 ( enum V_119 type , double V_120 )
{
static const double V_121 [ V_122 ] [ 3 ] = {
[ V_123 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_124 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_125 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_126 = V_127 ;
if ( V_120 > V_121 [ type ] [ 0 ] )
V_126 = V_128 ;
else if ( V_120 > V_121 [ type ] [ 1 ] )
V_126 = V_129 ;
else if ( V_120 > V_121 [ type ] [ 2 ] )
V_126 = V_130 ;
return V_126 ;
}
static void F_47 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_49 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_123 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_29 ) ;
}
static void F_49 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_49 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_124 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_30 ) ;
}
static void F_50 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_55 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_125 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_31 ) ;
}
static void F_51 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_60 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_125 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_32 ) ;
}
static void F_52 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_62 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_125 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_33 ) ;
}
static void F_53 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_66 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_125 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_34 ) ;
}
static void F_54 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_68 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_125 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_35 ) ;
}
static void F_55 ( int V_79 , struct V_1 * V_2 V_80 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
const char * V_126 ;
V_108 = F_5 ( & V_64 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 * 100.0 ;
V_126 = F_46 ( V_125 , V_120 ) ;
fprintf ( V_77 , L_27 ) ;
F_48 ( V_77 , V_126 , L_28 , V_120 ) ;
fprintf ( V_77 , L_36 ) ;
}
static void F_56 ( int V_79 , struct V_1 * V_2 , double V_109 )
{
double V_108 , V_120 = 0.0 ;
char V_115 [ 16 ] = { '\0' , } ;
const char * V_116 ;
if ( V_111 )
V_116 = L_37 ;
else if ( V_131 )
V_116 = L_38 ;
else
V_116 = L_39 ;
if ( V_107 )
sprintf ( V_115 , L_23 ,
V_111 ? 0 : - 4 ,
V_33 -> V_34 -> V_92 [ V_79 ] , V_112 ) ;
else
V_79 = 0 ;
fprintf ( V_77 , V_116 , V_115 , V_109 , V_112 , F_18 ( V_2 ) ) ;
if ( V_2 -> V_117 )
fprintf ( V_77 , L_24 , V_112 , V_2 -> V_117 -> V_118 ) ;
if ( V_111 )
return;
if ( F_14 ( V_2 , V_47 , V_132 ) ) {
V_108 = F_5 ( & V_49 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 / V_108 ;
fprintf ( V_77 , L_40 , V_120 ) ;
V_108 = F_5 ( & V_51 [ V_79 ] ) ;
V_108 = F_57 ( V_108 , F_5 ( & V_53 [ V_79 ] ) ) ;
if ( V_108 && V_109 ) {
V_120 = V_108 / V_109 ;
fprintf ( V_77 , L_41 , V_120 ) ;
}
} else if ( F_14 ( V_2 , V_47 , V_133 ) &&
V_55 [ V_79 ] . V_9 != 0 ) {
F_50 ( V_79 , V_2 , V_109 ) ;
} else if (
V_2 -> V_16 . type == V_134 &&
V_2 -> V_16 . V_135 == ( V_136 |
( ( V_137 ) << 8 ) |
( ( V_138 ) << 16 ) ) &&
V_60 [ V_79 ] . V_9 != 0 ) {
F_51 ( V_79 , V_2 , V_109 ) ;
} else if (
V_2 -> V_16 . type == V_134 &&
V_2 -> V_16 . V_135 == ( V_139 |
( ( V_137 ) << 8 ) |
( ( V_138 ) << 16 ) ) &&
V_62 [ V_79 ] . V_9 != 0 ) {
F_52 ( V_79 , V_2 , V_109 ) ;
} else if (
V_2 -> V_16 . type == V_134 &&
V_2 -> V_16 . V_135 == ( V_140 |
( ( V_137 ) << 8 ) |
( ( V_138 ) << 16 ) ) &&
V_66 [ V_79 ] . V_9 != 0 ) {
F_53 ( V_79 , V_2 , V_109 ) ;
} else if (
V_2 -> V_16 . type == V_134 &&
V_2 -> V_16 . V_135 == ( V_141 |
( ( V_137 ) << 8 ) |
( ( V_138 ) << 16 ) ) &&
V_68 [ V_79 ] . V_9 != 0 ) {
F_54 ( V_79 , V_2 , V_109 ) ;
} else if (
V_2 -> V_16 . type == V_134 &&
V_2 -> V_16 . V_135 == ( V_142 |
( ( V_137 ) << 8 ) |
( ( V_138 ) << 16 ) ) &&
V_64 [ V_79 ] . V_9 != 0 ) {
F_55 ( V_79 , V_2 , V_109 ) ;
} else if ( F_14 ( V_2 , V_47 , V_143 ) &&
V_57 [ V_79 ] . V_9 != 0 ) {
V_108 = F_5 ( & V_57 [ V_79 ] ) ;
if ( V_108 )
V_120 = V_109 * 100 / V_108 ;
fprintf ( V_77 , L_42 , V_120 ) ;
} else if ( F_14 ( V_2 , V_47 , V_50 ) ) {
F_47 ( V_79 , V_2 , V_109 ) ;
} else if ( F_14 ( V_2 , V_47 , V_52 ) ) {
F_49 ( V_79 , V_2 , V_109 ) ;
} else if ( F_14 ( V_2 , V_47 , V_48 ) ) {
V_108 = F_5 ( & V_46 [ V_79 ] ) ;
if ( V_108 )
V_120 = 1.0 * V_109 / V_108 ;
fprintf ( V_77 , L_43 , V_120 ) ;
} else if ( V_46 [ V_79 ] . V_9 != 0 ) {
char V_144 = 'M' ;
V_108 = F_5 ( & V_46 [ V_79 ] ) ;
if ( V_108 )
V_120 = 1000.0 * V_109 / V_108 ;
if ( V_120 < 0.001 ) {
V_120 *= 1000 ;
V_144 = 'K' ;
}
fprintf ( V_77 , L_44 , V_120 , V_144 ) ;
} else {
fprintf ( V_77 , L_26 ) ;
}
}
static void F_58 ( struct V_1 * V_44 )
{
struct V_4 * V_69 = V_44 -> V_3 ;
double V_109 = F_5 ( & V_69 -> V_75 [ 0 ] ) ;
int V_145 = V_44 -> V_70 -> V_145 ;
if ( V_145 == - 1 ) {
fprintf ( V_77 , L_45 ,
V_111 ? 0 : 18 ,
V_44 -> V_100 ? V_146 : V_147 ,
V_112 ,
V_111 ? 0 : - 24 ,
F_18 ( V_44 ) ) ;
if ( V_44 -> V_117 )
fprintf ( V_77 , L_24 , V_112 , V_44 -> V_117 -> V_118 ) ;
fputc ( '\n' , V_77 ) ;
return;
}
if ( F_13 ( V_44 ) )
F_45 ( - 1 , V_44 , V_109 ) ;
else
F_56 ( - 1 , V_44 , V_109 ) ;
F_44 ( V_44 , V_109 ) ;
if ( V_111 ) {
fputc ( '\n' , V_77 ) ;
return;
}
if ( V_145 ) {
double V_148 , V_149 ;
V_148 = F_5 ( & V_69 -> V_75 [ 1 ] ) ;
V_149 = F_5 ( & V_69 -> V_75 [ 2 ] ) ;
fprintf ( V_77 , L_46 , 100 * V_149 / V_148 ) ;
}
fprintf ( V_77 , L_5 ) ;
}
static void F_59 ( struct V_1 * V_44 )
{
T_1 V_150 , V_151 , V_7 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_33 -> V_34 -> V_74 ; V_79 ++ ) {
V_7 = V_44 -> V_70 -> V_79 [ V_79 ] . V_7 ;
V_150 = V_44 -> V_70 -> V_79 [ V_79 ] . V_150 ;
V_151 = V_44 -> V_70 -> V_79 [ V_79 ] . V_151 ;
if ( V_151 == 0 || V_150 == 0 ) {
fprintf ( V_77 , L_47 ,
V_111 ? 0 : - 4 ,
V_33 -> V_34 -> V_92 [ V_79 ] , V_112 ,
V_111 ? 0 : 18 ,
V_44 -> V_100 ? V_146 : V_147 ,
V_112 ,
V_111 ? 0 : - 24 ,
F_18 ( V_44 ) ) ;
if ( V_44 -> V_117 )
fprintf ( V_77 , L_24 ,
V_112 , V_44 -> V_117 -> V_118 ) ;
fputc ( '\n' , V_77 ) ;
continue;
}
if ( F_13 ( V_44 ) )
F_45 ( V_79 , V_44 , V_7 ) ;
else
F_56 ( V_79 , V_44 , V_7 ) ;
if ( ! V_111 ) {
F_44 ( V_44 , 1.0 ) ;
if ( V_151 != V_150 )
fprintf ( V_77 , L_48 ,
100.0 * V_151 / V_150 ) ;
}
fputc ( '\n' , V_77 ) ;
}
}
static void F_60 ( int T_2 , const char * * V_81 )
{
struct V_1 * V_44 ;
int V_73 ;
fflush ( stdout ) ;
if ( ! V_111 ) {
fprintf ( V_77 , L_5 ) ;
fprintf ( V_77 , L_49 ) ;
if ( ! F_10 ( & V_32 ) ) {
fprintf ( V_77 , L_50 , V_81 [ 0 ] ) ;
for ( V_73 = 1 ; V_73 < T_2 ; V_73 ++ )
fprintf ( V_77 , L_51 , V_81 [ V_73 ] ) ;
} else if ( V_32 . V_152 )
fprintf ( V_77 , L_52 , V_32 . V_152 ) ;
else
fprintf ( V_77 , L_53 , V_32 . V_153 ) ;
fprintf ( V_77 , L_54 ) ;
if ( V_113 > 1 )
fprintf ( V_77 , L_55 , V_113 ) ;
fprintf ( V_77 , L_56 ) ;
}
if ( V_107 ) {
F_30 (counter, &evsel_list->entries, node)
F_59 ( V_44 ) ;
} else {
F_30 (counter, &evsel_list->entries, node)
F_58 ( V_44 ) ;
}
if ( ! V_111 ) {
if ( ! V_154 )
fprintf ( V_77 , L_5 ) ;
fprintf ( V_77 , L_57 ,
F_5 ( & V_106 ) / 1e9 ) ;
if ( V_113 > 1 ) {
fprintf ( V_77 , L_58 ) ;
F_43 ( F_6 ( & V_106 ) ,
F_5 ( & V_106 ) ) ;
}
fprintf ( V_77 , L_59 ) ;
}
}
static void F_61 ( int V_155 )
{
if( V_89 == - 1 )
V_105 = 1 ;
V_156 = V_155 ;
}
static void F_62 ( void )
{
if ( V_89 != - 1 )
F_32 ( V_89 , V_104 ) ;
if ( V_156 == - 1 )
return;
signal ( V_156 , V_157 ) ;
F_32 ( F_63 () , V_156 ) ;
}
static int F_64 ( const struct V_158 * T_3 V_80 ,
const char * T_4 V_80 , int V_159 )
{
V_160 = V_159 ? 0 : 1 ;
return 0 ;
}
static int F_65 ( void )
{
if ( V_154 )
return 0 ;
if ( ! V_33 -> V_161 ) {
if ( F_66 ( V_33 , V_162 ) < 0 )
return - 1 ;
}
if ( V_163 < 1 )
return 0 ;
if ( F_66 ( V_33 , V_164 ) < 0 )
return - 1 ;
if ( V_163 < 2 )
return 0 ;
if ( F_66 ( V_33 , V_165 ) < 0 )
return - 1 ;
if ( V_163 < 3 )
return 0 ;
return F_66 ( V_33 , V_166 ) ;
}
int F_67 ( int T_2 , const char * * V_81 , const char * T_5 V_80 )
{
struct V_1 * V_167 ;
int V_84 = - V_5 ;
const char * V_168 ;
setlocale ( V_169 , L_8 ) ;
V_33 = F_68 ( NULL , NULL ) ;
if ( V_33 == NULL )
return - V_5 ;
T_2 = F_69 ( T_2 , V_81 , V_170 , V_171 ,
V_172 ) ;
V_77 = V_173 ;
if ( V_174 && strcmp ( V_174 , L_60 ) )
V_77 = NULL ;
if ( V_174 && V_175 ) {
fprintf ( V_173 , L_61 ) ;
F_70 ( V_171 , V_170 ) ;
}
if ( V_175 < 0 ) {
fprintf ( V_173 , L_62 ) ;
F_70 ( V_171 , V_170 ) ;
}
if ( ! V_77 ) {
struct V_176 V_177 ;
V_168 = V_178 ? L_63 : L_64 ;
V_77 = fopen ( V_174 , V_168 ) ;
if ( ! V_77 ) {
perror ( L_65 ) ;
exit ( - 1 ) ;
}
F_71 ( V_179 , & V_177 ) ;
fprintf ( V_77 , L_66 , ctime ( & V_177 . V_180 ) ) ;
} else if ( V_175 > 0 ) {
V_168 = V_178 ? L_63 : L_64 ;
V_77 = fdopen ( V_175 , V_168 ) ;
if ( ! V_77 ) {
perror ( L_67 ) ;
return - V_39 ;
}
}
if ( V_112 ) {
V_111 = true ;
if ( ! strcmp ( V_112 , L_68 ) )
V_112 = L_69 ;
} else
V_112 = V_181 ;
if ( V_111 ) {
if ( V_160 == 1 ) {
fprintf ( V_173 , L_70 ) ;
F_70 ( V_171 , V_170 ) ;
} else
V_131 = false ;
} else if ( V_160 == 0 )
V_131 = false ;
if ( ! T_2 && ! F_10 ( & V_32 ) )
F_70 ( V_171 , V_170 ) ;
if ( V_113 <= 0 )
F_70 ( V_171 , V_170 ) ;
if ( ( V_107 || V_182 ) && ! F_8 ( & V_32 ) ) {
fprintf ( V_173 , L_71
L_72 ) ;
F_70 ( V_171 , V_170 ) ;
}
if ( F_65 () )
goto V_183;
F_72 ( & V_32 ) ;
if ( F_73 ( V_33 , & V_32 ) < 0 ) {
if ( F_10 ( & V_32 ) )
F_74 ( L_73 ) ;
if ( F_8 ( & V_32 ) )
perror ( L_74 ) ;
F_70 ( V_171 , V_170 ) ;
return - 1 ;
}
F_30 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_167 ) < 0 ||
F_75 ( V_167 , V_33 -> V_34 -> V_74 ) < 0 )
goto V_184;
}
atexit ( F_62 ) ;
signal ( V_185 , F_61 ) ;
signal ( V_186 , F_61 ) ;
signal ( V_187 , F_61 ) ;
V_84 = 0 ;
for ( V_188 = 0 ; V_188 < V_113 ; V_188 ++ ) {
if ( V_113 != 1 && V_76 )
fprintf ( V_77 , L_75 ,
V_188 + 1 ) ;
if ( V_189 )
F_76 () ;
V_84 = F_21 ( T_2 , V_81 ) ;
}
if ( V_84 != - 1 )
F_60 ( T_2 , V_81 ) ;
V_184:
F_30 (pos, &evsel_list->entries, node)
F_3 ( V_167 ) ;
F_77 ( V_33 ) ;
V_183:
F_78 ( V_33 ) ;
return V_84 ;
}
