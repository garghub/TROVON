void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 , V_8 = 0 ;
bool V_9 = false ;
if ( V_4 -> V_10 != V_6 -> V_11 ) {
V_9 = true ;
V_4 -> V_10 = V_6 -> V_11 ;
}
if ( V_6 -> V_11 ) {
if ( V_4 -> V_12 != V_6 -> V_13 ) {
V_9 = true ;
V_4 -> V_12 = V_6 -> V_13 ;
}
if ( V_4 -> V_14 != V_6 -> V_15 ) {
V_9 = true ;
V_4 -> V_14 = V_6 -> V_15 ;
}
if ( V_4 -> V_16 != V_6 -> V_17 ) {
V_9 = true ;
V_4 -> V_16 = V_6 -> V_17 ;
}
if ( ! V_9 )
return;
if ( V_6 -> V_13 == V_18 )
V_8 = V_19 ;
else if ( V_6 -> V_13 == V_20 )
V_8 = V_21 ;
else
V_8 = V_22 ;
V_8 <<= V_23 ;
if ( V_6 -> V_15 != V_24 )
V_8 |= V_25 ;
if ( ! V_6 -> V_17 )
V_8 |= V_26 | V_27 ;
V_7 = F_3 ( V_4 , V_28 ) ;
V_7 &= ~ V_29 ;
V_7 |= V_30 ;
F_4 ( V_4 , V_7 , V_28 ) ;
V_7 = F_5 ( V_4 , V_31 ) ;
V_7 &= ~ ( ( V_32 << V_23 ) |
V_25 |
V_26 | V_27 ) ;
V_7 |= V_8 ;
F_6 ( V_4 , V_7 , V_31 ) ;
} else {
if ( ! V_9 )
return;
F_7 ( V_2 ) ;
}
F_8 ( V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
if ( V_2 && V_2 -> V_6 && V_34 )
V_34 -> V_11 = V_2 -> V_6 -> V_11 ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_11 ( V_4 ) )
return;
if ( V_4 -> V_6 ) {
F_12 ( V_4 -> V_6 ) ;
F_13 ( V_4 -> V_6 ) ;
}
}
void F_14 ( struct V_1 * V_2 , bool V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = 0 ;
if ( F_11 ( V_4 ) ) {
V_7 = F_3 ( V_4 , V_36 ) ;
if ( V_35 ) {
V_7 &= ~ V_37 ;
F_4 ( V_4 , V_7 , V_36 ) ;
F_15 ( 1 ) ;
V_7 &= ~ ( V_38 | V_39 ) ;
V_7 |= V_40 ;
F_4 ( V_4 , V_7 , V_36 ) ;
F_15 ( 1 ) ;
V_7 &= ~ V_40 ;
} else {
V_7 |= V_38 | V_39 |
V_40 ;
F_4 ( V_4 , V_7 , V_36 ) ;
F_15 ( 1 ) ;
V_7 |= V_37 ;
}
F_4 ( V_4 , V_7 , V_36 ) ;
F_16 ( 60 ) ;
} else {
F_15 ( 1 ) ;
}
}
static void F_17 ( struct V_3 * V_4 )
{
T_1 V_7 ;
if ( ! F_18 ( V_4 ) ) {
V_7 = F_19 ( V_4 , V_41 ) ;
V_7 |= V_42 ;
F_20 ( V_4 , V_7 , V_41 ) ;
}
if ( V_4 -> V_43 -> V_44 & V_45 )
F_21 ( V_4 -> V_6 ,
F_9 ) ;
}
int F_22 ( struct V_1 * V_2 , bool V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_47 * V_48 = & V_4 -> V_49 -> V_2 ;
const char * V_50 = NULL ;
T_1 V_51 = 0 ;
T_1 V_52 ;
T_1 V_7 ;
V_4 -> V_53 = ! V_4 -> V_54 &&
( V_4 -> V_55 != V_56 ) ;
switch ( V_4 -> V_55 ) {
case V_57 :
case V_56 :
if ( F_11 ( V_4 ) )
V_52 = V_58 ;
else
V_52 = V_59 ;
F_20 ( V_4 , V_52 , V_41 ) ;
if ( V_4 -> V_54 ) {
V_50 = L_1 ;
} else if ( V_4 -> V_55 == V_56 ) {
V_50 = L_2 ;
F_17 ( V_4 ) ;
}
break;
case V_60 :
V_50 = L_3 ;
V_6 -> V_61 &= V_62 ;
F_20 ( V_4 ,
V_63 , V_41 ) ;
break;
case V_64 :
V_50 = L_4 ;
if ( ( V_4 -> V_6 -> V_61 & V_62 ) ==
V_62 )
V_52 = V_65 ;
else
V_52 = V_66 ;
F_20 ( V_4 , V_52 , V_41 ) ;
break;
case V_67 :
V_51 = F_23 ( 16 ) ;
case V_68 :
if ( V_51 )
V_50 = L_5 ;
else
V_50 = L_6 ;
F_20 ( V_4 ,
V_69 , V_41 ) ;
break;
default:
F_24 ( V_48 , L_7 , V_4 -> V_55 ) ;
return - V_70 ;
}
if ( V_4 -> V_53 ) {
V_7 = F_3 ( V_4 , V_28 ) ;
V_7 |= V_71 | V_51 ;
F_4 ( V_4 , V_7 , V_28 ) ;
}
if ( V_46 )
F_25 ( V_48 , L_8 , V_50 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_73 = V_4 -> V_49 -> V_2 . V_74 ;
struct V_5 * V_6 ;
T_1 V_75 ;
int V_76 ;
V_75 = V_4 -> V_77 ;
V_4 -> V_10 = - 1 ;
V_4 -> V_12 = - 1 ;
V_4 -> V_14 = - 1 ;
V_4 -> V_16 = - 1 ;
if ( V_73 ) {
V_6 = F_27 ( V_2 , V_4 -> V_78 , F_1 ,
V_75 , V_4 -> V_55 ) ;
if ( ! V_6 ) {
F_28 ( L_9 ) ;
return - V_79 ;
}
} else {
V_6 = V_4 -> V_6 ;
V_6 -> V_80 = V_75 ;
V_76 = F_29 ( V_2 , V_6 , F_1 ,
V_4 -> V_55 ) ;
if ( V_76 ) {
F_28 ( L_9 ) ;
return - V_79 ;
}
}
V_4 -> V_6 = V_6 ;
V_76 = F_22 ( V_2 , true ) ;
if ( V_76 ) {
F_30 ( V_4 -> V_6 ) ;
return V_76 ;
}
V_6 -> V_81 = V_6 -> V_61 ;
if ( V_4 -> V_54 )
V_4 -> V_6 -> V_82 = V_83 ;
return 0 ;
}
static struct V_72 * F_31 ( struct V_3 * V_4 )
{
struct V_72 * V_73 = V_4 -> V_49 -> V_2 . V_74 ;
struct V_47 * V_48 = & V_4 -> V_49 -> V_2 ;
char * V_84 ;
V_84 = F_32 ( V_85 , L_10 , V_4 -> V_86 ) ;
if ( ! V_84 )
return NULL ;
V_4 -> V_87 = F_33 ( V_73 , NULL , V_84 ) ;
F_34 ( V_84 ) ;
if ( ! V_4 -> V_87 ) {
F_24 ( V_48 , L_11 ) ;
return NULL ;
}
return V_4 -> V_87 ;
}
static void F_35 ( struct V_3 * V_4 ,
struct V_88 * V_89 )
{
struct V_47 * V_48 = & V_4 -> V_49 -> V_2 ;
struct V_90 * V_91 = V_48 -> V_92 ;
if ( V_91 -> V_55 != V_56 && V_91 -> V_93 ) {
if ( V_91 -> V_94 >= 0 && V_91 -> V_94 < V_95 )
V_89 -> V_96 = 1 << V_91 -> V_94 ;
else
V_89 -> V_96 = 0 ;
}
}
static int F_36 ( void * V_97 )
{
struct V_3 * V_4 = V_97 ;
F_37 ( V_4 -> V_98 ,
! ( F_5 ( V_4 , V_99 )
& V_100 ) ,
V_101 / 100 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_102 * V_49 = V_4 -> V_49 ;
struct V_90 * V_103 = V_49 -> V_2 . V_92 ;
struct V_72 * V_73 = V_49 -> V_2 . V_74 ;
struct V_88 V_89 ;
struct V_102 * V_104 ;
struct V_105 * V_106 , V_107 ;
int V_108 , V_76 ;
V_106 = F_39 ( V_49 , V_109 , 0 ) ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_110 = F_36 ;
V_89 . V_97 = V_4 ;
V_89 . V_111 = L_12 ;
V_107 . V_112 = V_106 -> V_112 + V_113 + V_99 ;
V_107 . V_114 = V_107 . V_112 + 8 ;
V_107 . V_44 = V_109 ;
if ( V_73 )
V_108 = F_40 ( V_73 , L_13 ) ;
else
V_108 = V_49 -> V_108 ;
V_104 = F_41 ( V_115 , V_108 ) ;
if ( ! V_104 )
return - V_116 ;
V_4 -> V_117 = V_104 ;
V_104 -> V_2 . V_118 = & V_49 -> V_2 ;
V_104 -> V_2 . V_74 = F_31 ( V_4 ) ;
if ( V_103 )
F_35 ( V_4 , & V_89 ) ;
V_76 = F_42 ( V_104 , & V_107 , 1 ) ;
if ( V_76 )
goto V_119;
V_76 = F_43 ( V_104 , & V_89 , sizeof( V_89 ) ) ;
if ( V_76 )
goto V_119;
V_76 = F_44 ( V_104 ) ;
if ( V_76 )
goto V_119;
return 0 ;
V_119:
F_45 ( V_104 ) ;
return V_76 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_72 * V_73 = V_4 -> V_49 -> V_2 . V_74 ;
struct V_47 * V_48 = & V_4 -> V_49 -> V_2 ;
struct V_5 * V_6 ;
int V_120 ;
int V_76 ;
V_4 -> V_78 = F_47 ( V_73 , L_14 , 0 ) ;
if ( ! V_4 -> V_78 && F_48 ( V_73 ) ) {
V_76 = F_49 ( V_73 ) ;
if ( V_76 )
return V_76 ;
V_4 -> V_78 = F_50 ( V_73 ) ;
}
V_120 = F_51 ( V_73 ) ;
if ( V_120 < 0 ) {
F_24 ( V_48 , L_15 ) ;
return V_120 ;
}
V_4 -> V_55 = V_120 ;
if ( V_4 -> V_55 == V_57 )
V_4 -> V_54 = true ;
if ( V_120 == V_56 ) {
V_6 = F_52 ( V_73 ) ;
if ( V_6 ) {
V_6 -> V_11 = 0 ;
F_53 ( & V_6 -> V_121 . V_2 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_47 * V_48 = & V_4 -> V_49 -> V_2 ;
struct V_90 * V_91 = V_48 -> V_92 ;
char V_50 [ V_122 + 3 ] ;
char V_123 [ V_122 ] ;
struct V_5 * V_6 ;
snprintf ( V_123 , V_122 , L_16 ,
V_115 , V_4 -> V_49 -> V_108 ) ;
if ( V_91 -> V_55 != V_56 && V_91 -> V_93 ) {
snprintf ( V_50 , V_122 , V_124 ,
V_123 , V_91 -> V_94 ) ;
V_6 = F_55 ( V_4 -> V_2 , V_50 , V_91 -> V_55 ) ;
if ( ! V_6 ) {
F_24 ( V_48 , L_17 ) ;
return - V_79 ;
}
} else {
struct V_33 V_125 = {
. V_11 = 1 ,
. V_13 = V_91 -> V_126 ,
. V_15 = V_91 -> V_127 ,
. V_17 = 0 ,
. V_128 = 0 ,
} ;
V_6 = F_56 ( V_129 , & V_125 , - 1 , NULL ) ;
if ( ! V_6 || F_57 ( V_6 ) ) {
F_24 ( V_48 , L_18 ) ;
return - V_79 ;
}
V_6 -> V_11 = 0 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_55 = V_91 -> V_55 ;
return 0 ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_72 * V_73 = V_4 -> V_49 -> V_2 . V_74 ;
if ( V_73 )
return F_46 ( V_4 ) ;
else
return F_54 ( V_4 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_76 ;
V_76 = F_38 ( V_4 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_58 ( V_4 ) ;
if ( V_76 )
goto V_119;
return 0 ;
V_119:
F_60 ( V_2 ) ;
return V_76 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_72 * V_73 = V_4 -> V_49 -> V_2 . V_74 ;
if ( F_48 ( V_73 ) )
F_61 ( V_73 ) ;
F_62 ( V_4 -> V_78 ) ;
F_63 ( V_4 -> V_117 ) ;
F_45 ( V_4 -> V_117 ) ;
}
