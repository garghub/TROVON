static void F_1 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div ;
if ( * V_1 > V_2 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div > 8 )
div = 8 ;
* V_1 = V_2 / div ;
if ( V_5 == NULL )
return;
* V_5 = div - 1 ;
}
static void T_3 F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 , & V_11 ,
& V_12 ) ;
F_5 ( V_10 ) ;
F_6 ( V_10 ) ;
}
