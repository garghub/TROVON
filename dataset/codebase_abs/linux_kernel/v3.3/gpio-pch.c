static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_5 = F_4 ( & V_7 -> V_9 -> V_10 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_9 -> V_10 ) ;
F_6 ( & V_7 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return F_4 ( & V_7 -> V_9 -> V_11 ) & ( 1 << V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_12 ;
T_1 V_5 ;
F_3 ( & V_7 -> V_8 ) ;
V_12 = F_4 ( & V_7 -> V_9 -> V_12 ) & ( ( 1 << V_13 [ V_7 -> V_14 ] ) - 1 ) ;
V_12 |= ( 1 << V_3 ) ;
F_5 ( V_12 , & V_7 -> V_9 -> V_12 ) ;
V_5 = F_4 ( & V_7 -> V_9 -> V_10 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_9 -> V_10 ) ;
F_6 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_12 ;
F_3 ( & V_7 -> V_8 ) ;
V_12 = F_4 ( & V_7 -> V_9 -> V_12 ) & ( ( 1 << V_13 [ V_7 -> V_14 ] ) - 1 ) ;
V_12 &= ~ ( 1 << V_3 ) ;
F_5 ( V_12 , & V_7 -> V_9 -> V_12 ) ;
F_6 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
V_7 -> V_15 . V_16 = F_4 ( & V_7 -> V_9 -> V_17 ) ;
V_7 -> V_15 . V_18 = F_4 ( & V_7 -> V_9 -> V_19 ) ;
V_7 -> V_15 . V_20 = F_4 ( & V_7 -> V_9 -> V_10 ) ;
V_7 -> V_15 . V_21 = F_4 ( & V_7 -> V_9 -> V_12 ) ;
V_7 -> V_15 . V_22 = F_4 ( & V_7 -> V_9 -> V_23 ) ;
if ( V_7 -> V_14 == V_24 )
V_7 -> V_15 . V_25 = F_4 ( & V_7 -> V_9 -> V_26 ) ;
if ( V_7 -> V_14 == V_27 )
V_7 -> V_15 . V_28 =\
F_4 ( & V_7 -> V_9 -> V_29 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_5 ( V_7 -> V_15 . V_16 , & V_7 -> V_9 -> V_17 ) ;
F_5 ( V_7 -> V_15 . V_18 , & V_7 -> V_9 -> V_19 ) ;
F_5 ( V_7 -> V_15 . V_20 , & V_7 -> V_9 -> V_10 ) ;
F_5 ( V_7 -> V_15 . V_21 , & V_7 -> V_9 -> V_12 ) ;
F_5 ( V_7 -> V_15 . V_22 , & V_7 -> V_9 -> V_23 ) ;
if ( V_7 -> V_14 == V_24 )
F_5 ( V_7 -> V_15 . V_25 , & V_7 -> V_9 -> V_26 ) ;
if ( V_7 -> V_14 == V_27 )
F_5 ( V_7 -> V_15 . V_28 ,
& V_7 -> V_9 -> V_29 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_30 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return V_7 -> V_31 + V_30 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_32 = F_14 ( V_7 -> V_33 ) ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = F_9 ;
V_2 -> V_37 = F_7 ;
V_2 -> V_38 = F_8 ;
V_2 -> V_39 = F_1 ;
V_2 -> V_40 = NULL ;
V_2 -> V_41 = - 1 ;
V_2 -> V_42 = V_13 [ V_7 -> V_14 ] ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = F_12 ;
}
static int F_15 ( struct V_45 * V_46 , unsigned int type )
{
T_1 V_47 ;
T_1 T_2 * V_48 ;
T_1 V_17 ;
T_1 V_49 ;
int V_50 ;
unsigned long V_51 ;
T_1 V_4 ;
int V_52 = V_46 -> V_52 ;
struct V_53 * V_54 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
V_50 = V_52 - V_7 -> V_31 ;
if ( V_52 <= V_7 -> V_31 + 7 ) {
V_48 = & V_7 -> V_9 -> V_23 ;
V_49 = V_50 ;
} else {
V_48 = & V_7 -> V_9 -> V_26 ;
V_49 = V_50 - 8 ;
}
F_17 ( V_7 -> V_33 , L_1 ,
V_56 , V_52 , type , V_50 , V_49 ) ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
switch ( type ) {
case V_58 :
V_4 = V_59 ;
break;
case V_60 :
V_4 = V_61 ;
break;
case V_62 :
V_4 = V_63 ;
break;
case V_64 :
V_4 = V_65 ;
break;
case V_66 :
V_4 = V_67 ;
break;
case V_68 :
goto V_69;
default:
F_19 ( V_7 -> V_33 , L_2 ,
V_56 , type ) ;
goto V_69;
}
V_47 = F_4 ( V_48 ) & ~ ( V_70 << ( V_49 * 4 ) ) ;
F_5 ( V_47 | ( V_4 << ( V_49 * 4 ) ) , V_48 ) ;
F_5 ( F_20 ( V_50 ) , & V_7 -> V_9 -> V_71 ) ;
F_5 ( F_20 ( V_50 ) , & V_7 -> V_9 -> V_72 ) ;
V_17 = F_4 ( & V_7 -> V_9 -> V_17 ) ;
F_5 ( V_17 | F_20 ( V_50 ) , & V_7 -> V_9 -> V_17 ) ;
V_69:
F_21 ( & V_7 -> V_57 , V_51 ) ;
return 0 ;
}
static void F_22 ( struct V_45 * V_46 )
{
struct V_53 * V_54 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
F_5 ( 1 << ( V_46 -> V_52 - V_7 -> V_31 ) , & V_7 -> V_9 -> V_72 ) ;
}
static void F_23 ( struct V_45 * V_46 )
{
struct V_53 * V_54 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
F_5 ( 1 << ( V_46 -> V_52 - V_7 -> V_31 ) , & V_7 -> V_9 -> V_19 ) ;
}
static T_3 F_24 ( int V_52 , void * V_73 )
{
struct V_6 * V_7 = V_73 ;
T_1 V_5 = F_4 ( & V_7 -> V_9 -> V_74 ) ;
int V_75 ;
int V_76 = V_77 ;
for ( V_75 = 0 ; V_75 < V_13 [ V_7 -> V_14 ] ; V_75 ++ ) {
if ( V_5 & F_20 ( V_75 ) ) {
F_17 ( V_7 -> V_33 , L_3 ,
V_56 , V_75 , V_52 , V_5 ) ;
F_5 ( F_20 ( V_75 ) , & V_7 -> V_9 -> V_71 ) ;
F_25 ( V_7 -> V_31 + V_75 ) ;
V_76 = V_78 ;
}
}
return V_76 ;
}
static T_4 void F_26 ( struct V_6 * V_7 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_53 * V_54 ;
struct V_81 * V_82 ;
V_54 = F_27 ( L_4 , 1 , V_79 , V_7 -> V_41 ,
V_83 ) ;
V_54 -> V_55 = V_7 ;
V_82 = V_54 -> V_84 ;
V_82 -> V_7 . V_85 = F_23 ;
V_82 -> V_7 . V_86 = F_22 ;
V_82 -> V_7 . V_87 = F_15 ;
F_28 ( V_54 , F_29 ( V_80 ) , V_88 ,
V_89 | V_90 , 0 ) ;
}
static int T_4 F_30 ( struct V_91 * V_92 ,
const struct V_93 * V_94 )
{
T_5 V_76 ;
struct V_6 * V_7 ;
int V_31 ;
V_7 = F_31 ( sizeof( * V_7 ) , V_95 ) ;
if ( V_7 == NULL )
return - V_96 ;
V_7 -> V_33 = & V_92 -> V_33 ;
V_76 = F_32 ( V_92 ) ;
if ( V_76 ) {
F_33 ( & V_92 -> V_33 , L_5 , V_56 ) ;
goto V_97;
}
V_76 = F_34 ( V_92 , V_98 ) ;
if ( V_76 ) {
F_33 ( & V_92 -> V_33 , L_6 , V_76 ) ;
goto V_99;
}
V_7 -> V_41 = F_35 ( V_92 , 1 , 0 ) ;
if ( ! V_7 -> V_41 ) {
F_33 ( & V_92 -> V_33 , L_7 , V_56 ) ;
V_76 = - V_96 ;
goto V_100;
}
if ( V_92 -> V_101 == 0x8803 )
V_7 -> V_14 = V_24 ;
else if ( V_92 -> V_101 == 0x8014 )
V_7 -> V_14 = V_102 ;
else if ( V_92 -> V_101 == 0x8043 )
V_7 -> V_14 = V_27 ;
V_7 -> V_9 = V_7 -> V_41 ;
F_36 ( V_92 , V_7 ) ;
F_37 ( & V_7 -> V_8 ) ;
F_38 ( & V_7 -> V_57 ) ;
F_13 ( V_7 ) ;
V_76 = F_39 ( & V_7 -> V_2 ) ;
if ( V_76 ) {
F_33 ( & V_92 -> V_33 , L_8 ) ;
goto V_103;
}
V_31 = F_40 ( - 1 , 0 , V_13 [ V_7 -> V_14 ] , V_104 ) ;
if ( V_31 < 0 ) {
F_19 ( & V_92 -> V_33 , L_9 ) ;
V_7 -> V_31 = - 1 ;
goto V_69;
}
V_7 -> V_31 = V_31 ;
V_76 = F_41 ( V_92 -> V_52 , F_24 ,
V_105 , V_98 , V_7 ) ;
if ( V_76 != 0 ) {
F_33 ( & V_92 -> V_33 ,
L_10 , V_56 ) ;
goto V_106;
}
F_26 ( V_7 , V_31 , V_13 [ V_7 -> V_14 ] ) ;
F_5 ( 0 , & V_7 -> V_9 -> V_17 ) ;
V_69:
return 0 ;
V_106:
F_42 ( V_31 , V_13 [ V_7 -> V_14 ] ) ;
V_76 = F_43 ( & V_7 -> V_2 ) ;
if ( V_76 )
F_33 ( & V_92 -> V_33 , L_11 , V_56 ) ;
V_103:
F_44 ( V_92 , V_7 -> V_41 ) ;
V_100:
F_45 ( V_92 ) ;
V_99:
F_46 ( V_92 ) ;
V_97:
F_47 ( V_7 ) ;
F_33 ( & V_92 -> V_33 , L_12 , V_56 , V_76 ) ;
return V_76 ;
}
static void T_6 F_48 ( struct V_91 * V_92 )
{
int V_107 ;
struct V_6 * V_7 = F_49 ( V_92 ) ;
if ( V_7 -> V_31 != - 1 ) {
F_50 ( V_92 -> V_52 , V_7 ) ;
F_42 ( V_7 -> V_31 , V_13 [ V_7 -> V_14 ] ) ;
}
V_107 = F_43 ( & V_7 -> V_2 ) ;
if ( V_107 )
F_33 ( & V_92 -> V_33 , L_13 ) ;
F_44 ( V_92 , V_7 -> V_41 ) ;
F_45 ( V_92 ) ;
F_46 ( V_92 ) ;
F_47 ( V_7 ) ;
}
static int F_51 ( struct V_91 * V_92 , T_7 V_108 )
{
T_5 V_76 ;
struct V_6 * V_7 = F_49 ( V_92 ) ;
unsigned long V_51 ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
F_10 ( V_7 ) ;
F_21 ( & V_7 -> V_57 , V_51 ) ;
V_76 = F_52 ( V_92 ) ;
if ( V_76 ) {
F_33 ( & V_92 -> V_33 , L_14 , V_76 ) ;
return V_76 ;
}
F_46 ( V_92 ) ;
F_53 ( V_92 , V_109 ) ;
V_76 = F_54 ( V_92 , V_109 , 1 ) ;
if ( V_76 )
F_33 ( & V_92 -> V_33 , L_15 , V_76 ) ;
return 0 ;
}
static int F_55 ( struct V_91 * V_92 )
{
T_5 V_76 ;
struct V_6 * V_7 = F_49 ( V_92 ) ;
unsigned long V_51 ;
V_76 = F_54 ( V_92 , V_109 , 0 ) ;
F_53 ( V_92 , V_109 ) ;
V_76 = F_32 ( V_92 ) ;
if ( V_76 ) {
F_33 ( & V_92 -> V_33 , L_16 , V_76 ) ;
return V_76 ;
}
F_56 ( V_92 ) ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
F_5 ( 0x01 , & V_7 -> V_9 -> V_110 ) ;
F_5 ( 0x00 , & V_7 -> V_9 -> V_110 ) ;
F_11 ( V_7 ) ;
F_21 ( & V_7 -> V_57 , V_51 ) ;
return 0 ;
}
static int T_8 F_57 ( void )
{
return F_58 ( & V_111 ) ;
}
static void T_9 F_59 ( void )
{
F_60 ( & V_111 ) ;
}
