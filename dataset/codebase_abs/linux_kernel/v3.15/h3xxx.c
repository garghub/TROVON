static void F_1 ( int V_1 )
{
F_2 ( V_2 , V_1 ) ;
}
static int F_3 ( void )
{
int V_3 = F_4 ( V_2 , L_1 ) ;
if ( V_3 ) {
F_5 ( L_2 , V_4 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 , 0 ) ;
if ( V_3 )
F_7 ( V_2 ) ;
return V_3 ;
}
static void F_8 ( void )
{
F_7 ( V_2 ) ;
}
static bool F_9 ( void )
{
static bool V_5 ;
int V_6 ;
if ( V_5 )
return true ;
V_6 = F_10 ( V_7 , F_11 ( V_7 ) ) ;
if ( V_6 )
F_5 ( L_3 , V_6 ) ;
else
V_5 = true ;
return V_5 ;
}
static void F_12 ( struct V_8 * V_9 , T_1 V_10 )
{
if ( V_9 -> V_11 == V_12 ) {
if ( ! F_9 () )
return;
F_2 ( V_13 , ! ( V_10 & V_14 ) ) ;
}
}
static T_1 F_13 ( struct V_8 * V_9 )
{
T_1 V_15 = V_16 | V_17 | V_18 ;
if ( V_9 -> V_11 == V_12 ) {
if ( ! F_9 () )
return V_15 ;
if ( F_14 ( V_19 ) )
V_15 &= ~ V_16 ;
if ( F_14 ( V_20 ) )
V_15 &= ~ V_17 ;
}
return V_15 ;
}
static void F_15 ( struct V_8 * V_9 , T_1 V_21 , T_1 V_22 )
{
if ( V_9 -> V_11 == V_12 ) {
if ( ! F_4 ( V_23 , L_4 ) ) {
F_6 ( V_23 , ! V_21 ) ;
F_7 ( V_23 ) ;
} else {
F_5 ( L_5 ,
V_4 ) ;
}
}
}
static int F_16 ( struct V_8 * V_9 , T_1 V_24 )
{
int V_3 = - V_25 ;
if ( V_9 -> V_11 == V_12 ) {
if ( V_24 )
V_26 |= V_27 | V_28 ;
else
V_26 &= ~ ( V_27 | V_28 ) ;
V_3 = 0 ;
}
return V_3 ;
}
void T_2 F_17 ( void )
{
F_18 ( & V_29 ) ;
F_19 ( & V_30 , & V_31 , 1 ) ;
F_20 ( V_32 , F_11 ( V_32 ) ) ;
}
void T_2 F_21 ( void )
{
F_22 () ;
F_23 ( V_33 , F_11 ( V_33 ) ) ;
F_24 ( 0 , 3 ) ;
V_34 |= V_35 | V_36 | V_37 ;
V_38 &= ~ ( V_35 | V_36 | V_37 ) ;
V_39 = 0 ;
V_40 = V_41 ;
V_42 = 0 ;
V_43 = 0x0fffffff ;
V_44 = 0 ;
}
