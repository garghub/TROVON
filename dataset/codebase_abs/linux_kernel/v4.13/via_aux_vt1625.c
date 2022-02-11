static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 = {
. V_2 = V_2 ,
. V_3 = V_3 ,
. V_6 = V_6 } ;
T_1 V_7 ;
if ( ! F_2 ( & V_5 , 0x1B , & V_7 , 1 ) || V_7 != 0x50 )
return;
F_3 ( V_8 L_1 , V_6 , V_3 ) ;
F_4 ( & V_5 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x20 ) ;
F_1 ( V_2 , 0x21 ) ;
}
