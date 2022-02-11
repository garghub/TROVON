int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 0 ;
#ifndef F_1
int V_7 = 0 ;
#endif
T_2 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 , V_15 = 1 ;
char * V_16 , * V_17 , * V_18 ;
char * V_19 = NULL ;
#ifndef F_2
char * V_20 = NULL ;
#endif
int V_21 = 0 , V_22 = 0 ;
F_3 () ;
if ( V_23 == NULL )
if ( ( V_23 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_23 , V_24 , V_25 | V_26 ) ;
if ( ! F_7 ( V_23 , NULL ) )
goto V_27;
V_16 = NULL ;
V_17 = NULL ;
V_10 = V_28 ;
V_11 = V_28 ;
V_18 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_10 = F_8 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_11 = F_8 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_17 = * ( ++ V_2 ) ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_20 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_6 = 1 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_7 = 1 ;
#endif
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_22 = 2 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_22 = 5 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_19 = * ( ++ V_2 ) ;
}
else if ( ( ( sscanf ( * V_2 , L_14 , & V_21 ) == 0 ) || ( V_21 <= 0 ) ) )
goto V_29;
V_2 ++ ;
V_1 -- ;
}
if ( V_5 )
{
V_29:
F_9 ( V_23 , L_15 , V_18 ) ;
F_9 ( V_23 , L_16 ) ;
F_9 ( V_23 , L_17 ) ;
F_9 ( V_23 , L_18 ) ;
F_9 ( V_23 , L_19 ) ;
F_9 ( V_23 , L_20 ) ;
#ifndef F_1
F_9 ( V_23 , L_21 ) ;
#endif
F_9 ( V_23 , L_22 ) ;
F_9 ( V_23 , L_23 ) ;
F_9 ( V_23 , L_24 ) ;
F_9 ( V_23 , L_25 ) ;
F_9 ( V_23 , L_26 ) ;
F_9 ( V_23 , L_27 ) ;
#ifndef F_2
F_9 ( V_23 , L_28 ) ;
#endif
F_9 ( V_23 , L_29 , V_30 , V_30 ) ;
F_9 ( V_23 , L_30 ) ;
F_9 ( V_23 , L_31 ) ;
F_9 ( V_23 , L_32 ) ;
goto V_27;
}
F_10 () ;
#ifndef F_2
F_11 ( V_23 , V_20 , 0 ) ;
#endif
if ( V_22 && ! V_21 )
V_21 = V_31 ;
#ifndef F_1
if ( V_7 )
{
if ( V_22 )
{
F_9 ( V_23 , L_33 ) ;
goto V_27;
}
}
else
#endif
{
if ( V_21 && ! V_22 )
V_22 = 2 ;
}
if( V_21 ) {
T_3 V_32 ;
F_12 ( & V_32 , V_33 , V_23 ) ;
if ( ! F_13 ( NULL , V_23 , 1 ) && V_19 == NULL )
{
F_9 ( V_23 , L_34 ) ;
}
if ( V_19 != NULL )
F_9 ( V_23 , L_35 ,
F_14 ( V_19 ) ) ;
#ifndef F_1
if ( V_7 )
{
T_4 * V_34 = F_15 () ;
F_9 ( V_23 , L_36 , V_21 ) ;
if( ! V_34 || ! F_16 ( V_34 , V_21 ,
NULL , 0 , NULL , NULL , & V_32 ) )
{
if( V_34 ) F_17 ( V_34 ) ;
F_18 ( V_23 ) ;
goto V_27;
}
V_3 = F_19 ( V_34 ) ;
F_17 ( V_34 ) ;
if ( V_3 == NULL )
{
F_18 ( V_23 ) ;
goto V_27;
}
}
else
#endif
{
V_3 = F_20 () ;
F_9 ( V_23 , L_37 , V_21 , V_22 ) ;
F_9 ( V_23 , L_38 ) ;
if( ! V_3 || ! F_21 ( V_3 , V_21 , V_22 , & V_32 ) )
{
if( V_3 ) F_22 ( V_3 ) ;
F_18 ( V_23 ) ;
goto V_27;
}
}
F_23 ( NULL , V_23 ) ;
} else {
V_8 = F_4 ( F_5 () ) ;
if ( V_8 == NULL )
{
F_18 ( V_23 ) ;
goto V_27;
}
if ( V_16 == NULL )
F_6 ( V_8 , V_35 , V_25 ) ;
else
{
if ( F_24 ( V_8 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_27;
}
}
if ( V_10 != V_36 && V_10 != V_28 )
{
F_9 ( V_23 , L_39 ) ;
goto V_27;
}
#ifndef F_1
if ( V_7 )
{
T_4 * V_34 ;
if ( V_10 == V_36 )
V_34 = F_25 ( V_8 , NULL ) ;
else
V_34 = F_26 ( V_8 , NULL , NULL , NULL ) ;
if ( V_34 == NULL )
{
F_9 ( V_23 , L_40 ) ;
F_18 ( V_23 ) ;
goto V_27;
}
V_3 = F_19 ( V_34 ) ;
F_17 ( V_34 ) ;
if ( V_3 == NULL )
{
F_18 ( V_23 ) ;
goto V_27;
}
}
else
#endif
{
if ( V_10 == V_36 )
V_3 = F_27 ( V_8 , NULL ) ;
else
V_3 = F_28 ( V_8 , NULL , NULL , NULL ) ;
if ( V_3 == NULL )
{
F_9 ( V_23 , L_41 ) ;
F_18 ( V_23 ) ;
goto V_27;
}
}
}
V_9 = F_4 ( F_5 () ) ;
if ( V_9 == NULL )
{
F_18 ( V_23 ) ;
goto V_27;
}
if ( V_17 == NULL )
{
F_6 ( V_9 , stdout , V_25 ) ;
#ifdef F_29
{
T_2 * V_37 = F_4 ( F_30 () ) ;
V_9 = F_31 ( V_37 , V_9 ) ;
}
#endif
}
else
{
if ( F_32 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_27;
}
}
if ( V_6 )
{
F_33 ( V_9 , V_3 ) ;
}
if ( V_12 )
{
if ( ! F_34 ( V_3 , & V_4 ) )
{
F_18 ( V_23 ) ;
goto V_27;
}
if ( V_4 & V_38 )
printf ( L_42 ) ;
if ( V_4 & V_39 )
printf ( L_43 ) ;
if ( V_4 & V_40 )
printf ( L_44 ) ;
if ( V_4 & V_41 )
printf ( L_45 ) ;
if ( V_4 == 0 )
printf ( L_46 ) ;
}
if ( V_14 )
{
unsigned char * V_42 ;
int V_43 , V_44 , V_45 ;
V_43 = F_35 ( V_3 -> V_46 ) ;
V_45 = F_36 ( V_3 -> V_46 ) ;
V_42 = ( unsigned char * ) F_37 ( V_43 ) ;
if ( V_42 == NULL )
{
perror ( L_47 ) ;
goto V_27;
}
printf ( L_48
L_49
L_50 ) ;
printf ( L_51 , V_45 ) ;
V_44 = F_38 ( V_3 -> V_46 , V_42 ) ;
printf ( L_52 , V_45 ) ;
for ( V_4 = 0 ; V_4 < V_44 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_53 ) ;
printf ( L_54 , V_42 [ V_4 ] ) ;
}
printf ( L_55 ) ;
V_44 = F_38 ( V_3 -> V_22 , V_42 ) ;
printf ( L_56 , V_45 ) ;
for ( V_4 = 0 ; V_4 < V_44 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_53 ) ;
printf ( L_54 , V_42 [ V_4 ] ) ;
}
printf ( L_55 ) ;
printf ( L_57 ) ;
printf ( L_58 ) ;
printf ( L_59 ,
V_45 , V_45 ) ;
printf ( L_60 ,
V_45 , V_45 ) ;
printf ( L_61 ) ;
printf ( L_62 ) ;
if ( V_3 -> V_47 )
printf ( L_63 , V_3 -> V_47 ) ;
printf ( L_64 ) ;
F_39 ( V_42 ) ;
}
if ( ! V_13 )
{
if ( V_11 == V_36 )
V_4 = F_40 ( V_9 , V_3 ) ;
else if ( V_11 == V_28 )
V_4 = F_41 ( V_9 , V_3 ) ;
else {
F_9 ( V_23 , L_65 ) ;
goto V_27;
}
if ( ! V_4 )
{
F_9 ( V_23 , L_66 ) ;
F_18 ( V_23 ) ;
goto V_27;
}
}
V_15 = 0 ;
V_27:
if ( V_8 != NULL ) F_42 ( V_8 ) ;
if ( V_9 != NULL ) F_43 ( V_9 ) ;
if ( V_3 != NULL ) F_22 ( V_3 ) ;
F_44 () ;
F_45 ( V_15 ) ;
}
static int T_5 V_33 ( int V_46 , int V_48 , T_3 * V_32 )
{
char V_49 = '*' ;
if ( V_46 == 0 ) V_49 = '.' ;
if ( V_46 == 1 ) V_49 = '+' ;
if ( V_46 == 2 ) V_49 = '*' ;
if ( V_46 == 3 ) V_49 = '\n' ;
F_46 ( V_32 -> V_50 , & V_49 , 1 ) ;
( void ) F_47 ( V_32 -> V_50 ) ;
#ifdef F_48
V_46 = V_48 ;
#endif
return 1 ;
}
