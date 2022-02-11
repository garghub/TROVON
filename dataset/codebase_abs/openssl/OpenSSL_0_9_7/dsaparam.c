int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
int V_5 , V_6 = 0 , V_7 = 0 ;
T_3 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 , V_14 = 1 ;
char * V_15 , * V_16 , * V_17 , * V_18 = NULL ;
int V_19 = - 1 , V_20 , V_21 = 0 ;
int V_22 = 0 ;
char * V_23 = NULL ;
F_1 () ;
if ( V_24 == NULL )
if ( ( V_24 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_24 , V_25 , V_26 | V_27 ) ;
if ( ! F_5 ( V_24 , NULL ) )
goto V_28;
V_15 = NULL ;
V_16 = NULL ;
V_10 = V_29 ;
V_11 = V_29 ;
V_17 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_10 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_11 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_16 = * ( ++ V_2 ) ;
}
else if( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_7 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
V_21 = 1 ;
V_22 = 1 ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_18 = * ( ++ V_2 ) ;
V_22 = 1 ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_12 = 1 ;
else if ( sscanf ( * V_2 , L_11 , & V_20 ) == 1 )
{
V_19 = V_20 ;
V_22 = 1 ;
}
else
{
F_7 ( V_24 , L_12 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_30:
F_7 ( V_24 , L_13 , V_17 ) ;
F_7 ( V_24 , L_14 ) ;
F_7 ( V_24 , L_15 ) ;
F_7 ( V_24 , L_16 ) ;
F_7 ( V_24 , L_17 ) ;
F_7 ( V_24 , L_18 ) ;
F_7 ( V_24 , L_19 ) ;
F_7 ( V_24 , L_20 ) ;
F_7 ( V_24 , L_21 ) ;
F_7 ( V_24 , L_22 ) ;
F_7 ( V_24 , L_23 ) ;
F_7 ( V_24 , L_24 ) ;
F_7 ( V_24 , L_25 ) ;
goto V_28;
}
F_8 () ;
V_8 = F_2 ( F_3 () ) ;
V_9 = F_2 ( F_3 () ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
F_9 ( V_24 ) ;
goto V_28;
}
if ( V_15 == NULL )
F_4 ( V_8 , V_31 , V_26 ) ;
else
{
if ( F_10 ( V_8 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_28;
}
}
if ( V_16 == NULL )
{
F_4 ( V_9 , stdout , V_26 ) ;
#ifdef F_11
{
T_3 * V_32 = F_2 ( F_12 () ) ;
V_9 = F_13 ( V_32 , V_9 ) ;
}
#endif
}
else
{
if ( F_14 ( V_9 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_28;
}
}
V_3 = F_15 ( V_24 , V_23 , 0 ) ;
if ( V_22 )
{
F_16 ( NULL , V_24 , ( V_18 != NULL ) ) ;
if ( V_18 != NULL )
F_7 ( V_24 , L_26 ,
F_17 ( V_18 ) ) ;
}
if ( V_19 > 0 )
{
assert ( V_22 ) ;
F_7 ( V_24 , L_27 , V_20 ) ;
F_7 ( V_24 , L_28 ) ;
V_4 = F_18 ( V_20 , NULL , 0 , NULL , NULL , V_33 , V_24 ) ;
}
else if ( V_10 == V_34 )
V_4 = F_19 ( V_8 , NULL ) ;
else if ( V_10 == V_29 )
V_4 = F_20 ( V_8 , NULL , NULL , NULL ) ;
else
{
F_7 ( V_24 , L_29 ) ;
goto V_28;
}
if ( V_4 == NULL )
{
F_7 ( V_24 , L_30 ) ;
F_9 ( V_24 ) ;
goto V_28;
}
if ( V_7 )
{
F_21 ( V_9 , V_4 ) ;
}
if ( V_13 )
{
unsigned char * V_35 ;
int V_36 , V_37 , V_38 , V_39 , V_40 ;
V_37 = F_22 ( V_4 -> V_41 ) ;
V_38 = F_23 ( V_4 -> V_41 ) ;
V_39 = F_23 ( V_4 -> V_42 ) ;
V_40 = F_23 ( V_4 -> V_43 ) ;
V_35 = ( unsigned char * ) F_24 ( V_37 + 20 ) ;
if ( V_35 == NULL )
{
perror ( L_31 ) ;
goto V_28;
}
V_36 = F_25 ( V_4 -> V_41 , V_35 ) ;
printf ( L_32 , V_38 ) ;
for ( V_5 = 0 ; V_5 < V_36 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_33 ) ;
printf ( L_34 , V_35 [ V_5 ] ) ;
}
printf ( L_35 ) ;
V_36 = F_25 ( V_4 -> V_42 , V_35 ) ;
printf ( L_36 , V_38 ) ;
for ( V_5 = 0 ; V_5 < V_36 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_33 ) ;
printf ( L_34 , V_35 [ V_5 ] ) ;
}
printf ( L_35 ) ;
V_36 = F_25 ( V_4 -> V_43 , V_35 ) ;
printf ( L_37 , V_38 ) ;
for ( V_5 = 0 ; V_5 < V_36 ; V_5 ++ )
{
if ( ( V_5 % 12 ) == 0 ) printf ( L_33 ) ;
printf ( L_34 , V_35 [ V_5 ] ) ;
}
printf ( L_38 ) ;
printf ( L_39 , V_38 ) ;
printf ( L_40 ) ;
printf ( L_41 ) ;
printf ( L_42 ,
V_38 , V_38 ) ;
printf ( L_43 ,
V_38 , V_38 ) ;
printf ( L_44 ,
V_38 , V_38 ) ;
printf ( L_45 ) ;
printf ( L_46 ) ;
printf ( L_47 ) ;
}
if ( ! V_12 )
{
if ( V_11 == V_34 )
V_5 = F_26 ( V_9 , V_4 ) ;
else if ( V_11 == V_29 )
V_5 = F_27 ( V_9 , V_4 ) ;
else {
F_7 ( V_24 , L_48 ) ;
goto V_28;
}
if ( ! V_5 )
{
F_7 ( V_24 , L_49 ) ;
F_9 ( V_24 ) ;
goto V_28;
}
}
if ( V_21 )
{
T_2 * V_44 ;
assert ( V_22 ) ;
if ( ( V_44 = F_28 ( V_4 ) ) == NULL ) goto V_28;
if ( ! F_29 ( V_44 ) ) goto V_28;
if ( V_11 == V_34 )
V_5 = F_30 ( V_9 , V_44 ) ;
else if ( V_11 == V_29 )
V_5 = F_31 ( V_9 , V_44 , NULL , NULL , 0 , NULL , NULL ) ;
else {
F_7 ( V_24 , L_48 ) ;
goto V_28;
}
F_32 ( V_44 ) ;
}
if ( V_22 )
F_33 ( NULL , V_24 ) ;
V_14 = 0 ;
V_28:
if ( V_8 != NULL ) F_34 ( V_8 ) ;
if ( V_9 != NULL ) F_35 ( V_9 ) ;
if ( V_4 != NULL ) F_32 ( V_4 ) ;
F_36 () ;
F_37 ( V_14 ) ;
}
static void T_4 V_33 ( int V_41 , int V_45 , void * V_46 )
{
char V_47 = '*' ;
if ( V_41 == 0 ) V_47 = '.' ;
if ( V_41 == 1 ) V_47 = '+' ;
if ( V_41 == 2 ) V_47 = '*' ;
if ( V_41 == 3 ) V_47 = '\n' ;
F_38 ( V_46 , & V_47 , 1 ) ;
( void ) F_39 ( V_46 ) ;
#ifdef F_40
V_41 = V_45 ;
#endif
}
