static void T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 ( 10 ) ;
F_4 ( V_1 ) ;
F_3 ( 10 ) ;
V_2 [ 0 ] . V_3 = V_4 ;
V_2 [ 0 ] . V_5 = V_4 + V_6 - 1 ;
V_2 [ 1 ] . V_3 = F_5 ( 2 ) ;
V_2 [ 1 ] . V_5 = F_5 ( 2 ) ;
}
static int F_6 ( void )
{
F_2 ( V_7 ) ;
F_4 ( V_7 ) ;
return 0 ;
}
static int F_7 ( void )
{
return V_8 ;
}
static void T_1 F_8 ( void )
{
T_2 V_9 ;
F_6 () ;
V_10 . V_11 = L_1 ;
V_2 [ 0 ] . V_3 = V_12 ;
V_2 [ 0 ] . V_5 = V_12 + V_13 - 1 ;
V_2 [ 1 ] . V_3 = F_5 ( 2 ) ;
V_2 [ 1 ] . V_5 = F_5 ( 2 ) ;
V_9 = F_9 ( V_14 ) ;
if ( V_9 & V_15 )
V_16 . V_17 = false ;
else
V_16 . V_17 = true ;
if ( V_8 == 1 )
V_16 . V_18 = F_7 ;
V_16 . V_19 = F_6 ;
}
static void F_10 ( void )
{
T_2 V_9 ;
V_10 . V_11 = L_2 ;
V_2 [ 0 ] . V_3 = V_20 ;
V_2 [ 0 ] . V_5 = V_20 + V_21 - 1 ;
V_2 [ 1 ] . V_3 = F_11 ( 1 ) ;
V_2 [ 1 ] . V_5 = F_11 ( 1 ) ;
V_9 = F_9 ( V_22 ) ;
if ( V_9 & V_23 )
V_16 . V_17 = false ;
else
V_16 . V_17 = true ;
}
static void F_12 ( void )
{
T_2 V_9 ;
V_10 . V_11 = L_3 ;
V_2 [ 0 ] . V_3 = V_24 ;
V_2 [ 0 ] . V_5 = V_24 + V_25 - 1 ;
V_2 [ 1 ] . V_3 = F_11 ( 1 ) ;
V_2 [ 1 ] . V_5 = F_11 ( 1 ) ;
V_9 = F_9 ( V_26 ) ;
if ( V_9 & V_27 )
V_16 . V_17 = false ;
else
V_16 . V_17 = true ;
}
void T_1 F_13 ( T_3 * V_28 )
{
if ( F_14 () )
F_1 () ;
else if ( F_15 () )
F_8 () ;
else if ( F_16 () )
F_10 () ;
else if ( F_17 () )
F_12 () ;
else
F_18 () ;
if ( V_28 )
memcpy ( V_16 . V_29 , V_28 ,
sizeof( V_16 . V_29 ) ) ;
F_19 ( & V_10 ) ;
}
