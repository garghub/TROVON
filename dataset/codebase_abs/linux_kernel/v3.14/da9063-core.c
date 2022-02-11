int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_6 ;
int V_7 , V_8 ;
int V_9 ;
if ( V_4 ) {
V_1 -> V_10 = V_4 -> V_10 ;
V_1 -> V_11 = V_4 -> V_11 ;
} else {
V_1 -> V_10 = 0 ;
V_1 -> V_11 = 0 ;
}
V_1 -> V_12 = V_2 ;
if ( V_4 && V_4 -> V_13 != NULL ) {
V_9 = V_4 -> V_13 ( V_1 ) ;
if ( V_9 != 0 ) {
F_2 ( V_1 -> V_5 ,
L_1 ) ;
return V_9 ;
}
}
V_9 = F_3 ( V_1 -> V_14 , V_15 , & V_7 ) ;
if ( V_9 < 0 ) {
F_2 ( V_1 -> V_5 , L_2 ) ;
return - V_16 ;
}
if ( V_7 != V_17 ) {
F_2 ( V_1 -> V_5 , L_3 , V_7 ) ;
return - V_18 ;
}
V_9 = F_3 ( V_1 -> V_14 , V_19 , & V_8 ) ;
if ( V_9 < 0 ) {
F_2 ( V_1 -> V_5 , L_4 ) ;
return - V_16 ;
}
V_8 >>= V_20 ;
if ( V_8 != 3 ) {
F_2 ( V_1 -> V_5 , L_5 , V_8 ) ;
return - V_18 ;
}
V_1 -> V_7 = V_7 ;
V_1 -> V_8 = V_8 ;
F_4 ( V_1 -> V_5 ,
L_6 ,
V_7 , V_8 ) ;
V_9 = F_5 ( V_1 ) ;
if ( V_9 ) {
F_2 ( V_1 -> V_5 , L_7 ) ;
return V_9 ;
}
V_9 = F_6 ( V_1 -> V_5 , - 1 , V_21 ,
F_7 ( V_21 ) , NULL , V_1 -> V_11 ,
NULL ) ;
if ( V_9 )
F_2 ( V_1 -> V_5 , L_8 ) ;
return V_9 ;
}
void F_8 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_5 ) ;
F_10 ( V_1 ) ;
}
