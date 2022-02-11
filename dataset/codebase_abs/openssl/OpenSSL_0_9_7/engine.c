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
strcat ( * V_2 , L_1 ) ;
strcat ( * V_2 , V_3 ) ;
return 1 ;
}
static int F_5 ( T_1 * V_7 , unsigned int V_8 , const char * V_9 )
{
int V_10 = 0 , V_11 = 0 ;
F_6 ( V_7 , L_2 , V_9 , V_9 ) ;
if( V_8 == 0 )
{
F_6 ( V_7 , L_3 ) ;
return 1 ;
}
if( V_8 & V_12 )
{
F_6 ( V_7 , L_4 ) ;
}
if( V_8 & V_13 )
{
if( V_10 )
{
F_6 ( V_7 , L_5 ) ;
V_11 = 1 ;
}
F_6 ( V_7 , L_6 ) ;
V_10 = 1 ;
}
if( V_8 & V_14 )
{
if( V_10 )
{
F_6 ( V_7 , L_5 ) ;
V_11 = 1 ;
}
F_6 ( V_7 , L_7 ) ;
V_10 = 1 ;
}
if( V_8 & V_15 )
{
if( V_10 )
{
F_6 ( V_7 , L_5 ) ;
V_11 = 1 ;
}
F_6 ( V_7 , L_8 ) ;
V_10 = 1 ;
}
V_8 = V_8 & ~ V_13 &
~ V_14 &
~ V_15 &
~ V_12 ;
if( V_8 )
{
if( V_10 ) F_6 ( V_7 , L_5 ) ;
F_6 ( V_7 , L_9 , V_8 ) ;
}
if( V_11 )
F_6 ( V_7 , L_10 ) ;
F_6 ( V_7 , L_11 ) ;
return 1 ;
}
static int F_7 ( T_2 * V_16 , int V_17 , T_1 * V_7 , const char * V_9 )
{
static const int V_18 = 78 ;
int V_19 ;
int V_20 = 0 ;
char * V_21 = NULL ;
char * V_22 = NULL ;
int V_8 ;
int V_23 = 0 ;
T_3 * V_24 = NULL ;
if( ! F_8 ( V_16 , V_25 , 0 , NULL , NULL ) ||
( ( V_19 = F_8 ( V_16 , V_26 ,
0 , NULL , NULL ) ) <= 0 ) )
{
#if 0
BIO_printf(bio_out, "%s<no control commands>\n", indent);
#endif
return 1 ;
}
V_24 = F_9 () ;
if( ! V_24 )
goto V_11;
do {
int V_27 ;
if( ( V_8 = F_8 ( V_16 , V_28 , V_19 ,
NULL , NULL ) ) < 0 )
goto V_11;
if ( ! ( V_8 & V_12 ) || V_17 >= 4 )
{
if( ( V_27 = F_8 ( V_16 , V_29 , V_19 ,
NULL , NULL ) ) <= 0 )
goto V_11;
if( ( V_21 = F_3 ( V_27 + 1 ) ) == NULL )
goto V_11;
if( F_8 ( V_16 , V_30 , V_19 , V_21 ,
NULL ) <= 0 )
goto V_11;
if( ( V_27 = F_8 ( V_16 , V_31 , V_19 ,
NULL , NULL ) ) < 0 )
goto V_11;
if( V_27 > 0 )
{
if( ( V_22 = F_3 ( V_27 + 1 ) ) == NULL )
goto V_11;
if( F_8 ( V_16 , V_32 , V_19 , V_22 ,
NULL ) <= 0 )
goto V_11;
}
if( V_23 == 0 )
V_23 = F_6 ( V_7 , V_9 ) ;
else
V_23 += F_6 ( V_7 , L_1 ) ;
if( V_17 == 1 )
{
if( ( V_23 > ( int ) strlen ( V_9 ) ) &&
( V_23 + ( int ) strlen ( V_21 ) > V_18 ) )
{
F_6 ( V_7 , L_11 ) ;
V_23 = F_6 ( V_7 , V_9 ) ;
}
V_23 += F_6 ( V_7 , L_12 , V_21 ) ;
}
else
{
F_6 ( V_7 , L_13 , V_21 ,
( V_22 == NULL ) ? L_14 : V_22 ) ;
if( ( V_17 >= 3 ) && ! F_5 ( V_7 , V_8 ,
V_9 ) )
goto V_11;
V_23 = 0 ;
}
}
F_10 ( V_21 ) ; V_21 = NULL ;
if( V_22 ) { F_10 ( V_22 ) ; V_22 = NULL ; }
V_19 = F_8 ( V_16 , V_33 ,
V_19 , NULL , NULL ) ;
} while( V_19 > 0 );
if( V_23 > 0 )
F_6 ( V_7 , L_11 ) ;
V_20 = 1 ;
V_11:
if( V_24 ) F_11 ( V_24 , F_1 ) ;
if( V_21 ) F_10 ( V_21 ) ;
if( V_22 ) F_10 ( V_22 ) ;
return V_20 ;
}
static void F_12 ( T_2 * V_16 , T_3 * V_24 , T_1 * V_7 , const char * V_9 )
{
int V_34 , V_35 , V_19 = F_13 ( V_24 ) ;
if( V_19 < 0 )
{
F_6 ( V_7 , L_15 ) ;
return;
}
for( V_34 = 0 ; V_34 < V_19 ; V_34 ++ )
{
char V_2 [ 256 ] ;
const char * V_36 , * V_37 ;
V_36 = F_14 ( V_24 , V_34 ) ;
V_35 = 1 ;
if( ( V_37 = strstr ( V_36 , L_16 ) ) == NULL )
{
if( ! F_15 ( V_16 , V_36 , NULL , 0 ) )
V_35 = 0 ;
}
else
{
if( ( int ) ( V_37 - V_36 ) > 254 )
{
F_6 ( V_7 , L_17 ) ;
return;
}
memcpy ( V_2 , V_36 , ( int ) ( V_37 - V_36 ) ) ;
V_2 [ V_37 - V_36 ] = '\0' ;
V_37 ++ ;
if( ! F_15 ( V_16 , V_2 , V_37 , 0 ) )
V_35 = 0 ;
}
if( V_35 )
F_6 ( V_7 , L_18 , V_36 ) ;
else
{
F_6 ( V_7 , L_19 , V_36 ) ;
F_16 ( V_7 ) ;
}
}
}
int MAIN ( int V_38 , char * * V_39 )
{
int V_20 = 1 , V_40 ;
char * * V_41 ;
int V_17 = 0 , V_42 = 0 , V_43 = 0 ;
T_2 * V_16 ;
T_3 * V_44 = F_9 () ;
T_3 * V_45 = F_9 () ;
T_3 * V_46 = F_9 () ;
int V_47 = 1 ;
T_1 * V_7 = NULL ;
const char * V_9 = L_20 ;
F_17 () ;
F_18 () ;
if ( V_48 == NULL )
V_48 = F_19 ( V_49 , V_50 ) ;
if ( ! F_20 ( V_48 , NULL ) )
goto V_51;
V_7 = F_19 ( stdout , V_50 ) ;
#ifdef F_21
{
T_1 * V_52 = F_22 ( F_23 () ) ;
V_7 = F_24 ( V_52 , V_7 ) ;
}
#endif
V_38 -- ;
V_39 ++ ;
while ( V_38 >= 1 )
{
if ( strncmp ( * V_39 , L_21 , 2 ) == 0 )
{
if( strspn ( * V_39 + 1 , L_22 ) < strlen ( * V_39 + 1 ) )
goto V_53;
if( ( V_17 = strlen ( * V_39 + 1 ) ) > 4 )
goto V_53;
}
else if ( strcmp ( * V_39 , L_23 ) == 0 )
V_42 = 1 ;
else if ( strcmp ( * V_39 , L_24 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( * V_39 , L_25 ) == 0 )
{
V_38 -- ; V_39 ++ ;
F_25 ( V_45 , * V_39 ) ;
}
else if ( strcmp ( * V_39 , L_26 ) == 0 )
{
V_38 -- ; V_39 ++ ;
F_25 ( V_46 , * V_39 ) ;
}
else if ( ( strncmp ( * V_39 , L_27 , 2 ) == 0 ) ||
( strcmp ( * V_39 , L_28 ) == 0 ) )
goto V_53;
else
F_25 ( V_44 , * V_39 ) ;
V_38 -- ;
V_39 ++ ;
}
V_47 = 0 ;
V_53:
if ( V_47 )
{
for ( V_41 = V_54 ; ( * V_41 != NULL ) ; V_41 ++ )
F_6 ( V_48 , L_12 , * V_41 ) ;
goto V_51;
}
if ( F_13 ( V_44 ) == 0 )
{
for( V_16 = F_26 () ; V_16 != NULL ; V_16 = F_27 ( V_16 ) )
{
F_25 ( V_44 , ( char * ) F_28 ( V_16 ) ) ;
}
}
for ( V_40 = 0 ; V_40 < F_13 ( V_44 ) ; V_40 ++ )
{
const char * V_55 = F_14 ( V_44 , V_40 ) ;
if ( ( V_16 = F_29 ( V_55 ) ) != NULL )
{
const char * V_21 = F_30 ( V_16 ) ;
F_6 ( V_7 , L_29 , V_55 , V_21 ) ;
F_12 ( V_16 , V_45 , V_7 , V_9 ) ;
if ( strcmp ( F_28 ( V_16 ) , V_55 ) != 0 )
{
F_6 ( V_7 , L_30 ,
F_28 ( V_16 ) , F_30 ( V_16 ) ) ;
}
if ( V_42 )
{
int V_56 = 256 ;
char * V_57 = NULL ;
int V_58 , V_59 ;
const int * V_60 ;
T_4 V_61 ;
T_5 V_62 ;
if ( F_31 ( V_16 ) != NULL
&& ! F_2 ( & V_57 , L_31 ,
& V_56 , 256 ) )
goto V_51;
if ( F_32 ( V_16 ) != NULL
&& ! F_2 ( & V_57 , L_32 ,
& V_56 , 256 ) )
goto V_51;
if ( F_33 ( V_16 ) != NULL
&& ! F_2 ( & V_57 , L_33 ,
& V_56 , 256 ) )
goto V_51;
if ( F_34 ( V_16 ) != NULL
&& ! F_2 ( & V_57 , L_34 ,
& V_56 , 256 ) )
goto V_51;
V_61 = F_35 ( V_16 ) ;
if( ! V_61 ) goto V_63;
V_59 = V_61 ( V_16 , NULL , & V_60 , 0 ) ;
for( V_58 = 0 ; V_58 < V_59 ; ++ V_58 )
if( ! F_2 ( & V_57 ,
F_36 ( V_60 [ V_58 ] ) ,
& V_56 , 256 ) )
goto V_51;
V_63:
V_62 = F_37 ( V_16 ) ;
if( ! V_62 ) goto V_64;
V_59 = V_62 ( V_16 , NULL , & V_60 , 0 ) ;
for( V_58 = 0 ; V_58 < V_59 ; ++ V_58 )
if( ! F_2 ( & V_57 ,
F_36 ( V_60 [ V_58 ] ) ,
& V_56 , 256 ) )
goto V_51;
V_64:
if ( V_57 && ( * V_57 != '\0' ) )
F_6 ( V_7 , L_35 , V_57 ) ;
F_10 ( V_57 ) ;
}
if( V_43 )
{
F_6 ( V_7 , L_12 , V_9 ) ;
if ( F_38 ( V_16 ) )
{
F_6 ( V_7 , L_36 ) ;
F_12 ( V_16 , V_46 , V_7 , V_9 ) ;
F_39 ( V_16 ) ;
}
else
{
F_6 ( V_7 , L_37 ) ;
F_40 ( stdout ) ;
F_41 () ;
}
}
if( ( V_17 > 0 ) && ! F_7 ( V_16 , V_17 , V_7 , V_9 ) )
goto V_51;
F_42 ( V_16 ) ;
}
else
F_16 ( V_48 ) ;
}
V_20 = 0 ;
V_51:
F_16 ( V_48 ) ;
F_11 ( V_44 , F_1 ) ;
F_11 ( V_45 , F_1 ) ;
F_11 ( V_46 , F_1 ) ;
if ( V_7 != NULL ) F_43 ( V_7 ) ;
F_44 () ;
F_45 ( V_20 ) ;
}
