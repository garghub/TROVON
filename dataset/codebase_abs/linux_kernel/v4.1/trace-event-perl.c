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
break;
case V_50 :
F_17 ( V_25 , V_5 , args -> V_51 . V_52 ) ;
break;
case V_53 :
if ( strcmp ( args -> V_54 . V_54 , L_8 ) == 0 )
V_31 = 1 ;
F_17 ( V_25 , V_5 , args -> V_54 . V_55 ) ;
F_17 ( V_25 , V_5 , args -> V_54 . V_56 ) ;
break;
case V_57 :
default:
F_19 ( L_9 ) ;
return;
}
if ( args -> V_22 )
F_17 ( V_25 , V_5 , args -> V_22 ) ;
}
static void F_20 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_62 )
{
struct V_24 * V_25 = V_61 -> V_63 ;
struct V_64 * V_20 ;
static char V_65 [ 256 ] ;
unsigned long long V_66 ;
unsigned long V_67 , V_68 ;
int V_69 ;
int V_70 = V_59 -> V_70 ;
void * V_71 = V_59 -> V_72 ;
unsigned long long V_73 = V_59 -> time ;
const char * V_74 = F_21 ( V_62 ) ;
V_10 ;
if ( V_61 -> V_75 . type != V_76 )
return;
if ( ! V_25 )
F_22 ( L_10 V_77 , ( V_78 ) V_61 -> V_75 . V_79 ) ;
V_69 = F_23 ( V_25 , L_11 , V_71 ) ;
sprintf ( V_65 , L_12 , V_25 -> system , V_25 -> V_33 ) ;
if ( ! F_24 ( V_25 -> V_80 , V_81 ) )
F_17 ( V_25 , V_65 , V_25 -> V_82 . args ) ;
V_67 = V_73 / V_83 ;
V_68 = V_73 - V_67 * V_83 ;
V_84 -> V_85 = V_71 ;
V_84 -> V_86 = V_61 -> V_63 -> V_86 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_65 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_84 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_67 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_68 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_74 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_87 . V_88 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_89 ) {
int V_90 ;
if ( V_20 -> V_35 & V_91 ) {
V_90 = * ( int * ) ( V_71 + V_20 -> V_90 ) ;
V_90 &= 0xffff ;
} else
V_90 = V_20 -> V_90 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_71 + V_90 , 0 ) ) ) ;
} else {
V_66 = F_27 ( V_25 , V_71 + V_20 -> V_90 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_92 ) {
F_6 ( F_7 ( F_25 ( V_66 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_66 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_65 , 0 ) )
F_11 ( V_65 , V_15 ) ;
else if ( F_10 ( L_13 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_65 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_84 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_73 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_74 , 0 ) ) ) ;
F_11 ( L_13 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_28 ( union V_93 * V_25 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_10 ;
if ( ! F_10 ( L_14 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_25 , V_25 -> V_94 . V_41 ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) & V_61 -> V_75 , sizeof( V_61 -> V_75 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_59 , sizeof( * V_59 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_59 -> V_72 , V_59 -> V_95 ) ) ) ;
V_14 ;
F_11 ( L_14 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_30 ( union V_93 * V_25 ,
struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_96 * V_97 )
{
F_20 ( V_59 , V_61 , V_97 -> V_62 ) ;
F_28 ( V_25 , V_59 , V_61 ) ;
}
static void F_31 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_15 , 0 ) )
F_11 ( L_15 , V_98 | V_99 ) ;
}
static int F_32 ( const char * V_100 , int V_101 , const char * * V_102 )
{
const char * * V_103 ;
int V_104 , V_105 = 0 ;
V_103 = malloc ( ( V_101 + 2 ) * sizeof( const char * ) ) ;
V_103 [ 0 ] = L_16 ;
V_103 [ 1 ] = V_100 ;
for ( V_104 = 2 ; V_104 < V_101 + 2 ; V_104 ++ )
V_103 [ V_104 ] = V_102 [ V_104 - 2 ] ;
V_106 = F_33 () ;
F_34 ( V_106 ) ;
if ( F_35 ( V_106 , F_1 , V_101 + 2 , ( char * * ) V_103 ,
( char * * ) NULL ) ) {
V_105 = - 1 ;
goto error;
}
if ( F_36 ( V_106 ) ) {
V_105 = - 1 ;
goto error;
}
if ( F_37 ( V_107 ) ) {
V_105 = - 1 ;
goto error;
}
F_31 () ;
free ( V_103 ) ;
return 0 ;
error:
F_38 ( V_106 ) ;
free ( V_103 ) ;
return V_105 ;
}
static int F_39 ( void )
{
return 0 ;
}
static int F_40 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_17 , 0 ) )
F_11 ( L_17 , V_98 | V_99 ) ;
F_41 ( V_106 ) ;
F_38 ( V_106 ) ;
return 0 ;
}
static int F_42 ( struct V_86 * V_86 , const char * V_108 )
{
struct V_24 * V_25 = NULL ;
struct V_64 * V_109 ;
char V_110 [ V_111 ] ;
int V_112 , V_44 ;
T_2 * V_113 ;
sprintf ( V_110 , L_18 , V_108 ) ;
V_113 = fopen ( V_110 , L_19 ) ;
if ( V_113 == NULL ) {
fprintf ( V_114 , L_20 , V_110 ) ;
return - 1 ;
}
fprintf ( V_113 , L_21
L_22 ) ;
fprintf ( V_113 , L_23
L_24 ) ;
fprintf ( V_113 , L_25
L_26 ) ;
fprintf ( V_113 , L_27
L_28 ) ;
fprintf ( V_113 , L_29
L_30 ) ;
fprintf ( V_113 , L_31
L_32 ) ;
fprintf ( V_113 , L_33
L_34 ) ;
fprintf ( V_113 , L_35
L_36 ) ;
fprintf ( V_113 , L_37 ) ;
fprintf ( V_113 , L_38 ) ;
fprintf ( V_113 , L_39 ) ;
fprintf ( V_113 , L_40 ) ;
fprintf ( V_113 , L_41 ) ;
fprintf ( V_113 , L_42 ) ;
while ( ( V_25 = F_43 ( V_86 , V_25 ) ) ) {
fprintf ( V_113 , L_43 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_113 , L_44 ) ;
fprintf ( V_113 , L_45 ) ;
fprintf ( V_113 , L_46 ) ;
fprintf ( V_113 , L_47 ) ;
fprintf ( V_113 , L_48 ) ;
fprintf ( V_113 , L_49 ) ;
fprintf ( V_113 , L_50 ) ;
fprintf ( V_113 , L_51 ) ;
V_112 = 0 ;
V_44 = 0 ;
for ( V_109 = V_25 -> V_87 . V_88 ; V_109 ; V_109 = V_109 -> V_22 ) {
if ( V_112 ++ )
fprintf ( V_113 , L_52 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_113 , L_53 ) ;
fprintf ( V_113 , L_54 , V_109 -> V_33 ) ;
}
fprintf ( V_113 , L_55 ) ;
fprintf ( V_113 , L_56
L_57
L_58 ) ;
fprintf ( V_113 , L_59 ) ;
V_112 = 0 ;
V_44 = 0 ;
for ( V_109 = V_25 -> V_87 . V_88 ; V_109 ; V_109 = V_109 -> V_22 ) {
if ( V_112 ++ )
fprintf ( V_113 , L_52 ) ;
if ( V_44 && V_44 % 4 == 0 ) {
fprintf ( V_113 , L_60 ) ;
}
V_44 ++ ;
fprintf ( V_113 , L_61 , V_109 -> V_33 ) ;
if ( V_109 -> V_35 & V_89 ||
V_109 -> V_35 & V_115 ||
V_109 -> V_35 & V_116 )
fprintf ( V_113 , L_62 ) ;
else if ( V_109 -> V_35 & V_92 )
fprintf ( V_113 , L_63 ) ;
else
fprintf ( V_113 , L_64 ) ;
}
fprintf ( V_113 , L_65 ) ;
V_112 = 0 ;
V_44 = 0 ;
for ( V_109 = V_25 -> V_87 . V_88 ; V_109 ; V_109 = V_109 -> V_22 ) {
if ( V_112 ++ )
fprintf ( V_113 , L_52 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_113 , L_66 ) ;
if ( V_109 -> V_35 & V_115 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_113 , L_66 ) ;
V_44 = 4 ;
}
fprintf ( V_113 , L_67 ) ;
fprintf ( V_113 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_113 , L_69 , V_109 -> V_33 ,
V_109 -> V_33 ) ;
} else if ( V_109 -> V_35 & V_116 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_113 , L_66 ) ;
V_44 = 4 ;
}
fprintf ( V_113 , L_70 ) ;
fprintf ( V_113 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_113 , L_69 , V_109 -> V_33 ,
V_109 -> V_33 ) ;
} else
fprintf ( V_113 , L_54 , V_109 -> V_33 ) ;
}
fprintf ( V_113 , L_71 ) ;
fprintf ( V_113 , L_72 ) ;
}
fprintf ( V_113 , L_73
L_74
L_75 ) ;
fprintf ( V_113 , L_56
L_76
L_77 ) ;
fprintf ( V_113 , L_78
L_79
L_80
L_81 ) ;
fprintf ( V_113 ,
L_82
L_83
L_84
L_85
L_86
L_87
L_88
L_89
L_90
L_91
L_88
L_92
L_93
L_94
L_95
L_88
L_96
L_97
L_98 ) ;
fclose ( V_113 ) ;
fprintf ( V_114 , L_99 , V_110 ) ;
return 0 ;
}
