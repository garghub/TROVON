static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
unsigned int V_10 ;
struct V_11 * V_12 = F_2 ( V_2 , & V_9 ) ;
if ( ! V_12 )
V_10 = V_13 ;
else {
if ( F_3 ( V_12 ) )
V_10 = V_14 ;
else
V_10 = F_4 ( V_9 ) ;
}
return ( V_6 -> V_15 & V_10 ) ;
}
static int F_5 ( const struct V_16 * V_4 )
{
int V_17 ;
V_17 = F_6 ( V_4 -> V_18 , V_4 -> V_19 ) ;
if ( V_17 < 0 )
F_7 ( L_1 ,
V_4 -> V_19 ) ;
return V_17 ;
}
static void F_8 ( const struct V_20 * V_4 )
{
F_9 ( V_4 -> V_18 , V_4 -> V_19 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_21 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_21 ) ;
}
