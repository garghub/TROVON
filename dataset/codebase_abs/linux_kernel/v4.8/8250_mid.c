static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
switch ( V_6 -> V_8 ) {
case V_9 :
V_2 -> V_10 = 0 ;
break;
case V_11 :
V_2 -> V_10 = 1 ;
break;
case V_12 :
V_2 -> V_10 = 2 ;
break;
default:
return - V_13 ;
}
V_2 -> V_14 = F_3 ( V_6 -> V_15 ,
F_4 ( F_5 ( V_6 -> V_16 ) , 3 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
int V_17 = F_7 ( V_6 -> V_16 ) ;
if ( V_17 -- == 0 )
return - V_18 ;
V_2 -> V_10 = V_17 ;
V_2 -> V_14 = F_3 ( V_6 -> V_15 , F_4 ( 5 , 0 ) ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_19 ;
struct V_20 * V_21 = F_9 ( V_4 ) ;
unsigned int V_22 = F_10 ( V_4 , V_23 ) ;
T_1 V_24 ;
int V_25 = V_26 ;
int V_27 ;
if ( V_22 & F_11 ( 2 ) ) {
V_27 = F_12 ( & V_2 -> V_28 , 1 , & V_24 ) ;
if ( V_27 > 0 ) {
F_13 ( V_21 ) ;
V_25 |= V_29 ;
} else if ( V_27 == 0 )
V_25 |= F_14 ( & V_2 -> V_28 , 1 , V_24 ) ;
}
if ( V_22 & F_11 ( 1 ) ) {
V_27 = F_12 ( & V_2 -> V_28 , 0 , & V_24 ) ;
if ( V_27 > 0 )
V_25 |= V_29 ;
else if ( V_27 == 0 )
V_25 |= F_14 ( & V_2 -> V_28 , 0 , V_24 ) ;
}
if ( V_22 & F_11 ( 0 ) )
V_25 |= F_15 ( V_4 , F_10 ( V_4 , V_30 ) ) ;
return V_25 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_2 -> V_28 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_33 = F_17 ( V_2 -> V_34 -> V_35 ) ;
int V_25 ;
V_32 -> V_7 = & V_6 -> V_7 ;
V_32 -> V_36 = V_6 -> V_36 ;
V_32 -> V_37 = V_4 -> V_38 ;
V_32 -> V_39 = F_18 ( V_6 , V_33 ) ;
V_32 -> V_40 = V_41 ;
V_25 = F_19 ( V_32 ) ;
if ( V_25 )
return 0 ;
V_2 -> V_14 = V_6 ;
V_4 -> V_42 = F_8 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return;
F_21 ( & V_2 -> V_28 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_43 * V_44 ,
struct V_43 * V_45 )
{
unsigned int V_46 = F_23 ( V_44 ) ;
struct V_1 * V_2 = V_4 -> V_19 ;
unsigned short V_47 = 16 ;
unsigned long V_48 = V_46 * V_47 ;
unsigned long V_49 = F_11 ( 24 ) - 1 ;
unsigned long V_50 , div ;
V_48 = V_48 ? V_48 : 9600 * 16 ;
if ( V_2 -> V_34 -> V_51 < V_48 ) {
if ( V_2 -> V_34 -> V_51 > V_46 )
V_47 = V_2 -> V_34 -> V_51 / V_46 ;
else
V_47 = 1 ;
V_48 = V_46 * V_47 ;
} else {
V_48 *= F_24 ( V_2 -> V_34 -> V_51 / V_48 ) ;
}
F_25 ( V_48 , V_2 -> V_34 -> V_51 , V_49 , V_49 , & V_50 , & div ) ;
V_4 -> V_52 = V_48 * 16 / V_47 ;
F_26 ( V_47 , V_4 -> V_38 + V_53 ) ;
F_26 ( V_50 , V_4 -> V_38 + V_54 ) ;
F_26 ( div , V_4 -> V_38 + V_55 ) ;
F_27 ( V_4 , V_44 , V_45 ) ;
}
static bool F_28 ( struct V_56 * V_57 , void * V_58 )
{
struct V_59 * V_60 = V_58 ;
if ( V_60 -> V_14 != V_57 -> V_8 -> V_7 || V_60 -> V_61 != V_57 -> V_61 )
return false ;
V_57 -> V_62 = V_60 ;
return true ;
}
static int F_29 ( struct V_1 * V_2 , struct V_20 * V_63 )
{
struct V_64 * V_65 = & V_2 -> V_65 ;
struct V_8 * V_7 = V_63 -> V_63 . V_7 ;
struct V_59 * V_66 ;
struct V_59 * V_67 ;
if ( ! V_2 -> V_14 )
return 0 ;
V_66 = F_30 ( V_7 , sizeof( * V_66 ) , V_68 ) ;
if ( ! V_66 )
return - V_69 ;
V_67 = F_30 ( V_7 , sizeof( * V_67 ) , V_68 ) ;
if ( ! V_67 )
return - V_69 ;
V_66 -> V_61 = V_2 -> V_10 * 2 + 1 ;
V_67 -> V_61 = V_2 -> V_10 * 2 ;
V_65 -> V_70 . V_71 = 64 ;
V_65 -> V_72 . V_73 = 64 ;
V_66 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_67 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_65 -> V_74 = F_28 ;
V_65 -> V_66 = V_66 ;
V_65 -> V_67 = V_67 ;
V_63 -> V_65 = V_65 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 , const struct V_75 * V_76 )
{
struct V_20 V_77 ;
struct V_1 * V_2 ;
unsigned int V_33 ;
int V_25 ;
V_25 = F_32 ( V_6 ) ;
if ( V_25 )
return V_25 ;
F_33 ( V_6 ) ;
V_2 = F_30 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_34 = (struct V_78 * ) V_76 -> V_79 ;
V_33 = F_17 ( V_2 -> V_34 -> V_35 ) ;
memset ( & V_77 , 0 , sizeof( struct V_20 ) ) ;
V_77 . V_63 . V_7 = & V_6 -> V_7 ;
V_77 . V_63 . V_36 = V_6 -> V_36 ;
V_77 . V_63 . V_19 = V_2 ;
V_77 . V_63 . type = V_80 ;
V_77 . V_63 . V_81 = V_82 ;
V_77 . V_63 . V_52 = V_2 -> V_34 -> V_83 * 16 ;
V_77 . V_63 . V_35 = V_84 | V_85 | V_86 ;
V_77 . V_63 . V_87 = F_22 ;
V_77 . V_63 . V_88 = F_34 ( V_6 , V_33 ) ;
V_77 . V_63 . V_38 = F_35 ( V_6 , V_33 , 0 ) ;
if ( ! V_77 . V_63 . V_38 )
return - V_69 ;
if ( V_2 -> V_34 -> V_89 ) {
V_25 = V_2 -> V_34 -> V_89 ( V_2 , & V_77 . V_63 ) ;
if ( V_25 )
return V_25 ;
}
V_25 = F_29 ( V_2 , & V_77 ) ;
if ( V_25 )
goto V_27;
V_25 = F_36 ( & V_77 ) ;
if ( V_25 < 0 )
goto V_27;
V_2 -> line = V_25 ;
F_37 ( V_6 , V_2 ) ;
return 0 ;
V_27:
if ( V_2 -> V_34 -> exit )
V_2 -> V_34 -> exit ( V_2 ) ;
return V_25 ;
}
static void F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
if ( V_2 -> V_34 -> exit )
V_2 -> V_34 -> exit ( V_2 ) ;
F_40 ( V_2 -> line ) ;
}
