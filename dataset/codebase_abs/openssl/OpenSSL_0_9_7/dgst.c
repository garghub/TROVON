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
char * V_29 = NULL ;
F_2 () ;
if ( ( V_4 = ( unsigned char * ) F_3 ( V_30 ) ) == NULL )
{
F_4 ( V_31 , L_1 ) ;
goto V_32;
}
if ( V_31 == NULL )
if ( ( V_31 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_31 , V_33 , V_34 | V_35 ) ;
if ( ! F_8 ( V_31 , NULL ) )
goto V_32;
F_9 ( V_2 [ 0 ] , V_14 , sizeof V_14 ) ;
V_7 = F_10 ( V_14 ) ;
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
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_20 = * ( ++ V_2 ) ;
V_24 = 1 ;
V_25 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_20 = * ( ++ V_2 ) ;
V_25 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_17 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_29 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_23 = 0 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_23 = 1 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_16 = 1 ;
else if ( ( V_8 = F_10 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
V_7 = V_8 ;
else
break;
V_1 -- ;
V_2 ++ ;
}
if ( V_7 == NULL )
V_7 = F_12 () ;
if( V_25 && ! V_21 ) {
F_4 ( V_31 , L_14 ) ;
V_6 = 1 ;
goto V_32;
}
if ( ( V_1 > 0 ) && ( V_2 [ 0 ] [ 0 ] == '-' ) )
{
F_4 ( V_31 , L_15 , * V_2 ) ;
F_4 ( V_31 , L_16 ) ;
F_4 ( V_31 , L_17 ) ;
F_4 ( V_31 , L_18 ) ;
F_4 ( V_31 , L_19 ) ;
F_4 ( V_31 , L_20 ) ;
F_4 ( V_31 , L_21 ) ;
F_4 ( V_31 , L_22 ) ;
F_4 ( V_31 , L_23 ) ;
F_4 ( V_31 , L_24 ) ;
F_4 ( V_31 , L_25 ) ;
F_4 ( V_31 , L_20 ) ;
F_4 ( V_31 , L_26 ) ;
F_4 ( V_31 , L_27 ,
V_36 , V_36 ) ;
F_4 ( V_31 , L_28 ,
V_37 , V_37 ) ;
F_4 ( V_31 , L_28 ,
V_38 , V_38 ) ;
F_4 ( V_31 , L_28 ,
V_39 , V_39 ) ;
F_4 ( V_31 , L_28 ,
V_40 , V_40 ) ;
F_4 ( V_31 , L_28 ,
V_41 , V_41 ) ;
F_4 ( V_31 , L_28 ,
V_42 , V_42 ) ;
V_6 = 1 ;
goto V_32;
}
V_3 = F_13 ( V_31 , V_29 , 0 ) ;
V_9 = F_5 ( F_6 () ) ;
V_11 = F_5 ( F_14 () ) ;
if ( V_16 )
{
F_15 ( V_9 , V_43 ) ;
F_16 ( V_9 , V_31 ) ;
}
if ( ( V_9 == NULL ) || ( V_11 == NULL ) )
{
F_17 ( V_31 ) ;
goto V_32;
}
if( V_23 == - 1 ) {
if( V_20 ) V_23 = 1 ;
else V_23 = 0 ;
}
if( V_22 )
F_18 ( V_22 , V_31 , 0 ) ;
if( V_19 ) {
if( V_23 )
V_12 = F_19 ( V_19 , L_29 ) ;
else V_12 = F_19 ( V_19 , L_30 ) ;
} else {
V_12 = F_20 ( stdout , V_34 ) ;
#ifdef F_21
{
T_3 * V_44 = F_5 ( F_22 () ) ;
V_12 = F_23 ( V_44 , V_12 ) ;
}
#endif
}
if( ! V_12 ) {
F_4 ( V_31 , L_31 ,
V_19 ? V_19 : L_32 ) ;
F_17 ( V_31 ) ;
goto V_32;
}
if( V_20 )
{
if ( V_24 )
V_26 = F_24 ( V_31 , V_20 , V_17 , 0 , NULL ,
V_3 , L_33 ) ;
else
V_26 = F_25 ( V_31 , V_20 , V_17 , 0 , NULL ,
V_3 , L_33 ) ;
if ( ! V_26 )
{
goto V_32;
}
}
if( V_21 && V_26 ) {
T_3 * V_45 ;
V_45 = F_19 ( V_21 , L_34 ) ;
V_28 = F_26 ( V_26 ) ;
V_27 = F_3 ( V_28 ) ;
if( ! V_45 ) {
F_4 ( V_31 , L_35 ,
V_21 ) ;
F_17 ( V_31 ) ;
goto V_32;
}
V_28 = F_27 ( V_45 , V_27 , V_28 ) ;
F_28 ( V_45 ) ;
if( V_28 <= 0 ) {
F_4 ( V_31 , L_36 ,
V_21 ) ;
F_17 ( V_31 ) ;
goto V_32;
}
}
F_29 ( V_11 , V_7 ) ;
V_10 = F_23 ( V_11 , V_9 ) ;
if ( V_1 == 0 )
{
F_7 ( V_9 , V_46 , V_34 ) ;
V_6 = F_30 ( V_12 , V_4 , V_10 , V_15 , V_23 , V_26 , V_27 ,
V_28 , L_37 , L_38 ) ;
}
else
{
V_13 = F_31 ( V_7 -> type ) ;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ )
{
char * V_47 , * V_48 = NULL ;
int V_49 ;
if ( F_32 ( V_9 , V_2 [ V_5 ] ) <= 0 )
{
perror ( V_2 [ V_5 ] ) ;
V_6 ++ ;
continue;
}
if( ! V_23 )
{
V_47 = V_48 = F_3 ( strlen ( V_13 ) + strlen ( V_2 [ V_5 ] ) + 5 ) ;
sprintf ( V_47 , L_39 , V_13 , V_2 [ V_5 ] ) ;
}
else
V_47 = L_37 ;
V_49 = F_30 ( V_12 , V_4 , V_10 , V_15 , V_23 , V_26 , V_27 ,
V_28 , V_47 , V_2 [ V_5 ] ) ;
if( V_49 )
V_6 = V_49 ;
if( V_48 )
F_33 ( V_48 ) ;
( void ) F_34 ( V_11 ) ;
}
}
V_32:
if ( V_4 != NULL )
{
F_35 ( V_4 , V_30 ) ;
F_33 ( V_4 ) ;
}
if ( V_9 != NULL ) F_28 ( V_9 ) ;
F_36 ( V_12 ) ;
F_37 ( V_26 ) ;
if( V_27 ) F_33 ( V_27 ) ;
if ( V_11 != NULL ) F_28 ( V_11 ) ;
F_38 () ;
F_39 ( V_6 ) ;
}
int F_30 ( T_3 * V_12 , unsigned char * V_4 , T_3 * V_50 , int V_51 , int V_52 ,
T_4 * V_53 , unsigned char * V_54 , int V_28 , const char * V_55 ,
const char * V_56 )
{
int V_57 ;
int V_5 ;
for (; ; )
{
V_5 = F_27 ( V_50 , ( char * ) V_4 , V_30 ) ;
if( V_5 < 0 )
{
F_4 ( V_31 , L_40 , V_56 ) ;
F_17 ( V_31 ) ;
return 1 ;
}
if ( V_5 == 0 ) break;
}
if( V_54 )
{
T_5 * V_58 ;
F_40 ( V_50 , & V_58 ) ;
V_5 = F_41 ( V_58 , V_54 , ( unsigned int ) V_28 , V_53 ) ;
if( V_5 > 0 )
F_4 ( V_12 , L_41 ) ;
else if( V_5 == 0 )
{
F_4 ( V_12 , L_42 ) ;
return 1 ;
}
else
{
F_4 ( V_31 , L_43 ) ;
F_17 ( V_31 ) ;
return 1 ;
}
return 0 ;
}
if( V_53 )
{
T_5 * V_58 ;
F_40 ( V_50 , & V_58 ) ;
if( ! F_42 ( V_58 , V_4 , ( unsigned int * ) & V_57 , V_53 ) )
{
F_4 ( V_31 , L_44 ) ;
F_17 ( V_31 ) ;
return 1 ;
}
}
else
V_57 = F_43 ( V_50 , ( char * ) V_4 , V_30 ) ;
if( V_52 ) F_44 ( V_12 , V_4 , V_57 ) ;
else
{
F_44 ( V_12 , V_55 , strlen ( V_55 ) ) ;
for ( V_5 = 0 ; V_5 < V_57 ; V_5 ++ )
{
if ( V_51 && ( V_5 != 0 ) )
F_4 ( V_12 , L_45 ) ;
F_4 ( V_12 , L_46 , V_4 [ V_5 ] ) ;
}
F_4 ( V_12 , L_47 ) ;
}
return 0 ;
}
