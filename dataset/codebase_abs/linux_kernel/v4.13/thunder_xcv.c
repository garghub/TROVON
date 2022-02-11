void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 &= ~ V_5 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 &= ~ V_6 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
F_4 ( 1 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_7 ) ;
V_1 &= ~ 0xFF03 ;
V_1 |= V_8 ;
F_3 ( V_1 , V_2 -> V_3 + V_7 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_9 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_2 -> V_3 + V_4 ) ;
F_4 ( 10 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_10 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_6 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
}
void F_5 ( bool V_11 , int V_12 )
{
T_1 V_1 ;
int V_13 = 2 ;
if ( ! V_2 ) {
F_6 ( L_1 ) ;
return;
}
if ( V_12 == 100 )
V_13 = 1 ;
else if ( V_12 == 10 )
V_13 = 0 ;
if ( V_11 ) {
V_1 = F_2 ( V_2 -> V_3 + V_14 ) ;
V_1 &= ~ 0x03 ;
V_1 |= V_13 ;
F_3 ( V_1 , V_2 -> V_3 + V_14 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_15 | V_16 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_17 | V_18 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
F_3 ( 0x01 , V_2 -> V_3 + V_19 ) ;
} else {
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 &= ~ ( V_17 | V_18 ) ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_2 -> V_3 + V_4 ) ;
}
}
static int F_7 ( struct V_20 * V_21 , const struct V_22 * V_23 )
{
int V_24 ;
struct V_25 * V_26 = & V_21 -> V_26 ;
V_2 = F_8 ( V_26 , sizeof( struct V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_21 = V_21 ;
F_9 ( V_21 , V_2 ) ;
V_24 = F_10 ( V_21 ) ;
if ( V_24 ) {
F_11 ( V_26 , L_2 ) ;
goto V_29;
}
V_24 = F_12 ( V_21 , V_30 ) ;
if ( V_24 ) {
F_11 ( V_26 , L_3 , V_24 ) ;
goto V_31;
}
V_2 -> V_3 = F_13 ( V_21 , V_32 , 0 ) ;
if ( ! V_2 -> V_3 ) {
F_11 ( V_26 , L_4 ) ;
V_24 = - V_28 ;
goto V_33;
}
return 0 ;
V_33:
F_14 ( V_21 ) ;
V_31:
F_15 ( V_21 ) ;
V_29:
F_16 ( V_26 , V_2 ) ;
V_2 = NULL ;
return V_24 ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = & V_21 -> V_26 ;
if ( V_2 ) {
F_16 ( V_26 , V_2 ) ;
V_2 = NULL ;
}
F_14 ( V_21 ) ;
F_15 ( V_21 ) ;
}
static int T_2 F_18 ( void )
{
F_19 ( L_5 , V_30 , V_34 ) ;
return F_20 ( & V_35 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_35 ) ;
}
