static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
if ( V_4 -> V_8 & V_9 )
V_5 >>= 4 ;
return ! ! ( V_5 & V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
if ( V_4 -> V_8 & V_9 )
V_5 |= V_10 << 4 ;
else
V_5 |= V_10 ;
F_5 ( V_5 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
if ( V_4 -> V_8 & V_9 )
V_5 &= ~ ( V_10 << 4 ) ;
else
V_5 &= ~ V_10 ;
F_5 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static unsigned long
F_7 ( struct V_1 * V_2 , unsigned long V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_12 , V_13 ;
T_2 V_14 = V_11 ;
V_5 = F_3 ( V_4 -> V_6 + V_15 ) ;
V_12 = ( V_5 & V_16 ) >> V_17 ;
V_12 = V_18 [ V_12 ] ;
V_13 = ( V_5 & V_19 ) >> V_20 ;
V_14 *= V_13 ;
F_8 ( V_14 , V_12 ) ;
return ( unsigned long ) V_14 ;
}
struct V_21 * T_3 F_9 ( void T_4 * V_6 ,
const char * V_22 , const char * V_23 ,
T_5 V_24 , unsigned long V_8 )
{
struct V_3 * V_4 ;
struct V_25 V_26 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return F_11 ( - V_28 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_24 ;
V_4 -> V_2 . V_26 = & V_26 ;
V_26 . V_22 = V_22 ;
V_26 . V_29 = & V_30 ;
V_26 . V_31 = & V_23 ;
V_26 . V_32 = 1 ;
V_26 . V_8 = V_8 ;
return F_12 ( NULL , & V_4 -> V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_14 ( V_2 ) ;
T_1 V_5 ;
if ( V_34 -> V_35 == 7 )
return 1 ;
V_5 = F_3 ( V_34 -> V_6 + V_36 ) ;
V_5 &= V_37 << V_34 -> V_35 ;
return ! ! V_5 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_14 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_34 -> V_6 + V_36 ) ;
V_5 |= V_37 << V_34 -> V_35 ;
F_5 ( V_5 , V_34 -> V_6 + V_36 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_14 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_34 -> V_6 + V_36 ) ;
V_5 &= ~ ( V_37 << V_34 -> V_35 ) ;
F_5 ( V_5 , V_34 -> V_6 + V_36 ) ;
}
static unsigned long
F_17 ( struct V_1 * V_2 , unsigned long V_11 )
{
struct V_33 * V_34 = F_14 ( V_2 ) ;
T_1 V_5 , V_38 , V_39 , V_40 = 1 ;
T_2 V_14 = V_11 ;
V_5 = F_3 ( V_34 -> V_6 + V_41 ) ;
if ( ( V_5 & ( V_42 << V_34 -> V_35 ) ) == 0 )
goto V_43;
V_5 = F_3 ( V_34 -> V_6 + F_18 ( V_34 -> V_35 ) ) ;
if ( V_34 -> V_8 & V_9 && V_34 -> V_35 == 0 )
V_5 >>= 4 ;
V_40 = V_5 & V_44 ;
V_5 = F_3 ( V_34 -> V_6 + F_19 ( V_34 -> V_35 ) ) ;
V_14 *= V_5 & V_45 ;
if ( V_34 -> V_35 == 7 )
goto V_43;
V_5 = F_3 ( V_34 -> V_6 + V_46 ) >> 7 ;
V_5 = ( V_5 >> ( V_34 -> V_35 * 3 ) ) ;
if ( V_5 & F_20 ( 2 ) )
V_40 *= V_47 [ V_5 & 0x3 ] ;
if ( V_34 -> V_35 == 0 ) {
V_5 = F_3 ( V_34 -> V_6 + V_46 ) ;
V_5 >>= 28 ;
} else {
V_5 = F_3 ( V_34 -> V_6 + V_48 ) ;
V_5 >>= ( V_34 -> V_35 - 1 ) * 3 ;
}
if ( V_5 & F_20 ( 2 ) )
V_40 *= V_49 [ V_5 & 0x3 ] ;
if ( V_34 -> V_35 < 2 ) {
V_5 = F_3 ( V_34 -> V_6 + V_48 ) ;
V_5 >>= 18 + ( V_34 -> V_35 * 7 ) ;
} else if ( V_34 -> V_35 < 7 ) {
V_5 = F_3 ( V_34 -> V_6 + V_50 ) ;
V_5 >>= ( V_34 -> V_35 - 2 ) * 7 ;
} else {
V_5 = F_3 ( V_34 -> V_6 + V_51 ) ;
}
V_38 = V_5 & 0x7f ;
if ( V_38 )
V_40 *= V_38 ;
if ( V_34 -> V_35 < 6 ) {
V_5 = F_3 ( V_34 -> V_6 + V_51 ) ;
V_5 >>= 7 + ( V_34 -> V_35 * 4 ) ;
} else {
V_5 = F_3 ( V_34 -> V_6 + V_52 ) ;
}
V_39 = V_5 & 0xf ;
if ( V_38 && V_39 )
V_14 *= 2 ;
V_43:
F_8 ( V_14 , V_40 ) ;
return ( unsigned long ) V_14 ;
}
struct V_21 * T_3 F_21 ( void T_4 * V_6 ,
const char * V_22 , T_5 V_35 , const char * V_23 ,
T_5 V_53 , unsigned long V_8 )
{
struct V_33 * V_34 ;
struct V_25 V_26 ;
V_34 = F_10 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 )
return F_11 ( - V_28 ) ;
V_34 -> V_6 = V_6 ;
if ( V_53 & V_54 )
V_34 -> V_35 = V_55 [ V_35 ] ;
else
V_34 -> V_35 = V_35 ;
V_34 -> V_8 = V_53 ;
V_34 -> V_2 . V_26 = & V_26 ;
V_26 . V_22 = V_22 ;
V_26 . V_29 = & V_56 ;
V_26 . V_31 = & V_23 ;
V_26 . V_32 = 1 ;
V_26 . V_8 = V_8 ;
return F_12 ( NULL , & V_34 -> V_2 ) ;
}
