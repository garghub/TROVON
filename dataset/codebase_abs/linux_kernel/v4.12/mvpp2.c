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
V_77 = ( 8 << V_45 -> V_50 . V_67 [ V_76 + 1 ] ) | V_45 -> V_50 . V_67 [ V_76 ] ;
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
F_48 ( & V_45 , V_63 | V_186 ,
V_64 | V_186 ) ;
F_36 ( & V_45 , 5 , V_177 , V_187 ) ;
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
V_45 . V_58 . V_51 [ V_188 ] = 0x0 ;
F_48 ( & V_45 , V_63 , V_64 ) ;
F_36 ( & V_45 , 2 , 0x00 , V_189 ) ;
F_36 ( & V_45 , 3 , 0x00 , V_187 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned short V_190 )
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
switch ( V_190 ) {
case V_191 :
F_36 ( & V_45 , 0 , V_192 ,
V_193 ) ;
F_48 ( & V_45 , V_194 ,
V_195 ) ;
break;
case V_196 :
V_84 = V_197 ;
F_36 ( & V_45 , 0 , V_84 , V_84 ) ;
F_36 ( & V_45 , 1 , V_84 , V_84 ) ;
F_36 ( & V_45 , 2 , V_84 , V_84 ) ;
F_36 ( & V_45 , 3 , V_84 , V_84 ) ;
F_48 ( & V_45 , V_198 ,
V_195 ) ;
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
( V_177 != V_199 ) && ( V_177 != V_200 ) )
return - V_49 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_201 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_63 , V_64 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_202 ) - 6 ,
V_184 ) ;
F_36 ( & V_45 , 0 , V_177 , V_187 ) ;
F_41 ( & V_45 , V_203 ,
V_203 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_201 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , unsigned short V_190 )
{
struct V_44 V_45 ;
int V_116 ;
if ( V_190 != V_191 )
return - V_49 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_201 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_201 ) ;
F_48 ( & V_45 , V_194 ,
V_195 ) ;
F_50 ( & V_45 , V_203 ,
V_203 ) ;
F_53 ( & V_45 , - 18 , V_131 ) ;
F_36 ( & V_45 , 0 , V_204 ,
V_205 ) ;
F_41 ( & V_45 , 0 , V_203 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_201 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , int V_8 , int V_206 ,
int V_207 , int V_3 )
{
T_1 V_18 ;
V_18 = F_3 ( V_2 , V_208 ) ;
V_18 &= ~ F_76 ( V_8 ) ;
V_18 |= F_77 ( V_8 , V_206 ) ;
F_1 ( V_2 , V_208 , V_18 ) ;
V_18 = F_3 ( V_2 , F_78 ( V_8 ) ) ;
V_18 &= ~ F_79 ( V_8 ) ;
V_18 |= F_80 ( V_8 , V_207 ) ;
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
for ( V_8 = 0 ; V_8 < V_209 ; V_8 ++ ) {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_118 ) ;
V_45 . V_47 = V_210 - V_8 ;
F_34 ( & V_45 , 0 ) ;
F_50 ( & V_45 , V_8 , V_119 ) ;
F_45 ( & V_45 , V_211 , 1 ) ;
F_29 ( V_2 , V_45 . V_47 , V_118 ) ;
F_24 ( V_2 , & V_45 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_47 = V_212 ;
F_31 ( & V_45 , V_213 ) ;
F_53 ( & V_45 , V_214 ,
V_131 ) ;
F_52 ( & V_45 , V_123 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_213 ) ;
F_24 ( V_2 , & V_45 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_47 = V_215 ;
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
F_62 ( V_2 , V_133 , 0 , false ) ;
F_62 ( V_2 , V_216 , 0 , false ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
F_63 ( V_2 , 0 , false , V_217 ,
V_218 ) ;
F_63 ( V_2 , 0 , false , V_219 , V_218 ) ;
F_63 ( V_2 , 0 , false , V_217 ,
V_220 ) ;
F_63 ( V_2 , 0 , false , V_219 , V_220 ) ;
F_64 ( V_2 , 0 , false ,
V_217 , V_218 ) ;
F_64 ( V_2 , 0 , false ,
V_219 , V_218 ) ;
F_64 ( V_2 , 0 , true ,
V_217 , V_220 ) ;
F_64 ( V_2 , 0 , true ,
V_219 , V_220 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_127 ) ;
V_45 . V_47 = V_221 ;
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
F_44 ( & V_45 , 0 , V_222 ) ;
F_53 ( & V_45 , V_223 ,
V_131 ) ;
F_52 ( & V_45 , V_224 ) ;
F_48 ( & V_45 , V_225 ,
V_225 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = false ;
F_30 ( V_2 , V_45 . V_47 , V_225 ,
V_225 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_229 ) ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_230 ,
V_231 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = true ;
F_30 ( V_2 , V_45 . V_47 , V_230 ,
V_231 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_233 ) ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_234 |
V_235 ,
V_236 |
V_237 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = true ;
F_30 ( V_2 , V_45 . V_47 , V_234 |
V_235 ,
V_236 |
V_237 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_238 ) ;
F_36 ( & V_45 , V_153 ,
V_239 | V_240 ,
V_241 |
V_242 ) ;
F_52 ( & V_45 , V_181 ) ;
F_48 ( & V_45 , V_243 ,
V_231 ) ;
F_53 ( & V_45 , V_153 + 4 ,
V_131 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = false ;
F_30 ( V_2 , V_45 . V_47 , V_243 ,
V_231 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 . V_47 = V_116 ;
V_45 . V_50 . V_67 [ F_37 ( V_153 ) ] = 0x0 ;
V_45 . V_50 . V_67 [ F_38 ( V_153 ) ] = 0x0 ;
F_36 ( & V_45 , V_153 ,
V_239 ,
V_241 ) ;
V_45 . V_58 . V_51 [ V_89 ] = 0x0 ;
V_45 . V_58 . V_51 [ V_188 ] = 0x0 ;
F_48 ( & V_45 , V_244 ,
V_231 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = false ;
F_30 ( V_2 , V_45 . V_47 , V_244 ,
V_231 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_245 ) ;
F_53 ( & V_45 , V_153 + 8 +
V_246 ,
V_131 ) ;
F_52 ( & V_45 , V_201 ) ;
F_48 ( & V_45 , V_247 ,
V_231 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = false ;
F_30 ( V_2 , V_45 . V_47 , V_247 ,
V_231 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_31 ( & V_45 , V_146 ) ;
V_45 . V_47 = V_248 ;
F_34 ( & V_45 , V_73 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_52 ( & V_45 , V_118 ) ;
F_48 ( & V_45 , V_249 ,
V_231 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_146 ) ;
V_2 -> V_61 [ V_45 . V_47 ] . V_226 = V_227 ;
V_2 -> V_61 [ V_45 . V_47 ] . V_228 = true ;
F_30 ( V_2 , V_45 . V_47 , V_249 ,
V_231 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_89 ( struct V_250 * V_251 , struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_252 ;
V_2 -> V_173 = F_90 ( & V_251 -> V_253 , sizeof( bool ) ,
V_172 ,
V_117 ) ;
if ( ! V_2 -> V_173 )
return - V_167 ;
V_252 = F_70 ( V_2 , V_254 , V_255 ,
V_73 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_70 ( V_2 , V_254 , V_254 ,
V_73 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_67 ( V_2 , V_255 , V_171 ,
V_73 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_67 ( V_2 , V_254 , V_171 ,
V_73 ) ;
if ( V_252 )
return V_252 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_143 ) ;
V_45 . V_47 = V_256 ;
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
V_45 . V_47 = V_257 ;
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
F_31 ( & V_45 , V_224 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_258 ) ;
F_52 ( & V_45 , V_181 ) ;
F_48 ( & V_45 , V_244 ,
V_231 ) ;
F_53 ( & V_45 , V_153 + 4 ,
V_131 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_224 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 . V_47 = V_116 ;
F_36 ( & V_45 , V_153 ,
V_239 | V_240 ,
V_241 |
V_242 ) ;
V_45 . V_58 . V_51 [ V_89 ] = 0x0 ;
V_45 . V_58 . V_51 [ V_188 ] = 0x0 ;
F_48 ( & V_45 , V_243 ,
V_231 ) ;
F_29 ( V_2 , V_45 . V_47 , V_224 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_224 ) ;
V_45 . V_47 = V_116 ;
F_44 ( & V_45 , 0 , V_259 ) ;
F_52 ( & V_45 , V_201 ) ;
F_48 ( & V_45 , V_247 ,
V_231 ) ;
F_53 ( & V_45 , V_153 + 4 ,
V_131 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_224 ) ;
F_24 ( V_2 , & V_45 ) ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_224 ) ;
V_45 . V_47 = V_116 ;
F_48 ( & V_45 , V_249 ,
V_231 ) ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_54 ( & V_45 , V_232 ,
V_153 ,
V_184 ) ;
F_29 ( V_2 , V_45 . V_47 , V_224 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_44 V_45 ;
int V_252 ;
V_252 = F_71 ( V_2 , V_178 , V_260 ,
V_261 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_71 ( V_2 , V_179 , V_262 ,
V_261 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_71 ( V_2 , V_180 ,
V_234 |
V_235 ,
V_236 |
V_237 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_72 ( V_2 , V_196 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_72 ( V_2 , V_191 ) ;
if ( V_252 )
return V_252 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_181 ) ;
V_45 . V_47 = V_263 ;
F_52 ( & V_45 , V_181 ) ;
F_53 ( & V_45 , 12 , V_131 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_183 ) - 4 ,
V_184 ) ;
F_50 ( & V_45 , V_185 ,
V_185 ) ;
F_48 ( & V_45 , V_264 ,
V_261 ) ;
F_41 ( & V_45 , 0 , V_185 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_181 ) ;
V_45 . V_47 = V_265 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_266 ,
V_195 ) ;
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
int V_116 , V_252 ;
V_252 = F_73 ( V_2 , V_178 ,
V_260 ,
V_261 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_73 ( V_2 , V_179 ,
V_262 ,
V_261 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_73 ( V_2 , V_199 ,
V_234 |
V_235 ,
V_236 |
V_237 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_73 ( V_2 , V_200 ,
V_267 ,
V_268 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_74 ( V_2 , V_191 ) ;
if ( V_252 )
return V_252 ;
V_116 = F_58 ( V_2 , V_156 ,
V_157 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_201 ) ;
V_45 . V_47 = V_116 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_249 |
V_124 ,
V_231 |
V_124 ) ;
F_36 ( & V_45 , 1 , 0x00 , V_269 ) ;
F_41 ( & V_45 , V_203 ,
V_203 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_31 ( & V_45 , V_201 ) ;
V_45 . V_47 = V_270 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_264 ,
V_261 ) ;
F_54 ( & V_45 , V_182 ,
sizeof( struct V_202 ) - 4 ,
V_184 ) ;
F_41 ( & V_45 , V_203 ,
V_203 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_31 ( & V_45 , V_201 ) ;
V_45 . V_47 = V_271 ;
F_52 ( & V_45 , V_118 ) ;
F_45 ( & V_45 , V_125 , 1 ) ;
F_48 ( & V_45 , V_264 ,
V_261 ) ;
F_41 ( & V_45 , V_272 ,
V_272 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_181 ) ;
F_24 ( V_2 , & V_45 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_31 ( & V_45 , V_201 ) ;
V_45 . V_47 = V_273 ;
F_52 ( & V_45 , V_201 ) ;
F_48 ( & V_45 , V_266 ,
V_195 ) ;
F_50 ( & V_45 , V_203 ,
V_203 ) ;
F_53 ( & V_45 , - 18 , V_131 ) ;
F_41 ( & V_45 , 0 , V_203 ) ;
F_34 ( & V_45 , V_73 ) ;
F_29 ( V_2 , V_45 . V_47 , V_201 ) ;
F_24 ( V_2 , & V_45 ) ;
return 0 ;
}
static int F_94 ( struct V_250 * V_251 ,
struct V_1 * V_2 )
{
int V_252 , V_47 , V_46 ;
F_1 ( V_2 , V_274 , V_275 ) ;
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
V_2 -> V_61 = F_90 ( & V_251 -> V_253 , V_48 ,
sizeof( * V_2 -> V_61 ) ,
V_117 ) ;
if ( ! V_2 -> V_61 )
return - V_167 ;
for ( V_47 = 0 ; V_47 < V_209 ; V_47 ++ )
F_75 ( V_2 , V_47 , V_213 ,
V_276 , 0 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
V_252 = F_88 ( V_2 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_89 ( V_251 , V_2 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_91 ( V_2 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_93 ( V_2 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_92 ( V_2 ) ;
if ( V_252 )
return V_252 ;
return 0 ;
}
static bool F_95 ( struct V_44 * V_45 ,
const T_6 * V_277 , unsigned char * V_84 )
{
unsigned char V_278 , V_279 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_130 ; V_47 ++ ) {
F_39 ( V_45 , V_47 , & V_278 , & V_279 ) ;
if ( V_279 != V_84 [ V_47 ] )
return false ;
if ( ( V_279 & V_278 ) != ( V_277 [ V_47 ] & V_84 [ V_47 ] ) )
return false ;
}
return true ;
}
static struct V_44 *
F_96 ( struct V_1 * V_2 , int V_280 , const T_6 * V_277 ,
unsigned char * V_84 , int V_281 )
{
struct V_44 * V_45 ;
int V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return NULL ;
F_31 ( V_45 , V_123 ) ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ ) {
unsigned int V_282 ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
( V_2 -> V_61 [ V_116 ] . V_60 != V_123 ) ||
( V_2 -> V_61 [ V_116 ] . V_226 != V_281 ) )
continue;
V_45 -> V_47 = V_116 ;
F_27 ( V_2 , V_45 ) ;
V_282 = F_35 ( V_45 ) ;
if ( F_95 ( V_45 , V_277 , V_84 ) &&
V_282 == V_280 )
return V_45 ;
}
F_57 ( V_45 ) ;
return NULL ;
}
static int F_97 ( struct V_1 * V_2 , int V_8 ,
const T_6 * V_277 , bool V_69 )
{
struct V_44 * V_45 ;
unsigned int V_280 , V_283 , V_63 ;
unsigned char V_84 [ V_130 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_116 ;
V_45 = F_96 ( V_2 , ( 1 << V_8 ) , V_277 , V_84 ,
V_284 ) ;
if ( ! V_45 ) {
if ( ! V_69 )
return 0 ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ )
if ( V_2 -> V_61 [ V_116 ] . V_62 &&
( V_2 -> V_61 [ V_116 ] . V_60 == V_123 ) &&
( V_2 -> V_61 [ V_116 ] . V_226 ==
V_285 ) )
break;
V_116 = F_58 ( V_2 , V_156 ,
V_116 - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_45 = F_56 ( sizeof( * V_45 ) , V_117 ) ;
if ( ! V_45 )
return - V_167 ;
F_31 ( V_45 , V_123 ) ;
V_45 -> V_47 = V_116 ;
F_34 ( V_45 , 0 ) ;
}
F_33 ( V_45 , V_8 , V_69 ) ;
V_280 = F_35 ( V_45 ) ;
if ( V_280 == 0 ) {
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
V_283 = V_130 ;
while ( V_283 -- )
F_36 ( V_45 , V_283 , V_277 [ V_283 ] , 0xff ) ;
if ( F_98 ( V_277 ) )
V_63 = V_286 ;
else if ( F_99 ( V_277 ) )
V_63 = V_134 ;
else
V_63 = V_128 | V_287 ;
F_48 ( V_45 , V_63 , V_129 |
V_287 ) ;
F_30 ( V_2 , V_45 -> V_47 , V_63 , V_129 |
V_287 ) ;
F_53 ( V_45 , 2 * V_130 ,
V_131 ) ;
V_2 -> V_61 [ V_45 -> V_47 ] . V_226 = V_284 ;
F_29 ( V_2 , V_45 -> V_47 , V_123 ) ;
F_24 ( V_2 , V_45 ) ;
F_57 ( V_45 ) ;
return 0 ;
}
static int F_100 ( struct V_288 * V_253 , const T_6 * V_277 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
int V_252 ;
V_252 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_253 -> V_289 ,
false ) ;
if ( V_252 )
return V_252 ;
V_252 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_277 , true ) ;
if ( V_252 )
return V_252 ;
F_102 ( V_253 -> V_289 , V_277 ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 , int V_8 )
{
struct V_44 V_45 ;
int V_47 , V_116 ;
for ( V_116 = V_156 ;
V_116 <= V_157 ; V_116 ++ ) {
unsigned char V_277 [ V_130 ] , V_290 [ V_130 ] ;
if ( ! V_2 -> V_61 [ V_116 ] . V_62 ||
( V_2 -> V_61 [ V_116 ] . V_60 != V_123 ) ||
( V_2 -> V_61 [ V_116 ] . V_226 != V_284 ) )
continue;
V_45 . V_47 = V_116 ;
F_27 ( V_2 , & V_45 ) ;
for ( V_47 = 0 ; V_47 < V_130 ; V_47 ++ )
F_39 ( & V_45 , V_47 , & V_277 [ V_47 ] ,
& V_290 [ V_47 ] ) ;
if ( F_99 ( V_277 ) && ! F_98 ( V_277 ) )
F_97 ( V_2 , V_8 , V_277 , false ) ;
}
}
static int F_104 ( struct V_1 * V_2 , int V_8 , int type )
{
switch ( type ) {
case V_291 :
F_63 ( V_2 , V_8 , true ,
V_219 , V_218 ) ;
F_63 ( V_2 , V_8 , true ,
V_217 , V_218 ) ;
F_63 ( V_2 , V_8 , false ,
V_219 , V_220 ) ;
F_63 ( V_2 , V_8 , false ,
V_217 , V_220 ) ;
break;
case V_292 :
F_63 ( V_2 , V_8 , true ,
V_219 , V_220 ) ;
F_63 ( V_2 , V_8 , true ,
V_217 , V_220 ) ;
F_63 ( V_2 , V_8 , false ,
V_219 , V_218 ) ;
F_63 ( V_2 , V_8 , false ,
V_217 , V_218 ) ;
break;
case V_293 :
case V_294 :
F_63 ( V_2 , V_8 , false ,
V_219 , V_220 ) ;
F_63 ( V_2 , V_8 , false ,
V_217 , V_220 ) ;
F_63 ( V_2 , V_8 , false ,
V_219 , V_218 ) ;
F_63 ( V_2 , V_8 , false ,
V_217 , V_218 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_291 ) )
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
F_45 ( V_45 , V_211 , 1 ) ;
F_29 ( V_8 -> V_2 , V_45 -> V_47 , V_118 ) ;
}
F_34 ( V_45 , ( 1 << V_8 -> V_42 ) ) ;
F_24 ( V_8 -> V_2 , V_45 ) ;
F_57 ( V_45 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_295 * V_296 )
{
F_1 ( V_2 , V_297 , V_296 -> V_47 ) ;
F_1 ( V_2 , V_298 , V_296 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_299 , V_296 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_300 , V_296 -> V_4 [ 2 ] ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
T_1 V_18 ;
V_18 = ( V_302 -> V_303 << V_304 ) | V_302 -> V_305 ;
F_1 ( V_2 , V_306 , V_18 ) ;
F_1 ( V_2 , V_307 , V_302 -> V_4 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_301 V_302 ;
struct V_295 V_296 ;
int V_47 ;
F_1 ( V_2 , V_308 , V_309 ) ;
memset ( & V_296 . V_4 , 0 , sizeof( V_296 . V_4 ) ) ;
for ( V_47 = 0 ; V_47 < V_310 ; V_47 ++ ) {
V_296 . V_47 = V_47 ;
F_106 ( V_2 , & V_296 ) ;
}
V_302 . V_4 = 0 ;
for ( V_47 = 0 ; V_47 < V_311 ; V_47 ++ ) {
V_302 . V_305 = V_47 ;
V_302 . V_303 = 0 ;
F_107 ( V_2 , & V_302 ) ;
V_302 . V_303 = 1 ;
F_107 ( V_2 , & V_302 ) ;
}
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_301 V_302 ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_2 , V_312 ) ;
V_18 &= ~ F_110 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_312 , V_18 ) ;
V_302 . V_305 = V_8 -> V_42 ;
V_302 . V_303 = 0 ;
V_302 . V_4 = 0 ;
V_302 . V_4 &= ~ V_313 ;
V_302 . V_4 |= V_8 -> V_314 ;
V_302 . V_4 &= ~ V_315 ;
F_107 ( V_8 -> V_2 , & V_302 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
T_1 V_18 ;
F_1 ( V_8 -> V_2 , F_112 ( V_8 -> V_42 ) ,
V_8 -> V_314 & V_316 ) ;
F_1 ( V_8 -> V_2 , F_113 ( V_8 -> V_42 ) ,
( V_8 -> V_314 >> V_317 ) ) ;
V_18 = F_3 ( V_8 -> V_2 , V_318 ) ;
V_18 |= F_114 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_318 , V_18 ) ;
}
static void * F_115 ( const struct V_319 * V_320 )
{
if ( F_116 ( V_320 -> V_321 <= V_322 ) )
return F_117 ( V_320 -> V_321 ) ;
else
return F_118 ( V_320 -> V_321 , V_323 ) ;
}
static void F_119 ( const struct V_319 * V_320 , void * V_4 )
{
if ( F_116 ( V_320 -> V_321 <= V_322 ) )
F_120 ( V_4 ) ;
else
F_57 ( V_4 ) ;
}
static int F_121 ( struct V_250 * V_251 ,
struct V_1 * V_2 ,
struct V_319 * V_324 , int V_20 )
{
T_1 V_18 ;
if ( ! F_122 ( V_20 , 16 ) )
return - V_49 ;
if ( V_2 -> V_11 == V_12 )
V_324 -> V_325 = 2 * sizeof( T_1 ) * V_20 ;
else
V_324 -> V_325 = 2 * sizeof( T_3 ) * V_20 ;
V_324 -> V_326 = F_123 ( & V_251 -> V_253 , V_324 -> V_325 ,
& V_324 -> V_17 ,
V_117 ) ;
if ( ! V_324 -> V_326 )
return - V_167 ;
if ( ! F_122 ( ( unsigned long ) V_324 -> V_326 ,
V_327 ) ) {
F_124 ( & V_251 -> V_253 , V_324 -> V_325 ,
V_324 -> V_326 , V_324 -> V_17 ) ;
F_125 ( & V_251 -> V_253 , L_1 ,
V_324 -> V_42 , V_327 ) ;
return - V_167 ;
}
F_1 ( V_2 , F_126 ( V_324 -> V_42 ) ,
F_127 ( V_324 -> V_17 ) ) ;
F_1 ( V_2 , F_128 ( V_324 -> V_42 ) , V_20 ) ;
V_18 = F_3 ( V_2 , F_129 ( V_324 -> V_42 ) ) ;
V_18 |= V_328 ;
F_1 ( V_2 , F_129 ( V_324 -> V_42 ) , V_18 ) ;
V_324 -> type = V_329 ;
V_324 -> V_20 = V_20 ;
V_324 -> V_330 = 0 ;
V_324 -> V_331 = 0 ;
return 0 ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_319 * V_324 ,
int V_332 )
{
T_1 V_18 ;
V_324 -> V_332 = V_332 ;
V_18 = F_131 ( V_332 , 1 << V_333 ) ;
F_1 ( V_2 , F_132 ( V_324 -> V_42 ) , V_18 ) ;
}
static void F_133 ( struct V_334 * V_253 , struct V_1 * V_2 ,
struct V_319 * V_324 ,
T_2 * V_17 ,
T_7 * V_335 )
{
int V_6 = F_134 () ;
* V_17 = F_6 ( V_2 , V_6 ,
F_135 ( V_324 -> V_42 ) ) ;
* V_335 = F_6 ( V_2 , V_6 , V_336 ) ;
if ( V_2 -> V_11 == V_337 ) {
T_1 V_18 ;
T_1 V_338 , V_339 ;
V_18 = F_6 ( V_2 , V_6 , V_340 ) ;
V_338 = ( V_18 & V_341 ) ;
V_339 = ( V_18 & V_342 ) >>
V_343 ;
if ( sizeof( T_2 ) == 8 )
* V_17 |= ( T_3 ) V_338 << 32 ;
if ( sizeof( T_7 ) == 8 )
* V_335 |= ( T_3 ) V_339 << 32 ;
}
F_136 () ;
}
static void F_137 ( struct V_334 * V_253 , struct V_1 * V_2 ,
struct V_319 * V_324 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_324 -> V_331 ; V_46 ++ ) {
T_2 V_14 ;
T_7 V_344 ;
void * V_4 ;
F_133 ( V_253 , V_2 , V_324 ,
& V_14 , & V_344 ) ;
F_138 ( V_253 , V_14 ,
V_324 -> V_332 , V_345 ) ;
V_4 = ( void * ) F_139 ( V_344 ) ;
if ( ! V_4 )
break;
F_119 ( V_324 , V_4 ) ;
}
V_324 -> V_331 -= V_46 ;
}
static int F_140 ( struct V_250 * V_251 ,
struct V_1 * V_2 ,
struct V_319 * V_324 )
{
T_1 V_18 ;
F_137 ( & V_251 -> V_253 , V_2 , V_324 ) ;
if ( V_324 -> V_331 ) {
F_141 ( 1 , L_2 , V_324 -> V_42 ) ;
return 0 ;
}
V_18 = F_3 ( V_2 , F_129 ( V_324 -> V_42 ) ) ;
V_18 |= V_346 ;
F_1 ( V_2 , F_129 ( V_324 -> V_42 ) , V_18 ) ;
F_124 ( & V_251 -> V_253 , V_324 -> V_325 ,
V_324 -> V_326 ,
V_324 -> V_17 ) ;
return 0 ;
}
static int F_142 ( struct V_250 * V_251 ,
struct V_1 * V_2 )
{
int V_46 , V_252 , V_20 ;
struct V_319 * V_324 ;
V_20 = V_347 ;
for ( V_46 = 0 ; V_46 < V_348 ; V_46 ++ ) {
V_324 = & V_2 -> V_349 [ V_46 ] ;
V_324 -> V_42 = V_46 ;
V_252 = F_121 ( V_251 , V_2 , V_324 , V_20 ) ;
if ( V_252 )
goto V_350;
F_130 ( V_2 , V_324 , 0 ) ;
}
return 0 ;
V_350:
F_125 ( & V_251 -> V_253 , L_3 , V_46 , V_20 ) ;
for ( V_46 = V_46 - 1 ; V_46 >= 0 ; V_46 -- )
F_140 ( V_251 , V_2 , & V_2 -> V_349 [ V_46 ] ) ;
return V_252 ;
}
static int F_143 ( struct V_250 * V_251 , struct V_1 * V_2 )
{
int V_46 , V_252 ;
for ( V_46 = 0 ; V_46 < V_348 ; V_46 ++ ) {
F_1 ( V_2 , F_144 ( V_46 ) , 0 ) ;
F_1 ( V_2 , F_145 ( V_46 ) , 0 ) ;
}
V_2 -> V_349 = F_90 ( & V_251 -> V_253 , V_348 ,
sizeof( * V_2 -> V_349 ) , V_117 ) ;
if ( ! V_2 -> V_349 )
return - V_167 ;
V_252 = F_142 ( V_251 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
return 0 ;
}
static void F_146 ( struct V_7 * V_8 ,
int V_351 , int V_352 )
{
T_1 V_18 , V_84 ;
int V_353 ;
V_353 = V_8 -> V_354 [ V_351 ] -> V_42 ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_84 = V_355 ;
else
V_84 = V_356 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_353 ) ) ;
V_18 &= ~ V_84 ;
V_18 |= ( V_352 << V_357 ) & V_84 ;
F_1 ( V_8 -> V_2 , F_147 ( V_353 ) , V_18 ) ;
}
static void F_148 ( struct V_7 * V_8 ,
int V_351 , int V_358 )
{
T_1 V_18 , V_84 ;
int V_353 ;
V_353 = V_8 -> V_354 [ V_351 ] -> V_42 ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_84 = V_359 ;
else
V_84 = V_360 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_353 ) ) ;
V_18 &= ~ V_84 ;
V_18 |= ( V_358 << V_361 ) & V_84 ;
F_1 ( V_8 -> V_2 , F_147 ( V_353 ) , V_18 ) ;
}
static void * F_149 ( struct V_7 * V_8 ,
struct V_319 * V_324 ,
T_2 * V_14 ,
T_7 * V_344 ,
T_8 V_362 )
{
T_2 V_17 ;
void * V_4 ;
V_4 = F_115 ( V_324 ) ;
if ( ! V_4 )
return NULL ;
V_17 = F_150 ( V_8 -> V_253 -> V_253 . V_363 , V_4 ,
F_151 ( V_324 -> V_330 ) ,
V_345 ) ;
if ( F_152 ( F_153 ( V_8 -> V_253 -> V_253 . V_363 , V_17 ) ) ) {
F_119 ( V_324 , V_4 ) ;
return NULL ;
}
* V_14 = V_17 ;
* V_344 = F_154 ( V_4 ) ;
return V_4 ;
}
static inline T_1 F_155 ( T_1 V_364 , int V_320 )
{
T_1 V_365 ;
V_365 = V_364 & ~ ( 0xFF << V_366 ) ;
V_365 |= ( ( V_320 & 0xFF ) << V_366 ) ;
return V_365 ;
}
static inline void F_156 ( struct V_7 * V_8 , int V_320 ,
T_2 V_14 ,
T_7 V_344 )
{
int V_6 = F_134 () ;
if ( V_8 -> V_2 -> V_11 == V_337 ) {
T_1 V_18 = 0 ;
if ( sizeof( T_2 ) == 8 )
V_18 |= F_157 ( V_14 ) &
V_367 ;
if ( sizeof( T_7 ) == 8 )
V_18 |= ( F_157 ( V_344 )
<< V_368 ) &
V_369 ;
F_5 ( V_8 -> V_2 , V_6 ,
V_370 , V_18 ) ;
}
F_5 ( V_8 -> V_2 , V_6 ,
V_371 , V_344 ) ;
F_5 ( V_8 -> V_2 , V_6 ,
F_158 ( V_320 ) , V_14 ) ;
F_136 () ;
}
static void F_159 ( struct V_7 * V_8 , int V_320 ,
T_2 V_17 ,
T_7 V_335 )
{
F_156 ( V_8 , V_320 , V_17 , V_335 ) ;
}
static int F_160 ( struct V_7 * V_8 ,
struct V_319 * V_324 , int V_331 )
{
int V_46 , V_332 , V_372 ;
T_2 V_17 ;
T_7 V_335 ;
void * V_373 ;
V_332 = F_151 ( V_324 -> V_330 ) ;
V_372 = F_161 ( V_332 ) ;
if ( V_331 < 0 ||
( V_331 + V_324 -> V_331 > V_324 -> V_20 ) ) {
F_162 ( V_8 -> V_253 ,
L_4 ,
V_331 , V_324 -> V_42 ) ;
return 0 ;
}
for ( V_46 = 0 ; V_46 < V_331 ; V_46 ++ ) {
V_373 = F_149 ( V_8 , V_324 , & V_17 ,
& V_335 , V_117 ) ;
if ( ! V_373 )
break;
F_156 ( V_8 , V_324 -> V_42 , V_17 ,
V_335 ) ;
}
V_324 -> V_331 += V_46 ;
F_163 ( V_8 -> V_253 ,
L_5 ,
V_324 -> type == V_374 ? L_6 : L_7 ,
V_324 -> V_42 , V_324 -> V_330 , V_332 , V_372 ) ;
F_163 ( V_8 -> V_253 ,
L_8 ,
V_324 -> type == V_374 ? L_6 : L_7 ,
V_324 -> V_42 , V_46 , V_331 ) ;
return V_46 ;
}
static struct V_319 *
F_164 ( struct V_7 * V_8 , int V_320 , enum V_375 type ,
int V_330 )
{
struct V_319 * V_376 = & V_8 -> V_2 -> V_349 [ V_320 ] ;
int V_377 ;
if ( V_376 -> type != V_329 && V_376 -> type != type ) {
F_162 ( V_8 -> V_253 , L_9 ) ;
return NULL ;
}
if ( V_376 -> type == V_329 )
V_376 -> type = type ;
if ( ( ( type == V_378 ) && ( V_330 > V_376 -> V_330 ) ) ||
( V_376 -> V_330 == 0 ) ) {
int V_379 ;
V_379 = V_376 -> V_331 ;
if ( V_379 == 0 )
V_379 = type == V_378 ?
V_380 :
V_381 ;
else
F_137 ( V_8 -> V_253 -> V_253 . V_363 ,
V_8 -> V_2 , V_376 ) ;
V_376 -> V_330 = V_330 ;
V_376 -> V_321 =
F_165 ( F_151 ( V_330 ) ) +
V_382 ;
V_377 = F_160 ( V_8 , V_376 , V_379 ) ;
if ( V_377 != V_379 ) {
F_141 ( 1 , L_10 ,
V_376 -> V_42 , V_377 , V_379 ) ;
return NULL ;
}
}
F_130 ( V_8 -> V_2 , V_376 ,
F_151 ( V_376 -> V_330 ) ) ;
return V_376 ;
}
static int F_166 ( struct V_7 * V_8 )
{
int V_383 ;
if ( ! V_8 -> V_384 ) {
V_8 -> V_384 =
F_164 ( V_8 , F_167 ( V_8 -> V_42 ) ,
V_378 ,
V_8 -> V_330 ) ;
if ( ! V_8 -> V_384 )
return - V_167 ;
V_8 -> V_384 -> V_164 |= ( 1 << V_8 -> V_42 ) ;
for ( V_383 = 0 ; V_383 < V_385 ; V_383 ++ )
F_146 ( V_8 , V_383 , V_8 -> V_384 -> V_42 ) ;
}
if ( ! V_8 -> V_386 ) {
V_8 -> V_386 =
F_164 ( V_8 , V_387 ,
V_374 ,
V_388 ) ;
if ( ! V_8 -> V_386 )
return - V_167 ;
V_8 -> V_386 -> V_164 |= ( 1 << V_8 -> V_42 ) ;
for ( V_383 = 0 ; V_383 < V_385 ; V_383 ++ )
F_148 ( V_8 , V_383 ,
V_8 -> V_386 -> V_42 ) ;
}
return 0 ;
}
static int F_168 ( struct V_288 * V_253 , int V_389 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_319 * V_390 = V_8 -> V_384 ;
int V_377 , V_379 = V_390 -> V_331 ;
int V_330 = F_169 ( V_389 ) ;
F_137 ( V_253 -> V_253 . V_363 , V_8 -> V_2 , V_390 ) ;
if ( V_390 -> V_331 ) {
F_141 ( 1 , L_2 , V_390 -> V_42 ) ;
return - V_391 ;
}
V_390 -> V_330 = V_330 ;
V_390 -> V_321 = F_165 ( F_151 ( V_330 ) ) +
V_382 ;
V_377 = F_160 ( V_8 , V_390 , V_379 ) ;
if ( V_377 != V_379 ) {
F_141 ( 1 , L_10 ,
V_390 -> V_42 , V_377 , V_379 ) ;
return - V_391 ;
}
F_130 ( V_8 -> V_2 , V_390 ,
F_151 ( V_390 -> V_330 ) ) ;
V_253 -> V_389 = V_389 ;
F_170 ( V_253 ) ;
return 0 ;
}
static inline void F_171 ( struct V_7 * V_8 )
{
int V_6 , V_392 = 0 ;
F_172 (cpu)
V_392 |= 1 << V_6 ;
F_1 ( V_8 -> V_2 , F_173 ( V_8 -> V_42 ) ,
F_174 ( V_392 ) ) ;
}
static inline void F_175 ( struct V_7 * V_8 )
{
int V_6 , V_392 = 0 ;
F_172 (cpu)
V_392 |= 1 << V_6 ;
F_1 ( V_8 -> V_2 , F_173 ( V_8 -> V_42 ) ,
F_176 ( V_392 ) ) ;
}
static void F_177 ( void * V_393 )
{
struct V_7 * V_8 = V_393 ;
F_5 ( V_8 -> V_2 , F_178 () ,
F_179 ( V_8 -> V_42 ) , 0 ) ;
}
static void F_180 ( void * V_393 )
{
struct V_7 * V_8 = V_393 ;
F_5 ( V_8 -> V_2 , F_178 () ,
F_179 ( V_8 -> V_42 ) ,
( V_394 |
V_395 ) ) ;
}
static void F_181 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_396 == 0 ) {
V_18 = F_4 ( V_8 -> V_397 + V_398 ) ;
V_18 &= ~ V_399 ;
V_18 |= V_400 ;
F_2 ( V_18 , V_8 -> V_397 + V_398 ) ;
}
V_18 = F_4 ( V_8 -> V_397 + V_401 ) ;
if ( V_8 -> V_402 == V_403 )
V_18 |= V_404 ;
else
V_18 &= ~ V_404 ;
V_18 &= ~ V_405 ;
V_18 |= V_406 ;
V_18 |= V_407 ;
F_2 ( V_18 , V_8 -> V_397 + V_401 ) ;
}
static void F_182 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_2 -> V_11 == V_337 )
F_181 ( V_8 ) ;
V_18 = F_4 ( V_8 -> V_397 + V_408 ) ;
switch ( V_8 -> V_402 ) {
case V_409 :
V_18 |= V_410 ;
break;
case V_403 :
V_18 |= V_411 ;
default:
V_18 &= ~ V_412 ;
}
F_2 ( V_18 , V_8 -> V_397 + V_408 ) ;
}
static void F_183 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_413 ) ;
V_18 |= V_414 ;
F_2 ( V_18 , V_8 -> V_397 + V_413 ) ;
}
static void F_184 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_415 ) ;
V_18 |= V_416 ;
V_18 |= V_417 ;
F_2 ( V_18 , V_8 -> V_397 + V_415 ) ;
}
static void F_185 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_415 ) ;
V_18 &= ~ ( V_416 ) ;
F_2 ( V_18 , V_8 -> V_397 + V_415 ) ;
}
static void F_186 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_418 ) &
~ V_419 ;
F_2 ( V_18 , V_8 -> V_397 + V_418 ) ;
}
static void F_187 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_418 ) ;
if ( V_8 -> V_420 == 1000 )
V_18 |= V_421 ;
else
V_18 &= ~ V_421 ;
if ( V_8 -> V_402 == V_409 )
V_18 |= V_422 ;
else
V_18 &= ~ V_422 ;
F_2 ( V_18 , V_8 -> V_397 + V_418 ) ;
}
static void F_188 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_408 ) &
~ V_423 ;
F_2 ( V_18 , V_8 -> V_397 + V_408 ) ;
while ( F_4 ( V_8 -> V_397 + V_408 ) &
V_423 )
continue;
}
static inline void F_189 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_415 ) ;
V_18 &= ~ V_424 ;
V_18 |= ( ( ( V_8 -> V_330 - V_214 ) / 2 ) <<
V_425 ) ;
F_2 ( V_18 , V_8 -> V_397 + V_415 ) ;
}
static void F_190 ( struct V_7 * V_8 )
{
int V_426 , V_18 , V_427 , V_428 , V_351 ;
if ( V_8 -> V_2 -> V_11 == V_12 ) {
if ( V_8 -> V_429 & V_430 )
F_187 ( V_8 ) ;
V_18 = F_4 ( V_8 -> V_397 + V_431 ) ;
V_18 &= ~ V_432 ;
V_18 |= F_191 ( 64 - 4 - 2 ) ;
F_2 ( V_18 , V_8 -> V_397 + V_431 ) ;
}
V_426 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_433 ,
V_426 ) ;
F_1 ( V_8 -> V_2 , V_434 , 0 ) ;
for ( V_427 = 0 ; V_427 < V_43 ; V_427 ++ ) {
V_428 = F_23 ( V_8 -> V_42 , V_427 ) ;
F_1 ( V_8 -> V_2 ,
F_192 ( V_428 ) , 0 ) ;
}
F_1 ( V_8 -> V_2 , V_435 ,
V_8 -> V_2 -> V_436 / V_437 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_438 ) ;
V_18 &= ~ V_439 ;
V_18 |= F_193 ( 1 ) ;
V_18 |= V_440 ;
F_1 ( V_8 -> V_2 , V_438 , V_18 ) ;
V_18 = V_441 ;
F_1 ( V_8 -> V_2 , V_442 , V_18 ) ;
F_1 ( V_8 -> V_2 , F_194 ( V_8 -> V_42 ) ,
V_443 |
F_195 ( 256 ) ) ;
for ( V_351 = 0 ; V_351 < V_385 ; V_351 ++ ) {
V_427 = V_8 -> V_354 [ V_351 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_427 ) ) ;
V_18 |= V_444 |
V_445 ;
F_1 ( V_8 -> V_2 , F_147 ( V_427 ) , V_18 ) ;
}
F_175 ( V_8 ) ;
}
static void F_196 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_351 , V_427 ;
for ( V_351 = 0 ; V_351 < V_385 ; V_351 ++ ) {
V_427 = V_8 -> V_354 [ V_351 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_427 ) ) ;
V_18 &= ~ V_446 ;
F_1 ( V_8 -> V_2 , F_147 ( V_427 ) , V_18 ) ;
}
}
static void F_197 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_351 , V_427 ;
for ( V_351 = 0 ; V_351 < V_385 ; V_351 ++ ) {
V_427 = V_8 -> V_354 [ V_351 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_427 ) ) ;
V_18 |= V_446 ;
F_1 ( V_8 -> V_2 , F_147 ( V_427 ) , V_18 ) ;
}
}
static void F_198 ( struct V_7 * V_8 )
{
T_1 V_447 ;
int V_427 ;
int V_426 = F_22 ( V_8 ) ;
V_447 = 0 ;
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
struct V_449 * V_21 = V_8 -> V_450 [ V_427 ] ;
if ( V_21 -> V_451 )
V_447 |= ( 1 << V_427 ) ;
}
F_1 ( V_8 -> V_2 , V_433 , V_426 ) ;
F_1 ( V_8 -> V_2 , V_452 , V_447 ) ;
}
static void F_199 ( struct V_7 * V_8 )
{
T_1 V_453 ;
int V_454 ;
int V_426 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_433 , V_426 ) ;
V_453 = ( F_3 ( V_8 -> V_2 , V_452 ) ) &
V_455 ;
if ( V_453 != 0 )
F_1 ( V_8 -> V_2 , V_452 ,
( V_453 << V_456 ) ) ;
V_454 = 0 ;
do {
if ( V_454 >= V_457 ) {
F_200 ( V_8 -> V_253 ,
L_11 ,
V_453 ) ;
break;
}
F_201 ( 1 ) ;
V_454 ++ ;
V_453 = F_3 ( V_8 -> V_2 , V_452 ) ;
} while ( V_453 & V_455 );
}
static inline int
F_202 ( struct V_7 * V_8 , int V_458 )
{
T_1 V_18 = F_3 ( V_8 -> V_2 , F_203 ( V_458 ) ) ;
return V_18 & V_459 ;
}
static inline void
F_204 ( struct V_7 * V_8 , int V_458 ,
int V_460 , int V_461 )
{
T_1 V_18 = V_460 | ( V_461 << V_462 ) ;
F_1 ( V_8 -> V_2 , F_205 ( V_458 ) , V_18 ) ;
}
static inline struct V_25 *
F_206 ( struct V_463 * V_383 )
{
int V_26 = V_383 -> V_464 ;
V_383 -> V_464 = F_207 ( V_383 , V_26 ) ;
F_208 ( V_383 -> V_451 + V_383 -> V_464 ) ;
return V_383 -> V_451 + V_26 ;
}
static void F_209 ( struct V_7 * V_8 ,
int V_353 , int V_3 )
{
T_1 V_18 ;
V_3 = V_3 >> 5 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_353 ) ) ;
V_18 &= ~ V_465 ;
V_18 |= ( ( V_3 << V_466 ) &
V_465 ) ;
F_1 ( V_8 -> V_2 , F_147 ( V_353 ) , V_18 ) ;
}
static struct V_9 *
F_210 ( struct V_449 * V_21 )
{
int V_10 = V_21 -> V_464 ;
V_21 -> V_464 = F_207 ( V_21 , V_10 ) ;
return V_21 -> V_451 + V_10 ;
}
static void F_211 ( struct V_7 * V_8 , int V_467 )
{
F_5 ( V_8 -> V_2 , F_178 () ,
V_468 , V_467 ) ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_449 * V_469 , int V_377 )
{
if ( ( V_469 -> V_470 + V_377 ) > V_469 -> V_20 ) {
int V_6 = F_178 () ;
T_1 V_18 = F_3 ( V_2 , F_213 ( V_6 ) ) ;
V_469 -> V_470 = V_18 & V_471 ;
}
if ( ( V_469 -> V_470 + V_377 ) > V_469 -> V_20 )
return - V_167 ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 ,
struct V_449 * V_21 , int V_377 )
{
T_1 V_18 ;
int V_6 = F_178 () ;
V_18 = ( V_21 -> V_42 << V_472 ) | V_377 ;
F_5 ( V_2 , V_6 , V_473 , V_18 ) ;
V_18 = F_6 ( V_2 , V_6 , V_474 ) ;
return V_18 & V_475 ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_449 * V_21 ,
struct V_31 * V_32 ,
int V_377 )
{
int V_476 , V_6 , V_477 ;
if ( V_32 -> V_478 >= V_377 )
return 0 ;
V_477 = 0 ;
F_172 (cpu) {
struct V_31 * V_479 ;
V_479 = F_216 ( V_21 -> V_480 , V_6 ) ;
V_477 += V_479 -> V_470 ;
V_477 += V_479 -> V_478 ;
}
V_476 = F_217 ( V_481 , V_377 - V_32 -> V_478 ) ;
V_477 += V_476 ;
if ( V_477 >
( V_21 -> V_20 - ( F_218 () * V_481 ) ) )
return - V_167 ;
V_32 -> V_478 += F_214 ( V_2 , V_21 , V_476 ) ;
if ( V_32 -> V_478 < V_377 )
return - V_167 ;
return 0 ;
}
static void F_219 ( struct V_449 * V_21 )
{
if ( V_21 -> V_464 == 0 )
V_21 -> V_464 = V_21 -> V_482 - 1 ;
else
V_21 -> V_464 -- ;
}
static T_1 F_220 ( int V_483 , int V_484 ,
int V_485 , int V_486 )
{
T_1 V_23 ;
V_23 = ( V_483 << V_487 ) ;
V_23 |= ( V_485 << V_488 ) ;
V_23 |= V_489 ;
if ( V_484 == F_66 ( V_238 ) ) {
V_23 &= ~ V_489 ;
V_23 &= ~ V_490 ;
} else {
V_23 |= V_490 ;
}
if ( V_486 == V_178 ) {
V_23 &= ~ V_491 ;
V_23 &= ~ V_492 ;
} else if ( V_486 == V_179 ) {
V_23 |= V_491 ;
V_23 &= ~ V_492 ;
} else {
V_23 |= V_493 ;
}
return V_23 ;
}
static inline int F_221 ( struct V_7 * V_8 ,
struct V_449 * V_21 )
{
T_1 V_18 ;
V_18 = F_6 ( V_8 -> V_2 , F_178 () ,
F_222 ( V_21 -> V_42 ) ) ;
return ( V_18 & V_494 ) >>
V_495 ;
}
static void F_223 ( void * V_393 )
{
struct V_7 * V_8 = V_393 ;
int V_427 ;
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
int V_42 = V_8 -> V_450 [ V_427 ] -> V_42 ;
F_6 ( V_8 -> V_2 , F_178 () ,
F_222 ( V_42 ) ) ;
}
}
static void F_224 ( struct V_7 * V_8 )
{
T_1 V_18 , V_20 , V_389 ;
int V_21 , V_426 ;
V_389 = V_8 -> V_330 * 8 ;
if ( V_389 > V_496 )
V_389 = V_496 ;
V_389 = 3 * V_389 ;
V_426 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_433 , V_426 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_497 ) ;
V_18 &= ~ V_496 ;
V_18 |= V_389 ;
F_1 ( V_8 -> V_2 , V_497 , V_18 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_442 ) ;
V_20 = V_18 & V_441 ;
if ( V_20 < V_389 ) {
V_20 = V_389 ;
V_18 &= ~ V_441 ;
V_18 |= V_20 ;
F_1 ( V_8 -> V_2 , V_442 , V_18 ) ;
}
for ( V_21 = 0 ; V_21 < V_448 ; V_21 ++ ) {
V_18 = F_3 ( V_8 -> V_2 ,
F_225 ( V_21 ) ) ;
V_20 = V_18 & V_498 ;
if ( V_20 < V_389 ) {
V_20 = V_389 ;
V_18 &= ~ V_498 ;
V_18 |= V_20 ;
F_1 ( V_8 -> V_2 ,
F_225 ( V_21 ) ,
V_18 ) ;
}
}
}
static void F_226 ( struct V_7 * V_8 ,
struct V_463 * V_383 )
{
int V_6 = F_134 () ;
if ( V_383 -> V_499 > V_500 )
V_383 -> V_499 = V_500 ;
F_5 ( V_8 -> V_2 , V_6 , V_501 , V_383 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_502 ,
V_383 -> V_499 ) ;
F_136 () ;
}
static T_1 F_227 ( T_1 V_503 , unsigned long V_504 )
{
T_3 V_505 = ( T_3 ) V_504 * V_503 ;
F_228 ( V_505 , V_437 ) ;
return V_505 > V_506 ? V_506 : V_505 ;
}
static T_1 F_229 ( T_1 V_507 , unsigned long V_504 )
{
T_3 V_505 = ( T_3 ) V_507 * V_437 ;
F_228 ( V_505 , V_504 ) ;
return V_505 > V_506 ? V_506 : V_505 ;
}
static void F_230 ( struct V_7 * V_8 ,
struct V_463 * V_383 )
{
unsigned long V_508 = V_8 -> V_2 -> V_436 ;
T_1 V_18 = F_227 ( V_383 -> V_509 , V_508 ) ;
if ( V_18 > V_510 ) {
V_383 -> V_509 =
F_229 ( V_510 , V_508 ) ;
V_18 = F_227 ( V_383 -> V_509 , V_508 ) ;
}
F_1 ( V_8 -> V_2 , F_231 ( V_383 -> V_42 ) , V_18 ) ;
}
static void F_232 ( struct V_7 * V_8 ,
struct V_449 * V_21 ,
struct V_31 * V_32 , int V_377 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_377 ; V_46 ++ ) {
struct V_36 * V_37 =
V_32 -> V_38 + V_32 -> V_33 ;
F_138 ( V_8 -> V_253 -> V_253 . V_363 , V_37 -> V_40 ,
V_37 -> V_20 , V_511 ) ;
if ( V_37 -> V_35 )
F_233 ( V_37 -> V_35 ) ;
F_20 ( V_32 ) ;
}
}
static inline struct V_463 * F_234 ( struct V_7 * V_8 ,
T_1 V_512 )
{
int V_427 = F_235 ( V_512 ) - 1 ;
return V_8 -> V_354 [ V_427 ] ;
}
static inline struct V_449 * F_236 ( struct V_7 * V_8 ,
T_1 V_512 )
{
int V_427 = F_235 ( V_512 ) - 1 ;
return V_8 -> V_450 [ V_427 ] ;
}
static void F_237 ( struct V_7 * V_8 , struct V_449 * V_21 ,
struct V_31 * V_32 )
{
struct V_513 * V_514 = F_238 ( V_8 -> V_253 , V_21 -> V_515 ) ;
int V_516 ;
if ( V_32 -> V_6 != F_178 () )
F_162 ( V_8 -> V_253 , L_12 ) ;
V_516 = F_221 ( V_8 , V_21 ) ;
if ( ! V_516 )
return;
F_232 ( V_8 , V_21 , V_32 , V_516 ) ;
V_32 -> V_470 -= V_516 ;
if ( F_239 ( V_514 ) )
if ( V_32 -> V_20 - V_32 -> V_470 >= V_517 + 1 )
F_240 ( V_514 ) ;
}
static unsigned int F_241 ( struct V_7 * V_8 , T_1 V_512 )
{
struct V_449 * V_21 ;
struct V_31 * V_32 ;
unsigned int V_518 = 0 ;
while ( V_512 ) {
V_21 = F_236 ( V_8 , V_512 ) ;
if ( ! V_21 )
break;
V_32 = F_242 ( V_21 -> V_480 ) ;
if ( V_32 -> V_470 ) {
F_237 ( V_8 , V_21 , V_32 ) ;
V_518 += V_32 -> V_470 ;
}
V_512 &= ~ ( 1 << V_21 -> V_515 ) ;
}
return V_518 ;
}
static int F_243 ( struct V_250 * V_251 ,
struct V_449 * V_469 ,
int V_519 , int V_6 ,
struct V_1 * V_2 )
{
T_1 V_520 ;
V_469 -> V_451 = F_123 ( & V_251 -> V_253 ,
V_519 * V_521 ,
& V_469 -> V_522 , V_117 ) ;
if ( ! V_469 -> V_451 )
return - V_167 ;
V_469 -> V_482 = V_469 -> V_20 - 1 ;
V_469 -> V_464 = F_3 ( V_2 ,
F_244 ( V_6 ) ) ;
if ( V_2 -> V_11 == V_12 )
V_520 = V_469 -> V_522 ;
else
V_520 = V_469 -> V_522 >>
V_523 ;
F_1 ( V_2 , F_245 ( V_6 ) , V_520 ) ;
F_1 ( V_2 , F_246 ( V_6 ) , V_519 ) ;
return 0 ;
}
static int F_247 ( struct V_7 * V_8 ,
struct V_463 * V_383 )
{
T_1 V_524 ;
int V_6 ;
V_383 -> V_20 = V_8 -> V_525 ;
V_383 -> V_451 = F_123 ( V_8 -> V_253 -> V_253 . V_363 ,
V_383 -> V_20 * V_521 ,
& V_383 -> V_522 , V_117 ) ;
if ( ! V_383 -> V_451 )
return - V_167 ;
V_383 -> V_482 = V_383 -> V_20 - 1 ;
F_1 ( V_8 -> V_2 , F_203 ( V_383 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_501 , V_383 -> V_42 ) ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_524 = V_383 -> V_522 ;
else
V_524 = V_383 -> V_522 >> V_526 ;
F_5 ( V_8 -> V_2 , V_6 , V_527 , V_524 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_528 , V_383 -> V_20 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_529 , 0 ) ;
F_136 () ;
F_209 ( V_8 , V_383 -> V_42 , V_530 ) ;
F_226 ( V_8 , V_383 ) ;
F_230 ( V_8 , V_383 ) ;
F_204 ( V_8 , V_383 -> V_42 , 0 , V_383 -> V_20 ) ;
return 0 ;
}
static void F_248 ( struct V_7 * V_8 ,
struct V_463 * V_383 )
{
int V_531 , V_46 ;
V_531 = F_202 ( V_8 , V_383 -> V_42 ) ;
if ( ! V_531 )
return;
for ( V_46 = 0 ; V_46 < V_531 ; V_46 ++ ) {
struct V_25 * V_26 = F_206 ( V_383 ) ;
T_1 V_30 = F_19 ( V_8 , V_26 ) ;
int V_320 ;
V_320 = ( V_30 & V_532 ) >>
V_533 ;
F_159 ( V_8 , V_320 ,
F_16 ( V_8 , V_26 ) ,
F_17 ( V_8 , V_26 ) ) ;
}
F_204 ( V_8 , V_383 -> V_42 , V_531 , V_531 ) ;
}
static void F_249 ( struct V_7 * V_8 ,
struct V_463 * V_383 )
{
int V_6 ;
F_248 ( V_8 , V_383 ) ;
if ( V_383 -> V_451 )
F_124 ( V_8 -> V_253 -> V_253 . V_363 ,
V_383 -> V_20 * V_521 ,
V_383 -> V_451 ,
V_383 -> V_522 ) ;
V_383 -> V_451 = NULL ;
V_383 -> V_482 = 0 ;
V_383 -> V_464 = 0 ;
V_383 -> V_522 = 0 ;
F_1 ( V_8 -> V_2 , F_203 ( V_383 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_501 , V_383 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_527 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_528 , 0 ) ;
F_136 () ;
}
static int F_250 ( struct V_7 * V_8 ,
struct V_449 * V_21 )
{
T_1 V_18 ;
int V_6 , V_534 , V_535 , V_426 ;
struct V_31 * V_32 ;
V_21 -> V_20 = V_8 -> V_536 ;
V_21 -> V_451 = F_123 ( V_8 -> V_253 -> V_253 . V_363 ,
V_21 -> V_20 * V_521 ,
& V_21 -> V_522 , V_117 ) ;
if ( ! V_21 -> V_451 )
return - V_167 ;
V_21 -> V_482 = V_21 -> V_20 - 1 ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_537 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_538 ,
V_21 -> V_522 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_539 ,
V_21 -> V_20 & V_540 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_541 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_542 ,
V_21 -> V_42 << V_543 ) ;
V_18 = F_6 ( V_8 -> V_2 , V_6 , V_544 ) ;
V_18 &= ~ V_545 ;
F_5 ( V_8 -> V_2 , V_6 , V_544 , V_18 ) ;
V_535 = 16 ;
V_534 = ( V_8 -> V_42 * V_43 * V_535 ) +
( V_21 -> V_515 * V_535 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_546 ,
F_251 ( V_534 ) | V_547 |
F_252 ( V_535 / 2 ) ) ;
F_136 () ;
V_426 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_433 , V_426 ) ;
V_18 = F_3 ( V_8 -> V_2 , F_253 ( V_21 -> V_515 ) ) ;
V_18 &= ~ V_548 ;
V_18 |= F_254 ( 1 ) ;
V_18 |= V_549 ;
F_1 ( V_8 -> V_2 , F_253 ( V_21 -> V_515 ) , V_18 ) ;
V_18 = V_498 ;
F_1 ( V_8 -> V_2 , F_225 ( V_21 -> V_515 ) ,
V_18 ) ;
F_172 (cpu) {
V_32 = F_216 ( V_21 -> V_480 , V_6 ) ;
V_32 -> V_20 = V_21 -> V_20 ;
V_32 -> V_38 = F_255 ( V_32 -> V_20 ,
sizeof( * V_32 -> V_38 ) ,
V_117 ) ;
if ( ! V_32 -> V_38 )
goto V_550;
V_32 -> V_470 = 0 ;
V_32 -> V_478 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> V_33 = 0 ;
}
return 0 ;
V_550:
F_172 (cpu) {
V_32 = F_216 ( V_21 -> V_480 , V_6 ) ;
F_57 ( V_32 -> V_38 ) ;
}
F_124 ( V_8 -> V_253 -> V_253 . V_363 ,
V_21 -> V_20 * V_521 ,
V_21 -> V_451 , V_21 -> V_522 ) ;
return - V_167 ;
}
static void F_256 ( struct V_7 * V_8 ,
struct V_449 * V_21 )
{
struct V_31 * V_32 ;
int V_6 ;
F_172 (cpu) {
V_32 = F_216 ( V_21 -> V_480 , V_6 ) ;
F_57 ( V_32 -> V_38 ) ;
}
if ( V_21 -> V_451 )
F_124 ( V_8 -> V_253 -> V_253 . V_363 ,
V_21 -> V_20 * V_521 ,
V_21 -> V_451 , V_21 -> V_522 ) ;
V_21 -> V_451 = NULL ;
V_21 -> V_482 = 0 ;
V_21 -> V_464 = 0 ;
V_21 -> V_522 = 0 ;
F_1 ( V_8 -> V_2 , F_192 ( V_21 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_537 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_538 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_539 , 0 ) ;
F_136 () ;
}
static void F_257 ( struct V_7 * V_8 , struct V_449 * V_21 )
{
struct V_31 * V_32 ;
int V_454 , V_467 , V_6 ;
T_1 V_18 ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_537 , V_21 -> V_42 ) ;
V_18 = F_6 ( V_8 -> V_2 , V_6 , V_546 ) ;
V_18 |= V_551 ;
F_5 ( V_8 -> V_2 , V_6 , V_546 , V_18 ) ;
V_454 = 0 ;
do {
if ( V_454 >= V_552 ) {
F_200 ( V_8 -> V_253 ,
L_13 ,
V_8 -> V_42 , V_21 -> V_515 ) ;
break;
}
F_201 ( 1 ) ;
V_454 ++ ;
V_467 = F_6 ( V_8 -> V_2 , V_6 ,
V_544 ) ;
V_467 &= V_545 ;
} while ( V_467 );
V_18 &= ~ V_551 ;
F_5 ( V_8 -> V_2 , V_6 , V_546 , V_18 ) ;
F_136 () ;
F_172 (cpu) {
V_32 = F_216 ( V_21 -> V_480 , V_6 ) ;
F_232 ( V_8 , V_21 , V_32 , V_32 -> V_470 ) ;
V_32 -> V_470 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> V_33 = 0 ;
}
}
static void F_258 ( struct V_7 * V_8 )
{
struct V_449 * V_21 ;
int V_427 ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_2 , V_553 ) ;
V_18 |= F_259 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_553 , V_18 ) ;
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
V_21 = V_8 -> V_450 [ V_427 ] ;
F_257 ( V_8 , V_21 ) ;
F_256 ( V_8 , V_21 ) ;
}
F_260 ( F_223 , V_8 , 1 ) ;
V_18 &= ~ F_259 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_553 , V_18 ) ;
}
static void F_261 ( struct V_7 * V_8 )
{
int V_427 ;
for ( V_427 = 0 ; V_427 < V_385 ; V_427 ++ )
F_249 ( V_8 , V_8 -> V_354 [ V_427 ] ) ;
}
static int F_262 ( struct V_7 * V_8 )
{
int V_427 , V_252 ;
for ( V_427 = 0 ; V_427 < V_385 ; V_427 ++ ) {
V_252 = F_247 ( V_8 , V_8 -> V_354 [ V_427 ] ) ;
if ( V_252 )
goto V_554;
}
return 0 ;
V_554:
F_261 ( V_8 ) ;
return V_252 ;
}
static int F_263 ( struct V_7 * V_8 )
{
struct V_449 * V_21 ;
int V_427 , V_252 ;
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
V_21 = V_8 -> V_450 [ V_427 ] ;
V_252 = F_250 ( V_8 , V_21 ) ;
if ( V_252 )
goto V_554;
}
F_260 ( F_223 , V_8 , 1 ) ;
return 0 ;
V_554:
F_258 ( V_8 ) ;
return V_252 ;
}
static T_9 F_264 ( int V_555 , void * V_556 )
{
struct V_7 * V_8 = (struct V_7 * ) V_556 ;
F_175 ( V_8 ) ;
F_265 ( & V_8 -> V_557 ) ;
return V_558 ;
}
static void F_266 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_559 * V_560 = V_253 -> V_560 ;
int V_561 = 0 ;
T_1 V_18 ;
if ( V_560 -> V_562 ) {
if ( ( V_8 -> V_420 != V_560 -> V_420 ) ||
( V_8 -> V_563 != V_560 -> V_563 ) ) {
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_397 + V_413 ) ;
V_18 &= ~ ( V_564 |
V_565 |
V_566 |
V_567 |
V_568 ) ;
if ( V_560 -> V_563 )
V_18 |= V_566 ;
if ( V_560 -> V_420 == V_569 )
V_18 |= V_565 ;
else if ( V_560 -> V_420 == V_570 )
V_18 |= V_564 ;
F_2 ( V_18 , V_8 -> V_397 + V_413 ) ;
V_8 -> V_563 = V_560 -> V_563 ;
V_8 -> V_420 = V_560 -> V_420 ;
}
}
if ( V_560 -> V_562 != V_8 -> V_562 ) {
if ( ! V_560 -> V_562 ) {
V_8 -> V_563 = - 1 ;
V_8 -> V_420 = 0 ;
}
V_8 -> V_562 = V_560 -> V_562 ;
V_561 = 1 ;
}
if ( V_561 ) {
if ( V_560 -> V_562 ) {
V_18 = F_4 ( V_8 -> V_397 + V_413 ) ;
V_18 |= ( V_571 |
V_572 ) ;
F_2 ( V_18 , V_8 -> V_397 + V_413 ) ;
F_198 ( V_8 ) ;
F_196 ( V_8 ) ;
} else {
F_197 ( V_8 ) ;
F_199 ( V_8 ) ;
}
F_267 ( V_560 ) ;
}
}
static void F_268 ( struct V_573 * V_574 )
{
T_10 V_575 ;
if ( ! V_574 -> V_576 ) {
V_574 -> V_576 = true ;
V_575 = V_577 ;
F_269 ( & V_574 -> V_578 , V_575 ,
V_579 ) ;
}
}
static void F_270 ( unsigned long V_4 )
{
struct V_288 * V_253 = (struct V_288 * ) V_4 ;
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_573 * V_574 = F_242 ( V_8 -> V_480 ) ;
unsigned int V_518 , V_512 ;
if ( ! F_271 ( V_253 ) )
return;
V_574 -> V_576 = false ;
V_512 = ( 1 << V_448 ) - 1 ;
V_518 = F_241 ( V_8 , V_512 ) ;
if ( V_518 )
F_268 ( V_574 ) ;
}
static enum V_580 F_272 ( struct V_581 * V_582 )
{
struct V_573 * V_574 = F_273 ( V_582 ,
struct V_573 ,
V_578 ) ;
F_274 ( & V_574 -> V_583 ) ;
return V_584 ;
}
static void F_275 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
T_1 V_30 = F_19 ( V_8 , V_26 ) ;
T_4 V_585 = F_18 ( V_8 , V_26 ) ;
switch ( V_30 & V_586 ) {
case V_587 :
F_162 ( V_8 -> V_253 , L_14 ,
V_30 , V_585 ) ;
break;
case V_588 :
F_162 ( V_8 -> V_253 , L_15 ,
V_30 , V_585 ) ;
break;
case V_589 :
F_162 ( V_8 -> V_253 , L_16 ,
V_30 , V_585 ) ;
break;
}
}
static void F_276 ( struct V_7 * V_8 , T_1 V_30 ,
struct V_34 * V_35 )
{
if ( ( ( V_30 & V_590 ) &&
! ( V_30 & V_591 ) ) ||
( V_30 & V_592 ) )
if ( ( ( V_30 & V_593 ) ||
( V_30 & V_594 ) ) &&
( V_30 & V_595 ) ) {
V_35 -> V_596 = 0 ;
V_35 -> V_597 = V_598 ;
return;
}
V_35 -> V_597 = V_599 ;
}
static int F_277 ( struct V_7 * V_8 ,
struct V_319 * V_324 , int V_320 )
{
T_2 V_17 ;
T_7 V_335 ;
void * V_373 ;
V_373 = F_149 ( V_8 , V_324 , & V_17 , & V_335 ,
V_323 ) ;
if ( ! V_373 )
return - V_167 ;
F_159 ( V_8 , V_320 , V_17 , V_335 ) ;
return 0 ;
}
static T_1 F_278 ( struct V_7 * V_8 , struct V_34 * V_35 )
{
if ( V_35 -> V_597 == V_600 ) {
int V_485 = 0 ;
T_6 V_486 ;
if ( V_35 -> V_601 == F_279 ( V_238 ) ) {
struct V_183 * V_602 = F_280 ( V_35 ) ;
V_485 = V_602 -> V_603 ;
V_486 = V_602 -> V_601 ;
} else if ( V_35 -> V_601 == F_279 ( V_245 ) ) {
struct V_202 * V_604 = F_281 ( V_35 ) ;
if ( F_282 ( V_35 ) > 0 )
V_485 = ( F_282 ( V_35 ) >> 2 ) ;
V_486 = V_604 -> V_605 ;
} else {
return V_493 ;
}
return F_220 ( F_283 ( V_35 ) ,
V_35 -> V_601 , V_485 , V_486 ) ;
}
return V_493 | V_489 ;
}
static int F_284 ( struct V_7 * V_8 , int V_606 ,
struct V_463 * V_383 )
{
struct V_288 * V_253 = V_8 -> V_253 ;
int V_531 ;
int V_607 = 0 ;
T_1 V_608 = 0 ;
T_1 V_609 = 0 ;
V_531 = F_202 ( V_8 , V_383 -> V_42 ) ;
if ( V_606 > V_531 )
V_606 = V_531 ;
while ( V_607 < V_606 ) {
struct V_25 * V_26 = F_206 ( V_383 ) ;
struct V_319 * V_324 ;
struct V_34 * V_35 ;
unsigned int V_321 ;
T_2 V_17 ;
T_7 V_335 ;
T_1 V_610 ;
int V_320 , V_611 , V_252 ;
void * V_4 ;
V_607 ++ ;
V_610 = F_19 ( V_8 , V_26 ) ;
V_611 = F_18 ( V_8 , V_26 ) ;
V_611 -= V_214 ;
V_17 = F_16 ( V_8 , V_26 ) ;
V_335 = F_17 ( V_8 , V_26 ) ;
V_4 = ( void * ) F_139 ( V_335 ) ;
V_320 = ( V_610 & V_532 ) >>
V_533 ;
V_324 = & V_8 -> V_2 -> V_349 [ V_320 ] ;
if ( V_610 & V_612 ) {
V_613:
V_253 -> V_614 . V_615 ++ ;
F_275 ( V_8 , V_26 ) ;
F_159 ( V_8 , V_320 , V_17 , V_335 ) ;
continue;
}
if ( V_324 -> V_321 > V_322 )
V_321 = 0 ;
else
V_321 = V_324 -> V_321 ;
V_35 = F_285 ( V_4 , V_321 ) ;
if ( ! V_35 ) {
F_200 ( V_8 -> V_253 , L_17 ) ;
goto V_613;
}
V_252 = F_277 ( V_8 , V_324 , V_320 ) ;
if ( V_252 ) {
F_162 ( V_8 -> V_253 , L_18 ) ;
goto V_613;
}
F_138 ( V_253 -> V_253 . V_363 , V_17 ,
V_324 -> V_332 , V_345 ) ;
V_608 ++ ;
V_609 += V_611 ;
F_286 ( V_35 , V_214 + V_530 ) ;
F_287 ( V_35 , V_611 ) ;
V_35 -> V_601 = F_288 ( V_35 , V_253 ) ;
F_276 ( V_8 , V_610 , V_35 ) ;
F_289 ( & V_8 -> V_557 , V_35 ) ;
}
if ( V_608 ) {
struct V_616 * V_614 = F_242 ( V_8 -> V_614 ) ;
F_290 ( & V_614 -> V_617 ) ;
V_614 -> V_618 += V_608 ;
V_614 -> V_611 += V_609 ;
F_291 ( & V_614 -> V_617 ) ;
}
F_292 () ;
F_204 ( V_8 , V_383 -> V_42 , V_607 , V_607 ) ;
return V_606 ;
}
static inline void
F_293 ( struct V_7 * V_8 , struct V_449 * V_21 ,
struct V_9 * V_534 )
{
T_2 V_14 =
F_7 ( V_8 , V_534 ) ;
T_4 V_619 =
F_10 ( V_8 , V_534 ) ;
F_138 ( V_8 -> V_253 -> V_253 . V_363 , V_14 ,
V_619 , V_511 ) ;
F_219 ( V_21 ) ;
}
static int F_294 ( struct V_7 * V_8 , struct V_34 * V_35 ,
struct V_449 * V_469 ,
struct V_449 * V_21 )
{
struct V_31 * V_32 = F_242 ( V_21 -> V_480 ) ;
struct V_9 * V_10 ;
int V_46 ;
T_2 V_14 ;
for ( V_46 = 0 ; V_46 < F_295 ( V_35 ) -> V_620 ; V_46 ++ ) {
T_11 * V_621 = & F_295 ( V_35 ) -> V_622 [ V_46 ] ;
void * V_623 = F_296 ( V_621 -> V_624 . V_625 ) + V_621 -> V_626 ;
V_10 = F_210 ( V_469 ) ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , V_621 -> V_20 ) ;
V_14 = F_150 ( V_8 -> V_253 -> V_253 . V_363 , V_623 ,
V_621 -> V_20 ,
V_511 ) ;
if ( F_153 ( V_8 -> V_253 -> V_253 . V_363 , V_14 ) ) {
F_219 ( V_21 ) ;
goto V_550;
}
F_14 ( V_8 , V_10 ,
V_14 & V_627 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_627 ) ;
if ( V_46 == ( F_295 ( V_35 ) -> V_620 - 1 ) ) {
F_13 ( V_8 , V_10 ,
V_628 ) ;
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
} else {
F_13 ( V_8 , V_10 , 0 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
}
}
return 0 ;
V_550:
for ( V_46 = V_46 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_10 = V_21 -> V_451 + V_46 ;
F_293 ( V_8 , V_21 , V_10 ) ;
}
return - V_167 ;
}
static int F_297 ( struct V_34 * V_35 , struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_449 * V_21 , * V_469 ;
struct V_31 * V_32 ;
struct V_9 * V_10 ;
T_2 V_14 ;
int V_622 = 0 ;
T_5 V_629 ;
T_1 V_630 ;
V_629 = F_298 ( V_35 ) ;
V_21 = V_8 -> V_450 [ V_629 ] ;
V_32 = F_242 ( V_21 -> V_480 ) ;
V_469 = & V_8 -> V_2 -> V_631 [ F_178 () ] ;
V_622 = F_295 ( V_35 ) -> V_620 + 1 ;
if ( F_212 ( V_8 -> V_2 , V_469 , V_622 ) ||
F_215 ( V_8 -> V_2 , V_21 ,
V_32 , V_622 ) ) {
V_622 = 0 ;
goto V_632;
}
V_10 = F_210 ( V_469 ) ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , F_299 ( V_35 ) ) ;
V_14 = F_150 ( V_253 -> V_253 . V_363 , V_35 -> V_4 ,
F_299 ( V_35 ) , V_511 ) ;
if ( F_152 ( F_153 ( V_253 -> V_253 . V_363 , V_14 ) ) ) {
F_219 ( V_21 ) ;
V_622 = 0 ;
goto V_632;
}
F_14 ( V_8 , V_10 ,
V_14 & V_627 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_627 ) ;
V_630 = F_278 ( V_8 , V_35 ) ;
if ( V_622 == 1 ) {
V_630 |= V_633 | V_628 ;
F_13 ( V_8 , V_10 , V_630 ) ;
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
} else {
V_630 |= V_633 | V_634 ;
F_13 ( V_8 , V_10 , V_630 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
if ( F_294 ( V_8 , V_35 , V_469 , V_21 ) ) {
F_293 ( V_8 , V_21 , V_10 ) ;
V_622 = 0 ;
goto V_632;
}
}
V_32 -> V_478 -= V_622 ;
V_32 -> V_470 += V_622 ;
V_469 -> V_470 += V_622 ;
F_292 () ;
F_211 ( V_8 , V_622 ) ;
if ( V_32 -> V_20 - V_32 -> V_470 < V_517 + 1 ) {
struct V_513 * V_514 = F_238 ( V_253 , V_629 ) ;
F_300 ( V_514 ) ;
}
V_632:
if ( V_622 > 0 ) {
struct V_616 * V_614 = F_242 ( V_8 -> V_614 ) ;
F_290 ( & V_614 -> V_617 ) ;
V_614 -> V_635 ++ ;
V_614 -> V_636 += V_35 -> V_283 ;
F_291 ( & V_614 -> V_617 ) ;
} else {
V_253 -> V_614 . V_637 ++ ;
F_233 ( V_35 ) ;
}
if ( V_32 -> V_470 >= V_21 -> V_638 )
F_237 ( V_8 , V_21 , V_32 ) ;
if ( V_32 -> V_470 <= V_622 && V_32 -> V_470 > 0 ) {
struct V_573 * V_574 = F_242 ( V_8 -> V_480 ) ;
F_268 ( V_574 ) ;
}
return V_639 ;
}
static inline void F_301 ( struct V_288 * V_253 , int V_512 )
{
if ( V_512 & V_640 )
F_162 ( V_253 , L_19 ) ;
if ( V_512 & V_641 )
F_162 ( V_253 , L_20 ) ;
if ( V_512 & V_642 )
F_162 ( V_253 , L_21 ) ;
}
static int F_302 ( struct V_643 * V_557 , int V_644 )
{
T_1 V_645 , V_646 , V_647 ;
int V_607 = 0 ;
struct V_7 * V_8 = F_101 ( V_557 -> V_253 ) ;
int V_6 = F_178 () ;
V_645 = F_6 ( V_8 -> V_2 , V_6 ,
F_303 ( V_8 -> V_42 ) ) ;
V_645 &= ~ V_648 ;
V_647 = V_645 & V_394 ;
if ( V_647 ) {
F_301 ( V_8 -> V_253 , V_647 ) ;
F_1 ( V_8 -> V_2 , V_649 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 ,
F_303 ( V_8 -> V_42 ) ,
V_645 & ~ V_394 ) ;
}
V_646 = V_645 & V_395 ;
V_646 |= V_8 -> V_650 ;
while ( V_646 && V_644 > 0 ) {
int V_470 ;
struct V_463 * V_383 ;
V_383 = F_234 ( V_8 , V_646 ) ;
if ( ! V_383 )
break;
V_470 = F_284 ( V_8 , V_644 , V_383 ) ;
V_607 += V_470 ;
V_644 -= V_470 ;
if ( V_644 > 0 ) {
V_646 &= ~ ( 1 << V_383 -> V_651 ) ;
}
}
if ( V_644 > 0 ) {
V_646 = 0 ;
F_304 ( V_557 , V_607 ) ;
F_171 ( V_8 ) ;
}
V_8 -> V_650 = V_646 ;
return V_607 ;
}
static void F_305 ( struct V_7 * V_8 )
{
struct V_288 * V_652 = V_8 -> V_253 ;
F_189 ( V_8 ) ;
F_224 ( V_8 ) ;
F_306 ( & V_8 -> V_557 ) ;
F_171 ( V_8 ) ;
F_184 ( V_8 ) ;
F_307 ( V_652 -> V_560 ) ;
F_308 ( V_8 -> V_253 ) ;
}
static void F_309 ( struct V_7 * V_8 )
{
struct V_288 * V_652 = V_8 -> V_253 ;
F_197 ( V_8 ) ;
F_201 ( 10 ) ;
F_175 ( V_8 ) ;
F_310 ( & V_8 -> V_557 ) ;
F_311 ( V_8 -> V_253 ) ;
F_312 ( V_8 -> V_253 ) ;
F_199 ( V_8 ) ;
F_185 ( V_8 ) ;
F_313 ( V_652 -> V_560 ) ;
}
static int F_314 ( struct V_288 * V_253 ,
struct V_653 * V_654 )
{
T_5 V_655 = V_654 -> V_656 ;
T_5 V_657 = V_654 -> V_658 ;
if ( V_654 -> V_656 == 0 || V_654 -> V_658 == 0 )
return - V_49 ;
if ( V_654 -> V_656 > V_659 )
V_655 = V_659 ;
else if ( ! F_122 ( V_654 -> V_656 , 16 ) )
V_655 = F_131 ( V_654 -> V_656 , 16 ) ;
if ( V_654 -> V_658 > V_660 )
V_657 = V_660 ;
else if ( ! F_122 ( V_654 -> V_658 , 32 ) )
V_657 = F_131 ( V_654 -> V_658 , 32 ) ;
if ( V_654 -> V_656 != V_655 ) {
F_315 ( V_253 , L_22 ,
V_654 -> V_656 , V_655 ) ;
V_654 -> V_656 = V_655 ;
}
if ( V_654 -> V_658 != V_657 ) {
F_315 ( V_253 , L_23 ,
V_654 -> V_658 , V_657 ) ;
V_654 -> V_658 = V_657 ;
}
return 0 ;
}
static void F_316 ( struct V_7 * V_8 , unsigned char * V_623 )
{
T_1 V_661 , V_662 , V_663 ;
V_661 = F_4 ( V_8 -> V_397 + V_418 ) ;
V_662 = F_4 ( V_8 -> V_2 -> V_664 + V_665 ) ;
V_663 = F_4 ( V_8 -> V_2 -> V_664 + V_666 ) ;
V_623 [ 0 ] = ( V_663 >> 24 ) & 0xFF ;
V_623 [ 1 ] = ( V_663 >> 16 ) & 0xFF ;
V_623 [ 2 ] = ( V_663 >> 8 ) & 0xFF ;
V_623 [ 3 ] = V_663 & 0xFF ;
V_623 [ 4 ] = V_662 & 0xFF ;
V_623 [ 5 ] = ( V_661 >> V_667 ) & 0xFF ;
}
static int F_317 ( struct V_7 * V_8 )
{
struct V_559 * V_668 ;
V_668 = F_318 ( V_8 -> V_253 , V_8 -> V_669 , F_266 , 0 ,
V_8 -> V_402 ) ;
if ( ! V_668 ) {
F_162 ( V_8 -> V_253 , L_24 ) ;
return - V_670 ;
}
V_668 -> V_671 &= V_672 ;
V_668 -> V_673 = V_668 -> V_671 ;
V_8 -> V_562 = 0 ;
V_8 -> V_563 = 0 ;
V_8 -> V_420 = 0 ;
return 0 ;
}
static void F_319 ( struct V_7 * V_8 )
{
struct V_288 * V_652 = V_8 -> V_253 ;
F_320 ( V_652 -> V_560 ) ;
}
static int F_321 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
unsigned char V_674 [ V_130 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_252 ;
V_252 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_674 , true ) ;
if ( V_252 ) {
F_162 ( V_253 , L_25 ) ;
return V_252 ;
}
V_252 = F_97 ( V_8 -> V_2 , V_8 -> V_42 ,
V_253 -> V_289 , true ) ;
if ( V_252 ) {
F_162 ( V_253 , L_26 ) ;
return V_252 ;
}
V_252 = F_104 ( V_8 -> V_2 , V_8 -> V_42 , V_293 ) ;
if ( V_252 ) {
F_162 ( V_253 , L_27 ) ;
return V_252 ;
}
V_252 = F_105 ( V_8 ) ;
if ( V_252 ) {
F_162 ( V_253 , L_28 ) ;
return V_252 ;
}
V_252 = F_262 ( V_8 ) ;
if ( V_252 ) {
F_162 ( V_8 -> V_253 , L_29 ) ;
return V_252 ;
}
V_252 = F_263 ( V_8 ) ;
if ( V_252 ) {
F_162 ( V_8 -> V_253 , L_30 ) ;
goto V_675;
}
V_252 = F_322 ( V_8 -> V_555 , F_264 , 0 , V_253 -> V_676 , V_8 ) ;
if ( V_252 ) {
F_162 ( V_8 -> V_253 , L_31 , V_8 -> V_555 ) ;
goto V_677;
}
F_311 ( V_8 -> V_253 ) ;
V_252 = F_317 ( V_8 ) ;
if ( V_252 < 0 )
goto V_678;
F_260 ( F_180 , V_8 , 1 ) ;
F_305 ( V_8 ) ;
return 0 ;
V_678:
F_323 ( V_8 -> V_555 , V_8 ) ;
V_677:
F_258 ( V_8 ) ;
V_675:
F_261 ( V_8 ) ;
return V_252 ;
}
static int F_324 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_573 * V_574 ;
int V_6 ;
F_309 ( V_8 ) ;
F_319 ( V_8 ) ;
F_260 ( F_177 , V_8 , 1 ) ;
F_323 ( V_8 -> V_555 , V_8 ) ;
F_172 (cpu) {
V_574 = F_216 ( V_8 -> V_480 , V_6 ) ;
F_325 ( & V_574 -> V_578 ) ;
V_574 -> V_576 = false ;
F_326 ( & V_574 -> V_583 ) ;
}
F_261 ( V_8 ) ;
F_258 ( V_8 ) ;
return 0 ;
}
static void F_327 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_679 * V_680 ;
int V_42 = V_8 -> V_42 ;
bool V_681 = V_253 -> V_429 & V_682 ;
F_61 ( V_2 , V_42 , V_253 -> V_429 & V_683 ) ;
F_62 ( V_2 , V_42 , V_133 , V_681 ) ;
F_62 ( V_2 , V_42 , V_216 , V_681 ) ;
F_103 ( V_2 , V_42 ) ;
if ( V_681 && ! F_328 ( V_253 ) ) {
F_329 (ha, dev)
F_97 ( V_2 , V_42 , V_680 -> V_623 , true ) ;
}
}
static int F_330 ( struct V_288 * V_253 , void * V_625 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
const struct V_684 * V_623 = V_625 ;
int V_252 ;
if ( ! F_331 ( V_623 -> V_685 ) ) {
V_252 = - V_686 ;
goto V_687;
}
if ( ! F_271 ( V_253 ) ) {
V_252 = F_100 ( V_253 , V_623 -> V_685 ) ;
if ( ! V_252 )
return 0 ;
V_252 = F_100 ( V_253 , V_253 -> V_289 ) ;
if ( V_252 )
goto V_687;
}
F_309 ( V_8 ) ;
V_252 = F_100 ( V_253 , V_623 -> V_685 ) ;
if ( ! V_252 )
goto V_688;
V_252 = F_100 ( V_253 , V_253 -> V_289 ) ;
if ( V_252 )
goto V_687;
V_688:
F_305 ( V_8 ) ;
F_198 ( V_8 ) ;
F_196 ( V_8 ) ;
return 0 ;
V_687:
F_162 ( V_253 , L_32 ) ;
return V_252 ;
}
static int F_332 ( struct V_288 * V_253 , int V_389 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
int V_252 ;
if ( ! F_122 ( F_169 ( V_389 ) , 8 ) ) {
F_315 ( V_253 , L_33 , V_389 ,
F_131 ( F_169 ( V_389 ) , 8 ) ) ;
V_389 = F_131 ( F_169 ( V_389 ) , 8 ) ;
}
if ( ! F_271 ( V_253 ) ) {
V_252 = F_168 ( V_253 , V_389 ) ;
if ( ! V_252 ) {
V_8 -> V_330 = F_169 ( V_389 ) ;
return 0 ;
}
V_252 = F_168 ( V_253 , V_253 -> V_389 ) ;
if ( V_252 )
goto V_687;
}
F_309 ( V_8 ) ;
V_252 = F_168 ( V_253 , V_389 ) ;
if ( ! V_252 ) {
V_8 -> V_330 = F_169 ( V_389 ) ;
goto V_688;
}
V_252 = F_168 ( V_253 , V_253 -> V_389 ) ;
if ( V_252 )
goto V_687;
V_688:
F_305 ( V_8 ) ;
F_198 ( V_8 ) ;
F_196 ( V_8 ) ;
return 0 ;
V_687:
F_162 ( V_253 , L_34 ) ;
return V_252 ;
}
static void
F_333 ( struct V_288 * V_253 , struct V_689 * V_614 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
unsigned int V_120 ;
int V_6 ;
F_334 (cpu) {
struct V_616 * V_690 ;
T_3 V_618 ;
T_3 V_611 ;
T_3 V_635 ;
T_3 V_636 ;
V_690 = F_216 ( V_8 -> V_614 , V_6 ) ;
do {
V_120 = F_335 ( & V_690 -> V_617 ) ;
V_618 = V_690 -> V_618 ;
V_611 = V_690 -> V_611 ;
V_635 = V_690 -> V_635 ;
V_636 = V_690 -> V_636 ;
} while ( F_336 ( & V_690 -> V_617 , V_120 ) );
V_614 -> V_618 += V_618 ;
V_614 -> V_611 += V_611 ;
V_614 -> V_635 += V_635 ;
V_614 -> V_636 += V_636 ;
}
V_614 -> V_615 = V_253 -> V_614 . V_615 ;
V_614 -> V_691 = V_253 -> V_614 . V_691 ;
V_614 -> V_637 = V_253 -> V_614 . V_637 ;
}
static int F_337 ( struct V_288 * V_253 , struct V_692 * V_693 , int V_694 )
{
int V_166 ;
if ( ! V_253 -> V_560 )
return - V_695 ;
V_166 = F_338 ( V_253 -> V_560 , V_693 , V_694 ) ;
if ( ! V_166 )
F_266 ( V_253 ) ;
return V_166 ;
}
static int F_339 ( struct V_288 * V_253 ,
struct V_696 * V_697 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
int V_427 ;
for ( V_427 = 0 ; V_427 < V_385 ; V_427 ++ ) {
struct V_463 * V_383 = V_8 -> V_354 [ V_427 ] ;
V_383 -> V_509 = V_697 -> V_698 ;
V_383 -> V_499 = V_697 -> V_699 ;
F_226 ( V_8 , V_383 ) ;
F_230 ( V_8 , V_383 ) ;
}
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
struct V_449 * V_21 = V_8 -> V_450 [ V_427 ] ;
V_21 -> V_638 = V_697 -> V_700 ;
}
return 0 ;
}
static int F_340 ( struct V_288 * V_253 ,
struct V_696 * V_697 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
V_697 -> V_698 = V_8 -> V_354 [ 0 ] -> V_509 ;
V_697 -> V_699 = V_8 -> V_354 [ 0 ] -> V_499 ;
V_697 -> V_700 = V_8 -> V_450 [ 0 ] -> V_638 ;
return 0 ;
}
static void F_341 ( struct V_288 * V_253 ,
struct V_701 * V_702 )
{
F_342 ( V_702 -> V_703 , V_704 ,
sizeof( V_702 -> V_703 ) ) ;
F_342 ( V_702 -> V_705 , V_706 ,
sizeof( V_702 -> V_705 ) ) ;
F_342 ( V_702 -> V_707 , F_343 ( & V_253 -> V_253 ) ,
sizeof( V_702 -> V_707 ) ) ;
}
static void F_344 ( struct V_288 * V_253 ,
struct V_653 * V_654 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
V_654 -> V_708 = V_659 ;
V_654 -> V_709 = V_660 ;
V_654 -> V_656 = V_8 -> V_525 ;
V_654 -> V_658 = V_8 -> V_536 ;
}
static int F_345 ( struct V_288 * V_253 ,
struct V_653 * V_654 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
T_5 V_710 = V_8 -> V_525 ;
T_5 V_711 = V_8 -> V_536 ;
int V_252 ;
V_252 = F_314 ( V_253 , V_654 ) ;
if ( V_252 )
return V_252 ;
if ( ! F_271 ( V_253 ) ) {
V_8 -> V_525 = V_654 -> V_656 ;
V_8 -> V_536 = V_654 -> V_658 ;
return 0 ;
}
F_309 ( V_8 ) ;
F_261 ( V_8 ) ;
F_258 ( V_8 ) ;
V_8 -> V_525 = V_654 -> V_656 ;
V_8 -> V_536 = V_654 -> V_658 ;
V_252 = F_262 ( V_8 ) ;
if ( V_252 ) {
V_8 -> V_525 = V_710 ;
V_654 -> V_656 = V_710 ;
V_252 = F_262 ( V_8 ) ;
if ( V_252 )
goto V_712;
}
V_252 = F_263 ( V_8 ) ;
if ( V_252 ) {
V_8 -> V_536 = V_711 ;
V_654 -> V_658 = V_711 ;
V_252 = F_263 ( V_8 ) ;
if ( V_252 )
goto V_713;
}
F_305 ( V_8 ) ;
F_198 ( V_8 ) ;
F_196 ( V_8 ) ;
return 0 ;
V_713:
F_261 ( V_8 ) ;
V_712:
F_162 ( V_253 , L_35 ) ;
return V_252 ;
}
static int F_346 ( struct V_7 * V_8 )
{
struct V_334 * V_253 = V_8 -> V_253 -> V_253 . V_363 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_31 * V_32 ;
int V_427 , V_6 , V_252 ;
if ( V_8 -> V_314 + V_385 >
V_209 * V_2 -> V_714 )
return - V_49 ;
F_199 ( V_8 ) ;
F_185 ( V_8 ) ;
V_8 -> V_450 = F_90 ( V_253 , V_448 , sizeof( * V_8 -> V_450 ) ,
V_117 ) ;
if ( ! V_8 -> V_450 )
return - V_167 ;
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
int V_715 = F_23 ( V_8 -> V_42 , V_427 ) ;
struct V_449 * V_21 ;
V_21 = F_347 ( V_253 , sizeof( * V_21 ) , V_117 ) ;
if ( ! V_21 ) {
V_252 = - V_167 ;
goto V_716;
}
V_21 -> V_480 = F_348 ( struct V_31 ) ;
if ( ! V_21 -> V_480 ) {
V_252 = - V_167 ;
goto V_716;
}
V_21 -> V_42 = V_715 ;
V_21 -> V_515 = V_427 ;
V_21 -> V_638 = V_717 ;
F_172 (cpu) {
V_32 = F_216 ( V_21 -> V_480 , V_6 ) ;
V_32 -> V_6 = V_6 ;
}
V_8 -> V_450 [ V_427 ] = V_21 ;
}
V_8 -> V_354 = F_90 ( V_253 , V_385 , sizeof( * V_8 -> V_354 ) ,
V_117 ) ;
if ( ! V_8 -> V_354 ) {
V_252 = - V_167 ;
goto V_716;
}
for ( V_427 = 0 ; V_427 < V_385 ; V_427 ++ ) {
struct V_463 * V_383 ;
V_383 = F_347 ( V_253 , sizeof( * V_383 ) , V_117 ) ;
if ( ! V_383 ) {
V_252 = - V_167 ;
goto V_716;
}
V_383 -> V_42 = V_8 -> V_314 + V_427 ;
V_383 -> V_8 = V_8 -> V_42 ;
V_383 -> V_651 = V_427 ;
V_8 -> V_354 [ V_427 ] = V_383 ;
}
if ( V_2 -> V_11 == V_12 ) {
F_1 ( V_2 , F_349 ( V_8 -> V_42 ) ,
V_385 ) ;
} else {
T_1 V_18 ;
V_18 = ( V_8 -> V_42 << V_718 ) ;
F_1 ( V_2 , V_719 , V_18 ) ;
V_18 = ( V_385 << V_720 ) ;
F_1 ( V_2 , V_721 , V_18 ) ;
}
for ( V_427 = 0 ; V_427 < V_385 ; V_427 ++ ) {
struct V_463 * V_383 = V_8 -> V_354 [ V_427 ] ;
V_383 -> V_20 = V_8 -> V_525 ;
V_383 -> V_499 = V_722 ;
V_383 -> V_509 = V_723 ;
}
F_197 ( V_8 ) ;
F_190 ( V_8 ) ;
F_111 ( V_8 ) ;
F_109 ( V_8 ) ;
V_8 -> V_330 = F_169 ( V_8 -> V_253 -> V_389 ) ;
V_252 = F_166 ( V_8 ) ;
if ( V_252 )
goto V_716;
return 0 ;
V_716:
for ( V_427 = 0 ; V_427 < V_448 ; V_427 ++ ) {
if ( ! V_8 -> V_450 [ V_427 ] )
continue;
F_350 ( V_8 -> V_450 [ V_427 ] -> V_480 ) ;
}
return V_252 ;
}
static int F_351 ( struct V_250 * V_251 ,
struct V_724 * V_725 ,
struct V_1 * V_2 )
{
struct V_724 * V_669 ;
struct V_7 * V_8 ;
struct V_573 * V_574 ;
struct V_288 * V_253 ;
struct V_726 * V_727 ;
const char * V_728 ;
const char * V_729 ;
char V_730 [ V_130 ] ;
T_1 V_42 ;
int V_731 ;
int V_732 ;
int V_252 , V_46 , V_6 ;
V_253 = F_352 ( sizeof( * V_8 ) , V_448 , V_385 ) ;
if ( ! V_253 )
return - V_167 ;
V_669 = F_353 ( V_725 , L_36 , 0 ) ;
if ( ! V_669 ) {
F_125 ( & V_251 -> V_253 , L_37 ) ;
V_252 = - V_670 ;
goto V_733;
}
V_732 = F_354 ( V_725 ) ;
if ( V_732 < 0 ) {
F_125 ( & V_251 -> V_253 , L_38 ) ;
V_252 = V_732 ;
goto V_733;
}
if ( F_355 ( V_725 , L_39 , & V_42 ) ) {
V_252 = - V_49 ;
F_125 ( & V_251 -> V_253 , L_40 ) ;
goto V_733;
}
V_253 -> V_734 = V_660 ;
V_253 -> V_735 = 5 * V_736 ;
V_253 -> V_737 = & V_738 ;
V_253 -> V_739 = & V_740 ;
V_8 = F_101 ( V_253 ) ;
V_8 -> V_555 = F_356 ( V_725 , 0 ) ;
if ( V_8 -> V_555 <= 0 ) {
V_252 = - V_49 ;
goto V_733;
}
if ( F_357 ( V_725 , L_41 ) )
V_8 -> V_429 |= V_430 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_42 = V_42 ;
if ( V_2 -> V_11 == V_12 )
V_8 -> V_314 = V_8 -> V_42 * V_385 ;
else
V_8 -> V_314 = V_8 -> V_42 * V_2 -> V_714 ;
V_8 -> V_669 = V_669 ;
V_8 -> V_402 = V_732 ;
if ( V_2 -> V_11 == V_12 ) {
V_727 = F_358 ( V_251 , V_741 , 2 + V_42 ) ;
V_8 -> V_397 = F_359 ( & V_251 -> V_253 , V_727 ) ;
if ( F_360 ( V_8 -> V_397 ) ) {
V_252 = F_361 ( V_8 -> V_397 ) ;
goto V_678;
}
} else {
if ( F_355 ( V_725 , L_42 ,
& V_8 -> V_396 ) ) {
V_252 = - V_49 ;
F_125 ( & V_251 -> V_253 , L_43 ) ;
goto V_678;
}
V_8 -> V_397 = V_2 -> V_742 + F_362 ( V_8 -> V_396 ) ;
}
V_8 -> V_614 = F_363 ( struct V_616 ) ;
if ( ! V_8 -> V_614 ) {
V_252 = - V_167 ;
goto V_678;
}
V_728 = F_364 ( V_725 ) ;
if ( V_728 && F_331 ( V_728 ) ) {
V_729 = L_44 ;
F_102 ( V_253 -> V_289 , V_728 ) ;
} else {
if ( V_2 -> V_11 == V_12 )
F_316 ( V_8 , V_730 ) ;
if ( F_331 ( V_730 ) ) {
V_729 = L_45 ;
F_102 ( V_253 -> V_289 , V_730 ) ;
} else {
V_729 = L_46 ;
F_365 ( V_253 ) ;
}
}
V_8 -> V_536 = V_660 ;
V_8 -> V_525 = V_659 ;
V_8 -> V_253 = V_253 ;
F_366 ( V_253 , & V_251 -> V_253 ) ;
V_252 = F_346 ( V_8 ) ;
if ( V_252 < 0 ) {
F_125 ( & V_251 -> V_253 , L_47 , V_42 ) ;
goto V_743;
}
F_182 ( V_8 ) ;
F_186 ( V_8 ) ;
if ( V_2 -> V_11 == V_12 )
F_183 ( V_8 ) ;
F_188 ( V_8 ) ;
V_8 -> V_480 = F_348 ( struct V_573 ) ;
if ( ! V_8 -> V_480 ) {
V_252 = - V_167 ;
goto V_744;
}
F_172 (cpu) {
V_574 = F_216 ( V_8 -> V_480 , V_6 ) ;
F_367 ( & V_574 -> V_578 , V_745 ,
V_579 ) ;
V_574 -> V_578 . V_746 = F_272 ;
V_574 -> V_576 = false ;
F_368 ( & V_574 -> V_583 , F_270 ,
( unsigned long ) V_253 ) ;
}
F_369 ( V_253 , & V_8 -> V_557 , F_302 , V_747 ) ;
V_731 = V_748 | V_749 ;
V_253 -> V_731 = V_731 | V_750 ;
V_253 -> V_751 |= V_731 | V_750 | V_752 ;
V_253 -> V_753 |= V_731 ;
V_253 -> V_754 = V_755 ;
V_253 -> V_756 = 9676 ;
V_252 = F_370 ( V_253 ) ;
if ( V_252 < 0 ) {
F_125 ( & V_251 -> V_253 , L_48 ) ;
goto V_757;
}
F_315 ( V_253 , L_49 , V_729 , V_253 -> V_289 ) ;
V_2 -> V_758 [ V_42 ] = V_8 ;
return 0 ;
V_757:
F_350 ( V_8 -> V_480 ) ;
V_744:
for ( V_46 = 0 ; V_46 < V_448 ; V_46 ++ )
F_350 ( V_8 -> V_450 [ V_46 ] -> V_480 ) ;
V_743:
F_350 ( V_8 -> V_614 ) ;
V_678:
F_371 ( V_8 -> V_555 ) ;
V_733:
F_372 ( V_669 ) ;
F_373 ( V_253 ) ;
return V_252 ;
}
static void F_374 ( struct V_7 * V_8 )
{
int V_46 ;
F_375 ( V_8 -> V_253 ) ;
F_372 ( V_8 -> V_669 ) ;
F_350 ( V_8 -> V_480 ) ;
F_350 ( V_8 -> V_614 ) ;
for ( V_46 = 0 ; V_46 < V_448 ; V_46 ++ )
F_350 ( V_8 -> V_450 [ V_46 ] -> V_480 ) ;
F_371 ( V_8 -> V_555 ) ;
F_373 ( V_8 -> V_253 ) ;
}
static void F_376 ( const struct V_759 * V_760 ,
struct V_1 * V_2 )
{
T_1 V_761 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 6 ; V_46 ++ ) {
F_1 ( V_2 , F_377 ( V_46 ) , 0 ) ;
F_1 ( V_2 , F_378 ( V_46 ) , 0 ) ;
if ( V_46 < 4 )
F_1 ( V_2 , F_379 ( V_46 ) , 0 ) ;
}
V_761 = 0 ;
for ( V_46 = 0 ; V_46 < V_760 -> V_762 ; V_46 ++ ) {
const struct V_763 * V_764 = V_760 -> V_764 + V_46 ;
F_1 ( V_2 , F_377 ( V_46 ) ,
( V_764 -> V_397 & 0xffff0000 ) | ( V_764 -> V_765 << 8 ) |
V_760 -> V_766 ) ;
F_1 ( V_2 , F_378 ( V_46 ) ,
( V_764 -> V_20 - 1 ) & 0xffff0000 ) ;
V_761 |= ( 1 << V_46 ) ;
}
F_1 ( V_2 , V_767 , V_761 ) ;
}
static void F_380 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_209 ; V_8 ++ ) {
F_1 ( V_2 , F_381 ( V_8 ) ,
V_768 ) ;
F_1 ( V_2 , F_382 ( V_8 ) ,
V_769 ) ;
}
F_1 ( V_2 , V_770 ,
V_771 ) ;
F_1 ( V_2 , V_772 , 0x1 ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
T_1 V_18 , V_773 , V_774 ;
F_1 ( V_2 , V_370 , 0x0 ) ;
V_773 = V_775
<< V_776 ;
V_773 |= V_777
<< V_778 ;
V_774 = V_779
<< V_776 ;
V_774 |= V_777
<< V_778 ;
F_1 ( V_2 , V_780 , V_774 ) ;
F_1 ( V_2 , V_781 , V_773 ) ;
F_1 ( V_2 , V_782 , V_773 ) ;
F_1 ( V_2 , V_783 , V_774 ) ;
F_1 ( V_2 , V_784 , V_773 ) ;
F_1 ( V_2 , V_785 , V_774 ) ;
F_1 ( V_2 , V_786 , V_773 ) ;
F_1 ( V_2 , V_787 , V_774 ) ;
V_18 = V_788
<< V_789 ;
V_18 |= V_790
<< V_791 ;
F_1 ( V_2 , V_792 , V_18 ) ;
F_1 ( V_2 , V_793 , V_18 ) ;
V_18 = V_775
<< V_789 ;
V_18 |= V_777
<< V_791 ;
F_1 ( V_2 , V_794 , V_18 ) ;
V_18 = V_779
<< V_789 ;
V_18 |= V_777
<< V_791 ;
F_1 ( V_2 , V_795 , V_18 ) ;
}
static int F_384 ( struct V_250 * V_251 , struct V_1 * V_2 )
{
const struct V_759 * V_796 ;
int V_252 , V_46 ;
T_1 V_18 ;
if ( V_385 % 4 || ( V_385 > V_2 -> V_714 ) ||
( V_448 > V_43 ) ) {
F_125 ( & V_251 -> V_253 , L_50 ) ;
return - V_49 ;
}
V_796 = F_385 () ;
if ( V_796 )
F_376 ( V_796 , V_2 ) ;
if ( V_2 -> V_11 == V_337 )
F_383 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_18 = F_4 ( V_2 -> V_664 + V_797 ) ;
V_18 |= V_798 ;
F_2 ( V_18 , V_2 -> V_664 + V_797 ) ;
} else {
V_18 = F_4 ( V_2 -> V_742 + V_799 ) ;
V_18 &= ~ V_800 ;
F_2 ( V_18 , V_2 -> V_742 + V_799 ) ;
}
V_2 -> V_631 = F_90 ( & V_251 -> V_253 , F_218 () ,
sizeof( * V_2 -> V_631 ) ,
V_117 ) ;
if ( ! V_2 -> V_631 )
return - V_167 ;
F_172 (i) {
V_2 -> V_631 [ V_46 ] . V_42 = V_46 ;
V_2 -> V_631 [ V_46 ] . V_20 = V_801 ;
V_252 = F_243 ( V_251 , & V_2 -> V_631 [ V_46 ] ,
V_801 , V_46 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
}
F_380 ( V_2 ) ;
for ( V_46 = 0 ; V_46 < V_209 ; V_46 ++ ) {
if ( V_2 -> V_11 == V_12 ) {
F_1 ( V_2 , F_349 ( V_46 ) ,
V_385 ) ;
continue;
} else {
T_1 V_18 ;
V_18 = ( V_46 << V_718 ) ;
F_1 ( V_2 , V_719 , V_18 ) ;
V_18 = ( V_385 << V_720 ) ;
F_1 ( V_2 , V_721 , V_18 ) ;
}
}
if ( V_2 -> V_11 == V_12 )
F_2 ( V_802 ,
V_2 -> V_664 + V_803 ) ;
F_1 ( V_2 , V_804 , 0x1 ) ;
V_252 = F_143 ( V_251 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
V_252 = F_94 ( V_251 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
F_108 ( V_2 ) ;
return 0 ;
}
static int F_386 ( struct V_250 * V_251 )
{
struct V_724 * V_805 = V_251 -> V_253 . V_806 ;
struct V_724 * V_725 ;
struct V_1 * V_2 ;
struct V_726 * V_727 ;
void T_12 * V_397 ;
int V_807 , V_6 ;
int V_252 ;
V_2 = F_347 ( & V_251 -> V_253 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_167 ;
V_2 -> V_11 =
( unsigned long ) F_387 ( & V_251 -> V_253 ) ;
V_727 = F_358 ( V_251 , V_741 , 0 ) ;
V_397 = F_359 ( & V_251 -> V_253 , V_727 ) ;
if ( F_360 ( V_397 ) )
return F_361 ( V_397 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_727 = F_358 ( V_251 , V_741 , 1 ) ;
V_2 -> V_664 = F_359 ( & V_251 -> V_253 , V_727 ) ;
if ( F_360 ( V_2 -> V_664 ) )
return F_361 ( V_2 -> V_664 ) ;
} else {
V_727 = F_358 ( V_251 , V_741 , 1 ) ;
V_2 -> V_742 = F_359 ( & V_251 -> V_253 , V_727 ) ;
if ( F_360 ( V_2 -> V_742 ) )
return F_361 ( V_2 -> V_742 ) ;
}
F_172 (cpu) {
T_1 V_808 ;
V_808 = ( V_2 -> V_11 == V_12 ?
V_809 : V_810 ) ;
V_2 -> V_5 [ V_6 ] = V_397 + V_6 * V_808 ;
}
if ( V_2 -> V_11 == V_12 )
V_2 -> V_714 = 8 ;
else
V_2 -> V_714 = 32 ;
V_2 -> V_811 = F_388 ( & V_251 -> V_253 , L_51 ) ;
if ( F_360 ( V_2 -> V_811 ) )
return F_361 ( V_2 -> V_811 ) ;
V_252 = F_389 ( V_2 -> V_811 ) ;
if ( V_252 < 0 )
return V_252 ;
V_2 -> V_812 = F_388 ( & V_251 -> V_253 , L_52 ) ;
if ( F_360 ( V_2 -> V_812 ) ) {
V_252 = F_361 ( V_2 -> V_812 ) ;
goto V_813;
}
V_252 = F_389 ( V_2 -> V_812 ) ;
if ( V_252 < 0 )
goto V_813;
if ( V_2 -> V_11 == V_337 ) {
V_2 -> V_814 = F_388 ( & V_251 -> V_253 , L_53 ) ;
if ( F_360 ( V_2 -> V_814 ) ) {
V_252 = F_361 ( V_2 -> V_814 ) ;
goto V_815;
}
V_252 = F_389 ( V_2 -> V_814 ) ;
if ( V_252 < 0 )
goto V_815;
}
V_2 -> V_436 = F_390 ( V_2 -> V_811 ) ;
if ( V_2 -> V_11 == V_337 ) {
V_252 = F_391 ( & V_251 -> V_253 , F_392 ( 40 ) ) ;
if ( V_252 )
goto V_816;
V_252 = F_393 ( & V_251 -> V_253 , F_392 ( 32 ) ) ;
if ( V_252 )
goto V_816;
}
V_252 = F_384 ( V_251 , V_2 ) ;
if ( V_252 < 0 ) {
F_125 ( & V_251 -> V_253 , L_54 ) ;
goto V_816;
}
V_807 = F_394 ( V_805 ) ;
if ( V_807 == 0 ) {
F_125 ( & V_251 -> V_253 , L_55 ) ;
V_252 = - V_670 ;
goto V_816;
}
V_2 -> V_758 = F_90 ( & V_251 -> V_253 , V_807 ,
sizeof( * V_2 -> V_758 ) ,
V_117 ) ;
if ( ! V_2 -> V_758 ) {
V_252 = - V_167 ;
goto V_816;
}
F_395 (dn, port_node) {
V_252 = F_351 ( V_251 , V_725 , V_2 ) ;
if ( V_252 < 0 )
goto V_816;
}
F_396 ( V_251 , V_2 ) ;
return 0 ;
V_816:
if ( V_2 -> V_11 == V_337 )
F_397 ( V_2 -> V_814 ) ;
V_815:
F_397 ( V_2 -> V_812 ) ;
V_813:
F_397 ( V_2 -> V_811 ) ;
return V_252 ;
}
static int F_398 ( struct V_250 * V_251 )
{
struct V_1 * V_2 = F_399 ( V_251 ) ;
struct V_724 * V_805 = V_251 -> V_253 . V_806 ;
struct V_724 * V_725 ;
int V_46 = 0 ;
F_395 (dn, port_node) {
if ( V_2 -> V_758 [ V_46 ] )
F_374 ( V_2 -> V_758 [ V_46 ] ) ;
V_46 ++ ;
}
for ( V_46 = 0 ; V_46 < V_348 ; V_46 ++ ) {
struct V_319 * V_324 = & V_2 -> V_349 [ V_46 ] ;
F_140 ( V_251 , V_2 , V_324 ) ;
}
F_172 (i) {
struct V_449 * V_469 = & V_2 -> V_631 [ V_46 ] ;
F_124 ( & V_251 -> V_253 ,
V_801 * V_521 ,
V_469 -> V_451 ,
V_469 -> V_522 ) ;
}
F_397 ( V_2 -> V_814 ) ;
F_397 ( V_2 -> V_811 ) ;
F_397 ( V_2 -> V_812 ) ;
return 0 ;
}
