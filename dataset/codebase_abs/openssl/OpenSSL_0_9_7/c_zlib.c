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
#ifdef F_3
fprintf ( V_10 , L_1 ,
V_5 , ( int ) V_6 , ( V_8 ) ? L_2 : L_3 ) ;
#endif
return ( ( int ) V_6 ) ;
}
static int F_4 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int V_3 , unsigned char * V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
int V_7 ;
if ( V_4 [ 0 ] )
{
V_6 = V_3 ;
V_7 = F_5 ( V_2 , & V_6 , & ( V_4 [ 1 ] ) , ( unsigned long ) V_5 - 1 ) ;
if ( V_7 != V_9 )
return ( - 1 ) ;
}
else
{
memcpy ( V_2 , & ( V_4 [ 1 ] ) , V_5 - 1 ) ;
V_6 = V_5 - 1 ;
}
#ifdef F_3
fprintf ( V_10 , L_4 ,
V_5 , ( int ) V_6 , V_4 [ 0 ] ? L_3 : L_2 ) ;
#endif
return ( ( int ) V_6 ) ;
}
static int F_5 ( T_2 * V_11 , T_3 * V_12 , const T_2 * V_13 ,
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
V_16 = F_6 ( & V_15 ) ;
if ( V_16 != V_9 ) return V_16 ;
V_16 = F_7 ( & V_15 , V_27 ) ;
if ( V_16 != V_28 ) {
F_8 ( & V_15 ) ;
return V_16 ;
}
* V_12 = V_15 . V_29 ;
V_16 = F_8 ( & V_15 ) ;
return V_16 ;
}
T_6 * F_9 ( void )
{
T_6 * V_30 = & V_31 ;
#ifdef F_10
if ( ! V_32 )
{
#if F_11 ( V_33 ) || F_11 ( V_34 )
V_35 = F_12 ( NULL , L_5 , NULL , 0 ) ;
#else
V_35 = F_12 ( NULL , L_6 , NULL , 0 ) ;
#endif
if ( V_35 != NULL )
{
V_36
= ( V_37 ) F_13 ( V_35 ,
L_7 ) ;
V_38
= ( V_39 ) F_13 ( V_35 ,
L_8 ) ;
V_40
= ( V_41 ) F_13 ( V_35 ,
L_9 ) ;
V_42
= ( V_43 ) F_13 ( V_35 ,
L_10 ) ;
V_32 ++ ;
}
}
#endif
#if F_11 ( V_44 ) || F_11 ( F_10 )
V_30 = & V_45 ;
#endif
return ( V_30 ) ;
}
static int
F_14 ( T_2 * V_11 , T_3 * V_12 , const T_2 * V_13 , T_4 V_14 )
{
if ( V_36 )
return ( V_36 ( V_11 , V_12 , V_13 , V_14 ) ) ;
else
return ( V_46 ) ;
}
static int
F_15 ( T_7 V_47 )
{
if ( V_38 )
return ( V_38 ( V_47 ) ) ;
else
return ( V_46 ) ;
}
static int
F_16 ( T_7 V_47 , int V_48 )
{
if ( V_40 )
return ( V_40 ( V_47 , V_48 ) ) ;
else
return ( V_46 ) ;
}
static int
F_17 ( T_7 V_47 , const char * V_49 , int V_50 )
{
if ( V_42 )
return ( V_42 ( V_47 , V_49 , V_50 ) ) ;
else
return ( V_46 ) ;
}
