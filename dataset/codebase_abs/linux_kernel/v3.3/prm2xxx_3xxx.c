T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( V_3 + V_1 + V_2 ) ;
}
void F_3 ( T_1 V_4 , T_2 V_1 , T_3 V_2 )
{
F_4 ( V_4 , V_3 + V_1 + V_2 ) ;
}
T_1 F_5 ( T_1 V_5 , T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_3 ( V_7 , V_1 , V_2 ) ;
return V_7 ;
}
T_1 F_6 ( T_2 V_8 , T_2 V_2 , T_1 V_5 )
{
T_1 V_7 ;
V_7 = F_1 ( V_8 , V_2 ) ;
V_7 &= V_5 ;
V_7 >>= F_7 ( V_5 ) ;
return V_7 ;
}
T_1 F_8 ( T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
return F_5 ( V_6 , V_6 , V_1 , V_2 ) ;
}
T_1 F_9 ( T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
return F_5 ( V_6 , 0x0 , V_1 , V_2 ) ;
}
int F_10 ( T_2 V_9 , T_4 V_10 )
{
if ( ! ( F_11 () || F_12 () ) )
return - V_11 ;
return F_6 ( V_9 , V_12 ,
( 1 << V_10 ) ) ;
}
int F_13 ( T_2 V_9 , T_4 V_10 )
{
T_1 V_5 ;
if ( ! ( F_11 () || F_12 () ) )
return - V_11 ;
V_5 = 1 << V_10 ;
F_5 ( V_5 , V_5 , V_9 , V_12 ) ;
return 0 ;
}
int F_14 ( T_2 V_9 , T_4 V_13 , T_4 V_14 )
{
T_1 V_15 , V_16 ;
int V_17 ;
if ( ! ( F_11 () || F_12 () ) )
return - V_11 ;
V_15 = 1 << V_13 ;
V_16 = 1 << V_14 ;
if ( F_6 ( V_9 , V_12 , V_15 ) == 0 )
return - V_18 ;
F_5 ( 0xffffffff , V_16 , V_9 , V_19 ) ;
F_5 ( V_15 , 0 , V_9 , V_12 ) ;
F_15 ( F_6 ( V_9 , V_19 ,
V_16 ) ,
V_20 , V_17 ) ;
return ( V_17 == V_20 ) ? - V_21 : 0 ;
}
T_1 F_16 ( T_4 V_22 )
{
struct V_23 * V_24 = & V_23 [ V_22 ] ;
T_1 V_25 ;
V_25 = F_1 ( V_26 ,
V_27 ) ;
return V_25 & V_24 -> V_28 ;
}
void F_17 ( T_4 V_22 )
{
struct V_23 * V_24 = & V_23 [ V_22 ] ;
F_3 ( V_24 -> V_28 ,
V_26 , V_27 ) ;
}
T_1 F_18 ( T_4 V_29 )
{
return F_1 ( V_30 , V_29 ) ;
}
void F_19 ( T_1 V_4 , T_4 V_29 )
{
F_3 ( V_4 , V_30 , V_29 ) ;
}
T_1 F_20 ( T_1 V_5 , T_1 V_6 , T_4 V_29 )
{
return F_5 ( V_5 , V_6 , V_30 , V_29 ) ;
}
void F_21 ( unsigned long * V_31 )
{
T_1 V_5 , V_16 ;
V_5 = F_1 ( V_26 , V_32 ) ;
V_16 = F_1 ( V_26 , V_27 ) ;
V_31 [ 0 ] = V_5 & V_16 ;
}
void F_22 ( void )
{
F_1 ( V_26 , V_33 ) ;
}
void F_23 ( T_1 * V_34 )
{
V_34 [ 0 ] = F_1 ( V_26 ,
V_32 ) ;
F_3 ( 0 , V_26 , V_32 ) ;
F_1 ( V_26 , V_33 ) ;
}
void F_24 ( T_1 * V_34 )
{
F_3 ( V_34 [ 0 ] , V_26 ,
V_32 ) ;
}
static int T_5 F_25 ( void )
{
if ( F_12 () )
return F_26 ( & V_35 ) ;
return 0 ;
}
