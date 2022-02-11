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
T_1 V_8 ;
T_1 V_9 = 1 << V_7 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
void T_2 * V_14 ;
int V_15 ;
V_2 -> V_16 &= ~ V_9 ;
switch ( type ) {
case V_17 :
V_8 = F_5 ( V_2 -> V_18 . V_12 . V_19 + V_7 -> V_10 ) ;
if ( V_8 )
V_15 = V_20 ;
else
V_15 = V_21 ;
V_2 -> V_16 |= V_9 ;
break;
case V_22 :
V_15 = V_21 ;
break;
case V_23 :
V_15 = V_20 ;
break;
case V_24 :
V_15 = V_25 ;
break;
case V_26 :
V_15 = V_27 ;
break;
default:
return - V_28 ;
}
V_14 = V_2 -> V_19 + F_6 ( V_2 ) ;
if ( V_15 & V_29 )
F_7 ( V_9 , V_14 + V_30 ) ;
else
F_7 ( V_9 , V_14 + V_31 ) ;
V_14 = V_2 -> V_19 + F_8 ( V_2 ) ;
if ( V_15 & V_32 )
F_7 ( V_9 , V_14 + V_30 ) ;
else
F_7 ( V_9 , V_14 + V_31 ) ;
F_7 ( V_9 ,
V_2 -> V_19 + F_9 ( V_2 ) + V_31 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_33 )
{
T_1 V_34 , V_8 , V_15 ;
void T_2 * V_14 ;
V_34 = 1 << V_33 ;
V_14 = V_2 -> V_19 + F_8 ( V_2 ) ;
V_8 = F_11 ( V_14 ) ;
V_15 = V_8 & V_34 ;
if ( V_15 )
F_7 ( V_34 , V_14 + V_31 ) ;
else
F_7 ( V_34 , V_14 + V_30 ) ;
}
static void F_12 ( T_1 V_35 , struct V_36 * V_37 )
{
T_1 V_38 ;
struct V_1 * V_2 = F_13 ( V_35 ) ;
V_37 -> V_6 . V_39 -> V_40 ( & V_37 -> V_6 ) ;
V_38 = F_11 ( V_2 -> V_19 + F_9 ( V_2 ) ) &
F_11 ( V_2 -> V_19 + F_14 ( V_2 ) ) ;
while ( V_38 != 0 ) {
int V_41 = F_15 ( V_38 ) - 1 ;
if ( V_2 -> V_16 & ( 1 << V_41 ) )
F_10 ( V_2 , V_41 ) ;
F_16 ( F_17 ( V_2 -> V_42 , V_41 ) ) ;
V_38 &= ~ ( 1 << V_41 ) ;
}
}
static int F_18 ( struct V_6 * V_7 , unsigned int V_43 )
{
struct V_11 * V_12 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
if ( V_43 )
F_19 ( V_2 -> V_35 ) ;
else
F_20 ( V_2 -> V_35 ) ;
return 0 ;
}
static void T_3 F_21 ( struct V_1 * V_2 , int V_44 )
{
struct V_11 * V_12 ;
struct V_45 * V_46 ;
V_12 = F_22 ( L_1 , 1 , V_44 ,
V_2 -> V_19 , V_47 ) ;
V_12 -> V_13 = V_2 ;
V_46 = V_12 -> V_48 ;
V_46 -> V_39 . V_40 = V_49 ;
V_46 -> V_39 . V_50 = V_51 ;
V_46 -> V_39 . V_52 = V_53 ;
V_46 -> V_39 . V_54 = F_3 ;
V_46 -> V_39 . V_55 = F_18 ;
V_46 -> V_56 . V_57 = F_9 ( V_2 ) + V_31 ;
V_46 -> V_56 . V_58 = F_14 ( V_2 ) ;
F_23 ( V_12 , F_24 ( 32 ) , 0 , V_59 , 0 ) ;
}
static int F_25 ( struct V_60 * V_12 , unsigned V_61 )
{
struct V_62 * V_18 = F_26 ( V_12 ) ;
struct V_1 * V_2 =
F_27 ( V_18 , struct V_1 , V_18 ) ;
return F_17 ( V_2 -> V_42 , V_61 ) ;
}
static int F_28 ( struct V_63 * V_64 )
{
const struct V_65 * V_66 =
F_29 ( V_67 , & V_64 -> V_68 ) ;
struct V_69 * V_70 = V_64 -> V_68 . V_71 ;
struct V_69 * V_72 ;
static void T_2 * V_19 ;
struct V_1 * V_2 ;
struct V_73 * V_74 = NULL ;
int V_44 ;
int V_75 ;
V_2 = F_30 ( & V_64 -> V_68 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
if ( V_70 ) {
V_2 -> V_78 = F_31 ( V_70 , L_2 ) ;
if ( V_2 -> V_78 < 0 )
return V_2 -> V_78 ;
V_2 -> V_3 = (enum V_79 ) V_66 -> V_80 ;
} else {
V_2 -> V_78 = V_64 -> V_78 ;
V_2 -> V_3 = V_64 -> V_81 -> V_82 ;
}
V_2 -> V_35 = F_32 ( V_64 , 0 ) ;
if ( V_2 -> V_35 < 0 )
return V_2 -> V_35 ;
if ( ! V_19 ) {
if ( V_70 ) {
V_72 = F_33 ( V_70 ) ;
V_19 = F_34 ( V_72 , 0 ) ;
F_35 ( V_72 ) ;
if ( ! V_19 )
return - V_83 ;
} else {
V_74 = F_36 ( V_64 , V_84 , 0 ) ;
V_19 = F_37 ( & V_64 -> V_68 , V_74 ) ;
if ( F_38 ( V_19 ) )
return F_39 ( V_19 ) ;
}
}
V_2 -> V_19 = V_19 ;
F_7 ( ~ 0U , V_2 -> V_19 + F_40 ( V_2 ) ) ;
F_7 ( 0 , V_2 -> V_19 + F_14 ( V_2 ) ) ;
F_7 ( ~ 0U , V_2 -> V_19 + F_9 ( V_2 ) + V_31 ) ;
V_44 = F_41 ( - 1 , 0 , 32 , F_42 () ) ;
if ( V_44 < 0 )
return V_44 ;
V_2 -> V_42 = F_43 ( V_70 , 32 , V_44 , 0 ,
& V_85 , NULL ) ;
if ( ! V_2 -> V_42 ) {
V_75 = - V_86 ;
goto V_87;
}
F_21 ( V_2 , V_44 ) ;
F_44 ( V_2 -> V_35 , F_12 ) ;
F_45 ( V_2 -> V_35 , V_2 ) ;
V_75 = F_46 ( & V_2 -> V_18 , & V_64 -> V_68 , 4 ,
V_2 -> V_19 + F_47 ( V_2 ) ,
V_2 -> V_19 + F_48 ( V_2 ) , NULL ,
V_2 -> V_19 + F_49 ( V_2 ) , NULL , 0 ) ;
if ( V_75 )
goto V_87;
V_2 -> V_18 . V_12 . V_88 = F_25 ;
V_2 -> V_18 . V_12 . V_19 = V_2 -> V_78 * 32 ;
V_75 = F_50 ( & V_2 -> V_18 . V_12 ) ;
if ( V_75 )
goto V_89;
return 0 ;
V_89:
F_51 ( & V_2 -> V_18 ) ;
V_87:
F_52 ( V_44 , 32 ) ;
return V_75 ;
}
static int T_3 F_53 ( void )
{
return F_54 ( & V_90 ) ;
}
