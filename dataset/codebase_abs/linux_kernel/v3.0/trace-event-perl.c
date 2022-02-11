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
struct V_54 * T_3 V_49 ,
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
type = F_22 ( V_63 ) ;
V_24 = F_19 ( type ) ;
if ( ! V_24 )
F_23 ( L_10 , type ) ;
V_61 = F_24 ( V_63 ) ;
sprintf ( V_57 , L_9 , V_24 -> system , V_24 -> V_32 ) ;
V_59 = V_65 / V_67 ;
V_60 = V_65 - V_59 * V_67 ;
V_68 -> V_69 = V_63 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_57 , 0 ) ) ) ;
F_6 ( F_7 ( F_25 ( F_26 ( V_68 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_62 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_59 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_60 ) ) ) ;
F_6 ( F_7 ( F_25 ( V_61 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_66 , 0 ) ) ) ;
for ( V_20 = V_24 -> V_70 . V_71 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_34 & V_72 ) {
int V_73 ;
if ( V_20 -> V_34 & V_74 ) {
V_73 = * ( int * ) ( V_63 + V_20 -> V_73 ) ;
V_73 &= 0xffff ;
} else
V_73 = V_20 -> V_73 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_63 + V_73 , 0 ) ) ) ;
} else {
V_58 = F_27 ( V_63 + V_20 -> V_73 , V_20 -> V_75 ) ;
if ( V_20 -> V_34 & V_76 ) {
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
F_6 ( F_7 ( F_25 ( F_26 ( V_68 ) ) ) ) ;
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
static void F_28 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_12 , 0 ) )
F_11 ( L_12 , V_77 | V_78 ) ;
}
static int F_29 ( const char * V_79 , int V_80 , const char * * V_81 )
{
const char * * V_82 ;
int V_83 , V_84 = 0 ;
V_82 = malloc ( ( V_80 + 2 ) * sizeof( const char * ) ) ;
V_82 [ 0 ] = L_13 ;
V_82 [ 1 ] = V_79 ;
for ( V_83 = 2 ; V_83 < V_80 + 2 ; V_83 ++ )
V_82 [ V_83 ] = V_81 [ V_83 - 2 ] ;
V_85 = F_30 () ;
F_31 ( V_85 ) ;
if ( F_32 ( V_85 , F_1 , V_80 + 2 , ( char * * ) V_82 ,
( char * * ) NULL ) ) {
V_84 = - 1 ;
goto error;
}
if ( F_33 ( V_85 ) ) {
V_84 = - 1 ;
goto error;
}
if ( F_34 ( V_86 ) ) {
V_84 = - 1 ;
goto error;
}
F_28 () ;
free ( V_82 ) ;
return 0 ;
error:
F_35 ( V_85 ) ;
free ( V_82 ) ;
return V_84 ;
}
static int F_36 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_14 , 0 ) )
F_11 ( L_14 , V_77 | V_78 ) ;
F_37 ( V_85 ) ;
F_35 ( V_85 ) ;
return 0 ;
}
static int F_38 ( const char * V_87 )
{
struct V_24 * V_24 = NULL ;
struct V_56 * V_88 ;
char V_89 [ V_90 ] ;
int V_91 , V_92 ;
T_4 * V_93 ;
sprintf ( V_89 , L_15 , V_87 ) ;
V_93 = fopen ( V_89 , L_16 ) ;
if ( V_93 == NULL ) {
fprintf ( V_94 , L_17 , V_89 ) ;
return - 1 ;
}
fprintf ( V_93 , L_18
L_19 ) ;
fprintf ( V_93 , L_20
L_21 ) ;
fprintf ( V_93 , L_22
L_23 ) ;
fprintf ( V_93 , L_24
L_25 ) ;
fprintf ( V_93 , L_26
L_27 ) ;
fprintf ( V_93 , L_28
L_29 ) ;
fprintf ( V_93 , L_30
L_31 ) ;
fprintf ( V_93 , L_32
L_33 ) ;
fprintf ( V_93 , L_34 ) ;
fprintf ( V_93 , L_35 ) ;
fprintf ( V_93 , L_36 ) ;
fprintf ( V_93 , L_37 ) ;
fprintf ( V_93 , L_38 ) ;
fprintf ( V_93 , L_39 ) ;
while ( ( V_24 = F_39 ( V_24 ) ) ) {
fprintf ( V_93 , L_40 , V_24 -> system , V_24 -> V_32 ) ;
fprintf ( V_93 , L_41 ) ;
fprintf ( V_93 , L_42 ) ;
fprintf ( V_93 , L_43 ) ;
fprintf ( V_93 , L_44 ) ;
fprintf ( V_93 , L_45 ) ;
fprintf ( V_93 , L_46 ) ;
fprintf ( V_93 , L_47 ) ;
fprintf ( V_93 , L_48 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_88 = V_24 -> V_70 . V_71 ; V_88 ; V_88 = V_88 -> V_22 ) {
if ( V_91 ++ )
fprintf ( V_93 , L_49 ) ;
if ( ++ V_92 % 5 == 0 )
fprintf ( V_93 , L_50 ) ;
fprintf ( V_93 , L_51 , V_88 -> V_32 ) ;
}
fprintf ( V_93 , L_52 ) ;
fprintf ( V_93 , L_53
L_54
L_55 ) ;
fprintf ( V_93 , L_56 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_88 = V_24 -> V_70 . V_71 ; V_88 ; V_88 = V_88 -> V_22 ) {
if ( V_91 ++ )
fprintf ( V_93 , L_49 ) ;
if ( V_92 && V_92 % 4 == 0 ) {
fprintf ( V_93 , L_57 ) ;
}
V_92 ++ ;
fprintf ( V_93 , L_58 , V_88 -> V_32 ) ;
if ( V_88 -> V_34 & V_72 ||
V_88 -> V_34 & V_95 ||
V_88 -> V_34 & V_96 )
fprintf ( V_93 , L_59 ) ;
else if ( V_88 -> V_34 & V_76 )
fprintf ( V_93 , L_60 ) ;
else
fprintf ( V_93 , L_61 ) ;
}
fprintf ( V_93 , L_62 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_88 = V_24 -> V_70 . V_71 ; V_88 ; V_88 = V_88 -> V_22 ) {
if ( V_91 ++ )
fprintf ( V_93 , L_49 ) ;
if ( ++ V_92 % 5 == 0 )
fprintf ( V_93 , L_63 ) ;
if ( V_88 -> V_34 & V_95 ) {
if ( ( V_92 - 1 ) % 5 != 0 ) {
fprintf ( V_93 , L_63 ) ;
V_92 = 4 ;
}
fprintf ( V_93 , L_64 ) ;
fprintf ( V_93 , L_65 , V_24 -> system ,
V_24 -> V_32 ) ;
fprintf ( V_93 , L_66 , V_88 -> V_32 ,
V_88 -> V_32 ) ;
} else if ( V_88 -> V_34 & V_96 ) {
if ( ( V_92 - 1 ) % 5 != 0 ) {
fprintf ( V_93 , L_63 ) ;
V_92 = 4 ;
}
fprintf ( V_93 , L_67 ) ;
fprintf ( V_93 , L_65 , V_24 -> system ,
V_24 -> V_32 ) ;
fprintf ( V_93 , L_66 , V_88 -> V_32 ,
V_88 -> V_32 ) ;
} else
fprintf ( V_93 , L_51 , V_88 -> V_32 ) ;
}
fprintf ( V_93 , L_68 ) ;
fprintf ( V_93 , L_69 ) ;
}
fprintf ( V_93 , L_70
L_71
L_72 ) ;
fprintf ( V_93 , L_53
L_73
L_74 ) ;
fprintf ( V_93 , L_75
L_76
L_77
L_78 ) ;
fclose ( V_93 ) ;
fprintf ( V_94 , L_79 , V_89 ) ;
return 0 ;
}
