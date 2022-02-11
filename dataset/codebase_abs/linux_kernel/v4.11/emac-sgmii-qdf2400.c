static void F_1 ( void T_1 * V_1 ,
const struct V_2 * V_3 , T_2 V_4 )
{
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; ++ V_3 , ++ V_5 )
F_2 ( V_3 -> V_6 , V_1 + V_3 -> V_7 ) ;
}
int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
void T_1 * V_12 = V_11 -> V_1 ;
void T_1 * V_13 = V_11 -> V_14 ;
unsigned int V_5 ;
T_3 V_15 ;
F_1 ( V_11 -> V_1 , V_16 ,
F_4 ( V_16 ) ) ;
F_1 ( V_11 -> V_14 , V_17 , F_4 ( V_17 ) ) ;
F_2 ( 0 , V_12 + V_18 ) ;
F_2 ( 1 , V_13 + V_19 ) ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_15 = F_5 ( V_12 + V_21 ) ;
if ( V_15 & F_6 ( 1 ) )
break;
F_7 ( 100 , 200 ) ;
}
if ( V_5 == V_20 ) {
F_8 ( V_9 -> V_22 , L_1 ) ;
return - V_23 ;
}
F_2 ( 0 , V_12 + V_24 ) ;
F_2 ( 0 , V_12 + V_25 ) ;
F_2 ( 0 , V_12 + V_26 ) ;
F_2 ( 0 , V_12 + V_27 ) ;
return 0 ;
}
