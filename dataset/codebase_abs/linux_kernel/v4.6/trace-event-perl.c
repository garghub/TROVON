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
static void F_20 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_63 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
struct V_65 * V_20 ;
static char V_66 [ 256 ] ;
unsigned long long V_67 ;
unsigned long V_68 , V_69 ;
int V_70 ;
int V_71 = V_60 -> V_71 ;
void * V_72 = V_60 -> V_73 ;
unsigned long long V_74 = V_60 -> time ;
const char * V_75 = F_21 ( V_63 ) ;
V_10 ;
if ( V_62 -> V_76 . type != V_77 )
return;
if ( ! V_25 )
F_22 ( L_10 V_78 , ( V_79 ) V_62 -> V_76 . V_80 ) ;
V_70 = F_23 ( V_25 , L_11 , V_72 ) ;
sprintf ( V_66 , L_12 , V_25 -> system , V_25 -> V_33 ) ;
if ( ! F_24 ( V_25 -> V_81 , V_82 ) )
F_17 ( V_25 , V_66 , V_25 -> V_83 . args ) ;
V_68 = V_74 / V_84 ;
V_69 = V_74 - V_68 * V_84 ;
V_85 -> V_86 = V_72 ;
V_85 -> V_87 = V_62 -> V_64 -> V_87 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_66 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_85 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_71 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_68 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_75 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_88 . V_89 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_90 ) {
int V_91 ;
if ( V_20 -> V_35 & V_92 ) {
V_91 = * ( int * ) ( V_72 + V_20 -> V_91 ) ;
V_91 &= 0xffff ;
} else
V_91 = V_20 -> V_91 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_72 + V_91 , 0 ) ) ) ;
} else {
V_67 = F_27 ( V_25 , V_72 + V_20 -> V_91 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_93 ) {
F_6 ( F_7 ( F_25 ( V_67 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_67 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_66 , 0 ) )
F_11 ( V_66 , V_15 ) ;
else if ( F_10 ( L_13 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_66 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_85 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_71 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_74 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_75 , 0 ) ) ) ;
F_11 ( L_13 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_28 ( union V_94 * V_25 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
V_10 ;
if ( ! F_10 ( L_14 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_25 , V_25 -> V_95 . V_41 ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) & V_62 -> V_76 , sizeof( V_62 -> V_76 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_60 , sizeof( * V_60 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_60 -> V_73 , V_60 -> V_96 ) ) ) ;
V_14 ;
F_11 ( L_14 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_30 ( union V_94 * V_25 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_97 * V_98 )
{
F_20 ( V_60 , V_62 , V_98 -> V_63 ) ;
F_28 ( V_25 , V_60 , V_62 ) ;
}
static void F_31 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_15 , 0 ) )
F_11 ( L_15 , V_99 | V_100 ) ;
}
static int F_32 ( const char * V_101 , int V_102 , const char * * V_103 )
{
const char * * V_104 ;
int V_105 , V_106 = 0 ;
V_104 = malloc ( ( V_102 + 2 ) * sizeof( const char * ) ) ;
V_104 [ 0 ] = L_16 ;
V_104 [ 1 ] = V_101 ;
for ( V_105 = 2 ; V_105 < V_102 + 2 ; V_105 ++ )
V_104 [ V_105 ] = V_103 [ V_105 - 2 ] ;
V_107 = F_33 () ;
F_34 ( V_107 ) ;
if ( F_35 ( V_107 , F_1 , V_102 + 2 , ( char * * ) V_104 ,
( char * * ) NULL ) ) {
V_106 = - 1 ;
goto error;
}
if ( F_36 ( V_107 ) ) {
V_106 = - 1 ;
goto error;
}
if ( F_37 ( V_108 ) ) {
V_106 = - 1 ;
goto error;
}
F_31 () ;
free ( V_104 ) ;
return 0 ;
error:
F_38 ( V_107 ) ;
free ( V_104 ) ;
return V_106 ;
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
F_11 ( L_17 , V_99 | V_100 ) ;
F_41 ( V_107 ) ;
F_38 ( V_107 ) ;
return 0 ;
}
static int F_42 ( struct V_87 * V_87 , const char * V_109 )
{
struct V_24 * V_25 = NULL ;
struct V_65 * V_110 ;
char V_111 [ V_112 ] ;
int V_113 , V_44 ;
T_2 * V_114 ;
sprintf ( V_111 , L_18 , V_109 ) ;
V_114 = fopen ( V_111 , L_19 ) ;
if ( V_114 == NULL ) {
fprintf ( V_115 , L_20 , V_111 ) ;
return - 1 ;
}
fprintf ( V_114 , L_21
L_22 ) ;
fprintf ( V_114 , L_23
L_24 ) ;
fprintf ( V_114 , L_25
L_26 ) ;
fprintf ( V_114 , L_27
L_28 ) ;
fprintf ( V_114 , L_29
L_30 ) ;
fprintf ( V_114 , L_31
L_32 ) ;
fprintf ( V_114 , L_33
L_34 ) ;
fprintf ( V_114 , L_35
L_36 ) ;
fprintf ( V_114 , L_37 ) ;
fprintf ( V_114 , L_38 ) ;
fprintf ( V_114 , L_39 ) ;
fprintf ( V_114 , L_40 ) ;
fprintf ( V_114 , L_41 ) ;
fprintf ( V_114 , L_42 ) ;
while ( ( V_25 = F_43 ( V_87 , V_25 ) ) ) {
fprintf ( V_114 , L_43 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_114 , L_44 ) ;
fprintf ( V_114 , L_45 ) ;
fprintf ( V_114 , L_46 ) ;
fprintf ( V_114 , L_47 ) ;
fprintf ( V_114 , L_48 ) ;
fprintf ( V_114 , L_49 ) ;
fprintf ( V_114 , L_50 ) ;
fprintf ( V_114 , L_51 ) ;
V_113 = 0 ;
V_44 = 0 ;
for ( V_110 = V_25 -> V_88 . V_89 ; V_110 ; V_110 = V_110 -> V_22 ) {
if ( V_113 ++ )
fprintf ( V_114 , L_52 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_114 , L_53 ) ;
fprintf ( V_114 , L_54 , V_110 -> V_33 ) ;
}
fprintf ( V_114 , L_55 ) ;
fprintf ( V_114 , L_56
L_57
L_58 ) ;
fprintf ( V_114 , L_59 ) ;
V_113 = 0 ;
V_44 = 0 ;
for ( V_110 = V_25 -> V_88 . V_89 ; V_110 ; V_110 = V_110 -> V_22 ) {
if ( V_113 ++ )
fprintf ( V_114 , L_52 ) ;
if ( V_44 && V_44 % 4 == 0 ) {
fprintf ( V_114 , L_60 ) ;
}
V_44 ++ ;
fprintf ( V_114 , L_61 , V_110 -> V_33 ) ;
if ( V_110 -> V_35 & V_90 ||
V_110 -> V_35 & V_116 ||
V_110 -> V_35 & V_117 )
fprintf ( V_114 , L_62 ) ;
else if ( V_110 -> V_35 & V_93 )
fprintf ( V_114 , L_63 ) ;
else
fprintf ( V_114 , L_64 ) ;
}
fprintf ( V_114 , L_65 ) ;
V_113 = 0 ;
V_44 = 0 ;
for ( V_110 = V_25 -> V_88 . V_89 ; V_110 ; V_110 = V_110 -> V_22 ) {
if ( V_113 ++ )
fprintf ( V_114 , L_52 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_114 , L_66 ) ;
if ( V_110 -> V_35 & V_116 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_114 , L_66 ) ;
V_44 = 4 ;
}
fprintf ( V_114 , L_67 ) ;
fprintf ( V_114 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_114 , L_69 , V_110 -> V_33 ,
V_110 -> V_33 ) ;
} else if ( V_110 -> V_35 & V_117 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_114 , L_66 ) ;
V_44 = 4 ;
}
fprintf ( V_114 , L_70 ) ;
fprintf ( V_114 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_114 , L_69 , V_110 -> V_33 ,
V_110 -> V_33 ) ;
} else
fprintf ( V_114 , L_54 , V_110 -> V_33 ) ;
}
fprintf ( V_114 , L_71 ) ;
fprintf ( V_114 , L_72 ) ;
}
fprintf ( V_114 , L_73
L_74
L_75 ) ;
fprintf ( V_114 , L_56
L_76
L_77 ) ;
fprintf ( V_114 , L_78
L_79
L_80
L_81 ) ;
fprintf ( V_114 ,
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
fclose ( V_114 ) ;
fprintf ( V_115 , L_99 , V_111 ) ;
return 0 ;
}
