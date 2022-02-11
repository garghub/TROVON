static void F_1 ( char * V_1 )
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
F_7 ( V_7 , L_5 ) ;
V_10 = 1 ;
}
if( V_8 & V_14 )
{
if( V_10 )
{
F_7 ( V_7 , L_6 ) ;
V_11 = 1 ;
}
F_7 ( V_7 , L_7 ) ;
V_10 = 1 ;
}
if( V_8 & V_15 )
{
if( V_10 )
{
F_7 ( V_7 , L_6 ) ;
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
if( V_10 ) F_7 ( V_7 , L_6 ) ;
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
F_9 ( V_24 ) * V_25 = NULL ;
if( ! F_10 ( V_16 , V_26 , 0 , NULL , NULL ) ||
( ( V_19 = F_10 ( V_16 , V_27 ,
0 , NULL , NULL ) ) <= 0 ) )
{
#if 0
BIO_printf(bio_out, "%s<no control commands>\n", indent);
#endif
return 1 ;
}
V_25 = F_11 () ;
if( ! V_25 )
goto V_11;
do {
int V_28 ;
if( ( V_8 = F_10 ( V_16 , V_29 , V_19 ,
NULL , NULL ) ) < 0 )
goto V_11;
if ( ! ( V_8 & V_12 ) || V_17 >= 4 )
{
if( ( V_28 = F_10 ( V_16 , V_30 , V_19 ,
NULL , NULL ) ) <= 0 )
goto V_11;
if( ( V_21 = F_3 ( V_28 + 1 ) ) == NULL )
goto V_11;
if( F_10 ( V_16 , V_31 , V_19 , V_21 ,
NULL ) <= 0 )
goto V_11;
if( ( V_28 = F_10 ( V_16 , V_32 , V_19 ,
NULL , NULL ) ) < 0 )
goto V_11;
if( V_28 > 0 )
{
if( ( V_22 = F_3 ( V_28 + 1 ) ) == NULL )
goto V_11;
if( F_10 ( V_16 , V_33 , V_19 , V_22 ,
NULL ) <= 0 )
goto V_11;
}
if( V_23 == 0 )
V_23 = F_12 ( V_7 , V_9 ) ;
else
V_23 += F_7 ( V_7 , L_1 ) ;
if( V_17 == 1 )
{
if( ( V_23 > ( int ) strlen ( V_9 ) ) &&
( V_23 + ( int ) strlen ( V_21 ) > V_18 ) )
{
F_7 ( V_7 , L_11 ) ;
V_23 = F_12 ( V_7 , V_9 ) ;
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
F_13 ( V_21 ) ; V_21 = NULL ;
if( V_22 ) { F_13 ( V_22 ) ; V_22 = NULL ; }
V_19 = F_10 ( V_16 , V_34 ,
V_19 , NULL , NULL ) ;
} while( V_19 > 0 );
if( V_23 > 0 )
F_7 ( V_7 , L_11 ) ;
V_20 = 1 ;
V_11:
if( V_25 ) F_14 ( V_25 , F_1 ) ;
if( V_21 ) F_13 ( V_21 ) ;
if( V_22 ) F_13 ( V_22 ) ;
return V_20 ;
}
int MAIN ( int V_35 , char * * V_36 )
{
int V_20 = 1 , V_37 ;
const char * * V_38 ;
int V_17 = 0 , V_39 = 0 , V_40 = 0 , V_41 = 0 ;
T_2 * V_16 ;
F_9 ( V_24 ) * V_42 = F_11 () ;
F_9 ( V_24 ) * V_43 = F_11 () ;
F_9 ( V_24 ) * V_44 = F_11 () ;
int V_45 = 1 ;
T_1 * V_7 = NULL ;
const char * V_9 = L_15 ;
F_15 () ;
F_16 () ;
if ( V_46 == NULL )
V_46 = F_17 ( V_47 , V_48 ) ;
if ( ! F_18 ( V_46 , NULL ) )
goto V_49;
V_7 = F_17 ( stdout , V_48 ) ;
#ifdef F_19
{
T_1 * V_50 = F_20 ( F_21 () ) ;
V_7 = F_22 ( V_50 , V_7 ) ;
}
#endif
V_35 -- ;
V_36 ++ ;
while ( V_35 >= 1 )
{
if ( strncmp ( * V_36 , L_16 , 2 ) == 0 )
{
if( strspn ( * V_36 + 1 , L_17 ) < strlen ( * V_36 + 1 ) )
goto V_51;
if( ( V_17 = strlen ( * V_36 + 1 ) ) > 4 )
goto V_51;
}
else if ( strcmp ( * V_36 , L_18 ) == 0 )
V_39 = 1 ;
else if ( strncmp ( * V_36 , L_19 , 2 ) == 0 )
{
V_40 = 1 ;
if( strspn ( * V_36 + 1 , L_20 ) < strlen ( * V_36 + 1 ) )
goto V_51;
if( ( V_41 = strlen ( * V_36 + 1 ) - 1 ) > 1 )
goto V_51;
}
else if ( strcmp ( * V_36 , L_21 ) == 0 )
{
V_35 -- ; V_36 ++ ;
if ( V_35 == 0 )
goto V_51;
F_23 ( V_43 , * V_36 ) ;
}
else if ( strcmp ( * V_36 , L_22 ) == 0 )
{
V_35 -- ; V_36 ++ ;
if ( V_35 == 0 )
goto V_51;
F_23 ( V_44 , * V_36 ) ;
}
else if ( ( strncmp ( * V_36 , L_23 , 2 ) == 0 ) ||
( strcmp ( * V_36 , L_24 ) == 0 ) )
goto V_51;
else
F_23 ( V_42 , * V_36 ) ;
V_35 -- ;
V_36 ++ ;
}
V_45 = 0 ;
V_51:
if ( V_45 )
{
for ( V_38 = V_52 ; ( * V_38 != NULL ) ; V_38 ++ )
F_7 ( V_46 , L_12 , * V_38 ) ;
goto V_49;
}
if ( F_24 ( V_42 ) == 0 )
{
for( V_16 = F_25 () ; V_16 != NULL ; V_16 = F_26 ( V_16 ) )
{
F_23 ( V_42 , ( char * ) F_27 ( V_16 ) ) ;
}
}
for ( V_37 = 0 ; V_37 < F_24 ( V_42 ) ; V_37 ++ )
{
const char * V_53 = F_28 ( V_42 , V_37 ) ;
if ( ( V_16 = F_29 ( V_53 ) ) != NULL )
{
const char * V_21 = F_30 ( V_16 ) ;
F_7 ( V_7 , L_25 , V_53 , V_21 ) ;
F_31 ( V_16 , V_43 , V_7 , V_9 ) ;
if ( strcmp ( F_27 ( V_16 ) , V_53 ) != 0 )
{
F_7 ( V_7 , L_26 ,
F_27 ( V_16 ) , F_30 ( V_16 ) ) ;
}
if ( V_39 )
{
int V_54 = 256 ;
char * V_55 = NULL ;
int V_56 , V_57 ;
const int * V_58 ;
T_3 V_59 ;
T_4 V_60 ;
T_5 V_61 ;
if ( F_32 ( V_16 ) != NULL
&& ! F_2 ( & V_55 , L_27 ,
& V_54 , 256 ) )
goto V_49;
if ( F_33 ( V_16 ) != NULL
&& ! F_2 ( & V_55 , L_28 ,
& V_54 , 256 ) )
goto V_49;
if ( F_34 ( V_16 ) != NULL
&& ! F_2 ( & V_55 , L_29 ,
& V_54 , 256 ) )
goto V_49;
if ( F_35 ( V_16 ) != NULL
&& ! F_2 ( & V_55 , L_30 ,
& V_54 , 256 ) )
goto V_49;
V_59 = F_36 ( V_16 ) ;
if( ! V_59 ) goto V_62;
V_57 = V_59 ( V_16 , NULL , & V_58 , 0 ) ;
for( V_56 = 0 ; V_56 < V_57 ; ++ V_56 )
if( ! F_2 ( & V_55 ,
F_37 ( V_58 [ V_56 ] ) ,
& V_54 , 256 ) )
goto V_49;
V_62:
V_60 = F_38 ( V_16 ) ;
if( ! V_60 ) goto V_63;
V_57 = V_60 ( V_16 , NULL , & V_58 , 0 ) ;
for( V_56 = 0 ; V_56 < V_57 ; ++ V_56 )
if( ! F_2 ( & V_55 ,
F_37 ( V_58 [ V_56 ] ) ,
& V_54 , 256 ) )
goto V_49;
V_63:
V_61 = F_39 ( V_16 ) ;
if( ! V_61 ) goto V_64;
V_57 = V_61 ( V_16 , NULL , & V_58 , 0 ) ;
for( V_56 = 0 ; V_56 < V_57 ; ++ V_56 )
if( ! F_2 ( & V_55 ,
F_37 ( V_58 [ V_56 ] ) ,
& V_54 , 256 ) )
goto V_49;
V_64:
if ( V_55 && ( * V_55 != '\0' ) )
F_7 ( V_7 , L_31 , V_55 ) ;
F_13 ( V_55 ) ;
}
if( V_40 )
{
F_7 ( V_7 , L_12 , V_9 ) ;
if ( F_40 ( V_16 ) )
{
F_7 ( V_7 , L_32 ) ;
F_31 ( V_16 , V_44 , V_7 , V_9 ) ;
F_41 ( V_16 ) ;
}
else
{
F_7 ( V_7 , L_33 ) ;
if( V_41 )
F_42 ( stdout ) ;
F_43 () ;
}
}
if( ( V_17 > 0 ) && ! F_8 ( V_16 , V_17 , V_7 , V_9 ) )
goto V_49;
F_44 ( V_16 ) ;
}
else
F_45 ( V_46 ) ;
}
V_20 = 0 ;
V_49:
F_45 ( V_46 ) ;
F_14 ( V_42 , F_1 ) ;
F_14 ( V_43 , F_1 ) ;
F_14 ( V_44 , F_1 ) ;
if ( V_7 != NULL ) F_46 ( V_7 ) ;
F_47 () ;
F_48 ( V_20 ) ;
}
