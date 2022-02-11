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
F_17 ( V_25 , V_5 , args -> V_40 . V_20 ) ;
F_17 ( V_25 , V_5 , args -> V_40 . V_41 ) ;
break;
case V_42 :
F_17 ( V_25 , V_5 , args -> V_43 . V_20 ) ;
F_17 ( V_25 , V_5 , args -> V_43 . V_44 ) ;
F_17 ( V_25 , V_5 , args -> V_43 . V_45 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
break;
case V_51 :
F_17 ( V_25 , V_5 , args -> V_52 . V_53 ) ;
break;
case V_54 :
if ( strcmp ( args -> V_55 . V_55 , L_8 ) == 0 )
V_31 = 1 ;
F_17 ( V_25 , V_5 , args -> V_55 . V_56 ) ;
F_17 ( V_25 , V_5 , args -> V_55 . V_57 ) ;
break;
case V_58 :
default:
F_19 ( L_9 ) ;
return;
}
if ( args -> V_22 )
F_17 ( V_25 , V_5 , args -> V_22 ) ;
}
static T_2 * F_20 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_64 )
{
T_3 * V_65 ;
V_65 = F_21 () ;
if ( ! V_65 )
goto exit;
if ( ! V_66 . V_67 || ! V_60 -> V_68 )
goto exit;
if ( F_22 ( V_64 -> V_69 , & V_70 , V_62 ,
V_60 , NULL , NULL , V_71 ) != 0 ) {
F_19 ( L_10 ) ;
goto exit;
}
F_23 ( & V_70 ) ;
while ( 1 ) {
T_4 * V_72 ;
struct V_73 * V_74 ;
V_74 = F_24 ( & V_70 ) ;
if ( ! V_74 )
break;
V_72 = F_25 () ;
if ( ! V_72 )
goto exit;
if ( ! F_26 ( V_72 , L_11 , F_9 ( V_74 -> V_75 ) ) ) {
F_27 ( V_72 ) ;
goto exit;
}
if ( V_74 -> V_76 ) {
T_4 * V_76 = F_25 () ;
if ( ! V_76 ) {
F_27 ( V_72 ) ;
goto exit;
}
if ( ! F_26 ( V_76 , L_12 , F_9 ( V_74 -> V_76 -> V_77 ) ) ||
! F_26 ( V_76 , L_13 , F_9 ( V_74 -> V_76 -> V_78 ) ) ||
! F_26 ( V_76 , L_14 , F_9 ( V_74 -> V_76 -> V_79 ) ) ||
! F_26 ( V_76 , L_15 , F_28 ( V_74 -> V_76 -> V_33 ,
V_74 -> V_76 -> V_80 ) ) ||
! F_26 ( V_72 , L_16 , F_29 ( ( T_2 * ) V_76 ) ) ) {
F_27 ( V_76 ) ;
F_27 ( V_72 ) ;
goto exit;
}
}
if ( V_74 -> V_81 ) {
struct V_81 * V_81 = V_74 -> V_81 ;
const char * V_82 = L_17 ;
if ( V_81 && V_81 -> V_83 && ( V_81 -> V_83 -> V_33 || V_81 -> V_83 -> V_84 ) ) {
if ( V_66 . V_85 && V_81 -> V_83 -> V_84 )
V_82 = V_81 -> V_83 -> V_84 ;
else if ( V_81 -> V_83 -> V_33 )
V_82 = V_81 -> V_83 -> V_33 ;
}
if ( ! F_26 ( V_72 , L_18 , F_8 ( V_82 , 0 ) ) ) {
F_27 ( V_72 ) ;
goto exit;
}
}
F_30 ( & V_70 ) ;
F_31 ( V_65 , F_29 ( ( T_2 * ) V_72 ) ) ;
}
exit:
return F_29 ( ( T_2 * ) V_65 ) ;
}
static void F_32 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_69 * V_69 = V_64 -> V_69 ;
struct V_24 * V_25 = V_62 -> V_86 ;
struct V_87 * V_20 ;
static char V_88 [ 256 ] ;
unsigned long long V_89 ;
unsigned long V_90 , V_91 ;
int V_92 ;
int V_93 = V_60 -> V_93 ;
void * V_94 = V_60 -> V_95 ;
unsigned long long V_96 = V_60 -> time ;
const char * V_97 = F_33 ( V_69 ) ;
V_10 ;
if ( V_62 -> V_98 . type != V_99 )
return;
if ( ! V_25 )
F_34 ( L_19 V_100 , ( V_101 ) V_62 -> V_98 . V_102 ) ;
V_92 = F_35 ( V_25 , L_20 , V_94 ) ;
sprintf ( V_88 , L_21 , V_25 -> system , V_25 -> V_33 ) ;
if ( ! F_36 ( V_25 -> V_103 , V_104 ) )
F_17 ( V_25 , V_88 , V_25 -> V_105 . args ) ;
V_90 = V_96 / V_106 ;
V_91 = V_96 - V_90 * V_106 ;
V_107 -> V_108 = V_94 ;
V_107 -> V_109 = V_62 -> V_86 -> V_109 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_88 , 0 ) ) ) ;
F_6 ( F_7 ( F_37 ( F_38 ( V_107 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_93 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_90 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_91 ) ) ) ;
F_6 ( F_7 ( F_37 ( V_92 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_97 , 0 ) ) ) ;
F_6 ( F_7 ( F_20 ( V_60 , V_62 , V_64 ) ) ) ;
for ( V_20 = V_25 -> V_110 . V_111 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_112 ) {
int V_113 ;
if ( V_20 -> V_35 & V_114 ) {
V_113 = * ( int * ) ( V_94 + V_20 -> V_113 ) ;
V_113 &= 0xffff ;
} else
V_113 = V_20 -> V_113 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_94 + V_113 , 0 ) ) ) ;
} else {
V_89 = F_39 ( V_25 , V_94 + V_20 -> V_113 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_115 ) {
F_6 ( F_7 ( F_37 ( V_89 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_89 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_88 , 0 ) )
F_11 ( V_88 , V_15 ) ;
else if ( F_10 ( L_22 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_88 , 0 ) ) ) ;
F_6 ( F_7 ( F_37 ( F_38 ( V_107 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_93 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_96 ) ) ) ;
F_6 ( F_7 ( F_37 ( V_92 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_97 , 0 ) ) ) ;
F_6 ( F_7 ( F_20 ( V_60 , V_62 , V_64 ) ) ) ;
F_11 ( L_22 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_40 ( union V_116 * V_25 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
V_10 ;
if ( ! F_10 ( L_23 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_25 , V_25 -> V_117 . V_41 ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) & V_62 -> V_98 , sizeof( V_62 -> V_98 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_60 , sizeof( * V_60 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_60 -> V_95 , V_60 -> V_118 ) ) ) ;
V_14 ;
F_11 ( L_23 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_41 ( union V_116 * V_25 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_64 )
{
F_32 ( V_60 , V_62 , V_64 ) ;
F_40 ( V_25 , V_60 , V_62 ) ;
}
static void F_42 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_24 , 0 ) )
F_11 ( L_24 , V_119 | V_120 ) ;
}
static int F_43 ( const char * V_121 , int V_122 , const char * * V_123 )
{
const char * * V_124 ;
int V_125 , V_126 = 0 ;
V_124 = malloc ( ( V_122 + 2 ) * sizeof( const char * ) ) ;
V_124 [ 0 ] = L_25 ;
V_124 [ 1 ] = V_121 ;
for ( V_125 = 2 ; V_125 < V_122 + 2 ; V_125 ++ )
V_124 [ V_125 ] = V_123 [ V_125 - 2 ] ;
V_127 = F_44 () ;
F_45 ( V_127 ) ;
if ( F_46 ( V_127 , F_1 , V_122 + 2 , ( char * * ) V_124 ,
( char * * ) NULL ) ) {
V_126 = - 1 ;
goto error;
}
if ( F_47 ( V_127 ) ) {
V_126 = - 1 ;
goto error;
}
if ( F_48 ( V_128 ) ) {
V_126 = - 1 ;
goto error;
}
F_42 () ;
free ( V_124 ) ;
return 0 ;
error:
F_49 ( V_127 ) ;
free ( V_124 ) ;
return V_126 ;
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
F_11 ( L_26 , V_119 | V_120 ) ;
F_52 ( V_127 ) ;
F_49 ( V_127 ) ;
return 0 ;
}
static int F_53 ( struct V_109 * V_109 , const char * V_129 )
{
struct V_24 * V_25 = NULL ;
struct V_87 * V_130 ;
char V_131 [ V_132 ] ;
int V_133 , V_44 ;
T_5 * V_134 ;
sprintf ( V_131 , L_27 , V_129 ) ;
V_134 = fopen ( V_131 , L_28 ) ;
if ( V_134 == NULL ) {
fprintf ( V_135 , L_29 , V_131 ) ;
return - 1 ;
}
fprintf ( V_134 , L_30
L_31 ) ;
fprintf ( V_134 , L_32
L_33 ) ;
fprintf ( V_134 , L_34
L_35 ) ;
fprintf ( V_134 , L_36
L_37 ) ;
fprintf ( V_134 , L_38
L_39 ) ;
fprintf ( V_134 , L_40
L_41 ) ;
fprintf ( V_134 , L_42
L_43 ) ;
fprintf ( V_134 , L_44
L_45 ) ;
fprintf ( V_134 , L_46 ) ;
fprintf ( V_134 , L_47 ) ;
fprintf ( V_134 , L_48 ) ;
fprintf ( V_134 , L_49 ) ;
fprintf ( V_134 , L_50 ) ;
fprintf ( V_134 , L_51 ) ;
fprintf ( V_134 , L_52 ) ;
while ( ( V_25 = F_54 ( V_109 , V_25 ) ) ) {
fprintf ( V_134 , L_53 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_134 , L_54 ) ;
fprintf ( V_134 , L_55 ) ;
fprintf ( V_134 , L_56 ) ;
fprintf ( V_134 , L_57 ) ;
fprintf ( V_134 , L_58 ) ;
fprintf ( V_134 , L_59 ) ;
fprintf ( V_134 , L_60 ) ;
fprintf ( V_134 , L_61 ) ;
fprintf ( V_134 , L_62 ) ;
V_133 = 0 ;
V_44 = 0 ;
for ( V_130 = V_25 -> V_110 . V_111 ; V_130 ; V_130 = V_130 -> V_22 ) {
if ( V_133 ++ )
fprintf ( V_134 , L_63 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_134 , L_64 ) ;
fprintf ( V_134 , L_65 , V_130 -> V_33 ) ;
}
fprintf ( V_134 , L_66 ) ;
fprintf ( V_134 , L_67
L_68
L_69 ) ;
fprintf ( V_134 , L_70 ) ;
V_133 = 0 ;
V_44 = 0 ;
for ( V_130 = V_25 -> V_110 . V_111 ; V_130 ; V_130 = V_130 -> V_22 ) {
if ( V_133 ++ )
fprintf ( V_134 , L_63 ) ;
if ( V_44 && V_44 % 4 == 0 ) {
fprintf ( V_134 , L_71 ) ;
}
V_44 ++ ;
fprintf ( V_134 , L_72 , V_130 -> V_33 ) ;
if ( V_130 -> V_35 & V_112 ||
V_130 -> V_35 & V_136 ||
V_130 -> V_35 & V_137 )
fprintf ( V_134 , L_73 ) ;
else if ( V_130 -> V_35 & V_115 )
fprintf ( V_134 , L_74 ) ;
else
fprintf ( V_134 , L_75 ) ;
}
fprintf ( V_134 , L_76 ) ;
V_133 = 0 ;
V_44 = 0 ;
for ( V_130 = V_25 -> V_110 . V_111 ; V_130 ; V_130 = V_130 -> V_22 ) {
if ( V_133 ++ )
fprintf ( V_134 , L_63 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_134 , L_77 ) ;
if ( V_130 -> V_35 & V_136 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_134 , L_77 ) ;
V_44 = 4 ;
}
fprintf ( V_134 , L_78 ) ;
fprintf ( V_134 , L_79 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_134 , L_80 , V_130 -> V_33 ,
V_130 -> V_33 ) ;
} else if ( V_130 -> V_35 & V_137 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_134 , L_77 ) ;
V_44 = 4 ;
}
fprintf ( V_134 , L_81 ) ;
fprintf ( V_134 , L_79 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_134 , L_80 , V_130 -> V_33 ,
V_130 -> V_33 ) ;
} else
fprintf ( V_134 , L_65 , V_130 -> V_33 ) ;
}
fprintf ( V_134 , L_82 ) ;
fprintf ( V_134 , L_83 ) ;
fprintf ( V_134 , L_84 ) ;
}
fprintf ( V_134 , L_85
L_86
L_87 ) ;
fprintf ( V_134 , L_67
L_88
L_89 ) ;
fprintf ( V_134 , L_83 ) ;
fprintf ( V_134 , L_84 ) ;
fprintf ( V_134 , L_90
L_91
L_92
L_93 ) ;
fprintf ( V_134 ,
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
fclose ( V_134 ) ;
fprintf ( V_135 , L_111 , V_131 ) ;
return 0 ;
}
