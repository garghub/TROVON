static T_1 *
F_1 ( struct V_1 * V_2 , T_1 * * V_3 ,
T_1 * V_4 , char * V_5 )
{
const struct V_6 * V_7 ;
if ( F_2 ( & V_7 , V_5 , & V_2 -> V_8 ) ) {
F_3 ( L_1 , V_5 ) ;
goto error;
}
* V_3 = ( T_1 * ) V_7 -> V_9 ;
* V_4 = V_7 -> V_10 / sizeof( T_1 ) ;
V_11 = V_7 ;
return * V_3 ;
error:
return NULL ;
}
T_1 *
F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 == V_13 ) {
if ( V_14 == 0 )
F_1 ( V_2 , & V_15 ,
& V_14 , V_16 ) ;
return V_15 ;
} else if ( F_5 ( V_2 -> V_12 ) ) {
if ( V_17 == 0 )
F_1 ( V_2 , & V_18 ,
& V_17 , V_19 ) ;
return V_18 ;
}
return NULL ;
}
T_1 *
F_6 ( enum V_20 V_21 , T_1 V_22 )
{
switch ( V_21 ) {
case V_23 :
return ( V_18 + V_22 ) ;
break;
case V_24 :
return ( V_15 + V_22 ) ;
break;
default:
return NULL ;
}
}
T_1
F_7 ( enum V_20 V_21 )
{
switch ( V_21 ) {
case V_23 :
return V_17 ;
break;
case V_24 :
return V_14 ;
break;
default:
return 0 ;
}
}
