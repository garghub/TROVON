struct V_1 V_1 ( T_1 V_2 )
{
struct V_1 V_3 ;
T_2 V_4 ;
int V_5 ;
V_5 = F_1 ( V_2 - 1 ) ;
V_4 = ( ( 1ULL << 32 ) * ( ( 1ULL << V_5 ) - V_2 ) ) ;
F_2 ( V_4 , V_2 ) ;
++ V_4 ;
V_3 . V_4 = ( T_1 ) V_4 ;
V_3 . V_6 = F_3 ( V_5 , 1 ) ;
V_3 . V_7 = F_4 ( V_5 - 1 , 0 ) ;
return V_3 ;
}
