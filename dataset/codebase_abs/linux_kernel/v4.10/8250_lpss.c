static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned int V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_10 = V_8 -> V_11 -> V_12 , V_13 = V_6 * 16 ;
unsigned long V_14 = F_3 ( 15 ) - 1 ;
unsigned long V_15 , V_16 ;
T_1 V_17 ;
V_13 = V_13 ? V_13 : 9600 * 16 ;
V_13 *= F_4 ( V_10 / V_13 ) ;
F_5 ( V_13 , V_10 , V_14 , V_14 , & V_15 , & V_16 ) ;
V_2 -> V_18 = V_13 ;
V_17 = ( V_15 << V_19 ) | ( V_16 << V_20 ) ;
F_6 ( V_17 , V_2 -> V_21 + V_22 ) ;
V_17 |= V_23 | V_24 ;
F_6 ( V_17 , V_2 -> V_21 + V_22 ) ;
V_2 -> V_25 &= ~ V_26 ;
if ( V_4 -> V_27 & V_28 )
V_2 -> V_25 |= V_26 ;
F_7 ( V_2 , V_4 , V_5 ) ;
}
static unsigned int F_8 ( struct V_1 * V_29 )
{
unsigned int V_30 = F_9 ( V_29 ) ;
V_30 |= V_31 | V_32 ;
return V_30 ;
}
static int F_10 ( struct V_7 * V_8 , struct V_1 * V_29 )
{
struct V_33 * V_34 = & V_8 -> V_35 ;
struct V_36 * V_37 = F_11 ( V_29 ) ;
struct V_38 * V_39 = F_12 ( V_29 -> V_40 ) ;
unsigned int V_41 = F_13 ( F_14 ( V_39 -> V_42 ) , 0 ) ;
struct V_38 * V_43 = F_15 ( V_39 -> V_44 , V_41 ) ;
switch ( V_39 -> V_45 ) {
case V_46 :
case V_47 :
case V_48 :
V_34 -> V_49 = 3 ;
V_34 -> V_50 = 2 ;
break;
case V_51 :
case V_52 :
case V_53 :
V_34 -> V_49 = 5 ;
V_34 -> V_50 = 4 ;
break;
default:
return - V_54 ;
}
V_34 -> V_43 = & V_43 -> V_40 ;
V_34 -> V_55 = 0 ;
V_34 -> V_56 = 1 ;
V_29 -> V_57 = 64 ;
V_37 -> V_58 = 64 ;
V_8 -> V_59 = 16 ;
V_29 -> V_60 = F_1 ;
V_29 -> V_61 = F_8 ;
F_6 ( V_62 , V_29 -> V_21 + V_63 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 , struct V_1 * V_29 )
{
struct V_64 * V_65 = & V_8 -> V_65 ;
struct V_66 * V_67 = & V_8 -> V_68 ;
struct V_33 * V_34 = & V_8 -> V_35 ;
struct V_38 * V_39 = F_12 ( V_29 -> V_40 ) ;
int V_30 ;
V_67 -> V_40 = & V_39 -> V_40 ;
V_67 -> V_69 = F_17 ( V_39 , 0 ) ;
V_67 -> V_70 = F_18 ( V_39 , 1 ) ;
V_67 -> V_71 = & V_72 ;
V_30 = F_19 ( V_67 ) ;
if ( V_30 )
return;
F_20 ( V_39 ) ;
F_21 ( V_39 ) ;
V_65 -> V_73 = 0xfffff000 ;
V_65 -> V_74 = 0xfffff000 ;
V_34 -> V_43 = & V_39 -> V_40 ;
V_34 -> V_49 = 0 ;
V_34 -> V_50 = 1 ;
V_34 -> V_75 = true ;
V_8 -> V_59 = 8 ;
}
static void F_22 ( struct V_7 * V_8 )
{
struct V_33 * V_34 = & V_8 -> V_35 ;
if ( ! V_34 -> V_43 )
return;
F_23 ( & V_8 -> V_68 ) ;
}
static void F_16 ( struct V_7 * V_8 , struct V_1 * V_29 ) {}
static void F_22 ( struct V_7 * V_8 ) {}
static int F_24 ( struct V_7 * V_8 , struct V_1 * V_29 )
{
struct V_38 * V_39 = F_12 ( V_29 -> V_40 ) ;
int V_30 ;
V_30 = F_25 ( V_39 , 1 , 1 , V_76 ) ;
if ( V_30 < 0 )
return V_30 ;
V_29 -> V_69 = F_17 ( V_39 , 0 ) ;
F_16 ( V_8 , V_29 ) ;
return 0 ;
}
static void F_26 ( struct V_7 * V_8 )
{
F_22 ( V_8 ) ;
}
static bool F_27 ( struct V_77 * V_78 , void * V_34 )
{
struct V_33 * V_79 = V_34 ;
if ( V_79 -> V_43 != V_78 -> V_45 -> V_40 )
return false ;
V_78 -> V_80 = V_79 ;
return true ;
}
static int F_28 ( struct V_7 * V_8 , struct V_36 * V_29 )
{
struct V_64 * V_65 = & V_8 -> V_65 ;
struct V_33 * V_81 , * V_82 ;
struct V_45 * V_40 = V_29 -> V_29 . V_40 ;
if ( ! V_8 -> V_35 . V_43 )
return 0 ;
V_81 = F_29 ( V_40 , sizeof( * V_81 ) , V_83 ) ;
if ( ! V_81 )
return - V_84 ;
V_82 = F_29 ( V_40 , sizeof( * V_82 ) , V_83 ) ;
if ( ! V_82 )
return - V_84 ;
* V_81 = V_8 -> V_35 ;
V_65 -> V_85 . V_86 = V_8 -> V_59 ;
* V_82 = V_8 -> V_35 ;
V_65 -> V_87 . V_88 = V_8 -> V_59 ;
V_65 -> V_89 = F_27 ;
V_65 -> V_81 = V_81 ;
V_65 -> V_82 = V_82 ;
V_29 -> V_65 = V_65 ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 , const struct V_90 * V_91 )
{
struct V_36 V_92 ;
struct V_7 * V_8 ;
int V_30 ;
V_30 = F_31 ( V_39 ) ;
if ( V_30 )
return V_30 ;
V_8 = F_29 ( & V_39 -> V_40 , sizeof( * V_8 ) , V_83 ) ;
if ( ! V_8 )
return - V_84 ;
V_8 -> V_11 = (struct V_93 * ) V_91 -> V_94 ;
memset ( & V_92 , 0 , sizeof( struct V_36 ) ) ;
V_92 . V_29 . V_40 = & V_39 -> V_40 ;
V_92 . V_29 . V_69 = V_39 -> V_69 ;
V_92 . V_29 . V_9 = V_8 ;
V_92 . V_29 . type = V_95 ;
V_92 . V_29 . V_96 = V_97 ;
V_92 . V_29 . V_98 = 2 ;
V_92 . V_29 . V_18 = V_8 -> V_11 -> V_99 * 16 ;
V_92 . V_29 . V_100 = V_101 | V_102 | V_103 ;
V_92 . V_104 = V_105 | V_106 ;
V_92 . V_29 . V_107 = F_32 ( V_39 , 0 ) ;
V_92 . V_29 . V_21 = F_33 ( V_39 , 0 , 0 ) ;
if ( ! V_92 . V_29 . V_21 )
return - V_84 ;
V_30 = V_8 -> V_11 -> V_108 ( V_8 , & V_92 . V_29 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_28 ( V_8 , & V_92 ) ;
if ( V_30 )
goto V_109;
V_30 = F_34 ( & V_92 ) ;
if ( V_30 < 0 )
goto V_109;
V_8 -> line = V_30 ;
F_35 ( V_39 , V_8 ) ;
return 0 ;
V_109:
if ( V_8 -> V_11 -> exit )
V_8 -> V_11 -> exit ( V_8 ) ;
return V_30 ;
}
static void F_36 ( struct V_38 * V_39 )
{
struct V_7 * V_8 = F_37 ( V_39 ) ;
if ( V_8 -> V_11 -> exit )
V_8 -> V_11 -> exit ( V_8 ) ;
F_38 ( V_8 -> line ) ;
}
