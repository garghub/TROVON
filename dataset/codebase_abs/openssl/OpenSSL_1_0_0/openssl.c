static void F_1 ( int V_1 , int type , const char * V_2 , int line )
{
static int V_3 [ V_4 ] ;
const char * V_5 = NULL ;
int V_6 ;
V_6 = V_1 & ( V_7 | V_8 ) ;
if ( ! ( ( V_6 == V_7 ) || ( V_6 == V_8 ) ) )
{
V_5 = L_1 ;
goto V_9;
}
if ( type < 0 || type >= V_4 )
{
V_5 = L_2 ;
goto V_9;
}
if ( V_1 & V_10 )
{
if ( V_3 [ type ] )
{
V_5 = L_3 ;
goto V_9;
}
V_3 [ type ] = V_6 ;
}
else if ( V_1 & V_11 )
{
if ( ! V_3 [ type ] )
{
V_5 = L_4 ;
goto V_9;
}
if ( V_3 [ type ] != V_6 )
{
V_5 = ( V_6 == V_7 ) ?
L_5 :
L_6 ;
}
V_3 [ type ] = 0 ;
}
else
{
V_5 = L_1 ;
goto V_9;
}
V_9:
if ( V_5 )
{
fprintf ( V_12 , L_7 ,
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
V_15 . V_30 = NULL ;
V_15 . V_31 = 0 ;
if ( V_32 == NULL )
if ( ( V_32 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_32 , V_12 , V_33 | V_34 ) ;
if ( getenv ( L_8 ) != NULL )
{
if ( ! ( 0 == strcmp ( getenv ( L_8 ) , L_9 ) ) )
{
F_7 () ;
F_8 ( V_35 ) ;
}
else
{
F_9 ( 0 , 0 , 0 , 0 , 0 ) ;
}
}
F_10 ( V_36 ) ;
#if 0
if (getenv("OPENSSL_DEBUG_LOCKING") != NULL)
#endif
{
F_11 ( F_1 ) ;
}
F_12 () ;
V_27 = getenv ( L_10 ) ;
if ( V_27 == NULL )
V_27 = getenv ( L_11 ) ;
if ( V_27 == NULL )
V_27 = V_21 = F_13 () ;
V_37 = V_27 ;
V_38 = F_14 ( NULL ) ;
V_23 = F_15 ( V_38 , V_27 , & V_29 ) ;
if ( V_23 == 0 )
{
if ( F_16 ( F_17 () )
== V_39 )
{
F_18 ( V_32 ,
L_12 , V_27 ) ;
F_19 () ;
F_20 ( V_38 ) ;
V_38 = NULL ;
}
else
{
F_21 ( V_32 ) ;
F_20 ( V_38 ) ;
exit ( 1 ) ;
}
}
V_28 = F_22 () ;
F_23 ( V_14 [ 0 ] , V_16 , sizeof V_16 ) ;
V_17 . V_40 = V_16 ;
V_18 = F_24 ( V_28 , & V_17 ) ;
if ( V_18 != NULL )
{
V_14 [ 0 ] = V_16 ;
V_24 = V_18 -> V_41 ( V_13 , V_14 ) ;
goto V_42;
}
if ( V_13 != 1 )
{
V_13 -- ;
V_14 ++ ;
V_24 = F_25 ( V_28 , V_13 , V_14 ) ;
if ( V_24 < 0 ) V_24 = 0 ;
goto V_42;
}
for (; ; )
{
V_24 = 0 ;
V_27 = V_20 ;
V_22 = sizeof V_20 ;
V_23 = 0 ;
for (; ; )
{
V_27 [ 0 ] = '\0' ;
if ( V_23 ++ )
V_19 = L_13 ;
else V_19 = L_14 ;
fputs ( V_19 , stdout ) ;
fflush ( stdout ) ;
if ( ! fgets ( V_27 , V_22 , V_43 ) )
goto V_42;
if ( V_27 [ 0 ] == '\0' ) goto V_42;
V_23 = strlen ( V_27 ) ;
if ( V_23 <= 1 ) break;
if ( V_27 [ V_23 - 2 ] != '\\' ) break;
V_23 -= 2 ;
V_27 += V_23 ;
V_22 -= V_23 ;
}
if ( ! F_26 ( & V_15 , V_20 , & V_25 , & V_26 ) ) break;
V_24 = F_25 ( V_28 , V_25 , V_26 ) ;
if ( V_24 < 0 )
{
V_24 = 0 ;
goto V_42;
}
if ( V_24 != 0 )
F_18 ( V_32 , L_15 , V_26 [ 0 ] ) ;
( void ) F_27 ( V_32 ) ;
}
F_18 ( V_32 , L_16 ) ;
V_24 = 1 ;
V_42:
if ( V_21 )
F_28 ( V_21 ) ;
if ( V_38 != NULL )
{
F_20 ( V_38 ) ;
V_38 = NULL ;
}
if ( V_28 != NULL ) F_29 ( V_28 ) ;
if ( V_15 . V_30 != NULL ) F_28 ( V_15 . V_30 ) ;
F_30 () ;
F_31 ( V_32 ) ;
if ( V_32 != NULL )
{
F_32 ( V_32 ) ;
V_32 = NULL ;
}
F_33 ( V_24 ) ;
}
static int F_34 ( const void * V_44 , const void * V_45 )
{
const T_1 * V_46 = V_44 ;
const T_1 * V_47 = V_45 ;
if( V_46 -> type != V_47 -> type )
return V_46 -> type - V_47 -> type ;
return strcmp ( V_46 -> V_40 , V_47 -> V_40 ) ;
}
static void F_35 ( T_3 * V_48 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_36 () ; V_23 ++ )
{
const T_4 * V_49 ;
int V_50 , V_51 , V_52 ;
const char * V_53 , * V_54 ;
V_49 = F_37 ( V_23 ) ;
F_38 ( & V_50 , & V_51 , & V_52 ,
& V_53 , & V_54 , V_49 ) ;
if ( V_52 & V_55 )
{
F_18 ( V_48 , L_17 ,
F_39 ( V_50 ) ) ;
F_18 ( V_48 , L_18 ,
F_39 ( V_51 ) ) ;
}
else
{
F_18 ( V_48 , L_17 , V_53 ) ;
F_18 ( V_48 , L_19 ,
V_52 & V_56 ?
L_20 : L_21 ) ;
F_18 ( V_48 , L_22 , F_39 ( V_50 ) ) ;
if ( V_54 == NULL )
V_54 = L_23 ;
F_18 ( V_48 , L_24 , V_54 ) ;
}
}
}
static void F_40 ( const T_5 * V_57 ,
const char * V_58 , const char * V_59 , void * V_15 )
{
if ( V_57 )
F_18 ( V_15 , L_25 , F_41 ( V_57 ) ) ;
else
{
if ( ! V_58 )
V_58 = L_26 ;
if ( ! V_59 )
V_59 = L_26 ;
F_18 ( V_15 , L_27 , V_58 , V_59 ) ;
}
}
static void F_42 ( T_3 * V_48 )
{
F_43 ( F_40 , V_48 ) ;
}
static void F_44 ( const T_6 * V_60 ,
const char * V_58 , const char * V_59 , void * V_15 )
{
if ( V_60 )
F_18 ( V_15 , L_25 , F_45 ( V_60 ) ) ;
else
{
if ( ! V_58 )
V_58 = L_26 ;
if ( ! V_59 )
V_59 = L_26 ;
F_18 ( V_15 , L_27 , V_58 , V_59 ) ;
}
}
static void F_46 ( T_3 * V_48 )
{
F_47 ( F_44 , V_48 ) ;
}
static int T_7 F_48 ( const T_1 * V_61 , const T_1 * V_62 )
{
return strncmp ( V_61 -> V_40 , V_62 -> V_40 , 8 ) ;
}
