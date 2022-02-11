static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const T_2 * V_3 ;
int V_4 , V_5 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 )
return - V_6 ;
V_3 = F_3 ( V_2 , L_2 , & V_4 ) ;
if ( ! V_3 )
return - V_6 ;
if ( V_4 % 4 || V_4 > ( 4 * 4 ) )
return - V_6 ;
for ( V_5 = 0 ; V_5 < ( V_4 / 4 ) ; V_5 ++ )
F_4 ( V_7 + V_5 , V_3 [ V_5 ] ) ;
V_8 = true ;
return 0 ;
}
