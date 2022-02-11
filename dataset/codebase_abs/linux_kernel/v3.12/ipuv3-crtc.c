static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
V_3 = V_2 -> V_3 ;
V_4 = V_2 -> V_4 ;
if ( ! V_3 || ! V_4 )
return 60 ;
return V_2 -> clock * 1000 / V_4 / V_3 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_5 )
{
return V_2 -> V_6 * V_2 -> V_7 * V_5 ;
}
static void F_3 ( struct V_8 * V_8 )
{
if ( V_8 -> V_9 )
return;
F_4 ( V_8 -> V_10 ) ;
F_5 ( V_8 -> V_11 ) ;
F_6 ( V_8 -> V_12 ) ;
F_7 ( V_8 -> V_13 ) ;
if ( V_8 -> V_14 )
F_8 ( V_8 -> V_14 ) ;
V_8 -> V_9 = 1 ;
}
static void F_9 ( struct V_8 * V_8 )
{
if ( ! V_8 -> V_9 )
return;
if ( V_8 -> V_14 )
F_10 ( V_8 -> V_14 ) ;
F_11 ( V_8 -> V_13 ) ;
F_12 ( V_8 -> V_12 ) ;
F_13 ( V_8 -> V_11 ) ;
F_14 ( V_8 -> V_10 ) ;
V_8 -> V_9 = 0 ;
}
static void F_15 ( struct V_15 * V_16 , int V_2 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_17 ( V_8 -> V_17 , L_1 , V_18 , V_2 ) ;
switch ( V_2 ) {
case V_19 :
F_3 ( V_8 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
F_9 ( V_8 ) ;
break;
}
}
static int F_18 ( struct V_15 * V_16 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
T_1 V_27 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
int V_28 ;
if ( V_8 -> V_29 )
return - V_30 ;
V_28 = F_19 ( V_8 -> V_31 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_17 , L_2 ) ;
F_20 ( & V_26 -> V_32 . V_33 ) ;
return V_28 ;
}
V_8 -> V_29 = V_24 ;
V_8 -> V_34 = V_26 ;
V_16 -> V_24 = V_24 ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 , int V_35 , int V_36 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
struct V_37 * V_38 ;
struct V_23 * V_24 = V_16 -> V_24 ;
unsigned long V_39 ;
V_38 = F_22 ( V_24 , 0 ) ;
if ( ! V_38 ) {
F_23 ( L_3 ) ;
return - V_40 ;
}
V_39 = V_38 -> V_41 ;
V_39 += V_35 * ( V_24 -> V_42 >> 3 ) ;
V_39 += V_36 * V_24 -> V_43 [ 0 ] ;
F_17 ( V_8 -> V_17 , L_4 , V_18 , V_39 ) ;
F_17 ( V_8 -> V_17 , L_5 , V_18 , V_35 , V_36 ) ;
F_24 ( F_25 ( V_8 -> V_12 ) , V_24 -> V_43 [ 0 ] ) ;
F_26 ( F_25 ( V_8 -> V_12 ) ,
0 , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 ,
struct V_1 * V_44 ,
struct V_1 * V_2 ,
int V_35 , int V_36 ,
struct V_23 * V_45 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
struct V_23 * V_24 = V_8 -> V_32 . V_24 ;
int V_28 ;
struct V_46 V_47 = {} ;
T_2 V_48 ;
struct V_49 T_3 * V_50 = F_25 ( V_8 -> V_12 ) ;
int V_51 ;
T_2 V_52 ;
F_17 ( V_8 -> V_17 , L_6 , V_18 ,
V_2 -> V_6 ) ;
F_17 ( V_8 -> V_17 , L_7 , V_18 ,
V_2 -> V_7 ) ;
F_28 ( V_50 ) ;
switch ( V_24 -> V_53 ) {
case V_54 :
case V_55 :
V_52 = V_56 ;
V_51 = 32 ;
break;
case V_57 :
V_52 = V_58 ;
V_51 = 16 ;
break;
case V_59 :
V_52 = V_60 ;
V_51 = 24 ;
break;
default:
F_29 ( V_8 -> V_17 , L_8 ,
V_24 -> V_53 ) ;
return - V_61 ;
}
V_48 = V_8 -> V_62 ;
if ( V_2 -> V_63 & V_64 )
V_47 . V_65 = 1 ;
if ( V_2 -> V_63 & V_66 )
V_47 . V_67 = 1 ;
if ( V_2 -> V_63 & V_68 )
V_47 . V_69 = 1 ;
V_47 . V_70 = 1 ;
V_47 . V_71 = 0 ;
V_47 . V_72 = V_2 -> V_6 ;
V_47 . V_73 = V_2 -> V_7 ;
V_47 . V_74 = V_48 ;
V_47 . V_75 = V_2 -> V_3 - V_2 -> V_76 ;
V_47 . V_77 = V_2 -> V_76 - V_2 -> V_78 ;
V_47 . V_79 = V_2 -> V_78 - V_2 -> V_6 ;
V_47 . V_80 = V_2 -> V_4 - V_2 -> V_81 ;
V_47 . V_82 = V_2 -> V_81 - V_2 -> V_83 ;
V_47 . V_84 = V_2 -> V_83 - V_2 -> V_7 ;
V_47 . V_85 = V_2 -> clock * 1000 ;
V_47 . V_86 = V_8 -> V_87 ;
V_47 . V_88 = 0 ;
V_47 . V_89 = V_8 -> V_90 ;
V_47 . V_91 = V_8 -> V_92 ;
if ( V_8 -> V_14 ) {
V_28 = F_30 ( V_8 -> V_14 , V_93 ,
V_93 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 ,
L_9 ,
V_28 ) ;
return V_28 ;
}
F_31 ( V_8 -> V_14 , 1 , 0 , 1 ) ;
}
V_28 = F_32 ( V_8 -> V_13 , V_8 -> V_10 , V_47 . V_65 ,
V_48 , V_2 -> V_6 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 ,
L_10 ,
V_28 ) ;
return V_28 ;
}
V_28 = F_33 ( V_8 -> V_10 , & V_47 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 ,
L_11 , V_28 ) ;
return V_28 ;
}
F_34 ( V_50 , V_2 -> V_6 , V_2 -> V_7 ) ;
F_35 ( V_50 , V_52 ) ;
F_36 ( V_8 -> V_12 ) ;
V_28 = F_37 ( V_8 -> V_11 , V_2 -> V_6 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 ,
L_12 ,
V_28 ) ;
return V_28 ;
}
V_28 = F_38 ( V_8 -> V_11 ,
F_2 ( V_2 , F_1 ( V_2 ) ) , 64 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 ,
L_13 ,
V_28 ) ;
return V_28 ;
}
F_21 ( V_16 , V_35 , V_36 ) ;
return 0 ;
}
static void F_39 ( struct V_8 * V_8 )
{
unsigned long V_63 ;
struct V_94 * V_95 = V_8 -> V_32 . V_17 ;
F_40 ( & V_95 -> V_96 , V_63 ) ;
if ( V_8 -> V_34 )
F_41 ( V_95 , - 1 , V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
F_42 ( V_8 -> V_31 ) ;
F_43 ( & V_95 -> V_96 , V_63 ) ;
}
static T_4 F_44 ( int V_97 , void * V_98 )
{
struct V_8 * V_8 = V_98 ;
F_45 ( V_8 -> V_31 ) ;
if ( V_8 -> V_29 ) {
V_8 -> V_29 = NULL ;
F_21 ( & V_8 -> V_32 , 0 , 0 ) ;
F_39 ( V_8 ) ;
}
return V_99 ;
}
static bool F_46 ( struct V_15 * V_16 ,
const struct V_1 * V_2 ,
struct V_1 * V_100 )
{
return true ;
}
static void F_47 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_9 ( V_8 ) ;
}
static void F_48 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_3 ( V_8 ) ;
}
static int F_49 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_50 ( V_8 -> V_97 ) ;
return 0 ;
}
static void F_51 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_52 ( V_8 -> V_97 ) ;
}
static int F_53 ( struct V_15 * V_16 , T_2 V_101 ,
T_2 V_102 , int V_89 , int V_91 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
V_8 -> V_62 = V_102 ;
V_8 -> V_90 = V_89 ;
V_8 -> V_92 = V_91 ;
switch ( V_101 ) {
case V_103 :
case V_104 :
case V_105 :
V_8 -> V_87 = V_106 |
V_107 ;
break;
case V_108 :
V_8 -> V_87 = 0 ;
break;
}
return 0 ;
}
static void F_54 ( struct V_8 * V_8 )
{
if ( ! F_55 ( V_8 -> V_12 ) )
F_56 ( V_8 -> V_12 ) ;
if ( ! F_55 ( V_8 -> V_11 ) )
F_57 ( V_8 -> V_11 ) ;
if ( ! F_55 ( V_8 -> V_14 ) )
F_58 ( V_8 -> V_14 ) ;
if ( ! F_55 ( V_8 -> V_10 ) )
F_59 ( V_8 -> V_10 ) ;
}
static int F_60 ( struct V_8 * V_8 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = F_61 ( V_8 -> V_17 -> V_113 ) ;
int V_28 ;
V_8 -> V_12 = F_62 ( V_112 , V_110 -> V_114 [ 0 ] ) ;
if ( F_63 ( V_8 -> V_12 ) ) {
V_28 = F_64 ( V_8 -> V_12 ) ;
goto V_115;
}
V_8 -> V_13 = F_65 ( V_112 , V_110 -> V_13 ) ;
if ( F_63 ( V_8 -> V_13 ) ) {
V_28 = F_64 ( V_8 -> V_13 ) ;
goto V_115;
}
V_8 -> V_11 = F_66 ( V_112 , V_110 -> V_114 [ 0 ] ) ;
if ( F_63 ( V_8 -> V_11 ) ) {
V_28 = F_64 ( V_8 -> V_11 ) ;
goto V_115;
}
if ( V_110 -> V_14 >= 0 ) {
V_8 -> V_14 = F_67 ( V_112 , V_110 -> V_14 ) ;
if ( F_63 ( V_8 -> V_14 ) ) {
V_28 = F_64 ( V_8 -> V_14 ) ;
goto V_115;
}
}
V_8 -> V_10 = F_68 ( V_112 , V_110 -> V_10 ) ;
if ( F_63 ( V_8 -> V_10 ) ) {
V_28 = F_64 ( V_8 -> V_10 ) ;
goto V_115;
}
return 0 ;
V_115:
F_54 ( V_8 ) ;
return V_28 ;
}
static int F_69 ( struct V_8 * V_8 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = F_61 ( V_8 -> V_17 -> V_113 ) ;
int V_28 ;
V_28 = F_60 ( V_8 , V_110 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 , L_14 ,
V_28 ) ;
return V_28 ;
}
V_28 = F_70 ( & V_8 -> V_32 ,
& V_8 -> V_31 ,
& V_116 , V_117 ,
V_8 -> V_17 -> V_113 -> V_118 , V_110 -> V_10 ) ;
if ( V_28 ) {
F_29 ( V_8 -> V_17 , L_15 , V_28 ) ;
goto V_119;
}
V_8 -> V_97 = F_71 ( V_112 , V_8 -> V_12 ,
V_120 ) ;
V_28 = F_72 ( V_8 -> V_17 , V_8 -> V_97 , F_44 , 0 ,
L_16 , V_8 ) ;
if ( V_28 < 0 ) {
F_29 ( V_8 -> V_17 , L_17 , V_28 ) ;
goto V_119;
}
F_52 ( V_8 -> V_97 ) ;
return 0 ;
V_119:
F_54 ( V_8 ) ;
return V_28 ;
}
static int F_73 ( struct V_121 * V_122 )
{
struct V_109 * V_110 = V_122 -> V_17 . V_123 ;
struct V_8 * V_8 ;
int V_28 ;
if ( ! V_110 )
return - V_61 ;
V_122 -> V_17 . V_124 = F_74 ( 32 ) ;
V_8 = F_75 ( & V_122 -> V_17 , sizeof( * V_8 ) , V_125 ) ;
if ( ! V_8 )
return - V_126 ;
V_8 -> V_17 = & V_122 -> V_17 ;
V_28 = F_69 ( V_8 , V_110 ) ;
if ( V_28 )
return V_28 ;
F_76 ( V_122 , V_8 ) ;
return 0 ;
}
static int F_77 ( struct V_121 * V_122 )
{
struct V_8 * V_8 = F_78 ( V_122 ) ;
F_79 ( V_8 -> V_31 ) ;
F_54 ( V_8 ) ;
return 0 ;
}
