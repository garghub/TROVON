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
V_19 = F_6 ( V_15 , V_13 -> V_22 ) ;
if ( F_7 ( V_19 ) )
return F_8 ( V_19 ) ;
V_13 -> V_1 = F_9 ( V_15 , NULL , V_19 ,
& V_24 ) ;
F_10 ( V_13 -> V_1 , F_11 ( V_25 ) , & V_13 -> V_26 ) ;
if ( ( V_13 -> V_26 < V_27 ) || ( V_13 -> V_26 > V_28 ) ) {
F_12 ( V_15 , L_1 , V_13 -> V_26 ) ;
return - V_29 ;
}
F_1 ( V_13 -> V_1 ) ;
V_13 -> V_30 = F_13 ( V_17 , L_2 , 0 ) ;
if ( ! F_14 ( V_13 -> V_30 ) ) {
F_15 ( V_15 , L_3 ) ;
return - V_31 ;
}
V_11 = F_16 ( V_15 , V_13 -> V_30 , V_32 ,
L_4 ) ;
if ( V_11 < 0 ) {
F_15 ( V_15 , L_5 ,
V_13 -> V_30 , V_11 ) ;
return V_11 ;
}
V_11 = F_17 ( V_13 -> V_1 , F_18 ( V_13 -> V_30 ) ,
V_33 | V_34 , 0 ,
& V_35 , & V_13 -> V_36 ) ;
if ( V_11 ) {
F_15 ( V_15 , L_6 , V_11 ) ;
return V_11 ;
}
F_19 ( V_10 , V_13 ) ;
V_11 = F_20 ( V_15 , V_37 , V_38 ,
F_21 ( V_38 ) , NULL , 0 ,
F_22 ( V_13 -> V_36 ) ) ;
if ( V_11 ) {
F_15 ( V_15 , L_7 , V_11 ) ;
F_23 ( F_18 ( V_13 -> V_30 ) , V_13 -> V_36 ) ;
return V_11 ;
}
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_25 ( V_10 ) ;
F_23 ( F_18 ( V_13 -> V_30 ) , V_13 -> V_36 ) ;
F_26 ( & V_10 -> V_15 ) ;
return 0 ;
}
