static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
const T_2 * V_9 ;
struct V_10 * V_11 ;
T_3 V_12 [ 4 ] = {
05 ,
033 ,
0113 ,
01111 ,
} ;
T_3 V_13 = 0 ;
T_3 V_14 ;
int V_15 = 0 ;
int V_16 = 0 ;
V_11 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_11 ) ) {
F_4 ( & V_2 -> V_5 , L_2 ) ;
return 0 ;
}
F_5 (np, L_3 , prop, p, val) {
if ( V_16 % 4 == 0 ) {
V_15 = V_14 ;
} else if ( V_16 % 4 == 3 && V_14 ) {
V_14 = ( V_14 / V_17 ) | 1 ;
V_13 |= V_14 << V_15 * 3 ;
}
V_16 ++ ;
}
if ( V_16 == 0 || V_16 % 4 )
goto V_18;
for ( V_16 = 0 ; V_16 < F_6 ( V_12 ) ; V_16 ++ ) {
if ( V_13 == V_12 [ V_16 ] ) {
F_7 ( V_11 , V_19 , 0xfff , V_13 ) ;
return 0 ;
}
}
V_18:
F_8 ( & V_2 -> V_5 , L_4 ) ;
return - V_20 ;
}
static int T_1 F_9 ( struct V_3 * V_4 , void T_4 * V_21 ,
const struct V_22 * V_23 )
{
T_3 V_24 , V_25 [ V_23 -> V_26 ] ;
int V_16 , V_27 ;
V_27 = F_10 ( V_4 , L_5 , & V_24 ) ;
if ( V_27 )
return V_27 ;
if ( V_24 >= V_23 -> V_28 )
return - V_20 ;
V_27 = F_11 ( V_4 , L_6 ,
V_25 , V_23 -> V_26 ) ;
if ( V_27 )
return V_27 ;
for ( V_16 = 0 ; V_16 < V_23 -> V_26 ; V_16 ++ )
F_12 ( V_25 [ V_16 ] , V_21 + V_24 * V_23 -> V_29 + V_16 * 4 ) ;
return 0 ;
}
static int T_1 F_13 ( struct V_1 * V_2 ,
void T_4 * V_21 )
{
const struct V_30 * V_31 = F_14 ( V_32 ,
& V_2 -> V_5 ) ;
const struct V_22 * V_23 = V_31 -> V_33 ;
struct V_3 * V_34 ;
int V_27 , V_35 = 0 ;
if ( V_23 == & V_36 ) {
V_27 = F_1 ( V_2 ) ;
if ( V_27 )
return V_27 ;
}
F_15 (pdev->dev.of_node, child) {
if ( ! V_34 -> V_37 )
continue;
V_27 = F_9 ( V_34 , V_21 , V_23 ) ;
if ( V_27 )
F_16 ( & V_2 -> V_5 , L_7 ,
V_34 -> V_38 ) ;
else
V_35 = 1 ;
}
if ( V_35 )
V_27 = F_17 ( V_2 -> V_5 . V_6 ,
NULL , & V_2 -> V_5 ) ;
if ( V_27 )
F_8 ( & V_2 -> V_5 , L_8 ,
V_2 -> V_5 . V_6 -> V_38 ) ;
return V_27 ;
}
static int T_1 F_18 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
struct V_41 * V_41 ;
void T_4 * V_21 ;
int V_27 ;
V_40 = F_19 ( V_2 , V_42 , 0 ) ;
V_21 = F_20 ( & V_2 -> V_5 , V_40 ) ;
if ( F_3 ( V_21 ) )
return F_21 ( V_21 ) ;
V_41 = F_22 ( & V_2 -> V_5 , NULL ) ;
if ( F_3 ( V_41 ) )
return F_21 ( V_41 ) ;
V_27 = F_23 ( V_41 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_13 ( V_2 , V_21 ) ;
if ( V_27 )
F_24 ( V_41 ) ;
else
F_25 ( & V_2 -> V_5 , L_9 ) ;
return V_27 ;
}
