static void F_1 ( void )
{
V_1 = V_2 ;
V_3 = NULL ;
V_4 = NULL ;
V_5 = NULL ;
V_6 = NULL ;
V_7 = NULL ;
V_8 = V_9 ;
V_10 = V_11 ;
V_12 = NULL ;
V_13 = NULL ;
V_14 = NULL ;
V_15 = 0 ;
V_16 = 0 ;
V_17 = 0 ;
#ifdef F_2
V_18 = 0 ;
#endif
#ifdef F_3
V_19 = 0 ;
#endif
}
static void F_4 ( void )
{
static char V_20 [] = L_1 ;
printf ( L_2 ) ;
printf ( L_3 , V_2 ) ;
#ifdef F_2
printf ( L_4 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
#endif
printf ( V_20 , V_11 ) ;
}
static int F_5 ( int V_21 , char * * V_22 )
{
int V_23 = 0 ;
V_24 = 0 ;
V_25 = V_26 ;
V_21 -- ;
V_22 ++ ;
while ( V_21 >= 1 ) {
if ( strcmp ( * V_22 , L_11 ) == 0 )
{
if ( -- V_21 < 1 ) goto V_27;
V_1 = * ( ++ V_22 ) ;
}
#if 0
else if( strcmp(*argv,"-host") == 0)
{
if (--argc < 1) goto bad;
host= *(++argv);
}
else if( strcmp(*argv,"-port") == 0)
{
if (--argc < 1) goto bad;
port= *(++argv);
}
#endif
else if ( strcmp ( * V_22 , L_12 ) == 0 )
V_17 = 2 ;
else if ( strcmp ( * V_22 , L_13 ) == 0 )
V_17 = 1 ;
else if( strcmp ( * V_22 , L_14 ) == 0 ) {
V_8 = V_28 | V_29 ;
if ( -- V_21 < 1 ) goto V_27;
V_24 = atoi ( * ( ++ V_22 ) ) ;
F_6 ( V_30 , L_15 , V_24 ) ;
} else if( strcmp ( * V_22 , L_16 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_3 = * ( ++ V_22 ) ;
} else if( strcmp ( * V_22 , L_17 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_4 = * ( ++ V_22 ) ;
} else if( strcmp ( * V_22 , L_18 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_5 = * ( ++ V_22 ) ;
} else if( strcmp ( * V_22 , L_19 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_6 = * ( ++ V_22 ) ;
} else if( strcmp ( * V_22 , L_20 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_7 = * ( ++ V_22 ) ;
}
#ifdef F_2
else if( strcmp ( * V_22 , L_21 ) == 0 ) {
V_18 = 1 ;
}
#endif
else if( strcmp ( * V_22 , L_22 ) == 0 )
{
if ( -- V_21 < 1 ) goto V_27;
V_14 = * ( ++ V_22 ) ;
if( strlen ( V_14 ) > V_31 - 100 )
{
F_6 ( V_30 , L_23 ) ;
V_23 = 1 ;
}
}
else if( strcmp ( * V_22 , L_24 ) == 0 )
V_16 = 1 ;
#ifndef F_7
else if( strcmp ( * V_22 , L_25 ) == 0 )
V_13 = F_8 () ;
#endif
#ifndef F_9
else if( strcmp ( * V_22 , L_26 ) == 0 )
V_13 = F_10 () ;
#endif
else if( strcmp ( * V_22 , L_27 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_10 = atoi ( * ( ++ V_22 ) ) ;
}
else {
F_6 ( V_30 , L_28 , * V_22 ) ;
V_23 = 1 ;
break;
}
V_21 -- ;
V_22 ++ ;
}
if ( V_17 == 0 ) V_17 = 3 ;
if( V_23 ) {
V_27:
F_4 () ;
return - 1 ;
}
return 0 ;
}
static double F_11 ( int V_32 )
{
static double V_33 ;
#ifdef F_12
static struct V_34 V_35 , V_36 ;
if( V_32 == V_37 ) {
F_13 ( & V_35 ) ;
return ( 0 ) ;
} else {
F_13 ( & V_36 ) ;
V_33 = ( ( double ) ( V_36 . V_38 - V_35 . V_38 ) ) / V_39 ;
return ( ( V_33 == 0.0 ) ? 1e-6 : V_33 ) ;
}
#elif F_14 ( V_40 )
static T_1 V_35 , V_36 ;
if ( V_32 == V_37 )
{
V_35 = clock () ;
return ( 0 ) ;
}
else
{
V_36 = clock () ;
V_33 = ( double ) ( ( double ) ( V_36 ) - ( double ) ( V_35 ) ) ;
return ( ( V_33 < 0.001 ) ? 0.001 : V_33 ) ;
}
#elif F_14 ( V_41 )
{
static unsigned long V_42 , V_43 ;
if( V_32 == V_37 )
{
V_42 = F_15 () ;
return 0 ;
}
else
{
V_43 = F_15 () ;
V_33 = ( double ) ( V_43 - V_42 ) / ( double ) F_16 () ;
return ( ( V_33 == 0.0 ) ? 1e-6 : V_33 ) ;
}
}
#else
static struct V_44 V_35 , V_36 ;
long V_45 ;
if( V_32 == V_37 ) {
F_17 ( & V_35 ) ;
return ( 0 ) ;
} else {
F_17 ( & V_36 ) ;
V_45 = ( long ) V_36 . V_46 - ( long ) V_35 . V_46 ;
V_33 = ( ( double ) ( V_36 . time - V_35 . time ) ) + ( ( double ) V_45 ) / 1000.0 ;
return ( ( V_33 == 0.0 ) ? 1e-6 : V_33 ) ;
}
#endif
}
int MAIN ( int V_21 , char * * V_22 )
{
double V_47 = 0.0 ;
int V_48 = 0 ;
T_2 * V_49 = NULL ;
long V_50 = 0 ;
int V_33 = 1 , V_45 ;
T_3 char V_51 [ 1024 * 8 ] ;
int V_52 ;
F_18 () ;
F_1 () ;
if ( V_30 == NULL )
V_30 = F_19 ( V_53 , V_54 ) ;
#if ! F_14 ( F_7 ) && ! F_14 ( F_9 )
V_13 = F_20 () ;
#elif ! F_14 ( F_9 )
V_13 = F_10 () ;
#elif ! F_14 ( F_7 )
V_13 = F_8 () ;
#endif
if( F_5 ( V_21 , V_22 ) < 0 )
goto V_55;
F_21 () ;
if ( ( V_12 = F_22 ( V_13 ) ) == NULL ) return ( 1 ) ;
F_23 ( V_12 , 1 ) ;
if ( V_16 ) F_24 ( V_12 , V_56 ) ;
F_25 ( V_12 , V_7 ) ;
if( ! F_26 ( V_12 , V_3 , V_4 ) )
goto V_55;
F_27 () ;
if ( ( ! F_28 ( V_12 , V_6 , V_5 ) ) ||
( ! F_29 ( V_12 ) ) )
{
F_30 ( V_30 ) ;
}
if ( V_7 == NULL )
V_7 = getenv ( L_29 ) ;
if ( V_7 == NULL ) {
fprintf ( V_53 , L_30 ) ;
}
if ( ! ( V_17 & 1 ) ) goto V_57;
printf ( L_31 , V_10 ) ;
V_15 = 0 ;
V_50 = ( long ) time ( NULL ) + V_10 ;
F_11 ( V_37 ) ;
for (; ; )
{
if ( V_50 < ( long ) time ( NULL ) ) break;
#ifdef F_31
if( F_32 ( 0 ) == - 1 )
goto V_55;
if( V_58 || V_19 )
goto V_55;
#endif
if( ( V_49 = F_33 ( NULL ) ) == NULL )
goto V_55;
if ( V_14 != NULL )
{
F_34 ( V_51 , sizeof V_51 , L_32 , V_14 ) ;
F_35 ( V_49 , V_51 , strlen ( V_51 ) ) ;
while ( ( V_45 = F_36 ( V_49 , V_51 , sizeof( V_51 ) ) ) > 0 )
V_15 += V_45 ;
}
#ifdef F_37
F_38 ( V_49 , V_59 | V_60 ) ;
#else
F_39 ( V_49 ) ;
#endif
F_40 ( F_41 ( V_49 ) ) ;
V_48 += 1 ;
if ( F_42 ( V_49 ) )
V_52 = 'r' ;
else
{
V_52 = F_43 ( V_49 ) ;
if ( V_52 == V_61 )
V_52 = 't' ;
else if ( V_52 == V_62 )
V_52 = '3' ;
else if ( V_52 == V_63 )
V_52 = '2' ;
else
V_52 = '*' ;
}
fputc ( V_52 , stdout ) ;
fflush ( stdout ) ;
F_44 ( V_49 ) ;
V_49 = NULL ;
}
V_47 += F_11 ( V_64 ) ;
V_45 = ( int ) ( ( long ) time ( NULL ) - V_50 + V_10 ) ;
printf ( L_33 , V_48 , V_47 , ( ( double ) V_48 / V_47 ) , V_15 ) ;
printf ( L_34 , V_48 , ( long ) time ( NULL ) - V_50 + V_10 , V_15 / V_48 ) ;
V_57:
if ( ! ( V_17 & 2 ) ) goto V_55;
printf ( L_35 ) ;
if( ( V_49 = F_33 ( NULL ) ) == NULL )
{
fprintf ( V_53 , L_36 ) ;
goto V_55;
}
if ( V_14 != NULL )
{
F_34 ( V_51 , sizeof V_51 , L_32 , V_14 ) ;
F_35 ( V_49 , V_51 , strlen ( V_51 ) ) ;
while ( F_36 ( V_49 , V_51 , sizeof( V_51 ) ) > 0 )
;
}
#ifdef F_37
F_38 ( V_49 , V_59 | V_60 ) ;
#else
F_39 ( V_49 ) ;
#endif
F_40 ( F_41 ( V_49 ) ) ;
V_48 = 0 ;
V_47 = 0.0 ;
V_50 = ( long ) time ( NULL ) + V_10 ;
printf ( L_37 ) ;
V_15 = 0 ;
F_11 ( V_37 ) ;
for (; ; )
{
if ( V_50 < ( long ) time ( NULL ) ) break;
#ifdef F_31
if( F_32 ( 0 ) == - 1 )
goto V_55;
if( V_58 || V_19 )
goto V_55;
#endif
if( ( F_33 ( V_49 ) ) == NULL )
goto V_55;
if ( V_14 )
{
F_34 ( V_51 , sizeof V_51 , L_32 , V_14 ) ;
F_35 ( V_49 , V_51 , strlen ( V_51 ) ) ;
while ( ( V_45 = F_36 ( V_49 , V_51 , sizeof( V_51 ) ) ) > 0 )
V_15 += V_45 ;
}
#ifdef F_37
F_38 ( V_49 , V_59 | V_60 ) ;
#else
F_39 ( V_49 ) ;
#endif
F_40 ( F_41 ( V_49 ) ) ;
V_48 += 1 ;
if ( F_42 ( V_49 ) )
V_52 = 'r' ;
else
{
V_52 = F_43 ( V_49 ) ;
if ( V_52 == V_61 )
V_52 = 't' ;
else if ( V_52 == V_62 )
V_52 = '3' ;
else if ( V_52 == V_63 )
V_52 = '2' ;
else
V_52 = '*' ;
}
fputc ( V_52 , stdout ) ;
fflush ( stdout ) ;
}
V_47 += F_11 ( V_64 ) ;
printf ( L_33 , V_48 , V_47 , ( ( double ) V_48 / V_47 ) , V_15 ) ;
printf ( L_34 , V_48 , ( long ) time ( NULL ) - V_50 + V_10 , V_15 / V_48 ) ;
V_33 = 0 ;
V_55:
if ( V_49 != NULL ) F_44 ( V_49 ) ;
if ( V_12 != NULL )
{
F_45 ( V_12 ) ;
V_12 = NULL ;
}
F_46 () ;
F_47 ( V_33 ) ;
}
static T_2 * F_33 ( T_2 * V_49 )
{
T_4 * V_65 ;
T_2 * V_66 ;
int V_67 , V_45 ;
T_5 V_68 ;
if ( ( V_65 = F_48 ( F_49 () ) ) == NULL )
return ( NULL ) ;
F_50 ( V_65 , V_1 ) ;
if ( V_49 == NULL )
V_66 = F_51 ( V_12 ) ;
else
{
V_66 = V_49 ;
F_52 ( V_66 ) ;
}
F_53 ( V_66 , V_65 , V_65 ) ;
#if 0
if( scon != NULL )
SSL_set_session(serverCon,SSL_get_session(scon));
#endif
for(; ; ) {
V_45 = F_54 ( V_66 ) ;
if ( F_55 ( V_45 ) )
{
F_6 ( V_30 , L_38 ) ;
V_45 = F_41 ( V_66 ) ;
V_67 = V_45 + 1 ;
F_56 ( & V_68 ) ;
F_57 ( V_45 , & V_68 ) ;
F_58 ( V_67 , ( void * ) & V_68 , NULL , NULL , NULL ) ;
continue;
}
break;
}
if( V_45 <= 0 )
{
F_6 ( V_30 , L_39 ) ;
if ( V_25 != V_26 )
F_6 ( V_30 , L_40 ,
F_59 ( V_25 ) ) ;
else
F_30 ( V_30 ) ;
if ( V_49 == NULL )
F_44 ( V_66 ) ;
return NULL ;
}
return V_66 ;
}
