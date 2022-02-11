int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_3 ( V_2 -> V_8 ,
( 1 << V_10 ) ) ;
}
int F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_11 * const V_12 [] )
{
T_1 V_13 = F_5 ( struct V_14 , V_15 . V_16 ) ;
struct V_17 * V_18 = F_6 ( V_4 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_4 , NULL ) ;
if ( V_7 )
return V_7 ;
if ( V_12 [ V_19 ] ) {
V_18 -> V_20 = F_7 ( F_8 ( V_12 [ V_19 ] ) ) ;
if ( V_18 -> V_20 & ~ V_21 )
return - V_22 ;
}
if ( V_12 [ V_23 ] ) {
V_18 -> V_24 =
F_9 ( V_12 [ V_23 ] ) ;
V_7 = F_10 ( V_18 -> V_24 , V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_12 [ V_25 ] ) {
V_18 -> V_26 =
F_9 ( V_12 [ V_25 ] ) ;
V_7 = F_10 ( V_18 -> V_26 ,
V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
V_18 -> V_26 = V_18 -> V_24 ;
}
}
return 0 ;
}
int F_11 ( struct V_27 * V_28 , const struct V_3 * V_4 )
{
const struct V_17 * V_18 = F_6 ( V_4 ) ;
if ( V_18 -> V_20 != 0 &&
F_12 ( V_28 , V_19 , F_13 ( V_18 -> V_20 ) ) )
goto V_29;
if ( V_18 -> V_24 ) {
if ( F_14 ( V_28 , V_23 ,
V_18 -> V_24 ) ||
F_14 ( V_28 , V_25 ,
V_18 -> V_26 ) )
goto V_29;
}
return 0 ;
V_29:
return - 1 ;
}
