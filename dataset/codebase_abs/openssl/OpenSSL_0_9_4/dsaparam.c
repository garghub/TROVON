int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 0 ;
T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 = 0 , V_12 = 0 , V_13 = 1 ;
char * V_14 , * V_15 , * V_16 , * V_17 = NULL ;
int V_18 = - 1 , V_19 , V_20 = 0 ;
char V_21 [ 200 ] , * V_22 = NULL ;
F_1 () ;
if ( V_23 == NULL )
if ( ( V_23 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_23 , V_24 , V_25 | V_26 ) ;
V_14 = NULL ;
V_15 = NULL ;
V_9 = V_27 ;
V_10 = V_27 ;
V_16 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_11 = 1 ;
else if ( sscanf ( * V_2 , L_10 , & V_19 ) == 1 )
{
V_18 = V_19 ;
}
else
{
F_6 ( V_23 , L_11 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
V_28:
F_6 ( V_23 , L_12 , V_16 ) ;
F_6 ( V_23 , L_13 ) ;
F_6 ( V_23 , L_14 ) ;
F_6 ( V_23 , L_15 ) ;
F_6 ( V_23 , L_16 ) ;
F_6 ( V_23 , L_17 ) ;
F_6 ( V_23 , L_18 ) ;
F_6 ( V_23 , L_19 ) ;
F_6 ( V_23 , L_20 ) ;
F_6 ( V_23 , L_21 ) ;
F_6 ( V_23 , L_22 ) ;
goto V_29;
}
F_7 () ;
V_7 = F_2 ( F_3 () ) ;
V_8 = F_2 ( F_3 () ) ;
if ( ( V_7 == NULL ) || ( V_8 == NULL ) )
{
F_8 ( V_23 ) ;
goto V_29;
}
if ( V_14 == NULL )
F_4 ( V_7 , V_30 , V_25 ) ;
else
{
if ( F_9 ( V_7 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_29;
}
}
if ( V_15 == NULL )
F_4 ( V_8 , stdout , V_25 ) ;
else
{
if ( F_10 ( V_8 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_29;
}
}
if ( V_18 > 0 )
{
V_22 = F_11 ( V_21 , 200 ) ;
F_12 ( V_22 , 1024L * 1024L ) ;
F_6 ( V_23 , L_23 , V_19 ) ;
F_6 ( V_23 , L_24 ) ;
V_3 = F_13 ( V_19 , NULL , 0 , NULL , NULL ,
V_31 , ( char * ) V_23 ) ;
}
else if ( V_9 == V_32 )
V_3 = F_14 ( V_7 , NULL ) ;
else if ( V_9 == V_27 )
V_3 = F_15 ( V_7 , NULL , NULL , NULL ) ;
else
{
F_6 ( V_23 , L_25 ) ;
goto V_29;
}
if ( V_3 == NULL )
{
F_6 ( V_23 , L_26 ) ;
F_8 ( V_23 ) ;
goto V_29;
}
if ( V_6 )
{
F_16 ( V_8 , V_3 ) ;
}
if ( V_12 )
{
unsigned char * V_33 ;
int V_34 , V_35 , V_36 , V_37 , V_38 ;
V_35 = F_17 ( V_3 -> V_39 ) ;
V_36 = F_18 ( V_3 -> V_39 ) ;
V_37 = F_18 ( V_3 -> V_40 ) ;
V_38 = F_18 ( V_3 -> V_41 ) ;
V_33 = ( unsigned char * ) Malloc ( V_35 + 20 ) ;
if ( V_33 == NULL )
{
perror ( L_27 ) ;
goto V_29;
}
V_34 = F_19 ( V_3 -> V_39 , V_33 ) ;
printf ( L_28 , V_36 ) ;
for ( V_4 = 0 ; V_4 < V_34 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_29 ) ;
printf ( L_30 , V_33 [ V_4 ] ) ;
}
printf ( L_31 ) ;
V_34 = F_19 ( V_3 -> V_40 , V_33 ) ;
printf ( L_32 , V_36 ) ;
for ( V_4 = 0 ; V_4 < V_34 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_29 ) ;
printf ( L_30 , V_33 [ V_4 ] ) ;
}
printf ( L_31 ) ;
V_34 = F_19 ( V_3 -> V_41 , V_33 ) ;
printf ( L_33 , V_36 ) ;
for ( V_4 = 0 ; V_4 < V_34 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_29 ) ;
printf ( L_30 , V_33 [ V_4 ] ) ;
}
printf ( L_34 ) ;
printf ( L_35 , V_36 ) ;
printf ( L_36 ) ;
printf ( L_37 ) ;
printf ( L_38 ,
V_36 , V_36 ) ;
printf ( L_39 ,
V_36 , V_36 ) ;
printf ( L_40 ,
V_36 , V_36 ) ;
printf ( L_41 ) ;
printf ( L_42 ) ;
printf ( L_43 ) ;
}
if ( ! V_11 )
{
if ( V_10 == V_32 )
V_4 = F_20 ( V_8 , V_3 ) ;
else if ( V_10 == V_27 )
V_4 = F_21 ( V_8 , V_3 ) ;
else {
F_6 ( V_23 , L_44 ) ;
goto V_29;
}
if ( ! V_4 )
{
F_6 ( V_23 , L_45 ) ;
F_8 ( V_23 ) ;
goto V_29;
}
}
if ( V_20 )
{
T_1 * V_42 ;
if ( ( V_42 = F_22 ( V_3 ) ) == NULL ) goto V_29;
if ( ! F_23 ( V_42 ) ) goto V_29;
if ( V_10 == V_32 )
V_4 = F_24 ( V_8 , V_42 ) ;
else if ( V_10 == V_27 )
V_4 = F_25 ( V_8 , V_42 , NULL , NULL , 0 , NULL , NULL ) ;
else {
F_6 ( V_23 , L_44 ) ;
goto V_29;
}
F_26 ( V_42 ) ;
}
V_13 = 0 ;
V_29:
if ( V_7 != NULL ) F_27 ( V_7 ) ;
if ( V_8 != NULL ) F_27 ( V_8 ) ;
if ( V_3 != NULL ) F_26 ( V_3 ) ;
EXIT ( V_13 ) ;
}
static void T_3 V_31 ( int V_39 , int V_43 , char * V_44 )
{
char V_45 = '*' ;
if ( V_39 == 0 ) V_45 = '.' ;
if ( V_39 == 1 ) V_45 = '+' ;
if ( V_39 == 2 ) V_45 = '*' ;
if ( V_39 == 3 ) V_45 = '\n' ;
F_28 ( ( T_2 * ) V_44 , & V_45 , 1 ) ;
( void ) F_29 ( ( T_2 * ) V_44 ) ;
#ifdef F_30
V_39 = V_43 ;
#endif
}
