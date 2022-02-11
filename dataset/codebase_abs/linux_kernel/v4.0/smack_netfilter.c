static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_4 && V_4 -> V_12 && V_4 -> V_12 -> V_13 ) {
V_9 = V_4 -> V_12 -> V_13 ;
V_11 = V_9 -> V_14 ;
V_4 -> V_15 = V_11 -> V_16 ;
}
return V_17 ;
}
static unsigned int F_3 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_4 && V_4 -> V_12 && V_4 -> V_12 -> V_13 ) {
V_9 = V_4 -> V_12 -> V_13 ;
V_11 = V_9 -> V_14 ;
V_4 -> V_15 = V_11 -> V_16 ;
}
return V_17 ;
}
static int T_1 F_4 ( void )
{
int V_18 ;
if ( V_19 == 0 )
return 0 ;
F_5 ( V_20 L_1 ) ;
V_18 = F_6 ( V_21 , F_7 ( V_21 ) ) ;
if ( V_18 )
F_8 ( L_2 , V_18 ) ;
return 0 ;
}
