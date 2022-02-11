const T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( void * V_2 , T_2 V_3 , const T_3 * V_4 ,
T_4 * V_5 ,
void * (* F_3)( const void * V_6 , T_2 V_7 , void * V_2 , T_2 * V_3 ) )
{
T_5 * V_8 ;
T_3 * V_9 = NULL ;
T_6 * V_10 = NULL , * V_11 = NULL ;
const T_6 * V_12 ;
const T_7 * V_13 ;
int V_14 = - 1 ;
T_2 V_15 , V_16 ;
unsigned char * V_17 = NULL ;
if ( V_3 > V_18 )
{
F_4 ( V_19 , V_20 ) ;
return - 1 ;
}
if ( ( V_8 = F_5 () ) == NULL ) goto V_21;
F_6 ( V_8 ) ;
V_10 = F_7 ( V_8 ) ;
V_11 = F_7 ( V_8 ) ;
V_12 = F_8 ( V_5 ) ;
if ( V_12 == NULL )
{
F_4 ( V_19 , V_22 ) ;
goto V_21;
}
V_13 = F_9 ( V_5 ) ;
if ( ( V_9 = F_10 ( V_13 ) ) == NULL )
{
F_4 ( V_19 , V_20 ) ;
goto V_21;
}
if ( ! F_11 ( V_13 , V_9 , NULL , V_4 , V_12 , V_8 ) )
{
F_4 ( V_19 , V_23 ) ;
goto V_21;
}
if ( F_12 ( F_13 ( V_13 ) ) == V_24 )
{
if ( ! F_14 ( V_13 , V_9 , V_10 , V_11 , V_8 ) )
{
F_4 ( V_19 , V_23 ) ;
goto V_21;
}
}
#ifndef F_15
else
{
if ( ! F_16 ( V_13 , V_9 , V_10 , V_11 , V_8 ) )
{
F_4 ( V_19 , V_23 ) ;
goto V_21;
}
}
#endif
V_15 = ( F_17 ( V_13 ) + 7 ) / 8 ;
V_16 = F_18 ( V_10 ) ;
if ( V_16 > V_15 )
{
F_4 ( V_19 , V_25 ) ;
goto V_21;
}
if ( ( V_17 = F_19 ( V_15 ) ) == NULL )
{
F_4 ( V_19 , V_20 ) ;
goto V_21;
}
memset ( V_17 , 0 , V_15 - V_16 ) ;
if ( V_16 != ( T_2 ) F_20 ( V_10 , V_17 + V_15 - V_16 ) )
{
F_4 ( V_19 , V_26 ) ;
goto V_21;
}
if ( F_3 != 0 )
{
if ( F_3 ( V_17 , V_15 , V_2 , & V_3 ) == NULL )
{
F_4 ( V_19 , V_27 ) ;
goto V_21;
}
V_14 = V_3 ;
}
else
{
if ( V_3 > V_15 )
V_3 = V_15 ;
memcpy ( V_2 , V_17 , V_3 ) ;
V_14 = V_3 ;
}
V_21:
if ( V_9 ) F_21 ( V_9 ) ;
if ( V_8 ) F_22 ( V_8 ) ;
if ( V_8 ) F_23 ( V_8 ) ;
if ( V_17 ) F_24 ( V_17 ) ;
return ( V_14 ) ;
}
