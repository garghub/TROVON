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
static void F_42 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_43 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 50.0 )
V_114 = V_116 ;
else if ( V_113 > 30.0 )
V_114 = V_117 ;
else if ( V_113 > 10.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_26 ) ;
}
static void F_44 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_43 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 75.0 )
V_114 = V_116 ;
else if ( V_113 > 50.0 )
V_114 = V_117 ;
else if ( V_113 > 20.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_27 ) ;
}
static void F_45 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_49 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 20.0 )
V_114 = V_116 ;
else if ( V_113 > 10.0 )
V_114 = V_117 ;
else if ( V_113 > 5.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_28 ) ;
}
static void F_46 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_54 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 20.0 )
V_114 = V_116 ;
else if ( V_113 > 10.0 )
V_114 = V_117 ;
else if ( V_113 > 5.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_29 ) ;
}
static void F_47 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_56 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 20.0 )
V_114 = V_116 ;
else if ( V_113 > 10.0 )
V_114 = V_117 ;
else if ( V_113 > 5.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_30 ) ;
}
static void F_48 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_60 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 20.0 )
V_114 = V_116 ;
else if ( V_113 > 10.0 )
V_114 = V_117 ;
else if ( V_113 > 5.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_31 ) ;
}
static void F_49 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_62 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 20.0 )
V_114 = V_116 ;
else if ( V_113 > 10.0 )
V_114 = V_117 ;
else if ( V_113 > 5.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_32 ) ;
}
static void F_50 ( int V_73 , struct V_1 * V_2 V_74 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
const char * V_114 ;
V_102 = F_5 ( & V_58 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 * 100.0 ;
V_114 = V_115 ;
if ( V_113 > 20.0 )
V_114 = V_116 ;
else if ( V_113 > 10.0 )
V_114 = V_117 ;
else if ( V_113 > 5.0 )
V_114 = V_118 ;
fprintf ( V_71 , L_24 ) ;
F_43 ( V_71 , V_114 , L_25 , V_113 ) ;
fprintf ( V_71 , L_33 ) ;
}
static void F_51 ( int V_73 , struct V_1 * V_2 , double V_103 )
{
double V_102 , V_113 = 0.0 ;
char V_109 [ 16 ] = { '\0' , } ;
const char * V_110 ;
if ( V_105 )
V_110 = L_34 ;
else if ( V_119 )
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
if ( F_11 ( V_2 , V_41 , V_120 ) ) {
V_102 = F_5 ( & V_43 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 / V_102 ;
fprintf ( V_71 , L_37 , V_113 ) ;
V_102 = F_5 ( & V_45 [ V_73 ] ) ;
V_102 = F_52 ( V_102 , F_5 ( & V_47 [ V_73 ] ) ) ;
if ( V_102 && V_103 ) {
V_113 = V_102 / V_103 ;
fprintf ( V_71 , L_38 , V_113 ) ;
}
} else if ( F_11 ( V_2 , V_41 , V_121 ) &&
V_49 [ V_73 ] . V_9 != 0 ) {
F_45 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_122 &&
V_2 -> V_16 . V_123 == ( V_124 |
( ( V_125 ) << 8 ) |
( ( V_126 ) << 16 ) ) &&
V_54 [ V_73 ] . V_9 != 0 ) {
F_46 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_122 &&
V_2 -> V_16 . V_123 == ( V_127 |
( ( V_125 ) << 8 ) |
( ( V_126 ) << 16 ) ) &&
V_56 [ V_73 ] . V_9 != 0 ) {
F_47 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_122 &&
V_2 -> V_16 . V_123 == ( V_128 |
( ( V_125 ) << 8 ) |
( ( V_126 ) << 16 ) ) &&
V_60 [ V_73 ] . V_9 != 0 ) {
F_48 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_122 &&
V_2 -> V_16 . V_123 == ( V_129 |
( ( V_125 ) << 8 ) |
( ( V_126 ) << 16 ) ) &&
V_62 [ V_73 ] . V_9 != 0 ) {
F_49 ( V_73 , V_2 , V_103 ) ;
} else if (
V_2 -> V_16 . type == V_122 &&
V_2 -> V_16 . V_123 == ( V_130 |
( ( V_125 ) << 8 ) |
( ( V_126 ) << 16 ) ) &&
V_58 [ V_73 ] . V_9 != 0 ) {
F_50 ( V_73 , V_2 , V_103 ) ;
} else if ( F_11 ( V_2 , V_41 , V_131 ) &&
V_51 [ V_73 ] . V_9 != 0 ) {
V_102 = F_5 ( & V_51 [ V_73 ] ) ;
if ( V_102 )
V_113 = V_103 * 100 / V_102 ;
fprintf ( V_71 , L_39 , V_113 ) ;
} else if ( F_11 ( V_2 , V_41 , V_44 ) ) {
F_42 ( V_73 , V_2 , V_103 ) ;
} else if ( F_11 ( V_2 , V_41 , V_46 ) ) {
F_44 ( V_73 , V_2 , V_103 ) ;
} else if ( F_11 ( V_2 , V_41 , V_42 ) ) {
V_102 = F_5 ( & V_40 [ V_73 ] ) ;
if ( V_102 )
V_113 = 1.0 * V_103 / V_102 ;
fprintf ( V_71 , L_40 , V_113 ) ;
} else if ( V_40 [ V_73 ] . V_9 != 0 ) {
V_102 = F_5 ( & V_40 [ V_73 ] ) ;
if ( V_102 )
V_113 = 1000.0 * V_103 / V_102 ;
fprintf ( V_71 , L_41 , V_113 ) ;
} else {
fprintf ( V_71 , L_42 ) ;
}
}
static void F_53 ( struct V_1 * V_38 )
{
struct V_4 * V_63 = V_38 -> V_3 ;
double V_103 = F_5 ( & V_63 -> V_69 [ 0 ] ) ;
int V_132 = V_38 -> V_64 -> V_132 ;
if ( V_132 == - 1 ) {
fprintf ( V_71 , L_43 ,
V_105 ? 0 : 18 ,
V_38 -> V_95 ? V_133 : V_134 ,
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
F_51 ( - 1 , V_38 , V_103 ) ;
F_40 ( V_38 , V_103 ) ;
if ( V_105 ) {
fputc ( '\n' , V_71 ) ;
return;
}
if ( V_132 ) {
double V_135 , V_136 ;
V_135 = F_5 ( & V_63 -> V_69 [ 1 ] ) ;
V_136 = F_5 ( & V_63 -> V_69 [ 2 ] ) ;
fprintf ( V_71 , L_44 , 100 * V_136 / V_135 ) ;
}
fprintf ( V_71 , L_3 ) ;
}
static void F_54 ( struct V_1 * V_38 )
{
T_1 V_137 , V_138 , V_7 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_28 -> V_29 -> V_68 ; V_73 ++ ) {
V_7 = V_38 -> V_64 -> V_73 [ V_73 ] . V_7 ;
V_137 = V_38 -> V_64 -> V_73 [ V_73 ] . V_137 ;
V_138 = V_38 -> V_64 -> V_73 [ V_73 ] . V_138 ;
if ( V_138 == 0 || V_137 == 0 ) {
fprintf ( V_71 , L_45 ,
V_105 ? 0 : - 4 ,
V_28 -> V_29 -> V_86 [ V_73 ] , V_106 ,
V_105 ? 0 : 18 ,
V_38 -> V_95 ? V_133 : V_134 ,
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
F_51 ( V_73 , V_38 , V_7 ) ;
if ( ! V_105 ) {
F_40 ( V_38 , 1.0 ) ;
if ( V_138 != V_137 )
fprintf ( V_71 , L_46 ,
100.0 * V_138 / V_137 ) ;
}
fputc ( '\n' , V_71 ) ;
}
}
static void F_55 ( int T_2 , const char * * V_75 )
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
F_54 ( V_38 ) ;
} else {
F_26 (counter, &evsel_list->entries, node)
F_53 ( V_38 ) ;
}
if ( ! V_105 ) {
if ( ! V_139 )
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
static void F_56 ( int V_140 )
{
if( V_83 == - 1 )
V_99 = 1 ;
V_141 = V_140 ;
}
static void F_57 ( void )
{
if ( V_83 != - 1 )
F_28 ( V_83 , V_98 ) ;
if ( V_141 == - 1 )
return;
signal ( V_141 , V_142 ) ;
F_28 ( F_58 () , V_141 ) ;
}
static int F_59 ( const struct V_143 * T_3 V_74 ,
const char * T_4 V_74 , int V_144 )
{
V_145 = V_144 ? 0 : 1 ;
return 0 ;
}
static int F_60 ( void )
{
struct V_1 * V_146 ;
T_5 V_147 = 0 ;
T_5 V_148 ;
if ( V_139 )
return 0 ;
if ( ! V_28 -> V_149 ) {
for ( V_148 = 0 ; V_148 < F_61 ( V_150 ) ; V_148 ++ ) {
V_146 = F_62 ( V_150 + V_148 , V_148 + V_147 ) ;
if ( V_146 == NULL )
return - 1 ;
F_63 ( V_28 , V_146 ) ;
}
V_147 += V_148 ;
}
if ( V_151 < 1 )
return 0 ;
for ( V_148 = 0 ; V_148 < F_61 ( V_152 ) ; V_148 ++ ) {
V_146 = F_62 ( V_152 + V_148 , V_148 + V_147 ) ;
if ( V_146 == NULL )
return - 1 ;
F_63 ( V_28 , V_146 ) ;
}
V_147 += V_148 ;
if ( V_151 < 2 )
return 0 ;
for ( V_148 = 0 ; V_148 < F_61 ( V_153 ) ; V_148 ++ ) {
V_146 = F_62 ( V_153 + V_148 , V_148 + V_147 ) ;
if ( V_146 == NULL )
return - 1 ;
F_63 ( V_28 , V_146 ) ;
}
if ( V_151 < 3 )
return 0 ;
for ( V_148 = 0 ; V_148 < F_61 ( V_154 ) ; V_148 ++ ) {
V_146 = F_62 ( V_154 + V_148 , V_148 + V_147 ) ;
if ( V_146 == NULL )
return - 1 ;
F_63 ( V_28 , V_146 ) ;
}
return 0 ;
}
int F_64 ( int T_2 , const char * * V_75 , const char * T_6 V_74 )
{
struct V_1 * V_146 ;
int V_78 = - V_5 ;
const char * V_155 ;
setlocale ( V_156 , L_6 ) ;
V_28 = F_65 ( NULL , NULL ) ;
if ( V_28 == NULL )
return - V_5 ;
T_2 = F_66 ( T_2 , V_75 , V_157 , V_158 ,
V_159 ) ;
V_71 = V_160 ;
if ( V_161 && strcmp ( V_161 , L_58 ) )
V_71 = NULL ;
if ( V_161 && V_162 ) {
fprintf ( V_160 , L_59 ) ;
F_67 ( V_158 , V_157 ) ;
}
if ( ! V_71 ) {
struct V_163 V_164 ;
V_155 = V_165 ? L_60 : L_61 ;
V_71 = fopen ( V_161 , V_155 ) ;
if ( ! V_71 ) {
perror ( L_62 ) ;
exit ( - 1 ) ;
}
F_68 ( V_166 , & V_164 ) ;
fprintf ( V_71 , L_63 , ctime ( & V_164 . V_167 ) ) ;
} else if ( V_162 != 2 ) {
V_155 = V_165 ? L_60 : L_61 ;
V_71 = fdopen ( V_162 , V_155 ) ;
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
V_106 = V_168 ;
if ( V_105 ) {
if ( V_145 == 1 ) {
fprintf ( V_160 , L_67 ) ;
F_67 ( V_158 , V_157 ) ;
} else
V_119 = false ;
} else if ( V_145 == 0 )
V_119 = false ;
if ( ! T_2 && V_30 == - 1 && V_31 == - 1 )
F_67 ( V_158 , V_157 ) ;
if ( V_107 <= 0 )
F_67 ( V_158 , V_157 ) ;
if ( ( V_101 || V_169 ) && ! V_27 ) {
fprintf ( V_160 , L_68
L_69 ) ;
F_67 ( V_158 , V_157 ) ;
}
if ( F_60 () )
goto V_170;
if ( V_30 != - 1 )
V_31 = V_30 ;
V_28 -> V_34 = F_69 ( V_30 , V_31 ) ;
if ( V_28 -> V_34 == NULL ) {
F_70 ( L_70 ) ;
F_67 ( V_158 , V_157 ) ;
}
if ( V_27 )
V_28 -> V_29 = F_71 ( V_171 ) ;
else
V_28 -> V_29 = F_72 () ;
if ( V_28 -> V_29 == NULL ) {
perror ( L_71 ) ;
F_67 ( V_158 , V_157 ) ;
return - 1 ;
}
F_26 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_146 ) < 0 ||
F_73 ( V_146 , V_28 -> V_29 -> V_68 ) < 0 ||
F_74 ( V_146 , V_28 -> V_29 -> V_68 , V_28 -> V_34 -> V_68 ) < 0 )
goto V_172;
}
atexit ( F_57 ) ;
signal ( V_173 , F_56 ) ;
signal ( V_174 , F_56 ) ;
signal ( V_175 , F_56 ) ;
V_78 = 0 ;
for ( V_176 = 0 ; V_176 < V_107 ; V_176 ++ ) {
if ( V_107 != 1 && V_70 )
fprintf ( V_71 , L_72 ,
V_176 + 1 ) ;
if ( V_177 )
F_75 () ;
V_78 = F_18 ( T_2 , V_75 ) ;
}
if ( V_78 != - 1 )
F_55 ( T_2 , V_75 ) ;
V_172:
F_26 (pos, &evsel_list->entries, node)
F_3 ( V_146 ) ;
F_76 ( V_28 ) ;
V_170:
F_77 ( V_28 ) ;
return V_78 ;
}
