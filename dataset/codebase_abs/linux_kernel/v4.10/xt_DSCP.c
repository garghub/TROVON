static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 = F_2 ( F_3 ( V_2 ) ) >> V_9 ;
if ( V_8 != V_6 -> V_8 ) {
if ( ! F_4 ( V_2 , sizeof( struct V_10 ) ) )
return V_11 ;
F_5 ( F_3 ( V_2 ) ,
( V_12 V_13 ) ( ~ V_14 ) ,
V_6 -> V_8 << V_9 ) ;
}
return V_15 ;
}
static unsigned int
F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 = F_7 ( F_8 ( V_2 ) ) >> V_9 ;
if ( V_8 != V_6 -> V_8 ) {
if ( ! F_4 ( V_2 , sizeof( struct V_16 ) ) )
return V_11 ;
F_9 ( F_8 ( V_2 ) ,
( V_12 V_13 ) ( ~ V_14 ) ,
V_6 -> V_8 << V_9 ) ;
}
return V_15 ;
}
static int F_10 ( const struct V_17 * V_4 )
{
const struct V_5 * V_18 = V_4 -> V_7 ;
if ( V_18 -> V_8 > V_19 ) {
F_11 ( L_1 , V_18 -> V_8 ) ;
return - V_20 ;
}
return 0 ;
}
static unsigned int
F_12 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_21 * V_18 = V_4 -> V_7 ;
struct V_10 * V_22 = F_3 ( V_2 ) ;
T_1 V_23 , V_24 ;
V_23 = F_2 ( V_22 ) ;
V_24 = ( V_23 & ~ V_18 -> V_25 ) ^ V_18 -> V_26 ;
if ( V_23 != V_24 ) {
if ( ! F_4 ( V_2 , sizeof( struct V_10 ) ) )
return V_11 ;
V_22 = F_3 ( V_2 ) ;
F_5 ( V_22 , 0 , V_24 ) ;
}
return V_15 ;
}
static unsigned int
F_13 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_21 * V_18 = V_4 -> V_7 ;
struct V_16 * V_22 = F_8 ( V_2 ) ;
T_1 V_23 , V_24 ;
V_23 = F_7 ( V_22 ) ;
V_24 = ( V_23 & ~ V_18 -> V_25 ) ^ V_18 -> V_26 ;
if ( V_23 != V_24 ) {
if ( ! F_4 ( V_2 , sizeof( struct V_10 ) ) )
return V_11 ;
V_22 = F_8 ( V_2 ) ;
F_9 ( V_22 , 0 , V_24 ) ;
}
return V_15 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( V_27 , F_16 ( V_27 ) ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( V_27 , F_16 ( V_27 ) ) ;
}
