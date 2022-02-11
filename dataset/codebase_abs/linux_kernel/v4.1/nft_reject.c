int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * const V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_6 [ V_9 ] == NULL )
return - V_10 ;
V_8 -> type = F_3 ( F_4 ( V_6 [ V_9 ] ) ) ;
switch ( V_8 -> type ) {
case V_11 :
if ( V_6 [ V_12 ] == NULL )
return - V_10 ;
V_8 -> V_13 = F_5 ( V_6 [ V_12 ] ) ;
case V_14 :
break;
default:
return - V_10 ;
}
return 0 ;
}
int F_6 ( struct V_15 * V_16 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_7 ( V_16 , V_9 , F_8 ( V_8 -> type ) ) )
goto V_17;
switch ( V_8 -> type ) {
case V_11 :
if ( F_9 ( V_16 , V_12 , V_8 -> V_13 ) )
goto V_17;
break;
default:
break;
}
return 0 ;
V_17:
return - 1 ;
}
int F_10 ( T_1 V_18 )
{
F_11 ( V_18 > V_19 ) ;
return V_20 [ V_18 ] ;
}
int F_12 ( T_1 V_18 )
{
F_11 ( V_18 > V_19 ) ;
return V_21 [ V_18 ] ;
}
