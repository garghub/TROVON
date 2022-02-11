static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
unsigned int V_10 ;
struct V_11 * V_12 = F_2 ( V_2 , & V_9 ) ;
if ( V_12 )
V_10 = F_3 ( V_9 ) ;
else if ( V_9 == V_13 )
V_10 = V_14 ;
else
V_10 = V_15 ;
return ( V_6 -> V_16 & V_10 ) ;
}
static int F_4 ( const struct V_17 * V_4 )
{
int V_18 ;
V_18 = F_5 ( V_4 -> V_19 , V_4 -> V_20 ) ;
if ( V_18 < 0 )
F_6 ( L_1 ,
V_4 -> V_20 ) ;
return V_18 ;
}
static void F_7 ( const struct V_21 * V_4 )
{
F_8 ( V_4 -> V_19 , V_4 -> V_20 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_22 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_22 ) ;
}
