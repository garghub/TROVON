static void F_1 ( int V_1 , int type , const char * V_2 , int line )
{
static int V_3 [ V_4 ] ;
const char * V_5 = NULL ;
int V_6 ;
V_6 = V_1 & ( V_7 | V_8 ) ;
if ( ! ( ( V_6 == V_7 ) || ( V_6 == V_8 ) ) ) {
V_5 = L_1 ;
goto V_9;
}
if ( type < 0 || type >= V_4 ) {
V_5 = L_2 ;
goto V_9;
}
if ( V_1 & V_10 ) {
if ( V_3 [ type ] ) {
V_5 = L_3 ;
goto V_9;
}
V_3 [ type ] = V_6 ;
} else if ( V_1 & V_11 ) {
if ( ! V_3 [ type ] ) {
V_5 = L_4 ;
goto V_9;
}
if ( V_3 [ type ] != V_6 ) {
V_5 = ( V_6 == V_7 ) ?
L_5 :
L_6 ;
}
V_3 [ type ] = 0 ;
} else {
V_5 = L_1 ;
goto V_9;
}
V_9:
if ( V_5 ) {
fprintf ( V_12 ,
L_7 ,
V_5 , V_1 , type , V_2 , line ) ;
}
}
int main ( int V_13 , char * V_14 [] )
{
ARGS V_15 ;
#define F_2 39
char V_16 [ F_2 + 1 ] ;
T_1 V_17 , * V_18 ;
T_2 const char * V_19 ;
T_2 char V_20 [ 1024 ] ;
char * V_21 = NULL ;
int V_22 , V_23 , V_24 = 0 ;
int V_25 ;
char * * V_26 , * V_27 ;
F_3 ( T_1 ) * V_28 = NULL ;
long V_29 ;
#if F_4 ( V_30 ) && ( V_31 == 64 )
char * * V_32 = NULL ;
int V_33 = 0 ;
if ( ( sizeof( V_34 ) < 8 )
# if ! F_4 ( V_35 )
|| ( V_34 [ V_13 ] != NULL )
# endif
) {
int V_23 ;
V_32 = F_5 ( ( V_13 + 1 ) * sizeof( char * ) ) ;
if ( V_32 == NULL ) {
V_24 = - 1 ;
goto V_36;
}
for ( V_23 = 0 ; V_23 < V_13 ; V_23 ++ )
V_32 [ V_23 ] = V_34 [ V_23 ] ;
V_32 [ V_13 ] = NULL ;
V_33 = 1 ;
} else {
V_32 = ( char * * ) V_34 ;
}
#endif
V_15 . V_37 = NULL ;
V_15 . V_38 = 0 ;
if ( V_39 == NULL )
if ( ( V_39 = F_6 ( F_7 () ) ) != NULL )
F_8 ( V_39 , V_12 , V_40 | V_41 ) ;
if ( getenv ( L_8 ) != NULL ) {
if ( ! ( 0 == strcmp ( getenv ( L_8 ) , L_9 ) ) ) {
F_9 () ;
F_10 ( V_42 ) ;
} else {
F_11 ( 0 , 0 , 0 , 0 , 0 ) ;
}
}
F_12 ( V_43 ) ;
#if 0
if (getenv("OPENSSL_DEBUG_LOCKING") != NULL)
#endif
{
F_13 ( F_1 ) ;
}
if ( getenv ( L_10 ) ) {
#ifdef F_14
if ( ! F_15 ( 1 ) ) {
F_16 () ;
F_17 ( F_18 ( V_12 , V_40 ) ) ;
EXIT ( 1 ) ;
}
#else
fprintf ( V_12 , L_11 ) ;
EXIT ( 1 ) ;
#endif
}
F_19 () ;
V_27 = getenv ( L_12 ) ;
if ( V_27 == NULL )
V_27 = getenv ( L_13 ) ;
if ( V_27 == NULL )
V_27 = V_21 = F_20 () ;
V_44 = V_27 ;
V_45 = F_21 ( NULL ) ;
V_23 = F_22 ( V_45 , V_27 , & V_29 ) ;
if ( V_23 == 0 ) {
if ( F_23 ( F_24 () )
== V_46 ) {
F_25 ( V_39 , L_14 , V_27 ) ;
F_26 () ;
F_27 ( V_45 ) ;
V_45 = NULL ;
} else {
F_17 ( V_39 ) ;
F_27 ( V_45 ) ;
exit ( 1 ) ;
}
}
V_28 = F_28 () ;
F_29 ( V_32 [ 0 ] , V_16 , sizeof V_16 ) ;
V_17 . V_47 = V_16 ;
V_18 = F_30 ( V_28 , & V_17 ) ;
if ( V_18 != NULL ) {
V_32 [ 0 ] = V_16 ;
V_24 = V_18 -> V_48 ( V_13 , V_32 ) ;
goto V_36;
}
if ( V_13 != 1 ) {
V_13 -- ;
V_32 ++ ;
V_24 = F_31 ( V_28 , V_13 , V_32 ) ;
if ( V_24 < 0 )
V_24 = 0 ;
goto V_36;
}
for (; ; ) {
V_24 = 0 ;
V_27 = V_20 ;
V_22 = sizeof V_20 ;
V_23 = 0 ;
for (; ; ) {
V_27 [ 0 ] = '\0' ;
if ( V_23 ++ )
V_19 = L_15 ;
else
V_19 = L_16 ;
fputs ( V_19 , stdout ) ;
fflush ( stdout ) ;
if ( ! fgets ( V_27 , V_22 , V_49 ) )
goto V_36;
if ( V_27 [ 0 ] == '\0' )
goto V_36;
V_23 = strlen ( V_27 ) ;
if ( V_23 <= 1 )
break;
if ( V_27 [ V_23 - 2 ] != '\\' )
break;
V_23 -= 2 ;
V_27 += V_23 ;
V_22 -= V_23 ;
}
if ( ! F_32 ( & V_15 , V_20 , & V_25 , & V_26 ) )
break;
V_24 = F_31 ( V_28 , V_25 , V_26 ) ;
if ( V_24 < 0 ) {
V_24 = 0 ;
goto V_36;
}
if ( V_24 != 0 )
F_25 ( V_39 , L_17 , V_26 [ 0 ] ) ;
( void ) F_33 ( V_39 ) ;
}
F_25 ( V_39 , L_18 ) ;
V_24 = 1 ;
V_36:
if ( V_21 )
F_34 ( V_21 ) ;
if ( V_45 != NULL ) {
F_27 ( V_45 ) ;
V_45 = NULL ;
}
if ( V_28 != NULL )
F_35 ( V_28 ) ;
if ( V_15 . V_37 != NULL )
F_34 ( V_15 . V_37 ) ;
if ( V_39 != NULL ) {
F_36 ( V_39 ) ;
V_39 = NULL ;
}
#if F_4 ( V_30 ) && ( V_31 == 64 )
if ( V_33 ) {
F_34 ( V_32 ) ;
}
#endif
F_37 () ;
F_38 ( V_39 ) ;
F_39 ( V_24 ) ;
}
static int F_40 ( const void * V_50 , const void * V_51 )
{
const T_1 * V_52 = V_50 ;
const T_1 * V_53 = V_51 ;
if ( V_52 -> type != V_53 -> type )
return V_52 -> type - V_53 -> type ;
return strcmp ( V_52 -> V_47 , V_53 -> V_47 ) ;
}
static void F_41 ( T_3 * V_54 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_42 () ; V_23 ++ ) {
const T_4 * V_55 ;
int V_56 , V_57 , V_58 ;
const char * V_59 , * V_60 ;
V_55 = F_43 ( V_23 ) ;
F_44 ( & V_56 , & V_57 , & V_58 ,
& V_59 , & V_60 , V_55 ) ;
if ( V_58 & V_61 ) {
F_25 ( V_54 , L_19 , F_45 ( V_56 ) ) ;
F_25 ( V_54 , L_20 ,
F_45 ( V_57 ) ) ;
} else {
F_25 ( V_54 , L_19 , V_59 ) ;
F_25 ( V_54 , L_21 ,
V_58 & V_62 ?
L_22 : L_23 ) ;
F_25 ( V_54 , L_24 , F_45 ( V_56 ) ) ;
if ( V_60 == NULL )
V_60 = L_25 ;
F_25 ( V_54 , L_26 , V_60 ) ;
}
}
}
static void F_46 ( const T_5 * V_63 ,
const char * V_64 , const char * V_65 , void * V_15 )
{
if ( V_63 )
F_25 ( V_15 , L_27 , F_47 ( V_63 ) ) ;
else {
if ( ! V_64 )
V_64 = L_28 ;
if ( ! V_65 )
V_65 = L_28 ;
F_25 ( V_15 , L_29 , V_64 , V_65 ) ;
}
}
static void F_48 ( T_3 * V_54 )
{
F_49 ( F_46 , V_54 ) ;
}
static void F_50 ( const T_6 * V_66 ,
const char * V_64 , const char * V_65 , void * V_15 )
{
if ( V_66 )
F_25 ( V_15 , L_27 , F_51 ( V_66 ) ) ;
else {
if ( ! V_64 )
V_64 = L_28 ;
if ( ! V_65 )
V_65 = L_28 ;
F_25 ( V_15 , L_29 , V_64 , V_65 ) ;
}
}
static void F_52 ( T_3 * V_54 )
{
F_53 ( F_50 , V_54 ) ;
}
static int T_7 F_54 ( const T_1 * V_67 , const T_1 * V_68 )
{
return strncmp ( V_67 -> V_47 , V_68 -> V_47 , 8 ) ;
}
