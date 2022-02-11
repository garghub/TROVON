int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * const V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_9 ;
V_9 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_6 [ V_12 ] == NULL )
return 0 ;
V_8 -> V_13 = F_4 ( F_5 ( V_6 [ V_12 ] ) ) ;
if ( V_8 -> V_13 & ~ V_14 )
return - V_15 ;
return 0 ;
}
int F_6 ( struct V_16 * V_17 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_13 == 0 )
return 0 ;
if ( F_7 ( V_17 , V_12 , F_8 ( V_8 -> V_13 ) ) )
goto V_18;
return 0 ;
V_18:
return - 1 ;
}
int F_9 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_19 * * V_20 )
{
return F_3 ( V_2 -> V_10 , V_11 ) ;
}
