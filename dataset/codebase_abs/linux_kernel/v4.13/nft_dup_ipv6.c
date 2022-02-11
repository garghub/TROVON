static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = (struct V_9 * ) & V_4 -> V_11 [ V_8 -> V_12 ] ;
int V_13 = V_8 -> V_14 ? V_4 -> V_11 [ V_8 -> V_14 ] : - 1 ;
F_3 ( F_4 ( V_6 ) , V_6 -> V_15 , F_5 ( V_6 ) , V_10 , V_13 ) ;
}
static int F_6 ( const struct V_16 * V_17 ,
const struct V_1 * V_2 ,
const struct V_18 * const V_19 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_20 ;
if ( V_19 [ V_21 ] == NULL )
return - V_22 ;
V_8 -> V_12 = F_7 ( V_19 [ V_21 ] ) ;
V_20 = F_8 ( V_8 -> V_12 , sizeof( struct V_9 ) ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_19 [ V_23 ] != NULL ) {
V_8 -> V_14 = F_7 ( V_19 [ V_23 ] ) ;
return F_8 ( V_8 -> V_14 , sizeof( int ) ) ;
}
return 0 ;
}
static int F_9 ( struct V_24 * V_15 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_10 ( V_15 , V_21 , V_8 -> V_12 ) )
goto V_25;
if ( V_8 -> V_14 &&
F_10 ( V_15 , V_23 , V_8 -> V_14 ) )
goto V_25;
return 0 ;
V_25:
return - 1 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_26 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_26 ) ;
}
