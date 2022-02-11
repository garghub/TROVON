static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
F_2 ( V_2 -> V_6 ,
V_2 -> V_7 + V_8 ,
F_3 ( V_9 ,
V_10 ,
V_11 ) ) ;
F_2 ( V_2 -> V_6 ,
V_2 -> V_7 + V_8 ,
F_3 ( V_12 ,
V_13 ,
V_14 ) ) ;
if ( V_3 == V_9 )
return 0 ;
F_4 ( 3 ) ;
F_2 ( V_2 -> V_6 ,
V_2 -> V_7 + V_8 ,
F_3 ( V_15 ,
V_10 ,
V_11 ) ) ;
F_4 ( 5 ) ;
F_5 ( V_2 -> V_6 ,
V_2 -> V_7 + V_16 ,
& V_4 ) ;
V_4 = ( V_4 >> V_17 ) & V_18 ;
if ( V_4 != V_19 ) {
F_6 ( L_1 ) ;
return - V_20 ;
}
F_2 ( V_2 -> V_6 ,
V_2 -> V_7 + V_8 ,
F_3 ( V_21 ,
V_13 ,
V_14 ) ) ;
F_4 ( 11 ) ;
F_5 ( V_2 -> V_6 ,
V_2 -> V_7 + V_16 ,
& V_5 ) ;
V_5 = ( V_5 >> V_22 ) & V_23 ;
if ( V_5 != V_24 ) {
F_6 ( L_2 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_7 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
int V_26 = 0 ;
V_26 = F_1 ( V_2 , V_9 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_9 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
int V_26 = 0 ;
V_26 = F_1 ( V_2 , V_15 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = & V_28 -> V_30 ;
struct V_1 * V_2 ;
struct V_25 * V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_34 ;
unsigned int V_7 ;
if ( ! V_30 -> V_35 || ! V_30 -> V_35 -> V_36 )
return - V_37 ;
V_34 = F_11 ( V_30 -> V_35 -> V_36 ) ;
if ( F_12 ( V_34 ) ) {
F_13 ( V_30 , L_3 ) ;
return F_14 ( V_34 ) ;
}
V_2 = F_15 ( V_30 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
if ( F_16 ( V_30 -> V_36 , L_4 , & V_7 ) ) {
F_13 ( V_30 , L_5 ,
V_30 -> V_36 -> V_40 ) ;
return - V_41 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = V_34 ;
V_31 = F_17 ( V_30 , V_30 -> V_36 , & V_42 ) ;
if ( F_12 ( V_31 ) ) {
F_13 ( V_30 , L_6 ) ;
return F_14 ( V_31 ) ;
}
F_18 ( V_31 , V_2 ) ;
V_32 = F_19 ( V_30 , V_43 ) ;
return F_20 ( V_32 ) ;
}
