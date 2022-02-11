static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_1 V_15 , V_16 ;
int V_17 ;
V_14 = F_2 ( 0 , F_3 ( 0 , 1 ) ) ;
if ( ! V_14 ) {
F_4 ( V_10 , L_1 ) ;
return - V_18 ;
}
V_17 = F_5 ( V_2 , V_3 , V_5 , & V_12 ) ;
* V_8 = F_6 ( V_12 ) ;
if ( V_17 )
return V_17 ;
if ( F_7 ( V_10 ) -> V_19 == 0x1a ) {
F_8 ( V_14 , 0x7c , & V_15 ) ;
V_16 = ( ( V_15 >> 6 ) & 31 ) + 1 ;
} else {
F_8 ( V_14 , 0x84 , & V_15 ) ;
V_16 = ( ( V_15 >> 4 ) & 127 ) + 1 ;
}
V_12 -> type = V_20 ;
V_12 -> V_7 = V_16 * 1024 * 1024 ;
return 0 ;
}
