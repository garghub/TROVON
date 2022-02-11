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
static int F_6 ( struct V_1 * V_2 ,
struct V_1 * V_12 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
bool V_15 = false ;
int V_16 ;
if ( V_17 )
V_14 -> V_18 = V_19 |
V_20 ;
V_14 -> V_21 = ! V_22 ;
V_23:
if ( V_15 )
V_2 -> V_14 . V_24 = V_2 -> V_14 . V_25 = 0 ;
if ( F_7 ( & V_8 ) ) {
V_16 = F_8 ( V_2 , F_4 ( V_2 ) ) ;
if ( V_16 )
goto V_26;
return 0 ;
}
if ( ! F_9 ( & V_8 ) && ( ! V_27 || V_2 == V_12 ) ) {
V_14 -> V_28 = 1 ;
V_14 -> V_29 = 1 ;
}
V_16 = F_10 ( V_2 , V_10 -> V_30 ) ;
if ( ! V_16 )
return 0 ;
V_26:
if ( V_16 && V_31 == V_32 ) {
if ( ! V_15 &&
( V_2 -> V_14 . V_24 || V_2 -> V_14 . V_25 ) ) {
F_11 ( L_1
L_2 ) ;
V_15 = true ;
goto V_23;
}
}
return V_16 ;
}
static inline int F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , V_33 , V_34 ) ||
F_13 ( V_2 , V_33 , V_35 ) )
return 1 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_36 , T_1 * V_37 )
{
if ( F_13 ( V_36 , V_33 , V_35 ) )
F_15 ( & V_38 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_39 , V_40 ) )
F_15 ( & V_41 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_39 , V_42 ) )
F_15 ( & V_43 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_39 , V_44 ) )
F_15 ( & V_45 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_39 , V_46 ) )
F_15 ( & V_47 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_39 , V_48 ) )
F_15 ( & V_49 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_50 , V_51 ) )
F_15 ( & V_52 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_50 , V_53 ) )
F_15 ( & V_54 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_50 , V_55 ) )
F_15 ( & V_56 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_50 , V_57 ) )
F_15 ( & V_58 [ 0 ] , V_37 [ 0 ] ) ;
else if ( F_13 ( V_36 , V_50 , V_59 ) )
F_15 ( & V_60 [ 0 ] , V_37 [ 0 ] ) ;
}
static int F_16 ( struct V_1 * V_36 )
{
struct V_4 * V_61 = V_36 -> V_3 ;
T_1 * V_37 = V_36 -> V_62 -> V_63 . V_64 ;
int V_65 ;
if ( F_17 ( V_36 , F_5 ( V_36 ) ,
V_10 -> V_30 -> V_11 , V_17 ) < 0 )
return - 1 ;
for ( V_65 = 0 ; V_65 < 3 ; V_65 ++ )
F_15 ( & V_61 -> V_66 [ V_65 ] , V_37 [ V_65 ] ) ;
if ( V_67 ) {
fprintf ( V_68 , L_3 V_69 L_4 V_69 L_4 V_69 L_5 ,
F_18 ( V_36 ) , V_37 [ 0 ] , V_37 [ 1 ] , V_37 [ 2 ] ) ;
}
F_14 ( V_36 , V_37 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_36 )
{
T_1 * V_37 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_5 ( V_36 ) ; V_70 ++ ) {
if ( F_20 ( V_36 , V_70 , 0 , V_17 ) < 0 )
return - 1 ;
V_37 = V_36 -> V_62 -> V_70 [ V_70 ] . V_64 ;
F_14 ( V_36 , V_37 ) ;
}
return 0 ;
}
static int F_21 ( int T_2 V_71 , const char * * V_72 )
{
unsigned long long V_73 , V_74 ;
struct V_1 * V_36 , * V_12 ;
int V_75 = 0 ;
int V_76 [ 2 ] , V_77 [ 2 ] ;
const bool V_78 = ( T_2 > 0 ) ;
char V_79 ;
if ( V_78 && ( F_22 ( V_76 ) < 0 || F_22 ( V_77 ) < 0 ) ) {
perror ( L_6 ) ;
return - 1 ;
}
if ( V_78 ) {
if ( ( V_80 = F_23 () ) < 0 )
perror ( L_7 ) ;
if ( ! V_80 ) {
F_24 ( V_76 [ 0 ] ) ;
F_24 ( V_77 [ 1 ] ) ;
F_25 ( V_77 [ 0 ] , V_81 , V_82 ) ;
F_26 ( L_8 , ( char * * ) V_72 ) ;
F_24 ( V_76 [ 1 ] ) ;
if ( F_27 ( V_77 [ 0 ] , & V_79 , 1 ) == - 1 )
perror ( L_9 ) ;
F_26 ( V_72 [ 0 ] , ( char * * ) V_72 ) ;
perror ( V_72 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_28 ( & V_8 ) )
V_10 -> V_30 -> V_83 [ 0 ] = V_80 ;
F_24 ( V_76 [ 1 ] ) ;
F_24 ( V_77 [ 0 ] ) ;
if ( F_27 ( V_76 [ 0 ] , & V_79 , 1 ) == - 1 )
perror ( L_9 ) ;
F_24 ( V_76 [ 0 ] ) ;
}
if ( V_27 )
F_29 ( V_10 ) ;
V_12 = F_30 ( V_10 ) ;
F_31 (counter, &evsel_list->entries, node) {
if ( F_6 ( V_36 , V_12 ) < 0 ) {
if ( V_31 == V_32 || V_31 == V_84 ||
V_31 == V_85 || V_31 == V_86 ||
V_31 == V_87 ) {
if ( V_67 )
F_32 ( L_10 ,
F_18 ( V_36 ) ) ;
V_36 -> V_88 = false ;
continue;
}
if ( V_31 == V_89 || V_31 == V_90 ) {
error ( L_11
L_12
L_13 ,
V_8 . V_91 ? L_14 : L_8 ) ;
} else {
error ( L_15
L_16 ,
V_31 , strerror ( V_31 ) ) ;
}
if ( V_80 != - 1 )
F_33 ( V_80 , V_92 ) ;
F_34 ( L_17 ) ;
return - 1 ;
}
V_36 -> V_88 = true ;
}
if ( F_35 ( V_10 ) ) {
error ( L_18 , V_31 ,
strerror ( V_31 ) ) ;
return - 1 ;
}
V_73 = F_36 () ;
if ( V_78 ) {
F_24 ( V_77 [ 1 ] ) ;
F_37 ( & V_75 ) ;
if ( F_38 ( V_75 ) )
F_39 ( F_40 ( V_75 ) , V_72 [ 0 ] ) ;
} else {
while( ! V_93 ) F_41 ( 1 ) ;
}
V_74 = F_36 () ;
F_15 ( & V_94 , V_74 - V_73 ) ;
if ( V_95 ) {
F_31 (counter, &evsel_list->entries, node) {
F_19 ( V_36 ) ;
F_42 ( V_36 , F_5 ( V_36 ) , 1 ) ;
}
} else {
F_31 (counter, &evsel_list->entries, node) {
F_16 ( V_36 ) ;
F_42 ( V_36 , F_5 ( V_36 ) ,
V_10 -> V_30 -> V_11 ) ;
}
}
return F_43 ( V_75 ) ;
}
static void F_44 ( double V_96 , double V_97 )
{
double V_98 = F_45 ( V_96 , V_97 ) ;
if ( V_99 )
fprintf ( V_68 , L_19 , V_100 , V_98 ) ;
else if ( V_98 )
fprintf ( V_68 , L_20 , V_98 ) ;
}
static void F_46 ( struct V_1 * V_2 , double V_97 )
{
struct V_4 * V_61 ;
if ( V_101 == 1 )
return;
V_61 = V_2 -> V_3 ;
F_44 ( F_47 ( & V_61 -> V_66 [ 0 ] ) , V_97 ) ;
}
static void F_48 ( int V_70 , struct V_1 * V_2 , double V_97 )
{
double V_102 = V_97 / 1e6 ;
char V_103 [ 16 ] = { '\0' , } ;
const char * V_104 = V_99 ? L_21 : L_22 ;
if ( V_95 )
sprintf ( V_103 , L_23 ,
V_99 ? 0 : - 4 ,
F_4 ( V_2 ) -> V_83 [ V_70 ] , V_100 ) ;
fprintf ( V_68 , V_104 , V_103 , V_102 , V_100 , F_18 ( V_2 ) ) ;
if ( V_2 -> V_105 )
fprintf ( V_68 , L_24 , V_100 , V_2 -> V_105 -> V_106 ) ;
if ( V_99 )
return;
if ( F_13 ( V_2 , V_33 , V_35 ) )
fprintf ( V_68 , L_25 ,
V_97 / F_49 ( & V_94 ) ) ;
else
fprintf ( V_68 , L_26 ) ;
}
static const char * F_50 ( enum V_107 type , double V_108 )
{
static const double V_109 [ V_110 ] [ 3 ] = {
[ V_111 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_112 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_113 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_114 = V_115 ;
if ( V_108 > V_109 [ type ] [ 0 ] )
V_114 = V_116 ;
else if ( V_108 > V_109 [ type ] [ 1 ] )
V_114 = V_117 ;
else if ( V_108 > V_109 [ type ] [ 2 ] )
V_114 = V_118 ;
return V_114 ;
}
static void F_51 ( int V_70 ,
struct V_1 * V_2
V_71 , double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_41 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_111 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_29 ) ;
}
static void F_53 ( int V_70 ,
struct V_1 * V_2
V_71 , double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_41 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_112 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_30 ) ;
}
static void F_54 ( int V_70 ,
struct V_1 * V_2 V_71 ,
double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_47 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_113 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_31 ) ;
}
static void F_55 ( int V_70 ,
struct V_1 * V_2 V_71 ,
double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_52 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_113 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_32 ) ;
}
static void F_56 ( int V_70 ,
struct V_1 * V_2 V_71 ,
double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_54 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_113 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_33 ) ;
}
static void F_57 ( int V_70 ,
struct V_1 * V_2 V_71 ,
double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_58 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_113 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_34 ) ;
}
static void F_58 ( int V_70 ,
struct V_1 * V_2 V_71 ,
double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_60 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_113 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_35 ) ;
}
static void F_59 ( int V_70 ,
struct V_1 * V_2 V_71 ,
double V_97 )
{
double V_96 , V_108 = 0.0 ;
const char * V_114 ;
V_96 = F_49 ( & V_56 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 * 100.0 ;
V_114 = F_50 ( V_113 , V_108 ) ;
fprintf ( V_68 , L_27 ) ;
F_52 ( V_68 , V_114 , L_28 , V_108 ) ;
fprintf ( V_68 , L_36 ) ;
}
static void F_60 ( int V_70 , struct V_1 * V_2 , double V_97 )
{
double V_96 , V_108 = 0.0 ;
char V_103 [ 16 ] = { '\0' , } ;
const char * V_104 ;
if ( V_99 )
V_104 = L_37 ;
else if ( V_119 )
V_104 = L_38 ;
else
V_104 = L_39 ;
if ( V_95 )
sprintf ( V_103 , L_23 ,
V_99 ? 0 : - 4 ,
F_4 ( V_2 ) -> V_83 [ V_70 ] , V_100 ) ;
else
V_70 = 0 ;
fprintf ( V_68 , V_104 , V_103 , V_97 , V_100 , F_18 ( V_2 ) ) ;
if ( V_2 -> V_105 )
fprintf ( V_68 , L_24 , V_100 , V_2 -> V_105 -> V_106 ) ;
if ( V_99 )
return;
if ( F_13 ( V_2 , V_39 , V_120 ) ) {
V_96 = F_49 ( & V_41 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 / V_96 ;
fprintf ( V_68 , L_40 , V_108 ) ;
V_96 = F_49 ( & V_43 [ V_70 ] ) ;
V_96 = F_61 ( V_96 , F_49 ( & V_45 [ V_70 ] ) ) ;
if ( V_96 && V_97 ) {
V_108 = V_96 / V_97 ;
fprintf ( V_68 , L_41 , V_108 ) ;
}
} else if ( F_13 ( V_2 , V_39 , V_121 ) &&
V_47 [ V_70 ] . V_122 != 0 ) {
F_54 ( V_70 , V_2 , V_97 ) ;
} else if (
V_2 -> V_14 . type == V_123 &&
V_2 -> V_14 . V_124 == ( V_125 |
( ( V_126 ) << 8 ) |
( ( V_127 ) << 16 ) ) &&
V_52 [ V_70 ] . V_122 != 0 ) {
F_55 ( V_70 , V_2 , V_97 ) ;
} else if (
V_2 -> V_14 . type == V_123 &&
V_2 -> V_14 . V_124 == ( V_128 |
( ( V_126 ) << 8 ) |
( ( V_127 ) << 16 ) ) &&
V_54 [ V_70 ] . V_122 != 0 ) {
F_56 ( V_70 , V_2 , V_97 ) ;
} else if (
V_2 -> V_14 . type == V_123 &&
V_2 -> V_14 . V_124 == ( V_129 |
( ( V_126 ) << 8 ) |
( ( V_127 ) << 16 ) ) &&
V_58 [ V_70 ] . V_122 != 0 ) {
F_57 ( V_70 , V_2 , V_97 ) ;
} else if (
V_2 -> V_14 . type == V_123 &&
V_2 -> V_14 . V_124 == ( V_130 |
( ( V_126 ) << 8 ) |
( ( V_127 ) << 16 ) ) &&
V_60 [ V_70 ] . V_122 != 0 ) {
F_58 ( V_70 , V_2 , V_97 ) ;
} else if (
V_2 -> V_14 . type == V_123 &&
V_2 -> V_14 . V_124 == ( V_131 |
( ( V_126 ) << 8 ) |
( ( V_127 ) << 16 ) ) &&
V_56 [ V_70 ] . V_122 != 0 ) {
F_59 ( V_70 , V_2 , V_97 ) ;
} else if ( F_13 ( V_2 , V_39 , V_132 ) &&
V_49 [ V_70 ] . V_122 != 0 ) {
V_96 = F_49 ( & V_49 [ V_70 ] ) ;
if ( V_96 )
V_108 = V_97 * 100 / V_96 ;
fprintf ( V_68 , L_42 , V_108 ) ;
} else if ( F_13 ( V_2 , V_39 , V_42 ) ) {
F_51 ( V_70 , V_2 , V_97 ) ;
} else if ( F_13 ( V_2 , V_39 , V_44 ) ) {
F_53 ( V_70 , V_2 , V_97 ) ;
} else if ( F_13 ( V_2 , V_39 , V_40 ) ) {
V_96 = F_49 ( & V_38 [ V_70 ] ) ;
if ( V_96 )
V_108 = 1.0 * V_97 / V_96 ;
fprintf ( V_68 , L_43 , V_108 ) ;
} else if ( V_38 [ V_70 ] . V_122 != 0 ) {
char V_133 = 'M' ;
V_96 = F_49 ( & V_38 [ V_70 ] ) ;
if ( V_96 )
V_108 = 1000.0 * V_97 / V_96 ;
if ( V_108 < 0.001 ) {
V_108 *= 1000 ;
V_133 = 'K' ;
}
fprintf ( V_68 , L_44 , V_108 , V_133 ) ;
} else {
fprintf ( V_68 , L_26 ) ;
}
}
static void F_62 ( struct V_1 * V_36 )
{
struct V_4 * V_61 = V_36 -> V_3 ;
double V_97 = F_49 ( & V_61 -> V_66 [ 0 ] ) ;
int V_134 = V_36 -> V_62 -> V_134 ;
if ( V_134 == - 1 ) {
fprintf ( V_68 , L_45 ,
V_99 ? 0 : 18 ,
V_36 -> V_88 ? V_135 : V_136 ,
V_100 ,
V_99 ? 0 : - 24 ,
F_18 ( V_36 ) ) ;
if ( V_36 -> V_105 )
fprintf ( V_68 , L_24 , V_100 , V_36 -> V_105 -> V_106 ) ;
fputc ( '\n' , V_68 ) ;
return;
}
if ( F_12 ( V_36 ) )
F_48 ( - 1 , V_36 , V_97 ) ;
else
F_60 ( - 1 , V_36 , V_97 ) ;
F_46 ( V_36 , V_97 ) ;
if ( V_99 ) {
fputc ( '\n' , V_68 ) ;
return;
}
if ( V_134 ) {
double V_137 , V_138 ;
V_137 = F_49 ( & V_61 -> V_66 [ 1 ] ) ;
V_138 = F_49 ( & V_61 -> V_66 [ 2 ] ) ;
fprintf ( V_68 , L_46 , 100 * V_138 / V_137 ) ;
}
fprintf ( V_68 , L_5 ) ;
}
static void F_63 ( struct V_1 * V_36 )
{
T_1 V_139 , V_140 , V_141 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_5 ( V_36 ) ; V_70 ++ ) {
V_141 = V_36 -> V_62 -> V_70 [ V_70 ] . V_141 ;
V_139 = V_36 -> V_62 -> V_70 [ V_70 ] . V_139 ;
V_140 = V_36 -> V_62 -> V_70 [ V_70 ] . V_140 ;
if ( V_140 == 0 || V_139 == 0 ) {
fprintf ( V_68 , L_47 ,
V_99 ? 0 : - 4 ,
F_4 ( V_36 ) -> V_83 [ V_70 ] , V_100 ,
V_99 ? 0 : 18 ,
V_36 -> V_88 ? V_135 : V_136 ,
V_100 ,
V_99 ? 0 : - 24 ,
F_18 ( V_36 ) ) ;
if ( V_36 -> V_105 )
fprintf ( V_68 , L_24 ,
V_100 , V_36 -> V_105 -> V_106 ) ;
fputc ( '\n' , V_68 ) ;
continue;
}
if ( F_12 ( V_36 ) )
F_48 ( V_70 , V_36 , V_141 ) ;
else
F_60 ( V_70 , V_36 , V_141 ) ;
if ( ! V_99 ) {
F_46 ( V_36 , 1.0 ) ;
if ( V_140 != V_139 )
fprintf ( V_68 , L_48 ,
100.0 * V_140 / V_139 ) ;
}
fputc ( '\n' , V_68 ) ;
}
}
static void F_64 ( int T_2 , const char * * V_72 )
{
struct V_1 * V_36 ;
int V_65 ;
fflush ( stdout ) ;
if ( ! V_99 ) {
fprintf ( V_68 , L_5 ) ;
fprintf ( V_68 , L_49 ) ;
if ( ! F_9 ( & V_8 ) ) {
fprintf ( V_68 , L_50 , V_72 [ 0 ] ) ;
for ( V_65 = 1 ; V_65 < T_2 ; V_65 ++ )
fprintf ( V_68 , L_51 , V_72 [ V_65 ] ) ;
} else if ( V_8 . V_142 )
fprintf ( V_68 , L_52 , V_8 . V_142 ) ;
else
fprintf ( V_68 , L_53 , V_8 . V_143 ) ;
fprintf ( V_68 , L_54 ) ;
if ( V_101 > 1 )
fprintf ( V_68 , L_55 , V_101 ) ;
fprintf ( V_68 , L_56 ) ;
}
if ( V_95 ) {
F_31 (counter, &evsel_list->entries, node)
F_63 ( V_36 ) ;
} else {
F_31 (counter, &evsel_list->entries, node)
F_62 ( V_36 ) ;
}
if ( ! V_99 ) {
if ( ! V_144 )
fprintf ( V_68 , L_5 ) ;
fprintf ( V_68 , L_57 ,
F_49 ( & V_94 ) / 1e9 ) ;
if ( V_101 > 1 ) {
fprintf ( V_68 , L_58 ) ;
F_44 ( F_47 ( & V_94 ) ,
F_49 ( & V_94 ) ) ;
}
fprintf ( V_68 , L_59 ) ;
}
}
static void F_65 ( int V_145 )
{
if( V_80 == - 1 )
V_93 = 1 ;
V_146 = V_145 ;
}
static void F_66 ( void )
{
if ( V_80 != - 1 )
F_33 ( V_80 , V_92 ) ;
if ( V_146 == - 1 )
return;
signal ( V_146 , V_147 ) ;
F_33 ( F_67 () , V_146 ) ;
}
static int F_68 ( const struct V_148 * T_3 V_71 ,
const char * T_4 V_71 , int V_149 )
{
V_150 = V_149 ? 0 : 1 ;
return 0 ;
}
static int F_69 ( void )
{
struct V_13 V_151 [] = {
{ . type = V_152 , . V_124 = V_153 } ,
{ . type = V_152 , . V_124 = V_154 } ,
{ . type = V_152 , . V_124 = V_155 } ,
{ . type = V_152 , . V_124 = V_156 } ,
{ . type = V_157 , . V_124 = V_158 } ,
{ . type = V_157 , . V_124 = V_159 } ,
{ . type = V_157 , . V_124 = V_160 } ,
{ . type = V_157 , . V_124 = V_161 } ,
{ . type = V_157 , . V_124 = V_162 } ,
{ . type = V_157 , . V_124 = V_163 } ,
} ;
struct V_13 V_164 [] = {
{ . type = V_123 ,
. V_124 =
V_125 << 0 |
( V_126 << 8 ) |
( V_165 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_125 << 0 |
( V_126 << 8 ) |
( V_127 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_131 << 0 |
( V_126 << 8 ) |
( V_165 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_131 << 0 |
( V_126 << 8 ) |
( V_127 << 16 ) } ,
} ;
struct V_13 V_166 [] = {
{ . type = V_123 ,
. V_124 =
V_128 << 0 |
( V_126 << 8 ) |
( V_165 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_128 << 0 |
( V_126 << 8 ) |
( V_127 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_129 << 0 |
( V_126 << 8 ) |
( V_165 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_129 << 0 |
( V_126 << 8 ) |
( V_127 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_130 << 0 |
( V_126 << 8 ) |
( V_165 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_130 << 0 |
( V_126 << 8 ) |
( V_127 << 16 ) } ,
} ;
struct V_13 V_167 [] = {
{ . type = V_123 ,
. V_124 =
V_125 << 0 |
( V_168 << 8 ) |
( V_165 << 16 ) } ,
{ . type = V_123 ,
. V_124 =
V_125 << 0 |
( V_168 << 8 ) |
( V_127 << 16 ) } ,
} ;
if ( V_144 )
return 0 ;
if ( ! V_10 -> V_169 ) {
if ( F_70 ( V_10 , V_151 ) < 0 )
return - 1 ;
}
if ( V_170 < 1 )
return 0 ;
if ( F_70 ( V_10 , V_164 ) < 0 )
return - 1 ;
if ( V_170 < 2 )
return 0 ;
if ( F_70 ( V_10 , V_166 ) < 0 )
return - 1 ;
if ( V_170 < 3 )
return 0 ;
return F_70 ( V_10 , V_167 ) ;
}
int F_71 ( int T_2 , const char * * V_72 , const char * T_5 V_71 )
{
bool V_171 = false ,
V_172 = false ;
int V_173 = 0 ;
const char * V_174 = NULL ;
const struct V_148 V_175 [] = {
F_72 ( 'e' , L_60 , & V_10 , L_60 ,
L_61 ,
V_176 ) ,
F_72 ( 0 , L_62 , & V_10 , L_62 ,
L_63 , V_177 ) ,
F_73 ( 'i' , L_64 , & V_22 ,
L_65 ) ,
F_74 ( 'p' , L_66 , & V_8 . V_142 , L_66 ,
L_67 ) ,
F_74 ( 't' , L_68 , & V_8 . V_143 , L_68 ,
L_69 ) ,
F_73 ( 'a' , L_70 , & V_8 . V_91 ,
L_71 ) ,
F_73 ( 'g' , L_72 , & V_27 ,
L_73 ) ,
F_73 ( 'c' , L_74 , & V_17 , L_75 ) ,
F_75 ( 'v' , L_76 , & V_67 ,
L_77 ) ,
F_76 ( 'r' , L_78 , & V_101 ,
L_79 ) ,
F_73 ( 'n' , L_80 , & V_144 ,
L_81 ) ,
F_75 ( 'd' , L_82 , & V_170 ,
L_83 ) ,
F_73 ( 'S' , L_84 , & V_172 ,
L_85 ) ,
F_77 ( 'B' , L_86 , NULL , NULL ,
L_87 ,
F_68 ) ,
F_74 ( 'C' , L_88 , & V_8 . V_9 , L_88 ,
L_89 ) ,
F_73 ( 'A' , L_90 , & V_95 , L_91 ) ,
F_74 ( 'x' , L_92 , & V_100 , L_93 ,
L_94 ) ,
F_72 ( 'G' , L_95 , & V_10 , L_96 ,
L_97 , V_178 ) ,
F_74 ( 'o' , L_98 , & V_174 , L_99 , L_100 ) ,
F_73 ( 0 , L_101 , & V_171 , L_102 ) ,
F_76 ( 0 , L_103 , & V_173 ,
L_104 ) ,
F_78 ()
} ;
const char * const V_179 [] = {
L_105 ,
NULL
} ;
struct V_1 * V_180 ;
int V_75 = - V_5 , V_181 ;
const char * V_182 ;
setlocale ( V_183 , L_8 ) ;
V_10 = F_79 ( NULL , NULL ) ;
if ( V_10 == NULL )
return - V_5 ;
T_2 = F_80 ( T_2 , V_72 , V_175 , V_179 ,
V_184 ) ;
V_68 = V_185 ;
if ( V_174 && strcmp ( V_174 , L_106 ) )
V_68 = NULL ;
if ( V_174 && V_173 ) {
fprintf ( V_185 , L_107 ) ;
F_81 ( V_179 , V_175 ) ;
}
if ( V_173 < 0 ) {
fprintf ( V_185 , L_108 ) ;
F_81 ( V_179 , V_175 ) ;
}
if ( ! V_68 ) {
struct V_186 V_187 ;
V_182 = V_171 ? L_109 : L_110 ;
V_68 = fopen ( V_174 , V_182 ) ;
if ( ! V_68 ) {
perror ( L_111 ) ;
return - 1 ;
}
F_82 ( V_188 , & V_187 ) ;
fprintf ( V_68 , L_112 , ctime ( & V_187 . V_189 ) ) ;
} else if ( V_173 > 0 ) {
V_182 = V_171 ? L_109 : L_110 ;
V_68 = fdopen ( V_173 , V_182 ) ;
if ( ! V_68 ) {
perror ( L_113 ) ;
return - V_31 ;
}
}
if ( V_100 ) {
V_99 = true ;
if ( ! strcmp ( V_100 , L_114 ) )
V_100 = L_115 ;
} else
V_100 = V_190 ;
if ( V_99 ) {
if ( V_150 == 1 ) {
fprintf ( V_185 , L_116 ) ;
F_81 ( V_179 , V_175 ) ;
} else
V_119 = false ;
} else if ( V_150 == 0 )
V_119 = false ;
if ( ! T_2 && ! F_9 ( & V_8 ) )
F_81 ( V_179 , V_175 ) ;
if ( V_101 <= 0 )
F_81 ( V_179 , V_175 ) ;
if ( ( V_95 || V_191 ) && ! F_7 ( & V_8 ) ) {
fprintf ( V_185 , L_117
L_118 ) ;
F_81 ( V_179 , V_175 ) ;
}
if ( F_69 () )
goto V_192;
F_83 ( & V_8 ) ;
if ( F_84 ( V_10 , & V_8 ) < 0 ) {
if ( F_9 ( & V_8 ) )
F_34 ( L_119 ) ;
if ( F_7 ( & V_8 ) )
perror ( L_120 ) ;
F_81 ( V_179 , V_175 ) ;
return - 1 ;
}
F_31 (pos, &evsel_list->entries, node) {
if ( F_1 ( V_180 ) < 0 ||
F_85 ( V_180 , F_5 ( V_180 ) ) < 0 )
goto V_193;
}
atexit ( F_66 ) ;
signal ( V_194 , F_65 ) ;
signal ( V_195 , F_65 ) ;
signal ( V_196 , F_65 ) ;
V_75 = 0 ;
for ( V_181 = 0 ; V_181 < V_101 ; V_181 ++ ) {
if ( V_101 != 1 && V_67 )
fprintf ( V_68 , L_121 ,
V_181 + 1 ) ;
if ( V_172 )
F_86 () ;
V_75 = F_21 ( T_2 , V_72 ) ;
}
if ( V_75 != - 1 )
F_64 ( T_2 , V_72 ) ;
V_193:
F_31 (pos, &evsel_list->entries, node)
F_3 ( V_180 ) ;
F_87 ( V_10 ) ;
V_192:
F_88 ( V_10 ) ;
return V_75 ;
}
