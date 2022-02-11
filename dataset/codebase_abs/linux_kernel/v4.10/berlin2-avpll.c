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
int T_3 F_9 ( void T_4 * V_6 ,
const char * V_21 , const char * V_22 ,
T_5 V_23 , unsigned long V_8 )
{
struct V_3 * V_4 ;
struct V_24 V_25 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_23 ;
V_4 -> V_2 . V_25 = & V_25 ;
V_25 . V_21 = V_21 ;
V_25 . V_28 = & V_29 ;
V_25 . V_30 = & V_22 ;
V_25 . V_31 = 1 ;
V_25 . V_8 = V_8 ;
return F_11 ( NULL , & V_4 -> V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_13 ( V_2 ) ;
T_1 V_5 ;
if ( V_33 -> V_34 == 7 )
return 1 ;
V_5 = F_3 ( V_33 -> V_6 + V_35 ) ;
V_5 &= V_36 << V_33 -> V_34 ;
return ! ! V_5 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_13 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_33 -> V_6 + V_35 ) ;
V_5 |= V_36 << V_33 -> V_34 ;
F_5 ( V_5 , V_33 -> V_6 + V_35 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_13 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_33 -> V_6 + V_35 ) ;
V_5 &= ~ ( V_36 << V_33 -> V_34 ) ;
F_5 ( V_5 , V_33 -> V_6 + V_35 ) ;
}
static unsigned long
F_16 ( struct V_1 * V_2 , unsigned long V_11 )
{
struct V_32 * V_33 = F_13 ( V_2 ) ;
T_1 V_5 , V_37 , V_38 , V_39 = 1 ;
T_2 V_14 = V_11 ;
V_5 = F_3 ( V_33 -> V_6 + V_40 ) ;
if ( ( V_5 & ( V_41 << V_33 -> V_34 ) ) == 0 )
goto V_42;
V_5 = F_3 ( V_33 -> V_6 + F_17 ( V_33 -> V_34 ) ) ;
if ( V_33 -> V_8 & V_9 && V_33 -> V_34 == 0 )
V_5 >>= 4 ;
V_39 = V_5 & V_43 ;
V_5 = F_3 ( V_33 -> V_6 + F_18 ( V_33 -> V_34 ) ) ;
V_14 *= V_5 & V_44 ;
if ( V_33 -> V_34 == 7 )
goto V_42;
V_5 = F_3 ( V_33 -> V_6 + V_45 ) >> 7 ;
V_5 = ( V_5 >> ( V_33 -> V_34 * 3 ) ) ;
if ( V_5 & F_19 ( 2 ) )
V_39 *= V_46 [ V_5 & 0x3 ] ;
if ( V_33 -> V_34 == 0 ) {
V_5 = F_3 ( V_33 -> V_6 + V_45 ) ;
V_5 >>= 28 ;
} else {
V_5 = F_3 ( V_33 -> V_6 + V_47 ) ;
V_5 >>= ( V_33 -> V_34 - 1 ) * 3 ;
}
if ( V_5 & F_19 ( 2 ) )
V_39 *= V_48 [ V_5 & 0x3 ] ;
if ( V_33 -> V_34 < 2 ) {
V_5 = F_3 ( V_33 -> V_6 + V_47 ) ;
V_5 >>= 18 + ( V_33 -> V_34 * 7 ) ;
} else if ( V_33 -> V_34 < 7 ) {
V_5 = F_3 ( V_33 -> V_6 + V_49 ) ;
V_5 >>= ( V_33 -> V_34 - 2 ) * 7 ;
} else {
V_5 = F_3 ( V_33 -> V_6 + V_50 ) ;
}
V_37 = V_5 & 0x7f ;
if ( V_37 )
V_39 *= V_37 ;
if ( V_33 -> V_34 < 6 ) {
V_5 = F_3 ( V_33 -> V_6 + V_50 ) ;
V_5 >>= 7 + ( V_33 -> V_34 * 4 ) ;
} else {
V_5 = F_3 ( V_33 -> V_6 + V_51 ) ;
}
V_38 = V_5 & 0xf ;
if ( V_37 && V_38 )
V_14 *= 2 ;
V_42:
F_8 ( V_14 , V_39 ) ;
return ( unsigned long ) V_14 ;
}
int T_3 F_20 ( void T_4 * V_6 ,
const char * V_21 , T_5 V_34 , const char * V_22 ,
T_5 V_52 , unsigned long V_8 )
{
struct V_32 * V_33 ;
struct V_24 V_25 ;
V_33 = F_10 ( sizeof( * V_33 ) , V_26 ) ;
if ( ! V_33 )
return - V_27 ;
V_33 -> V_6 = V_6 ;
if ( V_52 & V_53 )
V_33 -> V_34 = V_54 [ V_34 ] ;
else
V_33 -> V_34 = V_34 ;
V_33 -> V_8 = V_52 ;
V_33 -> V_2 . V_25 = & V_25 ;
V_25 . V_21 = V_21 ;
V_25 . V_28 = & V_55 ;
V_25 . V_30 = & V_22 ;
V_25 . V_31 = 1 ;
V_25 . V_8 = V_8 ;
return F_11 ( NULL , & V_33 -> V_2 ) ;
}
