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
if ( ! V_25 )
return;
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
int V_44 = 0 ;
for ( V_43 = F_11 ( V_39 ) ;
V_43 && V_43 -> V_45 ;
V_43 = F_12 ( V_39 , V_43 ) ) {
if ( V_43 -> V_46 == V_47 &&
V_43 -> V_48 == V_49 ) {
V_17 = ( void * ) F_13 ( V_43 ) ;
} else if ( ( V_43 -> V_46 == V_50 &&
V_43 -> V_48 == V_51 ) ||
( V_43 -> V_46 == V_52 &&
V_43 -> V_48 == V_53 ) ) {
V_41 = ( void * ) F_13 ( V_43 ) ;
if ( V_41 -> V_54 != V_55 ||
V_41 -> V_56 != V_57 ) {
fprintf ( V_8 , L_14 ,
V_41 -> V_54 ,
V_41 -> V_56 ) ;
V_41 = NULL ;
}
} else if ( V_43 -> V_46 == V_50 &&
V_43 -> V_48 == V_58 ) {
struct V_59 * V_60 = ( void * ) F_13 ( V_43 ) ;
F_6 ( V_61 , V_60 -> V_62 ,
& V_60 -> V_63 , & V_60 -> V_64 ) ;
} else if ( V_43 -> V_46 == V_52 &&
V_43 -> V_48 == V_65 ) {
struct V_66 * V_67 = ( void * ) F_13 ( V_43 ) ;
F_6 ( V_68 , V_67 -> V_69 ,
NULL , & V_67 -> V_70 ) ;
} else
fprintf ( V_8 , L_15 ,
V_43 -> V_46 , V_43 -> V_48 ) ;
if ( V_41 && V_17 ) {
F_4 ( V_17 , V_41 -> V_71 , V_41 -> V_72 ,
V_5 ) ;
V_41 = NULL ;
V_17 = NULL ;
V_44 ++ ;
}
}
if ( V_44 > 1 )
fprintf ( V_8 , L_16 , V_44 ) ;
}
static int F_14 ( int V_34 )
{
static char V_73 [ 1024 ] ;
static struct V_38 V_39 ;
struct V_74 V_75 ;
static char * V_24 ;
int V_36 = 0 ;
V_24 = malloc ( V_76 ) ;
if ( ! V_24 )
error ( 1 , 0 , L_17 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
V_75 . V_77 = V_24 ;
V_75 . V_78 = V_76 ;
V_39 . V_79 = & V_75 ;
V_39 . V_80 = 1 ;
V_39 . V_81 = NULL ;
V_39 . V_82 = 0 ;
V_39 . V_83 = V_73 ;
V_39 . V_84 = sizeof( V_73 ) ;
V_36 = F_15 ( V_34 , & V_39 , V_85 ) ;
if ( V_36 == - 1 && V_37 != V_86 )
error ( 1 , V_37 , L_18 ) ;
if ( V_36 >= 0 ) {
F_10 ( & V_39 , V_36 ) ;
if ( V_87 )
F_5 ( V_24 , V_76 ) ;
}
free ( V_24 ) ;
return V_36 == - 1 ;
}
static void F_16 ( int V_27 , unsigned int V_88 )
{
char * V_89 ;
int V_34 , V_26 , V_90 = 1 , V_91 ;
if ( V_27 == V_68 && V_92 != V_93 ) {
fprintf ( V_8 , L_19 ) ;
return;
}
V_91 = V_76 ;
if ( V_92 == V_94 ) {
V_91 += sizeof( struct V_95 ) ;
if ( V_96 == V_97 )
V_91 += sizeof( struct V_98 ) ;
}
V_89 = malloc ( V_91 ) ;
if ( ! V_89 )
error ( 1 , 0 , L_17 ) ;
V_34 = F_17 ( V_27 , V_92 , V_96 ) ;
if ( V_34 < 0 )
error ( 1 , V_37 , L_20 ) ;
if ( V_92 == V_93 ) {
if ( F_18 ( V_34 , V_99 , V_100 ,
( char * ) & V_90 , sizeof( V_90 ) ) )
error ( 1 , 0 , L_21 ) ;
if ( V_27 == V_101 ) {
if ( F_19 ( V_34 , ( void * ) & V_30 , sizeof( V_30 ) ) )
error ( 1 , V_37 , L_22 ) ;
} else {
if ( F_19 ( V_34 , ( void * ) & V_102 , sizeof( V_102 ) ) )
error ( 1 , V_37 , L_23 ) ;
}
}
if ( V_103 ) {
if ( V_27 == V_68 ) {
if ( F_18 ( V_34 , V_52 , V_104 ,
& V_90 , sizeof( V_90 ) ) )
error ( 1 , V_37 , L_24 ) ;
} else {
if ( F_18 ( V_34 , V_50 , V_58 ,
& V_90 , sizeof( V_90 ) ) )
error ( 1 , V_37 , L_25 ) ;
}
}
V_88 |= V_105 |
V_106 |
V_107 ;
if ( V_108 )
V_88 |= V_109 ;
if ( F_18 ( V_34 , V_47 , V_110 ,
( char * ) & V_88 , sizeof( V_88 ) ) )
error ( 1 , 0 , L_26 ) ;
for ( V_26 = 0 ; V_26 < V_111 ; V_26 ++ ) {
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
memset ( V_89 , 'a' + V_26 , V_91 ) ;
if ( V_92 == V_94 ) {
struct V_95 * V_112 ;
int V_113 = 0 ;
if ( V_96 == V_97 ) {
struct V_98 * V_114 = ( void * ) V_89 ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
V_114 -> V_115 = 5 ;
V_114 -> V_116 = 4 ;
V_114 -> V_117 = 2 ;
V_114 -> V_30 = V_30 . V_118 . V_119 ;
V_114 -> V_120 = V_121 ;
V_113 = sizeof( * V_114 ) ;
}
V_112 = ( void * ) V_89 + V_113 ;
V_112 -> V_122 = F_20 ( 9000 ) ;
V_112 -> V_123 = F_20 ( V_124 ) ;
V_112 -> V_25 = F_20 ( sizeof( * V_112 ) + V_76 ) ;
V_112 -> V_125 = 0 ;
}
F_2 () ;
if ( V_92 != V_93 ) {
if ( V_27 == V_101 )
V_90 = F_21 ( V_34 , V_89 , V_91 , 0 , ( void * ) & V_30 , sizeof( V_30 ) ) ;
else
V_90 = F_21 ( V_34 , V_89 , V_91 , 0 , ( void * ) & V_102 , sizeof( V_102 ) ) ;
} else {
V_90 = F_22 ( V_34 , V_89 , V_76 , 0 ) ;
}
if ( V_90 != V_91 )
error ( 1 , V_37 , L_27 ) ;
F_23 ( 50 * 1000 ) ;
F_8 ( V_34 ) ;
while ( ! F_14 ( V_34 ) ) {}
}
if ( F_24 ( V_34 ) )
error ( 1 , V_37 , L_28 ) ;
free ( V_89 ) ;
F_23 ( 400 * 1000 ) ;
}
static void F_25 ( int V_126 , char * * V_127 )
{
int V_128 = 0 ;
char V_129 ;
while ( ( V_129 = F_26 ( V_126 , V_127 , L_29 ) ) != - 1 ) {
switch ( V_129 ) {
case '4' :
V_130 = 0 ;
break;
case '6' :
V_131 = 0 ;
break;
case 'I' :
V_103 = true ;
break;
case 'n' :
V_108 = true ;
break;
case 'r' :
V_128 ++ ;
V_92 = V_94 ;
V_96 = V_121 ;
break;
case 'R' :
V_128 ++ ;
V_92 = V_94 ;
V_96 = V_97 ;
break;
case 'u' :
V_128 ++ ;
V_92 = V_132 ;
V_96 = V_121 ;
break;
case 'l' :
V_76 = strtoul ( V_133 , NULL , 10 ) ;
break;
case 'p' :
V_124 = strtoul ( V_133 , NULL , 10 ) ;
break;
case 'x' :
V_87 = true ;
break;
case 'h' :
default:
F_27 ( V_127 [ 0 ] ) ;
}
}
if ( ! V_76 )
error ( 1 , 0 , L_30 ) ;
if ( V_92 != V_93 && V_76 > 1472 )
error ( 1 , 0 , L_31 ) ;
if ( ! V_131 && ! V_130 )
error ( 1 , 0 , L_32 ) ;
if ( V_128 > 1 )
error ( 1 , 0 , L_33 ) ;
if ( V_134 != V_126 - 1 )
error ( 1 , 0 , L_34 ) ;
}
static void F_28 ( const char * V_135 )
{
struct V_136 * V_137 , * V_3 ;
int V_138 = 0 , V_139 = 0 ;
if ( F_29 ( V_135 , NULL , NULL , & V_137 ) )
error ( 1 , V_37 , L_35 ) ;
V_3 = V_137 ;
while ( V_3 && ! V_138 && ! V_139 ) {
if ( ! V_138 && V_3 -> V_140 == V_61 ) {
memcpy ( & V_30 , V_3 -> V_141 , sizeof( V_30 ) ) ;
V_30 . V_142 = F_30 ( V_124 ) ;
V_138 = 1 ;
}
else if ( ! V_139 && V_3 -> V_140 == V_68 ) {
memcpy ( & V_102 , V_3 -> V_141 , sizeof( V_102 ) ) ;
V_102 . V_143 = F_30 ( V_124 ) ;
V_139 = 1 ;
}
V_3 = V_3 -> V_144 ;
}
if ( V_137 )
F_31 ( V_137 ) ;
V_131 &= V_138 ;
V_130 &= V_139 ;
}
static void F_32 ( int V_27 )
{
fprintf ( V_8 , L_36 ,
V_27 == V_101 ? L_37 : L_38 ) ;
fprintf ( V_8 , L_39 ) ;
F_16 ( V_27 , V_145 ) ;
fprintf ( V_8 , L_40 ) ;
F_16 ( V_27 , V_146 ) ;
fprintf ( V_8 , L_41 ) ;
F_16 ( V_27 , V_146 |
V_145 ) ;
if ( V_92 == V_93 ) {
fprintf ( V_8 , L_42 ) ;
F_16 ( V_27 , V_147 ) ;
fprintf ( V_8 , L_43 ) ;
F_16 ( V_27 , V_145 |
V_147 ) ;
fprintf ( V_8 , L_44 ) ;
F_16 ( V_27 , V_146 |
V_145 |
V_147 ) ;
}
}
int main ( int V_126 , char * * V_127 )
{
if ( V_126 == 1 )
F_27 ( V_127 [ 0 ] ) ;
F_25 ( V_126 , V_127 ) ;
F_28 ( V_127 [ V_126 - 1 ] ) ;
fprintf ( V_8 , L_45 , V_148 [ V_92 ] ) ;
fprintf ( V_8 , L_46 , V_76 ) ;
fprintf ( V_8 , L_47 , V_124 ) ;
fprintf ( V_8 , L_3 ) ;
if ( V_131 )
F_32 ( V_101 ) ;
if ( V_130 )
F_32 ( V_149 ) ;
return 0 ;
}
