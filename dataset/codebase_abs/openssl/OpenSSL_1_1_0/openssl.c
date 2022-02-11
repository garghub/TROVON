static int F_1 ()
{
#ifdef F_2
signal ( F_2 , V_1 ) ;
#endif
if ( ! F_3 ( V_2
| V_3 , NULL ) )
return 0 ;
#ifndef F_4
F_5 () ;
#endif
return 1 ;
}
static void F_6 ()
{
#ifndef F_4
F_7 () ;
#endif
}
static char * F_8 ()
{
const char * V_4 ;
T_1 V_5 ;
char * V_6 ;
if ( ( V_4 = getenv ( L_1 ) ) != NULL )
return F_9 ( V_4 ) ;
V_4 = F_10 () ;
V_5 = strlen ( V_4 ) + 1 + strlen ( V_7 ) + 1 ;
V_6 = F_11 ( V_5 , L_2 ) ;
strcpy ( V_6 , V_4 ) ;
#ifndef F_12
strcat ( V_6 , L_3 ) ;
#endif
strcat ( V_6 , V_7 ) ;
return V_6 ;
}
int main ( int V_8 , char * V_9 [] )
{
T_2 V_10 , * V_11 ;
F_13 ( T_2 ) * V_12 = NULL ;
char * * V_13 = NULL ;
char * V_6 , * V_14 ;
char V_15 [ 1024 ] ;
const char * V_16 ;
ARGS V_17 ;
int V_18 , V_19 , V_20 , V_21 = 0 ;
V_17 . V_9 = NULL ;
V_17 . V_22 = 0 ;
V_23 = F_8 () ;
V_24 = F_14 ( V_25 ) ;
V_26 = F_15 ( V_25 ) ;
V_27 = F_16 ( V_25 ) ;
#if F_17 ( F_12 ) && F_17 ( V_28 )
V_13 = V_9 = F_18 ( & V_8 , V_9 ) ;
#elif F_17 ( V_29 )
F_19 ( & V_8 , & V_9 ) ;
#endif
V_6 = getenv ( L_4 ) ;
if ( V_6 != NULL && strcmp ( V_6 , L_5 ) == 0 )
F_20 ( 1 ) ;
F_21 ( V_30 ) ;
if ( getenv ( L_6 ) ) {
#ifdef F_22
if ( ! F_23 ( 1 ) ) {
F_24 ( V_27 ) ;
return 1 ;
}
#else
F_25 ( V_27 , L_7 ) ;
return 1 ;
#endif
}
if ( ! F_1 () )
goto V_31;
V_12 = F_26 () ;
V_14 = F_27 ( V_9 [ 0 ] ) ;
V_10 . V_32 = V_14 ;
V_11 = F_28 ( V_12 , & V_10 ) ;
if ( V_11 != NULL ) {
V_9 [ 0 ] = V_14 ;
V_21 = V_11 -> V_33 ( V_8 , V_9 ) ;
goto V_31;
}
if ( V_8 != 1 ) {
V_8 -- ;
V_9 ++ ;
V_21 = F_29 ( V_12 , V_8 , V_9 ) ;
if ( V_21 < 0 )
V_21 = 0 ;
goto V_31;
}
for (; ; ) {
V_21 = 0 ;
for ( V_6 = V_15 , V_19 = sizeof V_15 , V_20 = 0 , V_18 = 1 ; V_19 > 0 ; V_18 = 0 ) {
V_16 = V_18 ? L_8 : L_9 ;
V_6 [ 0 ] = '\0' ;
#ifndef F_30
fputs ( V_16 , stdout ) ;
fflush ( stdout ) ;
if ( ! fgets ( V_6 , V_19 , V_34 ) )
goto V_31;
if ( V_6 [ 0 ] == '\0' )
goto V_31;
V_20 = strlen ( V_6 ) ;
if ( V_20 <= 1 )
break;
if ( V_6 [ V_20 - 2 ] != '\\' )
break;
V_20 -= 2 ;
V_6 += V_20 ;
V_19 -= V_20 ;
#else
{
extern char * V_35 ( const char * ) ;
extern void V_36 ( const char * V_37 ) ;
char * V_38 ;
V_38 = V_35 ( V_16 ) ;
if ( V_38 == NULL )
goto V_31;
V_20 = strlen ( V_38 ) ;
if ( V_20 == 0 || V_20 > V_19 )
break;
if ( V_38 [ V_20 - 1 ] != '\\' ) {
V_6 += strlen ( strcpy ( V_6 , V_38 ) ) ;
free ( V_38 ) ;
V_36 ( V_15 ) ;
break;
}
V_38 [ V_20 - 1 ] = '\0' ;
V_6 += strlen ( strcpy ( V_6 , V_38 ) ) ;
free ( V_38 ) ;
V_19 -= V_20 ;
}
#endif
}
if ( ! F_31 ( & V_17 , V_15 ) ) {
F_25 ( V_27 , L_10 ) ;
break;
}
V_21 = F_29 ( V_12 , V_17 . V_8 , V_17 . V_9 ) ;
if ( V_21 == V_39 ) {
V_21 = 0 ;
goto V_31;
}
if ( V_21 != 0 )
F_25 ( V_27 , L_11 , V_17 . V_9 [ 0 ] ) ;
( void ) F_32 ( V_26 ) ;
( void ) F_32 ( V_27 ) ;
}
V_21 = 1 ;
V_31:
F_33 ( V_13 ) ;
F_33 ( V_23 ) ;
F_34 ( V_40 ) ;
V_40 = NULL ;
F_35 ( V_12 ) ;
F_33 ( V_17 . V_9 ) ;
F_36 ( V_24 ) ;
F_37 ( V_26 ) ;
F_6 () ;
#ifndef F_38
if ( F_39 ( V_27 ) <= 0 )
V_21 = 1 ;
#endif
F_36 ( V_27 ) ;
EXIT ( V_21 ) ;
}
static void F_40 ( const T_3 * V_41 ,
const char * V_42 , const char * V_43 , void * V_17 )
{
if ( V_41 )
F_25 ( V_17 , L_12 , F_41 ( V_41 ) ) ;
else {
if ( ! V_42 )
V_42 = L_13 ;
if ( ! V_43 )
V_43 = L_13 ;
F_25 ( V_17 , L_14 , V_42 , V_43 ) ;
}
}
static void F_42 ( const T_4 * V_44 ,
const char * V_42 , const char * V_43 , void * V_17 )
{
if ( V_44 )
F_25 ( V_17 , L_12 , F_43 ( V_44 ) ) ;
else {
if ( ! V_42 )
V_42 = L_13 ;
if ( ! V_43 )
V_43 = L_13 ;
F_25 ( ( V_45 * ) V_17 , L_14 , V_42 , V_43 ) ;
}
}
int F_44 ( int V_8 , char * * V_9 )
{
char * V_12 ;
T_5 V_46 ;
int V_47 = 0 ;
V_12 = F_45 ( V_8 , V_9 , V_48 ) ;
while ( ( V_46 = F_46 () ) != V_49 ) {
switch ( V_46 ) {
case V_49 :
case V_50 :
F_25 ( V_27 , L_15 , V_12 ) ;
return 1 ;
case V_51 :
F_47 ( V_48 ) ;
break;
case V_52 :
F_48 ( V_53 ) ;
break;
case V_54 :
F_48 ( V_55 ) ;
break;
case V_56 :
F_49 ( F_42 , V_26 ) ;
break;
case V_57 :
F_48 ( V_58 ) ;
break;
case V_59 :
F_50 ( F_40 , V_26 ) ;
break;
case V_60 :
F_51 () ;
break;
case V_61 :
F_52 () ;
break;
}
V_47 = 1 ;
}
if ( ! V_47 ) {
F_25 ( V_27 , L_15 , V_12 ) ;
return 1 ;
}
return 0 ;
}
int F_53 ( int V_8 , char * * V_9 )
{
T_2 * V_11 ;
int V_20 , V_62 ;
T_6 V_63 ;
char * V_12 ;
T_5 V_46 ;
V_12 = F_45 ( V_8 , V_9 , V_64 ) ;
while ( ( V_46 = F_46 () ) != V_49 ) {
switch ( V_46 ) {
default:
F_25 ( V_27 , L_15 , V_12 ) ;
return 1 ;
case V_51 :
F_47 ( V_64 ) ;
return 0 ;
}
}
if ( F_54 () != 0 ) {
F_25 ( V_27 , L_16 , V_12 ) ;
return 1 ;
}
F_25 ( V_27 , L_17 ) ;
V_20 = 0 ;
V_63 = V_65 ;
for ( V_11 = V_66 ; V_11 -> V_32 != NULL ; V_11 ++ ) {
V_62 = 0 ;
if ( ( ( V_20 ++ ) % V_67 ) == 0 ) {
F_25 ( V_27 , L_18 ) ;
V_62 = 1 ;
}
if ( V_11 -> type != V_63 ) {
V_63 = V_11 -> type ;
if ( ! V_62 )
F_25 ( V_27 , L_18 ) ;
if ( V_63 == V_55 ) {
V_20 = 1 ;
F_25 ( V_27 ,
L_19 ) ;
} else if ( V_63 == V_58 ) {
V_20 = 1 ;
F_25 ( V_27 ,
L_20 ) ;
}
}
F_25 ( V_27 , V_68 , V_11 -> V_32 ) ;
}
F_25 ( V_27 , L_21 ) ;
return 0 ;
}
int F_55 ( int V_8 , char * * V_9 )
{
return V_39 ;
}
static void F_48 ( T_6 V_69 )
{
T_2 * V_11 ;
int V_20 = 0 ;
for ( V_11 = V_66 ; V_11 -> V_32 != NULL ; V_11 ++ )
if ( V_11 -> type == V_69 ) {
if ( ( V_20 ++ % V_67 ) == 0 )
F_25 ( V_26 , L_18 ) ;
F_25 ( V_26 , V_68 , V_11 -> V_32 ) ;
}
F_25 ( V_26 , L_18 ) ;
}
static void F_51 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_56 () ; V_20 ++ ) {
const T_7 * V_70 ;
int V_71 , V_72 , V_73 ;
const char * V_74 , * V_75 ;
V_70 = F_57 ( V_20 ) ;
F_58 ( & V_71 , & V_72 , & V_73 ,
& V_74 , & V_75 , V_70 ) ;
if ( V_73 & V_76 ) {
F_25 ( V_26 , L_22 , F_59 ( V_71 ) ) ;
F_25 ( V_26 , L_23 ,
F_59 ( V_72 ) ) ;
} else {
F_25 ( V_26 , L_22 , V_74 ) ;
F_25 ( V_26 , L_24 ,
V_73 & V_77 ?
L_25 : L_26 ) ;
F_25 ( V_26 , L_27 , F_59 ( V_71 ) ) ;
if ( V_75 == NULL )
V_75 = L_28 ;
F_25 ( V_26 , L_29 , V_75 ) ;
}
}
}
static int F_60 ( const T_2 * V_78 , const T_2 * V_79 )
{
return strncmp ( V_78 -> V_32 , V_79 -> V_32 , 8 ) ;
}
static unsigned long F_61 ( const T_2 * V_78 )
{
return F_62 ( V_78 -> V_32 ) ;
}
static int F_63 ( const void * V_80 , const void * V_81 )
{
const T_2 * V_82 = V_80 ;
const T_2 * V_83 = V_81 ;
if ( V_82 -> type != V_83 -> type )
return V_82 -> type - V_83 -> type ;
return strcmp ( V_82 -> V_32 , V_83 -> V_32 ) ;
}
static void F_52 ( void )
{
F_64 ( V_26 , L_30 ) ;
#ifdef F_65
F_64 ( V_26 , L_31 ) ;
#endif
#ifndef F_66
F_64 ( V_26 , L_32 ) ;
#endif
#ifdef F_67
F_64 ( V_26 , L_33 ) ;
#endif
#ifdef F_68
F_64 ( V_26 , L_34 ) ;
#endif
#ifdef F_69
F_64 ( V_26 , L_35 ) ;
#endif
#ifdef F_70
F_64 ( V_26 , L_36 ) ;
#endif
#ifdef F_71
F_64 ( V_26 , L_37 ) ;
#endif
#ifdef F_72
F_64 ( V_26 , L_38 ) ;
#endif
#ifdef F_73
F_64 ( V_26 , L_39 ) ;
#endif
#ifdef F_74
F_64 ( V_26 , L_40 ) ;
#endif
#ifdef F_75
F_64 ( V_26 , L_41 ) ;
#endif
#if F_17 ( V_84 )
F_64 ( V_26 , L_42 ) ;
#endif
#if F_17 ( V_85 )
F_64 ( V_26 , L_43 ) ;
#endif
#if F_17 ( V_86 )
F_64 ( V_26 , L_44 ) ;
#endif
#ifdef F_76
F_64 ( V_26 , L_45 ) ;
#endif
#ifdef F_77
F_64 ( V_26 , L_46 ) ;
#endif
#ifdef F_78
F_64 ( V_26 , L_47 ) ;
#endif
#ifdef F_79
F_64 ( V_26 , L_48 ) ;
#endif
#ifdef F_80
F_64 ( V_26 , L_49 ) ;
#endif
#ifdef F_81
F_64 ( V_26 , L_50 ) ;
#endif
#ifdef F_82
F_64 ( V_26 , L_51 ) ;
#endif
#ifdef F_83
F_64 ( V_26 , L_52 ) ;
#endif
#ifdef F_84
F_64 ( V_26 , L_53 ) ;
#endif
#ifdef F_85
F_64 ( V_26 , L_54 ) ;
#endif
#ifdef F_86
F_64 ( V_26 , L_55 ) ;
#endif
#ifdef F_87
F_64 ( V_26 , L_56 ) ;
#endif
#ifdef F_88
F_64 ( V_26 , L_57 ) ;
#endif
#ifdef F_89
F_64 ( V_26 , L_58 ) ;
#endif
#ifdef F_90
F_64 ( V_26 , L_59 ) ;
#endif
#ifdef F_91
F_64 ( V_26 , L_60 ) ;
#endif
#ifdef F_92
F_64 ( V_26 , L_61 ) ;
#endif
#ifdef F_93
F_64 ( V_26 , L_62 ) ;
#endif
#ifdef F_94
F_64 ( V_26 , L_63 ) ;
#endif
#ifdef F_95
F_64 ( V_26 , L_64 ) ;
#endif
#ifdef F_96
F_64 ( V_26 , L_65 ) ;
#endif
#ifdef F_97
F_64 ( V_26 , L_66 ) ;
#endif
#ifdef F_98
F_64 ( V_26 , L_67 ) ;
#endif
#ifdef F_99
F_64 ( V_26 , L_68 ) ;
#endif
#ifdef F_100
F_64 ( V_26 , L_69 ) ;
#endif
#ifdef F_101
F_64 ( V_26 , L_70 ) ;
#endif
#ifdef F_102
F_64 ( V_26 , L_71 ) ;
#endif
#ifdef F_103
F_64 ( V_26 , L_72 ) ;
#endif
#ifdef F_104
F_64 ( V_26 , L_73 ) ;
#endif
#ifndef F_105
F_64 ( V_26 , L_74 ) ;
#endif
}
