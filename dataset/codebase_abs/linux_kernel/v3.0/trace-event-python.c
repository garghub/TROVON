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
static void F_16 ( struct V_21 * V_21 ,
const char * V_4 ,
struct V_22 * args )
{
switch ( args -> type ) {
case V_23 :
break;
case V_24 :
F_4 ( V_20 , V_4 , V_25 , L_7 ,
args -> V_26 . V_26 ) ;
V_27 = 0 ;
break;
case V_28 :
if ( V_25 )
free ( V_25 ) ;
V_25 = F_17 ( args -> V_16 . V_29 ) ;
break;
case V_20 :
F_16 ( V_21 , V_4 , args -> V_30 . V_16 ) ;
F_15 ( V_20 , V_4 , V_25 ,
args -> V_30 . V_19 ) ;
F_14 ( V_20 , args -> V_30 . V_30 , V_4 ,
V_25 ) ;
break;
case V_13 :
F_16 ( V_21 , V_4 , args -> V_31 . V_16 ) ;
F_15 ( V_13 , V_4 , V_25 , NULL ) ;
F_14 ( V_13 , args -> V_31 . V_32 , V_4 ,
V_25 ) ;
break;
case V_33 :
break;
case V_34 :
F_16 ( V_21 , V_4 , args -> V_35 . V_36 ) ;
break;
case V_37 :
if ( strcmp ( args -> V_38 . V_38 , L_8 ) == 0 )
V_27 = 1 ;
F_16 ( V_21 , V_4 , args -> V_38 . V_39 ) ;
F_16 ( V_21 , V_4 , args -> V_38 . V_40 ) ;
break;
default:
return;
}
if ( args -> V_18 )
F_16 ( V_21 , V_4 , args -> V_18 ) ;
}
static inline struct V_21 * F_18 ( int type )
{
static char V_4 [ 256 ] ;
struct V_21 * V_21 ;
if ( V_41 [ type ] )
return V_41 [ type ] ;
V_41 [ type ] = V_21 = F_19 ( type ) ;
if ( ! V_21 )
return NULL ;
sprintf ( V_4 , L_9 , V_21 -> system , V_21 -> V_29 ) ;
F_16 ( V_21 , V_4 , V_21 -> V_42 . args ) ;
return V_21 ;
}
static void F_20 ( union V_43 * T_2 V_44 ,
struct V_45 * V_46 ,
struct V_47 * T_3 V_44 ,
struct V_48 * T_4 V_44 ,
struct V_49 * V_49 )
{
T_1 * V_8 , * V_10 , * V_50 , * V_9 , * V_51 , * V_52 = NULL ;
static char V_1 [ 256 ] ;
struct V_53 * V_16 ;
unsigned long long V_54 ;
unsigned long V_55 , V_56 ;
struct V_21 * V_21 ;
unsigned V_12 = 0 ;
int type ;
int V_57 ;
int V_58 = V_46 -> V_58 ;
void * V_59 = V_46 -> V_60 ;
unsigned long long V_61 = V_46 -> time ;
char * V_62 = V_49 -> V_62 ;
V_9 = F_5 ( V_63 ) ;
if ( ! V_9 )
F_3 ( L_4 ) ;
type = F_21 ( V_59 ) ;
V_21 = F_18 ( type ) ;
if ( ! V_21 )
F_22 ( L_10 , type ) ;
V_57 = F_23 ( V_59 ) ;
sprintf ( V_1 , L_9 , V_21 -> system , V_21 -> V_29 ) ;
V_8 = F_10 ( V_14 , V_1 ) ;
if ( V_8 && ! F_11 ( V_8 ) )
V_8 = NULL ;
if ( ! V_8 ) {
V_52 = F_24 () ;
if ( ! V_52 )
F_3 ( L_11 ) ;
}
V_55 = V_61 / V_64 ;
V_56 = V_61 - V_55 * V_64 ;
V_65 -> V_66 = V_59 ;
V_50 = F_25 ( V_65 , NULL ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_1 ) ) ;
F_7 ( V_9 , V_12 ++ , V_50 ) ;
if ( V_8 ) {
F_7 ( V_9 , V_12 ++ , F_9 ( V_58 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_55 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_56 ) ) ;
F_7 ( V_9 , V_12 ++ , F_9 ( V_57 ) ) ;
F_7 ( V_9 , V_12 ++ , F_8 ( V_62 ) ) ;
} else {
F_26 ( V_52 , L_12 , F_9 ( V_58 ) ) ;
F_26 ( V_52 , L_13 , F_9 ( V_55 ) ) ;
F_26 ( V_52 , L_14 , F_9 ( V_56 ) ) ;
F_26 ( V_52 , L_15 , F_9 ( V_57 ) ) ;
F_26 ( V_52 , L_16 , F_8 ( V_62 ) ) ;
}
for ( V_16 = V_21 -> V_67 . V_68 ; V_16 ; V_16 = V_16 -> V_18 ) {
if ( V_16 -> V_30 & V_69 ) {
int V_70 ;
if ( V_16 -> V_30 & V_71 ) {
V_70 = * ( int * ) ( V_59 + V_16 -> V_70 ) ;
V_70 &= 0xffff ;
} else
V_70 = V_16 -> V_70 ;
V_51 = F_8 ( ( char * ) V_59 + V_70 ) ;
} else {
V_54 = F_27 ( V_59 + V_16 -> V_70 , V_16 -> V_72 ) ;
if ( V_16 -> V_30 & V_73 ) {
if ( ( long long ) V_54 >= V_74 &&
( long long ) V_54 <= V_75 )
V_51 = F_9 ( V_54 ) ;
else
V_51 = F_28 ( V_54 ) ;
} else {
if ( V_54 <= V_75 )
V_51 = F_9 ( V_54 ) ;
else
V_51 = F_29 ( V_54 ) ;
}
}
if ( V_8 )
F_7 ( V_9 , V_12 ++ , V_51 ) ;
else
F_26 ( V_52 , V_16 -> V_29 , V_51 ) ;
}
if ( ! V_8 )
F_7 ( V_9 , V_12 ++ , V_52 ) ;
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
F_13 ( V_52 ) ;
}
F_13 ( V_9 ) ;
}
static int F_31 ( void )
{
T_1 * V_8 , * V_10 ;
int V_76 = 0 ;
V_77 = F_32 ( L_19 ) ;
if ( V_77 == NULL )
return - 1 ;
F_33 ( V_77 ) ;
V_14 = F_34 ( V_77 ) ;
if ( V_14 == NULL ) {
V_76 = - 1 ;
goto error;
}
F_33 ( V_14 ) ;
V_8 = F_10 ( V_14 , L_20 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_78;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_20 ) ;
F_13 ( V_10 ) ;
return V_76 ;
error:
F_35 ( V_14 ) ;
F_35 ( V_77 ) ;
V_78:
return V_76 ;
}
static int F_36 ( const char * V_79 , int V_80 , const char * * V_81 )
{
const char * * V_82 ;
char V_83 [ V_84 ] ;
int V_85 , V_76 = 0 ;
T_5 * V_86 ;
V_82 = malloc ( ( V_80 + 1 ) * sizeof( const char * ) ) ;
V_82 [ 0 ] = V_79 ;
for ( V_85 = 1 ; V_85 < V_80 + 1 ; V_85 ++ )
V_82 [ V_85 ] = V_81 [ V_85 - 1 ] ;
F_37 () ;
F_38 () ;
F_39 ( V_80 + 1 , ( char * * ) V_82 ) ;
V_86 = fopen ( V_79 , L_21 ) ;
if ( ! V_86 ) {
sprintf ( V_83 , L_22 , V_79 ) ;
perror ( V_83 ) ;
V_76 = - 1 ;
goto error;
}
V_76 = F_40 ( V_86 , V_79 ) ;
if ( V_76 ) {
fprintf ( V_87 , L_23 , V_79 ) ;
goto error;
}
V_76 = F_31 () ;
if ( V_76 ) {
fprintf ( V_87 , L_24 , V_79 ) ;
goto error;
}
free ( V_82 ) ;
return V_76 ;
error:
F_41 () ;
free ( V_82 ) ;
return V_76 ;
}
static int F_42 ( void )
{
T_1 * V_8 , * V_10 ;
int V_76 = 0 ;
V_8 = F_10 ( V_14 , L_25 ) ;
if ( V_8 == NULL || ! F_11 ( V_8 ) )
goto V_78;
V_10 = F_12 ( V_8 , NULL ) ;
if ( V_10 == NULL )
F_1 ( L_25 ) ;
else
F_13 ( V_10 ) ;
V_78:
F_35 ( V_14 ) ;
F_35 ( V_77 ) ;
F_41 () ;
return V_76 ;
}
static int F_43 ( const char * V_88 )
{
struct V_21 * V_21 = NULL ;
struct V_53 * V_89 ;
char V_90 [ V_84 ] ;
int V_91 , V_92 ;
T_5 * V_93 ;
sprintf ( V_90 , L_26 , V_88 ) ;
V_93 = fopen ( V_90 , L_27 ) ;
if ( V_93 == NULL ) {
fprintf ( V_87 , L_28 , V_90 ) ;
return - 1 ;
}
fprintf ( V_93 , L_29
L_30 ) ;
fprintf ( V_93 , L_31
L_32 ) ;
fprintf ( V_93 , L_33
L_34 ) ;
fprintf ( V_93 , L_35
L_36 ) ;
fprintf ( V_93 , L_37
L_38 ) ;
fprintf ( V_93 , L_39
L_40 ) ;
fprintf ( V_93 , L_41
L_42 ) ;
fprintf ( V_93 , L_43 ) ;
fprintf ( V_93 , L_44 ) ;
fprintf ( V_93 , L_45 ) ;
fprintf ( V_93 , L_46 ) ;
fprintf ( V_93 , L_47 ) ;
fprintf ( V_93 , L_48 ) ;
fprintf ( V_93 , L_49 ) ;
fprintf ( V_93 , L_50 ) ;
fprintf ( V_93 , L_51 ) ;
fprintf ( V_93 , L_52 ) ;
while ( ( V_21 = F_44 ( V_21 ) ) ) {
fprintf ( V_93 , L_53 , V_21 -> system , V_21 -> V_29 ) ;
fprintf ( V_93 , L_54 ) ;
fprintf ( V_93 , L_55 ) ;
fprintf ( V_93 , L_56 ) ;
fprintf ( V_93 , L_57 ) ;
fprintf ( V_93 , L_58 ) ;
fprintf ( V_93 , L_59 ) ;
fprintf ( V_93 , L_60 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_89 = V_21 -> V_67 . V_68 ; V_89 ; V_89 = V_89 -> V_18 ) {
if ( V_91 ++ )
fprintf ( V_93 , L_61 ) ;
if ( ++ V_92 % 5 == 0 )
fprintf ( V_93 , L_62 ) ;
fprintf ( V_93 , L_63 , V_89 -> V_29 ) ;
}
fprintf ( V_93 , L_64 ) ;
fprintf ( V_93 , L_65
L_66
L_67 ) ;
fprintf ( V_93 , L_68 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_89 = V_21 -> V_67 . V_68 ; V_89 ; V_89 = V_89 -> V_18 ) {
if ( V_91 ++ )
fprintf ( V_93 , L_61 ) ;
if ( V_92 && V_92 % 3 == 0 ) {
fprintf ( V_93 , L_69 ) ;
}
V_92 ++ ;
fprintf ( V_93 , L_70 , V_89 -> V_29 ) ;
if ( V_89 -> V_30 & V_69 ||
V_89 -> V_30 & V_94 ||
V_89 -> V_30 & V_95 )
fprintf ( V_93 , L_71 ) ;
else if ( V_89 -> V_30 & V_73 )
fprintf ( V_93 , L_72 ) ;
else
fprintf ( V_93 , L_73 ) ;
}
fprintf ( V_93 , L_74 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_89 = V_21 -> V_67 . V_68 ; V_89 ; V_89 = V_89 -> V_18 ) {
if ( V_91 ++ )
fprintf ( V_93 , L_61 ) ;
if ( ++ V_92 % 5 == 0 )
fprintf ( V_93 , L_75 ) ;
if ( V_89 -> V_30 & V_94 ) {
if ( ( V_92 - 1 ) % 5 != 0 ) {
fprintf ( V_93 , L_75 ) ;
V_92 = 4 ;
}
fprintf ( V_93 , L_76 ) ;
fprintf ( V_93 , L_77 , V_21 -> system ,
V_21 -> V_29 ) ;
fprintf ( V_93 , L_78 , V_89 -> V_29 ,
V_89 -> V_29 ) ;
} else if ( V_89 -> V_30 & V_95 ) {
if ( ( V_92 - 1 ) % 5 != 0 ) {
fprintf ( V_93 , L_75 ) ;
V_92 = 4 ;
}
fprintf ( V_93 , L_79 ) ;
fprintf ( V_93 , L_77 , V_21 -> system ,
V_21 -> V_29 ) ;
fprintf ( V_93 , L_78 , V_89 -> V_29 ,
V_89 -> V_29 ) ;
} else
fprintf ( V_93 , L_63 , V_89 -> V_29 ) ;
}
fprintf ( V_93 , L_80 ) ;
}
fprintf ( V_93 , L_81
L_82 ) ;
fprintf ( V_93 , L_83
L_84 ) ;
fprintf ( V_93 , L_85
L_86
L_87
L_88 ) ;
fclose ( V_93 ) ;
fprintf ( V_87 , L_89 , V_90 ) ;
return 0 ;
}
