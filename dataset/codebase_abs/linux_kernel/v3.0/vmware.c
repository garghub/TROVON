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
F_6 ( V_10 L_1 ,
( unsigned long ) V_7 / 1000 ,
( unsigned long ) V_7 % 1000 ) ;
if ( ! V_11 ) {
V_8 = ( ( V_12 ) V_7 * 1000 ) ;
F_4 ( V_8 , V_13 ) ;
V_11 = V_8 ;
}
return V_7 ;
}
static void T_3 F_7 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_9 , V_1 , V_2 , V_3 , V_4 ) ;
if ( V_2 != V_14 )
V_15 . V_16 = F_3 ;
else
F_6 ( V_17
L_2 ) ;
}
static bool T_3 F_8 ( void )
{
if ( V_18 ) {
unsigned int V_1 ;
unsigned int V_19 [ 3 ] ;
F_9 ( V_20 , & V_1 , & V_19 [ 0 ] ,
& V_19 [ 1 ] , & V_19 [ 2 ] ) ;
if ( ! memcmp ( V_19 , L_3 , 12 ) )
return true ;
} else if ( V_21 && F_10 ( L_4 ) &&
F_1 () )
return true ;
return false ;
}
static void T_4 F_11 ( struct V_22 * V_23 )
{
F_12 ( V_23 , V_24 ) ;
F_12 ( V_23 , V_25 ) ;
}
