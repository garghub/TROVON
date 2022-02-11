static int F_1 ( const struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 -> V_4 )
return 1 ;
return F_2 ( V_3 * V_2 -> V_5 , 1000 * V_2 -> V_4 ) ;
}
static bool F_3 ( struct V_6 * V_7 , T_1 * V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 . V_10 ;
const struct V_1 * V_2 = & V_7 -> V_12 . V_13 ;
enum V_14 V_14 = V_7 -> V_14 ;
long V_15 = F_4 ( 1 ) ;
int V_16 , V_17 , V_18 , V_19 ;
F_5 ( V_20 ) ;
F_6 ( ! F_7 ( & V_7 -> V_11 . V_21 ) ) ;
V_19 = V_2 -> V_22 ;
if ( V_2 -> V_23 & V_24 )
V_19 = F_2 ( V_19 , 2 ) ;
V_17 = V_19 - F_1 ( V_2 , 100 ) ;
V_18 = V_19 - 1 ;
if ( V_17 <= 0 || V_18 <= 0 )
return false ;
if ( F_6 ( F_8 ( V_10 , V_14 ) ) )
return false ;
F_9 () ;
F_10 ( V_7 , V_17 , V_18 ) ;
for (; ; ) {
F_11 ( & V_7 -> V_25 , & V_20 , V_26 ) ;
V_16 = F_12 ( V_7 ) ;
if ( V_16 < V_17 || V_16 > V_18 )
break;
if ( V_15 <= 0 ) {
F_13 ( L_1 ,
F_14 ( V_7 -> V_14 ) ) ;
break;
}
F_15 () ;
V_15 = F_16 ( V_15 ) ;
F_9 () ;
}
F_17 ( & V_7 -> V_25 , & V_20 ) ;
F_18 ( V_10 , V_14 ) ;
* V_8 = V_10 -> V_27 -> V_28 ( V_10 , V_14 ) ;
F_19 ( V_7 , V_17 , V_18 , * V_8 ) ;
return true ;
}
static void F_20 ( struct V_6 * V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 . V_10 ;
enum V_14 V_14 = V_7 -> V_14 ;
T_2 V_29 = V_10 -> V_27 -> V_28 ( V_10 , V_14 ) ;
F_21 ( V_7 , V_29 ) ;
F_15 () ;
if ( V_8 != V_29 )
F_13 ( L_2 ,
F_14 ( V_14 ) , V_8 , V_29 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_11 . V_10 -> V_32 ;
int V_33 = F_23 ( V_7 -> V_34 ) ;
if ( V_7 -> V_35 )
F_24 ( V_33 , F_25 ( V_33 ) | V_36 ) ;
else
F_24 ( V_33 , F_25 ( V_33 ) & ~ V_36 ) ;
}
static void
F_26 ( struct V_37 * V_38 , struct V_39 * V_7 ,
struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 , int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
T_1 V_48 , T_1 V_49 ,
T_1 V_50 , T_1 V_51 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_38 ) ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
int V_14 = V_52 -> V_14 ;
int V_34 = V_52 -> V_34 ;
T_2 V_53 ;
unsigned long V_54 , V_55 ;
int V_56 = F_29 ( V_41 -> V_57 , 0 ) ;
T_2 V_8 ;
bool V_58 ;
V_53 = F_25 ( F_30 ( V_14 , V_34 ) ) ;
V_53 &= ~ V_59 ;
V_53 &= ~ V_60 ;
V_53 &= ~ V_61 ;
switch ( V_41 -> V_57 ) {
case V_62 :
V_53 |= V_63 | V_64 ;
break;
case V_65 :
V_53 |= V_63 | V_66 ;
break;
case V_67 :
V_53 |= V_63 | V_68 ;
break;
case V_69 :
V_53 |= V_63 | V_70 ;
break;
case V_71 :
V_53 |= V_72 ;
break;
case V_73 :
V_53 |= V_74 ;
break;
case V_75 :
V_53 |= V_76 ;
break;
case V_77 :
V_53 |= V_78 ;
break;
case V_79 :
V_53 |= V_80 ;
break;
case V_81 :
V_53 |= V_82 ;
break;
case V_83 :
V_53 |= V_84 ;
break;
default:
F_31 () ;
break;
}
V_53 |= V_85 ;
if ( V_43 -> V_86 != V_87 )
V_53 |= V_61 ;
V_53 |= V_88 ;
F_32 ( V_38 , V_7 , V_50 , V_56 , true ,
V_50 != V_46 || V_51 != V_47 ) ;
V_50 -- ;
V_51 -- ;
V_46 -- ;
V_47 -- ;
V_55 = V_49 * V_41 -> V_89 [ 0 ] + V_48 * V_56 ;
V_54 = F_33 ( & V_48 , & V_49 ,
V_43 -> V_86 ,
V_56 ,
V_41 -> V_89 [ 0 ] ) ;
V_55 -= V_54 ;
V_58 = F_3 ( V_6 , & V_8 ) ;
F_22 ( V_6 ) ;
F_24 ( F_34 ( V_14 , V_34 ) , V_41 -> V_89 [ 0 ] ) ;
F_24 ( F_35 ( V_14 , V_34 ) , ( V_45 << 16 ) | V_44 ) ;
if ( V_43 -> V_86 != V_87 )
F_24 ( F_36 ( V_14 , V_34 ) , ( V_49 << 16 ) | V_48 ) ;
else
F_24 ( F_37 ( V_14 , V_34 ) , V_55 ) ;
F_24 ( F_38 ( V_14 , V_34 ) , ( V_47 << 16 ) | V_46 ) ;
F_24 ( F_30 ( V_14 , V_34 ) , V_53 ) ;
F_24 ( F_39 ( V_14 , V_34 ) , F_40 ( V_43 ) +
V_54 ) ;
F_41 ( V_31 , V_6 -> V_34 ) ;
if ( V_58 )
F_20 ( V_6 , V_8 ) ;
}
static void
F_42 ( struct V_37 * V_38 , struct V_39 * V_7 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_38 ) ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
int V_14 = V_52 -> V_14 ;
int V_34 = V_52 -> V_34 ;
T_2 V_8 ;
bool V_58 ;
V_58 = F_3 ( V_6 , & V_8 ) ;
F_22 ( V_6 ) ;
F_24 ( F_30 ( V_14 , V_34 ) , F_25 ( F_30 ( V_14 , V_34 ) ) &
~ V_88 ) ;
F_24 ( F_39 ( V_14 , V_34 ) , 0 ) ;
F_41 ( V_31 , V_6 -> V_34 ) ;
if ( V_58 )
F_20 ( V_6 , V_8 ) ;
F_32 ( V_38 , V_7 , 0 , 0 , false , false ) ;
}
static int
F_43 ( struct V_37 * V_38 ,
struct V_90 * V_91 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_38 ) ;
int V_14 = V_52 -> V_14 ;
int V_34 = V_52 -> V_34 ;
T_2 V_53 ;
if ( V_91 -> V_23 & V_92 )
return - V_93 ;
F_24 ( F_44 ( V_14 , V_34 ) , V_91 -> V_94 ) ;
F_24 ( F_45 ( V_14 , V_34 ) , V_91 -> V_95 ) ;
F_24 ( F_46 ( V_14 , V_34 ) , V_91 -> V_96 ) ;
V_53 = F_25 ( F_30 ( V_14 , V_34 ) ) ;
V_53 &= ~ V_97 ;
if ( V_91 -> V_23 & V_98 )
V_53 |= V_97 ;
F_24 ( F_30 ( V_14 , V_34 ) , V_53 ) ;
F_47 ( F_46 ( V_14 , V_34 ) ) ;
return 0 ;
}
static void
F_48 ( struct V_37 * V_38 ,
struct V_90 * V_91 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_38 ) ;
int V_14 = V_52 -> V_14 ;
int V_34 = V_52 -> V_34 ;
T_2 V_53 ;
V_91 -> V_94 = F_25 ( F_44 ( V_14 , V_34 ) ) ;
V_91 -> V_95 = F_25 ( F_45 ( V_14 , V_34 ) ) ;
V_91 -> V_96 = F_25 ( F_46 ( V_14 , V_34 ) ) ;
V_53 = F_25 ( F_30 ( V_14 , V_34 ) ) ;
if ( V_53 & V_97 )
V_91 -> V_23 = V_98 ;
else
V_91 -> V_23 = V_99 ;
}
static void
F_49 ( struct V_37 * V_34 , struct V_39 * V_7 ,
struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 , int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
T_1 V_48 , T_1 V_49 ,
T_1 V_50 , T_1 V_51 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_34 ) ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
int V_14 = V_52 -> V_14 ;
T_2 V_53 , V_100 = 0 ;
unsigned long V_54 , V_55 ;
int V_56 = F_29 ( V_41 -> V_57 , 0 ) ;
T_2 V_8 ;
bool V_58 ;
V_53 = F_25 ( F_50 ( V_14 ) ) ;
V_53 &= ~ V_101 ;
V_53 &= ~ V_102 ;
V_53 &= ~ V_103 ;
V_53 &= ~ V_104 ;
switch ( V_41 -> V_57 ) {
case V_81 :
V_53 |= V_105 | V_102 ;
break;
case V_73 :
V_53 |= V_105 ;
break;
case V_62 :
V_53 |= V_106 | V_107 ;
break;
case V_65 :
V_53 |= V_106 | V_108 ;
break;
case V_67 :
V_53 |= V_106 | V_109 ;
break;
case V_69 :
V_53 |= V_106 | V_110 ;
break;
default:
F_31 () ;
}
V_53 |= V_111 ;
if ( V_43 -> V_86 != V_87 )
V_53 |= V_104 ;
if ( F_51 ( V_10 ) || F_52 ( V_10 ) )
V_53 &= ~ V_112 ;
else
V_53 |= V_112 ;
V_53 |= V_113 ;
if ( F_51 ( V_10 ) || F_52 ( V_10 ) )
V_53 |= V_114 ;
F_32 ( V_34 , V_7 , V_50 , V_56 , true ,
V_50 != V_46 || V_51 != V_47 ) ;
V_50 -- ;
V_51 -- ;
V_46 -- ;
V_47 -- ;
if ( V_46 != V_50 || V_47 != V_51 )
V_100 = V_115 | ( V_50 << 16 ) | V_51 ;
V_55 = V_49 * V_41 -> V_89 [ 0 ] + V_48 * V_56 ;
V_54 =
F_33 ( & V_48 , & V_49 , V_43 -> V_86 ,
V_56 , V_41 -> V_89 [ 0 ] ) ;
V_55 -= V_54 ;
V_58 = F_3 ( V_6 , & V_8 ) ;
F_22 ( V_6 ) ;
F_24 ( F_53 ( V_14 ) , V_41 -> V_89 [ 0 ] ) ;
F_24 ( F_54 ( V_14 ) , ( V_45 << 16 ) | V_44 ) ;
if ( F_51 ( V_10 ) || F_52 ( V_10 ) )
F_24 ( F_55 ( V_14 ) , ( V_49 << 16 ) | V_48 ) ;
else if ( V_43 -> V_86 != V_87 )
F_24 ( F_56 ( V_14 ) , ( V_49 << 16 ) | V_48 ) ;
else
F_24 ( F_57 ( V_14 ) , V_55 ) ;
F_24 ( F_58 ( V_14 ) , ( V_47 << 16 ) | V_46 ) ;
if ( V_52 -> V_116 )
F_24 ( F_59 ( V_14 ) , V_100 ) ;
F_24 ( F_50 ( V_14 ) , V_53 ) ;
F_24 ( F_60 ( V_14 ) ,
F_40 ( V_43 ) + V_54 ) ;
F_41 ( V_31 , V_6 -> V_34 ) ;
if ( V_58 )
F_20 ( V_6 , V_8 ) ;
}
static void
F_61 ( struct V_37 * V_34 , struct V_39 * V_7 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_34 ) ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
int V_14 = V_52 -> V_14 ;
T_2 V_8 ;
bool V_58 ;
V_58 = F_3 ( V_6 , & V_8 ) ;
F_22 ( V_6 ) ;
F_24 ( F_50 ( V_14 ) , F_25 ( F_50 ( V_14 ) ) & ~ V_113 ) ;
if ( V_52 -> V_116 )
F_24 ( F_59 ( V_14 ) , 0 ) ;
F_24 ( F_60 ( V_14 ) , 0 ) ;
F_41 ( V_31 , V_6 -> V_34 ) ;
if ( V_58 )
F_20 ( V_6 , V_8 ) ;
F_62 ( V_10 , V_14 ) ;
F_32 ( V_34 , V_7 , 0 , 0 , false , false ) ;
}
static int
F_63 ( struct V_37 * V_34 ,
struct V_90 * V_91 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 ;
T_2 V_53 ;
int V_117 = 0 ;
V_52 = F_27 ( V_34 ) ;
F_24 ( F_64 ( V_52 -> V_14 ) , V_91 -> V_94 ) ;
F_24 ( F_65 ( V_52 -> V_14 ) , V_91 -> V_95 ) ;
F_24 ( F_66 ( V_52 -> V_14 ) , V_91 -> V_96 ) ;
V_53 = F_25 ( F_50 ( V_52 -> V_14 ) ) ;
V_53 &= ~ ( V_118 | V_119 ) ;
if ( V_91 -> V_23 & V_92 )
V_53 |= V_119 ;
else if ( V_91 -> V_23 & V_98 )
V_53 |= V_118 ;
F_24 ( F_50 ( V_52 -> V_14 ) , V_53 ) ;
F_47 ( F_66 ( V_52 -> V_14 ) ) ;
return V_117 ;
}
static void
F_67 ( struct V_37 * V_34 , struct V_90 * V_91 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 ;
T_2 V_53 ;
V_52 = F_27 ( V_34 ) ;
V_91 -> V_94 = F_25 ( F_64 ( V_52 -> V_14 ) ) ;
V_91 -> V_95 = F_25 ( F_65 ( V_52 -> V_14 ) ) ;
V_91 -> V_96 = F_25 ( F_66 ( V_52 -> V_14 ) ) ;
V_91 -> V_23 = 0 ;
V_53 = F_25 ( F_50 ( V_52 -> V_14 ) ) ;
if ( V_53 & V_119 )
V_91 -> V_23 = V_92 ;
else if ( V_53 & V_118 )
V_91 -> V_23 = V_98 ;
else
V_91 -> V_23 = V_99 ;
}
static void
F_68 ( struct V_37 * V_34 , struct V_39 * V_7 ,
struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 , int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
T_1 V_48 , T_1 V_49 ,
T_1 V_50 , T_1 V_51 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_34 ) ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
int V_14 = V_52 -> V_14 ;
unsigned long V_120 , V_55 ;
T_2 V_121 , V_122 ;
int V_56 = F_29 ( V_41 -> V_57 , 0 ) ;
T_2 V_8 ;
bool V_58 ;
V_121 = F_25 ( F_69 ( V_14 ) ) ;
V_121 &= ~ V_123 ;
V_121 &= ~ V_124 ;
V_121 &= ~ V_125 ;
V_121 &= ~ V_126 ;
switch ( V_41 -> V_57 ) {
case V_81 :
V_121 |= V_127 | V_124 ;
break;
case V_73 :
V_121 |= V_127 ;
break;
case V_62 :
V_121 |= V_128 | V_129 ;
break;
case V_65 :
V_121 |= V_128 | V_130 ;
break;
case V_67 :
V_121 |= V_128 | V_131 ;
break;
case V_69 :
V_121 |= V_128 | V_132 ;
break;
default:
F_31 () ;
}
V_121 |= V_133 ;
if ( V_43 -> V_86 != V_87 )
V_121 |= V_126 ;
if ( F_70 ( V_10 ) )
V_121 |= V_134 ;
V_121 |= V_135 ;
F_32 ( V_34 , V_7 , V_50 , V_56 , true ,
V_50 != V_46 || V_51 != V_47 ) ;
V_50 -- ;
V_51 -- ;
V_46 -- ;
V_47 -- ;
V_122 = 0 ;
if ( V_46 != V_50 || V_47 != V_51 )
V_122 = V_136 | ( V_50 << 16 ) | V_51 ;
V_55 = V_49 * V_41 -> V_89 [ 0 ] + V_48 * V_56 ;
V_120 =
F_33 ( & V_48 , & V_49 , V_43 -> V_86 ,
V_56 , V_41 -> V_89 [ 0 ] ) ;
V_55 -= V_120 ;
V_58 = F_3 ( V_6 , & V_8 ) ;
F_22 ( V_6 ) ;
F_24 ( F_71 ( V_14 ) , V_41 -> V_89 [ 0 ] ) ;
F_24 ( F_72 ( V_14 ) , ( V_45 << 16 ) | V_44 ) ;
if ( V_43 -> V_86 != V_87 )
F_24 ( F_73 ( V_14 ) , ( V_49 << 16 ) | V_48 ) ;
else
F_24 ( F_74 ( V_14 ) , V_55 ) ;
F_24 ( F_75 ( V_14 ) , ( V_47 << 16 ) | V_46 ) ;
F_24 ( F_76 ( V_14 ) , V_122 ) ;
F_24 ( F_69 ( V_14 ) , V_121 ) ;
F_24 ( F_77 ( V_14 ) ,
F_40 ( V_43 ) + V_120 ) ;
F_41 ( V_31 , V_6 -> V_34 ) ;
if ( V_58 )
F_20 ( V_6 , V_8 ) ;
}
static void
F_78 ( struct V_37 * V_34 , struct V_39 * V_7 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 = F_27 ( V_34 ) ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
int V_14 = V_52 -> V_14 ;
T_2 V_8 ;
bool V_58 ;
V_58 = F_3 ( V_6 , & V_8 ) ;
F_22 ( V_6 ) ;
F_24 ( F_69 ( V_14 ) , F_25 ( F_69 ( V_14 ) ) & ~ V_135 ) ;
F_24 ( F_76 ( V_14 ) , 0 ) ;
F_24 ( F_77 ( V_14 ) , 0 ) ;
F_41 ( V_31 , V_6 -> V_34 ) ;
if ( V_58 )
F_20 ( V_6 , V_8 ) ;
F_62 ( V_10 , V_14 ) ;
F_32 ( V_34 , V_7 , 0 , 0 , false , false ) ;
}
static void
F_79 ( struct V_39 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
if ( F_52 ( V_10 ) )
F_62 ( V_10 , V_6 -> V_14 ) ;
F_80 ( V_6 ) ;
F_81 ( & V_10 -> V_137 ) ;
F_82 ( V_10 ) ;
F_83 ( & V_10 -> V_137 ) ;
}
static void
F_84 ( struct V_39 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
F_81 ( & V_10 -> V_137 ) ;
if ( V_31 -> V_138 . V_34 == V_6 -> V_34 )
F_85 ( V_10 ) ;
F_83 ( & V_10 -> V_137 ) ;
F_86 ( V_6 ) ;
}
static int
F_87 ( struct V_37 * V_34 ,
struct V_90 * V_91 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 ;
T_2 V_121 ;
int V_117 = 0 ;
V_52 = F_27 ( V_34 ) ;
F_24 ( F_88 ( V_52 -> V_14 ) , V_91 -> V_94 ) ;
F_24 ( F_89 ( V_52 -> V_14 ) , V_91 -> V_95 ) ;
F_24 ( F_90 ( V_52 -> V_14 ) , V_91 -> V_96 ) ;
V_121 = F_25 ( F_69 ( V_52 -> V_14 ) ) ;
V_121 &= ~ ( V_139 | V_140 ) ;
if ( V_91 -> V_23 & V_92 )
V_121 |= V_140 ;
else if ( V_91 -> V_23 & V_98 )
V_121 |= V_139 ;
F_24 ( F_69 ( V_52 -> V_14 ) , V_121 ) ;
F_47 ( F_90 ( V_52 -> V_14 ) ) ;
return V_117 ;
}
static void
F_91 ( struct V_37 * V_34 , struct V_90 * V_91 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_52 * V_52 ;
T_2 V_121 ;
V_52 = F_27 ( V_34 ) ;
V_91 -> V_94 = F_25 ( F_88 ( V_52 -> V_14 ) ) ;
V_91 -> V_95 = F_25 ( F_89 ( V_52 -> V_14 ) ) ;
V_91 -> V_96 = F_25 ( F_90 ( V_52 -> V_14 ) ) ;
V_91 -> V_23 = 0 ;
V_121 = F_25 ( F_69 ( V_52 -> V_14 ) ) ;
if ( V_121 & V_140 )
V_91 -> V_23 = V_92 ;
else if ( V_121 & V_139 )
V_91 -> V_23 = V_98 ;
else
V_91 -> V_23 = V_99 ;
}
static bool
F_92 ( T_1 V_141 )
{
switch ( V_141 ) {
case V_62 :
case V_67 :
case V_69 :
case V_65 :
return true ;
default:
return false ;
}
}
static bool F_93 ( struct V_52 * V_52 )
{
struct V_90 V_91 ;
V_52 -> V_142 ( & V_52 -> V_11 , & V_91 ) ;
return V_91 . V_23 != V_99 ;
}
static int
F_94 ( struct V_37 * V_34 , struct V_39 * V_7 ,
struct V_40 * V_41 , int V_44 , int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
T_1 V_143 , T_1 V_144 ,
T_1 V_50 , T_1 V_51 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_6 * V_6 = F_28 ( V_7 ) ;
struct V_52 * V_52 = F_27 ( V_34 ) ;
struct V_145 * V_146 = F_95 ( V_41 ) ;
struct V_42 * V_43 = V_146 -> V_43 ;
struct V_42 * V_147 = V_52 -> V_43 ;
int V_117 ;
bool V_35 ;
bool V_148 ;
int V_149 , V_150 ;
int V_151 , V_152 ;
int V_56 = F_29 ( V_41 -> V_57 , 0 ) ;
struct V_153 V_154 = {
. V_155 = V_143 ,
. V_156 = V_143 + V_50 ,
. y1 = V_144 ,
. V_157 = V_144 + V_51 ,
} ;
struct V_153 V_158 = {
. V_155 = V_44 ,
. V_156 = V_44 + V_46 ,
. y1 = V_45 ,
. V_157 = V_45 + V_47 ,
} ;
const struct V_153 V_159 = {
. V_156 = V_6 -> V_160 ? V_6 -> V_12 . V_161 : 0 ,
. V_157 = V_6 -> V_160 ? V_6 -> V_12 . V_162 : 0 ,
} ;
const struct {
int V_44 , V_45 ;
unsigned int V_46 , V_47 ;
T_1 V_143 , V_144 , V_50 , V_51 ;
} V_163 = {
. V_44 = V_44 ,
. V_45 = V_45 ,
. V_46 = V_46 ,
. V_47 = V_47 ,
. V_143 = V_143 ,
. V_144 = V_144 ,
. V_50 = V_50 ,
. V_51 = V_51 ,
} ;
if ( V_52 -> V_14 != V_6 -> V_14 ) {
F_96 ( L_3 ) ;
return - V_93 ;
}
if ( V_41 -> V_164 < 3 || V_41 -> V_165 < 3 || V_41 -> V_89 [ 0 ] > 16384 ) {
F_96 ( L_4 ) ;
return - V_93 ;
}
switch ( V_43 -> V_86 ) {
case V_87 :
case V_166 :
break;
default:
F_96 ( L_5 ) ;
return - V_93 ;
}
V_151 = V_52 -> V_167 << 16 ;
V_152 = V_52 -> V_116 ? 1 : ( 1 << 16 ) ;
V_149 = F_97 ( & V_154 , & V_158 , V_152 , V_151 ) ;
F_98 ( V_149 < 0 ) ;
V_150 = F_99 ( & V_154 , & V_158 , V_152 , V_151 ) ;
F_98 ( V_150 < 0 ) ;
V_148 = F_100 ( & V_154 , & V_158 , & V_159 , V_149 , V_150 ) ;
V_44 = V_158 . V_155 ;
V_45 = V_158 . y1 ;
V_46 = F_101 ( & V_158 ) ;
V_47 = F_102 ( & V_158 ) ;
if ( V_148 ) {
V_149 = F_103 ( & V_154 , & V_158 , V_152 , V_151 ) ;
if ( V_149 < 0 ) {
F_96 ( L_6 ) ;
F_104 ( & V_154 , true ) ;
F_104 ( & V_158 , false ) ;
return V_149 ;
}
V_150 = F_105 ( & V_154 , & V_158 , V_152 , V_151 ) ;
if ( V_150 < 0 ) {
F_96 ( L_7 ) ;
F_104 ( & V_154 , true ) ;
F_104 ( & V_158 , false ) ;
return V_150 ;
}
F_106 ( & V_154 ,
F_101 ( & V_158 ) * V_149 - F_101 ( & V_154 ) ,
F_102 ( & V_158 ) * V_150 - F_102 ( & V_154 ) ) ;
F_6 ( V_154 . V_155 < ( int ) V_143 ||
V_154 . y1 < ( int ) V_144 ||
V_154 . V_156 > ( int ) ( V_143 + V_50 ) ||
V_154 . V_157 > ( int ) ( V_144 + V_51 ) ) ;
V_143 = V_154 . V_155 >> 16 ;
V_50 = F_101 ( & V_154 ) >> 16 ;
V_144 = V_154 . y1 >> 16 ;
V_51 = F_102 ( & V_154 ) >> 16 ;
if ( F_92 ( V_41 -> V_57 ) ) {
V_143 &= ~ 1 ;
V_50 &= ~ 1 ;
if ( ! V_52 -> V_116 )
V_46 &= ~ 1 ;
if ( V_46 == 0 )
V_148 = false ;
}
}
if ( V_148 && ( V_50 != V_46 || V_51 != V_47 ) ) {
unsigned int V_168 ;
F_6 ( ! V_52 -> V_116 ) ;
if ( V_46 < 3 || V_47 < 3 )
V_148 = false ;
if ( V_50 < 3 || V_51 < 3 )
V_148 = false ;
V_168 = ( ( V_143 * V_56 ) & 63 ) + V_50 * V_56 ;
if ( V_50 > 2048 || V_51 > 2048 ||
V_168 > 4096 || V_41 -> V_89 [ 0 ] > 4096 ) {
F_96 ( L_8 ) ;
return - V_93 ;
}
}
V_158 . V_155 = V_44 ;
V_158 . V_156 = V_44 + V_46 ;
V_158 . y1 = V_45 ;
V_158 . V_157 = V_45 + V_47 ;
V_35 = ! F_107 ( & V_158 , & V_159 ) || F_93 ( V_52 ) ;
F_6 ( ! V_35 && ! V_148 && V_6 -> V_160 ) ;
F_81 ( & V_10 -> V_137 ) ;
V_117 = F_108 ( V_10 , V_43 , NULL ) ;
F_83 ( & V_10 -> V_137 ) ;
if ( V_117 )
return V_117 ;
V_52 -> V_44 = V_163 . V_44 ;
V_52 -> V_45 = V_163 . V_45 ;
V_52 -> V_46 = V_163 . V_46 ;
V_52 -> V_47 = V_163 . V_47 ;
V_52 -> V_143 = V_163 . V_143 ;
V_52 -> V_144 = V_163 . V_144 ;
V_52 -> V_50 = V_163 . V_50 ;
V_52 -> V_51 = V_163 . V_51 ;
V_52 -> V_43 = V_43 ;
if ( V_6 -> V_160 ) {
bool V_169 = V_6 -> V_35 ;
V_6 -> V_35 = V_35 ;
if ( V_169 != V_35 )
F_109 ( V_7 ) ;
if ( V_169 && ! V_35 )
F_84 ( V_7 ) ;
if ( V_148 )
V_52 -> V_170 ( V_34 , V_7 , V_41 , V_43 ,
V_44 , V_45 , V_46 , V_47 ,
V_143 , V_144 , V_50 , V_51 ) ;
else
V_52 -> V_171 ( V_34 , V_7 ) ;
if ( ! V_169 && V_35 )
F_79 ( V_7 ) ;
}
if ( V_147 ) {
if ( V_147 != V_43 && V_6 -> V_160 )
F_62 ( V_10 , V_6 -> V_14 ) ;
F_81 ( & V_10 -> V_137 ) ;
F_110 ( V_147 ) ;
F_83 ( & V_10 -> V_137 ) ;
}
return 0 ;
}
static int
F_111 ( struct V_37 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_52 * V_52 = F_27 ( V_34 ) ;
struct V_6 * V_6 ;
if ( ! V_34 -> V_41 )
return 0 ;
if ( F_6 ( ! V_34 -> V_7 ) )
return - V_93 ;
V_6 = F_28 ( V_34 -> V_7 ) ;
if ( V_6 -> V_160 ) {
bool V_169 = V_6 -> V_35 ;
V_6 -> V_35 = true ;
V_52 -> V_171 ( V_34 , V_34 -> V_7 ) ;
if ( ! V_169 && V_6 -> V_35 )
F_79 ( V_34 -> V_7 ) ;
}
if ( V_52 -> V_43 ) {
if ( V_6 -> V_160 )
F_62 ( V_10 , V_52 -> V_14 ) ;
F_81 ( & V_10 -> V_137 ) ;
F_110 ( V_52 -> V_43 ) ;
F_83 ( & V_10 -> V_137 ) ;
V_52 -> V_43 = NULL ;
}
return 0 ;
}
static void F_112 ( struct V_37 * V_34 )
{
struct V_52 * V_52 = F_27 ( V_34 ) ;
F_111 ( V_34 ) ;
F_113 ( V_34 ) ;
F_114 ( V_52 ) ;
}
int F_115 ( struct V_9 * V_10 , void * V_172 ,
struct V_173 * V_174 )
{
struct V_90 * V_175 = V_172 ;
struct V_176 * V_43 ;
struct V_37 * V_34 ;
struct V_52 * V_52 ;
int V_117 = 0 ;
if ( ! F_116 ( V_10 , V_177 ) )
return - V_178 ;
if ( ( V_175 -> V_23 & ( V_92 | V_98 ) ) == ( V_92 | V_98 ) )
return - V_93 ;
F_117 ( V_10 ) ;
V_43 = F_118 ( V_10 , V_175 -> V_179 , V_180 ) ;
if ( ! V_43 ) {
V_117 = - V_181 ;
goto V_182;
}
V_34 = F_119 ( V_43 ) ;
V_52 = F_27 ( V_34 ) ;
V_117 = V_52 -> V_183 ( V_34 , V_175 ) ;
V_182:
F_120 ( V_10 ) ;
return V_117 ;
}
int F_121 ( struct V_9 * V_10 , void * V_172 ,
struct V_173 * V_174 )
{
struct V_90 * V_184 = V_172 ;
struct V_176 * V_43 ;
struct V_37 * V_34 ;
struct V_52 * V_52 ;
int V_117 = 0 ;
if ( ! F_116 ( V_10 , V_177 ) )
return - V_178 ;
F_117 ( V_10 ) ;
V_43 = F_118 ( V_10 , V_184 -> V_179 , V_180 ) ;
if ( ! V_43 ) {
V_117 = - V_181 ;
goto V_182;
}
V_34 = F_119 ( V_43 ) ;
V_52 = F_27 ( V_34 ) ;
V_52 -> V_142 ( V_34 , V_184 ) ;
V_182:
F_120 ( V_10 ) ;
return V_117 ;
}
void F_122 ( struct V_37 * V_34 )
{
struct V_52 * V_52 = F_27 ( V_34 ) ;
if ( ! V_34 -> V_7 || ! V_34 -> V_41 )
return;
F_94 ( V_34 , V_34 -> V_7 , V_34 -> V_41 ,
V_52 -> V_44 , V_52 -> V_45 ,
V_52 -> V_46 , V_52 -> V_47 ,
V_52 -> V_143 , V_52 -> V_144 ,
V_52 -> V_50 , V_52 -> V_51 ) ;
}
void F_123 ( struct V_37 * V_34 )
{
if ( ! V_34 -> V_7 || ! V_34 -> V_41 )
return;
F_111 ( V_34 ) ;
}
int
F_124 ( struct V_9 * V_10 , enum V_14 V_14 , int V_34 )
{
struct V_52 * V_52 ;
unsigned long V_185 ;
const T_1 * V_186 ;
int V_187 ;
int V_117 ;
if ( F_125 ( V_10 ) -> V_188 < 5 )
return - V_178 ;
V_52 = F_126 ( sizeof( * V_52 ) , V_189 ) ;
if ( ! V_52 )
return - V_190 ;
switch ( F_125 ( V_10 ) -> V_188 ) {
case 5 :
case 6 :
V_52 -> V_116 = true ;
V_52 -> V_167 = 16 ;
V_52 -> V_170 = F_68 ;
V_52 -> V_171 = F_78 ;
V_52 -> V_183 = F_87 ;
V_52 -> V_142 = F_91 ;
if ( F_70 ( V_10 ) ) {
V_186 = V_191 ;
V_187 = F_127 ( V_191 ) ;
} else {
V_186 = V_192 ;
V_187 = F_127 ( V_192 ) ;
}
break;
case 7 :
case 8 :
if ( F_128 ( V_10 ) ) {
V_52 -> V_116 = true ;
V_52 -> V_167 = 2 ;
} else {
V_52 -> V_116 = false ;
V_52 -> V_167 = 1 ;
}
if ( F_129 ( V_10 ) ) {
V_52 -> V_170 = F_26 ;
V_52 -> V_171 = F_42 ;
V_52 -> V_183 = F_43 ;
V_52 -> V_142 = F_48 ;
V_186 = V_193 ;
V_187 = F_127 ( V_193 ) ;
} else {
V_52 -> V_170 = F_49 ;
V_52 -> V_171 = F_61 ;
V_52 -> V_183 = F_63 ;
V_52 -> V_142 = F_67 ;
V_186 = V_191 ;
V_187 = F_127 ( V_191 ) ;
}
break;
default:
F_114 ( V_52 ) ;
return - V_178 ;
}
V_52 -> V_14 = V_14 ;
V_52 -> V_34 = V_34 ;
V_185 = ( 1 << V_14 ) ;
V_117 = F_130 ( V_10 , & V_52 -> V_11 , V_185 ,
& V_194 ,
V_186 , V_187 ,
false ) ;
if ( V_117 )
F_114 ( V_52 ) ;
return V_117 ;
}
