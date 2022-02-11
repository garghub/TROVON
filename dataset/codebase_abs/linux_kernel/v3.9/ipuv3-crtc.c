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
if ( V_8 -> V_14 ) {
V_27 = F_30 ( V_8 -> V_14 , V_88 ,
V_88 ) ;
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
struct V_25 * V_89 ;
struct V_90 V_91 ;
unsigned long V_62 ;
struct V_92 * V_93 = V_8 -> V_31 . V_17 ;
F_40 ( & V_93 -> V_94 , V_62 ) ;
V_89 = V_8 -> V_33 ;
if ( ! V_89 ) {
F_41 ( & V_93 -> V_94 , V_62 ) ;
return;
}
F_42 ( & V_91 ) ;
V_89 -> V_26 . V_95 = 0 ;
V_89 -> V_26 . V_96 = V_91 . V_96 ;
V_89 -> V_26 . V_97 = V_91 . V_97 ;
V_8 -> V_33 = NULL ;
F_43 ( V_8 -> V_30 ) ;
F_44 ( & V_89 -> V_31 . V_32 , & V_89 -> V_31 . V_98 -> V_99 ) ;
F_45 ( & V_89 -> V_31 . V_98 -> V_100 ) ;
F_41 ( & V_93 -> V_94 , V_62 ) ;
}
static T_3 F_46 ( int V_101 , void * V_102 )
{
struct V_8 * V_8 = V_102 ;
F_47 ( V_8 -> V_30 ) ;
if ( V_8 -> V_28 ) {
V_8 -> V_31 . V_24 = V_8 -> V_28 ;
V_8 -> V_28 = NULL ;
F_21 ( & V_8 -> V_31 , 0 , 0 ) ;
F_39 ( V_8 ) ;
}
return V_103 ;
}
static bool F_48 ( struct V_15 * V_16 ,
const struct V_1 * V_2 ,
struct V_1 * V_104 )
{
return true ;
}
static void F_49 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_9 ( V_8 ) ;
}
static void F_50 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_3 ( V_8 ) ;
}
static void F_51 ( struct V_15 * V_16 )
{
}
static int F_52 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_53 ( V_8 -> V_101 ) ;
return 0 ;
}
static void F_54 ( struct V_15 * V_16 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
F_55 ( V_8 -> V_101 ) ;
}
static int F_56 ( struct V_15 * V_16 , T_1 V_105 ,
T_1 V_106 )
{
struct V_8 * V_8 = F_16 ( V_16 ) ;
V_8 -> V_61 = V_106 ;
switch ( V_105 ) {
case V_107 :
V_8 -> V_86 = V_108 |
V_109 ;
break;
case V_110 :
V_8 -> V_86 = 0 ;
break;
}
return 0 ;
}
static void F_57 ( struct V_8 * V_8 )
{
if ( ! F_58 ( V_8 -> V_12 ) )
F_59 ( V_8 -> V_12 ) ;
if ( ! F_58 ( V_8 -> V_11 ) )
F_60 ( V_8 -> V_11 ) ;
if ( ! F_58 ( V_8 -> V_14 ) )
F_61 ( V_8 -> V_14 ) ;
if ( ! F_58 ( V_8 -> V_10 ) )
F_62 ( V_8 -> V_10 ) ;
}
static int F_63 ( struct V_8 * V_8 ,
struct V_111 * V_112 )
{
struct V_113 * V_114 = F_64 ( V_8 -> V_17 -> V_115 ) ;
int V_27 ;
V_8 -> V_12 = F_65 ( V_114 , V_112 -> V_116 [ 0 ] ) ;
if ( F_66 ( V_8 -> V_12 ) ) {
V_27 = F_67 ( V_8 -> V_12 ) ;
goto V_117;
}
V_8 -> V_13 = F_68 ( V_114 , V_112 -> V_13 ) ;
if ( F_66 ( V_8 -> V_13 ) ) {
V_27 = F_67 ( V_8 -> V_13 ) ;
goto V_117;
}
V_8 -> V_11 = F_69 ( V_114 , V_112 -> V_116 [ 0 ] ) ;
if ( F_66 ( V_8 -> V_11 ) ) {
V_27 = F_67 ( V_8 -> V_11 ) ;
goto V_117;
}
if ( V_112 -> V_14 >= 0 ) {
V_8 -> V_14 = F_70 ( V_114 , V_112 -> V_14 ) ;
if ( F_66 ( V_8 -> V_14 ) ) {
V_27 = F_67 ( V_8 -> V_14 ) ;
goto V_117;
}
}
V_8 -> V_10 = F_71 ( V_114 , V_112 -> V_10 ) ;
if ( F_66 ( V_8 -> V_10 ) ) {
V_27 = F_67 ( V_8 -> V_10 ) ;
goto V_117;
}
return 0 ;
V_117:
F_57 ( V_8 ) ;
return V_27 ;
}
static int F_72 ( struct V_8 * V_8 ,
struct V_111 * V_112 )
{
struct V_113 * V_114 = F_64 ( V_8 -> V_17 -> V_115 ) ;
int V_27 ;
V_27 = F_63 ( V_8 , V_112 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 , L_14 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_73 ( & V_8 -> V_31 ,
& V_8 -> V_30 ,
& V_118 , V_119 ,
V_8 -> V_17 -> V_115 -> V_120 , V_112 -> V_10 ) ;
if ( V_27 ) {
F_29 ( V_8 -> V_17 , L_15 , V_27 ) ;
goto V_121;
}
V_8 -> V_101 = F_74 ( V_114 , V_8 -> V_12 ,
V_122 ) ;
V_27 = F_75 ( V_8 -> V_17 , V_8 -> V_101 , F_46 , 0 ,
L_16 , V_8 ) ;
if ( V_27 < 0 ) {
F_29 ( V_8 -> V_17 , L_17 , V_27 ) ;
goto V_121;
}
F_55 ( V_8 -> V_101 ) ;
return 0 ;
V_121:
F_57 ( V_8 ) ;
return V_27 ;
}
static int F_76 ( struct V_123 * V_124 )
{
struct V_111 * V_112 = V_124 -> V_17 . V_125 ;
struct V_8 * V_8 ;
int V_27 ;
if ( ! V_112 )
return - V_60 ;
V_124 -> V_17 . V_126 = F_77 ( 32 ) ;
V_8 = F_78 ( & V_124 -> V_17 , sizeof( * V_8 ) , V_127 ) ;
if ( ! V_8 )
return - V_128 ;
V_8 -> V_17 = & V_124 -> V_17 ;
V_27 = F_72 ( V_8 , V_112 ) ;
if ( V_27 )
return V_27 ;
F_79 ( V_124 , V_8 ) ;
return 0 ;
}
static int F_80 ( struct V_123 * V_124 )
{
struct V_8 * V_8 = F_81 ( V_124 ) ;
F_82 ( V_8 -> V_30 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
