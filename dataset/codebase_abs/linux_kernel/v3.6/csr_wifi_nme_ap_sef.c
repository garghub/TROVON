void F_1 ( void * V_1 , T_1 * V_2 )
{
switch( V_2 -> type ) {
case V_3 :
F_2 ( V_1 , V_2 ) ;
break;
case V_4 :
F_3 ( V_1 , V_2 ) ;
break;
case V_5 :
F_4 ( V_1 , V_2 ) ;
break;
default:
F_5 ( V_1 , L_1 , V_2 -> type ) ;
break;
}
}
