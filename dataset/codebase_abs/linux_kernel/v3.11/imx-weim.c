static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 [ V_8 ] ;
T_1 V_9 ;
int V_10 ;
int V_11 ;
V_10 = F_3 ( V_4 , L_1 , & V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 > 3 )
return - V_12 ;
V_10 = F_4 ( V_4 , L_2 ,
V_7 , V_8 ) ;
if ( V_10 )
return V_10 ;
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
F_5 ( V_7 [ V_11 ] , V_6 -> V_13 + V_9 * V_14 + V_11 * 4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_15 ;
int V_10 ;
F_7 (pdev->dev.of_node, child) {
if ( ! V_15 -> V_16 )
continue;
V_10 = F_1 ( V_2 , V_15 ) ;
if ( V_10 ) {
F_8 ( & V_2 -> V_17 , L_3 ,
V_15 -> V_18 ) ;
return V_10 ;
}
}
V_10 = F_9 ( V_2 -> V_17 . V_19 , NULL , NULL , & V_2 -> V_17 ) ;
if ( V_10 )
F_8 ( & V_2 -> V_17 , L_4 ,
V_2 -> V_17 . V_19 -> V_18 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_20 * V_21 ;
int V_10 = - V_12 ;
V_6 = F_11 ( & V_2 -> V_17 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 ) {
V_10 = - V_23 ;
goto V_24;
}
F_12 ( V_2 , V_6 ) ;
V_21 = F_13 ( V_2 , V_25 , 0 ) ;
V_6 -> V_13 = F_14 ( & V_2 -> V_17 , V_21 ) ;
if ( F_15 ( V_6 -> V_13 ) ) {
V_10 = F_16 ( V_6 -> V_13 ) ;
goto V_24;
}
V_6 -> V_26 = F_17 ( & V_2 -> V_17 , NULL ) ;
if ( F_15 ( V_6 -> V_26 ) )
goto V_24;
V_10 = F_18 ( V_6 -> V_26 ) ;
if ( V_10 )
goto V_24;
V_10 = F_6 ( V_2 ) ;
if ( V_10 ) {
F_19 ( V_6 -> V_26 ) ;
goto V_24;
}
F_20 ( & V_2 -> V_17 , L_5 ) ;
return 0 ;
V_24:
return V_10 ;
}
