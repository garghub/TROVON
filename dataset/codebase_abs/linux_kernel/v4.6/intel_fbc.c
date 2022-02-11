static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_5 ( V_2 ) -> V_3 >= 8 ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
return F_5 ( V_2 ) -> V_3 < 4 ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 ) -> V_3 <= 3 ;
}
static unsigned int F_8 ( struct V_4 * V_5 )
{
return V_5 -> V_6 . V_7 - V_5 -> V_8 ;
}
static void F_9 ( struct V_9 * V_10 ,
int * V_11 , int * V_12 )
{
int V_13 , V_14 ;
if ( F_10 ( V_10 -> V_15 . V_16 ) ) {
V_13 = V_10 -> V_15 . V_17 ;
V_14 = V_10 -> V_15 . V_18 ;
} else {
V_13 = V_10 -> V_15 . V_18 ;
V_14 = V_10 -> V_15 . V_17 ;
}
if ( V_11 )
* V_11 = V_13 ;
if ( V_12 )
* V_12 = V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_19 ;
F_9 ( V_10 , NULL , & V_19 ) ;
if ( F_5 ( V_2 ) -> V_3 >= 7 )
V_19 = F_12 ( V_19 , 2048 ) ;
return V_19 * V_10 -> V_20 . V_21 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_22 ;
V_22 = F_14 ( V_23 ) ;
if ( ( V_22 & V_24 ) == 0 )
return;
V_22 &= ~ V_24 ;
F_15 ( V_23 , V_22 ) ;
if ( F_16 ( ( F_14 ( V_25 ) & V_26 ) == 0 , 10 ) ) {
F_17 ( L_1 ) ;
return;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
int V_30 ;
int V_31 ;
T_1 V_22 ;
V_30 = V_28 -> V_32 / V_33 ;
if ( V_28 -> V_20 . V_21 < V_30 )
V_30 = V_28 -> V_20 . V_21 ;
if ( F_19 ( V_2 ) )
V_30 = ( V_30 / 32 ) - 1 ;
else
V_30 = ( V_30 / 64 ) - 1 ;
for ( V_31 = 0 ; V_31 < ( V_33 / 32 ) + 1 ; V_31 ++ )
F_15 ( F_20 ( V_31 ) , 0 ) ;
if ( F_21 ( V_2 ) ) {
T_1 V_34 ;
V_34 = V_35 | V_36 | V_37 ;
V_34 |= F_22 ( V_28 -> V_5 . V_15 ) ;
F_15 ( V_38 , V_34 ) ;
F_15 ( V_39 , V_28 -> V_5 . V_40 ) ;
}
V_22 = F_14 ( V_23 ) ;
V_22 &= 0x3fff << V_41 ;
V_22 |= V_24 | V_42 ;
if ( F_23 ( V_2 ) )
V_22 |= V_43 ;
V_22 |= ( V_30 & 0xff ) << V_44 ;
V_22 |= V_28 -> V_20 . V_45 ;
F_15 ( V_23 , V_22 ) ;
}
static bool F_24 ( struct V_1 * V_2 )
{
return F_14 ( V_23 ) & V_24 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_46 ;
V_46 = F_26 ( V_28 -> V_5 . V_15 ) | V_47 ;
if ( F_27 ( V_28 -> V_20 . V_48 , 0 ) == 2 )
V_46 |= V_49 ;
else
V_46 |= V_50 ;
V_46 |= V_51 | V_28 -> V_20 . V_45 ;
F_15 ( V_52 , V_28 -> V_5 . V_40 ) ;
F_15 ( V_53 , V_46 | V_54 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_14 ( V_53 ) ;
if ( V_46 & V_54 ) {
V_46 &= ~ V_54 ;
F_15 ( V_53 , V_46 ) ;
}
}
static bool F_29 ( struct V_1 * V_2 )
{
return F_14 ( V_53 ) & V_54 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_15 ( V_55 , V_56 ) ;
F_31 ( V_55 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_46 ;
int V_57 = V_2 -> V_29 . V_57 ;
V_46 = F_26 ( V_28 -> V_5 . V_15 ) ;
if ( F_27 ( V_28 -> V_20 . V_48 , 0 ) == 2 )
V_57 ++ ;
switch ( V_57 ) {
case 4 :
case 3 :
V_46 |= V_58 ;
break;
case 2 :
V_46 |= V_49 ;
break;
case 1 :
V_46 |= V_50 ;
break;
}
V_46 |= V_51 ;
if ( F_33 ( V_2 ) )
V_46 |= V_28 -> V_20 . V_45 ;
F_15 ( V_59 , V_28 -> V_5 . V_40 ) ;
F_15 ( V_60 , V_28 -> V_20 . V_61 | V_62 ) ;
F_15 ( V_63 , V_46 | V_54 ) ;
if ( F_34 ( V_2 ) ) {
F_15 ( V_64 ,
V_65 | V_28 -> V_20 . V_45 ) ;
F_15 ( V_66 , V_28 -> V_5 . V_40 ) ;
}
F_30 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_14 ( V_63 ) ;
if ( V_46 & V_54 ) {
V_46 &= ~ V_54 ;
F_15 ( V_63 , V_46 ) ;
}
}
static bool F_36 ( struct V_1 * V_2 )
{
return F_14 ( V_63 ) & V_54 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_46 ;
int V_57 = V_2 -> V_29 . V_57 ;
V_46 = 0 ;
if ( F_38 ( V_2 ) )
V_46 |= F_39 ( V_28 -> V_5 . V_15 ) ;
if ( F_27 ( V_28 -> V_20 . V_48 , 0 ) == 2 )
V_57 ++ ;
switch ( V_57 ) {
case 4 :
case 3 :
V_46 |= V_58 ;
break;
case 2 :
V_46 |= V_49 ;
break;
case 1 :
V_46 |= V_50 ;
break;
}
V_46 |= V_67 ;
if ( V_2 -> V_29 . V_68 )
V_46 |= V_69 ;
if ( F_38 ( V_2 ) ) {
F_15 ( V_70 ,
F_14 ( V_70 ) |
V_71 ) ;
} else if ( F_4 ( V_2 ) || F_40 ( V_2 ) ) {
F_15 ( F_41 ( V_28 -> V_5 . V_72 ) ,
F_14 ( F_41 ( V_28 -> V_5 . V_72 ) ) |
V_73 ) ;
}
F_15 ( V_63 , V_46 | V_54 ) ;
F_15 ( V_64 ,
V_65 | V_28 -> V_20 . V_45 ) ;
F_15 ( V_66 , V_28 -> V_5 . V_40 ) ;
F_30 ( V_2 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) -> V_3 >= 5 )
return F_36 ( V_2 ) ;
else if ( F_43 ( V_2 ) )
return F_29 ( V_2 ) ;
else
return F_24 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
V_29 -> V_75 = true ;
if ( F_5 ( V_2 ) -> V_3 >= 7 )
F_37 ( V_2 ) ;
else if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_32 ( V_2 ) ;
else if ( F_43 ( V_2 ) )
F_25 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
V_29 -> V_75 = false ;
if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_35 ( V_2 ) ;
else if ( F_43 ( V_2 ) )
F_28 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
bool F_46 ( struct V_1 * V_2 )
{
return V_2 -> V_29 . V_75 ;
}
static void F_47 ( struct V_76 * V_77 )
{
struct V_1 * V_2 =
F_48 ( V_77 , struct V_1 , V_29 . V_78 . V_78 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_79 * V_78 = & V_29 -> V_78 ;
struct V_4 * V_5 = V_29 -> V_5 ;
struct V_80 * V_81 = & V_2 -> V_82 -> V_81 [ V_5 -> V_72 ] ;
if ( F_49 ( & V_5 -> V_6 ) ) {
F_50 ( L_2 ,
F_51 ( V_5 -> V_72 ) ) ;
F_52 ( & V_29 -> V_83 ) ;
V_78 -> V_84 = false ;
F_53 ( & V_29 -> V_83 ) ;
return;
}
V_85:
F_54 ( V_81 -> V_86 ,
F_55 ( & V_5 -> V_6 ) != V_78 -> V_87 ,
F_56 ( 50 ) ) ;
F_52 ( & V_29 -> V_83 ) ;
if ( ! V_78 -> V_84 )
goto V_88;
if ( F_55 ( & V_5 -> V_6 ) == V_78 -> V_87 ) {
F_53 ( & V_29 -> V_83 ) ;
goto V_85;
}
F_44 ( V_2 ) ;
V_78 -> V_84 = false ;
V_88:
F_53 ( & V_29 -> V_83 ) ;
F_57 ( & V_5 -> V_6 ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_79 * V_78 = & V_29 -> V_78 ;
F_59 ( ! F_60 ( & V_29 -> V_83 ) ) ;
if ( F_49 ( & V_5 -> V_6 ) ) {
F_50 ( L_2 ,
F_51 ( V_5 -> V_72 ) ) ;
return;
}
V_78 -> V_84 = true ;
V_78 -> V_87 = F_55 ( & V_5 -> V_6 ) ;
F_57 ( & V_5 -> V_6 ) ;
F_61 ( & V_78 -> V_78 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
F_59 ( ! F_60 ( & V_29 -> V_83 ) ) ;
V_29 -> V_78 . V_84 = false ;
if ( V_29 -> V_75 )
F_45 ( V_2 ) ;
}
static bool F_63 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_90 * V_91 = V_5 -> V_6 . V_91 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
enum V_72 V_72 = V_5 -> V_72 ;
if ( ! F_7 ( V_2 ) )
return true ;
F_59 ( ! F_64 ( & V_91 -> V_92 ) ) ;
if ( F_65 ( V_91 -> V_93 ) -> V_94 )
V_29 -> V_95 |= ( 1 << V_72 ) ;
else
V_29 -> V_95 &= ~ ( 1 << V_72 ) ;
return ( V_29 -> V_95 & ~ ( 1 << V_72 ) ) != 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
int V_98 ,
int V_99 )
{
int V_100 = 1 ;
int V_101 ;
T_2 V_102 ;
if ( F_40 ( V_2 ) ||
F_67 ( V_2 ) || F_68 ( V_2 ) )
V_102 = V_2 -> V_103 . V_104 - 8 * 1024 * 1024 ;
else
V_102 = V_2 -> V_103 . V_105 ;
V_101 = F_69 ( V_2 , V_97 , V_98 <<= 1 ,
4096 , 0 , V_102 ) ;
if ( V_101 == 0 )
return V_100 ;
V_106:
if ( V_100 > 4 ||
( V_99 == 2 && V_100 == 2 ) )
return 0 ;
V_101 = F_69 ( V_2 , V_97 , V_98 >>= 1 ,
4096 , 0 , V_102 ) ;
if ( V_101 && F_5 ( V_2 ) -> V_3 <= 4 ) {
return 0 ;
} else if ( V_101 ) {
V_100 <<= 1 ;
goto V_106;
} else {
return V_100 ;
}
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_96 * V_107 ( V_108 ) ;
int V_98 , V_99 , V_101 ;
F_59 ( F_71 ( & V_29 -> V_109 ) ) ;
V_98 = F_11 ( V_2 , & V_29 -> V_110 ) ;
V_99 = F_27 ( V_29 -> V_110 . V_20 . V_48 , 0 ) ;
V_101 = F_66 ( V_2 , & V_29 -> V_109 ,
V_98 , V_99 ) ;
if ( ! V_101 )
goto V_111;
else if ( V_101 > 1 ) {
F_72 ( L_3 ) ;
}
V_29 -> V_57 = V_101 ;
if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_15 ( V_112 , V_29 -> V_109 . V_113 ) ;
else if ( F_43 ( V_2 ) ) {
F_15 ( V_114 , V_29 -> V_109 . V_113 ) ;
} else {
V_108 = F_73 ( sizeof( * V_108 ) , V_115 ) ;
if ( ! V_108 )
goto V_116;
V_101 = F_74 ( V_2 , V_108 ,
4096 , 4096 ) ;
if ( V_101 )
goto V_116;
V_29 -> V_108 = V_108 ;
F_15 ( V_117 ,
V_2 -> V_118 . V_119 + V_29 -> V_109 . V_113 ) ;
F_15 ( V_120 ,
V_2 -> V_118 . V_119 + V_108 -> V_113 ) ;
}
F_17 ( L_4 ,
V_29 -> V_109 . V_98 , V_29 -> V_57 ) ;
return 0 ;
V_116:
F_75 ( V_108 ) ;
F_76 ( V_2 , & V_29 -> V_109 ) ;
V_111:
F_77 ( L_5 , V_98 ) ;
return - V_121 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( F_71 ( & V_29 -> V_109 ) )
F_76 ( V_2 , & V_29 -> V_109 ) ;
if ( V_29 -> V_108 ) {
F_76 ( V_2 , V_29 -> V_108 ) ;
F_75 ( V_29 -> V_108 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
F_78 ( V_2 ) ;
F_53 ( & V_29 -> V_83 ) ;
}
static bool F_80 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
F_59 ( V_21 < 512 ) ;
F_59 ( ( V_21 & ( 64 - 1 ) ) != 0 ) ;
if ( F_19 ( V_2 ) || F_81 ( V_2 ) )
return V_21 == 4096 || V_21 == 8192 ;
if ( F_21 ( V_2 ) && ! F_82 ( V_2 ) && V_21 < 2048 )
return false ;
if ( V_21 > 16384 )
return false ;
return true ;
}
static bool F_83 ( struct V_1 * V_2 ,
T_3 V_48 )
{
switch ( V_48 ) {
case V_122 :
case V_123 :
return true ;
case V_124 :
case V_125 :
if ( F_19 ( V_2 ) )
return false ;
if ( F_82 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_84 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
unsigned int V_126 , V_127 , V_128 , V_129 ;
if ( F_5 ( V_2 ) -> V_3 >= 8 || F_4 ( V_2 ) ) {
V_128 = 4096 ;
V_129 = 4096 ;
} else if ( F_82 ( V_2 ) || F_5 ( V_2 ) -> V_3 >= 5 ) {
V_128 = 4096 ;
V_129 = 2048 ;
} else {
V_128 = 2048 ;
V_129 = 1536 ;
}
F_9 ( & V_29 -> V_110 , & V_126 ,
& V_127 ) ;
V_126 += V_5 -> V_130 ;
V_127 += V_5 -> V_8 ;
return V_126 <= V_128 && V_127 <= V_129 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_110 ;
struct V_131 * V_132 =
F_86 ( V_5 -> V_6 . V_93 ) ;
struct V_133 * V_134 =
F_65 ( V_5 -> V_6 . V_91 -> V_93 ) ;
struct V_135 * V_20 = V_134 -> V_6 . V_20 ;
struct V_136 * V_137 ;
F_59 ( ! F_64 ( & V_5 -> V_6 . V_92 ) ) ;
F_59 ( ! F_64 ( & V_5 -> V_6 . V_91 -> V_92 ) ) ;
V_10 -> V_5 . V_138 = V_132 -> V_6 . V_139 . V_140 ;
if ( F_4 ( V_2 ) || F_40 ( V_2 ) )
V_10 -> V_5 . V_141 =
F_87 ( V_132 ) ;
V_10 -> V_15 . V_16 = V_134 -> V_6 . V_16 ;
V_10 -> V_15 . V_18 = F_88 ( & V_134 -> V_142 ) >> 16 ;
V_10 -> V_15 . V_17 = F_89 ( & V_134 -> V_142 ) >> 16 ;
V_10 -> V_15 . V_94 = V_134 -> V_94 ;
if ( ! V_10 -> V_15 . V_94 )
return;
V_137 = F_90 ( V_20 ) ;
if ( F_5 ( V_2 ) -> V_3 >= 5 && F_5 ( V_2 ) -> V_3 < 7 )
V_10 -> V_20 . V_143 = F_91 ( V_137 ) ;
V_10 -> V_20 . V_48 = V_20 -> V_48 ;
V_10 -> V_20 . V_21 = V_20 -> V_144 [ 0 ] ;
V_10 -> V_20 . V_45 = V_137 -> V_45 ;
V_10 -> V_20 . V_145 = V_137 -> V_145 ;
}
static bool F_92 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_110 ;
if ( ! V_10 -> V_15 . V_94 ) {
V_29 -> V_146 = L_6 ;
return false ;
}
if ( ( V_10 -> V_5 . V_138 & V_147 ) ||
( V_10 -> V_5 . V_138 & V_148 ) ) {
V_29 -> V_146 = L_7 ;
return false ;
}
if ( ! F_84 ( V_5 ) ) {
V_29 -> V_146 = L_8 ;
return false ;
}
if ( V_10 -> V_20 . V_145 != V_149 ||
V_10 -> V_20 . V_45 == V_150 ) {
V_29 -> V_146 = L_9 ;
return false ;
}
if ( F_5 ( V_2 ) -> V_3 <= 4 && ! F_82 ( V_2 ) &&
V_10 -> V_15 . V_16 != F_93 ( V_151 ) ) {
V_29 -> V_146 = L_10 ;
return false ;
}
if ( ! F_80 ( V_2 , V_10 -> V_20 . V_21 ) ) {
V_29 -> V_146 = L_11 ;
return false ;
}
if ( ! F_83 ( V_2 , V_10 -> V_20 . V_48 ) ) {
V_29 -> V_146 = L_12 ;
return false ;
}
if ( ( F_4 ( V_2 ) || F_40 ( V_2 ) ) &&
V_10 -> V_5 . V_141 >= V_2 -> V_152 * 95 / 100 ) {
V_29 -> V_146 = L_13 ;
return false ;
}
if ( F_11 ( V_2 , & V_29 -> V_110 ) >
V_29 -> V_109 . V_98 * V_29 -> V_57 ) {
V_29 -> V_146 = L_14 ;
return false ;
}
return true ;
}
static bool F_94 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
bool V_153 = F_4 ( V_2 ) ||
F_40 ( V_2 ) ;
if ( F_95 ( V_2 -> V_82 ) ) {
V_29 -> V_146 = L_15 ;
return false ;
}
if ( V_154 . V_155 < 0 && ! V_153 ) {
V_29 -> V_146 = L_16 ;
return false ;
}
if ( ! V_154 . V_155 ) {
V_29 -> V_146 = L_17 ;
return false ;
}
if ( F_3 ( V_2 ) && V_5 -> V_72 != V_156 ) {
V_29 -> V_146 = L_18 ;
return false ;
}
if ( F_6 ( V_2 ) && V_5 -> V_15 != V_157 ) {
V_29 -> V_146 = L_19 ;
return false ;
}
return true ;
}
static void F_96 ( struct V_4 * V_5 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_110 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_5 . V_72 = V_5 -> V_72 ;
V_28 -> V_5 . V_15 = V_5 -> V_15 ;
V_28 -> V_5 . V_40 = F_8 ( V_5 ) ;
V_28 -> V_20 . V_48 = V_10 -> V_20 . V_48 ;
V_28 -> V_20 . V_21 = V_10 -> V_20 . V_21 ;
V_28 -> V_20 . V_45 = V_10 -> V_20 . V_45 ;
V_28 -> V_32 = F_11 ( V_2 , V_10 ) ;
V_28 -> V_20 . V_61 = V_10 -> V_20 . V_143 ;
}
static bool F_97 ( struct V_27 * V_158 ,
struct V_27 * V_159 )
{
return memcmp ( V_158 , V_159 , sizeof( * V_158 ) ) == 0 ;
}
void F_98 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( ! F_63 ( V_5 ) ) {
V_29 -> V_146 = L_20 ;
goto V_160;
}
if ( ! V_29 -> V_161 || V_29 -> V_5 != V_5 )
goto V_162;
F_85 ( V_5 ) ;
V_160:
F_62 ( V_2 ) ;
V_162:
F_53 ( & V_29 -> V_83 ) ;
}
static void F_99 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_27 V_163 ;
F_59 ( ! F_60 ( & V_29 -> V_83 ) ) ;
if ( ! V_29 -> V_161 || V_29 -> V_5 != V_5 )
return;
if ( ! F_92 ( V_5 ) ) {
F_59 ( V_29 -> V_75 ) ;
return;
}
V_163 = V_29 -> V_28 ;
F_96 ( V_5 , & V_29 -> V_28 ) ;
if ( V_29 -> V_75 &&
F_97 ( & V_163 , & V_29 -> V_28 ) )
return;
F_62 ( V_2 ) ;
F_58 ( V_5 ) ;
V_29 -> V_146 = L_21 ;
}
void F_100 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
F_99 ( V_5 ) ;
F_53 ( & V_29 -> V_83 ) ;
}
static unsigned int F_101 ( struct V_74 * V_29 )
{
if ( V_29 -> V_161 )
return F_102 ( V_29 -> V_5 -> V_6 . V_91 ) -> V_164 ;
else
return V_29 -> V_165 ;
}
void F_103 ( struct V_1 * V_2 ,
unsigned int V_166 ,
enum V_167 V_168 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_168 == V_169 || V_168 == V_170 )
return;
F_52 ( & V_29 -> V_83 ) ;
V_29 -> V_171 |= F_101 ( V_29 ) & V_166 ;
if ( V_29 -> V_161 && V_29 -> V_171 )
F_62 ( V_2 ) ;
F_53 ( & V_29 -> V_83 ) ;
}
void F_104 ( struct V_1 * V_2 ,
unsigned int V_166 , enum V_167 V_168 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_168 == V_169 || V_168 == V_170 )
return;
F_52 ( & V_29 -> V_83 ) ;
V_29 -> V_171 &= ~ V_166 ;
if ( ! V_29 -> V_171 && V_29 -> V_161 &&
( V_166 & F_101 ( V_29 ) ) ) {
if ( V_29 -> V_75 )
F_30 ( V_2 ) ;
else
F_99 ( V_29 -> V_5 ) ;
}
F_53 ( & V_29 -> V_83 ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_172 * V_93 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_173 * V_5 ;
struct V_174 * V_132 ;
struct V_90 * V_15 ;
struct V_175 * V_134 ;
bool V_176 = false ;
int V_31 , V_177 ;
F_52 ( & V_29 -> V_83 ) ;
F_106 (state, crtc, crtc_state, i) {
if ( V_29 -> V_5 == F_107 ( V_5 ) ) {
V_176 = true ;
break;
}
}
if ( ! V_176 && V_29 -> V_5 != NULL )
goto V_88;
F_108 (state, plane, plane_state, i) {
struct V_133 * V_133 =
F_65 ( V_134 ) ;
if ( ! V_133 -> V_94 )
continue;
F_106 (state, crtc, crtc_state, j) {
struct V_131 * V_131 =
F_86 ( V_132 ) ;
if ( V_134 -> V_5 != V_5 )
continue;
if ( ! F_94 ( F_107 ( V_5 ) ) )
break;
V_131 -> V_155 = true ;
goto V_88;
}
}
V_88:
F_53 ( & V_29 -> V_83 ) ;
}
void F_109 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_161 ) {
F_59 ( V_29 -> V_5 == NULL ) ;
if ( V_29 -> V_5 == V_5 ) {
F_59 ( ! V_5 -> V_178 -> V_155 ) ;
F_59 ( V_29 -> V_75 ) ;
}
goto V_88;
}
if ( ! V_5 -> V_178 -> V_155 )
goto V_88;
F_59 ( V_29 -> V_75 ) ;
F_59 ( V_29 -> V_5 != NULL ) ;
F_85 ( V_5 ) ;
if ( F_70 ( V_5 ) ) {
V_29 -> V_146 = L_22 ;
goto V_88;
}
F_17 ( L_23 , F_51 ( V_5 -> V_72 ) ) ;
V_29 -> V_146 = L_24 ;
V_29 -> V_161 = true ;
V_29 -> V_5 = V_5 ;
V_88:
F_53 ( & V_29 -> V_83 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_4 * V_5 = V_29 -> V_5 ;
F_59 ( ! F_60 ( & V_29 -> V_83 ) ) ;
F_59 ( ! V_29 -> V_161 ) ;
F_59 ( V_29 -> V_75 ) ;
F_59 ( V_5 -> V_75 ) ;
F_17 ( L_25 , F_51 ( V_5 -> V_72 ) ) ;
F_78 ( V_2 ) ;
V_29 -> V_161 = false ;
V_29 -> V_5 = NULL ;
}
void F_111 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_82 -> V_89 ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_5 == V_5 ) {
F_59 ( ! V_29 -> V_161 ) ;
F_59 ( V_29 -> V_75 ) ;
F_110 ( V_2 ) ;
}
F_53 ( & V_29 -> V_83 ) ;
F_112 ( & V_29 -> V_78 . V_78 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_161 )
F_110 ( V_2 ) ;
F_53 ( & V_29 -> V_83 ) ;
F_112 ( & V_29 -> V_78 . V_78 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! F_7 ( V_2 ) )
return;
F_115 (dev_priv->dev, crtc)
if ( F_116 ( & V_5 -> V_6 ) &&
F_65 ( V_5 -> V_6 . V_91 -> V_93 ) -> V_94 )
V_2 -> V_29 . V_95 |= ( 1 << V_5 -> V_72 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
enum V_72 V_72 ;
F_118 ( & V_29 -> V_78 . V_78 , F_47 ) ;
F_119 ( & V_29 -> V_83 ) ;
V_29 -> V_161 = false ;
V_29 -> V_75 = false ;
V_29 -> V_78 . V_84 = false ;
if ( ! F_2 ( V_2 ) ) {
V_29 -> V_146 = L_26 ;
return;
}
F_120 (dev_priv, pipe) {
V_29 -> V_165 |=
F_121 ( V_72 ) ;
if ( F_3 ( V_2 ) )
break;
}
if ( F_5 ( V_2 ) -> V_3 <= 4 && ! F_43 ( V_2 ) )
F_15 ( V_23 , 500 << V_41 ) ;
if ( F_42 ( V_2 ) )
F_45 ( V_2 ) ;
}
