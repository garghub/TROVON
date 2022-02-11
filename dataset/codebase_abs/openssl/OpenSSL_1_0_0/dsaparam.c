static void F_1 ( int V_1 )
{
V_2 = 1 ;
}
int MAIN ( int V_3 , char * * V_4 )
{
#ifndef F_2
T_1 * V_5 = NULL ;
#endif
T_2 * V_6 = NULL ;
int V_7 , V_8 = 0 , V_9 = 0 ;
T_3 * V_10 = NULL , * V_11 = NULL ;
int V_12 , V_13 , V_14 = 0 , V_15 = 0 , V_16 = 1 ;
char * V_17 , * V_18 , * V_19 , * V_20 = NULL ;
int V_21 = - 1 , V_22 , V_23 = 0 ;
int V_24 = 0 ;
#ifndef F_2
char * V_25 = NULL ;
#endif
#ifdef F_3
int V_26 = 0 ;
#endif
F_4 () ;
if ( V_27 == NULL )
if ( ( V_27 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_27 , V_28 , V_29 | V_30 ) ;
if ( ! F_8 ( V_27 , NULL ) )
goto V_31;
V_17 = NULL ;
V_18 = NULL ;
V_12 = V_32 ;
V_13 = V_32 ;
V_19 = V_4 [ 0 ] ;
V_3 -- ;
V_4 ++ ;
while ( V_3 >= 1 )
{
if ( strcmp ( * V_4 , L_1 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_12 = F_9 ( * ( ++ V_4 ) ) ;
}
else if ( strcmp ( * V_4 , L_2 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_13 = F_9 ( * ( ++ V_4 ) ) ;
}
else if ( strcmp ( * V_4 , L_3 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_17 = * ( ++ V_4 ) ;
}
else if ( strcmp ( * V_4 , L_4 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_18 = * ( ++ V_4 ) ;
}
#ifndef F_2
else if( strcmp ( * V_4 , L_5 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_25 = * ( ++ V_4 ) ;
}
#endif
#ifdef F_3
else if( strcmp ( * V_4 , L_6 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_26 = atoi ( * ( ++ V_4 ) ) ;
}
#endif
else if ( strcmp ( * V_4 , L_7 ) == 0 )
V_9 = 1 ;
else if ( strcmp ( * V_4 , L_8 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_4 , L_9 ) == 0 )
{
V_23 = 1 ;
V_24 = 1 ;
}
else if ( strcmp ( * V_4 , L_10 ) == 0 )
{
if ( -- V_3 < 1 ) goto V_33;
V_20 = * ( ++ V_4 ) ;
V_24 = 1 ;
}
else if ( strcmp ( * V_4 , L_11 ) == 0 )
V_14 = 1 ;
else if ( sscanf ( * V_4 , L_12 , & V_22 ) == 1 )
{
V_21 = V_22 ;
V_24 = 1 ;
}
else
{
F_10 ( V_27 , L_13 , * V_4 ) ;
V_8 = 1 ;
break;
}
V_3 -- ;
V_4 ++ ;
}
if ( V_8 )
{
V_33:
F_10 ( V_27 , L_14 , V_19 ) ;
F_10 ( V_27 , L_15 ) ;
F_10 ( V_27 , L_16 ) ;
F_10 ( V_27 , L_17 ) ;
F_10 ( V_27 , L_18 ) ;
F_10 ( V_27 , L_19 ) ;
F_10 ( V_27 , L_20 ) ;
F_10 ( V_27 , L_21 ) ;
F_10 ( V_27 , L_22 ) ;
F_10 ( V_27 , L_23 ) ;
F_10 ( V_27 , L_24 ) ;
#ifndef F_2
F_10 ( V_27 , L_25 ) ;
#endif
#ifdef F_3
F_10 ( V_27 , L_26 ) ;
#endif
F_10 ( V_27 , L_27 ) ;
goto V_31;
}
F_11 () ;
V_10 = F_5 ( F_6 () ) ;
V_11 = F_5 ( F_6 () ) ;
if ( ( V_10 == NULL ) || ( V_11 == NULL ) )
{
F_12 ( V_27 ) ;
goto V_31;
}
if ( V_17 == NULL )
F_7 ( V_10 , V_34 , V_29 ) ;
else
{
if ( F_13 ( V_10 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_31;
}
}
if ( V_18 == NULL )
{
F_7 ( V_11 , stdout , V_29 ) ;
#ifdef F_14
{
T_3 * V_35 = F_5 ( F_15 () ) ;
V_11 = F_16 ( V_35 , V_11 ) ;
}
#endif
}
else
{
if ( F_17 ( V_11 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_31;
}
}
#ifndef F_2
V_5 = F_18 ( V_27 , V_25 , 0 ) ;
#endif
if ( V_24 )
{
F_19 ( NULL , V_27 , ( V_20 != NULL ) ) ;
if ( V_20 != NULL )
F_10 ( V_27 , L_28 ,
F_20 ( V_20 ) ) ;
}
if ( V_21 > 0 )
{
T_4 V_36 ;
F_21 ( & V_36 , V_37 , V_27 ) ;
assert ( V_24 ) ;
V_6 = F_22 () ;
if( ! V_6 )
{
F_10 ( V_27 , L_29 ) ;
goto V_31;
}
F_10 ( V_27 , L_30 , V_22 ) ;
F_10 ( V_27 , L_31 ) ;
#ifdef F_3
if( V_26 > 0 )
{
struct V_38 V_39 ;
V_39 . V_40 = F_1 ;
V_39 . V_41 = 0 ;
F_10 ( V_27 , L_32 ,
V_26 ) ;
if( V_38 ( V_42 , & V_39 , NULL ) != 0 )
{
F_10 ( V_27 , L_33 ) ;
goto V_31;
}
F_23 ( V_26 ) ;
}
#endif
if( ! F_24 ( V_6 , V_22 , NULL , 0 , NULL , NULL , & V_36 ) )
{
#ifdef F_3
if( V_2 )
{
F_10 ( V_27 , L_34 ) ;
V_16 = 0 ;
goto V_31;
}
#endif
F_10 ( V_27 , L_35 ) ;
goto V_31;
}
}
else if ( V_12 == V_43 )
V_6 = F_25 ( V_10 , NULL ) ;
else if ( V_12 == V_32 )
V_6 = F_26 ( V_10 , NULL , NULL , NULL ) ;
else
{
F_10 ( V_27 , L_36 ) ;
goto V_31;
}
if ( V_6 == NULL )
{
F_10 ( V_27 , L_37 ) ;
F_12 ( V_27 ) ;
goto V_31;
}
if ( V_9 )
{
F_27 ( V_11 , V_6 ) ;
}
if ( V_15 )
{
unsigned char * V_44 ;
int V_45 , V_46 , V_47 , V_48 , V_49 ;
V_46 = F_28 ( V_6 -> V_50 ) ;
V_47 = F_29 ( V_6 -> V_50 ) ;
V_48 = F_29 ( V_6 -> V_51 ) ;
V_49 = F_29 ( V_6 -> V_52 ) ;
V_44 = ( unsigned char * ) F_30 ( V_46 + 20 ) ;
if ( V_44 == NULL )
{
perror ( L_38 ) ;
goto V_31;
}
V_45 = F_31 ( V_6 -> V_50 , V_44 ) ;
printf ( L_39 , V_47 ) ;
for ( V_7 = 0 ; V_7 < V_45 ; V_7 ++ )
{
if ( ( V_7 % 12 ) == 0 ) printf ( L_40 ) ;
printf ( L_41 , V_44 [ V_7 ] ) ;
}
printf ( L_42 ) ;
V_45 = F_31 ( V_6 -> V_51 , V_44 ) ;
printf ( L_43 , V_47 ) ;
for ( V_7 = 0 ; V_7 < V_45 ; V_7 ++ )
{
if ( ( V_7 % 12 ) == 0 ) printf ( L_40 ) ;
printf ( L_41 , V_44 [ V_7 ] ) ;
}
printf ( L_42 ) ;
V_45 = F_31 ( V_6 -> V_52 , V_44 ) ;
printf ( L_44 , V_47 ) ;
for ( V_7 = 0 ; V_7 < V_45 ; V_7 ++ )
{
if ( ( V_7 % 12 ) == 0 ) printf ( L_40 ) ;
printf ( L_41 , V_44 [ V_7 ] ) ;
}
printf ( L_45 ) ;
printf ( L_46 , V_47 ) ;
printf ( L_47 ) ;
printf ( L_48 ) ;
printf ( L_49 ,
V_47 , V_47 ) ;
printf ( L_50 ,
V_47 , V_47 ) ;
printf ( L_51 ,
V_47 , V_47 ) ;
printf ( L_52 ) ;
printf ( L_53 ) ;
printf ( L_54 ) ;
}
if ( ! V_14 )
{
if ( V_13 == V_43 )
V_7 = F_32 ( V_11 , V_6 ) ;
else if ( V_13 == V_32 )
V_7 = F_33 ( V_11 , V_6 ) ;
else {
F_10 ( V_27 , L_55 ) ;
goto V_31;
}
if ( ! V_7 )
{
F_10 ( V_27 , L_56 ) ;
F_12 ( V_27 ) ;
goto V_31;
}
}
if ( V_23 )
{
T_2 * V_53 ;
assert ( V_24 ) ;
if ( ( V_53 = F_34 ( V_6 ) ) == NULL ) goto V_31;
if ( ! F_35 ( V_53 ) ) goto V_31;
if ( V_13 == V_43 )
V_7 = F_36 ( V_11 , V_53 ) ;
else if ( V_13 == V_32 )
V_7 = F_37 ( V_11 , V_53 , NULL , NULL , 0 , NULL , NULL ) ;
else {
F_10 ( V_27 , L_55 ) ;
goto V_31;
}
F_38 ( V_53 ) ;
}
if ( V_24 )
F_39 ( NULL , V_27 ) ;
V_16 = 0 ;
V_31:
if ( V_10 != NULL ) F_40 ( V_10 ) ;
if ( V_11 != NULL ) F_41 ( V_11 ) ;
if ( V_6 != NULL ) F_38 ( V_6 ) ;
F_42 () ;
F_43 ( V_16 ) ;
}
static int T_5 V_37 ( int V_50 , int V_54 , T_4 * V_36 )
{
char V_55 = '*' ;
if ( V_50 == 0 ) V_55 = '.' ;
if ( V_50 == 1 ) V_55 = '+' ;
if ( V_50 == 2 ) V_55 = '*' ;
if ( V_50 == 3 ) V_55 = '\n' ;
F_44 ( V_36 -> V_56 , & V_55 , 1 ) ;
( void ) F_45 ( V_36 -> V_56 ) ;
#ifdef F_46
V_50 = V_54 ;
#endif
#ifdef F_3
if( V_2 )
return 0 ;
#endif
return 1 ;
}
