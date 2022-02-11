static void F_1 ( const char * V_1 )
{
F_2 () ;
F_3 ( L_1 ) ;
}
static void F_4 ( enum V_2 V_3 ,
const char * V_4 ,
const char * V_5 ,
const char * V_6 ,
const char * V_7 )
{
const char * V_1 = L_2 ;
T_1 * V_8 , * V_9 , * V_10 ;
unsigned long long V_11 ;
unsigned V_12 = 0 ;
if ( V_3 == V_13 )
V_1 = L_3 ;
V_9 = F_5 ( 4 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
V_11 = F_6 ( V_6 ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_4 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_5 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_11 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_7 ) ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( V_8 && F_11 ( V_8 ) ) {
V_10 = F_12 ( V_8 , V_9 ) ;
if ( V_10 == NULL )
F_1 ( V_1 ) ;
}
F_13 ( V_9 ) ;
}
static void F_14 ( enum V_2 V_3 ,
struct V_15 * V_16 ,
const char * V_4 ,
const char * V_5 )
{
F_4 ( V_3 , V_4 , V_5 , V_16 -> V_11 ,
V_16 -> V_17 ) ;
if ( V_16 -> V_18 )
F_14 ( V_3 , V_16 -> V_18 , V_4 , V_5 ) ;
}
static void F_15 ( enum V_2 V_3 ,
const char * V_4 ,
const char * V_5 ,
const char * V_19 )
{
const char * V_1 = L_5 ;
T_1 * V_8 , * V_9 , * V_10 ;
unsigned V_12 = 0 ;
if ( V_3 == V_13 )
V_1 = L_6 ;
if ( V_3 == V_20 )
V_9 = F_5 ( 3 ) ;
else
V_9 = F_5 ( 2 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_4 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_5 ) ) ;
if ( V_3 == V_20 )
F_7 ( V_9 , V_12 ++ , F_8 ( V_19 ) ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( V_8 && F_11 ( V_8 ) ) {
V_10 = F_12 ( V_8 , V_9 ) ;
if ( V_10 == NULL )
F_1 ( V_1 ) ;
}
F_13 ( V_9 ) ;
}
static void F_16 ( struct V_21 * V_22 ,
const char * V_4 ,
struct V_23 * args )
{
switch ( args -> type ) {
case V_24 :
break;
case V_25 :
F_4 ( V_20 , V_4 , V_26 , L_7 ,
args -> V_27 . V_27 ) ;
V_28 = 0 ;
break;
case V_29 :
if ( V_26 )
free ( V_26 ) ;
V_26 = F_17 ( args -> V_16 . V_30 ) ;
break;
case V_20 :
F_16 ( V_22 , V_4 , args -> V_31 . V_16 ) ;
F_15 ( V_20 , V_4 , V_26 ,
args -> V_31 . V_19 ) ;
F_14 ( V_20 , args -> V_31 . V_31 , V_4 ,
V_26 ) ;
break;
case V_13 :
F_16 ( V_22 , V_4 , args -> V_32 . V_16 ) ;
F_15 ( V_13 , V_4 , V_26 , NULL ) ;
F_14 ( V_13 , args -> V_32 . V_33 , V_4 ,
V_26 ) ;
break;
case V_34 :
F_16 ( V_22 , V_4 , args -> V_35 . V_16 ) ;
F_16 ( V_22 , V_4 , args -> V_35 . V_36 ) ;
break;
case V_37 :
break;
case V_38 :
F_16 ( V_22 , V_4 , args -> V_39 . V_40 ) ;
break;
case V_41 :
if ( strcmp ( args -> V_42 . V_42 , L_8 ) == 0 )
V_28 = 1 ;
F_16 ( V_22 , V_4 , args -> V_42 . V_43 ) ;
F_16 ( V_22 , V_4 , args -> V_42 . V_44 ) ;
break;
default:
case V_45 :
case V_46 :
case V_47 :
return;
}
if ( args -> V_18 )
F_16 ( V_22 , V_4 , args -> V_18 ) ;
}
static inline struct V_21 * F_18 ( struct V_48 * V_49 )
{
static char V_4 [ 256 ] ;
struct V_21 * V_22 ;
int type = V_49 -> V_50 . V_51 ;
if ( V_52 [ type ] )
return V_52 [ type ] ;
V_52 [ type ] = V_22 = V_49 -> V_53 ;
if ( ! V_22 )
return NULL ;
sprintf ( V_4 , L_9 , V_22 -> system , V_22 -> V_30 ) ;
F_16 ( V_22 , V_4 , V_22 -> V_54 . args ) ;
return V_22 ;
}
static void F_19 ( union V_55 * V_55
V_56 ,
struct V_57 * V_58 ,
struct V_48 * V_49 ,
struct V_59 * V_59 V_56 ,
struct V_60 * V_61 )
{
T_1 * V_8 , * V_10 , * V_62 , * V_9 , * V_63 , * V_64 = NULL ;
static char V_1 [ 256 ] ;
struct V_65 * V_16 ;
unsigned long long V_66 ;
unsigned long V_67 , V_68 ;
struct V_21 * V_22 ;
unsigned V_12 = 0 ;
int V_69 ;
int V_70 = V_58 -> V_70 ;
void * V_71 = V_58 -> V_72 ;
unsigned long long V_73 = V_58 -> time ;
struct V_74 * V_74 = V_61 -> V_74 ;
char * V_75 = V_74 -> V_75 ;
V_9 = F_5 ( V_76 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
V_22 = F_18 ( V_49 ) ;
if ( ! V_22 )
F_20 ( L_10 , ( int ) V_49 -> V_50 . V_51 ) ;
V_69 = F_21 ( V_22 , L_11 , V_71 ) ;
sprintf ( V_1 , L_9 , V_22 -> system , V_22 -> V_30 ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( V_8 && ! F_11 ( V_8 ) )
V_8 = NULL ;
if ( ! V_8 ) {
V_64 = F_22 () ;
if ( ! V_64 )
F_3 ( L_12 ) ;
}
V_67 = V_73 / V_77 ;
V_68 = V_73 - V_67 * V_77 ;
V_78 -> V_79 = V_71 ;
V_78 -> V_80 = V_49 -> V_53 -> V_80 ;
V_62 = F_23 ( V_78 , NULL ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_1 ) ) ;
F_7 ( V_9 , V_12 ++ , V_62 ) ;
if ( V_8 ) {
F_7 ( V_9 , V_12 ++ , F_9 ( V_70 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_67 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_68 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_69 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_75 ) ) ;
} else {
F_24 ( V_64 , L_13 , F_9 ( V_70 ) ) ;
F_24 ( V_64 , L_14 , F_9 ( V_67 ) ) ;
F_24 ( V_64 , L_15 , F_9 ( V_68 ) ) ;
F_24 ( V_64 , L_11 , F_9 ( V_69 ) ) ;
F_24 ( V_64 , L_16 , F_8 ( V_75 ) ) ;
}
for ( V_16 = V_22 -> V_81 . V_82 ; V_16 ; V_16 = V_16 -> V_18 ) {
if ( V_16 -> V_31 & V_83 ) {
int V_84 ;
if ( V_16 -> V_31 & V_85 ) {
V_84 = * ( int * ) ( V_71 + V_16 -> V_84 ) ;
V_84 &= 0xffff ;
} else
V_84 = V_16 -> V_84 ;
V_63 = F_8 ( ( char * ) V_71 + V_84 ) ;
} else {
V_66 = F_25 ( V_22 , V_71 + V_16 -> V_84 ,
V_16 -> V_36 ) ;
if ( V_16 -> V_31 & V_86 ) {
if ( ( long long ) V_66 >= V_87 &&
( long long ) V_66 <= V_88 )
V_63 = F_9 ( V_66 ) ;
else
V_63 = F_26 ( V_66 ) ;
} else {
if ( V_66 <= V_88 )
V_63 = F_9 ( V_66 ) ;
else
V_63 = F_27 ( V_66 ) ;
}
}
if ( V_8 )
F_7 ( V_9 , V_12 ++ , V_63 ) ;
else
F_24 ( V_64 , V_16 -> V_30 , V_63 ) ;
}
if ( ! V_8 )
F_7 ( V_9 , V_12 ++ , V_64 ) ;
if ( F_28 ( & V_9 , V_12 ) == - 1 )
F_3 ( L_17 ) ;
if ( V_8 ) {
V_10 = F_12 ( V_8 , V_9 ) ;
if ( V_10 == NULL )
F_1 ( V_1 ) ;
} else {
V_8 = F_10 ( V_14 , L_18 ) ;
if ( V_8 && F_11 ( V_8 ) ) {
V_10 = F_12 ( V_8 , V_9 ) ;
if ( V_10 == NULL )
F_1 ( L_18 ) ;
}
F_13 ( V_64 ) ;
}
F_13 ( V_9 ) ;
}
static void F_29 ( union V_55 * V_55
V_56 ,
struct V_57 * V_58 ,
struct V_48 * V_49 ,
struct V_59 * V_59 V_56 ,
struct V_60 * V_61 )
{
T_1 * V_8 , * V_10 , * V_9 , * V_64 ;
static char V_1 [ 64 ] ;
unsigned V_12 = 0 ;
struct V_74 * V_74 = V_61 -> V_74 ;
V_9 = F_5 ( V_76 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
V_64 = F_22 () ;
if ( ! V_64 )
F_3 ( L_19 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_20 , L_21 ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( ! V_8 || ! F_11 ( V_8 ) )
goto exit;
F_24 ( V_64 , L_22 , F_8 ( F_30 ( V_49 ) ) ) ;
F_24 ( V_64 , L_23 , F_31 (
( const char * ) & V_49 -> V_50 , sizeof( V_49 -> V_50 ) ) ) ;
F_24 ( V_64 , L_24 , F_31 (
( const char * ) V_58 , sizeof( * V_58 ) ) ) ;
F_24 ( V_64 , L_25 , F_31 (
( const char * ) V_58 -> V_72 , V_58 -> V_89 ) ) ;
F_24 ( V_64 , L_26 ,
F_8 ( V_74 -> V_75 ) ) ;
if ( V_61 -> V_90 ) {
F_24 ( V_64 , L_27 ,
F_8 ( V_61 -> V_90 -> V_91 -> V_30 ) ) ;
}
if ( V_61 -> V_92 ) {
F_24 ( V_64 , L_28 ,
F_8 ( V_61 -> V_92 -> V_30 ) ) ;
}
F_7 ( V_9 , V_12 ++ , V_64 ) ;
if ( F_28 ( & V_9 , V_12 ) == - 1 )
F_3 ( L_17 ) ;
V_10 = F_12 ( V_8 , V_9 ) ;
if ( V_10 == NULL )
F_1 ( V_1 ) ;
exit:
F_13 ( V_64 ) ;
F_13 ( V_9 ) ;
}
static void F_32 ( union V_55 * V_55 ,
struct V_57 * V_58 ,
struct V_48 * V_49 ,
struct V_59 * V_59 ,
struct V_60 * V_61 )
{
switch ( V_49 -> V_50 . type ) {
case V_93 :
F_19 ( V_55 , V_58 , V_49 ,
V_59 , V_61 ) ;
break;
default:
F_29 ( V_55 , V_58 , V_49 ,
V_59 , V_61 ) ;
}
}
static int F_33 ( void )
{
T_1 * V_8 , * V_10 ;
int V_94 = 0 ;
V_95 = F_34 ( L_29 ) ;
if ( V_95 == NULL )
return - 1 ;
F_35 ( V_95 ) ;
V_14 = F_36 ( V_95 ) ;
if ( V_14 == NULL ) {
V_94 = - 1 ;
goto error;
}
F_35 ( V_14 ) ;
V_8 = F_10 ( V_14 , L_30 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_96;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_30 ) ;
F_13 ( V_10 ) ;
return V_94 ;
error:
F_37 ( V_14 ) ;
F_37 ( V_95 ) ;
V_96:
return V_94 ;
}
static int F_38 ( const char * V_97 , int V_98 , const char * * V_99 )
{
const char * * V_100 ;
char V_101 [ V_102 ] ;
int V_103 , V_94 = 0 ;
T_2 * V_104 ;
V_100 = malloc ( ( V_98 + 1 ) * sizeof( const char * ) ) ;
V_100 [ 0 ] = V_97 ;
for ( V_103 = 1 ; V_103 < V_98 + 1 ; V_103 ++ )
V_100 [ V_103 ] = V_99 [ V_103 - 1 ] ;
F_39 () ;
F_40 () ;
F_41 ( V_98 + 1 , ( char * * ) V_100 ) ;
V_104 = fopen ( V_97 , L_31 ) ;
if ( ! V_104 ) {
sprintf ( V_101 , L_32 , V_97 ) ;
perror ( V_101 ) ;
V_94 = - 1 ;
goto error;
}
V_94 = F_42 ( V_104 , V_97 ) ;
if ( V_94 ) {
fprintf ( V_105 , L_33 , V_97 ) ;
goto error;
}
V_94 = F_33 () ;
if ( V_94 ) {
fprintf ( V_105 , L_34 , V_97 ) ;
goto error;
}
free ( V_100 ) ;
return V_94 ;
error:
F_43 () ;
free ( V_100 ) ;
return V_94 ;
}
static int F_44 ( void )
{
T_1 * V_8 , * V_10 ;
int V_94 = 0 ;
V_8 = F_10 ( V_14 , L_35 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_96;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_35 ) ;
else
F_13 ( V_10 ) ;
V_96:
F_37 ( V_14 ) ;
F_37 ( V_95 ) ;
F_43 () ;
return V_94 ;
}
static int F_45 ( struct V_80 * V_80 , const char * V_106 )
{
struct V_21 * V_22 = NULL ;
struct V_65 * V_107 ;
char V_108 [ V_102 ] ;
int V_109 , V_110 ;
T_2 * V_111 ;
sprintf ( V_108 , L_36 , V_106 ) ;
V_111 = fopen ( V_108 , L_37 ) ;
if ( V_111 == NULL ) {
fprintf ( V_105 , L_38 , V_108 ) ;
return - 1 ;
}
fprintf ( V_111 , L_39
L_40 ) ;
fprintf ( V_111 , L_41
L_42 ) ;
fprintf ( V_111 , L_43
L_44 ) ;
fprintf ( V_111 , L_45
L_46 ) ;
fprintf ( V_111 , L_47
L_48 ) ;
fprintf ( V_111 , L_49
L_50 ) ;
fprintf ( V_111 , L_51
L_52 ) ;
fprintf ( V_111 , L_53 ) ;
fprintf ( V_111 , L_54 ) ;
fprintf ( V_111 , L_55 ) ;
fprintf ( V_111 , L_56 ) ;
fprintf ( V_111 , L_57 ) ;
fprintf ( V_111 , L_58 ) ;
fprintf ( V_111 , L_59 ) ;
fprintf ( V_111 , L_60 ) ;
fprintf ( V_111 , L_61 ) ;
fprintf ( V_111 , L_62 ) ;
while ( ( V_22 = F_46 ( V_80 , V_22 ) ) ) {
fprintf ( V_111 , L_63 , V_22 -> system , V_22 -> V_30 ) ;
fprintf ( V_111 , L_64 ) ;
fprintf ( V_111 , L_65 ) ;
fprintf ( V_111 , L_66 ) ;
fprintf ( V_111 , L_67 ) ;
fprintf ( V_111 , L_68 ) ;
fprintf ( V_111 , L_69 ) ;
fprintf ( V_111 , L_70 ) ;
V_109 = 0 ;
V_110 = 0 ;
for ( V_107 = V_22 -> V_81 . V_82 ; V_107 ; V_107 = V_107 -> V_18 ) {
if ( V_109 ++ )
fprintf ( V_111 , L_71 ) ;
if ( ++ V_110 % 5 == 0 )
fprintf ( V_111 , L_72 ) ;
fprintf ( V_111 , L_20 , V_107 -> V_30 ) ;
}
fprintf ( V_111 , L_73 ) ;
fprintf ( V_111 , L_74
L_75
L_76 ) ;
fprintf ( V_111 , L_77 ) ;
V_109 = 0 ;
V_110 = 0 ;
for ( V_107 = V_22 -> V_81 . V_82 ; V_107 ; V_107 = V_107 -> V_18 ) {
if ( V_109 ++ )
fprintf ( V_111 , L_71 ) ;
if ( V_110 && V_110 % 3 == 0 ) {
fprintf ( V_111 , L_78 ) ;
}
V_110 ++ ;
fprintf ( V_111 , L_79 , V_107 -> V_30 ) ;
if ( V_107 -> V_31 & V_83 ||
V_107 -> V_31 & V_112 ||
V_107 -> V_31 & V_113 )
fprintf ( V_111 , L_80 ) ;
else if ( V_107 -> V_31 & V_86 )
fprintf ( V_111 , L_81 ) ;
else
fprintf ( V_111 , L_82 ) ;
}
fprintf ( V_111 , L_83 ) ;
V_109 = 0 ;
V_110 = 0 ;
for ( V_107 = V_22 -> V_81 . V_82 ; V_107 ; V_107 = V_107 -> V_18 ) {
if ( V_109 ++ )
fprintf ( V_111 , L_71 ) ;
if ( ++ V_110 % 5 == 0 )
fprintf ( V_111 , L_84 ) ;
if ( V_107 -> V_31 & V_112 ) {
if ( ( V_110 - 1 ) % 5 != 0 ) {
fprintf ( V_111 , L_84 ) ;
V_110 = 4 ;
}
fprintf ( V_111 , L_85 ) ;
fprintf ( V_111 , L_86 , V_22 -> system ,
V_22 -> V_30 ) ;
fprintf ( V_111 , L_87 , V_107 -> V_30 ,
V_107 -> V_30 ) ;
} else if ( V_107 -> V_31 & V_113 ) {
if ( ( V_110 - 1 ) % 5 != 0 ) {
fprintf ( V_111 , L_84 ) ;
V_110 = 4 ;
}
fprintf ( V_111 , L_88 ) ;
fprintf ( V_111 , L_86 , V_22 -> system ,
V_22 -> V_30 ) ;
fprintf ( V_111 , L_87 , V_107 -> V_30 ,
V_107 -> V_30 ) ;
} else
fprintf ( V_111 , L_20 , V_107 -> V_30 ) ;
}
fprintf ( V_111 , L_89 ) ;
}
fprintf ( V_111 , L_90
L_91 ) ;
fprintf ( V_111 , L_92
L_93 ) ;
fprintf ( V_111 , L_94
L_95
L_96
L_97 ) ;
fclose ( V_111 ) ;
fprintf ( V_105 , L_98 , V_108 ) ;
return 0 ;
}
