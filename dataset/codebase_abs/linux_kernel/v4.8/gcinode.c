int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 , T_2 V_4 ,
struct V_5 * * V_6 )
{
struct V_5 * V_7 ;
int V_8 ;
V_7 = F_2 ( V_1 , V_1 -> V_9 , V_2 , 0 ) ;
if ( F_3 ( ! V_7 ) )
return - V_10 ;
if ( F_4 ( V_7 ) )
goto V_11;
if ( V_3 == 0 ) {
struct V_12 * V_13 = V_1 -> V_14 -> V_15 ;
V_8 = F_5 ( V_13 -> V_16 , V_4 , & V_3 ) ;
if ( F_3 ( V_8 ) ) {
F_6 ( V_7 ) ;
goto V_17;
}
}
F_7 ( V_7 ) ;
if ( F_4 ( V_7 ) ) {
F_8 ( V_7 ) ;
goto V_11;
}
if ( ! F_9 ( V_7 ) ) {
V_7 -> V_18 = V_1 -> V_14 -> V_19 ;
F_10 ( V_7 ) ;
}
V_7 -> V_20 = V_3 ;
V_7 -> V_21 = V_22 ;
F_11 ( V_7 ) ;
F_12 ( V_23 , 0 , V_7 ) ;
if ( V_4 )
V_7 -> V_20 = V_4 ;
V_11:
V_8 = 0 ;
* V_6 = V_7 ;
V_17:
F_13 ( V_7 -> V_24 ) ;
F_14 ( V_7 -> V_24 ) ;
return V_8 ;
}
int F_15 ( struct V_1 * V_1 , T_1 V_3 ,
T_2 V_4 , struct V_5 * * V_6 )
{
int V_25 ;
V_25 = F_16 ( & F_17 ( V_1 ) -> V_26 ,
V_4 ? : V_3 , V_3 , V_23 , 0 ,
V_6 , & V_3 ) ;
if ( V_25 == - V_27 )
V_25 = 0 ;
return V_25 ;
}
int F_18 ( struct V_5 * V_7 )
{
F_19 ( V_7 ) ;
if ( ! F_4 ( V_7 ) ) {
struct V_1 * V_1 = V_7 -> V_24 -> V_28 -> V_29 ;
F_20 ( V_1 -> V_14 , V_30 ,
L_1 ,
F_21 ( V_7 ) ? L_2 : L_3 ,
V_1 -> V_31 , ( unsigned long long ) V_7 -> V_20 ) ;
return - V_32 ;
}
if ( F_22 ( V_7 ) )
return - V_27 ;
if ( F_21 ( V_7 ) && F_23 ( V_7 ) ) {
F_24 ( V_7 ) ;
return - V_32 ;
}
F_25 ( V_7 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_1 )
{
struct V_33 * V_34 = F_17 ( V_1 ) ;
V_1 -> V_35 = V_36 ;
F_27 ( V_1 -> V_9 , V_37 ) ;
V_1 -> V_9 -> V_38 = & V_39 ;
V_34 -> V_40 = 0 ;
F_28 ( V_34 -> V_41 ) ;
return 0 ;
}
void F_29 ( struct V_12 * V_13 )
{
struct V_42 * V_43 = & V_13 -> V_44 ;
struct V_33 * V_34 ;
while ( ! F_30 ( V_43 ) ) {
V_34 = F_31 ( V_43 , struct V_33 , V_45 ) ;
F_32 ( & V_34 -> V_45 ) ;
F_33 ( & V_34 -> V_46 . V_47 , 0 ) ;
F_34 ( & V_34 -> V_26 ) ;
F_35 ( & V_34 -> V_46 ) ;
}
}
