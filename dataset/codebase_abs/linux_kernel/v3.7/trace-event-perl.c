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
struct V_65 * V_66 )
{
struct V_67 * V_20 ;
static char V_68 [ 256 ] ;
unsigned long long V_69 ;
unsigned long V_70 , V_71 ;
struct V_24 * V_25 ;
int V_72 ;
int V_73 = V_63 -> V_73 ;
void * V_74 = V_63 -> V_75 ;
unsigned long long V_76 = V_63 -> time ;
struct V_77 * V_77 = V_66 -> V_77 ;
char * V_78 = V_77 -> V_78 ;
V_10 ;
if ( V_54 -> V_55 . type != V_79 )
return;
V_25 = F_20 ( V_54 ) ;
if ( ! V_25 )
F_22 ( L_11 V_80 , V_54 -> V_55 . V_56 ) ;
V_72 = F_23 ( V_25 , L_12 , V_74 ) ;
sprintf ( V_68 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
V_70 = V_76 / V_81 ;
V_71 = V_76 - V_70 * V_81 ;
V_82 -> V_83 = V_74 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_68 , 0 ) ) ) ;
F_6 ( F_7 ( F_24 ( F_25 ( V_82 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_73 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_71 ) ) ) ;
F_6 ( F_7 ( F_24 ( V_72 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_78 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_84 . V_85 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_86 ) {
int V_87 ;
if ( V_20 -> V_35 & V_88 ) {
V_87 = * ( int * ) ( V_74 + V_20 -> V_87 ) ;
V_87 &= 0xffff ;
} else
V_87 = V_20 -> V_87 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_74 + V_87 , 0 ) ) ) ;
} else {
V_69 = F_26 ( V_25 , V_74 + V_20 -> V_87 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_89 ) {
F_6 ( F_7 ( F_24 ( V_69 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_69 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_68 , 0 ) )
F_11 ( V_68 , V_15 ) ;
else if ( F_10 ( L_13 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_68 , 0 ) ) ) ;
F_6 ( F_7 ( F_24 ( F_25 ( V_82 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_73 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_76 ) ) ) ;
F_6 ( F_7 ( F_24 ( V_72 ) ) ) ;
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
struct V_65 * V_66 V_61 )
{
V_10 ;
if ( ! F_10 ( L_14 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_25 , V_25 -> V_90 . V_41 ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) & V_54 -> V_55 , sizeof( V_54 -> V_55 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_63 , sizeof( * V_63 ) ) ) ) ;
F_6 ( F_7 ( F_28 ( ( const char * ) V_63 -> V_75 , V_63 -> V_91 ) ) ) ;
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
struct V_65 * V_66 )
{
F_21 ( V_25 , V_63 , V_54 , V_64 , V_66 ) ;
F_27 ( V_25 , V_63 , V_54 , V_64 , V_66 ) ;
}
static void F_30 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_15 , 0 ) )
F_11 ( L_15 , V_92 | V_93 ) ;
}
static int F_31 ( const char * V_94 , int V_95 , const char * * V_96 )
{
const char * * V_97 ;
int V_98 , V_99 = 0 ;
V_97 = malloc ( ( V_95 + 2 ) * sizeof( const char * ) ) ;
V_97 [ 0 ] = L_16 ;
V_97 [ 1 ] = V_94 ;
for ( V_98 = 2 ; V_98 < V_95 + 2 ; V_98 ++ )
V_97 [ V_98 ] = V_96 [ V_98 - 2 ] ;
V_100 = F_32 () ;
F_33 ( V_100 ) ;
if ( F_34 ( V_100 , F_1 , V_95 + 2 , ( char * * ) V_97 ,
( char * * ) NULL ) ) {
V_99 = - 1 ;
goto error;
}
if ( F_35 ( V_100 ) ) {
V_99 = - 1 ;
goto error;
}
if ( F_36 ( V_101 ) ) {
V_99 = - 1 ;
goto error;
}
F_30 () ;
free ( V_97 ) ;
return 0 ;
error:
F_37 ( V_100 ) ;
free ( V_97 ) ;
return V_99 ;
}
static int F_38 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_17 , 0 ) )
F_11 ( L_17 , V_92 | V_93 ) ;
F_39 ( V_100 ) ;
F_37 ( V_100 ) ;
return 0 ;
}
static int F_40 ( struct V_102 * V_102 , const char * V_103 )
{
struct V_24 * V_25 = NULL ;
struct V_67 * V_104 ;
char V_105 [ V_106 ] ;
int V_107 , V_108 ;
T_2 * V_109 ;
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
while ( ( V_25 = F_41 ( V_102 , V_25 ) ) ) {
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
for ( V_104 = V_25 -> V_84 . V_85 ; V_104 ; V_104 = V_104 -> V_22 ) {
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
for ( V_104 = V_25 -> V_84 . V_85 ; V_104 ; V_104 = V_104 -> V_22 ) {
if ( V_107 ++ )
fprintf ( V_109 , L_52 ) ;
if ( V_108 && V_108 % 4 == 0 ) {
fprintf ( V_109 , L_60 ) ;
}
V_108 ++ ;
fprintf ( V_109 , L_61 , V_104 -> V_33 ) ;
if ( V_104 -> V_35 & V_86 ||
V_104 -> V_35 & V_111 ||
V_104 -> V_35 & V_112 )
fprintf ( V_109 , L_62 ) ;
else if ( V_104 -> V_35 & V_89 )
fprintf ( V_109 , L_63 ) ;
else
fprintf ( V_109 , L_64 ) ;
}
fprintf ( V_109 , L_65 ) ;
V_107 = 0 ;
V_108 = 0 ;
for ( V_104 = V_25 -> V_84 . V_85 ; V_104 ; V_104 = V_104 -> V_22 ) {
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
