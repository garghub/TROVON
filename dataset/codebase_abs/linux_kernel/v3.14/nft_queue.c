static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 = V_9 -> V_11 ;
T_1 V_12 ;
if ( V_9 -> V_13 > 1 ) {
if ( V_9 -> V_14 & V_15 ) {
int V_16 = F_3 () ;
V_10 = V_9 -> V_11 + V_16 % V_9 -> V_13 ;
} else {
V_10 = F_4 ( V_7 -> V_17 , V_10 ,
V_9 -> V_13 , V_7 -> V_18 -> V_19 ,
V_20 ) ;
}
}
V_12 = F_5 ( V_10 ) ;
if ( V_9 -> V_14 & V_21 )
V_12 |= V_22 ;
V_4 [ V_23 ] . V_24 = V_12 ;
}
static int F_6 ( const struct V_25 * V_26 ,
const struct V_1 * V_2 ,
const struct V_27 * const V_28 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_28 [ V_29 ] == NULL )
return - V_30 ;
F_7 ( & V_20 ) ;
V_9 -> V_11 = F_8 ( F_9 ( V_28 [ V_29 ] ) ) ;
if ( V_28 [ V_31 ] != NULL )
V_9 -> V_13 = F_8 ( F_9 ( V_28 [ V_31 ] ) ) ;
if ( V_28 [ V_32 ] != NULL ) {
V_9 -> V_14 = F_8 ( F_9 ( V_28 [ V_32 ] ) ) ;
if ( V_9 -> V_14 & ~ V_33 )
return - V_30 ;
}
return 0 ;
}
static int F_10 ( struct V_34 * V_17 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_11 ( V_17 , V_29 , F_12 ( V_9 -> V_11 ) ) ||
F_11 ( V_17 , V_31 , F_12 ( V_9 -> V_13 ) ) ||
F_11 ( V_17 , V_32 , F_12 ( V_9 -> V_14 ) ) )
goto V_35;
return 0 ;
V_35:
return - 1 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_36 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_36 ) ;
}
