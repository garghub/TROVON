int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 = - 1 ;
switch ( V_3 ) {
case 8 : break;
case 11 : V_5 = F_2 ( 0x300 ) ; break;
case 12 : V_5 = F_2 ( 0x360 ) ; break;
case 13 : V_5 = F_2 ( 0x2a0 ) ; break;
case 14 : V_5 = F_2 ( 0x300 ) ; break;
case 15 : V_5 = F_2 ( 0x360 ) ; break;
}
F_3 ( L_1 ,
V_3 , V_4 - 1 + 'A' , V_5 ) ;
return V_5 ;
}
