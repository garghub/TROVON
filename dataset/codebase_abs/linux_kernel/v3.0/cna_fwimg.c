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
if ( V_12 == 0 )
F_1 ( V_2 , & V_13 ,
& V_12 , V_14 ) ;
return V_13 ;
}
T_1 *
F_5 ( int type , T_1 V_15 )
{
return ( T_1 * ) ( V_13 + V_15 ) ;
}
T_1
F_6 ( int type )
{
return V_12 ;
}
