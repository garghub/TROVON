static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_7 && V_7 -> V_12 ) {
V_9 = V_7 -> V_12 ;
V_11 = V_9 -> V_13 ;
V_3 -> V_14 = V_11 -> V_15 ;
}
return V_16 ;
}
static unsigned int F_3 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_7 && V_7 -> V_12 ) {
V_9 = V_7 -> V_12 ;
V_11 = V_9 -> V_13 ;
V_3 -> V_14 = V_11 -> V_15 ;
}
return V_16 ;
}
static int T_1 F_4 ( struct V_17 * V_17 )
{
return F_5 ( V_17 , V_18 ,
F_6 ( V_18 ) ) ;
}
static void T_2 F_7 ( struct V_17 * V_17 )
{
F_8 ( V_17 , V_18 , F_6 ( V_18 ) ) ;
}
static int T_3 F_9 ( void )
{
if ( V_19 == 0 )
return 0 ;
F_10 ( V_20 L_1 ) ;
return F_11 ( & V_21 ) ;
}
