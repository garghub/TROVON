int MAIN ( int V_1 , char * * V_2 )
{
unsigned char * V_3 = NULL ;
int V_4 , V_5 = 0 ;
const T_1 * V_6 = NULL , * V_7 ;
T_2 * V_8 = NULL , * V_9 ;
T_2 * V_10 = NULL ;
T_2 * V_11 = NULL ;
const char * V_12 ;
#define F_1 16
char V_13 [ F_1 ] ;
int V_14 = 0 ;
int V_15 = 0 ;
const char * V_16 = NULL , * V_17 = NULL ;
const char * V_18 = NULL , * V_19 = NULL ;
char V_20 = - 1 , V_21 = 0 , V_22 = 0 ;
T_3 * V_23 = NULL ;
unsigned char * V_24 = NULL ;
int V_25 = 0 ;
F_2 () ;
if ( ( V_3 = ( unsigned char * ) F_3 ( V_26 ) ) == NULL )
{
F_4 ( V_27 , L_1 ) ;
goto V_28;
}
if ( V_27 == NULL )
if ( ( V_27 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_27 , V_29 , V_30 | V_31 ) ;
F_8 ( V_2 [ 0 ] , V_13 , F_1 ) ;
V_6 = F_9 ( V_13 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 > 0 )
{
if ( ( * V_2 ) [ 0 ] != '-' ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_17 = * ( ++ V_2 ) ;
V_21 = 1 ;
V_22 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_17 = * ( ++ V_2 ) ;
V_22 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) break;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_20 = 0 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_15 = 1 ;
else if ( ( V_7 = F_9 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
V_6 = V_7 ;
else
break;
V_1 -- ;
V_2 ++ ;
}
if ( V_6 == NULL )
V_6 = F_10 () ;
if( V_22 && ! V_18 ) {
F_4 ( V_27 , L_12 ) ;
V_5 = 1 ;
goto V_28;
}
if ( ( V_1 > 0 ) && ( V_2 [ 0 ] [ 0 ] == '-' ) )
{
F_4 ( V_27 , L_13 , * V_2 ) ;
F_4 ( V_27 , L_14 ) ;
F_4 ( V_27 , L_15 ) ;
F_4 ( V_27 , L_16 ) ;
F_4 ( V_27 , L_17 ) ;
F_4 ( V_27 , L_18 ) ;
F_4 ( V_27 , L_19 ) ;
F_4 ( V_27 , L_20 ) ;
F_4 ( V_27 , L_21 ) ;
F_4 ( V_27 , L_22 ) ;
F_4 ( V_27 , L_18 ) ;
F_4 ( V_27 , L_23 ,
V_32 , V_32 ) ;
F_4 ( V_27 , L_24 ,
V_33 , V_33 ) ;
F_4 ( V_27 , L_24 ,
V_34 , V_34 ) ;
F_4 ( V_27 , L_24 ,
V_35 , V_35 ) ;
F_4 ( V_27 , L_24 ,
V_36 , V_36 ) ;
F_4 ( V_27 , L_24 ,
V_37 , V_37 ) ;
F_4 ( V_27 , L_24 ,
V_38 , V_38 ) ;
V_5 = 1 ;
goto V_28;
}
V_8 = F_5 ( F_6 () ) ;
V_10 = F_5 ( F_11 () ) ;
if ( V_15 )
{
F_12 ( V_8 , V_39 ) ;
F_13 ( V_8 , V_27 ) ;
}
if ( ( V_8 == NULL ) || ( V_10 == NULL ) )
{
F_14 ( V_27 ) ;
goto V_28;
}
if( V_20 == - 1 ) {
if( V_17 ) V_20 = 1 ;
else V_20 = 0 ;
}
if( V_19 )
F_15 ( V_19 , V_27 , 0 ) ;
if( V_16 ) {
if( V_20 )
V_11 = F_16 ( V_16 , L_25 ) ;
else V_11 = F_16 ( V_16 , L_26 ) ;
} else {
V_11 = F_17 ( stdout , V_30 ) ;
#ifdef F_18
{
T_2 * V_40 = F_5 ( F_19 () ) ;
V_11 = F_20 ( V_40 , V_11 ) ;
}
#endif
}
if( ! V_11 ) {
F_4 ( V_27 , L_27 ,
V_16 ? V_16 : L_28 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
if( V_17 ) {
T_2 * V_41 ;
V_41 = F_16 ( V_17 , L_29 ) ;
if( ! V_41 ) {
F_4 ( V_27 , L_30 ,
V_17 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
if( V_21 )
V_23 = F_21 ( V_41 , NULL , NULL , NULL ) ;
else V_23 = F_22 ( V_41 , NULL , NULL , NULL ) ;
F_23 ( V_41 ) ;
if( ! V_23 ) {
F_4 ( V_27 , L_31 ,
V_17 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
}
if( V_18 && V_23 ) {
T_2 * V_42 ;
V_42 = F_16 ( V_18 , L_32 ) ;
V_25 = F_24 ( V_23 ) ;
V_24 = F_3 ( V_25 ) ;
if( ! V_42 ) {
F_4 ( V_27 , L_33 ,
V_18 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
V_25 = F_25 ( V_42 , V_24 , V_25 ) ;
F_23 ( V_42 ) ;
if( V_25 <= 0 ) {
F_4 ( V_27 , L_34 ,
V_18 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
}
F_26 ( V_10 , V_6 ) ;
V_9 = F_20 ( V_10 , V_8 ) ;
if ( V_1 == 0 )
{
F_7 ( V_8 , V_43 , V_30 ) ;
F_27 ( V_11 , V_3 , V_9 , V_14 , V_20 , V_23 , V_24 , V_25 ) ;
}
else
{
V_12 = F_28 ( V_6 -> type ) ;
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ )
{
if ( F_29 ( V_8 , V_2 [ V_4 ] ) <= 0 )
{
perror ( V_2 [ V_4 ] ) ;
V_5 ++ ;
continue;
}
if( ! V_20 ) F_4 ( V_11 , L_35 , V_12 , V_2 [ V_4 ] ) ;
F_27 ( V_11 , V_3 , V_9 , V_14 , V_20 , V_23 ,
V_24 , V_25 ) ;
( void ) F_30 ( V_10 ) ;
}
}
V_28:
if ( V_3 != NULL )
{
memset ( V_3 , 0 , V_26 ) ;
F_31 ( V_3 ) ;
}
if ( V_8 != NULL ) F_23 ( V_8 ) ;
F_32 ( V_11 ) ;
F_33 ( V_23 ) ;
if( V_24 ) F_31 ( V_24 ) ;
if ( V_10 != NULL ) F_23 ( V_10 ) ;
EXIT ( V_5 ) ;
}
void F_27 ( T_2 * V_11 , unsigned char * V_3 , T_2 * V_44 , int V_45 , char V_46 ,
T_3 * V_47 , unsigned char * V_48 , int V_25 )
{
int V_49 ;
int V_4 ;
for (; ; )
{
V_4 = F_25 ( V_44 , ( char * ) V_3 , V_26 ) ;
if ( V_4 <= 0 ) break;
}
if( V_48 )
{
T_4 * V_50 ;
F_34 ( V_44 , & V_50 ) ;
V_4 = F_35 ( V_50 , V_48 , ( unsigned int ) V_25 , V_47 ) ;
if( V_4 > 0 ) F_4 ( V_11 , L_36 ) ;
else if( V_4 == 0 ) F_4 ( V_11 , L_37 ) ;
else
{
F_4 ( V_27 , L_38 ) ;
F_14 ( V_27 ) ;
}
return;
}
if( V_47 )
{
T_4 * V_50 ;
F_34 ( V_44 , & V_50 ) ;
if( ! F_36 ( V_50 , V_3 , ( unsigned int * ) & V_49 , V_47 ) )
{
F_4 ( V_27 , L_39 ) ;
F_14 ( V_27 ) ;
return;
}
}
else
V_49 = F_37 ( V_44 , ( char * ) V_3 , V_26 ) ;
if( V_46 ) F_38 ( V_11 , V_3 , V_49 ) ;
else
{
for ( V_4 = 0 ; V_4 < V_49 ; V_4 ++ )
{
if ( V_45 && ( V_4 != 0 ) )
F_4 ( V_11 , L_40 ) ;
F_4 ( V_11 , L_41 , V_3 [ V_4 ] ) ;
}
F_4 ( V_11 , L_42 ) ;
}
}
