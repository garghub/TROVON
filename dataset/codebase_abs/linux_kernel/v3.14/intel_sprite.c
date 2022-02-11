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
V_25 |= V_56 ;
if ( V_8 -> V_57 != V_58 )
V_25 |= V_32 ;
V_25 |= V_59 ;
F_7 ( V_2 , V_4 , V_15 , V_28 , true ,
V_15 != V_11 || V_16 != V_12 ) ;
V_15 -- ;
V_16 -- ;
V_11 -- ;
V_12 -- ;
F_8 ( F_9 ( V_23 , V_24 ) , V_6 -> V_60 [ 0 ] ) ;
F_8 ( F_10 ( V_23 , V_24 ) , ( V_10 << 16 ) | V_9 ) ;
V_27 = V_14 * V_6 -> V_60 [ 0 ] + V_13 * V_28 ;
V_26 = F_11 ( & V_13 , & V_14 ,
V_8 -> V_57 ,
V_28 ,
V_6 -> V_60 [ 0 ] ) ;
V_27 -= V_26 ;
if ( V_8 -> V_57 != V_58 )
F_8 ( F_12 ( V_23 , V_24 ) , ( V_14 << 16 ) | V_13 ) ;
else
F_8 ( F_13 ( V_23 , V_24 ) , V_27 ) ;
F_8 ( F_14 ( V_23 , V_24 ) , ( V_12 << 16 ) | V_11 ) ;
F_8 ( F_5 ( V_23 , V_24 ) , V_25 ) ;
F_8 ( F_15 ( V_23 , V_24 ) , F_16 ( V_8 ) +
V_26 ) ;
F_17 ( F_15 ( V_23 , V_24 ) ) ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
F_8 ( F_5 ( V_23 , V_24 ) , F_4 ( F_5 ( V_23 , V_24 ) ) &
~ V_59 ) ;
F_8 ( F_15 ( V_23 , V_24 ) , 0 ) ;
F_17 ( F_15 ( V_23 , V_24 ) ) ;
F_7 ( V_2 , V_4 , 0 , 0 , false , false ) ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
T_2 V_25 ;
if ( V_62 -> V_63 & V_64 )
return - V_65 ;
F_8 ( F_20 ( V_23 , V_24 ) , V_62 -> V_66 ) ;
F_8 ( F_21 ( V_23 , V_24 ) , V_62 -> V_67 ) ;
F_8 ( F_22 ( V_23 , V_24 ) , V_62 -> V_68 ) ;
V_25 = F_4 ( F_5 ( V_23 , V_24 ) ) ;
V_25 &= ~ V_69 ;
if ( V_62 -> V_63 & V_70 )
V_25 |= V_69 ;
F_8 ( F_5 ( V_23 , V_24 ) , V_25 ) ;
F_17 ( F_22 ( V_23 , V_24 ) ) ;
return 0 ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_2 ) ;
int V_23 = V_22 -> V_23 ;
int V_24 = V_22 -> V_24 ;
T_2 V_25 ;
V_62 -> V_66 = F_4 ( F_20 ( V_23 , V_24 ) ) ;
V_62 -> V_67 = F_4 ( F_21 ( V_23 , V_24 ) ) ;
V_62 -> V_68 = F_4 ( F_22 ( V_23 , V_24 ) ) ;
V_25 = F_4 ( F_5 ( V_23 , V_24 ) ) ;
if ( V_25 & V_69 )
V_62 -> V_63 = V_70 ;
else
V_62 -> V_63 = V_71 ;
}
static void
F_24 ( struct V_1 * V_24 , struct V_3 * V_4 ,
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
T_2 V_25 , V_72 = 0 ;
unsigned long V_26 , V_27 ;
int V_28 = F_3 ( V_6 -> V_29 , 0 ) ;
V_25 = F_4 ( F_25 ( V_23 ) ) ;
V_25 &= ~ V_73 ;
V_25 &= ~ V_74 ;
V_25 &= ~ V_75 ;
V_25 &= ~ V_76 ;
switch ( V_6 -> V_29 ) {
case V_52 :
V_25 |= V_77 | V_74 ;
break;
case V_44 :
V_25 |= V_77 ;
break;
case V_33 :
V_25 |= V_78 | V_79 ;
break;
case V_36 :
V_25 |= V_78 | V_80 ;
break;
case V_38 :
V_25 |= V_78 | V_81 ;
break;
case V_40 :
V_25 |= V_78 | V_82 ;
break;
default:
F_6 () ;
}
V_25 |= V_83 ;
if ( V_8 -> V_57 != V_58 )
V_25 |= V_76 ;
if ( F_26 ( V_18 ) || F_27 ( V_18 ) )
V_25 &= ~ V_84 ;
else
V_25 |= V_84 ;
V_25 |= V_85 ;
if ( F_26 ( V_18 ) || F_27 ( V_18 ) )
V_25 |= V_86 ;
F_7 ( V_24 , V_4 , V_15 , V_28 , true ,
V_15 != V_11 || V_16 != V_12 ) ;
V_15 -- ;
V_16 -- ;
V_11 -- ;
V_12 -- ;
if ( V_11 != V_15 || V_12 != V_16 )
V_72 = V_87 | ( V_15 << 16 ) | V_16 ;
F_8 ( F_28 ( V_23 ) , V_6 -> V_60 [ 0 ] ) ;
F_8 ( F_29 ( V_23 ) , ( V_10 << 16 ) | V_9 ) ;
V_27 = V_14 * V_6 -> V_60 [ 0 ] + V_13 * V_28 ;
V_26 =
F_11 ( & V_13 , & V_14 , V_8 -> V_57 ,
V_28 , V_6 -> V_60 [ 0 ] ) ;
V_27 -= V_26 ;
if ( F_26 ( V_18 ) || F_27 ( V_18 ) )
F_8 ( F_30 ( V_23 ) , ( V_14 << 16 ) | V_13 ) ;
else if ( V_8 -> V_57 != V_58 )
F_8 ( F_31 ( V_23 ) , ( V_14 << 16 ) | V_13 ) ;
else
F_8 ( F_32 ( V_23 ) , V_27 ) ;
F_8 ( F_33 ( V_23 ) , ( V_12 << 16 ) | V_11 ) ;
if ( V_22 -> V_88 )
F_8 ( F_34 ( V_23 ) , V_72 ) ;
F_8 ( F_25 ( V_23 ) , V_25 ) ;
F_8 ( F_35 ( V_23 ) ,
F_16 ( V_8 ) + V_26 ) ;
F_17 ( F_35 ( V_23 ) ) ;
}
static void
F_36 ( struct V_1 * V_24 , struct V_3 * V_4 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
int V_23 = V_22 -> V_23 ;
F_8 ( F_25 ( V_23 ) , F_4 ( F_25 ( V_23 ) ) & ~ V_85 ) ;
if ( V_22 -> V_88 )
F_8 ( F_34 ( V_23 ) , 0 ) ;
F_8 ( F_35 ( V_23 ) , 0 ) ;
F_17 ( F_35 ( V_23 ) ) ;
F_37 ( V_18 , V_23 ) ;
F_7 ( V_24 , V_4 , 0 , 0 , false , false ) ;
}
static int
F_38 ( struct V_1 * V_24 ,
struct V_61 * V_62 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_25 ;
int V_89 = 0 ;
V_22 = F_2 ( V_24 ) ;
F_8 ( F_39 ( V_22 -> V_23 ) , V_62 -> V_66 ) ;
F_8 ( F_40 ( V_22 -> V_23 ) , V_62 -> V_67 ) ;
F_8 ( F_41 ( V_22 -> V_23 ) , V_62 -> V_68 ) ;
V_25 = F_4 ( F_25 ( V_22 -> V_23 ) ) ;
V_25 &= ~ ( V_90 | V_91 ) ;
if ( V_62 -> V_63 & V_64 )
V_25 |= V_91 ;
else if ( V_62 -> V_63 & V_70 )
V_25 |= V_90 ;
F_8 ( F_25 ( V_22 -> V_23 ) , V_25 ) ;
F_17 ( F_41 ( V_22 -> V_23 ) ) ;
return V_89 ;
}
static void
F_42 ( struct V_1 * V_24 , struct V_61 * V_62 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_25 ;
V_22 = F_2 ( V_24 ) ;
V_62 -> V_66 = F_4 ( F_39 ( V_22 -> V_23 ) ) ;
V_62 -> V_67 = F_4 ( F_40 ( V_22 -> V_23 ) ) ;
V_62 -> V_68 = F_4 ( F_41 ( V_22 -> V_23 ) ) ;
V_62 -> V_63 = 0 ;
V_25 = F_4 ( F_25 ( V_22 -> V_23 ) ) ;
if ( V_25 & V_91 )
V_62 -> V_63 = V_64 ;
else if ( V_25 & V_90 )
V_62 -> V_63 = V_70 ;
else
V_62 -> V_63 = V_71 ;
}
static void
F_43 ( struct V_1 * V_24 , struct V_3 * V_4 ,
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
V_93 = F_4 ( F_44 ( V_23 ) ) ;
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
V_93 |= V_105 ;
if ( V_8 -> V_57 != V_58 )
V_93 |= V_98 ;
if ( F_45 ( V_18 ) )
V_93 |= V_106 ;
V_93 |= V_107 ;
F_7 ( V_24 , V_4 , V_15 , V_28 , true ,
V_15 != V_11 || V_16 != V_12 ) ;
V_15 -- ;
V_16 -- ;
V_11 -- ;
V_12 -- ;
V_94 = 0 ;
if ( V_11 != V_15 || V_12 != V_16 )
V_94 = V_108 | ( V_15 << 16 ) | V_16 ;
F_8 ( F_46 ( V_23 ) , V_6 -> V_60 [ 0 ] ) ;
F_8 ( F_47 ( V_23 ) , ( V_10 << 16 ) | V_9 ) ;
V_27 = V_14 * V_6 -> V_60 [ 0 ] + V_13 * V_28 ;
V_92 =
F_11 ( & V_13 , & V_14 , V_8 -> V_57 ,
V_28 , V_6 -> V_60 [ 0 ] ) ;
V_27 -= V_92 ;
if ( V_8 -> V_57 != V_58 )
F_8 ( F_48 ( V_23 ) , ( V_14 << 16 ) | V_13 ) ;
else
F_8 ( F_49 ( V_23 ) , V_27 ) ;
F_8 ( F_50 ( V_23 ) , ( V_12 << 16 ) | V_11 ) ;
F_8 ( F_51 ( V_23 ) , V_94 ) ;
F_8 ( F_44 ( V_23 ) , V_93 ) ;
F_8 ( F_52 ( V_23 ) ,
F_16 ( V_8 ) + V_92 ) ;
F_17 ( F_52 ( V_23 ) ) ;
}
static void
F_53 ( struct V_1 * V_24 , struct V_3 * V_4 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
int V_23 = V_22 -> V_23 ;
F_8 ( F_44 ( V_23 ) , F_4 ( F_44 ( V_23 ) ) & ~ V_107 ) ;
F_8 ( F_51 ( V_23 ) , 0 ) ;
F_8 ( F_52 ( V_23 ) , 0 ) ;
F_17 ( F_52 ( V_23 ) ) ;
F_37 ( V_18 , V_23 ) ;
F_7 ( V_24 , V_4 , 0 , 0 , false , false ) ;
}
static void
F_54 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_109 * V_109 = F_55 ( V_4 ) ;
int V_110 = F_56 ( V_109 -> V_24 ) ;
if ( V_109 -> V_111 )
return;
V_109 -> V_111 = true ;
F_8 ( V_110 , F_4 ( V_110 ) | V_112 ) ;
F_57 ( V_20 , V_109 -> V_24 ) ;
if ( V_109 -> V_113 . V_114 ) {
F_37 ( V_18 , V_109 -> V_23 ) ;
F_58 ( V_109 ) ;
}
F_59 ( & V_18 -> V_115 ) ;
F_60 ( V_18 ) ;
F_61 ( & V_18 -> V_115 ) ;
}
static void
F_62 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_109 * V_109 = F_55 ( V_4 ) ;
int V_110 = F_56 ( V_109 -> V_24 ) ;
if ( ! V_109 -> V_111 )
return;
V_109 -> V_111 = false ;
F_59 ( & V_18 -> V_115 ) ;
if ( V_20 -> V_116 . V_24 == V_109 -> V_24 )
F_63 ( V_18 ) ;
F_61 ( & V_18 -> V_115 ) ;
F_64 ( V_109 ) ;
F_8 ( V_110 , F_4 ( V_110 ) & ~ V_112 ) ;
F_57 ( V_20 , V_109 -> V_24 ) ;
}
static int
F_65 ( struct V_1 * V_24 ,
struct V_61 * V_62 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_93 ;
int V_89 = 0 ;
V_22 = F_2 ( V_24 ) ;
F_8 ( F_66 ( V_22 -> V_23 ) , V_62 -> V_66 ) ;
F_8 ( F_67 ( V_22 -> V_23 ) , V_62 -> V_67 ) ;
F_8 ( F_68 ( V_22 -> V_23 ) , V_62 -> V_68 ) ;
V_93 = F_4 ( F_44 ( V_22 -> V_23 ) ) ;
V_93 &= ~ ( V_117 | V_118 ) ;
if ( V_62 -> V_63 & V_64 )
V_93 |= V_118 ;
else if ( V_62 -> V_63 & V_70 )
V_93 |= V_117 ;
F_8 ( F_44 ( V_22 -> V_23 ) , V_93 ) ;
F_17 ( F_68 ( V_22 -> V_23 ) ) ;
return V_89 ;
}
static void
F_69 ( struct V_1 * V_24 , struct V_61 * V_62 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_22 * V_22 ;
T_2 V_93 ;
V_22 = F_2 ( V_24 ) ;
V_62 -> V_66 = F_4 ( F_66 ( V_22 -> V_23 ) ) ;
V_62 -> V_67 = F_4 ( F_67 ( V_22 -> V_23 ) ) ;
V_62 -> V_68 = F_4 ( F_68 ( V_22 -> V_23 ) ) ;
V_62 -> V_63 = 0 ;
V_93 = F_4 ( F_44 ( V_22 -> V_23 ) ) ;
if ( V_93 & V_118 )
V_62 -> V_63 = V_64 ;
else if ( V_93 & V_117 )
V_62 -> V_63 = V_70 ;
else
V_62 -> V_63 = V_71 ;
}
static bool
F_70 ( T_1 V_119 )
{
switch ( V_119 ) {
case V_33 :
case V_38 :
case V_40 :
case V_36 :
return true ;
default:
return false ;
}
}
static bool F_71 ( struct V_22 * V_22 )
{
struct V_61 V_62 ;
V_22 -> V_120 ( & V_22 -> V_121 , & V_62 ) ;
return V_62 . V_63 != V_71 ;
}
static int
F_72 ( struct V_1 * V_24 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_9 , int V_10 ,
unsigned int V_11 , unsigned int V_12 ,
T_1 V_122 , T_1 V_123 ,
T_1 V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_109 * V_109 = F_55 ( V_4 ) ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
struct V_124 * V_125 = F_73 ( V_6 ) ;
struct V_7 * V_8 = V_125 -> V_8 ;
struct V_7 * V_126 = V_22 -> V_8 ;
int V_89 ;
bool V_127 = false ;
bool V_128 ;
int V_129 , V_130 ;
int V_131 , V_132 ;
int V_28 = F_3 ( V_6 -> V_29 , 0 ) ;
struct V_133 V_134 = {
. V_135 = V_122 ,
. V_136 = V_122 + V_15 ,
. y1 = V_123 ,
. V_137 = V_123 + V_16 ,
} ;
struct V_133 V_138 = {
. V_135 = V_9 ,
. V_136 = V_9 + V_11 ,
. y1 = V_10 ,
. V_137 = V_10 + V_12 ,
} ;
const struct V_133 V_139 = {
. V_136 = V_109 -> V_140 ? V_109 -> V_113 . V_141 : 0 ,
. V_137 = V_109 -> V_140 ? V_109 -> V_113 . V_142 : 0 ,
} ;
const struct {
int V_9 , V_10 ;
unsigned int V_11 , V_12 ;
T_1 V_122 , V_123 , V_15 , V_16 ;
} V_143 = {
. V_9 = V_9 ,
. V_10 = V_10 ,
. V_11 = V_11 ,
. V_12 = V_12 ,
. V_122 = V_122 ,
. V_123 = V_123 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
} ;
if ( V_22 -> V_23 != V_109 -> V_23 ) {
F_74 ( L_1 ) ;
return - V_65 ;
}
if ( V_6 -> V_144 < 3 || V_6 -> V_145 < 3 || V_6 -> V_60 [ 0 ] > 16384 ) {
F_74 ( L_2 ) ;
return - V_65 ;
}
switch ( V_8 -> V_57 ) {
case V_58 :
case V_146 :
break;
default:
F_74 ( L_3 ) ;
return - V_65 ;
}
V_131 = V_22 -> V_147 << 16 ;
V_132 = V_22 -> V_88 ? 1 : ( 1 << 16 ) ;
V_129 = F_75 ( & V_134 , & V_138 , V_132 , V_131 ) ;
F_76 ( V_129 < 0 ) ;
V_130 = F_77 ( & V_134 , & V_138 , V_132 , V_131 ) ;
F_76 ( V_130 < 0 ) ;
V_128 = F_78 ( & V_134 , & V_138 , & V_139 , V_129 , V_130 ) ;
V_9 = V_138 . V_135 ;
V_10 = V_138 . y1 ;
V_11 = F_79 ( & V_138 ) ;
V_12 = F_80 ( & V_138 ) ;
if ( V_128 ) {
V_129 = F_81 ( & V_134 , & V_138 , V_132 , V_131 ) ;
if ( V_129 < 0 ) {
F_74 ( L_4 ) ;
F_82 ( & V_134 , true ) ;
F_82 ( & V_138 , false ) ;
return V_129 ;
}
V_130 = F_83 ( & V_134 , & V_138 , V_132 , V_131 ) ;
if ( V_130 < 0 ) {
F_74 ( L_5 ) ;
F_82 ( & V_134 , true ) ;
F_82 ( & V_138 , false ) ;
return V_130 ;
}
F_84 ( & V_134 ,
F_79 ( & V_138 ) * V_129 - F_79 ( & V_134 ) ,
F_80 ( & V_138 ) * V_130 - F_80 ( & V_134 ) ) ;
F_85 ( V_134 . V_135 < ( int ) V_122 ||
V_134 . y1 < ( int ) V_123 ||
V_134 . V_136 > ( int ) ( V_122 + V_15 ) ||
V_134 . V_137 > ( int ) ( V_123 + V_16 ) ) ;
V_122 = V_134 . V_135 >> 16 ;
V_15 = F_79 ( & V_134 ) >> 16 ;
V_123 = V_134 . y1 >> 16 ;
V_16 = F_80 ( & V_134 ) >> 16 ;
if ( F_70 ( V_6 -> V_29 ) ) {
V_122 &= ~ 1 ;
V_15 &= ~ 1 ;
if ( ! V_22 -> V_88 )
V_11 &= ~ 1 ;
if ( V_11 == 0 )
V_128 = false ;
}
}
if ( V_128 && ( V_15 != V_11 || V_16 != V_12 ) ) {
unsigned int V_148 ;
F_85 ( ! V_22 -> V_88 ) ;
if ( V_11 < 3 || V_12 < 3 )
V_128 = false ;
if ( V_15 < 3 || V_16 < 3 )
V_128 = false ;
V_148 = ( ( V_122 * V_28 ) & 63 ) + V_15 * V_28 ;
if ( V_15 > 2048 || V_16 > 2048 ||
V_148 > 4096 || V_6 -> V_60 [ 0 ] > 4096 ) {
F_74 ( L_6 ) ;
return - V_65 ;
}
}
V_138 . V_135 = V_9 ;
V_138 . V_136 = V_9 + V_11 ;
V_138 . y1 = V_10 ;
V_138 . V_137 = V_10 + V_12 ;
V_127 = F_86 ( & V_138 , & V_139 ) && ! F_71 ( V_22 ) ;
F_85 ( V_127 && ! V_128 && V_109 -> V_140 ) ;
F_59 ( & V_18 -> V_115 ) ;
V_89 = F_87 ( V_18 , V_8 , NULL ) ;
F_61 ( & V_18 -> V_115 ) ;
if ( V_89 )
return V_89 ;
V_22 -> V_9 = V_143 . V_9 ;
V_22 -> V_10 = V_143 . V_10 ;
V_22 -> V_11 = V_143 . V_11 ;
V_22 -> V_12 = V_143 . V_12 ;
V_22 -> V_122 = V_143 . V_122 ;
V_22 -> V_123 = V_143 . V_123 ;
V_22 -> V_15 = V_143 . V_15 ;
V_22 -> V_16 = V_143 . V_16 ;
V_22 -> V_8 = V_8 ;
if ( V_109 -> V_140 ) {
if ( ! V_127 )
F_54 ( V_4 ) ;
if ( V_128 )
V_22 -> V_149 ( V_24 , V_4 , V_6 , V_8 ,
V_9 , V_10 , V_11 , V_12 ,
V_122 , V_123 , V_15 , V_16 ) ;
else
V_22 -> V_150 ( V_24 , V_4 ) ;
if ( V_127 )
F_62 ( V_4 ) ;
}
if ( V_126 ) {
if ( V_126 != V_8 && V_109 -> V_140 )
F_37 ( V_18 , V_109 -> V_23 ) ;
F_59 ( & V_18 -> V_115 ) ;
F_88 ( V_126 ) ;
F_61 ( & V_18 -> V_115 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_1 * V_24 )
{
struct V_17 * V_18 = V_24 -> V_18 ;
struct V_22 * V_22 = F_2 ( V_24 ) ;
struct V_109 * V_109 ;
if ( ! V_24 -> V_6 )
return 0 ;
if ( F_85 ( ! V_24 -> V_4 ) )
return - V_65 ;
V_109 = F_55 ( V_24 -> V_4 ) ;
if ( V_109 -> V_140 ) {
F_54 ( V_24 -> V_4 ) ;
V_22 -> V_150 ( V_24 , V_24 -> V_4 ) ;
}
if ( V_22 -> V_8 ) {
if ( V_109 -> V_140 )
F_37 ( V_18 , V_22 -> V_23 ) ;
F_59 ( & V_18 -> V_115 ) ;
F_88 ( V_22 -> V_8 ) ;
F_61 ( & V_18 -> V_115 ) ;
V_22 -> V_8 = NULL ;
}
return 0 ;
}
static void F_90 ( struct V_1 * V_24 )
{
struct V_22 * V_22 = F_2 ( V_24 ) ;
F_89 ( V_24 ) ;
F_91 ( V_24 ) ;
F_92 ( V_22 ) ;
}
int F_93 ( struct V_17 * V_18 , void * V_151 ,
struct V_152 * V_153 )
{
struct V_61 * V_154 = V_151 ;
struct V_155 * V_8 ;
struct V_1 * V_24 ;
struct V_22 * V_22 ;
int V_89 = 0 ;
if ( ! F_94 ( V_18 , V_156 ) )
return - V_157 ;
if ( ( V_154 -> V_63 & ( V_64 | V_70 ) ) == ( V_64 | V_70 ) )
return - V_65 ;
F_95 ( V_18 ) ;
V_8 = F_96 ( V_18 , V_154 -> V_158 , V_159 ) ;
if ( ! V_8 ) {
V_89 = - V_160 ;
goto V_161;
}
V_24 = F_97 ( V_8 ) ;
V_22 = F_2 ( V_24 ) ;
V_89 = V_22 -> V_162 ( V_24 , V_154 ) ;
V_161:
F_98 ( V_18 ) ;
return V_89 ;
}
int F_99 ( struct V_17 * V_18 , void * V_151 ,
struct V_152 * V_153 )
{
struct V_61 * V_163 = V_151 ;
struct V_155 * V_8 ;
struct V_1 * V_24 ;
struct V_22 * V_22 ;
int V_89 = 0 ;
if ( ! F_94 ( V_18 , V_156 ) )
return - V_157 ;
F_95 ( V_18 ) ;
V_8 = F_96 ( V_18 , V_163 -> V_158 , V_159 ) ;
if ( ! V_8 ) {
V_89 = - V_160 ;
goto V_161;
}
V_24 = F_97 ( V_8 ) ;
V_22 = F_2 ( V_24 ) ;
V_22 -> V_120 ( V_24 , V_163 ) ;
V_161:
F_98 ( V_18 ) ;
return V_89 ;
}
void F_100 ( struct V_1 * V_24 )
{
struct V_22 * V_22 = F_2 ( V_24 ) ;
if ( ! V_24 -> V_4 || ! V_24 -> V_6 )
return;
F_72 ( V_24 , V_24 -> V_4 , V_24 -> V_6 ,
V_22 -> V_9 , V_22 -> V_10 ,
V_22 -> V_11 , V_22 -> V_12 ,
V_22 -> V_122 , V_22 -> V_123 ,
V_22 -> V_15 , V_22 -> V_16 ) ;
}
void F_101 ( struct V_1 * V_24 )
{
if ( ! V_24 -> V_4 || ! V_24 -> V_6 )
return;
F_89 ( V_24 ) ;
}
int
F_102 ( struct V_17 * V_18 , enum V_23 V_23 , int V_24 )
{
struct V_22 * V_22 ;
unsigned long V_164 ;
const T_1 * V_165 ;
int V_166 ;
int V_89 ;
if ( F_103 ( V_18 ) -> V_167 < 5 )
return - V_157 ;
V_22 = F_104 ( sizeof( * V_22 ) , V_168 ) ;
if ( ! V_22 )
return - V_169 ;
switch ( F_103 ( V_18 ) -> V_167 ) {
case 5 :
case 6 :
V_22 -> V_88 = true ;
V_22 -> V_147 = 16 ;
V_22 -> V_149 = F_43 ;
V_22 -> V_150 = F_53 ;
V_22 -> V_162 = F_65 ;
V_22 -> V_120 = F_69 ;
if ( F_45 ( V_18 ) ) {
V_165 = V_170 ;
V_166 = F_105 ( V_170 ) ;
} else {
V_165 = V_171 ;
V_166 = F_105 ( V_171 ) ;
}
break;
case 7 :
case 8 :
if ( F_106 ( V_18 ) ) {
V_22 -> V_88 = true ;
V_22 -> V_147 = 2 ;
} else {
V_22 -> V_88 = false ;
V_22 -> V_147 = 1 ;
}
if ( F_107 ( V_18 ) ) {
V_22 -> V_149 = F_1 ;
V_22 -> V_150 = F_18 ;
V_22 -> V_162 = F_19 ;
V_22 -> V_120 = F_23 ;
V_165 = V_172 ;
V_166 = F_105 ( V_172 ) ;
} else {
V_22 -> V_149 = F_24 ;
V_22 -> V_150 = F_36 ;
V_22 -> V_162 = F_38 ;
V_22 -> V_120 = F_42 ;
V_165 = V_170 ;
V_166 = F_105 ( V_170 ) ;
}
break;
default:
F_92 ( V_22 ) ;
return - V_157 ;
}
V_22 -> V_23 = V_23 ;
V_22 -> V_24 = V_24 ;
V_164 = ( 1 << V_23 ) ;
V_89 = F_108 ( V_18 , & V_22 -> V_121 , V_164 ,
& V_173 ,
V_165 , V_166 ,
false ) ;
if ( V_89 )
F_92 ( V_22 ) ;
return V_89 ;
}
