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
return F_8 ( V_2 , V_23 -> V_24 , false ) ;
if ( V_25 == - 1 && V_26 == - 1 ) {
V_15 -> V_27 = 1 ;
V_15 -> V_28 = 1 ;
}
return F_9 ( V_2 , V_23 -> V_29 , false ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 , V_30 , V_31 ) ||
F_11 ( V_2 , V_30 , V_32 ) )
return 1 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_33 , T_1 * V_34 )
{
if ( F_11 ( V_33 , V_30 , V_32 ) )
F_4 ( & V_35 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_36 , V_37 ) )
F_4 ( & V_38 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_36 , V_39 ) )
F_4 ( & V_40 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_36 , V_41 ) )
F_4 ( & V_42 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_36 , V_43 ) )
F_4 ( & V_44 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_36 , V_45 ) )
F_4 ( & V_46 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_47 , V_48 ) )
F_4 ( & V_49 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_47 , V_50 ) )
F_4 ( & V_51 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_47 , V_52 ) )
F_4 ( & V_53 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_47 , V_54 ) )
F_4 ( & V_55 [ 0 ] , V_34 [ 0 ] ) ;
else if ( F_11 ( V_33 , V_47 , V_56 ) )
F_4 ( & V_57 [ 0 ] , V_34 [ 0 ] ) ;
}
static int F_13 ( struct V_1 * V_33 )
{
struct V_4 * V_58 = V_33 -> V_3 ;
T_1 * V_34 = V_33 -> V_59 -> V_60 . V_61 ;
int V_62 ;
if ( F_14 ( V_33 , V_23 -> V_24 -> V_63 ,
V_23 -> V_29 -> V_63 , V_16 ) < 0 )
return - 1 ;
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ )
F_4 ( & V_58 -> V_64 [ V_62 ] , V_34 [ V_62 ] ) ;
if ( V_65 ) {
fprintf ( V_66 , L_1 V_67 L_2 V_67 L_2 V_67 L_3 ,
F_15 ( V_33 ) , V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] ) ;
}
F_12 ( V_33 , V_34 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_33 )
{
T_1 * V_34 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_23 -> V_24 -> V_63 ; V_68 ++ ) {
if ( F_17 ( V_33 , V_68 , 0 , V_16 ) < 0 )
return - 1 ;
V_34 = V_33 -> V_59 -> V_68 [ V_68 ] . V_61 ;
F_12 ( V_33 , V_34 ) ;
}
return 0 ;
}
static int F_18 ( int T_2 V_69 , const char * * V_70 )
{
unsigned long long V_71 , V_72 ;
struct V_1 * V_33 ;
int V_73 = 0 ;
int V_74 [ 2 ] , V_75 [ 2 ] ;
const bool V_76 = ( T_2 > 0 ) ;
char V_77 ;
if ( V_76 && ( F_19 ( V_74 ) < 0 || F_19 ( V_75 ) < 0 ) ) {
perror ( L_4 ) ;
exit ( 1 ) ;
}
if ( V_76 ) {
if ( ( V_78 = F_20 () ) < 0 )
perror ( L_5 ) ;
if ( ! V_78 ) {
F_21 ( V_74 [ 0 ] ) ;
F_21 ( V_75 [ 1 ] ) ;
F_22 ( V_75 [ 0 ] , V_79 , V_80 ) ;
F_23 ( L_6 , ( char * * ) V_70 ) ;
F_21 ( V_74 [ 1 ] ) ;
if ( F_24 ( V_75 [ 0 ] , & V_77 , 1 ) == - 1 )
perror ( L_7 ) ;
F_23 ( V_70 [ 0 ] , ( char * * ) V_70 ) ;
perror ( V_70 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( V_26 == - 1 && V_25 == - 1 && ! V_22 )
V_23 -> V_29 -> V_81 [ 0 ] = V_78 ;
F_21 ( V_74 [ 1 ] ) ;
F_21 ( V_75 [ 0 ] ) ;
if ( F_24 ( V_74 [ 0 ] , & V_77 , 1 ) == - 1 )
perror ( L_7 ) ;
F_21 ( V_74 [ 0 ] ) ;
}
F_25 (counter, &evsel_list->entries, node) {
if ( F_7 ( V_33 ) < 0 ) {
if ( V_82 == V_83 || V_82 == V_84 || V_82 == V_85 ) {
if ( V_65 )
F_26 ( L_8 ,
F_15 ( V_33 ) ) ;
continue;
}
if ( V_82 == V_86 || V_82 == V_87 ) {
error ( L_9
L_10
L_11 ,
V_22 ? L_12 : L_6 ) ;
} else {
error ( L_13
L_14 ,
V_82 , strerror ( V_82 ) ) ;
}
if ( V_78 != - 1 )
F_27 ( V_78 , V_88 ) ;
F_28 ( L_15 ) ;
return - 1 ;
}
}
if ( F_29 ( V_23 ) ) {
error ( L_16 , V_82 ,
strerror ( V_82 ) ) ;
return - 1 ;
}
V_71 = F_30 () ;
if ( V_76 ) {
F_21 ( V_75 [ 1 ] ) ;
F_31 ( & V_73 ) ;
} else {
while( ! V_89 ) F_32 ( 1 ) ;
}
V_72 = F_30 () ;
F_4 ( & V_90 , V_72 - V_71 ) ;
if ( V_91 ) {
F_25 (counter, &evsel_list->entries, node) {
F_16 ( V_33 ) ;
F_33 ( V_33 , V_23 -> V_24 -> V_63 , 1 ) ;
}
} else {
F_25 (counter, &evsel_list->entries, node) {
F_13 ( V_33 ) ;
F_33 ( V_33 , V_23 -> V_24 -> V_63 ,
V_23 -> V_29 -> V_63 ) ;
}
}
return F_34 ( V_73 ) ;
}
static void F_35 ( double V_92 , double V_93 )
{
double V_94 = 0.0 ;
if ( V_93 )
V_94 = 100.0 * V_92 / V_93 ;
fprintf ( V_66 , L_17 , V_94 ) ;
}
static void F_36 ( struct V_1 * V_2 , double V_93 )
{
struct V_4 * V_58 ;
if ( V_95 == 1 )
return;
V_58 = V_2 -> V_3 ;
F_35 ( F_6 ( & V_58 -> V_64 [ 0 ] ) , V_93 ) ;
}
static void F_37 ( int V_68 , struct V_1 * V_2 , double V_93 )
{
double V_96 = V_93 / 1e6 ;
char V_97 [ 16 ] = { '\0' , } ;
const char * V_98 = V_99 ? L_18 : L_19 ;
if ( V_91 )
sprintf ( V_97 , L_20 ,
V_99 ? 0 : - 4 ,
V_23 -> V_24 -> V_81 [ V_68 ] , V_100 ) ;
fprintf ( V_66 , V_98 , V_97 , V_96 , V_100 , F_15 ( V_2 ) ) ;
if ( V_2 -> V_101 )
fprintf ( V_66 , L_21 , V_100 , V_2 -> V_101 -> V_102 ) ;
if ( V_99 )
return;
if ( F_11 ( V_2 , V_30 , V_32 ) )
fprintf ( V_66 , L_22 , V_93 / F_5 ( & V_90 ) ) ;
}
static void F_38 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_38 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 50.0 )
V_104 = V_106 ;
else if ( V_103 > 30.0 )
V_104 = V_107 ;
else if ( V_103 > 10.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_25 ) ;
}
static void F_40 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_38 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 75.0 )
V_104 = V_106 ;
else if ( V_103 > 50.0 )
V_104 = V_107 ;
else if ( V_103 > 20.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_26 ) ;
}
static void F_41 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_44 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 20.0 )
V_104 = V_106 ;
else if ( V_103 > 10.0 )
V_104 = V_107 ;
else if ( V_103 > 5.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_27 ) ;
}
static void F_42 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_49 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 20.0 )
V_104 = V_106 ;
else if ( V_103 > 10.0 )
V_104 = V_107 ;
else if ( V_103 > 5.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_28 ) ;
}
static void F_43 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_51 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 20.0 )
V_104 = V_106 ;
else if ( V_103 > 10.0 )
V_104 = V_107 ;
else if ( V_103 > 5.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_29 ) ;
}
static void F_44 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_55 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 20.0 )
V_104 = V_106 ;
else if ( V_103 > 10.0 )
V_104 = V_107 ;
else if ( V_103 > 5.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_30 ) ;
}
static void F_45 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_57 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 20.0 )
V_104 = V_106 ;
else if ( V_103 > 10.0 )
V_104 = V_107 ;
else if ( V_103 > 5.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_31 ) ;
}
static void F_46 ( int V_68 , struct V_1 * V_2 V_69 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
const char * V_104 ;
V_92 = F_5 ( & V_53 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 * 100.0 ;
V_104 = V_105 ;
if ( V_103 > 20.0 )
V_104 = V_106 ;
else if ( V_103 > 10.0 )
V_104 = V_107 ;
else if ( V_103 > 5.0 )
V_104 = V_108 ;
fprintf ( V_66 , L_23 ) ;
F_39 ( V_66 , V_104 , L_24 , V_103 ) ;
fprintf ( V_66 , L_32 ) ;
}
static void F_47 ( int V_68 , struct V_1 * V_2 , double V_93 )
{
double V_92 , V_103 = 0.0 ;
char V_97 [ 16 ] = { '\0' , } ;
const char * V_98 ;
if ( V_99 )
V_98 = L_33 ;
else if ( V_109 )
V_98 = L_34 ;
else
V_98 = L_35 ;
if ( V_91 )
sprintf ( V_97 , L_20 ,
V_99 ? 0 : - 4 ,
V_23 -> V_24 -> V_81 [ V_68 ] , V_100 ) ;
else
V_68 = 0 ;
fprintf ( V_66 , V_98 , V_97 , V_93 , V_100 , F_15 ( V_2 ) ) ;
if ( V_2 -> V_101 )
fprintf ( V_66 , L_21 , V_100 , V_2 -> V_101 -> V_102 ) ;
if ( V_99 )
return;
if ( F_11 ( V_2 , V_36 , V_110 ) ) {
V_92 = F_5 ( & V_38 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 / V_92 ;
fprintf ( V_66 , L_36 , V_103 ) ;
V_92 = F_5 ( & V_40 [ V_68 ] ) ;
V_92 = F_48 ( V_92 , F_5 ( & V_42 [ V_68 ] ) ) ;
if ( V_92 && V_93 ) {
V_103 = V_92 / V_93 ;
fprintf ( V_66 , L_37 , V_103 ) ;
}
} else if ( F_11 ( V_2 , V_36 , V_111 ) &&
V_44 [ V_68 ] . V_9 != 0 ) {
F_41 ( V_68 , V_2 , V_93 ) ;
} else if (
V_2 -> V_15 . type == V_112 &&
V_2 -> V_15 . V_113 == ( V_114 |
( ( V_115 ) << 8 ) |
( ( V_116 ) << 16 ) ) &&
V_49 [ V_68 ] . V_9 != 0 ) {
F_42 ( V_68 , V_2 , V_93 ) ;
} else if (
V_2 -> V_15 . type == V_112 &&
V_2 -> V_15 . V_113 == ( V_117 |
( ( V_115 ) << 8 ) |
( ( V_116 ) << 16 ) ) &&
V_51 [ V_68 ] . V_9 != 0 ) {
F_43 ( V_68 , V_2 , V_93 ) ;
} else if (
V_2 -> V_15 . type == V_112 &&
V_2 -> V_15 . V_113 == ( V_118 |
( ( V_115 ) << 8 ) |
( ( V_116 ) << 16 ) ) &&
V_55 [ V_68 ] . V_9 != 0 ) {
F_44 ( V_68 , V_2 , V_93 ) ;
} else if (
V_2 -> V_15 . type == V_112 &&
V_2 -> V_15 . V_113 == ( V_119 |
( ( V_115 ) << 8 ) |
( ( V_116 ) << 16 ) ) &&
V_57 [ V_68 ] . V_9 != 0 ) {
F_45 ( V_68 , V_2 , V_93 ) ;
} else if (
V_2 -> V_15 . type == V_112 &&
V_2 -> V_15 . V_113 == ( V_120 |
( ( V_115 ) << 8 ) |
( ( V_116 ) << 16 ) ) &&
V_53 [ V_68 ] . V_9 != 0 ) {
F_46 ( V_68 , V_2 , V_93 ) ;
} else if ( F_11 ( V_2 , V_36 , V_121 ) &&
V_46 [ V_68 ] . V_9 != 0 ) {
V_92 = F_5 ( & V_46 [ V_68 ] ) ;
if ( V_92 )
V_103 = V_93 * 100 / V_92 ;
fprintf ( V_66 , L_38 , V_103 ) ;
} else if ( F_11 ( V_2 , V_36 , V_39 ) ) {
F_38 ( V_68 , V_2 , V_93 ) ;
} else if ( F_11 ( V_2 , V_36 , V_41 ) ) {
F_40 ( V_68 , V_2 , V_93 ) ;
} else if ( F_11 ( V_2 , V_36 , V_37 ) ) {
V_92 = F_5 ( & V_35 [ V_68 ] ) ;
if ( V_92 )
V_103 = 1.0 * V_93 / V_92 ;
fprintf ( V_66 , L_39 , V_103 ) ;
} else if ( V_35 [ V_68 ] . V_9 != 0 ) {
V_92 = F_5 ( & V_35 [ V_68 ] ) ;
if ( V_92 )
V_103 = 1000.0 * V_93 / V_92 ;
fprintf ( V_66 , L_40 , V_103 ) ;
} else {
fprintf ( V_66 , L_41 ) ;
}
}
static void F_49 ( struct V_1 * V_33 )
{
struct V_4 * V_58 = V_33 -> V_3 ;
double V_93 = F_5 ( & V_58 -> V_64 [ 0 ] ) ;
int V_122 = V_33 -> V_59 -> V_122 ;
if ( V_122 == - 1 ) {
fprintf ( V_66 , L_42 ,
V_99 ? 0 : 18 ,
L_43 ,
V_100 ,
V_99 ? 0 : - 24 ,
F_15 ( V_33 ) ) ;
if ( V_33 -> V_101 )
fprintf ( V_66 , L_21 , V_100 , V_33 -> V_101 -> V_102 ) ;
fputc ( '\n' , V_66 ) ;
return;
}
if ( F_10 ( V_33 ) )
F_37 ( - 1 , V_33 , V_93 ) ;
else
F_47 ( - 1 , V_33 , V_93 ) ;
if ( V_99 ) {
fputc ( '\n' , V_66 ) ;
return;
}
F_36 ( V_33 , V_93 ) ;
if ( V_122 ) {
double V_123 , V_124 ;
V_123 = F_5 ( & V_58 -> V_64 [ 1 ] ) ;
V_124 = F_5 ( & V_58 -> V_64 [ 2 ] ) ;
fprintf ( V_66 , L_44 , 100 * V_124 / V_123 ) ;
}
fprintf ( V_66 , L_3 ) ;
}
static void F_50 ( struct V_1 * V_33 )
{
T_1 V_125 , V_126 , V_7 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_23 -> V_24 -> V_63 ; V_68 ++ ) {
V_7 = V_33 -> V_59 -> V_68 [ V_68 ] . V_7 ;
V_125 = V_33 -> V_59 -> V_68 [ V_68 ] . V_125 ;
V_126 = V_33 -> V_59 -> V_68 [ V_68 ] . V_126 ;
if ( V_126 == 0 || V_125 == 0 ) {
fprintf ( V_66 , L_45 ,
V_99 ? 0 : - 4 ,
V_23 -> V_24 -> V_81 [ V_68 ] , V_100 ,
V_99 ? 0 : 18 ,
L_43 , V_100 ,
V_99 ? 0 : - 24 ,
F_15 ( V_33 ) ) ;
if ( V_33 -> V_101 )
fprintf ( V_66 , L_21 , V_100 , V_33 -> V_101 -> V_102 ) ;
fputc ( '\n' , V_66 ) ;
continue;
}
if ( F_10 ( V_33 ) )
F_37 ( V_68 , V_33 , V_7 ) ;
else
F_47 ( V_68 , V_33 , V_7 ) ;
if ( ! V_99 ) {
F_36 ( V_33 , 1.0 ) ;
if ( V_126 != V_125 )
fprintf ( V_66 , L_46 , 100.0 * V_126 / V_125 ) ;
}
fputc ( '\n' , V_66 ) ;
}
}
static void F_51 ( int T_2 , const char * * V_70 )
{
struct V_1 * V_33 ;
int V_62 ;
fflush ( stdout ) ;
if ( ! V_99 ) {
fprintf ( V_66 , L_3 ) ;
fprintf ( V_66 , L_47 ) ;
if( V_25 == - 1 && V_26 == - 1 ) {
fprintf ( V_66 , L_48 , V_70 [ 0 ] ) ;
for ( V_62 = 1 ; V_62 < T_2 ; V_62 ++ )
fprintf ( V_66 , L_49 , V_70 [ V_62 ] ) ;
} else if ( V_25 != - 1 )
fprintf ( V_66 , L_50 , V_25 ) ;
else
fprintf ( V_66 , L_51 , V_26 ) ;
fprintf ( V_66 , L_52 ) ;
if ( V_95 > 1 )
fprintf ( V_66 , L_53 , V_95 ) ;
fprintf ( V_66 , L_54 ) ;
}
if ( V_91 ) {
F_25 (counter, &evsel_list->entries, node)
F_50 ( V_33 ) ;
} else {
F_25 (counter, &evsel_list->entries, node)
F_49 ( V_33 ) ;
}
if ( ! V_99 ) {
if ( ! V_127 )
fprintf ( V_66 , L_3 ) ;
fprintf ( V_66 , L_55 ,
F_5 ( & V_90 ) / 1e9 ) ;
if ( V_95 > 1 ) {
fprintf ( V_66 , L_56 ) ;
F_35 ( F_6 ( & V_90 ) ,
F_5 ( & V_90 ) ) ;
}
fprintf ( V_66 , L_57 ) ;
}
}
static void F_52 ( int V_128 )
{
if( V_78 == - 1 )
V_89 = 1 ;
V_129 = V_128 ;
}
static void F_53 ( void )
{
if ( V_78 != - 1 )
F_27 ( V_78 , V_88 ) ;
if ( V_129 == - 1 )
return;
signal ( V_129 , V_130 ) ;
F_27 ( F_54 () , V_129 ) ;
}
static int F_55 ( const struct V_131 * T_3 V_69 ,
const char * T_4 V_69 , int V_132 )
{
V_133 = V_132 ? 0 : 1 ;
return 0 ;
}
static int F_56 ( void )
{
struct V_1 * V_134 ;
T_5 V_135 = 0 ;
T_5 V_136 ;
if ( V_127 )
return 0 ;
if ( ! V_23 -> V_137 ) {
for ( V_136 = 0 ; V_136 < F_57 ( V_138 ) ; V_136 ++ ) {
V_134 = F_58 ( V_138 + V_136 , V_136 + V_135 ) ;
if ( V_134 == NULL )
return - 1 ;
F_59 ( V_23 , V_134 ) ;
}
V_135 += V_136 ;
}
if ( V_139 < 1 )
return 0 ;
for ( V_136 = 0 ; V_136 < F_57 ( V_140 ) ; V_136 ++ ) {
V_134 = F_58 ( V_140 + V_136 , V_136 + V_135 ) ;
if ( V_134 == NULL )
return - 1 ;
F_59 ( V_23 , V_134 ) ;
}
V_135 += V_136 ;
if ( V_139 < 2 )
return 0 ;
for ( V_136 = 0 ; V_136 < F_57 ( V_141 ) ; V_136 ++ ) {
V_134 = F_58 ( V_141 + V_136 , V_136 + V_135 ) ;
if ( V_134 == NULL )
return - 1 ;
F_59 ( V_23 , V_134 ) ;
}
if ( V_139 < 3 )
return 0 ;
for ( V_136 = 0 ; V_136 < F_57 ( V_142 ) ; V_136 ++ ) {
V_134 = F_58 ( V_142 + V_136 , V_136 + V_135 ) ;
if ( V_134 == NULL )
return - 1 ;
F_59 ( V_23 , V_134 ) ;
}
return 0 ;
}
int F_60 ( int T_2 , const char * * V_70 , const char * T_6 V_69 )
{
struct V_1 * V_134 ;
int V_73 = - V_5 ;
setlocale ( V_143 , L_6 ) ;
V_23 = F_61 ( NULL , NULL ) ;
if ( V_23 == NULL )
return - V_5 ;
T_2 = F_62 ( T_2 , V_70 , V_144 , V_145 ,
V_146 ) ;
if ( V_100 )
V_99 = true ;
else
V_100 = V_147 ;
if ( V_99 ) {
if ( V_133 == 1 ) {
fprintf ( V_66 , L_58 ) ;
F_63 ( V_145 , V_144 ) ;
} else
V_109 = false ;
} else if ( V_133 == 0 )
V_109 = false ;
if ( ! T_2 && V_25 == - 1 && V_26 == - 1 )
F_63 ( V_145 , V_144 ) ;
if ( V_95 <= 0 )
F_63 ( V_145 , V_144 ) ;
if ( ( V_91 || V_148 ) && ! V_22 ) {
fprintf ( V_66 , L_59
L_60 ) ;
F_63 ( V_145 , V_144 ) ;
}
if ( F_56 () )
goto V_149;
if ( V_25 != - 1 )
V_26 = V_25 ;
V_23 -> V_29 = F_64 ( V_25 , V_26 ) ;
if ( V_23 -> V_29 == NULL ) {
F_65 ( L_61 ) ;
F_63 ( V_145 , V_144 ) ;
}
if ( V_22 )
V_23 -> V_24 = F_66 ( V_150 ) ;
else
V_23 -> V_24 = F_67 () ;
if ( V_23 -> V_24 == NULL ) {
perror ( L_62 ) ;
F_63 ( V_145 , V_144 ) ;
return - 1 ;
}
F_25 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_134 ) < 0 ||
F_68 ( V_134 , V_23 -> V_24 -> V_63 ) < 0 ||
F_69 ( V_134 , V_23 -> V_24 -> V_63 , V_23 -> V_29 -> V_63 ) < 0 )
goto V_151;
}
atexit ( F_53 ) ;
signal ( V_152 , F_52 ) ;
signal ( V_153 , F_52 ) ;
signal ( V_154 , F_52 ) ;
V_73 = 0 ;
for ( V_155 = 0 ; V_155 < V_95 ; V_155 ++ ) {
if ( V_95 != 1 && V_65 )
fprintf ( V_66 , L_63 , V_155 + 1 ) ;
if ( V_156 )
F_70 () ;
V_73 = F_18 ( T_2 , V_70 ) ;
}
if ( V_73 != - 1 )
F_51 ( T_2 , V_70 ) ;
V_151:
F_25 (pos, &evsel_list->entries, node)
F_3 ( V_134 ) ;
F_71 ( V_23 ) ;
V_149:
F_72 ( V_23 ) ;
return V_73 ;
}
