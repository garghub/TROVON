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
printf ( L_3 ,
V_2 ) ;
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
if ( strcmp ( * V_22 , L_11 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_1 = * ( ++ V_22 ) ;
}
#if 0
else if (strcmp(*argv, "-host") == 0) {
if (--argc < 1)
goto bad;
host = *(++argv);
} else if (strcmp(*argv, "-port") == 0) {
if (--argc < 1)
goto bad;
port = *(++argv);
}
#endif
else if ( strcmp ( * V_22 , L_12 ) == 0 )
V_17 = 2 ;
else if ( strcmp ( * V_22 , L_13 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_22 , L_14 ) == 0 ) {
V_8 = V_28 | V_29 ;
if ( -- V_21 < 1 )
goto V_27;
V_24 = atoi ( * ( ++ V_22 ) ) ;
F_6 ( V_30 , L_15 , V_24 ) ;
} else if ( strcmp ( * V_22 , L_16 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_3 = * ( ++ V_22 ) ;
} else if ( strcmp ( * V_22 , L_17 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_4 = * ( ++ V_22 ) ;
} else if ( strcmp ( * V_22 , L_18 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_5 = * ( ++ V_22 ) ;
} else if ( strcmp ( * V_22 , L_19 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_6 = * ( ++ V_22 ) ;
} else if ( strcmp ( * V_22 , L_20 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_7 = * ( ++ V_22 ) ;
}
#ifdef F_2
else if ( strcmp ( * V_22 , L_21 ) == 0 ) {
V_18 = 1 ;
}
#endif
else if ( strcmp ( * V_22 , L_22 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_14 = * ( ++ V_22 ) ;
if ( strlen ( V_14 ) > V_31 - 100 ) {
F_6 ( V_30 , L_23 ) ;
V_23 = 1 ;
}
} else if ( strcmp ( * V_22 , L_24 ) == 0 )
V_16 = 1 ;
#ifndef F_7
else if ( strcmp ( * V_22 , L_25 ) == 0 )
V_13 = F_8 () ;
#endif
#ifndef F_9
else if ( strcmp ( * V_22 , L_26 ) == 0 )
V_13 = F_10 () ;
#endif
else if ( strcmp ( * V_22 , L_27 ) == 0 ) {
if ( -- V_21 < 1 )
goto V_27;
V_10 = atoi ( * ( ++ V_22 ) ) ;
} else {
F_6 ( V_30 , L_28 , * V_22 ) ;
V_23 = 1 ;
break;
}
V_21 -- ;
V_22 ++ ;
}
if ( V_17 == 0 )
V_17 = 3 ;
if ( V_23 ) {
V_27:
F_4 () ;
return - 1 ;
}
return 0 ;
}
static double F_11 ( int V_32 )
{
return F_12 ( V_32 , 1 ) ;
}
int MAIN ( int V_21 , char * * V_22 )
{
double V_33 = 0.0 ;
int V_34 = 0 ;
T_1 * V_35 = NULL ;
long V_36 = 0 ;
int V_37 = 1 , V_38 ;
T_2 char V_39 [ 1024 * 8 ] ;
int V_40 ;
F_13 () ;
F_1 () ;
if ( V_30 == NULL )
V_30 = F_14 ( V_41 , V_42 ) ;
V_13 = F_15 () ;
if ( F_5 ( V_21 , V_22 ) < 0 )
goto V_43;
F_16 () ;
if ( ( V_12 = F_17 ( V_13 ) ) == NULL )
return ( 1 ) ;
F_18 ( V_12 , 1 ) ;
if ( V_16 )
F_19 ( V_12 , V_44 ) ;
F_20 ( V_12 , V_7 ) ;
if ( ! F_21 ( V_12 , V_3 , V_4 ) )
goto V_43;
F_22 () ;
if ( ( ! F_23 ( V_12 , V_6 , V_5 ) ) ||
( ! F_24 ( V_12 ) ) ) {
F_25 ( V_30 ) ;
}
if ( V_7 == NULL )
V_7 = getenv ( L_29 ) ;
if ( V_7 == NULL ) {
fprintf ( V_41 , L_30 ) ;
}
if ( ! ( V_17 & 1 ) )
goto V_45;
printf ( L_31 , V_10 ) ;
V_15 = 0 ;
V_36 = ( long ) time ( NULL ) + V_10 ;
F_11 ( V_46 ) ;
for (; ; ) {
if ( V_36 < ( long ) time ( NULL ) )
break;
#ifdef F_26
if ( F_27 ( 0 ) == - 1 )
goto V_43;
if ( V_47 || V_19 )
goto V_43;
#endif
if ( ( V_35 = F_28 ( NULL ) ) == NULL )
goto V_43;
if ( V_14 != NULL ) {
F_29 ( V_39 , sizeof V_39 , L_32 ,
V_14 ) ;
F_30 ( V_35 , V_39 , strlen ( V_39 ) ) ;
while ( ( V_38 = F_31 ( V_35 , V_39 , sizeof( V_39 ) ) ) > 0 )
V_15 += V_38 ;
}
#ifdef F_32
F_33 ( V_35 , V_48 | V_49 ) ;
#else
F_34 ( V_35 ) ;
#endif
F_35 ( F_36 ( V_35 ) ) ;
V_34 += 1 ;
if ( F_37 ( V_35 ) )
V_40 = 'r' ;
else {
V_40 = F_38 ( V_35 ) ;
if ( V_40 == V_50 )
V_40 = 't' ;
else if ( V_40 == V_51 )
V_40 = '3' ;
else if ( V_40 == V_52 )
V_40 = '2' ;
else
V_40 = '*' ;
}
fputc ( V_40 , stdout ) ;
fflush ( stdout ) ;
F_39 ( V_35 ) ;
V_35 = NULL ;
}
V_33 += F_11 ( V_53 ) ;
V_38 = ( int ) ( ( long ) time ( NULL ) - V_36 + V_10 ) ;
printf
( L_33 ,
V_34 , V_33 , ( ( double ) V_34 / V_33 ) , V_15 ) ;
printf
( L_34 ,
V_34 , ( long ) time ( NULL ) - V_36 + V_10 , V_15 / V_34 ) ;
V_45:
if ( ! ( V_17 & 2 ) )
goto V_43;
printf ( L_35 ) ;
if ( ( V_35 = F_28 ( NULL ) ) == NULL ) {
fprintf ( V_41 , L_36 ) ;
goto V_43;
}
if ( V_14 != NULL ) {
F_29 ( V_39 , sizeof V_39 , L_32 , V_14 ) ;
F_30 ( V_35 , V_39 , strlen ( V_39 ) ) ;
while ( F_31 ( V_35 , V_39 , sizeof( V_39 ) ) > 0 ) ;
}
#ifdef F_32
F_33 ( V_35 , V_48 | V_49 ) ;
#else
F_34 ( V_35 ) ;
#endif
F_35 ( F_36 ( V_35 ) ) ;
V_34 = 0 ;
V_33 = 0.0 ;
V_36 = ( long ) time ( NULL ) + V_10 ;
printf ( L_37 ) ;
V_15 = 0 ;
F_11 ( V_46 ) ;
for (; ; ) {
if ( V_36 < ( long ) time ( NULL ) )
break;
#ifdef F_26
if ( F_27 ( 0 ) == - 1 )
goto V_43;
if ( V_47 || V_19 )
goto V_43;
#endif
if ( ( F_28 ( V_35 ) ) == NULL )
goto V_43;
if ( V_14 ) {
F_29 ( V_39 , sizeof V_39 , L_32 ,
V_14 ) ;
F_30 ( V_35 , V_39 , strlen ( V_39 ) ) ;
while ( ( V_38 = F_31 ( V_35 , V_39 , sizeof( V_39 ) ) ) > 0 )
V_15 += V_38 ;
}
#ifdef F_32
F_33 ( V_35 , V_48 | V_49 ) ;
#else
F_34 ( V_35 ) ;
#endif
F_35 ( F_36 ( V_35 ) ) ;
V_34 += 1 ;
if ( F_37 ( V_35 ) )
V_40 = 'r' ;
else {
V_40 = F_38 ( V_35 ) ;
if ( V_40 == V_50 )
V_40 = 't' ;
else if ( V_40 == V_51 )
V_40 = '3' ;
else if ( V_40 == V_52 )
V_40 = '2' ;
else
V_40 = '*' ;
}
fputc ( V_40 , stdout ) ;
fflush ( stdout ) ;
}
V_33 += F_11 ( V_53 ) ;
printf
( L_33 ,
V_34 , V_33 , ( ( double ) V_34 / V_33 ) , V_15 ) ;
printf
( L_34 ,
V_34 , ( long ) time ( NULL ) - V_36 + V_10 , V_15 / V_34 ) ;
V_37 = 0 ;
V_43:
if ( V_35 != NULL )
F_39 ( V_35 ) ;
if ( V_12 != NULL ) {
F_40 ( V_12 ) ;
V_12 = NULL ;
}
F_41 () ;
F_42 ( V_37 ) ;
}
static T_1 * F_28 ( T_1 * V_35 )
{
T_3 * V_54 ;
T_1 * V_55 ;
int V_56 , V_38 ;
T_4 V_57 ;
if ( ( V_54 = F_43 ( F_44 () ) ) == NULL )
return ( NULL ) ;
F_45 ( V_54 , V_1 ) ;
if ( V_35 == NULL )
V_55 = F_46 ( V_12 ) ;
else {
V_55 = V_35 ;
F_47 ( V_55 ) ;
}
F_48 ( V_55 , V_54 , V_54 ) ;
#if 0
if (scon != NULL)
SSL_set_session(serverCon, SSL_get_session(scon));
#endif
for (; ; ) {
V_38 = F_49 ( V_55 ) ;
if ( F_50 ( V_38 ) ) {
F_6 ( V_30 , L_38 ) ;
V_38 = F_36 ( V_55 ) ;
V_56 = V_38 + 1 ;
F_51 ( & V_57 ) ;
F_52 ( V_38 , & V_57 ) ;
F_53 ( V_56 , ( void * ) & V_57 , NULL , NULL , NULL ) ;
continue;
}
break;
}
if ( V_38 <= 0 ) {
F_6 ( V_30 , L_39 ) ;
if ( V_25 != V_26 )
F_6 ( V_30 , L_40 ,
F_54 ( V_25 ) ) ;
else
F_25 ( V_30 ) ;
if ( V_35 == NULL )
F_39 ( V_55 ) ;
return NULL ;
}
return V_55 ;
}
