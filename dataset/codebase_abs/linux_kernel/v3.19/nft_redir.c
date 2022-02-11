int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_3 ( V_2 -> V_8 ,
( 1 << V_10 ) |
( 1 << V_11 ) ) ;
}
int F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_12 * const V_13 [] )
{
struct V_14 * V_15 = F_5 ( V_4 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_4 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_13 [ V_16 ] ) {
V_15 -> V_17 =
F_6 ( F_7 ( V_13 [ V_16 ] ) ) ;
V_7 = F_8 ( V_15 -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_13 [ V_18 ] ) {
V_15 -> V_19 =
F_6 ( F_7 ( V_13 [ V_18 ] ) ) ;
V_7 = F_8 ( V_15 -> V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
V_15 -> V_19 = V_15 -> V_17 ;
}
}
if ( V_13 [ V_20 ] ) {
V_15 -> V_21 = F_6 ( F_7 ( V_13 [ V_20 ] ) ) ;
if ( V_15 -> V_21 & ~ V_22 )
return - V_23 ;
}
return 0 ;
}
int F_9 ( struct V_24 * V_25 , const struct V_3 * V_4 )
{
const struct V_14 * V_15 = F_5 ( V_4 ) ;
if ( V_15 -> V_17 ) {
if ( F_10 ( V_25 , V_16 ,
F_11 ( V_15 -> V_17 ) ) )
goto V_26;
if ( F_10 ( V_25 , V_18 ,
F_11 ( V_15 -> V_19 ) ) )
goto V_26;
}
if ( V_15 -> V_21 != 0 &&
F_10 ( V_25 , V_20 , F_11 ( V_15 -> V_21 ) ) )
goto V_26;
return 0 ;
V_26:
return - 1 ;
}
