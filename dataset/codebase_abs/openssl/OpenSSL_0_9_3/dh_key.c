int F_1 ( T_1 * V_1 )
{
int V_2 = 0 ;
unsigned int V_3 ;
T_2 V_4 ;
T_3 * V_5 ;
T_4 * V_6 = NULL , * V_7 = NULL ;
F_2 ( & V_4 ) ;
if ( V_1 -> V_7 == NULL )
{
V_3 = V_1 -> V_8 ;
if ( V_3 == 0 )
{
V_3 = F_3 ( V_1 -> V_9 ) - 1 ;
}
V_7 = F_4 () ;
if ( V_7 == NULL ) goto V_10;
if ( ! F_5 ( V_7 , V_3 , 0 , 0 ) ) goto V_10;
}
else
V_7 = V_1 -> V_7 ;
if ( V_1 -> V_6 == NULL )
{
V_6 = F_4 () ;
if ( V_6 == NULL ) goto V_10;
}
else
V_6 = V_1 -> V_6 ;
if ( ( V_1 -> V_11 == NULL ) && ( V_1 -> V_12 & V_13 ) )
{
if ( ( V_1 -> V_11 = ( char * ) F_6 () ) != NULL )
if ( ! F_7 ( ( T_3 * ) V_1 -> V_11 ,
V_1 -> V_9 , & V_4 ) ) goto V_10;
}
V_5 = ( T_3 * ) V_1 -> V_11 ;
if ( ! F_8 ( V_6 , V_1 -> V_14 , V_7 , V_1 -> V_9 , & V_4 , V_5 ) ) goto V_10;
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 ;
V_2 = 1 ;
V_10:
if ( V_2 != 1 )
F_9 ( V_15 , V_16 ) ;
if ( ( V_6 != NULL ) && ( V_1 -> V_6 == NULL ) ) F_10 ( V_6 ) ;
if ( ( V_7 != NULL ) && ( V_1 -> V_7 == NULL ) ) F_10 ( V_7 ) ;
F_11 ( & V_4 ) ;
return ( V_2 ) ;
}
int F_12 ( unsigned char * V_17 , T_4 * V_6 , T_1 * V_1 )
{
T_2 V_4 ;
T_3 * V_5 ;
T_4 * V_18 ;
int V_19 = - 1 ;
F_2 ( & V_4 ) ;
V_18 = & ( V_4 . V_20 [ V_4 . V_21 ++ ] ) ;
if ( V_1 -> V_7 == NULL )
{
F_9 ( V_22 , V_23 ) ;
goto V_10;
}
if ( ( V_1 -> V_11 == NULL ) && ( V_1 -> V_12 & V_13 ) )
{
if ( ( V_1 -> V_11 = ( char * ) F_6 () ) != NULL )
if ( ! F_7 ( ( T_3 * ) V_1 -> V_11 ,
V_1 -> V_9 , & V_4 ) ) goto V_10;
}
V_5 = ( T_3 * ) V_1 -> V_11 ;
if ( ! F_8 ( V_18 , V_6 , V_1 -> V_7 , V_1 -> V_9 , & V_4 , V_5 ) )
{
F_9 ( V_22 , V_16 ) ;
goto V_10;
}
V_19 = F_13 ( V_18 , V_17 ) ;
V_10:
F_11 ( & V_4 ) ;
return ( V_19 ) ;
}
