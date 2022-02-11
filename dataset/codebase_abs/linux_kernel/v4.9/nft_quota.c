static inline bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_4 -> V_5 -> V_6 , & V_2 -> V_7 ) < 0 ;
}
static void F_3 ( const struct V_8 * V_9 ,
struct V_10 * V_11 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( F_1 ( V_2 , V_4 ) ^ V_2 -> V_12 )
V_11 -> V_13 . V_14 = V_15 ;
}
static int F_5 ( const struct V_16 * V_17 ,
const struct V_8 * V_9 ,
const struct V_18 * const V_19 [] )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
T_1 V_20 = 0 ;
T_2 V_21 ;
if ( ! V_19 [ V_22 ] )
return - V_23 ;
V_21 = F_6 ( F_7 ( V_19 [ V_22 ] ) ) ;
if ( V_21 > V_24 )
return - V_25 ;
if ( V_19 [ V_26 ] ) {
V_20 = F_8 ( F_9 ( V_19 [ V_26 ] ) ) ;
if ( V_20 & ~ V_27 )
return - V_23 ;
}
V_2 -> V_21 = V_21 ;
V_2 -> V_12 = ( V_20 & V_27 ) ? true : false ;
F_10 ( & V_2 -> V_7 , V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_5 , const struct V_8 * V_9 )
{
const struct V_1 * V_2 = F_4 ( V_9 ) ;
T_1 V_20 = V_2 -> V_12 ? V_27 : 0 ;
if ( F_12 ( V_5 , V_22 , F_13 ( V_2 -> V_21 ) ,
V_29 ) ||
F_14 ( V_5 , V_26 , F_15 ( V_20 ) ) )
goto V_30;
return 0 ;
V_30:
return - 1 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_31 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_31 ) ;
}
