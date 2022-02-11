static int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
int V_3 = 0 ;
V_2 = F_2 ( V_1 -> V_4 , V_5 , & V_3 ) ;
if ( V_2 < 0 ) {
F_3 ( V_1 -> V_6 , L_1 ) ;
return - V_7 ;
}
if ( V_3 ) {
if ( V_3 & V_8 )
F_4 ( V_1 -> V_6 ,
L_2 ) ;
if ( V_3 & V_9 )
F_4 ( V_1 -> V_6 ,
L_3 ) ;
if ( V_3 & V_10 )
F_4 ( V_1 -> V_6 ,
L_4 ) ;
if ( V_3 & V_11 )
F_4 ( V_1 -> V_6 ,
L_5 ) ;
if ( V_3 & V_12 )
F_4 ( V_1 -> V_6 ,
L_6 ) ;
if ( V_3 & V_13 )
F_4 ( V_1 -> V_6 ,
L_7 ) ;
if ( V_3 & V_14 )
F_4 ( V_1 -> V_6 ,
L_8 ) ;
if ( V_3 & V_15 )
F_4 ( V_1 -> V_6 ,
L_9 ) ;
}
V_2 = F_5 ( V_1 -> V_4 ,
V_5 ,
V_3 ) ;
if ( V_2 < 0 )
F_3 ( V_1 -> V_6 ,
L_10 , V_2 ) ;
return V_2 ;
}
int F_6 ( struct V_1 * V_1 , unsigned int V_16 )
{
struct V_17 * V_18 = V_1 -> V_6 -> V_19 ;
int V_20 , V_21 , V_22 ;
int V_2 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
F_3 ( V_1 -> V_6 , L_11 ) ;
if ( V_18 ) {
V_1 -> V_23 = V_18 -> V_23 ;
V_1 -> V_24 = V_18 -> V_24 ;
} else {
V_1 -> V_23 = 0 ;
V_1 -> V_24 = - 1 ;
}
V_1 -> V_25 = V_16 ;
if ( V_18 && V_18 -> V_26 != NULL ) {
V_2 = V_18 -> V_26 ( V_1 ) ;
if ( V_2 != 0 ) {
F_3 ( V_1 -> V_6 ,
L_12 ) ;
return V_2 ;
}
}
V_2 = F_2 ( V_1 -> V_4 , V_27 , & V_20 ) ;
if ( V_2 < 0 ) {
F_3 ( V_1 -> V_6 , L_13 ) ;
return - V_7 ;
}
if ( V_20 != V_28 ) {
F_3 ( V_1 -> V_6 , L_14 , V_20 ) ;
return - V_29 ;
}
V_2 = F_2 ( V_1 -> V_4 , V_30 , & V_21 ) ;
if ( V_2 < 0 ) {
F_3 ( V_1 -> V_6 , L_15 ) ;
return - V_7 ;
}
V_22 = V_21 >> V_31 ;
F_7 ( V_1 -> V_6 ,
L_16 ,
V_20 , V_21 ) ;
if ( V_22 < V_32 && V_22 != V_33 ) {
F_3 ( V_1 -> V_6 ,
L_17 , V_22 ) ;
return - V_29 ;
}
V_1 -> V_20 = V_20 ;
V_1 -> V_22 = V_22 ;
V_2 = F_8 ( V_1 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_6 , L_18 ) ;
return V_2 ;
}
V_1 -> V_24 = F_9 ( V_1 -> V_34 ) ;
V_2 = F_10 ( V_1 -> V_6 , - 1 , V_35 ,
F_11 ( V_35 ) , NULL , V_1 -> V_24 ,
NULL ) ;
if ( V_2 )
F_3 ( V_1 -> V_6 , L_19 ) ;
return V_2 ;
}
void F_12 ( struct V_1 * V_1 )
{
F_13 ( V_1 -> V_6 ) ;
F_14 ( V_1 ) ;
}
