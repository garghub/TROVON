int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned char * V_4 , int V_5 , T_1 V_6 )
{
int V_7 ;
unsigned char * V_8 ;
if ( ! V_2 -> V_9 ) {
F_2 ( V_10 L_1
L_2 , V_11 ) ;
return - V_12 ;
}
V_8 = F_3 ( V_4 , V_5 , V_13 ) ;
if ( ! V_8 ) {
F_4 ( & V_2 -> V_9 -> V_9 , L_3 ,
V_11 , V_5 ) ;
return - V_14 ;
}
V_7 = F_5 ( V_2 -> V_9 , F_6 ( V_2 -> V_9 , 0 ) ,
V_6 , 0x40 , V_3 , 0 , V_8 , V_5 , 3000 ) ;
F_7 ( V_8 ) ;
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , unsigned char V_15 )
{
int V_16 ;
V_16 = F_1 ( V_2 , V_17 , & V_15 , 1 , 0xa0 ) ;
if ( V_16 < 0 )
F_4 ( & V_2 -> V_9 -> V_9 , L_4 ,
V_11 , V_15 ) ;
return V_16 ;
}
