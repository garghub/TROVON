static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
void F_5 ( enum V_4 V_5 )
{
T_1 V_6 ;
struct V_7 * V_8 = V_9 ;
switch ( V_5 ) {
case V_10 :
F_6 ( V_8 -> V_11 , L_1 ) ;
V_6 = F_1 ( V_8 -> V_1 , V_12 ) ;
V_6 &= ~ ( V_13
| V_14
| V_15 ) ;
V_6 |= V_16
| V_17 ;
F_3 ( V_8 -> V_1 , V_12 , V_6 ) ;
break;
case V_18 :
F_6 ( V_8 -> V_11 , L_2 ) ;
V_6 = F_1 ( V_8 -> V_1 , V_12 ) ;
V_6 &= ~ V_15 ;
V_6 |= V_13
| V_14
| V_16
| V_17 ;
F_3 ( V_8 -> V_1 , V_12 , V_6 ) ;
break;
case V_19 :
case V_20 :
F_6 ( V_8 -> V_11 , L_3 ) ;
V_6 = F_1 ( V_8 -> V_1 , V_12 ) ;
V_6 &= ~ ( V_16
| V_14
| V_17 ) ;
V_6 |= V_15
| V_13 ;
F_3 ( V_8 -> V_1 , V_12 , V_6 ) ;
break;
default:
F_6 ( V_8 -> V_11 , L_4 ) ;
}
return;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_21 V_22 ;
struct V_23 * V_24 ;
int V_25 ;
memset ( & V_22 , 0x00 , sizeof( V_22 ) ) ;
V_24 = F_8 ( L_5 , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
V_8 -> V_28 = V_24 ;
V_22 . type = V_29 ;
V_25 = F_9 ( V_8 -> V_28 , & V_22 , sizeof( V_22 ) ) ;
if ( V_25 )
goto V_30;
V_24 = F_8 ( L_5 , V_26 ) ;
if ( ! V_24 ) {
V_25 = - V_27 ;
goto V_30;
}
V_8 -> V_31 = V_24 ;
V_22 . type = V_32 ;
V_25 = F_9 ( V_8 -> V_31 , & V_22 , sizeof( V_22 ) ) ;
if ( V_25 )
goto V_33;
V_25 = F_10 ( V_8 -> V_28 ) ;
if ( V_25 )
goto V_33;
V_25 = F_10 ( V_8 -> V_31 ) ;
if ( V_25 )
goto V_34;
return 0 ;
V_34:
F_11 ( V_8 -> V_28 ) ;
V_33:
F_12 ( V_8 -> V_31 ) ;
V_30:
F_12 ( V_8 -> V_28 ) ;
return V_25 ;
}
static T_3 F_13 ( int V_35 , void * V_9 )
{
struct V_7 * V_8 = V_9 ;
T_1 V_36 ;
F_14 ( & V_8 -> V_37 ) ;
V_36 = F_1 ( V_8 -> V_1 , V_38 ) ;
if ( V_36 & V_39 ) {
F_6 ( V_8 -> V_11 , L_6 ) ;
V_8 -> V_40 = false ;
}
if ( V_36 & V_41 )
F_6 ( V_8 -> V_11 , L_7 ) ;
if ( V_36 & V_42 )
F_6 ( V_8 -> V_11 , L_8 ) ;
if ( V_36 & V_43 )
F_6 ( V_8 -> V_11 , L_9 ) ;
if ( V_36 & V_44 )
F_6 ( V_8 -> V_11 , L_10 ) ;
if ( V_36 & V_45 )
F_6 ( V_8 -> V_11 , L_11 ) ;
if ( V_36 & V_46 )
F_6 ( V_8 -> V_11 , L_12 ) ;
if ( V_36 & V_47 )
F_6 ( V_8 -> V_11 , L_13 ) ;
if ( V_36 & V_48 )
F_6 ( V_8 -> V_11 , L_14 ) ;
if ( V_36 & V_49 )
F_6 ( V_8 -> V_11 , L_15 ) ;
F_3 ( V_8 -> V_1 , V_38 , V_36 ) ;
V_36 = F_1 ( V_8 -> V_1 , V_50 ) ;
F_3 ( V_8 -> V_1 , V_50 , V_36 ) ;
F_15 ( & V_8 -> V_37 ) ;
return V_51 ;
}
static int F_16 ( struct V_52 * V_11 , void * V_53 )
{
struct V_23 * V_24 = F_17 ( V_11 ) ;
F_18 ( V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 )
{
struct V_54 * V_22 = V_24 -> V_11 . V_55 ;
struct V_56 * V_57 = V_24 -> V_11 . V_58 ;
struct V_7 * V_8 ;
struct V_59 * V_60 ;
struct V_52 * V_11 = & V_24 -> V_11 ;
int V_61 ;
int V_25 = - V_27 ;
int V_35 ;
const T_1 * V_62 ;
T_1 V_36 ;
void T_2 * V_1 ;
void * V_63 ;
V_8 = F_20 ( V_11 , sizeof( * V_8 ) , V_64 ) ;
if ( ! V_8 ) {
F_21 ( V_11 , L_16 ) ;
return - V_27 ;
}
F_22 ( V_24 , V_8 ) ;
V_35 = F_23 ( V_24 , 1 ) ;
if ( V_35 < 0 ) {
F_21 ( V_11 , L_17 ) ;
return - V_65 ;
}
V_60 = F_24 ( V_24 , V_66 , 1 ) ;
if ( ! V_60 ) {
F_21 ( V_11 , L_18 ) ;
return - V_65 ;
}
V_1 = F_25 ( V_11 , V_60 -> V_67 , F_26 ( V_60 ) ) ;
if ( ! V_1 ) {
F_21 ( V_11 , L_19 ) ;
return - V_27 ;
}
V_25 = F_7 ( V_8 ) ;
if ( V_25 ) {
F_21 ( V_11 , L_20 ) ;
return V_25 ;
}
V_63 = F_20 ( V_11 , F_26 ( V_60 ) , V_64 ) ;
if ( ! V_63 ) {
F_21 ( V_11 , L_21 ) ;
return - V_27 ;
}
F_27 ( & V_8 -> V_37 ) ;
V_8 -> F_26 = F_26 ( V_60 ) ;
V_8 -> V_63 = V_63 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_35 = V_35 ;
V_8 -> V_1 = V_1 ;
V_9 = V_8 ;
F_28 ( V_11 ) ;
V_25 = F_29 ( V_11 ) ;
if ( V_25 < 0 ) {
F_21 ( V_11 , L_22 , V_25 ) ;
return V_25 ;
}
V_36 = F_1 ( V_8 -> V_1 , V_12 ) ;
V_62 = F_30 ( V_57 , L_23 , & V_61 ) ;
if ( V_62 && V_61 == sizeof( * V_62 ) ) {
V_36 |= * V_62 ;
} else {
if ( ! V_22 ) {
F_6 ( V_11 , L_24 ) ;
} else {
switch ( V_22 -> V_62 ) {
case V_68 :
V_36 |= V_69 ;
break;
case V_70 :
V_36 &= ~ V_69 ;
break;
default:
F_6 ( V_11 , L_25 ,
V_22 -> V_62 ) ;
}
}
}
F_3 ( V_8 -> V_1 , V_12 , V_36 ) ;
V_36 = F_1 ( V_8 -> V_1 , V_71 ) ;
V_8 -> V_40 = ! ! ( V_36 & V_72 ) ;
V_25 = F_31 ( V_11 , V_8 -> V_35 , F_13 , 0 ,
L_26 , V_8 ) ;
if ( V_25 ) {
F_21 ( V_11 , L_27 ,
V_8 -> V_35 , V_25 ) ;
return V_25 ;
}
V_36 = V_73 ;
F_3 ( V_8 -> V_1 , V_74 , V_36 ) ;
V_36 = ( V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 |
V_47 |
V_48 |
V_49 ) ;
F_3 ( V_8 -> V_1 , V_75 , V_36 ) ;
if ( V_57 ) {
V_25 = F_32 ( V_57 , NULL , NULL , V_11 ) ;
if ( V_25 ) {
F_21 ( & V_24 -> V_11 ,
L_28 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_33 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_34 ( V_24 ) ;
F_18 ( V_8 -> V_28 ) ;
F_18 ( V_8 -> V_31 ) ;
F_35 ( & V_24 -> V_11 ) ;
F_36 ( & V_24 -> V_11 ) ;
F_37 ( & V_24 -> V_11 , NULL , F_16 ) ;
return 0 ;
}
