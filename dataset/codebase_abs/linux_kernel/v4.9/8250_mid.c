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
int V_25 = 0 ;
int V_26 ;
if ( V_22 & F_11 ( 2 ) ) {
V_26 = F_12 ( & V_2 -> V_27 , 1 , & V_24 ) ;
if ( V_26 > 0 ) {
F_13 ( V_21 ) ;
V_25 |= 1 ;
} else if ( V_26 == 0 )
V_25 |= F_14 ( & V_2 -> V_27 , 1 , V_24 ) ;
}
if ( V_22 & F_11 ( 1 ) ) {
V_26 = F_12 ( & V_2 -> V_27 , 0 , & V_24 ) ;
if ( V_26 > 0 )
V_25 |= 1 ;
else if ( V_26 == 0 )
V_25 |= F_14 ( & V_2 -> V_27 , 0 , V_24 ) ;
}
if ( V_22 & F_11 ( 0 ) )
V_25 |= F_15 ( V_4 , F_10 ( V_4 , V_28 ) ) ;
return F_16 ( V_25 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = & V_2 -> V_27 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_31 = F_18 ( V_2 -> V_32 -> V_33 ) ;
int V_25 ;
V_30 -> V_7 = & V_6 -> V_7 ;
V_30 -> V_34 = V_6 -> V_34 ;
V_30 -> V_35 = V_4 -> V_36 ;
V_30 -> V_37 = F_19 ( V_6 , V_31 ) ;
V_30 -> V_38 = V_39 ;
V_25 = F_20 ( V_30 ) ;
if ( V_25 )
return 0 ;
V_2 -> V_14 = V_6 ;
V_4 -> V_40 = F_8 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return;
F_22 ( & V_2 -> V_27 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
struct V_41 * V_42 ,
struct V_41 * V_43 )
{
unsigned int V_44 = F_24 ( V_42 ) ;
struct V_1 * V_2 = V_4 -> V_19 ;
unsigned short V_45 = 16 ;
unsigned long V_46 = V_44 * V_45 ;
unsigned long V_47 = F_11 ( 24 ) - 1 ;
unsigned long V_48 , div ;
V_46 = V_46 ? V_46 : 9600 * 16 ;
if ( V_2 -> V_32 -> V_49 < V_46 ) {
if ( V_2 -> V_32 -> V_49 > V_44 )
V_45 = V_2 -> V_32 -> V_49 / V_44 ;
else
V_45 = 1 ;
V_46 = V_44 * V_45 ;
} else {
V_46 *= F_25 ( V_2 -> V_32 -> V_49 / V_46 ) ;
}
F_26 ( V_46 , V_2 -> V_32 -> V_49 , V_47 , V_47 , & V_48 , & div ) ;
V_4 -> V_50 = V_46 * 16 / V_45 ;
F_27 ( V_45 , V_4 -> V_36 + V_51 ) ;
F_27 ( V_48 , V_4 -> V_36 + V_52 ) ;
F_27 ( div , V_4 -> V_36 + V_53 ) ;
F_28 ( V_4 , V_42 , V_43 ) ;
}
static bool F_29 ( struct V_54 * V_55 , void * V_56 )
{
struct V_57 * V_58 = V_56 ;
if ( V_58 -> V_14 != V_55 -> V_8 -> V_7 || V_58 -> V_59 != V_55 -> V_59 )
return false ;
V_55 -> V_60 = V_58 ;
return true ;
}
static int F_30 ( struct V_1 * V_2 , struct V_20 * V_61 )
{
struct V_62 * V_63 = & V_2 -> V_63 ;
struct V_8 * V_7 = V_61 -> V_61 . V_7 ;
struct V_57 * V_64 ;
struct V_57 * V_65 ;
if ( ! V_2 -> V_14 )
return 0 ;
V_64 = F_31 ( V_7 , sizeof( * V_64 ) , V_66 ) ;
if ( ! V_64 )
return - V_67 ;
V_65 = F_31 ( V_7 , sizeof( * V_65 ) , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_64 -> V_59 = V_2 -> V_10 * 2 + 1 ;
V_65 -> V_59 = V_2 -> V_10 * 2 ;
V_63 -> V_68 . V_69 = 64 ;
V_63 -> V_70 . V_71 = 64 ;
V_64 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_65 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_63 -> V_72 = F_29 ;
V_63 -> V_64 = V_64 ;
V_63 -> V_65 = V_65 ;
V_61 -> V_63 = V_63 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 , const struct V_73 * V_74 )
{
struct V_20 V_75 ;
struct V_1 * V_2 ;
unsigned int V_31 ;
int V_25 ;
V_25 = F_33 ( V_6 ) ;
if ( V_25 )
return V_25 ;
F_34 ( V_6 ) ;
V_2 = F_31 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
V_2 -> V_32 = (struct V_76 * ) V_74 -> V_77 ;
V_31 = F_18 ( V_2 -> V_32 -> V_33 ) ;
memset ( & V_75 , 0 , sizeof( struct V_20 ) ) ;
V_75 . V_61 . V_7 = & V_6 -> V_7 ;
V_75 . V_61 . V_34 = V_6 -> V_34 ;
V_75 . V_61 . V_19 = V_2 ;
V_75 . V_61 . type = V_78 ;
V_75 . V_61 . V_79 = V_80 ;
V_75 . V_61 . V_50 = V_2 -> V_32 -> V_81 * 16 ;
V_75 . V_61 . V_33 = V_82 | V_83 | V_84 ;
V_75 . V_61 . V_85 = F_23 ;
V_75 . V_61 . V_86 = F_35 ( V_6 , V_31 ) ;
V_75 . V_61 . V_36 = F_36 ( V_6 , V_31 , 0 ) ;
if ( ! V_75 . V_61 . V_36 )
return - V_67 ;
if ( V_2 -> V_32 -> V_87 ) {
V_25 = V_2 -> V_32 -> V_87 ( V_2 , & V_75 . V_61 ) ;
if ( V_25 )
return V_25 ;
}
V_25 = F_30 ( V_2 , & V_75 ) ;
if ( V_25 )
goto V_26;
V_25 = F_37 ( & V_75 ) ;
if ( V_25 < 0 )
goto V_26;
V_2 -> line = V_25 ;
F_38 ( V_6 , V_2 ) ;
return 0 ;
V_26:
if ( V_2 -> V_32 -> exit )
V_2 -> V_32 -> exit ( V_2 ) ;
return V_25 ;
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
if ( V_2 -> V_32 -> exit )
V_2 -> V_32 -> exit ( V_2 ) ;
F_41 ( V_2 -> line ) ;
}
