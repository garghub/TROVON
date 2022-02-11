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
double V_12 = V_6 -> V_11 / ( V_6 -> V_9 - 1 ) ;
double V_13 = V_12 / V_6 -> V_9 ;
return sqrt ( V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
if ( V_16 )
V_15 -> V_17 = V_18 |
V_19 ;
V_15 -> V_20 = ! V_21 ;
if ( V_22 )
return F_8 ( V_2 , V_23 -> V_24 , V_25 ) ;
if ( V_26 == - 1 && V_27 == - 1 ) {
V_15 -> V_28 = 1 ;
V_15 -> V_29 = 1 ;
}
return F_9 ( V_2 , V_23 -> V_30 , V_25 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 , V_31 , V_32 ) ||
F_11 ( V_2 , V_31 , V_33 ) )
return 1 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_34 , T_1 * V_35 )
{
if ( F_11 ( V_34 , V_31 , V_33 ) )
F_4 ( & V_36 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_37 , V_38 ) )
F_4 ( & V_39 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_37 , V_40 ) )
F_4 ( & V_41 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_37 , V_42 ) )
F_4 ( & V_43 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_37 , V_44 ) )
F_4 ( & V_45 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_37 , V_46 ) )
F_4 ( & V_47 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_48 , V_49 ) )
F_4 ( & V_50 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_48 , V_51 ) )
F_4 ( & V_52 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_48 , V_53 ) )
F_4 ( & V_54 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_48 , V_55 ) )
F_4 ( & V_56 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_11 ( V_34 , V_48 , V_57 ) )
F_4 ( & V_58 [ 0 ] , V_35 [ 0 ] ) ;
}
static int F_13 ( struct V_1 * V_34 )
{
struct V_4 * V_59 = V_34 -> V_3 ;
T_1 * V_35 = V_34 -> V_60 -> V_61 . V_62 ;
int V_63 ;
if ( F_14 ( V_34 , V_23 -> V_24 -> V_64 ,
V_23 -> V_30 -> V_64 , V_16 ) < 0 )
return - 1 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ )
F_4 ( & V_59 -> V_65 [ V_63 ] , V_35 [ V_63 ] ) ;
if ( V_66 ) {
fprintf ( V_67 , L_1 V_68 L_2 V_68 L_2 V_68 L_3 ,
F_15 ( V_34 ) , V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] ) ;
}
F_12 ( V_34 , V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_34 )
{
T_1 * V_35 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_23 -> V_24 -> V_64 ; V_69 ++ ) {
if ( F_17 ( V_34 , V_69 , 0 , V_16 ) < 0 )
return - 1 ;
V_35 = V_34 -> V_60 -> V_69 [ V_69 ] . V_62 ;
F_12 ( V_34 , V_35 ) ;
}
return 0 ;
}
static int F_18 ( int T_2 V_70 , const char * * V_71 )
{
unsigned long long V_72 , V_73 ;
struct V_1 * V_34 ;
int V_74 = 0 ;
int V_75 [ 2 ] , V_76 [ 2 ] ;
const bool V_77 = ( T_2 > 0 ) ;
char V_78 ;
if ( V_77 && ( F_19 ( V_75 ) < 0 || F_19 ( V_76 ) < 0 ) ) {
perror ( L_4 ) ;
exit ( 1 ) ;
}
if ( V_77 ) {
if ( ( V_79 = F_20 () ) < 0 )
perror ( L_5 ) ;
if ( ! V_79 ) {
F_21 ( V_75 [ 0 ] ) ;
F_21 ( V_76 [ 1 ] ) ;
F_22 ( V_76 [ 0 ] , V_80 , V_81 ) ;
F_23 ( L_6 , ( char * * ) V_71 ) ;
F_21 ( V_75 [ 1 ] ) ;
if ( F_24 ( V_76 [ 0 ] , & V_78 , 1 ) == - 1 )
perror ( L_7 ) ;
F_23 ( V_71 [ 0 ] , ( char * * ) V_71 ) ;
perror ( V_71 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( V_27 == - 1 && V_26 == - 1 && ! V_22 )
V_23 -> V_30 -> V_82 [ 0 ] = V_79 ;
F_21 ( V_75 [ 1 ] ) ;
F_21 ( V_76 [ 0 ] ) ;
if ( F_24 ( V_75 [ 0 ] , & V_78 , 1 ) == - 1 )
perror ( L_7 ) ;
F_21 ( V_75 [ 0 ] ) ;
}
F_25 (counter, &evsel_list->entries, node) {
if ( F_7 ( V_34 ) < 0 ) {
if ( V_83 == V_84 || V_83 == V_85 || V_83 == V_86 ) {
if ( V_66 )
F_26 ( L_8 ,
F_15 ( V_34 ) ) ;
V_34 -> V_87 = false ;
continue;
}
if ( V_83 == V_88 || V_83 == V_89 ) {
error ( L_9
L_10
L_11 ,
V_22 ? L_12 : L_6 ) ;
} else {
error ( L_13
L_14 ,
V_83 , strerror ( V_83 ) ) ;
}
if ( V_79 != - 1 )
F_27 ( V_79 , V_90 ) ;
F_28 ( L_15 ) ;
return - 1 ;
}
V_34 -> V_87 = true ;
}
if ( F_29 ( V_23 ) ) {
error ( L_16 , V_83 ,
strerror ( V_83 ) ) ;
return - 1 ;
}
V_72 = F_30 () ;
if ( V_77 ) {
F_21 ( V_76 [ 1 ] ) ;
F_31 ( & V_74 ) ;
} else {
while( ! V_91 ) F_32 ( 1 ) ;
}
V_73 = F_30 () ;
F_4 ( & V_92 , V_73 - V_72 ) ;
if ( V_93 ) {
F_25 (counter, &evsel_list->entries, node) {
F_16 ( V_34 ) ;
F_33 ( V_34 , V_23 -> V_24 -> V_64 , 1 ) ;
}
} else {
F_25 (counter, &evsel_list->entries, node) {
F_13 ( V_34 ) ;
F_33 ( V_34 , V_23 -> V_24 -> V_64 ,
V_23 -> V_30 -> V_64 ) ;
}
}
return F_34 ( V_74 ) ;
}
static void F_35 ( double V_94 , double V_95 )
{
double V_96 = 0.0 ;
if ( V_95 )
V_96 = 100.0 * V_94 / V_95 ;
if ( V_97 )
fprintf ( V_67 , L_17 , V_98 , V_96 ) ;
else
fprintf ( V_67 , L_18 , V_96 ) ;
}
static void F_36 ( struct V_1 * V_2 , double V_95 )
{
struct V_4 * V_59 ;
if ( V_99 == 1 )
return;
V_59 = V_2 -> V_3 ;
F_35 ( F_6 ( & V_59 -> V_65 [ 0 ] ) , V_95 ) ;
}
static void F_37 ( int V_69 , struct V_1 * V_2 , double V_95 )
{
double V_100 = V_95 / 1e6 ;
char V_101 [ 16 ] = { '\0' , } ;
const char * V_102 = V_97 ? L_19 : L_20 ;
if ( V_93 )
sprintf ( V_101 , L_21 ,
V_97 ? 0 : - 4 ,
V_23 -> V_24 -> V_82 [ V_69 ] , V_98 ) ;
fprintf ( V_67 , V_102 , V_101 , V_100 , V_98 , F_15 ( V_2 ) ) ;
if ( V_2 -> V_103 )
fprintf ( V_67 , L_22 , V_98 , V_2 -> V_103 -> V_104 ) ;
if ( V_97 )
return;
if ( F_11 ( V_2 , V_31 , V_33 ) )
fprintf ( V_67 , L_23 , V_95 / F_5 ( & V_92 ) ) ;
}
static void F_38 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_39 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 50.0 )
V_106 = V_108 ;
else if ( V_105 > 30.0 )
V_106 = V_109 ;
else if ( V_105 > 10.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_26 ) ;
}
static void F_40 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_39 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 75.0 )
V_106 = V_108 ;
else if ( V_105 > 50.0 )
V_106 = V_109 ;
else if ( V_105 > 20.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_27 ) ;
}
static void F_41 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_45 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 20.0 )
V_106 = V_108 ;
else if ( V_105 > 10.0 )
V_106 = V_109 ;
else if ( V_105 > 5.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_28 ) ;
}
static void F_42 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_50 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 20.0 )
V_106 = V_108 ;
else if ( V_105 > 10.0 )
V_106 = V_109 ;
else if ( V_105 > 5.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_29 ) ;
}
static void F_43 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_52 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 20.0 )
V_106 = V_108 ;
else if ( V_105 > 10.0 )
V_106 = V_109 ;
else if ( V_105 > 5.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_30 ) ;
}
static void F_44 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_56 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 20.0 )
V_106 = V_108 ;
else if ( V_105 > 10.0 )
V_106 = V_109 ;
else if ( V_105 > 5.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_31 ) ;
}
static void F_45 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_58 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 20.0 )
V_106 = V_108 ;
else if ( V_105 > 10.0 )
V_106 = V_109 ;
else if ( V_105 > 5.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_32 ) ;
}
static void F_46 ( int V_69 , struct V_1 * V_2 V_70 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
const char * V_106 ;
V_94 = F_5 ( & V_54 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 * 100.0 ;
V_106 = V_107 ;
if ( V_105 > 20.0 )
V_106 = V_108 ;
else if ( V_105 > 10.0 )
V_106 = V_109 ;
else if ( V_105 > 5.0 )
V_106 = V_110 ;
fprintf ( V_67 , L_24 ) ;
F_39 ( V_67 , V_106 , L_25 , V_105 ) ;
fprintf ( V_67 , L_33 ) ;
}
static void F_47 ( int V_69 , struct V_1 * V_2 , double V_95 )
{
double V_94 , V_105 = 0.0 ;
char V_101 [ 16 ] = { '\0' , } ;
const char * V_102 ;
if ( V_97 )
V_102 = L_34 ;
else if ( V_111 )
V_102 = L_35 ;
else
V_102 = L_36 ;
if ( V_93 )
sprintf ( V_101 , L_21 ,
V_97 ? 0 : - 4 ,
V_23 -> V_24 -> V_82 [ V_69 ] , V_98 ) ;
else
V_69 = 0 ;
fprintf ( V_67 , V_102 , V_101 , V_95 , V_98 , F_15 ( V_2 ) ) ;
if ( V_2 -> V_103 )
fprintf ( V_67 , L_22 , V_98 , V_2 -> V_103 -> V_104 ) ;
if ( V_97 )
return;
if ( F_11 ( V_2 , V_37 , V_112 ) ) {
V_94 = F_5 ( & V_39 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 / V_94 ;
fprintf ( V_67 , L_37 , V_105 ) ;
V_94 = F_5 ( & V_41 [ V_69 ] ) ;
V_94 = F_48 ( V_94 , F_5 ( & V_43 [ V_69 ] ) ) ;
if ( V_94 && V_95 ) {
V_105 = V_94 / V_95 ;
fprintf ( V_67 , L_38 , V_105 ) ;
}
} else if ( F_11 ( V_2 , V_37 , V_113 ) &&
V_45 [ V_69 ] . V_9 != 0 ) {
F_41 ( V_69 , V_2 , V_95 ) ;
} else if (
V_2 -> V_15 . type == V_114 &&
V_2 -> V_15 . V_115 == ( V_116 |
( ( V_117 ) << 8 ) |
( ( V_118 ) << 16 ) ) &&
V_50 [ V_69 ] . V_9 != 0 ) {
F_42 ( V_69 , V_2 , V_95 ) ;
} else if (
V_2 -> V_15 . type == V_114 &&
V_2 -> V_15 . V_115 == ( V_119 |
( ( V_117 ) << 8 ) |
( ( V_118 ) << 16 ) ) &&
V_52 [ V_69 ] . V_9 != 0 ) {
F_43 ( V_69 , V_2 , V_95 ) ;
} else if (
V_2 -> V_15 . type == V_114 &&
V_2 -> V_15 . V_115 == ( V_120 |
( ( V_117 ) << 8 ) |
( ( V_118 ) << 16 ) ) &&
V_56 [ V_69 ] . V_9 != 0 ) {
F_44 ( V_69 , V_2 , V_95 ) ;
} else if (
V_2 -> V_15 . type == V_114 &&
V_2 -> V_15 . V_115 == ( V_121 |
( ( V_117 ) << 8 ) |
( ( V_118 ) << 16 ) ) &&
V_58 [ V_69 ] . V_9 != 0 ) {
F_45 ( V_69 , V_2 , V_95 ) ;
} else if (
V_2 -> V_15 . type == V_114 &&
V_2 -> V_15 . V_115 == ( V_122 |
( ( V_117 ) << 8 ) |
( ( V_118 ) << 16 ) ) &&
V_54 [ V_69 ] . V_9 != 0 ) {
F_46 ( V_69 , V_2 , V_95 ) ;
} else if ( F_11 ( V_2 , V_37 , V_123 ) &&
V_47 [ V_69 ] . V_9 != 0 ) {
V_94 = F_5 ( & V_47 [ V_69 ] ) ;
if ( V_94 )
V_105 = V_95 * 100 / V_94 ;
fprintf ( V_67 , L_39 , V_105 ) ;
} else if ( F_11 ( V_2 , V_37 , V_40 ) ) {
F_38 ( V_69 , V_2 , V_95 ) ;
} else if ( F_11 ( V_2 , V_37 , V_42 ) ) {
F_40 ( V_69 , V_2 , V_95 ) ;
} else if ( F_11 ( V_2 , V_37 , V_38 ) ) {
V_94 = F_5 ( & V_36 [ V_69 ] ) ;
if ( V_94 )
V_105 = 1.0 * V_95 / V_94 ;
fprintf ( V_67 , L_40 , V_105 ) ;
} else if ( V_36 [ V_69 ] . V_9 != 0 ) {
V_94 = F_5 ( & V_36 [ V_69 ] ) ;
if ( V_94 )
V_105 = 1000.0 * V_95 / V_94 ;
fprintf ( V_67 , L_41 , V_105 ) ;
} else {
fprintf ( V_67 , L_42 ) ;
}
}
static void F_49 ( struct V_1 * V_34 )
{
struct V_4 * V_59 = V_34 -> V_3 ;
double V_95 = F_5 ( & V_59 -> V_65 [ 0 ] ) ;
int V_124 = V_34 -> V_60 -> V_124 ;
if ( V_124 == - 1 ) {
fprintf ( V_67 , L_43 ,
V_97 ? 0 : 18 ,
V_34 -> V_87 ? V_125 : V_126 ,
V_98 ,
V_97 ? 0 : - 24 ,
F_15 ( V_34 ) ) ;
if ( V_34 -> V_103 )
fprintf ( V_67 , L_22 , V_98 , V_34 -> V_103 -> V_104 ) ;
fputc ( '\n' , V_67 ) ;
return;
}
if ( F_10 ( V_34 ) )
F_37 ( - 1 , V_34 , V_95 ) ;
else
F_47 ( - 1 , V_34 , V_95 ) ;
F_36 ( V_34 , V_95 ) ;
if ( V_97 ) {
fputc ( '\n' , V_67 ) ;
return;
}
if ( V_124 ) {
double V_127 , V_128 ;
V_127 = F_5 ( & V_59 -> V_65 [ 1 ] ) ;
V_128 = F_5 ( & V_59 -> V_65 [ 2 ] ) ;
fprintf ( V_67 , L_44 , 100 * V_128 / V_127 ) ;
}
fprintf ( V_67 , L_3 ) ;
}
static void F_50 ( struct V_1 * V_34 )
{
T_1 V_129 , V_130 , V_7 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_23 -> V_24 -> V_64 ; V_69 ++ ) {
V_7 = V_34 -> V_60 -> V_69 [ V_69 ] . V_7 ;
V_129 = V_34 -> V_60 -> V_69 [ V_69 ] . V_129 ;
V_130 = V_34 -> V_60 -> V_69 [ V_69 ] . V_130 ;
if ( V_130 == 0 || V_129 == 0 ) {
fprintf ( V_67 , L_45 ,
V_97 ? 0 : - 4 ,
V_23 -> V_24 -> V_82 [ V_69 ] , V_98 ,
V_97 ? 0 : 18 ,
V_34 -> V_87 ? V_125 : V_126 ,
V_98 ,
V_97 ? 0 : - 24 ,
F_15 ( V_34 ) ) ;
if ( V_34 -> V_103 )
fprintf ( V_67 , L_22 , V_98 , V_34 -> V_103 -> V_104 ) ;
fputc ( '\n' , V_67 ) ;
continue;
}
if ( F_10 ( V_34 ) )
F_37 ( V_69 , V_34 , V_7 ) ;
else
F_47 ( V_69 , V_34 , V_7 ) ;
if ( ! V_97 ) {
F_36 ( V_34 , 1.0 ) ;
if ( V_130 != V_129 )
fprintf ( V_67 , L_46 , 100.0 * V_130 / V_129 ) ;
}
fputc ( '\n' , V_67 ) ;
}
}
static void F_51 ( int T_2 , const char * * V_71 )
{
struct V_1 * V_34 ;
int V_63 ;
fflush ( stdout ) ;
if ( ! V_97 ) {
fprintf ( V_67 , L_3 ) ;
fprintf ( V_67 , L_47 ) ;
if( V_26 == - 1 && V_27 == - 1 ) {
fprintf ( V_67 , L_48 , V_71 [ 0 ] ) ;
for ( V_63 = 1 ; V_63 < T_2 ; V_63 ++ )
fprintf ( V_67 , L_49 , V_71 [ V_63 ] ) ;
} else if ( V_26 != - 1 )
fprintf ( V_67 , L_50 , V_26 ) ;
else
fprintf ( V_67 , L_51 , V_27 ) ;
fprintf ( V_67 , L_52 ) ;
if ( V_99 > 1 )
fprintf ( V_67 , L_53 , V_99 ) ;
fprintf ( V_67 , L_54 ) ;
}
if ( V_93 ) {
F_25 (counter, &evsel_list->entries, node)
F_50 ( V_34 ) ;
} else {
F_25 (counter, &evsel_list->entries, node)
F_49 ( V_34 ) ;
}
if ( ! V_97 ) {
if ( ! V_131 )
fprintf ( V_67 , L_3 ) ;
fprintf ( V_67 , L_55 ,
F_5 ( & V_92 ) / 1e9 ) ;
if ( V_99 > 1 ) {
fprintf ( V_67 , L_56 ) ;
F_35 ( F_6 ( & V_92 ) ,
F_5 ( & V_92 ) ) ;
}
fprintf ( V_67 , L_57 ) ;
}
}
static void F_52 ( int V_132 )
{
if( V_79 == - 1 )
V_91 = 1 ;
V_133 = V_132 ;
}
static void F_53 ( void )
{
if ( V_79 != - 1 )
F_27 ( V_79 , V_90 ) ;
if ( V_133 == - 1 )
return;
signal ( V_133 , V_134 ) ;
F_27 ( F_54 () , V_133 ) ;
}
static int F_55 ( const struct V_135 * T_3 V_70 ,
const char * T_4 V_70 , int V_136 )
{
V_137 = V_136 ? 0 : 1 ;
return 0 ;
}
static int F_56 ( void )
{
struct V_1 * V_138 ;
T_5 V_139 = 0 ;
T_5 V_140 ;
if ( V_131 )
return 0 ;
if ( ! V_23 -> V_141 ) {
for ( V_140 = 0 ; V_140 < F_57 ( V_142 ) ; V_140 ++ ) {
V_138 = F_58 ( V_142 + V_140 , V_140 + V_139 ) ;
if ( V_138 == NULL )
return - 1 ;
F_59 ( V_23 , V_138 ) ;
}
V_139 += V_140 ;
}
if ( V_143 < 1 )
return 0 ;
for ( V_140 = 0 ; V_140 < F_57 ( V_144 ) ; V_140 ++ ) {
V_138 = F_58 ( V_144 + V_140 , V_140 + V_139 ) ;
if ( V_138 == NULL )
return - 1 ;
F_59 ( V_23 , V_138 ) ;
}
V_139 += V_140 ;
if ( V_143 < 2 )
return 0 ;
for ( V_140 = 0 ; V_140 < F_57 ( V_145 ) ; V_140 ++ ) {
V_138 = F_58 ( V_145 + V_140 , V_140 + V_139 ) ;
if ( V_138 == NULL )
return - 1 ;
F_59 ( V_23 , V_138 ) ;
}
if ( V_143 < 3 )
return 0 ;
for ( V_140 = 0 ; V_140 < F_57 ( V_146 ) ; V_140 ++ ) {
V_138 = F_58 ( V_146 + V_140 , V_140 + V_139 ) ;
if ( V_138 == NULL )
return - 1 ;
F_59 ( V_23 , V_138 ) ;
}
return 0 ;
}
int F_60 ( int T_2 , const char * * V_71 , const char * T_6 V_70 )
{
struct V_1 * V_138 ;
int V_74 = - V_5 ;
setlocale ( V_147 , L_6 ) ;
V_23 = F_61 ( NULL , NULL ) ;
if ( V_23 == NULL )
return - V_5 ;
T_2 = F_62 ( T_2 , V_71 , V_148 , V_149 ,
V_150 ) ;
if ( V_98 )
V_97 = true ;
else
V_98 = V_151 ;
if ( V_97 ) {
if ( V_137 == 1 ) {
fprintf ( V_67 , L_58 ) ;
F_63 ( V_149 , V_148 ) ;
} else
V_111 = false ;
} else if ( V_137 == 0 )
V_111 = false ;
if ( ! T_2 && V_26 == - 1 && V_27 == - 1 )
F_63 ( V_149 , V_148 ) ;
if ( V_99 <= 0 )
F_63 ( V_149 , V_148 ) ;
if ( ( V_93 || V_152 ) && ! V_22 ) {
fprintf ( V_67 , L_59
L_60 ) ;
F_63 ( V_149 , V_148 ) ;
}
if ( F_56 () )
goto V_153;
if ( V_26 != - 1 )
V_27 = V_26 ;
V_23 -> V_30 = F_64 ( V_26 , V_27 ) ;
if ( V_23 -> V_30 == NULL ) {
F_65 ( L_61 ) ;
F_63 ( V_149 , V_148 ) ;
}
if ( V_22 )
V_23 -> V_24 = F_66 ( V_154 ) ;
else
V_23 -> V_24 = F_67 () ;
if ( V_23 -> V_24 == NULL ) {
perror ( L_62 ) ;
F_63 ( V_149 , V_148 ) ;
return - 1 ;
}
F_25 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_138 ) < 0 ||
F_68 ( V_138 , V_23 -> V_24 -> V_64 ) < 0 ||
F_69 ( V_138 , V_23 -> V_24 -> V_64 , V_23 -> V_30 -> V_64 ) < 0 )
goto V_155;
}
atexit ( F_53 ) ;
signal ( V_156 , F_52 ) ;
signal ( V_157 , F_52 ) ;
signal ( V_158 , F_52 ) ;
V_74 = 0 ;
for ( V_159 = 0 ; V_159 < V_99 ; V_159 ++ ) {
if ( V_99 != 1 && V_66 )
fprintf ( V_67 , L_63 , V_159 + 1 ) ;
if ( V_160 )
F_70 () ;
V_74 = F_18 ( T_2 , V_71 ) ;
}
if ( V_74 != - 1 )
F_51 ( T_2 , V_71 ) ;
V_155:
F_25 (pos, &evsel_list->entries, node)
F_3 ( V_138 ) ;
F_71 ( V_23 ) ;
V_153:
F_72 ( V_23 ) ;
return V_74 ;
}
