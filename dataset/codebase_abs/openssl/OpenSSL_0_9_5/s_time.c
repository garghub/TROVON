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
}
else if( strcmp ( * V_22 , L_23 ) == 0 )
V_16 = 1 ;
#ifndef F_7
else if( strcmp ( * V_22 , L_24 ) == 0 )
V_13 = F_8 () ;
#endif
#ifndef F_9
else if( strcmp ( * V_22 , L_25 ) == 0 )
V_13 = F_10 () ;
#endif
else if( strcmp ( * V_22 , L_26 ) == 0 ) {
if ( -- V_21 < 1 ) goto V_27;
V_10 = atoi ( * ( ++ V_22 ) ) ;
}
else {
F_6 ( V_30 , L_27 , * V_22 ) ;
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
static double F_11 ( int V_31 )
{
static double V_32 ;
#ifdef F_12
static struct V_33 V_34 , V_35 ;
if( V_31 == V_36 ) {
F_13 ( & V_34 ) ;
return ( 0 ) ;
} else {
F_13 ( & V_35 ) ;
V_32 = ( ( double ) ( V_35 . V_37 - V_34 . V_37 ) ) / V_38 ;
return ( ( V_32 == 0.0 ) ? 1e-6 : V_32 ) ;
}
#else
static struct V_39 V_34 , V_35 ;
long V_40 ;
if( V_31 == V_36 ) {
F_14 ( & V_34 ) ;
return ( 0 ) ;
} else {
F_14 ( & V_35 ) ;
V_40 = ( long ) V_35 . V_41 - ( long ) V_34 . V_41 ;
V_32 = ( ( double ) ( V_35 . time - V_34 . time ) ) + ( ( double ) V_40 ) / 1000.0 ;
return ( ( V_32 == 0.0 ) ? 1e-6 : V_32 ) ;
}
#endif
}
int MAIN ( int V_21 , char * * V_22 )
{
double V_42 = 0.0 ;
int V_43 = 0 ;
T_1 * V_44 = NULL ;
long V_45 = 0 ;
int V_32 = 1 , V_40 ;
T_2 char V_46 [ 1024 * 8 ] ;
int V_47 ;
F_15 () ;
F_1 () ;
if ( V_30 == NULL )
V_30 = F_16 ( V_48 , V_49 ) ;
#if ! F_17 ( F_7 ) && ! F_17 ( F_9 )
V_13 = F_18 () ;
#elif ! F_17 ( F_9 )
V_13 = F_10 () ;
#elif ! F_17 ( F_7 )
V_13 = F_8 () ;
#endif
if( F_5 ( V_21 , V_22 ) < 0 )
goto V_50;
F_19 () ;
if ( ( V_12 = F_20 ( V_13 ) ) == NULL ) return ( 1 ) ;
F_21 ( V_12 , 1 ) ;
if ( V_16 ) F_22 ( V_12 , V_51 ) ;
F_23 ( V_12 , V_7 ) ;
if( ! F_24 ( V_12 , V_3 , V_4 ) )
goto V_50;
F_25 () ;
if ( ( ! F_26 ( V_12 , V_6 , V_5 ) ) ||
( ! F_27 ( V_12 ) ) )
{
F_28 ( V_30 ) ;
}
if ( V_7 == NULL )
V_7 = getenv ( L_28 ) ;
if ( V_7 == NULL ) {
fprintf ( V_48 , L_29 ) ;
}
if ( ! ( V_17 & 1 ) ) goto V_52;
printf ( L_30 , V_10 ) ;
V_15 = 0 ;
V_45 = ( long ) time ( NULL ) + V_10 ;
F_11 ( V_36 ) ;
for (; ; )
{
if ( V_45 < time ( NULL ) ) break;
#ifdef F_29
if( F_30 ( 0 ) == - 1 )
goto V_50;
if( V_53 || V_19 )
goto V_50;
#endif
if( ( V_44 = F_31 ( NULL ) ) == NULL )
goto V_50;
if ( V_14 != NULL )
{
sprintf ( V_46 , L_31 , V_14 ) ;
F_32 ( V_44 , V_46 , strlen ( V_46 ) ) ;
while ( ( V_40 = F_33 ( V_44 , V_46 , sizeof( V_46 ) ) ) > 0 )
V_15 += V_40 ;
}
#ifdef F_34
F_35 ( V_44 , V_54 | V_55 ) ;
#else
F_36 ( V_44 ) ;
#endif
F_37 ( F_38 ( V_44 ) ) ;
V_43 += 1 ;
if ( F_39 ( V_44 ) )
V_47 = 'r' ;
else
{
V_47 = F_40 ( V_44 ) ;
if ( V_47 == V_56 )
V_47 = 't' ;
else if ( V_47 == V_57 )
V_47 = '3' ;
else if ( V_47 == V_58 )
V_47 = '2' ;
else
V_47 = '*' ;
}
fputc ( V_47 , stdout ) ;
fflush ( stdout ) ;
F_41 ( V_44 ) ;
V_44 = NULL ;
}
V_42 += F_11 ( V_59 ) ;
V_40 = ( int ) ( time ( NULL ) - V_45 + V_10 ) ;
printf ( L_32 , V_43 , V_42 , ( ( double ) V_43 / V_42 ) , V_15 ) ;
printf ( L_33 , V_43 , time ( NULL ) - V_45 + V_10 , V_15 / V_43 ) ;
V_52:
if ( ! ( V_17 & 2 ) ) goto V_50;
printf ( L_34 ) ;
if( ( V_44 = F_31 ( NULL ) ) == NULL )
{
fprintf ( V_48 , L_35 ) ;
goto V_50;
}
if ( V_14 != NULL )
{
sprintf ( V_46 , L_31 , V_14 ) ;
F_32 ( V_44 , V_46 , strlen ( V_46 ) ) ;
while ( F_33 ( V_44 , V_46 , sizeof( V_46 ) ) > 0 )
;
}
#ifdef F_34
F_35 ( V_44 , V_54 | V_55 ) ;
#else
F_36 ( V_44 ) ;
#endif
F_37 ( F_38 ( V_44 ) ) ;
V_43 = 0 ;
V_42 = 0.0 ;
V_45 = time ( NULL ) + V_10 ;
printf ( L_36 ) ;
V_15 = 0 ;
F_11 ( V_36 ) ;
for (; ; )
{
if ( V_45 < time ( NULL ) ) break;
#ifdef F_29
if( F_30 ( 0 ) == - 1 )
goto V_50;
if( V_53 || V_19 )
goto V_50;
#endif
if( ( F_31 ( V_44 ) ) == NULL )
goto V_50;
if ( V_14 )
{
sprintf ( V_46 , L_31 , V_14 ) ;
F_32 ( V_44 , V_46 , strlen ( V_46 ) ) ;
while ( ( V_40 = F_33 ( V_44 , V_46 , sizeof( V_46 ) ) ) > 0 )
V_15 += V_40 ;
}
#ifdef F_34
F_35 ( V_44 , V_54 | V_55 ) ;
#else
F_36 ( V_44 ) ;
#endif
F_37 ( F_38 ( V_44 ) ) ;
V_43 += 1 ;
if ( F_39 ( V_44 ) )
V_47 = 'r' ;
else
{
V_47 = F_40 ( V_44 ) ;
if ( V_47 == V_56 )
V_47 = 't' ;
else if ( V_47 == V_57 )
V_47 = '3' ;
else if ( V_47 == V_58 )
V_47 = '2' ;
else
V_47 = '*' ;
}
fputc ( V_47 , stdout ) ;
fflush ( stdout ) ;
}
V_42 += F_11 ( V_59 ) ;
printf ( L_32 , V_43 , V_42 , ( ( double ) V_43 / V_42 ) , V_15 ) ;
printf ( L_33 , V_43 , time ( NULL ) - V_45 + V_10 , V_15 / V_43 ) ;
V_32 = 0 ;
V_50:
if ( V_44 != NULL ) F_41 ( V_44 ) ;
if ( V_12 != NULL )
{
F_42 ( V_12 ) ;
V_12 = NULL ;
}
EXIT ( V_32 ) ;
}
static T_1 * F_31 ( T_1 * V_44 )
{
T_3 * V_60 ;
T_1 * V_61 ;
int V_62 , V_40 ;
T_4 V_63 ;
if ( ( V_60 = F_43 ( F_44 () ) ) == NULL )
return ( NULL ) ;
F_45 ( V_60 , V_1 ) ;
if ( V_44 == NULL )
V_61 = F_46 ( V_12 ) ;
else
{
V_61 = V_44 ;
F_47 ( V_61 ) ;
}
F_48 ( V_61 , V_60 , V_60 ) ;
#if 0
if( scon != NULL )
SSL_set_session(serverCon,SSL_get_session(scon));
#endif
for(; ; ) {
V_40 = F_49 ( V_61 ) ;
if ( F_50 ( V_40 ) )
{
F_6 ( V_30 , L_37 ) ;
V_40 = F_38 ( V_61 ) ;
V_62 = V_40 + 1 ;
F_51 ( & V_63 ) ;
F_52 ( V_40 , & V_63 ) ;
F_53 ( V_62 , ( void * ) & V_63 , NULL , NULL , NULL ) ;
continue;
}
break;
}
if( V_40 <= 0 )
{
F_6 ( V_30 , L_38 ) ;
if ( V_25 != V_26 )
F_6 ( V_30 , L_39 ,
F_54 ( V_25 ) ) ;
else
F_28 ( V_30 ) ;
if ( V_44 == NULL )
F_41 ( V_61 ) ;
return NULL ;
}
return V_61 ;
}
