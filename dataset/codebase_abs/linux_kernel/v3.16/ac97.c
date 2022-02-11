static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( V_5 . V_6 + V_7 ) & 0x7 ;
if ( V_4 == V_8 )
return;
F_3 ( & V_5 . V_9 ) ;
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
F_3 ( & V_5 . V_9 ) ;
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
F_3 ( & V_5 . V_9 ) ;
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
static int F_20 ( struct V_31 * V_32 , int V_33 ,
struct V_34 * V_35 )
{
T_1 V_3 ;
struct V_36 * V_37 = V_32 -> V_38 ;
struct V_39 * V_40 =
F_21 ( V_37 -> V_41 , V_32 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
if ( V_32 -> V_42 == V_43 )
V_3 &= ~ V_44 ;
else
V_3 &= ~ V_45 ;
switch ( V_33 ) {
case V_46 :
case V_47 :
case V_48 :
if ( V_32 -> V_42 == V_43 )
V_3 |= V_49 ;
else
V_3 |= V_50 ;
break;
case V_51 :
case V_52 :
case V_53 :
break;
}
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! V_40 -> V_54 )
V_40 -> V_54 = F_22 () ;
V_40 -> V_54 -> V_55 ( V_40 -> V_56 ) ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 ,
int V_33 , struct V_34 * V_35 )
{
T_1 V_3 ;
struct V_36 * V_37 = V_32 -> V_38 ;
struct V_39 * V_40 =
F_21 ( V_37 -> V_41 , V_32 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 &= ~ V_57 ;
switch ( V_33 ) {
case V_46 :
case V_47 :
case V_48 :
V_3 |= V_58 ;
break;
case V_51 :
case V_52 :
case V_53 :
break;
}
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! V_40 -> V_54 )
V_40 -> V_54 = F_22 () ;
V_40 -> V_54 -> V_55 ( V_40 -> V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_34 * V_35 )
{
F_25 ( V_35 , & V_59 , & V_60 ) ;
return 0 ;
}
static int F_26 ( struct V_34 * V_35 )
{
F_25 ( V_35 , NULL , & V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_62 * V_63 )
{
struct V_64 * V_65 , * V_66 , * V_67 , * V_68 , * V_69 ;
struct V_70 * V_71 ;
int V_72 ;
V_71 = V_63 -> V_73 . V_74 ;
if ( ! V_71 || ! V_71 -> V_75 ) {
F_28 ( & V_63 -> V_73 , L_7 ) ;
return - V_76 ;
}
V_66 = F_29 ( V_63 , V_77 , 0 ) ;
if ( ! V_66 ) {
F_28 ( & V_63 -> V_73 , L_8 ) ;
return - V_78 ;
}
V_67 = F_29 ( V_63 , V_77 , 1 ) ;
if ( ! V_67 ) {
F_28 ( & V_63 -> V_73 , L_9 ) ;
return - V_78 ;
}
V_68 = F_29 ( V_63 , V_77 , 2 ) ;
if ( ! V_68 ) {
F_28 ( & V_63 -> V_73 , L_10 ) ;
return - V_78 ;
}
V_69 = F_29 ( V_63 , V_79 , 0 ) ;
if ( ! V_69 ) {
F_28 ( & V_63 -> V_73 , L_11 ) ;
return - V_78 ;
}
V_65 = F_29 ( V_63 , V_80 , 0 ) ;
V_5 . V_6 = F_30 ( & V_63 -> V_73 , V_65 ) ;
if ( F_31 ( V_5 . V_6 ) )
return F_32 ( V_5 . V_6 ) ;
V_59 . V_56 = V_66 -> V_81 ;
V_59 . V_82 = V_65 -> V_81 + V_83 ;
V_60 . V_56 = V_67 -> V_81 ;
V_60 . V_82 = V_65 -> V_81 + V_83 ;
V_61 . V_56 = V_68 -> V_81 ;
V_61 . V_82 = V_65 -> V_81 + V_84 ;
F_33 ( & V_5 . V_9 ) ;
F_34 ( & V_5 . V_19 ) ;
V_5 . V_85 = F_35 ( & V_63 -> V_73 , L_12 ) ;
if ( F_31 ( V_5 . V_85 ) ) {
F_28 ( & V_63 -> V_73 , L_13 ) ;
V_72 = - V_86 ;
goto V_87;
}
F_36 ( V_5 . V_85 ) ;
if ( V_71 -> V_75 ( V_63 ) ) {
F_28 ( & V_63 -> V_73 , L_14 ) ;
V_72 = - V_76 ;
goto V_88;
}
V_72 = F_37 ( V_69 -> V_81 , F_18 ,
0 , L_15 , NULL ) ;
if ( V_72 < 0 ) {
F_28 ( & V_63 -> V_73 , L_16 ) ;
goto V_89;
}
V_72 = F_38 ( & V_90 ) ;
if ( V_72 != 0 ) {
F_28 ( & V_63 -> V_73 , L_17 , V_72 ) ;
goto V_89;
}
V_72 = F_39 ( & V_63 -> V_73 , & V_91 ,
V_92 , F_40 ( V_92 ) ) ;
if ( V_72 )
goto V_93;
V_72 = F_41 ( & V_63 -> V_73 ) ;
if ( V_72 ) {
F_28 ( & V_63 -> V_73 , L_18 , V_72 ) ;
goto V_93;
}
return 0 ;
V_93:
F_42 ( V_69 -> V_81 , NULL ) ;
V_89:
V_88:
F_43 ( V_5 . V_85 ) ;
V_87:
F_38 ( NULL ) ;
return V_72 ;
}
static int F_44 ( struct V_62 * V_63 )
{
struct V_64 * V_69 ;
V_69 = F_29 ( V_63 , V_79 , 0 ) ;
if ( V_69 )
F_42 ( V_69 -> V_81 , NULL ) ;
F_43 ( V_5 . V_85 ) ;
F_38 ( NULL ) ;
return 0 ;
}
