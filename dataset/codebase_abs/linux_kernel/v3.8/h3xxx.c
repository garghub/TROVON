void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
while ( V_3 -- ) {
const char * V_4 = V_2 -> V_4 ;
int V_5 ;
if ( ! V_4 )
V_4 = L_1 ;
V_5 = F_2 ( V_2 -> V_6 , V_4 ) ;
if ( V_5 ) {
F_3 ( V_7 L_2 ,
V_2 -> V_6 , V_5 ) ;
continue;
}
if ( V_2 -> V_8 >= 0 ) {
V_5 = F_4 ( V_2 -> V_6 , V_2 -> V_8 ) ;
} else {
V_5 = F_5 ( V_2 -> V_6 ) ;
}
if ( V_5 ) {
F_3 ( V_7 L_3 ,
V_2 -> V_6 , V_5 ) ;
continue;
}
if ( ! V_2 -> V_4 )
F_6 ( V_2 -> V_6 ) ;
V_2 ++ ;
}
}
static void F_7 ( int V_9 )
{
F_8 ( V_10 , V_9 ) ;
}
static int F_9 ( void )
{
int V_5 = F_2 ( V_10 , L_4 ) ;
if ( V_5 ) {
F_10 ( L_5 , V_11 ) ;
return V_5 ;
}
V_5 = F_4 ( V_10 , 0 ) ;
if ( V_5 )
F_6 ( V_10 ) ;
return V_5 ;
}
static void F_11 ( void )
{
F_6 ( V_10 ) ;
}
static void F_12 ( struct V_12 * V_13 , T_2 V_14 )
{
if ( V_13 -> V_15 == V_16 ) {
F_8 ( V_17 , ! ( V_14 & V_18 ) ) ;
}
}
static T_2 F_13 ( struct V_12 * V_13 )
{
T_2 V_19 = V_20 | V_21 | V_22 ;
if ( V_13 -> V_15 == V_16 ) {
if ( F_14 ( V_23 ) )
V_19 &= ~ V_20 ;
if ( F_14 ( V_24 ) )
V_19 &= ~ V_21 ;
}
return V_19 ;
}
static void F_15 ( struct V_12 * V_13 , T_2 V_25 , T_2 V_26 )
{
if ( V_13 -> V_15 == V_16 ) {
if ( ! F_2 ( V_27 , L_6 ) ) {
F_4 ( V_27 , ! V_25 ) ;
F_6 ( V_27 ) ;
} else {
F_10 ( L_7 ,
V_11 ) ;
}
}
}
static int F_16 ( struct V_12 * V_13 , T_2 V_28 )
{
int V_5 = - V_29 ;
if ( V_13 -> V_15 == V_16 ) {
if ( V_28 )
V_30 |= V_31 | V_32 ;
else
V_30 &= ~ ( V_31 | V_32 ) ;
V_5 = 0 ;
}
return V_5 ;
}
void T_3 F_17 ( void )
{
F_18 ( & V_33 ) ;
F_19 ( & V_34 , & V_35 , 1 ) ;
F_20 ( V_36 , F_21 ( V_36 ) ) ;
}
void T_3 F_22 ( void )
{
F_23 () ;
F_24 ( V_37 , F_21 ( V_37 ) ) ;
F_25 ( 0 , 3 ) ;
V_38 |= V_39 | V_40 | V_41 ;
V_42 &= ~ ( V_39 | V_40 | V_41 ) ;
V_43 = 0 ;
V_44 = V_45 ;
V_46 = 0 ;
V_47 = 0x0fffffff ;
V_48 = 0 ;
}
