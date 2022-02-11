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
int F_8 ( T_4 V_8 , T_2 V_1 ,
T_3 V_9 , T_3 V_10 )
{
int V_11 ;
T_1 V_5 = 1 << V_8 ;
if ( F_6 ( V_8 , V_1 , V_9 ) == 0 )
return - V_12 ;
F_5 ( 0xffffffff , V_5 , V_1 , V_10 ) ;
F_5 ( V_5 , 0 , V_1 , V_9 ) ;
F_9 ( F_6 ( V_8 , V_1 ,
V_10 ) ,
V_13 , V_11 ) ;
return ( V_11 == V_13 ) ? - V_14 : 0 ;
}
static int F_10 ( struct V_15 * V_16 , T_4 V_17 )
{
F_5 ( V_18 ,
( V_17 << V_19 ) ,
V_16 -> V_20 , V_16 -> V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 )
{
T_1 V_7 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_21 ) ;
V_7 &= V_18 ;
V_7 >>= V_19 ;
return V_7 ;
}
static int F_12 ( struct V_15 * V_16 )
{
T_1 V_7 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_22 ) ;
V_7 &= V_23 ;
V_7 >>= V_24 ;
return V_7 ;
}
static int F_13 ( struct V_15 * V_16 )
{
T_1 V_7 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_22 ) ;
V_7 &= V_25 ;
V_7 >>= V_26 ;
return V_7 ;
}
static int F_14 ( struct V_15 * V_16 )
{
F_5 ( V_27 ,
( 1 << V_28 ) ,
V_16 -> V_20 , V_16 -> V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
F_5 ( V_25 ,
V_25 ,
V_16 -> V_20 , V_16 -> V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 , T_4 V_17 )
{
T_1 V_29 ;
V_29 = V_16 -> V_30 ;
if ( ! V_29 )
return - V_31 ;
F_5 ( V_29 , ( V_17 << F_17 ( V_29 ) ) ,
V_16 -> V_20 , V_16 -> V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 )
{
T_1 V_7 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_22 ) ;
V_7 &= V_32 ;
V_7 >>= V_33 ;
return V_7 ;
}
static int F_19 ( struct V_15 * V_16 )
{
T_1 V_7 , V_29 ;
V_29 = V_16 -> V_30 ;
if ( ! V_29 )
return - V_31 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_21 ) ;
V_7 &= V_29 ;
V_7 >>= F_17 ( V_29 ) ;
return V_7 ;
}
static int F_20 ( struct V_15 * V_16 , T_4 V_34 ,
T_4 V_17 )
{
T_1 V_29 ;
V_29 = V_16 -> V_35 [ V_34 ] ;
if ( ! V_29 )
return - V_31 ;
F_5 ( V_29 , ( V_17 << F_17 ( V_29 ) ) ,
V_16 -> V_20 , V_16 -> V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 , T_4 V_34 ,
T_4 V_17 )
{
T_1 V_29 ;
V_29 = V_16 -> V_36 [ V_34 ] ;
if ( ! V_29 )
return - V_31 ;
F_5 ( V_29 , ( V_17 << F_17 ( V_29 ) ) ,
V_16 -> V_20 , V_16 -> V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_15 * V_16 , T_4 V_34 )
{
T_1 V_29 , V_7 ;
V_29 = V_16 -> V_37 [ V_34 ] ;
if ( ! V_29 )
return - V_31 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_22 ) ;
V_7 &= V_29 ;
V_7 >>= F_17 ( V_29 ) ;
return V_7 ;
}
static int F_23 ( struct V_15 * V_16 , T_4 V_34 )
{
T_1 V_29 , V_7 ;
V_29 = V_16 -> V_38 [ V_34 ] ;
if ( ! V_29 )
return - V_31 ;
V_7 = F_1 ( V_16 -> V_20 , V_16 -> V_21 ) ;
V_7 &= V_29 ;
V_7 >>= F_17 ( V_29 ) ;
return V_7 ;
}
static int F_24 ( struct V_15 * V_16 )
{
T_1 V_11 = 0 ;
while ( ( F_1 ( V_16 -> V_20 , V_16 -> V_22 )
& V_39 ) &&
( V_11 ++ < V_40 ) )
F_25 ( 1 ) ;
if ( V_11 > V_40 ) {
F_26 ( L_1 ,
V_16 -> V_41 ) ;
return - V_42 ;
}
F_27 ( L_2 , V_11 ) ;
return 0 ;
}
