T_1 * F_1 ( int V_1 )
{
T_1 * V_2 ;
if ( ! ( V_2 = F_2 () ) ) {
F_3 ( V_3 , V_4 ) ;
return NULL ;
}
F_4 ( V_2 -> V_5 , 3 ) ;
V_2 -> V_6 -> type = F_5 ( V_1 ) ;
switch ( V_1 ) {
case V_7 :
if ( ! ( V_2 -> V_6 -> V_8 . V_9 =
F_6 () ) ) {
F_3 ( V_3 , V_4 ) ;
goto V_10;
}
break;
default:
F_3 ( V_3 ,
V_11 ) ;
goto V_10;
}
return V_2 ;
V_10:
if ( V_2 != NULL ) F_7 ( V_2 ) ;
return NULL ;
}
