static void FPRINTF ( T_1 * V_1 , const char * V_2 , ... )
{
T_2 args ;
#ifdef F_1
va_start ( args , V_2 ) ;
vfprintf ( V_3 , V_2 , args ) ;
va_end ( args ) ;
#endif
if ( V_1 ) {
va_start ( args , V_2 ) ;
vfprintf ( V_1 , V_2 , args ) ;
va_end ( args ) ;
}
}
static void
F_2 ( char * V_4 , char * V_5 )
{
T_3 * V_6 ;
V_6 = malloc ( sizeof( T_3 ) ) ;
V_6 -> V_7 = V_8 ;
V_8 = V_6 ;
V_6 -> V_4 = F_3 ( V_4 ) ;
V_6 -> V_5 = F_3 ( V_5 ) ;
}
static char *
F_4 ( char * V_4 )
{
T_3 * V_6 ;
for( V_6 = V_8 ; V_6 ; V_6 = V_6 -> V_7 ) {
if( ! strcmp ( V_4 , V_6 -> V_4 ) ) {
return V_6 -> V_5 ;
}
}
return L_1 ;
}
static T_4 *
F_5 ( T_4 * V_9 , int V_10 )
{
T_4 * V_11 ;
V_11 = V_9 ;
while( V_11 ) {
if( V_10 ) V_10 -- ;
V_11 = V_11 -> V_7 ;
}
if( ! V_11 ) V_11 = V_9 ;
while( V_10 -- ) {
V_11 = malloc ( sizeof( T_4 ) ) ;
V_11 -> V_7 = V_9 ;
V_11 -> type = V_12 ;
V_9 = V_11 ;
}
V_9 = V_11 ;
return V_9 ;
}
static char *
F_6 ( char * V_13 )
{
if( ! strcmp ( V_13 , L_2 ) ) {
return L_3 ;
} else if( ! strcmp ( V_13 , L_4 ) ) {
return L_5 ;
} else if( ! strcmp ( V_13 , L_6 ) ) {
return L_7 ;
}
fprintf ( V_3 , L_8 , V_13 ) ;
exit ( 10 ) ;
}
static int
F_7 ( char * V_4 )
{
T_5 * V_14 ;
for( V_14 = V_15 ; V_14 ; V_14 = V_14 -> V_7 ) {
if( ! strcmp ( V_4 , V_14 -> V_4 ) ) {
return V_14 -> V_16 ;
}
}
fprintf ( V_3 , L_9 , V_4 ) ;
fprintf ( V_3 , L_10 ) ;
exit ( 10 ) ;
}
static void
F_8 ( char * V_17 , char * V_18 )
{
T_6 * V_19 ;
V_19 = malloc ( sizeof( T_6 ) ) ;
V_19 -> V_7 = V_20 ;
V_20 = V_19 ;
V_19 -> V_21 = 0 ;
V_19 -> V_17 = F_3 ( V_17 ) ;
V_19 -> V_18 = F_3 ( V_18 ) ;
}
static void
F_9 ( void )
{
T_6 * V_22 ;
for( V_22 = V_20 ; V_22 ; V_22 = V_22 -> V_7 ) {
if( ! V_22 -> V_21 ) {
fprintf ( V_3 , L_11 , V_22 -> V_17 ) ;
exit ( 10 ) ;
}
}
}
static T_7 *
F_10 ( char * V_4 )
{
T_7 * V_23 ;
for( V_23 = V_24 ; V_23 ; V_23 = V_23 -> V_7 ) {
if( ! strcmp ( V_23 -> V_4 , V_4 ) ) {
break;
}
}
if ( ! V_23 ) {
fprintf ( V_3 , L_12 , V_4 ) ;
Exit ( 10 ) ;
}
return V_23 ;
}
static char *
F_11 ( char * V_25 , char * V_26 , char * V_27 , char * V_28 , char * V_29 , char * V_30 , char * V_31 , char * V_32 )
{
T_7 * V_23 ;
T_6 * V_22 ;
for( V_22 = V_20 ; V_22 ; V_22 = V_22 -> V_7 ) {
if( ! strcmp ( V_25 , V_22 -> V_17 ) ) {
V_23 = F_10 ( V_22 -> V_18 ) ;
if( strcmp ( V_28 , V_23 -> V_28 ) ) {
fprintf ( V_3 , L_13 , V_25 , V_23 -> V_4 , V_28 , V_23 -> V_28 ) ;
Exit ( 10 ) ;
}
V_22 -> V_21 ++ ;
return V_22 -> V_18 ;
}
}
V_23 = malloc ( sizeof( T_7 ) ) ;
V_23 -> V_7 = V_24 ;
V_24 = V_23 ;
V_23 -> V_4 = F_3 ( V_25 ) ;
V_23 -> V_28 = F_3 ( V_28 ) ;
FPRINTF ( V_33 , L_14 , V_25 ) ;
FPRINTF ( V_34 , L_15 , V_25 ) ;
FPRINTF ( V_34 , L_16 , V_26 , V_27 , V_28 , V_29 ) ;
FPRINTF ( V_34 , L_17 , V_30 , V_31 ) ;
if ( strlen ( V_32 ) > 0 )
FPRINTF ( V_34 , L_18 , V_32 ) ;
else
FPRINTF ( V_34 , L_19 ) ;
FPRINTF ( V_34 , L_20 ) ;
return V_25 ;
}
static int
F_12 ( char * V_4 )
{
T_8 * V_35 ;
for( V_35 = V_36 ; V_35 ; V_35 = V_35 -> V_7 ) {
if( ! strcmp ( V_4 , V_35 -> V_4 ) ) {
FPRINTF ( NULL , L_21 , V_4 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_13 ( char * V_17 , char * V_18 )
{
T_9 * V_37 ;
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! strcmp ( V_37 -> V_39 , V_17 ) ) {
V_37 -> V_39 = F_3 ( V_18 ) ;
}
}
}
static void
F_14 ( char * V_4 )
{
T_9 * V_37 , * V_40 ;
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! strcmp ( V_37 -> V_39 , V_4 ) ) {
if( ! strcmp ( V_37 -> V_7 -> V_39 , L_22 ) ) {
V_40 = V_37 ;
while( 1 ) {
if( ! strcmp ( V_40 -> V_39 , L_23 ) ) {
V_37 -> V_7 = V_40 -> V_7 ;
break;
}
V_40 = V_40 -> V_7 ;
}
}
}
}
}
static T_9 *
F_15 ( T_9 * V_37 , T_10 * * V_41 ) {
T_10 * V_42 ;
T_11 * V_43 ;
if( strcmp ( V_37 -> V_39 , L_24 ) ) {
fprintf ( V_3 , L_25 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_42 = malloc ( sizeof( T_10 ) ) ;
* V_41 = V_42 ;
V_42 -> V_44 = 0 ;
V_42 -> V_45 = NULL ;
V_42 -> V_46 = NULL ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_26 )
|| ! strcmp ( V_37 -> V_39 , L_27 ) ) {
fprintf ( V_3 , L_28 ) ;
Exit ( 10 ) ;
}
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
fprintf ( V_3 , L_29 ) ;
Exit ( 10 ) ;
}
if( ! strcmp ( V_37 -> V_39 , L_30 ) ) {
V_37 = V_37 -> V_7 ;
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
return V_37 ;
}
if( ! strcmp ( V_37 -> V_39 , L_31 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_32 ) ) {
V_42 -> V_44 |= V_47 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_22 ) ) {
fprintf ( V_3 , L_33 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_42 -> V_45 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_23 ) ) {
fprintf ( V_3 , L_34 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_35 ) ) {
V_42 -> V_44 |= V_47 ;
V_42 -> V_44 |= V_48 ;
V_42 -> V_45 = L_35 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_36 ) ) {
V_42 -> V_44 |= V_49 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_37 ) ) {
V_42 -> V_44 |= V_50 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_38 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_39 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_40 ) ) {
fprintf ( V_3 , L_41 ) ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_42 ) ) {
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_43 ) ) {
int V_51 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_22 ) ) {
fprintf ( V_3 , L_44 ) ;
Exit ( 10 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_22 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 -- ;
if( V_51 ) {
continue;
}
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_45 ) ) {
int V_51 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_22 ) ) {
fprintf ( V_3 , L_46 ) ;
Exit ( 10 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_22 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 -- ;
if( V_51 ) {
continue;
}
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_47 ) ) {
int V_51 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_22 ) ) {
fprintf ( V_3 , L_48 ) ;
Exit ( 10 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_22 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 -- ;
if( V_51 ) {
continue;
}
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_49 ) ) {
V_42 -> V_44 |= V_52 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_22 ) ) {
fprintf ( V_3 , L_50 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_43 = F_16 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
fprintf ( V_3 , L_51 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_42 -> V_53 = V_43 -> V_54 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_23 ) ) {
fprintf ( V_3 , L_52 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_53 ) ) {
V_42 -> V_44 |= V_55 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_54 ) ) {
V_42 -> V_44 |= V_56 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_55 ) ) {
V_42 -> V_44 |= V_57 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_56 ) ) {
V_42 -> V_44 |= V_58 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_4 )
|| ! strcmp ( V_37 -> V_39 , L_2 )
|| ! strcmp ( V_37 -> V_39 , L_6 ) ) {
T_4 * V_59 ;
V_42 -> V_44 |= V_60 ;
V_59 = malloc ( sizeof( T_4 ) ) ;
V_59 -> V_7 = NULL ;
V_59 -> type = V_37 -> V_39 ;
V_59 -> V_7 = V_42 -> V_46 ;
V_42 -> V_46 = V_59 ;
V_37 = V_37 -> V_7 ;
continue;
}
fprintf ( V_3 , L_57 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
return NULL ;
}
static T_11 *
F_17 ( char * V_4 , char * V_61 , char * V_28 , char * V_29 , char * V_31 , char * V_30 , int V_54 ) {
T_11 * V_62 ;
FPRINTF ( NULL , L_58 , V_4 , V_61 , V_28 , V_29 , V_31 , V_30 , V_54 ) ;
V_62 = malloc ( sizeof( T_11 ) ) ;
V_62 -> V_7 = V_63 ;
V_62 -> V_4 = F_3 ( V_4 ) ;
V_62 -> V_64 = F_3 ( V_61 ) ;
V_62 -> V_28 = F_3 ( V_28 ) ;
V_62 -> V_29 = F_3 ( V_29 ) ;
V_62 -> V_31 = F_3 ( V_31 ) ;
V_62 -> V_65 = F_3 ( V_30 ) ;
V_62 -> V_54 = V_54 ;
V_63 = V_62 ;
return V_62 ;
}
static void F_18 ( int V_66 )
{
T_9 * V_37 ;
fprintf ( V_3 , L_59 ) ;
for( V_37 = V_38 ; V_37 && V_66 ; V_66 -- , V_37 = V_37 -> V_7 ) {
fprintf ( V_3 , L_60 , V_37 -> V_39 ) ;
}
if( ! V_66 ) {
fprintf ( V_3 , L_61 ) ;
}
}
static void F_19 ( void )
{
char V_27 [ 256 ] ;
T_9 * V_37 ;
int V_51 = 0 ;
int V_67 , V_68 ;
V_37 = V_38 ;
if( ! V_37 ) {
fprintf ( V_3 , L_62 ) ;
Exit ( 10 ) ;
}
if( strcmp ( V_37 -> V_39 , L_24 ) ) {
fprintf ( V_3 , L_63 ) ;
Exit ( 10 ) ;
}
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_51 ++ ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_30 ) ) {
V_51 -- ;
if( ! V_51 ) {
V_38 = V_37 -> V_7 ;
break;
}
}
if( V_51 == 1 ) {
if( ! strcmp ( V_37 -> V_39 , L_64 ) ) {
V_69 = V_37 -> V_7 -> V_7 -> V_39 ;
FPRINTF ( NULL , L_65 , V_69 ) ;
}
if( ! strcmp ( V_37 -> V_39 , L_66 ) ) {
V_70 = V_37 -> V_7 -> V_7 -> V_39 ;
FPRINTF ( NULL , L_67 , V_70 ) ;
}
if( ! strcmp ( V_37 -> V_39 , L_68 ) ) {
if( ! strcmp ( V_37 -> V_7 -> V_7 -> V_39 , L_2 ) ) {
V_12 = L_2 ;
} else if( ! strcmp ( V_37 -> V_7 -> V_7 -> V_39 , L_6 ) ) {
V_12 = L_6 ;
} else {
fprintf ( V_3 , L_69 ) ;
Exit ( 10 ) ;
}
FPRINTF ( NULL , L_70 , V_12 ) ;
}
}
}
if( ! V_38 ) {
fprintf ( V_3 , L_71 ) ;
Exit ( 10 ) ;
}
if( strcmp ( V_38 -> V_39 , L_72 ) ) {
fprintf ( V_3 , L_73 ) ;
Exit ( 10 ) ;
}
V_38 = V_38 -> V_7 ;
V_71 = V_38 -> V_39 ;
V_38 = V_38 -> V_7 ;
FPRINTF ( NULL , L_74 , V_71 ) ;
sprintf ( V_72 , L_75 , V_71 ) ;
sprintf ( V_27 , L_76 , V_71 ) ;
F_11 ( V_72 , L_77 , V_27 , L_78 , L_79 , L_80 , L_1 , L_81 ) ;
sprintf ( V_72 , L_82 , V_71 ) ;
sprintf ( V_27 , L_83 , V_71 ) ;
F_11 ( V_72 , L_84 , V_27 , L_85 , L_86 , L_87 , L_1 , L_81 ) ;
FPRINTF ( V_73 , L_88 , V_71 ) ;
FPRINTF ( V_74 , L_89 , V_71 ) ;
if( strcmp ( V_38 -> V_39 , L_26 ) ) {
fprintf ( V_3 , L_90 ) ;
Exit ( 10 ) ;
}
V_38 = V_38 -> V_7 ;
if( ! V_69 ) {
fprintf ( V_3 , L_91 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_92 , V_71 ) ;
FPRINTF ( V_75 , L_93 , V_69 [ 1 ] , V_69 [ 2 ] , V_69 [ 3 ] , V_69 [ 4 ] , V_69 [ 5 ] , V_69 [ 6 ] , V_69 [ 7 ] , V_69 [ 8 ] , V_69 [ 10 ] , V_69 [ 11 ] , V_69 [ 12 ] , V_69 [ 13 ] , V_69 [ 15 ] , V_69 [ 16 ] , V_69 [ 17 ] , V_69 [ 18 ] ) ;
FPRINTF ( V_75 , L_94 , V_69 [ 20 ] , V_69 [ 21 ] , V_69 [ 22 ] , V_69 [ 23 ] , V_69 [ 25 ] , V_69 [ 26 ] , V_69 [ 27 ] , V_69 [ 28 ] , V_69 [ 29 ] , V_69 [ 30 ] , V_69 [ 31 ] , V_69 [ 32 ] , V_69 [ 33 ] , V_69 [ 34 ] , V_69 [ 35 ] , V_69 [ 36 ] ) ;
FPRINTF ( V_75 , L_95 ) ;
FPRINTF ( V_75 , L_20 ) ;
sscanf ( V_70 , L_96 , & V_67 , & V_68 ) ;
FPRINTF ( V_75 , L_97 , V_71 , V_67 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_76 , L_98 , V_71 , V_71 ) ;
FPRINTF ( V_76 , L_99 , V_71 , V_71 ) ;
FPRINTF ( V_76 , L_100 , V_71 ) ;
}
static void F_20 ( char * V_77 )
{
T_9 * V_78 ;
V_78 = malloc ( sizeof( T_9 ) ) ;
V_78 -> V_7 = NULL ;
V_78 -> V_39 = V_77 ;
if( ! V_38 ) {
V_38 = V_78 ;
} else {
V_79 -> V_7 = V_78 ;
}
V_79 = V_78 ;
}
static void F_21 ( T_1 * V_1 )
{
int V_80 ;
int V_81 = 0 ;
int V_82 = 0 ;
int V_83 = 0 ;
char V_84 [ 1024 ] ;
int V_85 = 0 ;
int V_86 = 0 ;
char V_77 [ 1024 ] ;
int V_87 = 0 ;
while( ! feof ( V_1 ) ) {
V_80 = fgetc ( V_1 ) ;
if( V_81 ) {
if( ( V_80 == '\n' ) || ( V_80 == '\r' ) ) {
V_81 = 0 ;
V_88 = 0 ;
}
continue;
}
if( ( V_80 == '#' ) && ( V_88 == 0 ) ) {
V_81 = 1 ;
continue;
}
if( V_82 == 0 ) {
if( V_80 == '/' ) {
int V_89 ;
V_89 = fgetc ( V_1 ) ;
if( V_89 == '*' ) {
V_82 = 1 ;
continue;
}
ungetc ( V_89 , V_1 ) ;
}
} else {
if( V_80 == '*' ) {
int V_89 ;
V_89 = fgetc ( V_1 ) ;
if( V_89 == '/' ) {
V_82 = 0 ;
continue;
}
ungetc ( V_89 , V_1 ) ;
}
continue;
}
if( V_83 ) {
if( V_80 == '"' ) {
V_83 = 0 ;
V_84 [ V_85 ++ ] = '"' ;
V_84 [ V_85 ] = 0 ;
F_20 ( F_3 ( V_84 ) ) ;
continue;
} else {
V_84 [ V_85 ++ ] = ( char ) V_80 ;
continue;
}
} else {
if( V_80 == '"' ) {
V_83 = 1 ;
V_84 [ 0 ] = '"' ;
V_85 = 1 ;
continue;
}
}
switch( V_80 ) {
case '\n' :
case '\r' :
if( V_86 ) {
V_86 = 0 ;
V_77 [ V_87 ] = 0 ;
F_20 ( F_3 ( V_77 ) ) ;
}
line [ V_88 ] = 0 ;
V_88 = 0 ;
V_90 ++ ;
break;
case '\t' :
case ' ' :
if( V_86 ) {
V_86 = 0 ;
V_77 [ V_87 ] = 0 ;
F_20 ( F_3 ( V_77 ) ) ;
}
break;
case '[' :
case ']' :
case '(' :
case ')' :
case ',' :
case ';' :
case '*' :
case '=' :
if( V_86 ) {
V_86 = 0 ;
V_77 [ V_87 ] = 0 ;
F_20 ( F_3 ( V_77 ) ) ;
}
V_77 [ 0 ] = ( char ) V_80 ;
V_77 [ 1 ] = 0 ;
F_20 ( F_3 ( V_77 ) ) ;
break;
default:
if( ! V_86 ) {
V_87 = 0 ;
}
V_86 = 1 ;
V_77 [ V_87 ++ ] = ( char ) V_80 ;
line [ V_88 ++ ] = ( char ) V_80 ;
break;
}
}
}
static T_11 *
F_16 ( char * V_4 )
{
T_11 * V_91 ;
for( V_91 = V_63 ; V_91 ; V_91 = V_91 -> V_7 ) {
if( ! strcmp ( V_91 -> V_4 , V_4 ) ) {
break;
}
}
if( ! V_91 ) {
char V_61 [ 256 ] ;
if( ! strcmp ( V_4 , L_101 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_107 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_101 , V_61 , L_78 , L_79 , L_1 , L_80 , 2 ) ;
} else if( ! strcmp ( V_4 , L_110 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_107 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_110 , V_61 , L_111 , L_79 , L_1 , L_80 , 2 ) ;
} else if( ! strcmp ( V_4 , L_112 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_113 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_112 , V_61 , L_85 , L_79 , L_1 , L_80 , 4 ) ;
} else if( ( ! strcmp ( V_4 , L_114 ) )
|| ( ! strcmp ( V_4 , L_115 ) ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_113 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
if ( ! strcmp ( V_4 , L_114 ) )
V_91 = F_17 ( L_114 , V_61 , L_116 , L_79 , L_1 , L_80 , 4 ) ;
else
V_91 = F_17 ( L_115 , V_61 , L_116 , L_79 , L_1 , L_80 , 4 ) ;
} else if( ( ! strcmp ( V_4 , L_117 ) ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_118 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_117 , V_61 , L_119 , L_79 , L_1 , L_80 , 1 ) ;
} else if( ( ! strcmp ( V_4 , L_120 ) )
|| ( ! strcmp ( V_4 , L_121 ) ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_118 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
if ( ! strcmp ( V_4 , L_120 ) )
V_91 = F_17 ( L_120 , V_61 , L_122 , L_79 , L_1 , L_80 , 1 ) ;
else
V_91 = F_17 ( L_121 , V_61 , L_122 , L_79 , L_1 , L_80 , 1 ) ;
} else if( ! strcmp ( V_4 , L_123 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_118 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_123 , V_61 , L_122 , L_79 , L_1 , L_80 , 1 ) ;
} else if( ! strcmp ( V_4 , L_124 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_125 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_124 , V_61 , L_126 , L_127 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_128 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_129 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_128 , V_61 , L_126 , L_127 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_130 )
|| ! strcmp ( V_4 , L_131 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_132 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( V_4 , V_61 , L_133 , L_127 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_134 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_135 ) ;
FPRINTF ( V_75 , L_136 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_137 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_138 ) ;
FPRINTF ( V_75 , L_139 ) ;
FPRINTF ( V_75 , L_140 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_134 , V_61 , L_141 , L_127 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_142 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_143 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_142 , V_61 , L_144 , L_145 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_146 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_147 ) ;
FPRINTF ( V_75 , L_143 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_146 , V_61 , L_144 , L_145 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_148 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_147 ) ;
FPRINTF ( V_75 , L_143 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_148 , V_61 , L_144 , L_145 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_149 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_150 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_149 , V_61 , L_151 , L_79 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_152 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_150 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_152 , V_61 , L_153 , L_79 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_154 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_155 ) ;
FPRINTF ( V_75 , L_147 ) ;
FPRINTF ( V_75 , L_156 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_154 , V_61 , L_151 , L_79 , L_1 , L_80 , 8 ) ;
} else if( ! strcmp ( V_4 , L_157 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_155 ) ;
FPRINTF ( V_75 , L_158 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_157 , V_61 , L_144 , L_145 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_159 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_137 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_160 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_161 ) ;
FPRINTF ( V_75 , L_162 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_159 , V_61 , L_126 , L_127 , L_1 , L_80 , 4 ) ;
} else if( ! strcmp ( V_4 , L_163 ) ) {
sprintf ( V_61 , L_102 , V_71 , V_4 ) ;
FPRINTF ( NULL , L_103 , V_4 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_155 ) ;
FPRINTF ( V_75 , L_113 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_91 = F_17 ( L_163 , V_61 , L_85 , L_79 , L_1 , L_87 , 4 ) ;
}
}
return V_91 ;
}
static void F_22 ( void )
{
T_9 * V_37 ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_164 ) ) {
fprintf ( V_3 , L_165 ) ;
Exit ( 10 ) ;
}
while( strcmp ( V_37 -> V_39 , L_166 ) ) {
V_37 = V_37 -> V_7 ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
static void F_23 ( void )
{
T_9 * V_37 ;
char * V_4 , * V_5 ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_167 ) ) {
fprintf ( V_3 , L_168 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( F_16 ( V_37 -> V_39 ) ) {
fprintf ( V_3 , L_169 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_4 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_170 ) ) {
fprintf ( V_3 , L_171 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_5 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_172 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
FPRINTF ( NULL , L_173 , V_4 ) ;
FPRINTF ( V_92 , L_174 , V_4 , V_5 ) ;
FPRINTF ( NULL , L_175 , V_4 ) ;
V_38 = V_37 ;
}
static void F_24 ( int V_93 )
{
T_9 * V_37 , * V_40 ;
char * V_94 ;
char V_61 [ 256 ] ;
char V_95 [ 256 ] , * V_96 ;
int V_51 , V_10 ;
static int V_54 ;
T_11 * V_43 ;
char V_97 [ 256 ] ;
T_10 * V_98 = NULL ;
T_4 * V_11 ;
char * V_13 ;
char * V_99 ;
int V_100 ;
int V_101 ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_176 ) ) {
fprintf ( V_3 , L_177 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = F_15 ( V_37 , & V_98 ) ;
}
if( V_98 ) {
if( V_98 -> V_44 ) {
fprintf ( V_3 , L_178 , V_98 -> V_44 ) ;
Exit ( 10 ) ;
}
}
if( strcmp ( V_37 -> V_39 , L_179 ) ) {
fprintf ( V_3 , L_180 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_26 ) ) {
fprintf ( V_3 , L_181 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_40 = V_37 , V_51 = 0 ; V_40 ; V_40 = V_40 -> V_7 ) {
if( ! strcmp ( V_40 -> V_39 , L_26 ) ) {
V_51 ++ ;
continue;
}
if( ! strcmp ( V_40 -> V_39 , L_27 ) ) {
if( ! V_51 ) {
break;
}
V_51 -- ;
continue;
}
}
if( ! V_40 || ! V_40 -> V_7 ) {
fprintf ( V_3 , L_182 ) ;
Exit ( 10 ) ;
}
V_94 = V_40 -> V_7 -> V_39 ;
sprintf ( V_61 , L_102 , V_71 , V_94 ) ;
FPRINTF ( NULL , L_183 , V_94 , V_93 ) ;
if( ! F_12 ( V_61 ) ) {
FPRINTF ( NULL , L_184 ) ;
V_37 = V_40 ;
goto V_102;
}
if( V_93 == 0 ) {
V_54 = 1 ;
}
if( V_93 == 1 ) {
FPRINTF ( V_73 , L_185 , V_71 , V_94 ) ;
FPRINTF ( V_74 , L_186 , V_71 , V_94 ) ;
FPRINTF ( V_92 , L_187 , V_61 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_188 ) ;
FPRINTF ( V_75 , L_189 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_190 ) ;
FPRINTF ( V_75 , L_191 ) ;
FPRINTF ( V_75 , L_192 ) ;
FPRINTF ( V_75 , L_20 ) ;
switch( V_54 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_75 , L_193 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
case 4 :
FPRINTF ( V_75 , L_194 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
case 8 :
FPRINTF ( V_75 , L_147 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
default:
fprintf ( V_3 , L_195 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_196 ) ;
FPRINTF ( V_75 , L_197 ) ;
FPRINTF ( V_75 , L_198 ) ;
FPRINTF ( V_75 , L_199 , V_71 , V_94 ) ;
FPRINTF ( V_75 , L_200 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_26 ) ) {
V_51 ++ ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_27 ) ) {
if( ! V_51 ) {
break;
}
V_51 -- ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = F_15 ( V_37 , & V_98 ) ;
continue;
}
if( V_98 ) {
if( V_98 -> V_44 & ( ~ ( V_55 | V_56 | V_60 ) ) ) {
fprintf ( V_3 , L_178 , V_98 -> V_44 ) ;
Exit ( 10 ) ;
}
}
V_43 = F_16 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
fprintf ( V_3 , L_201 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_10 = 0 ; ! strcmp ( V_37 -> V_39 , L_202 ) ; V_37 = V_37 -> V_7 ) {
V_10 ++ ;
if( V_54 < 4 ) {
V_54 = 4 ;
}
}
V_11 = F_5 ( V_98 ? V_98 -> V_46 : NULL , V_10 ) ;
if( V_54 < V_43 -> V_54 ) {
V_54 = V_43 -> V_54 ;
}
V_99 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
V_100 = 0 ;
V_101 = 0 ;
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
char V_103 [ 256 ] ;
V_37 = V_37 -> V_7 ;
V_100 = atoi ( V_37 -> V_39 ) ;
sprintf ( V_103 , L_203 , V_100 ) ;
if( ! strcmp ( L_30 , V_37 -> V_39 ) ) {
V_100 = 0 ;
} else if( ! strcmp ( L_202 , V_37 -> V_39 ) ) {
V_11 = F_5 ( V_11 , V_10 + 1 ) ;
V_100 = 0 ;
V_101 = 1 ;
V_37 = V_37 -> V_7 ;
} else if( strcmp ( V_103 , V_37 -> V_39 ) ) {
fprintf ( V_3 , L_204 , V_94 , V_103 , V_37 -> V_39 ) ;
V_37 = V_37 -> V_7 ;
Exit ( 10 ) ;
} else {
V_37 = V_37 -> V_7 ;
}
if( strcmp ( V_37 -> V_39 , L_30 ) ) {
fprintf ( V_3 , L_205 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
}
sprintf ( V_97 , L_206 , V_71 , V_94 , V_99 ) ;
if( V_93 == 0 ) {
char V_27 [ 256 ] ;
char * V_104 ;
sprintf ( V_95 , L_207 , V_71 , V_94 , V_99 ) ;
V_96 = F_3 ( V_95 ) ;
if( F_12 ( V_95 ) ) {
sprintf ( V_27 , L_208 , V_71 , V_94 , V_99 ) ;
V_104 = F_11 ( V_97 , V_99 , V_27 , V_43 -> V_28 , V_43 -> V_29 , V_43 -> V_65 , V_43 -> V_31 , L_81 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_96 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_210 , F_4 ( V_96 ) ) ;
FPRINTF ( V_75 , L_211 , V_43 -> V_64 , V_104 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
if( V_101 ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
sprintf ( V_95 , L_214 , V_13 , V_96 ) ;
if( F_12 ( V_95 ) ) {
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_215 , V_96 , F_6 ( V_13 ) , V_99 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
V_96 = F_3 ( V_95 ) ;
} else if( V_100 ) {
sprintf ( V_95 , L_216 , V_96 ) ;
if( F_12 ( V_95 ) ) {
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_217 , V_100 ) ;
FPRINTF ( V_75 , L_218 ) ;
FPRINTF ( V_75 , L_219 , V_96 ) ;
FPRINTF ( V_75 , L_220 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
V_96 = F_3 ( V_95 ) ;
}
if( V_98 ) {
switch( V_98 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 :
sprintf ( V_95 , L_221 , V_96 ) ;
if( F_12 ( V_95 ) ) {
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_222 , V_96 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
V_96 = F_3 ( V_95 ) ;
break;
case V_56 :
sprintf ( V_95 , L_223 , V_96 ) ;
if( F_12 ( V_95 ) ) {
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_224 , V_96 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
V_96 = F_3 ( V_95 ) ;
break;
case V_55 | V_56 :
sprintf ( V_95 , L_225 , V_96 ) ;
if( F_12 ( V_95 ) ) {
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_226 , V_96 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
V_96 = F_3 ( V_95 ) ;
break;
default:
fprintf ( V_3 , L_227 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
sprintf ( V_95 , L_214 , V_13 , V_96 ) ;
if( F_12 ( V_95 ) ) {
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_215 , V_96 , F_6 ( V_13 ) , V_99 ) ;
FPRINTF ( V_75 , L_212 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
} else {
FPRINTF ( NULL , L_213 , V_95 ) ;
}
V_96 = F_3 ( V_95 ) ;
}
}
if( V_93 == 1 ) {
sprintf ( V_95 , L_207 , V_71 , V_94 , V_99 ) ;
V_96 = F_3 ( V_95 ) ;
if( V_101 ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
sprintf ( V_95 , L_214 , V_13 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
} else if( V_100 ) {
sprintf ( V_95 , L_216 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
}
if( V_98 ) {
switch( V_98 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 :
sprintf ( V_95 , L_221 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
break;
case V_56 :
sprintf ( V_95 , L_223 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
break;
case V_55 | V_56 :
sprintf ( V_95 , L_225 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
break;
default:
fprintf ( V_3 , L_227 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
sprintf ( V_95 , L_214 , V_13 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
}
FPRINTF ( V_75 , L_228 , V_96 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
if( strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_229 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_98 = NULL ;
}
if( V_93 == 1 ) {
FPRINTF ( V_75 , L_230 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
F_17 ( V_94 , V_61 , L_231 , L_127 , L_1 , L_80 , V_54 ) ;
}
V_102:
FPRINTF ( NULL , L_232 , V_94 , V_93 ) ;
if( V_93 == 1 ) {
if( ! V_37 || strcmp ( V_37 -> V_39 , L_27 ) ) {
fprintf ( V_3 , L_233 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( ! V_37 || strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_234 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static void F_25 ( int V_93 )
{
T_9 * V_37 , * V_40 ;
char * V_105 ;
char V_61 [ 256 ] , V_106 [ 256 ] ;
int V_54 ;
unsigned int V_107 ;
char * V_4 , * V_5 ;
T_10 * V_98 = NULL ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_176 ) ) {
fprintf ( V_3 , L_235 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_54 = 4 ;
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = F_15 ( V_37 , & V_98 ) ;
}
if( V_98 ) {
if( V_98 -> V_44 & ( ~ ( V_58 | V_57 ) ) ) {
fprintf ( V_3 , L_236 , V_98 -> V_44 ) ;
Exit ( 10 ) ;
}
if( V_98 -> V_44 & V_58 ) {
V_54 = 4 ;
}
if( V_98 -> V_44 & V_57 ) {
V_54 = 1 ;
}
}
if( strcmp ( V_37 -> V_39 , L_237 ) ) {
fprintf ( V_3 , L_238 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_26 ) ) {
fprintf ( V_3 , L_239 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_40 = V_37 ; V_40 ; V_40 = V_40 -> V_7 ) {
if( ! strcmp ( V_40 -> V_39 , L_26 ) ) {
fprintf ( V_3 , L_240 ) ;
Exit ( 10 ) ;
}
if( ! strcmp ( V_40 -> V_39 , L_27 ) ) {
break;
}
}
if ( ! V_40 || ! V_40 -> V_7 ) {
fprintf ( V_3 , L_241 ) ;
Exit ( 10 ) ;
}
V_105 = V_40 -> V_7 -> V_39 ;
sprintf ( V_61 , L_102 , V_71 , V_105 ) ;
FPRINTF ( NULL , L_242 , V_105 , V_93 ) ;
if( V_93 == 1 ) {
FPRINTF ( V_73 , L_185 , V_71 , V_105 ) ;
FPRINTF ( V_74 , L_186 , V_71 , V_105 ) ;
FPRINTF ( V_92 , L_187 , V_61 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_188 ) ;
FPRINTF ( V_75 , L_189 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_190 ) ;
FPRINTF ( V_75 , L_191 ) ;
switch( V_54 ) {
case 1 :
FPRINTF ( V_75 , L_243 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
case 4 :
FPRINTF ( V_75 , L_244 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_194 ) ;
break;
default:
fprintf ( V_3 , L_245 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_197 ) ;
FPRINTF ( V_75 , L_246 , V_54 ) ;
FPRINTF ( V_75 , L_199 , V_71 , V_105 ) ;
FPRINTF ( V_75 , L_200 ) ;
FPRINTF ( V_75 , L_20 ) ;
switch( V_54 ) {
case 1 :
FPRINTF ( V_75 , L_247 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
case 4 :
FPRINTF ( V_75 , L_248 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
default:
fprintf ( V_3 , L_245 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_20 ) ;
}
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_27 ) ) {
break;
}
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
fprintf ( V_3 , L_249 ) ;
Exit ( 10 ) ;
}
V_4 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
sprintf ( V_106 , L_206 , V_71 , V_105 , V_4 ) ;
if( strcmp ( V_37 -> V_39 , L_170 ) ) {
fprintf ( V_3 , L_250 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_5 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
V_107 = 0 ;
if( ! strncmp ( V_5 , L_251 , 2 ) ) {
sscanf ( V_5 , L_252 , & V_107 ) ;
} else {
fprintf ( V_3 , L_253 ) ;
Exit ( 10 ) ;
}
if( V_107 & ( V_107 - 1 ) ) {
fprintf ( V_3 , L_254 ) ;
Exit ( 10 ) ;
}
if( V_93 == 0 ) {
char V_27 [ 256 ] , V_108 [ 256 ] , V_109 [ 256 ] ;
sprintf ( V_27 , L_208 , V_71 , V_105 , V_4 ) ;
sprintf ( V_108 , L_203 , V_54 * 8 ) ;
sprintf ( V_109 , L_255 , V_4 ) ;
F_11 ( V_106 , V_4 , V_27 , L_256 , V_108 , V_109 , V_5 , L_81 ) ;
FPRINTF ( V_75 , L_257 , V_4 ) ;
FPRINTF ( V_75 , L_258 , V_4 ) ;
FPRINTF ( V_75 , L_259 , V_4 ) ;
FPRINTF ( V_75 , L_95 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
if( V_93 == 1 ) {
FPRINTF ( V_75 , L_260 , V_106 , V_54 , V_54 ) ;
FPRINTF ( V_75 , L_261 , V_5 ) ;
FPRINTF ( V_75 , L_262 , V_4 ) ;
FPRINTF ( V_75 , L_200 ) ;
FPRINTF ( V_75 , L_263 , V_5 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
if( ! strcmp ( V_37 -> V_39 , L_31 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
}
if( V_93 == 1 ) {
FPRINTF ( V_75 , L_264 ) ;
FPRINTF ( V_75 , L_265 ) ;
FPRINTF ( V_75 , L_200 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
switch( V_54 ) {
case 1 :
F_17 ( V_105 , V_61 , L_119 , L_86 , L_1 , L_80 , V_54 ) ;
break;
case 4 :
F_17 ( V_105 , V_61 , L_85 , L_86 , L_1 , L_80 , V_54 ) ;
break;
default:
fprintf ( V_3 , L_245 , V_54 ) ;
Exit ( 10 ) ;
}
}
FPRINTF ( NULL , L_266 , V_105 , V_93 ) ;
if( V_93 == 1 ) {
if( ! V_37 || strcmp ( V_37 -> V_39 , L_27 ) ) {
fprintf ( V_3 , L_267 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( ! V_37 || strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_268 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static char *
F_26 ( char * V_39 )
{
char * V_110 ;
if( V_39 [ 0 ] != '-' ) {
return V_39 ;
}
V_110 = F_3 ( V_39 ) ;
V_110 [ 0 ] = 'm' ;
return V_110 ;
}
static void F_27 ( int V_93 )
{
char * V_111 ;
T_9 * V_37 , * V_40 ;
char V_61 [ 256 ] ;
T_10 * V_98 = NULL ;
char V_95 [ 256 ] , * V_96 ;
int V_51 , V_10 ;
static int V_54 ;
T_11 * V_43 ;
char V_97 [ 256 ] ;
int V_112 , V_113 ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_176 ) ) {
fprintf ( V_3 , L_269 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = F_15 ( V_37 , & V_98 ) ;
}
if( V_98 ) {
if( V_98 -> V_44 & ( ~ ( V_52 ) ) ) {
fprintf ( V_3 , L_270 , V_98 -> V_44 ) ;
Exit ( 10 ) ;
}
}
if( strcmp ( V_37 -> V_39 , L_271 ) ) {
fprintf ( V_3 , L_272 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_26 ) ) {
fprintf ( V_3 , L_273 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_40 = V_37 , V_51 = 0 ; V_40 ; V_40 = V_40 -> V_7 ) {
if( ! strcmp ( V_40 -> V_39 , L_26 ) ) {
V_51 ++ ;
continue;
}
if( ! strcmp ( V_40 -> V_39 , L_27 ) ) {
if( ! V_51 ) {
break;
}
V_51 -- ;
continue;
}
}
if ( ! V_40 || ! V_40 -> V_7 ) {
fprintf ( V_3 , L_274 ) ;
Exit ( 10 ) ;
}
V_111 = V_40 -> V_7 -> V_39 ;
sprintf ( V_61 , L_275 , V_71 , V_111 ) ;
FPRINTF ( NULL , L_276 , V_111 , V_93 ) ;
if( V_98 && V_98 -> V_44 & V_52 ) {
V_112 = V_98 -> V_53 ;
} else {
V_112 = F_7 ( V_111 ) ;
}
if( V_93 == 0 ) {
V_54 = V_112 ;
}
if( V_93 == 1 ) {
FPRINTF ( V_73 , L_185 , V_71 , V_111 ) ;
FPRINTF ( V_74 , L_186 , V_71 , V_111 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_189 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_190 ) ;
FPRINTF ( V_75 , L_191 ) ;
FPRINTF ( V_75 , L_192 ) ;
switch( V_112 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_75 , L_277 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_193 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
case 4 :
FPRINTF ( V_75 , L_278 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_194 ) ;
FPRINTF ( V_75 , L_20 ) ;
break;
default:
fprintf ( V_3 , L_279 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_196 ) ;
FPRINTF ( V_75 , L_197 ) ;
FPRINTF ( V_75 , L_280 , V_111 ) ;
FPRINTF ( V_75 , L_199 , V_71 , V_111 ) ;
FPRINTF ( V_75 , L_200 ) ;
FPRINTF ( V_75 , L_20 ) ;
switch( V_112 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_75 , L_281 ) ;
FPRINTF ( V_75 , L_282 ) ;
break;
case 4 :
FPRINTF ( V_75 , L_283 ) ;
FPRINTF ( V_75 , L_282 ) ;
break;
default:
fprintf ( V_3 , L_284 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_285 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_26 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_27 ) ) {
if( ! V_51 ) {
break;
}
V_37 = V_37 -> V_7 ;
V_51 -- ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = F_15 ( V_37 , & V_98 ) ;
continue;
}
if( ! V_98 ) {
fprintf ( V_3 , L_286 ) ;
Exit ( 10 ) ;
}
if( V_98 -> V_44 & ( ~ ( V_47 | V_48 | V_60 ) ) ) {
fprintf ( V_3 , L_270 , V_98 -> V_44 ) ;
Exit ( 10 ) ;
}
if( ! ( V_98 -> V_44 & V_47 ) ) {
fprintf ( V_3 , L_287 ) ;
Exit ( 10 ) ;
}
#ifdef F_28
if( V_98 -> V_44 & V_48 ) {
if( strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_288 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
continue;
}
#endif
if( ! strcmp ( V_37 -> V_39 , L_166 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
V_43 = F_16 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
fprintf ( V_3 , L_289 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_10 = 0 ; ! strcmp ( V_37 -> V_39 , L_202 ) ; V_37 = V_37 -> V_7 ) {
V_10 ++ ;
}
if( V_10 ) {
V_113 = 4 ;
} else {
V_113 = V_43 -> V_54 ;
}
if( V_54 < V_113 ) {
V_54 = V_113 ;
}
sprintf ( V_97 , L_290 , V_71 , V_111 , F_26 ( V_98 -> V_45 ) , V_37 -> V_39 ) ;
if( V_93 == 0 ) {
char V_27 [ 256 ] ;
char * V_104 ;
sprintf ( V_95 , L_291 , V_71 , V_111 , F_26 ( V_98 -> V_45 ) , V_37 -> V_39 ) ;
V_96 = F_3 ( V_95 ) ;
sprintf ( V_27 , L_208 , V_71 , V_111 , V_37 -> V_39 ) ;
V_104 = F_11 ( V_97 , V_37 -> V_39 , V_27 , V_43 -> V_28 , V_43 -> V_29 , V_43 -> V_65 , V_43 -> V_31 , L_81 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_96 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_292 , F_4 ( V_96 ) ) ;
FPRINTF ( V_75 , L_293 , V_43 -> V_64 , V_104 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
while( V_10 -- ) {
sprintf ( V_95 , L_214 , V_96 , L_2 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_294 , V_96 , V_37 -> V_39 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_96 = F_3 ( V_95 ) ;
}
}
if( V_93 == 1 ) {
sprintf ( V_95 , L_291 , V_71 , V_111 , F_26 ( V_98 -> V_45 ) , V_37 -> V_39 ) ;
V_96 = F_3 ( V_95 ) ;
while( V_10 -- ) {
sprintf ( V_95 , L_214 , V_96 , L_2 ) ;
V_96 = F_3 ( V_95 ) ;
}
if( V_98 -> V_44 & V_48 ) {
FPRINTF ( V_75 , L_295 ) ;
} else {
FPRINTF ( V_75 , L_296 , V_98 -> V_45 ) ;
}
switch( V_113 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_75 , L_297 ) ;
break;
case 4 :
FPRINTF ( V_75 , L_298 ) ;
break;
case 8 :
FPRINTF ( V_75 , L_299 ) ;
break;
default:
fprintf ( V_3 , L_300 , V_113 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_301 , V_96 ) ;
FPRINTF ( V_75 , L_302 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_303 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
}
if( V_93 == 1 ) {
FPRINTF ( V_75 , L_200 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_230 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_304 ) ;
FPRINTF ( V_75 , L_109 ) ;
switch( V_112 ) {
case 2 :
F_17 ( V_111 , V_61 , L_78 , L_79 , L_1 , L_80 , V_54 ) ;
break;
case 4 :
F_17 ( V_111 , V_61 , L_85 , L_79 , L_1 , L_80 , V_54 ) ;
break;
default:
fprintf ( V_3 , L_305 , V_54 ) ;
Exit ( 10 ) ;
}
}
FPRINTF ( NULL , L_306 , V_111 , V_93 ) ;
if( V_93 == 1 ) {
if( ! V_37 || strcmp ( V_37 -> V_39 , L_27 ) ) {
fprintf ( V_3 , L_307 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( ! V_37 || strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_308 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static void F_29 ( int V_93 )
{
char * V_114 ;
static int V_115 = 0 ;
T_9 * V_37 ;
T_10 * V_98 = NULL ;
T_4 * V_11 ;
char * V_13 ;
char V_95 [ 256 ] , * V_96 ;
int V_51 , V_10 ;
T_11 * V_43 ;
char V_97 [ 256 ] ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_163 ) ) {
fprintf ( V_3 , L_309 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_114 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_22 ) ) {
fprintf ( V_3 , L_310 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
FPRINTF ( NULL , L_311 , V_114 , V_93 ) ;
if( V_93 == 0 ) {
FPRINTF ( V_116 , L_312 , V_115 , V_114 ) ;
FPRINTF ( V_116 , L_313 , V_71 , V_114 ) ;
FPRINTF ( V_116 , L_314 , V_71 , V_114 ) ;
V_115 ++ ;
}
if( ( V_93 == 1 ) || ( V_93 == 2 ) ) {
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_315 , V_71 , V_114 , ( V_93 == 1 ) ? L_316 : L_317 ) ;
FPRINTF ( V_75 , L_106 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! strcmp ( V_37 -> V_39 , L_22 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_23 ) ) {
if( ! V_51 ) {
break;
}
V_37 = V_37 -> V_7 ;
V_51 -- ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = F_15 ( V_37 , & V_98 ) ;
continue;
}
if( ! V_98 ) {
fprintf ( V_3 , L_318 ) ;
Exit ( 10 ) ;
}
if( V_98 -> V_44 & ( ~ ( V_49 | V_50 | V_60 | V_55 | V_56 ) ) ) {
fprintf ( V_3 , L_319 , V_98 -> V_44 ) ;
Exit ( 10 ) ;
}
if( ! ( V_98 -> V_44 & ( V_49 | V_50 ) ) ) {
fprintf ( V_3 , L_320 ) ;
Exit ( 10 ) ;
}
V_43 = F_16 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
fprintf ( V_3 , L_321 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_10 = 0 ; ! strcmp ( V_37 -> V_39 , L_202 ) ; V_37 = V_37 -> V_7 ) {
V_10 ++ ;
}
V_11 = F_5 ( V_98 -> V_46 , V_10 ) ;
sprintf ( V_97 , L_206 , V_71 , V_114 , V_37 -> V_39 ) ;
if( V_93 == 0 ) {
char V_27 [ 256 ] ;
char * V_104 ;
sprintf ( V_95 , L_207 , V_71 , V_114 , V_37 -> V_39 ) ;
V_96 = F_3 ( V_95 ) ;
sprintf ( V_27 , L_208 , V_71 , V_114 , V_37 -> V_39 ) ;
V_104 = F_11 ( V_97 , V_37 -> V_39 , V_27 , V_43 -> V_28 , V_43 -> V_29 , V_43 -> V_65 , V_43 -> V_31 , L_81 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_96 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_292 , F_4 ( V_96 ) ) ;
FPRINTF ( V_75 , L_293 , V_43 -> V_64 , V_104 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
if( V_98 ) {
switch( V_98 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 | V_56 :
sprintf ( V_95 , L_225 , V_96 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_322 , V_96 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_96 = F_3 ( V_95 ) ;
break;
case V_55 :
sprintf ( V_95 , L_221 , V_96 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_323 , V_96 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_96 = F_3 ( V_95 ) ;
break;
default:
fprintf ( V_3 , L_324 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
sprintf ( V_95 , L_214 , V_13 , V_96 ) ;
FPRINTF ( V_75 , L_104 ) ;
FPRINTF ( V_75 , L_209 , V_95 ) ;
FPRINTF ( V_75 , L_106 ) ;
FPRINTF ( V_75 , L_325 , V_96 , F_6 ( V_13 ) , V_37 -> V_39 ) ;
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
V_96 = F_3 ( V_95 ) ;
}
}
if( ( V_93 == 1 ) || ( V_93 == 2 ) ) {
sprintf ( V_95 , L_207 , V_71 , V_114 , V_37 -> V_39 ) ;
V_96 = F_3 ( V_95 ) ;
if( V_98 ) {
switch( V_98 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 | V_56 :
sprintf ( V_95 , L_225 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
break;
case V_55 :
sprintf ( V_95 , L_221 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
break;
default:
fprintf ( V_3 , L_324 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
sprintf ( V_95 , L_214 , V_13 , V_96 ) ;
V_96 = F_3 ( V_95 ) ;
}
if( ( V_93 == 1 ) && ( V_98 -> V_44 & V_49 ) ) {
FPRINTF ( V_75 , L_301 , V_96 ) ;
FPRINTF ( V_75 , L_326 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
if( ( V_93 == 2 ) && ( V_98 -> V_44 & V_50 ) ) {
FPRINTF ( V_75 , L_301 , V_96 ) ;
FPRINTF ( V_75 , L_326 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
}
V_37 = V_37 -> V_7 ;
if( ! strcmp ( V_37 -> V_39 , L_31 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
}
if( ( V_93 == 1 ) || ( V_93 == 2 ) ) {
if( V_93 == 2 ) {
FPRINTF ( V_75 , L_327 , V_72 ) ;
FPRINTF ( V_75 , L_20 ) ;
}
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_304 ) ;
FPRINTF ( V_75 , L_109 ) ;
}
FPRINTF ( NULL , L_328 , V_114 , V_93 ) ;
if( V_93 == 2 ) {
if( ! V_37 || strcmp ( V_37 -> V_39 , L_23 ) ) {
fprintf ( V_3 , L_329 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! V_37 || strcmp ( V_37 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_330 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static void F_30 ( void )
{
T_9 * V_37 ;
T_12 * V_117 , * V_118 , * V_119 ;
char * V_120 ;
long V_107 ;
int V_121 , V_122 ;
char V_61 [ 256 ] , V_30 [ 256 ] , V_123 [ 256 ] ;
V_122 = 16 ;
V_37 = V_38 ;
if( strcmp ( V_37 -> V_39 , L_176 ) ) {
fprintf ( V_3 , L_331 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! strcmp ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_332 ) ) {
fprintf ( V_3 , L_333 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_30 ) ) {
fprintf ( V_3 , L_334 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_122 = 32 ;
}
if( strcmp ( V_37 -> V_39 , L_335 ) ) {
fprintf ( V_3 , L_336 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( strcmp ( V_37 -> V_39 , L_26 ) ) {
fprintf ( V_3 , L_337 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_121 = 0 ;
V_117 = NULL ;
V_119 = NULL ;
while( 1 ) {
if( ! strcmp ( V_37 -> V_39 , L_27 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
V_118 = malloc ( sizeof( T_12 ) ) ;
V_118 -> V_7 = NULL ;
if( ! V_117 ) {
V_117 = V_118 ;
} else {
V_119 -> V_7 = V_118 ;
}
V_119 = V_118 ;
V_118 -> V_4 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( ! strcmp ( V_37 -> V_39 , L_170 ) ) {
V_37 = V_37 -> V_7 ;
V_107 = strtol ( V_37 -> V_39 , & V_120 , 0 ) ;
if ( V_120 == V_37 -> V_39 || * V_120 ) {
fprintf ( V_3 , L_338 ) ;
Exit ( 10 ) ;
}
V_118 -> V_107 = V_107 ;
V_37 = V_37 -> V_7 ;
} else {
V_118 -> V_107 = V_121 ;
}
V_121 = V_118 -> V_107 + 1 ;
if( ! strcmp ( V_37 -> V_39 , L_31 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! strcmp ( V_37 -> V_39 , L_27 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
fprintf ( V_3 , L_339 ) ;
Exit ( 10 ) ;
}
if( strcmp ( V_37 -> V_7 -> V_39 , L_166 ) ) {
fprintf ( V_3 , L_340 ) ;
Exit ( 10 ) ;
}
sprintf ( V_30 , L_341 , V_71 , V_37 -> V_39 ) ;
sprintf ( V_61 , L_102 , V_71 , V_37 -> V_39 ) ;
FPRINTF ( NULL , L_342 , V_37 -> V_39 ) ;
FPRINTF ( V_92 , L_20 ) ;
for( V_118 = V_117 ; V_118 ; V_118 = V_118 -> V_7 ) {
FPRINTF ( V_92 , L_343 , V_118 -> V_4 , V_118 -> V_107 ) ;
}
FPRINTF ( V_92 , L_20 ) ;
FPRINTF ( V_92 , L_344 , V_30 ) ;
FPRINTF ( V_92 , L_187 , V_61 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_345 , V_30 ) ;
for( V_118 = V_117 ; V_118 ; V_118 = V_118 -> V_7 ) {
FPRINTF ( V_75 , L_346 , V_118 -> V_107 , V_118 -> V_4 ) ;
}
FPRINTF ( V_75 , L_347 ) ;
FPRINTF ( V_75 , L_95 ) ;
FPRINTF ( V_75 , L_20 ) ;
FPRINTF ( V_75 , L_188 ) ;
FPRINTF ( V_75 , L_105 , V_61 ) ;
FPRINTF ( V_75 , L_106 ) ;
switch( V_122 ) {
case 16 :
FPRINTF ( V_75 , L_107 ) ;
break;
case 32 :
FPRINTF ( V_75 , L_113 ) ;
break;
default:
fprintf ( V_3 , L_348 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_75 , L_108 ) ;
FPRINTF ( V_75 , L_109 ) ;
FPRINTF ( V_75 , L_20 ) ;
sprintf ( V_123 , L_349 , V_30 ) ;
switch( V_122 ) {
case 16 :
F_17 ( V_37 -> V_39 , V_61 , L_111 , L_79 , L_1 , V_123 , 2 ) ;
break;
case 32 :
F_17 ( V_37 -> V_39 , V_61 , L_116 , L_79 , L_1 , V_123 , 4 ) ;
break;
default:
fprintf ( V_3 , L_348 ) ;
Exit ( 10 ) ;
}
FPRINTF ( NULL , L_350 , V_37 -> V_39 ) ;
V_38 = V_37 -> V_7 -> V_7 ;
}
static void F_31 ( char * V_124 )
{
T_13 * V_125 ;
V_125 = malloc ( sizeof( T_13 ) ) ;
V_125 -> V_7 = V_126 ;
V_126 = V_125 ;
V_125 -> V_4 = F_3 ( V_124 ) ;
}
static void
F_32 ( void )
{
T_9 * V_37 ;
T_13 * V_127 ;
T_14 V_128 ;
for( V_127 = V_126 ; V_127 ; V_127 = V_127 -> V_7 ) {
V_128 = strlen ( V_127 -> V_4 ) ;
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! strncmp ( V_37 -> V_39 , V_127 -> V_4 , V_128 ) ) {
V_37 -> V_39 += V_128 ;
}
}
}
}
static int Exit ( int V_129 )
{
fprintf ( V_3 , L_351 ) ;
F_18 ( 10 ) ;
exit ( V_129 ) ;
}
static void F_33 ( void )
{
fprintf ( V_3 , L_352 ) ;
}
static void
F_34 ( char * V_4 , T_1 * V_130 )
{
T_1 * V_131 ;
fprintf ( V_130 , L_353 , V_4 ) ;
V_131 = fopen ( V_4 , L_354 ) ;
while( ! feof ( V_131 ) ) {
int V_80 ;
V_80 = fgetc ( V_131 ) ;
if( V_80 != - 1 ) {
fputc ( V_80 , V_130 ) ;
}
}
fclose ( V_131 ) ;
fprintf ( V_130 , L_355 , V_4 ) ;
}
static char *
F_35 ( char * V_39 , char * * V_4 )
{
char V_95 [ 256 ] , * V_132 ;
int V_133 ;
int V_134 ;
V_132 = V_95 ;
V_133 = 1 ;
V_134 = 0 ;
while( 1 ) {
if( ! * V_39 ) {
* V_132 = 0 ;
* V_4 = F_3 ( V_95 ) ;
return V_39 ;
}
if( V_133 ) {
if( ( * V_39 == ' ' ) || ( * V_39 == '\t' ) ) {
V_39 ++ ;
continue;
}
if( * V_39 == '"' ) {
V_39 ++ ;
V_134 = 1 ;
}
V_133 = 0 ;
continue;
}
if( ( * V_39 == ' ' ) || ( * V_39 == '\t' ) ) {
if( V_134 ) {
* V_132 ++ = * V_39 ++ ;
continue;
}
* V_132 = 0 ;
* V_4 = F_3 ( V_95 ) ;
return V_39 ;
}
if( ( * V_39 == '"' ) || ( * V_39 == '\n' ) ) {
* V_132 = 0 ;
* V_4 = F_3 ( V_95 ) ;
return ++ V_39 ;
}
* V_132 ++ = * V_39 ++ ;
}
return NULL ;
}
static void
F_36 ( T_1 * V_1 )
{
char V_135 [ 1024 ] ;
FPRINTF ( NULL , L_356 ) ;
while( ! feof ( V_1 ) ) {
V_135 [ 0 ] = 0 ;
if( ! fgets ( V_135 , 1023 , V_1 ) || ! V_135 [ 0 ] ) {
continue;
}
if( V_135 [ 0 ] == '#' ) {
} else if( ! strncmp ( V_135 , L_357 , 6 ) ) {
T_8 * V_136 ;
char * V_39 , * V_4 ;
V_39 = V_135 + 6 ;
V_39 = F_35 ( V_39 , & V_4 ) ;
V_136 = malloc ( sizeof( T_8 ) ) ;
V_136 -> V_7 = V_36 ;
V_36 = V_136 ;
V_136 -> V_4 = V_4 ;
FPRINTF ( NULL , L_358 , V_136 -> V_4 ) ;
} else if( ! strncmp ( V_135 , L_359 , 4 ) ) {
char * V_4 , * V_61 , * V_28 , * V_29 ;
char * V_31 , * V_30 , * V_137 ;
char * V_39 ;
int V_54 ;
V_39 = V_135 + 4 ;
V_39 = F_35 ( V_39 , & V_4 ) ;
V_39 = F_35 ( V_39 , & V_61 ) ;
V_39 = F_35 ( V_39 , & V_28 ) ;
V_39 = F_35 ( V_39 , & V_29 ) ;
V_39 = F_35 ( V_39 , & V_31 ) ;
V_39 = F_35 ( V_39 , & V_30 ) ;
V_39 = F_35 ( V_39 , & V_137 ) ;
V_54 = atoi ( V_137 ) ;
FPRINTF ( NULL , L_360 , V_4 , V_61 ) ;
F_17 ( V_4 , V_61 , V_28 , V_29 , V_31 , V_30 , V_54 ) ;
} else if( ! strncmp ( V_135 , L_361 , 11 ) ) {
char * V_61 , * V_5 ;
char * V_39 ;
V_39 = V_135 + 11 ;
V_39 = F_35 ( V_39 , & V_61 ) ;
V_39 = F_35 ( V_39 , & V_5 ) ;
FPRINTF ( NULL , L_362 , V_61 , V_5 ) ;
F_2 ( V_61 , V_5 ) ;
} else if( ! strncmp ( V_135 , L_363 , 8 ) ) {
char * V_97 , * V_26 , * V_27 , * V_28 ;
char * V_29 , * V_30 , * V_31 , * V_32 ;
char * V_39 ;
V_39 = V_135 + 8 ;
V_39 = F_35 ( V_39 , & V_97 ) ;
V_39 = F_35 ( V_39 , & V_26 ) ;
V_39 = F_35 ( V_39 , & V_27 ) ;
V_39 = F_35 ( V_39 , & V_28 ) ;
V_39 = F_35 ( V_39 , & V_29 ) ;
V_39 = F_35 ( V_39 , & V_30 ) ;
V_39 = F_35 ( V_39 , & V_31 ) ;
V_39 = F_35 ( V_39 , & V_32 ) ;
FPRINTF ( NULL , L_364 , V_97 , V_26 ) ;
F_11 ( V_97 , V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ) ;
} else if( ! strncmp ( V_135 , L_365 , 9 ) ) {
char * V_17 , * V_18 ;
char * V_39 ;
V_39 = V_135 + 9 ;
V_39 = F_35 ( V_39 , & V_17 ) ;
V_39 = F_35 ( V_39 , & V_18 ) ;
FPRINTF ( NULL , L_366 , V_17 , V_18 ) ;
F_8 ( V_17 , V_18 ) ;
} else if( ! strncmp ( V_135 , L_367 , 14 ) ) {
char * V_111 , * V_138 ;
int V_53 ;
T_5 * V_14 ;
char * V_39 ;
V_39 = V_135 + 14 ;
V_39 = F_35 ( V_39 , & V_111 ) ;
V_39 = F_35 ( V_39 , & V_138 ) ;
V_53 = atoi ( V_138 ) ;
FPRINTF ( NULL , L_368 , V_111 , V_53 ) ;
V_14 = malloc ( sizeof( T_5 ) ) ;
V_14 -> V_7 = V_15 ;
V_15 = V_14 ;
V_14 -> V_4 = F_3 ( V_111 ) ;
V_14 -> V_16 = V_53 ;
} else if( ! strncmp ( V_135 , L_369 , 12 ) ) {
char * V_124 ;
char * V_39 ;
V_39 = V_135 + 12 ;
V_39 = F_35 ( V_39 , & V_124 ) ;
FPRINTF ( NULL , L_370 , V_124 ) ;
F_31 ( V_124 ) ;
} else {
fprintf ( V_3 , L_371 , V_135 ) ;
exit ( 10 ) ;
}
}
}
int main ( int V_139 , char * V_140 [] )
{
char V_141 [ 256 ] ;
char V_142 [ 256 ] ;
char V_143 [ 256 ] ;
T_10 * V_98 ;
T_1 * V_1 ;
if( V_139 != 2 ) {
F_33 () ;
exit ( 0 ) ;
}
V_75 = fopen ( L_372 , L_373 ) ;
V_92 = fopen ( L_374 , L_373 ) ;
V_34 = fopen ( L_375 , L_373 ) ;
V_33 = fopen ( L_376 , L_373 ) ;
V_74 = fopen ( L_377 , L_373 ) ;
V_73 = fopen ( L_378 , L_373 ) ;
V_116 = fopen ( L_379 , L_373 ) ;
V_76 = fopen ( L_380 , L_373 ) ;
sprintf ( V_141 , L_381 , V_140 [ 1 ] ) ;
V_1 = fopen ( V_141 , L_354 ) ;
if( V_1 ) {
F_36 ( V_1 ) ;
fclose ( V_1 ) ;
}
sprintf ( V_141 , L_382 , V_140 [ 1 ] ) ;
V_1 = fopen ( V_141 , L_354 ) ;
if( ! V_1 ) {
fprintf ( V_3 , L_383 , V_141 ) ;
Exit ( 0 ) ;
}
V_90 = 0 ;
V_88 = 0 ;
F_21 ( V_1 ) ;
F_14 ( L_53 ) ;
F_14 ( L_54 ) ;
F_13 ( L_384 , L_163 ) ;
F_13 ( L_385 , L_124 ) ;
F_13 ( L_386 , L_128 ) ;
F_13 ( L_387 , L_154 ) ;
FPRINTF ( NULL , L_388 ) ;
F_19 () ;
sprintf ( V_143 , L_389 , V_71 ) ;
F_31 ( V_143 ) ;
F_32 () ;
while( 1 ) {
if( ! strcmp ( V_38 -> V_39 , L_24 ) ) {
V_38 = F_15 ( V_38 , & V_98 ) ;
continue;
}
if( ! strcmp ( V_38 -> V_39 , L_176 )
&& ! strcmp ( V_38 -> V_7 -> V_39 , L_335 ) ) {
F_30 () ;
continue;
}
if( ! strcmp ( V_38 -> V_39 , L_176 )
&& ! strcmp ( V_38 -> V_7 -> V_39 , L_24 )
&& ! strcmp ( V_38 -> V_7 -> V_7 -> V_39 , L_332 )
&& ! strcmp ( V_38 -> V_7 -> V_7 -> V_7 -> V_39 , L_30 )
&& ! strcmp ( V_38 -> V_7 -> V_7 -> V_7 -> V_7 -> V_39 , L_335 ) ) {
F_30 () ;
continue;
}
if( ! strcmp ( V_38 -> V_39 , L_167 ) ) {
F_23 () ;
continue;
}
if( ! strcmp ( V_38 -> V_39 , L_176 ) ) {
T_9 * V_40 ;
V_40 = V_38 -> V_7 ;
if( ! strcmp ( V_40 -> V_39 , L_24 ) ) {
V_40 = F_15 ( V_40 , & V_98 ) ;
}
if( ! strcmp ( V_40 -> V_39 , L_179 ) ) {
F_24 ( 0 ) ;
F_24 ( 1 ) ;
continue;
}
}
if( ! strcmp ( V_38 -> V_39 , L_176 ) ) {
T_9 * V_40 ;
V_40 = V_38 -> V_7 ;
if( ! strcmp ( V_40 -> V_39 , L_24 ) ) {
V_40 = F_15 ( V_40 , & V_98 ) ;
}
if( ! strcmp ( V_40 -> V_39 , L_271 ) ) {
F_27 ( 0 ) ;
F_27 ( 1 ) ;
continue;
}
}
if( ! strcmp ( V_38 -> V_39 , L_176 ) ) {
T_9 * V_40 ;
V_40 = V_38 -> V_7 ;
if( ! strcmp ( V_40 -> V_39 , L_24 ) ) {
V_40 = F_15 ( V_40 , & V_98 ) ;
}
if( ! strcmp ( V_40 -> V_39 , L_237 ) ) {
F_25 ( 0 ) ;
F_25 ( 1 ) ;
continue;
}
}
if( ! strcmp ( V_38 -> V_39 , L_163 )
&& ! strcmp ( V_38 -> V_7 -> V_7 -> V_39 , L_22 ) ) {
F_29 ( 0 ) ;
F_29 ( 1 ) ;
F_29 ( 2 ) ;
continue;
}
if( ! strcmp ( V_38 -> V_39 , L_164 ) ) {
F_22 () ;
continue;
}
break;
} ;
fclose ( V_75 ) ;
fclose ( V_92 ) ;
fclose ( V_33 ) ;
fclose ( V_34 ) ;
fclose ( V_73 ) ;
fclose ( V_74 ) ;
fclose ( V_116 ) ;
fclose ( V_76 ) ;
if( strcmp ( V_38 -> V_39 , L_27 ) || V_38 -> V_7 ) {
fprintf ( V_3 , L_390 ) ;
F_18 ( 10 ) ;
exit ( 10 ) ;
}
F_9 () ;
sprintf ( line , L_391 , V_71 ) ;
V_1 = fopen ( line , L_373 ) ;
sprintf ( V_142 , L_392 , V_140 [ 1 ] ) ;
V_144 = fopen ( V_142 , L_354 ) ;
if( ! V_144 ) {
fprintf ( V_3 , L_393 , V_142 ) ;
exit ( 10 ) ;
}
while( ! feof ( V_144 ) ) {
line [ 0 ] = 0 ;
if( ! fgets ( line , 1024 , V_144 ) || ! line [ 0 ] ) {
continue;
}
if( ! strncmp ( line , L_372 , 8 ) ) {
F_34 ( L_372 , V_1 ) ;
} else if( ! strncmp ( line , L_374 , 7 ) ) {
F_34 ( L_374 , V_1 ) ;
} else if( ! strncmp ( line , L_375 , 9 ) ) {
F_34 ( L_375 , V_1 ) ;
} else if( ! strncmp ( line , L_376 , 6 ) ) {
F_34 ( L_376 , V_1 ) ;
} else if( ! strncmp ( line , L_377 , 10 ) ) {
F_34 ( L_377 , V_1 ) ;
} else if( ! strncmp ( line , L_378 , 7 ) ) {
F_34 ( L_378 , V_1 ) ;
} else if( ! strncmp ( line , L_379 , 6 ) ) {
F_34 ( L_379 , V_1 ) ;
} else if( ! strncmp ( line , L_380 , 11 ) ) {
F_34 ( L_380 , V_1 ) ;
} else {
fputs ( line , V_1 ) ;
}
}
fclose ( V_1 ) ;
fclose ( V_144 ) ;
sprintf ( line , L_394 , V_71 ) ;
V_1 = fopen ( line , L_373 ) ;
sprintf ( V_142 , L_395 , V_140 [ 1 ] ) ;
V_144 = fopen ( V_142 , L_354 ) ;
if( ! V_144 ) {
fprintf ( V_3 , L_393 , V_142 ) ;
exit ( 10 ) ;
}
while( ! feof ( V_144 ) ) {
line [ 0 ] = 0 ;
if( ! fgets ( line , 1024 , V_144 ) || ! line [ 0 ] ) {
continue;
}
if( ! strncmp ( line , L_372 , 8 ) ) {
F_34 ( L_372 , V_1 ) ;
} else if( ! strncmp ( line , L_374 , 7 ) ) {
F_34 ( L_374 , V_1 ) ;
} else if( ! strncmp ( line , L_375 , 9 ) ) {
F_34 ( L_375 , V_1 ) ;
} else if( ! strncmp ( line , L_376 , 6 ) ) {
F_34 ( L_376 , V_1 ) ;
} else if( ! strncmp ( line , L_377 , 10 ) ) {
F_34 ( L_377 , V_1 ) ;
} else if( ! strncmp ( line , L_378 , 7 ) ) {
F_34 ( L_378 , V_1 ) ;
} else if( ! strncmp ( line , L_379 , 6 ) ) {
F_34 ( L_379 , V_1 ) ;
} else if( ! strncmp ( line , L_380 , 11 ) ) {
F_34 ( L_380 , V_1 ) ;
} else {
fputs ( line , V_1 ) ;
}
}
printf ( L_396 , V_71 ) ;
fclose ( V_1 ) ;
fclose ( V_144 ) ;
remove ( L_372 ) ;
remove ( L_374 ) ;
remove ( L_375 ) ;
remove ( L_376 ) ;
remove ( L_377 ) ;
remove ( L_378 ) ;
remove ( L_379 ) ;
remove ( L_380 ) ;
return 0 ;
}
