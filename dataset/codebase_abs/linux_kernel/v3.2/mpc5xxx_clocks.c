unsigned int
F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
const unsigned int * V_4 = NULL ;
F_2 ( V_2 ) ;
while ( V_2 ) {
V_4 = F_3 ( V_2 , L_1 , NULL ) ;
if ( V_4 )
break;
V_3 = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 = V_3 ;
}
if ( V_2 )
F_5 ( V_2 ) ;
return V_4 ? * V_4 : 0 ;
}
