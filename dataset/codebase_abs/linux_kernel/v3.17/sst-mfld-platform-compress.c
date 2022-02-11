static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( L_1 ) ;
if ( V_3 )
F_3 ( V_3 ) ;
}
static void F_4 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( L_2 ) ;
if ( V_3 )
F_5 ( V_3 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
F_8 ( & V_8 -> V_11 ) ;
if ( ! V_12 || ! F_9 ( V_12 -> V_13 -> V_14 -> V_15 ) ) {
F_10 ( L_3 ) ;
V_4 = - V_16 ;
goto V_17;
}
V_8 -> V_18 = V_12 -> V_18 ;
V_8 -> V_19 = 0 ;
F_11 ( V_8 , V_20 ) ;
V_6 -> V_21 = V_8 ;
return 0 ;
V_17:
F_12 ( V_8 ) ;
return V_4 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_4 = 0 , V_22 ;
V_8 = V_3 -> V_6 -> V_21 ;
V_22 = V_8 -> V_19 ;
if ( V_22 )
V_4 = V_8 -> V_18 -> V_23 ( V_22 ) ;
F_14 ( V_12 -> V_13 -> V_14 -> V_15 ) ;
F_12 ( V_8 ) ;
F_2 ( L_4 , V_24 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_7 * V_8 ;
int V_27 ;
struct V_28 V_29 ;
struct V_30 V_31 ;
struct V_32 * V_33 = V_3 -> V_21 ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_36 * V_37 = F_16 ( V_35 ) ;
V_8 = V_3 -> V_6 -> V_21 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_27 = F_17 ( V_3 , V_37 , & V_29 , true ) ;
F_2 ( L_5 , V_27 ) ;
if ( V_27 < 0 )
return V_27 ;
switch ( V_26 -> V_38 . V_19 ) {
case V_39 : {
V_29 . V_38 = V_40 ;
V_29 . V_41 . V_42 . V_43 . V_44 = V_26 -> V_38 . V_45 ;
V_29 . V_41 . V_42 . V_43 . V_46 = 16 ;
break;
}
case V_47 : {
V_29 . V_38 = V_48 ;
V_29 . V_41 . V_42 . V_49 . V_44 = V_26 -> V_38 . V_45 ;
V_29 . V_41 . V_42 . V_49 . V_46 = 16 ;
if ( V_26 -> V_38 . V_50 == V_51 )
V_29 . V_41 . V_42 . V_49 . V_52 =
V_53 ;
else if ( V_26 -> V_38 . V_50 == V_54 )
V_29 . V_41 . V_42 . V_49 . V_52 =
V_55 ;
else {
F_10 ( L_6 , V_26 -> V_38 . V_50 ) ;
return - V_56 ;
}
V_29 . V_41 . V_42 . V_49 . V_57 =
V_26 -> V_38 . V_58 ;
break;
}
default:
F_10 ( L_7 , V_26 -> V_38 . V_19 ) ;
return - V_56 ;
}
V_29 . V_59 . V_60 [ 0 ] . V_61 =
F_18 ( V_3 -> V_6 -> V_62 ) ;
V_29 . V_59 . V_60 [ 0 ] . V_63 =
V_3 -> V_6 -> V_64 ;
V_29 . V_59 . V_65 = 1 ;
V_29 . V_59 . V_66 = V_3 -> V_6 -> V_67 ;
V_31 . V_68 = V_3 ;
V_31 . V_69 = F_1 ;
V_31 . V_70 = V_3 ;
V_31 . V_71 = F_4 ;
V_27 = V_8 -> V_18 -> V_72 ( & V_29 , & V_31 ) ;
if ( V_27 < 0 ) {
F_10 ( L_8 , V_27 ) ;
return V_27 ;
}
V_8 -> V_19 = V_27 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , int V_73 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_21 ;
return V_8 -> V_18 -> V_74 ( V_73 , V_8 -> V_19 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_75 * V_76 )
{
struct V_7 * V_8 ;
V_8 = V_3 -> V_6 -> V_21 ;
V_8 -> V_18 -> V_76 ( V_8 -> V_19 , V_76 ) ;
V_76 -> V_77 = V_76 -> V_78 %
( V_79 ) V_3 -> V_6 -> V_64 ;
F_2 ( L_9 , V_76 -> V_77 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_80 )
{
struct V_7 * V_8 ;
V_8 = V_3 -> V_6 -> V_21 ;
V_8 -> V_18 -> V_81 ( V_8 -> V_19 , ( unsigned long ) V_80 ) ;
V_8 -> V_82 += V_80 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_21 ;
return V_8 -> V_18 -> V_85 ( V_84 ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_86 * V_38 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_21 ;
return V_8 -> V_18 -> V_87 ( V_38 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_88 * V_89 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_21 ;
return V_8 -> V_18 -> V_90 ( V_8 -> V_19 , V_89 ) ;
}
