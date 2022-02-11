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
static void F_5 ( int V_24 )
{
struct V_25 V_25 ;
int V_26 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_24 = V_24 ;
V_26 = F_6 ( & V_25 , 1 , 100 ) ;
if ( V_26 != 1 )
error ( 1 , V_27 , L_9 ) ;
}
static void F_7 ( struct V_28 * V_29 , int V_5 )
{
struct V_30 * V_31 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_32 * V_33 ;
for ( V_33 = F_8 ( V_29 ) ;
V_33 && V_33 -> V_34 ;
V_33 = F_9 ( V_29 , V_33 ) ) {
if ( V_33 -> V_35 == V_36 &&
V_33 -> V_37 == V_38 ) {
V_17 = ( void * ) F_10 ( V_33 ) ;
} else if ( ( V_33 -> V_35 == V_39 &&
V_33 -> V_37 == V_40 ) ||
( V_33 -> V_35 == V_41 &&
V_33 -> V_37 == V_42 ) ) {
V_31 = ( void * ) F_10 ( V_33 ) ;
if ( V_31 -> V_43 != V_44 ||
V_31 -> V_45 != V_46 ) {
fprintf ( V_8 , L_10 ,
V_31 -> V_43 ,
V_31 -> V_45 ) ;
V_31 = NULL ;
}
} else
fprintf ( V_8 , L_11 ,
V_33 -> V_35 , V_33 -> V_37 ) ;
}
if ( V_31 && V_17 )
F_4 ( V_17 , V_31 -> V_47 , V_31 -> V_48 , V_5 ) ;
}
static int F_11 ( int V_24 )
{
static char V_49 [ 1024 ] ;
static struct V_28 V_29 ;
struct V_50 V_51 ;
static char * V_52 ;
int V_26 = 0 ;
V_52 = malloc ( V_53 ) ;
if ( ! V_52 )
error ( 1 , 0 , L_12 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
memset ( V_49 , 0 , sizeof( V_49 ) ) ;
V_51 . V_54 = V_52 ;
V_51 . V_55 = V_53 ;
V_29 . V_56 = & V_51 ;
V_29 . V_57 = 1 ;
V_29 . V_58 = NULL ;
V_29 . V_59 = 0 ;
V_29 . V_60 = V_49 ;
V_29 . V_61 = sizeof( V_49 ) ;
V_26 = F_12 ( V_24 , & V_29 , V_62 ) ;
if ( V_26 == - 1 && V_27 != V_63 )
error ( 1 , V_27 , L_13 ) ;
F_7 ( & V_29 , V_26 ) ;
free ( V_52 ) ;
return V_26 == - 1 ;
}
static void F_13 ( int V_64 , unsigned int V_65 )
{
char * V_66 ;
int V_24 , V_67 , V_68 , V_69 ;
if ( V_64 == V_70 && V_71 != V_72 ) {
fprintf ( V_8 , L_14 ) ;
return;
}
V_69 = V_53 ;
if ( V_71 == V_73 ) {
V_69 += sizeof( struct V_74 ) ;
if ( V_75 == V_76 )
V_69 += sizeof( struct V_77 ) ;
}
V_66 = malloc ( V_69 ) ;
if ( ! V_66 )
error ( 1 , 0 , L_12 ) ;
V_24 = F_14 ( V_64 , V_71 , V_75 ) ;
if ( V_24 < 0 )
error ( 1 , V_27 , L_15 ) ;
if ( V_71 == V_72 ) {
V_68 = 1 ;
if ( F_15 ( V_24 , V_78 , V_79 ,
( char * ) & V_68 , sizeof( V_68 ) ) )
error ( 1 , 0 , L_16 ) ;
if ( V_64 == V_80 ) {
if ( F_16 ( V_24 , ( void * ) & V_81 , sizeof( V_81 ) ) )
error ( 1 , V_27 , L_17 ) ;
} else {
if ( F_16 ( V_24 , ( void * ) & V_82 , sizeof( V_82 ) ) )
error ( 1 , V_27 , L_18 ) ;
}
}
V_65 |= V_83 |
V_84 ;
if ( F_15 ( V_24 , V_36 , V_85 ,
( char * ) & V_65 , sizeof( V_65 ) ) )
error ( 1 , 0 , L_19 ) ;
for ( V_67 = 0 ; V_67 < V_86 ; V_67 ++ ) {
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
memset ( V_66 , 'a' + V_67 , V_69 ) ;
V_66 [ V_69 - 2 ] = '\n' ;
V_66 [ V_69 - 1 ] = '\0' ;
if ( V_71 == V_73 ) {
struct V_74 * V_87 ;
int V_88 = 0 ;
if ( V_75 == V_76 ) {
struct V_77 * V_89 = ( void * ) V_66 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_90 = 5 ;
V_89 -> V_91 = 4 ;
V_89 -> V_92 = 2 ;
V_89 -> V_81 = V_81 . V_93 . V_94 ;
V_89 -> V_95 = V_96 ;
V_88 = sizeof( * V_89 ) ;
}
V_87 = ( void * ) V_66 + V_88 ;
V_87 -> V_97 = F_17 ( 9000 ) ;
V_87 -> V_98 = F_17 ( V_99 ) ;
V_87 -> V_100 = F_17 ( sizeof( * V_87 ) + V_53 ) ;
V_87 -> V_101 = 0 ;
}
F_2 () ;
if ( V_71 != V_72 ) {
if ( V_64 == V_80 )
V_68 = F_18 ( V_24 , V_66 , V_69 , 0 , ( void * ) & V_81 , sizeof( V_81 ) ) ;
else
V_68 = F_18 ( V_24 , V_66 , V_69 , 0 , ( void * ) & V_82 , sizeof( V_82 ) ) ;
} else {
V_68 = F_19 ( V_24 , V_66 , V_53 , 0 ) ;
}
if ( V_68 != V_69 )
error ( 1 , V_27 , L_20 ) ;
F_20 ( 50 * 1000 ) ;
F_5 ( V_24 ) ;
while ( ! F_11 ( V_24 ) ) {}
}
if ( F_21 ( V_24 ) )
error ( 1 , V_27 , L_21 ) ;
free ( V_66 ) ;
F_20 ( 400 * 1000 ) ;
}
static void F_22 ( int V_102 , char * * V_103 )
{
int V_104 = 0 ;
char V_105 ;
while ( ( V_105 = F_23 ( V_102 , V_103 , L_22 ) ) != - 1 ) {
switch ( V_105 ) {
case '4' :
V_106 = 0 ;
break;
case '6' :
V_107 = 0 ;
break;
case 'r' :
V_104 ++ ;
V_71 = V_73 ;
V_75 = V_96 ;
break;
case 'R' :
V_104 ++ ;
V_71 = V_73 ;
V_75 = V_76 ;
break;
case 'u' :
V_104 ++ ;
V_71 = V_108 ;
V_75 = V_96 ;
break;
case 'l' :
V_53 = strtoul ( V_109 , NULL , 10 ) ;
break;
case 'p' :
V_99 = strtoul ( V_109 , NULL , 10 ) ;
break;
case 'h' :
default:
F_24 ( V_103 [ 0 ] ) ;
}
}
if ( ! V_53 )
error ( 1 , 0 , L_23 ) ;
if ( V_71 != V_72 && V_53 > 1472 )
error ( 1 , 0 , L_24 ) ;
if ( ! V_107 && ! V_106 )
error ( 1 , 0 , L_25 ) ;
if ( V_104 > 1 )
error ( 1 , 0 , L_26 ) ;
if ( V_110 != V_102 - 1 )
error ( 1 , 0 , L_27 ) ;
}
static void F_25 ( const char * V_111 )
{
struct V_112 * V_113 , * V_3 ;
int V_114 = 0 , V_115 = 0 ;
if ( F_26 ( V_111 , NULL , NULL , & V_113 ) )
error ( 1 , V_27 , L_28 ) ;
V_3 = V_113 ;
while ( V_3 && ! V_114 && ! V_115 ) {
if ( ! V_114 && V_3 -> V_116 == V_117 ) {
memcpy ( & V_81 , V_3 -> V_118 , sizeof( V_81 ) ) ;
V_81 . V_119 = F_27 ( V_99 ) ;
V_114 = 1 ;
}
else if ( ! V_115 && V_3 -> V_116 == V_120 ) {
memcpy ( & V_82 , V_3 -> V_118 , sizeof( V_82 ) ) ;
V_82 . V_121 = F_27 ( V_99 ) ;
V_115 = 1 ;
}
V_3 = V_3 -> V_122 ;
}
if ( V_113 )
F_28 ( V_113 ) ;
V_107 &= V_114 ;
V_106 &= V_115 ;
}
static void F_29 ( int V_64 )
{
fprintf ( V_8 , L_29 ,
V_64 == V_80 ? L_30 : L_31 ) ;
fprintf ( V_8 , L_32 ) ;
F_13 ( V_64 , V_123 ) ;
fprintf ( V_8 , L_33 ) ;
F_13 ( V_64 , V_124 ) ;
fprintf ( V_8 , L_34 ) ;
F_13 ( V_64 , V_124 |
V_123 ) ;
if ( V_71 == V_72 ) {
fprintf ( V_8 , L_35 ) ;
F_13 ( V_64 , V_125 ) ;
fprintf ( V_8 , L_36 ) ;
F_13 ( V_64 , V_123 |
V_125 ) ;
fprintf ( V_8 , L_37 ) ;
F_13 ( V_64 , V_124 |
V_123 |
V_125 ) ;
}
}
int main ( int V_102 , char * * V_103 )
{
if ( V_102 == 1 )
F_24 ( V_103 [ 0 ] ) ;
F_22 ( V_102 , V_103 ) ;
F_25 ( V_103 [ V_102 - 1 ] ) ;
fprintf ( V_8 , L_38 , V_126 [ V_71 ] ) ;
fprintf ( V_8 , L_39 , V_53 ) ;
fprintf ( V_8 , L_40 , V_99 ) ;
fprintf ( V_8 , L_3 ) ;
if ( V_107 )
F_29 ( V_80 ) ;
if ( V_106 )
F_29 ( V_127 ) ;
return 0 ;
}
