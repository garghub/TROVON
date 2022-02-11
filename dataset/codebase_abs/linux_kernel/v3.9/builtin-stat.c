static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_3 -> V_5 - V_4 -> V_5 ;
if ( V_3 -> V_6 < V_4 -> V_6 ) {
V_2 -> V_6 = V_3 -> V_6 + 1000000000L - V_4 -> V_6 ;
V_2 -> V_5 -- ;
} else {
V_2 -> V_6 = V_3 -> V_6 - V_4 -> V_6 ;
}
}
static inline struct V_7 * F_2 ( struct V_8 * V_9 )
{
return ( V_9 -> V_10 && ! V_11 . V_12 ) ? V_9 -> V_10 : V_13 -> V_10 ;
}
static inline int F_3 ( struct V_8 * V_9 )
{
return F_2 ( V_9 ) -> V_14 ;
}
static int F_4 ( struct V_8 * V_9 )
{
V_9 -> V_15 = F_5 ( sizeof( struct V_16 ) ) ;
return V_9 -> V_15 == NULL ? - V_17 : 0 ;
}
static void F_6 ( struct V_8 * V_9 )
{
free ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
}
static int F_7 ( struct V_8 * V_9 )
{
void * V_18 ;
T_1 V_19 ;
V_19 = sizeof( * V_9 -> V_20 ) +
( F_3 ( V_9 ) * sizeof( struct V_21 ) ) ;
V_18 = F_5 ( V_19 ) ;
if ( ! V_18 )
return - V_17 ;
V_9 -> V_22 = V_18 ;
return 0 ;
}
static void F_8 ( struct V_8 * V_9 )
{
free ( V_9 -> V_22 ) ;
V_9 -> V_22 = NULL ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_23 * V_24 = & V_9 -> V_24 ;
if ( V_25 )
V_24 -> V_26 = V_27 |
V_28 ;
V_24 -> V_29 = ! V_30 ;
if ( F_10 ( & V_11 ) )
return F_11 ( V_9 , F_2 ( V_9 ) ) ;
if ( ! F_12 ( & V_11 ) &&
F_13 ( V_9 ) ) {
V_24 -> V_31 = 1 ;
V_24 -> V_32 = 1 ;
}
return F_14 ( V_9 , V_13 -> V_33 ) ;
}
static inline int F_15 ( struct V_8 * V_9 )
{
if ( F_16 ( V_9 , V_34 , V_35 ) ||
F_16 ( V_9 , V_34 , V_36 ) )
return 1 ;
return 0 ;
}
static void F_17 ( struct V_8 * V_37 , T_2 * V_38 )
{
if ( F_16 ( V_37 , V_34 , V_36 ) )
F_18 ( & V_39 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_40 , V_41 ) )
F_18 ( & V_42 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_40 , V_43 ) )
F_18 ( & V_44 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_40 , V_45 ) )
F_18 ( & V_46 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_40 , V_47 ) )
F_18 ( & V_48 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_40 , V_49 ) )
F_18 ( & V_50 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_51 , V_52 ) )
F_18 ( & V_53 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_51 , V_54 ) )
F_18 ( & V_55 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_51 , V_56 ) )
F_18 ( & V_57 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_51 , V_58 ) )
F_18 ( & V_59 [ 0 ] , V_38 [ 0 ] ) ;
else if ( F_16 ( V_37 , V_51 , V_60 ) )
F_18 ( & V_61 [ 0 ] , V_38 [ 0 ] ) ;
}
static int F_19 ( struct V_8 * V_37 )
{
struct V_16 * V_62 = V_37 -> V_15 ;
T_2 * V_38 = V_37 -> V_20 -> V_63 . V_64 ;
int V_65 ;
if ( F_20 ( V_37 , F_3 ( V_37 ) ,
V_13 -> V_33 -> V_14 , V_25 ) < 0 )
return - 1 ;
for ( V_65 = 0 ; V_65 < 3 ; V_65 ++ )
F_18 ( & V_62 -> V_66 [ V_65 ] , V_38 [ V_65 ] ) ;
if ( V_67 ) {
fprintf ( V_68 , L_1 V_69 L_2 V_69 L_2 V_69 L_3 ,
F_21 ( V_37 ) , V_38 [ 0 ] , V_38 [ 1 ] , V_38 [ 2 ] ) ;
}
F_17 ( V_37 , V_38 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_37 )
{
T_2 * V_38 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_3 ( V_37 ) ; V_70 ++ ) {
if ( F_23 ( V_37 , V_70 , 0 , V_25 ) < 0 )
return - 1 ;
V_38 = V_37 -> V_20 -> V_70 [ V_70 ] . V_64 ;
F_17 ( V_37 , V_38 ) ;
}
return 0 ;
}
static void F_24 ( void )
{
static int V_71 ;
struct V_8 * V_37 ;
struct V_16 * V_62 ;
struct V_1 V_72 , V_73 ;
char V_74 [ 64 ] ;
if ( V_75 ) {
F_25 (counter, &evsel_list->entries, node) {
V_62 = V_37 -> V_15 ;
memset ( V_62 -> V_66 , 0 , sizeof( V_62 -> V_66 ) ) ;
F_22 ( V_37 ) ;
}
} else {
F_25 (counter, &evsel_list->entries, node) {
V_62 = V_37 -> V_15 ;
memset ( V_62 -> V_66 , 0 , sizeof( V_62 -> V_66 ) ) ;
F_19 ( V_37 ) ;
}
}
F_26 ( V_76 , & V_72 ) ;
F_1 ( & V_73 , & V_72 , & V_77 ) ;
sprintf ( V_74 , L_4 , V_73 . V_5 , V_73 . V_6 , V_78 ) ;
if ( V_71 == 0 && ! V_79 ) {
if ( V_80 )
fprintf ( V_68 , L_5 ) ;
else if ( V_75 )
fprintf ( V_68 , L_6 ) ;
else
fprintf ( V_68 , L_7 ) ;
}
if ( ++ V_71 == 25 )
V_71 = 0 ;
if ( V_80 )
F_27 ( V_74 ) ;
else if ( V_75 ) {
F_25 (counter, &evsel_list->entries, node)
F_28 ( V_37 , V_74 ) ;
} else {
F_25 (counter, &evsel_list->entries, node)
F_29 ( V_37 , V_74 ) ;
}
}
static int F_30 ( int T_3 V_81 , const char * * V_82 )
{
char V_83 [ 512 ] ;
unsigned long long V_84 , V_85 ;
struct V_8 * V_37 ;
struct V_1 V_72 ;
int V_86 = 0 ;
int V_87 [ 2 ] , V_88 [ 2 ] ;
const bool V_89 = ( T_3 > 0 ) ;
char V_90 ;
if ( V_91 ) {
V_72 . V_5 = V_91 / 1000 ;
V_72 . V_6 = ( V_91 % 1000 ) * 1000000 ;
} else {
V_72 . V_5 = 1 ;
V_72 . V_6 = 0 ;
}
if ( V_80
&& F_31 ( V_13 -> V_10 , & V_92 ) ) {
perror ( L_8 ) ;
return - 1 ;
}
if ( V_89 && ( F_32 ( V_87 ) < 0 || F_32 ( V_88 ) < 0 ) ) {
perror ( L_9 ) ;
return - 1 ;
}
if ( V_89 ) {
if ( ( V_93 = F_33 () ) < 0 )
perror ( L_10 ) ;
if ( ! V_93 ) {
F_34 ( V_87 [ 0 ] ) ;
F_34 ( V_88 [ 1 ] ) ;
F_35 ( V_88 [ 0 ] , V_94 , V_95 ) ;
F_36 ( L_11 , ( char * * ) V_82 ) ;
F_34 ( V_87 [ 1 ] ) ;
if ( F_37 ( V_88 [ 0 ] , & V_90 , 1 ) == - 1 )
perror ( L_12 ) ;
F_36 ( V_82 [ 0 ] , ( char * * ) V_82 ) ;
perror ( V_82 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_38 ( & V_11 ) )
V_13 -> V_33 -> V_96 [ 0 ] = V_93 ;
F_34 ( V_87 [ 1 ] ) ;
F_34 ( V_88 [ 0 ] ) ;
if ( F_37 ( V_87 [ 0 ] , & V_90 , 1 ) == - 1 )
perror ( L_12 ) ;
F_34 ( V_87 [ 0 ] ) ;
}
if ( V_97 )
F_39 ( V_13 ) ;
F_25 (counter, &evsel_list->entries, node) {
if ( F_9 ( V_37 ) < 0 ) {
if ( V_98 == V_99 || V_98 == V_100 ||
V_98 == V_101 || V_98 == V_102 ||
V_98 == V_103 ) {
if ( V_67 )
F_40 ( L_13 ,
F_21 ( V_37 ) ) ;
V_37 -> V_104 = false ;
continue;
}
F_41 ( V_37 , & V_11 ,
V_98 , V_83 , sizeof( V_83 ) ) ;
F_42 ( L_14 , V_83 ) ;
if ( V_93 != - 1 )
F_43 ( V_93 , V_105 ) ;
return - 1 ;
}
V_37 -> V_104 = true ;
}
if ( F_44 ( V_13 ) ) {
error ( L_15 , V_98 ,
strerror ( V_98 ) ) ;
return - 1 ;
}
V_84 = F_45 () ;
F_26 ( V_76 , & V_77 ) ;
if ( V_89 ) {
F_34 ( V_88 [ 1 ] ) ;
if ( V_91 ) {
while ( ! F_46 ( V_93 , & V_86 , V_106 ) ) {
F_47 ( & V_72 , NULL ) ;
F_24 () ;
}
}
F_48 ( & V_86 ) ;
if ( F_49 ( V_86 ) )
F_50 ( F_51 ( V_86 ) , V_82 [ 0 ] ) ;
} else {
while ( ! V_107 ) {
F_47 ( & V_72 , NULL ) ;
if ( V_91 )
F_24 () ;
}
}
V_85 = F_45 () ;
F_18 ( & V_108 , V_85 - V_84 ) ;
if ( V_75 ) {
F_25 (counter, &evsel_list->entries, node) {
F_22 ( V_37 ) ;
F_52 ( V_37 , F_3 ( V_37 ) , 1 ) ;
}
} else {
F_25 (counter, &evsel_list->entries, node) {
F_19 ( V_37 ) ;
F_52 ( V_37 , F_3 ( V_37 ) ,
V_13 -> V_33 -> V_14 ) ;
}
}
return F_53 ( V_86 ) ;
}
static int F_54 ( int T_3 V_81 , const char * * V_82 )
{
int V_109 ;
if ( V_110 ) {
V_109 = system ( V_110 ) ;
if ( V_109 )
return V_109 ;
}
if ( V_111 )
F_55 () ;
V_109 = F_30 ( T_3 , V_82 ) ;
if ( V_109 )
return V_109 ;
if ( V_112 ) {
V_109 = system ( V_112 ) ;
if ( V_109 )
return V_109 ;
}
return V_109 ;
}
static void F_56 ( double V_113 , double V_114 )
{
double V_115 = F_57 ( V_113 , V_114 ) ;
if ( V_79 )
fprintf ( V_68 , L_16 , V_78 , V_115 ) ;
else if ( V_115 )
fprintf ( V_68 , L_17 , V_115 ) ;
}
static void F_58 ( struct V_8 * V_9 , double V_114 )
{
struct V_16 * V_62 ;
if ( V_116 == 1 )
return;
V_62 = V_9 -> V_15 ;
F_56 ( F_59 ( & V_62 -> V_66 [ 0 ] ) , V_114 ) ;
}
static void F_60 ( int V_70 , int V_14 , struct V_8 * V_9 , double V_114 )
{
double V_117 = V_114 / 1e6 ;
char V_118 [ 16 ] = { '\0' , } ;
const char * V_119 = V_79 ? L_18 : L_19 ;
if ( V_80 )
sprintf ( V_118 , L_20 ,
V_79 ? 0 : - 5 ,
V_70 ,
V_78 ,
V_79 ? 0 : 4 ,
V_14 ,
V_78 ) ;
else if ( V_75 )
sprintf ( V_118 , L_21 ,
V_79 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_96 [ V_70 ] , V_78 ) ;
fprintf ( V_68 , V_119 , V_118 , V_117 , V_78 , F_21 ( V_9 ) ) ;
if ( V_9 -> V_120 )
fprintf ( V_68 , L_22 , V_78 , V_9 -> V_120 -> V_121 ) ;
if ( V_79 || V_91 )
return;
if ( F_16 ( V_9 , V_34 , V_36 ) )
fprintf ( V_68 , L_23 ,
V_114 / F_61 ( & V_108 ) ) ;
else
fprintf ( V_68 , L_24 ) ;
}
static const char * F_62 ( enum V_122 type , double V_123 )
{
static const double V_124 [ V_125 ] [ 3 ] = {
[ V_126 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_127 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_128 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_129 = V_130 ;
if ( V_123 > V_124 [ type ] [ 0 ] )
V_129 = V_131 ;
else if ( V_123 > V_124 [ type ] [ 1 ] )
V_129 = V_132 ;
else if ( V_123 > V_124 [ type ] [ 2 ] )
V_129 = V_133 ;
return V_129 ;
}
static void F_63 ( int V_70 ,
struct V_8 * V_9
V_81 , double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_42 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_126 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_27 ) ;
}
static void F_65 ( int V_70 ,
struct V_8 * V_9
V_81 , double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_42 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_127 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_28 ) ;
}
static void F_66 ( int V_70 ,
struct V_8 * V_9 V_81 ,
double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_48 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_128 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_29 ) ;
}
static void F_67 ( int V_70 ,
struct V_8 * V_9 V_81 ,
double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_53 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_128 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_30 ) ;
}
static void F_68 ( int V_70 ,
struct V_8 * V_9 V_81 ,
double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_55 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_128 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_31 ) ;
}
static void F_69 ( int V_70 ,
struct V_8 * V_9 V_81 ,
double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_59 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_128 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_32 ) ;
}
static void F_70 ( int V_70 ,
struct V_8 * V_9 V_81 ,
double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_61 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_128 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_33 ) ;
}
static void F_71 ( int V_70 ,
struct V_8 * V_9 V_81 ,
double V_114 )
{
double V_113 , V_123 = 0.0 ;
const char * V_129 ;
V_113 = F_61 ( & V_57 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 * 100.0 ;
V_129 = F_62 ( V_128 , V_123 ) ;
fprintf ( V_68 , L_25 ) ;
F_64 ( V_68 , V_129 , L_26 , V_123 ) ;
fprintf ( V_68 , L_34 ) ;
}
static void F_72 ( int V_70 , int V_14 , struct V_8 * V_9 , double V_114 )
{
double V_113 , V_123 = 0.0 ;
char V_118 [ 16 ] = { '\0' , } ;
const char * V_119 ;
if ( V_79 )
V_119 = L_35 ;
else if ( V_134 )
V_119 = L_36 ;
else
V_119 = L_37 ;
if ( V_80 )
sprintf ( V_118 , L_20 ,
V_79 ? 0 : - 5 ,
V_70 ,
V_78 ,
V_79 ? 0 : 4 ,
V_14 ,
V_78 ) ;
else if ( V_75 )
sprintf ( V_118 , L_21 ,
V_79 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_96 [ V_70 ] , V_78 ) ;
else
V_70 = 0 ;
fprintf ( V_68 , V_119 , V_118 , V_114 , V_78 , F_21 ( V_9 ) ) ;
if ( V_9 -> V_120 )
fprintf ( V_68 , L_22 , V_78 , V_9 -> V_120 -> V_121 ) ;
if ( V_79 || V_91 )
return;
if ( F_16 ( V_9 , V_40 , V_135 ) ) {
V_113 = F_61 ( & V_42 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 / V_113 ;
fprintf ( V_68 , L_38 , V_123 ) ;
V_113 = F_61 ( & V_44 [ V_70 ] ) ;
V_113 = F_73 ( V_113 , F_61 ( & V_46 [ V_70 ] ) ) ;
if ( V_113 && V_114 ) {
V_123 = V_113 / V_114 ;
fprintf ( V_68 , L_39 , V_123 ) ;
}
} else if ( F_16 ( V_9 , V_40 , V_136 ) &&
V_48 [ V_70 ] . V_137 != 0 ) {
F_66 ( V_70 , V_9 , V_114 ) ;
} else if (
V_9 -> V_24 . type == V_138 &&
V_9 -> V_24 . V_139 == ( V_140 |
( ( V_141 ) << 8 ) |
( ( V_142 ) << 16 ) ) &&
V_53 [ V_70 ] . V_137 != 0 ) {
F_67 ( V_70 , V_9 , V_114 ) ;
} else if (
V_9 -> V_24 . type == V_138 &&
V_9 -> V_24 . V_139 == ( V_143 |
( ( V_141 ) << 8 ) |
( ( V_142 ) << 16 ) ) &&
V_55 [ V_70 ] . V_137 != 0 ) {
F_68 ( V_70 , V_9 , V_114 ) ;
} else if (
V_9 -> V_24 . type == V_138 &&
V_9 -> V_24 . V_139 == ( V_144 |
( ( V_141 ) << 8 ) |
( ( V_142 ) << 16 ) ) &&
V_59 [ V_70 ] . V_137 != 0 ) {
F_69 ( V_70 , V_9 , V_114 ) ;
} else if (
V_9 -> V_24 . type == V_138 &&
V_9 -> V_24 . V_139 == ( V_145 |
( ( V_141 ) << 8 ) |
( ( V_142 ) << 16 ) ) &&
V_61 [ V_70 ] . V_137 != 0 ) {
F_70 ( V_70 , V_9 , V_114 ) ;
} else if (
V_9 -> V_24 . type == V_138 &&
V_9 -> V_24 . V_139 == ( V_146 |
( ( V_141 ) << 8 ) |
( ( V_142 ) << 16 ) ) &&
V_57 [ V_70 ] . V_137 != 0 ) {
F_71 ( V_70 , V_9 , V_114 ) ;
} else if ( F_16 ( V_9 , V_40 , V_147 ) &&
V_50 [ V_70 ] . V_137 != 0 ) {
V_113 = F_61 ( & V_50 [ V_70 ] ) ;
if ( V_113 )
V_123 = V_114 * 100 / V_113 ;
fprintf ( V_68 , L_40 , V_123 ) ;
} else if ( F_16 ( V_9 , V_40 , V_43 ) ) {
F_63 ( V_70 , V_9 , V_114 ) ;
} else if ( F_16 ( V_9 , V_40 , V_45 ) ) {
F_65 ( V_70 , V_9 , V_114 ) ;
} else if ( F_16 ( V_9 , V_40 , V_41 ) ) {
V_113 = F_61 ( & V_39 [ V_70 ] ) ;
if ( V_113 )
V_123 = 1.0 * V_114 / V_113 ;
fprintf ( V_68 , L_41 , V_123 ) ;
} else if ( V_39 [ V_70 ] . V_137 != 0 ) {
char V_148 = 'M' ;
V_113 = F_61 ( & V_39 [ V_70 ] ) ;
if ( V_113 )
V_123 = 1000.0 * V_114 / V_113 ;
if ( V_123 < 0.001 ) {
V_123 *= 1000 ;
V_148 = 'K' ;
}
fprintf ( V_68 , L_42 , V_123 , V_148 ) ;
} else {
fprintf ( V_68 , L_24 ) ;
}
}
static void F_27 ( char * V_74 )
{
struct V_8 * V_37 ;
T_2 V_149 , V_150 , V_151 ;
int V_70 , V_152 , V_153 , V_154 , V_14 ;
if ( ! V_92 )
return;
for ( V_152 = 0 ; V_152 < V_92 -> V_14 ; V_152 ++ ) {
V_154 = F_74 ( V_92 , V_152 ) ;
F_25 (counter, &evsel_list->entries, node) {
V_151 = V_149 = V_150 = 0 ;
V_14 = 0 ;
for ( V_70 = 0 ; V_70 < F_3 ( V_37 ) ; V_70 ++ ) {
V_153 = F_75 ( V_13 -> V_10 , V_70 ) ;
if ( V_153 != V_154 )
continue;
V_151 += V_37 -> V_20 -> V_70 [ V_70 ] . V_151 ;
V_149 += V_37 -> V_20 -> V_70 [ V_70 ] . V_149 ;
V_150 += V_37 -> V_20 -> V_70 [ V_70 ] . V_150 ;
V_14 ++ ;
}
if ( V_74 )
fprintf ( V_68 , L_43 , V_74 ) ;
if ( V_150 == 0 || V_149 == 0 ) {
fprintf ( V_68 , L_44 ,
V_79 ? 0 : - 5 ,
V_152 ,
V_78 ,
V_79 ? 0 : 4 ,
V_14 ,
V_78 ,
V_79 ? 0 : 18 ,
V_37 -> V_104 ? V_155 : V_156 ,
V_78 ,
V_79 ? 0 : - 24 ,
F_21 ( V_37 ) ) ;
if ( V_37 -> V_120 )
fprintf ( V_68 , L_22 ,
V_78 , V_37 -> V_120 -> V_121 ) ;
fputc ( '\n' , V_68 ) ;
continue;
}
if ( F_15 ( V_37 ) )
F_60 ( V_154 , V_14 , V_37 , V_151 ) ;
else
F_72 ( V_154 , V_14 , V_37 , V_151 ) ;
if ( ! V_79 ) {
F_58 ( V_37 , 1.0 ) ;
if ( V_150 != V_149 )
fprintf ( V_68 , L_45 ,
100.0 * V_150 / V_149 ) ;
}
fputc ( '\n' , V_68 ) ;
}
}
}
static void F_29 ( struct V_8 * V_37 , char * V_74 )
{
struct V_16 * V_62 = V_37 -> V_15 ;
double V_114 = F_61 ( & V_62 -> V_66 [ 0 ] ) ;
int V_157 = V_37 -> V_20 -> V_157 ;
if ( V_74 )
fprintf ( V_68 , L_43 , V_74 ) ;
if ( V_157 == - 1 ) {
fprintf ( V_68 , L_46 ,
V_79 ? 0 : 18 ,
V_37 -> V_104 ? V_155 : V_156 ,
V_78 ,
V_79 ? 0 : - 24 ,
F_21 ( V_37 ) ) ;
if ( V_37 -> V_120 )
fprintf ( V_68 , L_22 , V_78 , V_37 -> V_120 -> V_121 ) ;
fputc ( '\n' , V_68 ) ;
return;
}
if ( F_15 ( V_37 ) )
F_60 ( - 1 , 0 , V_37 , V_114 ) ;
else
F_72 ( - 1 , 0 , V_37 , V_114 ) ;
F_58 ( V_37 , V_114 ) ;
if ( V_79 ) {
fputc ( '\n' , V_68 ) ;
return;
}
if ( V_157 ) {
double V_158 , V_159 ;
V_158 = F_61 ( & V_62 -> V_66 [ 1 ] ) ;
V_159 = F_61 ( & V_62 -> V_66 [ 2 ] ) ;
fprintf ( V_68 , L_47 , 100 * V_159 / V_158 ) ;
}
fprintf ( V_68 , L_3 ) ;
}
static void F_28 ( struct V_8 * V_37 , char * V_74 )
{
T_2 V_149 , V_150 , V_151 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_3 ( V_37 ) ; V_70 ++ ) {
V_151 = V_37 -> V_20 -> V_70 [ V_70 ] . V_151 ;
V_149 = V_37 -> V_20 -> V_70 [ V_70 ] . V_149 ;
V_150 = V_37 -> V_20 -> V_70 [ V_70 ] . V_150 ;
if ( V_74 )
fprintf ( V_68 , L_43 , V_74 ) ;
if ( V_150 == 0 || V_149 == 0 ) {
fprintf ( V_68 , L_48 ,
V_79 ? 0 : - 4 ,
F_2 ( V_37 ) -> V_96 [ V_70 ] , V_78 ,
V_79 ? 0 : 18 ,
V_37 -> V_104 ? V_155 : V_156 ,
V_78 ,
V_79 ? 0 : - 24 ,
F_21 ( V_37 ) ) ;
if ( V_37 -> V_120 )
fprintf ( V_68 , L_22 ,
V_78 , V_37 -> V_120 -> V_121 ) ;
fputc ( '\n' , V_68 ) ;
continue;
}
if ( F_15 ( V_37 ) )
F_60 ( V_70 , 0 , V_37 , V_151 ) ;
else
F_72 ( V_70 , 0 , V_37 , V_151 ) ;
if ( ! V_79 ) {
F_58 ( V_37 , 1.0 ) ;
if ( V_150 != V_149 )
fprintf ( V_68 , L_45 ,
100.0 * V_150 / V_149 ) ;
}
fputc ( '\n' , V_68 ) ;
}
}
static void F_76 ( int T_3 , const char * * V_82 )
{
struct V_8 * V_37 ;
int V_65 ;
fflush ( stdout ) ;
if ( ! V_79 ) {
fprintf ( V_68 , L_3 ) ;
fprintf ( V_68 , L_49 ) ;
if ( ! F_12 ( & V_11 ) ) {
fprintf ( V_68 , L_50 , V_82 [ 0 ] ) ;
for ( V_65 = 1 ; V_65 < T_3 ; V_65 ++ )
fprintf ( V_68 , L_51 , V_82 [ V_65 ] ) ;
} else if ( V_11 . V_160 )
fprintf ( V_68 , L_52 , V_11 . V_160 ) ;
else
fprintf ( V_68 , L_53 , V_11 . V_161 ) ;
fprintf ( V_68 , L_54 ) ;
if ( V_116 > 1 )
fprintf ( V_68 , L_55 , V_116 ) ;
fprintf ( V_68 , L_56 ) ;
}
if ( V_80 )
F_27 ( NULL ) ;
else if ( V_75 ) {
F_25 (counter, &evsel_list->entries, node)
F_28 ( V_37 , NULL ) ;
} else {
F_25 (counter, &evsel_list->entries, node)
F_29 ( V_37 , NULL ) ;
}
if ( ! V_79 ) {
if ( ! V_162 )
fprintf ( V_68 , L_3 ) ;
fprintf ( V_68 , L_57 ,
F_61 ( & V_108 ) / 1e9 ) ;
if ( V_116 > 1 ) {
fprintf ( V_68 , L_58 ) ;
F_56 ( F_59 ( & V_108 ) ,
F_61 ( & V_108 ) ) ;
}
fprintf ( V_68 , L_59 ) ;
}
}
static void F_77 ( int V_163 )
{
if ( ( V_93 == - 1 ) || V_91 )
V_107 = 1 ;
V_164 = V_163 ;
}
static void F_78 ( void )
{
if ( V_93 != - 1 )
F_43 ( V_93 , V_105 ) ;
if ( V_164 == - 1 )
return;
signal ( V_164 , V_165 ) ;
F_43 ( F_79 () , V_164 ) ;
}
static int F_80 ( const struct V_166 * T_4 V_81 ,
const char * V_152 V_81 , int V_167 )
{
V_168 = V_167 ? 0 : 1 ;
return 0 ;
}
static int F_81 ( void )
{
struct V_23 V_169 [] = {
{ . type = V_170 , . V_139 = V_171 } ,
{ . type = V_170 , . V_139 = V_172 } ,
{ . type = V_170 , . V_139 = V_173 } ,
{ . type = V_170 , . V_139 = V_174 } ,
{ . type = V_175 , . V_139 = V_176 } ,
{ . type = V_175 , . V_139 = V_177 } ,
{ . type = V_175 , . V_139 = V_178 } ,
{ . type = V_175 , . V_139 = V_179 } ,
{ . type = V_175 , . V_139 = V_180 } ,
{ . type = V_175 , . V_139 = V_181 } ,
} ;
struct V_23 V_182 [] = {
{ . type = V_138 ,
. V_139 =
V_140 << 0 |
( V_141 << 8 ) |
( V_183 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_140 << 0 |
( V_141 << 8 ) |
( V_142 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_146 << 0 |
( V_141 << 8 ) |
( V_183 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_146 << 0 |
( V_141 << 8 ) |
( V_142 << 16 ) } ,
} ;
struct V_23 V_184 [] = {
{ . type = V_138 ,
. V_139 =
V_143 << 0 |
( V_141 << 8 ) |
( V_183 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_143 << 0 |
( V_141 << 8 ) |
( V_142 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_144 << 0 |
( V_141 << 8 ) |
( V_183 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_144 << 0 |
( V_141 << 8 ) |
( V_142 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_145 << 0 |
( V_141 << 8 ) |
( V_183 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_145 << 0 |
( V_141 << 8 ) |
( V_142 << 16 ) } ,
} ;
struct V_23 V_185 [] = {
{ . type = V_138 ,
. V_139 =
V_140 << 0 |
( V_186 << 8 ) |
( V_183 << 16 ) } ,
{ . type = V_138 ,
. V_139 =
V_140 << 0 |
( V_186 << 8 ) |
( V_142 << 16 ) } ,
} ;
if ( V_162 )
return 0 ;
if ( ! V_13 -> V_187 ) {
if ( F_82 ( V_13 , V_169 ) < 0 )
return - 1 ;
}
if ( V_188 < 1 )
return 0 ;
if ( F_82 ( V_13 , V_182 ) < 0 )
return - 1 ;
if ( V_188 < 2 )
return 0 ;
if ( F_82 ( V_13 , V_184 ) < 0 )
return - 1 ;
if ( V_188 < 3 )
return 0 ;
return F_82 ( V_13 , V_185 ) ;
}
int F_83 ( int T_3 , const char * * V_82 , const char * V_74 V_81 )
{
bool V_189 = false ;
int V_190 = 0 ;
const char * V_191 = NULL ;
const struct V_166 V_192 [] = {
F_84 ( 'e' , L_60 , & V_13 , L_60 ,
L_61 ,
V_193 ) ,
F_84 ( 0 , L_62 , & V_13 , L_62 ,
L_63 , V_194 ) ,
F_85 ( 'i' , L_64 , & V_30 ,
L_65 ) ,
F_86 ( 'p' , L_66 , & V_11 . V_160 , L_66 ,
L_67 ) ,
F_86 ( 't' , L_68 , & V_11 . V_161 , L_68 ,
L_69 ) ,
F_85 ( 'a' , L_70 , & V_11 . V_195 ,
L_71 ) ,
F_85 ( 'g' , L_72 , & V_97 ,
L_73 ) ,
F_85 ( 'c' , L_74 , & V_25 , L_75 ) ,
F_87 ( 'v' , L_76 , & V_67 ,
L_77 ) ,
F_88 ( 'r' , L_78 , & V_116 ,
L_79 ) ,
F_85 ( 'n' , L_80 , & V_162 ,
L_81 ) ,
F_87 ( 'd' , L_82 , & V_188 ,
L_83 ) ,
F_85 ( 'S' , L_84 , & V_111 ,
L_85 ) ,
F_89 ( 'B' , L_86 , NULL , NULL ,
L_87 ,
F_80 ) ,
F_86 ( 'C' , L_88 , & V_11 . V_12 , L_88 ,
L_89 ) ,
F_85 ( 'A' , L_90 , & V_75 , L_91 ) ,
F_86 ( 'x' , L_92 , & V_78 , L_93 ,
L_94 ) ,
F_84 ( 'G' , L_95 , & V_13 , L_96 ,
L_97 , V_196 ) ,
F_86 ( 'o' , L_98 , & V_191 , L_99 , L_100 ) ,
F_85 ( 0 , L_101 , & V_189 , L_102 ) ,
F_88 ( 0 , L_103 , & V_190 ,
L_104 ) ,
F_86 ( 0 , L_105 , & V_110 , L_106 ,
L_107 ) ,
F_86 ( 0 , L_108 , & V_112 , L_106 ,
L_109 ) ,
F_90 ( 'I' , L_110 , & V_91 ,
L_111 ) ,
F_85 ( 0 , L_112 , & V_80 , L_113 ) ,
F_91 ()
} ;
const char * const V_197 [] = {
L_114 ,
NULL
} ;
struct V_8 * V_198 ;
int V_86 = - V_17 , V_199 ;
const char * V_200 ;
setlocale ( V_201 , L_11 ) ;
V_13 = F_92 ( NULL , NULL ) ;
if ( V_13 == NULL )
return - V_17 ;
T_3 = F_93 ( T_3 , V_82 , V_192 , V_197 ,
V_202 ) ;
V_68 = V_203 ;
if ( V_191 && strcmp ( V_191 , L_115 ) )
V_68 = NULL ;
if ( V_191 && V_190 ) {
fprintf ( V_203 , L_116 ) ;
F_94 ( V_197 , V_192 ) ;
}
if ( V_190 < 0 ) {
fprintf ( V_203 , L_117 ) ;
F_94 ( V_197 , V_192 ) ;
}
if ( ! V_68 ) {
struct V_1 V_204 ;
V_200 = V_189 ? L_118 : L_119 ;
V_68 = fopen ( V_191 , V_200 ) ;
if ( ! V_68 ) {
perror ( L_120 ) ;
return - 1 ;
}
F_26 ( V_205 , & V_204 ) ;
fprintf ( V_68 , L_121 , ctime ( & V_204 . V_5 ) ) ;
} else if ( V_190 > 0 ) {
V_200 = V_189 ? L_118 : L_119 ;
V_68 = fdopen ( V_190 , V_200 ) ;
if ( ! V_68 ) {
perror ( L_122 ) ;
return - V_98 ;
}
}
if ( V_78 ) {
V_79 = true ;
if ( ! strcmp ( V_78 , L_123 ) )
V_78 = L_124 ;
} else
V_78 = V_206 ;
if ( V_79 ) {
if ( V_168 == 1 ) {
fprintf ( V_203 , L_125 ) ;
F_94 ( V_197 , V_192 ) ;
} else
V_134 = false ;
} else if ( V_168 == 0 )
V_134 = false ;
if ( ! T_3 && ! F_12 ( & V_11 ) )
F_94 ( V_197 , V_192 ) ;
if ( V_116 <= 0 )
F_94 ( V_197 , V_192 ) ;
if ( ( V_75 || V_207 ) && ! F_10 ( & V_11 ) ) {
fprintf ( V_203 , L_126
L_127 ) ;
F_94 ( V_197 , V_192 ) ;
}
if ( V_80 ) {
if ( ! F_10 ( & V_11 ) ) {
fprintf ( V_203 , L_128 ) ;
F_94 ( V_197 , V_192 ) ;
}
V_75 = true ;
}
if ( F_81 () )
goto V_208;
F_95 ( & V_11 ) ;
if ( F_96 ( V_13 , & V_11 ) < 0 ) {
if ( F_12 ( & V_11 ) )
F_97 ( L_129 ) ;
if ( F_10 ( & V_11 ) )
perror ( L_130 ) ;
F_94 ( V_197 , V_192 ) ;
return - 1 ;
}
if ( V_91 && V_91 < 100 ) {
F_97 ( L_131 ) ;
F_94 ( V_197 , V_192 ) ;
return - 1 ;
}
F_25 (pos, &evsel_list->entries, node) {
if ( F_4 ( V_198 ) < 0 ||
F_98 ( V_198 , F_3 ( V_198 ) ) < 0 )
goto V_209;
}
if ( V_91 ) {
F_25 (pos, &evsel_list->entries, node) {
if ( F_7 ( V_198 ) < 0 )
goto V_209;
}
}
atexit ( F_78 ) ;
signal ( V_210 , F_77 ) ;
signal ( V_211 , F_77 ) ;
signal ( V_212 , F_77 ) ;
signal ( V_213 , F_77 ) ;
V_86 = 0 ;
for ( V_199 = 0 ; V_199 < V_116 ; V_199 ++ ) {
if ( V_116 != 1 && V_67 )
fprintf ( V_68 , L_132 ,
V_199 + 1 ) ;
V_86 = F_54 ( T_3 , V_82 ) ;
}
if ( V_86 != - 1 && ! V_91 )
F_76 ( T_3 , V_82 ) ;
V_209:
F_25 (pos, &evsel_list->entries, node) {
F_6 ( V_198 ) ;
F_99 ( V_198 ) ;
F_8 ( V_198 ) ;
}
F_100 ( V_13 ) ;
V_208:
F_101 ( V_13 ) ;
return V_86 ;
}
