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
static void F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 , V_11 ;
V_9 = V_4 -> V_23 [ V_8 -> V_24 ] ;
V_11 = F_5 ( V_9 ) ;
if ( V_8 -> V_13 & V_19 )
V_11 |= V_20 ;
V_4 -> V_21 . V_22 = V_11 ;
}
static int F_7 ( const struct V_25 * V_26 ,
const struct V_1 * V_2 ,
const struct V_27 * const V_28 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_29 ;
V_8 -> V_10 = F_8 ( F_9 ( V_28 [ V_30 ] ) ) ;
if ( V_28 [ V_31 ] )
V_8 -> V_12 = F_8 ( F_9 ( V_28 [ V_31 ] ) ) ;
else
V_8 -> V_12 = 1 ;
if ( V_8 -> V_12 == 0 )
return - V_32 ;
V_29 = V_8 -> V_12 - 1 + V_8 -> V_10 ;
if ( V_29 > V_33 )
return - V_34 ;
if ( V_28 [ V_35 ] ) {
V_8 -> V_13 = F_8 ( F_9 ( V_28 [ V_35 ] ) ) ;
if ( V_8 -> V_13 & ~ V_36 )
return - V_32 ;
}
return 0 ;
}
static int F_10 ( const struct V_25 * V_26 ,
const struct V_1 * V_2 ,
const struct V_27 * const V_28 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_37 ;
V_8 -> V_24 = F_11 ( V_28 [ V_38 ] ) ;
V_37 = F_12 ( V_8 -> V_24 , sizeof( T_1 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_28 [ V_35 ] ) {
V_8 -> V_13 = F_8 ( F_9 ( V_28 [ V_35 ] ) ) ;
if ( V_8 -> V_13 & ~ V_36 )
return - V_32 ;
if ( V_8 -> V_13 & V_14 )
return - V_39 ;
}
return 0 ;
}
static int F_13 ( struct V_40 * V_16 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_14 ( V_16 , V_30 , F_15 ( V_8 -> V_10 ) ) ||
F_14 ( V_16 , V_31 , F_15 ( V_8 -> V_12 ) ) ||
F_14 ( V_16 , V_35 , F_15 ( V_8 -> V_13 ) ) )
goto V_41;
return 0 ;
V_41:
return - 1 ;
}
static int
F_16 ( struct V_40 * V_16 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_17 ( V_16 , V_38 , V_8 -> V_24 ) ||
F_14 ( V_16 , V_35 , F_15 ( V_8 -> V_13 ) ) )
goto V_41;
return 0 ;
V_41:
return - 1 ;
}
static const struct V_42 *
F_18 ( const struct V_25 * V_26 ,
const struct V_27 * const V_28 [] )
{
if ( V_28 [ V_30 ] && V_28 [ V_38 ] )
return F_19 ( - V_32 ) ;
F_20 ( & V_18 ) ;
if ( V_28 [ V_30 ] )
return & V_43 ;
if ( V_28 [ V_38 ] )
return & V_44 ;
return F_19 ( - V_32 ) ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_45 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_45 ) ;
}
