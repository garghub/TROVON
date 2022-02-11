struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_2 * V_4 , unsigned int V_5 ,
unsigned int V_6 , T_1 V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 , V_12 ,
& V_3 , 1 , & V_4 , 1 , V_7 ) ;
struct V_13 * V_14 = V_11 ? V_11 -> V_14 : NULL ;
struct V_1 * V_15 = NULL ;
struct V_16 * V_17 = NULL ;
if ( V_14 )
V_17 = F_3 ( V_14 -> V_18 , 2 , V_19 ) ;
if ( V_17 && F_4 ( V_14 , V_6 , V_5 , V_7 ) ) {
unsigned long V_20 = 0 ;
if ( V_9 -> V_21 )
V_20 |= V_22 ;
if ( V_9 -> V_23 & V_24 )
V_20 |= V_25 ;
V_17 -> V_26 = 1 ;
V_17 -> V_27 [ 0 ] = F_5 ( V_14 -> V_18 , V_4 , V_6 , V_7 ,
V_28 ) ;
V_17 -> V_29 = 1 ;
V_17 -> V_27 [ 1 ] = F_5 ( V_14 -> V_18 , V_3 , V_5 , V_7 ,
V_30 ) ;
V_17 -> V_7 = V_7 ;
V_15 = V_14 -> V_31 ( V_11 , V_17 -> V_27 [ 1 ] ,
V_17 -> V_27 [ 0 ] , V_7 ,
V_20 ) ;
}
if ( V_15 ) {
F_6 ( L_1 , V_32 , V_7 ) ;
F_7 ( V_15 , V_17 ) ;
F_8 ( V_11 , V_15 , V_9 ) ;
} else {
void * V_33 , * V_34 ;
F_6 ( L_2 , V_32 , V_7 ) ;
F_9 ( & V_9 -> V_35 ) ;
V_33 = F_10 ( V_3 ) + V_5 ;
V_34 = F_10 ( V_4 ) + V_6 ;
memcpy ( V_33 , V_34 , V_7 ) ;
F_11 ( V_34 ) ;
F_11 ( V_33 ) ;
F_12 ( V_9 ) ;
}
F_13 ( V_17 ) ;
return V_15 ;
}
