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
if ( F_27 ( V_27 -> V_19 . V_49 , 0 ) == 2 )
V_47 |= V_50 ;
else
V_47 |= V_51 ;
if ( V_27 -> V_44 -> V_45 ) {
V_47 |= V_52 | V_27 -> V_44 -> V_45 -> V_46 ;
F_15 ( V_53 , V_27 -> V_4 . V_39 ) ;
} else {
F_15 ( V_53 , 0 ) ;
}
F_15 ( V_54 , V_47 | V_55 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_47 ;
V_47 = F_14 ( V_54 ) ;
if ( V_47 & V_55 ) {
V_47 &= ~ V_55 ;
F_15 ( V_54 , V_47 ) ;
}
}
static bool F_29 ( struct V_1 * V_2 )
{
return F_14 ( V_54 ) & V_55 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_15 ( V_56 , V_57 ) ;
F_31 ( V_56 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_27 ;
T_1 V_47 ;
int V_58 = V_2 -> V_28 . V_58 ;
V_47 = F_26 ( V_27 -> V_4 . V_14 ) ;
if ( F_27 ( V_27 -> V_19 . V_49 , 0 ) == 2 )
V_58 ++ ;
switch ( V_58 ) {
case 4 :
case 3 :
V_47 |= V_59 ;
break;
case 2 :
V_47 |= V_50 ;
break;
case 1 :
V_47 |= V_51 ;
break;
}
if ( V_27 -> V_44 -> V_45 ) {
V_47 |= V_52 ;
if ( F_33 ( V_2 ) )
V_47 |= V_27 -> V_44 -> V_45 -> V_46 ;
if ( F_34 ( V_2 ) ) {
F_15 ( V_60 ,
V_61 |
V_27 -> V_44 -> V_45 -> V_46 ) ;
F_15 ( V_62 ,
V_27 -> V_4 . V_39 ) ;
}
} else {
if ( F_34 ( V_2 ) ) {
F_15 ( V_60 , 0 ) ;
F_15 ( V_62 , 0 ) ;
}
}
F_15 ( V_63 , V_27 -> V_4 . V_39 ) ;
F_15 ( V_64 ,
F_35 ( V_27 -> V_44 ) | V_65 ) ;
F_15 ( V_66 , V_47 | V_55 ) ;
F_30 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_47 ;
V_47 = F_14 ( V_66 ) ;
if ( V_47 & V_55 ) {
V_47 &= ~ V_55 ;
F_15 ( V_66 , V_47 ) ;
}
}
static bool F_37 ( struct V_1 * V_2 )
{
return F_14 ( V_66 ) & V_55 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_27 ;
T_1 V_47 ;
int V_58 = V_2 -> V_28 . V_58 ;
V_47 = 0 ;
if ( F_39 ( V_2 ) )
V_47 |= F_40 ( V_27 -> V_4 . V_14 ) ;
if ( F_27 ( V_27 -> V_19 . V_49 , 0 ) == 2 )
V_58 ++ ;
switch ( V_58 ) {
case 4 :
case 3 :
V_47 |= V_59 ;
break;
case 2 :
V_47 |= V_50 ;
break;
case 1 :
V_47 |= V_51 ;
break;
}
if ( V_27 -> V_44 -> V_45 ) {
V_47 |= V_67 ;
F_15 ( V_60 ,
V_61 |
V_27 -> V_44 -> V_45 -> V_46 ) ;
F_15 ( V_62 , V_27 -> V_4 . V_39 ) ;
} else {
F_15 ( V_60 , 0 ) ;
F_15 ( V_62 , 0 ) ;
}
if ( V_2 -> V_28 . V_68 )
V_47 |= V_69 ;
if ( F_39 ( V_2 ) ) {
F_15 ( V_70 ,
F_14 ( V_70 ) |
V_71 ) ;
} else if ( F_4 ( V_2 ) || F_41 ( V_2 ) ) {
F_15 ( F_42 ( V_27 -> V_4 . V_72 ) ,
F_14 ( F_42 ( V_27 -> V_4 . V_72 ) ) |
V_73 ) ;
}
F_15 ( V_66 , V_47 | V_55 ) ;
F_30 ( V_2 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) >= 5 )
return F_37 ( V_2 ) ;
else if ( F_44 ( V_2 ) )
return F_29 ( V_2 ) ;
else
return F_24 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
V_28 -> V_75 = true ;
if ( F_5 ( V_2 ) >= 7 )
F_38 ( V_2 ) ;
else if ( F_5 ( V_2 ) >= 5 )
F_32 ( V_2 ) ;
else if ( F_44 ( V_2 ) )
F_25 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
V_28 -> V_75 = false ;
if ( F_5 ( V_2 ) >= 5 )
F_36 ( V_2 ) ;
else if ( F_44 ( V_2 ) )
F_28 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
bool F_47 ( struct V_1 * V_2 )
{
return V_2 -> V_28 . V_75 ;
}
static void F_48 ( struct V_76 * V_77 )
{
struct V_1 * V_2 =
F_49 ( V_77 , struct V_1 , V_28 . V_78 . V_78 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_79 * V_78 = & V_28 -> V_78 ;
struct V_3 * V_4 = V_28 -> V_4 ;
struct V_80 * V_81 = & V_2 -> V_82 . V_81 [ V_4 -> V_72 ] ;
if ( F_50 ( & V_4 -> V_5 ) ) {
F_51 ( L_2 ,
F_52 ( V_4 -> V_72 ) ) ;
F_53 ( & V_28 -> V_83 ) ;
V_78 -> V_84 = false ;
F_54 ( & V_28 -> V_83 ) ;
return;
}
V_85:
F_55 ( V_81 -> V_86 ,
F_56 ( & V_4 -> V_5 ) != V_78 -> V_87 ,
F_57 ( 50 ) ) ;
F_53 ( & V_28 -> V_83 ) ;
if ( ! V_78 -> V_84 )
goto V_88;
if ( F_56 ( & V_4 -> V_5 ) == V_78 -> V_87 ) {
F_54 ( & V_28 -> V_83 ) ;
goto V_85;
}
F_45 ( V_2 ) ;
V_78 -> V_84 = false ;
V_88:
F_54 ( & V_28 -> V_83 ) ;
F_58 ( & V_4 -> V_5 ) ;
}
static void F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_79 * V_78 = & V_28 -> V_78 ;
F_61 ( ! F_62 ( & V_28 -> V_83 ) ) ;
if ( F_50 ( & V_4 -> V_5 ) ) {
F_51 ( L_2 ,
F_52 ( V_4 -> V_72 ) ) ;
return;
}
V_78 -> V_84 = true ;
V_78 -> V_87 = F_56 ( & V_4 -> V_5 ) ;
F_58 ( & V_4 -> V_5 ) ;
F_63 ( & V_78 -> V_78 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
F_61 ( ! F_62 ( & V_28 -> V_83 ) ) ;
V_28 -> V_78 . V_84 = false ;
if ( V_28 -> V_75 )
F_46 ( V_2 ) ;
}
static bool F_65 ( struct V_3 * V_4 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
enum V_72 V_72 = V_4 -> V_72 ;
if ( ! F_7 ( V_2 ) )
return true ;
if ( V_91 -> V_5 . V_92 )
V_28 -> V_93 |= ( 1 << V_72 ) ;
else
V_28 -> V_93 &= ~ ( 1 << V_72 ) ;
return ( V_28 -> V_93 & ~ ( 1 << V_72 ) ) != 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
int V_96 ,
int V_97 )
{
struct V_98 * V_99 = & V_2 -> V_99 ;
int V_100 = 1 ;
int V_101 ;
T_2 V_102 ;
if ( F_41 ( V_2 ) ||
F_67 ( V_2 ) || F_68 ( V_2 ) )
V_102 = V_99 -> V_103 - 8 * 1024 * 1024 ;
else
V_102 = V_99 -> V_104 ;
V_101 = F_69 ( V_2 , V_95 , V_96 <<= 1 ,
4096 , 0 , V_102 ) ;
if ( V_101 == 0 )
return V_100 ;
V_105:
if ( V_100 > 4 ||
( V_97 == 2 && V_100 == 2 ) )
return 0 ;
V_101 = F_69 ( V_2 , V_95 , V_96 >>= 1 ,
4096 , 0 , V_102 ) ;
if ( V_101 && F_5 ( V_2 ) <= 4 ) {
return 0 ;
} else if ( V_101 ) {
V_100 <<= 1 ;
goto V_105;
} else {
return V_100 ;
}
}
static int F_70 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_94 * V_106 ( V_107 ) ;
int V_96 , V_97 , V_101 ;
F_61 ( F_71 ( & V_28 -> V_108 ) ) ;
V_96 = F_11 ( V_2 , & V_28 -> V_109 ) ;
V_97 = F_27 ( V_28 -> V_109 . V_19 . V_49 , 0 ) ;
V_101 = F_66 ( V_2 , & V_28 -> V_108 ,
V_96 , V_97 ) ;
if ( ! V_101 )
goto V_110;
else if ( V_101 > 1 ) {
F_72 ( L_3 ) ;
}
V_28 -> V_58 = V_101 ;
if ( F_5 ( V_2 ) >= 5 )
F_15 ( V_111 , V_28 -> V_108 . V_112 ) ;
else if ( F_44 ( V_2 ) ) {
F_15 ( V_113 , V_28 -> V_108 . V_112 ) ;
} else {
V_107 = F_73 ( sizeof( * V_107 ) , V_114 ) ;
if ( ! V_107 )
goto V_115;
V_101 = F_74 ( V_2 , V_107 ,
4096 , 4096 ) ;
if ( V_101 )
goto V_115;
V_28 -> V_107 = V_107 ;
F_15 ( V_116 ,
V_2 -> V_117 . V_118 + V_28 -> V_108 . V_112 ) ;
F_15 ( V_119 ,
V_2 -> V_117 . V_118 + V_107 -> V_112 ) ;
}
F_17 ( L_4 ,
V_28 -> V_108 . V_96 , V_28 -> V_58 ) ;
return 0 ;
V_115:
F_75 ( V_107 ) ;
F_76 ( V_2 , & V_28 -> V_108 ) ;
V_110:
F_77 ( L_5 , V_96 ) ;
return - V_120 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( F_71 ( & V_28 -> V_108 ) )
F_76 ( V_2 , & V_28 -> V_108 ) ;
if ( V_28 -> V_107 ) {
F_76 ( V_2 , V_28 -> V_107 ) ;
F_75 ( V_28 -> V_107 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
F_78 ( V_2 ) ;
F_54 ( & V_28 -> V_83 ) ;
}
static bool F_80 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
F_61 ( V_20 < 512 ) ;
F_61 ( ( V_20 & ( 64 - 1 ) ) != 0 ) ;
if ( F_19 ( V_2 ) || F_81 ( V_2 ) )
return V_20 == 4096 || V_20 == 8192 ;
if ( F_21 ( V_2 ) && ! F_82 ( V_2 ) && V_20 < 2048 )
return false ;
if ( V_20 > 16384 )
return false ;
return true ;
}
static bool F_83 ( struct V_1 * V_2 ,
T_3 V_49 )
{
switch ( V_49 ) {
case V_121 :
case V_122 :
return true ;
case V_123 :
case V_124 :
if ( F_19 ( V_2 ) )
return false ;
if ( F_82 ( V_2 ) )
return false ;
return true ;
default:
return false ;
}
}
static bool F_84 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
unsigned int V_125 , V_126 , V_127 , V_128 ;
if ( F_5 ( V_2 ) >= 8 || F_4 ( V_2 ) ) {
V_127 = 4096 ;
V_128 = 4096 ;
} else if ( F_82 ( V_2 ) || F_5 ( V_2 ) >= 5 ) {
V_127 = 4096 ;
V_128 = 2048 ;
} else {
V_127 = 2048 ;
V_128 = 1536 ;
}
F_9 ( & V_28 -> V_109 , & V_125 ,
& V_126 ) ;
V_125 += V_4 -> V_129 ;
V_126 += V_4 -> V_7 ;
return V_125 <= V_127 && V_126 <= V_128 ;
}
static void F_85 ( struct V_3 * V_4 ,
struct V_130 * V_131 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_8 * V_9 = & V_28 -> V_109 ;
struct V_132 * V_19 = V_91 -> V_5 . V_19 ;
V_9 -> V_44 = NULL ;
V_9 -> V_4 . V_133 = V_131 -> V_5 . V_134 . V_135 ;
if ( F_4 ( V_2 ) || F_41 ( V_2 ) )
V_9 -> V_4 . V_136 =
F_86 ( V_131 ) ;
V_9 -> V_14 . V_15 = V_91 -> V_5 . V_15 ;
V_9 -> V_14 . V_17 = F_87 ( & V_91 -> V_5 . V_137 ) >> 16 ;
V_9 -> V_14 . V_16 = F_88 ( & V_91 -> V_5 . V_137 ) >> 16 ;
V_9 -> V_14 . V_92 = V_91 -> V_5 . V_92 ;
if ( ! V_9 -> V_14 . V_92 )
return;
V_9 -> V_19 . V_49 = V_19 -> V_49 ;
V_9 -> V_19 . V_20 = V_19 -> V_138 [ 0 ] ;
V_9 -> V_44 = V_91 -> V_44 ;
}
static bool F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_8 * V_9 = & V_28 -> V_109 ;
if ( V_28 -> V_139 ) {
V_28 -> V_140 = L_6 ;
return false ;
}
if ( ! V_9 -> V_44 ) {
V_28 -> V_140 = L_7 ;
return false ;
}
if ( ( V_9 -> V_4 . V_133 & V_141 ) ||
( V_9 -> V_4 . V_133 & V_142 ) ) {
V_28 -> V_140 = L_8 ;
return false ;
}
if ( ! F_84 ( V_4 ) ) {
V_28 -> V_140 = L_9 ;
return false ;
}
if ( ! V_9 -> V_44 -> V_45 ) {
V_28 -> V_140 = L_10 ;
return false ;
}
if ( F_5 ( V_2 ) <= 4 && ! F_82 ( V_2 ) &&
V_9 -> V_14 . V_15 != V_143 ) {
V_28 -> V_140 = L_11 ;
return false ;
}
if ( ! F_80 ( V_2 , V_9 -> V_19 . V_20 ) ) {
V_28 -> V_140 = L_12 ;
return false ;
}
if ( ! F_83 ( V_2 , V_9 -> V_19 . V_49 ) ) {
V_28 -> V_140 = L_13 ;
return false ;
}
if ( ( F_4 ( V_2 ) || F_41 ( V_2 ) ) &&
V_9 -> V_4 . V_136 >= V_2 -> V_144 * 95 / 100 ) {
V_28 -> V_140 = L_14 ;
return false ;
}
if ( F_11 ( V_2 , & V_28 -> V_109 ) >
V_28 -> V_108 . V_96 * V_28 -> V_58 ) {
V_28 -> V_140 = L_15 ;
return false ;
}
return true ;
}
static bool F_90 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( F_91 ( V_2 ) ) {
V_28 -> V_140 = L_16 ;
return false ;
}
if ( ! V_145 . V_146 ) {
V_28 -> V_140 = L_17 ;
return false ;
}
if ( V_28 -> V_139 ) {
V_28 -> V_140 = L_6 ;
return false ;
}
return true ;
}
static void F_92 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_8 * V_9 = & V_28 -> V_109 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_44 = V_9 -> V_44 ;
V_27 -> V_4 . V_72 = V_4 -> V_72 ;
V_27 -> V_4 . V_14 = V_4 -> V_14 ;
V_27 -> V_4 . V_39 = F_8 ( V_4 ) ;
V_27 -> V_19 . V_49 = V_9 -> V_19 . V_49 ;
V_27 -> V_19 . V_20 = V_9 -> V_19 . V_20 ;
V_27 -> V_31 = F_11 ( V_2 , V_9 ) ;
}
static bool F_93 ( struct V_26 * V_147 ,
struct V_26 * V_148 )
{
return memcmp ( V_147 , V_148 , sizeof( * V_147 ) ) == 0 ;
}
void F_94 ( struct V_3 * V_4 ,
struct V_130 * V_131 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
if ( ! F_65 ( V_4 , V_91 ) ) {
V_28 -> V_140 = L_18 ;
goto V_149;
}
if ( ! V_28 -> V_150 || V_28 -> V_4 != V_4 )
goto V_151;
F_85 ( V_4 , V_131 , V_91 ) ;
V_149:
F_64 ( V_2 ) ;
V_151:
F_54 ( & V_28 -> V_83 ) ;
}
static void F_95 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_26 V_152 ;
F_61 ( ! F_62 ( & V_28 -> V_83 ) ) ;
if ( ! V_28 -> V_150 || V_28 -> V_4 != V_4 )
return;
if ( ! F_89 ( V_4 ) ) {
F_61 ( V_28 -> V_75 ) ;
return;
}
V_152 = V_28 -> V_27 ;
F_92 ( V_4 , & V_28 -> V_27 ) ;
if ( V_28 -> V_75 &&
F_93 ( & V_152 , & V_28 -> V_27 ) )
return;
F_64 ( V_2 ) ;
F_59 ( V_4 ) ;
V_28 -> V_140 = L_19 ;
}
void F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
F_95 ( V_4 ) ;
F_54 ( & V_28 -> V_83 ) ;
}
static unsigned int F_97 ( struct V_74 * V_28 )
{
if ( V_28 -> V_150 )
return F_98 ( V_28 -> V_4 -> V_5 . V_153 ) -> V_154 ;
else
return V_28 -> V_155 ;
}
void F_99 ( struct V_1 * V_2 ,
unsigned int V_156 ,
enum V_157 V_158 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
if ( V_158 == V_159 || V_158 == V_160 )
return;
F_53 ( & V_28 -> V_83 ) ;
V_28 -> V_161 |= F_97 ( V_28 ) & V_156 ;
if ( V_28 -> V_150 && V_28 -> V_161 )
F_64 ( V_2 ) ;
F_54 ( & V_28 -> V_83 ) ;
}
void F_100 ( struct V_1 * V_2 ,
unsigned int V_156 , enum V_157 V_158 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
V_28 -> V_161 &= ~ V_156 ;
if ( V_158 == V_159 || V_158 == V_160 )
goto V_88;
if ( ! V_28 -> V_161 && V_28 -> V_150 &&
( V_156 & F_97 ( V_28 ) ) ) {
if ( V_28 -> V_75 )
F_30 ( V_2 ) ;
else
F_95 ( V_28 -> V_4 ) ;
}
V_88:
F_54 ( & V_28 -> V_83 ) ;
}
void F_101 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_164 * V_14 ;
struct V_165 * V_91 ;
bool V_166 = false ;
int V_30 ;
F_53 ( & V_28 -> V_83 ) ;
if ( V_28 -> V_4 &&
! F_102 ( V_163 , & V_28 -> V_4 -> V_5 ) )
goto V_88;
if ( ! F_90 ( V_2 ) )
goto V_88;
F_103 (state, plane, plane_state, i) {
struct V_90 * V_90 =
F_104 ( V_91 ) ;
struct V_130 * V_130 ;
struct V_3 * V_4 = F_105 ( V_91 -> V_4 ) ;
if ( ! V_90 -> V_5 . V_92 )
continue;
if ( F_3 ( V_2 ) && V_4 -> V_72 != V_167 )
continue;
if ( F_6 ( V_2 ) && V_4 -> V_14 != V_168 )
continue;
V_130 = F_106 (
F_102 ( V_163 , & V_4 -> V_5 ) ) ;
V_130 -> V_146 = true ;
V_166 = true ;
break;
}
if ( ! V_166 )
V_28 -> V_140 = L_20 ;
V_88:
F_54 ( & V_28 -> V_83 ) ;
}
void F_107 ( struct V_3 * V_4 ,
struct V_130 * V_131 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
if ( V_28 -> V_150 ) {
F_61 ( V_28 -> V_4 == NULL ) ;
if ( V_28 -> V_4 == V_4 ) {
F_61 ( ! V_131 -> V_146 ) ;
F_61 ( V_28 -> V_75 ) ;
}
goto V_88;
}
if ( ! V_131 -> V_146 )
goto V_88;
F_61 ( V_28 -> V_75 ) ;
F_61 ( V_28 -> V_4 != NULL ) ;
F_85 ( V_4 , V_131 , V_91 ) ;
if ( F_70 ( V_4 ) ) {
V_28 -> V_140 = L_21 ;
goto V_88;
}
F_17 ( L_22 , F_52 ( V_4 -> V_72 ) ) ;
V_28 -> V_140 = L_23 ;
V_28 -> V_150 = true ;
V_28 -> V_4 = V_4 ;
V_88:
F_54 ( & V_28 -> V_83 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
struct V_3 * V_4 = V_28 -> V_4 ;
F_61 ( ! F_62 ( & V_28 -> V_83 ) ) ;
F_61 ( ! V_28 -> V_150 ) ;
F_61 ( V_28 -> V_75 ) ;
F_61 ( V_4 -> V_75 ) ;
F_17 ( L_24 , F_52 ( V_4 -> V_72 ) ) ;
F_78 ( V_2 ) ;
V_28 -> V_150 = false ;
V_28 -> V_4 = NULL ;
}
void F_109 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_60 ( V_4 -> V_5 . V_89 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
if ( V_28 -> V_4 == V_4 )
F_108 ( V_2 ) ;
F_54 ( & V_28 -> V_83 ) ;
F_110 ( & V_28 -> V_78 . V_78 ) ;
}
void F_111 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
F_53 ( & V_28 -> V_83 ) ;
if ( V_28 -> V_150 )
F_108 ( V_2 ) ;
F_54 ( & V_28 -> V_83 ) ;
F_110 ( & V_28 -> V_78 . V_78 ) ;
}
static void F_112 ( struct V_76 * V_78 )
{
struct V_1 * V_2 =
F_49 ( V_78 , struct V_1 , V_28 . V_169 ) ;
struct V_74 * V_28 = & V_2 -> V_28 ;
F_53 ( & V_28 -> V_83 ) ;
if ( V_28 -> V_139 )
goto V_88;
F_17 ( L_25 ) ;
V_28 -> V_139 = true ;
F_64 ( V_2 ) ;
V_88:
F_54 ( & V_28 -> V_83 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
if ( ! F_1 ( V_2 ) )
return;
if ( F_114 ( V_28 -> V_139 ) )
return;
F_63 ( & V_28 -> V_169 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_7 ( V_2 ) )
return;
F_116 (&dev_priv->drm, crtc)
if ( F_117 ( V_4 ) &&
F_104 ( V_4 -> V_5 . V_153 -> V_163 ) -> V_5 . V_92 )
V_2 -> V_28 . V_93 |= ( 1 << V_4 -> V_72 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
if ( V_145 . V_146 >= 0 )
return ! ! V_145 . V_146 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_41 ( V_2 ) )
return 1 ;
return 0 ;
}
static bool F_119 ( struct V_1 * V_2 )
{
#ifdef F_120
if ( V_170 &&
( F_67 ( V_2 ) || F_121 ( V_2 ) ) ) {
F_72 ( L_26 ) ;
return true ;
}
#endif
return false ;
}
void F_122 ( struct V_1 * V_2 )
{
struct V_74 * V_28 = & V_2 -> V_28 ;
enum V_72 V_72 ;
F_123 ( & V_28 -> V_78 . V_78 , F_48 ) ;
F_123 ( & V_28 -> V_169 , F_112 ) ;
F_124 ( & V_28 -> V_83 ) ;
V_28 -> V_150 = false ;
V_28 -> V_75 = false ;
V_28 -> V_78 . V_84 = false ;
if ( F_119 ( V_2 ) )
F_125 ( V_2 ) -> V_171 = false ;
V_145 . V_146 = F_118 ( V_2 ) ;
F_17 ( L_27 , V_145 . V_146 ) ;
if ( ! F_2 ( V_2 ) ) {
V_28 -> V_140 = L_28 ;
return;
}
F_126 (dev_priv, pipe) {
V_28 -> V_155 |=
F_127 ( V_72 ) ;
if ( F_3 ( V_2 ) )
break;
}
if ( F_5 ( V_2 ) <= 4 && ! F_44 ( V_2 ) )
F_15 ( V_22 , 500 << V_40 ) ;
if ( F_43 ( V_2 ) )
F_46 ( V_2 ) ;
}
