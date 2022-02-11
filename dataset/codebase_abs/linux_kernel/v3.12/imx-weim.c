static int T_1 F_1 ( struct V_1 * V_2 , void T_2 * V_3 ,
const struct V_4 * V_5 )
{
T_3 V_6 , V_7 [ V_5 -> V_8 ] ;
int V_9 , V_10 ;
V_10 = F_2 ( V_2 , L_1 , & V_6 ) ;
if ( V_10 )
return V_10 ;
if ( V_6 >= V_5 -> V_11 )
return - V_12 ;
V_10 = F_3 ( V_2 , L_2 ,
V_7 , V_5 -> V_8 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_8 ; V_9 ++ )
F_4 ( V_7 [ V_9 ] , V_3 + V_6 * V_5 -> V_13 + V_9 * 4 ) ;
return 0 ;
}
static int T_1 F_5 ( struct V_14 * V_15 ,
void T_2 * V_3 )
{
const struct V_16 * V_17 = F_6 ( V_18 ,
& V_15 -> V_19 ) ;
const struct V_4 * V_5 = V_17 -> V_20 ;
struct V_1 * V_21 ;
int V_10 ;
F_7 (pdev->dev.of_node, child) {
if ( ! V_21 -> V_22 )
continue;
V_10 = F_1 ( V_21 , V_3 , V_5 ) ;
if ( V_10 ) {
F_8 ( & V_15 -> V_19 , L_3 ,
V_21 -> V_23 ) ;
return V_10 ;
}
}
V_10 = F_9 ( V_15 -> V_19 . V_24 , NULL , NULL , & V_15 -> V_19 ) ;
if ( V_10 )
F_8 ( & V_15 -> V_19 , L_4 ,
V_15 -> V_19 . V_24 -> V_23 ) ;
return V_10 ;
}
static int T_1 F_10 ( struct V_14 * V_15 )
{
struct V_25 * V_26 ;
struct V_27 * V_27 ;
void T_2 * V_3 ;
int V_10 ;
V_26 = F_11 ( V_15 , V_28 , 0 ) ;
V_3 = F_12 ( & V_15 -> V_19 , V_26 ) ;
if ( F_13 ( V_3 ) )
return F_14 ( V_3 ) ;
V_27 = F_15 ( & V_15 -> V_19 , NULL ) ;
if ( F_13 ( V_27 ) )
return F_14 ( V_27 ) ;
V_10 = F_16 ( V_27 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_5 ( V_15 , V_3 ) ;
if ( V_10 )
F_17 ( V_27 ) ;
else
F_18 ( & V_15 -> V_19 , L_5 ) ;
return V_10 ;
}
