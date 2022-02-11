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
case V_43 :
case V_44 :
case V_45 :
break;
case V_46 :
F_17 ( V_25 , V_5 , args -> V_47 . V_48 ) ;
break;
case V_49 :
if ( strcmp ( args -> V_50 . V_50 , L_8 ) == 0 )
V_31 = 1 ;
F_17 ( V_25 , V_5 , args -> V_50 . V_51 ) ;
F_17 ( V_25 , V_5 , args -> V_50 . V_52 ) ;
break;
case V_53 :
default:
F_19 ( L_9 ) ;
return;
}
if ( args -> V_22 )
F_17 ( V_25 , V_5 , args -> V_22 ) ;
}
static inline struct V_24 * F_20 ( struct V_54 * V_55 )
{
static char V_5 [ 256 ] ;
struct V_24 * V_25 ;
int type = V_55 -> V_56 . V_57 ;
if ( V_58 [ type ] )
return V_58 [ type ] ;
V_58 [ type ] = V_25 = V_55 -> V_59 ;
if ( ! V_25 )
return NULL ;
sprintf ( V_5 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
F_17 ( V_25 , V_5 , V_25 -> V_60 . args ) ;
return V_25 ;
}
static void F_21 ( struct V_61 * V_62 ,
struct V_54 * V_55 ,
struct V_63 * V_63 )
{
struct V_64 * V_20 ;
static char V_65 [ 256 ] ;
unsigned long long V_66 ;
unsigned long V_67 , V_68 ;
struct V_24 * V_25 ;
int V_69 ;
int V_70 = V_62 -> V_70 ;
void * V_71 = V_62 -> V_72 ;
unsigned long long V_73 = V_62 -> time ;
const char * V_74 = F_22 ( V_63 ) ;
V_10 ;
if ( V_55 -> V_56 . type != V_75 )
return;
V_25 = F_20 ( V_55 ) ;
if ( ! V_25 )
F_23 ( L_11 V_76 , ( V_77 ) V_55 -> V_56 . V_57 ) ;
V_69 = F_24 ( V_25 , L_12 , V_71 ) ;
sprintf ( V_65 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
V_67 = V_73 / V_78 ;
V_68 = V_73 - V_67 * V_78 ;
V_79 -> V_80 = V_71 ;
V_79 -> V_81 = V_55 -> V_59 -> V_81 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_65 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_79 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_67 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_68 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_74 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_82 . V_83 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_84 ) {
int V_85 ;
if ( V_20 -> V_35 & V_86 ) {
V_85 = * ( int * ) ( V_71 + V_20 -> V_85 ) ;
V_85 &= 0xffff ;
} else
V_85 = V_20 -> V_85 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_71 + V_85 , 0 ) ) ) ;
} else {
V_66 = F_27 ( V_25 , V_71 + V_20 -> V_85 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_87 ) {
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
F_6 ( F_7 ( F_25 ( F_26 ( V_79 ) ) ) ) ;
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
static void F_28 ( union V_88 * V_25 ,
struct V_61 * V_62 ,
struct V_54 * V_55 )
{
V_10 ;
if ( ! F_10 ( L_14 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_25 , V_25 -> V_89 . V_41 ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) & V_55 -> V_56 , sizeof( V_55 -> V_56 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_62 , sizeof( * V_62 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_62 -> V_72 , V_62 -> V_90 ) ) ) ;
V_14 ;
F_11 ( L_14 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_30 ( union V_88 * V_25 ,
struct V_61 * V_62 ,
struct V_54 * V_55 ,
struct V_63 * V_63 ,
struct V_91 * T_2 V_92 )
{
F_21 ( V_62 , V_55 , V_63 ) ;
F_28 ( V_25 , V_62 , V_55 ) ;
}
static void F_31 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_15 , 0 ) )
F_11 ( L_15 , V_93 | V_94 ) ;
}
static int F_32 ( const char * V_95 , int V_96 , const char * * V_97 )
{
const char * * V_98 ;
int V_99 , V_100 = 0 ;
V_98 = malloc ( ( V_96 + 2 ) * sizeof( const char * ) ) ;
V_98 [ 0 ] = L_16 ;
V_98 [ 1 ] = V_95 ;
for ( V_99 = 2 ; V_99 < V_96 + 2 ; V_99 ++ )
V_98 [ V_99 ] = V_97 [ V_99 - 2 ] ;
V_101 = F_33 () ;
F_34 ( V_101 ) ;
if ( F_35 ( V_101 , F_1 , V_96 + 2 , ( char * * ) V_98 ,
( char * * ) NULL ) ) {
V_100 = - 1 ;
goto error;
}
if ( F_36 ( V_101 ) ) {
V_100 = - 1 ;
goto error;
}
if ( F_37 ( V_102 ) ) {
V_100 = - 1 ;
goto error;
}
F_31 () ;
free ( V_98 ) ;
return 0 ;
error:
F_38 ( V_101 ) ;
free ( V_98 ) ;
return V_100 ;
}
static int F_39 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_17 , 0 ) )
F_11 ( L_17 , V_93 | V_94 ) ;
F_40 ( V_101 ) ;
F_38 ( V_101 ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_81 , const char * V_103 )
{
struct V_24 * V_25 = NULL ;
struct V_64 * V_104 ;
char V_105 [ V_106 ] ;
int V_107 , V_108 ;
T_3 * V_109 ;
sprintf ( V_105 , L_18 , V_103 ) ;
V_109 = fopen ( V_105 , L_19 ) ;
if ( V_109 == NULL ) {
fprintf ( V_110 , L_20 , V_105 ) ;
return - 1 ;
}
fprintf ( V_109 , L_21
L_22 ) ;
fprintf ( V_109 , L_23
L_24 ) ;
fprintf ( V_109 , L_25
L_26 ) ;
fprintf ( V_109 , L_27
L_28 ) ;
fprintf ( V_109 , L_29
L_30 ) ;
fprintf ( V_109 , L_31
L_32 ) ;
fprintf ( V_109 , L_33
L_34 ) ;
fprintf ( V_109 , L_35
L_36 ) ;
fprintf ( V_109 , L_37 ) ;
fprintf ( V_109 , L_38 ) ;
fprintf ( V_109 , L_39 ) ;
fprintf ( V_109 , L_40 ) ;
fprintf ( V_109 , L_41 ) ;
fprintf ( V_109 , L_42 ) ;
while ( ( V_25 = F_42 ( V_81 , V_25 ) ) ) {
fprintf ( V_109 , L_43 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_109 , L_44 ) ;
fprintf ( V_109 , L_45 ) ;
fprintf ( V_109 , L_46 ) ;
fprintf ( V_109 , L_47 ) ;
fprintf ( V_109 , L_48 ) ;
fprintf ( V_109 , L_49 ) ;
fprintf ( V_109 , L_50 ) ;
fprintf ( V_109 , L_51 ) ;
V_107 = 0 ;
V_108 = 0 ;
for ( V_104 = V_25 -> V_82 . V_83 ; V_104 ; V_104 = V_104 -> V_22 ) {
if ( V_107 ++ )
fprintf ( V_109 , L_52 ) ;
if ( ++ V_108 % 5 == 0 )
fprintf ( V_109 , L_53 ) ;
fprintf ( V_109 , L_54 , V_104 -> V_33 ) ;
}
fprintf ( V_109 , L_55 ) ;
fprintf ( V_109 , L_56
L_57
L_58 ) ;
fprintf ( V_109 , L_59 ) ;
V_107 = 0 ;
V_108 = 0 ;
for ( V_104 = V_25 -> V_82 . V_83 ; V_104 ; V_104 = V_104 -> V_22 ) {
if ( V_107 ++ )
fprintf ( V_109 , L_52 ) ;
if ( V_108 && V_108 % 4 == 0 ) {
fprintf ( V_109 , L_60 ) ;
}
V_108 ++ ;
fprintf ( V_109 , L_61 , V_104 -> V_33 ) ;
if ( V_104 -> V_35 & V_84 ||
V_104 -> V_35 & V_111 ||
V_104 -> V_35 & V_112 )
fprintf ( V_109 , L_62 ) ;
else if ( V_104 -> V_35 & V_87 )
fprintf ( V_109 , L_63 ) ;
else
fprintf ( V_109 , L_64 ) ;
}
fprintf ( V_109 , L_65 ) ;
V_107 = 0 ;
V_108 = 0 ;
for ( V_104 = V_25 -> V_82 . V_83 ; V_104 ; V_104 = V_104 -> V_22 ) {
if ( V_107 ++ )
fprintf ( V_109 , L_52 ) ;
if ( ++ V_108 % 5 == 0 )
fprintf ( V_109 , L_66 ) ;
if ( V_104 -> V_35 & V_111 ) {
if ( ( V_108 - 1 ) % 5 != 0 ) {
fprintf ( V_109 , L_66 ) ;
V_108 = 4 ;
}
fprintf ( V_109 , L_67 ) ;
fprintf ( V_109 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_109 , L_69 , V_104 -> V_33 ,
V_104 -> V_33 ) ;
} else if ( V_104 -> V_35 & V_112 ) {
if ( ( V_108 - 1 ) % 5 != 0 ) {
fprintf ( V_109 , L_66 ) ;
V_108 = 4 ;
}
fprintf ( V_109 , L_70 ) ;
fprintf ( V_109 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_109 , L_69 , V_104 -> V_33 ,
V_104 -> V_33 ) ;
} else
fprintf ( V_109 , L_54 , V_104 -> V_33 ) ;
}
fprintf ( V_109 , L_71 ) ;
fprintf ( V_109 , L_72 ) ;
}
fprintf ( V_109 , L_73
L_74
L_75 ) ;
fprintf ( V_109 , L_56
L_76
L_77 ) ;
fprintf ( V_109 , L_78
L_79
L_80
L_81 ) ;
fprintf ( V_109 ,
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
fclose ( V_109 ) ;
fprintf ( V_110 , L_99 , V_105 ) ;
return 0 ;
}
