static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int V_3 , unsigned char * V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
int V_7 ;
int V_8 = 1 ;
if ( V_5 > 128 )
{
V_2 [ 0 ] = 1 ;
V_6 = V_3 - 1 ;
V_7 = F_2 ( & ( V_2 [ 1 ] ) , & V_6 , V_4 , ( unsigned long ) V_5 ) ;
if ( V_7 != V_9 )
return ( - 1 ) ;
if ( V_5 > V_6 )
{
V_8 = 0 ;
V_6 ++ ;
}
}
if ( V_8 )
{
V_2 [ 0 ] = 0 ;
memcpy ( & ( V_2 [ 1 ] ) , V_4 , V_5 ) ;
V_6 = V_5 + 1 ;
}
fprintf ( V_10 , L_1 , V_5 , ( int ) V_6 , ( V_8 ) ? L_2 : L_3 ) ;
return ( ( int ) V_6 ) ;
}
static int F_3 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int V_3 , unsigned char * V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
int V_7 ;
if ( V_4 [ 0 ] )
{
V_6 = V_3 ;
V_7 = F_4 ( V_2 , & V_6 , & ( V_4 [ 1 ] ) , ( unsigned long ) V_5 - 1 ) ;
if ( V_7 != V_9 )
return ( - 1 ) ;
}
else
{
memcpy ( V_2 , & ( V_4 [ 1 ] ) , V_5 - 1 ) ;
V_6 = V_5 - 1 ;
}
fprintf ( V_10 , L_4 , V_5 , ( int ) V_6 , V_4 [ 0 ] ? L_3 : L_2 ) ;
return ( ( int ) V_6 ) ;
}
static int F_4 ( T_2 * V_11 , T_3 * V_12 , const T_2 * V_13 ,
T_4 V_14 )
{
T_5 V_15 ;
int V_16 ;
V_15 . V_17 = ( T_2 * ) V_13 ;
V_15 . V_18 = ( V_19 ) V_14 ;
if ( ( T_4 ) V_15 . V_18 != V_14 ) return V_20 ;
V_15 . V_21 = V_11 ;
V_15 . V_22 = ( V_19 ) * V_12 ;
if ( ( T_4 ) V_15 . V_22 != * V_12 ) return V_20 ;
V_15 . V_23 = ( V_24 ) 0 ;
V_15 . V_25 = ( V_26 ) 0 ;
V_16 = F_5 ( & V_15 ) ;
if ( V_16 != V_9 ) return V_16 ;
V_16 = F_6 ( & V_15 , V_27 ) ;
if ( V_16 != V_28 ) {
F_7 ( & V_15 ) ;
return V_16 ;
}
* V_12 = V_15 . V_29 ;
V_16 = F_7 ( & V_15 ) ;
return V_16 ;
}
T_6 * F_8 ( void )
{
return ( & V_30 ) ;
}
