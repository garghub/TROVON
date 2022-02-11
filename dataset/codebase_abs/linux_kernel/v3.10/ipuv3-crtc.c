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
struct V_25 * V_26 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
int V_27 ;
if ( V_8 -> V_28 )
return - V_29 ;
V_27 = F_19 ( V_8 -> V_30 ) ;
if ( V_27 ) {
F_17 ( V_8 -> V_17 , L_2 ) ;
F_20 ( & V_26 -> V_31 . V_32 ) ;
return V_27 ;
}
V_8 -> V_28 = V_24 ;
V_8 -> V_33 = V_26 ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 , int V_34 , int V_35 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
struct V_36 * V_37 ;
struct V_23 * V_24 = V_16 -> V_24 ;
unsigned long V_38 ;
V_37 = F_22 ( V_24 , 0 ) ;
if ( ! V_37 ) {
F_23 ( L_3 ) ;
return - V_39 ;
}
V_38 = V_37 -> V_40 ;
V_38 += V_34 * ( V_24 -> V_41 >> 3 ) ;
V_38 += V_35 * V_24 -> V_42 [ 0 ] ;
F_17 ( V_8 -> V_17 , L_4 , V_18 , V_38 ) ;
F_17 ( V_8 -> V_17 , L_5 , V_18 , V_34 , V_35 ) ;
F_24 ( F_25 ( V_8 -> V_12 ) , V_24 -> V_42 [ 0 ] ) ;
F_26 ( F_25 ( V_8 -> V_12 ) ,
0 , V_38 ) ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 ,
struct V_1 * V_43 ,
struct V_1 * V_2 ,
int V_34 , int V_35 ,
struct V_23 * V_44 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
struct V_23 * V_24 = V_8 -> V_31 . V_24 ;
int V_27 ;
struct V_45 V_46 = {} ;
T_1 V_47 ;
struct V_48 T_2 * V_49 = F_25 ( V_8 -> V_12 ) ;
int V_50 ;
T_1 V_51 ;
F_17 ( V_8 -> V_17 , L_6 , V_18 ,
V_2 -> V_6 ) ;
F_17 ( V_8 -> V_17 , L_7 , V_18 ,
V_2 -> V_7 ) ;
F_28 ( V_49 ) ;
switch ( V_24 -> V_52 ) {
case V_53 :
case V_54 :
V_51 = V_55 ;
V_50 = 32 ;
break;
case V_56 :
V_51 = V_57 ;
V_50 = 16 ;
break;
case V_58 :
V_51 = V_59 ;
V_50 = 24 ;
break;
default:
F_29 ( V_8 -> V_17 , L_8 ,
V_24 -> V_52 ) ;
return - V_60 ;
}
V_47 = V_8 -> V_61 ;
if ( V_2 -> V_62 & V_63 )
V_46 . V_64 = 1 ;
if ( V_2 -> V_62 & V_65 )
V_46 . V_66 = 1 ;
if ( V_2 -> V_62 & V_67 )
V_46 . V_68 = 1 ;
V_46 . V_69 = 1 ;
V_46 . V_70 = 0 ;
V_46 . V_71 = V_2 -> V_6 ;
V_46 . V_72 = V_2 -> V_7 ;
V_46 . V_73 = V_47 ;
V_46 . V_74 = V_2 -> V_3 - V_2 -> V_75 ;
V_46 . V_76 = V_2 -> V_75 - V_2 -> V_77 ;
V_46 . V_78 = V_2 -> V_77 - V_2 -> V_6 ;
V_46 . V_79 = V_2 -> V_4 - V_2 -> V_80 ;
V_46 . V_81 = V_2 -> V_80 - V_2 -> V_82 ;
V_46 . V_83 = V_2 -> V_82 - V_2 -> V_7 ;
V_46 . V_84 = V_2 -> clock * 1000 ;
V_46 . V_85 = V_8 -> V_86 ;
V_46 . V_87 = 0 ;
V_46 . V_88 = V_8 -> V_89 ;
V_46 . V_90 = V_8 -> V_91 ;
if ( V_8 -> V_14 ) {
V_27 = F_30 ( V_8 -> V_14 , V_92 ,
V_92 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 ,
L_9 ,
V_27 ) ;
return V_27 ;
}
F_31 ( V_8 -> V_14 , 1 , 0 , 1 ) ;
}
V_27 = F_32 ( V_8 -> V_13 , V_8 -> V_10 , V_46 . V_64 ,
V_47 , V_2 -> V_6 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 ,
L_10 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_33 ( V_8 -> V_10 , & V_46 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 ,
L_11 , V_27 ) ;
return V_27 ;
}
F_34 ( V_49 , V_2 -> V_6 , V_2 -> V_7 ) ;
F_35 ( V_49 , V_51 ) ;
F_36 ( V_8 -> V_12 ) ;
V_27 = F_37 ( V_8 -> V_11 , V_2 -> V_6 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 ,
L_12 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_38 ( V_8 -> V_11 ,
F_2 ( V_2 , F_1 ( V_2 ) ) , 64 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 ,
L_13 ,
V_27 ) ;
return V_27 ;
}
F_21 ( V_16 , V_34 , V_35 ) ;
return 0 ;
}
static void F_39 ( struct V_8 * V_8 )
{
unsigned long V_62 ;
struct V_93 * V_94 = V_8 -> V_31 . V_17 ;
F_40 ( & V_94 -> V_95 , V_62 ) ;
if ( V_8 -> V_33 )
F_41 ( V_94 , - 1 , V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
F_42 ( V_8 -> V_30 ) ;
F_43 ( & V_94 -> V_95 , V_62 ) ;
}
static T_3 F_44 ( int V_96 , void * V_97 )
{
struct V_8 * V_8 = V_97 ;
F_45 ( V_8 -> V_30 ) ;
if ( V_8 -> V_28 ) {
V_8 -> V_31 . V_24 = V_8 -> V_28 ;
V_8 -> V_28 = NULL ;
F_21 ( & V_8 -> V_31 , 0 , 0 ) ;
F_39 ( V_8 ) ;
}
return V_98 ;
}
static bool F_46 ( struct V_15 * V_16 ,
const struct V_1 * V_2 ,
struct V_1 * V_99 )
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
static void F_49 ( struct V_15 * V_16 )
{
}
static int F_50 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_51 ( V_8 -> V_96 ) ;
return 0 ;
}
static void F_52 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_53 ( V_8 -> V_96 ) ;
}
static int F_54 ( struct V_15 * V_16 , T_1 V_100 ,
T_1 V_101 , int V_88 , int V_90 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
V_8 -> V_61 = V_101 ;
V_8 -> V_89 = V_88 ;
V_8 -> V_91 = V_90 ;
switch ( V_100 ) {
case V_102 :
case V_103 :
case V_104 :
V_8 -> V_86 = V_105 |
V_106 ;
break;
case V_107 :
V_8 -> V_86 = 0 ;
break;
}
return 0 ;
}
static void F_55 ( struct V_8 * V_8 )
{
if ( ! F_56 ( V_8 -> V_12 ) )
F_57 ( V_8 -> V_12 ) ;
if ( ! F_56 ( V_8 -> V_11 ) )
F_58 ( V_8 -> V_11 ) ;
if ( ! F_56 ( V_8 -> V_14 ) )
F_59 ( V_8 -> V_14 ) ;
if ( ! F_56 ( V_8 -> V_10 ) )
F_60 ( V_8 -> V_10 ) ;
}
static int F_61 ( struct V_8 * V_8 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 = F_62 ( V_8 -> V_17 -> V_112 ) ;
int V_27 ;
V_8 -> V_12 = F_63 ( V_111 , V_109 -> V_113 [ 0 ] ) ;
if ( F_64 ( V_8 -> V_12 ) ) {
V_27 = F_65 ( V_8 -> V_12 ) ;
goto V_114;
}
V_8 -> V_13 = F_66 ( V_111 , V_109 -> V_13 ) ;
if ( F_64 ( V_8 -> V_13 ) ) {
V_27 = F_65 ( V_8 -> V_13 ) ;
goto V_114;
}
V_8 -> V_11 = F_67 ( V_111 , V_109 -> V_113 [ 0 ] ) ;
if ( F_64 ( V_8 -> V_11 ) ) {
V_27 = F_65 ( V_8 -> V_11 ) ;
goto V_114;
}
if ( V_109 -> V_14 >= 0 ) {
V_8 -> V_14 = F_68 ( V_111 , V_109 -> V_14 ) ;
if ( F_64 ( V_8 -> V_14 ) ) {
V_27 = F_65 ( V_8 -> V_14 ) ;
goto V_114;
}
}
V_8 -> V_10 = F_69 ( V_111 , V_109 -> V_10 ) ;
if ( F_64 ( V_8 -> V_10 ) ) {
V_27 = F_65 ( V_8 -> V_10 ) ;
goto V_114;
}
return 0 ;
V_114:
F_55 ( V_8 ) ;
return V_27 ;
}
static int F_70 ( struct V_8 * V_8 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 = F_62 ( V_8 -> V_17 -> V_112 ) ;
int V_27 ;
V_27 = F_61 ( V_8 , V_109 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 , L_14 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_71 ( & V_8 -> V_31 ,
& V_8 -> V_30 ,
& V_115 , V_116 ,
V_8 -> V_17 -> V_112 -> V_117 , V_109 -> V_10 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 , L_15 , V_27 ) ;
goto V_118;
}
V_8 -> V_96 = F_72 ( V_111 , V_8 -> V_12 ,
V_119 ) ;
V_27 = F_73 ( V_8 -> V_17 , V_8 -> V_96 , F_44 , 0 ,
L_16 , V_8 ) ;
if ( V_27 < 0 ) {
F_29 ( V_8 -> V_17 , L_17 , V_27 ) ;
goto V_118;
}
F_53 ( V_8 -> V_96 ) ;
return 0 ;
V_118:
F_55 ( V_8 ) ;
return V_27 ;
}
static int F_74 ( struct V_120 * V_121 )
{
struct V_108 * V_109 = V_121 -> V_17 . V_122 ;
struct V_8 * V_8 ;
int V_27 ;
if ( ! V_109 )
return - V_60 ;
V_121 -> V_17 . V_123 = F_75 ( 32 ) ;
V_8 = F_76 ( & V_121 -> V_17 , sizeof( * V_8 ) , V_124 ) ;
if ( ! V_8 )
return - V_125 ;
V_8 -> V_17 = & V_121 -> V_17 ;
V_27 = F_70 ( V_8 , V_109 ) ;
if ( V_27 )
return V_27 ;
F_77 ( V_121 , V_8 ) ;
return 0 ;
}
static int F_78 ( struct V_120 * V_121 )
{
struct V_8 * V_8 = F_79 ( V_121 ) ;
F_80 ( V_8 -> V_30 ) ;
F_55 ( V_8 ) ;
return 0 ;
}
