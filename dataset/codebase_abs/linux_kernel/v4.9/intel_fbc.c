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
if ( F_12 ( V_2 ) == 7 )
V_19 = F_13 ( V_19 , 2048 ) ;
else if ( F_12 ( V_2 ) >= 8 )
V_19 = F_13 ( V_19 , 2560 ) ;
return V_19 * V_10 -> V_20 . V_21 ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_22 ;
V_22 = F_15 ( V_23 ) ;
if ( ( V_22 & V_24 ) == 0 )
return;
V_22 &= ~ V_24 ;
F_16 ( V_23 , V_22 ) ;
if ( F_17 ( V_2 ,
V_25 , V_26 , 0 ,
10 ) ) {
F_18 ( L_1 ) ;
return;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
int V_30 ;
int V_31 ;
T_1 V_22 ;
V_30 = V_28 -> V_32 / V_33 ;
if ( V_28 -> V_20 . V_21 < V_30 )
V_30 = V_28 -> V_20 . V_21 ;
if ( F_20 ( V_2 ) )
V_30 = ( V_30 / 32 ) - 1 ;
else
V_30 = ( V_30 / 64 ) - 1 ;
for ( V_31 = 0 ; V_31 < ( V_33 / 32 ) + 1 ; V_31 ++ )
F_16 ( F_21 ( V_31 ) , 0 ) ;
if ( F_22 ( V_2 ) ) {
T_1 V_34 ;
V_34 = V_35 | V_36 | V_37 ;
V_34 |= F_23 ( V_28 -> V_5 . V_15 ) ;
F_16 ( V_38 , V_34 ) ;
F_16 ( V_39 , V_28 -> V_5 . V_40 ) ;
}
V_22 = F_15 ( V_23 ) ;
V_22 &= 0x3fff << V_41 ;
V_22 |= V_24 | V_42 ;
if ( F_24 ( V_2 ) )
V_22 |= V_43 ;
V_22 |= ( V_30 & 0xff ) << V_44 ;
V_22 |= V_28 -> V_20 . V_45 ;
F_16 ( V_23 , V_22 ) ;
}
static bool F_25 ( struct V_1 * V_2 )
{
return F_15 ( V_23 ) & V_24 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_46 ;
V_46 = F_27 ( V_28 -> V_5 . V_15 ) | V_47 ;
if ( F_28 ( V_28 -> V_20 . V_48 , 0 ) == 2 )
V_46 |= V_49 ;
else
V_46 |= V_50 ;
if ( V_28 -> V_20 . V_45 != V_51 ) {
V_46 |= V_52 | V_28 -> V_20 . V_45 ;
F_16 ( V_53 , V_28 -> V_5 . V_40 ) ;
} else {
F_16 ( V_53 , 0 ) ;
}
F_16 ( V_54 , V_46 | V_55 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_15 ( V_54 ) ;
if ( V_46 & V_55 ) {
V_46 &= ~ V_55 ;
F_16 ( V_54 , V_46 ) ;
}
}
static bool F_30 ( struct V_1 * V_2 )
{
return F_15 ( V_54 ) & V_55 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_16 ( V_56 , V_57 ) ;
F_32 ( V_56 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_46 ;
int V_58 = V_2 -> V_29 . V_58 ;
V_46 = F_27 ( V_28 -> V_5 . V_15 ) ;
if ( F_28 ( V_28 -> V_20 . V_48 , 0 ) == 2 )
V_58 ++ ;
switch ( V_58 ) {
case 4 :
case 3 :
V_46 |= V_59 ;
break;
case 2 :
V_46 |= V_49 ;
break;
case 1 :
V_46 |= V_50 ;
break;
}
if ( V_28 -> V_20 . V_45 != V_51 ) {
V_46 |= V_52 ;
if ( F_34 ( V_2 ) )
V_46 |= V_28 -> V_20 . V_45 ;
if ( F_35 ( V_2 ) ) {
F_16 ( V_60 ,
V_61 | V_28 -> V_20 . V_45 ) ;
F_16 ( V_62 ,
V_28 -> V_5 . V_40 ) ;
}
} else {
if ( F_35 ( V_2 ) ) {
F_16 ( V_60 , 0 ) ;
F_16 ( V_62 , 0 ) ;
}
}
F_16 ( V_63 , V_28 -> V_5 . V_40 ) ;
F_16 ( V_64 , V_28 -> V_20 . V_65 | V_66 ) ;
F_16 ( V_67 , V_46 | V_55 ) ;
F_31 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_15 ( V_67 ) ;
if ( V_46 & V_55 ) {
V_46 &= ~ V_55 ;
F_16 ( V_67 , V_46 ) ;
}
}
static bool F_37 ( struct V_1 * V_2 )
{
return F_15 ( V_67 ) & V_55 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_46 ;
int V_58 = V_2 -> V_29 . V_58 ;
V_46 = 0 ;
if ( F_39 ( V_2 ) )
V_46 |= F_40 ( V_28 -> V_5 . V_15 ) ;
if ( F_28 ( V_28 -> V_20 . V_48 , 0 ) == 2 )
V_58 ++ ;
switch ( V_58 ) {
case 4 :
case 3 :
V_46 |= V_59 ;
break;
case 2 :
V_46 |= V_49 ;
break;
case 1 :
V_46 |= V_50 ;
break;
}
if ( V_28 -> V_20 . V_45 != V_51 ) {
V_46 |= V_68 ;
F_16 ( V_60 ,
V_61 | V_28 -> V_20 . V_45 ) ;
F_16 ( V_62 , V_28 -> V_5 . V_40 ) ;
} else {
F_16 ( V_60 , 0 ) ;
F_16 ( V_62 , 0 ) ;
}
if ( V_2 -> V_29 . V_69 )
V_46 |= V_70 ;
if ( F_39 ( V_2 ) ) {
F_16 ( V_71 ,
F_15 ( V_71 ) |
V_72 ) ;
} else if ( F_4 ( V_2 ) || F_41 ( V_2 ) ) {
F_16 ( F_42 ( V_28 -> V_5 . V_73 ) ,
F_15 ( F_42 ( V_28 -> V_5 . V_73 ) ) |
V_74 ) ;
}
F_16 ( V_67 , V_46 | V_55 ) ;
F_31 ( V_2 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) -> V_3 >= 5 )
return F_37 ( V_2 ) ;
else if ( F_44 ( V_2 ) )
return F_30 ( V_2 ) ;
else
return F_25 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
V_29 -> V_76 = true ;
if ( F_5 ( V_2 ) -> V_3 >= 7 )
F_38 ( V_2 ) ;
else if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_33 ( V_2 ) ;
else if ( F_44 ( V_2 ) )
F_26 ( V_2 ) ;
else
F_19 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
V_29 -> V_76 = false ;
if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_36 ( V_2 ) ;
else if ( F_44 ( V_2 ) )
F_29 ( V_2 ) ;
else
F_14 ( V_2 ) ;
}
bool F_47 ( struct V_1 * V_2 )
{
return V_2 -> V_29 . V_76 ;
}
static void F_48 ( struct V_77 * V_78 )
{
struct V_1 * V_2 =
F_49 ( V_78 , struct V_1 , V_29 . V_79 . V_79 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_80 * V_79 = & V_29 -> V_79 ;
struct V_4 * V_5 = V_29 -> V_5 ;
struct V_81 * V_82 = & V_2 -> V_83 . V_82 [ V_5 -> V_73 ] ;
if ( F_50 ( & V_5 -> V_6 ) ) {
F_51 ( L_2 ,
F_52 ( V_5 -> V_73 ) ) ;
F_53 ( & V_29 -> V_84 ) ;
V_79 -> V_85 = false ;
F_54 ( & V_29 -> V_84 ) ;
return;
}
V_86:
F_55 ( V_82 -> V_87 ,
F_56 ( & V_5 -> V_6 ) != V_79 -> V_88 ,
F_57 ( 50 ) ) ;
F_53 ( & V_29 -> V_84 ) ;
if ( ! V_79 -> V_85 )
goto V_89;
if ( F_56 ( & V_5 -> V_6 ) == V_79 -> V_88 ) {
F_54 ( & V_29 -> V_84 ) ;
goto V_86;
}
F_45 ( V_2 ) ;
V_79 -> V_85 = false ;
V_89:
F_54 ( & V_29 -> V_84 ) ;
F_58 ( & V_5 -> V_6 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_80 * V_79 = & V_29 -> V_79 ;
F_61 ( ! F_62 ( & V_29 -> V_84 ) ) ;
if ( F_50 ( & V_5 -> V_6 ) ) {
F_51 ( L_2 ,
F_52 ( V_5 -> V_73 ) ) ;
return;
}
V_79 -> V_85 = true ;
V_79 -> V_88 = F_56 ( & V_5 -> V_6 ) ;
F_58 ( & V_5 -> V_6 ) ;
F_63 ( & V_79 -> V_79 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
F_61 ( ! F_62 ( & V_29 -> V_84 ) ) ;
V_29 -> V_79 . V_85 = false ;
if ( V_29 -> V_76 )
F_46 ( V_2 ) ;
}
static bool F_65 ( struct V_4 * V_5 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
enum V_73 V_73 = V_5 -> V_73 ;
if ( ! F_7 ( V_2 ) )
return true ;
if ( V_92 -> V_6 . V_93 )
V_29 -> V_94 |= ( 1 << V_73 ) ;
else
V_29 -> V_94 &= ~ ( 1 << V_73 ) ;
return ( V_29 -> V_94 & ~ ( 1 << V_73 ) ) != 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
int V_97 ,
int V_98 )
{
struct V_99 * V_100 = & V_2 -> V_100 ;
int V_101 = 1 ;
int V_102 ;
T_2 V_103 ;
if ( F_41 ( V_2 ) ||
F_67 ( V_2 ) || F_68 ( V_2 ) )
V_103 = V_100 -> V_104 - 8 * 1024 * 1024 ;
else
V_103 = V_100 -> V_105 ;
V_102 = F_69 ( V_2 , V_96 , V_97 <<= 1 ,
4096 , 0 , V_103 ) ;
if ( V_102 == 0 )
return V_101 ;
V_106:
if ( V_101 > 4 ||
( V_98 == 2 && V_101 == 2 ) )
return 0 ;
V_102 = F_69 ( V_2 , V_96 , V_97 >>= 1 ,
4096 , 0 , V_103 ) ;
if ( V_102 && F_5 ( V_2 ) -> V_3 <= 4 ) {
return 0 ;
} else if ( V_102 ) {
V_101 <<= 1 ;
goto V_106;
} else {
return V_101 ;
}
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_95 * V_107 ( V_108 ) ;
int V_97 , V_98 , V_102 ;
F_61 ( F_71 ( & V_29 -> V_109 ) ) ;
V_97 = F_11 ( V_2 , & V_29 -> V_110 ) ;
V_98 = F_28 ( V_29 -> V_110 . V_20 . V_48 , 0 ) ;
V_102 = F_66 ( V_2 , & V_29 -> V_109 ,
V_97 , V_98 ) ;
if ( ! V_102 )
goto V_111;
else if ( V_102 > 1 ) {
F_72 ( L_3 ) ;
}
V_29 -> V_58 = V_102 ;
if ( F_5 ( V_2 ) -> V_3 >= 5 )
F_16 ( V_112 , V_29 -> V_109 . V_113 ) ;
else if ( F_44 ( V_2 ) ) {
F_16 ( V_114 , V_29 -> V_109 . V_113 ) ;
} else {
V_108 = F_73 ( sizeof( * V_108 ) , V_115 ) ;
if ( ! V_108 )
goto V_116;
V_102 = F_74 ( V_2 , V_108 ,
4096 , 4096 ) ;
if ( V_102 )
goto V_116;
V_29 -> V_108 = V_108 ;
F_16 ( V_117 ,
V_2 -> V_118 . V_119 + V_29 -> V_109 . V_113 ) ;
F_16 ( V_120 ,
V_2 -> V_118 . V_119 + V_108 -> V_113 ) ;
}
F_18 ( L_4 ,
V_29 -> V_109 . V_97 , V_29 -> V_58 ) ;
return 0 ;
V_116:
F_75 ( V_108 ) ;
F_76 ( V_2 , & V_29 -> V_109 ) ;
V_111:
F_77 ( L_5 , V_97 ) ;
return - V_121 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( F_71 ( & V_29 -> V_109 ) )
F_76 ( V_2 , & V_29 -> V_109 ) ;
if ( V_29 -> V_108 ) {
F_76 ( V_2 , V_29 -> V_108 ) ;
F_75 ( V_29 -> V_108 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
F_78 ( V_2 ) ;
F_54 ( & V_29 -> V_84 ) ;
}
static bool F_80 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
F_61 ( V_21 < 512 ) ;
F_61 ( ( V_21 & ( 64 - 1 ) ) != 0 ) ;
if ( F_20 ( V_2 ) || F_81 ( V_2 ) )
return V_21 == 4096 || V_21 == 8192 ;
if ( F_22 ( V_2 ) && ! F_82 ( V_2 ) && V_21 < 2048 )
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
if ( F_20 ( V_2 ) )
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
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
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
static int F_85 ( struct V_131 * V_20 )
{
struct V_132 * V_133 = F_86 ( F_87 ( V_20 ) , NULL ) ;
return V_133 && V_133 -> V_134 ? V_133 -> V_134 -> V_135 : V_51 ;
}
static void F_88 ( struct V_4 * V_5 ,
struct V_136 * V_137 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_110 ;
struct V_131 * V_20 = V_92 -> V_6 . V_20 ;
struct V_138 * V_139 ;
V_10 -> V_5 . V_140 = V_137 -> V_6 . V_141 . V_142 ;
if ( F_4 ( V_2 ) || F_41 ( V_2 ) )
V_10 -> V_5 . V_143 =
F_89 ( V_137 ) ;
V_10 -> V_15 . V_16 = V_92 -> V_6 . V_16 ;
V_10 -> V_15 . V_18 = F_90 ( & V_92 -> V_6 . V_144 ) >> 16 ;
V_10 -> V_15 . V_17 = F_91 ( & V_92 -> V_6 . V_144 ) >> 16 ;
V_10 -> V_15 . V_93 = V_92 -> V_6 . V_93 ;
if ( ! V_10 -> V_15 . V_93 )
return;
V_139 = F_87 ( V_20 ) ;
if ( F_92 ( V_2 , 5 , 6 ) )
V_10 -> V_20 . V_145 = F_93 ( V_139 , NULL ) ;
V_10 -> V_20 . V_48 = V_20 -> V_48 ;
V_10 -> V_20 . V_21 = V_20 -> V_146 [ 0 ] ;
V_10 -> V_20 . V_45 = F_85 ( V_20 ) ;
V_10 -> V_20 . V_147 = F_94 ( V_139 ) ;
}
static bool F_95 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_110 ;
if ( ! V_10 -> V_15 . V_93 ) {
V_29 -> V_148 = L_6 ;
return false ;
}
if ( ( V_10 -> V_5 . V_140 & V_149 ) ||
( V_10 -> V_5 . V_140 & V_150 ) ) {
V_29 -> V_148 = L_7 ;
return false ;
}
if ( ! F_84 ( V_5 ) ) {
V_29 -> V_148 = L_8 ;
return false ;
}
if ( V_10 -> V_20 . V_147 != V_151 ||
V_10 -> V_20 . V_45 == V_51 ) {
V_29 -> V_148 = L_9 ;
return false ;
}
if ( F_5 ( V_2 ) -> V_3 <= 4 && ! F_82 ( V_2 ) &&
V_10 -> V_15 . V_16 != V_152 ) {
V_29 -> V_148 = L_10 ;
return false ;
}
if ( ! F_80 ( V_2 , V_10 -> V_20 . V_21 ) ) {
V_29 -> V_148 = L_11 ;
return false ;
}
if ( ! F_83 ( V_2 , V_10 -> V_20 . V_48 ) ) {
V_29 -> V_148 = L_12 ;
return false ;
}
if ( ( F_4 ( V_2 ) || F_41 ( V_2 ) ) &&
V_10 -> V_5 . V_143 >= V_2 -> V_153 * 95 / 100 ) {
V_29 -> V_148 = L_13 ;
return false ;
}
if ( F_11 ( V_2 , & V_29 -> V_110 ) >
V_29 -> V_109 . V_97 * V_29 -> V_58 ) {
V_29 -> V_148 = L_14 ;
return false ;
}
return true ;
}
static bool F_96 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( F_97 ( V_2 ) ) {
V_29 -> V_148 = L_15 ;
return false ;
}
if ( ! V_154 . V_155 ) {
V_29 -> V_148 = L_16 ;
return false ;
}
if ( F_3 ( V_2 ) && V_5 -> V_73 != V_156 ) {
V_29 -> V_148 = L_17 ;
return false ;
}
if ( F_6 ( V_2 ) && V_5 -> V_15 != V_157 ) {
V_29 -> V_148 = L_18 ;
return false ;
}
return true ;
}
static void F_98 ( struct V_4 * V_5 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_9 * V_10 = & V_29 -> V_110 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_5 . V_73 = V_5 -> V_73 ;
V_28 -> V_5 . V_15 = V_5 -> V_15 ;
V_28 -> V_5 . V_40 = F_8 ( V_5 ) ;
V_28 -> V_20 . V_48 = V_10 -> V_20 . V_48 ;
V_28 -> V_20 . V_21 = V_10 -> V_20 . V_21 ;
V_28 -> V_20 . V_45 = V_10 -> V_20 . V_45 ;
V_28 -> V_32 = F_11 ( V_2 , V_10 ) ;
V_28 -> V_20 . V_65 = V_10 -> V_20 . V_145 ;
}
static bool F_99 ( struct V_27 * V_158 ,
struct V_27 * V_159 )
{
return memcmp ( V_158 , V_159 , sizeof( * V_158 ) ) == 0 ;
}
void F_100 ( struct V_4 * V_5 ,
struct V_136 * V_137 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
if ( ! F_65 ( V_5 , V_92 ) ) {
V_29 -> V_148 = L_19 ;
goto V_160;
}
if ( ! V_29 -> V_161 || V_29 -> V_5 != V_5 )
goto V_162;
F_88 ( V_5 , V_137 , V_92 ) ;
V_160:
F_64 ( V_2 ) ;
V_162:
F_54 ( & V_29 -> V_84 ) ;
}
static void F_101 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_27 V_163 ;
F_61 ( ! F_62 ( & V_29 -> V_84 ) ) ;
if ( ! V_29 -> V_161 || V_29 -> V_5 != V_5 )
return;
if ( ! F_95 ( V_5 ) ) {
F_61 ( V_29 -> V_76 ) ;
return;
}
V_163 = V_29 -> V_28 ;
F_98 ( V_5 , & V_29 -> V_28 ) ;
if ( V_29 -> V_76 &&
F_99 ( & V_163 , & V_29 -> V_28 ) )
return;
F_64 ( V_2 ) ;
F_59 ( V_5 ) ;
V_29 -> V_148 = L_20 ;
}
void F_102 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
F_101 ( V_5 ) ;
F_54 ( & V_29 -> V_84 ) ;
}
static unsigned int F_103 ( struct V_75 * V_29 )
{
if ( V_29 -> V_161 )
return F_104 ( V_29 -> V_5 -> V_6 . V_164 ) -> V_165 ;
else
return V_29 -> V_166 ;
}
void F_105 ( struct V_1 * V_2 ,
unsigned int V_167 ,
enum V_168 V_169 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_169 == V_170 || V_169 == V_171 )
return;
F_53 ( & V_29 -> V_84 ) ;
V_29 -> V_172 |= F_103 ( V_29 ) & V_167 ;
if ( V_29 -> V_161 && V_29 -> V_172 )
F_64 ( V_2 ) ;
F_54 ( & V_29 -> V_84 ) ;
}
void F_106 ( struct V_1 * V_2 ,
unsigned int V_167 , enum V_168 V_169 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
V_29 -> V_172 &= ~ V_167 ;
if ( V_169 == V_170 || V_169 == V_171 )
goto V_89;
if ( ! V_29 -> V_172 && V_29 -> V_161 &&
( V_167 & F_103 ( V_29 ) ) ) {
if ( V_29 -> V_76 )
F_31 ( V_2 ) ;
else
F_101 ( V_29 -> V_5 ) ;
}
V_89:
F_54 ( & V_29 -> V_84 ) ;
}
void F_107 ( struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_175 * V_5 ;
struct V_176 * V_137 ;
struct V_177 * V_15 ;
struct V_178 * V_92 ;
bool V_179 = false ;
int V_31 , V_180 ;
F_53 ( & V_29 -> V_84 ) ;
F_108 (state, crtc, crtc_state, i) {
if ( V_29 -> V_5 == F_109 ( V_5 ) ) {
V_179 = true ;
break;
}
}
if ( ! V_179 && V_29 -> V_5 != NULL )
goto V_89;
F_110 (state, plane, plane_state, i) {
struct V_91 * V_91 =
F_111 ( V_92 ) ;
if ( ! V_91 -> V_6 . V_93 )
continue;
F_108 (state, crtc, crtc_state, j) {
struct V_136 * V_136 =
F_112 ( V_137 ) ;
if ( V_92 -> V_5 != V_5 )
continue;
if ( ! F_96 ( F_109 ( V_5 ) ) )
break;
V_136 -> V_155 = true ;
goto V_89;
}
}
V_89:
F_54 ( & V_29 -> V_84 ) ;
}
void F_113 ( struct V_4 * V_5 ,
struct V_136 * V_137 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
if ( V_29 -> V_161 ) {
F_61 ( V_29 -> V_5 == NULL ) ;
if ( V_29 -> V_5 == V_5 ) {
F_61 ( ! V_137 -> V_155 ) ;
F_61 ( V_29 -> V_76 ) ;
}
goto V_89;
}
if ( ! V_137 -> V_155 )
goto V_89;
F_61 ( V_29 -> V_76 ) ;
F_61 ( V_29 -> V_5 != NULL ) ;
F_88 ( V_5 , V_137 , V_92 ) ;
if ( F_70 ( V_5 ) ) {
V_29 -> V_148 = L_21 ;
goto V_89;
}
F_18 ( L_22 , F_52 ( V_5 -> V_73 ) ) ;
V_29 -> V_148 = L_23 ;
V_29 -> V_161 = true ;
V_29 -> V_5 = V_5 ;
V_89:
F_54 ( & V_29 -> V_84 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
struct V_4 * V_5 = V_29 -> V_5 ;
F_61 ( ! F_62 ( & V_29 -> V_84 ) ) ;
F_61 ( ! V_29 -> V_161 ) ;
F_61 ( V_29 -> V_76 ) ;
F_61 ( V_5 -> V_76 ) ;
F_18 ( L_24 , F_52 ( V_5 -> V_73 ) ) ;
F_78 ( V_2 ) ;
V_29 -> V_161 = false ;
V_29 -> V_5 = NULL ;
}
void F_115 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_60 ( V_5 -> V_6 . V_90 ) ;
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
if ( V_29 -> V_5 == V_5 )
F_114 ( V_2 ) ;
F_54 ( & V_29 -> V_84 ) ;
F_116 ( & V_29 -> V_79 . V_79 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_29 -> V_84 ) ;
if ( V_29 -> V_161 )
F_114 ( V_2 ) ;
F_54 ( & V_29 -> V_84 ) ;
F_116 ( & V_29 -> V_79 . V_79 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! F_7 ( V_2 ) )
return;
F_119 (&dev_priv->drm, crtc)
if ( F_120 ( & V_5 -> V_6 ) &&
F_111 ( V_5 -> V_6 . V_164 -> V_174 ) -> V_6 . V_93 )
V_2 -> V_29 . V_94 |= ( 1 << V_5 -> V_73 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
if ( V_154 . V_155 >= 0 )
return ! ! V_154 . V_155 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_41 ( V_2 ) )
return 1 ;
return 0 ;
}
static bool F_122 ( struct V_1 * V_2 )
{
#ifdef F_123
if ( V_181 &&
( F_67 ( V_2 ) || F_124 ( V_2 ) ) ) {
F_72 ( L_25 ) ;
return true ;
}
#endif
return false ;
}
void F_125 ( struct V_1 * V_2 )
{
struct V_75 * V_29 = & V_2 -> V_29 ;
enum V_73 V_73 ;
F_126 ( & V_29 -> V_79 . V_79 , F_48 ) ;
F_127 ( & V_29 -> V_84 ) ;
V_29 -> V_161 = false ;
V_29 -> V_76 = false ;
V_29 -> V_79 . V_85 = false ;
if ( F_122 ( V_2 ) )
F_128 ( V_2 ) -> V_182 = false ;
V_154 . V_155 = F_121 ( V_2 ) ;
F_18 ( L_26 , V_154 . V_155 ) ;
if ( ! F_2 ( V_2 ) ) {
V_29 -> V_148 = L_27 ;
return;
}
F_129 (dev_priv, pipe) {
V_29 -> V_166 |=
F_130 ( V_73 ) ;
if ( F_3 ( V_2 ) )
break;
}
if ( F_5 ( V_2 ) -> V_3 <= 4 && ! F_44 ( V_2 ) )
F_16 ( V_23 , 500 << V_41 ) ;
if ( F_43 ( V_2 ) )
F_46 ( V_2 ) ;
}
