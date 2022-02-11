static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 ;
F_2 ( V_3 -> V_6 , V_3 -> V_7 ,
V_3 -> V_8 -> V_9 , V_1 -> V_10 ) ;
V_5 = F_3 ( V_3 -> V_11 ) ;
if ( V_5 ) {
F_4 ( & V_1 -> V_12 , L_1 ) ;
return V_5 ;
}
if ( V_3 -> V_8 -> V_13 ) {
V_5 = F_5 ( V_3 -> V_13 ) ;
if ( V_5 ) {
F_4 ( & V_1 -> V_12 , L_2 ) ;
goto V_14;
}
}
if ( V_3 -> V_8 -> V_15 ) {
V_5 = F_5 ( V_3 -> V_15 ) ;
if ( V_5 ) {
F_4 ( & V_1 -> V_12 , L_3 ) ;
goto V_16;
}
}
F_6 ( & V_1 -> V_12 , L_4 , V_1 -> V_10 ) ;
return 0 ;
V_16:
if ( V_3 -> V_8 -> V_15 )
F_7 ( V_3 -> V_13 ) ;
V_14:
F_8 ( V_3 -> V_11 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_17 = 0 , V_18 = 0 ;
if ( V_3 -> V_8 -> V_13 ) {
V_17 = F_7 ( V_3 -> V_13 ) ;
if ( V_17 )
F_4 ( & V_1 -> V_12 , L_5 ) ;
}
if ( V_3 -> V_8 -> V_15 ) {
V_18 = F_7 ( V_3 -> V_15 ) ;
if ( V_18 )
F_4 ( & V_1 -> V_12 , L_6 ) ;
}
F_8 ( V_3 -> V_11 ) ;
return V_17 ? : V_18 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_11 ( V_20 ) ;
struct V_2 * V_3 = V_1 -> V_4 ;
int V_21 = 0 , V_22 = 0 ;
if ( V_3 -> V_8 -> V_13 )
V_21 = F_12 ( V_3 -> V_13 ) ;
if ( V_3 -> V_8 -> V_15 )
V_22 = F_12 ( V_3 -> V_15 ) ;
if ( V_21 < 0 || V_22 < 0 )
return - V_23 ;
return ! V_21 && ! V_22 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_24 * V_12 = & V_20 -> V_12 ;
struct V_1 * V_1 = F_11 ( V_20 ) ;
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_25 * V_26 = V_12 -> V_27 ;
int V_5 ;
if ( V_3 -> V_8 -> V_13 ) {
V_3 -> V_13 = F_14 ( V_12 , L_7 ) ;
if ( F_15 ( V_3 -> V_13 ) ) {
F_4 ( V_12 , L_8 ) ;
return F_16 ( V_3 -> V_13 ) ;
}
}
if ( V_3 -> V_8 -> V_15 ) {
V_3 -> V_15 = F_14 ( V_12 , L_9 ) ;
if ( F_15 ( V_3 -> V_15 ) ) {
F_4 ( V_12 , L_10 ) ;
return F_16 ( V_3 -> V_15 ) ;
}
}
V_3 -> V_11 = F_17 ( V_12 , NULL ) ;
if ( F_15 ( V_3 -> V_11 ) ) {
F_4 ( V_12 , L_11 ) ;
return F_16 ( V_3 -> V_11 ) ;
}
V_5 = F_18 ( V_26 , L_12 , & V_3 -> V_28 ) ;
if ( V_5 ) {
F_4 ( V_12 , L_13 ) ;
return V_5 ;
}
V_3 -> V_6 = F_19 ( V_26 , L_14 ) ;
if ( F_15 ( V_3 -> V_6 ) ) {
F_4 ( V_12 , L_15 ) ;
return F_16 ( V_3 -> V_6 ) ;
}
V_5 = F_20 ( V_26 , L_14 , 1 ,
& V_3 -> V_7 ) ;
if ( V_5 ) {
F_4 ( V_12 , L_16 ) ;
return - V_23 ;
}
V_5 = F_21 ( V_12 ) ;
if ( V_5 ) {
F_4 ( V_12 , L_17 ) ;
return V_5 ;
}
V_5 = F_22 ( V_3 -> V_11 ) ;
if ( V_5 )
F_4 ( V_12 , L_18 ) ;
return V_5 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_24 * V_12 = & V_20 -> V_12 ;
const struct V_29 * V_30 ;
struct V_2 * V_3 ;
struct V_25 * V_26 = V_12 -> V_27 ;
struct V_1 * V_1 ;
int V_31 ;
int V_32 ;
V_30 = F_24 ( V_33 , V_12 ) ;
if ( ! V_30 || ! V_30 -> V_34 ) {
F_4 ( V_12 , L_19 ) ;
return - V_35 ;
}
V_1 = F_25 ( V_12 , V_26 -> V_36 , & V_37 , NULL , sizeof( * V_3 ) ) ;
if ( ! V_1 )
return - V_38 ;
V_1 -> V_39 = false ;
V_3 = V_1 -> V_4 ;
V_3 -> V_8 = (struct V_40 * ) V_30 -> V_34 ;
F_26 ( V_20 , V_1 ) ;
V_32 = F_13 ( V_20 ) ;
if ( V_32 )
goto V_41;
V_31 = F_10 ( V_20 ) ;
if ( V_31 < 0 ) {
V_32 = V_31 ;
goto V_41;
}
if ( V_31 ) {
F_27 ( & V_1 -> V_42 ) ;
V_1 -> V_43 = V_44 ;
} else {
F_28 ( V_3 -> V_11 , V_3 -> V_28 ) ;
}
V_32 = F_29 ( V_1 ) ;
if ( V_32 )
goto V_41;
return 0 ;
V_41:
F_30 ( V_1 ) ;
return V_32 ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_11 ( V_20 ) ;
struct V_2 * V_3 = V_1 -> V_4 ;
F_32 ( V_1 ) ;
F_33 ( V_3 -> V_11 ) ;
F_34 ( & V_20 -> V_12 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
