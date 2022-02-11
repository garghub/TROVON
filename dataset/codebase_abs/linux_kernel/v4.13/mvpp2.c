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
static inline void F_155 ( struct V_7 * V_8 , int V_320 ,
T_2 V_14 ,
T_7 V_344 )
{
int V_6 = F_134 () ;
if ( V_8 -> V_2 -> V_11 == V_337 ) {
T_1 V_18 = 0 ;
if ( sizeof( T_2 ) == 8 )
V_18 |= F_156 ( V_14 ) &
V_364 ;
if ( sizeof( T_7 ) == 8 )
V_18 |= ( F_156 ( V_344 )
<< V_365 ) &
V_366 ;
F_5 ( V_8 -> V_2 , V_6 ,
V_367 , V_18 ) ;
}
F_5 ( V_8 -> V_2 , V_6 ,
V_368 , V_344 ) ;
F_5 ( V_8 -> V_2 , V_6 ,
F_157 ( V_320 ) , V_14 ) ;
F_136 () ;
}
static int F_158 ( struct V_7 * V_8 ,
struct V_319 * V_324 , int V_331 )
{
int V_46 , V_332 , V_369 ;
T_2 V_17 ;
T_7 V_335 ;
void * V_370 ;
V_332 = F_151 ( V_324 -> V_330 ) ;
V_369 = F_159 ( V_332 ) ;
if ( V_331 < 0 ||
( V_331 + V_324 -> V_331 > V_324 -> V_20 ) ) {
F_160 ( V_8 -> V_253 ,
L_4 ,
V_331 , V_324 -> V_42 ) ;
return 0 ;
}
for ( V_46 = 0 ; V_46 < V_331 ; V_46 ++ ) {
V_370 = F_149 ( V_8 , V_324 , & V_17 ,
& V_335 , V_117 ) ;
if ( ! V_370 )
break;
F_155 ( V_8 , V_324 -> V_42 , V_17 ,
V_335 ) ;
}
V_324 -> V_331 += V_46 ;
F_161 ( V_8 -> V_253 ,
L_5 ,
V_324 -> type == V_371 ? L_6 : L_7 ,
V_324 -> V_42 , V_324 -> V_330 , V_332 , V_369 ) ;
F_161 ( V_8 -> V_253 ,
L_8 ,
V_324 -> type == V_371 ? L_6 : L_7 ,
V_324 -> V_42 , V_46 , V_331 ) ;
return V_46 ;
}
static struct V_319 *
F_162 ( struct V_7 * V_8 , int V_320 , enum V_372 type ,
int V_330 )
{
struct V_319 * V_373 = & V_8 -> V_2 -> V_349 [ V_320 ] ;
int V_374 ;
if ( V_373 -> type != V_329 && V_373 -> type != type ) {
F_160 ( V_8 -> V_253 , L_9 ) ;
return NULL ;
}
if ( V_373 -> type == V_329 )
V_373 -> type = type ;
if ( ( ( type == V_375 ) && ( V_330 > V_373 -> V_330 ) ) ||
( V_373 -> V_330 == 0 ) ) {
int V_376 ;
V_376 = V_373 -> V_331 ;
if ( V_376 == 0 )
V_376 = type == V_375 ?
V_377 :
V_378 ;
else
F_137 ( V_8 -> V_253 -> V_253 . V_363 ,
V_8 -> V_2 , V_373 ) ;
V_373 -> V_330 = V_330 ;
V_373 -> V_321 =
F_163 ( F_151 ( V_330 ) ) +
V_379 ;
V_374 = F_158 ( V_8 , V_373 , V_376 ) ;
if ( V_374 != V_376 ) {
F_141 ( 1 , L_10 ,
V_373 -> V_42 , V_374 , V_376 ) ;
return NULL ;
}
}
F_130 ( V_8 -> V_2 , V_373 ,
F_151 ( V_373 -> V_330 ) ) ;
return V_373 ;
}
static int F_164 ( struct V_7 * V_8 )
{
int V_380 ;
if ( ! V_8 -> V_381 ) {
V_8 -> V_381 =
F_162 ( V_8 , F_165 ( V_8 -> V_42 ) ,
V_375 ,
V_8 -> V_330 ) ;
if ( ! V_8 -> V_381 )
return - V_167 ;
V_8 -> V_381 -> V_164 |= ( 1 << V_8 -> V_42 ) ;
for ( V_380 = 0 ; V_380 < V_382 ; V_380 ++ )
F_146 ( V_8 , V_380 , V_8 -> V_381 -> V_42 ) ;
}
if ( ! V_8 -> V_383 ) {
V_8 -> V_383 =
F_162 ( V_8 , V_384 ,
V_371 ,
V_385 ) ;
if ( ! V_8 -> V_383 )
return - V_167 ;
V_8 -> V_383 -> V_164 |= ( 1 << V_8 -> V_42 ) ;
for ( V_380 = 0 ; V_380 < V_382 ; V_380 ++ )
F_148 ( V_8 , V_380 ,
V_8 -> V_383 -> V_42 ) ;
}
return 0 ;
}
static int F_166 ( struct V_288 * V_253 , int V_386 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_319 * V_387 = V_8 -> V_381 ;
int V_374 , V_376 = V_387 -> V_331 ;
int V_330 = F_167 ( V_386 ) ;
F_137 ( V_253 -> V_253 . V_363 , V_8 -> V_2 , V_387 ) ;
if ( V_387 -> V_331 ) {
F_141 ( 1 , L_2 , V_387 -> V_42 ) ;
return - V_388 ;
}
V_387 -> V_330 = V_330 ;
V_387 -> V_321 = F_163 ( F_151 ( V_330 ) ) +
V_379 ;
V_374 = F_158 ( V_8 , V_387 , V_376 ) ;
if ( V_374 != V_376 ) {
F_141 ( 1 , L_10 ,
V_387 -> V_42 , V_374 , V_376 ) ;
return - V_388 ;
}
F_130 ( V_8 -> V_2 , V_387 ,
F_151 ( V_387 -> V_330 ) ) ;
V_253 -> V_386 = V_386 ;
F_168 ( V_253 ) ;
return 0 ;
}
static inline void F_169 ( struct V_7 * V_8 )
{
int V_6 , V_389 = 0 ;
F_170 (cpu)
V_389 |= 1 << V_6 ;
F_1 ( V_8 -> V_2 , F_171 ( V_8 -> V_42 ) ,
F_172 ( V_389 ) ) ;
}
static inline void F_173 ( struct V_7 * V_8 )
{
int V_6 , V_389 = 0 ;
F_170 (cpu)
V_389 |= 1 << V_6 ;
F_1 ( V_8 -> V_2 , F_171 ( V_8 -> V_42 ) ,
F_174 ( V_389 ) ) ;
}
static void F_175 ( void * V_390 )
{
struct V_7 * V_8 = V_390 ;
F_5 ( V_8 -> V_2 , F_176 () ,
F_177 ( V_8 -> V_42 ) , 0 ) ;
}
static void F_178 ( void * V_390 )
{
struct V_7 * V_8 = V_390 ;
F_5 ( V_8 -> V_2 , F_176 () ,
F_177 ( V_8 -> V_42 ) ,
( V_391 |
V_392 ) ) ;
}
static void F_179 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_393 == 0 ) {
V_18 = F_4 ( V_8 -> V_394 + V_395 ) ;
V_18 &= ~ V_396 ;
if ( V_8 -> V_397 == V_398 ||
V_8 -> V_397 == V_399 )
V_18 |= V_400 ;
else
V_18 |= V_401 ;
F_2 ( V_18 , V_8 -> V_394 + V_395 ) ;
}
V_18 = F_4 ( V_8 -> V_394 + V_402 ) ;
if ( V_8 -> V_397 == V_403 )
V_18 |= V_404 ;
else
V_18 &= ~ V_404 ;
V_18 &= ~ V_405 ;
V_18 |= V_406 ;
V_18 |= V_407 ;
F_2 ( V_18 , V_8 -> V_394 + V_402 ) ;
}
static void F_180 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_2 -> V_11 == V_337 )
F_179 ( V_8 ) ;
V_18 = F_4 ( V_8 -> V_394 + V_408 ) ;
switch ( V_8 -> V_397 ) {
case V_409 :
V_18 |= V_410 ;
break;
case V_403 :
V_18 |= V_411 ;
default:
V_18 &= ~ V_412 ;
}
F_2 ( V_18 , V_8 -> V_394 + V_408 ) ;
}
static void F_181 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_394 + V_413 ) ;
V_18 |= V_414 ;
F_2 ( V_18 , V_8 -> V_394 + V_413 ) ;
}
static void F_182 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_393 == 0 &&
( V_8 -> V_397 == V_398 ||
V_8 -> V_397 == V_399 ) ) {
V_18 = F_4 ( V_8 -> V_394 + V_415 ) ;
V_18 |= V_416 |
V_417 ;
V_18 &= ~ V_418 ;
F_2 ( V_18 , V_8 -> V_394 + V_415 ) ;
} else {
V_18 = F_4 ( V_8 -> V_394 + V_419 ) ;
V_18 |= V_420 ;
V_18 |= V_421 ;
F_2 ( V_18 , V_8 -> V_394 + V_419 ) ;
}
}
static void F_183 ( struct V_7 * V_8 )
{
T_1 V_18 ;
if ( V_8 -> V_393 == 0 &&
( V_8 -> V_397 == V_398 ||
V_8 -> V_397 == V_399 ) ) {
V_18 = F_4 ( V_8 -> V_394 + V_415 ) ;
V_18 &= ~ ( V_416 |
V_417 ) ;
F_2 ( V_18 , V_8 -> V_394 + V_415 ) ;
} else {
V_18 = F_4 ( V_8 -> V_394 + V_419 ) ;
V_18 &= ~ ( V_420 ) ;
F_2 ( V_18 , V_8 -> V_394 + V_419 ) ;
}
}
static void F_184 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_394 + V_422 ) &
~ V_423 ;
F_2 ( V_18 , V_8 -> V_394 + V_422 ) ;
}
static void F_185 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_394 + V_422 ) ;
if ( V_8 -> V_424 == 1000 )
V_18 |= V_425 ;
else
V_18 &= ~ V_425 ;
if ( V_8 -> V_397 == V_409 )
V_18 |= V_426 ;
else
V_18 &= ~ V_426 ;
F_2 ( V_18 , V_8 -> V_394 + V_422 ) ;
}
static void F_186 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_394 + V_408 ) &
~ V_427 ;
F_2 ( V_18 , V_8 -> V_394 + V_408 ) ;
while ( F_4 ( V_8 -> V_394 + V_408 ) &
V_427 )
continue;
}
static inline void F_187 ( struct V_7 * V_8 )
{
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_394 + V_419 ) ;
V_18 &= ~ V_428 ;
V_18 |= ( ( ( V_8 -> V_330 - V_214 ) / 2 ) <<
V_429 ) ;
F_2 ( V_18 , V_8 -> V_394 + V_419 ) ;
}
static void F_188 ( struct V_7 * V_8 )
{
int V_430 , V_18 , V_431 , V_432 , V_351 ;
if ( V_8 -> V_2 -> V_11 == V_12 ) {
if ( V_8 -> V_433 & V_434 )
F_185 ( V_8 ) ;
V_18 = F_4 ( V_8 -> V_394 + V_435 ) ;
V_18 &= ~ V_436 ;
V_18 |= F_189 ( 64 - 4 - 2 ) ;
F_2 ( V_18 , V_8 -> V_394 + V_435 ) ;
}
V_430 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_437 ,
V_430 ) ;
F_1 ( V_8 -> V_2 , V_438 , 0 ) ;
for ( V_431 = 0 ; V_431 < V_43 ; V_431 ++ ) {
V_432 = F_23 ( V_8 -> V_42 , V_431 ) ;
F_1 ( V_8 -> V_2 ,
F_190 ( V_432 ) , 0 ) ;
}
F_1 ( V_8 -> V_2 , V_439 ,
V_8 -> V_2 -> V_440 / V_441 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_442 ) ;
V_18 &= ~ V_443 ;
V_18 |= F_191 ( 1 ) ;
V_18 |= V_444 ;
F_1 ( V_8 -> V_2 , V_442 , V_18 ) ;
V_18 = V_445 ;
F_1 ( V_8 -> V_2 , V_446 , V_18 ) ;
F_1 ( V_8 -> V_2 , F_192 ( V_8 -> V_42 ) ,
V_447 |
F_193 ( 256 ) ) ;
for ( V_351 = 0 ; V_351 < V_382 ; V_351 ++ ) {
V_431 = V_8 -> V_354 [ V_351 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_431 ) ) ;
V_18 |= V_448 |
V_449 ;
F_1 ( V_8 -> V_2 , F_147 ( V_431 ) , V_18 ) ;
}
F_173 ( V_8 ) ;
}
static void F_194 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_351 , V_431 ;
for ( V_351 = 0 ; V_351 < V_382 ; V_351 ++ ) {
V_431 = V_8 -> V_354 [ V_351 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_431 ) ) ;
V_18 &= ~ V_450 ;
F_1 ( V_8 -> V_2 , F_147 ( V_431 ) , V_18 ) ;
}
}
static void F_195 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_351 , V_431 ;
for ( V_351 = 0 ; V_351 < V_382 ; V_351 ++ ) {
V_431 = V_8 -> V_354 [ V_351 ] -> V_42 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_431 ) ) ;
V_18 |= V_450 ;
F_1 ( V_8 -> V_2 , F_147 ( V_431 ) , V_18 ) ;
}
}
static void F_196 ( struct V_7 * V_8 )
{
T_1 V_451 ;
int V_431 ;
int V_430 = F_22 ( V_8 ) ;
V_451 = 0 ;
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
struct V_453 * V_21 = V_8 -> V_454 [ V_431 ] ;
if ( V_21 -> V_455 )
V_451 |= ( 1 << V_431 ) ;
}
F_1 ( V_8 -> V_2 , V_437 , V_430 ) ;
F_1 ( V_8 -> V_2 , V_456 , V_451 ) ;
}
static void F_197 ( struct V_7 * V_8 )
{
T_1 V_457 ;
int V_458 ;
int V_430 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_437 , V_430 ) ;
V_457 = ( F_3 ( V_8 -> V_2 , V_456 ) ) &
V_459 ;
if ( V_457 != 0 )
F_1 ( V_8 -> V_2 , V_456 ,
( V_457 << V_460 ) ) ;
V_458 = 0 ;
do {
if ( V_458 >= V_461 ) {
F_198 ( V_8 -> V_253 ,
L_11 ,
V_457 ) ;
break;
}
F_199 ( 1 ) ;
V_458 ++ ;
V_457 = F_3 ( V_8 -> V_2 , V_456 ) ;
} while ( V_457 & V_459 );
}
static inline int
F_200 ( struct V_7 * V_8 , int V_462 )
{
T_1 V_18 = F_3 ( V_8 -> V_2 , F_201 ( V_462 ) ) ;
return V_18 & V_463 ;
}
static inline void
F_202 ( struct V_7 * V_8 , int V_462 ,
int V_464 , int V_465 )
{
T_1 V_18 = V_464 | ( V_465 << V_466 ) ;
F_1 ( V_8 -> V_2 , F_203 ( V_462 ) , V_18 ) ;
}
static inline struct V_25 *
F_204 ( struct V_467 * V_380 )
{
int V_26 = V_380 -> V_468 ;
V_380 -> V_468 = F_205 ( V_380 , V_26 ) ;
F_206 ( V_380 -> V_455 + V_380 -> V_468 ) ;
return V_380 -> V_455 + V_26 ;
}
static void F_207 ( struct V_7 * V_8 ,
int V_353 , int V_3 )
{
T_1 V_18 ;
V_3 = V_3 >> 5 ;
V_18 = F_3 ( V_8 -> V_2 , F_147 ( V_353 ) ) ;
V_18 &= ~ V_469 ;
V_18 |= ( ( V_3 << V_470 ) &
V_469 ) ;
F_1 ( V_8 -> V_2 , F_147 ( V_353 ) , V_18 ) ;
}
static struct V_9 *
F_208 ( struct V_453 * V_21 )
{
int V_10 = V_21 -> V_468 ;
V_21 -> V_468 = F_205 ( V_21 , V_10 ) ;
return V_21 -> V_455 + V_10 ;
}
static void F_209 ( struct V_7 * V_8 , int V_471 )
{
F_5 ( V_8 -> V_2 , F_176 () ,
V_472 , V_471 ) ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_453 * V_473 , int V_374 )
{
if ( ( V_473 -> V_474 + V_374 ) > V_473 -> V_20 ) {
int V_6 = F_176 () ;
T_1 V_18 = F_3 ( V_2 , F_211 ( V_6 ) ) ;
V_473 -> V_474 = V_18 & V_475 ;
}
if ( ( V_473 -> V_474 + V_374 ) > V_473 -> V_20 )
return - V_167 ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_453 * V_21 , int V_374 )
{
T_1 V_18 ;
int V_6 = F_176 () ;
V_18 = ( V_21 -> V_42 << V_476 ) | V_374 ;
F_5 ( V_2 , V_6 , V_477 , V_18 ) ;
V_18 = F_6 ( V_2 , V_6 , V_478 ) ;
return V_18 & V_479 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_453 * V_21 ,
struct V_31 * V_32 ,
int V_374 )
{
int V_480 , V_6 , V_481 ;
if ( V_32 -> V_482 >= V_374 )
return 0 ;
V_481 = 0 ;
F_170 (cpu) {
struct V_31 * V_483 ;
V_483 = F_214 ( V_21 -> V_484 , V_6 ) ;
V_481 += V_483 -> V_474 ;
V_481 += V_483 -> V_482 ;
}
V_480 = F_215 ( V_485 , V_374 - V_32 -> V_482 ) ;
V_481 += V_480 ;
if ( V_481 >
( V_21 -> V_20 - ( F_216 () * V_485 ) ) )
return - V_167 ;
V_32 -> V_482 += F_212 ( V_2 , V_21 , V_480 ) ;
if ( V_32 -> V_482 < V_374 )
return - V_167 ;
return 0 ;
}
static void F_217 ( struct V_453 * V_21 )
{
if ( V_21 -> V_468 == 0 )
V_21 -> V_468 = V_21 -> V_486 - 1 ;
else
V_21 -> V_468 -- ;
}
static T_1 F_218 ( int V_487 , int V_488 ,
int V_489 , int V_490 )
{
T_1 V_23 ;
V_23 = ( V_487 << V_491 ) ;
V_23 |= ( V_489 << V_492 ) ;
V_23 |= V_493 ;
if ( V_488 == F_66 ( V_238 ) ) {
V_23 &= ~ V_493 ;
V_23 &= ~ V_494 ;
} else {
V_23 |= V_494 ;
}
if ( V_490 == V_178 ) {
V_23 &= ~ V_495 ;
V_23 &= ~ V_496 ;
} else if ( V_490 == V_179 ) {
V_23 |= V_495 ;
V_23 &= ~ V_496 ;
} else {
V_23 |= V_497 ;
}
return V_23 ;
}
static inline int F_219 ( struct V_7 * V_8 ,
struct V_453 * V_21 )
{
T_1 V_18 ;
V_18 = F_6 ( V_8 -> V_2 , F_176 () ,
F_220 ( V_21 -> V_42 ) ) ;
return ( V_18 & V_498 ) >>
V_499 ;
}
static void F_221 ( void * V_390 )
{
struct V_7 * V_8 = V_390 ;
int V_431 ;
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
int V_42 = V_8 -> V_454 [ V_431 ] -> V_42 ;
F_6 ( V_8 -> V_2 , F_176 () ,
F_220 ( V_42 ) ) ;
}
}
static void F_222 ( struct V_7 * V_8 )
{
T_1 V_18 , V_20 , V_386 ;
int V_21 , V_430 ;
V_386 = V_8 -> V_330 * 8 ;
if ( V_386 > V_500 )
V_386 = V_500 ;
V_386 = 3 * V_386 ;
V_430 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_437 , V_430 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_501 ) ;
V_18 &= ~ V_500 ;
V_18 |= V_386 ;
F_1 ( V_8 -> V_2 , V_501 , V_18 ) ;
V_18 = F_3 ( V_8 -> V_2 , V_446 ) ;
V_20 = V_18 & V_445 ;
if ( V_20 < V_386 ) {
V_20 = V_386 ;
V_18 &= ~ V_445 ;
V_18 |= V_20 ;
F_1 ( V_8 -> V_2 , V_446 , V_18 ) ;
}
for ( V_21 = 0 ; V_21 < V_452 ; V_21 ++ ) {
V_18 = F_3 ( V_8 -> V_2 ,
F_223 ( V_21 ) ) ;
V_20 = V_18 & V_502 ;
if ( V_20 < V_386 ) {
V_20 = V_386 ;
V_18 &= ~ V_502 ;
V_18 |= V_20 ;
F_1 ( V_8 -> V_2 ,
F_223 ( V_21 ) ,
V_18 ) ;
}
}
}
static void F_224 ( struct V_7 * V_8 ,
struct V_467 * V_380 )
{
int V_6 = F_134 () ;
if ( V_380 -> V_503 > V_504 )
V_380 -> V_503 = V_504 ;
F_5 ( V_8 -> V_2 , V_6 , V_505 , V_380 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_506 ,
V_380 -> V_503 ) ;
F_136 () ;
}
static T_1 F_225 ( T_1 V_507 , unsigned long V_508 )
{
T_3 V_509 = ( T_3 ) V_508 * V_507 ;
F_226 ( V_509 , V_441 ) ;
return V_509 > V_510 ? V_510 : V_509 ;
}
static T_1 F_227 ( T_1 V_511 , unsigned long V_508 )
{
T_3 V_509 = ( T_3 ) V_511 * V_441 ;
F_226 ( V_509 , V_508 ) ;
return V_509 > V_510 ? V_510 : V_509 ;
}
static void F_228 ( struct V_7 * V_8 ,
struct V_467 * V_380 )
{
unsigned long V_512 = V_8 -> V_2 -> V_440 ;
T_1 V_18 = F_225 ( V_380 -> V_513 , V_512 ) ;
if ( V_18 > V_514 ) {
V_380 -> V_513 =
F_227 ( V_514 , V_512 ) ;
V_18 = F_225 ( V_380 -> V_513 , V_512 ) ;
}
F_1 ( V_8 -> V_2 , F_229 ( V_380 -> V_42 ) , V_18 ) ;
}
static void F_230 ( struct V_7 * V_8 ,
struct V_453 * V_21 ,
struct V_31 * V_32 , int V_374 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_374 ; V_46 ++ ) {
struct V_36 * V_37 =
V_32 -> V_38 + V_32 -> V_33 ;
F_138 ( V_8 -> V_253 -> V_253 . V_363 , V_37 -> V_40 ,
V_37 -> V_20 , V_515 ) ;
if ( V_37 -> V_35 )
F_231 ( V_37 -> V_35 ) ;
F_20 ( V_32 ) ;
}
}
static inline struct V_467 * F_232 ( struct V_7 * V_8 ,
T_1 V_516 )
{
int V_431 = F_233 ( V_516 ) - 1 ;
return V_8 -> V_354 [ V_431 ] ;
}
static inline struct V_453 * F_234 ( struct V_7 * V_8 ,
T_1 V_516 )
{
int V_431 = F_233 ( V_516 ) - 1 ;
return V_8 -> V_454 [ V_431 ] ;
}
static void F_235 ( struct V_7 * V_8 , struct V_453 * V_21 ,
struct V_31 * V_32 )
{
struct V_517 * V_518 = F_236 ( V_8 -> V_253 , V_21 -> V_519 ) ;
int V_520 ;
if ( V_32 -> V_6 != F_176 () )
F_160 ( V_8 -> V_253 , L_12 ) ;
V_520 = F_219 ( V_8 , V_21 ) ;
if ( ! V_520 )
return;
F_230 ( V_8 , V_21 , V_32 , V_520 ) ;
V_32 -> V_474 -= V_520 ;
if ( F_237 ( V_518 ) )
if ( V_32 -> V_20 - V_32 -> V_474 >= V_521 + 1 )
F_238 ( V_518 ) ;
}
static unsigned int F_239 ( struct V_7 * V_8 , T_1 V_516 )
{
struct V_453 * V_21 ;
struct V_31 * V_32 ;
unsigned int V_522 = 0 ;
while ( V_516 ) {
V_21 = F_234 ( V_8 , V_516 ) ;
if ( ! V_21 )
break;
V_32 = F_240 ( V_21 -> V_484 ) ;
if ( V_32 -> V_474 ) {
F_235 ( V_8 , V_21 , V_32 ) ;
V_522 += V_32 -> V_474 ;
}
V_516 &= ~ ( 1 << V_21 -> V_519 ) ;
}
return V_522 ;
}
static int F_241 ( struct V_250 * V_251 ,
struct V_453 * V_473 ,
int V_523 , int V_6 ,
struct V_1 * V_2 )
{
T_1 V_524 ;
V_473 -> V_455 = F_123 ( & V_251 -> V_253 ,
V_523 * V_525 ,
& V_473 -> V_526 , V_117 ) ;
if ( ! V_473 -> V_455 )
return - V_167 ;
V_473 -> V_486 = V_473 -> V_20 - 1 ;
V_473 -> V_468 = F_3 ( V_2 ,
F_242 ( V_6 ) ) ;
if ( V_2 -> V_11 == V_12 )
V_524 = V_473 -> V_526 ;
else
V_524 = V_473 -> V_526 >>
V_527 ;
F_1 ( V_2 , F_243 ( V_6 ) , V_524 ) ;
F_1 ( V_2 , F_244 ( V_6 ) , V_523 ) ;
return 0 ;
}
static int F_245 ( struct V_7 * V_8 ,
struct V_467 * V_380 )
{
T_1 V_528 ;
int V_6 ;
V_380 -> V_20 = V_8 -> V_529 ;
V_380 -> V_455 = F_123 ( V_8 -> V_253 -> V_253 . V_363 ,
V_380 -> V_20 * V_525 ,
& V_380 -> V_526 , V_117 ) ;
if ( ! V_380 -> V_455 )
return - V_167 ;
V_380 -> V_486 = V_380 -> V_20 - 1 ;
F_1 ( V_8 -> V_2 , F_201 ( V_380 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_505 , V_380 -> V_42 ) ;
if ( V_8 -> V_2 -> V_11 == V_12 )
V_528 = V_380 -> V_526 ;
else
V_528 = V_380 -> V_526 >> V_530 ;
F_5 ( V_8 -> V_2 , V_6 , V_531 , V_528 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_532 , V_380 -> V_20 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_533 , 0 ) ;
F_136 () ;
F_207 ( V_8 , V_380 -> V_42 , V_534 ) ;
F_224 ( V_8 , V_380 ) ;
F_228 ( V_8 , V_380 ) ;
F_202 ( V_8 , V_380 -> V_42 , 0 , V_380 -> V_20 ) ;
return 0 ;
}
static void F_246 ( struct V_7 * V_8 ,
struct V_467 * V_380 )
{
int V_535 , V_46 ;
V_535 = F_200 ( V_8 , V_380 -> V_42 ) ;
if ( ! V_535 )
return;
for ( V_46 = 0 ; V_46 < V_535 ; V_46 ++ ) {
struct V_25 * V_26 = F_204 ( V_380 ) ;
T_1 V_30 = F_19 ( V_8 , V_26 ) ;
int V_320 ;
V_320 = ( V_30 & V_536 ) >>
V_537 ;
F_155 ( V_8 , V_320 ,
F_16 ( V_8 , V_26 ) ,
F_17 ( V_8 , V_26 ) ) ;
}
F_202 ( V_8 , V_380 -> V_42 , V_535 , V_535 ) ;
}
static void F_247 ( struct V_7 * V_8 ,
struct V_467 * V_380 )
{
int V_6 ;
F_246 ( V_8 , V_380 ) ;
if ( V_380 -> V_455 )
F_124 ( V_8 -> V_253 -> V_253 . V_363 ,
V_380 -> V_20 * V_525 ,
V_380 -> V_455 ,
V_380 -> V_526 ) ;
V_380 -> V_455 = NULL ;
V_380 -> V_486 = 0 ;
V_380 -> V_468 = 0 ;
V_380 -> V_526 = 0 ;
F_1 ( V_8 -> V_2 , F_201 ( V_380 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_505 , V_380 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_531 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_532 , 0 ) ;
F_136 () ;
}
static int F_248 ( struct V_7 * V_8 ,
struct V_453 * V_21 )
{
T_1 V_18 ;
int V_6 , V_538 , V_539 , V_430 ;
struct V_31 * V_32 ;
V_21 -> V_20 = V_8 -> V_540 ;
V_21 -> V_455 = F_123 ( V_8 -> V_253 -> V_253 . V_363 ,
V_21 -> V_20 * V_525 ,
& V_21 -> V_526 , V_117 ) ;
if ( ! V_21 -> V_455 )
return - V_167 ;
V_21 -> V_486 = V_21 -> V_20 - 1 ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_541 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_542 ,
V_21 -> V_526 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_543 ,
V_21 -> V_20 & V_544 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_545 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_546 ,
V_21 -> V_42 << V_547 ) ;
V_18 = F_6 ( V_8 -> V_2 , V_6 , V_548 ) ;
V_18 &= ~ V_549 ;
F_5 ( V_8 -> V_2 , V_6 , V_548 , V_18 ) ;
V_539 = 16 ;
V_538 = ( V_8 -> V_42 * V_43 * V_539 ) +
( V_21 -> V_519 * V_539 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_550 ,
F_249 ( V_538 ) | V_551 |
F_250 ( V_539 / 2 ) ) ;
F_136 () ;
V_430 = F_22 ( V_8 ) ;
F_1 ( V_8 -> V_2 , V_437 , V_430 ) ;
V_18 = F_3 ( V_8 -> V_2 , F_251 ( V_21 -> V_519 ) ) ;
V_18 &= ~ V_552 ;
V_18 |= F_252 ( 1 ) ;
V_18 |= V_553 ;
F_1 ( V_8 -> V_2 , F_251 ( V_21 -> V_519 ) , V_18 ) ;
V_18 = V_502 ;
F_1 ( V_8 -> V_2 , F_223 ( V_21 -> V_519 ) ,
V_18 ) ;
F_170 (cpu) {
V_32 = F_214 ( V_21 -> V_484 , V_6 ) ;
V_32 -> V_20 = V_21 -> V_20 ;
V_32 -> V_38 = F_253 ( V_32 -> V_20 ,
sizeof( * V_32 -> V_38 ) ,
V_117 ) ;
if ( ! V_32 -> V_38 )
goto V_554;
V_32 -> V_474 = 0 ;
V_32 -> V_482 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> V_33 = 0 ;
}
return 0 ;
V_554:
F_170 (cpu) {
V_32 = F_214 ( V_21 -> V_484 , V_6 ) ;
F_57 ( V_32 -> V_38 ) ;
}
F_124 ( V_8 -> V_253 -> V_253 . V_363 ,
V_21 -> V_20 * V_525 ,
V_21 -> V_455 , V_21 -> V_526 ) ;
return - V_167 ;
}
static void F_254 ( struct V_7 * V_8 ,
struct V_453 * V_21 )
{
struct V_31 * V_32 ;
int V_6 ;
F_170 (cpu) {
V_32 = F_214 ( V_21 -> V_484 , V_6 ) ;
F_57 ( V_32 -> V_38 ) ;
}
if ( V_21 -> V_455 )
F_124 ( V_8 -> V_253 -> V_253 . V_363 ,
V_21 -> V_20 * V_525 ,
V_21 -> V_455 , V_21 -> V_526 ) ;
V_21 -> V_455 = NULL ;
V_21 -> V_486 = 0 ;
V_21 -> V_468 = 0 ;
V_21 -> V_526 = 0 ;
F_1 ( V_8 -> V_2 , F_190 ( V_21 -> V_42 ) , 0 ) ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_541 , V_21 -> V_42 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_542 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 , V_543 , 0 ) ;
F_136 () ;
}
static void F_255 ( struct V_7 * V_8 , struct V_453 * V_21 )
{
struct V_31 * V_32 ;
int V_458 , V_471 , V_6 ;
T_1 V_18 ;
V_6 = F_134 () ;
F_5 ( V_8 -> V_2 , V_6 , V_541 , V_21 -> V_42 ) ;
V_18 = F_6 ( V_8 -> V_2 , V_6 , V_550 ) ;
V_18 |= V_555 ;
F_5 ( V_8 -> V_2 , V_6 , V_550 , V_18 ) ;
V_458 = 0 ;
do {
if ( V_458 >= V_556 ) {
F_198 ( V_8 -> V_253 ,
L_13 ,
V_8 -> V_42 , V_21 -> V_519 ) ;
break;
}
F_199 ( 1 ) ;
V_458 ++ ;
V_471 = F_6 ( V_8 -> V_2 , V_6 ,
V_548 ) ;
V_471 &= V_549 ;
} while ( V_471 );
V_18 &= ~ V_555 ;
F_5 ( V_8 -> V_2 , V_6 , V_550 , V_18 ) ;
F_136 () ;
F_170 (cpu) {
V_32 = F_214 ( V_21 -> V_484 , V_6 ) ;
F_230 ( V_8 , V_21 , V_32 , V_32 -> V_474 ) ;
V_32 -> V_474 = 0 ;
V_32 -> V_39 = 0 ;
V_32 -> V_33 = 0 ;
}
}
static void F_256 ( struct V_7 * V_8 )
{
struct V_453 * V_21 ;
int V_431 ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_2 , V_557 ) ;
V_18 |= F_257 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_557 , V_18 ) ;
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
V_21 = V_8 -> V_454 [ V_431 ] ;
F_255 ( V_8 , V_21 ) ;
F_254 ( V_8 , V_21 ) ;
}
F_258 ( F_221 , V_8 , 1 ) ;
V_18 &= ~ F_257 ( V_8 -> V_42 ) ;
F_1 ( V_8 -> V_2 , V_557 , V_18 ) ;
}
static void F_259 ( struct V_7 * V_8 )
{
int V_431 ;
for ( V_431 = 0 ; V_431 < V_382 ; V_431 ++ )
F_247 ( V_8 , V_8 -> V_354 [ V_431 ] ) ;
}
static int F_260 ( struct V_7 * V_8 )
{
int V_431 , V_252 ;
for ( V_431 = 0 ; V_431 < V_382 ; V_431 ++ ) {
V_252 = F_245 ( V_8 , V_8 -> V_354 [ V_431 ] ) ;
if ( V_252 )
goto V_558;
}
return 0 ;
V_558:
F_259 ( V_8 ) ;
return V_252 ;
}
static int F_261 ( struct V_7 * V_8 )
{
struct V_453 * V_21 ;
int V_431 , V_252 ;
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
V_21 = V_8 -> V_454 [ V_431 ] ;
V_252 = F_248 ( V_8 , V_21 ) ;
if ( V_252 )
goto V_558;
}
F_258 ( F_221 , V_8 , 1 ) ;
return 0 ;
V_558:
F_256 ( V_8 ) ;
return V_252 ;
}
static T_9 F_262 ( int V_559 , void * V_560 )
{
struct V_7 * V_8 = (struct V_7 * ) V_560 ;
F_173 ( V_8 ) ;
F_263 ( & V_8 -> V_561 ) ;
return V_562 ;
}
static void F_264 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_563 * V_564 = V_253 -> V_564 ;
int V_565 = 0 ;
T_1 V_18 ;
if ( V_564 -> V_566 ) {
if ( ( V_8 -> V_424 != V_564 -> V_424 ) ||
( V_8 -> V_567 != V_564 -> V_567 ) ) {
T_1 V_18 ;
V_18 = F_4 ( V_8 -> V_394 + V_413 ) ;
V_18 &= ~ ( V_568 |
V_569 |
V_570 |
V_571 |
V_572 ) ;
if ( V_564 -> V_567 )
V_18 |= V_570 ;
if ( V_564 -> V_424 == V_573 )
V_18 |= V_569 ;
else if ( V_564 -> V_424 == V_574 )
V_18 |= V_568 ;
F_2 ( V_18 , V_8 -> V_394 + V_413 ) ;
V_8 -> V_567 = V_564 -> V_567 ;
V_8 -> V_424 = V_564 -> V_424 ;
}
}
if ( V_564 -> V_566 != V_8 -> V_566 ) {
if ( ! V_564 -> V_566 ) {
V_8 -> V_567 = - 1 ;
V_8 -> V_424 = 0 ;
}
V_8 -> V_566 = V_564 -> V_566 ;
V_565 = 1 ;
}
if ( V_565 ) {
if ( V_564 -> V_566 ) {
V_18 = F_4 ( V_8 -> V_394 + V_413 ) ;
V_18 |= ( V_575 |
V_576 ) ;
F_2 ( V_18 , V_8 -> V_394 + V_413 ) ;
F_196 ( V_8 ) ;
F_194 ( V_8 ) ;
} else {
F_195 ( V_8 ) ;
F_197 ( V_8 ) ;
}
F_265 ( V_564 ) ;
}
}
static void F_266 ( struct V_577 * V_578 )
{
T_10 V_579 ;
if ( ! V_578 -> V_580 ) {
V_578 -> V_580 = true ;
V_579 = V_581 ;
F_267 ( & V_578 -> V_582 , V_579 ,
V_583 ) ;
}
}
static void F_268 ( unsigned long V_4 )
{
struct V_288 * V_253 = (struct V_288 * ) V_4 ;
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_577 * V_578 = F_240 ( V_8 -> V_484 ) ;
unsigned int V_522 , V_516 ;
if ( ! F_269 ( V_253 ) )
return;
V_578 -> V_580 = false ;
V_516 = ( 1 << V_452 ) - 1 ;
V_522 = F_239 ( V_8 , V_516 ) ;
if ( V_522 )
F_266 ( V_578 ) ;
}
static enum V_584 F_270 ( struct V_585 * V_586 )
{
struct V_577 * V_578 = F_271 ( V_586 ,
struct V_577 ,
V_582 ) ;
F_272 ( & V_578 -> V_587 ) ;
return V_588 ;
}
static void F_273 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
T_1 V_30 = F_19 ( V_8 , V_26 ) ;
T_4 V_589 = F_18 ( V_8 , V_26 ) ;
switch ( V_30 & V_590 ) {
case V_591 :
F_160 ( V_8 -> V_253 , L_14 ,
V_30 , V_589 ) ;
break;
case V_592 :
F_160 ( V_8 -> V_253 , L_15 ,
V_30 , V_589 ) ;
break;
case V_593 :
F_160 ( V_8 -> V_253 , L_16 ,
V_30 , V_589 ) ;
break;
}
}
static void F_274 ( struct V_7 * V_8 , T_1 V_30 ,
struct V_34 * V_35 )
{
if ( ( ( V_30 & V_594 ) &&
! ( V_30 & V_595 ) ) ||
( V_30 & V_596 ) )
if ( ( ( V_30 & V_597 ) ||
( V_30 & V_598 ) ) &&
( V_30 & V_599 ) ) {
V_35 -> V_600 = 0 ;
V_35 -> V_601 = V_602 ;
return;
}
V_35 -> V_601 = V_603 ;
}
static int F_275 ( struct V_7 * V_8 ,
struct V_319 * V_324 , int V_320 )
{
T_2 V_17 ;
T_7 V_335 ;
void * V_370 ;
V_370 = F_149 ( V_8 , V_324 , & V_17 , & V_335 ,
V_323 ) ;
if ( ! V_370 )
return - V_167 ;
F_155 ( V_8 , V_320 , V_17 , V_335 ) ;
return 0 ;
}
static T_1 F_276 ( struct V_7 * V_8 , struct V_34 * V_35 )
{
if ( V_35 -> V_601 == V_604 ) {
int V_489 = 0 ;
T_6 V_490 ;
if ( V_35 -> V_605 == F_277 ( V_238 ) ) {
struct V_183 * V_606 = F_278 ( V_35 ) ;
V_489 = V_606 -> V_607 ;
V_490 = V_606 -> V_605 ;
} else if ( V_35 -> V_605 == F_277 ( V_245 ) ) {
struct V_202 * V_608 = F_279 ( V_35 ) ;
if ( F_280 ( V_35 ) > 0 )
V_489 = ( F_280 ( V_35 ) >> 2 ) ;
V_490 = V_608 -> V_609 ;
} else {
return V_497 ;
}
return F_218 ( F_281 ( V_35 ) ,
V_35 -> V_605 , V_489 , V_490 ) ;
}
return V_497 | V_493 ;
}
static int F_282 ( struct V_7 * V_8 , int V_610 ,
struct V_467 * V_380 )
{
struct V_288 * V_253 = V_8 -> V_253 ;
int V_535 ;
int V_611 = 0 ;
T_1 V_612 = 0 ;
T_1 V_613 = 0 ;
V_535 = F_200 ( V_8 , V_380 -> V_42 ) ;
if ( V_610 > V_535 )
V_610 = V_535 ;
while ( V_611 < V_610 ) {
struct V_25 * V_26 = F_204 ( V_380 ) ;
struct V_319 * V_324 ;
struct V_34 * V_35 ;
unsigned int V_321 ;
T_2 V_17 ;
T_7 V_335 ;
T_1 V_614 ;
int V_320 , V_615 , V_252 ;
void * V_4 ;
V_611 ++ ;
V_614 = F_19 ( V_8 , V_26 ) ;
V_615 = F_18 ( V_8 , V_26 ) ;
V_615 -= V_214 ;
V_17 = F_16 ( V_8 , V_26 ) ;
V_335 = F_17 ( V_8 , V_26 ) ;
V_4 = ( void * ) F_139 ( V_335 ) ;
V_320 = ( V_614 & V_536 ) >>
V_537 ;
V_324 = & V_8 -> V_2 -> V_349 [ V_320 ] ;
if ( V_614 & V_616 ) {
V_617:
V_253 -> V_618 . V_619 ++ ;
F_273 ( V_8 , V_26 ) ;
F_155 ( V_8 , V_320 , V_17 , V_335 ) ;
continue;
}
if ( V_324 -> V_321 > V_322 )
V_321 = 0 ;
else
V_321 = V_324 -> V_321 ;
V_35 = F_283 ( V_4 , V_321 ) ;
if ( ! V_35 ) {
F_198 ( V_8 -> V_253 , L_17 ) ;
goto V_617;
}
V_252 = F_275 ( V_8 , V_324 , V_320 ) ;
if ( V_252 ) {
F_160 ( V_8 -> V_253 , L_18 ) ;
goto V_617;
}
F_138 ( V_253 -> V_253 . V_363 , V_17 ,
V_324 -> V_332 , V_345 ) ;
V_612 ++ ;
V_613 += V_615 ;
F_284 ( V_35 , V_214 + V_534 ) ;
F_285 ( V_35 , V_615 ) ;
V_35 -> V_605 = F_286 ( V_35 , V_253 ) ;
F_274 ( V_8 , V_614 , V_35 ) ;
F_287 ( & V_8 -> V_561 , V_35 ) ;
}
if ( V_612 ) {
struct V_620 * V_618 = F_240 ( V_8 -> V_618 ) ;
F_288 ( & V_618 -> V_621 ) ;
V_618 -> V_622 += V_612 ;
V_618 -> V_615 += V_613 ;
F_289 ( & V_618 -> V_621 ) ;
}
F_290 () ;
F_202 ( V_8 , V_380 -> V_42 , V_611 , V_611 ) ;
return V_610 ;
}
static inline void
F_291 ( struct V_7 * V_8 , struct V_453 * V_21 ,
struct V_9 * V_538 )
{
T_2 V_14 =
F_7 ( V_8 , V_538 ) ;
T_4 V_623 =
F_10 ( V_8 , V_538 ) ;
F_138 ( V_8 -> V_253 -> V_253 . V_363 , V_14 ,
V_623 , V_515 ) ;
F_217 ( V_21 ) ;
}
static int F_292 ( struct V_7 * V_8 , struct V_34 * V_35 ,
struct V_453 * V_473 ,
struct V_453 * V_21 )
{
struct V_31 * V_32 = F_240 ( V_21 -> V_484 ) ;
struct V_9 * V_10 ;
int V_46 ;
T_2 V_14 ;
for ( V_46 = 0 ; V_46 < F_293 ( V_35 ) -> V_624 ; V_46 ++ ) {
T_11 * V_625 = & F_293 ( V_35 ) -> V_626 [ V_46 ] ;
void * V_627 = F_294 ( V_625 -> V_628 . V_629 ) + V_625 -> V_630 ;
V_10 = F_208 ( V_473 ) ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , V_625 -> V_20 ) ;
V_14 = F_150 ( V_8 -> V_253 -> V_253 . V_363 , V_627 ,
V_625 -> V_20 ,
V_515 ) ;
if ( F_153 ( V_8 -> V_253 -> V_253 . V_363 , V_14 ) ) {
F_217 ( V_21 ) ;
goto V_554;
}
F_14 ( V_8 , V_10 ,
V_14 & V_631 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_631 ) ;
if ( V_46 == ( F_293 ( V_35 ) -> V_624 - 1 ) ) {
F_13 ( V_8 , V_10 ,
V_632 ) ;
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
} else {
F_13 ( V_8 , V_10 , 0 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
}
}
return 0 ;
V_554:
for ( V_46 = V_46 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_10 = V_21 -> V_455 + V_46 ;
F_291 ( V_8 , V_21 , V_10 ) ;
}
return - V_167 ;
}
static int F_295 ( struct V_34 * V_35 , struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_453 * V_21 , * V_473 ;
struct V_31 * V_32 ;
struct V_9 * V_10 ;
T_2 V_14 ;
int V_626 = 0 ;
T_5 V_633 ;
T_1 V_634 ;
V_633 = F_296 ( V_35 ) ;
V_21 = V_8 -> V_454 [ V_633 ] ;
V_32 = F_240 ( V_21 -> V_484 ) ;
V_473 = & V_8 -> V_2 -> V_635 [ F_176 () ] ;
V_626 = F_293 ( V_35 ) -> V_624 + 1 ;
if ( F_210 ( V_8 -> V_2 , V_473 , V_626 ) ||
F_213 ( V_8 -> V_2 , V_21 ,
V_32 , V_626 ) ) {
V_626 = 0 ;
goto V_636;
}
V_10 = F_208 ( V_473 ) ;
F_12 ( V_8 , V_10 , V_21 -> V_42 ) ;
F_11 ( V_8 , V_10 , F_297 ( V_35 ) ) ;
V_14 = F_150 ( V_253 -> V_253 . V_363 , V_35 -> V_4 ,
F_297 ( V_35 ) , V_515 ) ;
if ( F_152 ( F_153 ( V_253 -> V_253 . V_363 , V_14 ) ) ) {
F_217 ( V_21 ) ;
V_626 = 0 ;
goto V_636;
}
F_14 ( V_8 , V_10 ,
V_14 & V_631 ) ;
F_9 ( V_8 , V_10 ,
V_14 & ~ V_631 ) ;
V_634 = F_276 ( V_8 , V_35 ) ;
if ( V_626 == 1 ) {
V_634 |= V_637 | V_632 ;
F_13 ( V_8 , V_10 , V_634 ) ;
F_21 ( V_8 , V_32 , V_35 , V_10 ) ;
} else {
V_634 |= V_637 | V_638 ;
F_13 ( V_8 , V_10 , V_634 ) ;
F_21 ( V_8 , V_32 , NULL , V_10 ) ;
if ( F_292 ( V_8 , V_35 , V_473 , V_21 ) ) {
F_291 ( V_8 , V_21 , V_10 ) ;
V_626 = 0 ;
goto V_636;
}
}
V_32 -> V_482 -= V_626 ;
V_32 -> V_474 += V_626 ;
V_473 -> V_474 += V_626 ;
F_290 () ;
F_209 ( V_8 , V_626 ) ;
if ( V_32 -> V_20 - V_32 -> V_474 < V_521 + 1 ) {
struct V_517 * V_518 = F_236 ( V_253 , V_633 ) ;
F_298 ( V_518 ) ;
}
V_636:
if ( V_626 > 0 ) {
struct V_620 * V_618 = F_240 ( V_8 -> V_618 ) ;
F_288 ( & V_618 -> V_621 ) ;
V_618 -> V_639 ++ ;
V_618 -> V_640 += V_35 -> V_283 ;
F_289 ( & V_618 -> V_621 ) ;
} else {
V_253 -> V_618 . V_641 ++ ;
F_231 ( V_35 ) ;
}
if ( V_32 -> V_474 >= V_21 -> V_642 )
F_235 ( V_8 , V_21 , V_32 ) ;
if ( V_32 -> V_474 <= V_626 && V_32 -> V_474 > 0 ) {
struct V_577 * V_578 = F_240 ( V_8 -> V_484 ) ;
F_266 ( V_578 ) ;
}
return V_643 ;
}
static inline void F_299 ( struct V_288 * V_253 , int V_516 )
{
if ( V_516 & V_644 )
F_160 ( V_253 , L_19 ) ;
if ( V_516 & V_645 )
F_160 ( V_253 , L_20 ) ;
if ( V_516 & V_646 )
F_160 ( V_253 , L_21 ) ;
}
static int F_300 ( struct V_647 * V_561 , int V_648 )
{
T_1 V_649 , V_650 , V_651 ;
int V_611 = 0 ;
struct V_7 * V_8 = F_101 ( V_561 -> V_253 ) ;
int V_6 = F_176 () ;
V_649 = F_6 ( V_8 -> V_2 , V_6 ,
F_301 ( V_8 -> V_42 ) ) ;
V_649 &= ~ V_652 ;
V_651 = V_649 & V_391 ;
if ( V_651 ) {
F_299 ( V_8 -> V_253 , V_651 ) ;
F_1 ( V_8 -> V_2 , V_653 , 0 ) ;
F_5 ( V_8 -> V_2 , V_6 ,
F_301 ( V_8 -> V_42 ) ,
V_649 & ~ V_391 ) ;
}
V_650 = V_649 & V_392 ;
V_650 |= V_8 -> V_654 ;
while ( V_650 && V_648 > 0 ) {
int V_474 ;
struct V_467 * V_380 ;
V_380 = F_232 ( V_8 , V_650 ) ;
if ( ! V_380 )
break;
V_474 = F_282 ( V_8 , V_648 , V_380 ) ;
V_611 += V_474 ;
V_648 -= V_474 ;
if ( V_648 > 0 ) {
V_650 &= ~ ( 1 << V_380 -> V_655 ) ;
}
}
if ( V_648 > 0 ) {
V_650 = 0 ;
F_302 ( V_561 , V_611 ) ;
F_169 ( V_8 ) ;
}
V_8 -> V_654 = V_650 ;
return V_611 ;
}
static void F_303 ( struct V_7 * V_8 )
{
struct V_288 * V_656 = V_8 -> V_253 ;
F_187 ( V_8 ) ;
F_222 ( V_8 ) ;
F_304 ( & V_8 -> V_561 ) ;
F_169 ( V_8 ) ;
F_182 ( V_8 ) ;
F_305 ( V_656 -> V_564 ) ;
F_306 ( V_8 -> V_253 ) ;
}
static void F_307 ( struct V_7 * V_8 )
{
struct V_288 * V_656 = V_8 -> V_253 ;
F_195 ( V_8 ) ;
F_199 ( 10 ) ;
F_173 ( V_8 ) ;
F_308 ( & V_8 -> V_561 ) ;
F_309 ( V_8 -> V_253 ) ;
F_310 ( V_8 -> V_253 ) ;
F_197 ( V_8 ) ;
F_183 ( V_8 ) ;
F_311 ( V_656 -> V_564 ) ;
}
static int F_312 ( struct V_288 * V_253 ,
struct V_657 * V_658 )
{
T_5 V_659 = V_658 -> V_660 ;
T_5 V_661 = V_658 -> V_662 ;
if ( V_658 -> V_660 == 0 || V_658 -> V_662 == 0 )
return - V_49 ;
if ( V_658 -> V_660 > V_663 )
V_659 = V_663 ;
else if ( ! F_122 ( V_658 -> V_660 , 16 ) )
V_659 = F_131 ( V_658 -> V_660 , 16 ) ;
if ( V_658 -> V_662 > V_664 )
V_661 = V_664 ;
else if ( ! F_122 ( V_658 -> V_662 , 32 ) )
V_661 = F_131 ( V_658 -> V_662 , 32 ) ;
if ( V_658 -> V_660 != V_659 ) {
F_313 ( V_253 , L_22 ,
V_658 -> V_660 , V_659 ) ;
V_658 -> V_660 = V_659 ;
}
if ( V_658 -> V_662 != V_661 ) {
F_313 ( V_253 , L_23 ,
V_658 -> V_662 , V_661 ) ;
V_658 -> V_662 = V_661 ;
}
return 0 ;
}
static void F_314 ( struct V_7 * V_8 , unsigned char * V_627 )
{
T_1 V_665 , V_666 , V_667 ;
V_665 = F_4 ( V_8 -> V_394 + V_422 ) ;
V_666 = F_4 ( V_8 -> V_2 -> V_668 + V_669 ) ;
V_667 = F_4 ( V_8 -> V_2 -> V_668 + V_670 ) ;
V_627 [ 0 ] = ( V_667 >> 24 ) & 0xFF ;
V_627 [ 1 ] = ( V_667 >> 16 ) & 0xFF ;
V_627 [ 2 ] = ( V_667 >> 8 ) & 0xFF ;
V_627 [ 3 ] = V_667 & 0xFF ;
V_627 [ 4 ] = V_666 & 0xFF ;
V_627 [ 5 ] = ( V_665 >> V_671 ) & 0xFF ;
}
static int F_315 ( struct V_7 * V_8 )
{
struct V_563 * V_672 ;
V_672 = F_316 ( V_8 -> V_253 , V_8 -> V_673 , F_264 , 0 ,
V_8 -> V_397 ) ;
if ( ! V_672 ) {
F_160 ( V_8 -> V_253 , L_24 ) ;
return - V_674 ;
}
V_672 -> V_675 &= V_676 ;
V_672 -> V_677 = V_672 -> V_675 ;
V_8 -> V_566 = 0 ;
V_8 -> V_567 = 0 ;
V_8 -> V_424 = 0 ;
return 0 ;
}
static void F_317 ( struct V_7 * V_8 )
{
struct V_288 * V_656 = V_8 -> V_253 ;
F_318 ( V_656 -> V_564 ) ;
}
static int F_319 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
unsigned char V_678 [ V_130 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_252 ;
V_252 = F_97 ( V_8 -> V_2 , V_8 -> V_42 , V_678 , true ) ;
if ( V_252 ) {
F_160 ( V_253 , L_25 ) ;
return V_252 ;
}
V_252 = F_97 ( V_8 -> V_2 , V_8 -> V_42 ,
V_253 -> V_289 , true ) ;
if ( V_252 ) {
F_160 ( V_253 , L_26 ) ;
return V_252 ;
}
V_252 = F_104 ( V_8 -> V_2 , V_8 -> V_42 , V_293 ) ;
if ( V_252 ) {
F_160 ( V_253 , L_27 ) ;
return V_252 ;
}
V_252 = F_105 ( V_8 ) ;
if ( V_252 ) {
F_160 ( V_253 , L_28 ) ;
return V_252 ;
}
V_252 = F_260 ( V_8 ) ;
if ( V_252 ) {
F_160 ( V_8 -> V_253 , L_29 ) ;
return V_252 ;
}
V_252 = F_261 ( V_8 ) ;
if ( V_252 ) {
F_160 ( V_8 -> V_253 , L_30 ) ;
goto V_679;
}
V_252 = F_320 ( V_8 -> V_559 , F_262 , 0 , V_253 -> V_680 , V_8 ) ;
if ( V_252 ) {
F_160 ( V_8 -> V_253 , L_31 , V_8 -> V_559 ) ;
goto V_681;
}
F_309 ( V_8 -> V_253 ) ;
V_252 = F_315 ( V_8 ) ;
if ( V_252 < 0 )
goto V_682;
F_258 ( F_178 , V_8 , 1 ) ;
F_303 ( V_8 ) ;
return 0 ;
V_682:
F_321 ( V_8 -> V_559 , V_8 ) ;
V_681:
F_256 ( V_8 ) ;
V_679:
F_259 ( V_8 ) ;
return V_252 ;
}
static int F_322 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_577 * V_578 ;
int V_6 ;
F_307 ( V_8 ) ;
F_317 ( V_8 ) ;
F_258 ( F_175 , V_8 , 1 ) ;
F_321 ( V_8 -> V_559 , V_8 ) ;
F_170 (cpu) {
V_578 = F_214 ( V_8 -> V_484 , V_6 ) ;
F_323 ( & V_578 -> V_582 ) ;
V_578 -> V_580 = false ;
F_324 ( & V_578 -> V_587 ) ;
}
F_259 ( V_8 ) ;
F_256 ( V_8 ) ;
return 0 ;
}
static void F_325 ( struct V_288 * V_253 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_683 * V_684 ;
int V_42 = V_8 -> V_42 ;
bool V_685 = V_253 -> V_433 & V_686 ;
F_61 ( V_2 , V_42 , V_253 -> V_433 & V_687 ) ;
F_62 ( V_2 , V_42 , V_133 , V_685 ) ;
F_62 ( V_2 , V_42 , V_216 , V_685 ) ;
F_103 ( V_2 , V_42 ) ;
if ( V_685 && ! F_326 ( V_253 ) ) {
F_327 (ha, dev)
F_97 ( V_2 , V_42 , V_684 -> V_627 , true ) ;
}
}
static int F_328 ( struct V_288 * V_253 , void * V_629 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
const struct V_688 * V_627 = V_629 ;
int V_252 ;
if ( ! F_329 ( V_627 -> V_689 ) ) {
V_252 = - V_690 ;
goto V_691;
}
if ( ! F_269 ( V_253 ) ) {
V_252 = F_100 ( V_253 , V_627 -> V_689 ) ;
if ( ! V_252 )
return 0 ;
V_252 = F_100 ( V_253 , V_253 -> V_289 ) ;
if ( V_252 )
goto V_691;
}
F_307 ( V_8 ) ;
V_252 = F_100 ( V_253 , V_627 -> V_689 ) ;
if ( ! V_252 )
goto V_692;
V_252 = F_100 ( V_253 , V_253 -> V_289 ) ;
if ( V_252 )
goto V_691;
V_692:
F_303 ( V_8 ) ;
F_196 ( V_8 ) ;
F_194 ( V_8 ) ;
return 0 ;
V_691:
F_160 ( V_253 , L_32 ) ;
return V_252 ;
}
static int F_330 ( struct V_288 * V_253 , int V_386 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
int V_252 ;
if ( ! F_122 ( F_167 ( V_386 ) , 8 ) ) {
F_313 ( V_253 , L_33 , V_386 ,
F_131 ( F_167 ( V_386 ) , 8 ) ) ;
V_386 = F_131 ( F_167 ( V_386 ) , 8 ) ;
}
if ( ! F_269 ( V_253 ) ) {
V_252 = F_166 ( V_253 , V_386 ) ;
if ( ! V_252 ) {
V_8 -> V_330 = F_167 ( V_386 ) ;
return 0 ;
}
V_252 = F_166 ( V_253 , V_253 -> V_386 ) ;
if ( V_252 )
goto V_691;
}
F_307 ( V_8 ) ;
V_252 = F_166 ( V_253 , V_386 ) ;
if ( ! V_252 ) {
V_8 -> V_330 = F_167 ( V_386 ) ;
goto V_692;
}
V_252 = F_166 ( V_253 , V_253 -> V_386 ) ;
if ( V_252 )
goto V_691;
V_692:
F_303 ( V_8 ) ;
F_196 ( V_8 ) ;
F_194 ( V_8 ) ;
return 0 ;
V_691:
F_160 ( V_253 , L_34 ) ;
return V_252 ;
}
static void
F_331 ( struct V_288 * V_253 , struct V_693 * V_618 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
unsigned int V_120 ;
int V_6 ;
F_332 (cpu) {
struct V_620 * V_694 ;
T_3 V_622 ;
T_3 V_615 ;
T_3 V_639 ;
T_3 V_640 ;
V_694 = F_214 ( V_8 -> V_618 , V_6 ) ;
do {
V_120 = F_333 ( & V_694 -> V_621 ) ;
V_622 = V_694 -> V_622 ;
V_615 = V_694 -> V_615 ;
V_639 = V_694 -> V_639 ;
V_640 = V_694 -> V_640 ;
} while ( F_334 ( & V_694 -> V_621 , V_120 ) );
V_618 -> V_622 += V_622 ;
V_618 -> V_615 += V_615 ;
V_618 -> V_639 += V_639 ;
V_618 -> V_640 += V_640 ;
}
V_618 -> V_619 = V_253 -> V_618 . V_619 ;
V_618 -> V_695 = V_253 -> V_618 . V_695 ;
V_618 -> V_641 = V_253 -> V_618 . V_641 ;
}
static int F_335 ( struct V_288 * V_253 , struct V_696 * V_697 , int V_698 )
{
int V_166 ;
if ( ! V_253 -> V_564 )
return - V_699 ;
V_166 = F_336 ( V_253 -> V_564 , V_697 , V_698 ) ;
if ( ! V_166 )
F_264 ( V_253 ) ;
return V_166 ;
}
static int F_337 ( struct V_288 * V_253 ,
struct V_700 * V_701 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
int V_431 ;
for ( V_431 = 0 ; V_431 < V_382 ; V_431 ++ ) {
struct V_467 * V_380 = V_8 -> V_354 [ V_431 ] ;
V_380 -> V_513 = V_701 -> V_702 ;
V_380 -> V_503 = V_701 -> V_703 ;
F_224 ( V_8 , V_380 ) ;
F_228 ( V_8 , V_380 ) ;
}
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
struct V_453 * V_21 = V_8 -> V_454 [ V_431 ] ;
V_21 -> V_642 = V_701 -> V_704 ;
}
return 0 ;
}
static int F_338 ( struct V_288 * V_253 ,
struct V_700 * V_701 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
V_701 -> V_702 = V_8 -> V_354 [ 0 ] -> V_513 ;
V_701 -> V_703 = V_8 -> V_354 [ 0 ] -> V_503 ;
V_701 -> V_704 = V_8 -> V_454 [ 0 ] -> V_642 ;
return 0 ;
}
static void F_339 ( struct V_288 * V_253 ,
struct V_705 * V_706 )
{
F_340 ( V_706 -> V_707 , V_708 ,
sizeof( V_706 -> V_707 ) ) ;
F_340 ( V_706 -> V_709 , V_710 ,
sizeof( V_706 -> V_709 ) ) ;
F_340 ( V_706 -> V_711 , F_341 ( & V_253 -> V_253 ) ,
sizeof( V_706 -> V_711 ) ) ;
}
static void F_342 ( struct V_288 * V_253 ,
struct V_657 * V_658 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
V_658 -> V_712 = V_663 ;
V_658 -> V_713 = V_664 ;
V_658 -> V_660 = V_8 -> V_529 ;
V_658 -> V_662 = V_8 -> V_540 ;
}
static int F_343 ( struct V_288 * V_253 ,
struct V_657 * V_658 )
{
struct V_7 * V_8 = F_101 ( V_253 ) ;
T_5 V_714 = V_8 -> V_529 ;
T_5 V_715 = V_8 -> V_540 ;
int V_252 ;
V_252 = F_312 ( V_253 , V_658 ) ;
if ( V_252 )
return V_252 ;
if ( ! F_269 ( V_253 ) ) {
V_8 -> V_529 = V_658 -> V_660 ;
V_8 -> V_540 = V_658 -> V_662 ;
return 0 ;
}
F_307 ( V_8 ) ;
F_259 ( V_8 ) ;
F_256 ( V_8 ) ;
V_8 -> V_529 = V_658 -> V_660 ;
V_8 -> V_540 = V_658 -> V_662 ;
V_252 = F_260 ( V_8 ) ;
if ( V_252 ) {
V_8 -> V_529 = V_714 ;
V_658 -> V_660 = V_714 ;
V_252 = F_260 ( V_8 ) ;
if ( V_252 )
goto V_716;
}
V_252 = F_261 ( V_8 ) ;
if ( V_252 ) {
V_8 -> V_540 = V_715 ;
V_658 -> V_662 = V_715 ;
V_252 = F_261 ( V_8 ) ;
if ( V_252 )
goto V_717;
}
F_303 ( V_8 ) ;
F_196 ( V_8 ) ;
F_194 ( V_8 ) ;
return 0 ;
V_717:
F_259 ( V_8 ) ;
V_716:
F_160 ( V_253 , L_35 ) ;
return V_252 ;
}
static int F_344 ( struct V_7 * V_8 )
{
struct V_334 * V_253 = V_8 -> V_253 -> V_253 . V_363 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_31 * V_32 ;
int V_431 , V_6 , V_252 ;
if ( V_8 -> V_314 + V_382 >
V_209 * V_2 -> V_718 )
return - V_49 ;
F_197 ( V_8 ) ;
F_183 ( V_8 ) ;
V_8 -> V_454 = F_90 ( V_253 , V_452 , sizeof( * V_8 -> V_454 ) ,
V_117 ) ;
if ( ! V_8 -> V_454 )
return - V_167 ;
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
int V_719 = F_23 ( V_8 -> V_42 , V_431 ) ;
struct V_453 * V_21 ;
V_21 = F_345 ( V_253 , sizeof( * V_21 ) , V_117 ) ;
if ( ! V_21 ) {
V_252 = - V_167 ;
goto V_720;
}
V_21 -> V_484 = F_346 ( struct V_31 ) ;
if ( ! V_21 -> V_484 ) {
V_252 = - V_167 ;
goto V_720;
}
V_21 -> V_42 = V_719 ;
V_21 -> V_519 = V_431 ;
V_21 -> V_642 = V_721 ;
F_170 (cpu) {
V_32 = F_214 ( V_21 -> V_484 , V_6 ) ;
V_32 -> V_6 = V_6 ;
}
V_8 -> V_454 [ V_431 ] = V_21 ;
}
V_8 -> V_354 = F_90 ( V_253 , V_382 , sizeof( * V_8 -> V_354 ) ,
V_117 ) ;
if ( ! V_8 -> V_354 ) {
V_252 = - V_167 ;
goto V_720;
}
for ( V_431 = 0 ; V_431 < V_382 ; V_431 ++ ) {
struct V_467 * V_380 ;
V_380 = F_345 ( V_253 , sizeof( * V_380 ) , V_117 ) ;
if ( ! V_380 ) {
V_252 = - V_167 ;
goto V_720;
}
V_380 -> V_42 = V_8 -> V_314 + V_431 ;
V_380 -> V_8 = V_8 -> V_42 ;
V_380 -> V_655 = V_431 ;
V_8 -> V_354 [ V_431 ] = V_380 ;
}
if ( V_2 -> V_11 == V_12 ) {
F_1 ( V_2 , F_347 ( V_8 -> V_42 ) ,
V_382 ) ;
} else {
T_1 V_18 ;
V_18 = ( V_8 -> V_42 << V_722 ) ;
F_1 ( V_2 , V_723 , V_18 ) ;
V_18 = ( V_382 << V_724 ) ;
F_1 ( V_2 , V_725 , V_18 ) ;
}
for ( V_431 = 0 ; V_431 < V_382 ; V_431 ++ ) {
struct V_467 * V_380 = V_8 -> V_354 [ V_431 ] ;
V_380 -> V_20 = V_8 -> V_529 ;
V_380 -> V_503 = V_726 ;
V_380 -> V_513 = V_727 ;
}
F_195 ( V_8 ) ;
F_188 ( V_8 ) ;
F_111 ( V_8 ) ;
F_109 ( V_8 ) ;
V_8 -> V_330 = F_167 ( V_8 -> V_253 -> V_386 ) ;
V_252 = F_164 ( V_8 ) ;
if ( V_252 )
goto V_720;
return 0 ;
V_720:
for ( V_431 = 0 ; V_431 < V_452 ; V_431 ++ ) {
if ( ! V_8 -> V_454 [ V_431 ] )
continue;
F_348 ( V_8 -> V_454 [ V_431 ] -> V_484 ) ;
}
return V_252 ;
}
static int F_349 ( struct V_250 * V_251 ,
struct V_728 * V_729 ,
struct V_1 * V_2 )
{
struct V_728 * V_673 ;
struct V_7 * V_8 ;
struct V_577 * V_578 ;
struct V_288 * V_253 ;
struct V_730 * V_731 ;
const char * V_732 ;
const char * V_733 ;
char V_734 [ V_130 ] = { 0 } ;
T_1 V_42 ;
int V_735 ;
int V_736 ;
int V_252 , V_46 , V_6 ;
V_253 = F_350 ( sizeof( * V_8 ) , V_452 , V_382 ) ;
if ( ! V_253 )
return - V_167 ;
V_673 = F_351 ( V_729 , L_36 , 0 ) ;
if ( ! V_673 ) {
F_125 ( & V_251 -> V_253 , L_37 ) ;
V_252 = - V_674 ;
goto V_737;
}
V_736 = F_352 ( V_729 ) ;
if ( V_736 < 0 ) {
F_125 ( & V_251 -> V_253 , L_38 ) ;
V_252 = V_736 ;
goto V_737;
}
if ( F_353 ( V_729 , L_39 , & V_42 ) ) {
V_252 = - V_49 ;
F_125 ( & V_251 -> V_253 , L_40 ) ;
goto V_737;
}
V_253 -> V_738 = V_664 ;
V_253 -> V_739 = 5 * V_740 ;
V_253 -> V_741 = & V_742 ;
V_253 -> V_743 = & V_744 ;
V_8 = F_101 ( V_253 ) ;
V_8 -> V_559 = F_354 ( V_729 , 0 ) ;
if ( V_8 -> V_559 <= 0 ) {
V_252 = - V_49 ;
goto V_737;
}
if ( F_355 ( V_729 , L_41 ) )
V_8 -> V_433 |= V_434 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_42 = V_42 ;
if ( V_2 -> V_11 == V_12 )
V_8 -> V_314 = V_8 -> V_42 * V_382 ;
else
V_8 -> V_314 = V_8 -> V_42 * V_2 -> V_718 ;
V_8 -> V_673 = V_673 ;
V_8 -> V_397 = V_736 ;
if ( V_2 -> V_11 == V_12 ) {
V_731 = F_356 ( V_251 , V_745 , 2 + V_42 ) ;
V_8 -> V_394 = F_357 ( & V_251 -> V_253 , V_731 ) ;
if ( F_358 ( V_8 -> V_394 ) ) {
V_252 = F_359 ( V_8 -> V_394 ) ;
goto V_682;
}
} else {
if ( F_353 ( V_729 , L_42 ,
& V_8 -> V_393 ) ) {
V_252 = - V_49 ;
F_125 ( & V_251 -> V_253 , L_43 ) ;
goto V_682;
}
V_8 -> V_394 = V_2 -> V_746 + F_360 ( V_8 -> V_393 ) ;
}
V_8 -> V_618 = F_361 ( struct V_620 ) ;
if ( ! V_8 -> V_618 ) {
V_252 = - V_167 ;
goto V_682;
}
V_732 = F_362 ( V_729 ) ;
if ( V_732 && F_329 ( V_732 ) ) {
V_733 = L_44 ;
F_102 ( V_253 -> V_289 , V_732 ) ;
} else {
if ( V_2 -> V_11 == V_12 )
F_314 ( V_8 , V_734 ) ;
if ( F_329 ( V_734 ) ) {
V_733 = L_45 ;
F_102 ( V_253 -> V_289 , V_734 ) ;
} else {
V_733 = L_46 ;
F_363 ( V_253 ) ;
}
}
V_8 -> V_540 = V_664 ;
V_8 -> V_529 = V_663 ;
V_8 -> V_253 = V_253 ;
F_364 ( V_253 , & V_251 -> V_253 ) ;
V_252 = F_344 ( V_8 ) ;
if ( V_252 < 0 ) {
F_125 ( & V_251 -> V_253 , L_47 , V_42 ) ;
goto V_747;
}
F_180 ( V_8 ) ;
F_184 ( V_8 ) ;
if ( V_2 -> V_11 == V_12 )
F_181 ( V_8 ) ;
F_186 ( V_8 ) ;
V_8 -> V_484 = F_346 ( struct V_577 ) ;
if ( ! V_8 -> V_484 ) {
V_252 = - V_167 ;
goto V_748;
}
F_170 (cpu) {
V_578 = F_214 ( V_8 -> V_484 , V_6 ) ;
F_365 ( & V_578 -> V_582 , V_749 ,
V_583 ) ;
V_578 -> V_582 . V_750 = F_270 ;
V_578 -> V_580 = false ;
F_366 ( & V_578 -> V_587 , F_268 ,
( unsigned long ) V_253 ) ;
}
F_367 ( V_253 , & V_8 -> V_561 , F_300 , V_751 ) ;
V_735 = V_752 | V_753 ;
V_253 -> V_735 = V_735 | V_754 ;
V_253 -> V_755 |= V_735 | V_754 | V_756 ;
V_253 -> V_757 |= V_735 ;
V_253 -> V_758 = V_759 ;
V_253 -> V_760 = 9676 ;
V_252 = F_368 ( V_253 ) ;
if ( V_252 < 0 ) {
F_125 ( & V_251 -> V_253 , L_48 ) ;
goto V_761;
}
F_313 ( V_253 , L_49 , V_733 , V_253 -> V_289 ) ;
V_2 -> V_762 [ V_42 ] = V_8 ;
return 0 ;
V_761:
F_348 ( V_8 -> V_484 ) ;
V_748:
for ( V_46 = 0 ; V_46 < V_452 ; V_46 ++ )
F_348 ( V_8 -> V_454 [ V_46 ] -> V_484 ) ;
V_747:
F_348 ( V_8 -> V_618 ) ;
V_682:
F_369 ( V_8 -> V_559 ) ;
V_737:
F_370 ( V_673 ) ;
F_371 ( V_253 ) ;
return V_252 ;
}
static void F_372 ( struct V_7 * V_8 )
{
int V_46 ;
F_373 ( V_8 -> V_253 ) ;
F_370 ( V_8 -> V_673 ) ;
F_348 ( V_8 -> V_484 ) ;
F_348 ( V_8 -> V_618 ) ;
for ( V_46 = 0 ; V_46 < V_452 ; V_46 ++ )
F_348 ( V_8 -> V_454 [ V_46 ] -> V_484 ) ;
F_369 ( V_8 -> V_559 ) ;
F_371 ( V_8 -> V_253 ) ;
}
static void F_374 ( const struct V_763 * V_764 ,
struct V_1 * V_2 )
{
T_1 V_765 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 6 ; V_46 ++ ) {
F_1 ( V_2 , F_375 ( V_46 ) , 0 ) ;
F_1 ( V_2 , F_376 ( V_46 ) , 0 ) ;
if ( V_46 < 4 )
F_1 ( V_2 , F_377 ( V_46 ) , 0 ) ;
}
V_765 = 0 ;
for ( V_46 = 0 ; V_46 < V_764 -> V_766 ; V_46 ++ ) {
const struct V_767 * V_768 = V_764 -> V_768 + V_46 ;
F_1 ( V_2 , F_375 ( V_46 ) ,
( V_768 -> V_394 & 0xffff0000 ) | ( V_768 -> V_769 << 8 ) |
V_764 -> V_770 ) ;
F_1 ( V_2 , F_376 ( V_46 ) ,
( V_768 -> V_20 - 1 ) & 0xffff0000 ) ;
V_765 |= ( 1 << V_46 ) ;
}
F_1 ( V_2 , V_771 , V_765 ) ;
}
static void F_378 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_209 ; V_8 ++ ) {
F_1 ( V_2 , F_379 ( V_8 ) ,
V_772 ) ;
F_1 ( V_2 , F_380 ( V_8 ) ,
V_773 ) ;
}
F_1 ( V_2 , V_774 ,
V_775 ) ;
F_1 ( V_2 , V_776 , 0x1 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
T_1 V_18 , V_777 , V_778 ;
F_1 ( V_2 , V_367 , 0x0 ) ;
V_777 = V_779
<< V_780 ;
V_777 |= V_781
<< V_782 ;
V_778 = V_783
<< V_780 ;
V_778 |= V_781
<< V_782 ;
F_1 ( V_2 , V_784 , V_778 ) ;
F_1 ( V_2 , V_785 , V_777 ) ;
F_1 ( V_2 , V_786 , V_777 ) ;
F_1 ( V_2 , V_787 , V_778 ) ;
F_1 ( V_2 , V_788 , V_777 ) ;
F_1 ( V_2 , V_789 , V_778 ) ;
F_1 ( V_2 , V_790 , V_777 ) ;
F_1 ( V_2 , V_791 , V_778 ) ;
V_18 = V_792
<< V_793 ;
V_18 |= V_794
<< V_795 ;
F_1 ( V_2 , V_796 , V_18 ) ;
F_1 ( V_2 , V_797 , V_18 ) ;
V_18 = V_779
<< V_793 ;
V_18 |= V_781
<< V_795 ;
F_1 ( V_2 , V_798 , V_18 ) ;
V_18 = V_783
<< V_793 ;
V_18 |= V_781
<< V_795 ;
F_1 ( V_2 , V_799 , V_18 ) ;
}
static int F_382 ( struct V_250 * V_251 , struct V_1 * V_2 )
{
const struct V_763 * V_800 ;
int V_252 , V_46 ;
T_1 V_18 ;
if ( V_382 % 4 || ( V_382 > V_2 -> V_718 ) ||
( V_452 > V_43 ) ) {
F_125 ( & V_251 -> V_253 , L_50 ) ;
return - V_49 ;
}
V_800 = F_383 () ;
if ( V_800 )
F_374 ( V_800 , V_2 ) ;
if ( V_2 -> V_11 == V_337 )
F_381 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_18 = F_4 ( V_2 -> V_668 + V_801 ) ;
V_18 |= V_802 ;
F_2 ( V_18 , V_2 -> V_668 + V_801 ) ;
} else {
V_18 = F_4 ( V_2 -> V_746 + V_803 ) ;
V_18 &= ~ V_804 ;
F_2 ( V_18 , V_2 -> V_746 + V_803 ) ;
}
V_2 -> V_635 = F_90 ( & V_251 -> V_253 , F_216 () ,
sizeof( * V_2 -> V_635 ) ,
V_117 ) ;
if ( ! V_2 -> V_635 )
return - V_167 ;
F_170 (i) {
V_2 -> V_635 [ V_46 ] . V_42 = V_46 ;
V_2 -> V_635 [ V_46 ] . V_20 = V_805 ;
V_252 = F_241 ( V_251 , & V_2 -> V_635 [ V_46 ] ,
V_805 , V_46 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
}
F_378 ( V_2 ) ;
for ( V_46 = 0 ; V_46 < V_209 ; V_46 ++ ) {
if ( V_2 -> V_11 == V_12 ) {
F_1 ( V_2 , F_347 ( V_46 ) ,
V_382 ) ;
continue;
} else {
T_1 V_18 ;
V_18 = ( V_46 << V_722 ) ;
F_1 ( V_2 , V_723 , V_18 ) ;
V_18 = ( V_382 << V_724 ) ;
F_1 ( V_2 , V_725 , V_18 ) ;
}
}
if ( V_2 -> V_11 == V_12 )
F_2 ( V_806 ,
V_2 -> V_668 + V_807 ) ;
F_1 ( V_2 , V_808 , 0x1 ) ;
V_252 = F_143 ( V_251 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
V_252 = F_94 ( V_251 , V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
F_108 ( V_2 ) ;
return 0 ;
}
static int F_384 ( struct V_250 * V_251 )
{
struct V_728 * V_809 = V_251 -> V_253 . V_810 ;
struct V_728 * V_729 ;
struct V_1 * V_2 ;
struct V_730 * V_731 ;
void T_12 * V_394 ;
int V_811 , V_6 ;
int V_252 ;
V_2 = F_345 ( & V_251 -> V_253 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_167 ;
V_2 -> V_11 =
( unsigned long ) F_385 ( & V_251 -> V_253 ) ;
V_731 = F_356 ( V_251 , V_745 , 0 ) ;
V_394 = F_357 ( & V_251 -> V_253 , V_731 ) ;
if ( F_358 ( V_394 ) )
return F_359 ( V_394 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_731 = F_356 ( V_251 , V_745 , 1 ) ;
V_2 -> V_668 = F_357 ( & V_251 -> V_253 , V_731 ) ;
if ( F_358 ( V_2 -> V_668 ) )
return F_359 ( V_2 -> V_668 ) ;
} else {
V_731 = F_356 ( V_251 , V_745 , 1 ) ;
V_2 -> V_746 = F_357 ( & V_251 -> V_253 , V_731 ) ;
if ( F_358 ( V_2 -> V_746 ) )
return F_359 ( V_2 -> V_746 ) ;
}
F_170 (cpu) {
T_1 V_812 ;
V_812 = ( V_2 -> V_11 == V_12 ?
V_813 : V_814 ) ;
V_2 -> V_5 [ V_6 ] = V_394 + V_6 * V_812 ;
}
if ( V_2 -> V_11 == V_12 )
V_2 -> V_718 = 8 ;
else
V_2 -> V_718 = 32 ;
V_2 -> V_815 = F_386 ( & V_251 -> V_253 , L_51 ) ;
if ( F_358 ( V_2 -> V_815 ) )
return F_359 ( V_2 -> V_815 ) ;
V_252 = F_387 ( V_2 -> V_815 ) ;
if ( V_252 < 0 )
return V_252 ;
V_2 -> V_816 = F_386 ( & V_251 -> V_253 , L_52 ) ;
if ( F_358 ( V_2 -> V_816 ) ) {
V_252 = F_359 ( V_2 -> V_816 ) ;
goto V_817;
}
V_252 = F_387 ( V_2 -> V_816 ) ;
if ( V_252 < 0 )
goto V_817;
if ( V_2 -> V_11 == V_337 ) {
V_2 -> V_818 = F_386 ( & V_251 -> V_253 , L_53 ) ;
if ( F_358 ( V_2 -> V_818 ) ) {
V_252 = F_359 ( V_2 -> V_818 ) ;
goto V_819;
}
V_252 = F_387 ( V_2 -> V_818 ) ;
if ( V_252 < 0 )
goto V_819;
}
V_2 -> V_440 = F_388 ( V_2 -> V_815 ) ;
if ( V_2 -> V_11 == V_337 ) {
V_252 = F_389 ( & V_251 -> V_253 , F_390 ( 40 ) ) ;
if ( V_252 )
goto V_820;
V_252 = F_391 ( & V_251 -> V_253 , F_390 ( 32 ) ) ;
if ( V_252 )
goto V_820;
}
V_252 = F_382 ( V_251 , V_2 ) ;
if ( V_252 < 0 ) {
F_125 ( & V_251 -> V_253 , L_54 ) ;
goto V_820;
}
V_811 = F_392 ( V_809 ) ;
if ( V_811 == 0 ) {
F_125 ( & V_251 -> V_253 , L_55 ) ;
V_252 = - V_674 ;
goto V_820;
}
V_2 -> V_762 = F_90 ( & V_251 -> V_253 , V_811 ,
sizeof( * V_2 -> V_762 ) ,
V_117 ) ;
if ( ! V_2 -> V_762 ) {
V_252 = - V_167 ;
goto V_820;
}
F_393 (dn, port_node) {
V_252 = F_349 ( V_251 , V_729 , V_2 ) ;
if ( V_252 < 0 )
goto V_820;
}
F_394 ( V_251 , V_2 ) ;
return 0 ;
V_820:
if ( V_2 -> V_11 == V_337 )
F_395 ( V_2 -> V_818 ) ;
V_819:
F_395 ( V_2 -> V_816 ) ;
V_817:
F_395 ( V_2 -> V_815 ) ;
return V_252 ;
}
static int F_396 ( struct V_250 * V_251 )
{
struct V_1 * V_2 = F_397 ( V_251 ) ;
struct V_728 * V_809 = V_251 -> V_253 . V_810 ;
struct V_728 * V_729 ;
int V_46 = 0 ;
F_393 (dn, port_node) {
if ( V_2 -> V_762 [ V_46 ] )
F_372 ( V_2 -> V_762 [ V_46 ] ) ;
V_46 ++ ;
}
for ( V_46 = 0 ; V_46 < V_348 ; V_46 ++ ) {
struct V_319 * V_324 = & V_2 -> V_349 [ V_46 ] ;
F_140 ( V_251 , V_2 , V_324 ) ;
}
F_170 (i) {
struct V_453 * V_473 = & V_2 -> V_635 [ V_46 ] ;
F_124 ( & V_251 -> V_253 ,
V_805 * V_525 ,
V_473 -> V_455 ,
V_473 -> V_526 ) ;
}
F_395 ( V_2 -> V_818 ) ;
F_395 ( V_2 -> V_815 ) ;
F_395 ( V_2 -> V_816 ) ;
return 0 ;
}
