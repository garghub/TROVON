int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
int V_4 , V_5 ;
V_4 = F_2 ( V_2 , L_1 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_5 = 0 ; V_5 < F_3 ( V_6 ) ; V_5 ++ )
if ( ! strcasecmp ( V_3 , V_6 [ V_5 ] ) )
return V_5 ;
return - V_7 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_8 ;
if ( F_5 ( V_2 , L_2 , & V_8 ) )
return 8 ;
switch( V_8 ) {
case 8 :
case 16 :
return V_8 ;
default:
return - V_9 ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , L_3 ) ;
}
