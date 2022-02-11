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
break;
case V_35 :
F_16 ( V_22 , V_4 , args -> V_36 . V_37 ) ;
break;
case V_38 :
if ( strcmp ( args -> V_39 . V_39 , L_8 ) == 0 )
V_28 = 1 ;
F_16 ( V_22 , V_4 , args -> V_39 . V_40 ) ;
F_16 ( V_22 , V_4 , args -> V_39 . V_41 ) ;
break;
default:
case V_42 :
case V_43 :
case V_44 :
return;
}
if ( args -> V_18 )
F_16 ( V_22 , V_4 , args -> V_18 ) ;
}
static inline struct V_21 * F_18 ( int type )
{
static char V_4 [ 256 ] ;
struct V_21 * V_22 ;
if ( V_45 [ type ] )
return V_45 [ type ] ;
V_45 [ type ] = V_22 = F_19 ( type ) ;
if ( ! V_22 )
return NULL ;
sprintf ( V_4 , L_9 , V_22 -> system , V_22 -> V_30 ) ;
F_16 ( V_22 , V_4 , V_22 -> V_46 . args ) ;
return V_22 ;
}
static void F_20 ( union V_47 * T_2 V_48 ,
struct V_49 * V_50 ,
struct V_51 * T_3 V_48 ,
struct V_52 * V_52 V_48 ,
struct V_53 * V_53 )
{
T_1 * V_8 , * V_10 , * V_54 , * V_9 , * V_55 , * V_56 = NULL ;
static char V_1 [ 256 ] ;
struct V_57 * V_16 ;
unsigned long long V_58 ;
unsigned long V_59 , V_60 ;
struct V_21 * V_22 ;
unsigned V_12 = 0 ;
int type ;
int V_61 ;
int V_62 = V_50 -> V_62 ;
void * V_63 = V_50 -> V_64 ;
unsigned long long V_65 = V_50 -> time ;
char * V_66 = V_53 -> V_66 ;
V_9 = F_5 ( V_67 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
type = F_21 ( V_63 ) ;
V_22 = F_18 ( type ) ;
if ( ! V_22 )
F_22 ( L_10 , type ) ;
V_61 = F_23 ( V_63 ) ;
sprintf ( V_1 , L_9 , V_22 -> system , V_22 -> V_30 ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( V_8 && ! F_11 ( V_8 ) )
V_8 = NULL ;
if ( ! V_8 ) {
V_56 = F_24 () ;
if ( ! V_56 )
F_3 ( L_11 ) ;
}
V_59 = V_65 / V_68 ;
V_60 = V_65 - V_59 * V_68 ;
V_69 -> V_70 = V_63 ;
V_54 = F_25 ( V_69 , NULL ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_1 ) ) ;
F_7 ( V_9 , V_12 ++ , V_54 ) ;
if ( V_8 ) {
F_7 ( V_9 , V_12 ++ , F_9 ( V_62 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_59 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_60 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_61 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_66 ) ) ;
} else {
F_26 ( V_56 , L_12 , F_9 ( V_62 ) ) ;
F_26 ( V_56 , L_13 , F_9 ( V_59 ) ) ;
F_26 ( V_56 , L_14 , F_9 ( V_60 ) ) ;
F_26 ( V_56 , L_15 , F_9 ( V_61 ) ) ;
F_26 ( V_56 , L_16 , F_8 ( V_66 ) ) ;
}
for ( V_16 = V_22 -> V_71 . V_72 ; V_16 ; V_16 = V_16 -> V_18 ) {
if ( V_16 -> V_31 & V_73 ) {
int V_74 ;
if ( V_16 -> V_31 & V_75 ) {
V_74 = * ( int * ) ( V_63 + V_16 -> V_74 ) ;
V_74 &= 0xffff ;
} else
V_74 = V_16 -> V_74 ;
V_55 = F_8 ( ( char * ) V_63 + V_74 ) ;
} else {
V_58 = F_27 ( V_63 + V_16 -> V_74 , V_16 -> V_76 ) ;
if ( V_16 -> V_31 & V_77 ) {
if ( ( long long ) V_58 >= V_78 &&
( long long ) V_58 <= V_79 )
V_55 = F_9 ( V_58 ) ;
else
V_55 = F_28 ( V_58 ) ;
} else {
if ( V_58 <= V_79 )
V_55 = F_9 ( V_58 ) ;
else
V_55 = F_29 ( V_58 ) ;
}
}
if ( V_8 )
F_7 ( V_9 , V_12 ++ , V_55 ) ;
else
F_26 ( V_56 , V_16 -> V_30 , V_55 ) ;
}
if ( ! V_8 )
F_7 ( V_9 , V_12 ++ , V_56 ) ;
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
F_13 ( V_56 ) ;
}
F_13 ( V_9 ) ;
}
static int F_31 ( void )
{
T_1 * V_8 , * V_10 ;
int V_80 = 0 ;
V_81 = F_32 ( L_19 ) ;
if ( V_81 == NULL )
return - 1 ;
F_33 ( V_81 ) ;
V_14 = F_34 ( V_81 ) ;
if ( V_14 == NULL ) {
V_80 = - 1 ;
goto error;
}
F_33 ( V_14 ) ;
V_8 = F_10 ( V_14 , L_20 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_82;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_20 ) ;
F_13 ( V_10 ) ;
return V_80 ;
error:
F_35 ( V_14 ) ;
F_35 ( V_81 ) ;
V_82:
return V_80 ;
}
static int F_36 ( const char * V_83 , int V_84 , const char * * V_85 )
{
const char * * V_86 ;
char V_87 [ V_88 ] ;
int V_89 , V_80 = 0 ;
T_4 * V_90 ;
V_86 = malloc ( ( V_84 + 1 ) * sizeof( const char * ) ) ;
V_86 [ 0 ] = V_83 ;
for ( V_89 = 1 ; V_89 < V_84 + 1 ; V_89 ++ )
V_86 [ V_89 ] = V_85 [ V_89 - 1 ] ;
F_37 () ;
F_38 () ;
F_39 ( V_84 + 1 , ( char * * ) V_86 ) ;
V_90 = fopen ( V_83 , L_21 ) ;
if ( ! V_90 ) {
sprintf ( V_87 , L_22 , V_83 ) ;
perror ( V_87 ) ;
V_80 = - 1 ;
goto error;
}
V_80 = F_40 ( V_90 , V_83 ) ;
if ( V_80 ) {
fprintf ( V_91 , L_23 , V_83 ) ;
goto error;
}
V_80 = F_31 () ;
if ( V_80 ) {
fprintf ( V_91 , L_24 , V_83 ) ;
goto error;
}
free ( V_86 ) ;
return V_80 ;
error:
F_41 () ;
free ( V_86 ) ;
return V_80 ;
}
static int F_42 ( void )
{
T_1 * V_8 , * V_10 ;
int V_80 = 0 ;
V_8 = F_10 ( V_14 , L_25 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_82;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_25 ) ;
else
F_13 ( V_10 ) ;
V_82:
F_35 ( V_14 ) ;
F_35 ( V_81 ) ;
F_41 () ;
return V_80 ;
}
static int F_43 ( const char * V_92 )
{
struct V_21 * V_22 = NULL ;
struct V_57 * V_93 ;
char V_94 [ V_88 ] ;
int V_95 , V_96 ;
T_4 * V_97 ;
sprintf ( V_94 , L_26 , V_92 ) ;
V_97 = fopen ( V_94 , L_27 ) ;
if ( V_97 == NULL ) {
fprintf ( V_91 , L_28 , V_94 ) ;
return - 1 ;
}
fprintf ( V_97 , L_29
L_30 ) ;
fprintf ( V_97 , L_31
L_32 ) ;
fprintf ( V_97 , L_33
L_34 ) ;
fprintf ( V_97 , L_35
L_36 ) ;
fprintf ( V_97 , L_37
L_38 ) ;
fprintf ( V_97 , L_39
L_40 ) ;
fprintf ( V_97 , L_41
L_42 ) ;
fprintf ( V_97 , L_43 ) ;
fprintf ( V_97 , L_44 ) ;
fprintf ( V_97 , L_45 ) ;
fprintf ( V_97 , L_46 ) ;
fprintf ( V_97 , L_47 ) ;
fprintf ( V_97 , L_48 ) ;
fprintf ( V_97 , L_49 ) ;
fprintf ( V_97 , L_50 ) ;
fprintf ( V_97 , L_51 ) ;
fprintf ( V_97 , L_52 ) ;
while ( ( V_22 = F_44 ( V_22 ) ) ) {
fprintf ( V_97 , L_53 , V_22 -> system , V_22 -> V_30 ) ;
fprintf ( V_97 , L_54 ) ;
fprintf ( V_97 , L_55 ) ;
fprintf ( V_97 , L_56 ) ;
fprintf ( V_97 , L_57 ) ;
fprintf ( V_97 , L_58 ) ;
fprintf ( V_97 , L_59 ) ;
fprintf ( V_97 , L_60 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_93 = V_22 -> V_71 . V_72 ; V_93 ; V_93 = V_93 -> V_18 ) {
if ( V_95 ++ )
fprintf ( V_97 , L_61 ) ;
if ( ++ V_96 % 5 == 0 )
fprintf ( V_97 , L_62 ) ;
fprintf ( V_97 , L_63 , V_93 -> V_30 ) ;
}
fprintf ( V_97 , L_64 ) ;
fprintf ( V_97 , L_65
L_66
L_67 ) ;
fprintf ( V_97 , L_68 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_93 = V_22 -> V_71 . V_72 ; V_93 ; V_93 = V_93 -> V_18 ) {
if ( V_95 ++ )
fprintf ( V_97 , L_61 ) ;
if ( V_96 && V_96 % 3 == 0 ) {
fprintf ( V_97 , L_69 ) ;
}
V_96 ++ ;
fprintf ( V_97 , L_70 , V_93 -> V_30 ) ;
if ( V_93 -> V_31 & V_73 ||
V_93 -> V_31 & V_98 ||
V_93 -> V_31 & V_99 )
fprintf ( V_97 , L_71 ) ;
else if ( V_93 -> V_31 & V_77 )
fprintf ( V_97 , L_72 ) ;
else
fprintf ( V_97 , L_73 ) ;
}
fprintf ( V_97 , L_74 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_93 = V_22 -> V_71 . V_72 ; V_93 ; V_93 = V_93 -> V_18 ) {
if ( V_95 ++ )
fprintf ( V_97 , L_61 ) ;
if ( ++ V_96 % 5 == 0 )
fprintf ( V_97 , L_75 ) ;
if ( V_93 -> V_31 & V_98 ) {
if ( ( V_96 - 1 ) % 5 != 0 ) {
fprintf ( V_97 , L_75 ) ;
V_96 = 4 ;
}
fprintf ( V_97 , L_76 ) ;
fprintf ( V_97 , L_77 , V_22 -> system ,
V_22 -> V_30 ) ;
fprintf ( V_97 , L_78 , V_93 -> V_30 ,
V_93 -> V_30 ) ;
} else if ( V_93 -> V_31 & V_99 ) {
if ( ( V_96 - 1 ) % 5 != 0 ) {
fprintf ( V_97 , L_75 ) ;
V_96 = 4 ;
}
fprintf ( V_97 , L_79 ) ;
fprintf ( V_97 , L_77 , V_22 -> system ,
V_22 -> V_30 ) ;
fprintf ( V_97 , L_78 , V_93 -> V_30 ,
V_93 -> V_30 ) ;
} else
fprintf ( V_97 , L_63 , V_93 -> V_30 ) ;
}
fprintf ( V_97 , L_80 ) ;
}
fprintf ( V_97 , L_81
L_82 ) ;
fprintf ( V_97 , L_83
L_84 ) ;
fprintf ( V_97 , L_85
L_86
L_87
L_88 ) ;
fclose ( V_97 ) ;
fprintf ( V_91 , L_89 , V_94 ) ;
return 0 ;
}
