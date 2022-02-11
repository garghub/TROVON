static void F_1 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 0 ;
if ( clock == 0 ) {
if ( V_4 -> V_6 ) {
F_3 ( V_4 -> V_7 ) ;
V_4 -> V_6 = 0 ;
}
} else {
if ( 0 == V_4 -> V_6 ) {
if ( V_4 -> V_8 -> V_9 & V_10 ) {
V_5 = F_4 ( V_2 -> V_11 + V_12 ) ;
V_5 |= V_13 ;
F_5 ( V_5 , V_2 -> V_11 + V_12 ) ;
}
V_6 ( V_4 -> V_7 ) ;
V_4 -> V_6 = 1 ;
}
}
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_2 V_15 ;
V_15 = F_7 ( V_2 , V_16 ) ;
V_15 &= ~ V_17 ;
switch ( V_14 ) {
case V_18 :
V_15 |= V_19 ;
break;
case V_20 :
V_15 |= V_21 ;
break;
case V_22 :
V_15 |= V_23 | V_24 ;
break;
case V_25 :
V_15 |= V_26 | V_24 ;
break;
case V_27 :
V_15 |= V_28 | V_24 ;
break;
}
F_8 ( V_2 , V_15 , V_16 ) ;
F_9 ( L_1 ,
V_29 , F_10 ( V_2 -> V_30 ) , V_14 , V_15 ) ;
return 0 ;
}
static int T_3 F_11 ( struct V_31 * V_32 )
{
struct V_33 * V_8 = V_32 -> V_34 . V_35 ;
struct V_36 * V_34 = & V_32 -> V_34 ;
struct V_1 * V_2 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_3 * V_4 = NULL ;
int V_39 , V_40 ;
V_40 = F_12 ( V_32 , 0 ) ;
if ( V_40 < 0 ) {
F_13 ( V_34 , L_2 ) ;
return V_40 ;
}
V_38 = F_14 ( V_32 , V_41 , 0 ) ;
if ( ! V_38 ) {
F_13 ( V_34 , L_3 ) ;
return - V_42 ;
}
V_2 = F_15 ( & V_32 -> V_34 , sizeof( struct V_3 ) ) ;
if ( F_16 ( V_2 ) ) {
F_13 ( V_34 , L_4 ) ;
return F_17 ( V_2 ) ;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = F_18 ( V_34 , L_5 ) ;
if ( F_16 ( V_4 -> V_7 ) ) {
F_13 ( V_34 , L_6 ) ;
V_39 = F_17 ( V_4 -> V_7 ) ;
goto V_43;
}
V_4 -> V_44 = F_19 ( V_38 -> V_45 , F_20 ( V_38 ) ,
F_10 ( V_2 -> V_30 ) ) ;
if ( ! V_4 -> V_44 ) {
F_13 ( & V_32 -> V_34 , L_7 ) ;
V_39 = - V_46 ;
goto V_43;
}
V_2 -> V_11 = F_21 ( V_38 -> V_45 , F_20 ( V_38 ) ) ;
if ( ! V_2 -> V_11 ) {
F_13 ( & V_32 -> V_34 , L_8 ) ;
V_39 = - V_47 ;
goto V_43;
}
V_2 -> V_48 = L_9 ;
V_2 -> V_49 = & V_50 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_51 = V_52
| V_53
| V_54
| V_55
| V_56
| V_57 ;
if ( V_8 -> V_51 )
V_2 -> V_51 |= V_8 -> V_51 ;
V_2 -> V_30 -> V_58 |= V_59 ;
if ( V_8 -> V_9 & V_60 )
V_2 -> V_30 -> V_58 |= V_61 ;
V_39 = F_22 ( V_2 ) ;
if ( V_39 ) {
F_13 ( & V_32 -> V_34 , L_10 ) ;
goto V_43;
}
if ( V_4 -> V_8 -> V_62 )
V_2 -> V_30 -> V_63 = V_4 -> V_8 -> V_62 ;
F_23 ( V_32 , V_2 ) ;
return 0 ;
V_43:
if ( V_2 ) {
F_24 ( V_4 -> V_7 ) ;
if ( V_2 -> V_11 )
F_25 ( V_2 -> V_11 ) ;
if ( V_4 -> V_44 )
F_26 ( V_4 -> V_44 -> V_45 ,
F_20 ( V_4 -> V_44 ) ) ;
F_27 ( V_2 ) ;
}
return V_39 ;
}
static int T_4 F_28 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_29 ( V_32 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_64 = 0 ;
T_1 V_65 ;
if ( V_2 ) {
V_65 = F_4 ( V_2 -> V_11 + V_66 ) ;
if ( V_65 == ( T_1 ) - 1 )
V_64 = 1 ;
F_30 ( V_2 , V_64 ) ;
if ( V_2 -> V_11 )
F_25 ( V_2 -> V_11 ) ;
if ( V_4 -> V_44 )
F_26 ( V_4 -> V_44 -> V_45 ,
F_20 ( V_4 -> V_44 ) ) ;
if ( V_4 -> V_6 ) {
F_3 ( V_4 -> V_7 ) ;
V_4 -> V_6 = 0 ;
}
F_24 ( V_4 -> V_7 ) ;
F_27 ( V_2 ) ;
F_23 ( V_32 , NULL ) ;
}
return 0 ;
}
static int F_31 ( struct V_31 * V_34 , T_5 V_67 )
{
struct V_1 * V_2 = F_29 ( V_34 ) ;
return F_32 ( V_2 , V_67 ) ;
}
static int F_33 ( struct V_31 * V_34 )
{
struct V_1 * V_2 = F_29 ( V_34 ) ;
return F_34 ( V_2 ) ;
}
static int T_6 F_35 ( void )
{
return F_36 ( & V_68 ) ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_68 ) ;
}
