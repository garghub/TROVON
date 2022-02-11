struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
char * V_4 = L_1 ;
const char * V_5 ;
V_5 = F_2 ( V_2 ) - 1 ;
if ( ! strcmp ( V_2 , L_1 ) )
return F_3 ( - V_6 ) ;
if ( V_5 > V_2 ) {
V_4 = F_4 ( V_2 , V_5 - V_2 , V_7 ) ;
if ( ! V_4 )
return F_3 ( - V_8 ) ;
}
V_3 = F_5 ( V_4 ) ;
if ( strcmp ( V_4 , L_1 ) )
F_6 ( V_4 ) ;
return V_3 ? V_3 : F_3 ( - V_6 ) ;
}
