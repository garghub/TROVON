T_1 *
F_1 ( const T_2 * V_1 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) F_2 ( 14 ) ;
F_3 ( V_1 , V_2 , 14 ) ;
return V_2 ;
}
void
F_3 ( const T_2 * V_1 , T_1 * V_3 , int V_4 )
{
const T_3 * V_5 ;
struct V_6 V_6 ;
switch ( V_1 -> V_7 ) {
case 1 :
V_5 = ( T_3 * ) V_1 -> V_8 ;
F_4 ( V_3 , V_4 , L_1 , V_5 [ 0 ] ) ;
break;
case 2 :
V_5 = ( T_3 * ) V_1 -> V_8 ;
F_4 ( V_3 , V_4 , L_1 , F_5 ( & V_5 [ 0 ] ) ) ;
break;
case V_9 :
memcpy ( & V_6 , V_1 -> V_8 , V_9 ) ;
F_4 ( V_3 , V_4 , L_2 , V_6 . V_10 ,
V_6 . V_11 ) ;
break;
}
}
