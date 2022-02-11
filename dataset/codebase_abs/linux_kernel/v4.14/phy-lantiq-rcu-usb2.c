static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_3 -> V_4 -> V_5 ) {
F_3 ( V_3 -> V_6 , V_3 -> V_7 ,
V_8 , V_8 ) ;
F_3 ( V_3 -> V_6 , V_3 -> V_7 ,
V_9 , 7 << V_10 ) ;
}
F_3 ( V_3 -> V_6 , V_3 -> V_11 ,
F_4 ( V_3 -> V_4 -> V_12 ) , 0 ) ;
F_3 ( V_3 -> V_6 , V_3 -> V_11 ,
F_4 ( V_3 -> V_4 -> V_13 ) , 0 ) ;
F_3 ( V_3 -> V_6 , V_3 -> V_11 ,
F_4 ( V_3 -> V_4 -> V_14 ) ,
F_4 ( V_3 -> V_4 -> V_14 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_15 * V_16 = V_3 -> V_16 ;
int V_17 ;
F_6 ( V_3 -> V_18 ) ;
V_17 = F_7 ( V_3 -> V_19 ) ;
if ( V_17 )
F_8 ( V_16 , L_1 ) ;
return V_17 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_10 ( V_3 -> V_18 ) ;
F_11 ( V_3 -> V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_15 * V_16 = V_3 -> V_16 ;
const T_1 * V_22 ;
int V_17 ;
V_3 -> V_4 = F_13 ( V_16 ) ;
V_3 -> V_6 = F_14 ( V_16 -> V_23 -> V_24 ) ;
if ( F_15 ( V_3 -> V_6 ) ) {
F_8 ( V_16 , L_2 ) ;
return F_16 ( V_3 -> V_6 ) ;
}
V_22 = F_17 ( V_16 -> V_23 , 0 , NULL , NULL ) ;
if ( ! V_22 ) {
F_8 ( V_16 , L_3 ) ;
return - V_25 ;
}
V_3 -> V_11 = F_18 ( * V_22 ) ;
if ( V_3 -> V_4 -> V_5 ) {
V_22 = F_17 ( V_16 -> V_23 , 1 , NULL , NULL ) ;
if ( ! V_22 ) {
F_8 ( V_16 , L_4 ) ;
return - V_25 ;
}
V_3 -> V_7 = F_18 ( * V_22 ) ;
}
V_3 -> V_19 = F_19 ( V_16 , L_5 ) ;
if ( F_15 ( V_3 -> V_19 ) ) {
F_8 ( V_16 , L_6 ) ;
return F_16 ( V_3 -> V_19 ) ;
}
V_3 -> V_26 = F_20 ( V_16 , L_7 ) ;
if ( F_15 ( V_3 -> V_26 ) ) {
if ( F_16 ( V_3 -> V_26 ) != - V_27 )
F_8 ( V_16 , L_8 ) ;
return F_16 ( V_3 -> V_26 ) ;
}
V_3 -> V_18 = F_21 ( V_16 , L_5 ) ;
if ( F_15 ( V_3 -> V_18 ) )
return F_16 ( V_3 -> V_18 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = & V_21 -> V_16 ;
struct V_2 * V_3 ;
struct V_28 * V_29 ;
int V_17 ;
V_3 = F_23 ( V_16 , sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 )
return - V_31 ;
V_3 -> V_16 = V_16 ;
V_17 = F_12 ( V_3 , V_21 ) ;
if ( V_17 )
return V_17 ;
F_6 ( V_3 -> V_26 ) ;
F_10 ( V_3 -> V_18 ) ;
V_3 -> V_1 = F_24 ( V_16 , V_16 -> V_23 , & V_32 ) ;
if ( F_15 ( V_3 -> V_1 ) ) {
F_8 ( V_16 , L_9 ) ;
return F_16 ( V_3 -> V_1 ) ;
}
F_25 ( V_3 -> V_1 , V_3 ) ;
V_29 = F_26 ( V_16 , V_33 ) ;
if ( F_15 ( V_29 ) )
return F_16 ( V_29 ) ;
F_27 ( V_3 -> V_16 , V_3 ) ;
return 0 ;
}
