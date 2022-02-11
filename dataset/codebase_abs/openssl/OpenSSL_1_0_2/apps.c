int F_1 ( char * V_1 , int * V_2 , char * * V_3 [] )
{
T_1 * V_4 ;
int V_5 , V_6 ;
unsigned int V_7 ;
static char * V_8 = NULL ;
static char * * V_9 = NULL ;
char * V_10 ;
V_4 = fopen ( V_1 , L_1 ) ;
if ( V_4 == NULL )
return ( 0 ) ;
if ( fseek ( V_4 , 0 , V_11 ) == 0 )
V_7 = ftell ( V_4 ) , rewind ( V_4 ) ;
else
V_7 = - 1 ;
if ( V_7 <= 0 ) {
fclose ( V_4 ) ;
return ( 0 ) ;
}
* V_2 = 0 ;
* V_3 = NULL ;
if ( V_8 != NULL )
F_2 ( V_8 ) ;
V_8 = ( char * ) F_3 ( V_7 + 1 ) ;
if ( V_8 == NULL )
return ( 0 ) ;
V_7 = fread ( V_8 , 1 , V_7 , V_4 ) ;
if ( V_7 <= 1 )
return ( 0 ) ;
V_8 [ V_7 ] = '\0' ;
V_6 = 0 ;
for ( V_10 = V_8 ; * V_10 ; V_10 ++ )
if ( * V_10 == '\n' )
V_6 ++ ;
if ( V_9 != NULL )
F_2 ( V_9 ) ;
V_9 = ( char * * ) F_3 ( sizeof( char * ) * ( V_6 * 2 ) ) ;
* V_3 = V_9 ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; ) {
if ( ! * V_10 )
break;
if ( * V_10 == '#' ) {
while ( * V_10 && ( * V_10 != '\n' ) )
V_10 ++ ;
continue;
}
* ( V_9 ++ ) = V_10 ;
V_5 ++ ;
while ( * V_10 && ( ( * V_10 != ' ' ) && ( * V_10 != '\t' ) && ( * V_10 != '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 )
break;
if ( * V_10 == '\n' ) {
* ( V_10 ++ ) = '\0' ;
continue;
}
V_10 ++ ;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 )
break;
if ( * V_10 == '\n' ) {
V_10 ++ ;
continue;
}
* ( V_9 ++ ) = V_10 ++ ;
V_5 ++ ;
while ( * V_10 && ( * V_10 != '\n' ) )
V_10 ++ ;
if ( ! * V_10 )
break;
* ( V_10 ++ ) = '\0' ;
}
* V_2 = V_5 ;
return ( 1 ) ;
}
int F_4 ( char * V_12 )
{
if ( V_12 == NULL )
return V_13 ;
if ( ( * V_12 == 'D' ) || ( * V_12 == 'd' ) )
return ( V_14 ) ;
else if ( ( * V_12 == 'T' ) || ( * V_12 == 't' ) )
return ( V_15 ) ;
else if ( ( * V_12 == 'N' ) || ( * V_12 == 'n' ) )
return ( V_16 ) ;
else if ( ( * V_12 == 'S' ) || ( * V_12 == 's' ) )
return ( V_17 ) ;
else if ( ( * V_12 == 'M' ) || ( * V_12 == 'm' ) )
return ( V_18 ) ;
else if ( ( * V_12 == '1' )
|| ( strcmp ( V_12 , L_2 ) == 0 ) || ( strcmp ( V_12 , L_3 ) == 0 )
|| ( strcmp ( V_12 , L_4 ) == 0 ) || ( strcmp ( V_12 , L_5 ) == 0 ) )
return ( V_19 ) ;
else if ( ( * V_12 == 'E' ) || ( * V_12 == 'e' ) )
return ( V_20 ) ;
else if ( ( * V_12 == 'H' ) || ( * V_12 == 'h' ) )
return V_21 ;
else if ( ( * V_12 == 'P' ) || ( * V_12 == 'p' ) ) {
if ( V_12 [ 1 ] == 'V' || V_12 [ 1 ] == 'v' )
return V_22 ;
else
return ( V_23 ) ;
} else
return ( V_13 ) ;
}
void F_5 ( char * V_24 , char * V_25 , int V_26 )
{
int V_6 , V_27 ;
char * V_10 = NULL ;
V_27 = strlen ( V_24 ) ;
for ( V_6 = V_27 - 1 ; V_6 > 0 ; V_6 -- ) {
if ( ( V_24 [ V_6 ] == '/' ) || ( V_24 [ V_6 ] == '\\' ) || ( V_24 [ V_6 ] == ':' ) ) {
V_10 = & ( V_24 [ V_6 + 1 ] ) ;
break;
}
}
if ( V_10 == NULL )
V_10 = V_24 ;
V_27 = strlen ( V_10 ) ;
# if F_6 ( V_28 )
if ( ( V_27 > 4 ) && ( V_10 [ V_27 - 4 ] == '.' ) &&
( ( V_10 [ V_27 - 3 ] == 'n' ) || ( V_10 [ V_27 - 3 ] == 'N' ) ) &&
( ( V_10 [ V_27 - 2 ] == 'l' ) || ( V_10 [ V_27 - 2 ] == 'L' ) ) &&
( ( V_10 [ V_27 - 1 ] == 'm' ) || ( V_10 [ V_27 - 1 ] == 'M' ) ) )
V_27 -= 4 ;
# else
if ( ( V_27 > 4 ) && ( V_10 [ V_27 - 4 ] == '.' ) &&
( ( V_10 [ V_27 - 3 ] == 'e' ) || ( V_10 [ V_27 - 3 ] == 'E' ) ) &&
( ( V_10 [ V_27 - 2 ] == 'x' ) || ( V_10 [ V_27 - 2 ] == 'X' ) ) &&
( ( V_10 [ V_27 - 1 ] == 'e' ) || ( V_10 [ V_27 - 1 ] == 'E' ) ) )
V_27 -= 4 ;
# endif
if ( V_27 > V_26 - 1 )
V_27 = V_26 - 1 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
if ( ( V_10 [ V_6 ] >= 'A' ) && ( V_10 [ V_6 ] <= 'Z' ) )
V_25 [ V_6 ] = V_10 [ V_6 ] - 'A' + 'a' ;
else
V_25 [ V_6 ] = V_10 [ V_6 ] ;
}
V_25 [ V_27 ] = '\0' ;
}
void F_5 ( char * V_24 , char * V_25 , int V_26 )
{
char * V_10 = V_24 , * V_29 ;
char * V_30 = L_6 ;
while ( * V_30 != '\0' ) {
V_29 = strrchr ( V_10 , * V_30 ) ;
if ( V_29 > V_10 )
V_10 = V_29 + 1 ;
V_30 ++ ;
}
V_29 = strrchr ( V_10 , '.' ) ;
if ( V_29 == NULL )
V_29 = V_10 + strlen ( V_10 ) ;
strncpy ( V_25 , V_10 , V_26 - 1 ) ;
if ( V_29 - V_10 >= V_26 ) {
V_25 [ V_26 - 1 ] = '\0' ;
} else {
V_25 [ V_29 - V_10 ] = '\0' ;
}
}
void F_5 ( char * V_24 , char * V_25 , int V_26 )
{
char * V_10 ;
V_10 = strrchr ( V_24 , '/' ) ;
if ( V_10 != NULL )
V_10 ++ ;
else
V_10 = V_24 ;
F_7 ( V_25 , V_10 , V_26 ) ;
}
int F_8 ( ARGS * V_9 , char * V_8 , int * V_2 , char * * V_3 [] )
{
int V_5 , V_6 ;
char * V_10 ;
* V_2 = 0 ;
* V_3 = NULL ;
V_6 = 0 ;
if ( V_9 -> V_31 == 0 ) {
V_9 -> V_31 = 20 ;
V_9 -> V_32 = ( char * * ) F_3 ( sizeof( char * ) * V_9 -> V_31 ) ;
if ( V_9 -> V_32 == NULL )
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_9 -> V_31 ; V_6 ++ )
V_9 -> V_32 [ V_6 ] = NULL ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; ) {
if ( ! * V_10 )
break;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 )
break;
if ( V_5 >= V_9 -> V_31 ) {
char * * V_33 ;
int V_34 = V_9 -> V_31 + 20 ;
V_33 = ( char * * ) F_9 ( V_9 -> V_32 ,
sizeof( char * ) * V_34 ) ;
if ( V_33 == NULL )
return 0 ;
V_9 -> V_32 = V_33 ;
V_9 -> V_31 = V_34 ;
for ( V_6 = V_5 ; V_6 < V_9 -> V_31 ; V_6 ++ )
V_9 -> V_32 [ V_6 ] = NULL ;
}
V_9 -> V_32 [ V_5 ++ ] = V_10 ;
if ( ( * V_10 == '\'' ) || ( * V_10 == '\"' ) ) {
V_6 = * ( V_10 ++ ) ;
V_9 -> V_32 [ V_5 - 1 ] ++ ;
while ( * V_10 && ( * V_10 != V_6 ) )
V_10 ++ ;
* V_10 = '\0' ;
} else {
while ( * V_10 && ( ( * V_10 != ' ' ) && ( * V_10 != '\t' ) && ( * V_10 != '\n' ) ) )
V_10 ++ ;
if ( * V_10 == '\0' )
V_10 -- ;
else
* V_10 = '\0' ;
}
V_10 ++ ;
}
* V_2 = V_5 ;
* V_3 = V_9 -> V_32 ;
return ( 1 ) ;
}
int F_10 ( long V_35 )
{
return ( 1 ) ;
}
int F_11 ( T_2 * V_25 , T_3 * V_36 )
{
char * V_10 ;
V_10 = F_12 ( F_13 ( V_36 ) , NULL , 0 ) ;
F_14 ( V_25 , L_7 ) ;
F_14 ( V_25 , V_10 ) ;
F_2 ( V_10 ) ;
V_10 = F_12 ( F_15 ( V_36 ) , NULL , 0 ) ;
F_14 ( V_25 , L_8 ) ;
F_14 ( V_25 , V_10 ) ;
F_14 ( V_25 , L_9 ) ;
F_2 ( V_10 ) ;
return 0 ;
}
static int F_16 ( T_4 * V_37 )
{
return F_17 ( F_18 () ) ( V_37 ) ;
}
static int F_19 ( T_4 * V_37 , T_5 * V_38 )
{
if ( F_20 ( V_38 ) & V_39
&& F_21 ( V_37 ) ) {
switch ( F_22 ( V_38 ) ) {
case V_40 :
case V_41 :
{
const char * V_42 =
( ( V_43 * ) F_21 ( V_37 ) ) -> V_42 ;
if ( V_42 && V_42 [ 0 ] != '\0' ) {
F_23 ( V_37 , V_38 , V_42 ) ;
return 1 ;
}
}
default:
break;
}
}
return F_24 ( F_18 () ) ( V_37 , V_38 ) ;
}
static int F_25 ( T_4 * V_37 , T_5 * V_38 )
{
if ( F_20 ( V_38 ) & V_39
&& F_21 ( V_37 ) ) {
switch ( F_22 ( V_38 ) ) {
case V_40 :
case V_41 :
{
const char * V_42 =
( ( V_43 * ) F_21 ( V_37 ) ) -> V_42 ;
if ( V_42 && V_42 [ 0 ] != '\0' )
return 1 ;
}
default:
break;
}
}
return F_26 ( F_18 () ) ( V_37 , V_38 ) ;
}
static int F_27 ( T_4 * V_37 )
{
return F_28 ( F_18 () ) ( V_37 ) ;
}
int F_29 ( void )
{
V_44 = F_30 ( L_10 ) ;
F_31 ( V_44 , F_16 ) ;
F_32 ( V_44 , F_19 ) ;
F_33 ( V_44 , F_25 ) ;
F_34 ( V_44 , F_27 ) ;
return 0 ;
}
void F_35 ( void )
{
if ( V_44 ) {
F_36 ( V_44 ) ;
V_44 = NULL ;
}
}
int F_37 ( char * V_8 , int V_45 , int V_46 , V_43 * V_47 )
{
T_4 * V_37 = NULL ;
int V_48 = 0 ;
const char * V_49 = NULL ;
const char * V_42 = NULL ;
V_43 * V_50 = ( V_43 * ) V_47 ;
if ( V_50 ) {
if ( V_50 -> V_42 )
V_42 = V_50 -> V_42 ;
if ( V_50 -> V_49 )
V_49 = V_50 -> V_49 ;
}
if ( V_42 ) {
V_48 = strlen ( V_42 ) ;
if ( V_48 > V_45 )
V_48 = V_45 ;
memcpy ( V_8 , V_42 , V_48 ) ;
return V_48 ;
}
V_37 = F_38 ( V_44 ) ;
if ( V_37 ) {
int V_51 = 0 ;
char * V_52 = NULL ;
int V_53 = 0 ;
char * V_54 = NULL ;
V_54 = F_39 ( V_37 , L_11 , V_49 ) ;
V_53 |= V_39 ;
F_40 ( V_37 , V_55 , 1 , 0 , 0 ) ;
if ( V_51 >= 0 )
V_51 = F_41 ( V_37 , V_54 , V_53 , V_8 ,
V_56 , V_45 - 1 ) ;
if ( V_51 >= 0 && V_46 ) {
V_52 = ( char * ) F_3 ( V_45 ) ;
V_51 = F_42 ( V_37 , V_54 , V_53 , V_52 ,
V_56 , V_45 - 1 , V_8 ) ;
}
if ( V_51 >= 0 )
do {
V_51 = F_43 ( V_37 ) ;
}
while ( V_51 < 0 && F_40 ( V_37 , V_57 , 0 , 0 , 0 ) );
if ( V_52 ) {
F_44 ( V_52 , ( unsigned int ) V_45 ) ;
F_2 ( V_52 ) ;
}
if ( V_51 >= 0 )
V_48 = strlen ( V_8 ) ;
if ( V_51 == - 1 ) {
F_45 ( V_58 , L_12 ) ;
F_46 ( V_58 ) ;
F_44 ( V_8 , ( unsigned int ) V_45 ) ;
V_48 = 0 ;
}
if ( V_51 == - 2 ) {
F_45 ( V_58 , L_13 ) ;
F_44 ( V_8 , ( unsigned int ) V_45 ) ;
V_48 = 0 ;
}
F_47 ( V_37 ) ;
F_2 ( V_54 ) ;
}
return V_48 ;
}
int F_48 ( T_2 * V_59 , char * V_60 , char * V_61 , char * * V_62 , char * * V_63 )
{
int V_64 ;
if ( ! V_61 || ! V_60 || strcmp ( V_60 , V_61 ) )
V_64 = 0 ;
else
V_64 = 1 ;
if ( V_60 ) {
* V_62 = F_49 ( V_59 , V_60 , V_64 ) ;
if ( ! * V_62 )
return 0 ;
} else if ( V_62 )
* V_62 = NULL ;
if ( V_61 ) {
* V_63 = F_49 ( V_59 , V_61 , V_64 ? 2 : 0 ) ;
if ( ! * V_63 )
return 0 ;
} else if ( V_63 )
* V_63 = NULL ;
return 1 ;
}
static char * F_49 ( T_2 * V_59 , char * V_9 , int V_65 )
{
char * V_66 , V_67 [ V_68 ] ;
static T_2 * V_69 = NULL ;
int V_6 ;
if ( ! strncmp ( V_9 , L_14 , 5 ) )
return F_50 ( V_9 + 5 ) ;
if ( ! strncmp ( V_9 , L_15 , 4 ) ) {
V_66 = getenv ( V_9 + 4 ) ;
if ( ! V_66 ) {
F_45 ( V_59 , L_16 , V_9 + 4 ) ;
return NULL ;
}
return F_50 ( V_66 ) ;
}
if ( ! V_65 || ! V_69 ) {
if ( ! strncmp ( V_9 , L_17 , 5 ) ) {
V_69 = F_51 ( V_9 + 5 , L_1 ) ;
if ( ! V_69 ) {
F_45 ( V_59 , L_18 , V_9 + 5 ) ;
return NULL ;
}
#if ! F_6 ( V_70 )
} else if ( ! strncmp ( V_9 , L_19 , 3 ) ) {
T_2 * V_71 ;
V_6 = atoi ( V_9 + 3 ) ;
if ( V_6 >= 0 )
V_69 = F_52 ( V_6 , V_72 ) ;
if ( ( V_6 < 0 ) || ! V_69 ) {
F_45 ( V_59 , L_20 , V_9 + 3 ) ;
return NULL ;
}
V_71 = F_53 ( F_54 () ) ;
V_69 = F_55 ( V_71 , V_69 ) ;
#endif
} else if ( ! strcmp ( V_9 , L_21 ) ) {
V_69 = F_56 ( V_73 , V_72 ) ;
if ( ! V_69 ) {
F_45 ( V_59 , L_22 ) ;
return NULL ;
}
} else {
F_45 ( V_59 , L_23 , V_9 ) ;
return NULL ;
}
}
V_6 = F_57 ( V_69 , V_67 , V_68 ) ;
if ( V_65 != 1 ) {
F_58 ( V_69 ) ;
V_69 = NULL ;
}
if ( V_6 <= 0 ) {
F_45 ( V_59 , L_24 ) ;
return NULL ;
}
V_66 = strchr ( V_67 , '\n' ) ;
if ( V_66 )
* V_66 = 0 ;
return F_50 ( V_67 ) ;
}
int F_59 ( T_2 * V_59 , T_6 * V_74 )
{
char * V_10 ;
F_60 ( V_75 ) * V_76 ;
V_75 * V_77 ;
int V_6 ;
if ( ! ( V_10 = F_61 ( V_74 , NULL , L_25 ) ) ) {
F_62 () ;
return 1 ;
}
if ( ! ( V_76 = F_63 ( V_74 , V_10 ) ) ) {
F_45 ( V_59 , L_26 , V_10 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < F_64 ( V_76 ) ; V_6 ++ ) {
V_77 = F_65 ( V_76 , V_6 ) ;
if ( F_66 ( V_77 -> V_78 , V_77 -> V_79 , V_77 -> V_79 ) == V_80 ) {
F_45 ( V_59 , L_27 ,
V_77 -> V_79 , V_77 -> V_78 ) ;
return 0 ;
}
}
return 1 ;
}
int F_67 ( const char * V_81 , T_2 * V_59 ,
T_3 * * V_82 , T_7 * * V_83 )
{
char * V_84 = NULL , * V_85 = NULL , * V_86 = NULL ;
T_2 * V_87 = NULL ;
T_8 * V_88 = NULL ;
int V_89 , V_90 = 0 ;
if ( ! F_68 ( V_81 , & V_84 , & V_85 , & V_86 , & V_89 ) )
goto V_59;
if ( V_89 ) {
if ( V_59 )
F_14 ( V_59 , L_28 ) ;
goto V_59;
}
V_87 = F_69 ( V_84 ) ;
if ( ! V_87 || ! F_70 ( V_87 , V_85 ) )
goto V_59;
V_88 = F_71 ( V_87 , 1024 ) ;
if ( ! V_88 )
goto V_59;
if ( ! F_72 ( V_88 , L_29 , V_86 ) )
goto V_59;
if ( ! F_73 ( V_88 , L_30 , V_84 ) )
goto V_59;
if ( V_82 ) {
do {
V_90 = F_74 ( V_88 , V_82 ) ;
}
while ( V_90 == - 1 );
} else {
do {
V_90 = F_75 ( V_88 , V_83 ) ;
} while ( V_90 == - 1 );
}
V_59:
if ( V_84 )
F_2 ( V_84 ) ;
if ( V_86 )
F_2 ( V_86 ) ;
if ( V_85 )
F_2 ( V_85 ) ;
if ( V_87 )
F_58 ( V_87 ) ;
if ( V_88 )
F_76 ( V_88 ) ;
if ( V_90 != 1 ) {
if ( V_87 && V_59 )
F_45 ( V_58 , L_31 ,
V_82 ? L_32 : L_33 , V_81 ) ;
F_46 ( V_58 ) ;
}
return V_90 ;
}
T_3 * F_77 ( T_2 * V_59 , const char * V_1 , int V_91 ,
const char * V_92 , T_9 * V_93 , const char * V_94 )
{
T_3 * V_36 = NULL ;
T_2 * V_95 ;
if ( V_91 == V_21 ) {
F_67 ( V_1 , V_59 , & V_36 , NULL ) ;
return V_36 ;
}
if ( ( V_95 = F_53 ( F_78 () ) ) == NULL ) {
F_46 ( V_59 ) ;
goto V_96;
}
if ( V_1 == NULL ) {
#ifdef F_79
# ifndef F_80
setvbuf ( V_73 , NULL , F_79 , 0 ) ;
# endif
#endif
F_81 ( V_95 , V_73 , V_72 ) ;
} else {
if ( F_82 ( V_95 , V_1 ) <= 0 ) {
F_45 ( V_59 , L_34 , V_94 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_96;
}
}
if ( V_91 == V_14 )
V_36 = F_83 ( V_95 , NULL ) ;
else if ( V_91 == V_16 ) {
T_10 * V_97 ;
V_97 = F_84 ( F_85 ( T_10 ) , V_95 , NULL ) ;
if ( V_97 == NULL )
goto V_96;
if ( ( strncmp ( V_98 , ( char * ) V_97 -> V_99 -> V_32 ,
V_97 -> V_99 -> V_100 ) != 0 ) ) {
F_86 ( V_97 ) ;
F_45 ( V_59 , L_35 ) ;
goto V_96;
}
V_36 = V_97 -> V_95 ;
V_97 -> V_95 = NULL ;
F_86 ( V_97 ) ;
} else if ( V_91 == V_23 )
V_36 = F_87 ( V_95 , NULL ,
( V_101 * ) F_37 , NULL ) ;
else if ( V_91 == V_19 ) {
if ( ! F_88 ( V_59 , V_95 , V_94 , NULL , NULL , NULL , & V_36 , NULL ) )
goto V_96;
} else {
F_45 ( V_59 , L_36 , V_94 ) ;
goto V_96;
}
V_96:
if ( V_36 == NULL ) {
F_45 ( V_59 , L_37 ) ;
F_46 ( V_59 ) ;
}
if ( V_95 != NULL )
F_89 ( V_95 ) ;
return ( V_36 ) ;
}
T_7 * F_90 ( const char * V_102 , int V_91 )
{
T_7 * V_36 = NULL ;
T_2 * V_24 = NULL ;
if ( V_91 == V_21 ) {
F_67 ( V_102 , V_58 , NULL , & V_36 ) ;
return V_36 ;
}
V_24 = F_53 ( F_78 () ) ;
if ( V_24 == NULL ) {
F_46 ( V_58 ) ;
goto V_96;
}
if ( V_102 == NULL )
F_81 ( V_24 , V_73 , V_72 ) ;
else {
if ( F_82 ( V_24 , V_102 ) <= 0 ) {
perror ( V_102 ) ;
goto V_96;
}
}
if ( V_91 == V_14 )
V_36 = F_91 ( V_24 , NULL ) ;
else if ( V_91 == V_23 )
V_36 = F_92 ( V_24 , NULL , NULL , NULL ) ;
else {
F_45 ( V_58 , L_38 ) ;
goto V_96;
}
if ( V_36 == NULL ) {
F_45 ( V_58 , L_39 ) ;
F_46 ( V_58 ) ;
goto V_96;
}
V_96:
F_89 ( V_24 ) ;
return ( V_36 ) ;
}
T_11 * F_93 ( T_2 * V_59 , const char * V_1 , int V_91 , int V_103 ,
const char * V_92 , T_9 * V_93 , const char * V_104 )
{
T_2 * V_105 = NULL ;
T_11 * V_106 = NULL ;
V_43 V_50 ;
V_50 . V_42 = V_92 ;
V_50 . V_49 = V_1 ;
if ( V_1 == NULL && ( ! V_103 || V_91 == V_20 ) ) {
F_45 ( V_59 , L_40 ) ;
goto V_96;
}
#ifndef F_94
if ( V_91 == V_20 ) {
if ( ! V_93 )
F_45 ( V_59 , L_41 ) ;
else {
V_106 = F_95 ( V_93 , V_1 , V_44 , & V_50 ) ;
if ( ! V_106 ) {
F_45 ( V_59 , L_42 , V_104 ) ;
F_46 ( V_59 ) ;
}
}
goto V_96;
}
#endif
V_105 = F_53 ( F_78 () ) ;
if ( V_105 == NULL ) {
F_46 ( V_59 ) ;
goto V_96;
}
if ( V_1 == NULL && V_103 ) {
#ifdef F_79
# ifndef F_80
setvbuf ( V_73 , NULL , F_79 , 0 ) ;
# endif
#endif
F_81 ( V_105 , V_73 , V_72 ) ;
} else if ( F_82 ( V_105 , V_1 ) <= 0 ) {
F_45 ( V_59 , L_34 , V_104 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_96;
}
if ( V_91 == V_14 ) {
V_106 = F_96 ( V_105 , NULL ) ;
} else if ( V_91 == V_23 ) {
V_106 = F_97 ( V_105 , NULL ,
( V_101 * ) F_37 ,
& V_50 ) ;
}
#if ! F_6 ( V_107 ) && ! F_6 ( V_108 )
else if ( V_91 == V_16 || V_91 == V_109 )
V_106 = F_98 ( V_59 , V_105 , V_1 , V_104 , V_91 ) ;
#endif
else if ( V_91 == V_19 ) {
if ( ! F_88 ( V_59 , V_105 , V_104 ,
( V_101 * ) F_37 , & V_50 ,
& V_106 , NULL , NULL ) )
goto V_96;
}
#if ! F_6 ( V_108 ) && ! F_6 ( V_110 ) && ! F_6 ( V_107 )
else if ( V_91 == V_18 )
V_106 = F_99 ( V_105 ) ;
else if ( V_91 == V_22 )
V_106 = F_100 ( V_105 , ( V_101 * ) F_37 ,
& V_50 ) ;
#endif
else {
F_45 ( V_59 , L_43 ) ;
goto V_96;
}
V_96:
if ( V_105 != NULL )
F_89 ( V_105 ) ;
if ( V_106 == NULL ) {
F_45 ( V_59 , L_44 , V_104 ) ;
F_46 ( V_59 ) ;
}
return ( V_106 ) ;
}
T_11 * F_101 ( T_2 * V_59 , const char * V_1 , int V_91 , int V_103 ,
const char * V_92 , T_9 * V_93 , const char * V_104 )
{
T_2 * V_105 = NULL ;
T_11 * V_106 = NULL ;
V_43 V_50 ;
V_50 . V_42 = V_92 ;
V_50 . V_49 = V_1 ;
if ( V_1 == NULL && ( ! V_103 || V_91 == V_20 ) ) {
F_45 ( V_59 , L_40 ) ;
goto V_96;
}
#ifndef F_94
if ( V_91 == V_20 ) {
if ( ! V_93 )
F_45 ( V_58 , L_41 ) ;
else
V_106 = F_102 ( V_93 , V_1 , V_44 , & V_50 ) ;
goto V_96;
}
#endif
V_105 = F_53 ( F_78 () ) ;
if ( V_105 == NULL ) {
F_46 ( V_59 ) ;
goto V_96;
}
if ( V_1 == NULL && V_103 ) {
#ifdef F_79
# ifndef F_80
setvbuf ( V_73 , NULL , F_79 , 0 ) ;
# endif
#endif
F_81 ( V_105 , V_73 , V_72 ) ;
} else if ( F_82 ( V_105 , V_1 ) <= 0 ) {
F_45 ( V_59 , L_34 , V_104 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_96;
}
if ( V_91 == V_14 ) {
V_106 = F_103 ( V_105 , NULL ) ;
}
#ifndef V_108
else if ( V_91 == V_111 ) {
T_12 * V_112 ;
V_112 = F_104 ( V_105 , NULL ) ;
if ( V_112 ) {
V_106 = F_105 () ;
if ( V_106 )
F_106 ( V_106 , V_112 ) ;
F_107 ( V_112 ) ;
} else
V_106 = NULL ;
} else if ( V_91 == V_113 ) {
T_12 * V_112 ;
V_112 = F_108 ( V_105 , NULL ,
( V_101 * ) F_37 ,
& V_50 ) ;
if ( V_112 ) {
V_106 = F_105 () ;
if ( V_106 )
F_106 ( V_106 , V_112 ) ;
F_107 ( V_112 ) ;
} else
V_106 = NULL ;
}
#endif
else if ( V_91 == V_23 ) {
V_106 = F_109 ( V_105 , NULL ,
( V_101 * ) F_37 ,
& V_50 ) ;
}
#if ! F_6 ( V_107 ) && ! F_6 ( V_108 )
else if ( V_91 == V_16 || V_91 == V_109 )
V_106 = F_98 ( V_59 , V_105 , V_1 , V_104 , V_91 ) ;
#endif
#if ! F_6 ( V_108 ) && ! F_6 ( V_110 )
else if ( V_91 == V_18 )
V_106 = F_110 ( V_105 ) ;
#endif
else {
F_45 ( V_59 , L_43 ) ;
goto V_96;
}
V_96:
if ( V_105 != NULL )
F_89 ( V_105 ) ;
if ( V_106 == NULL )
F_45 ( V_59 , L_44 , V_104 ) ;
return ( V_106 ) ;
}
static T_11 * F_98 ( T_2 * V_59 , T_2 * V_105 , const char * V_1 ,
const char * V_104 , int V_91 )
{
T_11 * V_106 ;
T_13 * V_8 ;
T_12 * V_112 ;
const unsigned char * V_10 ;
int V_26 , V_6 ;
V_8 = F_111 () ;
V_106 = F_105 () ;
V_26 = 0 ;
if ( V_8 == NULL || V_106 == NULL )
goto error;
for (; ; ) {
if ( ! F_112 ( V_8 , V_26 + 1024 * 10 ) )
goto error;
V_6 = F_113 ( V_105 , & ( V_8 -> V_32 [ V_26 ] ) , 1024 * 10 ) ;
V_26 += V_6 ;
if ( V_6 == 0 )
break;
if ( V_6 < 0 ) {
F_45 ( V_59 , L_45 , V_104 , V_1 ) ;
goto error;
}
}
V_10 = ( unsigned char * ) V_8 -> V_32 ;
V_112 = F_114 ( NULL , & V_10 , ( long ) V_26 , NULL ,
( V_91 == V_109 ? 1 : 0 ) ) ;
if ( V_112 == NULL )
goto error;
F_115 ( V_8 ) ;
F_106 ( V_106 , V_112 ) ;
return V_106 ;
error:
F_115 ( V_8 ) ;
F_116 ( V_106 ) ;
return NULL ;
}
int F_117 ( unsigned long * V_114 , const char * V_9 )
{
static const T_14 V_115 [] = {
{ L_46 , V_116 , 0 } ,
{ L_47 , V_117 , 0 } ,
{ L_48 , V_118 , 0 } ,
{ L_49 , V_119 , 0 } ,
{ L_50 , V_120 , 0 } ,
{ L_51 , V_121 , 0 } ,
{ L_52 , V_122 , 0 } ,
{ L_53 , V_123 , 0 } ,
{ L_54 , V_124 , 0 } ,
{ L_55 , V_125 , 0 } ,
{ L_56 , V_126 , 0xffffffffL } ,
{ L_57 , V_127 , V_128 } ,
{ L_58 , V_129 , V_128 } ,
{ L_59 , V_130 , V_128 } ,
{ L_60 , V_131 , V_128 } ,
{ L_61 , V_132 , 0 } ,
{ L_62 , V_133 , V_134 } ,
{ L_63 , V_135 , V_134 } ,
{ L_64 , V_136 , V_134 } ,
{ L_65 , V_137 , 0 } ,
{ L_66 , V_138 , V_134 } ,
{ L_67 , V_139 , 0 } ,
{ L_68 , V_140 , 0 } ,
{ L_69 , V_141 , 0xffffffffL } ,
{ L_70 , V_142 , 0xffffffffL } ,
{ L_71 , V_143 , 0xffffffffL } ,
{ L_72 , V_143 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
return F_118 ( V_114 , V_9 , V_115 ) ;
}
int F_119 ( int * V_144 , const char * V_9 )
{
if ( ! strcasecmp ( V_9 , L_73 ) )
* V_144 = V_145 ;
else if ( ! strcasecmp ( V_9 , L_74 ) )
* V_144 = V_146 ;
else if ( ! strcasecmp ( V_9 , L_75 ) )
* V_144 = V_147 ;
else
return 0 ;
return 1 ;
}
int F_120 ( T_3 * V_36 , T_15 * V_148 , int V_144 )
{
F_60 ( V_149 ) * V_150 = NULL ;
V_149 * V_151 , * V_152 ;
T_16 * V_153 ;
int V_6 , V_154 , V_155 = 0 ;
if ( ! V_36 || ! V_148 || ( V_144 == V_145 ) )
return 1 ;
V_150 = F_121 ( V_148 ) ;
for ( V_6 = 0 ; V_6 < F_122 ( V_150 ) ; V_6 ++ ) {
V_151 = F_123 ( V_150 , V_6 ) ;
V_153 = F_124 ( V_151 ) ;
V_154 = F_125 ( V_36 , V_153 , - 1 ) ;
if ( V_154 != - 1 ) {
if ( V_144 == V_146 )
continue;
do {
V_152 = F_126 ( V_36 , V_154 ) ;
F_127 ( V_36 , V_154 ) ;
F_128 ( V_152 ) ;
V_154 = F_125 ( V_36 , V_153 , - 1 ) ;
} while ( V_154 != - 1 );
}
if ( ! F_129 ( V_36 , V_151 , - 1 ) )
goto V_96;
}
V_155 = 1 ;
V_96:
F_130 ( V_150 , F_128 ) ;
return V_155 ;
}
static int F_118 ( unsigned long * V_114 , const char * V_9 ,
const T_14 * V_156 )
{
F_60 ( V_75 ) * V_157 ;
V_75 * V_158 ;
int V_6 , V_155 = 1 ;
if ( ! V_9 )
return 0 ;
V_157 = F_131 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < F_64 ( V_157 ) ; V_6 ++ ) {
V_158 = F_65 ( V_157 , V_6 ) ;
if ( ! F_132 ( V_114 , V_158 -> V_79 , V_156 ) )
V_155 = 0 ;
}
F_133 ( V_157 , V_159 ) ;
return V_155 ;
}
static int F_132 ( unsigned long * V_114 , const char * V_9 ,
const T_14 * V_156 )
{
char V_160 ;
const T_14 * V_161 ;
V_160 = V_9 [ 0 ] ;
if ( V_160 == '-' ) {
V_160 = 0 ;
V_9 ++ ;
} else if ( V_160 == '+' ) {
V_160 = 1 ;
V_9 ++ ;
} else
V_160 = 1 ;
for ( V_161 = V_156 ; V_161 -> V_79 ; V_161 ++ ) {
if ( ! strcasecmp ( V_9 , V_161 -> V_79 ) ) {
* V_114 &= ~ V_161 -> V_162 ;
if ( V_160 )
* V_114 |= V_161 -> V_163 ;
else
* V_114 &= ~ V_161 -> V_163 ;
return 1 ;
}
}
return 0 ;
}
void F_134 ( T_2 * V_25 , const char * V_164 , T_17 * V_165 ,
unsigned long V_166 )
{
char * V_8 ;
char V_167 = 0 ;
int V_168 = 0 ;
if ( V_164 )
F_14 ( V_25 , V_164 ) ;
if ( ( V_166 & V_128 ) == V_131 ) {
V_167 = 1 ;
V_168 = 4 ;
}
if ( V_166 == V_126 ) {
V_8 = F_12 ( V_165 , 0 , 0 ) ;
F_14 ( V_25 , V_8 ) ;
F_14 ( V_25 , L_9 ) ;
F_2 ( V_8 ) ;
} else {
if ( V_167 )
F_14 ( V_25 , L_9 ) ;
F_135 ( V_25 , V_165 , V_168 , V_166 ) ;
F_14 ( V_25 , L_9 ) ;
}
}
T_18 * F_136 ( T_2 * V_169 , char * V_170 , char * V_171 )
{
T_18 * V_172 ;
T_19 * V_173 ;
if ( ! ( V_172 = F_137 () ) )
goto V_96;
V_173 = F_138 ( V_172 , F_139 () ) ;
if ( V_173 == NULL )
goto V_96;
if ( V_170 ) {
if ( ! F_140 ( V_173 , V_170 , V_174 ) ) {
F_45 ( V_169 , L_76 , V_170 ) ;
goto V_96;
}
} else
F_140 ( V_173 , NULL , V_175 ) ;
V_173 = F_138 ( V_172 , F_141 () ) ;
if ( V_173 == NULL )
goto V_96;
if ( V_171 ) {
if ( ! F_142 ( V_173 , V_171 , V_174 ) ) {
F_45 ( V_169 , L_77 , V_171 ) ;
goto V_96;
}
} else
F_142 ( V_173 , NULL , V_175 ) ;
F_62 () ;
return V_172 ;
V_96:
F_143 ( V_172 ) ;
return NULL ;
}
static T_9 * F_144 ( T_2 * V_59 , const char * V_176 , int V_177 )
{
T_9 * V_93 = F_145 ( L_78 ) ;
if ( V_93 ) {
if ( ! F_146 ( V_93 , L_79 , V_176 , 0 )
|| ! F_146 ( V_93 , L_80 , NULL , 0 ) ) {
F_147 ( V_93 ) ;
V_93 = NULL ;
}
}
return V_93 ;
}
T_9 * F_148 ( T_2 * V_59 , const char * V_176 , int V_177 )
{
T_9 * V_93 = NULL ;
if ( V_176 ) {
if ( strcmp ( V_176 , L_81 ) == 0 ) {
F_45 ( V_59 , L_82 ) ;
F_149 () ;
return NULL ;
}
if ( ( V_93 = F_145 ( V_176 ) ) == NULL
&& ( V_93 = F_144 ( V_59 , V_176 , V_177 ) ) == NULL ) {
F_45 ( V_59 , L_83 , V_176 ) ;
F_46 ( V_59 ) ;
return NULL ;
}
if ( V_177 ) {
F_150 ( V_93 , V_178 , 0 , V_59 , 0 ) ;
}
F_151 ( V_93 , L_84 , 0 , V_44 , 0 , 1 ) ;
if ( ! F_152 ( V_93 , V_179 ) ) {
F_45 ( V_59 , L_85 ) ;
F_46 ( V_59 ) ;
F_147 ( V_93 ) ;
return NULL ;
}
F_45 ( V_59 , L_86 , F_153 ( V_93 ) ) ;
F_147 ( V_93 ) ;
}
return V_93 ;
}
int F_154 ( T_2 * V_59 , T_6 * V_77 )
{
static int V_180 = 0 ;
if ( V_180 )
return 1 ;
V_180 = 1 ;
if ( ! V_77 )
V_77 = V_181 ;
if ( ! V_77 )
return 1 ;
F_155 () ;
if ( F_156 ( V_77 , NULL , 0 ) <= 0 ) {
F_45 ( V_59 , L_87 ) ;
F_46 ( V_59 ) ;
return 0 ;
}
return 1 ;
}
char * F_157 ()
{
const char * V_182 = F_158 () ;
T_20 V_7 ;
char * V_10 ;
V_7 = strlen ( V_182 ) + strlen ( V_183 ) + 2 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 == NULL )
return NULL ;
F_7 ( V_10 , V_182 , V_7 ) ;
#ifndef F_159
F_160 ( V_10 , L_88 , V_7 ) ;
#endif
F_160 ( V_10 , V_183 , V_7 ) ;
return V_10 ;
}
static unsigned long F_161 ( const T_21 * V_184 )
{
const char * V_27 ;
V_27 = V_184 [ V_185 ] ;
while ( * V_27 == '0' )
V_27 ++ ;
return ( F_162 ( V_27 ) ) ;
}
static int F_163 ( const T_21 * V_184 ,
const T_21 * V_186 )
{
const char * V_187 , * V_188 ;
for ( V_187 = V_184 [ V_185 ] ; * V_187 == '0' ; V_187 ++ ) ;
for ( V_188 = V_186 [ V_185 ] ; * V_188 == '0' ; V_188 ++ ) ;
return ( strcmp ( V_187 , V_188 ) ) ;
}
static int F_164 ( char * * V_184 )
{
return ( V_184 [ 0 ] [ 0 ] == 'V' ) ;
}
static unsigned long F_165 ( const T_21 * V_184 )
{
return ( F_162 ( V_184 [ V_189 ] ) ) ;
}
int F_166 ( const T_21 * V_184 , const T_21 * V_186 )
{
return ( strcmp ( V_184 [ V_189 ] , V_186 [ V_189 ] ) ) ;
}
int F_167 ( char * V_190 , char * V_191 , char * V_192 )
{
char V_8 [ 5 ] [ V_193 ] ;
int V_6 , V_194 ;
V_6 = strlen ( V_190 ) + strlen ( V_192 ) ;
V_194 = strlen ( V_190 ) + strlen ( V_191 ) ;
if ( V_6 > V_194 )
V_194 = V_6 ;
if ( V_194 + 1 >= V_193 ) {
F_45 ( V_58 , L_89 ) ;
goto V_59;
}
#ifndef F_159
V_194 = F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_90 , V_190 , V_191 ) ;
#else
V_194 = F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_91 , V_190 , V_191 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_90 , V_190 , V_192 ) ;
#else
V_194 = F_168 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_91 , V_190 , V_192 ) ;
#endif
#ifdef F_169
F_45 ( V_58 , L_92 ,
V_190 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_190 , V_8 [ 1 ] ) < 0 && V_195 != V_196
#ifdef F_170
&& V_195 != F_170
#endif
) {
F_45 ( V_58 ,
L_93 , V_190 , V_8 [ 1 ] ) ;
perror ( L_94 ) ;
goto V_59;
}
#ifdef F_169
F_45 ( V_58 , L_92 ,
V_8 [ 0 ] , V_190 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_190 ) < 0 ) {
F_45 ( V_58 ,
L_93 , V_8 [ 0 ] , V_190 ) ;
perror ( L_94 ) ;
rename ( V_8 [ 1 ] , V_190 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
int F_171 ( T_22 * V_186 , T_23 * V_197 )
{
T_22 * V_71 ;
int V_155 = 0 ;
if ( V_186 )
V_71 = V_186 ;
else
V_71 = F_172 () ;
if ( ! V_71 )
return 0 ;
if ( ! F_173 ( V_71 , V_198 , 0 , 0 ) )
goto error;
if ( V_197 && ! F_174 ( V_71 , V_197 ) )
goto error;
V_155 = 1 ;
error:
if ( ! V_186 )
F_175 ( V_71 ) ;
return V_155 ;
}
T_24 * F_176 ( char * V_199 , T_25 * V_200 )
{
T_24 * V_201 = NULL ;
T_26 * V_202 = NULL ;
T_2 * V_24 = F_53 ( F_78 () ) ;
T_6 * V_203 = NULL ;
char V_8 [ 1 ] [ V_193 ] ;
long V_204 = - 1 ;
if ( V_24 == NULL ) {
F_46 ( V_58 ) ;
goto V_59;
}
if ( F_82 ( V_24 , V_199 ) <= 0 ) {
perror ( V_199 ) ;
F_45 ( V_58 , L_95 , V_199 ) ;
goto V_59;
}
if ( ( V_202 = F_177 ( V_24 , V_205 ) ) == NULL )
goto V_59;
#ifndef F_159
F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_96 , V_199 ) ;
#else
F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_97 , V_199 ) ;
#endif
V_203 = F_178 ( NULL ) ;
if ( F_179 ( V_203 , V_8 [ 0 ] , & V_204 ) <= 0 ) {
if ( V_204 > 0 ) {
F_45 ( V_58 ,
L_98 ,
V_204 , V_8 [ 0 ] ) ;
goto V_59;
} else {
F_180 ( V_203 ) ;
V_203 = NULL ;
}
}
if ( ( V_201 = F_3 ( sizeof( T_24 ) ) ) == NULL ) {
fprintf ( V_206 , L_99 ) ;
goto V_59;
}
V_201 -> V_207 = V_202 ;
V_202 = NULL ;
if ( V_200 )
V_201 -> V_208 = * V_200 ;
else {
V_201 -> V_208 . V_209 = 1 ;
}
if ( V_203 ) {
char * V_10 = F_61 ( V_203 , NULL , L_100 ) ;
if ( V_10 ) {
#ifdef F_169
F_45 ( V_58 ,
L_101 , V_10 ) ;
#endif
V_201 -> V_208 . V_209 = F_181 ( V_10 , 1 ) ;
}
}
V_59:
if ( V_203 )
F_180 ( V_203 ) ;
if ( V_202 )
F_182 ( V_202 ) ;
if ( V_24 )
F_58 ( V_24 ) ;
return V_201 ;
}
int F_183 ( T_24 * V_207 )
{
if ( ! F_184 ( V_207 -> V_207 , V_185 , NULL ,
F_185 ( V_210 ) ,
F_186 ( V_210 ) ) ) {
F_45 ( V_58 ,
L_102 ,
V_207 -> V_207 -> error , V_207 -> V_207 -> V_60 , V_207 -> V_207 -> V_61 ) ;
return 0 ;
}
if ( V_207 -> V_208 . V_209
&& ! F_184 ( V_207 -> V_207 , V_189 , F_164 ,
F_185 ( V_211 ) ,
F_186 ( V_211 ) ) ) {
F_45 ( V_58 , L_103 ,
V_207 -> V_207 -> error , V_207 -> V_207 -> V_60 , V_207 -> V_207 -> V_61 ) ;
return 0 ;
}
return 1 ;
}
int F_187 ( const char * V_199 , const char * V_212 , T_24 * V_207 )
{
char V_8 [ 3 ] [ V_193 ] ;
T_2 * V_25 = F_53 ( F_78 () ) ;
int V_194 ;
if ( V_25 == NULL ) {
F_46 ( V_58 ) ;
goto V_59;
}
V_194 = strlen ( V_199 ) + strlen ( V_212 ) ;
if ( V_194 + 6 >= V_193 ) {
F_45 ( V_58 , L_89 ) ;
goto V_59;
}
#ifndef F_159
V_194 = F_168 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_96 , V_199 ) ;
#else
V_194 = F_168 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_97 , V_199 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_104 , V_199 , V_212 ) ;
#else
V_194 = F_168 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_105 , V_199 , V_212 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_90 , V_199 , V_212 ) ;
#else
V_194 = F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_91 , V_199 , V_212 ) ;
#endif
#ifdef F_169
F_45 ( V_58 , L_106 , V_8 [ 0 ] ) ;
#endif
if ( F_188 ( V_25 , V_8 [ 0 ] ) <= 0 ) {
perror ( V_199 ) ;
F_45 ( V_58 , L_95 , V_199 ) ;
goto V_59;
}
V_194 = F_189 ( V_25 , V_207 -> V_207 ) ;
if ( V_194 <= 0 )
goto V_59;
F_89 ( V_25 ) ;
V_25 = F_53 ( F_78 () ) ;
#ifdef F_169
F_45 ( V_58 , L_106 , V_8 [ 1 ] ) ;
#endif
if ( F_188 ( V_25 , V_8 [ 1 ] ) <= 0 ) {
perror ( V_8 [ 2 ] ) ;
F_45 ( V_58 , L_95 , V_8 [ 2 ] ) ;
goto V_59;
}
F_45 ( V_25 , L_107 ,
V_207 -> V_208 . V_209 ? L_108 : L_109 ) ;
F_89 ( V_25 ) ;
return 1 ;
V_59:
return 0 ;
}
int F_190 ( const char * V_199 , const char * V_191 ,
const char * V_192 )
{
char V_8 [ 5 ] [ V_193 ] ;
int V_6 , V_194 ;
V_6 = strlen ( V_199 ) + strlen ( V_192 ) ;
V_194 = strlen ( V_199 ) + strlen ( V_191 ) ;
if ( V_6 > V_194 )
V_194 = V_6 ;
if ( V_194 + 6 >= V_193 ) {
F_45 ( V_58 , L_89 ) ;
goto V_59;
}
#ifndef F_159
V_194 = F_168 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_96 , V_199 ) ;
#else
V_194 = F_168 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_97 , V_199 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_104 , V_199 , V_191 ) ;
#else
V_194 = F_168 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_105 , V_199 , V_191 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_90 , V_199 , V_191 ) ;
#else
V_194 = F_168 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_91 , V_199 , V_191 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_90 , V_199 , V_192 ) ;
#else
V_194 = F_168 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_91 , V_199 , V_192 ) ;
#endif
#ifndef F_159
V_194 = F_168 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_104 , V_199 , V_192 ) ;
#else
V_194 = F_168 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_105 , V_199 , V_192 ) ;
#endif
#ifdef F_169
F_45 ( V_58 , L_92 , V_199 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_199 , V_8 [ 1 ] ) < 0 && V_195 != V_196
#ifdef F_170
&& V_195 != F_170
#endif
) {
F_45 ( V_58 , L_93 , V_199 , V_8 [ 1 ] ) ;
perror ( L_94 ) ;
goto V_59;
}
#ifdef F_169
F_45 ( V_58 , L_92 , V_8 [ 0 ] , V_199 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_199 ) < 0 ) {
F_45 ( V_58 , L_93 , V_8 [ 0 ] , V_199 ) ;
perror ( L_94 ) ;
rename ( V_8 [ 1 ] , V_199 ) ;
goto V_59;
}
#ifdef F_169
F_45 ( V_58 , L_92 , V_8 [ 4 ] , V_8 [ 3 ] ) ;
#endif
if ( rename ( V_8 [ 4 ] , V_8 [ 3 ] ) < 0 && V_195 != V_196
#ifdef F_170
&& V_195 != F_170
#endif
) {
F_45 ( V_58 , L_93 , V_8 [ 4 ] , V_8 [ 3 ] ) ;
perror ( L_94 ) ;
rename ( V_199 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_199 ) ;
goto V_59;
}
#ifdef F_169
F_45 ( V_58 , L_92 , V_8 [ 2 ] , V_8 [ 4 ] ) ;
#endif
if ( rename ( V_8 [ 2 ] , V_8 [ 4 ] ) < 0 ) {
F_45 ( V_58 , L_93 , V_8 [ 2 ] , V_8 [ 4 ] ) ;
perror ( L_94 ) ;
rename ( V_8 [ 3 ] , V_8 [ 4 ] ) ;
rename ( V_199 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_199 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
void F_191 ( T_24 * V_207 )
{
if ( V_207 ) {
if ( V_207 -> V_207 )
F_182 ( V_207 -> V_207 ) ;
F_2 ( V_207 ) ;
}
}
int F_181 ( const char * V_213 , int V_214 )
{
int V_155 = V_214 ;
if ( V_213 ) {
switch ( * V_213 ) {
case 'f' :
case 'F' :
case 'n' :
case 'N' :
case '0' :
V_155 = 0 ;
break;
case 't' :
case 'T' :
case 'y' :
case 'Y' :
case '1' :
V_155 = 1 ;
break;
default:
V_155 = V_214 ;
break;
}
}
return V_155 ;
}
T_17 * F_192 ( char * V_215 , long V_216 , int V_217 )
{
T_20 V_218 = strlen ( V_215 ) + 1 ;
char * V_8 = F_3 ( V_218 ) ;
T_20 V_219 = V_218 / 2 + 1 ;
char * * V_220 = F_3 ( V_219 * sizeof( char * ) ) ;
char * * V_221 = F_3 ( V_219 * sizeof( char * ) ) ;
int * V_222 = F_3 ( V_219 * sizeof( int ) ) ;
char * V_223 = V_215 , * V_169 = V_8 ;
int V_6 , V_224 = 0 ;
T_17 * V_27 = NULL ;
int V_225 ;
if ( ! V_8 || ! V_220 || ! V_221 || ! V_222 ) {
F_45 ( V_58 , L_110 ) ;
goto error;
}
if ( * V_215 != '/' ) {
F_45 ( V_58 , L_111 ) ;
goto error;
}
V_223 ++ ;
V_222 [ V_224 ] = 0 ;
while ( * V_223 ) {
V_220 [ V_224 ] = V_169 ;
while ( * V_223 ) {
if ( * V_223 == '\\' ) {
if ( * ++ V_223 )
* V_169 ++ = * V_223 ++ ;
else {
F_45 ( V_58 ,
L_112 ) ;
goto error;
}
} else if ( * V_223 == '=' ) {
V_223 ++ ;
* V_169 ++ = '\0' ;
break;
} else
* V_169 ++ = * V_223 ++ ;
}
if ( ! * V_223 ) {
F_45 ( V_58 ,
L_113 ,
V_224 ) ;
goto error;
}
V_221 [ V_224 ] = V_169 ;
while ( * V_223 ) {
if ( * V_223 == '\\' ) {
if ( * ++ V_223 )
* V_169 ++ = * V_223 ++ ;
else {
F_45 ( V_58 ,
L_112 ) ;
goto error;
}
} else if ( * V_223 == '/' ) {
V_223 ++ ;
V_222 [ V_224 + 1 ] = 0 ;
break;
} else if ( * V_223 == '+' && V_217 ) {
V_223 ++ ;
V_222 [ V_224 + 1 ] = - 1 ;
break;
} else
* V_169 ++ = * V_223 ++ ;
}
* V_169 ++ = '\0' ;
V_224 ++ ;
}
if ( ! ( V_27 = F_193 () ) )
goto error;
for ( V_6 = 0 ; V_6 < V_224 ; V_6 ++ ) {
if ( ( V_225 = F_194 ( V_220 [ V_6 ] ) ) == V_80 ) {
F_45 ( V_58 ,
L_114 ,
V_220 [ V_6 ] ) ;
continue;
}
if ( ! * V_221 [ V_6 ] ) {
F_45 ( V_58 ,
L_115 ,
V_220 [ V_6 ] ) ;
continue;
}
if ( ! F_195
( V_27 , V_225 , V_216 , ( unsigned char * ) V_221 [ V_6 ] , - 1 , - 1 , V_222 [ V_6 ] ) )
goto error;
}
F_2 ( V_221 ) ;
F_2 ( V_220 ) ;
F_2 ( V_8 ) ;
F_2 ( V_222 ) ;
return V_27 ;
error:
F_196 ( V_27 ) ;
if ( V_221 )
F_2 ( V_221 ) ;
if ( V_220 )
F_2 ( V_220 ) ;
if ( V_222 )
F_2 ( V_222 ) ;
if ( V_8 )
F_2 ( V_8 ) ;
return NULL ;
}
int F_197 ( char * * * V_226 , int * V_227 ,
int * V_228 , T_2 * V_59 , T_27 * * V_229 )
{
T_16 * V_230 = NULL ;
unsigned long V_114 = 0 ;
int V_6 ;
int V_231 = 0 , V_232 = - 1 ;
char * * V_233 = * V_226 ;
char * V_9 = * * V_226 , * V_234 = ( * V_226 ) [ 1 ] ;
T_28 V_235 = 0 ;
char * V_236 = NULL ;
char * V_237 = NULL ;
char * V_238 = NULL ;
if ( ! strcmp ( V_9 , L_116 ) ) {
if ( ! V_234 )
* V_228 = 1 ;
else {
V_230 = F_198 ( V_234 , 0 ) ;
if ( ! V_230 ) {
F_45 ( V_59 , L_117 , V_234 ) ;
* V_228 = 1 ;
}
}
( * V_226 ) ++ ;
} else if ( strcmp ( V_9 , L_118 ) == 0 ) {
T_29 * V_239 ;
if ( ! V_234 )
* V_228 = 1 ;
else {
V_6 = F_199 ( V_234 ) ;
if ( V_6 < 0 ) {
F_45 ( V_59 , L_119 ) ;
* V_228 = 1 ;
} else {
V_239 = F_200 ( V_6 ) ;
V_231 = F_201 ( V_239 ) ;
}
}
( * V_226 ) ++ ;
} else if ( strcmp ( V_9 , L_120 ) == 0 ) {
if ( ! V_234 )
* V_228 = 1 ;
else {
V_232 = atoi ( V_234 ) ;
if ( V_232 < 0 ) {
F_45 ( V_59 , L_121 ) ;
* V_228 = 1 ;
}
}
( * V_226 ) ++ ;
} else if ( strcmp ( V_9 , L_122 ) == 0 ) {
if ( ! V_234 )
* V_228 = 1 ;
else {
long V_240 ;
if ( sscanf ( V_234 , L_123 , & V_240 ) != 1 ) {
F_45 ( V_58 , L_124 , V_234 ) ;
* V_228 = 1 ;
}
V_235 = ( T_28 ) V_240 ;
}
( * V_226 ) ++ ;
} else if ( strcmp ( V_9 , L_125 ) == 0 ) {
if ( ! V_234 )
* V_228 = 1 ;
V_236 = V_234 ;
( * V_226 ) ++ ;
} else if ( strcmp ( V_9 , L_126 ) == 0 ) {
if ( ! V_234 )
* V_228 = 1 ;
V_237 = V_234 ;
( * V_226 ) ++ ;
} else if ( strcmp ( V_9 , L_127 ) == 0 ) {
if ( ! V_234 )
* V_228 = 1 ;
V_238 = V_234 ;
( * V_226 ) ++ ;
} else if ( ! strcmp ( V_9 , L_128 ) )
V_114 |= V_241 ;
else if ( ! strcmp ( V_9 , L_129 ) )
V_114 |= V_242 ;
else if ( ! strcmp ( V_9 , L_130 ) )
V_114 |= V_243 ;
else if ( ! strcmp ( V_9 , L_131 ) )
V_114 |= V_243 | V_244 ;
else if ( ! strcmp ( V_9 , L_132 ) )
V_114 |= V_245 ;
else if ( ! strcmp ( V_9 , L_133 ) )
V_114 |= V_246 ;
else if ( ! strcmp ( V_9 , L_134 ) )
V_114 |= V_247 ;
else if ( ! strcmp ( V_9 , L_135 ) )
V_114 |= V_248 ;
else if ( ! strcmp ( V_9 , L_136 ) )
V_114 |= V_249 ;
else if ( ! strcmp ( V_9 , L_137 ) )
V_114 |= V_250 ;
else if ( ! strcmp ( V_9 , L_138 ) )
V_114 |= V_251 ;
else if ( ! strcmp ( V_9 , L_139 ) )
V_114 |= V_252 ;
else if ( ! strcmp ( V_9 , L_140 ) )
V_114 |= V_253 ;
else if ( ! strcmp ( V_9 , L_141 ) )
V_114 |= V_254 ;
else if ( ! strcmp ( V_9 , L_142 ) )
V_114 |= V_255 ;
else if ( ! strcmp ( V_9 , L_143 ) )
V_114 |= V_256 ;
else if ( ! strcmp ( V_9 , L_144 ) )
V_114 |= V_257 ;
else if ( ! strcmp ( V_9 , L_145 ) )
V_114 |= V_258 ;
else
return 0 ;
if ( * V_228 ) {
if ( * V_229 )
F_202 ( * V_229 ) ;
* V_229 = NULL ;
goto V_96;
}
if ( ! * V_229 && ! ( * V_229 = F_203 () ) ) {
* V_228 = 1 ;
goto V_96;
}
if ( V_230 )
F_204 ( * V_229 , V_230 ) ;
if ( V_114 )
F_205 ( * V_229 , V_114 ) ;
if ( V_231 )
F_206 ( * V_229 , V_231 ) ;
if ( V_232 >= 0 )
F_207 ( * V_229 , V_232 ) ;
if ( V_235 )
F_208 ( * V_229 , V_235 ) ;
if ( V_236 && ! F_209 ( * V_229 , V_236 , 0 ) )
* V_228 = 1 ;
if ( V_237 && ! F_210 ( * V_229 , V_237 , 0 ) )
* V_228 = 1 ;
if ( V_238 && ! F_211 ( * V_229 , V_238 ) )
* V_228 = 1 ;
V_96:
( * V_226 ) ++ ;
if ( V_227 )
* V_227 -= * V_226 - V_233 ;
return 1 ;
}
int F_212 ( unsigned char * * V_25 , int V_259 , T_2 * V_24 )
{
T_2 * V_260 ;
int V_7 , V_155 ;
unsigned char V_261 [ 1024 ] ;
V_260 = F_53 ( F_213 () ) ;
if ( ! V_260 )
return - 1 ;
for (; ; ) {
if ( ( V_259 != - 1 ) && V_259 < 1024 )
V_7 = V_259 ;
else
V_7 = 1024 ;
V_7 = F_113 ( V_24 , V_261 , V_7 ) ;
if ( V_7 <= 0 )
break;
if ( F_214 ( V_260 , V_261 , V_7 ) != V_7 ) {
F_89 ( V_260 ) ;
return - 1 ;
}
V_259 -= V_7 ;
if ( V_259 == 0 )
break;
}
V_155 = F_215 ( V_260 , ( char * * ) V_25 ) ;
F_216 ( V_260 , V_262 ) ;
F_89 ( V_260 ) ;
return V_155 ;
}
int F_217 ( T_30 * V_263 , char * V_78 )
{
int V_90 ;
char * V_264 , * V_265 = NULL ;
V_264 = F_50 ( V_78 ) ;
if ( ! V_264 )
return - 1 ;
V_265 = strchr ( V_264 , ':' ) ;
if ( V_265 ) {
* V_265 = 0 ;
V_265 ++ ;
}
V_90 = F_218 ( V_263 , V_264 , V_265 ) ;
F_2 ( V_264 ) ;
return V_90 ;
}
void F_219 ( T_2 * V_25 , T_31 * V_263 )
{
T_32 * V_266 ;
int V_267 ;
int V_268 = 0 ;
if ( V_25 == NULL ) {
V_25 = F_56 ( V_206 , V_72 ) ;
V_268 = 1 ;
}
V_266 = F_220 ( V_263 ) ;
V_267 = F_221 ( V_263 ) ;
F_45 ( V_25 , L_146 ,
V_267 ? L_147 : L_148 ) ;
F_222 ( V_25 , L_149 , F_223 ( V_266 ) ) ;
F_222 ( V_25 , L_150 , F_224 ( V_266 ) ) ;
if ( V_268 )
F_89 ( V_25 ) ;
}
static T_33 * F_225 ( const char * V_269 , const char * V_270 ,
const char * V_271 )
{
T_22 * V_10 = NULL ;
T_22 * V_272 = NULL ;
T_22 * V_29 = NULL ;
T_22 * V_273 = F_172 () ;
T_33 * V_263 ;
F_226 ( & V_10 ,
L_151 ) ;
V_272 = F_172 () ;
F_227 ( V_272 , 2 ) ;
V_29 = F_172 () ;
F_228 ( V_29 , V_10 ) ;
F_229 ( ( const unsigned char * ) V_271 , strlen ( V_271 ) , V_273 ) ;
V_263 = F_230 ( V_269 , V_270 , V_10 , V_272 , V_29 , V_273 ) ;
F_175 ( V_273 ) ;
F_175 ( V_29 ) ;
F_175 ( V_272 ) ;
F_175 ( V_10 ) ;
return V_263 ;
}
static void F_231 ( T_2 * V_274 , const T_34 * V_10 )
{
F_232 ( V_274 , V_10 -> V_275 ) ;
F_14 ( V_274 , L_9 ) ;
F_232 ( V_274 , V_10 -> V_276 . V_277 ) ;
F_14 ( V_274 , L_9 ) ;
F_232 ( V_274 , V_10 -> V_276 . V_186 ) ;
F_14 ( V_274 , L_9 ) ;
}
static void F_233 ( T_2 * V_278 , T_33 * V_263 )
{
T_35 V_279 ;
F_234 ( & V_279 ) ;
F_235 ( & V_279 , V_263 ) ;
F_231 ( V_278 , & V_279 . V_280 ) ;
F_231 ( V_278 , & V_279 . V_281 ) ;
( void ) F_236 ( V_278 ) ;
F_237 ( & V_279 ) ;
}
static void F_238 ( T_2 * V_278 , T_33 * V_263 )
{
T_36 V_282 ;
F_239 ( & V_282 ) ;
F_240 ( & V_282 , V_263 ) ;
F_231 ( V_278 , & V_282 ) ;
( void ) F_236 ( V_278 ) ;
F_241 ( & V_282 ) ;
}
static void F_242 ( T_2 * V_278 , T_33 * V_263 )
{
T_37 V_283 ;
F_243 ( & V_283 ) ;
F_244 ( & V_283 , V_263 ) ;
F_214 ( V_278 , V_283 . V_284 , sizeof V_283 . V_284 ) ;
( void ) F_236 ( V_278 ) ;
F_245 ( & V_283 ) ;
}
static void F_246 ( T_2 * V_278 , T_33 * V_263 )
{
T_38 V_285 ;
F_247 ( & V_285 ) ;
F_248 ( & V_285 , V_263 ) ;
F_214 ( V_278 , V_285 . V_286 , sizeof V_285 . V_286 ) ;
( void ) F_236 ( V_278 ) ;
F_249 ( & V_285 ) ;
}
static void F_250 ( T_22 * * V_287 , T_2 * V_278 )
{
char V_8 [ 10240 ] ;
int V_288 ;
V_288 = F_57 ( V_278 , V_8 , sizeof V_8 ) ;
assert ( V_288 > 0 ) ;
assert ( V_8 [ V_288 - 1 ] == '\n' ) ;
V_8 [ V_288 - 1 ] = '\0' ;
F_226 ( V_287 , V_8 ) ;
}
static void F_251 ( T_34 * V_10 , T_2 * V_278 )
{
F_250 ( & V_10 -> V_275 , V_278 ) ;
F_250 ( & V_10 -> V_276 . V_277 , V_278 ) ;
F_250 ( & V_10 -> V_276 . V_186 , V_278 ) ;
}
static void F_252 ( T_33 * V_263 , T_2 * V_278 )
{
T_35 V_279 ;
F_234 ( & V_279 ) ;
F_251 ( & V_279 . V_280 , V_278 ) ;
F_251 ( & V_279 . V_281 , V_278 ) ;
if ( ! F_253 ( V_263 , & V_279 ) ) {
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_237 ( & V_279 ) ;
}
static void F_254 ( T_33 * V_263 , T_2 * V_278 )
{
T_36 V_282 ;
F_239 ( & V_282 ) ;
F_251 ( & V_282 , V_278 ) ;
if ( ! F_255 ( V_263 , & V_282 ) ) {
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_241 ( & V_282 ) ;
}
static void F_256 ( T_33 * V_263 , T_2 * V_278 )
{
T_37 V_283 ;
int V_288 ;
F_243 ( & V_283 ) ;
V_288 = F_113 ( V_278 , V_283 . V_284 , sizeof V_283 . V_284 ) ;
assert ( V_288 == sizeof V_283 . V_284 ) ;
if ( ! F_257 ( V_263 , & V_283 ) ) {
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_245 ( & V_283 ) ;
}
static void F_258 ( T_33 * V_263 , T_2 * V_278 )
{
T_38 V_285 ;
int V_288 ;
F_247 ( & V_285 ) ;
V_288 = F_113 ( V_278 , V_285 . V_286 , sizeof V_285 . V_286 ) ;
assert ( V_288 == sizeof V_285 . V_286 ) ;
if ( ! F_259 ( V_263 , & V_285 ) ) {
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_249 ( & V_285 ) ;
}
void F_260 ( T_2 * V_25 , T_2 * V_274 , const char * V_271 )
{
T_33 * V_263 ;
T_2 * V_278 ;
F_14 ( V_25 , L_152 ) ;
V_263 = F_225 ( L_153 , L_154 , V_271 ) ;
V_278 = F_53 ( F_54 () ) ;
F_55 ( V_278 , V_274 ) ;
F_233 ( V_278 , V_263 ) ;
F_252 ( V_263 , V_278 ) ;
F_238 ( V_278 , V_263 ) ;
F_254 ( V_263 , V_278 ) ;
F_242 ( V_278 , V_263 ) ;
F_258 ( V_263 , V_278 ) ;
F_14 ( V_25 , L_155 ) ;
if ( V_289 )
F_2 ( V_289 ) ;
V_289 = F_261 ( F_262 ( V_263 ) ) ;
F_263 ( V_278 ) ;
F_89 ( V_278 ) ;
F_264 ( V_263 ) ;
}
void F_265 ( T_2 * V_25 , T_2 * V_274 , const char * V_271 )
{
T_33 * V_263 ;
T_2 * V_278 ;
F_14 ( V_25 , L_152 ) ;
V_263 = F_225 ( L_154 , L_153 , V_271 ) ;
V_278 = F_53 ( F_54 () ) ;
F_55 ( V_278 , V_274 ) ;
F_252 ( V_263 , V_278 ) ;
F_233 ( V_278 , V_263 ) ;
F_254 ( V_263 , V_278 ) ;
F_238 ( V_278 , V_263 ) ;
F_256 ( V_263 , V_278 ) ;
F_246 ( V_278 , V_263 ) ;
F_14 ( V_25 , L_155 ) ;
if ( V_289 )
F_2 ( V_289 ) ;
V_289 = F_261 ( F_262 ( V_263 ) ) ;
F_263 ( V_278 ) ;
F_89 ( V_278 ) ;
F_264 ( V_263 ) ;
}
unsigned char * F_266 ( unsigned short * V_290 , const char * V_24 )
{
T_20 V_7 ;
unsigned char * V_25 ;
T_20 V_6 , V_291 = 0 ;
V_7 = strlen ( V_24 ) ;
if ( V_7 >= 65535 )
return NULL ;
V_25 = F_3 ( strlen ( V_24 ) + 1 ) ;
if ( ! V_25 )
return NULL ;
for ( V_6 = 0 ; V_6 <= V_7 ; ++ V_6 ) {
if ( V_6 == V_7 || V_24 [ V_6 ] == ',' ) {
if ( V_6 - V_291 > 255 ) {
F_2 ( V_25 ) ;
return NULL ;
}
V_25 [ V_291 ] = V_6 - V_291 ;
V_291 = V_6 + 1 ;
} else
V_25 [ V_6 + 1 ] = V_24 [ V_6 ] ;
}
* V_290 = V_7 + 1 ;
return V_25 ;
}
void F_267 ( T_2 * V_87 , T_3 * V_36 ,
const char * V_292 ,
const char * V_293 , const char * V_294 )
{
if ( V_36 == NULL )
return;
if ( V_292 ) {
F_45 ( V_87 , L_156 ,
V_292 , F_268 ( V_36 , V_292 , 0 , 0 , NULL )
? L_157 : L_158 ) ;
}
if ( V_293 ) {
F_45 ( V_87 , L_159 ,
V_293 , F_269 ( V_36 , V_293 , 0 ,
0 ) ? L_157 : L_158 ) ;
}
if ( V_294 ) {
F_45 ( V_87 , L_160 ,
V_294 , F_270 ( V_36 , V_294 , 0 ) ? L_157 : L_158 ) ;
}
}
static const char * F_271 ( T_39 * V_295 )
{
T_40 * V_296 ;
T_41 * V_297 ;
int V_6 , V_298 ;
T_42 * V_299 ;
if ( ! V_295 -> V_300 || V_295 -> V_300 -> type != 0 )
return NULL ;
V_296 = V_295 -> V_300 -> V_79 . V_301 ;
for ( V_6 = 0 ; V_6 < F_272 ( V_296 ) ; V_6 ++ ) {
V_297 = F_273 ( V_296 , V_6 ) ;
V_299 = F_274 ( V_297 , & V_298 ) ;
if ( V_298 == V_302 && F_275 ( V_299 ) > 6 ) {
char * V_303 = ( char * ) F_276 ( V_299 ) ;
if ( ! strncmp ( V_303 , L_161 , 7 ) )
return V_303 ;
}
}
return NULL ;
}
static int F_277 ( const char * V_304 , const char * V_305 )
{
T_43 * V_306 = NULL , * V_307 ;
T_44 V_59 ;
int V_155 = 0 ;
if ( sizeof( T_43 ) == 1 ) {
V_306 = ( T_43 * ) V_304 ;
V_307 = ( T_43 * ) V_305 ;
} else {
T_20 V_6 , V_308 = strlen ( V_304 ) + 1 , V_34 = strlen ( V_305 ) + 1 ;
V_306 = ( T_43 * ) malloc ( sizeof( T_43 ) * ( V_308 + V_34 ) ) ;
if ( V_306 == NULL )
goto V_59;
V_307 = V_306 + V_308 ;
# if ! F_6 ( V_309 ) || V_309 >= 101
if ( ! F_278 ( V_310 , 0 , V_304 , V_308 , ( V_311 * ) V_306 , V_308 ) )
# endif
for ( V_6 = 0 ; V_6 < V_308 ; V_6 ++ )
V_306 [ V_6 ] = ( T_43 ) V_304 [ V_6 ] ;
# if ! F_6 ( V_309 ) || V_309 >= 101
if ( ! F_278 ( V_310 , 0 , V_305 , V_34 , ( V_311 * ) V_307 , V_34 ) )
# endif
for ( V_6 = 0 ; V_6 < V_34 ; V_6 ++ )
V_307 [ V_6 ] = ( T_43 ) V_305 [ V_6 ] ;
}
if ( F_279 ( V_306 , V_307 ) )
goto V_51;
V_59 = F_280 () ;
if ( V_59 == V_312 || V_59 == V_313 ) {
if ( F_281 ( V_307 ) && F_279 ( V_306 , V_307 ) )
goto V_51;
V_59 = F_280 () ;
}
if ( V_59 == V_314 || V_59 == V_315 )
V_195 = V_196 ;
else if ( V_59 == V_316 )
V_195 = V_317 ;
else
V_195 = V_318 ;
V_59:
V_155 = - 1 ;
V_51:
if ( V_306 != NULL && V_306 != ( T_43 * ) V_304 )
free ( V_306 ) ;
return V_155 ;
}
double F_282 ( int V_319 , int V_320 )
{
T_45 V_321 ;
double V_155 = 0 ;
static T_46 V_322 ;
static int V_323 = 1 ;
# ifdef F_283
static T_47 V_324 = NULL ;
if ( V_324 == NULL ) {
if ( F_284 () )
V_324 = F_285 ( V_325 , FALSE ,
F_286 () ) ;
if ( V_324 == NULL )
V_324 = ( T_47 ) - 1 ;
}
if ( V_320 && V_324 != ( T_47 ) - 1 ) {
T_45 V_326 ;
F_287 ( V_324 , & V_326 , & V_326 , & V_326 , & V_321 ) ;
} else
# endif
{
T_48 V_327 ;
if ( V_320 && V_323 ) {
F_45 ( V_58 , L_162
L_163 ) ;
V_323 = 0 ;
}
F_288 ( & V_327 ) ;
F_289 ( & V_327 , & V_321 ) ;
}
if ( V_319 == V_328 ) {
V_322 . V_329 . V_330 = V_321 . V_331 ;
V_322 . V_329 . V_332 = V_321 . V_333 ;
} else {
T_46 V_334 ;
V_334 . V_329 . V_330 = V_321 . V_331 ;
V_334 . V_329 . V_332 = V_321 . V_333 ;
V_155 = ( V_335 ) ( V_334 . V_336 - V_322 . V_336 ) * 1e-7 ;
}
return ( V_155 ) ;
}
double F_282 ( int V_319 , int V_320 )
{
double V_155 = 0 ;
static T_49 V_322 ;
static int V_323 = 1 ;
if ( V_320 && V_323 ) {
F_45 ( V_58 , L_162
L_163 ) ;
V_323 = 0 ;
}
if ( V_319 == V_328 )
V_322 = clock () ;
else
V_155 = ( clock () - V_322 ) / ( double ) V_337 ;
return ( V_155 ) ;
}
double F_282 ( int V_319 , int V_320 )
{
double V_155 = 0 ;
# ifdef F_290
static struct V_338 V_322 ;
struct V_338 V_321 ;
# else
static unsigned long V_322 ;
unsigned long V_321 ;
# endif
static int V_323 = 1 ;
if ( V_320 && V_323 ) {
F_45 ( V_58 , L_162
L_163 ) ;
V_323 = 0 ;
}
# ifdef F_290
F_291 ( F_290 , & V_321 ) ;
if ( V_319 == V_328 )
V_322 = V_321 ;
else
V_155 = ( ( V_321 . V_339 + V_321 . V_340 * 1e-9 )
- ( V_322 . V_339 + V_322 . V_340 * 1e-9 ) ) ;
# else
V_321 = F_292 () ;
if ( V_319 == V_328 )
V_322 = V_321 ;
else
V_155 = ( V_321 - V_322 ) / ( double ) F_293 () ;
# endif
return ( V_155 ) ;
}
double F_282 ( int V_319 , int V_320 )
{
static T_49 V_322 ;
double V_155 = 0 ;
T_49 V_321 ;
# ifdef F_294
struct V_341 V_342 ;
V_321 = F_295 ( & V_342 ) ;
if ( V_320 )
V_321 = V_342 . V_343 ;
# else
if ( V_320 )
V_321 = clock () ;
else {
struct V_344 V_345 ;
F_296 ( & V_345 , NULL ) ;
V_321 = ( T_49 ) ( ( unsigned long long ) V_345 . V_339 * V_346 +
( unsigned long long ) V_345 . V_347 * ( 1000000 / V_346 )
) ;
}
# endif
if ( V_319 == V_328 )
V_322 = V_321 ;
else
V_155 = ( V_321 - V_322 ) / ( double ) ( V_346 ) ;
return ( V_155 ) ;
}
double F_282 ( int V_319 , int V_320 )
{
double V_155 = 0 ;
struct V_341 V_342 ;
T_49 V_321 = F_295 ( & V_342 ) ;
static T_49 V_322 ;
if ( V_320 )
V_321 = V_342 . V_343 ;
if ( V_319 == V_328 )
V_322 = V_321 ;
else {
long int V_348 = F_297 ( V_349 ) ;
V_155 = ( V_321 - V_322 ) / ( double ) V_348 ;
}
return ( V_155 ) ;
}
double F_282 ( int V_319 , int V_320 )
{
double V_155 = 0 ;
struct V_350 V_342 ;
struct V_344 V_321 ;
static struct V_344 V_322 ;
if ( V_320 )
F_298 ( V_351 , & V_342 ) , V_321 = V_342 . V_352 ;
else
F_296 ( & V_321 , NULL ) ;
if ( V_319 == V_328 )
V_322 = V_321 ;
else
V_155 = ( ( V_321 . V_339 + V_321 . V_347 * 1e-6 )
- ( V_322 . V_339 + V_322 . V_347 * 1e-6 ) ) ;
return V_155 ;
}
int F_299 ( const char * V_79 )
{
T_47 V_353 ;
T_50 V_354 ;
# if F_6 ( V_355 ) || F_6 ( V_356 )
T_20 V_6 , V_357 = strlen ( V_79 ) + 1 ;
if ( V_357 > sizeof( V_354 . V_358 ) / sizeof( V_354 . V_358 [ 0 ] ) )
return - 1 ;
# if ! F_6 ( V_309 ) || V_309 >= 101
if ( ! F_278
( V_310 , 0 , V_79 , V_357 , V_354 . V_358 , V_357 ) )
# endif
for ( V_6 = 0 ; V_6 < V_357 ; V_6 ++ )
V_354 . V_358 [ V_6 ] = ( V_311 ) V_79 [ V_6 ] ;
V_353 = F_300 ( V_354 . V_358 , & V_354 ) ;
# else
V_353 = F_300 ( V_79 , & V_354 ) ;
# endif
if ( V_353 == V_359 )
return - 1 ;
F_301 ( V_353 ) ;
return ( ( V_354 . V_360 & V_361 ) != 0 ) ;
}
int F_299 ( const char * V_79 )
{
# if F_6 ( V_362 )
struct V_363 V_364 ;
if ( V_363 ( V_79 , & V_364 ) == 0 )
return V_362 ( V_364 . V_365 ) ;
else
return - 1 ;
# else
return - 1 ;
# endif
}
int F_302 ( void * V_8 , int V_366 )
{
T_44 V_27 ;
if ( F_303 ( F_304 ( V_367 ) , V_8 , V_366 , & V_27 , NULL ) )
return ( V_27 ) ;
else
return ( - 1 ) ;
}
int F_302 ( void * V_8 , int V_366 )
{
return F_305 ( fileno ( V_73 ) , V_8 , V_366 ) ;
}
int F_306 ( const void * V_8 , int V_366 )
{
T_44 V_27 ;
if ( F_307 ( F_304 ( V_368 ) , V_8 , V_366 , & V_27 , NULL ) )
return ( V_27 ) ;
else
return ( - 1 ) ;
}
int F_306 ( const void * V_8 , int V_366 )
{
return F_308 ( fileno ( stdout ) , V_8 , V_366 ) ;
}
