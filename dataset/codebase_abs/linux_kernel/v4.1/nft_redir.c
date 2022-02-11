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
unsigned int V_16 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_4 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 = F_6 ( struct V_17 , V_18 . V_19 ) ;
if ( V_13 [ V_20 ] ) {
V_15 -> V_21 =
F_7 ( V_13 [ V_20 ] ) ;
V_7 = F_8 ( V_15 -> V_21 , V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_13 [ V_22 ] ) {
V_15 -> V_23 =
F_7 ( V_13 [ V_22 ] ) ;
V_7 = F_8 ( V_15 -> V_23 ,
V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
V_15 -> V_23 = V_15 -> V_21 ;
}
}
if ( V_13 [ V_24 ] ) {
V_15 -> V_25 = F_9 ( F_10 ( V_13 [ V_24 ] ) ) ;
if ( V_15 -> V_25 & ~ V_26 )
return - V_27 ;
}
return 0 ;
}
int F_11 ( struct V_28 * V_29 , const struct V_3 * V_4 )
{
const struct V_14 * V_15 = F_5 ( V_4 ) ;
if ( V_15 -> V_21 ) {
if ( F_12 ( V_29 , V_20 ,
V_15 -> V_21 ) )
goto V_30;
if ( F_12 ( V_29 , V_22 ,
V_15 -> V_23 ) )
goto V_30;
}
if ( V_15 -> V_25 != 0 &&
F_13 ( V_29 , V_24 , F_14 ( V_15 -> V_25 ) ) )
goto V_30;
return 0 ;
V_30:
return - 1 ;
}
