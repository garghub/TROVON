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
static int F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_17 ;
struct V_18 * V_19 = F_7 ( V_4 ) ;
struct V_20 * V_21 ;
T_1 V_22 ;
int V_23 = 0 ;
int V_24 ;
V_21 = F_8 ( V_2 -> V_14 ) ;
V_24 = F_9 ( V_21 , V_2 -> V_10 * 2 + 1 , & V_22 ) ;
if ( V_24 > 0 ) {
F_10 ( V_19 ) ;
V_23 |= 1 ;
} else if ( V_24 == 0 )
V_23 |= F_11 ( V_21 , V_2 -> V_10 * 2 + 1 , V_22 ) ;
V_24 = F_9 ( V_21 , V_2 -> V_10 * 2 , & V_22 ) ;
if ( V_24 > 0 )
V_23 |= 1 ;
else if ( V_24 == 0 )
V_23 |= F_11 ( V_21 , V_2 -> V_10 * 2 , V_22 ) ;
V_23 |= F_12 ( V_4 , F_13 ( V_4 , V_25 ) ) ;
return F_14 ( V_23 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
int V_26 = F_16 ( V_6 -> V_16 ) ;
if ( V_26 -- == 0 )
return - V_27 ;
V_2 -> V_10 = V_26 ;
V_2 -> V_14 = F_3 ( V_6 -> V_15 , F_4 ( 5 , 0 ) ) ;
V_4 -> V_28 = F_6 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_17 ;
struct V_18 * V_19 = F_7 ( V_4 ) ;
unsigned int V_29 = F_13 ( V_4 , V_30 ) ;
T_1 V_22 ;
int V_23 = 0 ;
int V_24 ;
if ( V_29 & F_18 ( 2 ) ) {
V_24 = F_9 ( & V_2 -> V_31 , 1 , & V_22 ) ;
if ( V_24 > 0 ) {
F_10 ( V_19 ) ;
V_23 |= 1 ;
} else if ( V_24 == 0 )
V_23 |= F_11 ( & V_2 -> V_31 , 1 , V_22 ) ;
}
if ( V_29 & F_18 ( 1 ) ) {
V_24 = F_9 ( & V_2 -> V_31 , 0 , & V_22 ) ;
if ( V_24 > 0 )
V_23 |= 1 ;
else if ( V_24 == 0 )
V_23 |= F_11 ( & V_2 -> V_31 , 0 , V_22 ) ;
}
if ( V_29 & F_18 ( 0 ) )
V_23 |= F_12 ( V_4 , F_13 ( V_4 , V_25 ) ) ;
return F_14 ( V_23 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_2 -> V_31 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_32 = F_20 ( V_2 -> V_33 -> V_34 ) ;
int V_23 ;
F_21 ( V_6 ) ;
V_23 = F_22 ( V_6 , 1 , 1 , V_35 ) ;
if ( V_23 < 0 )
return V_23 ;
V_4 -> V_36 = F_23 ( V_6 , 0 ) ;
V_21 -> V_7 = & V_6 -> V_7 ;
V_21 -> V_36 = F_23 ( V_6 , 0 ) ;
V_21 -> V_37 = V_4 -> V_38 ;
V_21 -> V_39 = F_24 ( V_6 , V_32 ) ;
V_21 -> V_40 = V_41 ;
V_23 = F_25 ( V_21 ) ;
if ( V_23 )
return 0 ;
V_2 -> V_14 = V_6 ;
V_4 -> V_28 = F_17 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return;
F_27 ( & V_2 -> V_31 ) ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_42 * V_43 ,
struct V_42 * V_44 )
{
unsigned int V_45 = F_29 ( V_43 ) ;
struct V_1 * V_2 = V_4 -> V_17 ;
unsigned short V_46 = 16 ;
unsigned long V_47 = V_45 * V_46 ;
unsigned long V_48 = F_18 ( 24 ) - 1 ;
unsigned long V_49 , div ;
V_47 = V_47 ? V_47 : 9600 * 16 ;
if ( V_2 -> V_33 -> V_50 < V_47 ) {
if ( V_2 -> V_33 -> V_50 > V_45 )
V_46 = V_2 -> V_33 -> V_50 / V_45 ;
else
V_46 = 1 ;
V_47 = V_45 * V_46 ;
} else {
V_47 *= F_30 ( V_2 -> V_33 -> V_50 / V_47 ) ;
}
F_31 ( V_47 , V_2 -> V_33 -> V_50 , V_48 , V_48 , & V_49 , & div ) ;
V_4 -> V_51 = V_47 * 16 / V_46 ;
F_32 ( V_46 , V_4 -> V_38 + V_52 ) ;
F_32 ( V_49 , V_4 -> V_38 + V_53 ) ;
F_32 ( div , V_4 -> V_38 + V_54 ) ;
F_33 ( V_4 , V_43 , V_44 ) ;
}
static bool F_34 ( struct V_55 * V_56 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
if ( V_59 -> V_14 != V_56 -> V_8 -> V_7 || V_59 -> V_60 != V_56 -> V_60 )
return false ;
V_56 -> V_61 = V_59 ;
return true ;
}
static int F_35 ( struct V_1 * V_2 , struct V_18 * V_62 )
{
struct V_63 * V_64 = & V_2 -> V_64 ;
struct V_8 * V_7 = V_62 -> V_62 . V_7 ;
struct V_58 * V_65 ;
struct V_58 * V_66 ;
if ( ! V_2 -> V_14 )
return 0 ;
V_65 = F_36 ( V_7 , sizeof( * V_65 ) , V_67 ) ;
if ( ! V_65 )
return - V_68 ;
V_66 = F_36 ( V_7 , sizeof( * V_66 ) , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
V_65 -> V_60 = V_2 -> V_10 * 2 + 1 ;
V_66 -> V_60 = V_2 -> V_10 * 2 ;
V_64 -> V_69 . V_70 = 64 ;
V_64 -> V_71 . V_72 = 64 ;
V_65 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_66 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_64 -> V_73 = F_34 ;
V_64 -> V_65 = V_65 ;
V_64 -> V_66 = V_66 ;
V_62 -> V_64 = V_64 ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 , const struct V_74 * V_75 )
{
struct V_18 V_76 ;
struct V_1 * V_2 ;
unsigned int V_32 ;
int V_23 ;
V_23 = F_38 ( V_6 ) ;
if ( V_23 )
return V_23 ;
V_2 = F_36 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_2 -> V_33 = (struct V_77 * ) V_75 -> V_78 ;
V_32 = F_20 ( V_2 -> V_33 -> V_34 ) ;
memset ( & V_76 , 0 , sizeof( struct V_18 ) ) ;
V_76 . V_62 . V_7 = & V_6 -> V_7 ;
V_76 . V_62 . V_36 = V_6 -> V_36 ;
V_76 . V_62 . V_17 = V_2 ;
V_76 . V_62 . type = V_79 ;
V_76 . V_62 . V_80 = V_81 ;
V_76 . V_62 . V_51 = V_2 -> V_33 -> V_82 * 16 ;
V_76 . V_62 . V_34 = V_83 | V_84 | V_85 ;
V_76 . V_62 . V_86 = F_28 ;
V_76 . V_62 . V_87 = F_39 ( V_6 , V_32 ) ;
V_76 . V_62 . V_38 = F_40 ( V_6 , V_32 , 0 ) ;
if ( ! V_76 . V_62 . V_38 )
return - V_68 ;
if ( V_2 -> V_33 -> V_88 ) {
V_23 = V_2 -> V_33 -> V_88 ( V_2 , & V_76 . V_62 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_35 ( V_2 , & V_76 ) ;
if ( V_23 )
goto V_24;
V_23 = F_41 ( & V_76 ) ;
if ( V_23 < 0 )
goto V_24;
V_2 -> line = V_23 ;
F_42 ( V_6 , V_2 ) ;
return 0 ;
V_24:
if ( V_2 -> V_33 -> exit )
V_2 -> V_33 -> exit ( V_2 ) ;
return V_23 ;
}
static void F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
F_44 ( V_2 -> line ) ;
if ( V_2 -> V_33 -> exit )
V_2 -> V_33 -> exit ( V_2 ) ;
}
