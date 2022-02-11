int F_1 ( T_1 * V_1 )
{
return V_1 -> V_2 -> V_3 ( V_1 ) ;
}
int F_2 ( unsigned char * V_4 , T_2 * V_5 , T_1 * V_1 )
{
return V_1 -> V_2 -> V_6 ( V_4 , V_5 , V_1 ) ;
}
T_3 * F_3 ( void )
{
return & V_7 ;
}
static int V_3 ( T_1 * V_1 )
{
int V_8 = 0 ;
unsigned int V_9 ;
T_4 V_10 ;
T_5 * V_11 ;
T_2 * V_5 = NULL , * V_12 = NULL ;
F_4 ( & V_10 ) ;
if ( V_1 -> V_12 == NULL )
{
V_9 = V_1 -> V_13 ;
if ( V_9 == 0 )
{
V_9 = F_5 ( V_1 -> V_14 ) - 1 ;
}
V_12 = F_6 () ;
if ( V_12 == NULL ) goto V_15;
if ( ! F_7 ( V_12 , V_9 , 0 , 0 ) ) goto V_15;
}
else
V_12 = V_1 -> V_12 ;
if ( V_1 -> V_5 == NULL )
{
V_5 = F_6 () ;
if ( V_5 == NULL ) goto V_15;
}
else
V_5 = V_1 -> V_5 ;
if ( ( V_1 -> V_16 == NULL ) && ( V_1 -> V_17 & V_18 ) )
{
if ( ( V_1 -> V_16 = ( char * ) F_8 () ) != NULL )
if ( ! F_9 ( ( T_5 * ) V_1 -> V_16 ,
V_1 -> V_14 , & V_10 ) ) goto V_15;
}
V_11 = ( T_5 * ) V_1 -> V_16 ;
if ( ! V_1 -> V_2 -> V_19 ( V_1 , V_5 , V_1 -> V_20 , V_12 , V_1 -> V_14 , & V_10 , V_11 ) )
goto V_15;
V_1 -> V_5 = V_5 ;
V_1 -> V_12 = V_12 ;
V_8 = 1 ;
V_15:
if ( V_8 != 1 )
F_10 ( V_21 , V_22 ) ;
if ( ( V_5 != NULL ) && ( V_1 -> V_5 == NULL ) ) F_11 ( V_5 ) ;
if ( ( V_12 != NULL ) && ( V_1 -> V_12 == NULL ) ) F_11 ( V_12 ) ;
F_12 ( & V_10 ) ;
return ( V_8 ) ;
}
static int V_6 ( unsigned char * V_4 , T_2 * V_5 , T_1 * V_1 )
{
T_4 V_10 ;
T_5 * V_11 ;
T_2 * V_23 ;
int V_24 = - 1 ;
F_4 ( & V_10 ) ;
F_13 ( & V_10 ) ;
V_23 = F_14 ( & V_10 ) ;
if ( V_1 -> V_12 == NULL )
{
F_10 ( V_25 , V_26 ) ;
goto V_15;
}
if ( ( V_1 -> V_16 == NULL ) && ( V_1 -> V_17 & V_18 ) )
{
if ( ( V_1 -> V_16 = ( char * ) F_8 () ) != NULL )
if ( ! F_9 ( ( T_5 * ) V_1 -> V_16 ,
V_1 -> V_14 , & V_10 ) ) goto V_15;
}
V_11 = ( T_5 * ) V_1 -> V_16 ;
if ( ! V_1 -> V_2 -> V_19 ( V_1 , V_23 , V_5 , V_1 -> V_12 , V_1 -> V_14 , & V_10 , V_11 ) )
{
F_10 ( V_25 , V_22 ) ;
goto V_15;
}
V_24 = F_15 ( V_23 , V_4 ) ;
V_15:
F_16 ( & V_10 ) ;
F_12 ( & V_10 ) ;
return ( V_24 ) ;
}
static int F_17 ( T_1 * V_1 , T_2 * V_27 , T_2 * V_28 , const T_2 * V_14 ,
const T_2 * V_29 , T_4 * V_10 ,
T_5 * V_30 )
{
if ( V_28 -> V_31 == 1 )
{
T_6 V_32 = V_28 -> V_33 [ 0 ] ;
return F_18 ( V_27 , V_32 , V_14 , V_29 , V_10 , V_30 ) ;
}
else
return F_19 ( V_27 , V_28 , V_14 , V_29 , V_10 , V_30 ) ;
}
static int F_20 ( T_1 * V_1 )
{
V_1 -> V_17 |= V_18 ;
return ( 1 ) ;
}
static int F_21 ( T_1 * V_1 )
{
if( V_1 -> V_16 )
F_22 ( ( T_5 * ) V_1 -> V_16 ) ;
return ( 1 ) ;
}
