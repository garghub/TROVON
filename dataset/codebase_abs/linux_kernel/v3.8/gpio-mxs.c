static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static int F_3 ( struct V_6 * V_7 , unsigned int type )
{
T_1 V_8 = 1 << V_7 -> V_9 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_11 -> V_12 ;
void T_2 * V_13 ;
int V_14 ;
switch ( type ) {
case V_15 :
V_14 = V_16 ;
break;
case V_17 :
V_14 = V_18 ;
break;
case V_19 :
V_14 = V_20 ;
break;
case V_21 :
V_14 = V_22 ;
break;
default:
return - V_23 ;
}
V_13 = V_2 -> V_24 + F_5 ( V_2 ) ;
if ( V_14 & V_25 )
F_6 ( V_8 , V_13 + V_26 ) ;
else
F_6 ( V_8 , V_13 + V_27 ) ;
V_13 = V_2 -> V_24 + F_7 ( V_2 ) ;
if ( V_14 & V_28 )
F_6 ( V_8 , V_13 + V_26 ) ;
else
F_6 ( V_8 , V_13 + V_27 ) ;
F_6 ( V_8 ,
V_2 -> V_24 + F_8 ( V_2 ) + V_27 ) ;
return 0 ;
}
static void F_9 ( T_1 V_29 , struct V_30 * V_31 )
{
T_1 V_32 ;
struct V_1 * V_2 = F_10 ( V_29 ) ;
V_31 -> V_6 . V_33 -> V_34 ( & V_31 -> V_6 ) ;
V_32 = F_11 ( V_2 -> V_24 + F_8 ( V_2 ) ) &
F_11 ( V_2 -> V_24 + F_12 ( V_2 ) ) ;
while ( V_32 != 0 ) {
int V_35 = F_13 ( V_32 ) - 1 ;
F_14 ( F_15 ( V_2 -> V_36 , V_35 ) ) ;
V_32 &= ~ ( 1 << V_35 ) ;
}
}
static int F_16 ( struct V_6 * V_7 , unsigned int V_37 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_11 -> V_12 ;
if ( V_37 )
F_17 ( V_2 -> V_29 ) ;
else
F_18 ( V_2 -> V_29 ) ;
return 0 ;
}
static void T_3 F_19 ( struct V_1 * V_2 , int V_38 )
{
struct V_10 * V_11 ;
struct V_39 * V_40 ;
V_11 = F_20 ( L_1 , 1 , V_38 ,
V_2 -> V_24 , V_41 ) ;
V_11 -> V_12 = V_2 ;
V_40 = V_11 -> V_42 ;
V_40 -> V_33 . V_34 = V_43 ;
V_40 -> V_33 . V_44 = V_45 ;
V_40 -> V_33 . V_46 = V_47 ;
V_40 -> V_33 . V_48 = F_3 ;
V_40 -> V_33 . V_49 = F_16 ;
V_40 -> V_50 . V_51 = F_8 ( V_2 ) + V_27 ;
V_40 -> V_50 . V_52 = F_12 ( V_2 ) ;
F_21 ( V_11 , F_22 ( 32 ) , 0 , V_53 , 0 ) ;
}
static int F_23 ( struct V_54 * V_11 , unsigned V_55 )
{
struct V_56 * V_57 = F_24 ( V_11 ) ;
struct V_1 * V_2 =
F_25 ( V_57 , struct V_1 , V_57 ) ;
return F_15 ( V_2 -> V_36 , V_55 ) ;
}
static int F_26 ( struct V_58 * V_59 )
{
const struct V_60 * V_61 =
F_27 ( V_62 , & V_59 -> V_63 ) ;
struct V_64 * V_65 = V_59 -> V_63 . V_66 ;
struct V_64 * V_67 ;
static void T_2 * V_24 ;
struct V_1 * V_2 ;
struct V_68 * V_69 = NULL ;
int V_38 ;
int V_70 ;
V_2 = F_28 ( & V_59 -> V_63 , sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
return - V_72 ;
if ( V_65 ) {
V_2 -> V_73 = F_29 ( V_65 , L_2 ) ;
if ( V_2 -> V_73 < 0 )
return V_2 -> V_73 ;
V_2 -> V_3 = (enum V_74 ) V_61 -> V_75 ;
} else {
V_2 -> V_73 = V_59 -> V_73 ;
V_2 -> V_3 = V_59 -> V_76 -> V_77 ;
}
V_2 -> V_29 = F_30 ( V_59 , 0 ) ;
if ( V_2 -> V_29 < 0 )
return V_2 -> V_29 ;
if ( ! V_24 ) {
if ( V_65 ) {
V_67 = F_31 ( V_65 ) ;
V_24 = F_32 ( V_67 , 0 ) ;
F_33 ( V_67 ) ;
} else {
V_69 = F_34 ( V_59 , V_78 , 0 ) ;
V_24 = F_35 ( & V_59 -> V_63 , V_69 ) ;
}
if ( ! V_24 )
return - V_79 ;
}
V_2 -> V_24 = V_24 ;
F_6 ( ~ 0U , V_2 -> V_24 + F_36 ( V_2 ) ) ;
F_6 ( 0 , V_2 -> V_24 + F_12 ( V_2 ) ) ;
F_6 ( ~ 0U , V_2 -> V_24 + F_8 ( V_2 ) + V_27 ) ;
V_38 = F_37 ( - 1 , 0 , 32 , F_38 () ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 -> V_36 = F_39 ( V_65 , 32 , V_38 , 0 ,
& V_80 , NULL ) ;
if ( ! V_2 -> V_36 ) {
V_70 = - V_81 ;
goto V_82;
}
F_19 ( V_2 , V_38 ) ;
F_40 ( V_2 -> V_29 , F_9 ) ;
F_41 ( V_2 -> V_29 , V_2 ) ;
V_70 = F_42 ( & V_2 -> V_57 , & V_59 -> V_63 , 4 ,
V_2 -> V_24 + F_43 ( V_2 ) ,
V_2 -> V_24 + F_44 ( V_2 ) , NULL ,
V_2 -> V_24 + F_45 ( V_2 ) , NULL , 0 ) ;
if ( V_70 )
goto V_82;
V_2 -> V_57 . V_11 . V_83 = F_23 ;
V_2 -> V_57 . V_11 . V_24 = V_2 -> V_73 * 32 ;
V_70 = F_46 ( & V_2 -> V_57 . V_11 ) ;
if ( V_70 )
goto V_84;
return 0 ;
V_84:
F_47 ( & V_2 -> V_57 ) ;
V_82:
F_48 ( V_38 , 32 ) ;
return V_70 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_85 ) ;
}
