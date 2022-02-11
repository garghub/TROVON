static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 = {
. V_2 = V_2 ,
. V_3 = V_3 ,
. V_6 = V_6 } ;
const T_1 V_7 [] = { 0x01 , 0x00 , 0x06 , 0x00 } , V_8 = F_2 ( V_7 ) ;
T_1 V_9 [ V_8 ] ;
if ( ! F_3 ( & V_5 , 0x00 , V_9 , V_8 ) || memcmp ( V_7 , V_9 , V_8 ) )
return;
F_4 ( V_10 L_1 , V_6 , V_3 ) ;
F_5 ( & V_5 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_11 ;
for ( V_11 = 0x38 ; V_11 <= 0x3F ; V_11 ++ )
F_1 ( V_2 , V_11 ) ;
}
