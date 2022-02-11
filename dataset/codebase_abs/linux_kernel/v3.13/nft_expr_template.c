static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
}
static int F_3 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
const struct V_12 * const V_13 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return 0 ;
}
static void F_4 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
}
static int F_5 ( struct V_14 * V_15 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
F_6 ( V_15 , V_16 , V_9 -> V_17 ) ;
return 0 ;
V_18:
return - 1 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_19 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_19 ) ;
}
