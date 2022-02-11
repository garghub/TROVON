static void F_1 ( const char * V_1 , struct V_2 * V_3 ,
T_1 V_4 , int V_5 )
{
if ( ! ( V_3 -> V_6 | V_3 -> V_7 ) )
return;
fprintf ( V_8 , L_1 ,
V_1 , V_3 -> V_6 , V_3 -> V_7 / 1000 ,
V_4 , V_5 ) ;
if ( ( V_9 . V_6 | V_9 . V_7 ) ) {
T_2 V_10 , V_11 ;
V_10 = ( long ) V_3 -> V_6 * 1000 * 1000 ;
V_10 += V_3 -> V_7 / 1000 ;
V_11 = ( long ) V_9 . V_6 * 1000 * 1000 ;
V_11 += V_9 . V_7 / 1000 ;
fprintf ( V_8 , L_2 , V_10 - V_11 ) ;
}
V_9 = * V_3 ;
fprintf ( V_8 , L_3 ) ;
}
static void F_2 ( void )
{
struct V_2 V_12 ;
struct V_13 V_14 ;
F_3 ( & V_14 , NULL ) ;
V_12 . V_6 = V_14 . V_6 ;
V_12 . V_7 = V_14 . V_15 * 1000 ;
F_1 ( L_4 , & V_12 , 0 , 0 ) ;
}
static void F_4 ( struct V_16 * V_17 , int V_18 ,
int V_19 , int V_5 )
{
const char * V_20 ;
switch ( V_18 ) {
case V_21 :
V_20 = L_5 ;
break;
case V_22 :
V_20 = L_6 ;
break;
case V_23 :
V_20 = L_7 ;
break;
default:
error ( 1 , 0 , L_8 ,
V_18 ) ;
}
F_1 ( V_20 , & V_17 -> V_12 [ 0 ] , V_19 , V_5 ) ;
}
static void F_5 ( char * V_24 , int V_25 )
{
int V_26 ;
if ( V_25 > 70 )
V_25 = 70 ;
fprintf ( V_8 , L_9 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ )
fprintf ( V_8 , L_10 , V_24 [ V_26 ] ) ;
fprintf ( V_8 , L_3 ) ;
}
static void F_6 ( int V_27 , int V_28 , void * V_29 , void * V_30 )
{
char V_31 [ V_32 ] , V_33 [ V_32 ] ;
fprintf ( V_8 , L_11 ,
V_28 ,
V_29 ? F_7 ( V_27 , V_29 , V_31 , sizeof( V_31 ) ) : L_12 ,
V_30 ? F_7 ( V_27 , V_30 , V_33 , sizeof( V_33 ) ) : L_12 ) ;
}
static void F_8 ( int V_34 )
{
struct V_35 V_35 ;
int V_36 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_34 = V_34 ;
V_36 = F_9 ( & V_35 , 1 , 100 ) ;
if ( V_36 != 1 )
error ( 1 , V_37 , L_13 ) ;
}
static void F_10 ( struct V_38 * V_39 , int V_5 )
{
struct V_40 * V_41 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_42 * V_43 ;
for ( V_43 = F_11 ( V_39 ) ;
V_43 && V_43 -> V_44 ;
V_43 = F_12 ( V_39 , V_43 ) ) {
if ( V_43 -> V_45 == V_46 &&
V_43 -> V_47 == V_48 ) {
V_17 = ( void * ) F_13 ( V_43 ) ;
} else if ( ( V_43 -> V_45 == V_49 &&
V_43 -> V_47 == V_50 ) ||
( V_43 -> V_45 == V_51 &&
V_43 -> V_47 == V_52 ) ) {
V_41 = ( void * ) F_13 ( V_43 ) ;
if ( V_41 -> V_53 != V_54 ||
V_41 -> V_55 != V_56 ) {
fprintf ( V_8 , L_14 ,
V_41 -> V_53 ,
V_41 -> V_55 ) ;
V_41 = NULL ;
}
} else if ( V_43 -> V_45 == V_49 &&
V_43 -> V_47 == V_57 ) {
struct V_58 * V_59 = ( void * ) F_13 ( V_43 ) ;
F_6 ( V_60 , V_59 -> V_61 ,
& V_59 -> V_62 , & V_59 -> V_63 ) ;
} else if ( V_43 -> V_45 == V_51 &&
V_43 -> V_47 == V_64 ) {
struct V_65 * V_66 = ( void * ) F_13 ( V_43 ) ;
F_6 ( V_67 , V_66 -> V_68 ,
NULL , & V_66 -> V_69 ) ;
} else
fprintf ( V_8 , L_15 ,
V_43 -> V_45 , V_43 -> V_47 ) ;
}
if ( V_41 && V_17 )
F_4 ( V_17 , V_41 -> V_70 , V_41 -> V_71 , V_5 ) ;
}
static int F_14 ( int V_34 )
{
static char V_72 [ 1024 ] ;
static struct V_38 V_39 ;
struct V_73 V_74 ;
static char * V_24 ;
int V_36 = 0 ;
V_24 = malloc ( V_75 ) ;
if ( ! V_24 )
error ( 1 , 0 , L_16 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
V_74 . V_76 = V_24 ;
V_74 . V_77 = V_75 ;
V_39 . V_78 = & V_74 ;
V_39 . V_79 = 1 ;
V_39 . V_80 = NULL ;
V_39 . V_81 = 0 ;
V_39 . V_82 = V_72 ;
V_39 . V_83 = sizeof( V_72 ) ;
V_36 = F_15 ( V_34 , & V_39 , V_84 ) ;
if ( V_36 == - 1 && V_37 != V_85 )
error ( 1 , V_37 , L_17 ) ;
if ( V_36 > 0 ) {
F_10 ( & V_39 , V_36 ) ;
if ( V_86 )
F_5 ( V_24 , V_75 ) ;
}
free ( V_24 ) ;
return V_36 == - 1 ;
}
static void F_16 ( int V_27 , unsigned int V_87 )
{
char * V_88 ;
int V_34 , V_26 , V_89 = 1 , V_90 ;
if ( V_27 == V_67 && V_91 != V_92 ) {
fprintf ( V_8 , L_18 ) ;
return;
}
V_90 = V_75 ;
if ( V_91 == V_93 ) {
V_90 += sizeof( struct V_94 ) ;
if ( V_95 == V_96 )
V_90 += sizeof( struct V_97 ) ;
}
V_88 = malloc ( V_90 ) ;
if ( ! V_88 )
error ( 1 , 0 , L_16 ) ;
V_34 = F_17 ( V_27 , V_91 , V_95 ) ;
if ( V_34 < 0 )
error ( 1 , V_37 , L_19 ) ;
if ( V_91 == V_92 ) {
if ( F_18 ( V_34 , V_98 , V_99 ,
( char * ) & V_89 , sizeof( V_89 ) ) )
error ( 1 , 0 , L_20 ) ;
if ( V_27 == V_100 ) {
if ( F_19 ( V_34 , ( void * ) & V_30 , sizeof( V_30 ) ) )
error ( 1 , V_37 , L_21 ) ;
} else {
if ( F_19 ( V_34 , ( void * ) & V_101 , sizeof( V_101 ) ) )
error ( 1 , V_37 , L_22 ) ;
}
}
if ( V_102 ) {
if ( V_27 == V_67 ) {
if ( F_18 ( V_34 , V_51 , V_103 ,
& V_89 , sizeof( V_89 ) ) )
error ( 1 , V_37 , L_23 ) ;
} else {
if ( F_18 ( V_34 , V_49 , V_57 ,
& V_89 , sizeof( V_89 ) ) )
error ( 1 , V_37 , L_24 ) ;
}
}
V_87 |= V_104 |
V_105 |
V_106 ;
if ( F_18 ( V_34 , V_46 , V_107 ,
( char * ) & V_87 , sizeof( V_87 ) ) )
error ( 1 , 0 , L_25 ) ;
for ( V_26 = 0 ; V_26 < V_108 ; V_26 ++ ) {
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
memset ( V_88 , 'a' + V_26 , V_90 ) ;
if ( V_91 == V_93 ) {
struct V_94 * V_109 ;
int V_110 = 0 ;
if ( V_95 == V_96 ) {
struct V_97 * V_111 = ( void * ) V_88 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_112 = 5 ;
V_111 -> V_113 = 4 ;
V_111 -> V_114 = 2 ;
V_111 -> V_30 = V_30 . V_115 . V_116 ;
V_111 -> V_117 = V_118 ;
V_110 = sizeof( * V_111 ) ;
}
V_109 = ( void * ) V_88 + V_110 ;
V_109 -> V_119 = F_20 ( 9000 ) ;
V_109 -> V_120 = F_20 ( V_121 ) ;
V_109 -> V_25 = F_20 ( sizeof( * V_109 ) + V_75 ) ;
V_109 -> V_122 = 0 ;
}
F_2 () ;
if ( V_91 != V_92 ) {
if ( V_27 == V_100 )
V_89 = F_21 ( V_34 , V_88 , V_90 , 0 , ( void * ) & V_30 , sizeof( V_30 ) ) ;
else
V_89 = F_21 ( V_34 , V_88 , V_90 , 0 , ( void * ) & V_101 , sizeof( V_101 ) ) ;
} else {
V_89 = F_22 ( V_34 , V_88 , V_75 , 0 ) ;
}
if ( V_89 != V_90 )
error ( 1 , V_37 , L_26 ) ;
F_23 ( 50 * 1000 ) ;
F_8 ( V_34 ) ;
while ( ! F_14 ( V_34 ) ) {}
}
if ( F_24 ( V_34 ) )
error ( 1 , V_37 , L_27 ) ;
free ( V_88 ) ;
F_23 ( 400 * 1000 ) ;
}
static void F_25 ( int V_123 , char * * V_124 )
{
int V_125 = 0 ;
char V_126 ;
while ( ( V_126 = F_26 ( V_123 , V_124 , L_28 ) ) != - 1 ) {
switch ( V_126 ) {
case '4' :
V_127 = 0 ;
break;
case '6' :
V_128 = 0 ;
break;
case 'I' :
V_102 = true ;
break;
case 'r' :
V_125 ++ ;
V_91 = V_93 ;
V_95 = V_118 ;
break;
case 'R' :
V_125 ++ ;
V_91 = V_93 ;
V_95 = V_96 ;
break;
case 'u' :
V_125 ++ ;
V_91 = V_129 ;
V_95 = V_118 ;
break;
case 'l' :
V_75 = strtoul ( V_130 , NULL , 10 ) ;
break;
case 'p' :
V_121 = strtoul ( V_130 , NULL , 10 ) ;
break;
case 'x' :
V_86 = true ;
break;
case 'h' :
default:
F_27 ( V_124 [ 0 ] ) ;
}
}
if ( ! V_75 )
error ( 1 , 0 , L_29 ) ;
if ( V_91 != V_92 && V_75 > 1472 )
error ( 1 , 0 , L_30 ) ;
if ( ! V_128 && ! V_127 )
error ( 1 , 0 , L_31 ) ;
if ( V_125 > 1 )
error ( 1 , 0 , L_32 ) ;
if ( V_131 != V_123 - 1 )
error ( 1 , 0 , L_33 ) ;
}
static void F_28 ( const char * V_132 )
{
struct V_133 * V_134 , * V_3 ;
int V_135 = 0 , V_136 = 0 ;
if ( F_29 ( V_132 , NULL , NULL , & V_134 ) )
error ( 1 , V_37 , L_34 ) ;
V_3 = V_134 ;
while ( V_3 && ! V_135 && ! V_136 ) {
if ( ! V_135 && V_3 -> V_137 == V_60 ) {
memcpy ( & V_30 , V_3 -> V_138 , sizeof( V_30 ) ) ;
V_30 . V_139 = F_30 ( V_121 ) ;
V_135 = 1 ;
}
else if ( ! V_136 && V_3 -> V_137 == V_67 ) {
memcpy ( & V_101 , V_3 -> V_138 , sizeof( V_101 ) ) ;
V_101 . V_140 = F_30 ( V_121 ) ;
V_136 = 1 ;
}
V_3 = V_3 -> V_141 ;
}
if ( V_134 )
F_31 ( V_134 ) ;
V_128 &= V_135 ;
V_127 &= V_136 ;
}
static void F_32 ( int V_27 )
{
fprintf ( V_8 , L_35 ,
V_27 == V_100 ? L_36 : L_37 ) ;
fprintf ( V_8 , L_38 ) ;
F_16 ( V_27 , V_142 ) ;
fprintf ( V_8 , L_39 ) ;
F_16 ( V_27 , V_143 ) ;
fprintf ( V_8 , L_40 ) ;
F_16 ( V_27 , V_143 |
V_142 ) ;
if ( V_91 == V_92 ) {
fprintf ( V_8 , L_41 ) ;
F_16 ( V_27 , V_144 ) ;
fprintf ( V_8 , L_42 ) ;
F_16 ( V_27 , V_142 |
V_144 ) ;
fprintf ( V_8 , L_43 ) ;
F_16 ( V_27 , V_143 |
V_142 |
V_144 ) ;
}
}
int main ( int V_123 , char * * V_124 )
{
if ( V_123 == 1 )
F_27 ( V_124 [ 0 ] ) ;
F_25 ( V_123 , V_124 ) ;
F_28 ( V_124 [ V_123 - 1 ] ) ;
fprintf ( V_8 , L_44 , V_145 [ V_91 ] ) ;
fprintf ( V_8 , L_45 , V_75 ) ;
fprintf ( V_8 , L_46 , V_121 ) ;
fprintf ( V_8 , L_3 ) ;
if ( V_128 )
F_32 ( V_100 ) ;
if ( V_127 )
F_32 ( V_146 ) ;
return 0 ;
}
