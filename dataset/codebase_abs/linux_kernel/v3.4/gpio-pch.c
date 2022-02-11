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
struct V_47 * V_48 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_48 -> V_49 ;
T_1 V_50 , V_51 , V_4 ;
T_1 T_2 * V_52 ;
unsigned long V_53 ;
int V_54 , V_55 = V_46 -> V_55 ;
V_54 = V_55 - V_7 -> V_31 ;
if ( V_55 <= V_7 -> V_31 + 7 ) {
V_52 = & V_7 -> V_9 -> V_23 ;
V_51 = V_54 ;
} else {
V_52 = & V_7 -> V_9 -> V_26 ;
V_51 = V_54 - 8 ;
}
F_17 ( V_7 -> V_33 , L_1 ,
V_56 , V_55 , type , V_54 , V_51 ) ;
F_18 ( & V_7 -> V_57 , V_53 ) ;
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
default:
goto V_68;
}
V_50 = F_4 ( V_52 ) & ~ ( V_69 << ( V_51 * 4 ) ) ;
F_5 ( V_50 | ( V_4 << ( V_51 * 4 ) ) , V_52 ) ;
if ( type & ( V_66 | V_64 ) )
F_19 ( V_46 -> V_55 , V_70 ) ;
else if ( type & ( V_60 | V_58 ) )
F_19 ( V_46 -> V_55 , V_71 ) ;
V_68:
F_20 ( & V_7 -> V_57 , V_53 ) ;
return 0 ;
}
static void F_21 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_48 -> V_49 ;
F_5 ( 1 << ( V_46 -> V_55 - V_7 -> V_31 ) , & V_7 -> V_9 -> V_72 ) ;
}
static void F_22 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_48 -> V_49 ;
F_5 ( 1 << ( V_46 -> V_55 - V_7 -> V_31 ) , & V_7 -> V_9 -> V_19 ) ;
}
static void F_23 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( V_46 ) ;
struct V_6 * V_7 = V_48 -> V_49 ;
F_5 ( 1 << ( V_46 -> V_55 - V_7 -> V_31 ) , & V_7 -> V_9 -> V_73 ) ;
}
static T_3 F_24 ( int V_55 , void * V_74 )
{
struct V_6 * V_7 = V_74 ;
T_1 V_5 = F_4 ( & V_7 -> V_9 -> V_75 ) ;
int V_76 , V_77 = V_78 ;
for ( V_76 = 0 ; V_76 < V_13 [ V_7 -> V_14 ] ; V_76 ++ ) {
if ( V_5 & F_25 ( V_76 ) ) {
F_17 ( V_7 -> V_33 , L_2 ,
V_56 , V_76 , V_55 , V_5 ) ;
F_26 ( V_7 -> V_31 + V_76 ) ;
V_77 = V_79 ;
}
}
return V_77 ;
}
static T_4 void F_27 ( struct V_6 * V_7 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_47 * V_48 ;
struct V_82 * V_83 ;
V_48 = F_28 ( L_3 , 1 , V_80 , V_7 -> V_41 ,
V_84 ) ;
V_48 -> V_49 = V_7 ;
V_83 = V_48 -> V_85 ;
V_83 -> V_7 . V_86 = F_23 ;
V_83 -> V_7 . V_87 = F_22 ;
V_83 -> V_7 . V_88 = F_21 ;
V_83 -> V_7 . V_89 = F_15 ;
F_29 ( V_48 , F_30 ( V_81 ) , V_90 ,
V_91 | V_92 , 0 ) ;
}
static int T_4 F_31 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
T_5 V_77 ;
struct V_6 * V_7 ;
int V_31 ;
T_1 V_97 ;
V_7 = F_32 ( sizeof( * V_7 ) , V_98 ) ;
if ( V_7 == NULL )
return - V_99 ;
V_7 -> V_33 = & V_94 -> V_33 ;
V_77 = F_33 ( V_94 ) ;
if ( V_77 ) {
F_34 ( & V_94 -> V_33 , L_4 , V_56 ) ;
goto V_100;
}
V_77 = F_35 ( V_94 , V_101 ) ;
if ( V_77 ) {
F_34 ( & V_94 -> V_33 , L_5 , V_77 ) ;
goto V_102;
}
V_7 -> V_41 = F_36 ( V_94 , 1 , 0 ) ;
if ( ! V_7 -> V_41 ) {
F_34 ( & V_94 -> V_33 , L_6 , V_56 ) ;
V_77 = - V_99 ;
goto V_103;
}
if ( V_94 -> V_104 == 0x8803 )
V_7 -> V_14 = V_24 ;
else if ( V_94 -> V_104 == 0x8014 )
V_7 -> V_14 = V_105 ;
else if ( V_94 -> V_104 == 0x8043 )
V_7 -> V_14 = V_27 ;
V_7 -> V_9 = V_7 -> V_41 ;
F_37 ( V_94 , V_7 ) ;
F_38 ( & V_7 -> V_8 ) ;
F_39 ( & V_7 -> V_57 ) ;
F_13 ( V_7 ) ;
V_77 = F_40 ( & V_7 -> V_2 ) ;
if ( V_77 ) {
F_34 ( & V_94 -> V_33 , L_7 ) ;
goto V_106;
}
V_31 = F_41 ( - 1 , 0 , V_13 [ V_7 -> V_14 ] , V_107 ) ;
if ( V_31 < 0 ) {
F_42 ( & V_94 -> V_33 , L_8 ) ;
V_7 -> V_31 = - 1 ;
goto V_108;
}
V_7 -> V_31 = V_31 ;
V_97 = ( 1 << V_13 [ V_7 -> V_14 ] ) - 1 ;
F_5 ( V_97 , & V_7 -> V_9 -> V_19 ) ;
F_5 ( V_97 , & V_7 -> V_9 -> V_17 ) ;
V_77 = F_43 ( V_94 -> V_55 , F_24 ,
V_109 , V_101 , V_7 ) ;
if ( V_77 != 0 ) {
F_34 ( & V_94 -> V_33 ,
L_9 , V_56 ) ;
goto V_110;
}
F_27 ( V_7 , V_31 , V_13 [ V_7 -> V_14 ] ) ;
V_108:
return 0 ;
V_110:
F_44 ( V_31 , V_13 [ V_7 -> V_14 ] ) ;
V_77 = F_45 ( & V_7 -> V_2 ) ;
if ( V_77 )
F_34 ( & V_94 -> V_33 , L_10 , V_56 ) ;
V_106:
F_46 ( V_94 , V_7 -> V_41 ) ;
V_103:
F_47 ( V_94 ) ;
V_102:
F_48 ( V_94 ) ;
V_100:
F_49 ( V_7 ) ;
F_34 ( & V_94 -> V_33 , L_11 , V_56 , V_77 ) ;
return V_77 ;
}
static void T_6 F_50 ( struct V_93 * V_94 )
{
int V_111 ;
struct V_6 * V_7 = F_51 ( V_94 ) ;
if ( V_7 -> V_31 != - 1 ) {
F_52 ( V_94 -> V_55 , V_7 ) ;
F_44 ( V_7 -> V_31 , V_13 [ V_7 -> V_14 ] ) ;
}
V_111 = F_45 ( & V_7 -> V_2 ) ;
if ( V_111 )
F_34 ( & V_94 -> V_33 , L_12 ) ;
F_46 ( V_94 , V_7 -> V_41 ) ;
F_47 ( V_94 ) ;
F_48 ( V_94 ) ;
F_49 ( V_7 ) ;
}
static int F_53 ( struct V_93 * V_94 , T_7 V_112 )
{
T_5 V_77 ;
struct V_6 * V_7 = F_51 ( V_94 ) ;
unsigned long V_53 ;
F_18 ( & V_7 -> V_57 , V_53 ) ;
F_10 ( V_7 ) ;
F_20 ( & V_7 -> V_57 , V_53 ) ;
V_77 = F_54 ( V_94 ) ;
if ( V_77 ) {
F_34 ( & V_94 -> V_33 , L_13 , V_77 ) ;
return V_77 ;
}
F_48 ( V_94 ) ;
F_55 ( V_94 , V_113 ) ;
V_77 = F_56 ( V_94 , V_113 , 1 ) ;
if ( V_77 )
F_34 ( & V_94 -> V_33 , L_14 , V_77 ) ;
return 0 ;
}
static int F_57 ( struct V_93 * V_94 )
{
T_5 V_77 ;
struct V_6 * V_7 = F_51 ( V_94 ) ;
unsigned long V_53 ;
V_77 = F_56 ( V_94 , V_113 , 0 ) ;
F_55 ( V_94 , V_113 ) ;
V_77 = F_33 ( V_94 ) ;
if ( V_77 ) {
F_34 ( & V_94 -> V_33 , L_15 , V_77 ) ;
return V_77 ;
}
F_58 ( V_94 ) ;
F_18 ( & V_7 -> V_57 , V_53 ) ;
F_5 ( 0x01 , & V_7 -> V_9 -> V_114 ) ;
F_5 ( 0x00 , & V_7 -> V_9 -> V_114 ) ;
F_11 ( V_7 ) ;
F_20 ( & V_7 -> V_57 , V_53 ) ;
return 0 ;
}
static int T_8 F_59 ( void )
{
return F_60 ( & V_115 ) ;
}
static void T_9 F_61 ( void )
{
F_62 ( & V_115 ) ;
}
