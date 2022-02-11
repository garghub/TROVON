static T_1 T_2 F_1 ( void )
{
T_3 V_1 ;
T_3 V_2 [ 3 ] ;
if ( ! F_2 ( V_3 ) )
return 0 ;
F_3 ( V_4 ,
& V_1 , & V_2 [ 0 ] , & V_2 [ 1 ] , & V_2 [ 2 ] ) ;
if ( V_1 >= V_5 &&
V_1 <= V_6 &&
! memcmp ( L_1 , V_2 , 12 ) )
return V_4 ;
return 0 ;
}
static T_4 F_4 ( struct V_7 * V_8 )
{
T_4 V_9 ;
F_5 ( V_10 , V_9 ) ;
return V_9 ;
}
static void T_2 F_6 ( void )
{
V_11 . V_12 = F_7 ( V_13 ) ;
V_11 . V_14 = F_7 ( V_15 ) ;
F_8 ( V_16 L_2 ,
V_11 . V_12 , V_11 . V_14 ) ;
#ifdef F_9
if ( V_11 . V_12 & V_17 ) {
T_5 V_18 ;
F_5 ( V_19 , V_18 ) ;
V_18 = F_10 ( V_18 , V_20 ) ;
V_21 = V_18 ;
F_8 ( V_16 L_3 ,
V_21 ) ;
if ( F_11 ( V_22 ) ) {
F_8 ( V_16 L_4 ) ;
V_23 = & V_24 ;
}
}
#endif
if ( V_11 . V_12 & V_25 )
F_12 ( & V_26 , V_27 / 100 ) ;
}
void F_13 ( int V_28 , T_6 V_29 )
{
F_14 ( V_30 , V_31 ) ;
V_32 = V_28 ;
V_33 = V_29 ;
}
void F_15 ( struct V_34 * V_35 )
{
struct V_34 * V_36 = F_16 ( V_35 ) ;
struct V_37 * V_38 ;
F_17 () ;
F_18 () ;
V_38 = F_19 ( V_32 ) ;
if ( V_38 )
F_20 ( V_32 , V_38 ) ;
F_21 () ;
F_16 ( V_36 ) ;
}
void F_13 ( int V_28 , T_6 V_29 )
{
}
