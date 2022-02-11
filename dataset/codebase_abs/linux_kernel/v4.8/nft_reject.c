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
int V_15 ;
V_15 = F_1 ( V_2 , V_4 , NULL ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_12 [ V_16 ] == NULL )
return - V_17 ;
V_14 -> type = F_5 ( F_6 ( V_12 [ V_16 ] ) ) ;
switch ( V_14 -> type ) {
case V_18 :
if ( V_12 [ V_19 ] == NULL )
return - V_17 ;
V_14 -> V_20 = F_7 ( V_12 [ V_19 ] ) ;
case V_21 :
break;
default:
return - V_17 ;
}
return 0 ;
}
int F_8 ( struct V_22 * V_23 , const struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_4 ( V_4 ) ;
if ( F_9 ( V_23 , V_16 , F_10 ( V_14 -> type ) ) )
goto V_24;
switch ( V_14 -> type ) {
case V_18 :
if ( F_11 ( V_23 , V_19 , V_14 -> V_20 ) )
goto V_24;
break;
default:
break;
}
return 0 ;
V_24:
return - 1 ;
}
int F_12 ( T_1 V_25 )
{
F_13 ( V_25 > V_26 ) ;
return V_27 [ V_25 ] ;
}
int F_14 ( T_1 V_25 )
{
F_13 ( V_25 > V_26 ) ;
return V_28 [ V_25 ] ;
}
