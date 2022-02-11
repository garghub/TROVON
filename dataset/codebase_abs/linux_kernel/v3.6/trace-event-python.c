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
static inline
struct V_21 * F_18 ( struct V_48 * V_48 , int type )
{
static char V_4 [ 256 ] ;
struct V_21 * V_22 ;
if ( V_49 [ type ] )
return V_49 [ type ] ;
V_49 [ type ] = V_22 = F_19 ( V_48 , type ) ;
if ( ! V_22 )
return NULL ;
sprintf ( V_4 , L_9 , V_22 -> system , V_22 -> V_30 ) ;
F_16 ( V_22 , V_4 , V_22 -> V_50 . args ) ;
return V_22 ;
}
static void F_20 ( union V_51 * V_51 V_52 ,
struct V_48 * V_48 ,
struct V_53 * V_54 ,
struct V_55 * T_2 V_52 ,
struct V_56 * V_56 V_52 ,
struct V_57 * V_57 )
{
T_1 * V_8 , * V_10 , * V_58 , * V_9 , * V_59 , * V_60 = NULL ;
static char V_1 [ 256 ] ;
struct V_61 * V_16 ;
unsigned long long V_62 ;
unsigned long V_63 , V_64 ;
struct V_21 * V_22 ;
unsigned V_12 = 0 ;
int type ;
int V_65 ;
int V_66 = V_54 -> V_66 ;
void * V_67 = V_54 -> V_68 ;
unsigned long long V_69 = V_54 -> time ;
char * V_70 = V_57 -> V_70 ;
V_9 = F_5 ( V_71 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
type = F_21 ( V_48 , V_67 ) ;
V_22 = F_18 ( V_48 , type ) ;
if ( ! V_22 )
F_22 ( L_10 , type ) ;
V_65 = F_23 ( V_48 , V_67 ) ;
sprintf ( V_1 , L_9 , V_22 -> system , V_22 -> V_30 ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( V_8 && ! F_11 ( V_8 ) )
V_8 = NULL ;
if ( ! V_8 ) {
V_60 = F_24 () ;
if ( ! V_60 )
F_3 ( L_11 ) ;
}
V_63 = V_69 / V_72 ;
V_64 = V_69 - V_63 * V_72 ;
V_73 -> V_74 = V_67 ;
V_58 = F_25 ( V_73 , NULL ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_1 ) ) ;
F_7 ( V_9 , V_12 ++ , V_58 ) ;
if ( V_8 ) {
F_7 ( V_9 , V_12 ++ , F_9 ( V_66 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_63 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_64 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_65 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_70 ) ) ;
} else {
F_26 ( V_60 , L_12 , F_9 ( V_66 ) ) ;
F_26 ( V_60 , L_13 , F_9 ( V_63 ) ) ;
F_26 ( V_60 , L_14 , F_9 ( V_64 ) ) ;
F_26 ( V_60 , L_15 , F_9 ( V_65 ) ) ;
F_26 ( V_60 , L_16 , F_8 ( V_70 ) ) ;
}
for ( V_16 = V_22 -> V_75 . V_76 ; V_16 ; V_16 = V_16 -> V_18 ) {
if ( V_16 -> V_31 & V_77 ) {
int V_78 ;
if ( V_16 -> V_31 & V_79 ) {
V_78 = * ( int * ) ( V_67 + V_16 -> V_78 ) ;
V_78 &= 0xffff ;
} else
V_78 = V_16 -> V_78 ;
V_59 = F_8 ( ( char * ) V_67 + V_78 ) ;
} else {
V_62 = F_27 ( V_48 , V_67 + V_16 -> V_78 ,
V_16 -> V_36 ) ;
if ( V_16 -> V_31 & V_80 ) {
if ( ( long long ) V_62 >= V_81 &&
( long long ) V_62 <= V_82 )
V_59 = F_9 ( V_62 ) ;
else
V_59 = F_28 ( V_62 ) ;
} else {
if ( V_62 <= V_82 )
V_59 = F_9 ( V_62 ) ;
else
V_59 = F_29 ( V_62 ) ;
}
}
if ( V_8 )
F_7 ( V_9 , V_12 ++ , V_59 ) ;
else
F_26 ( V_60 , V_16 -> V_30 , V_59 ) ;
}
if ( ! V_8 )
F_7 ( V_9 , V_12 ++ , V_60 ) ;
if ( F_30 ( & V_9 , V_12 ) == - 1 )
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
F_13 ( V_60 ) ;
}
F_13 ( V_9 ) ;
}
static int F_31 ( void )
{
T_1 * V_8 , * V_10 ;
int V_83 = 0 ;
V_84 = F_32 ( L_19 ) ;
if ( V_84 == NULL )
return - 1 ;
F_33 ( V_84 ) ;
V_14 = F_34 ( V_84 ) ;
if ( V_14 == NULL ) {
V_83 = - 1 ;
goto error;
}
F_33 ( V_14 ) ;
V_8 = F_10 ( V_14 , L_20 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_85;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_20 ) ;
F_13 ( V_10 ) ;
return V_83 ;
error:
F_35 ( V_14 ) ;
F_35 ( V_84 ) ;
V_85:
return V_83 ;
}
static int F_36 ( const char * V_86 , int V_87 , const char * * V_88 )
{
const char * * V_89 ;
char V_90 [ V_91 ] ;
int V_92 , V_83 = 0 ;
T_3 * V_93 ;
V_89 = malloc ( ( V_87 + 1 ) * sizeof( const char * ) ) ;
V_89 [ 0 ] = V_86 ;
for ( V_92 = 1 ; V_92 < V_87 + 1 ; V_92 ++ )
V_89 [ V_92 ] = V_88 [ V_92 - 1 ] ;
F_37 () ;
F_38 () ;
F_39 ( V_87 + 1 , ( char * * ) V_89 ) ;
V_93 = fopen ( V_86 , L_21 ) ;
if ( ! V_93 ) {
sprintf ( V_90 , L_22 , V_86 ) ;
perror ( V_90 ) ;
V_83 = - 1 ;
goto error;
}
V_83 = F_40 ( V_93 , V_86 ) ;
if ( V_83 ) {
fprintf ( V_94 , L_23 , V_86 ) ;
goto error;
}
V_83 = F_31 () ;
if ( V_83 ) {
fprintf ( V_94 , L_24 , V_86 ) ;
goto error;
}
free ( V_89 ) ;
return V_83 ;
error:
F_41 () ;
free ( V_89 ) ;
return V_83 ;
}
static int F_42 ( void )
{
T_1 * V_8 , * V_10 ;
int V_83 = 0 ;
V_8 = F_10 ( V_14 , L_25 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_85;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_25 ) ;
else
F_13 ( V_10 ) ;
V_85:
F_35 ( V_14 ) ;
F_35 ( V_84 ) ;
F_41 () ;
return V_83 ;
}
static int F_43 ( struct V_48 * V_48 , const char * V_95 )
{
struct V_21 * V_22 = NULL ;
struct V_61 * V_96 ;
char V_97 [ V_91 ] ;
int V_98 , V_99 ;
T_3 * V_100 ;
sprintf ( V_97 , L_26 , V_95 ) ;
V_100 = fopen ( V_97 , L_27 ) ;
if ( V_100 == NULL ) {
fprintf ( V_94 , L_28 , V_97 ) ;
return - 1 ;
}
fprintf ( V_100 , L_29
L_30 ) ;
fprintf ( V_100 , L_31
L_32 ) ;
fprintf ( V_100 , L_33
L_34 ) ;
fprintf ( V_100 , L_35
L_36 ) ;
fprintf ( V_100 , L_37
L_38 ) ;
fprintf ( V_100 , L_39
L_40 ) ;
fprintf ( V_100 , L_41
L_42 ) ;
fprintf ( V_100 , L_43 ) ;
fprintf ( V_100 , L_44 ) ;
fprintf ( V_100 , L_45 ) ;
fprintf ( V_100 , L_46 ) ;
fprintf ( V_100 , L_47 ) ;
fprintf ( V_100 , L_48 ) ;
fprintf ( V_100 , L_49 ) ;
fprintf ( V_100 , L_50 ) ;
fprintf ( V_100 , L_51 ) ;
fprintf ( V_100 , L_52 ) ;
while ( ( V_22 = F_44 ( V_48 , V_22 ) ) ) {
fprintf ( V_100 , L_53 , V_22 -> system , V_22 -> V_30 ) ;
fprintf ( V_100 , L_54 ) ;
fprintf ( V_100 , L_55 ) ;
fprintf ( V_100 , L_56 ) ;
fprintf ( V_100 , L_57 ) ;
fprintf ( V_100 , L_58 ) ;
fprintf ( V_100 , L_59 ) ;
fprintf ( V_100 , L_60 ) ;
V_98 = 0 ;
V_99 = 0 ;
for ( V_96 = V_22 -> V_75 . V_76 ; V_96 ; V_96 = V_96 -> V_18 ) {
if ( V_98 ++ )
fprintf ( V_100 , L_61 ) ;
if ( ++ V_99 % 5 == 0 )
fprintf ( V_100 , L_62 ) ;
fprintf ( V_100 , L_63 , V_96 -> V_30 ) ;
}
fprintf ( V_100 , L_64 ) ;
fprintf ( V_100 , L_65
L_66
L_67 ) ;
fprintf ( V_100 , L_68 ) ;
V_98 = 0 ;
V_99 = 0 ;
for ( V_96 = V_22 -> V_75 . V_76 ; V_96 ; V_96 = V_96 -> V_18 ) {
if ( V_98 ++ )
fprintf ( V_100 , L_61 ) ;
if ( V_99 && V_99 % 3 == 0 ) {
fprintf ( V_100 , L_69 ) ;
}
V_99 ++ ;
fprintf ( V_100 , L_70 , V_96 -> V_30 ) ;
if ( V_96 -> V_31 & V_77 ||
V_96 -> V_31 & V_101 ||
V_96 -> V_31 & V_102 )
fprintf ( V_100 , L_71 ) ;
else if ( V_96 -> V_31 & V_80 )
fprintf ( V_100 , L_72 ) ;
else
fprintf ( V_100 , L_73 ) ;
}
fprintf ( V_100 , L_74 ) ;
V_98 = 0 ;
V_99 = 0 ;
for ( V_96 = V_22 -> V_75 . V_76 ; V_96 ; V_96 = V_96 -> V_18 ) {
if ( V_98 ++ )
fprintf ( V_100 , L_61 ) ;
if ( ++ V_99 % 5 == 0 )
fprintf ( V_100 , L_75 ) ;
if ( V_96 -> V_31 & V_101 ) {
if ( ( V_99 - 1 ) % 5 != 0 ) {
fprintf ( V_100 , L_75 ) ;
V_99 = 4 ;
}
fprintf ( V_100 , L_76 ) ;
fprintf ( V_100 , L_77 , V_22 -> system ,
V_22 -> V_30 ) ;
fprintf ( V_100 , L_78 , V_96 -> V_30 ,
V_96 -> V_30 ) ;
} else if ( V_96 -> V_31 & V_102 ) {
if ( ( V_99 - 1 ) % 5 != 0 ) {
fprintf ( V_100 , L_75 ) ;
V_99 = 4 ;
}
fprintf ( V_100 , L_79 ) ;
fprintf ( V_100 , L_77 , V_22 -> system ,
V_22 -> V_30 ) ;
fprintf ( V_100 , L_78 , V_96 -> V_30 ,
V_96 -> V_30 ) ;
} else
fprintf ( V_100 , L_63 , V_96 -> V_30 ) ;
}
fprintf ( V_100 , L_80 ) ;
}
fprintf ( V_100 , L_81
L_82 ) ;
fprintf ( V_100 , L_83
L_84 ) ;
fprintf ( V_100 , L_85
L_86
L_87
L_88 ) ;
fclose ( V_100 ) ;
fprintf ( V_94 , L_89 , V_97 ) ;
return 0 ;
}
