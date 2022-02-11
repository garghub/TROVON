static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
return F_2 ( V_6 -> V_8 ) ;
}
static unsigned int
F_3 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_9 * V_10 = V_4 -> V_7 ;
T_1 V_11 = V_10 -> V_8 ;
if ( V_10 -> V_12 > 1 ) {
V_11 = F_4 ( V_2 , V_11 , V_10 -> V_12 ,
V_4 -> V_13 , V_14 ) ;
}
return F_2 ( V_11 ) ;
}
static unsigned int
F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_15 * V_10 = V_4 -> V_7 ;
unsigned int V_16 = F_3 ( V_2 , V_4 ) ;
if ( V_10 -> V_17 )
V_16 |= V_18 ;
return V_16 ;
}
static int F_6 ( const struct V_19 * V_4 )
{
const struct V_20 * V_10 = V_4 -> V_7 ;
T_1 V_21 ;
F_7 ( & V_14 ) ;
if ( V_10 -> V_12 == 0 ) {
F_8 ( L_1 ) ;
return - V_22 ;
}
V_21 = V_10 -> V_12 - 1 + V_10 -> V_8 ;
if ( V_21 > 0xffff ) {
F_8 ( L_2 ,
V_10 -> V_12 , V_21 ) ;
return - V_23 ;
}
if ( V_4 -> V_24 -> V_25 == 2 && V_10 -> V_26 > 1 )
return - V_22 ;
if ( V_4 -> V_24 -> V_25 == 3 && V_10 -> V_26 & ~ V_27 )
return - V_22 ;
return 0 ;
}
static unsigned int
F_9 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_20 * V_10 = V_4 -> V_7 ;
T_1 V_11 = V_10 -> V_8 ;
int V_16 ;
if ( V_10 -> V_12 > 1 ) {
if ( V_10 -> V_26 & V_28 ) {
int V_29 = F_10 () ;
V_11 = V_10 -> V_8 + V_29 % V_10 -> V_12 ;
} else {
V_11 = F_4 ( V_2 , V_11 , V_10 -> V_12 ,
V_4 -> V_13 , V_14 ) ;
}
}
V_16 = F_2 ( V_11 ) ;
if ( V_10 -> V_26 & V_30 )
V_16 |= V_18 ;
return V_16 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( V_31 , F_13 ( V_31 ) ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( V_31 , F_13 ( V_31 ) ) ;
}
