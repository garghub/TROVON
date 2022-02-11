int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
unsigned char * V_4 = NULL ;
int V_5 , V_6 = 0 ;
const T_2 * V_7 = NULL , * V_8 ;
T_3 * V_9 = NULL , * V_10 ;
T_3 * V_11 = NULL ;
T_3 * V_12 = NULL ;
const char * V_13 ;
#define F_1 39
char V_14 [ F_1 + 1 ] ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = V_18 ;
const char * V_19 = NULL , * V_20 = NULL ;
const char * V_21 = NULL , * V_22 = NULL ;
int V_23 = - 1 , V_24 = 0 , V_25 = 0 ;
T_4 * V_26 = NULL ;
unsigned char * V_27 = NULL ;
int V_28 = 0 ;
char * V_29 = NULL , * V_30 = NULL ;
#ifndef F_2
char * V_31 = NULL ;
#endif
F_3 () ;
if ( ( V_4 = ( unsigned char * ) F_4 ( V_32 ) ) == NULL )
{
F_5 ( V_33 , L_1 ) ;
goto V_34;
}
if ( V_33 == NULL )
if ( ( V_33 = F_6 ( F_7 () ) ) != NULL )
F_8 ( V_33 , V_35 , V_36 | V_37 ) ;
if ( ! F_9 ( V_33 , NULL ) )
goto V_34;
F_10 ( V_2 [ 0 ] , V_14 , sizeof V_14 ) ;
V_7 = F_11 ( V_14 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 > 0 )
{
if ( ( * V_2 ) [ 0 ] != '-' ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_20 = * ( ++ V_2 ) ;
}
else if ( ! strcmp ( * V_2 , L_6 ) )
{
if ( -- V_1 < 1 )
break;
V_29 = * ++ V_2 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_20 = * ( ++ V_2 ) ;
V_24 = 1 ;
V_25 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_20 = * ( ++ V_2 ) ;
V_25 = 1 ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_17 = F_12 ( * ( ++ V_2 ) ) ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_31 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_23 = 0 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_23 = 1 ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_16 = 1 ;
else if ( ( V_8 = F_11 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
V_7 = V_8 ;
else
break;
V_1 -- ;
V_2 ++ ;
}
if ( V_7 == NULL )
V_7 = F_13 () ;
if( V_25 && ! V_21 ) {
F_5 ( V_33 , L_15 ) ;
V_6 = 1 ;
goto V_34;
}
if ( ( V_1 > 0 ) && ( V_2 [ 0 ] [ 0 ] == '-' ) )
{
F_5 ( V_33 , L_16 , * V_2 ) ;
F_5 ( V_33 , L_17 ) ;
F_5 ( V_33 , L_18 ) ;
F_5 ( V_33 , L_19 ) ;
F_5 ( V_33 , L_20 ) ;
F_5 ( V_33 , L_21 ) ;
F_5 ( V_33 , L_22 ) ;
F_5 ( V_33 , L_23 ) ;
F_5 ( V_33 , L_24 ) ;
F_5 ( V_33 , L_25 ) ;
F_5 ( V_33 , L_26 ) ;
F_5 ( V_33 , L_21 ) ;
#ifndef F_2
F_5 ( V_33 , L_27 ) ;
#endif
F_5 ( V_33 , L_28 ,
V_38 , V_38 ) ;
F_5 ( V_33 , L_29 ,
V_39 , V_39 ) ;
F_5 ( V_33 , L_29 ,
V_40 , V_40 ) ;
#ifndef F_14
F_5 ( V_33 , L_29 ,
V_41 , V_41 ) ;
F_5 ( V_33 , L_29 ,
V_42 , V_42 ) ;
#ifndef F_15
F_5 ( V_33 , L_29 ,
V_43 , V_43 ) ;
#endif
#ifndef F_16
F_5 ( V_33 , L_29 ,
V_44 , V_44 ) ;
#endif
#endif
F_5 ( V_33 , L_29 ,
V_45 , V_45 ) ;
F_5 ( V_33 , L_29 ,
V_46 , V_46 ) ;
V_6 = 1 ;
goto V_34;
}
#ifndef F_2
V_3 = F_17 ( V_33 , V_31 , 0 ) ;
#endif
V_9 = F_6 ( F_7 () ) ;
V_11 = F_6 ( F_18 () ) ;
if ( V_16 )
{
F_19 ( V_9 , V_47 ) ;
F_20 ( V_9 , V_33 ) ;
}
if( ! F_21 ( V_33 , V_29 , NULL , & V_30 , NULL ) )
{
F_5 ( V_33 , L_30 ) ;
goto V_34;
}
if ( ( V_9 == NULL ) || ( V_11 == NULL ) )
{
F_22 ( V_33 ) ;
goto V_34;
}
if( V_23 == - 1 ) {
if( V_20 ) V_23 = 1 ;
else V_23 = 0 ;
}
if( V_22 )
F_23 ( V_22 , V_33 , 0 ) ;
if( V_19 ) {
if( V_23 )
V_12 = F_24 ( V_19 , L_31 ) ;
else V_12 = F_24 ( V_19 , L_32 ) ;
} else {
V_12 = F_25 ( stdout , V_36 ) ;
#ifdef F_26
{
T_3 * V_48 = F_6 ( F_27 () ) ;
V_12 = F_28 ( V_48 , V_12 ) ;
}
#endif
}
if( ! V_12 ) {
F_5 ( V_33 , L_33 ,
V_19 ? V_19 : L_34 ) ;
F_22 ( V_33 ) ;
goto V_34;
}
if( V_20 )
{
if ( V_24 )
V_26 = F_29 ( V_33 , V_20 , V_17 , 0 , NULL ,
V_3 , L_35 ) ;
else
V_26 = F_30 ( V_33 , V_20 , V_17 , 0 , V_30 ,
V_3 , L_35 ) ;
if ( ! V_26 )
{
goto V_34;
}
}
if( V_21 && V_26 ) {
T_3 * V_49 ;
V_49 = F_24 ( V_21 , L_36 ) ;
V_28 = F_31 ( V_26 ) ;
V_27 = F_4 ( V_28 ) ;
if( ! V_49 ) {
F_5 ( V_33 , L_37 ,
V_21 ) ;
F_22 ( V_33 ) ;
goto V_34;
}
V_28 = F_32 ( V_49 , V_27 , V_28 ) ;
F_33 ( V_49 ) ;
if( V_28 <= 0 ) {
F_5 ( V_33 , L_38 ,
V_21 ) ;
F_22 ( V_33 ) ;
goto V_34;
}
}
if ( ! F_34 ( V_11 , V_7 ) )
{
F_5 ( V_33 , L_39 , V_14 ) ;
F_22 ( V_33 ) ;
goto V_34;
}
V_10 = F_28 ( V_11 , V_9 ) ;
if ( V_1 == 0 )
{
F_8 ( V_9 , V_50 , V_36 ) ;
V_6 = F_35 ( V_12 , V_4 , V_10 , V_15 , V_23 , V_26 , V_27 ,
V_28 , L_40 , L_41 ) ;
}
else
{
V_13 = F_36 ( V_7 -> type ) ;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ )
{
char * V_51 , * V_52 = NULL ;
int V_53 ;
if ( F_37 ( V_9 , V_2 [ V_5 ] ) <= 0 )
{
perror ( V_2 [ V_5 ] ) ;
V_6 ++ ;
continue;
}
if( ! V_23 )
{
T_5 V_54 = strlen ( V_13 ) + strlen ( V_2 [ V_5 ] ) + 5 ;
V_51 = V_52 = F_4 ( V_54 ) ;
F_38 ( V_51 , V_54 , L_42 , V_13 , V_2 [ V_5 ] ) ;
}
else
V_51 = L_40 ;
V_53 = F_35 ( V_12 , V_4 , V_10 , V_15 , V_23 , V_26 , V_27 ,
V_28 , V_51 , V_2 [ V_5 ] ) ;
if( V_53 )
V_6 = V_53 ;
if( V_52 )
F_39 ( V_52 ) ;
( void ) F_40 ( V_11 ) ;
}
}
V_34:
if ( V_4 != NULL )
{
F_41 ( V_4 , V_32 ) ;
F_39 ( V_4 ) ;
}
if ( V_9 != NULL ) F_33 ( V_9 ) ;
if ( V_30 )
F_39 ( V_30 ) ;
F_42 ( V_12 ) ;
F_43 ( V_26 ) ;
if( V_27 ) F_39 ( V_27 ) ;
if ( V_11 != NULL ) F_33 ( V_11 ) ;
F_44 () ;
F_45 ( V_6 ) ;
}
int F_35 ( T_3 * V_12 , unsigned char * V_4 , T_3 * V_55 , int V_56 , int V_57 ,
T_4 * V_58 , unsigned char * V_59 , int V_28 , const char * V_60 ,
const char * V_61 )
{
int V_54 ;
int V_5 ;
for (; ; )
{
V_5 = F_32 ( V_55 , ( char * ) V_4 , V_32 ) ;
if( V_5 < 0 )
{
F_5 ( V_33 , L_43 , V_61 ) ;
F_22 ( V_33 ) ;
return 1 ;
}
if ( V_5 == 0 ) break;
}
if( V_59 )
{
T_6 * V_62 ;
F_46 ( V_55 , & V_62 ) ;
V_5 = F_47 ( V_62 , V_59 , ( unsigned int ) V_28 , V_58 ) ;
if( V_5 > 0 )
F_5 ( V_12 , L_44 ) ;
else if( V_5 == 0 )
{
F_5 ( V_12 , L_45 ) ;
return 1 ;
}
else
{
F_5 ( V_33 , L_46 ) ;
F_22 ( V_33 ) ;
return 1 ;
}
return 0 ;
}
if( V_58 )
{
T_6 * V_62 ;
F_46 ( V_55 , & V_62 ) ;
if( ! F_48 ( V_62 , V_4 , ( unsigned int * ) & V_54 , V_58 ) )
{
F_5 ( V_33 , L_47 ) ;
F_22 ( V_33 ) ;
return 1 ;
}
}
else
V_54 = F_49 ( V_55 , ( char * ) V_4 , V_32 ) ;
if( V_57 ) F_50 ( V_12 , V_4 , V_54 ) ;
else
{
F_50 ( V_12 , V_60 , strlen ( V_60 ) ) ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ )
{
if ( V_56 && ( V_5 != 0 ) )
F_5 ( V_12 , L_48 ) ;
F_5 ( V_12 , L_49 , V_4 [ V_5 ] ) ;
}
F_5 ( V_12 , L_50 ) ;
}
return 0 ;
}
