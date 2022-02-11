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
int F_6 ( T_4 V_8 , T_2 V_1 , T_3 V_9 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_9 ) ;
V_7 &= 1 << V_8 ;
V_7 >>= V_8 ;
return V_7 ;
}
int F_7 ( T_4 V_8 , T_2 V_1 , T_3 V_9 )
{
T_1 V_5 = 1 << V_8 ;
F_5 ( V_5 , V_5 , V_1 , V_9 ) ;
return 0 ;
}
int F_8 ( T_4 V_8 , T_4 V_10 , T_2 V_1 ,
T_3 V_9 , T_3 V_11 )
{
int V_12 ;
T_1 V_5 = 1 << V_10 ;
if ( F_6 ( V_8 , V_1 , V_9 ) == 0 )
return - V_13 ;
F_5 ( 0xffffffff , V_5 , V_1 , V_11 ) ;
V_5 = 1 << V_8 ;
F_5 ( V_5 , 0 , V_1 , V_9 ) ;
F_9 ( F_6 ( V_10 , V_1 ,
V_11 ) ,
V_14 , V_12 ) ;
return ( V_12 == V_14 ) ? - V_15 : 0 ;
}
static int F_10 ( struct V_16 * V_17 , T_4 V_18 )
{
F_5 ( V_19 ,
( V_18 << V_20 ) ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 )
{
T_1 V_7 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_22 ) ;
V_7 &= V_19 ;
V_7 >>= V_20 ;
return V_7 ;
}
static int F_12 ( struct V_16 * V_17 )
{
T_1 V_7 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_23 ) ;
V_7 &= V_24 ;
V_7 >>= V_25 ;
return V_7 ;
}
static int F_13 ( struct V_16 * V_17 )
{
T_1 V_7 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_23 ) ;
V_7 &= V_26 ;
V_7 >>= V_27 ;
return V_7 ;
}
static int F_14 ( struct V_16 * V_17 )
{
F_5 ( V_28 ,
( 1 << V_29 ) ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 )
{
F_5 ( V_26 ,
V_26 ,
V_17 -> V_21 , V_17 -> V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , T_4 V_18 )
{
T_1 V_30 ;
V_30 = V_17 -> V_31 ;
if ( ! V_30 )
return - V_32 ;
F_5 ( V_30 , ( V_18 << F_17 ( V_30 ) ) ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 )
{
T_1 V_7 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_23 ) ;
V_7 &= V_33 ;
V_7 >>= V_34 ;
return V_7 ;
}
static int F_19 ( struct V_16 * V_17 )
{
T_1 V_7 , V_30 ;
V_30 = V_17 -> V_31 ;
if ( ! V_30 )
return - V_32 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_22 ) ;
V_7 &= V_30 ;
V_7 >>= F_17 ( V_30 ) ;
return V_7 ;
}
static int F_20 ( struct V_16 * V_17 , T_4 V_35 ,
T_4 V_18 )
{
T_1 V_30 ;
V_30 = V_17 -> V_36 [ V_35 ] ;
if ( ! V_30 )
return - V_32 ;
F_5 ( V_30 , ( V_18 << F_17 ( V_30 ) ) ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , T_4 V_35 ,
T_4 V_18 )
{
T_1 V_30 ;
V_30 = V_17 -> V_37 [ V_35 ] ;
if ( ! V_30 )
return - V_32 ;
F_5 ( V_30 , ( V_18 << F_17 ( V_30 ) ) ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , T_4 V_35 )
{
T_1 V_30 , V_7 ;
V_30 = V_17 -> V_38 [ V_35 ] ;
if ( ! V_30 )
return - V_32 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_23 ) ;
V_7 &= V_30 ;
V_7 >>= F_17 ( V_30 ) ;
return V_7 ;
}
static int F_23 ( struct V_16 * V_17 , T_4 V_35 )
{
T_1 V_30 , V_7 ;
V_30 = V_17 -> V_39 [ V_35 ] ;
if ( ! V_30 )
return - V_32 ;
V_7 = F_1 ( V_17 -> V_21 , V_17 -> V_22 ) ;
V_7 &= V_30 ;
V_7 >>= F_17 ( V_30 ) ;
return V_7 ;
}
static int F_24 ( struct V_16 * V_17 )
{
T_1 V_12 = 0 ;
while ( ( F_1 ( V_17 -> V_21 , V_17 -> V_23 )
& V_40 ) &&
( V_12 ++ < V_41 ) )
F_25 ( 1 ) ;
if ( V_12 > V_41 ) {
F_26 ( L_1 ,
V_17 -> V_42 ) ;
return - V_43 ;
}
F_27 ( L_2 , V_12 ) ;
return 0 ;
}
static int F_28 ( void )
{
return 0 ;
}
