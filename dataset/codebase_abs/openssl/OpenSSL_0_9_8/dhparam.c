int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
T_2 * V_4 = NULL ;
int V_5 , V_6 = 0 , V_7 = 0 ;
#ifndef F_2
int V_8 = 0 ;
#endif
T_3 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 1 ;
char * V_17 , * V_18 , * V_19 ;
char * V_20 = NULL ;
#ifndef F_1
char * V_21 = NULL ;
#endif
int V_22 = 0 , V_23 = 0 ;
F_3 () ;
if ( V_24 == NULL )
if ( ( V_24 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_24 , V_25 , V_26 | V_27 ) ;
if ( ! F_7 ( V_24 , NULL ) )
goto V_28;
V_17 = NULL ;
V_18 = NULL ;
V_11 = V_29 ;
V_12 = V_29 ;
V_19 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_11 = F_8 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_12 = F_8 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_18 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_21 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_7 = 1 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_8 = 1 ;
#endif
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_23 = 2 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_23 = 5 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_20 = * ( ++ V_2 ) ;
}
else if ( ( ( sscanf ( * V_2 , L_14 , & V_22 ) == 0 ) || ( V_22 <= 0 ) ) )
goto V_30;
V_2 ++ ;
V_1 -- ;
}
if ( V_6 )
{
V_30:
F_9 ( V_24 , L_15 , V_19 ) ;
F_9 ( V_24 , L_16 ) ;
F_9 ( V_24 , L_17 ) ;
F_9 ( V_24 , L_18 ) ;
F_9 ( V_24 , L_19 ) ;
F_9 ( V_24 , L_20 ) ;
#ifndef F_2
F_9 ( V_24 , L_21 ) ;
#endif
F_9 ( V_24 , L_22 ) ;
F_9 ( V_24 , L_23 ) ;
F_9 ( V_24 , L_24 ) ;
F_9 ( V_24 , L_25 ) ;
F_9 ( V_24 , L_26 ) ;
F_9 ( V_24 , L_27 ) ;
#ifndef F_1
F_9 ( V_24 , L_28 ) ;
#endif
F_9 ( V_24 , L_29 , V_31 , V_31 ) ;
F_9 ( V_24 , L_30 ) ;
F_9 ( V_24 , L_31 ) ;
F_9 ( V_24 , L_32 ) ;
goto V_28;
}
F_10 () ;
#ifndef F_1
V_3 = F_11 ( V_24 , V_21 , 0 ) ;
#endif
if ( V_23 && ! V_22 )
V_22 = V_32 ;
#ifndef F_2
if ( V_8 )
{
if ( V_23 )
{
F_9 ( V_24 , L_33 ) ;
goto V_28;
}
}
else
#endif
{
if ( V_22 && ! V_23 )
V_23 = 2 ;
}
if( V_22 ) {
T_4 V_33 ;
F_12 ( & V_33 , V_34 , V_24 ) ;
if ( ! F_13 ( NULL , V_24 , 1 ) && V_20 == NULL )
{
F_9 ( V_24 , L_34 ) ;
}
if ( V_20 != NULL )
F_9 ( V_24 , L_35 ,
F_14 ( V_20 ) ) ;
#ifndef F_2
if ( V_8 )
{
T_5 * V_35 = F_15 () ;
F_9 ( V_24 , L_36 , V_22 ) ;
if( ! V_35 || ! F_16 ( V_35 , V_22 ,
NULL , 0 , NULL , NULL , & V_33 ) )
{
if( V_35 ) F_17 ( V_35 ) ;
F_18 ( V_24 ) ;
goto V_28;
}
V_4 = F_19 ( V_35 ) ;
F_17 ( V_35 ) ;
if ( V_4 == NULL )
{
F_18 ( V_24 ) ;
goto V_28;
}
}
else
#endif
{
V_4 = F_20 () ;
F_9 ( V_24 , L_37 , V_22 , V_23 ) ;
F_9 ( V_24 , L_38 ) ;
if( ! V_4 || ! F_21 ( V_4 , V_22 , V_23 , & V_33 ) )
{
if( V_4 ) F_22 ( V_4 ) ;
F_18 ( V_24 ) ;
goto V_28;
}
}
F_23 ( NULL , V_24 ) ;
} else {
V_9 = F_4 ( F_5 () ) ;
if ( V_9 == NULL )
{
F_18 ( V_24 ) ;
goto V_28;
}
if ( V_17 == NULL )
F_6 ( V_9 , V_36 , V_26 ) ;
else
{
if ( F_24 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_28;
}
}
if ( V_11 != V_37 && V_11 != V_29 )
{
F_9 ( V_24 , L_39 ) ;
goto V_28;
}
#ifndef F_2
if ( V_8 )
{
T_5 * V_35 ;
if ( V_11 == V_37 )
V_35 = F_25 ( V_9 , NULL ) ;
else
V_35 = F_26 ( V_9 , NULL , NULL , NULL ) ;
if ( V_35 == NULL )
{
F_9 ( V_24 , L_40 ) ;
F_18 ( V_24 ) ;
goto V_28;
}
V_4 = F_19 ( V_35 ) ;
F_17 ( V_35 ) ;
if ( V_4 == NULL )
{
F_18 ( V_24 ) ;
goto V_28;
}
}
else
#endif
{
if ( V_11 == V_37 )
V_4 = F_27 ( V_9 , NULL ) ;
else
V_4 = F_28 ( V_9 , NULL , NULL , NULL ) ;
if ( V_4 == NULL )
{
F_9 ( V_24 , L_41 ) ;
F_18 ( V_24 ) ;
goto V_28;
}
}
}
V_10 = F_4 ( F_5 () ) ;
if ( V_10 == NULL )
{
F_18 ( V_24 ) ;
goto V_28;
}
if ( V_18 == NULL )
{
F_6 ( V_10 , stdout , V_26 ) ;
#ifdef F_29
{
T_3 * V_38 = F_4 ( F_30 () ) ;
V_10 = F_31 ( V_38 , V_10 ) ;
}
#endif
}
else
{
if ( F_32 ( V_10 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_28;
}
}
if ( V_7 )
{
F_33 ( V_10 , V_4 ) ;
}
if ( V_13 )
{
if ( ! F_34 ( V_4 , & V_5 ) )
{
F_18 ( V_24 ) ;
goto V_28;
}
if ( V_5 & V_39 )
printf ( L_42 ) ;
if ( V_5 & V_40 )
printf ( L_43 ) ;
if ( V_5 & V_41 )
printf ( L_44 ) ;
if ( V_5 & V_42 )
printf ( L_45 ) ;
if ( V_5 == 0 )
printf ( L_46 ) ;
}
if ( V_15 )
{
unsigned char * V_43 ;
int V_44 , V_45 , V_46 ;
V_44 = F_35 ( V_4 -> V_47 ) ;
V_46 = F_36 ( V_4 -> V_47 ) ;
V_43 = ( unsigned char * ) F_37 ( V_44 ) ;
if ( V_43 == NULL )
{
perror ( L_47 ) ;
goto V_28;
}
printf ( L_48
L_49
L_50 ) ;
printf ( L_51 , V_46 ) ;
V_45 = F_38 ( V_4 -> V_47 , V_43 ) ;
printf ( L_52 , V_46 ) ;
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_53 ) ;
printf ( L_54 , V_43 [ V_5 ] ) ;
}
printf ( L_55 ) ;
V_45 = F_38 ( V_4 -> V_23 , V_43 ) ;
printf ( L_56 , V_46 ) ;
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_53 ) ;
printf ( L_54 , V_43 [ V_5 ] ) ;
}
printf ( L_55 ) ;
printf ( L_57 ) ;
printf ( L_58 ) ;
printf ( L_59 ,
V_46 , V_46 ) ;
printf ( L_60 ,
V_46 , V_46 ) ;
printf ( L_61 ) ;
printf ( L_62 ) ;
if ( V_4 -> V_48 )
printf ( L_63 , V_4 -> V_48 ) ;
printf ( L_64 ) ;
F_39 ( V_43 ) ;
}
if ( ! V_14 )
{
if ( V_12 == V_37 )
V_5 = F_40 ( V_10 , V_4 ) ;
else if ( V_12 == V_29 )
V_5 = F_41 ( V_10 , V_4 ) ;
else {
F_9 ( V_24 , L_65 ) ;
goto V_28;
}
if ( ! V_5 )
{
F_9 ( V_24 , L_66 ) ;
F_18 ( V_24 ) ;
goto V_28;
}
}
V_16 = 0 ;
V_28:
if ( V_9 != NULL ) F_42 ( V_9 ) ;
if ( V_10 != NULL ) F_43 ( V_10 ) ;
if ( V_4 != NULL ) F_22 ( V_4 ) ;
F_44 () ;
F_45 ( V_16 ) ;
}
static int T_6 V_34 ( int V_47 , int V_49 , T_4 * V_33 )
{
char V_50 = '*' ;
if ( V_47 == 0 ) V_50 = '.' ;
if ( V_47 == 1 ) V_50 = '+' ;
if ( V_47 == 2 ) V_50 = '*' ;
if ( V_47 == 3 ) V_50 = '\n' ;
F_46 ( V_33 -> V_51 , & V_50 , 1 ) ;
( void ) F_47 ( V_33 -> V_51 ) ;
#ifdef F_48
V_47 = V_49 ;
#endif
return 1 ;
}
