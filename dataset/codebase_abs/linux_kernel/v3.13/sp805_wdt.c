static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
V_7 = F_3 ( V_5 -> V_8 ) ;
V_6 = F_4 ( V_7 , 2 ) * V_3 - 1 ;
V_6 = ( V_6 > V_9 ) ? V_9 : V_6 ;
V_6 = ( V_6 < V_10 ) ? V_10 : V_6 ;
F_5 ( & V_5 -> V_11 ) ;
V_5 -> V_12 = V_6 ;
V_5 -> V_3 = F_4 ( ( V_6 + 1 ) * 2 + ( V_7 / 2 ) , V_7 ) ;
F_6 ( & V_5 -> V_11 ) ;
return 0 ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
V_7 = F_3 ( V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_11 ) ;
V_6 = F_8 ( V_5 -> V_13 + V_14 ) ;
if ( ! ( F_8 ( V_5 -> V_13 + V_15 ) & V_16 ) )
V_6 += V_5 -> V_12 + 1 ;
F_6 ( & V_5 -> V_11 ) ;
return F_4 ( V_6 , V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , bool V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_18 ;
if ( ! V_17 ) {
V_18 = F_10 ( V_5 -> V_8 ) ;
if ( V_18 ) {
F_11 ( & V_5 -> V_19 -> V_20 , L_1 ) ;
return V_18 ;
}
}
F_5 ( & V_5 -> V_11 ) ;
F_12 ( V_21 , V_5 -> V_13 + V_22 ) ;
F_12 ( V_5 -> V_12 , V_5 -> V_13 + V_23 ) ;
if ( ! V_17 ) {
F_12 ( V_16 , V_5 -> V_13 + V_24 ) ;
F_12 ( V_25 | V_26 , V_5 -> V_13 +
V_27 ) ;
}
F_12 ( V_28 , V_5 -> V_13 + V_22 ) ;
F_8 ( V_5 -> V_13 + V_22 ) ;
F_6 ( & V_5 -> V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , true ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , false ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_5 ( & V_5 -> V_11 ) ;
F_12 ( V_21 , V_5 -> V_13 + V_22 ) ;
F_12 ( 0 , V_5 -> V_13 + V_27 ) ;
F_12 ( V_28 , V_5 -> V_13 + V_22 ) ;
F_8 ( V_5 -> V_13 + V_22 ) ;
F_6 ( & V_5 -> V_11 ) ;
F_16 ( V_5 -> V_8 ) ;
return 0 ;
}
static int
F_17 ( struct V_29 * V_19 , const struct V_30 * V_31 )
{
struct V_4 * V_5 ;
int V_18 = 0 ;
if ( ! F_18 ( & V_19 -> V_20 , V_19 -> V_32 . V_33 ,
F_19 ( & V_19 -> V_32 ) , L_2 ) ) {
F_20 ( & V_19 -> V_20 , L_3 ) ;
V_18 = - V_34 ;
goto V_35;
}
V_5 = F_21 ( & V_19 -> V_20 , sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 ) {
F_20 ( & V_19 -> V_20 , L_4 ) ;
V_18 = - V_37 ;
goto V_35;
}
V_5 -> V_13 = F_22 ( & V_19 -> V_20 , V_19 -> V_32 . V_33 ,
F_19 ( & V_19 -> V_32 ) ) ;
if ( ! V_5 -> V_13 ) {
V_18 = - V_37 ;
F_20 ( & V_19 -> V_20 , L_5 ) ;
goto V_35;
}
V_5 -> V_8 = F_23 ( & V_19 -> V_20 , NULL ) ;
if ( F_24 ( V_5 -> V_8 ) ) {
F_20 ( & V_19 -> V_20 , L_6 ) ;
V_18 = F_25 ( V_5 -> V_8 ) ;
goto V_35;
}
V_5 -> V_19 = V_19 ;
V_5 -> V_2 . V_38 = & V_39 ;
V_5 -> V_2 . V_40 = & V_41 ;
F_26 ( & V_5 -> V_11 ) ;
F_27 ( & V_5 -> V_2 , V_42 ) ;
F_28 ( & V_5 -> V_2 , V_5 ) ;
F_1 ( & V_5 -> V_2 , V_43 ) ;
V_18 = F_29 ( & V_5 -> V_2 ) ;
if ( V_18 ) {
F_11 ( & V_19 -> V_20 , L_7 ,
V_18 ) ;
goto V_35;
}
F_30 ( V_19 , V_5 ) ;
F_31 ( & V_19 -> V_20 , L_8 ) ;
return 0 ;
V_35:
F_11 ( & V_19 -> V_20 , L_9 ) ;
return V_18 ;
}
static int F_32 ( struct V_29 * V_19 )
{
struct V_4 * V_5 = F_33 ( V_19 ) ;
F_34 ( & V_5 -> V_2 ) ;
F_28 ( & V_5 -> V_2 , NULL ) ;
return 0 ;
}
static int T_2 F_35 ( struct V_44 * V_20 )
{
struct V_4 * V_5 = F_36 ( V_20 ) ;
if ( F_37 ( & V_5 -> V_2 ) )
return F_15 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int T_2 F_38 ( struct V_44 * V_20 )
{
struct V_4 * V_5 = F_36 ( V_20 ) ;
if ( F_37 ( & V_5 -> V_2 ) )
return F_14 ( & V_5 -> V_2 ) ;
return 0 ;
}
