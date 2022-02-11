static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = (struct V_9 * ) & V_4 -> V_11 [ V_8 -> V_12 ] ;
int V_13 = V_4 -> V_11 [ V_8 -> V_14 ] ;
F_3 ( V_6 -> V_15 , V_6 -> V_16 , V_6 -> V_17 , V_10 , V_13 ) ;
}
static int F_4 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const struct V_20 * const V_21 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_22 ;
if ( V_21 [ V_23 ] == NULL )
return - V_24 ;
V_8 -> V_12 = F_5 ( V_21 [ V_23 ] ) ;
V_22 = F_6 ( V_8 -> V_12 , sizeof( struct V_9 ) ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_21 [ V_25 ] != NULL ) {
V_8 -> V_14 = F_5 ( V_21 [ V_25 ] ) ;
return F_6 ( V_8 -> V_14 , sizeof( int ) ) ;
}
return 0 ;
}
static int F_7 ( struct V_26 * V_16 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_8 ( V_16 , V_23 , V_8 -> V_12 ) ||
F_8 ( V_16 , V_25 , V_8 -> V_14 ) )
goto V_27;
return 0 ;
V_27:
return - 1 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_28 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_28 ) ;
}
