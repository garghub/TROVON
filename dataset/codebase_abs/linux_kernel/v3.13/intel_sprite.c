static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 , int V_10 ,
unsigned int V_11 , unsigned int V_12 ,
T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
T_2 V_25 ;
unsigned long V_26 , V_27 ;
int V_28 = F_3 ( V_6 -> V_29 , 0 ) ;
V_25 = F_4 ( F_5 ( V_23 , V_24 ) ) ;
V_25 &= ~ V_30 ;
V_25 &= ~ V_31 ;
V_25 &= ~ V_32 ;
switch ( V_6 -> V_29 ) {
case V_33 :
V_25 |= V_34 | V_35 ;
break;
case V_36 :
V_25 |= V_34 | V_37 ;
break;
case V_38 :
V_25 |= V_34 | V_39 ;
break;
case V_40 :
V_25 |= V_34 | V_41 ;
break;
case V_42 :
V_25 |= V_43 ;
break;
case V_44 :
V_25 |= V_45 ;
break;
case V_46 :
V_25 |= V_47 ;
break;
case V_48 :
V_25 |= V_49 ;
break;
case V_50 :
V_25 |= V_51 ;
break;
case V_52 :
V_25 |= V_53 ;
break;
case V_54 :
V_25 |= V_55 ;
break;
default:
F_6 () ;
break;
}
if ( V_8 -> V_56 != V_57 )
V_25 |= V_32 ;
V_25 |= V_58 ;
F_7 ( V_2 , V_4 , V_15 , V_28 , true ,
V_15 != V_11 || V_16 != V_12 ) ;
V_15 -- ;
V_16 -- ;
V_11 -- ;
V_12 -- ;
F_8 ( F_9 ( V_23 , V_24 ) , V_6 -> V_59 [ 0 ] ) ;
F_8 ( F_10 ( V_23 , V_24 ) , ( V_10 << 16 ) | V_9 ) ;
V_27 = V_14 * V_6 -> V_59 [ 0 ] + V_13 * V_28 ;
V_26 = F_11 ( & V_13 , & V_14 ,
V_8 -> V_56 ,
V_28 ,
V_6 -> V_59 [ 0 ] ) ;
V_27 -= V_26 ;
if ( V_8 -> V_56 != V_57 )
F_8 ( F_12 ( V_23 , V_24 ) , ( V_14 << 16 ) | V_13 ) ;
else
F_8 ( F_13 ( V_23 , V_24 ) , V_27 ) ;
F_8 ( F_14 ( V_23 , V_24 ) , ( V_12 << 16 ) | V_11 ) ;
F_8 ( F_5 ( V_23 , V_24 ) , V_25 ) ;
F_15 ( F_16 ( V_23 , V_24 ) , F_17 ( V_8 ) +
V_26 ) ;
F_18 ( F_16 ( V_23 , V_24 ) ) ;
}
static void
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
F_8 ( F_5 ( V_23 , V_24 ) , F_4 ( F_5 ( V_23 , V_24 ) ) &
~ V_58 ) ;
F_15 ( F_16 ( V_23 , V_24 ) , 0 ) ;
F_18 ( F_16 ( V_23 , V_24 ) ) ;
F_7 ( V_2 , V_4 , 0 , 0 , false , false ) ;
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
T_2 V_25 ;
if ( V_61 -> V_62 & V_63 )
return - V_64 ;
F_8 ( F_21 ( V_23 , V_24 ) , V_61 -> V_65 ) ;
F_8 ( F_22 ( V_23 , V_24 ) , V_61 -> V_66 ) ;
F_8 ( F_23 ( V_23 , V_24 ) , V_61 -> V_67 ) ;
V_25 = F_4 ( F_5 ( V_23 , V_24 ) ) ;
V_25 &= ~ V_68 ;
if ( V_61 -> V_62 & V_69 )
V_25 |= V_68 ;
F_8 ( F_5 ( V_23 , V_24 ) , V_25 ) ;
F_18 ( F_23 ( V_23 , V_24 ) ) ;
return 0 ;
}
static void
F_24 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
T_2 V_25 ;
V_61 -> V_65 = F_4 ( F_21 ( V_23 , V_24 ) ) ;
V_61 -> V_66 = F_4 ( F_22 ( V_23 , V_24 ) ) ;
V_61 -> V_67 = F_4 ( F_23 ( V_23 , V_24 ) ) ;
V_25 = F_4 ( F_5 ( V_23 , V_24 ) ) ;
if ( V_25 & V_68 )
V_61 -> V_62 = V_69 ;
else
V_61 -> V_62 = V_70 ;
}
static void
F_25 ( struct V_1 * V_24 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 , int V_10 ,
unsigned int V_11 , unsigned int V_12 ,
T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
int V_23 = V_22 -> V_23 ;
T_2 V_25 , V_71 = 0 ;
unsigned long V_26 , V_27 ;
int V_28 = F_3 ( V_6 -> V_29 , 0 ) ;
bool V_72 = V_20 -> V_73 ;
V_25 = F_4 ( F_26 ( V_23 ) ) ;
V_25 &= ~ V_74 ;
V_25 &= ~ V_75 ;
V_25 &= ~ V_76 ;
V_25 &= ~ V_77 ;
switch ( V_6 -> V_29 ) {
case V_52 :
V_25 |= V_78 | V_75 ;
break;
case V_44 :
V_25 |= V_78 ;
break;
case V_33 :
V_25 |= V_79 | V_80 ;
break;
case V_36 :
V_25 |= V_79 | V_81 ;
break;
case V_38 :
V_25 |= V_79 | V_82 ;
break;
case V_40 :
V_25 |= V_79 | V_83 ;
break;
default:
F_6 () ;
}
if ( V_8 -> V_56 != V_57 )
V_25 |= V_77 ;
if ( F_27 ( V_18 ) || F_28 ( V_18 ) )
V_25 &= ~ V_84 ;
else
V_25 |= V_84 ;
V_25 |= V_85 ;
if ( F_27 ( V_18 ) || F_28 ( V_18 ) )
V_25 |= V_86 ;
F_7 ( V_24 , V_4 , V_15 , V_28 , true ,
V_15 != V_11 || V_16 != V_12 ) ;
V_15 -- ;
V_16 -- ;
V_11 -- ;
V_12 -- ;
if ( V_11 != V_15 || V_12 != V_16 ) {
V_20 -> V_73 |= 1 << V_23 ;
if ( ! V_72 ) {
F_29 ( V_4 ) ;
F_30 ( V_18 , V_23 ) ;
}
V_71 = V_87 | ( V_15 << 16 ) | V_16 ;
} else
V_20 -> V_73 &= ~ ( 1 << V_23 ) ;
F_8 ( F_31 ( V_23 ) , V_6 -> V_59 [ 0 ] ) ;
F_8 ( F_32 ( V_23 ) , ( V_10 << 16 ) | V_9 ) ;
V_27 = V_14 * V_6 -> V_59 [ 0 ] + V_13 * V_28 ;
V_26 =
F_11 ( & V_13 , & V_14 , V_8 -> V_56 ,
V_28 , V_6 -> V_59 [ 0 ] ) ;
V_27 -= V_26 ;
if ( F_27 ( V_18 ) || F_28 ( V_18 ) )
F_8 ( F_33 ( V_23 ) , ( V_14 << 16 ) | V_13 ) ;
else if ( V_8 -> V_56 != V_57 )
F_8 ( F_34 ( V_23 ) , ( V_14 << 16 ) | V_13 ) ;
else
F_8 ( F_35 ( V_23 ) , V_27 ) ;
F_8 ( F_36 ( V_23 ) , ( V_12 << 16 ) | V_11 ) ;
if ( V_22 -> V_88 )
F_8 ( F_37 ( V_23 ) , V_71 ) ;
F_8 ( F_26 ( V_23 ) , V_25 ) ;
F_15 ( F_38 ( V_23 ) ,
F_17 ( V_8 ) + V_26 ) ;
F_18 ( F_38 ( V_23 ) ) ;
if ( V_72 && ! V_20 -> V_73 )
F_29 ( V_4 ) ;
}
static void
F_39 ( struct V_1 * V_24 , struct V_3 * V_4 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
int V_23 = V_22 -> V_23 ;
bool V_72 = V_20 -> V_73 ;
F_8 ( F_26 ( V_23 ) , F_4 ( F_26 ( V_23 ) ) & ~ V_85 ) ;
if ( V_22 -> V_88 )
F_8 ( F_37 ( V_23 ) , 0 ) ;
F_15 ( F_38 ( V_23 ) , 0 ) ;
F_18 ( F_38 ( V_23 ) ) ;
V_20 -> V_73 &= ~ ( 1 << V_23 ) ;
F_7 ( V_24 , V_4 , 0 , 0 , false , false ) ;
if ( V_72 && ! V_20 -> V_73 )
F_29 ( V_4 ) ;
}
static int
F_40 ( struct V_1 * V_24 ,
struct V_60 * V_61 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_25 ;
int V_89 = 0 ;
V_22 = F_2 ( V_24 ) ;
F_8 ( F_41 ( V_22 -> V_23 ) , V_61 -> V_65 ) ;
F_8 ( F_42 ( V_22 -> V_23 ) , V_61 -> V_66 ) ;
F_8 ( F_43 ( V_22 -> V_23 ) , V_61 -> V_67 ) ;
V_25 = F_4 ( F_26 ( V_22 -> V_23 ) ) ;
V_25 &= ~ ( V_90 | V_91 ) ;
if ( V_61 -> V_62 & V_63 )
V_25 |= V_91 ;
else if ( V_61 -> V_62 & V_69 )
V_25 |= V_90 ;
F_8 ( F_26 ( V_22 -> V_23 ) , V_25 ) ;
F_18 ( F_43 ( V_22 -> V_23 ) ) ;
return V_89 ;
}
static void
F_44 ( struct V_1 * V_24 , struct V_60 * V_61 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_25 ;
V_22 = F_2 ( V_24 ) ;
V_61 -> V_65 = F_4 ( F_41 ( V_22 -> V_23 ) ) ;
V_61 -> V_66 = F_4 ( F_42 ( V_22 -> V_23 ) ) ;
V_61 -> V_67 = F_4 ( F_43 ( V_22 -> V_23 ) ) ;
V_61 -> V_62 = 0 ;
V_25 = F_4 ( F_26 ( V_22 -> V_23 ) ) ;
if ( V_25 & V_91 )
V_61 -> V_62 = V_63 ;
else if ( V_25 & V_90 )
V_61 -> V_62 = V_69 ;
else
V_61 -> V_62 = V_70 ;
}
static void
F_45 ( struct V_1 * V_24 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 , int V_10 ,
unsigned int V_11 , unsigned int V_12 ,
T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
int V_23 = V_22 -> V_23 ;
unsigned long V_92 , V_27 ;
T_2 V_93 , V_94 ;
int V_28 = F_3 ( V_6 -> V_29 , 0 ) ;
V_93 = F_4 ( F_46 ( V_23 ) ) ;
V_93 &= ~ V_95 ;
V_93 &= ~ V_96 ;
V_93 &= ~ V_97 ;
V_93 &= ~ V_98 ;
switch ( V_6 -> V_29 ) {
case V_52 :
V_93 |= V_99 | V_96 ;
break;
case V_44 :
V_93 |= V_99 ;
break;
case V_33 :
V_93 |= V_100 | V_101 ;
break;
case V_36 :
V_93 |= V_100 | V_102 ;
break;
case V_38 :
V_93 |= V_100 | V_103 ;
break;
case V_40 :
V_93 |= V_100 | V_104 ;
break;
default:
F_6 () ;
}
if ( V_8 -> V_56 != V_57 )
V_93 |= V_98 ;
if ( F_47 ( V_18 ) )
V_93 |= V_105 ;
V_93 |= V_106 ;
F_7 ( V_24 , V_4 , V_15 , V_28 , true ,
V_15 != V_11 || V_16 != V_12 ) ;
V_15 -- ;
V_16 -- ;
V_11 -- ;
V_12 -- ;
V_94 = 0 ;
if ( F_48 ( V_18 ) || V_11 != V_15 || V_12 != V_16 )
V_94 = V_107 | ( V_15 << 16 ) | V_16 ;
F_8 ( F_49 ( V_23 ) , V_6 -> V_59 [ 0 ] ) ;
F_8 ( F_50 ( V_23 ) , ( V_10 << 16 ) | V_9 ) ;
V_27 = V_14 * V_6 -> V_59 [ 0 ] + V_13 * V_28 ;
V_92 =
F_11 ( & V_13 , & V_14 , V_8 -> V_56 ,
V_28 , V_6 -> V_59 [ 0 ] ) ;
V_27 -= V_92 ;
if ( V_8 -> V_56 != V_57 )
F_8 ( F_51 ( V_23 ) , ( V_14 << 16 ) | V_13 ) ;
else
F_8 ( F_52 ( V_23 ) , V_27 ) ;
F_8 ( F_53 ( V_23 ) , ( V_12 << 16 ) | V_11 ) ;
F_8 ( F_54 ( V_23 ) , V_94 ) ;
F_8 ( F_46 ( V_23 ) , V_93 ) ;
F_15 ( F_55 ( V_23 ) ,
F_17 ( V_8 ) + V_92 ) ;
F_18 ( F_55 ( V_23 ) ) ;
}
static void
F_56 ( struct V_1 * V_24 , struct V_3 * V_4 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
int V_23 = V_22 -> V_23 ;
F_8 ( F_46 ( V_23 ) , F_4 ( F_46 ( V_23 ) ) & ~ V_106 ) ;
F_8 ( F_54 ( V_23 ) , 0 ) ;
F_15 ( F_55 ( V_23 ) , 0 ) ;
F_18 ( F_55 ( V_23 ) ) ;
F_7 ( V_24 , V_4 , 0 , 0 , false , false ) ;
}
static void
F_57 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_108 * V_108 = F_58 ( V_4 ) ;
int V_109 = F_59 ( V_108 -> V_24 ) ;
if ( V_108 -> V_110 )
return;
V_108 -> V_110 = true ;
F_8 ( V_109 , F_4 ( V_109 ) | V_111 ) ;
F_60 ( V_20 , V_108 -> V_24 ) ;
if ( V_108 -> V_112 . V_113 ) {
F_30 ( V_18 , V_108 -> V_23 ) ;
F_61 ( V_108 ) ;
}
F_62 ( & V_18 -> V_114 ) ;
F_63 ( V_18 ) ;
F_64 ( & V_18 -> V_114 ) ;
}
static void
F_65 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_108 * V_108 = F_58 ( V_4 ) ;
int V_109 = F_59 ( V_108 -> V_24 ) ;
if ( ! V_108 -> V_110 )
return;
V_108 -> V_110 = false ;
F_62 ( & V_18 -> V_114 ) ;
if ( V_20 -> V_115 . V_24 == V_108 -> V_24 )
F_66 ( V_18 ) ;
F_64 ( & V_18 -> V_114 ) ;
F_67 ( V_108 ) ;
F_8 ( V_109 , F_4 ( V_109 ) & ~ V_111 ) ;
F_60 ( V_20 , V_108 -> V_24 ) ;
}
static int
F_68 ( struct V_1 * V_24 ,
struct V_60 * V_61 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_93 ;
int V_89 = 0 ;
V_22 = F_2 ( V_24 ) ;
F_8 ( F_69 ( V_22 -> V_23 ) , V_61 -> V_65 ) ;
F_8 ( F_70 ( V_22 -> V_23 ) , V_61 -> V_66 ) ;
F_8 ( F_71 ( V_22 -> V_23 ) , V_61 -> V_67 ) ;
V_93 = F_4 ( F_46 ( V_22 -> V_23 ) ) ;
V_93 &= ~ ( V_116 | V_117 ) ;
if ( V_61 -> V_62 & V_63 )
V_93 |= V_117 ;
else if ( V_61 -> V_62 & V_69 )
V_93 |= V_116 ;
F_8 ( F_46 ( V_22 -> V_23 ) , V_93 ) ;
F_18 ( F_71 ( V_22 -> V_23 ) ) ;
return V_89 ;
}
static void
F_72 ( struct V_1 * V_24 , struct V_60 * V_61 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_93 ;
V_22 = F_2 ( V_24 ) ;
V_61 -> V_65 = F_4 ( F_69 ( V_22 -> V_23 ) ) ;
V_61 -> V_66 = F_4 ( F_70 ( V_22 -> V_23 ) ) ;
V_61 -> V_67 = F_4 ( F_71 ( V_22 -> V_23 ) ) ;
V_61 -> V_62 = 0 ;
V_93 = F_4 ( F_46 ( V_22 -> V_23 ) ) ;
if ( V_93 & V_117 )
V_61 -> V_62 = V_63 ;
else if ( V_93 & V_116 )
V_61 -> V_62 = V_69 ;
else
V_61 -> V_62 = V_70 ;
}
static bool
F_73 ( T_1 V_118 )
{
switch ( V_118 ) {
case V_33 :
case V_38 :
case V_40 :
case V_36 :
return true ;
default:
return false ;
}
}
static int
F_74 ( struct V_1 * V_24 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_9 , int V_10 ,
unsigned int V_11 , unsigned int V_12 ,
T_1 V_119 , T_1 V_120 ,
T_1 V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_108 * V_108 = F_58 ( V_4 ) ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
struct V_121 * V_122 = F_75 ( V_6 ) ;
struct V_7 * V_8 = V_122 -> V_8 ;
struct V_7 * V_123 = V_22 -> V_8 ;
int V_89 ;
bool V_124 = false ;
bool V_125 ;
int V_126 , V_127 ;
int V_128 , V_129 ;
int V_28 = F_3 ( V_6 -> V_29 , 0 ) ;
struct V_130 V_131 = {
. V_132 = V_119 ,
. V_133 = V_119 + V_15 ,
. y1 = V_120 ,
. V_134 = V_120 + V_16 ,
} ;
struct V_130 V_135 = {
. V_132 = V_9 ,
. V_133 = V_9 + V_11 ,
. y1 = V_10 ,
. V_134 = V_10 + V_12 ,
} ;
const struct V_130 V_136 = {
. V_133 = V_108 -> V_137 ? V_108 -> V_112 . V_138 : 0 ,
. V_134 = V_108 -> V_137 ? V_108 -> V_112 . V_139 : 0 ,
} ;
const struct {
int V_9 , V_10 ;
unsigned int V_11 , V_12 ;
T_1 V_119 , V_120 , V_15 , V_16 ;
} V_140 = {
. V_9 = V_9 ,
. V_10 = V_10 ,
. V_11 = V_11 ,
. V_12 = V_12 ,
. V_119 = V_119 ,
. V_120 = V_120 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
} ;
if ( V_22 -> V_23 != V_108 -> V_23 ) {
F_76 ( L_1 ) ;
return - V_64 ;
}
if ( V_6 -> V_141 < 3 || V_6 -> V_142 < 3 || V_6 -> V_59 [ 0 ] > 16384 ) {
F_76 ( L_2 ) ;
return - V_64 ;
}
switch ( V_8 -> V_56 ) {
case V_57 :
case V_143 :
break;
default:
F_76 ( L_3 ) ;
return - V_64 ;
}
V_128 = V_22 -> V_144 << 16 ;
V_129 = V_22 -> V_88 ? 1 : ( 1 << 16 ) ;
V_126 = F_77 ( & V_131 , & V_135 , V_129 , V_128 ) ;
F_78 ( V_126 < 0 ) ;
V_127 = F_79 ( & V_131 , & V_135 , V_129 , V_128 ) ;
F_78 ( V_127 < 0 ) ;
V_125 = F_80 ( & V_131 , & V_135 , & V_136 , V_126 , V_127 ) ;
V_9 = V_135 . V_132 ;
V_10 = V_135 . y1 ;
V_11 = F_81 ( & V_135 ) ;
V_12 = F_82 ( & V_135 ) ;
if ( V_125 ) {
V_126 = F_83 ( & V_131 , & V_135 , V_129 , V_128 ) ;
if ( V_126 < 0 ) {
F_76 ( L_4 ) ;
F_84 ( & V_131 , true ) ;
F_84 ( & V_135 , false ) ;
return V_126 ;
}
V_127 = F_85 ( & V_131 , & V_135 , V_129 , V_128 ) ;
if ( V_127 < 0 ) {
F_76 ( L_5 ) ;
F_84 ( & V_131 , true ) ;
F_84 ( & V_135 , false ) ;
return V_127 ;
}
F_86 ( & V_131 ,
F_81 ( & V_135 ) * V_126 - F_81 ( & V_131 ) ,
F_82 ( & V_135 ) * V_127 - F_82 ( & V_131 ) ) ;
F_87 ( V_131 . V_132 < ( int ) V_119 ||
V_131 . y1 < ( int ) V_120 ||
V_131 . V_133 > ( int ) ( V_119 + V_15 ) ||
V_131 . V_134 > ( int ) ( V_120 + V_16 ) ) ;
V_119 = V_131 . V_132 >> 16 ;
V_15 = F_81 ( & V_131 ) >> 16 ;
V_120 = V_131 . y1 >> 16 ;
V_16 = F_82 ( & V_131 ) >> 16 ;
if ( F_73 ( V_6 -> V_29 ) ) {
V_119 &= ~ 1 ;
V_15 &= ~ 1 ;
if ( ! V_22 -> V_88 )
V_11 &= ~ 1 ;
if ( V_11 == 0 )
V_125 = false ;
}
}
if ( V_125 && ( V_15 != V_11 || V_16 != V_12 ) ) {
unsigned int V_145 ;
F_87 ( ! V_22 -> V_88 ) ;
if ( V_11 < 3 || V_12 < 3 )
V_125 = false ;
if ( V_15 < 3 || V_16 < 3 )
V_125 = false ;
V_145 = ( ( V_119 * V_28 ) & 63 ) + V_15 * V_28 ;
if ( V_15 > 2048 || V_16 > 2048 ||
V_145 > 4096 || V_6 -> V_59 [ 0 ] > 4096 ) {
F_76 ( L_6 ) ;
return - V_64 ;
}
}
V_135 . V_132 = V_9 ;
V_135 . V_133 = V_9 + V_11 ;
V_135 . y1 = V_10 ;
V_135 . V_134 = V_10 + V_12 ;
V_124 = F_88 ( & V_135 , & V_136 ) ;
F_87 ( V_124 && ! V_125 && V_108 -> V_137 ) ;
F_62 ( & V_18 -> V_114 ) ;
V_89 = F_89 ( V_18 , V_8 , NULL ) ;
F_64 ( & V_18 -> V_114 ) ;
if ( V_89 )
return V_89 ;
V_22 -> V_9 = V_140 . V_9 ;
V_22 -> V_10 = V_140 . V_10 ;
V_22 -> V_11 = V_140 . V_11 ;
V_22 -> V_12 = V_140 . V_12 ;
V_22 -> V_119 = V_140 . V_119 ;
V_22 -> V_120 = V_140 . V_120 ;
V_22 -> V_15 = V_140 . V_15 ;
V_22 -> V_16 = V_140 . V_16 ;
V_22 -> V_8 = V_8 ;
if ( V_108 -> V_137 ) {
if ( ! V_124 )
F_57 ( V_4 ) ;
if ( V_125 )
V_22 -> V_146 ( V_24 , V_4 , V_6 , V_8 ,
V_9 , V_10 , V_11 , V_12 ,
V_119 , V_120 , V_15 , V_16 ) ;
else
V_22 -> V_147 ( V_24 , V_4 ) ;
if ( V_124 )
F_65 ( V_4 ) ;
}
if ( V_123 ) {
if ( V_123 != V_8 && V_108 -> V_137 )
F_30 ( V_18 , V_108 -> V_23 ) ;
F_62 ( & V_18 -> V_114 ) ;
F_90 ( V_123 ) ;
F_64 ( & V_18 -> V_114 ) ;
}
return 0 ;
}
static int
F_91 ( struct V_1 * V_24 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
struct V_108 * V_108 ;
if ( ! V_24 -> V_6 )
return 0 ;
if ( F_87 ( ! V_24 -> V_4 ) )
return - V_64 ;
V_108 = F_58 ( V_24 -> V_4 ) ;
if ( V_108 -> V_137 ) {
F_57 ( V_24 -> V_4 ) ;
V_22 -> V_147 ( V_24 , V_24 -> V_4 ) ;
}
if ( V_22 -> V_8 ) {
if ( V_108 -> V_137 )
F_30 ( V_18 , V_22 -> V_23 ) ;
F_62 ( & V_18 -> V_114 ) ;
F_90 ( V_22 -> V_8 ) ;
F_64 ( & V_18 -> V_114 ) ;
V_22 -> V_8 = NULL ;
}
return 0 ;
}
static void F_92 ( struct V_1 * V_24 )
{
struct V_22 * V_22 = F_2 ( V_24 ) ;
F_91 ( V_24 ) ;
F_93 ( V_24 ) ;
F_94 ( V_22 ) ;
}
int F_95 ( struct V_17 * V_18 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_60 * V_151 = V_148 ;
struct V_152 * V_8 ;
struct V_1 * V_24 ;
struct V_22 * V_22 ;
int V_89 = 0 ;
if ( ! F_96 ( V_18 , V_153 ) )
return - V_154 ;
if ( ( V_151 -> V_62 & ( V_63 | V_69 ) ) == ( V_63 | V_69 ) )
return - V_64 ;
F_97 ( V_18 ) ;
V_8 = F_98 ( V_18 , V_151 -> V_155 , V_156 ) ;
if ( ! V_8 ) {
V_89 = - V_157 ;
goto V_158;
}
V_24 = F_99 ( V_8 ) ;
V_22 = F_2 ( V_24 ) ;
V_89 = V_22 -> V_159 ( V_24 , V_151 ) ;
V_158:
F_100 ( V_18 ) ;
return V_89 ;
}
int F_101 ( struct V_17 * V_18 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_60 * V_160 = V_148 ;
struct V_152 * V_8 ;
struct V_1 * V_24 ;
struct V_22 * V_22 ;
int V_89 = 0 ;
if ( ! F_96 ( V_18 , V_153 ) )
return - V_154 ;
F_97 ( V_18 ) ;
V_8 = F_98 ( V_18 , V_160 -> V_155 , V_156 ) ;
if ( ! V_8 ) {
V_89 = - V_157 ;
goto V_158;
}
V_24 = F_99 ( V_8 ) ;
V_22 = F_2 ( V_24 ) ;
V_22 -> V_161 ( V_24 , V_160 ) ;
V_158:
F_100 ( V_18 ) ;
return V_89 ;
}
void F_102 ( struct V_1 * V_24 )
{
struct V_22 * V_22 = F_2 ( V_24 ) ;
if ( ! V_24 -> V_4 || ! V_24 -> V_6 )
return;
F_74 ( V_24 , V_24 -> V_4 , V_24 -> V_6 ,
V_22 -> V_9 , V_22 -> V_10 ,
V_22 -> V_11 , V_22 -> V_12 ,
V_22 -> V_119 , V_22 -> V_120 ,
V_22 -> V_15 , V_22 -> V_16 ) ;
}
void F_103 ( struct V_1 * V_24 )
{
if ( ! V_24 -> V_4 || ! V_24 -> V_6 )
return;
F_91 ( V_24 ) ;
}
int
F_104 ( struct V_17 * V_18 , enum V_23 V_23 , int V_24 )
{
struct V_22 * V_22 ;
unsigned long V_162 ;
const T_1 * V_163 ;
int V_164 ;
int V_89 ;
if ( F_105 ( V_18 ) -> V_165 < 5 )
return - V_154 ;
V_22 = F_106 ( sizeof( * V_22 ) , V_166 ) ;
if ( ! V_22 )
return - V_167 ;
switch ( F_105 ( V_18 ) -> V_165 ) {
case 5 :
case 6 :
V_22 -> V_88 = true ;
V_22 -> V_144 = 16 ;
V_22 -> V_146 = F_45 ;
V_22 -> V_147 = F_56 ;
V_22 -> V_159 = F_68 ;
V_22 -> V_161 = F_72 ;
if ( F_47 ( V_18 ) ) {
V_163 = V_168 ;
V_164 = F_107 ( V_168 ) ;
} else {
V_163 = V_169 ;
V_164 = F_107 ( V_169 ) ;
}
break;
case 7 :
case 8 :
if ( F_108 ( V_18 ) ) {
V_22 -> V_88 = true ;
V_22 -> V_144 = 2 ;
} else {
V_22 -> V_88 = false ;
V_22 -> V_144 = 1 ;
}
if ( F_109 ( V_18 ) ) {
V_22 -> V_146 = F_1 ;
V_22 -> V_147 = F_19 ;
V_22 -> V_159 = F_20 ;
V_22 -> V_161 = F_24 ;
V_163 = V_170 ;
V_164 = F_107 ( V_170 ) ;
} else {
V_22 -> V_146 = F_25 ;
V_22 -> V_147 = F_39 ;
V_22 -> V_159 = F_40 ;
V_22 -> V_161 = F_44 ;
V_163 = V_168 ;
V_164 = F_107 ( V_168 ) ;
}
break;
default:
F_94 ( V_22 ) ;
return - V_154 ;
}
V_22 -> V_23 = V_23 ;
V_22 -> V_24 = V_24 ;
V_162 = ( 1 << V_23 ) ;
V_89 = F_110 ( V_18 , & V_22 -> V_171 , V_162 ,
& V_172 ,
V_163 , V_164 ,
false ) ;
if ( V_89 )
F_94 ( V_22 ) ;
return V_89 ;
}
