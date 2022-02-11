static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_2 ( unsigned long V_3 )
{
struct V_4 * V_5 = ( void * ) V_3 ;
unsigned V_6 = F_3 () ;
if ( V_6 != V_5 -> V_6 ) {
V_5 -> V_6 = V_6 ;
F_4 ( L_1 , V_7 ,
V_6 ? L_2 : L_3 ) ;
F_5 ( & V_5 -> V_8 , V_9 ) ;
}
if ( V_5 -> V_10 )
F_6 ( & V_5 -> V_11 , V_12 + V_13 ) ;
}
static T_1 F_7 ( int V_14 , void * V_3 )
{
F_2 ( ( unsigned long ) V_3 ) ;
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 * V_16 )
{
if ( ! V_16 )
return - V_17 ;
if ( F_3 () ) {
struct V_4 * V_5 ;
* V_16 = V_18 | V_9 | V_19 | V_20 ;
V_5 = F_9 ( V_2 , struct V_4 , V_8 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = V_5 -> V_14 ;
} else
* V_16 = 0 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_23 , struct V_24 * V_2 )
{
T_3 V_25 ;
switch ( V_2 -> V_26 ) {
case 0 :
case 33 :
break;
default:
return - V_17 ;
}
V_25 = F_11 ( V_27 ) ;
if ( V_2 -> V_28 & V_29 )
F_12 ( V_30 , V_27 ) ;
else
F_12 ( 0 , V_27 ) ;
F_4 ( L_4 ,
V_7 , V_2 -> V_26 , V_2 -> V_31 , V_2 -> V_28 , V_2 -> V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_4 ( L_5 , V_7 , V_33 ) ;
return F_10 ( V_2 , & V_34 ) ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_4 * V_5 ;
V_5 = F_9 ( V_2 , struct V_4 , V_8 ) ;
V_36 -> V_28 &= V_37 | V_38 | V_39 ;
V_36 -> V_40 = V_5 -> V_41 + V_42 ;
V_36 -> V_43 = V_36 -> V_40 + V_44 - 1 ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_4 * V_5 ;
if ( V_46 -> V_47 )
return - V_17 ;
V_5 = F_9 ( V_2 , struct V_4 , V_8 ) ;
V_46 -> V_48 = V_5 -> V_41 ;
V_46 -> V_28 &= V_37 | V_38 | V_39 ;
if ( V_46 -> V_28 & V_38 )
V_46 -> V_48 += V_44 ;
return 0 ;
}
static int T_4 F_16 ( struct V_49 * V_50 )
{
unsigned V_51 ;
struct V_4 * V_5 ;
int V_14 ;
int V_52 ;
V_51 = ( int ) V_50 -> V_53 . V_54 ;
if ( V_51 == 0 || V_51 > 3 )
return - V_55 ;
V_14 = F_17 ( V_50 , 0 ) ;
if ( V_14 < 0 )
return - V_17 ;
V_5 = F_18 ( sizeof *V_5 , V_56 ) ;
if ( ! V_5 )
return - V_57 ;
F_19 ( & V_5 -> V_11 ) ;
V_5 -> V_11 . V_58 = F_2 ;
V_5 -> V_11 . V_59 = ( unsigned long ) V_5 ;
V_5 -> V_50 = V_50 ;
F_20 ( V_50 , V_5 ) ;
V_52 = F_21 ( V_14 , F_7 , V_60 ,
V_7 , V_5 ) ;
if ( V_52 < 0 )
goto V_61;
V_5 -> V_14 = V_14 ;
V_5 -> V_8 . V_22 = V_14 ;
switch ( V_51 ) {
case 1 :
V_5 -> V_41 = V_62 ;
break;
case 2 :
V_5 -> V_41 = V_63 ;
break;
case 3 :
V_5 -> V_41 = F_22 () ;
break;
default:
goto V_64;
}
V_5 -> V_65 . V_40 = V_5 -> V_41 ;
V_5 -> V_65 . V_66 = V_5 -> V_65 . V_66 + V_67 - 1 ;
V_5 -> V_65 . V_28 = V_68 ;
V_5 -> V_8 . V_69 = ( unsigned long )
F_23 ( V_5 -> V_41 + V_42 , V_44 ) ;
if ( ! V_5 -> V_8 . V_69 )
goto V_64;
if ( ! F_24 ( V_5 -> V_41 , V_67 , V_7 ) )
goto V_64;
F_25 ( V_70 ) ;
F_25 ( V_71 ) ;
F_25 ( V_72 ) ;
F_25 ( V_73 ) ;
F_25 ( V_74 ) ;
F_12 ( ~ ( 1 << V_51 ) , V_75 ) ;
F_26 ( L_6 , V_7 , V_51 , V_14 ) ;
F_4 ( L_7 , V_7 ,
V_51 , F_27 ( F_28 ( V_51 ) ) , F_27 ( F_29 ( V_51 ) ) ) ;
F_30 ( 0x0004a1b3 , F_28 ( V_51 ) ) ;
F_30 ( 0x00000000 , F_29 ( V_51 ) ) ;
F_4 ( L_8 , V_7 ,
F_11 ( V_76 ) , F_11 ( V_75 ) ,
F_11 ( V_27 ) ,
F_3 () ? L_2 : L_9 ) ;
V_5 -> V_8 . V_77 = V_78 ;
V_5 -> V_8 . V_53 . V_79 = & V_50 -> V_53 ;
V_5 -> V_8 . V_80 = & V_81 ;
V_5 -> V_8 . V_82 = & V_83 ;
V_5 -> V_8 . V_84 = V_85 | V_86
| V_87 ;
V_5 -> V_8 . V_88 = V_44 ;
V_5 -> V_8 . V_36 [ 0 ] . V_89 = & V_5 -> V_65 ;
V_52 = F_31 ( & V_5 -> V_8 ) ;
if ( V_52 < 0 )
goto V_90;
V_5 -> V_10 = 1 ;
F_6 ( & V_5 -> V_11 , V_12 + V_13 ) ;
return 0 ;
V_90:
F_32 ( V_5 -> V_41 , V_67 ) ;
V_64:
if ( V_5 -> V_8 . V_69 )
F_33 ( ( void V_91 * ) V_5 -> V_8 . V_69 ) ;
F_34 ( V_14 , V_5 ) ;
V_61:
F_35 ( V_5 ) ;
return V_52 ;
}
static int T_5 F_36 ( struct V_49 * V_50 )
{
struct V_4 * V_5 = F_37 ( V_50 ) ;
V_5 -> V_10 = 0 ;
F_38 ( & V_5 -> V_8 ) ;
F_39 ( & V_5 -> V_11 ) ;
F_33 ( ( void V_91 * ) V_5 -> V_8 . V_69 ) ;
F_32 ( V_5 -> V_41 , V_67 ) ;
F_34 ( V_5 -> V_14 , V_5 ) ;
F_35 ( V_5 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
if ( F_41 () )
return F_42 ( & V_92 , F_16 ) ;
return - V_55 ;
}
static void T_5 F_43 ( void )
{
if ( F_41 () )
F_44 ( & V_92 ) ;
}
