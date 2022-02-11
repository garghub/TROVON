int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 1 ;
T_1 V_5 ;
unsigned char * V_6 ;
struct V_7 {
T_2 V_8 [ 270 ] ;
struct V_9 {
T_3 V_10 ;
T_2 V_11 ;
T_2 V_12 [ 3 ] ;
T_3 V_13 ;
T_3 V_14 ;
} V_15 [ 2 ] ;
T_2 V_16 [ 208 ] ;
T_4 V_17 ;
} V_18 ( ( V_19 ) ) * V_20 ;
struct V_9 * V_21 ;
V_6 = F_2 ( V_2 , 0 , & V_5 ) ;
if ( ! V_6 )
return - 1 ;
V_20 = (struct V_7 * ) V_6 ;
if ( F_3 ( V_20 -> V_17 ) != V_22 ) {
F_4 ( V_5 ) ;
return 0 ;
}
V_21 = V_20 -> V_15 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ , V_21 ++ ) {
if ( V_4 == V_2 -> V_23 )
break;
if ( V_21 -> V_11 == 0x4d && F_5 ( V_21 -> V_14 ) ) {
F_6 ( V_2 , V_4 , F_5 ( V_21 -> V_13 ) ,
F_5 ( V_21 -> V_14 ) ) ;
}
V_4 ++ ;
}
F_7 ( V_2 -> V_24 , L_1 , V_25 ) ;
F_4 ( V_5 ) ;
return 1 ;
}
