static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 [ 0 ] + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 [ 0 ] + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 [ V_6 ] + V_3 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , int V_6 ,
T_1 V_3 )
{
return F_4 ( V_2 -> V_5 [ V_6 ] + V_3 ) ;
}
static T_2 F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_10 -> V_13 . V_14 ;
else
return V_10 -> V_15 . V_16 & F_8 ( 40 , 0 ) ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_17 )
{
if ( V_8 -> V_2 -> V_11 == V_12 ) {
V_10 -> V_13 . V_14 = V_17 ;
} else {
T_3 V_18 = ( T_3 ) V_17 ;
V_10 -> V_15 . V_16 &= ~ F_8 ( 40 , 0 ) ;
V_10 -> V_15 . V_16 |= V_18 ;
}
}
static T_4 F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_10 -> V_13 . V_19 ;
else
return V_10 -> V_15 . V_19 ;
}
static void F_11 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_4 V_20 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
V_10 -> V_13 . V_19 = V_20 ;
else
V_10 -> V_15 . V_19 = V_20 ;
}
static void F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int V_21 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
V_10 -> V_13 . V_22 = V_21 ;
else
V_10 -> V_15 . V_22 = V_21 ;
}
static void F_13 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int V_23 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
V_10 -> V_13 . V_23 = V_23 ;
else
V_10 -> V_15 . V_23 = V_23 ;
}
static void F_14 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int V_3 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
V_10 -> V_13 . V_24 = V_3 ;
else
V_10 -> V_15 . V_24 = V_3 ;
}
static unsigned int F_15 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_10 -> V_13 . V_24 ;
else
return V_10 -> V_15 . V_24 ;
}
static T_2 F_16 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_26 -> V_13 . V_14 ;
else
return V_26 -> V_15 . V_27 & F_8 ( 40 , 0 ) ;
}
static unsigned long F_17 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_26 -> V_13 . V_28 ;
else
return V_26 -> V_15 . V_29 & F_8 ( 40 , 0 ) ;
}
static T_4 F_18 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_26 -> V_13 . V_19 ;
else
return V_26 -> V_15 . V_19 ;
}
static T_1 F_19 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
if ( V_8 -> V_2 -> V_11 == V_12 )
return V_26 -> V_13 . V_30 ;
else
return V_26 -> V_15 . V_30 ;
}
static void F_20 ( struct V_31 * V_32 )
{
V_32 -> V_33 ++ ;
if ( V_32 -> V_33 == V_32 -> V_20 )
V_32 -> V_33 = 0 ;
}
static void F_21 ( struct V_7 * V_8 ,
struct V_31 * V_32 ,
struct V_34 * V_35 ,
struct V_9 * V_10 )
{
struct V_36 * V_37 =
V_32 -> V_38 + V_32 -> V_39 ;
V_37 -> V_35 = V_35 ;
V_37 -> V_20 = F_10 ( V_8 , V_10 ) ;
V_37 -> V_40 = F_7 ( V_8 , V_10 ) +
F_15 ( V_8 , V_10 ) ;
V_32 -> V_39 ++ ;
if ( V_32 -> V_39 == V_32 -> V_20 )
V_32 -> V_39 = 0 ;
}
static inline int F_22 ( struct V_7 * V_8 )
{
return V_41 + V_8 -> V_42 ;
}
static inline int F_23 ( int V_8 , int V_21 )
{
return ( V_41 + V_8 ) * V_43 + V_21 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_46 ;
if ( V_45 -> V_47 > V_48 - 1 )
return - V_49 ;
V_45 -> V_50 . V_51 [ V_52 ] &= ~ V_53 ;
F_1 ( V_2 , V_54 , V_45 -> V_47 ) ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ )
F_1 ( V_2 , F_25 ( V_46 ) , V_45 -> V_50 . V_51 [ V_46 ] ) ;
F_1 ( V_2 , V_56 , V_45 -> V_47 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ )
F_1 ( V_2 , F_26 ( V_46 ) , V_45 -> V_58 . V_51 [ V_46 ] ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_46 ;
if ( V_45 -> V_47 > V_48 - 1 )
return - V_49 ;
F_1 ( V_2 , V_54 , V_45 -> V_47 ) ;
V_45 -> V_50 . V_51 [ V_52 ] = F_3 ( V_2 ,
F_25 ( V_52 ) ) ;
if ( V_45 -> V_50 . V_51 [ V_52 ] & V_53 )
return V_59 ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ )
V_45 -> V_50 . V_51 [ V_46 ] = F_3 ( V_2 , F_25 ( V_46 ) ) ;
F_1 ( V_2 , V_56 , V_45 -> V_47 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ )
V_45 -> V_58 . V_51 [ V_46 ] = F_3 ( V_2 , F_26 ( V_46 ) ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , int V_47 )
{
F_1 ( V_2 , V_54 , V_47 ) ;
F_1 ( V_2 , F_25 ( V_52 ) ,
V_53 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_47 , int V_60 )
{
V_2 -> V_61 [ V_47 ] . V_62 = true ;
V_2 -> V_61 [ V_47 ] . V_60 = V_60 ;
}
static void F_30 ( struct V_1 * V_2 , int V_47 ,
unsigned int V_63 , unsigned int V_64 )
{
V_2 -> V_61 [ V_47 ] . V_64 = V_64 ;
V_2 -> V_61 [ V_47 ] . V_63 = V_63 ;
}
static void F_31 ( struct V_44 * V_45 , unsigned int V_60 )
{
int V_65 = F_32 ( V_66 ) ;
V_45 -> V_50 . V_67 [ V_66 ] = V_60 ;
V_45 -> V_50 . V_67 [ V_65 ] = V_68 ;
}
static void F_33 ( struct V_44 * V_45 ,
unsigned int V_8 , bool V_69 )
{
int V_65 = F_32 ( V_70 ) ;
if ( V_69 )
V_45 -> V_50 . V_67 [ V_65 ] &= ~ ( 1 << V_8 ) ;
else
V_45 -> V_50 . V_67 [ V_65 ] |= 1 << V_8 ;
}
static void F_34 ( struct V_44 * V_45 ,
unsigned int V_71 )
{
unsigned char V_72 = V_73 ;
int V_65 = F_32 ( V_70 ) ;
V_45 -> V_50 . V_67 [ V_70 ] = 0 ;
V_45 -> V_50 . V_67 [ V_65 ] &= ~ V_72 ;
V_45 -> V_50 . V_67 [ V_65 ] |= ~ V_71 & V_73 ;
}
static unsigned int F_35 ( struct V_44 * V_45 )
{
int V_65 = F_32 ( V_70 ) ;
return ~ ( V_45 -> V_50 . V_67 [ V_65 ] ) & V_73 ;
}
static void F_36 ( struct V_44 * V_45 ,
unsigned int V_74 , unsigned char V_67 ,
unsigned char V_75 )
{
V_45 -> V_50 . V_67 [ F_37 ( V_74 ) ] = V_67 ;
V_45 -> V_50 . V_67 [ F_38 ( V_74 ) ] = V_75 ;
}
static void F_39 ( struct V_44 * V_45 ,
unsigned int V_74 , unsigned char * V_67 ,
unsigned char * V_75 )
{
* V_67 = V_45 -> V_50 . V_67 [ F_37 ( V_74 ) ] ;
* V_75 = V_45 -> V_50 . V_67 [ F_38 ( V_74 ) ] ;
}
static bool F_40 ( struct V_44 * V_45 , int V_74 ,
T_5 V_4 )
{
int V_76 = F_37 ( V_74 ) ;
T_5 V_77 ;
V_77 = ( V_45 -> V_50 . V_67 [ V_76 + 1 ] << 8 ) | V_45 -> V_50 . V_67 [ V_76 ] ;
if ( V_77 != V_4 )
return false ;
return true ;
}
static void F_41 ( struct V_44 * V_45 ,
unsigned int V_78 , unsigned int V_75 )
{
int V_46 , V_79 = V_80 ;
for ( V_46 = 0 ; V_46 < V_81 ; V_46 ++ ) {
if ( ! ( V_75 & F_42 ( V_46 ) ) )
continue;
if ( V_78 & F_42 ( V_46 ) )
V_45 -> V_50 . V_67 [ V_79 ] |= 1 << V_46 ;
else
V_45 -> V_50 . V_67 [ V_79 ] &= ~ ( 1 << V_46 ) ;
}
V_45 -> V_50 . V_67 [ F_32 ( V_79 ) ] |= V_75 ;
}
static int F_43 ( struct V_44 * V_45 )
{
return V_45 -> V_50 . V_67 [ V_80 ] ;
}
static void F_44 ( struct V_44 * V_45 , int V_3 ,
unsigned short V_82 )
{
F_36 ( V_45 , V_3 + 0 , V_82 >> 8 , 0xff ) ;
F_36 ( V_45 , V_3 + 1 , V_82 & 0xff , 0xff ) ;
}
static void F_45 ( struct V_44 * V_45 , int V_83 ,
int V_18 )
{
V_45 -> V_58 . V_67 [ F_46 ( V_83 ) ] |= ( V_18 << ( V_83 % 8 ) ) ;
}
static void F_47 ( struct V_44 * V_45 , int V_83 ,
int V_18 )
{
V_45 -> V_58 . V_67 [ F_46 ( V_83 ) ] &= ~ ( V_18 << ( V_83 % 8 ) ) ;
}
static void F_48 ( struct V_44 * V_45 ,
unsigned int V_78 , unsigned int V_84 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_85 ; V_46 ++ ) {
int V_86 = V_87 ;
if ( ! ( V_84 & F_42 ( V_46 ) ) )
continue;
if ( V_78 & F_42 ( V_46 ) )
F_45 ( V_45 , V_86 + V_46 , 1 ) ;
else
F_47 ( V_45 , V_86 + V_46 , 1 ) ;
F_45 ( V_45 , V_88 + V_46 , 1 ) ;
}
}
static int F_49 ( struct V_44 * V_45 )
{
return V_45 -> V_58 . V_51 [ V_89 ] ;
}
static void F_50 ( struct V_44 * V_45 ,
unsigned int V_78 , unsigned int V_84 )
{
unsigned int V_46 ;
int V_90 = V_91 ;
for ( V_46 = 0 ; V_46 < V_92 ; V_46 ++ ) {
if ( ! ( V_84 & F_42 ( V_46 ) ) )
continue;
if ( V_78 & F_42 ( V_46 ) )
F_45 ( V_45 , V_90 + V_46 , 1 ) ;
else
F_47 ( V_45 , V_90 + V_46 , 1 ) ;
F_45 ( V_45 , V_93 + V_46 , 1 ) ;
}
}
static int F_51 ( struct V_44 * V_45 )
{
T_6 V_78 ;
int V_90 = F_46 ( V_91 ) ;
int V_94 = V_90 + 1 ;
int V_95 = V_91 % 8 ;
V_78 = ( V_45 -> V_58 . V_67 [ V_90 ] >> V_95 ) |
( V_45 -> V_58 . V_67 [ V_94 ] << ( 8 - V_95 ) ) ;
return V_78 ;
}
static void F_52 ( struct V_44 * V_45 ,
unsigned int V_60 )
{
int V_96 = V_97 ;
F_47 ( V_45 , V_96 ,
V_98 ) ;
F_45 ( V_45 , V_96 , V_60 ) ;
}
static void F_53 ( struct V_44 * V_45 , int V_99 ,
unsigned int V_100 )
{
if ( V_99 < 0 ) {
F_45 ( V_45 , V_101 , 1 ) ;
V_99 = 0 - V_99 ;
} else {
F_47 ( V_45 , V_101 , 1 ) ;
}
V_45 -> V_58 . V_67 [ F_46 ( V_102 ) ] =
( unsigned char ) V_99 ;
F_47 ( V_45 , V_103 ,
V_104 ) ;
F_45 ( V_45 , V_103 , V_100 ) ;
F_47 ( V_45 , V_105 , 1 ) ;
}
static void F_54 ( struct V_44 * V_45 ,
unsigned int type , int V_3 ,
unsigned int V_100 )
{
if ( V_3 < 0 ) {
F_45 ( V_45 , V_106 , 1 ) ;
V_3 = 0 - V_3 ;
} else {
F_47 ( V_45 , V_106 , 1 ) ;
}
F_47 ( V_45 , V_107 ,
V_108 ) ;
F_45 ( V_45 , V_107 , V_3 ) ;
V_45 -> V_58 . V_67 [ F_46 ( V_107 +
V_109 ) ] &=
~ ( V_108 >> ( 8 - ( V_107 % 8 ) ) ) ;
V_45 -> V_58 . V_67 [ F_46 ( V_107 +
V_109 ) ] |=
( V_3 >> ( 8 - ( V_107 % 8 ) ) ) ;
F_47 ( V_45 , V_110 ,
V_111 ) ;
F_45 ( V_45 , V_110 , type ) ;
F_47 ( V_45 , V_112 ,
V_113 ) ;
F_45 ( V_45 , V_112 , V_100 ) ;
V_45 -> V_58 . V_67 [ F_46 ( V_112 +
V_114 ) ] &=
~ ( V_113 >>
( 8 - ( V_112 % 8 ) ) ) ;
V_45 -> V_58 . V_67 [ F_46 ( V_112 +
V_114 ) ] |=
( V_100 >> ( 8 - ( V_112 % 8 ) ) ) ;
F_47 ( V_45 , V_105 , 1 ) ;
}
static struct V_44 * F_55 ( struct V_1 * V_2 , int V_115 )
{
struct V_44 * V_45 ;
int V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return NULL ;
F_31 ( V_45 , V_118 ) ;
for ( V_116 = V_48 - 1 ; V_116 >= 0 ; V_116 -- ) {
T_6 V_78 ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
V_2 -> V_61 [ V_116 ] . V_60 != V_118 )
continue;
V_45 -> V_47 = V_116 ;
F_27 ( V_2 , V_45 ) ;
V_78 = F_51 ( V_45 ) ;
if ( ( V_78 & V_119 ) == V_115 )
return V_45 ;
}
F_57 ( V_45 ) ;
return NULL ;
}
static int F_58 ( struct V_1 * V_2 , unsigned char V_120 ,
unsigned char V_121 )
{
int V_116 ;
if ( V_120 > V_121 )
F_59 ( V_120 , V_121 ) ;
if ( V_121 >= V_48 )
V_121 = V_48 - 1 ;
for ( V_116 = V_120 ; V_116 <= V_121 ; V_116 ++ ) {
if ( ! V_2 -> V_61 [ V_116 ] . V_62 )
return V_116 ;
}
return - V_49 ;
}
static void F_60 ( struct V_1 * V_2 , int V_8 , bool V_69 )
{
struct V_44 V_45 ;
if ( V_2 -> V_61 [ V_122 ] . V_62 ) {
V_45 . V_47 = V_122 ;
F_27 ( V_2 , & V_45 ) ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_123 ) ;
V_45 . V_47 = V_122 ;
F_48 ( & V_45 , V_124 ,
V_124 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_52 ( & V_45 , V_118 ) ;
F_29 ( V_2 , V_45 . V_47 , V_123 ) ;
F_34 ( & V_45 , 0 ) ;
}
F_33 ( & V_45 , V_8 , V_69 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_8 , bool V_69 )
{
struct V_44 V_45 ;
if ( V_2 -> V_61 [ V_126 ] . V_62 ) {
V_45 . V_47 = V_126 ;
F_27 ( V_2 , & V_45 ) ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_123 ) ;
V_45 . V_47 = V_126 ;
F_52 ( & V_45 , V_127 ) ;
F_48 ( & V_45 , V_128 ,
V_129 ) ;
F_53 ( & V_45 , 2 * V_130 ,
V_131 ) ;
F_34 ( & V_45 , 0 ) ;
F_29 ( V_2 , V_45 . V_47 , V_123 ) ;
}
F_33 ( & V_45 , V_8 , V_69 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_8 , int V_47 ,
bool V_69 )
{
struct V_44 V_45 ;
unsigned char V_132 ;
V_132 = ( V_47 == V_133 ) ? 0x01 : 0x33 ;
if ( V_2 -> V_61 [ V_47 ] . V_62 ) {
V_45 . V_47 = V_47 ;
F_27 ( V_2 , & V_45 ) ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_123 ) ;
V_45 . V_47 = V_47 ;
F_52 ( & V_45 , V_127 ) ;
F_48 ( & V_45 , V_134 ,
V_129 ) ;
F_36 ( & V_45 , 0 , V_132 , 0xff ) ;
F_53 ( & V_45 , 2 * V_130 ,
V_131 ) ;
F_34 ( & V_45 , 0 ) ;
F_29 ( V_2 , V_45 . V_47 , V_123 ) ;
}
F_33 ( & V_45 , V_8 , V_69 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static void F_63 ( struct V_1 * V_2 , int V_8 , bool V_69 ,
bool V_135 , bool V_136 )
{
struct V_44 V_45 ;
int V_116 , V_99 ;
if ( V_136 ) {
V_116 = V_135 ? V_137 : V_138 ;
V_99 = 8 ;
} else {
V_116 = V_135 ? V_139 : V_140 ;
V_99 = 4 ;
}
if ( V_2 -> V_61 [ V_116 ] . V_62 ) {
V_45 . V_47 = V_116 ;
F_27 ( V_2 , & V_45 ) ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_127 ) ;
V_45 . V_47 = V_116 ;
F_53 ( & V_45 , V_99 ,
V_131 ) ;
F_29 ( V_2 , V_45 . V_47 , V_127 ) ;
if ( V_135 ) {
F_36 ( & V_45 , 0 ,
V_141 ,
V_141 ) ;
F_50 ( & V_45 , 0 ,
V_142 ) ;
F_52 ( & V_45 , V_143 ) ;
} else {
F_48 ( & V_45 , V_144 ,
V_145 ) ;
F_52 ( & V_45 , V_146 ) ;
}
F_34 ( & V_45 , 0 ) ;
}
F_33 ( & V_45 , V_8 , V_69 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static void F_64 ( struct V_1 * V_2 , int V_8 ,
bool V_69 , bool V_135 , bool V_136 )
{
struct V_44 V_45 ;
int V_116 , V_99 , V_72 ;
if ( V_136 ) {
V_116 = V_135 ? V_147 :
V_148 ;
V_72 = 0 ;
V_99 = 8 ;
} else {
V_116 = V_135 ? V_149 :
V_150 ;
V_72 = V_73 ;
V_99 = 4 ;
}
if ( V_2 -> V_61 [ V_116 ] . V_62 ) {
V_45 . V_47 = V_116 ;
F_27 ( V_2 , & V_45 ) ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_127 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_151 ) ;
F_44 ( & V_45 , 2 , 0 ) ;
F_48 ( & V_45 , V_152 ,
V_152 ) ;
F_53 ( & V_45 , 2 + V_153 + V_99 ,
V_131 ) ;
F_29 ( V_2 , V_45 . V_47 , V_127 ) ;
if ( V_135 ) {
F_36 ( & V_45 ,
V_153 + 2 + 3 ,
V_141 ,
V_141 ) ;
F_50 ( & V_45 , 0 ,
V_142 ) ;
F_52 ( & V_45 , V_143 ) ;
} else {
F_48 ( & V_45 , V_144 ,
V_145 ) ;
F_52 ( & V_45 , V_146 ) ;
}
F_34 ( & V_45 , V_72 ) ;
}
F_33 ( & V_45 , V_8 , V_69 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static struct V_44 * F_65 ( struct V_1 * V_2 ,
unsigned short V_154 , int V_155 )
{
struct V_44 * V_45 ;
int V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return NULL ;
F_31 ( V_45 , V_143 ) ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ ) {
unsigned int V_158 , V_159 ;
bool V_160 ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
V_2 -> V_61 [ V_116 ] . V_60 != V_143 )
continue;
V_45 -> V_47 = V_116 ;
F_27 ( V_2 , V_45 ) ;
V_160 = F_40 ( V_45 , 0 , F_66 ( V_154 ) ) ;
if ( ! V_160 )
continue;
V_158 = F_49 ( V_45 ) ;
V_158 &= V_145 ;
V_159 = F_43 ( V_45 ) ;
V_159 &= ~ V_161 ;
if ( V_155 != V_159 )
continue;
if ( V_158 == V_162 ||
V_158 == V_163 )
return V_45 ;
}
F_57 ( V_45 ) ;
return NULL ;
}
static int F_67 ( struct V_1 * V_2 , unsigned short V_154 , int V_155 ,
unsigned int V_164 )
{
struct V_44 * V_45 ;
int V_165 , V_116 ;
int V_166 = 0 ;
V_45 = F_65 ( V_2 , V_154 , V_155 ) ;
if ( ! V_45 ) {
V_116 = F_58 ( V_2 , V_157 ,
V_156 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return - V_167 ;
for ( V_165 = V_157 ;
V_165 >= V_156 ; V_165 -- ) {
unsigned int V_158 ;
if ( ! V_2 -> V_61 [ V_165 ] . V_62 ||
V_2 -> V_61 [ V_165 ] . V_60 != V_143 )
continue;
V_45 -> V_47 = V_165 ;
F_27 ( V_2 , V_45 ) ;
V_158 = F_49 ( V_45 ) ;
if ( ( V_158 & V_145 ) ==
V_168 )
break;
}
if ( V_116 <= V_165 ) {
V_166 = - V_49 ;
goto V_169;
}
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
F_31 ( V_45 , V_143 ) ;
V_45 -> V_47 = V_116 ;
F_44 ( V_45 , 0 , V_154 ) ;
F_52 ( V_45 , V_146 ) ;
F_53 ( V_45 , V_170 ,
V_131 ) ;
F_50 ( V_45 , 0 , V_142 ) ;
if ( V_155 == V_171 ) {
F_48 ( V_45 , V_162 ,
V_145 ) ;
} else {
V_155 |= V_161 ;
F_48 ( V_45 , V_163 ,
V_145 ) ;
}
F_41 ( V_45 , V_155 , V_142 ) ;
F_29 ( V_2 , V_45 -> V_47 , V_143 ) ;
}
F_34 ( V_45 , V_164 ) ;
F_24 ( V_2 , V_45 ) ;
V_169:
F_57 ( V_45 ) ;
return V_166 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 1 ; V_46 < V_172 ; V_46 ++ ) {
if ( ! V_2 -> V_173 [ V_46 ] )
return V_46 ;
}
return - V_49 ;
}
static struct V_44 * F_69 ( struct V_1 * V_2 ,
unsigned short V_174 ,
unsigned short V_175 )
{
struct V_44 * V_45 ;
int V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return NULL ;
F_31 ( V_45 , V_143 ) ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ ) {
unsigned int V_64 ;
bool V_160 ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
V_2 -> V_61 [ V_116 ] . V_60 != V_143 )
continue;
V_45 -> V_47 = V_116 ;
F_27 ( V_2 , V_45 ) ;
V_160 = F_40 ( V_45 , 0 , F_66 ( V_174 ) )
&& F_40 ( V_45 , 4 , F_66 ( V_175 ) ) ;
if ( ! V_160 )
continue;
V_64 = F_49 ( V_45 ) & V_145 ;
if ( V_64 == V_168 )
return V_45 ;
}
F_57 ( V_45 ) ;
return NULL ;
}
static int F_70 ( struct V_1 * V_2 , unsigned short V_174 ,
unsigned short V_175 ,
unsigned int V_164 )
{
struct V_44 * V_45 ;
int V_165 , V_116 , V_155 , V_166 = 0 ;
V_45 = F_69 ( V_2 , V_174 , V_175 ) ;
if ( ! V_45 ) {
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return - V_167 ;
V_155 = F_68 ( V_2 ) ;
if ( V_155 < 0 ) {
V_166 = V_155 ;
goto V_169;
}
for ( V_165 = V_156 ;
V_165 <= V_157 ; V_165 ++ ) {
unsigned int V_158 ;
if ( ! V_2 -> V_61 [ V_165 ] . V_62 ||
V_2 -> V_61 [ V_165 ] . V_60 != V_143 )
continue;
V_45 -> V_47 = V_165 ;
F_27 ( V_2 , V_45 ) ;
V_158 = F_49 ( V_45 ) ;
V_158 &= V_145 ;
if ( V_158 == V_162 ||
V_158 == V_163 )
break;
}
if ( V_116 >= V_165 ) {
V_166 = - V_176 ;
goto V_169;
}
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
F_31 ( V_45 , V_143 ) ;
V_45 -> V_47 = V_116 ;
V_2 -> V_173 [ V_155 ] = true ;
F_44 ( V_45 , 0 , V_174 ) ;
F_44 ( V_45 , 4 , V_175 ) ;
F_52 ( V_45 , V_143 ) ;
F_53 ( V_45 , 2 * V_170 ,
V_131 ) ;
F_48 ( V_45 , V_168 ,
V_145 ) ;
F_50 ( V_45 , V_155 | V_161 ,
V_142 ) ;
F_29 ( V_2 , V_45 -> V_47 , V_143 ) ;
}
F_34 ( V_45 , V_164 ) ;
F_24 ( V_2 , V_45 ) ;
V_169:
F_57 ( V_45 ) ;
return V_166 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned short V_177 ,
unsigned int V_63 , unsigned int V_64 )
{
struct V_44 V_45 ;
int V_116 ;
if ( ( V_177 != V_178 ) && ( V_177 != V_179 ) &&
( V_177 != V_180 ) )
return - V_49 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_181 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_181 ) ;
F_53 ( & V_45 , 12 , V_131 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_183 ) - 4 ,
V_184 ) ;
F_50 ( & V_45 , V_185 ,
V_185 ) ;
F_48 ( & V_45 , V_63 , V_64 | V_186 ) ;
F_36 ( & V_45 , 2 , 0x00 ,
V_187 ) ;
F_36 ( & V_45 , 3 , 0x00 ,
V_188 ) ;
F_36 ( & V_45 , 5 , V_177 , V_188 ) ;
F_41 ( & V_45 , 0 , V_185 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 . V_47 = V_116 ;
V_45 . V_58 . V_51 [ V_89 ] = 0x0 ;
V_45 . V_58 . V_51 [ V_189 ] = 0x0 ;
F_48 ( & V_45 , V_63 , V_64 ) ;
F_48 ( & V_45 , V_63 | V_190 ,
V_64 | V_186 ) ;
F_36 ( & V_45 , 2 , 0x00 , 0x0 ) ;
F_36 ( & V_45 , 3 , 0x00 , 0x0 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned short V_191 )
{
struct V_44 V_45 ;
int V_84 , V_116 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_181 ) ;
V_45 . V_47 = V_116 ;
switch ( V_191 ) {
case V_192 :
F_36 ( & V_45 , 0 , V_193 ,
V_194 ) ;
F_48 ( & V_45 , V_195 ,
V_196 ) ;
break;
case V_197 :
V_84 = V_198 ;
F_36 ( & V_45 , 0 , V_84 , V_84 ) ;
F_36 ( & V_45 , 1 , V_84 , V_84 ) ;
F_36 ( & V_45 , 2 , V_84 , V_84 ) ;
F_36 ( & V_45 , 3 , V_84 , V_84 ) ;
F_48 ( & V_45 , V_199 ,
V_196 ) ;
break;
default:
return - V_49 ;
}
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_41 ( & V_45 , V_185 ,
V_185 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned short V_177 ,
unsigned int V_63 , unsigned int V_64 )
{
struct V_44 V_45 ;
int V_116 ;
if ( ( V_177 != V_178 ) && ( V_177 != V_179 ) &&
( V_177 != V_200 ) && ( V_177 != V_201 ) )
return - V_49 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_202 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_63 , V_64 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_203 ) - 6 ,
V_184 ) ;
F_36 ( & V_45 , 0 , V_177 , V_188 ) ;
F_41 ( & V_45 , V_204 ,
V_204 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_202 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , unsigned short V_191 )
{
struct V_44 V_45 ;
int V_116 ;
if ( V_191 != V_192 )
return - V_49 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_202 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_202 ) ;
F_48 ( & V_45 , V_195 ,
V_196 ) ;
F_50 ( & V_45 , V_204 ,
V_204 ) ;
F_53 ( & V_45 , - 18 , V_131 ) ;
F_36 ( & V_45 , 0 , V_205 ,
V_206 ) ;
F_41 ( & V_45 , 0 , V_204 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_202 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , int V_8 , int V_207 ,
int V_208 , int V_3 )
{
T_1 V_18 ;
V_18 = F_3 ( V_2 , V_209 ) ;
V_18 &= ~ F_76 ( V_8 ) ;
V_18 |= F_77 ( V_8 , V_207 ) ;
F_1 ( V_2 , V_209 , V_18 ) ;
V_18 = F_3 ( V_2 , F_78 ( V_8 ) ) ;
V_18 &= ~ F_79 ( V_8 ) ;
V_18 |= F_80 ( V_8 , V_208 ) ;
F_1 ( V_2 , F_78 ( V_8 ) , V_18 ) ;
V_18 = F_3 ( V_2 , F_81 ( V_8 ) ) ;
V_18 &= ~ F_82 ( V_8 ) ;
V_18 |= F_83 ( V_8 , V_3 ) ;
F_1 ( V_2 , F_81 ( V_8 ) , V_18 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_210 ; V_8 ++ ) {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_118 ) ;
V_45 . V_47 = V_211 - V_8 ;
F_34 ( & V_45 , 0 ) ;
F_50 ( & V_45 , V_8 , V_119 ) ;
F_45 ( & V_45 , V_212 , 1 ) ;
F_29 ( V_2 , V_45 . V_47 , V_118 ) ;
F_24 ( V_2 , & V_45 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_47 = V_213 ;
F_31 ( & V_45 , V_214 ) ;
F_53 ( & V_45 , V_215 ,
V_131 ) ;
F_52 ( & V_45 , V_123 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_214 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_47 = V_216 ;
F_31 ( & V_45 , V_123 ) ;
F_48 ( & V_45 , V_124 ,
V_124 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_52 ( & V_45 , V_118 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_123 ) ;
F_24 ( V_2 , & V_45 ) ;
F_60 ( V_2 , 0 , false ) ;
F_61 ( V_2 , 0 , false ) ;
F_62 ( V_2 , 0 , V_133 , false ) ;
F_62 ( V_2 , 0 , V_217 , false ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
F_63 ( V_2 , 0 , false , V_218 ,
V_219 ) ;
F_63 ( V_2 , 0 , false , V_220 , V_219 ) ;
F_63 ( V_2 , 0 , false , V_218 ,
V_221 ) ;
F_63 ( V_2 , 0 , false , V_220 , V_221 ) ;
F_64 ( V_2 , 0 , false ,
V_218 , V_219 ) ;
F_64 ( V_2 , 0 , false ,
V_220 , V_219 ) ;
F_64 ( V_2 , 0 , true ,
V_218 , V_221 ) ;
F_64 ( V_2 , 0 , true ,
V_220 , V_221 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_127 ) ;
V_45 . V_47 = V_222 ;
F_52 ( & V_45 , V_143 ) ;
F_53 ( & V_45 , 0 , V_131 ) ;
F_29 ( V_2 , V_45 . V_47 , V_123 ) ;
F_50 ( & V_45 , 0 , V_142 ) ;
F_34 ( & V_45 , V_73 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_116 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_223 ) ;
F_53 ( & V_45 , V_224 ,
V_131 ) ;
F_52 ( & V_45 , V_225 ) ;
F_48 ( & V_45 , V_226 ,
V_226 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = false ;
F_30 ( V_2 , V_45 . V_47 , V_226 ,
V_226 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_230 ) ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_231 ,
V_232 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = true ;
F_30 ( V_2 , V_45 . V_47 , V_231 ,
V_232 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_234 ) ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_235 |
V_236 ,
V_237 |
V_238 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = true ;
F_30 ( V_2 , V_45 . V_47 , V_235 |
V_236 ,
V_237 |
V_238 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_239 ) ;
F_36 ( & V_45 , V_153 ,
V_240 | V_241 ,
V_242 |
V_243 ) ;
F_52 ( & V_45 , V_181 ) ;
F_48 ( & V_45 , V_244 ,
V_232 ) ;
F_53 ( & V_45 , V_153 + 4 ,
V_131 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = false ;
F_30 ( V_2 , V_45 . V_47 , V_244 ,
V_232 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 . V_47 = V_116 ;
V_45 . V_50 . V_67 [ F_37 ( V_153 ) ] = 0x0 ;
V_45 . V_50 . V_67 [ F_38 ( V_153 ) ] = 0x0 ;
F_36 ( & V_45 , V_153 ,
V_240 ,
V_242 ) ;
V_45 . V_58 . V_51 [ V_89 ] = 0x0 ;
V_45 . V_58 . V_51 [ V_189 ] = 0x0 ;
F_48 ( & V_45 , V_245 ,
V_232 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = false ;
F_30 ( V_2 , V_45 . V_47 , V_245 ,
V_232 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_246 ) ;
F_53 ( & V_45 , V_153 + 8 +
V_247 ,
V_131 ) ;
F_52 ( & V_45 , V_202 ) ;
F_48 ( & V_45 , V_248 ,
V_232 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = false ;
F_30 ( V_2 , V_45 . V_47 , V_248 ,
V_232 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_249 ;
F_34 ( & V_45 , V_73 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_52 ( & V_45 , V_118 ) ;
F_48 ( & V_45 , V_250 ,
V_232 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_227 = V_228 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_229 = true ;
F_30 ( V_2 , V_45 . V_47 , V_250 ,
V_232 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_89 ( struct V_251 * V_252 , struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_253 ;
V_2 -> V_173 = F_90 ( & V_252 -> V_254 , sizeof( bool ) ,
V_172 ,
V_117 ) ;
if ( ! V_2 -> V_173 )
return - V_167 ;
V_253 = F_70 ( V_2 , V_255 , V_256 ,
V_73 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_70 ( V_2 , V_255 , V_255 ,
V_73 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_67 ( V_2 , V_256 , V_171 ,
V_73 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_67 ( V_2 , V_255 , V_171 ,
V_73 ) ;
if ( V_253 )
return V_253 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_143 ) ;
V_45 . V_47 = V_257 ;
F_52 ( & V_45 , V_146 ) ;
F_50 ( & V_45 , 0 , V_142 ) ;
F_48 ( & V_45 , V_168 ,
V_145 ) ;
F_41 ( & V_45 , V_161 ,
V_161 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_143 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_143 ) ;
V_45 . V_47 = V_258 ;
F_52 ( & V_45 , V_146 ) ;
F_48 ( & V_45 , V_144 ,
V_145 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_143 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_116 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_225 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_259 ) ;
F_52 ( & V_45 , V_181 ) ;
F_48 ( & V_45 , V_245 ,
V_232 ) ;
F_53 ( & V_45 , V_153 + 4 ,
V_131 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_225 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 . V_47 = V_116 ;
F_36 ( & V_45 , V_153 ,
V_240 | V_241 ,
V_242 |
V_243 ) ;
V_45 . V_58 . V_51 [ V_89 ] = 0x0 ;
V_45 . V_58 . V_51 [ V_189 ] = 0x0 ;
F_48 ( & V_45 , V_244 ,
V_232 ) ;
F_29 ( V_2 , V_45 . V_47 , V_225 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_225 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_260 ) ;
F_52 ( & V_45 , V_202 ) ;
F_48 ( & V_45 , V_248 ,
V_232 ) ;
F_53 ( & V_45 , V_153 + 4 ,
V_131 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_225 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_225 ) ;
V_45 . V_47 = V_116 ;
F_48 ( & V_45 , V_250 ,
V_232 ) ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_54 ( & V_45 , V_233 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_225 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_253 ;
V_253 = F_71 ( V_2 , V_178 , V_261 ,
V_262 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_71 ( V_2 , V_179 , V_263 ,
V_262 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_71 ( V_2 , V_180 ,
V_235 |
V_236 ,
V_237 |
V_238 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_72 ( V_2 , V_197 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_72 ( V_2 , V_192 ) ;
if ( V_253 )
return V_253 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_181 ) ;
V_45 . V_47 = V_264 ;
F_52 ( & V_45 , V_181 ) ;
F_53 ( & V_45 , 12 , V_131 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_183 ) - 4 ,
V_184 ) ;
F_50 ( & V_45 , V_185 ,
V_185 ) ;
F_48 ( & V_45 , V_265 ,
V_262 ) ;
F_41 ( & V_45 , 0 , V_185 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_181 ) ;
V_45 . V_47 = V_266 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_267 ,
V_196 ) ;
F_41 ( & V_45 , V_185 ,
V_185 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_116 , V_253 ;
V_253 = F_73 ( V_2 , V_178 ,
V_261 ,
V_262 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_73 ( V_2 , V_179 ,
V_263 ,
V_262 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_73 ( V_2 , V_200 ,
V_235 |
V_236 ,
V_237 |
V_238 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_73 ( V_2 , V_201 ,
V_268 ,
V_269 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_74 ( V_2 , V_192 ) ;
if ( V_253 )
return V_253 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_202 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_250 |
V_124 ,
V_232 |
V_124 ) ;
F_36 ( & V_45 , 1 , 0x00 , V_270 ) ;
F_41 ( & V_45 , V_204 ,
V_204 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_202 ) ;
V_45 . V_47 = V_271 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_265 ,
V_262 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_203 ) - 4 ,
V_184 ) ;
F_41 ( & V_45 , V_204 ,
V_204 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_31 ( & V_45 , V_202 ) ;
V_45 . V_47 = V_272 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_265 ,
V_262 ) ;
F_41 ( & V_45 , V_273 ,
V_273 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_31 ( & V_45 , V_202 ) ;
V_45 . V_47 = V_274 ;
F_52 ( & V_45 , V_202 ) ;
F_48 ( & V_45 , V_267 ,
V_196 ) ;
F_50 ( & V_45 , V_204 ,
V_204 ) ;
F_53 ( & V_45 , - 18 , V_131 ) ;
F_41 ( & V_45 , 0 , V_204 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_202 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_94 ( struct V_251 * V_252 ,
struct V_1 * V_2 )
{
int V_253 , V_47 , V_46 ;
F_1 ( V_2 , V_275 , V_276 ) ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
F_1 ( V_2 , V_54 , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ )
F_1 ( V_2 , F_25 ( V_46 ) , 0 ) ;
F_1 ( V_2 , V_56 , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ )
F_1 ( V_2 , F_26 ( V_46 ) , 0 ) ;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ )
F_28 ( V_2 , V_47 ) ;
V_2 -> V_61 = F_90 ( & V_252 -> V_254 , V_48 ,
sizeof( * V_2 -> V_61 ) ,
V_117 ) ;
if ( ! V_2 -> V_61 )
return - V_167 ;
for ( V_47 = 0 ; V_47 < V_210 ; V_47 ++ )
F_75 ( V_2 , V_47 , V_214 ,
V_277 , 0 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
V_253 = F_88 ( V_2 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_89 ( V_252 , V_2 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_91 ( V_2 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_93 ( V_2 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_92 ( V_2 ) ;
if ( V_253 )
return V_253 ;
return 0 ;
}
static bool F_95 ( struct V_44 * V_45 ,
const T_6 * V_278 , unsigned char * V_84 )
{
unsigned char V_279 , V_280 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_130 ; V_47 ++ ) {
F_39 ( V_45 , V_47 , & V_279 , & V_280 ) ;
if ( V_280 != V_84 [ V_47 ] )
return false ;
if ( ( V_280 & V_279 ) != ( V_278 [ V_47 ] & V_84 [ V_47 ] ) )
return false ;
}
return true ;
}
static struct V_44 *
F_96 ( struct V_1 * V_2 , int V_281 , const T_6 * V_278 ,
unsigned char * V_84 , int V_282 )
{
struct V_44 * V_45 ;
int V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_283 ) ;
if ( ! V_45 )
return NULL ;
F_31 ( V_45 , V_123 ) ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ ) {
unsigned int V_284 ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
( V_2 -> V_61 [ V_116 ] . V_60 != V_123 ) ||
( V_2 -> V_61 [ V_116 ] . V_227 != V_282 ) )
continue;
V_45 -> V_47 = V_116 ;
F_27 ( V_2 , V_45 ) ;
V_284 = F_35 ( V_45 ) ;
if ( F_95 ( V_45 , V_278 , V_84 ) &&
V_284 == V_281 )
return V_45 ;
}
F_57 ( V_45 ) ;
return NULL ;
}
static int F_97 ( struct V_1 * V_2 , int V_8 ,
const T_6 * V_278 , bool V_69 )
{
struct V_44 * V_45 ;
unsigned int V_281 , V_285 , V_63 ;
unsigned char V_84 [ V_130 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_116 ;
V_45 = F_96 ( V_2 , ( 1 << V_8 ) , V_278 , V_84 ,
V_286 ) ;
if ( ! V_45 ) {
if ( ! V_69 )
return 0 ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ )
if ( V_2 -> V_61 [ V_116 ] . V_62 &&
( V_2 -> V_61 [ V_116 ] . V_60 == V_123 ) &&
( V_2 -> V_61 [ V_116 ] . V_227 ==
V_287 ) )
break;
V_116 = F_58 ( V_2 , V_156 ,
V_116 - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_283 ) ;
if ( ! V_45 )
return - V_167 ;
F_31 ( V_45 , V_123 ) ;
V_45 -> V_47 = V_116 ;
F_34 ( V_45 , 0 ) ;
}
F_33 ( V_45 , V_8 , V_69 ) ;
V_281 = F_35 ( V_45 ) ;
if ( V_281 == 0 ) {
if ( V_69 ) {
F_57 ( V_45 ) ;
return - V_49 ;
}
F_28 ( V_2 , V_45 -> V_47 ) ;
V_2 -> V_61 [ V_45 -> V_47 ] . V_62 = false ;
F_57 ( V_45 ) ;
return 0 ;
}
F_52 ( V_45 , V_127 ) ;
V_285 = V_130 ;
while ( V_285 -- )
F_36 ( V_45 , V_285 , V_278 [ V_285 ] , 0xff ) ;
if ( F_98 ( V_278 ) )
V_63 = V_288 ;
else if ( F_99 ( V_278 ) )
V_63 = V_134 ;
else
V_63 = V_128 | V_289 ;
F_48 ( V_45 , V_63 , V_129 |
V_289 ) ;
F_30 ( V_2 , V_45 -> V_47 , V_63 , V_129 |
V_289 ) ;
F_53 ( V_45 , 2 * V_130 ,
V_131 ) ;
V_2 -> V_61 [ V_45 -> V_47 ] . V_227 = V_286 ;
F_29 ( V_2 , V_45 -> V_47 , V_123 ) ;
F_24 ( V_2 , V_45 ) ;
F_57 ( V_45 ) ;
return 0 ;
}
static int F_100 ( struct V_290 * V_254 , const T_6 * V_278 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
int V_253 ;
V_253 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_254 -> V_291 ,
false ) ;
if ( V_253 )
return V_253 ;
V_253 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_278 , true ) ;
if ( V_253 )
return V_253 ;
F_102 ( V_254 -> V_291 , V_278 ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 , int V_8 )
{
struct V_44 V_45 ;
int V_47 , V_116 ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ ) {
unsigned char V_278 [ V_130 ] , V_292 [ V_130 ] ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
( V_2 -> V_61 [ V_116 ] . V_60 != V_123 ) ||
( V_2 -> V_61 [ V_116 ] . V_227 != V_286 ) )
continue;
V_45 . V_47 = V_116 ;
F_27 ( V_2 , & V_45 ) ;
for ( V_47 = 0 ; V_47 < V_130 ; V_47 ++ )
F_39 ( & V_45 , V_47 , & V_278 [ V_47 ] ,
& V_292 [ V_47 ] ) ;
if ( F_99 ( V_278 ) && ! F_98 ( V_278 ) )
F_97 ( V_2 , V_8 , V_278 , false ) ;
}
}
static int F_104 ( struct V_1 * V_2 , int V_8 , int type )
{
switch ( type ) {
case V_293 :
F_63 ( V_2 , V_8 , true ,
V_220 , V_219 ) ;
F_63 ( V_2 , V_8 , true ,
V_218 , V_219 ) ;
F_63 ( V_2 , V_8 , false ,
V_220 , V_221 ) ;
F_63 ( V_2 , V_8 , false ,
V_218 , V_221 ) ;
break;
case V_294 :
F_63 ( V_2 , V_8 , true ,
V_220 , V_221 ) ;
F_63 ( V_2 , V_8 , true ,
V_218 , V_221 ) ;
F_63 ( V_2 , V_8 , false ,
V_220 , V_219 ) ;
F_63 ( V_2 , V_8 , false ,
V_218 , V_219 ) ;
break;
case V_295 :
case V_296 :
F_63 ( V_2 , V_8 , false ,
V_220 , V_221 ) ;
F_63 ( V_2 , V_8 , false ,
V_218 , V_221 ) ;
F_63 ( V_2 , V_8 , false ,
V_220 , V_219 ) ;
F_63 ( V_2 , V_8 , false ,
V_218 , V_219 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_293 ) )
return - V_49 ;
}
return 0 ;
}
static int F_105 ( struct V_7 * V_8 )
{
struct V_44 * V_45 ;
int V_116 ;
V_45 = F_55 ( V_8 -> V_2 , V_8 -> V_42 ) ;
if ( ! V_45 ) {
V_116 = F_58 ( V_8 -> V_2 ,
V_157 ,
V_156 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return - V_167 ;
F_31 ( V_45 , V_118 ) ;
V_45 -> V_47 = V_116 ;
F_50 ( V_45 , V_8 -> V_42 , V_119 ) ;
F_45 ( V_45 , V_212 , 1 ) ;
F_29 ( V_8 -> V_2 , V_45 -> V_47 , V_118 ) ;
}
F_34 ( V_45 , ( 1 << V_8 -> V_42 ) ) ;
F_24 ( V_8 -> V_2 , V_45 ) ;
F_57 ( V_45 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
F_1 ( V_2 , V_299 , V_298 -> V_47 ) ;
F_1 ( V_2 , V_300 , V_298 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_301 , V_298 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_302 , V_298 -> V_4 [ 2 ] ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_303 * V_304 )
{
T_1 V_18 ;
V_18 = ( V_304 -> V_305 << V_306 ) | V_304 -> V_307 ;
F_1 ( V_2 , V_308 , V_18 ) ;
F_1 ( V_2 , V_309 , V_304 -> V_4 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_303 V_304 ;
struct V_297 V_298 ;
int V_47 ;
F_1 ( V_2 , V_310 , V_311 ) ;
memset ( & V_298 . V_4 , 0 , sizeof( V_298 . V_4 ) ) ;
for ( V_47 = 0 ; V_47 < V_312 ; V_47 ++ ) {
V_298 . V_47 = V_47 ;
F_106 ( V_2 , & V_298 ) ;
}
V_304 . V_4 = 0 ;
for ( V_47 = 0 ; V_47 < V_313 ; V_47 ++ ) {
V_304 . V_307 = V_47 ;
V_304 . V_305 = 0 ;
F_107 ( V_2 , & V_304 ) ;
V_304 . V_305 = 1 ;
F_107 ( V_2 , & V_304 ) ;
}
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_303 V_304 ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_2 , V_314 ) ;
V_18 &= ~ F_110 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_314 , V_18 ) ;
V_304 . V_307 = V_8 -> V_42 ;
V_304 . V_305 = 0 ;
V_304 . V_4 = 0 ;
V_304 . V_4 &= ~ V_315 ;
V_304 . V_4 |= V_8 -> V_316 ;
V_304 . V_4 &= ~ V_317 ;
F_107 ( V_8 -> V_2 , & V_304 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
T_1 V_18 ;
F_1 ( V_8 -> V_2 , F_112 ( V_8 -> V_42 ) ,
V_8 -> V_316 & V_318 ) ;
F_1 ( V_8 -> V_2 , F_113 ( V_8 -> V_42 ) ,
( V_8 -> V_316 >> V_319 ) ) ;
V_18 = F_3 ( V_8 -> V_2 , V_320 ) ;
V_18 |= F_114 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_320 , V_18 ) ;
}
static void * F_115 ( const struct V_321 * V_322 )
{
if ( F_116 ( V_322 -> V_323 <= V_324 ) )
return F_117 ( V_322 -> V_323 ) ;
else
return F_118 ( V_322 -> V_323 , V_283 ) ;
}
static void F_119 ( const struct V_321 * V_322 , void * V_4 )
{
if ( F_116 ( V_322 -> V_323 <= V_324 ) )
F_120 ( V_4 ) ;
else
F_57 ( V_4 ) ;
}
static int F_121 ( struct V_251 * V_252 ,
struct V_1 * V_2 ,
struct V_321 * V_325 , int V_20 )
{
T_1 V_18 ;
if ( ! F_122 ( V_20 , 16 ) )
return - V_49 ;
if ( V_2 -> V_11 == V_12 )
V_325 -> V_326 = 2 * sizeof( T_1 ) * V_20 ;
else
V_325 -> V_326 = 2 * sizeof( T_3 ) * V_20 ;
V_325 -> V_327 = F_123 ( & V_252 -> V_254 , V_325 -> V_326 ,
& V_325 -> V_17 ,
V_117 ) ;
if ( ! V_325 -> V_327 )
return - V_167 ;
if ( ! F_122 ( ( unsigned long ) V_325 -> V_327 ,
V_328 ) ) {
F_124 ( & V_252 -> V_254 , V_325 -> V_326 ,
V_325 -> V_327 , V_325 -> V_17 ) ;
F_125 ( & V_252 -> V_254 , L_1 ,
V_325 -> V_42 , V_328 ) ;
return - V_167 ;
}
F_1 ( V_2 , F_126 ( V_325 -> V_42 ) ,
F_127 ( V_325 -> V_17 ) ) ;
F_1 ( V_2 , F_128 ( V_325 -> V_42 ) , V_20 ) ;
V_18 = F_3 ( V_2 , F_129 ( V_325 -> V_42 ) ) ;
V_18 |= V_329 ;
F_1 ( V_2 , F_129 ( V_325 -> V_42 ) , V_18 ) ;
V_325 -> type = V_330 ;
V_325 -> V_20 = V_20 ;
V_325 -> V_331 = 0 ;
V_325 -> V_332 = 0 ;
return 0 ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_321 * V_325 ,
int V_333 )
{
T_1 V_18 ;
V_325 -> V_333 = V_333 ;
V_18 = F_131 ( V_333 , 1 << V_334 ) ;
F_1 ( V_2 , F_132 ( V_325 -> V_42 ) , V_18 ) ;
}
static void F_133 ( struct V_335 * V_254 , struct V_1 * V_2 ,
struct V_321 * V_325 ,
T_2 * V_17 ,
T_7 * V_336 )
{
int V_6 = F_134 () ;
* V_17 = F_6 ( V_2 , V_6 ,
F_135 ( V_325 -> V_42 ) ) ;
* V_336 = F_6 ( V_2 , V_6 , V_337 ) ;
if ( V_2 -> V_11 == V_338 ) {
T_1 V_18 ;
T_1 V_339 , V_340 ;
V_18 = F_6 ( V_2 , V_6 , V_341 ) ;
V_339 = ( V_18 & V_342 ) ;
V_340 = ( V_18 & V_343 ) >>
V_344 ;
if ( sizeof( T_2 ) == 8 )
* V_17 |= ( T_3 ) V_339 << 32 ;
if ( sizeof( T_7 ) == 8 )
* V_336 |= ( T_3 ) V_340 << 32 ;
}
F_136 () ;
}
static void F_137 ( struct V_335 * V_254 , struct V_1 * V_2 ,
struct V_321 * V_325 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_325 -> V_332 ; V_46 ++ ) {
T_2 V_14 ;
T_7 V_345 ;
void * V_4 ;
F_133 ( V_254 , V_2 , V_325 ,
& V_14 , & V_345 ) ;
F_138 ( V_254 , V_14 ,
V_325 -> V_333 , V_346 ) ;
V_4 = ( void * ) F_139 ( V_345 ) ;
if ( ! V_4 )
break;
F_119 ( V_325 , V_4 ) ;
}
V_325 -> V_332 -= V_46 ;
}
static int F_140 ( struct V_251 * V_252 ,
struct V_1 * V_2 ,
struct V_321 * V_325 )
{
T_1 V_18 ;
F_137 ( & V_252 -> V_254 , V_2 , V_325 ) ;
if ( V_325 -> V_332 ) {
F_141 ( 1 , L_2 , V_325 -> V_42 ) ;
return 0 ;
}
V_18 = F_3 ( V_2 , F_129 ( V_325 -> V_42 ) ) ;
V_18 |= V_347 ;
F_1 ( V_2 , F_129 ( V_325 -> V_42 ) , V_18 ) ;
F_124 ( & V_252 -> V_254 , V_325 -> V_326 ,
V_325 -> V_327 ,
V_325 -> V_17 ) ;
return 0 ;
}
static int F_142 ( struct V_251 * V_252 ,
struct V_1 * V_2 )
{
int V_46 , V_253 , V_20 ;
struct V_321 * V_325 ;
V_20 = V_348 ;
for ( V_46 = 0 ; V_46 < V_349 ; V_46 ++ ) {
V_325 = & V_2 -> V_350 [ V_46 ] ;
V_325 -> V_42 = V_46 ;
V_253 = F_121 ( V_252 , V_2 , V_325 , V_20 ) ;
if ( V_253 )
goto V_351;
F_130 ( V_2 , V_325 , 0 ) ;
}
return 0 ;
V_351:
F_125 ( & V_252 -> V_254 , L_3 , V_46 , V_20 ) ;
for ( V_46 = V_46 - 1 ; V_46 >= 0 ; V_46 -- )
F_140 ( V_252 , V_2 , & V_2 -> V_350 [ V_46 ] ) ;
return V_253 ;
}
static int F_143 ( struct V_251 * V_252 , struct V_1 * V_2 )
{
int V_46 , V_253 ;
for ( V_46 = 0 ; V_46 < V_349 ; V_46 ++ ) {
F_1 ( V_2 , F_144 ( V_46 ) , 0 ) ;
F_1 ( V_2 , F_145 ( V_46 ) , 0 ) ;
}
V_2 -> V_350 = F_90 ( & V_252 -> V_254 , V_349 ,
sizeof( * V_2 -> V_350 ) , V_117 ) ;
if ( ! V_2 -> V_350 )
return - V_167 ;
V_253 = F_142 ( V_252 , V_2 ) ;
if ( V_253 < 0 )
return V_253 ;
return 0 ;
}
static void F_146 ( struct V_7 * V_8 ,
int V_352 , int V_353 )
{
T_1 V_18 , V_84 ;
int V_354 ;
V_354 = V_8 -> V_355 [ V_352 ] -> V_42 ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_84 = V_356 ;
else
V_84 = V_357 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_354 ) ) ;
V_18 &= ~ V_84 ;
V_18 |= ( V_353 << V_358 ) & V_84 ;
F_1 ( V_8 -> V_2 , F_147 ( V_354 ) , V_18 ) ;
}
static void F_148 ( struct V_7 * V_8 ,
int V_352 , int V_359 )
{
T_1 V_18 , V_84 ;
int V_354 ;
V_354 = V_8 -> V_355 [ V_352 ] -> V_42 ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_84 = V_360 ;
else
V_84 = V_361 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_354 ) ) ;
V_18 &= ~ V_84 ;
V_18 |= ( V_359 << V_362 ) & V_84 ;
F_1 ( V_8 -> V_2 , F_147 ( V_354 ) , V_18 ) ;
}
static void * F_149 ( struct V_7 * V_8 ,
struct V_321 * V_325 ,
T_2 * V_14 ,
T_7 * V_345 ,
T_8 V_363 )
{
T_2 V_17 ;
void * V_4 ;
V_4 = F_115 ( V_325 ) ;
if ( ! V_4 )
return NULL ;
V_17 = F_150 ( V_8 -> V_254 -> V_254 . V_364 , V_4 ,
F_151 ( V_325 -> V_331 ) ,
V_346 ) ;
if ( F_152 ( F_153 ( V_8 -> V_254 -> V_254 . V_364 , V_17 ) ) ) {
F_119 ( V_325 , V_4 ) ;
return NULL ;
}
* V_14 = V_17 ;
* V_345 = F_154 ( V_4 ) ;
return V_4 ;
}
static inline void F_155 ( struct V_7 * V_8 , int V_322 ,
T_2 V_14 ,
T_7 V_345 )
{
int V_6 = F_134 () ;
if ( V_8 -> V_2 -> V_11 == V_338 ) {
T_1 V_18 = 0 ;
if ( sizeof( T_2 ) == 8 )
V_18 |= F_156 ( V_14 ) &
V_365 ;
if ( sizeof( T_7 ) == 8 )
V_18 |= ( F_156 ( V_345 )
<< V_366 ) &
V_367 ;
F_5 ( V_8 -> V_2 , V_6 ,
V_368 , V_18 ) ;
}
F_5 ( V_8 -> V_2 , V_6 ,
V_369 , V_345 ) ;
F_5 ( V_8 -> V_2 , V_6 ,
F_157 ( V_322 ) , V_14 ) ;
F_136 () ;
}
static int F_158 ( struct V_7 * V_8 ,
struct V_321 * V_325 , int V_332 )
{
int V_46 , V_333 , V_370 ;
T_2 V_17 ;
T_7 V_336 ;
void * V_371 ;
V_333 = F_151 ( V_325 -> V_331 ) ;
V_370 = F_159 ( V_333 ) ;
if ( V_332 < 0 ||
( V_332 + V_325 -> V_332 > V_325 -> V_20 ) ) {
F_160 ( V_8 -> V_254 ,
L_4 ,
V_332 , V_325 -> V_42 ) ;
return 0 ;
}
for ( V_46 = 0 ; V_46 < V_332 ; V_46 ++ ) {
V_371 = F_149 ( V_8 , V_325 , & V_17 ,
& V_336 , V_117 ) ;
if ( ! V_371 )
break;
F_155 ( V_8 , V_325 -> V_42 , V_17 ,
V_336 ) ;
}
V_325 -> V_332 += V_46 ;
F_161 ( V_8 -> V_254 ,
L_5 ,
V_325 -> type == V_372 ? L_6 : L_7 ,
V_325 -> V_42 , V_325 -> V_331 , V_333 , V_370 ) ;
F_161 ( V_8 -> V_254 ,
L_8 ,
V_325 -> type == V_372 ? L_6 : L_7 ,
V_325 -> V_42 , V_46 , V_332 ) ;
return V_46 ;
}
static struct V_321 *
F_162 ( struct V_7 * V_8 , int V_322 , enum V_373 type ,
int V_331 )
{
struct V_321 * V_374 = & V_8 -> V_2 -> V_350 [ V_322 ] ;
int V_375 ;
if ( V_374 -> type != V_330 && V_374 -> type != type ) {
F_160 ( V_8 -> V_254 , L_9 ) ;
return NULL ;
}
if ( V_374 -> type == V_330 )
V_374 -> type = type ;
if ( ( ( type == V_376 ) && ( V_331 > V_374 -> V_331 ) ) ||
( V_374 -> V_331 == 0 ) ) {
int V_377 ;
V_377 = V_374 -> V_332 ;
if ( V_377 == 0 )
V_377 = type == V_376 ?
V_378 :
V_379 ;
else
F_137 ( V_8 -> V_254 -> V_254 . V_364 ,
V_8 -> V_2 , V_374 ) ;
V_374 -> V_331 = V_331 ;
V_374 -> V_323 =
F_163 ( F_151 ( V_331 ) ) +
V_380 ;
V_375 = F_158 ( V_8 , V_374 , V_377 ) ;
if ( V_375 != V_377 ) {
F_141 ( 1 , L_10 ,
V_374 -> V_42 , V_375 , V_377 ) ;
return NULL ;
}
}
F_130 ( V_8 -> V_2 , V_374 ,
F_151 ( V_374 -> V_331 ) ) ;
return V_374 ;
}
static int F_164 ( struct V_7 * V_8 )
{
int V_381 ;
if ( ! V_8 -> V_382 ) {
V_8 -> V_382 =
F_162 ( V_8 , F_165 ( V_8 -> V_42 ) ,
V_376 ,
V_8 -> V_331 ) ;
if ( ! V_8 -> V_382 )
return - V_167 ;
V_8 -> V_382 -> V_164 |= ( 1 << V_8 -> V_42 ) ;
for ( V_381 = 0 ; V_381 < V_8 -> V_383 ; V_381 ++ )
F_146 ( V_8 , V_381 , V_8 -> V_382 -> V_42 ) ;
}
if ( ! V_8 -> V_384 ) {
V_8 -> V_384 =
F_162 ( V_8 , V_385 ,
V_372 ,
V_386 ) ;
if ( ! V_8 -> V_384 )
return - V_167 ;
V_8 -> V_384 -> V_164 |= ( 1 << V_8 -> V_42 ) ;
for ( V_381 = 0 ; V_381 < V_8 -> V_383 ; V_381 ++ )
F_148 ( V_8 , V_381 ,
V_8 -> V_384 -> V_42 ) ;
}
return 0 ;
}
static int F_166 ( struct V_290 * V_254 , int V_387 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_321 * V_388 = V_8 -> V_382 ;
int V_375 , V_377 = V_388 -> V_332 ;
int V_331 = F_167 ( V_387 ) ;
F_137 ( V_254 -> V_254 . V_364 , V_8 -> V_2 , V_388 ) ;
if ( V_388 -> V_332 ) {
F_141 ( 1 , L_2 , V_388 -> V_42 ) ;
return - V_389 ;
}
V_388 -> V_331 = V_331 ;
V_388 -> V_323 = F_163 ( F_151 ( V_331 ) ) +
V_380 ;
V_375 = F_158 ( V_8 , V_388 , V_377 ) ;
if ( V_375 != V_377 ) {
F_141 ( 1 , L_10 ,
V_388 -> V_42 , V_375 , V_377 ) ;
return - V_389 ;
}
F_130 ( V_8 -> V_2 , V_388 ,
F_151 ( V_388 -> V_331 ) ) ;
V_254 -> V_387 = V_387 ;
F_168 ( V_254 ) ;
return 0 ;
}
static inline void F_169 ( struct V_7 * V_8 )
{
int V_46 , V_390 = 0 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ )
V_390 |= V_8 -> V_392 [ V_46 ] . V_390 ;
F_1 ( V_8 -> V_2 , F_170 ( V_8 -> V_42 ) ,
F_171 ( V_390 ) ) ;
}
static inline void F_172 ( struct V_7 * V_8 )
{
int V_46 , V_390 = 0 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ )
V_390 |= V_8 -> V_392 [ V_46 ] . V_390 ;
F_1 ( V_8 -> V_2 , F_170 ( V_8 -> V_42 ) ,
F_173 ( V_390 ) ) ;
}
static inline void F_174 ( struct V_393 * V_394 )
{
struct V_7 * V_8 = V_394 -> V_8 ;
F_1 ( V_8 -> V_2 , F_170 ( V_8 -> V_42 ) ,
F_171 ( V_394 -> V_390 ) ) ;
}
static inline void F_175 ( struct V_393 * V_394 )
{
struct V_7 * V_8 = V_394 -> V_8 ;
F_1 ( V_8 -> V_2 , F_170 ( V_8 -> V_42 ) ,
F_173 ( V_394 -> V_390 ) ) ;
}
static void F_176 ( void * V_395 )
{
struct V_7 * V_8 = V_395 ;
F_5 ( V_8 -> V_2 , F_177 () ,
F_178 ( V_8 -> V_42 ) , 0 ) ;
}
static void F_179 ( void * V_395 )
{
struct V_7 * V_8 = V_395 ;
T_1 V_18 ;
V_18 = V_396 |
V_397 ;
if ( V_8 -> V_398 )
V_18 |= V_399 ;
F_5 ( V_8 -> V_2 , F_177 () ,
F_178 ( V_8 -> V_42 ) , V_18 ) ;
}
static void
F_180 ( struct V_7 * V_8 , bool V_84 )
{
T_1 V_18 ;
int V_46 ;
if ( V_8 -> V_2 -> V_11 != V_338 )
return;
if ( V_84 )
V_18 = 0 ;
else
V_18 = V_397 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ ) {
struct V_393 * V_400 = V_8 -> V_392 + V_46 ;
if ( V_400 -> type != V_401 )
continue;
F_5 ( V_8 -> V_2 , V_400 -> V_402 ,
F_178 ( V_8 -> V_42 ) , V_18 ) ;
}
}
static void F_181 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_18 ;
F_182 ( V_2 -> V_403 , V_404 , & V_18 ) ;
V_18 |= V_405 ;
F_183 ( V_2 -> V_403 , V_404 , V_18 ) ;
F_182 ( V_2 -> V_403 , V_406 , & V_18 ) ;
if ( V_8 -> V_407 == 2 )
V_18 |= V_408 | V_409 ;
else if ( V_8 -> V_407 == 3 )
V_18 |= V_410 ;
F_183 ( V_2 -> V_403 , V_406 , V_18 ) ;
}
static void F_184 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_18 ;
F_182 ( V_2 -> V_403 , V_404 , & V_18 ) ;
V_18 |= V_405 |
V_411 ;
F_183 ( V_2 -> V_403 , V_404 , V_18 ) ;
if ( V_8 -> V_407 > 1 ) {
F_182 ( V_2 -> V_403 , V_406 , & V_18 ) ;
if ( V_8 -> V_407 == 2 )
V_18 &= ~ V_408 ;
else if ( V_8 -> V_407 == 3 )
V_18 &= ~ V_410 ;
F_183 ( V_2 -> V_403 , V_406 , V_18 ) ;
}
}
static void F_185 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
void T_9 * V_412 = V_2 -> V_413 + F_186 ( V_8 -> V_407 ) ;
void T_9 * V_414 = V_2 -> V_413 + F_187 ( V_8 -> V_407 ) ;
T_1 V_18 ;
V_18 = F_4 ( V_414 + V_415 ) ;
V_18 &= ~ ( F_188 ( 0x3 ) |
F_189 ( 0x3 ) ) ;
V_18 |= F_189 ( 2 ) ;
F_2 ( V_18 , V_414 + V_415 ) ;
V_18 = F_4 ( V_412 + V_416 ) ;
V_18 &= ~ V_417 ;
F_2 ( V_18 , V_412 + V_416 ) ;
V_18 = F_4 ( V_412 + V_418 ) ;
V_18 &= ~ ( F_190 ( 0x7 ) | V_419 |
V_420 | V_421 ) ;
V_18 |= F_190 ( 1 ) ;
F_2 ( V_18 , V_412 + V_418 ) ;
V_18 &= ~ V_422 ;
V_18 |= V_419 | V_420 | V_421 ;
F_2 ( V_18 , V_412 + V_418 ) ;
}
static int F_191 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_18 ;
if ( ! V_2 -> V_403 )
return 0 ;
switch ( V_8 -> V_423 ) {
case V_424 :
case V_425 :
case V_426 :
case V_427 :
if ( V_8 -> V_407 == 0 )
goto V_428;
F_181 ( V_8 ) ;
break;
case V_429 :
F_184 ( V_8 ) ;
break;
case V_430 :
if ( V_8 -> V_407 != 0 )
goto V_428;
F_185 ( V_8 ) ;
break;
default:
goto V_431;
}
F_182 ( V_2 -> V_403 , V_432 , & V_18 ) ;
V_18 |= F_192 ( V_8 -> V_407 ) |
F_193 ( V_8 -> V_407 ) ;
F_183 ( V_2 -> V_403 , V_432 , V_18 ) ;
F_182 ( V_2 -> V_403 , V_404 , & V_18 ) ;
V_18 |= V_433 ;
F_183 ( V_2 -> V_403 , V_404 , V_18 ) ;
F_182 ( V_2 -> V_403 , V_434 , & V_18 ) ;
V_18 |= V_435 ;
F_183 ( V_2 -> V_403 , V_434 , V_18 ) ;
V_431:
return 0 ;
V_428:
F_160 ( V_8 -> V_254 , L_11 ) ;
return - V_49 ;
}
static void F_194 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( F_195 ( V_8 -> V_423 ) ||
V_8 -> V_423 == V_429 ) {
V_18 = F_4 ( V_8 -> V_436 + V_437 ) ;
V_18 |= V_438 ;
F_2 ( V_18 , V_8 -> V_436 + V_437 ) ;
}
if ( V_8 -> V_407 == 0 ) {
V_18 = F_4 ( V_8 -> V_436 + V_439 ) ;
if ( V_8 -> V_423 == V_430 )
V_18 |= V_440 ;
else
V_18 |= V_441 ;
F_2 ( V_18 , V_8 -> V_436 + V_439 ) ;
}
}
static void F_196 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_407 == 0 ) {
V_18 = F_4 ( V_8 -> V_436 + V_439 ) ;
V_18 &= ~ ( V_440 |
V_441 ) ;
F_2 ( V_18 , V_8 -> V_436 + V_439 ) ;
}
if ( F_195 ( V_8 -> V_423 ) ||
V_8 -> V_423 == V_429 ) {
V_18 = F_4 ( V_8 -> V_436 + V_437 ) ;
V_18 &= ~ V_438 ;
F_2 ( V_18 , V_8 -> V_436 + V_437 ) ;
}
}
static void F_197 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( F_195 ( V_8 -> V_423 ) ||
V_8 -> V_423 == V_429 ) {
V_18 = F_4 ( V_8 -> V_436 + V_442 ) ;
V_18 |= V_443 ;
F_2 ( V_18 , V_8 -> V_436 + V_442 ) ;
}
if ( V_8 -> V_407 == 0 ) {
V_18 = F_4 ( V_8 -> V_436 + V_444 ) ;
V_18 |= V_445 ;
F_2 ( V_18 , V_8 -> V_436 + V_444 ) ;
}
F_194 ( V_8 ) ;
}
static int F_198 ( struct V_7 * V_8 )
{
enum V_446 V_447 ;
int V_166 ;
if ( ! V_8 -> V_448 )
return 0 ;
switch ( V_8 -> V_423 ) {
case V_429 :
V_447 = V_449 ;
break;
case V_430 :
V_447 = V_450 ;
break;
default:
return - V_49 ;
}
V_166 = F_199 ( V_8 -> V_448 , V_447 ) ;
if ( V_166 )
return V_166 ;
return F_200 ( V_8 -> V_448 ) ;
}
static void F_201 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_423 == V_429 ) {
V_18 = F_4 ( V_8 -> V_436 + V_451 ) ;
V_18 |= V_452 | V_453 |
V_454 ;
V_18 &= ~ V_455 ;
F_2 ( V_18 , V_8 -> V_436 + V_451 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_456 ) ;
V_18 |= V_457 ;
V_18 &= ~ V_458 ;
F_2 ( V_18 , V_8 -> V_436 + V_456 ) ;
} else if ( F_195 ( V_8 -> V_423 ) ) {
V_18 = F_4 ( V_8 -> V_436 + V_451 ) ;
V_18 |= V_455 |
V_452 |
V_454 ;
V_18 &= ~ V_453 ;
F_2 ( V_18 , V_8 -> V_436 + V_451 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_456 ) ;
V_18 &= ~ V_457 ;
F_2 ( V_18 , V_8 -> V_436 + V_456 ) ;
}
V_18 = F_4 ( V_8 -> V_436 + V_459 ) ;
V_18 &= ~ V_460 ;
F_2 ( V_18 , V_8 -> V_436 + V_459 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_461 ) ;
V_18 |= V_462 |
V_463 | V_464 |
V_465 ;
if ( V_8 -> V_423 == V_429 )
V_18 |= V_466 ;
F_2 ( V_18 , V_8 -> V_436 + V_461 ) ;
}
static void F_202 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_461 ) ;
V_18 &= ~ V_467 ;
V_18 |= V_468 ;
F_2 ( V_18 , V_8 -> V_436 + V_461 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_456 ) ;
V_18 |= V_469 ;
F_2 ( V_18 , V_8 -> V_436 + V_456 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_456 ) ;
if ( V_8 -> V_423 == V_429 ) {
V_18 |= V_470 | V_471 ;
} else if ( F_195 ( V_8 -> V_423 ) ) {
V_18 &= ~ V_471 ;
}
F_2 ( V_18 , V_8 -> V_436 + V_456 ) ;
F_201 ( V_8 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_456 ) ;
V_18 &= ~ V_469 ;
F_2 ( V_18 , V_8 -> V_436 + V_456 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_461 ) ;
V_18 &= ~ V_468 ;
F_2 ( V_18 , V_8 -> V_436 + V_461 ) ;
}
static void F_203 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_407 != 0 )
return;
V_18 = F_4 ( V_8 -> V_436 + V_472 ) ;
V_18 |= V_473 ;
F_2 ( V_18 , V_8 -> V_436 + V_472 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_474 ) ;
V_18 &= ~ V_475 ;
V_18 |= V_476 | V_477 ;
F_2 ( V_18 , V_8 -> V_436 + V_474 ) ;
}
static void F_204 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_407 == 0 ) {
V_18 = F_4 ( V_8 -> V_436 + V_478 ) ;
V_18 &= ~ V_479 ;
if ( V_8 -> V_423 == V_480 ||
V_8 -> V_423 == V_430 )
V_18 |= V_481 ;
else
V_18 |= V_482 ;
F_2 ( V_18 , V_8 -> V_436 + V_478 ) ;
}
}
static void F_205 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_11 == V_338 )
F_204 ( V_8 ) ;
if ( F_195 ( V_8 -> V_423 ) ||
V_8 -> V_423 == V_429 )
F_202 ( V_8 ) ;
else if ( V_8 -> V_423 == V_430 )
F_203 ( V_8 ) ;
}
static void F_206 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_461 ) ;
V_18 |= V_483 ;
F_2 ( V_18 , V_8 -> V_436 + V_461 ) ;
}
static void F_207 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_407 == 0 &&
( V_8 -> V_423 == V_480 ||
V_8 -> V_423 == V_430 ) ) {
V_18 = F_4 ( V_8 -> V_436 + V_472 ) ;
V_18 |= V_484 |
V_485 ;
V_18 &= ~ V_486 ;
F_2 ( V_18 , V_8 -> V_436 + V_472 ) ;
} else {
V_18 = F_4 ( V_8 -> V_436 + V_459 ) ;
V_18 |= V_487 ;
V_18 |= V_488 ;
F_2 ( V_18 , V_8 -> V_436 + V_459 ) ;
}
}
static void F_208 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_407 == 0 &&
( V_8 -> V_423 == V_480 ||
V_8 -> V_423 == V_430 ) ) {
V_18 = F_4 ( V_8 -> V_436 + V_472 ) ;
V_18 &= ~ ( V_484 |
V_485 ) ;
F_2 ( V_18 , V_8 -> V_436 + V_472 ) ;
} else {
V_18 = F_4 ( V_8 -> V_436 + V_459 ) ;
V_18 &= ~ ( V_487 ) ;
F_2 ( V_18 , V_8 -> V_436 + V_459 ) ;
}
}
static void F_209 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_489 ) &
~ V_490 ;
F_2 ( V_18 , V_8 -> V_436 + V_489 ) ;
}
static void F_210 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_489 ) ;
if ( V_8 -> V_491 == 1000 )
V_18 |= V_492 ;
else
V_18 &= ~ V_492 ;
if ( V_8 -> V_423 == V_429 )
V_18 |= V_493 ;
else
V_18 &= ~ V_493 ;
F_2 ( V_18 , V_8 -> V_436 + V_489 ) ;
}
static void F_211 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_456 ) &
~ V_469 ;
F_2 ( V_18 , V_8 -> V_436 + V_456 ) ;
while ( F_4 ( V_8 -> V_436 + V_456 ) &
V_469 )
continue;
}
static inline void F_212 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_459 ) ;
V_18 &= ~ V_494 ;
V_18 |= ( ( ( V_8 -> V_331 - V_215 ) / 2 ) <<
V_495 ) ;
F_2 ( V_18 , V_8 -> V_436 + V_459 ) ;
}
static inline void F_213 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_436 + V_496 ) ;
V_18 &= ~ V_497 ;
V_18 |= ( ( V_8 -> V_331 - V_215 ) / 2 ) <<
V_498 ;
F_2 ( V_18 , V_8 -> V_436 + V_496 ) ;
}
static void F_214 ( struct V_7 * V_8 )
{
int V_499 , V_18 , V_500 , V_501 , V_352 ;
if ( V_8 -> V_2 -> V_11 == V_12 ) {
if ( V_8 -> V_502 & V_503 )
F_210 ( V_8 ) ;
V_18 = F_4 ( V_8 -> V_436 + V_504 ) ;
V_18 &= ~ V_505 ;
V_18 |= F_215 ( 64 - 4 - 2 ) ;
F_2 ( V_18 , V_8 -> V_436 + V_504 ) ;
}
V_499 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_506 ,
V_499 ) ;
F_1 ( V_8 -> V_2 , V_507 , 0 ) ;
for ( V_500 = 0 ; V_500 < V_43 ; V_500 ++ ) {
V_501 = F_23 ( V_8 -> V_42 , V_500 ) ;
F_1 ( V_8 -> V_2 ,
F_216 ( V_501 ) , 0 ) ;
}
F_1 ( V_8 -> V_2 , V_508 ,
V_8 -> V_2 -> V_509 / V_510 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_511 ) ;
V_18 &= ~ V_512 ;
V_18 |= F_217 ( 1 ) ;
V_18 |= V_513 ;
F_1 ( V_8 -> V_2 , V_511 , V_18 ) ;
V_18 = V_514 ;
F_1 ( V_8 -> V_2 , V_515 , V_18 ) ;
F_1 ( V_8 -> V_2 , F_218 ( V_8 -> V_42 ) ,
V_516 |
F_219 ( 256 ) ) ;
for ( V_352 = 0 ; V_352 < V_8 -> V_383 ; V_352 ++ ) {
V_500 = V_8 -> V_355 [ V_352 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_500 ) ) ;
V_18 |= V_517 |
V_518 ;
F_1 ( V_8 -> V_2 , F_147 ( V_500 ) , V_18 ) ;
}
F_172 ( V_8 ) ;
}
static void F_220 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_352 , V_500 ;
for ( V_352 = 0 ; V_352 < V_8 -> V_383 ; V_352 ++ ) {
V_500 = V_8 -> V_355 [ V_352 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_500 ) ) ;
V_18 &= ~ V_519 ;
F_1 ( V_8 -> V_2 , F_147 ( V_500 ) , V_18 ) ;
}
}
static void F_221 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_352 , V_500 ;
for ( V_352 = 0 ; V_352 < V_8 -> V_383 ; V_352 ++ ) {
V_500 = V_8 -> V_355 [ V_352 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_500 ) ) ;
V_18 |= V_519 ;
F_1 ( V_8 -> V_2 , F_147 ( V_500 ) , V_18 ) ;
}
}
static void F_222 ( struct V_7 * V_8 )
{
T_1 V_520 ;
int V_500 ;
int V_499 = F_22 ( V_8 ) ;
V_520 = 0 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
struct V_522 * V_21 = V_8 -> V_523 [ V_500 ] ;
if ( V_21 -> V_524 )
V_520 |= ( 1 << V_500 ) ;
}
F_1 ( V_8 -> V_2 , V_506 , V_499 ) ;
F_1 ( V_8 -> V_2 , V_525 , V_520 ) ;
}
static void F_223 ( struct V_7 * V_8 )
{
T_1 V_526 ;
int V_527 ;
int V_499 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_506 , V_499 ) ;
V_526 = ( F_3 ( V_8 -> V_2 , V_525 ) ) &
V_528 ;
if ( V_526 != 0 )
F_1 ( V_8 -> V_2 , V_525 ,
( V_526 << V_529 ) ) ;
V_527 = 0 ;
do {
if ( V_527 >= V_530 ) {
F_224 ( V_8 -> V_254 ,
L_12 ,
V_526 ) ;
break;
}
F_225 ( 1 ) ;
V_527 ++ ;
V_526 = F_3 ( V_8 -> V_2 , V_525 ) ;
} while ( V_526 & V_528 );
}
static inline int
F_226 ( struct V_7 * V_8 , int V_531 )
{
T_1 V_18 = F_3 ( V_8 -> V_2 , F_227 ( V_531 ) ) ;
return V_18 & V_532 ;
}
static inline void
F_228 ( struct V_7 * V_8 , int V_531 ,
int V_533 , int V_534 )
{
T_1 V_18 = V_533 | ( V_534 << V_535 ) ;
F_1 ( V_8 -> V_2 , F_229 ( V_531 ) , V_18 ) ;
}
static inline struct V_25 *
F_230 ( struct V_536 * V_381 )
{
int V_26 = V_381 -> V_537 ;
V_381 -> V_537 = F_231 ( V_381 , V_26 ) ;
F_232 ( V_381 -> V_524 + V_381 -> V_537 ) ;
return V_381 -> V_524 + V_26 ;
}
static void F_233 ( struct V_7 * V_8 ,
int V_354 , int V_3 )
{
T_1 V_18 ;
V_3 = V_3 >> 5 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_354 ) ) ;
V_18 &= ~ V_538 ;
V_18 |= ( ( V_3 << V_539 ) &
V_538 ) ;
F_1 ( V_8 -> V_2 , F_147 ( V_354 ) , V_18 ) ;
}
static struct V_9 *
F_234 ( struct V_522 * V_21 )
{
int V_10 = V_21 -> V_537 ;
V_21 -> V_537 = F_231 ( V_21 , V_10 ) ;
return V_21 -> V_524 + V_10 ;
}
static void F_235 ( struct V_7 * V_8 , int V_540 )
{
F_5 ( V_8 -> V_2 , F_177 () ,
V_541 , V_540 ) ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_522 * V_542 , int V_375 )
{
if ( ( V_542 -> V_543 + V_375 ) > V_542 -> V_20 ) {
int V_6 = F_177 () ;
T_1 V_18 = F_3 ( V_2 , F_237 ( V_6 ) ) ;
V_542 -> V_543 = V_18 & V_544 ;
}
if ( ( V_542 -> V_543 + V_375 ) > V_542 -> V_20 )
return - V_167 ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 ,
struct V_522 * V_21 , int V_375 )
{
T_1 V_18 ;
int V_6 = F_177 () ;
V_18 = ( V_21 -> V_42 << V_545 ) | V_375 ;
F_5 ( V_2 , V_6 , V_546 , V_18 ) ;
V_18 = F_6 ( V_2 , V_6 , V_547 ) ;
return V_18 & V_548 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_522 * V_21 ,
struct V_31 * V_32 ,
int V_375 )
{
int V_549 , V_6 , V_550 ;
if ( V_32 -> V_551 >= V_375 )
return 0 ;
V_550 = 0 ;
F_240 (cpu) {
struct V_31 * V_552 ;
V_552 = F_241 ( V_21 -> V_553 , V_6 ) ;
V_550 += V_552 -> V_543 ;
V_550 += V_552 -> V_551 ;
}
V_549 = F_242 ( V_554 , V_375 - V_32 -> V_551 ) ;
V_550 += V_549 ;
if ( V_550 >
( V_21 -> V_20 - ( F_243 () * V_554 ) ) )
return - V_167 ;
V_32 -> V_551 += F_238 ( V_2 , V_21 , V_549 ) ;
if ( V_32 -> V_551 < V_375 )
return - V_167 ;
return 0 ;
}
static void F_244 ( struct V_522 * V_21 )
{
if ( V_21 -> V_537 == 0 )
V_21 -> V_537 = V_21 -> V_555 - 1 ;
else
V_21 -> V_537 -- ;
}
static T_1 F_245 ( int V_556 , int V_557 ,
int V_558 , int V_559 )
{
T_1 V_23 ;
V_23 = ( V_556 << V_560 ) ;
V_23 |= ( V_558 << V_561 ) ;
V_23 |= V_562 ;
if ( V_557 == F_66 ( V_239 ) ) {
V_23 &= ~ V_562 ;
V_23 &= ~ V_563 ;
} else {
V_23 |= V_563 ;
}
if ( V_559 == V_178 ) {
V_23 &= ~ V_564 ;
V_23 &= ~ V_565 ;
} else if ( V_559 == V_179 ) {
V_23 |= V_564 ;
V_23 &= ~ V_565 ;
} else {
V_23 |= V_566 ;
}
return V_23 ;
}
static inline int F_246 ( struct V_7 * V_8 ,
struct V_522 * V_21 )
{
T_1 V_18 ;
V_18 = F_6 ( V_8 -> V_2 , F_177 () ,
F_247 ( V_21 -> V_42 ) ) ;
return ( V_18 & V_567 ) >>
V_568 ;
}
static void F_248 ( void * V_395 )
{
struct V_7 * V_8 = V_395 ;
int V_500 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
int V_42 = V_8 -> V_523 [ V_500 ] -> V_42 ;
F_6 ( V_8 -> V_2 , F_177 () ,
F_247 ( V_42 ) ) ;
}
}
static void F_249 ( struct V_7 * V_8 )
{
T_1 V_18 , V_20 , V_387 ;
int V_21 , V_499 ;
V_387 = V_8 -> V_331 * 8 ;
if ( V_387 > V_569 )
V_387 = V_569 ;
V_387 = 3 * V_387 ;
V_499 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_506 , V_499 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_570 ) ;
V_18 &= ~ V_569 ;
V_18 |= V_387 ;
F_1 ( V_8 -> V_2 , V_570 , V_18 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_515 ) ;
V_20 = V_18 & V_514 ;
if ( V_20 < V_387 ) {
V_20 = V_387 ;
V_18 &= ~ V_514 ;
V_18 |= V_20 ;
F_1 ( V_8 -> V_2 , V_515 , V_18 ) ;
}
for ( V_21 = 0 ; V_21 < V_8 -> V_521 ; V_21 ++ ) {
V_18 = F_3 ( V_8 -> V_2 ,
F_250 ( V_21 ) ) ;
V_20 = V_18 & V_571 ;
if ( V_20 < V_387 ) {
V_20 = V_387 ;
V_18 &= ~ V_571 ;
V_18 |= V_20 ;
F_1 ( V_8 -> V_2 ,
F_250 ( V_21 ) ,
V_18 ) ;
}
}
}
static void F_251 ( struct V_7 * V_8 ,
struct V_536 * V_381 )
{
int V_6 = F_134 () ;
if ( V_381 -> V_572 > V_573 )
V_381 -> V_572 = V_573 ;
F_5 ( V_8 -> V_2 , V_6 , V_574 , V_381 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_575 ,
V_381 -> V_572 ) ;
F_136 () ;
}
static void F_252 ( struct V_7 * V_8 ,
struct V_522 * V_21 )
{
int V_6 = F_134 () ;
T_1 V_18 ;
if ( V_21 -> V_576 > V_577 )
V_21 -> V_576 = V_577 ;
V_18 = ( V_21 -> V_576 << V_578 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_579 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_580 , V_18 ) ;
F_136 () ;
}
static T_1 F_253 ( T_1 V_581 , unsigned long V_582 )
{
T_3 V_583 = ( T_3 ) V_582 * V_581 ;
F_254 ( V_583 , V_510 ) ;
return V_583 > V_584 ? V_584 : V_583 ;
}
static T_1 F_255 ( T_1 V_585 , unsigned long V_582 )
{
T_3 V_583 = ( T_3 ) V_585 * V_510 ;
F_254 ( V_583 , V_582 ) ;
return V_583 > V_584 ? V_584 : V_583 ;
}
static void F_256 ( struct V_7 * V_8 ,
struct V_536 * V_381 )
{
unsigned long V_586 = V_8 -> V_2 -> V_509 ;
T_1 V_18 = F_253 ( V_381 -> V_587 , V_586 ) ;
if ( V_18 > V_588 ) {
V_381 -> V_587 =
F_255 ( V_588 , V_586 ) ;
V_18 = F_253 ( V_381 -> V_587 , V_586 ) ;
}
F_1 ( V_8 -> V_2 , F_257 ( V_381 -> V_42 ) , V_18 ) ;
}
static void F_258 ( struct V_7 * V_8 )
{
unsigned long V_586 = V_8 -> V_2 -> V_509 ;
T_1 V_18 = F_253 ( V_8 -> V_589 , V_586 ) ;
if ( V_18 > V_590 ) {
V_8 -> V_589 =
F_255 ( V_590 , V_586 ) ;
V_18 = F_253 ( V_8 -> V_589 , V_586 ) ;
}
F_1 ( V_8 -> V_2 , F_259 ( V_8 -> V_42 ) , V_18 ) ;
}
static void F_260 ( struct V_7 * V_8 ,
struct V_522 * V_21 ,
struct V_31 * V_32 , int V_375 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_375 ; V_46 ++ ) {
struct V_36 * V_37 =
V_32 -> V_38 + V_32 -> V_33 ;
if ( ! F_261 ( V_32 , V_37 -> V_40 ) )
F_138 ( V_8 -> V_254 -> V_254 . V_364 , V_37 -> V_40 ,
V_37 -> V_20 , V_591 ) ;
if ( V_37 -> V_35 )
F_262 ( V_37 -> V_35 ) ;
F_20 ( V_32 ) ;
}
}
static inline struct V_536 * F_263 ( struct V_7 * V_8 ,
T_1 V_592 )
{
int V_500 = F_264 ( V_592 ) - 1 ;
return V_8 -> V_355 [ V_500 ] ;
}
static inline struct V_522 * F_265 ( struct V_7 * V_8 ,
T_1 V_592 )
{
int V_500 = F_264 ( V_592 ) - 1 ;
return V_8 -> V_523 [ V_500 ] ;
}
static void F_266 ( struct V_7 * V_8 , struct V_522 * V_21 ,
struct V_31 * V_32 )
{
struct V_593 * V_594 = F_267 ( V_8 -> V_254 , V_21 -> V_595 ) ;
int V_596 ;
if ( V_32 -> V_6 != F_177 () )
F_160 ( V_8 -> V_254 , L_13 ) ;
V_596 = F_246 ( V_8 , V_21 ) ;
if ( ! V_596 )
return;
F_260 ( V_8 , V_21 , V_32 , V_596 ) ;
V_32 -> V_543 -= V_596 ;
if ( F_268 ( V_594 ) )
if ( V_32 -> V_20 - V_32 -> V_543 >= V_597 + 1 )
F_269 ( V_594 ) ;
}
static unsigned int F_270 ( struct V_7 * V_8 , T_1 V_592 ,
int V_6 )
{
struct V_522 * V_21 ;
struct V_31 * V_32 ;
unsigned int V_598 = 0 ;
while ( V_592 ) {
V_21 = F_265 ( V_8 , V_592 ) ;
if ( ! V_21 )
break;
V_32 = F_241 ( V_21 -> V_553 , V_6 ) ;
if ( V_32 -> V_543 ) {
F_266 ( V_8 , V_21 , V_32 ) ;
V_598 += V_32 -> V_543 ;
}
V_592 &= ~ ( 1 << V_21 -> V_595 ) ;
}
return V_598 ;
}
static int F_271 ( struct V_251 * V_252 ,
struct V_522 * V_542 , int V_6 ,
struct V_1 * V_2 )
{
T_1 V_599 ;
V_542 -> V_524 = F_123 ( & V_252 -> V_254 ,
V_600 * V_601 ,
& V_542 -> V_602 , V_117 ) ;
if ( ! V_542 -> V_524 )
return - V_167 ;
V_542 -> V_555 = V_542 -> V_20 - 1 ;
V_542 -> V_537 = F_3 ( V_2 ,
F_272 ( V_6 ) ) ;
if ( V_2 -> V_11 == V_12 )
V_599 = V_542 -> V_602 ;
else
V_599 = V_542 -> V_602 >>
V_603 ;
F_1 ( V_2 , F_273 ( V_6 ) , V_599 ) ;
F_1 ( V_2 , F_274 ( V_6 ) ,
V_600 ) ;
return 0 ;
}
static int F_275 ( struct V_7 * V_8 ,
struct V_536 * V_381 )
{
T_1 V_604 ;
int V_6 ;
V_381 -> V_20 = V_8 -> V_605 ;
V_381 -> V_524 = F_123 ( V_8 -> V_254 -> V_254 . V_364 ,
V_381 -> V_20 * V_601 ,
& V_381 -> V_602 , V_117 ) ;
if ( ! V_381 -> V_524 )
return - V_167 ;
V_381 -> V_555 = V_381 -> V_20 - 1 ;
F_1 ( V_8 -> V_2 , F_227 ( V_381 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_574 , V_381 -> V_42 ) ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_604 = V_381 -> V_602 ;
else
V_604 = V_381 -> V_602 >> V_606 ;
F_5 ( V_8 -> V_2 , V_6 , V_607 , V_604 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_608 , V_381 -> V_20 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_609 , 0 ) ;
F_136 () ;
F_233 ( V_8 , V_381 -> V_42 , V_610 ) ;
F_251 ( V_8 , V_381 ) ;
F_256 ( V_8 , V_381 ) ;
F_228 ( V_8 , V_381 -> V_42 , 0 , V_381 -> V_20 ) ;
return 0 ;
}
static void F_276 ( struct V_7 * V_8 ,
struct V_536 * V_381 )
{
int V_611 , V_46 ;
V_611 = F_226 ( V_8 , V_381 -> V_42 ) ;
if ( ! V_611 )
return;
for ( V_46 = 0 ; V_46 < V_611 ; V_46 ++ ) {
struct V_25 * V_26 = F_230 ( V_381 ) ;
T_1 V_30 = F_19 ( V_8 , V_26 ) ;
int V_322 ;
V_322 = ( V_30 & V_612 ) >>
V_613 ;
F_155 ( V_8 , V_322 ,
F_16 ( V_8 , V_26 ) ,
F_17 ( V_8 , V_26 ) ) ;
}
F_228 ( V_8 , V_381 -> V_42 , V_611 , V_611 ) ;
}
static void F_277 ( struct V_7 * V_8 ,
struct V_536 * V_381 )
{
int V_6 ;
F_276 ( V_8 , V_381 ) ;
if ( V_381 -> V_524 )
F_124 ( V_8 -> V_254 -> V_254 . V_364 ,
V_381 -> V_20 * V_601 ,
V_381 -> V_524 ,
V_381 -> V_602 ) ;
V_381 -> V_524 = NULL ;
V_381 -> V_555 = 0 ;
V_381 -> V_537 = 0 ;
V_381 -> V_602 = 0 ;
F_1 ( V_8 -> V_2 , F_227 ( V_381 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_574 , V_381 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_607 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_608 , 0 ) ;
F_136 () ;
}
static int F_278 ( struct V_7 * V_8 ,
struct V_522 * V_21 )
{
T_1 V_18 ;
int V_6 , V_614 , V_615 , V_499 ;
struct V_31 * V_32 ;
V_21 -> V_20 = V_8 -> V_616 ;
V_21 -> V_524 = F_123 ( V_8 -> V_254 -> V_254 . V_364 ,
V_21 -> V_20 * V_601 ,
& V_21 -> V_602 , V_117 ) ;
if ( ! V_21 -> V_524 )
return - V_167 ;
V_21 -> V_555 = V_21 -> V_20 - 1 ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_579 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_617 ,
V_21 -> V_602 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_618 ,
V_21 -> V_20 & V_619 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_620 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_621 ,
V_21 -> V_42 << V_622 ) ;
V_18 = F_6 ( V_8 -> V_2 , V_6 , V_623 ) ;
V_18 &= ~ V_624 ;
F_5 ( V_8 -> V_2 , V_6 , V_623 , V_18 ) ;
V_615 = 16 ;
V_614 = ( V_8 -> V_42 * V_43 * V_615 ) +
( V_21 -> V_595 * V_615 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_625 ,
F_279 ( V_614 ) | V_626 |
F_280 ( V_615 / 2 ) ) ;
F_136 () ;
V_499 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_506 , V_499 ) ;
V_18 = F_3 ( V_8 -> V_2 , F_281 ( V_21 -> V_595 ) ) ;
V_18 &= ~ V_627 ;
V_18 |= F_282 ( 1 ) ;
V_18 |= V_628 ;
F_1 ( V_8 -> V_2 , F_281 ( V_21 -> V_595 ) , V_18 ) ;
V_18 = V_571 ;
F_1 ( V_8 -> V_2 , F_250 ( V_21 -> V_595 ) ,
V_18 ) ;
F_240 (cpu) {
V_32 = F_241 ( V_21 -> V_553 , V_6 ) ;
V_32 -> V_20 = V_21 -> V_20 ;
V_32 -> V_38 = F_283 ( V_32 -> V_20 ,
sizeof( * V_32 -> V_38 ) ,
V_117 ) ;
if ( ! V_32 -> V_38 )
goto V_629;
V_32 -> V_543 = 0 ;
V_32 -> V_551 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> V_33 = 0 ;
V_32 -> V_630 =
F_123 ( V_8 -> V_254 -> V_254 . V_364 ,
V_32 -> V_20 * V_631 ,
& V_32 -> V_632 ,
V_117 ) ;
if ( ! V_32 -> V_630 )
goto V_629;
}
return 0 ;
V_629:
F_240 (cpu) {
V_32 = F_241 ( V_21 -> V_553 , V_6 ) ;
F_57 ( V_32 -> V_38 ) ;
F_124 ( V_8 -> V_254 -> V_254 . V_364 ,
V_32 -> V_20 * V_631 ,
V_32 -> V_630 ,
V_32 -> V_632 ) ;
}
F_124 ( V_8 -> V_254 -> V_254 . V_364 ,
V_21 -> V_20 * V_601 ,
V_21 -> V_524 , V_21 -> V_602 ) ;
return - V_167 ;
}
static void F_284 ( struct V_7 * V_8 ,
struct V_522 * V_21 )
{
struct V_31 * V_32 ;
int V_6 ;
F_240 (cpu) {
V_32 = F_241 ( V_21 -> V_553 , V_6 ) ;
F_57 ( V_32 -> V_38 ) ;
F_124 ( V_8 -> V_254 -> V_254 . V_364 ,
V_32 -> V_20 * V_631 ,
V_32 -> V_630 ,
V_32 -> V_632 ) ;
}
if ( V_21 -> V_524 )
F_124 ( V_8 -> V_254 -> V_254 . V_364 ,
V_21 -> V_20 * V_601 ,
V_21 -> V_524 , V_21 -> V_602 ) ;
V_21 -> V_524 = NULL ;
V_21 -> V_555 = 0 ;
V_21 -> V_537 = 0 ;
V_21 -> V_602 = 0 ;
F_1 ( V_8 -> V_2 , F_216 ( V_21 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_579 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_617 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_618 , 0 ) ;
F_136 () ;
}
static void F_285 ( struct V_7 * V_8 , struct V_522 * V_21 )
{
struct V_31 * V_32 ;
int V_527 , V_540 , V_6 ;
T_1 V_18 ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_579 , V_21 -> V_42 ) ;
V_18 = F_6 ( V_8 -> V_2 , V_6 , V_625 ) ;
V_18 |= V_633 ;
F_5 ( V_8 -> V_2 , V_6 , V_625 , V_18 ) ;
V_527 = 0 ;
do {
if ( V_527 >= V_634 ) {
F_224 ( V_8 -> V_254 ,
L_14 ,
V_8 -> V_42 , V_21 -> V_595 ) ;
break;
}
F_225 ( 1 ) ;
V_527 ++ ;
V_540 = F_6 ( V_8 -> V_2 , V_6 ,
V_623 ) ;
V_540 &= V_624 ;
} while ( V_540 );
V_18 &= ~ V_633 ;
F_5 ( V_8 -> V_2 , V_6 , V_625 , V_18 ) ;
F_136 () ;
F_240 (cpu) {
V_32 = F_241 ( V_21 -> V_553 , V_6 ) ;
F_260 ( V_8 , V_21 , V_32 , V_32 -> V_543 ) ;
V_32 -> V_543 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> V_33 = 0 ;
}
}
static void F_286 ( struct V_7 * V_8 )
{
struct V_522 * V_21 ;
int V_500 ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_2 , V_635 ) ;
V_18 |= F_287 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_635 , V_18 ) ;
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
V_21 = V_8 -> V_523 [ V_500 ] ;
F_285 ( V_8 , V_21 ) ;
F_284 ( V_8 , V_21 ) ;
}
F_288 ( F_248 , V_8 , 1 ) ;
V_18 &= ~ F_287 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_635 , V_18 ) ;
}
static void F_289 ( struct V_7 * V_8 )
{
int V_500 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_383 ; V_500 ++ )
F_277 ( V_8 , V_8 -> V_355 [ V_500 ] ) ;
}
static int F_290 ( struct V_7 * V_8 )
{
int V_500 , V_253 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_383 ; V_500 ++ ) {
V_253 = F_275 ( V_8 , V_8 -> V_355 [ V_500 ] ) ;
if ( V_253 )
goto V_636;
}
return 0 ;
V_636:
F_289 ( V_8 ) ;
return V_253 ;
}
static int F_291 ( struct V_7 * V_8 )
{
struct V_522 * V_21 ;
int V_500 , V_253 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
V_21 = V_8 -> V_523 [ V_500 ] ;
V_253 = F_278 ( V_8 , V_21 ) ;
if ( V_253 )
goto V_636;
}
if ( V_8 -> V_398 ) {
F_258 ( V_8 ) ;
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
V_21 = V_8 -> V_523 [ V_500 ] ;
F_252 ( V_8 , V_21 ) ;
}
}
F_288 ( F_248 , V_8 , 1 ) ;
return 0 ;
V_636:
F_286 ( V_8 ) ;
return V_253 ;
}
static T_10 F_292 ( int V_637 , void * V_638 )
{
struct V_393 * V_639 = V_638 ;
F_175 ( V_639 ) ;
F_293 ( & V_639 -> V_640 ) ;
return V_641 ;
}
static T_10 F_294 ( int V_637 , void * V_638 )
{
struct V_7 * V_8 = (struct V_7 * ) V_638 ;
struct V_290 * V_254 = V_8 -> V_254 ;
bool V_642 = false , V_643 = false ;
T_1 V_18 ;
F_196 ( V_8 ) ;
if ( V_8 -> V_407 == 0 &&
V_8 -> V_423 == V_430 ) {
V_18 = F_4 ( V_8 -> V_436 + V_644 ) ;
if ( V_18 & V_645 ) {
V_642 = true ;
V_18 = F_4 ( V_8 -> V_436 + V_646 ) ;
if ( V_18 & V_647 )
V_643 = true ;
}
} else if ( F_195 ( V_8 -> V_423 ) ||
V_8 -> V_423 == V_429 ) {
V_18 = F_4 ( V_8 -> V_436 + V_648 ) ;
if ( V_18 & V_649 ) {
V_642 = true ;
V_18 = F_4 ( V_8 -> V_436 + V_650 ) ;
if ( V_18 & V_651 )
V_643 = true ;
}
}
if ( ! F_295 ( V_254 ) || ! V_642 )
goto V_652;
if ( V_643 ) {
F_169 ( V_8 ) ;
F_222 ( V_8 ) ;
F_220 ( V_8 ) ;
F_296 ( V_254 ) ;
F_297 ( V_254 ) ;
} else {
F_298 ( V_254 ) ;
F_299 ( V_254 ) ;
F_221 ( V_8 ) ;
F_223 ( V_8 ) ;
F_172 ( V_8 ) ;
}
V_652:
F_194 ( V_8 ) ;
return V_641 ;
}
static void F_300 ( struct V_7 * V_8 ,
struct V_653 * V_654 )
{
T_1 V_18 ;
if ( V_8 -> V_423 != V_424 &&
V_8 -> V_423 != V_425 &&
V_8 -> V_423 != V_426 &&
V_8 -> V_423 != V_427 &&
V_8 -> V_423 != V_429 )
return;
V_18 = F_4 ( V_8 -> V_436 + V_461 ) ;
V_18 &= ~ ( V_655 |
V_656 |
V_657 |
V_463 |
V_465 ) ;
if ( V_654 -> V_658 )
V_18 |= V_657 ;
if ( V_654 -> V_491 == V_659 )
V_18 |= V_656 ;
else if ( V_654 -> V_491 == V_660 )
V_18 |= V_655 ;
F_2 ( V_18 , V_8 -> V_436 + V_461 ) ;
}
static void F_301 ( struct V_290 * V_254 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_653 * V_654 = V_254 -> V_654 ;
bool V_661 = false ;
T_1 V_18 ;
if ( V_654 -> V_643 ) {
if ( V_8 -> V_423 != V_654 -> V_662 && V_8 -> V_448 ) {
F_172 ( V_8 ) ;
F_299 ( V_8 -> V_254 ) ;
F_208 ( V_8 ) ;
F_302 ( V_8 -> V_448 ) ;
V_8 -> V_423 = V_654 -> V_662 ;
F_198 ( V_8 ) ;
F_191 ( V_8 ) ;
F_205 ( V_8 ) ;
V_661 = true ;
}
if ( ( V_8 -> V_491 != V_654 -> V_491 ) ||
( V_8 -> V_658 != V_654 -> V_658 ) ) {
F_300 ( V_8 , V_654 ) ;
V_8 -> V_658 = V_654 -> V_658 ;
V_8 -> V_491 = V_654 -> V_491 ;
}
}
if ( V_654 -> V_643 != V_8 -> V_643 || V_661 ) {
V_8 -> V_643 = V_654 -> V_643 ;
if ( V_654 -> V_643 ) {
if ( V_8 -> V_423 == V_424 ||
V_8 -> V_423 == V_425 ||
V_8 -> V_423 == V_426 ||
V_8 -> V_423 == V_427 ||
V_8 -> V_423 == V_429 ) {
V_18 = F_4 ( V_8 -> V_436 + V_461 ) ;
V_18 |= ( V_467 |
V_468 ) ;
F_2 ( V_18 , V_8 -> V_436 + V_461 ) ;
}
F_169 ( V_8 ) ;
F_207 ( V_8 ) ;
F_222 ( V_8 ) ;
F_220 ( V_8 ) ;
F_296 ( V_254 ) ;
F_297 ( V_254 ) ;
} else {
V_8 -> V_658 = - 1 ;
V_8 -> V_491 = 0 ;
F_298 ( V_254 ) ;
F_299 ( V_254 ) ;
F_221 ( V_8 ) ;
F_223 ( V_8 ) ;
F_208 ( V_8 ) ;
F_172 ( V_8 ) ;
}
F_303 ( V_654 ) ;
}
}
static void F_304 ( struct V_663 * V_664 )
{
T_11 V_665 ;
if ( ! V_664 -> V_666 ) {
V_664 -> V_666 = true ;
V_665 = V_667 ;
F_305 ( & V_664 -> V_668 , V_665 ,
V_669 ) ;
}
}
static void F_306 ( unsigned long V_4 )
{
struct V_290 * V_254 = (struct V_290 * ) V_4 ;
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_663 * V_664 = F_307 ( V_8 -> V_553 ) ;
unsigned int V_598 , V_592 ;
if ( ! F_295 ( V_254 ) )
return;
V_664 -> V_666 = false ;
V_592 = ( 1 << V_8 -> V_521 ) - 1 ;
V_598 = F_270 ( V_8 , V_592 , F_177 () ) ;
if ( V_598 )
F_304 ( V_664 ) ;
}
static enum V_670 F_308 ( struct V_671 * V_672 )
{
struct V_663 * V_664 = F_309 ( V_672 ,
struct V_663 ,
V_668 ) ;
F_310 ( & V_664 -> V_673 ) ;
return V_674 ;
}
static void F_311 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
T_1 V_30 = F_19 ( V_8 , V_26 ) ;
T_4 V_675 = F_18 ( V_8 , V_26 ) ;
switch ( V_30 & V_676 ) {
case V_677 :
F_160 ( V_8 -> V_254 , L_15 ,
V_30 , V_675 ) ;
break;
case V_678 :
F_160 ( V_8 -> V_254 , L_16 ,
V_30 , V_675 ) ;
break;
case V_679 :
F_160 ( V_8 -> V_254 , L_17 ,
V_30 , V_675 ) ;
break;
}
}
static void F_312 ( struct V_7 * V_8 , T_1 V_30 ,
struct V_34 * V_35 )
{
if ( ( ( V_30 & V_680 ) &&
! ( V_30 & V_681 ) ) ||
( V_30 & V_682 ) )
if ( ( ( V_30 & V_683 ) ||
( V_30 & V_684 ) ) &&
( V_30 & V_685 ) ) {
V_35 -> V_686 = 0 ;
V_35 -> V_687 = V_688 ;
return;
}
V_35 -> V_687 = V_689 ;
}
static int F_313 ( struct V_7 * V_8 ,
struct V_321 * V_325 , int V_322 )
{
T_2 V_17 ;
T_7 V_336 ;
void * V_371 ;
V_371 = F_149 ( V_8 , V_325 , & V_17 , & V_336 ,
V_283 ) ;
if ( ! V_371 )
return - V_167 ;
F_155 ( V_8 , V_322 , V_17 , V_336 ) ;
return 0 ;
}
static T_1 F_314 ( struct V_7 * V_8 , struct V_34 * V_35 )
{
if ( V_35 -> V_687 == V_690 ) {
int V_558 = 0 ;
T_6 V_559 ;
if ( V_35 -> V_691 == F_315 ( V_239 ) ) {
struct V_183 * V_692 = F_316 ( V_35 ) ;
V_558 = V_692 -> V_693 ;
V_559 = V_692 -> V_691 ;
} else if ( V_35 -> V_691 == F_315 ( V_246 ) ) {
struct V_203 * V_694 = F_317 ( V_35 ) ;
if ( F_318 ( V_35 ) > 0 )
V_558 = ( F_318 ( V_35 ) >> 2 ) ;
V_559 = V_694 -> V_695 ;
} else {
return V_566 ;
}
return F_245 ( F_319 ( V_35 ) ,
V_35 -> V_691 , V_558 , V_559 ) ;
}
return V_566 | V_562 ;
}
static int F_320 ( struct V_7 * V_8 , struct V_696 * V_640 ,
int V_697 , struct V_536 * V_381 )
{
struct V_290 * V_254 = V_8 -> V_254 ;
int V_611 ;
int V_698 = 0 ;
T_1 V_699 = 0 ;
T_1 V_700 = 0 ;
V_611 = F_226 ( V_8 , V_381 -> V_42 ) ;
if ( V_697 > V_611 )
V_697 = V_611 ;
while ( V_698 < V_697 ) {
struct V_25 * V_26 = F_230 ( V_381 ) ;
struct V_321 * V_325 ;
struct V_34 * V_35 ;
unsigned int V_323 ;
T_2 V_17 ;
T_7 V_336 ;
T_1 V_701 ;
int V_322 , V_702 , V_253 ;
void * V_4 ;
V_698 ++ ;
V_701 = F_19 ( V_8 , V_26 ) ;
V_702 = F_18 ( V_8 , V_26 ) ;
V_702 -= V_215 ;
V_17 = F_16 ( V_8 , V_26 ) ;
V_336 = F_17 ( V_8 , V_26 ) ;
V_4 = ( void * ) F_139 ( V_336 ) ;
V_322 = ( V_701 & V_612 ) >>
V_613 ;
V_325 = & V_8 -> V_2 -> V_350 [ V_322 ] ;
if ( V_701 & V_703 ) {
V_704:
V_254 -> V_705 . V_706 ++ ;
F_311 ( V_8 , V_26 ) ;
F_155 ( V_8 , V_322 , V_17 , V_336 ) ;
continue;
}
if ( V_325 -> V_323 > V_324 )
V_323 = 0 ;
else
V_323 = V_325 -> V_323 ;
V_35 = F_321 ( V_4 , V_323 ) ;
if ( ! V_35 ) {
F_224 ( V_8 -> V_254 , L_18 ) ;
goto V_704;
}
V_253 = F_313 ( V_8 , V_325 , V_322 ) ;
if ( V_253 ) {
F_160 ( V_8 -> V_254 , L_19 ) ;
goto V_704;
}
F_138 ( V_254 -> V_254 . V_364 , V_17 ,
V_325 -> V_333 , V_346 ) ;
V_699 ++ ;
V_700 += V_702 ;
F_322 ( V_35 , V_215 + V_610 ) ;
F_323 ( V_35 , V_702 ) ;
V_35 -> V_691 = F_324 ( V_35 , V_254 ) ;
F_312 ( V_8 , V_701 , V_35 ) ;
F_325 ( V_640 , V_35 ) ;
}
if ( V_699 ) {
struct V_707 * V_705 = F_307 ( V_8 -> V_705 ) ;
F_326 ( & V_705 -> V_708 ) ;
V_705 -> V_709 += V_699 ;
V_705 -> V_702 += V_700 ;
F_327 ( & V_705 -> V_708 ) ;
}
F_328 () ;
F_228 ( V_8 , V_381 -> V_42 , V_698 , V_698 ) ;
return V_697 ;
}
static inline void
F_329 ( struct V_7 * V_8 , struct V_522 * V_21 ,
struct V_9 * V_614 )
{
struct V_31 * V_32 = F_307 ( V_21 -> V_553 ) ;
T_2 V_14 =
F_7 ( V_8 , V_614 ) ;
T_4 V_710 =
F_10 ( V_8 , V_614 ) ;
if ( ! F_261 ( V_32 , V_14 ) )
F_138 ( V_8 -> V_254 -> V_254 . V_364 , V_14 ,
V_710 , V_591 ) ;
F_244 ( V_21 ) ;
}
static int F_330 ( struct V_7 * V_8 , struct V_34 * V_35 ,
struct V_522 * V_542 ,
struct V_522 * V_21 )
{
struct V_31 * V_32 = F_307 ( V_21 -> V_553 ) ;
struct V_9 * V_10 ;
int V_46 ;
T_2 V_14 ;
for ( V_46 = 0 ; V_46 < F_331 ( V_35 ) -> V_711 ; V_46 ++ ) {
T_12 * V_712 = & F_331 ( V_35 ) -> V_713 [ V_46 ] ;
void * V_714 = F_332 ( V_712 -> V_715 . V_716 ) + V_712 -> V_717 ;
V_10 = F_234 ( V_542 ) ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , V_712 -> V_20 ) ;
V_14 = F_150 ( V_8 -> V_254 -> V_254 . V_364 , V_714 ,
V_712 -> V_20 ,
V_591 ) ;
if ( F_153 ( V_8 -> V_254 -> V_254 . V_364 , V_14 ) ) {
F_244 ( V_21 ) ;
goto V_629;
}
F_14 ( V_8 , V_10 ,
V_14 & V_718 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_718 ) ;
if ( V_46 == ( F_331 ( V_35 ) -> V_711 - 1 ) ) {
F_13 ( V_8 , V_10 ,
V_719 ) ;
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
} else {
F_13 ( V_8 , V_10 , 0 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
}
}
return 0 ;
V_629:
for ( V_46 = V_46 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_10 = V_21 -> V_524 + V_46 ;
F_329 ( V_8 , V_21 , V_10 ) ;
}
return - V_167 ;
}
static inline void F_333 ( struct V_34 * V_35 ,
struct V_290 * V_254 ,
struct V_522 * V_21 ,
struct V_522 * V_542 ,
struct V_31 * V_32 ,
int V_720 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_9 * V_10 = F_234 ( V_542 ) ;
T_2 V_714 ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , V_720 ) ;
V_714 = V_32 -> V_632 +
V_32 -> V_39 * V_631 ;
F_14 ( V_8 , V_10 , V_714 & V_718 ) ;
F_9 ( V_8 , V_10 , V_714 & ~ V_718 ) ;
F_13 ( V_8 , V_10 , F_314 ( V_8 , V_35 ) |
V_721 |
V_722 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
}
static inline int F_334 ( struct V_34 * V_35 ,
struct V_290 * V_254 , struct V_723 * V_724 ,
struct V_522 * V_21 ,
struct V_522 * V_542 ,
struct V_31 * V_32 ,
int V_675 , bool V_725 , bool V_726 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_9 * V_10 = F_234 ( V_542 ) ;
T_2 V_14 ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , V_675 ) ;
V_14 = F_150 ( V_254 -> V_254 . V_364 , V_724 -> V_4 , V_675 ,
V_591 ) ;
if ( F_152 ( F_153 ( V_254 -> V_254 . V_364 , V_14 ) ) ) {
F_244 ( V_21 ) ;
return - V_167 ;
}
F_14 ( V_8 , V_10 ,
V_14 & V_718 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_718 ) ;
if ( ! V_725 ) {
F_13 ( V_8 , V_10 , V_719 ) ;
if ( V_726 ) {
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
return 0 ;
}
} else {
F_13 ( V_8 , V_10 , 0 ) ;
}
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
return 0 ;
}
static int F_335 ( struct V_34 * V_35 , struct V_290 * V_254 ,
struct V_522 * V_21 ,
struct V_522 * V_542 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_723 V_724 ;
int V_720 = F_336 ( V_35 ) + F_337 ( V_35 ) ;
int V_46 , V_285 , V_524 = 0 ;
if ( F_236 ( V_8 -> V_2 , V_542 ,
F_338 ( V_35 ) ) ||
F_239 ( V_8 -> V_2 , V_21 , V_32 ,
F_338 ( V_35 ) ) )
return 0 ;
F_339 ( V_35 , & V_724 ) ;
V_285 = V_35 -> V_285 - V_720 ;
while ( V_285 > 0 ) {
int V_725 = F_340 ( int , F_331 ( V_35 ) -> V_727 , V_285 ) ;
char * V_728 = V_32 -> V_630 +
V_32 -> V_39 * V_631 ;
V_285 -= V_725 ;
V_524 ++ ;
F_341 ( V_35 , V_728 , & V_724 , V_725 , V_285 == 0 ) ;
F_333 ( V_35 , V_254 , V_21 , V_542 , V_32 , V_720 ) ;
while ( V_725 > 0 ) {
int V_675 = F_340 ( int , V_724 . V_20 , V_725 ) ;
V_725 -= V_675 ;
V_524 ++ ;
if ( F_334 ( V_35 , V_254 , & V_724 , V_21 , V_542 ,
V_32 , V_675 , V_725 , V_285 == 0 ) )
goto V_729;
F_342 ( V_35 , & V_724 , V_675 ) ;
}
}
return V_524 ;
V_729:
for ( V_46 = V_524 - 1 ; V_46 >= 0 ; V_46 -- ) {
struct V_9 * V_10 = V_21 -> V_524 + V_46 ;
F_329 ( V_8 , V_21 , V_10 ) ;
}
return 0 ;
}
static int F_343 ( struct V_34 * V_35 , struct V_290 * V_254 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_522 * V_21 , * V_542 ;
struct V_31 * V_32 ;
struct V_9 * V_10 ;
T_2 V_14 ;
int V_713 = 0 ;
T_5 V_730 ;
T_1 V_731 ;
V_730 = F_344 ( V_35 ) ;
V_21 = V_8 -> V_523 [ V_730 ] ;
V_32 = F_307 ( V_21 -> V_553 ) ;
V_542 = & V_8 -> V_2 -> V_732 [ F_177 () ] ;
if ( F_345 ( V_35 ) ) {
V_713 = F_335 ( V_35 , V_254 , V_21 , V_542 , V_32 ) ;
goto V_733;
}
V_713 = F_331 ( V_35 ) -> V_711 + 1 ;
if ( F_236 ( V_8 -> V_2 , V_542 , V_713 ) ||
F_239 ( V_8 -> V_2 , V_21 ,
V_32 , V_713 ) ) {
V_713 = 0 ;
goto V_733;
}
V_10 = F_234 ( V_542 ) ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , F_346 ( V_35 ) ) ;
V_14 = F_150 ( V_254 -> V_254 . V_364 , V_35 -> V_4 ,
F_346 ( V_35 ) , V_591 ) ;
if ( F_152 ( F_153 ( V_254 -> V_254 . V_364 , V_14 ) ) ) {
F_244 ( V_21 ) ;
V_713 = 0 ;
goto V_733;
}
F_14 ( V_8 , V_10 ,
V_14 & V_718 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_718 ) ;
V_731 = F_314 ( V_8 , V_35 ) ;
if ( V_713 == 1 ) {
V_731 |= V_721 | V_719 ;
F_13 ( V_8 , V_10 , V_731 ) ;
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
} else {
V_731 |= V_721 | V_722 ;
F_13 ( V_8 , V_10 , V_731 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
if ( F_330 ( V_8 , V_35 , V_542 , V_21 ) ) {
F_329 ( V_8 , V_21 , V_10 ) ;
V_713 = 0 ;
goto V_733;
}
}
V_733:
if ( V_713 > 0 ) {
struct V_707 * V_705 = F_307 ( V_8 -> V_705 ) ;
struct V_593 * V_594 = F_267 ( V_254 , V_730 ) ;
V_32 -> V_551 -= V_713 ;
V_32 -> V_543 += V_713 ;
V_542 -> V_543 += V_713 ;
F_328 () ;
F_235 ( V_8 , V_713 ) ;
if ( V_32 -> V_20 - V_32 -> V_543 < V_597 + 1 )
F_347 ( V_594 ) ;
F_326 ( & V_705 -> V_708 ) ;
V_705 -> V_734 ++ ;
V_705 -> V_735 += V_35 -> V_285 ;
F_327 ( & V_705 -> V_708 ) ;
} else {
V_254 -> V_705 . V_736 ++ ;
F_262 ( V_35 ) ;
}
if ( ! V_8 -> V_398 && V_32 -> V_543 >= V_21 -> V_576 )
F_266 ( V_8 , V_21 , V_32 ) ;
if ( ! V_8 -> V_398 && V_32 -> V_543 <= V_713 &&
V_32 -> V_543 > 0 ) {
struct V_663 * V_664 = F_307 ( V_8 -> V_553 ) ;
F_304 ( V_664 ) ;
}
return V_737 ;
}
static inline void F_348 ( struct V_290 * V_254 , int V_592 )
{
if ( V_592 & V_738 )
F_160 ( V_254 , L_20 ) ;
if ( V_592 & V_739 )
F_160 ( V_254 , L_21 ) ;
if ( V_592 & V_740 )
F_160 ( V_254 , L_22 ) ;
}
static int F_349 ( struct V_696 * V_640 , int V_741 )
{
T_1 V_742 , V_743 , V_744 , V_745 ;
int V_698 = 0 ;
struct V_7 * V_8 = F_101 ( V_640 -> V_254 ) ;
struct V_393 * V_639 ;
int V_6 = F_177 () ;
V_639 = F_309 ( V_640 , struct V_393 , V_640 ) ;
V_742 = F_6 ( V_8 -> V_2 , V_639 -> V_402 ,
F_350 ( V_8 -> V_42 ) ) ;
V_745 = V_742 & V_396 ;
if ( V_745 ) {
F_348 ( V_8 -> V_254 , V_745 ) ;
F_1 ( V_8 -> V_2 , V_746 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 ,
F_350 ( V_8 -> V_42 ) ,
V_742 & ~ V_396 ) ;
}
V_744 = V_742 & V_399 ;
if ( V_744 ) {
V_744 >>= V_747 ;
F_270 ( V_8 , V_744 , V_639 -> V_402 ) ;
}
V_743 = V_742 & V_397 ;
V_743 <<= V_639 -> V_316 ;
V_743 |= V_639 -> V_748 ;
while ( V_743 && V_741 > 0 ) {
int V_543 ;
struct V_536 * V_381 ;
V_381 = F_263 ( V_8 , V_743 ) ;
if ( ! V_381 )
break;
V_543 = F_320 ( V_8 , V_640 , V_741 , V_381 ) ;
V_698 += V_543 ;
V_741 -= V_543 ;
if ( V_741 > 0 ) {
V_743 &= ~ ( 1 << V_381 -> V_749 ) ;
}
}
if ( V_741 > 0 ) {
V_743 = 0 ;
F_351 ( V_640 , V_698 ) ;
F_174 ( V_639 ) ;
}
V_639 -> V_748 = V_743 ;
return V_698 ;
}
static void F_352 ( struct V_7 * V_8 )
{
struct V_290 * V_750 = V_8 -> V_254 ;
int V_46 ;
if ( V_8 -> V_407 == 0 &&
( V_8 -> V_423 == V_480 ||
V_8 -> V_423 == V_430 ) )
F_213 ( V_8 ) ;
else
F_212 ( V_8 ) ;
F_249 ( V_8 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ )
F_353 ( & V_8 -> V_392 [ V_46 ] . V_640 ) ;
F_169 ( V_8 ) ;
if ( V_8 -> V_2 -> V_11 == V_338 ) {
F_198 ( V_8 ) ;
F_191 ( V_8 ) ;
}
F_205 ( V_8 ) ;
F_207 ( V_8 ) ;
if ( V_750 -> V_654 )
F_354 ( V_750 -> V_654 ) ;
F_355 ( V_8 -> V_254 ) ;
}
static void F_356 ( struct V_7 * V_8 )
{
struct V_290 * V_750 = V_8 -> V_254 ;
int V_46 ;
F_221 ( V_8 ) ;
F_225 ( 10 ) ;
F_172 ( V_8 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ )
F_357 ( & V_8 -> V_392 [ V_46 ] . V_640 ) ;
F_299 ( V_8 -> V_254 ) ;
F_298 ( V_8 -> V_254 ) ;
F_223 ( V_8 ) ;
F_208 ( V_8 ) ;
if ( V_750 -> V_654 )
F_358 ( V_750 -> V_654 ) ;
F_302 ( V_8 -> V_448 ) ;
}
static int F_359 ( struct V_290 * V_254 ,
struct V_751 * V_752 )
{
T_5 V_753 = V_752 -> V_754 ;
T_5 V_755 = V_752 -> V_756 ;
if ( V_752 -> V_754 == 0 || V_752 -> V_756 == 0 )
return - V_49 ;
if ( V_752 -> V_754 > V_757 )
V_753 = V_757 ;
else if ( ! F_122 ( V_752 -> V_754 , 16 ) )
V_753 = F_131 ( V_752 -> V_754 , 16 ) ;
if ( V_752 -> V_756 > V_758 )
V_755 = V_758 ;
else if ( ! F_122 ( V_752 -> V_756 , 32 ) )
V_755 = F_131 ( V_752 -> V_756 , 32 ) ;
if ( V_752 -> V_754 != V_753 ) {
F_360 ( V_254 , L_23 ,
V_752 -> V_754 , V_753 ) ;
V_752 -> V_754 = V_753 ;
}
if ( V_752 -> V_756 != V_755 ) {
F_360 ( V_254 , L_24 ,
V_752 -> V_756 , V_755 ) ;
V_752 -> V_756 = V_755 ;
}
return 0 ;
}
static void F_361 ( struct V_7 * V_8 , unsigned char * V_714 )
{
T_1 V_759 , V_760 , V_761 ;
V_759 = F_4 ( V_8 -> V_436 + V_489 ) ;
V_760 = F_4 ( V_8 -> V_2 -> V_762 + V_763 ) ;
V_761 = F_4 ( V_8 -> V_2 -> V_762 + V_764 ) ;
V_714 [ 0 ] = ( V_761 >> 24 ) & 0xFF ;
V_714 [ 1 ] = ( V_761 >> 16 ) & 0xFF ;
V_714 [ 2 ] = ( V_761 >> 8 ) & 0xFF ;
V_714 [ 3 ] = V_761 & 0xFF ;
V_714 [ 4 ] = V_760 & 0xFF ;
V_714 [ 5 ] = ( V_759 >> V_765 ) & 0xFF ;
}
static int F_362 ( struct V_7 * V_8 )
{
struct V_653 * V_766 ;
if ( ! V_8 -> V_767 )
return 0 ;
V_766 = F_363 ( V_8 -> V_254 , V_8 -> V_767 , F_301 , 0 ,
V_8 -> V_423 ) ;
if ( ! V_766 ) {
F_160 ( V_8 -> V_254 , L_25 ) ;
return - V_768 ;
}
V_766 -> V_769 &= V_770 ;
V_766 -> V_771 = V_766 -> V_769 ;
V_8 -> V_643 = 0 ;
V_8 -> V_658 = 0 ;
V_8 -> V_491 = 0 ;
return 0 ;
}
static void F_364 ( struct V_7 * V_8 )
{
struct V_290 * V_750 = V_8 -> V_254 ;
if ( ! V_750 -> V_654 )
return;
F_365 ( V_750 -> V_654 ) ;
}
static int F_366 ( struct V_7 * V_8 )
{
int V_253 , V_46 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ ) {
struct V_393 * V_639 = V_8 -> V_392 + V_46 ;
if ( V_639 -> type == V_772 )
F_367 ( V_639 -> V_637 , V_773 ) ;
V_253 = F_368 ( V_639 -> V_637 , F_292 , 0 , V_8 -> V_254 -> V_774 , V_639 ) ;
if ( V_253 )
goto V_253;
if ( V_639 -> type == V_772 )
F_369 ( V_639 -> V_637 ,
F_370 ( V_639 -> V_402 ) ) ;
}
return 0 ;
V_253:
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ ) {
struct V_393 * V_639 = V_8 -> V_392 + V_46 ;
F_369 ( V_639 -> V_637 , NULL ) ;
F_371 ( V_639 -> V_637 , V_639 ) ;
}
return V_253 ;
}
static void F_372 ( struct V_7 * V_8 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ ) {
struct V_393 * V_639 = V_8 -> V_392 + V_46 ;
F_369 ( V_639 -> V_637 , NULL ) ;
F_373 ( V_639 -> V_637 , V_773 ) ;
F_371 ( V_639 -> V_637 , V_639 ) ;
}
}
static int F_374 ( struct V_290 * V_254 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned char V_775 [ V_130 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_253 ;
V_253 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_775 , true ) ;
if ( V_253 ) {
F_160 ( V_254 , L_26 ) ;
return V_253 ;
}
V_253 = F_97 ( V_8 -> V_2 , V_8 -> V_42 ,
V_254 -> V_291 , true ) ;
if ( V_253 ) {
F_160 ( V_254 , L_27 ) ;
return V_253 ;
}
V_253 = F_104 ( V_8 -> V_2 , V_8 -> V_42 , V_295 ) ;
if ( V_253 ) {
F_160 ( V_254 , L_28 ) ;
return V_253 ;
}
V_253 = F_105 ( V_8 ) ;
if ( V_253 ) {
F_160 ( V_254 , L_29 ) ;
return V_253 ;
}
V_253 = F_290 ( V_8 ) ;
if ( V_253 ) {
F_160 ( V_8 -> V_254 , L_30 ) ;
return V_253 ;
}
V_253 = F_291 ( V_8 ) ;
if ( V_253 ) {
F_160 ( V_8 -> V_254 , L_31 ) ;
goto V_776;
}
V_253 = F_366 ( V_8 ) ;
if ( V_253 ) {
F_160 ( V_8 -> V_254 , L_32 ) ;
goto V_777;
}
if ( V_2 -> V_11 == V_338 && ! V_8 -> V_767 && V_8 -> V_778 ) {
V_253 = F_368 ( V_8 -> V_778 , F_294 , 0 ,
V_254 -> V_774 , V_8 ) ;
if ( V_253 ) {
F_160 ( V_8 -> V_254 , L_33 ,
V_8 -> V_778 ) ;
goto V_779;
}
F_197 ( V_8 ) ;
}
F_299 ( V_8 -> V_254 ) ;
V_253 = F_362 ( V_8 ) ;
if ( V_253 < 0 )
goto V_780;
F_288 ( F_179 , V_8 , 1 ) ;
F_180 ( V_8 , false ) ;
F_352 ( V_8 ) ;
return 0 ;
V_780:
if ( V_2 -> V_11 == V_338 && ! V_8 -> V_767 && V_8 -> V_778 )
F_371 ( V_8 -> V_778 , V_8 ) ;
V_779:
F_372 ( V_8 ) ;
V_777:
F_286 ( V_8 ) ;
V_776:
F_289 ( V_8 ) ;
return V_253 ;
}
static int F_375 ( struct V_290 * V_254 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_663 * V_664 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_6 ;
F_356 ( V_8 ) ;
F_364 ( V_8 ) ;
F_288 ( F_176 , V_8 , 1 ) ;
F_180 ( V_8 , true ) ;
if ( V_2 -> V_11 == V_338 && ! V_8 -> V_767 && V_8 -> V_778 )
F_371 ( V_8 -> V_778 , V_8 ) ;
F_372 ( V_8 ) ;
if ( ! V_8 -> V_398 ) {
F_240 (cpu) {
V_664 = F_241 ( V_8 -> V_553 , V_6 ) ;
F_376 ( & V_664 -> V_668 ) ;
V_664 -> V_666 = false ;
F_377 ( & V_664 -> V_673 ) ;
}
}
F_289 ( V_8 ) ;
F_286 ( V_8 ) ;
return 0 ;
}
static void F_378 ( struct V_290 * V_254 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_781 * V_782 ;
int V_42 = V_8 -> V_42 ;
bool V_783 = V_254 -> V_502 & V_784 ;
F_61 ( V_2 , V_42 , V_254 -> V_502 & V_785 ) ;
F_62 ( V_2 , V_42 , V_133 , V_783 ) ;
F_62 ( V_2 , V_42 , V_217 , V_783 ) ;
F_103 ( V_2 , V_42 ) ;
if ( V_783 && ! F_379 ( V_254 ) ) {
F_380 (ha, dev)
F_97 ( V_2 , V_42 , V_782 -> V_714 , true ) ;
}
}
static int F_381 ( struct V_290 * V_254 , void * V_716 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
const struct V_786 * V_714 = V_716 ;
int V_253 ;
if ( ! F_382 ( V_714 -> V_787 ) ) {
V_253 = - V_788 ;
goto V_789;
}
if ( ! F_295 ( V_254 ) ) {
V_253 = F_100 ( V_254 , V_714 -> V_787 ) ;
if ( ! V_253 )
return 0 ;
V_253 = F_100 ( V_254 , V_254 -> V_291 ) ;
if ( V_253 )
goto V_789;
}
F_356 ( V_8 ) ;
V_253 = F_100 ( V_254 , V_714 -> V_787 ) ;
if ( ! V_253 )
goto V_790;
V_253 = F_100 ( V_254 , V_254 -> V_291 ) ;
if ( V_253 )
goto V_789;
V_790:
F_352 ( V_8 ) ;
F_222 ( V_8 ) ;
F_220 ( V_8 ) ;
return 0 ;
V_789:
F_160 ( V_254 , L_34 ) ;
return V_253 ;
}
static int F_383 ( struct V_290 * V_254 , int V_387 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
int V_253 ;
if ( ! F_122 ( F_167 ( V_387 ) , 8 ) ) {
F_360 ( V_254 , L_35 , V_387 ,
F_131 ( F_167 ( V_387 ) , 8 ) ) ;
V_387 = F_131 ( F_167 ( V_387 ) , 8 ) ;
}
if ( ! F_295 ( V_254 ) ) {
V_253 = F_166 ( V_254 , V_387 ) ;
if ( ! V_253 ) {
V_8 -> V_331 = F_167 ( V_387 ) ;
return 0 ;
}
V_253 = F_166 ( V_254 , V_254 -> V_387 ) ;
if ( V_253 )
goto V_789;
}
F_356 ( V_8 ) ;
V_253 = F_166 ( V_254 , V_387 ) ;
if ( ! V_253 ) {
V_8 -> V_331 = F_167 ( V_387 ) ;
goto V_790;
}
V_253 = F_166 ( V_254 , V_254 -> V_387 ) ;
if ( V_253 )
goto V_789;
V_790:
F_352 ( V_8 ) ;
F_222 ( V_8 ) ;
F_220 ( V_8 ) ;
return 0 ;
V_789:
F_160 ( V_254 , L_36 ) ;
return V_253 ;
}
static void
F_384 ( struct V_290 * V_254 , struct V_791 * V_705 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
unsigned int V_120 ;
int V_6 ;
F_385 (cpu) {
struct V_707 * V_792 ;
T_3 V_709 ;
T_3 V_702 ;
T_3 V_734 ;
T_3 V_735 ;
V_792 = F_241 ( V_8 -> V_705 , V_6 ) ;
do {
V_120 = F_386 ( & V_792 -> V_708 ) ;
V_709 = V_792 -> V_709 ;
V_702 = V_792 -> V_702 ;
V_734 = V_792 -> V_734 ;
V_735 = V_792 -> V_735 ;
} while ( F_387 ( & V_792 -> V_708 , V_120 ) );
V_705 -> V_709 += V_709 ;
V_705 -> V_702 += V_702 ;
V_705 -> V_734 += V_734 ;
V_705 -> V_735 += V_735 ;
}
V_705 -> V_706 = V_254 -> V_705 . V_706 ;
V_705 -> V_793 = V_254 -> V_705 . V_793 ;
V_705 -> V_736 = V_254 -> V_705 . V_736 ;
}
static int F_388 ( struct V_290 * V_254 , struct V_794 * V_795 , int V_796 )
{
int V_166 ;
if ( ! V_254 -> V_654 )
return - V_797 ;
V_166 = F_389 ( V_254 -> V_654 , V_795 , V_796 ) ;
if ( ! V_166 )
F_301 ( V_254 ) ;
return V_166 ;
}
static int F_390 ( struct V_290 * V_254 ,
struct V_798 * V_799 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
int V_500 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_383 ; V_500 ++ ) {
struct V_536 * V_381 = V_8 -> V_355 [ V_500 ] ;
V_381 -> V_587 = V_799 -> V_800 ;
V_381 -> V_572 = V_799 -> V_801 ;
F_251 ( V_8 , V_381 ) ;
F_256 ( V_8 , V_381 ) ;
}
if ( V_8 -> V_398 ) {
V_8 -> V_589 = V_799 -> V_802 ;
F_258 ( V_8 ) ;
}
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
struct V_522 * V_21 = V_8 -> V_523 [ V_500 ] ;
V_21 -> V_576 = V_799 -> V_803 ;
if ( V_8 -> V_398 )
F_252 ( V_8 , V_21 ) ;
}
return 0 ;
}
static int F_391 ( struct V_290 * V_254 ,
struct V_798 * V_799 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
V_799 -> V_800 = V_8 -> V_355 [ 0 ] -> V_587 ;
V_799 -> V_801 = V_8 -> V_355 [ 0 ] -> V_572 ;
V_799 -> V_803 = V_8 -> V_523 [ 0 ] -> V_576 ;
return 0 ;
}
static void F_392 ( struct V_290 * V_254 ,
struct V_804 * V_805 )
{
F_393 ( V_805 -> V_806 , V_807 ,
sizeof( V_805 -> V_806 ) ) ;
F_393 ( V_805 -> V_808 , V_809 ,
sizeof( V_805 -> V_808 ) ) ;
F_393 ( V_805 -> V_810 , F_394 ( & V_254 -> V_254 ) ,
sizeof( V_805 -> V_810 ) ) ;
}
static void F_395 ( struct V_290 * V_254 ,
struct V_751 * V_752 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
V_752 -> V_811 = V_757 ;
V_752 -> V_812 = V_758 ;
V_752 -> V_754 = V_8 -> V_605 ;
V_752 -> V_756 = V_8 -> V_616 ;
}
static int F_396 ( struct V_290 * V_254 ,
struct V_751 * V_752 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
T_5 V_813 = V_8 -> V_605 ;
T_5 V_814 = V_8 -> V_616 ;
int V_253 ;
V_253 = F_359 ( V_254 , V_752 ) ;
if ( V_253 )
return V_253 ;
if ( ! F_295 ( V_254 ) ) {
V_8 -> V_605 = V_752 -> V_754 ;
V_8 -> V_616 = V_752 -> V_756 ;
return 0 ;
}
F_356 ( V_8 ) ;
F_289 ( V_8 ) ;
F_286 ( V_8 ) ;
V_8 -> V_605 = V_752 -> V_754 ;
V_8 -> V_616 = V_752 -> V_756 ;
V_253 = F_290 ( V_8 ) ;
if ( V_253 ) {
V_8 -> V_605 = V_813 ;
V_752 -> V_754 = V_813 ;
V_253 = F_290 ( V_8 ) ;
if ( V_253 )
goto V_815;
}
V_253 = F_291 ( V_8 ) ;
if ( V_253 ) {
V_8 -> V_616 = V_814 ;
V_752 -> V_756 = V_814 ;
V_253 = F_291 ( V_8 ) ;
if ( V_253 )
goto V_816;
}
F_352 ( V_8 ) ;
F_222 ( V_8 ) ;
F_220 ( V_8 ) ;
return 0 ;
V_816:
F_289 ( V_8 ) ;
V_815:
F_160 ( V_254 , L_37 ) ;
return V_253 ;
}
static int F_397 ( struct V_7 * V_8 ,
struct V_817 * V_818 )
{
struct V_393 * V_400 = & V_8 -> V_392 [ 0 ] ;
V_400 -> V_316 = 0 ;
V_400 -> V_383 = V_8 -> V_383 ;
V_400 -> type = V_401 ;
V_400 -> V_402 = 0 ;
V_400 -> V_390 = * F_398 ( V_819 ) ;
V_400 -> V_8 = V_8 ;
V_400 -> V_637 = F_399 ( V_818 , 0 ) ;
if ( V_400 -> V_637 <= 0 )
return - V_49 ;
F_400 ( V_8 -> V_254 , & V_400 -> V_640 , F_349 ,
V_820 ) ;
V_8 -> V_391 = 1 ;
return 0 ;
}
static int F_401 ( struct V_7 * V_8 ,
struct V_817 * V_818 )
{
struct V_393 * V_400 ;
int V_46 , V_166 ;
V_8 -> V_391 = F_402 () ;
if ( V_821 == V_822 )
V_8 -> V_391 += 1 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ ) {
char V_823 [ 16 ] ;
V_400 = V_8 -> V_392 + V_46 ;
V_400 -> V_8 = V_8 ;
V_400 -> type = V_772 ;
V_400 -> V_402 = V_46 ;
V_400 -> V_390 = F_42 ( V_46 ) ;
snprintf ( V_823 , sizeof( V_823 ) , L_38 , V_46 ) ;
if ( V_821 == V_824 ) {
V_400 -> V_316 = V_46 * V_825 ;
V_400 -> V_383 = V_825 ;
} else if ( V_821 == V_822 &&
V_46 == ( V_8 -> V_391 - 1 ) ) {
V_400 -> V_316 = 0 ;
V_400 -> V_383 = V_8 -> V_383 ;
V_400 -> type = V_401 ;
strncpy ( V_823 , L_39 , sizeof( V_823 ) ) ;
}
V_400 -> V_637 = F_403 ( V_818 , V_823 ) ;
if ( V_400 -> V_637 <= 0 ) {
V_166 = - V_49 ;
goto V_253;
}
F_400 ( V_8 -> V_254 , & V_400 -> V_640 , F_349 ,
V_820 ) ;
}
return 0 ;
V_253:
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ )
F_404 ( V_8 -> V_392 [ V_46 ] . V_637 ) ;
return V_166 ;
}
static int F_405 ( struct V_7 * V_8 ,
struct V_817 * V_818 )
{
if ( V_8 -> V_398 )
return F_401 ( V_8 , V_818 ) ;
else
return F_397 ( V_8 , V_818 ) ;
}
static void F_406 ( struct V_7 * V_8 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ )
F_404 ( V_8 -> V_392 [ V_46 ] . V_637 ) ;
}
static void F_407 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_18 ;
int V_46 ;
if ( V_2 -> V_11 == V_12 ) {
F_1 ( V_2 , F_408 ( V_8 -> V_42 ) ,
V_8 -> V_383 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_8 -> V_391 ; V_46 ++ ) {
struct V_393 * V_639 = V_8 -> V_392 + V_46 ;
if ( ! V_639 -> V_383 )
continue;
V_18 = V_639 -> V_402 ;
V_18 |= V_8 -> V_42 << V_826 ;
F_1 ( V_2 , V_827 , V_18 ) ;
V_18 = V_639 -> V_316 ;
V_18 |= V_639 -> V_383 << V_828 ;
F_1 ( V_2 , V_829 , V_18 ) ;
}
}
static int F_409 ( struct V_7 * V_8 )
{
struct V_335 * V_254 = V_8 -> V_254 -> V_254 . V_364 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_31 * V_32 ;
int V_500 , V_6 , V_253 ;
if ( V_8 -> V_316 + V_8 -> V_383 >
V_210 * V_2 -> V_830 )
return - V_49 ;
if ( V_8 -> V_383 % 4 || ( V_8 -> V_383 > V_2 -> V_830 ) ||
( V_8 -> V_521 > V_43 ) )
return - V_49 ;
F_223 ( V_8 ) ;
F_208 ( V_8 ) ;
V_8 -> V_589 = V_831 ;
V_8 -> V_523 = F_90 ( V_254 , V_8 -> V_521 , sizeof( * V_8 -> V_523 ) ,
V_117 ) ;
if ( ! V_8 -> V_523 )
return - V_167 ;
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
int V_832 = F_23 ( V_8 -> V_42 , V_500 ) ;
struct V_522 * V_21 ;
V_21 = F_410 ( V_254 , sizeof( * V_21 ) , V_117 ) ;
if ( ! V_21 ) {
V_253 = - V_167 ;
goto V_833;
}
V_21 -> V_553 = F_411 ( struct V_31 ) ;
if ( ! V_21 -> V_553 ) {
V_253 = - V_167 ;
goto V_833;
}
V_21 -> V_42 = V_832 ;
V_21 -> V_595 = V_500 ;
V_21 -> V_576 = V_834 ;
F_240 (cpu) {
V_32 = F_241 ( V_21 -> V_553 , V_6 ) ;
V_32 -> V_6 = V_6 ;
}
V_8 -> V_523 [ V_500 ] = V_21 ;
}
V_8 -> V_355 = F_90 ( V_254 , V_8 -> V_383 , sizeof( * V_8 -> V_355 ) ,
V_117 ) ;
if ( ! V_8 -> V_355 ) {
V_253 = - V_167 ;
goto V_833;
}
for ( V_500 = 0 ; V_500 < V_8 -> V_383 ; V_500 ++ ) {
struct V_536 * V_381 ;
V_381 = F_410 ( V_254 , sizeof( * V_381 ) , V_117 ) ;
if ( ! V_381 ) {
V_253 = - V_167 ;
goto V_833;
}
V_381 -> V_42 = V_8 -> V_316 + V_500 ;
V_381 -> V_8 = V_8 -> V_42 ;
V_381 -> V_749 = V_500 ;
V_8 -> V_355 [ V_500 ] = V_381 ;
}
F_407 ( V_8 ) ;
for ( V_500 = 0 ; V_500 < V_8 -> V_383 ; V_500 ++ ) {
struct V_536 * V_381 = V_8 -> V_355 [ V_500 ] ;
V_381 -> V_20 = V_8 -> V_605 ;
V_381 -> V_572 = V_835 ;
V_381 -> V_587 = V_836 ;
}
F_221 ( V_8 ) ;
F_214 ( V_8 ) ;
F_111 ( V_8 ) ;
F_109 ( V_8 ) ;
V_8 -> V_331 = F_167 ( V_8 -> V_254 -> V_387 ) ;
V_253 = F_164 ( V_8 ) ;
if ( V_253 )
goto V_833;
return 0 ;
V_833:
for ( V_500 = 0 ; V_500 < V_8 -> V_521 ; V_500 ++ ) {
if ( ! V_8 -> V_523 [ V_500 ] )
continue;
F_412 ( V_8 -> V_523 [ V_500 ] -> V_553 ) ;
}
return V_253 ;
}
static bool F_413 ( struct V_1 * V_2 ,
struct V_817 * V_818 )
{
char * V_837 [ 5 ] = { L_39 , L_40 , L_41 ,
L_42 , L_43 } ;
int V_166 , V_46 ;
if ( V_2 -> V_11 == V_12 )
return false ;
for ( V_46 = 0 ; V_46 < 5 ; V_46 ++ ) {
V_166 = F_414 ( V_818 , L_44 ,
V_837 [ V_46 ] ) ;
if ( V_166 < 0 )
return false ;
}
return true ;
}
static void F_415 ( struct V_290 * V_254 , struct V_1 * V_2 ,
struct V_817 * V_818 ,
char * * V_838 )
{
struct V_7 * V_8 = F_101 ( V_254 ) ;
char V_839 [ V_130 ] = { 0 } ;
const char * V_840 ;
V_840 = F_416 ( V_818 ) ;
if ( V_840 && F_382 ( V_840 ) ) {
* V_838 = L_45 ;
F_102 ( V_254 -> V_291 , V_840 ) ;
return;
}
if ( V_2 -> V_11 == V_12 ) {
F_361 ( V_8 , V_839 ) ;
if ( F_382 ( V_839 ) ) {
* V_838 = L_46 ;
F_102 ( V_254 -> V_291 , V_839 ) ;
return;
}
}
* V_838 = L_47 ;
F_417 ( V_254 ) ;
}
static int F_418 ( struct V_251 * V_252 ,
struct V_817 * V_818 ,
struct V_1 * V_2 , int V_47 )
{
struct V_817 * V_767 ;
struct V_841 * V_448 ;
struct V_7 * V_8 ;
struct V_663 * V_664 ;
struct V_290 * V_254 ;
struct V_842 * V_843 ;
char * V_838 = L_48 ;
unsigned int V_521 , V_383 ;
bool V_398 ;
T_1 V_42 ;
int V_844 ;
int V_446 ;
int V_253 , V_46 , V_6 ;
V_398 = F_413 ( V_2 , V_818 ) ;
if ( ! V_398 )
V_821 = V_822 ;
V_521 = V_43 ;
if ( V_2 -> V_11 == V_338 && V_821 == V_824 )
V_383 = V_825 * F_402 () ;
else
V_383 = V_825 ;
V_254 = F_419 ( sizeof( * V_8 ) , V_521 , V_383 ) ;
if ( ! V_254 )
return - V_167 ;
V_767 = F_420 ( V_818 , L_49 , 0 ) ;
V_446 = F_421 ( V_818 ) ;
if ( V_446 < 0 ) {
F_125 ( & V_252 -> V_254 , L_50 ) ;
V_253 = V_446 ;
goto V_845;
}
V_448 = F_422 ( & V_252 -> V_254 , V_818 , NULL ) ;
if ( F_423 ( V_448 ) ) {
if ( F_424 ( V_448 ) == - V_846 ) {
V_253 = - V_846 ;
goto V_845;
}
V_448 = NULL ;
}
if ( F_425 ( V_818 , L_51 , & V_42 ) ) {
V_253 = - V_49 ;
F_125 ( & V_252 -> V_254 , L_52 ) ;
goto V_845;
}
V_254 -> V_847 = V_758 ;
V_254 -> V_848 = 5 * V_849 ;
V_254 -> V_850 = & V_851 ;
V_254 -> V_852 = & V_853 ;
V_8 = F_101 ( V_254 ) ;
V_8 -> V_254 = V_254 ;
V_8 -> V_521 = V_521 ;
V_8 -> V_383 = V_383 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_398 = V_398 ;
V_253 = F_405 ( V_8 , V_818 ) ;
if ( V_253 )
goto V_845;
V_8 -> V_778 = F_403 ( V_818 , L_53 ) ;
if ( V_8 -> V_778 == - V_846 ) {
V_253 = - V_846 ;
goto V_854;
}
if ( V_8 -> V_778 <= 0 )
V_8 -> V_778 = 0 ;
if ( F_426 ( V_818 , L_54 ) )
V_8 -> V_502 |= V_503 ;
V_8 -> V_42 = V_42 ;
if ( V_2 -> V_11 == V_12 )
V_8 -> V_316 = V_8 -> V_42 * V_8 -> V_383 ;
else
V_8 -> V_316 = V_8 -> V_42 * V_2 -> V_830 ;
V_8 -> V_767 = V_767 ;
V_8 -> V_423 = V_446 ;
V_8 -> V_448 = V_448 ;
if ( V_2 -> V_11 == V_12 ) {
V_843 = F_427 ( V_252 , V_855 , 2 + V_42 ) ;
V_8 -> V_436 = F_428 ( & V_252 -> V_254 , V_843 ) ;
if ( F_423 ( V_8 -> V_436 ) ) {
V_253 = F_424 ( V_8 -> V_436 ) ;
goto V_779;
}
} else {
if ( F_425 ( V_818 , L_55 ,
& V_8 -> V_407 ) ) {
V_253 = - V_49 ;
F_125 ( & V_252 -> V_254 , L_56 ) ;
goto V_854;
}
V_8 -> V_436 = V_2 -> V_413 + F_429 ( V_8 -> V_407 ) ;
}
V_8 -> V_705 = F_430 ( struct V_707 ) ;
if ( ! V_8 -> V_705 ) {
V_253 = - V_167 ;
goto V_779;
}
F_415 ( V_254 , V_2 , V_818 , & V_838 ) ;
V_8 -> V_616 = V_758 ;
V_8 -> V_605 = V_757 ;
F_431 ( V_254 , & V_252 -> V_254 ) ;
V_253 = F_409 ( V_8 ) ;
if ( V_253 < 0 ) {
F_125 ( & V_252 -> V_254 , L_57 , V_42 ) ;
goto V_856;
}
F_209 ( V_8 ) ;
if ( V_2 -> V_11 == V_12 )
F_206 ( V_8 ) ;
F_211 ( V_8 ) ;
V_8 -> V_553 = F_411 ( struct V_663 ) ;
if ( ! V_8 -> V_553 ) {
V_253 = - V_167 ;
goto V_857;
}
if ( ! V_8 -> V_398 ) {
F_240 (cpu) {
V_664 = F_241 ( V_8 -> V_553 , V_6 ) ;
F_432 ( & V_664 -> V_668 , V_858 ,
V_669 ) ;
V_664 -> V_668 . V_859 = F_308 ;
V_664 -> V_666 = false ;
F_433 ( & V_664 -> V_673 ,
F_306 ,
( unsigned long ) V_254 ) ;
}
}
V_844 = V_860 | V_861 | V_862 ;
V_254 -> V_844 = V_844 | V_863 ;
V_254 -> V_864 |= V_844 | V_863 | V_865 ;
V_254 -> V_866 |= V_844 ;
V_254 -> V_867 = V_868 ;
V_254 -> V_869 = 9676 ;
V_253 = F_434 ( V_254 ) ;
if ( V_253 < 0 ) {
F_125 ( & V_252 -> V_254 , L_58 ) ;
goto V_870;
}
F_360 ( V_254 , L_59 , V_838 , V_254 -> V_291 ) ;
V_2 -> V_871 [ V_47 ] = V_8 ;
return 0 ;
V_870:
F_412 ( V_8 -> V_553 ) ;
V_857:
for ( V_46 = 0 ; V_46 < V_8 -> V_521 ; V_46 ++ )
F_412 ( V_8 -> V_523 [ V_46 ] -> V_553 ) ;
V_856:
F_412 ( V_8 -> V_705 ) ;
V_779:
if ( V_8 -> V_778 )
F_404 ( V_8 -> V_778 ) ;
V_854:
F_406 ( V_8 ) ;
V_845:
F_435 ( V_767 ) ;
F_436 ( V_254 ) ;
return V_253 ;
}
static void F_437 ( struct V_7 * V_8 )
{
int V_46 ;
F_438 ( V_8 -> V_254 ) ;
F_435 ( V_8 -> V_767 ) ;
F_412 ( V_8 -> V_553 ) ;
F_412 ( V_8 -> V_705 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_521 ; V_46 ++ )
F_412 ( V_8 -> V_523 [ V_46 ] -> V_553 ) ;
F_406 ( V_8 ) ;
if ( V_8 -> V_778 )
F_404 ( V_8 -> V_778 ) ;
F_436 ( V_8 -> V_254 ) ;
}
static void F_439 ( const struct V_872 * V_873 ,
struct V_1 * V_2 )
{
T_1 V_874 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 6 ; V_46 ++ ) {
F_1 ( V_2 , F_440 ( V_46 ) , 0 ) ;
F_1 ( V_2 , F_441 ( V_46 ) , 0 ) ;
if ( V_46 < 4 )
F_1 ( V_2 , F_442 ( V_46 ) , 0 ) ;
}
V_874 = 0 ;
for ( V_46 = 0 ; V_46 < V_873 -> V_875 ; V_46 ++ ) {
const struct V_876 * V_877 = V_873 -> V_877 + V_46 ;
F_1 ( V_2 , F_440 ( V_46 ) ,
( V_877 -> V_436 & 0xffff0000 ) | ( V_877 -> V_878 << 8 ) |
V_873 -> V_879 ) ;
F_1 ( V_2 , F_441 ( V_46 ) ,
( V_877 -> V_20 - 1 ) & 0xffff0000 ) ;
V_874 |= ( 1 << V_46 ) ;
}
F_1 ( V_2 , V_880 , V_874 ) ;
}
static void F_443 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_210 ; V_8 ++ ) {
F_1 ( V_2 , F_444 ( V_8 ) ,
V_881 ) ;
F_1 ( V_2 , F_445 ( V_8 ) ,
V_882 ) ;
}
F_1 ( V_2 , V_883 ,
V_884 ) ;
F_1 ( V_2 , V_885 , 0x1 ) ;
}
static void F_446 ( struct V_1 * V_2 )
{
T_1 V_18 , V_886 , V_887 ;
F_1 ( V_2 , V_368 , 0x0 ) ;
V_886 = V_888
<< V_889 ;
V_886 |= V_890
<< V_891 ;
V_887 = V_892
<< V_889 ;
V_887 |= V_890
<< V_891 ;
F_1 ( V_2 , V_893 , V_887 ) ;
F_1 ( V_2 , V_894 , V_886 ) ;
F_1 ( V_2 , V_895 , V_886 ) ;
F_1 ( V_2 , V_896 , V_887 ) ;
F_1 ( V_2 , V_897 , V_886 ) ;
F_1 ( V_2 , V_898 , V_887 ) ;
F_1 ( V_2 , V_899 , V_886 ) ;
F_1 ( V_2 , V_900 , V_887 ) ;
V_18 = V_901
<< V_902 ;
V_18 |= V_903
<< V_904 ;
F_1 ( V_2 , V_905 , V_18 ) ;
F_1 ( V_2 , V_906 , V_18 ) ;
V_18 = V_888
<< V_902 ;
V_18 |= V_890
<< V_904 ;
F_1 ( V_2 , V_907 , V_18 ) ;
V_18 = V_892
<< V_902 ;
V_18 |= V_890
<< V_904 ;
F_1 ( V_2 , V_908 , V_18 ) ;
}
static int F_447 ( struct V_251 * V_252 , struct V_1 * V_2 )
{
const struct V_872 * V_909 ;
int V_253 , V_46 ;
T_1 V_18 ;
V_909 = F_448 () ;
if ( V_909 )
F_439 ( V_909 , V_2 ) ;
if ( V_2 -> V_11 == V_338 )
F_446 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_18 = F_4 ( V_2 -> V_762 + V_910 ) ;
V_18 |= V_911 ;
F_2 ( V_18 , V_2 -> V_762 + V_910 ) ;
} else {
V_18 = F_4 ( V_2 -> V_413 + V_912 ) ;
V_18 &= ~ V_913 ;
F_2 ( V_18 , V_2 -> V_413 + V_912 ) ;
}
V_2 -> V_732 = F_90 ( & V_252 -> V_254 , F_243 () ,
sizeof( * V_2 -> V_732 ) ,
V_117 ) ;
if ( ! V_2 -> V_732 )
return - V_167 ;
F_240 (i) {
V_2 -> V_732 [ V_46 ] . V_42 = V_46 ;
V_2 -> V_732 [ V_46 ] . V_20 = V_600 ;
V_253 = F_271 ( V_252 , & V_2 -> V_732 [ V_46 ] , V_46 , V_2 ) ;
if ( V_253 < 0 )
return V_253 ;
}
F_443 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 )
F_2 ( V_914 ,
V_2 -> V_762 + V_915 ) ;
F_1 ( V_2 , V_916 , 0x1 ) ;
V_253 = F_143 ( V_252 , V_2 ) ;
if ( V_253 < 0 )
return V_253 ;
V_253 = F_94 ( V_252 , V_2 ) ;
if ( V_253 < 0 )
return V_253 ;
F_108 ( V_2 ) ;
return 0 ;
}
static int F_449 ( struct V_251 * V_252 )
{
struct V_817 * V_917 = V_252 -> V_254 . V_918 ;
struct V_817 * V_818 ;
struct V_1 * V_2 ;
struct V_842 * V_843 ;
void T_9 * V_436 ;
int V_919 , V_46 ;
int V_253 ;
V_2 = F_410 ( & V_252 -> V_254 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_167 ;
V_2 -> V_11 =
( unsigned long ) F_450 ( & V_252 -> V_254 ) ;
V_843 = F_427 ( V_252 , V_855 , 0 ) ;
V_436 = F_428 ( & V_252 -> V_254 , V_843 ) ;
if ( F_423 ( V_436 ) )
return F_424 ( V_436 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_843 = F_427 ( V_252 , V_855 , 1 ) ;
V_2 -> V_762 = F_428 ( & V_252 -> V_254 , V_843 ) ;
if ( F_423 ( V_2 -> V_762 ) )
return F_424 ( V_2 -> V_762 ) ;
} else {
V_843 = F_427 ( V_252 , V_855 , 1 ) ;
V_2 -> V_413 = F_428 ( & V_252 -> V_254 , V_843 ) ;
if ( F_423 ( V_2 -> V_413 ) )
return F_424 ( V_2 -> V_413 ) ;
V_2 -> V_403 =
F_451 ( V_252 -> V_254 . V_918 ,
L_60 ) ;
if ( F_423 ( V_2 -> V_403 ) )
V_2 -> V_403 = NULL ;
}
for ( V_46 = 0 ; V_46 < V_920 ; V_46 ++ ) {
T_1 V_921 ;
V_921 = ( V_2 -> V_11 == V_12 ?
V_922 : V_923 ) ;
V_2 -> V_5 [ V_46 ] = V_436 + V_46 * V_921 ;
}
if ( V_2 -> V_11 == V_12 )
V_2 -> V_830 = 8 ;
else
V_2 -> V_830 = 32 ;
V_2 -> V_924 = F_452 ( & V_252 -> V_254 , L_61 ) ;
if ( F_423 ( V_2 -> V_924 ) )
return F_424 ( V_2 -> V_924 ) ;
V_253 = F_453 ( V_2 -> V_924 ) ;
if ( V_253 < 0 )
return V_253 ;
V_2 -> V_925 = F_452 ( & V_252 -> V_254 , L_62 ) ;
if ( F_423 ( V_2 -> V_925 ) ) {
V_253 = F_424 ( V_2 -> V_925 ) ;
goto V_926;
}
V_253 = F_453 ( V_2 -> V_925 ) ;
if ( V_253 < 0 )
goto V_926;
if ( V_2 -> V_11 == V_338 ) {
V_2 -> V_927 = F_452 ( & V_252 -> V_254 , L_63 ) ;
if ( F_423 ( V_2 -> V_927 ) ) {
V_253 = F_424 ( V_2 -> V_927 ) ;
goto V_928;
}
V_253 = F_453 ( V_2 -> V_927 ) ;
if ( V_253 < 0 )
goto V_928;
V_2 -> V_929 = F_452 ( & V_252 -> V_254 , L_64 ) ;
if ( F_423 ( V_2 -> V_929 ) ) {
V_253 = F_424 ( V_2 -> V_929 ) ;
if ( V_253 == - V_846 )
goto V_928;
V_2 -> V_929 = NULL ;
} else {
V_253 = F_453 ( V_2 -> V_929 ) ;
if ( V_253 < 0 )
goto V_928;
}
}
V_2 -> V_509 = F_454 ( V_2 -> V_924 ) ;
if ( V_2 -> V_11 == V_338 ) {
V_253 = F_455 ( & V_252 -> V_254 , F_456 ( 40 ) ) ;
if ( V_253 )
goto V_930;
V_253 = F_457 ( & V_252 -> V_254 , F_456 ( 32 ) ) ;
if ( V_253 )
goto V_930;
}
V_253 = F_447 ( V_252 , V_2 ) ;
if ( V_253 < 0 ) {
F_125 ( & V_252 -> V_254 , L_65 ) ;
goto V_930;
}
V_919 = F_458 ( V_917 ) ;
if ( V_919 == 0 ) {
F_125 ( & V_252 -> V_254 , L_66 ) ;
V_253 = - V_768 ;
goto V_930;
}
V_2 -> V_871 = F_90 ( & V_252 -> V_254 , V_919 ,
sizeof( * V_2 -> V_871 ) ,
V_117 ) ;
if ( ! V_2 -> V_871 ) {
V_253 = - V_167 ;
goto V_930;
}
V_46 = 0 ;
F_459 (dn, port_node) {
V_253 = F_418 ( V_252 , V_818 , V_2 , V_46 ) ;
if ( V_253 < 0 )
goto V_930;
V_46 ++ ;
}
F_460 ( V_252 , V_2 ) ;
return 0 ;
V_930:
F_461 ( V_2 -> V_929 ) ;
if ( V_2 -> V_11 == V_338 )
F_461 ( V_2 -> V_927 ) ;
V_928:
F_461 ( V_2 -> V_925 ) ;
V_926:
F_461 ( V_2 -> V_924 ) ;
return V_253 ;
}
static int F_462 ( struct V_251 * V_252 )
{
struct V_1 * V_2 = F_463 ( V_252 ) ;
struct V_817 * V_917 = V_252 -> V_254 . V_918 ;
struct V_817 * V_818 ;
int V_46 = 0 ;
F_459 (dn, port_node) {
if ( V_2 -> V_871 [ V_46 ] )
F_437 ( V_2 -> V_871 [ V_46 ] ) ;
V_46 ++ ;
}
for ( V_46 = 0 ; V_46 < V_349 ; V_46 ++ ) {
struct V_321 * V_325 = & V_2 -> V_350 [ V_46 ] ;
F_140 ( V_252 , V_2 , V_325 ) ;
}
F_240 (i) {
struct V_522 * V_542 = & V_2 -> V_732 [ V_46 ] ;
F_124 ( & V_252 -> V_254 ,
V_600 * V_601 ,
V_542 -> V_524 ,
V_542 -> V_602 ) ;
}
F_461 ( V_2 -> V_929 ) ;
F_461 ( V_2 -> V_927 ) ;
F_461 ( V_2 -> V_924 ) ;
F_461 ( V_2 -> V_925 ) ;
return 0 ;
}
