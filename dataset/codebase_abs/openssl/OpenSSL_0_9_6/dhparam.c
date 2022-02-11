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
int V_20 = 0 , V_21 = 0 ;
F_2 () ;
if ( V_22 == NULL )
if ( ( V_22 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_22 , V_23 , V_24 | V_25 ) ;
V_16 = NULL ;
V_17 = NULL ;
V_10 = V_26 ;
V_11 = V_26 ;
V_18 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_10 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_11 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_6 = 1 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_7 = 1 ;
#endif
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_21 = 2 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_21 = 5 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_19 = * ( ++ V_2 ) ;
}
else if ( ( ( sscanf ( * V_2 , L_13 , & V_20 ) == 0 ) || ( V_20 <= 0 ) ) )
goto V_27;
V_2 ++ ;
V_1 -- ;
}
if ( V_5 )
{
V_27:
F_7 ( V_22 , L_14 , V_18 ) ;
F_7 ( V_22 , L_15 ) ;
F_7 ( V_22 , L_16 ) ;
F_7 ( V_22 , L_17 ) ;
F_7 ( V_22 , L_18 ) ;
F_7 ( V_22 , L_19 ) ;
#ifndef F_1
F_7 ( V_22 , L_20 ) ;
#endif
F_7 ( V_22 , L_21 ) ;
F_7 ( V_22 , L_22 ) ;
F_7 ( V_22 , L_23 ) ;
F_7 ( V_22 , L_24 ) ;
F_7 ( V_22 , L_25 ) ;
F_7 ( V_22 , L_26 ) ;
F_7 ( V_22 , L_27 , V_28 , V_28 ) ;
F_7 ( V_22 , L_28 ) ;
F_7 ( V_22 , L_29 ) ;
F_7 ( V_22 , L_30 ) ;
goto V_29;
}
F_8 () ;
if ( V_21 && ! V_20 )
V_20 = V_30 ;
#ifndef F_1
if ( V_7 )
{
if ( V_21 )
{
F_7 ( V_22 , L_31 ) ;
goto V_29;
}
}
else
#endif
{
if ( V_20 && ! V_21 )
V_21 = 2 ;
}
if( V_20 ) {
if ( ! F_9 ( NULL , V_22 , 1 ) && V_19 == NULL )
{
F_7 ( V_22 , L_32 ) ;
}
if ( V_19 != NULL )
F_7 ( V_22 , L_33 ,
F_10 ( V_19 ) ) ;
#ifndef F_1
if ( V_7 )
{
T_3 * V_31 ;
F_7 ( V_22 , L_34 , V_20 ) ;
V_31 = F_11 ( V_20 , NULL , 0 , NULL , NULL , V_32 , V_22 ) ;
if ( V_31 == NULL )
{
F_12 ( V_22 ) ;
goto V_29;
}
V_3 = F_13 ( V_31 ) ;
F_14 ( V_31 ) ;
if ( V_3 == NULL )
{
F_12 ( V_22 ) ;
goto V_29;
}
}
else
#endif
{
F_7 ( V_22 , L_35 , V_20 , V_21 ) ;
F_7 ( V_22 , L_36 ) ;
V_3 = F_15 ( V_20 , V_21 , V_32 , V_22 ) ;
if ( V_3 == NULL )
{
F_12 ( V_22 ) ;
goto V_29;
}
}
F_16 ( NULL , V_22 ) ;
} else {
V_8 = F_3 ( F_4 () ) ;
if ( V_8 == NULL )
{
F_12 ( V_22 ) ;
goto V_29;
}
if ( V_16 == NULL )
F_5 ( V_8 , V_33 , V_24 ) ;
else
{
if ( F_17 ( V_8 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_29;
}
}
if ( V_10 != V_34 && V_10 != V_26 )
{
F_7 ( V_22 , L_37 ) ;
goto V_29;
}
#ifndef F_1
if ( V_7 )
{
T_3 * V_31 ;
if ( V_10 == V_34 )
V_31 = F_18 ( V_8 , NULL ) ;
else
V_31 = F_19 ( V_8 , NULL , NULL , NULL ) ;
if ( V_31 == NULL )
{
F_7 ( V_22 , L_38 ) ;
F_12 ( V_22 ) ;
goto V_29;
}
V_3 = F_13 ( V_31 ) ;
F_14 ( V_31 ) ;
if ( V_3 == NULL )
{
F_12 ( V_22 ) ;
goto V_29;
}
}
else
#endif
{
if ( V_10 == V_34 )
V_3 = F_20 ( V_8 , NULL ) ;
else
V_3 = F_21 ( V_8 , NULL , NULL , NULL ) ;
if ( V_3 == NULL )
{
F_7 ( V_22 , L_39 ) ;
F_12 ( V_22 ) ;
goto V_29;
}
}
}
V_9 = F_3 ( F_4 () ) ;
if ( V_9 == NULL )
{
F_12 ( V_22 ) ;
goto V_29;
}
if ( V_17 == NULL )
{
F_5 ( V_9 , stdout , V_24 ) ;
#ifdef F_22
{
T_2 * V_35 = F_3 ( F_23 () ) ;
V_9 = F_24 ( V_35 , V_9 ) ;
}
#endif
}
else
{
if ( F_25 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_29;
}
}
if ( V_6 )
{
F_26 ( V_9 , V_3 ) ;
}
if ( V_12 )
{
if ( ! F_27 ( V_3 , & V_4 ) )
{
F_12 ( V_22 ) ;
goto V_29;
}
if ( V_4 & V_36 )
printf ( L_40 ) ;
if ( V_4 & V_37 )
printf ( L_41 ) ;
if ( V_4 & V_38 )
printf ( L_42 ) ;
if ( V_4 & V_39 )
printf ( L_43 ) ;
if ( V_4 == 0 )
printf ( L_44 ) ;
}
if ( V_14 )
{
unsigned char * V_40 ;
int V_41 , V_42 , V_43 ;
V_41 = F_28 ( V_3 -> V_44 ) ;
V_43 = F_29 ( V_3 -> V_44 ) ;
V_40 = ( unsigned char * ) F_30 ( V_41 ) ;
if ( V_40 == NULL )
{
perror ( L_45 ) ;
goto V_29;
}
printf ( L_46
L_47
L_48 ) ;
printf ( L_49 , V_43 ) ;
V_42 = F_31 ( V_3 -> V_44 , V_40 ) ;
printf ( L_50 , V_43 ) ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_51 ) ;
printf ( L_52 , V_40 [ V_4 ] ) ;
}
printf ( L_53 ) ;
V_42 = F_31 ( V_3 -> V_21 , V_40 ) ;
printf ( L_54 , V_43 ) ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_51 ) ;
printf ( L_52 , V_40 [ V_4 ] ) ;
}
printf ( L_53 ) ;
printf ( L_55 ) ;
printf ( L_56 ) ;
printf ( L_57 ,
V_43 , V_43 ) ;
printf ( L_58 ,
V_43 , V_43 ) ;
printf ( L_59 ) ;
printf ( L_60 ) ;
if ( V_3 -> V_45 )
printf ( L_61 , V_3 -> V_45 ) ;
printf ( L_62 ) ;
F_32 ( V_40 ) ;
}
if ( ! V_13 )
{
if ( V_11 == V_34 )
V_4 = F_33 ( V_9 , V_3 ) ;
else if ( V_11 == V_26 )
V_4 = F_34 ( V_9 , V_3 ) ;
else {
F_7 ( V_22 , L_63 ) ;
goto V_29;
}
if ( ! V_4 )
{
F_7 ( V_22 , L_64 ) ;
F_12 ( V_22 ) ;
goto V_29;
}
}
V_15 = 0 ;
V_29:
if ( V_8 != NULL ) F_35 ( V_8 ) ;
if ( V_9 != NULL ) F_36 ( V_9 ) ;
if ( V_3 != NULL ) F_37 ( V_3 ) ;
EXIT ( V_15 ) ;
}
static void T_4 V_32 ( int V_44 , int V_46 , void * V_47 )
{
char V_48 = '*' ;
if ( V_44 == 0 ) V_48 = '.' ;
if ( V_44 == 1 ) V_48 = '+' ;
if ( V_44 == 2 ) V_48 = '*' ;
if ( V_44 == 3 ) V_48 = '\n' ;
F_38 ( ( T_2 * ) V_47 , & V_48 , 1 ) ;
( void ) F_39 ( ( T_2 * ) V_47 ) ;
#ifdef F_40
V_44 = V_46 ;
#endif
}
