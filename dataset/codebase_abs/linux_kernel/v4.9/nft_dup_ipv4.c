static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 = {
. V_11 = ( V_12 V_13 ) V_4 -> V_14 [ V_8 -> V_15 ] ,
} ;
int V_16 = V_8 -> V_17 ? V_4 -> V_14 [ V_8 -> V_17 ] : - 1 ;
F_3 ( V_6 -> V_18 , V_6 -> V_19 , V_6 -> V_20 , & V_10 , V_16 ) ;
}
static int F_4 ( const struct V_21 * V_22 ,
const struct V_1 * V_2 ,
const struct V_23 * const V_24 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_25 ;
if ( V_24 [ V_26 ] == NULL )
return - V_27 ;
V_8 -> V_15 = F_5 ( V_24 [ V_26 ] ) ;
V_25 = F_6 ( V_8 -> V_15 , sizeof( struct V_9 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_24 [ V_28 ] != NULL ) {
V_8 -> V_17 = F_5 ( V_24 [ V_28 ] ) ;
return F_6 ( V_8 -> V_17 , sizeof( int ) ) ;
}
return 0 ;
}
static int F_7 ( struct V_29 * V_19 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_8 ( V_19 , V_26 , V_8 -> V_15 ) )
goto V_30;
if ( V_8 -> V_17 &&
F_8 ( V_19 , V_28 , V_8 -> V_17 ) )
goto V_30;
return 0 ;
V_30:
return - 1 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_31 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_31 ) ;
}
