static void
F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 ;
while ( 1 ) {
V_3 -> V_5 . V_6 -> V_7 ( & V_3 -> V_5 ) ;
V_4 = V_8 ^ ( V_9 | V_10 ) ;
if ( ( V_4 & ( V_9 | V_10 | V_11 ) ) == 0 )
break;
if ( V_4 & ( V_9 | V_10 ) ) {
V_3 -> V_5 . V_6 -> V_12 ( & V_3 -> V_5 ) ;
V_3 -> V_5 . V_6 -> V_7 ( & V_3 -> V_5 ) ;
if ( V_4 & V_9 ) {
F_2 ( V_13 ) ;
}
if ( V_4 & V_10 ) {
F_2 ( V_14 ) ;
}
V_3 -> V_5 . V_6 -> V_15 ( & V_3 -> V_5 ) ;
}
if ( V_4 & V_11 ) {
F_2 ( V_16 ) ;
}
}
}
static void F_3 ( struct V_17 * V_18 , T_1 V_19 )
{
T_1 V_20 = V_21 ;
if ( V_18 -> V_22 == V_23 ) {
if ( V_19 & V_24 )
V_20 &= ~ V_25 ;
else
V_20 |= V_25 ;
if ( V_19 & V_26 )
V_20 &= ~ V_27 ;
else
V_20 |= V_27 ;
} else if ( V_18 -> V_22 == V_28 ) {
if ( V_19 & V_24 )
V_20 &= ~ V_29 ;
else
V_20 |= V_29 ;
if ( V_19 & V_26 )
V_20 &= ~ V_30 ;
else
V_20 |= V_30 ;
}
V_21 = V_20 ;
}
static T_1 F_4 ( struct V_17 * V_18 )
{
T_1 V_31 = V_32 | V_33 | V_34 ;
T_1 V_35 = V_36 ;
if ( V_18 -> V_22 == V_23 ) {
if ( V_35 & V_37 )
V_31 &= ~ V_32 ;
if ( V_35 & V_38 )
V_31 &= ~ V_33 ;
if ( V_35 & V_39 )
V_31 &= ~ V_34 ;
} else if ( V_18 -> V_22 == V_28 ) {
if ( V_35 & V_40 )
V_31 &= ~ V_32 ;
if ( V_35 & V_41 )
V_31 &= ~ V_33 ;
if ( V_35 & V_42 )
V_31 &= ~ V_34 ;
}
return V_31 ;
}
static int T_2 F_5 ( struct V_43 * V_44 )
{
F_6 ( & V_45 ) ;
F_7 ( V_46 , V_47 ) ;
F_8 ( V_46 , F_1 ) ;
#if 0
enable_irq_wake(IRQ_GPIO25);
#endif
F_9 ( V_13 , V_48 ) ;
F_10 ( V_13 , V_49 | V_50 ) ;
F_9 ( V_14 , V_48 ) ;
F_10 ( V_14 , V_49 | V_50 ) ;
V_51 = V_52 ;
return 0 ;
}
static int F_11 ( struct V_43 * V_44 , T_3 V_53 )
{
V_54 = V_51 ;
return 0 ;
}
static int F_12 ( struct V_43 * V_44 )
{
V_51 = V_54 ;
return 0 ;
}
static int T_4 F_13 ( void )
{
F_14 ( & V_55 ) ;
if ( ! F_15 () )
return - V_56 ;
F_16 () ;
if ( ! F_17 () ) {
F_18 ( V_57 L_1 ) ;
return - V_56 ;
}
if ( V_58 != 0x11 ) {
F_18 ( V_59 L_2
L_3 , V_58 ) ;
return - V_56 ;
}
return F_19 ( V_60 , F_20 ( V_60 ) ) ;
}
void T_4 F_21 ( void )
{
F_22 ( V_61 , F_20 ( V_61 ) ) ;
}
