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
static void F_17 ( struct V_24 * V_24 ,
const char * V_5 ,
struct V_25 * args )
{
switch ( args -> type ) {
case V_26 :
break;
case V_27 :
F_14 ( V_5 , V_28 , L_7 ,
args -> V_29 . V_29 ) ;
V_30 = 0 ;
break;
case V_31 :
if ( V_28 )
free ( V_28 ) ;
V_28 = F_18 ( args -> V_20 . V_32 ) ;
break;
case V_33 :
F_17 ( V_24 , V_5 , args -> V_34 . V_20 ) ;
F_16 ( V_5 , V_28 , args -> V_34 . V_23 ) ;
F_15 ( args -> V_34 . V_34 , V_5 , V_28 ) ;
break;
case V_35 :
F_17 ( V_24 , V_5 , args -> V_36 . V_20 ) ;
F_13 ( V_5 , V_28 ) ;
F_12 ( args -> V_36 . V_37 , V_5 ,
V_28 ) ;
break;
case V_38 :
break;
case V_39 :
F_17 ( V_24 , V_5 , args -> V_40 . V_41 ) ;
break;
case V_42 :
if ( strcmp ( args -> V_43 . V_43 , L_8 ) == 0 )
V_30 = 1 ;
F_17 ( V_24 , V_5 , args -> V_43 . V_44 ) ;
F_17 ( V_24 , V_5 , args -> V_43 . V_45 ) ;
break;
default:
return;
}
if ( args -> V_22 )
F_17 ( V_24 , V_5 , args -> V_22 ) ;
}
static inline struct V_24 * F_19 ( int type )
{
static char V_5 [ 256 ] ;
struct V_24 * V_24 ;
if ( V_46 [ type ] )
return V_46 [ type ] ;
V_46 [ type ] = V_24 = F_20 ( type ) ;
if ( ! V_24 )
return NULL ;
sprintf ( V_5 , L_9 , V_24 -> system , V_24 -> V_32 ) ;
F_17 ( V_24 , V_5 , V_24 -> V_47 . args ) ;
return V_24 ;
}
static void F_21 ( union V_48 * T_2 V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_54 V_49 ,
struct V_55 * V_55 )
{
struct V_56 * V_20 ;
static char V_57 [ 256 ] ;
unsigned long long V_58 ;
unsigned long V_59 , V_60 ;
struct V_24 * V_24 ;
int type ;
int V_61 ;
int V_62 = V_51 -> V_62 ;
void * V_63 = V_51 -> V_64 ;
unsigned long long V_65 = V_51 -> time ;
char * V_66 = V_55 -> V_66 ;
V_10 ;
if ( V_53 -> V_67 . type != V_68 )
return;
type = F_22 ( V_63 ) ;
V_24 = F_19 ( type ) ;
if ( ! V_24 )
F_23 ( L_10 , type ) ;
V_61 = F_24 ( V_63 ) ;
sprintf ( V_57 , L_9 , V_24 -> system , V_24 -> V_32 ) ;
V_59 = V_65 / V_69 ;
V_60 = V_65 - V_59 * V_69 ;
V_70 -> V_71 = V_63 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_57 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_70 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_62 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_59 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_60 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_61 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_66 , 0 ) ) ) ;
for ( V_20 = V_24 -> V_72 . V_73 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_34 & V_74 ) {
int V_75 ;
if ( V_20 -> V_34 & V_76 ) {
V_75 = * ( int * ) ( V_63 + V_20 -> V_75 ) ;
V_75 &= 0xffff ;
} else
V_75 = V_20 -> V_75 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_63 + V_75 , 0 ) ) ) ;
} else {
V_58 = F_27 ( V_63 + V_20 -> V_75 , V_20 -> V_77 ) ;
if ( V_20 -> V_34 & V_78 ) {
F_6 ( F_7 ( F_25 ( V_58 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_58 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_57 , 0 ) )
F_11 ( V_57 , V_15 ) ;
else if ( F_10 ( L_11 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_57 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_70 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_62 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_65 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_61 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_66 , 0 ) ) ) ;
F_11 ( L_11 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_28 ( union V_48 * T_2 V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_53 V_49 ,
struct V_54 * V_54 V_49 ,
struct V_55 * V_55 V_49 )
{
V_10 ;
if ( ! F_10 ( L_12 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) T_2 , T_2 -> V_79 . V_77 ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) & V_53 -> V_67 , sizeof( V_53 -> V_67 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_51 , sizeof( * V_51 ) ) ) ) ;
F_6 ( F_7 ( F_29 ( ( const char * ) V_51 -> V_64 , V_51 -> V_80 ) ) ) ;
V_14 ;
F_11 ( L_12 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_30 ( union V_48 * T_2 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_54 ,
struct V_55 * V_55 )
{
F_21 ( T_2 , V_51 , V_53 , V_54 , V_55 ) ;
F_28 ( T_2 , V_51 , V_53 , V_54 , V_55 ) ;
}
static void F_31 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_13 , 0 ) )
F_11 ( L_13 , V_81 | V_82 ) ;
}
static int F_32 ( const char * V_83 , int V_84 , const char * * V_85 )
{
const char * * V_86 ;
int V_87 , V_88 = 0 ;
V_86 = malloc ( ( V_84 + 2 ) * sizeof( const char * ) ) ;
V_86 [ 0 ] = L_14 ;
V_86 [ 1 ] = V_83 ;
for ( V_87 = 2 ; V_87 < V_84 + 2 ; V_87 ++ )
V_86 [ V_87 ] = V_85 [ V_87 - 2 ] ;
V_89 = F_33 () ;
F_34 ( V_89 ) ;
if ( F_35 ( V_89 , F_1 , V_84 + 2 , ( char * * ) V_86 ,
( char * * ) NULL ) ) {
V_88 = - 1 ;
goto error;
}
if ( F_36 ( V_89 ) ) {
V_88 = - 1 ;
goto error;
}
if ( F_37 ( V_90 ) ) {
V_88 = - 1 ;
goto error;
}
F_31 () ;
free ( V_86 ) ;
return 0 ;
error:
F_38 ( V_89 ) ;
free ( V_86 ) ;
return V_88 ;
}
static int F_39 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_15 , 0 ) )
F_11 ( L_15 , V_81 | V_82 ) ;
F_40 ( V_89 ) ;
F_38 ( V_89 ) ;
return 0 ;
}
static int F_41 ( const char * V_91 )
{
struct V_24 * V_24 = NULL ;
struct V_56 * V_92 ;
char V_93 [ V_94 ] ;
int V_95 , V_96 ;
T_3 * V_97 ;
sprintf ( V_93 , L_16 , V_91 ) ;
V_97 = fopen ( V_93 , L_17 ) ;
if ( V_97 == NULL ) {
fprintf ( V_98 , L_18 , V_93 ) ;
return - 1 ;
}
fprintf ( V_97 , L_19
L_20 ) ;
fprintf ( V_97 , L_21
L_22 ) ;
fprintf ( V_97 , L_23
L_24 ) ;
fprintf ( V_97 , L_25
L_26 ) ;
fprintf ( V_97 , L_27
L_28 ) ;
fprintf ( V_97 , L_29
L_30 ) ;
fprintf ( V_97 , L_31
L_32 ) ;
fprintf ( V_97 , L_33
L_34 ) ;
fprintf ( V_97 , L_35 ) ;
fprintf ( V_97 , L_36 ) ;
fprintf ( V_97 , L_37 ) ;
fprintf ( V_97 , L_38 ) ;
fprintf ( V_97 , L_39 ) ;
fprintf ( V_97 , L_40 ) ;
while ( ( V_24 = F_42 ( V_24 ) ) ) {
fprintf ( V_97 , L_41 , V_24 -> system , V_24 -> V_32 ) ;
fprintf ( V_97 , L_42 ) ;
fprintf ( V_97 , L_43 ) ;
fprintf ( V_97 , L_44 ) ;
fprintf ( V_97 , L_45 ) ;
fprintf ( V_97 , L_46 ) ;
fprintf ( V_97 , L_47 ) ;
fprintf ( V_97 , L_48 ) ;
fprintf ( V_97 , L_49 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_92 = V_24 -> V_72 . V_73 ; V_92 ; V_92 = V_92 -> V_22 ) {
if ( V_95 ++ )
fprintf ( V_97 , L_50 ) ;
if ( ++ V_96 % 5 == 0 )
fprintf ( V_97 , L_51 ) ;
fprintf ( V_97 , L_52 , V_92 -> V_32 ) ;
}
fprintf ( V_97 , L_53 ) ;
fprintf ( V_97 , L_54
L_55
L_56 ) ;
fprintf ( V_97 , L_57 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_92 = V_24 -> V_72 . V_73 ; V_92 ; V_92 = V_92 -> V_22 ) {
if ( V_95 ++ )
fprintf ( V_97 , L_50 ) ;
if ( V_96 && V_96 % 4 == 0 ) {
fprintf ( V_97 , L_58 ) ;
}
V_96 ++ ;
fprintf ( V_97 , L_59 , V_92 -> V_32 ) ;
if ( V_92 -> V_34 & V_74 ||
V_92 -> V_34 & V_99 ||
V_92 -> V_34 & V_100 )
fprintf ( V_97 , L_60 ) ;
else if ( V_92 -> V_34 & V_78 )
fprintf ( V_97 , L_61 ) ;
else
fprintf ( V_97 , L_62 ) ;
}
fprintf ( V_97 , L_63 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_92 = V_24 -> V_72 . V_73 ; V_92 ; V_92 = V_92 -> V_22 ) {
if ( V_95 ++ )
fprintf ( V_97 , L_50 ) ;
if ( ++ V_96 % 5 == 0 )
fprintf ( V_97 , L_64 ) ;
if ( V_92 -> V_34 & V_99 ) {
if ( ( V_96 - 1 ) % 5 != 0 ) {
fprintf ( V_97 , L_64 ) ;
V_96 = 4 ;
}
fprintf ( V_97 , L_65 ) ;
fprintf ( V_97 , L_66 , V_24 -> system ,
V_24 -> V_32 ) ;
fprintf ( V_97 , L_67 , V_92 -> V_32 ,
V_92 -> V_32 ) ;
} else if ( V_92 -> V_34 & V_100 ) {
if ( ( V_96 - 1 ) % 5 != 0 ) {
fprintf ( V_97 , L_64 ) ;
V_96 = 4 ;
}
fprintf ( V_97 , L_68 ) ;
fprintf ( V_97 , L_66 , V_24 -> system ,
V_24 -> V_32 ) ;
fprintf ( V_97 , L_67 , V_92 -> V_32 ,
V_92 -> V_32 ) ;
} else
fprintf ( V_97 , L_52 , V_92 -> V_32 ) ;
}
fprintf ( V_97 , L_69 ) ;
fprintf ( V_97 , L_70 ) ;
}
fprintf ( V_97 , L_71
L_72
L_73 ) ;
fprintf ( V_97 , L_54
L_74
L_75 ) ;
fprintf ( V_97 , L_76
L_77
L_78
L_79 ) ;
fprintf ( V_97 ,
L_80
L_81
L_82
L_83
L_84
L_85
L_86
L_87
L_88
L_89
L_86
L_90
L_91
L_92
L_93
L_86
L_94
L_95
L_96 ) ;
fclose ( V_97 ) ;
fprintf ( V_98 , L_97 , V_93 ) ;
return 0 ;
}
