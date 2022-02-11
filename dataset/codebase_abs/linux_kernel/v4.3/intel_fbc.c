static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 . V_5 = false ;
V_3 = F_2 ( V_6 ) ;
if ( ( V_3 & V_7 ) == 0 )
return;
V_3 &= ~ V_7 ;
F_3 ( V_6 , V_3 ) ;
if ( F_4 ( ( F_2 ( V_8 ) & V_9 ) == 0 , 10 ) ) {
F_5 ( L_1 ) ;
return;
}
F_5 ( L_2 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 . V_13 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_12 . V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
int V_20 ;
int V_21 ;
T_1 V_3 ;
V_2 -> V_4 . V_5 = true ;
V_20 = V_2 -> V_4 . V_22 / V_23 ;
if ( V_16 -> V_24 [ 0 ] < V_20 )
V_20 = V_16 -> V_24 [ 0 ] ;
if ( F_8 ( V_2 ) )
V_20 = ( V_20 / 32 ) - 1 ;
else
V_20 = ( V_20 / 64 ) - 1 ;
for ( V_21 = 0 ; V_21 < ( V_23 / 32 ) + 1 ; V_21 ++ )
F_3 ( V_25 + ( V_21 * 4 ) , 0 ) ;
if ( F_9 ( V_2 ) ) {
T_1 V_26 ;
V_26 = V_27 | V_28 | V_29 ;
V_26 |= F_10 ( V_11 -> V_30 ) ;
F_3 ( V_31 , V_26 ) ;
F_3 ( V_32 , V_11 -> V_12 . V_33 ) ;
}
V_3 = F_2 ( V_6 ) ;
V_3 &= 0x3fff << V_34 ;
V_3 |= V_7 | V_35 ;
if ( F_11 ( V_2 ) )
V_3 |= V_36 ;
V_3 |= ( V_20 & 0xff ) << V_37 ;
V_3 |= V_19 -> V_38 ;
F_3 ( V_6 , V_3 ) ;
F_5 ( L_3 ,
V_20 , V_11 -> V_12 . V_33 , F_12 ( V_11 -> V_30 ) ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
return F_2 ( V_6 ) & V_7 ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 . V_13 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_12 . V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
T_1 V_39 ;
V_2 -> V_4 . V_5 = true ;
V_39 = F_15 ( V_11 -> V_30 ) | V_40 ;
if ( F_16 ( V_16 -> V_41 , 0 ) == 2 )
V_39 |= V_42 ;
else
V_39 |= V_43 ;
V_39 |= V_44 | V_19 -> V_38 ;
F_3 ( V_45 , V_11 -> V_12 . V_33 ) ;
F_3 ( V_46 , V_39 | V_47 ) ;
F_5 ( L_4 , F_12 ( V_11 -> V_30 ) ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_2 -> V_4 . V_5 = false ;
V_39 = F_2 ( V_46 ) ;
if ( V_39 & V_47 ) {
V_39 &= ~ V_47 ;
F_3 ( V_46 , V_39 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_18 ( struct V_1 * V_2 )
{
return F_2 ( V_46 ) & V_47 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_3 ( V_48 , V_49 ) ;
F_20 ( V_48 ) ;
}
static void F_21 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 . V_13 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_12 . V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
T_1 V_39 ;
int V_50 = V_2 -> V_4 . V_50 ;
V_2 -> V_4 . V_5 = true ;
V_39 = F_15 ( V_11 -> V_30 ) ;
if ( F_16 ( V_16 -> V_41 , 0 ) == 2 )
V_50 ++ ;
switch ( V_50 ) {
case 4 :
case 3 :
V_39 |= V_51 ;
break;
case 2 :
V_39 |= V_42 ;
break;
case 1 :
V_39 |= V_43 ;
break;
}
V_39 |= V_44 ;
if ( F_22 ( V_2 ) )
V_39 |= V_19 -> V_38 ;
F_3 ( V_52 , V_11 -> V_12 . V_33 ) ;
F_3 ( V_53 , F_23 ( V_19 ) | V_54 ) ;
F_3 ( V_55 , V_39 | V_47 ) ;
if ( F_24 ( V_2 ) ) {
F_3 ( V_56 ,
V_57 | V_19 -> V_38 ) ;
F_3 ( V_58 , V_11 -> V_12 . V_33 ) ;
}
F_19 ( V_2 ) ;
F_5 ( L_4 , F_12 ( V_11 -> V_30 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_2 -> V_4 . V_5 = false ;
V_39 = F_2 ( V_55 ) ;
if ( V_39 & V_47 ) {
V_39 &= ~ V_47 ;
F_3 ( V_55 , V_39 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_26 ( struct V_1 * V_2 )
{
return F_2 ( V_55 ) & V_47 ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 . V_13 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_12 . V_17 -> V_16 ;
struct V_18 * V_19 = F_7 ( V_16 ) ;
T_1 V_39 ;
int V_50 = V_2 -> V_4 . V_50 ;
V_2 -> V_4 . V_5 = true ;
V_39 = 0 ;
if ( F_28 ( V_2 ) )
V_39 |= F_29 ( V_11 -> V_30 ) ;
if ( F_16 ( V_16 -> V_41 , 0 ) == 2 )
V_50 ++ ;
switch ( V_50 ) {
case 4 :
case 3 :
V_39 |= V_51 ;
break;
case 2 :
V_39 |= V_42 ;
break;
case 1 :
V_39 |= V_43 ;
break;
}
V_39 |= V_59 ;
if ( V_2 -> V_4 . V_60 )
V_39 |= V_61 ;
F_3 ( V_55 , V_39 | V_47 ) ;
if ( F_28 ( V_2 ) ) {
F_3 ( V_62 ,
F_2 ( V_62 ) |
V_63 ) ;
} else {
F_3 ( F_30 ( V_11 -> V_64 ) ,
F_2 ( F_30 ( V_11 -> V_64 ) ) |
V_65 ) ;
}
F_3 ( V_56 ,
V_57 | V_19 -> V_38 ) ;
F_3 ( V_58 , V_11 -> V_12 . V_33 ) ;
F_19 ( V_2 ) ;
F_5 ( L_4 , F_12 ( V_11 -> V_30 ) ) ;
}
bool F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_5 ;
}
static void F_32 ( struct V_66 * V_67 )
{
struct V_68 * V_69 =
F_33 ( F_34 ( V_67 ) ,
struct V_68 , V_69 ) ;
struct V_1 * V_2 = V_69 -> V_11 -> V_12 . V_13 -> V_14 ;
struct V_15 * V_70 = V_69 -> V_11 -> V_12 . V_17 -> V_16 ;
F_35 ( & V_2 -> V_4 . V_71 ) ;
if ( V_69 == V_2 -> V_4 . V_72 ) {
if ( V_70 == V_69 -> V_16 ) {
V_2 -> V_4 . V_73 ( V_69 -> V_11 ) ;
V_2 -> V_4 . V_11 = V_69 -> V_11 ;
V_2 -> V_4 . V_74 = V_70 -> V_12 . V_75 ;
V_2 -> V_4 . V_33 = V_69 -> V_11 -> V_12 . V_33 ;
}
V_2 -> V_4 . V_72 = NULL ;
}
F_36 ( & V_2 -> V_4 . V_71 ) ;
F_37 ( V_69 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( ! F_40 ( & V_2 -> V_4 . V_71 ) ) ;
if ( V_2 -> V_4 . V_72 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_41 ( & V_2 -> V_4 . V_72 -> V_69 ) )
F_37 ( V_2 -> V_4 . V_72 ) ;
V_2 -> V_4 . V_72 = NULL ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_68 * V_69 ;
struct V_1 * V_2 = V_11 -> V_12 . V_13 -> V_14 ;
F_39 ( ! F_40 ( & V_2 -> V_4 . V_71 ) ) ;
F_38 ( V_2 ) ;
V_69 = F_43 ( sizeof( * V_69 ) , V_76 ) ;
if ( V_69 == NULL ) {
F_44 ( L_6 ) ;
V_2 -> V_4 . V_73 ( V_11 ) ;
return;
}
V_69 -> V_11 = V_11 ;
V_69 -> V_16 = V_11 -> V_12 . V_17 -> V_16 ;
F_45 ( & V_69 -> V_69 , F_32 ) ;
V_2 -> V_4 . V_72 = V_69 ;
F_46 ( & V_69 -> V_69 , F_47 ( 50 ) ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_39 ( ! F_40 ( & V_2 -> V_4 . V_71 ) ) ;
F_38 ( V_2 ) ;
V_2 -> V_4 . V_77 ( V_2 ) ;
V_2 -> V_4 . V_11 = NULL ;
}
void F_49 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_73 )
return;
F_35 ( & V_2 -> V_4 . V_71 ) ;
F_48 ( V_2 ) ;
F_36 ( & V_2 -> V_4 . V_71 ) ;
}
void F_50 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 . V_13 -> V_14 ;
if ( ! V_2 -> V_4 . V_73 )
return;
F_35 ( & V_2 -> V_4 . V_71 ) ;
if ( V_2 -> V_4 . V_11 == V_11 )
F_48 ( V_2 ) ;
F_36 ( & V_2 -> V_4 . V_71 ) ;
}
const char * F_51 ( enum V_78 V_79 )
{
switch ( V_79 ) {
case V_80 :
return L_7 ;
case V_81 :
return L_8 ;
case V_82 :
return L_9 ;
case V_83 :
return L_10 ;
case V_84 :
return L_11 ;
case V_85 :
return L_12 ;
case V_86 :
return L_13 ;
case V_87 :
return L_14 ;
case V_88 :
return L_15 ;
case V_89 :
return L_16 ;
case V_90 :
return L_17 ;
case V_91 :
return L_18 ;
case V_92 :
return L_19 ;
default:
F_52 ( V_79 ) ;
return L_20 ;
}
}
static void F_53 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
if ( V_2 -> V_4 . V_78 == V_79 )
return;
V_2 -> V_4 . V_78 = V_79 ;
F_5 ( L_21 , F_51 ( V_79 ) ) ;
}
static struct V_93 * F_54 ( struct V_1 * V_2 )
{
struct V_93 * V_11 = NULL , * V_94 ;
enum V_64 V_64 ;
bool V_95 = false ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) -> V_96 >= 8 )
V_95 = true ;
F_57 (dev_priv, pipe) {
V_94 = V_2 -> V_97 [ V_64 ] ;
if ( F_58 ( V_94 ) &&
F_59 ( V_94 -> V_17 -> V_98 ) -> V_99 )
V_11 = V_94 ;
if ( V_95 )
break;
}
if ( ! V_11 || V_11 -> V_17 -> V_16 == NULL )
return NULL ;
return V_11 ;
}
static bool F_60 ( struct V_1 * V_2 )
{
enum V_64 V_64 ;
int V_100 = 0 ;
struct V_93 * V_11 ;
if ( F_56 ( V_2 ) -> V_96 > 4 )
return true ;
F_57 (dev_priv, pipe) {
V_11 = V_2 -> V_97 [ V_64 ] ;
if ( F_58 ( V_11 ) &&
F_59 ( V_11 -> V_17 -> V_98 ) -> V_99 )
V_100 ++ ;
}
return ( V_100 < 2 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
int V_103 ,
int V_104 )
{
int V_105 = 1 ;
int V_106 ;
V_106 = F_62 ( V_2 , V_102 , V_103 <<= 1 , 4096 ) ;
if ( V_106 == 0 )
return V_105 ;
V_107:
if ( V_105 > 4 ||
( V_104 == 2 && V_105 == 2 ) )
return 0 ;
V_106 = F_62 ( V_2 , V_102 , V_103 >>= 1 , 4096 ) ;
if ( V_106 && F_56 ( V_2 ) -> V_96 <= 4 ) {
return 0 ;
} else if ( V_106 ) {
V_105 <<= 1 ;
goto V_107;
} else {
return V_105 ;
}
}
static int F_63 ( struct V_1 * V_2 , int V_103 ,
int V_104 )
{
struct V_101 * V_108 ( V_109 ) ;
int V_106 ;
V_106 = F_61 ( V_2 , & V_2 -> V_4 . V_110 ,
V_103 , V_104 ) ;
if ( ! V_106 )
goto V_111;
else if ( V_106 > 1 ) {
F_64 ( L_22 ) ;
}
V_2 -> V_4 . V_50 = V_106 ;
if ( F_56 ( V_2 ) -> V_96 >= 5 )
F_3 ( V_112 , V_2 -> V_4 . V_110 . V_113 ) ;
else if ( F_65 ( V_2 ) ) {
F_3 ( V_114 , V_2 -> V_4 . V_110 . V_113 ) ;
} else {
V_109 = F_43 ( sizeof( * V_109 ) , V_76 ) ;
if ( ! V_109 )
goto V_115;
V_106 = F_62 ( V_2 , V_109 ,
4096 , 4096 ) ;
if ( V_106 )
goto V_115;
V_2 -> V_4 . V_109 = V_109 ;
F_3 ( V_116 ,
V_2 -> V_117 . V_118 + V_2 -> V_4 . V_110 . V_113 ) ;
F_3 ( V_119 ,
V_2 -> V_117 . V_118 + V_109 -> V_113 ) ;
}
V_2 -> V_4 . V_22 = V_103 ;
F_5 ( L_23 ,
V_103 ) ;
return 0 ;
V_115:
F_37 ( V_109 ) ;
F_66 ( V_2 , & V_2 -> V_4 . V_110 ) ;
V_111:
F_67 ( L_24 , V_103 ) ;
return - V_120 ;
}
static void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_22 == 0 )
return;
F_66 ( V_2 , & V_2 -> V_4 . V_110 ) ;
if ( V_2 -> V_4 . V_109 ) {
F_66 ( V_2 ,
V_2 -> V_4 . V_109 ) ;
F_37 ( V_2 -> V_4 . V_109 ) ;
}
V_2 -> V_4 . V_22 = 0 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_73 )
return;
F_35 ( & V_2 -> V_4 . V_71 ) ;
F_68 ( V_2 ) ;
F_36 ( & V_2 -> V_4 . V_71 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_103 ,
int V_104 )
{
if ( V_103 <= V_2 -> V_4 . V_22 )
return 0 ;
F_68 ( V_2 ) ;
return F_63 ( V_2 , V_103 , V_104 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_93 * V_11 = NULL ;
struct V_10 * V_10 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
const struct V_121 * V_122 ;
unsigned int V_123 , V_124 ;
F_39 ( ! F_40 ( & V_2 -> V_4 . V_71 ) ) ;
if ( F_72 ( V_2 -> V_13 ) )
V_125 . V_73 = 0 ;
if ( V_125 . V_73 < 0 ) {
F_53 ( V_2 , V_90 ) ;
goto V_126;
}
if ( ! V_125 . V_73 ) {
F_53 ( V_2 , V_89 ) ;
goto V_126;
}
V_11 = F_54 ( V_2 ) ;
if ( ! V_11 ) {
F_53 ( V_2 , V_82 ) ;
goto V_126;
}
if ( ! F_60 ( V_2 ) ) {
F_53 ( V_2 , V_88 ) ;
goto V_126;
}
V_10 = F_73 ( V_11 ) ;
V_16 = V_11 -> V_17 -> V_16 ;
V_19 = F_7 ( V_16 ) ;
V_122 = & V_10 -> V_127 -> V_12 . V_122 ;
if ( ( V_122 -> V_128 & V_129 ) ||
( V_122 -> V_128 & V_130 ) ) {
F_53 ( V_2 , V_84 ) ;
goto V_126;
}
if ( F_56 ( V_2 ) -> V_96 >= 8 || F_55 ( V_2 ) ) {
V_123 = 4096 ;
V_124 = 4096 ;
} else if ( F_74 ( V_2 ) || F_56 ( V_2 ) -> V_96 >= 5 ) {
V_123 = 4096 ;
V_124 = 2048 ;
} else {
V_123 = 2048 ;
V_124 = 1536 ;
}
if ( V_10 -> V_127 -> V_131 > V_123 ||
V_10 -> V_127 -> V_132 > V_124 ) {
F_53 ( V_2 , V_85 ) ;
goto V_126;
}
if ( ( F_56 ( V_2 ) -> V_96 < 4 || F_75 ( V_2 ) ) &&
V_10 -> V_30 != V_133 ) {
F_53 ( V_2 , V_86 ) ;
goto V_126;
}
if ( V_19 -> V_134 != V_135 ||
V_19 -> V_38 == V_136 ) {
F_53 ( V_2 , V_87 ) ;
goto V_126;
}
if ( F_56 ( V_2 ) -> V_96 <= 4 && ! F_74 ( V_2 ) &&
V_11 -> V_17 -> V_98 -> V_137 != F_76 ( V_138 ) ) {
F_53 ( V_2 , V_91 ) ;
goto V_126;
}
if ( F_77 () ) {
F_53 ( V_2 , V_92 ) ;
goto V_126;
}
if ( F_70 ( V_2 , V_19 -> V_12 . V_103 ,
F_16 ( V_16 -> V_41 , 0 ) ) ) {
F_53 ( V_2 , V_83 ) ;
goto V_126;
}
if ( V_2 -> V_4 . V_11 == V_10 &&
V_2 -> V_4 . V_74 == V_16 -> V_12 . V_75 &&
V_2 -> V_4 . V_33 == V_11 -> V_33 )
return;
if ( F_31 ( V_2 ) ) {
F_5 ( L_25 ) ;
F_48 ( V_2 ) ;
}
F_42 ( V_10 ) ;
V_2 -> V_4 . V_78 = V_80 ;
return;
V_126:
if ( F_31 ( V_2 ) ) {
F_5 ( L_26 ) ;
F_48 ( V_2 ) ;
}
F_68 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_73 )
return;
F_35 ( & V_2 -> V_4 . V_71 ) ;
F_71 ( V_2 ) ;
F_36 ( & V_2 -> V_4 . V_71 ) ;
}
void F_79 ( struct V_1 * V_2 ,
unsigned int V_139 ,
enum V_140 V_141 )
{
unsigned int V_142 ;
if ( ! V_2 -> V_4 . V_73 )
return;
if ( V_141 == V_143 )
return;
F_35 ( & V_2 -> V_4 . V_71 ) ;
if ( V_2 -> V_4 . V_5 )
V_142 = F_80 ( V_2 -> V_4 . V_11 -> V_64 ) ;
else if ( V_2 -> V_4 . V_72 )
V_142 = F_80 (
V_2 -> V_4 . V_72 -> V_11 -> V_64 ) ;
else
V_142 = V_2 -> V_4 . V_144 ;
V_2 -> V_4 . V_145 |= ( V_142 & V_139 ) ;
if ( V_2 -> V_4 . V_145 )
F_48 ( V_2 ) ;
F_36 ( & V_2 -> V_4 . V_71 ) ;
}
void F_81 ( struct V_1 * V_2 ,
unsigned int V_139 , enum V_140 V_141 )
{
if ( ! V_2 -> V_4 . V_73 )
return;
if ( V_141 == V_143 )
return;
F_35 ( & V_2 -> V_4 . V_71 ) ;
V_2 -> V_4 . V_145 &= ~ V_139 ;
if ( ! V_2 -> V_4 . V_145 ) {
F_48 ( V_2 ) ;
F_71 ( V_2 ) ;
}
F_36 ( & V_2 -> V_4 . V_71 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
enum V_64 V_64 ;
F_83 ( & V_2 -> V_4 . V_71 ) ;
if ( ! F_84 ( V_2 ) ) {
V_2 -> V_4 . V_5 = false ;
V_2 -> V_4 . V_78 = V_81 ;
return;
}
F_57 (dev_priv, pipe) {
V_2 -> V_4 . V_144 |=
F_80 ( V_64 ) ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) -> V_96 >= 8 )
break;
}
if ( F_56 ( V_2 ) -> V_96 >= 7 ) {
V_2 -> V_4 . V_146 = F_26 ;
V_2 -> V_4 . V_73 = F_27 ;
V_2 -> V_4 . V_77 = F_25 ;
} else if ( F_56 ( V_2 ) -> V_96 >= 5 ) {
V_2 -> V_4 . V_146 = F_26 ;
V_2 -> V_4 . V_73 = F_21 ;
V_2 -> V_4 . V_77 = F_25 ;
} else if ( F_65 ( V_2 ) ) {
V_2 -> V_4 . V_146 = F_18 ;
V_2 -> V_4 . V_73 = F_14 ;
V_2 -> V_4 . V_77 = F_17 ;
} else {
V_2 -> V_4 . V_146 = F_13 ;
V_2 -> V_4 . V_73 = F_6 ;
V_2 -> V_4 . V_77 = F_1 ;
F_3 ( V_6 , 500 << V_34 ) ;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_146 ( V_2 ) ;
}
