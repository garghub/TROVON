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
static int F_26 ( struct V_1 * V_2 ,
T_1 V_36 , T_1 V_65 ,
unsigned long V_66 )
{
unsigned long V_67 ;
T_1 V_5 ;
if ( ! V_66 )
V_66 = V_68 ;
V_67 = V_69 + F_27 ( V_66 ) ;
do {
V_5 = F_8 ( V_2 , V_70 ) ;
if ( ( V_5 & V_36 ) == V_65 )
return 0 ;
F_28 () ;
} while ( F_29 ( V_67 , V_69 ) );
F_30 ( V_2 -> V_10 , L_3 ,
V_65 , V_5 & V_36 ) ;
return - V_71 ;
}
static inline void F_31 ( struct V_1 * V_2 , bool V_56 )
{
T_1 V_5 = V_56 ? V_72 : 0 ;
F_10 ( V_2 , V_73 , V_72 , 0 , V_5 ) ;
}
static inline bool F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_74 ;
}
static inline bool F_33 ( const void * V_75 )
{
return V_75 && ! F_34 ( V_75 ) &&
F_35 ( F_36 ( ( V_76 ) V_75 , 4 ) ) ;
}
static inline void F_37 ( struct V_1 * V_2 , T_3 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_74 + V_3 ) ;
}
static inline T_1 F_38 ( struct V_1 * V_2 , T_3 V_3 )
{
return F_2 ( V_2 -> V_74 + V_3 ) ;
}
static inline bool F_39 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
if ( V_2 -> V_9 <= 0x0701 )
return V_78 -> V_79 == 0 && V_78 -> V_80 == 16 &&
V_78 -> V_63 == 15 ;
else
return V_78 -> V_79 == 0 && ( ( V_78 -> V_80 == 16 &&
V_78 -> V_63 == 15 ) ||
( V_78 -> V_80 == 28 && V_78 -> V_63 == 16 ) ) ;
}
static int F_40 ( struct V_81 * V_82 , int V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_77 * V_78 = & V_50 -> V_62 ;
int V_88 = V_78 -> V_80 << V_78 -> V_79 ;
int V_89 = V_78 -> V_90 / ( 512 << V_78 -> V_79 ) ;
if ( V_83 >= V_89 )
return - V_91 ;
V_85 -> V_92 = ( V_83 * V_88 ) + 6 ;
V_85 -> V_93 = 3 ;
return 0 ;
}
static int F_43 ( struct V_81 * V_82 , int V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_77 * V_78 = & V_50 -> V_62 ;
int V_88 = V_78 -> V_80 << V_78 -> V_79 ;
int V_89 = V_78 -> V_90 / ( 512 << V_78 -> V_79 ) ;
if ( V_83 >= V_89 * 2 )
return - V_91 ;
V_85 -> V_92 = ( V_83 / 2 ) * V_88 ;
if ( V_83 & 1 ) {
V_85 -> V_92 += 9 ;
V_85 -> V_93 = 7 ;
} else {
V_85 -> V_93 = 6 ;
if ( ! V_83 ) {
if ( V_78 -> V_90 > 512 )
V_85 -> V_92 ++ ;
V_85 -> V_93 -- ;
}
}
return 0 ;
}
static int F_44 ( struct V_81 * V_82 , int V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_77 * V_78 = & V_50 -> V_62 ;
int V_88 = V_78 -> V_80 << V_78 -> V_79 ;
int V_89 = V_78 -> V_90 / ( 512 << V_78 -> V_79 ) ;
if ( V_83 >= V_89 )
return - V_91 ;
V_85 -> V_92 = ( V_83 * ( V_88 + 1 ) ) - V_87 -> V_94 . V_95 ;
V_85 -> V_93 = V_87 -> V_94 . V_95 ;
return 0 ;
}
static int F_45 ( struct V_81 * V_82 , int V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_77 * V_78 = & V_50 -> V_62 ;
int V_88 = V_78 -> V_80 << V_78 -> V_79 ;
int V_89 = V_78 -> V_90 / ( 512 << V_78 -> V_79 ) ;
if ( V_83 >= V_89 )
return - V_91 ;
if ( V_88 <= V_87 -> V_94 . V_95 )
return 0 ;
V_85 -> V_92 = V_83 * V_88 ;
V_85 -> V_93 = V_88 - V_87 -> V_94 . V_95 ;
if ( ! V_83 ) {
V_85 -> V_92 ++ ;
V_85 -> V_93 -- ;
}
return 0 ;
}
static int F_46 ( struct V_81 * V_82 , int V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_77 * V_78 = & V_50 -> V_62 ;
int V_88 = V_78 -> V_80 << V_78 -> V_79 ;
if ( V_83 > 1 || V_88 - V_87 -> V_94 . V_95 < 6 ||
( V_83 && V_88 - V_87 -> V_94 . V_95 == 6 ) )
return - V_91 ;
if ( ! V_83 ) {
V_85 -> V_92 = 0 ;
V_85 -> V_93 = 5 ;
} else {
V_85 -> V_92 = 6 ;
V_85 -> V_93 = V_88 - V_87 -> V_94 . V_95 - 6 ;
}
return 0 ;
}
static int F_47 ( struct V_49 * V_50 )
{
struct V_77 * V_96 = & V_50 -> V_62 ;
struct V_81 * V_82 = F_48 ( & V_50 -> V_87 ) ;
struct V_97 * V_94 = & V_50 -> V_87 . V_94 ;
unsigned int V_63 = V_96 -> V_63 ;
int V_88 = V_96 -> V_80 << V_96 -> V_79 ;
int V_89 = V_96 -> V_90 / ( 512 << V_96 -> V_79 ) ;
if ( V_96 -> V_79 )
V_63 <<= 1 ;
if ( F_39 ( V_50 -> V_2 , V_96 ) ) {
V_94 -> V_95 = 3 * V_89 ;
F_49 ( V_82 , & V_98 ) ;
return 0 ;
}
V_94 -> V_95 = F_50 ( V_63 * 14 , 8 ) ;
if ( V_96 -> V_90 == 512 )
F_49 ( V_82 , & V_99 ) ;
else
F_49 ( V_82 , & V_100 ) ;
if ( V_94 -> V_95 >= V_88 ) {
F_6 ( & V_50 -> V_101 -> V_10 ,
L_4 ,
V_94 -> V_95 , V_88 ) ;
return - V_102 ;
}
return 0 ;
}
static void F_51 ( struct V_81 * V_82 , int V_103 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
if ( ( V_2 -> V_28 & V_32 ) && V_104 == 1 ) {
static int V_105 = - 1 ;
int V_106 ;
if ( V_105 != V_103 ) {
F_52 ( V_2 -> V_10 , L_5 , V_103 ? L_6 : L_7 ) ;
V_105 = V_103 ;
}
V_106 = F_26 ( V_2 , V_107 |
V_108 ,
V_107 |
V_108 , 0 ) ;
if ( V_106 )
return;
F_31 ( V_2 , V_103 ) ;
V_87 -> V_109 ( V_82 , V_110 , - 1 , - 1 ) ;
V_106 = F_26 ( V_2 ,
V_107 |
V_108 |
V_111 ,
V_107 |
V_108 |
( V_103 ? 0 : V_111 ) , 0 ) ;
if ( V_106 )
F_53 ( & V_50 -> V_101 -> V_10 ,
L_8 ,
V_103 ? L_6 : L_7 ) ;
}
}
static inline T_3 F_54 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_112 , V_113 , V_114 ;
V_112 = V_2 -> V_12 [ V_115 ] ;
V_113 = V_2 -> V_12 [ V_116 ] ;
if ( V_3 >= V_2 -> V_27 )
return 0x77 ;
if ( V_3 >= 16 && V_113 )
V_114 = V_113 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_114 = V_112 + ( V_3 & ~ 0x03 ) ;
return F_1 ( V_2 , V_114 ) >> ( 24 - ( ( V_3 & 0x03 ) << 3 ) ) ;
}
static inline void F_55 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_117 )
{
T_2 V_112 , V_113 , V_114 ;
V_112 = V_2 -> V_12 [ V_118 ] ;
V_113 = V_2 -> V_12 [ V_119 ] ;
if ( V_3 >= V_2 -> V_27 )
return;
if ( V_3 >= 16 && V_113 )
V_114 = V_113 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_114 = V_112 + ( V_3 & ~ 0x03 ) ;
F_3 ( V_2 , V_114 , V_117 ) ;
}
static int F_56 ( struct V_1 * V_2 , int V_120 , T_3 * V_121 ,
int V_88 , int V_122 )
{
int V_123 = V_88 << V_122 ;
int V_124 ;
if ( V_122 && ( V_120 & 0x01 ) )
V_123 = F_57 ( 0 , V_123 - ( int ) V_2 -> V_27 ) ;
V_123 = F_58 ( int , V_123 , V_2 -> V_27 ) ;
for ( V_124 = 0 ; V_124 < V_123 ; V_124 ++ )
V_121 [ V_124 ] = F_54 ( V_2 , V_124 ) ;
return V_123 ;
}
static int F_59 ( struct V_1 * V_2 , int V_120 ,
const T_3 * V_121 , int V_88 , int V_122 )
{
int V_123 = V_88 << V_122 ;
int V_124 ;
if ( V_122 && ( V_120 & 0x01 ) )
V_123 = F_57 ( 0 , V_123 - ( int ) V_2 -> V_27 ) ;
V_123 = F_58 ( int , V_123 , V_2 -> V_27 ) ;
for ( V_124 = 0 ; V_124 < V_123 ; V_124 += 4 )
F_55 ( V_2 , V_124 ,
( V_121 [ V_124 + 0 ] << 24 ) |
( V_121 [ V_124 + 1 ] << 16 ) |
( V_121 [ V_124 + 2 ] << 8 ) |
( V_121 [ V_124 + 3 ] << 0 ) ) ;
return V_123 ;
}
static T_4 F_60 ( int V_125 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
if ( V_2 -> V_126 )
return V_127 ;
F_61 ( & V_2 -> V_128 ) ;
return V_127 ;
}
static T_4 F_62 ( int V_125 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
if ( V_2 -> V_129 -> V_130 ( V_2 -> V_129 ) )
return F_60 ( V_125 , V_117 ) ;
return V_131 ;
}
static T_4 F_63 ( int V_125 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
F_61 ( & V_2 -> V_132 ) ;
return V_127 ;
}
static void F_64 ( struct V_49 * V_50 , int V_133 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
int V_106 ;
F_52 ( V_2 -> V_10 , L_9 , V_133 ,
F_8 ( V_2 , V_134 ) ) ;
F_65 ( V_2 -> V_135 != 0 ) ;
V_2 -> V_135 = V_133 ;
V_106 = F_26 ( V_2 , V_107 , V_107 , 0 ) ;
F_66 ( V_106 ) ;
F_67 () ;
F_9 ( V_2 , V_136 ,
V_133 << F_18 ( V_2 ) ) ;
}
static void F_68 ( struct V_81 * V_82 , int V_137 ,
unsigned int V_2 )
{
}
static int F_69 ( struct V_81 * V_82 , struct V_86 * V_138 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned long V_139 = F_27 ( 100 ) ;
F_52 ( V_2 -> V_10 , L_10 , V_2 -> V_135 ) ;
if ( V_2 -> V_135 &&
F_70 ( & V_2 -> V_128 , V_139 ) <= 0 ) {
T_1 V_133 = F_8 ( V_2 , V_136 )
>> F_18 ( V_2 ) ;
F_53 ( V_2 -> V_10 ,
L_11 , V_133 ) ;
F_53 ( V_2 -> V_10 , L_12 ,
F_8 ( V_2 , V_70 ) ) ;
}
V_2 -> V_135 = 0 ;
return F_8 ( V_2 , V_70 ) &
V_140 ;
}
static int F_71 ( struct V_49 * V_50 ,
enum V_141 type , T_1 V_117 ,
bool V_142 )
{
struct V_81 * V_82 = F_48 ( & V_50 -> V_87 ) ;
struct V_86 * V_87 = & V_50 -> V_87 ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_1 V_38 ;
V_38 = V_117 & V_143 ;
switch ( type ) {
case V_144 :
V_38 |= V_145 | V_146 ;
break;
case V_147 :
V_38 |= V_145 | V_148 ;
break;
case V_149 :
V_38 |= V_145 ;
break;
case V_150 :
V_38 |= V_151 ;
break;
}
if ( V_142 )
V_38 |= V_152 ;
F_52 ( V_2 -> V_10 , L_13 , V_38 ) ;
F_9 ( V_2 , V_153 , V_38 ) ;
( void ) F_8 ( V_2 , V_153 ) ;
F_64 ( V_50 , V_154 ) ;
return F_69 ( V_82 , V_87 ) ;
}
static void F_72 ( struct V_81 * V_82 , unsigned V_155 ,
int V_156 , int V_157 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_5 V_158 = ( T_5 ) V_157 << V_87 -> V_159 ;
int V_160 = 0 ;
if ( V_155 == V_161 || V_155 == V_162 ||
V_155 == V_163 )
V_158 = ( T_5 ) V_156 ;
else if ( V_157 < 0 )
V_158 = 0 ;
F_52 ( V_2 -> V_10 , L_14 , V_155 ,
( unsigned long long ) V_158 ) ;
V_50 -> V_164 = V_155 ;
V_50 -> V_165 = 0 ;
V_50 -> V_166 = V_158 ;
switch ( V_155 ) {
case V_167 :
V_160 = V_168 ;
break;
case V_110 :
V_160 = V_169 ;
break;
case V_161 :
V_160 = V_170 ;
break;
case V_171 :
V_160 = V_172 ;
break;
case V_173 :
V_160 = V_174 ;
F_51 ( V_82 , 0 ) ;
break;
case V_162 :
V_160 = V_175 ;
break;
case V_176 :
case V_177 :
F_71 ( V_50 , V_144 , V_155 , false ) ;
F_71 ( V_50 , V_147 , V_156 , false ) ;
break;
case V_163 :
V_160 = V_178 ;
V_158 &= ~ ( ( T_5 ) ( V_179 - 1 ) ) ;
if ( F_24 ( V_50 ) ) {
V_50 -> V_62 . V_79 =
F_24 ( V_50 ) ;
F_25 ( V_50 , 0 ) ;
}
break;
}
if ( ! V_160 )
return;
F_9 ( V_2 , V_180 ,
( V_50 -> V_41 << 16 ) | ( ( V_158 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_180 ) ;
F_9 ( V_2 , V_134 , F_73 ( V_158 ) ) ;
( void ) F_8 ( V_2 , V_134 ) ;
F_64 ( V_50 , V_160 ) ;
F_69 ( V_82 , V_87 ) ;
if ( V_160 == V_175 ||
V_160 == V_178 ) {
T_1 * V_181 = ( T_1 * ) V_2 -> V_181 ;
int V_120 ;
F_74 ( V_2 -> V_129 , true ) ;
for ( V_120 = 0 ; V_120 < V_182 ; V_120 ++ )
V_181 [ V_120 ] = F_75 ( F_11 ( V_2 , V_120 ) ) ;
F_76 ( V_2 -> V_129 , true ) ;
if ( V_50 -> V_62 . V_79 )
F_25 ( V_50 ,
V_50 -> V_62 . V_79 ) ;
}
if ( V_155 == V_173 )
F_51 ( V_82 , 1 ) ;
}
static T_6 F_77 ( struct V_81 * V_82 )
{
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_6 V_106 = 0 ;
int V_158 , V_3 ;
switch ( V_50 -> V_164 ) {
case V_161 :
if ( V_50 -> V_165 < 4 )
V_106 = F_8 ( V_2 , V_183 ) >>
( 24 - ( V_50 -> V_165 << 3 ) ) ;
else if ( V_50 -> V_165 < 8 )
V_106 = F_8 ( V_2 , V_184 ) >>
( 56 - ( V_50 -> V_165 << 3 ) ) ;
break;
case V_171 :
V_106 = F_54 ( V_2 , V_50 -> V_165 ) ;
break;
case V_110 :
V_106 = F_8 ( V_2 , V_70 ) &
V_140 ;
if ( V_104 )
V_106 |= V_111 ;
break;
case V_162 :
case V_163 :
V_158 = V_50 -> V_166 + V_50 -> V_165 ;
V_3 = V_158 & ( V_179 - 1 ) ;
if ( V_50 -> V_165 > 0 && V_3 == 0 )
V_87 -> V_109 ( V_82 , V_163 , V_158 , - 1 ) ;
V_106 = V_2 -> V_181 [ V_3 ] ;
break;
case V_177 :
if ( V_50 -> V_165 >= V_185 ) {
V_106 = 0 ;
} else {
bool V_186 = V_50 -> V_165 ==
V_185 - 1 ;
F_71 ( V_50 , V_150 , 0 , V_186 ) ;
V_106 = F_8 ( V_2 , V_187 ) & 0xff ;
}
}
F_52 ( V_2 -> V_10 , L_15 , V_106 ) ;
V_50 -> V_165 ++ ;
return V_106 ;
}
static void F_78 ( struct V_81 * V_82 , T_6 * V_75 , int V_188 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_188 ; V_120 ++ , V_75 ++ )
* V_75 = F_77 ( V_82 ) ;
}
static void F_79 ( struct V_81 * V_82 , const T_6 * V_75 ,
int V_188 )
{
int V_120 ;
struct V_86 * V_87 = F_41 ( V_82 ) ;
struct V_49 * V_50 = F_42 ( V_87 ) ;
switch ( V_50 -> V_164 ) {
case V_176 :
for ( V_120 = 0 ; V_120 < V_188 ; V_120 ++ )
F_71 ( V_50 , V_149 , V_75 [ V_120 ] ,
( V_120 + 1 ) == V_188 ) ;
break;
default:
F_80 () ;
break;
}
}
static int F_81 ( struct V_49 * V_50 ,
struct V_189 * V_190 , T_5 V_158 ,
T_7 V_75 , T_1 V_188 , T_3 V_191 ,
bool V_192 , bool V_193 ,
T_7 V_194 )
{
memset ( V_190 , 0 , sizeof( * V_190 ) ) ;
V_190 -> V_194 = F_73 ( V_194 ) ;
V_190 -> V_195 = F_82 ( V_194 ) ;
V_190 -> V_196 = ( V_191 << 24 ) |
( V_193 ? ( 0x03 << 8 ) : 0 ) |
( ! ! V_192 ) | ( ( ! ! V_193 ) << 1 ) ;
#ifdef F_83
V_190 -> V_196 |= 0x01 << 12 ;
#endif
V_190 -> V_197 = F_73 ( V_75 ) ;
V_190 -> V_198 = F_82 ( V_75 ) ;
V_190 -> V_199 = V_188 ;
V_190 -> V_200 = V_188 ;
V_190 -> V_201 = F_73 ( V_158 ) ;
V_190 -> V_202 = F_82 ( V_158 ) ;
V_190 -> V_41 = V_50 -> V_41 ;
V_190 -> V_203 = 0x01 ;
return 0 ;
}
static void F_84 ( struct V_49 * V_50 , T_7 V_190 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned long V_139 = F_27 ( 100 ) ;
F_37 ( V_2 , V_204 , F_73 ( V_190 ) ) ;
( void ) F_38 ( V_2 , V_204 ) ;
F_37 ( V_2 , V_205 , F_82 ( V_190 ) ) ;
( void ) F_38 ( V_2 , V_205 ) ;
V_2 -> V_126 = true ;
F_67 () ;
F_37 ( V_2 , V_206 , 0x03 ) ;
if ( F_70 ( & V_2 -> V_132 , V_139 ) <= 0 ) {
F_6 ( V_2 -> V_10 ,
L_16 ,
F_38 ( V_2 , V_207 ) ,
F_38 ( V_2 , V_208 ) ) ;
}
V_2 -> V_126 = false ;
F_37 ( V_2 , V_206 , 0 ) ;
}
static int F_85 ( struct V_49 * V_50 , T_5 V_158 , T_1 * V_75 ,
T_1 V_188 , T_3 V_191 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_7 V_209 ;
int V_210 = V_191 == V_211 ? V_212 : V_213 ;
V_209 = F_86 ( V_2 -> V_10 , V_75 , V_188 , V_210 ) ;
if ( F_87 ( V_2 -> V_10 , V_209 ) ) {
F_6 ( V_2 -> V_10 , L_17 ) ;
return - V_214 ;
}
F_81 ( V_50 , V_2 -> V_215 , V_158 , V_209 , V_188 ,
V_191 , true , true , 0 ) ;
F_84 ( V_50 , V_2 -> V_216 ) ;
F_88 ( V_2 -> V_10 , V_209 , V_188 , V_210 ) ;
if ( V_2 -> V_215 -> V_203 & V_217 )
return - V_218 ;
else if ( V_2 -> V_215 -> V_203 & V_219 )
return - V_220 ;
return 0 ;
}
static int F_89 ( struct V_81 * V_82 , struct V_86 * V_87 ,
T_5 V_158 , unsigned int V_221 , T_1 * V_75 ,
T_3 * V_121 , T_5 * V_222 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
int V_120 , V_124 , V_106 = 0 ;
F_9 ( V_2 , V_223 , 0 ) ;
F_9 ( V_2 , V_224 , 0 ) ;
F_9 ( V_2 , V_225 , 0 ) ;
F_9 ( V_2 , V_226 , 0 ) ;
F_9 ( V_2 , V_180 ,
( V_50 -> V_41 << 16 ) | ( ( V_158 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_180 ) ;
for ( V_120 = 0 ; V_120 < V_221 ; V_120 ++ , V_158 += V_179 ) {
F_9 ( V_2 , V_134 ,
F_73 ( V_158 ) ) ;
( void ) F_8 ( V_2 , V_134 ) ;
F_64 ( V_50 , V_211 ) ;
F_69 ( V_82 , V_87 ) ;
if ( F_35 ( V_75 ) ) {
F_74 ( V_2 -> V_129 , false ) ;
for ( V_124 = 0 ; V_124 < V_182 ; V_124 ++ , V_75 ++ )
* V_75 = F_11 ( V_2 , V_124 ) ;
F_76 ( V_2 -> V_129 , false ) ;
}
if ( V_121 )
V_121 += F_56 ( V_2 , V_120 , V_121 ,
V_82 -> V_227 / V_221 ,
V_50 -> V_62 . V_79 ) ;
if ( ! V_106 ) {
* V_222 = F_8 ( V_2 ,
V_223 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_225 )
& 0xffff ) << 32 ) ;
if ( * V_222 )
V_106 = - V_218 ;
}
if ( ! V_106 ) {
* V_222 = F_8 ( V_2 ,
V_224 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_226 )
& 0xffff ) << 32 ) ;
if ( * V_222 )
V_106 = - V_220 ;
}
}
return V_106 ;
}
static int F_90 ( struct V_81 * V_82 ,
struct V_86 * V_87 , void * V_75 , T_5 V_158 )
{
int V_120 , V_88 ;
void * V_121 = V_87 -> V_228 ;
int V_229 = 0 ;
int V_230 = V_158 >> V_87 -> V_159 ;
int V_106 ;
if ( ! V_75 ) {
V_75 = V_87 -> V_231 -> V_232 ;
V_87 -> V_233 = - 1 ;
}
V_88 = V_82 -> V_227 / V_87 -> V_94 . V_234 ;
V_87 -> V_109 ( V_82 , V_235 , 0x00 , V_230 ) ;
V_106 = V_87 -> V_94 . V_236 ( V_82 , V_87 , V_75 , true , V_230 ) ;
if ( V_106 )
return V_106 ;
for ( V_120 = 0 ; V_120 < V_87 -> V_94 . V_234 ; V_120 ++ , V_121 += V_88 ) {
V_106 = F_91 ( V_75 , V_87 -> V_94 . V_237 ,
V_121 , V_88 , NULL , 0 ,
V_87 -> V_94 . V_238 ) ;
if ( V_106 < 0 )
return V_106 ;
V_229 = F_57 ( V_229 , V_106 ) ;
}
return V_229 ;
}
static int F_92 ( struct V_81 * V_82 , struct V_86 * V_87 ,
T_5 V_158 , unsigned int V_221 , T_1 * V_75 , T_3 * V_121 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_5 V_222 = 0 ;
int V_239 ;
bool V_240 = true ;
F_52 ( V_2 -> V_10 , L_18 , ( unsigned long long ) V_158 , V_75 ) ;
V_241:
F_9 ( V_2 , V_242 , 0 ) ;
if ( F_32 ( V_2 ) && ! V_121 && F_33 ( V_75 ) ) {
V_239 = F_85 ( V_50 , V_158 , V_75 , V_221 * V_179 ,
V_211 ) ;
if ( V_239 ) {
if ( F_93 ( V_239 ) )
V_222 = V_158 ;
else
return - V_243 ;
}
} else {
if ( V_121 )
memset ( V_121 , 0x99 , V_82 -> V_227 ) ;
V_239 = F_89 ( V_82 , V_87 , V_158 , V_221 , V_75 ,
V_121 , & V_222 ) ;
}
if ( F_94 ( V_239 ) ) {
if ( ( V_2 -> V_9 == 0x0700 ) ||
( V_2 -> V_9 == 0x0701 ) ) {
if ( V_240 ) {
V_240 = false ;
goto V_241;
}
}
if ( V_2 -> V_9 < 0x0702 ) {
V_239 = F_90 ( V_82 , V_87 , V_75 ,
V_158 ) ;
if ( V_239 > 0 )
return V_239 ;
}
F_52 ( V_2 -> V_10 , L_19 ,
( unsigned long long ) V_222 ) ;
V_82 -> V_244 . V_245 ++ ;
return 0 ;
}
if ( F_95 ( V_239 ) ) {
unsigned int V_246 = F_16 ( V_2 ) ;
F_52 ( V_2 -> V_10 , L_20 ,
( unsigned long long ) V_222 ) ;
V_82 -> V_244 . V_246 += V_246 ;
return F_57 ( V_82 -> V_247 , V_246 ) ;
}
return 0 ;
}
static int F_96 ( struct V_81 * V_82 , struct V_86 * V_87 ,
T_6 * V_75 , int V_248 , int V_230 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
T_3 * V_121 = V_248 ? ( T_3 * ) V_87 -> V_228 : NULL ;
return F_92 ( V_82 , V_87 , V_50 -> V_166 ,
V_82 -> V_249 >> V_250 , ( T_1 * ) V_75 , V_121 ) ;
}
static int F_97 ( struct V_81 * V_82 , struct V_86 * V_87 ,
T_6 * V_75 , int V_248 , int V_230 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
T_3 * V_121 = V_248 ? ( T_3 * ) V_87 -> V_228 : NULL ;
int V_106 ;
F_22 ( V_50 , 0 ) ;
V_106 = F_92 ( V_82 , V_87 , V_50 -> V_166 ,
V_82 -> V_249 >> V_250 , ( T_1 * ) V_75 , V_121 ) ;
F_22 ( V_50 , 1 ) ;
return V_106 ;
}
static int F_98 ( struct V_81 * V_82 , struct V_86 * V_87 ,
int V_230 )
{
return F_92 ( V_82 , V_87 , ( T_5 ) V_230 << V_87 -> V_159 ,
V_82 -> V_249 >> V_250 ,
NULL , ( T_3 * ) V_87 -> V_228 ) ;
}
static int F_99 ( struct V_81 * V_82 , struct V_86 * V_87 ,
int V_230 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
F_22 ( V_50 , 0 ) ;
F_92 ( V_82 , V_87 , ( T_5 ) V_230 << V_87 -> V_159 ,
V_82 -> V_249 >> V_250 ,
NULL , ( T_3 * ) V_87 -> V_228 ) ;
F_22 ( V_50 , 1 ) ;
return 0 ;
}
static int F_100 ( struct V_81 * V_82 , struct V_86 * V_87 ,
T_5 V_158 , const T_1 * V_75 , T_3 * V_121 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned int V_120 , V_124 , V_221 = V_82 -> V_249 >> V_250 ;
int V_251 , V_106 = 0 ;
F_52 ( V_2 -> V_10 , L_21 , ( unsigned long long ) V_158 , V_75 ) ;
if ( F_101 ( ( unsigned long ) V_75 & 0x03 ) ) {
F_30 ( V_2 -> V_10 , L_22 , V_75 ) ;
V_75 = ( T_1 * ) ( ( unsigned long ) V_75 & ~ 0x03 ) ;
}
F_51 ( V_82 , 0 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_27 ; V_120 += 4 )
F_55 ( V_2 , V_120 , 0xffffffff ) ;
if ( F_32 ( V_2 ) && ! V_121 && F_33 ( V_75 ) ) {
if ( F_85 ( V_50 , V_158 , ( T_1 * ) V_75 ,
V_82 -> V_249 , V_252 ) )
V_106 = - V_243 ;
goto V_253;
}
F_9 ( V_2 , V_180 ,
( V_50 -> V_41 << 16 ) | ( ( V_158 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_180 ) ;
for ( V_120 = 0 ; V_120 < V_221 ; V_120 ++ , V_158 += V_179 ) {
F_9 ( V_2 , V_134 ,
F_73 ( V_158 ) ) ;
( void ) F_8 ( V_2 , V_134 ) ;
if ( V_75 ) {
F_74 ( V_2 -> V_129 , false ) ;
for ( V_124 = 0 ; V_124 < V_182 ; V_124 ++ , V_75 ++ )
F_13 ( V_2 , V_124 , * V_75 ) ;
F_76 ( V_2 -> V_129 , false ) ;
} else if ( V_121 ) {
for ( V_124 = 0 ; V_124 < V_182 ; V_124 ++ )
F_13 ( V_2 , V_124 , 0xffffffff ) ;
}
if ( V_121 ) {
V_121 += F_59 ( V_2 , V_120 , V_121 ,
V_82 -> V_227 / V_221 ,
V_50 -> V_62 . V_79 ) ;
}
F_64 ( V_50 , V_252 ) ;
V_251 = F_69 ( V_82 , V_87 ) ;
if ( V_251 & V_254 ) {
F_102 ( V_2 -> V_10 , L_23 ,
( unsigned long long ) V_158 ) ;
V_106 = - V_243 ;
goto V_253;
}
}
V_253:
F_51 ( V_82 , 1 ) ;
return V_106 ;
}
static int F_103 ( struct V_81 * V_82 , struct V_86 * V_87 ,
const T_6 * V_75 , int V_248 , int V_230 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
void * V_121 = V_248 ? V_87 -> V_228 : NULL ;
F_100 ( V_82 , V_87 , V_50 -> V_166 , ( const T_1 * ) V_75 , V_121 ) ;
return 0 ;
}
static int F_104 ( struct V_81 * V_82 ,
struct V_86 * V_87 , const T_6 * V_75 ,
int V_248 , int V_230 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
void * V_121 = V_248 ? V_87 -> V_228 : NULL ;
F_22 ( V_50 , 0 ) ;
F_100 ( V_82 , V_87 , V_50 -> V_166 , ( const T_1 * ) V_75 , V_121 ) ;
F_22 ( V_50 , 1 ) ;
return 0 ;
}
static int F_105 ( struct V_81 * V_82 , struct V_86 * V_87 ,
int V_230 )
{
return F_100 ( V_82 , V_87 , ( T_5 ) V_230 << V_87 -> V_159 ,
NULL , V_87 -> V_228 ) ;
}
static int F_106 ( struct V_81 * V_82 , struct V_86 * V_87 ,
int V_230 )
{
struct V_49 * V_50 = F_42 ( V_87 ) ;
int V_106 ;
F_22 ( V_50 , 0 ) ;
V_106 = F_100 ( V_82 , V_87 , ( T_5 ) V_230 << V_87 -> V_159 , NULL ,
( T_3 * ) V_87 -> V_228 ) ;
F_22 ( V_50 , 1 ) ;
return V_106 ;
}
static int F_107 ( struct V_49 * V_50 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_86 * V_87 = & V_50 -> V_87 ;
T_2 V_255 = F_15 ( V_2 , V_50 -> V_41 , V_256 ) ;
T_2 V_257 = F_15 ( V_2 , V_50 -> V_41 ,
V_258 ) ;
T_2 V_64 = F_15 ( V_2 , V_50 -> V_41 ,
V_57 ) ;
T_3 V_259 = 0 , V_90 = 0 , V_260 = 0 ;
T_1 V_38 ;
if ( V_2 -> V_26 ) {
int V_120 , V_261 ;
for ( V_120 = 0 , V_261 = 0 ; V_2 -> V_26 [ V_120 ] ; V_120 ++ )
if ( V_2 -> V_26 [ V_120 ] * 1024 == V_78 -> V_259 ) {
V_259 = V_120 ;
V_261 = 1 ;
}
if ( ! V_261 ) {
F_30 ( V_2 -> V_10 , L_24 ,
V_78 -> V_259 ) ;
return - V_102 ;
}
} else {
V_259 = F_108 ( V_78 -> V_259 ) - F_108 ( V_262 ) ;
}
if ( V_78 -> V_259 < V_262 || ( V_2 -> V_25 &&
V_78 -> V_259 > V_2 -> V_25 ) ) {
F_30 ( V_2 -> V_10 , L_24 ,
V_78 -> V_259 ) ;
V_259 = 0 ;
}
if ( V_2 -> V_8 ) {
int V_120 , V_261 ;
for ( V_120 = 0 , V_261 = 0 ; V_2 -> V_8 [ V_120 ] ; V_120 ++ )
if ( V_2 -> V_8 [ V_120 ] == V_78 -> V_90 ) {
V_90 = V_120 ;
V_261 = 1 ;
}
if ( ! V_261 ) {
F_30 ( V_2 -> V_10 , L_25 ,
V_78 -> V_90 ) ;
return - V_102 ;
}
} else {
V_90 = F_108 ( V_78 -> V_90 ) - F_108 ( V_263 ) ;
}
if ( V_78 -> V_90 < V_263 || ( V_2 -> V_24 &&
V_78 -> V_90 > V_2 -> V_24 ) ) {
F_30 ( V_2 -> V_10 , L_25 , V_78 -> V_90 ) ;
return - V_102 ;
}
if ( F_109 ( V_78 -> V_260 ) < F_109 ( V_264 ) ) {
F_30 ( V_2 -> V_10 , L_26 ,
( unsigned long long ) V_78 -> V_260 ) ;
return - V_102 ;
}
V_260 = F_109 ( V_78 -> V_260 ) - F_109 ( V_264 ) ;
V_38 = ( V_78 -> V_265 << V_266 ) |
( V_78 -> V_267 << V_268 ) |
( V_78 -> V_269 << V_270 ) |
( ! ! ( V_78 -> V_271 == 16 ) << V_272 ) |
( V_260 << V_273 ) ;
if ( V_255 == V_257 ) {
V_38 |= ( V_90 << V_274 ) |
( V_259 << V_275 ) ;
F_3 ( V_2 , V_255 , V_38 ) ;
} else {
F_3 ( V_2 , V_255 , V_38 ) ;
V_38 = ( V_90 << V_276 ) |
( V_259 << V_277 ) ;
F_3 ( V_2 , V_257 , V_38 ) ;
}
V_38 = F_1 ( V_2 , V_64 ) ;
V_38 &= ~ F_21 ( V_2 ) ;
V_38 |= V_78 -> V_63 << V_54 ;
V_38 &= ~ F_19 ( V_2 ) ;
V_38 |= V_78 -> V_80 ;
F_3 ( V_2 , V_64 , V_38 ) ;
F_25 ( V_50 , V_78 -> V_79 ) ;
F_17 ( V_50 , F_50 ( V_87 -> V_94 . V_238 * 3 , 4 ) ) ;
return 0 ;
}
static void F_110 ( struct V_49 * V_50 ,
char * V_75 , struct V_77 * V_78 )
{
V_75 += sprintf ( V_75 ,
L_27 ,
( unsigned long long ) V_78 -> V_260 >> 20 ,
V_78 -> V_259 >> 10 ,
V_78 -> V_90 >= 1024 ? V_78 -> V_90 >> 10 : V_78 -> V_90 ,
V_78 -> V_90 >= 1024 ? L_28 : L_29 ,
V_78 -> V_80 , V_78 -> V_271 ) ;
if ( F_39 ( V_50 -> V_2 , V_78 ) )
sprintf ( V_75 , L_30 ) ;
else if ( V_78 -> V_79 )
sprintf ( V_75 , L_31 , V_78 -> V_63 << 1 ) ;
else
sprintf ( V_75 , L_32 , V_78 -> V_63 ) ;
}
static inline int F_111 ( T_5 V_237 , T_1 V_249 )
{
return F_112 ( F_113 ( V_237 ) - F_113 ( V_249 ) , 8 ) >> 3 ;
}
static int F_114 ( struct V_49 * V_50 )
{
struct V_81 * V_82 = F_48 ( & V_50 -> V_87 ) ;
struct V_86 * V_87 = & V_50 -> V_87 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_77 * V_78 = & V_50 -> V_62 ;
char V_278 [ 128 ] ;
T_1 V_3 , V_38 , V_279 ;
int V_106 ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_106 = F_115 ( F_116 ( V_87 ) ,
L_33 ,
& V_279 ) ;
if ( V_106 ) {
V_78 -> V_80 = V_82 -> V_227 /
( V_82 -> V_249 >> V_250 ) ;
} else {
V_78 -> V_80 = V_279 ;
}
if ( V_78 -> V_80 > V_2 -> V_27 )
V_78 -> V_80 = V_2 -> V_27 ;
V_82 -> V_227 = V_78 -> V_80 * ( V_82 -> V_249 >> V_250 ) ;
V_78 -> V_260 = V_82 -> V_237 ;
V_78 -> V_259 = V_82 -> V_280 ;
V_78 -> V_90 = V_82 -> V_249 ;
V_78 -> V_271 = ( V_87 -> V_281 & V_282 ) ? 16 : 8 ;
V_78 -> V_267 = 2 ;
V_78 -> V_265 = F_111 ( V_82 -> V_237 , V_82 -> V_249 ) ;
if ( V_87 -> V_94 . V_283 != V_284 ) {
F_6 ( V_2 -> V_10 , L_34 ,
V_87 -> V_94 . V_283 ) ;
return - V_102 ;
}
if ( V_87 -> V_94 . V_285 == V_286 ) {
if ( V_87 -> V_94 . V_238 == 1 && V_87 -> V_94 . V_237 == 512 )
V_87 -> V_94 . V_285 = V_287 ;
else
V_87 -> V_94 . V_285 = V_288 ;
}
if ( V_87 -> V_94 . V_285 == V_287 && ( V_87 -> V_94 . V_238 != 1 ||
V_87 -> V_94 . V_237 != 512 ) ) {
F_6 ( V_2 -> V_10 , L_35 ,
V_87 -> V_94 . V_238 , V_87 -> V_94 . V_237 ) ;
return - V_102 ;
}
switch ( V_87 -> V_94 . V_237 ) {
case 512 :
if ( V_87 -> V_94 . V_285 == V_287 )
V_78 -> V_63 = 15 ;
else
V_78 -> V_63 = V_87 -> V_94 . V_238 ;
V_78 -> V_79 = 0 ;
break;
case 1024 :
if ( ! ( V_2 -> V_28 & V_31 ) ) {
F_6 ( V_2 -> V_10 , L_36 ) ;
return - V_102 ;
}
if ( V_87 -> V_94 . V_238 & 0x1 ) {
F_6 ( V_2 -> V_10 ,
L_37 ) ;
return - V_102 ;
}
V_78 -> V_63 = V_87 -> V_94 . V_238 >> 1 ;
V_78 -> V_79 = 1 ;
break;
default:
F_6 ( V_2 -> V_10 , L_38 ,
V_87 -> V_94 . V_237 ) ;
return - V_102 ;
}
V_78 -> V_269 = V_78 -> V_265 ;
if ( V_82 -> V_249 > 512 )
V_78 -> V_269 += V_78 -> V_267 ;
else
V_78 -> V_269 += 1 ;
V_106 = F_107 ( V_50 , V_78 ) ;
if ( V_106 )
return V_106 ;
F_22 ( V_50 , 1 ) ;
F_110 ( V_50 , V_278 , V_78 ) ;
F_102 ( V_2 -> V_10 , L_39 , V_278 ) ;
V_3 = F_15 ( V_2 , V_50 -> V_41 , V_57 ) ;
V_38 = F_1 ( V_2 , V_3 ) ;
V_38 &= ~ V_289 ;
V_38 &= ~ V_290 ;
if ( V_2 -> V_9 >= 0x0702 )
V_38 |= V_290 ;
V_38 &= ~ V_291 ;
if ( V_2 -> V_28 & V_29 ) {
if ( F_32 ( V_2 ) )
V_38 &= ~ V_292 ;
else
V_38 |= V_292 ;
}
F_3 ( V_2 , V_3 , V_38 ) ;
return 0 ;
}
static int F_117 ( struct V_49 * V_50 , struct V_293 * V_294 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_295 * V_101 = V_50 -> V_101 ;
struct V_81 * V_82 ;
struct V_86 * V_87 ;
int V_106 ;
T_2 V_255 ;
V_106 = F_115 ( V_294 , L_40 , & V_50 -> V_41 ) ;
if ( V_106 ) {
F_6 ( & V_101 -> V_10 , L_41 ) ;
return - V_296 ;
}
V_82 = F_48 ( & V_50 -> V_87 ) ;
V_87 = & V_50 -> V_87 ;
F_118 ( V_87 , V_294 ) ;
F_119 ( V_87 , V_50 ) ;
V_82 -> V_297 = F_120 ( & V_101 -> V_10 , V_298 , L_42 ,
V_50 -> V_41 ) ;
V_82 -> V_299 = V_300 ;
V_82 -> V_10 . V_301 = & V_101 -> V_10 ;
V_87 -> V_302 = ( void V_303 * ) 0xdeadbeef ;
V_87 -> V_304 = ( void V_303 * ) 0xdeadbeef ;
V_87 -> V_305 = F_68 ;
V_87 -> V_109 = F_72 ;
V_87 -> V_306 = F_69 ;
V_87 -> V_307 = F_77 ;
V_87 -> V_308 = F_78 ;
V_87 -> V_309 = F_79 ;
V_87 -> V_94 . V_283 = V_284 ;
V_87 -> V_94 . V_310 = F_96 ;
V_87 -> V_94 . V_311 = F_103 ;
V_87 -> V_94 . V_236 = F_97 ;
V_87 -> V_94 . V_312 = F_104 ;
V_87 -> V_94 . V_313 = F_106 ;
V_87 -> V_94 . V_314 = F_99 ;
V_87 -> V_94 . V_315 = F_98 ;
V_87 -> V_94 . V_316 = F_105 ;
V_87 -> V_317 = & V_2 -> V_317 ;
V_255 = F_15 ( V_2 , V_50 -> V_41 , V_256 ) ;
F_3 ( V_2 , V_255 ,
F_1 ( V_2 , V_255 ) & ~ V_318 ) ;
V_106 = F_121 ( V_82 , 1 , NULL ) ;
if ( V_106 )
return V_106 ;
V_87 -> V_281 |= V_319 ;
V_87 -> V_281 |= V_320 ;
if ( V_87 -> V_321 & V_322 )
V_87 -> V_321 |= V_323 ;
if ( F_114 ( V_50 ) )
return - V_296 ;
V_87 -> V_94 . V_237 = V_50 -> V_62 . V_79 ? 1024 : 512 ;
V_82 -> V_247 = 1 ;
V_106 = F_47 ( V_50 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_122 ( V_82 ) ;
if ( V_106 )
return V_106 ;
return F_123 ( V_82 , NULL , 0 ) ;
}
static void F_124 ( struct V_49 * V_50 ,
int V_324 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_2 V_255 = F_15 ( V_2 , V_50 -> V_41 , V_256 ) ;
T_2 V_257 = F_15 ( V_2 , V_50 -> V_41 ,
V_258 ) ;
T_2 V_64 = F_15 ( V_2 , V_50 -> V_41 ,
V_57 ) ;
T_2 V_325 = F_15 ( V_2 , V_50 -> V_41 , V_326 ) ;
T_2 V_327 = F_15 ( V_2 , V_50 -> V_41 , V_328 ) ;
if ( V_324 ) {
F_3 ( V_2 , V_255 , V_50 -> V_62 . V_329 ) ;
if ( V_255 != V_257 )
F_3 ( V_2 , V_257 ,
V_50 -> V_62 . V_330 ) ;
F_3 ( V_2 , V_64 , V_50 -> V_62 . V_58 ) ;
F_3 ( V_2 , V_325 , V_50 -> V_62 . V_331 ) ;
F_3 ( V_2 , V_327 , V_50 -> V_62 . V_332 ) ;
} else {
V_50 -> V_62 . V_329 = F_1 ( V_2 , V_255 ) ;
if ( V_255 != V_257 )
V_50 -> V_62 . V_330 =
F_1 ( V_2 , V_257 ) ;
V_50 -> V_62 . V_58 = F_1 ( V_2 , V_64 ) ;
V_50 -> V_62 . V_331 = F_1 ( V_2 , V_325 ) ;
V_50 -> V_62 . V_332 = F_1 ( V_2 , V_327 ) ;
}
}
static int F_125 ( struct V_333 * V_10 )
{
struct V_1 * V_2 = F_126 ( V_10 ) ;
struct V_49 * V_50 ;
F_127 (host, &ctrl->host_list, node)
F_124 ( V_50 , 0 ) ;
V_2 -> V_334 = F_8 ( V_2 , V_73 ) ;
V_2 -> V_335 = F_8 ( V_2 , V_336 ) ;
V_2 -> V_337 =
F_8 ( V_2 , V_52 ) ;
if ( F_32 ( V_2 ) )
V_2 -> V_338 = F_38 ( V_2 , V_339 ) ;
return 0 ;
}
static int F_128 ( struct V_333 * V_10 )
{
struct V_1 * V_2 = F_126 ( V_10 ) ;
struct V_49 * V_50 ;
if ( F_32 ( V_2 ) ) {
F_37 ( V_2 , V_339 , V_2 -> V_338 ) ;
F_37 ( V_2 , V_208 , 0 ) ;
}
F_9 ( V_2 , V_73 , V_2 -> V_334 ) ;
F_9 ( V_2 , V_336 , V_2 -> V_335 ) ;
F_9 ( V_2 , V_52 ,
V_2 -> V_337 ) ;
if ( V_2 -> V_129 ) {
V_2 -> V_129 -> V_130 ( V_2 -> V_129 ) ;
V_2 -> V_129 -> V_340 ( V_2 -> V_129 , true ) ;
}
F_127 (host, &ctrl->host_list, node) {
struct V_86 * V_87 = & V_50 -> V_87 ;
struct V_81 * V_82 = F_48 ( V_87 ) ;
F_124 ( V_50 , 1 ) ;
V_87 -> V_109 ( V_82 , V_167 , - 1 , - 1 ) ;
}
return 0 ;
}
int F_129 ( struct V_295 * V_101 , struct V_341 * V_129 )
{
struct V_333 * V_10 = & V_101 -> V_10 ;
struct V_293 * V_294 = V_10 -> V_33 , * V_342 ;
struct V_1 * V_2 ;
struct V_343 * V_344 ;
int V_106 ;
if ( ! V_294 )
return - V_11 ;
if ( ! F_130 ( V_345 , V_294 ) )
return - V_11 ;
V_2 = F_131 ( V_10 , sizeof( * V_2 ) , V_298 ) ;
if ( ! V_2 )
return - V_214 ;
F_132 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
F_133 ( & V_2 -> V_128 ) ;
F_133 ( & V_2 -> V_132 ) ;
F_134 ( & V_2 -> V_317 ) ;
F_135 ( & V_2 -> V_346 ) ;
V_344 = F_136 ( V_101 , V_347 , 0 ) ;
V_2 -> V_4 = F_137 ( V_10 , V_344 ) ;
if ( F_138 ( V_2 -> V_4 ) )
return F_139 ( V_2 -> V_4 ) ;
V_2 -> V_348 = F_140 ( V_10 , L_43 ) ;
if ( ! F_138 ( V_2 -> V_348 ) ) {
V_106 = F_141 ( V_2 -> V_348 ) ;
if ( V_106 )
return V_106 ;
} else {
V_106 = F_139 ( V_2 -> V_348 ) ;
if ( V_106 == - V_349 )
return V_106 ;
V_2 -> V_348 = NULL ;
}
V_106 = F_5 ( V_2 ) ;
if ( V_106 )
goto V_239;
V_344 = F_142 ( V_101 , V_347 , L_44 ) ;
if ( V_344 ) {
V_2 -> V_40 = F_137 ( V_10 , V_344 ) ;
if ( F_138 ( V_2 -> V_40 ) ) {
V_106 = F_139 ( V_2 -> V_40 ) ;
goto V_239;
}
} else {
V_2 -> V_40 = V_2 -> V_4 +
V_2 -> V_12 [ V_350 ] ;
}
V_344 = F_142 ( V_101 , V_347 , L_45 ) ;
if ( V_344 ) {
V_2 -> V_74 = F_137 ( V_10 , V_344 ) ;
if ( F_138 ( V_2 -> V_74 ) ) {
V_106 = F_139 ( V_2 -> V_74 ) ;
goto V_239;
}
F_37 ( V_2 , V_339 , 1 ) ;
F_37 ( V_2 , V_208 , 0 ) ;
V_2 -> V_215 = F_143 ( V_10 ,
sizeof( * V_2 -> V_215 ) ,
& V_2 -> V_216 , V_298 ) ;
if ( ! V_2 -> V_215 ) {
V_106 = - V_214 ;
goto V_239;
}
V_2 -> V_351 = F_144 ( V_101 , 1 ) ;
if ( ( int ) V_2 -> V_351 < 0 ) {
F_6 ( V_10 , L_46 ) ;
V_106 = - V_11 ;
goto V_239;
}
V_106 = F_145 ( V_10 , V_2 -> V_351 ,
F_63 , 0 , V_352 ,
V_2 ) ;
if ( V_106 < 0 ) {
F_6 ( V_10 , L_47 ,
V_2 -> V_351 , V_106 ) ;
goto V_239;
}
F_102 ( V_10 , L_48 ) ;
}
F_10 ( V_2 , V_73 ,
V_353 | 0xff , 0 , 0 ) ;
F_10 ( V_2 , V_336 , 0xff , 0 , 0 ) ;
if ( V_2 -> V_28 & V_32 ) {
if ( V_104 == 2 )
F_31 ( V_2 , false ) ;
} else {
V_104 = 0 ;
}
V_2 -> V_125 = F_144 ( V_101 , 0 ) ;
if ( ( int ) V_2 -> V_125 < 0 ) {
F_6 ( V_10 , L_49 ) ;
V_106 = - V_11 ;
goto V_239;
}
if ( V_129 ) {
V_2 -> V_129 = V_129 ;
V_106 = F_145 ( V_10 , V_2 -> V_125 , F_62 , 0 ,
V_352 , V_2 ) ;
V_2 -> V_129 -> V_130 ( V_2 -> V_129 ) ;
V_2 -> V_129 -> V_340 ( V_2 -> V_129 , true ) ;
} else {
V_106 = F_145 ( V_10 , V_2 -> V_125 , F_60 , 0 ,
V_352 , V_2 ) ;
}
if ( V_106 < 0 ) {
F_6 ( V_10 , L_47 ,
V_2 -> V_125 , V_106 ) ;
goto V_239;
}
F_146 (dn, child) {
if ( F_147 ( V_342 , L_50 ) ) {
struct V_49 * V_50 ;
V_50 = F_131 ( V_10 , sizeof( * V_50 ) , V_298 ) ;
if ( ! V_50 ) {
F_148 ( V_342 ) ;
V_106 = - V_214 ;
goto V_239;
}
V_50 -> V_101 = V_101 ;
V_50 -> V_2 = V_2 ;
V_106 = F_117 ( V_50 , V_342 ) ;
if ( V_106 ) {
F_149 ( V_10 , V_50 ) ;
continue;
}
F_150 ( & V_50 -> V_354 , & V_2 -> V_346 ) ;
}
}
if ( F_151 ( & V_2 -> V_346 ) ) {
V_106 = - V_11 ;
goto V_239;
}
return 0 ;
V_239:
F_152 ( V_2 -> V_348 ) ;
return V_106 ;
}
int F_153 ( struct V_295 * V_101 )
{
struct V_1 * V_2 = F_126 ( & V_101 -> V_10 ) ;
struct V_49 * V_50 ;
F_127 (host, &ctrl->host_list, node)
F_154 ( F_48 ( & V_50 -> V_87 ) ) ;
F_152 ( V_2 -> V_348 ) ;
F_132 ( & V_101 -> V_10 , NULL ) ;
return 0 ;
}
