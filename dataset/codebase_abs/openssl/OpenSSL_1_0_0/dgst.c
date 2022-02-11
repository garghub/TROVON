static void F_1 ( const T_1 * V_1 ,
const char * V_2 , const char * V_3 , void * V_4 )
{
const char * V_5 ;
if ( ! V_1 )
return;
V_5 = F_2 ( F_3 ( V_1 ) ) ;
if ( strcmp ( V_2 , V_5 ) )
return;
if ( F_4 ( V_1 ) & V_6 )
return;
if ( strchr ( V_5 , ' ' ) )
V_5 = F_5 ( V_1 ) ;
F_6 ( V_4 , L_1 ,
V_5 , V_5 ) ;
}
int MAIN ( int V_7 , char * * V_8 )
{
T_2 * V_9 = NULL ;
unsigned char * V_10 = NULL ;
int V_11 , V_12 = 1 ;
const T_1 * V_13 = NULL , * V_1 ;
T_3 * V_14 = NULL , * V_15 ;
T_3 * V_16 = NULL ;
T_3 * V_17 = NULL ;
#define F_7 39
char V_18 [ F_7 + 1 ] ;
int V_19 = 0 ;
int V_20 = 0 ;
int V_21 = V_22 ;
const char * V_23 = NULL , * V_24 = NULL ;
const char * V_25 = NULL , * V_26 = NULL ;
int V_27 = - 1 , V_28 = 0 , V_29 = 0 ;
T_4 * V_30 = NULL ;
unsigned char * V_31 = NULL ;
int V_32 = 0 ;
char * V_33 = NULL , * V_34 = NULL ;
#ifndef F_8
char * V_35 = NULL ;
#endif
char * V_36 = NULL ;
char * V_37 = NULL ;
F_9 ( V_38 ) * V_39 = NULL , * V_40 = NULL ;
F_10 () ;
if ( ( V_10 = ( unsigned char * ) F_11 ( V_41 ) ) == NULL )
{
F_6 ( V_42 , L_2 ) ;
goto V_43;
}
if ( V_42 == NULL )
if ( ( V_42 = F_12 ( F_13 () ) ) != NULL )
F_14 ( V_42 , V_44 , V_45 | V_46 ) ;
if ( ! F_15 ( V_42 , NULL ) )
goto V_43;
F_16 ( V_8 [ 0 ] , V_18 , sizeof V_18 ) ;
V_13 = F_17 ( V_18 ) ;
V_7 -- ;
V_8 ++ ;
while ( V_7 > 0 )
{
if ( ( * V_8 ) [ 0 ] != '-' ) break;
if ( strcmp ( * V_8 , L_3 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( * V_8 , L_4 ) == 0 )
V_19 = 2 ;
else if ( strcmp ( * V_8 , L_5 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_26 = * ( ++ V_8 ) ;
}
else if ( strcmp ( * V_8 , L_6 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_23 = * ( ++ V_8 ) ;
}
else if ( strcmp ( * V_8 , L_7 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_24 = * ( ++ V_8 ) ;
}
else if ( ! strcmp ( * V_8 , L_8 ) )
{
if ( -- V_7 < 1 )
break;
V_33 = * ++ V_8 ;
}
else if ( strcmp ( * V_8 , L_9 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_24 = * ( ++ V_8 ) ;
V_28 = 1 ;
V_29 = 1 ;
}
else if ( strcmp ( * V_8 , L_10 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_24 = * ( ++ V_8 ) ;
V_29 = 1 ;
}
else if ( strcmp ( * V_8 , L_11 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_25 = * ( ++ V_8 ) ;
}
else if ( strcmp ( * V_8 , L_12 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_21 = F_18 ( * ( ++ V_8 ) ) ;
}
#ifndef F_8
else if ( strcmp ( * V_8 , L_13 ) == 0 )
{
if ( -- V_7 < 1 ) break;
V_35 = * ( ++ V_8 ) ;
V_9 = F_19 ( V_42 , V_35 , 0 ) ;
}
#endif
else if ( strcmp ( * V_8 , L_14 ) == 0 )
V_27 = 0 ;
else if ( strcmp ( * V_8 , L_15 ) == 0 )
V_27 = 1 ;
else if ( strcmp ( * V_8 , L_16 ) == 0 )
V_20 = 1 ;
else if ( ! strcmp ( * V_8 , L_17 ) )
{
if ( -- V_7 < 1 )
break;
V_36 = * ++ V_8 ;
}
else if ( ! strcmp ( * V_8 , L_18 ) )
{
if ( -- V_7 < 1 )
break;
V_37 = * ++ V_8 ;
}
else if ( strcmp ( * V_8 , L_19 ) == 0 )
{
if ( -- V_7 < 1 )
break;
if ( ! V_39 )
V_39 = F_20 () ;
if ( ! V_39 || ! F_21 ( V_39 , * ( ++ V_8 ) ) )
break;
}
else if ( strcmp ( * V_8 , L_20 ) == 0 )
{
if ( -- V_7 < 1 )
break;
if ( ! V_40 )
V_40 = F_20 () ;
if ( ! V_40 || ! F_21 ( V_40 , * ( ++ V_8 ) ) )
break;
}
else if ( ( V_1 = F_17 ( & ( ( * V_8 ) [ 1 ] ) ) ) != NULL )
V_13 = V_1 ;
else
break;
V_7 -- ;
V_8 ++ ;
}
if( V_29 && ! V_25 ) {
F_6 ( V_42 , L_21 ) ;
goto V_43;
}
if ( ( V_7 > 0 ) && ( V_8 [ 0 ] [ 0 ] == '-' ) )
{
F_6 ( V_42 , L_22 , * V_8 ) ;
F_6 ( V_42 , L_23 ) ;
F_6 ( V_42 , L_24 ) ;
F_6 ( V_42 , L_25 ) ;
F_6 ( V_42 , L_26 ) ;
F_6 ( V_42 , L_27 ) ;
F_6 ( V_42 , L_28 ) ;
F_6 ( V_42 , L_29 ) ;
F_6 ( V_42 , L_30 ) ;
F_6 ( V_42 , L_31 ) ;
F_6 ( V_42 , L_32 ) ;
F_6 ( V_42 , L_33 ) ;
F_6 ( V_42 , L_34 ) ;
F_6 ( V_42 , L_35 ) ;
F_6 ( V_42 , L_36 ) ;
F_6 ( V_42 , L_37 ) ;
F_6 ( V_42 , L_38 ) ;
#ifndef F_8
F_6 ( V_42 , L_39 ) ;
#endif
F_22 ( F_1 , V_42 ) ;
goto V_43;
}
V_14 = F_12 ( F_13 () ) ;
V_16 = F_12 ( F_23 () ) ;
if ( V_20 )
{
F_24 ( V_14 , V_47 ) ;
F_25 ( V_14 , ( char * ) V_42 ) ;
}
if( ! F_26 ( V_42 , V_33 , NULL , & V_34 , NULL ) )
{
F_6 ( V_42 , L_40 ) ;
goto V_43;
}
if ( ( V_14 == NULL ) || ( V_16 == NULL ) )
{
F_27 ( V_42 ) ;
goto V_43;
}
if( V_27 == - 1 ) {
if( V_24 )
V_27 = 1 ;
else
V_27 = 0 ;
}
if( V_26 )
F_28 ( V_26 , V_42 , 0 ) ;
if( V_23 ) {
if( V_27 )
V_17 = F_29 ( V_23 , L_41 ) ;
else V_17 = F_29 ( V_23 , L_42 ) ;
} else {
V_17 = F_30 ( stdout , V_45 ) ;
#ifdef F_31
{
T_3 * V_48 = F_12 ( F_32 () ) ;
V_17 = F_33 ( V_48 , V_17 ) ;
}
#endif
}
if( ! V_17 ) {
F_6 ( V_42 , L_43 ,
V_23 ? V_23 : L_44 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
if ( ( ! ! V_37 + ! ! V_24 + ! ! V_36 ) > 1 )
{
F_6 ( V_42 , L_45 ) ;
goto V_43;
}
if( V_24 )
{
if ( V_28 )
V_30 = F_34 ( V_42 , V_24 , V_21 , 0 , NULL ,
V_9 , L_46 ) ;
else
V_30 = F_35 ( V_42 , V_24 , V_21 , 0 , V_34 ,
V_9 , L_46 ) ;
if ( ! V_30 )
{
goto V_43;
}
}
if ( V_37 )
{
T_5 * V_49 = NULL ;
int V_50 = 0 ;
if ( ! F_36 ( V_42 , & V_49 , V_37 , V_9 , 0 ) )
goto V_51;
if ( V_40 )
{
char * V_52 ;
for ( V_11 = 0 ; V_11 < F_37 ( V_40 ) ; V_11 ++ )
{
V_52 = F_38 ( V_40 , V_11 ) ;
if ( F_39 ( V_49 , V_52 ) <= 0 )
{
F_6 ( V_42 ,
L_47 ,
V_52 ) ;
F_27 ( V_42 ) ;
goto V_51;
}
}
}
if ( F_40 ( V_49 , & V_30 ) <= 0 )
{
F_41 ( V_42 , L_48 ) ;
F_27 ( V_42 ) ;
goto V_51;
}
V_50 = 1 ;
V_51:
if ( V_49 )
F_42 ( V_49 ) ;
if ( V_50 == 0 )
goto V_43;
}
if ( V_36 )
{
V_30 = F_43 ( V_53 , V_9 ,
( unsigned char * ) V_36 , - 1 ) ;
if ( ! V_30 )
goto V_43;
}
if ( V_30 )
{
T_6 * V_54 = NULL ;
T_5 * V_55 = NULL ;
int V_50 ;
if ( ! F_44 ( V_16 , & V_54 ) )
{
F_6 ( V_42 , L_49 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
if ( V_29 )
V_50 = F_45 ( V_54 , & V_55 , V_13 , V_9 , V_30 ) ;
else
V_50 = F_46 ( V_54 , & V_55 , V_13 , V_9 , V_30 ) ;
if ( ! V_50 )
{
F_6 ( V_42 , L_50 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
if ( V_39 )
{
char * V_56 ;
for ( V_11 = 0 ; V_11 < F_37 ( V_39 ) ; V_11 ++ )
{
V_56 = F_38 ( V_39 , V_11 ) ;
if ( F_39 ( V_55 , V_56 ) <= 0 )
{
F_6 ( V_42 ,
L_51 ,
V_56 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
}
}
}
else
{
if ( V_13 == NULL )
V_13 = F_47 () ;
if ( ! F_48 ( V_16 , V_13 ) )
{
F_6 ( V_42 , L_52 , V_18 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
}
if( V_25 && V_30 ) {
T_3 * V_57 ;
V_57 = F_29 ( V_25 , L_53 ) ;
V_32 = F_49 ( V_30 ) ;
V_31 = F_11 ( V_32 ) ;
if( ! V_57 ) {
F_6 ( V_42 , L_54 ,
V_25 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
V_32 = F_50 ( V_57 , V_31 , V_32 ) ;
F_51 ( V_57 ) ;
if( V_32 <= 0 ) {
F_6 ( V_42 , L_55 ,
V_25 ) ;
F_27 ( V_42 ) ;
goto V_43;
}
}
V_15 = F_33 ( V_16 , V_14 ) ;
if ( V_13 == NULL )
{
T_6 * V_58 ;
F_44 ( V_16 , & V_58 ) ;
V_13 = F_52 ( V_58 ) ;
}
if ( V_7 == 0 )
{
F_14 ( V_14 , V_59 , V_45 ) ;
V_12 = F_53 ( V_17 , V_10 , V_15 , V_19 , V_27 , V_30 , V_31 ,
V_32 , NULL , NULL , L_56 , V_16 ) ;
}
else
{
const char * V_60 = NULL , * V_61 = NULL ;
if( ! V_27 )
{
if ( V_30 )
{
const T_7 * V_62 ;
V_62 = F_54 ( V_30 ) ;
if ( V_62 )
F_55 ( NULL , NULL ,
NULL , NULL , & V_61 , V_62 ) ;
}
V_60 = F_5 ( V_13 ) ;
}
V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ )
{
int V_50 ;
if ( F_56 ( V_14 , V_8 [ V_11 ] ) <= 0 )
{
perror ( V_8 [ V_11 ] ) ;
V_12 ++ ;
continue;
}
else
V_50 = F_53 ( V_17 , V_10 , V_15 , V_19 , V_27 , V_30 , V_31 ,
V_32 , V_61 , V_60 , V_8 [ V_11 ] , V_16 ) ;
if( V_50 )
V_12 = V_50 ;
( void ) F_57 ( V_16 ) ;
}
}
V_43:
if ( V_10 != NULL )
{
F_58 ( V_10 , V_41 ) ;
F_59 ( V_10 ) ;
}
if ( V_14 != NULL ) F_51 ( V_14 ) ;
if ( V_34 )
F_59 ( V_34 ) ;
F_60 ( V_17 ) ;
F_61 ( V_30 ) ;
if ( V_39 )
F_62 ( V_39 ) ;
if ( V_40 )
F_62 ( V_40 ) ;
if( V_31 ) F_59 ( V_31 ) ;
if ( V_16 != NULL ) F_51 ( V_16 ) ;
F_63 () ;
F_64 ( V_12 ) ;
}
int F_53 ( T_3 * V_17 , unsigned char * V_10 , T_3 * V_63 , int V_64 , int V_65 ,
T_4 * V_66 , unsigned char * V_67 , int V_32 ,
const char * V_61 , const char * V_60 ,
const char * V_68 , T_3 * V_16 )
{
T_8 V_69 ;
int V_11 ;
for (; ; )
{
V_11 = F_50 ( V_63 , ( char * ) V_10 , V_41 ) ;
if( V_11 < 0 )
{
F_6 ( V_42 , L_57 , V_68 ) ;
F_27 ( V_42 ) ;
return 1 ;
}
if ( V_11 == 0 ) break;
}
if( V_67 )
{
T_6 * V_70 ;
F_44 ( V_63 , & V_70 ) ;
V_11 = F_65 ( V_70 , V_67 , ( unsigned int ) V_32 ) ;
if( V_11 > 0 )
F_6 ( V_17 , L_58 ) ;
else if( V_11 == 0 )
{
F_6 ( V_17 , L_59 ) ;
return 1 ;
}
else
{
F_6 ( V_42 , L_60 ) ;
F_27 ( V_42 ) ;
return 1 ;
}
return 0 ;
}
if( V_66 )
{
T_6 * V_70 ;
F_44 ( V_63 , & V_70 ) ;
V_69 = V_41 ;
if( ! F_66 ( V_70 , V_10 , & V_69 ) )
{
F_6 ( V_42 , L_61 ) ;
F_27 ( V_42 ) ;
return 1 ;
}
}
else
{
V_69 = F_67 ( V_63 , ( char * ) V_10 , V_41 ) ;
if ( ( int ) V_69 < 0 )
{
F_27 ( V_42 ) ;
return 1 ;
}
}
if( V_65 ) F_68 ( V_17 , V_10 , V_69 ) ;
else if ( V_64 == 2 )
{
for ( V_11 = 0 ; V_11 < ( int ) V_69 ; V_11 ++ )
F_6 ( V_17 , L_62 , V_10 [ V_11 ] ) ;
F_6 ( V_17 , L_63 , V_68 ) ;
}
else
{
if ( V_61 )
F_6 ( V_17 , L_64 , V_61 , V_60 , V_68 ) ;
else if ( V_60 )
F_6 ( V_17 , L_65 , V_60 , V_68 ) ;
else
F_6 ( V_17 , L_66 , V_68 ) ;
for ( V_11 = 0 ; V_11 < ( int ) V_69 ; V_11 ++ )
{
if ( V_64 && ( V_11 != 0 ) )
F_6 ( V_17 , L_67 ) ;
F_6 ( V_17 , L_62 , V_10 [ V_11 ] ) ;
}
F_6 ( V_17 , L_68 ) ;
}
return 0 ;
}
