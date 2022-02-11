int F_1 ( T_1 * V_1 )
{
return V_1 -> V_2 -> V_3 ( V_1 ) ;
}
int F_2 ( unsigned char * V_4 , const T_2 * V_5 , T_1 * V_1 )
{
return V_1 -> V_2 -> V_6 ( V_4 , V_5 , V_1 ) ;
}
const T_3 * F_3 ( void )
{
return & V_7 ;
}
static int V_3 ( T_1 * V_1 )
{
int V_8 = 0 ;
int V_9 = 0 ;
unsigned V_10 ;
T_4 * V_11 ;
T_5 * V_12 ;
T_2 * V_5 = NULL , * V_13 = NULL ;
V_11 = F_4 () ;
if ( V_11 == NULL ) goto V_14;
if ( V_1 -> V_13 == NULL )
{
V_13 = F_5 () ;
if ( V_13 == NULL ) goto V_14;
V_9 = 1 ;
}
else
V_13 = V_1 -> V_13 ;
if ( V_1 -> V_5 == NULL )
{
V_5 = F_5 () ;
if ( V_5 == NULL ) goto V_14;
}
else
V_5 = V_1 -> V_5 ;
if ( ( V_1 -> V_15 == NULL ) && ( V_1 -> V_16 & V_17 ) )
{
if ( ( V_1 -> V_15 = ( char * ) F_6 () ) != NULL )
if ( ! F_7 ( ( T_5 * ) V_1 -> V_15 ,
V_1 -> V_18 , V_11 ) ) goto V_14;
}
V_12 = ( T_5 * ) V_1 -> V_15 ;
if ( V_9 )
{
V_10 = V_1 -> V_19 ? V_1 -> V_19 : F_8 ( V_1 -> V_18 ) - 1 ;
if ( ! F_9 ( V_13 , V_10 , 0 , 0 ) ) goto V_14;
}
if ( ! V_1 -> V_2 -> V_20 ( V_1 , V_5 , V_1 -> V_21 , V_13 , V_1 -> V_18 , V_11 , V_12 ) )
goto V_14;
V_1 -> V_5 = V_5 ;
V_1 -> V_13 = V_13 ;
V_8 = 1 ;
V_14:
if ( V_8 != 1 )
F_10 ( V_22 , V_23 ) ;
if ( ( V_5 != NULL ) && ( V_1 -> V_5 == NULL ) ) F_11 ( V_5 ) ;
if ( ( V_13 != NULL ) && ( V_1 -> V_13 == NULL ) ) F_11 ( V_13 ) ;
F_12 ( V_11 ) ;
return ( V_8 ) ;
}
static int V_6 ( unsigned char * V_4 , const T_2 * V_5 , T_1 * V_1 )
{
T_4 * V_11 ;
T_5 * V_12 ;
T_2 * V_24 ;
int V_25 = - 1 ;
V_11 = F_4 () ;
if ( V_11 == NULL ) goto V_14;
F_13 ( V_11 ) ;
V_24 = F_14 ( V_11 ) ;
if ( V_1 -> V_13 == NULL )
{
F_10 ( V_26 , V_27 ) ;
goto V_14;
}
if ( ( V_1 -> V_15 == NULL ) && ( V_1 -> V_16 & V_17 ) )
{
if ( ( V_1 -> V_15 = ( char * ) F_6 () ) != NULL )
if ( ! F_7 ( ( T_5 * ) V_1 -> V_15 ,
V_1 -> V_18 , V_11 ) ) goto V_14;
}
V_12 = ( T_5 * ) V_1 -> V_15 ;
if ( ! V_1 -> V_2 -> V_20 ( V_1 , V_24 , V_5 , V_1 -> V_13 , V_1 -> V_18 , V_11 , V_12 ) )
{
F_10 ( V_26 , V_23 ) ;
goto V_14;
}
V_25 = F_15 ( V_24 , V_4 ) ;
V_14:
F_16 ( V_11 ) ;
F_12 ( V_11 ) ;
return ( V_25 ) ;
}
static int F_17 ( const T_1 * V_1 , T_2 * V_28 ,
const T_2 * V_29 , const T_2 * V_18 ,
const T_2 * V_30 , T_4 * V_11 ,
T_5 * V_31 )
{
if ( V_29 -> V_32 == 1 )
{
T_6 V_33 = V_29 -> V_34 [ 0 ] ;
return F_18 ( V_28 , V_33 , V_18 , V_30 , V_11 , V_31 ) ;
}
else
return F_19 ( V_28 , V_29 , V_18 , V_30 , V_11 , V_31 ) ;
}
static int F_20 ( T_1 * V_1 )
{
V_1 -> V_16 |= V_17 ;
return ( 1 ) ;
}
static int F_21 ( T_1 * V_1 )
{
if( V_1 -> V_15 )
F_22 ( ( T_5 * ) V_1 -> V_15 ) ;
return ( 1 ) ;
}
