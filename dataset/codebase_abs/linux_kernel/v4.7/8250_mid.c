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
unsigned int V_20 = F_9 ( V_4 , V_21 ) ;
int V_22 = V_23 ;
if ( V_20 & F_10 ( 2 ) )
V_22 |= F_11 ( & V_2 -> V_24 , 1 ) ;
if ( V_20 & F_10 ( 1 ) )
V_22 |= F_11 ( & V_2 -> V_24 , 0 ) ;
if ( V_20 & F_10 ( 0 ) )
V_22 |= F_12 ( V_4 , F_9 ( V_4 , V_25 ) ) ;
return V_22 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_26 * V_27 = & V_2 -> V_24 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_28 = F_14 ( V_2 -> V_29 -> V_30 ) ;
int V_22 ;
V_27 -> V_7 = & V_6 -> V_7 ;
V_27 -> V_31 = V_6 -> V_31 ;
V_27 -> V_32 = V_4 -> V_33 ;
V_27 -> V_34 = F_15 ( V_6 , V_28 ) ;
V_27 -> V_35 = V_36 ;
V_22 = F_16 ( V_27 ) ;
if ( V_22 )
return 0 ;
V_2 -> V_14 = V_6 ;
V_4 -> V_37 = F_8 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return;
F_18 ( & V_2 -> V_24 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
struct V_38 * V_39 ,
struct V_38 * V_40 )
{
unsigned int V_41 = F_20 ( V_39 ) ;
struct V_1 * V_2 = V_4 -> V_19 ;
unsigned short V_42 = 16 ;
unsigned long V_43 = V_41 * V_42 ;
unsigned long V_44 = F_10 ( 24 ) - 1 ;
unsigned long V_45 , div ;
if ( V_2 -> V_29 -> V_46 < V_43 ) {
if ( V_2 -> V_29 -> V_46 > V_41 )
V_42 = V_2 -> V_29 -> V_46 / V_41 ;
else
V_42 = 1 ;
V_43 = V_41 * V_42 ;
} else {
V_43 *= F_21 ( V_2 -> V_29 -> V_46 / V_43 ) ;
}
F_22 ( V_43 , V_2 -> V_29 -> V_46 , V_44 , V_44 , & V_45 , & div ) ;
V_4 -> V_47 = V_43 * 16 / V_42 ;
F_23 ( V_42 , V_4 -> V_33 + V_48 ) ;
F_23 ( V_45 , V_4 -> V_33 + V_49 ) ;
F_23 ( div , V_4 -> V_33 + V_50 ) ;
F_24 ( V_4 , V_39 , V_40 ) ;
}
static bool F_25 ( struct V_51 * V_52 , void * V_53 )
{
struct V_54 * V_55 = V_53 ;
if ( V_55 -> V_14 != V_52 -> V_8 -> V_7 || V_55 -> V_56 != V_52 -> V_56 )
return false ;
V_52 -> V_57 = V_55 ;
return true ;
}
static int F_26 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_2 -> V_61 ;
struct V_8 * V_7 = V_59 -> V_59 . V_7 ;
struct V_54 * V_62 ;
struct V_54 * V_63 ;
if ( ! V_2 -> V_14 )
return 0 ;
V_62 = F_27 ( V_7 , sizeof( * V_62 ) , V_64 ) ;
if ( ! V_62 )
return - V_65 ;
V_63 = F_27 ( V_7 , sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 )
return - V_65 ;
V_62 -> V_56 = V_2 -> V_10 * 2 + 1 ;
V_63 -> V_56 = V_2 -> V_10 * 2 ;
V_61 -> V_66 . V_67 = 64 ;
V_61 -> V_68 . V_69 = 64 ;
V_62 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_63 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_61 -> V_70 = F_25 ;
V_61 -> V_62 = V_62 ;
V_61 -> V_63 = V_63 ;
V_59 -> V_61 = V_61 ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 , const struct V_71 * V_72 )
{
struct V_58 V_73 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
int V_22 ;
V_22 = F_29 ( V_6 ) ;
if ( V_22 )
return V_22 ;
F_30 ( V_6 ) ;
V_2 = F_27 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_2 -> V_29 = (struct V_74 * ) V_72 -> V_75 ;
V_28 = F_14 ( V_2 -> V_29 -> V_30 ) ;
memset ( & V_73 , 0 , sizeof( struct V_58 ) ) ;
V_73 . V_59 . V_7 = & V_6 -> V_7 ;
V_73 . V_59 . V_31 = V_6 -> V_31 ;
V_73 . V_59 . V_19 = V_2 ;
V_73 . V_59 . type = V_76 ;
V_73 . V_59 . V_77 = V_78 ;
V_73 . V_59 . V_47 = V_2 -> V_29 -> V_79 * 16 ;
V_73 . V_59 . V_30 = V_80 | V_81 | V_82 ;
V_73 . V_59 . V_83 = F_19 ;
V_73 . V_59 . V_84 = F_31 ( V_6 , V_28 ) ;
V_73 . V_59 . V_33 = F_32 ( V_6 , V_28 , 0 ) ;
if ( ! V_73 . V_59 . V_33 )
return - V_65 ;
if ( V_2 -> V_29 -> V_85 ) {
V_22 = V_2 -> V_29 -> V_85 ( V_2 , & V_73 . V_59 ) ;
if ( V_22 )
return V_22 ;
}
V_22 = F_26 ( V_2 , & V_73 ) ;
if ( V_22 )
goto V_86;
V_22 = F_33 ( & V_73 ) ;
if ( V_22 < 0 )
goto V_86;
V_2 -> line = V_22 ;
F_34 ( V_6 , V_2 ) ;
return 0 ;
V_86:
if ( V_2 -> V_29 -> exit )
V_2 -> V_29 -> exit ( V_2 ) ;
return V_22 ;
}
static void F_35 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 ) ;
if ( V_2 -> V_29 -> exit )
V_2 -> V_29 -> exit ( V_2 ) ;
F_37 ( V_2 -> line ) ;
}
