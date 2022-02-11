int MAIN ( int V_1 , char * * V_2 )
{
unsigned char * V_3 = NULL ;
int V_4 , V_5 = 0 ;
const T_1 * V_6 = NULL , * V_7 ;
T_2 * V_8 = NULL , * V_9 ;
T_2 * V_10 = NULL ;
const char * V_11 ;
#define F_1 16
char V_12 [ F_1 ] ;
int V_13 = 0 ;
int V_14 = 0 ;
F_2 () ;
if ( ( V_3 = ( unsigned char * ) Malloc ( V_15 ) ) == NULL )
{
F_3 ( V_16 , L_1 ) ;
goto V_17;
}
if ( V_16 == NULL )
if ( ( V_16 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_16 , V_18 , V_19 | V_20 ) ;
F_7 ( V_2 [ 0 ] , V_12 , F_1 ) ;
V_6 = F_8 ( V_12 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 > 0 )
{
if ( ( * V_2 ) [ 0 ] != '-' ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_14 = 1 ;
else if ( ( V_7 = F_8 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
V_6 = V_7 ;
else
break;
V_1 -- ;
V_2 ++ ;
}
if ( V_6 == NULL )
V_6 = F_9 () ;
if ( ( V_1 > 0 ) && ( V_2 [ 0 ] [ 0 ] == '-' ) )
{
F_3 ( V_16 , L_4 , * V_2 ) ;
F_3 ( V_16 , L_5 ) ;
F_3 ( V_16 , L_6 ) ;
F_3 ( V_16 , L_7 ) ;
F_3 ( V_16 , L_8 ,
V_21 , V_21 ) ;
F_3 ( V_16 , L_9 ,
V_22 , V_22 ) ;
F_3 ( V_16 , L_9 ,
V_23 , V_23 ) ;
F_3 ( V_16 , L_9 ,
V_24 , V_24 ) ;
F_3 ( V_16 , L_9 ,
V_25 , V_25 ) ;
F_3 ( V_16 , L_9 ,
V_26 , V_26 ) ;
V_5 = 1 ;
goto V_17;
}
V_8 = F_4 ( F_5 () ) ;
V_10 = F_4 ( F_10 () ) ;
if ( V_14 )
{
F_11 ( V_8 , V_27 ) ;
F_12 ( V_8 , V_16 ) ;
}
if ( ( V_8 == NULL ) || ( V_10 == NULL ) )
{
F_13 ( V_16 ) ;
goto V_17;
}
F_14 ( V_10 , V_6 ) ;
V_9 = F_15 ( V_10 , V_8 ) ;
if ( V_1 == 0 )
{
F_6 ( V_8 , V_28 , V_19 ) ;
F_16 ( V_3 , V_9 , V_13 ) ;
}
else
{
V_11 = F_17 ( V_6 -> type ) ;
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ )
{
if ( F_18 ( V_8 , V_2 [ V_4 ] ) <= 0 )
{
perror ( V_2 [ V_4 ] ) ;
V_5 ++ ;
continue;
}
printf ( L_10 , V_11 , V_2 [ V_4 ] ) ;
F_16 ( V_3 , V_9 , V_13 ) ;
( void ) F_19 ( V_10 ) ;
}
}
V_17:
if ( V_3 != NULL )
{
memset ( V_3 , 0 , V_15 ) ;
Free ( V_3 ) ;
}
if ( V_8 != NULL ) F_20 ( V_8 ) ;
if ( V_10 != NULL ) F_20 ( V_10 ) ;
EXIT ( V_5 ) ;
}
void F_16 ( unsigned char * V_3 , T_2 * V_29 , int V_30 )
{
int V_31 ;
int V_4 ;
for (; ; )
{
V_4 = F_21 ( V_29 , ( char * ) V_3 , V_15 ) ;
if ( V_4 <= 0 ) break;
}
V_31 = F_22 ( V_29 , ( char * ) V_3 , V_15 ) ;
for ( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
{
if ( V_30 && ( V_4 != 0 ) )
putc ( ':' , stdout ) ;
printf ( L_11 , V_3 [ V_4 ] ) ;
}
printf ( L_12 ) ;
}
