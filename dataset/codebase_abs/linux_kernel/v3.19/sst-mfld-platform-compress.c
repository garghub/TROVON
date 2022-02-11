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
V_12 -> V_18 -> V_20 ( V_12 -> V_13 , true ) ;
F_11 ( V_8 , V_21 ) ;
V_6 -> V_22 = V_8 ;
return 0 ;
V_17:
F_12 ( V_8 ) ;
return V_4 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_4 = 0 , V_23 ;
V_8 = V_3 -> V_6 -> V_22 ;
V_12 -> V_18 -> V_20 ( V_12 -> V_13 , false ) ;
V_23 = V_8 -> V_19 ;
if ( V_23 )
V_4 = V_8 -> V_18 -> V_24 ( V_12 -> V_13 , V_23 ) ;
F_14 ( V_12 -> V_13 -> V_14 -> V_15 ) ;
F_12 ( V_8 ) ;
F_2 ( L_4 , V_25 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_7 * V_8 ;
int V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
struct V_33 * V_34 = V_3 -> V_22 ;
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_37 * V_38 = F_16 ( V_36 ) ;
V_8 = V_3 -> V_6 -> V_22 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_28 = F_17 ( V_3 , V_38 , & V_30 , true ) ;
F_2 ( L_5 , V_28 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_27 -> V_39 . V_19 ) {
case V_40 : {
V_30 . V_39 = V_41 ;
V_30 . V_42 . V_43 . V_44 . V_45 = V_27 -> V_39 . V_46 ;
V_30 . V_42 . V_43 . V_44 . V_47 = 16 ;
break;
}
case V_48 : {
V_30 . V_39 = V_49 ;
V_30 . V_42 . V_43 . V_50 . V_45 = V_27 -> V_39 . V_46 ;
V_30 . V_42 . V_43 . V_50 . V_47 = 16 ;
if ( V_27 -> V_39 . V_51 == V_52 )
V_30 . V_42 . V_43 . V_50 . V_53 =
V_54 ;
else if ( V_27 -> V_39 . V_51 == V_55 )
V_30 . V_42 . V_43 . V_50 . V_53 =
V_56 ;
else {
F_10 ( L_6 , V_27 -> V_39 . V_51 ) ;
return - V_57 ;
}
V_30 . V_42 . V_43 . V_50 . V_58 =
V_27 -> V_39 . V_59 ;
break;
}
default:
F_10 ( L_7 , V_27 -> V_39 . V_19 ) ;
return - V_57 ;
}
V_30 . V_60 . V_61 [ 0 ] . V_62 =
F_18 ( V_3 -> V_6 -> V_63 ) ;
V_30 . V_60 . V_61 [ 0 ] . V_64 =
V_3 -> V_6 -> V_65 ;
V_30 . V_60 . V_66 = 1 ;
V_30 . V_60 . V_67 = V_3 -> V_6 -> V_68 ;
V_32 . V_69 = V_3 ;
V_32 . V_70 = F_1 ;
V_32 . V_71 = V_3 ;
V_32 . V_72 = F_4 ;
V_28 = V_8 -> V_18 -> V_73 ( V_12 -> V_13 , & V_30 , & V_32 ) ;
if ( V_28 < 0 ) {
F_10 ( L_8 , V_28 ) ;
return V_28 ;
}
V_8 -> V_19 = V_28 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , int V_74 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_22 ;
switch ( V_74 ) {
case V_75 :
if ( V_8 -> V_18 -> V_76 )
return V_8 -> V_18 -> V_76 ( V_12 -> V_13 , V_8 -> V_19 ) ;
case V_77 :
if ( V_8 -> V_18 -> V_78 )
return V_8 -> V_18 -> V_78 ( V_12 -> V_13 , V_8 -> V_19 ) ;
case V_79 :
if ( V_8 -> V_18 -> V_80 )
return V_8 -> V_18 -> V_80 ( V_12 -> V_13 , V_8 -> V_19 ) ;
case V_81 :
if ( V_8 -> V_18 -> V_82 )
return V_8 -> V_18 -> V_82 ( V_12 -> V_13 , V_8 -> V_19 ) ;
case V_83 :
if ( V_8 -> V_18 -> V_84 )
return V_8 -> V_18 -> V_84 ( V_12 -> V_13 , V_8 -> V_19 ) ;
case V_85 :
if ( V_8 -> V_18 -> V_86 )
return V_8 -> V_18 -> V_86 ( V_12 -> V_13 , V_8 -> V_19 ) ;
default:
return - V_57 ;
}
}
static int F_20 ( struct V_2 * V_3 ,
struct V_87 * V_88 )
{
struct V_7 * V_8 ;
V_8 = V_3 -> V_6 -> V_22 ;
V_8 -> V_18 -> V_88 ( V_12 -> V_13 , V_8 -> V_19 , V_88 ) ;
V_88 -> V_89 = V_88 -> V_90 %
( V_91 ) V_3 -> V_6 -> V_65 ;
F_2 ( L_9 , V_88 -> V_89 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_92 )
{
struct V_7 * V_8 ;
V_8 = V_3 -> V_6 -> V_22 ;
V_8 -> V_18 -> V_93 ( V_12 -> V_13 , V_8 -> V_19 , ( unsigned long ) V_92 ) ;
V_8 -> V_94 += V_92 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_95 * V_96 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_22 ;
return V_8 -> V_18 -> V_97 ( V_96 ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_98 * V_39 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_22 ;
return V_8 -> V_18 -> V_99 ( V_39 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 =
V_3 -> V_6 -> V_22 ;
return V_8 -> V_18 -> V_102 ( V_12 -> V_13 , V_8 -> V_19 , V_101 ) ;
}
