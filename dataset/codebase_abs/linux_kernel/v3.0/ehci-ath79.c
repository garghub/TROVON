static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 -> V_7 . V_8 ) ;
const struct V_9 * V_10 ;
int V_11 ;
V_10 = F_4 ( V_6 ) ;
if ( ! V_10 ) {
F_5 ( V_2 -> V_7 . V_8 , L_1 ) ;
return - V_12 ;
}
switch ( V_10 -> V_13 ) {
case V_14 :
V_4 -> V_15 = 1 ;
V_4 -> V_16 = V_2 -> V_17 ;
V_4 -> V_17 = V_2 -> V_17 +
F_6 ( V_4 ,
F_7 ( V_4 , & V_4 -> V_16 -> V_18 ) ) ;
break;
case V_19 :
V_2 -> V_20 = 1 ;
V_4 -> V_16 = V_2 -> V_17 + 0x100 ;
V_4 -> V_17 = V_2 -> V_17 + 0x100 +
F_6 ( V_4 ,
F_7 ( V_4 , & V_4 -> V_16 -> V_18 ) ) ;
break;
default:
F_8 () ;
}
F_9 ( V_4 , L_2 ) ;
F_10 ( V_4 , L_2 ) ;
V_4 -> V_21 = F_7 ( V_4 , & V_4 -> V_16 -> V_21 ) ;
V_4 -> V_22 = 0x20 ;
F_11 ( V_4 ) ;
V_11 = F_12 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_13 ( V_4 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_25 ;
int V_11 ;
if ( F_15 () )
return - V_26 ;
V_24 = F_16 ( V_6 , V_27 , 0 ) ;
if ( ! V_24 ) {
F_17 ( & V_6 -> V_28 , L_3 ) ;
return - V_26 ;
}
V_25 = V_24 -> V_29 ;
V_24 = F_16 ( V_6 , V_30 , 0 ) ;
if ( ! V_24 ) {
F_17 ( & V_6 -> V_28 , L_4 ) ;
return - V_26 ;
}
V_2 = F_18 ( & V_31 , & V_6 -> V_28 ,
F_19 ( & V_6 -> V_28 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_33 = V_24 -> V_29 ;
V_2 -> V_34 = V_24 -> V_35 - V_24 -> V_29 + 1 ;
if ( ! F_20 ( V_2 -> V_33 , V_2 -> V_34 , V_36 ) ) {
F_17 ( & V_6 -> V_28 , L_5 ) ;
V_11 = - V_37 ;
goto V_38;
}
V_2 -> V_17 = F_21 ( V_2 -> V_33 , V_2 -> V_34 ) ;
if ( ! V_2 -> V_17 ) {
F_17 ( & V_6 -> V_28 , L_6 ) ;
V_11 = - V_39 ;
goto V_40;
}
V_11 = F_22 ( V_2 , V_25 , V_41 | V_42 ) ;
if ( V_11 )
goto V_43;
return 0 ;
V_43:
F_23 ( V_2 -> V_17 ) ;
V_40:
F_24 ( V_2 -> V_33 , V_2 -> V_34 ) ;
V_38:
F_25 ( V_2 ) ;
return V_11 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_27 ( V_6 ) ;
F_28 ( V_2 ) ;
F_23 ( V_2 -> V_17 ) ;
F_24 ( V_2 -> V_33 , V_2 -> V_34 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
