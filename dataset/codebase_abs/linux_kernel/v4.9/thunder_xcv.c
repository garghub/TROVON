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
F_6 ( & V_2 -> V_14 -> V_15 ,
L_1 ) ;
return;
}
if ( V_12 == 100 )
V_13 = 1 ;
else if ( V_12 == 10 )
V_13 = 0 ;
if ( V_11 ) {
V_1 = F_2 ( V_2 -> V_3 + V_16 ) ;
V_1 &= ~ 0x03 ;
V_1 |= V_13 ;
F_3 ( V_1 , V_2 -> V_3 + V_16 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_17 | V_18 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 |= V_19 | V_20 ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
F_3 ( 0x01 , V_2 -> V_3 + V_21 ) ;
} else {
V_1 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_1 &= ~ ( V_19 | V_20 ) ;
F_3 ( V_1 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_2 -> V_3 + V_4 ) ;
}
}
static int F_7 ( struct V_22 * V_14 , const struct V_23 * V_24 )
{
int V_25 ;
struct V_26 * V_15 = & V_14 -> V_15 ;
V_2 = F_8 ( V_15 , sizeof( struct V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_14 = V_14 ;
F_9 ( V_14 , V_2 ) ;
V_25 = F_10 ( V_14 ) ;
if ( V_25 ) {
F_6 ( V_15 , L_2 ) ;
goto V_29;
}
V_25 = F_11 ( V_14 , V_30 ) ;
if ( V_25 ) {
F_6 ( V_15 , L_3 , V_25 ) ;
goto V_31;
}
V_2 -> V_3 = F_12 ( V_14 , V_32 , 0 ) ;
if ( ! V_2 -> V_3 ) {
F_6 ( V_15 , L_4 ) ;
V_25 = - V_28 ;
goto V_33;
}
return 0 ;
V_33:
F_13 ( V_14 ) ;
V_31:
F_14 ( V_14 ) ;
V_29:
F_15 ( V_15 , V_2 ) ;
V_2 = NULL ;
return V_25 ;
}
static void F_16 ( struct V_22 * V_14 )
{
struct V_26 * V_15 = & V_14 -> V_15 ;
if ( V_2 ) {
F_15 ( V_15 , V_2 ) ;
V_2 = NULL ;
}
F_13 ( V_14 ) ;
F_14 ( V_14 ) ;
}
static int T_2 F_17 ( void )
{
F_18 ( L_5 , V_30 , V_34 ) ;
return F_19 ( & V_35 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_35 ) ;
}
