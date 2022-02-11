static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
V_9 = F_4 ( V_4 ) ;
F_5 ( V_8 -> V_10 ) ;
F_5 ( V_8 -> V_11 ) ;
F_5 ( V_8 -> V_12 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
V_9 = F_7 ( V_8 -> V_12 ) ;
if ( V_9 ) {
F_8 ( V_2 , L_1 ) ;
return V_9 ;
}
V_9 = F_7 ( V_8 -> V_11 ) ;
if ( V_9 ) {
F_8 ( V_2 , L_2 ) ;
return V_9 ;
}
V_9 = F_7 ( V_8 -> V_10 ) ;
if ( V_9 ) {
F_8 ( V_2 , L_3 ) ;
return V_9 ;
}
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 ;
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_19 , V_20 ;
unsigned int V_21 , V_22 ;
unsigned int V_23 , V_24 ;
int V_9 ;
V_16 = F_11 ( V_25 , & V_14 -> V_2 ) ;
if ( ! V_16 )
return - V_26 ;
V_18 = V_16 -> V_27 ;
V_8 = F_12 ( & V_14 -> V_2 , sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 ) {
F_8 ( & V_14 -> V_2 , L_4 ) ;
return - V_29 ;
}
V_8 -> V_12 = F_13 ( & V_14 -> V_2 , L_5 ) ;
if ( F_14 ( V_8 -> V_12 ) ) {
F_8 ( & V_14 -> V_2 , L_6 ) ;
return F_15 ( V_8 -> V_12 ) ;
}
V_8 -> V_11 = F_13 ( & V_14 -> V_2 , L_7 ) ;
if ( F_14 ( V_8 -> V_11 ) ) {
F_8 ( & V_14 -> V_2 , L_8 ) ;
return F_15 ( V_8 -> V_11 ) ;
}
V_8 -> V_10 = F_13 ( & V_14 -> V_2 , L_9 ) ;
if ( F_14 ( V_8 -> V_10 ) ) {
F_8 ( & V_14 -> V_2 , L_10 ) ;
return F_15 ( V_8 -> V_10 ) ;
}
V_4 = F_16 ( V_14 , V_18 , 0 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
F_7 ( V_8 -> V_11 ) ;
V_19 = F_17 ( V_4 -> V_30 + V_31 ) ;
V_20 = F_17 ( V_4 -> V_30 + V_32 ) ;
V_21 = ( V_19 & V_33 ) >> V_34 ;
V_22 = ( V_20 & V_35 ) >> V_36 ;
V_23 = V_21 * 1000000 * ( V_22 + 1 ) ;
V_9 = F_18 ( V_8 -> V_10 , V_23 ) ;
if ( V_9 < 0 ) {
F_8 ( & V_14 -> V_2 , L_11 ) ;
goto V_37;
}
V_24 = F_19 ( V_8 -> V_10 ) ;
if ( V_24 != V_23 ) {
V_22 = V_24 / ( V_21 * 1000000 ) - 1 ;
V_20 &= ( ~ V_35 ) ;
V_20 |= ( ( V_22 << V_36 ) & V_35 ) ;
F_20 ( V_38 | V_39 , V_4 -> V_30 + V_40 ) ;
F_20 ( V_20 , V_4 -> V_30 + V_32 ) ;
F_20 ( 0 , V_4 -> V_30 + V_40 ) ;
F_21 ( & V_14 -> V_2 , L_12 ,
V_22 , V_24 ) ;
}
F_7 ( V_8 -> V_12 ) ;
F_7 ( V_8 -> V_10 ) ;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_8 = V_8 ;
V_9 = F_22 ( V_4 -> V_41 ) ;
if ( V_9 )
goto V_42;
F_23 ( V_14 ) ;
F_24 ( & V_14 -> V_2 ) ;
F_25 ( & V_14 -> V_2 ) ;
F_26 ( & V_14 -> V_2 ) ;
F_27 ( & V_14 -> V_2 , 50 ) ;
F_28 ( & V_14 -> V_2 ) ;
V_9 = F_29 ( V_4 ) ;
if ( V_9 )
goto V_43;
F_30 ( & V_14 -> V_2 ) ;
return 0 ;
V_43:
V_43 ( & V_14 -> V_2 ) ;
F_31 ( & V_14 -> V_2 ) ;
F_32 ( & V_14 -> V_2 ) ;
V_42:
F_5 ( V_8 -> V_10 ) ;
F_5 ( V_8 -> V_12 ) ;
V_37:
F_5 ( V_8 -> V_11 ) ;
F_33 ( V_14 ) ;
return V_9 ;
}
static int F_34 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_35 ( V_14 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_36 ( & V_14 -> V_2 ) ;
V_43 ( & V_14 -> V_2 ) ;
F_32 ( & V_14 -> V_2 ) ;
F_37 ( V_14 ) ;
F_5 ( V_8 -> V_10 ) ;
F_5 ( V_8 -> V_11 ) ;
F_5 ( V_8 -> V_12 ) ;
return 0 ;
}
