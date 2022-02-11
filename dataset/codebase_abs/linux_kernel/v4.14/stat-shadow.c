static int F_1 ( struct V_1 * V_1 , const void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ,
struct V_3 ,
V_1 ) ;
const struct V_3 * V_5 = V_2 ;
if ( V_4 -> V_6 != V_5 -> V_6 )
return V_4 -> V_6 - V_5 -> V_6 ;
if ( V_4 -> V_7 != V_5 -> V_7 )
return V_4 -> V_7 - V_5 -> V_7 ;
if ( V_4 -> V_8 == V_5 -> V_8 )
return 0 ;
if ( ( char * ) V_4 -> V_8 < ( char * ) V_5 -> V_8 )
return - 1 ;
return + 1 ;
}
static struct V_1 * F_3 ( struct V_9 * V_9 V_10 ,
const void * V_2 )
{
struct V_3 * V_11 = malloc ( sizeof( struct V_3 ) ) ;
if ( ! V_11 )
return NULL ;
memcpy ( V_11 , V_2 , sizeof( struct V_3 ) ) ;
return & V_11 -> V_1 ;
}
static struct V_3 * F_4 ( struct V_12 * V_8 ,
int V_7 , int V_6 ,
bool V_13 )
{
struct V_1 * V_11 ;
struct V_3 V_14 = {
. V_7 = V_7 ,
. V_6 = V_6 ,
. V_8 = V_8 ,
} ;
V_11 = F_5 ( & V_15 , & V_14 ) ;
if ( V_11 )
return F_2 ( V_11 , struct V_3 , V_1 ) ;
if ( V_13 ) {
F_6 ( & V_15 , & V_14 ) ;
V_11 = F_5 ( & V_15 , & V_14 ) ;
if ( V_11 )
return F_2 ( V_11 , struct V_3 , V_1 ) ;
}
return NULL ;
}
void F_7 ( void )
{
V_16 = F_8 ( L_1 , L_2 ) ;
F_9 ( & V_15 ) ;
V_15 . V_17 = F_1 ;
V_15 . V_18 = F_3 ;
}
static int F_10 ( struct V_12 * V_8 )
{
int V_6 = 0 ;
if ( V_8 -> V_19 . V_20 )
V_6 |= V_21 ;
if ( V_8 -> V_19 . V_22 )
V_6 |= V_23 ;
if ( V_8 -> V_19 . V_24 )
V_6 |= V_25 ;
if ( V_8 -> V_19 . V_26 )
V_6 |= V_27 ;
if ( V_8 -> V_19 . V_28 )
V_6 |= V_29 ;
return V_6 ;
}
void F_11 ( void )
{
struct V_1 * V_30 , * V_31 ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
memset ( V_42 , 0 , sizeof( V_42 ) ) ;
memset ( V_43 , 0 ,
sizeof( V_43 ) ) ;
memset ( V_44 , 0 ,
sizeof( V_44 ) ) ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
memset ( V_49 , 0 , sizeof( V_49 ) ) ;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
memset ( V_52 , 0 , sizeof( V_52 ) ) ;
memset ( V_53 , 0 , sizeof( V_53 ) ) ;
V_31 = F_12 ( & V_15 . V_54 ) ;
while ( V_31 ) {
V_30 = V_31 ;
V_31 = F_13 ( V_30 ) ;
memset ( & F_2 ( V_30 , struct V_3 , V_1 ) -> V_55 ,
0 ,
sizeof( struct V_55 ) ) ;
}
}
void F_14 ( struct V_12 * V_56 , T_1 * V_57 ,
int V_7 )
{
int V_6 = F_10 ( V_56 ) ;
if ( F_15 ( V_56 , V_58 , V_59 ) ||
F_15 ( V_56 , V_58 , V_60 ) )
F_16 ( & V_32 [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_61 , V_62 ) )
F_16 ( & V_33 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_63 ) )
F_16 ( & V_43 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_64 ) )
F_16 ( & V_44 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_65 ) )
F_16 ( & V_45 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_66 ) )
F_16 ( & V_47 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_67 ) )
F_16 ( & V_49 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_68 ) )
F_16 ( & V_48 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_69 ) )
F_16 ( & V_50 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_70 ) )
F_16 ( & V_51 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_61 , V_71 ) )
F_16 ( & V_34 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_61 , V_72 ) )
F_16 ( & V_35 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_61 , V_73 ) )
F_16 ( & V_36 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_61 , V_74 ) )
F_16 ( & V_37 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_75 , V_76 ) )
F_16 ( & V_38 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_75 , V_77 ) )
F_16 ( & V_40 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_75 , V_78 ) )
F_16 ( & V_40 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_75 , V_79 ) )
F_16 ( & V_42 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_15 ( V_56 , V_75 , V_80 ) )
F_16 ( & V_41 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_81 ) )
F_16 ( & V_52 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
else if ( F_17 ( V_56 , V_82 ) )
F_16 ( & V_53 [ V_6 ] [ V_7 ] , V_57 [ 0 ] ) ;
if ( V_56 -> V_83 ) {
struct V_3 * V_84 = F_4 ( V_56 , V_7 , V_6 ,
true ) ;
F_16 ( & V_84 -> V_55 , V_57 [ 0 ] ) ;
}
}
static const char * F_18 ( enum V_85 type , double V_86 )
{
static const double V_87 [ V_88 ] [ 3 ] = {
[ V_89 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_90 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_91 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_92 = V_93 ;
if ( V_86 > V_87 [ type ] [ 0 ] )
V_92 = V_94 ;
else if ( V_86 > V_87 [ type ] [ 1 ] )
V_92 = V_95 ;
else if ( V_86 > V_87 [ type ] [ 2 ] )
V_92 = V_96 ;
return V_92 ;
}
static struct V_12 * F_19 ( struct V_97 * V_98 ,
const char * V_99 )
{
struct V_12 * V_100 ;
F_20 (evsel_list, c2) {
if ( ! strcasecmp ( V_100 -> V_99 , V_99 ) )
return V_100 ;
}
return NULL ;
}
void F_21 ( struct V_97 * V_98 )
{
struct V_12 * V_56 , * V_101 , * * V_102 , * V_103 ;
bool V_104 ;
const char * * V_105 ;
int V_106 ;
int V_107 ;
F_20 (evsel_list, counter) {
bool V_108 = false ;
V_101 = V_56 -> V_101 ;
if ( ! V_56 -> V_109 )
continue;
V_102 = V_56 -> V_102 ;
if ( ! V_102 ) {
if ( F_22 ( V_56 -> V_109 , V_56 -> V_99 ,
& V_105 , & V_107 ) < 0 )
continue;
V_102 = calloc ( sizeof( struct V_12 * ) ,
V_107 + 1 ) ;
if ( ! V_102 )
return;
V_56 -> V_102 = V_102 ;
}
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ ) {
V_104 = false ;
if ( V_101 ) {
F_23 (oc, leader) {
if ( ! strcasecmp ( V_103 -> V_99 , V_105 [ V_106 ] ) ) {
V_104 = true ;
break;
}
}
}
if ( ! V_104 ) {
V_103 = F_19 ( V_98 , V_105 [ V_106 ] ) ;
}
if ( ! V_103 ) {
static char * V_110 ;
if ( ! V_110 || strcasecmp ( V_110 , V_105 [ V_106 ] ) ) {
fprintf ( V_111 ,
L_3 ,
V_105 [ V_106 ] ,
V_56 -> V_99 ) ;
V_110 = F_24 ( V_105 [ V_106 ] ) ;
}
V_108 = true ;
continue;
}
V_102 [ V_106 ] = V_103 ;
V_103 -> V_83 = true ;
}
V_102 [ V_106 ] = NULL ;
free ( V_105 ) ;
if ( V_108 ) {
free ( V_102 ) ;
V_56 -> V_102 = NULL ;
V_56 -> V_109 = NULL ;
}
}
}
static void F_25 ( int V_7 ,
struct V_12 * V_8 , double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_89 , V_86 ) ;
if ( V_86 )
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_5 ,
V_86 ) ;
else
V_114 -> V_116 ( V_114 -> V_6 , NULL , NULL , L_5 , 0 ) ;
}
static void F_27 ( int V_7 ,
struct V_12 * V_8 , double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_90 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_6 , V_86 ) ;
}
static void F_28 ( int V_7 ,
struct V_12 * V_8 ,
double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_36 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_91 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_7 , V_86 ) ;
}
static void F_29 ( int V_7 ,
struct V_12 * V_8 ,
double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_38 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_91 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_8 , V_86 ) ;
}
static void F_30 ( int V_7 ,
struct V_12 * V_8 ,
double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_39 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_91 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_9 , V_86 ) ;
}
static void F_31 ( int V_7 ,
struct V_12 * V_8 ,
double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_42 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_91 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_10 , V_86 ) ;
}
static void F_32 ( int V_7 ,
struct V_12 * V_8 ,
double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_41 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_91 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_11 , V_86 ) ;
}
static void F_33 ( int V_7 ,
struct V_12 * V_8 ,
double V_112 ,
struct V_113 * V_114 )
{
double V_115 , V_86 = 0.0 ;
const char * V_92 ;
int V_6 = F_10 ( V_8 ) ;
V_115 = F_26 ( & V_40 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 / V_115 * 100.0 ;
V_92 = F_18 ( V_91 , V_86 ) ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_4 , L_12 , V_86 ) ;
}
static double F_34 ( double V_117 )
{
if ( V_117 < 0 && V_117 >= - 0.02 )
return 0.0 ;
return V_117 ;
}
static double F_35 ( int V_6 , int V_7 )
{
return F_26 ( & V_47 [ V_6 ] [ V_7 ] ) ;
}
static double F_36 ( int V_6 , int V_7 )
{
double V_118 = 0 ;
double V_119 ;
double V_115 ;
V_115 = F_26 ( & V_49 [ V_6 ] [ V_7 ] ) -
F_26 ( & V_48 [ V_6 ] [ V_7 ] ) +
F_26 ( & V_51 [ V_6 ] [ V_7 ] ) ;
V_119 = F_35 ( V_6 , V_7 ) ;
if ( V_119 )
V_118 = V_115 / V_119 ;
return F_34 ( V_118 ) ;
}
static double F_37 ( int V_6 , int V_7 )
{
double V_120 = 0 ;
double V_119 = F_35 ( V_6 , V_7 ) ;
double V_121 = F_26 ( & V_48 [ V_6 ] [ V_7 ] ) ;
if ( V_119 )
V_120 = V_121 / V_119 ;
return V_120 ;
}
static double F_38 ( int V_6 , int V_7 )
{
double V_122 = 0 ;
double V_119 = F_35 ( V_6 , V_7 ) ;
double V_123 = F_26 ( & V_50 [ V_6 ] [ V_7 ] ) ;
if ( V_119 )
V_122 = V_123 / V_119 ;
return V_122 ;
}
static double F_39 ( int V_6 , int V_7 )
{
double V_124 = ( F_38 ( V_6 , V_7 ) +
F_36 ( V_6 , V_7 ) +
F_37 ( V_6 , V_7 ) ) ;
if ( V_124 == 0 )
return 0 ;
return F_34 ( 1.0 - V_124 ) ;
}
static void F_40 ( int V_7 , struct V_12 * V_8 ,
struct V_113 * V_114 )
{
double V_125 , V_126 , V_127 , V_128 = 0.0 ;
int V_6 = F_10 ( V_8 ) ;
const char * V_92 = NULL ;
V_125 = F_26 ( & V_52 [ V_6 ] [ V_7 ] ) ;
V_126 = F_26 ( & V_53 [ V_6 ] [ V_7 ] ) ;
V_127 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( ( V_127 == 0 ) || ( V_126 == 0 ) )
return;
if ( V_125 )
V_128 = ( V_126 - V_127 ) / V_126 * 100.00 ;
if ( V_128 > 10 )
V_92 = V_94 ;
V_114 -> V_116 ( V_114 -> V_6 , V_92 , L_13 , L_14 , V_128 ) ;
V_114 -> V_116 ( V_114 -> V_6 , NULL , L_15 , L_16 , V_125 ) ;
}
void F_41 ( struct V_12 * V_8 ,
double V_112 , int V_7 ,
struct V_113 * V_114 )
{
void * V_129 = V_114 -> V_6 ;
T_2 V_116 = V_114 -> V_116 ;
double V_115 , V_86 = 0.0 , V_130 ;
const char * V_92 = NULL ;
int V_6 = F_10 ( V_8 ) ;
if ( F_15 ( V_8 , V_61 , V_131 ) ) {
V_115 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_115 ) {
V_86 = V_112 / V_115 ;
V_116 ( V_129 , NULL , L_17 ,
L_18 , V_86 ) ;
} else {
V_116 ( V_129 , NULL , NULL , L_18 , 0 ) ;
}
V_115 = F_26 ( & V_34 [ V_6 ] [ V_7 ] ) ;
V_115 = F_42 ( V_115 , F_26 ( & V_35 [ V_6 ] [ V_7 ] ) ) ;
if ( V_115 && V_112 ) {
V_114 -> V_132 ( V_129 ) ;
V_86 = V_115 / V_112 ;
V_116 ( V_129 , NULL , L_17 ,
L_19 ,
V_86 ) ;
} else if ( V_16 ) {
V_116 ( V_129 , NULL , NULL ,
L_19 , 0 ) ;
}
} else if ( F_15 ( V_8 , V_61 , V_133 ) ) {
if ( V_36 [ V_6 ] [ V_7 ] . V_134 != 0 )
F_28 ( V_7 , V_8 , V_112 , V_114 ) ;
else
V_116 ( V_129 , NULL , NULL , L_7 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_135 &&
V_8 -> V_19 . V_136 == ( V_137 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) ) {
if ( V_38 [ V_6 ] [ V_7 ] . V_134 != 0 )
F_29 ( V_7 , V_8 , V_112 , V_114 ) ;
else
V_116 ( V_129 , NULL , NULL , L_8 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_135 &&
V_8 -> V_19 . V_136 == ( V_140 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) ) {
if ( V_39 [ V_6 ] [ V_7 ] . V_134 != 0 )
F_30 ( V_7 , V_8 , V_112 , V_114 ) ;
else
V_116 ( V_129 , NULL , NULL , L_9 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_135 &&
V_8 -> V_19 . V_136 == ( V_141 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) ) {
if ( V_42 [ V_6 ] [ V_7 ] . V_134 != 0 )
F_31 ( V_7 , V_8 , V_112 , V_114 ) ;
else
V_116 ( V_129 , NULL , NULL , L_10 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_135 &&
V_8 -> V_19 . V_136 == ( V_142 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) ) {
if ( V_41 [ V_6 ] [ V_7 ] . V_134 != 0 )
F_32 ( V_7 , V_8 , V_112 , V_114 ) ;
else
V_116 ( V_129 , NULL , NULL , L_11 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_135 &&
V_8 -> V_19 . V_136 == ( V_143 |
( ( V_138 ) << 8 ) |
( ( V_139 ) << 16 ) ) ) {
if ( V_40 [ V_6 ] [ V_7 ] . V_134 != 0 )
F_33 ( V_7 , V_8 , V_112 , V_114 ) ;
else
V_116 ( V_129 , NULL , NULL , L_12 , 0 ) ;
} else if ( F_15 ( V_8 , V_61 , V_144 ) ) {
V_115 = F_26 ( & V_37 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_86 = V_112 * 100 / V_115 ;
if ( V_37 [ V_6 ] [ V_7 ] . V_134 != 0 )
V_116 ( V_129 , NULL , L_20 ,
L_21 , V_86 ) ;
else
V_116 ( V_129 , NULL , NULL , L_21 , 0 ) ;
} else if ( F_15 ( V_8 , V_61 , V_71 ) ) {
F_25 ( V_7 , V_8 , V_112 , V_114 ) ;
} else if ( F_15 ( V_8 , V_61 , V_72 ) ) {
F_27 ( V_7 , V_8 , V_112 , V_114 ) ;
} else if ( F_15 ( V_8 , V_61 , V_62 ) ) {
V_115 = F_26 ( & V_32 [ V_7 ] ) ;
if ( V_115 ) {
V_86 = V_112 / V_115 ;
V_116 ( V_129 , NULL , L_22 , L_23 , V_86 ) ;
} else {
V_116 ( V_129 , NULL , NULL , L_24 , 0 ) ;
}
} else if ( F_17 ( V_8 , V_63 ) ) {
V_115 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_116 ( V_129 , NULL ,
L_4 , L_25 ,
100.0 * ( V_112 / V_115 ) ) ;
else
V_116 ( V_129 , NULL , NULL , L_25 ,
0 ) ;
} else if ( F_17 ( V_8 , V_145 ) ) {
V_115 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
V_130 = F_26 ( & V_43 [ V_6 ] [ V_7 ] ) ;
if ( V_130 < V_112 )
V_130 = V_112 ;
if ( V_115 )
V_116 ( V_129 , NULL , L_4 , L_26 ,
100.0 * ( ( V_130 - V_112 ) / V_115 ) ) ;
else
V_116 ( V_129 , NULL , NULL , L_26 , 0 ) ;
} else if ( F_17 ( V_8 , V_64 ) ) {
V_115 = F_26 ( & V_43 [ V_6 ] [ V_7 ] ) ;
if ( V_112 )
V_86 = V_115 / V_112 ;
if ( V_43 [ V_6 ] [ V_7 ] . V_134 != 0 )
V_116 ( V_129 , NULL , L_27 ,
L_28 , V_86 ) ;
else
V_116 ( V_129 , NULL , NULL , L_28 ,
0 ) ;
} else if ( F_17 ( V_8 , V_65 ) ) {
V_115 = F_26 ( & V_43 [ V_6 ] [ V_7 ] ) ;
if ( V_112 )
V_86 = V_115 / V_112 ;
V_116 ( V_129 , NULL , L_27 , L_29 , V_86 ) ;
} else if ( F_15 ( V_8 , V_58 , V_59 ) ||
F_15 ( V_8 , V_58 , V_60 ) ) {
if ( ( V_86 = F_26 ( & V_46 ) ) != 0 )
V_116 ( V_129 , NULL , L_22 , L_30 ,
V_112 / V_86 ) ;
else
V_116 ( V_129 , NULL , NULL , L_30 , 0 ) ;
} else if ( F_17 ( V_8 , V_69 ) ) {
double V_122 = F_38 ( V_6 , V_7 ) ;
if ( V_122 > 0.2 )
V_92 = V_94 ;
V_116 ( V_129 , V_92 , L_13 , L_31 ,
V_122 * 100. ) ;
} else if ( F_17 ( V_8 , V_68 ) ) {
double V_120 = F_37 ( V_6 , V_7 ) ;
if ( V_120 > 0.7 )
V_92 = V_146 ;
V_116 ( V_129 , V_92 , L_13 , L_32 ,
V_120 * 100. ) ;
} else if ( F_17 ( V_8 , V_70 ) ) {
double V_118 = F_36 ( V_6 , V_7 ) ;
if ( V_118 > 0.1 )
V_92 = V_94 ;
V_116 ( V_129 , V_92 , L_13 , L_33 ,
V_118 * 100. ) ;
} else if ( F_17 ( V_8 , V_67 ) ) {
double V_147 = F_39 ( V_6 , V_7 ) ;
const char * V_99 = L_34 ;
static int V_148 = - 1 ;
if ( V_148 < 0 )
V_148 = F_8 ( L_1 ,
L_35 ) ;
if ( ! V_148 )
V_99 = L_36 ;
if ( V_147 > 0.2 )
V_92 = V_94 ;
if ( F_35 ( V_6 , V_7 ) > 0 )
V_116 ( V_129 , V_92 , L_13 , V_99 ,
V_147 * 100. ) ;
else
V_116 ( V_129 , NULL , NULL , V_99 , 0 ) ;
} else if ( V_8 -> V_109 ) {
struct V_149 V_150 ;
int V_106 ;
F_43 ( & V_150 ) ;
F_44 ( & V_150 , V_8 -> V_99 , V_112 ) ;
for ( V_106 = 0 ; V_8 -> V_102 [ V_106 ] ; V_106 ++ ) {
struct V_3 * V_84 ;
V_84 = F_4 ( V_8 -> V_102 [ V_106 ] , V_7 , V_6 , false ) ;
if ( ! V_84 )
break;
F_44 ( & V_150 , V_8 -> V_102 [ V_106 ] -> V_99 ,
F_26 ( & V_84 -> V_55 ) ) ;
}
if ( ! V_8 -> V_102 [ V_106 ] ) {
const char * V_151 = V_8 -> V_109 ;
if ( F_45 ( & V_86 , & V_150 , & V_151 ) == 0 )
V_116 ( V_129 , NULL , L_37 ,
V_8 -> V_152 ?
V_8 -> V_152 :
V_114 -> V_153 ? V_8 -> V_99 : L_38 ,
V_86 ) ;
else
V_116 ( V_129 , NULL , NULL , L_38 , 0 ) ;
} else
V_116 ( V_129 , NULL , NULL , L_38 , 0 ) ;
} else if ( V_32 [ V_7 ] . V_134 != 0 ) {
char V_154 = 'M' ;
char V_155 [ 10 ] ;
V_115 = F_26 ( & V_32 [ V_7 ] ) ;
if ( V_115 )
V_86 = 1000.0 * V_112 / V_115 ;
if ( V_86 < 0.001 ) {
V_86 *= 1000 ;
V_154 = 'K' ;
}
snprintf ( V_155 , sizeof( V_155 ) , L_39 , V_154 ) ;
V_116 ( V_129 , NULL , L_22 , V_155 , V_86 ) ;
} else if ( F_17 ( V_8 , V_81 ) ) {
F_40 ( V_7 , V_8 , V_114 ) ;
} else {
V_116 ( V_129 , NULL , NULL , NULL , 0 ) ;
}
}
