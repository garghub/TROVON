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
return V_4 -> V_8 - V_5 -> V_8 ;
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
V_31 = F_12 ( & V_15 . V_52 ) ;
while ( V_31 ) {
V_30 = V_31 ;
V_31 = F_13 ( V_30 ) ;
memset ( & F_2 ( V_30 , struct V_3 , V_1 ) -> V_53 ,
0 ,
sizeof( struct V_53 ) ) ;
}
}
void F_14 ( struct V_12 * V_54 , T_1 * V_55 ,
int V_7 )
{
int V_6 = F_10 ( V_54 ) ;
if ( F_15 ( V_54 , V_56 , V_57 ) ||
F_15 ( V_54 , V_56 , V_58 ) )
F_16 ( & V_32 [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_59 , V_60 ) )
F_16 ( & V_33 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_61 ) )
F_16 ( & V_43 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_62 ) )
F_16 ( & V_44 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_63 ) )
F_16 ( & V_45 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_64 ) )
F_16 ( & V_47 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_65 ) )
F_16 ( & V_49 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_66 ) )
F_16 ( & V_48 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_67 ) )
F_16 ( & V_50 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_17 ( V_54 , V_68 ) )
F_16 ( & V_51 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_59 , V_69 ) )
F_16 ( & V_34 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_59 , V_70 ) )
F_16 ( & V_35 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_59 , V_71 ) )
F_16 ( & V_36 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_59 , V_72 ) )
F_16 ( & V_37 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_73 , V_74 ) )
F_16 ( & V_38 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_73 , V_75 ) )
F_16 ( & V_40 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_73 , V_76 ) )
F_16 ( & V_40 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_73 , V_77 ) )
F_16 ( & V_42 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
else if ( F_15 ( V_54 , V_73 , V_78 ) )
F_16 ( & V_41 [ V_6 ] [ V_7 ] , V_55 [ 0 ] ) ;
if ( V_54 -> V_79 ) {
struct V_3 * V_80 = F_4 ( V_54 , V_7 , V_6 ,
true ) ;
F_16 ( & V_80 -> V_53 , V_55 [ 0 ] ) ;
}
}
static const char * F_18 ( enum V_81 type , double V_82 )
{
static const double V_83 [ V_84 ] [ 3 ] = {
[ V_85 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_86 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_87 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_88 = V_89 ;
if ( V_82 > V_83 [ type ] [ 0 ] )
V_88 = V_90 ;
else if ( V_82 > V_83 [ type ] [ 1 ] )
V_88 = V_91 ;
else if ( V_82 > V_83 [ type ] [ 2 ] )
V_88 = V_92 ;
return V_88 ;
}
static struct V_12 * F_19 ( struct V_93 * V_94 ,
const char * V_95 )
{
struct V_12 * V_96 ;
F_20 (evsel_list, c2) {
if ( ! strcasecmp ( V_96 -> V_95 , V_95 ) )
return V_96 ;
}
return NULL ;
}
void F_21 ( struct V_93 * V_94 )
{
struct V_12 * V_54 , * V_97 , * * V_98 , * V_99 ;
bool V_100 ;
const char * * V_101 ;
int V_102 ;
int V_103 ;
F_20 (evsel_list, counter) {
bool V_104 = false ;
V_97 = V_54 -> V_97 ;
if ( ! V_54 -> V_105 )
continue;
V_98 = V_54 -> V_98 ;
if ( ! V_98 ) {
if ( F_22 ( V_54 -> V_105 , V_54 -> V_95 ,
& V_101 , & V_103 ) < 0 )
continue;
V_98 = calloc ( sizeof( struct V_12 * ) ,
V_103 + 1 ) ;
if ( ! V_98 )
return;
V_54 -> V_98 = V_98 ;
}
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
V_100 = false ;
if ( V_97 ) {
F_23 (oc, leader) {
if ( ! strcasecmp ( V_99 -> V_95 , V_101 [ V_102 ] ) ) {
V_100 = true ;
break;
}
}
}
if ( ! V_100 ) {
V_99 = F_19 ( V_94 , V_101 [ V_102 ] ) ;
}
if ( ! V_99 ) {
static char * V_106 ;
if ( ! V_106 || strcasecmp ( V_106 , V_101 [ V_102 ] ) ) {
fprintf ( V_107 ,
L_3 ,
V_101 [ V_102 ] ,
V_54 -> V_95 ) ;
V_106 = F_24 ( V_101 [ V_102 ] ) ;
}
V_104 = true ;
continue;
}
V_98 [ V_102 ] = V_99 ;
V_99 -> V_79 = true ;
}
V_98 [ V_102 ] = NULL ;
free ( V_101 ) ;
if ( V_104 ) {
free ( V_98 ) ;
V_54 -> V_98 = NULL ;
V_54 -> V_105 = NULL ;
}
}
}
static void F_25 ( int V_7 ,
struct V_12 * V_8 , double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_85 , V_82 ) ;
if ( V_82 )
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_5 ,
V_82 ) ;
else
V_110 -> V_112 ( V_110 -> V_6 , NULL , NULL , L_5 , 0 ) ;
}
static void F_27 ( int V_7 ,
struct V_12 * V_8 , double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_86 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_6 , V_82 ) ;
}
static void F_28 ( int V_7 ,
struct V_12 * V_8 ,
double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_36 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_87 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_7 , V_82 ) ;
}
static void F_29 ( int V_7 ,
struct V_12 * V_8 ,
double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_38 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_87 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_8 , V_82 ) ;
}
static void F_30 ( int V_7 ,
struct V_12 * V_8 ,
double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_39 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_87 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_9 , V_82 ) ;
}
static void F_31 ( int V_7 ,
struct V_12 * V_8 ,
double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_42 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_87 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_10 , V_82 ) ;
}
static void F_32 ( int V_7 ,
struct V_12 * V_8 ,
double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_41 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_87 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_11 , V_82 ) ;
}
static void F_33 ( int V_7 ,
struct V_12 * V_8 ,
double V_108 ,
struct V_109 * V_110 )
{
double V_111 , V_82 = 0.0 ;
const char * V_88 ;
int V_6 = F_10 ( V_8 ) ;
V_111 = F_26 ( & V_40 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 / V_111 * 100.0 ;
V_88 = F_18 ( V_87 , V_82 ) ;
V_110 -> V_112 ( V_110 -> V_6 , V_88 , L_4 , L_12 , V_82 ) ;
}
static double F_34 ( double V_113 )
{
if ( V_113 < 0 && V_113 >= - 0.02 )
return 0.0 ;
return V_113 ;
}
static double F_35 ( int V_6 , int V_7 )
{
return F_26 ( & V_47 [ V_6 ] [ V_7 ] ) ;
}
static double F_36 ( int V_6 , int V_7 )
{
double V_114 = 0 ;
double V_115 ;
double V_111 ;
V_111 = F_26 ( & V_49 [ V_6 ] [ V_7 ] ) -
F_26 ( & V_48 [ V_6 ] [ V_7 ] ) +
F_26 ( & V_51 [ V_6 ] [ V_7 ] ) ;
V_115 = F_35 ( V_6 , V_7 ) ;
if ( V_115 )
V_114 = V_111 / V_115 ;
return F_34 ( V_114 ) ;
}
static double F_37 ( int V_6 , int V_7 )
{
double V_116 = 0 ;
double V_115 = F_35 ( V_6 , V_7 ) ;
double V_117 = F_26 ( & V_48 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_116 = V_117 / V_115 ;
return V_116 ;
}
static double F_38 ( int V_6 , int V_7 )
{
double V_118 = 0 ;
double V_115 = F_35 ( V_6 , V_7 ) ;
double V_119 = F_26 ( & V_50 [ V_6 ] [ V_7 ] ) ;
if ( V_115 )
V_118 = V_119 / V_115 ;
return V_118 ;
}
static double F_39 ( int V_6 , int V_7 )
{
double V_120 = ( F_38 ( V_6 , V_7 ) +
F_36 ( V_6 , V_7 ) +
F_37 ( V_6 , V_7 ) ) ;
if ( V_120 == 0 )
return 0 ;
return F_34 ( 1.0 - V_120 ) ;
}
void F_40 ( struct V_12 * V_8 ,
double V_108 , int V_7 ,
struct V_109 * V_110 )
{
void * V_121 = V_110 -> V_6 ;
T_2 V_112 = V_110 -> V_112 ;
double V_111 , V_82 = 0.0 , V_122 ;
const char * V_88 = NULL ;
int V_6 = F_10 ( V_8 ) ;
if ( F_15 ( V_8 , V_59 , V_123 ) ) {
V_111 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_111 ) {
V_82 = V_108 / V_111 ;
V_112 ( V_121 , NULL , L_13 ,
L_14 , V_82 ) ;
} else {
V_112 ( V_121 , NULL , NULL , L_14 , 0 ) ;
}
V_111 = F_26 ( & V_34 [ V_6 ] [ V_7 ] ) ;
V_111 = F_41 ( V_111 , F_26 ( & V_35 [ V_6 ] [ V_7 ] ) ) ;
if ( V_111 && V_108 ) {
V_110 -> V_124 ( V_121 ) ;
V_82 = V_111 / V_108 ;
V_112 ( V_121 , NULL , L_13 ,
L_15 ,
V_82 ) ;
} else if ( V_16 ) {
V_112 ( V_121 , NULL , NULL ,
L_15 , 0 ) ;
}
} else if ( F_15 ( V_8 , V_59 , V_125 ) ) {
if ( V_36 [ V_6 ] [ V_7 ] . V_126 != 0 )
F_28 ( V_7 , V_8 , V_108 , V_110 ) ;
else
V_112 ( V_121 , NULL , NULL , L_7 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_127 &&
V_8 -> V_19 . V_128 == ( V_129 |
( ( V_130 ) << 8 ) |
( ( V_131 ) << 16 ) ) ) {
if ( V_38 [ V_6 ] [ V_7 ] . V_126 != 0 )
F_29 ( V_7 , V_8 , V_108 , V_110 ) ;
else
V_112 ( V_121 , NULL , NULL , L_8 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_127 &&
V_8 -> V_19 . V_128 == ( V_132 |
( ( V_130 ) << 8 ) |
( ( V_131 ) << 16 ) ) ) {
if ( V_39 [ V_6 ] [ V_7 ] . V_126 != 0 )
F_30 ( V_7 , V_8 , V_108 , V_110 ) ;
else
V_112 ( V_121 , NULL , NULL , L_9 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_127 &&
V_8 -> V_19 . V_128 == ( V_133 |
( ( V_130 ) << 8 ) |
( ( V_131 ) << 16 ) ) ) {
if ( V_42 [ V_6 ] [ V_7 ] . V_126 != 0 )
F_31 ( V_7 , V_8 , V_108 , V_110 ) ;
else
V_112 ( V_121 , NULL , NULL , L_10 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_127 &&
V_8 -> V_19 . V_128 == ( V_134 |
( ( V_130 ) << 8 ) |
( ( V_131 ) << 16 ) ) ) {
if ( V_41 [ V_6 ] [ V_7 ] . V_126 != 0 )
F_32 ( V_7 , V_8 , V_108 , V_110 ) ;
else
V_112 ( V_121 , NULL , NULL , L_11 , 0 ) ;
} else if (
V_8 -> V_19 . type == V_127 &&
V_8 -> V_19 . V_128 == ( V_135 |
( ( V_130 ) << 8 ) |
( ( V_131 ) << 16 ) ) ) {
if ( V_40 [ V_6 ] [ V_7 ] . V_126 != 0 )
F_33 ( V_7 , V_8 , V_108 , V_110 ) ;
else
V_112 ( V_121 , NULL , NULL , L_12 , 0 ) ;
} else if ( F_15 ( V_8 , V_59 , V_136 ) ) {
V_111 = F_26 ( & V_37 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_82 = V_108 * 100 / V_111 ;
if ( V_37 [ V_6 ] [ V_7 ] . V_126 != 0 )
V_112 ( V_121 , NULL , L_16 ,
L_17 , V_82 ) ;
else
V_112 ( V_121 , NULL , NULL , L_17 , 0 ) ;
} else if ( F_15 ( V_8 , V_59 , V_69 ) ) {
F_25 ( V_7 , V_8 , V_108 , V_110 ) ;
} else if ( F_15 ( V_8 , V_59 , V_70 ) ) {
F_27 ( V_7 , V_8 , V_108 , V_110 ) ;
} else if ( F_15 ( V_8 , V_59 , V_60 ) ) {
V_111 = F_26 ( & V_32 [ V_7 ] ) ;
if ( V_111 ) {
V_82 = V_108 / V_111 ;
V_112 ( V_121 , NULL , L_18 , L_19 , V_82 ) ;
} else {
V_112 ( V_121 , NULL , NULL , L_20 , 0 ) ;
}
} else if ( F_17 ( V_8 , V_61 ) ) {
V_111 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
if ( V_111 )
V_112 ( V_121 , NULL ,
L_4 , L_21 ,
100.0 * ( V_108 / V_111 ) ) ;
else
V_112 ( V_121 , NULL , NULL , L_21 ,
0 ) ;
} else if ( F_17 ( V_8 , V_137 ) ) {
V_111 = F_26 ( & V_33 [ V_6 ] [ V_7 ] ) ;
V_122 = F_26 ( & V_43 [ V_6 ] [ V_7 ] ) ;
if ( V_122 < V_108 )
V_122 = V_108 ;
if ( V_111 )
V_112 ( V_121 , NULL , L_4 , L_22 ,
100.0 * ( ( V_122 - V_108 ) / V_111 ) ) ;
else
V_112 ( V_121 , NULL , NULL , L_22 , 0 ) ;
} else if ( F_17 ( V_8 , V_62 ) ) {
V_111 = F_26 ( & V_43 [ V_6 ] [ V_7 ] ) ;
if ( V_108 )
V_82 = V_111 / V_108 ;
if ( V_43 [ V_6 ] [ V_7 ] . V_126 != 0 )
V_112 ( V_121 , NULL , L_23 ,
L_24 , V_82 ) ;
else
V_112 ( V_121 , NULL , NULL , L_24 ,
0 ) ;
} else if ( F_17 ( V_8 , V_63 ) ) {
V_111 = F_26 ( & V_43 [ V_6 ] [ V_7 ] ) ;
if ( V_108 )
V_82 = V_111 / V_108 ;
V_112 ( V_121 , NULL , L_23 , L_25 , V_82 ) ;
} else if ( F_15 ( V_8 , V_56 , V_57 ) ||
F_15 ( V_8 , V_56 , V_58 ) ) {
if ( ( V_82 = F_26 ( & V_46 ) ) != 0 )
V_112 ( V_121 , NULL , L_18 , L_26 ,
V_108 / V_82 ) ;
else
V_112 ( V_121 , NULL , NULL , L_26 , 0 ) ;
} else if ( F_17 ( V_8 , V_67 ) ) {
double V_118 = F_38 ( V_6 , V_7 ) ;
if ( V_118 > 0.2 )
V_88 = V_90 ;
V_112 ( V_121 , V_88 , L_27 , L_28 ,
V_118 * 100. ) ;
} else if ( F_17 ( V_8 , V_66 ) ) {
double V_116 = F_37 ( V_6 , V_7 ) ;
if ( V_116 > 0.7 )
V_88 = V_138 ;
V_112 ( V_121 , V_88 , L_27 , L_29 ,
V_116 * 100. ) ;
} else if ( F_17 ( V_8 , V_68 ) ) {
double V_114 = F_36 ( V_6 , V_7 ) ;
if ( V_114 > 0.1 )
V_88 = V_90 ;
V_112 ( V_121 , V_88 , L_27 , L_30 ,
V_114 * 100. ) ;
} else if ( F_17 ( V_8 , V_65 ) ) {
double V_139 = F_39 ( V_6 , V_7 ) ;
const char * V_95 = L_31 ;
static int V_140 = - 1 ;
if ( V_140 < 0 )
V_140 = F_8 ( L_1 ,
L_32 ) ;
if ( ! V_140 )
V_95 = L_33 ;
if ( V_139 > 0.2 )
V_88 = V_90 ;
if ( F_35 ( V_6 , V_7 ) > 0 )
V_112 ( V_121 , V_88 , L_27 , V_95 ,
V_139 * 100. ) ;
else
V_112 ( V_121 , NULL , NULL , V_95 , 0 ) ;
} else if ( V_8 -> V_105 ) {
struct V_141 V_142 ;
int V_102 ;
F_42 ( & V_142 ) ;
F_43 ( & V_142 , V_8 -> V_95 , V_108 ) ;
for ( V_102 = 0 ; V_8 -> V_98 [ V_102 ] ; V_102 ++ ) {
struct V_3 * V_80 ;
V_80 = F_4 ( V_8 -> V_98 [ V_102 ] , V_7 , V_6 , false ) ;
if ( ! V_80 )
break;
F_43 ( & V_142 , V_8 -> V_98 [ V_102 ] -> V_95 ,
F_26 ( & V_80 -> V_53 ) ) ;
}
if ( ! V_8 -> V_98 [ V_102 ] ) {
const char * V_143 = V_8 -> V_105 ;
if ( F_44 ( & V_82 , & V_142 , & V_143 ) == 0 )
V_112 ( V_121 , NULL , L_34 ,
V_8 -> V_144 ?
V_8 -> V_144 :
V_110 -> V_145 ? V_8 -> V_95 : L_35 ,
V_82 ) ;
else
V_112 ( V_121 , NULL , NULL , L_35 , 0 ) ;
} else
V_112 ( V_121 , NULL , NULL , L_35 , 0 ) ;
} else if ( V_32 [ V_7 ] . V_126 != 0 ) {
char V_146 = 'M' ;
char V_147 [ 10 ] ;
V_111 = F_26 ( & V_32 [ V_7 ] ) ;
if ( V_111 )
V_82 = 1000.0 * V_108 / V_111 ;
if ( V_82 < 0.001 ) {
V_82 *= 1000 ;
V_146 = 'K' ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_36 , V_146 ) ;
V_112 ( V_121 , NULL , L_18 , V_147 , V_82 ) ;
} else {
V_112 ( V_121 , NULL , NULL , NULL , 0 ) ;
}
}
