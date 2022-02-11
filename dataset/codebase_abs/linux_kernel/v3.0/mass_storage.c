static int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return 0 ;
}
static int T_1 F_3 ( struct V_3 * V_4 )
{
static const struct V_5 V_6 = {
. V_7 = F_1 ,
} ;
static struct V_1 V_2 ;
struct V_1 * V_8 ;
struct V_9 V_10 ;
int V_11 ;
if ( F_4 ( V_4 -> V_12 -> V_13 ) ) {
V_4 -> V_14 = V_15 ;
V_4 -> V_16 |= V_17 ;
}
F_5 ( & V_10 , & V_18 ) ;
V_10 . V_6 = & V_6 ;
V_8 = F_6 ( & V_2 , V_4 -> V_12 , & V_10 ) ;
if ( F_7 ( V_8 ) )
return F_8 ( V_8 ) ;
V_11 = F_9 ( V_4 -> V_12 , V_4 , & V_2 ) ;
F_10 ( & V_2 ) ;
return V_11 ;
}
static int T_1 F_11 ( struct V_19 * V_12 )
{
int V_20 ;
V_20 = F_12 ( V_12 , & V_21 , F_3 ) ;
if ( V_20 < 0 )
return V_20 ;
F_13 ( & V_12 -> V_13 -> V_22 ,
V_23 L_1 V_24 L_2 ) ;
F_14 ( 0 , & V_25 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_26 , F_11 ) ;
}
static void F_2 ( void )
{
if ( F_17 ( 0 , & V_25 ) )
F_18 ( & V_26 ) ;
}
