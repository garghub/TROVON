unsigned long F_1 ( struct V_1 * V_2 )
{
const unsigned int * V_3 = NULL ;
F_2 ( V_2 ) ;
while ( V_2 ) {
V_3 = F_3 ( V_2 , L_1 , NULL ) ;
if ( V_3 )
break;
V_2 = F_4 ( V_2 ) ;
}
F_5 ( V_2 ) ;
return V_3 ? * V_3 : 0 ;
}
