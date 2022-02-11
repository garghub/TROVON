int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
int V_5 , V_6 = 0 , V_7 = 0 ;
#ifndef F_1
int V_8 = 0 ;
#endif
T_3 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 1 ;
char * V_17 , * V_18 , * V_19 ;
char * V_20 = NULL , * V_21 = NULL ;
int V_22 = 0 , V_23 = 0 ;
F_2 () ;
if ( V_24 == NULL )
if ( ( V_24 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_24 , V_25 , V_26 | V_27 ) ;
if ( ! F_6 ( V_24 , NULL ) )
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
V_11 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_12 = F_7 ( * ( ++ V_2 ) ) ;
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
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_7 = 1 ;
#ifndef F_1
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
F_8 ( V_24 , L_15 , V_19 ) ;
F_8 ( V_24 , L_16 ) ;
F_8 ( V_24 , L_17 ) ;
F_8 ( V_24 , L_18 ) ;
F_8 ( V_24 , L_19 ) ;
F_8 ( V_24 , L_20 ) ;
#ifndef F_1
F_8 ( V_24 , L_21 ) ;
#endif
F_8 ( V_24 , L_22 ) ;
F_8 ( V_24 , L_23 ) ;
F_8 ( V_24 , L_24 ) ;
F_8 ( V_24 , L_25 ) ;
F_8 ( V_24 , L_26 ) ;
F_8 ( V_24 , L_27 ) ;
F_8 ( V_24 , L_28 ) ;
F_8 ( V_24 , L_29 , V_31 , V_31 ) ;
F_8 ( V_24 , L_30 ) ;
F_8 ( V_24 , L_31 ) ;
F_8 ( V_24 , L_32 ) ;
goto V_28;
}
F_9 () ;
V_3 = F_10 ( V_24 , V_21 , 0 ) ;
if ( V_23 && ! V_22 )
V_22 = V_32 ;
#ifndef F_1
if ( V_8 )
{
if ( V_23 )
{
F_8 ( V_24 , L_33 ) ;
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
if ( ! F_11 ( NULL , V_24 , 1 ) && V_20 == NULL )
{
F_8 ( V_24 , L_34 ) ;
}
if ( V_20 != NULL )
F_8 ( V_24 , L_35 ,
F_12 ( V_20 ) ) ;
#ifndef F_1
if ( V_8 )
{
T_4 * V_33 ;
F_8 ( V_24 , L_36 , V_22 ) ;
V_33 = F_13 ( V_22 , NULL , 0 , NULL , NULL , V_34 , V_24 ) ;
if ( V_33 == NULL )
{
F_14 ( V_24 ) ;
goto V_28;
}
V_4 = F_15 ( V_33 ) ;
F_16 ( V_33 ) ;
if ( V_4 == NULL )
{
F_14 ( V_24 ) ;
goto V_28;
}
}
else
#endif
{
F_8 ( V_24 , L_37 , V_22 , V_23 ) ;
F_8 ( V_24 , L_38 ) ;
V_4 = F_17 ( V_22 , V_23 , V_34 , V_24 ) ;
if ( V_4 == NULL )
{
F_14 ( V_24 ) ;
goto V_28;
}
}
F_18 ( NULL , V_24 ) ;
} else {
V_9 = F_3 ( F_4 () ) ;
if ( V_9 == NULL )
{
F_14 ( V_24 ) ;
goto V_28;
}
if ( V_17 == NULL )
F_5 ( V_9 , V_35 , V_26 ) ;
else
{
if ( F_19 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_28;
}
}
if ( V_11 != V_36 && V_11 != V_29 )
{
F_8 ( V_24 , L_39 ) ;
goto V_28;
}
#ifndef F_1
if ( V_8 )
{
T_4 * V_33 ;
if ( V_11 == V_36 )
V_33 = F_20 ( V_9 , NULL ) ;
else
V_33 = F_21 ( V_9 , NULL , NULL , NULL ) ;
if ( V_33 == NULL )
{
F_8 ( V_24 , L_40 ) ;
F_14 ( V_24 ) ;
goto V_28;
}
V_4 = F_15 ( V_33 ) ;
F_16 ( V_33 ) ;
if ( V_4 == NULL )
{
F_14 ( V_24 ) ;
goto V_28;
}
}
else
#endif
{
if ( V_11 == V_36 )
V_4 = F_22 ( V_9 , NULL ) ;
else
V_4 = F_23 ( V_9 , NULL , NULL , NULL ) ;
if ( V_4 == NULL )
{
F_8 ( V_24 , L_41 ) ;
F_14 ( V_24 ) ;
goto V_28;
}
}
}
V_10 = F_3 ( F_4 () ) ;
if ( V_10 == NULL )
{
F_14 ( V_24 ) ;
goto V_28;
}
if ( V_18 == NULL )
{
F_5 ( V_10 , stdout , V_26 ) ;
#ifdef F_24
{
T_3 * V_37 = F_3 ( F_25 () ) ;
V_10 = F_26 ( V_37 , V_10 ) ;
}
#endif
}
else
{
if ( F_27 ( V_10 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_28;
}
}
if ( V_7 )
{
F_28 ( V_10 , V_4 ) ;
}
if ( V_13 )
{
if ( ! F_29 ( V_4 , & V_5 ) )
{
F_14 ( V_24 ) ;
goto V_28;
}
if ( V_5 & V_38 )
printf ( L_42 ) ;
if ( V_5 & V_39 )
printf ( L_43 ) ;
if ( V_5 & V_40 )
printf ( L_44 ) ;
if ( V_5 & V_41 )
printf ( L_45 ) ;
if ( V_5 == 0 )
printf ( L_46 ) ;
}
if ( V_15 )
{
unsigned char * V_42 ;
int V_43 , V_44 , V_45 ;
V_43 = F_30 ( V_4 -> V_46 ) ;
V_45 = F_31 ( V_4 -> V_46 ) ;
V_42 = ( unsigned char * ) F_32 ( V_43 ) ;
if ( V_42 == NULL )
{
perror ( L_47 ) ;
goto V_28;
}
printf ( L_48
L_49
L_50 ) ;
printf ( L_51 , V_45 ) ;
V_44 = F_33 ( V_4 -> V_46 , V_42 ) ;
printf ( L_52 , V_45 ) ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_53 ) ;
printf ( L_54 , V_42 [ V_5 ] ) ;
}
printf ( L_55 ) ;
V_44 = F_33 ( V_4 -> V_23 , V_42 ) ;
printf ( L_56 , V_45 ) ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_53 ) ;
printf ( L_54 , V_42 [ V_5 ] ) ;
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
if ( V_4 -> V_47 )
printf ( L_63 , V_4 -> V_47 ) ;
printf ( L_64 ) ;
F_34 ( V_42 ) ;
}
if ( ! V_14 )
{
if ( V_12 == V_36 )
V_5 = F_35 ( V_10 , V_4 ) ;
else if ( V_12 == V_29 )
V_5 = F_36 ( V_10 , V_4 ) ;
else {
F_8 ( V_24 , L_65 ) ;
goto V_28;
}
if ( ! V_5 )
{
F_8 ( V_24 , L_66 ) ;
F_14 ( V_24 ) ;
goto V_28;
}
}
V_16 = 0 ;
V_28:
if ( V_9 != NULL ) F_37 ( V_9 ) ;
if ( V_10 != NULL ) F_38 ( V_10 ) ;
if ( V_4 != NULL ) F_39 ( V_4 ) ;
F_40 () ;
F_41 ( V_16 ) ;
}
static void T_5 V_34 ( int V_46 , int V_48 , void * V_49 )
{
char V_50 = '*' ;
if ( V_46 == 0 ) V_50 = '.' ;
if ( V_46 == 1 ) V_50 = '+' ;
if ( V_46 == 2 ) V_50 = '*' ;
if ( V_46 == 3 ) V_50 = '\n' ;
F_42 ( ( T_3 * ) V_49 , & V_50 , 1 ) ;
( void ) F_43 ( ( T_3 * ) V_49 ) ;
#ifdef F_44
V_46 = V_48 ;
#endif
}
