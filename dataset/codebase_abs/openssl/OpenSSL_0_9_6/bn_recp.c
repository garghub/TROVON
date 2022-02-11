void F_1 ( T_1 * V_1 )
{
F_2 ( & ( V_1 -> V_2 ) ) ;
F_2 ( & ( V_1 -> V_3 ) ) ;
V_1 -> V_4 = 0 ;
V_1 -> V_5 = 0 ;
}
T_1 * F_3 ( void )
{
T_1 * V_6 ;
if ( ( V_6 = ( T_1 * ) F_4 ( sizeof( T_1 ) ) ) == NULL )
return ( NULL ) ;
F_1 ( V_6 ) ;
V_6 -> V_5 = V_7 ;
return ( V_6 ) ;
}
void F_5 ( T_1 * V_1 )
{
if( V_1 == NULL )
return;
F_6 ( & ( V_1 -> V_2 ) ) ;
F_6 ( & ( V_1 -> V_3 ) ) ;
if ( V_1 -> V_5 & V_7 )
F_7 ( V_1 ) ;
}
int F_8 ( T_1 * V_1 , const T_2 * V_8 , T_3 * V_9 )
{
F_9 ( & ( V_1 -> V_2 ) , V_8 ) ;
F_10 ( & ( V_1 -> V_3 ) ) ;
V_1 -> V_4 = F_11 ( V_8 ) ;
V_1 -> V_10 = 0 ;
return ( 1 ) ;
}
int F_12 ( T_2 * V_11 , T_2 * V_12 , T_2 * V_13 , T_1 * V_1 ,
T_3 * V_9 )
{
int V_6 = 0 ;
T_2 * V_14 ;
F_13 ( V_9 ) ;
if ( ( V_14 = F_14 ( V_9 ) ) == NULL ) goto V_15;
if ( V_13 != NULL )
{
if ( V_12 == V_13 )
{ if ( ! F_15 ( V_14 , V_12 , V_9 ) ) goto V_15; }
else
{ if ( ! F_16 ( V_14 , V_12 , V_13 , V_9 ) ) goto V_15; }
}
else
V_14 = V_12 ;
F_17 ( NULL , V_11 , V_14 , V_1 , V_9 ) ;
V_6 = 1 ;
V_15:
F_18 ( V_9 ) ;
return ( V_6 ) ;
}
int F_17 ( T_2 * V_16 , T_2 * V_17 , T_2 * V_18 , T_1 * V_1 ,
T_3 * V_9 )
{
int V_19 , V_20 , V_6 = 0 ;
T_2 * V_14 , * V_21 , * V_8 , * V_11 ;
F_13 ( V_9 ) ;
V_14 = F_14 ( V_9 ) ;
V_21 = F_14 ( V_9 ) ;
if ( V_16 != NULL )
V_8 = V_16 ;
else
V_8 = F_14 ( V_9 ) ;
if ( V_17 != NULL )
V_11 = V_17 ;
else
V_11 = F_14 ( V_9 ) ;
if ( V_14 == NULL || V_21 == NULL || V_8 == NULL || V_11 == NULL ) goto V_15;
if ( F_19 ( V_18 , & ( V_1 -> V_2 ) ) < 0 )
{
F_10 ( V_8 ) ;
F_9 ( V_11 , V_18 ) ;
F_18 ( V_9 ) ;
return ( 1 ) ;
}
V_19 = F_11 ( V_18 ) ;
V_20 = V_1 -> V_4 << 1 ;
if ( V_20 > V_19 ) V_19 = V_20 ;
V_20 >>= 1 ;
if ( V_19 != V_1 -> V_10 )
V_1 -> V_10 = F_20 ( & ( V_1 -> V_3 ) , & ( V_1 -> V_2 ) ,
V_19 , V_9 ) ;
if ( ! F_21 ( V_14 , V_18 , V_20 ) ) goto V_15;
if ( ! F_16 ( V_21 , V_14 , & ( V_1 -> V_3 ) , V_9 ) ) goto V_15;
if ( ! F_21 ( V_8 , V_21 , V_19 - V_20 ) ) goto V_15;
V_8 -> V_22 = 0 ;
if ( ! F_16 ( V_21 , & ( V_1 -> V_2 ) , V_8 , V_9 ) ) goto V_15;
if ( ! F_22 ( V_11 , V_18 , V_21 ) ) goto V_15;
V_11 -> V_22 = 0 ;
#if 1
V_20 = 0 ;
while ( F_19 ( V_11 , & ( V_1 -> V_2 ) ) >= 0 )
{
if ( V_20 ++ > 2 )
{
F_23 ( V_23 , V_24 ) ;
goto V_15;
}
if ( ! F_22 ( V_11 , V_11 , & ( V_1 -> V_2 ) ) ) goto V_15;
if ( ! F_24 ( V_8 , 1 ) ) goto V_15;
}
#endif
V_11 -> V_22 = F_25 ( V_11 ) ? 0 : V_18 -> V_22 ;
V_8 -> V_22 = V_18 -> V_22 ^ V_1 -> V_2 . V_22 ;
V_6 = 1 ;
V_15:
F_18 ( V_9 ) ;
return ( V_6 ) ;
}
int F_20 ( T_2 * V_11 , T_2 * V_18 , int V_25 , T_3 * V_9 )
{
int V_6 = - 1 ;
T_2 V_26 ;
F_2 ( & V_26 ) ;
F_10 ( & V_26 ) ;
if ( ! F_26 ( & V_26 , V_25 ) ) goto V_15;
if ( ! F_27 ( V_11 , NULL , & V_26 , V_18 , V_9 ) ) goto V_15;
V_6 = V_25 ;
V_15:
F_6 ( & V_26 ) ;
return ( V_6 ) ;
}
