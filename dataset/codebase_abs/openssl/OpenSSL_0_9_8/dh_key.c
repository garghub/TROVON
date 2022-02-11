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
T_5 * V_12 = NULL ;
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
if ( V_1 -> V_15 & V_16 )
{
V_12 = F_6 ( & V_1 -> V_17 ,
V_18 , V_1 -> V_19 , V_11 ) ;
if ( ! V_12 )
goto V_14;
}
if ( V_9 )
{
V_10 = V_1 -> V_20 ? V_1 -> V_20 : F_7 ( V_1 -> V_19 ) - 1 ;
if ( ! F_8 ( V_13 , V_10 , 0 , 0 ) ) goto V_14;
}
{
T_2 V_21 ;
T_2 * V_22 ;
if ( ( V_1 -> V_15 & V_23 ) == 0 )
{
F_9 ( & V_21 ) ;
V_22 = & V_21 ;
F_10 ( V_22 , V_13 , V_24 ) ;
}
else
V_22 = V_13 ;
if ( ! V_1 -> V_2 -> V_25 ( V_1 , V_5 , V_1 -> V_26 , V_22 , V_1 -> V_19 , V_11 , V_12 ) ) goto V_14;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_13 = V_13 ;
V_8 = 1 ;
V_14:
if ( V_8 != 1 )
F_11 ( V_27 , V_28 ) ;
if ( ( V_5 != NULL ) && ( V_1 -> V_5 == NULL ) ) F_12 ( V_5 ) ;
if ( ( V_13 != NULL ) && ( V_1 -> V_13 == NULL ) ) F_12 ( V_13 ) ;
F_13 ( V_11 ) ;
return ( V_8 ) ;
}
static int V_6 ( unsigned char * V_4 , const T_2 * V_5 , T_1 * V_1 )
{
T_4 * V_11 ;
T_5 * V_12 = NULL ;
T_2 * V_29 ;
int V_30 = - 1 ;
V_11 = F_4 () ;
if ( V_11 == NULL ) goto V_14;
F_14 ( V_11 ) ;
V_29 = F_15 ( V_11 ) ;
if ( V_1 -> V_13 == NULL )
{
F_11 ( V_31 , V_32 ) ;
goto V_14;
}
if ( V_1 -> V_15 & V_16 )
{
V_12 = F_6 ( & V_1 -> V_17 ,
V_18 , V_1 -> V_19 , V_11 ) ;
if ( ( V_1 -> V_15 & V_23 ) == 0 )
{
F_16 ( V_1 -> V_13 , V_24 ) ;
}
if ( ! V_12 )
goto V_14;
}
if ( ! V_1 -> V_2 -> V_25 ( V_1 , V_29 , V_5 , V_1 -> V_13 , V_1 -> V_19 , V_11 , V_12 ) )
{
F_11 ( V_31 , V_28 ) ;
goto V_14;
}
V_30 = F_17 ( V_29 , V_4 ) ;
V_14:
F_18 ( V_11 ) ;
F_13 ( V_11 ) ;
return ( V_30 ) ;
}
static int F_19 ( const T_1 * V_1 , T_2 * V_33 ,
const T_2 * V_34 , const T_2 * V_19 ,
const T_2 * V_35 , T_4 * V_11 ,
T_5 * V_36 )
{
if ( V_34 -> V_37 == 1 && ( ( V_1 -> V_15 & V_23 ) != 0 ) )
{
T_6 V_38 = V_34 -> V_39 [ 0 ] ;
return F_20 ( V_33 , V_38 , V_19 , V_35 , V_11 , V_36 ) ;
}
else
return F_21 ( V_33 , V_34 , V_19 , V_35 , V_11 , V_36 ) ;
}
static int F_22 ( T_1 * V_1 )
{
V_1 -> V_15 |= V_16 ;
return ( 1 ) ;
}
static int F_23 ( T_1 * V_1 )
{
if( V_1 -> V_17 )
F_24 ( V_1 -> V_17 ) ;
return ( 1 ) ;
}
