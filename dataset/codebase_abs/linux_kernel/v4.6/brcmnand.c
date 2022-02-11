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
if ( V_2 -> V_9 >= 0x0701 )
V_2 -> V_12 = V_13 ;
else if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_12 = V_14 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_12 = V_15 ;
else if ( V_2 -> V_9 >= 0x0400 )
V_2 -> V_12 = V_16 ;
if ( V_2 -> V_9 >= 0x0701 )
V_2 -> V_17 = 0x14 ;
else
V_2 -> V_17 = 0x10 ;
if ( V_2 -> V_9 >= 0x0701 ) {
V_2 -> V_18 = V_19 ;
} else {
V_2 -> V_18 = V_20 ;
if ( V_2 -> V_9 <= 0x0500 )
V_2 -> V_21 = V_22 ;
}
if ( V_2 -> V_9 >= 0x0701 ) {
V_2 -> V_23 = 16 * 1024 ;
V_2 -> V_24 = 2 * 1024 * 1024 ;
} else {
V_2 -> V_8 = V_8 ;
if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_25 = V_6 ;
else
V_2 -> V_25 = V_7 ;
if ( V_2 -> V_9 < 0x0400 ) {
V_2 -> V_23 = 4096 ;
V_2 -> V_24 = 512 * 1024 ;
}
}
if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_26 = 64 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_26 = 32 ;
else
V_2 -> V_26 = 16 ;
if ( V_2 -> V_9 >= 0x0600 && V_2 -> V_9 != 0x0601 )
V_2 -> V_27 |= V_28 ;
if ( V_2 -> V_9 >= 0x0700 )
V_2 -> V_27 |= V_29 ;
if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_27 |= V_30 ;
if ( V_2 -> V_9 >= 0x0700 )
V_2 -> V_27 |= V_31 ;
else if ( F_7 ( V_2 -> V_10 -> V_32 , L_2 ) )
V_2 -> V_27 |= V_31 ;
return 0 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
enum V_33 V_34 )
{
T_2 V_3 = V_2 -> V_12 [ V_34 ] ;
if ( V_3 )
return F_1 ( V_2 , V_3 ) ;
else
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 ,
enum V_33 V_34 , T_1 V_5 )
{
T_2 V_3 = V_2 -> V_12 [ V_34 ] ;
if ( V_3 )
F_3 ( V_2 , V_3 , V_5 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
enum V_33 V_34 , T_1 V_35 , unsigned
int V_36 , T_1 V_5 )
{
T_1 V_37 = F_8 ( V_2 , V_34 ) ;
V_37 &= ~ V_35 ;
V_37 |= V_5 << V_36 ;
F_9 ( V_2 , V_34 , V_37 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , int V_38 )
{
return F_12 ( V_2 -> V_39 + V_38 * 4 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
int V_38 , T_1 V_5 )
{
F_14 ( V_5 , V_2 -> V_39 + V_38 * 4 ) ;
}
static inline T_2 F_15 ( struct V_1 * V_2 , int V_40 ,
enum V_41 V_34 )
{
T_2 V_42 = V_2 -> V_12 [ V_43 ] ;
T_2 V_44 = V_2 -> V_12 [ V_45 ] ;
T_3 V_46 ;
if ( V_40 == 0 && V_2 -> V_21 )
V_46 = V_2 -> V_21 [ V_34 ] ;
else
V_46 = V_2 -> V_18 [ V_34 ] ;
if ( V_40 && V_44 )
return V_44 + ( V_40 - 1 ) * V_2 -> V_17 + V_46 ;
return V_42 + V_40 * V_2 -> V_17 + V_46 ;
}
static inline T_1 F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 < 0x0600 )
return 1 ;
return F_8 ( V_2 , V_47 ) ;
}
static void F_17 ( struct V_48 * V_49 , T_3 V_5 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
unsigned int V_36 = 0 , V_50 ;
enum V_33 V_34 = V_51 ;
int V_40 = V_49 -> V_40 ;
if ( V_2 -> V_9 >= 0x0600 )
V_50 = 6 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_50 = 5 ;
else
V_50 = 4 ;
if ( V_2 -> V_9 >= 0x0600 ) {
if ( V_40 >= 5 )
V_34 = V_52 ;
V_36 = ( V_40 % 5 ) * V_50 ;
}
F_10 ( V_2 , V_34 , ( V_50 - 1 ) << V_36 , V_36 , V_5 ) ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 < 0x0700 )
return 24 ;
return 0 ;
}
static inline T_1 F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 >= 0x0600 )
return F_20 ( 6 , 0 ) ;
else
return F_20 ( 5 , 0 ) ;
}
static inline T_1 F_21 ( struct V_1 * V_2 )
{
T_1 V_35 = ( V_2 -> V_9 >= 0x0600 ) ? 0x1f : 0x0f ;
return V_35 << V_53 ;
}
static void F_22 ( struct V_48 * V_49 , int V_54 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_2 V_3 = F_15 ( V_2 , V_49 -> V_40 , V_55 ) ;
T_1 V_56 = F_1 ( V_2 , V_3 ) ;
T_1 V_57 = V_58 | V_59 ;
if ( V_54 ) {
V_56 |= V_57 ;
V_56 |= V_49 -> V_60 . V_61
<< V_53 ;
} else {
V_56 &= ~ V_57 ;
V_56 &= ~ F_21 ( V_2 ) ;
}
F_3 ( V_2 , V_3 , V_56 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 >= 0x0600 )
return 7 ;
else if ( V_2 -> V_9 >= 0x0500 )
return 6 ;
else
return - 1 ;
}
static int F_24 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
int V_36 = F_23 ( V_2 ) ;
T_2 V_62 = F_15 ( V_2 , V_49 -> V_40 ,
V_55 ) ;
if ( V_36 < 0 )
return 0 ;
return ( F_1 ( V_2 , V_62 ) >> V_36 ) & 0x1 ;
}
static void F_25 ( struct V_48 * V_49 , int V_5 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
int V_36 = F_23 ( V_2 ) ;
T_2 V_62 = F_15 ( V_2 , V_49 -> V_40 ,
V_55 ) ;
T_1 V_37 ;
if ( V_36 < 0 )
return;
V_37 = F_1 ( V_2 , V_62 ) ;
V_37 &= ~ ( 1 << V_36 ) ;
V_37 |= ( ! ! V_5 ) << V_36 ;
F_3 ( V_2 , V_62 , V_37 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , bool V_54 )
{
T_1 V_5 = V_54 ? V_63 : 0 ;
F_10 ( V_2 , V_64 , V_63 , 0 , V_5 ) ;
}
static inline bool F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_65 ;
}
static inline bool F_28 ( const void * V_66 )
{
return V_66 && ! F_29 ( V_66 ) &&
F_30 ( F_31 ( ( V_67 ) V_66 , 4 ) ) ;
}
static inline void F_32 ( struct V_1 * V_2 , T_3 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_65 + V_3 ) ;
}
static inline T_1 F_33 ( struct V_1 * V_2 , T_3 V_3 )
{
return F_2 ( V_2 -> V_65 + V_3 ) ;
}
static inline bool F_34 ( struct V_68 * V_69 )
{
return V_69 -> V_70 == 0 && V_69 -> V_71 == 16 &&
V_69 -> V_61 == 15 ;
}
static struct V_72 * F_35 ( int V_61 ,
struct V_48 * V_49 )
{
struct V_68 * V_69 = & V_49 -> V_60 ;
int V_73 , V_74 ;
struct V_72 * V_75 ;
int V_76 ;
int V_77 ;
int V_78 ;
int V_79 , V_80 ;
V_75 = F_36 ( & V_49 -> V_81 -> V_10 , sizeof( * V_75 ) , V_82 ) ;
if ( ! V_75 )
return NULL ;
V_77 = V_69 -> V_83 / ( 512 << V_69 -> V_70 ) ;
V_78 = V_69 -> V_71 << V_69 -> V_70 ;
if ( F_34 ( V_69 ) ) {
for ( V_73 = 0 , V_79 = 0 , V_80 = 0 ; V_73 < V_77 ; V_73 ++ ) {
if ( V_73 == 0 ) {
V_75 -> V_84 [ V_80 ] . V_85 = V_73 * V_78 + 1 ;
if ( V_69 -> V_83 == 512 )
V_75 -> V_84 [ V_80 ] . V_85 -- ;
V_75 -> V_84 [ V_80 ] . V_86 = 5 ;
} else {
V_75 -> V_84 [ V_80 ] . V_85 = V_73 * V_78 ;
V_75 -> V_84 [ V_80 ] . V_86 = 6 ;
}
V_80 ++ ;
V_75 -> V_87 [ V_79 ++ ] = V_73 * V_78 + 6 ;
V_75 -> V_87 [ V_79 ++ ] = V_73 * V_78 + 7 ;
V_75 -> V_87 [ V_79 ++ ] = V_73 * V_78 + 8 ;
V_75 -> V_84 [ V_80 ] . V_85 = V_73 * V_78 + 9 ;
V_75 -> V_84 [ V_80 ] . V_86 = 7 ;
V_80 ++ ;
if ( V_79 >= V_88 ||
V_80 >= V_89 - 1 )
break;
}
return V_75 ;
}
V_76 = F_37 ( V_61 * 14 , 8 ) ;
if ( V_76 >= V_78 ) {
F_6 ( & V_49 -> V_81 -> V_10 ,
L_3 ,
V_76 , V_78 ) ;
return NULL ;
}
V_75 -> V_90 = V_76 * V_77 ;
for ( V_73 = 0 , V_79 = 0 , V_80 = 0 ; V_73 < V_77 ; V_73 ++ ) {
for ( V_74 = V_78 - V_76 ; V_74 < V_78 && V_79 <
V_88 ; V_74 ++ , V_79 ++ )
V_75 -> V_87 [ V_79 ] = V_73 * V_78 + V_74 ;
if ( V_73 == 0 ) {
if ( V_69 -> V_83 == 512 && ( V_78 - V_76 >= 6 ) ) {
V_75 -> V_84 [ V_80 ] . V_85 = 0 ;
V_75 -> V_84 [ V_80 ] . V_86 = 5 ;
V_80 ++ ;
if ( V_78 - V_76 > 6 ) {
V_75 -> V_84 [ V_80 ] . V_85 = 6 ;
V_75 -> V_84 [ V_80 ] . V_86 =
V_78 - V_76 - 6 ;
V_80 ++ ;
}
} else if ( V_78 > V_76 + 1 ) {
V_75 -> V_84 [ V_80 ] . V_85 = V_73 * V_78 + 1 ;
V_75 -> V_84 [ V_80 ] . V_86 = V_78 - V_76 - 1 ;
V_80 ++ ;
}
} else if ( V_78 > V_76 ) {
V_75 -> V_84 [ V_80 ] . V_85 = V_73 * V_78 ;
V_75 -> V_84 [ V_80 ] . V_86 = V_78 - V_76 ;
V_80 ++ ;
}
if ( V_79 >= V_88 ||
V_80 >= V_89 - 1 )
break;
}
return V_75 ;
}
static struct V_72 * F_38 (
struct V_48 * V_49 )
{
struct V_72 * V_75 ;
struct V_68 * V_91 = & V_49 -> V_60 ;
unsigned int V_61 = V_91 -> V_61 ;
if ( V_91 -> V_70 )
V_61 <<= 1 ;
V_75 = F_35 ( V_61 , V_49 ) ;
if ( ! V_75 ) {
F_6 ( & V_49 -> V_81 -> V_10 ,
L_4 ) ;
return NULL ;
}
return V_75 ;
}
static void F_39 ( struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 = F_40 ( V_93 ) ;
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
if ( ( V_2 -> V_27 & V_31 ) && V_97 == 1 ) {
static int V_98 = - 1 ;
if ( V_98 != V_94 ) {
F_42 ( V_2 -> V_10 , L_5 , V_94 ? L_6 : L_7 ) ;
V_98 = V_94 ;
}
F_26 ( V_2 , V_94 ) ;
}
}
static inline T_3 F_43 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_99 , V_100 , V_101 ;
V_99 = V_2 -> V_12 [ V_102 ] ;
V_100 = V_2 -> V_12 [ V_103 ] ;
if ( V_3 >= V_2 -> V_26 )
return 0x77 ;
if ( V_3 >= 16 && V_100 )
V_101 = V_100 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_101 = V_99 + ( V_3 & ~ 0x03 ) ;
return F_1 ( V_2 , V_101 ) >> ( 24 - ( ( V_3 & 0x03 ) << 3 ) ) ;
}
static inline void F_44 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_104 )
{
T_2 V_99 , V_100 , V_101 ;
V_99 = V_2 -> V_12 [ V_105 ] ;
V_100 = V_2 -> V_12 [ V_106 ] ;
if ( V_3 >= V_2 -> V_26 )
return;
if ( V_3 >= 16 && V_100 )
V_101 = V_100 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_101 = V_99 + ( V_3 & ~ 0x03 ) ;
F_3 ( V_2 , V_101 , V_104 ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_73 , T_3 * V_107 ,
int V_78 , int V_108 )
{
int V_109 = V_78 << V_108 ;
int V_74 ;
if ( V_108 && ( V_73 & 0x01 ) )
V_109 = F_46 ( 0 , V_109 - ( int ) V_2 -> V_26 ) ;
V_109 = F_47 ( int , V_109 , V_2 -> V_26 ) ;
for ( V_74 = 0 ; V_74 < V_109 ; V_74 ++ )
V_107 [ V_74 ] = F_43 ( V_2 , V_74 ) ;
return V_109 ;
}
static int F_48 ( struct V_1 * V_2 , int V_73 ,
const T_3 * V_107 , int V_78 , int V_108 )
{
int V_109 = V_78 << V_108 ;
int V_74 ;
if ( V_108 && ( V_73 & 0x01 ) )
V_109 = F_46 ( 0 , V_109 - ( int ) V_2 -> V_26 ) ;
V_109 = F_47 ( int , V_109 , V_2 -> V_26 ) ;
for ( V_74 = 0 ; V_74 < V_109 ; V_74 += 4 )
F_44 ( V_2 , V_74 ,
( V_107 [ V_74 + 0 ] << 24 ) |
( V_107 [ V_74 + 1 ] << 16 ) |
( V_107 [ V_74 + 2 ] << 8 ) |
( V_107 [ V_74 + 3 ] << 0 ) ) ;
return V_109 ;
}
static T_4 F_49 ( int V_110 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
if ( V_2 -> V_111 )
return V_112 ;
F_50 ( & V_2 -> V_113 ) ;
return V_112 ;
}
static T_4 F_51 ( int V_110 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
if ( V_2 -> V_114 -> V_115 ( V_2 -> V_114 ) )
return F_49 ( V_110 , V_104 ) ;
return V_116 ;
}
static T_4 F_52 ( int V_110 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
F_50 ( & V_2 -> V_117 ) ;
return V_112 ;
}
static void F_53 ( struct V_48 * V_49 , int V_118 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_119 ;
F_42 ( V_2 -> V_10 , L_8 , V_118 ,
F_8 ( V_2 , V_120 ) ) ;
F_54 ( V_2 -> V_121 != 0 ) ;
V_2 -> V_121 = V_118 ;
V_119 = F_8 ( V_2 , V_122 ) ;
F_54 ( ! ( V_119 & V_123 ) ) ;
F_55 () ;
F_9 ( V_2 , V_124 ,
V_118 << F_18 ( V_2 ) ) ;
}
static void F_56 ( struct V_92 * V_93 , int V_125 ,
unsigned int V_2 )
{
}
static int F_57 ( struct V_92 * V_93 , struct V_95 * V_126 )
{
struct V_95 * V_96 = F_40 ( V_93 ) ;
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
unsigned long V_127 = F_58 ( 100 ) ;
F_42 ( V_2 -> V_10 , L_9 , V_2 -> V_121 ) ;
if ( V_2 -> V_121 &&
F_59 ( & V_2 -> V_113 , V_127 ) <= 0 ) {
T_1 V_118 = F_8 ( V_2 , V_124 )
>> F_18 ( V_2 ) ;
F_60 ( V_2 -> V_10 ,
L_10 , V_118 ) ;
F_60 ( V_2 -> V_10 , L_11 ,
F_8 ( V_2 , V_122 ) ) ;
}
V_2 -> V_121 = 0 ;
return F_8 ( V_2 , V_122 ) &
V_128 ;
}
static int F_61 ( struct V_48 * V_49 ,
enum V_129 type , T_1 V_104 ,
bool V_130 )
{
struct V_92 * V_93 = F_62 ( & V_49 -> V_96 ) ;
struct V_95 * V_96 = & V_49 -> V_96 ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_37 ;
V_37 = V_104 & V_131 ;
switch ( type ) {
case V_132 :
V_37 |= V_133 | V_134 ;
break;
case V_135 :
V_37 |= V_133 | V_136 ;
break;
case V_137 :
V_37 |= V_133 ;
break;
case V_138 :
V_37 |= V_139 ;
break;
}
if ( V_130 )
V_37 |= V_140 ;
F_42 ( V_2 -> V_10 , L_12 , V_37 ) ;
F_9 ( V_2 , V_141 , V_37 ) ;
( void ) F_8 ( V_2 , V_141 ) ;
F_53 ( V_49 , V_142 ) ;
return F_57 ( V_93 , V_96 ) ;
}
static void F_63 ( struct V_92 * V_93 , unsigned V_143 ,
int V_144 , int V_145 )
{
struct V_95 * V_96 = F_40 ( V_93 ) ;
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_5 V_146 = ( T_5 ) V_145 << V_96 -> V_147 ;
int V_148 = 0 ;
if ( V_143 == V_149 || V_143 == V_150 ||
V_143 == V_151 )
V_146 = ( T_5 ) V_144 ;
else if ( V_145 < 0 )
V_146 = 0 ;
F_42 ( V_2 -> V_10 , L_13 , V_143 ,
( unsigned long long ) V_146 ) ;
V_49 -> V_152 = V_143 ;
V_49 -> V_153 = 0 ;
V_49 -> V_154 = V_146 ;
switch ( V_143 ) {
case V_155 :
V_148 = V_156 ;
break;
case V_157 :
V_148 = V_158 ;
break;
case V_149 :
V_148 = V_159 ;
break;
case V_160 :
V_148 = V_161 ;
break;
case V_162 :
V_148 = V_163 ;
F_39 ( V_93 , 0 ) ;
break;
case V_150 :
V_148 = V_164 ;
break;
case V_165 :
case V_166 :
F_61 ( V_49 , V_132 , V_143 , false ) ;
F_61 ( V_49 , V_135 , V_144 , false ) ;
break;
case V_151 :
V_148 = V_167 ;
V_146 &= ~ ( ( T_5 ) ( V_168 - 1 ) ) ;
if ( F_24 ( V_49 ) ) {
V_49 -> V_60 . V_70 =
F_24 ( V_49 ) ;
F_25 ( V_49 , 0 ) ;
}
break;
}
if ( ! V_148 )
return;
F_9 ( V_2 , V_169 ,
( V_49 -> V_40 << 16 ) | ( ( V_146 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_169 ) ;
F_9 ( V_2 , V_120 , F_64 ( V_146 ) ) ;
( void ) F_8 ( V_2 , V_120 ) ;
F_53 ( V_49 , V_148 ) ;
F_57 ( V_93 , V_96 ) ;
if ( V_148 == V_164 ||
V_148 == V_167 ) {
T_1 * V_170 = ( T_1 * ) V_2 -> V_170 ;
int V_73 ;
F_65 ( V_2 -> V_114 ) ;
for ( V_73 = 0 ; V_73 < V_171 ; V_73 ++ )
V_170 [ V_73 ] = F_66 ( F_11 ( V_2 , V_73 ) ) ;
F_67 ( V_2 -> V_114 ) ;
if ( V_49 -> V_60 . V_70 )
F_25 ( V_49 ,
V_49 -> V_60 . V_70 ) ;
}
if ( V_143 == V_162 )
F_39 ( V_93 , 1 ) ;
}
static T_6 F_68 ( struct V_92 * V_93 )
{
struct V_95 * V_96 = F_40 ( V_93 ) ;
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_6 V_172 = 0 ;
int V_146 , V_3 ;
switch ( V_49 -> V_152 ) {
case V_149 :
if ( V_49 -> V_153 < 4 )
V_172 = F_8 ( V_2 , V_173 ) >>
( 24 - ( V_49 -> V_153 << 3 ) ) ;
else if ( V_49 -> V_153 < 8 )
V_172 = F_8 ( V_2 , V_174 ) >>
( 56 - ( V_49 -> V_153 << 3 ) ) ;
break;
case V_160 :
V_172 = F_43 ( V_2 , V_49 -> V_153 ) ;
break;
case V_157 :
V_172 = F_8 ( V_2 , V_122 ) &
V_128 ;
if ( V_97 )
V_172 |= V_175 ;
break;
case V_150 :
case V_151 :
V_146 = V_49 -> V_154 + V_49 -> V_153 ;
V_3 = V_146 & ( V_168 - 1 ) ;
if ( V_49 -> V_153 > 0 && V_3 == 0 )
V_96 -> V_176 ( V_93 , V_151 , V_146 , - 1 ) ;
V_172 = V_2 -> V_170 [ V_3 ] ;
break;
case V_166 :
if ( V_49 -> V_153 >= V_177 ) {
V_172 = 0 ;
} else {
bool V_178 = V_49 -> V_153 ==
V_177 - 1 ;
F_61 ( V_49 , V_138 , 0 , V_178 ) ;
V_172 = F_8 ( V_2 , V_179 ) & 0xff ;
}
}
F_42 ( V_2 -> V_10 , L_14 , V_172 ) ;
V_49 -> V_153 ++ ;
return V_172 ;
}
static void F_69 ( struct V_92 * V_93 , T_6 * V_66 , int V_180 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_180 ; V_73 ++ , V_66 ++ )
* V_66 = F_68 ( V_93 ) ;
}
static void F_70 ( struct V_92 * V_93 , const T_6 * V_66 ,
int V_180 )
{
int V_73 ;
struct V_95 * V_96 = F_40 ( V_93 ) ;
struct V_48 * V_49 = F_41 ( V_96 ) ;
switch ( V_49 -> V_152 ) {
case V_165 :
for ( V_73 = 0 ; V_73 < V_180 ; V_73 ++ )
F_61 ( V_49 , V_137 , V_66 [ V_73 ] ,
( V_73 + 1 ) == V_180 ) ;
break;
default:
F_71 () ;
break;
}
}
static int F_72 ( struct V_48 * V_49 ,
struct V_181 * V_182 , T_5 V_146 ,
T_7 V_66 , T_1 V_180 , T_3 V_183 ,
bool V_184 , bool V_185 ,
T_7 V_186 )
{
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_186 = F_64 ( V_186 ) ;
V_182 -> V_187 = F_73 ( V_186 ) ;
V_182 -> V_188 = ( V_183 << 24 ) |
( V_185 ? ( 0x03 << 8 ) : 0 ) |
( ! ! V_184 ) | ( ( ! ! V_185 ) << 1 ) ;
#ifdef F_74
V_182 -> V_188 |= 0x01 << 12 ;
#endif
V_182 -> V_189 = F_64 ( V_66 ) ;
V_182 -> V_190 = F_73 ( V_66 ) ;
V_182 -> V_191 = V_180 ;
V_182 -> V_192 = V_180 ;
V_182 -> V_193 = F_64 ( V_146 ) ;
V_182 -> V_194 = F_73 ( V_146 ) ;
V_182 -> V_40 = V_49 -> V_40 ;
V_182 -> V_195 = 0x01 ;
return 0 ;
}
static void F_75 ( struct V_48 * V_49 , T_7 V_182 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
unsigned long V_127 = F_58 ( 100 ) ;
F_32 ( V_2 , V_196 , F_64 ( V_182 ) ) ;
( void ) F_33 ( V_2 , V_196 ) ;
F_32 ( V_2 , V_197 , F_73 ( V_182 ) ) ;
( void ) F_33 ( V_2 , V_197 ) ;
V_2 -> V_111 = true ;
F_55 () ;
F_32 ( V_2 , V_198 , 0x03 ) ;
if ( F_59 ( & V_2 -> V_117 , V_127 ) <= 0 ) {
F_6 ( V_2 -> V_10 ,
L_15 ,
F_33 ( V_2 , V_199 ) ,
F_33 ( V_2 , V_200 ) ) ;
}
V_2 -> V_111 = false ;
F_32 ( V_2 , V_198 , 0 ) ;
}
static int F_76 ( struct V_48 * V_49 , T_5 V_146 , T_1 * V_66 ,
T_1 V_180 , T_3 V_183 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_7 V_201 ;
int V_202 = V_183 == V_203 ? V_204 : V_205 ;
V_201 = F_77 ( V_2 -> V_10 , V_66 , V_180 , V_202 ) ;
if ( F_78 ( V_2 -> V_10 , V_201 ) ) {
F_6 ( V_2 -> V_10 , L_16 ) ;
return - V_206 ;
}
F_72 ( V_49 , V_2 -> V_207 , V_146 , V_201 , V_180 ,
V_183 , true , true , 0 ) ;
F_75 ( V_49 , V_2 -> V_208 ) ;
F_79 ( V_2 -> V_10 , V_201 , V_180 , V_202 ) ;
if ( V_2 -> V_207 -> V_195 & V_209 )
return - V_210 ;
else if ( V_2 -> V_207 -> V_195 & V_211 )
return - V_212 ;
return 0 ;
}
static int F_80 ( struct V_92 * V_93 , struct V_95 * V_96 ,
T_5 V_146 , unsigned int V_213 , T_1 * V_66 ,
T_3 * V_107 , T_5 * V_214 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
int V_73 , V_74 , V_172 = 0 ;
F_9 ( V_2 , V_215 , 0 ) ;
F_9 ( V_2 , V_216 , 0 ) ;
F_9 ( V_2 , V_217 , 0 ) ;
F_9 ( V_2 , V_218 , 0 ) ;
F_9 ( V_2 , V_169 ,
( V_49 -> V_40 << 16 ) | ( ( V_146 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_169 ) ;
for ( V_73 = 0 ; V_73 < V_213 ; V_73 ++ , V_146 += V_168 ) {
F_9 ( V_2 , V_120 ,
F_64 ( V_146 ) ) ;
( void ) F_8 ( V_2 , V_120 ) ;
F_53 ( V_49 , V_203 ) ;
F_57 ( V_93 , V_96 ) ;
if ( F_30 ( V_66 ) ) {
F_65 ( V_2 -> V_114 ) ;
for ( V_74 = 0 ; V_74 < V_171 ; V_74 ++ , V_66 ++ )
* V_66 = F_11 ( V_2 , V_74 ) ;
F_67 ( V_2 -> V_114 ) ;
}
if ( V_107 )
V_107 += F_45 ( V_2 , V_73 , V_107 ,
V_93 -> V_219 / V_213 ,
V_49 -> V_60 . V_70 ) ;
if ( ! V_172 ) {
* V_214 = F_8 ( V_2 ,
V_215 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_217 )
& 0xffff ) << 32 ) ;
if ( * V_214 )
V_172 = - V_210 ;
}
if ( ! V_172 ) {
* V_214 = F_8 ( V_2 ,
V_216 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_218 )
& 0xffff ) << 32 ) ;
if ( * V_214 )
V_172 = - V_212 ;
}
}
return V_172 ;
}
static int F_81 ( struct V_92 * V_93 , struct V_95 * V_96 ,
T_5 V_146 , unsigned int V_213 , T_1 * V_66 , T_3 * V_107 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_5 V_214 = 0 ;
int V_220 ;
F_42 ( V_2 -> V_10 , L_17 , ( unsigned long long ) V_146 , V_66 ) ;
F_9 ( V_2 , V_221 , 0 ) ;
if ( F_27 ( V_2 ) && ! V_107 && F_28 ( V_66 ) ) {
V_220 = F_76 ( V_49 , V_146 , V_66 , V_213 * V_168 ,
V_203 ) ;
if ( V_220 ) {
if ( F_82 ( V_220 ) )
V_214 = V_146 ;
else
return - V_222 ;
}
} else {
if ( V_107 )
memset ( V_107 , 0x99 , V_93 -> V_219 ) ;
V_220 = F_80 ( V_93 , V_96 , V_146 , V_213 , V_66 ,
V_107 , & V_214 ) ;
}
if ( F_83 ( V_220 ) ) {
F_42 ( V_2 -> V_10 , L_18 ,
( unsigned long long ) V_214 ) ;
V_93 -> V_223 . V_224 ++ ;
return 0 ;
}
if ( F_84 ( V_220 ) ) {
unsigned int V_225 = F_16 ( V_2 ) ;
F_42 ( V_2 -> V_10 , L_19 ,
( unsigned long long ) V_214 ) ;
V_93 -> V_223 . V_225 += V_225 ;
return F_46 ( V_93 -> V_226 , V_225 ) ;
}
return 0 ;
}
static int F_85 ( struct V_92 * V_93 , struct V_95 * V_96 ,
T_6 * V_66 , int V_227 , int V_228 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
T_3 * V_107 = V_227 ? ( T_3 * ) V_96 -> V_229 : NULL ;
return F_81 ( V_93 , V_96 , V_49 -> V_154 ,
V_93 -> V_230 >> V_231 , ( T_1 * ) V_66 , V_107 ) ;
}
static int F_86 ( struct V_92 * V_93 , struct V_95 * V_96 ,
T_6 * V_66 , int V_227 , int V_228 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
T_3 * V_107 = V_227 ? ( T_3 * ) V_96 -> V_229 : NULL ;
int V_172 ;
F_22 ( V_49 , 0 ) ;
V_172 = F_81 ( V_93 , V_96 , V_49 -> V_154 ,
V_93 -> V_230 >> V_231 , ( T_1 * ) V_66 , V_107 ) ;
F_22 ( V_49 , 1 ) ;
return V_172 ;
}
static int F_87 ( struct V_92 * V_93 , struct V_95 * V_96 ,
int V_228 )
{
return F_81 ( V_93 , V_96 , ( T_5 ) V_228 << V_96 -> V_147 ,
V_93 -> V_230 >> V_231 ,
NULL , ( T_3 * ) V_96 -> V_229 ) ;
}
static int F_88 ( struct V_92 * V_93 , struct V_95 * V_96 ,
int V_228 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
F_22 ( V_49 , 0 ) ;
F_81 ( V_93 , V_96 , ( T_5 ) V_228 << V_96 -> V_147 ,
V_93 -> V_230 >> V_231 ,
NULL , ( T_3 * ) V_96 -> V_229 ) ;
F_22 ( V_49 , 1 ) ;
return 0 ;
}
static int F_89 ( struct V_92 * V_93 , struct V_95 * V_96 ,
T_5 V_146 , const T_1 * V_66 , T_3 * V_107 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
unsigned int V_73 , V_74 , V_213 = V_93 -> V_230 >> V_231 ;
int V_232 , V_172 = 0 ;
F_42 ( V_2 -> V_10 , L_20 , ( unsigned long long ) V_146 , V_66 ) ;
if ( F_90 ( ( unsigned long ) V_66 & 0x03 ) ) {
F_91 ( V_2 -> V_10 , L_21 , V_66 ) ;
V_66 = ( T_1 * ) ( ( unsigned long ) V_66 & ~ 0x03 ) ;
}
F_39 ( V_93 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_26 ; V_73 += 4 )
F_44 ( V_2 , V_73 , 0xffffffff ) ;
if ( F_27 ( V_2 ) && ! V_107 && F_28 ( V_66 ) ) {
if ( F_76 ( V_49 , V_146 , ( T_1 * ) V_66 ,
V_93 -> V_230 , V_233 ) )
V_172 = - V_222 ;
goto V_234;
}
F_9 ( V_2 , V_169 ,
( V_49 -> V_40 << 16 ) | ( ( V_146 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_169 ) ;
for ( V_73 = 0 ; V_73 < V_213 ; V_73 ++ , V_146 += V_168 ) {
F_9 ( V_2 , V_120 ,
F_64 ( V_146 ) ) ;
( void ) F_8 ( V_2 , V_120 ) ;
if ( V_66 ) {
F_65 ( V_2 -> V_114 ) ;
for ( V_74 = 0 ; V_74 < V_171 ; V_74 ++ , V_66 ++ )
F_13 ( V_2 , V_74 , * V_66 ) ;
F_67 ( V_2 -> V_114 ) ;
} else if ( V_107 ) {
for ( V_74 = 0 ; V_74 < V_171 ; V_74 ++ )
F_13 ( V_2 , V_74 , 0xffffffff ) ;
}
if ( V_107 ) {
V_107 += F_48 ( V_2 , V_73 , V_107 ,
V_93 -> V_219 / V_213 ,
V_49 -> V_60 . V_70 ) ;
}
F_53 ( V_49 , V_233 ) ;
V_232 = F_57 ( V_93 , V_96 ) ;
if ( V_232 & V_235 ) {
F_92 ( V_2 -> V_10 , L_22 ,
( unsigned long long ) V_146 ) ;
V_172 = - V_222 ;
goto V_234;
}
}
V_234:
F_39 ( V_93 , 1 ) ;
return V_172 ;
}
static int F_93 ( struct V_92 * V_93 , struct V_95 * V_96 ,
const T_6 * V_66 , int V_227 , int V_228 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
void * V_107 = V_227 ? V_96 -> V_229 : NULL ;
F_89 ( V_93 , V_96 , V_49 -> V_154 , ( const T_1 * ) V_66 , V_107 ) ;
return 0 ;
}
static int F_94 ( struct V_92 * V_93 ,
struct V_95 * V_96 , const T_6 * V_66 ,
int V_227 , int V_228 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
void * V_107 = V_227 ? V_96 -> V_229 : NULL ;
F_22 ( V_49 , 0 ) ;
F_89 ( V_93 , V_96 , V_49 -> V_154 , ( const T_1 * ) V_66 , V_107 ) ;
F_22 ( V_49 , 1 ) ;
return 0 ;
}
static int F_95 ( struct V_92 * V_93 , struct V_95 * V_96 ,
int V_228 )
{
return F_89 ( V_93 , V_96 , ( T_5 ) V_228 << V_96 -> V_147 ,
NULL , V_96 -> V_229 ) ;
}
static int F_96 ( struct V_92 * V_93 , struct V_95 * V_96 ,
int V_228 )
{
struct V_48 * V_49 = F_41 ( V_96 ) ;
int V_172 ;
F_22 ( V_49 , 0 ) ;
V_172 = F_89 ( V_93 , V_96 , ( T_5 ) V_228 << V_96 -> V_147 , NULL ,
( T_3 * ) V_96 -> V_229 ) ;
F_22 ( V_49 , 1 ) ;
return V_172 ;
}
static int F_97 ( struct V_48 * V_49 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_95 * V_96 = & V_49 -> V_96 ;
T_2 V_236 = F_15 ( V_2 , V_49 -> V_40 , V_237 ) ;
T_2 V_238 = F_15 ( V_2 , V_49 -> V_40 ,
V_239 ) ;
T_2 V_62 = F_15 ( V_2 , V_49 -> V_40 ,
V_55 ) ;
T_3 V_240 = 0 , V_83 = 0 , V_241 = 0 ;
T_1 V_37 ;
if ( V_2 -> V_25 ) {
int V_73 , V_242 ;
for ( V_73 = 0 , V_242 = 0 ; V_2 -> V_25 [ V_73 ] ; V_73 ++ )
if ( V_2 -> V_25 [ V_73 ] * 1024 == V_69 -> V_240 ) {
V_240 = V_73 ;
V_242 = 1 ;
}
if ( ! V_242 ) {
F_91 ( V_2 -> V_10 , L_23 ,
V_69 -> V_240 ) ;
return - V_243 ;
}
} else {
V_240 = F_98 ( V_69 -> V_240 ) - F_98 ( V_244 ) ;
}
if ( V_69 -> V_240 < V_244 || ( V_2 -> V_24 &&
V_69 -> V_240 > V_2 -> V_24 ) ) {
F_91 ( V_2 -> V_10 , L_23 ,
V_69 -> V_240 ) ;
V_240 = 0 ;
}
if ( V_2 -> V_8 ) {
int V_73 , V_242 ;
for ( V_73 = 0 , V_242 = 0 ; V_2 -> V_8 [ V_73 ] ; V_73 ++ )
if ( V_2 -> V_8 [ V_73 ] == V_69 -> V_83 ) {
V_83 = V_73 ;
V_242 = 1 ;
}
if ( ! V_242 ) {
F_91 ( V_2 -> V_10 , L_24 ,
V_69 -> V_83 ) ;
return - V_243 ;
}
} else {
V_83 = F_98 ( V_69 -> V_83 ) - F_98 ( V_245 ) ;
}
if ( V_69 -> V_83 < V_245 || ( V_2 -> V_23 &&
V_69 -> V_83 > V_2 -> V_23 ) ) {
F_91 ( V_2 -> V_10 , L_24 , V_69 -> V_83 ) ;
return - V_243 ;
}
if ( F_99 ( V_69 -> V_241 ) < F_99 ( V_246 ) ) {
F_91 ( V_2 -> V_10 , L_25 ,
( unsigned long long ) V_69 -> V_241 ) ;
return - V_243 ;
}
V_241 = F_99 ( V_69 -> V_241 ) - F_99 ( V_246 ) ;
V_37 = ( V_69 -> V_247 << V_248 ) |
( V_69 -> V_249 << V_250 ) |
( V_69 -> V_251 << V_252 ) |
( ! ! ( V_69 -> V_253 == 16 ) << V_254 ) |
( V_241 << V_255 ) ;
if ( V_236 == V_238 ) {
V_37 |= ( V_83 << V_256 ) |
( V_240 << V_257 ) ;
F_3 ( V_2 , V_236 , V_37 ) ;
} else {
F_3 ( V_2 , V_236 , V_37 ) ;
V_37 = ( V_83 << V_258 ) |
( V_240 << V_259 ) ;
F_3 ( V_2 , V_238 , V_37 ) ;
}
V_37 = F_1 ( V_2 , V_62 ) ;
V_37 &= ~ F_21 ( V_2 ) ;
V_37 |= V_69 -> V_61 << V_53 ;
V_37 &= ~ F_19 ( V_2 ) ;
V_37 |= V_69 -> V_71 ;
F_3 ( V_2 , V_62 , V_37 ) ;
F_25 ( V_49 , V_69 -> V_70 ) ;
F_17 ( V_49 , F_37 ( V_96 -> V_260 . V_261 * 3 , 4 ) ) ;
return 0 ;
}
static void F_100 ( char * V_66 , struct V_68 * V_69 )
{
V_66 += sprintf ( V_66 ,
L_26 ,
( unsigned long long ) V_69 -> V_241 >> 20 ,
V_69 -> V_240 >> 10 ,
V_69 -> V_83 >= 1024 ? V_69 -> V_83 >> 10 : V_69 -> V_83 ,
V_69 -> V_83 >= 1024 ? L_27 : L_28 ,
V_69 -> V_71 , V_69 -> V_253 ) ;
if ( F_34 ( V_69 ) )
sprintf ( V_66 , L_29 ) ;
else if ( V_69 -> V_70 )
sprintf ( V_66 , L_30 , V_69 -> V_61 << 1 ) ;
else
sprintf ( V_66 , L_31 , V_69 -> V_61 ) ;
}
static inline int F_101 ( T_5 V_262 , T_1 V_230 )
{
return F_102 ( F_103 ( V_262 ) - F_103 ( V_230 ) , 8 ) >> 3 ;
}
static int F_104 ( struct V_48 * V_49 )
{
struct V_92 * V_93 = F_62 ( & V_49 -> V_96 ) ;
struct V_95 * V_96 = & V_49 -> V_96 ;
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_68 * V_69 = & V_49 -> V_60 ;
char V_263 [ 128 ] ;
T_1 V_3 , V_37 , V_264 ;
int V_172 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_172 = F_105 ( F_106 ( V_96 ) ,
L_32 ,
& V_264 ) ;
if ( V_172 ) {
V_69 -> V_71 = V_93 -> V_219 /
( V_93 -> V_230 >> V_231 ) ;
} else {
V_69 -> V_71 = V_264 ;
}
if ( V_69 -> V_71 > V_2 -> V_26 )
V_69 -> V_71 = V_2 -> V_26 ;
V_93 -> V_219 = V_69 -> V_71 * ( V_93 -> V_230 >> V_231 ) ;
V_69 -> V_241 = V_93 -> V_262 ;
V_69 -> V_240 = V_93 -> V_265 ;
V_69 -> V_83 = V_93 -> V_230 ;
V_69 -> V_253 = ( V_96 -> V_266 & V_267 ) ? 16 : 8 ;
V_69 -> V_249 = 2 ;
V_69 -> V_247 = F_101 ( V_93 -> V_262 , V_93 -> V_230 ) ;
switch ( V_96 -> V_260 . V_262 ) {
case 512 :
if ( V_96 -> V_260 . V_261 == 1 )
V_69 -> V_61 = 15 ;
else
V_69 -> V_61 = V_96 -> V_260 . V_261 ;
V_69 -> V_70 = 0 ;
break;
case 1024 :
if ( ! ( V_2 -> V_27 & V_30 ) ) {
F_6 ( V_2 -> V_10 , L_33 ) ;
return - V_243 ;
}
if ( V_96 -> V_260 . V_261 & 0x1 ) {
F_6 ( V_2 -> V_10 ,
L_34 ) ;
return - V_243 ;
}
V_69 -> V_61 = V_96 -> V_260 . V_261 >> 1 ;
V_69 -> V_70 = 1 ;
break;
default:
F_6 ( V_2 -> V_10 , L_35 ,
V_96 -> V_260 . V_262 ) ;
return - V_243 ;
}
V_69 -> V_251 = V_69 -> V_247 ;
if ( V_93 -> V_230 > 512 )
V_69 -> V_251 += V_69 -> V_249 ;
else
V_69 -> V_251 += 1 ;
V_172 = F_97 ( V_49 , V_69 ) ;
if ( V_172 )
return V_172 ;
F_22 ( V_49 , 1 ) ;
F_100 ( V_263 , V_69 ) ;
F_92 ( V_2 -> V_10 , L_36 , V_263 ) ;
V_3 = F_15 ( V_2 , V_49 -> V_40 , V_55 ) ;
V_37 = F_1 ( V_2 , V_3 ) ;
V_37 &= ~ V_268 ;
V_37 &= ~ V_269 ;
V_37 &= ~ V_270 ;
if ( V_2 -> V_27 & V_28 ) {
if ( F_27 ( V_2 ) )
V_37 &= ~ V_271 ;
else
V_37 |= V_271 ;
}
F_3 ( V_2 , V_3 , V_37 ) ;
return 0 ;
}
static int F_107 ( struct V_48 * V_49 , struct V_272 * V_273 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_274 * V_81 = V_49 -> V_81 ;
struct V_92 * V_93 ;
struct V_95 * V_96 ;
int V_172 ;
T_2 V_236 ;
V_172 = F_105 ( V_273 , L_37 , & V_49 -> V_40 ) ;
if ( V_172 ) {
F_6 ( & V_81 -> V_10 , L_38 ) ;
return - V_275 ;
}
V_93 = F_62 ( & V_49 -> V_96 ) ;
V_96 = & V_49 -> V_96 ;
F_108 ( V_96 , V_273 ) ;
F_109 ( V_96 , V_49 ) ;
V_93 -> V_276 = F_110 ( & V_81 -> V_10 , V_82 , L_39 ,
V_49 -> V_40 ) ;
V_93 -> V_277 = V_278 ;
V_93 -> V_10 . V_279 = & V_81 -> V_10 ;
V_96 -> V_280 = ( void V_281 * ) 0xdeadbeef ;
V_96 -> V_282 = ( void V_281 * ) 0xdeadbeef ;
V_96 -> V_283 = F_56 ;
V_96 -> V_176 = F_63 ;
V_96 -> V_284 = F_57 ;
V_96 -> V_285 = F_68 ;
V_96 -> V_286 = F_69 ;
V_96 -> V_287 = F_70 ;
V_96 -> V_260 . V_288 = V_289 ;
V_96 -> V_260 . V_290 = F_85 ;
V_96 -> V_260 . V_291 = F_93 ;
V_96 -> V_260 . V_292 = F_86 ;
V_96 -> V_260 . V_293 = F_94 ;
V_96 -> V_260 . V_294 = F_96 ;
V_96 -> V_260 . V_295 = F_88 ;
V_96 -> V_260 . V_296 = F_87 ;
V_96 -> V_260 . V_297 = F_95 ;
V_96 -> V_298 = & V_2 -> V_298 ;
V_236 = F_15 ( V_2 , V_49 -> V_40 , V_237 ) ;
F_3 ( V_2 , V_236 ,
F_1 ( V_2 , V_236 ) & ~ V_299 ) ;
if ( F_111 ( V_93 , 1 , NULL ) )
return - V_275 ;
V_96 -> V_266 |= V_300 ;
V_96 -> V_266 |= V_301 ;
if ( F_112 ( V_273 ) )
V_96 -> V_302 |= V_303 | V_304 ;
if ( F_104 ( V_49 ) )
return - V_275 ;
V_96 -> V_260 . V_262 = V_49 -> V_60 . V_70 ? 1024 : 512 ;
V_93 -> V_226 = 1 ;
V_96 -> V_260 . V_75 = F_38 ( V_49 ) ;
if ( ! V_96 -> V_260 . V_75 )
return - V_275 ;
if ( F_113 ( V_93 ) )
return - V_275 ;
return F_114 ( V_93 , NULL , 0 ) ;
}
static void F_115 ( struct V_48 * V_49 ,
int V_305 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_2 V_236 = F_15 ( V_2 , V_49 -> V_40 , V_237 ) ;
T_2 V_238 = F_15 ( V_2 , V_49 -> V_40 ,
V_239 ) ;
T_2 V_62 = F_15 ( V_2 , V_49 -> V_40 ,
V_55 ) ;
T_2 V_306 = F_15 ( V_2 , V_49 -> V_40 , V_307 ) ;
T_2 V_308 = F_15 ( V_2 , V_49 -> V_40 , V_309 ) ;
if ( V_305 ) {
F_3 ( V_2 , V_236 , V_49 -> V_60 . V_310 ) ;
if ( V_236 != V_238 )
F_3 ( V_2 , V_238 ,
V_49 -> V_60 . V_311 ) ;
F_3 ( V_2 , V_62 , V_49 -> V_60 . V_56 ) ;
F_3 ( V_2 , V_306 , V_49 -> V_60 . V_312 ) ;
F_3 ( V_2 , V_308 , V_49 -> V_60 . V_313 ) ;
} else {
V_49 -> V_60 . V_310 = F_1 ( V_2 , V_236 ) ;
if ( V_236 != V_238 )
V_49 -> V_60 . V_311 =
F_1 ( V_2 , V_238 ) ;
V_49 -> V_60 . V_56 = F_1 ( V_2 , V_62 ) ;
V_49 -> V_60 . V_312 = F_1 ( V_2 , V_306 ) ;
V_49 -> V_60 . V_313 = F_1 ( V_2 , V_308 ) ;
}
}
static int F_116 ( struct V_314 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
struct V_48 * V_49 ;
F_118 (host, &ctrl->host_list, node)
F_115 ( V_49 , 0 ) ;
V_2 -> V_315 = F_8 ( V_2 , V_64 ) ;
V_2 -> V_316 = F_8 ( V_2 , V_317 ) ;
V_2 -> V_318 =
F_8 ( V_2 , V_51 ) ;
if ( F_27 ( V_2 ) )
V_2 -> V_319 = F_33 ( V_2 , V_320 ) ;
return 0 ;
}
static int F_119 ( struct V_314 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
struct V_48 * V_49 ;
if ( F_27 ( V_2 ) ) {
F_32 ( V_2 , V_320 , V_2 -> V_319 ) ;
F_32 ( V_2 , V_200 , 0 ) ;
}
F_9 ( V_2 , V_64 , V_2 -> V_315 ) ;
F_9 ( V_2 , V_317 , V_2 -> V_316 ) ;
F_9 ( V_2 , V_51 ,
V_2 -> V_318 ) ;
if ( V_2 -> V_114 ) {
V_2 -> V_114 -> V_115 ( V_2 -> V_114 ) ;
V_2 -> V_114 -> V_321 ( V_2 -> V_114 , true ) ;
}
F_118 (host, &ctrl->host_list, node) {
struct V_95 * V_96 = & V_49 -> V_96 ;
struct V_92 * V_93 = F_62 ( V_96 ) ;
F_115 ( V_49 , 1 ) ;
V_96 -> V_176 ( V_93 , V_155 , - 1 , - 1 ) ;
}
return 0 ;
}
int F_120 ( struct V_274 * V_81 , struct V_322 * V_114 )
{
struct V_314 * V_10 = & V_81 -> V_10 ;
struct V_272 * V_273 = V_10 -> V_32 , * V_323 ;
struct V_1 * V_2 ;
struct V_324 * V_325 ;
int V_172 ;
if ( ! V_273 )
return - V_11 ;
if ( ! F_121 ( V_326 , V_273 ) )
return - V_11 ;
V_2 = F_36 ( V_10 , sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_206 ;
F_122 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
F_123 ( & V_2 -> V_113 ) ;
F_123 ( & V_2 -> V_117 ) ;
F_124 ( & V_2 -> V_298 . V_327 ) ;
F_125 ( & V_2 -> V_298 . V_328 ) ;
F_126 ( & V_2 -> V_329 ) ;
V_325 = F_127 ( V_81 , V_330 , 0 ) ;
V_2 -> V_4 = F_128 ( V_10 , V_325 ) ;
if ( F_129 ( V_2 -> V_4 ) )
return F_130 ( V_2 -> V_4 ) ;
V_2 -> V_331 = F_131 ( V_10 , L_40 ) ;
if ( ! F_129 ( V_2 -> V_331 ) ) {
V_172 = F_132 ( V_2 -> V_331 ) ;
if ( V_172 )
return V_172 ;
} else {
V_172 = F_130 ( V_2 -> V_331 ) ;
if ( V_172 == - V_332 )
return V_172 ;
V_2 -> V_331 = NULL ;
}
V_172 = F_5 ( V_2 ) ;
if ( V_172 )
goto V_220;
V_325 = F_133 ( V_81 , V_330 , L_41 ) ;
if ( V_325 ) {
V_2 -> V_39 = F_128 ( V_10 , V_325 ) ;
if ( F_129 ( V_2 -> V_39 ) ) {
V_172 = F_130 ( V_2 -> V_39 ) ;
goto V_220;
}
} else {
V_2 -> V_39 = V_2 -> V_4 +
V_2 -> V_12 [ V_333 ] ;
}
V_325 = F_133 ( V_81 , V_330 , L_42 ) ;
if ( V_325 ) {
V_2 -> V_65 = F_128 ( V_10 , V_325 ) ;
if ( F_129 ( V_2 -> V_65 ) ) {
V_172 = F_130 ( V_2 -> V_65 ) ;
goto V_220;
}
F_32 ( V_2 , V_320 , 1 ) ;
F_32 ( V_2 , V_200 , 0 ) ;
V_2 -> V_207 = F_134 ( V_10 ,
sizeof( * V_2 -> V_207 ) ,
& V_2 -> V_208 , V_82 ) ;
if ( ! V_2 -> V_207 ) {
V_172 = - V_206 ;
goto V_220;
}
V_2 -> V_334 = F_135 ( V_81 , 1 ) ;
if ( ( int ) V_2 -> V_334 < 0 ) {
F_6 ( V_10 , L_43 ) ;
V_172 = - V_11 ;
goto V_220;
}
V_172 = F_136 ( V_10 , V_2 -> V_334 ,
F_52 , 0 , V_335 ,
V_2 ) ;
if ( V_172 < 0 ) {
F_6 ( V_10 , L_44 ,
V_2 -> V_334 , V_172 ) ;
goto V_220;
}
F_92 ( V_10 , L_45 ) ;
}
F_10 ( V_2 , V_64 ,
V_336 | 0xff , 0 , 0 ) ;
F_10 ( V_2 , V_317 , 0xff , 0 , 0 ) ;
if ( V_2 -> V_27 & V_31 ) {
if ( V_97 == 2 )
F_26 ( V_2 , false ) ;
} else {
V_97 = 0 ;
}
V_2 -> V_110 = F_135 ( V_81 , 0 ) ;
if ( ( int ) V_2 -> V_110 < 0 ) {
F_6 ( V_10 , L_46 ) ;
V_172 = - V_11 ;
goto V_220;
}
if ( V_114 ) {
V_2 -> V_114 = V_114 ;
V_172 = F_136 ( V_10 , V_2 -> V_110 , F_51 , 0 ,
V_335 , V_2 ) ;
V_2 -> V_114 -> V_115 ( V_2 -> V_114 ) ;
V_2 -> V_114 -> V_321 ( V_2 -> V_114 , true ) ;
} else {
V_172 = F_136 ( V_10 , V_2 -> V_110 , F_49 , 0 ,
V_335 , V_2 ) ;
}
if ( V_172 < 0 ) {
F_6 ( V_10 , L_44 ,
V_2 -> V_110 , V_172 ) ;
goto V_220;
}
F_137 (dn, child) {
if ( F_138 ( V_323 , L_47 ) ) {
struct V_48 * V_49 ;
V_49 = F_36 ( V_10 , sizeof( * V_49 ) , V_82 ) ;
if ( ! V_49 ) {
F_139 ( V_323 ) ;
V_172 = - V_206 ;
goto V_220;
}
V_49 -> V_81 = V_81 ;
V_49 -> V_2 = V_2 ;
V_172 = F_107 ( V_49 , V_323 ) ;
if ( V_172 ) {
F_140 ( V_10 , V_49 ) ;
continue;
}
F_141 ( & V_49 -> V_337 , & V_2 -> V_329 ) ;
}
}
if ( F_142 ( & V_2 -> V_329 ) ) {
V_172 = - V_11 ;
goto V_220;
}
return 0 ;
V_220:
F_143 ( V_2 -> V_331 ) ;
return V_172 ;
}
int F_144 ( struct V_274 * V_81 )
{
struct V_1 * V_2 = F_117 ( & V_81 -> V_10 ) ;
struct V_48 * V_49 ;
F_118 (host, &ctrl->host_list, node)
F_145 ( F_62 ( & V_49 -> V_96 ) ) ;
F_143 ( V_2 -> V_331 ) ;
F_122 ( & V_81 -> V_10 , NULL ) ;
return 0 ;
}
