void F_1 ( T_1 )
{
const char * V_1 = __FILE__ ;
V_2 ;
F_2 ( L_1 , V_3 ,
V_1 ) ;
F_2 ( L_2 , V_4 , V_1 ) ;
}
static void F_3 ( const char * V_5 ,
const char * V_6 ,
const char * V_7 ,
const char * V_8 )
{
unsigned long long V_9 ;
V_10 ;
V_9 = F_4 ( V_7 ) ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_5 , 0 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_6 , 0 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_9 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_8 , 0 ) ) ) ;
V_14 ;
if ( F_10 ( L_3 , 0 ) )
F_11 ( L_3 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_12 ( struct V_19 * V_20 ,
const char * V_5 ,
const char * V_6 )
{
F_3 ( V_5 , V_6 , V_20 -> V_9 , V_20 -> V_21 ) ;
if ( V_20 -> V_22 )
F_12 ( V_20 -> V_22 , V_5 , V_6 ) ;
}
static void F_13 ( const char * V_5 ,
const char * V_6 )
{
V_10 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_5 , 0 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_6 , 0 ) ) ) ;
V_14 ;
if ( F_10 ( L_4 , 0 ) )
F_11 ( L_4 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_14 ( const char * V_5 ,
const char * V_6 ,
const char * V_7 ,
const char * V_8 )
{
unsigned long long V_9 ;
V_10 ;
V_9 = F_4 ( V_7 ) ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_5 , 0 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_6 , 0 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_9 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_8 , 0 ) ) ) ;
V_14 ;
if ( F_10 ( L_5 , 0 ) )
F_11 ( L_5 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_15 ( struct V_19 * V_20 ,
const char * V_5 ,
const char * V_6 )
{
F_14 ( V_5 , V_6 , V_20 -> V_9 , V_20 -> V_21 ) ;
if ( V_20 -> V_22 )
F_15 ( V_20 -> V_22 , V_5 , V_6 ) ;
}
static void F_16 ( const char * V_5 ,
const char * V_6 ,
const char * V_23 )
{
V_10 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_5 , 0 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_6 , 0 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_23 , 0 ) ) ) ;
V_14 ;
if ( F_10 ( L_6 , 0 ) )
F_11 ( L_6 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_17 ( struct V_24 * V_25 ,
const char * V_5 ,
struct V_26 * args )
{
if ( args == NULL )
return;
switch ( args -> type ) {
case V_27 :
break;
case V_28 :
F_14 ( V_5 , V_29 , L_7 ,
args -> V_30 . V_30 ) ;
V_31 = 0 ;
break;
case V_32 :
free ( V_29 ) ;
V_29 = F_18 ( args -> V_20 . V_33 ) ;
break;
case V_34 :
F_17 ( V_25 , V_5 , args -> V_35 . V_20 ) ;
F_16 ( V_5 , V_29 , args -> V_35 . V_23 ) ;
F_15 ( args -> V_35 . V_35 , V_5 , V_29 ) ;
break;
case V_36 :
F_17 ( V_25 , V_5 , args -> V_37 . V_20 ) ;
F_13 ( V_5 , V_29 ) ;
F_12 ( args -> V_37 . V_38 , V_5 ,
V_29 ) ;
break;
case V_39 :
case V_40 :
F_17 ( V_25 , V_5 , args -> V_41 . V_20 ) ;
F_17 ( V_25 , V_5 , args -> V_41 . V_42 ) ;
break;
case V_43 :
F_17 ( V_25 , V_5 , args -> V_44 . V_20 ) ;
F_17 ( V_25 , V_5 , args -> V_44 . V_45 ) ;
F_17 ( V_25 , V_5 , args -> V_44 . V_46 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
break;
case V_52 :
F_17 ( V_25 , V_5 , args -> V_53 . V_54 ) ;
break;
case V_55 :
if ( strcmp ( args -> V_56 . V_56 , L_8 ) == 0 )
V_31 = 1 ;
F_17 ( V_25 , V_5 , args -> V_56 . V_57 ) ;
F_17 ( V_25 , V_5 , args -> V_56 . V_58 ) ;
break;
case V_59 :
default:
F_19 ( L_9 ) ;
return;
}
if ( args -> V_22 )
F_17 ( V_25 , V_5 , args -> V_22 ) ;
}
static T_2 * F_20 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
T_3 * V_66 ;
V_66 = F_21 () ;
if ( ! V_66 )
goto exit;
if ( ! V_67 . V_68 || ! V_61 -> V_69 )
goto exit;
if ( F_22 ( V_65 -> V_70 , & V_71 , V_63 ,
V_61 , NULL , NULL , V_72 ) != 0 ) {
F_19 ( L_10 ) ;
goto exit;
}
F_23 ( & V_71 ) ;
while ( 1 ) {
T_4 * V_73 ;
struct V_74 * V_75 ;
V_75 = F_24 ( & V_71 ) ;
if ( ! V_75 )
break;
V_73 = F_25 () ;
if ( ! V_73 )
goto exit;
if ( ! F_26 ( V_73 , L_11 , F_9 ( V_75 -> V_76 ) ) ) {
F_27 ( V_73 ) ;
goto exit;
}
if ( V_75 -> V_77 ) {
T_4 * V_77 = F_25 () ;
if ( ! V_77 ) {
F_27 ( V_73 ) ;
goto exit;
}
if ( ! F_26 ( V_77 , L_12 , F_9 ( V_75 -> V_77 -> V_78 ) ) ||
! F_26 ( V_77 , L_13 , F_9 ( V_75 -> V_77 -> V_79 ) ) ||
! F_26 ( V_77 , L_14 , F_9 ( V_75 -> V_77 -> V_80 ) ) ||
! F_26 ( V_77 , L_15 , F_28 ( V_75 -> V_77 -> V_33 ,
V_75 -> V_77 -> V_81 ) ) ||
! F_26 ( V_73 , L_16 , F_29 ( ( T_2 * ) V_77 ) ) ) {
F_27 ( V_77 ) ;
F_27 ( V_73 ) ;
goto exit;
}
}
if ( V_75 -> V_82 ) {
struct V_82 * V_82 = V_75 -> V_82 ;
const char * V_83 = L_17 ;
if ( V_82 && V_82 -> V_84 ) {
if ( V_67 . V_85 && V_82 -> V_84 -> V_86 )
V_83 = V_82 -> V_84 -> V_86 ;
else
V_83 = V_82 -> V_84 -> V_33 ;
}
if ( ! F_26 ( V_73 , L_18 , F_8 ( V_83 , 0 ) ) ) {
F_27 ( V_73 ) ;
goto exit;
}
}
F_30 ( & V_71 ) ;
F_31 ( V_66 , F_29 ( ( T_2 * ) V_73 ) ) ;
}
exit:
return F_29 ( ( T_2 * ) V_66 ) ;
}
static void F_32 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_70 * V_70 = V_65 -> V_70 ;
struct V_24 * V_25 = V_63 -> V_87 ;
struct V_88 * V_20 ;
static char V_89 [ 256 ] ;
unsigned long long V_90 ;
unsigned long V_91 , V_92 ;
int V_93 ;
int V_94 = V_61 -> V_94 ;
void * V_95 = V_61 -> V_96 ;
unsigned long long V_97 = V_61 -> time ;
const char * V_98 = F_33 ( V_70 ) ;
V_10 ;
if ( V_63 -> V_99 . type != V_100 )
return;
if ( ! V_25 ) {
F_34 ( L_19 V_101 , ( V_102 ) V_63 -> V_99 . V_103 ) ;
return;
}
V_93 = F_35 ( V_25 , L_20 , V_95 ) ;
sprintf ( V_89 , L_21 , V_25 -> system , V_25 -> V_33 ) ;
if ( ! F_36 ( V_25 -> V_104 , V_105 ) )
F_17 ( V_25 , V_89 , V_25 -> V_106 . args ) ;
V_91 = V_97 / V_107 ;
V_92 = V_97 - V_91 * V_107 ;
V_108 -> V_109 = V_95 ;
V_108 -> V_110 = V_63 -> V_87 -> V_110 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_89 , 0 ) ) ) ;
F_6 ( F_7 ( F_37 ( F_38 ( V_108 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_94 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_91 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_92 ) ) ) ;
F_6 ( F_7 ( F_37 ( V_93 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_98 , 0 ) ) ) ;
F_6 ( F_7 ( F_20 ( V_61 , V_63 , V_65 ) ) ) ;
for ( V_20 = V_25 -> V_111 . V_112 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_113 ) {
int V_114 ;
if ( V_20 -> V_35 & V_115 ) {
V_114 = * ( int * ) ( V_95 + V_20 -> V_114 ) ;
V_114 &= 0xffff ;
} else
V_114 = V_20 -> V_114 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_95 + V_114 , 0 ) ) ) ;
} else {
V_90 = F_39 ( V_25 , V_95 + V_20 -> V_114 ,
V_20 -> V_42 ) ;
if ( V_20 -> V_35 & V_116 ) {
F_6 ( F_7 ( F_37 ( V_90 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_90 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_89 , 0 ) )
F_11 ( V_89 , V_15 ) ;
else if ( F_10 ( L_22 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_89 , 0 ) ) ) ;
F_6 ( F_7 ( F_37 ( F_38 ( V_108 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_94 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_97 ) ) ) ;
F_6 ( F_7 ( F_37 ( V_93 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_98 , 0 ) ) ) ;
F_6 ( F_7 ( F_20 ( V_61 , V_63 , V_65 ) ) ) ;
F_11 ( L_22 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_40 ( union V_117 * V_25 ,
struct V_60 * V_61 ,
struct V_62 * V_63 )
{
V_10 ;
if ( ! F_10 ( L_23 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_25 , V_25 -> V_118 . V_42 ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) & V_63 -> V_99 , sizeof( V_63 -> V_99 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_61 , sizeof( * V_61 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_61 -> V_96 , V_61 -> V_119 ) ) ) ;
V_14 ;
F_11 ( L_23 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_41 ( union V_117 * V_25 ,
struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
F_32 ( V_61 , V_63 , V_65 ) ;
F_40 ( V_25 , V_61 , V_63 ) ;
}
static void F_42 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_24 , 0 ) )
F_11 ( L_24 , V_120 | V_121 ) ;
}
static int F_43 ( const char * V_122 , int V_123 , const char * * V_124 )
{
const char * * V_125 ;
int V_126 , V_127 = 0 ;
V_125 = malloc ( ( V_123 + 2 ) * sizeof( const char * ) ) ;
V_125 [ 0 ] = L_25 ;
V_125 [ 1 ] = V_122 ;
for ( V_126 = 2 ; V_126 < V_123 + 2 ; V_126 ++ )
V_125 [ V_126 ] = V_124 [ V_126 - 2 ] ;
V_128 = F_44 () ;
F_45 ( V_128 ) ;
if ( F_46 ( V_128 , F_1 , V_123 + 2 , ( char * * ) V_125 ,
( char * * ) NULL ) ) {
V_127 = - 1 ;
goto error;
}
if ( F_47 ( V_128 ) ) {
V_127 = - 1 ;
goto error;
}
if ( F_48 ( V_129 ) ) {
V_127 = - 1 ;
goto error;
}
F_42 () ;
free ( V_125 ) ;
return 0 ;
error:
F_49 ( V_128 ) ;
free ( V_125 ) ;
return V_127 ;
}
static int F_50 ( void )
{
return 0 ;
}
static int F_51 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_26 , 0 ) )
F_11 ( L_26 , V_120 | V_121 ) ;
F_52 ( V_128 ) ;
F_49 ( V_128 ) ;
return 0 ;
}
static int F_53 ( struct V_110 * V_110 , const char * V_130 )
{
struct V_24 * V_25 = NULL ;
struct V_88 * V_131 ;
char V_132 [ V_133 ] ;
int V_134 , V_45 ;
T_5 * V_135 ;
sprintf ( V_132 , L_27 , V_130 ) ;
V_135 = fopen ( V_132 , L_28 ) ;
if ( V_135 == NULL ) {
fprintf ( V_136 , L_29 , V_132 ) ;
return - 1 ;
}
fprintf ( V_135 , L_30
L_31 ) ;
fprintf ( V_135 , L_32
L_33 ) ;
fprintf ( V_135 , L_34
L_35 ) ;
fprintf ( V_135 , L_36
L_37 ) ;
fprintf ( V_135 , L_38
L_39 ) ;
fprintf ( V_135 , L_40
L_41 ) ;
fprintf ( V_135 , L_42
L_43 ) ;
fprintf ( V_135 , L_44
L_45 ) ;
fprintf ( V_135 , L_46 ) ;
fprintf ( V_135 , L_47 ) ;
fprintf ( V_135 , L_48 ) ;
fprintf ( V_135 , L_49 ) ;
fprintf ( V_135 , L_50 ) ;
fprintf ( V_135 , L_51 ) ;
fprintf ( V_135 , L_52 ) ;
while ( ( V_25 = F_54 ( V_110 , V_25 ) ) ) {
fprintf ( V_135 , L_53 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_135 , L_54 ) ;
fprintf ( V_135 , L_55 ) ;
fprintf ( V_135 , L_56 ) ;
fprintf ( V_135 , L_57 ) ;
fprintf ( V_135 , L_58 ) ;
fprintf ( V_135 , L_59 ) ;
fprintf ( V_135 , L_60 ) ;
fprintf ( V_135 , L_61 ) ;
fprintf ( V_135 , L_62 ) ;
V_134 = 0 ;
V_45 = 0 ;
for ( V_131 = V_25 -> V_111 . V_112 ; V_131 ; V_131 = V_131 -> V_22 ) {
if ( V_134 ++ )
fprintf ( V_135 , L_63 ) ;
if ( ++ V_45 % 5 == 0 )
fprintf ( V_135 , L_64 ) ;
fprintf ( V_135 , L_65 , V_131 -> V_33 ) ;
}
fprintf ( V_135 , L_66 ) ;
fprintf ( V_135 , L_67
L_68
L_69 ) ;
fprintf ( V_135 , L_70 ) ;
V_134 = 0 ;
V_45 = 0 ;
for ( V_131 = V_25 -> V_111 . V_112 ; V_131 ; V_131 = V_131 -> V_22 ) {
if ( V_134 ++ )
fprintf ( V_135 , L_63 ) ;
if ( V_45 && V_45 % 4 == 0 ) {
fprintf ( V_135 , L_71 ) ;
}
V_45 ++ ;
fprintf ( V_135 , L_72 , V_131 -> V_33 ) ;
if ( V_131 -> V_35 & V_113 ||
V_131 -> V_35 & V_137 ||
V_131 -> V_35 & V_138 )
fprintf ( V_135 , L_73 ) ;
else if ( V_131 -> V_35 & V_116 )
fprintf ( V_135 , L_74 ) ;
else
fprintf ( V_135 , L_75 ) ;
}
fprintf ( V_135 , L_76 ) ;
V_134 = 0 ;
V_45 = 0 ;
for ( V_131 = V_25 -> V_111 . V_112 ; V_131 ; V_131 = V_131 -> V_22 ) {
if ( V_134 ++ )
fprintf ( V_135 , L_63 ) ;
if ( ++ V_45 % 5 == 0 )
fprintf ( V_135 , L_77 ) ;
if ( V_131 -> V_35 & V_137 ) {
if ( ( V_45 - 1 ) % 5 != 0 ) {
fprintf ( V_135 , L_77 ) ;
V_45 = 4 ;
}
fprintf ( V_135 , L_78 ) ;
fprintf ( V_135 , L_79 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_135 , L_80 , V_131 -> V_33 ,
V_131 -> V_33 ) ;
} else if ( V_131 -> V_35 & V_138 ) {
if ( ( V_45 - 1 ) % 5 != 0 ) {
fprintf ( V_135 , L_77 ) ;
V_45 = 4 ;
}
fprintf ( V_135 , L_81 ) ;
fprintf ( V_135 , L_79 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_135 , L_80 , V_131 -> V_33 ,
V_131 -> V_33 ) ;
} else
fprintf ( V_135 , L_65 , V_131 -> V_33 ) ;
}
fprintf ( V_135 , L_82 ) ;
fprintf ( V_135 , L_83 ) ;
fprintf ( V_135 , L_84 ) ;
}
fprintf ( V_135 , L_85
L_86
L_87 ) ;
fprintf ( V_135 , L_67
L_88
L_89 ) ;
fprintf ( V_135 , L_83 ) ;
fprintf ( V_135 , L_84 ) ;
fprintf ( V_135 , L_90
L_91
L_92
L_93 ) ;
fprintf ( V_135 ,
L_94
L_95
L_96
L_97
L_98
L_99
L_100
L_101
L_102
L_103
L_100
L_104
L_105
L_106
L_107
L_100
L_108
L_109
L_110 ) ;
fclose ( V_135 ) ;
fprintf ( V_136 , L_111 , V_132 ) ;
return 0 ;
}
