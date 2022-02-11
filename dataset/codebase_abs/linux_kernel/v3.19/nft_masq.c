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
struct V_13 * V_14 = F_5 ( V_4 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_4 , NULL ) ;
if ( V_7 )
return V_7 ;
if ( V_12 [ V_15 ] == NULL )
return 0 ;
V_14 -> V_16 = F_6 ( F_7 ( V_12 [ V_15 ] ) ) ;
if ( V_14 -> V_16 & ~ V_17 )
return - V_18 ;
return 0 ;
}
int F_8 ( struct V_19 * V_20 , const struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_5 ( V_4 ) ;
if ( V_14 -> V_16 == 0 )
return 0 ;
if ( F_9 ( V_20 , V_15 , F_10 ( V_14 -> V_16 ) ) )
goto V_21;
return 0 ;
V_21:
return - 1 ;
}
