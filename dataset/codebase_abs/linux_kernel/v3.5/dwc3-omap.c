static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static T_3 F_5 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
T_1 V_8 ;
F_6 ( & V_7 -> V_9 ) ;
V_8 = F_1 ( V_7 -> V_1 , V_10 ) ;
if ( V_8 & V_11 ) {
F_7 ( V_7 -> V_12 , L_1 ) ;
V_7 -> V_13 = false ;
}
if ( V_8 & V_14 )
F_7 ( V_7 -> V_12 , L_2 ) ;
if ( V_8 & V_15 )
F_7 ( V_7 -> V_12 , L_3 ) ;
if ( V_8 & V_16 )
F_7 ( V_7 -> V_12 , L_4 ) ;
if ( V_8 & V_17 )
F_7 ( V_7 -> V_12 , L_5 ) ;
if ( V_8 & V_18 )
F_7 ( V_7 -> V_12 , L_6 ) ;
if ( V_8 & V_19 )
F_7 ( V_7 -> V_12 , L_7 ) ;
if ( V_8 & V_20 )
F_7 ( V_7 -> V_12 , L_8 ) ;
if ( V_8 & V_21 )
F_7 ( V_7 -> V_12 , L_9 ) ;
if ( V_8 & V_22 )
F_7 ( V_7 -> V_12 , L_10 ) ;
F_3 ( V_7 -> V_1 , V_10 , V_8 ) ;
V_8 = F_1 ( V_7 -> V_1 , V_23 ) ;
F_3 ( V_7 -> V_1 , V_23 , V_8 ) ;
F_8 ( & V_7 -> V_9 ) ;
return V_24 ;
}
static int T_4 F_9 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_12 . V_29 ;
struct V_30 * V_31 = V_26 -> V_12 . V_32 ;
struct V_25 * V_33 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
struct V_36 * V_12 = & V_26 -> V_12 ;
int V_37 ;
int V_38 ;
int V_39 = - V_40 ;
int V_4 ;
const T_1 * V_41 ;
T_1 V_8 ;
void T_2 * V_1 ;
void * V_42 ;
V_7 = F_10 ( V_12 , sizeof( * V_7 ) , V_43 ) ;
if ( ! V_7 ) {
F_11 ( V_12 , L_11 ) ;
return - V_40 ;
}
F_12 ( V_26 , V_7 ) ;
V_4 = F_13 ( V_26 , 1 ) ;
if ( V_4 < 0 ) {
F_11 ( V_12 , L_12 ) ;
return - V_44 ;
}
V_35 = F_14 ( V_26 , V_45 , 1 ) ;
if ( ! V_35 ) {
F_11 ( V_12 , L_13 ) ;
return - V_44 ;
}
V_1 = F_15 ( V_12 , V_35 -> V_46 , F_16 ( V_35 ) ) ;
if ( ! V_1 ) {
F_11 ( V_12 , L_14 ) ;
return - V_40 ;
}
V_37 = F_17 () ;
if ( V_37 < 0 )
return - V_47 ;
V_33 = F_18 ( L_15 , V_37 ) ;
if ( ! V_33 ) {
F_11 ( V_12 , L_16 ) ;
goto V_48;
}
V_42 = F_10 ( V_12 , F_16 ( V_35 ) , V_43 ) ;
if ( ! V_42 ) {
F_11 ( V_12 , L_17 ) ;
goto V_49;
}
F_19 ( & V_7 -> V_9 ) ;
F_20 ( & V_33 -> V_12 , V_12 -> V_50 ) ;
V_33 -> V_12 . V_51 = V_12 ;
V_33 -> V_12 . V_52 = V_12 -> V_52 ;
V_33 -> V_12 . V_53 = V_12 -> V_53 ;
V_7 -> F_16 = F_16 ( V_35 ) ;
V_7 -> V_42 = V_42 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_1 = V_1 ;
V_7 -> V_33 = V_33 ;
V_8 = F_1 ( V_7 -> V_1 , V_54 ) ;
V_41 = F_21 ( V_31 , L_18 , & V_38 ) ;
if ( V_41 && V_38 == sizeof( * V_41 ) ) {
V_8 |= * V_41 ;
} else {
if ( ! V_28 ) {
F_7 ( V_12 , L_19 ) ;
} else {
switch ( V_28 -> V_41 ) {
case V_55 :
V_8 |= V_56 ;
break;
case V_57 :
V_8 &= ~ V_56 ;
break;
default:
F_7 ( V_12 , L_20 ,
V_28 -> V_41 ) ;
}
}
}
F_3 ( V_7 -> V_1 , V_54 , V_8 ) ;
V_8 = F_1 ( V_7 -> V_1 , V_58 ) ;
V_7 -> V_13 = ! ! ( V_8 & V_59 ) ;
V_8 &= ~ ( V_60
| V_61 ) ;
V_8 |= ( F_22 ( V_62 )
| F_23 ( V_63 ) ) ;
F_3 ( V_7 -> V_1 , V_58 , V_8 ) ;
V_39 = F_24 ( V_12 , V_7 -> V_4 , F_5 , 0 ,
L_21 , V_7 ) ;
if ( V_39 ) {
F_11 ( V_12 , L_22 ,
V_7 -> V_4 , V_39 ) ;
goto V_49;
}
V_8 = V_64 ;
F_3 ( V_7 -> V_1 , V_65 , V_8 ) ;
V_8 = ( V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 ) ;
F_3 ( V_7 -> V_1 , V_66 , V_8 ) ;
V_39 = F_25 ( V_33 , V_26 -> V_34 ,
V_26 -> V_67 ) ;
if ( V_39 ) {
F_11 ( V_12 , L_23 ) ;
goto V_49;
}
V_39 = F_26 ( V_33 ) ;
if ( V_39 ) {
F_11 ( V_12 , L_24 ) ;
goto V_49;
}
return 0 ;
V_49:
F_27 ( V_33 ) ;
V_48:
F_28 ( V_37 ) ;
return V_39 ;
}
static int T_5 F_29 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = F_30 ( V_26 ) ;
F_31 ( V_7 -> V_33 ) ;
F_28 ( V_7 -> V_33 -> V_68 ) ;
return 0 ;
}
