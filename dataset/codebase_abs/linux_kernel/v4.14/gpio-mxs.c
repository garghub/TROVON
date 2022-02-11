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
struct V_13 * V_14 = F_5 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_15 ;
void T_2 * V_16 ;
int V_17 ;
if ( ! ( V_14 -> type & type ) )
if ( F_6 ( V_7 , type ) )
return - V_18 ;
V_2 -> V_19 &= ~ V_9 ;
switch ( type ) {
case V_20 :
V_8 = F_7 ( V_2 -> V_12 . V_21 + V_7 -> V_10 ) ;
if ( V_8 )
V_17 = V_22 ;
else
V_17 = V_23 ;
V_2 -> V_19 |= V_9 ;
break;
case V_24 :
V_17 = V_23 ;
break;
case V_25 :
V_17 = V_22 ;
break;
case V_26 :
V_17 = V_27 ;
break;
case V_28 :
V_17 = V_29 ;
break;
default:
return - V_18 ;
}
V_16 = V_2 -> V_21 + F_8 ( V_2 ) ;
if ( V_17 & V_30 ) {
F_9 ( V_9 , V_16 + V_31 ) ;
F_9 ( V_9 , V_2 -> V_21 + F_10 ( V_2 ) + V_31 ) ;
} else {
F_9 ( V_9 , V_16 + V_32 ) ;
F_9 ( V_9 , V_2 -> V_21 + F_11 ( V_2 ) + V_31 ) ;
}
V_16 = V_2 -> V_21 + F_12 ( V_2 ) ;
if ( V_17 & V_33 )
F_9 ( V_9 , V_16 + V_31 ) ;
else
F_9 ( V_9 , V_16 + V_32 ) ;
F_9 ( V_9 ,
V_2 -> V_21 + F_13 ( V_2 ) + V_32 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_34 )
{
T_1 V_35 , V_8 , V_17 ;
void T_2 * V_16 ;
V_35 = 1 << V_34 ;
V_16 = V_2 -> V_21 + F_12 ( V_2 ) ;
V_8 = F_15 ( V_16 ) ;
V_17 = V_8 & V_35 ;
if ( V_17 )
F_9 ( V_35 , V_16 + V_32 ) ;
else
F_9 ( V_35 , V_16 + V_31 ) ;
}
static void F_16 ( struct V_36 * V_37 )
{
T_1 V_38 ;
struct V_1 * V_2 = F_17 ( V_37 ) ;
V_37 -> V_6 . V_39 -> V_40 ( & V_37 -> V_6 ) ;
V_38 = F_15 ( V_2 -> V_21 + F_13 ( V_2 ) ) &
F_15 ( V_2 -> V_21 + F_10 ( V_2 ) ) ;
while ( V_38 != 0 ) {
int V_41 = F_18 ( V_38 ) - 1 ;
if ( V_2 -> V_19 & ( 1 << V_41 ) )
F_14 ( V_2 , V_41 ) ;
F_19 ( F_20 ( V_2 -> V_42 , V_41 ) ) ;
V_38 &= ~ ( 1 << V_41 ) ;
}
}
static int F_21 ( struct V_6 * V_7 , unsigned int V_43 )
{
struct V_11 * V_12 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_15 ;
if ( V_43 )
F_22 ( V_2 -> V_44 ) ;
else
F_23 ( V_2 -> V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_45 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_46 ;
V_12 = F_25 ( V_2 -> V_47 , L_1 , 2 , V_45 ,
V_2 -> V_21 , V_48 ) ;
if ( ! V_12 )
return - V_49 ;
V_12 -> V_15 = V_2 ;
V_14 = & V_12 -> V_50 [ 0 ] ;
V_14 -> type = V_28 | V_26 ;
V_14 -> V_39 . V_40 = V_51 ;
V_14 -> V_39 . V_52 = V_53 ;
V_14 -> V_39 . V_54 = V_55 ;
V_14 -> V_39 . V_56 = F_3 ;
V_14 -> V_39 . V_57 = F_21 ;
V_14 -> V_39 . V_58 = V_59 ;
V_14 -> V_60 . V_61 = F_13 ( V_2 ) + V_32 ;
V_14 -> V_60 . V_43 = F_11 ( V_2 ) + V_31 ;
V_14 -> V_60 . V_62 = F_11 ( V_2 ) + V_32 ;
V_14 = & V_12 -> V_50 [ 1 ] ;
V_14 -> type = V_24 | V_25 ;
V_14 -> V_39 . V_40 = V_51 ;
V_14 -> V_39 . V_52 = V_53 ;
V_14 -> V_39 . V_54 = V_55 ;
V_14 -> V_39 . V_56 = F_3 ;
V_14 -> V_39 . V_57 = F_21 ;
V_14 -> V_39 . V_58 = V_59 ;
V_14 -> V_60 . V_61 = F_13 ( V_2 ) + V_32 ;
V_14 -> V_60 . V_43 = F_10 ( V_2 ) + V_31 ;
V_14 -> V_60 . V_62 = F_10 ( V_2 ) + V_32 ;
V_14 -> V_63 = V_48 ;
V_46 = F_26 ( V_2 -> V_47 , V_12 , F_27 ( 32 ) ,
V_64 ,
V_65 , 0 ) ;
return V_46 ;
}
static int F_28 ( struct V_66 * V_12 , unsigned V_67 )
{
struct V_1 * V_2 = F_29 ( V_12 ) ;
return F_20 ( V_2 -> V_42 , V_67 ) ;
}
static int F_30 ( struct V_66 * V_12 , unsigned V_67 )
{
struct V_1 * V_2 = F_29 ( V_12 ) ;
T_1 V_68 = 1 << V_67 ;
T_1 V_69 ;
V_69 = F_15 ( V_2 -> V_21 + F_31 ( V_2 ) ) ;
return ! ( V_69 & V_68 ) ;
}
static int F_32 ( struct V_70 * V_71 )
{
const struct V_72 * V_73 =
F_33 ( V_74 , & V_71 -> V_47 ) ;
struct V_75 * V_76 = V_71 -> V_47 . V_77 ;
struct V_75 * V_78 ;
static void T_2 * V_21 ;
struct V_1 * V_2 ;
int V_45 ;
int V_79 ;
V_2 = F_34 ( & V_71 -> V_47 , sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_81 = F_35 ( V_76 , L_2 ) ;
if ( V_2 -> V_81 < 0 )
return V_2 -> V_81 ;
V_2 -> V_3 = (enum V_82 ) V_73 -> V_83 ;
V_2 -> V_47 = & V_71 -> V_47 ;
V_2 -> V_44 = F_36 ( V_71 , 0 ) ;
if ( V_2 -> V_44 < 0 )
return V_2 -> V_44 ;
if ( ! V_21 ) {
V_78 = F_37 ( V_76 ) ;
V_21 = F_38 ( V_78 , 0 ) ;
F_39 ( V_78 ) ;
if ( ! V_21 )
return - V_84 ;
}
V_2 -> V_21 = V_21 ;
F_9 ( 0 , V_2 -> V_21 + F_11 ( V_2 ) ) ;
F_9 ( 0 , V_2 -> V_21 + F_10 ( V_2 ) ) ;
F_9 ( ~ 0U , V_2 -> V_21 + F_13 ( V_2 ) + V_32 ) ;
V_45 = F_40 ( & V_71 -> V_47 , - 1 , 0 , 32 , F_41 () ) ;
if ( V_45 < 0 ) {
V_79 = V_45 ;
goto V_85;
}
V_2 -> V_42 = F_42 ( V_76 , 32 , V_45 , 0 ,
& V_86 , NULL ) ;
if ( ! V_2 -> V_42 ) {
V_79 = - V_87 ;
goto V_85;
}
V_79 = F_24 ( V_2 , V_45 ) ;
if ( V_79 < 0 )
goto V_88;
F_43 ( V_2 -> V_44 , F_16 ,
V_2 ) ;
V_79 = F_44 ( & V_2 -> V_12 , & V_71 -> V_47 , 4 ,
V_2 -> V_21 + F_45 ( V_2 ) ,
V_2 -> V_21 + F_46 ( V_2 ) + V_31 ,
V_2 -> V_21 + F_46 ( V_2 ) + V_32 ,
V_2 -> V_21 + F_31 ( V_2 ) , NULL , 0 ) ;
if ( V_79 )
goto V_88;
V_2 -> V_12 . V_89 = F_28 ;
V_2 -> V_12 . V_90 = F_30 ;
V_2 -> V_12 . V_21 = V_2 -> V_81 * 32 ;
V_79 = F_47 ( & V_2 -> V_12 , V_2 ) ;
if ( V_79 )
goto V_88;
return 0 ;
V_88:
F_48 ( V_2 -> V_42 ) ;
V_85:
F_49 ( V_2 -> V_21 ) ;
return V_79 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_91 ) ;
}
