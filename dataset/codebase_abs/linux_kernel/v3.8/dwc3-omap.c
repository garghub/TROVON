static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
memset ( & V_7 , 0x00 , sizeof( V_7 ) ) ;
V_9 = F_6 ( L_1 , 0 ) ;
if ( ! V_9 )
return - V_11 ;
V_5 -> V_12 = V_9 ;
V_7 . type = V_13 ;
V_10 = F_7 ( V_5 -> V_12 , & V_7 , sizeof( V_7 ) ) ;
if ( V_10 )
goto V_14;
V_9 = F_6 ( L_1 , 1 ) ;
if ( ! V_9 ) {
V_10 = - V_11 ;
goto V_14;
}
V_5 -> V_15 = V_9 ;
V_7 . type = V_16 ;
V_10 = F_7 ( V_5 -> V_15 , & V_7 , sizeof( V_7 ) ) ;
if ( V_10 )
goto V_17;
V_10 = F_8 ( V_5 -> V_12 ) ;
if ( V_10 )
goto V_17;
V_10 = F_8 ( V_5 -> V_15 ) ;
if ( V_10 )
goto V_18;
return 0 ;
V_18:
F_9 ( V_5 -> V_12 ) ;
V_17:
F_10 ( V_5 -> V_15 ) ;
V_14:
F_10 ( V_5 -> V_12 ) ;
return V_10 ;
}
static T_3 F_11 ( int V_19 , void * V_20 )
{
struct V_4 * V_5 = V_20 ;
T_1 V_21 ;
F_12 ( & V_5 -> V_22 ) ;
V_21 = F_1 ( V_5 -> V_1 , V_23 ) ;
if ( V_21 & V_24 ) {
F_13 ( V_5 -> V_25 , L_2 ) ;
V_5 -> V_26 = false ;
}
if ( V_21 & V_27 )
F_13 ( V_5 -> V_25 , L_3 ) ;
if ( V_21 & V_28 )
F_13 ( V_5 -> V_25 , L_4 ) ;
if ( V_21 & V_29 )
F_13 ( V_5 -> V_25 , L_5 ) ;
if ( V_21 & V_30 )
F_13 ( V_5 -> V_25 , L_6 ) ;
if ( V_21 & V_31 )
F_13 ( V_5 -> V_25 , L_7 ) ;
if ( V_21 & V_32 )
F_13 ( V_5 -> V_25 , L_8 ) ;
if ( V_21 & V_33 )
F_13 ( V_5 -> V_25 , L_9 ) ;
if ( V_21 & V_34 )
F_13 ( V_5 -> V_25 , L_10 ) ;
if ( V_21 & V_35 )
F_13 ( V_5 -> V_25 , L_11 ) ;
F_3 ( V_5 -> V_1 , V_23 , V_21 ) ;
V_21 = F_1 ( V_5 -> V_1 , V_36 ) ;
F_3 ( V_5 -> V_1 , V_36 , V_21 ) ;
F_14 ( & V_5 -> V_22 ) ;
return V_37 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_38 * V_7 = V_9 -> V_25 . V_39 ;
struct V_40 * V_41 = V_9 -> V_25 . V_42 ;
struct V_8 * V_43 ;
struct V_4 * V_5 ;
struct V_44 * V_45 ;
struct V_46 * V_25 = & V_9 -> V_25 ;
int V_47 ;
int V_10 = - V_11 ;
int V_19 ;
const T_1 * V_48 ;
T_1 V_21 ;
void T_2 * V_1 ;
void * V_49 ;
V_5 = F_16 ( V_25 , sizeof( * V_5 ) , V_50 ) ;
if ( ! V_5 ) {
F_17 ( V_25 , L_12 ) ;
return - V_11 ;
}
F_18 ( V_9 , V_5 ) ;
V_19 = F_19 ( V_9 , 1 ) ;
if ( V_19 < 0 ) {
F_17 ( V_25 , L_13 ) ;
return - V_51 ;
}
V_45 = F_20 ( V_9 , V_52 , 1 ) ;
if ( ! V_45 ) {
F_17 ( V_25 , L_14 ) ;
return - V_51 ;
}
V_1 = F_21 ( V_25 , V_45 -> V_53 , F_22 ( V_45 ) ) ;
if ( ! V_1 ) {
F_17 ( V_25 , L_15 ) ;
return - V_11 ;
}
V_10 = F_5 ( V_5 ) ;
if ( V_10 ) {
F_17 ( V_25 , L_16 ) ;
return V_10 ;
}
V_43 = F_6 ( L_17 , V_54 ) ;
if ( ! V_43 ) {
F_17 ( V_25 , L_18 ) ;
return - V_11 ;
}
V_49 = F_16 ( V_25 , F_22 ( V_45 ) , V_50 ) ;
if ( ! V_49 ) {
F_17 ( V_25 , L_19 ) ;
goto V_17;
}
F_23 ( & V_5 -> V_22 ) ;
F_24 ( & V_43 -> V_25 , V_25 -> V_55 ) ;
V_43 -> V_25 . V_56 = V_25 ;
V_43 -> V_25 . V_57 = V_25 -> V_57 ;
V_43 -> V_25 . V_58 = V_25 -> V_58 ;
V_5 -> F_22 = F_22 ( V_45 ) ;
V_5 -> V_49 = V_49 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_43 = V_43 ;
V_21 = F_1 ( V_5 -> V_1 , V_59 ) ;
V_48 = F_25 ( V_41 , L_20 , & V_47 ) ;
if ( V_48 && V_47 == sizeof( * V_48 ) ) {
V_21 |= * V_48 ;
} else {
if ( ! V_7 ) {
F_13 ( V_25 , L_21 ) ;
} else {
switch ( V_7 -> V_48 ) {
case V_60 :
V_21 |= V_61 ;
break;
case V_62 :
V_21 &= ~ V_61 ;
break;
default:
F_13 ( V_25 , L_22 ,
V_7 -> V_48 ) ;
}
}
}
F_3 ( V_5 -> V_1 , V_59 , V_21 ) ;
V_21 = F_1 ( V_5 -> V_1 , V_63 ) ;
V_5 -> V_26 = ! ! ( V_21 & V_64 ) ;
V_21 &= ~ ( V_65
| V_66 ) ;
V_21 |= ( F_26 ( V_67 )
| F_27 ( V_68 ) ) ;
F_3 ( V_5 -> V_1 , V_63 , V_21 ) ;
V_10 = F_28 ( V_25 , V_5 -> V_19 , F_11 , 0 ,
L_23 , V_5 ) ;
if ( V_10 ) {
F_17 ( V_25 , L_24 ,
V_5 -> V_19 , V_10 ) ;
goto V_17;
}
V_21 = V_69 ;
F_3 ( V_5 -> V_1 , V_70 , V_21 ) ;
V_21 = ( V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ) ;
F_3 ( V_5 -> V_1 , V_71 , V_21 ) ;
V_10 = F_29 ( V_43 , V_9 -> V_44 ,
V_9 -> V_72 ) ;
if ( V_10 ) {
F_17 ( V_25 , L_25 ) ;
goto V_17;
}
V_10 = F_8 ( V_43 ) ;
if ( V_10 ) {
F_17 ( V_25 , L_26 ) ;
goto V_17;
}
return 0 ;
V_17:
F_10 ( V_43 ) ;
return V_10 ;
}
static int F_30 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = F_31 ( V_9 ) ;
F_32 ( V_5 -> V_43 ) ;
F_32 ( V_5 -> V_12 ) ;
F_32 ( V_5 -> V_15 ) ;
return 0 ;
}
