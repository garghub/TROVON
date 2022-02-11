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
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_18 = true ;
} else {
V_4 -> V_18 = false ;
F_10 ( V_4 -> V_12 , V_13 ,
V_14 , V_19 ) ;
if ( ! V_4 -> V_20 ) {
F_10 ( V_4 -> V_12 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_10 ( V_4 -> V_12 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
while ( V_10 ) {
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
V_11 -- ;
if ( ! V_11 ) {
F_12 ( V_4 -> V_2 , L_2 ) ;
break;
}
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
V_26 , V_26 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_20 = true ;
} else {
V_4 -> V_20 = false ;
F_10 ( V_4 -> V_12 , V_13 ,
V_26 , V_27 ) ;
if ( ! V_4 -> V_18 ) {
F_10 ( V_4 -> V_12 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_10 ( V_4 -> V_12 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
while ( V_10 ) {
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
V_11 -- ;
if ( ! V_11 ) {
F_12 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
}
static int F_14 ( struct V_7 * V_28 ,
unsigned int V_29 )
{
struct V_3 * V_4 = F_7 ( V_28 ) ;
unsigned int V_30 = 0 , V_10 = 0 ;
V_30 = V_31 ;
switch ( V_29 & V_32 ) {
case V_33 :
V_10 = V_34 ;
V_4 -> V_35 = true ;
break;
case V_36 :
V_10 = V_37 ;
V_4 -> V_35 = false ;
break;
default:
return - V_38 ;
}
F_10 ( V_4 -> V_12 , V_39 , V_30 , V_10 ) ;
V_30 = V_40 ;
switch ( V_29 & V_41 ) {
case V_42 :
V_10 = V_43 ;
break;
case V_44 :
V_10 = V_45 ;
break;
case V_46 :
V_10 = V_47 ;
break;
default:
return - V_38 ;
}
F_10 ( V_4 -> V_12 , V_48 , V_30 , V_10 ) ;
V_30 = V_49 ;
switch ( V_29 & V_41 ) {
case V_42 :
V_10 = V_50 ;
break;
case V_44 :
V_10 = V_51 ;
break;
case V_46 :
V_10 = V_52 ;
break;
default:
return - V_38 ;
}
F_10 ( V_4 -> V_12 , V_53 , V_30 , V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
struct V_58 * V_59 = V_55 -> V_60 ;
unsigned int V_10 = 0 ;
unsigned int V_61 , V_62 , V_63 , V_64 ;
if ( V_4 -> V_35 ) {
V_61 = F_16 ( V_4 -> V_5 ) ;
V_62 = 2 * 32 * F_17 ( V_57 ) ;
if ( V_62 && V_61 % V_62 )
return - V_38 ;
V_63 = V_61 / V_62 ;
V_64 = V_62 / F_17 ( V_57 ) ;
F_10 ( V_4 -> V_12 , V_39 ,
V_65 ,
F_18 ( V_63 ) ) ;
F_10 ( V_4 -> V_12 , V_39 ,
V_66 |
V_67 ,
F_19 ( V_64 ) |
F_20 ( V_64 ) ) ;
}
switch ( F_21 ( V_57 ) ) {
case V_68 :
V_10 |= F_22 ( 8 ) ;
break;
case V_69 :
V_10 |= F_22 ( 16 ) ;
break;
case V_70 :
V_10 |= F_22 ( 20 ) ;
break;
case V_71 :
V_10 |= F_22 ( 24 ) ;
break;
case V_72 :
V_10 |= F_22 ( 32 ) ;
break;
default:
return - V_38 ;
}
switch ( F_23 ( V_57 ) ) {
case 8 :
V_10 |= V_73 ;
break;
case 6 :
V_10 |= V_74 ;
break;
case 4 :
V_10 |= V_75 ;
break;
case 2 :
V_10 |= V_76 ;
break;
default:
F_6 ( V_4 -> V_2 , L_3 ,
F_23 ( V_57 ) ) ;
return - V_38 ;
}
if ( V_55 -> V_77 == V_78 )
F_10 ( V_4 -> V_12 , V_53 ,
V_79 | V_80 ,
V_10 ) ;
else
F_10 ( V_4 -> V_12 , V_48 ,
V_81 | V_82 ,
V_10 ) ;
F_10 ( V_4 -> V_12 , V_13 , V_83 ,
F_24 ( 16 ) ) ;
F_10 ( V_4 -> V_12 , V_13 , V_84 ,
F_25 ( 16 ) ) ;
V_10 = V_85 ;
if ( V_8 -> V_86 -> V_87 || V_59 -> V_88 -> V_87 )
V_10 = V_89 ;
F_10 ( V_4 -> V_12 , V_39 ,
V_90 ,
V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_54 * V_55 ,
int V_91 , struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
int V_6 = 0 ;
switch ( V_91 ) {
case V_92 :
case V_93 :
case V_94 :
if ( V_55 -> V_77 == V_78 )
F_13 ( V_4 , 1 ) ;
else
F_9 ( V_4 , 1 ) ;
break;
case V_95 :
case V_96 :
case V_97 :
if ( V_55 -> V_77 == V_78 )
F_13 ( V_4 , 0 ) ;
else
F_9 ( V_4 , 0 ) ;
break;
default:
V_6 = - V_38 ;
break;
}
return V_6 ;
}
static int F_27 ( struct V_7 * V_28 , int V_98 ,
unsigned int V_99 , int V_100 )
{
struct V_3 * V_4 = F_7 ( V_28 ) ;
int V_6 ;
V_6 = F_28 ( V_4 -> V_5 , V_99 ) ;
if ( V_6 )
F_6 ( V_4 -> V_2 , L_4 , V_6 ) ;
return V_6 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
V_8 -> V_101 = & V_4 -> V_101 ;
V_8 -> V_102 = & V_4 -> V_102 ;
return 0 ;
}
static bool F_30 ( struct V_1 * V_2 , unsigned int V_103 )
{
switch ( V_103 ) {
case V_48 :
case V_53 :
case V_39 :
case V_13 :
case V_104 :
case V_15 :
case V_23 :
case V_105 :
return true ;
default:
return false ;
}
}
static bool F_31 ( struct V_1 * V_2 , unsigned int V_103 )
{
switch ( V_103 ) {
case V_48 :
case V_53 :
case V_39 :
case V_13 :
case V_104 :
case V_15 :
case V_23 :
case V_106 :
case V_107 :
case V_108 :
return true ;
default:
return false ;
}
}
static bool F_32 ( struct V_1 * V_2 , unsigned int V_103 )
{
switch ( V_103 ) {
case V_108 :
case V_23 :
return true ;
default:
return false ;
}
}
static bool F_33 ( struct V_1 * V_2 , unsigned int V_103 )
{
switch ( V_103 ) {
default:
return false ;
}
}
static int F_34 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = V_110 -> V_2 . V_113 ;
struct V_3 * V_4 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
void T_1 * V_118 ;
int V_6 ;
int V_10 ;
V_4 = F_35 ( & V_110 -> V_2 , sizeof( * V_4 ) , V_119 ) ;
if ( ! V_4 ) {
F_6 ( & V_110 -> V_2 , L_5 ) ;
return - V_120 ;
}
V_4 -> V_121 = F_36 ( & V_110 -> V_2 , L_6 ) ;
if ( F_37 ( V_4 -> V_121 ) ) {
F_6 ( & V_110 -> V_2 , L_7 ) ;
return F_38 ( V_4 -> V_121 ) ;
}
V_6 = F_5 ( V_4 -> V_121 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_2 , L_8 , V_6 ) ;
return V_6 ;
}
V_4 -> V_5 = F_36 ( & V_110 -> V_2 , L_9 ) ;
if ( F_37 ( V_4 -> V_5 ) ) {
F_6 ( & V_110 -> V_2 , L_10 ) ;
return F_38 ( V_4 -> V_5 ) ;
}
V_117 = F_39 ( V_110 , V_122 , 0 ) ;
V_118 = F_40 ( & V_110 -> V_2 , V_117 ) ;
if ( F_37 ( V_118 ) )
return F_38 ( V_118 ) ;
V_4 -> V_12 = F_41 ( & V_110 -> V_2 , V_118 ,
& V_123 ) ;
if ( F_37 ( V_4 -> V_12 ) ) {
F_6 ( & V_110 -> V_2 ,
L_11 ) ;
return F_38 ( V_4 -> V_12 ) ;
}
V_4 -> V_102 . V_124 = V_117 -> V_125 + V_105 ;
V_4 -> V_102 . V_126 = V_127 ;
V_4 -> V_102 . V_128 = 4 ;
V_4 -> V_101 . V_124 = V_117 -> V_125 + V_106 ;
V_4 -> V_101 . V_126 = V_127 ;
V_4 -> V_101 . V_128 = 4 ;
V_4 -> V_2 = & V_110 -> V_2 ;
F_42 ( & V_110 -> V_2 , V_4 ) ;
F_43 ( & V_110 -> V_2 ) ;
if ( ! F_44 ( & V_110 -> V_2 ) ) {
V_6 = F_4 ( & V_110 -> V_2 ) ;
if ( V_6 )
goto V_129;
}
V_115 = F_35 ( & V_110 -> V_2 ,
sizeof( * V_115 ) , V_119 ) ;
if ( ! V_115 )
return - V_120 ;
memcpy ( V_115 , & V_130 , sizeof( * V_115 ) ) ;
if ( ! F_45 ( V_112 , L_12 , & V_10 ) ) {
if ( V_10 >= 2 && V_10 <= 8 )
V_115 -> V_131 . V_132 = V_10 ;
}
if ( ! F_45 ( V_112 , L_13 , & V_10 ) ) {
if ( V_10 >= 2 && V_10 <= 8 )
V_115 -> V_133 . V_132 = V_10 ;
}
V_6 = F_46 ( & V_110 -> V_2 ,
& V_134 ,
V_115 , 1 ) ;
if ( V_6 ) {
F_6 ( & V_110 -> V_2 , L_14 ) ;
goto V_135;
}
V_6 = F_47 ( & V_110 -> V_2 , NULL , 0 ) ;
if ( V_6 ) {
F_6 ( & V_110 -> V_2 , L_15 ) ;
return V_6 ;
}
return 0 ;
V_135:
if ( ! F_48 ( & V_110 -> V_2 ) )
F_1 ( & V_110 -> V_2 ) ;
V_129:
F_49 ( & V_110 -> V_2 ) ;
return V_6 ;
}
static int F_50 ( struct V_109 * V_110 )
{
struct V_3 * V_4 = F_2 ( & V_110 -> V_2 ) ;
F_49 ( & V_110 -> V_2 ) ;
if ( ! F_48 ( & V_110 -> V_2 ) )
F_1 ( & V_110 -> V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_121 ) ;
return 0 ;
}
