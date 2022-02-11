static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 , V_4 , V_5 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
F_2 ( V_2 , V_7 + V_3 * V_8 ,
V_5 ) ;
}
}
static int F_3 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = & V_10 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
void T_1 * V_19 ;
V_13 = F_4 ( V_15 , sizeof( * V_13 ) , V_20 ) ;
if ( ! V_13 )
return - V_21 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_22 = F_5 ( V_10 , V_23 , 0 ) ;
if ( ! V_13 -> V_22 )
return - V_24 ;
V_19 = F_6 ( V_15 , V_13 -> V_22 ) ;
if ( ! V_19 )
return - V_21 ;
V_13 -> V_1 = F_7 ( V_15 , NULL , V_19 ,
& V_25 ) ;
F_8 ( V_13 -> V_1 , F_9 ( V_26 ) , & V_13 -> V_27 ) ;
if ( ( V_13 -> V_27 < V_28 ) || ( V_13 -> V_27 > V_29 ) ) {
F_10 ( V_15 , L_1 , V_13 -> V_27 ) ;
return - V_30 ;
}
F_1 ( V_13 -> V_1 ) ;
V_13 -> V_31 = F_11 ( V_17 , L_2 , 0 ) ;
if ( ! F_12 ( V_13 -> V_31 ) ) {
F_13 ( V_15 , L_3 ) ;
return - V_32 ;
}
V_11 = F_14 ( V_15 , V_13 -> V_31 , V_33 ,
L_4 ) ;
if ( V_11 < 0 ) {
F_13 ( V_15 , L_5 ,
V_13 -> V_31 , V_11 ) ;
return V_11 ;
}
V_11 = F_15 ( V_13 -> V_1 , F_16 ( V_13 -> V_31 ) ,
V_34 | V_35 , 0 ,
& V_36 , & V_13 -> V_37 ) ;
if ( V_11 ) {
F_13 ( V_15 , L_6 , V_11 ) ;
return V_11 ;
}
F_17 ( V_10 , V_13 ) ;
V_11 = F_18 ( V_15 , V_38 , V_39 ,
F_19 ( V_39 ) , NULL , 0 , NULL ) ;
if ( V_11 ) {
F_13 ( V_15 , L_7 , V_11 ) ;
F_20 ( F_16 ( V_13 -> V_31 ) , V_13 -> V_37 ) ;
return V_11 ;
}
return 0 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_22 ( V_10 ) ;
F_20 ( F_16 ( V_13 -> V_31 ) , V_13 -> V_37 ) ;
F_23 ( & V_10 -> V_15 ) ;
return 0 ;
}
