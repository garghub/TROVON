void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_3 () ;
F_4 ( V_4 ) ;
if ( V_5 )
V_5 () ;
F_5 () ;
F_2 ( V_3 ) ;
}
void F_6 ( void (* F_7)( void ) )
{
V_5 = F_7 ;
if ( ! F_8 ( V_6 , V_7 ) )
F_9 ( V_6 ,
V_8 ) ;
}
void F_10 ( void )
{
V_5 = NULL ;
}
static T_1 T_2 F_11 ( void )
{
T_3 V_9 ;
T_3 V_10 [ 3 ] ;
if ( ! F_12 ( V_11 ) )
return 0 ;
F_13 ( V_12 ,
& V_9 , & V_10 [ 0 ] , & V_10 [ 1 ] , & V_10 [ 2 ] ) ;
if ( V_9 >= V_13 &&
V_9 <= V_14 &&
! memcmp ( L_1 , V_10 , 12 ) )
return V_12 ;
return 0 ;
}
static T_4 F_14 ( struct V_15 * V_16 )
{
T_4 V_17 ;
F_15 ( V_18 , V_17 ) ;
return V_17 ;
}
static void T_2 F_16 ( void )
{
V_19 . V_20 = F_17 ( V_21 ) ;
V_19 . V_22 = F_17 ( V_23 ) ;
F_18 ( V_24 L_2 ,
V_19 . V_20 , V_19 . V_22 ) ;
#ifdef F_19
if ( V_19 . V_20 & V_25 ) {
T_5 V_26 ;
F_15 ( V_27 , V_26 ) ;
V_26 = F_20 ( V_26 , V_28 ) ;
V_29 = V_26 ;
F_18 ( V_24 L_3 ,
V_29 ) ;
}
#endif
if ( V_19 . V_20 & V_30 )
F_21 ( & V_31 , V_32 / 100 ) ;
#ifdef F_22
V_33 = 1 ;
#endif
}
