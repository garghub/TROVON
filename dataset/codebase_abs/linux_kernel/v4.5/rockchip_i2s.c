static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 -> V_5 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_2 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static inline struct V_3 * F_7 ( struct V_7 * V_8 )
{
return F_8 ( V_8 ) ;
}
static void F_9 ( struct V_3 * V_4 , int V_9 )
{
unsigned int V_10 = 0 ;
int V_11 = 10 ;
if ( V_9 ) {
F_10 ( V_4 -> V_12 , V_13 ,
V_14 , V_14 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_16 ,
V_16 ) ;
} else {
F_10 ( V_4 -> V_12 , V_13 ,
V_14 , V_17 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_16 ,
V_18 ) ;
F_10 ( V_4 -> V_12 , V_19 ,
V_20 ,
V_20 ) ;
F_11 ( V_4 -> V_12 , V_19 , & V_10 ) ;
while ( V_10 & V_20 ) {
F_11 ( V_4 -> V_12 , V_19 , & V_10 ) ;
V_11 -- ;
if ( ! V_11 ) {
F_12 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
static void F_13 ( struct V_3 * V_4 , int V_9 )
{
unsigned int V_10 = 0 ;
int V_11 = 10 ;
if ( V_9 ) {
F_10 ( V_4 -> V_12 , V_13 ,
V_21 , V_21 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_22 ,
V_22 ) ;
} else {
F_10 ( V_4 -> V_12 , V_13 ,
V_21 , V_23 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_22 ,
V_24 ) ;
F_10 ( V_4 -> V_12 , V_19 ,
V_25 ,
V_25 ) ;
F_11 ( V_4 -> V_12 , V_19 , & V_10 ) ;
while ( V_10 & V_25 ) {
F_11 ( V_4 -> V_12 , V_19 , & V_10 ) ;
V_11 -- ;
if ( ! V_11 ) {
F_12 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
static int F_14 ( struct V_7 * V_26 ,
unsigned int V_27 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
unsigned int V_28 = 0 , V_10 = 0 ;
V_28 = V_29 ;
switch ( V_27 & V_30 ) {
case V_31 :
V_10 = V_32 ;
V_4 -> V_33 = true ;
break;
case V_34 :
V_10 = V_35 ;
V_4 -> V_33 = false ;
break;
default:
return - V_36 ;
}
F_10 ( V_4 -> V_12 , V_37 , V_28 , V_10 ) ;
V_28 = V_38 ;
switch ( V_27 & V_39 ) {
case V_40 :
V_10 = V_41 ;
break;
case V_42 :
V_10 = V_43 ;
break;
case V_44 :
V_10 = V_45 ;
break;
default:
return - V_36 ;
}
F_10 ( V_4 -> V_12 , V_46 , V_28 , V_10 ) ;
V_28 = V_47 ;
switch ( V_27 & V_39 ) {
case V_40 :
V_10 = V_48 ;
break;
case V_42 :
V_10 = V_49 ;
break;
case V_44 :
V_10 = V_50 ;
break;
default:
return - V_36 ;
}
F_10 ( V_4 -> V_12 , V_51 , V_28 , V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
struct V_56 * V_57 = V_53 -> V_58 ;
unsigned int V_10 = 0 ;
unsigned int V_59 , V_60 , V_61 , V_62 ;
if ( V_4 -> V_33 ) {
V_59 = F_16 ( V_4 -> V_5 ) ;
V_60 = 2 * 32 * F_17 ( V_55 ) ;
if ( V_60 && V_59 % V_60 )
return - V_36 ;
V_61 = V_59 / V_60 ;
V_62 = V_60 / F_17 ( V_55 ) ;
F_10 ( V_4 -> V_12 , V_37 ,
V_63 ,
F_18 ( V_61 ) ) ;
F_10 ( V_4 -> V_12 , V_37 ,
V_64 |
V_65 ,
F_19 ( V_62 ) |
F_20 ( V_62 ) ) ;
}
switch ( F_21 ( V_55 ) ) {
case V_66 :
V_10 |= F_22 ( 8 ) ;
break;
case V_67 :
V_10 |= F_22 ( 16 ) ;
break;
case V_68 :
V_10 |= F_22 ( 20 ) ;
break;
case V_69 :
V_10 |= F_22 ( 24 ) ;
break;
case V_70 :
V_10 |= F_22 ( 32 ) ;
break;
default:
return - V_36 ;
}
switch ( F_23 ( V_55 ) ) {
case 8 :
V_10 |= V_71 ;
break;
case 6 :
V_10 |= V_72 ;
break;
case 4 :
V_10 |= V_73 ;
break;
case 2 :
V_10 |= V_74 ;
break;
default:
F_6 ( V_4 -> V_2 , L_3 ,
F_23 ( V_55 ) ) ;
return - V_36 ;
}
if ( V_53 -> V_75 == V_76 )
F_10 ( V_4 -> V_12 , V_51 ,
V_77 | V_78 ,
V_10 ) ;
else
F_10 ( V_4 -> V_12 , V_46 ,
V_79 | V_80 ,
V_10 ) ;
F_10 ( V_4 -> V_12 , V_13 , V_81 ,
F_24 ( 16 ) ) ;
F_10 ( V_4 -> V_12 , V_13 , V_82 ,
F_25 ( 16 ) ) ;
V_10 = V_83 ;
if ( V_8 -> V_84 -> V_85 || V_57 -> V_86 -> V_85 )
V_10 = V_87 ;
F_10 ( V_4 -> V_12 , V_37 ,
V_88 ,
V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_52 * V_53 ,
int V_89 , struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
int V_6 = 0 ;
switch ( V_89 ) {
case V_90 :
case V_91 :
case V_92 :
if ( V_53 -> V_75 == V_76 )
F_13 ( V_4 , 1 ) ;
else
F_9 ( V_4 , 1 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
if ( V_53 -> V_75 == V_76 )
F_13 ( V_4 , 0 ) ;
else
F_9 ( V_4 , 0 ) ;
break;
default:
V_6 = - V_36 ;
break;
}
return V_6 ;
}
static int F_27 ( struct V_7 * V_26 , int V_96 ,
unsigned int V_97 , int V_98 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
int V_6 ;
V_6 = F_28 ( V_4 -> V_5 , V_97 ) ;
if ( V_6 )
F_6 ( V_4 -> V_2 , L_4 , V_6 ) ;
return V_6 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
V_8 -> V_99 = & V_4 -> V_99 ;
V_8 -> V_100 = & V_4 -> V_100 ;
return 0 ;
}
static bool F_30 ( struct V_1 * V_2 , unsigned int V_101 )
{
switch ( V_101 ) {
case V_46 :
case V_51 :
case V_37 :
case V_13 :
case V_102 :
case V_15 :
case V_19 :
case V_103 :
return true ;
default:
return false ;
}
}
static bool F_31 ( struct V_1 * V_2 , unsigned int V_101 )
{
switch ( V_101 ) {
case V_46 :
case V_51 :
case V_37 :
case V_13 :
case V_102 :
case V_15 :
case V_19 :
case V_104 :
case V_105 :
case V_106 :
return true ;
default:
return false ;
}
}
static bool F_32 ( struct V_1 * V_2 , unsigned int V_101 )
{
switch ( V_101 ) {
case V_106 :
case V_19 :
return true ;
default:
return false ;
}
}
static bool F_33 ( struct V_1 * V_2 , unsigned int V_101 )
{
switch ( V_101 ) {
default:
return false ;
}
}
static int F_34 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_2 . V_111 ;
struct V_3 * V_4 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
void T_1 * V_116 ;
int V_6 ;
int V_10 ;
V_4 = F_35 ( & V_108 -> V_2 , sizeof( * V_4 ) , V_117 ) ;
if ( ! V_4 ) {
F_6 ( & V_108 -> V_2 , L_5 ) ;
return - V_118 ;
}
V_4 -> V_119 = F_36 ( & V_108 -> V_2 , L_6 ) ;
if ( F_37 ( V_4 -> V_119 ) ) {
F_6 ( & V_108 -> V_2 , L_7 ) ;
return F_38 ( V_4 -> V_119 ) ;
}
V_6 = F_5 ( V_4 -> V_119 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_2 , L_8 , V_6 ) ;
return V_6 ;
}
V_4 -> V_5 = F_36 ( & V_108 -> V_2 , L_9 ) ;
if ( F_37 ( V_4 -> V_5 ) ) {
F_6 ( & V_108 -> V_2 , L_10 ) ;
return F_38 ( V_4 -> V_5 ) ;
}
V_115 = F_39 ( V_108 , V_120 , 0 ) ;
V_116 = F_40 ( & V_108 -> V_2 , V_115 ) ;
if ( F_37 ( V_116 ) )
return F_38 ( V_116 ) ;
V_4 -> V_12 = F_41 ( & V_108 -> V_2 , V_116 ,
& V_121 ) ;
if ( F_37 ( V_4 -> V_12 ) ) {
F_6 ( & V_108 -> V_2 ,
L_11 ) ;
return F_38 ( V_4 -> V_12 ) ;
}
V_4 -> V_100 . V_122 = V_115 -> V_123 + V_103 ;
V_4 -> V_100 . V_124 = V_125 ;
V_4 -> V_100 . V_126 = 4 ;
V_4 -> V_99 . V_122 = V_115 -> V_123 + V_104 ;
V_4 -> V_99 . V_124 = V_125 ;
V_4 -> V_99 . V_126 = 4 ;
V_4 -> V_2 = & V_108 -> V_2 ;
F_42 ( & V_108 -> V_2 , V_4 ) ;
F_43 ( & V_108 -> V_2 ) ;
if ( ! F_44 ( & V_108 -> V_2 ) ) {
V_6 = F_4 ( & V_108 -> V_2 ) ;
if ( V_6 )
goto V_127;
}
V_113 = F_35 ( & V_108 -> V_2 ,
sizeof( * V_113 ) , V_117 ) ;
if ( ! V_113 )
return - V_118 ;
memcpy ( V_113 , & V_128 , sizeof( * V_113 ) ) ;
if ( ! F_45 ( V_110 , L_12 , & V_10 ) ) {
if ( V_10 >= 2 && V_10 <= 8 )
V_113 -> V_129 . V_130 = V_10 ;
}
if ( ! F_45 ( V_110 , L_13 , & V_10 ) ) {
if ( V_10 >= 2 && V_10 <= 8 )
V_113 -> V_131 . V_130 = V_10 ;
}
V_6 = F_46 ( & V_108 -> V_2 ,
& V_132 ,
V_113 , 1 ) ;
if ( V_6 ) {
F_6 ( & V_108 -> V_2 , L_14 ) ;
goto V_133;
}
V_6 = F_47 ( & V_108 -> V_2 , NULL , 0 ) ;
if ( V_6 ) {
F_6 ( & V_108 -> V_2 , L_15 ) ;
return V_6 ;
}
return 0 ;
V_133:
if ( ! F_48 ( & V_108 -> V_2 ) )
F_1 ( & V_108 -> V_2 ) ;
V_127:
F_49 ( & V_108 -> V_2 ) ;
return V_6 ;
}
static int F_50 ( struct V_107 * V_108 )
{
struct V_3 * V_4 = F_2 ( & V_108 -> V_2 ) ;
F_49 ( & V_108 -> V_2 ) ;
if ( ! F_48 ( & V_108 -> V_2 ) )
F_1 ( & V_108 -> V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_119 ) ;
return 0 ;
}
