static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_5 [ V_3 / sizeof( T_2 ) ] = V_4 ;
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 , bool V_7 )
{
return ! V_7 ? F_4 ( V_2 -> V_6 + V_3 ) :
V_2 -> V_5 [ V_3 / sizeof( T_2 ) ] ;
}
static int F_5 ( struct V_8 * V_9 , unsigned int * V_10 ,
unsigned int * V_11 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
int V_15 = F_6 ( V_13 -> V_16 ,
V_13 -> V_17 -> V_18 ) ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
if ( V_15 < 0 )
return V_15 ;
* V_11 = V_15 * V_13 -> V_24 ;
if ( ! * V_10 || * V_10 < F_8 ( V_2 -> V_25 ) )
* V_10 = F_8 ( V_2 -> V_25 ) ;
if ( * V_11 * * V_10 > V_26 * 1024 * 1024 )
* V_10 = ( V_26 * 1024 * 1024 ) / * V_11 ;
F_9 ( V_13 -> V_21 . V_22 ,
L_1 , V_27 , * V_10 , * V_11 ) ;
return 0 ;
}
static void F_10 ( struct V_8 * V_9 , struct V_28 * V_29 ,
enum V_30 V_25 )
{
struct V_31 * V_32 = & V_29 -> V_32 ;
F_11 ( F_12 () ) ;
F_13 ( V_9 , V_32 , 0 , 0 ) ;
if ( V_25 == V_33 ) {
F_14 ( V_9 , V_32 ) ;
} else {
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_34 * V_21 = V_13 -> V_21 . V_22 ;
struct V_35 * V_36 = F_15 ( V_32 ) ;
F_16 ( V_21 , V_36 ) ;
F_17 ( V_36 ) ;
}
V_32 -> V_37 = V_38 ;
}
static int F_18 ( struct V_8 * V_9 ,
struct V_31 * V_32 , enum V_39 V_40 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_28 * V_29 = F_19 ( V_32 , struct V_28 , V_32 ) ;
int V_15 = F_6 ( V_13 -> V_16 ,
V_13 -> V_17 -> V_18 ) ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
int V_41 ;
if ( V_15 < 0 )
return V_15 ;
F_20 ( ! F_21 ( & V_32 -> V_42 ) ) ;
F_11 ( NULL == V_13 -> V_17 ) ;
V_29 -> V_43 = 1 ;
if ( V_29 -> V_44 != V_13 -> V_17 -> V_44 || V_32 -> V_40 != V_40 ||
V_32 -> V_45 != V_13 -> V_16 ||
V_32 -> V_46 != V_13 -> V_24 ) {
V_29 -> V_44 = V_13 -> V_17 -> V_44 ;
V_32 -> V_45 = V_13 -> V_16 ;
V_32 -> V_46 = V_13 -> V_24 ;
V_32 -> V_40 = V_40 ;
V_32 -> V_37 = V_38 ;
}
V_32 -> V_11 = V_15 * V_32 -> V_46 ;
if ( V_32 -> V_47 && V_32 -> V_48 < V_32 -> V_11 ) {
V_41 = - V_49 ;
goto V_50;
}
if ( V_32 -> V_37 == V_38 ) {
V_41 = F_22 ( V_9 , V_32 , NULL ) ;
if ( V_41 )
goto V_51;
V_32 -> V_37 = V_52 ;
}
V_29 -> V_43 = 0 ;
return 0 ;
V_51:
F_10 ( V_9 , V_29 , V_2 -> V_25 ) ;
V_50:
V_29 -> V_43 = 0 ;
return V_41 ;
}
static void F_23 ( int V_53 , struct V_28 * V_29 ,
enum V_30 V_25 )
{
T_3 V_54 ;
unsigned int V_55 ;
if ( V_25 == V_33 ) {
V_54 = F_24 ( & V_29 -> V_32 ) ;
V_55 = V_29 -> V_32 . V_11 ;
} else {
if ( F_20 ( ! V_29 -> V_56 ) ) {
V_29 -> V_57 = V_58 ;
return;
}
V_54 = F_25 ( V_29 -> V_56 ) ;
if ( F_20 ( ! V_54 ) ) {
V_29 -> V_56 = NULL ;
V_29 -> V_57 = V_58 ;
return;
}
V_55 = F_26 ( V_29 -> V_56 ) ;
if ( F_20 ( ! V_55 ) ) {
V_29 -> V_56 = NULL ;
V_29 -> V_57 = V_58 ;
return;
}
if ( F_27 ( V_29 -> V_59 < V_55 ) )
V_55 = V_29 -> V_59 ;
if ( F_20 ( V_54 & ( F_28 ( V_25 ) *
V_60 - 1 ) ) ) {
V_54 = F_29 ( V_54 , F_28 ( V_25 ) *
V_60 ) ;
V_55 &= ~ ( F_28 ( V_25 ) *
V_60 - 1 ) ;
}
V_29 -> V_59 -= V_55 ;
V_29 -> V_61 ++ ;
}
F_30 ( V_53 ,
V_62 , V_63 , V_54 , 0 , 0 ) ;
F_31 ( V_53 ,
V_64 , F_28 ( V_25 ) ,
V_55 >> ( F_32 ( V_25 ) + V_65 ) ,
V_66 , 0 , 0 ) ;
}
static struct V_28 * F_33 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
V_29 = V_2 -> V_67 ;
if ( ! V_29 ) {
if ( F_21 ( & V_2 -> V_68 ) )
return V_29 ;
V_29 = F_34 ( V_2 -> V_68 . V_69 ,
struct V_28 , V_32 . V_42 ) ;
V_29 -> V_32 . V_37 = V_70 ;
V_2 -> V_67 = V_29 ;
F_35 ( & V_29 -> V_32 . V_42 ) ;
}
if ( V_2 -> V_25 == V_33 ) {
F_23 ( V_2 -> V_53 , V_29 , V_2 -> V_25 ) ;
} else {
V_29 -> V_56 = NULL ;
}
return V_29 ;
}
static struct V_71 * F_36 ( int V_53 , struct V_28 * V_29 )
{
struct V_71 * V_56 ;
if ( F_37 ( V_29 -> V_56 ) ) {
if ( F_27 ( ! V_29 -> V_59 ) ) {
V_56 = NULL ;
} else {
V_56 = F_38 ( V_29 -> V_56 ) ;
if ( F_20 ( ! V_56 ) ) {
V_29 -> V_57 = V_58 ;
} else if ( F_20 ( ! F_26 ( V_56 ) ) ) {
V_56 = NULL ;
V_29 -> V_57 = V_58 ;
}
}
V_29 -> V_56 = V_56 ;
} else {
struct V_35 * V_36 = F_15 ( & V_29 -> V_32 ) ;
V_56 = V_36 -> V_72 ;
if ( ! ( F_20 ( ! V_56 ) ) ) {
V_29 -> V_56 = V_56 ;
V_29 -> V_61 = 0 ;
V_29 -> V_59 = V_29 -> V_32 . V_11 ;
V_29 -> V_57 = V_73 ;
}
}
if ( V_56 )
F_23 ( V_53 , V_29 , V_74 ) ;
return V_56 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_75 ;
T_2 V_76 = F_40 ( V_2 , V_77 ) ;
T_2 V_78 = F_40 ( V_2 , V_79 ) & ~ V_80 ;
if ( F_20 ( ! V_29 ) )
return;
V_78 |= V_81 ;
if ( F_27 ( V_76 & V_82 ) )
F_41 ( V_2 , V_77 , V_76 & ~ V_82 ) ;
F_41 ( V_2 , V_79 , V_78 | V_83 ) ;
F_42 ( V_2 -> V_53 ) ;
if ( V_2 -> V_25 == V_74 ) {
F_36 ( V_2 -> V_53 , V_29 ) ;
}
F_41 ( V_2 , V_77 , V_76 | V_82 ) ;
F_41 ( V_2 , V_79 , V_78 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_2 V_76 = F_40 ( V_2 , V_77 ) ;
F_41 ( V_2 , V_77 , V_76 & ~ V_82 ) ;
F_44 ( V_2 -> V_53 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_2 V_78 = F_40 ( V_2 , V_79 ) ;
F_41 ( V_2 , V_79 , V_78 & ~ ( V_84 | V_85 ) ) ;
}
static void F_46 ( struct V_8 * V_9 ,
struct V_31 * V_32 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
struct V_28 * V_29 ;
T_2 V_78 ;
F_47 ( & V_32 -> V_42 , & V_2 -> V_68 ) ;
V_32 -> V_37 = V_86 ;
if ( V_2 -> V_75 ) {
return;
}
F_20 ( V_2 -> V_67 ) ;
V_29 = F_33 ( V_2 ) ;
if ( F_20 ( ! V_29 ) )
return;
V_2 -> V_75 = V_29 ;
V_2 -> V_67 = NULL ;
F_9 ( V_13 -> V_21 . V_22 ,
L_2 , V_27 ) ;
V_78 = F_40 ( V_2 , V_79 ) & ~ V_87 ;
V_78 |= F_48 ( V_2 -> V_25 ) << V_88 ;
F_41 ( V_2 , V_79 , V_78 | V_89 | V_85 ) ;
if ( V_2 -> V_25 == V_74 ) {
F_36 ( V_2 -> V_53 , V_29 ) ;
}
F_39 ( V_2 ) ;
}
static void F_49 ( struct V_8 * V_9 ,
struct V_31 * V_32 )
{
struct V_28 * V_29 =
F_19 ( V_32 , struct V_28 , V_32 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_34 * V_21 = V_13 -> V_21 . V_22 ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
switch ( V_32 -> V_37 ) {
case V_73 :
F_9 ( V_21 , L_3 , V_27 ) ;
break;
case V_70 :
F_9 ( V_21 , L_4 , V_27 ) ;
break;
case V_86 :
F_9 ( V_21 , L_5 , V_27 ) ;
break;
case V_52 :
F_9 ( V_21 , L_6 , V_27 ) ;
break;
default:
F_9 ( V_21 , L_7 , V_27 , V_32 -> V_37 ) ;
break;
}
F_10 ( V_9 , V_29 , V_2 -> V_25 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
enum V_90 V_57 )
{
struct V_28 * V_29 = V_2 -> V_75 ;
struct V_31 * V_32 ;
struct V_34 * V_21 = V_2 -> V_13 -> V_21 . V_22 ;
if ( F_20 ( ! V_29 ) ) {
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
return;
}
if ( V_57 == V_58 )
F_43 ( V_2 ) ;
V_32 = & V_29 -> V_32 ;
if ( F_51 ( & V_32 -> V_91 ) ) {
if ( ! V_2 -> V_67 && V_57 != V_58 ) {
F_43 ( V_2 ) ;
}
V_32 -> V_37 = V_57 ;
F_52 ( & V_32 -> V_92 ) ;
if ( V_57 != V_58 )
V_32 -> V_93 ++ ;
F_53 ( & V_32 -> V_91 ) ;
V_29 = V_2 -> V_67 ;
V_2 -> V_75 = V_29 ;
V_2 -> V_67 = NULL ;
if ( ! V_29 ) {
V_57 = V_58 ;
F_33 ( V_2 ) ;
V_29 = V_2 -> V_67 ;
V_2 -> V_75 = V_29 ;
V_2 -> V_67 = NULL ;
}
} else if ( V_2 -> V_67 ) {
F_9 ( V_21 , L_8 ,
V_27 ) ;
V_2 -> V_75 = V_2 -> V_67 ;
if ( V_2 -> V_25 == V_74 ) {
V_29 -> V_56 = NULL ;
}
V_2 -> V_67 = V_29 ;
V_29 = V_2 -> V_75 ;
} else {
if ( V_2 -> V_25 == V_33 ) {
F_9 ( V_21 ,
L_9 ,
V_27 ) ;
} else {
if ( V_57 != V_58 ) {
F_43 ( V_2 ) ;
V_57 = V_58 ;
}
}
}
if ( ! V_29 ) {
F_9 ( V_21 , L_10 , V_27 ) ;
F_45 ( V_2 ) ;
return;
}
if ( V_2 -> V_25 == V_33 ) {
} else {
if ( V_57 == V_58 )
V_29 -> V_56 = NULL ;
F_36 ( V_2 -> V_53 , V_29 ) ;
}
if ( V_57 == V_58 ) {
F_9 ( V_21 , L_11 ,
V_27 ) ;
F_39 ( V_2 ) ;
}
F_33 ( V_2 ) ;
}
static void F_54 ( int V_94 , unsigned short V_95 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_28 * V_29 = V_2 -> V_75 ;
unsigned long V_97 ;
F_55 ( & V_2 -> V_98 , V_97 ) ;
if ( F_20 ( ! V_29 ) ) {
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
goto V_50;
}
if ( V_2 -> V_25 == V_33 ) {
F_41 ( V_2 , V_79 ,
F_40 ( V_2 , V_79 ) & ~ V_80 ) ;
F_50 ( V_2 , V_73 ) ;
} else {
if ( V_29 -> V_56 ) {
F_36 ( V_2 -> V_53 , V_29 ) ;
if ( V_29 -> V_56 )
goto V_50;
if ( V_29 -> V_57 != V_58 ) {
V_29 = F_33 ( V_2 ) ;
if ( ! V_29 )
goto V_50;
F_36 ( V_2 -> V_53 , V_29 ) ;
goto V_50;
}
}
F_50 ( V_2 , V_29 -> V_57 ) ;
}
V_50:
F_56 ( & V_2 -> V_98 , V_97 ) ;
}
static T_4 F_57 ( int V_99 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_34 * V_21 = V_2 -> V_13 -> V_21 . V_22 ;
struct V_28 * V_29 = V_2 -> V_75 ;
T_2 V_100 ;
unsigned long V_97 ;
V_100 = F_58 ( V_2 , V_101 ) ;
if ( ! V_100 )
return V_102 ;
F_55 ( & V_2 -> V_98 , V_97 ) ;
if ( F_20 ( ! V_29 ) ) {
F_59 ( V_21 , L_12 ,
V_27 , V_100 ) ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
goto V_50;
}
if ( F_27 ( V_100 & V_103 ) ) {
F_59 ( V_21 , L_13 , V_27 ) ;
} else if ( V_100 & V_104 ) {
if ( V_2 -> V_25 == V_33 ) {
} else {
if ( V_29 -> V_61 == 2 ) {
goto V_50;
}
}
F_60 ( V_21 , L_14 ,
V_27 ) ;
} else if ( V_100 & V_105 ) {
T_2 V_78 ;
if ( V_2 -> V_25 == V_33 ) {
V_78 = F_40 ( V_2 , V_79 ) ;
} else {
V_78 = F_40 ( V_2 , V_79 ) & ~ V_81 ;
}
if ( ! ( V_78 & V_80 ) ) {
V_78 |= V_80 ;
}
F_41 ( V_2 , V_79 , V_78 ) ;
goto V_50;
} else {
F_59 ( V_21 , L_12 ,
V_27 , V_100 ) ;
goto V_50;
}
F_50 ( V_2 , V_58 ) ;
V_50:
F_56 ( & V_2 -> V_98 , V_97 ) ;
return V_106 ;
}
static void F_61 ( struct V_1 * V_2 , bool V_107 )
{
if ( V_2 -> V_108 & V_109 )
F_41 ( V_2 , V_110 , V_107 ) ;
else if ( V_2 -> V_108 & V_111 )
F_41 ( V_2 , V_110 , ! V_107 ) ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
T_2 V_76 ;
if ( V_2 -> V_13 )
return - V_112 ;
F_63 ( V_2 -> V_113 ) ;
V_76 = F_58 ( V_2 , V_77 ) ;
V_76 &= ~ ( V_114 | V_115 | V_116 ) ;
F_41 ( V_2 , V_77 , V_76 ) ;
V_76 &= ~ V_117 ;
switch ( V_2 -> V_118 ) {
case 6000000 :
V_76 |= V_114 | V_119 ;
break;
case 8000000 :
V_76 |= V_114 | V_120 | V_116 ;
break;
case 9600000 :
V_76 |= V_114 | V_121 | V_116 ;
break;
case 12000000 :
V_76 |= V_114 | V_122 ;
break;
case 24000000 :
V_76 |= V_114 | V_123 | V_116 ;
default:
break;
}
F_41 ( V_2 , V_77 , V_76 & ~ V_116 ) ;
V_76 |= V_115 ;
F_41 ( V_2 , V_77 , V_76 ) ;
F_61 ( V_2 , false ) ;
V_2 -> V_13 = V_13 ;
F_9 ( V_13 -> V_21 . V_22 , L_15 ,
V_13 -> V_124 ) ;
return 0 ;
}
static void F_64 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
T_2 V_76 ;
F_11 ( V_13 != V_2 -> V_13 ) ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
F_61 ( V_2 , true ) ;
V_76 = F_40 ( V_2 , V_77 ) ;
V_76 &= ~ ( V_115 | V_116 | V_114 ) ;
F_41 ( V_2 , V_77 , V_76 ) ;
V_76 = ( V_76 & ~ V_117 ) | V_122 ;
F_41 ( V_2 , V_77 , V_76 ) ;
F_41 ( V_2 , V_77 , V_76 | V_115 ) ;
F_41 ( V_2 , V_77 , V_76 & ~ V_115 ) ;
F_65 ( V_2 -> V_113 ) ;
V_2 -> V_13 = NULL ;
F_9 ( V_13 -> V_21 . V_22 ,
L_16 , V_13 -> V_124 ) ;
}
static int F_66 ( struct V_12 * V_13 ,
unsigned int V_125 , struct V_126 * V_127 )
{
struct V_128 * V_129 = F_67 ( V_13 ) ;
struct V_34 * V_21 = V_13 -> V_21 . V_22 ;
int V_130 = 0 , V_41 ;
enum V_131 V_44 ;
const struct V_132 * V_133 ;
V_41 = F_68 ( V_129 , V_134 , V_135 , V_125 , & V_44 ) ;
if ( V_41 < 0 )
return 0 ;
V_133 = F_69 ( V_44 ) ;
if ( ! V_133 ) {
F_59 ( V_21 , L_17 , V_27 ,
V_125 , V_44 ) ;
return 0 ;
}
if ( V_133 -> V_136 != 8 )
return 0 ;
switch ( V_44 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_130 ++ ;
if ( V_127 ) {
V_127 -> V_18 = F_70 ( V_44 ,
V_145 ,
F_71 ( V_145 ) ) ;
V_127 -> V_44 = V_44 ;
V_127 ++ ;
F_9 ( V_21 ,
L_18 ,
V_27 , V_127 -> V_18 -> V_146 , V_44 ) ;
}
default:
if ( V_127 )
F_9 ( V_21 ,
L_19 ,
V_27 , V_133 -> V_146 ) ;
}
V_130 ++ ;
if ( V_127 ) {
V_127 -> V_18 = V_133 ;
V_127 -> V_44 = V_44 ;
V_127 ++ ;
}
return V_130 ;
}
static bool F_72 ( T_5 V_15 , unsigned int V_46 ,
enum V_30 V_25 )
{
int V_11 = V_15 * V_46 ;
return F_73 ( V_15 , V_60 ) &&
F_73 ( V_11 , F_28 ( V_25 ) * V_60 ) ;
}
static int F_74 ( int * V_45 , int * V_46 ,
const struct V_132 * V_133 ,
enum V_30 V_25 , bool V_147 )
{
T_5 V_15 = F_6 ( * V_45 , V_133 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! F_72 ( V_15 , * V_46 , V_25 ) ) {
unsigned int V_148 = F_75 ( V_15 / * V_45 ) ;
unsigned int V_149 = F_32 ( V_25 ) +
V_65 - V_148 ;
unsigned int V_150 = V_147 << V_149 ;
F_76 ( V_45 , 1 , * V_45 + V_150 , 0 ,
V_46 , 1 , * V_46 + V_150 , 0 , V_149 ) ;
return 0 ;
}
return 1 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_34 * V_21 ,
struct V_12 * V_13 , struct V_128 * V_129 ,
struct V_151 * V_152 ,
const struct V_126 * V_127 )
{
T_5 V_15 ;
int V_41 = F_78 ( V_2 , V_21 , V_13 , V_129 , V_153 , V_152 ) ;
if ( V_41 < 0 ) {
F_79 ( V_21 , L_20 , V_27 ) ;
return V_41 ;
}
if ( V_152 -> V_44 != V_127 -> V_44 ) {
F_79 ( V_21 , L_21 , V_27 ) ;
return - V_49 ;
}
V_15 = F_6 ( V_152 -> V_45 , V_127 -> V_18 ) ;
if ( V_15 < 0 ) {
F_79 ( V_21 , L_22 ,
V_27 ) ;
return V_15 ;
}
if ( ! F_72 ( V_15 , V_152 -> V_46 , V_2 -> V_25 ) ) {
F_79 ( V_21 , L_23 ,
V_27 , V_152 -> V_45 , V_152 -> V_46 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_80 ( struct V_12 * V_13 ,
struct V_154 * V_155 )
{
struct V_156 * V_157 = & V_155 -> V_158 ;
const struct V_126 * V_127 = V_13 -> V_17 ;
struct V_128 * V_129 = F_67 ( V_13 ) ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
struct V_34 * V_21 = V_13 -> V_21 . V_22 ;
struct V_151 V_152 ;
int V_41 ;
V_41 = F_78 ( V_2 , V_21 , V_13 , V_129 , V_159 , V_155 ) ;
if ( V_41 < 0 ) {
F_59 ( V_21 , L_24 , V_27 ,
V_157 -> V_45 , V_157 -> V_46 , V_157 -> V_160 , V_157 -> V_161 ) ;
return V_41 ;
}
V_41 = F_68 ( V_129 , V_134 , V_162 , & V_152 ) ;
if ( V_41 < 0 ) {
F_59 ( V_21 , L_25 , V_27 ) ;
return V_41 ;
}
V_41 = F_74 ( & V_152 . V_45 , & V_152 . V_46 , V_127 -> V_18 , V_2 -> V_25 ,
false ) ;
if ( V_41 < 0 ) {
F_79 ( V_21 , L_26 ,
V_27 , V_152 . V_45 , V_152 . V_46 ,
V_127 -> V_18 -> V_146 ) ;
return V_41 ;
}
if ( ! V_41 ) {
V_41 = F_77 ( V_2 , V_21 , V_13 , V_129 , & V_152 , V_127 ) ;
if ( V_41 < 0 ) {
F_79 ( V_21 , L_27 , V_27 ) ;
return V_41 ;
}
}
V_13 -> V_16 = V_152 . V_45 ;
V_13 -> V_24 = V_152 . V_46 ;
return 0 ;
}
static int F_81 ( struct V_12 * V_13 ,
struct V_163 * V_164 )
{
struct V_128 * V_129 = F_67 ( V_13 ) ;
const struct V_126 * V_127 ;
struct V_34 * V_21 = V_13 -> V_21 . V_22 ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
struct V_165 * V_166 = & V_164 -> V_133 . V_166 ;
struct V_151 V_152 ;
int V_41 ;
V_127 = F_82 ( V_13 , V_166 -> V_167 ) ;
if ( ! V_127 ) {
F_59 ( V_21 , L_28 , V_27 ,
V_166 -> V_167 ) ;
return - V_49 ;
}
V_152 . V_45 = V_166 -> V_45 ;
V_152 . V_46 = V_166 -> V_46 ;
V_152 . V_40 = V_166 -> V_40 ;
V_152 . V_168 = V_166 -> V_168 ;
V_152 . V_44 = V_127 -> V_44 ;
V_41 = F_74 ( & V_152 . V_45 , & V_152 . V_46 , V_127 -> V_18 , V_2 -> V_25 ,
true ) ;
if ( V_41 < 0 ) {
F_79 ( V_21 , L_26 ,
V_27 , V_166 -> V_45 , V_166 -> V_46 ,
V_127 -> V_18 -> V_146 ) ;
return V_41 ;
}
V_41 = F_77 ( V_2 , V_21 , V_13 , V_129 , & V_152 , V_127 ) ;
if ( V_41 < 0 ) {
F_79 ( V_21 , L_27 , V_27 ) ;
return V_41 ;
}
V_166 -> V_45 = V_152 . V_45 ;
V_166 -> V_46 = V_152 . V_46 ;
V_166 -> V_40 = V_152 . V_40 ;
V_166 -> V_168 = V_152 . V_168 ;
V_13 -> V_17 = V_127 ;
return 0 ;
}
static int F_83 ( struct V_12 * V_13 ,
struct V_163 * V_164 )
{
struct V_128 * V_129 = F_67 ( V_13 ) ;
const struct V_126 * V_127 ;
struct V_165 * V_166 = & V_164 -> V_133 . V_166 ;
struct V_151 V_152 ;
int V_41 ;
V_127 = F_82 ( V_13 , V_166 -> V_167 ) ;
if ( ! V_127 ) {
F_59 ( V_13 -> V_21 . V_22 , L_29 ,
V_166 -> V_167 ) ;
return - V_49 ;
}
V_152 . V_45 = V_166 -> V_45 ;
V_152 . V_46 = V_166 -> V_46 ;
V_152 . V_40 = V_166 -> V_40 ;
V_152 . V_168 = V_166 -> V_168 ;
V_152 . V_44 = V_127 -> V_44 ;
V_41 = F_68 ( V_129 , V_134 , V_169 , & V_152 ) ;
if ( V_41 < 0 )
return V_41 ;
V_166 -> V_45 = V_152 . V_45 ;
V_166 -> V_46 = V_152 . V_46 ;
V_166 -> V_40 = V_152 . V_40 ;
V_166 -> V_168 = V_152 . V_168 ;
return 0 ;
}
static int F_84 ( struct V_8 * V_170 ,
struct V_31 * V_29 ,
struct V_171 * V_172 )
{
struct V_12 * V_13 = V_170 -> V_14 ;
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
int V_41 ;
V_41 = V_2 -> V_173 ( V_170 , V_29 , V_172 ) ;
if ( V_41 == - V_174 )
V_175 = true ;
return V_41 ;
}
static void F_85 ( struct V_8 * V_170 ,
struct V_12 * V_13 )
{
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
if ( ! V_175 )
F_86 ( V_170 , & V_176 ,
V_13 -> V_21 . V_22 , & V_2 -> V_98 ,
V_177 , V_178 ,
sizeof( struct V_28 ) , V_13 , & V_13 -> V_179 ) ;
else
F_87 ( V_170 , & V_176 ,
V_13 -> V_21 . V_22 , & V_2 -> V_98 ,
V_177 , V_178 ,
sizeof( struct V_28 ) , V_13 , & V_13 -> V_179 ) ;
V_2 -> V_25 = V_175 ? V_74 : V_33 ;
if ( ! V_175 && V_170 -> V_180 -> V_173 != F_84 ) {
V_2 -> V_173 = V_170 -> V_180 -> V_173 ;
V_170 -> V_180 -> V_173 = F_84 ;
}
}
static int F_88 ( struct V_12 * V_13 ,
struct V_181 * V_182 )
{
int V_183 ;
for ( V_183 = 0 ; V_183 < V_182 -> V_10 ; V_183 ++ ) {
struct V_28 * V_29 = F_19 ( V_13 -> V_184 . V_185 [ V_183 ] ,
struct V_28 , V_32 ) ;
V_29 -> V_43 = 0 ;
F_89 ( & V_29 -> V_32 . V_42 ) ;
}
return 0 ;
}
static int F_90 ( struct V_19 * V_20 ,
struct V_186 * V_187 )
{
F_91 ( V_187 -> V_188 , L_30 , sizeof( V_187 -> V_188 ) ) ;
V_187 -> V_189 = V_190 ;
V_187 -> V_191 = V_192 | V_193 ;
return 0 ;
}
static int F_92 ( struct V_12 * V_13 ,
T_6 V_194 )
{
struct V_19 * V_20 = F_7 ( V_13 -> V_21 . V_22 ) ;
struct V_1 * V_2 = V_20 -> V_23 ;
struct V_34 * V_21 = V_13 -> V_21 . V_22 ;
const struct V_126 * V_127 ;
const struct V_132 * V_133 ;
unsigned long V_195 , V_196 ;
T_2 V_76 , V_78 ;
int V_41 ;
V_195 = V_13 -> V_197 -> V_198 ( V_13 ) ;
V_196 = F_93 ( V_195 ,
V_199 ) ;
if ( ! V_196 )
return - V_49 ;
if ( ( V_196 & V_200 ) &&
( V_196 & V_201 ) ) {
if ( ! V_2 -> V_202 ||
V_2 -> V_202 -> V_97 & V_203 )
V_196 &= ~ V_201 ;
else
V_196 &= ~ V_200 ;
}
V_41 = V_13 -> V_197 -> V_204 ( V_13 , V_196 ) ;
if ( V_41 < 0 )
return V_41 ;
V_76 = F_40 ( V_2 , V_77 ) ;
if ( V_76 & V_82 )
F_41 ( V_2 , V_77 , V_76 & ~ V_82 ) ;
if ( V_196 & V_200 ) {
F_9 ( V_21 , L_31 ) ;
V_76 |= V_205 ;
} else {
F_9 ( V_21 , L_32 ) ;
V_76 &= ~ V_205 ;
}
F_41 ( V_2 , V_77 , V_76 & ~ V_82 ) ;
if ( V_76 & V_82 )
F_41 ( V_2 , V_77 , V_76 ) ;
V_127 = F_82 ( V_13 , V_194 ) ;
V_133 = V_127 -> V_18 ;
V_78 = F_58 ( V_2 , V_79 ) & ~ ( V_83 | V_84 | V_85 ) ;
if ( V_133 -> V_206 == V_207 ) {
F_9 ( V_21 , L_33 ) ;
F_41 ( V_2 , V_79 , V_78 & ~ V_208 ) ;
} else {
F_9 ( V_21 , L_34 ) ;
F_41 ( V_2 , V_79 , V_78 | V_208 ) ;
}
return 0 ;
}
static unsigned int F_94 ( struct V_209 * V_209 , T_7 * V_210 )
{
struct V_12 * V_13 = V_209 -> V_211 ;
struct V_28 * V_29 ;
V_29 = F_34 ( V_13 -> V_184 . V_212 . V_69 , struct V_28 ,
V_32 . V_212 ) ;
F_95 ( V_209 , & V_29 -> V_32 . V_91 , V_210 ) ;
if ( V_29 -> V_32 . V_37 == V_73 ||
V_29 -> V_32 . V_37 == V_58 )
return V_213 | V_214 ;
return 0 ;
}
static int T_8 F_96 ( struct V_215 * V_216 )
{
struct V_1 * V_2 ;
struct V_217 * V_218 ;
struct V_113 * V_113 ;
void T_9 * V_6 ;
unsigned int V_99 ;
int V_219 = 0 ;
V_218 = F_97 ( V_216 , V_220 , 0 ) ;
V_99 = F_98 ( V_216 , 0 ) ;
if ( ! V_218 || ( int ) V_99 <= 0 ) {
V_219 = - V_221 ;
goto exit;
}
V_113 = F_99 ( & V_216 -> V_21 , L_35 ) ;
if ( F_100 ( V_113 ) ) {
V_219 = F_101 ( V_113 ) ;
goto exit;
}
V_2 = F_102 ( sizeof( * V_2 ) + F_103 ( V_218 ) , V_222 ) ;
if ( ! V_2 ) {
F_79 ( & V_216 -> V_21 , L_36 ) ;
V_219 = - V_174 ;
goto V_223;
}
V_2 -> V_218 = V_218 ;
V_2 -> V_113 = V_113 ;
V_2 -> V_202 = V_216 -> V_21 . V_224 ;
V_2 -> V_108 = V_2 -> V_202 -> V_97 ;
if ( V_2 -> V_202 )
V_2 -> V_118 = V_2 -> V_202 -> V_225 * 1000 ;
switch ( V_2 -> V_118 ) {
case 6000000 :
case 8000000 :
case 9600000 :
case 12000000 :
case 24000000 :
break;
default:
F_59 ( & V_216 -> V_21 ,
L_37
L_38
L_39 ,
V_2 -> V_202 -> V_225 ) ;
V_2 -> V_118 = 0 ;
case 0 :
F_104 ( & V_216 -> V_21 ,
L_40 ) ;
}
F_89 ( & V_2 -> V_68 ) ;
F_105 ( & V_2 -> V_98 ) ;
if ( ! F_106 ( V_218 -> V_226 , F_103 ( V_218 ) , V_227 ) ) {
V_219 = - V_112 ;
goto V_228;
}
V_6 = F_107 ( V_218 -> V_226 , F_103 ( V_218 ) ) ;
if ( ! V_6 ) {
V_219 = - V_174 ;
goto V_229;
}
V_2 -> V_99 = V_99 ;
V_2 -> V_6 = V_6 ;
F_61 ( V_2 , true ) ;
V_219 = F_108 ( V_230 , V_227 ,
F_54 , ( void * ) V_2 , & V_2 -> V_53 ) ;
if ( V_219 < 0 ) {
F_79 ( & V_216 -> V_21 , L_41 ) ;
V_219 = - V_112 ;
goto V_231;
}
F_9 ( & V_216 -> V_21 , L_42 , V_2 -> V_53 ) ;
F_109 ( V_2 -> V_53 , V_232 ,
V_233 , V_218 -> V_226 + V_234 ,
0 , 0 ) ;
F_110 ( V_2 -> V_53 , V_235 ) ;
F_111 ( V_2 -> V_53 , V_2 -> V_53 ) ;
V_219 = F_112 ( V_2 -> V_99 , F_57 , 0 , V_227 , V_2 ) ;
if ( V_219 ) {
F_79 ( & V_216 -> V_21 , L_43 ) ;
goto V_236;
}
V_2 -> V_237 . V_238 = V_227 ;
V_2 -> V_237 . V_197 = & V_239 ;
V_2 -> V_237 . V_23 = V_2 ;
V_2 -> V_237 . V_240 . V_21 = & V_216 -> V_21 ;
V_2 -> V_237 . V_241 = V_216 -> V_242 ;
V_219 = F_113 ( & V_2 -> V_237 ) ;
if ( V_219 )
goto V_243;
F_104 ( & V_216 -> V_21 , L_44 ) ;
return 0 ;
V_243:
F_114 ( V_2 -> V_99 , V_2 ) ;
V_236:
F_115 ( V_2 -> V_53 ) ;
V_231:
F_116 ( V_6 ) ;
V_229:
F_117 ( V_218 -> V_226 , F_103 ( V_218 ) ) ;
V_228:
F_118 ( V_2 ) ;
V_223:
F_119 ( V_113 ) ;
exit:
return V_219 ;
}
static int T_10 F_120 ( struct V_215 * V_216 )
{
struct V_19 * V_237 = F_7 ( & V_216 -> V_21 ) ;
struct V_1 * V_2 = F_19 ( V_237 ,
struct V_1 , V_237 ) ;
struct V_217 * V_218 ;
F_114 ( V_2 -> V_99 , V_2 ) ;
F_115 ( V_2 -> V_53 ) ;
F_121 ( V_237 ) ;
F_116 ( V_2 -> V_6 ) ;
V_218 = V_2 -> V_218 ;
F_117 ( V_218 -> V_226 , F_103 ( V_218 ) ) ;
F_119 ( V_2 -> V_113 ) ;
F_118 ( V_2 ) ;
F_104 ( & V_216 -> V_21 , L_45 ) ;
return 0 ;
}
static int T_8 F_122 ( void )
{
return F_123 ( & V_244 ) ;
}
static void T_10 F_124 ( void )
{
F_125 ( & V_244 ) ;
}
