static int F_1 ( void * V_1 , int * V_2 )
{
void T_1 * V_3 ;
struct V_4 * V_5 = V_1 ;
T_2 V_6 ;
int V_7 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
V_3 = V_5 -> V_3 ;
F_2 ( & V_5 -> V_10 ) ;
F_3 ( V_11 ,
V_3 + V_12 ) ;
F_3 ( V_13 , V_3 + V_14 ) ;
V_6 = F_4 ( V_3 + V_15 ) ;
V_6 &= ~ V_16 ;
V_6 |= V_17 ;
F_3 ( V_6 , V_3 + V_15 ) ;
F_5 ( 100 , 300 ) ;
V_7 = F_6 ( V_18 , V_3 + V_19 ,
V_6 , V_6 & V_20 , 300 ,
V_21 ) ;
if ( V_7 ) {
F_7 ( V_5 -> V_22 , L_1 ) ;
goto V_23;
}
F_3 ( V_24 | V_13 ,
V_3 + V_14 ) ;
V_6 = F_4 ( V_3 + V_19 )
& V_25 ;
F_3 ( V_26 ,
V_3 + V_12 ) ;
* V_2 = F_8 ( ( ( V_27 ) V_6 + V_5 -> V_8 -> V_28 -> V_29 ) * 1000 ,
V_5 -> V_8 -> V_28 -> V_30 ) ;
V_23:
F_9 ( & V_5 -> V_10 ) ;
return V_7 ;
}
static int F_10 ( struct V_31 * V_32 )
{
struct V_4 * V_5 ;
struct V_33 * V_34 ;
int V_7 ;
V_5 = F_11 ( & V_32 -> V_22 , sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_34 = F_12 ( V_32 , V_37 , 0 ) ;
V_5 -> V_3 = F_13 ( & V_32 -> V_22 , V_34 ) ;
if ( F_14 ( V_5 -> V_3 ) )
return F_15 ( V_5 -> V_3 ) ;
V_5 -> V_38 = F_16 ( & V_32 -> V_22 , L_2 ) ;
if ( F_14 ( V_5 -> V_38 ) ) {
V_7 = F_15 ( V_5 -> V_38 ) ;
F_7 ( & V_32 -> V_22 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_5 -> V_38 ) ;
if ( V_7 ) {
F_7 ( & V_32 -> V_22 , L_4 ,
V_7 ) ;
return V_7 ;
}
V_5 -> V_39 = F_16 ( & V_32 -> V_22 , L_5 ) ;
if ( F_14 ( V_5 -> V_39 ) ) {
V_7 = F_15 ( V_5 -> V_39 ) ;
F_7 ( & V_32 -> V_22 , L_6 , V_7 ) ;
goto V_40;
}
V_7 = F_17 ( V_5 -> V_39 ) ;
if ( V_7 ) {
F_7 ( & V_32 -> V_22 , L_7 ,
V_7 ) ;
goto V_40;
}
F_18 ( & V_5 -> V_10 ) ;
V_5 -> V_8 = F_19 ( & V_32 -> V_22 ,
0 , V_5 , & V_41 ) ;
if ( F_14 ( V_5 -> V_8 ) ) {
V_7 = F_15 ( V_5 -> V_8 ) ;
F_7 ( & V_32 -> V_22 , L_8 , V_7 ) ;
goto V_42;
}
if ( V_5 -> V_8 -> V_28 -> V_30 == 0 ) {
F_20 ( & V_32 -> V_22 , V_5 -> V_8 ) ;
F_7 ( & V_32 -> V_22 , L_9 ) ;
V_7 = - V_43 ;
goto V_42;
}
V_5 -> V_22 = & V_32 -> V_22 ;
F_21 ( V_32 , V_5 ) ;
return 0 ;
V_42:
F_22 ( V_5 -> V_39 ) ;
V_40:
F_22 ( V_5 -> V_38 ) ;
return V_7 ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_24 ( V_32 ) ;
F_20 ( & V_32 -> V_22 , V_5 -> V_8 ) ;
F_22 ( V_5 -> V_38 ) ;
F_22 ( V_5 -> V_39 ) ;
return 0 ;
}
static int F_25 ( struct V_44 * V_22 )
{
struct V_31 * V_32 = F_26 ( V_22 ) ;
struct V_4 * V_5 = F_24 ( V_32 ) ;
if ( V_5 && V_5 -> V_38 )
F_22 ( V_5 -> V_38 ) ;
if ( V_5 && V_5 -> V_39 )
F_22 ( V_5 -> V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_44 * V_22 )
{
struct V_31 * V_32 = F_26 ( V_22 ) ;
struct V_4 * V_5 = F_24 ( V_32 ) ;
int error ;
error = F_17 ( V_5 -> V_38 ) ;
if ( error )
return error ;
error = F_17 ( V_5 -> V_39 ) ;
if ( error ) {
F_22 ( V_5 -> V_38 ) ;
return error ;
}
return 0 ;
}
