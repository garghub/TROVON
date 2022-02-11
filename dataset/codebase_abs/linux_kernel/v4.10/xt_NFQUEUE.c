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
F_5 ( V_4 ) , V_13 ) ;
}
return F_2 ( V_11 ) ;
}
static unsigned int
F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_14 * V_10 = V_4 -> V_7 ;
unsigned int V_15 = F_3 ( V_2 , V_4 ) ;
if ( V_10 -> V_16 )
V_15 |= V_17 ;
return V_15 ;
}
static int F_7 ( const struct V_18 * V_4 )
{
const struct V_19 * V_10 = V_4 -> V_7 ;
T_1 V_20 ;
F_8 ( & V_13 ) ;
if ( V_10 -> V_12 == 0 ) {
F_9 ( L_1 ) ;
return - V_21 ;
}
V_20 = V_10 -> V_12 - 1 + V_10 -> V_8 ;
if ( V_20 > 0xffff ) {
F_9 ( L_2 ,
V_10 -> V_12 , V_20 ) ;
return - V_22 ;
}
if ( V_4 -> V_23 -> V_24 == 2 && V_10 -> V_25 > 1 )
return - V_21 ;
if ( V_4 -> V_23 -> V_24 == 3 && V_10 -> V_25 & ~ V_26 )
return - V_21 ;
return 0 ;
}
static unsigned int
F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_19 * V_10 = V_4 -> V_7 ;
T_1 V_11 = V_10 -> V_8 ;
int V_15 ;
if ( V_10 -> V_12 > 1 ) {
if ( V_10 -> V_25 & V_27 ) {
int V_28 = F_11 () ;
V_11 = V_10 -> V_8 + V_28 % V_10 -> V_12 ;
} else {
V_11 = F_4 ( V_2 , V_11 , V_10 -> V_12 ,
F_5 ( V_4 ) , V_13 ) ;
}
}
V_15 = F_2 ( V_11 ) ;
if ( V_10 -> V_25 & V_29 )
V_15 |= V_17 ;
return V_15 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( V_30 , F_14 ( V_30 ) ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( V_30 , F_14 ( V_30 ) ) ;
}
