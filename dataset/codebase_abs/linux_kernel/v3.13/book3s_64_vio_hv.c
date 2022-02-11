long F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
F_2 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_8 -> V_3 == V_3 ) {
unsigned long V_9 = V_4 >> V_10 ;
struct V_11 * V_11 ;
T_1 * V_12 ;
if ( V_4 >= V_8 -> V_13 )
return V_14 ;
V_11 = V_8 -> V_15 [ V_9 / V_16 ] ;
V_12 = ( T_1 * ) F_3 ( V_11 ) ;
V_12 [ V_9 % V_16 ] = V_5 ;
return V_17 ;
}
}
return V_18 ;
}
