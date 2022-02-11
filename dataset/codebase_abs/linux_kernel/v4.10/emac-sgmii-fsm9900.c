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
unsigned int V_5 ;
F_1 ( V_11 -> V_1 , V_12 ,
F_4 ( V_12 ) ) ;
F_1 ( V_11 -> V_1 , V_13 ,
F_4 ( V_13 ) ) ;
F_1 ( V_11 -> V_1 , V_14 , F_4 ( V_14 ) ) ;
F_1 ( V_11 -> V_1 , V_15 , F_4 ( V_15 ) ) ;
F_1 ( V_11 -> V_1 , V_16 , F_4 ( V_16 ) ) ;
F_2 ( V_17 , V_11 -> V_1 + V_18 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( F_5 ( V_11 -> V_1 + V_20 ) & V_21 )
break;
F_6 ( 100 , 200 ) ;
}
if ( V_5 == V_19 ) {
F_7 ( V_9 -> V_22 , L_1 ) ;
return - V_23 ;
}
F_2 ( 0 , V_11 -> V_1 + V_24 ) ;
return 0 ;
}
