int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 0 ;
T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 , V_11 = 0 , V_12 = 0 , V_13 = 1 ;
char * V_14 , * V_15 , * V_16 , * V_17 = NULL ;
int V_18 = - 1 , V_19 , V_20 = 0 ;
int V_21 = 0 ;
F_1 () ;
if ( V_22 == NULL )
if ( ( V_22 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_22 , V_23 , V_24 | V_25 ) ;
V_14 = NULL ;
V_15 = NULL ;
V_9 = V_26 ;
V_10 = V_26 ;
V_16 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
V_20 = 1 ;
V_21 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_17 = * ( ++ V_2 ) ;
V_21 = 1 ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_11 = 1 ;
else if ( sscanf ( * V_2 , L_10 , & V_19 ) == 1 )
{
V_18 = V_19 ;
V_21 = 1 ;
}
else
{
F_6 ( V_22 , L_11 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
V_27:
F_6 ( V_22 , L_12 , V_16 ) ;
F_6 ( V_22 , L_13 ) ;
F_6 ( V_22 , L_14 ) ;
F_6 ( V_22 , L_15 ) ;
F_6 ( V_22 , L_16 ) ;
F_6 ( V_22 , L_17 ) ;
F_6 ( V_22 , L_18 ) ;
F_6 ( V_22 , L_19 ) ;
F_6 ( V_22 , L_20 ) ;
F_6 ( V_22 , L_21 ) ;
F_6 ( V_22 , L_22 ) ;
goto V_28;
}
F_7 () ;
V_7 = F_2 ( F_3 () ) ;
V_8 = F_2 ( F_3 () ) ;
if ( ( V_7 == NULL ) || ( V_8 == NULL ) )
{
F_8 ( V_22 ) ;
goto V_28;
}
if ( V_14 == NULL )
F_4 ( V_7 , V_29 , V_24 ) ;
else
{
if ( F_9 ( V_7 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_28;
}
}
if ( V_15 == NULL )
F_4 ( V_8 , stdout , V_24 ) ;
else
{
if ( F_10 ( V_8 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_28;
}
}
if ( V_21 )
{
F_11 ( NULL , V_22 , ( V_17 != NULL ) ) ;
if ( V_17 != NULL )
F_6 ( V_22 , L_23 ,
F_12 ( V_17 ) ) ;
}
if ( V_18 > 0 )
{
assert ( V_21 ) ;
F_6 ( V_22 , L_24 , V_19 ) ;
F_6 ( V_22 , L_25 ) ;
V_3 = F_13 ( V_19 , NULL , 0 , NULL , NULL , V_30 , V_22 ) ;
}
else if ( V_9 == V_31 )
V_3 = F_14 ( V_7 , NULL ) ;
else if ( V_9 == V_26 )
V_3 = F_15 ( V_7 , NULL , NULL , NULL ) ;
else
{
F_6 ( V_22 , L_26 ) ;
goto V_28;
}
if ( V_3 == NULL )
{
F_6 ( V_22 , L_27 ) ;
F_8 ( V_22 ) ;
goto V_28;
}
if ( V_6 )
{
F_16 ( V_8 , V_3 ) ;
}
if ( V_12 )
{
unsigned char * V_32 ;
int V_33 , V_34 , V_35 , V_36 , V_37 ;
V_34 = F_17 ( V_3 -> V_38 ) ;
V_35 = F_18 ( V_3 -> V_38 ) ;
V_36 = F_18 ( V_3 -> V_39 ) ;
V_37 = F_18 ( V_3 -> V_40 ) ;
V_32 = ( unsigned char * ) Malloc ( V_34 + 20 ) ;
if ( V_32 == NULL )
{
perror ( L_28 ) ;
goto V_28;
}
V_33 = F_19 ( V_3 -> V_38 , V_32 ) ;
printf ( L_29 , V_35 ) ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_30 ) ;
printf ( L_31 , V_32 [ V_4 ] ) ;
}
printf ( L_32 ) ;
V_33 = F_19 ( V_3 -> V_39 , V_32 ) ;
printf ( L_33 , V_35 ) ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_30 ) ;
printf ( L_31 , V_32 [ V_4 ] ) ;
}
printf ( L_32 ) ;
V_33 = F_19 ( V_3 -> V_40 , V_32 ) ;
printf ( L_34 , V_35 ) ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ )
{
if ( ( V_4 % 12 ) == 0 ) printf ( L_30 ) ;
printf ( L_31 , V_32 [ V_4 ] ) ;
}
printf ( L_35 ) ;
printf ( L_36 , V_35 ) ;
printf ( L_37 ) ;
printf ( L_38 ) ;
printf ( L_39 ,
V_35 , V_35 ) ;
printf ( L_40 ,
V_35 , V_35 ) ;
printf ( L_41 ,
V_35 , V_35 ) ;
printf ( L_42 ) ;
printf ( L_43 ) ;
printf ( L_44 ) ;
}
if ( ! V_11 )
{
if ( V_10 == V_31 )
V_4 = F_20 ( V_8 , V_3 ) ;
else if ( V_10 == V_26 )
V_4 = F_21 ( V_8 , V_3 ) ;
else {
F_6 ( V_22 , L_45 ) ;
goto V_28;
}
if ( ! V_4 )
{
F_6 ( V_22 , L_46 ) ;
F_8 ( V_22 ) ;
goto V_28;
}
}
if ( V_20 )
{
T_1 * V_41 ;
assert ( V_21 ) ;
if ( ( V_41 = F_22 ( V_3 ) ) == NULL ) goto V_28;
if ( ! F_23 ( V_41 ) ) goto V_28;
if ( V_10 == V_31 )
V_4 = F_24 ( V_8 , V_41 ) ;
else if ( V_10 == V_26 )
V_4 = F_25 ( V_8 , V_41 , NULL , NULL , 0 , NULL , NULL ) ;
else {
F_6 ( V_22 , L_45 ) ;
goto V_28;
}
F_26 ( V_41 ) ;
}
if ( V_21 )
F_27 ( NULL , V_22 ) ;
V_13 = 0 ;
V_28:
if ( V_7 != NULL ) F_28 ( V_7 ) ;
if ( V_8 != NULL ) F_28 ( V_8 ) ;
if ( V_3 != NULL ) F_26 ( V_3 ) ;
EXIT ( V_13 ) ;
}
static void T_3 V_30 ( int V_38 , int V_42 , void * V_43 )
{
char V_44 = '*' ;
if ( V_38 == 0 ) V_44 = '.' ;
if ( V_38 == 1 ) V_44 = '+' ;
if ( V_38 == 2 ) V_44 = '*' ;
if ( V_38 == 3 ) V_44 = '\n' ;
F_29 ( V_43 , & V_44 , 1 ) ;
( void ) F_30 ( V_43 ) ;
#ifdef F_31
V_38 = V_42 ;
#endif
}
