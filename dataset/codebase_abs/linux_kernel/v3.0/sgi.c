int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
T_1 V_5 ;
int V_6 = 1 ;
unsigned int V_7 , V_8 ;
T_1 * V_9 , V_10 ;
T_2 V_11 ;
struct V_12 * V_13 ;
struct F_1 * V_14 ;
char V_15 [ V_16 ] ;
V_13 = F_2 ( V_2 , 0 , & V_11 ) ;
if ( ! V_13 )
return - 1 ;
V_14 = & V_13 -> V_17 [ 0 ] ;
V_5 = V_13 -> V_18 ;
if( F_3 ( V_5 ) != V_19 ) {
F_4 ( V_11 ) ;
return 0 ;
}
V_9 = ( ( T_1 * ) ( V_13 + 1 ) ) - 1 ;
for( V_4 = 0 ; V_9 >= ( ( T_1 * ) V_13 ) ; ) {
V_10 = * V_9 -- ;
V_4 += F_3 ( V_10 ) ;
}
if( V_4 ) {
F_5 ( V_20 L_1 ,
F_6 ( V_2 -> V_21 , V_15 ) ) ;
F_4 ( V_11 ) ;
return 0 ;
}
for( V_3 = 0 ; V_3 < 16 ; V_3 ++ , V_14 ++ ) {
V_8 = F_3 ( V_14 -> V_22 ) ;
V_7 = F_3 ( V_14 -> V_23 ) ;
if ( V_8 ) {
F_7 ( V_2 , V_6 , V_7 , V_8 ) ;
if ( F_3 ( V_14 -> type ) == V_24 )
V_2 -> V_25 [ V_6 ] . V_26 = V_27 ;
}
V_6 ++ ;
}
F_8 ( V_2 -> V_28 , L_2 , V_29 ) ;
F_4 ( V_11 ) ;
return 1 ;
}
