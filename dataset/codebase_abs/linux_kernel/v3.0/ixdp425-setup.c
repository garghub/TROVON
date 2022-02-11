static void
F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = ( int ) V_6 -> V_7 ;
if ( V_4 & V_9 ) {
if ( V_4 & V_10 ) {
F_2 ( V_11 , V_12 ) ;
F_3 ( 5 ) ;
} else
F_2 ( V_11 , V_13 ) ;
V_8 = ( V_4 & V_14 ) ? V_15 : 0 ;
V_8 |= ( V_4 & V_16 ) ? V_17 : 0 ;
V_6 -> V_7 = ( void * ) V_8 ;
}
if ( V_3 != V_18 )
F_4 ( V_3 , V_6 -> V_19 + V_8 ) ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
V_20 . V_21 = F_7 ( 0 ) ;
V_20 . V_22 =
F_7 ( 0 ) + V_23 - 1 ;
#if F_8 ( V_24 ) || \
F_8 ( V_25 )
V_26 . V_21 = F_7 ( 3 ) ,
V_26 . V_22 = F_7 ( 3 ) + 0x10 - 1 ;
F_9 ( V_11 , V_27 ) ;
* V_28 = V_29 |
F_10 ( 1 ) |
F_11 ( 0 ) |
F_12 ( 0 ) |
V_30 |
V_31 ;
#endif
if ( F_13 () ) {
V_32 . V_33 = 1 ;
V_34 [ 1 ] . V_35 = 0 ;
}
F_14 ( V_36 , F_15 ( V_36 ) ) ;
}
