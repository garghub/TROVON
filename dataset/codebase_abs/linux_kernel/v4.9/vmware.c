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
if ( V_2 != V_13 ) {
V_14 . V_15 = F_3 ;
#ifdef F_8
V_16 = V_3 / V_12 ;
F_6 ( L_2 ,
V_3 ) ;
#endif
} else {
F_9 ( L_3 ) ;
}
#ifdef F_10
V_17 = 1 ;
#endif
}
static T_1 T_3 F_11 ( void )
{
if ( F_12 ( V_18 ) ) {
unsigned int V_1 ;
unsigned int V_19 [ 3 ] ;
F_13 ( V_20 , & V_1 , & V_19 [ 0 ] ,
& V_19 [ 1 ] , & V_19 [ 2 ] ) ;
if ( ! memcmp ( V_19 , L_4 , 12 ) )
return V_20 ;
} else if ( V_21 && F_14 ( L_5 ) &&
F_1 () )
return 1 ;
return 0 ;
}
static void F_15 ( struct V_22 * V_23 )
{
F_16 ( V_23 , V_24 ) ;
F_16 ( V_23 , V_25 ) ;
}
static bool T_3 F_17 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_26 , V_1 , V_2 , V_3 , V_4 ) ;
return ( V_1 & ( 1 << V_27 ) ) == 0 &&
( V_1 & ( 1 << V_28 ) ) != 0 ;
}
