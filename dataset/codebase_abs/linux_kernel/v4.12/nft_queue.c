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
V_8 -> V_12 , F_5 ( V_6 ) ,
V_17 ) ;
}
}
V_11 = F_6 ( V_9 ) ;
if ( V_8 -> V_13 & V_18 )
V_11 |= V_19 ;
V_4 -> V_20 . V_21 = V_11 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 , V_11 ;
V_9 = V_4 -> V_22 [ V_8 -> V_23 ] ;
V_11 = F_6 ( V_9 ) ;
if ( V_8 -> V_13 & V_18 )
V_11 |= V_19 ;
V_4 -> V_20 . V_21 = V_11 ;
}
static int F_8 ( const struct V_24 * V_25 ,
const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_28 ;
V_8 -> V_10 = F_9 ( F_10 ( V_27 [ V_29 ] ) ) ;
if ( V_27 [ V_30 ] )
V_8 -> V_12 = F_9 ( F_10 ( V_27 [ V_30 ] ) ) ;
else
V_8 -> V_12 = 1 ;
if ( V_8 -> V_12 == 0 )
return - V_31 ;
V_28 = V_8 -> V_12 - 1 + V_8 -> V_10 ;
if ( V_28 > V_32 )
return - V_33 ;
if ( V_27 [ V_34 ] ) {
V_8 -> V_13 = F_9 ( F_10 ( V_27 [ V_34 ] ) ) ;
if ( V_8 -> V_13 & ~ V_35 )
return - V_31 ;
}
return 0 ;
}
static int F_11 ( const struct V_24 * V_25 ,
const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_36 ;
V_8 -> V_23 = F_12 ( V_27 [ V_37 ] ) ;
V_36 = F_13 ( V_8 -> V_23 , sizeof( T_1 ) ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_27 [ V_34 ] ) {
V_8 -> V_13 = F_9 ( F_10 ( V_27 [ V_34 ] ) ) ;
if ( V_8 -> V_13 & ~ V_35 )
return - V_31 ;
if ( V_8 -> V_13 & V_14 )
return - V_38 ;
}
return 0 ;
}
static int F_14 ( struct V_39 * V_16 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_15 ( V_16 , V_29 , F_16 ( V_8 -> V_10 ) ) ||
F_15 ( V_16 , V_30 , F_16 ( V_8 -> V_12 ) ) ||
F_15 ( V_16 , V_34 , F_16 ( V_8 -> V_13 ) ) )
goto V_40;
return 0 ;
V_40:
return - 1 ;
}
static int
F_17 ( struct V_39 * V_16 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_18 ( V_16 , V_37 , V_8 -> V_23 ) ||
F_15 ( V_16 , V_34 , F_16 ( V_8 -> V_13 ) ) )
goto V_40;
return 0 ;
V_40:
return - 1 ;
}
static const struct V_41 *
F_19 ( const struct V_24 * V_25 ,
const struct V_26 * const V_27 [] )
{
if ( V_27 [ V_29 ] && V_27 [ V_37 ] )
return F_20 ( - V_31 ) ;
F_21 ( & V_17 ) ;
if ( V_27 [ V_29 ] )
return & V_42 ;
if ( V_27 [ V_37 ] )
return & V_43 ;
return F_20 ( - V_31 ) ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_44 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_44 ) ;
}
