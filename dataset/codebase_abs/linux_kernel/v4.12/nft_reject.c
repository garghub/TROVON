int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * * V_6 )
{
return F_2 ( V_2 -> V_7 ,
( 1 << V_8 ) |
( 1 << V_9 ) |
( 1 << V_10 ) ) ;
}
int F_3 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_11 * const V_12 [] )
{
struct V_13 * V_14 = F_4 ( V_4 ) ;
if ( V_12 [ V_15 ] == NULL )
return - V_16 ;
V_14 -> type = F_5 ( F_6 ( V_12 [ V_15 ] ) ) ;
switch ( V_14 -> type ) {
case V_17 :
if ( V_12 [ V_18 ] == NULL )
return - V_16 ;
V_14 -> V_19 = F_7 ( V_12 [ V_18 ] ) ;
case V_20 :
break;
default:
return - V_16 ;
}
return 0 ;
}
int F_8 ( struct V_21 * V_22 , const struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_4 ( V_4 ) ;
if ( F_9 ( V_22 , V_15 , F_10 ( V_14 -> type ) ) )
goto V_23;
switch ( V_14 -> type ) {
case V_17 :
if ( F_11 ( V_22 , V_18 , V_14 -> V_19 ) )
goto V_23;
break;
default:
break;
}
return 0 ;
V_23:
return - 1 ;
}
int F_12 ( T_1 V_24 )
{
F_13 ( V_24 > V_25 ) ;
return V_26 [ V_24 ] ;
}
int F_14 ( T_1 V_24 )
{
F_13 ( V_24 > V_25 ) ;
return V_27 [ V_24 ] ;
}
