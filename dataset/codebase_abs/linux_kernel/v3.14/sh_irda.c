static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_4 , V_2 -> V_7 + V_3 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_5 ;
T_2 V_8 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_8 = F_6 ( V_2 -> V_7 + V_3 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_9 , T_2 V_4 )
{
unsigned long V_5 ;
T_2 V_10 , V_11 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_10 = F_6 ( V_2 -> V_7 + V_3 ) ;
V_11 = ( V_10 & ~ V_9 ) | V_4 ;
if ( V_10 != V_11 )
F_3 ( V_4 , V_2 -> V_7 + V_3 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_7 ( V_2 , V_16 , V_17 , V_12 ? V_17 : 0 ) ;
F_9 ( V_14 , L_1 , V_12 ? L_2 : L_3 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_18 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
if ( V_19 != V_2 -> V_20 )
V_18 = 0 ;
if ( V_18 < 0 || V_18 > 2 ) {
F_11 ( V_14 , L_4 ) ;
return - V_21 ;
}
F_7 ( V_2 , V_22 , V_23 , V_18 << V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_25 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
T_2 V_26 ;
if ( V_25 < 0 )
return 0 ;
if ( V_19 != V_2 -> V_20 ) {
F_11 ( V_14 , L_5 ) ;
return - V_21 ;
}
V_26 = ( 48000000 / 26 / 16 / V_25 ) - 1 ;
F_9 ( V_14 , L_6 , V_25 , V_26 ) ;
F_7 ( V_2 , V_27 , V_28 , V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return V_29 & F_5 ( V_2 , V_30 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_7 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_8 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_9 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_10 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_11 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
T_2 V_31 ;
T_3 * V_4 = ( T_3 * ) & V_31 ;
int V_32 = F_13 ( V_2 ) ;
int V_33 , V_34 ;
if ( V_32 > V_35 )
V_32 = V_35 ;
F_9 ( V_14 , L_12 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_34 = V_33 % 2 ;
if ( ! V_34 )
V_31 = F_5 ( V_2 , V_36 + V_33 ) ;
F_20 ( V_2 -> V_15 , & V_2 -> V_15 -> V_37 ,
& V_2 -> V_38 , V_4 [ V_34 ] ) ;
}
V_2 -> V_15 -> V_39 = V_40 ;
F_8 ( V_2 , 1 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_13 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_14 ) ;
F_12 ( V_2 , 9600 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_11 ( V_14 , L_15 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
F_9 ( V_14 , L_16 ) ;
F_25 ( V_2 -> V_15 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , enum V_41 V_20 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
struct V_42 * V_43 ;
const char * V_44 ;
T_2 V_4 ;
switch ( V_20 ) {
case V_19 :
V_44 = L_17 ;
V_4 = V_45 ;
V_43 = & V_46 ;
break;
case V_47 :
V_44 = L_18 ;
V_4 = V_48 ;
V_43 = & V_49 ;
break;
case V_50 :
V_44 = L_19 ;
V_4 = V_51 ;
V_43 = & V_49 ;
break;
default:
V_44 = L_20 ;
V_4 = 0 ;
V_43 = & V_42 ;
break;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_52 = V_43 ;
F_7 ( V_2 , V_53 , V_54 , V_4 ) ;
F_9 ( V_14 , L_21 , V_44 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_2 V_55 ;
T_2 V_56 ;
F_7 ( V_2 , V_53 , V_57 , V_57 ) ;
F_7 ( V_2 , V_58 , V_59 , V_59 ) ;
F_7 ( V_2 , V_60 , V_59 , V_59 ) ;
F_7 ( V_2 , V_61 , V_59 , V_59 ) ;
F_7 ( V_2 , V_62 , V_59 , V_59 ) ;
switch ( V_2 -> V_20 ) {
case V_19 :
V_55 = V_63 ;
V_56 = V_58 ;
break;
case V_47 :
case V_50 :
V_55 = V_64 ;
V_56 = V_60 ;
break;
default:
V_55 = 0 ;
V_56 = 0 ;
break;
}
if ( V_56 ) {
F_7 ( V_2 , V_53 , V_55 , 0 ) ;
F_7 ( V_2 , V_56 , V_59 , 0 ) ;
}
}
static T_4 F_28 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
struct V_42 * V_43 = V_2 -> V_52 ;
T_2 V_67 = F_5 ( V_2 , V_68 ) ;
F_1 ( V_2 , V_61 , V_67 ) ;
if ( V_67 & V_69 )
V_43 -> V_70 ( V_2 ) ;
if ( V_67 & V_71 )
V_43 -> V_72 ( V_2 ) ;
if ( V_67 & V_73 )
V_43 -> V_74 ( V_2 ) ;
if ( V_67 & V_75 )
V_43 -> V_76 ( V_2 ) ;
if ( V_67 & V_77 )
V_43 -> V_78 ( V_2 ) ;
return V_79 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_80 , V_81 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_2 V_4 )
{
F_1 ( V_2 , V_82 , V_4 & V_83 ) ;
}
static T_2 F_31 ( struct V_1 * V_2 )
{
return V_84 & F_5 ( V_2 , V_80 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_85 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
int V_8 = - V_86 ;
T_2 V_26 ;
F_29 ( V_2 ) ;
F_30 ( V_2 , 0xCC ) ;
F_30 ( V_2 , 0xF5 ) ;
F_30 ( V_2 , 0xF1 ) ;
F_30 ( V_2 , 0xA7 ) ;
V_26 = F_31 ( V_2 ) ;
if ( 4 != V_26 ) {
F_11 ( V_14 , L_22 , V_26 ) ;
goto V_87;
}
V_26 = F_32 ( V_2 ) ;
if ( 0x51DF != V_26 ) {
F_11 ( V_14 , L_23 , V_26 ) ;
goto V_87;
}
V_8 = 0 ;
V_87:
F_29 ( V_2 ) ;
return V_8 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_38 . V_88 ) ;
V_2 -> V_89 . V_88 = NULL ;
V_2 -> V_89 . V_4 = NULL ;
V_2 -> V_38 . V_88 = NULL ;
V_2 -> V_38 . V_4 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , int V_90 , int V_91 )
{
if ( V_2 -> V_38 . V_88 ||
V_2 -> V_89 . V_88 ) {
F_11 ( & V_2 -> V_15 -> V_14 , L_24 ) ;
return - V_21 ;
}
V_2 -> V_38 . V_88 = F_37 ( V_90 , V_92 ) ;
if ( ! V_2 -> V_38 . V_88 )
return - V_93 ;
V_2 -> V_38 . V_94 = V_90 ;
V_2 -> V_38 . V_95 = FALSE ;
V_2 -> V_38 . V_96 = V_97 ;
V_2 -> V_38 . V_4 = V_2 -> V_38 . V_88 ;
V_2 -> V_89 . V_88 = V_2 -> V_7 + V_36 ;
V_2 -> V_89 . V_94 = V_35 ;
return 0 ;
}
static int F_38 ( struct V_98 * V_99 , struct V_100 * V_15 )
{
struct V_1 * V_2 = F_39 ( V_15 ) ;
struct V_13 * V_14 = & V_2 -> V_15 -> V_14 ;
int V_101 = F_40 ( V_99 ) ;
int V_8 ;
F_9 ( V_14 , L_25 ) ;
F_41 ( V_15 ) ;
F_8 ( V_2 , 0 ) ;
V_8 = F_12 ( V_2 , V_101 ) ;
if ( V_8 < 0 )
goto V_102;
V_2 -> V_89 . V_32 = 0 ;
if ( V_99 -> V_32 ) {
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_89 . V_32 = F_42 ( V_99 ,
V_2 -> V_89 . V_88 ,
V_2 -> V_89 . V_94 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
if ( V_2 -> V_89 . V_32 > V_2 -> V_89 . V_94 )
V_2 -> V_89 . V_32 = V_2 -> V_89 . V_94 ;
F_1 ( V_2 , V_103 , V_2 -> V_89 . V_32 ) ;
F_1 ( V_2 , V_104 , V_105 | V_106 ) ;
} else
goto V_102;
F_43 ( V_99 ) ;
return 0 ;
V_102:
F_12 ( V_2 , 9600 ) ;
F_25 ( V_2 -> V_15 ) ;
F_8 ( V_2 , 1 ) ;
F_43 ( V_99 ) ;
return V_8 ;
}
static int F_44 ( struct V_100 * V_15 , struct V_107 * V_107 , int V_108 )
{
return 0 ;
}
static struct V_109 * F_45 ( struct V_100 * V_15 )
{
struct V_1 * V_2 = F_39 ( V_15 ) ;
return & V_2 -> V_15 -> V_37 ;
}
static int F_46 ( struct V_100 * V_15 )
{
struct V_1 * V_2 = F_39 ( V_15 ) ;
int V_110 ;
F_47 ( & V_2 -> V_111 -> V_14 ) ;
V_110 = F_33 ( V_2 ) ;
if ( V_110 )
goto V_112;
F_26 ( V_2 , V_19 ) ;
F_10 ( V_2 , 2 ) ;
F_12 ( V_2 , 9600 ) ;
V_2 -> V_113 = F_48 ( V_15 , & V_2 -> V_114 , V_115 ) ;
if ( ! V_2 -> V_113 ) {
V_110 = - V_116 ;
goto V_112;
}
F_49 ( V_15 ) ;
F_8 ( V_2 , 1 ) ;
F_27 ( V_2 ) ;
F_50 ( & V_15 -> V_14 , L_26 ) ;
return 0 ;
V_112:
F_51 ( & V_2 -> V_111 -> V_14 ) ;
return V_110 ;
}
static int F_52 ( struct V_100 * V_15 )
{
struct V_1 * V_2 = F_39 ( V_15 ) ;
if ( V_2 -> V_113 ) {
F_53 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
F_41 ( V_15 ) ;
F_51 ( & V_2 -> V_111 -> V_14 ) ;
F_50 ( & V_15 -> V_14 , L_27 ) ;
return 0 ;
}
static int F_54 ( struct V_117 * V_111 )
{
struct V_100 * V_15 ;
struct V_1 * V_2 ;
struct V_118 * V_119 ;
int V_65 ;
int V_110 = - V_93 ;
V_119 = F_55 ( V_111 , V_120 , 0 ) ;
V_65 = F_56 ( V_111 , 0 ) ;
if ( ! V_119 || V_65 < 0 ) {
F_11 ( & V_111 -> V_14 , L_28 ) ;
goto exit;
}
V_15 = F_57 ( sizeof( * V_2 ) ) ;
if ( ! V_15 )
goto exit;
V_2 = F_39 ( V_15 ) ;
V_2 -> V_7 = F_58 ( V_119 -> V_121 , F_59 ( V_119 ) ) ;
if ( ! V_2 -> V_7 ) {
V_110 = - V_122 ;
F_11 ( & V_111 -> V_14 , L_29 ) ;
goto V_123;
}
V_110 = F_36 ( V_2 , V_124 , V_125 ) ;
if ( V_110 )
goto V_126;
V_2 -> V_111 = V_111 ;
F_60 ( & V_111 -> V_14 ) ;
F_61 ( & V_2 -> V_114 ) ;
V_15 -> V_127 = & V_128 ;
V_15 -> V_65 = V_65 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_114 . V_129 . V_130 &= V_131 ;
V_2 -> V_114 . V_132 . V_130 = 1 ;
F_62 ( & V_2 -> V_6 ) ;
F_63 ( & V_2 -> V_114 ) ;
V_110 = F_64 ( V_15 ) ;
if ( V_110 )
goto V_133;
F_65 ( V_111 , V_15 ) ;
V_110 = F_66 ( & V_111 -> V_14 , V_65 , F_28 , 0 , L_30 , V_2 ) ;
if ( V_110 ) {
F_67 ( & V_111 -> V_14 , L_31 ) ;
goto V_133;
}
F_50 ( & V_111 -> V_14 , L_32 ) ;
goto exit;
V_133:
F_68 ( & V_111 -> V_14 ) ;
F_34 ( V_2 ) ;
V_126:
F_69 ( V_2 -> V_7 ) ;
V_123:
F_70 ( V_15 ) ;
exit:
return V_110 ;
}
static int F_71 ( struct V_117 * V_111 )
{
struct V_100 * V_15 = F_72 ( V_111 ) ;
struct V_1 * V_2 = F_39 ( V_15 ) ;
if ( ! V_2 )
return 0 ;
F_73 ( V_15 ) ;
F_68 ( & V_111 -> V_14 ) ;
F_34 ( V_2 ) ;
F_69 ( V_2 -> V_7 ) ;
F_70 ( V_15 ) ;
return 0 ;
}
static int F_74 ( struct V_13 * V_14 )
{
return 0 ;
}
