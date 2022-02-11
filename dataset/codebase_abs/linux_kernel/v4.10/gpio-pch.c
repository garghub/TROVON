static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
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
struct V_6 * V_7 = F_2 ( V_2 ) ;
return ( F_4 ( & V_7 -> V_10 -> V_12 ) >> V_3 ) & 1 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_13 ;
T_1 V_5 ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_5 = F_4 ( & V_7 -> V_10 -> V_11 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_10 -> V_11 ) ;
V_13 = F_4 ( & V_7 -> V_10 -> V_13 ) & ( ( 1 << V_14 [ V_7 -> V_15 ] ) - 1 ) ;
V_13 |= ( 1 << V_3 ) ;
F_5 ( V_13 , & V_7 -> V_10 -> V_13 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
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
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_32 + V_31 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_33 = F_14 ( V_7 -> V_34 ) ;
V_2 -> V_35 = V_7 -> V_34 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_9 ;
V_2 -> V_39 = F_7 ;
V_2 -> V_40 = F_8 ;
V_2 -> V_41 = F_1 ;
V_2 -> V_42 = NULL ;
V_2 -> V_43 = - 1 ;
V_2 -> V_44 = V_14 [ V_7 -> V_15 ] ;
V_2 -> V_45 = false ;
V_2 -> V_46 = F_12 ;
}
static int F_15 ( struct V_47 * V_48 , unsigned int type )
{
struct V_49 * V_50 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_50 -> V_51 ;
T_1 V_52 , V_53 , V_4 ;
T_1 T_2 * V_54 ;
unsigned long V_8 ;
int V_55 , V_56 = V_48 -> V_56 ;
V_55 = V_56 - V_7 -> V_32 ;
if ( V_56 <= V_7 -> V_32 + 7 ) {
V_54 = & V_7 -> V_10 -> V_24 ;
V_53 = V_55 ;
} else {
V_54 = & V_7 -> V_10 -> V_27 ;
V_53 = V_55 - 8 ;
}
F_17 ( V_7 -> V_34 , L_1 ,
V_57 , V_56 , type , V_55 , V_53 ) ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
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
V_52 = F_4 ( V_54 ) & ~ ( V_69 << ( V_53 * 4 ) ) ;
F_5 ( V_52 | ( V_4 << ( V_53 * 4 ) ) , V_54 ) ;
if ( type & ( V_66 | V_64 ) )
F_18 ( V_48 , V_70 ) ;
else if ( type & ( V_60 | V_58 ) )
F_18 ( V_48 , V_71 ) ;
V_68:
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_19 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_50 -> V_51 ;
F_5 ( 1 << ( V_48 -> V_56 - V_7 -> V_32 ) , & V_7 -> V_10 -> V_72 ) ;
}
static void F_20 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_50 -> V_51 ;
F_5 ( 1 << ( V_48 -> V_56 - V_7 -> V_32 ) , & V_7 -> V_10 -> V_20 ) ;
}
static void F_21 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_50 -> V_51 ;
F_5 ( 1 << ( V_48 -> V_56 - V_7 -> V_32 ) , & V_7 -> V_10 -> V_73 ) ;
}
static T_3 F_22 ( int V_56 , void * V_74 )
{
struct V_6 * V_7 = V_74 ;
T_1 V_5 = F_4 ( & V_7 -> V_10 -> V_75 ) ;
int V_76 , V_77 = V_78 ;
for ( V_76 = 0 ; V_76 < V_14 [ V_7 -> V_15 ] ; V_76 ++ ) {
if ( V_5 & F_23 ( V_76 ) ) {
F_17 ( V_7 -> V_34 , L_2 ,
V_57 , V_76 , V_56 , V_5 ) ;
F_24 ( V_7 -> V_32 + V_76 ) ;
V_77 = V_79 ;
}
}
return V_77 ;
}
static void F_25 ( struct V_6 * V_7 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_49 * V_50 ;
struct V_82 * V_83 ;
V_50 = F_26 ( L_3 , 1 , V_80 , V_7 -> V_43 ,
V_84 ) ;
V_50 -> V_51 = V_7 ;
V_83 = V_50 -> V_85 ;
V_83 -> V_7 . V_86 = F_21 ;
V_83 -> V_7 . V_87 = F_20 ;
V_83 -> V_7 . V_88 = F_19 ;
V_83 -> V_7 . V_89 = F_15 ;
F_27 ( V_50 , F_28 ( V_81 ) , V_90 ,
V_91 | V_92 , 0 ) ;
}
static int F_29 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
T_4 V_77 ;
struct V_6 * V_7 ;
int V_32 ;
T_1 V_97 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_98 ) ;
if ( V_7 == NULL )
return - V_99 ;
V_7 -> V_34 = & V_94 -> V_34 ;
V_77 = F_31 ( V_94 ) ;
if ( V_77 ) {
F_32 ( & V_94 -> V_34 , L_4 , V_57 ) ;
goto V_100;
}
V_77 = F_33 ( V_94 , V_101 ) ;
if ( V_77 ) {
F_32 ( & V_94 -> V_34 , L_5 , V_77 ) ;
goto V_102;
}
V_7 -> V_43 = F_34 ( V_94 , 1 , 0 ) ;
if ( ! V_7 -> V_43 ) {
F_32 ( & V_94 -> V_34 , L_6 , V_57 ) ;
V_77 = - V_99 ;
goto V_103;
}
if ( V_94 -> V_104 == 0x8803 )
V_7 -> V_15 = V_25 ;
else if ( V_94 -> V_104 == 0x8014 )
V_7 -> V_15 = V_105 ;
else if ( V_94 -> V_104 == 0x8043 )
V_7 -> V_15 = V_28 ;
V_7 -> V_10 = V_7 -> V_43 ;
F_35 ( V_94 , V_7 ) ;
F_36 ( & V_7 -> V_9 ) ;
F_13 ( V_7 ) ;
#ifdef F_37
V_7 -> V_2 . V_106 = V_94 -> V_34 . V_106 ;
#endif
V_77 = F_38 ( & V_7 -> V_2 , V_7 ) ;
if ( V_77 ) {
F_32 ( & V_94 -> V_34 , L_7 ) ;
goto V_107;
}
V_32 = F_39 ( - 1 , 0 , V_14 [ V_7 -> V_15 ] , V_108 ) ;
if ( V_32 < 0 ) {
F_40 ( & V_94 -> V_34 , L_8 ) ;
V_7 -> V_32 = - 1 ;
goto V_109;
}
V_7 -> V_32 = V_32 ;
V_97 = ( 1 << V_14 [ V_7 -> V_15 ] ) - 1 ;
F_5 ( V_97 , & V_7 -> V_10 -> V_20 ) ;
F_5 ( V_97 , & V_7 -> V_10 -> V_18 ) ;
V_77 = F_41 ( V_94 -> V_56 , F_22 ,
V_110 , V_101 , V_7 ) ;
if ( V_77 != 0 ) {
F_32 ( & V_94 -> V_34 ,
L_9 , V_57 ) ;
goto V_111;
}
F_25 ( V_7 , V_32 , V_14 [ V_7 -> V_15 ] ) ;
V_109:
return 0 ;
V_111:
F_42 ( V_32 , V_14 [ V_7 -> V_15 ] ) ;
F_43 ( & V_7 -> V_2 ) ;
V_107:
F_44 ( V_94 , V_7 -> V_43 ) ;
V_103:
F_45 ( V_94 ) ;
V_102:
F_46 ( V_94 ) ;
V_100:
F_47 ( V_7 ) ;
F_32 ( & V_94 -> V_34 , L_10 , V_57 , V_77 ) ;
return V_77 ;
}
static void F_48 ( struct V_93 * V_94 )
{
struct V_6 * V_7 = F_49 ( V_94 ) ;
if ( V_7 -> V_32 != - 1 ) {
F_50 ( V_94 -> V_56 , V_7 ) ;
F_42 ( V_7 -> V_32 , V_14 [ V_7 -> V_15 ] ) ;
}
F_43 ( & V_7 -> V_2 ) ;
F_44 ( V_94 , V_7 -> V_43 ) ;
F_45 ( V_94 ) ;
F_46 ( V_94 ) ;
F_47 ( V_7 ) ;
}
static int F_51 ( struct V_93 * V_94 , T_5 V_112 )
{
T_4 V_77 ;
struct V_6 * V_7 = F_49 ( V_94 ) ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_10 ( V_7 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_77 = F_52 ( V_94 ) ;
if ( V_77 ) {
F_32 ( & V_94 -> V_34 , L_11 , V_77 ) ;
return V_77 ;
}
F_46 ( V_94 ) ;
F_53 ( V_94 , V_113 ) ;
V_77 = F_54 ( V_94 , V_113 , 1 ) ;
if ( V_77 )
F_32 ( & V_94 -> V_34 , L_12 , V_77 ) ;
return 0 ;
}
static int F_55 ( struct V_93 * V_94 )
{
T_4 V_77 ;
struct V_6 * V_7 = F_49 ( V_94 ) ;
unsigned long V_8 ;
V_77 = F_54 ( V_94 , V_113 , 0 ) ;
F_53 ( V_94 , V_113 ) ;
V_77 = F_31 ( V_94 ) ;
if ( V_77 ) {
F_32 ( & V_94 -> V_34 , L_13 , V_77 ) ;
return V_77 ;
}
F_56 ( V_94 ) ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_5 ( 0x01 , & V_7 -> V_10 -> V_114 ) ;
F_5 ( 0x00 , & V_7 -> V_10 -> V_114 ) ;
F_11 ( V_7 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
