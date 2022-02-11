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
fprintf ( V_8 , L_2 V_12 L_3 , V_10 - V_11 ) ;
}
V_9 = * V_3 ;
fprintf ( V_8 , L_4 ) ;
}
static void F_2 ( void )
{
struct V_2 V_13 ;
struct V_14 V_15 ;
F_3 ( & V_15 , NULL ) ;
V_13 . V_6 = V_15 . V_6 ;
V_13 . V_7 = V_15 . V_16 * 1000 ;
F_1 ( L_5 , & V_13 , 0 , 0 ) ;
}
static void F_4 ( struct V_17 * V_18 , int V_19 ,
int V_20 , int V_5 )
{
const char * V_21 ;
switch ( V_19 ) {
case V_22 :
V_21 = L_6 ;
break;
case V_23 :
V_21 = L_7 ;
break;
case V_24 :
V_21 = L_8 ;
break;
default:
error ( 1 , 0 , L_9 ,
V_19 ) ;
}
F_1 ( V_21 , & V_18 -> V_13 [ 0 ] , V_20 , V_5 ) ;
}
static void F_5 ( char * V_25 , int V_26 )
{
int V_27 ;
if ( ! V_26 )
return;
if ( V_26 > 70 )
V_26 = 70 ;
fprintf ( V_8 , L_10 ) ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
fprintf ( V_8 , L_11 , V_25 [ V_27 ] ) ;
fprintf ( V_8 , L_4 ) ;
}
static void F_6 ( int V_28 , int V_29 , void * V_30 , void * V_31 )
{
char V_32 [ V_33 ] , V_34 [ V_33 ] ;
fprintf ( V_8 , L_12 ,
V_29 ,
V_30 ? F_7 ( V_28 , V_30 , V_32 , sizeof( V_32 ) ) : L_13 ,
V_31 ? F_7 ( V_28 , V_31 , V_34 , sizeof( V_34 ) ) : L_13 ) ;
}
static void F_8 ( int V_35 )
{
struct V_36 V_36 ;
int V_37 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_35 = V_35 ;
V_37 = F_9 ( & V_36 , 1 , 100 ) ;
if ( V_37 != 1 )
error ( 1 , V_38 , L_14 ) ;
}
static void F_10 ( struct V_39 * V_40 , int V_5 )
{
struct V_41 * V_42 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_43 * V_44 ;
int V_45 = 0 ;
for ( V_44 = F_11 ( V_40 ) ;
V_44 && V_44 -> V_46 ;
V_44 = F_12 ( V_40 , V_44 ) ) {
if ( V_44 -> V_47 == V_48 &&
V_44 -> V_49 == V_50 ) {
V_18 = ( void * ) F_13 ( V_44 ) ;
} else if ( ( V_44 -> V_47 == V_51 &&
V_44 -> V_49 == V_52 ) ||
( V_44 -> V_47 == V_53 &&
V_44 -> V_49 == V_54 ) ) {
V_42 = ( void * ) F_13 ( V_44 ) ;
if ( V_42 -> V_55 != V_56 ||
V_42 -> V_57 != V_58 ) {
fprintf ( V_8 , L_15 ,
V_42 -> V_55 ,
V_42 -> V_57 ) ;
V_42 = NULL ;
}
} else if ( V_44 -> V_47 == V_51 &&
V_44 -> V_49 == V_59 ) {
struct V_60 * V_61 = ( void * ) F_13 ( V_44 ) ;
F_6 ( V_62 , V_61 -> V_63 ,
& V_61 -> V_64 , & V_61 -> V_65 ) ;
} else if ( V_44 -> V_47 == V_53 &&
V_44 -> V_49 == V_66 ) {
struct V_67 * V_68 = ( void * ) F_13 ( V_44 ) ;
F_6 ( V_69 , V_68 -> V_70 ,
NULL , & V_68 -> V_71 ) ;
} else
fprintf ( V_8 , L_16 ,
V_44 -> V_47 , V_44 -> V_49 ) ;
if ( V_42 && V_18 ) {
F_4 ( V_18 , V_42 -> V_72 , V_42 -> V_73 ,
V_5 ) ;
V_42 = NULL ;
V_18 = NULL ;
V_45 ++ ;
}
}
if ( V_45 > 1 )
fprintf ( V_8 , L_17 , V_45 ) ;
}
static int F_14 ( int V_35 )
{
static char V_74 [ 1024 ] ;
static struct V_39 V_40 ;
struct V_75 V_76 ;
static char * V_25 ;
int V_37 = 0 ;
V_25 = malloc ( V_77 ) ;
if ( ! V_25 )
error ( 1 , 0 , L_18 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
V_76 . V_78 = V_25 ;
V_76 . V_79 = V_77 ;
V_40 . V_80 = & V_76 ;
V_40 . V_81 = 1 ;
V_40 . V_82 = NULL ;
V_40 . V_83 = 0 ;
V_40 . V_84 = V_74 ;
V_40 . V_85 = sizeof( V_74 ) ;
V_37 = F_15 ( V_35 , & V_40 , V_86 ) ;
if ( V_37 == - 1 && V_38 != V_87 )
error ( 1 , V_38 , L_19 ) ;
if ( V_37 >= 0 ) {
F_10 ( & V_40 , V_37 ) ;
if ( V_88 )
F_5 ( V_25 , V_77 ) ;
}
free ( V_25 ) ;
return V_37 == - 1 ;
}
static void F_16 ( int V_28 , unsigned int V_89 )
{
char * V_90 ;
int V_35 , V_27 , V_91 = 1 , V_92 ;
if ( V_28 == V_69 && V_93 != V_94 ) {
fprintf ( V_8 , L_20 ) ;
return;
}
V_92 = V_77 ;
if ( V_93 == V_95 ) {
V_92 += sizeof( struct V_96 ) ;
if ( V_97 == V_98 )
V_92 += sizeof( struct V_99 ) ;
}
V_90 = malloc ( V_92 ) ;
if ( ! V_90 )
error ( 1 , 0 , L_18 ) ;
V_35 = F_17 ( V_28 , V_93 , V_97 ) ;
if ( V_35 < 0 )
error ( 1 , V_38 , L_21 ) ;
if ( V_93 == V_94 ) {
if ( F_18 ( V_35 , V_100 , V_101 ,
( char * ) & V_91 , sizeof( V_91 ) ) )
error ( 1 , 0 , L_22 ) ;
if ( V_28 == V_102 ) {
if ( F_19 ( V_35 , ( void * ) & V_31 , sizeof( V_31 ) ) )
error ( 1 , V_38 , L_23 ) ;
} else {
if ( F_19 ( V_35 , ( void * ) & V_103 , sizeof( V_103 ) ) )
error ( 1 , V_38 , L_24 ) ;
}
}
if ( V_104 ) {
if ( V_28 == V_69 ) {
if ( F_18 ( V_35 , V_53 , V_105 ,
& V_91 , sizeof( V_91 ) ) )
error ( 1 , V_38 , L_25 ) ;
} else {
if ( F_18 ( V_35 , V_51 , V_59 ,
& V_91 , sizeof( V_91 ) ) )
error ( 1 , V_38 , L_26 ) ;
}
}
V_89 |= V_106 |
V_107 |
V_108 ;
if ( V_109 )
V_89 |= V_110 ;
if ( F_18 ( V_35 , V_48 , V_111 ,
( char * ) & V_89 , sizeof( V_89 ) ) )
error ( 1 , 0 , L_27 ) ;
for ( V_27 = 0 ; V_27 < V_112 ; V_27 ++ ) {
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
memset ( V_90 , 'a' + V_27 , V_92 ) ;
if ( V_93 == V_95 ) {
struct V_96 * V_113 ;
int V_114 = 0 ;
if ( V_97 == V_98 ) {
struct V_99 * V_115 = ( void * ) V_90 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_116 = 5 ;
V_115 -> V_117 = 4 ;
V_115 -> V_118 = 2 ;
V_115 -> V_31 = V_31 . V_119 . V_120 ;
V_115 -> V_121 = V_122 ;
V_114 = sizeof( * V_115 ) ;
}
V_113 = ( void * ) V_90 + V_114 ;
V_113 -> V_123 = F_20 ( 9000 ) ;
V_113 -> V_124 = F_20 ( V_125 ) ;
V_113 -> V_26 = F_20 ( sizeof( * V_113 ) + V_77 ) ;
V_113 -> V_126 = 0 ;
}
F_2 () ;
if ( V_93 != V_94 ) {
if ( V_28 == V_102 )
V_91 = F_21 ( V_35 , V_90 , V_92 , 0 , ( void * ) & V_31 , sizeof( V_31 ) ) ;
else
V_91 = F_21 ( V_35 , V_90 , V_92 , 0 , ( void * ) & V_103 , sizeof( V_103 ) ) ;
} else {
V_91 = F_22 ( V_35 , V_90 , V_77 , 0 ) ;
}
if ( V_91 != V_92 )
error ( 1 , V_38 , L_28 ) ;
F_23 ( 50 * 1000 ) ;
F_8 ( V_35 ) ;
while ( ! F_14 ( V_35 ) ) {}
}
if ( F_24 ( V_35 ) )
error ( 1 , V_38 , L_29 ) ;
free ( V_90 ) ;
F_23 ( 400 * 1000 ) ;
}
static void F_25 ( int V_127 , char * * V_128 )
{
int V_129 = 0 ;
char V_130 ;
while ( ( V_130 = F_26 ( V_127 , V_128 , L_30 ) ) != - 1 ) {
switch ( V_130 ) {
case '4' :
V_131 = 0 ;
break;
case '6' :
V_132 = 0 ;
break;
case 'I' :
V_104 = true ;
break;
case 'n' :
V_109 = true ;
break;
case 'r' :
V_129 ++ ;
V_93 = V_95 ;
V_97 = V_122 ;
break;
case 'R' :
V_129 ++ ;
V_93 = V_95 ;
V_97 = V_98 ;
break;
case 'u' :
V_129 ++ ;
V_93 = V_133 ;
V_97 = V_122 ;
break;
case 'l' :
V_77 = strtoul ( V_134 , NULL , 10 ) ;
break;
case 'p' :
V_125 = strtoul ( V_134 , NULL , 10 ) ;
break;
case 'x' :
V_88 = true ;
break;
case 'h' :
default:
F_27 ( V_128 [ 0 ] ) ;
}
}
if ( ! V_77 )
error ( 1 , 0 , L_31 ) ;
if ( V_93 != V_94 && V_77 > 1472 )
error ( 1 , 0 , L_32 ) ;
if ( ! V_132 && ! V_131 )
error ( 1 , 0 , L_33 ) ;
if ( V_129 > 1 )
error ( 1 , 0 , L_34 ) ;
if ( V_135 != V_127 - 1 )
error ( 1 , 0 , L_35 ) ;
}
static void F_28 ( const char * V_136 )
{
struct V_137 * V_138 , * V_3 ;
int V_139 = 0 , V_140 = 0 ;
if ( F_29 ( V_136 , NULL , NULL , & V_138 ) )
error ( 1 , V_38 , L_36 ) ;
V_3 = V_138 ;
while ( V_3 && ! V_139 && ! V_140 ) {
if ( ! V_139 && V_3 -> V_141 == V_62 ) {
memcpy ( & V_31 , V_3 -> V_142 , sizeof( V_31 ) ) ;
V_31 . V_143 = F_30 ( V_125 ) ;
V_139 = 1 ;
}
else if ( ! V_140 && V_3 -> V_141 == V_69 ) {
memcpy ( & V_103 , V_3 -> V_142 , sizeof( V_103 ) ) ;
V_103 . V_144 = F_30 ( V_125 ) ;
V_140 = 1 ;
}
V_3 = V_3 -> V_145 ;
}
if ( V_138 )
F_31 ( V_138 ) ;
V_132 &= V_139 ;
V_131 &= V_140 ;
}
static void F_32 ( int V_28 )
{
fprintf ( V_8 , L_37 ,
V_28 == V_102 ? L_38 : L_39 ) ;
fprintf ( V_8 , L_40 ) ;
F_16 ( V_28 , V_146 ) ;
fprintf ( V_8 , L_41 ) ;
F_16 ( V_28 , V_147 ) ;
fprintf ( V_8 , L_42 ) ;
F_16 ( V_28 , V_147 |
V_146 ) ;
if ( V_93 == V_94 ) {
fprintf ( V_8 , L_43 ) ;
F_16 ( V_28 , V_148 ) ;
fprintf ( V_8 , L_44 ) ;
F_16 ( V_28 , V_146 |
V_148 ) ;
fprintf ( V_8 , L_45 ) ;
F_16 ( V_28 , V_147 |
V_146 |
V_148 ) ;
}
}
int main ( int V_127 , char * * V_128 )
{
if ( V_127 == 1 )
F_27 ( V_128 [ 0 ] ) ;
F_25 ( V_127 , V_128 ) ;
F_28 ( V_128 [ V_127 - 1 ] ) ;
fprintf ( V_8 , L_46 , V_149 [ V_93 ] ) ;
fprintf ( V_8 , L_47 , V_77 ) ;
fprintf ( V_8 , L_48 , V_125 ) ;
fprintf ( V_8 , L_4 ) ;
if ( V_132 )
F_32 ( V_102 ) ;
if ( V_131 )
F_32 ( V_150 ) ;
return 0 ;
}
