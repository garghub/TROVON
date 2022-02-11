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
F_12 ( V_23 , V_7 ) ;
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
V_4 ? : V_3 , V_3 , V_23 , V_6 , & V_3 ) ;
if ( V_25 == - V_27 )
V_25 = 0 ;
return V_25 ;
}
int F_18 ( struct V_5 * V_7 )
{
F_19 ( V_7 ) ;
if ( ! F_4 ( V_7 ) )
return - V_28 ;
if ( F_20 ( V_7 ) )
return - V_27 ;
if ( F_21 ( V_7 ) && F_22 ( V_7 ) ) {
F_23 ( V_7 ) ;
return - V_28 ;
}
F_24 ( V_7 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = F_17 ( V_1 ) ;
V_1 -> V_31 = V_32 ;
F_26 ( V_1 -> V_9 , V_33 ) ;
V_1 -> V_9 -> V_34 = & V_35 ;
V_30 -> V_36 = 0 ;
F_27 ( V_30 -> V_37 ) ;
return 0 ;
}
void F_28 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = & V_13 -> V_40 ;
struct V_29 * V_30 ;
while ( ! F_29 ( V_39 ) ) {
V_30 = F_30 ( V_39 , struct V_29 , V_41 ) ;
F_31 ( & V_30 -> V_41 ) ;
F_32 ( & V_30 -> V_42 . V_43 , 0 ) ;
F_33 ( & V_30 -> V_26 ) ;
F_34 ( & V_30 -> V_42 ) ;
}
}
