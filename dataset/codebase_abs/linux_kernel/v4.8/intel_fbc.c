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
if ( F_16 ( V_2 ,
V_25 , V_26 , 0 ,
10 ) ) {
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
struct V_80 * V_81 = & V_2 -> V_82 . V_81 [ V_5 -> V_72 ] ;
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
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_79 * V_78 = & V_29 -> V_78 ;
F_60 ( ! F_61 ( & V_29 -> V_83 ) ) ;
if ( F_49 ( & V_5 -> V_6 ) ) {
F_50 ( L_2 ,
F_51 ( V_5 -> V_72 ) ) ;
return;
}
V_78 -> V_84 = true ;
V_78 -> V_87 = F_55 ( & V_5 -> V_6 ) ;
F_57 ( & V_5 -> V_6 ) ;
F_62 ( & V_78 -> V_78 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
F_60 ( ! F_61 ( & V_29 -> V_83 ) ) ;
V_29 -> V_78 . V_84 = false ;
if ( V_29 -> V_75 )
F_45 ( V_2 ) ;
}
static bool F_64 ( struct V_4 * V_5 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
enum V_72 V_72 = V_5 -> V_72 ;
if ( ! F_7 ( V_2 ) )
return true ;
if ( V_91 -> V_92 )
V_29 -> V_93 |= ( 1 << V_72 ) ;
else
V_29 -> V_93 &= ~ ( 1 << V_72 ) ;
return ( V_29 -> V_93 & ~ ( 1 << V_72 ) ) != 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
int V_96 ,
int V_97 )
{
struct V_98 * V_99 = & V_2 -> V_99 ;
int V_100 = 1 ;
int V_101 ;
T_2 V_102 ;
if ( F_40 ( V_2 ) ||
F_66 ( V_2 ) || F_67 ( V_2 ) )
V_102 = V_99 -> V_103 - 8 * 1024 * 1024 ;
else
V_102 = V_99 -> V_104 ;
V_101 = F_68 ( V_2 , V_95 , V_96 <<= 1 ,
4096 , 0 , V_102 ) ;
if ( V_101 == 0 )
return V_100 ;
V_105:
if ( V_100 > 4 ||
( V_97 == 2 && V_100 == 2 ) )
return 0 ;
V_101 = F_68 ( V_2 , V_95 , V_96 >>= 1 ,
4096 , 0 , V_102 ) ;
if ( V_101 && F_5 ( V_2 ) -> V_3 <= 4 ) {
return 0 ;
} else if ( V_101 ) {
V_100 <<= 1 ;
goto V_105;
} else {
return V_100 ;
}
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_94 * V_106 ( V_107 ) ;
int V_96 , V_97 , V_101 ;
F_60 ( F_70 ( & V_29 -> V_108 ) ) ;
V_96 = F_11 ( V_2 , & V_29 -> V_109 ) ;
V_97 = F_27 ( V_29 -> V_109 . V_20 . V_48 , 0 ) ;
V_101 = F_65 ( V_2 , & V_29 -> V_108 ,
V_96 , V_97 ) ;
if ( ! V_101 )
goto V_110;
else if ( V_101 > 1 ) {
F_71 ( L_3 ) ;
}
V_29 -> V_57 = V_101 ;
if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_15 ( V_111 , V_29 -> V_108 . V_112 ) ;
else if ( F_43 ( V_2 ) ) {
F_15 ( V_113 , V_29 -> V_108 . V_112 ) ;
} else {
V_107 = F_72 ( sizeof( * V_107 ) , V_114 ) ;
if ( ! V_107 )
goto V_115;
V_101 = F_73 ( V_2 , V_107 ,
4096 , 4096 ) ;
if ( V_101 )
goto V_115;
V_29 -> V_107 = V_107 ;
F_15 ( V_116 ,
V_2 -> V_117 . V_118 + V_29 -> V_108 . V_112 ) ;
F_15 ( V_119 ,
V_2 -> V_117 . V_118 + V_107 -> V_112 ) ;
}
F_17 ( L_4 ,
V_29 -> V_108 . V_96 , V_29 -> V_57 ) ;
return 0 ;
V_115:
F_74 ( V_107 ) ;
F_75 ( V_2 , & V_29 -> V_108 ) ;
V_110:
F_76 ( L_5 , V_96 ) ;
return - V_120 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( F_70 ( & V_29 -> V_108 ) )
F_75 ( V_2 , & V_29 -> V_108 ) ;
if ( V_29 -> V_107 ) {
F_75 ( V_2 , V_29 -> V_107 ) ;
F_74 ( V_29 -> V_107 ) ;
}
}
void F_78 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
F_77 ( V_2 ) ;
F_53 ( & V_29 -> V_83 ) ;
}
static bool F_79 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
F_60 ( V_21 < 512 ) ;
F_60 ( ( V_21 & ( 64 - 1 ) ) != 0 ) ;
if ( F_19 ( V_2 ) || F_80 ( V_2 ) )
return V_21 == 4096 || V_21 == 8192 ;
if ( F_21 ( V_2 ) && ! F_81 ( V_2 ) && V_21 < 2048 )
return false ;
if ( V_21 > 16384 )
return false ;
return true ;
}
static bool F_82 ( struct V_1 * V_2 ,
T_3 V_48 )
{
switch ( V_48 ) {
case V_121 :
case V_122 :
return true ;
case V_123 :
case V_124 :
if ( F_19 ( V_2 ) )
return false ;
if ( F_81 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_83 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
unsigned int V_125 , V_126 , V_127 , V_128 ;
if ( F_5 ( V_2 ) -> V_3 >= 8 || F_4 ( V_2 ) ) {
V_127 = 4096 ;
V_128 = 4096 ;
} else if ( F_81 ( V_2 ) || F_5 ( V_2 ) -> V_3 >= 5 ) {
V_127 = 4096 ;
V_128 = 2048 ;
} else {
V_127 = 2048 ;
V_128 = 1536 ;
}
F_9 ( & V_29 -> V_109 , & V_125 ,
& V_126 ) ;
V_125 += V_5 -> V_129 ;
V_126 += V_5 -> V_8 ;
return V_125 <= V_127 && V_126 <= V_128 ;
}
static void F_84 ( struct V_4 * V_5 ,
struct V_130 * V_131 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_109 ;
struct V_132 * V_20 = V_91 -> V_6 . V_20 ;
struct V_133 * V_134 ;
V_10 -> V_5 . V_135 = V_131 -> V_6 . V_136 . V_137 ;
if ( F_4 ( V_2 ) || F_40 ( V_2 ) )
V_10 -> V_5 . V_138 =
F_85 ( V_131 ) ;
V_10 -> V_15 . V_16 = V_91 -> V_6 . V_16 ;
V_10 -> V_15 . V_18 = F_86 ( & V_91 -> V_139 ) >> 16 ;
V_10 -> V_15 . V_17 = F_87 ( & V_91 -> V_139 ) >> 16 ;
V_10 -> V_15 . V_92 = V_91 -> V_92 ;
if ( ! V_10 -> V_15 . V_92 )
return;
V_134 = F_88 ( V_20 ) ;
if ( F_89 ( V_2 , 5 , 6 ) )
V_10 -> V_20 . V_140 = F_90 ( V_134 ) ;
V_10 -> V_20 . V_48 = V_20 -> V_48 ;
V_10 -> V_20 . V_21 = V_20 -> V_141 [ 0 ] ;
V_10 -> V_20 . V_45 = V_134 -> V_45 ;
V_10 -> V_20 . V_142 = V_134 -> V_142 ;
}
static bool F_91 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_109 ;
if ( ! V_10 -> V_15 . V_92 ) {
V_29 -> V_143 = L_6 ;
return false ;
}
if ( ( V_10 -> V_5 . V_135 & V_144 ) ||
( V_10 -> V_5 . V_135 & V_145 ) ) {
V_29 -> V_143 = L_7 ;
return false ;
}
if ( ! F_83 ( V_5 ) ) {
V_29 -> V_143 = L_8 ;
return false ;
}
if ( V_10 -> V_20 . V_142 != V_146 ||
V_10 -> V_20 . V_45 == V_147 ) {
V_29 -> V_143 = L_9 ;
return false ;
}
if ( F_5 ( V_2 ) -> V_3 <= 4 && ! F_81 ( V_2 ) &&
V_10 -> V_15 . V_16 != F_92 ( V_148 ) ) {
V_29 -> V_143 = L_10 ;
return false ;
}
if ( ! F_79 ( V_2 , V_10 -> V_20 . V_21 ) ) {
V_29 -> V_143 = L_11 ;
return false ;
}
if ( ! F_82 ( V_2 , V_10 -> V_20 . V_48 ) ) {
V_29 -> V_143 = L_12 ;
return false ;
}
if ( ( F_4 ( V_2 ) || F_40 ( V_2 ) ) &&
V_10 -> V_5 . V_138 >= V_2 -> V_149 * 95 / 100 ) {
V_29 -> V_143 = L_13 ;
return false ;
}
if ( F_11 ( V_2 , & V_29 -> V_109 ) >
V_29 -> V_108 . V_96 * V_29 -> V_57 ) {
V_29 -> V_143 = L_14 ;
return false ;
}
return true ;
}
static bool F_93 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( F_94 ( V_2 ) ) {
V_29 -> V_143 = L_15 ;
return false ;
}
if ( ! V_150 . V_151 ) {
V_29 -> V_143 = L_16 ;
return false ;
}
if ( F_3 ( V_2 ) && V_5 -> V_72 != V_152 ) {
V_29 -> V_143 = L_17 ;
return false ;
}
if ( F_6 ( V_2 ) && V_5 -> V_15 != V_153 ) {
V_29 -> V_143 = L_18 ;
return false ;
}
return true ;
}
static void F_95 ( struct V_4 * V_5 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_109 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_5 . V_72 = V_5 -> V_72 ;
V_28 -> V_5 . V_15 = V_5 -> V_15 ;
V_28 -> V_5 . V_40 = F_8 ( V_5 ) ;
V_28 -> V_20 . V_48 = V_10 -> V_20 . V_48 ;
V_28 -> V_20 . V_21 = V_10 -> V_20 . V_21 ;
V_28 -> V_20 . V_45 = V_10 -> V_20 . V_45 ;
V_28 -> V_32 = F_11 ( V_2 , V_10 ) ;
V_28 -> V_20 . V_61 = V_10 -> V_20 . V_140 ;
}
static bool F_96 ( struct V_27 * V_154 ,
struct V_27 * V_155 )
{
return memcmp ( V_154 , V_155 , sizeof( * V_154 ) ) == 0 ;
}
void F_97 ( struct V_4 * V_5 ,
struct V_130 * V_131 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( ! F_64 ( V_5 , V_91 ) ) {
V_29 -> V_143 = L_19 ;
goto V_156;
}
if ( ! V_29 -> V_157 || V_29 -> V_5 != V_5 )
goto V_158;
F_84 ( V_5 , V_131 , V_91 ) ;
V_156:
F_63 ( V_2 ) ;
V_158:
F_53 ( & V_29 -> V_83 ) ;
}
static void F_98 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_27 V_159 ;
F_60 ( ! F_61 ( & V_29 -> V_83 ) ) ;
if ( ! V_29 -> V_157 || V_29 -> V_5 != V_5 )
return;
if ( ! F_91 ( V_5 ) ) {
F_60 ( V_29 -> V_75 ) ;
return;
}
V_159 = V_29 -> V_28 ;
F_95 ( V_5 , & V_29 -> V_28 ) ;
if ( V_29 -> V_75 &&
F_96 ( & V_159 , & V_29 -> V_28 ) )
return;
F_63 ( V_2 ) ;
F_58 ( V_5 ) ;
V_29 -> V_143 = L_20 ;
}
void F_99 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
F_98 ( V_5 ) ;
F_53 ( & V_29 -> V_83 ) ;
}
static unsigned int F_100 ( struct V_74 * V_29 )
{
if ( V_29 -> V_157 )
return F_101 ( V_29 -> V_5 -> V_6 . V_160 ) -> V_161 ;
else
return V_29 -> V_162 ;
}
void F_102 ( struct V_1 * V_2 ,
unsigned int V_163 ,
enum V_164 V_165 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_165 == V_166 || V_165 == V_167 )
return;
F_52 ( & V_29 -> V_83 ) ;
V_29 -> V_168 |= F_100 ( V_29 ) & V_163 ;
if ( V_29 -> V_157 && V_29 -> V_168 )
F_63 ( V_2 ) ;
F_53 ( & V_29 -> V_83 ) ;
}
void F_103 ( struct V_1 * V_2 ,
unsigned int V_163 , enum V_164 V_165 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
V_29 -> V_168 &= ~ V_163 ;
if ( V_165 == V_166 || V_165 == V_167 )
goto V_88;
if ( ! V_29 -> V_168 && V_29 -> V_157 &&
( V_163 & F_100 ( V_29 ) ) ) {
if ( V_29 -> V_75 )
F_30 ( V_2 ) ;
else
F_98 ( V_29 -> V_5 ) ;
}
V_88:
F_53 ( & V_29 -> V_83 ) ;
}
void F_104 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_171 * V_5 ;
struct V_172 * V_131 ;
struct V_173 * V_15 ;
struct V_174 * V_91 ;
bool V_175 = false ;
int V_31 , V_176 ;
F_52 ( & V_29 -> V_83 ) ;
F_105 (state, crtc, crtc_state, i) {
if ( V_29 -> V_5 == F_106 ( V_5 ) ) {
V_175 = true ;
break;
}
}
if ( ! V_175 && V_29 -> V_5 != NULL )
goto V_88;
F_107 (state, plane, plane_state, i) {
struct V_90 * V_90 =
F_108 ( V_91 ) ;
if ( ! V_90 -> V_92 )
continue;
F_105 (state, crtc, crtc_state, j) {
struct V_130 * V_130 =
F_109 ( V_131 ) ;
if ( V_91 -> V_5 != V_5 )
continue;
if ( ! F_93 ( F_106 ( V_5 ) ) )
break;
V_130 -> V_151 = true ;
goto V_88;
}
}
V_88:
F_53 ( & V_29 -> V_83 ) ;
}
void F_110 ( struct V_4 * V_5 ,
struct V_130 * V_131 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_157 ) {
F_60 ( V_29 -> V_5 == NULL ) ;
if ( V_29 -> V_5 == V_5 ) {
F_60 ( ! V_131 -> V_151 ) ;
F_60 ( V_29 -> V_75 ) ;
}
goto V_88;
}
if ( ! V_131 -> V_151 )
goto V_88;
F_60 ( V_29 -> V_75 ) ;
F_60 ( V_29 -> V_5 != NULL ) ;
F_84 ( V_5 , V_131 , V_91 ) ;
if ( F_69 ( V_5 ) ) {
V_29 -> V_143 = L_21 ;
goto V_88;
}
F_17 ( L_22 , F_51 ( V_5 -> V_72 ) ) ;
V_29 -> V_143 = L_23 ;
V_29 -> V_157 = true ;
V_29 -> V_5 = V_5 ;
V_88:
F_53 ( & V_29 -> V_83 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
struct V_4 * V_5 = V_29 -> V_5 ;
F_60 ( ! F_61 ( & V_29 -> V_83 ) ) ;
F_60 ( ! V_29 -> V_157 ) ;
F_60 ( V_29 -> V_75 ) ;
F_60 ( V_5 -> V_75 ) ;
F_17 ( L_24 , F_51 ( V_5 -> V_72 ) ) ;
F_77 ( V_2 ) ;
V_29 -> V_157 = false ;
V_29 -> V_5 = NULL ;
}
void F_112 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_59 ( V_5 -> V_6 . V_89 ) ;
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_5 == V_5 ) {
F_60 ( ! V_29 -> V_157 ) ;
F_60 ( V_29 -> V_75 ) ;
F_111 ( V_2 ) ;
}
F_53 ( & V_29 -> V_83 ) ;
F_113 ( & V_29 -> V_78 . V_78 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_157 )
F_111 ( V_2 ) ;
F_53 ( & V_29 -> V_83 ) ;
F_113 ( & V_29 -> V_78 . V_78 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! F_7 ( V_2 ) )
return;
F_116 (&dev_priv->drm, crtc)
if ( F_117 ( & V_5 -> V_6 ) &&
F_108 ( V_5 -> V_6 . V_160 -> V_170 ) -> V_92 )
V_2 -> V_29 . V_93 |= ( 1 << V_5 -> V_72 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
if ( V_150 . V_151 >= 0 )
return ! ! V_150 . V_151 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_40 ( V_2 ) )
return 1 ;
return 0 ;
}
static bool F_119 ( struct V_1 * V_2 )
{
#ifdef F_120
if ( V_177 &&
( F_66 ( V_2 ) || F_121 ( V_2 ) ) ) {
F_71 ( L_25 ) ;
return true ;
}
#endif
return false ;
}
void F_122 ( struct V_1 * V_2 )
{
struct V_74 * V_29 = & V_2 -> V_29 ;
enum V_72 V_72 ;
F_123 ( & V_29 -> V_78 . V_78 , F_47 ) ;
F_124 ( & V_29 -> V_83 ) ;
V_29 -> V_157 = false ;
V_29 -> V_75 = false ;
V_29 -> V_78 . V_84 = false ;
if ( F_119 ( V_2 ) )
F_125 ( V_2 ) -> V_178 = false ;
V_150 . V_151 = F_118 ( V_2 ) ;
F_17 ( L_26 , V_150 . V_151 ) ;
if ( ! F_2 ( V_2 ) ) {
V_29 -> V_143 = L_27 ;
return;
}
F_126 (dev_priv, pipe) {
V_29 -> V_162 |=
F_127 ( V_72 ) ;
if ( F_3 ( V_2 ) )
break;
}
if ( F_5 ( V_2 ) -> V_3 <= 4 && ! F_43 ( V_2 ) )
F_15 ( V_23 , 500 << V_41 ) ;
if ( F_42 ( V_2 ) )
F_45 ( V_2 ) ;
}
