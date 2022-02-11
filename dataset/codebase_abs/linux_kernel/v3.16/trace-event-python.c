static void F_1 ( const char * V_1 )
{
F_2 () ;
F_3 ( L_1 ) ;
}
static void F_4 ( T_1 * V_2 , const char * V_3 , T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( enum V_5 V_6 ,
const char * V_7 ,
const char * V_8 ,
const char * V_9 ,
const char * V_10 )
{
const char * V_1 = L_2 ;
T_1 * V_11 , * V_12 , * V_13 ;
unsigned long long V_14 ;
unsigned V_15 = 0 ;
if ( V_6 == V_16 )
V_1 = L_3 ;
V_12 = F_8 ( 4 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
V_14 = F_9 ( V_9 ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_7 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_8 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_14 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_10 ) ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( V_11 && F_14 ( V_11 ) ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
}
F_6 ( V_12 ) ;
}
static void F_16 ( enum V_5 V_6 ,
struct V_18 * V_19 ,
const char * V_7 ,
const char * V_8 )
{
F_7 ( V_6 , V_7 , V_8 , V_19 -> V_14 ,
V_19 -> V_20 ) ;
if ( V_19 -> V_21 )
F_16 ( V_6 , V_19 -> V_21 , V_7 , V_8 ) ;
}
static void F_17 ( enum V_5 V_6 ,
const char * V_7 ,
const char * V_8 ,
const char * V_22 )
{
const char * V_1 = L_5 ;
T_1 * V_11 , * V_12 , * V_13 ;
unsigned V_15 = 0 ;
if ( V_6 == V_16 )
V_1 = L_6 ;
if ( V_6 == V_23 )
V_12 = F_8 ( 3 ) ;
else
V_12 = F_8 ( 2 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_7 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_8 ) ) ;
if ( V_6 == V_23 )
F_10 ( V_12 , V_15 ++ , F_11 ( V_22 ) ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( V_11 && F_14 ( V_11 ) ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
}
F_6 ( V_12 ) ;
}
static void F_18 ( struct V_24 * V_25 ,
const char * V_7 ,
struct V_26 * args )
{
switch ( args -> type ) {
case V_27 :
break;
case V_28 :
F_7 ( V_23 , V_7 , V_29 , L_7 ,
args -> V_30 . V_30 ) ;
V_31 = 0 ;
break;
case V_32 :
free ( V_29 ) ;
V_29 = F_19 ( args -> V_19 . V_33 ) ;
break;
case V_23 :
F_18 ( V_25 , V_7 , args -> V_34 . V_19 ) ;
F_17 ( V_23 , V_7 , V_29 ,
args -> V_34 . V_22 ) ;
F_16 ( V_23 , args -> V_34 . V_34 , V_7 ,
V_29 ) ;
break;
case V_16 :
F_18 ( V_25 , V_7 , args -> V_35 . V_19 ) ;
F_17 ( V_16 , V_7 , V_29 , NULL ) ;
F_16 ( V_16 , args -> V_35 . V_36 , V_7 ,
V_29 ) ;
break;
case V_37 :
F_18 ( V_25 , V_7 , args -> V_38 . V_19 ) ;
F_18 ( V_25 , V_7 , args -> V_38 . V_39 ) ;
break;
case V_40 :
break;
case V_41 :
F_18 ( V_25 , V_7 , args -> V_42 . V_43 ) ;
break;
case V_44 :
if ( strcmp ( args -> V_45 . V_45 , L_8 ) == 0 )
V_31 = 1 ;
F_18 ( V_25 , V_7 , args -> V_45 . V_46 ) ;
F_18 ( V_25 , V_7 , args -> V_45 . V_47 ) ;
break;
default:
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return;
}
if ( args -> V_21 )
F_18 ( V_25 , V_7 , args -> V_21 ) ;
}
static inline struct V_24 * F_20 ( struct V_52 * V_53 )
{
static char V_7 [ 256 ] ;
struct V_24 * V_25 ;
int type = V_53 -> V_54 . V_55 ;
if ( V_56 [ type ] )
return V_56 [ type ] ;
V_56 [ type ] = V_25 = V_53 -> V_57 ;
if ( ! V_25 )
return NULL ;
sprintf ( V_7 , L_9 , V_25 -> system , V_25 -> V_33 ) ;
F_18 ( V_25 , V_7 , V_25 -> V_58 . args ) ;
return V_25 ;
}
static void F_21 ( struct V_59 * V_60 ,
struct V_52 * V_53 ,
struct V_61 * V_61 ,
struct V_62 * V_63 )
{
T_1 * V_11 , * V_13 , * V_64 , * V_12 , * V_65 , * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_66 * V_19 ;
unsigned long long V_4 ;
unsigned long V_67 , V_68 ;
struct V_24 * V_25 ;
unsigned V_15 = 0 ;
int V_69 ;
int V_70 = V_60 -> V_70 ;
void * V_71 = V_60 -> V_72 ;
unsigned long long V_73 = V_60 -> time ;
const char * V_74 = F_22 ( V_61 ) ;
V_12 = F_8 ( V_75 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
V_25 = F_20 ( V_53 ) ;
if ( ! V_25 )
F_23 ( L_10 , ( int ) V_53 -> V_54 . V_55 ) ;
V_69 = F_24 ( V_25 , L_11 , V_71 ) ;
sprintf ( V_1 , L_9 , V_25 -> system , V_25 -> V_33 ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( V_11 && ! F_14 ( V_11 ) )
V_11 = NULL ;
if ( ! V_11 ) {
V_2 = F_25 () ;
if ( ! V_2 )
F_3 ( L_12 ) ;
}
V_67 = V_73 / V_76 ;
V_68 = V_73 - V_67 * V_76 ;
V_77 -> V_78 = V_71 ;
V_77 -> V_79 = V_53 -> V_57 -> V_79 ;
V_64 = F_26 ( V_77 , NULL ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_1 ) ) ;
F_10 ( V_12 , V_15 ++ , V_64 ) ;
if ( V_11 ) {
F_10 ( V_12 , V_15 ++ , F_12 ( V_70 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_67 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_68 ) ) ;
F_10 ( V_12 , V_15 ++ , F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_15 ++ , F_11 ( V_74 ) ) ;
} else {
F_4 ( V_2 , L_13 , F_12 ( V_70 ) ) ;
F_4 ( V_2 , L_14 , F_12 ( V_67 ) ) ;
F_4 ( V_2 , L_15 , F_12 ( V_68 ) ) ;
F_4 ( V_2 , L_11 , F_12 ( V_69 ) ) ;
F_4 ( V_2 , L_16 , F_11 ( V_74 ) ) ;
}
for ( V_19 = V_25 -> V_80 . V_81 ; V_19 ; V_19 = V_19 -> V_21 ) {
if ( V_19 -> V_34 & V_82 ) {
int V_83 ;
if ( V_19 -> V_34 & V_84 ) {
V_83 = * ( int * ) ( V_71 + V_19 -> V_83 ) ;
V_83 &= 0xffff ;
} else
V_83 = V_19 -> V_83 ;
V_65 = F_11 ( ( char * ) V_71 + V_83 ) ;
} else {
V_4 = F_27 ( V_25 , V_71 + V_19 -> V_83 ,
V_19 -> V_39 ) ;
if ( V_19 -> V_34 & V_85 ) {
if ( ( long long ) V_4 >= V_86 &&
( long long ) V_4 <= V_87 )
V_65 = F_12 ( V_4 ) ;
else
V_65 = F_28 ( V_4 ) ;
} else {
if ( V_4 <= V_87 )
V_65 = F_12 ( V_4 ) ;
else
V_65 = F_29 ( V_4 ) ;
}
}
if ( V_11 )
F_10 ( V_12 , V_15 ++ , V_65 ) ;
else
F_4 ( V_2 , V_19 -> V_33 , V_65 ) ;
}
if ( ! V_11 )
F_10 ( V_12 , V_15 ++ , V_2 ) ;
if ( F_30 ( & V_12 , V_15 ) == - 1 )
F_3 ( L_17 ) ;
if ( V_11 ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
} else {
V_11 = F_13 ( V_17 , L_18 ) ;
if ( V_11 && F_14 ( V_11 ) ) {
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( L_18 ) ;
}
F_6 ( V_2 ) ;
}
F_6 ( V_12 ) ;
}
static void F_31 ( struct V_59 * V_60 ,
struct V_52 * V_53 ,
struct V_61 * V_61 ,
struct V_62 * V_63 )
{
T_1 * V_11 , * V_13 , * V_12 , * V_2 ;
static char V_1 [ 64 ] ;
unsigned V_15 = 0 ;
V_12 = F_8 ( V_75 ) ;
if ( ! V_12 )
F_3 ( L_4 ) ;
V_2 = F_25 () ;
if ( ! V_2 )
F_3 ( L_19 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_20 , L_21 ) ;
V_11 = F_13 ( V_17 , V_1 ) ;
if ( ! V_11 || ! F_14 ( V_11 ) )
goto exit;
F_4 ( V_2 , L_22 , F_11 ( F_32 ( V_53 ) ) ) ;
F_4 ( V_2 , L_23 , F_33 (
( const char * ) & V_53 -> V_54 , sizeof( V_53 -> V_54 ) ) ) ;
F_4 ( V_2 , L_24 , F_33 (
( const char * ) V_60 , sizeof( * V_60 ) ) ) ;
F_4 ( V_2 , L_25 , F_33 (
( const char * ) V_60 -> V_72 , V_60 -> V_88 ) ) ;
F_4 ( V_2 , L_26 ,
F_11 ( F_22 ( V_61 ) ) ) ;
if ( V_63 -> V_89 ) {
F_4 ( V_2 , L_27 ,
F_11 ( V_63 -> V_89 -> V_90 -> V_33 ) ) ;
}
if ( V_63 -> V_91 ) {
F_4 ( V_2 , L_28 ,
F_11 ( V_63 -> V_91 -> V_33 ) ) ;
}
F_10 ( V_12 , V_15 ++ , V_2 ) ;
if ( F_30 ( & V_12 , V_15 ) == - 1 )
F_3 ( L_17 ) ;
V_13 = F_15 ( V_11 , V_12 ) ;
if ( V_13 == NULL )
F_1 ( V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_12 ) ;
}
static void F_34 ( union V_92 * V_25 V_93 ,
struct V_59 * V_60 ,
struct V_52 * V_53 ,
struct V_61 * V_61 ,
struct V_62 * V_63 )
{
switch ( V_53 -> V_54 . type ) {
case V_94 :
F_21 ( V_60 , V_53 , V_61 , V_63 ) ;
break;
default:
F_31 ( V_60 , V_53 , V_61 , V_63 ) ;
}
}
static int F_35 ( void )
{
T_1 * V_11 , * V_13 ;
int V_95 = 0 ;
V_96 = F_36 ( L_29 ) ;
if ( V_96 == NULL )
return - 1 ;
F_37 ( V_96 ) ;
V_17 = F_38 ( V_96 ) ;
if ( V_17 == NULL ) {
V_95 = - 1 ;
goto error;
}
F_37 ( V_17 ) ;
V_11 = F_13 ( V_17 , L_30 ) ;
if ( V_11 == NULL || ! F_14 ( V_11 ) )
goto V_97;
V_13 = F_15 ( V_11 , NULL ) ;
if ( V_13 == NULL )
F_1 ( L_30 ) ;
F_6 ( V_13 ) ;
return V_95 ;
error:
F_39 ( V_17 ) ;
F_39 ( V_96 ) ;
V_97:
return V_95 ;
}
static int F_40 ( const char * V_98 , int V_99 , const char * * V_100 )
{
const char * * V_101 ;
char V_102 [ V_103 ] ;
int V_104 , V_95 = 0 ;
T_2 * V_105 ;
V_101 = malloc ( ( V_99 + 1 ) * sizeof( const char * ) ) ;
V_101 [ 0 ] = V_98 ;
for ( V_104 = 1 ; V_104 < V_99 + 1 ; V_104 ++ )
V_101 [ V_104 ] = V_100 [ V_104 - 1 ] ;
F_41 () ;
F_42 () ;
F_43 ( V_99 + 1 , ( char * * ) V_101 ) ;
V_105 = fopen ( V_98 , L_31 ) ;
if ( ! V_105 ) {
sprintf ( V_102 , L_32 , V_98 ) ;
perror ( V_102 ) ;
V_95 = - 1 ;
goto error;
}
V_95 = F_44 ( V_105 , V_98 ) ;
if ( V_95 ) {
fprintf ( V_106 , L_33 , V_98 ) ;
goto error;
}
V_95 = F_35 () ;
if ( V_95 ) {
fprintf ( V_106 , L_34 , V_98 ) ;
goto error;
}
free ( V_101 ) ;
return V_95 ;
error:
F_45 () ;
free ( V_101 ) ;
return V_95 ;
}
static int F_46 ( void )
{
T_1 * V_11 , * V_13 ;
int V_95 = 0 ;
V_11 = F_13 ( V_17 , L_35 ) ;
if ( V_11 == NULL || ! F_14 ( V_11 ) )
goto V_97;
V_13 = F_15 ( V_11 , NULL ) ;
if ( V_13 == NULL )
F_1 ( L_35 ) ;
else
F_6 ( V_13 ) ;
V_97:
F_39 ( V_17 ) ;
F_39 ( V_96 ) ;
F_45 () ;
return V_95 ;
}
static int F_47 ( struct V_79 * V_79 , const char * V_107 )
{
struct V_24 * V_25 = NULL ;
struct V_66 * V_108 ;
char V_109 [ V_103 ] ;
int V_110 , V_111 ;
T_2 * V_112 ;
sprintf ( V_109 , L_36 , V_107 ) ;
V_112 = fopen ( V_109 , L_37 ) ;
if ( V_112 == NULL ) {
fprintf ( V_106 , L_38 , V_109 ) ;
return - 1 ;
}
fprintf ( V_112 , L_39
L_40 ) ;
fprintf ( V_112 , L_41
L_42 ) ;
fprintf ( V_112 , L_43
L_44 ) ;
fprintf ( V_112 , L_45
L_46 ) ;
fprintf ( V_112 , L_47
L_48 ) ;
fprintf ( V_112 , L_49
L_50 ) ;
fprintf ( V_112 , L_51
L_52 ) ;
fprintf ( V_112 , L_53 ) ;
fprintf ( V_112 , L_54 ) ;
fprintf ( V_112 , L_55 ) ;
fprintf ( V_112 , L_56 ) ;
fprintf ( V_112 , L_57 ) ;
fprintf ( V_112 , L_58 ) ;
fprintf ( V_112 , L_59 ) ;
fprintf ( V_112 , L_60 ) ;
fprintf ( V_112 , L_61 ) ;
fprintf ( V_112 , L_62 ) ;
while ( ( V_25 = F_48 ( V_79 , V_25 ) ) ) {
fprintf ( V_112 , L_63 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_112 , L_64 ) ;
fprintf ( V_112 , L_65 ) ;
fprintf ( V_112 , L_66 ) ;
fprintf ( V_112 , L_67 ) ;
fprintf ( V_112 , L_68 ) ;
fprintf ( V_112 , L_69 ) ;
fprintf ( V_112 , L_70 ) ;
V_110 = 0 ;
V_111 = 0 ;
for ( V_108 = V_25 -> V_80 . V_81 ; V_108 ; V_108 = V_108 -> V_21 ) {
if ( V_110 ++ )
fprintf ( V_112 , L_71 ) ;
if ( ++ V_111 % 5 == 0 )
fprintf ( V_112 , L_72 ) ;
fprintf ( V_112 , L_20 , V_108 -> V_33 ) ;
}
fprintf ( V_112 , L_73 ) ;
fprintf ( V_112 , L_74
L_75
L_76 ) ;
fprintf ( V_112 , L_77 ) ;
V_110 = 0 ;
V_111 = 0 ;
for ( V_108 = V_25 -> V_80 . V_81 ; V_108 ; V_108 = V_108 -> V_21 ) {
if ( V_110 ++ )
fprintf ( V_112 , L_71 ) ;
if ( V_111 && V_111 % 3 == 0 ) {
fprintf ( V_112 , L_78 ) ;
}
V_111 ++ ;
fprintf ( V_112 , L_79 , V_108 -> V_33 ) ;
if ( V_108 -> V_34 & V_82 ||
V_108 -> V_34 & V_113 ||
V_108 -> V_34 & V_114 ||
V_108 -> V_34 & V_115 )
fprintf ( V_112 , L_80 ) ;
else if ( V_108 -> V_34 & V_85 )
fprintf ( V_112 , L_81 ) ;
else
fprintf ( V_112 , L_82 ) ;
}
fprintf ( V_112 , L_83 ) ;
V_110 = 0 ;
V_111 = 0 ;
for ( V_108 = V_25 -> V_80 . V_81 ; V_108 ; V_108 = V_108 -> V_21 ) {
if ( V_110 ++ )
fprintf ( V_112 , L_71 ) ;
if ( ++ V_111 % 5 == 0 )
fprintf ( V_112 , L_84 ) ;
if ( V_108 -> V_34 & V_113 ) {
if ( ( V_111 - 1 ) % 5 != 0 ) {
fprintf ( V_112 , L_84 ) ;
V_111 = 4 ;
}
fprintf ( V_112 , L_85 ) ;
fprintf ( V_112 , L_86 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_112 , L_87 , V_108 -> V_33 ,
V_108 -> V_33 ) ;
} else if ( V_108 -> V_34 & V_115 ) {
if ( ( V_111 - 1 ) % 5 != 0 ) {
fprintf ( V_112 , L_84 ) ;
V_111 = 4 ;
}
fprintf ( V_112 , L_88 ) ;
fprintf ( V_112 , L_86 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_112 , L_87 , V_108 -> V_33 ,
V_108 -> V_33 ) ;
} else
fprintf ( V_112 , L_20 , V_108 -> V_33 ) ;
}
fprintf ( V_112 , L_89 ) ;
}
fprintf ( V_112 , L_90
L_91 ) ;
fprintf ( V_112 , L_92
L_93 ) ;
fprintf ( V_112 , L_94
L_95
L_96
L_97 ) ;
fclose ( V_112 ) ;
fprintf ( V_106 , L_98 , V_109 ) ;
return 0 ;
}
