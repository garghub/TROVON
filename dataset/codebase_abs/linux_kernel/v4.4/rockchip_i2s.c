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
break;
case V_35 :
V_10 = V_36 ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_38 , V_30 , V_10 ) ;
V_30 = V_39 ;
switch ( V_29 & V_40 ) {
case V_41 :
V_10 = V_42 ;
break;
case V_43 :
V_10 = V_44 ;
break;
case V_45 :
V_10 = V_46 ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_47 , V_30 , V_10 ) ;
V_30 = V_48 ;
switch ( V_29 & V_40 ) {
case V_41 :
V_10 = V_49 ;
break;
case V_43 :
V_10 = V_50 ;
break;
case V_45 :
V_10 = V_51 ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_52 , V_30 , V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
struct V_57 * V_58 = V_54 -> V_59 ;
unsigned int V_10 = 0 ;
switch ( F_16 ( V_56 ) ) {
case V_60 :
V_10 |= F_17 ( 8 ) ;
break;
case V_61 :
V_10 |= F_17 ( 16 ) ;
break;
case V_62 :
V_10 |= F_17 ( 20 ) ;
break;
case V_63 :
V_10 |= F_17 ( 24 ) ;
break;
default:
return - V_37 ;
}
switch ( F_18 ( V_56 ) ) {
case 8 :
V_10 |= V_64 ;
break;
case 6 :
V_10 |= V_65 ;
break;
case 4 :
V_10 |= V_66 ;
break;
case 2 :
V_10 |= V_67 ;
break;
default:
F_6 ( V_4 -> V_2 , L_3 ,
F_18 ( V_56 ) ) ;
return - V_37 ;
}
if ( V_54 -> V_68 == V_69 )
F_10 ( V_4 -> V_12 , V_52 ,
V_70 | V_71 ,
V_10 ) ;
else
F_10 ( V_4 -> V_12 , V_47 ,
V_72 | V_73 ,
V_10 ) ;
F_10 ( V_4 -> V_12 , V_13 , V_74 ,
F_19 ( 16 ) ) ;
F_10 ( V_4 -> V_12 , V_13 , V_75 ,
F_20 ( 16 ) ) ;
V_10 = V_76 ;
if ( V_8 -> V_77 -> V_78 || V_58 -> V_79 -> V_78 )
V_10 = V_80 ;
F_10 ( V_4 -> V_12 , V_38 ,
V_81 ,
V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_53 * V_54 ,
int V_82 , struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
int V_6 = 0 ;
switch ( V_82 ) {
case V_83 :
case V_84 :
case V_85 :
if ( V_54 -> V_68 == V_69 )
F_13 ( V_4 , 1 ) ;
else
F_9 ( V_4 , 1 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
if ( V_54 -> V_68 == V_69 )
F_13 ( V_4 , 0 ) ;
else
F_9 ( V_4 , 0 ) ;
break;
default:
V_6 = - V_37 ;
break;
}
return V_6 ;
}
static int F_22 ( struct V_7 * V_28 , int V_89 ,
unsigned int V_90 , int V_91 )
{
struct V_3 * V_4 = F_7 ( V_28 ) ;
int V_6 ;
V_6 = F_23 ( V_4 -> V_5 , V_90 ) ;
if ( V_6 )
F_6 ( V_4 -> V_2 , L_4 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
V_8 -> V_92 = & V_4 -> V_92 ;
V_8 -> V_93 = & V_4 -> V_93 ;
return 0 ;
}
static bool F_25 ( struct V_1 * V_2 , unsigned int V_94 )
{
switch ( V_94 ) {
case V_47 :
case V_52 :
case V_38 :
case V_13 :
case V_95 :
case V_15 :
case V_23 :
case V_96 :
return true ;
default:
return false ;
}
}
static bool F_26 ( struct V_1 * V_2 , unsigned int V_94 )
{
switch ( V_94 ) {
case V_47 :
case V_52 :
case V_38 :
case V_13 :
case V_95 :
case V_15 :
case V_23 :
case V_97 :
case V_98 :
case V_99 :
return true ;
default:
return false ;
}
}
static bool F_27 ( struct V_1 * V_2 , unsigned int V_94 )
{
switch ( V_94 ) {
case V_99 :
case V_23 :
return true ;
default:
return false ;
}
}
static bool F_28 ( struct V_1 * V_2 , unsigned int V_94 )
{
switch ( V_94 ) {
default:
return false ;
}
}
static int F_29 ( struct V_100 * V_101 )
{
struct V_102 * V_103 = V_101 -> V_2 . V_104 ;
struct V_3 * V_4 ;
struct V_105 * V_106 ;
void T_1 * V_107 ;
int V_6 ;
int V_10 ;
V_4 = F_30 ( & V_101 -> V_2 , sizeof( * V_4 ) , V_108 ) ;
if ( ! V_4 ) {
F_6 ( & V_101 -> V_2 , L_5 ) ;
return - V_109 ;
}
V_4 -> V_110 = F_31 ( & V_101 -> V_2 , L_6 ) ;
if ( F_32 ( V_4 -> V_110 ) ) {
F_6 ( & V_101 -> V_2 , L_7 ) ;
return F_33 ( V_4 -> V_110 ) ;
}
V_6 = F_5 ( V_4 -> V_110 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_2 , L_8 , V_6 ) ;
return V_6 ;
}
V_4 -> V_5 = F_31 ( & V_101 -> V_2 , L_9 ) ;
if ( F_32 ( V_4 -> V_5 ) ) {
F_6 ( & V_101 -> V_2 , L_10 ) ;
return F_33 ( V_4 -> V_5 ) ;
}
V_106 = F_34 ( V_101 , V_111 , 0 ) ;
V_107 = F_35 ( & V_101 -> V_2 , V_106 ) ;
if ( F_32 ( V_107 ) )
return F_33 ( V_107 ) ;
V_4 -> V_12 = F_36 ( & V_101 -> V_2 , V_107 ,
& V_112 ) ;
if ( F_32 ( V_4 -> V_12 ) ) {
F_6 ( & V_101 -> V_2 ,
L_11 ) ;
return F_33 ( V_4 -> V_12 ) ;
}
V_4 -> V_93 . V_113 = V_106 -> V_114 + V_96 ;
V_4 -> V_93 . V_115 = V_116 ;
V_4 -> V_93 . V_117 = 4 ;
V_4 -> V_92 . V_113 = V_106 -> V_114 + V_97 ;
V_4 -> V_92 . V_115 = V_116 ;
V_4 -> V_92 . V_117 = 4 ;
V_4 -> V_2 = & V_101 -> V_2 ;
F_37 ( & V_101 -> V_2 , V_4 ) ;
F_38 ( & V_101 -> V_2 ) ;
if ( ! F_39 ( & V_101 -> V_2 ) ) {
V_6 = F_4 ( & V_101 -> V_2 ) ;
if ( V_6 )
goto V_118;
}
if ( ! F_40 ( V_103 , L_12 , & V_10 ) ) {
if ( V_10 >= 2 && V_10 <= 8 )
V_119 . V_120 . V_121 = V_10 ;
else
V_119 . V_120 . V_121 = 2 ;
}
V_6 = F_41 ( & V_101 -> V_2 ,
& V_122 ,
& V_119 , 1 ) ;
if ( V_6 ) {
F_6 ( & V_101 -> V_2 , L_13 ) ;
goto V_123;
}
V_6 = F_42 ( & V_101 -> V_2 , NULL , 0 ) ;
if ( V_6 ) {
F_6 ( & V_101 -> V_2 , L_14 ) ;
return V_6 ;
}
return 0 ;
V_123:
if ( ! F_43 ( & V_101 -> V_2 ) )
F_1 ( & V_101 -> V_2 ) ;
V_118:
F_44 ( & V_101 -> V_2 ) ;
return V_6 ;
}
static int F_45 ( struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( & V_101 -> V_2 ) ;
F_44 ( & V_101 -> V_2 ) ;
if ( ! F_43 ( & V_101 -> V_2 ) )
F_1 ( & V_101 -> V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_110 ) ;
return 0 ;
}
