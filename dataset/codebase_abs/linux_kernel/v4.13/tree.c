T_1 * T_2
F_1 ( T_1 * V_1 )
{
if ( V_1 == V_2 )
return V_2 ;
return ( T_1 * ) F_2 ( V_3 , V_1 ) ;
}
T_1 * T_2
F_3 ( T_1 * V_1 )
{
return ( T_1 * ) F_2 ( V_4 , V_1 ) ;
}
T_1 * T_2
F_4 ( T_1 * V_1 )
{
if ( V_1 == V_2 )
return V_2 ;
return ( T_1 * ) F_2 ( V_5 , V_1 ) ;
}
LONG T_2
F_5 ( VOID * V_6 , T_1 * V_1 )
{
return F_6 ( V_7 , V_6 , V_1 ) ;
}
T_1 * T_2
F_7 ( T_1 * V_1 , T_1 * V_8 , VOID * V_9 )
{
return ( T_1 * )
F_8 ( V_10 , V_1 , V_8 , V_9 ) ;
}
LONG T_2
F_9 ( T_1 * V_11 )
{
return F_2 ( V_12 , V_11 ) ;
}
T_1 * T_2
F_10 ( CHAR * V_13 )
{
return ( T_1 * ) F_2 ( V_14 , V_13 ) ;
}
static void T_2
F_11 ( T_1 * V_15 )
{
F_12 ( L_1 ,
V_15 , V_16 [ V_15 -> V_17 ] , V_18 [ V_15 -> type ] ,
V_19 [ V_15 -> V_19 ] , V_15 -> V_20 , V_15 -> V_21 ) ;
F_12 ( L_2 ,
V_15 -> V_22 , V_15 -> V_23 , ( int ) V_15 -> V_24 , ( int ) V_15 -> V_25 , V_15 -> V_26 ) ;
}
static void T_2
F_13 ( T_1 * V_15 , int V_27 )
{
F_11 ( V_15 ) ;
if( F_3 ( V_15 ) )
F_13 ( F_3 ( V_15 ) , 1 ) ;
if( F_1 ( V_15 ) && V_27 )
F_13 ( F_1 ( V_15 ) , 1 ) ;
}
void T_2
F_14 ( void )
{
T_1 * V_15 ;
V_15 = F_3 ( V_2 ) ;
F_11 ( V_15 ) ;
V_15 = F_3 ( V_15 ) ;
while( V_15 ) {
F_11 ( V_15 ) ;
V_15 = F_1 ( V_15 ) ;
}
}
