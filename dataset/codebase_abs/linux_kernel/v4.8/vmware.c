static inline int F_1 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_5 , V_1 , V_2 , V_3 , V_4 ) ;
return V_1 != ( T_1 ) - 1 && V_2 == V_6 ;
}
static unsigned long F_3 ( void )
{
T_2 V_7 , V_8 ;
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_9 , V_1 , V_2 , V_3 , V_4 ) ;
V_7 = V_1 | ( ( ( T_2 ) V_2 ) << 32 ) ;
F_4 ( V_7 , 1000 ) ;
F_5 ( V_7 >> 32 ) ;
F_6 ( L_1 ,
( unsigned long ) V_7 / 1000 ,
( unsigned long ) V_7 % 1000 ) ;
if ( ! V_10 ) {
V_8 = ( ( V_11 ) V_7 * 1000 ) ;
F_4 ( V_8 , V_12 ) ;
V_10 = V_8 ;
}
return V_7 ;
}
static void T_3 F_7 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_9 , V_1 , V_2 , V_3 , V_4 ) ;
if ( V_2 != V_13 )
V_14 . V_15 = F_3 ;
else
F_8 ( L_2 ) ;
}
static T_1 T_3 F_9 ( void )
{
if ( F_10 ( V_16 ) ) {
unsigned int V_1 ;
unsigned int V_17 [ 3 ] ;
F_11 ( V_18 , & V_1 , & V_17 [ 0 ] ,
& V_17 [ 1 ] , & V_17 [ 2 ] ) ;
if ( ! memcmp ( V_17 , L_3 , 12 ) )
return V_18 ;
} else if ( V_19 && F_12 ( L_4 ) &&
F_1 () )
return 1 ;
return 0 ;
}
static void F_13 ( struct V_20 * V_21 )
{
F_14 ( V_21 , V_22 ) ;
F_14 ( V_21 , V_23 ) ;
}
static bool T_3 F_15 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_24 , V_1 , V_2 , V_3 , V_4 ) ;
return ( V_1 & ( 1 << V_25 ) ) == 0 &&
( V_1 & ( 1 << V_26 ) ) != 0 ;
}
