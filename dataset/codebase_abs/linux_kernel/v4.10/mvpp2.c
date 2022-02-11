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
V_15 -> V_19 = V_13 -> V_20 ;
V_7 -> V_17 ++ ;
if ( V_7 -> V_17 == V_7 -> V_9 )
V_7 -> V_17 = 0 ;
}
static inline int F_7 ( struct V_21 * V_22 )
{
return V_23 + V_22 -> V_24 ;
}
static inline int F_8 ( int V_22 , int V_25 )
{
return ( V_23 + V_22 ) * V_26 + V_25 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_29 ;
if ( V_28 -> V_30 > V_31 - 1 )
return - V_32 ;
V_28 -> V_33 . V_34 [ V_35 ] &= ~ V_36 ;
F_1 ( V_2 , V_37 , V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_38 ; V_29 ++ )
F_1 ( V_2 , F_10 ( V_29 ) , V_28 -> V_33 . V_34 [ V_29 ] ) ;
F_1 ( V_2 , V_39 , V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ )
F_1 ( V_2 , F_11 ( V_29 ) , V_28 -> V_41 . V_34 [ V_29 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_29 ;
if ( V_28 -> V_30 > V_31 - 1 )
return - V_32 ;
F_1 ( V_2 , V_37 , V_28 -> V_30 ) ;
V_28 -> V_33 . V_34 [ V_35 ] = F_3 ( V_2 ,
F_10 ( V_35 ) ) ;
if ( V_28 -> V_33 . V_34 [ V_35 ] & V_36 )
return V_42 ;
for ( V_29 = 0 ; V_29 < V_38 ; V_29 ++ )
V_28 -> V_33 . V_34 [ V_29 ] = F_3 ( V_2 , F_10 ( V_29 ) ) ;
F_1 ( V_2 , V_39 , V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ )
V_28 -> V_41 . V_34 [ V_29 ] = F_3 ( V_2 , F_11 ( V_29 ) ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , int V_30 )
{
F_1 ( V_2 , V_37 , V_30 ) ;
F_1 ( V_2 , F_10 ( V_35 ) ,
V_36 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_30 , int V_43 )
{
V_2 -> V_44 [ V_30 ] . V_45 = true ;
V_2 -> V_44 [ V_30 ] . V_43 = V_43 ;
}
static void F_15 ( struct V_1 * V_2 , int V_30 ,
unsigned int V_46 , unsigned int V_47 )
{
V_2 -> V_44 [ V_30 ] . V_47 = V_47 ;
V_2 -> V_44 [ V_30 ] . V_46 = V_46 ;
}
static void F_16 ( struct V_27 * V_28 , unsigned int V_43 )
{
int V_48 = F_17 ( V_49 ) ;
V_28 -> V_33 . V_50 [ V_49 ] = V_43 ;
V_28 -> V_33 . V_50 [ V_48 ] = V_51 ;
}
static void F_18 ( struct V_27 * V_28 ,
unsigned int V_22 , bool V_52 )
{
int V_48 = F_17 ( V_53 ) ;
if ( V_52 )
V_28 -> V_33 . V_50 [ V_48 ] &= ~ ( 1 << V_22 ) ;
else
V_28 -> V_33 . V_50 [ V_48 ] |= 1 << V_22 ;
}
static void F_19 ( struct V_27 * V_28 ,
unsigned int V_54 )
{
unsigned char V_55 = V_56 ;
int V_48 = F_17 ( V_53 ) ;
V_28 -> V_33 . V_50 [ V_53 ] = 0 ;
V_28 -> V_33 . V_50 [ V_48 ] &= ~ V_55 ;
V_28 -> V_33 . V_50 [ V_48 ] |= ~ V_54 & V_56 ;
}
static unsigned int F_20 ( struct V_27 * V_28 )
{
int V_48 = F_17 ( V_53 ) ;
return ~ ( V_28 -> V_33 . V_50 [ V_48 ] ) & V_56 ;
}
static void F_21 ( struct V_27 * V_28 ,
unsigned int V_57 , unsigned char V_50 ,
unsigned char V_58 )
{
V_28 -> V_33 . V_50 [ F_22 ( V_57 ) ] = V_50 ;
V_28 -> V_33 . V_50 [ F_23 ( V_57 ) ] = V_58 ;
}
static void F_24 ( struct V_27 * V_28 ,
unsigned int V_57 , unsigned char * V_50 ,
unsigned char * V_58 )
{
* V_50 = V_28 -> V_33 . V_50 [ F_22 ( V_57 ) ] ;
* V_58 = V_28 -> V_33 . V_50 [ F_23 ( V_57 ) ] ;
}
static bool F_25 ( struct V_27 * V_28 , int V_57 ,
T_2 V_4 )
{
int V_59 = F_22 ( V_57 ) ;
T_2 V_60 ;
V_60 = ( 8 << V_28 -> V_33 . V_50 [ V_59 + 1 ] ) | V_28 -> V_33 . V_50 [ V_59 ] ;
if ( V_60 != V_4 )
return false ;
return true ;
}
static void F_26 ( struct V_27 * V_28 ,
unsigned int V_61 , unsigned int V_58 )
{
int V_29 , V_62 = V_63 ;
for ( V_29 = 0 ; V_29 < V_64 ; V_29 ++ ) {
if ( ! ( V_58 & F_27 ( V_29 ) ) )
continue;
if ( V_61 & F_27 ( V_29 ) )
V_28 -> V_33 . V_50 [ V_62 ] |= 1 << V_29 ;
else
V_28 -> V_33 . V_50 [ V_62 ] &= ~ ( 1 << V_29 ) ;
}
V_28 -> V_33 . V_50 [ F_17 ( V_62 ) ] |= V_58 ;
}
static int F_28 ( struct V_27 * V_28 )
{
return V_28 -> V_33 . V_50 [ V_63 ] ;
}
static void F_29 ( struct V_27 * V_28 , int V_3 ,
unsigned short V_65 )
{
F_21 ( V_28 , V_3 + 0 , V_65 >> 8 , 0xff ) ;
F_21 ( V_28 , V_3 + 1 , V_65 & 0xff , 0xff ) ;
}
static void F_30 ( struct V_27 * V_28 , int V_66 ,
int V_67 )
{
V_28 -> V_41 . V_50 [ F_31 ( V_66 ) ] |= ( V_67 << ( V_66 % 8 ) ) ;
}
static void F_32 ( struct V_27 * V_28 , int V_66 ,
int V_67 )
{
V_28 -> V_41 . V_50 [ F_31 ( V_66 ) ] &= ~ ( V_67 << ( V_66 % 8 ) ) ;
}
static void F_33 ( struct V_27 * V_28 ,
unsigned int V_61 , unsigned int V_68 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_69 ; V_29 ++ ) {
int V_70 = V_71 ;
if ( ! ( V_68 & F_27 ( V_29 ) ) )
continue;
if ( V_61 & F_27 ( V_29 ) )
F_30 ( V_28 , V_70 + V_29 , 1 ) ;
else
F_32 ( V_28 , V_70 + V_29 , 1 ) ;
F_30 ( V_28 , V_72 + V_29 , 1 ) ;
}
}
static int F_34 ( struct V_27 * V_28 )
{
return V_28 -> V_41 . V_34 [ V_73 ] ;
}
static void F_35 ( struct V_27 * V_28 ,
unsigned int V_61 , unsigned int V_68 )
{
unsigned int V_29 ;
int V_74 = V_75 ;
for ( V_29 = 0 ; V_29 < V_76 ; V_29 ++ ) {
if ( ! ( V_68 & F_27 ( V_29 ) ) )
continue;
if ( V_61 & F_27 ( V_29 ) )
F_30 ( V_28 , V_74 + V_29 , 1 ) ;
else
F_32 ( V_28 , V_74 + V_29 , 1 ) ;
F_30 ( V_28 , V_77 + V_29 , 1 ) ;
}
}
static int F_36 ( struct V_27 * V_28 )
{
T_3 V_61 ;
int V_74 = F_31 ( V_75 ) ;
int V_78 = V_74 + 1 ;
int V_79 = V_75 % 8 ;
V_61 = ( V_28 -> V_41 . V_50 [ V_74 ] >> V_79 ) |
( V_28 -> V_41 . V_50 [ V_78 ] << ( 8 - V_79 ) ) ;
return V_61 ;
}
static void F_37 ( struct V_27 * V_28 ,
unsigned int V_43 )
{
int V_80 = V_81 ;
F_32 ( V_28 , V_80 ,
V_82 ) ;
F_30 ( V_28 , V_80 , V_43 ) ;
}
static void F_38 ( struct V_27 * V_28 , int V_83 ,
unsigned int V_84 )
{
if ( V_83 < 0 ) {
F_30 ( V_28 , V_85 , 1 ) ;
V_83 = 0 - V_83 ;
} else {
F_32 ( V_28 , V_85 , 1 ) ;
}
V_28 -> V_41 . V_50 [ F_31 ( V_86 ) ] =
( unsigned char ) V_83 ;
F_32 ( V_28 , V_87 ,
V_88 ) ;
F_30 ( V_28 , V_87 , V_84 ) ;
F_32 ( V_28 , V_89 , 1 ) ;
}
static void F_39 ( struct V_27 * V_28 ,
unsigned int type , int V_3 ,
unsigned int V_84 )
{
if ( V_3 < 0 ) {
F_30 ( V_28 , V_90 , 1 ) ;
V_3 = 0 - V_3 ;
} else {
F_32 ( V_28 , V_90 , 1 ) ;
}
F_32 ( V_28 , V_91 ,
V_92 ) ;
F_30 ( V_28 , V_91 , V_3 ) ;
V_28 -> V_41 . V_50 [ F_31 ( V_91 +
V_93 ) ] &=
~ ( V_92 >> ( 8 - ( V_91 % 8 ) ) ) ;
V_28 -> V_41 . V_50 [ F_31 ( V_91 +
V_93 ) ] |=
( V_3 >> ( 8 - ( V_91 % 8 ) ) ) ;
F_32 ( V_28 , V_94 ,
V_95 ) ;
F_30 ( V_28 , V_94 , type ) ;
F_32 ( V_28 , V_96 ,
V_97 ) ;
F_30 ( V_28 , V_96 , V_84 ) ;
V_28 -> V_41 . V_50 [ F_31 ( V_96 +
V_98 ) ] &=
~ ( V_97 >>
( 8 - ( V_96 % 8 ) ) ) ;
V_28 -> V_41 . V_50 [ F_31 ( V_96 +
V_98 ) ] |=
( V_84 >> ( 8 - ( V_96 % 8 ) ) ) ;
F_32 ( V_28 , V_89 , 1 ) ;
}
static struct V_27 * F_40 ( struct V_1 * V_2 , int V_99 )
{
struct V_27 * V_28 ;
int V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return NULL ;
F_16 ( V_28 , V_102 ) ;
for ( V_100 = V_31 - 1 ; V_100 >= 0 ; V_100 -- ) {
T_3 V_61 ;
if ( ! V_2 -> V_44 [ V_100 ] . V_45 ||
V_2 -> V_44 [ V_100 ] . V_43 != V_102 )
continue;
V_28 -> V_30 = V_100 ;
F_12 ( V_2 , V_28 ) ;
V_61 = F_36 ( V_28 ) ;
if ( ( V_61 & V_103 ) == V_99 )
return V_28 ;
}
F_42 ( V_28 ) ;
return NULL ;
}
static int F_43 ( struct V_1 * V_2 , unsigned char V_104 ,
unsigned char V_105 )
{
int V_100 ;
if ( V_104 > V_105 )
F_44 ( V_104 , V_105 ) ;
if ( V_105 >= V_31 )
V_105 = V_31 - 1 ;
for ( V_100 = V_104 ; V_100 <= V_105 ; V_100 ++ ) {
if ( ! V_2 -> V_44 [ V_100 ] . V_45 )
return V_100 ;
}
return - V_32 ;
}
static void F_45 ( struct V_1 * V_2 , int V_22 , bool V_52 )
{
struct V_27 V_28 ;
if ( V_2 -> V_44 [ V_106 ] . V_45 ) {
V_28 . V_30 = V_106 ;
F_12 ( V_2 , & V_28 ) ;
} else {
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_107 ) ;
V_28 . V_30 = V_106 ;
F_33 ( & V_28 , V_108 ,
V_108 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_37 ( & V_28 , V_102 ) ;
F_14 ( V_2 , V_28 . V_30 , V_107 ) ;
F_19 ( & V_28 , 0 ) ;
}
F_18 ( & V_28 , V_22 , V_52 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static void F_46 ( struct V_1 * V_2 , int V_22 , bool V_52 )
{
struct V_27 V_28 ;
if ( V_2 -> V_44 [ V_110 ] . V_45 ) {
V_28 . V_30 = V_110 ;
F_12 ( V_2 , & V_28 ) ;
} else {
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_107 ) ;
V_28 . V_30 = V_110 ;
F_37 ( & V_28 , V_111 ) ;
F_33 ( & V_28 , V_112 ,
V_113 ) ;
F_38 ( & V_28 , 2 * V_114 ,
V_115 ) ;
F_19 ( & V_28 , 0 ) ;
F_14 ( V_2 , V_28 . V_30 , V_107 ) ;
}
F_18 ( & V_28 , V_22 , V_52 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_22 , int V_30 ,
bool V_52 )
{
struct V_27 V_28 ;
unsigned char V_116 ;
V_116 = ( V_30 == V_117 ) ? 0x01 : 0x33 ;
if ( V_2 -> V_44 [ V_30 ] . V_45 ) {
V_28 . V_30 = V_30 ;
F_12 ( V_2 , & V_28 ) ;
} else {
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_107 ) ;
V_28 . V_30 = V_30 ;
F_37 ( & V_28 , V_111 ) ;
F_33 ( & V_28 , V_118 ,
V_113 ) ;
F_21 ( & V_28 , 0 , V_116 , 0xff ) ;
F_38 ( & V_28 , 2 * V_114 ,
V_115 ) ;
F_19 ( & V_28 , 0 ) ;
F_14 ( V_2 , V_28 . V_30 , V_107 ) ;
}
F_18 ( & V_28 , V_22 , V_52 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_22 , bool V_52 ,
bool V_119 , bool V_120 )
{
struct V_27 V_28 ;
int V_100 , V_83 ;
if ( V_120 ) {
V_100 = V_119 ? V_121 : V_122 ;
V_83 = 8 ;
} else {
V_100 = V_119 ? V_123 : V_124 ;
V_83 = 4 ;
}
if ( V_2 -> V_44 [ V_100 ] . V_45 ) {
V_28 . V_30 = V_100 ;
F_12 ( V_2 , & V_28 ) ;
} else {
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_111 ) ;
V_28 . V_30 = V_100 ;
F_38 ( & V_28 , V_83 ,
V_115 ) ;
F_14 ( V_2 , V_28 . V_30 , V_111 ) ;
if ( V_119 ) {
F_21 ( & V_28 , 0 ,
V_125 ,
V_125 ) ;
F_35 ( & V_28 , 0 ,
V_126 ) ;
F_37 ( & V_28 , V_127 ) ;
} else {
F_33 ( & V_28 , V_128 ,
V_129 ) ;
F_37 ( & V_28 , V_130 ) ;
}
F_19 ( & V_28 , 0 ) ;
}
F_18 ( & V_28 , V_22 , V_52 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_22 ,
bool V_52 , bool V_119 , bool V_120 )
{
struct V_27 V_28 ;
int V_100 , V_83 , V_55 ;
if ( V_120 ) {
V_100 = V_119 ? V_131 :
V_132 ;
V_55 = 0 ;
V_83 = 8 ;
} else {
V_100 = V_119 ? V_133 :
V_134 ;
V_55 = V_56 ;
V_83 = 4 ;
}
if ( V_2 -> V_44 [ V_100 ] . V_45 ) {
V_28 . V_30 = V_100 ;
F_12 ( V_2 , & V_28 ) ;
} else {
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_111 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_135 ) ;
F_29 ( & V_28 , 2 , 0 ) ;
F_33 ( & V_28 , V_136 ,
V_136 ) ;
F_38 ( & V_28 , 2 + V_137 + V_83 ,
V_115 ) ;
F_14 ( V_2 , V_28 . V_30 , V_111 ) ;
if ( V_119 ) {
F_21 ( & V_28 ,
V_137 + 2 + 3 ,
V_125 ,
V_125 ) ;
F_35 ( & V_28 , 0 ,
V_126 ) ;
F_37 ( & V_28 , V_127 ) ;
} else {
F_33 ( & V_28 , V_128 ,
V_129 ) ;
F_37 ( & V_28 , V_130 ) ;
}
F_19 ( & V_28 , V_55 ) ;
}
F_18 ( & V_28 , V_22 , V_52 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static struct V_27 * F_50 ( struct V_1 * V_2 ,
unsigned short V_138 , int V_139 )
{
struct V_27 * V_28 ;
int V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return NULL ;
F_16 ( V_28 , V_127 ) ;
for ( V_100 = V_140 ;
V_100 <= V_141 ; V_100 ++ ) {
unsigned int V_142 , V_143 ;
bool V_144 ;
if ( ! V_2 -> V_44 [ V_100 ] . V_45 ||
V_2 -> V_44 [ V_100 ] . V_43 != V_127 )
continue;
V_28 -> V_30 = V_100 ;
F_12 ( V_2 , V_28 ) ;
V_144 = F_25 ( V_28 , 0 , F_51 ( V_138 ) ) ;
if ( ! V_144 )
continue;
V_142 = F_34 ( V_28 ) ;
V_142 &= V_129 ;
V_143 = F_28 ( V_28 ) ;
V_143 &= ~ V_145 ;
if ( V_139 != V_143 )
continue;
if ( V_142 == V_146 ||
V_142 == V_147 )
return V_28 ;
}
F_42 ( V_28 ) ;
return NULL ;
}
static int F_52 ( struct V_1 * V_2 , unsigned short V_138 , int V_139 ,
unsigned int V_148 )
{
struct V_27 * V_28 ;
int V_149 , V_100 ;
int V_150 = 0 ;
V_28 = F_50 ( V_2 , V_138 , V_139 ) ;
if ( ! V_28 ) {
V_100 = F_43 ( V_2 , V_141 ,
V_140 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return - V_151 ;
for ( V_149 = V_141 ;
V_149 >= V_140 ; V_149 -- ) {
unsigned int V_142 ;
if ( ! V_2 -> V_44 [ V_149 ] . V_45 ||
V_2 -> V_44 [ V_149 ] . V_43 != V_127 )
continue;
V_28 -> V_30 = V_149 ;
F_12 ( V_2 , V_28 ) ;
V_142 = F_34 ( V_28 ) ;
if ( ( V_142 & V_129 ) ==
V_152 )
break;
}
if ( V_100 <= V_149 ) {
V_150 = - V_32 ;
goto error;
}
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( V_28 , V_127 ) ;
V_28 -> V_30 = V_100 ;
F_29 ( V_28 , 0 , V_138 ) ;
F_37 ( V_28 , V_130 ) ;
F_38 ( V_28 , V_153 ,
V_115 ) ;
F_35 ( V_28 , 0 , V_126 ) ;
if ( V_139 == V_154 ) {
F_33 ( V_28 , V_146 ,
V_129 ) ;
} else {
V_139 |= V_145 ;
F_33 ( V_28 , V_147 ,
V_129 ) ;
}
F_26 ( V_28 , V_139 , V_126 ) ;
F_14 ( V_2 , V_28 -> V_30 , V_127 ) ;
}
F_19 ( V_28 , V_148 ) ;
F_9 ( V_2 , V_28 ) ;
error:
F_42 ( V_28 ) ;
return V_150 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_29 ;
for ( V_29 = 1 ; V_29 < V_155 ; V_29 ++ ) {
if ( ! V_2 -> V_156 [ V_29 ] )
return V_29 ;
}
return - V_32 ;
}
static struct V_27 * F_54 ( struct V_1 * V_2 ,
unsigned short V_157 ,
unsigned short V_158 )
{
struct V_27 * V_28 ;
int V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return NULL ;
F_16 ( V_28 , V_127 ) ;
for ( V_100 = V_140 ;
V_100 <= V_141 ; V_100 ++ ) {
unsigned int V_47 ;
bool V_144 ;
if ( ! V_2 -> V_44 [ V_100 ] . V_45 ||
V_2 -> V_44 [ V_100 ] . V_43 != V_127 )
continue;
V_28 -> V_30 = V_100 ;
F_12 ( V_2 , V_28 ) ;
V_144 = F_25 ( V_28 , 0 , F_51 ( V_157 ) )
&& F_25 ( V_28 , 4 , F_51 ( V_158 ) ) ;
if ( ! V_144 )
continue;
V_47 = F_34 ( V_28 ) & V_129 ;
if ( V_47 == V_152 )
return V_28 ;
}
F_42 ( V_28 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , unsigned short V_157 ,
unsigned short V_158 ,
unsigned int V_148 )
{
struct V_27 * V_28 ;
int V_149 , V_100 , V_139 , V_150 = 0 ;
V_28 = F_54 ( V_2 , V_157 , V_158 ) ;
if ( ! V_28 ) {
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return - V_151 ;
V_139 = F_53 ( V_2 ) ;
if ( V_139 < 0 ) {
V_150 = V_139 ;
goto error;
}
for ( V_149 = V_140 ;
V_149 <= V_141 ; V_149 ++ ) {
unsigned int V_142 ;
if ( ! V_2 -> V_44 [ V_149 ] . V_45 ||
V_2 -> V_44 [ V_149 ] . V_43 != V_127 )
continue;
V_28 -> V_30 = V_149 ;
F_12 ( V_2 , V_28 ) ;
V_142 = F_34 ( V_28 ) ;
V_142 &= V_129 ;
if ( V_142 == V_146 ||
V_142 == V_147 )
break;
}
if ( V_100 >= V_149 ) {
V_150 = - V_159 ;
goto error;
}
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( V_28 , V_127 ) ;
V_28 -> V_30 = V_100 ;
V_2 -> V_156 [ V_139 ] = true ;
F_29 ( V_28 , 0 , V_157 ) ;
F_29 ( V_28 , 4 , V_158 ) ;
F_37 ( V_28 , V_127 ) ;
F_38 ( V_28 , 2 * V_153 ,
V_115 ) ;
F_33 ( V_28 , V_152 ,
V_129 ) ;
F_35 ( V_28 , V_139 | V_145 ,
V_126 ) ;
F_14 ( V_2 , V_28 -> V_30 , V_127 ) ;
}
F_19 ( V_28 , V_148 ) ;
F_9 ( V_2 , V_28 ) ;
error:
F_42 ( V_28 ) ;
return V_150 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned short V_160 ,
unsigned int V_46 , unsigned int V_47 )
{
struct V_27 V_28 ;
int V_100 ;
if ( ( V_160 != V_161 ) && ( V_160 != V_162 ) &&
( V_160 != V_163 ) )
return - V_32 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_164 ) ;
V_28 . V_30 = V_100 ;
F_37 ( & V_28 , V_164 ) ;
F_38 ( & V_28 , 12 , V_115 ) ;
F_39 ( & V_28 , V_165 ,
sizeof( struct V_166 ) - 4 ,
V_167 ) ;
F_35 ( & V_28 , V_168 ,
V_168 ) ;
F_33 ( & V_28 , V_46 | V_169 ,
V_47 | V_169 ) ;
F_21 ( & V_28 , 5 , V_160 , V_170 ) ;
F_26 ( & V_28 , 0 , V_168 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 . V_30 = V_100 ;
V_28 . V_41 . V_34 [ V_73 ] = 0x0 ;
V_28 . V_41 . V_34 [ V_171 ] = 0x0 ;
F_33 ( & V_28 , V_46 , V_47 ) ;
F_21 ( & V_28 , 2 , 0x00 , V_172 ) ;
F_21 ( & V_28 , 3 , 0x00 , V_170 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned short V_173 )
{
struct V_27 V_28 ;
int V_68 , V_100 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_164 ) ;
V_28 . V_30 = V_100 ;
switch ( V_173 ) {
case V_174 :
F_21 ( & V_28 , 0 , V_175 ,
V_176 ) ;
F_33 ( & V_28 , V_177 ,
V_178 ) ;
break;
case V_179 :
V_68 = V_180 ;
F_21 ( & V_28 , 0 , V_68 , V_68 ) ;
F_21 ( & V_28 , 1 , V_68 , V_68 ) ;
F_21 ( & V_28 , 2 , V_68 , V_68 ) ;
F_21 ( & V_28 , 3 , V_68 , V_68 ) ;
F_33 ( & V_28 , V_181 ,
V_178 ) ;
break;
default:
return - V_32 ;
}
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_26 ( & V_28 , V_168 ,
V_168 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned short V_160 ,
unsigned int V_46 , unsigned int V_47 )
{
struct V_27 V_28 ;
int V_100 ;
if ( ( V_160 != V_161 ) && ( V_160 != V_162 ) &&
( V_160 != V_182 ) && ( V_160 != V_183 ) )
return - V_32 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_184 ) ;
V_28 . V_30 = V_100 ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_46 , V_47 ) ;
F_39 ( & V_28 , V_165 ,
sizeof( struct V_185 ) - 6 ,
V_167 ) ;
F_21 ( & V_28 , 0 , V_160 , V_170 ) ;
F_26 ( & V_28 , V_186 ,
V_186 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_184 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned short V_173 )
{
struct V_27 V_28 ;
int V_100 ;
if ( V_173 != V_174 )
return - V_32 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_184 ) ;
V_28 . V_30 = V_100 ;
F_37 ( & V_28 , V_184 ) ;
F_33 ( & V_28 , V_177 ,
V_178 ) ;
F_35 ( & V_28 , V_186 ,
V_186 ) ;
F_38 ( & V_28 , - 18 , V_115 ) ;
F_21 ( & V_28 , 0 , V_187 ,
V_188 ) ;
F_26 ( & V_28 , 0 , V_186 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_184 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_22 , int V_189 ,
int V_190 , int V_3 )
{
T_1 V_67 ;
V_67 = F_3 ( V_2 , V_191 ) ;
V_67 &= ~ F_61 ( V_22 ) ;
V_67 |= F_62 ( V_22 , V_189 ) ;
F_1 ( V_2 , V_191 , V_67 ) ;
V_67 = F_3 ( V_2 , F_63 ( V_22 ) ) ;
V_67 &= ~ F_64 ( V_22 ) ;
V_67 |= F_65 ( V_22 , V_190 ) ;
F_1 ( V_2 , F_63 ( V_22 ) , V_67 ) ;
V_67 = F_3 ( V_2 , F_66 ( V_22 ) ) ;
V_67 &= ~ F_67 ( V_22 ) ;
V_67 |= F_68 ( V_22 , V_3 ) ;
F_1 ( V_2 , F_66 ( V_22 ) , V_67 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_192 ; V_22 ++ ) {
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_102 ) ;
V_28 . V_30 = V_193 - V_22 ;
F_19 ( & V_28 , 0 ) ;
F_35 ( & V_28 , V_22 , V_103 ) ;
F_30 ( & V_28 , V_194 , 1 ) ;
F_14 ( V_2 , V_28 . V_30 , V_102 ) ;
F_9 ( V_2 , & V_28 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_30 = V_195 ;
F_16 ( & V_28 , V_196 ) ;
F_38 ( & V_28 , V_197 ,
V_115 ) ;
F_37 ( & V_28 , V_107 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_196 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_30 = V_198 ;
F_16 ( & V_28 , V_107 ) ;
F_33 ( & V_28 , V_108 ,
V_108 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_37 ( & V_28 , V_102 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_107 ) ;
F_9 ( V_2 , & V_28 ) ;
F_45 ( V_2 , 0 , false ) ;
F_46 ( V_2 , 0 , false ) ;
F_47 ( V_2 , V_117 , 0 , false ) ;
F_47 ( V_2 , V_199 , 0 , false ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
F_48 ( V_2 , 0 , false , V_200 ,
V_201 ) ;
F_48 ( V_2 , 0 , false , V_202 , V_201 ) ;
F_48 ( V_2 , 0 , false , V_200 ,
V_203 ) ;
F_48 ( V_2 , 0 , false , V_202 , V_203 ) ;
F_49 ( V_2 , 0 , false ,
V_200 , V_201 ) ;
F_49 ( V_2 , 0 , false ,
V_202 , V_201 ) ;
F_49 ( V_2 , 0 , true ,
V_200 , V_203 ) ;
F_49 ( V_2 , 0 , true ,
V_202 , V_203 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_111 ) ;
V_28 . V_30 = V_204 ;
F_37 ( & V_28 , V_127 ) ;
F_38 ( & V_28 , 0 , V_115 ) ;
F_14 ( V_2 , V_28 . V_30 , V_107 ) ;
F_35 ( & V_28 , 0 , V_126 ) ;
F_19 ( & V_28 , V_56 ) ;
F_9 ( V_2 , & V_28 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
int V_100 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_130 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_205 ) ;
F_38 ( & V_28 , V_206 ,
V_115 ) ;
F_37 ( & V_28 , V_207 ) ;
F_33 ( & V_28 , V_208 ,
V_208 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = false ;
F_15 ( V_2 , V_28 . V_30 , V_208 ,
V_208 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_130 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_212 ) ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_213 ,
V_214 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = true ;
F_15 ( V_2 , V_28 . V_30 , V_213 ,
V_214 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_130 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_216 ) ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_217 |
V_218 ,
V_219 |
V_220 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = true ;
F_15 ( V_2 , V_28 . V_30 , V_217 |
V_218 ,
V_219 |
V_220 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_130 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_221 ) ;
F_21 ( & V_28 , V_137 ,
V_222 | V_223 ,
V_224 |
V_225 ) ;
F_37 ( & V_28 , V_164 ) ;
F_33 ( & V_28 , V_226 ,
V_214 ) ;
F_38 ( & V_28 , V_137 + 4 ,
V_115 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = false ;
F_15 ( V_2 , V_28 . V_30 , V_226 ,
V_214 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 . V_30 = V_100 ;
V_28 . V_33 . V_50 [ F_22 ( V_137 ) ] = 0x0 ;
V_28 . V_33 . V_50 [ F_23 ( V_137 ) ] = 0x0 ;
F_21 ( & V_28 , V_137 ,
V_222 ,
V_224 ) ;
V_28 . V_41 . V_34 [ V_73 ] = 0x0 ;
V_28 . V_41 . V_34 [ V_171 ] = 0x0 ;
F_33 ( & V_28 , V_227 ,
V_214 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = false ;
F_15 ( V_2 , V_28 . V_30 , V_227 ,
V_214 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_130 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_228 ) ;
F_38 ( & V_28 , V_137 + 8 +
V_229 ,
V_115 ) ;
F_37 ( & V_28 , V_184 ) ;
F_33 ( & V_28 , V_230 ,
V_214 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = false ;
F_15 ( V_2 , V_28 . V_30 , V_230 ,
V_214 ) ;
F_9 ( V_2 , & V_28 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_130 ) ;
V_28 . V_30 = V_231 ;
F_19 ( & V_28 , V_56 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_37 ( & V_28 , V_102 ) ;
F_33 ( & V_28 , V_232 ,
V_214 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_130 ) ;
V_2 -> V_44 [ V_28 . V_30 ] . V_209 = V_210 ;
V_2 -> V_44 [ V_28 . V_30 ] . V_211 = true ;
F_15 ( V_2 , V_28 . V_30 , V_232 ,
V_214 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_74 ( struct V_233 * V_234 , struct V_1 * V_2 )
{
struct V_27 V_28 ;
int V_235 ;
V_2 -> V_156 = F_75 ( & V_234 -> V_236 , sizeof( bool ) ,
V_155 ,
V_101 ) ;
if ( ! V_2 -> V_156 )
return - V_151 ;
V_235 = F_55 ( V_2 , V_237 , V_238 ,
V_56 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_55 ( V_2 , V_237 , V_237 ,
V_56 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_52 ( V_2 , V_238 , V_154 ,
V_56 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_52 ( V_2 , V_237 , V_154 ,
V_56 ) ;
if ( V_235 )
return V_235 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_127 ) ;
V_28 . V_30 = V_239 ;
F_37 ( & V_28 , V_130 ) ;
F_35 ( & V_28 , 0 , V_126 ) ;
F_33 ( & V_28 , V_152 ,
V_129 ) ;
F_26 ( & V_28 , V_145 ,
V_145 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_127 ) ;
F_9 ( V_2 , & V_28 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_127 ) ;
V_28 . V_30 = V_240 ;
F_37 ( & V_28 , V_130 ) ;
F_33 ( & V_28 , V_128 ,
V_129 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_127 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
int V_100 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_207 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_241 ) ;
F_37 ( & V_28 , V_164 ) ;
F_33 ( & V_28 , V_227 ,
V_214 ) ;
F_38 ( & V_28 , V_137 + 4 ,
V_115 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_207 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 . V_30 = V_100 ;
F_21 ( & V_28 , V_137 ,
V_222 | V_223 ,
V_224 |
V_225 ) ;
V_28 . V_41 . V_34 [ V_73 ] = 0x0 ;
V_28 . V_41 . V_34 [ V_171 ] = 0x0 ;
F_33 ( & V_28 , V_226 ,
V_214 ) ;
F_14 ( V_2 , V_28 . V_30 , V_207 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_207 ) ;
V_28 . V_30 = V_100 ;
F_29 ( & V_28 , 0 , V_242 ) ;
F_37 ( & V_28 , V_184 ) ;
F_33 ( & V_28 , V_230 ,
V_214 ) ;
F_38 ( & V_28 , V_137 + 4 ,
V_115 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_207 ) ;
F_9 ( V_2 , & V_28 ) ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_207 ) ;
V_28 . V_30 = V_100 ;
F_33 ( & V_28 , V_232 ,
V_214 ) ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_39 ( & V_28 , V_215 ,
V_137 ,
V_167 ) ;
F_14 ( V_2 , V_28 . V_30 , V_207 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
int V_235 ;
V_235 = F_56 ( V_2 , V_161 , V_243 ,
V_244 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_56 ( V_2 , V_162 , V_245 ,
V_244 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_56 ( V_2 , V_163 ,
V_217 |
V_218 ,
V_219 |
V_220 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_57 ( V_2 , V_179 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_57 ( V_2 , V_174 ) ;
if ( V_235 )
return V_235 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_164 ) ;
V_28 . V_30 = V_246 ;
F_37 ( & V_28 , V_164 ) ;
F_38 ( & V_28 , 12 , V_115 ) ;
F_39 ( & V_28 , V_165 ,
sizeof( struct V_166 ) - 4 ,
V_167 ) ;
F_35 ( & V_28 , V_168 ,
V_168 ) ;
F_33 ( & V_28 , V_247 ,
V_244 ) ;
F_26 ( & V_28 , 0 , V_168 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_164 ) ;
V_28 . V_30 = V_248 ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_249 ,
V_178 ) ;
F_26 ( & V_28 , V_168 ,
V_168 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
int V_100 , V_235 ;
V_235 = F_58 ( V_2 , V_161 ,
V_243 ,
V_244 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_58 ( V_2 , V_162 ,
V_245 ,
V_244 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_58 ( V_2 , V_182 ,
V_217 |
V_218 ,
V_219 |
V_220 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_58 ( V_2 , V_183 ,
V_250 ,
V_251 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_59 ( V_2 , V_174 ) ;
if ( V_235 )
return V_235 ;
V_100 = F_43 ( V_2 , V_140 ,
V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_184 ) ;
V_28 . V_30 = V_100 ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_232 |
V_108 ,
V_214 |
V_108 ) ;
F_21 ( & V_28 , 1 , 0x00 , V_252 ) ;
F_26 ( & V_28 , V_186 ,
V_186 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_184 ) ;
V_28 . V_30 = V_253 ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_247 ,
V_244 ) ;
F_39 ( & V_28 , V_165 ,
sizeof( struct V_185 ) - 4 ,
V_167 ) ;
F_26 ( & V_28 , V_186 ,
V_186 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_184 ) ;
V_28 . V_30 = V_254 ;
F_37 ( & V_28 , V_102 ) ;
F_30 ( & V_28 , V_109 , 1 ) ;
F_33 ( & V_28 , V_247 ,
V_244 ) ;
F_26 ( & V_28 , V_255 ,
V_255 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_164 ) ;
F_9 ( V_2 , & V_28 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_16 ( & V_28 , V_184 ) ;
V_28 . V_30 = V_256 ;
F_37 ( & V_28 , V_184 ) ;
F_33 ( & V_28 , V_249 ,
V_178 ) ;
F_35 ( & V_28 , V_186 ,
V_186 ) ;
F_38 ( & V_28 , - 18 , V_115 ) ;
F_26 ( & V_28 , 0 , V_186 ) ;
F_19 ( & V_28 , V_56 ) ;
F_14 ( V_2 , V_28 . V_30 , V_184 ) ;
F_9 ( V_2 , & V_28 ) ;
return 0 ;
}
static int F_79 ( struct V_233 * V_234 ,
struct V_1 * V_2 )
{
int V_235 , V_30 , V_29 ;
F_1 ( V_2 , V_257 , V_258 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
F_1 ( V_2 , V_37 , V_30 ) ;
for ( V_29 = 0 ; V_29 < V_38 ; V_29 ++ )
F_1 ( V_2 , F_10 ( V_29 ) , 0 ) ;
F_1 ( V_2 , V_39 , V_30 ) ;
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ )
F_1 ( V_2 , F_11 ( V_29 ) , 0 ) ;
}
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
F_13 ( V_2 , V_30 ) ;
V_2 -> V_44 = F_75 ( & V_234 -> V_236 , V_31 ,
sizeof( struct V_259 ) ,
V_101 ) ;
if ( ! V_2 -> V_44 )
return - V_151 ;
for ( V_30 = 0 ; V_30 < V_192 ; V_30 ++ )
F_60 ( V_2 , V_30 , V_196 ,
V_260 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
V_235 = F_73 ( V_2 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_74 ( V_234 , V_2 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_76 ( V_2 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_78 ( V_2 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_77 ( V_2 ) ;
if ( V_235 )
return V_235 ;
return 0 ;
}
static bool F_80 ( struct V_27 * V_28 ,
const T_3 * V_261 , unsigned char * V_68 )
{
unsigned char V_262 , V_263 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_114 ; V_30 ++ ) {
F_24 ( V_28 , V_30 , & V_262 , & V_263 ) ;
if ( V_263 != V_68 [ V_30 ] )
return false ;
if ( ( V_263 & V_262 ) != ( V_261 [ V_30 ] & V_68 [ V_30 ] ) )
return false ;
}
return true ;
}
static struct V_27 *
F_81 ( struct V_1 * V_2 , int V_264 , const T_3 * V_261 ,
unsigned char * V_68 , int V_265 )
{
struct V_27 * V_28 ;
int V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return NULL ;
F_16 ( V_28 , V_107 ) ;
for ( V_100 = V_140 ;
V_100 <= V_141 ; V_100 ++ ) {
unsigned int V_266 ;
if ( ! V_2 -> V_44 [ V_100 ] . V_45 ||
( V_2 -> V_44 [ V_100 ] . V_43 != V_107 ) ||
( V_2 -> V_44 [ V_100 ] . V_209 != V_265 ) )
continue;
V_28 -> V_30 = V_100 ;
F_12 ( V_2 , V_28 ) ;
V_266 = F_20 ( V_28 ) ;
if ( F_80 ( V_28 , V_261 , V_68 ) &&
V_266 == V_264 )
return V_28 ;
}
F_42 ( V_28 ) ;
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_22 ,
const T_3 * V_261 , bool V_52 )
{
struct V_27 * V_28 ;
unsigned int V_264 , V_267 , V_46 ;
unsigned char V_68 [ V_114 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_100 ;
V_28 = F_81 ( V_2 , ( 1 << V_22 ) , V_261 , V_68 ,
V_268 ) ;
if ( ! V_28 ) {
if ( ! V_52 )
return 0 ;
for ( V_100 = V_140 ;
V_100 <= V_141 ; V_100 ++ )
if ( V_2 -> V_44 [ V_100 ] . V_45 &&
( V_2 -> V_44 [ V_100 ] . V_43 == V_107 ) &&
( V_2 -> V_44 [ V_100 ] . V_209 ==
V_269 ) )
break;
V_100 = F_43 ( V_2 , V_140 ,
V_100 - 1 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return - V_151 ;
F_16 ( V_28 , V_107 ) ;
V_28 -> V_30 = V_100 ;
F_19 ( V_28 , 0 ) ;
}
F_18 ( V_28 , V_22 , V_52 ) ;
V_264 = F_20 ( V_28 ) ;
if ( V_264 == 0 ) {
if ( V_52 ) {
F_42 ( V_28 ) ;
return - V_32 ;
}
F_13 ( V_2 , V_28 -> V_30 ) ;
V_2 -> V_44 [ V_28 -> V_30 ] . V_45 = false ;
F_42 ( V_28 ) ;
return 0 ;
}
F_37 ( V_28 , V_111 ) ;
V_267 = V_114 ;
while ( V_267 -- )
F_21 ( V_28 , V_267 , V_261 [ V_267 ] , 0xff ) ;
if ( F_83 ( V_261 ) )
V_46 = V_270 ;
else if ( F_84 ( V_261 ) )
V_46 = V_118 ;
else
V_46 = V_112 | V_271 ;
F_33 ( V_28 , V_46 , V_113 |
V_271 ) ;
F_15 ( V_2 , V_28 -> V_30 , V_46 , V_113 |
V_271 ) ;
F_38 ( V_28 , 2 * V_114 ,
V_115 ) ;
V_2 -> V_44 [ V_28 -> V_30 ] . V_209 = V_268 ;
F_14 ( V_2 , V_28 -> V_30 , V_107 ) ;
F_9 ( V_2 , V_28 ) ;
F_42 ( V_28 ) ;
return 0 ;
}
static int F_85 ( struct V_272 * V_236 , const T_3 * V_261 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
int V_235 ;
V_235 = F_82 ( V_22 -> V_2 , V_22 -> V_24 , V_236 -> V_273 ,
false ) ;
if ( V_235 )
return V_235 ;
V_235 = F_82 ( V_22 -> V_2 , V_22 -> V_24 , V_261 , true ) ;
if ( V_235 )
return V_235 ;
F_87 ( V_236 -> V_273 , V_261 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , int V_22 )
{
struct V_27 V_28 ;
int V_30 , V_100 ;
for ( V_100 = V_140 ;
V_100 <= V_141 ; V_100 ++ ) {
unsigned char V_261 [ V_114 ] , V_274 [ V_114 ] ;
if ( ! V_2 -> V_44 [ V_100 ] . V_45 ||
( V_2 -> V_44 [ V_100 ] . V_43 != V_107 ) ||
( V_2 -> V_44 [ V_100 ] . V_209 != V_268 ) )
continue;
V_28 . V_30 = V_100 ;
F_12 ( V_2 , & V_28 ) ;
for ( V_30 = 0 ; V_30 < V_114 ; V_30 ++ )
F_24 ( & V_28 , V_30 , & V_261 [ V_30 ] ,
& V_274 [ V_30 ] ) ;
if ( F_84 ( V_261 ) && ! F_83 ( V_261 ) )
F_82 ( V_2 , V_22 , V_261 , false ) ;
}
}
static int F_89 ( struct V_1 * V_2 , int V_22 , int type )
{
switch ( type ) {
case V_275 :
F_48 ( V_2 , V_22 , true ,
V_202 , V_201 ) ;
F_48 ( V_2 , V_22 , true ,
V_200 , V_201 ) ;
F_48 ( V_2 , V_22 , false ,
V_202 , V_203 ) ;
F_48 ( V_2 , V_22 , false ,
V_200 , V_203 ) ;
break;
case V_276 :
F_48 ( V_2 , V_22 , true ,
V_202 , V_203 ) ;
F_48 ( V_2 , V_22 , true ,
V_200 , V_203 ) ;
F_48 ( V_2 , V_22 , false ,
V_202 , V_201 ) ;
F_48 ( V_2 , V_22 , false ,
V_200 , V_201 ) ;
break;
case V_277 :
case V_278 :
F_48 ( V_2 , V_22 , false ,
V_202 , V_203 ) ;
F_48 ( V_2 , V_22 , false ,
V_200 , V_203 ) ;
F_48 ( V_2 , V_22 , false ,
V_202 , V_201 ) ;
F_48 ( V_2 , V_22 , false ,
V_200 , V_201 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_275 ) )
return - V_32 ;
}
return 0 ;
}
static int F_90 ( struct V_21 * V_22 )
{
struct V_27 * V_28 ;
int V_100 ;
V_28 = F_40 ( V_22 -> V_2 , V_22 -> V_24 ) ;
if ( ! V_28 ) {
V_100 = F_43 ( V_22 -> V_2 ,
V_141 ,
V_140 ) ;
if ( V_100 < 0 )
return V_100 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 )
return - V_151 ;
F_16 ( V_28 , V_102 ) ;
V_28 -> V_30 = V_100 ;
F_35 ( V_28 , V_22 -> V_24 , V_103 ) ;
F_30 ( V_28 , V_194 , 1 ) ;
F_14 ( V_22 -> V_2 , V_28 -> V_30 , V_102 ) ;
}
F_19 ( V_28 , ( 1 << V_22 -> V_24 ) ) ;
F_9 ( V_22 -> V_2 , V_28 ) ;
F_42 ( V_28 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
F_1 ( V_2 , V_281 , V_280 -> V_30 ) ;
F_1 ( V_2 , V_282 , V_280 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_283 , V_280 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_284 , V_280 -> V_4 [ 2 ] ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_285 * V_286 )
{
T_1 V_67 ;
V_67 = ( V_286 -> V_287 << V_288 ) | V_286 -> V_289 ;
F_1 ( V_2 , V_290 , V_67 ) ;
F_1 ( V_2 , V_291 , V_286 -> V_4 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_285 V_286 ;
struct V_279 V_280 ;
int V_30 ;
F_1 ( V_2 , V_292 , V_293 ) ;
memset ( & V_280 . V_4 , 0 , sizeof( V_280 . V_4 ) ) ;
for ( V_30 = 0 ; V_30 < V_294 ; V_30 ++ ) {
V_280 . V_30 = V_30 ;
F_91 ( V_2 , & V_280 ) ;
}
V_286 . V_4 = 0 ;
for ( V_30 = 0 ; V_30 < V_295 ; V_30 ++ ) {
V_286 . V_289 = V_30 ;
V_286 . V_287 = 0 ;
F_92 ( V_2 , & V_286 ) ;
V_286 . V_287 = 1 ;
F_92 ( V_2 , & V_286 ) ;
}
}
static void F_94 ( struct V_21 * V_22 )
{
struct V_285 V_286 ;
T_1 V_67 ;
V_67 = F_3 ( V_22 -> V_2 , V_296 ) ;
V_67 &= ~ F_95 ( V_22 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_296 , V_67 ) ;
V_286 . V_289 = V_22 -> V_24 ;
V_286 . V_287 = 0 ;
V_286 . V_4 = 0 ;
V_286 . V_4 &= ~ V_297 ;
V_286 . V_4 |= V_22 -> V_298 ;
V_286 . V_4 &= ~ V_299 ;
F_92 ( V_22 -> V_2 , & V_286 ) ;
}
static void F_96 ( struct V_21 * V_22 )
{
T_1 V_67 ;
F_1 ( V_22 -> V_2 , F_97 ( V_22 -> V_24 ) ,
V_22 -> V_298 & V_300 ) ;
F_1 ( V_22 -> V_2 , F_98 ( V_22 -> V_24 ) ,
( V_22 -> V_298 >> V_301 ) ) ;
V_67 = F_3 ( V_22 -> V_2 , V_302 ) ;
V_67 |= F_99 ( V_22 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_302 , V_67 ) ;
}
static int F_100 ( struct V_233 * V_234 ,
struct V_1 * V_2 ,
struct V_303 * V_304 , int V_9 )
{
int V_305 ;
T_1 V_67 ;
V_305 = sizeof( T_1 ) * V_9 ;
V_304 -> V_306 = F_101 ( & V_234 -> V_236 , V_305 ,
& V_304 -> V_307 ,
V_101 ) ;
if ( ! V_304 -> V_306 )
return - V_151 ;
if ( ! F_102 ( ( T_1 ) V_304 -> V_306 , V_308 ) ) {
F_103 ( & V_234 -> V_236 , V_305 , V_304 -> V_306 ,
V_304 -> V_307 ) ;
F_104 ( & V_234 -> V_236 , L_1 ,
V_304 -> V_24 , V_308 ) ;
return - V_151 ;
}
F_1 ( V_2 , F_105 ( V_304 -> V_24 ) ,
V_304 -> V_307 ) ;
F_1 ( V_2 , F_106 ( V_304 -> V_24 ) , V_9 ) ;
V_67 = F_3 ( V_2 , F_107 ( V_304 -> V_24 ) ) ;
V_67 |= V_309 ;
F_1 ( V_2 , F_107 ( V_304 -> V_24 ) , V_67 ) ;
V_304 -> type = V_310 ;
V_304 -> V_9 = V_9 ;
V_304 -> V_311 = 0 ;
V_304 -> V_312 = 0 ;
F_108 ( & V_304 -> V_313 , 0 ) ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_303 * V_304 ,
int V_314 )
{
T_1 V_67 ;
V_304 -> V_314 = V_314 ;
V_67 = F_110 ( V_314 , 1 << V_315 ) ;
F_1 ( V_2 , F_111 ( V_304 -> V_24 ) , V_67 ) ;
}
static void F_112 ( struct V_316 * V_236 , struct V_1 * V_2 ,
struct V_303 * V_304 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_304 -> V_312 ; V_29 ++ ) {
T_4 V_20 ;
T_1 V_317 ;
V_20 = F_3 ( V_2 ,
F_113 ( V_304 -> V_24 ) ) ;
V_317 = F_3 ( V_2 , V_318 ) ;
F_114 ( V_236 , V_20 ,
V_304 -> V_314 , V_319 ) ;
if ( ! V_317 )
break;
F_115 ( (struct V_10 * ) V_317 ) ;
}
V_304 -> V_312 -= V_29 ;
}
static int F_116 ( struct V_233 * V_234 ,
struct V_1 * V_2 ,
struct V_303 * V_304 )
{
T_1 V_67 ;
F_112 ( & V_234 -> V_236 , V_2 , V_304 ) ;
if ( V_304 -> V_312 ) {
F_117 ( 1 , L_2 , V_304 -> V_24 ) ;
return 0 ;
}
V_67 = F_3 ( V_2 , F_107 ( V_304 -> V_24 ) ) ;
V_67 |= V_320 ;
F_1 ( V_2 , F_107 ( V_304 -> V_24 ) , V_67 ) ;
F_103 ( & V_234 -> V_236 , sizeof( T_1 ) * V_304 -> V_9 ,
V_304 -> V_306 ,
V_304 -> V_307 ) ;
return 0 ;
}
static int F_118 ( struct V_233 * V_234 ,
struct V_1 * V_2 )
{
int V_29 , V_235 , V_9 ;
struct V_303 * V_304 ;
V_9 = V_321 ;
for ( V_29 = 0 ; V_29 < V_322 ; V_29 ++ ) {
V_304 = & V_2 -> V_323 [ V_29 ] ;
V_304 -> V_24 = V_29 ;
V_235 = F_100 ( V_234 , V_2 , V_304 , V_9 ) ;
if ( V_235 )
goto V_324;
F_109 ( V_2 , V_304 , 0 ) ;
}
return 0 ;
V_324:
F_104 ( & V_234 -> V_236 , L_3 , V_29 , V_9 ) ;
for ( V_29 = V_29 - 1 ; V_29 >= 0 ; V_29 -- )
F_116 ( V_234 , V_2 , & V_2 -> V_323 [ V_29 ] ) ;
return V_235 ;
}
static int F_119 ( struct V_233 * V_234 , struct V_1 * V_2 )
{
int V_29 , V_235 ;
for ( V_29 = 0 ; V_29 < V_322 ; V_29 ++ ) {
F_1 ( V_2 , F_120 ( V_29 ) , 0 ) ;
F_1 ( V_2 , F_121 ( V_29 ) , 0 ) ;
}
V_2 -> V_323 = F_75 ( & V_234 -> V_236 , V_322 ,
sizeof( struct V_303 ) , V_101 ) ;
if ( ! V_2 -> V_323 )
return - V_151 ;
V_235 = F_118 ( V_234 , V_2 ) ;
if ( V_235 < 0 )
return V_235 ;
return 0 ;
}
static void F_122 ( struct V_21 * V_22 ,
int V_325 , int V_326 )
{
T_1 V_67 ;
int V_327 ;
V_327 = V_22 -> V_328 [ V_325 ] -> V_24 ;
V_67 = F_3 ( V_22 -> V_2 , F_123 ( V_327 ) ) ;
V_67 &= ~ V_329 ;
V_67 |= ( ( V_326 << V_330 ) &
V_329 ) ;
F_1 ( V_22 -> V_2 , F_123 ( V_327 ) , V_67 ) ;
}
static void F_124 ( struct V_21 * V_22 ,
int V_325 , int V_331 )
{
T_1 V_67 ;
int V_327 ;
V_327 = V_22 -> V_328 [ V_325 ] -> V_24 ;
V_67 = F_3 ( V_22 -> V_2 , F_123 ( V_327 ) ) ;
V_67 &= ~ V_332 ;
V_67 |= ( ( V_331 << V_333 ) &
V_332 ) ;
F_1 ( V_22 -> V_2 , F_123 ( V_327 ) , V_67 ) ;
}
static struct V_10 * F_125 ( struct V_21 * V_22 ,
struct V_303 * V_304 ,
T_4 * V_20 ,
T_5 V_334 )
{
struct V_10 * V_11 ;
T_4 V_307 ;
V_11 = F_126 ( V_304 -> V_311 , V_334 ) ;
if ( ! V_11 )
return NULL ;
V_307 = F_127 ( V_22 -> V_236 -> V_236 . V_335 , V_11 -> V_336 ,
F_128 ( V_304 -> V_311 ) ,
V_319 ) ;
if ( F_129 ( F_130 ( V_22 -> V_236 -> V_236 . V_335 , V_307 ) ) ) {
F_115 ( V_11 ) ;
return NULL ;
}
* V_20 = V_307 ;
return V_11 ;
}
static inline T_1 F_131 ( T_1 V_337 , int V_338 )
{
T_1 V_339 ;
V_339 = V_337 & ~ ( 0xFF << V_340 ) ;
V_339 |= ( ( V_338 & 0xFF ) << V_340 ) ;
return V_339 ;
}
static inline int F_132 ( T_1 V_337 )
{
return ( V_337 >> V_340 ) & 0xFF ;
}
static inline void F_133 ( struct V_21 * V_22 , int V_338 ,
T_1 V_20 , T_1 V_341 )
{
F_1 ( V_22 -> V_2 , V_342 , V_341 ) ;
F_1 ( V_22 -> V_2 , F_134 ( V_338 ) , V_20 ) ;
}
static void F_135 ( struct V_21 * V_22 , int V_338 ,
T_1 V_20 , T_1 V_341 ,
int V_343 )
{
T_1 V_67 = 0 ;
V_67 |= ( V_343 & V_344 ) ;
F_1 ( V_22 -> V_2 , V_345 , V_67 ) ;
F_133 ( V_22 , V_338 ,
V_20 | V_346 ,
V_341 ) ;
}
static void F_136 ( struct V_21 * V_22 , T_1 V_339 ,
T_1 V_307 , T_1 V_337 )
{
int V_338 = F_132 ( V_339 ) ;
F_133 ( V_22 , V_338 , V_307 , V_337 ) ;
}
static int F_137 ( struct V_21 * V_22 ,
struct V_303 * V_304 , int V_312 )
{
struct V_10 * V_11 ;
int V_29 , V_314 , V_347 ;
T_1 V_339 ;
T_4 V_307 ;
V_314 = F_128 ( V_304 -> V_311 ) ;
V_347 = F_138 ( V_314 ) ;
if ( V_312 < 0 ||
( V_312 + V_304 -> V_312 > V_304 -> V_9 ) ) {
F_139 ( V_22 -> V_236 ,
L_4 ,
V_312 , V_304 -> V_24 ) ;
return 0 ;
}
V_339 = F_131 ( 0 , V_304 -> V_24 ) ;
for ( V_29 = 0 ; V_29 < V_312 ; V_29 ++ ) {
V_11 = F_125 ( V_22 , V_304 , & V_307 , V_101 ) ;
if ( ! V_11 )
break;
F_136 ( V_22 , V_339 , ( T_1 ) V_307 , ( T_1 ) V_11 ) ;
}
V_304 -> V_312 += V_29 ;
V_304 -> V_348 = V_304 -> V_312 / 4 ;
F_140 ( V_22 -> V_236 ,
L_5 ,
V_304 -> type == V_349 ? L_6 : L_7 ,
V_304 -> V_24 , V_304 -> V_311 , V_314 , V_347 ) ;
F_140 ( V_22 -> V_236 ,
L_8 ,
V_304 -> type == V_349 ? L_6 : L_7 ,
V_304 -> V_24 , V_29 , V_312 ) ;
return V_29 ;
}
static struct V_303 *
F_141 ( struct V_21 * V_22 , int V_338 , enum V_350 type ,
int V_311 )
{
struct V_303 * V_351 = & V_22 -> V_2 -> V_323 [ V_338 ] ;
int V_352 ;
if ( V_351 -> type != V_310 && V_351 -> type != type ) {
F_139 ( V_22 -> V_236 , L_9 ) ;
return NULL ;
}
if ( V_351 -> type == V_310 )
V_351 -> type = type ;
if ( ( ( type == V_353 ) && ( V_311 > V_351 -> V_311 ) ) ||
( V_351 -> V_311 == 0 ) ) {
int V_354 ;
V_354 = V_351 -> V_312 ;
if ( V_354 == 0 )
V_354 = type == V_353 ?
V_355 :
V_356 ;
else
F_112 ( V_22 -> V_236 -> V_236 . V_335 ,
V_22 -> V_2 , V_351 ) ;
V_351 -> V_311 = V_311 ;
V_352 = F_137 ( V_22 , V_351 , V_354 ) ;
if ( V_352 != V_354 ) {
F_117 ( 1 , L_10 ,
V_351 -> V_24 , V_352 , V_354 ) ;
return NULL ;
}
}
F_109 ( V_22 -> V_2 , V_351 ,
F_128 ( V_351 -> V_311 ) ) ;
return V_351 ;
}
static int F_142 ( struct V_21 * V_22 )
{
int V_357 ;
if ( ! V_22 -> V_358 ) {
V_22 -> V_358 =
F_141 ( V_22 , F_143 ( V_22 -> V_24 ) ,
V_353 ,
V_22 -> V_311 ) ;
if ( ! V_22 -> V_358 )
return - V_151 ;
V_22 -> V_358 -> V_148 |= ( 1 << V_22 -> V_24 ) ;
for ( V_357 = 0 ; V_357 < V_359 ; V_357 ++ )
F_122 ( V_22 , V_357 , V_22 -> V_358 -> V_24 ) ;
}
if ( ! V_22 -> V_360 ) {
V_22 -> V_360 =
F_141 ( V_22 , V_361 ,
V_349 ,
V_362 ) ;
if ( ! V_22 -> V_360 )
return - V_151 ;
V_22 -> V_360 -> V_148 |= ( 1 << V_22 -> V_24 ) ;
for ( V_357 = 0 ; V_357 < V_359 ; V_357 ++ )
F_124 ( V_22 , V_357 ,
V_22 -> V_360 -> V_24 ) ;
}
return 0 ;
}
static int F_144 ( struct V_272 * V_236 , int V_363 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
struct V_303 * V_364 = V_22 -> V_358 ;
int V_352 , V_354 = V_364 -> V_312 ;
int V_311 = F_145 ( V_363 ) ;
F_112 ( V_236 -> V_236 . V_335 , V_22 -> V_2 , V_364 ) ;
if ( V_364 -> V_312 ) {
F_117 ( 1 , L_2 , V_364 -> V_24 ) ;
return - V_365 ;
}
V_364 -> V_311 = V_311 ;
V_352 = F_137 ( V_22 , V_364 , V_354 ) ;
if ( V_352 != V_354 ) {
F_117 ( 1 , L_10 ,
V_364 -> V_24 , V_352 , V_354 ) ;
return - V_365 ;
}
F_109 ( V_22 -> V_2 , V_364 ,
F_128 ( V_364 -> V_311 ) ) ;
V_236 -> V_363 = V_363 ;
F_146 ( V_236 ) ;
return 0 ;
}
static inline void F_147 ( struct V_21 * V_22 )
{
int V_366 , V_367 = 0 ;
F_148 (cpu)
V_367 |= 1 << V_366 ;
F_1 ( V_22 -> V_2 , F_149 ( V_22 -> V_24 ) ,
F_150 ( V_367 ) ) ;
}
static inline void F_151 ( struct V_21 * V_22 )
{
int V_366 , V_367 = 0 ;
F_148 (cpu)
V_367 |= 1 << V_366 ;
F_1 ( V_22 -> V_2 , F_149 ( V_22 -> V_24 ) ,
F_152 ( V_367 ) ) ;
}
static void F_153 ( void * V_368 )
{
struct V_21 * V_22 = V_368 ;
F_1 ( V_22 -> V_2 , F_154 ( V_22 -> V_24 ) , 0 ) ;
}
static void F_155 ( void * V_368 )
{
struct V_21 * V_22 = V_368 ;
F_1 ( V_22 -> V_2 , F_154 ( V_22 -> V_24 ) ,
( V_369 |
V_370 ) ) ;
}
static void F_156 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_371 ) ;
switch ( V_22 -> V_372 ) {
case V_373 :
V_67 |= V_374 ;
break;
case V_375 :
V_67 |= V_376 ;
default:
V_67 &= ~ V_377 ;
}
F_2 ( V_67 , V_22 -> V_5 + V_371 ) ;
}
static void F_157 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_378 ) ;
V_67 |= V_379 ;
F_2 ( V_67 , V_22 -> V_5 + V_378 ) ;
}
static void F_158 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_380 ) ;
V_67 |= V_381 ;
V_67 |= V_382 ;
F_2 ( V_67 , V_22 -> V_5 + V_380 ) ;
}
static void F_159 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_380 ) ;
V_67 &= ~ ( V_381 ) ;
F_2 ( V_67 , V_22 -> V_5 + V_380 ) ;
}
static void F_160 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_383 ) &
~ V_384 ;
F_2 ( V_67 , V_22 -> V_5 + V_383 ) ;
}
static void F_161 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_383 ) ;
if ( V_22 -> V_385 == 1000 )
V_67 |= V_386 ;
else
V_67 &= ~ V_386 ;
if ( V_22 -> V_372 == V_373 )
V_67 |= V_387 ;
else
V_67 &= ~ V_387 ;
F_2 ( V_67 , V_22 -> V_5 + V_383 ) ;
}
static void F_162 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_371 ) &
~ V_388 ;
F_2 ( V_67 , V_22 -> V_5 + V_371 ) ;
while ( F_4 ( V_22 -> V_5 + V_371 ) &
V_388 )
continue;
}
static inline void F_163 ( struct V_21 * V_22 )
{
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_380 ) ;
V_67 &= ~ V_389 ;
V_67 |= ( ( ( V_22 -> V_311 - V_197 ) / 2 ) <<
V_390 ) ;
F_2 ( V_67 , V_22 -> V_5 + V_380 ) ;
}
static void F_164 ( struct V_21 * V_22 )
{
int V_391 , V_67 , V_392 , V_393 , V_325 ;
if ( V_22 -> V_394 & V_395 )
F_161 ( V_22 ) ;
V_67 = F_4 ( V_22 -> V_5 + V_396 ) ;
V_67 &= ~ V_397 ;
V_67 |= F_165 ( 64 - 4 - 2 ) ;
F_2 ( V_67 , V_22 -> V_5 + V_396 ) ;
V_391 = F_7 ( V_22 ) ;
F_1 ( V_22 -> V_2 , V_398 ,
V_391 ) ;
F_1 ( V_22 -> V_2 , V_399 , 0 ) ;
for ( V_392 = 0 ; V_392 < V_26 ; V_392 ++ ) {
V_393 = F_8 ( V_22 -> V_24 , V_392 ) ;
F_1 ( V_22 -> V_2 ,
F_166 ( V_393 ) , 0 ) ;
}
F_1 ( V_22 -> V_2 , V_400 ,
V_22 -> V_2 -> V_401 / V_402 ) ;
V_67 = F_3 ( V_22 -> V_2 , V_403 ) ;
V_67 &= ~ V_404 ;
V_67 |= F_167 ( 1 ) ;
V_67 |= V_405 ;
F_1 ( V_22 -> V_2 , V_403 , V_67 ) ;
V_67 = V_406 ;
F_1 ( V_22 -> V_2 , V_407 , V_67 ) ;
F_1 ( V_22 -> V_2 , F_168 ( V_22 -> V_24 ) ,
V_408 |
F_169 ( 256 ) ) ;
for ( V_325 = 0 ; V_325 < V_359 ; V_325 ++ ) {
V_392 = V_22 -> V_328 [ V_325 ] -> V_24 ;
V_67 = F_3 ( V_22 -> V_2 , F_123 ( V_392 ) ) ;
V_67 |= V_409 |
V_410 ;
F_1 ( V_22 -> V_2 , F_123 ( V_392 ) , V_67 ) ;
}
F_151 ( V_22 ) ;
}
static void F_170 ( struct V_21 * V_22 )
{
T_1 V_67 ;
int V_325 , V_392 ;
for ( V_325 = 0 ; V_325 < V_359 ; V_325 ++ ) {
V_392 = V_22 -> V_328 [ V_325 ] -> V_24 ;
V_67 = F_3 ( V_22 -> V_2 , F_123 ( V_392 ) ) ;
V_67 &= ~ V_411 ;
F_1 ( V_22 -> V_2 , F_123 ( V_392 ) , V_67 ) ;
}
}
static void F_171 ( struct V_21 * V_22 )
{
T_1 V_67 ;
int V_325 , V_392 ;
for ( V_325 = 0 ; V_325 < V_359 ; V_325 ++ ) {
V_392 = V_22 -> V_328 [ V_325 ] -> V_24 ;
V_67 = F_3 ( V_22 -> V_2 , F_123 ( V_392 ) ) ;
V_67 |= V_411 ;
F_1 ( V_22 -> V_2 , F_123 ( V_392 ) , V_67 ) ;
}
}
static void F_172 ( struct V_21 * V_22 )
{
T_1 V_412 ;
int V_392 ;
int V_391 = F_7 ( V_22 ) ;
V_412 = 0 ;
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
struct V_414 * V_25 = V_22 -> V_415 [ V_392 ] ;
if ( V_25 -> V_416 != NULL )
V_412 |= ( 1 << V_392 ) ;
}
F_1 ( V_22 -> V_2 , V_398 , V_391 ) ;
F_1 ( V_22 -> V_2 , V_417 , V_412 ) ;
}
static void F_173 ( struct V_21 * V_22 )
{
T_1 V_418 ;
int V_419 ;
int V_391 = F_7 ( V_22 ) ;
F_1 ( V_22 -> V_2 , V_398 , V_391 ) ;
V_418 = ( F_3 ( V_22 -> V_2 , V_417 ) ) &
V_420 ;
if ( V_418 != 0 )
F_1 ( V_22 -> V_2 , V_417 ,
( V_418 << V_421 ) ) ;
V_419 = 0 ;
do {
if ( V_419 >= V_422 ) {
F_174 ( V_22 -> V_236 ,
L_11 ,
V_418 ) ;
break;
}
F_175 ( 1 ) ;
V_419 ++ ;
V_418 = F_3 ( V_22 -> V_2 , V_417 ) ;
} while ( V_418 & V_420 );
}
static inline int
F_176 ( struct V_21 * V_22 , int V_423 )
{
T_1 V_67 = F_3 ( V_22 -> V_2 , F_177 ( V_423 ) ) ;
return V_67 & V_424 ;
}
static inline void
F_178 ( struct V_21 * V_22 , int V_423 ,
int V_425 , int V_426 )
{
T_1 V_67 = V_425 | ( V_426 << V_427 ) ;
F_1 ( V_22 -> V_2 , F_179 ( V_423 ) , V_67 ) ;
}
static inline struct V_428 *
F_180 ( struct V_429 * V_357 )
{
int V_430 = V_357 -> V_431 ;
V_357 -> V_431 = F_181 ( V_357 , V_430 ) ;
F_182 ( V_357 -> V_416 + V_357 -> V_431 ) ;
return V_357 -> V_416 + V_430 ;
}
static void F_183 ( struct V_21 * V_22 ,
int V_327 , int V_3 )
{
T_1 V_67 ;
V_3 = V_3 >> 5 ;
V_67 = F_3 ( V_22 -> V_2 , F_123 ( V_327 ) ) ;
V_67 &= ~ V_432 ;
V_67 |= ( ( V_3 << V_433 ) &
V_432 ) ;
F_1 ( V_22 -> V_2 , F_123 ( V_327 ) , V_67 ) ;
}
static T_1 F_184 ( struct V_428 * V_430 )
{
int V_338 = ( V_430 -> V_434 & V_435 ) >>
V_436 ;
int V_366 = F_185 () ;
return ( ( V_338 & 0xFF ) << V_340 ) |
( ( V_366 & 0xFF ) << V_437 ) ;
}
static int F_186 ( struct V_21 * V_22 ,
struct V_414 * V_25 )
{
T_1 V_67 ;
F_1 ( V_22 -> V_2 , V_438 , V_25 -> V_24 ) ;
V_67 = F_3 ( V_22 -> V_2 , V_439 ) ;
return V_67 & V_440 ;
}
static struct V_12 *
F_187 ( struct V_414 * V_25 )
{
int V_13 = V_25 -> V_431 ;
V_25 -> V_431 = F_181 ( V_25 , V_13 ) ;
return V_25 -> V_416 + V_13 ;
}
static void F_188 ( struct V_21 * V_22 , int V_441 )
{
F_1 ( V_22 -> V_2 , V_442 , V_441 ) ;
}
static int F_189 ( struct V_1 * V_2 ,
struct V_414 * V_443 , int V_352 )
{
if ( ( V_443 -> V_444 + V_352 ) > V_443 -> V_9 ) {
int V_366 = F_185 () ;
T_1 V_67 = F_3 ( V_2 , F_190 ( V_366 ) ) ;
V_443 -> V_444 = V_67 & V_445 ;
}
if ( ( V_443 -> V_444 + V_352 ) > V_443 -> V_9 )
return - V_151 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_414 * V_25 , int V_352 )
{
T_1 V_67 ;
V_67 = ( V_25 -> V_24 << V_446 ) | V_352 ;
F_1 ( V_2 , V_447 , V_67 ) ;
V_67 = F_3 ( V_2 , V_448 ) ;
return V_67 & V_449 ;
}
static int F_192 ( struct V_1 * V_2 ,
struct V_414 * V_25 ,
struct V_6 * V_7 ,
int V_352 )
{
int V_450 , V_366 , V_451 ;
if ( V_7 -> V_452 >= V_352 )
return 0 ;
V_451 = 0 ;
F_148 (cpu) {
struct V_6 * V_453 ;
V_453 = F_193 ( V_25 -> V_454 , V_366 ) ;
V_451 += V_453 -> V_444 ;
V_451 += V_453 -> V_452 ;
}
V_450 = F_194 ( V_455 , V_352 - V_7 -> V_452 ) ;
V_451 += V_450 ;
if ( V_451 >
( V_25 -> V_9 - ( F_195 () * V_455 ) ) )
return - V_151 ;
V_7 -> V_452 += F_191 ( V_2 , V_25 , V_450 ) ;
if ( V_7 -> V_452 < V_352 )
return - V_151 ;
return 0 ;
}
static void F_196 ( struct V_414 * V_25 )
{
if ( V_25 -> V_431 == 0 )
V_25 -> V_431 = V_25 -> V_456 - 1 ;
else
V_25 -> V_431 -- ;
}
static T_1 F_197 ( int V_457 , int V_458 ,
int V_459 , int V_460 )
{
T_1 V_461 ;
V_461 = ( V_457 << V_462 ) ;
V_461 |= ( V_459 << V_463 ) ;
V_461 |= V_464 ;
if ( V_458 == F_51 ( V_221 ) ) {
V_461 &= ~ V_464 ;
V_461 &= ~ V_465 ;
} else {
V_461 |= V_465 ;
}
if ( V_460 == V_161 ) {
V_461 &= ~ V_466 ;
V_461 &= ~ V_467 ;
} else if ( V_460 == V_162 ) {
V_461 |= V_466 ;
V_461 &= ~ V_467 ;
} else {
V_461 |= V_468 ;
}
return V_461 ;
}
static inline int F_198 ( struct V_21 * V_22 ,
struct V_414 * V_25 )
{
T_1 V_67 ;
V_67 = F_3 ( V_22 -> V_2 , F_199 ( V_25 -> V_24 ) ) ;
return ( V_67 & V_469 ) >>
V_470 ;
}
static void F_200 ( void * V_368 )
{
struct V_21 * V_22 = V_368 ;
int V_392 ;
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
int V_24 = V_22 -> V_415 [ V_392 ] -> V_24 ;
F_3 ( V_22 -> V_2 , F_199 ( V_24 ) ) ;
}
}
static void F_201 ( struct V_21 * V_22 )
{
T_1 V_67 , V_9 , V_363 ;
int V_25 , V_391 ;
V_363 = V_22 -> V_311 * 8 ;
if ( V_363 > V_471 )
V_363 = V_471 ;
V_363 = 3 * V_363 ;
V_391 = F_7 ( V_22 ) ;
F_1 ( V_22 -> V_2 , V_398 , V_391 ) ;
V_67 = F_3 ( V_22 -> V_2 , V_472 ) ;
V_67 &= ~ V_471 ;
V_67 |= V_363 ;
F_1 ( V_22 -> V_2 , V_472 , V_67 ) ;
V_67 = F_3 ( V_22 -> V_2 , V_407 ) ;
V_9 = V_67 & V_406 ;
if ( V_9 < V_363 ) {
V_9 = V_363 ;
V_67 &= ~ V_406 ;
V_67 |= V_9 ;
F_1 ( V_22 -> V_2 , V_407 , V_67 ) ;
}
for ( V_25 = 0 ; V_25 < V_413 ; V_25 ++ ) {
V_67 = F_3 ( V_22 -> V_2 ,
F_202 ( V_25 ) ) ;
V_9 = V_67 & V_473 ;
if ( V_9 < V_363 ) {
V_9 = V_363 ;
V_67 &= ~ V_473 ;
V_67 |= V_9 ;
F_1 ( V_22 -> V_2 ,
F_202 ( V_25 ) ,
V_67 ) ;
}
}
}
static void F_203 ( struct V_21 * V_22 ,
struct V_429 * V_357 , T_1 V_474 )
{
T_1 V_67 ;
V_67 = ( V_474 & V_475 ) ;
F_1 ( V_22 -> V_2 , V_476 , V_357 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_477 , V_67 ) ;
V_357 -> V_478 = V_474 ;
}
static void F_204 ( struct V_21 * V_22 ,
struct V_429 * V_357 , T_1 V_479 )
{
T_1 V_67 ;
V_67 = ( V_22 -> V_2 -> V_401 / V_402 ) * V_479 ;
F_1 ( V_22 -> V_2 , F_205 ( V_357 -> V_24 ) , V_67 ) ;
V_357 -> V_480 = V_479 ;
}
static void F_206 ( struct V_21 * V_22 ,
struct V_414 * V_25 ,
struct V_6 * V_7 , int V_352 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_352 ; V_29 ++ ) {
struct V_14 * V_15 =
V_7 -> V_16 + V_7 -> V_8 ;
F_5 ( V_7 ) ;
F_114 ( V_22 -> V_236 -> V_236 . V_335 , V_15 -> V_19 ,
V_15 -> V_9 , V_481 ) ;
if ( ! V_15 -> V_11 )
continue;
F_115 ( V_15 -> V_11 ) ;
}
}
static inline struct V_429 * F_207 ( struct V_21 * V_22 ,
T_1 V_482 )
{
int V_392 = F_208 ( V_482 ) - 1 ;
return V_22 -> V_328 [ V_392 ] ;
}
static inline struct V_414 * F_209 ( struct V_21 * V_22 ,
T_1 V_482 )
{
int V_392 = F_208 ( V_482 ) - 1 ;
return V_22 -> V_415 [ V_392 ] ;
}
static void F_210 ( struct V_21 * V_22 , struct V_414 * V_25 ,
struct V_6 * V_7 )
{
struct V_483 * V_484 = F_211 ( V_22 -> V_236 , V_25 -> V_485 ) ;
int V_486 ;
if ( V_7 -> V_366 != F_185 () )
F_139 ( V_22 -> V_236 , L_12 ) ;
V_486 = F_198 ( V_22 , V_25 ) ;
if ( ! V_486 )
return;
F_206 ( V_22 , V_25 , V_7 , V_486 ) ;
V_7 -> V_444 -= V_486 ;
if ( F_212 ( V_484 ) )
if ( V_7 -> V_9 - V_7 -> V_444 >= V_487 + 1 )
F_213 ( V_484 ) ;
}
static unsigned int F_214 ( struct V_21 * V_22 , T_1 V_482 )
{
struct V_414 * V_25 ;
struct V_6 * V_7 ;
unsigned int V_488 = 0 ;
while ( V_482 ) {
V_25 = F_209 ( V_22 , V_482 ) ;
if ( ! V_25 )
break;
V_7 = F_215 ( V_25 -> V_454 ) ;
if ( V_7 -> V_444 ) {
F_210 ( V_22 , V_25 , V_7 ) ;
V_488 += V_7 -> V_444 ;
}
V_482 &= ~ ( 1 << V_25 -> V_485 ) ;
}
return V_488 ;
}
static int F_216 ( struct V_233 * V_234 ,
struct V_414 * V_443 ,
int V_489 , int V_366 ,
struct V_1 * V_2 )
{
V_443 -> V_416 = F_101 ( & V_234 -> V_236 ,
V_489 * V_490 ,
& V_443 -> V_491 , V_101 ) ;
if ( ! V_443 -> V_416 )
return - V_151 ;
V_443 -> V_456 = V_443 -> V_9 - 1 ;
V_443 -> V_431 = F_3 ( V_2 ,
F_217 ( V_366 ) ) ;
F_1 ( V_2 , F_218 ( V_366 ) ,
V_443 -> V_491 ) ;
F_1 ( V_2 , F_219 ( V_366 ) , V_489 ) ;
return 0 ;
}
static int F_220 ( struct V_21 * V_22 ,
struct V_429 * V_357 )
{
V_357 -> V_9 = V_22 -> V_492 ;
V_357 -> V_416 = F_101 ( V_22 -> V_236 -> V_236 . V_335 ,
V_357 -> V_9 * V_490 ,
& V_357 -> V_491 , V_101 ) ;
if ( ! V_357 -> V_416 )
return - V_151 ;
V_357 -> V_456 = V_357 -> V_9 - 1 ;
F_1 ( V_22 -> V_2 , F_177 ( V_357 -> V_24 ) , 0 ) ;
F_1 ( V_22 -> V_2 , V_476 , V_357 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_493 , V_357 -> V_491 ) ;
F_1 ( V_22 -> V_2 , V_494 , V_357 -> V_9 ) ;
F_1 ( V_22 -> V_2 , V_495 , 0 ) ;
F_183 ( V_22 , V_357 -> V_24 , V_496 ) ;
F_203 ( V_22 , V_357 , V_357 -> V_478 ) ;
F_204 ( V_22 , V_357 , V_357 -> V_480 ) ;
F_178 ( V_22 , V_357 -> V_24 , 0 , V_357 -> V_9 ) ;
return 0 ;
}
static void F_221 ( struct V_21 * V_22 ,
struct V_429 * V_357 )
{
int V_497 , V_29 ;
V_497 = F_176 ( V_22 , V_357 -> V_24 ) ;
if ( ! V_497 )
return;
for ( V_29 = 0 ; V_29 < V_497 ; V_29 ++ ) {
struct V_428 * V_430 = F_180 ( V_357 ) ;
T_1 V_339 = F_184 ( V_430 ) ;
F_136 ( V_22 , V_339 , V_430 -> V_20 ,
V_430 -> V_498 ) ;
}
F_178 ( V_22 , V_357 -> V_24 , V_497 , V_497 ) ;
}
static void F_222 ( struct V_21 * V_22 ,
struct V_429 * V_357 )
{
F_221 ( V_22 , V_357 ) ;
if ( V_357 -> V_416 )
F_103 ( V_22 -> V_236 -> V_236 . V_335 ,
V_357 -> V_9 * V_490 ,
V_357 -> V_416 ,
V_357 -> V_491 ) ;
V_357 -> V_416 = NULL ;
V_357 -> V_456 = 0 ;
V_357 -> V_431 = 0 ;
V_357 -> V_491 = 0 ;
F_1 ( V_22 -> V_2 , F_177 ( V_357 -> V_24 ) , 0 ) ;
F_1 ( V_22 -> V_2 , V_476 , V_357 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_493 , 0 ) ;
F_1 ( V_22 -> V_2 , V_494 , 0 ) ;
}
static int F_223 ( struct V_21 * V_22 ,
struct V_414 * V_25 )
{
T_1 V_67 ;
int V_366 , V_499 , V_500 , V_391 ;
struct V_6 * V_7 ;
V_25 -> V_9 = V_22 -> V_501 ;
V_25 -> V_416 = F_101 ( V_22 -> V_236 -> V_236 . V_335 ,
V_25 -> V_9 * V_490 ,
& V_25 -> V_491 , V_101 ) ;
if ( ! V_25 -> V_416 )
return - V_151 ;
V_25 -> V_456 = V_25 -> V_9 - 1 ;
F_1 ( V_22 -> V_2 , V_438 , V_25 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_502 , V_25 -> V_491 ) ;
F_1 ( V_22 -> V_2 , V_503 , V_25 -> V_9 &
V_504 ) ;
F_1 ( V_22 -> V_2 , V_505 , 0 ) ;
F_1 ( V_22 -> V_2 , V_506 ,
V_25 -> V_24 << V_507 ) ;
V_67 = F_3 ( V_22 -> V_2 , V_439 ) ;
V_67 &= ~ V_440 ;
F_1 ( V_22 -> V_2 , V_439 , V_67 ) ;
V_500 = 16 ;
V_499 = ( V_22 -> V_24 * V_26 * V_500 ) +
( V_25 -> V_485 * V_500 ) ;
F_1 ( V_22 -> V_2 , V_508 ,
F_224 ( V_499 ) | V_509 |
F_225 ( V_500 / 2 ) ) ;
V_391 = F_7 ( V_22 ) ;
F_1 ( V_22 -> V_2 , V_398 , V_391 ) ;
V_67 = F_3 ( V_22 -> V_2 , F_226 ( V_25 -> V_485 ) ) ;
V_67 &= ~ V_510 ;
V_67 |= F_227 ( 1 ) ;
V_67 |= V_511 ;
F_1 ( V_22 -> V_2 , F_226 ( V_25 -> V_485 ) , V_67 ) ;
V_67 = V_473 ;
F_1 ( V_22 -> V_2 , F_202 ( V_25 -> V_485 ) ,
V_67 ) ;
F_148 (cpu) {
V_7 = F_193 ( V_25 -> V_454 , V_366 ) ;
V_7 -> V_9 = V_25 -> V_9 ;
V_7 -> V_16 = F_228 ( V_7 -> V_9 *
sizeof( struct V_14 ) ,
V_101 ) ;
if ( ! V_7 -> V_16 )
goto error;
V_7 -> V_444 = 0 ;
V_7 -> V_452 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_8 = 0 ;
}
return 0 ;
error:
F_148 (cpu) {
V_7 = F_193 ( V_25 -> V_454 , V_366 ) ;
F_42 ( V_7 -> V_16 ) ;
}
F_103 ( V_22 -> V_236 -> V_236 . V_335 ,
V_25 -> V_9 * V_490 ,
V_25 -> V_416 , V_25 -> V_491 ) ;
return - V_151 ;
}
static void F_229 ( struct V_21 * V_22 ,
struct V_414 * V_25 )
{
struct V_6 * V_7 ;
int V_366 ;
F_148 (cpu) {
V_7 = F_193 ( V_25 -> V_454 , V_366 ) ;
F_42 ( V_7 -> V_16 ) ;
}
if ( V_25 -> V_416 )
F_103 ( V_22 -> V_236 -> V_236 . V_335 ,
V_25 -> V_9 * V_490 ,
V_25 -> V_416 , V_25 -> V_491 ) ;
V_25 -> V_416 = NULL ;
V_25 -> V_456 = 0 ;
V_25 -> V_431 = 0 ;
V_25 -> V_491 = 0 ;
F_1 ( V_22 -> V_2 , F_166 ( V_25 -> V_24 ) , 0 ) ;
F_1 ( V_22 -> V_2 , V_438 , V_25 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_502 , 0 ) ;
F_1 ( V_22 -> V_2 , V_503 , 0 ) ;
}
static void F_230 ( struct V_21 * V_22 , struct V_414 * V_25 )
{
struct V_6 * V_7 ;
int V_419 , V_441 , V_366 ;
T_1 V_67 ;
F_1 ( V_22 -> V_2 , V_438 , V_25 -> V_24 ) ;
V_67 = F_3 ( V_22 -> V_2 , V_508 ) ;
V_67 |= V_512 ;
F_1 ( V_22 -> V_2 , V_508 , V_67 ) ;
V_419 = 0 ;
do {
if ( V_419 >= V_513 ) {
F_174 ( V_22 -> V_236 ,
L_13 ,
V_22 -> V_24 , V_25 -> V_485 ) ;
break;
}
F_175 ( 1 ) ;
V_419 ++ ;
V_441 = F_186 ( V_22 , V_25 ) ;
} while ( V_441 );
V_67 &= ~ V_512 ;
F_1 ( V_22 -> V_2 , V_508 , V_67 ) ;
F_148 (cpu) {
V_7 = F_193 ( V_25 -> V_454 , V_366 ) ;
F_206 ( V_22 , V_25 , V_7 , V_7 -> V_444 ) ;
V_7 -> V_444 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_8 = 0 ;
}
}
static void F_231 ( struct V_21 * V_22 )
{
struct V_414 * V_25 ;
int V_392 ;
T_1 V_67 ;
V_67 = F_3 ( V_22 -> V_2 , V_514 ) ;
V_67 |= F_232 ( V_22 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_514 , V_67 ) ;
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
V_25 = V_22 -> V_415 [ V_392 ] ;
F_230 ( V_22 , V_25 ) ;
F_229 ( V_22 , V_25 ) ;
}
F_233 ( F_200 , V_22 , 1 ) ;
V_67 &= ~ F_232 ( V_22 -> V_24 ) ;
F_1 ( V_22 -> V_2 , V_514 , V_67 ) ;
}
static void F_234 ( struct V_21 * V_22 )
{
int V_392 ;
for ( V_392 = 0 ; V_392 < V_359 ; V_392 ++ )
F_222 ( V_22 , V_22 -> V_328 [ V_392 ] ) ;
}
static int F_235 ( struct V_21 * V_22 )
{
int V_392 , V_235 ;
for ( V_392 = 0 ; V_392 < V_359 ; V_392 ++ ) {
V_235 = F_220 ( V_22 , V_22 -> V_328 [ V_392 ] ) ;
if ( V_235 )
goto V_515;
}
return 0 ;
V_515:
F_234 ( V_22 ) ;
return V_235 ;
}
static int F_236 ( struct V_21 * V_22 )
{
struct V_414 * V_25 ;
int V_392 , V_235 ;
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
V_25 = V_22 -> V_415 [ V_392 ] ;
V_235 = F_223 ( V_22 , V_25 ) ;
if ( V_235 )
goto V_515;
}
F_233 ( F_200 , V_22 , 1 ) ;
return 0 ;
V_515:
F_231 ( V_22 ) ;
return V_235 ;
}
static T_6 F_237 ( int V_516 , void * V_517 )
{
struct V_21 * V_22 = (struct V_21 * ) V_517 ;
F_151 ( V_22 ) ;
F_238 ( & V_22 -> V_518 ) ;
return V_519 ;
}
static void F_239 ( struct V_272 * V_236 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
struct V_520 * V_521 = V_236 -> V_521 ;
int V_522 = 0 ;
T_1 V_67 ;
if ( V_521 -> V_523 ) {
if ( ( V_22 -> V_385 != V_521 -> V_385 ) ||
( V_22 -> V_524 != V_521 -> V_524 ) ) {
T_1 V_67 ;
V_67 = F_4 ( V_22 -> V_5 + V_378 ) ;
V_67 &= ~ ( V_525 |
V_526 |
V_527 |
V_528 |
V_529 ) ;
if ( V_521 -> V_524 )
V_67 |= V_527 ;
if ( V_521 -> V_385 == V_530 )
V_67 |= V_526 ;
else if ( V_521 -> V_385 == V_531 )
V_67 |= V_525 ;
F_2 ( V_67 , V_22 -> V_5 + V_378 ) ;
V_22 -> V_524 = V_521 -> V_524 ;
V_22 -> V_385 = V_521 -> V_385 ;
}
}
if ( V_521 -> V_523 != V_22 -> V_523 ) {
if ( ! V_521 -> V_523 ) {
V_22 -> V_524 = - 1 ;
V_22 -> V_385 = 0 ;
}
V_22 -> V_523 = V_521 -> V_523 ;
V_522 = 1 ;
}
if ( V_522 ) {
if ( V_521 -> V_523 ) {
V_67 = F_4 ( V_22 -> V_5 + V_378 ) ;
V_67 |= ( V_532 |
V_533 ) ;
F_2 ( V_67 , V_22 -> V_5 + V_378 ) ;
F_172 ( V_22 ) ;
F_170 ( V_22 ) ;
} else {
F_171 ( V_22 ) ;
F_173 ( V_22 ) ;
}
F_240 ( V_521 ) ;
}
}
static void F_241 ( struct V_534 * V_535 )
{
T_7 V_536 ;
if ( ! V_535 -> V_537 ) {
V_535 -> V_537 = true ;
V_536 = V_538 ;
F_242 ( & V_535 -> V_539 , V_536 ,
V_540 ) ;
}
}
static void F_243 ( unsigned long V_4 )
{
struct V_272 * V_236 = (struct V_272 * ) V_4 ;
struct V_21 * V_22 = F_86 ( V_236 ) ;
struct V_534 * V_535 = F_215 ( V_22 -> V_454 ) ;
unsigned int V_488 , V_482 ;
if ( ! F_244 ( V_236 ) )
return;
V_535 -> V_537 = false ;
V_482 = ( 1 << V_413 ) - 1 ;
V_488 = F_214 ( V_22 , V_482 ) ;
if ( V_488 )
F_241 ( V_535 ) ;
}
static enum V_541 F_245 ( struct V_542 * V_543 )
{
struct V_534 * V_535 = F_246 ( V_543 ,
struct V_534 ,
V_539 ) ;
F_247 ( & V_535 -> V_544 ) ;
return V_545 ;
}
static void F_248 ( struct V_21 * V_22 ,
struct V_428 * V_430 )
{
T_1 V_434 = V_430 -> V_434 ;
switch ( V_434 & V_546 ) {
case V_547 :
F_139 ( V_22 -> V_236 , L_14 ,
V_434 , V_430 -> V_18 ) ;
break;
case V_548 :
F_139 ( V_22 -> V_236 , L_15 ,
V_434 , V_430 -> V_18 ) ;
break;
case V_549 :
F_139 ( V_22 -> V_236 , L_16 ,
V_434 , V_430 -> V_18 ) ;
break;
}
}
static void F_249 ( struct V_21 * V_22 , T_1 V_434 ,
struct V_10 * V_11 )
{
if ( ( ( V_434 & V_550 ) &&
! ( V_434 & V_551 ) ) ||
( V_434 & V_552 ) )
if ( ( ( V_434 & V_553 ) ||
( V_434 & V_554 ) ) &&
( V_434 & V_555 ) ) {
V_11 -> V_556 = 0 ;
V_11 -> V_557 = V_558 ;
return;
}
V_11 -> V_557 = V_559 ;
}
static int F_250 ( struct V_21 * V_22 ,
struct V_303 * V_304 ,
T_1 V_339 , int V_560 )
{
struct V_10 * V_11 ;
T_4 V_307 ;
if ( V_560 &&
( F_251 ( & V_304 -> V_313 ) < V_304 -> V_348 ) )
return 0 ;
V_11 = F_125 ( V_22 , V_304 , & V_307 , V_561 ) ;
if ( ! V_11 )
return - V_151 ;
F_136 ( V_22 , V_339 , ( T_1 ) V_307 , ( T_1 ) V_11 ) ;
F_252 ( & V_304 -> V_313 ) ;
return 0 ;
}
static T_1 F_253 ( struct V_21 * V_22 , struct V_10 * V_11 )
{
if ( V_11 -> V_557 == V_562 ) {
int V_459 = 0 ;
T_3 V_460 ;
if ( V_11 -> V_563 == F_254 ( V_221 ) ) {
struct V_166 * V_564 = F_255 ( V_11 ) ;
V_459 = V_564 -> V_565 ;
V_460 = V_564 -> V_563 ;
} else if ( V_11 -> V_563 == F_254 ( V_228 ) ) {
struct V_185 * V_566 = F_256 ( V_11 ) ;
if ( F_257 ( V_11 ) > 0 )
V_459 = ( F_257 ( V_11 ) >> 2 ) ;
V_460 = V_566 -> V_567 ;
} else {
return V_468 ;
}
return F_197 ( F_258 ( V_11 ) ,
V_11 -> V_563 , V_459 , V_460 ) ;
}
return V_468 | V_464 ;
}
static void F_259 ( struct V_21 * V_22 ,
struct V_428 * V_430 )
{
struct V_568 * V_569 ;
struct V_10 * V_11 ;
T_1 V_570 = V_430 -> V_434 ;
T_1 V_571 ;
T_1 V_572 ;
T_1 V_573 ;
T_1 V_574 ;
int V_343 ;
int V_575 ;
V_575 = ( V_570 & V_435 ) >>
V_436 ;
V_571 = V_430 -> V_20 ;
V_572 = V_430 -> V_498 ;
do {
V_11 = (struct V_10 * ) V_572 ;
V_569 = (struct V_568 * ) V_11 -> V_336 ;
V_343 = F_260 ( V_569 -> V_576 ) ;
V_573 = V_569 -> V_577 ;
V_574 = V_569 -> V_578 ;
F_135 ( V_22 , V_575 , V_571 ,
V_572 , V_343 ) ;
V_571 = V_573 ;
V_572 = V_574 ;
} while ( ! F_261 ( V_569 -> V_576 ) );
}
static int F_262 ( struct V_21 * V_22 , int V_579 ,
struct V_429 * V_357 )
{
struct V_272 * V_236 = V_22 -> V_236 ;
int V_497 ;
int V_580 = 0 ;
T_1 V_581 = 0 ;
T_1 V_582 = 0 ;
V_497 = F_176 ( V_22 , V_357 -> V_24 ) ;
if ( V_579 > V_497 )
V_579 = V_497 ;
while ( V_580 < V_579 ) {
struct V_428 * V_430 = F_180 ( V_357 ) ;
struct V_303 * V_304 ;
struct V_10 * V_11 ;
T_4 V_307 ;
T_1 V_339 , V_570 ;
int V_338 , V_583 , V_235 ;
V_580 ++ ;
V_570 = V_430 -> V_434 ;
V_583 = V_430 -> V_18 - V_197 ;
V_307 = V_430 -> V_20 ;
V_339 = F_184 ( V_430 ) ;
V_338 = F_132 ( V_339 ) ;
V_304 = & V_22 -> V_2 -> V_323 [ V_338 ] ;
if ( V_570 & V_584 ) {
F_259 ( V_22 , V_430 ) ;
continue;
}
if ( V_570 & V_585 ) {
V_586:
V_236 -> V_587 . V_588 ++ ;
F_248 ( V_22 , V_430 ) ;
F_136 ( V_22 , V_339 , V_430 -> V_20 ,
V_430 -> V_498 ) ;
continue;
}
V_11 = (struct V_10 * ) V_430 -> V_498 ;
V_235 = F_250 ( V_22 , V_304 , V_339 , 0 ) ;
if ( V_235 ) {
F_139 ( V_22 -> V_236 , L_17 ) ;
goto V_586;
}
F_114 ( V_236 -> V_236 . V_335 , V_307 ,
V_304 -> V_314 , V_319 ) ;
V_581 ++ ;
V_582 += V_583 ;
F_263 ( & V_304 -> V_313 ) ;
F_264 ( V_11 , V_197 ) ;
F_265 ( V_11 , V_583 ) ;
V_11 -> V_563 = F_266 ( V_11 , V_236 ) ;
F_249 ( V_22 , V_570 , V_11 ) ;
F_267 ( & V_22 -> V_518 , V_11 ) ;
}
if ( V_581 ) {
struct V_589 * V_587 = F_215 ( V_22 -> V_587 ) ;
F_268 ( & V_587 -> V_590 ) ;
V_587 -> V_591 += V_581 ;
V_587 -> V_583 += V_582 ;
F_269 ( & V_587 -> V_590 ) ;
}
F_270 () ;
F_178 ( V_22 , V_357 -> V_24 , V_580 , V_580 ) ;
return V_579 ;
}
static inline void
F_271 ( struct V_316 * V_236 , struct V_414 * V_25 ,
struct V_12 * V_499 )
{
F_114 ( V_236 , V_499 -> V_20 ,
V_499 -> V_18 , V_481 ) ;
F_196 ( V_25 ) ;
}
static int F_272 ( struct V_21 * V_22 , struct V_10 * V_11 ,
struct V_414 * V_443 ,
struct V_414 * V_25 )
{
struct V_6 * V_7 = F_215 ( V_25 -> V_454 ) ;
struct V_12 * V_13 ;
int V_29 ;
T_4 V_20 ;
for ( V_29 = 0 ; V_29 < F_273 ( V_11 ) -> V_592 ; V_29 ++ ) {
T_8 * V_593 = & F_273 ( V_11 ) -> V_594 [ V_29 ] ;
void * V_595 = F_274 ( V_593 -> V_596 . V_597 ) + V_593 -> V_598 ;
V_13 = F_187 ( V_443 ) ;
V_13 -> V_599 = V_25 -> V_24 ;
V_13 -> V_18 = V_593 -> V_9 ;
V_20 = F_127 ( V_22 -> V_236 -> V_236 . V_335 , V_595 ,
V_13 -> V_18 ,
V_481 ) ;
if ( F_130 ( V_22 -> V_236 -> V_236 . V_335 , V_20 ) ) {
F_196 ( V_25 ) ;
goto error;
}
V_13 -> V_600 = V_20 & V_601 ;
V_13 -> V_20 = V_20 & ( ~ V_601 ) ;
if ( V_29 == ( F_273 ( V_11 ) -> V_592 - 1 ) ) {
V_13 -> V_461 = V_602 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_13 -> V_461 = 0 ;
F_6 ( V_7 , NULL , V_13 ) ;
}
}
return 0 ;
error:
for ( V_29 = V_29 - 1 ; V_29 >= 0 ; V_29 -- ) {
V_13 = V_25 -> V_416 + V_29 ;
F_271 ( V_22 -> V_236 -> V_236 . V_335 , V_25 , V_13 ) ;
}
return - V_151 ;
}
static int F_275 ( struct V_10 * V_11 , struct V_272 * V_236 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
struct V_414 * V_25 , * V_443 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
T_4 V_20 ;
int V_594 = 0 ;
T_2 V_603 ;
T_1 V_604 ;
V_603 = F_276 ( V_11 ) ;
V_25 = V_22 -> V_415 [ V_603 ] ;
V_7 = F_215 ( V_25 -> V_454 ) ;
V_443 = & V_22 -> V_2 -> V_605 [ F_185 () ] ;
V_594 = F_273 ( V_11 ) -> V_592 + 1 ;
if ( F_189 ( V_22 -> V_2 , V_443 , V_594 ) ||
F_192 ( V_22 -> V_2 , V_25 ,
V_7 , V_594 ) ) {
V_594 = 0 ;
goto V_606;
}
V_13 = F_187 ( V_443 ) ;
V_13 -> V_599 = V_25 -> V_24 ;
V_13 -> V_18 = F_277 ( V_11 ) ;
V_20 = F_127 ( V_236 -> V_236 . V_335 , V_11 -> V_4 ,
V_13 -> V_18 , V_481 ) ;
if ( F_129 ( F_130 ( V_236 -> V_236 . V_335 , V_20 ) ) ) {
F_196 ( V_25 ) ;
V_594 = 0 ;
goto V_606;
}
V_13 -> V_600 = V_20 & V_601 ;
V_13 -> V_20 = V_20 & ~ V_601 ;
V_604 = F_253 ( V_22 , V_11 ) ;
if ( V_594 == 1 ) {
V_604 |= V_607 | V_602 ;
V_13 -> V_461 = V_604 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_604 |= V_607 | V_608 ;
V_13 -> V_461 = V_604 ;
F_6 ( V_7 , NULL , V_13 ) ;
if ( F_272 ( V_22 , V_11 , V_443 , V_25 ) ) {
F_271 ( V_22 -> V_236 -> V_236 . V_335 , V_25 , V_13 ) ;
V_594 = 0 ;
goto V_606;
}
}
V_7 -> V_452 -= V_594 ;
V_7 -> V_444 += V_594 ;
V_443 -> V_444 += V_594 ;
F_270 () ;
F_188 ( V_22 , V_594 ) ;
if ( V_7 -> V_9 - V_7 -> V_444 < V_487 + 1 ) {
struct V_483 * V_484 = F_211 ( V_236 , V_603 ) ;
F_278 ( V_484 ) ;
}
V_606:
if ( V_594 > 0 ) {
struct V_589 * V_587 = F_215 ( V_22 -> V_587 ) ;
F_268 ( & V_587 -> V_590 ) ;
V_587 -> V_609 ++ ;
V_587 -> V_610 += V_11 -> V_267 ;
F_269 ( & V_587 -> V_590 ) ;
} else {
V_236 -> V_587 . V_611 ++ ;
F_115 ( V_11 ) ;
}
if ( V_7 -> V_444 >= V_25 -> V_612 )
F_210 ( V_22 , V_25 , V_7 ) ;
if ( V_7 -> V_444 <= V_594 && V_7 -> V_444 > 0 ) {
struct V_534 * V_535 = F_215 ( V_22 -> V_454 ) ;
F_241 ( V_535 ) ;
}
return V_613 ;
}
static inline void F_279 ( struct V_272 * V_236 , int V_482 )
{
if ( V_482 & V_614 )
F_139 ( V_236 , L_18 ) ;
if ( V_482 & V_615 )
F_139 ( V_236 , L_19 ) ;
if ( V_482 & V_616 )
F_139 ( V_236 , L_20 ) ;
}
static int F_280 ( struct V_617 * V_518 , int V_618 )
{
T_1 V_619 , V_620 , V_621 ;
int V_580 = 0 ;
struct V_21 * V_22 = F_86 ( V_518 -> V_236 ) ;
V_619 = F_3 ( V_22 -> V_2 ,
F_281 ( V_22 -> V_24 ) ) ;
V_619 &= ~ V_622 ;
V_621 = V_619 & V_369 ;
if ( V_621 ) {
F_279 ( V_22 -> V_236 , V_621 ) ;
F_1 ( V_22 -> V_2 , V_623 , 0 ) ;
F_1 ( V_22 -> V_2 , F_281 ( V_22 -> V_24 ) ,
V_619 & ~ V_369 ) ;
}
V_620 = V_619 & V_370 ;
V_620 |= V_22 -> V_624 ;
while ( V_620 && V_618 > 0 ) {
int V_444 ;
struct V_429 * V_357 ;
V_357 = F_207 ( V_22 , V_620 ) ;
if ( ! V_357 )
break;
V_444 = F_262 ( V_22 , V_618 , V_357 ) ;
V_580 += V_444 ;
V_618 -= V_444 ;
if ( V_618 > 0 ) {
V_620 &= ~ ( 1 << V_357 -> V_625 ) ;
}
}
if ( V_618 > 0 ) {
V_620 = 0 ;
F_282 ( V_518 ) ;
F_147 ( V_22 ) ;
}
V_22 -> V_624 = V_620 ;
return V_580 ;
}
static void F_283 ( struct V_21 * V_22 )
{
struct V_272 * V_626 = V_22 -> V_236 ;
F_163 ( V_22 ) ;
F_201 ( V_22 ) ;
F_284 ( & V_22 -> V_518 ) ;
F_147 ( V_22 ) ;
F_158 ( V_22 ) ;
F_285 ( V_626 -> V_521 ) ;
F_286 ( V_22 -> V_236 ) ;
}
static void F_287 ( struct V_21 * V_22 )
{
struct V_272 * V_626 = V_22 -> V_236 ;
F_171 ( V_22 ) ;
F_175 ( 10 ) ;
F_151 ( V_22 ) ;
F_288 ( & V_22 -> V_518 ) ;
F_289 ( V_22 -> V_236 ) ;
F_290 ( V_22 -> V_236 ) ;
F_173 ( V_22 ) ;
F_159 ( V_22 ) ;
F_291 ( V_626 -> V_521 ) ;
}
static int F_292 ( struct V_272 * V_236 ,
struct V_627 * V_628 )
{
T_2 V_629 = V_628 -> V_630 ;
T_2 V_631 = V_628 -> V_632 ;
if ( V_628 -> V_630 == 0 || V_628 -> V_632 == 0 )
return - V_32 ;
if ( V_628 -> V_630 > V_633 )
V_629 = V_633 ;
else if ( ! F_102 ( V_628 -> V_630 , 16 ) )
V_629 = F_110 ( V_628 -> V_630 , 16 ) ;
if ( V_628 -> V_632 > V_634 )
V_631 = V_634 ;
else if ( ! F_102 ( V_628 -> V_632 , 32 ) )
V_631 = F_110 ( V_628 -> V_632 , 32 ) ;
if ( V_628 -> V_630 != V_629 ) {
F_293 ( V_236 , L_21 ,
V_628 -> V_630 , V_629 ) ;
V_628 -> V_630 = V_629 ;
}
if ( V_628 -> V_632 != V_631 ) {
F_293 ( V_236 , L_22 ,
V_628 -> V_632 , V_631 ) ;
V_628 -> V_632 = V_631 ;
}
return 0 ;
}
static void F_294 ( struct V_21 * V_22 , unsigned char * V_595 )
{
T_1 V_635 , V_636 , V_637 ;
V_635 = F_4 ( V_22 -> V_5 + V_383 ) ;
V_636 = F_4 ( V_22 -> V_2 -> V_638 + V_639 ) ;
V_637 = F_4 ( V_22 -> V_2 -> V_638 + V_640 ) ;
V_595 [ 0 ] = ( V_637 >> 24 ) & 0xFF ;
V_595 [ 1 ] = ( V_637 >> 16 ) & 0xFF ;
V_595 [ 2 ] = ( V_637 >> 8 ) & 0xFF ;
V_595 [ 3 ] = V_637 & 0xFF ;
V_595 [ 4 ] = V_636 & 0xFF ;
V_595 [ 5 ] = ( V_635 >> V_641 ) & 0xFF ;
}
static int F_295 ( struct V_21 * V_22 )
{
struct V_520 * V_642 ;
V_642 = F_296 ( V_22 -> V_236 , V_22 -> V_643 , F_239 , 0 ,
V_22 -> V_372 ) ;
if ( ! V_642 ) {
F_139 ( V_22 -> V_236 , L_23 ) ;
return - V_644 ;
}
V_642 -> V_645 &= V_646 ;
V_642 -> V_647 = V_642 -> V_645 ;
V_22 -> V_523 = 0 ;
V_22 -> V_524 = 0 ;
V_22 -> V_385 = 0 ;
return 0 ;
}
static void F_297 ( struct V_21 * V_22 )
{
struct V_272 * V_626 = V_22 -> V_236 ;
F_298 ( V_626 -> V_521 ) ;
}
static int F_299 ( struct V_272 * V_236 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
unsigned char V_648 [ V_114 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_235 ;
V_235 = F_82 ( V_22 -> V_2 , V_22 -> V_24 , V_648 , true ) ;
if ( V_235 ) {
F_139 ( V_236 , L_24 ) ;
return V_235 ;
}
V_235 = F_82 ( V_22 -> V_2 , V_22 -> V_24 ,
V_236 -> V_273 , true ) ;
if ( V_235 ) {
F_139 ( V_236 , L_25 ) ;
return V_235 ;
}
V_235 = F_89 ( V_22 -> V_2 , V_22 -> V_24 , V_277 ) ;
if ( V_235 ) {
F_139 ( V_236 , L_26 ) ;
return V_235 ;
}
V_235 = F_90 ( V_22 ) ;
if ( V_235 ) {
F_139 ( V_236 , L_27 ) ;
return V_235 ;
}
V_235 = F_235 ( V_22 ) ;
if ( V_235 ) {
F_139 ( V_22 -> V_236 , L_28 ) ;
return V_235 ;
}
V_235 = F_236 ( V_22 ) ;
if ( V_235 ) {
F_139 ( V_22 -> V_236 , L_29 ) ;
goto V_649;
}
V_235 = F_300 ( V_22 -> V_516 , F_237 , 0 , V_236 -> V_650 , V_22 ) ;
if ( V_235 ) {
F_139 ( V_22 -> V_236 , L_30 , V_22 -> V_516 ) ;
goto V_651;
}
F_289 ( V_22 -> V_236 ) ;
V_235 = F_295 ( V_22 ) ;
if ( V_235 < 0 )
goto V_652;
F_233 ( F_155 , V_22 , 1 ) ;
F_283 ( V_22 ) ;
return 0 ;
V_652:
F_301 ( V_22 -> V_516 , V_22 ) ;
V_651:
F_231 ( V_22 ) ;
V_649:
F_234 ( V_22 ) ;
return V_235 ;
}
static int F_302 ( struct V_272 * V_236 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
struct V_534 * V_535 ;
int V_366 ;
F_287 ( V_22 ) ;
F_297 ( V_22 ) ;
F_233 ( F_153 , V_22 , 1 ) ;
F_301 ( V_22 -> V_516 , V_22 ) ;
F_148 (cpu) {
V_535 = F_193 ( V_22 -> V_454 , V_366 ) ;
F_303 ( & V_535 -> V_539 ) ;
V_535 -> V_537 = false ;
F_304 ( & V_535 -> V_544 ) ;
}
F_234 ( V_22 ) ;
F_231 ( V_22 ) ;
return 0 ;
}
static void F_305 ( struct V_272 * V_236 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_653 * V_654 ;
int V_24 = V_22 -> V_24 ;
bool V_655 = V_236 -> V_394 & V_656 ;
F_46 ( V_2 , V_24 , V_236 -> V_394 & V_657 ) ;
F_47 ( V_2 , V_24 , V_117 , V_655 ) ;
F_47 ( V_2 , V_24 , V_199 , V_655 ) ;
F_88 ( V_2 , V_24 ) ;
if ( V_655 && ! F_306 ( V_236 ) ) {
F_307 (ha, dev)
F_82 ( V_2 , V_24 , V_654 -> V_595 , true ) ;
}
}
static int F_308 ( struct V_272 * V_236 , void * V_597 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
const struct V_658 * V_595 = V_597 ;
int V_235 ;
if ( ! F_309 ( V_595 -> V_659 ) ) {
V_235 = - V_660 ;
goto error;
}
if ( ! F_244 ( V_236 ) ) {
V_235 = F_85 ( V_236 , V_595 -> V_659 ) ;
if ( ! V_235 )
return 0 ;
V_235 = F_85 ( V_236 , V_236 -> V_273 ) ;
if ( V_235 )
goto error;
}
F_287 ( V_22 ) ;
V_235 = F_85 ( V_236 , V_595 -> V_659 ) ;
if ( ! V_235 )
goto V_661;
V_235 = F_85 ( V_236 , V_236 -> V_273 ) ;
if ( V_235 )
goto error;
V_661:
F_283 ( V_22 ) ;
F_172 ( V_22 ) ;
F_170 ( V_22 ) ;
return 0 ;
error:
F_139 ( V_236 , L_31 ) ;
return V_235 ;
}
static int F_310 ( struct V_272 * V_236 , int V_363 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
int V_235 ;
if ( ! F_102 ( F_145 ( V_363 ) , 8 ) ) {
F_293 ( V_236 , L_32 , V_363 ,
F_110 ( F_145 ( V_363 ) , 8 ) ) ;
V_363 = F_110 ( F_145 ( V_363 ) , 8 ) ;
}
if ( ! F_244 ( V_236 ) ) {
V_235 = F_144 ( V_236 , V_363 ) ;
if ( ! V_235 ) {
V_22 -> V_311 = F_145 ( V_363 ) ;
return 0 ;
}
V_235 = F_144 ( V_236 , V_236 -> V_363 ) ;
if ( V_235 )
goto error;
}
F_287 ( V_22 ) ;
V_235 = F_144 ( V_236 , V_363 ) ;
if ( ! V_235 ) {
V_22 -> V_311 = F_145 ( V_363 ) ;
goto V_661;
}
V_235 = F_144 ( V_236 , V_236 -> V_363 ) ;
if ( V_235 )
goto error;
V_661:
F_283 ( V_22 ) ;
F_172 ( V_22 ) ;
F_170 ( V_22 ) ;
return 0 ;
error:
F_139 ( V_236 , L_33 ) ;
return V_235 ;
}
static struct V_662 *
F_311 ( struct V_272 * V_236 , struct V_662 * V_587 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
unsigned int V_104 ;
int V_366 ;
F_312 (cpu) {
struct V_589 * V_663 ;
T_9 V_591 ;
T_9 V_583 ;
T_9 V_609 ;
T_9 V_610 ;
V_663 = F_193 ( V_22 -> V_587 , V_366 ) ;
do {
V_104 = F_313 ( & V_663 -> V_590 ) ;
V_591 = V_663 -> V_591 ;
V_583 = V_663 -> V_583 ;
V_609 = V_663 -> V_609 ;
V_610 = V_663 -> V_610 ;
} while ( F_314 ( & V_663 -> V_590 , V_104 ) );
V_587 -> V_591 += V_591 ;
V_587 -> V_583 += V_583 ;
V_587 -> V_609 += V_609 ;
V_587 -> V_610 += V_610 ;
}
V_587 -> V_588 = V_236 -> V_587 . V_588 ;
V_587 -> V_664 = V_236 -> V_587 . V_664 ;
V_587 -> V_611 = V_236 -> V_587 . V_611 ;
return V_587 ;
}
static int F_315 ( struct V_272 * V_236 , struct V_665 * V_666 , int V_667 )
{
int V_150 ;
if ( ! V_236 -> V_521 )
return - V_668 ;
V_150 = F_316 ( V_236 -> V_521 , V_666 , V_667 ) ;
if ( ! V_150 )
F_239 ( V_236 ) ;
return V_150 ;
}
static int F_317 ( struct V_272 * V_236 ,
struct V_669 * V_670 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
int V_392 ;
for ( V_392 = 0 ; V_392 < V_359 ; V_392 ++ ) {
struct V_429 * V_357 = V_22 -> V_328 [ V_392 ] ;
V_357 -> V_480 = V_670 -> V_671 ;
V_357 -> V_478 = V_670 -> V_672 ;
F_203 ( V_22 , V_357 , V_357 -> V_478 ) ;
F_204 ( V_22 , V_357 , V_357 -> V_480 ) ;
}
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
struct V_414 * V_25 = V_22 -> V_415 [ V_392 ] ;
V_25 -> V_612 = V_670 -> V_673 ;
}
return 0 ;
}
static int F_318 ( struct V_272 * V_236 ,
struct V_669 * V_670 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
V_670 -> V_671 = V_22 -> V_328 [ 0 ] -> V_480 ;
V_670 -> V_672 = V_22 -> V_328 [ 0 ] -> V_478 ;
V_670 -> V_673 = V_22 -> V_415 [ 0 ] -> V_612 ;
return 0 ;
}
static void F_319 ( struct V_272 * V_236 ,
struct V_674 * V_675 )
{
F_320 ( V_675 -> V_676 , V_677 ,
sizeof( V_675 -> V_676 ) ) ;
F_320 ( V_675 -> V_678 , V_679 ,
sizeof( V_675 -> V_678 ) ) ;
F_320 ( V_675 -> V_680 , F_321 ( & V_236 -> V_236 ) ,
sizeof( V_675 -> V_680 ) ) ;
}
static void F_322 ( struct V_272 * V_236 ,
struct V_627 * V_628 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
V_628 -> V_681 = V_633 ;
V_628 -> V_682 = V_634 ;
V_628 -> V_630 = V_22 -> V_492 ;
V_628 -> V_632 = V_22 -> V_501 ;
}
static int F_323 ( struct V_272 * V_236 ,
struct V_627 * V_628 )
{
struct V_21 * V_22 = F_86 ( V_236 ) ;
T_2 V_683 = V_22 -> V_492 ;
T_2 V_684 = V_22 -> V_501 ;
int V_235 ;
V_235 = F_292 ( V_236 , V_628 ) ;
if ( V_235 )
return V_235 ;
if ( ! F_244 ( V_236 ) ) {
V_22 -> V_492 = V_628 -> V_630 ;
V_22 -> V_501 = V_628 -> V_632 ;
return 0 ;
}
F_287 ( V_22 ) ;
F_234 ( V_22 ) ;
F_231 ( V_22 ) ;
V_22 -> V_492 = V_628 -> V_630 ;
V_22 -> V_501 = V_628 -> V_632 ;
V_235 = F_235 ( V_22 ) ;
if ( V_235 ) {
V_22 -> V_492 = V_683 ;
V_628 -> V_630 = V_683 ;
V_235 = F_235 ( V_22 ) ;
if ( V_235 )
goto V_685;
}
V_235 = F_236 ( V_22 ) ;
if ( V_235 ) {
V_22 -> V_501 = V_684 ;
V_628 -> V_632 = V_684 ;
V_235 = F_236 ( V_22 ) ;
if ( V_235 )
goto V_686;
}
F_283 ( V_22 ) ;
F_172 ( V_22 ) ;
F_170 ( V_22 ) ;
return 0 ;
V_686:
F_234 ( V_22 ) ;
V_685:
F_139 ( V_236 , L_34 ) ;
return V_235 ;
}
static void F_324 ( struct V_21 * V_22 )
{
F_156 ( V_22 ) ;
F_160 ( V_22 ) ;
F_157 ( V_22 ) ;
F_162 ( V_22 ) ;
}
static int F_325 ( struct V_21 * V_22 )
{
struct V_316 * V_236 = V_22 -> V_236 -> V_236 . V_335 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_6 * V_7 ;
int V_392 , V_366 , V_235 ;
if ( V_22 -> V_298 + V_359 > V_687 )
return - V_32 ;
F_173 ( V_22 ) ;
F_159 ( V_22 ) ;
V_22 -> V_415 = F_75 ( V_236 , V_413 , sizeof( * V_22 -> V_415 ) ,
V_101 ) ;
if ( ! V_22 -> V_415 )
return - V_151 ;
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
int V_688 = F_8 ( V_22 -> V_24 , V_392 ) ;
struct V_414 * V_25 ;
V_25 = F_326 ( V_236 , sizeof( * V_25 ) , V_101 ) ;
if ( ! V_25 )
return - V_151 ;
V_25 -> V_454 = F_327 ( struct V_6 ) ;
if ( ! V_25 -> V_454 ) {
V_235 = - V_151 ;
goto V_689;
}
V_25 -> V_24 = V_688 ;
V_25 -> V_485 = V_392 ;
V_25 -> V_612 = V_690 ;
F_148 (cpu) {
V_7 = F_193 ( V_25 -> V_454 , V_366 ) ;
V_7 -> V_366 = V_366 ;
}
V_22 -> V_415 [ V_392 ] = V_25 ;
}
V_22 -> V_328 = F_75 ( V_236 , V_359 , sizeof( * V_22 -> V_328 ) ,
V_101 ) ;
if ( ! V_22 -> V_328 ) {
V_235 = - V_151 ;
goto V_689;
}
for ( V_392 = 0 ; V_392 < V_359 ; V_392 ++ ) {
struct V_429 * V_357 ;
V_357 = F_326 ( V_236 , sizeof( * V_357 ) , V_101 ) ;
if ( ! V_357 ) {
V_235 = - V_151 ;
goto V_689;
}
V_357 -> V_24 = V_22 -> V_298 + V_392 ;
V_357 -> V_22 = V_22 -> V_24 ;
V_357 -> V_625 = V_392 ;
V_22 -> V_328 [ V_392 ] = V_357 ;
}
F_1 ( V_2 , F_328 ( V_22 -> V_24 ) , V_359 ) ;
for ( V_392 = 0 ; V_392 < V_359 ; V_392 ++ ) {
struct V_429 * V_357 = V_22 -> V_328 [ V_392 ] ;
V_357 -> V_9 = V_22 -> V_492 ;
V_357 -> V_478 = V_691 ;
V_357 -> V_480 = V_692 ;
}
F_171 ( V_22 ) ;
F_164 ( V_22 ) ;
F_96 ( V_22 ) ;
F_94 ( V_22 ) ;
V_22 -> V_311 = F_145 ( V_22 -> V_236 -> V_363 ) ;
V_235 = F_142 ( V_22 ) ;
if ( V_235 )
goto V_689;
return 0 ;
V_689:
for ( V_392 = 0 ; V_392 < V_413 ; V_392 ++ ) {
if ( ! V_22 -> V_415 [ V_392 ] )
continue;
F_329 ( V_22 -> V_415 [ V_392 ] -> V_454 ) ;
}
return V_235 ;
}
static int F_330 ( struct V_233 * V_234 ,
struct V_693 * V_694 ,
struct V_1 * V_2 ,
int * V_695 )
{
struct V_693 * V_643 ;
struct V_21 * V_22 ;
struct V_534 * V_535 ;
struct V_272 * V_236 ;
struct V_696 * V_697 ;
const char * V_698 ;
const char * V_699 ;
char V_700 [ V_114 ] ;
T_1 V_24 ;
int V_701 ;
int V_702 ;
int V_703 = 2 ;
int V_235 , V_29 , V_366 ;
V_236 = F_331 ( sizeof( struct V_21 ) , V_413 ,
V_359 ) ;
if ( ! V_236 )
return - V_151 ;
V_643 = F_332 ( V_694 , L_35 , 0 ) ;
if ( ! V_643 ) {
F_104 ( & V_234 -> V_236 , L_36 ) ;
V_235 = - V_644 ;
goto V_704;
}
V_702 = F_333 ( V_694 ) ;
if ( V_702 < 0 ) {
F_104 ( & V_234 -> V_236 , L_37 ) ;
V_235 = V_702 ;
goto V_704;
}
if ( F_334 ( V_694 , L_38 , & V_24 ) ) {
V_235 = - V_32 ;
F_104 ( & V_234 -> V_236 , L_39 ) ;
goto V_704;
}
V_236 -> V_705 = V_634 ;
V_236 -> V_706 = 5 * V_707 ;
V_236 -> V_708 = & V_709 ;
V_236 -> V_710 = & V_711 ;
V_22 = F_86 ( V_236 ) ;
V_22 -> V_516 = F_335 ( V_694 , 0 ) ;
if ( V_22 -> V_516 <= 0 ) {
V_235 = - V_32 ;
goto V_704;
}
if ( F_336 ( V_694 , L_40 ) )
V_22 -> V_394 |= V_395 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_24 = V_24 ;
V_22 -> V_298 = * V_695 ;
V_22 -> V_643 = V_643 ;
V_22 -> V_372 = V_702 ;
V_697 = F_337 ( V_234 , V_712 ,
V_703 + V_24 ) ;
V_22 -> V_5 = F_338 ( & V_234 -> V_236 , V_697 ) ;
if ( F_339 ( V_22 -> V_5 ) ) {
V_235 = F_340 ( V_22 -> V_5 ) ;
goto V_652;
}
V_22 -> V_587 = F_341 ( struct V_589 ) ;
if ( ! V_22 -> V_587 ) {
V_235 = - V_151 ;
goto V_652;
}
V_698 = F_342 ( V_694 ) ;
if ( V_698 && F_309 ( V_698 ) ) {
V_699 = L_41 ;
F_87 ( V_236 -> V_273 , V_698 ) ;
} else {
F_294 ( V_22 , V_700 ) ;
if ( F_309 ( V_700 ) ) {
V_699 = L_42 ;
F_87 ( V_236 -> V_273 , V_700 ) ;
} else {
V_699 = L_43 ;
F_343 ( V_236 ) ;
}
}
V_22 -> V_501 = V_634 ;
V_22 -> V_492 = V_633 ;
V_22 -> V_236 = V_236 ;
F_344 ( V_236 , & V_234 -> V_236 ) ;
V_235 = F_325 ( V_22 ) ;
if ( V_235 < 0 ) {
F_104 ( & V_234 -> V_236 , L_44 , V_24 ) ;
goto V_713;
}
F_324 ( V_22 ) ;
V_22 -> V_454 = F_327 ( struct V_534 ) ;
if ( ! V_22 -> V_454 ) {
V_235 = - V_151 ;
goto V_714;
}
F_148 (cpu) {
V_535 = F_193 ( V_22 -> V_454 , V_366 ) ;
F_345 ( & V_535 -> V_539 , V_715 ,
V_540 ) ;
V_535 -> V_539 . V_716 = F_245 ;
V_535 -> V_537 = false ;
F_346 ( & V_535 -> V_544 , F_243 ,
( unsigned long ) V_236 ) ;
}
F_347 ( V_236 , & V_22 -> V_518 , F_280 , V_717 ) ;
V_701 = V_718 | V_719 ;
V_236 -> V_701 = V_701 | V_720 ;
V_236 -> V_721 |= V_701 | V_720 | V_722 ;
V_236 -> V_723 |= V_701 ;
V_236 -> V_724 = V_725 ;
V_236 -> V_726 = 9676 ;
V_235 = F_348 ( V_236 ) ;
if ( V_235 < 0 ) {
F_104 ( & V_234 -> V_236 , L_45 ) ;
goto V_727;
}
F_293 ( V_236 , L_46 , V_699 , V_236 -> V_273 ) ;
* V_695 += V_359 ;
V_2 -> V_728 [ V_24 ] = V_22 ;
return 0 ;
V_727:
F_329 ( V_22 -> V_454 ) ;
V_714:
for ( V_29 = 0 ; V_29 < V_413 ; V_29 ++ )
F_329 ( V_22 -> V_415 [ V_29 ] -> V_454 ) ;
V_713:
F_329 ( V_22 -> V_587 ) ;
V_652:
F_349 ( V_22 -> V_516 ) ;
V_704:
F_350 ( V_643 ) ;
F_351 ( V_236 ) ;
return V_235 ;
}
static void F_352 ( struct V_21 * V_22 )
{
int V_29 ;
F_353 ( V_22 -> V_236 ) ;
F_350 ( V_22 -> V_643 ) ;
F_329 ( V_22 -> V_454 ) ;
F_329 ( V_22 -> V_587 ) ;
for ( V_29 = 0 ; V_29 < V_413 ; V_29 ++ )
F_329 ( V_22 -> V_415 [ V_29 ] -> V_454 ) ;
F_349 ( V_22 -> V_516 ) ;
F_351 ( V_22 -> V_236 ) ;
}
static void F_354 ( const struct V_729 * V_730 ,
struct V_1 * V_2 )
{
T_1 V_731 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ ) {
F_1 ( V_2 , F_355 ( V_29 ) , 0 ) ;
F_1 ( V_2 , F_356 ( V_29 ) , 0 ) ;
if ( V_29 < 4 )
F_1 ( V_2 , F_357 ( V_29 ) , 0 ) ;
}
V_731 = 0 ;
for ( V_29 = 0 ; V_29 < V_730 -> V_732 ; V_29 ++ ) {
const struct V_733 * V_734 = V_730 -> V_734 + V_29 ;
F_1 ( V_2 , F_355 ( V_29 ) ,
( V_734 -> V_5 & 0xffff0000 ) | ( V_734 -> V_735 << 8 ) |
V_730 -> V_736 ) ;
F_1 ( V_2 , F_356 ( V_29 ) ,
( V_734 -> V_9 - 1 ) & 0xffff0000 ) ;
V_731 |= ( 1 << V_29 ) ;
}
F_1 ( V_2 , V_737 , V_731 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_192 ; V_22 ++ ) {
F_1 ( V_2 , F_359 ( V_22 ) ,
V_738 ) ;
F_1 ( V_2 , F_360 ( V_22 ) ,
V_739 ) ;
}
F_1 ( V_2 , V_740 ,
V_741 ) ;
F_1 ( V_2 , V_742 , 0x1 ) ;
}
static int F_361 ( struct V_233 * V_234 , struct V_1 * V_2 )
{
const struct V_729 * V_743 ;
int V_235 , V_29 ;
T_1 V_67 ;
if ( V_359 % 4 || ( V_359 > V_744 ) ||
( V_413 > V_26 ) ) {
F_104 ( & V_234 -> V_236 , L_47 ) ;
return - V_32 ;
}
V_743 = F_362 () ;
if ( V_743 )
F_354 ( V_743 , V_2 ) ;
V_67 = F_4 ( V_2 -> V_638 + V_745 ) ;
V_67 |= V_746 ;
F_2 ( V_67 , V_2 -> V_638 + V_745 ) ;
V_2 -> V_605 = F_75 ( & V_234 -> V_236 , F_195 () ,
sizeof( struct V_414 ) ,
V_101 ) ;
if ( ! V_2 -> V_605 )
return - V_151 ;
F_148 (i) {
V_2 -> V_605 [ V_29 ] . V_24 = V_29 ;
V_2 -> V_605 [ V_29 ] . V_9 = V_747 ;
V_235 = F_216 ( V_234 , & V_2 -> V_605 [ V_29 ] ,
V_747 , V_29 , V_2 ) ;
if ( V_235 < 0 )
return V_235 ;
}
F_358 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < V_192 ; V_29 ++ )
F_1 ( V_2 , F_328 ( V_29 ) , V_359 ) ;
F_2 ( V_748 ,
V_2 -> V_638 + V_749 ) ;
F_1 ( V_2 , V_750 , 0x1 ) ;
V_235 = F_119 ( V_234 , V_2 ) ;
if ( V_235 < 0 )
return V_235 ;
V_235 = F_79 ( V_234 , V_2 ) ;
if ( V_235 < 0 )
return V_235 ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_363 ( struct V_233 * V_234 )
{
struct V_693 * V_751 = V_234 -> V_236 . V_752 ;
struct V_693 * V_694 ;
struct V_1 * V_2 ;
struct V_696 * V_697 ;
int V_753 , V_298 ;
int V_235 ;
V_2 = F_326 ( & V_234 -> V_236 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_2 )
return - V_151 ;
V_697 = F_337 ( V_234 , V_712 , 0 ) ;
V_2 -> V_5 = F_338 ( & V_234 -> V_236 , V_697 ) ;
if ( F_339 ( V_2 -> V_5 ) )
return F_340 ( V_2 -> V_5 ) ;
V_697 = F_337 ( V_234 , V_712 , 1 ) ;
V_2 -> V_638 = F_338 ( & V_234 -> V_236 , V_697 ) ;
if ( F_339 ( V_2 -> V_638 ) )
return F_340 ( V_2 -> V_638 ) ;
V_2 -> V_754 = F_364 ( & V_234 -> V_236 , L_48 ) ;
if ( F_339 ( V_2 -> V_754 ) )
return F_340 ( V_2 -> V_754 ) ;
V_235 = F_365 ( V_2 -> V_754 ) ;
if ( V_235 < 0 )
return V_235 ;
V_2 -> V_755 = F_364 ( & V_234 -> V_236 , L_49 ) ;
if ( F_339 ( V_2 -> V_755 ) ) {
V_235 = F_340 ( V_2 -> V_755 ) ;
goto V_756;
}
V_235 = F_365 ( V_2 -> V_755 ) ;
if ( V_235 < 0 )
goto V_756;
V_2 -> V_401 = F_366 ( V_2 -> V_754 ) ;
V_235 = F_361 ( V_234 , V_2 ) ;
if ( V_235 < 0 ) {
F_104 ( & V_234 -> V_236 , L_50 ) ;
goto V_757;
}
V_753 = F_367 ( V_751 ) ;
if ( V_753 == 0 ) {
F_104 ( & V_234 -> V_236 , L_51 ) ;
V_235 = - V_644 ;
goto V_757;
}
V_2 -> V_728 = F_75 ( & V_234 -> V_236 , V_753 ,
sizeof( struct V_21 * ) ,
V_101 ) ;
if ( ! V_2 -> V_728 ) {
V_235 = - V_151 ;
goto V_757;
}
V_298 = 0 ;
F_368 (dn, port_node) {
V_235 = F_330 ( V_234 , V_694 , V_2 , & V_298 ) ;
if ( V_235 < 0 )
goto V_757;
}
F_369 ( V_234 , V_2 ) ;
return 0 ;
V_757:
F_370 ( V_2 -> V_755 ) ;
V_756:
F_370 ( V_2 -> V_754 ) ;
return V_235 ;
}
static int F_371 ( struct V_233 * V_234 )
{
struct V_1 * V_2 = F_372 ( V_234 ) ;
struct V_693 * V_751 = V_234 -> V_236 . V_752 ;
struct V_693 * V_694 ;
int V_29 = 0 ;
F_368 (dn, port_node) {
if ( V_2 -> V_728 [ V_29 ] )
F_352 ( V_2 -> V_728 [ V_29 ] ) ;
V_29 ++ ;
}
for ( V_29 = 0 ; V_29 < V_322 ; V_29 ++ ) {
struct V_303 * V_304 = & V_2 -> V_323 [ V_29 ] ;
F_116 ( V_234 , V_2 , V_304 ) ;
}
F_148 (i) {
struct V_414 * V_443 = & V_2 -> V_605 [ V_29 ] ;
F_103 ( & V_234 -> V_236 ,
V_747 * V_490 ,
V_443 -> V_416 ,
V_443 -> V_491 ) ;
}
F_370 ( V_2 -> V_754 ) ;
F_370 ( V_2 -> V_755 ) ;
return 0 ;
}
