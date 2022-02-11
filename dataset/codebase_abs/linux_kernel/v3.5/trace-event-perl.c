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
case V_40 :
case V_41 :
break;
case V_42 :
F_17 ( V_25 , V_5 , args -> V_43 . V_44 ) ;
break;
case V_45 :
if ( strcmp ( args -> V_46 . V_46 , L_8 ) == 0 )
V_31 = 1 ;
F_17 ( V_25 , V_5 , args -> V_46 . V_47 ) ;
F_17 ( V_25 , V_5 , args -> V_46 . V_48 ) ;
break;
case V_49 :
default:
F_19 ( L_9 ) ;
return;
}
if ( args -> V_22 )
F_17 ( V_25 , V_5 , args -> V_22 ) ;
}
static inline struct V_24 * F_20 ( int type )
{
static char V_5 [ 256 ] ;
struct V_24 * V_25 ;
if ( V_50 [ type ] )
return V_50 [ type ] ;
V_50 [ type ] = V_25 = F_21 ( type ) ;
if ( ! V_25 )
return NULL ;
sprintf ( V_5 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
F_17 ( V_25 , V_5 , V_25 -> V_51 . args ) ;
return V_25 ;
}
static void F_22 ( union V_52 * T_2 V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_58 V_53 ,
struct V_59 * V_59 )
{
struct V_60 * V_20 ;
static char V_61 [ 256 ] ;
unsigned long long V_62 ;
unsigned long V_63 , V_64 ;
struct V_24 * V_25 ;
int type ;
int V_65 ;
int V_66 = V_55 -> V_66 ;
void * V_67 = V_55 -> V_68 ;
unsigned long long V_69 = V_55 -> time ;
char * V_70 = V_59 -> V_70 ;
V_10 ;
if ( V_57 -> V_71 . type != V_72 )
return;
type = F_23 ( V_67 ) ;
V_25 = F_20 ( type ) ;
if ( ! V_25 )
F_24 ( L_11 , type ) ;
V_65 = F_25 ( V_67 ) ;
sprintf ( V_61 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
V_63 = V_69 / V_73 ;
V_64 = V_69 - V_63 * V_73 ;
V_74 -> V_75 = V_67 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_61 , 0 ) ) ) ;
F_6 ( F_7 ( F_26 ( F_27 ( V_74 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_66 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_63 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_64 ) ) ) ;
F_6 ( F_7 ( F_26 ( V_65 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_70 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_76 . V_77 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_78 ) {
int V_79 ;
if ( V_20 -> V_35 & V_80 ) {
V_79 = * ( int * ) ( V_67 + V_20 -> V_79 ) ;
V_79 &= 0xffff ;
} else
V_79 = V_20 -> V_79 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_67 + V_79 , 0 ) ) ) ;
} else {
V_62 = F_28 ( V_67 + V_20 -> V_79 , V_20 -> V_81 ) ;
if ( V_20 -> V_35 & V_82 ) {
F_6 ( F_7 ( F_26 ( V_62 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_62 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_61 , 0 ) )
F_11 ( V_61 , V_15 ) ;
else if ( F_10 ( L_12 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_61 , 0 ) ) ) ;
F_6 ( F_7 ( F_26 ( F_27 ( V_74 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_66 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_26 ( V_65 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_70 , 0 ) ) ) ;
F_11 ( L_12 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_29 ( union V_52 * T_2 V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_57 V_53 ,
struct V_58 * V_58 V_53 ,
struct V_59 * V_59 V_53 )
{
V_10 ;
if ( ! F_10 ( L_13 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) T_2 , T_2 -> V_83 . V_81 ) ) ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) & V_57 -> V_71 , sizeof( V_57 -> V_71 ) ) ) ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) V_55 , sizeof( * V_55 ) ) ) ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) V_55 -> V_68 , V_55 -> V_84 ) ) ) ;
V_14 ;
F_11 ( L_13 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_31 ( union V_52 * T_2 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
struct V_59 * V_59 )
{
F_22 ( T_2 , V_55 , V_57 , V_58 , V_59 ) ;
F_29 ( T_2 , V_55 , V_57 , V_58 , V_59 ) ;
}
static void F_32 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_14 , 0 ) )
F_11 ( L_14 , V_85 | V_86 ) ;
}
static int F_33 ( const char * V_87 , int V_88 , const char * * V_89 )
{
const char * * V_90 ;
int V_91 , V_92 = 0 ;
V_90 = malloc ( ( V_88 + 2 ) * sizeof( const char * ) ) ;
V_90 [ 0 ] = L_15 ;
V_90 [ 1 ] = V_87 ;
for ( V_91 = 2 ; V_91 < V_88 + 2 ; V_91 ++ )
V_90 [ V_91 ] = V_89 [ V_91 - 2 ] ;
V_93 = F_34 () ;
F_35 ( V_93 ) ;
if ( F_36 ( V_93 , F_1 , V_88 + 2 , ( char * * ) V_90 ,
( char * * ) NULL ) ) {
V_92 = - 1 ;
goto error;
}
if ( F_37 ( V_93 ) ) {
V_92 = - 1 ;
goto error;
}
if ( F_38 ( V_94 ) ) {
V_92 = - 1 ;
goto error;
}
F_32 () ;
free ( V_90 ) ;
return 0 ;
error:
F_39 ( V_93 ) ;
free ( V_90 ) ;
return V_92 ;
}
static int F_40 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_16 , 0 ) )
F_11 ( L_16 , V_85 | V_86 ) ;
F_41 ( V_93 ) ;
F_39 ( V_93 ) ;
return 0 ;
}
static int F_42 ( const char * V_95 )
{
struct V_24 * V_25 = NULL ;
struct V_60 * V_96 ;
char V_97 [ V_98 ] ;
int V_99 , V_100 ;
T_3 * V_101 ;
sprintf ( V_97 , L_17 , V_95 ) ;
V_101 = fopen ( V_97 , L_18 ) ;
if ( V_101 == NULL ) {
fprintf ( V_102 , L_19 , V_97 ) ;
return - 1 ;
}
fprintf ( V_101 , L_20
L_21 ) ;
fprintf ( V_101 , L_22
L_23 ) ;
fprintf ( V_101 , L_24
L_25 ) ;
fprintf ( V_101 , L_26
L_27 ) ;
fprintf ( V_101 , L_28
L_29 ) ;
fprintf ( V_101 , L_30
L_31 ) ;
fprintf ( V_101 , L_32
L_33 ) ;
fprintf ( V_101 , L_34
L_35 ) ;
fprintf ( V_101 , L_36 ) ;
fprintf ( V_101 , L_37 ) ;
fprintf ( V_101 , L_38 ) ;
fprintf ( V_101 , L_39 ) ;
fprintf ( V_101 , L_40 ) ;
fprintf ( V_101 , L_41 ) ;
while ( ( V_25 = F_43 ( V_25 ) ) ) {
fprintf ( V_101 , L_42 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_101 , L_43 ) ;
fprintf ( V_101 , L_44 ) ;
fprintf ( V_101 , L_45 ) ;
fprintf ( V_101 , L_46 ) ;
fprintf ( V_101 , L_47 ) ;
fprintf ( V_101 , L_48 ) ;
fprintf ( V_101 , L_49 ) ;
fprintf ( V_101 , L_50 ) ;
V_99 = 0 ;
V_100 = 0 ;
for ( V_96 = V_25 -> V_76 . V_77 ; V_96 ; V_96 = V_96 -> V_22 ) {
if ( V_99 ++ )
fprintf ( V_101 , L_51 ) ;
if ( ++ V_100 % 5 == 0 )
fprintf ( V_101 , L_52 ) ;
fprintf ( V_101 , L_53 , V_96 -> V_33 ) ;
}
fprintf ( V_101 , L_54 ) ;
fprintf ( V_101 , L_55
L_56
L_57 ) ;
fprintf ( V_101 , L_58 ) ;
V_99 = 0 ;
V_100 = 0 ;
for ( V_96 = V_25 -> V_76 . V_77 ; V_96 ; V_96 = V_96 -> V_22 ) {
if ( V_99 ++ )
fprintf ( V_101 , L_51 ) ;
if ( V_100 && V_100 % 4 == 0 ) {
fprintf ( V_101 , L_59 ) ;
}
V_100 ++ ;
fprintf ( V_101 , L_60 , V_96 -> V_33 ) ;
if ( V_96 -> V_35 & V_78 ||
V_96 -> V_35 & V_103 ||
V_96 -> V_35 & V_104 )
fprintf ( V_101 , L_61 ) ;
else if ( V_96 -> V_35 & V_82 )
fprintf ( V_101 , L_62 ) ;
else
fprintf ( V_101 , L_63 ) ;
}
fprintf ( V_101 , L_64 ) ;
V_99 = 0 ;
V_100 = 0 ;
for ( V_96 = V_25 -> V_76 . V_77 ; V_96 ; V_96 = V_96 -> V_22 ) {
if ( V_99 ++ )
fprintf ( V_101 , L_51 ) ;
if ( ++ V_100 % 5 == 0 )
fprintf ( V_101 , L_65 ) ;
if ( V_96 -> V_35 & V_103 ) {
if ( ( V_100 - 1 ) % 5 != 0 ) {
fprintf ( V_101 , L_65 ) ;
V_100 = 4 ;
}
fprintf ( V_101 , L_66 ) ;
fprintf ( V_101 , L_67 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_101 , L_68 , V_96 -> V_33 ,
V_96 -> V_33 ) ;
} else if ( V_96 -> V_35 & V_104 ) {
if ( ( V_100 - 1 ) % 5 != 0 ) {
fprintf ( V_101 , L_65 ) ;
V_100 = 4 ;
}
fprintf ( V_101 , L_69 ) ;
fprintf ( V_101 , L_67 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_101 , L_68 , V_96 -> V_33 ,
V_96 -> V_33 ) ;
} else
fprintf ( V_101 , L_53 , V_96 -> V_33 ) ;
}
fprintf ( V_101 , L_70 ) ;
fprintf ( V_101 , L_71 ) ;
}
fprintf ( V_101 , L_72
L_73
L_74 ) ;
fprintf ( V_101 , L_55
L_75
L_76 ) ;
fprintf ( V_101 , L_77
L_78
L_79
L_80 ) ;
fprintf ( V_101 ,
L_81
L_82
L_83
L_84
L_85
L_86
L_87
L_88
L_89
L_90
L_87
L_91
L_92
L_93
L_94
L_87
L_95
L_96
L_97 ) ;
fclose ( V_101 ) ;
fprintf ( V_102 , L_98 , V_97 ) ;
return 0 ;
}
