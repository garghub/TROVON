static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( & V_9 ) ;
if ( F_4 ( V_10 , V_8 -> V_11 ) ) {
V_8 -> V_12 = V_8 -> V_13 ;
V_8 -> V_11 = V_10 + V_8 -> V_14 * V_15 ;
}
if ( V_8 -> V_12 >= 1 ) {
V_8 -> V_12 -- ;
F_5 ( & V_9 ) ;
return;
}
F_5 ( & V_9 ) ;
V_4 -> V_16 . V_17 = V_18 ;
}
static int F_6 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_22 [ V_23 ] == NULL ||
V_22 [ V_24 ] == NULL )
return - V_25 ;
V_8 -> V_13 = F_7 ( F_8 ( V_22 [ V_23 ] ) ) ;
V_8 -> V_14 = F_7 ( F_8 ( V_22 [ V_24 ] ) ) ;
V_8 -> V_11 = V_10 + V_8 -> V_14 * V_15 ;
V_8 -> V_12 = V_8 -> V_13 ;
return 0 ;
}
static int F_9 ( struct V_26 * V_27 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_10 ( V_27 , V_23 , F_11 ( V_8 -> V_13 ) ) )
goto V_28;
if ( F_10 ( V_27 , V_24 , F_11 ( V_8 -> V_14 ) ) )
goto V_28;
return 0 ;
V_28:
return - 1 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_29 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_29 ) ;
}
