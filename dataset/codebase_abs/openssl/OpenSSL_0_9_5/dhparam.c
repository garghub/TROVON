int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 0 ;
T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 = 0 , V_12 = 0 , V_13 = 0 , V_14 = 1 ;
char * V_15 , * V_16 , * V_17 ;
char * V_18 = NULL ;
int V_19 = 0 , V_20 = 0 ;
F_1 () ;
if ( V_21 == NULL )
if ( ( V_21 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_21 , V_22 , V_23 | V_24 ) ;
V_15 = NULL ;
V_16 = NULL ;
V_9 = V_25 ;
V_10 = V_25 ;
V_17 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_11 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_20 = 2 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_20 = 5 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_18 = * ( ++ V_2 ) ;
}
else if ( ( ( sscanf ( * V_2 , L_12 , & V_19 ) == 0 ) || ( V_19 <= 0 ) ) )
goto V_26;
V_2 ++ ;
V_1 -- ;
}
if ( V_5 )
{
V_26:
F_6 ( V_21 , L_13 , V_17 ) ;
F_6 ( V_21 , L_14 ) ;
F_6 ( V_21 , L_15 ) ;
F_6 ( V_21 , L_16 ) ;
F_6 ( V_21 , L_17 ) ;
F_6 ( V_21 , L_18 ) ;
F_6 ( V_21 , L_19 ) ;
F_6 ( V_21 , L_20 ) ;
F_6 ( V_21 , L_21 ) ;
F_6 ( V_21 , L_22 ) ;
F_6 ( V_21 , L_23 ) ;
F_6 ( V_21 , L_24 ) ;
F_6 ( V_21 , L_25 ) ;
F_6 ( V_21 , L_26 ) ;
F_6 ( V_21 , L_27 ) ;
F_6 ( V_21 , L_28 ) ;
goto V_27;
}
F_7 () ;
if( V_20 && ! V_19 ) V_19 = V_28 ;
else if( V_19 && ! V_20 ) V_20 = 2 ;
if( V_19 ) {
if ( ! F_8 ( NULL , V_21 , 1 ) && V_18 == NULL )
{
F_6 ( V_21 , L_29 ) ;
}
if ( V_18 != NULL )
F_6 ( V_21 , L_30 ,
F_9 ( V_18 ) ) ;
F_6 ( V_21 , L_31 , V_19 , V_20 ) ;
F_6 ( V_21 , L_32 ) ;
V_3 = F_10 ( V_19 , V_20 , V_29 , V_21 ) ;
if ( V_3 == NULL ) goto V_27;
F_11 ( NULL , V_21 ) ;
} else {
V_7 = F_2 ( F_3 () ) ;
if ( V_7 == NULL )
{
F_12 ( V_21 ) ;
goto V_27;
}
if ( V_15 == NULL )
F_4 ( V_7 , V_30 , V_23 ) ;
else
{
if ( F_13 ( V_7 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_27;
}
}
if ( V_9 == V_31 )
V_3 = F_14 ( V_7 , NULL ) ;
else if ( V_9 == V_25 )
V_3 = F_15 ( V_7 , NULL , NULL , NULL ) ;
else
{
F_6 ( V_21 , L_33 ) ;
goto V_27;
}
if ( V_3 == NULL )
{
F_6 ( V_21 , L_34 ) ;
F_12 ( V_21 ) ;
goto V_27;
}
}
V_8 = F_2 ( F_3 () ) ;
if ( V_8 == NULL )
{
F_12 ( V_21 ) ;
goto V_27;
}
if ( V_16 == NULL )
F_4 ( V_8 , stdout , V_23 ) ;
else
{
if ( F_16 ( V_8 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_27;
}
}
if ( V_6 )
{
F_17 ( V_8 , V_3 ) ;
}
if ( V_11 )
{
if ( ! F_18 ( V_3 , & V_4 ) )
{
F_12 ( V_21 ) ;
goto V_27;
}
if ( V_4 & V_32 )
printf ( L_35 ) ;
if ( V_4 & V_33 )
printf ( L_36 ) ;
if ( V_4 & V_34 )
printf ( L_37 ) ;
if ( V_4 & V_35 )
printf ( L_38 ) ;
if ( V_4 == 0 )
printf ( L_39 ) ;
}
if ( V_13 )
{
unsigned char * V_36 ;
int V_37 , V_38 , V_39 ;
V_37 = F_19 ( V_3 -> V_40 ) ;
V_39 = F_20 ( V_3 -> V_40 ) ;
V_36 = ( unsigned char * ) Malloc ( V_37 ) ;
if ( V_36 == NULL )
{
perror ( L_40 ) ;
goto V_27;
}
V_38 = F_21 ( V_3 -> V_40 , V_36 ) ;
printf ( L_41 , V_39 ) ;
for ( V_4 = 0 ; V_4 < V_38 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_42 ) ;
printf ( L_43 , V_36 [ V_4 ] ) ;
}
printf ( L_44 ) ;
V_38 = F_21 ( V_3 -> V_20 , V_36 ) ;
printf ( L_45 , V_39 ) ;
for ( V_4 = 0 ; V_4 < V_38 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_42 ) ;
printf ( L_43 , V_36 [ V_4 ] ) ;
}
printf ( L_46 ) ;
printf ( L_47 , V_39 ) ;
printf ( L_48 ) ;
printf ( L_49 ) ;
printf ( L_50 ,
V_39 , V_39 ) ;
printf ( L_51 ,
V_39 , V_39 ) ;
printf ( L_52 ) ;
printf ( L_53 ) ;
printf ( L_54 ) ;
Free ( V_36 ) ;
}
if ( ! V_12 )
{
if ( V_10 == V_31 )
V_4 = F_22 ( V_8 , V_3 ) ;
else if ( V_10 == V_25 )
V_4 = F_23 ( V_8 , V_3 ) ;
else {
F_6 ( V_21 , L_55 ) ;
goto V_27;
}
if ( ! V_4 )
{
F_6 ( V_21 , L_56 ) ;
F_12 ( V_21 ) ;
goto V_27;
}
}
V_14 = 0 ;
V_27:
if ( V_7 != NULL ) F_24 ( V_7 ) ;
if ( V_8 != NULL ) F_24 ( V_8 ) ;
if ( V_3 != NULL ) F_25 ( V_3 ) ;
EXIT ( V_14 ) ;
}
static void T_3 V_29 ( int V_40 , int V_41 , void * V_42 )
{
char V_43 = '*' ;
if ( V_40 == 0 ) V_43 = '.' ;
if ( V_40 == 1 ) V_43 = '+' ;
if ( V_40 == 2 ) V_43 = '*' ;
if ( V_40 == 3 ) V_43 = '\n' ;
F_26 ( ( T_2 * ) V_42 , & V_43 , 1 ) ;
( void ) F_27 ( ( T_2 * ) V_42 ) ;
#ifdef F_28
V_40 = V_41 ;
#endif
}
