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
static int T_1 F_4 ( void )
{
int V_17 ;
if ( V_18 == 0 )
return 0 ;
F_5 ( V_19 L_1 ) ;
V_17 = F_6 ( V_20 , F_7 ( V_20 ) ) ;
if ( V_17 )
F_8 ( L_2 , V_17 ) ;
return 0 ;
}
