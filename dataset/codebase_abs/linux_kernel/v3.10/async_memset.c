struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 , unsigned int V_5 , T_1 V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 , V_11 ,
& V_3 , 1 , NULL , 0 , V_6 ) ;
struct V_12 * V_13 = V_10 ? V_10 -> V_13 : NULL ;
struct V_1 * V_14 = NULL ;
if ( V_13 && F_3 ( V_13 , V_5 , 0 , V_6 ) ) {
T_2 V_15 ;
unsigned long V_16 = 0 ;
if ( V_8 -> V_17 )
V_16 |= V_18 ;
if ( V_8 -> V_19 & V_20 )
V_16 |= V_21 ;
V_15 = F_4 ( V_13 -> V_22 , V_3 , V_5 , V_6 ,
V_23 ) ;
V_14 = V_13 -> V_24 ( V_10 , V_15 , V_4 , V_6 ,
V_16 ) ;
}
if ( V_14 ) {
F_5 ( L_1 , V_25 , V_6 ) ;
F_6 ( V_10 , V_14 , V_8 ) ;
} else {
void * V_26 ;
F_5 ( L_2 , V_25 , V_6 ) ;
V_26 = F_7 ( V_3 ) + V_5 ;
F_8 ( & V_8 -> V_27 ) ;
memset ( V_26 , V_4 , V_6 ) ;
F_9 ( V_8 ) ;
}
return V_14 ;
}
