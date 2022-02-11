static int F_1 ( T_1 * V_1 , char * V_2 , char type )
{
char * * V_3 ;
int V_4 ;
if ( V_2 == NULL ) return - 1 ;
if ( type == V_5 )
for ( V_4 = 0 ; V_4 < F_2 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ )
{
V_3 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] == V_5 && ! strcmp ( V_2 , V_3 [ V_8 ] ) )
return V_4 ;
}
else for ( V_4 = 0 ; V_4 < F_2 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ )
{
V_3 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] != V_5 && ! strcmp ( V_2 , V_3 [ V_8 ] ) )
return V_4 ;
}
return - 1 ;
}
static void F_4 ( T_1 * V_1 , T_2 * V_9 , int V_10 , int V_11 , char * V_12 )
{
if ( V_10 >= 0 && V_11 )
{
int V_13 ;
char * * V_3 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_10 ) ;
F_5 ( V_9 , L_1 , V_12 , V_3 [ V_8 ] ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
{
F_5 ( V_15 , L_2 , V_13 , V_3 [ V_13 ] ) ;
}
}
}
static void F_6 ( T_1 * V_1 , T_2 * V_9 , int V_16 , int V_11 )
{
F_4 ( V_1 , V_9 , V_16 , V_11 , L_3 ) ;
}
static void F_7 ( T_1 * V_1 , T_2 * V_9 , int V_17 , int V_11 )
{
if ( V_11 > 0 )
{
char * * V_3 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_17 ) ;
if ( V_3 [ V_7 ] [ 0 ] != 'I' )
{
F_4 ( V_1 , V_9 , V_17 , V_11 , L_4 ) ;
F_4 ( V_1 , V_9 , F_1 ( V_1 , V_3 [ V_18 ] , 'I' ) , V_11 , L_3 ) ;
}
}
}
static int F_8 ( T_1 * V_1 , T_2 * V_9 , char * * V_19 )
{
char * * V_20 ;
int V_4 ;
if ( ( V_20 = ( char * * ) F_9 ( sizeof( char * ) * ( V_14 + 1 ) ) ) == NULL )
{
F_5 ( V_15 , L_5 ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ )
{
V_20 [ V_4 ] = V_19 [ V_4 ] ;
V_19 [ V_4 ] = NULL ;
}
V_20 [ V_14 ] = NULL ;
if ( ! F_10 ( V_1 -> V_1 , V_20 ) )
{
F_5 ( V_9 , L_6 ) ;
F_5 ( V_9 , L_7 , V_1 -> V_1 -> error ) ;
F_11 ( V_20 ) ;
return 0 ;
}
return 1 ;
}
static void F_12 ( const char * V_21 , char * V_22 )
{
F_5 ( V_15 , L_8 , V_21 , V_22 ) ;
}
static char * F_13 ( const char * V_23 , const char * V_24 ,
char * V_25 , const char * V_26 , const char * V_27 ,
const char * V_28 , T_2 * V_9 , int V_11 )
{
char V_29 [ 1024 ] ;
T_3 V_30 ;
char * V_31 = NULL ;
char * V_32 = NULL ;
V_30 . V_33 = V_23 ;
V_30 . V_29 = V_28 ;
if ( F_14 ( V_29 , 1024 , 0 , & V_30 ) > 0 )
{
T_4 F_5 ( V_9 , L_9 , V_23 , V_24 , V_25 , V_26 , V_27 ) ;
F_5 ( V_9 , L_10 , V_29 ) ;
if ( ! ( V_32 = F_15 ( V_23 , V_29 , & V_25 , & V_31 , V_27 , V_26 ) ) )
{
F_5 ( V_9 , L_11 ) ;
}
else
{
if ( strcmp ( V_31 , V_24 ) )
V_32 = NULL ;
F_11 ( V_31 ) ;
}
}
return V_32 ;
}
static char * F_16 ( char * V_23 , char * * V_24 ,
char * * V_25 , char * V_26 , char * V_27 ,
char * V_34 , T_2 * V_9 , int V_11 )
{
char V_29 [ 1024 ] ;
T_3 V_30 ;
char * V_32 = NULL ;
char * V_35 = NULL ;
V_30 . V_33 = V_23 ;
V_30 . V_29 = V_34 ;
if ( F_14 ( V_29 , 1024 , 1 , & V_30 ) > 0 )
{
T_4 F_5 ( V_9 , L_12 , V_23 , V_26 , V_27 ) ;
if ( ! ( V_32 = F_15 ( V_23 , V_29 , & V_35 , V_24 , V_27 , V_26 ) ) )
{
F_5 ( V_9 , L_13 ) ;
}
else
* V_25 = V_35 ;
T_5 F_5 ( V_9 , L_14 , V_32 , V_35 , * V_24 ) ;
}
return V_32 ;
}
int MAIN ( int V_36 , char * * V_37 )
{
int V_38 = 0 ;
int V_39 = 0 ;
int V_40 = 0 ;
int V_41 = 0 ;
char * V_23 = NULL ;
char * V_42 = NULL , * V_43 = NULL ;
char * V_28 = NULL , * V_34 = NULL ;
char * V_44 = NULL ;
int V_45 = - 1 ;
char * * V_46 = NULL ;
int V_47 = - 1 ;
char * V_48 = NULL ;
int V_49 = 0 ;
int V_50 = 1 ;
int V_51 = 0 ;
int V_11 = 0 ;
int V_52 = 0 ;
char * V_53 = NULL ;
char * V_54 = NULL ;
T_1 * V_1 = NULL ;
char * * V_3 ;
int V_4 ;
long V_55 = - 1 ;
char * V_56 = NULL ;
#ifndef F_17
char * V_57 = NULL ;
#endif
char * V_58 = NULL ;
T_6 V_59 ;
#ifdef F_18
V_60 = 1 ;
V_61 = 1 ;
V_62 = 0 ;
#endif
F_19 () ;
V_63 = NULL ;
V_64 = NULL ;
if ( V_15 == NULL )
if ( ( V_15 = F_20 ( F_21 () ) ) != NULL )
F_22 ( V_15 , V_65 , V_66 | V_67 ) ;
V_36 -- ;
V_37 ++ ;
while ( V_36 >= 1 && V_49 == 0 )
{
if ( strcmp ( * V_37 , L_15 ) == 0 )
V_11 ++ ;
else if ( strcmp ( * V_37 , L_16 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_53 = * ( ++ V_37 ) ;
}
else if ( strcmp ( * V_37 , L_17 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_64 = * ( ++ V_37 ) ;
}
else if ( strcmp ( * V_37 , L_18 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_54 = * ( ++ V_37 ) ;
}
else if ( strcmp ( * V_37 , L_19 ) == 0 )
V_38 = 1 ;
else if ( strcmp ( * V_37 , L_20 ) == 0 )
V_40 = 1 ;
else if ( strcmp ( * V_37 , L_21 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( * V_37 , L_22 ) == 0 )
V_39 = 1 ;
else if ( strcmp ( * V_37 , L_23 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_44 = * ( ++ V_37 ) ;
}
else if ( strcmp ( * V_37 , L_24 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_48 = * ( ++ V_37 ) ;
}
else if ( strcmp ( * V_37 , L_25 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_42 = * ( ++ V_37 ) ;
}
else if ( strcmp ( * V_37 , L_26 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_43 = * ( ++ V_37 ) ;
}
#ifndef F_17
else if ( strcmp ( * V_37 , L_27 ) == 0 )
{
if ( -- V_36 < 1 ) goto V_68;
V_57 = * ( ++ V_37 ) ;
}
#endif
else if ( * * V_37 == '-' )
{
V_68:
F_5 ( V_15 , L_28 , * V_37 ) ;
V_49 = 1 ;
break;
}
else
break;
V_36 -- ;
V_37 ++ ;
}
if ( V_54 && V_53 )
{
F_5 ( V_15 , L_29 ) ;
V_49 = 1 ;
}
if ( V_38 + V_40 + V_41 + V_39 != 1 )
{
F_5 ( V_15 , L_30 ) ;
V_49 = 1 ;
}
if ( V_40 + V_41 + V_40 == 1 && V_36 <= 0 )
{
F_5 ( V_15 , L_31 ) ;
V_49 = 1 ;
}
if ( ( V_28 || V_34 ) && V_36 != 1 )
{
F_5 ( V_15 , L_32 ) ;
V_49 = 1 ;
}
if ( V_49 )
{
for ( V_3 = V_69 ; ( * V_3 != NULL ) ; V_3 ++ )
F_5 ( V_15 , L_33 , * V_3 ) ;
F_5 ( V_15 , L_34 , V_70 , V_70 ) ;
F_5 ( V_15 , L_35 ) ;
F_5 ( V_15 , L_36 ) ;
goto V_71;
}
F_23 () ;
#ifndef F_17
F_24 ( V_15 , V_57 , 0 ) ;
#endif
if( ! F_25 ( V_15 , V_42 , V_43 , & V_28 , & V_34 ) )
{
F_5 ( V_15 , L_37 ) ;
goto V_71;
}
if ( ! V_54 )
{
V_58 = NULL ;
if ( V_53 == NULL ) V_53 = getenv ( L_38 ) ;
if ( V_53 == NULL ) V_53 = getenv ( L_39 ) ;
if ( V_53 == NULL )
{
const char * V_12 = F_26 () ;
T_7 V_72 ;
#ifdef F_27
V_72 = strlen ( V_12 ) + sizeof( V_73 ) ;
V_58 = F_9 ( V_72 ) ;
strcpy ( V_58 , V_12 ) ;
#else
V_72 = strlen ( V_12 ) + sizeof( V_73 ) + 1 ;
V_58 = F_9 ( V_72 ) ;
F_28 ( V_58 , V_12 , V_72 ) ;
F_29 ( V_58 , L_40 , V_72 ) ;
#endif
F_29 ( V_58 , V_73 , V_72 ) ;
V_53 = V_58 ;
}
T_4 F_5 ( V_15 , L_41 , V_53 ) ;
V_63 = F_30 ( NULL ) ;
if ( F_31 ( V_63 , V_53 , & V_55 ) <= 0 )
{
if ( V_55 <= 0 )
F_5 ( V_15 , L_42 ,
V_53 ) ;
else
F_5 ( V_15 , L_43
, V_55 , V_53 ) ;
goto V_71;
}
if( V_58 )
{
F_11 ( V_58 ) ;
V_58 = NULL ;
}
if ( ! F_32 ( V_15 , V_63 ) )
goto V_71;
if ( V_64 == NULL )
{
T_4 F_5 ( V_15 , L_44 V_74 L_45 ) ;
V_64 = F_33 ( V_63 , V_75 , V_74 ) ;
if ( V_64 == NULL )
{
F_12 ( V_75 , V_74 ) ;
goto V_71;
}
}
if ( V_56 == NULL && V_63 )
V_56 = F_33 ( V_63 , V_75 , L_46 ) ;
T_4 F_5 ( V_15 , L_44 V_76 L_47 , V_64 ) ;
if ( ( V_54 = F_33 ( V_63 , V_64 , V_76 ) ) == NULL )
{
F_12 ( V_64 , V_76 ) ;
goto V_71;
}
}
if ( V_56 == NULL )
F_34 () ;
else
F_35 ( V_56 , V_15 , 0 ) ;
T_4 F_5 ( V_15 , L_48 , V_54 ) ;
V_1 = F_36 ( V_54 , & V_59 ) ;
if ( V_1 == NULL ) goto V_71;
for ( V_4 = 0 ; V_4 < F_2 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ )
{
V_3 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] == V_5 )
{
V_47 = V_4 ;
if ( V_45 < 0 && V_44 != NULL && ! strcmp ( V_44 , V_3 [ V_8 ] ) )
V_45 = V_4 ;
F_6 ( V_1 , V_15 , V_4 , V_11 > 1 ) ;
}
}
T_4 F_5 ( V_15 , L_49 ) ;
if ( V_45 >= 0 )
{
V_46 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_45 ) ;
F_4 ( V_1 , V_15 , V_45 , V_11 > 1 , L_50 ) ;
}
else if ( V_47 > 0 && ! F_37 ( V_44 ) )
{
F_5 ( V_15 , L_51 , V_44 ) ;
goto V_71;
}
else
{
T_4 F_5 ( V_15 , L_52 ) ;
V_46 = NULL ;
}
T_5 F_5 ( V_15 , L_53 ) ;
if ( V_36 > 0 )
V_23 = * ( V_37 ++ ) ;
while ( V_39 || V_23 )
{
int V_17 = - 1 ;
if ( V_23 )
T_5 F_5 ( V_15 , L_54 , V_23 ) ;
if ( ( V_17 = F_1 ( V_1 , V_23 , 'U' ) ) >= 0 )
{
F_7 ( V_1 , V_15 , V_17 , ( V_11 > 0 ) || V_39 ) ;
}
if ( V_39 )
{
if ( V_23 == NULL )
{
F_5 ( V_15 , L_55 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ )
{
F_7 ( V_1 , V_15 , V_4 , 1 ) ;
}
V_39 = 0 ;
}
else if ( V_17 < 0 )
{
F_5 ( V_15 , L_56 ,
V_23 ) ;
V_51 ++ ;
}
}
else if ( V_38 )
{
if ( V_17 >= 0 )
{
char * * V_19 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_17 ) ;
F_5 ( V_15 , L_57 , V_23 ) ;
V_19 [ V_7 ] [ 0 ] = 'V' ;
V_52 = 1 ;
}
else
{
char * V_19 [ V_14 ] ; char * V_32 ;
V_19 [ V_77 ] = NULL ;
V_19 [ V_78 ] = NULL ;
V_19 [ V_79 ] = NULL ;
if ( ! ( V_32 = F_16 ( V_23 , & ( V_19 [ V_77 ] ) , & ( V_19 [ V_78 ] ) , V_46 ? V_46 [ V_78 ] : V_44 , V_46 ? V_46 [ V_77 ] : NULL , V_34 , V_15 , V_11 ) ) )
{
F_5 ( V_15 , L_58 , V_23 ) ;
V_51 ++ ;
goto V_71;
}
V_19 [ V_8 ] = F_38 ( V_23 ) ;
V_19 [ V_7 ] = F_38 ( L_59 ) ;
V_19 [ V_18 ] = F_38 ( V_32 ) ;
if ( ! V_19 [ V_8 ] || ! V_19 [ V_18 ] || ! V_19 [ V_7 ] || ! V_19 [ V_77 ] || ! V_19 [ V_78 ] ||
( V_48 && ( ! ( V_19 [ V_79 ] = F_38 ( V_48 ) ) ) ) ||
! F_8 ( V_1 , V_15 , V_19 ) )
{
if ( V_19 [ V_8 ] ) F_11 ( V_19 [ V_8 ] ) ;
if ( V_19 [ V_18 ] ) F_11 ( V_19 [ V_18 ] ) ;
if ( V_19 [ V_79 ] ) F_11 ( V_19 [ V_79 ] ) ;
if ( V_19 [ V_7 ] ) F_11 ( V_19 [ V_7 ] ) ;
if ( V_19 [ V_77 ] ) F_11 ( V_19 [ V_77 ] ) ;
if ( V_19 [ V_78 ] ) F_11 ( V_19 [ V_78 ] ) ;
goto V_71;
}
V_52 = 1 ;
}
}
else if ( V_41 )
{
if ( V_17 < 0 )
{
F_5 ( V_15 , L_60 , V_23 ) ;
V_51 ++ ;
}
else
{
char * * V_19 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_17 ) ;
char type = V_19 [ V_7 ] [ 0 ] ;
if ( type == 'v' )
{
F_5 ( V_15 , L_61 , V_23 ) ;
V_51 ++ ;
}
else
{
char * V_32 ;
if ( V_19 [ V_7 ] [ 0 ] == 'V' )
{
int V_80 ;
char * * V_20 = NULL ;
T_4 F_5 ( V_15 , L_62 , V_23 ) ;
if ( ( V_80 = F_1 ( V_1 , V_19 [ V_18 ] , V_5 ) ) >= 0 )
V_20 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_17 ) ;
if ( ! F_13 ( V_23 , V_19 [ V_77 ] , V_19 [ V_78 ] , V_20 ? V_20 [ V_78 ] : V_19 [ V_18 ] , V_20 ? V_20 [ V_77 ] : NULL , V_28 , V_15 , V_11 ) )
{
F_5 ( V_15 , L_63 , V_23 ) ;
V_51 ++ ;
goto V_71;
}
}
T_4 F_5 ( V_15 , L_64 , V_23 ) ;
if ( ! ( V_32 = F_16 ( V_23 , & ( V_19 [ V_77 ] ) , & ( V_19 [ V_78 ] ) , V_46 ? V_46 [ V_78 ] : NULL , V_46 ? V_46 [ V_77 ] : NULL , V_34 , V_15 , V_11 ) ) )
{
F_5 ( V_15 , L_65 , V_23 ) ;
V_51 ++ ;
goto V_71;
}
V_19 [ V_7 ] [ 0 ] = 'v' ;
V_19 [ V_18 ] = F_38 ( V_32 ) ;
if ( ! V_19 [ V_8 ] || ! V_19 [ V_18 ] || ! V_19 [ V_7 ] || ! V_19 [ V_77 ] || ! V_19 [ V_78 ] ||
( V_48 && ( ! ( V_19 [ V_79 ] = F_38 ( V_48 ) ) ) ) )
goto V_71;
V_52 = 1 ;
}
}
}
else if ( V_40 )
{
if ( V_17 < 0 )
{
F_5 ( V_15 , L_66 , V_23 ) ;
V_51 ++ ;
}
else
{
char * * V_81 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_17 ) ;
F_5 ( V_15 , L_67 , V_23 ) ;
V_81 [ V_7 ] [ 0 ] = 'R' ;
V_52 = 1 ;
}
}
if ( -- V_36 > 0 )
V_23 = * ( V_37 ++ ) ;
else
{
V_23 = NULL ;
V_39 = 0 ;
}
}
T_4 F_5 ( V_15 , L_68 ) ;
if ( V_52 )
{
for ( V_4 = 0 ; V_4 < F_2 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ )
{
V_3 = ( char * * ) F_3 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] == 'v' )
{
V_3 [ V_7 ] [ 0 ] = 'V' ;
F_7 ( V_1 , V_15 , V_4 , V_11 ) ;
}
}
T_4 F_5 ( V_15 , L_69 ) ;
if ( ! F_39 ( V_54 , L_70 , V_1 ) ) goto V_71;
T_4 F_5 ( V_15 , L_71 ) ;
if ( ! F_40 ( V_54 , L_70 , L_72 ) ) goto V_71;
T_4 F_5 ( V_15 , L_73 ) ;
}
V_50 = ( V_51 != 0 ) ;
V_71:
if ( V_51 != 0 )
T_4 F_5 ( V_15 , L_74 , V_51 ) ;
T_4 F_5 ( V_15 , L_75 , V_50 ) ;
if( V_58 )
F_11 ( V_58 ) ;
if ( V_50 ) F_41 ( V_15 ) ;
if ( V_56 ) F_42 ( V_56 , V_15 ) ;
if ( V_63 ) F_43 ( V_63 ) ;
if ( V_1 ) F_44 ( V_1 ) ;
F_45 () ;
F_46 () ;
F_47 ( V_50 ) ;
}
