int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_6 ;
int V_7 , V_8 , V_9 ;
int V_10 ;
if ( V_4 ) {
V_1 -> V_11 = V_4 -> V_11 ;
V_1 -> V_12 = V_4 -> V_12 ;
} else {
V_1 -> V_11 = 0 ;
V_1 -> V_12 = - 1 ;
}
V_1 -> V_13 = V_2 ;
if ( V_4 && V_4 -> V_14 != NULL ) {
V_10 = V_4 -> V_14 ( V_1 ) ;
if ( V_10 != 0 ) {
F_2 ( V_1 -> V_5 ,
L_1 ) ;
return V_10 ;
}
}
V_10 = F_3 ( V_1 -> V_15 , V_16 , & V_7 ) ;
if ( V_10 < 0 ) {
F_2 ( V_1 -> V_5 , L_2 ) ;
return - V_17 ;
}
if ( V_7 != V_18 ) {
F_2 ( V_1 -> V_5 , L_3 , V_7 ) ;
return - V_19 ;
}
V_10 = F_3 ( V_1 -> V_15 , V_20 , & V_8 ) ;
if ( V_10 < 0 ) {
F_2 ( V_1 -> V_5 , L_4 ) ;
return - V_17 ;
}
V_9 = V_8 >> V_21 ;
F_4 ( V_1 -> V_5 ,
L_5 ,
V_7 , V_8 ) ;
if ( V_9 < V_22 && V_9 != V_23 ) {
F_2 ( V_1 -> V_5 ,
L_6 , V_9 ) ;
return - V_19 ;
}
V_1 -> V_7 = V_7 ;
V_1 -> V_9 = V_9 ;
V_10 = F_5 ( V_1 ) ;
if ( V_10 ) {
F_2 ( V_1 -> V_5 , L_7 ) ;
return V_10 ;
}
V_1 -> V_12 = F_6 ( V_1 -> V_24 ) ;
V_10 = F_7 ( V_1 -> V_5 , - 1 , V_25 ,
F_8 ( V_25 ) , NULL , V_1 -> V_12 ,
NULL ) ;
if ( V_10 )
F_2 ( V_1 -> V_5 , L_8 ) ;
return V_10 ;
}
void F_9 ( struct V_1 * V_1 )
{
F_10 ( V_1 -> V_5 ) ;
F_11 ( V_1 ) ;
}
