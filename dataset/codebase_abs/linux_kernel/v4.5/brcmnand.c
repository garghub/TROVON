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
if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_12 = V_13 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_12 = V_14 ;
else if ( V_2 -> V_9 >= 0x0400 )
V_2 -> V_12 = V_15 ;
if ( V_2 -> V_9 >= 0x0701 )
V_2 -> V_16 = 0x14 ;
else
V_2 -> V_16 = 0x10 ;
if ( V_2 -> V_9 >= 0x0701 ) {
V_2 -> V_17 = V_18 ;
} else {
V_2 -> V_17 = V_19 ;
if ( V_2 -> V_9 <= 0x0500 )
V_2 -> V_20 = V_21 ;
}
if ( V_2 -> V_9 >= 0x0701 ) {
V_2 -> V_22 = 16 * 1024 ;
V_2 -> V_23 = 2 * 1024 * 1024 ;
} else {
V_2 -> V_8 = V_8 ;
if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_24 = V_6 ;
else
V_2 -> V_24 = V_7 ;
if ( V_2 -> V_9 < 0x0400 ) {
V_2 -> V_22 = 4096 ;
V_2 -> V_23 = 512 * 1024 ;
}
}
if ( V_2 -> V_9 >= 0x0600 )
V_2 -> V_25 = 64 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_25 = 32 ;
else
V_2 -> V_25 = 16 ;
if ( V_2 -> V_9 >= 0x0600 && V_2 -> V_9 != 0x0601 )
V_2 -> V_26 |= V_27 ;
if ( V_2 -> V_9 >= 0x0700 )
V_2 -> V_26 |= V_28 ;
if ( V_2 -> V_9 >= 0x0500 )
V_2 -> V_26 |= V_29 ;
if ( V_2 -> V_9 >= 0x0700 )
V_2 -> V_26 |= V_30 ;
else if ( F_7 ( V_2 -> V_10 -> V_31 , L_2 ) )
V_2 -> V_26 |= V_30 ;
return 0 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
T_2 V_3 = V_2 -> V_12 [ V_33 ] ;
if ( V_3 )
return F_1 ( V_2 , V_3 ) ;
else
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 ,
enum V_32 V_33 , T_1 V_5 )
{
T_2 V_3 = V_2 -> V_12 [ V_33 ] ;
if ( V_3 )
F_3 ( V_2 , V_3 , V_5 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
enum V_32 V_33 , T_1 V_34 , unsigned
int V_35 , T_1 V_5 )
{
T_1 V_36 = F_8 ( V_2 , V_33 ) ;
V_36 &= ~ V_34 ;
V_36 |= V_5 << V_35 ;
F_9 ( V_2 , V_33 , V_36 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , int V_37 )
{
return F_12 ( V_2 -> V_38 + V_37 * 4 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
int V_37 , T_1 V_5 )
{
F_14 ( V_5 , V_2 -> V_38 + V_37 * 4 ) ;
}
static inline T_2 F_15 ( struct V_1 * V_2 , int V_39 ,
enum V_40 V_33 )
{
T_2 V_41 = V_2 -> V_12 [ V_42 ] ;
T_2 V_43 = V_2 -> V_12 [ V_44 ] ;
T_3 V_45 ;
if ( V_39 == 0 && V_2 -> V_20 )
V_45 = V_2 -> V_20 [ V_33 ] ;
else
V_45 = V_2 -> V_17 [ V_33 ] ;
if ( V_39 && V_43 )
return V_43 + ( V_39 - 1 ) * V_2 -> V_16 + V_45 ;
return V_41 + V_39 * V_2 -> V_16 + V_45 ;
}
static inline T_1 F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 < 0x0600 )
return 1 ;
return F_8 ( V_2 , V_46 ) ;
}
static void F_17 ( struct V_47 * V_48 , T_3 V_5 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned int V_35 = 0 , V_49 ;
enum V_32 V_33 = V_50 ;
int V_39 = V_48 -> V_39 ;
if ( V_2 -> V_9 >= 0x0600 )
V_49 = 6 ;
else if ( V_2 -> V_9 >= 0x0500 )
V_49 = 5 ;
else
V_49 = 4 ;
if ( V_2 -> V_9 >= 0x0600 ) {
if ( V_39 >= 5 )
V_33 = V_51 ;
V_35 = ( V_39 % 5 ) * V_49 ;
}
F_10 ( V_2 , V_33 , ( V_49 - 1 ) << V_35 , V_35 , V_5 ) ;
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
T_1 V_34 = ( V_2 -> V_9 >= 0x0600 ) ? 0x1f : 0x0f ;
return V_34 << V_52 ;
}
static void F_22 ( struct V_47 * V_48 , int V_53 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_2 V_3 = F_15 ( V_2 , V_48 -> V_39 , V_54 ) ;
T_1 V_55 = F_1 ( V_2 , V_3 ) ;
T_1 V_56 = V_57 | V_58 ;
if ( V_53 ) {
V_55 |= V_56 ;
V_55 |= V_48 -> V_59 . V_60
<< V_52 ;
} else {
V_55 &= ~ V_56 ;
V_55 &= ~ F_21 ( V_2 ) ;
}
F_3 ( V_2 , V_3 , V_55 ) ;
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
static int F_24 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
int V_35 = F_23 ( V_2 ) ;
T_2 V_61 = F_15 ( V_2 , V_48 -> V_39 ,
V_54 ) ;
if ( V_35 < 0 )
return 0 ;
return ( F_1 ( V_2 , V_61 ) >> V_35 ) & 0x1 ;
}
static void F_25 ( struct V_47 * V_48 , int V_5 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
int V_35 = F_23 ( V_2 ) ;
T_2 V_61 = F_15 ( V_2 , V_48 -> V_39 ,
V_54 ) ;
T_1 V_36 ;
if ( V_35 < 0 )
return;
V_36 = F_1 ( V_2 , V_61 ) ;
V_36 &= ~ ( 1 << V_35 ) ;
V_36 |= ( ! ! V_5 ) << V_35 ;
F_3 ( V_2 , V_61 , V_36 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , bool V_53 )
{
T_1 V_5 = V_53 ? V_62 : 0 ;
F_10 ( V_2 , V_63 , V_62 , 0 , V_5 ) ;
}
static inline bool F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_64 ;
}
static inline bool F_28 ( const void * V_65 )
{
return V_65 && ! F_29 ( V_65 ) &&
F_30 ( F_31 ( ( V_66 ) V_65 , 4 ) ) ;
}
static inline void F_32 ( struct V_1 * V_2 , T_3 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_64 + V_3 ) ;
}
static inline T_1 F_33 ( struct V_1 * V_2 , T_3 V_3 )
{
return F_2 ( V_2 -> V_64 + V_3 ) ;
}
static inline bool F_34 ( struct V_67 * V_68 )
{
return V_68 -> V_69 == 0 && V_68 -> V_70 == 16 &&
V_68 -> V_60 == 15 ;
}
static struct V_71 * F_35 ( int V_60 ,
struct V_47 * V_48 )
{
struct V_67 * V_68 = & V_48 -> V_59 ;
int V_72 , V_73 ;
struct V_71 * V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
int V_78 , V_79 ;
V_74 = F_36 ( & V_48 -> V_80 -> V_10 , sizeof( * V_74 ) , V_81 ) ;
if ( ! V_74 )
return NULL ;
V_76 = V_68 -> V_82 / ( 512 << V_68 -> V_69 ) ;
V_77 = V_68 -> V_70 << V_68 -> V_69 ;
if ( F_34 ( V_68 ) ) {
for ( V_72 = 0 , V_78 = 0 , V_79 = 0 ; V_72 < V_76 ; V_72 ++ ) {
if ( V_72 == 0 ) {
V_74 -> V_83 [ V_79 ] . V_84 = V_72 * V_77 + 1 ;
if ( V_68 -> V_82 == 512 )
V_74 -> V_83 [ V_79 ] . V_84 -- ;
V_74 -> V_83 [ V_79 ] . V_85 = 5 ;
} else {
V_74 -> V_83 [ V_79 ] . V_84 = V_72 * V_77 ;
V_74 -> V_83 [ V_79 ] . V_85 = 6 ;
}
V_79 ++ ;
V_74 -> V_86 [ V_78 ++ ] = V_72 * V_77 + 6 ;
V_74 -> V_86 [ V_78 ++ ] = V_72 * V_77 + 7 ;
V_74 -> V_86 [ V_78 ++ ] = V_72 * V_77 + 8 ;
V_74 -> V_83 [ V_79 ] . V_84 = V_72 * V_77 + 9 ;
V_74 -> V_83 [ V_79 ] . V_85 = 7 ;
V_79 ++ ;
if ( V_78 >= V_87 ||
V_79 >= V_88 - 1 )
break;
}
goto V_89;
}
V_75 = F_37 ( V_60 * 14 , 8 ) ;
if ( V_75 >= V_77 ) {
F_6 ( & V_48 -> V_80 -> V_10 ,
L_3 ,
V_75 , V_77 ) ;
return NULL ;
}
V_74 -> V_90 = V_75 * V_76 ;
for ( V_72 = 0 , V_78 = 0 , V_79 = 0 ; V_72 < V_76 ; V_72 ++ ) {
for ( V_73 = V_77 - V_75 ; V_73 < V_77 && V_78 <
V_87 ; V_73 ++ , V_78 ++ )
V_74 -> V_86 [ V_78 ] = V_72 * V_77 + V_73 ;
if ( V_72 == 0 ) {
if ( V_68 -> V_82 == 512 && ( V_77 - V_75 >= 6 ) ) {
V_74 -> V_83 [ V_79 ] . V_84 = 0 ;
V_74 -> V_83 [ V_79 ] . V_85 = 5 ;
V_79 ++ ;
if ( V_77 - V_75 > 6 ) {
V_74 -> V_83 [ V_79 ] . V_84 = 6 ;
V_74 -> V_83 [ V_79 ] . V_85 =
V_77 - V_75 - 6 ;
V_79 ++ ;
}
} else if ( V_77 > V_75 + 1 ) {
V_74 -> V_83 [ V_79 ] . V_84 = V_72 * V_77 + 1 ;
V_74 -> V_83 [ V_79 ] . V_85 = V_77 - V_75 - 1 ;
V_79 ++ ;
}
} else if ( V_77 > V_75 ) {
V_74 -> V_83 [ V_79 ] . V_84 = V_72 * V_77 ;
V_74 -> V_83 [ V_79 ] . V_85 = V_77 - V_75 ;
V_79 ++ ;
}
if ( V_78 >= V_87 ||
V_79 >= V_88 - 1 )
break;
}
V_89:
for ( V_72 = 0 ; V_72 < V_88 ; V_72 ++ )
V_74 -> V_91 += V_74 -> V_83 [ V_72 ] . V_85 ;
return V_74 ;
}
static struct V_71 * F_38 (
struct V_47 * V_48 )
{
struct V_71 * V_74 ;
struct V_67 * V_92 = & V_48 -> V_59 ;
unsigned int V_60 = V_92 -> V_60 ;
if ( V_92 -> V_69 )
V_60 <<= 1 ;
V_74 = F_35 ( V_60 , V_48 ) ;
if ( ! V_74 ) {
F_6 ( & V_48 -> V_80 -> V_10 ,
L_4 ) ;
return NULL ;
}
return V_74 ;
}
static void F_39 ( struct V_93 * V_94 , int V_95 )
{
struct V_96 * V_97 = F_40 ( V_94 ) ;
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
if ( ( V_2 -> V_26 & V_30 ) && V_98 == 1 ) {
static int V_99 = - 1 ;
if ( V_99 != V_95 ) {
F_42 ( V_2 -> V_10 , L_5 , V_95 ? L_6 : L_7 ) ;
V_99 = V_95 ;
}
F_26 ( V_2 , V_95 ) ;
}
}
static inline T_3 F_43 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_100 , V_101 , V_102 ;
V_100 = V_2 -> V_12 [ V_103 ] ;
V_101 = V_2 -> V_12 [ V_104 ] ;
if ( V_3 >= V_2 -> V_25 )
return 0x77 ;
if ( V_3 >= 16 && V_101 )
V_102 = V_101 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_102 = V_100 + ( V_3 & ~ 0x03 ) ;
return F_1 ( V_2 , V_102 ) >> ( 24 - ( ( V_3 & 0x03 ) << 3 ) ) ;
}
static inline void F_44 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_105 )
{
T_2 V_100 , V_101 , V_102 ;
V_100 = V_2 -> V_12 [ V_106 ] ;
V_101 = V_2 -> V_12 [ V_107 ] ;
if ( V_3 >= V_2 -> V_25 )
return;
if ( V_3 >= 16 && V_101 )
V_102 = V_101 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_102 = V_100 + ( V_3 & ~ 0x03 ) ;
F_3 ( V_2 , V_102 , V_105 ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_72 , T_3 * V_108 ,
int V_77 , int V_109 )
{
int V_110 = V_77 << V_109 ;
int V_73 ;
if ( V_109 && ( V_72 & 0x01 ) )
V_110 = F_46 ( 0 , V_110 - ( int ) V_2 -> V_25 ) ;
V_110 = F_47 ( int , V_110 , V_2 -> V_25 ) ;
for ( V_73 = 0 ; V_73 < V_110 ; V_73 ++ )
V_108 [ V_73 ] = F_43 ( V_2 , V_73 ) ;
return V_110 ;
}
static int F_48 ( struct V_1 * V_2 , int V_72 ,
const T_3 * V_108 , int V_77 , int V_109 )
{
int V_110 = V_77 << V_109 ;
int V_73 ;
if ( V_109 && ( V_72 & 0x01 ) )
V_110 = F_46 ( 0 , V_110 - ( int ) V_2 -> V_25 ) ;
V_110 = F_47 ( int , V_110 , V_2 -> V_25 ) ;
for ( V_73 = 0 ; V_73 < V_110 ; V_73 += 4 )
F_44 ( V_2 , V_73 ,
( V_108 [ V_73 + 0 ] << 24 ) |
( V_108 [ V_73 + 1 ] << 16 ) |
( V_108 [ V_73 + 2 ] << 8 ) |
( V_108 [ V_73 + 3 ] << 0 ) ) ;
return V_110 ;
}
static T_4 F_49 ( int V_111 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
if ( V_2 -> V_112 )
return V_113 ;
F_50 ( & V_2 -> V_114 ) ;
return V_113 ;
}
static T_4 F_51 ( int V_111 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
if ( V_2 -> V_115 -> V_116 ( V_2 -> V_115 ) )
return F_49 ( V_111 , V_105 ) ;
return V_117 ;
}
static T_4 F_52 ( int V_111 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
F_50 ( & V_2 -> V_118 ) ;
return V_113 ;
}
static void F_53 ( struct V_47 * V_48 , int V_119 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_1 V_120 ;
F_42 ( V_2 -> V_10 , L_8 , V_119 ,
F_8 ( V_2 , V_121 ) ) ;
F_54 ( V_2 -> V_122 != 0 ) ;
V_2 -> V_122 = V_119 ;
V_120 = F_8 ( V_2 , V_123 ) ;
F_54 ( ! ( V_120 & V_124 ) ) ;
F_55 () ;
F_9 ( V_2 , V_125 ,
V_119 << F_18 ( V_2 ) ) ;
}
static void F_56 ( struct V_93 * V_94 , int V_126 ,
unsigned int V_2 )
{
}
static int F_57 ( struct V_93 * V_94 , struct V_96 * V_127 )
{
struct V_96 * V_97 = F_40 ( V_94 ) ;
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned long V_128 = F_58 ( 100 ) ;
F_42 ( V_2 -> V_10 , L_9 , V_2 -> V_122 ) ;
if ( V_2 -> V_122 &&
F_59 ( & V_2 -> V_114 , V_128 ) <= 0 ) {
T_1 V_119 = F_8 ( V_2 , V_125 )
>> F_18 ( V_2 ) ;
F_60 ( V_2 -> V_10 ,
L_10 , V_119 ) ;
F_60 ( V_2 -> V_10 , L_11 ,
F_8 ( V_2 , V_123 ) ) ;
}
V_2 -> V_122 = 0 ;
return F_8 ( V_2 , V_123 ) &
V_129 ;
}
static int F_61 ( struct V_47 * V_48 ,
enum V_130 type , T_1 V_105 ,
bool V_131 )
{
struct V_93 * V_94 = F_62 ( & V_48 -> V_97 ) ;
struct V_96 * V_97 = & V_48 -> V_97 ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_1 V_36 ;
V_36 = V_105 & V_132 ;
switch ( type ) {
case V_133 :
V_36 |= V_134 | V_135 ;
break;
case V_136 :
V_36 |= V_134 | V_137 ;
break;
case V_138 :
V_36 |= V_134 ;
break;
case V_139 :
V_36 |= V_140 ;
break;
}
if ( V_131 )
V_36 |= V_141 ;
F_42 ( V_2 -> V_10 , L_12 , V_36 ) ;
F_9 ( V_2 , V_142 , V_36 ) ;
( void ) F_8 ( V_2 , V_142 ) ;
F_53 ( V_48 , V_143 ) ;
return F_57 ( V_94 , V_97 ) ;
}
static void F_63 ( struct V_93 * V_94 , unsigned V_144 ,
int V_145 , int V_146 )
{
struct V_96 * V_97 = F_40 ( V_94 ) ;
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_5 V_147 = ( T_5 ) V_146 << V_97 -> V_148 ;
int V_149 = 0 ;
if ( V_144 == V_150 || V_144 == V_151 ||
V_144 == V_152 )
V_147 = ( T_5 ) V_145 ;
else if ( V_146 < 0 )
V_147 = 0 ;
F_42 ( V_2 -> V_10 , L_13 , V_144 ,
( unsigned long long ) V_147 ) ;
V_48 -> V_153 = V_144 ;
V_48 -> V_154 = 0 ;
V_48 -> V_155 = V_147 ;
switch ( V_144 ) {
case V_156 :
V_149 = V_157 ;
break;
case V_158 :
V_149 = V_159 ;
break;
case V_150 :
V_149 = V_160 ;
break;
case V_161 :
V_149 = V_162 ;
break;
case V_163 :
V_149 = V_164 ;
F_39 ( V_94 , 0 ) ;
break;
case V_151 :
V_149 = V_165 ;
break;
case V_166 :
case V_167 :
F_61 ( V_48 , V_133 , V_144 , false ) ;
F_61 ( V_48 , V_136 , V_145 , false ) ;
break;
case V_152 :
V_149 = V_168 ;
V_147 &= ~ ( ( T_5 ) ( V_169 - 1 ) ) ;
if ( F_24 ( V_48 ) ) {
V_48 -> V_59 . V_69 =
F_24 ( V_48 ) ;
F_25 ( V_48 , 0 ) ;
}
break;
}
if ( ! V_149 )
return;
F_9 ( V_2 , V_170 ,
( V_48 -> V_39 << 16 ) | ( ( V_147 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_170 ) ;
F_9 ( V_2 , V_121 , F_64 ( V_147 ) ) ;
( void ) F_8 ( V_2 , V_121 ) ;
F_53 ( V_48 , V_149 ) ;
F_57 ( V_94 , V_97 ) ;
if ( V_149 == V_165 ||
V_149 == V_168 ) {
T_1 * V_171 = ( T_1 * ) V_2 -> V_171 ;
int V_72 ;
F_65 ( V_2 -> V_115 ) ;
for ( V_72 = 0 ; V_72 < V_172 ; V_72 ++ )
V_171 [ V_72 ] = F_66 ( F_11 ( V_2 , V_72 ) ) ;
F_67 ( V_2 -> V_115 ) ;
if ( V_48 -> V_59 . V_69 )
F_25 ( V_48 ,
V_48 -> V_59 . V_69 ) ;
}
if ( V_144 == V_163 )
F_39 ( V_94 , 1 ) ;
}
static T_6 F_68 ( struct V_93 * V_94 )
{
struct V_96 * V_97 = F_40 ( V_94 ) ;
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_6 V_173 = 0 ;
int V_147 , V_3 ;
switch ( V_48 -> V_153 ) {
case V_150 :
if ( V_48 -> V_154 < 4 )
V_173 = F_8 ( V_2 , V_174 ) >>
( 24 - ( V_48 -> V_154 << 3 ) ) ;
else if ( V_48 -> V_154 < 8 )
V_173 = F_8 ( V_2 , V_175 ) >>
( 56 - ( V_48 -> V_154 << 3 ) ) ;
break;
case V_161 :
V_173 = F_43 ( V_2 , V_48 -> V_154 ) ;
break;
case V_158 :
V_173 = F_8 ( V_2 , V_123 ) &
V_129 ;
if ( V_98 )
V_173 |= V_176 ;
break;
case V_151 :
case V_152 :
V_147 = V_48 -> V_155 + V_48 -> V_154 ;
V_3 = V_147 & ( V_169 - 1 ) ;
if ( V_48 -> V_154 > 0 && V_3 == 0 )
V_97 -> V_177 ( V_94 , V_152 , V_147 , - 1 ) ;
V_173 = V_2 -> V_171 [ V_3 ] ;
break;
case V_167 :
if ( V_48 -> V_154 >= V_178 ) {
V_173 = 0 ;
} else {
bool V_179 = V_48 -> V_154 ==
V_178 - 1 ;
F_61 ( V_48 , V_139 , 0 , V_179 ) ;
V_173 = F_8 ( V_2 , V_180 ) & 0xff ;
}
}
F_42 ( V_2 -> V_10 , L_14 , V_173 ) ;
V_48 -> V_154 ++ ;
return V_173 ;
}
static void F_69 ( struct V_93 * V_94 , T_6 * V_65 , int V_181 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_181 ; V_72 ++ , V_65 ++ )
* V_65 = F_68 ( V_94 ) ;
}
static void F_70 ( struct V_93 * V_94 , const T_6 * V_65 ,
int V_181 )
{
int V_72 ;
struct V_96 * V_97 = F_40 ( V_94 ) ;
struct V_47 * V_48 = F_41 ( V_97 ) ;
switch ( V_48 -> V_153 ) {
case V_166 :
for ( V_72 = 0 ; V_72 < V_181 ; V_72 ++ )
F_61 ( V_48 , V_138 , V_65 [ V_72 ] ,
( V_72 + 1 ) == V_181 ) ;
break;
default:
F_71 () ;
break;
}
}
static int F_72 ( struct V_47 * V_48 ,
struct V_182 * V_183 , T_5 V_147 ,
T_7 V_65 , T_1 V_181 , T_3 V_184 ,
bool V_185 , bool V_186 ,
T_7 V_187 )
{
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_187 = F_64 ( V_187 ) ;
V_183 -> V_188 = F_73 ( V_187 ) ;
V_183 -> V_189 = ( V_184 << 24 ) |
( V_186 ? ( 0x03 << 8 ) : 0 ) |
( ! ! V_185 ) | ( ( ! ! V_186 ) << 1 ) ;
#ifdef F_74
V_183 -> V_189 |= 0x01 << 12 ;
#endif
V_183 -> V_190 = F_64 ( V_65 ) ;
V_183 -> V_191 = F_73 ( V_65 ) ;
V_183 -> V_192 = V_181 ;
V_183 -> V_193 = V_181 ;
V_183 -> V_194 = F_64 ( V_147 ) ;
V_183 -> V_195 = F_73 ( V_147 ) ;
V_183 -> V_39 = V_48 -> V_39 ;
V_183 -> V_196 = 0x01 ;
return 0 ;
}
static void F_75 ( struct V_47 * V_48 , T_7 V_183 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned long V_128 = F_58 ( 100 ) ;
F_32 ( V_2 , V_197 , F_64 ( V_183 ) ) ;
( void ) F_33 ( V_2 , V_197 ) ;
F_32 ( V_2 , V_198 , F_73 ( V_183 ) ) ;
( void ) F_33 ( V_2 , V_198 ) ;
V_2 -> V_112 = true ;
F_55 () ;
F_32 ( V_2 , V_199 , 0x03 ) ;
if ( F_59 ( & V_2 -> V_118 , V_128 ) <= 0 ) {
F_6 ( V_2 -> V_10 ,
L_15 ,
F_33 ( V_2 , V_200 ) ,
F_33 ( V_2 , V_201 ) ) ;
}
V_2 -> V_112 = false ;
F_32 ( V_2 , V_199 , 0 ) ;
}
static int F_76 ( struct V_47 * V_48 , T_5 V_147 , T_1 * V_65 ,
T_1 V_181 , T_3 V_184 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_7 V_202 ;
int V_203 = V_184 == V_204 ? V_205 : V_206 ;
V_202 = F_77 ( V_2 -> V_10 , V_65 , V_181 , V_203 ) ;
if ( F_78 ( V_2 -> V_10 , V_202 ) ) {
F_6 ( V_2 -> V_10 , L_16 ) ;
return - V_207 ;
}
F_72 ( V_48 , V_2 -> V_208 , V_147 , V_202 , V_181 ,
V_184 , true , true , 0 ) ;
F_75 ( V_48 , V_2 -> V_209 ) ;
F_79 ( V_2 -> V_10 , V_202 , V_181 , V_203 ) ;
if ( V_2 -> V_208 -> V_196 & V_210 )
return - V_211 ;
else if ( V_2 -> V_208 -> V_196 & V_212 )
return - V_213 ;
return 0 ;
}
static int F_80 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_5 V_147 , unsigned int V_214 , T_1 * V_65 ,
T_3 * V_108 , T_5 * V_215 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
int V_72 , V_73 , V_173 = 0 ;
F_9 ( V_2 , V_216 , 0 ) ;
F_9 ( V_2 , V_217 , 0 ) ;
F_9 ( V_2 , V_218 , 0 ) ;
F_9 ( V_2 , V_219 , 0 ) ;
F_9 ( V_2 , V_170 ,
( V_48 -> V_39 << 16 ) | ( ( V_147 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_170 ) ;
for ( V_72 = 0 ; V_72 < V_214 ; V_72 ++ , V_147 += V_169 ) {
F_9 ( V_2 , V_121 ,
F_64 ( V_147 ) ) ;
( void ) F_8 ( V_2 , V_121 ) ;
F_53 ( V_48 , V_204 ) ;
F_57 ( V_94 , V_97 ) ;
if ( F_30 ( V_65 ) ) {
F_65 ( V_2 -> V_115 ) ;
for ( V_73 = 0 ; V_73 < V_172 ; V_73 ++ , V_65 ++ )
* V_65 = F_11 ( V_2 , V_73 ) ;
F_67 ( V_2 -> V_115 ) ;
}
if ( V_108 )
V_108 += F_45 ( V_2 , V_72 , V_108 ,
V_94 -> V_220 / V_214 ,
V_48 -> V_59 . V_69 ) ;
if ( ! V_173 ) {
* V_215 = F_8 ( V_2 ,
V_216 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_218 )
& 0xffff ) << 32 ) ;
if ( * V_215 )
V_173 = - V_211 ;
}
if ( ! V_173 ) {
* V_215 = F_8 ( V_2 ,
V_217 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_219 )
& 0xffff ) << 32 ) ;
if ( * V_215 )
V_173 = - V_213 ;
}
}
return V_173 ;
}
static int F_81 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_5 V_147 , unsigned int V_214 , T_1 * V_65 , T_3 * V_108 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_5 V_215 = 0 ;
int V_221 ;
F_42 ( V_2 -> V_10 , L_17 , ( unsigned long long ) V_147 , V_65 ) ;
F_9 ( V_2 , V_222 , 0 ) ;
if ( F_27 ( V_2 ) && ! V_108 && F_28 ( V_65 ) ) {
V_221 = F_76 ( V_48 , V_147 , V_65 , V_214 * V_169 ,
V_204 ) ;
if ( V_221 ) {
if ( F_82 ( V_221 ) )
V_215 = V_147 ;
else
return - V_223 ;
}
} else {
if ( V_108 )
memset ( V_108 , 0x99 , V_94 -> V_220 ) ;
V_221 = F_80 ( V_94 , V_97 , V_147 , V_214 , V_65 ,
V_108 , & V_215 ) ;
}
if ( F_83 ( V_221 ) ) {
F_42 ( V_2 -> V_10 , L_18 ,
( unsigned long long ) V_215 ) ;
V_94 -> V_224 . V_225 ++ ;
return 0 ;
}
if ( F_84 ( V_221 ) ) {
unsigned int V_226 = F_16 ( V_2 ) ;
F_42 ( V_2 -> V_10 , L_19 ,
( unsigned long long ) V_215 ) ;
V_94 -> V_224 . V_226 += V_226 ;
return F_46 ( V_94 -> V_227 , V_226 ) ;
}
return 0 ;
}
static int F_85 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_6 * V_65 , int V_228 , int V_229 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
T_3 * V_108 = V_228 ? ( T_3 * ) V_97 -> V_230 : NULL ;
return F_81 ( V_94 , V_97 , V_48 -> V_155 ,
V_94 -> V_231 >> V_232 , ( T_1 * ) V_65 , V_108 ) ;
}
static int F_86 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_6 * V_65 , int V_228 , int V_229 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
T_3 * V_108 = V_228 ? ( T_3 * ) V_97 -> V_230 : NULL ;
int V_173 ;
F_22 ( V_48 , 0 ) ;
V_173 = F_81 ( V_94 , V_97 , V_48 -> V_155 ,
V_94 -> V_231 >> V_232 , ( T_1 * ) V_65 , V_108 ) ;
F_22 ( V_48 , 1 ) ;
return V_173 ;
}
static int F_87 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_229 )
{
return F_81 ( V_94 , V_97 , ( T_5 ) V_229 << V_97 -> V_148 ,
V_94 -> V_231 >> V_232 ,
NULL , ( T_3 * ) V_97 -> V_230 ) ;
}
static int F_88 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_229 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
F_22 ( V_48 , 0 ) ;
F_81 ( V_94 , V_97 , ( T_5 ) V_229 << V_97 -> V_148 ,
V_94 -> V_231 >> V_232 ,
NULL , ( T_3 * ) V_97 -> V_230 ) ;
F_22 ( V_48 , 1 ) ;
return 0 ;
}
static int F_89 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_5 V_147 , const T_1 * V_65 , T_3 * V_108 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned int V_72 , V_73 , V_214 = V_94 -> V_231 >> V_232 ;
int V_233 , V_173 = 0 ;
F_42 ( V_2 -> V_10 , L_20 , ( unsigned long long ) V_147 , V_65 ) ;
if ( F_90 ( ( unsigned long ) V_65 & 0x03 ) ) {
F_91 ( V_2 -> V_10 , L_21 , V_65 ) ;
V_65 = ( T_1 * ) ( ( unsigned long ) V_65 & ~ 0x03 ) ;
}
F_39 ( V_94 , 0 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_25 ; V_72 += 4 )
F_44 ( V_2 , V_72 , 0xffffffff ) ;
if ( F_27 ( V_2 ) && ! V_108 && F_28 ( V_65 ) ) {
if ( F_76 ( V_48 , V_147 , ( T_1 * ) V_65 ,
V_94 -> V_231 , V_234 ) )
V_173 = - V_223 ;
goto V_89;
}
F_9 ( V_2 , V_170 ,
( V_48 -> V_39 << 16 ) | ( ( V_147 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_170 ) ;
for ( V_72 = 0 ; V_72 < V_214 ; V_72 ++ , V_147 += V_169 ) {
F_9 ( V_2 , V_121 ,
F_64 ( V_147 ) ) ;
( void ) F_8 ( V_2 , V_121 ) ;
if ( V_65 ) {
F_65 ( V_2 -> V_115 ) ;
for ( V_73 = 0 ; V_73 < V_172 ; V_73 ++ , V_65 ++ )
F_13 ( V_2 , V_73 , * V_65 ) ;
F_67 ( V_2 -> V_115 ) ;
} else if ( V_108 ) {
for ( V_73 = 0 ; V_73 < V_172 ; V_73 ++ )
F_13 ( V_2 , V_73 , 0xffffffff ) ;
}
if ( V_108 ) {
V_108 += F_48 ( V_2 , V_72 , V_108 ,
V_94 -> V_220 / V_214 ,
V_48 -> V_59 . V_69 ) ;
}
F_53 ( V_48 , V_234 ) ;
V_233 = F_57 ( V_94 , V_97 ) ;
if ( V_233 & V_235 ) {
F_92 ( V_2 -> V_10 , L_22 ,
( unsigned long long ) V_147 ) ;
V_173 = - V_223 ;
goto V_89;
}
}
V_89:
F_39 ( V_94 , 1 ) ;
return V_173 ;
}
static int F_93 ( struct V_93 * V_94 , struct V_96 * V_97 ,
const T_6 * V_65 , int V_228 , int V_229 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
void * V_108 = V_228 ? V_97 -> V_230 : NULL ;
F_89 ( V_94 , V_97 , V_48 -> V_155 , ( const T_1 * ) V_65 , V_108 ) ;
return 0 ;
}
static int F_94 ( struct V_93 * V_94 ,
struct V_96 * V_97 , const T_6 * V_65 ,
int V_228 , int V_229 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
void * V_108 = V_228 ? V_97 -> V_230 : NULL ;
F_22 ( V_48 , 0 ) ;
F_89 ( V_94 , V_97 , V_48 -> V_155 , ( const T_1 * ) V_65 , V_108 ) ;
F_22 ( V_48 , 1 ) ;
return 0 ;
}
static int F_95 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_229 )
{
return F_89 ( V_94 , V_97 , ( T_5 ) V_229 << V_97 -> V_148 ,
NULL , V_97 -> V_230 ) ;
}
static int F_96 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_229 )
{
struct V_47 * V_48 = F_41 ( V_97 ) ;
int V_173 ;
F_22 ( V_48 , 0 ) ;
V_173 = F_89 ( V_94 , V_97 , ( T_5 ) V_229 << V_97 -> V_148 , NULL ,
( T_3 * ) V_97 -> V_230 ) ;
F_22 ( V_48 , 1 ) ;
return V_173 ;
}
static int F_97 ( struct V_47 * V_48 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_96 * V_97 = & V_48 -> V_97 ;
T_2 V_236 = F_15 ( V_2 , V_48 -> V_39 , V_237 ) ;
T_2 V_238 = F_15 ( V_2 , V_48 -> V_39 ,
V_239 ) ;
T_2 V_61 = F_15 ( V_2 , V_48 -> V_39 ,
V_54 ) ;
T_3 V_240 = 0 , V_82 = 0 , V_241 = 0 ;
T_1 V_36 ;
if ( V_2 -> V_24 ) {
int V_72 , V_242 ;
for ( V_72 = 0 , V_242 = 0 ; V_2 -> V_24 [ V_72 ] ; V_72 ++ )
if ( V_2 -> V_24 [ V_72 ] * 1024 == V_68 -> V_240 ) {
V_240 = V_72 ;
V_242 = 1 ;
}
if ( ! V_242 ) {
F_91 ( V_2 -> V_10 , L_23 ,
V_68 -> V_240 ) ;
return - V_243 ;
}
} else {
V_240 = F_98 ( V_68 -> V_240 ) - F_98 ( V_244 ) ;
}
if ( V_68 -> V_240 < V_244 || ( V_2 -> V_23 &&
V_68 -> V_240 > V_2 -> V_23 ) ) {
F_91 ( V_2 -> V_10 , L_23 ,
V_68 -> V_240 ) ;
V_240 = 0 ;
}
if ( V_2 -> V_8 ) {
int V_72 , V_242 ;
for ( V_72 = 0 , V_242 = 0 ; V_2 -> V_8 [ V_72 ] ; V_72 ++ )
if ( V_2 -> V_8 [ V_72 ] == V_68 -> V_82 ) {
V_82 = V_72 ;
V_242 = 1 ;
}
if ( ! V_242 ) {
F_91 ( V_2 -> V_10 , L_24 ,
V_68 -> V_82 ) ;
return - V_243 ;
}
} else {
V_82 = F_98 ( V_68 -> V_82 ) - F_98 ( V_245 ) ;
}
if ( V_68 -> V_82 < V_245 || ( V_2 -> V_22 &&
V_68 -> V_82 > V_2 -> V_22 ) ) {
F_91 ( V_2 -> V_10 , L_24 , V_68 -> V_82 ) ;
return - V_243 ;
}
if ( F_99 ( V_68 -> V_241 ) < F_99 ( V_246 ) ) {
F_91 ( V_2 -> V_10 , L_25 ,
( unsigned long long ) V_68 -> V_241 ) ;
return - V_243 ;
}
V_241 = F_99 ( V_68 -> V_241 ) - F_99 ( V_246 ) ;
V_36 = ( V_68 -> V_247 << V_248 ) |
( V_68 -> V_249 << V_250 ) |
( V_68 -> V_251 << V_252 ) |
( ! ! ( V_68 -> V_253 == 16 ) << V_254 ) |
( V_241 << V_255 ) ;
if ( V_236 == V_238 ) {
V_36 |= ( V_82 << V_256 ) |
( V_240 << V_257 ) ;
F_3 ( V_2 , V_236 , V_36 ) ;
} else {
F_3 ( V_2 , V_236 , V_36 ) ;
V_36 = ( V_82 << V_258 ) |
( V_240 << V_259 ) ;
F_3 ( V_2 , V_238 , V_36 ) ;
}
V_36 = F_1 ( V_2 , V_61 ) ;
V_36 &= ~ F_21 ( V_2 ) ;
V_36 |= V_68 -> V_60 << V_52 ;
V_36 &= ~ F_19 ( V_2 ) ;
V_36 |= V_68 -> V_70 ;
F_3 ( V_2 , V_61 , V_36 ) ;
F_25 ( V_48 , V_68 -> V_69 ) ;
F_17 ( V_48 , F_37 ( V_97 -> V_260 . V_261 * 3 , 4 ) ) ;
return 0 ;
}
static void F_100 ( char * V_65 , struct V_67 * V_68 )
{
V_65 += sprintf ( V_65 ,
L_26 ,
( unsigned long long ) V_68 -> V_241 >> 20 ,
V_68 -> V_240 >> 10 ,
V_68 -> V_82 >= 1024 ? V_68 -> V_82 >> 10 : V_68 -> V_82 ,
V_68 -> V_82 >= 1024 ? L_27 : L_28 ,
V_68 -> V_70 , V_68 -> V_253 ) ;
if ( F_34 ( V_68 ) )
sprintf ( V_65 , L_29 ) ;
else if ( V_68 -> V_69 )
sprintf ( V_65 , L_30 , V_68 -> V_60 << 1 ) ;
else
sprintf ( V_65 , L_31 , V_68 -> V_60 ) ;
}
static inline int F_101 ( T_5 V_262 , T_1 V_231 )
{
return F_102 ( F_103 ( V_262 ) - F_103 ( V_231 ) , 8 ) >> 3 ;
}
static int F_104 ( struct V_47 * V_48 )
{
struct V_93 * V_94 = F_62 ( & V_48 -> V_97 ) ;
struct V_96 * V_97 = & V_48 -> V_97 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_67 * V_68 = & V_48 -> V_59 ;
char V_263 [ 128 ] ;
T_1 V_3 , V_36 , V_264 ;
int V_173 ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_173 = F_105 ( F_106 ( V_97 ) ,
L_32 ,
& V_264 ) ;
if ( V_173 ) {
V_68 -> V_70 = V_94 -> V_220 /
( V_94 -> V_231 >> V_232 ) ;
} else {
V_68 -> V_70 = V_264 ;
}
if ( V_68 -> V_70 > V_2 -> V_25 )
V_68 -> V_70 = V_2 -> V_25 ;
V_94 -> V_220 = V_68 -> V_70 * ( V_94 -> V_231 >> V_232 ) ;
V_68 -> V_241 = V_94 -> V_262 ;
V_68 -> V_240 = V_94 -> V_265 ;
V_68 -> V_82 = V_94 -> V_231 ;
V_68 -> V_253 = ( V_97 -> V_266 & V_267 ) ? 16 : 8 ;
V_68 -> V_249 = 2 ;
V_68 -> V_247 = F_101 ( V_94 -> V_262 , V_94 -> V_231 ) ;
switch ( V_97 -> V_260 . V_262 ) {
case 512 :
if ( V_97 -> V_260 . V_261 == 1 )
V_68 -> V_60 = 15 ;
else
V_68 -> V_60 = V_97 -> V_260 . V_261 ;
V_68 -> V_69 = 0 ;
break;
case 1024 :
if ( ! ( V_2 -> V_26 & V_29 ) ) {
F_6 ( V_2 -> V_10 , L_33 ) ;
return - V_243 ;
}
if ( V_97 -> V_260 . V_261 & 0x1 ) {
F_6 ( V_2 -> V_10 ,
L_34 ) ;
return - V_243 ;
}
V_68 -> V_60 = V_97 -> V_260 . V_261 >> 1 ;
V_68 -> V_69 = 1 ;
break;
default:
F_6 ( V_2 -> V_10 , L_35 ,
V_97 -> V_260 . V_262 ) ;
return - V_243 ;
}
V_68 -> V_251 = V_68 -> V_247 ;
if ( V_94 -> V_231 > 512 )
V_68 -> V_251 += V_68 -> V_249 ;
else
V_68 -> V_251 += 1 ;
V_173 = F_97 ( V_48 , V_68 ) ;
if ( V_173 )
return V_173 ;
F_22 ( V_48 , 1 ) ;
F_100 ( V_263 , V_68 ) ;
F_92 ( V_2 -> V_10 , L_36 , V_263 ) ;
V_3 = F_15 ( V_2 , V_48 -> V_39 , V_54 ) ;
V_36 = F_1 ( V_2 , V_3 ) ;
V_36 &= ~ V_268 ;
V_36 &= ~ V_269 ;
V_36 &= ~ V_270 ;
if ( V_2 -> V_26 & V_27 ) {
if ( F_27 ( V_2 ) )
V_36 &= ~ V_271 ;
else
V_36 |= V_271 ;
}
F_3 ( V_2 , V_3 , V_36 ) ;
return 0 ;
}
static int F_107 ( struct V_47 * V_48 , struct V_272 * V_273 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_274 * V_80 = V_48 -> V_80 ;
struct V_93 * V_94 ;
struct V_96 * V_97 ;
int V_173 ;
T_2 V_236 ;
V_173 = F_105 ( V_273 , L_37 , & V_48 -> V_39 ) ;
if ( V_173 ) {
F_6 ( & V_80 -> V_10 , L_38 ) ;
return - V_275 ;
}
V_94 = F_62 ( & V_48 -> V_97 ) ;
V_97 = & V_48 -> V_97 ;
F_108 ( V_97 , V_273 ) ;
F_109 ( V_97 , V_48 ) ;
V_94 -> V_276 = F_110 ( & V_80 -> V_10 , V_81 , L_39 ,
V_48 -> V_39 ) ;
V_94 -> V_277 = V_278 ;
V_94 -> V_10 . V_279 = & V_80 -> V_10 ;
V_97 -> V_280 = ( void V_281 * ) 0xdeadbeef ;
V_97 -> V_282 = ( void V_281 * ) 0xdeadbeef ;
V_97 -> V_283 = F_56 ;
V_97 -> V_177 = F_63 ;
V_97 -> V_284 = F_57 ;
V_97 -> V_285 = F_68 ;
V_97 -> V_286 = F_69 ;
V_97 -> V_287 = F_70 ;
V_97 -> V_260 . V_288 = V_289 ;
V_97 -> V_260 . V_290 = F_85 ;
V_97 -> V_260 . V_291 = F_93 ;
V_97 -> V_260 . V_292 = F_86 ;
V_97 -> V_260 . V_293 = F_94 ;
V_97 -> V_260 . V_294 = F_96 ;
V_97 -> V_260 . V_295 = F_88 ;
V_97 -> V_260 . V_296 = F_87 ;
V_97 -> V_260 . V_297 = F_95 ;
V_97 -> V_298 = & V_2 -> V_298 ;
V_236 = F_15 ( V_2 , V_48 -> V_39 , V_237 ) ;
F_3 ( V_2 , V_236 ,
F_1 ( V_2 , V_236 ) & ~ V_299 ) ;
if ( F_111 ( V_94 , 1 , NULL ) )
return - V_275 ;
V_97 -> V_266 |= V_300 ;
V_97 -> V_266 |= V_301 ;
if ( F_112 ( V_273 ) )
V_97 -> V_302 |= V_303 | V_304 ;
if ( F_104 ( V_48 ) )
return - V_275 ;
V_97 -> V_260 . V_262 = V_48 -> V_59 . V_69 ? 1024 : 512 ;
V_94 -> V_227 = 1 ;
V_97 -> V_260 . V_74 = F_38 ( V_48 ) ;
if ( ! V_97 -> V_260 . V_74 )
return - V_275 ;
if ( F_113 ( V_94 ) )
return - V_275 ;
return F_114 ( V_94 , NULL , 0 ) ;
}
static void F_115 ( struct V_47 * V_48 ,
int V_305 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_2 V_236 = F_15 ( V_2 , V_48 -> V_39 , V_237 ) ;
T_2 V_238 = F_15 ( V_2 , V_48 -> V_39 ,
V_239 ) ;
T_2 V_61 = F_15 ( V_2 , V_48 -> V_39 ,
V_54 ) ;
T_2 V_306 = F_15 ( V_2 , V_48 -> V_39 , V_307 ) ;
T_2 V_308 = F_15 ( V_2 , V_48 -> V_39 , V_309 ) ;
if ( V_305 ) {
F_3 ( V_2 , V_236 , V_48 -> V_59 . V_310 ) ;
if ( V_236 != V_238 )
F_3 ( V_2 , V_238 ,
V_48 -> V_59 . V_311 ) ;
F_3 ( V_2 , V_61 , V_48 -> V_59 . V_55 ) ;
F_3 ( V_2 , V_306 , V_48 -> V_59 . V_312 ) ;
F_3 ( V_2 , V_308 , V_48 -> V_59 . V_313 ) ;
} else {
V_48 -> V_59 . V_310 = F_1 ( V_2 , V_236 ) ;
if ( V_236 != V_238 )
V_48 -> V_59 . V_311 =
F_1 ( V_2 , V_238 ) ;
V_48 -> V_59 . V_55 = F_1 ( V_2 , V_61 ) ;
V_48 -> V_59 . V_312 = F_1 ( V_2 , V_306 ) ;
V_48 -> V_59 . V_313 = F_1 ( V_2 , V_308 ) ;
}
}
static int F_116 ( struct V_314 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
struct V_47 * V_48 ;
F_118 (host, &ctrl->host_list, node)
F_115 ( V_48 , 0 ) ;
V_2 -> V_315 = F_8 ( V_2 , V_63 ) ;
V_2 -> V_316 = F_8 ( V_2 , V_317 ) ;
V_2 -> V_318 =
F_8 ( V_2 , V_50 ) ;
if ( F_27 ( V_2 ) )
V_2 -> V_319 = F_33 ( V_2 , V_320 ) ;
return 0 ;
}
static int F_119 ( struct V_314 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
struct V_47 * V_48 ;
if ( F_27 ( V_2 ) ) {
F_32 ( V_2 , V_320 , V_2 -> V_319 ) ;
F_32 ( V_2 , V_201 , 0 ) ;
}
F_9 ( V_2 , V_63 , V_2 -> V_315 ) ;
F_9 ( V_2 , V_317 , V_2 -> V_316 ) ;
F_9 ( V_2 , V_50 ,
V_2 -> V_318 ) ;
if ( V_2 -> V_115 ) {
V_2 -> V_115 -> V_116 ( V_2 -> V_115 ) ;
V_2 -> V_115 -> V_321 ( V_2 -> V_115 , true ) ;
}
F_118 (host, &ctrl->host_list, node) {
struct V_96 * V_97 = & V_48 -> V_97 ;
struct V_93 * V_94 = F_62 ( V_97 ) ;
F_115 ( V_48 , 1 ) ;
V_97 -> V_177 ( V_94 , V_156 , - 1 , - 1 ) ;
}
return 0 ;
}
int F_120 ( struct V_274 * V_80 , struct V_322 * V_115 )
{
struct V_314 * V_10 = & V_80 -> V_10 ;
struct V_272 * V_273 = V_10 -> V_31 , * V_323 ;
struct V_1 * V_2 ;
struct V_324 * V_325 ;
int V_173 ;
if ( ! V_273 )
return - V_11 ;
if ( ! F_121 ( V_326 , V_273 ) )
return - V_11 ;
V_2 = F_36 ( V_10 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_207 ;
F_122 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
F_123 ( & V_2 -> V_114 ) ;
F_123 ( & V_2 -> V_118 ) ;
F_124 ( & V_2 -> V_298 . V_327 ) ;
F_125 ( & V_2 -> V_298 . V_328 ) ;
F_126 ( & V_2 -> V_329 ) ;
V_325 = F_127 ( V_80 , V_330 , 0 ) ;
V_2 -> V_4 = F_128 ( V_10 , V_325 ) ;
if ( F_129 ( V_2 -> V_4 ) )
return F_130 ( V_2 -> V_4 ) ;
V_2 -> V_331 = F_131 ( V_10 , L_40 ) ;
if ( ! F_129 ( V_2 -> V_331 ) ) {
V_173 = F_132 ( V_2 -> V_331 ) ;
if ( V_173 )
return V_173 ;
} else {
V_173 = F_130 ( V_2 -> V_331 ) ;
if ( V_173 == - V_332 )
return V_173 ;
V_2 -> V_331 = NULL ;
}
V_173 = F_5 ( V_2 ) ;
if ( V_173 )
goto V_221;
V_325 = F_133 ( V_80 , V_330 , L_41 ) ;
if ( V_325 ) {
V_2 -> V_38 = F_128 ( V_10 , V_325 ) ;
if ( F_129 ( V_2 -> V_38 ) ) {
V_173 = F_130 ( V_2 -> V_38 ) ;
goto V_221;
}
} else {
V_2 -> V_38 = V_2 -> V_4 +
V_2 -> V_12 [ V_333 ] ;
}
V_325 = F_133 ( V_80 , V_330 , L_42 ) ;
if ( V_325 ) {
V_2 -> V_64 = F_128 ( V_10 , V_325 ) ;
if ( F_129 ( V_2 -> V_64 ) ) {
V_173 = F_130 ( V_2 -> V_64 ) ;
goto V_221;
}
F_32 ( V_2 , V_320 , 1 ) ;
F_32 ( V_2 , V_201 , 0 ) ;
V_2 -> V_208 = F_134 ( V_10 ,
sizeof( * V_2 -> V_208 ) ,
& V_2 -> V_209 , V_81 ) ;
if ( ! V_2 -> V_208 ) {
V_173 = - V_207 ;
goto V_221;
}
V_2 -> V_334 = F_135 ( V_80 , 1 ) ;
if ( ( int ) V_2 -> V_334 < 0 ) {
F_6 ( V_10 , L_43 ) ;
V_173 = - V_11 ;
goto V_221;
}
V_173 = F_136 ( V_10 , V_2 -> V_334 ,
F_52 , 0 , V_335 ,
V_2 ) ;
if ( V_173 < 0 ) {
F_6 ( V_10 , L_44 ,
V_2 -> V_334 , V_173 ) ;
goto V_221;
}
F_92 ( V_10 , L_45 ) ;
}
F_10 ( V_2 , V_63 ,
V_336 | 0xff , 0 , 0 ) ;
F_10 ( V_2 , V_317 , 0xff , 0 , 0 ) ;
if ( V_2 -> V_26 & V_30 ) {
if ( V_98 == 2 )
F_26 ( V_2 , false ) ;
} else {
V_98 = 0 ;
}
V_2 -> V_111 = F_135 ( V_80 , 0 ) ;
if ( ( int ) V_2 -> V_111 < 0 ) {
F_6 ( V_10 , L_46 ) ;
V_173 = - V_11 ;
goto V_221;
}
if ( V_115 ) {
V_2 -> V_115 = V_115 ;
V_173 = F_136 ( V_10 , V_2 -> V_111 , F_51 , 0 ,
V_335 , V_2 ) ;
V_2 -> V_115 -> V_116 ( V_2 -> V_115 ) ;
V_2 -> V_115 -> V_321 ( V_2 -> V_115 , true ) ;
} else {
V_173 = F_136 ( V_10 , V_2 -> V_111 , F_49 , 0 ,
V_335 , V_2 ) ;
}
if ( V_173 < 0 ) {
F_6 ( V_10 , L_44 ,
V_2 -> V_111 , V_173 ) ;
goto V_221;
}
F_137 (dn, child) {
if ( F_138 ( V_323 , L_47 ) ) {
struct V_47 * V_48 ;
V_48 = F_36 ( V_10 , sizeof( * V_48 ) , V_81 ) ;
if ( ! V_48 ) {
F_139 ( V_323 ) ;
V_173 = - V_207 ;
goto V_221;
}
V_48 -> V_80 = V_80 ;
V_48 -> V_2 = V_2 ;
V_173 = F_107 ( V_48 , V_323 ) ;
if ( V_173 ) {
F_140 ( V_10 , V_48 ) ;
continue;
}
F_141 ( & V_48 -> V_337 , & V_2 -> V_329 ) ;
}
}
if ( F_142 ( & V_2 -> V_329 ) ) {
V_173 = - V_11 ;
goto V_221;
}
return 0 ;
V_221:
F_143 ( V_2 -> V_331 ) ;
return V_173 ;
}
int F_144 ( struct V_274 * V_80 )
{
struct V_1 * V_2 = F_117 ( & V_80 -> V_10 ) ;
struct V_47 * V_48 ;
F_118 (host, &ctrl->host_list, node)
F_145 ( F_62 ( & V_48 -> V_97 ) ) ;
F_143 ( V_2 -> V_331 ) ;
F_122 ( & V_80 -> V_10 , NULL ) ;
return 0 ;
}
