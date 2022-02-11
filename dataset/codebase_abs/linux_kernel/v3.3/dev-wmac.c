static void T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 ( 10 ) ;
F_4 ( V_1 ) ;
F_3 ( 10 ) ;
V_2 [ 0 ] . V_3 = V_4 ;
V_2 [ 0 ] . V_5 = V_4 + V_6 - 1 ;
}
static int F_5 ( void )
{
F_4 ( V_7 ) ;
F_2 ( V_7 ) ;
return 0 ;
}
static int F_6 ( void )
{
return V_8 ;
}
static void T_1 F_7 ( void )
{
T_2 V_9 ;
F_5 () ;
V_10 . V_11 = L_1 ;
V_2 [ 0 ] . V_3 = V_12 ;
V_2 [ 0 ] . V_5 = V_12 + V_13 - 1 ;
V_9 = F_8 ( V_14 ) ;
if ( V_9 & V_15 )
V_16 . V_17 = false ;
else
V_16 . V_17 = true ;
if ( V_8 == 1 )
V_16 . V_18 = F_6 ;
V_16 . V_19 = F_5 ;
}
void T_1 F_9 ( T_3 * V_20 )
{
if ( F_10 () )
F_1 () ;
else if ( F_11 () )
F_7 () ;
else
F_12 () ;
if ( V_20 )
memcpy ( V_16 . V_21 , V_20 ,
sizeof( V_16 . V_21 ) ) ;
F_13 ( & V_10 ) ;
}
