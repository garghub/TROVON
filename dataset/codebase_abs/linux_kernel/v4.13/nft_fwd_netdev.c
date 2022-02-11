static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = V_4 -> V_10 [ V_8 -> V_11 ] ;
F_3 ( V_6 , V_9 ) ;
V_4 -> V_12 . V_13 = V_14 ;
}
static int F_4 ( const struct V_15 * V_16 ,
const struct V_1 * V_2 ,
const struct V_17 * const V_18 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_18 [ V_19 ] == NULL )
return - V_20 ;
V_8 -> V_11 = F_5 ( V_18 [ V_19 ] ) ;
return F_6 ( V_8 -> V_11 , sizeof( int ) ) ;
}
static int F_7 ( struct V_21 * V_22 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_8 ( V_22 , V_19 , V_8 -> V_11 ) )
goto V_23;
return 0 ;
V_23:
return - 1 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_24 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_24 ) ;
}
