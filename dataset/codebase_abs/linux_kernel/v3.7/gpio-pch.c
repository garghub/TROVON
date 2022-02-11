static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_5 = F_4 ( & V_7 -> V_10 -> V_11 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_10 -> V_11 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return F_4 ( & V_7 -> V_10 -> V_12 ) & ( 1 << V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_13 ;
T_1 V_5 ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_13 = F_4 ( & V_7 -> V_10 -> V_13 ) & ( ( 1 << V_14 [ V_7 -> V_15 ] ) - 1 ) ;
V_13 |= ( 1 << V_3 ) ;
F_5 ( V_13 , & V_7 -> V_10 -> V_13 ) ;
V_5 = F_4 ( & V_7 -> V_10 -> V_11 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_10 -> V_11 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_13 ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_13 = F_4 ( & V_7 -> V_10 -> V_13 ) & ( ( 1 << V_14 [ V_7 -> V_15 ] ) - 1 ) ;
V_13 &= ~ ( 1 << V_3 ) ;
F_5 ( V_13 , & V_7 -> V_10 -> V_13 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
V_7 -> V_16 . V_17 = F_4 ( & V_7 -> V_10 -> V_18 ) ;
V_7 -> V_16 . V_19 = F_4 ( & V_7 -> V_10 -> V_20 ) ;
V_7 -> V_16 . V_21 = F_4 ( & V_7 -> V_10 -> V_11 ) ;
V_7 -> V_16 . V_22 = F_4 ( & V_7 -> V_10 -> V_13 ) ;
V_7 -> V_16 . V_23 = F_4 ( & V_7 -> V_10 -> V_24 ) ;
if ( V_7 -> V_15 == V_25 )
V_7 -> V_16 . V_26 = F_4 ( & V_7 -> V_10 -> V_27 ) ;
if ( V_7 -> V_15 == V_28 )
V_7 -> V_16 . V_29 =\
F_4 ( & V_7 -> V_10 -> V_30 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_5 ( V_7 -> V_16 . V_17 , & V_7 -> V_10 -> V_18 ) ;
F_5 ( V_7 -> V_16 . V_19 , & V_7 -> V_10 -> V_20 ) ;
F_5 ( V_7 -> V_16 . V_21 , & V_7 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_16 . V_22 , & V_7 -> V_10 -> V_13 ) ;
F_5 ( V_7 -> V_16 . V_23 , & V_7 -> V_10 -> V_24 ) ;
if ( V_7 -> V_15 == V_25 )
F_5 ( V_7 -> V_16 . V_26 , & V_7 -> V_10 -> V_27 ) ;
if ( V_7 -> V_15 == V_28 )
F_5 ( V_7 -> V_16 . V_29 ,
& V_7 -> V_10 -> V_30 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return V_7 -> V_32 + V_31 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_33 = F_14 ( V_7 -> V_34 ) ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_9 ;
V_2 -> V_38 = F_7 ;
V_2 -> V_39 = F_8 ;
V_2 -> V_40 = F_1 ;
V_2 -> V_41 = NULL ;
V_2 -> V_42 = - 1 ;
V_2 -> V_43 = V_14 [ V_7 -> V_15 ] ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = F_12 ;
}
static int F_15 ( struct V_46 * V_47 , unsigned int type )
{
struct V_48 * V_49 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_49 -> V_50 ;
T_1 V_51 , V_52 , V_4 ;
T_1 T_2 * V_53 ;
unsigned long V_8 ;
int V_54 , V_55 = V_47 -> V_55 ;
V_54 = V_55 - V_7 -> V_32 ;
if ( V_55 <= V_7 -> V_32 + 7 ) {
V_53 = & V_7 -> V_10 -> V_24 ;
V_52 = V_54 ;
} else {
V_53 = & V_7 -> V_10 -> V_27 ;
V_52 = V_54 - 8 ;
}
F_17 ( V_7 -> V_34 , L_1 ,
V_56 , V_55 , type , V_54 , V_52 ) ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
switch ( type ) {
case V_57 :
V_4 = V_58 ;
break;
case V_59 :
V_4 = V_60 ;
break;
case V_61 :
V_4 = V_62 ;
break;
case V_63 :
V_4 = V_64 ;
break;
case V_65 :
V_4 = V_66 ;
break;
default:
goto V_67;
}
V_51 = F_4 ( V_53 ) & ~ ( V_68 << ( V_52 * 4 ) ) ;
F_5 ( V_51 | ( V_4 << ( V_52 * 4 ) ) , V_53 ) ;
if ( type & ( V_65 | V_63 ) )
F_18 ( V_47 -> V_55 , V_69 ) ;
else if ( type & ( V_59 | V_57 ) )
F_18 ( V_47 -> V_55 , V_70 ) ;
V_67:
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_19 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_49 -> V_50 ;
F_5 ( 1 << ( V_47 -> V_55 - V_7 -> V_32 ) , & V_7 -> V_10 -> V_71 ) ;
}
static void F_20 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_49 -> V_50 ;
F_5 ( 1 << ( V_47 -> V_55 - V_7 -> V_32 ) , & V_7 -> V_10 -> V_20 ) ;
}
static void F_21 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_49 -> V_50 ;
F_5 ( 1 << ( V_47 -> V_55 - V_7 -> V_32 ) , & V_7 -> V_10 -> V_72 ) ;
}
static T_3 F_22 ( int V_55 , void * V_73 )
{
struct V_6 * V_7 = V_73 ;
T_1 V_5 = F_4 ( & V_7 -> V_10 -> V_74 ) ;
int V_75 , V_76 = V_77 ;
for ( V_75 = 0 ; V_75 < V_14 [ V_7 -> V_15 ] ; V_75 ++ ) {
if ( V_5 & F_23 ( V_75 ) ) {
F_17 ( V_7 -> V_34 , L_2 ,
V_56 , V_75 , V_55 , V_5 ) ;
F_24 ( V_7 -> V_32 + V_75 ) ;
V_76 = V_78 ;
}
}
return V_76 ;
}
static T_4 void F_25 ( struct V_6 * V_7 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_48 * V_49 ;
struct V_81 * V_82 ;
V_49 = F_26 ( L_3 , 1 , V_79 , V_7 -> V_42 ,
V_83 ) ;
V_49 -> V_50 = V_7 ;
V_82 = V_49 -> V_84 ;
V_82 -> V_7 . V_85 = F_21 ;
V_82 -> V_7 . V_86 = F_20 ;
V_82 -> V_7 . V_87 = F_19 ;
V_82 -> V_7 . V_88 = F_15 ;
F_27 ( V_49 , F_28 ( V_80 ) , V_89 ,
V_90 | V_91 , 0 ) ;
}
static int T_4 F_29 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
T_5 V_76 ;
struct V_6 * V_7 ;
int V_32 ;
T_1 V_96 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_97 ) ;
if ( V_7 == NULL )
return - V_98 ;
V_7 -> V_34 = & V_93 -> V_34 ;
V_76 = F_31 ( V_93 ) ;
if ( V_76 ) {
F_32 ( & V_93 -> V_34 , L_4 , V_56 ) ;
goto V_99;
}
V_76 = F_33 ( V_93 , V_100 ) ;
if ( V_76 ) {
F_32 ( & V_93 -> V_34 , L_5 , V_76 ) ;
goto V_101;
}
V_7 -> V_42 = F_34 ( V_93 , 1 , 0 ) ;
if ( ! V_7 -> V_42 ) {
F_32 ( & V_93 -> V_34 , L_6 , V_56 ) ;
V_76 = - V_98 ;
goto V_102;
}
if ( V_93 -> V_103 == 0x8803 )
V_7 -> V_15 = V_25 ;
else if ( V_93 -> V_103 == 0x8014 )
V_7 -> V_15 = V_104 ;
else if ( V_93 -> V_103 == 0x8043 )
V_7 -> V_15 = V_28 ;
V_7 -> V_10 = V_7 -> V_42 ;
F_35 ( V_93 , V_7 ) ;
F_36 ( & V_7 -> V_9 ) ;
F_13 ( V_7 ) ;
V_76 = F_37 ( & V_7 -> V_2 ) ;
if ( V_76 ) {
F_32 ( & V_93 -> V_34 , L_7 ) ;
goto V_105;
}
V_32 = F_38 ( - 1 , 0 , V_14 [ V_7 -> V_15 ] , V_106 ) ;
if ( V_32 < 0 ) {
F_39 ( & V_93 -> V_34 , L_8 ) ;
V_7 -> V_32 = - 1 ;
goto V_107;
}
V_7 -> V_32 = V_32 ;
V_96 = ( 1 << V_14 [ V_7 -> V_15 ] ) - 1 ;
F_5 ( V_96 , & V_7 -> V_10 -> V_20 ) ;
F_5 ( V_96 , & V_7 -> V_10 -> V_18 ) ;
V_76 = F_40 ( V_93 -> V_55 , F_22 ,
V_108 , V_100 , V_7 ) ;
if ( V_76 != 0 ) {
F_32 ( & V_93 -> V_34 ,
L_9 , V_56 ) ;
goto V_109;
}
F_25 ( V_7 , V_32 , V_14 [ V_7 -> V_15 ] ) ;
V_107:
return 0 ;
V_109:
F_41 ( V_32 , V_14 [ V_7 -> V_15 ] ) ;
V_76 = F_42 ( & V_7 -> V_2 ) ;
if ( V_76 )
F_32 ( & V_93 -> V_34 , L_10 , V_56 ) ;
V_105:
F_43 ( V_93 , V_7 -> V_42 ) ;
V_102:
F_44 ( V_93 ) ;
V_101:
F_45 ( V_93 ) ;
V_99:
F_46 ( V_7 ) ;
F_32 ( & V_93 -> V_34 , L_11 , V_56 , V_76 ) ;
return V_76 ;
}
static void T_6 F_47 ( struct V_92 * V_93 )
{
int V_110 ;
struct V_6 * V_7 = F_48 ( V_93 ) ;
if ( V_7 -> V_32 != - 1 ) {
F_49 ( V_93 -> V_55 , V_7 ) ;
F_41 ( V_7 -> V_32 , V_14 [ V_7 -> V_15 ] ) ;
}
V_110 = F_42 ( & V_7 -> V_2 ) ;
if ( V_110 )
F_32 ( & V_93 -> V_34 , L_12 ) ;
F_43 ( V_93 , V_7 -> V_42 ) ;
F_44 ( V_93 ) ;
F_45 ( V_93 ) ;
F_46 ( V_7 ) ;
}
static int F_50 ( struct V_92 * V_93 , T_7 V_111 )
{
T_5 V_76 ;
struct V_6 * V_7 = F_48 ( V_93 ) ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_10 ( V_7 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_76 = F_51 ( V_93 ) ;
if ( V_76 ) {
F_32 ( & V_93 -> V_34 , L_13 , V_76 ) ;
return V_76 ;
}
F_45 ( V_93 ) ;
F_52 ( V_93 , V_112 ) ;
V_76 = F_53 ( V_93 , V_112 , 1 ) ;
if ( V_76 )
F_32 ( & V_93 -> V_34 , L_14 , V_76 ) ;
return 0 ;
}
static int F_54 ( struct V_92 * V_93 )
{
T_5 V_76 ;
struct V_6 * V_7 = F_48 ( V_93 ) ;
unsigned long V_8 ;
V_76 = F_53 ( V_93 , V_112 , 0 ) ;
F_52 ( V_93 , V_112 ) ;
V_76 = F_31 ( V_93 ) ;
if ( V_76 ) {
F_32 ( & V_93 -> V_34 , L_15 , V_76 ) ;
return V_76 ;
}
F_55 ( V_93 ) ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_5 ( 0x01 , & V_7 -> V_10 -> V_113 ) ;
F_5 ( 0x00 , & V_7 -> V_10 -> V_113 ) ;
F_11 ( V_7 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
