static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
T_1 V_6 ;
T_1 V_7 = 0 ;
int V_8 ;
V_6 = F_3 (
V_2 -> V_9 -> V_10 )
<< V_11 ;
switch ( V_2 -> V_12 -> V_10 ) {
case V_13 :
break;
case V_14 :
V_7 = V_15 ;
V_7 |= F_4 ( V_2 -> V_16 -> V_10 )
<< V_17 ;
break;
case V_18 :
V_6 |= F_5 (
V_2 -> V_19 -> V_10 )
<< V_20 ;
break;
}
V_8 = F_6 ( V_4 , V_21 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_4 , V_22 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_23 ;
int V_8 ;
V_23 = F_8 ( V_4 , V_24 ) ;
if ( F_9 ( V_23 ) )
return V_23 ;
V_2 -> V_23 |= V_23 ;
if ( ! V_2 -> V_23 )
return 0 ;
V_8 = F_6 ( V_4 , V_21 , 0 ) ;
if ( F_9 ( V_8 ) )
return V_8 ;
V_2 -> V_12 -> V_10 = V_13 ;
V_8 = F_1 ( V_2 ) ;
if ( F_9 ( V_8 ) )
return V_8 ;
return V_2 -> V_23 ;
}
static int F_10 ( struct V_1 * V_2 , int V_25 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
T_1 V_6 = F_3 (
V_2 -> V_9 -> V_10 )
<< V_11 ;
int V_8 ;
if ( V_2 -> V_12 -> V_10 != V_14 )
return - V_26 ;
if ( ! V_25 )
return F_6 ( V_4 , V_21 ,
V_6 ) ;
V_6 |= F_5 (
V_2 -> V_27 -> V_10 )
<< V_20 ;
V_8 = F_6 ( V_4 , V_21 , V_6 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_4 , V_28 ,
V_29 ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_4 , V_28 , 0 ) ;
}
static int F_11 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_12 ( V_31 -> V_32 , struct V_1 , V_33 ) ;
int V_8 ;
V_8 = F_7 ( V_2 ) ;
if ( F_9 ( V_8 ) )
return V_8 ;
V_31 -> V_34 . V_10 = 0 ;
if ( V_2 -> V_23 & V_35 )
V_31 -> V_34 . V_10 |= V_36 ;
if ( V_2 -> V_23 & V_37 )
V_31 -> V_34 . V_10 |= V_38 ;
if ( V_2 -> V_23 & V_39 )
V_31 -> V_34 . V_10 |= V_40 ;
if ( V_2 -> V_23 & V_41 )
V_31 -> V_34 . V_10 |= V_42 ;
V_2 -> V_23 = 0 ;
return 0 ;
}
static int F_13 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_12 ( V_31 -> V_32 , struct V_1 , V_33 ) ;
int V_8 ;
V_8 = F_7 ( V_2 ) ;
if ( F_9 ( V_8 ) )
return V_8 ;
if ( ( V_8 & ( V_35 |
V_37 |
V_41 ) ) &&
( V_31 -> V_43 == V_44 ||
V_31 -> V_43 == V_45 ||
V_31 -> V_43 == V_46 ) )
return - V_26 ;
switch ( V_31 -> V_43 ) {
case V_44 :
return F_10 ( V_2 , 1 ) ;
case V_47 :
return F_10 ( V_2 , 0 ) ;
}
return F_1 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_30 * V_23 ;
F_15 ( & V_2 -> V_33 , 9 ) ;
V_2 -> V_12 =
F_16 ( & V_2 -> V_33 , & V_48 ,
V_46 ,
V_18 , ~ 0x7 , 0 ) ;
F_16 ( & V_2 -> V_33 , & V_48 ,
V_49 ,
V_50 , ~ 0x1 , 0 ) ;
F_17 ( & V_2 -> V_33 , & V_48 ,
V_44 , 0 , 0 , 0 , 0 ) ;
F_17 ( & V_2 -> V_33 , & V_48 ,
V_47 , 0 , 0 , 0 , 0 ) ;
V_2 -> V_16 =
F_17 ( & V_2 -> V_33 , & V_48 ,
V_51 , V_52 ,
V_2 -> V_53 -> V_54 ,
V_55 ,
V_2 -> V_53 -> V_54 ) ;
V_2 -> V_27 =
F_17 ( & V_2 -> V_33 , & V_48 ,
V_56 ,
V_57 ,
V_2 -> V_53 -> V_58 ,
1 , V_2 -> V_53 -> V_58 ) ;
V_2 -> V_19 =
F_17 ( & V_2 -> V_33 , & V_48 ,
V_45 ,
V_59 ,
V_2 -> V_53 -> V_60 ,
V_61 ,
V_2 -> V_53 -> V_60 ) ;
V_2 -> V_9 =
F_17 ( & V_2 -> V_33 , & V_48 ,
V_62 ,
V_63 ,
V_2 -> V_53 -> V_64 ,
V_65 ,
V_63 ) ;
V_23 = F_17 ( & V_2 -> V_33 , & V_48 ,
V_66 , 0 ,
V_42
| V_38
| V_36 , 0 , 0 ) ;
if ( V_2 -> V_33 . error )
return V_2 -> V_33 . error ;
V_23 -> V_67 = 1 ;
V_2 -> V_5 . V_68 = & V_2 -> V_33 ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_8 ;
V_8 = F_6 ( V_4 , V_21 , 0 ) ;
if ( V_8 < 0 ) {
F_19 ( & V_4 -> V_69 , L_1 ) ;
return - V_70 ;
}
F_20 ( & V_2 -> V_33 . V_71 ) ;
V_2 -> V_23 = 0 ;
V_8 = F_7 ( V_2 ) ;
F_21 ( & V_2 -> V_33 . V_71 ) ;
if ( V_8 > 0 ) {
F_19 ( & V_4 -> V_69 , L_2 , V_8 ) ;
return - V_70 ;
}
F_20 ( & V_2 -> V_33 . V_71 ) ;
V_8 = F_1 ( V_2 ) ;
F_21 ( & V_2 -> V_33 . V_71 ) ;
if ( V_8 ) {
F_19 ( & V_4 -> V_69 ,
L_3 , V_72 ) ;
return - V_70 ;
}
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , int V_73 )
{
int V_74 ;
V_74 = V_2 -> V_53 -> V_75 ( & V_2 -> V_5 , V_73 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( ! V_73 )
return 0 ;
V_74 = F_18 ( V_2 ) ;
if ( V_74 < 0 )
V_2 -> V_53 -> V_75 ( & V_2 -> V_5 , 0 ) ;
return V_74 ;
}
static int
F_23 ( struct V_76 * V_5 , int V_73 )
{
struct V_1 * V_2 = F_24 ( V_5 ) ;
int V_74 = 0 ;
F_20 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 == ! V_73 ) {
V_74 = F_22 ( V_2 , ! ! V_73 ) ;
if ( V_74 < 0 )
goto V_79;
}
V_2 -> V_78 += V_73 ? 1 : - 1 ;
F_25 ( V_2 -> V_78 < 0 ) ;
V_79:
F_21 ( & V_2 -> V_77 ) ;
return V_74 ;
}
static int F_26 ( struct V_76 * V_80 , struct V_81 * V_82 )
{
return F_23 ( V_80 , 1 ) ;
}
static int F_27 ( struct V_76 * V_80 , struct V_81 * V_82 )
{
return F_23 ( V_80 , 0 ) ;
}
static int F_28 ( struct V_83 * V_69 )
{
struct V_3 * V_4 = F_29 ( V_69 ) ;
struct V_76 * V_5 = F_30 ( V_4 ) ;
struct V_1 * V_2 = F_24 ( V_5 ) ;
if ( ! V_2 -> V_78 )
return 0 ;
return F_22 ( V_2 , 0 ) ;
}
static int F_31 ( struct V_83 * V_69 )
{
struct V_3 * V_4 = F_29 ( V_69 ) ;
struct V_76 * V_5 = F_30 ( V_4 ) ;
struct V_1 * V_2 = F_24 ( V_5 ) ;
if ( ! V_2 -> V_78 )
return 0 ;
return F_22 ( V_2 , 1 ) ;
}
static int F_32 ( struct V_3 * V_4 ,
const struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_74 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_86 ) ;
if ( V_2 == NULL )
return - V_87 ;
V_2 -> V_53 = V_4 -> V_69 . V_53 ;
F_34 ( & V_2 -> V_77 ) ;
F_35 ( & V_2 -> V_5 , V_4 , & V_88 ) ;
V_2 -> V_5 . V_89 = & V_90 ;
V_2 -> V_5 . V_91 |= V_92 ;
F_14 ( V_2 ) ;
V_74 = F_36 ( & V_2 -> V_5 . V_93 , 0 , NULL , 0 ) ;
if ( V_74 < 0 )
F_37 ( V_2 ) ;
return V_74 ;
}
static int T_2 F_38 ( struct V_3 * V_4 )
{
struct V_76 * V_5 = F_30 ( V_4 ) ;
struct V_1 * V_2 = F_24 ( V_5 ) ;
F_39 ( & V_2 -> V_5 ) ;
F_40 ( & V_2 -> V_33 ) ;
F_41 ( & V_2 -> V_5 . V_93 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
int V_8 ;
V_8 = F_43 ( & V_94 ) ;
if ( V_8 )
F_44 ( V_95 L_4 , V_72 ) ;
return V_8 ;
}
static void T_2 F_45 ( void )
{
F_46 ( & V_94 ) ;
}
