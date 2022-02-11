T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_1 V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 && * V_3 >= 0x30 && * V_4 >= 0x16 ) {
T_1 V_8 = F_3 ( V_2 , V_7 + 0x14 ) ;
if ( V_8 ) {
* V_3 = F_4 ( V_2 , V_8 + 0 ) ;
* V_4 = F_4 ( V_2 , V_8 + 1 ) ;
* V_5 = F_4 ( V_2 , V_8 + 2 ) ;
* V_6 = F_4 ( V_2 , V_8 + 3 ) ;
return V_8 ;
}
}
return 0x0000 ;
}
T_1
F_5 ( struct V_1 * V_2 , T_2 V_9 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_8 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_8 && V_9 < V_5 )
return V_8 + V_4 + ( V_9 * * V_6 ) ;
return 0x0000 ;
}
