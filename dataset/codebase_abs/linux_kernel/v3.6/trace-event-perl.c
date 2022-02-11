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
static inline
struct V_24 * F_20 ( struct V_53 * V_53 , int type )
{
static char V_5 [ 256 ] ;
struct V_24 * V_25 ;
if ( V_54 [ type ] )
return V_54 [ type ] ;
V_54 [ type ] = V_25 = F_21 ( V_53 , type ) ;
if ( ! V_25 )
return NULL ;
sprintf ( V_5 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
F_17 ( V_25 , V_5 , V_25 -> V_55 . args ) ;
return V_25 ;
}
static void F_22 ( union V_56 * V_56 V_57 ,
struct V_53 * V_53 ,
struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_62 V_57 ,
struct V_63 * V_63 )
{
struct V_64 * V_20 ;
static char V_65 [ 256 ] ;
unsigned long long V_66 ;
unsigned long V_67 , V_68 ;
struct V_24 * V_25 ;
int type ;
int V_69 ;
int V_70 = V_59 -> V_70 ;
void * V_71 = V_59 -> V_72 ;
unsigned long long V_73 = V_59 -> time ;
char * V_74 = V_63 -> V_74 ;
V_10 ;
if ( V_61 -> V_75 . type != V_76 )
return;
type = F_23 ( V_53 , V_71 ) ;
V_25 = F_20 ( V_53 , type ) ;
if ( ! V_25 )
F_24 ( L_11 , type ) ;
V_69 = F_25 ( V_53 , V_71 ) ;
sprintf ( V_65 , L_10 , V_25 -> system , V_25 -> V_33 ) ;
V_67 = V_73 / V_77 ;
V_68 = V_73 - V_67 * V_77 ;
V_78 -> V_79 = V_71 ;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_8 ( V_65 , 0 ) ) ) ;
F_6 ( F_7 ( F_26 ( F_27 ( V_78 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_67 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_68 ) ) ) ;
F_6 ( F_7 ( F_26 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_74 , 0 ) ) ) ;
for ( V_20 = V_25 -> V_80 . V_81 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_82 ) {
int V_83 ;
if ( V_20 -> V_35 & V_84 ) {
V_83 = * ( int * ) ( V_71 + V_20 -> V_83 ) ;
V_83 &= 0xffff ;
} else
V_83 = V_20 -> V_83 ;
F_6 ( F_7 ( F_8 ( ( char * ) V_71 + V_83 , 0 ) ) ) ;
} else {
V_66 = F_28 ( V_53 , V_71 + V_20 -> V_83 ,
V_20 -> V_41 ) ;
if ( V_20 -> V_35 & V_85 ) {
F_6 ( F_7 ( F_26 ( V_66 ) ) ) ;
} else {
F_6 ( F_7 ( F_9 ( V_66 ) ) ) ;
}
}
}
V_14 ;
if ( F_10 ( V_65 , 0 ) )
F_11 ( V_65 , V_15 ) ;
else if ( F_10 ( L_12 , 0 ) ) {
F_6 ( F_7 ( F_8 ( V_65 , 0 ) ) ) ;
F_6 ( F_7 ( F_26 ( F_27 ( V_78 ) ) ) ) ;
F_6 ( F_7 ( F_9 ( V_70 ) ) ) ;
F_6 ( F_7 ( F_9 ( V_73 ) ) ) ;
F_6 ( F_7 ( F_26 ( V_69 ) ) ) ;
F_6 ( F_7 ( F_8 ( V_74 , 0 ) ) ) ;
F_11 ( L_12 , V_15 ) ;
}
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_29 ( union V_56 * V_53 V_57 ,
struct V_58 * V_59 ,
struct V_60 * V_61 V_57 ,
struct V_62 * V_62 V_57 ,
struct V_63 * V_63 V_57 )
{
V_10 ;
if ( ! F_10 ( L_13 , 0 ) )
return;
V_11 ;
V_12 ;
F_5 ( V_13 ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) V_53 , V_53 -> V_86 . V_41 ) ) ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) & V_61 -> V_75 , sizeof( V_61 -> V_75 ) ) ) ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) V_59 , sizeof( * V_59 ) ) ) ) ;
F_6 ( F_7 ( F_30 ( ( const char * ) V_59 -> V_72 , V_59 -> V_87 ) ) ) ;
V_14 ;
F_11 ( L_13 , V_15 ) ;
V_16 ;
V_14 ;
V_17 ;
V_18 ;
}
static void F_31 ( union V_56 * V_25 ,
struct V_53 * V_53 ,
struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_62 ,
struct V_63 * V_63 )
{
F_22 ( V_25 , V_53 , V_59 , V_61 , V_62 , V_63 ) ;
F_29 ( V_25 , V_59 , V_61 , V_62 , V_63 ) ;
}
static void F_32 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_14 , 0 ) )
F_11 ( L_14 , V_88 | V_89 ) ;
}
static int F_33 ( const char * V_90 , int V_91 , const char * * V_92 )
{
const char * * V_93 ;
int V_94 , V_95 = 0 ;
V_93 = malloc ( ( V_91 + 2 ) * sizeof( const char * ) ) ;
V_93 [ 0 ] = L_15 ;
V_93 [ 1 ] = V_90 ;
for ( V_94 = 2 ; V_94 < V_91 + 2 ; V_94 ++ )
V_93 [ V_94 ] = V_92 [ V_94 - 2 ] ;
V_96 = F_34 () ;
F_35 ( V_96 ) ;
if ( F_36 ( V_96 , F_1 , V_91 + 2 , ( char * * ) V_93 ,
( char * * ) NULL ) ) {
V_95 = - 1 ;
goto error;
}
if ( F_37 ( V_96 ) ) {
V_95 = - 1 ;
goto error;
}
if ( F_38 ( V_97 ) ) {
V_95 = - 1 ;
goto error;
}
F_32 () ;
free ( V_93 ) ;
return 0 ;
error:
F_39 ( V_96 ) ;
free ( V_93 ) ;
return V_95 ;
}
static int F_40 ( void )
{
V_10 ;
F_5 ( V_13 ) ;
if ( F_10 ( L_16 , 0 ) )
F_11 ( L_16 , V_88 | V_89 ) ;
F_41 ( V_96 ) ;
F_39 ( V_96 ) ;
return 0 ;
}
static int F_42 ( struct V_53 * V_53 , const char * V_98 )
{
struct V_24 * V_25 = NULL ;
struct V_64 * V_99 ;
char V_100 [ V_101 ] ;
int V_102 , V_103 ;
T_2 * V_104 ;
sprintf ( V_100 , L_17 , V_98 ) ;
V_104 = fopen ( V_100 , L_18 ) ;
if ( V_104 == NULL ) {
fprintf ( V_105 , L_19 , V_100 ) ;
return - 1 ;
}
fprintf ( V_104 , L_20
L_21 ) ;
fprintf ( V_104 , L_22
L_23 ) ;
fprintf ( V_104 , L_24
L_25 ) ;
fprintf ( V_104 , L_26
L_27 ) ;
fprintf ( V_104 , L_28
L_29 ) ;
fprintf ( V_104 , L_30
L_31 ) ;
fprintf ( V_104 , L_32
L_33 ) ;
fprintf ( V_104 , L_34
L_35 ) ;
fprintf ( V_104 , L_36 ) ;
fprintf ( V_104 , L_37 ) ;
fprintf ( V_104 , L_38 ) ;
fprintf ( V_104 , L_39 ) ;
fprintf ( V_104 , L_40 ) ;
fprintf ( V_104 , L_41 ) ;
while ( ( V_25 = F_43 ( V_53 , V_25 ) ) ) {
fprintf ( V_104 , L_42 , V_25 -> system , V_25 -> V_33 ) ;
fprintf ( V_104 , L_43 ) ;
fprintf ( V_104 , L_44 ) ;
fprintf ( V_104 , L_45 ) ;
fprintf ( V_104 , L_46 ) ;
fprintf ( V_104 , L_47 ) ;
fprintf ( V_104 , L_48 ) ;
fprintf ( V_104 , L_49 ) ;
fprintf ( V_104 , L_50 ) ;
V_102 = 0 ;
V_103 = 0 ;
for ( V_99 = V_25 -> V_80 . V_81 ; V_99 ; V_99 = V_99 -> V_22 ) {
if ( V_102 ++ )
fprintf ( V_104 , L_51 ) ;
if ( ++ V_103 % 5 == 0 )
fprintf ( V_104 , L_52 ) ;
fprintf ( V_104 , L_53 , V_99 -> V_33 ) ;
}
fprintf ( V_104 , L_54 ) ;
fprintf ( V_104 , L_55
L_56
L_57 ) ;
fprintf ( V_104 , L_58 ) ;
V_102 = 0 ;
V_103 = 0 ;
for ( V_99 = V_25 -> V_80 . V_81 ; V_99 ; V_99 = V_99 -> V_22 ) {
if ( V_102 ++ )
fprintf ( V_104 , L_51 ) ;
if ( V_103 && V_103 % 4 == 0 ) {
fprintf ( V_104 , L_59 ) ;
}
V_103 ++ ;
fprintf ( V_104 , L_60 , V_99 -> V_33 ) ;
if ( V_99 -> V_35 & V_82 ||
V_99 -> V_35 & V_106 ||
V_99 -> V_35 & V_107 )
fprintf ( V_104 , L_61 ) ;
else if ( V_99 -> V_35 & V_85 )
fprintf ( V_104 , L_62 ) ;
else
fprintf ( V_104 , L_63 ) ;
}
fprintf ( V_104 , L_64 ) ;
V_102 = 0 ;
V_103 = 0 ;
for ( V_99 = V_25 -> V_80 . V_81 ; V_99 ; V_99 = V_99 -> V_22 ) {
if ( V_102 ++ )
fprintf ( V_104 , L_51 ) ;
if ( ++ V_103 % 5 == 0 )
fprintf ( V_104 , L_65 ) ;
if ( V_99 -> V_35 & V_106 ) {
if ( ( V_103 - 1 ) % 5 != 0 ) {
fprintf ( V_104 , L_65 ) ;
V_103 = 4 ;
}
fprintf ( V_104 , L_66 ) ;
fprintf ( V_104 , L_67 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_104 , L_68 , V_99 -> V_33 ,
V_99 -> V_33 ) ;
} else if ( V_99 -> V_35 & V_107 ) {
if ( ( V_103 - 1 ) % 5 != 0 ) {
fprintf ( V_104 , L_65 ) ;
V_103 = 4 ;
}
fprintf ( V_104 , L_69 ) ;
fprintf ( V_104 , L_67 , V_25 -> system ,
V_25 -> V_33 ) ;
fprintf ( V_104 , L_68 , V_99 -> V_33 ,
V_99 -> V_33 ) ;
} else
fprintf ( V_104 , L_53 , V_99 -> V_33 ) ;
}
fprintf ( V_104 , L_70 ) ;
fprintf ( V_104 , L_71 ) ;
}
fprintf ( V_104 , L_72
L_73
L_74 ) ;
fprintf ( V_104 , L_55
L_75
L_76 ) ;
fprintf ( V_104 , L_77
L_78
L_79
L_80 ) ;
fprintf ( V_104 ,
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
fclose ( V_104 ) ;
fprintf ( V_105 , L_98 , V_100 ) ;
return 0 ;
}
