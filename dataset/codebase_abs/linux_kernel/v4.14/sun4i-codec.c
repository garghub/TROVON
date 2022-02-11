static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_5 ) ,
F_3 ( V_5 ) ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_6 ) ,
F_3 ( V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_6 ) ,
0 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_7 ,
F_3 ( V_8 ) ,
F_3 ( V_8 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_7 ,
F_3 ( V_8 ) , 0 ) ;
}
static int F_8 ( struct V_9 * V_10 , int V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 ;
struct V_1 * V_2 = F_9 ( V_15 -> V_17 ) ;
switch ( V_11 ) {
case V_18 :
case V_19 :
case V_20 :
if ( V_10 -> V_21 == V_22 )
F_1 ( V_2 ) ;
else
F_5 ( V_2 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
if ( V_10 -> V_21 == V_22 )
F_4 ( V_2 ) ;
else
F_7 ( V_2 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 ;
struct V_1 * V_2 = F_9 ( V_15 -> V_17 ) ;
F_6 ( V_2 -> V_7 ,
F_3 ( V_27 ) ,
F_3 ( V_27 ) ) ;
F_6 ( V_2 -> V_7 ,
0xf << V_28 ,
0x7 << V_28 ) ;
if ( F_11 ( V_2 -> V_29 -> V_30 ,
L_1 ) ||
F_11 ( V_2 -> V_29 -> V_30 ,
L_2 ) ) {
F_2 ( V_2 -> V_3 , V_31 ,
0x3 << 25 ,
0x1 << 25 ) ;
}
if ( F_11 ( V_2 -> V_29 -> V_30 ,
L_2 ) )
F_2 ( V_2 -> V_3 , V_32 ,
0x3 << 8 ,
0x1 << 8 ) ;
F_6 ( V_2 -> V_7 ,
F_3 ( V_33 ) ,
F_3 ( V_33 ) ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 ;
struct V_1 * V_2 = F_9 ( V_15 -> V_17 ) ;
T_1 V_34 ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_5 ) ,
F_3 ( V_5 ) ) ;
F_2 ( V_2 -> V_3 , V_4 ,
0x3f << V_35 ,
0xf << V_35 ) ;
if ( V_10 -> V_36 -> V_37 > 32000 )
V_34 = 0 ;
else
V_34 = F_3 ( V_38 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_38 ) ,
V_34 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_39 ) ,
0 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_12 * V_13 )
{
if ( V_10 -> V_21 == V_22 )
return F_12 ( V_10 , V_13 ) ;
return F_10 ( V_10 , V_13 ) ;
}
static unsigned long F_14 ( struct V_40 * V_41 )
{
unsigned int V_37 = F_15 ( V_41 ) ;
switch ( V_37 ) {
case 176400 :
case 88200 :
case 44100 :
case 33075 :
case 22050 :
case 14700 :
case 11025 :
case 7350 :
return 22579200 ;
case 192000 :
case 96000 :
case 48000 :
case 32000 :
case 24000 :
case 16000 :
case 12000 :
case 8000 :
return 24576000 ;
default:
return 0 ;
}
}
static int F_16 ( struct V_40 * V_41 )
{
unsigned int V_37 = F_15 ( V_41 ) ;
switch ( V_37 ) {
case 192000 :
case 176400 :
return 6 ;
case 96000 :
case 88200 :
return 7 ;
case 48000 :
case 44100 :
return 0 ;
case 32000 :
case 33075 :
return 1 ;
case 24000 :
case 22050 :
return 2 ;
case 16000 :
case 14700 :
return 3 ;
case 12000 :
case 11025 :
return 4 ;
case 8000 :
case 7350 :
return 5 ;
default:
return - V_26 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
unsigned int V_42 )
{
F_6 ( V_2 -> V_7 ,
7 << V_43 ,
V_42 << V_43 ) ;
if ( F_18 ( V_41 ) == 1 )
F_6 ( V_2 -> V_7 ,
F_3 ( V_44 ) ,
F_3 ( V_44 ) ) ;
else
F_6 ( V_2 -> V_7 ,
F_3 ( V_44 ) ,
0 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
unsigned int V_42 )
{
T_1 V_34 ;
F_2 ( V_2 -> V_3 , V_4 ,
7 << V_45 ,
V_42 << V_45 ) ;
if ( F_18 ( V_41 ) == 1 )
V_34 = F_3 ( V_46 ) ;
else
V_34 = 0 ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_46 ) ,
V_34 ) ;
if ( F_20 ( V_41 , V_47 ) -> V_48 == 32 ) {
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_49 ) ,
F_3 ( V_49 ) ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_50 ) ,
0 ) ;
V_2 -> V_51 . V_52 = V_53 ;
} else {
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_49 ) ,
0 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_50 ) ,
F_3 ( V_50 ) ) ;
V_2 -> V_51 . V_52 = V_54 ;
}
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_40 * V_41 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 ;
struct V_1 * V_2 = F_9 ( V_15 -> V_17 ) ;
unsigned long V_55 ;
int V_56 , V_42 ;
V_55 = F_14 ( V_41 ) ;
if ( ! V_55 )
return - V_26 ;
V_56 = F_22 ( V_2 -> V_57 , V_55 ) ;
if ( V_56 )
return V_56 ;
V_42 = F_16 ( V_41 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_10 -> V_21 == V_22 )
return F_19 ( V_2 , V_41 ,
V_42 ) ;
return F_17 ( V_2 , V_41 ,
V_42 ) ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 ;
struct V_1 * V_2 = F_9 ( V_15 -> V_17 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
3 << V_58 ,
3 << V_58 ) ;
return F_24 ( V_2 -> V_57 ) ;
}
static void F_25 ( struct V_9 * V_10 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 ;
struct V_1 * V_2 = F_9 ( V_15 -> V_17 ) ;
F_26 ( V_2 -> V_57 ) ;
}
static int F_27 ( struct V_12 * V_13 )
{
struct V_59 * V_17 = F_28 ( V_13 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_29 ( V_13 , & V_2 -> V_51 ,
& V_2 -> V_60 ) ;
return 0 ;
}
static struct V_61 * F_30 ( struct V_62 * V_29 ,
int * V_63 )
{
struct V_61 * V_64 = F_31 ( V_29 , sizeof( * V_64 ) ,
V_65 ) ;
if ( ! V_64 )
return NULL ;
V_64 -> V_66 = L_3 ;
V_64 -> V_67 = L_4 ;
V_64 -> V_68 = L_5 ;
V_64 -> V_69 = F_32 ( V_29 ) ;
V_64 -> V_70 = F_32 ( V_29 ) ;
V_64 -> V_71 = F_32 ( V_29 ) ;
V_64 -> V_72 = V_73 ;
* V_63 = 1 ;
return V_64 ;
}
static int F_33 ( struct V_74 * V_75 ,
struct V_76 * V_77 , int V_78 )
{
struct V_1 * V_2 = F_9 ( V_75 -> V_79 -> V_17 ) ;
F_34 ( V_2 -> V_80 ,
! ! F_35 ( V_78 ) ) ;
return 0 ;
}
static struct V_59 * F_36 ( struct V_62 * V_29 )
{
struct V_59 * V_17 ;
V_17 = F_31 ( V_29 , sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return F_37 ( - V_81 ) ;
V_17 -> V_82 = F_30 ( V_29 , & V_17 -> V_63 ) ;
if ( ! V_17 -> V_82 )
return F_37 ( - V_81 ) ;
V_17 -> V_29 = V_29 ;
V_17 -> V_66 = L_6 ;
V_17 -> V_83 = V_84 ;
V_17 -> V_85 = F_38 ( V_84 ) ;
V_17 -> V_86 = V_87 ;
V_17 -> V_88 = F_38 ( V_87 ) ;
return V_17 ;
}
static struct V_59 * F_39 ( struct V_62 * V_29 )
{
struct V_59 * V_17 ;
int V_56 ;
V_17 = F_31 ( V_29 , sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return F_37 ( - V_81 ) ;
V_17 -> V_82 = F_30 ( V_29 , & V_17 -> V_63 ) ;
if ( ! V_17 -> V_82 )
return F_37 ( - V_81 ) ;
V_17 -> V_29 = V_29 ;
V_17 -> V_66 = L_7 ;
V_17 -> V_83 = V_89 ;
V_17 -> V_85 = F_38 ( V_89 ) ;
V_17 -> V_90 = true ;
V_56 = F_40 ( V_17 , L_8 ) ;
if ( V_56 )
F_41 ( V_29 , L_9 , V_56 ) ;
return V_17 ;
}
static struct V_59 * F_42 ( struct V_62 * V_29 )
{
struct V_59 * V_17 ;
int V_56 ;
V_17 = F_31 ( V_29 , sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return F_37 ( - V_81 ) ;
V_91 . V_92 = F_43 ( V_29 -> V_30 ,
L_10 ,
0 ) ;
if ( ! V_91 . V_92 ) {
F_44 ( V_29 , L_11 ) ;
return F_37 ( - V_26 ) ;
} ;
V_17 -> V_82 = F_30 ( V_29 , & V_17 -> V_63 ) ;
if ( ! V_17 -> V_82 )
return F_37 ( - V_81 ) ;
V_17 -> V_29 = V_29 ;
V_17 -> V_66 = L_12 ;
V_17 -> V_83 = V_89 ;
V_17 -> V_85 = F_38 ( V_89 ) ;
V_17 -> V_86 = V_93 ;
V_17 -> V_88 = F_38 ( V_93 ) ;
V_17 -> V_91 = & V_91 ;
V_17 -> V_94 = 1 ;
V_17 -> V_90 = true ;
V_56 = F_40 ( V_17 , L_8 ) ;
if ( V_56 )
F_41 ( V_29 , L_9 , V_56 ) ;
return V_17 ;
}
static struct V_59 * F_45 ( struct V_62 * V_29 )
{
struct V_59 * V_17 ;
int V_56 ;
V_17 = F_31 ( V_29 , sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return F_37 ( - V_81 ) ;
V_91 . V_92 = F_43 ( V_29 -> V_30 ,
L_10 ,
0 ) ;
if ( ! V_91 . V_92 ) {
F_44 ( V_29 , L_11 ) ;
return F_37 ( - V_26 ) ;
} ;
V_17 -> V_82 = F_30 ( V_29 , & V_17 -> V_63 ) ;
if ( ! V_17 -> V_82 )
return F_37 ( - V_81 ) ;
V_17 -> V_29 = V_29 ;
V_17 -> V_66 = L_13 ;
V_17 -> V_83 = V_89 ;
V_17 -> V_85 = F_38 ( V_89 ) ;
V_17 -> V_86 = V_93 ;
V_17 -> V_88 = F_38 ( V_93 ) ;
V_17 -> V_91 = & V_91 ;
V_17 -> V_94 = 1 ;
V_17 -> V_90 = true ;
V_56 = F_40 ( V_17 , L_8 ) ;
if ( V_56 )
F_41 ( V_29 , L_9 , V_56 ) ;
return V_17 ;
}
static struct V_59 * F_46 ( struct V_62 * V_29 )
{
struct V_59 * V_17 ;
int V_56 ;
V_17 = F_31 ( V_29 , sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return F_37 ( - V_81 ) ;
V_91 . V_92 = F_43 ( V_29 -> V_30 ,
L_10 ,
0 ) ;
if ( ! V_91 . V_92 ) {
F_44 ( V_29 , L_11 ) ;
return F_37 ( - V_26 ) ;
} ;
V_17 -> V_82 = F_30 ( V_29 , & V_17 -> V_63 ) ;
if ( ! V_17 -> V_82 )
return F_37 ( - V_81 ) ;
V_17 -> V_29 = V_29 ;
V_17 -> V_66 = L_14 ;
V_17 -> V_83 = V_89 ;
V_17 -> V_85 = F_38 ( V_89 ) ;
V_17 -> V_86 = V_93 ;
V_17 -> V_88 = F_38 ( V_93 ) ;
V_17 -> V_91 = & V_91 ;
V_17 -> V_94 = 1 ;
V_17 -> V_90 = true ;
V_56 = F_40 ( V_17 , L_8 ) ;
if ( V_56 )
F_41 ( V_29 , L_9 , V_56 ) ;
return V_17 ;
}
static int F_47 ( struct V_95 * V_96 )
{
struct V_59 * V_17 ;
struct V_1 * V_2 ;
const struct V_97 * V_98 ;
struct V_99 * V_100 ;
void T_2 * V_101 ;
int V_56 ;
V_2 = F_31 ( & V_96 -> V_29 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_29 = & V_96 -> V_29 ;
V_100 = F_48 ( V_96 , V_102 , 0 ) ;
V_101 = F_49 ( & V_96 -> V_29 , V_100 ) ;
if ( F_50 ( V_101 ) ) {
F_44 ( & V_96 -> V_29 , L_15 ) ;
return F_51 ( V_101 ) ;
}
V_98 = F_52 ( & V_96 -> V_29 ) ;
if ( V_98 == NULL ) {
F_44 ( & V_96 -> V_29 , L_16 ) ;
return - V_103 ;
}
V_2 -> V_3 = F_53 ( & V_96 -> V_29 , V_101 ,
V_98 -> V_104 ) ;
if ( F_50 ( V_2 -> V_3 ) ) {
F_44 ( & V_96 -> V_29 , L_17 ) ;
return F_51 ( V_2 -> V_3 ) ;
}
V_2 -> V_105 = F_54 ( & V_96 -> V_29 , L_18 ) ;
if ( F_50 ( V_2 -> V_105 ) ) {
F_44 ( & V_96 -> V_29 , L_19 ) ;
return F_51 ( V_2 -> V_105 ) ;
}
V_2 -> V_57 = F_54 ( & V_96 -> V_29 , L_20 ) ;
if ( F_50 ( V_2 -> V_57 ) ) {
F_44 ( & V_96 -> V_29 , L_21 ) ;
return F_51 ( V_2 -> V_57 ) ;
}
if ( V_98 -> V_106 ) {
V_2 -> V_107 = F_55 ( & V_96 -> V_29 ,
NULL ) ;
if ( F_50 ( V_2 -> V_107 ) ) {
F_44 ( & V_96 -> V_29 , L_22 ) ;
return F_51 ( V_2 -> V_107 ) ;
}
}
V_2 -> V_80 = F_56 ( & V_96 -> V_29 , L_23 ,
V_108 ) ;
if ( F_50 ( V_2 -> V_80 ) ) {
V_56 = F_51 ( V_2 -> V_80 ) ;
if ( V_56 != - V_109 )
F_44 ( & V_96 -> V_29 , L_24 , V_56 ) ;
return V_56 ;
}
V_2 -> V_7 = F_57 ( & V_96 -> V_29 ,
V_2 -> V_3 ,
V_98 -> V_7 ) ;
if ( F_50 ( V_2 -> V_7 ) ) {
V_56 = F_51 ( V_2 -> V_7 ) ;
F_44 ( & V_96 -> V_29 , L_25 ,
V_56 ) ;
return V_56 ;
}
if ( F_24 ( V_2 -> V_105 ) ) {
F_44 ( & V_96 -> V_29 , L_26 ) ;
return - V_26 ;
}
if ( V_2 -> V_107 ) {
V_56 = F_58 ( V_2 -> V_107 ) ;
if ( V_56 ) {
F_44 ( & V_96 -> V_29 ,
L_27 ) ;
goto V_110;
}
}
V_2 -> V_51 . V_111 = V_100 -> V_112 + V_98 -> V_113 ;
V_2 -> V_51 . V_114 = 8 ;
V_2 -> V_51 . V_52 = V_54 ;
V_2 -> V_60 . V_111 = V_100 -> V_112 + V_98 -> V_115 ;
V_2 -> V_60 . V_114 = 8 ;
V_2 -> V_60 . V_52 = V_54 ;
V_56 = F_59 ( & V_96 -> V_29 , V_98 -> V_116 ,
& V_117 , 1 ) ;
if ( V_56 ) {
F_44 ( & V_96 -> V_29 , L_28 ) ;
goto V_118;
}
V_56 = F_60 ( & V_96 -> V_29 ,
& V_119 ,
& V_120 , 1 ) ;
if ( V_56 ) {
F_44 ( & V_96 -> V_29 , L_29 ) ;
goto V_121;
}
V_56 = F_61 ( & V_96 -> V_29 , NULL , 0 ) ;
if ( V_56 ) {
F_44 ( & V_96 -> V_29 , L_30 ) ;
goto V_121;
}
V_17 = V_98 -> V_122 ( & V_96 -> V_29 ) ;
if ( F_50 ( V_17 ) ) {
V_56 = F_51 ( V_17 ) ;
F_44 ( & V_96 -> V_29 , L_31 ) ;
goto V_121;
}
F_62 ( V_17 , V_2 ) ;
V_56 = F_63 ( V_17 ) ;
if ( V_56 ) {
F_44 ( & V_96 -> V_29 , L_32 ) ;
goto V_121;
}
return 0 ;
V_121:
F_64 ( & V_96 -> V_29 ) ;
V_118:
if ( V_2 -> V_107 )
F_65 ( V_2 -> V_107 ) ;
V_110:
F_26 ( V_2 -> V_105 ) ;
return V_56 ;
}
static int F_66 ( struct V_95 * V_96 )
{
struct V_59 * V_17 = F_67 ( V_96 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_68 ( V_17 ) ;
F_64 ( & V_96 -> V_29 ) ;
if ( V_2 -> V_107 )
F_65 ( V_2 -> V_107 ) ;
F_26 ( V_2 -> V_105 ) ;
return 0 ;
}
