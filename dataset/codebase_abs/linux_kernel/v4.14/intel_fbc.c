static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_5 ( V_2 ) >= 8 ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
return F_5 ( V_2 ) < 4 ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 ) <= 3 ;
}
static unsigned int F_8 ( struct V_3 * V_4 )
{
return V_4 -> V_5 . V_6 - V_4 -> V_7 ;
}
static void F_9 ( struct V_8 * V_9 ,
int * V_10 , int * V_11 )
{
if ( V_10 )
* V_10 = V_9 -> V_12 . V_13 ;
if ( V_11 )
* V_11 = V_9 -> V_12 . V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_15 ;
F_9 ( V_9 , NULL , & V_15 ) ;
if ( F_5 ( V_2 ) == 7 )
V_15 = F_11 ( V_15 , 2048 ) ;
else if ( F_5 ( V_2 ) >= 8 )
V_15 = F_11 ( V_15 , 2560 ) ;
return V_15 * V_9 -> V_16 . V_17 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_13 ( V_19 ) ;
if ( ( V_18 & V_20 ) == 0 )
return;
V_18 &= ~ V_20 ;
F_14 ( V_19 , V_18 ) ;
if ( F_15 ( V_2 ,
V_21 , V_22 , 0 ,
10 ) ) {
F_16 ( L_1 ) ;
return;
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 . V_24 ;
int V_26 ;
int V_27 ;
T_1 V_18 ;
V_26 = V_24 -> V_28 / V_29 ;
if ( V_24 -> V_16 . V_17 < V_26 )
V_26 = V_24 -> V_16 . V_17 ;
if ( F_18 ( V_2 ) )
V_26 = ( V_26 / 32 ) - 1 ;
else
V_26 = ( V_26 / 64 ) - 1 ;
for ( V_27 = 0 ; V_27 < ( V_29 / 32 ) + 1 ; V_27 ++ )
F_14 ( F_19 ( V_27 ) , 0 ) ;
if ( F_20 ( V_2 ) ) {
T_1 V_30 ;
V_30 = V_31 | V_32 | V_33 ;
V_30 |= F_21 ( V_24 -> V_4 . V_12 ) ;
F_14 ( V_34 , V_30 ) ;
F_14 ( V_35 , V_24 -> V_4 . V_36 ) ;
}
V_18 = F_13 ( V_19 ) ;
V_18 &= 0x3fff << V_37 ;
V_18 |= V_20 | V_38 ;
if ( F_22 ( V_2 ) )
V_18 |= V_39 ;
V_18 |= ( V_26 & 0xff ) << V_40 ;
V_18 |= V_24 -> V_41 -> V_42 -> V_43 ;
F_14 ( V_19 , V_18 ) ;
}
static bool F_23 ( struct V_1 * V_2 )
{
return F_13 ( V_19 ) & V_20 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 . V_24 ;
T_1 V_44 ;
V_44 = F_25 ( V_24 -> V_4 . V_12 ) | V_45 ;
if ( V_24 -> V_16 . V_46 -> V_47 [ 0 ] == 2 )
V_44 |= V_48 ;
else
V_44 |= V_49 ;
if ( V_24 -> V_41 -> V_42 ) {
V_44 |= V_50 | V_24 -> V_41 -> V_42 -> V_43 ;
F_14 ( V_51 , V_24 -> V_4 . V_36 ) ;
} else {
F_14 ( V_51 , 0 ) ;
}
F_14 ( V_52 , V_44 | V_53 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_44 ;
V_44 = F_13 ( V_52 ) ;
if ( V_44 & V_53 ) {
V_44 &= ~ V_53 ;
F_14 ( V_52 , V_44 ) ;
}
}
static bool F_27 ( struct V_1 * V_2 )
{
return F_13 ( V_52 ) & V_53 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_14 ( V_54 , V_55 ) ;
F_29 ( V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 . V_24 ;
T_1 V_44 ;
int V_56 = V_2 -> V_25 . V_56 ;
V_44 = F_25 ( V_24 -> V_4 . V_12 ) ;
if ( V_24 -> V_16 . V_46 -> V_47 [ 0 ] == 2 )
V_56 ++ ;
switch ( V_56 ) {
case 4 :
case 3 :
V_44 |= V_57 ;
break;
case 2 :
V_44 |= V_48 ;
break;
case 1 :
V_44 |= V_49 ;
break;
}
if ( V_24 -> V_41 -> V_42 ) {
V_44 |= V_50 ;
if ( F_31 ( V_2 ) )
V_44 |= V_24 -> V_41 -> V_42 -> V_43 ;
if ( F_32 ( V_2 ) ) {
F_14 ( V_58 ,
V_59 |
V_24 -> V_41 -> V_42 -> V_43 ) ;
F_14 ( V_60 ,
V_24 -> V_4 . V_36 ) ;
}
} else {
if ( F_32 ( V_2 ) ) {
F_14 ( V_58 , 0 ) ;
F_14 ( V_60 , 0 ) ;
}
}
F_14 ( V_61 , V_24 -> V_4 . V_36 ) ;
F_14 ( V_62 ,
F_33 ( V_24 -> V_41 ) | V_63 ) ;
F_14 ( V_64 , V_44 | V_53 ) ;
F_28 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_44 ;
V_44 = F_13 ( V_64 ) ;
if ( V_44 & V_53 ) {
V_44 &= ~ V_53 ;
F_14 ( V_64 , V_44 ) ;
}
}
static bool F_35 ( struct V_1 * V_2 )
{
return F_13 ( V_64 ) & V_53 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 . V_24 ;
T_1 V_44 ;
int V_56 = V_2 -> V_25 . V_56 ;
V_44 = 0 ;
if ( F_37 ( V_2 ) )
V_44 |= F_38 ( V_24 -> V_4 . V_12 ) ;
if ( V_24 -> V_16 . V_46 -> V_47 [ 0 ] == 2 )
V_56 ++ ;
switch ( V_56 ) {
case 4 :
case 3 :
V_44 |= V_57 ;
break;
case 2 :
V_44 |= V_48 ;
break;
case 1 :
V_44 |= V_49 ;
break;
}
if ( V_24 -> V_41 -> V_42 ) {
V_44 |= V_65 ;
F_14 ( V_58 ,
V_59 |
V_24 -> V_41 -> V_42 -> V_43 ) ;
F_14 ( V_60 , V_24 -> V_4 . V_36 ) ;
} else {
F_14 ( V_58 , 0 ) ;
F_14 ( V_60 , 0 ) ;
}
if ( V_2 -> V_25 . V_66 )
V_44 |= V_67 ;
if ( F_37 ( V_2 ) ) {
F_14 ( V_68 ,
F_13 ( V_68 ) |
V_69 ) ;
} else if ( F_4 ( V_2 ) || F_39 ( V_2 ) ) {
F_14 ( F_40 ( V_24 -> V_4 . V_70 ) ,
F_13 ( F_40 ( V_24 -> V_4 . V_70 ) ) |
V_71 ) ;
}
F_14 ( V_64 , V_44 | V_53 ) ;
F_28 ( V_2 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) >= 5 )
return F_35 ( V_2 ) ;
else if ( F_42 ( V_2 ) )
return F_27 ( V_2 ) ;
else
return F_23 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
V_25 -> V_73 = true ;
if ( F_5 ( V_2 ) >= 7 )
F_36 ( V_2 ) ;
else if ( F_5 ( V_2 ) >= 5 )
F_30 ( V_2 ) ;
else if ( F_42 ( V_2 ) )
F_24 ( V_2 ) ;
else
F_17 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
V_25 -> V_73 = false ;
if ( F_5 ( V_2 ) >= 5 )
F_34 ( V_2 ) ;
else if ( F_42 ( V_2 ) )
F_26 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
bool F_45 ( struct V_1 * V_2 )
{
return V_2 -> V_25 . V_73 ;
}
static void F_46 ( struct V_74 * V_75 )
{
struct V_1 * V_2 =
F_47 ( V_75 , struct V_1 , V_25 . V_76 . V_76 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_77 * V_76 = & V_25 -> V_76 ;
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_78 * V_79 = & V_2 -> V_80 . V_79 [ V_4 -> V_70 ] ;
if ( F_48 ( & V_4 -> V_5 ) ) {
F_49 ( & V_25 -> V_81 ) ;
V_76 -> V_82 = false ;
F_50 ( & V_25 -> V_81 ) ;
return;
}
V_83:
F_51 ( V_79 -> V_84 ,
F_52 ( & V_4 -> V_5 ) != V_76 -> V_85 ,
F_53 ( 50 ) ) ;
F_49 ( & V_25 -> V_81 ) ;
if ( ! V_76 -> V_82 )
goto V_86;
if ( F_52 ( & V_4 -> V_5 ) == V_76 -> V_85 ) {
F_50 ( & V_25 -> V_81 ) ;
goto V_83;
}
F_43 ( V_2 ) ;
V_76 -> V_82 = false ;
V_86:
F_50 ( & V_25 -> V_81 ) ;
F_54 ( & V_4 -> V_5 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_77 * V_76 = & V_25 -> V_76 ;
F_57 ( ! F_58 ( & V_25 -> V_81 ) ) ;
if ( F_57 ( ! V_25 -> V_88 ) )
return;
if ( F_48 ( & V_4 -> V_5 ) ) {
F_59 ( L_2 ,
F_60 ( V_4 -> V_70 ) ) ;
return;
}
V_76 -> V_82 = true ;
V_76 -> V_85 = F_52 ( & V_4 -> V_5 ) ;
F_54 ( & V_4 -> V_5 ) ;
F_61 ( & V_76 -> V_76 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
F_57 ( ! F_58 ( & V_25 -> V_81 ) ) ;
V_25 -> V_76 . V_82 = false ;
if ( V_25 -> V_73 )
F_44 ( V_2 ) ;
}
static bool F_63 ( struct V_3 * V_4 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
enum V_70 V_70 = V_4 -> V_70 ;
if ( ! F_7 ( V_2 ) )
return true ;
if ( V_90 -> V_5 . V_91 )
V_25 -> V_92 |= ( 1 << V_70 ) ;
else
V_25 -> V_92 &= ~ ( 1 << V_70 ) ;
return ( V_25 -> V_92 & ~ ( 1 << V_70 ) ) != 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
int V_95 ,
int V_96 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
int V_99 = 1 ;
int V_100 ;
T_2 V_101 ;
if ( F_39 ( V_2 ) || F_65 ( V_2 ) )
V_101 = V_98 -> V_102 - 8 * 1024 * 1024 ;
else
V_101 = V_103 ;
V_100 = F_66 ( V_2 , V_94 , V_95 <<= 1 ,
4096 , 0 , V_101 ) ;
if ( V_100 == 0 )
return V_99 ;
V_104:
if ( V_99 > 4 ||
( V_96 == 2 && V_99 == 2 ) )
return 0 ;
V_100 = F_66 ( V_2 , V_94 , V_95 >>= 1 ,
4096 , 0 , V_101 ) ;
if ( V_100 && F_5 ( V_2 ) <= 4 ) {
return 0 ;
} else if ( V_100 ) {
V_99 <<= 1 ;
goto V_104;
} else {
return V_99 ;
}
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_93 * V_105 ( V_106 ) ;
int V_95 , V_96 , V_100 ;
F_57 ( F_68 ( & V_25 -> V_107 ) ) ;
V_95 = F_10 ( V_2 , & V_25 -> V_108 ) ;
V_96 = V_25 -> V_108 . V_16 . V_46 -> V_47 [ 0 ] ;
V_100 = F_64 ( V_2 , & V_25 -> V_107 ,
V_95 , V_96 ) ;
if ( ! V_100 )
goto V_109;
else if ( V_100 > 1 ) {
F_69 ( L_3 ) ;
}
V_25 -> V_56 = V_100 ;
if ( F_5 ( V_2 ) >= 5 )
F_14 ( V_110 , V_25 -> V_107 . V_111 ) ;
else if ( F_42 ( V_2 ) ) {
F_14 ( V_112 , V_25 -> V_107 . V_111 ) ;
} else {
V_106 = F_70 ( sizeof( * V_106 ) , V_113 ) ;
if ( ! V_106 )
goto V_114;
V_100 = F_71 ( V_2 , V_106 ,
4096 , 4096 ) ;
if ( V_100 )
goto V_114;
V_25 -> V_106 = V_106 ;
F_14 ( V_115 ,
V_2 -> V_116 . V_117 + V_25 -> V_107 . V_111 ) ;
F_14 ( V_118 ,
V_2 -> V_116 . V_117 + V_106 -> V_111 ) ;
}
F_16 ( L_4 ,
V_25 -> V_107 . V_95 , V_25 -> V_56 ) ;
return 0 ;
V_114:
F_72 ( V_106 ) ;
F_73 ( V_2 , & V_25 -> V_107 ) ;
V_109:
if ( F_74 ( & V_2 -> V_116 . V_119 ) )
F_75 ( L_5 , V_95 ) ;
return - V_120 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( F_68 ( & V_25 -> V_107 ) )
F_73 ( V_2 , & V_25 -> V_107 ) ;
if ( V_25 -> V_106 ) {
F_73 ( V_2 , V_25 -> V_106 ) ;
F_72 ( V_25 -> V_106 ) ;
}
}
void F_77 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
F_76 ( V_2 ) ;
F_50 ( & V_25 -> V_81 ) ;
}
static bool F_78 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
F_57 ( V_17 < 512 ) ;
F_57 ( ( V_17 & ( 64 - 1 ) ) != 0 ) ;
if ( F_18 ( V_2 ) || F_79 ( V_2 ) )
return V_17 == 4096 || V_17 == 8192 ;
if ( F_20 ( V_2 ) && ! F_80 ( V_2 ) && V_17 < 2048 )
return false ;
if ( V_17 > 16384 )
return false ;
return true ;
}
static bool F_81 ( struct V_1 * V_2 ,
T_3 V_121 )
{
switch ( V_121 ) {
case V_122 :
case V_123 :
return true ;
case V_124 :
case V_125 :
if ( F_18 ( V_2 ) )
return false ;
if ( F_80 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_82 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
unsigned int V_126 , V_127 , V_128 , V_129 ;
if ( F_5 ( V_2 ) >= 8 || F_4 ( V_2 ) ) {
V_128 = 4096 ;
V_129 = 4096 ;
} else if ( F_80 ( V_2 ) || F_5 ( V_2 ) >= 5 ) {
V_128 = 4096 ;
V_129 = 2048 ;
} else {
V_128 = 2048 ;
V_129 = 1536 ;
}
F_9 ( & V_25 -> V_108 , & V_126 ,
& V_127 ) ;
V_126 += V_4 -> V_130 ;
V_127 += V_4 -> V_7 ;
return V_126 <= V_128 && V_127 <= V_129 ;
}
static void F_83 ( struct V_3 * V_4 ,
struct V_131 * V_132 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_8 * V_9 = & V_25 -> V_108 ;
struct V_133 * V_16 = V_90 -> V_5 . V_16 ;
V_9 -> V_41 = NULL ;
V_9 -> V_4 . V_134 = V_132 -> V_5 . V_135 . V_136 ;
if ( F_4 ( V_2 ) || F_39 ( V_2 ) )
V_9 -> V_4 . V_137 = V_132 -> V_138 ;
V_9 -> V_12 . V_139 = V_90 -> V_5 . V_139 ;
V_9 -> V_12 . V_13 = F_84 ( & V_90 -> V_5 . V_140 ) >> 16 ;
V_9 -> V_12 . V_14 = F_85 ( & V_90 -> V_5 . V_140 ) >> 16 ;
V_9 -> V_12 . V_91 = V_90 -> V_5 . V_91 ;
if ( ! V_9 -> V_12 . V_91 )
return;
V_9 -> V_16 . V_46 = V_16 -> V_46 ;
V_9 -> V_16 . V_17 = V_16 -> V_141 [ 0 ] ;
V_9 -> V_41 = V_90 -> V_41 ;
}
static bool F_86 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_8 * V_9 = & V_25 -> V_108 ;
if ( V_25 -> V_142 ) {
V_25 -> V_143 = L_6 ;
return false ;
}
if ( ! V_9 -> V_41 ) {
V_25 -> V_143 = L_7 ;
return false ;
}
if ( ( V_9 -> V_4 . V_134 & V_144 ) ||
( V_9 -> V_4 . V_134 & V_145 ) ) {
V_25 -> V_143 = L_8 ;
return false ;
}
if ( ! F_82 ( V_4 ) ) {
V_25 -> V_143 = L_9 ;
return false ;
}
if ( ! V_9 -> V_41 -> V_42 ) {
V_25 -> V_143 = L_10 ;
return false ;
}
if ( F_5 ( V_2 ) <= 4 && ! F_80 ( V_2 ) &&
V_9 -> V_12 . V_139 != V_146 ) {
V_25 -> V_143 = L_11 ;
return false ;
}
if ( ! F_78 ( V_2 , V_9 -> V_16 . V_17 ) ) {
V_25 -> V_143 = L_12 ;
return false ;
}
if ( ! F_81 ( V_2 , V_9 -> V_16 . V_46 -> V_46 ) ) {
V_25 -> V_143 = L_13 ;
return false ;
}
if ( ( F_4 ( V_2 ) || F_39 ( V_2 ) ) &&
V_9 -> V_4 . V_137 >= V_2 -> V_147 . V_148 . V_147 * 95 / 100 ) {
V_25 -> V_143 = L_14 ;
return false ;
}
if ( F_10 ( V_2 , & V_25 -> V_108 ) >
V_25 -> V_107 . V_95 * V_25 -> V_56 ) {
V_25 -> V_143 = L_15 ;
return false ;
}
return true ;
}
static bool F_87 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( F_88 ( V_2 ) ) {
V_25 -> V_143 = L_16 ;
return false ;
}
if ( ! V_149 . V_150 ) {
V_25 -> V_143 = L_17 ;
return false ;
}
if ( V_25 -> V_142 ) {
V_25 -> V_143 = L_6 ;
return false ;
}
return true ;
}
static void F_89 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_8 * V_9 = & V_25 -> V_108 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_41 = V_9 -> V_41 ;
V_24 -> V_4 . V_70 = V_4 -> V_70 ;
V_24 -> V_4 . V_12 = V_4 -> V_12 ;
V_24 -> V_4 . V_36 = F_8 ( V_4 ) ;
V_24 -> V_16 . V_46 = V_9 -> V_16 . V_46 ;
V_24 -> V_16 . V_17 = V_9 -> V_16 . V_17 ;
V_24 -> V_28 = F_10 ( V_2 , V_9 ) ;
}
static bool F_90 ( struct V_23 * V_151 ,
struct V_23 * V_152 )
{
return memcmp ( V_151 , V_152 , sizeof( * V_151 ) ) == 0 ;
}
void F_91 ( struct V_3 * V_4 ,
struct V_131 * V_132 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
if ( ! F_63 ( V_4 , V_90 ) ) {
V_25 -> V_143 = L_18 ;
goto V_153;
}
if ( ! V_25 -> V_88 || V_25 -> V_4 != V_4 )
goto V_154;
F_83 ( V_4 , V_132 , V_90 ) ;
V_153:
F_62 ( V_2 ) ;
V_154:
F_50 ( & V_25 -> V_81 ) ;
}
static void F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_23 V_155 ;
F_57 ( ! F_58 ( & V_25 -> V_81 ) ) ;
if ( ! V_25 -> V_88 || V_25 -> V_4 != V_4 )
return;
if ( ! F_86 ( V_4 ) ) {
F_57 ( V_25 -> V_73 ) ;
return;
}
V_155 = V_25 -> V_24 ;
F_89 ( V_4 , & V_25 -> V_24 ) ;
if ( V_25 -> V_73 &&
F_90 ( & V_155 , & V_25 -> V_24 ) )
return;
F_62 ( V_2 ) ;
F_55 ( V_4 ) ;
V_25 -> V_143 = L_19 ;
}
void F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
F_92 ( V_4 ) ;
F_50 ( & V_25 -> V_81 ) ;
}
static unsigned int F_94 ( struct V_72 * V_25 )
{
if ( V_25 -> V_88 )
return F_95 ( V_25 -> V_4 -> V_5 . V_156 ) -> V_157 ;
else
return V_25 -> V_158 ;
}
void F_96 ( struct V_1 * V_2 ,
unsigned int V_159 ,
enum V_160 V_161 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_161 == V_162 || V_161 == V_163 )
return;
F_49 ( & V_25 -> V_81 ) ;
V_25 -> V_164 |= F_94 ( V_25 ) & V_159 ;
if ( V_25 -> V_88 && V_25 -> V_164 )
F_62 ( V_2 ) ;
F_50 ( & V_25 -> V_81 ) ;
}
void F_97 ( struct V_1 * V_2 ,
unsigned int V_159 , enum V_160 V_161 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
V_25 -> V_164 &= ~ V_159 ;
if ( V_161 == V_162 || V_161 == V_163 )
goto V_86;
if ( ! V_25 -> V_164 && V_25 -> V_88 &&
( V_159 & F_94 ( V_25 ) ) ) {
if ( V_25 -> V_73 )
F_28 ( V_2 ) ;
else
F_92 ( V_25 -> V_4 ) ;
}
V_86:
F_50 ( & V_25 -> V_81 ) ;
}
void F_98 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_167 * V_12 ;
struct V_168 * V_90 ;
bool V_169 = false ;
int V_27 ;
F_49 ( & V_25 -> V_81 ) ;
if ( V_25 -> V_4 &&
! F_99 ( V_166 , & V_25 -> V_4 -> V_5 ) )
goto V_86;
if ( ! F_87 ( V_2 ) )
goto V_86;
F_100 (state, plane, plane_state, i) {
struct V_89 * V_89 =
F_101 ( V_90 ) ;
struct V_131 * V_131 ;
struct V_3 * V_4 = F_102 ( V_90 -> V_4 ) ;
if ( ! V_89 -> V_5 . V_91 )
continue;
if ( F_3 ( V_2 ) && V_4 -> V_70 != V_170 )
continue;
if ( F_6 ( V_2 ) && V_4 -> V_12 != V_171 )
continue;
V_131 = F_103 (
F_99 ( V_166 , & V_4 -> V_5 ) ) ;
V_131 -> V_150 = true ;
V_169 = true ;
break;
}
if ( ! V_169 )
V_25 -> V_143 = L_20 ;
V_86:
F_50 ( & V_25 -> V_81 ) ;
}
void F_104 ( struct V_3 * V_4 ,
struct V_131 * V_132 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
if ( V_25 -> V_88 ) {
F_57 ( V_25 -> V_4 == NULL ) ;
if ( V_25 -> V_4 == V_4 ) {
F_57 ( ! V_132 -> V_150 ) ;
F_57 ( V_25 -> V_73 ) ;
}
goto V_86;
}
if ( ! V_132 -> V_150 )
goto V_86;
F_57 ( V_25 -> V_73 ) ;
F_57 ( V_25 -> V_4 != NULL ) ;
F_83 ( V_4 , V_132 , V_90 ) ;
if ( F_67 ( V_4 ) ) {
V_25 -> V_143 = L_21 ;
goto V_86;
}
F_16 ( L_22 , F_60 ( V_4 -> V_70 ) ) ;
V_25 -> V_143 = L_23 ;
V_25 -> V_88 = true ;
V_25 -> V_4 = V_4 ;
V_86:
F_50 ( & V_25 -> V_81 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
struct V_3 * V_4 = V_25 -> V_4 ;
F_57 ( ! F_58 ( & V_25 -> V_81 ) ) ;
F_57 ( ! V_25 -> V_88 ) ;
F_57 ( V_25 -> V_73 ) ;
F_57 ( V_4 -> V_73 ) ;
F_16 ( L_24 , F_60 ( V_4 -> V_70 ) ) ;
F_76 ( V_2 ) ;
V_25 -> V_88 = false ;
V_25 -> V_4 = NULL ;
}
void F_106 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_56 ( V_4 -> V_5 . V_87 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
if ( V_25 -> V_4 == V_4 )
F_105 ( V_2 ) ;
F_50 ( & V_25 -> V_81 ) ;
F_107 ( & V_25 -> V_76 . V_76 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
F_49 ( & V_25 -> V_81 ) ;
if ( V_25 -> V_88 )
F_105 ( V_2 ) ;
F_50 ( & V_25 -> V_81 ) ;
F_107 ( & V_25 -> V_76 . V_76 ) ;
}
static void F_109 ( struct V_74 * V_76 )
{
struct V_1 * V_2 =
F_47 ( V_76 , struct V_1 , V_25 . V_172 ) ;
struct V_72 * V_25 = & V_2 -> V_25 ;
F_49 ( & V_25 -> V_81 ) ;
if ( V_25 -> V_142 || ! V_25 -> V_88 )
goto V_86;
F_16 ( L_25 ) ;
V_25 -> V_142 = true ;
F_62 ( V_2 ) ;
V_86:
F_50 ( & V_25 -> V_81 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
if ( ! F_1 ( V_2 ) )
return;
if ( F_111 ( V_25 -> V_142 ) )
return;
F_61 ( & V_25 -> V_172 ) ;
}
void F_112 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_7 ( V_2 ) )
return;
F_113 (&dev_priv->drm, crtc)
if ( F_114 ( V_4 ) &&
V_4 -> V_5 . V_156 -> V_166 -> V_91 )
V_2 -> V_25 . V_92 |= ( 1 << V_4 -> V_70 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
if ( V_149 . V_150 >= 0 )
return ! ! V_149 . V_150 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_39 ( V_2 ) || F_5 ( V_2 ) >= 9 )
return 1 ;
return 0 ;
}
static bool F_116 ( struct V_1 * V_2 )
{
if ( F_117 () &&
( F_118 ( V_2 ) || F_119 ( V_2 ) ) ) {
F_69 ( L_26 ) ;
return true ;
}
return false ;
}
void F_120 ( struct V_1 * V_2 )
{
struct V_72 * V_25 = & V_2 -> V_25 ;
enum V_70 V_70 ;
F_121 ( & V_25 -> V_76 . V_76 , F_46 ) ;
F_121 ( & V_25 -> V_172 , F_109 ) ;
F_122 ( & V_25 -> V_81 ) ;
V_25 -> V_88 = false ;
V_25 -> V_73 = false ;
V_25 -> V_76 . V_82 = false ;
if ( F_116 ( V_2 ) )
F_123 ( V_2 ) -> V_173 = false ;
V_149 . V_150 = F_115 ( V_2 ) ;
F_16 ( L_27 , V_149 . V_150 ) ;
if ( ! F_2 ( V_2 ) ) {
V_25 -> V_143 = L_28 ;
return;
}
F_124 (dev_priv, pipe) {
V_25 -> V_158 |=
F_125 ( V_70 ) ;
if ( F_3 ( V_2 ) )
break;
}
if ( F_5 ( V_2 ) <= 4 && ! F_42 ( V_2 ) )
F_14 ( V_19 , 500 << V_37 ) ;
if ( F_41 ( V_2 ) )
F_44 ( V_2 ) ;
}
