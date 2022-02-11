static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 = {
. V_11 = ( V_12 V_13 ) V_4 -> V_14 [ V_8 -> V_15 ] ,
} ;
int V_16 = V_8 -> V_17 ? V_4 -> V_14 [ V_8 -> V_17 ] : - 1 ;
F_3 ( F_4 ( V_6 ) , V_6 -> V_18 , F_5 ( V_6 ) , & V_10 , V_16 ) ;
}
static int F_6 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_23 ;
if ( V_22 [ V_24 ] == NULL )
return - V_25 ;
V_8 -> V_15 = F_7 ( V_22 [ V_24 ] ) ;
V_23 = F_8 ( V_8 -> V_15 , sizeof( struct V_9 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_22 [ V_26 ] != NULL ) {
V_8 -> V_17 = F_7 ( V_22 [ V_26 ] ) ;
return F_8 ( V_8 -> V_17 , sizeof( int ) ) ;
}
return 0 ;
}
static int F_9 ( struct V_27 * V_18 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_10 ( V_18 , V_24 , V_8 -> V_15 ) )
goto V_28;
if ( V_8 -> V_17 &&
F_10 ( V_18 , V_26 , V_8 -> V_17 ) )
goto V_28;
return 0 ;
V_28:
return - 1 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_29 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_29 ) ;
}
