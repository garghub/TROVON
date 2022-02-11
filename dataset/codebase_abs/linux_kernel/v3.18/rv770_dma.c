struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 ,
unsigned V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = NULL ;
struct V_1 * V_11 ;
int V_12 = V_3 -> V_13 -> V_14 . V_15 ;
struct V_16 * V_17 = & V_3 -> V_17 [ V_12 ] ;
T_2 V_18 , V_19 ;
int V_20 , V_21 ;
int V_22 = 0 ;
V_22 = F_2 ( V_3 , & V_10 ) ;
if ( V_22 ) {
F_3 ( L_1 , V_22 ) ;
return F_4 ( V_22 ) ;
}
V_18 = ( V_6 << V_23 ) / 4 ;
V_21 = F_5 ( V_18 , 0xFFFF ) ;
V_22 = F_6 ( V_3 , V_17 , V_21 * 5 + 8 ) ;
if ( V_22 ) {
F_3 ( L_1 , V_22 ) ;
F_7 ( V_3 , & V_10 , NULL ) ;
return F_4 ( V_22 ) ;
}
F_8 ( V_3 , V_10 , V_8 , false ) ;
F_9 ( V_3 , V_10 , V_17 -> V_24 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_19 = V_18 ;
if ( V_19 > 0xFFFF )
V_19 = 0xFFFF ;
V_18 -= V_19 ;
F_10 ( V_17 , F_11 ( V_25 , 0 , 0 , V_19 ) ) ;
F_10 ( V_17 , V_5 & 0xfffffffc ) ;
F_10 ( V_17 , V_4 & 0xfffffffc ) ;
F_10 ( V_17 , F_12 ( V_5 ) & 0xff ) ;
F_10 ( V_17 , F_12 ( V_4 ) & 0xff ) ;
V_4 += V_19 * 4 ;
V_5 += V_19 * 4 ;
}
V_22 = F_13 ( V_3 , & V_11 , V_17 -> V_24 ) ;
if ( V_22 ) {
F_14 ( V_3 , V_17 ) ;
F_7 ( V_3 , & V_10 , NULL ) ;
return F_4 ( V_22 ) ;
}
F_15 ( V_3 , V_17 , false ) ;
F_7 ( V_3 , & V_10 , V_11 ) ;
return V_11 ;
}
