static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( & V_10 ) ;
if ( F_4 ( V_11 , V_9 -> V_12 ) ) {
V_9 -> V_13 = V_9 -> V_14 ;
V_9 -> V_12 = V_11 + V_9 -> V_15 * V_16 ;
}
if ( V_9 -> V_13 >= 1 ) {
V_9 -> V_13 -- ;
F_5 ( & V_10 ) ;
return;
}
F_5 ( & V_10 ) ;
V_4 [ V_17 ] . V_18 = V_19 ;
}
static int F_6 ( const struct V_20 * V_21 ,
const struct V_1 * V_2 ,
const struct V_22 * const V_23 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_23 [ V_24 ] == NULL ||
V_23 [ V_25 ] == NULL )
return - V_26 ;
V_9 -> V_14 = F_7 ( F_8 ( V_23 [ V_24 ] ) ) ;
V_9 -> V_15 = F_7 ( F_8 ( V_23 [ V_25 ] ) ) ;
V_9 -> V_12 = V_11 + V_9 -> V_15 * V_16 ;
V_9 -> V_13 = V_9 -> V_14 ;
return 0 ;
}
static int F_9 ( struct V_27 * V_28 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_10 ( V_28 , V_24 , F_11 ( V_9 -> V_14 ) ) )
goto V_29;
if ( F_10 ( V_28 , V_25 , F_11 ( V_9 -> V_15 ) ) )
goto V_29;
return 0 ;
V_29:
return - 1 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_30 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_30 ) ;
}
