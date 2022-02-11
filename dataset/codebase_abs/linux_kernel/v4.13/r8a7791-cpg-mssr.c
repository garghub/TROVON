static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
T_2 V_9 ;
int error ;
error = F_2 ( & V_9 ) ;
if ( error )
return error ;
V_4 = & V_10 [ F_3 ( V_9 ) ] ;
if ( F_4 ( V_6 , L_1 ) ) {
for ( V_8 = 0 ; V_8 < F_5 ( V_11 ) ; V_8 ++ )
if ( V_11 [ V_8 ] . V_12 == V_13 ) {
V_11 [ V_8 ] . div = 5 ;
break;
}
}
return F_6 ( V_4 , 2 , V_9 ) ;
}
