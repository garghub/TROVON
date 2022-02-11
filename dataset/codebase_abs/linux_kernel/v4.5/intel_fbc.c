static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 != NULL ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) || F_4 ( V_2 ) -> V_5 >= 8 ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) -> V_5 < 4 ;
}
static unsigned int F_6 ( struct V_6 * V_7 )
{
return V_7 -> V_8 . V_9 - V_7 -> V_10 ;
}
static void F_7 ( struct V_6 * V_7 ,
int * V_11 , int * V_12 )
{
struct V_13 * V_14 =
F_8 ( V_7 -> V_8 . V_15 -> V_16 ) ;
int V_17 , V_18 ;
if ( F_9 ( V_14 -> V_8 . V_19 ) ) {
V_17 = F_10 ( & V_14 -> V_20 ) >> 16 ;
V_18 = F_11 ( & V_14 -> V_20 ) >> 16 ;
} else {
V_17 = F_11 ( & V_14 -> V_20 ) >> 16 ;
V_18 = F_10 ( & V_14 -> V_20 ) >> 16 ;
}
if ( V_11 )
* V_11 = V_17 ;
if ( V_12 )
* V_12 = V_18 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
int V_25 ;
F_7 ( V_7 , NULL , & V_25 ) ;
if ( F_4 ( V_2 ) -> V_5 >= 7 )
V_25 = F_13 ( V_25 , 2048 ) ;
return V_25 * V_22 -> V_26 [ 0 ] ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_27 ;
V_2 -> V_3 . V_28 = false ;
V_27 = F_15 ( V_29 ) ;
if ( ( V_27 & V_30 ) == 0 )
return;
V_27 &= ~ V_30 ;
F_16 ( V_29 , V_27 ) ;
if ( F_17 ( ( F_15 ( V_31 ) & V_32 ) == 0 , 10 ) ) {
F_18 ( L_1 ) ;
return;
}
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_21 * V_22 = V_7 -> V_8 . V_15 -> V_22 ;
struct V_33 * V_34 = F_20 ( V_22 ) ;
int V_35 ;
int V_36 ;
T_1 V_27 ;
V_2 -> V_3 . V_28 = true ;
V_35 = F_12 ( V_7 , V_22 ) / V_37 ;
if ( V_22 -> V_26 [ 0 ] < V_35 )
V_35 = V_22 -> V_26 [ 0 ] ;
if ( F_21 ( V_2 ) )
V_35 = ( V_35 / 32 ) - 1 ;
else
V_35 = ( V_35 / 64 ) - 1 ;
for ( V_36 = 0 ; V_36 < ( V_37 / 32 ) + 1 ; V_36 ++ )
F_16 ( F_22 ( V_36 ) , 0 ) ;
if ( F_23 ( V_2 ) ) {
T_1 V_38 ;
V_38 = V_39 | V_40 | V_41 ;
V_38 |= F_24 ( V_7 -> V_42 ) ;
F_16 ( V_43 , V_38 ) ;
F_16 ( V_44 , F_6 ( V_7 ) ) ;
}
V_27 = F_15 ( V_29 ) ;
V_27 &= 0x3fff << V_45 ;
V_27 |= V_30 | V_46 ;
if ( F_25 ( V_2 ) )
V_27 |= V_47 ;
V_27 |= ( V_35 & 0xff ) << V_48 ;
V_27 |= V_34 -> V_49 ;
F_16 ( V_29 , V_27 ) ;
}
static bool F_26 ( struct V_1 * V_2 )
{
return F_15 ( V_29 ) & V_30 ;
}
static void F_27 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_21 * V_22 = V_7 -> V_8 . V_15 -> V_22 ;
struct V_33 * V_34 = F_20 ( V_22 ) ;
T_1 V_50 ;
V_2 -> V_3 . V_28 = true ;
V_50 = F_28 ( V_7 -> V_42 ) | V_51 ;
if ( F_29 ( V_22 -> V_52 , 0 ) == 2 )
V_50 |= V_53 ;
else
V_50 |= V_54 ;
V_50 |= V_55 | V_34 -> V_49 ;
F_16 ( V_56 , F_6 ( V_7 ) ) ;
F_16 ( V_57 , V_50 | V_58 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_50 ;
V_2 -> V_3 . V_28 = false ;
V_50 = F_15 ( V_57 ) ;
if ( V_50 & V_58 ) {
V_50 &= ~ V_58 ;
F_16 ( V_57 , V_50 ) ;
}
}
static bool F_31 ( struct V_1 * V_2 )
{
return F_15 ( V_57 ) & V_58 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_16 ( V_59 , V_60 ) ;
F_33 ( V_59 ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_21 * V_22 = V_7 -> V_8 . V_15 -> V_22 ;
struct V_33 * V_34 = F_20 ( V_22 ) ;
T_1 V_50 ;
int V_61 = V_2 -> V_3 . V_61 ;
unsigned int V_62 ;
V_2 -> V_3 . V_28 = true ;
V_50 = F_28 ( V_7 -> V_42 ) ;
if ( F_29 ( V_22 -> V_52 , 0 ) == 2 )
V_61 ++ ;
switch ( V_61 ) {
case 4 :
case 3 :
V_50 |= V_63 ;
break;
case 2 :
V_50 |= V_53 ;
break;
case 1 :
V_50 |= V_54 ;
break;
}
V_50 |= V_55 ;
if ( F_35 ( V_2 ) )
V_50 |= V_34 -> V_49 ;
V_62 = F_6 ( V_7 ) ;
F_16 ( V_64 , V_62 ) ;
F_16 ( V_65 , F_36 ( V_34 ) | V_66 ) ;
F_16 ( V_67 , V_50 | V_58 ) ;
if ( F_37 ( V_2 ) ) {
F_16 ( V_68 ,
V_69 | V_34 -> V_49 ) ;
F_16 ( V_70 , V_62 ) ;
}
F_32 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_50 ;
V_2 -> V_3 . V_28 = false ;
V_50 = F_15 ( V_67 ) ;
if ( V_50 & V_58 ) {
V_50 &= ~ V_58 ;
F_16 ( V_67 , V_50 ) ;
}
}
static bool F_39 ( struct V_1 * V_2 )
{
return F_15 ( V_67 ) & V_58 ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_21 * V_22 = V_7 -> V_8 . V_15 -> V_22 ;
struct V_33 * V_34 = F_20 ( V_22 ) ;
T_1 V_50 ;
int V_61 = V_2 -> V_3 . V_61 ;
V_2 -> V_3 . V_28 = true ;
V_50 = 0 ;
if ( F_41 ( V_2 ) )
V_50 |= F_42 ( V_7 -> V_42 ) ;
if ( F_29 ( V_22 -> V_52 , 0 ) == 2 )
V_61 ++ ;
switch ( V_61 ) {
case 4 :
case 3 :
V_50 |= V_63 ;
break;
case 2 :
V_50 |= V_53 ;
break;
case 1 :
V_50 |= V_54 ;
break;
}
V_50 |= V_71 ;
if ( V_2 -> V_3 . V_72 )
V_50 |= V_73 ;
if ( F_41 ( V_2 ) ) {
F_16 ( V_74 ,
F_15 ( V_74 ) |
V_75 ) ;
} else if ( F_3 ( V_2 ) || F_43 ( V_2 ) ) {
F_16 ( F_44 ( V_7 -> V_76 ) ,
F_15 ( F_44 ( V_7 -> V_76 ) ) |
V_77 ) ;
}
F_16 ( V_67 , V_50 | V_58 ) ;
F_16 ( V_68 ,
V_69 | V_34 -> V_49 ) ;
F_16 ( V_70 , F_6 ( V_7 ) ) ;
F_32 ( V_2 ) ;
}
bool F_45 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_28 ;
}
static void F_46 ( const struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_3 . V_7 ;
V_2 -> V_3 . V_4 ( V_7 ) ;
V_2 -> V_3 . V_78 = V_22 -> V_8 . V_79 ;
V_2 -> V_3 . V_9 = V_7 -> V_8 . V_9 ;
}
static void F_47 ( struct V_80 * V_81 )
{
struct V_1 * V_2 =
F_48 ( V_81 , struct V_1 , V_3 . V_82 . V_82 ) ;
struct V_83 * V_82 = & V_2 -> V_3 . V_82 ;
struct V_6 * V_7 = V_2 -> V_3 . V_7 ;
int V_84 = 50 ;
V_85:
F_49 ( V_82 -> V_86 , V_84 ) ;
F_50 ( & V_2 -> V_3 . V_87 ) ;
if ( ! V_82 -> V_88 )
goto V_89;
if ( F_51 ( V_82 -> V_86 + F_52 ( V_84 ) ,
V_90 ) ) {
F_53 ( & V_2 -> V_3 . V_87 ) ;
goto V_85;
}
if ( V_7 -> V_8 . V_15 -> V_22 == V_82 -> V_22 )
F_46 ( V_82 -> V_22 ) ;
V_82 -> V_88 = false ;
V_89:
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( ! F_56 ( & V_2 -> V_3 . V_87 ) ) ;
V_2 -> V_3 . V_82 . V_88 = false ;
}
static void F_57 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_83 * V_82 = & V_2 -> V_3 . V_82 ;
F_55 ( ! F_56 ( & V_2 -> V_3 . V_87 ) ) ;
V_82 -> V_22 = V_7 -> V_8 . V_15 -> V_22 ;
V_82 -> V_88 = true ;
V_82 -> V_86 = V_90 ;
F_58 ( & V_82 -> V_82 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_55 ( ! F_56 ( & V_2 -> V_3 . V_87 ) ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_3 . V_28 )
V_2 -> V_3 . V_91 ( V_2 ) ;
}
void F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
if ( ! F_1 ( V_2 ) )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
if ( V_2 -> V_3 . V_7 == V_7 )
F_59 ( V_2 ) ;
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
const char * V_92 )
{
if ( V_2 -> V_3 . V_93 == V_92 )
return;
V_2 -> V_3 . V_93 = V_92 ;
F_18 ( L_2 , V_92 ) ;
}
static bool F_62 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
if ( F_2 ( V_2 ) && V_7 -> V_76 != V_94 )
return false ;
if ( F_5 ( V_2 ) && V_7 -> V_42 != V_95 )
return false ;
return true ;
}
static bool F_63 ( struct V_6 * V_7 )
{
if ( ! F_64 ( & V_7 -> V_8 ) )
return false ;
if ( ! F_8 ( V_7 -> V_8 . V_15 -> V_16 ) -> V_96 )
return false ;
return true ;
}
static bool F_65 ( struct V_1 * V_2 )
{
enum V_76 V_76 ;
int V_97 = 0 ;
struct V_98 * V_7 ;
if ( F_4 ( V_2 ) -> V_5 > 4 )
return true ;
F_66 (dev_priv, pipe) {
V_7 = V_2 -> V_99 [ V_76 ] ;
if ( F_64 ( V_7 ) &&
F_8 ( V_7 -> V_15 -> V_16 ) -> V_96 )
V_97 ++ ;
}
return ( V_97 < 2 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
int V_102 ,
int V_103 )
{
int V_104 = 1 ;
int V_105 ;
T_2 V_106 ;
if ( F_43 ( V_2 ) ||
F_68 ( V_2 ) || F_69 ( V_2 ) )
V_106 = V_2 -> V_107 . V_108 - 8 * 1024 * 1024 ;
else
V_106 = V_2 -> V_107 . V_109 ;
V_105 = F_70 ( V_2 , V_101 , V_102 <<= 1 ,
4096 , 0 , V_106 ) ;
if ( V_105 == 0 )
return V_104 ;
V_110:
if ( V_104 > 4 ||
( V_103 == 2 && V_104 == 2 ) )
return 0 ;
V_105 = F_70 ( V_2 , V_101 , V_102 >>= 1 ,
4096 , 0 , V_106 ) ;
if ( V_105 && F_4 ( V_2 ) -> V_5 <= 4 ) {
return 0 ;
} else if ( V_105 ) {
V_104 <<= 1 ;
goto V_110;
} else {
return V_104 ;
}
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_21 * V_22 = V_7 -> V_8 . V_15 -> V_16 -> V_22 ;
struct V_100 * V_111 ( V_112 ) ;
int V_102 , V_103 , V_105 ;
F_55 ( F_72 ( & V_2 -> V_3 . V_113 ) ) ;
V_102 = F_12 ( V_7 , V_22 ) ;
V_103 = F_29 ( V_22 -> V_52 , 0 ) ;
V_105 = F_67 ( V_2 , & V_2 -> V_3 . V_113 ,
V_102 , V_103 ) ;
if ( ! V_105 )
goto V_114;
else if ( V_105 > 1 ) {
F_73 ( L_3 ) ;
}
V_2 -> V_3 . V_61 = V_105 ;
if ( F_4 ( V_2 ) -> V_5 >= 5 )
F_16 ( V_115 , V_2 -> V_3 . V_113 . V_116 ) ;
else if ( F_74 ( V_2 ) ) {
F_16 ( V_117 , V_2 -> V_3 . V_113 . V_116 ) ;
} else {
V_112 = F_75 ( sizeof( * V_112 ) , V_118 ) ;
if ( ! V_112 )
goto V_119;
V_105 = F_76 ( V_2 , V_112 ,
4096 , 4096 ) ;
if ( V_105 )
goto V_119;
V_2 -> V_3 . V_112 = V_112 ;
F_16 ( V_120 ,
V_2 -> V_121 . V_122 + V_2 -> V_3 . V_113 . V_116 ) ;
F_16 ( V_123 ,
V_2 -> V_121 . V_122 + V_112 -> V_116 ) ;
}
F_18 ( L_4 ,
V_2 -> V_3 . V_113 . V_102 ,
V_2 -> V_3 . V_61 ) ;
return 0 ;
V_119:
F_77 ( V_112 ) ;
F_78 ( V_2 , & V_2 -> V_3 . V_113 ) ;
V_114:
F_79 ( L_5 , V_102 ) ;
return - V_124 ;
}
static void F_80 ( struct V_1 * V_2 )
{
if ( F_72 ( & V_2 -> V_3 . V_113 ) )
F_78 ( V_2 ,
& V_2 -> V_3 . V_113 ) ;
if ( V_2 -> V_3 . V_112 ) {
F_78 ( V_2 ,
V_2 -> V_3 . V_112 ) ;
F_77 ( V_2 -> V_3 . V_112 ) ;
}
}
void F_81 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
F_80 ( V_2 ) ;
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
static bool F_82 ( struct V_1 * V_2 ,
unsigned int V_125 )
{
F_55 ( V_125 < 512 ) ;
F_55 ( ( V_125 & ( 64 - 1 ) ) != 0 ) ;
if ( F_21 ( V_2 ) || F_83 ( V_2 ) )
return V_125 == 4096 || V_125 == 8192 ;
if ( F_23 ( V_2 ) && ! F_84 ( V_2 ) && V_125 < 2048 )
return false ;
if ( V_125 > 16384 )
return false ;
return true ;
}
static bool F_85 ( struct V_21 * V_22 )
{
struct V_126 * V_23 = V_22 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_24 ;
switch ( V_22 -> V_52 ) {
case V_127 :
case V_128 :
return true ;
case V_129 :
case V_130 :
if ( F_21 ( V_23 ) )
return false ;
if ( F_84 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_86 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
unsigned int V_131 , V_132 , V_133 , V_134 ;
if ( F_4 ( V_2 ) -> V_5 >= 8 || F_3 ( V_2 ) ) {
V_133 = 4096 ;
V_134 = 4096 ;
} else if ( F_84 ( V_2 ) || F_4 ( V_2 ) -> V_5 >= 5 ) {
V_133 = 4096 ;
V_134 = 2048 ;
} else {
V_133 = 2048 ;
V_134 = 1536 ;
}
F_7 ( V_7 , & V_131 , & V_132 ) ;
V_131 += V_7 -> V_135 ;
V_132 += V_7 -> V_10 ;
return V_131 <= V_133 && V_132 <= V_134 ;
}
static void F_87 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
struct V_21 * V_22 ;
struct V_33 * V_34 ;
const struct V_136 * V_137 ;
F_55 ( ! F_56 ( & V_2 -> V_3 . V_87 ) ) ;
if ( ! F_65 ( V_2 ) ) {
F_61 ( V_2 , L_6 ) ;
goto V_138;
}
if ( ! V_2 -> V_3 . V_139 || V_2 -> V_3 . V_7 != V_7 )
return;
if ( ! F_63 ( V_7 ) ) {
F_61 ( V_2 , L_7 ) ;
goto V_138;
}
V_22 = V_7 -> V_8 . V_15 -> V_22 ;
V_34 = F_20 ( V_22 ) ;
V_137 = & V_7 -> V_140 -> V_8 . V_137 ;
if ( ( V_137 -> V_141 & V_142 ) ||
( V_137 -> V_141 & V_143 ) ) {
F_61 ( V_2 , L_8 ) ;
goto V_138;
}
if ( ! F_86 ( V_7 ) ) {
F_61 ( V_2 , L_9 ) ;
goto V_138;
}
if ( V_34 -> V_144 != V_145 ||
V_34 -> V_49 == V_146 ) {
F_61 ( V_2 , L_10 ) ;
goto V_138;
}
if ( F_4 ( V_2 ) -> V_5 <= 4 && ! F_84 ( V_2 ) &&
V_7 -> V_8 . V_15 -> V_16 -> V_19 != F_88 ( V_147 ) ) {
F_61 ( V_2 , L_11 ) ;
goto V_138;
}
if ( ! F_82 ( V_2 , V_22 -> V_26 [ 0 ] ) ) {
F_61 ( V_2 , L_12 ) ;
goto V_138;
}
if ( ! F_85 ( V_22 ) ) {
F_61 ( V_2 , L_13 ) ;
goto V_138;
}
if ( ( F_3 ( V_2 ) || F_43 ( V_2 ) ) &&
F_89 ( V_7 -> V_140 ) >=
V_2 -> V_148 * 95 / 100 ) {
F_61 ( V_2 , L_14 ) ;
goto V_138;
}
if ( F_12 ( V_7 , V_22 ) >
V_2 -> V_3 . V_113 . V_102 * V_2 -> V_3 . V_61 ) {
F_61 ( V_2 , L_15 ) ;
goto V_138;
}
if ( V_2 -> V_3 . V_7 == V_7 &&
V_2 -> V_3 . V_78 == V_22 -> V_8 . V_79 &&
V_2 -> V_3 . V_9 == V_7 -> V_8 . V_9 &&
V_2 -> V_3 . V_28 )
return;
if ( F_45 ( V_2 ) ) {
F_18 ( L_16 ) ;
F_59 ( V_2 ) ;
}
F_57 ( V_7 ) ;
V_2 -> V_3 . V_93 = L_17 ;
return;
V_138:
if ( F_45 ( V_2 ) ) {
F_18 ( L_18 ) ;
F_59 ( V_2 ) ;
}
}
void F_90 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
if ( ! F_1 ( V_2 ) )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
F_87 ( V_7 ) ;
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
void F_91 ( struct V_1 * V_2 ,
unsigned int V_149 ,
enum V_150 V_151 )
{
unsigned int V_152 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_151 == V_153 )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
if ( V_2 -> V_3 . V_139 )
V_152 = F_92 ( V_2 -> V_3 . V_7 -> V_76 ) ;
else
V_152 = V_2 -> V_3 . V_154 ;
V_2 -> V_3 . V_155 |= ( V_152 & V_149 ) ;
if ( V_2 -> V_3 . V_155 )
F_59 ( V_2 ) ;
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
void F_93 ( struct V_1 * V_2 ,
unsigned int V_149 , enum V_150 V_151 )
{
if ( ! F_1 ( V_2 ) )
return;
if ( V_151 == V_153 )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
V_2 -> V_3 . V_155 &= ~ V_149 ;
if ( ! V_2 -> V_3 . V_155 && V_2 -> V_3 . V_139 ) {
if ( V_151 != V_156 && V_2 -> V_3 . V_28 ) {
F_32 ( V_2 ) ;
} else {
F_59 ( V_2 ) ;
F_87 ( V_2 -> V_3 . V_7 ) ;
}
}
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
void F_94 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
if ( ! F_1 ( V_2 ) )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
if ( V_2 -> V_3 . V_139 ) {
F_55 ( V_2 -> V_3 . V_7 == V_7 ) ;
goto V_89;
}
F_55 ( V_2 -> V_3 . V_28 ) ;
F_55 ( V_2 -> V_3 . V_7 != NULL ) ;
if ( F_95 ( V_2 -> V_23 ) ) {
F_61 ( V_2 , L_19 ) ;
goto V_89;
}
if ( V_157 . V_158 < 0 ) {
F_61 ( V_2 , L_20 ) ;
goto V_89;
}
if ( ! V_157 . V_158 ) {
F_61 ( V_2 , L_21 ) ;
goto V_89;
}
if ( ! F_62 ( V_7 ) ) {
F_61 ( V_2 , L_22 ) ;
goto V_89;
}
if ( F_71 ( V_7 ) ) {
F_61 ( V_2 , L_23 ) ;
goto V_89;
}
F_18 ( L_24 , F_96 ( V_7 -> V_76 ) ) ;
V_2 -> V_3 . V_93 = L_25 ;
V_2 -> V_3 . V_139 = true ;
V_2 -> V_3 . V_7 = V_7 ;
V_89:
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_3 . V_7 ;
F_55 ( ! F_56 ( & V_2 -> V_3 . V_87 ) ) ;
F_55 ( ! V_2 -> V_3 . V_139 ) ;
F_55 ( V_2 -> V_3 . V_28 ) ;
F_98 ( V_2 , V_7 -> V_76 ) ;
F_18 ( L_26 , F_96 ( V_7 -> V_76 ) ) ;
F_80 ( V_2 ) ;
V_2 -> V_3 . V_139 = false ;
V_2 -> V_3 . V_7 = NULL ;
}
void F_99 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_23 -> V_24 ;
if ( ! F_1 ( V_2 ) )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
if ( V_2 -> V_3 . V_7 == V_7 ) {
F_55 ( ! V_2 -> V_3 . V_139 ) ;
F_55 ( V_2 -> V_3 . V_28 ) ;
F_97 ( V_2 ) ;
}
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return;
F_50 ( & V_2 -> V_3 . V_87 ) ;
if ( V_2 -> V_3 . V_139 )
F_97 ( V_2 ) ;
F_53 ( & V_2 -> V_3 . V_87 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
enum V_76 V_76 ;
F_102 ( & V_2 -> V_3 . V_82 . V_82 , F_47 ) ;
F_103 ( & V_2 -> V_3 . V_87 ) ;
V_2 -> V_3 . V_139 = false ;
V_2 -> V_3 . V_28 = false ;
V_2 -> V_3 . V_82 . V_88 = false ;
if ( ! F_104 ( V_2 ) ) {
V_2 -> V_3 . V_93 = L_27 ;
return;
}
F_66 (dev_priv, pipe) {
V_2 -> V_3 . V_154 |=
F_92 ( V_76 ) ;
if ( F_2 ( V_2 ) )
break;
}
if ( F_4 ( V_2 ) -> V_5 >= 7 ) {
V_2 -> V_3 . V_159 = F_39 ;
V_2 -> V_3 . V_4 = F_40 ;
V_2 -> V_3 . V_91 = F_38 ;
} else if ( F_4 ( V_2 ) -> V_5 >= 5 ) {
V_2 -> V_3 . V_159 = F_39 ;
V_2 -> V_3 . V_4 = F_34 ;
V_2 -> V_3 . V_91 = F_38 ;
} else if ( F_74 ( V_2 ) ) {
V_2 -> V_3 . V_159 = F_31 ;
V_2 -> V_3 . V_4 = F_27 ;
V_2 -> V_3 . V_91 = F_30 ;
} else {
V_2 -> V_3 . V_159 = F_26 ;
V_2 -> V_3 . V_4 = F_19 ;
V_2 -> V_3 . V_91 = F_14 ;
F_16 ( V_29 , 500 << V_45 ) ;
}
if ( V_2 -> V_3 . V_159 ( V_2 ) )
V_2 -> V_3 . V_91 ( V_2 ) ;
}
