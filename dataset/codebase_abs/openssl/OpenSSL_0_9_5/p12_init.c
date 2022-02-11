T_1 * F_1 ( int V_1 )
{
T_1 * V_2 ;
if ( ! ( V_2 = F_2 () ) ) {
F_3 ( V_3 , V_4 ) ;
return NULL ;
}
if ( ! ( V_2 -> V_5 = F_4 () ) ) {
F_3 ( V_3 , V_4 ) ;
return NULL ;
}
F_5 ( V_2 -> V_5 , 3 ) ;
if ( ! ( V_2 -> V_6 = F_6 () ) ) {
F_3 ( V_3 , V_4 ) ;
return NULL ;
}
V_2 -> V_6 -> type = F_7 ( V_1 ) ;
switch ( V_1 ) {
case V_7 :
if ( ! ( V_2 -> V_6 -> V_8 . V_9 =
F_8 () ) ) {
F_3 ( V_3 , V_4 ) ;
return NULL ;
}
break;
default:
F_3 ( V_3 , V_10 ) ;
F_9 ( V_2 ) ;
return NULL ;
break;
}
return V_2 ;
}
