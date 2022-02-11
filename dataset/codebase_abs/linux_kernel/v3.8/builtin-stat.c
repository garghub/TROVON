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
static inline struct V_6 * F_4 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 && ! V_8 . V_9 ) ? V_2 -> V_7 : V_10 -> V_7 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) -> V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_13 ;
bool V_14 = false ;
int V_15 ;
if ( V_16 )
V_13 -> V_17 = V_18 |
V_19 ;
V_13 -> V_20 = ! V_21 ;
V_22:
if ( V_14 )
V_2 -> V_13 . V_23 = V_2 -> V_13 . V_24 = 0 ;
if ( F_7 ( & V_8 ) ) {
V_15 = F_8 ( V_2 , F_4 ( V_2 ) ) ;
if ( V_15 )
goto V_25;
return 0 ;
}
if ( ! F_9 ( & V_8 ) &&
! F_10 ( V_2 ) ) {
V_13 -> V_26 = 1 ;
V_13 -> V_27 = 1 ;
}
V_15 = F_11 ( V_2 , V_10 -> V_28 ) ;
if ( ! V_15 )
return 0 ;
V_25:
if ( V_15 && V_29 == V_30 ) {
if ( ! V_14 &&
( V_2 -> V_13 . V_23 || V_2 -> V_13 . V_24 ) ) {
F_12 ( L_1
L_2 ) ;
V_14 = true ;
goto V_22;
}
}
return V_15 ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 , V_31 , V_32 ) ||
F_14 ( V_2 , V_31 , V_33 ) )
return 1 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_34 , T_1 * V_35 )
{
if ( F_14 ( V_34 , V_31 , V_33 ) )
F_16 ( & V_36 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_37 , V_38 ) )
F_16 ( & V_39 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_37 , V_40 ) )
F_16 ( & V_41 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_37 , V_42 ) )
F_16 ( & V_43 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_37 , V_44 ) )
F_16 ( & V_45 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_37 , V_46 ) )
F_16 ( & V_47 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_48 , V_49 ) )
F_16 ( & V_50 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_48 , V_51 ) )
F_16 ( & V_52 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_48 , V_53 ) )
F_16 ( & V_54 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_48 , V_55 ) )
F_16 ( & V_56 [ 0 ] , V_35 [ 0 ] ) ;
else if ( F_14 ( V_34 , V_48 , V_57 ) )
F_16 ( & V_58 [ 0 ] , V_35 [ 0 ] ) ;
}
static int F_17 ( struct V_1 * V_34 )
{
struct V_4 * V_59 = V_34 -> V_3 ;
T_1 * V_35 = V_34 -> V_60 -> V_61 . V_62 ;
int V_63 ;
if ( F_18 ( V_34 , F_5 ( V_34 ) ,
V_10 -> V_28 -> V_11 , V_16 ) < 0 )
return - 1 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ )
F_16 ( & V_59 -> V_64 [ V_63 ] , V_35 [ V_63 ] ) ;
if ( V_65 ) {
fprintf ( V_66 , L_3 V_67 L_4 V_67 L_4 V_67 L_5 ,
F_19 ( V_34 ) , V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] ) ;
}
F_15 ( V_34 , V_35 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_34 )
{
T_1 * V_35 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < F_5 ( V_34 ) ; V_68 ++ ) {
if ( F_21 ( V_34 , V_68 , 0 , V_16 ) < 0 )
return - 1 ;
V_35 = V_34 -> V_60 -> V_68 [ V_68 ] . V_62 ;
F_15 ( V_34 , V_35 ) ;
}
return 0 ;
}
static int F_22 ( int T_2 V_69 , const char * * V_70 )
{
unsigned long long V_71 , V_72 ;
struct V_1 * V_34 ;
int V_73 = 0 ;
int V_74 [ 2 ] , V_75 [ 2 ] ;
const bool V_76 = ( T_2 > 0 ) ;
char V_77 ;
if ( V_76 && ( F_23 ( V_74 ) < 0 || F_23 ( V_75 ) < 0 ) ) {
perror ( L_6 ) ;
return - 1 ;
}
if ( V_76 ) {
if ( ( V_78 = F_24 () ) < 0 )
perror ( L_7 ) ;
if ( ! V_78 ) {
F_25 ( V_74 [ 0 ] ) ;
F_25 ( V_75 [ 1 ] ) ;
F_26 ( V_75 [ 0 ] , V_79 , V_80 ) ;
F_27 ( L_8 , ( char * * ) V_70 ) ;
F_25 ( V_74 [ 1 ] ) ;
if ( F_28 ( V_75 [ 0 ] , & V_77 , 1 ) == - 1 )
perror ( L_9 ) ;
F_27 ( V_70 [ 0 ] , ( char * * ) V_70 ) ;
perror ( V_70 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_29 ( & V_8 ) )
V_10 -> V_28 -> V_81 [ 0 ] = V_78 ;
F_25 ( V_74 [ 1 ] ) ;
F_25 ( V_75 [ 0 ] ) ;
if ( F_28 ( V_74 [ 0 ] , & V_77 , 1 ) == - 1 )
perror ( L_9 ) ;
F_25 ( V_74 [ 0 ] ) ;
}
if ( V_82 )
F_30 ( V_10 ) ;
F_31 (counter, &evsel_list->entries, node) {
if ( F_6 ( V_34 ) < 0 ) {
if ( V_29 == V_30 || V_29 == V_83 ||
V_29 == V_84 || V_29 == V_85 ||
V_29 == V_86 ) {
if ( V_65 )
F_32 ( L_10 ,
F_19 ( V_34 ) ) ;
V_34 -> V_87 = false ;
continue;
}
if ( V_29 == V_88 || V_29 == V_89 ) {
error ( L_11
L_12
L_13 ,
V_8 . V_90 ? L_14 : L_8 ) ;
} else {
error ( L_15
L_16 ,
V_29 , strerror ( V_29 ) ) ;
}
if ( V_78 != - 1 )
F_33 ( V_78 , V_91 ) ;
F_34 ( L_17 ) ;
return - 1 ;
}
V_34 -> V_87 = true ;
}
if ( F_35 ( V_10 ) ) {
error ( L_18 , V_29 ,
strerror ( V_29 ) ) ;
return - 1 ;
}
V_71 = F_36 () ;
if ( V_76 ) {
F_25 ( V_75 [ 1 ] ) ;
F_37 ( & V_73 ) ;
if ( F_38 ( V_73 ) )
F_39 ( F_40 ( V_73 ) , V_70 [ 0 ] ) ;
} else {
while( ! V_92 ) F_41 ( 1 ) ;
}
V_72 = F_36 () ;
F_16 ( & V_93 , V_72 - V_71 ) ;
if ( V_94 ) {
F_31 (counter, &evsel_list->entries, node) {
F_20 ( V_34 ) ;
F_42 ( V_34 , F_5 ( V_34 ) , 1 ) ;
}
} else {
F_31 (counter, &evsel_list->entries, node) {
F_17 ( V_34 ) ;
F_42 ( V_34 , F_5 ( V_34 ) ,
V_10 -> V_28 -> V_11 ) ;
}
}
return F_43 ( V_73 ) ;
}
static int F_44 ( int T_2 V_69 , const char * * V_70 )
{
int V_15 ;
if ( V_95 ) {
V_15 = system ( V_95 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_96 )
F_45 () ;
V_15 = F_22 ( T_2 , V_70 ) ;
if ( V_15 )
return V_15 ;
if ( V_97 ) {
V_15 = system ( V_97 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static void F_46 ( double V_98 , double V_99 )
{
double V_100 = F_47 ( V_98 , V_99 ) ;
if ( V_101 )
fprintf ( V_66 , L_19 , V_102 , V_100 ) ;
else if ( V_100 )
fprintf ( V_66 , L_20 , V_100 ) ;
}
static void F_48 ( struct V_1 * V_2 , double V_99 )
{
struct V_4 * V_59 ;
if ( V_103 == 1 )
return;
V_59 = V_2 -> V_3 ;
F_46 ( F_49 ( & V_59 -> V_64 [ 0 ] ) , V_99 ) ;
}
static void F_50 ( int V_68 , struct V_1 * V_2 , double V_99 )
{
double V_104 = V_99 / 1e6 ;
char V_105 [ 16 ] = { '\0' , } ;
const char * V_106 = V_101 ? L_21 : L_22 ;
if ( V_94 )
sprintf ( V_105 , L_23 ,
V_101 ? 0 : - 4 ,
F_4 ( V_2 ) -> V_81 [ V_68 ] , V_102 ) ;
fprintf ( V_66 , V_106 , V_105 , V_104 , V_102 , F_19 ( V_2 ) ) ;
if ( V_2 -> V_107 )
fprintf ( V_66 , L_24 , V_102 , V_2 -> V_107 -> V_108 ) ;
if ( V_101 )
return;
if ( F_14 ( V_2 , V_31 , V_33 ) )
fprintf ( V_66 , L_25 ,
V_99 / F_51 ( & V_93 ) ) ;
else
fprintf ( V_66 , L_26 ) ;
}
static const char * F_52 ( enum V_109 type , double V_110 )
{
static const double V_111 [ V_112 ] [ 3 ] = {
[ V_113 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_114 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_115 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_116 = V_117 ;
if ( V_110 > V_111 [ type ] [ 0 ] )
V_116 = V_118 ;
else if ( V_110 > V_111 [ type ] [ 1 ] )
V_116 = V_119 ;
else if ( V_110 > V_111 [ type ] [ 2 ] )
V_116 = V_120 ;
return V_116 ;
}
static void F_53 ( int V_68 ,
struct V_1 * V_2
V_69 , double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_39 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_113 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_29 ) ;
}
static void F_55 ( int V_68 ,
struct V_1 * V_2
V_69 , double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_39 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_114 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_30 ) ;
}
static void F_56 ( int V_68 ,
struct V_1 * V_2 V_69 ,
double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_45 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_115 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_31 ) ;
}
static void F_57 ( int V_68 ,
struct V_1 * V_2 V_69 ,
double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_50 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_115 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_32 ) ;
}
static void F_58 ( int V_68 ,
struct V_1 * V_2 V_69 ,
double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_52 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_115 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_33 ) ;
}
static void F_59 ( int V_68 ,
struct V_1 * V_2 V_69 ,
double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_56 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_115 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_34 ) ;
}
static void F_60 ( int V_68 ,
struct V_1 * V_2 V_69 ,
double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_58 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_115 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_35 ) ;
}
static void F_61 ( int V_68 ,
struct V_1 * V_2 V_69 ,
double V_99 )
{
double V_98 , V_110 = 0.0 ;
const char * V_116 ;
V_98 = F_51 ( & V_54 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 * 100.0 ;
V_116 = F_52 ( V_115 , V_110 ) ;
fprintf ( V_66 , L_27 ) ;
F_54 ( V_66 , V_116 , L_28 , V_110 ) ;
fprintf ( V_66 , L_36 ) ;
}
static void F_62 ( int V_68 , struct V_1 * V_2 , double V_99 )
{
double V_98 , V_110 = 0.0 ;
char V_105 [ 16 ] = { '\0' , } ;
const char * V_106 ;
if ( V_101 )
V_106 = L_37 ;
else if ( V_121 )
V_106 = L_38 ;
else
V_106 = L_39 ;
if ( V_94 )
sprintf ( V_105 , L_23 ,
V_101 ? 0 : - 4 ,
F_4 ( V_2 ) -> V_81 [ V_68 ] , V_102 ) ;
else
V_68 = 0 ;
fprintf ( V_66 , V_106 , V_105 , V_99 , V_102 , F_19 ( V_2 ) ) ;
if ( V_2 -> V_107 )
fprintf ( V_66 , L_24 , V_102 , V_2 -> V_107 -> V_108 ) ;
if ( V_101 )
return;
if ( F_14 ( V_2 , V_37 , V_122 ) ) {
V_98 = F_51 ( & V_39 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 / V_98 ;
fprintf ( V_66 , L_40 , V_110 ) ;
V_98 = F_51 ( & V_41 [ V_68 ] ) ;
V_98 = F_63 ( V_98 , F_51 ( & V_43 [ V_68 ] ) ) ;
if ( V_98 && V_99 ) {
V_110 = V_98 / V_99 ;
fprintf ( V_66 , L_41 , V_110 ) ;
}
} else if ( F_14 ( V_2 , V_37 , V_123 ) &&
V_45 [ V_68 ] . V_124 != 0 ) {
F_56 ( V_68 , V_2 , V_99 ) ;
} else if (
V_2 -> V_13 . type == V_125 &&
V_2 -> V_13 . V_126 == ( V_127 |
( ( V_128 ) << 8 ) |
( ( V_129 ) << 16 ) ) &&
V_50 [ V_68 ] . V_124 != 0 ) {
F_57 ( V_68 , V_2 , V_99 ) ;
} else if (
V_2 -> V_13 . type == V_125 &&
V_2 -> V_13 . V_126 == ( V_130 |
( ( V_128 ) << 8 ) |
( ( V_129 ) << 16 ) ) &&
V_52 [ V_68 ] . V_124 != 0 ) {
F_58 ( V_68 , V_2 , V_99 ) ;
} else if (
V_2 -> V_13 . type == V_125 &&
V_2 -> V_13 . V_126 == ( V_131 |
( ( V_128 ) << 8 ) |
( ( V_129 ) << 16 ) ) &&
V_56 [ V_68 ] . V_124 != 0 ) {
F_59 ( V_68 , V_2 , V_99 ) ;
} else if (
V_2 -> V_13 . type == V_125 &&
V_2 -> V_13 . V_126 == ( V_132 |
( ( V_128 ) << 8 ) |
( ( V_129 ) << 16 ) ) &&
V_58 [ V_68 ] . V_124 != 0 ) {
F_60 ( V_68 , V_2 , V_99 ) ;
} else if (
V_2 -> V_13 . type == V_125 &&
V_2 -> V_13 . V_126 == ( V_133 |
( ( V_128 ) << 8 ) |
( ( V_129 ) << 16 ) ) &&
V_54 [ V_68 ] . V_124 != 0 ) {
F_61 ( V_68 , V_2 , V_99 ) ;
} else if ( F_14 ( V_2 , V_37 , V_134 ) &&
V_47 [ V_68 ] . V_124 != 0 ) {
V_98 = F_51 ( & V_47 [ V_68 ] ) ;
if ( V_98 )
V_110 = V_99 * 100 / V_98 ;
fprintf ( V_66 , L_42 , V_110 ) ;
} else if ( F_14 ( V_2 , V_37 , V_40 ) ) {
F_53 ( V_68 , V_2 , V_99 ) ;
} else if ( F_14 ( V_2 , V_37 , V_42 ) ) {
F_55 ( V_68 , V_2 , V_99 ) ;
} else if ( F_14 ( V_2 , V_37 , V_38 ) ) {
V_98 = F_51 ( & V_36 [ V_68 ] ) ;
if ( V_98 )
V_110 = 1.0 * V_99 / V_98 ;
fprintf ( V_66 , L_43 , V_110 ) ;
} else if ( V_36 [ V_68 ] . V_124 != 0 ) {
char V_135 = 'M' ;
V_98 = F_51 ( & V_36 [ V_68 ] ) ;
if ( V_98 )
V_110 = 1000.0 * V_99 / V_98 ;
if ( V_110 < 0.001 ) {
V_110 *= 1000 ;
V_135 = 'K' ;
}
fprintf ( V_66 , L_44 , V_110 , V_135 ) ;
} else {
fprintf ( V_66 , L_26 ) ;
}
}
static void F_64 ( struct V_1 * V_34 )
{
struct V_4 * V_59 = V_34 -> V_3 ;
double V_99 = F_51 ( & V_59 -> V_64 [ 0 ] ) ;
int V_136 = V_34 -> V_60 -> V_136 ;
if ( V_136 == - 1 ) {
fprintf ( V_66 , L_45 ,
V_101 ? 0 : 18 ,
V_34 -> V_87 ? V_137 : V_138 ,
V_102 ,
V_101 ? 0 : - 24 ,
F_19 ( V_34 ) ) ;
if ( V_34 -> V_107 )
fprintf ( V_66 , L_24 , V_102 , V_34 -> V_107 -> V_108 ) ;
fputc ( '\n' , V_66 ) ;
return;
}
if ( F_13 ( V_34 ) )
F_50 ( - 1 , V_34 , V_99 ) ;
else
F_62 ( - 1 , V_34 , V_99 ) ;
F_48 ( V_34 , V_99 ) ;
if ( V_101 ) {
fputc ( '\n' , V_66 ) ;
return;
}
if ( V_136 ) {
double V_139 , V_140 ;
V_139 = F_51 ( & V_59 -> V_64 [ 1 ] ) ;
V_140 = F_51 ( & V_59 -> V_64 [ 2 ] ) ;
fprintf ( V_66 , L_46 , 100 * V_140 / V_139 ) ;
}
fprintf ( V_66 , L_5 ) ;
}
static void F_65 ( struct V_1 * V_34 )
{
T_1 V_141 , V_142 , V_143 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < F_5 ( V_34 ) ; V_68 ++ ) {
V_143 = V_34 -> V_60 -> V_68 [ V_68 ] . V_143 ;
V_141 = V_34 -> V_60 -> V_68 [ V_68 ] . V_141 ;
V_142 = V_34 -> V_60 -> V_68 [ V_68 ] . V_142 ;
if ( V_142 == 0 || V_141 == 0 ) {
fprintf ( V_66 , L_47 ,
V_101 ? 0 : - 4 ,
F_4 ( V_34 ) -> V_81 [ V_68 ] , V_102 ,
V_101 ? 0 : 18 ,
V_34 -> V_87 ? V_137 : V_138 ,
V_102 ,
V_101 ? 0 : - 24 ,
F_19 ( V_34 ) ) ;
if ( V_34 -> V_107 )
fprintf ( V_66 , L_24 ,
V_102 , V_34 -> V_107 -> V_108 ) ;
fputc ( '\n' , V_66 ) ;
continue;
}
if ( F_13 ( V_34 ) )
F_50 ( V_68 , V_34 , V_143 ) ;
else
F_62 ( V_68 , V_34 , V_143 ) ;
if ( ! V_101 ) {
F_48 ( V_34 , 1.0 ) ;
if ( V_142 != V_141 )
fprintf ( V_66 , L_48 ,
100.0 * V_142 / V_141 ) ;
}
fputc ( '\n' , V_66 ) ;
}
}
static void F_66 ( int T_2 , const char * * V_70 )
{
struct V_1 * V_34 ;
int V_63 ;
fflush ( stdout ) ;
if ( ! V_101 ) {
fprintf ( V_66 , L_5 ) ;
fprintf ( V_66 , L_49 ) ;
if ( ! F_9 ( & V_8 ) ) {
fprintf ( V_66 , L_50 , V_70 [ 0 ] ) ;
for ( V_63 = 1 ; V_63 < T_2 ; V_63 ++ )
fprintf ( V_66 , L_51 , V_70 [ V_63 ] ) ;
} else if ( V_8 . V_144 )
fprintf ( V_66 , L_52 , V_8 . V_144 ) ;
else
fprintf ( V_66 , L_53 , V_8 . V_145 ) ;
fprintf ( V_66 , L_54 ) ;
if ( V_103 > 1 )
fprintf ( V_66 , L_55 , V_103 ) ;
fprintf ( V_66 , L_56 ) ;
}
if ( V_94 ) {
F_31 (counter, &evsel_list->entries, node)
F_65 ( V_34 ) ;
} else {
F_31 (counter, &evsel_list->entries, node)
F_64 ( V_34 ) ;
}
if ( ! V_101 ) {
if ( ! V_146 )
fprintf ( V_66 , L_5 ) ;
fprintf ( V_66 , L_57 ,
F_51 ( & V_93 ) / 1e9 ) ;
if ( V_103 > 1 ) {
fprintf ( V_66 , L_58 ) ;
F_46 ( F_49 ( & V_93 ) ,
F_51 ( & V_93 ) ) ;
}
fprintf ( V_66 , L_59 ) ;
}
}
static void F_67 ( int V_147 )
{
if( V_78 == - 1 )
V_92 = 1 ;
V_148 = V_147 ;
}
static void F_68 ( void )
{
if ( V_78 != - 1 )
F_33 ( V_78 , V_91 ) ;
if ( V_148 == - 1 )
return;
signal ( V_148 , V_149 ) ;
F_33 ( F_69 () , V_148 ) ;
}
static int F_70 ( const struct V_150 * T_3 V_69 ,
const char * T_4 V_69 , int V_151 )
{
V_152 = V_151 ? 0 : 1 ;
return 0 ;
}
static int F_71 ( void )
{
struct V_12 V_153 [] = {
{ . type = V_154 , . V_126 = V_155 } ,
{ . type = V_154 , . V_126 = V_156 } ,
{ . type = V_154 , . V_126 = V_157 } ,
{ . type = V_154 , . V_126 = V_158 } ,
{ . type = V_159 , . V_126 = V_160 } ,
{ . type = V_159 , . V_126 = V_161 } ,
{ . type = V_159 , . V_126 = V_162 } ,
{ . type = V_159 , . V_126 = V_163 } ,
{ . type = V_159 , . V_126 = V_164 } ,
{ . type = V_159 , . V_126 = V_165 } ,
} ;
struct V_12 V_166 [] = {
{ . type = V_125 ,
. V_126 =
V_127 << 0 |
( V_128 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_127 << 0 |
( V_128 << 8 ) |
( V_129 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_133 << 0 |
( V_128 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_133 << 0 |
( V_128 << 8 ) |
( V_129 << 16 ) } ,
} ;
struct V_12 V_168 [] = {
{ . type = V_125 ,
. V_126 =
V_130 << 0 |
( V_128 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_130 << 0 |
( V_128 << 8 ) |
( V_129 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_131 << 0 |
( V_128 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_131 << 0 |
( V_128 << 8 ) |
( V_129 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_132 << 0 |
( V_128 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_132 << 0 |
( V_128 << 8 ) |
( V_129 << 16 ) } ,
} ;
struct V_12 V_169 [] = {
{ . type = V_125 ,
. V_126 =
V_127 << 0 |
( V_170 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_125 ,
. V_126 =
V_127 << 0 |
( V_170 << 8 ) |
( V_129 << 16 ) } ,
} ;
if ( V_146 )
return 0 ;
if ( ! V_10 -> V_171 ) {
if ( F_72 ( V_10 , V_153 ) < 0 )
return - 1 ;
}
if ( V_172 < 1 )
return 0 ;
if ( F_72 ( V_10 , V_166 ) < 0 )
return - 1 ;
if ( V_172 < 2 )
return 0 ;
if ( F_72 ( V_10 , V_168 ) < 0 )
return - 1 ;
if ( V_172 < 3 )
return 0 ;
return F_72 ( V_10 , V_169 ) ;
}
int F_73 ( int T_2 , const char * * V_70 , const char * T_5 V_69 )
{
bool V_173 = false ;
int V_174 = 0 ;
const char * V_175 = NULL ;
const struct V_150 V_176 [] = {
F_74 ( 'e' , L_60 , & V_10 , L_60 ,
L_61 ,
V_177 ) ,
F_74 ( 0 , L_62 , & V_10 , L_62 ,
L_63 , V_178 ) ,
F_75 ( 'i' , L_64 , & V_21 ,
L_65 ) ,
F_76 ( 'p' , L_66 , & V_8 . V_144 , L_66 ,
L_67 ) ,
F_76 ( 't' , L_68 , & V_8 . V_145 , L_68 ,
L_69 ) ,
F_75 ( 'a' , L_70 , & V_8 . V_90 ,
L_71 ) ,
F_75 ( 'g' , L_72 , & V_82 ,
L_73 ) ,
F_75 ( 'c' , L_74 , & V_16 , L_75 ) ,
F_77 ( 'v' , L_76 , & V_65 ,
L_77 ) ,
F_78 ( 'r' , L_78 , & V_103 ,
L_79 ) ,
F_75 ( 'n' , L_80 , & V_146 ,
L_81 ) ,
F_77 ( 'd' , L_82 , & V_172 ,
L_83 ) ,
F_75 ( 'S' , L_84 , & V_96 ,
L_85 ) ,
F_79 ( 'B' , L_86 , NULL , NULL ,
L_87 ,
F_70 ) ,
F_76 ( 'C' , L_88 , & V_8 . V_9 , L_88 ,
L_89 ) ,
F_75 ( 'A' , L_90 , & V_94 , L_91 ) ,
F_76 ( 'x' , L_92 , & V_102 , L_93 ,
L_94 ) ,
F_74 ( 'G' , L_95 , & V_10 , L_96 ,
L_97 , V_179 ) ,
F_76 ( 'o' , L_98 , & V_175 , L_99 , L_100 ) ,
F_75 ( 0 , L_101 , & V_173 , L_102 ) ,
F_78 ( 0 , L_103 , & V_174 ,
L_104 ) ,
F_76 ( 0 , L_105 , & V_95 , L_106 ,
L_107 ) ,
F_76 ( 0 , L_108 , & V_97 , L_106 ,
L_109 ) ,
F_80 ()
} ;
const char * const V_180 [] = {
L_110 ,
NULL
} ;
struct V_1 * V_181 ;
int V_73 = - V_5 , V_182 ;
const char * V_183 ;
setlocale ( V_184 , L_8 ) ;
V_10 = F_81 ( NULL , NULL ) ;
if ( V_10 == NULL )
return - V_5 ;
T_2 = F_82 ( T_2 , V_70 , V_176 , V_180 ,
V_185 ) ;
V_66 = V_186 ;
if ( V_175 && strcmp ( V_175 , L_111 ) )
V_66 = NULL ;
if ( V_175 && V_174 ) {
fprintf ( V_186 , L_112 ) ;
F_83 ( V_180 , V_176 ) ;
}
if ( V_174 < 0 ) {
fprintf ( V_186 , L_113 ) ;
F_83 ( V_180 , V_176 ) ;
}
if ( ! V_66 ) {
struct V_187 V_188 ;
V_183 = V_173 ? L_114 : L_115 ;
V_66 = fopen ( V_175 , V_183 ) ;
if ( ! V_66 ) {
perror ( L_116 ) ;
return - 1 ;
}
F_84 ( V_189 , & V_188 ) ;
fprintf ( V_66 , L_117 , ctime ( & V_188 . V_190 ) ) ;
} else if ( V_174 > 0 ) {
V_183 = V_173 ? L_114 : L_115 ;
V_66 = fdopen ( V_174 , V_183 ) ;
if ( ! V_66 ) {
perror ( L_118 ) ;
return - V_29 ;
}
}
if ( V_102 ) {
V_101 = true ;
if ( ! strcmp ( V_102 , L_119 ) )
V_102 = L_120 ;
} else
V_102 = V_191 ;
if ( V_101 ) {
if ( V_152 == 1 ) {
fprintf ( V_186 , L_121 ) ;
F_83 ( V_180 , V_176 ) ;
} else
V_121 = false ;
} else if ( V_152 == 0 )
V_121 = false ;
if ( ! T_2 && ! F_9 ( & V_8 ) )
F_83 ( V_180 , V_176 ) ;
if ( V_103 <= 0 )
F_83 ( V_180 , V_176 ) ;
if ( ( V_94 || V_192 ) && ! F_7 ( & V_8 ) ) {
fprintf ( V_186 , L_122
L_123 ) ;
F_83 ( V_180 , V_176 ) ;
}
if ( F_71 () )
goto V_193;
F_85 ( & V_8 ) ;
if ( F_86 ( V_10 , & V_8 ) < 0 ) {
if ( F_9 ( & V_8 ) )
F_34 ( L_124 ) ;
if ( F_7 ( & V_8 ) )
perror ( L_125 ) ;
F_83 ( V_180 , V_176 ) ;
return - 1 ;
}
F_31 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_181 ) < 0 ||
F_87 ( V_181 , F_5 ( V_181 ) ) < 0 )
goto V_194;
}
atexit ( F_68 ) ;
signal ( V_195 , F_67 ) ;
signal ( V_196 , F_67 ) ;
signal ( V_197 , F_67 ) ;
V_73 = 0 ;
for ( V_182 = 0 ; V_182 < V_103 ; V_182 ++ ) {
if ( V_103 != 1 && V_65 )
fprintf ( V_66 , L_126 ,
V_182 + 1 ) ;
V_73 = F_44 ( T_2 , V_70 ) ;
}
if ( V_73 != - 1 )
F_66 ( T_2 , V_70 ) ;
V_194:
F_31 (pos, &evsel_list->entries, node)
F_3 ( V_181 ) ;
F_88 ( V_10 ) ;
V_193:
F_89 ( V_10 ) ;
return V_73 ;
}
