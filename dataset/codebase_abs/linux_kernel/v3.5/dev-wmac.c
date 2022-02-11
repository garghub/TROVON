static void T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 ( 10 ) ;
F_4 ( V_1 ) ;
F_3 ( 10 ) ;
V_2 [ 0 ] . V_3 = V_4 ;
V_2 [ 0 ] . V_5 = V_4 + V_6 - 1 ;
V_2 [ 1 ] . V_3 = V_7 ;
V_2 [ 1 ] . V_5 = V_7 ;
}
static int F_5 ( void )
{
F_2 ( V_8 ) ;
F_4 ( V_8 ) ;
return 0 ;
}
static int F_6 ( void )
{
return V_9 ;
}
static void T_1 F_7 ( void )
{
T_2 V_10 ;
F_5 () ;
V_11 . V_12 = L_1 ;
V_2 [ 0 ] . V_3 = V_13 ;
V_2 [ 0 ] . V_5 = V_13 + V_14 - 1 ;
V_2 [ 1 ] . V_3 = V_7 ;
V_2 [ 1 ] . V_5 = V_7 ;
V_10 = F_8 ( V_15 ) ;
if ( V_10 & V_16 )
V_17 . V_18 = false ;
else
V_17 . V_18 = true ;
if ( V_9 == 1 )
V_17 . V_19 = F_6 ;
V_17 . V_20 = F_5 ;
}
static void F_9 ( void )
{
T_2 V_10 ;
V_11 . V_12 = L_2 ;
V_2 [ 0 ] . V_3 = V_21 ;
V_2 [ 0 ] . V_5 = V_21 + V_22 - 1 ;
V_2 [ 1 ] . V_3 = F_10 ( 1 ) ;
V_2 [ 1 ] . V_3 = F_10 ( 1 ) ;
V_10 = F_8 ( V_23 ) ;
if ( V_10 & V_24 )
V_17 . V_18 = false ;
else
V_17 . V_18 = true ;
}
void T_1 F_11 ( T_3 * V_25 )
{
if ( F_12 () )
F_1 () ;
else if ( F_13 () )
F_7 () ;
else if ( F_14 () )
F_9 () ;
else
F_15 () ;
if ( V_25 )
memcpy ( V_17 . V_26 , V_25 ,
sizeof( V_17 . V_26 ) ) ;
F_16 ( & V_11 ) ;
}
