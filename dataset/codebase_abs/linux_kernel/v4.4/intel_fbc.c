static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 != NULL ;
}
static unsigned int F_2 ( struct V_5 * V_6 )
{
return V_6 -> V_7 . V_8 - V_6 -> V_9 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_2 -> V_3 . V_11 = false ;
V_10 = F_4 ( V_12 ) ;
if ( ( V_10 & V_13 ) == 0 )
return;
V_10 &= ~ V_13 ;
F_5 ( V_12 , V_10 ) ;
if ( F_6 ( ( F_4 ( V_14 ) & V_15 ) == 0 , 10 ) ) {
F_7 ( L_1 ) ;
return;
}
F_7 ( L_2 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_7 . V_20 -> V_19 ;
struct V_21 * V_22 = F_9 ( V_19 ) ;
int V_23 ;
int V_24 ;
T_1 V_10 ;
V_2 -> V_3 . V_11 = true ;
V_23 = V_2 -> V_3 . V_25 / V_26 ;
if ( V_19 -> V_27 [ 0 ] < V_23 )
V_23 = V_19 -> V_27 [ 0 ] ;
if ( F_10 ( V_2 ) )
V_23 = ( V_23 / 32 ) - 1 ;
else
V_23 = ( V_23 / 64 ) - 1 ;
for ( V_24 = 0 ; V_24 < ( V_26 / 32 ) + 1 ; V_24 ++ )
F_5 ( F_11 ( V_24 ) , 0 ) ;
if ( F_12 ( V_2 ) ) {
T_1 V_28 ;
V_28 = V_29 | V_30 | V_31 ;
V_28 |= F_13 ( V_6 -> V_32 ) ;
F_5 ( V_33 , V_28 ) ;
F_5 ( V_34 , F_2 ( V_6 ) ) ;
}
V_10 = F_4 ( V_12 ) ;
V_10 &= 0x3fff << V_35 ;
V_10 |= V_13 | V_36 ;
if ( F_14 ( V_2 ) )
V_10 |= V_37 ;
V_10 |= ( V_23 & 0xff ) << V_38 ;
V_10 |= V_22 -> V_39 ;
F_5 ( V_12 , V_10 ) ;
F_7 ( L_3 ,
V_23 , V_6 -> V_7 . V_8 , F_15 ( V_6 -> V_32 ) ) ;
}
static bool F_16 ( struct V_1 * V_2 )
{
return F_4 ( V_12 ) & V_13 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_7 . V_20 -> V_19 ;
struct V_21 * V_22 = F_9 ( V_19 ) ;
T_1 V_40 ;
V_2 -> V_3 . V_11 = true ;
V_40 = F_18 ( V_6 -> V_32 ) | V_41 ;
if ( F_19 ( V_19 -> V_42 , 0 ) == 2 )
V_40 |= V_43 ;
else
V_40 |= V_44 ;
V_40 |= V_45 | V_22 -> V_39 ;
F_5 ( V_46 , F_2 ( V_6 ) ) ;
F_5 ( V_47 , V_40 | V_48 ) ;
F_7 ( L_4 , F_15 ( V_6 -> V_32 ) ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_40 ;
V_2 -> V_3 . V_11 = false ;
V_40 = F_4 ( V_47 ) ;
if ( V_40 & V_48 ) {
V_40 &= ~ V_48 ;
F_5 ( V_47 , V_40 ) ;
F_7 ( L_2 ) ;
}
}
static bool F_21 ( struct V_1 * V_2 )
{
return F_4 ( V_47 ) & V_48 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_5 ( V_49 , V_50 ) ;
F_23 ( V_49 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_7 . V_20 -> V_19 ;
struct V_21 * V_22 = F_9 ( V_19 ) ;
T_1 V_40 ;
int V_51 = V_2 -> V_3 . V_51 ;
unsigned int V_52 ;
V_2 -> V_3 . V_11 = true ;
V_40 = F_18 ( V_6 -> V_32 ) ;
if ( F_19 ( V_19 -> V_42 , 0 ) == 2 )
V_51 ++ ;
switch ( V_51 ) {
case 4 :
case 3 :
V_40 |= V_53 ;
break;
case 2 :
V_40 |= V_43 ;
break;
case 1 :
V_40 |= V_44 ;
break;
}
V_40 |= V_45 ;
if ( F_25 ( V_2 ) )
V_40 |= V_22 -> V_39 ;
V_52 = F_2 ( V_6 ) ;
F_5 ( V_54 , V_52 ) ;
F_5 ( V_55 , F_26 ( V_22 ) | V_56 ) ;
F_5 ( V_57 , V_40 | V_48 ) ;
if ( F_27 ( V_2 ) ) {
F_5 ( V_58 ,
V_59 | V_22 -> V_39 ) ;
F_5 ( V_60 , V_52 ) ;
}
F_22 ( V_2 ) ;
F_7 ( L_4 , F_15 ( V_6 -> V_32 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_40 ;
V_2 -> V_3 . V_11 = false ;
V_40 = F_4 ( V_57 ) ;
if ( V_40 & V_48 ) {
V_40 &= ~ V_48 ;
F_5 ( V_57 , V_40 ) ;
F_7 ( L_2 ) ;
}
}
static bool F_29 ( struct V_1 * V_2 )
{
return F_4 ( V_57 ) & V_48 ;
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_7 . V_20 -> V_19 ;
struct V_21 * V_22 = F_9 ( V_19 ) ;
T_1 V_40 ;
int V_51 = V_2 -> V_3 . V_51 ;
V_2 -> V_3 . V_11 = true ;
V_40 = 0 ;
if ( F_31 ( V_2 ) )
V_40 |= F_32 ( V_6 -> V_32 ) ;
if ( F_19 ( V_19 -> V_42 , 0 ) == 2 )
V_51 ++ ;
switch ( V_51 ) {
case 4 :
case 3 :
V_40 |= V_53 ;
break;
case 2 :
V_40 |= V_43 ;
break;
case 1 :
V_40 |= V_44 ;
break;
}
V_40 |= V_61 ;
if ( V_2 -> V_3 . V_62 )
V_40 |= V_63 ;
if ( F_31 ( V_2 ) ) {
F_5 ( V_64 ,
F_4 ( V_64 ) |
V_65 ) ;
} else if ( F_33 ( V_2 ) || F_34 ( V_2 ) ) {
F_5 ( F_35 ( V_6 -> V_66 ) ,
F_4 ( F_35 ( V_6 -> V_66 ) ) |
V_67 ) ;
}
F_5 ( V_57 , V_40 | V_48 ) ;
F_5 ( V_58 ,
V_59 | V_22 -> V_39 ) ;
F_5 ( V_60 , F_2 ( V_6 ) ) ;
F_22 ( V_2 ) ;
F_7 ( L_4 , F_15 ( V_6 -> V_32 ) ) ;
}
bool F_36 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_11 ;
}
static void F_37 ( struct V_5 * V_6 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
V_2 -> V_3 . V_4 ( V_6 ) ;
V_2 -> V_3 . V_6 = V_6 ;
V_2 -> V_3 . V_68 = V_19 -> V_7 . V_69 ;
V_2 -> V_3 . V_8 = V_6 -> V_7 . V_8 ;
}
static void F_38 ( struct V_70 * V_71 )
{
struct V_72 * V_73 =
F_39 ( F_40 ( V_71 ) ,
struct V_72 , V_73 ) ;
struct V_1 * V_2 = V_73 -> V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_74 = V_73 -> V_6 -> V_7 . V_20 -> V_19 ;
F_41 ( & V_2 -> V_3 . V_75 ) ;
if ( V_73 == V_2 -> V_3 . V_76 ) {
if ( V_74 == V_73 -> V_19 )
F_37 ( V_73 -> V_6 , V_73 -> V_19 ) ;
V_2 -> V_3 . V_76 = NULL ;
}
F_42 ( & V_2 -> V_3 . V_75 ) ;
F_43 ( V_73 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( ! F_46 ( & V_2 -> V_3 . V_75 ) ) ;
if ( V_2 -> V_3 . V_76 == NULL )
return;
F_7 ( L_5 ) ;
if ( F_47 ( & V_2 -> V_3 . V_76 -> V_73 ) )
F_43 ( V_2 -> V_3 . V_76 ) ;
V_2 -> V_3 . V_76 = NULL ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_72 * V_73 ;
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
F_45 ( ! F_46 ( & V_2 -> V_3 . V_75 ) ) ;
F_44 ( V_2 ) ;
V_73 = F_49 ( sizeof( * V_73 ) , V_77 ) ;
if ( V_73 == NULL ) {
F_50 ( L_6 ) ;
F_37 ( V_6 , V_6 -> V_7 . V_20 -> V_19 ) ;
return;
}
V_73 -> V_6 = V_6 ;
V_73 -> V_19 = V_6 -> V_7 . V_20 -> V_19 ;
F_51 ( & V_73 -> V_73 , F_38 ) ;
V_2 -> V_3 . V_76 = V_73 ;
F_52 ( & V_73 -> V_73 , F_53 ( 50 ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_45 ( ! F_46 ( & V_2 -> V_3 . V_75 ) ) ;
F_44 ( V_2 ) ;
V_2 -> V_3 . V_78 ( V_2 ) ;
V_2 -> V_3 . V_6 = NULL ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return;
F_41 ( & V_2 -> V_3 . V_75 ) ;
F_54 ( V_2 ) ;
F_42 ( & V_2 -> V_3 . V_75 ) ;
}
void F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
if ( ! F_1 ( V_2 ) )
return;
F_41 ( & V_2 -> V_3 . V_75 ) ;
if ( V_2 -> V_3 . V_6 == V_6 )
F_54 ( V_2 ) ;
F_42 ( & V_2 -> V_3 . V_75 ) ;
}
const char * F_57 ( enum V_79 V_80 )
{
switch ( V_80 ) {
case V_81 :
return L_7 ;
case V_82 :
return L_8 ;
case V_83 :
return L_9 ;
case V_84 :
return L_10 ;
case V_85 :
return L_11 ;
case V_86 :
return L_12 ;
case V_87 :
return L_13 ;
case V_88 :
return L_14 ;
case V_89 :
return L_15 ;
case V_90 :
return L_16 ;
case V_91 :
return L_17 ;
case V_92 :
return L_18 ;
case V_93 :
return L_19 ;
case V_94 :
return L_20 ;
case V_95 :
return L_21 ;
case V_96 :
return L_22 ;
default:
F_58 ( V_80 ) ;
return L_23 ;
}
}
static void F_59 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
if ( V_2 -> V_3 . V_79 == V_80 )
return;
V_2 -> V_3 . V_79 = V_80 ;
F_7 ( L_24 , F_57 ( V_80 ) ) ;
}
static struct V_97 * F_60 ( struct V_1 * V_2 )
{
struct V_97 * V_6 = NULL , * V_98 ;
enum V_66 V_66 ;
bool V_99 = false ;
if ( F_33 ( V_2 ) || F_61 ( V_2 ) -> V_100 >= 8 )
V_99 = true ;
F_62 (dev_priv, pipe) {
V_98 = V_2 -> V_101 [ V_66 ] ;
if ( F_63 ( V_98 ) &&
F_64 ( V_98 -> V_20 -> V_102 ) -> V_103 )
V_6 = V_98 ;
if ( V_99 )
break;
}
if ( ! V_6 || V_6 -> V_20 -> V_19 == NULL )
return NULL ;
return V_6 ;
}
static bool F_65 ( struct V_1 * V_2 )
{
enum V_66 V_66 ;
int V_104 = 0 ;
struct V_97 * V_6 ;
if ( F_61 ( V_2 ) -> V_100 > 4 )
return true ;
F_62 (dev_priv, pipe) {
V_6 = V_2 -> V_101 [ V_66 ] ;
if ( F_63 ( V_6 ) &&
F_64 ( V_6 -> V_20 -> V_102 ) -> V_103 )
V_104 ++ ;
}
return ( V_104 < 2 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
int V_107 ,
int V_108 )
{
int V_109 = 1 ;
int V_110 ;
T_2 V_111 ;
if ( F_34 ( V_2 ) || F_67 ( V_2 ) )
V_111 = V_2 -> V_112 . V_113 - 8 * 1024 * 1024 ;
else
V_111 = V_2 -> V_112 . V_114 ;
V_110 = F_68 ( V_2 , V_106 , V_107 <<= 1 ,
4096 , 0 , V_111 ) ;
if ( V_110 == 0 )
return V_109 ;
V_115:
if ( V_109 > 4 ||
( V_108 == 2 && V_109 == 2 ) )
return 0 ;
V_110 = F_68 ( V_2 , V_106 , V_107 >>= 1 ,
4096 , 0 , V_111 ) ;
if ( V_110 && F_61 ( V_2 ) -> V_100 <= 4 ) {
return 0 ;
} else if ( V_110 ) {
V_109 <<= 1 ;
goto V_115;
} else {
return V_109 ;
}
}
static int F_69 ( struct V_1 * V_2 , int V_107 ,
int V_108 )
{
struct V_105 * V_116 ( V_117 ) ;
int V_110 ;
V_110 = F_66 ( V_2 , & V_2 -> V_3 . V_118 ,
V_107 , V_108 ) ;
if ( ! V_110 )
goto V_119;
else if ( V_110 > 1 ) {
F_70 ( L_25 ) ;
}
V_2 -> V_3 . V_51 = V_110 ;
if ( F_61 ( V_2 ) -> V_100 >= 5 )
F_5 ( V_120 , V_2 -> V_3 . V_118 . V_121 ) ;
else if ( F_71 ( V_2 ) ) {
F_5 ( V_122 , V_2 -> V_3 . V_118 . V_121 ) ;
} else {
V_117 = F_49 ( sizeof( * V_117 ) , V_77 ) ;
if ( ! V_117 )
goto V_123;
V_110 = F_72 ( V_2 , V_117 ,
4096 , 4096 ) ;
if ( V_110 )
goto V_123;
V_2 -> V_3 . V_117 = V_117 ;
F_5 ( V_124 ,
V_2 -> V_125 . V_126 + V_2 -> V_3 . V_118 . V_121 ) ;
F_5 ( V_127 ,
V_2 -> V_125 . V_126 + V_117 -> V_121 ) ;
}
V_2 -> V_3 . V_25 = V_107 ;
F_7 ( L_26 ,
V_2 -> V_3 . V_118 . V_107 ,
V_2 -> V_3 . V_51 ) ;
return 0 ;
V_123:
F_43 ( V_117 ) ;
F_73 ( V_2 , & V_2 -> V_3 . V_118 ) ;
V_119:
F_74 ( L_27 , V_107 ) ;
return - V_128 ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_25 == 0 )
return;
F_73 ( V_2 , & V_2 -> V_3 . V_118 ) ;
if ( V_2 -> V_3 . V_117 ) {
F_73 ( V_2 ,
V_2 -> V_3 . V_117 ) ;
F_43 ( V_2 -> V_3 . V_117 ) ;
}
V_2 -> V_3 . V_25 = 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return;
F_41 ( & V_2 -> V_3 . V_75 ) ;
F_75 ( V_2 ) ;
F_42 ( & V_2 -> V_3 . V_75 ) ;
}
static void F_77 ( struct V_5 * V_6 ,
int * V_129 , int * V_130 )
{
struct V_131 * V_132 =
F_64 ( V_6 -> V_7 . V_20 -> V_102 ) ;
int V_133 , V_134 ;
if ( F_78 ( V_132 -> V_7 . V_135 ) ) {
V_133 = F_79 ( & V_132 -> V_136 ) >> 16 ;
V_134 = F_80 ( & V_132 -> V_136 ) >> 16 ;
} else {
V_133 = F_80 ( & V_132 -> V_136 ) >> 16 ;
V_134 = F_79 ( & V_132 -> V_136 ) >> 16 ;
}
if ( V_129 )
* V_129 = V_133 ;
if ( V_130 )
* V_130 = V_134 ;
}
static int F_81 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_7 . V_20 -> V_19 ;
int V_137 ;
F_77 ( V_6 , NULL , & V_137 ) ;
if ( F_61 ( V_2 ) -> V_100 >= 7 )
V_137 = F_82 ( V_137 , 2048 ) ;
return V_137 * V_19 -> V_27 [ 0 ] ;
}
static int F_83 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_7 . V_20 -> V_19 ;
int V_107 , V_138 ;
V_107 = F_81 ( V_6 ) ;
V_138 = F_19 ( V_19 -> V_42 , 0 ) ;
if ( V_107 <= V_2 -> V_3 . V_25 )
return 0 ;
F_75 ( V_2 ) ;
return F_69 ( V_2 , V_107 , V_138 ) ;
}
static bool F_84 ( struct V_1 * V_2 ,
unsigned int V_139 )
{
F_45 ( V_139 < 512 ) ;
F_45 ( ( V_139 & ( 64 - 1 ) ) != 0 ) ;
if ( F_10 ( V_2 ) || F_85 ( V_2 ) )
return V_139 == 4096 || V_139 == 8192 ;
if ( F_12 ( V_2 ) && ! F_86 ( V_2 ) && V_139 < 2048 )
return false ;
if ( V_139 > 16384 )
return false ;
return true ;
}
static bool F_87 ( struct V_18 * V_19 )
{
struct V_140 * V_16 = V_19 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
switch ( V_19 -> V_42 ) {
case V_141 :
case V_142 :
return true ;
case V_143 :
case V_144 :
if ( F_10 ( V_16 ) )
return false ;
if ( F_86 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_88 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_16 -> V_17 ;
unsigned int V_145 , V_146 , V_147 , V_148 ;
if ( F_61 ( V_2 ) -> V_100 >= 8 || F_33 ( V_2 ) ) {
V_147 = 4096 ;
V_148 = 4096 ;
} else if ( F_86 ( V_2 ) || F_61 ( V_2 ) -> V_100 >= 5 ) {
V_147 = 4096 ;
V_148 = 2048 ;
} else {
V_147 = 2048 ;
V_148 = 1536 ;
}
F_77 ( V_6 , & V_145 , & V_146 ) ;
V_145 += V_6 -> V_149 ;
V_146 += V_6 -> V_9 ;
return V_145 <= V_147 && V_146 <= V_148 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_97 * V_6 = NULL ;
struct V_5 * V_5 ;
struct V_18 * V_19 ;
struct V_21 * V_22 ;
const struct V_150 * V_151 ;
F_45 ( ! F_46 ( & V_2 -> V_3 . V_75 ) ) ;
if ( F_90 ( V_2 -> V_16 ) )
V_152 . V_4 = 0 ;
if ( V_152 . V_4 < 0 ) {
F_59 ( V_2 , V_91 ) ;
goto V_153;
}
if ( ! V_152 . V_4 ) {
F_59 ( V_2 , V_90 ) ;
goto V_153;
}
V_6 = F_60 ( V_2 ) ;
if ( ! V_6 ) {
F_59 ( V_2 , V_83 ) ;
goto V_153;
}
if ( ! F_65 ( V_2 ) ) {
F_59 ( V_2 , V_89 ) ;
goto V_153;
}
V_5 = F_91 ( V_6 ) ;
V_19 = V_6 -> V_20 -> V_19 ;
V_22 = F_9 ( V_19 ) ;
V_151 = & V_5 -> V_154 -> V_7 . V_151 ;
if ( ( V_151 -> V_155 & V_156 ) ||
( V_151 -> V_155 & V_157 ) ) {
F_59 ( V_2 , V_85 ) ;
goto V_153;
}
if ( ! F_88 ( V_5 ) ) {
F_59 ( V_2 , V_86 ) ;
goto V_153;
}
if ( ( F_61 ( V_2 ) -> V_100 < 4 || F_92 ( V_2 ) ) &&
V_5 -> V_32 != V_158 ) {
F_59 ( V_2 , V_87 ) ;
goto V_153;
}
if ( V_22 -> V_159 != V_160 ||
V_22 -> V_39 == V_161 ) {
F_59 ( V_2 , V_88 ) ;
goto V_153;
}
if ( F_61 ( V_2 ) -> V_100 <= 4 && ! F_86 ( V_2 ) &&
V_6 -> V_20 -> V_102 -> V_135 != F_93 ( V_162 ) ) {
F_59 ( V_2 , V_92 ) ;
goto V_153;
}
if ( ! F_84 ( V_2 , V_19 -> V_27 [ 0 ] ) ) {
F_59 ( V_2 , V_94 ) ;
goto V_153;
}
if ( ! F_87 ( V_19 ) ) {
F_59 ( V_2 , V_96 ) ;
goto V_153;
}
if ( F_94 () ) {
F_59 ( V_2 , V_93 ) ;
goto V_153;
}
if ( ( F_33 ( V_2 ) || F_34 ( V_2 ) ) &&
F_95 ( V_5 -> V_154 ) >=
V_2 -> V_163 * 95 / 100 ) {
F_59 ( V_2 , V_95 ) ;
goto V_153;
}
if ( F_83 ( V_5 ) ) {
F_59 ( V_2 , V_84 ) ;
goto V_153;
}
if ( V_2 -> V_3 . V_6 == V_5 &&
V_2 -> V_3 . V_68 == V_19 -> V_7 . V_69 &&
V_2 -> V_3 . V_8 == V_6 -> V_8 )
return;
if ( F_36 ( V_2 ) ) {
F_7 ( L_28 ) ;
F_54 ( V_2 ) ;
}
F_48 ( V_5 ) ;
V_2 -> V_3 . V_79 = V_81 ;
return;
V_153:
if ( F_36 ( V_2 ) ) {
F_7 ( L_29 ) ;
F_54 ( V_2 ) ;
}
F_75 ( V_2 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return;
F_41 ( & V_2 -> V_3 . V_75 ) ;
F_89 ( V_2 ) ;
F_42 ( & V_2 -> V_3 . V_75 ) ;
}
void F_97 ( struct V_1 * V_2 ,
unsigned int V_164 ,
enum V_165 V_166 )
{
unsigned int V_167 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_166 == V_168 )
return;
F_41 ( & V_2 -> V_3 . V_75 ) ;
if ( V_2 -> V_3 . V_11 )
V_167 = F_98 ( V_2 -> V_3 . V_6 -> V_66 ) ;
else if ( V_2 -> V_3 . V_76 )
V_167 = F_98 (
V_2 -> V_3 . V_76 -> V_6 -> V_66 ) ;
else
V_167 = V_2 -> V_3 . V_169 ;
V_2 -> V_3 . V_170 |= ( V_167 & V_164 ) ;
if ( V_2 -> V_3 . V_170 )
F_54 ( V_2 ) ;
F_42 ( & V_2 -> V_3 . V_75 ) ;
}
void F_99 ( struct V_1 * V_2 ,
unsigned int V_164 , enum V_165 V_166 )
{
if ( ! F_1 ( V_2 ) )
return;
if ( V_166 == V_168 )
return;
F_41 ( & V_2 -> V_3 . V_75 ) ;
V_2 -> V_3 . V_170 &= ~ V_164 ;
if ( ! V_2 -> V_3 . V_170 ) {
F_54 ( V_2 ) ;
F_89 ( V_2 ) ;
}
F_42 ( & V_2 -> V_3 . V_75 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
enum V_66 V_66 ;
F_101 ( & V_2 -> V_3 . V_75 ) ;
if ( ! F_102 ( V_2 ) ) {
V_2 -> V_3 . V_11 = false ;
V_2 -> V_3 . V_79 = V_82 ;
return;
}
F_62 (dev_priv, pipe) {
V_2 -> V_3 . V_169 |=
F_98 ( V_66 ) ;
if ( F_33 ( V_2 ) || F_61 ( V_2 ) -> V_100 >= 8 )
break;
}
if ( F_61 ( V_2 ) -> V_100 >= 7 ) {
V_2 -> V_3 . V_171 = F_29 ;
V_2 -> V_3 . V_4 = F_30 ;
V_2 -> V_3 . V_78 = F_28 ;
} else if ( F_61 ( V_2 ) -> V_100 >= 5 ) {
V_2 -> V_3 . V_171 = F_29 ;
V_2 -> V_3 . V_4 = F_24 ;
V_2 -> V_3 . V_78 = F_28 ;
} else if ( F_71 ( V_2 ) ) {
V_2 -> V_3 . V_171 = F_21 ;
V_2 -> V_3 . V_4 = F_17 ;
V_2 -> V_3 . V_78 = F_20 ;
} else {
V_2 -> V_3 . V_171 = F_16 ;
V_2 -> V_3 . V_4 = F_8 ;
V_2 -> V_3 . V_78 = F_3 ;
F_5 ( V_12 , 500 << V_35 ) ;
}
V_2 -> V_3 . V_11 = V_2 -> V_3 . V_171 ( V_2 ) ;
}
