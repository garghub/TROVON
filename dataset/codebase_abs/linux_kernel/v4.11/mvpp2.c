static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_8 ++ ;
if ( V_7 -> V_8 == V_7 -> V_9 )
V_7 -> V_8 = 0 ;
}
static void F_6 ( struct V_6 * V_7 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 =
V_7 -> V_16 + V_7 -> V_17 ;
V_15 -> V_11 = V_11 ;
V_15 -> V_9 = V_13 -> V_18 ;
V_15 -> V_19 = V_13 -> V_20 + V_13 -> V_21 ;
V_7 -> V_17 ++ ;
if ( V_7 -> V_17 == V_7 -> V_9 )
V_7 -> V_17 = 0 ;
}
static inline int F_7 ( struct V_22 * V_23 )
{
return V_24 + V_23 -> V_25 ;
}
static inline int F_8 ( int V_23 , int V_26 )
{
return ( V_24 + V_23 ) * V_27 + V_26 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_30 ;
if ( V_29 -> V_31 > V_32 - 1 )
return - V_33 ;
V_29 -> V_34 . V_35 [ V_36 ] &= ~ V_37 ;
F_1 ( V_2 , V_38 , V_29 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ )
F_1 ( V_2 , F_10 ( V_30 ) , V_29 -> V_34 . V_35 [ V_30 ] ) ;
F_1 ( V_2 , V_40 , V_29 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_41 ; V_30 ++ )
F_1 ( V_2 , F_11 ( V_30 ) , V_29 -> V_42 . V_35 [ V_30 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_30 ;
if ( V_29 -> V_31 > V_32 - 1 )
return - V_33 ;
F_1 ( V_2 , V_38 , V_29 -> V_31 ) ;
V_29 -> V_34 . V_35 [ V_36 ] = F_3 ( V_2 ,
F_10 ( V_36 ) ) ;
if ( V_29 -> V_34 . V_35 [ V_36 ] & V_37 )
return V_43 ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ )
V_29 -> V_34 . V_35 [ V_30 ] = F_3 ( V_2 , F_10 ( V_30 ) ) ;
F_1 ( V_2 , V_40 , V_29 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_41 ; V_30 ++ )
V_29 -> V_42 . V_35 [ V_30 ] = F_3 ( V_2 , F_11 ( V_30 ) ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , int V_31 )
{
F_1 ( V_2 , V_38 , V_31 ) ;
F_1 ( V_2 , F_10 ( V_36 ) ,
V_37 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_31 , int V_44 )
{
V_2 -> V_45 [ V_31 ] . V_46 = true ;
V_2 -> V_45 [ V_31 ] . V_44 = V_44 ;
}
static void F_15 ( struct V_1 * V_2 , int V_31 ,
unsigned int V_47 , unsigned int V_48 )
{
V_2 -> V_45 [ V_31 ] . V_48 = V_48 ;
V_2 -> V_45 [ V_31 ] . V_47 = V_47 ;
}
static void F_16 ( struct V_28 * V_29 , unsigned int V_44 )
{
int V_49 = F_17 ( V_50 ) ;
V_29 -> V_34 . V_51 [ V_50 ] = V_44 ;
V_29 -> V_34 . V_51 [ V_49 ] = V_52 ;
}
static void F_18 ( struct V_28 * V_29 ,
unsigned int V_23 , bool V_53 )
{
int V_49 = F_17 ( V_54 ) ;
if ( V_53 )
V_29 -> V_34 . V_51 [ V_49 ] &= ~ ( 1 << V_23 ) ;
else
V_29 -> V_34 . V_51 [ V_49 ] |= 1 << V_23 ;
}
static void F_19 ( struct V_28 * V_29 ,
unsigned int V_55 )
{
unsigned char V_56 = V_57 ;
int V_49 = F_17 ( V_54 ) ;
V_29 -> V_34 . V_51 [ V_54 ] = 0 ;
V_29 -> V_34 . V_51 [ V_49 ] &= ~ V_56 ;
V_29 -> V_34 . V_51 [ V_49 ] |= ~ V_55 & V_57 ;
}
static unsigned int F_20 ( struct V_28 * V_29 )
{
int V_49 = F_17 ( V_54 ) ;
return ~ ( V_29 -> V_34 . V_51 [ V_49 ] ) & V_57 ;
}
static void F_21 ( struct V_28 * V_29 ,
unsigned int V_58 , unsigned char V_51 ,
unsigned char V_59 )
{
V_29 -> V_34 . V_51 [ F_22 ( V_58 ) ] = V_51 ;
V_29 -> V_34 . V_51 [ F_23 ( V_58 ) ] = V_59 ;
}
static void F_24 ( struct V_28 * V_29 ,
unsigned int V_58 , unsigned char * V_51 ,
unsigned char * V_59 )
{
* V_51 = V_29 -> V_34 . V_51 [ F_22 ( V_58 ) ] ;
* V_59 = V_29 -> V_34 . V_51 [ F_23 ( V_58 ) ] ;
}
static bool F_25 ( struct V_28 * V_29 , int V_58 ,
T_2 V_4 )
{
int V_60 = F_22 ( V_58 ) ;
T_2 V_61 ;
V_61 = ( 8 << V_29 -> V_34 . V_51 [ V_60 + 1 ] ) | V_29 -> V_34 . V_51 [ V_60 ] ;
if ( V_61 != V_4 )
return false ;
return true ;
}
static void F_26 ( struct V_28 * V_29 ,
unsigned int V_62 , unsigned int V_59 )
{
int V_30 , V_63 = V_64 ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ ) {
if ( ! ( V_59 & F_27 ( V_30 ) ) )
continue;
if ( V_62 & F_27 ( V_30 ) )
V_29 -> V_34 . V_51 [ V_63 ] |= 1 << V_30 ;
else
V_29 -> V_34 . V_51 [ V_63 ] &= ~ ( 1 << V_30 ) ;
}
V_29 -> V_34 . V_51 [ F_17 ( V_63 ) ] |= V_59 ;
}
static int F_28 ( struct V_28 * V_29 )
{
return V_29 -> V_34 . V_51 [ V_64 ] ;
}
static void F_29 ( struct V_28 * V_29 , int V_3 ,
unsigned short V_66 )
{
F_21 ( V_29 , V_3 + 0 , V_66 >> 8 , 0xff ) ;
F_21 ( V_29 , V_3 + 1 , V_66 & 0xff , 0xff ) ;
}
static void F_30 ( struct V_28 * V_29 , int V_67 ,
int V_68 )
{
V_29 -> V_42 . V_51 [ F_31 ( V_67 ) ] |= ( V_68 << ( V_67 % 8 ) ) ;
}
static void F_32 ( struct V_28 * V_29 , int V_67 ,
int V_68 )
{
V_29 -> V_42 . V_51 [ F_31 ( V_67 ) ] &= ~ ( V_68 << ( V_67 % 8 ) ) ;
}
static void F_33 ( struct V_28 * V_29 ,
unsigned int V_62 , unsigned int V_69 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_70 ; V_30 ++ ) {
int V_71 = V_72 ;
if ( ! ( V_69 & F_27 ( V_30 ) ) )
continue;
if ( V_62 & F_27 ( V_30 ) )
F_30 ( V_29 , V_71 + V_30 , 1 ) ;
else
F_32 ( V_29 , V_71 + V_30 , 1 ) ;
F_30 ( V_29 , V_73 + V_30 , 1 ) ;
}
}
static int F_34 ( struct V_28 * V_29 )
{
return V_29 -> V_42 . V_35 [ V_74 ] ;
}
static void F_35 ( struct V_28 * V_29 ,
unsigned int V_62 , unsigned int V_69 )
{
unsigned int V_30 ;
int V_75 = V_76 ;
for ( V_30 = 0 ; V_30 < V_77 ; V_30 ++ ) {
if ( ! ( V_69 & F_27 ( V_30 ) ) )
continue;
if ( V_62 & F_27 ( V_30 ) )
F_30 ( V_29 , V_75 + V_30 , 1 ) ;
else
F_32 ( V_29 , V_75 + V_30 , 1 ) ;
F_30 ( V_29 , V_78 + V_30 , 1 ) ;
}
}
static int F_36 ( struct V_28 * V_29 )
{
T_3 V_62 ;
int V_75 = F_31 ( V_76 ) ;
int V_79 = V_75 + 1 ;
int V_80 = V_76 % 8 ;
V_62 = ( V_29 -> V_42 . V_51 [ V_75 ] >> V_80 ) |
( V_29 -> V_42 . V_51 [ V_79 ] << ( 8 - V_80 ) ) ;
return V_62 ;
}
static void F_37 ( struct V_28 * V_29 ,
unsigned int V_44 )
{
int V_81 = V_82 ;
F_32 ( V_29 , V_81 ,
V_83 ) ;
F_30 ( V_29 , V_81 , V_44 ) ;
}
static void F_38 ( struct V_28 * V_29 , int V_84 ,
unsigned int V_85 )
{
if ( V_84 < 0 ) {
F_30 ( V_29 , V_86 , 1 ) ;
V_84 = 0 - V_84 ;
} else {
F_32 ( V_29 , V_86 , 1 ) ;
}
V_29 -> V_42 . V_51 [ F_31 ( V_87 ) ] =
( unsigned char ) V_84 ;
F_32 ( V_29 , V_88 ,
V_89 ) ;
F_30 ( V_29 , V_88 , V_85 ) ;
F_32 ( V_29 , V_90 , 1 ) ;
}
static void F_39 ( struct V_28 * V_29 ,
unsigned int type , int V_3 ,
unsigned int V_85 )
{
if ( V_3 < 0 ) {
F_30 ( V_29 , V_91 , 1 ) ;
V_3 = 0 - V_3 ;
} else {
F_32 ( V_29 , V_91 , 1 ) ;
}
F_32 ( V_29 , V_92 ,
V_93 ) ;
F_30 ( V_29 , V_92 , V_3 ) ;
V_29 -> V_42 . V_51 [ F_31 ( V_92 +
V_94 ) ] &=
~ ( V_93 >> ( 8 - ( V_92 % 8 ) ) ) ;
V_29 -> V_42 . V_51 [ F_31 ( V_92 +
V_94 ) ] |=
( V_3 >> ( 8 - ( V_92 % 8 ) ) ) ;
F_32 ( V_29 , V_95 ,
V_96 ) ;
F_30 ( V_29 , V_95 , type ) ;
F_32 ( V_29 , V_97 ,
V_98 ) ;
F_30 ( V_29 , V_97 , V_85 ) ;
V_29 -> V_42 . V_51 [ F_31 ( V_97 +
V_99 ) ] &=
~ ( V_98 >>
( 8 - ( V_97 % 8 ) ) ) ;
V_29 -> V_42 . V_51 [ F_31 ( V_97 +
V_99 ) ] |=
( V_85 >> ( 8 - ( V_97 % 8 ) ) ) ;
F_32 ( V_29 , V_90 , 1 ) ;
}
static struct V_28 * F_40 ( struct V_1 * V_2 , int V_100 )
{
struct V_28 * V_29 ;
int V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return NULL ;
F_16 ( V_29 , V_103 ) ;
for ( V_101 = V_32 - 1 ; V_101 >= 0 ; V_101 -- ) {
T_3 V_62 ;
if ( ! V_2 -> V_45 [ V_101 ] . V_46 ||
V_2 -> V_45 [ V_101 ] . V_44 != V_103 )
continue;
V_29 -> V_31 = V_101 ;
F_12 ( V_2 , V_29 ) ;
V_62 = F_36 ( V_29 ) ;
if ( ( V_62 & V_104 ) == V_100 )
return V_29 ;
}
F_42 ( V_29 ) ;
return NULL ;
}
static int F_43 ( struct V_1 * V_2 , unsigned char V_105 ,
unsigned char V_106 )
{
int V_101 ;
if ( V_105 > V_106 )
F_44 ( V_105 , V_106 ) ;
if ( V_106 >= V_32 )
V_106 = V_32 - 1 ;
for ( V_101 = V_105 ; V_101 <= V_106 ; V_101 ++ ) {
if ( ! V_2 -> V_45 [ V_101 ] . V_46 )
return V_101 ;
}
return - V_33 ;
}
static void F_45 ( struct V_1 * V_2 , int V_23 , bool V_53 )
{
struct V_28 V_29 ;
if ( V_2 -> V_45 [ V_107 ] . V_46 ) {
V_29 . V_31 = V_107 ;
F_12 ( V_2 , & V_29 ) ;
} else {
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_108 ) ;
V_29 . V_31 = V_107 ;
F_33 ( & V_29 , V_109 ,
V_109 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_37 ( & V_29 , V_103 ) ;
F_14 ( V_2 , V_29 . V_31 , V_108 ) ;
F_19 ( & V_29 , 0 ) ;
}
F_18 ( & V_29 , V_23 , V_53 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static void F_46 ( struct V_1 * V_2 , int V_23 , bool V_53 )
{
struct V_28 V_29 ;
if ( V_2 -> V_45 [ V_111 ] . V_46 ) {
V_29 . V_31 = V_111 ;
F_12 ( V_2 , & V_29 ) ;
} else {
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_108 ) ;
V_29 . V_31 = V_111 ;
F_37 ( & V_29 , V_112 ) ;
F_33 ( & V_29 , V_113 ,
V_114 ) ;
F_38 ( & V_29 , 2 * V_115 ,
V_116 ) ;
F_19 ( & V_29 , 0 ) ;
F_14 ( V_2 , V_29 . V_31 , V_108 ) ;
}
F_18 ( & V_29 , V_23 , V_53 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_23 , int V_31 ,
bool V_53 )
{
struct V_28 V_29 ;
unsigned char V_117 ;
V_117 = ( V_31 == V_118 ) ? 0x01 : 0x33 ;
if ( V_2 -> V_45 [ V_31 ] . V_46 ) {
V_29 . V_31 = V_31 ;
F_12 ( V_2 , & V_29 ) ;
} else {
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_108 ) ;
V_29 . V_31 = V_31 ;
F_37 ( & V_29 , V_112 ) ;
F_33 ( & V_29 , V_119 ,
V_114 ) ;
F_21 ( & V_29 , 0 , V_117 , 0xff ) ;
F_38 ( & V_29 , 2 * V_115 ,
V_116 ) ;
F_19 ( & V_29 , 0 ) ;
F_14 ( V_2 , V_29 . V_31 , V_108 ) ;
}
F_18 ( & V_29 , V_23 , V_53 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_23 , bool V_53 ,
bool V_120 , bool V_121 )
{
struct V_28 V_29 ;
int V_101 , V_84 ;
if ( V_121 ) {
V_101 = V_120 ? V_122 : V_123 ;
V_84 = 8 ;
} else {
V_101 = V_120 ? V_124 : V_125 ;
V_84 = 4 ;
}
if ( V_2 -> V_45 [ V_101 ] . V_46 ) {
V_29 . V_31 = V_101 ;
F_12 ( V_2 , & V_29 ) ;
} else {
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_112 ) ;
V_29 . V_31 = V_101 ;
F_38 ( & V_29 , V_84 ,
V_116 ) ;
F_14 ( V_2 , V_29 . V_31 , V_112 ) ;
if ( V_120 ) {
F_21 ( & V_29 , 0 ,
V_126 ,
V_126 ) ;
F_35 ( & V_29 , 0 ,
V_127 ) ;
F_37 ( & V_29 , V_128 ) ;
} else {
F_33 ( & V_29 , V_129 ,
V_130 ) ;
F_37 ( & V_29 , V_131 ) ;
}
F_19 ( & V_29 , 0 ) ;
}
F_18 ( & V_29 , V_23 , V_53 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_23 ,
bool V_53 , bool V_120 , bool V_121 )
{
struct V_28 V_29 ;
int V_101 , V_84 , V_56 ;
if ( V_121 ) {
V_101 = V_120 ? V_132 :
V_133 ;
V_56 = 0 ;
V_84 = 8 ;
} else {
V_101 = V_120 ? V_134 :
V_135 ;
V_56 = V_57 ;
V_84 = 4 ;
}
if ( V_2 -> V_45 [ V_101 ] . V_46 ) {
V_29 . V_31 = V_101 ;
F_12 ( V_2 , & V_29 ) ;
} else {
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_112 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_136 ) ;
F_29 ( & V_29 , 2 , 0 ) ;
F_33 ( & V_29 , V_137 ,
V_137 ) ;
F_38 ( & V_29 , 2 + V_138 + V_84 ,
V_116 ) ;
F_14 ( V_2 , V_29 . V_31 , V_112 ) ;
if ( V_120 ) {
F_21 ( & V_29 ,
V_138 + 2 + 3 ,
V_126 ,
V_126 ) ;
F_35 ( & V_29 , 0 ,
V_127 ) ;
F_37 ( & V_29 , V_128 ) ;
} else {
F_33 ( & V_29 , V_129 ,
V_130 ) ;
F_37 ( & V_29 , V_131 ) ;
}
F_19 ( & V_29 , V_56 ) ;
}
F_18 ( & V_29 , V_23 , V_53 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static struct V_28 * F_50 ( struct V_1 * V_2 ,
unsigned short V_139 , int V_140 )
{
struct V_28 * V_29 ;
int V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return NULL ;
F_16 ( V_29 , V_128 ) ;
for ( V_101 = V_141 ;
V_101 <= V_142 ; V_101 ++ ) {
unsigned int V_143 , V_144 ;
bool V_145 ;
if ( ! V_2 -> V_45 [ V_101 ] . V_46 ||
V_2 -> V_45 [ V_101 ] . V_44 != V_128 )
continue;
V_29 -> V_31 = V_101 ;
F_12 ( V_2 , V_29 ) ;
V_145 = F_25 ( V_29 , 0 , F_51 ( V_139 ) ) ;
if ( ! V_145 )
continue;
V_143 = F_34 ( V_29 ) ;
V_143 &= V_130 ;
V_144 = F_28 ( V_29 ) ;
V_144 &= ~ V_146 ;
if ( V_140 != V_144 )
continue;
if ( V_143 == V_147 ||
V_143 == V_148 )
return V_29 ;
}
F_42 ( V_29 ) ;
return NULL ;
}
static int F_52 ( struct V_1 * V_2 , unsigned short V_139 , int V_140 ,
unsigned int V_149 )
{
struct V_28 * V_29 ;
int V_150 , V_101 ;
int V_151 = 0 ;
V_29 = F_50 ( V_2 , V_139 , V_140 ) ;
if ( ! V_29 ) {
V_101 = F_43 ( V_2 , V_142 ,
V_141 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return - V_152 ;
for ( V_150 = V_142 ;
V_150 >= V_141 ; V_150 -- ) {
unsigned int V_143 ;
if ( ! V_2 -> V_45 [ V_150 ] . V_46 ||
V_2 -> V_45 [ V_150 ] . V_44 != V_128 )
continue;
V_29 -> V_31 = V_150 ;
F_12 ( V_2 , V_29 ) ;
V_143 = F_34 ( V_29 ) ;
if ( ( V_143 & V_130 ) ==
V_153 )
break;
}
if ( V_101 <= V_150 ) {
V_151 = - V_33 ;
goto error;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( V_29 , V_128 ) ;
V_29 -> V_31 = V_101 ;
F_29 ( V_29 , 0 , V_139 ) ;
F_37 ( V_29 , V_131 ) ;
F_38 ( V_29 , V_154 ,
V_116 ) ;
F_35 ( V_29 , 0 , V_127 ) ;
if ( V_140 == V_155 ) {
F_33 ( V_29 , V_147 ,
V_130 ) ;
} else {
V_140 |= V_146 ;
F_33 ( V_29 , V_148 ,
V_130 ) ;
}
F_26 ( V_29 , V_140 , V_127 ) ;
F_14 ( V_2 , V_29 -> V_31 , V_128 ) ;
}
F_19 ( V_29 , V_149 ) ;
F_9 ( V_2 , V_29 ) ;
error:
F_42 ( V_29 ) ;
return V_151 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_30 ;
for ( V_30 = 1 ; V_30 < V_156 ; V_30 ++ ) {
if ( ! V_2 -> V_157 [ V_30 ] )
return V_30 ;
}
return - V_33 ;
}
static struct V_28 * F_54 ( struct V_1 * V_2 ,
unsigned short V_158 ,
unsigned short V_159 )
{
struct V_28 * V_29 ;
int V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return NULL ;
F_16 ( V_29 , V_128 ) ;
for ( V_101 = V_141 ;
V_101 <= V_142 ; V_101 ++ ) {
unsigned int V_48 ;
bool V_145 ;
if ( ! V_2 -> V_45 [ V_101 ] . V_46 ||
V_2 -> V_45 [ V_101 ] . V_44 != V_128 )
continue;
V_29 -> V_31 = V_101 ;
F_12 ( V_2 , V_29 ) ;
V_145 = F_25 ( V_29 , 0 , F_51 ( V_158 ) )
&& F_25 ( V_29 , 4 , F_51 ( V_159 ) ) ;
if ( ! V_145 )
continue;
V_48 = F_34 ( V_29 ) & V_130 ;
if ( V_48 == V_153 )
return V_29 ;
}
F_42 ( V_29 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , unsigned short V_158 ,
unsigned short V_159 ,
unsigned int V_149 )
{
struct V_28 * V_29 ;
int V_150 , V_101 , V_140 , V_151 = 0 ;
V_29 = F_54 ( V_2 , V_158 , V_159 ) ;
if ( ! V_29 ) {
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return - V_152 ;
V_140 = F_53 ( V_2 ) ;
if ( V_140 < 0 ) {
V_151 = V_140 ;
goto error;
}
for ( V_150 = V_141 ;
V_150 <= V_142 ; V_150 ++ ) {
unsigned int V_143 ;
if ( ! V_2 -> V_45 [ V_150 ] . V_46 ||
V_2 -> V_45 [ V_150 ] . V_44 != V_128 )
continue;
V_29 -> V_31 = V_150 ;
F_12 ( V_2 , V_29 ) ;
V_143 = F_34 ( V_29 ) ;
V_143 &= V_130 ;
if ( V_143 == V_147 ||
V_143 == V_148 )
break;
}
if ( V_101 >= V_150 ) {
V_151 = - V_160 ;
goto error;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( V_29 , V_128 ) ;
V_29 -> V_31 = V_101 ;
V_2 -> V_157 [ V_140 ] = true ;
F_29 ( V_29 , 0 , V_158 ) ;
F_29 ( V_29 , 4 , V_159 ) ;
F_37 ( V_29 , V_128 ) ;
F_38 ( V_29 , 2 * V_154 ,
V_116 ) ;
F_33 ( V_29 , V_153 ,
V_130 ) ;
F_35 ( V_29 , V_140 | V_146 ,
V_127 ) ;
F_14 ( V_2 , V_29 -> V_31 , V_128 ) ;
}
F_19 ( V_29 , V_149 ) ;
F_9 ( V_2 , V_29 ) ;
error:
F_42 ( V_29 ) ;
return V_151 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned short V_161 ,
unsigned int V_47 , unsigned int V_48 )
{
struct V_28 V_29 ;
int V_101 ;
if ( ( V_161 != V_162 ) && ( V_161 != V_163 ) &&
( V_161 != V_164 ) )
return - V_33 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_165 ) ;
V_29 . V_31 = V_101 ;
F_37 ( & V_29 , V_165 ) ;
F_38 ( & V_29 , 12 , V_116 ) ;
F_39 ( & V_29 , V_166 ,
sizeof( struct V_167 ) - 4 ,
V_168 ) ;
F_35 ( & V_29 , V_169 ,
V_169 ) ;
F_33 ( & V_29 , V_47 | V_170 ,
V_48 | V_170 ) ;
F_21 ( & V_29 , 5 , V_161 , V_171 ) ;
F_26 ( & V_29 , 0 , V_169 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 . V_31 = V_101 ;
V_29 . V_42 . V_35 [ V_74 ] = 0x0 ;
V_29 . V_42 . V_35 [ V_172 ] = 0x0 ;
F_33 ( & V_29 , V_47 , V_48 ) ;
F_21 ( & V_29 , 2 , 0x00 , V_173 ) ;
F_21 ( & V_29 , 3 , 0x00 , V_171 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned short V_174 )
{
struct V_28 V_29 ;
int V_69 , V_101 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_165 ) ;
V_29 . V_31 = V_101 ;
switch ( V_174 ) {
case V_175 :
F_21 ( & V_29 , 0 , V_176 ,
V_177 ) ;
F_33 ( & V_29 , V_178 ,
V_179 ) ;
break;
case V_180 :
V_69 = V_181 ;
F_21 ( & V_29 , 0 , V_69 , V_69 ) ;
F_21 ( & V_29 , 1 , V_69 , V_69 ) ;
F_21 ( & V_29 , 2 , V_69 , V_69 ) ;
F_21 ( & V_29 , 3 , V_69 , V_69 ) ;
F_33 ( & V_29 , V_182 ,
V_179 ) ;
break;
default:
return - V_33 ;
}
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_26 ( & V_29 , V_169 ,
V_169 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned short V_161 ,
unsigned int V_47 , unsigned int V_48 )
{
struct V_28 V_29 ;
int V_101 ;
if ( ( V_161 != V_162 ) && ( V_161 != V_163 ) &&
( V_161 != V_183 ) && ( V_161 != V_184 ) )
return - V_33 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_185 ) ;
V_29 . V_31 = V_101 ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_47 , V_48 ) ;
F_39 ( & V_29 , V_166 ,
sizeof( struct V_186 ) - 6 ,
V_168 ) ;
F_21 ( & V_29 , 0 , V_161 , V_171 ) ;
F_26 ( & V_29 , V_187 ,
V_187 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_185 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned short V_174 )
{
struct V_28 V_29 ;
int V_101 ;
if ( V_174 != V_175 )
return - V_33 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_185 ) ;
V_29 . V_31 = V_101 ;
F_37 ( & V_29 , V_185 ) ;
F_33 ( & V_29 , V_178 ,
V_179 ) ;
F_35 ( & V_29 , V_187 ,
V_187 ) ;
F_38 ( & V_29 , - 18 , V_116 ) ;
F_21 ( & V_29 , 0 , V_188 ,
V_189 ) ;
F_26 ( & V_29 , 0 , V_187 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_185 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_23 , int V_190 ,
int V_191 , int V_3 )
{
T_1 V_68 ;
V_68 = F_3 ( V_2 , V_192 ) ;
V_68 &= ~ F_61 ( V_23 ) ;
V_68 |= F_62 ( V_23 , V_190 ) ;
F_1 ( V_2 , V_192 , V_68 ) ;
V_68 = F_3 ( V_2 , F_63 ( V_23 ) ) ;
V_68 &= ~ F_64 ( V_23 ) ;
V_68 |= F_65 ( V_23 , V_191 ) ;
F_1 ( V_2 , F_63 ( V_23 ) , V_68 ) ;
V_68 = F_3 ( V_2 , F_66 ( V_23 ) ) ;
V_68 &= ~ F_67 ( V_23 ) ;
V_68 |= F_68 ( V_23 , V_3 ) ;
F_1 ( V_2 , F_66 ( V_23 ) , V_68 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_193 ; V_23 ++ ) {
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_103 ) ;
V_29 . V_31 = V_194 - V_23 ;
F_19 ( & V_29 , 0 ) ;
F_35 ( & V_29 , V_23 , V_104 ) ;
F_30 ( & V_29 , V_195 , 1 ) ;
F_14 ( V_2 , V_29 . V_31 , V_103 ) ;
F_9 ( V_2 , & V_29 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_31 = V_196 ;
F_16 ( & V_29 , V_197 ) ;
F_38 ( & V_29 , V_198 ,
V_116 ) ;
F_37 ( & V_29 , V_108 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_197 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_31 = V_199 ;
F_16 ( & V_29 , V_108 ) ;
F_33 ( & V_29 , V_109 ,
V_109 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_37 ( & V_29 , V_103 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_108 ) ;
F_9 ( V_2 , & V_29 ) ;
F_45 ( V_2 , 0 , false ) ;
F_46 ( V_2 , 0 , false ) ;
F_47 ( V_2 , V_118 , 0 , false ) ;
F_47 ( V_2 , V_200 , 0 , false ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
F_48 ( V_2 , 0 , false , V_201 ,
V_202 ) ;
F_48 ( V_2 , 0 , false , V_203 , V_202 ) ;
F_48 ( V_2 , 0 , false , V_201 ,
V_204 ) ;
F_48 ( V_2 , 0 , false , V_203 , V_204 ) ;
F_49 ( V_2 , 0 , false ,
V_201 , V_202 ) ;
F_49 ( V_2 , 0 , false ,
V_203 , V_202 ) ;
F_49 ( V_2 , 0 , true ,
V_201 , V_204 ) ;
F_49 ( V_2 , 0 , true ,
V_203 , V_204 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_112 ) ;
V_29 . V_31 = V_205 ;
F_37 ( & V_29 , V_128 ) ;
F_38 ( & V_29 , 0 , V_116 ) ;
F_14 ( V_2 , V_29 . V_31 , V_108 ) ;
F_35 ( & V_29 , 0 , V_127 ) ;
F_19 ( & V_29 , V_57 ) ;
F_9 ( V_2 , & V_29 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
int V_101 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_131 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_206 ) ;
F_38 ( & V_29 , V_207 ,
V_116 ) ;
F_37 ( & V_29 , V_208 ) ;
F_33 ( & V_29 , V_209 ,
V_209 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = false ;
F_15 ( V_2 , V_29 . V_31 , V_209 ,
V_209 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_131 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_213 ) ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_214 ,
V_215 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = true ;
F_15 ( V_2 , V_29 . V_31 , V_214 ,
V_215 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_131 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_217 ) ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_218 |
V_219 ,
V_220 |
V_221 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = true ;
F_15 ( V_2 , V_29 . V_31 , V_218 |
V_219 ,
V_220 |
V_221 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_131 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_222 ) ;
F_21 ( & V_29 , V_138 ,
V_223 | V_224 ,
V_225 |
V_226 ) ;
F_37 ( & V_29 , V_165 ) ;
F_33 ( & V_29 , V_227 ,
V_215 ) ;
F_38 ( & V_29 , V_138 + 4 ,
V_116 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = false ;
F_15 ( V_2 , V_29 . V_31 , V_227 ,
V_215 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 . V_31 = V_101 ;
V_29 . V_34 . V_51 [ F_22 ( V_138 ) ] = 0x0 ;
V_29 . V_34 . V_51 [ F_23 ( V_138 ) ] = 0x0 ;
F_21 ( & V_29 , V_138 ,
V_223 ,
V_225 ) ;
V_29 . V_42 . V_35 [ V_74 ] = 0x0 ;
V_29 . V_42 . V_35 [ V_172 ] = 0x0 ;
F_33 ( & V_29 , V_228 ,
V_215 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = false ;
F_15 ( V_2 , V_29 . V_31 , V_228 ,
V_215 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_131 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_229 ) ;
F_38 ( & V_29 , V_138 + 8 +
V_230 ,
V_116 ) ;
F_37 ( & V_29 , V_185 ) ;
F_33 ( & V_29 , V_231 ,
V_215 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = false ;
F_15 ( V_2 , V_29 . V_31 , V_231 ,
V_215 ) ;
F_9 ( V_2 , & V_29 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_131 ) ;
V_29 . V_31 = V_232 ;
F_19 ( & V_29 , V_57 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_37 ( & V_29 , V_103 ) ;
F_33 ( & V_29 , V_233 ,
V_215 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_131 ) ;
V_2 -> V_45 [ V_29 . V_31 ] . V_210 = V_211 ;
V_2 -> V_45 [ V_29 . V_31 ] . V_212 = true ;
F_15 ( V_2 , V_29 . V_31 , V_233 ,
V_215 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_74 ( struct V_234 * V_235 , struct V_1 * V_2 )
{
struct V_28 V_29 ;
int V_236 ;
V_2 -> V_157 = F_75 ( & V_235 -> V_237 , sizeof( bool ) ,
V_156 ,
V_102 ) ;
if ( ! V_2 -> V_157 )
return - V_152 ;
V_236 = F_55 ( V_2 , V_238 , V_239 ,
V_57 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_55 ( V_2 , V_238 , V_238 ,
V_57 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_52 ( V_2 , V_239 , V_155 ,
V_57 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_52 ( V_2 , V_238 , V_155 ,
V_57 ) ;
if ( V_236 )
return V_236 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_128 ) ;
V_29 . V_31 = V_240 ;
F_37 ( & V_29 , V_131 ) ;
F_35 ( & V_29 , 0 , V_127 ) ;
F_33 ( & V_29 , V_153 ,
V_130 ) ;
F_26 ( & V_29 , V_146 ,
V_146 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_128 ) ;
F_9 ( V_2 , & V_29 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_128 ) ;
V_29 . V_31 = V_241 ;
F_37 ( & V_29 , V_131 ) ;
F_33 ( & V_29 , V_129 ,
V_130 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_128 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
int V_101 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_208 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_242 ) ;
F_37 ( & V_29 , V_165 ) ;
F_33 ( & V_29 , V_228 ,
V_215 ) ;
F_38 ( & V_29 , V_138 + 4 ,
V_116 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_208 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 . V_31 = V_101 ;
F_21 ( & V_29 , V_138 ,
V_223 | V_224 ,
V_225 |
V_226 ) ;
V_29 . V_42 . V_35 [ V_74 ] = 0x0 ;
V_29 . V_42 . V_35 [ V_172 ] = 0x0 ;
F_33 ( & V_29 , V_227 ,
V_215 ) ;
F_14 ( V_2 , V_29 . V_31 , V_208 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_208 ) ;
V_29 . V_31 = V_101 ;
F_29 ( & V_29 , 0 , V_243 ) ;
F_37 ( & V_29 , V_185 ) ;
F_33 ( & V_29 , V_231 ,
V_215 ) ;
F_38 ( & V_29 , V_138 + 4 ,
V_116 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_208 ) ;
F_9 ( V_2 , & V_29 ) ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_208 ) ;
V_29 . V_31 = V_101 ;
F_33 ( & V_29 , V_233 ,
V_215 ) ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_39 ( & V_29 , V_216 ,
V_138 ,
V_168 ) ;
F_14 ( V_2 , V_29 . V_31 , V_208 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
int V_236 ;
V_236 = F_56 ( V_2 , V_162 , V_244 ,
V_245 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_56 ( V_2 , V_163 , V_246 ,
V_245 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_56 ( V_2 , V_164 ,
V_218 |
V_219 ,
V_220 |
V_221 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_57 ( V_2 , V_180 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_57 ( V_2 , V_175 ) ;
if ( V_236 )
return V_236 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_165 ) ;
V_29 . V_31 = V_247 ;
F_37 ( & V_29 , V_165 ) ;
F_38 ( & V_29 , 12 , V_116 ) ;
F_39 ( & V_29 , V_166 ,
sizeof( struct V_167 ) - 4 ,
V_168 ) ;
F_35 ( & V_29 , V_169 ,
V_169 ) ;
F_33 ( & V_29 , V_248 ,
V_245 ) ;
F_26 ( & V_29 , 0 , V_169 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_165 ) ;
V_29 . V_31 = V_249 ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_250 ,
V_179 ) ;
F_26 ( & V_29 , V_169 ,
V_169 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
int V_101 , V_236 ;
V_236 = F_58 ( V_2 , V_162 ,
V_244 ,
V_245 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_58 ( V_2 , V_163 ,
V_246 ,
V_245 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_58 ( V_2 , V_183 ,
V_218 |
V_219 ,
V_220 |
V_221 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_58 ( V_2 , V_184 ,
V_251 ,
V_252 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_59 ( V_2 , V_175 ) ;
if ( V_236 )
return V_236 ;
V_101 = F_43 ( V_2 , V_141 ,
V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_185 ) ;
V_29 . V_31 = V_101 ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_233 |
V_109 ,
V_215 |
V_109 ) ;
F_21 ( & V_29 , 1 , 0x00 , V_253 ) ;
F_26 ( & V_29 , V_187 ,
V_187 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_185 ) ;
V_29 . V_31 = V_254 ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_248 ,
V_245 ) ;
F_39 ( & V_29 , V_166 ,
sizeof( struct V_186 ) - 4 ,
V_168 ) ;
F_26 ( & V_29 , V_187 ,
V_187 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_185 ) ;
V_29 . V_31 = V_255 ;
F_37 ( & V_29 , V_103 ) ;
F_30 ( & V_29 , V_110 , 1 ) ;
F_33 ( & V_29 , V_248 ,
V_245 ) ;
F_26 ( & V_29 , V_256 ,
V_256 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_165 ) ;
F_9 ( V_2 , & V_29 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
F_16 ( & V_29 , V_185 ) ;
V_29 . V_31 = V_257 ;
F_37 ( & V_29 , V_185 ) ;
F_33 ( & V_29 , V_250 ,
V_179 ) ;
F_35 ( & V_29 , V_187 ,
V_187 ) ;
F_38 ( & V_29 , - 18 , V_116 ) ;
F_26 ( & V_29 , 0 , V_187 ) ;
F_19 ( & V_29 , V_57 ) ;
F_14 ( V_2 , V_29 . V_31 , V_185 ) ;
F_9 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_79 ( struct V_234 * V_235 ,
struct V_1 * V_2 )
{
int V_236 , V_31 , V_30 ;
F_1 ( V_2 , V_258 , V_259 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
F_1 ( V_2 , V_38 , V_31 ) ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ )
F_1 ( V_2 , F_10 ( V_30 ) , 0 ) ;
F_1 ( V_2 , V_40 , V_31 ) ;
for ( V_30 = 0 ; V_30 < V_41 ; V_30 ++ )
F_1 ( V_2 , F_11 ( V_30 ) , 0 ) ;
}
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
F_13 ( V_2 , V_31 ) ;
V_2 -> V_45 = F_75 ( & V_235 -> V_237 , V_32 ,
sizeof( struct V_260 ) ,
V_102 ) ;
if ( ! V_2 -> V_45 )
return - V_152 ;
for ( V_31 = 0 ; V_31 < V_193 ; V_31 ++ )
F_60 ( V_2 , V_31 , V_197 ,
V_261 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
V_236 = F_73 ( V_2 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_74 ( V_235 , V_2 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_76 ( V_2 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_78 ( V_2 ) ;
if ( V_236 )
return V_236 ;
V_236 = F_77 ( V_2 ) ;
if ( V_236 )
return V_236 ;
return 0 ;
}
static bool F_80 ( struct V_28 * V_29 ,
const T_3 * V_262 , unsigned char * V_69 )
{
unsigned char V_263 , V_264 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_115 ; V_31 ++ ) {
F_24 ( V_29 , V_31 , & V_263 , & V_264 ) ;
if ( V_264 != V_69 [ V_31 ] )
return false ;
if ( ( V_264 & V_263 ) != ( V_262 [ V_31 ] & V_69 [ V_31 ] ) )
return false ;
}
return true ;
}
static struct V_28 *
F_81 ( struct V_1 * V_2 , int V_265 , const T_3 * V_262 ,
unsigned char * V_69 , int V_266 )
{
struct V_28 * V_29 ;
int V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return NULL ;
F_16 ( V_29 , V_108 ) ;
for ( V_101 = V_141 ;
V_101 <= V_142 ; V_101 ++ ) {
unsigned int V_267 ;
if ( ! V_2 -> V_45 [ V_101 ] . V_46 ||
( V_2 -> V_45 [ V_101 ] . V_44 != V_108 ) ||
( V_2 -> V_45 [ V_101 ] . V_210 != V_266 ) )
continue;
V_29 -> V_31 = V_101 ;
F_12 ( V_2 , V_29 ) ;
V_267 = F_20 ( V_29 ) ;
if ( F_80 ( V_29 , V_262 , V_69 ) &&
V_267 == V_265 )
return V_29 ;
}
F_42 ( V_29 ) ;
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_23 ,
const T_3 * V_262 , bool V_53 )
{
struct V_28 * V_29 ;
unsigned int V_265 , V_268 , V_47 ;
unsigned char V_69 [ V_115 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_101 ;
V_29 = F_81 ( V_2 , ( 1 << V_23 ) , V_262 , V_69 ,
V_269 ) ;
if ( ! V_29 ) {
if ( ! V_53 )
return 0 ;
for ( V_101 = V_141 ;
V_101 <= V_142 ; V_101 ++ )
if ( V_2 -> V_45 [ V_101 ] . V_46 &&
( V_2 -> V_45 [ V_101 ] . V_44 == V_108 ) &&
( V_2 -> V_45 [ V_101 ] . V_210 ==
V_270 ) )
break;
V_101 = F_43 ( V_2 , V_141 ,
V_101 - 1 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return - V_152 ;
F_16 ( V_29 , V_108 ) ;
V_29 -> V_31 = V_101 ;
F_19 ( V_29 , 0 ) ;
}
F_18 ( V_29 , V_23 , V_53 ) ;
V_265 = F_20 ( V_29 ) ;
if ( V_265 == 0 ) {
if ( V_53 ) {
F_42 ( V_29 ) ;
return - V_33 ;
}
F_13 ( V_2 , V_29 -> V_31 ) ;
V_2 -> V_45 [ V_29 -> V_31 ] . V_46 = false ;
F_42 ( V_29 ) ;
return 0 ;
}
F_37 ( V_29 , V_112 ) ;
V_268 = V_115 ;
while ( V_268 -- )
F_21 ( V_29 , V_268 , V_262 [ V_268 ] , 0xff ) ;
if ( F_83 ( V_262 ) )
V_47 = V_271 ;
else if ( F_84 ( V_262 ) )
V_47 = V_119 ;
else
V_47 = V_113 | V_272 ;
F_33 ( V_29 , V_47 , V_114 |
V_272 ) ;
F_15 ( V_2 , V_29 -> V_31 , V_47 , V_114 |
V_272 ) ;
F_38 ( V_29 , 2 * V_115 ,
V_116 ) ;
V_2 -> V_45 [ V_29 -> V_31 ] . V_210 = V_269 ;
F_14 ( V_2 , V_29 -> V_31 , V_108 ) ;
F_9 ( V_2 , V_29 ) ;
F_42 ( V_29 ) ;
return 0 ;
}
static int F_85 ( struct V_273 * V_237 , const T_3 * V_262 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
int V_236 ;
V_236 = F_82 ( V_23 -> V_2 , V_23 -> V_25 , V_237 -> V_274 ,
false ) ;
if ( V_236 )
return V_236 ;
V_236 = F_82 ( V_23 -> V_2 , V_23 -> V_25 , V_262 , true ) ;
if ( V_236 )
return V_236 ;
F_87 ( V_237 -> V_274 , V_262 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , int V_23 )
{
struct V_28 V_29 ;
int V_31 , V_101 ;
for ( V_101 = V_141 ;
V_101 <= V_142 ; V_101 ++ ) {
unsigned char V_262 [ V_115 ] , V_275 [ V_115 ] ;
if ( ! V_2 -> V_45 [ V_101 ] . V_46 ||
( V_2 -> V_45 [ V_101 ] . V_44 != V_108 ) ||
( V_2 -> V_45 [ V_101 ] . V_210 != V_269 ) )
continue;
V_29 . V_31 = V_101 ;
F_12 ( V_2 , & V_29 ) ;
for ( V_31 = 0 ; V_31 < V_115 ; V_31 ++ )
F_24 ( & V_29 , V_31 , & V_262 [ V_31 ] ,
& V_275 [ V_31 ] ) ;
if ( F_84 ( V_262 ) && ! F_83 ( V_262 ) )
F_82 ( V_2 , V_23 , V_262 , false ) ;
}
}
static int F_89 ( struct V_1 * V_2 , int V_23 , int type )
{
switch ( type ) {
case V_276 :
F_48 ( V_2 , V_23 , true ,
V_203 , V_202 ) ;
F_48 ( V_2 , V_23 , true ,
V_201 , V_202 ) ;
F_48 ( V_2 , V_23 , false ,
V_203 , V_204 ) ;
F_48 ( V_2 , V_23 , false ,
V_201 , V_204 ) ;
break;
case V_277 :
F_48 ( V_2 , V_23 , true ,
V_203 , V_204 ) ;
F_48 ( V_2 , V_23 , true ,
V_201 , V_204 ) ;
F_48 ( V_2 , V_23 , false ,
V_203 , V_202 ) ;
F_48 ( V_2 , V_23 , false ,
V_201 , V_202 ) ;
break;
case V_278 :
case V_279 :
F_48 ( V_2 , V_23 , false ,
V_203 , V_204 ) ;
F_48 ( V_2 , V_23 , false ,
V_201 , V_204 ) ;
F_48 ( V_2 , V_23 , false ,
V_203 , V_202 ) ;
F_48 ( V_2 , V_23 , false ,
V_201 , V_202 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_276 ) )
return - V_33 ;
}
return 0 ;
}
static int F_90 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
int V_101 ;
V_29 = F_40 ( V_23 -> V_2 , V_23 -> V_25 ) ;
if ( ! V_29 ) {
V_101 = F_43 ( V_23 -> V_2 ,
V_142 ,
V_141 ) ;
if ( V_101 < 0 )
return V_101 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_102 ) ;
if ( ! V_29 )
return - V_152 ;
F_16 ( V_29 , V_103 ) ;
V_29 -> V_31 = V_101 ;
F_35 ( V_29 , V_23 -> V_25 , V_104 ) ;
F_30 ( V_29 , V_195 , 1 ) ;
F_14 ( V_23 -> V_2 , V_29 -> V_31 , V_103 ) ;
}
F_19 ( V_29 , ( 1 << V_23 -> V_25 ) ) ;
F_9 ( V_23 -> V_2 , V_29 ) ;
F_42 ( V_29 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
F_1 ( V_2 , V_282 , V_281 -> V_31 ) ;
F_1 ( V_2 , V_283 , V_281 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_284 , V_281 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_285 , V_281 -> V_4 [ 2 ] ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_286 * V_287 )
{
T_1 V_68 ;
V_68 = ( V_287 -> V_288 << V_289 ) | V_287 -> V_290 ;
F_1 ( V_2 , V_291 , V_68 ) ;
F_1 ( V_2 , V_292 , V_287 -> V_4 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_286 V_287 ;
struct V_280 V_281 ;
int V_31 ;
F_1 ( V_2 , V_293 , V_294 ) ;
memset ( & V_281 . V_4 , 0 , sizeof( V_281 . V_4 ) ) ;
for ( V_31 = 0 ; V_31 < V_295 ; V_31 ++ ) {
V_281 . V_31 = V_31 ;
F_91 ( V_2 , & V_281 ) ;
}
V_287 . V_4 = 0 ;
for ( V_31 = 0 ; V_31 < V_296 ; V_31 ++ ) {
V_287 . V_290 = V_31 ;
V_287 . V_288 = 0 ;
F_92 ( V_2 , & V_287 ) ;
V_287 . V_288 = 1 ;
F_92 ( V_2 , & V_287 ) ;
}
}
static void F_94 ( struct V_22 * V_23 )
{
struct V_286 V_287 ;
T_1 V_68 ;
V_68 = F_3 ( V_23 -> V_2 , V_297 ) ;
V_68 &= ~ F_95 ( V_23 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_297 , V_68 ) ;
V_287 . V_290 = V_23 -> V_25 ;
V_287 . V_288 = 0 ;
V_287 . V_4 = 0 ;
V_287 . V_4 &= ~ V_298 ;
V_287 . V_4 |= V_23 -> V_299 ;
V_287 . V_4 &= ~ V_300 ;
F_92 ( V_23 -> V_2 , & V_287 ) ;
}
static void F_96 ( struct V_22 * V_23 )
{
T_1 V_68 ;
F_1 ( V_23 -> V_2 , F_97 ( V_23 -> V_25 ) ,
V_23 -> V_299 & V_301 ) ;
F_1 ( V_23 -> V_2 , F_98 ( V_23 -> V_25 ) ,
( V_23 -> V_299 >> V_302 ) ) ;
V_68 = F_3 ( V_23 -> V_2 , V_303 ) ;
V_68 |= F_99 ( V_23 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_303 , V_68 ) ;
}
static void * F_100 ( const struct V_304 * V_305 )
{
if ( F_101 ( V_305 -> V_306 <= V_307 ) )
return F_102 ( V_305 -> V_306 ) ;
else
return F_103 ( V_305 -> V_306 , V_308 ) ;
}
static void F_104 ( const struct V_304 * V_305 , void * V_4 )
{
if ( F_101 ( V_305 -> V_306 <= V_307 ) )
F_105 ( V_4 ) ;
else
F_42 ( V_4 ) ;
}
static int F_106 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_304 * V_309 , int V_9 )
{
int V_310 ;
T_1 V_68 ;
V_310 = sizeof( T_1 ) * V_9 ;
V_309 -> V_311 = F_107 ( & V_235 -> V_237 , V_310 ,
& V_309 -> V_312 ,
V_102 ) ;
if ( ! V_309 -> V_311 )
return - V_152 ;
if ( ! F_108 ( ( unsigned long ) V_309 -> V_311 ,
V_313 ) ) {
F_109 ( & V_235 -> V_237 , V_310 , V_309 -> V_311 ,
V_309 -> V_312 ) ;
F_110 ( & V_235 -> V_237 , L_1 ,
V_309 -> V_25 , V_313 ) ;
return - V_152 ;
}
F_1 ( V_2 , F_111 ( V_309 -> V_25 ) ,
V_309 -> V_312 ) ;
F_1 ( V_2 , F_112 ( V_309 -> V_25 ) , V_9 ) ;
V_68 = F_3 ( V_2 , F_113 ( V_309 -> V_25 ) ) ;
V_68 |= V_314 ;
F_1 ( V_2 , F_113 ( V_309 -> V_25 ) , V_68 ) ;
V_309 -> type = V_315 ;
V_309 -> V_9 = V_9 ;
V_309 -> V_316 = 0 ;
V_309 -> V_317 = 0 ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_304 * V_309 ,
int V_318 )
{
T_1 V_68 ;
V_309 -> V_318 = V_318 ;
V_68 = F_115 ( V_318 , 1 << V_319 ) ;
F_1 ( V_2 , F_116 ( V_309 -> V_25 ) , V_68 ) ;
}
static void F_117 ( struct V_320 * V_237 , struct V_1 * V_2 ,
struct V_304 * V_309 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_309 -> V_317 ; V_30 ++ ) {
T_4 V_20 ;
unsigned long V_321 ;
V_20 = F_3 ( V_2 ,
F_118 ( V_309 -> V_25 ) ) ;
V_321 = F_3 ( V_2 , V_322 ) ;
F_119 ( V_237 , V_20 ,
V_309 -> V_318 , V_323 ) ;
if ( ! V_321 )
break;
F_104 ( V_309 , ( void * ) V_321 ) ;
}
V_309 -> V_317 -= V_30 ;
}
static int F_120 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_304 * V_309 )
{
T_1 V_68 ;
F_117 ( & V_235 -> V_237 , V_2 , V_309 ) ;
if ( V_309 -> V_317 ) {
F_121 ( 1 , L_2 , V_309 -> V_25 ) ;
return 0 ;
}
V_68 = F_3 ( V_2 , F_113 ( V_309 -> V_25 ) ) ;
V_68 |= V_324 ;
F_1 ( V_2 , F_113 ( V_309 -> V_25 ) , V_68 ) ;
F_109 ( & V_235 -> V_237 , sizeof( T_1 ) * V_309 -> V_9 ,
V_309 -> V_311 ,
V_309 -> V_312 ) ;
return 0 ;
}
static int F_122 ( struct V_234 * V_235 ,
struct V_1 * V_2 )
{
int V_30 , V_236 , V_9 ;
struct V_304 * V_309 ;
V_9 = V_325 ;
for ( V_30 = 0 ; V_30 < V_326 ; V_30 ++ ) {
V_309 = & V_2 -> V_327 [ V_30 ] ;
V_309 -> V_25 = V_30 ;
V_236 = F_106 ( V_235 , V_2 , V_309 , V_9 ) ;
if ( V_236 )
goto V_328;
F_114 ( V_2 , V_309 , 0 ) ;
}
return 0 ;
V_328:
F_110 ( & V_235 -> V_237 , L_3 , V_30 , V_9 ) ;
for ( V_30 = V_30 - 1 ; V_30 >= 0 ; V_30 -- )
F_120 ( V_235 , V_2 , & V_2 -> V_327 [ V_30 ] ) ;
return V_236 ;
}
static int F_123 ( struct V_234 * V_235 , struct V_1 * V_2 )
{
int V_30 , V_236 ;
for ( V_30 = 0 ; V_30 < V_326 ; V_30 ++ ) {
F_1 ( V_2 , F_124 ( V_30 ) , 0 ) ;
F_1 ( V_2 , F_125 ( V_30 ) , 0 ) ;
}
V_2 -> V_327 = F_75 ( & V_235 -> V_237 , V_326 ,
sizeof( struct V_304 ) , V_102 ) ;
if ( ! V_2 -> V_327 )
return - V_152 ;
V_236 = F_122 ( V_235 , V_2 ) ;
if ( V_236 < 0 )
return V_236 ;
return 0 ;
}
static void F_126 ( struct V_22 * V_23 ,
int V_329 , int V_330 )
{
T_1 V_68 ;
int V_331 ;
V_331 = V_23 -> V_332 [ V_329 ] -> V_25 ;
V_68 = F_3 ( V_23 -> V_2 , F_127 ( V_331 ) ) ;
V_68 &= ~ V_333 ;
V_68 |= ( ( V_330 << V_334 ) &
V_333 ) ;
F_1 ( V_23 -> V_2 , F_127 ( V_331 ) , V_68 ) ;
}
static void F_128 ( struct V_22 * V_23 ,
int V_329 , int V_335 )
{
T_1 V_68 ;
int V_331 ;
V_331 = V_23 -> V_332 [ V_329 ] -> V_25 ;
V_68 = F_3 ( V_23 -> V_2 , F_127 ( V_331 ) ) ;
V_68 &= ~ V_336 ;
V_68 |= ( ( V_335 << V_337 ) &
V_336 ) ;
F_1 ( V_23 -> V_2 , F_127 ( V_331 ) , V_68 ) ;
}
static void * F_129 ( struct V_22 * V_23 ,
struct V_304 * V_309 ,
T_4 * V_20 ,
T_5 V_338 )
{
T_4 V_312 ;
void * V_4 ;
V_4 = F_100 ( V_309 ) ;
if ( ! V_4 )
return NULL ;
V_312 = F_130 ( V_23 -> V_237 -> V_237 . V_339 , V_4 ,
F_131 ( V_309 -> V_316 ) ,
V_323 ) ;
if ( F_132 ( F_133 ( V_23 -> V_237 -> V_237 . V_339 , V_312 ) ) ) {
F_104 ( V_309 , V_4 ) ;
return NULL ;
}
* V_20 = V_312 ;
return V_4 ;
}
static inline T_1 F_134 ( T_1 V_340 , int V_305 )
{
T_1 V_341 ;
V_341 = V_340 & ~ ( 0xFF << V_342 ) ;
V_341 |= ( ( V_305 & 0xFF ) << V_342 ) ;
return V_341 ;
}
static inline int F_135 ( unsigned long V_340 )
{
return ( V_340 >> V_342 ) & 0xFF ;
}
static inline void F_136 ( struct V_22 * V_23 , int V_305 ,
T_4 V_20 ,
unsigned long V_343 )
{
F_1 ( V_23 -> V_2 , V_344 , V_343 ) ;
F_1 ( V_23 -> V_2 , F_137 ( V_305 ) , V_20 ) ;
}
static void F_138 ( struct V_22 * V_23 , int V_305 ,
T_4 V_20 ,
unsigned long V_343 ,
int V_345 )
{
T_1 V_68 = 0 ;
V_68 |= ( V_345 & V_346 ) ;
F_1 ( V_23 -> V_2 , V_347 , V_68 ) ;
F_136 ( V_23 , V_305 ,
V_20 | V_348 ,
V_343 ) ;
}
static void F_139 ( struct V_22 * V_23 , T_1 V_341 ,
T_4 V_312 ,
unsigned long V_340 )
{
int V_305 = F_135 ( V_341 ) ;
F_136 ( V_23 , V_305 , V_312 , V_340 ) ;
}
static int F_140 ( struct V_22 * V_23 ,
struct V_304 * V_309 , int V_317 )
{
int V_30 , V_318 , V_349 ;
T_4 V_312 ;
void * V_350 ;
V_318 = F_131 ( V_309 -> V_316 ) ;
V_349 = F_141 ( V_318 ) ;
if ( V_317 < 0 ||
( V_317 + V_309 -> V_317 > V_309 -> V_9 ) ) {
F_142 ( V_23 -> V_237 ,
L_4 ,
V_317 , V_309 -> V_25 ) ;
return 0 ;
}
for ( V_30 = 0 ; V_30 < V_317 ; V_30 ++ ) {
V_350 = F_129 ( V_23 , V_309 , & V_312 , V_102 ) ;
if ( ! V_350 )
break;
F_136 ( V_23 , V_309 -> V_25 , V_312 ,
( unsigned long ) V_350 ) ;
}
V_309 -> V_317 += V_30 ;
F_143 ( V_23 -> V_237 ,
L_5 ,
V_309 -> type == V_351 ? L_6 : L_7 ,
V_309 -> V_25 , V_309 -> V_316 , V_318 , V_349 ) ;
F_143 ( V_23 -> V_237 ,
L_8 ,
V_309 -> type == V_351 ? L_6 : L_7 ,
V_309 -> V_25 , V_30 , V_317 ) ;
return V_30 ;
}
static struct V_304 *
F_144 ( struct V_22 * V_23 , int V_305 , enum V_352 type ,
int V_316 )
{
struct V_304 * V_353 = & V_23 -> V_2 -> V_327 [ V_305 ] ;
int V_354 ;
if ( V_353 -> type != V_315 && V_353 -> type != type ) {
F_142 ( V_23 -> V_237 , L_9 ) ;
return NULL ;
}
if ( V_353 -> type == V_315 )
V_353 -> type = type ;
if ( ( ( type == V_355 ) && ( V_316 > V_353 -> V_316 ) ) ||
( V_353 -> V_316 == 0 ) ) {
int V_356 ;
V_356 = V_353 -> V_317 ;
if ( V_356 == 0 )
V_356 = type == V_355 ?
V_357 :
V_358 ;
else
F_117 ( V_23 -> V_237 -> V_237 . V_339 ,
V_23 -> V_2 , V_353 ) ;
V_353 -> V_316 = V_316 ;
V_353 -> V_306 =
F_145 ( F_131 ( V_316 ) ) +
V_359 ;
V_354 = F_140 ( V_23 , V_353 , V_356 ) ;
if ( V_354 != V_356 ) {
F_121 ( 1 , L_10 ,
V_353 -> V_25 , V_354 , V_356 ) ;
return NULL ;
}
}
F_114 ( V_23 -> V_2 , V_353 ,
F_131 ( V_353 -> V_316 ) ) ;
return V_353 ;
}
static int F_146 ( struct V_22 * V_23 )
{
int V_360 ;
if ( ! V_23 -> V_361 ) {
V_23 -> V_361 =
F_144 ( V_23 , F_147 ( V_23 -> V_25 ) ,
V_355 ,
V_23 -> V_316 ) ;
if ( ! V_23 -> V_361 )
return - V_152 ;
V_23 -> V_361 -> V_149 |= ( 1 << V_23 -> V_25 ) ;
for ( V_360 = 0 ; V_360 < V_362 ; V_360 ++ )
F_126 ( V_23 , V_360 , V_23 -> V_361 -> V_25 ) ;
}
if ( ! V_23 -> V_363 ) {
V_23 -> V_363 =
F_144 ( V_23 , V_364 ,
V_351 ,
V_365 ) ;
if ( ! V_23 -> V_363 )
return - V_152 ;
V_23 -> V_363 -> V_149 |= ( 1 << V_23 -> V_25 ) ;
for ( V_360 = 0 ; V_360 < V_362 ; V_360 ++ )
F_128 ( V_23 , V_360 ,
V_23 -> V_363 -> V_25 ) ;
}
return 0 ;
}
static int F_148 ( struct V_273 * V_237 , int V_366 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
struct V_304 * V_367 = V_23 -> V_361 ;
int V_354 , V_356 = V_367 -> V_317 ;
int V_316 = F_149 ( V_366 ) ;
F_117 ( V_237 -> V_237 . V_339 , V_23 -> V_2 , V_367 ) ;
if ( V_367 -> V_317 ) {
F_121 ( 1 , L_2 , V_367 -> V_25 ) ;
return - V_368 ;
}
V_367 -> V_316 = V_316 ;
V_367 -> V_306 = F_145 ( F_131 ( V_316 ) ) +
V_359 ;
V_354 = F_140 ( V_23 , V_367 , V_356 ) ;
if ( V_354 != V_356 ) {
F_121 ( 1 , L_10 ,
V_367 -> V_25 , V_354 , V_356 ) ;
return - V_368 ;
}
F_114 ( V_23 -> V_2 , V_367 ,
F_131 ( V_367 -> V_316 ) ) ;
V_237 -> V_366 = V_366 ;
F_150 ( V_237 ) ;
return 0 ;
}
static inline void F_151 ( struct V_22 * V_23 )
{
int V_369 , V_370 = 0 ;
F_152 (cpu)
V_370 |= 1 << V_369 ;
F_1 ( V_23 -> V_2 , F_153 ( V_23 -> V_25 ) ,
F_154 ( V_370 ) ) ;
}
static inline void F_155 ( struct V_22 * V_23 )
{
int V_369 , V_370 = 0 ;
F_152 (cpu)
V_370 |= 1 << V_369 ;
F_1 ( V_23 -> V_2 , F_153 ( V_23 -> V_25 ) ,
F_156 ( V_370 ) ) ;
}
static void F_157 ( void * V_371 )
{
struct V_22 * V_23 = V_371 ;
F_1 ( V_23 -> V_2 , F_158 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_159 ( void * V_371 )
{
struct V_22 * V_23 = V_371 ;
F_1 ( V_23 -> V_2 , F_158 ( V_23 -> V_25 ) ,
( V_372 |
V_373 ) ) ;
}
static void F_160 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_374 ) ;
switch ( V_23 -> V_375 ) {
case V_376 :
V_68 |= V_377 ;
break;
case V_378 :
V_68 |= V_379 ;
default:
V_68 &= ~ V_380 ;
}
F_2 ( V_68 , V_23 -> V_5 + V_374 ) ;
}
static void F_161 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_381 ) ;
V_68 |= V_382 ;
F_2 ( V_68 , V_23 -> V_5 + V_381 ) ;
}
static void F_162 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_383 ) ;
V_68 |= V_384 ;
V_68 |= V_385 ;
F_2 ( V_68 , V_23 -> V_5 + V_383 ) ;
}
static void F_163 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_383 ) ;
V_68 &= ~ ( V_384 ) ;
F_2 ( V_68 , V_23 -> V_5 + V_383 ) ;
}
static void F_164 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_386 ) &
~ V_387 ;
F_2 ( V_68 , V_23 -> V_5 + V_386 ) ;
}
static void F_165 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_386 ) ;
if ( V_23 -> V_388 == 1000 )
V_68 |= V_389 ;
else
V_68 &= ~ V_389 ;
if ( V_23 -> V_375 == V_376 )
V_68 |= V_390 ;
else
V_68 &= ~ V_390 ;
F_2 ( V_68 , V_23 -> V_5 + V_386 ) ;
}
static void F_166 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_374 ) &
~ V_391 ;
F_2 ( V_68 , V_23 -> V_5 + V_374 ) ;
while ( F_4 ( V_23 -> V_5 + V_374 ) &
V_391 )
continue;
}
static inline void F_167 ( struct V_22 * V_23 )
{
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_383 ) ;
V_68 &= ~ V_392 ;
V_68 |= ( ( ( V_23 -> V_316 - V_198 ) / 2 ) <<
V_393 ) ;
F_2 ( V_68 , V_23 -> V_5 + V_383 ) ;
}
static void F_168 ( struct V_22 * V_23 )
{
int V_394 , V_68 , V_395 , V_396 , V_329 ;
if ( V_23 -> V_397 & V_398 )
F_165 ( V_23 ) ;
V_68 = F_4 ( V_23 -> V_5 + V_399 ) ;
V_68 &= ~ V_400 ;
V_68 |= F_169 ( 64 - 4 - 2 ) ;
F_2 ( V_68 , V_23 -> V_5 + V_399 ) ;
V_394 = F_7 ( V_23 ) ;
F_1 ( V_23 -> V_2 , V_401 ,
V_394 ) ;
F_1 ( V_23 -> V_2 , V_402 , 0 ) ;
for ( V_395 = 0 ; V_395 < V_27 ; V_395 ++ ) {
V_396 = F_8 ( V_23 -> V_25 , V_395 ) ;
F_1 ( V_23 -> V_2 ,
F_170 ( V_396 ) , 0 ) ;
}
F_1 ( V_23 -> V_2 , V_403 ,
V_23 -> V_2 -> V_404 / V_405 ) ;
V_68 = F_3 ( V_23 -> V_2 , V_406 ) ;
V_68 &= ~ V_407 ;
V_68 |= F_171 ( 1 ) ;
V_68 |= V_408 ;
F_1 ( V_23 -> V_2 , V_406 , V_68 ) ;
V_68 = V_409 ;
F_1 ( V_23 -> V_2 , V_410 , V_68 ) ;
F_1 ( V_23 -> V_2 , F_172 ( V_23 -> V_25 ) ,
V_411 |
F_173 ( 256 ) ) ;
for ( V_329 = 0 ; V_329 < V_362 ; V_329 ++ ) {
V_395 = V_23 -> V_332 [ V_329 ] -> V_25 ;
V_68 = F_3 ( V_23 -> V_2 , F_127 ( V_395 ) ) ;
V_68 |= V_412 |
V_413 ;
F_1 ( V_23 -> V_2 , F_127 ( V_395 ) , V_68 ) ;
}
F_155 ( V_23 ) ;
}
static void F_174 ( struct V_22 * V_23 )
{
T_1 V_68 ;
int V_329 , V_395 ;
for ( V_329 = 0 ; V_329 < V_362 ; V_329 ++ ) {
V_395 = V_23 -> V_332 [ V_329 ] -> V_25 ;
V_68 = F_3 ( V_23 -> V_2 , F_127 ( V_395 ) ) ;
V_68 &= ~ V_414 ;
F_1 ( V_23 -> V_2 , F_127 ( V_395 ) , V_68 ) ;
}
}
static void F_175 ( struct V_22 * V_23 )
{
T_1 V_68 ;
int V_329 , V_395 ;
for ( V_329 = 0 ; V_329 < V_362 ; V_329 ++ ) {
V_395 = V_23 -> V_332 [ V_329 ] -> V_25 ;
V_68 = F_3 ( V_23 -> V_2 , F_127 ( V_395 ) ) ;
V_68 |= V_414 ;
F_1 ( V_23 -> V_2 , F_127 ( V_395 ) , V_68 ) ;
}
}
static void F_176 ( struct V_22 * V_23 )
{
T_1 V_415 ;
int V_395 ;
int V_394 = F_7 ( V_23 ) ;
V_415 = 0 ;
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
struct V_417 * V_26 = V_23 -> V_418 [ V_395 ] ;
if ( V_26 -> V_419 != NULL )
V_415 |= ( 1 << V_395 ) ;
}
F_1 ( V_23 -> V_2 , V_401 , V_394 ) ;
F_1 ( V_23 -> V_2 , V_420 , V_415 ) ;
}
static void F_177 ( struct V_22 * V_23 )
{
T_1 V_421 ;
int V_422 ;
int V_394 = F_7 ( V_23 ) ;
F_1 ( V_23 -> V_2 , V_401 , V_394 ) ;
V_421 = ( F_3 ( V_23 -> V_2 , V_420 ) ) &
V_423 ;
if ( V_421 != 0 )
F_1 ( V_23 -> V_2 , V_420 ,
( V_421 << V_424 ) ) ;
V_422 = 0 ;
do {
if ( V_422 >= V_425 ) {
F_178 ( V_23 -> V_237 ,
L_11 ,
V_421 ) ;
break;
}
F_179 ( 1 ) ;
V_422 ++ ;
V_421 = F_3 ( V_23 -> V_2 , V_420 ) ;
} while ( V_421 & V_423 );
}
static inline int
F_180 ( struct V_22 * V_23 , int V_426 )
{
T_1 V_68 = F_3 ( V_23 -> V_2 , F_181 ( V_426 ) ) ;
return V_68 & V_427 ;
}
static inline void
F_182 ( struct V_22 * V_23 , int V_426 ,
int V_428 , int V_429 )
{
T_1 V_68 = V_428 | ( V_429 << V_430 ) ;
F_1 ( V_23 -> V_2 , F_183 ( V_426 ) , V_68 ) ;
}
static inline struct V_431 *
F_184 ( struct V_432 * V_360 )
{
int V_433 = V_360 -> V_434 ;
V_360 -> V_434 = F_185 ( V_360 , V_433 ) ;
F_186 ( V_360 -> V_419 + V_360 -> V_434 ) ;
return V_360 -> V_419 + V_433 ;
}
static void F_187 ( struct V_22 * V_23 ,
int V_331 , int V_3 )
{
T_1 V_68 ;
V_3 = V_3 >> 5 ;
V_68 = F_3 ( V_23 -> V_2 , F_127 ( V_331 ) ) ;
V_68 &= ~ V_435 ;
V_68 |= ( ( V_3 << V_436 ) &
V_435 ) ;
F_1 ( V_23 -> V_2 , F_127 ( V_331 ) , V_68 ) ;
}
static T_1 F_188 ( struct V_431 * V_433 )
{
int V_305 = ( V_433 -> V_437 & V_438 ) >>
V_439 ;
int V_369 = F_189 () ;
return ( ( V_305 & 0xFF ) << V_342 ) |
( ( V_369 & 0xFF ) << V_440 ) ;
}
static int F_190 ( struct V_22 * V_23 ,
struct V_417 * V_26 )
{
T_1 V_68 ;
F_1 ( V_23 -> V_2 , V_441 , V_26 -> V_25 ) ;
V_68 = F_3 ( V_23 -> V_2 , V_442 ) ;
return V_68 & V_443 ;
}
static struct V_12 *
F_191 ( struct V_417 * V_26 )
{
int V_13 = V_26 -> V_434 ;
V_26 -> V_434 = F_185 ( V_26 , V_13 ) ;
return V_26 -> V_419 + V_13 ;
}
static void F_192 ( struct V_22 * V_23 , int V_444 )
{
F_1 ( V_23 -> V_2 , V_445 , V_444 ) ;
}
static int F_193 ( struct V_1 * V_2 ,
struct V_417 * V_446 , int V_354 )
{
if ( ( V_446 -> V_447 + V_354 ) > V_446 -> V_9 ) {
int V_369 = F_189 () ;
T_1 V_68 = F_3 ( V_2 , F_194 ( V_369 ) ) ;
V_446 -> V_447 = V_68 & V_448 ;
}
if ( ( V_446 -> V_447 + V_354 ) > V_446 -> V_9 )
return - V_152 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_417 * V_26 , int V_354 )
{
T_1 V_68 ;
V_68 = ( V_26 -> V_25 << V_449 ) | V_354 ;
F_1 ( V_2 , V_450 , V_68 ) ;
V_68 = F_3 ( V_2 , V_451 ) ;
return V_68 & V_452 ;
}
static int F_196 ( struct V_1 * V_2 ,
struct V_417 * V_26 ,
struct V_6 * V_7 ,
int V_354 )
{
int V_453 , V_369 , V_454 ;
if ( V_7 -> V_455 >= V_354 )
return 0 ;
V_454 = 0 ;
F_152 (cpu) {
struct V_6 * V_456 ;
V_456 = F_197 ( V_26 -> V_457 , V_369 ) ;
V_454 += V_456 -> V_447 ;
V_454 += V_456 -> V_455 ;
}
V_453 = F_198 ( V_458 , V_354 - V_7 -> V_455 ) ;
V_454 += V_453 ;
if ( V_454 >
( V_26 -> V_9 - ( F_199 () * V_458 ) ) )
return - V_152 ;
V_7 -> V_455 += F_195 ( V_2 , V_26 , V_453 ) ;
if ( V_7 -> V_455 < V_354 )
return - V_152 ;
return 0 ;
}
static void F_200 ( struct V_417 * V_26 )
{
if ( V_26 -> V_434 == 0 )
V_26 -> V_434 = V_26 -> V_459 - 1 ;
else
V_26 -> V_434 -- ;
}
static T_1 F_201 ( int V_460 , int V_461 ,
int V_462 , int V_463 )
{
T_1 V_464 ;
V_464 = ( V_460 << V_465 ) ;
V_464 |= ( V_462 << V_466 ) ;
V_464 |= V_467 ;
if ( V_461 == F_51 ( V_222 ) ) {
V_464 &= ~ V_467 ;
V_464 &= ~ V_468 ;
} else {
V_464 |= V_468 ;
}
if ( V_463 == V_162 ) {
V_464 &= ~ V_469 ;
V_464 &= ~ V_470 ;
} else if ( V_463 == V_163 ) {
V_464 |= V_469 ;
V_464 &= ~ V_470 ;
} else {
V_464 |= V_471 ;
}
return V_464 ;
}
static inline int F_202 ( struct V_22 * V_23 ,
struct V_417 * V_26 )
{
T_1 V_68 ;
V_68 = F_3 ( V_23 -> V_2 , F_203 ( V_26 -> V_25 ) ) ;
return ( V_68 & V_472 ) >>
V_473 ;
}
static void F_204 ( void * V_371 )
{
struct V_22 * V_23 = V_371 ;
int V_395 ;
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
int V_25 = V_23 -> V_418 [ V_395 ] -> V_25 ;
F_3 ( V_23 -> V_2 , F_203 ( V_25 ) ) ;
}
}
static void F_205 ( struct V_22 * V_23 )
{
T_1 V_68 , V_9 , V_366 ;
int V_26 , V_394 ;
V_366 = V_23 -> V_316 * 8 ;
if ( V_366 > V_474 )
V_366 = V_474 ;
V_366 = 3 * V_366 ;
V_394 = F_7 ( V_23 ) ;
F_1 ( V_23 -> V_2 , V_401 , V_394 ) ;
V_68 = F_3 ( V_23 -> V_2 , V_475 ) ;
V_68 &= ~ V_474 ;
V_68 |= V_366 ;
F_1 ( V_23 -> V_2 , V_475 , V_68 ) ;
V_68 = F_3 ( V_23 -> V_2 , V_410 ) ;
V_9 = V_68 & V_409 ;
if ( V_9 < V_366 ) {
V_9 = V_366 ;
V_68 &= ~ V_409 ;
V_68 |= V_9 ;
F_1 ( V_23 -> V_2 , V_410 , V_68 ) ;
}
for ( V_26 = 0 ; V_26 < V_416 ; V_26 ++ ) {
V_68 = F_3 ( V_23 -> V_2 ,
F_206 ( V_26 ) ) ;
V_9 = V_68 & V_476 ;
if ( V_9 < V_366 ) {
V_9 = V_366 ;
V_68 &= ~ V_476 ;
V_68 |= V_9 ;
F_1 ( V_23 -> V_2 ,
F_206 ( V_26 ) ,
V_68 ) ;
}
}
}
static void F_207 ( struct V_22 * V_23 ,
struct V_432 * V_360 )
{
if ( V_360 -> V_477 > V_478 )
V_360 -> V_477 = V_478 ;
F_1 ( V_23 -> V_2 , V_479 , V_360 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_480 ,
V_360 -> V_477 ) ;
}
static T_1 F_208 ( T_1 V_481 , unsigned long V_482 )
{
T_6 V_483 = ( T_6 ) V_482 * V_481 ;
F_209 ( V_483 , V_405 ) ;
return V_483 > V_484 ? V_484 : V_483 ;
}
static T_1 F_210 ( T_1 V_485 , unsigned long V_482 )
{
T_6 V_483 = ( T_6 ) V_485 * V_405 ;
F_209 ( V_483 , V_482 ) ;
return V_483 > V_484 ? V_484 : V_483 ;
}
static void F_211 ( struct V_22 * V_23 ,
struct V_432 * V_360 )
{
unsigned long V_486 = V_23 -> V_2 -> V_404 ;
T_1 V_68 = F_208 ( V_360 -> V_487 , V_486 ) ;
if ( V_68 > V_488 ) {
V_360 -> V_487 =
F_210 ( V_488 , V_486 ) ;
V_68 = F_208 ( V_360 -> V_487 , V_486 ) ;
}
F_1 ( V_23 -> V_2 , F_212 ( V_360 -> V_25 ) , V_68 ) ;
}
static void F_213 ( struct V_22 * V_23 ,
struct V_417 * V_26 ,
struct V_6 * V_7 , int V_354 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_354 ; V_30 ++ ) {
struct V_14 * V_15 =
V_7 -> V_16 + V_7 -> V_8 ;
F_119 ( V_23 -> V_237 -> V_237 . V_339 , V_15 -> V_19 ,
V_15 -> V_9 , V_489 ) ;
if ( V_15 -> V_11 )
F_214 ( V_15 -> V_11 ) ;
F_5 ( V_7 ) ;
}
}
static inline struct V_432 * F_215 ( struct V_22 * V_23 ,
T_1 V_490 )
{
int V_395 = F_216 ( V_490 ) - 1 ;
return V_23 -> V_332 [ V_395 ] ;
}
static inline struct V_417 * F_217 ( struct V_22 * V_23 ,
T_1 V_490 )
{
int V_395 = F_216 ( V_490 ) - 1 ;
return V_23 -> V_418 [ V_395 ] ;
}
static void F_218 ( struct V_22 * V_23 , struct V_417 * V_26 ,
struct V_6 * V_7 )
{
struct V_491 * V_492 = F_219 ( V_23 -> V_237 , V_26 -> V_493 ) ;
int V_494 ;
if ( V_7 -> V_369 != F_189 () )
F_142 ( V_23 -> V_237 , L_12 ) ;
V_494 = F_202 ( V_23 , V_26 ) ;
if ( ! V_494 )
return;
F_213 ( V_23 , V_26 , V_7 , V_494 ) ;
V_7 -> V_447 -= V_494 ;
if ( F_220 ( V_492 ) )
if ( V_7 -> V_9 - V_7 -> V_447 >= V_495 + 1 )
F_221 ( V_492 ) ;
}
static unsigned int F_222 ( struct V_22 * V_23 , T_1 V_490 )
{
struct V_417 * V_26 ;
struct V_6 * V_7 ;
unsigned int V_496 = 0 ;
while ( V_490 ) {
V_26 = F_217 ( V_23 , V_490 ) ;
if ( ! V_26 )
break;
V_7 = F_223 ( V_26 -> V_457 ) ;
if ( V_7 -> V_447 ) {
F_218 ( V_23 , V_26 , V_7 ) ;
V_496 += V_7 -> V_447 ;
}
V_490 &= ~ ( 1 << V_26 -> V_493 ) ;
}
return V_496 ;
}
static int F_224 ( struct V_234 * V_235 ,
struct V_417 * V_446 ,
int V_497 , int V_369 ,
struct V_1 * V_2 )
{
V_446 -> V_419 = F_107 ( & V_235 -> V_237 ,
V_497 * V_498 ,
& V_446 -> V_499 , V_102 ) ;
if ( ! V_446 -> V_419 )
return - V_152 ;
V_446 -> V_459 = V_446 -> V_9 - 1 ;
V_446 -> V_434 = F_3 ( V_2 ,
F_225 ( V_369 ) ) ;
F_1 ( V_2 , F_226 ( V_369 ) ,
V_446 -> V_499 ) ;
F_1 ( V_2 , F_227 ( V_369 ) , V_497 ) ;
return 0 ;
}
static int F_228 ( struct V_22 * V_23 ,
struct V_432 * V_360 )
{
V_360 -> V_9 = V_23 -> V_500 ;
V_360 -> V_419 = F_107 ( V_23 -> V_237 -> V_237 . V_339 ,
V_360 -> V_9 * V_498 ,
& V_360 -> V_499 , V_102 ) ;
if ( ! V_360 -> V_419 )
return - V_152 ;
V_360 -> V_459 = V_360 -> V_9 - 1 ;
F_1 ( V_23 -> V_2 , F_181 ( V_360 -> V_25 ) , 0 ) ;
F_1 ( V_23 -> V_2 , V_479 , V_360 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_501 , V_360 -> V_499 ) ;
F_1 ( V_23 -> V_2 , V_502 , V_360 -> V_9 ) ;
F_1 ( V_23 -> V_2 , V_503 , 0 ) ;
F_187 ( V_23 , V_360 -> V_25 , V_504 ) ;
F_207 ( V_23 , V_360 ) ;
F_211 ( V_23 , V_360 ) ;
F_182 ( V_23 , V_360 -> V_25 , 0 , V_360 -> V_9 ) ;
return 0 ;
}
static void F_229 ( struct V_22 * V_23 ,
struct V_432 * V_360 )
{
int V_505 , V_30 ;
V_505 = F_180 ( V_23 , V_360 -> V_25 ) ;
if ( ! V_505 )
return;
for ( V_30 = 0 ; V_30 < V_505 ; V_30 ++ ) {
struct V_431 * V_433 = F_184 ( V_360 ) ;
T_1 V_341 = F_188 ( V_433 ) ;
F_139 ( V_23 , V_341 , V_433 -> V_20 ,
V_433 -> V_506 ) ;
}
F_182 ( V_23 , V_360 -> V_25 , V_505 , V_505 ) ;
}
static void F_230 ( struct V_22 * V_23 ,
struct V_432 * V_360 )
{
F_229 ( V_23 , V_360 ) ;
if ( V_360 -> V_419 )
F_109 ( V_23 -> V_237 -> V_237 . V_339 ,
V_360 -> V_9 * V_498 ,
V_360 -> V_419 ,
V_360 -> V_499 ) ;
V_360 -> V_419 = NULL ;
V_360 -> V_459 = 0 ;
V_360 -> V_434 = 0 ;
V_360 -> V_499 = 0 ;
F_1 ( V_23 -> V_2 , F_181 ( V_360 -> V_25 ) , 0 ) ;
F_1 ( V_23 -> V_2 , V_479 , V_360 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_501 , 0 ) ;
F_1 ( V_23 -> V_2 , V_502 , 0 ) ;
}
static int F_231 ( struct V_22 * V_23 ,
struct V_417 * V_26 )
{
T_1 V_68 ;
int V_369 , V_507 , V_508 , V_394 ;
struct V_6 * V_7 ;
V_26 -> V_9 = V_23 -> V_509 ;
V_26 -> V_419 = F_107 ( V_23 -> V_237 -> V_237 . V_339 ,
V_26 -> V_9 * V_498 ,
& V_26 -> V_499 , V_102 ) ;
if ( ! V_26 -> V_419 )
return - V_152 ;
V_26 -> V_459 = V_26 -> V_9 - 1 ;
F_1 ( V_23 -> V_2 , V_441 , V_26 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_510 , V_26 -> V_499 ) ;
F_1 ( V_23 -> V_2 , V_511 , V_26 -> V_9 &
V_512 ) ;
F_1 ( V_23 -> V_2 , V_513 , 0 ) ;
F_1 ( V_23 -> V_2 , V_514 ,
V_26 -> V_25 << V_515 ) ;
V_68 = F_3 ( V_23 -> V_2 , V_442 ) ;
V_68 &= ~ V_443 ;
F_1 ( V_23 -> V_2 , V_442 , V_68 ) ;
V_508 = 16 ;
V_507 = ( V_23 -> V_25 * V_27 * V_508 ) +
( V_26 -> V_493 * V_508 ) ;
F_1 ( V_23 -> V_2 , V_516 ,
F_232 ( V_507 ) | V_517 |
F_233 ( V_508 / 2 ) ) ;
V_394 = F_7 ( V_23 ) ;
F_1 ( V_23 -> V_2 , V_401 , V_394 ) ;
V_68 = F_3 ( V_23 -> V_2 , F_234 ( V_26 -> V_493 ) ) ;
V_68 &= ~ V_518 ;
V_68 |= F_235 ( 1 ) ;
V_68 |= V_519 ;
F_1 ( V_23 -> V_2 , F_234 ( V_26 -> V_493 ) , V_68 ) ;
V_68 = V_476 ;
F_1 ( V_23 -> V_2 , F_206 ( V_26 -> V_493 ) ,
V_68 ) ;
F_152 (cpu) {
V_7 = F_197 ( V_26 -> V_457 , V_369 ) ;
V_7 -> V_9 = V_26 -> V_9 ;
V_7 -> V_16 = F_103 ( V_7 -> V_9 *
sizeof( struct V_14 ) ,
V_102 ) ;
if ( ! V_7 -> V_16 )
goto error;
V_7 -> V_447 = 0 ;
V_7 -> V_455 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_8 = 0 ;
}
return 0 ;
error:
F_152 (cpu) {
V_7 = F_197 ( V_26 -> V_457 , V_369 ) ;
F_42 ( V_7 -> V_16 ) ;
}
F_109 ( V_23 -> V_237 -> V_237 . V_339 ,
V_26 -> V_9 * V_498 ,
V_26 -> V_419 , V_26 -> V_499 ) ;
return - V_152 ;
}
static void F_236 ( struct V_22 * V_23 ,
struct V_417 * V_26 )
{
struct V_6 * V_7 ;
int V_369 ;
F_152 (cpu) {
V_7 = F_197 ( V_26 -> V_457 , V_369 ) ;
F_42 ( V_7 -> V_16 ) ;
}
if ( V_26 -> V_419 )
F_109 ( V_23 -> V_237 -> V_237 . V_339 ,
V_26 -> V_9 * V_498 ,
V_26 -> V_419 , V_26 -> V_499 ) ;
V_26 -> V_419 = NULL ;
V_26 -> V_459 = 0 ;
V_26 -> V_434 = 0 ;
V_26 -> V_499 = 0 ;
F_1 ( V_23 -> V_2 , F_170 ( V_26 -> V_25 ) , 0 ) ;
F_1 ( V_23 -> V_2 , V_441 , V_26 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_510 , 0 ) ;
F_1 ( V_23 -> V_2 , V_511 , 0 ) ;
}
static void F_237 ( struct V_22 * V_23 , struct V_417 * V_26 )
{
struct V_6 * V_7 ;
int V_422 , V_444 , V_369 ;
T_1 V_68 ;
F_1 ( V_23 -> V_2 , V_441 , V_26 -> V_25 ) ;
V_68 = F_3 ( V_23 -> V_2 , V_516 ) ;
V_68 |= V_520 ;
F_1 ( V_23 -> V_2 , V_516 , V_68 ) ;
V_422 = 0 ;
do {
if ( V_422 >= V_521 ) {
F_178 ( V_23 -> V_237 ,
L_13 ,
V_23 -> V_25 , V_26 -> V_493 ) ;
break;
}
F_179 ( 1 ) ;
V_422 ++ ;
V_444 = F_190 ( V_23 , V_26 ) ;
} while ( V_444 );
V_68 &= ~ V_520 ;
F_1 ( V_23 -> V_2 , V_516 , V_68 ) ;
F_152 (cpu) {
V_7 = F_197 ( V_26 -> V_457 , V_369 ) ;
F_213 ( V_23 , V_26 , V_7 , V_7 -> V_447 ) ;
V_7 -> V_447 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_8 = 0 ;
}
}
static void F_238 ( struct V_22 * V_23 )
{
struct V_417 * V_26 ;
int V_395 ;
T_1 V_68 ;
V_68 = F_3 ( V_23 -> V_2 , V_522 ) ;
V_68 |= F_239 ( V_23 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_522 , V_68 ) ;
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
V_26 = V_23 -> V_418 [ V_395 ] ;
F_237 ( V_23 , V_26 ) ;
F_236 ( V_23 , V_26 ) ;
}
F_240 ( F_204 , V_23 , 1 ) ;
V_68 &= ~ F_239 ( V_23 -> V_25 ) ;
F_1 ( V_23 -> V_2 , V_522 , V_68 ) ;
}
static void F_241 ( struct V_22 * V_23 )
{
int V_395 ;
for ( V_395 = 0 ; V_395 < V_362 ; V_395 ++ )
F_230 ( V_23 , V_23 -> V_332 [ V_395 ] ) ;
}
static int F_242 ( struct V_22 * V_23 )
{
int V_395 , V_236 ;
for ( V_395 = 0 ; V_395 < V_362 ; V_395 ++ ) {
V_236 = F_228 ( V_23 , V_23 -> V_332 [ V_395 ] ) ;
if ( V_236 )
goto V_523;
}
return 0 ;
V_523:
F_241 ( V_23 ) ;
return V_236 ;
}
static int F_243 ( struct V_22 * V_23 )
{
struct V_417 * V_26 ;
int V_395 , V_236 ;
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
V_26 = V_23 -> V_418 [ V_395 ] ;
V_236 = F_231 ( V_23 , V_26 ) ;
if ( V_236 )
goto V_523;
}
F_240 ( F_204 , V_23 , 1 ) ;
return 0 ;
V_523:
F_238 ( V_23 ) ;
return V_236 ;
}
static T_7 F_244 ( int V_524 , void * V_525 )
{
struct V_22 * V_23 = (struct V_22 * ) V_525 ;
F_155 ( V_23 ) ;
F_245 ( & V_23 -> V_526 ) ;
return V_527 ;
}
static void F_246 ( struct V_273 * V_237 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
struct V_528 * V_529 = V_237 -> V_529 ;
int V_530 = 0 ;
T_1 V_68 ;
if ( V_529 -> V_531 ) {
if ( ( V_23 -> V_388 != V_529 -> V_388 ) ||
( V_23 -> V_532 != V_529 -> V_532 ) ) {
T_1 V_68 ;
V_68 = F_4 ( V_23 -> V_5 + V_381 ) ;
V_68 &= ~ ( V_533 |
V_534 |
V_535 |
V_536 |
V_537 ) ;
if ( V_529 -> V_532 )
V_68 |= V_535 ;
if ( V_529 -> V_388 == V_538 )
V_68 |= V_534 ;
else if ( V_529 -> V_388 == V_539 )
V_68 |= V_533 ;
F_2 ( V_68 , V_23 -> V_5 + V_381 ) ;
V_23 -> V_532 = V_529 -> V_532 ;
V_23 -> V_388 = V_529 -> V_388 ;
}
}
if ( V_529 -> V_531 != V_23 -> V_531 ) {
if ( ! V_529 -> V_531 ) {
V_23 -> V_532 = - 1 ;
V_23 -> V_388 = 0 ;
}
V_23 -> V_531 = V_529 -> V_531 ;
V_530 = 1 ;
}
if ( V_530 ) {
if ( V_529 -> V_531 ) {
V_68 = F_4 ( V_23 -> V_5 + V_381 ) ;
V_68 |= ( V_540 |
V_541 ) ;
F_2 ( V_68 , V_23 -> V_5 + V_381 ) ;
F_176 ( V_23 ) ;
F_174 ( V_23 ) ;
} else {
F_175 ( V_23 ) ;
F_177 ( V_23 ) ;
}
F_247 ( V_529 ) ;
}
}
static void F_248 ( struct V_542 * V_543 )
{
T_8 V_544 ;
if ( ! V_543 -> V_545 ) {
V_543 -> V_545 = true ;
V_544 = V_546 ;
F_249 ( & V_543 -> V_547 , V_544 ,
V_548 ) ;
}
}
static void F_250 ( unsigned long V_4 )
{
struct V_273 * V_237 = (struct V_273 * ) V_4 ;
struct V_22 * V_23 = F_86 ( V_237 ) ;
struct V_542 * V_543 = F_223 ( V_23 -> V_457 ) ;
unsigned int V_496 , V_490 ;
if ( ! F_251 ( V_237 ) )
return;
V_543 -> V_545 = false ;
V_490 = ( 1 << V_416 ) - 1 ;
V_496 = F_222 ( V_23 , V_490 ) ;
if ( V_496 )
F_248 ( V_543 ) ;
}
static enum V_549 F_252 ( struct V_550 * V_551 )
{
struct V_542 * V_543 = F_253 ( V_551 ,
struct V_542 ,
V_547 ) ;
F_254 ( & V_543 -> V_552 ) ;
return V_553 ;
}
static void F_255 ( struct V_22 * V_23 ,
struct V_431 * V_433 )
{
T_1 V_437 = V_433 -> V_437 ;
switch ( V_437 & V_554 ) {
case V_555 :
F_142 ( V_23 -> V_237 , L_14 ,
V_437 , V_433 -> V_18 ) ;
break;
case V_556 :
F_142 ( V_23 -> V_237 , L_15 ,
V_437 , V_433 -> V_18 ) ;
break;
case V_557 :
F_142 ( V_23 -> V_237 , L_16 ,
V_437 , V_433 -> V_18 ) ;
break;
}
}
static void F_256 ( struct V_22 * V_23 , T_1 V_437 ,
struct V_10 * V_11 )
{
if ( ( ( V_437 & V_558 ) &&
! ( V_437 & V_559 ) ) ||
( V_437 & V_560 ) )
if ( ( ( V_437 & V_561 ) ||
( V_437 & V_562 ) ) &&
( V_437 & V_563 ) ) {
V_11 -> V_564 = 0 ;
V_11 -> V_565 = V_566 ;
return;
}
V_11 -> V_565 = V_567 ;
}
static int F_257 ( struct V_22 * V_23 ,
struct V_304 * V_309 , T_1 V_341 )
{
T_4 V_312 ;
void * V_350 ;
V_350 = F_129 ( V_23 , V_309 , & V_312 , V_308 ) ;
if ( ! V_350 )
return - V_152 ;
F_139 ( V_23 , V_341 , V_312 , ( unsigned long ) V_350 ) ;
return 0 ;
}
static T_1 F_258 ( struct V_22 * V_23 , struct V_10 * V_11 )
{
if ( V_11 -> V_565 == V_568 ) {
int V_462 = 0 ;
T_3 V_463 ;
if ( V_11 -> V_569 == F_259 ( V_222 ) ) {
struct V_167 * V_570 = F_260 ( V_11 ) ;
V_462 = V_570 -> V_571 ;
V_463 = V_570 -> V_569 ;
} else if ( V_11 -> V_569 == F_259 ( V_229 ) ) {
struct V_186 * V_572 = F_261 ( V_11 ) ;
if ( F_262 ( V_11 ) > 0 )
V_462 = ( F_262 ( V_11 ) >> 2 ) ;
V_463 = V_572 -> V_573 ;
} else {
return V_471 ;
}
return F_201 ( F_263 ( V_11 ) ,
V_11 -> V_569 , V_462 , V_463 ) ;
}
return V_471 | V_467 ;
}
static void F_264 ( struct V_22 * V_23 ,
struct V_431 * V_433 )
{
struct V_574 * V_575 ;
struct V_10 * V_11 ;
T_1 V_576 = V_433 -> V_437 ;
T_4 V_577 ;
unsigned long V_578 ;
T_4 V_579 ;
unsigned long V_580 ;
int V_345 ;
int V_581 ;
V_581 = ( V_576 & V_438 ) >>
V_439 ;
V_577 = V_433 -> V_20 ;
V_578 = V_433 -> V_506 ;
do {
V_11 = (struct V_10 * ) V_578 ;
V_575 = (struct V_574 * ) V_11 -> V_582 ;
V_345 = F_265 ( V_575 -> V_583 ) ;
V_579 = V_575 -> V_584 ;
V_580 = V_575 -> V_585 ;
F_138 ( V_23 , V_581 , V_577 ,
V_578 , V_345 ) ;
V_577 = V_579 ;
V_578 = V_580 ;
} while ( ! F_266 ( V_575 -> V_583 ) );
}
static int F_267 ( struct V_22 * V_23 , int V_586 ,
struct V_432 * V_360 )
{
struct V_273 * V_237 = V_23 -> V_237 ;
int V_505 ;
int V_587 = 0 ;
T_1 V_588 = 0 ;
T_1 V_589 = 0 ;
V_505 = F_180 ( V_23 , V_360 -> V_25 ) ;
if ( V_586 > V_505 )
V_586 = V_505 ;
while ( V_587 < V_586 ) {
struct V_431 * V_433 = F_184 ( V_360 ) ;
struct V_304 * V_309 ;
struct V_10 * V_11 ;
unsigned int V_306 ;
T_4 V_312 ;
T_1 V_341 , V_576 ;
int V_305 , V_590 , V_236 ;
void * V_4 ;
V_587 ++ ;
V_576 = V_433 -> V_437 ;
V_590 = V_433 -> V_18 - V_198 ;
V_312 = V_433 -> V_20 ;
V_4 = ( void * ) ( V_591 ) V_433 -> V_506 ;
V_341 = F_188 ( V_433 ) ;
V_305 = F_135 ( V_341 ) ;
V_309 = & V_23 -> V_2 -> V_327 [ V_305 ] ;
if ( V_576 & V_592 ) {
F_264 ( V_23 , V_433 ) ;
continue;
}
if ( V_576 & V_593 ) {
V_594:
V_237 -> V_595 . V_596 ++ ;
F_255 ( V_23 , V_433 ) ;
F_139 ( V_23 , V_341 , V_433 -> V_20 ,
V_433 -> V_506 ) ;
continue;
}
if ( V_309 -> V_306 > V_307 )
V_306 = 0 ;
else
V_306 = V_309 -> V_306 ;
V_11 = F_268 ( V_4 , V_306 ) ;
if ( ! V_11 ) {
F_178 ( V_23 -> V_237 , L_17 ) ;
goto V_594;
}
V_236 = F_257 ( V_23 , V_309 , V_341 ) ;
if ( V_236 ) {
F_142 ( V_23 -> V_237 , L_18 ) ;
goto V_594;
}
F_119 ( V_237 -> V_237 . V_339 , V_312 ,
V_309 -> V_318 , V_323 ) ;
V_588 ++ ;
V_589 += V_590 ;
F_269 ( V_11 , V_198 + V_504 ) ;
F_270 ( V_11 , V_590 ) ;
V_11 -> V_569 = F_271 ( V_11 , V_237 ) ;
F_256 ( V_23 , V_576 , V_11 ) ;
F_272 ( & V_23 -> V_526 , V_11 ) ;
}
if ( V_588 ) {
struct V_597 * V_595 = F_223 ( V_23 -> V_595 ) ;
F_273 ( & V_595 -> V_598 ) ;
V_595 -> V_599 += V_588 ;
V_595 -> V_590 += V_589 ;
F_274 ( & V_595 -> V_598 ) ;
}
F_275 () ;
F_182 ( V_23 , V_360 -> V_25 , V_587 , V_587 ) ;
return V_586 ;
}
static inline void
F_276 ( struct V_320 * V_237 , struct V_417 * V_26 ,
struct V_12 * V_507 )
{
F_119 ( V_237 , V_507 -> V_20 ,
V_507 -> V_18 , V_489 ) ;
F_200 ( V_26 ) ;
}
static int F_277 ( struct V_22 * V_23 , struct V_10 * V_11 ,
struct V_417 * V_446 ,
struct V_417 * V_26 )
{
struct V_6 * V_7 = F_223 ( V_26 -> V_457 ) ;
struct V_12 * V_13 ;
int V_30 ;
T_4 V_20 ;
for ( V_30 = 0 ; V_30 < F_278 ( V_11 ) -> V_600 ; V_30 ++ ) {
T_9 * V_601 = & F_278 ( V_11 ) -> V_602 [ V_30 ] ;
void * V_603 = F_279 ( V_601 -> V_604 . V_605 ) + V_601 -> V_606 ;
V_13 = F_191 ( V_446 ) ;
V_13 -> V_607 = V_26 -> V_25 ;
V_13 -> V_18 = V_601 -> V_9 ;
V_20 = F_130 ( V_23 -> V_237 -> V_237 . V_339 , V_603 ,
V_13 -> V_18 ,
V_489 ) ;
if ( F_133 ( V_23 -> V_237 -> V_237 . V_339 , V_20 ) ) {
F_200 ( V_26 ) ;
goto error;
}
V_13 -> V_21 = V_20 & V_608 ;
V_13 -> V_20 = V_20 & ( ~ V_608 ) ;
if ( V_30 == ( F_278 ( V_11 ) -> V_600 - 1 ) ) {
V_13 -> V_464 = V_609 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_13 -> V_464 = 0 ;
F_6 ( V_7 , NULL , V_13 ) ;
}
}
return 0 ;
error:
for ( V_30 = V_30 - 1 ; V_30 >= 0 ; V_30 -- ) {
V_13 = V_26 -> V_419 + V_30 ;
F_276 ( V_23 -> V_237 -> V_237 . V_339 , V_26 , V_13 ) ;
}
return - V_152 ;
}
static int F_280 ( struct V_10 * V_11 , struct V_273 * V_237 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
struct V_417 * V_26 , * V_446 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
T_4 V_20 ;
int V_602 = 0 ;
T_2 V_610 ;
T_1 V_611 ;
V_610 = F_281 ( V_11 ) ;
V_26 = V_23 -> V_418 [ V_610 ] ;
V_7 = F_223 ( V_26 -> V_457 ) ;
V_446 = & V_23 -> V_2 -> V_612 [ F_189 () ] ;
V_602 = F_278 ( V_11 ) -> V_600 + 1 ;
if ( F_193 ( V_23 -> V_2 , V_446 , V_602 ) ||
F_196 ( V_23 -> V_2 , V_26 ,
V_7 , V_602 ) ) {
V_602 = 0 ;
goto V_613;
}
V_13 = F_191 ( V_446 ) ;
V_13 -> V_607 = V_26 -> V_25 ;
V_13 -> V_18 = F_282 ( V_11 ) ;
V_20 = F_130 ( V_237 -> V_237 . V_339 , V_11 -> V_4 ,
V_13 -> V_18 , V_489 ) ;
if ( F_132 ( F_133 ( V_237 -> V_237 . V_339 , V_20 ) ) ) {
F_200 ( V_26 ) ;
V_602 = 0 ;
goto V_613;
}
V_13 -> V_21 = V_20 & V_608 ;
V_13 -> V_20 = V_20 & ~ V_608 ;
V_611 = F_258 ( V_23 , V_11 ) ;
if ( V_602 == 1 ) {
V_611 |= V_614 | V_609 ;
V_13 -> V_464 = V_611 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_611 |= V_614 | V_615 ;
V_13 -> V_464 = V_611 ;
F_6 ( V_7 , NULL , V_13 ) ;
if ( F_277 ( V_23 , V_11 , V_446 , V_26 ) ) {
F_276 ( V_23 -> V_237 -> V_237 . V_339 , V_26 , V_13 ) ;
V_602 = 0 ;
goto V_613;
}
}
V_7 -> V_455 -= V_602 ;
V_7 -> V_447 += V_602 ;
V_446 -> V_447 += V_602 ;
F_275 () ;
F_192 ( V_23 , V_602 ) ;
if ( V_7 -> V_9 - V_7 -> V_447 < V_495 + 1 ) {
struct V_491 * V_492 = F_219 ( V_237 , V_610 ) ;
F_283 ( V_492 ) ;
}
V_613:
if ( V_602 > 0 ) {
struct V_597 * V_595 = F_223 ( V_23 -> V_595 ) ;
F_273 ( & V_595 -> V_598 ) ;
V_595 -> V_616 ++ ;
V_595 -> V_617 += V_11 -> V_268 ;
F_274 ( & V_595 -> V_598 ) ;
} else {
V_237 -> V_595 . V_618 ++ ;
F_214 ( V_11 ) ;
}
if ( V_7 -> V_447 >= V_26 -> V_619 )
F_218 ( V_23 , V_26 , V_7 ) ;
if ( V_7 -> V_447 <= V_602 && V_7 -> V_447 > 0 ) {
struct V_542 * V_543 = F_223 ( V_23 -> V_457 ) ;
F_248 ( V_543 ) ;
}
return V_620 ;
}
static inline void F_284 ( struct V_273 * V_237 , int V_490 )
{
if ( V_490 & V_621 )
F_142 ( V_237 , L_19 ) ;
if ( V_490 & V_622 )
F_142 ( V_237 , L_20 ) ;
if ( V_490 & V_623 )
F_142 ( V_237 , L_21 ) ;
}
static int F_285 ( struct V_624 * V_526 , int V_625 )
{
T_1 V_626 , V_627 , V_628 ;
int V_587 = 0 ;
struct V_22 * V_23 = F_86 ( V_526 -> V_237 ) ;
V_626 = F_3 ( V_23 -> V_2 ,
F_286 ( V_23 -> V_25 ) ) ;
V_626 &= ~ V_629 ;
V_628 = V_626 & V_372 ;
if ( V_628 ) {
F_284 ( V_23 -> V_237 , V_628 ) ;
F_1 ( V_23 -> V_2 , V_630 , 0 ) ;
F_1 ( V_23 -> V_2 , F_286 ( V_23 -> V_25 ) ,
V_626 & ~ V_372 ) ;
}
V_627 = V_626 & V_373 ;
V_627 |= V_23 -> V_631 ;
while ( V_627 && V_625 > 0 ) {
int V_447 ;
struct V_432 * V_360 ;
V_360 = F_215 ( V_23 , V_627 ) ;
if ( ! V_360 )
break;
V_447 = F_267 ( V_23 , V_625 , V_360 ) ;
V_587 += V_447 ;
V_625 -= V_447 ;
if ( V_625 > 0 ) {
V_627 &= ~ ( 1 << V_360 -> V_632 ) ;
}
}
if ( V_625 > 0 ) {
V_627 = 0 ;
F_287 ( V_526 , V_587 ) ;
F_151 ( V_23 ) ;
}
V_23 -> V_631 = V_627 ;
return V_587 ;
}
static void F_288 ( struct V_22 * V_23 )
{
struct V_273 * V_633 = V_23 -> V_237 ;
F_167 ( V_23 ) ;
F_205 ( V_23 ) ;
F_289 ( & V_23 -> V_526 ) ;
F_151 ( V_23 ) ;
F_162 ( V_23 ) ;
F_290 ( V_633 -> V_529 ) ;
F_291 ( V_23 -> V_237 ) ;
}
static void F_292 ( struct V_22 * V_23 )
{
struct V_273 * V_633 = V_23 -> V_237 ;
F_175 ( V_23 ) ;
F_179 ( 10 ) ;
F_155 ( V_23 ) ;
F_293 ( & V_23 -> V_526 ) ;
F_294 ( V_23 -> V_237 ) ;
F_295 ( V_23 -> V_237 ) ;
F_177 ( V_23 ) ;
F_163 ( V_23 ) ;
F_296 ( V_633 -> V_529 ) ;
}
static int F_297 ( struct V_273 * V_237 ,
struct V_634 * V_635 )
{
T_2 V_636 = V_635 -> V_637 ;
T_2 V_638 = V_635 -> V_639 ;
if ( V_635 -> V_637 == 0 || V_635 -> V_639 == 0 )
return - V_33 ;
if ( V_635 -> V_637 > V_640 )
V_636 = V_640 ;
else if ( ! F_108 ( V_635 -> V_637 , 16 ) )
V_636 = F_115 ( V_635 -> V_637 , 16 ) ;
if ( V_635 -> V_639 > V_641 )
V_638 = V_641 ;
else if ( ! F_108 ( V_635 -> V_639 , 32 ) )
V_638 = F_115 ( V_635 -> V_639 , 32 ) ;
if ( V_635 -> V_637 != V_636 ) {
F_298 ( V_237 , L_22 ,
V_635 -> V_637 , V_636 ) ;
V_635 -> V_637 = V_636 ;
}
if ( V_635 -> V_639 != V_638 ) {
F_298 ( V_237 , L_23 ,
V_635 -> V_639 , V_638 ) ;
V_635 -> V_639 = V_638 ;
}
return 0 ;
}
static void F_299 ( struct V_22 * V_23 , unsigned char * V_603 )
{
T_1 V_642 , V_643 , V_644 ;
V_642 = F_4 ( V_23 -> V_5 + V_386 ) ;
V_643 = F_4 ( V_23 -> V_2 -> V_645 + V_646 ) ;
V_644 = F_4 ( V_23 -> V_2 -> V_645 + V_647 ) ;
V_603 [ 0 ] = ( V_644 >> 24 ) & 0xFF ;
V_603 [ 1 ] = ( V_644 >> 16 ) & 0xFF ;
V_603 [ 2 ] = ( V_644 >> 8 ) & 0xFF ;
V_603 [ 3 ] = V_644 & 0xFF ;
V_603 [ 4 ] = V_643 & 0xFF ;
V_603 [ 5 ] = ( V_642 >> V_648 ) & 0xFF ;
}
static int F_300 ( struct V_22 * V_23 )
{
struct V_528 * V_649 ;
V_649 = F_301 ( V_23 -> V_237 , V_23 -> V_650 , F_246 , 0 ,
V_23 -> V_375 ) ;
if ( ! V_649 ) {
F_142 ( V_23 -> V_237 , L_24 ) ;
return - V_651 ;
}
V_649 -> V_652 &= V_653 ;
V_649 -> V_654 = V_649 -> V_652 ;
V_23 -> V_531 = 0 ;
V_23 -> V_532 = 0 ;
V_23 -> V_388 = 0 ;
return 0 ;
}
static void F_302 ( struct V_22 * V_23 )
{
struct V_273 * V_633 = V_23 -> V_237 ;
F_303 ( V_633 -> V_529 ) ;
}
static int F_304 ( struct V_273 * V_237 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
unsigned char V_655 [ V_115 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_236 ;
V_236 = F_82 ( V_23 -> V_2 , V_23 -> V_25 , V_655 , true ) ;
if ( V_236 ) {
F_142 ( V_237 , L_25 ) ;
return V_236 ;
}
V_236 = F_82 ( V_23 -> V_2 , V_23 -> V_25 ,
V_237 -> V_274 , true ) ;
if ( V_236 ) {
F_142 ( V_237 , L_26 ) ;
return V_236 ;
}
V_236 = F_89 ( V_23 -> V_2 , V_23 -> V_25 , V_278 ) ;
if ( V_236 ) {
F_142 ( V_237 , L_27 ) ;
return V_236 ;
}
V_236 = F_90 ( V_23 ) ;
if ( V_236 ) {
F_142 ( V_237 , L_28 ) ;
return V_236 ;
}
V_236 = F_242 ( V_23 ) ;
if ( V_236 ) {
F_142 ( V_23 -> V_237 , L_29 ) ;
return V_236 ;
}
V_236 = F_243 ( V_23 ) ;
if ( V_236 ) {
F_142 ( V_23 -> V_237 , L_30 ) ;
goto V_656;
}
V_236 = F_305 ( V_23 -> V_524 , F_244 , 0 , V_237 -> V_657 , V_23 ) ;
if ( V_236 ) {
F_142 ( V_23 -> V_237 , L_31 , V_23 -> V_524 ) ;
goto V_658;
}
F_294 ( V_23 -> V_237 ) ;
V_236 = F_300 ( V_23 ) ;
if ( V_236 < 0 )
goto V_659;
F_240 ( F_159 , V_23 , 1 ) ;
F_288 ( V_23 ) ;
return 0 ;
V_659:
F_306 ( V_23 -> V_524 , V_23 ) ;
V_658:
F_238 ( V_23 ) ;
V_656:
F_241 ( V_23 ) ;
return V_236 ;
}
static int F_307 ( struct V_273 * V_237 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
struct V_542 * V_543 ;
int V_369 ;
F_292 ( V_23 ) ;
F_302 ( V_23 ) ;
F_240 ( F_157 , V_23 , 1 ) ;
F_306 ( V_23 -> V_524 , V_23 ) ;
F_152 (cpu) {
V_543 = F_197 ( V_23 -> V_457 , V_369 ) ;
F_308 ( & V_543 -> V_547 ) ;
V_543 -> V_545 = false ;
F_309 ( & V_543 -> V_552 ) ;
}
F_241 ( V_23 ) ;
F_238 ( V_23 ) ;
return 0 ;
}
static void F_310 ( struct V_273 * V_237 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_660 * V_661 ;
int V_25 = V_23 -> V_25 ;
bool V_662 = V_237 -> V_397 & V_663 ;
F_46 ( V_2 , V_25 , V_237 -> V_397 & V_664 ) ;
F_47 ( V_2 , V_25 , V_118 , V_662 ) ;
F_47 ( V_2 , V_25 , V_200 , V_662 ) ;
F_88 ( V_2 , V_25 ) ;
if ( V_662 && ! F_311 ( V_237 ) ) {
F_312 (ha, dev)
F_82 ( V_2 , V_25 , V_661 -> V_603 , true ) ;
}
}
static int F_313 ( struct V_273 * V_237 , void * V_605 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
const struct V_665 * V_603 = V_605 ;
int V_236 ;
if ( ! F_314 ( V_603 -> V_666 ) ) {
V_236 = - V_667 ;
goto error;
}
if ( ! F_251 ( V_237 ) ) {
V_236 = F_85 ( V_237 , V_603 -> V_666 ) ;
if ( ! V_236 )
return 0 ;
V_236 = F_85 ( V_237 , V_237 -> V_274 ) ;
if ( V_236 )
goto error;
}
F_292 ( V_23 ) ;
V_236 = F_85 ( V_237 , V_603 -> V_666 ) ;
if ( ! V_236 )
goto V_668;
V_236 = F_85 ( V_237 , V_237 -> V_274 ) ;
if ( V_236 )
goto error;
V_668:
F_288 ( V_23 ) ;
F_176 ( V_23 ) ;
F_174 ( V_23 ) ;
return 0 ;
error:
F_142 ( V_237 , L_32 ) ;
return V_236 ;
}
static int F_315 ( struct V_273 * V_237 , int V_366 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
int V_236 ;
if ( ! F_108 ( F_149 ( V_366 ) , 8 ) ) {
F_298 ( V_237 , L_33 , V_366 ,
F_115 ( F_149 ( V_366 ) , 8 ) ) ;
V_366 = F_115 ( F_149 ( V_366 ) , 8 ) ;
}
if ( ! F_251 ( V_237 ) ) {
V_236 = F_148 ( V_237 , V_366 ) ;
if ( ! V_236 ) {
V_23 -> V_316 = F_149 ( V_366 ) ;
return 0 ;
}
V_236 = F_148 ( V_237 , V_237 -> V_366 ) ;
if ( V_236 )
goto error;
}
F_292 ( V_23 ) ;
V_236 = F_148 ( V_237 , V_366 ) ;
if ( ! V_236 ) {
V_23 -> V_316 = F_149 ( V_366 ) ;
goto V_668;
}
V_236 = F_148 ( V_237 , V_237 -> V_366 ) ;
if ( V_236 )
goto error;
V_668:
F_288 ( V_23 ) ;
F_176 ( V_23 ) ;
F_174 ( V_23 ) ;
return 0 ;
error:
F_142 ( V_237 , L_34 ) ;
return V_236 ;
}
static void
F_316 ( struct V_273 * V_237 , struct V_669 * V_595 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
unsigned int V_105 ;
int V_369 ;
F_317 (cpu) {
struct V_597 * V_670 ;
T_6 V_599 ;
T_6 V_590 ;
T_6 V_616 ;
T_6 V_617 ;
V_670 = F_197 ( V_23 -> V_595 , V_369 ) ;
do {
V_105 = F_318 ( & V_670 -> V_598 ) ;
V_599 = V_670 -> V_599 ;
V_590 = V_670 -> V_590 ;
V_616 = V_670 -> V_616 ;
V_617 = V_670 -> V_617 ;
} while ( F_319 ( & V_670 -> V_598 , V_105 ) );
V_595 -> V_599 += V_599 ;
V_595 -> V_590 += V_590 ;
V_595 -> V_616 += V_616 ;
V_595 -> V_617 += V_617 ;
}
V_595 -> V_596 = V_237 -> V_595 . V_596 ;
V_595 -> V_671 = V_237 -> V_595 . V_671 ;
V_595 -> V_618 = V_237 -> V_595 . V_618 ;
}
static int F_320 ( struct V_273 * V_237 , struct V_672 * V_673 , int V_674 )
{
int V_151 ;
if ( ! V_237 -> V_529 )
return - V_675 ;
V_151 = F_321 ( V_237 -> V_529 , V_673 , V_674 ) ;
if ( ! V_151 )
F_246 ( V_237 ) ;
return V_151 ;
}
static int F_322 ( struct V_273 * V_237 ,
struct V_676 * V_677 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
int V_395 ;
for ( V_395 = 0 ; V_395 < V_362 ; V_395 ++ ) {
struct V_432 * V_360 = V_23 -> V_332 [ V_395 ] ;
V_360 -> V_487 = V_677 -> V_678 ;
V_360 -> V_477 = V_677 -> V_679 ;
F_207 ( V_23 , V_360 ) ;
F_211 ( V_23 , V_360 ) ;
}
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
struct V_417 * V_26 = V_23 -> V_418 [ V_395 ] ;
V_26 -> V_619 = V_677 -> V_680 ;
}
return 0 ;
}
static int F_323 ( struct V_273 * V_237 ,
struct V_676 * V_677 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
V_677 -> V_678 = V_23 -> V_332 [ 0 ] -> V_487 ;
V_677 -> V_679 = V_23 -> V_332 [ 0 ] -> V_477 ;
V_677 -> V_680 = V_23 -> V_418 [ 0 ] -> V_619 ;
return 0 ;
}
static void F_324 ( struct V_273 * V_237 ,
struct V_681 * V_682 )
{
F_325 ( V_682 -> V_683 , V_684 ,
sizeof( V_682 -> V_683 ) ) ;
F_325 ( V_682 -> V_685 , V_686 ,
sizeof( V_682 -> V_685 ) ) ;
F_325 ( V_682 -> V_687 , F_326 ( & V_237 -> V_237 ) ,
sizeof( V_682 -> V_687 ) ) ;
}
static void F_327 ( struct V_273 * V_237 ,
struct V_634 * V_635 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
V_635 -> V_688 = V_640 ;
V_635 -> V_689 = V_641 ;
V_635 -> V_637 = V_23 -> V_500 ;
V_635 -> V_639 = V_23 -> V_509 ;
}
static int F_328 ( struct V_273 * V_237 ,
struct V_634 * V_635 )
{
struct V_22 * V_23 = F_86 ( V_237 ) ;
T_2 V_690 = V_23 -> V_500 ;
T_2 V_691 = V_23 -> V_509 ;
int V_236 ;
V_236 = F_297 ( V_237 , V_635 ) ;
if ( V_236 )
return V_236 ;
if ( ! F_251 ( V_237 ) ) {
V_23 -> V_500 = V_635 -> V_637 ;
V_23 -> V_509 = V_635 -> V_639 ;
return 0 ;
}
F_292 ( V_23 ) ;
F_241 ( V_23 ) ;
F_238 ( V_23 ) ;
V_23 -> V_500 = V_635 -> V_637 ;
V_23 -> V_509 = V_635 -> V_639 ;
V_236 = F_242 ( V_23 ) ;
if ( V_236 ) {
V_23 -> V_500 = V_690 ;
V_635 -> V_637 = V_690 ;
V_236 = F_242 ( V_23 ) ;
if ( V_236 )
goto V_692;
}
V_236 = F_243 ( V_23 ) ;
if ( V_236 ) {
V_23 -> V_509 = V_691 ;
V_635 -> V_639 = V_691 ;
V_236 = F_243 ( V_23 ) ;
if ( V_236 )
goto V_693;
}
F_288 ( V_23 ) ;
F_176 ( V_23 ) ;
F_174 ( V_23 ) ;
return 0 ;
V_693:
F_241 ( V_23 ) ;
V_692:
F_142 ( V_237 , L_35 ) ;
return V_236 ;
}
static void F_329 ( struct V_22 * V_23 )
{
F_160 ( V_23 ) ;
F_164 ( V_23 ) ;
F_161 ( V_23 ) ;
F_166 ( V_23 ) ;
}
static int F_330 ( struct V_22 * V_23 )
{
struct V_320 * V_237 = V_23 -> V_237 -> V_237 . V_339 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_6 * V_7 ;
int V_395 , V_369 , V_236 ;
if ( V_23 -> V_299 + V_362 > V_694 )
return - V_33 ;
F_177 ( V_23 ) ;
F_163 ( V_23 ) ;
V_23 -> V_418 = F_75 ( V_237 , V_416 , sizeof( * V_23 -> V_418 ) ,
V_102 ) ;
if ( ! V_23 -> V_418 )
return - V_152 ;
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
int V_695 = F_8 ( V_23 -> V_25 , V_395 ) ;
struct V_417 * V_26 ;
V_26 = F_331 ( V_237 , sizeof( * V_26 ) , V_102 ) ;
if ( ! V_26 ) {
V_236 = - V_152 ;
goto V_696;
}
V_26 -> V_457 = F_332 ( struct V_6 ) ;
if ( ! V_26 -> V_457 ) {
V_236 = - V_152 ;
goto V_696;
}
V_26 -> V_25 = V_695 ;
V_26 -> V_493 = V_395 ;
V_26 -> V_619 = V_697 ;
F_152 (cpu) {
V_7 = F_197 ( V_26 -> V_457 , V_369 ) ;
V_7 -> V_369 = V_369 ;
}
V_23 -> V_418 [ V_395 ] = V_26 ;
}
V_23 -> V_332 = F_75 ( V_237 , V_362 , sizeof( * V_23 -> V_332 ) ,
V_102 ) ;
if ( ! V_23 -> V_332 ) {
V_236 = - V_152 ;
goto V_696;
}
for ( V_395 = 0 ; V_395 < V_362 ; V_395 ++ ) {
struct V_432 * V_360 ;
V_360 = F_331 ( V_237 , sizeof( * V_360 ) , V_102 ) ;
if ( ! V_360 ) {
V_236 = - V_152 ;
goto V_696;
}
V_360 -> V_25 = V_23 -> V_299 + V_395 ;
V_360 -> V_23 = V_23 -> V_25 ;
V_360 -> V_632 = V_395 ;
V_23 -> V_332 [ V_395 ] = V_360 ;
}
F_1 ( V_2 , F_333 ( V_23 -> V_25 ) , V_362 ) ;
for ( V_395 = 0 ; V_395 < V_362 ; V_395 ++ ) {
struct V_432 * V_360 = V_23 -> V_332 [ V_395 ] ;
V_360 -> V_9 = V_23 -> V_500 ;
V_360 -> V_477 = V_698 ;
V_360 -> V_487 = V_699 ;
}
F_175 ( V_23 ) ;
F_168 ( V_23 ) ;
F_96 ( V_23 ) ;
F_94 ( V_23 ) ;
V_23 -> V_316 = F_149 ( V_23 -> V_237 -> V_366 ) ;
V_236 = F_146 ( V_23 ) ;
if ( V_236 )
goto V_696;
return 0 ;
V_696:
for ( V_395 = 0 ; V_395 < V_416 ; V_395 ++ ) {
if ( ! V_23 -> V_418 [ V_395 ] )
continue;
F_334 ( V_23 -> V_418 [ V_395 ] -> V_457 ) ;
}
return V_236 ;
}
static int F_335 ( struct V_234 * V_235 ,
struct V_700 * V_701 ,
struct V_1 * V_2 ,
int * V_702 )
{
struct V_700 * V_650 ;
struct V_22 * V_23 ;
struct V_542 * V_543 ;
struct V_273 * V_237 ;
struct V_703 * V_704 ;
const char * V_705 ;
const char * V_706 ;
char V_707 [ V_115 ] ;
T_1 V_25 ;
int V_708 ;
int V_709 ;
int V_710 = 2 ;
int V_236 , V_30 , V_369 ;
V_237 = F_336 ( sizeof( struct V_22 ) , V_416 ,
V_362 ) ;
if ( ! V_237 )
return - V_152 ;
V_650 = F_337 ( V_701 , L_36 , 0 ) ;
if ( ! V_650 ) {
F_110 ( & V_235 -> V_237 , L_37 ) ;
V_236 = - V_651 ;
goto V_711;
}
V_709 = F_338 ( V_701 ) ;
if ( V_709 < 0 ) {
F_110 ( & V_235 -> V_237 , L_38 ) ;
V_236 = V_709 ;
goto V_711;
}
if ( F_339 ( V_701 , L_39 , & V_25 ) ) {
V_236 = - V_33 ;
F_110 ( & V_235 -> V_237 , L_40 ) ;
goto V_711;
}
V_237 -> V_712 = V_641 ;
V_237 -> V_713 = 5 * V_714 ;
V_237 -> V_715 = & V_716 ;
V_237 -> V_717 = & V_718 ;
V_23 = F_86 ( V_237 ) ;
V_23 -> V_524 = F_340 ( V_701 , 0 ) ;
if ( V_23 -> V_524 <= 0 ) {
V_236 = - V_33 ;
goto V_711;
}
if ( F_341 ( V_701 , L_41 ) )
V_23 -> V_397 |= V_398 ;
V_23 -> V_2 = V_2 ;
V_23 -> V_25 = V_25 ;
V_23 -> V_299 = * V_702 ;
V_23 -> V_650 = V_650 ;
V_23 -> V_375 = V_709 ;
V_704 = F_342 ( V_235 , V_719 ,
V_710 + V_25 ) ;
V_23 -> V_5 = F_343 ( & V_235 -> V_237 , V_704 ) ;
if ( F_344 ( V_23 -> V_5 ) ) {
V_236 = F_345 ( V_23 -> V_5 ) ;
goto V_659;
}
V_23 -> V_595 = F_346 ( struct V_597 ) ;
if ( ! V_23 -> V_595 ) {
V_236 = - V_152 ;
goto V_659;
}
V_705 = F_347 ( V_701 ) ;
if ( V_705 && F_314 ( V_705 ) ) {
V_706 = L_42 ;
F_87 ( V_237 -> V_274 , V_705 ) ;
} else {
F_299 ( V_23 , V_707 ) ;
if ( F_314 ( V_707 ) ) {
V_706 = L_43 ;
F_87 ( V_237 -> V_274 , V_707 ) ;
} else {
V_706 = L_44 ;
F_348 ( V_237 ) ;
}
}
V_23 -> V_509 = V_641 ;
V_23 -> V_500 = V_640 ;
V_23 -> V_237 = V_237 ;
F_349 ( V_237 , & V_235 -> V_237 ) ;
V_236 = F_330 ( V_23 ) ;
if ( V_236 < 0 ) {
F_110 ( & V_235 -> V_237 , L_45 , V_25 ) ;
goto V_720;
}
F_329 ( V_23 ) ;
V_23 -> V_457 = F_332 ( struct V_542 ) ;
if ( ! V_23 -> V_457 ) {
V_236 = - V_152 ;
goto V_721;
}
F_152 (cpu) {
V_543 = F_197 ( V_23 -> V_457 , V_369 ) ;
F_350 ( & V_543 -> V_547 , V_722 ,
V_548 ) ;
V_543 -> V_547 . V_723 = F_252 ;
V_543 -> V_545 = false ;
F_351 ( & V_543 -> V_552 , F_250 ,
( unsigned long ) V_237 ) ;
}
F_352 ( V_237 , & V_23 -> V_526 , F_285 , V_724 ) ;
V_708 = V_725 | V_726 ;
V_237 -> V_708 = V_708 | V_727 ;
V_237 -> V_728 |= V_708 | V_727 | V_729 ;
V_237 -> V_730 |= V_708 ;
V_237 -> V_731 = V_732 ;
V_237 -> V_733 = 9676 ;
V_236 = F_353 ( V_237 ) ;
if ( V_236 < 0 ) {
F_110 ( & V_235 -> V_237 , L_46 ) ;
goto V_734;
}
F_298 ( V_237 , L_47 , V_706 , V_237 -> V_274 ) ;
* V_702 += V_362 ;
V_2 -> V_735 [ V_25 ] = V_23 ;
return 0 ;
V_734:
F_334 ( V_23 -> V_457 ) ;
V_721:
for ( V_30 = 0 ; V_30 < V_416 ; V_30 ++ )
F_334 ( V_23 -> V_418 [ V_30 ] -> V_457 ) ;
V_720:
F_334 ( V_23 -> V_595 ) ;
V_659:
F_354 ( V_23 -> V_524 ) ;
V_711:
F_355 ( V_650 ) ;
F_356 ( V_237 ) ;
return V_236 ;
}
static void F_357 ( struct V_22 * V_23 )
{
int V_30 ;
F_358 ( V_23 -> V_237 ) ;
F_355 ( V_23 -> V_650 ) ;
F_334 ( V_23 -> V_457 ) ;
F_334 ( V_23 -> V_595 ) ;
for ( V_30 = 0 ; V_30 < V_416 ; V_30 ++ )
F_334 ( V_23 -> V_418 [ V_30 ] -> V_457 ) ;
F_354 ( V_23 -> V_524 ) ;
F_356 ( V_23 -> V_237 ) ;
}
static void F_359 ( const struct V_736 * V_737 ,
struct V_1 * V_2 )
{
T_1 V_738 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ ) {
F_1 ( V_2 , F_360 ( V_30 ) , 0 ) ;
F_1 ( V_2 , F_361 ( V_30 ) , 0 ) ;
if ( V_30 < 4 )
F_1 ( V_2 , F_362 ( V_30 ) , 0 ) ;
}
V_738 = 0 ;
for ( V_30 = 0 ; V_30 < V_737 -> V_739 ; V_30 ++ ) {
const struct V_740 * V_741 = V_737 -> V_741 + V_30 ;
F_1 ( V_2 , F_360 ( V_30 ) ,
( V_741 -> V_5 & 0xffff0000 ) | ( V_741 -> V_742 << 8 ) |
V_737 -> V_743 ) ;
F_1 ( V_2 , F_361 ( V_30 ) ,
( V_741 -> V_9 - 1 ) & 0xffff0000 ) ;
V_738 |= ( 1 << V_30 ) ;
}
F_1 ( V_2 , V_744 , V_738 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_193 ; V_23 ++ ) {
F_1 ( V_2 , F_364 ( V_23 ) ,
V_745 ) ;
F_1 ( V_2 , F_365 ( V_23 ) ,
V_746 ) ;
}
F_1 ( V_2 , V_747 ,
V_748 ) ;
F_1 ( V_2 , V_749 , 0x1 ) ;
}
static int F_366 ( struct V_234 * V_235 , struct V_1 * V_2 )
{
const struct V_736 * V_750 ;
int V_236 , V_30 ;
T_1 V_68 ;
if ( V_362 % 4 || ( V_362 > V_751 ) ||
( V_416 > V_27 ) ) {
F_110 ( & V_235 -> V_237 , L_48 ) ;
return - V_33 ;
}
V_750 = F_367 () ;
if ( V_750 )
F_359 ( V_750 , V_2 ) ;
V_68 = F_4 ( V_2 -> V_645 + V_752 ) ;
V_68 |= V_753 ;
F_2 ( V_68 , V_2 -> V_645 + V_752 ) ;
V_2 -> V_612 = F_75 ( & V_235 -> V_237 , F_199 () ,
sizeof( struct V_417 ) ,
V_102 ) ;
if ( ! V_2 -> V_612 )
return - V_152 ;
F_152 (i) {
V_2 -> V_612 [ V_30 ] . V_25 = V_30 ;
V_2 -> V_612 [ V_30 ] . V_9 = V_754 ;
V_236 = F_224 ( V_235 , & V_2 -> V_612 [ V_30 ] ,
V_754 , V_30 , V_2 ) ;
if ( V_236 < 0 )
return V_236 ;
}
F_363 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_193 ; V_30 ++ )
F_1 ( V_2 , F_333 ( V_30 ) , V_362 ) ;
F_2 ( V_755 ,
V_2 -> V_645 + V_756 ) ;
F_1 ( V_2 , V_757 , 0x1 ) ;
V_236 = F_123 ( V_235 , V_2 ) ;
if ( V_236 < 0 )
return V_236 ;
V_236 = F_79 ( V_235 , V_2 ) ;
if ( V_236 < 0 )
return V_236 ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_368 ( struct V_234 * V_235 )
{
struct V_700 * V_758 = V_235 -> V_237 . V_759 ;
struct V_700 * V_701 ;
struct V_1 * V_2 ;
struct V_703 * V_704 ;
int V_760 , V_299 ;
int V_236 ;
V_2 = F_331 ( & V_235 -> V_237 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 )
return - V_152 ;
V_704 = F_342 ( V_235 , V_719 , 0 ) ;
V_2 -> V_5 = F_343 ( & V_235 -> V_237 , V_704 ) ;
if ( F_344 ( V_2 -> V_5 ) )
return F_345 ( V_2 -> V_5 ) ;
V_704 = F_342 ( V_235 , V_719 , 1 ) ;
V_2 -> V_645 = F_343 ( & V_235 -> V_237 , V_704 ) ;
if ( F_344 ( V_2 -> V_645 ) )
return F_345 ( V_2 -> V_645 ) ;
V_2 -> V_761 = F_369 ( & V_235 -> V_237 , L_49 ) ;
if ( F_344 ( V_2 -> V_761 ) )
return F_345 ( V_2 -> V_761 ) ;
V_236 = F_370 ( V_2 -> V_761 ) ;
if ( V_236 < 0 )
return V_236 ;
V_2 -> V_762 = F_369 ( & V_235 -> V_237 , L_50 ) ;
if ( F_344 ( V_2 -> V_762 ) ) {
V_236 = F_345 ( V_2 -> V_762 ) ;
goto V_763;
}
V_236 = F_370 ( V_2 -> V_762 ) ;
if ( V_236 < 0 )
goto V_763;
V_2 -> V_404 = F_371 ( V_2 -> V_761 ) ;
V_236 = F_366 ( V_235 , V_2 ) ;
if ( V_236 < 0 ) {
F_110 ( & V_235 -> V_237 , L_51 ) ;
goto V_764;
}
V_760 = F_372 ( V_758 ) ;
if ( V_760 == 0 ) {
F_110 ( & V_235 -> V_237 , L_52 ) ;
V_236 = - V_651 ;
goto V_764;
}
V_2 -> V_735 = F_75 ( & V_235 -> V_237 , V_760 ,
sizeof( struct V_22 * ) ,
V_102 ) ;
if ( ! V_2 -> V_735 ) {
V_236 = - V_152 ;
goto V_764;
}
V_299 = 0 ;
F_373 (dn, port_node) {
V_236 = F_335 ( V_235 , V_701 , V_2 , & V_299 ) ;
if ( V_236 < 0 )
goto V_764;
}
F_374 ( V_235 , V_2 ) ;
return 0 ;
V_764:
F_375 ( V_2 -> V_762 ) ;
V_763:
F_375 ( V_2 -> V_761 ) ;
return V_236 ;
}
static int F_376 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_377 ( V_235 ) ;
struct V_700 * V_758 = V_235 -> V_237 . V_759 ;
struct V_700 * V_701 ;
int V_30 = 0 ;
F_373 (dn, port_node) {
if ( V_2 -> V_735 [ V_30 ] )
F_357 ( V_2 -> V_735 [ V_30 ] ) ;
V_30 ++ ;
}
for ( V_30 = 0 ; V_30 < V_326 ; V_30 ++ ) {
struct V_304 * V_309 = & V_2 -> V_327 [ V_30 ] ;
F_120 ( V_235 , V_2 , V_309 ) ;
}
F_152 (i) {
struct V_417 * V_446 = & V_2 -> V_612 [ V_30 ] ;
F_109 ( & V_235 -> V_237 ,
V_754 * V_498 ,
V_446 -> V_419 ,
V_446 -> V_499 ) ;
}
F_375 ( V_2 -> V_761 ) ;
F_375 ( V_2 -> V_762 ) ;
return 0 ;
}
