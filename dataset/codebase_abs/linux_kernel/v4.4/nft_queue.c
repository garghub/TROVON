static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = V_8 -> V_10 ;
T_1 V_11 ;
if ( V_8 -> V_12 > 1 ) {
if ( V_8 -> V_13 & V_14 ) {
int V_15 = F_3 () ;
V_9 = V_8 -> V_10 + V_15 % V_8 -> V_12 ;
} else {
V_9 = F_4 ( V_6 -> V_16 , V_9 ,
V_8 -> V_12 , V_6 -> V_17 ,
V_18 ) ;
}
}
V_11 = F_5 ( V_9 ) ;
if ( V_8 -> V_13 & V_19 )
V_11 |= V_20 ;
V_4 -> V_21 . V_22 = V_11 ;
}
static int F_6 ( const struct V_23 * V_24 ,
const struct V_1 * V_2 ,
const struct V_25 * const V_26 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_26 [ V_27 ] == NULL )
return - V_28 ;
F_7 ( & V_18 ) ;
V_8 -> V_10 = F_8 ( F_9 ( V_26 [ V_27 ] ) ) ;
if ( V_26 [ V_29 ] != NULL )
V_8 -> V_12 = F_8 ( F_9 ( V_26 [ V_29 ] ) ) ;
if ( V_26 [ V_30 ] != NULL ) {
V_8 -> V_13 = F_8 ( F_9 ( V_26 [ V_30 ] ) ) ;
if ( V_8 -> V_13 & ~ V_31 )
return - V_28 ;
}
return 0 ;
}
static int F_10 ( struct V_32 * V_16 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_16 , V_27 , F_12 ( V_8 -> V_10 ) ) ||
F_11 ( V_16 , V_29 , F_12 ( V_8 -> V_12 ) ) ||
F_11 ( V_16 , V_30 , F_12 ( V_8 -> V_13 ) ) )
goto V_33;
return 0 ;
V_33:
return - 1 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_34 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_34 ) ;
}
