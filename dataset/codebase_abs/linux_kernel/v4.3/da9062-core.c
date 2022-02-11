static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_4 ) {
if ( V_4 & V_7 )
F_3 ( V_2 -> V_8 , L_1 ) ;
if ( V_4 & V_9 )
F_3 ( V_2 -> V_8 , L_2 ) ;
if ( V_4 & V_10 )
F_3 ( V_2 -> V_8 , L_3 ) ;
if ( V_4 & V_11 )
F_3 ( V_2 -> V_8 , L_4 ) ;
if ( V_4 & V_12 )
F_3 ( V_2 -> V_8 , L_5 ) ;
if ( V_4 & V_13 )
F_3 ( V_2 -> V_8 , L_6 ) ;
if ( V_4 & V_14 )
F_3 ( V_2 -> V_8 , L_7 ) ;
if ( V_4 & V_15 )
F_3 ( V_2 -> V_8 , L_8 ) ;
V_3 = F_4 ( V_2 -> V_5 , V_6 ,
V_4 ) ;
}
return V_3 ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_16 , V_17 , V_18 ;
int V_3 ;
V_3 = F_2 ( V_2 -> V_5 , V_19 , & V_16 ) ;
if ( V_3 < 0 ) {
F_6 ( V_2 -> V_8 , L_9 ) ;
return - V_20 ;
}
if ( V_16 != V_21 ) {
F_6 ( V_2 -> V_8 , L_10 , V_16 ) ;
return - V_22 ;
}
V_3 = F_2 ( V_2 -> V_5 , V_23 , & V_17 ) ;
if ( V_3 < 0 ) {
F_6 ( V_2 -> V_8 , L_11 ) ;
return - V_20 ;
}
F_7 ( V_2 -> V_8 ,
L_12 ,
V_16 , V_17 ) ;
V_18 = ( V_17 & V_24 ) >> V_25 ;
if ( V_18 < V_26 ) {
F_6 ( V_2 -> V_8 ,
L_13 , V_18 ) ;
return - V_22 ;
}
return V_3 ;
}
static int F_8 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
struct V_1 * V_2 ;
unsigned int V_31 ;
int V_3 ;
V_2 = F_9 ( & V_28 -> V_8 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
F_10 ( V_28 , V_2 ) ;
V_2 -> V_8 = & V_28 -> V_8 ;
if ( ! V_28 -> V_34 ) {
F_6 ( V_2 -> V_8 , L_14 ) ;
return - V_35 ;
}
V_2 -> V_5 = F_11 ( V_28 , & V_36 ) ;
if ( F_12 ( V_2 -> V_5 ) ) {
V_3 = F_13 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_8 , L_15 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
F_14 ( V_2 -> V_8 , L_16 ) ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_15 ( V_2 -> V_5 , V_28 -> V_34 ,
V_37 | V_38 | V_39 ,
- 1 , & V_40 ,
& V_2 -> V_41 ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_8 , L_17 ,
V_28 -> V_34 , V_3 ) ;
return V_3 ;
}
V_31 = F_16 ( V_2 -> V_41 ) ;
V_3 = F_17 ( V_2 -> V_8 , V_42 , V_43 ,
F_18 ( V_43 ) , NULL , V_31 ,
NULL ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_8 , L_18 ) ;
F_19 ( V_28 -> V_34 , V_2 -> V_41 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_20 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_21 ( V_28 ) ;
F_22 ( V_2 -> V_8 ) ;
F_19 ( V_28 -> V_34 , V_2 -> V_41 ) ;
return 0 ;
}
