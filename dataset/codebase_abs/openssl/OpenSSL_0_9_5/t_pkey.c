int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_6 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_6 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_6 ( T_3 * V_9 , T_2 * V_2 , int V_3 )
{
char V_10 [ 128 ] ;
const char * V_11 ;
unsigned char * V_12 = NULL ;
int V_13 , V_5 = 0 ;
V_13 = F_8 ( V_2 ) ;
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_13 + 10 ) ;
if ( V_12 == NULL )
{
F_4 ( V_14 , V_15 ) ;
goto V_16;
}
if ( V_3 )
{
if ( V_3 > 128 ) V_3 = 128 ;
memset ( V_10 , ' ' , V_3 ) ;
}
if ( V_2 -> V_17 != NULL )
{
if ( V_3 && ( F_9 ( V_9 , V_10 , V_3 ) <= 0 ) ) goto V_16;
if ( F_10 ( V_9 , L_1 , F_11 ( V_2 -> V_18 ) )
<= 0 ) goto V_16;
}
if ( V_2 -> V_17 == NULL )
sprintf ( V_10 , L_2 , F_11 ( V_2 -> V_18 ) ) ;
else
strcpy ( V_10 , L_3 ) ;
if ( ! F_12 ( V_9 , V_10 , V_2 -> V_18 , V_12 , V_3 ) ) goto V_16;
V_11 = ( V_2 -> V_17 == NULL ) ? L_4 : L_5 ;
if ( ! F_12 ( V_9 , V_11 , V_2 -> V_19 , V_12 , V_3 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_6 , V_2 -> V_17 , V_12 , V_3 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_7 , V_2 -> V_20 , V_12 , V_3 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_8 , V_2 -> V_21 , V_12 , V_3 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_9 , V_2 -> V_22 , V_12 , V_3 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_10 , V_2 -> V_23 , V_12 , V_3 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_11 , V_2 -> V_24 , V_12 , V_3 ) ) goto V_16;
V_5 = 1 ;
V_16:
if ( V_12 != NULL ) Free ( V_12 ) ;
return ( V_5 ) ;
}
int F_13 ( T_1 * V_1 , T_4 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_14 ( V_25 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_15 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_15 ( T_3 * V_9 , T_4 * V_2 , int V_3 )
{
char V_10 [ 128 ] ;
unsigned char * V_12 = NULL ;
int V_13 , V_5 = 0 ;
T_5 * V_26 = NULL ;
if ( V_2 -> V_20 != NULL )
V_26 = V_2 -> V_20 ;
else if ( V_2 -> V_27 != NULL )
V_26 = V_2 -> V_27 ;
else if ( V_2 -> V_28 != NULL )
V_26 = V_2 -> V_28 ;
if ( V_26 != NULL )
V_13 = F_16 ( V_26 ) * 2 ;
else
V_13 = 256 ;
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_13 + 10 ) ;
if ( V_12 == NULL )
{
F_14 ( V_29 , V_15 ) ;
goto V_16;
}
if ( V_3 )
{
if ( V_3 > 128 ) V_3 = 128 ;
memset ( V_10 , ' ' , V_3 ) ;
}
if ( V_2 -> V_27 != NULL )
{
if ( V_3 && ( F_9 ( V_9 , V_10 , V_3 ) <= 0 ) ) goto V_16;
if ( F_10 ( V_9 , L_1 , F_11 ( V_2 -> V_20 ) )
<= 0 ) goto V_16;
}
if ( ( V_2 -> V_27 != NULL ) && ! F_12 ( V_9 , L_12 , V_2 -> V_27 , V_12 , V_3 ) )
goto V_16;
if ( ( V_2 -> V_28 != NULL ) && ! F_12 ( V_9 , L_13 , V_2 -> V_28 , V_12 , V_3 ) )
goto V_16;
if ( ( V_2 -> V_20 != NULL ) && ! F_12 ( V_9 , L_14 , V_2 -> V_20 , V_12 , V_3 ) ) goto V_16;
if ( ( V_2 -> V_21 != NULL ) && ! F_12 ( V_9 , L_15 , V_2 -> V_21 , V_12 , V_3 ) ) goto V_16;
if ( ( V_2 -> V_30 != NULL ) && ! F_12 ( V_9 , L_16 , V_2 -> V_30 , V_12 , V_3 ) ) goto V_16;
V_5 = 1 ;
V_16:
if ( V_12 != NULL ) Free ( V_12 ) ;
return ( V_5 ) ;
}
static int F_12 ( T_3 * V_9 , const char * V_31 , T_5 * V_32 , unsigned char * V_33 ,
int V_3 )
{
int V_18 , V_13 ;
char V_10 [ 128 ] ;
const char * V_34 ;
if ( V_32 == NULL ) return ( 1 ) ;
V_34 = ( V_32 -> V_34 ) ? L_17 : L_18 ;
if ( V_3 )
{
if ( V_3 > 128 ) V_3 = 128 ;
memset ( V_10 , ' ' , V_3 ) ;
if ( F_9 ( V_9 , V_10 , V_3 ) <= 0 ) return ( 0 ) ;
}
if ( F_16 ( V_32 ) <= V_35 )
{
if ( F_10 ( V_9 , L_19 , V_31 , V_34 ,
( unsigned long ) V_32 -> V_17 [ 0 ] , V_34 , ( unsigned long ) V_32 -> V_17 [ 0 ] )
<= 0 ) return ( 0 ) ;
}
else
{
V_33 [ 0 ] = 0 ;
if ( F_10 ( V_9 , L_20 , V_31 ,
( V_34 [ 0 ] == '-' ) ? L_21 : L_18 ) <= 0 )
return ( 0 ) ;
V_18 = F_17 ( V_32 , & V_33 [ 1 ] ) ;
if ( V_33 [ 1 ] & 0x80 )
V_18 ++ ;
else V_33 ++ ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ )
{
if ( ( V_13 % 15 ) == 0 )
{
V_10 [ 0 ] = '\n' ;
memset ( & ( V_10 [ 1 ] ) , ' ' , V_3 + 4 ) ;
if ( F_9 ( V_9 , V_10 , V_3 + 1 + 4 ) <= 0 ) return ( 0 ) ;
}
if ( F_10 ( V_9 , L_22 , V_33 [ V_13 ] , ( ( V_13 + 1 ) == V_18 ) ? L_18 : L_23 )
<= 0 ) return ( 0 ) ;
}
if ( F_9 ( V_9 , L_24 , 1 ) <= 0 ) return ( 0 ) ;
}
return ( 1 ) ;
}
int F_18 ( T_1 * V_1 , T_6 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_19 ( V_36 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_20 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_20 ( T_3 * V_9 , T_6 * V_2 )
{
unsigned char * V_12 = NULL ;
int V_37 = V_7 , V_13 , V_5 = 0 ;
V_13 = F_16 ( V_2 -> V_20 ) ;
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_13 + 10 ) ;
if ( V_12 == NULL )
{
V_37 = V_15 ;
goto V_16;
}
if ( F_10 ( V_9 , L_25 ,
F_11 ( V_2 -> V_20 ) ) <= 0 )
goto V_16;
if ( ! F_12 ( V_9 , L_26 , V_2 -> V_20 , V_12 , 4 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_27 , V_2 -> V_30 , V_12 , 4 ) ) goto V_16;
if ( V_2 -> V_38 != 0 )
{
if ( F_10 ( V_9 , L_28 ,
( int ) V_2 -> V_38 ) <= 0 ) goto V_16;
}
V_5 = 1 ;
if ( 0 )
{
V_16:
F_19 ( V_39 , V_37 ) ;
}
if ( V_12 != NULL ) Free ( V_12 ) ;
return ( V_5 ) ;
}
int F_21 ( T_1 * V_1 , T_4 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_14 ( V_40 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_22 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_22 ( T_3 * V_9 , T_4 * V_2 )
{
unsigned char * V_12 = NULL ;
int V_37 = V_7 , V_13 , V_5 = 0 ;
V_13 = F_16 ( V_2 -> V_20 ) ;
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_13 + 10 ) ;
if ( V_12 == NULL )
{
V_37 = V_15 ;
goto V_16;
}
if ( F_10 ( V_9 , L_29 ,
F_11 ( V_2 -> V_20 ) ) <= 0 )
goto V_16;
if ( ! F_12 ( V_9 , L_30 , V_2 -> V_20 , V_12 , 4 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_31 , V_2 -> V_21 , V_12 , 4 ) ) goto V_16;
if ( ! F_12 ( V_9 , L_32 , V_2 -> V_30 , V_12 , 4 ) ) goto V_16;
V_5 = 1 ;
V_16:
if ( V_12 != NULL ) Free ( V_12 ) ;
F_14 ( V_41 , V_37 ) ;
return ( V_5 ) ;
}
