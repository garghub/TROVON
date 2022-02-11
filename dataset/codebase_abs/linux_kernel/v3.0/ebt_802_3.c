static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = V_8 ( V_2 ) ;
T_1 type = V_9 -> V_10 . V_11 . V_12 & V_13 ? V_9 -> V_10 . V_11 . type : V_9 -> V_10 . V_14 . type ;
if ( V_6 -> V_15 & V_16 ) {
if ( F_2 ( V_6 -> V_17 != V_9 -> V_10 . V_11 . V_18 , V_16 ) )
return false ;
if ( F_2 ( V_6 -> V_17 != V_9 -> V_10 . V_11 . V_19 , V_16 ) )
return false ;
}
if ( V_6 -> V_15 & V_20 ) {
if ( ! ( V_9 -> V_10 . V_11 . V_19 == V_21 && V_9 -> V_10 . V_11 . V_18 == V_21 ) )
return false ;
if ( F_2 ( V_6 -> type != type , V_20 ) )
return false ;
}
return true ;
}
static int F_3 ( const struct V_22 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_15 & ~ V_23 || V_6 -> V_24 & ~ V_23 )
return - V_25 ;
return 0 ;
}
static int T_2 F_4 ( void )
{
return F_5 ( & V_26 ) ;
}
static void T_3 F_6 ( void )
{
F_7 ( & V_26 ) ;
}
