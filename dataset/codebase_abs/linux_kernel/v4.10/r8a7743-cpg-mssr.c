static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
int error ;
error = F_2 ( & V_5 ) ;
if ( error )
return error ;
V_4 = & V_6 [ F_3 ( V_5 ) ] ;
return F_4 ( V_4 , 2 , V_5 ) ;
}
