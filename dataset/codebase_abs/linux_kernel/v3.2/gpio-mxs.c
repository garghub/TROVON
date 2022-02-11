static int F_1 ( struct V_1 * V_2 , unsigned int type )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
T_1 V_5 = 1 << ( V_3 & 31 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
void T_2 * V_11 ;
int V_12 ;
switch ( type ) {
case V_13 :
V_12 = V_14 ;
break;
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
V_12 = V_18 ;
break;
case V_19 :
V_12 = V_20 ;
break;
default:
return - V_21 ;
}
V_11 = V_9 -> V_22 + F_4 ( V_9 -> V_23 ) ;
if ( V_12 & V_24 )
F_5 ( V_5 , V_11 + V_25 ) ;
else
F_5 ( V_5 , V_11 + V_26 ) ;
V_11 = V_9 -> V_22 + F_6 ( V_9 -> V_23 ) ;
if ( V_12 & V_27 )
F_5 ( V_5 , V_11 + V_25 ) ;
else
F_5 ( V_5 , V_11 + V_26 ) ;
F_5 ( 1 << ( V_3 & 0x1f ) ,
V_9 -> V_22 + F_7 ( V_9 -> V_23 ) + V_26 ) ;
return 0 ;
}
static void F_8 ( T_1 V_4 , struct V_28 * V_29 )
{
T_1 V_30 ;
struct V_8 * V_9 = F_9 ( V_4 ) ;
T_1 V_31 = V_9 -> V_32 ;
V_29 -> V_1 . V_33 -> V_34 ( & V_29 -> V_1 ) ;
V_30 = F_10 ( V_9 -> V_22 + F_7 ( V_9 -> V_23 ) ) &
F_10 ( V_9 -> V_22 + F_11 ( V_9 -> V_23 ) ) ;
while ( V_30 != 0 ) {
int V_35 = F_12 ( V_30 ) - 1 ;
F_13 ( V_31 + V_35 ) ;
V_30 &= ~ ( 1 << V_35 ) ;
}
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_36 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_36 )
F_15 ( V_9 -> V_4 ) ;
else
F_16 ( V_9 -> V_4 ) ;
return 0 ;
}
static void T_3 F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
V_7 = F_18 ( L_1 , 1 , V_9 -> V_32 ,
V_9 -> V_22 , V_39 ) ;
V_7 -> V_10 = V_9 ;
V_38 = V_7 -> V_40 ;
V_38 -> V_33 . V_34 = V_41 ;
V_38 -> V_33 . V_42 = V_43 ;
V_38 -> V_33 . V_44 = V_45 ;
V_38 -> V_33 . V_46 = F_1 ;
V_38 -> V_33 . V_47 = F_14 ;
V_38 -> V_48 . V_49 = F_7 ( V_9 -> V_23 ) + V_26 ;
V_38 -> V_48 . V_50 = F_11 ( V_9 -> V_23 ) ;
F_19 ( V_7 , F_20 ( 32 ) , 0 , V_51 , 0 ) ;
}
static int F_21 ( struct V_52 * V_7 , unsigned V_53 )
{
struct V_54 * V_55 = F_22 ( V_7 ) ;
struct V_8 * V_9 =
F_23 ( V_55 , struct V_8 , V_55 ) ;
return V_9 -> V_32 + V_53 ;
}
static int T_4 F_24 ( struct V_56 * V_57 )
{
static void T_2 * V_22 ;
struct V_8 * V_9 ;
struct V_58 * V_59 = NULL ;
int V_60 ;
V_9 = F_25 ( sizeof( struct V_8 ) , V_61 ) ;
if ( ! V_9 )
return - V_62 ;
V_9 -> V_23 = V_57 -> V_23 ;
V_9 -> V_32 = V_63 + V_9 -> V_23 * 32 ;
if ( ! V_22 ) {
V_59 = F_26 ( V_57 , V_64 , 0 ) ;
if ( ! V_59 ) {
V_60 = - V_65 ;
goto V_66;
}
if ( ! F_27 ( V_59 -> V_67 , F_28 ( V_59 ) ,
V_57 -> V_68 ) ) {
V_60 = - V_69 ;
goto V_66;
}
V_22 = F_29 ( V_59 -> V_67 , F_28 ( V_59 ) ) ;
if ( ! V_22 ) {
V_60 = - V_62 ;
goto V_70;
}
}
V_9 -> V_22 = V_22 ;
V_9 -> V_4 = F_30 ( V_57 , 0 ) ;
if ( V_9 -> V_4 < 0 ) {
V_60 = - V_21 ;
goto V_71;
}
F_5 ( ~ 0U , V_9 -> V_22 + F_31 ( V_9 -> V_23 ) ) ;
F_5 ( 0 , V_9 -> V_22 + F_11 ( V_9 -> V_23 ) ) ;
F_5 ( ~ 0U , V_9 -> V_22 + F_7 ( V_9 -> V_23 ) + V_26 ) ;
F_17 ( V_9 ) ;
F_32 ( V_9 -> V_4 , F_8 ) ;
F_33 ( V_9 -> V_4 , V_9 ) ;
V_60 = F_34 ( & V_9 -> V_55 , & V_57 -> V_72 , 4 ,
V_9 -> V_22 + F_35 ( V_9 -> V_23 ) ,
V_9 -> V_22 + F_36 ( V_9 -> V_23 ) , NULL ,
V_9 -> V_22 + F_37 ( V_9 -> V_23 ) , NULL , false ) ;
if ( V_60 )
goto V_71;
V_9 -> V_55 . V_7 . V_73 = F_21 ;
V_9 -> V_55 . V_7 . V_22 = V_9 -> V_23 * 32 ;
V_60 = F_38 ( & V_9 -> V_55 . V_7 ) ;
if ( V_60 )
goto V_74;
return 0 ;
V_74:
F_39 ( & V_9 -> V_55 ) ;
V_71:
if ( V_59 )
F_40 ( V_9 -> V_22 ) ;
V_70:
if ( V_59 )
F_41 ( V_59 -> V_67 , F_28 ( V_59 ) ) ;
V_66:
F_42 ( V_9 ) ;
F_43 ( & V_57 -> V_72 , L_2 , V_75 , V_60 ) ;
return V_60 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_76 ) ;
}
