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
F_7 ( V_16 , V_21 , V_9 , V_26 ) ;
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
F_7 ( V_16 , V_21 , V_9 , V_26 ) ;
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
F_7 ( V_16 , V_21 , V_9 , V_26 ) ;
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
static int
F_65 ( struct V_1 * V_22 , struct V_107 * V_108 ,
struct V_3 * V_4 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_115 , T_1 V_116 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_109 * V_109 = F_56 ( V_108 ) ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
struct V_117 * V_118 ;
struct V_5 * V_6 , * V_119 ;
int V_21 = V_20 -> V_21 ;
enum V_120 V_121 = F_66 ( V_18 ,
V_21 ) ;
int V_88 = 0 ;
int V_11 = V_115 >> 16 , V_12 = V_116 >> 16 ;
int V_122 = V_108 -> V_123 . V_124 , V_125 = V_108 -> V_123 . V_126 ;
bool V_127 = false ;
V_118 = F_67 ( V_4 ) ;
V_6 = V_118 -> V_6 ;
V_119 = V_20 -> V_6 ;
V_20 -> V_7 = V_7 ;
V_20 -> V_8 = V_8 ;
V_20 -> V_9 = V_9 ;
V_20 -> V_10 = V_10 ;
V_20 -> V_115 = V_115 ;
V_20 -> V_116 = V_116 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_14 = V_14 ;
V_13 = V_13 >> 16 ;
V_14 = V_14 >> 16 ;
if ( ! ( F_4 ( F_68 ( V_121 ) ) & V_128 ) )
return - V_63 ;
if ( V_7 >= V_122 || V_8 >= V_125 )
return - V_63 ;
if ( V_20 -> V_21 != V_109 -> V_21 )
return - V_63 ;
switch ( V_6 -> V_54 ) {
case V_55 :
case V_129 :
break;
default:
return - V_63 ;
}
if ( ( V_7 < 0 ) && ( ( V_7 + V_9 ) > 0 ) ) {
V_9 += V_7 ;
V_7 = 0 ;
}
if ( ( V_7 + V_9 ) <= 0 )
goto V_130;
if ( ( V_7 + V_9 ) > V_122 )
V_9 = V_122 - V_7 ;
if ( ( V_8 < 0 ) && ( ( V_8 + V_10 ) > 0 ) ) {
V_10 += V_8 ;
V_8 = 0 ;
}
if ( ( V_8 + V_10 ) <= 0 )
goto V_130;
if ( V_8 + V_10 > V_125 )
V_10 = V_125 - V_8 ;
if ( ! V_9 || ! V_10 )
goto V_130;
if ( ! V_20 -> V_87 && ( V_9 != V_13 || V_10 != V_14 ) )
return - V_63 ;
if ( ( ( V_13 * V_14 ) / ( V_9 * V_10 ) ) > V_20 -> V_131 )
return - V_63 ;
if ( ( V_7 == 0 ) && ( V_8 == 0 ) &&
( V_9 == V_122 ) && ( V_10 == V_125 ) )
V_127 = true ;
F_69 ( & V_16 -> V_132 ) ;
V_88 = F_70 ( V_16 , V_6 , NULL ) ;
if ( V_88 )
goto V_133;
V_20 -> V_6 = V_6 ;
if ( ! V_127 )
F_55 ( V_108 ) ;
V_20 -> V_134 ( V_22 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_127 )
F_59 ( V_108 ) ;
if ( V_119 ) {
if ( V_119 != V_6 ) {
F_71 ( & V_16 -> V_132 ) ;
F_28 ( V_16 , F_56 ( V_108 ) -> V_21 ) ;
F_69 ( & V_16 -> V_132 ) ;
}
F_72 ( V_119 ) ;
}
V_133:
F_71 ( & V_16 -> V_132 ) ;
V_130:
return V_88 ;
}
static int
F_73 ( struct V_1 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_20 * V_20 = F_2 ( V_22 ) ;
int V_88 = 0 ;
if ( V_22 -> V_108 )
F_55 ( V_22 -> V_108 ) ;
V_20 -> V_135 ( V_22 ) ;
if ( ! V_20 -> V_6 )
goto V_130;
F_28 ( V_16 , V_20 -> V_21 ) ;
F_69 ( & V_16 -> V_132 ) ;
F_72 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_71 ( & V_16 -> V_132 ) ;
V_130:
return V_88 ;
}
static void F_74 ( struct V_1 * V_22 )
{
struct V_20 * V_20 = F_2 ( V_22 ) ;
F_73 ( V_22 ) ;
F_75 ( V_22 ) ;
F_76 ( V_20 ) ;
}
int F_77 ( struct V_15 * V_16 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_59 * V_139 = V_136 ;
struct V_140 * V_6 ;
struct V_1 * V_22 ;
struct V_20 * V_20 ;
int V_88 = 0 ;
if ( ! F_78 ( V_16 , V_141 ) )
return - V_142 ;
if ( ( V_139 -> V_61 & ( V_62 | V_68 ) ) == ( V_62 | V_68 ) )
return - V_63 ;
F_79 ( V_16 ) ;
V_6 = F_80 ( V_16 , V_139 -> V_143 , V_144 ) ;
if ( ! V_6 ) {
V_88 = - V_63 ;
goto V_133;
}
V_22 = F_81 ( V_6 ) ;
V_20 = F_2 ( V_22 ) ;
V_88 = V_20 -> V_145 ( V_22 , V_139 ) ;
V_133:
F_82 ( V_16 ) ;
return V_88 ;
}
int F_83 ( struct V_15 * V_16 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_59 * V_146 = V_136 ;
struct V_140 * V_6 ;
struct V_1 * V_22 ;
struct V_20 * V_20 ;
int V_88 = 0 ;
if ( ! F_78 ( V_16 , V_141 ) )
return - V_142 ;
F_79 ( V_16 ) ;
V_6 = F_80 ( V_16 , V_146 -> V_143 , V_144 ) ;
if ( ! V_6 ) {
V_88 = - V_63 ;
goto V_133;
}
V_22 = F_81 ( V_6 ) ;
V_20 = F_2 ( V_22 ) ;
V_20 -> V_147 ( V_22 , V_146 ) ;
V_133:
F_82 ( V_16 ) ;
return V_88 ;
}
void F_84 ( struct V_1 * V_22 )
{
struct V_20 * V_20 = F_2 ( V_22 ) ;
if ( ! V_22 -> V_108 || ! V_22 -> V_4 )
return;
F_65 ( V_22 , V_22 -> V_108 , V_22 -> V_4 ,
V_20 -> V_7 , V_20 -> V_8 ,
V_20 -> V_9 , V_20 -> V_10 ,
V_20 -> V_115 , V_20 -> V_116 ,
V_20 -> V_13 , V_20 -> V_14 ) ;
}
int
F_85 ( struct V_15 * V_16 , enum V_21 V_21 , int V_22 )
{
struct V_20 * V_20 ;
unsigned long V_148 ;
const T_1 * V_149 ;
int V_150 ;
int V_88 ;
if ( F_86 ( V_16 ) -> V_151 < 5 )
return - V_142 ;
V_20 = F_87 ( sizeof( struct V_20 ) , V_152 ) ;
if ( ! V_20 )
return - V_153 ;
switch ( F_86 ( V_16 ) -> V_151 ) {
case 5 :
case 6 :
V_20 -> V_87 = true ;
V_20 -> V_131 = 16 ;
V_20 -> V_134 = F_43 ;
V_20 -> V_135 = F_54 ;
V_20 -> V_145 = F_60 ;
V_20 -> V_147 = F_64 ;
if ( F_45 ( V_16 ) ) {
V_149 = V_154 ;
V_150 = F_88 ( V_154 ) ;
} else {
V_149 = V_155 ;
V_150 = F_88 ( V_155 ) ;
}
break;
case 7 :
if ( F_26 ( V_16 ) || F_89 ( V_16 ) )
V_20 -> V_87 = false ;
else
V_20 -> V_87 = true ;
if ( F_89 ( V_16 ) ) {
V_20 -> V_131 = 1 ;
V_20 -> V_134 = F_1 ;
V_20 -> V_135 = F_18 ;
V_20 -> V_145 = F_19 ;
V_20 -> V_147 = F_23 ;
V_149 = V_156 ;
V_150 = F_88 ( V_156 ) ;
} else {
V_20 -> V_131 = 2 ;
V_20 -> V_134 = F_24 ;
V_20 -> V_135 = F_37 ;
V_20 -> V_145 = F_38 ;
V_20 -> V_147 = F_42 ;
V_149 = V_154 ;
V_150 = F_88 ( V_154 ) ;
}
break;
default:
F_76 ( V_20 ) ;
return - V_142 ;
}
V_20 -> V_21 = V_21 ;
V_20 -> V_22 = V_22 ;
V_148 = ( 1 << V_21 ) ;
V_88 = F_90 ( V_16 , & V_20 -> V_157 , V_148 ,
& V_158 ,
V_149 , V_150 ,
false ) ;
if ( V_88 )
F_76 ( V_20 ) ;
return V_88 ;
}
