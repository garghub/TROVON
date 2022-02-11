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
int V_20 ;
V_20 = F_9 ( & V_2 -> V_21 , 0 ) ;
V_20 |= F_9 ( & V_2 -> V_21 , 1 ) ;
if ( V_20 )
return V_20 ;
return F_10 ( V_4 , F_11 ( V_4 , V_22 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_23 * V_24 = & V_2 -> V_21 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
int V_20 ;
V_24 -> V_7 = & V_6 -> V_7 ;
V_24 -> V_25 = V_6 -> V_25 ;
V_24 -> V_26 = V_4 -> V_27 ;
V_24 -> V_28 = F_13 ( V_6 , 0 ) ;
V_24 -> V_29 = V_30 ;
V_20 = F_14 ( V_24 ) ;
if ( V_20 )
return 0 ;
V_2 -> V_14 = V_6 ;
V_4 -> V_31 = F_8 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return;
F_16 ( & V_2 -> V_21 ) ;
}
static void F_17 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
struct V_32 * V_34 )
{
unsigned int V_35 = F_18 ( V_33 ) ;
struct V_1 * V_2 = V_4 -> V_19 ;
unsigned short V_36 = 16 ;
unsigned long V_37 = V_35 * V_36 ;
unsigned long V_38 = F_19 ( 24 ) - 1 ;
unsigned long V_39 , div ;
if ( V_2 -> V_40 -> V_41 < V_37 ) {
if ( V_2 -> V_40 -> V_41 > V_35 )
V_36 = V_2 -> V_40 -> V_41 / V_35 ;
else
V_36 = 1 ;
V_37 = V_35 * V_36 ;
} else {
V_37 *= F_20 ( V_2 -> V_40 -> V_41 / V_37 ) ;
}
F_21 ( V_37 , V_2 -> V_40 -> V_41 , V_38 , V_38 , & V_39 , & div ) ;
V_4 -> V_42 = V_37 * 16 / V_36 ;
F_22 ( V_36 , V_4 -> V_27 + V_43 ) ;
F_22 ( V_39 , V_4 -> V_27 + V_44 ) ;
F_22 ( div , V_4 -> V_27 + V_45 ) ;
F_23 ( V_4 , V_33 , V_34 ) ;
}
static bool F_24 ( struct V_46 * V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
if ( V_50 -> V_14 != V_47 -> V_8 -> V_7 || V_50 -> V_51 != V_47 -> V_51 )
return false ;
V_47 -> V_52 = V_50 ;
return true ;
}
static int F_25 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_8 * V_7 = V_54 -> V_54 . V_7 ;
struct V_49 * V_57 ;
struct V_49 * V_58 ;
if ( ! V_2 -> V_14 )
return 0 ;
V_57 = F_26 ( V_7 , sizeof( * V_57 ) , V_59 ) ;
if ( ! V_57 )
return - V_60 ;
V_58 = F_26 ( V_7 , sizeof( * V_58 ) , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
V_57 -> V_51 = V_2 -> V_10 * 2 + 1 ;
V_58 -> V_51 = V_2 -> V_10 * 2 ;
V_56 -> V_61 . V_62 = 64 ;
V_56 -> V_63 . V_64 = 64 ;
V_57 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_58 -> V_14 = & V_2 -> V_14 -> V_7 ;
V_56 -> V_65 = F_24 ;
V_56 -> V_57 = V_57 ;
V_56 -> V_58 = V_58 ;
V_54 -> V_56 = V_56 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , const struct V_66 * V_67 )
{
struct V_53 V_68 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_28 ( V_6 ) ;
if ( V_20 )
return V_20 ;
F_29 ( V_6 ) ;
V_2 = F_26 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_40 = (struct V_69 * ) V_67 -> V_70 ;
memset ( & V_68 , 0 , sizeof( struct V_53 ) ) ;
V_68 . V_54 . V_7 = & V_6 -> V_7 ;
V_68 . V_54 . V_25 = V_6 -> V_25 ;
V_68 . V_54 . V_19 = V_2 ;
V_68 . V_54 . type = V_71 ;
V_68 . V_54 . V_72 = V_73 ;
V_68 . V_54 . V_42 = V_2 -> V_40 -> V_74 * 16 ;
V_68 . V_54 . V_75 = V_76 | V_77 | V_78 ;
V_68 . V_54 . V_79 = F_17 ;
V_68 . V_54 . V_80 = F_30 ( V_6 , 0 ) ;
V_68 . V_54 . V_27 = F_31 ( V_6 , 0 , 0 ) ;
if ( ! V_68 . V_54 . V_27 )
return - V_60 ;
if ( V_2 -> V_40 -> V_81 ) {
V_20 = V_2 -> V_40 -> V_81 ( V_2 , & V_68 . V_54 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_25 ( V_2 , & V_68 ) ;
if ( V_20 )
goto V_82;
V_20 = F_32 ( & V_68 ) ;
if ( V_20 < 0 )
goto V_82;
V_2 -> line = V_20 ;
F_33 ( V_6 , V_2 ) ;
return 0 ;
V_82:
if ( V_2 -> V_40 -> exit )
V_2 -> V_40 -> exit ( V_2 ) ;
return V_20 ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 ) ;
if ( V_2 -> V_40 -> exit )
V_2 -> V_40 -> exit ( V_2 ) ;
F_36 ( V_2 -> line ) ;
}
