static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
if ( V_1 -> V_3 ) {
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 &= ~ ( 1 << V_1 -> V_4 ) ;
F_3 ( V_2 , V_1 -> V_3 ) ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
T_1 V_2 ;
if ( V_1 -> V_3 ) {
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 |= 1 << V_1 -> V_4 ;
F_3 ( V_2 , V_1 -> V_3 ) ;
}
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
return 24000000 ;
}
static unsigned long F_6 ( struct V_1 * V_1 )
{
return 480000000 ;
}
static int F_7 ( struct V_1 * V_1 )
{
F_3 ( V_5 |
V_6 ,
V_7 + V_8 ) ;
F_8 ( 10 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_1 )
{
F_3 ( V_5 |
V_6 ,
V_7 + V_9 ) ;
}
static unsigned long F_10 ( struct V_1 * V_1 )
{
return F_11 ( V_1 -> V_10 ) / 768 ;
}
static unsigned long F_12 ( struct V_1 * V_1 )
{
return V_1 -> V_10 -> V_11 ( V_1 -> V_10 ) / 750 ;
}
static int F_13 ( struct V_1 * V_1 , unsigned long V_12 )
{
T_1 V_2 , V_13 , V_14 , V_15 , V_16 , div , V_17 ;
unsigned long V_18 , V_19 , V_20 ;
int V_21 ;
V_19 = F_11 ( V_1 -> V_10 ) ;
if ( V_1 -> V_10 == & V_22 ) {
V_14 = V_23 >> V_24 ;
V_13 = V_25 ;
div = F_14 ( V_19 , V_12 ) ;
if ( div == 0 || div > V_14 )
return - V_26 ;
} else {
V_14 = V_27 >> V_28 ;
V_13 = V_29 ;
V_12 >>= V_30 ;
V_19 >>= V_30 ;
V_18 = V_19 ;
div = V_17 = 1 ;
for ( V_15 = 1 ; V_15 <= V_14 ; V_15 ++ ) {
V_16 = V_19 * 18 / V_15 / V_12 ;
if ( ( V_19 * 18 / V_15 ) % V_12 )
V_16 ++ ;
if ( V_16 < 18 || V_16 > 35 )
continue;
V_20 = V_19 * 18 / V_16 / V_15 ;
if ( V_20 > V_12 )
continue;
if ( V_12 - V_20 < V_18 ) {
V_17 = V_16 ;
div = V_15 ;
V_18 = V_12 - V_20 ;
}
if ( V_18 == 0 )
break;
}
if ( V_18 == V_19 )
return - V_26 ;
V_2 = F_2 ( V_7 + V_31 ) ;
V_2 &= ~ V_32 ;
V_2 |= V_17 ;
F_3 ( V_2 , V_7 + V_31 ) ;
}
V_2 = F_2 ( V_7 + V_33 ) ;
V_2 &= ~ V_27 ;
V_2 |= div << V_28 ;
F_3 ( V_2 , V_7 + V_33 ) ;
for ( V_21 = 10000 ; V_21 ; V_21 -- )
if ( ! ( F_2 ( V_7 +
V_33 ) & V_13 ) )
break;
if ( ! V_21 ) {
F_15 ( L_1 , V_34 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_16 ( void )
{
T_1 V_2 ;
int V_21 ;
V_2 = F_2 ( V_7 + V_36 ) ;
V_37 . V_10 = ( V_2 & V_38 ) ?
& V_22 : & V_39 ;
V_40 . V_10 = ( V_2 & V_41 ) ?
& V_22 : & V_42 ;
V_43 . V_10 = ( V_2 & V_44 ) ?
& V_22 : & V_45 ;
V_46 . V_10 = ( V_2 & V_47 ) ?
& V_22 : & V_45 ;
V_48 . V_10 = ( V_2 & V_49 ) ?
& V_22 : & V_50 ;
F_3 ( V_51 ,
V_7 + V_52 ) ;
F_3 ( V_53 ,
V_7 + V_52 ) ;
F_3 ( V_54 ,
V_7 + V_55 ) ;
V_2 = F_2 ( V_7 + V_56 ) ;
V_2 &= ~ V_57 ;
F_3 ( V_2 , V_7 + V_56 ) ;
V_2 = F_2 ( V_7 + V_58 ) ;
V_2 &= ~ V_59 ;
F_3 ( V_2 , V_7 + V_58 ) ;
V_2 = F_2 ( V_7 + V_60 ) ;
V_2 &= ~ V_61 ;
F_3 ( V_2 , V_7 + V_60 ) ;
V_2 = F_2 ( V_7 + V_62 ) ;
V_2 &= ~ V_63 ;
F_3 ( V_2 , V_7 + V_62 ) ;
V_2 = F_2 ( V_7 + V_64 ) ;
V_2 &= V_65 ;
V_2 |= 3 << V_66 ;
F_3 ( V_2 , V_7 + V_64 ) ;
for ( V_21 = 10000 ; V_21 ; V_21 -- )
if ( ! ( F_2 ( V_7 +
V_64 ) & V_67 ) )
break;
if ( ! V_21 ) {
F_15 ( L_1 , V_34 ) ;
return - V_35 ;
}
F_3 ( V_68 ,
V_7 + V_69 ) ;
V_2 = F_2 ( V_7 + V_31 ) ;
V_2 &= ~ V_70 ;
V_2 |= 30 << V_71 ;
F_3 ( V_2 , V_7 + V_31 ) ;
return 0 ;
}
int T_2 F_17 ( void )
{
F_16 () ;
F_18 ( & V_43 , & V_45 ) ;
F_19 ( & V_37 ) ;
F_19 ( & V_72 ) ;
F_19 ( & V_73 ) ;
F_19 ( & V_40 ) ;
F_19 ( & V_74 ) ;
F_20 ( V_75 , F_21 ( V_75 ) ) ;
F_22 ( & V_76 , V_77 ) ;
return 0 ;
}
