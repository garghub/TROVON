int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 ,
unsigned V_5 ,
struct V_6 * * V_7 )
{
struct V_8 * V_9 = NULL ;
int V_10 = V_2 -> V_11 -> V_12 . V_13 ;
struct V_14 * V_15 = & V_2 -> V_15 [ V_10 ] ;
T_2 V_16 , V_17 ;
int V_18 , V_19 ;
int V_20 = 0 ;
V_20 = F_2 ( V_2 , & V_9 ) ;
if ( V_20 ) {
F_3 ( L_1 , V_20 ) ;
return V_20 ;
}
V_16 = ( V_5 << V_21 ) / 4 ;
V_19 = F_4 ( V_16 , 0xFFFF ) ;
V_20 = F_5 ( V_2 , V_15 , V_19 * 5 + 8 ) ;
if ( V_20 ) {
F_3 ( L_1 , V_20 ) ;
F_6 ( V_2 , & V_9 , NULL ) ;
return V_20 ;
}
F_7 ( V_9 , * V_7 ) ;
F_8 ( V_2 , V_9 , V_15 -> V_22 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_17 = V_16 ;
if ( V_17 > 0xFFFF )
V_17 = 0xFFFF ;
V_16 -= V_17 ;
F_9 ( V_15 , F_10 ( V_23 , 0 , 0 , V_17 ) ) ;
F_9 ( V_15 , V_4 & 0xfffffffc ) ;
F_9 ( V_15 , V_3 & 0xfffffffc ) ;
F_9 ( V_15 , F_11 ( V_4 ) & 0xff ) ;
F_9 ( V_15 , F_11 ( V_3 ) & 0xff ) ;
V_3 += V_17 * 4 ;
V_4 += V_17 * 4 ;
}
V_20 = F_12 ( V_2 , V_7 , V_15 -> V_22 ) ;
if ( V_20 ) {
F_13 ( V_2 , V_15 ) ;
F_6 ( V_2 , & V_9 , NULL ) ;
return V_20 ;
}
F_14 ( V_2 , V_15 ) ;
F_6 ( V_2 , & V_9 , * V_7 ) ;
return V_20 ;
}
