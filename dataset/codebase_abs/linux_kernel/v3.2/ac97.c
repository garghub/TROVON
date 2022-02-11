static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( V_5 . V_6 + V_7 ) & 0x7 ;
if ( V_4 == V_8 )
return;
F_3 ( V_5 . V_9 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 = V_11 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
V_3 |= V_12 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! F_6 ( & V_5 . V_9 , V_14 ) )
F_7 ( L_1 ) ;
}
static unsigned short F_8 ( struct V_1 * V_2 ,
unsigned short V_15 )
{
T_1 V_3 , V_16 ;
T_1 V_4 , V_17 , V_18 ;
F_9 ( & V_5 . V_19 ) ;
F_1 ( V_2 ) ;
F_3 ( V_5 . V_9 ) ;
V_16 = F_2 ( V_5 . V_6 + V_20 ) ;
V_16 = V_21 | F_10 ( V_15 ) ;
F_4 ( V_16 , V_5 . V_6 + V_20 ) ;
F_11 ( 50 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! F_6 ( & V_5 . V_9 , V_14 ) )
F_7 ( L_2 ) ;
V_4 = F_2 ( V_5 . V_6 + V_22 ) ;
V_17 = ( V_4 >> 16 ) & 0x7f ;
V_18 = ( V_4 & 0xffff ) ;
if ( V_17 != V_15 )
F_7 ( L_3 ,
V_15 , V_17 ) ;
F_12 ( & V_5 . V_19 ) ;
return ( unsigned short ) V_18 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned short V_15 ,
unsigned short V_23 )
{
T_1 V_3 , V_16 ;
F_9 ( & V_5 . V_19 ) ;
F_1 ( V_2 ) ;
F_3 ( V_5 . V_9 ) ;
V_16 = F_2 ( V_5 . V_6 + V_20 ) ;
V_16 = F_10 ( V_15 ) | F_14 ( V_23 ) ;
F_4 ( V_16 , V_5 . V_6 + V_20 ) ;
F_11 ( 50 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! F_6 ( & V_5 . V_9 , V_14 ) )
F_7 ( L_4 ) ;
V_16 = F_2 ( V_5 . V_6 + V_20 ) ;
V_16 |= V_21 ;
F_4 ( V_16 , V_5 . V_6 + V_20 ) ;
F_12 ( & V_5 . V_19 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( L_5 ) ;
F_4 ( V_24 ,
V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( 0 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_5 . V_6 + V_7 ) & 0x7 ;
if ( V_4 == V_8 )
return;
F_16 ( L_6 ) ;
F_4 ( V_25 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( 0 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
F_1 ( V_2 ) ;
}
static T_2 F_18 ( int V_26 , void * V_27 )
{
T_1 V_3 , V_28 ;
V_28 = F_2 ( V_5 . V_6 + V_7 ) ;
if ( V_28 & V_29 ) {
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 &= ~ V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
F_19 ( & V_5 . V_9 ) ;
}
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= ( 1 << 30 ) ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
return V_30 ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_32 -> V_39 ;
struct V_35 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 ;
if ( V_32 -> V_43 == V_44 )
V_42 = & V_45 ;
else
V_42 = & V_46 ;
F_21 ( V_40 , V_32 , V_42 ) ;
return 0 ;
}
static int F_22 ( struct V_31 * V_32 , int V_47 ,
struct V_35 * V_36 )
{
T_1 V_3 ;
struct V_37 * V_38 = V_32 -> V_39 ;
struct V_41 * V_42 =
F_23 ( V_38 -> V_40 , V_32 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
if ( V_32 -> V_43 == V_48 )
V_3 &= ~ V_49 ;
else
V_3 &= ~ V_50 ;
switch ( V_47 ) {
case V_51 :
case V_52 :
case V_53 :
if ( V_32 -> V_43 == V_48 )
V_3 |= V_54 ;
else
V_3 |= V_55 ;
break;
case V_56 :
case V_57 :
case V_58 :
break;
}
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! V_42 -> V_59 )
V_42 -> V_59 = F_24 () ;
V_42 -> V_59 -> V_60 ( V_42 -> V_61 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_32 -> V_39 ;
struct V_35 * V_40 = V_38 -> V_40 ;
if ( V_32 -> V_43 == V_44 )
return - V_62 ;
else
F_21 ( V_40 , V_32 , & V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_32 ,
int V_47 , struct V_35 * V_36 )
{
T_1 V_3 ;
struct V_37 * V_38 = V_32 -> V_39 ;
struct V_41 * V_42 =
F_23 ( V_38 -> V_40 , V_32 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 &= ~ V_64 ;
switch ( V_47 ) {
case V_51 :
case V_52 :
case V_53 :
V_3 |= V_65 ;
break;
case V_56 :
case V_57 :
case V_58 :
break;
}
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! V_42 -> V_59 )
V_42 -> V_59 = F_24 () ;
V_42 -> V_59 -> V_60 ( V_42 -> V_61 ) ;
return 0 ;
}
static T_3 int F_27 ( struct V_66 * V_67 )
{
struct V_68 * V_69 , * V_70 , * V_71 , * V_72 , * V_73 ;
struct V_74 * V_75 ;
int V_76 ;
V_75 = V_67 -> V_77 . V_78 ;
if ( ! V_75 || ! V_75 -> V_79 ) {
F_28 ( & V_67 -> V_77 , L_7 ) ;
return - V_80 ;
}
V_70 = F_29 ( V_67 , V_81 , 0 ) ;
if ( ! V_70 ) {
F_28 ( & V_67 -> V_77 , L_8 ) ;
return - V_82 ;
}
V_71 = F_29 ( V_67 , V_81 , 1 ) ;
if ( ! V_71 ) {
F_28 ( & V_67 -> V_77 , L_9 ) ;
return - V_82 ;
}
V_72 = F_29 ( V_67 , V_81 , 2 ) ;
if ( ! V_72 ) {
F_28 ( & V_67 -> V_77 , L_10 ) ;
return - V_82 ;
}
V_69 = F_29 ( V_67 , V_83 , 0 ) ;
if ( ! V_69 ) {
F_28 ( & V_67 -> V_77 , L_11 ) ;
return - V_82 ;
}
V_73 = F_29 ( V_67 , V_84 , 0 ) ;
if ( ! V_73 ) {
F_28 ( & V_67 -> V_77 , L_12 ) ;
return - V_82 ;
}
if ( ! F_30 ( V_69 -> V_85 ,
F_31 ( V_69 ) , L_13 ) ) {
F_28 ( & V_67 -> V_77 , L_14 ) ;
return - V_86 ;
}
V_45 . V_61 = V_70 -> V_85 ;
V_45 . V_87 = V_69 -> V_85 + V_88 ;
V_46 . V_61 = V_71 -> V_85 ;
V_46 . V_87 = V_69 -> V_85 + V_88 ;
V_63 . V_61 = V_72 -> V_85 ;
V_63 . V_87 = V_69 -> V_85 + V_89 ;
F_32 ( & V_5 . V_9 ) ;
F_33 ( & V_5 . V_19 ) ;
V_5 . V_6 = F_34 ( V_69 -> V_85 , F_31 ( V_69 ) ) ;
if ( V_5 . V_6 == NULL ) {
F_28 ( & V_67 -> V_77 , L_15 ) ;
V_76 = - V_82 ;
goto V_90;
}
V_5 . V_91 = F_35 ( & V_67 -> V_77 , L_13 ) ;
if ( F_36 ( V_5 . V_91 ) ) {
F_28 ( & V_67 -> V_77 , L_16 ) ;
V_76 = - V_62 ;
goto V_92;
}
F_37 ( V_5 . V_91 ) ;
if ( V_75 -> V_79 ( V_67 ) ) {
F_28 ( & V_67 -> V_77 , L_17 ) ;
V_76 = - V_80 ;
goto V_93;
}
V_76 = F_38 ( V_73 -> V_85 , F_18 ,
0 , L_18 , NULL ) ;
if ( V_76 < 0 ) {
F_28 ( & V_67 -> V_77 , L_19 ) ;
goto V_94;
}
V_76 = F_39 ( & V_67 -> V_77 , V_95 ,
F_40 ( V_95 ) ) ;
if ( V_76 )
goto V_96;
return 0 ;
V_96:
F_41 ( V_73 -> V_85 , NULL ) ;
V_94:
V_93:
F_42 ( V_5 . V_91 ) ;
F_43 ( V_5 . V_91 ) ;
V_92:
F_44 ( V_5 . V_6 ) ;
V_90:
F_45 ( V_69 -> V_85 , F_31 ( V_69 ) ) ;
return V_76 ;
}
static T_4 int F_46 ( struct V_66 * V_67 )
{
struct V_68 * V_69 , * V_73 ;
F_47 ( & V_67 -> V_77 , F_40 ( V_95 ) ) ;
V_73 = F_29 ( V_67 , V_84 , 0 ) ;
if ( V_73 )
F_41 ( V_73 -> V_85 , NULL ) ;
F_42 ( V_5 . V_91 ) ;
F_43 ( V_5 . V_91 ) ;
F_44 ( V_5 . V_6 ) ;
V_69 = F_29 ( V_67 , V_83 , 0 ) ;
if ( V_69 )
F_45 ( V_69 -> V_85 , F_31 ( V_69 ) ) ;
return 0 ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_97 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_97 ) ;
}
