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
if ( V_29 )
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
break;
case V_45 :
F_17 ( V_25 , V_5 , args -> V_46 . V_47 ) ;
break;
case V_48 :
if ( strcmp ( args -> V_49 . V_49 , L_8 ) == 0 )
V_31 = 1 ;
F_17 ( V_25 , V_5 , args -> V_49 . V_50 ) ;
F_17 ( V_25 , V_5 , args -> V_49 . V_51 ) ;
break;
case V_52 :
default:
F_19 ( L_9 ) ;
return;
}
if ( args -> V_22 )
F_17 ( V_25 , V_5 , args -> V_22 ) ;
}
static inline struct V_24 * F_20 ( struct V_53 * V_54 )
{
static char V_5 [ 256 ] ;
struct V_24 * V_25 ;
int type = V_54 -> V_55 . V_56 ;
if ( V_57 [ type ] )
return V_57 [ type ] ;
V_57 [ type ] = V_25 = V_54 -> V_58 ;
if ( ! V_25 )
return NULL ;
sprintf ( V_5 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
F_17 ( V_25 , V_5 , V_25 -> V_59 . args ) ;
return V_25 ;
}
static void F_21 ( union V_60 * V_60 V_61 ,
struct V_62 * V_63 ,
struct V_53 * V_54 ,
struct V_64 * V_64 V_61 ,
struct V_65 * V_65 ,
struct V_66 * V_67 )
{
struct V_68 * V_20 ;
static char V_69 [ 256 ] ;
unsigned long long V_70 ;
unsigned long V_71 , V_72 ;
struct V_24 * V_25 ;
int V_73 ;
int V_74 = V_63 -> V_74 ;
void * V_75 = V_63 -> V_76 ;
unsigned long long V_77 = V_63 -> time ;
char * V_78 = V_65 -> V_78 ;
V_10 ;
if ( V_54 -> V_55 . type != V_79 )
return;
V_25 = F_20 ( V_54 ) ;
if ( ! V_25 )
F_22 ( L_11 V_80 , ( V_81 ) V_54 -> V_55 . V_56 ) ;
V_73 = F_23 ( V_25 , L_12 , V_75 ) ;
sprintf ( V_69 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
V_71 = V_77 / V_82 ;
V_72 = V_77 - V_71 * V_82 ;
V_83 -> V_84 = V_75 ;
V_83 -> V_85 = V_54 -> V_58 -> V_85 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_69 , 0 ) ) ) ;
F_6 ( F_7 ( F_24 ( F_25 ( V_83 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_74 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_71 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_72 ) ) ) ;
F_6 ( F_7 ( F_24 ( V_73 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_78 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_86 . V_87 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_88 ) {
int V_89 ;
if ( V_20 -> V_35 & V_90 ) {
V_89 = * ( int * ) ( V_75 + V_20 -> V_89 ) ;
V_89 &= 0xffff ;
} else
V_89 = V_20 -> V_89 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_75 + V_89 , 0 ) ) ) ;
} else {
V_70 = F_26 ( V_25 , V_75 + V_20 -> V_89 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_91 ) {
F_6 ( F_7 ( F_24 ( V_70 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_69 , 0 ) )
F_11 ( V_69 , V_15 ) ;
else if ( F_10 ( L_13 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_69 , 0 ) ) ) ;
F_6 ( F_7 ( F_24 ( F_25 ( V_83 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_74 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_77 ) ) ) ;
F_6 ( F_7 ( F_24 ( V_73 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_78 , 0 ) ) ) ;
F_11 ( L_13 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_27 ( union V_60 * V_25 ,
struct V_62 * V_63 ,
struct V_53 * V_54 ,
struct V_64 * V_64 V_61 ,
struct V_65 * V_65 V_61 ,
struct V_66 * V_67 V_61 )
{
V_10 ;
if ( ! F_10 ( L_14 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_25 , V_25 -> V_92 . V_41 ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) & V_54 -> V_55 , sizeof( V_54 -> V_55 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_63 , sizeof( * V_63 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_63 -> V_76 , V_63 -> V_93 ) ) ) ;
V_14 ;
F_11 ( L_14 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_29 ( union V_60 * V_25 ,
struct V_62 * V_63 ,
struct V_53 * V_54 ,
struct V_64 * V_64 ,
struct V_65 * V_65 ,
struct V_66 * V_67 )
{
F_21 ( V_25 , V_63 , V_54 , V_64 , V_65 , V_67 ) ;
F_27 ( V_25 , V_63 , V_54 , V_64 , V_65 , V_67 ) ;
}
static void F_30 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_15 , 0 ) )
F_11 ( L_15 , V_94 | V_95 ) ;
}
static int F_31 ( const char * V_96 , int V_97 , const char * * V_98 )
{
const char * * V_99 ;
int V_100 , V_101 = 0 ;
V_99 = malloc ( ( V_97 + 2 ) * sizeof( const char * ) ) ;
V_99 [ 0 ] = L_16 ;
V_99 [ 1 ] = V_96 ;
for ( V_100 = 2 ; V_100 < V_97 + 2 ; V_100 ++ )
V_99 [ V_100 ] = V_98 [ V_100 - 2 ] ;
V_102 = F_32 () ;
F_33 ( V_102 ) ;
if ( F_34 ( V_102 , F_1 , V_97 + 2 , ( char * * ) V_99 ,
( char * * ) NULL ) ) {
V_101 = - 1 ;
goto error;
}
if ( F_35 ( V_102 ) ) {
V_101 = - 1 ;
goto error;
}
if ( F_36 ( V_103 ) ) {
V_101 = - 1 ;
goto error;
}
F_30 () ;
free ( V_99 ) ;
return 0 ;
error:
F_37 ( V_102 ) ;
free ( V_99 ) ;
return V_101 ;
}
static int F_38 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_17 , 0 ) )
F_11 ( L_17 , V_94 | V_95 ) ;
F_39 ( V_102 ) ;
F_37 ( V_102 ) ;
return 0 ;
}
static int F_40 ( struct V_85 * V_85 , const char * V_104 )
{
struct V_24 * V_25 = NULL ;
struct V_68 * V_105 ;
char V_106 [ V_107 ] ;
int V_108 , V_109 ;
T_2 * V_110 ;
sprintf ( V_106 , L_18 , V_104 ) ;
V_110 = fopen ( V_106 , L_19 ) ;
if ( V_110 == NULL ) {
fprintf ( V_111 , L_20 , V_106 ) ;
return - 1 ;
}
fprintf ( V_110 , L_21
L_22 ) ;
fprintf ( V_110 , L_23
L_24 ) ;
fprintf ( V_110 , L_25
L_26 ) ;
fprintf ( V_110 , L_27
L_28 ) ;
fprintf ( V_110 , L_29
L_30 ) ;
fprintf ( V_110 , L_31
L_32 ) ;
fprintf ( V_110 , L_33
L_34 ) ;
fprintf ( V_110 , L_35
L_36 ) ;
fprintf ( V_110 , L_37 ) ;
fprintf ( V_110 , L_38 ) ;
fprintf ( V_110 , L_39 ) ;
fprintf ( V_110 , L_40 ) ;
fprintf ( V_110 , L_41 ) ;
fprintf ( V_110 , L_42 ) ;
while ( ( V_25 = F_41 ( V_85 , V_25 ) ) ) {
fprintf ( V_110 , L_43 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_110 , L_44 ) ;
fprintf ( V_110 , L_45 ) ;
fprintf ( V_110 , L_46 ) ;
fprintf ( V_110 , L_47 ) ;
fprintf ( V_110 , L_48 ) ;
fprintf ( V_110 , L_49 ) ;
fprintf ( V_110 , L_50 ) ;
fprintf ( V_110 , L_51 ) ;
V_108 = 0 ;
V_109 = 0 ;
for ( V_105 = V_25 -> V_86 . V_87 ; V_105 ; V_105 = V_105 -> V_22 ) {
if ( V_108 ++ )
fprintf ( V_110 , L_52 ) ;
if ( ++ V_109 % 5 == 0 )
fprintf ( V_110 , L_53 ) ;
fprintf ( V_110 , L_54 , V_105 -> V_33 ) ;
}
fprintf ( V_110 , L_55 ) ;
fprintf ( V_110 , L_56
L_57
L_58 ) ;
fprintf ( V_110 , L_59 ) ;
V_108 = 0 ;
V_109 = 0 ;
for ( V_105 = V_25 -> V_86 . V_87 ; V_105 ; V_105 = V_105 -> V_22 ) {
if ( V_108 ++ )
fprintf ( V_110 , L_52 ) ;
if ( V_109 && V_109 % 4 == 0 ) {
fprintf ( V_110 , L_60 ) ;
}
V_109 ++ ;
fprintf ( V_110 , L_61 , V_105 -> V_33 ) ;
if ( V_105 -> V_35 & V_88 ||
V_105 -> V_35 & V_112 ||
V_105 -> V_35 & V_113 )
fprintf ( V_110 , L_62 ) ;
else if ( V_105 -> V_35 & V_91 )
fprintf ( V_110 , L_63 ) ;
else
fprintf ( V_110 , L_64 ) ;
}
fprintf ( V_110 , L_65 ) ;
V_108 = 0 ;
V_109 = 0 ;
for ( V_105 = V_25 -> V_86 . V_87 ; V_105 ; V_105 = V_105 -> V_22 ) {
if ( V_108 ++ )
fprintf ( V_110 , L_52 ) ;
if ( ++ V_109 % 5 == 0 )
fprintf ( V_110 , L_66 ) ;
if ( V_105 -> V_35 & V_112 ) {
if ( ( V_109 - 1 ) % 5 != 0 ) {
fprintf ( V_110 , L_66 ) ;
V_109 = 4 ;
}
fprintf ( V_110 , L_67 ) ;
fprintf ( V_110 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_110 , L_69 , V_105 -> V_33 ,
V_105 -> V_33 ) ;
} else if ( V_105 -> V_35 & V_113 ) {
if ( ( V_109 - 1 ) % 5 != 0 ) {
fprintf ( V_110 , L_66 ) ;
V_109 = 4 ;
}
fprintf ( V_110 , L_70 ) ;
fprintf ( V_110 , L_68 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_110 , L_69 , V_105 -> V_33 ,
V_105 -> V_33 ) ;
} else
fprintf ( V_110 , L_54 , V_105 -> V_33 ) ;
}
fprintf ( V_110 , L_71 ) ;
fprintf ( V_110 , L_72 ) ;
}
fprintf ( V_110 , L_73
L_74
L_75 ) ;
fprintf ( V_110 , L_56
L_76
L_77 ) ;
fprintf ( V_110 , L_78
L_79
L_80
L_81 ) ;
fprintf ( V_110 ,
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
fclose ( V_110 ) ;
fprintf ( V_111 , L_99 , V_106 ) ;
return 0 ;
}
