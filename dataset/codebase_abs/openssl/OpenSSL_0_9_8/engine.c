static void F_1 ( void * V_1 )
{
return;
}
static int F_2 ( char * * V_2 , const char * V_3 , int * V_4 , int V_5 )
{
int V_6 = strlen ( V_3 ) ;
if ( * V_2 == NULL )
{
* V_4 = V_5 ;
* V_2 = F_3 ( * V_4 ) ;
if ( * V_2 == NULL )
return 0 ;
* * V_2 = '\0' ;
}
if ( * * V_2 != '\0' )
V_6 += 2 ;
if ( strlen ( * V_2 ) + strlen ( V_3 ) >= ( unsigned int ) * V_4 )
{
* V_4 += V_5 ;
* V_2 = F_4 ( * V_2 , * V_4 ) ;
}
if ( * V_2 == NULL )
return 0 ;
if ( * * V_2 != '\0' )
F_5 ( * V_2 , L_1 , * V_4 ) ;
F_5 ( * V_2 , V_3 , * V_4 ) ;
return 1 ;
}
static int F_6 ( T_1 * V_7 , unsigned int V_8 , const char * V_9 )
{
int V_10 = 0 , V_11 = 0 ;
F_7 ( V_7 , L_2 , V_9 , V_9 ) ;
if( V_8 == 0 )
{
F_7 ( V_7 , L_3 ) ;
return 1 ;
}
if( V_8 & V_12 )
{
F_7 ( V_7 , L_4 ) ;
}
if( V_8 & V_13 )
{
if( V_10 )
{
F_7 ( V_7 , L_5 ) ;
V_11 = 1 ;
}
F_7 ( V_7 , L_6 ) ;
V_10 = 1 ;
}
if( V_8 & V_14 )
{
if( V_10 )
{
F_7 ( V_7 , L_5 ) ;
V_11 = 1 ;
}
F_7 ( V_7 , L_7 ) ;
V_10 = 1 ;
}
if( V_8 & V_15 )
{
if( V_10 )
{
F_7 ( V_7 , L_5 ) ;
V_11 = 1 ;
}
F_7 ( V_7 , L_8 ) ;
V_10 = 1 ;
}
V_8 = V_8 & ~ V_13 &
~ V_14 &
~ V_15 &
~ V_12 ;
if( V_8 )
{
if( V_10 ) F_7 ( V_7 , L_5 ) ;
F_7 ( V_7 , L_9 , V_8 ) ;
}
if( V_11 )
F_7 ( V_7 , L_10 ) ;
F_7 ( V_7 , L_11 ) ;
return 1 ;
}
static int F_8 ( T_2 * V_16 , int V_17 , T_1 * V_7 , const char * V_9 )
{
static const int V_18 = 78 ;
int V_19 ;
int V_20 = 0 ;
char * V_21 = NULL ;
char * V_22 = NULL ;
int V_8 ;
int V_23 = 0 ;
T_3 * V_24 = NULL ;
if( ! F_9 ( V_16 , V_25 , 0 , NULL , NULL ) ||
( ( V_19 = F_9 ( V_16 , V_26 ,
0 , NULL , NULL ) ) <= 0 ) )
{
#if 0
BIO_printf(bio_out, "%s<no control commands>\n", indent);
#endif
return 1 ;
}
V_24 = F_10 () ;
if( ! V_24 )
goto V_11;
do {
int V_27 ;
if( ( V_8 = F_9 ( V_16 , V_28 , V_19 ,
NULL , NULL ) ) < 0 )
goto V_11;
if ( ! ( V_8 & V_12 ) || V_17 >= 4 )
{
if( ( V_27 = F_9 ( V_16 , V_29 , V_19 ,
NULL , NULL ) ) <= 0 )
goto V_11;
if( ( V_21 = F_3 ( V_27 + 1 ) ) == NULL )
goto V_11;
if( F_9 ( V_16 , V_30 , V_19 , V_21 ,
NULL ) <= 0 )
goto V_11;
if( ( V_27 = F_9 ( V_16 , V_31 , V_19 ,
NULL , NULL ) ) < 0 )
goto V_11;
if( V_27 > 0 )
{
if( ( V_22 = F_3 ( V_27 + 1 ) ) == NULL )
goto V_11;
if( F_9 ( V_16 , V_32 , V_19 , V_22 ,
NULL ) <= 0 )
goto V_11;
}
if( V_23 == 0 )
V_23 = F_7 ( V_7 , V_9 ) ;
else
V_23 += F_7 ( V_7 , L_1 ) ;
if( V_17 == 1 )
{
if( ( V_23 > ( int ) strlen ( V_9 ) ) &&
( V_23 + ( int ) strlen ( V_21 ) > V_18 ) )
{
F_7 ( V_7 , L_11 ) ;
V_23 = F_7 ( V_7 , V_9 ) ;
}
V_23 += F_7 ( V_7 , L_12 , V_21 ) ;
}
else
{
F_7 ( V_7 , L_13 , V_21 ,
( V_22 == NULL ) ? L_14 : V_22 ) ;
if( ( V_17 >= 3 ) && ! F_6 ( V_7 , V_8 ,
V_9 ) )
goto V_11;
V_23 = 0 ;
}
}
F_11 ( V_21 ) ; V_21 = NULL ;
if( V_22 ) { F_11 ( V_22 ) ; V_22 = NULL ; }
V_19 = F_9 ( V_16 , V_33 ,
V_19 , NULL , NULL ) ;
} while( V_19 > 0 );
if( V_23 > 0 )
F_7 ( V_7 , L_11 ) ;
V_20 = 1 ;
V_11:
if( V_24 ) F_12 ( V_24 , F_1 ) ;
if( V_21 ) F_11 ( V_21 ) ;
if( V_22 ) F_11 ( V_22 ) ;
return V_20 ;
}
static void F_13 ( T_2 * V_16 , T_3 * V_24 , T_1 * V_7 , const char * V_9 )
{
int V_34 , V_35 , V_19 = F_14 ( V_24 ) ;
if( V_19 < 0 )
{
F_7 ( V_7 , L_15 ) ;
return;
}
for( V_34 = 0 ; V_34 < V_19 ; V_34 ++ )
{
char V_2 [ 256 ] ;
const char * V_36 , * V_37 ;
V_36 = F_15 ( V_24 , V_34 ) ;
V_35 = 1 ;
if( ( V_37 = strstr ( V_36 , L_16 ) ) == NULL )
{
if( ! F_16 ( V_16 , V_36 , NULL , 0 ) )
V_35 = 0 ;
}
else
{
if( ( int ) ( V_37 - V_36 ) > 254 )
{
F_7 ( V_7 , L_17 ) ;
return;
}
memcpy ( V_2 , V_36 , ( int ) ( V_37 - V_36 ) ) ;
V_2 [ V_37 - V_36 ] = '\0' ;
V_37 ++ ;
if( ! F_16 ( V_16 , V_2 , V_37 , 0 ) )
V_35 = 0 ;
}
if( V_35 )
F_7 ( V_7 , L_18 , V_36 ) ;
else
{
F_7 ( V_7 , L_19 , V_36 ) ;
F_17 ( V_7 ) ;
}
}
}
int MAIN ( int V_38 , char * * V_39 )
{
int V_20 = 1 , V_40 ;
const char * * V_41 ;
int V_17 = 0 , V_42 = 0 , V_43 = 0 , V_44 = 0 ;
T_2 * V_16 ;
T_3 * V_45 = F_10 () ;
T_3 * V_46 = F_10 () ;
T_3 * V_47 = F_10 () ;
int V_48 = 1 ;
T_1 * V_7 = NULL ;
const char * V_9 = L_20 ;
F_18 () ;
F_19 () ;
if ( V_49 == NULL )
V_49 = F_20 ( V_50 , V_51 ) ;
if ( ! F_21 ( V_49 , NULL ) )
goto V_52;
V_7 = F_20 ( stdout , V_51 ) ;
#ifdef F_22
{
T_1 * V_53 = F_23 ( F_24 () ) ;
V_7 = F_25 ( V_53 , V_7 ) ;
}
#endif
V_38 -- ;
V_39 ++ ;
while ( V_38 >= 1 )
{
if ( strncmp ( * V_39 , L_21 , 2 ) == 0 )
{
if( strspn ( * V_39 + 1 , L_22 ) < strlen ( * V_39 + 1 ) )
goto V_54;
if( ( V_17 = strlen ( * V_39 + 1 ) ) > 4 )
goto V_54;
}
else if ( strcmp ( * V_39 , L_23 ) == 0 )
V_42 = 1 ;
else if ( strncmp ( * V_39 , L_24 , 2 ) == 0 )
{
V_43 = 1 ;
if( strspn ( * V_39 + 1 , L_25 ) < strlen ( * V_39 + 1 ) )
goto V_54;
if( ( V_44 = strlen ( * V_39 + 1 ) - 1 ) > 1 )
goto V_54;
}
else if ( strcmp ( * V_39 , L_26 ) == 0 )
{
V_38 -- ; V_39 ++ ;
if ( V_38 == 0 )
goto V_54;
F_26 ( V_46 , * V_39 ) ;
}
else if ( strcmp ( * V_39 , L_27 ) == 0 )
{
V_38 -- ; V_39 ++ ;
if ( V_38 == 0 )
goto V_54;
F_26 ( V_47 , * V_39 ) ;
}
else if ( ( strncmp ( * V_39 , L_28 , 2 ) == 0 ) ||
( strcmp ( * V_39 , L_29 ) == 0 ) )
goto V_54;
else
F_26 ( V_45 , * V_39 ) ;
V_38 -- ;
V_39 ++ ;
}
V_48 = 0 ;
V_54:
if ( V_48 )
{
for ( V_41 = V_55 ; ( * V_41 != NULL ) ; V_41 ++ )
F_7 ( V_49 , L_12 , * V_41 ) ;
goto V_52;
}
if ( F_14 ( V_45 ) == 0 )
{
for( V_16 = F_27 () ; V_16 != NULL ; V_16 = F_28 ( V_16 ) )
{
F_26 ( V_45 , ( char * ) F_29 ( V_16 ) ) ;
}
}
for ( V_40 = 0 ; V_40 < F_14 ( V_45 ) ; V_40 ++ )
{
const char * V_56 = F_15 ( V_45 , V_40 ) ;
if ( ( V_16 = F_30 ( V_56 ) ) != NULL )
{
const char * V_21 = F_31 ( V_16 ) ;
F_7 ( V_7 , L_30 , V_56 , V_21 ) ;
F_13 ( V_16 , V_46 , V_7 , V_9 ) ;
if ( strcmp ( F_29 ( V_16 ) , V_56 ) != 0 )
{
F_7 ( V_7 , L_31 ,
F_29 ( V_16 ) , F_31 ( V_16 ) ) ;
}
if ( V_42 )
{
int V_57 = 256 ;
char * V_58 = NULL ;
int V_59 , V_60 ;
const int * V_61 ;
T_4 V_62 ;
T_5 V_63 ;
if ( F_32 ( V_16 ) != NULL
&& ! F_2 ( & V_58 , L_32 ,
& V_57 , 256 ) )
goto V_52;
if ( F_33 ( V_16 ) != NULL
&& ! F_2 ( & V_58 , L_33 ,
& V_57 , 256 ) )
goto V_52;
if ( F_34 ( V_16 ) != NULL
&& ! F_2 ( & V_58 , L_34 ,
& V_57 , 256 ) )
goto V_52;
if ( F_35 ( V_16 ) != NULL
&& ! F_2 ( & V_58 , L_35 ,
& V_57 , 256 ) )
goto V_52;
V_62 = F_36 ( V_16 ) ;
if( ! V_62 ) goto V_64;
V_60 = V_62 ( V_16 , NULL , & V_61 , 0 ) ;
for( V_59 = 0 ; V_59 < V_60 ; ++ V_59 )
if( ! F_2 ( & V_58 ,
F_37 ( V_61 [ V_59 ] ) ,
& V_57 , 256 ) )
goto V_52;
V_64:
V_63 = F_38 ( V_16 ) ;
if( ! V_63 ) goto V_65;
V_60 = V_63 ( V_16 , NULL , & V_61 , 0 ) ;
for( V_59 = 0 ; V_59 < V_60 ; ++ V_59 )
if( ! F_2 ( & V_58 ,
F_37 ( V_61 [ V_59 ] ) ,
& V_57 , 256 ) )
goto V_52;
V_65:
if ( V_58 && ( * V_58 != '\0' ) )
F_7 ( V_7 , L_36 , V_58 ) ;
F_11 ( V_58 ) ;
}
if( V_43 )
{
F_7 ( V_7 , L_12 , V_9 ) ;
if ( F_39 ( V_16 ) )
{
F_7 ( V_7 , L_37 ) ;
F_13 ( V_16 , V_47 , V_7 , V_9 ) ;
F_40 ( V_16 ) ;
}
else
{
F_7 ( V_7 , L_38 ) ;
if( V_44 )
F_41 ( stdout ) ;
F_42 () ;
}
}
if( ( V_17 > 0 ) && ! F_8 ( V_16 , V_17 , V_7 , V_9 ) )
goto V_52;
F_43 ( V_16 ) ;
}
else
F_17 ( V_49 ) ;
}
V_20 = 0 ;
V_52:
F_17 ( V_49 ) ;
F_12 ( V_45 , F_1 ) ;
F_12 ( V_46 , F_1 ) ;
F_12 ( V_47 , F_1 ) ;
if ( V_7 != NULL ) F_44 ( V_7 ) ;
F_45 () ;
F_46 ( V_20 ) ;
}
