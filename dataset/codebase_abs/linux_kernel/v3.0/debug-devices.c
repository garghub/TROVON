int T_1 F_1 ( T_2 V_1 , unsigned V_2 )
{
int V_3 ;
V_4 [ 0 ] . V_5 = V_1 + 0x300 ;
V_4 [ 0 ] . V_6 = V_1 + 0x30f ;
V_4 [ 1 ] . V_5 = F_2 ( V_2 ) ;
V_4 [ 1 ] . V_6 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_2 , L_1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_7 L_2 , V_2 ) ;
return V_3 ;
}
F_5 ( V_2 ) ;
V_8 [ 0 ] . V_5 = V_1 ;
V_8 [ 0 ] . V_6 = V_1 + V_9 - 1 ;
return F_6 ( V_10 , F_7 ( V_10 ) ) ;
}
