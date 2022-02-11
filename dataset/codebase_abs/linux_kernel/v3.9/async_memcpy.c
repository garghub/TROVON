struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_2 * V_4 , unsigned int V_5 ,
unsigned int V_6 , T_1 V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 , V_12 ,
& V_3 , 1 , & V_4 , 1 , V_7 ) ;
struct V_13 * V_14 = V_11 ? V_11 -> V_14 : NULL ;
struct V_1 * V_15 = NULL ;
if ( V_14 && F_3 ( V_14 , V_6 , V_5 , V_7 ) ) {
T_2 V_16 , V_17 ;
unsigned long V_18 = 0 ;
if ( V_9 -> V_19 )
V_18 |= V_20 ;
if ( V_9 -> V_21 & V_22 )
V_18 |= V_23 ;
V_16 = F_4 ( V_14 -> V_24 , V_3 , V_5 , V_7 ,
V_25 ) ;
V_17 = F_4 ( V_14 -> V_24 , V_4 , V_6 , V_7 ,
V_26 ) ;
V_15 = V_14 -> V_27 ( V_11 , V_16 , V_17 ,
V_7 , V_18 ) ;
if ( ! V_15 ) {
F_5 ( V_14 -> V_24 , V_16 , V_7 ,
V_25 ) ;
F_5 ( V_14 -> V_24 , V_17 , V_7 ,
V_26 ) ;
}
}
if ( V_15 ) {
F_6 ( L_1 , V_28 , V_7 ) ;
F_7 ( V_11 , V_15 , V_9 ) ;
} else {
void * V_29 , * V_30 ;
F_6 ( L_2 , V_28 , V_7 ) ;
F_8 ( & V_9 -> V_31 ) ;
V_29 = F_9 ( V_3 ) + V_5 ;
V_30 = F_9 ( V_4 ) + V_6 ;
memcpy ( V_29 , V_30 , V_7 ) ;
F_10 ( V_30 ) ;
F_10 ( V_29 ) ;
F_11 ( V_9 ) ;
}
return V_15 ;
}
