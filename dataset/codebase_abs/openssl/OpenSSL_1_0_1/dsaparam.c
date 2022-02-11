static void F_1 ( int V_1 )
{
V_2 = 1 ;
}
int MAIN ( int V_3 , char * * V_4 )
{
T_1 * V_5 = NULL ;
int V_6 , V_7 = 0 , V_8 = 0 ;
T_2 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 , V_15 = 1 ;
char * V_16 , * V_17 , * V_18 , * V_19 = NULL ;
int V_20 = - 1 , V_21 , V_22 = 0 ;
int V_23 = 0 ;
#ifndef F_2
char * V_24 = NULL ;
#endif
#ifdef F_3
int V_25 = 0 ;
#endif
F_4 () ;
if ( V_26 == NULL )
if ( ( V_26 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_26 , V_27 , V_28 | V_29 ) ;
if ( ! F_8 ( V_26 , NULL ) )
goto V_30;
V_16 = NULL ;
V_17 = NULL ;
V_11 = V_31 ;
V_12 = V_31 ;
V_18 = V_4 [ 0 ] ;
V_3 -- ;
V_4 ++ ;
while ( V_3 >= 1 )
{
if ( strcmp ( * V_4 , L_1 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_11 = F_9 ( * ( ++ V_4 ) ) ;
}
else if ( strcmp ( * V_4 , L_2 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_12 = F_9 ( * ( ++ V_4 ) ) ;
}
else if ( strcmp ( * V_4 , L_3 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_16 = * ( ++ V_4 ) ;
}
else if ( strcmp ( * V_4 , L_4 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_17 = * ( ++ V_4 ) ;
}
#ifndef F_2
else if( strcmp ( * V_4 , L_5 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_24 = * ( ++ V_4 ) ;
}
#endif
#ifdef F_3
else if( strcmp ( * V_4 , L_6 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_25 = atoi ( * ( ++ V_4 ) ) ;
}
#endif
else if ( strcmp ( * V_4 , L_7 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_4 , L_8 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_4 , L_9 ) == 0 )
{
V_22 = 1 ;
V_23 = 1 ;
}
else if ( strcmp ( * V_4 , L_10 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_32;
V_19 = * ( ++ V_4 ) ;
V_23 = 1 ;
}
else if ( strcmp ( * V_4 , L_11 ) == 0 )
V_13 = 1 ;
else if ( sscanf ( * V_4 , L_12 , & V_21 ) == 1 )
{
V_20 = V_21 ;
V_23 = 1 ;
}
else
{
F_10 ( V_26 , L_13 , * V_4 ) ;
V_7 = 1 ;
break;
}
V_3 -- ;
V_4 ++ ;
}
if ( V_7 )
{
V_32:
F_10 ( V_26 , L_14 , V_18 ) ;
F_10 ( V_26 , L_15 ) ;
F_10 ( V_26 , L_16 ) ;
F_10 ( V_26 , L_17 ) ;
F_10 ( V_26 , L_18 ) ;
F_10 ( V_26 , L_19 ) ;
F_10 ( V_26 , L_20 ) ;
F_10 ( V_26 , L_21 ) ;
F_10 ( V_26 , L_22 ) ;
F_10 ( V_26 , L_23 ) ;
F_10 ( V_26 , L_24 ) ;
#ifndef F_2
F_10 ( V_26 , L_25 ) ;
#endif
#ifdef F_3
F_10 ( V_26 , L_26 ) ;
#endif
F_10 ( V_26 , L_27 ) ;
goto V_30;
}
F_11 () ;
V_9 = F_5 ( F_6 () ) ;
V_10 = F_5 ( F_6 () ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
F_12 ( V_26 ) ;
goto V_30;
}
if ( V_16 == NULL )
F_7 ( V_9 , V_33 , V_28 ) ;
else
{
if ( F_13 ( V_9 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_30;
}
}
if ( V_17 == NULL )
{
F_7 ( V_10 , stdout , V_28 ) ;
#ifdef F_14
{
T_2 * V_34 = F_5 ( F_15 () ) ;
V_10 = F_16 ( V_34 , V_10 ) ;
}
#endif
}
else
{
if ( F_17 ( V_10 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_30;
}
}
#ifndef F_2
F_18 ( V_26 , V_24 , 0 ) ;
#endif
if ( V_23 )
{
F_19 ( NULL , V_26 , ( V_19 != NULL ) ) ;
if ( V_19 != NULL )
F_10 ( V_26 , L_28 ,
F_20 ( V_19 ) ) ;
}
if ( V_20 > 0 )
{
T_3 V_35 ;
F_21 ( & V_35 , V_36 , V_26 ) ;
assert ( V_23 ) ;
V_5 = F_22 () ;
if( ! V_5 )
{
F_10 ( V_26 , L_29 ) ;
goto V_30;
}
F_10 ( V_26 , L_30 , V_21 ) ;
F_10 ( V_26 , L_31 ) ;
#ifdef F_3
if( V_25 > 0 )
{
struct V_37 V_38 ;
V_38 . V_39 = F_1 ;
V_38 . V_40 = 0 ;
F_10 ( V_26 , L_32 ,
V_25 ) ;
if( V_37 ( V_41 , & V_38 , NULL ) != 0 )
{
F_10 ( V_26 , L_33 ) ;
goto V_30;
}
F_23 ( V_25 ) ;
}
#endif
if( ! F_24 ( V_5 , V_21 , NULL , 0 , NULL , NULL , & V_35 ) )
{
#ifdef F_3
if( V_2 )
{
F_10 ( V_26 , L_34 ) ;
V_15 = 0 ;
goto V_30;
}
#endif
F_10 ( V_26 , L_35 ) ;
goto V_30;
}
}
else if ( V_11 == V_42 )
V_5 = F_25 ( V_9 , NULL ) ;
else if ( V_11 == V_31 )
V_5 = F_26 ( V_9 , NULL , NULL , NULL ) ;
else
{
F_10 ( V_26 , L_36 ) ;
goto V_30;
}
if ( V_5 == NULL )
{
F_10 ( V_26 , L_37 ) ;
F_12 ( V_26 ) ;
goto V_30;
}
if ( V_8 )
{
F_27 ( V_10 , V_5 ) ;
}
if ( V_14 )
{
unsigned char * V_43 ;
int V_44 , V_45 , V_46 ;
V_45 = F_28 ( V_5 -> V_47 ) ;
V_46 = F_29 ( V_5 -> V_47 ) ;
V_43 = ( unsigned char * ) F_30 ( V_45 + 20 ) ;
if ( V_43 == NULL )
{
perror ( L_38 ) ;
goto V_30;
}
V_44 = F_31 ( V_5 -> V_47 , V_43 ) ;
printf ( L_39 , V_46 ) ;
for ( V_6 = 0 ; V_6 < V_44 ; V_6 ++ )
{
if ( ( V_6 % 12 ) == 0 ) printf ( L_40 ) ;
printf ( L_41 , V_43 [ V_6 ] ) ;
}
printf ( L_42 ) ;
V_44 = F_31 ( V_5 -> V_48 , V_43 ) ;
printf ( L_43 , V_46 ) ;
for ( V_6 = 0 ; V_6 < V_44 ; V_6 ++ )
{
if ( ( V_6 % 12 ) == 0 ) printf ( L_40 ) ;
printf ( L_41 , V_43 [ V_6 ] ) ;
}
printf ( L_42 ) ;
V_44 = F_31 ( V_5 -> V_49 , V_43 ) ;
printf ( L_44 , V_46 ) ;
for ( V_6 = 0 ; V_6 < V_44 ; V_6 ++ )
{
if ( ( V_6 % 12 ) == 0 ) printf ( L_40 ) ;
printf ( L_41 , V_43 [ V_6 ] ) ;
}
printf ( L_45 ) ;
printf ( L_46 , V_46 ) ;
printf ( L_47 ) ;
printf ( L_48 ) ;
printf ( L_49 ,
V_46 , V_46 ) ;
printf ( L_50 ,
V_46 , V_46 ) ;
printf ( L_51 ,
V_46 , V_46 ) ;
printf ( L_52 ) ;
printf ( L_53 ) ;
printf ( L_54 ) ;
}
if ( ! V_13 )
{
if ( V_12 == V_42 )
V_6 = F_32 ( V_10 , V_5 ) ;
else if ( V_12 == V_31 )
V_6 = F_33 ( V_10 , V_5 ) ;
else {
F_10 ( V_26 , L_55 ) ;
goto V_30;
}
if ( ! V_6 )
{
F_10 ( V_26 , L_56 ) ;
F_12 ( V_26 ) ;
goto V_30;
}
}
if ( V_22 )
{
T_1 * V_50 ;
assert ( V_23 ) ;
if ( ( V_50 = F_34 ( V_5 ) ) == NULL ) goto V_30;
if ( ! F_35 ( V_50 ) ) goto V_30;
if ( V_12 == V_42 )
V_6 = F_36 ( V_10 , V_50 ) ;
else if ( V_12 == V_31 )
V_6 = F_37 ( V_10 , V_50 , NULL , NULL , 0 , NULL , NULL ) ;
else {
F_10 ( V_26 , L_55 ) ;
goto V_30;
}
F_38 ( V_50 ) ;
}
if ( V_23 )
F_39 ( NULL , V_26 ) ;
V_15 = 0 ;
V_30:
if ( V_9 != NULL ) F_40 ( V_9 ) ;
if ( V_10 != NULL ) F_41 ( V_10 ) ;
if ( V_5 != NULL ) F_38 ( V_5 ) ;
F_42 () ;
F_43 ( V_15 ) ;
}
static int T_4 V_36 ( int V_47 , int V_51 , T_3 * V_35 )
{
char V_52 = '*' ;
if ( V_47 == 0 ) V_52 = '.' ;
if ( V_47 == 1 ) V_52 = '+' ;
if ( V_47 == 2 ) V_52 = '*' ;
if ( V_47 == 3 ) V_52 = '\n' ;
F_44 ( V_35 -> V_53 , & V_52 , 1 ) ;
( void ) F_45 ( V_35 -> V_53 ) ;
#ifdef F_46
V_47 = V_51 ;
#endif
#ifdef F_3
if( V_2 )
return 0 ;
#endif
return 1 ;
}
