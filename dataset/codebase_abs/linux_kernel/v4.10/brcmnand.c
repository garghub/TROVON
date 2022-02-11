static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
static const unsigned int V_6 [] = { 8 , 16 , 128 , 256 , 512 , 1024 , 2048 , 0 } ;
static const unsigned int V_7 [] = { 16 , 128 , 8 , 512 , 256 , 1024 , 2048 , 0 } ;
static const unsigned int V_8 [] = { 512 , 2048 , 4096 , 8192 , 0 } ;
V_2 -> V_9 = F_1 ( V_2 , 0 ) & 0xffff ;
if ( V_2 -> V_9 < 0x0400 ) {
F_6 ( V_2 -> V_10 , L_1 ,
V_2 -> V_9 ) ;
return - V_11 ;
}
if ( V_2 -> V_9 >= 0x0702 )
V_2 -> V_12 = V_13 ;
else if ( V_2 -> V_9 >= 0x0701 )
V_2 -> V_12 = V_14 ;
else if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_12 = V_15 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_12 = V_16 ;
else if ( V_2 -> V_9 >= 0x0400 )
V_2 -> V_12 = V_17 ;
if ( V_2 -> V_9 >= 0x0701 )
V_2 -> V_18 = 0x14 ;
else
V_2 -> V_18 = 0x10 ;
if ( V_2 -> V_9 >= 0x0701 ) {
V_2 -> V_19 = V_20 ;
} else {
V_2 -> V_19 = V_21 ;
if ( V_2 -> V_9 <= 0x0500 )
V_2 -> V_22 = V_23 ;
}
if ( V_2 -> V_9 >= 0x0701 ) {
V_2 -> V_24 = 16 * 1024 ;
V_2 -> V_25 = 2 * 1024 * 1024 ;
} else {
V_2 -> V_8 = V_8 ;
if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_26 = V_6 ;
else
V_2 -> V_26 = V_7 ;
if ( V_2 -> V_9 < 0x0400 ) {
V_2 -> V_24 = 4096 ;
V_2 -> V_25 = 512 * 1024 ;
}
}
if ( V_2 -> V_9 >= 0x0702 )
V_2 -> V_27 = 128 ;
else if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_27 = 64 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_27 = 32 ;
else
V_2 -> V_27 = 16 ;
if ( V_2 -> V_9 >= 0x0600 && V_2 -> V_9 != 0x0601 )
V_2 -> V_28 |= V_29 ;
if ( V_2 -> V_9 >= 0x0700 )
V_2 -> V_28 |= V_30 ;
if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_28 |= V_31 ;
if ( V_2 -> V_9 >= 0x0700 )
V_2 -> V_28 |= V_32 ;
else if ( F_7 ( V_2 -> V_10 -> V_33 , L_2 ) )
V_2 -> V_28 |= V_32 ;
return 0 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
T_2 V_3 = V_2 -> V_12 [ V_35 ] ;
if ( V_3 )
return F_1 ( V_2 , V_3 ) ;
else
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 ,
enum V_34 V_35 , T_1 V_5 )
{
T_2 V_3 = V_2 -> V_12 [ V_35 ] ;
if ( V_3 )
F_3 ( V_2 , V_3 , V_5 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
enum V_34 V_35 , T_1 V_36 , unsigned
int V_37 , T_1 V_5 )
{
T_1 V_38 = F_8 ( V_2 , V_35 ) ;
V_38 &= ~ V_36 ;
V_38 |= V_5 << V_37 ;
F_9 ( V_2 , V_35 , V_38 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , int V_39 )
{
return F_12 ( V_2 -> V_40 + V_39 * 4 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
int V_39 , T_1 V_5 )
{
F_14 ( V_5 , V_2 -> V_40 + V_39 * 4 ) ;
}
static inline T_2 F_15 ( struct V_1 * V_2 , int V_41 ,
enum V_42 V_35 )
{
T_2 V_43 = V_2 -> V_12 [ V_44 ] ;
T_2 V_45 = V_2 -> V_12 [ V_46 ] ;
T_3 V_47 ;
if ( V_41 == 0 && V_2 -> V_22 )
V_47 = V_2 -> V_22 [ V_35 ] ;
else
V_47 = V_2 -> V_19 [ V_35 ] ;
if ( V_41 && V_45 )
return V_45 + ( V_41 - 1 ) * V_2 -> V_18 + V_47 ;
return V_43 + V_41 * V_2 -> V_18 + V_47 ;
}
static inline T_1 F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 < 0x0600 )
return 1 ;
return F_8 ( V_2 , V_48 ) ;
}
static void F_17 ( struct V_49 * V_50 , T_3 V_5 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned int V_37 = 0 , V_51 ;
enum V_34 V_35 = V_52 ;
int V_41 = V_50 -> V_41 ;
if ( V_2 -> V_9 >= 0x0702 )
V_51 = 7 ;
else if ( V_2 -> V_9 >= 0x0600 )
V_51 = 6 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_51 = 5 ;
else
V_51 = 4 ;
if ( V_2 -> V_9 >= 0x0702 ) {
if ( V_41 >= 4 )
V_35 = V_53 ;
V_37 = ( V_41 % 4 ) * V_51 ;
} else if ( V_2 -> V_9 >= 0x0600 ) {
if ( V_41 >= 5 )
V_35 = V_53 ;
V_37 = ( V_41 % 5 ) * V_51 ;
}
F_10 ( V_2 , V_35 , ( V_51 - 1 ) << V_37 , V_37 , V_5 ) ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 < 0x0602 )
return 24 ;
return 0 ;
}
static inline T_1 F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 >= 0x0702 )
return F_20 ( 7 , 0 ) ;
else if ( V_2 -> V_9 >= 0x0600 )
return F_20 ( 6 , 0 ) ;
else
return F_20 ( 5 , 0 ) ;
}
static inline T_1 F_21 ( struct V_1 * V_2 )
{
T_1 V_36 = ( V_2 -> V_9 >= 0x0600 ) ? 0x1f : 0x0f ;
V_36 <<= V_54 ;
if ( V_2 -> V_9 >= 0x0702 )
V_36 |= 0x7 << V_55 ;
return V_36 ;
}
static void F_22 ( struct V_49 * V_50 , int V_56 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_2 V_3 = F_15 ( V_2 , V_50 -> V_41 , V_57 ) ;
T_1 V_58 = F_1 ( V_2 , V_3 ) ;
T_1 V_59 = V_60 | V_61 ;
if ( V_56 ) {
V_58 |= V_59 ;
V_58 |= V_50 -> V_62 . V_63
<< V_54 ;
} else {
V_58 &= ~ V_59 ;
V_58 &= ~ F_21 ( V_2 ) ;
}
F_3 ( V_2 , V_3 , V_58 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 >= 0x0702 )
return 9 ;
else if ( V_2 -> V_9 >= 0x0600 )
return 7 ;
else if ( V_2 -> V_9 >= 0x0500 )
return 6 ;
else
return - 1 ;
}
static int F_24 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
int V_37 = F_23 ( V_2 ) ;
T_2 V_64 = F_15 ( V_2 , V_50 -> V_41 ,
V_57 ) ;
if ( V_37 < 0 )
return 0 ;
return ( F_1 ( V_2 , V_64 ) >> V_37 ) & 0x1 ;
}
static void F_25 ( struct V_49 * V_50 , int V_5 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
int V_37 = F_23 ( V_2 ) ;
T_2 V_64 = F_15 ( V_2 , V_50 -> V_41 ,
V_57 ) ;
T_1 V_38 ;
if ( V_37 < 0 )
return;
V_38 = F_1 ( V_2 , V_64 ) ;
V_38 &= ~ ( 1 << V_37 ) ;
V_38 |= ( ! ! V_5 ) << V_37 ;
F_3 ( V_2 , V_64 , V_38 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , bool V_56 )
{
T_1 V_5 = V_56 ? V_65 : 0 ;
F_10 ( V_2 , V_66 , V_65 , 0 , V_5 ) ;
}
static inline bool F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_67 ;
}
static inline bool F_28 ( const void * V_68 )
{
return V_68 && ! F_29 ( V_68 ) &&
F_30 ( F_31 ( ( V_69 ) V_68 , 4 ) ) ;
}
static inline void F_32 ( struct V_1 * V_2 , T_3 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_67 + V_3 ) ;
}
static inline T_1 F_33 ( struct V_1 * V_2 , T_3 V_3 )
{
return F_2 ( V_2 -> V_67 + V_3 ) ;
}
static inline bool F_34 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
if ( V_2 -> V_9 <= 0x0701 )
return V_71 -> V_72 == 0 && V_71 -> V_73 == 16 &&
V_71 -> V_63 == 15 ;
else
return V_71 -> V_72 == 0 && ( ( V_71 -> V_73 == 16 &&
V_71 -> V_63 == 15 ) ||
( V_71 -> V_73 == 28 && V_71 -> V_63 == 16 ) ) ;
}
static int F_35 ( struct V_74 * V_75 , int V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_70 * V_71 = & V_50 -> V_62 ;
int V_81 = V_71 -> V_73 << V_71 -> V_72 ;
int V_82 = V_71 -> V_83 / ( 512 << V_71 -> V_72 ) ;
if ( V_76 >= V_82 )
return - V_84 ;
V_78 -> V_85 = ( V_76 * V_81 ) + 6 ;
V_78 -> V_86 = 3 ;
return 0 ;
}
static int F_38 ( struct V_74 * V_75 , int V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_70 * V_71 = & V_50 -> V_62 ;
int V_81 = V_71 -> V_73 << V_71 -> V_72 ;
int V_82 = V_71 -> V_83 / ( 512 << V_71 -> V_72 ) ;
if ( V_76 >= V_82 * 2 )
return - V_84 ;
V_78 -> V_85 = ( V_76 / 2 ) * V_81 ;
if ( V_76 & 1 ) {
V_78 -> V_85 += 9 ;
V_78 -> V_86 = 7 ;
} else {
V_78 -> V_86 = 6 ;
if ( ! V_76 ) {
if ( V_71 -> V_83 > 512 )
V_78 -> V_85 ++ ;
V_78 -> V_86 -- ;
}
}
return 0 ;
}
static int F_39 ( struct V_74 * V_75 , int V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_70 * V_71 = & V_50 -> V_62 ;
int V_81 = V_71 -> V_73 << V_71 -> V_72 ;
int V_82 = V_71 -> V_83 / ( 512 << V_71 -> V_72 ) ;
if ( V_76 >= V_82 )
return - V_84 ;
V_78 -> V_85 = ( V_76 * ( V_81 + 1 ) ) - V_80 -> V_87 . V_88 ;
V_78 -> V_86 = V_80 -> V_87 . V_88 ;
return 0 ;
}
static int F_40 ( struct V_74 * V_75 , int V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_70 * V_71 = & V_50 -> V_62 ;
int V_81 = V_71 -> V_73 << V_71 -> V_72 ;
int V_82 = V_71 -> V_83 / ( 512 << V_71 -> V_72 ) ;
if ( V_76 >= V_82 )
return - V_84 ;
if ( V_81 <= V_80 -> V_87 . V_88 )
return 0 ;
V_78 -> V_85 = V_76 * V_81 ;
V_78 -> V_86 = V_81 - V_80 -> V_87 . V_88 ;
if ( ! V_76 ) {
V_78 -> V_85 ++ ;
V_78 -> V_86 -- ;
}
return 0 ;
}
static int F_41 ( struct V_74 * V_75 , int V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_70 * V_71 = & V_50 -> V_62 ;
int V_81 = V_71 -> V_73 << V_71 -> V_72 ;
if ( V_76 > 1 || V_81 - V_80 -> V_87 . V_88 < 6 ||
( V_76 && V_81 - V_80 -> V_87 . V_88 == 6 ) )
return - V_84 ;
if ( ! V_76 ) {
V_78 -> V_85 = 0 ;
V_78 -> V_86 = 5 ;
} else {
V_78 -> V_85 = 6 ;
V_78 -> V_86 = V_81 - V_80 -> V_87 . V_88 - 6 ;
}
return 0 ;
}
static int F_42 ( struct V_49 * V_50 )
{
struct V_70 * V_89 = & V_50 -> V_62 ;
struct V_74 * V_75 = F_43 ( & V_50 -> V_80 ) ;
struct V_90 * V_87 = & V_50 -> V_80 . V_87 ;
unsigned int V_63 = V_89 -> V_63 ;
int V_81 = V_89 -> V_73 << V_89 -> V_72 ;
int V_82 = V_89 -> V_83 / ( 512 << V_89 -> V_72 ) ;
if ( V_89 -> V_72 )
V_63 <<= 1 ;
if ( F_34 ( V_50 -> V_2 , V_89 ) ) {
V_87 -> V_88 = 3 * V_82 ;
F_44 ( V_75 , & V_91 ) ;
return 0 ;
}
V_87 -> V_88 = F_45 ( V_63 * 14 , 8 ) ;
if ( V_89 -> V_83 == 512 )
F_44 ( V_75 , & V_92 ) ;
else
F_44 ( V_75 , & V_93 ) ;
if ( V_87 -> V_88 >= V_81 ) {
F_6 ( & V_50 -> V_94 -> V_10 ,
L_3 ,
V_87 -> V_88 , V_81 ) ;
return - V_95 ;
}
return 0 ;
}
static void F_46 ( struct V_74 * V_75 , int V_96 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
if ( ( V_2 -> V_28 & V_32 ) && V_97 == 1 ) {
static int V_98 = - 1 ;
if ( V_98 != V_96 ) {
F_47 ( V_2 -> V_10 , L_4 , V_96 ? L_5 : L_6 ) ;
V_98 = V_96 ;
}
F_26 ( V_2 , V_96 ) ;
}
}
static inline T_3 F_48 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_99 , V_100 , V_101 ;
V_99 = V_2 -> V_12 [ V_102 ] ;
V_100 = V_2 -> V_12 [ V_103 ] ;
if ( V_3 >= V_2 -> V_27 )
return 0x77 ;
if ( V_3 >= 16 && V_100 )
V_101 = V_100 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_101 = V_99 + ( V_3 & ~ 0x03 ) ;
return F_1 ( V_2 , V_101 ) >> ( 24 - ( ( V_3 & 0x03 ) << 3 ) ) ;
}
static inline void F_49 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_104 )
{
T_2 V_99 , V_100 , V_101 ;
V_99 = V_2 -> V_12 [ V_105 ] ;
V_100 = V_2 -> V_12 [ V_106 ] ;
if ( V_3 >= V_2 -> V_27 )
return;
if ( V_3 >= 16 && V_100 )
V_101 = V_100 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_101 = V_99 + ( V_3 & ~ 0x03 ) ;
F_3 ( V_2 , V_101 , V_104 ) ;
}
static int F_50 ( struct V_1 * V_2 , int V_107 , T_3 * V_108 ,
int V_81 , int V_109 )
{
int V_110 = V_81 << V_109 ;
int V_111 ;
if ( V_109 && ( V_107 & 0x01 ) )
V_110 = F_51 ( 0 , V_110 - ( int ) V_2 -> V_27 ) ;
V_110 = F_52 ( int , V_110 , V_2 -> V_27 ) ;
for ( V_111 = 0 ; V_111 < V_110 ; V_111 ++ )
V_108 [ V_111 ] = F_48 ( V_2 , V_111 ) ;
return V_110 ;
}
static int F_53 ( struct V_1 * V_2 , int V_107 ,
const T_3 * V_108 , int V_81 , int V_109 )
{
int V_110 = V_81 << V_109 ;
int V_111 ;
if ( V_109 && ( V_107 & 0x01 ) )
V_110 = F_51 ( 0 , V_110 - ( int ) V_2 -> V_27 ) ;
V_110 = F_52 ( int , V_110 , V_2 -> V_27 ) ;
for ( V_111 = 0 ; V_111 < V_110 ; V_111 += 4 )
F_49 ( V_2 , V_111 ,
( V_108 [ V_111 + 0 ] << 24 ) |
( V_108 [ V_111 + 1 ] << 16 ) |
( V_108 [ V_111 + 2 ] << 8 ) |
( V_108 [ V_111 + 3 ] << 0 ) ) ;
return V_110 ;
}
static T_4 F_54 ( int V_112 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
if ( V_2 -> V_113 )
return V_114 ;
F_55 ( & V_2 -> V_115 ) ;
return V_114 ;
}
static T_4 F_56 ( int V_112 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
if ( V_2 -> V_116 -> V_117 ( V_2 -> V_116 ) )
return F_54 ( V_112 , V_104 ) ;
return V_118 ;
}
static T_4 F_57 ( int V_112 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
F_55 ( & V_2 -> V_119 ) ;
return V_114 ;
}
static void F_58 ( struct V_49 * V_50 , int V_120 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_1 V_121 ;
F_47 ( V_2 -> V_10 , L_7 , V_120 ,
F_8 ( V_2 , V_122 ) ) ;
F_59 ( V_2 -> V_123 != 0 ) ;
V_2 -> V_123 = V_120 ;
V_121 = F_8 ( V_2 , V_124 ) ;
F_60 ( ! ( V_121 & V_125 ) ) ;
F_61 () ;
F_9 ( V_2 , V_126 ,
V_120 << F_18 ( V_2 ) ) ;
}
static void F_62 ( struct V_74 * V_75 , int V_127 ,
unsigned int V_2 )
{
}
static int F_63 ( struct V_74 * V_75 , struct V_79 * V_128 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned long V_129 = F_64 ( 100 ) ;
F_47 ( V_2 -> V_10 , L_8 , V_2 -> V_123 ) ;
if ( V_2 -> V_123 &&
F_65 ( & V_2 -> V_115 , V_129 ) <= 0 ) {
T_1 V_120 = F_8 ( V_2 , V_126 )
>> F_18 ( V_2 ) ;
F_66 ( V_2 -> V_10 ,
L_9 , V_120 ) ;
F_66 ( V_2 -> V_10 , L_10 ,
F_8 ( V_2 , V_124 ) ) ;
}
V_2 -> V_123 = 0 ;
return F_8 ( V_2 , V_124 ) &
V_130 ;
}
static int F_67 ( struct V_49 * V_50 ,
enum V_131 type , T_1 V_104 ,
bool V_132 )
{
struct V_74 * V_75 = F_43 ( & V_50 -> V_80 ) ;
struct V_79 * V_80 = & V_50 -> V_80 ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_1 V_38 ;
V_38 = V_104 & V_133 ;
switch ( type ) {
case V_134 :
V_38 |= V_135 | V_136 ;
break;
case V_137 :
V_38 |= V_135 | V_138 ;
break;
case V_139 :
V_38 |= V_135 ;
break;
case V_140 :
V_38 |= V_141 ;
break;
}
if ( V_132 )
V_38 |= V_142 ;
F_47 ( V_2 -> V_10 , L_11 , V_38 ) ;
F_9 ( V_2 , V_143 , V_38 ) ;
( void ) F_8 ( V_2 , V_143 ) ;
F_58 ( V_50 , V_144 ) ;
return F_63 ( V_75 , V_80 ) ;
}
static void F_68 ( struct V_74 * V_75 , unsigned V_145 ,
int V_146 , int V_147 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_5 V_148 = ( T_5 ) V_147 << V_80 -> V_149 ;
int V_150 = 0 ;
if ( V_145 == V_151 || V_145 == V_152 ||
V_145 == V_153 )
V_148 = ( T_5 ) V_146 ;
else if ( V_147 < 0 )
V_148 = 0 ;
F_47 ( V_2 -> V_10 , L_12 , V_145 ,
( unsigned long long ) V_148 ) ;
V_50 -> V_154 = V_145 ;
V_50 -> V_155 = 0 ;
V_50 -> V_156 = V_148 ;
switch ( V_145 ) {
case V_157 :
V_150 = V_158 ;
break;
case V_159 :
V_150 = V_160 ;
break;
case V_151 :
V_150 = V_161 ;
break;
case V_162 :
V_150 = V_163 ;
break;
case V_164 :
V_150 = V_165 ;
F_46 ( V_75 , 0 ) ;
break;
case V_152 :
V_150 = V_166 ;
break;
case V_167 :
case V_168 :
F_67 ( V_50 , V_134 , V_145 , false ) ;
F_67 ( V_50 , V_137 , V_146 , false ) ;
break;
case V_153 :
V_150 = V_169 ;
V_148 &= ~ ( ( T_5 ) ( V_170 - 1 ) ) ;
if ( F_24 ( V_50 ) ) {
V_50 -> V_62 . V_72 =
F_24 ( V_50 ) ;
F_25 ( V_50 , 0 ) ;
}
break;
}
if ( ! V_150 )
return;
F_9 ( V_2 , V_171 ,
( V_50 -> V_41 << 16 ) | ( ( V_148 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_171 ) ;
F_9 ( V_2 , V_122 , F_69 ( V_148 ) ) ;
( void ) F_8 ( V_2 , V_122 ) ;
F_58 ( V_50 , V_150 ) ;
F_63 ( V_75 , V_80 ) ;
if ( V_150 == V_166 ||
V_150 == V_169 ) {
T_1 * V_172 = ( T_1 * ) V_2 -> V_172 ;
int V_107 ;
F_70 ( V_2 -> V_116 , true ) ;
for ( V_107 = 0 ; V_107 < V_173 ; V_107 ++ )
V_172 [ V_107 ] = F_71 ( F_11 ( V_2 , V_107 ) ) ;
F_72 ( V_2 -> V_116 , true ) ;
if ( V_50 -> V_62 . V_72 )
F_25 ( V_50 ,
V_50 -> V_62 . V_72 ) ;
}
if ( V_145 == V_164 )
F_46 ( V_75 , 1 ) ;
}
static T_6 F_73 ( struct V_74 * V_75 )
{
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_6 V_174 = 0 ;
int V_148 , V_3 ;
switch ( V_50 -> V_154 ) {
case V_151 :
if ( V_50 -> V_155 < 4 )
V_174 = F_8 ( V_2 , V_175 ) >>
( 24 - ( V_50 -> V_155 << 3 ) ) ;
else if ( V_50 -> V_155 < 8 )
V_174 = F_8 ( V_2 , V_176 ) >>
( 56 - ( V_50 -> V_155 << 3 ) ) ;
break;
case V_162 :
V_174 = F_48 ( V_2 , V_50 -> V_155 ) ;
break;
case V_159 :
V_174 = F_8 ( V_2 , V_124 ) &
V_130 ;
if ( V_97 )
V_174 |= V_177 ;
break;
case V_152 :
case V_153 :
V_148 = V_50 -> V_156 + V_50 -> V_155 ;
V_3 = V_148 & ( V_170 - 1 ) ;
if ( V_50 -> V_155 > 0 && V_3 == 0 )
V_80 -> V_178 ( V_75 , V_153 , V_148 , - 1 ) ;
V_174 = V_2 -> V_172 [ V_3 ] ;
break;
case V_168 :
if ( V_50 -> V_155 >= V_179 ) {
V_174 = 0 ;
} else {
bool V_180 = V_50 -> V_155 ==
V_179 - 1 ;
F_67 ( V_50 , V_140 , 0 , V_180 ) ;
V_174 = F_8 ( V_2 , V_181 ) & 0xff ;
}
}
F_47 ( V_2 -> V_10 , L_13 , V_174 ) ;
V_50 -> V_155 ++ ;
return V_174 ;
}
static void F_74 ( struct V_74 * V_75 , T_6 * V_68 , int V_182 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_182 ; V_107 ++ , V_68 ++ )
* V_68 = F_73 ( V_75 ) ;
}
static void F_75 ( struct V_74 * V_75 , const T_6 * V_68 ,
int V_182 )
{
int V_107 ;
struct V_79 * V_80 = F_36 ( V_75 ) ;
struct V_49 * V_50 = F_37 ( V_80 ) ;
switch ( V_50 -> V_154 ) {
case V_167 :
for ( V_107 = 0 ; V_107 < V_182 ; V_107 ++ )
F_67 ( V_50 , V_139 , V_68 [ V_107 ] ,
( V_107 + 1 ) == V_182 ) ;
break;
default:
F_76 () ;
break;
}
}
static int F_77 ( struct V_49 * V_50 ,
struct V_183 * V_184 , T_5 V_148 ,
T_7 V_68 , T_1 V_182 , T_3 V_185 ,
bool V_186 , bool V_187 ,
T_7 V_188 )
{
memset ( V_184 , 0 , sizeof( * V_184 ) ) ;
V_184 -> V_188 = F_69 ( V_188 ) ;
V_184 -> V_189 = F_78 ( V_188 ) ;
V_184 -> V_190 = ( V_185 << 24 ) |
( V_187 ? ( 0x03 << 8 ) : 0 ) |
( ! ! V_186 ) | ( ( ! ! V_187 ) << 1 ) ;
#ifdef F_79
V_184 -> V_190 |= 0x01 << 12 ;
#endif
V_184 -> V_191 = F_69 ( V_68 ) ;
V_184 -> V_192 = F_78 ( V_68 ) ;
V_184 -> V_193 = V_182 ;
V_184 -> V_194 = V_182 ;
V_184 -> V_195 = F_69 ( V_148 ) ;
V_184 -> V_196 = F_78 ( V_148 ) ;
V_184 -> V_41 = V_50 -> V_41 ;
V_184 -> V_197 = 0x01 ;
return 0 ;
}
static void F_80 ( struct V_49 * V_50 , T_7 V_184 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned long V_129 = F_64 ( 100 ) ;
F_32 ( V_2 , V_198 , F_69 ( V_184 ) ) ;
( void ) F_33 ( V_2 , V_198 ) ;
F_32 ( V_2 , V_199 , F_78 ( V_184 ) ) ;
( void ) F_33 ( V_2 , V_199 ) ;
V_2 -> V_113 = true ;
F_61 () ;
F_32 ( V_2 , V_200 , 0x03 ) ;
if ( F_65 ( & V_2 -> V_119 , V_129 ) <= 0 ) {
F_6 ( V_2 -> V_10 ,
L_14 ,
F_33 ( V_2 , V_201 ) ,
F_33 ( V_2 , V_202 ) ) ;
}
V_2 -> V_113 = false ;
F_32 ( V_2 , V_200 , 0 ) ;
}
static int F_81 ( struct V_49 * V_50 , T_5 V_148 , T_1 * V_68 ,
T_1 V_182 , T_3 V_185 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_7 V_203 ;
int V_204 = V_185 == V_205 ? V_206 : V_207 ;
V_203 = F_82 ( V_2 -> V_10 , V_68 , V_182 , V_204 ) ;
if ( F_83 ( V_2 -> V_10 , V_203 ) ) {
F_6 ( V_2 -> V_10 , L_15 ) ;
return - V_208 ;
}
F_77 ( V_50 , V_2 -> V_209 , V_148 , V_203 , V_182 ,
V_185 , true , true , 0 ) ;
F_80 ( V_50 , V_2 -> V_210 ) ;
F_84 ( V_2 -> V_10 , V_203 , V_182 , V_204 ) ;
if ( V_2 -> V_209 -> V_197 & V_211 )
return - V_212 ;
else if ( V_2 -> V_209 -> V_197 & V_213 )
return - V_214 ;
return 0 ;
}
static int F_85 ( struct V_74 * V_75 , struct V_79 * V_80 ,
T_5 V_148 , unsigned int V_215 , T_1 * V_68 ,
T_3 * V_108 , T_5 * V_216 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
int V_107 , V_111 , V_174 = 0 ;
F_9 ( V_2 , V_217 , 0 ) ;
F_9 ( V_2 , V_218 , 0 ) ;
F_9 ( V_2 , V_219 , 0 ) ;
F_9 ( V_2 , V_220 , 0 ) ;
F_9 ( V_2 , V_171 ,
( V_50 -> V_41 << 16 ) | ( ( V_148 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_171 ) ;
for ( V_107 = 0 ; V_107 < V_215 ; V_107 ++ , V_148 += V_170 ) {
F_9 ( V_2 , V_122 ,
F_69 ( V_148 ) ) ;
( void ) F_8 ( V_2 , V_122 ) ;
F_58 ( V_50 , V_205 ) ;
F_63 ( V_75 , V_80 ) ;
if ( F_30 ( V_68 ) ) {
F_70 ( V_2 -> V_116 , false ) ;
for ( V_111 = 0 ; V_111 < V_173 ; V_111 ++ , V_68 ++ )
* V_68 = F_11 ( V_2 , V_111 ) ;
F_72 ( V_2 -> V_116 , false ) ;
}
if ( V_108 )
V_108 += F_50 ( V_2 , V_107 , V_108 ,
V_75 -> V_221 / V_215 ,
V_50 -> V_62 . V_72 ) ;
if ( ! V_174 ) {
* V_216 = F_8 ( V_2 ,
V_217 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_219 )
& 0xffff ) << 32 ) ;
if ( * V_216 )
V_174 = - V_212 ;
}
if ( ! V_174 ) {
* V_216 = F_8 ( V_2 ,
V_218 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_220 )
& 0xffff ) << 32 ) ;
if ( * V_216 )
V_174 = - V_214 ;
}
}
return V_174 ;
}
static int F_86 ( struct V_74 * V_75 ,
struct V_79 * V_80 , void * V_68 , T_5 V_148 )
{
int V_107 , V_81 ;
void * V_108 = V_80 -> V_222 ;
int V_223 = 0 ;
int V_224 = V_148 >> V_80 -> V_149 ;
int V_174 ;
if ( ! V_68 ) {
V_68 = V_80 -> V_225 -> V_226 ;
V_80 -> V_227 = - 1 ;
}
V_81 = V_75 -> V_221 / V_80 -> V_87 . V_228 ;
V_80 -> V_178 ( V_75 , V_229 , 0x00 , V_224 ) ;
V_174 = V_80 -> V_87 . V_230 ( V_75 , V_80 , V_68 , true , V_224 ) ;
if ( V_174 )
return V_174 ;
for ( V_107 = 0 ; V_107 < V_80 -> V_87 . V_228 ; V_107 ++ , V_108 += V_81 ) {
V_174 = F_87 ( V_68 , V_80 -> V_87 . V_231 ,
V_108 , V_81 , NULL , 0 ,
V_80 -> V_87 . V_232 ) ;
if ( V_174 < 0 )
return V_174 ;
V_223 = F_51 ( V_223 , V_174 ) ;
}
return V_223 ;
}
static int F_88 ( struct V_74 * V_75 , struct V_79 * V_80 ,
T_5 V_148 , unsigned int V_215 , T_1 * V_68 , T_3 * V_108 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_5 V_216 = 0 ;
int V_233 ;
bool V_234 = true ;
F_47 ( V_2 -> V_10 , L_16 , ( unsigned long long ) V_148 , V_68 ) ;
V_235:
F_9 ( V_2 , V_236 , 0 ) ;
if ( F_27 ( V_2 ) && ! V_108 && F_28 ( V_68 ) ) {
V_233 = F_81 ( V_50 , V_148 , V_68 , V_215 * V_170 ,
V_205 ) ;
if ( V_233 ) {
if ( F_89 ( V_233 ) )
V_216 = V_148 ;
else
return - V_237 ;
}
} else {
if ( V_108 )
memset ( V_108 , 0x99 , V_75 -> V_221 ) ;
V_233 = F_85 ( V_75 , V_80 , V_148 , V_215 , V_68 ,
V_108 , & V_216 ) ;
}
if ( F_90 ( V_233 ) ) {
if ( ( V_2 -> V_9 == 0x0700 ) ||
( V_2 -> V_9 == 0x0701 ) ) {
if ( V_234 ) {
V_234 = false ;
goto V_235;
}
}
if ( V_2 -> V_9 < 0x0702 ) {
V_233 = F_86 ( V_75 , V_80 , V_68 ,
V_148 ) ;
if ( V_233 > 0 )
return V_233 ;
}
F_47 ( V_2 -> V_10 , L_17 ,
( unsigned long long ) V_216 ) ;
V_75 -> V_238 . V_239 ++ ;
return 0 ;
}
if ( F_91 ( V_233 ) ) {
unsigned int V_240 = F_16 ( V_2 ) ;
F_47 ( V_2 -> V_10 , L_18 ,
( unsigned long long ) V_216 ) ;
V_75 -> V_238 . V_240 += V_240 ;
return F_51 ( V_75 -> V_241 , V_240 ) ;
}
return 0 ;
}
static int F_92 ( struct V_74 * V_75 , struct V_79 * V_80 ,
T_6 * V_68 , int V_242 , int V_224 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
T_3 * V_108 = V_242 ? ( T_3 * ) V_80 -> V_222 : NULL ;
return F_88 ( V_75 , V_80 , V_50 -> V_156 ,
V_75 -> V_243 >> V_244 , ( T_1 * ) V_68 , V_108 ) ;
}
static int F_93 ( struct V_74 * V_75 , struct V_79 * V_80 ,
T_6 * V_68 , int V_242 , int V_224 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
T_3 * V_108 = V_242 ? ( T_3 * ) V_80 -> V_222 : NULL ;
int V_174 ;
F_22 ( V_50 , 0 ) ;
V_174 = F_88 ( V_75 , V_80 , V_50 -> V_156 ,
V_75 -> V_243 >> V_244 , ( T_1 * ) V_68 , V_108 ) ;
F_22 ( V_50 , 1 ) ;
return V_174 ;
}
static int F_94 ( struct V_74 * V_75 , struct V_79 * V_80 ,
int V_224 )
{
return F_88 ( V_75 , V_80 , ( T_5 ) V_224 << V_80 -> V_149 ,
V_75 -> V_243 >> V_244 ,
NULL , ( T_3 * ) V_80 -> V_222 ) ;
}
static int F_95 ( struct V_74 * V_75 , struct V_79 * V_80 ,
int V_224 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
F_22 ( V_50 , 0 ) ;
F_88 ( V_75 , V_80 , ( T_5 ) V_224 << V_80 -> V_149 ,
V_75 -> V_243 >> V_244 ,
NULL , ( T_3 * ) V_80 -> V_222 ) ;
F_22 ( V_50 , 1 ) ;
return 0 ;
}
static int F_96 ( struct V_74 * V_75 , struct V_79 * V_80 ,
T_5 V_148 , const T_1 * V_68 , T_3 * V_108 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned int V_107 , V_111 , V_215 = V_75 -> V_243 >> V_244 ;
int V_245 , V_174 = 0 ;
F_47 ( V_2 -> V_10 , L_19 , ( unsigned long long ) V_148 , V_68 ) ;
if ( F_97 ( ( unsigned long ) V_68 & 0x03 ) ) {
F_98 ( V_2 -> V_10 , L_20 , V_68 ) ;
V_68 = ( T_1 * ) ( ( unsigned long ) V_68 & ~ 0x03 ) ;
}
F_46 ( V_75 , 0 ) ;
for ( V_107 = 0 ; V_107 < V_2 -> V_27 ; V_107 += 4 )
F_49 ( V_2 , V_107 , 0xffffffff ) ;
if ( F_27 ( V_2 ) && ! V_108 && F_28 ( V_68 ) ) {
if ( F_81 ( V_50 , V_148 , ( T_1 * ) V_68 ,
V_75 -> V_243 , V_246 ) )
V_174 = - V_237 ;
goto V_247;
}
F_9 ( V_2 , V_171 ,
( V_50 -> V_41 << 16 ) | ( ( V_148 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_171 ) ;
for ( V_107 = 0 ; V_107 < V_215 ; V_107 ++ , V_148 += V_170 ) {
F_9 ( V_2 , V_122 ,
F_69 ( V_148 ) ) ;
( void ) F_8 ( V_2 , V_122 ) ;
if ( V_68 ) {
F_70 ( V_2 -> V_116 , false ) ;
for ( V_111 = 0 ; V_111 < V_173 ; V_111 ++ , V_68 ++ )
F_13 ( V_2 , V_111 , * V_68 ) ;
F_72 ( V_2 -> V_116 , false ) ;
} else if ( V_108 ) {
for ( V_111 = 0 ; V_111 < V_173 ; V_111 ++ )
F_13 ( V_2 , V_111 , 0xffffffff ) ;
}
if ( V_108 ) {
V_108 += F_53 ( V_2 , V_107 , V_108 ,
V_75 -> V_221 / V_215 ,
V_50 -> V_62 . V_72 ) ;
}
F_58 ( V_50 , V_246 ) ;
V_245 = F_63 ( V_75 , V_80 ) ;
if ( V_245 & V_248 ) {
F_99 ( V_2 -> V_10 , L_21 ,
( unsigned long long ) V_148 ) ;
V_174 = - V_237 ;
goto V_247;
}
}
V_247:
F_46 ( V_75 , 1 ) ;
return V_174 ;
}
static int F_100 ( struct V_74 * V_75 , struct V_79 * V_80 ,
const T_6 * V_68 , int V_242 , int V_224 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
void * V_108 = V_242 ? V_80 -> V_222 : NULL ;
F_96 ( V_75 , V_80 , V_50 -> V_156 , ( const T_1 * ) V_68 , V_108 ) ;
return 0 ;
}
static int F_101 ( struct V_74 * V_75 ,
struct V_79 * V_80 , const T_6 * V_68 ,
int V_242 , int V_224 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
void * V_108 = V_242 ? V_80 -> V_222 : NULL ;
F_22 ( V_50 , 0 ) ;
F_96 ( V_75 , V_80 , V_50 -> V_156 , ( const T_1 * ) V_68 , V_108 ) ;
F_22 ( V_50 , 1 ) ;
return 0 ;
}
static int F_102 ( struct V_74 * V_75 , struct V_79 * V_80 ,
int V_224 )
{
return F_96 ( V_75 , V_80 , ( T_5 ) V_224 << V_80 -> V_149 ,
NULL , V_80 -> V_222 ) ;
}
static int F_103 ( struct V_74 * V_75 , struct V_79 * V_80 ,
int V_224 )
{
struct V_49 * V_50 = F_37 ( V_80 ) ;
int V_174 ;
F_22 ( V_50 , 0 ) ;
V_174 = F_96 ( V_75 , V_80 , ( T_5 ) V_224 << V_80 -> V_149 , NULL ,
( T_3 * ) V_80 -> V_222 ) ;
F_22 ( V_50 , 1 ) ;
return V_174 ;
}
static int F_104 ( struct V_49 * V_50 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_79 * V_80 = & V_50 -> V_80 ;
T_2 V_249 = F_15 ( V_2 , V_50 -> V_41 , V_250 ) ;
T_2 V_251 = F_15 ( V_2 , V_50 -> V_41 ,
V_252 ) ;
T_2 V_64 = F_15 ( V_2 , V_50 -> V_41 ,
V_57 ) ;
T_3 V_253 = 0 , V_83 = 0 , V_254 = 0 ;
T_1 V_38 ;
if ( V_2 -> V_26 ) {
int V_107 , V_255 ;
for ( V_107 = 0 , V_255 = 0 ; V_2 -> V_26 [ V_107 ] ; V_107 ++ )
if ( V_2 -> V_26 [ V_107 ] * 1024 == V_71 -> V_253 ) {
V_253 = V_107 ;
V_255 = 1 ;
}
if ( ! V_255 ) {
F_98 ( V_2 -> V_10 , L_22 ,
V_71 -> V_253 ) ;
return - V_95 ;
}
} else {
V_253 = F_105 ( V_71 -> V_253 ) - F_105 ( V_256 ) ;
}
if ( V_71 -> V_253 < V_256 || ( V_2 -> V_25 &&
V_71 -> V_253 > V_2 -> V_25 ) ) {
F_98 ( V_2 -> V_10 , L_22 ,
V_71 -> V_253 ) ;
V_253 = 0 ;
}
if ( V_2 -> V_8 ) {
int V_107 , V_255 ;
for ( V_107 = 0 , V_255 = 0 ; V_2 -> V_8 [ V_107 ] ; V_107 ++ )
if ( V_2 -> V_8 [ V_107 ] == V_71 -> V_83 ) {
V_83 = V_107 ;
V_255 = 1 ;
}
if ( ! V_255 ) {
F_98 ( V_2 -> V_10 , L_23 ,
V_71 -> V_83 ) ;
return - V_95 ;
}
} else {
V_83 = F_105 ( V_71 -> V_83 ) - F_105 ( V_257 ) ;
}
if ( V_71 -> V_83 < V_257 || ( V_2 -> V_24 &&
V_71 -> V_83 > V_2 -> V_24 ) ) {
F_98 ( V_2 -> V_10 , L_23 , V_71 -> V_83 ) ;
return - V_95 ;
}
if ( F_106 ( V_71 -> V_254 ) < F_106 ( V_258 ) ) {
F_98 ( V_2 -> V_10 , L_24 ,
( unsigned long long ) V_71 -> V_254 ) ;
return - V_95 ;
}
V_254 = F_106 ( V_71 -> V_254 ) - F_106 ( V_258 ) ;
V_38 = ( V_71 -> V_259 << V_260 ) |
( V_71 -> V_261 << V_262 ) |
( V_71 -> V_263 << V_264 ) |
( ! ! ( V_71 -> V_265 == 16 ) << V_266 ) |
( V_254 << V_267 ) ;
if ( V_249 == V_251 ) {
V_38 |= ( V_83 << V_268 ) |
( V_253 << V_269 ) ;
F_3 ( V_2 , V_249 , V_38 ) ;
} else {
F_3 ( V_2 , V_249 , V_38 ) ;
V_38 = ( V_83 << V_270 ) |
( V_253 << V_271 ) ;
F_3 ( V_2 , V_251 , V_38 ) ;
}
V_38 = F_1 ( V_2 , V_64 ) ;
V_38 &= ~ F_21 ( V_2 ) ;
V_38 |= V_71 -> V_63 << V_54 ;
V_38 &= ~ F_19 ( V_2 ) ;
V_38 |= V_71 -> V_73 ;
F_3 ( V_2 , V_64 , V_38 ) ;
F_25 ( V_50 , V_71 -> V_72 ) ;
F_17 ( V_50 , F_45 ( V_80 -> V_87 . V_232 * 3 , 4 ) ) ;
return 0 ;
}
static void F_107 ( struct V_49 * V_50 ,
char * V_68 , struct V_70 * V_71 )
{
V_68 += sprintf ( V_68 ,
L_25 ,
( unsigned long long ) V_71 -> V_254 >> 20 ,
V_71 -> V_253 >> 10 ,
V_71 -> V_83 >= 1024 ? V_71 -> V_83 >> 10 : V_71 -> V_83 ,
V_71 -> V_83 >= 1024 ? L_26 : L_27 ,
V_71 -> V_73 , V_71 -> V_265 ) ;
if ( F_34 ( V_50 -> V_2 , V_71 ) )
sprintf ( V_68 , L_28 ) ;
else if ( V_71 -> V_72 )
sprintf ( V_68 , L_29 , V_71 -> V_63 << 1 ) ;
else
sprintf ( V_68 , L_30 , V_71 -> V_63 ) ;
}
static inline int F_108 ( T_5 V_231 , T_1 V_243 )
{
return F_109 ( F_110 ( V_231 ) - F_110 ( V_243 ) , 8 ) >> 3 ;
}
static int F_111 ( struct V_49 * V_50 )
{
struct V_74 * V_75 = F_43 ( & V_50 -> V_80 ) ;
struct V_79 * V_80 = & V_50 -> V_80 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_70 * V_71 = & V_50 -> V_62 ;
char V_272 [ 128 ] ;
T_1 V_3 , V_38 , V_273 ;
int V_174 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_174 = F_112 ( F_113 ( V_80 ) ,
L_31 ,
& V_273 ) ;
if ( V_174 ) {
V_71 -> V_73 = V_75 -> V_221 /
( V_75 -> V_243 >> V_244 ) ;
} else {
V_71 -> V_73 = V_273 ;
}
if ( V_71 -> V_73 > V_2 -> V_27 )
V_71 -> V_73 = V_2 -> V_27 ;
V_75 -> V_221 = V_71 -> V_73 * ( V_75 -> V_243 >> V_244 ) ;
V_71 -> V_254 = V_75 -> V_231 ;
V_71 -> V_253 = V_75 -> V_274 ;
V_71 -> V_83 = V_75 -> V_243 ;
V_71 -> V_265 = ( V_80 -> V_275 & V_276 ) ? 16 : 8 ;
V_71 -> V_261 = 2 ;
V_71 -> V_259 = F_108 ( V_75 -> V_231 , V_75 -> V_243 ) ;
if ( V_80 -> V_87 . V_277 != V_278 ) {
F_6 ( V_2 -> V_10 , L_32 ,
V_80 -> V_87 . V_277 ) ;
return - V_95 ;
}
if ( V_80 -> V_87 . V_279 == V_280 ) {
if ( V_80 -> V_87 . V_232 == 1 && V_80 -> V_87 . V_231 == 512 )
V_80 -> V_87 . V_279 = V_281 ;
else
V_80 -> V_87 . V_279 = V_282 ;
}
if ( V_80 -> V_87 . V_279 == V_281 && ( V_80 -> V_87 . V_232 != 1 ||
V_80 -> V_87 . V_231 != 512 ) ) {
F_6 ( V_2 -> V_10 , L_33 ,
V_80 -> V_87 . V_232 , V_80 -> V_87 . V_231 ) ;
return - V_95 ;
}
switch ( V_80 -> V_87 . V_231 ) {
case 512 :
if ( V_80 -> V_87 . V_279 == V_281 )
V_71 -> V_63 = 15 ;
else
V_71 -> V_63 = V_80 -> V_87 . V_232 ;
V_71 -> V_72 = 0 ;
break;
case 1024 :
if ( ! ( V_2 -> V_28 & V_31 ) ) {
F_6 ( V_2 -> V_10 , L_34 ) ;
return - V_95 ;
}
if ( V_80 -> V_87 . V_232 & 0x1 ) {
F_6 ( V_2 -> V_10 ,
L_35 ) ;
return - V_95 ;
}
V_71 -> V_63 = V_80 -> V_87 . V_232 >> 1 ;
V_71 -> V_72 = 1 ;
break;
default:
F_6 ( V_2 -> V_10 , L_36 ,
V_80 -> V_87 . V_231 ) ;
return - V_95 ;
}
V_71 -> V_263 = V_71 -> V_259 ;
if ( V_75 -> V_243 > 512 )
V_71 -> V_263 += V_71 -> V_261 ;
else
V_71 -> V_263 += 1 ;
V_174 = F_104 ( V_50 , V_71 ) ;
if ( V_174 )
return V_174 ;
F_22 ( V_50 , 1 ) ;
F_107 ( V_50 , V_272 , V_71 ) ;
F_99 ( V_2 -> V_10 , L_37 , V_272 ) ;
V_3 = F_15 ( V_2 , V_50 -> V_41 , V_57 ) ;
V_38 = F_1 ( V_2 , V_3 ) ;
V_38 &= ~ V_283 ;
V_38 &= ~ V_284 ;
if ( V_2 -> V_9 >= 0x0702 )
V_38 |= V_284 ;
V_38 &= ~ V_285 ;
if ( V_2 -> V_28 & V_29 ) {
if ( F_27 ( V_2 ) )
V_38 &= ~ V_286 ;
else
V_38 |= V_286 ;
}
F_3 ( V_2 , V_3 , V_38 ) ;
return 0 ;
}
static int F_114 ( struct V_49 * V_50 , struct V_287 * V_288 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_289 * V_94 = V_50 -> V_94 ;
struct V_74 * V_75 ;
struct V_79 * V_80 ;
int V_174 ;
T_2 V_249 ;
V_174 = F_112 ( V_288 , L_38 , & V_50 -> V_41 ) ;
if ( V_174 ) {
F_6 ( & V_94 -> V_10 , L_39 ) ;
return - V_290 ;
}
V_75 = F_43 ( & V_50 -> V_80 ) ;
V_80 = & V_50 -> V_80 ;
F_115 ( V_80 , V_288 ) ;
F_116 ( V_80 , V_50 ) ;
V_75 -> V_291 = F_117 ( & V_94 -> V_10 , V_292 , L_40 ,
V_50 -> V_41 ) ;
V_75 -> V_293 = V_294 ;
V_75 -> V_10 . V_295 = & V_94 -> V_10 ;
V_80 -> V_296 = ( void V_297 * ) 0xdeadbeef ;
V_80 -> V_298 = ( void V_297 * ) 0xdeadbeef ;
V_80 -> V_299 = F_62 ;
V_80 -> V_178 = F_68 ;
V_80 -> V_300 = F_63 ;
V_80 -> V_301 = F_73 ;
V_80 -> V_302 = F_74 ;
V_80 -> V_303 = F_75 ;
V_80 -> V_87 . V_277 = V_278 ;
V_80 -> V_87 . V_304 = F_92 ;
V_80 -> V_87 . V_305 = F_100 ;
V_80 -> V_87 . V_230 = F_93 ;
V_80 -> V_87 . V_306 = F_101 ;
V_80 -> V_87 . V_307 = F_103 ;
V_80 -> V_87 . V_308 = F_95 ;
V_80 -> V_87 . V_309 = F_94 ;
V_80 -> V_87 . V_310 = F_102 ;
V_80 -> V_311 = & V_2 -> V_311 ;
V_249 = F_15 ( V_2 , V_50 -> V_41 , V_250 ) ;
F_3 ( V_2 , V_249 ,
F_1 ( V_2 , V_249 ) & ~ V_312 ) ;
V_174 = F_118 ( V_75 , 1 , NULL ) ;
if ( V_174 )
return V_174 ;
V_80 -> V_275 |= V_313 ;
V_80 -> V_275 |= V_314 ;
if ( V_80 -> V_315 & V_316 )
V_80 -> V_315 |= V_317 ;
if ( F_111 ( V_50 ) )
return - V_290 ;
V_80 -> V_87 . V_231 = V_50 -> V_62 . V_72 ? 1024 : 512 ;
V_75 -> V_241 = 1 ;
V_174 = F_42 ( V_50 ) ;
if ( V_174 )
return V_174 ;
V_174 = F_119 ( V_75 ) ;
if ( V_174 )
return V_174 ;
return F_120 ( V_75 , NULL , 0 ) ;
}
static void F_121 ( struct V_49 * V_50 ,
int V_318 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_2 V_249 = F_15 ( V_2 , V_50 -> V_41 , V_250 ) ;
T_2 V_251 = F_15 ( V_2 , V_50 -> V_41 ,
V_252 ) ;
T_2 V_64 = F_15 ( V_2 , V_50 -> V_41 ,
V_57 ) ;
T_2 V_319 = F_15 ( V_2 , V_50 -> V_41 , V_320 ) ;
T_2 V_321 = F_15 ( V_2 , V_50 -> V_41 , V_322 ) ;
if ( V_318 ) {
F_3 ( V_2 , V_249 , V_50 -> V_62 . V_323 ) ;
if ( V_249 != V_251 )
F_3 ( V_2 , V_251 ,
V_50 -> V_62 . V_324 ) ;
F_3 ( V_2 , V_64 , V_50 -> V_62 . V_58 ) ;
F_3 ( V_2 , V_319 , V_50 -> V_62 . V_325 ) ;
F_3 ( V_2 , V_321 , V_50 -> V_62 . V_326 ) ;
} else {
V_50 -> V_62 . V_323 = F_1 ( V_2 , V_249 ) ;
if ( V_249 != V_251 )
V_50 -> V_62 . V_324 =
F_1 ( V_2 , V_251 ) ;
V_50 -> V_62 . V_58 = F_1 ( V_2 , V_64 ) ;
V_50 -> V_62 . V_325 = F_1 ( V_2 , V_319 ) ;
V_50 -> V_62 . V_326 = F_1 ( V_2 , V_321 ) ;
}
}
static int F_122 ( struct V_327 * V_10 )
{
struct V_1 * V_2 = F_123 ( V_10 ) ;
struct V_49 * V_50 ;
F_124 (host, &ctrl->host_list, node)
F_121 ( V_50 , 0 ) ;
V_2 -> V_328 = F_8 ( V_2 , V_66 ) ;
V_2 -> V_329 = F_8 ( V_2 , V_330 ) ;
V_2 -> V_331 =
F_8 ( V_2 , V_52 ) ;
if ( F_27 ( V_2 ) )
V_2 -> V_332 = F_33 ( V_2 , V_333 ) ;
return 0 ;
}
static int F_125 ( struct V_327 * V_10 )
{
struct V_1 * V_2 = F_123 ( V_10 ) ;
struct V_49 * V_50 ;
if ( F_27 ( V_2 ) ) {
F_32 ( V_2 , V_333 , V_2 -> V_332 ) ;
F_32 ( V_2 , V_202 , 0 ) ;
}
F_9 ( V_2 , V_66 , V_2 -> V_328 ) ;
F_9 ( V_2 , V_330 , V_2 -> V_329 ) ;
F_9 ( V_2 , V_52 ,
V_2 -> V_331 ) ;
if ( V_2 -> V_116 ) {
V_2 -> V_116 -> V_117 ( V_2 -> V_116 ) ;
V_2 -> V_116 -> V_334 ( V_2 -> V_116 , true ) ;
}
F_124 (host, &ctrl->host_list, node) {
struct V_79 * V_80 = & V_50 -> V_80 ;
struct V_74 * V_75 = F_43 ( V_80 ) ;
F_121 ( V_50 , 1 ) ;
V_80 -> V_178 ( V_75 , V_157 , - 1 , - 1 ) ;
}
return 0 ;
}
int F_126 ( struct V_289 * V_94 , struct V_335 * V_116 )
{
struct V_327 * V_10 = & V_94 -> V_10 ;
struct V_287 * V_288 = V_10 -> V_33 , * V_336 ;
struct V_1 * V_2 ;
struct V_337 * V_338 ;
int V_174 ;
if ( ! V_288 )
return - V_11 ;
if ( ! F_127 ( V_339 , V_288 ) )
return - V_11 ;
V_2 = F_128 ( V_10 , sizeof( * V_2 ) , V_292 ) ;
if ( ! V_2 )
return - V_208 ;
F_129 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
F_130 ( & V_2 -> V_115 ) ;
F_130 ( & V_2 -> V_119 ) ;
F_131 ( & V_2 -> V_311 ) ;
F_132 ( & V_2 -> V_340 ) ;
V_338 = F_133 ( V_94 , V_341 , 0 ) ;
V_2 -> V_4 = F_134 ( V_10 , V_338 ) ;
if ( F_135 ( V_2 -> V_4 ) )
return F_136 ( V_2 -> V_4 ) ;
V_2 -> V_342 = F_137 ( V_10 , L_41 ) ;
if ( ! F_135 ( V_2 -> V_342 ) ) {
V_174 = F_138 ( V_2 -> V_342 ) ;
if ( V_174 )
return V_174 ;
} else {
V_174 = F_136 ( V_2 -> V_342 ) ;
if ( V_174 == - V_343 )
return V_174 ;
V_2 -> V_342 = NULL ;
}
V_174 = F_5 ( V_2 ) ;
if ( V_174 )
goto V_233;
V_338 = F_139 ( V_94 , V_341 , L_42 ) ;
if ( V_338 ) {
V_2 -> V_40 = F_134 ( V_10 , V_338 ) ;
if ( F_135 ( V_2 -> V_40 ) ) {
V_174 = F_136 ( V_2 -> V_40 ) ;
goto V_233;
}
} else {
V_2 -> V_40 = V_2 -> V_4 +
V_2 -> V_12 [ V_344 ] ;
}
V_338 = F_139 ( V_94 , V_341 , L_43 ) ;
if ( V_338 ) {
V_2 -> V_67 = F_134 ( V_10 , V_338 ) ;
if ( F_135 ( V_2 -> V_67 ) ) {
V_174 = F_136 ( V_2 -> V_67 ) ;
goto V_233;
}
F_32 ( V_2 , V_333 , 1 ) ;
F_32 ( V_2 , V_202 , 0 ) ;
V_2 -> V_209 = F_140 ( V_10 ,
sizeof( * V_2 -> V_209 ) ,
& V_2 -> V_210 , V_292 ) ;
if ( ! V_2 -> V_209 ) {
V_174 = - V_208 ;
goto V_233;
}
V_2 -> V_345 = F_141 ( V_94 , 1 ) ;
if ( ( int ) V_2 -> V_345 < 0 ) {
F_6 ( V_10 , L_44 ) ;
V_174 = - V_11 ;
goto V_233;
}
V_174 = F_142 ( V_10 , V_2 -> V_345 ,
F_57 , 0 , V_346 ,
V_2 ) ;
if ( V_174 < 0 ) {
F_6 ( V_10 , L_45 ,
V_2 -> V_345 , V_174 ) ;
goto V_233;
}
F_99 ( V_10 , L_46 ) ;
}
F_10 ( V_2 , V_66 ,
V_347 | 0xff , 0 , 0 ) ;
F_10 ( V_2 , V_330 , 0xff , 0 , 0 ) ;
if ( V_2 -> V_28 & V_32 ) {
if ( V_97 == 2 )
F_26 ( V_2 , false ) ;
} else {
V_97 = 0 ;
}
V_2 -> V_112 = F_141 ( V_94 , 0 ) ;
if ( ( int ) V_2 -> V_112 < 0 ) {
F_6 ( V_10 , L_47 ) ;
V_174 = - V_11 ;
goto V_233;
}
if ( V_116 ) {
V_2 -> V_116 = V_116 ;
V_174 = F_142 ( V_10 , V_2 -> V_112 , F_56 , 0 ,
V_346 , V_2 ) ;
V_2 -> V_116 -> V_117 ( V_2 -> V_116 ) ;
V_2 -> V_116 -> V_334 ( V_2 -> V_116 , true ) ;
} else {
V_174 = F_142 ( V_10 , V_2 -> V_112 , F_54 , 0 ,
V_346 , V_2 ) ;
}
if ( V_174 < 0 ) {
F_6 ( V_10 , L_45 ,
V_2 -> V_112 , V_174 ) ;
goto V_233;
}
F_143 (dn, child) {
if ( F_144 ( V_336 , L_48 ) ) {
struct V_49 * V_50 ;
V_50 = F_128 ( V_10 , sizeof( * V_50 ) , V_292 ) ;
if ( ! V_50 ) {
F_145 ( V_336 ) ;
V_174 = - V_208 ;
goto V_233;
}
V_50 -> V_94 = V_94 ;
V_50 -> V_2 = V_2 ;
V_174 = F_114 ( V_50 , V_336 ) ;
if ( V_174 ) {
F_146 ( V_10 , V_50 ) ;
continue;
}
F_147 ( & V_50 -> V_348 , & V_2 -> V_340 ) ;
}
}
if ( F_148 ( & V_2 -> V_340 ) ) {
V_174 = - V_11 ;
goto V_233;
}
return 0 ;
V_233:
F_149 ( V_2 -> V_342 ) ;
return V_174 ;
}
int F_150 ( struct V_289 * V_94 )
{
struct V_1 * V_2 = F_123 ( & V_94 -> V_10 ) ;
struct V_49 * V_50 ;
F_124 (host, &ctrl->host_list, node)
F_151 ( F_43 ( & V_50 -> V_80 ) ) ;
F_149 ( V_2 -> V_342 ) ;
F_129 ( & V_94 -> V_10 , NULL ) ;
return 0 ;
}
