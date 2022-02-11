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
int V_12 , V_13 ;
if ( F_10 ( V_9 -> V_14 . V_15 ) ) {
V_12 = V_9 -> V_14 . V_16 ;
V_13 = V_9 -> V_14 . V_17 ;
} else {
V_12 = V_9 -> V_14 . V_17 ;
V_13 = V_9 -> V_14 . V_16 ;
}
if ( V_10 )
* V_10 = V_12 ;
if ( V_11 )
* V_11 = V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_18 ;
F_9 ( V_9 , NULL , & V_18 ) ;
if ( F_5 ( V_2 ) == 7 )
V_18 = F_12 ( V_18 , 2048 ) ;
else if ( F_5 ( V_2 ) >= 8 )
V_18 = F_12 ( V_18 , 2560 ) ;
return V_18 * V_9 -> V_19 . V_20 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_14 ( V_22 ) ;
if ( ( V_21 & V_23 ) == 0 )
return;
V_21 &= ~ V_23 ;
F_15 ( V_22 , V_21 ) ;
if ( F_16 ( V_2 ,
V_24 , V_25 , 0 ,
10 ) ) {
F_17 ( L_1 ) ;
return;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_27 ;
int V_29 ;
int V_30 ;
T_1 V_21 ;
V_29 = V_27 -> V_31 / V_32 ;
if ( V_27 -> V_19 . V_20 < V_29 )
V_29 = V_27 -> V_19 . V_20 ;
if ( F_19 ( V_2 ) )
V_29 = ( V_29 / 32 ) - 1 ;
else
V_29 = ( V_29 / 64 ) - 1 ;
for ( V_30 = 0 ; V_30 < ( V_32 / 32 ) + 1 ; V_30 ++ )
F_15 ( F_20 ( V_30 ) , 0 ) ;
if ( F_21 ( V_2 ) ) {
T_1 V_33 ;
V_33 = V_34 | V_35 | V_36 ;
V_33 |= F_22 ( V_27 -> V_4 . V_14 ) ;
F_15 ( V_37 , V_33 ) ;
F_15 ( V_38 , V_27 -> V_4 . V_39 ) ;
}
V_21 = F_14 ( V_22 ) ;
V_21 &= 0x3fff << V_40 ;
V_21 |= V_23 | V_41 ;
if ( F_23 ( V_2 ) )
V_21 |= V_42 ;
V_21 |= ( V_29 & 0xff ) << V_43 ;
V_21 |= V_27 -> V_44 -> V_45 -> V_46 ;
F_15 ( V_22 , V_21 ) ;
}
static bool F_24 ( struct V_1 * V_2 )
{
return F_14 ( V_22 ) & V_23 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_27 ;
T_1 V_47 ;
V_47 = F_26 ( V_27 -> V_4 . V_14 ) | V_48 ;
if ( V_27 -> V_19 . V_49 -> V_50 [ 0 ] == 2 )
V_47 |= V_51 ;
else
V_47 |= V_52 ;
if ( V_27 -> V_44 -> V_45 ) {
V_47 |= V_53 | V_27 -> V_44 -> V_45 -> V_46 ;
F_15 ( V_54 , V_27 -> V_4 . V_39 ) ;
} else {
F_15 ( V_54 , 0 ) ;
}
F_15 ( V_55 , V_47 | V_56 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_47 ;
V_47 = F_14 ( V_55 ) ;
if ( V_47 & V_56 ) {
V_47 &= ~ V_56 ;
F_15 ( V_55 , V_47 ) ;
}
}
static bool F_28 ( struct V_1 * V_2 )
{
return F_14 ( V_55 ) & V_56 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_15 ( V_57 , V_58 ) ;
F_30 ( V_57 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_27 ;
T_1 V_47 ;
int V_59 = V_2 -> V_28 . V_59 ;
V_47 = F_26 ( V_27 -> V_4 . V_14 ) ;
if ( V_27 -> V_19 . V_49 -> V_50 [ 0 ] == 2 )
V_59 ++ ;
switch ( V_59 ) {
case 4 :
case 3 :
V_47 |= V_60 ;
break;
case 2 :
V_47 |= V_51 ;
break;
case 1 :
V_47 |= V_52 ;
break;
}
if ( V_27 -> V_44 -> V_45 ) {
V_47 |= V_53 ;
if ( F_32 ( V_2 ) )
V_47 |= V_27 -> V_44 -> V_45 -> V_46 ;
if ( F_33 ( V_2 ) ) {
F_15 ( V_61 ,
V_62 |
V_27 -> V_44 -> V_45 -> V_46 ) ;
F_15 ( V_63 ,
V_27 -> V_4 . V_39 ) ;
}
} else {
if ( F_33 ( V_2 ) ) {
F_15 ( V_61 , 0 ) ;
F_15 ( V_63 , 0 ) ;
}
}
F_15 ( V_64 , V_27 -> V_4 . V_39 ) ;
F_15 ( V_65 ,
F_34 ( V_27 -> V_44 ) | V_66 ) ;
F_15 ( V_67 , V_47 | V_56 ) ;
F_29 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_47 ;
V_47 = F_14 ( V_67 ) ;
if ( V_47 & V_56 ) {
V_47 &= ~ V_56 ;
F_15 ( V_67 , V_47 ) ;
}
}
static bool F_36 ( struct V_1 * V_2 )
{
return F_14 ( V_67 ) & V_56 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_27 ;
T_1 V_47 ;
int V_59 = V_2 -> V_28 . V_59 ;
V_47 = 0 ;
if ( F_38 ( V_2 ) )
V_47 |= F_39 ( V_27 -> V_4 . V_14 ) ;
if ( V_27 -> V_19 . V_49 -> V_50 [ 0 ] == 2 )
V_59 ++ ;
switch ( V_59 ) {
case 4 :
case 3 :
V_47 |= V_60 ;
break;
case 2 :
V_47 |= V_51 ;
break;
case 1 :
V_47 |= V_52 ;
break;
}
if ( V_27 -> V_44 -> V_45 ) {
V_47 |= V_68 ;
F_15 ( V_61 ,
V_62 |
V_27 -> V_44 -> V_45 -> V_46 ) ;
F_15 ( V_63 , V_27 -> V_4 . V_39 ) ;
} else {
F_15 ( V_61 , 0 ) ;
F_15 ( V_63 , 0 ) ;
}
if ( V_2 -> V_28 . V_69 )
V_47 |= V_70 ;
if ( F_38 ( V_2 ) ) {
F_15 ( V_71 ,
F_14 ( V_71 ) |
V_72 ) ;
} else if ( F_4 ( V_2 ) || F_40 ( V_2 ) ) {
F_15 ( F_41 ( V_27 -> V_4 . V_73 ) ,
F_14 ( F_41 ( V_27 -> V_4 . V_73 ) ) |
V_74 ) ;
}
F_15 ( V_67 , V_47 | V_56 ) ;
F_29 ( V_2 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) >= 5 )
return F_36 ( V_2 ) ;
else if ( F_43 ( V_2 ) )
return F_28 ( V_2 ) ;
else
return F_24 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
V_28 -> V_76 = true ;
if ( F_5 ( V_2 ) >= 7 )
F_37 ( V_2 ) ;
else if ( F_5 ( V_2 ) >= 5 )
F_31 ( V_2 ) ;
else if ( F_43 ( V_2 ) )
F_25 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
V_28 -> V_76 = false ;
if ( F_5 ( V_2 ) >= 5 )
F_35 ( V_2 ) ;
else if ( F_43 ( V_2 ) )
F_27 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
bool F_46 ( struct V_1 * V_2 )
{
return V_2 -> V_28 . V_76 ;
}
static void F_47 ( struct V_77 * V_78 )
{
struct V_1 * V_2 =
F_48 ( V_78 , struct V_1 , V_28 . V_79 . V_79 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_80 * V_79 = & V_28 -> V_79 ;
struct V_3 * V_4 = V_28 -> V_4 ;
struct V_81 * V_82 = & V_2 -> V_83 . V_82 [ V_4 -> V_73 ] ;
if ( F_49 ( & V_4 -> V_5 ) ) {
F_50 ( L_2 ,
F_51 ( V_4 -> V_73 ) ) ;
F_52 ( & V_28 -> V_84 ) ;
V_79 -> V_85 = false ;
F_53 ( & V_28 -> V_84 ) ;
return;
}
V_86:
F_54 ( V_82 -> V_87 ,
F_55 ( & V_4 -> V_5 ) != V_79 -> V_88 ,
F_56 ( 50 ) ) ;
F_52 ( & V_28 -> V_84 ) ;
if ( ! V_79 -> V_85 )
goto V_89;
if ( F_55 ( & V_4 -> V_5 ) == V_79 -> V_88 ) {
F_53 ( & V_28 -> V_84 ) ;
goto V_86;
}
F_44 ( V_2 ) ;
V_79 -> V_85 = false ;
V_89:
F_53 ( & V_28 -> V_84 ) ;
F_57 ( & V_4 -> V_5 ) ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_80 * V_79 = & V_28 -> V_79 ;
F_60 ( ! F_61 ( & V_28 -> V_84 ) ) ;
if ( F_49 ( & V_4 -> V_5 ) ) {
F_50 ( L_2 ,
F_51 ( V_4 -> V_73 ) ) ;
return;
}
V_79 -> V_85 = true ;
V_79 -> V_88 = F_55 ( & V_4 -> V_5 ) ;
F_57 ( & V_4 -> V_5 ) ;
F_62 ( & V_79 -> V_79 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
F_60 ( ! F_61 ( & V_28 -> V_84 ) ) ;
V_28 -> V_79 . V_85 = false ;
if ( V_28 -> V_76 )
F_45 ( V_2 ) ;
}
static bool F_64 ( struct V_3 * V_4 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
enum V_73 V_73 = V_4 -> V_73 ;
if ( ! F_7 ( V_2 ) )
return true ;
if ( V_92 -> V_5 . V_93 )
V_28 -> V_94 |= ( 1 << V_73 ) ;
else
V_28 -> V_94 &= ~ ( 1 << V_73 ) ;
return ( V_28 -> V_94 & ~ ( 1 << V_73 ) ) != 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
int V_97 ,
int V_98 )
{
struct V_99 * V_100 = & V_2 -> V_100 ;
int V_101 = 1 ;
int V_102 ;
T_2 V_103 ;
if ( F_40 ( V_2 ) ||
F_66 ( V_2 ) || F_67 ( V_2 ) )
V_103 = V_100 -> V_104 - 8 * 1024 * 1024 ;
else
V_103 = V_105 ;
V_102 = F_68 ( V_2 , V_96 , V_97 <<= 1 ,
4096 , 0 , V_103 ) ;
if ( V_102 == 0 )
return V_101 ;
V_106:
if ( V_101 > 4 ||
( V_98 == 2 && V_101 == 2 ) )
return 0 ;
V_102 = F_68 ( V_2 , V_96 , V_97 >>= 1 ,
4096 , 0 , V_103 ) ;
if ( V_102 && F_5 ( V_2 ) <= 4 ) {
return 0 ;
} else if ( V_102 ) {
V_101 <<= 1 ;
goto V_106;
} else {
return V_101 ;
}
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_95 * V_107 ( V_108 ) ;
int V_97 , V_98 , V_102 ;
F_60 ( F_70 ( & V_28 -> V_109 ) ) ;
V_97 = F_11 ( V_2 , & V_28 -> V_110 ) ;
V_98 = V_28 -> V_110 . V_19 . V_49 -> V_50 [ 0 ] ;
V_102 = F_65 ( V_2 , & V_28 -> V_109 ,
V_97 , V_98 ) ;
if ( ! V_102 )
goto V_111;
else if ( V_102 > 1 ) {
F_71 ( L_3 ) ;
}
V_28 -> V_59 = V_102 ;
if ( F_5 ( V_2 ) >= 5 )
F_15 ( V_112 , V_28 -> V_109 . V_113 ) ;
else if ( F_43 ( V_2 ) ) {
F_15 ( V_114 , V_28 -> V_109 . V_113 ) ;
} else {
V_108 = F_72 ( sizeof( * V_108 ) , V_115 ) ;
if ( ! V_108 )
goto V_116;
V_102 = F_73 ( V_2 , V_108 ,
4096 , 4096 ) ;
if ( V_102 )
goto V_116;
V_28 -> V_108 = V_108 ;
F_15 ( V_117 ,
V_2 -> V_118 . V_119 + V_28 -> V_109 . V_113 ) ;
F_15 ( V_120 ,
V_2 -> V_118 . V_119 + V_108 -> V_113 ) ;
}
F_17 ( L_4 ,
V_28 -> V_109 . V_97 , V_28 -> V_59 ) ;
return 0 ;
V_116:
F_74 ( V_108 ) ;
F_75 ( V_2 , & V_28 -> V_109 ) ;
V_111:
F_76 ( L_5 , V_97 ) ;
return - V_121 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( F_70 ( & V_28 -> V_109 ) )
F_75 ( V_2 , & V_28 -> V_109 ) ;
if ( V_28 -> V_108 ) {
F_75 ( V_2 , V_28 -> V_108 ) ;
F_74 ( V_28 -> V_108 ) ;
}
}
void F_78 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
F_77 ( V_2 ) ;
F_53 ( & V_28 -> V_84 ) ;
}
static bool F_79 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
F_60 ( V_20 < 512 ) ;
F_60 ( ( V_20 & ( 64 - 1 ) ) != 0 ) ;
if ( F_19 ( V_2 ) || F_80 ( V_2 ) )
return V_20 == 4096 || V_20 == 8192 ;
if ( F_21 ( V_2 ) && ! F_81 ( V_2 ) && V_20 < 2048 )
return false ;
if ( V_20 > 16384 )
return false ;
return true ;
}
static bool F_82 ( struct V_1 * V_2 ,
T_3 V_122 )
{
switch ( V_122 ) {
case V_123 :
case V_124 :
return true ;
case V_125 :
case V_126 :
if ( F_19 ( V_2 ) )
return false ;
if ( F_81 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_83 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
unsigned int V_127 , V_128 , V_129 , V_130 ;
if ( F_5 ( V_2 ) >= 8 || F_4 ( V_2 ) ) {
V_129 = 4096 ;
V_130 = 4096 ;
} else if ( F_81 ( V_2 ) || F_5 ( V_2 ) >= 5 ) {
V_129 = 4096 ;
V_130 = 2048 ;
} else {
V_129 = 2048 ;
V_130 = 1536 ;
}
F_9 ( & V_28 -> V_110 , & V_127 ,
& V_128 ) ;
V_127 += V_4 -> V_131 ;
V_128 += V_4 -> V_7 ;
return V_127 <= V_129 && V_128 <= V_130 ;
}
static void F_84 ( struct V_3 * V_4 ,
struct V_132 * V_133 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_8 * V_9 = & V_28 -> V_110 ;
struct V_134 * V_19 = V_92 -> V_5 . V_19 ;
V_9 -> V_44 = NULL ;
V_9 -> V_4 . V_135 = V_133 -> V_5 . V_136 . V_137 ;
if ( F_4 ( V_2 ) || F_40 ( V_2 ) )
V_9 -> V_4 . V_138 =
F_85 ( V_133 ) ;
V_9 -> V_14 . V_15 = V_92 -> V_5 . V_15 ;
V_9 -> V_14 . V_17 = F_86 ( & V_92 -> V_5 . V_139 ) >> 16 ;
V_9 -> V_14 . V_16 = F_87 ( & V_92 -> V_5 . V_139 ) >> 16 ;
V_9 -> V_14 . V_93 = V_92 -> V_5 . V_93 ;
if ( ! V_9 -> V_14 . V_93 )
return;
V_9 -> V_19 . V_49 = V_19 -> V_49 ;
V_9 -> V_19 . V_20 = V_19 -> V_140 [ 0 ] ;
V_9 -> V_44 = V_92 -> V_44 ;
}
static bool F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_8 * V_9 = & V_28 -> V_110 ;
if ( V_28 -> V_141 ) {
V_28 -> V_142 = L_6 ;
return false ;
}
if ( ! V_9 -> V_44 ) {
V_28 -> V_142 = L_7 ;
return false ;
}
if ( ( V_9 -> V_4 . V_135 & V_143 ) ||
( V_9 -> V_4 . V_135 & V_144 ) ) {
V_28 -> V_142 = L_8 ;
return false ;
}
if ( ! F_83 ( V_4 ) ) {
V_28 -> V_142 = L_9 ;
return false ;
}
if ( ! V_9 -> V_44 -> V_45 ) {
V_28 -> V_142 = L_10 ;
return false ;
}
if ( F_5 ( V_2 ) <= 4 && ! F_81 ( V_2 ) &&
V_9 -> V_14 . V_15 != V_145 ) {
V_28 -> V_142 = L_11 ;
return false ;
}
if ( ! F_79 ( V_2 , V_9 -> V_19 . V_20 ) ) {
V_28 -> V_142 = L_12 ;
return false ;
}
if ( ! F_82 ( V_2 , V_9 -> V_19 . V_49 -> V_49 ) ) {
V_28 -> V_142 = L_13 ;
return false ;
}
if ( ( F_4 ( V_2 ) || F_40 ( V_2 ) ) &&
V_9 -> V_4 . V_138 >= V_2 -> V_146 * 95 / 100 ) {
V_28 -> V_142 = L_14 ;
return false ;
}
if ( F_11 ( V_2 , & V_28 -> V_110 ) >
V_28 -> V_109 . V_97 * V_28 -> V_59 ) {
V_28 -> V_142 = L_15 ;
return false ;
}
return true ;
}
static bool F_89 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( F_90 ( V_2 ) ) {
V_28 -> V_142 = L_16 ;
return false ;
}
if ( ! V_147 . V_148 ) {
V_28 -> V_142 = L_17 ;
return false ;
}
if ( V_28 -> V_141 ) {
V_28 -> V_142 = L_6 ;
return false ;
}
return true ;
}
static void F_91 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_8 * V_9 = & V_28 -> V_110 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_44 = V_9 -> V_44 ;
V_27 -> V_4 . V_73 = V_4 -> V_73 ;
V_27 -> V_4 . V_14 = V_4 -> V_14 ;
V_27 -> V_4 . V_39 = F_8 ( V_4 ) ;
V_27 -> V_19 . V_49 = V_9 -> V_19 . V_49 ;
V_27 -> V_19 . V_20 = V_9 -> V_19 . V_20 ;
V_27 -> V_31 = F_11 ( V_2 , V_9 ) ;
}
static bool F_92 ( struct V_26 * V_149 ,
struct V_26 * V_150 )
{
return memcmp ( V_149 , V_150 , sizeof( * V_149 ) ) == 0 ;
}
void F_93 ( struct V_3 * V_4 ,
struct V_132 * V_133 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
if ( ! F_64 ( V_4 , V_92 ) ) {
V_28 -> V_142 = L_18 ;
goto V_151;
}
if ( ! V_28 -> V_152 || V_28 -> V_4 != V_4 )
goto V_153;
F_84 ( V_4 , V_133 , V_92 ) ;
V_151:
F_63 ( V_2 ) ;
V_153:
F_53 ( & V_28 -> V_84 ) ;
}
static void F_94 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_26 V_154 ;
F_60 ( ! F_61 ( & V_28 -> V_84 ) ) ;
if ( ! V_28 -> V_152 || V_28 -> V_4 != V_4 )
return;
if ( ! F_88 ( V_4 ) ) {
F_60 ( V_28 -> V_76 ) ;
return;
}
V_154 = V_28 -> V_27 ;
F_91 ( V_4 , & V_28 -> V_27 ) ;
if ( V_28 -> V_76 &&
F_92 ( & V_154 , & V_28 -> V_27 ) )
return;
F_63 ( V_2 ) ;
F_58 ( V_4 ) ;
V_28 -> V_142 = L_19 ;
}
void F_95 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
F_94 ( V_4 ) ;
F_53 ( & V_28 -> V_84 ) ;
}
static unsigned int F_96 ( struct V_75 * V_28 )
{
if ( V_28 -> V_152 )
return F_97 ( V_28 -> V_4 -> V_5 . V_155 ) -> V_156 ;
else
return V_28 -> V_157 ;
}
void F_98 ( struct V_1 * V_2 ,
unsigned int V_158 ,
enum V_159 V_160 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_160 == V_161 || V_160 == V_162 )
return;
F_52 ( & V_28 -> V_84 ) ;
V_28 -> V_163 |= F_96 ( V_28 ) & V_158 ;
if ( V_28 -> V_152 && V_28 -> V_163 )
F_63 ( V_2 ) ;
F_53 ( & V_28 -> V_84 ) ;
}
void F_99 ( struct V_1 * V_2 ,
unsigned int V_158 , enum V_159 V_160 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
V_28 -> V_163 &= ~ V_158 ;
if ( V_160 == V_161 || V_160 == V_162 )
goto V_89;
if ( ! V_28 -> V_163 && V_28 -> V_152 &&
( V_158 & F_96 ( V_28 ) ) ) {
if ( V_28 -> V_76 )
F_29 ( V_2 ) ;
else
F_94 ( V_28 -> V_4 ) ;
}
V_89:
F_53 ( & V_28 -> V_84 ) ;
}
void F_100 ( struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_166 * V_14 ;
struct V_167 * V_92 ;
bool V_168 = false ;
int V_30 ;
F_52 ( & V_28 -> V_84 ) ;
if ( V_28 -> V_4 &&
! F_101 ( V_165 , & V_28 -> V_4 -> V_5 ) )
goto V_89;
if ( ! F_89 ( V_2 ) )
goto V_89;
F_102 (state, plane, plane_state, i) {
struct V_91 * V_91 =
F_103 ( V_92 ) ;
struct V_132 * V_132 ;
struct V_3 * V_4 = F_104 ( V_92 -> V_4 ) ;
if ( ! V_91 -> V_5 . V_93 )
continue;
if ( F_3 ( V_2 ) && V_4 -> V_73 != V_169 )
continue;
if ( F_6 ( V_2 ) && V_4 -> V_14 != V_170 )
continue;
V_132 = F_105 (
F_101 ( V_165 , & V_4 -> V_5 ) ) ;
V_132 -> V_148 = true ;
V_168 = true ;
break;
}
if ( ! V_168 )
V_28 -> V_142 = L_20 ;
V_89:
F_53 ( & V_28 -> V_84 ) ;
}
void F_106 ( struct V_3 * V_4 ,
struct V_132 * V_133 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
if ( V_28 -> V_152 ) {
F_60 ( V_28 -> V_4 == NULL ) ;
if ( V_28 -> V_4 == V_4 ) {
F_60 ( ! V_133 -> V_148 ) ;
F_60 ( V_28 -> V_76 ) ;
}
goto V_89;
}
if ( ! V_133 -> V_148 )
goto V_89;
F_60 ( V_28 -> V_76 ) ;
F_60 ( V_28 -> V_4 != NULL ) ;
F_84 ( V_4 , V_133 , V_92 ) ;
if ( F_69 ( V_4 ) ) {
V_28 -> V_142 = L_21 ;
goto V_89;
}
F_17 ( L_22 , F_51 ( V_4 -> V_73 ) ) ;
V_28 -> V_142 = L_23 ;
V_28 -> V_152 = true ;
V_28 -> V_4 = V_4 ;
V_89:
F_53 ( & V_28 -> V_84 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
struct V_3 * V_4 = V_28 -> V_4 ;
F_60 ( ! F_61 ( & V_28 -> V_84 ) ) ;
F_60 ( ! V_28 -> V_152 ) ;
F_60 ( V_28 -> V_76 ) ;
F_60 ( V_4 -> V_76 ) ;
F_17 ( L_24 , F_51 ( V_4 -> V_73 ) ) ;
F_77 ( V_2 ) ;
V_28 -> V_152 = false ;
V_28 -> V_4 = NULL ;
}
void F_108 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_59 ( V_4 -> V_5 . V_90 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
if ( V_28 -> V_4 == V_4 )
F_107 ( V_2 ) ;
F_53 ( & V_28 -> V_84 ) ;
F_109 ( & V_28 -> V_79 . V_79 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_52 ( & V_28 -> V_84 ) ;
if ( V_28 -> V_152 )
F_107 ( V_2 ) ;
F_53 ( & V_28 -> V_84 ) ;
F_109 ( & V_28 -> V_79 . V_79 ) ;
}
static void F_111 ( struct V_77 * V_79 )
{
struct V_1 * V_2 =
F_48 ( V_79 , struct V_1 , V_28 . V_171 ) ;
struct V_75 * V_28 = & V_2 -> V_28 ;
F_52 ( & V_28 -> V_84 ) ;
if ( V_28 -> V_141 )
goto V_89;
F_17 ( L_25 ) ;
V_28 -> V_141 = true ;
F_63 ( V_2 ) ;
V_89:
F_53 ( & V_28 -> V_84 ) ;
}
void F_112 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
if ( F_113 ( V_28 -> V_141 ) )
return;
F_62 ( & V_28 -> V_171 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_7 ( V_2 ) )
return;
F_115 (&dev_priv->drm, crtc)
if ( F_116 ( V_4 ) &&
V_4 -> V_5 . V_155 -> V_165 -> V_93 )
V_2 -> V_28 . V_94 |= ( 1 << V_4 -> V_73 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
if ( V_147 . V_148 >= 0 )
return ! ! V_147 . V_148 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_40 ( V_2 ) || F_5 ( V_2 ) >= 9 )
return 1 ;
return 0 ;
}
static bool F_118 ( struct V_1 * V_2 )
{
#ifdef F_119
if ( V_172 &&
( F_66 ( V_2 ) || F_120 ( V_2 ) ) ) {
F_71 ( L_26 ) ;
return true ;
}
#endif
return false ;
}
void F_121 ( struct V_1 * V_2 )
{
struct V_75 * V_28 = & V_2 -> V_28 ;
enum V_73 V_73 ;
F_122 ( & V_28 -> V_79 . V_79 , F_47 ) ;
F_122 ( & V_28 -> V_171 , F_111 ) ;
F_123 ( & V_28 -> V_84 ) ;
V_28 -> V_152 = false ;
V_28 -> V_76 = false ;
V_28 -> V_79 . V_85 = false ;
if ( F_118 ( V_2 ) )
F_124 ( V_2 ) -> V_173 = false ;
V_147 . V_148 = F_117 ( V_2 ) ;
F_17 ( L_27 , V_147 . V_148 ) ;
if ( ! F_2 ( V_2 ) ) {
V_28 -> V_142 = L_28 ;
return;
}
F_125 (dev_priv, pipe) {
V_28 -> V_157 |=
F_126 ( V_73 ) ;
if ( F_3 ( V_2 ) )
break;
}
if ( F_5 ( V_2 ) <= 4 && ! F_43 ( V_2 ) )
F_15 ( V_22 , 500 << V_40 ) ;
if ( F_42 ( V_2 ) )
F_45 ( V_2 ) ;
}
