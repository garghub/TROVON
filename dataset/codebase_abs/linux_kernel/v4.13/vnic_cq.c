void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , & V_2 -> V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_3 ( struct V_6 * V_3 , struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 , unsigned int V_9 )
{
int V_10 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = F_4 ( V_3 , V_11 , V_7 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( V_3 , L_1 , V_7 ) ;
return - V_12 ;
}
V_10 = F_6 ( V_3 , & V_2 -> V_4 , V_8 , V_9 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned int V_14 , unsigned int V_15 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 ,
unsigned int V_21 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = ( T_1 ) V_2 -> V_4 . V_24 | V_25 ;
F_8 ( V_23 , & V_2 -> V_5 -> V_26 ) ;
F_9 ( V_2 -> V_4 . V_8 , & V_2 -> V_5 -> V_27 ) ;
F_9 ( V_13 , & V_2 -> V_5 -> V_13 ) ;
F_9 ( V_14 , & V_2 -> V_5 -> V_14 ) ;
F_9 ( V_15 , & V_2 -> V_5 -> V_15 ) ;
F_9 ( V_16 , & V_2 -> V_5 -> V_16 ) ;
F_9 ( V_17 , & V_2 -> V_5 -> V_17 ) ;
F_9 ( V_18 , & V_2 -> V_5 -> V_18 ) ;
F_9 ( V_19 , & V_2 -> V_5 -> V_19 ) ;
F_9 ( V_20 , & V_2 -> V_5 -> V_20 ) ;
F_9 ( V_21 , & V_2 -> V_5 -> V_21 ) ;
F_8 ( V_22 , & V_2 -> V_5 -> V_22 ) ;
V_2 -> V_21 = V_21 ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
F_9 ( 0 , & V_2 -> V_5 -> V_15 ) ;
F_9 ( 0 , & V_2 -> V_5 -> V_16 ) ;
F_9 ( 1 , & V_2 -> V_5 -> V_17 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
