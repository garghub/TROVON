static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = V_4 -> V_10 [ V_8 -> V_11 ] ;
F_3 ( V_6 , V_9 ) ;
}
static int F_4 ( const struct V_12 * V_13 ,
const struct V_1 * V_2 ,
const struct V_14 * const V_15 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_15 [ V_16 ] == NULL )
return - V_17 ;
V_8 -> V_11 = F_5 ( V_15 [ V_16 ] ) ;
return F_6 ( V_8 -> V_11 , sizeof( int ) ) ;
}
static int F_7 ( struct V_18 * V_19 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_8 ( V_19 , V_16 , V_8 -> V_11 ) )
goto V_20;
return 0 ;
V_20:
return - 1 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_21 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_21 ) ;
}
