static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
int V_22 = V_20 -> V_22 ;
T_2 V_23 ;
unsigned long V_24 , V_25 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
V_23 = F_4 ( F_5 ( V_21 , V_22 ) ) ;
V_23 &= ~ V_28 ;
V_23 &= ~ V_29 ;
V_23 &= ~ V_30 ;
switch ( V_4 -> V_27 ) {
case V_31 :
V_23 |= V_32 | V_33 ;
break;
case V_34 :
V_23 |= V_32 | V_35 ;
break;
case V_36 :
V_23 |= V_32 | V_37 ;
break;
case V_38 :
V_23 |= V_32 | V_39 ;
break;
case V_40 :
V_23 |= V_41 ;
break;
case V_42 :
V_23 |= V_43 ;
break;
case V_44 :
V_23 |= V_45 ;
break;
case V_46 :
V_23 |= V_47 ;
break;
case V_48 :
V_23 |= V_49 ;
break;
case V_50 :
V_23 |= V_51 ;
break;
case V_52 :
V_23 |= V_53 ;
break;
default:
F_6 () ;
break;
}
if ( V_6 -> V_54 != V_55 )
V_23 |= V_30 ;
V_23 |= V_56 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_7 ( V_16 , V_21 , V_9 , V_26 , true ) ;
F_8 ( F_9 ( V_21 , V_22 ) , V_4 -> V_57 [ 0 ] ) ;
F_8 ( F_10 ( V_21 , V_22 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_57 [ 0 ] + V_11 * V_26 ;
V_24 = F_11 ( & V_11 , & V_12 ,
V_6 -> V_54 ,
V_26 ,
V_4 -> V_57 [ 0 ] ) ;
V_25 -= V_24 ;
if ( V_6 -> V_54 != V_55 )
F_8 ( F_12 ( V_21 , V_22 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_8 ( F_13 ( V_21 , V_22 ) , V_25 ) ;
F_8 ( F_14 ( V_21 , V_22 ) , ( V_10 << 16 ) | V_9 ) ;
F_8 ( F_5 ( V_21 , V_22 ) , V_23 ) ;
F_15 ( F_16 ( V_21 , V_22 ) , V_6 -> V_58 +
V_24 ) ;
F_17 ( F_16 ( V_21 , V_22 ) ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
int V_22 = V_20 -> V_22 ;
F_8 ( F_5 ( V_21 , V_22 ) , F_4 ( F_5 ( V_21 , V_22 ) ) &
~ V_56 ) ;
F_15 ( F_16 ( V_21 , V_22 ) , 0 ) ;
F_17 ( F_16 ( V_21 , V_22 ) ) ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
int V_22 = V_20 -> V_22 ;
T_2 V_23 ;
if ( V_60 -> V_61 & V_62 )
return - V_63 ;
F_8 ( F_20 ( V_21 , V_22 ) , V_60 -> V_64 ) ;
F_8 ( F_21 ( V_21 , V_22 ) , V_60 -> V_65 ) ;
F_8 ( F_22 ( V_21 , V_22 ) , V_60 -> V_66 ) ;
V_23 = F_4 ( F_5 ( V_21 , V_22 ) ) ;
V_23 &= ~ V_67 ;
if ( V_60 -> V_61 & V_68 )
V_23 |= V_67 ;
F_8 ( F_5 ( V_21 , V_22 ) , V_23 ) ;
F_17 ( F_22 ( V_21 , V_22 ) ) ;
return 0 ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
int V_22 = V_20 -> V_22 ;
T_2 V_23 ;
V_60 -> V_64 = F_4 ( F_20 ( V_21 , V_22 ) ) ;
V_60 -> V_65 = F_4 ( F_21 ( V_21 , V_22 ) ) ;
V_60 -> V_66 = F_4 ( F_22 ( V_21 , V_22 ) ) ;
V_23 = F_4 ( F_5 ( V_21 , V_22 ) ) ;
if ( V_23 & V_67 )
V_60 -> V_61 = V_68 ;
else
V_60 -> V_61 = V_69 ;
}
static void
F_24 ( struct V_1 * V_22 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
int V_21 = V_20 -> V_21 ;
T_2 V_23 , V_70 = 0 ;
unsigned long V_24 , V_25 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
bool V_71 = V_18 -> V_72 ;
V_23 = F_4 ( F_25 ( V_21 ) ) ;
V_23 &= ~ V_73 ;
V_23 &= ~ V_74 ;
V_23 &= ~ V_75 ;
V_23 &= ~ V_76 ;
switch ( V_4 -> V_27 ) {
case V_50 :
V_23 |= V_77 | V_74 ;
break;
case V_42 :
V_23 |= V_77 ;
break;
case V_31 :
V_23 |= V_78 | V_79 ;
break;
case V_34 :
V_23 |= V_78 | V_80 ;
break;
case V_36 :
V_23 |= V_78 | V_81 ;
break;
case V_38 :
V_23 |= V_78 | V_82 ;
break;
default:
F_6 () ;
}
if ( V_6 -> V_54 != V_55 )
V_23 |= V_76 ;
V_23 |= V_83 ;
V_23 |= V_84 ;
if ( F_26 ( V_16 ) )
V_23 |= V_85 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_7 ( V_16 , V_21 , V_9 , V_26 , true ) ;
if ( V_9 != V_13 || V_10 != V_14 ) {
V_18 -> V_72 |= 1 << V_21 ;
if ( ! V_71 ) {
F_27 ( V_16 ) ;
F_28 ( V_16 , V_21 ) ;
}
V_70 = V_86 | ( V_13 << 16 ) | V_14 ;
} else
V_18 -> V_72 &= ~ ( 1 << V_21 ) ;
F_8 ( F_29 ( V_21 ) , V_4 -> V_57 [ 0 ] ) ;
F_8 ( F_30 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_57 [ 0 ] + V_11 * V_26 ;
V_24 =
F_11 ( & V_11 , & V_12 , V_6 -> V_54 ,
V_26 , V_4 -> V_57 [ 0 ] ) ;
V_25 -= V_24 ;
if ( F_26 ( V_16 ) )
F_8 ( F_31 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else if ( V_6 -> V_54 != V_55 )
F_8 ( F_32 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_8 ( F_33 ( V_21 ) , V_25 ) ;
F_8 ( F_34 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
if ( V_20 -> V_87 )
F_8 ( F_35 ( V_21 ) , V_70 ) ;
F_8 ( F_25 ( V_21 ) , V_23 ) ;
F_15 ( F_36 ( V_21 ) , V_6 -> V_58 + V_24 ) ;
F_17 ( F_36 ( V_21 ) ) ;
if ( V_71 && ! V_18 -> V_72 )
F_27 ( V_16 ) ;
}
static void
F_37 ( struct V_1 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
int V_21 = V_20 -> V_21 ;
bool V_71 = V_18 -> V_72 ;
F_8 ( F_25 ( V_21 ) , F_4 ( F_25 ( V_21 ) ) & ~ V_84 ) ;
if ( V_20 -> V_87 )
F_8 ( F_35 ( V_21 ) , 0 ) ;
F_15 ( F_36 ( V_21 ) , 0 ) ;
F_17 ( F_36 ( V_21 ) ) ;
V_18 -> V_72 &= ~ ( 1 << V_21 ) ;
F_7 ( V_16 , V_21 , 0 , 0 , false ) ;
if ( V_71 && ! V_18 -> V_72 )
F_27 ( V_16 ) ;
}
static int
F_38 ( struct V_1 * V_22 ,
struct V_59 * V_60 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_23 ;
int V_88 = 0 ;
V_20 = F_2 ( V_22 ) ;
F_8 ( F_39 ( V_20 -> V_21 ) , V_60 -> V_64 ) ;
F_8 ( F_40 ( V_20 -> V_21 ) , V_60 -> V_65 ) ;
F_8 ( F_41 ( V_20 -> V_21 ) , V_60 -> V_66 ) ;
V_23 = F_4 ( F_25 ( V_20 -> V_21 ) ) ;
V_23 &= ~ ( V_89 | V_90 ) ;
if ( V_60 -> V_61 & V_62 )
V_23 |= V_90 ;
else if ( V_60 -> V_61 & V_68 )
V_23 |= V_89 ;
F_8 ( F_25 ( V_20 -> V_21 ) , V_23 ) ;
F_17 ( F_41 ( V_20 -> V_21 ) ) ;
return V_88 ;
}
static void
F_42 ( struct V_1 * V_22 , struct V_59 * V_60 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_23 ;
V_20 = F_2 ( V_22 ) ;
V_60 -> V_64 = F_4 ( F_39 ( V_20 -> V_21 ) ) ;
V_60 -> V_65 = F_4 ( F_40 ( V_20 -> V_21 ) ) ;
V_60 -> V_66 = F_4 ( F_41 ( V_20 -> V_21 ) ) ;
V_60 -> V_61 = 0 ;
V_23 = F_4 ( F_25 ( V_20 -> V_21 ) ) ;
if ( V_23 & V_90 )
V_60 -> V_61 = V_62 ;
else if ( V_23 & V_89 )
V_60 -> V_61 = V_68 ;
else
V_60 -> V_61 = V_69 ;
}
static void
F_43 ( struct V_1 * V_22 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
int V_21 = V_20 -> V_21 ;
unsigned long V_91 , V_25 ;
T_2 V_92 , V_93 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
V_92 = F_4 ( F_44 ( V_21 ) ) ;
V_92 &= ~ V_94 ;
V_92 &= ~ V_95 ;
V_92 &= ~ V_96 ;
V_92 &= ~ V_97 ;
switch ( V_4 -> V_27 ) {
case V_50 :
V_92 |= V_98 | V_95 ;
break;
case V_42 :
V_92 |= V_98 ;
break;
case V_31 :
V_92 |= V_99 | V_100 ;
break;
case V_34 :
V_92 |= V_99 | V_101 ;
break;
case V_36 :
V_92 |= V_99 | V_102 ;
break;
case V_38 :
V_92 |= V_99 | V_103 ;
break;
default:
F_6 () ;
}
if ( V_6 -> V_54 != V_55 )
V_92 |= V_97 ;
if ( F_45 ( V_16 ) )
V_92 |= V_104 ;
V_92 |= V_105 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_7 ( V_16 , V_21 , V_9 , V_26 , true ) ;
V_93 = 0 ;
if ( F_46 ( V_16 ) || V_9 != V_13 || V_10 != V_14 )
V_93 = V_106 | ( V_13 << 16 ) | V_14 ;
F_8 ( F_47 ( V_21 ) , V_4 -> V_57 [ 0 ] ) ;
F_8 ( F_48 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_57 [ 0 ] + V_11 * V_26 ;
V_91 =
F_11 ( & V_11 , & V_12 , V_6 -> V_54 ,
V_26 , V_4 -> V_57 [ 0 ] ) ;
V_25 -= V_91 ;
if ( V_6 -> V_54 != V_55 )
F_8 ( F_49 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_8 ( F_50 ( V_21 ) , V_25 ) ;
F_8 ( F_51 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_8 ( F_52 ( V_21 ) , V_93 ) ;
F_8 ( F_44 ( V_21 ) , V_92 ) ;
F_15 ( F_53 ( V_21 ) , V_6 -> V_58 + V_91 ) ;
F_17 ( F_53 ( V_21 ) ) ;
}
static void
F_54 ( struct V_1 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
int V_21 = V_20 -> V_21 ;
F_8 ( F_44 ( V_21 ) , F_4 ( F_44 ( V_21 ) ) & ~ V_105 ) ;
F_8 ( F_52 ( V_21 ) , 0 ) ;
F_15 ( F_53 ( V_21 ) , 0 ) ;
F_17 ( F_53 ( V_21 ) ) ;
}
static void
F_55 ( struct V_107 * V_108 )
{
struct V_15 * V_16 = V_108 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_109 * V_109 = F_56 ( V_108 ) ;
int V_110 = F_57 ( V_109 -> V_22 ) ;
if ( ! V_109 -> V_111 )
return;
V_109 -> V_111 = false ;
F_58 ( V_16 ) ;
F_8 ( V_110 , F_4 ( V_110 ) | V_112 ) ;
}
static void
F_59 ( struct V_107 * V_108 )
{
struct V_15 * V_16 = V_108 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_109 * V_109 = F_56 ( V_108 ) ;
int V_110 = F_57 ( V_109 -> V_22 ) ;
if ( V_109 -> V_111 )
return;
F_8 ( V_110 , F_4 ( V_110 ) & ~ V_112 ) ;
V_109 -> V_111 = true ;
F_58 ( V_16 ) ;
}
static int
F_60 ( struct V_1 * V_22 ,
struct V_59 * V_60 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_92 ;
int V_88 = 0 ;
V_20 = F_2 ( V_22 ) ;
F_8 ( F_61 ( V_20 -> V_21 ) , V_60 -> V_64 ) ;
F_8 ( F_62 ( V_20 -> V_21 ) , V_60 -> V_65 ) ;
F_8 ( F_63 ( V_20 -> V_21 ) , V_60 -> V_66 ) ;
V_92 = F_4 ( F_44 ( V_20 -> V_21 ) ) ;
V_92 &= ~ ( V_113 | V_114 ) ;
if ( V_60 -> V_61 & V_62 )
V_92 |= V_114 ;
else if ( V_60 -> V_61 & V_68 )
V_92 |= V_113 ;
F_8 ( F_44 ( V_20 -> V_21 ) , V_92 ) ;
F_17 ( F_63 ( V_20 -> V_21 ) ) ;
return V_88 ;
}
static void
F_64 ( struct V_1 * V_22 , struct V_59 * V_60 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_92 ;
V_20 = F_2 ( V_22 ) ;
V_60 -> V_64 = F_4 ( F_61 ( V_20 -> V_21 ) ) ;
V_60 -> V_65 = F_4 ( F_62 ( V_20 -> V_21 ) ) ;
V_60 -> V_66 = F_4 ( F_63 ( V_20 -> V_21 ) ) ;
V_60 -> V_61 = 0 ;
V_92 = F_4 ( F_44 ( V_20 -> V_21 ) ) ;
if ( V_92 & V_114 )
V_60 -> V_61 = V_62 ;
else if ( V_92 & V_113 )
V_60 -> V_61 = V_68 ;
else
V_60 -> V_61 = V_69 ;
}
static bool
F_65 ( T_1 V_115 )
{
switch ( V_115 ) {
case V_31 :
case V_36 :
case V_38 :
case V_34 :
return true ;
default:
return false ;
}
}
static int
F_66 ( struct V_1 * V_22 , struct V_107 * V_108 ,
struct V_3 * V_4 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_116 , T_1 V_117 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_109 * V_109 = F_56 ( V_108 ) ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
struct V_118 * V_119 ;
struct V_5 * V_6 , * V_120 ;
int V_21 = V_20 -> V_21 ;
enum V_121 V_122 = F_67 ( V_18 ,
V_21 ) ;
int V_88 = 0 ;
bool V_123 = false ;
bool V_124 ;
int V_125 , V_126 ;
int V_127 , V_128 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
struct V_129 V_130 = {
. V_131 = V_116 ,
. V_132 = V_116 + V_13 ,
. y1 = V_117 ,
. V_133 = V_117 + V_14 ,
} ;
struct V_129 V_134 = {
. V_131 = V_7 ,
. V_132 = V_7 + V_9 ,
. y1 = V_8 ,
. V_133 = V_8 + V_10 ,
} ;
const struct V_129 V_135 = {
. V_132 = V_108 -> V_136 . V_137 ,
. V_133 = V_108 -> V_136 . V_138 ,
} ;
V_119 = F_68 ( V_4 ) ;
V_6 = V_119 -> V_6 ;
V_120 = V_20 -> V_6 ;
V_20 -> V_7 = V_7 ;
V_20 -> V_8 = V_8 ;
V_20 -> V_9 = V_9 ;
V_20 -> V_10 = V_10 ;
V_20 -> V_116 = V_116 ;
V_20 -> V_117 = V_117 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_14 = V_14 ;
if ( ! ( F_4 ( F_69 ( V_122 ) ) & V_139 ) ) {
F_70 ( L_1 ) ;
return - V_63 ;
}
if ( V_20 -> V_21 != V_109 -> V_21 ) {
F_70 ( L_2 ) ;
return - V_63 ;
}
if ( V_4 -> V_140 < 3 || V_4 -> V_141 < 3 || V_4 -> V_57 [ 0 ] > 16384 ) {
F_70 ( L_3 ) ;
return - V_63 ;
}
switch ( V_6 -> V_54 ) {
case V_55 :
case V_142 :
break;
default:
F_70 ( L_4 ) ;
return - V_63 ;
}
V_127 = V_20 -> V_143 << 16 ;
V_128 = V_20 -> V_87 ? 1 : ( 1 << 16 ) ;
V_125 = F_71 ( & V_130 , & V_134 , V_128 , V_127 ) ;
F_72 ( V_125 < 0 ) ;
V_126 = F_73 ( & V_130 , & V_134 , V_128 , V_127 ) ;
F_72 ( V_126 < 0 ) ;
V_124 = F_74 ( & V_130 , & V_134 , & V_135 , V_125 , V_126 ) ;
V_7 = V_134 . V_131 ;
V_8 = V_134 . y1 ;
V_9 = F_75 ( & V_134 ) ;
V_10 = F_76 ( & V_134 ) ;
if ( V_124 ) {
V_125 = F_77 ( & V_130 , & V_134 , V_128 , V_127 ) ;
if ( V_125 < 0 ) {
F_70 ( L_5 ) ;
F_78 ( & V_130 , true ) ;
F_78 ( & V_134 , false ) ;
return V_125 ;
}
V_126 = F_79 ( & V_130 , & V_134 , V_128 , V_127 ) ;
if ( V_126 < 0 ) {
F_70 ( L_6 ) ;
F_78 ( & V_130 , true ) ;
F_78 ( & V_134 , false ) ;
return V_126 ;
}
F_80 ( & V_130 ,
F_75 ( & V_134 ) * V_125 - F_75 ( & V_130 ) ,
F_76 ( & V_134 ) * V_126 - F_76 ( & V_130 ) ) ;
F_81 ( V_130 . V_131 < ( int ) V_116 ||
V_130 . y1 < ( int ) V_117 ||
V_130 . V_132 > ( int ) ( V_116 + V_13 ) ||
V_130 . V_133 > ( int ) ( V_117 + V_14 ) ) ;
V_116 = V_130 . V_131 >> 16 ;
V_13 = F_75 ( & V_130 ) >> 16 ;
V_117 = V_130 . y1 >> 16 ;
V_14 = F_76 ( & V_130 ) >> 16 ;
if ( F_65 ( V_4 -> V_27 ) ) {
V_116 &= ~ 1 ;
V_13 &= ~ 1 ;
if ( ! V_20 -> V_87 )
V_9 &= ~ 1 ;
if ( V_9 == 0 )
V_124 = false ;
}
}
if ( V_124 && ( V_13 != V_9 || V_14 != V_10 ) ) {
unsigned int V_144 ;
F_81 ( ! V_20 -> V_87 ) ;
if ( V_9 < 3 || V_10 < 3 )
V_124 = false ;
if ( V_13 < 3 || V_14 < 3 )
V_124 = false ;
V_144 = ( ( V_116 * V_26 ) & 63 ) + V_13 * V_26 ;
if ( V_13 > 2048 || V_14 > 2048 ||
V_144 > 4096 || V_4 -> V_57 [ 0 ] > 4096 ) {
F_70 ( L_7 ) ;
return - V_63 ;
}
}
V_134 . V_131 = V_7 ;
V_134 . V_132 = V_7 + V_9 ;
V_134 . y1 = V_8 ;
V_134 . V_133 = V_8 + V_10 ;
V_123 = F_82 ( & V_134 , & V_135 ) ;
F_81 ( V_123 && ! V_124 ) ;
F_83 ( & V_16 -> V_145 ) ;
V_88 = F_84 ( V_16 , V_6 , NULL ) ;
if ( V_88 )
goto V_146;
V_20 -> V_6 = V_6 ;
if ( ! V_123 )
F_55 ( V_108 ) ;
if ( V_124 )
V_20 -> V_147 ( V_22 , V_4 , V_6 ,
V_7 , V_8 , V_9 , V_10 ,
V_116 , V_117 , V_13 , V_14 ) ;
else
V_20 -> V_148 ( V_22 ) ;
if ( V_123 )
F_59 ( V_108 ) ;
if ( V_120 ) {
if ( V_120 != V_6 ) {
F_85 ( & V_16 -> V_145 ) ;
F_28 ( V_16 , F_56 ( V_108 ) -> V_21 ) ;
F_83 ( & V_16 -> V_145 ) ;
}
F_86 ( V_120 ) ;
}
V_146:
F_85 ( & V_16 -> V_145 ) ;
return V_88 ;
}
static int
F_87 ( struct V_1 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
int V_88 = 0 ;
if ( V_22 -> V_108 )
F_55 ( V_22 -> V_108 ) ;
V_20 -> V_148 ( V_22 ) ;
if ( ! V_20 -> V_6 )
goto V_149;
F_28 ( V_16 , V_20 -> V_21 ) ;
F_83 ( & V_16 -> V_145 ) ;
F_86 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_85 ( & V_16 -> V_145 ) ;
V_149:
return V_88 ;
}
static void F_88 ( struct V_1 * V_22 )
{
struct V_20 * V_20 = F_2 ( V_22 ) ;
F_87 ( V_22 ) ;
F_89 ( V_22 ) ;
F_90 ( V_20 ) ;
}
int F_91 ( struct V_15 * V_16 , void * V_150 ,
struct V_151 * V_152 )
{
struct V_59 * V_153 = V_150 ;
struct V_154 * V_6 ;
struct V_1 * V_22 ;
struct V_20 * V_20 ;
int V_88 = 0 ;
if ( ! F_92 ( V_16 , V_155 ) )
return - V_156 ;
if ( ( V_153 -> V_61 & ( V_62 | V_68 ) ) == ( V_62 | V_68 ) )
return - V_63 ;
F_93 ( V_16 ) ;
V_6 = F_94 ( V_16 , V_153 -> V_157 , V_158 ) ;
if ( ! V_6 ) {
V_88 = - V_63 ;
goto V_146;
}
V_22 = F_95 ( V_6 ) ;
V_20 = F_2 ( V_22 ) ;
V_88 = V_20 -> V_159 ( V_22 , V_153 ) ;
V_146:
F_96 ( V_16 ) ;
return V_88 ;
}
int F_97 ( struct V_15 * V_16 , void * V_150 ,
struct V_151 * V_152 )
{
struct V_59 * V_160 = V_150 ;
struct V_154 * V_6 ;
struct V_1 * V_22 ;
struct V_20 * V_20 ;
int V_88 = 0 ;
if ( ! F_92 ( V_16 , V_155 ) )
return - V_156 ;
F_93 ( V_16 ) ;
V_6 = F_94 ( V_16 , V_160 -> V_157 , V_158 ) ;
if ( ! V_6 ) {
V_88 = - V_63 ;
goto V_146;
}
V_22 = F_95 ( V_6 ) ;
V_20 = F_2 ( V_22 ) ;
V_20 -> V_161 ( V_22 , V_160 ) ;
V_146:
F_96 ( V_16 ) ;
return V_88 ;
}
void F_98 ( struct V_1 * V_22 )
{
struct V_20 * V_20 = F_2 ( V_22 ) ;
if ( ! V_22 -> V_108 || ! V_22 -> V_4 )
return;
F_66 ( V_22 , V_22 -> V_108 , V_22 -> V_4 ,
V_20 -> V_7 , V_20 -> V_8 ,
V_20 -> V_9 , V_20 -> V_10 ,
V_20 -> V_116 , V_20 -> V_117 ,
V_20 -> V_13 , V_20 -> V_14 ) ;
}
void F_99 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_108 || ! V_22 -> V_4 )
return;
F_87 ( V_22 ) ;
}
int
F_100 ( struct V_15 * V_16 , enum V_21 V_21 , int V_22 )
{
struct V_20 * V_20 ;
unsigned long V_162 ;
const T_1 * V_163 ;
int V_164 ;
int V_88 ;
if ( F_101 ( V_16 ) -> V_165 < 5 )
return - V_156 ;
V_20 = F_102 ( sizeof( struct V_20 ) , V_166 ) ;
if ( ! V_20 )
return - V_167 ;
switch ( F_101 ( V_16 ) -> V_165 ) {
case 5 :
case 6 :
V_20 -> V_87 = true ;
V_20 -> V_143 = 16 ;
V_20 -> V_147 = F_43 ;
V_20 -> V_148 = F_54 ;
V_20 -> V_159 = F_60 ;
V_20 -> V_161 = F_64 ;
if ( F_45 ( V_16 ) ) {
V_163 = V_168 ;
V_164 = F_103 ( V_168 ) ;
} else {
V_163 = V_169 ;
V_164 = F_103 ( V_169 ) ;
}
break;
case 7 :
if ( F_104 ( V_16 ) ) {
V_20 -> V_87 = true ;
V_20 -> V_143 = 2 ;
} else {
V_20 -> V_87 = false ;
V_20 -> V_143 = 1 ;
}
if ( F_105 ( V_16 ) ) {
V_20 -> V_147 = F_1 ;
V_20 -> V_148 = F_18 ;
V_20 -> V_159 = F_19 ;
V_20 -> V_161 = F_23 ;
V_163 = V_170 ;
V_164 = F_103 ( V_170 ) ;
} else {
V_20 -> V_147 = F_24 ;
V_20 -> V_148 = F_37 ;
V_20 -> V_159 = F_38 ;
V_20 -> V_161 = F_42 ;
V_163 = V_168 ;
V_164 = F_103 ( V_168 ) ;
}
break;
default:
F_90 ( V_20 ) ;
return - V_156 ;
}
V_20 -> V_21 = V_21 ;
V_20 -> V_22 = V_22 ;
V_162 = ( 1 << V_21 ) ;
V_88 = F_106 ( V_16 , & V_20 -> V_171 , V_162 ,
& V_172 ,
V_163 , V_164 ,
false ) ;
if ( V_88 )
F_90 ( V_20 ) ;
return V_88 ;
}
