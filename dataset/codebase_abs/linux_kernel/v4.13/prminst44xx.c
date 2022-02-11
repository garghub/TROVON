void F_1 ( void )
{
memcpy ( & V_1 [ V_2 ] , & V_3 ,
sizeof( V_3 ) ) ;
memcpy ( & V_1 [ V_4 ] , & V_5 ,
sizeof( V_5 ) ) ;
}
T_1 F_2 ( void )
{
return V_6 ;
}
void F_3 ( T_1 V_7 )
{
V_6 = V_7 ;
}
T_2 F_4 ( T_3 V_8 , T_4 V_9 , T_5 V_10 )
{
F_5 ( V_8 >= V_11 ||
V_8 == V_12 ||
! V_1 [ V_8 ] . V_13 ) ;
return F_6 ( V_1 [ V_8 ] . V_13 + V_9 + V_10 ) ;
}
void F_7 ( T_2 V_14 , T_3 V_8 , T_4 V_9 , T_5 V_10 )
{
F_5 ( V_8 >= V_11 ||
V_8 == V_12 ||
! V_1 [ V_8 ] . V_13 ) ;
F_8 ( V_14 , V_1 [ V_8 ] . V_13 + V_9 + V_10 ) ;
}
T_2 F_9 ( T_2 V_15 , T_2 V_16 , T_3 V_8 , T_4 V_9 ,
T_5 V_10 )
{
T_2 V_17 ;
V_17 = F_4 ( V_8 , V_9 , V_10 ) ;
V_17 &= ~ V_15 ;
V_17 |= V_16 ;
F_7 ( V_17 , V_8 , V_9 , V_10 ) ;
return V_17 ;
}
int F_10 ( T_3 V_18 , T_3 V_8 , T_4 V_9 ,
T_5 V_19 )
{
T_2 V_17 ;
V_17 = F_4 ( V_8 , V_9 , V_19 ) ;
V_17 &= 1 << V_18 ;
V_17 >>= V_18 ;
return V_17 ;
}
int F_11 ( T_3 V_18 , T_3 V_8 , T_4 V_9 ,
T_5 V_19 )
{
T_2 V_15 = 1 << V_18 ;
F_9 ( V_15 , V_15 , V_8 , V_9 , V_19 ) ;
return 0 ;
}
int F_12 ( T_3 V_18 , T_3 V_20 , T_3 V_8 , T_4 V_9 ,
T_5 V_19 , T_5 V_21 )
{
int V_22 ;
T_2 V_15 = 1 << V_18 ;
T_2 V_23 = 1 << V_20 ;
if ( F_10 ( V_18 , V_8 , V_9 ,
V_19 ) == 0 )
return - V_24 ;
F_9 ( 0xffffffff , V_23 , V_8 , V_9 ,
V_21 ) ;
F_9 ( V_15 , 0 , V_8 , V_9 , V_19 ) ;
F_13 ( F_10 ( V_20 , V_8 ,
V_9 , V_21 ) ,
V_25 , V_22 ) ;
return ( V_22 == V_25 ) ? - V_26 : 0 ;
}
void F_14 ( void )
{
T_2 V_17 ;
T_1 V_9 = F_2 () ;
if ( V_9 == V_27 )
return;
V_17 = F_4 ( V_2 , V_9 ,
V_28 ) ;
V_17 |= V_29 ;
F_7 ( V_17 , V_2 ,
V_9 , V_28 ) ;
V_17 = F_4 ( V_2 ,
V_9 , V_28 ) ;
}
