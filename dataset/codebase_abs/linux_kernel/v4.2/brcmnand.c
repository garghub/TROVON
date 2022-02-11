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
struct V_96 * V_97 = V_94 -> V_98 ;
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
if ( ( V_2 -> V_26 & V_30 ) && V_99 == 1 ) {
static int V_100 = - 1 ;
if ( V_100 != V_95 ) {
F_40 ( V_2 -> V_10 , L_5 , V_95 ? L_6 : L_7 ) ;
V_100 = V_95 ;
}
F_26 ( V_2 , V_95 ) ;
}
}
static inline T_3 F_41 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_101 , V_102 , V_103 ;
V_101 = V_2 -> V_12 [ V_104 ] ;
V_102 = V_2 -> V_12 [ V_105 ] ;
if ( V_3 >= V_2 -> V_25 )
return 0x77 ;
if ( V_3 >= 16 && V_102 )
V_103 = V_102 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_103 = V_101 + ( V_3 & ~ 0x03 ) ;
return F_1 ( V_2 , V_103 ) >> ( 24 - ( ( V_3 & 0x03 ) << 3 ) ) ;
}
static inline void F_42 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_106 )
{
T_2 V_101 , V_102 , V_103 ;
V_101 = V_2 -> V_12 [ V_107 ] ;
V_102 = V_2 -> V_12 [ V_108 ] ;
if ( V_3 >= V_2 -> V_25 )
return;
if ( V_3 >= 16 && V_102 )
V_103 = V_102 + ( ( V_3 - 0x10 ) & ~ 0x03 ) ;
else
V_103 = V_101 + ( V_3 & ~ 0x03 ) ;
F_3 ( V_2 , V_103 , V_106 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_72 , T_3 * V_109 ,
int V_77 , int V_110 )
{
int V_111 = V_77 << V_110 ;
int V_73 ;
if ( V_110 && ( V_72 & 0x01 ) )
V_111 = F_44 ( 0 , V_111 - ( int ) V_2 -> V_25 ) ;
V_111 = F_45 ( int , V_111 , V_2 -> V_25 ) ;
for ( V_73 = 0 ; V_73 < V_111 ; V_73 ++ )
V_109 [ V_73 ] = F_41 ( V_2 , V_73 ) ;
return V_111 ;
}
static int F_46 ( struct V_1 * V_2 , int V_72 ,
const T_3 * V_109 , int V_77 , int V_110 )
{
int V_111 = V_77 << V_110 ;
int V_73 ;
if ( V_110 && ( V_72 & 0x01 ) )
V_111 = F_44 ( 0 , V_111 - ( int ) V_2 -> V_25 ) ;
V_111 = F_45 ( int , V_111 , V_2 -> V_25 ) ;
for ( V_73 = 0 ; V_73 < V_111 ; V_73 += 4 )
F_42 ( V_2 , V_73 ,
( V_109 [ V_73 + 0 ] << 24 ) |
( V_109 [ V_73 + 1 ] << 16 ) |
( V_109 [ V_73 + 2 ] << 8 ) |
( V_109 [ V_73 + 3 ] << 0 ) ) ;
return V_111 ;
}
static T_4 F_47 ( int V_112 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
if ( V_2 -> V_113 )
return V_114 ;
F_48 ( & V_2 -> V_115 ) ;
return V_114 ;
}
static T_4 F_49 ( int V_112 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
if ( V_2 -> V_116 -> V_117 ( V_2 -> V_116 ) )
return F_47 ( V_112 , V_106 ) ;
return V_118 ;
}
static T_4 F_50 ( int V_112 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
F_48 ( & V_2 -> V_119 ) ;
return V_114 ;
}
static void F_51 ( struct V_47 * V_48 , int V_120 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_1 V_121 ;
F_40 ( V_2 -> V_10 , L_8 , V_120 ,
F_8 ( V_2 , V_122 ) ) ;
F_52 ( V_2 -> V_123 != 0 ) ;
V_2 -> V_123 = V_120 ;
V_121 = F_8 ( V_2 , V_124 ) ;
F_52 ( ! ( V_121 & V_125 ) ) ;
F_53 () ;
F_9 ( V_2 , V_126 ,
V_120 << F_18 ( V_2 ) ) ;
}
static void F_54 ( struct V_93 * V_94 , int V_127 ,
unsigned int V_2 )
{
}
static int F_55 ( struct V_93 * V_94 , struct V_96 * V_128 )
{
struct V_96 * V_97 = V_94 -> V_98 ;
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned long V_129 = F_56 ( 100 ) ;
F_40 ( V_2 -> V_10 , L_9 , V_2 -> V_123 ) ;
if ( V_2 -> V_123 &&
F_57 ( & V_2 -> V_115 , V_129 ) <= 0 ) {
T_1 V_120 = F_8 ( V_2 , V_126 )
>> F_18 ( V_2 ) ;
F_58 ( V_2 -> V_10 ,
L_10 , V_120 ) ;
F_58 ( V_2 -> V_10 , L_11 ,
F_8 ( V_2 , V_124 ) ) ;
}
V_2 -> V_123 = 0 ;
return F_8 ( V_2 , V_124 ) &
V_130 ;
}
static int F_59 ( struct V_47 * V_48 ,
enum V_131 type , T_1 V_106 ,
bool V_132 )
{
struct V_93 * V_94 = & V_48 -> V_94 ;
struct V_96 * V_97 = & V_48 -> V_97 ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_1 V_36 ;
V_36 = V_106 & V_133 ;
switch ( type ) {
case V_134 :
V_36 |= V_135 | V_136 ;
break;
case V_137 :
V_36 |= V_135 | V_138 ;
break;
case V_139 :
V_36 |= V_135 ;
break;
case V_140 :
V_36 |= V_141 ;
break;
}
if ( V_132 )
V_36 |= V_142 ;
F_40 ( V_2 -> V_10 , L_12 , V_36 ) ;
F_9 ( V_2 , V_143 , V_36 ) ;
( void ) F_8 ( V_2 , V_143 ) ;
F_51 ( V_48 , V_144 ) ;
return F_55 ( V_94 , V_97 ) ;
}
static void F_60 ( struct V_93 * V_94 , unsigned V_145 ,
int V_146 , int V_147 )
{
struct V_96 * V_97 = V_94 -> V_98 ;
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_5 V_148 = ( T_5 ) V_147 << V_97 -> V_149 ;
int V_150 = 0 ;
if ( V_145 == V_151 || V_145 == V_152 ||
V_145 == V_153 )
V_148 = ( T_5 ) V_146 ;
else if ( V_147 < 0 )
V_148 = 0 ;
F_40 ( V_2 -> V_10 , L_13 , V_145 ,
( unsigned long long ) V_148 ) ;
V_48 -> V_154 = V_145 ;
V_48 -> V_155 = 0 ;
V_48 -> V_156 = V_148 ;
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
F_39 ( V_94 , 0 ) ;
break;
case V_152 :
V_150 = V_166 ;
break;
case V_167 :
case V_168 :
F_59 ( V_48 , V_134 , V_145 , false ) ;
F_59 ( V_48 , V_137 , V_146 , false ) ;
break;
case V_153 :
V_150 = V_169 ;
V_148 &= ~ ( ( T_5 ) ( V_170 - 1 ) ) ;
if ( F_24 ( V_48 ) ) {
V_48 -> V_59 . V_69 =
F_24 ( V_48 ) ;
F_25 ( V_48 , 0 ) ;
}
break;
}
if ( ! V_150 )
return;
F_9 ( V_2 , V_171 ,
( V_48 -> V_39 << 16 ) | ( ( V_148 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_171 ) ;
F_9 ( V_2 , V_122 , F_61 ( V_148 ) ) ;
( void ) F_8 ( V_2 , V_122 ) ;
F_51 ( V_48 , V_150 ) ;
F_55 ( V_94 , V_97 ) ;
if ( V_150 == V_166 ||
V_150 == V_169 ) {
int V_72 ;
F_62 ( V_2 -> V_116 ) ;
for ( V_72 = 0 ; V_72 < V_172 ; V_72 ++ )
V_2 -> V_173 [ V_72 ] = F_11 ( V_2 , V_72 ) ;
F_63 ( V_2 -> V_116 ) ;
if ( V_48 -> V_59 . V_69 )
F_25 ( V_48 ,
V_48 -> V_59 . V_69 ) ;
}
if ( V_145 == V_164 )
F_39 ( V_94 , 1 ) ;
}
static T_6 F_64 ( struct V_93 * V_94 )
{
struct V_96 * V_97 = V_94 -> V_98 ;
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_6 V_174 = 0 ;
int V_148 , V_3 ;
switch ( V_48 -> V_154 ) {
case V_151 :
if ( V_48 -> V_155 < 4 )
V_174 = F_8 ( V_2 , V_175 ) >>
( 24 - ( V_48 -> V_155 << 3 ) ) ;
else if ( V_48 -> V_155 < 8 )
V_174 = F_8 ( V_2 , V_176 ) >>
( 56 - ( V_48 -> V_155 << 3 ) ) ;
break;
case V_162 :
V_174 = F_41 ( V_2 , V_48 -> V_155 ) ;
break;
case V_159 :
V_174 = F_8 ( V_2 , V_124 ) &
V_130 ;
if ( V_99 )
V_174 |= V_177 ;
break;
case V_152 :
case V_153 :
V_148 = V_48 -> V_156 + V_48 -> V_155 ;
V_3 = V_148 & ( V_170 - 1 ) ;
if ( V_48 -> V_155 > 0 && V_3 == 0 )
V_97 -> V_178 ( V_94 , V_153 , V_148 , - 1 ) ;
V_174 = V_2 -> V_173 [ V_3 >> 2 ] >>
( 24 - ( ( V_3 & 0x03 ) << 3 ) ) ;
break;
case V_168 :
if ( V_48 -> V_155 >= V_179 ) {
V_174 = 0 ;
} else {
bool V_180 = V_48 -> V_155 ==
V_179 - 1 ;
F_59 ( V_48 , V_140 , 0 , V_180 ) ;
V_174 = F_8 ( V_2 , V_181 ) & 0xff ;
}
}
F_40 ( V_2 -> V_10 , L_14 , V_174 ) ;
V_48 -> V_155 ++ ;
return V_174 ;
}
static void F_65 ( struct V_93 * V_94 , T_6 * V_65 , int V_182 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_182 ; V_72 ++ , V_65 ++ )
* V_65 = F_64 ( V_94 ) ;
}
static void F_66 ( struct V_93 * V_94 , const T_6 * V_65 ,
int V_182 )
{
int V_72 ;
struct V_96 * V_97 = V_94 -> V_98 ;
struct V_47 * V_48 = V_97 -> V_98 ;
switch ( V_48 -> V_154 ) {
case V_167 :
for ( V_72 = 0 ; V_72 < V_182 ; V_72 ++ )
F_59 ( V_48 , V_139 , V_65 [ V_72 ] ,
( V_72 + 1 ) == V_182 ) ;
break;
default:
F_67 () ;
break;
}
}
static int F_68 ( struct V_47 * V_48 ,
struct V_183 * V_184 , T_5 V_148 ,
T_7 V_65 , T_1 V_182 , T_3 V_185 ,
bool V_186 , bool V_187 ,
T_7 V_188 )
{
memset ( V_184 , 0 , sizeof( * V_184 ) ) ;
V_184 -> V_188 = F_61 ( V_188 ) ;
V_184 -> V_189 = F_69 ( V_188 ) ;
V_184 -> V_190 = ( V_185 << 24 ) |
( V_187 ? ( 0x03 << 8 ) : 0 ) |
( ! ! V_186 ) | ( ( ! ! V_187 ) << 1 ) ;
#ifdef F_70
V_184 -> V_190 |= 0x01 << 12 ;
#endif
V_184 -> V_191 = F_61 ( V_65 ) ;
V_184 -> V_192 = F_69 ( V_65 ) ;
V_184 -> V_193 = V_182 ;
V_184 -> V_194 = V_182 ;
V_184 -> V_195 = F_61 ( V_148 ) ;
V_184 -> V_196 = F_69 ( V_148 ) ;
V_184 -> V_39 = V_48 -> V_39 ;
V_184 -> V_197 = 0x01 ;
return 0 ;
}
static void F_71 ( struct V_47 * V_48 , T_7 V_184 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned long V_129 = F_56 ( 100 ) ;
F_32 ( V_2 , V_198 , F_61 ( V_184 ) ) ;
( void ) F_33 ( V_2 , V_198 ) ;
F_32 ( V_2 , V_199 , F_69 ( V_184 ) ) ;
( void ) F_33 ( V_2 , V_199 ) ;
V_2 -> V_113 = true ;
F_53 () ;
F_32 ( V_2 , V_200 , 0x03 ) ;
if ( F_57 ( & V_2 -> V_119 , V_129 ) <= 0 ) {
F_6 ( V_2 -> V_10 ,
L_15 ,
F_33 ( V_2 , V_201 ) ,
F_33 ( V_2 , V_202 ) ) ;
}
V_2 -> V_113 = false ;
F_32 ( V_2 , V_200 , 0 ) ;
}
static int F_72 ( struct V_47 * V_48 , T_5 V_148 , T_1 * V_65 ,
T_1 V_182 , T_3 V_185 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_7 V_203 ;
int V_204 = V_185 == V_205 ? V_206 : V_207 ;
V_203 = F_73 ( V_2 -> V_10 , V_65 , V_182 , V_204 ) ;
if ( F_74 ( V_2 -> V_10 , V_203 ) ) {
F_6 ( V_2 -> V_10 , L_16 ) ;
return - V_208 ;
}
F_68 ( V_48 , V_2 -> V_209 , V_148 , V_203 , V_182 ,
V_185 , true , true , 0 ) ;
F_71 ( V_48 , V_2 -> V_210 ) ;
F_75 ( V_2 -> V_10 , V_203 , V_182 , V_204 ) ;
if ( V_2 -> V_209 -> V_197 & V_211 )
return - V_212 ;
else if ( V_2 -> V_209 -> V_197 & V_213 )
return - V_214 ;
return 0 ;
}
static int F_76 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_5 V_148 , unsigned int V_215 , T_1 * V_65 ,
T_3 * V_109 , T_5 * V_216 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
int V_72 , V_73 , V_174 = 0 ;
F_9 ( V_2 , V_217 , 0 ) ;
F_9 ( V_2 , V_218 , 0 ) ;
F_9 ( V_2 , V_171 ,
( V_48 -> V_39 << 16 ) | ( ( V_148 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_171 ) ;
for ( V_72 = 0 ; V_72 < V_215 ; V_72 ++ , V_148 += V_170 ) {
F_9 ( V_2 , V_122 ,
F_61 ( V_148 ) ) ;
( void ) F_8 ( V_2 , V_122 ) ;
F_51 ( V_48 , V_205 ) ;
F_55 ( V_94 , V_97 ) ;
if ( F_30 ( V_65 ) ) {
F_62 ( V_2 -> V_116 ) ;
for ( V_73 = 0 ; V_73 < V_172 ; V_73 ++ , V_65 ++ )
* V_65 = F_11 ( V_2 , V_73 ) ;
F_63 ( V_2 -> V_116 ) ;
}
if ( V_109 )
V_109 += F_43 ( V_2 , V_72 , V_109 ,
V_94 -> V_219 / V_215 ,
V_48 -> V_59 . V_69 ) ;
if ( ! V_174 ) {
* V_216 = F_8 ( V_2 ,
V_217 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_220 )
& 0xffff ) << 32 ) ;
if ( * V_216 )
V_174 = - V_212 ;
}
if ( ! V_174 ) {
* V_216 = F_8 ( V_2 ,
V_218 ) |
( ( T_5 ) ( F_8 ( V_2 ,
V_221 )
& 0xffff ) << 32 ) ;
if ( * V_216 )
V_174 = - V_214 ;
}
}
return V_174 ;
}
static int F_77 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_5 V_148 , unsigned int V_215 , T_1 * V_65 , T_3 * V_109 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_5 V_216 = 0 ;
int V_222 ;
F_40 ( V_2 -> V_10 , L_17 , ( unsigned long long ) V_148 , V_65 ) ;
F_9 ( V_2 , V_223 , 0 ) ;
if ( F_27 ( V_2 ) && ! V_109 && F_28 ( V_65 ) ) {
V_222 = F_72 ( V_48 , V_148 , V_65 , V_215 * V_170 ,
V_205 ) ;
if ( V_222 ) {
if ( F_78 ( V_222 ) )
V_216 = V_148 ;
else
return - V_224 ;
}
} else {
if ( V_109 )
memset ( V_109 , 0x99 , V_94 -> V_219 ) ;
V_222 = F_76 ( V_94 , V_97 , V_148 , V_215 , V_65 ,
V_109 , & V_216 ) ;
}
if ( F_79 ( V_222 ) ) {
F_40 ( V_2 -> V_10 , L_18 ,
( unsigned long long ) V_216 ) ;
V_94 -> V_225 . V_226 ++ ;
return 0 ;
}
if ( F_80 ( V_222 ) ) {
unsigned int V_227 = F_16 ( V_2 ) ;
F_40 ( V_2 -> V_10 , L_19 ,
( unsigned long long ) V_216 ) ;
V_94 -> V_225 . V_227 += V_227 ;
return F_44 ( V_94 -> V_228 , V_227 ) ;
}
return 0 ;
}
static int F_81 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_6 * V_65 , int V_229 , int V_230 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
T_3 * V_109 = V_229 ? ( T_3 * ) V_97 -> V_231 : NULL ;
return F_77 ( V_94 , V_97 , V_48 -> V_156 ,
V_94 -> V_232 >> V_233 , ( T_1 * ) V_65 , V_109 ) ;
}
static int F_82 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_6 * V_65 , int V_229 , int V_230 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
T_3 * V_109 = V_229 ? ( T_3 * ) V_97 -> V_231 : NULL ;
int V_174 ;
F_22 ( V_48 , 0 ) ;
V_174 = F_77 ( V_94 , V_97 , V_48 -> V_156 ,
V_94 -> V_232 >> V_233 , ( T_1 * ) V_65 , V_109 ) ;
F_22 ( V_48 , 1 ) ;
return V_174 ;
}
static int F_83 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_230 )
{
return F_77 ( V_94 , V_97 , ( T_5 ) V_230 << V_97 -> V_149 ,
V_94 -> V_232 >> V_233 ,
NULL , ( T_3 * ) V_97 -> V_231 ) ;
}
static int F_84 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_230 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
F_22 ( V_48 , 0 ) ;
F_77 ( V_94 , V_97 , ( T_5 ) V_230 << V_97 -> V_149 ,
V_94 -> V_232 >> V_233 ,
NULL , ( T_3 * ) V_97 -> V_231 ) ;
F_22 ( V_48 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_8 V_234 , T_8 V_235 ,
T_6 * V_236 , int V_230 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
return F_77 ( V_94 , V_97 , V_48 -> V_156 + V_234 ,
V_235 >> V_233 , ( T_1 * ) V_236 , NULL ) ;
}
static int F_86 ( struct V_93 * V_94 , struct V_96 * V_97 ,
T_5 V_148 , const T_1 * V_65 , T_3 * V_109 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned int V_72 , V_73 , V_215 = V_94 -> V_232 >> V_233 ;
int V_237 , V_174 = 0 ;
F_40 ( V_2 -> V_10 , L_20 , ( unsigned long long ) V_148 , V_65 ) ;
if ( F_87 ( ( T_1 ) V_65 & 0x03 ) ) {
F_88 ( V_2 -> V_10 , L_21 , V_65 ) ;
V_65 = ( T_1 * ) ( ( T_1 ) V_65 & ~ 0x03 ) ;
}
F_39 ( V_94 , 0 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_25 ; V_72 += 4 )
F_42 ( V_2 , V_72 , 0xffffffff ) ;
if ( F_27 ( V_2 ) && ! V_109 && F_28 ( V_65 ) ) {
if ( F_72 ( V_48 , V_148 , ( T_1 * ) V_65 ,
V_94 -> V_232 , V_238 ) )
V_174 = - V_224 ;
goto V_89;
}
F_9 ( V_2 , V_171 ,
( V_48 -> V_39 << 16 ) | ( ( V_148 >> 32 ) & 0xffff ) ) ;
( void ) F_8 ( V_2 , V_171 ) ;
for ( V_72 = 0 ; V_72 < V_215 ; V_72 ++ , V_148 += V_170 ) {
F_9 ( V_2 , V_122 ,
F_61 ( V_148 ) ) ;
( void ) F_8 ( V_2 , V_122 ) ;
if ( V_65 ) {
F_62 ( V_2 -> V_116 ) ;
for ( V_73 = 0 ; V_73 < V_172 ; V_73 ++ , V_65 ++ )
F_13 ( V_2 , V_73 , * V_65 ) ;
F_63 ( V_2 -> V_116 ) ;
} else if ( V_109 ) {
for ( V_73 = 0 ; V_73 < V_172 ; V_73 ++ )
F_13 ( V_2 , V_73 , 0xffffffff ) ;
}
if ( V_109 ) {
V_109 += F_46 ( V_2 , V_72 , V_109 ,
V_94 -> V_219 / V_215 ,
V_48 -> V_59 . V_69 ) ;
}
F_51 ( V_48 , V_238 ) ;
V_237 = F_55 ( V_94 , V_97 ) ;
if ( V_237 & V_239 ) {
F_89 ( V_2 -> V_10 , L_22 ,
( unsigned long long ) V_148 ) ;
V_174 = - V_224 ;
goto V_89;
}
}
V_89:
F_39 ( V_94 , 1 ) ;
return V_174 ;
}
static int F_90 ( struct V_93 * V_94 , struct V_96 * V_97 ,
const T_6 * V_65 , int V_229 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
void * V_109 = V_229 ? V_97 -> V_231 : NULL ;
F_86 ( V_94 , V_97 , V_48 -> V_156 , ( const T_1 * ) V_65 , V_109 ) ;
return 0 ;
}
static int F_91 ( struct V_93 * V_94 ,
struct V_96 * V_97 , const T_6 * V_65 ,
int V_229 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
void * V_109 = V_229 ? V_97 -> V_231 : NULL ;
F_22 ( V_48 , 0 ) ;
F_86 ( V_94 , V_97 , V_48 -> V_156 , ( const T_1 * ) V_65 , V_109 ) ;
F_22 ( V_48 , 1 ) ;
return 0 ;
}
static int F_92 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_230 )
{
return F_86 ( V_94 , V_97 , ( T_5 ) V_230 << V_97 -> V_149 ,
NULL , V_97 -> V_231 ) ;
}
static int F_93 ( struct V_93 * V_94 , struct V_96 * V_97 ,
int V_230 )
{
struct V_47 * V_48 = V_97 -> V_98 ;
int V_174 ;
F_22 ( V_48 , 0 ) ;
V_174 = F_86 ( V_94 , V_97 , ( T_5 ) V_230 << V_97 -> V_149 , NULL ,
( T_3 * ) V_97 -> V_231 ) ;
F_22 ( V_48 , 1 ) ;
return V_174 ;
}
static int F_94 ( struct V_47 * V_48 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_96 * V_97 = & V_48 -> V_97 ;
T_2 V_240 = F_15 ( V_2 , V_48 -> V_39 , V_241 ) ;
T_2 V_242 = F_15 ( V_2 , V_48 -> V_39 ,
V_243 ) ;
T_2 V_61 = F_15 ( V_2 , V_48 -> V_39 ,
V_54 ) ;
T_3 V_244 = 0 , V_82 = 0 , V_245 = 0 ;
T_1 V_36 ;
if ( V_2 -> V_24 ) {
int V_72 , V_246 ;
for ( V_72 = 0 , V_246 = 0 ; V_2 -> V_24 [ V_72 ] ; V_72 ++ )
if ( V_2 -> V_24 [ V_72 ] * 1024 == V_68 -> V_244 ) {
V_244 = V_72 ;
V_246 = 1 ;
}
if ( ! V_246 ) {
F_88 ( V_2 -> V_10 , L_23 ,
V_68 -> V_244 ) ;
return - V_247 ;
}
} else {
V_244 = F_95 ( V_68 -> V_244 ) - F_95 ( V_248 ) ;
}
if ( V_68 -> V_244 < V_248 || ( V_2 -> V_23 &&
V_68 -> V_244 > V_2 -> V_23 ) ) {
F_88 ( V_2 -> V_10 , L_23 ,
V_68 -> V_244 ) ;
V_244 = 0 ;
}
if ( V_2 -> V_8 ) {
int V_72 , V_246 ;
for ( V_72 = 0 , V_246 = 0 ; V_2 -> V_8 [ V_72 ] ; V_72 ++ )
if ( V_2 -> V_8 [ V_72 ] == V_68 -> V_82 ) {
V_82 = V_72 ;
V_246 = 1 ;
}
if ( ! V_246 ) {
F_88 ( V_2 -> V_10 , L_24 ,
V_68 -> V_82 ) ;
return - V_247 ;
}
} else {
V_82 = F_95 ( V_68 -> V_82 ) - F_95 ( V_249 ) ;
}
if ( V_68 -> V_82 < V_249 || ( V_2 -> V_22 &&
V_68 -> V_82 > V_2 -> V_22 ) ) {
F_88 ( V_2 -> V_10 , L_24 , V_68 -> V_82 ) ;
return - V_247 ;
}
if ( F_96 ( V_68 -> V_245 ) < F_96 ( V_250 ) ) {
F_88 ( V_2 -> V_10 , L_25 ,
( unsigned long long ) V_68 -> V_245 ) ;
return - V_247 ;
}
V_245 = F_96 ( V_68 -> V_245 ) - F_96 ( V_250 ) ;
V_36 = ( V_68 -> V_251 << 8 ) |
( V_68 -> V_252 << 12 ) |
( V_68 -> V_253 << 16 ) |
( ! ! ( V_68 -> V_254 == 16 ) << 23 ) |
( V_245 << 24 ) ;
if ( V_240 == V_242 ) {
V_36 |= ( V_82 << 20 ) | ( V_244 << 28 ) ;
F_3 ( V_2 , V_240 , V_36 ) ;
} else {
F_3 ( V_2 , V_240 , V_36 ) ;
V_36 = V_82 | ( V_244 << 4 ) ;
F_3 ( V_2 , V_242 , V_36 ) ;
}
V_36 = F_1 ( V_2 , V_61 ) ;
V_36 &= ~ F_21 ( V_2 ) ;
V_36 |= V_68 -> V_60 << V_52 ;
V_36 &= ~ F_19 ( V_2 ) ;
V_36 |= V_68 -> V_70 ;
F_3 ( V_2 , V_61 , V_36 ) ;
F_25 ( V_48 , V_68 -> V_69 ) ;
F_17 ( V_48 , F_37 ( V_97 -> V_255 . V_256 * 3 , 4 ) ) ;
return 0 ;
}
static void F_97 ( char * V_65 , struct V_67 * V_68 )
{
V_65 += sprintf ( V_65 ,
L_26 ,
( unsigned long long ) V_68 -> V_245 >> 20 ,
V_68 -> V_244 >> 10 ,
V_68 -> V_82 >= 1024 ? V_68 -> V_82 >> 10 : V_68 -> V_82 ,
V_68 -> V_82 >= 1024 ? L_27 : L_28 ,
V_68 -> V_70 , V_68 -> V_254 ) ;
if ( F_34 ( V_68 ) )
sprintf ( V_65 , L_29 ) ;
else if ( V_68 -> V_69 )
sprintf ( V_65 , L_30 , V_68 -> V_60 << 1 ) ;
else
sprintf ( V_65 , L_31 , V_68 -> V_60 ) ;
}
static inline int F_98 ( T_5 V_257 , T_1 V_232 )
{
return F_99 ( F_100 ( V_257 ) - F_100 ( V_232 ) , 8 ) >> 3 ;
}
static int F_101 ( struct V_47 * V_48 )
{
struct V_93 * V_94 = & V_48 -> V_94 ;
struct V_96 * V_97 = & V_48 -> V_97 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_67 * V_68 = & V_48 -> V_59 ;
char V_258 [ 128 ] ;
T_1 V_3 , V_36 , V_259 ;
int V_174 ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_174 = F_102 ( V_97 -> V_260 , L_32 ,
& V_259 ) ;
if ( V_174 ) {
V_68 -> V_70 = V_94 -> V_219 /
( V_94 -> V_232 >> V_233 ) ;
} else {
V_68 -> V_70 = V_259 ;
}
if ( V_68 -> V_70 > V_2 -> V_25 )
V_68 -> V_70 = V_2 -> V_25 ;
V_94 -> V_219 = V_68 -> V_70 * ( V_94 -> V_232 >> V_233 ) ;
V_68 -> V_245 = V_94 -> V_257 ;
V_68 -> V_244 = V_94 -> V_261 ;
V_68 -> V_82 = V_94 -> V_232 ;
V_68 -> V_254 = ( V_97 -> V_262 & V_263 ) ? 16 : 8 ;
V_68 -> V_252 = 2 ;
V_68 -> V_251 = F_98 ( V_94 -> V_257 , V_94 -> V_232 ) ;
switch ( V_97 -> V_255 . V_257 ) {
case 512 :
if ( V_97 -> V_255 . V_256 == 1 )
V_68 -> V_60 = 15 ;
else
V_68 -> V_60 = V_97 -> V_255 . V_256 ;
V_68 -> V_69 = 0 ;
break;
case 1024 :
if ( ! ( V_2 -> V_26 & V_29 ) ) {
F_6 ( V_2 -> V_10 , L_33 ) ;
return - V_247 ;
}
if ( V_97 -> V_255 . V_256 & 0x1 ) {
F_6 ( V_2 -> V_10 ,
L_34 ) ;
return - V_247 ;
}
V_68 -> V_60 = V_97 -> V_255 . V_256 >> 1 ;
V_68 -> V_69 = 1 ;
break;
default:
F_6 ( V_2 -> V_10 , L_35 ,
V_97 -> V_255 . V_257 ) ;
return - V_247 ;
}
V_68 -> V_253 = V_68 -> V_251 ;
if ( V_94 -> V_232 > 512 )
V_68 -> V_253 += V_68 -> V_252 ;
else
V_68 -> V_253 += 1 ;
V_174 = F_94 ( V_48 , V_68 ) ;
if ( V_174 )
return V_174 ;
F_22 ( V_48 , 1 ) ;
F_97 ( V_258 , V_68 ) ;
F_89 ( V_2 -> V_10 , L_36 , V_258 ) ;
V_3 = F_15 ( V_2 , V_48 -> V_39 , V_54 ) ;
V_36 = F_1 ( V_2 , V_3 ) ;
V_36 &= ~ V_264 ;
V_36 &= ~ V_265 ;
V_36 &= ~ V_266 ;
if ( V_2 -> V_26 & V_27 ) {
if ( F_27 ( V_2 ) )
V_36 &= ~ V_267 ;
else
V_36 |= V_267 ;
}
F_3 ( V_2 , V_3 , V_36 ) ;
return 0 ;
}
static int F_103 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_268 * V_260 = V_48 -> V_31 ;
struct V_269 * V_80 = V_48 -> V_80 ;
struct V_93 * V_94 ;
struct V_96 * V_97 ;
int V_174 ;
struct V_270 V_271 = { . V_31 = V_260 } ;
V_174 = F_102 ( V_260 , L_37 , & V_48 -> V_39 ) ;
if ( V_174 ) {
F_6 ( & V_80 -> V_10 , L_38 ) ;
return - V_272 ;
}
V_94 = & V_48 -> V_94 ;
V_97 = & V_48 -> V_97 ;
V_97 -> V_260 = V_260 ;
V_97 -> V_98 = V_48 ;
V_94 -> V_98 = V_97 ;
V_94 -> V_273 = F_104 ( & V_80 -> V_10 , V_81 , L_39 ,
V_48 -> V_39 ) ;
V_94 -> V_274 = V_275 ;
V_94 -> V_10 . V_276 = & V_80 -> V_10 ;
V_97 -> V_277 = ( void V_278 * ) 0xdeadbeef ;
V_97 -> V_279 = ( void V_278 * ) 0xdeadbeef ;
V_97 -> V_280 = F_54 ;
V_97 -> V_178 = F_60 ;
V_97 -> V_281 = F_55 ;
V_97 -> V_282 = F_64 ;
V_97 -> V_283 = F_65 ;
V_97 -> V_284 = F_66 ;
V_97 -> V_255 . V_285 = V_286 ;
V_97 -> V_255 . V_287 = F_81 ;
V_97 -> V_255 . V_288 = F_85 ;
V_97 -> V_255 . V_289 = F_90 ;
V_97 -> V_255 . V_290 = F_82 ;
V_97 -> V_255 . V_291 = F_91 ;
V_97 -> V_255 . V_292 = F_93 ;
V_97 -> V_255 . V_293 = F_84 ;
V_97 -> V_255 . V_294 = F_83 ;
V_97 -> V_255 . V_295 = F_92 ;
V_97 -> V_296 = & V_2 -> V_296 ;
if ( F_105 ( V_94 , 1 , NULL ) )
return - V_272 ;
V_97 -> V_262 |= V_297 ;
V_97 -> V_262 |= V_298 ;
if ( F_106 ( V_260 ) )
V_97 -> V_299 |= V_300 | V_301 ;
if ( F_101 ( V_48 ) )
return - V_272 ;
V_97 -> V_255 . V_257 = V_48 -> V_59 . V_69 ? 1024 : 512 ;
V_94 -> V_228 = 1 ;
V_97 -> V_255 . V_74 = F_38 ( V_48 ) ;
if ( ! V_97 -> V_255 . V_74 )
return - V_272 ;
if ( F_107 ( V_94 ) )
return - V_272 ;
return F_108 ( V_94 , NULL , & V_271 , NULL , 0 ) ;
}
static void F_109 ( struct V_47 * V_48 ,
int V_302 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_2 V_240 = F_15 ( V_2 , V_48 -> V_39 , V_241 ) ;
T_2 V_242 = F_15 ( V_2 , V_48 -> V_39 ,
V_243 ) ;
T_2 V_61 = F_15 ( V_2 , V_48 -> V_39 ,
V_54 ) ;
T_2 V_303 = F_15 ( V_2 , V_48 -> V_39 , V_304 ) ;
T_2 V_305 = F_15 ( V_2 , V_48 -> V_39 , V_306 ) ;
if ( V_302 ) {
F_3 ( V_2 , V_240 , V_48 -> V_59 . V_307 ) ;
if ( V_240 != V_242 )
F_3 ( V_2 , V_242 ,
V_48 -> V_59 . V_308 ) ;
F_3 ( V_2 , V_61 , V_48 -> V_59 . V_55 ) ;
F_3 ( V_2 , V_303 , V_48 -> V_59 . V_309 ) ;
F_3 ( V_2 , V_305 , V_48 -> V_59 . V_310 ) ;
} else {
V_48 -> V_59 . V_307 = F_1 ( V_2 , V_240 ) ;
if ( V_240 != V_242 )
V_48 -> V_59 . V_308 =
F_1 ( V_2 , V_242 ) ;
V_48 -> V_59 . V_55 = F_1 ( V_2 , V_61 ) ;
V_48 -> V_59 . V_309 = F_1 ( V_2 , V_303 ) ;
V_48 -> V_59 . V_310 = F_1 ( V_2 , V_305 ) ;
}
}
static int F_110 ( struct V_311 * V_10 )
{
struct V_1 * V_2 = F_111 ( V_10 ) ;
struct V_47 * V_48 ;
F_112 (host, &ctrl->host_list, node)
F_109 ( V_48 , 0 ) ;
V_2 -> V_312 = F_8 ( V_2 , V_63 ) ;
V_2 -> V_313 = F_8 ( V_2 , V_314 ) ;
V_2 -> V_315 =
F_8 ( V_2 , V_50 ) ;
if ( F_27 ( V_2 ) )
V_2 -> V_316 = F_33 ( V_2 , V_317 ) ;
return 0 ;
}
static int F_113 ( struct V_311 * V_10 )
{
struct V_1 * V_2 = F_111 ( V_10 ) ;
struct V_47 * V_48 ;
if ( F_27 ( V_2 ) ) {
F_32 ( V_2 , V_317 , V_2 -> V_316 ) ;
F_32 ( V_2 , V_202 , 0 ) ;
}
F_9 ( V_2 , V_63 , V_2 -> V_312 ) ;
F_9 ( V_2 , V_314 , V_2 -> V_313 ) ;
F_9 ( V_2 , V_50 ,
V_2 -> V_315 ) ;
if ( V_2 -> V_116 ) {
V_2 -> V_116 -> V_117 ( V_2 -> V_116 ) ;
V_2 -> V_116 -> V_318 ( V_2 -> V_116 , true ) ;
}
F_112 (host, &ctrl->host_list, node) {
struct V_93 * V_94 = & V_48 -> V_94 ;
struct V_96 * V_97 = V_94 -> V_98 ;
F_109 ( V_48 , 1 ) ;
V_97 -> V_178 ( V_94 , V_157 , - 1 , - 1 ) ;
}
return 0 ;
}
int F_114 ( struct V_269 * V_80 , struct V_319 * V_116 )
{
struct V_311 * V_10 = & V_80 -> V_10 ;
struct V_268 * V_260 = V_10 -> V_31 , * V_320 ;
struct V_1 * V_2 ;
struct V_321 * V_322 ;
int V_174 ;
if ( ! V_260 )
return - V_11 ;
if ( ! F_115 ( V_323 , V_260 ) )
return - V_11 ;
V_2 = F_36 ( V_10 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_208 ;
F_116 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
F_117 ( & V_2 -> V_115 ) ;
F_117 ( & V_2 -> V_119 ) ;
F_118 ( & V_2 -> V_296 . V_324 ) ;
F_119 ( & V_2 -> V_296 . V_325 ) ;
F_120 ( & V_2 -> V_326 ) ;
V_322 = F_121 ( V_80 , V_327 , 0 ) ;
V_2 -> V_4 = F_122 ( V_10 , V_322 ) ;
if ( F_123 ( V_2 -> V_4 ) )
return F_124 ( V_2 -> V_4 ) ;
V_174 = F_5 ( V_2 ) ;
if ( V_174 )
return V_174 ;
V_322 = F_125 ( V_80 , V_327 , L_40 ) ;
if ( V_322 ) {
V_2 -> V_38 = F_122 ( V_10 , V_322 ) ;
if ( F_123 ( V_2 -> V_38 ) )
return F_124 ( V_2 -> V_38 ) ;
} else {
V_2 -> V_38 = V_2 -> V_4 +
V_2 -> V_12 [ V_328 ] ;
}
V_322 = F_125 ( V_80 , V_327 , L_41 ) ;
if ( V_322 ) {
V_2 -> V_64 = F_122 ( V_10 , V_322 ) ;
if ( F_123 ( V_2 -> V_64 ) )
return F_124 ( V_2 -> V_64 ) ;
F_32 ( V_2 , V_317 , 1 ) ;
F_32 ( V_2 , V_202 , 0 ) ;
V_2 -> V_209 = F_126 ( V_10 ,
sizeof( * V_2 -> V_209 ) ,
& V_2 -> V_210 , V_81 ) ;
if ( ! V_2 -> V_209 )
return - V_208 ;
V_2 -> V_329 = F_127 ( V_80 , 1 ) ;
if ( ( int ) V_2 -> V_329 < 0 ) {
F_6 ( V_10 , L_42 ) ;
return - V_11 ;
}
V_174 = F_128 ( V_10 , V_2 -> V_329 ,
F_50 , 0 , V_330 ,
V_2 ) ;
if ( V_174 < 0 ) {
F_6 ( V_10 , L_43 ,
V_2 -> V_329 , V_174 ) ;
return V_174 ;
}
F_89 ( V_10 , L_44 ) ;
}
F_10 ( V_2 , V_63 ,
V_331 | 0xff , 0 , 0 ) ;
F_10 ( V_2 , V_314 , 0xff , 0 , 0 ) ;
if ( V_2 -> V_26 & V_30 ) {
if ( V_99 == 2 )
F_26 ( V_2 , false ) ;
} else {
V_99 = 0 ;
}
V_2 -> V_112 = F_127 ( V_80 , 0 ) ;
if ( ( int ) V_2 -> V_112 < 0 ) {
F_6 ( V_10 , L_45 ) ;
return - V_11 ;
}
if ( V_116 ) {
V_2 -> V_116 = V_116 ;
V_174 = F_128 ( V_10 , V_2 -> V_112 , F_49 , 0 ,
V_330 , V_2 ) ;
V_2 -> V_116 -> V_117 ( V_2 -> V_116 ) ;
V_2 -> V_116 -> V_318 ( V_2 -> V_116 , true ) ;
} else {
V_174 = F_128 ( V_10 , V_2 -> V_112 , F_47 , 0 ,
V_330 , V_2 ) ;
}
if ( V_174 < 0 ) {
F_6 ( V_10 , L_43 ,
V_2 -> V_112 , V_174 ) ;
return V_174 ;
}
F_129 (dn, child) {
if ( F_130 ( V_320 , L_46 ) ) {
struct V_47 * V_48 ;
V_48 = F_36 ( V_10 , sizeof( * V_48 ) , V_81 ) ;
if ( ! V_48 )
return - V_208 ;
V_48 -> V_80 = V_80 ;
V_48 -> V_2 = V_2 ;
V_48 -> V_31 = V_320 ;
V_174 = F_103 ( V_48 ) ;
if ( V_174 )
continue;
F_131 ( & V_48 -> V_332 , & V_2 -> V_326 ) ;
}
}
if ( F_132 ( & V_2 -> V_326 ) )
return - V_11 ;
return 0 ;
}
int F_133 ( struct V_269 * V_80 )
{
struct V_1 * V_2 = F_111 ( & V_80 -> V_10 ) ;
struct V_47 * V_48 ;
F_112 (host, &ctrl->host_list, node)
F_134 ( & V_48 -> V_94 ) ;
F_116 ( & V_80 -> V_10 , NULL ) ;
return 0 ;
}
