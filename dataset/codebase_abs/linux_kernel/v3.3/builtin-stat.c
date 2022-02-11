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
if ( V_19 && V_2 != V_14 )
V_18 = V_14 -> V_20 ;
if ( V_21 )
V_16 -> V_22 = V_23 |
V_24 ;
V_16 -> V_25 = ! V_26 ;
if ( V_27 )
return F_8 ( V_2 , V_28 -> V_29 ,
V_19 , V_18 ) ;
if ( V_30 == - 1 && V_31 == - 1 ) {
V_16 -> V_32 = 1 ;
V_16 -> V_33 = 1 ;
}
return F_9 ( V_2 , V_28 -> V_34 ,
V_19 , V_18 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 , V_35 , V_36 ) ||
F_11 ( V_2 , V_35 , V_37 ) )
return 1 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_38 , T_1 * V_39 )
{
if ( F_11 ( V_38 , V_35 , V_37 ) )
F_4 ( & V_40 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_41 , V_42 ) )
F_4 ( & V_43 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_41 , V_44 ) )
F_4 ( & V_45 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_41 , V_46 ) )
F_4 ( & V_47 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_41 , V_48 ) )
F_4 ( & V_49 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_41 , V_50 ) )
F_4 ( & V_51 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_52 , V_53 ) )
F_4 ( & V_54 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_52 , V_55 ) )
F_4 ( & V_56 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_52 , V_57 ) )
F_4 ( & V_58 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_52 , V_59 ) )
F_4 ( & V_60 [ 0 ] , V_39 [ 0 ] ) ;
else if ( F_11 ( V_38 , V_52 , V_61 ) )
F_4 ( & V_62 [ 0 ] , V_39 [ 0 ] ) ;
}
static int F_13 ( struct V_1 * V_38 )
{
struct V_4 * V_63 = V_38 -> V_3 ;
T_1 * V_39 = V_38 -> V_64 -> V_65 . V_66 ;
int V_67 ;
if ( F_14 ( V_38 , V_28 -> V_29 -> V_68 ,
V_28 -> V_34 -> V_68 , V_21 ) < 0 )
return - 1 ;
for ( V_67 = 0 ; V_67 < 3 ; V_67 ++ )
F_4 ( & V_63 -> V_69 [ V_67 ] , V_39 [ V_67 ] ) ;
if ( V_70 ) {
fprintf ( V_71 , L_1 V_72 L_2 V_72 L_2 V_72 L_3 ,
F_15 ( V_38 ) , V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ) ;
}
F_12 ( V_38 , V_39 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_38 )
{
T_1 * V_39 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_28 -> V_29 -> V_68 ; V_73 ++ ) {
if ( F_17 ( V_38 , V_73 , 0 , V_21 ) < 0 )
return - 1 ;
V_39 = V_38 -> V_64 -> V_73 [ V_73 ] . V_66 ;
F_12 ( V_38 , V_39 ) ;
}
return 0 ;
}
static int F_18 ( int T_2 V_74 , const char * * V_75 )
{
unsigned long long V_76 , V_77 ;
struct V_1 * V_38 , * V_14 ;
int V_78 = 0 ;
int V_79 [ 2 ] , V_80 [ 2 ] ;
const bool V_81 = ( T_2 > 0 ) ;
char V_82 ;
if ( V_81 && ( F_19 ( V_79 ) < 0 || F_19 ( V_80 ) < 0 ) ) {
perror ( L_4 ) ;
exit ( 1 ) ;
}
if ( V_81 ) {
if ( ( V_83 = F_20 () ) < 0 )
perror ( L_5 ) ;
if ( ! V_83 ) {
F_21 ( V_79 [ 0 ] ) ;
F_21 ( V_80 [ 1 ] ) ;
F_22 ( V_80 [ 0 ] , V_84 , V_85 ) ;
F_23 ( L_6 , ( char * * ) V_75 ) ;
F_21 ( V_79 [ 1 ] ) ;
if ( F_24 ( V_80 [ 0 ] , & V_82 , 1 ) == - 1 )
perror ( L_7 ) ;
F_23 ( V_75 [ 0 ] , ( char * * ) V_75 ) ;
perror ( V_75 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( V_31 == - 1 && V_30 == - 1 && ! V_27 )
V_28 -> V_34 -> V_86 [ 0 ] = V_83 ;
F_21 ( V_79 [ 1 ] ) ;
F_21 ( V_80 [ 0 ] ) ;
if ( F_24 ( V_79 [ 0 ] , & V_82 , 1 ) == - 1 )
perror ( L_7 ) ;
F_21 ( V_79 [ 0 ] ) ;
}
V_14 = F_25 ( V_28 -> V_87 . V_88 , struct V_1 , V_89 ) ;
F_26 (counter, &evsel_list->entries, node) {
if ( F_7 ( V_38 , V_14 ) < 0 ) {
if ( V_90 == V_91 || V_90 == V_92 ||
V_90 == V_93 || V_90 == V_94 ) {
if ( V_70 )
F_27 ( L_8 ,
F_15 ( V_38 ) ) ;
V_38 -> V_95 = false ;
continue;
}
if ( V_90 == V_96 || V_90 == V_97 ) {
error ( L_9
L_10
L_11 ,
V_27 ? L_12 : L_6 ) ;
} else {
error ( L_13
L_14 ,
V_90 , strerror ( V_90 ) ) ;
}
if ( V_83 != - 1 )
F_28 ( V_83 , V_98 ) ;
F_29 ( L_15 ) ;
return - 1 ;
}
V_38 -> V_95 = true ;
}
if ( F_30 ( V_28 ) ) {
error ( L_16 , V_90 ,
strerror ( V_90 ) ) ;
return - 1 ;
}
V_76 = F_31 () ;
if ( V_81 ) {
F_21 ( V_80 [ 1 ] ) ;
F_32 ( & V_78 ) ;
if ( F_33 ( V_78 ) )
F_34 ( F_35 ( V_78 ) , V_75 [ 0 ] ) ;
} else {
while( ! V_99 ) F_36 ( 1 ) ;
}
V_77 = F_31 () ;
F_4 ( & V_100 , V_77 - V_76 ) ;
if ( V_101 ) {
F_26 (counter, &evsel_list->entries, node) {
F_16 ( V_38 ) ;
F_37 ( V_38 , V_28 -> V_29 -> V_68 , 1 ) ;
}
} else {
F_26 (counter, &evsel_list->entries, node) {
F_13 ( V_38 ) ;
F_37 ( V_38 , V_28 -> V_29 -> V_68 ,
V_28 -> V_34 -> V_68 ) ;
}
}
return F_38 ( V_78 ) ;
}
static void F_39 ( double V_102 , double V_103 )
{
double V_104 = 0.0 ;
if ( V_103 )
V_104 = 100.0 * V_102 / V_103 ;
if ( V_105 )
fprintf ( V_71 , L_17 , V_106 , V_104 ) ;
else if ( V_104 )
fprintf ( V_71 , L_18 , V_104 ) ;
}
static void F_40 ( struct V_1 * V_2 , double V_103 )
{
struct V_4 * V_63 ;
if ( V_107 == 1 )
return;
V_63 = V_2 -> V_3 ;
F_39 ( F_6 ( & V_63 -> V_69 [ 0 ] ) , V_103 ) ;
}
static void F_41 ( int V_73 , struct V_1 * V_2 , double V_103 )
{
double V_108 = V_103 / 1e6 ;
char V_109 [ 16 ] = { '\0' , } ;
const char * V_110 = V_105 ? L_19 : L_20 ;
if ( V_101 )
sprintf ( V_109 , L_21 ,
V_105 ? 0 : - 4 ,
V_28 -> V_29 -> V_86 [ V_73 ] , V_106 ) ;
fprintf ( V_71 , V_110 , V_109 , V_108 , V_106 , F_15 ( V_2 ) ) ;
if ( V_2 -> V_111 )
fprintf ( V_71 , L_22 , V_106 , V_2 -> V_111 -> V_112 ) ;
if ( V_105 )
return;
if ( F_11 ( V_2 , V_35 , V_37 ) )
fprintf ( V_71 , L_23 ,
V_103 / F_5 ( & V_100 ) ) ;
}
static const char * F_42 ( enum V_113 type , double V_114 )
{
static const double V_115 [ V_116 ] [ 3 ] = {
[ V_117 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_118 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_119 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_120 = V_121 ;
if ( V_114 > V_115 [ type ] [ 0 ] )
V_120 = V_122 ;
else if ( V_114 > V_115 [ type ] [ 1 ] )
V_120 = V_123 ;
else if ( V_114 > V_115 [ type ] [ 2 ] )
V_120 = V_124 ;
return V_120 ;
}
static void F_43 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_43 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_117 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_26 ) ;
}
static void F_45 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_43 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_118 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_27 ) ;
}
static void F_46 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_49 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_119 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_28 ) ;
}
static void F_47 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_54 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_119 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_29 ) ;
}
static void F_48 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_56 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_119 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_30 ) ;
}
static void F_49 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_60 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_119 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_31 ) ;
}
static void F_50 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_62 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_119 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_32 ) ;
}
static void F_51 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
const char * V_120 ;
V_102 = F_5 ( & V_58 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 * 100.0 ;
V_120 = F_42 ( V_119 , V_114 ) ;
fprintf ( V_71 , L_24 ) ;
F_44 ( V_71 , V_120 , L_25 , V_114 ) ;
fprintf ( V_71 , L_33 ) ;
}
static void F_52 ( int V_73 , struct V_1 * V_2 , double V_103 )
{
double V_102 , V_114 = 0.0 ;
char V_109 [ 16 ] = { '\0' , } ;
const char * V_110 ;
if ( V_105 )
V_110 = L_34 ;
else if ( V_125 )
V_110 = L_35 ;
else
V_110 = L_36 ;
if ( V_101 )
sprintf ( V_109 , L_21 ,
V_105 ? 0 : - 4 ,
V_28 -> V_29 -> V_86 [ V_73 ] , V_106 ) ;
else
V_73 = 0 ;
fprintf ( V_71 , V_110 , V_109 , V_103 , V_106 , F_15 ( V_2 ) ) ;
if ( V_2 -> V_111 )
fprintf ( V_71 , L_22 , V_106 , V_2 -> V_111 -> V_112 ) ;
if ( V_105 )
return;
if ( F_11 ( V_2 , V_41 , V_126 ) ) {
V_102 = F_5 ( & V_43 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 / V_102 ;
fprintf ( V_71 , L_37 , V_114 ) ;
V_102 = F_5 ( & V_45 [ V_73 ] ) ;
V_102 = F_53 ( V_102 , F_5 ( & V_47 [ V_73 ] ) ) ;
if ( V_102 && V_103 ) {
V_114 = V_102 / V_103 ;
fprintf ( V_71 , L_38 , V_114 ) ;
}
} else if ( F_11 ( V_2 , V_41 , V_127 ) &&
V_49 [ V_73 ] . V_9 != 0 ) {
F_46 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_128 &&
V_2 -> V_16 . V_129 == ( V_130 |
( ( V_131 ) << 8 ) |
( ( V_132 ) << 16 ) ) &&
V_54 [ V_73 ] . V_9 != 0 ) {
F_47 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_128 &&
V_2 -> V_16 . V_129 == ( V_133 |
( ( V_131 ) << 8 ) |
( ( V_132 ) << 16 ) ) &&
V_56 [ V_73 ] . V_9 != 0 ) {
F_48 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_128 &&
V_2 -> V_16 . V_129 == ( V_134 |
( ( V_131 ) << 8 ) |
( ( V_132 ) << 16 ) ) &&
V_60 [ V_73 ] . V_9 != 0 ) {
F_49 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_128 &&
V_2 -> V_16 . V_129 == ( V_135 |
( ( V_131 ) << 8 ) |
( ( V_132 ) << 16 ) ) &&
V_62 [ V_73 ] . V_9 != 0 ) {
F_50 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_128 &&
V_2 -> V_16 . V_129 == ( V_136 |
( ( V_131 ) << 8 ) |
( ( V_132 ) << 16 ) ) &&
V_58 [ V_73 ] . V_9 != 0 ) {
F_51 ( V_73 , V_2 , V_103 ) ;
} else if ( F_11 ( V_2 , V_41 , V_137 ) &&
V_51 [ V_73 ] . V_9 != 0 ) {
V_102 = F_5 ( & V_51 [ V_73 ] ) ;
if ( V_102 )
V_114 = V_103 * 100 / V_102 ;
fprintf ( V_71 , L_39 , V_114 ) ;
} else if ( F_11 ( V_2 , V_41 , V_44 ) ) {
F_43 ( V_73 , V_2 , V_103 ) ;
} else if ( F_11 ( V_2 , V_41 , V_46 ) ) {
F_45 ( V_73 , V_2 , V_103 ) ;
} else if ( F_11 ( V_2 , V_41 , V_42 ) ) {
V_102 = F_5 ( & V_40 [ V_73 ] ) ;
if ( V_102 )
V_114 = 1.0 * V_103 / V_102 ;
fprintf ( V_71 , L_40 , V_114 ) ;
} else if ( V_40 [ V_73 ] . V_9 != 0 ) {
V_102 = F_5 ( & V_40 [ V_73 ] ) ;
if ( V_102 )
V_114 = 1000.0 * V_103 / V_102 ;
fprintf ( V_71 , L_41 , V_114 ) ;
} else {
fprintf ( V_71 , L_42 ) ;
}
}
static void F_54 ( struct V_1 * V_38 )
{
struct V_4 * V_63 = V_38 -> V_3 ;
double V_103 = F_5 ( & V_63 -> V_69 [ 0 ] ) ;
int V_138 = V_38 -> V_64 -> V_138 ;
if ( V_138 == - 1 ) {
fprintf ( V_71 , L_43 ,
V_105 ? 0 : 18 ,
V_38 -> V_95 ? V_139 : V_140 ,
V_106 ,
V_105 ? 0 : - 24 ,
F_15 ( V_38 ) ) ;
if ( V_38 -> V_111 )
fprintf ( V_71 , L_22 , V_106 , V_38 -> V_111 -> V_112 ) ;
fputc ( '\n' , V_71 ) ;
return;
}
if ( F_10 ( V_38 ) )
F_41 ( - 1 , V_38 , V_103 ) ;
else
F_52 ( - 1 , V_38 , V_103 ) ;
F_40 ( V_38 , V_103 ) ;
if ( V_105 ) {
fputc ( '\n' , V_71 ) ;
return;
}
if ( V_138 ) {
double V_141 , V_142 ;
V_141 = F_5 ( & V_63 -> V_69 [ 1 ] ) ;
V_142 = F_5 ( & V_63 -> V_69 [ 2 ] ) ;
fprintf ( V_71 , L_44 , 100 * V_142 / V_141 ) ;
}
fprintf ( V_71 , L_3 ) ;
}
static void F_55 ( struct V_1 * V_38 )
{
T_1 V_143 , V_144 , V_7 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_28 -> V_29 -> V_68 ; V_73 ++ ) {
V_7 = V_38 -> V_64 -> V_73 [ V_73 ] . V_7 ;
V_143 = V_38 -> V_64 -> V_73 [ V_73 ] . V_143 ;
V_144 = V_38 -> V_64 -> V_73 [ V_73 ] . V_144 ;
if ( V_144 == 0 || V_143 == 0 ) {
fprintf ( V_71 , L_45 ,
V_105 ? 0 : - 4 ,
V_28 -> V_29 -> V_86 [ V_73 ] , V_106 ,
V_105 ? 0 : 18 ,
V_38 -> V_95 ? V_139 : V_140 ,
V_106 ,
V_105 ? 0 : - 24 ,
F_15 ( V_38 ) ) ;
if ( V_38 -> V_111 )
fprintf ( V_71 , L_22 ,
V_106 , V_38 -> V_111 -> V_112 ) ;
fputc ( '\n' , V_71 ) ;
continue;
}
if ( F_10 ( V_38 ) )
F_41 ( V_73 , V_38 , V_7 ) ;
else
F_52 ( V_73 , V_38 , V_7 ) ;
if ( ! V_105 ) {
F_40 ( V_38 , 1.0 ) ;
if ( V_144 != V_143 )
fprintf ( V_71 , L_46 ,
100.0 * V_144 / V_143 ) ;
}
fputc ( '\n' , V_71 ) ;
}
}
static void F_56 ( int T_2 , const char * * V_75 )
{
struct V_1 * V_38 ;
int V_67 ;
fflush ( stdout ) ;
if ( ! V_105 ) {
fprintf ( V_71 , L_3 ) ;
fprintf ( V_71 , L_47 ) ;
if( V_30 == - 1 && V_31 == - 1 ) {
fprintf ( V_71 , L_48 , V_75 [ 0 ] ) ;
for ( V_67 = 1 ; V_67 < T_2 ; V_67 ++ )
fprintf ( V_71 , L_49 , V_75 [ V_67 ] ) ;
} else if ( V_30 != - 1 )
fprintf ( V_71 , L_50 , V_30 ) ;
else
fprintf ( V_71 , L_51 , V_31 ) ;
fprintf ( V_71 , L_52 ) ;
if ( V_107 > 1 )
fprintf ( V_71 , L_53 , V_107 ) ;
fprintf ( V_71 , L_54 ) ;
}
if ( V_101 ) {
F_26 (counter, &evsel_list->entries, node)
F_55 ( V_38 ) ;
} else {
F_26 (counter, &evsel_list->entries, node)
F_54 ( V_38 ) ;
}
if ( ! V_105 ) {
if ( ! V_145 )
fprintf ( V_71 , L_3 ) ;
fprintf ( V_71 , L_55 ,
F_5 ( & V_100 ) / 1e9 ) ;
if ( V_107 > 1 ) {
fprintf ( V_71 , L_56 ) ;
F_39 ( F_6 ( & V_100 ) ,
F_5 ( & V_100 ) ) ;
}
fprintf ( V_71 , L_57 ) ;
}
}
static void F_57 ( int V_146 )
{
if( V_83 == - 1 )
V_99 = 1 ;
V_147 = V_146 ;
}
static void F_58 ( void )
{
if ( V_83 != - 1 )
F_28 ( V_83 , V_98 ) ;
if ( V_147 == - 1 )
return;
signal ( V_147 , V_148 ) ;
F_28 ( F_59 () , V_147 ) ;
}
static int F_60 ( const struct V_149 * T_3 V_74 ,
const char * T_4 V_74 , int V_150 )
{
V_151 = V_150 ? 0 : 1 ;
return 0 ;
}
static int F_61 ( void )
{
if ( V_145 )
return 0 ;
if ( ! V_28 -> V_152 ) {
if ( F_62 ( V_28 , V_153 ) < 0 )
return - 1 ;
}
if ( V_154 < 1 )
return 0 ;
if ( F_62 ( V_28 , V_155 ) < 0 )
return - 1 ;
if ( V_154 < 2 )
return 0 ;
if ( F_62 ( V_28 , V_156 ) < 0 )
return - 1 ;
if ( V_154 < 3 )
return 0 ;
return F_62 ( V_28 , V_157 ) ;
}
int F_63 ( int T_2 , const char * * V_75 , const char * T_5 V_74 )
{
struct V_1 * V_158 ;
int V_78 = - V_5 ;
const char * V_159 ;
setlocale ( V_160 , L_6 ) ;
V_28 = F_64 ( NULL , NULL ) ;
if ( V_28 == NULL )
return - V_5 ;
T_2 = F_65 ( T_2 , V_75 , V_161 , V_162 ,
V_163 ) ;
V_71 = V_164 ;
if ( V_165 && strcmp ( V_165 , L_58 ) )
V_71 = NULL ;
if ( V_165 && V_166 ) {
fprintf ( V_164 , L_59 ) ;
F_66 ( V_162 , V_161 ) ;
}
if ( ! V_71 ) {
struct V_167 V_168 ;
V_159 = V_169 ? L_60 : L_61 ;
V_71 = fopen ( V_165 , V_159 ) ;
if ( ! V_71 ) {
perror ( L_62 ) ;
exit ( - 1 ) ;
}
F_67 ( V_170 , & V_168 ) ;
fprintf ( V_71 , L_63 , ctime ( & V_168 . V_171 ) ) ;
} else if ( V_166 != 2 ) {
V_159 = V_169 ? L_60 : L_61 ;
V_71 = fdopen ( V_166 , V_159 ) ;
if ( ! V_71 ) {
perror ( L_64 ) ;
return - V_90 ;
}
}
if ( V_106 ) {
V_105 = true ;
if ( ! strcmp ( V_106 , L_65 ) )
V_106 = L_66 ;
} else
V_106 = V_172 ;
if ( V_105 ) {
if ( V_151 == 1 ) {
fprintf ( V_164 , L_67 ) ;
F_66 ( V_162 , V_161 ) ;
} else
V_125 = false ;
} else if ( V_151 == 0 )
V_125 = false ;
if ( ! T_2 && V_30 == - 1 && V_31 == - 1 )
F_66 ( V_162 , V_161 ) ;
if ( V_107 <= 0 )
F_66 ( V_162 , V_161 ) ;
if ( ( V_101 || V_173 ) && ! V_27 ) {
fprintf ( V_164 , L_68
L_69 ) ;
F_66 ( V_162 , V_161 ) ;
}
if ( F_61 () )
goto V_174;
if ( V_30 != - 1 )
V_31 = V_30 ;
V_28 -> V_34 = F_68 ( V_30 , V_31 ) ;
if ( V_28 -> V_34 == NULL ) {
F_69 ( L_70 ) ;
F_66 ( V_162 , V_161 ) ;
}
if ( V_27 )
V_28 -> V_29 = F_70 ( V_175 ) ;
else
V_28 -> V_29 = F_71 () ;
if ( V_28 -> V_29 == NULL ) {
perror ( L_71 ) ;
F_66 ( V_162 , V_161 ) ;
return - 1 ;
}
F_26 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_158 ) < 0 ||
F_72 ( V_158 , V_28 -> V_29 -> V_68 ) < 0 )
goto V_176;
}
atexit ( F_58 ) ;
signal ( V_177 , F_57 ) ;
signal ( V_178 , F_57 ) ;
signal ( V_179 , F_57 ) ;
V_78 = 0 ;
for ( V_180 = 0 ; V_180 < V_107 ; V_180 ++ ) {
if ( V_107 != 1 && V_70 )
fprintf ( V_71 , L_72 ,
V_180 + 1 ) ;
if ( V_181 )
F_73 () ;
V_78 = F_18 ( T_2 , V_75 ) ;
}
if ( V_78 != - 1 )
F_56 ( T_2 , V_75 ) ;
V_176:
F_26 (pos, &evsel_list->entries, node)
F_3 ( V_158 ) ;
F_74 ( V_28 ) ;
V_174:
F_75 ( V_28 ) ;
return V_78 ;
}
