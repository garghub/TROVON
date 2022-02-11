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
int V_38 = 0 ;
F_9 ( V_39 ) * V_40 = NULL , * V_41 = NULL ;
F_10 () ;
if ( ( V_10 = ( unsigned char * ) F_11 ( V_42 ) ) == NULL )
{
F_6 ( V_43 , L_2 ) ;
goto V_44;
}
if ( V_43 == NULL )
if ( ( V_43 = F_12 ( F_13 () ) ) != NULL )
F_14 ( V_43 , V_45 , V_46 | V_47 ) ;
if ( ! F_15 ( V_43 , NULL ) )
goto V_44;
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
V_9 = F_19 ( V_43 , V_35 , 0 ) ;
}
#endif
else if ( strcmp ( * V_8 , L_14 ) == 0 )
V_27 = 0 ;
else if ( strcmp ( * V_8 , L_15 ) == 0 )
V_27 = 1 ;
else if ( strcmp ( * V_8 , L_16 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_8 , L_17 ) == 0 )
V_38 = 1 ;
else if ( ! strcmp ( * V_8 , L_18 ) )
V_36 = L_19 ;
else if ( ! strcmp ( * V_8 , L_20 ) )
{
if ( -- V_7 < 1 )
break;
V_36 = * ++ V_8 ;
}
else if ( ! strcmp ( * V_8 , L_21 ) )
{
if ( -- V_7 < 1 )
break;
V_37 = * ++ V_8 ;
}
else if ( strcmp ( * V_8 , L_22 ) == 0 )
{
if ( -- V_7 < 1 )
break;
if ( ! V_40 )
V_40 = F_20 () ;
if ( ! V_40 || ! F_21 ( V_40 , * ( ++ V_8 ) ) )
break;
}
else if ( strcmp ( * V_8 , L_23 ) == 0 )
{
if ( -- V_7 < 1 )
break;
if ( ! V_41 )
V_41 = F_20 () ;
if ( ! V_41 || ! F_21 ( V_41 , * ( ++ V_8 ) ) )
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
F_6 ( V_43 , L_24 ) ;
goto V_44;
}
if ( ( V_7 > 0 ) && ( V_8 [ 0 ] [ 0 ] == '-' ) )
{
F_6 ( V_43 , L_25 , * V_8 ) ;
F_6 ( V_43 , L_26 ) ;
F_6 ( V_43 , L_27 ) ;
F_6 ( V_43 , L_28 ) ;
F_6 ( V_43 , L_29 ) ;
F_6 ( V_43 , L_30 ) ;
F_6 ( V_43 , L_31 ) ;
F_6 ( V_43 , L_32 ) ;
F_6 ( V_43 , L_33 ) ;
F_6 ( V_43 , L_34 ) ;
F_6 ( V_43 , L_35 ) ;
F_6 ( V_43 , L_36 ) ;
F_6 ( V_43 , L_37 ) ;
F_6 ( V_43 , L_38 ) ;
F_6 ( V_43 , L_39 ) ;
F_6 ( V_43 , L_40 ) ;
F_6 ( V_43 , L_41 ) ;
#ifndef F_8
F_6 ( V_43 , L_42 ) ;
#endif
F_22 ( F_1 , V_43 ) ;
goto V_44;
}
V_14 = F_12 ( F_13 () ) ;
V_16 = F_12 ( F_23 () ) ;
if ( V_20 )
{
F_24 ( V_14 , V_48 ) ;
F_25 ( V_14 , ( char * ) V_43 ) ;
}
if( ! F_26 ( V_43 , V_33 , NULL , & V_34 , NULL ) )
{
F_6 ( V_43 , L_43 ) ;
goto V_44;
}
if ( ( V_14 == NULL ) || ( V_16 == NULL ) )
{
F_27 ( V_43 ) ;
goto V_44;
}
if( V_27 == - 1 ) {
if( V_24 )
V_27 = 1 ;
else
V_27 = 0 ;
}
if( V_26 )
F_28 ( V_26 , V_43 , 0 ) ;
if( V_23 ) {
if( V_27 )
V_17 = F_29 ( V_23 , L_44 ) ;
else V_17 = F_29 ( V_23 , L_45 ) ;
} else {
V_17 = F_30 ( stdout , V_46 ) ;
#ifdef F_31
{
T_3 * V_49 = F_12 ( F_32 () ) ;
V_17 = F_33 ( V_49 , V_17 ) ;
}
#endif
}
if( ! V_17 ) {
F_6 ( V_43 , L_46 ,
V_23 ? V_23 : L_47 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
if ( ( ! ! V_37 + ! ! V_24 + ! ! V_36 ) > 1 )
{
F_6 ( V_43 , L_48 ) ;
goto V_44;
}
if( V_24 )
{
if ( V_28 )
V_30 = F_34 ( V_43 , V_24 , V_21 , 0 , NULL ,
V_9 , L_49 ) ;
else
V_30 = F_35 ( V_43 , V_24 , V_21 , 0 , V_34 ,
V_9 , L_49 ) ;
if ( ! V_30 )
{
goto V_44;
}
}
if ( V_37 )
{
T_5 * V_50 = NULL ;
int V_51 = 0 ;
if ( ! F_36 ( V_43 , & V_50 , V_37 , V_9 , 0 ) )
goto V_52;
if ( V_41 )
{
char * V_53 ;
for ( V_11 = 0 ; V_11 < F_37 ( V_41 ) ; V_11 ++ )
{
V_53 = F_38 ( V_41 , V_11 ) ;
if ( F_39 ( V_50 , V_53 ) <= 0 )
{
F_6 ( V_43 ,
L_50 ,
V_53 ) ;
F_27 ( V_43 ) ;
goto V_52;
}
}
}
if ( F_40 ( V_50 , & V_30 ) <= 0 )
{
F_41 ( V_43 , L_51 ) ;
F_27 ( V_43 ) ;
goto V_52;
}
V_51 = 1 ;
V_52:
if ( V_50 )
F_42 ( V_50 ) ;
if ( V_51 == 0 )
goto V_44;
}
if ( V_38 )
{
T_6 * V_54 ;
F_43 ( V_16 , & V_54 ) ;
F_44 ( V_54 , V_55 ) ;
}
if ( V_36 )
{
V_30 = F_45 ( V_56 , V_9 ,
( unsigned char * ) V_36 , - 1 ) ;
if ( ! V_30 )
goto V_44;
}
if ( V_30 )
{
T_6 * V_57 = NULL ;
T_5 * V_58 = NULL ;
int V_51 ;
if ( ! F_43 ( V_16 , & V_57 ) )
{
F_6 ( V_43 , L_52 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
if ( V_29 )
V_51 = F_46 ( V_57 , & V_58 , V_13 , V_9 , V_30 ) ;
else
V_51 = F_47 ( V_57 , & V_58 , V_13 , V_9 , V_30 ) ;
if ( ! V_51 )
{
F_6 ( V_43 , L_53 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
if ( V_40 )
{
char * V_59 ;
for ( V_11 = 0 ; V_11 < F_37 ( V_40 ) ; V_11 ++ )
{
V_59 = F_38 ( V_40 , V_11 ) ;
if ( F_39 ( V_58 , V_59 ) <= 0 )
{
F_6 ( V_43 ,
L_54 ,
V_59 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
}
}
}
else
{
if ( V_13 == NULL )
V_13 = F_48 () ;
if ( ! F_49 ( V_16 , V_13 ) )
{
F_6 ( V_43 , L_55 , V_18 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
}
if( V_25 && V_30 ) {
T_3 * V_60 ;
V_60 = F_29 ( V_25 , L_56 ) ;
V_32 = F_50 ( V_30 ) ;
V_31 = F_11 ( V_32 ) ;
if( ! V_60 ) {
F_6 ( V_43 , L_57 ,
V_25 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
V_32 = F_51 ( V_60 , V_31 , V_32 ) ;
F_52 ( V_60 ) ;
if( V_32 <= 0 ) {
F_6 ( V_43 , L_58 ,
V_25 ) ;
F_27 ( V_43 ) ;
goto V_44;
}
}
V_15 = F_33 ( V_16 , V_14 ) ;
if ( V_13 == NULL )
{
T_6 * V_61 ;
F_43 ( V_16 , & V_61 ) ;
V_13 = F_53 ( V_61 ) ;
}
if ( V_7 == 0 )
{
F_14 ( V_14 , V_62 , V_46 ) ;
V_12 = F_54 ( V_17 , V_10 , V_15 , V_19 , V_27 , V_30 , V_31 ,
V_32 , NULL , NULL , L_59 , V_16 ) ;
}
else
{
const char * V_63 = NULL , * V_64 = NULL ;
if( ! V_27 )
{
if ( V_30 )
{
const T_7 * V_65 ;
V_65 = F_55 ( V_30 ) ;
if ( V_65 )
F_56 ( NULL , NULL ,
NULL , NULL , & V_64 , V_65 ) ;
}
V_63 = F_5 ( V_13 ) ;
}
V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ )
{
int V_51 ;
if ( F_57 ( V_14 , V_8 [ V_11 ] ) <= 0 )
{
perror ( V_8 [ V_11 ] ) ;
V_12 ++ ;
continue;
}
else
V_51 = F_54 ( V_17 , V_10 , V_15 , V_19 , V_27 , V_30 , V_31 ,
V_32 , V_64 , V_63 , V_8 [ V_11 ] , V_16 ) ;
if( V_51 )
V_12 = V_51 ;
( void ) F_58 ( V_16 ) ;
}
}
V_44:
if ( V_10 != NULL )
{
F_59 ( V_10 , V_42 ) ;
F_60 ( V_10 ) ;
}
if ( V_14 != NULL ) F_52 ( V_14 ) ;
if ( V_34 )
F_60 ( V_34 ) ;
F_61 ( V_17 ) ;
F_62 ( V_30 ) ;
if ( V_40 )
F_63 ( V_40 ) ;
if ( V_41 )
F_63 ( V_41 ) ;
if( V_31 ) F_60 ( V_31 ) ;
if ( V_16 != NULL ) F_52 ( V_16 ) ;
F_64 () ;
F_65 ( V_12 ) ;
}
int F_54 ( T_3 * V_17 , unsigned char * V_10 , T_3 * V_66 , int V_67 , int V_68 ,
T_4 * V_69 , unsigned char * V_70 , int V_32 ,
const char * V_64 , const char * V_63 ,
const char * V_71 , T_3 * V_16 )
{
T_8 V_72 ;
int V_11 ;
for (; ; )
{
V_11 = F_51 ( V_66 , ( char * ) V_10 , V_42 ) ;
if( V_11 < 0 )
{
F_6 ( V_43 , L_60 , V_71 ) ;
F_27 ( V_43 ) ;
return 1 ;
}
if ( V_11 == 0 ) break;
}
if( V_70 )
{
T_6 * V_73 ;
F_43 ( V_66 , & V_73 ) ;
V_11 = F_66 ( V_73 , V_70 , ( unsigned int ) V_32 ) ;
if( V_11 > 0 )
F_6 ( V_17 , L_61 ) ;
else if( V_11 == 0 )
{
F_6 ( V_17 , L_62 ) ;
return 1 ;
}
else
{
F_6 ( V_43 , L_63 ) ;
F_27 ( V_43 ) ;
return 1 ;
}
return 0 ;
}
if( V_69 )
{
T_6 * V_73 ;
F_43 ( V_66 , & V_73 ) ;
V_72 = V_42 ;
if( ! F_67 ( V_73 , V_10 , & V_72 ) )
{
F_6 ( V_43 , L_64 ) ;
F_27 ( V_43 ) ;
return 1 ;
}
}
else
{
V_72 = F_68 ( V_66 , ( char * ) V_10 , V_42 ) ;
if ( ( int ) V_72 < 0 )
{
F_27 ( V_43 ) ;
return 1 ;
}
}
if( V_68 ) F_69 ( V_17 , V_10 , V_72 ) ;
else if ( V_67 == 2 )
{
for ( V_11 = 0 ; V_11 < ( int ) V_72 ; V_11 ++ )
F_6 ( V_17 , L_65 , V_10 [ V_11 ] ) ;
F_6 ( V_17 , L_66 , V_71 ) ;
}
else
{
if ( V_64 )
F_6 ( V_17 , L_67 , V_64 , V_63 , V_71 ) ;
else if ( V_63 )
F_6 ( V_17 , L_68 , V_63 , V_71 ) ;
else
F_6 ( V_17 , L_69 , V_71 ) ;
for ( V_11 = 0 ; V_11 < ( int ) V_72 ; V_11 ++ )
{
if ( V_67 && ( V_11 != 0 ) )
F_6 ( V_17 , L_70 ) ;
F_6 ( V_17 , L_65 , V_10 [ V_11 ] ) ;
}
F_6 ( V_17 , L_71 ) ;
}
return 0 ;
}
