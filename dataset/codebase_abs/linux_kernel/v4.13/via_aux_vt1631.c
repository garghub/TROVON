void F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
. V_2 = V_2 ,
. V_5 = 0x38 ,
. V_6 = V_6 } ;
const T_1 V_7 [] = { 0x06 , 0x11 , 0x91 , 0x31 } , V_8 = F_2 ( V_7 ) ;
T_1 V_9 [ V_8 ] ;
if ( ! F_3 ( & V_4 , 0x00 , V_9 , V_8 ) || memcmp ( V_7 , V_9 , V_8 ) )
return;
F_4 ( V_10 L_1 , V_6 ) ;
F_5 ( & V_4 ) ;
}
