void T_1 F_1 ( void T_2 * V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_4 * * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
struct V_8 * V_9 ;
V_9 = V_7 + V_6 ;
V_5 = F_3 ( V_9 -> V_10 , V_3 ) ;
if ( ! V_5 )
continue;
V_4 = F_4 ( NULL , V_9 -> V_11 , V_9 -> V_12 ,
V_9 -> V_13 , V_14 ,
V_1 + V_15 , V_9 -> V_16 ,
3 , 0 , & V_17 ) ;
* V_5 = V_4 ;
V_5 = F_3 ( V_9 -> V_18 , V_3 ) ;
if ( ! V_5 )
continue;
V_4 = F_5 ( NULL , V_9 -> V_19 , V_9 -> V_11 ,
0 , V_1 + V_15 ,
V_9 -> V_20 , 0 , & V_17 ) ;
* V_5 = V_4 ;
F_6 ( V_4 , V_9 -> V_21 , V_9 -> V_19 ) ;
}
F_7 ( 0 , V_1 + V_22 ) ;
V_4 = F_5 ( NULL , L_1 , L_2 , 0 ,
V_1 + V_23 ,
V_24 , 0 , NULL ) ;
V_5 = F_3 ( V_25 , V_3 ) ;
if ( ! V_5 )
return;
V_4 = F_5 ( NULL , L_3 , L_1 , 0 ,
V_1 + V_26 ,
V_27 , 0 , NULL ) ;
F_6 ( V_4 , L_3 , NULL ) ;
* V_5 = V_4 ;
}
