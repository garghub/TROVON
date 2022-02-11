static bool T_1 F_1 ( void )
{
T_2 V_1 ;
T_2 V_2 [ 3 ] ;
if ( ! F_2 ( V_3 ) )
return false ;
F_3 ( V_4 ,
& V_1 , & V_2 [ 0 ] , & V_2 [ 1 ] , & V_2 [ 2 ] ) ;
return V_1 >= V_5 &&
V_1 <= V_6 &&
! memcmp ( L_1 , V_2 , 12 ) ;
}
static T_3 F_4 ( struct V_7 * V_8 )
{
T_3 V_9 ;
F_5 ( V_10 , V_9 ) ;
return V_9 ;
}
static void T_1 F_6 ( void )
{
V_11 . V_12 = F_7 ( V_13 ) ;
V_11 . V_14 = F_7 ( V_15 ) ;
F_8 ( V_16 L_2 ,
V_11 . V_12 , V_11 . V_14 ) ;
if ( V_11 . V_12 & V_17 )
F_9 ( & V_18 , V_19 / 100 ) ;
}
void F_10 ( int V_20 , T_4 V_21 )
{
F_11 ( V_22 , V_23 ) ;
V_24 = V_20 ;
V_25 = V_21 ;
}
void F_12 ( struct V_26 * V_27 )
{
struct V_26 * V_28 = F_13 ( V_27 ) ;
struct V_29 * V_30 ;
F_14 () ;
F_15 () ;
V_30 = F_16 ( V_24 ) ;
if ( V_30 )
F_17 ( V_24 , V_30 ) ;
F_18 () ;
F_13 ( V_28 ) ;
}
void F_10 ( int V_20 , T_4 V_21 )
{
}
