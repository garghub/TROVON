void
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
V_3 -> V_4 = V_2 -> V_4 ;
V_3 -> V_5 = V_2 -> V_5 ;
V_3 -> V_6 = V_2 -> V_6 ;
V_3 -> V_7 = V_2 -> V_7 ;
V_3 -> V_8 = V_2 -> V_8 ;
V_3 -> V_9 = V_2 -> V_9 ;
V_3 -> V_10 = V_2 -> V_10 ;
V_3 -> V_11 = V_2 -> V_11 ;
V_3 -> clock = V_2 -> clock ;
}
void
F_2 ( struct V_12 * V_12 ,
struct V_13 * V_14 ,
int V_15 )
{
struct V_1 * V_16 , * V_3 ;
int V_17 , V_18 , V_19 , V_20 ;
V_16 = & V_14 -> V_21 ;
V_3 = & V_14 -> V_3 ;
V_17 = V_18 = V_19 = V_20 = 0 ;
if ( V_3 -> V_4 == V_16 -> V_4 &&
V_3 -> V_8 == V_16 -> V_8 )
goto V_22;
switch ( V_15 ) {
case V_23 :
V_19 = V_16 -> V_4 ;
V_20 = V_16 -> V_8 ;
V_17 = ( V_3 -> V_4 - V_19 + 1 ) / 2 ;
V_18 = ( V_3 -> V_8 - V_20 + 1 ) / 2 ;
break;
case V_24 :
{
T_1 V_25 = V_3 -> V_4 * V_16 -> V_8 ;
T_1 V_26 = V_16 -> V_4 * V_3 -> V_8 ;
if ( V_25 > V_26 ) {
V_19 = V_26 / V_16 -> V_8 ;
if ( V_19 & 1 )
V_19 ++ ;
V_17 = ( V_3 -> V_4 - V_19 + 1 ) / 2 ;
V_18 = 0 ;
V_20 = V_3 -> V_8 ;
} else if ( V_25 < V_26 ) {
V_20 = V_25 / V_16 -> V_4 ;
if ( V_20 & 1 )
V_20 ++ ;
V_18 = ( V_3 -> V_8 - V_20 + 1 ) / 2 ;
V_17 = 0 ;
V_19 = V_3 -> V_4 ;
} else {
V_17 = V_18 = 0 ;
V_19 = V_3 -> V_4 ;
V_20 = V_3 -> V_8 ;
}
}
break;
case V_27 :
V_17 = V_18 = 0 ;
V_19 = V_3 -> V_4 ;
V_20 = V_3 -> V_8 ;
break;
default:
F_3 ( 1 , L_1 , V_15 ) ;
return;
}
V_22:
V_14 -> V_28 . V_29 = ( V_17 << 16 ) | V_18 ;
V_14 -> V_28 . V_30 = ( V_19 << 16 ) | V_20 ;
}
static void
F_4 ( struct V_1 * V_16 ,
int V_19 )
{
T_1 V_31 , V_32 , V_33 , V_34 ;
V_34 = V_16 -> V_35 - V_16 -> V_36 ;
V_33 = V_16 -> V_37 - V_16 -> V_38 ;
V_32 = ( V_33 - V_34 + 1 ) / 2 ;
V_31 = ( V_16 -> V_4 - V_19 + 1 ) / 2 ;
V_31 += V_31 & 1 ;
V_16 -> V_39 = V_19 ;
V_16 -> V_38 = V_19 + V_31 ;
V_16 -> V_37 = V_16 -> V_38 + V_33 ;
V_16 -> V_36 = V_16 -> V_38 + V_32 ;
V_16 -> V_35 = V_16 -> V_36 + V_34 ;
}
static void
F_5 ( struct V_1 * V_16 ,
int V_20 )
{
T_1 V_31 , V_32 , V_33 , V_34 ;
V_34 = V_16 -> V_40 - V_16 -> V_41 ;
V_33 = V_16 -> V_42 - V_16 -> V_43 ;
V_32 = ( V_33 - V_34 + 1 ) / 2 ;
V_31 = ( V_16 -> V_8 - V_20 + 1 ) / 2 ;
V_16 -> V_44 = V_20 ;
V_16 -> V_43 = V_20 + V_31 ;
V_16 -> V_42 = V_16 -> V_43 + V_33 ;
V_16 -> V_41 = V_16 -> V_43 + V_32 ;
V_16 -> V_40 = V_16 -> V_41 + V_34 ;
}
static inline T_1 F_6 ( T_1 V_45 , T_1 V_46 )
{
#define F_7 12
#define F_8 (1 << ACCURACY)
T_1 V_47 = V_45 * F_8 / V_46 ;
return ( F_8 * V_47 + F_8 / 2 ) / F_8 ;
}
void F_9 ( struct V_12 * V_12 ,
struct V_13 * V_14 ,
int V_15 )
{
struct V_48 * V_49 = V_12 -> V_50 . V_49 ;
T_1 V_51 = 0 , V_52 = 0 , V_31 = 0 ;
struct V_1 * V_16 , * V_3 ;
V_16 = & V_14 -> V_21 ;
V_3 = & V_14 -> V_3 ;
if ( V_3 -> V_4 == V_16 -> V_4 &&
V_3 -> V_8 == V_16 -> V_8 )
goto V_53;
F_10 ( V_3 , 0 ) ;
V_14 -> V_54 = true ;
switch ( V_15 ) {
case V_23 :
F_4 ( V_3 , V_16 -> V_4 ) ;
F_5 ( V_3 , V_16 -> V_8 ) ;
V_31 = V_55 ;
break;
case V_24 :
if ( F_11 ( V_49 ) -> V_56 >= 4 ) {
T_1 V_25 = V_3 -> V_4 *
V_16 -> V_8 ;
T_1 V_26 = V_16 -> V_4 *
V_3 -> V_8 ;
if ( V_25 > V_26 )
V_51 |= V_57 |
V_58 ;
else if ( V_25 < V_26 )
V_51 |= V_57 |
V_59 ;
else if ( V_3 -> V_4 != V_16 -> V_4 )
V_51 |= V_57 | V_60 ;
} else {
T_1 V_25 = V_3 -> V_4 *
V_16 -> V_8 ;
T_1 V_26 = V_16 -> V_4 *
V_3 -> V_8 ;
if ( V_25 > V_26 ) {
F_4 ( V_3 ,
V_26 /
V_16 -> V_8 ) ;
V_31 = V_55 ;
if ( V_16 -> V_8 != V_3 -> V_8 ) {
T_1 V_61 = F_6 ( V_16 -> V_8 , V_3 -> V_8 ) ;
V_52 |= ( V_61 << V_62 |
V_61 << V_63 ) ;
V_51 |= ( V_57 |
V_64 |
V_65 ) ;
}
} else if ( V_25 < V_26 ) {
F_5 ( V_3 ,
V_25 /
V_16 -> V_4 ) ;
V_31 = V_55 ;
if ( V_16 -> V_4 != V_3 -> V_4 ) {
T_1 V_61 = F_6 ( V_16 -> V_4 , V_3 -> V_4 ) ;
V_52 |= ( V_61 << V_62 |
V_61 << V_63 ) ;
V_51 |= ( V_57 |
V_64 |
V_65 ) ;
}
} else {
V_51 |= ( V_57 |
V_66 | V_67 |
V_64 |
V_65 ) ;
}
}
break;
case V_27 :
if ( V_16 -> V_8 != V_3 -> V_8 ||
V_16 -> V_4 != V_3 -> V_4 ) {
V_51 |= V_57 ;
if ( F_11 ( V_49 ) -> V_56 >= 4 )
V_51 |= V_60 ;
else
V_51 |= ( V_66 |
V_64 |
V_67 |
V_65 ) ;
}
break;
default:
F_3 ( 1 , L_1 , V_15 ) ;
return;
}
if ( F_11 ( V_49 ) -> V_56 >= 4 )
V_51 |= ( ( V_12 -> V_68 << V_69 ) |
V_70 ) ;
V_53:
if ( ( V_51 & V_57 ) == 0 ) {
V_51 = 0 ;
V_52 = 0 ;
}
if ( F_11 ( V_49 ) -> V_56 < 4 && V_14 -> V_71 == 18 )
V_51 |= V_72 ;
V_14 -> V_73 . V_74 = V_51 ;
V_14 -> V_73 . V_75 = V_52 ;
V_14 -> V_73 . V_76 = V_31 ;
}
static int F_12 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
if ( F_11 ( V_49 ) -> V_56 >= 4 )
return F_13 ( V_80 ) & V_81 ;
if ( F_14 ( V_49 ) )
return F_13 ( V_82 ) & V_83 ;
return 0 ;
}
static T_1 F_15 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
T_1 V_84 ;
F_16 ( ! F_17 ( & V_78 -> V_85 . V_86 ) ) ;
if ( F_18 ( V_78 -> V_49 ) ) {
V_84 = F_13 ( V_87 ) ;
if ( V_78 -> V_88 . V_89 == 0 ) {
V_78 -> V_88 . V_89 = V_84 ;
} else if ( V_84 == 0 ) {
V_84 = V_78 -> V_88 . V_89 ;
F_19 ( V_87 , V_84 ) ;
}
} else {
V_84 = F_13 ( V_82 ) ;
if ( V_78 -> V_88 . V_90 == 0 ) {
V_78 -> V_88 . V_90 = V_84 ;
if ( F_11 ( V_49 ) -> V_56 >= 4 )
V_78 -> V_88 . V_89 =
F_13 ( V_80 ) ;
} else if ( V_84 == 0 ) {
V_84 = V_78 -> V_88 . V_90 ;
F_19 ( V_82 , V_84 ) ;
if ( F_11 ( V_49 ) -> V_56 >= 4 )
F_19 ( V_80 ,
V_78 -> V_88 . V_89 ) ;
}
}
return V_84 ;
}
static T_1 F_20 ( struct V_48 * V_49 )
{
T_1 V_91 ;
V_91 = F_15 ( V_49 ) ;
if ( F_18 ( V_49 ) ) {
V_91 >>= 16 ;
} else {
if ( F_11 ( V_49 ) -> V_56 < 4 )
V_91 >>= 17 ;
else
V_91 >>= 16 ;
if ( F_12 ( V_49 ) )
V_91 *= 0xff ;
}
F_21 ( L_2 , V_91 ) ;
return V_91 ;
}
static T_1 F_22 ( struct V_48 * V_49 , T_1 V_84 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
if ( V_92 < 0 )
return V_84 ;
if ( V_92 > 0 ||
V_78 -> V_93 & V_94 ) {
T_1 V_91 = F_20 ( V_49 ) ;
if ( V_91 )
return V_91 - V_84 ;
}
return V_84 ;
}
static T_1 F_23 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
T_1 V_84 ;
unsigned long V_95 ;
F_24 ( & V_78 -> V_85 . V_86 , V_95 ) ;
if ( F_18 ( V_49 ) ) {
V_84 = F_13 ( V_96 ) & V_97 ;
} else {
V_84 = F_13 ( V_82 ) & V_97 ;
if ( F_11 ( V_49 ) -> V_56 < 4 )
V_84 >>= 1 ;
if ( F_12 ( V_49 ) ) {
T_2 V_98 ;
F_25 ( V_49 -> V_99 , V_100 , & V_98 ) ;
V_84 *= V_98 ;
}
}
V_84 = F_22 ( V_49 , V_84 ) ;
F_26 ( & V_78 -> V_85 . V_86 , V_95 ) ;
F_21 ( L_3 , V_84 ) ;
return V_84 ;
}
static void F_27 ( struct V_48 * V_49 , T_1 V_101 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
T_1 V_84 = F_13 ( V_96 ) & ~ V_97 ;
F_19 ( V_96 , V_84 | V_101 ) ;
}
static void F_28 ( struct V_48 * V_49 , T_1 V_101 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
T_1 V_102 ;
F_21 ( L_4 , V_101 ) ;
V_101 = F_22 ( V_49 , V_101 ) ;
if ( F_18 ( V_49 ) )
return F_27 ( V_49 , V_101 ) ;
if ( F_12 ( V_49 ) ) {
T_1 V_91 = F_20 ( V_49 ) ;
T_2 V_98 ;
if ( ! V_91 )
V_91 = 1 ;
V_98 = V_101 * 0xfe / V_91 + 1 ;
V_101 /= V_98 ;
F_29 ( V_49 -> V_99 , V_100 , V_98 ) ;
}
V_102 = F_13 ( V_82 ) ;
if ( F_11 ( V_49 ) -> V_56 < 4 )
V_101 <<= 1 ;
V_102 &= ~ V_97 ;
F_19 ( V_82 , V_102 | V_101 ) ;
}
void F_30 ( struct V_48 * V_49 , T_1 V_101 , T_1 V_91 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
T_1 V_103 ;
unsigned long V_95 ;
F_24 ( & V_78 -> V_85 . V_86 , V_95 ) ;
V_103 = F_20 ( V_49 ) ;
if ( ! V_103 ) {
goto V_53;
}
if ( V_103 < V_91 )
V_101 = V_101 * V_103 / V_91 ;
else
V_101 = V_103 / V_91 * V_101 ;
V_78 -> V_85 . V_101 = V_101 ;
if ( V_78 -> V_85 . V_104 )
V_78 -> V_85 . V_104 -> V_105 . V_106 = V_101 ;
if ( V_78 -> V_85 . V_107 )
F_28 ( V_49 , V_101 ) ;
V_53:
F_26 ( & V_78 -> V_85 . V_86 , V_95 ) ;
}
void F_31 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
unsigned long V_95 ;
if ( V_49 -> V_108 == V_109 ) {
F_21 ( L_5 ) ;
return;
}
F_24 ( & V_78 -> V_85 . V_86 , V_95 ) ;
V_78 -> V_85 . V_107 = false ;
F_28 ( V_49 , 0 ) ;
if ( F_11 ( V_49 ) -> V_56 >= 4 ) {
T_3 V_110 , V_102 ;
V_110 = F_18 ( V_49 ) ? V_111 : V_80 ;
F_19 ( V_110 , F_13 ( V_110 ) & ~ V_112 ) ;
if ( F_18 ( V_49 ) ) {
V_102 = F_13 ( V_113 ) ;
V_102 &= ~ V_114 ;
F_19 ( V_113 , V_102 ) ;
}
}
F_26 ( & V_78 -> V_85 . V_86 , V_95 ) ;
}
void F_32 ( struct V_48 * V_49 ,
enum V_68 V_68 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
enum V_115 V_116 =
F_33 ( V_78 , V_68 ) ;
unsigned long V_95 ;
F_24 ( & V_78 -> V_85 . V_86 , V_95 ) ;
if ( V_78 -> V_85 . V_101 == 0 ) {
V_78 -> V_85 . V_101 = F_20 ( V_49 ) ;
if ( V_78 -> V_85 . V_104 )
V_78 -> V_85 . V_104 -> V_105 . V_106 =
V_78 -> V_85 . V_101 ;
}
if ( F_11 ( V_49 ) -> V_56 >= 4 ) {
T_3 V_110 , V_102 ;
V_110 = F_18 ( V_49 ) ? V_111 : V_80 ;
V_102 = F_13 ( V_110 ) ;
if ( V_102 & V_112 )
goto V_117;
if ( F_11 ( V_49 ) -> V_118 == 3 )
V_102 &= ~ V_119 ;
else
V_102 &= ~ V_120 ;
if ( V_116 == V_121 )
V_102 |= V_122 ;
else
V_102 |= F_34 ( V_116 ) ;
V_102 &= ~ V_112 ;
F_19 ( V_110 , V_102 ) ;
F_35 ( V_110 ) ;
F_19 ( V_110 , V_102 | V_112 ) ;
if ( F_18 ( V_49 ) &&
! ( V_78 -> V_93 & V_123 ) ) {
V_102 = F_13 ( V_113 ) ;
V_102 |= V_114 ;
V_102 &= ~ V_124 ;
F_19 ( V_113 , V_102 ) ;
}
}
V_117:
V_78 -> V_85 . V_107 = true ;
F_28 ( V_49 , V_78 -> V_85 . V_101 ) ;
F_26 ( & V_78 -> V_85 . V_86 , V_95 ) ;
}
static void F_36 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
V_78 -> V_85 . V_101 = F_23 ( V_49 ) ;
V_78 -> V_85 . V_107 = V_78 -> V_85 . V_101 != 0 ;
}
enum V_125
F_37 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
if ( ! V_126 && V_78 -> V_127 . V_128 ) {
return F_38 ( V_78 -> V_127 . V_128 ) & 0x1 ?
V_129 :
V_130 ;
}
switch ( V_126 ) {
case - 2 :
return V_129 ;
case - 1 :
return V_130 ;
default:
return V_131 ;
}
}
static int F_39 ( struct V_132 * V_133 )
{
struct V_48 * V_49 = F_40 ( V_133 ) ;
F_30 ( V_49 , V_133 -> V_105 . V_106 ,
V_133 -> V_105 . V_134 ) ;
return 0 ;
}
static int F_41 ( struct V_132 * V_133 )
{
struct V_48 * V_49 = F_40 ( V_133 ) ;
return F_23 ( V_49 ) ;
}
int F_42 ( struct V_135 * V_136 )
{
struct V_48 * V_49 = V_136 -> V_49 ;
struct V_77 * V_78 = V_49 -> V_79 ;
struct V_137 V_105 ;
unsigned long V_95 ;
F_36 ( V_49 ) ;
if ( F_43 ( V_78 -> V_85 . V_104 ) )
return - V_138 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . type = V_139 ;
V_105 . V_106 = V_78 -> V_85 . V_101 ;
F_24 ( & V_78 -> V_85 . V_86 , V_95 ) ;
V_105 . V_134 = F_20 ( V_49 ) ;
F_26 ( & V_78 -> V_85 . V_86 , V_95 ) ;
if ( V_105 . V_134 == 0 ) {
F_21 ( L_6 ) ;
return - V_138 ;
}
V_78 -> V_85 . V_104 =
F_44 ( L_7 ,
& V_136 -> V_140 , V_49 ,
& V_141 , & V_105 ) ;
if ( F_45 ( V_78 -> V_85 . V_104 ) ) {
F_46 ( L_8 ,
F_47 ( V_78 -> V_85 . V_104 ) ) ;
V_78 -> V_85 . V_104 = NULL ;
return - V_138 ;
}
return 0 ;
}
void F_48 ( struct V_48 * V_49 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
if ( V_78 -> V_85 . V_104 ) {
F_49 ( V_78 -> V_85 . V_104 ) ;
V_78 -> V_85 . V_104 = NULL ;
}
}
int F_42 ( struct V_135 * V_136 )
{
F_36 ( V_136 -> V_49 ) ;
return 0 ;
}
void F_48 ( struct V_48 * V_49 )
{
return;
}
int F_50 ( struct V_142 * V_143 ,
struct V_1 * V_2 )
{
V_143 -> V_2 = V_2 ;
return 0 ;
}
void F_51 ( struct V_142 * V_143 )
{
struct V_144 * V_144 =
F_52 ( V_143 , struct V_144 , V_143 ) ;
if ( V_143 -> V_2 )
F_53 ( V_144 -> V_50 . V_49 , V_143 -> V_2 ) ;
}
