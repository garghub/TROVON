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
struct V_15 * V_16 = F_6 ( V_13 -> V_17 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
* V_11 = V_13 -> V_19 ;
if ( ! * V_10 || * V_10 < F_7 ( V_2 -> V_20 ) )
* V_10 = F_7 ( V_2 -> V_20 ) ;
if ( * V_11 * * V_10 > V_21 * 1024 * 1024 )
* V_10 = ( V_21 * 1024 * 1024 ) / * V_11 ;
F_8 ( V_13 -> V_17 ,
L_1 , V_22 , * V_10 , * V_11 ) ;
return 0 ;
}
static void F_9 ( struct V_8 * V_9 , struct V_23 * V_24 ,
enum V_25 V_20 )
{
struct V_26 * V_27 = & V_24 -> V_27 ;
F_10 ( F_11 () ) ;
F_12 ( V_9 , V_27 , 0 , 0 ) ;
if ( V_20 == V_28 ) {
F_13 ( V_9 , V_27 ) ;
} else {
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_29 * V_30 = V_13 -> V_17 ;
struct V_31 * V_32 = F_14 ( V_27 ) ;
F_15 ( V_30 , V_32 ) ;
F_16 ( V_32 ) ;
}
V_27 -> V_33 = V_34 ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_26 * V_27 , enum V_35 V_36 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_23 * V_24 = F_18 ( V_27 , struct V_23 , V_27 ) ;
struct V_15 * V_16 = F_6 ( V_13 -> V_17 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
int V_37 ;
F_19 ( ! F_20 ( & V_27 -> V_38 ) ) ;
F_10 ( NULL == V_13 -> V_39 ) ;
V_24 -> V_40 = 1 ;
if ( V_24 -> V_41 != V_13 -> V_39 -> V_41 || V_27 -> V_36 != V_36 ||
V_27 -> V_42 != V_13 -> V_43 ||
V_27 -> V_44 != V_13 -> V_45 ) {
V_24 -> V_41 = V_13 -> V_39 -> V_41 ;
V_27 -> V_42 = V_13 -> V_43 ;
V_27 -> V_44 = V_13 -> V_45 ;
V_27 -> V_36 = V_36 ;
V_27 -> V_33 = V_34 ;
}
V_27 -> V_11 = V_13 -> V_19 ;
if ( V_27 -> V_46 && V_27 -> V_47 < V_27 -> V_11 ) {
V_37 = - V_48 ;
goto V_49;
}
if ( V_27 -> V_33 == V_34 ) {
V_37 = F_21 ( V_9 , V_27 , NULL ) ;
if ( V_37 )
goto V_50;
V_27 -> V_33 = V_51 ;
}
V_24 -> V_40 = 0 ;
return 0 ;
V_50:
F_9 ( V_9 , V_24 , V_2 -> V_20 ) ;
V_49:
V_24 -> V_40 = 0 ;
return V_37 ;
}
static void F_22 ( int V_52 , struct V_23 * V_24 ,
enum V_25 V_20 )
{
T_3 V_53 ;
unsigned int V_54 ;
if ( V_20 == V_28 ) {
V_53 = F_23 ( & V_24 -> V_27 ) ;
V_54 = V_24 -> V_27 . V_11 ;
} else {
if ( F_19 ( ! V_24 -> V_55 ) ) {
V_24 -> V_56 = V_57 ;
return;
}
V_53 = F_24 ( V_24 -> V_55 ) ;
if ( F_19 ( ! V_53 ) ) {
V_24 -> V_55 = NULL ;
V_24 -> V_56 = V_57 ;
return;
}
V_54 = F_25 ( V_24 -> V_55 ) ;
if ( F_19 ( ! V_54 ) ) {
V_24 -> V_55 = NULL ;
V_24 -> V_56 = V_57 ;
return;
}
if ( F_26 ( V_24 -> V_58 < V_54 ) )
V_54 = V_24 -> V_58 ;
if ( F_19 ( V_53 & ( F_27 ( V_20 ) *
V_59 - 1 ) ) ) {
V_53 = F_28 ( V_53 , F_27 ( V_20 ) *
V_59 ) ;
V_54 &= ~ ( F_27 ( V_20 ) *
V_59 - 1 ) ;
}
V_24 -> V_58 -= V_54 ;
V_24 -> V_60 ++ ;
}
F_29 ( V_52 ,
V_61 , V_62 , V_53 , 0 , 0 ) ;
F_30 ( V_52 ,
V_63 , F_27 ( V_20 ) ,
V_54 >> ( F_31 ( V_20 ) + V_64 ) ,
V_65 , 0 , 0 ) ;
}
static struct V_23 * F_32 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
V_24 = V_2 -> V_66 ;
if ( ! V_24 ) {
if ( F_20 ( & V_2 -> V_67 ) )
return V_24 ;
V_24 = F_33 ( V_2 -> V_67 . V_68 ,
struct V_23 , V_27 . V_38 ) ;
V_24 -> V_27 . V_33 = V_69 ;
V_2 -> V_66 = V_24 ;
F_34 ( & V_24 -> V_27 . V_38 ) ;
}
if ( V_2 -> V_20 == V_28 ) {
F_22 ( V_2 -> V_52 , V_24 , V_2 -> V_20 ) ;
} else {
V_24 -> V_55 = NULL ;
}
return V_24 ;
}
static struct V_70 * F_35 ( int V_52 , struct V_23 * V_24 )
{
struct V_70 * V_55 ;
if ( F_36 ( V_24 -> V_55 ) ) {
if ( F_26 ( ! V_24 -> V_58 ) ) {
V_55 = NULL ;
} else {
V_55 = F_37 ( V_24 -> V_55 ) ;
if ( F_19 ( ! V_55 ) ) {
V_24 -> V_56 = V_57 ;
} else if ( F_19 ( ! F_25 ( V_55 ) ) ) {
V_55 = NULL ;
V_24 -> V_56 = V_57 ;
}
}
V_24 -> V_55 = V_55 ;
} else {
struct V_31 * V_32 = F_14 ( & V_24 -> V_27 ) ;
V_55 = V_32 -> V_71 ;
if ( ! ( F_19 ( ! V_55 ) ) ) {
V_24 -> V_55 = V_55 ;
V_24 -> V_60 = 0 ;
V_24 -> V_58 = V_24 -> V_27 . V_11 ;
V_24 -> V_56 = V_72 ;
}
}
if ( V_55 )
F_22 ( V_52 , V_24 , V_73 ) ;
return V_55 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_74 ;
T_2 V_75 = F_39 ( V_2 , V_76 ) ;
T_2 V_77 = F_39 ( V_2 , V_78 ) & ~ V_79 ;
if ( F_19 ( ! V_24 ) )
return;
V_77 |= V_80 ;
if ( F_26 ( V_75 & V_81 ) )
F_40 ( V_2 , V_76 , V_75 & ~ V_81 ) ;
F_40 ( V_2 , V_78 , V_77 | V_82 ) ;
F_41 ( V_2 -> V_52 ) ;
if ( V_2 -> V_20 == V_73 ) {
F_35 ( V_2 -> V_52 , V_24 ) ;
}
F_40 ( V_2 , V_76 , V_75 | V_81 ) ;
F_40 ( V_2 , V_78 , V_77 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_2 V_75 = F_39 ( V_2 , V_76 ) ;
F_40 ( V_2 , V_76 , V_75 & ~ V_81 ) ;
F_43 ( V_2 -> V_52 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_2 V_77 = F_39 ( V_2 , V_78 ) ;
F_40 ( V_2 , V_78 , V_77 & ~ ( V_83 | V_84 ) ) ;
}
static void F_45 ( struct V_8 * V_9 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_15 * V_16 = F_6 ( V_13 -> V_17 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_23 * V_24 ;
T_2 V_77 ;
F_46 ( & V_27 -> V_38 , & V_2 -> V_67 ) ;
V_27 -> V_33 = V_85 ;
if ( V_2 -> V_74 ) {
return;
}
F_19 ( V_2 -> V_66 ) ;
V_24 = F_32 ( V_2 ) ;
if ( F_19 ( ! V_24 ) )
return;
V_2 -> V_74 = V_24 ;
V_2 -> V_66 = NULL ;
F_8 ( V_13 -> V_17 ,
L_2 , V_22 ) ;
V_77 = F_39 ( V_2 , V_78 ) & ~ V_86 ;
V_77 |= F_47 ( V_2 -> V_20 ) << V_87 ;
F_40 ( V_2 , V_78 , V_77 | V_88 | V_84 ) ;
if ( V_2 -> V_20 == V_73 ) {
F_35 ( V_2 -> V_52 , V_24 ) ;
}
F_38 ( V_2 ) ;
}
static void F_48 ( struct V_8 * V_9 ,
struct V_26 * V_27 )
{
struct V_23 * V_24 =
F_18 ( V_27 , struct V_23 , V_27 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_29 * V_30 = V_13 -> V_17 ;
struct V_15 * V_16 = F_6 ( V_30 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
switch ( V_27 -> V_33 ) {
case V_72 :
F_8 ( V_30 , L_3 , V_22 ) ;
break;
case V_69 :
F_8 ( V_30 , L_4 , V_22 ) ;
break;
case V_85 :
F_8 ( V_30 , L_5 , V_22 ) ;
break;
case V_51 :
F_8 ( V_30 , L_6 , V_22 ) ;
break;
default:
F_8 ( V_30 , L_7 , V_22 , V_27 -> V_33 ) ;
break;
}
F_9 ( V_9 , V_24 , V_2 -> V_20 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
enum V_89 V_56 )
{
struct V_23 * V_24 = V_2 -> V_74 ;
struct V_26 * V_27 ;
struct V_29 * V_30 = V_2 -> V_90 . V_13 -> V_17 ;
if ( F_19 ( ! V_24 ) ) {
F_42 ( V_2 ) ;
F_44 ( V_2 ) ;
return;
}
if ( V_56 == V_57 )
F_42 ( V_2 ) ;
V_27 = & V_24 -> V_27 ;
if ( F_50 ( & V_27 -> V_91 ) ) {
if ( ! V_2 -> V_66 && V_56 != V_57 ) {
F_42 ( V_2 ) ;
}
V_27 -> V_33 = V_56 ;
F_51 ( & V_27 -> V_92 ) ;
if ( V_56 != V_57 )
V_27 -> V_93 ++ ;
F_52 ( & V_27 -> V_91 ) ;
V_24 = V_2 -> V_66 ;
V_2 -> V_74 = V_24 ;
V_2 -> V_66 = NULL ;
if ( ! V_24 ) {
V_56 = V_57 ;
F_32 ( V_2 ) ;
V_24 = V_2 -> V_66 ;
V_2 -> V_74 = V_24 ;
V_2 -> V_66 = NULL ;
}
} else if ( V_2 -> V_66 ) {
F_8 ( V_30 , L_8 ,
V_22 ) ;
V_2 -> V_74 = V_2 -> V_66 ;
if ( V_2 -> V_20 == V_73 ) {
V_24 -> V_55 = NULL ;
}
V_2 -> V_66 = V_24 ;
V_24 = V_2 -> V_74 ;
} else {
if ( V_2 -> V_20 == V_28 ) {
F_8 ( V_30 ,
L_9 ,
V_22 ) ;
} else {
if ( V_56 != V_57 ) {
F_42 ( V_2 ) ;
V_56 = V_57 ;
}
}
}
if ( ! V_24 ) {
F_8 ( V_30 , L_10 , V_22 ) ;
F_44 ( V_2 ) ;
return;
}
if ( V_2 -> V_20 == V_28 ) {
} else {
if ( V_56 == V_57 )
V_24 -> V_55 = NULL ;
F_35 ( V_2 -> V_52 , V_24 ) ;
}
if ( V_56 == V_57 ) {
F_8 ( V_30 , L_11 ,
V_22 ) ;
F_38 ( V_2 ) ;
}
F_32 ( V_2 ) ;
}
static void F_53 ( int V_94 , unsigned short V_95 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_23 * V_24 = V_2 -> V_74 ;
unsigned long V_97 ;
F_54 ( & V_2 -> V_98 , V_97 ) ;
if ( F_19 ( ! V_24 ) ) {
F_42 ( V_2 ) ;
F_44 ( V_2 ) ;
goto V_49;
}
if ( V_2 -> V_20 == V_28 ) {
F_40 ( V_2 , V_78 ,
F_39 ( V_2 , V_78 ) & ~ V_79 ) ;
F_49 ( V_2 , V_72 ) ;
} else {
if ( V_24 -> V_55 ) {
F_35 ( V_2 -> V_52 , V_24 ) ;
if ( V_24 -> V_55 )
goto V_49;
if ( V_24 -> V_56 != V_57 ) {
V_24 = F_32 ( V_2 ) ;
if ( ! V_24 )
goto V_49;
F_35 ( V_2 -> V_52 , V_24 ) ;
goto V_49;
}
}
F_49 ( V_2 , V_24 -> V_56 ) ;
}
V_49:
F_55 ( & V_2 -> V_98 , V_97 ) ;
}
static T_4 F_56 ( int V_99 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_29 * V_30 = V_2 -> V_90 . V_13 -> V_17 ;
struct V_23 * V_24 = V_2 -> V_74 ;
T_2 V_100 ;
unsigned long V_97 ;
V_100 = F_57 ( V_2 , V_101 ) ;
if ( ! V_100 )
return V_102 ;
F_54 ( & V_2 -> V_98 , V_97 ) ;
if ( F_19 ( ! V_24 ) ) {
F_58 ( V_30 , L_12 ,
V_22 , V_100 ) ;
F_42 ( V_2 ) ;
F_44 ( V_2 ) ;
goto V_49;
}
if ( F_26 ( V_100 & V_103 ) ) {
F_58 ( V_30 , L_13 , V_22 ) ;
} else if ( V_100 & V_104 ) {
if ( V_2 -> V_20 == V_28 ) {
} else {
if ( V_24 -> V_60 == 2 ) {
goto V_49;
}
}
F_59 ( V_30 , L_14 ,
V_22 ) ;
} else if ( V_100 & V_105 ) {
T_2 V_77 ;
if ( V_2 -> V_20 == V_28 ) {
V_77 = F_39 ( V_2 , V_78 ) ;
} else {
V_77 = F_39 ( V_2 , V_78 ) & ~ V_80 ;
}
if ( ! ( V_77 & V_79 ) ) {
V_77 |= V_79 ;
}
F_40 ( V_2 , V_78 , V_77 ) ;
goto V_49;
} else {
F_58 ( V_30 , L_12 ,
V_22 , V_100 ) ;
goto V_49;
}
F_49 ( V_2 , V_57 ) ;
V_49:
F_55 ( & V_2 -> V_98 , V_97 ) ;
return V_106 ;
}
static void F_60 ( struct V_1 * V_2 , bool V_107 )
{
if ( V_2 -> V_108 & V_109 )
F_40 ( V_2 , V_110 , V_107 ) ;
else if ( V_2 -> V_108 & V_111 )
F_40 ( V_2 , V_110 , ! V_107 ) ;
}
static int F_61 ( struct V_12 * V_13 )
{
F_8 ( V_13 -> V_17 , L_15 ,
V_13 -> V_112 ) ;
return 0 ;
}
static void F_62 ( struct V_12 * V_13 )
{
F_8 ( V_13 -> V_17 ,
L_16 , V_13 -> V_112 ) ;
}
static int F_63 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_2 V_75 ;
F_64 ( V_2 -> V_113 ) ;
V_75 = F_57 ( V_2 , V_76 ) ;
V_75 &= ~ ( V_114 | V_115 | V_116 ) ;
F_40 ( V_2 , V_76 , V_75 ) ;
V_75 &= ~ V_117 ;
switch ( V_2 -> V_118 ) {
case 6000000 :
V_75 |= V_114 | V_119 ;
break;
case 8000000 :
V_75 |= V_114 | V_120 | V_116 ;
break;
case 9600000 :
V_75 |= V_114 | V_121 | V_116 ;
break;
case 12000000 :
V_75 |= V_114 | V_122 ;
break;
case 24000000 :
V_75 |= V_114 | V_123 | V_116 ;
default:
break;
}
F_40 ( V_2 , V_76 , V_75 & ~ V_116 ) ;
V_75 |= V_115 ;
F_40 ( V_2 , V_76 , V_75 ) ;
F_60 ( V_2 , false ) ;
return 0 ;
}
static void F_65 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_2 V_75 ;
F_42 ( V_2 ) ;
F_44 ( V_2 ) ;
F_60 ( V_2 , true ) ;
V_75 = F_39 ( V_2 , V_76 ) ;
V_75 &= ~ ( V_115 | V_116 | V_114 ) ;
F_40 ( V_2 , V_76 , V_75 ) ;
V_75 = ( V_75 & ~ V_117 ) | V_122 ;
F_40 ( V_2 , V_76 , V_75 ) ;
F_40 ( V_2 , V_76 , V_75 | V_115 ) ;
F_40 ( V_2 , V_76 , V_75 & ~ V_115 ) ;
F_66 ( V_2 -> V_113 ) ;
}
static int F_67 ( struct V_12 * V_13 ,
unsigned int V_124 , struct V_125 * V_126 )
{
struct V_127 * V_128 = F_68 ( V_13 ) ;
struct V_29 * V_30 = V_13 -> V_17 ;
int V_129 = 0 , V_37 ;
enum V_130 V_41 ;
const struct V_131 * V_132 ;
V_37 = F_69 ( V_128 , V_133 , V_134 , V_124 , & V_41 ) ;
if ( V_37 < 0 )
return 0 ;
V_132 = F_70 ( V_41 ) ;
if ( ! V_132 ) {
F_58 ( V_30 , L_17 , V_22 ,
V_124 , V_41 ) ;
return 0 ;
}
if ( V_132 -> V_135 != 8 )
return 0 ;
switch ( V_41 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
V_129 ++ ;
if ( V_126 ) {
V_126 -> V_144 = F_71 ( V_41 ,
V_145 ,
F_72 ( V_145 ) ) ;
V_126 -> V_41 = V_41 ;
V_126 ++ ;
F_8 ( V_30 ,
L_18 ,
V_22 , V_126 -> V_144 -> V_146 , V_41 ) ;
}
default:
if ( V_126 )
F_8 ( V_30 ,
L_19 ,
V_22 , V_132 -> V_146 ) ;
}
V_129 ++ ;
if ( V_126 ) {
V_126 -> V_144 = V_132 ;
V_126 -> V_41 = V_41 ;
V_126 ++ ;
}
return V_129 ;
}
static bool F_73 ( T_5 V_147 , unsigned int V_44 ,
enum V_25 V_20 )
{
int V_11 = V_147 * V_44 ;
return F_74 ( V_147 , V_59 ) &&
F_74 ( V_11 , F_27 ( V_20 ) * V_59 ) ;
}
static int F_75 ( int * V_42 , int * V_44 ,
const struct V_131 * V_132 ,
enum V_25 V_20 , bool V_148 )
{
T_5 V_147 = F_76 ( * V_42 , V_132 ) ;
if ( V_147 < 0 )
return V_147 ;
if ( ! F_73 ( V_147 , * V_44 , V_20 ) ) {
unsigned int V_149 = F_77 ( V_147 / * V_42 ) ;
unsigned int V_150 = F_31 ( V_20 ) +
V_64 - V_149 ;
unsigned int V_151 = V_148 << V_150 ;
F_78 ( V_42 , 1 , * V_42 + V_151 , 0 ,
V_44 , 1 , * V_44 + V_151 , 0 , V_150 ) ;
return 0 ;
}
return 1 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_12 * V_13 , struct V_127 * V_128 ,
struct V_152 * V_153 ,
const struct V_125 * V_126 )
{
T_5 V_147 ;
int V_37 = F_80 ( V_2 , V_30 , V_13 , V_128 , V_154 , V_153 ) ;
if ( V_37 < 0 ) {
F_81 ( V_30 , L_20 , V_22 ) ;
return V_37 ;
}
if ( V_153 -> V_41 != V_126 -> V_41 ) {
F_81 ( V_30 , L_21 , V_22 ) ;
return - V_48 ;
}
V_147 = F_76 ( V_153 -> V_42 , V_126 -> V_144 ) ;
if ( V_147 < 0 ) {
F_81 ( V_30 , L_22 ,
V_22 ) ;
return V_147 ;
}
if ( ! F_73 ( V_147 , V_153 -> V_44 , V_2 -> V_20 ) ) {
F_81 ( V_30 , L_23 ,
V_22 , V_153 -> V_42 , V_153 -> V_44 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_82 ( struct V_12 * V_13 ,
const struct V_155 * V_156 )
{
const struct V_157 * V_158 = & V_156 -> V_159 ;
const struct V_125 * V_126 = V_13 -> V_39 ;
struct V_127 * V_128 = F_68 ( V_13 ) ;
struct V_29 * V_30 = V_13 -> V_17 ;
struct V_15 * V_16 = F_6 ( V_30 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_152 V_153 ;
int V_37 ;
V_37 = F_80 ( V_2 , V_30 , V_13 , V_128 , V_160 , V_156 ) ;
if ( V_37 < 0 ) {
F_58 ( V_30 , L_24 , V_22 ,
V_158 -> V_42 , V_158 -> V_44 , V_158 -> V_161 , V_158 -> V_162 ) ;
return V_37 ;
}
V_37 = F_69 ( V_128 , V_133 , V_163 , & V_153 ) ;
if ( V_37 < 0 ) {
F_58 ( V_30 , L_25 , V_22 ) ;
return V_37 ;
}
V_37 = F_75 ( & V_153 . V_42 , & V_153 . V_44 , V_126 -> V_144 , V_2 -> V_20 ,
false ) ;
if ( V_37 < 0 ) {
F_81 ( V_30 , L_26 ,
V_22 , V_153 . V_42 , V_153 . V_44 ,
V_126 -> V_144 -> V_146 ) ;
return V_37 ;
}
if ( ! V_37 ) {
V_37 = F_79 ( V_2 , V_30 , V_13 , V_128 , & V_153 , V_126 ) ;
if ( V_37 < 0 ) {
F_81 ( V_30 , L_27 , V_22 ) ;
return V_37 ;
}
}
V_13 -> V_43 = V_153 . V_42 ;
V_13 -> V_45 = V_153 . V_44 ;
return 0 ;
}
static int F_83 ( struct V_12 * V_13 ,
struct V_164 * V_165 )
{
struct V_127 * V_128 = F_68 ( V_13 ) ;
const struct V_125 * V_126 ;
struct V_29 * V_30 = V_13 -> V_17 ;
struct V_15 * V_16 = F_6 ( V_30 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_166 * V_167 = & V_165 -> V_132 . V_167 ;
struct V_152 V_153 ;
int V_37 ;
V_126 = F_84 ( V_13 , V_167 -> V_168 ) ;
if ( ! V_126 ) {
F_58 ( V_30 , L_28 , V_22 ,
V_167 -> V_168 ) ;
return - V_48 ;
}
V_153 . V_42 = V_167 -> V_42 ;
V_153 . V_44 = V_167 -> V_44 ;
V_153 . V_36 = V_167 -> V_36 ;
V_153 . V_169 = V_167 -> V_169 ;
V_153 . V_41 = V_126 -> V_41 ;
V_37 = F_75 ( & V_153 . V_42 , & V_153 . V_44 , V_126 -> V_144 , V_2 -> V_20 ,
true ) ;
if ( V_37 < 0 ) {
F_81 ( V_30 , L_26 ,
V_22 , V_167 -> V_42 , V_167 -> V_44 ,
V_126 -> V_144 -> V_146 ) ;
return V_37 ;
}
V_37 = F_79 ( V_2 , V_30 , V_13 , V_128 , & V_153 , V_126 ) ;
if ( V_37 < 0 ) {
F_81 ( V_30 , L_27 , V_22 ) ;
return V_37 ;
}
V_167 -> V_42 = V_153 . V_42 ;
V_167 -> V_44 = V_153 . V_44 ;
V_167 -> V_36 = V_153 . V_36 ;
V_167 -> V_169 = V_153 . V_169 ;
V_13 -> V_39 = V_126 ;
return 0 ;
}
static int F_85 ( struct V_12 * V_13 ,
struct V_164 * V_165 )
{
struct V_127 * V_128 = F_68 ( V_13 ) ;
const struct V_125 * V_126 ;
struct V_166 * V_167 = & V_165 -> V_132 . V_167 ;
struct V_152 V_153 ;
int V_37 ;
V_126 = F_84 ( V_13 , V_167 -> V_168 ) ;
if ( ! V_126 ) {
F_58 ( V_13 -> V_17 , L_29 ,
V_167 -> V_168 ) ;
return - V_48 ;
}
V_153 . V_42 = V_167 -> V_42 ;
V_153 . V_44 = V_167 -> V_44 ;
V_153 . V_36 = V_167 -> V_36 ;
V_153 . V_169 = V_167 -> V_169 ;
V_153 . V_41 = V_126 -> V_41 ;
V_37 = F_69 ( V_128 , V_133 , V_170 , & V_153 ) ;
if ( V_37 < 0 )
return V_37 ;
V_167 -> V_42 = V_153 . V_42 ;
V_167 -> V_44 = V_153 . V_44 ;
V_167 -> V_36 = V_153 . V_36 ;
V_167 -> V_169 = V_153 . V_169 ;
return 0 ;
}
static int F_86 ( struct V_8 * V_171 ,
struct V_26 * V_24 ,
struct V_172 * V_173 )
{
struct V_12 * V_13 = V_171 -> V_14 ;
struct V_15 * V_16 = F_6 ( V_13 -> V_17 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
int V_37 ;
V_37 = V_2 -> V_174 ( V_171 , V_24 , V_173 ) ;
if ( V_37 == - V_175 )
V_176 = true ;
return V_37 ;
}
static void F_87 ( struct V_8 * V_171 ,
struct V_12 * V_13 )
{
struct V_15 * V_16 = F_6 ( V_13 -> V_17 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
if ( ! V_176 )
F_88 ( V_171 , & V_177 ,
V_13 -> V_17 , & V_2 -> V_98 ,
V_178 , V_179 ,
sizeof( struct V_23 ) , V_13 , & V_16 -> V_180 ) ;
else
F_89 ( V_171 , & V_177 ,
V_13 -> V_17 , & V_2 -> V_98 ,
V_178 , V_179 ,
sizeof( struct V_23 ) , V_13 , & V_16 -> V_180 ) ;
V_2 -> V_20 = V_176 ? V_73 : V_28 ;
if ( ! V_176 && V_171 -> V_181 -> V_174 != F_86 ) {
V_2 -> V_174 = V_171 -> V_181 -> V_174 ;
V_171 -> V_181 -> V_174 = F_86 ;
}
}
static int F_90 ( struct V_12 * V_13 ,
struct V_182 * V_183 )
{
int V_184 ;
for ( V_184 = 0 ; V_184 < V_183 -> V_10 ; V_184 ++ ) {
struct V_23 * V_24 = F_18 ( V_13 -> V_185 . V_186 [ V_184 ] ,
struct V_23 , V_27 ) ;
V_24 -> V_40 = 0 ;
F_91 ( & V_24 -> V_27 . V_38 ) ;
}
return 0 ;
}
static int F_92 ( struct V_15 * V_16 ,
struct V_187 * V_188 )
{
F_93 ( V_188 -> V_189 , L_30 , sizeof( V_188 -> V_189 ) ) ;
V_188 -> V_190 = V_191 | V_192 ;
return 0 ;
}
static int F_94 ( struct V_12 * V_13 )
{
struct V_127 * V_128 = F_68 ( V_13 ) ;
struct V_29 * V_30 = V_13 -> V_17 ;
struct V_15 * V_16 = F_6 ( V_30 ) ;
struct V_1 * V_2 = V_16 -> V_18 ;
T_2 V_193 = V_13 -> V_39 -> V_144 -> V_194 ;
const struct V_125 * V_126 ;
const struct V_131 * V_132 ;
struct V_195 V_196 = { . type = V_197 ,} ;
unsigned long V_198 ;
T_2 V_75 , V_77 ;
int V_37 ;
V_37 = F_69 ( V_128 , V_133 , V_199 , & V_196 ) ;
if ( ! V_37 ) {
V_198 = F_95 ( & V_196 , V_200 ) ;
if ( ! V_198 ) {
F_58 ( V_30 ,
L_31 ,
V_196 . V_97 , V_200 ) ;
return - V_48 ;
}
} else if ( V_37 != - V_201 ) {
return V_37 ;
} else {
V_198 = V_200 ;
}
if ( ( V_198 & V_202 ) &&
( V_198 & V_203 ) ) {
if ( ! V_2 -> V_204 ||
V_2 -> V_204 -> V_97 & V_205 )
V_198 &= ~ V_203 ;
else
V_198 &= ~ V_202 ;
}
V_196 . V_97 = V_198 ;
V_37 = F_69 ( V_128 , V_133 , V_206 , & V_196 ) ;
if ( V_37 < 0 && V_37 != - V_201 ) {
F_8 ( V_30 , L_32 ,
V_198 , V_37 ) ;
return V_37 ;
}
V_75 = F_39 ( V_2 , V_76 ) ;
if ( V_75 & V_81 )
F_40 ( V_2 , V_76 , V_75 & ~ V_81 ) ;
if ( V_198 & V_202 ) {
F_8 ( V_30 , L_33 ) ;
V_75 |= V_207 ;
} else {
F_8 ( V_30 , L_34 ) ;
V_75 &= ~ V_207 ;
}
F_40 ( V_2 , V_76 , V_75 & ~ V_81 ) ;
if ( V_75 & V_81 )
F_40 ( V_2 , V_76 , V_75 ) ;
V_126 = F_84 ( V_13 , V_193 ) ;
V_132 = V_126 -> V_144 ;
V_77 = F_57 ( V_2 , V_78 ) & ~ ( V_82 | V_83 | V_84 ) ;
if ( V_132 -> V_208 == V_209 ) {
F_8 ( V_30 , L_35 ) ;
F_40 ( V_2 , V_78 , V_77 & ~ V_210 ) ;
} else {
F_8 ( V_30 , L_36 ) ;
F_40 ( V_2 , V_78 , V_77 | V_210 ) ;
}
return 0 ;
}
static unsigned int F_96 ( struct V_211 * V_211 , T_6 * V_212 )
{
struct V_12 * V_13 = V_211 -> V_213 ;
struct V_23 * V_24 ;
V_24 = F_33 ( V_13 -> V_185 . V_214 . V_68 , struct V_23 ,
V_27 . V_214 ) ;
F_97 ( V_211 , & V_24 -> V_27 . V_91 , V_212 ) ;
if ( V_24 -> V_27 . V_33 == V_72 ||
V_24 -> V_27 . V_33 == V_57 )
return V_215 | V_216 ;
return 0 ;
}
static int F_98 ( struct V_217 * V_218 )
{
struct V_1 * V_2 ;
struct V_219 * V_220 ;
struct V_113 * V_113 ;
void T_7 * V_6 ;
unsigned int V_99 ;
int V_221 = 0 ;
V_220 = F_99 ( V_218 , V_222 , 0 ) ;
V_99 = F_100 ( V_218 , 0 ) ;
if ( ! V_220 || ( int ) V_99 <= 0 ) {
V_221 = - V_223 ;
goto exit;
}
V_113 = F_101 ( & V_218 -> V_30 , L_37 ) ;
if ( F_102 ( V_113 ) ) {
V_221 = F_103 ( V_113 ) ;
goto exit;
}
V_2 = F_104 ( sizeof( * V_2 ) + F_105 ( V_220 ) , V_224 ) ;
if ( ! V_2 ) {
F_81 ( & V_218 -> V_30 , L_38 ) ;
V_221 = - V_175 ;
goto V_225;
}
V_2 -> V_220 = V_220 ;
V_2 -> V_113 = V_113 ;
V_2 -> V_204 = V_218 -> V_30 . V_226 ;
if ( V_2 -> V_204 ) {
V_2 -> V_108 = V_2 -> V_204 -> V_97 ;
V_2 -> V_118 = V_2 -> V_204 -> V_227 * 1000 ;
}
switch ( V_2 -> V_118 ) {
case 6000000 :
case 8000000 :
case 9600000 :
case 12000000 :
case 24000000 :
break;
default:
F_58 ( & V_218 -> V_30 ,
L_39
L_40
L_41 ,
V_2 -> V_204 -> V_227 ) ;
V_2 -> V_118 = 0 ;
case 0 :
F_106 ( & V_218 -> V_30 , L_42 ) ;
}
F_91 ( & V_2 -> V_67 ) ;
F_107 ( & V_2 -> V_98 ) ;
if ( ! F_108 ( V_220 -> V_228 , F_105 ( V_220 ) , V_229 ) ) {
V_221 = - V_230 ;
goto V_231;
}
V_6 = F_109 ( V_220 -> V_228 , F_105 ( V_220 ) ) ;
if ( ! V_6 ) {
V_221 = - V_175 ;
goto V_232;
}
V_2 -> V_99 = V_99 ;
V_2 -> V_6 = V_6 ;
F_60 ( V_2 , true ) ;
V_221 = F_110 ( V_233 , V_229 ,
F_53 , ( void * ) V_2 , & V_2 -> V_52 ) ;
if ( V_221 < 0 ) {
F_81 ( & V_218 -> V_30 , L_43 ) ;
V_221 = - V_230 ;
goto V_234;
}
F_8 ( & V_218 -> V_30 , L_44 , V_2 -> V_52 ) ;
F_111 ( V_2 -> V_52 , V_235 ,
V_236 , V_220 -> V_228 + V_237 ,
0 , 0 ) ;
F_112 ( V_2 -> V_52 , V_238 ) ;
F_113 ( V_2 -> V_52 , V_2 -> V_52 ) ;
V_221 = F_114 ( V_2 -> V_99 , F_56 , 0 , V_229 , V_2 ) ;
if ( V_221 ) {
F_81 ( & V_218 -> V_30 , L_45 ) ;
goto V_239;
}
V_2 -> V_90 . V_240 = V_229 ;
V_2 -> V_90 . V_241 = & V_242 ;
V_2 -> V_90 . V_18 = V_2 ;
V_2 -> V_90 . V_243 . V_30 = & V_218 -> V_30 ;
V_2 -> V_90 . V_244 = V_218 -> V_245 ;
V_221 = F_115 ( & V_2 -> V_90 ) ;
if ( V_221 )
goto V_246;
F_106 ( & V_218 -> V_30 , L_46 ) ;
return 0 ;
V_246:
F_116 ( V_2 -> V_99 , V_2 ) ;
V_239:
F_117 ( V_2 -> V_52 ) ;
V_234:
F_118 ( V_6 ) ;
V_232:
F_119 ( V_220 -> V_228 , F_105 ( V_220 ) ) ;
V_231:
F_120 ( V_2 ) ;
V_225:
F_121 ( V_113 ) ;
exit:
return V_221 ;
}
static int F_122 ( struct V_217 * V_218 )
{
struct V_15 * V_90 = F_6 ( & V_218 -> V_30 ) ;
struct V_1 * V_2 = F_18 ( V_90 ,
struct V_1 , V_90 ) ;
struct V_219 * V_220 ;
F_116 ( V_2 -> V_99 , V_2 ) ;
F_117 ( V_2 -> V_52 ) ;
F_123 ( V_90 ) ;
F_118 ( V_2 -> V_6 ) ;
V_220 = V_2 -> V_220 ;
F_119 ( V_220 -> V_228 , F_105 ( V_220 ) ) ;
F_121 ( V_2 -> V_113 ) ;
F_120 ( V_2 ) ;
F_106 ( & V_218 -> V_30 , L_47 ) ;
return 0 ;
}
