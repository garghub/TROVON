static T_1 *
F_1 ( struct V_1 * V_2 , T_1 * * V_3 ,
T_1 * V_4 , char * V_5 )
{
const struct V_6 * V_7 ;
T_1 V_8 ;
if ( F_2 ( & V_7 , V_5 , & V_2 -> V_9 ) ) {
F_3 ( & V_2 -> V_9 , L_1 , V_5 ) ;
goto error;
}
* V_3 = ( T_1 * ) V_7 -> V_10 ;
* V_4 = V_7 -> V_11 / sizeof( T_1 ) ;
V_12 = V_7 ;
for ( V_8 = 0 ; V_8 < * V_4 ; V_8 ++ )
F_4 ( * V_3 + V_8 ) ;
return * V_3 ;
error:
return NULL ;
}
T_1 *
F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == V_14 ) {
if ( V_15 == 0 )
F_1 ( V_2 , & V_16 ,
& V_15 , V_17 ) ;
return V_16 ;
} else if ( F_6 ( V_2 -> V_13 ) ) {
if ( V_18 == 0 )
F_1 ( V_2 , & V_19 ,
& V_18 , V_20 ) ;
return V_19 ;
}
return NULL ;
}
T_1 *
F_7 ( enum V_21 V_22 , T_1 V_23 )
{
switch ( V_22 ) {
case V_24 :
return ( V_19 + V_23 ) ;
case V_25 :
return ( V_16 + V_23 ) ;
default:
return NULL ;
}
}
T_1
F_8 ( enum V_21 V_22 )
{
switch ( V_22 ) {
case V_24 :
return V_18 ;
case V_25 :
return V_15 ;
default:
return 0 ;
}
}
