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
V_7 -> V_14 [ V_7 -> V_15 ] = V_11 ;
if ( V_11 )
V_7 -> V_16 [ V_7 -> V_15 ] =
V_13 -> V_17 ;
V_7 -> V_15 ++ ;
if ( V_7 -> V_15 == V_7 -> V_9 )
V_7 -> V_15 = 0 ;
}
static inline int F_7 ( struct V_18 * V_19 )
{
return V_20 + V_19 -> V_21 ;
}
static inline int F_8 ( int V_19 , int V_22 )
{
return ( V_20 + V_19 ) * V_23 + V_22 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_26 ;
if ( V_25 -> V_27 > V_28 - 1 )
return - V_29 ;
V_25 -> V_30 . V_31 [ V_32 ] &= ~ V_33 ;
F_1 ( V_2 , V_34 , V_25 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ )
F_1 ( V_2 , F_10 ( V_26 ) , V_25 -> V_30 . V_31 [ V_26 ] ) ;
F_1 ( V_2 , V_36 , V_25 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_37 ; V_26 ++ )
F_1 ( V_2 , F_11 ( V_26 ) , V_25 -> V_38 . V_31 [ V_26 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_26 ;
if ( V_25 -> V_27 > V_28 - 1 )
return - V_29 ;
F_1 ( V_2 , V_34 , V_25 -> V_27 ) ;
V_25 -> V_30 . V_31 [ V_32 ] = F_3 ( V_2 ,
F_10 ( V_32 ) ) ;
if ( V_25 -> V_30 . V_31 [ V_32 ] & V_33 )
return V_39 ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ )
V_25 -> V_30 . V_31 [ V_26 ] = F_3 ( V_2 , F_10 ( V_26 ) ) ;
F_1 ( V_2 , V_36 , V_25 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_37 ; V_26 ++ )
V_25 -> V_38 . V_31 [ V_26 ] = F_3 ( V_2 , F_11 ( V_26 ) ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , int V_27 )
{
F_1 ( V_2 , V_34 , V_27 ) ;
F_1 ( V_2 , F_10 ( V_32 ) ,
V_33 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_27 , int V_40 )
{
V_2 -> V_41 [ V_27 ] . V_42 = true ;
V_2 -> V_41 [ V_27 ] . V_40 = V_40 ;
}
static void F_15 ( struct V_1 * V_2 , int V_27 ,
unsigned int V_43 , unsigned int V_44 )
{
V_2 -> V_41 [ V_27 ] . V_44 = V_44 ;
V_2 -> V_41 [ V_27 ] . V_43 = V_43 ;
}
static void F_16 ( struct V_24 * V_25 , unsigned int V_40 )
{
int V_45 = F_17 ( V_46 ) ;
V_25 -> V_30 . V_47 [ V_46 ] = V_40 ;
V_25 -> V_30 . V_47 [ V_45 ] = V_48 ;
}
static void F_18 ( struct V_24 * V_25 ,
unsigned int V_19 , bool V_49 )
{
int V_45 = F_17 ( V_50 ) ;
if ( V_49 )
V_25 -> V_30 . V_47 [ V_45 ] &= ~ ( 1 << V_19 ) ;
else
V_25 -> V_30 . V_47 [ V_45 ] |= 1 << V_19 ;
}
static void F_19 ( struct V_24 * V_25 ,
unsigned int V_51 )
{
unsigned char V_52 = V_53 ;
int V_45 = F_17 ( V_50 ) ;
V_25 -> V_30 . V_47 [ V_50 ] = 0 ;
V_25 -> V_30 . V_47 [ V_45 ] &= ~ V_52 ;
V_25 -> V_30 . V_47 [ V_45 ] |= ~ V_51 & V_53 ;
}
static unsigned int F_20 ( struct V_24 * V_25 )
{
int V_45 = F_17 ( V_50 ) ;
return ~ ( V_25 -> V_30 . V_47 [ V_45 ] ) & V_53 ;
}
static void F_21 ( struct V_24 * V_25 ,
unsigned int V_54 , unsigned char V_47 ,
unsigned char V_55 )
{
V_25 -> V_30 . V_47 [ F_22 ( V_54 ) ] = V_47 ;
V_25 -> V_30 . V_47 [ F_23 ( V_54 ) ] = V_55 ;
}
static void F_24 ( struct V_24 * V_25 ,
unsigned int V_54 , unsigned char * V_47 ,
unsigned char * V_55 )
{
* V_47 = V_25 -> V_30 . V_47 [ F_22 ( V_54 ) ] ;
* V_55 = V_25 -> V_30 . V_47 [ F_23 ( V_54 ) ] ;
}
static bool F_25 ( struct V_24 * V_25 , int V_54 ,
T_2 V_4 )
{
int V_56 = F_22 ( V_54 ) ;
T_2 V_57 ;
V_57 = ( 8 << V_25 -> V_30 . V_47 [ V_56 + 1 ] ) | V_25 -> V_30 . V_47 [ V_56 ] ;
if ( V_57 != V_4 )
return false ;
return true ;
}
static void F_26 ( struct V_24 * V_25 ,
unsigned int V_58 , unsigned int V_55 )
{
int V_26 , V_59 = V_60 ;
for ( V_26 = 0 ; V_26 < V_61 ; V_26 ++ ) {
if ( ! ( V_55 & F_27 ( V_26 ) ) )
continue;
if ( V_58 & F_27 ( V_26 ) )
V_25 -> V_30 . V_47 [ V_59 ] |= 1 << V_26 ;
else
V_25 -> V_30 . V_47 [ V_59 ] &= ~ ( 1 << V_26 ) ;
}
V_25 -> V_30 . V_47 [ F_17 ( V_59 ) ] |= V_55 ;
}
static int F_28 ( struct V_24 * V_25 )
{
return V_25 -> V_30 . V_47 [ V_60 ] ;
}
static void F_29 ( struct V_24 * V_25 , int V_3 ,
unsigned short V_62 )
{
F_21 ( V_25 , V_3 + 0 , V_62 >> 8 , 0xff ) ;
F_21 ( V_25 , V_3 + 1 , V_62 & 0xff , 0xff ) ;
}
static void F_30 ( struct V_24 * V_25 , int V_63 ,
int V_64 )
{
V_25 -> V_38 . V_47 [ F_31 ( V_63 ) ] |= ( V_64 << ( V_63 % 8 ) ) ;
}
static void F_32 ( struct V_24 * V_25 , int V_63 ,
int V_64 )
{
V_25 -> V_38 . V_47 [ F_31 ( V_63 ) ] &= ~ ( V_64 << ( V_63 % 8 ) ) ;
}
static void F_33 ( struct V_24 * V_25 ,
unsigned int V_58 , unsigned int V_65 )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < V_66 ; V_26 ++ ) {
int V_67 = V_68 ;
if ( ! ( V_65 & F_27 ( V_26 ) ) )
continue;
if ( V_58 & F_27 ( V_26 ) )
F_30 ( V_25 , V_67 + V_26 , 1 ) ;
else
F_32 ( V_25 , V_67 + V_26 , 1 ) ;
F_30 ( V_25 , V_69 + V_26 , 1 ) ;
}
}
static int F_34 ( struct V_24 * V_25 )
{
return V_25 -> V_38 . V_31 [ V_70 ] ;
}
static void F_35 ( struct V_24 * V_25 ,
unsigned int V_58 , unsigned int V_65 )
{
unsigned int V_26 ;
int V_71 = V_72 ;
for ( V_26 = 0 ; V_26 < V_73 ; V_26 ++ ) {
if ( ! ( V_65 & F_27 ( V_26 ) ) )
continue;
if ( V_58 & F_27 ( V_26 ) )
F_30 ( V_25 , V_71 + V_26 , 1 ) ;
else
F_32 ( V_25 , V_71 + V_26 , 1 ) ;
F_30 ( V_25 , V_74 + V_26 , 1 ) ;
}
}
static int F_36 ( struct V_24 * V_25 )
{
T_3 V_58 ;
int V_71 = F_31 ( V_72 ) ;
int V_75 = V_71 + 1 ;
int V_76 = V_72 % 8 ;
V_58 = ( V_25 -> V_38 . V_47 [ V_71 ] >> V_76 ) |
( V_25 -> V_38 . V_47 [ V_75 ] << ( 8 - V_76 ) ) ;
return V_58 ;
}
static void F_37 ( struct V_24 * V_25 ,
unsigned int V_40 )
{
int V_77 = V_78 ;
F_32 ( V_25 , V_77 ,
V_79 ) ;
F_30 ( V_25 , V_77 , V_40 ) ;
}
static void F_38 ( struct V_24 * V_25 , int V_80 ,
unsigned int V_81 )
{
if ( V_80 < 0 ) {
F_30 ( V_25 , V_82 , 1 ) ;
V_80 = 0 - V_80 ;
} else {
F_32 ( V_25 , V_82 , 1 ) ;
}
V_25 -> V_38 . V_47 [ F_31 ( V_83 ) ] =
( unsigned char ) V_80 ;
F_32 ( V_25 , V_84 ,
V_85 ) ;
F_30 ( V_25 , V_84 , V_81 ) ;
F_32 ( V_25 , V_86 , 1 ) ;
}
static void F_39 ( struct V_24 * V_25 ,
unsigned int type , int V_3 ,
unsigned int V_81 )
{
if ( V_3 < 0 ) {
F_30 ( V_25 , V_87 , 1 ) ;
V_3 = 0 - V_3 ;
} else {
F_32 ( V_25 , V_87 , 1 ) ;
}
F_32 ( V_25 , V_88 ,
V_89 ) ;
F_30 ( V_25 , V_88 , V_3 ) ;
V_25 -> V_38 . V_47 [ F_31 ( V_88 +
V_90 ) ] &=
~ ( V_89 >> ( 8 - ( V_88 % 8 ) ) ) ;
V_25 -> V_38 . V_47 [ F_31 ( V_88 +
V_90 ) ] |=
( V_3 >> ( 8 - ( V_88 % 8 ) ) ) ;
F_32 ( V_25 , V_91 ,
V_92 ) ;
F_30 ( V_25 , V_91 , type ) ;
F_32 ( V_25 , V_93 ,
V_94 ) ;
F_30 ( V_25 , V_93 , V_81 ) ;
V_25 -> V_38 . V_47 [ F_31 ( V_93 +
V_95 ) ] &=
~ ( V_94 >>
( 8 - ( V_93 % 8 ) ) ) ;
V_25 -> V_38 . V_47 [ F_31 ( V_93 +
V_95 ) ] |=
( V_81 >> ( 8 - ( V_93 % 8 ) ) ) ;
F_32 ( V_25 , V_86 , 1 ) ;
}
static struct V_24 * F_40 ( struct V_1 * V_2 , int V_96 )
{
struct V_24 * V_25 ;
int V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return NULL ;
F_16 ( V_25 , V_99 ) ;
for ( V_97 = V_28 - 1 ; V_97 >= 0 ; V_97 -- ) {
T_3 V_58 ;
if ( ! V_2 -> V_41 [ V_97 ] . V_42 ||
V_2 -> V_41 [ V_97 ] . V_40 != V_99 )
continue;
V_25 -> V_27 = V_97 ;
F_12 ( V_2 , V_25 ) ;
V_58 = F_36 ( V_25 ) ;
if ( ( V_58 & V_100 ) == V_96 )
return V_25 ;
}
F_42 ( V_25 ) ;
return NULL ;
}
static int F_43 ( struct V_1 * V_2 , unsigned char V_101 ,
unsigned char V_102 )
{
int V_97 ;
if ( V_101 > V_102 )
F_44 ( V_101 , V_102 ) ;
if ( V_102 >= V_28 )
V_102 = V_28 - 1 ;
for ( V_97 = V_101 ; V_97 <= V_102 ; V_97 ++ ) {
if ( ! V_2 -> V_41 [ V_97 ] . V_42 )
return V_97 ;
}
return - V_29 ;
}
static void F_45 ( struct V_1 * V_2 , int V_19 , bool V_49 )
{
struct V_24 V_25 ;
if ( V_2 -> V_41 [ V_103 ] . V_42 ) {
V_25 . V_27 = V_103 ;
F_12 ( V_2 , & V_25 ) ;
} else {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_104 ) ;
V_25 . V_27 = V_103 ;
F_33 ( & V_25 , V_105 ,
V_105 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_37 ( & V_25 , V_99 ) ;
F_14 ( V_2 , V_25 . V_27 , V_104 ) ;
F_19 ( & V_25 , 0 ) ;
}
F_18 ( & V_25 , V_19 , V_49 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static void F_46 ( struct V_1 * V_2 , int V_19 , bool V_49 )
{
struct V_24 V_25 ;
if ( V_2 -> V_41 [ V_107 ] . V_42 ) {
V_25 . V_27 = V_107 ;
F_12 ( V_2 , & V_25 ) ;
} else {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_104 ) ;
V_25 . V_27 = V_107 ;
F_37 ( & V_25 , V_108 ) ;
F_33 ( & V_25 , V_109 ,
V_110 ) ;
F_38 ( & V_25 , 2 * V_111 ,
V_112 ) ;
F_19 ( & V_25 , 0 ) ;
F_14 ( V_2 , V_25 . V_27 , V_104 ) ;
}
F_18 ( & V_25 , V_19 , V_49 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_19 , int V_27 ,
bool V_49 )
{
struct V_24 V_25 ;
unsigned char V_113 ;
V_113 = ( V_27 == V_114 ) ? 0x01 : 0x33 ;
if ( V_2 -> V_41 [ V_27 ] . V_42 ) {
V_25 . V_27 = V_27 ;
F_12 ( V_2 , & V_25 ) ;
} else {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_104 ) ;
V_25 . V_27 = V_27 ;
F_37 ( & V_25 , V_108 ) ;
F_33 ( & V_25 , V_115 ,
V_110 ) ;
F_21 ( & V_25 , 0 , V_113 , 0xff ) ;
F_38 ( & V_25 , 2 * V_111 ,
V_112 ) ;
F_19 ( & V_25 , 0 ) ;
F_14 ( V_2 , V_25 . V_27 , V_104 ) ;
}
F_18 ( & V_25 , V_19 , V_49 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_19 , bool V_49 ,
bool V_116 , bool V_117 )
{
struct V_24 V_25 ;
int V_97 , V_80 ;
if ( V_117 ) {
V_97 = V_116 ? V_118 : V_119 ;
V_80 = 8 ;
} else {
V_97 = V_116 ? V_120 : V_121 ;
V_80 = 4 ;
}
if ( V_2 -> V_41 [ V_97 ] . V_42 ) {
V_25 . V_27 = V_97 ;
F_12 ( V_2 , & V_25 ) ;
} else {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_108 ) ;
V_25 . V_27 = V_97 ;
F_38 ( & V_25 , V_80 ,
V_112 ) ;
F_14 ( V_2 , V_25 . V_27 , V_108 ) ;
if ( V_116 ) {
F_21 ( & V_25 , 0 ,
V_122 ,
V_122 ) ;
F_35 ( & V_25 , 0 ,
V_123 ) ;
F_37 ( & V_25 , V_124 ) ;
} else {
F_33 ( & V_25 , V_125 ,
V_126 ) ;
F_37 ( & V_25 , V_127 ) ;
}
F_19 ( & V_25 , 0 ) ;
}
F_18 ( & V_25 , V_19 , V_49 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_19 ,
bool V_49 , bool V_116 , bool V_117 )
{
struct V_24 V_25 ;
int V_97 , V_80 , V_52 ;
if ( V_117 ) {
V_97 = V_116 ? V_128 :
V_129 ;
V_52 = 0 ;
V_80 = 8 ;
} else {
V_97 = V_116 ? V_130 :
V_131 ;
V_52 = V_53 ;
V_80 = 4 ;
}
if ( V_2 -> V_41 [ V_97 ] . V_42 ) {
V_25 . V_27 = V_97 ;
F_12 ( V_2 , & V_25 ) ;
} else {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_108 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_132 ) ;
F_29 ( & V_25 , 2 , 0 ) ;
F_33 ( & V_25 , V_133 ,
V_133 ) ;
F_38 ( & V_25 , 2 + V_134 + V_80 ,
V_112 ) ;
F_14 ( V_2 , V_25 . V_27 , V_108 ) ;
if ( V_116 ) {
F_21 ( & V_25 ,
V_134 + 2 + 3 ,
V_122 ,
V_122 ) ;
F_35 ( & V_25 , 0 ,
V_123 ) ;
F_37 ( & V_25 , V_124 ) ;
} else {
F_33 ( & V_25 , V_125 ,
V_126 ) ;
F_37 ( & V_25 , V_127 ) ;
}
F_19 ( & V_25 , V_52 ) ;
}
F_18 ( & V_25 , V_19 , V_49 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static struct V_24 * F_50 ( struct V_1 * V_2 ,
unsigned short V_135 , int V_136 )
{
struct V_24 * V_25 ;
int V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return NULL ;
F_16 ( V_25 , V_124 ) ;
for ( V_97 = V_137 ;
V_97 <= V_138 ; V_97 ++ ) {
unsigned int V_139 , V_140 ;
bool V_141 ;
if ( ! V_2 -> V_41 [ V_97 ] . V_42 ||
V_2 -> V_41 [ V_97 ] . V_40 != V_124 )
continue;
V_25 -> V_27 = V_97 ;
F_12 ( V_2 , V_25 ) ;
V_141 = F_25 ( V_25 , 0 , F_51 ( V_135 ) ) ;
if ( ! V_141 )
continue;
V_139 = F_34 ( V_25 ) ;
V_139 &= V_126 ;
V_140 = F_28 ( V_25 ) ;
V_140 &= ~ V_142 ;
if ( V_136 != V_140 )
continue;
if ( V_139 == V_143 ||
V_139 == V_144 )
return V_25 ;
}
F_42 ( V_25 ) ;
return NULL ;
}
static int F_52 ( struct V_1 * V_2 , unsigned short V_135 , int V_136 ,
unsigned int V_145 )
{
struct V_24 * V_25 ;
int V_146 , V_97 ;
int V_147 = 0 ;
V_25 = F_50 ( V_2 , V_135 , V_136 ) ;
if ( ! V_25 ) {
V_97 = F_43 ( V_2 , V_138 ,
V_137 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return - V_148 ;
for ( V_146 = V_138 ;
V_146 >= V_137 ; V_146 -- ) {
unsigned int V_139 ;
if ( ! V_2 -> V_41 [ V_146 ] . V_42 ||
V_2 -> V_41 [ V_146 ] . V_40 != V_124 )
continue;
V_25 -> V_27 = V_146 ;
F_12 ( V_2 , V_25 ) ;
V_139 = F_34 ( V_25 ) ;
if ( ( V_139 & V_126 ) ==
V_149 )
break;
}
if ( V_97 <= V_146 ) {
V_147 = - V_29 ;
goto error;
}
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( V_25 , V_124 ) ;
V_25 -> V_27 = V_97 ;
F_29 ( V_25 , 0 , V_135 ) ;
F_37 ( V_25 , V_127 ) ;
F_38 ( V_25 , V_150 ,
V_112 ) ;
F_35 ( V_25 , 0 , V_123 ) ;
if ( V_136 == V_151 ) {
F_33 ( V_25 , V_143 ,
V_126 ) ;
} else {
V_136 |= V_142 ;
F_33 ( V_25 , V_144 ,
V_126 ) ;
}
F_26 ( V_25 , V_136 , V_123 ) ;
F_14 ( V_2 , V_25 -> V_27 , V_124 ) ;
}
F_19 ( V_25 , V_145 ) ;
F_9 ( V_2 , V_25 ) ;
error:
F_42 ( V_25 ) ;
return V_147 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_26 ;
for ( V_26 = 1 ; V_26 < V_152 ; V_26 ++ ) {
if ( ! V_2 -> V_153 [ V_26 ] )
return V_26 ;
}
return - V_29 ;
}
static struct V_24 * F_54 ( struct V_1 * V_2 ,
unsigned short V_154 ,
unsigned short V_155 )
{
struct V_24 * V_25 ;
int V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return NULL ;
F_16 ( V_25 , V_124 ) ;
for ( V_97 = V_137 ;
V_97 <= V_138 ; V_97 ++ ) {
unsigned int V_44 ;
bool V_141 ;
if ( ! V_2 -> V_41 [ V_97 ] . V_42 ||
V_2 -> V_41 [ V_97 ] . V_40 != V_124 )
continue;
V_25 -> V_27 = V_97 ;
F_12 ( V_2 , V_25 ) ;
V_141 = F_25 ( V_25 , 0 , F_51 ( V_154 ) )
&& F_25 ( V_25 , 4 , F_51 ( V_155 ) ) ;
if ( ! V_141 )
continue;
V_44 = F_34 ( V_25 ) & V_126 ;
if ( V_44 == V_149 )
return V_25 ;
}
F_42 ( V_25 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , unsigned short V_154 ,
unsigned short V_155 ,
unsigned int V_145 )
{
struct V_24 * V_25 ;
int V_146 , V_97 , V_136 , V_147 = 0 ;
V_25 = F_54 ( V_2 , V_154 , V_155 ) ;
if ( ! V_25 ) {
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return - V_148 ;
V_136 = F_53 ( V_2 ) ;
if ( V_136 < 0 ) {
V_147 = V_136 ;
goto error;
}
for ( V_146 = V_137 ;
V_146 <= V_138 ; V_146 ++ ) {
unsigned int V_139 ;
if ( ! V_2 -> V_41 [ V_146 ] . V_42 ||
V_2 -> V_41 [ V_146 ] . V_40 != V_124 )
continue;
V_25 -> V_27 = V_146 ;
F_12 ( V_2 , V_25 ) ;
V_139 = F_34 ( V_25 ) ;
V_139 &= V_126 ;
if ( V_139 == V_143 ||
V_139 == V_144 )
break;
}
if ( V_97 >= V_146 ) {
V_147 = - V_156 ;
goto error;
}
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( V_25 , V_124 ) ;
V_25 -> V_27 = V_97 ;
V_2 -> V_153 [ V_136 ] = true ;
F_29 ( V_25 , 0 , V_154 ) ;
F_29 ( V_25 , 4 , V_155 ) ;
F_37 ( V_25 , V_124 ) ;
F_38 ( V_25 , 2 * V_150 ,
V_112 ) ;
F_33 ( V_25 , V_149 ,
V_126 ) ;
F_35 ( V_25 , V_136 | V_142 ,
V_123 ) ;
F_14 ( V_2 , V_25 -> V_27 , V_124 ) ;
}
F_19 ( V_25 , V_145 ) ;
F_9 ( V_2 , V_25 ) ;
error:
F_42 ( V_25 ) ;
return V_147 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned short V_157 ,
unsigned int V_43 , unsigned int V_44 )
{
struct V_24 V_25 ;
int V_97 ;
if ( ( V_157 != V_158 ) && ( V_157 != V_159 ) &&
( V_157 != V_160 ) )
return - V_29 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_161 ) ;
V_25 . V_27 = V_97 ;
F_37 ( & V_25 , V_161 ) ;
F_38 ( & V_25 , 12 , V_112 ) ;
F_39 ( & V_25 , V_162 ,
sizeof( struct V_163 ) - 4 ,
V_164 ) ;
F_35 ( & V_25 , V_165 ,
V_165 ) ;
F_33 ( & V_25 , V_43 | V_166 ,
V_44 | V_166 ) ;
F_21 ( & V_25 , 5 , V_157 , V_167 ) ;
F_26 ( & V_25 , 0 , V_165 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 . V_27 = V_97 ;
V_25 . V_38 . V_31 [ V_70 ] = 0x0 ;
V_25 . V_38 . V_31 [ V_168 ] = 0x0 ;
F_33 ( & V_25 , V_43 , V_44 ) ;
F_21 ( & V_25 , 2 , 0x00 , V_169 ) ;
F_21 ( & V_25 , 3 , 0x00 , V_167 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned short V_170 )
{
struct V_24 V_25 ;
int V_65 , V_97 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_161 ) ;
V_25 . V_27 = V_97 ;
switch ( V_170 ) {
case V_171 :
F_21 ( & V_25 , 0 , V_172 ,
V_173 ) ;
F_33 ( & V_25 , V_174 ,
V_175 ) ;
break;
case V_176 :
V_65 = V_177 ;
F_21 ( & V_25 , 0 , V_65 , V_65 ) ;
F_21 ( & V_25 , 1 , V_65 , V_65 ) ;
F_21 ( & V_25 , 2 , V_65 , V_65 ) ;
F_21 ( & V_25 , 3 , V_65 , V_65 ) ;
F_33 ( & V_25 , V_178 ,
V_175 ) ;
break;
default:
return - V_29 ;
}
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_26 ( & V_25 , V_165 ,
V_165 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned short V_157 ,
unsigned int V_43 , unsigned int V_44 )
{
struct V_24 V_25 ;
int V_97 ;
if ( ( V_157 != V_158 ) && ( V_157 != V_159 ) &&
( V_157 != V_179 ) && ( V_157 != V_180 ) )
return - V_29 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_181 ) ;
V_25 . V_27 = V_97 ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_43 , V_44 ) ;
F_39 ( & V_25 , V_162 ,
sizeof( struct V_182 ) - 6 ,
V_164 ) ;
F_21 ( & V_25 , 0 , V_157 , V_167 ) ;
F_26 ( & V_25 , V_183 ,
V_183 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_181 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned short V_170 )
{
struct V_24 V_25 ;
int V_97 ;
if ( V_170 != V_171 )
return - V_29 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_181 ) ;
V_25 . V_27 = V_97 ;
F_37 ( & V_25 , V_181 ) ;
F_33 ( & V_25 , V_174 ,
V_175 ) ;
F_35 ( & V_25 , V_183 ,
V_183 ) ;
F_38 ( & V_25 , - 18 , V_112 ) ;
F_21 ( & V_25 , 0 , V_184 ,
V_185 ) ;
F_26 ( & V_25 , 0 , V_183 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_181 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_19 , int V_186 ,
int V_187 , int V_3 )
{
T_1 V_64 ;
V_64 = F_3 ( V_2 , V_188 ) ;
V_64 &= ~ F_61 ( V_19 ) ;
V_64 |= F_62 ( V_19 , V_186 ) ;
F_1 ( V_2 , V_188 , V_64 ) ;
V_64 = F_3 ( V_2 , F_63 ( V_19 ) ) ;
V_64 &= ~ F_64 ( V_19 ) ;
V_64 |= F_65 ( V_19 , V_187 ) ;
F_1 ( V_2 , F_63 ( V_19 ) , V_64 ) ;
V_64 = F_3 ( V_2 , F_66 ( V_19 ) ) ;
V_64 &= ~ F_67 ( V_19 ) ;
V_64 |= F_68 ( V_19 , V_3 ) ;
F_1 ( V_2 , F_66 ( V_19 ) , V_64 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_189 ; V_19 ++ ) {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_99 ) ;
V_25 . V_27 = V_190 - V_19 ;
F_19 ( & V_25 , 0 ) ;
F_35 ( & V_25 , V_19 , V_100 ) ;
F_30 ( & V_25 , V_191 , 1 ) ;
F_14 ( V_2 , V_25 . V_27 , V_99 ) ;
F_9 ( V_2 , & V_25 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 . V_27 = V_192 ;
F_16 ( & V_25 , V_193 ) ;
F_38 ( & V_25 , V_194 ,
V_112 ) ;
F_37 ( & V_25 , V_104 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_193 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 . V_27 = V_195 ;
F_16 ( & V_25 , V_104 ) ;
F_33 ( & V_25 , V_105 ,
V_105 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_37 ( & V_25 , V_99 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_104 ) ;
F_9 ( V_2 , & V_25 ) ;
F_45 ( V_2 , 0 , false ) ;
F_46 ( V_2 , 0 , false ) ;
F_47 ( V_2 , V_114 , 0 , false ) ;
F_47 ( V_2 , V_196 , 0 , false ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
F_48 ( V_2 , 0 , false , V_197 ,
V_198 ) ;
F_48 ( V_2 , 0 , false , V_199 , V_198 ) ;
F_48 ( V_2 , 0 , false , V_197 ,
V_200 ) ;
F_48 ( V_2 , 0 , false , V_199 , V_200 ) ;
F_49 ( V_2 , 0 , false ,
V_197 , V_198 ) ;
F_49 ( V_2 , 0 , false ,
V_199 , V_198 ) ;
F_49 ( V_2 , 0 , true ,
V_197 , V_200 ) ;
F_49 ( V_2 , 0 , true ,
V_199 , V_200 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_108 ) ;
V_25 . V_27 = V_201 ;
F_37 ( & V_25 , V_124 ) ;
F_38 ( & V_25 , 0 , V_112 ) ;
F_14 ( V_2 , V_25 . V_27 , V_104 ) ;
F_35 ( & V_25 , 0 , V_123 ) ;
F_19 ( & V_25 , V_53 ) ;
F_9 ( V_2 , & V_25 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_97 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_127 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_202 ) ;
F_38 ( & V_25 , V_203 ,
V_112 ) ;
F_37 ( & V_25 , V_204 ) ;
F_33 ( & V_25 , V_205 ,
V_205 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = false ;
F_15 ( V_2 , V_25 . V_27 , V_205 ,
V_205 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_127 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_209 ) ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_210 ,
V_211 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = true ;
F_15 ( V_2 , V_25 . V_27 , V_210 ,
V_211 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_127 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_213 ) ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_214 |
V_215 ,
V_216 |
V_217 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = true ;
F_15 ( V_2 , V_25 . V_27 , V_214 |
V_215 ,
V_216 |
V_217 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_127 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_218 ) ;
F_21 ( & V_25 , V_134 ,
V_219 | V_220 ,
V_221 |
V_222 ) ;
F_37 ( & V_25 , V_161 ) ;
F_33 ( & V_25 , V_223 ,
V_211 ) ;
F_38 ( & V_25 , V_134 + 4 ,
V_112 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = false ;
F_15 ( V_2 , V_25 . V_27 , V_223 ,
V_211 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 . V_27 = V_97 ;
V_25 . V_30 . V_47 [ F_22 ( V_134 ) ] = 0x0 ;
V_25 . V_30 . V_47 [ F_23 ( V_134 ) ] = 0x0 ;
F_21 ( & V_25 , V_134 ,
V_219 ,
V_221 ) ;
V_25 . V_38 . V_31 [ V_70 ] = 0x0 ;
V_25 . V_38 . V_31 [ V_168 ] = 0x0 ;
F_33 ( & V_25 , V_224 ,
V_211 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = false ;
F_15 ( V_2 , V_25 . V_27 , V_224 ,
V_211 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_127 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_225 ) ;
F_38 ( & V_25 , V_134 + 8 +
V_226 ,
V_112 ) ;
F_37 ( & V_25 , V_181 ) ;
F_33 ( & V_25 , V_227 ,
V_211 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = false ;
F_15 ( V_2 , V_25 . V_27 , V_227 ,
V_211 ) ;
F_9 ( V_2 , & V_25 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_127 ) ;
V_25 . V_27 = V_228 ;
F_19 ( & V_25 , V_53 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_37 ( & V_25 , V_99 ) ;
F_33 ( & V_25 , V_229 ,
V_211 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_127 ) ;
V_2 -> V_41 [ V_25 . V_27 ] . V_206 = V_207 ;
V_2 -> V_41 [ V_25 . V_27 ] . V_208 = true ;
F_15 ( V_2 , V_25 . V_27 , V_229 ,
V_211 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_74 ( struct V_230 * V_231 , struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_232 ;
V_2 -> V_153 = F_75 ( & V_231 -> V_233 , sizeof( bool ) ,
V_152 ,
V_98 ) ;
if ( ! V_2 -> V_153 )
return - V_148 ;
V_232 = F_55 ( V_2 , V_234 , V_235 ,
V_53 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_55 ( V_2 , V_234 , V_234 ,
V_53 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_52 ( V_2 , V_235 , V_151 ,
V_53 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_52 ( V_2 , V_234 , V_151 ,
V_53 ) ;
if ( V_232 )
return V_232 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_124 ) ;
V_25 . V_27 = V_236 ;
F_37 ( & V_25 , V_127 ) ;
F_35 ( & V_25 , 0 , V_123 ) ;
F_33 ( & V_25 , V_149 ,
V_126 ) ;
F_26 ( & V_25 , V_142 ,
V_142 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_124 ) ;
F_9 ( V_2 , & V_25 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_124 ) ;
V_25 . V_27 = V_237 ;
F_37 ( & V_25 , V_127 ) ;
F_33 ( & V_25 , V_125 ,
V_126 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_124 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_97 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_204 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_238 ) ;
F_37 ( & V_25 , V_161 ) ;
F_33 ( & V_25 , V_224 ,
V_211 ) ;
F_38 ( & V_25 , V_134 + 4 ,
V_112 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_204 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 . V_27 = V_97 ;
F_21 ( & V_25 , V_134 ,
V_219 | V_220 ,
V_221 |
V_222 ) ;
V_25 . V_38 . V_31 [ V_70 ] = 0x0 ;
V_25 . V_38 . V_31 [ V_168 ] = 0x0 ;
F_33 ( & V_25 , V_223 ,
V_211 ) ;
F_14 ( V_2 , V_25 . V_27 , V_204 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_204 ) ;
V_25 . V_27 = V_97 ;
F_29 ( & V_25 , 0 , V_239 ) ;
F_37 ( & V_25 , V_181 ) ;
F_33 ( & V_25 , V_227 ,
V_211 ) ;
F_38 ( & V_25 , V_134 + 4 ,
V_112 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_204 ) ;
F_9 ( V_2 , & V_25 ) ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_204 ) ;
V_25 . V_27 = V_97 ;
F_33 ( & V_25 , V_229 ,
V_211 ) ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_39 ( & V_25 , V_212 ,
V_134 ,
V_164 ) ;
F_14 ( V_2 , V_25 . V_27 , V_204 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_232 ;
V_232 = F_56 ( V_2 , V_158 , V_240 ,
V_241 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_56 ( V_2 , V_159 , V_242 ,
V_241 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_56 ( V_2 , V_160 ,
V_214 |
V_215 ,
V_216 |
V_217 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_57 ( V_2 , V_176 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_57 ( V_2 , V_171 ) ;
if ( V_232 )
return V_232 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_161 ) ;
V_25 . V_27 = V_243 ;
F_37 ( & V_25 , V_161 ) ;
F_38 ( & V_25 , 12 , V_112 ) ;
F_39 ( & V_25 , V_162 ,
sizeof( struct V_163 ) - 4 ,
V_164 ) ;
F_35 ( & V_25 , V_165 ,
V_165 ) ;
F_33 ( & V_25 , V_244 ,
V_241 ) ;
F_26 ( & V_25 , 0 , V_165 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_161 ) ;
V_25 . V_27 = V_245 ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_246 ,
V_175 ) ;
F_26 ( & V_25 , V_165 ,
V_165 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_97 , V_232 ;
V_232 = F_58 ( V_2 , V_158 ,
V_240 ,
V_241 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_58 ( V_2 , V_159 ,
V_242 ,
V_241 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_58 ( V_2 , V_179 ,
V_214 |
V_215 ,
V_216 |
V_217 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_58 ( V_2 , V_180 ,
V_247 ,
V_248 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_59 ( V_2 , V_171 ) ;
if ( V_232 )
return V_232 ;
V_97 = F_43 ( V_2 , V_137 ,
V_138 ) ;
if ( V_97 < 0 )
return V_97 ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_181 ) ;
V_25 . V_27 = V_97 ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_229 |
V_105 ,
V_211 |
V_105 ) ;
F_21 ( & V_25 , 1 , 0x00 , V_249 ) ;
F_26 ( & V_25 , V_183 ,
V_183 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_181 ) ;
V_25 . V_27 = V_250 ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_244 ,
V_241 ) ;
F_39 ( & V_25 , V_162 ,
sizeof( struct V_182 ) - 4 ,
V_164 ) ;
F_26 ( & V_25 , V_183 ,
V_183 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_181 ) ;
V_25 . V_27 = V_251 ;
F_37 ( & V_25 , V_99 ) ;
F_30 ( & V_25 , V_106 , 1 ) ;
F_33 ( & V_25 , V_244 ,
V_241 ) ;
F_26 ( & V_25 , V_252 ,
V_252 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_161 ) ;
F_9 ( V_2 , & V_25 ) ;
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
F_16 ( & V_25 , V_181 ) ;
V_25 . V_27 = V_253 ;
F_37 ( & V_25 , V_181 ) ;
F_33 ( & V_25 , V_246 ,
V_175 ) ;
F_35 ( & V_25 , V_183 ,
V_183 ) ;
F_38 ( & V_25 , - 18 , V_112 ) ;
F_26 ( & V_25 , 0 , V_183 ) ;
F_19 ( & V_25 , V_53 ) ;
F_14 ( V_2 , V_25 . V_27 , V_181 ) ;
F_9 ( V_2 , & V_25 ) ;
return 0 ;
}
static int F_79 ( struct V_230 * V_231 ,
struct V_1 * V_2 )
{
int V_232 , V_27 , V_26 ;
F_1 ( V_2 , V_254 , V_255 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_1 ( V_2 , V_34 , V_27 ) ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ )
F_1 ( V_2 , F_10 ( V_26 ) , 0 ) ;
F_1 ( V_2 , V_36 , V_27 ) ;
for ( V_26 = 0 ; V_26 < V_37 ; V_26 ++ )
F_1 ( V_2 , F_11 ( V_26 ) , 0 ) ;
}
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
F_13 ( V_2 , V_27 ) ;
V_2 -> V_41 = F_75 ( & V_231 -> V_233 , V_28 ,
sizeof( struct V_256 ) ,
V_98 ) ;
if ( ! V_2 -> V_41 )
return - V_148 ;
for ( V_27 = 0 ; V_27 < V_189 ; V_27 ++ )
F_60 ( V_2 , V_27 , V_193 ,
V_257 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
V_232 = F_73 ( V_2 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_74 ( V_231 , V_2 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_76 ( V_2 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_78 ( V_2 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_77 ( V_2 ) ;
if ( V_232 )
return V_232 ;
return 0 ;
}
static bool F_80 ( struct V_24 * V_25 ,
const T_3 * V_258 , unsigned char * V_65 )
{
unsigned char V_259 , V_260 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_111 ; V_27 ++ ) {
F_24 ( V_25 , V_27 , & V_259 , & V_260 ) ;
if ( V_260 != V_65 [ V_27 ] )
return false ;
if ( ( V_260 & V_259 ) != ( V_258 [ V_27 ] & V_65 [ V_27 ] ) )
return false ;
}
return true ;
}
static struct V_24 *
F_81 ( struct V_1 * V_2 , int V_261 , const T_3 * V_258 ,
unsigned char * V_65 , int V_262 )
{
struct V_24 * V_25 ;
int V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return NULL ;
F_16 ( V_25 , V_104 ) ;
for ( V_97 = V_137 ;
V_97 <= V_138 ; V_97 ++ ) {
unsigned int V_263 ;
if ( ! V_2 -> V_41 [ V_97 ] . V_42 ||
( V_2 -> V_41 [ V_97 ] . V_40 != V_104 ) ||
( V_2 -> V_41 [ V_97 ] . V_206 != V_262 ) )
continue;
V_25 -> V_27 = V_97 ;
F_12 ( V_2 , V_25 ) ;
V_263 = F_20 ( V_25 ) ;
if ( F_80 ( V_25 , V_258 , V_65 ) &&
V_263 == V_261 )
return V_25 ;
}
F_42 ( V_25 ) ;
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_19 ,
const T_3 * V_258 , bool V_49 )
{
struct V_24 * V_25 ;
unsigned int V_261 , V_264 , V_43 ;
unsigned char V_65 [ V_111 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_97 ;
V_25 = F_81 ( V_2 , ( 1 << V_19 ) , V_258 , V_65 ,
V_265 ) ;
if ( ! V_25 ) {
if ( ! V_49 )
return 0 ;
for ( V_97 = V_137 ;
V_97 <= V_138 ; V_97 ++ )
if ( V_2 -> V_41 [ V_97 ] . V_42 &&
( V_2 -> V_41 [ V_97 ] . V_40 == V_104 ) &&
( V_2 -> V_41 [ V_97 ] . V_206 ==
V_266 ) )
break;
V_97 = F_43 ( V_2 , V_137 ,
V_97 - 1 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return - V_148 ;
F_16 ( V_25 , V_104 ) ;
V_25 -> V_27 = V_97 ;
F_19 ( V_25 , 0 ) ;
}
F_18 ( V_25 , V_19 , V_49 ) ;
V_261 = F_20 ( V_25 ) ;
if ( V_261 == 0 ) {
if ( V_49 ) {
F_42 ( V_25 ) ;
return - V_29 ;
}
F_13 ( V_2 , V_25 -> V_27 ) ;
V_2 -> V_41 [ V_25 -> V_27 ] . V_42 = false ;
F_42 ( V_25 ) ;
return 0 ;
}
F_37 ( V_25 , V_108 ) ;
V_264 = V_111 ;
while ( V_264 -- )
F_21 ( V_25 , V_264 , V_258 [ V_264 ] , 0xff ) ;
if ( F_83 ( V_258 ) )
V_43 = V_267 ;
else if ( F_84 ( V_258 ) )
V_43 = V_115 ;
else
V_43 = V_109 | V_268 ;
F_33 ( V_25 , V_43 , V_110 |
V_268 ) ;
F_15 ( V_2 , V_25 -> V_27 , V_43 , V_110 |
V_268 ) ;
F_38 ( V_25 , 2 * V_111 ,
V_112 ) ;
V_2 -> V_41 [ V_25 -> V_27 ] . V_206 = V_265 ;
F_14 ( V_2 , V_25 -> V_27 , V_104 ) ;
F_9 ( V_2 , V_25 ) ;
F_42 ( V_25 ) ;
return 0 ;
}
static int F_85 ( struct V_269 * V_233 , const T_3 * V_258 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
int V_232 ;
V_232 = F_82 ( V_19 -> V_2 , V_19 -> V_21 , V_233 -> V_270 ,
false ) ;
if ( V_232 )
return V_232 ;
V_232 = F_82 ( V_19 -> V_2 , V_19 -> V_21 , V_258 , true ) ;
if ( V_232 )
return V_232 ;
F_87 ( V_233 -> V_270 , V_258 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , int V_19 )
{
struct V_24 V_25 ;
int V_27 , V_97 ;
for ( V_97 = V_137 ;
V_97 <= V_138 ; V_97 ++ ) {
unsigned char V_258 [ V_111 ] , V_271 [ V_111 ] ;
if ( ! V_2 -> V_41 [ V_97 ] . V_42 ||
( V_2 -> V_41 [ V_97 ] . V_40 != V_104 ) ||
( V_2 -> V_41 [ V_97 ] . V_206 != V_265 ) )
continue;
V_25 . V_27 = V_97 ;
F_12 ( V_2 , & V_25 ) ;
for ( V_27 = 0 ; V_27 < V_111 ; V_27 ++ )
F_24 ( & V_25 , V_27 , & V_258 [ V_27 ] ,
& V_271 [ V_27 ] ) ;
if ( F_84 ( V_258 ) && ! F_83 ( V_258 ) )
F_82 ( V_2 , V_19 , V_258 , false ) ;
}
}
static int F_89 ( struct V_1 * V_2 , int V_19 , int type )
{
switch ( type ) {
case V_272 :
F_48 ( V_2 , V_19 , true ,
V_199 , V_198 ) ;
F_48 ( V_2 , V_19 , true ,
V_197 , V_198 ) ;
F_48 ( V_2 , V_19 , false ,
V_199 , V_200 ) ;
F_48 ( V_2 , V_19 , false ,
V_197 , V_200 ) ;
break;
case V_273 :
F_48 ( V_2 , V_19 , true ,
V_199 , V_200 ) ;
F_48 ( V_2 , V_19 , true ,
V_197 , V_200 ) ;
F_48 ( V_2 , V_19 , false ,
V_199 , V_198 ) ;
F_48 ( V_2 , V_19 , false ,
V_197 , V_198 ) ;
break;
case V_274 :
case V_275 :
F_48 ( V_2 , V_19 , false ,
V_199 , V_200 ) ;
F_48 ( V_2 , V_19 , false ,
V_197 , V_200 ) ;
F_48 ( V_2 , V_19 , false ,
V_199 , V_198 ) ;
F_48 ( V_2 , V_19 , false ,
V_197 , V_198 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_272 ) )
return - V_29 ;
}
return 0 ;
}
static int F_90 ( struct V_18 * V_19 )
{
struct V_24 * V_25 ;
int V_97 ;
V_25 = F_40 ( V_19 -> V_2 , V_19 -> V_21 ) ;
if ( ! V_25 ) {
V_97 = F_43 ( V_19 -> V_2 ,
V_138 ,
V_137 ) ;
if ( V_97 < 0 )
return V_97 ;
V_25 = F_41 ( sizeof( * V_25 ) , V_98 ) ;
if ( ! V_25 )
return - V_148 ;
F_16 ( V_25 , V_99 ) ;
V_25 -> V_27 = V_97 ;
F_35 ( V_25 , V_19 -> V_21 , V_100 ) ;
F_30 ( V_25 , V_191 , 1 ) ;
F_14 ( V_19 -> V_2 , V_25 -> V_27 , V_99 ) ;
}
F_19 ( V_25 , ( 1 << V_19 -> V_21 ) ) ;
F_9 ( V_19 -> V_2 , V_25 ) ;
F_42 ( V_25 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_276 * V_277 )
{
F_1 ( V_2 , V_278 , V_277 -> V_27 ) ;
F_1 ( V_2 , V_279 , V_277 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_280 , V_277 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_281 , V_277 -> V_4 [ 2 ] ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
T_1 V_64 ;
V_64 = ( V_283 -> V_284 << V_285 ) | V_283 -> V_286 ;
F_1 ( V_2 , V_287 , V_64 ) ;
F_1 ( V_2 , V_288 , V_283 -> V_4 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_282 V_283 ;
struct V_276 V_277 ;
int V_27 ;
F_1 ( V_2 , V_289 , V_290 ) ;
memset ( & V_277 . V_4 , 0 , V_291 ) ;
for ( V_27 = 0 ; V_27 < V_292 ; V_27 ++ ) {
V_277 . V_27 = V_27 ;
F_91 ( V_2 , & V_277 ) ;
}
V_283 . V_4 = 0 ;
for ( V_27 = 0 ; V_27 < V_293 ; V_27 ++ ) {
V_283 . V_286 = V_27 ;
V_283 . V_284 = 0 ;
F_92 ( V_2 , & V_283 ) ;
V_283 . V_284 = 1 ;
F_92 ( V_2 , & V_283 ) ;
}
}
static void F_94 ( struct V_18 * V_19 )
{
struct V_282 V_283 ;
T_1 V_64 ;
V_64 = F_3 ( V_19 -> V_2 , V_294 ) ;
V_64 &= ~ F_95 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_294 , V_64 ) ;
V_283 . V_286 = V_19 -> V_21 ;
V_283 . V_284 = 0 ;
V_283 . V_4 = 0 ;
V_283 . V_4 &= ~ V_295 ;
V_283 . V_4 |= V_19 -> V_296 ;
V_283 . V_4 &= ~ V_297 ;
F_92 ( V_19 -> V_2 , & V_283 ) ;
}
static void F_96 ( struct V_18 * V_19 )
{
T_1 V_64 ;
F_1 ( V_19 -> V_2 , F_97 ( V_19 -> V_21 ) ,
V_19 -> V_296 & V_298 ) ;
F_1 ( V_19 -> V_2 , F_98 ( V_19 -> V_21 ) ,
( V_19 -> V_296 >> V_299 ) ) ;
V_64 = F_3 ( V_19 -> V_2 , V_300 ) ;
V_64 |= F_99 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_300 , V_64 ) ;
}
static int F_100 ( struct V_230 * V_231 ,
struct V_1 * V_2 ,
struct V_301 * V_302 , int V_9 )
{
int V_303 ;
T_1 V_64 ;
V_303 = sizeof( T_1 ) * V_9 ;
V_302 -> V_304 = F_101 ( & V_231 -> V_233 , V_303 ,
& V_302 -> V_305 ,
V_98 ) ;
if ( ! V_302 -> V_304 )
return - V_148 ;
if ( ! F_102 ( ( T_1 ) V_302 -> V_304 , V_306 ) ) {
F_103 ( & V_231 -> V_233 , V_303 , V_302 -> V_304 ,
V_302 -> V_305 ) ;
F_104 ( & V_231 -> V_233 , L_1 ,
V_302 -> V_21 , V_306 ) ;
return - V_148 ;
}
F_1 ( V_2 , F_105 ( V_302 -> V_21 ) ,
V_302 -> V_305 ) ;
F_1 ( V_2 , F_106 ( V_302 -> V_21 ) , V_9 ) ;
V_64 = F_3 ( V_2 , F_107 ( V_302 -> V_21 ) ) ;
V_64 |= V_307 ;
F_1 ( V_2 , F_107 ( V_302 -> V_21 ) , V_64 ) ;
V_302 -> type = V_308 ;
V_302 -> V_9 = V_9 ;
V_302 -> V_309 = 0 ;
V_302 -> V_310 = 0 ;
F_108 ( & V_302 -> V_311 , 0 ) ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_301 * V_302 ,
int V_312 )
{
T_1 V_64 ;
V_302 -> V_312 = V_312 ;
V_64 = F_110 ( V_312 , 1 << V_313 ) ;
F_1 ( V_2 , F_111 ( V_302 -> V_21 ) , V_64 ) ;
}
static void F_112 ( struct V_314 * V_233 , struct V_1 * V_2 ,
struct V_301 * V_302 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_302 -> V_310 ; V_26 ++ ) {
T_4 V_17 ;
T_1 V_315 ;
V_17 = F_3 ( V_2 ,
F_113 ( V_302 -> V_21 ) ) ;
V_315 = F_3 ( V_2 , V_316 ) ;
F_114 ( V_233 , V_17 ,
V_302 -> V_312 , V_317 ) ;
if ( ! V_315 )
break;
F_115 ( (struct V_10 * ) V_315 ) ;
}
V_302 -> V_310 -= V_26 ;
}
static int F_116 ( struct V_230 * V_231 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
T_1 V_64 ;
F_112 ( & V_231 -> V_233 , V_2 , V_302 ) ;
if ( V_302 -> V_310 ) {
F_117 ( 1 , L_2 , V_302 -> V_21 ) ;
return 0 ;
}
V_64 = F_3 ( V_2 , F_107 ( V_302 -> V_21 ) ) ;
V_64 |= V_318 ;
F_1 ( V_2 , F_107 ( V_302 -> V_21 ) , V_64 ) ;
F_103 ( & V_231 -> V_233 , sizeof( T_1 ) * V_302 -> V_9 ,
V_302 -> V_304 ,
V_302 -> V_305 ) ;
return 0 ;
}
static int F_118 ( struct V_230 * V_231 ,
struct V_1 * V_2 )
{
int V_26 , V_232 , V_9 ;
struct V_301 * V_302 ;
V_9 = V_319 ;
for ( V_26 = 0 ; V_26 < V_320 ; V_26 ++ ) {
V_302 = & V_2 -> V_321 [ V_26 ] ;
V_302 -> V_21 = V_26 ;
V_232 = F_100 ( V_231 , V_2 , V_302 , V_9 ) ;
if ( V_232 )
goto V_322;
F_109 ( V_2 , V_302 , 0 ) ;
}
return 0 ;
V_322:
F_104 ( & V_231 -> V_233 , L_3 , V_26 , V_9 ) ;
for ( V_26 = V_26 - 1 ; V_26 >= 0 ; V_26 -- )
F_116 ( V_231 , V_2 , & V_2 -> V_321 [ V_26 ] ) ;
return V_232 ;
}
static int F_119 ( struct V_230 * V_231 , struct V_1 * V_2 )
{
int V_26 , V_232 ;
for ( V_26 = 0 ; V_26 < V_320 ; V_26 ++ ) {
F_1 ( V_2 , F_120 ( V_26 ) , 0 ) ;
F_1 ( V_2 , F_121 ( V_26 ) , 0 ) ;
}
V_2 -> V_321 = F_75 ( & V_231 -> V_233 , V_320 ,
sizeof( struct V_301 ) , V_98 ) ;
if ( ! V_2 -> V_321 )
return - V_148 ;
V_232 = F_118 ( V_231 , V_2 ) ;
if ( V_232 < 0 )
return V_232 ;
return 0 ;
}
static void F_122 ( struct V_18 * V_19 ,
int V_323 , int V_324 )
{
T_1 V_64 ;
int V_325 ;
V_325 = V_19 -> V_326 [ V_323 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_325 ) ) ;
V_64 &= ~ V_327 ;
V_64 |= ( ( V_324 << V_328 ) &
V_327 ) ;
F_1 ( V_19 -> V_2 , F_123 ( V_325 ) , V_64 ) ;
}
static void F_124 ( struct V_18 * V_19 ,
int V_323 , int V_329 )
{
T_1 V_64 ;
int V_325 ;
V_325 = V_19 -> V_326 [ V_323 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_325 ) ) ;
V_64 &= ~ V_330 ;
V_64 |= ( ( V_329 << V_331 ) &
V_330 ) ;
F_1 ( V_19 -> V_2 , F_123 ( V_325 ) , V_64 ) ;
}
static struct V_10 * F_125 ( struct V_18 * V_19 ,
struct V_301 * V_302 ,
T_4 * V_17 ,
T_5 V_332 )
{
struct V_10 * V_11 ;
T_4 V_305 ;
V_11 = F_126 ( V_302 -> V_309 , V_332 ) ;
if ( ! V_11 )
return NULL ;
V_305 = F_127 ( V_19 -> V_233 -> V_233 . V_333 , V_11 -> V_334 ,
F_128 ( V_302 -> V_309 ) ,
V_317 ) ;
if ( F_129 ( F_130 ( V_19 -> V_233 -> V_233 . V_333 , V_305 ) ) ) {
F_115 ( V_11 ) ;
return NULL ;
}
* V_17 = V_305 ;
return V_11 ;
}
static inline T_1 F_131 ( T_1 V_335 , int V_336 )
{
T_1 V_337 ;
V_337 = V_335 & ~ ( 0xFF << V_338 ) ;
V_337 |= ( ( V_336 & 0xFF ) << V_338 ) ;
return V_337 ;
}
static inline int F_132 ( T_1 V_335 )
{
return ( V_335 >> V_338 ) & 0xFF ;
}
static inline void F_133 ( struct V_18 * V_19 , int V_336 ,
T_1 V_17 , T_1 V_339 )
{
F_1 ( V_19 -> V_2 , V_340 , V_339 ) ;
F_1 ( V_19 -> V_2 , F_134 ( V_336 ) , V_17 ) ;
}
static void F_135 ( struct V_18 * V_19 , int V_336 ,
T_1 V_17 , T_1 V_339 ,
int V_341 )
{
T_1 V_64 = 0 ;
V_64 |= ( V_341 & V_342 ) ;
F_1 ( V_19 -> V_2 , V_343 , V_64 ) ;
F_133 ( V_19 , V_336 ,
V_17 | V_344 ,
V_339 ) ;
}
static void F_136 ( struct V_18 * V_19 , T_1 V_337 ,
T_1 V_305 , T_1 V_335 )
{
int V_336 = F_132 ( V_337 ) ;
F_133 ( V_19 , V_336 , V_305 , V_335 ) ;
}
static int F_137 ( struct V_18 * V_19 ,
struct V_301 * V_302 , int V_310 )
{
struct V_10 * V_11 ;
int V_26 , V_312 , V_345 ;
T_1 V_337 ;
T_4 V_305 ;
V_312 = F_128 ( V_302 -> V_309 ) ;
V_345 = F_138 ( V_312 ) ;
if ( V_310 < 0 ||
( V_310 + V_302 -> V_310 > V_302 -> V_9 ) ) {
F_139 ( V_19 -> V_233 ,
L_4 ,
V_310 , V_302 -> V_21 ) ;
return 0 ;
}
V_337 = F_131 ( 0 , V_302 -> V_21 ) ;
for ( V_26 = 0 ; V_26 < V_310 ; V_26 ++ ) {
V_11 = F_125 ( V_19 , V_302 , & V_305 , V_98 ) ;
if ( ! V_11 )
break;
F_136 ( V_19 , V_337 , ( T_1 ) V_305 , ( T_1 ) V_11 ) ;
}
V_302 -> V_310 += V_26 ;
V_302 -> V_346 = V_302 -> V_310 / 4 ;
F_140 ( V_19 -> V_233 ,
L_5 ,
V_302 -> type == V_347 ? L_6 : L_7 ,
V_302 -> V_21 , V_302 -> V_309 , V_312 , V_345 ) ;
F_140 ( V_19 -> V_233 ,
L_8 ,
V_302 -> type == V_347 ? L_6 : L_7 ,
V_302 -> V_21 , V_26 , V_310 ) ;
return V_26 ;
}
static struct V_301 *
F_141 ( struct V_18 * V_19 , int V_336 , enum V_348 type ,
int V_309 )
{
struct V_301 * V_349 = & V_19 -> V_2 -> V_321 [ V_336 ] ;
int V_350 ;
if ( V_349 -> type != V_308 && V_349 -> type != type ) {
F_139 ( V_19 -> V_233 , L_9 ) ;
return NULL ;
}
if ( V_349 -> type == V_308 )
V_349 -> type = type ;
if ( ( ( type == V_351 ) && ( V_309 > V_349 -> V_309 ) ) ||
( V_349 -> V_309 == 0 ) ) {
int V_352 ;
V_352 = V_349 -> V_310 ;
if ( V_352 == 0 )
V_352 = type == V_351 ?
V_353 :
V_354 ;
else
F_112 ( V_19 -> V_233 -> V_233 . V_333 ,
V_19 -> V_2 , V_349 ) ;
V_349 -> V_309 = V_309 ;
V_350 = F_137 ( V_19 , V_349 , V_352 ) ;
if ( V_350 != V_352 ) {
F_117 ( 1 , L_10 ,
V_349 -> V_21 , V_350 , V_352 ) ;
return NULL ;
}
}
F_109 ( V_19 -> V_2 , V_349 ,
F_128 ( V_349 -> V_309 ) ) ;
return V_349 ;
}
static int F_142 ( struct V_18 * V_19 )
{
int V_355 ;
if ( ! V_19 -> V_356 ) {
V_19 -> V_356 =
F_141 ( V_19 , F_143 ( V_19 -> V_21 ) ,
V_351 ,
V_19 -> V_309 ) ;
if ( ! V_19 -> V_356 )
return - V_148 ;
V_19 -> V_356 -> V_145 |= ( 1 << V_19 -> V_21 ) ;
for ( V_355 = 0 ; V_355 < V_357 ; V_355 ++ )
F_122 ( V_19 , V_355 , V_19 -> V_356 -> V_21 ) ;
}
if ( ! V_19 -> V_358 ) {
V_19 -> V_358 =
F_141 ( V_19 , V_359 ,
V_347 ,
V_360 ) ;
if ( ! V_19 -> V_358 )
return - V_148 ;
V_19 -> V_358 -> V_145 |= ( 1 << V_19 -> V_21 ) ;
for ( V_355 = 0 ; V_355 < V_357 ; V_355 ++ )
F_124 ( V_19 , V_355 ,
V_19 -> V_358 -> V_21 ) ;
}
return 0 ;
}
static int F_144 ( struct V_269 * V_233 , int V_361 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_301 * V_362 = V_19 -> V_356 ;
int V_350 , V_352 = V_362 -> V_310 ;
int V_309 = F_145 ( V_361 ) ;
F_112 ( V_233 -> V_233 . V_333 , V_19 -> V_2 , V_362 ) ;
if ( V_362 -> V_310 ) {
F_117 ( 1 , L_2 , V_362 -> V_21 ) ;
return - V_363 ;
}
V_362 -> V_309 = V_309 ;
V_350 = F_137 ( V_19 , V_362 , V_352 ) ;
if ( V_350 != V_352 ) {
F_117 ( 1 , L_10 ,
V_362 -> V_21 , V_350 , V_352 ) ;
return - V_363 ;
}
F_109 ( V_19 -> V_2 , V_362 ,
F_128 ( V_362 -> V_309 ) ) ;
V_233 -> V_361 = V_361 ;
F_146 ( V_233 ) ;
return 0 ;
}
static inline void F_147 ( struct V_18 * V_19 )
{
int V_364 , V_365 = 0 ;
F_148 (cpu)
V_365 |= 1 << V_364 ;
F_1 ( V_19 -> V_2 , F_149 ( V_19 -> V_21 ) ,
F_150 ( V_365 ) ) ;
}
static inline void F_151 ( struct V_18 * V_19 )
{
int V_364 , V_365 = 0 ;
F_148 (cpu)
V_365 |= 1 << V_364 ;
F_1 ( V_19 -> V_2 , F_149 ( V_19 -> V_21 ) ,
F_152 ( V_365 ) ) ;
}
static void F_153 ( void * V_366 )
{
struct V_18 * V_19 = V_366 ;
F_1 ( V_19 -> V_2 , F_154 ( V_19 -> V_21 ) , 0 ) ;
}
static void F_155 ( void * V_366 )
{
struct V_18 * V_19 = V_366 ;
F_1 ( V_19 -> V_2 , F_154 ( V_19 -> V_21 ) ,
( V_367 |
V_368 ) ) ;
}
static void F_156 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_369 ) ;
switch ( V_19 -> V_370 ) {
case V_371 :
V_64 |= V_372 ;
break;
case V_373 :
V_64 |= V_374 ;
default:
V_64 &= ~ V_375 ;
}
F_2 ( V_64 , V_19 -> V_5 + V_369 ) ;
}
static void F_157 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_376 ) ;
V_64 |= V_377 ;
F_2 ( V_64 , V_19 -> V_5 + V_376 ) ;
}
static void F_158 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_378 ) ;
V_64 |= V_379 ;
V_64 |= V_380 ;
F_2 ( V_64 , V_19 -> V_5 + V_378 ) ;
}
static void F_159 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_378 ) ;
V_64 &= ~ ( V_379 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_378 ) ;
}
static void F_160 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_381 ) &
~ V_382 ;
F_2 ( V_64 , V_19 -> V_5 + V_381 ) ;
}
static void F_161 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_381 ) ;
if ( V_19 -> V_383 == 1000 )
V_64 |= V_384 ;
else
V_64 &= ~ V_384 ;
if ( V_19 -> V_370 == V_371 )
V_64 |= V_385 ;
else
V_64 &= ~ V_385 ;
F_2 ( V_64 , V_19 -> V_5 + V_381 ) ;
}
static void F_162 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_369 ) &
~ V_386 ;
F_2 ( V_64 , V_19 -> V_5 + V_369 ) ;
while ( F_4 ( V_19 -> V_5 + V_369 ) &
V_386 )
continue;
}
static inline void F_163 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_378 ) ;
V_64 &= ~ V_387 ;
V_64 |= ( ( ( V_19 -> V_309 - V_194 ) / 2 ) <<
V_388 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_378 ) ;
}
static void F_164 ( struct V_18 * V_19 )
{
int V_389 , V_64 , V_390 , V_391 , V_323 ;
if ( V_19 -> V_392 & V_393 )
F_161 ( V_19 ) ;
V_64 = F_4 ( V_19 -> V_5 + V_394 ) ;
V_64 &= ~ V_395 ;
V_64 |= F_165 ( 64 - 4 - 2 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_394 ) ;
V_389 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_396 ,
V_389 ) ;
F_1 ( V_19 -> V_2 , V_397 , 0 ) ;
for ( V_390 = 0 ; V_390 < V_23 ; V_390 ++ ) {
V_391 = F_8 ( V_19 -> V_21 , V_390 ) ;
F_1 ( V_19 -> V_2 ,
F_166 ( V_391 ) , 0 ) ;
}
F_1 ( V_19 -> V_2 , V_398 ,
V_19 -> V_2 -> V_399 / V_400 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_401 ) ;
V_64 &= ~ V_402 ;
V_64 |= F_167 ( 1 ) ;
V_64 |= V_403 ;
F_1 ( V_19 -> V_2 , V_401 , V_64 ) ;
V_64 = V_404 ;
F_1 ( V_19 -> V_2 , V_405 , V_64 ) ;
F_1 ( V_19 -> V_2 , F_168 ( V_19 -> V_21 ) ,
V_406 |
F_169 ( 256 ) ) ;
for ( V_323 = 0 ; V_323 < V_357 ; V_323 ++ ) {
V_390 = V_19 -> V_326 [ V_323 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_390 ) ) ;
V_64 |= V_407 |
V_408 ;
F_1 ( V_19 -> V_2 , F_123 ( V_390 ) , V_64 ) ;
}
F_151 ( V_19 ) ;
}
static void F_170 ( struct V_18 * V_19 )
{
T_1 V_64 ;
int V_323 , V_390 ;
for ( V_323 = 0 ; V_323 < V_357 ; V_323 ++ ) {
V_390 = V_19 -> V_326 [ V_323 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_390 ) ) ;
V_64 &= ~ V_409 ;
F_1 ( V_19 -> V_2 , F_123 ( V_390 ) , V_64 ) ;
}
}
static void F_171 ( struct V_18 * V_19 )
{
T_1 V_64 ;
int V_323 , V_390 ;
for ( V_323 = 0 ; V_323 < V_357 ; V_323 ++ ) {
V_390 = V_19 -> V_326 [ V_323 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_390 ) ) ;
V_64 |= V_409 ;
F_1 ( V_19 -> V_2 , F_123 ( V_390 ) , V_64 ) ;
}
}
static void F_172 ( struct V_18 * V_19 )
{
T_1 V_410 ;
int V_390 ;
int V_389 = F_7 ( V_19 ) ;
V_410 = 0 ;
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
struct V_412 * V_22 = V_19 -> V_413 [ V_390 ] ;
if ( V_22 -> V_414 != NULL )
V_410 |= ( 1 << V_390 ) ;
}
F_1 ( V_19 -> V_2 , V_396 , V_389 ) ;
F_1 ( V_19 -> V_2 , V_415 , V_410 ) ;
}
static void F_173 ( struct V_18 * V_19 )
{
T_1 V_416 ;
int V_417 ;
int V_389 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_396 , V_389 ) ;
V_416 = ( F_3 ( V_19 -> V_2 , V_415 ) ) &
V_418 ;
if ( V_416 != 0 )
F_1 ( V_19 -> V_2 , V_415 ,
( V_416 << V_419 ) ) ;
V_417 = 0 ;
do {
if ( V_417 >= V_420 ) {
F_174 ( V_19 -> V_233 ,
L_11 ,
V_416 ) ;
break;
}
F_175 ( 1 ) ;
V_417 ++ ;
V_416 = F_3 ( V_19 -> V_2 , V_415 ) ;
} while ( V_416 & V_418 );
}
static inline int
F_176 ( struct V_18 * V_19 , int V_421 )
{
T_1 V_64 = F_3 ( V_19 -> V_2 , F_177 ( V_421 ) ) ;
return V_64 & V_422 ;
}
static inline void
F_178 ( struct V_18 * V_19 , int V_421 ,
int V_423 , int V_424 )
{
T_1 V_64 = V_423 | ( V_424 << V_425 ) ;
F_1 ( V_19 -> V_2 , F_179 ( V_421 ) , V_64 ) ;
}
static inline struct V_426 *
F_180 ( struct V_427 * V_355 )
{
int V_428 = V_355 -> V_429 ;
V_355 -> V_429 = F_181 ( V_355 , V_428 ) ;
F_182 ( V_355 -> V_414 + V_355 -> V_429 ) ;
return V_355 -> V_414 + V_428 ;
}
static void F_183 ( struct V_18 * V_19 ,
int V_325 , int V_3 )
{
T_1 V_64 ;
V_3 = V_3 >> 5 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_325 ) ) ;
V_64 &= ~ V_430 ;
V_64 |= ( ( V_3 << V_431 ) &
V_430 ) ;
F_1 ( V_19 -> V_2 , F_123 ( V_325 ) , V_64 ) ;
}
static T_1 F_184 ( struct V_426 * V_428 )
{
int V_336 = ( V_428 -> V_432 & V_433 ) >>
V_434 ;
int V_364 = F_185 () ;
return ( ( V_336 & 0xFF ) << V_338 ) |
( ( V_364 & 0xFF ) << V_435 ) ;
}
static int F_186 ( struct V_18 * V_19 ,
struct V_412 * V_22 )
{
T_1 V_64 ;
F_1 ( V_19 -> V_2 , V_436 , V_22 -> V_21 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_437 ) ;
return V_64 & V_438 ;
}
static struct V_12 *
F_187 ( struct V_412 * V_22 )
{
int V_13 = V_22 -> V_429 ;
V_22 -> V_429 = F_181 ( V_22 , V_13 ) ;
return V_22 -> V_414 + V_13 ;
}
static void F_188 ( struct V_18 * V_19 , int V_439 )
{
F_1 ( V_19 -> V_2 , V_440 , V_439 ) ;
}
static int F_189 ( struct V_1 * V_2 ,
struct V_412 * V_441 , int V_350 )
{
if ( ( V_441 -> V_442 + V_350 ) > V_441 -> V_9 ) {
int V_364 = F_185 () ;
T_1 V_64 = F_3 ( V_2 , F_190 ( V_364 ) ) ;
V_441 -> V_442 = V_64 & V_443 ;
}
if ( ( V_441 -> V_442 + V_350 ) > V_441 -> V_9 )
return - V_148 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_412 * V_22 , int V_350 )
{
T_1 V_64 ;
V_64 = ( V_22 -> V_21 << V_444 ) | V_350 ;
F_1 ( V_2 , V_445 , V_64 ) ;
V_64 = F_3 ( V_2 , V_446 ) ;
return V_64 & V_447 ;
}
static int F_192 ( struct V_1 * V_2 ,
struct V_412 * V_22 ,
struct V_6 * V_7 ,
int V_350 )
{
int V_448 , V_364 , V_449 ;
if ( V_7 -> V_450 >= V_350 )
return 0 ;
V_449 = 0 ;
F_148 (cpu) {
struct V_6 * V_451 ;
V_451 = F_193 ( V_22 -> V_452 , V_364 ) ;
V_449 += V_451 -> V_442 ;
V_449 += V_451 -> V_450 ;
}
V_448 = F_194 ( V_453 , V_350 - V_7 -> V_450 ) ;
V_449 += V_448 ;
if ( V_449 >
( V_22 -> V_9 - ( F_195 () * V_453 ) ) )
return - V_148 ;
V_7 -> V_450 += F_191 ( V_2 , V_22 , V_448 ) ;
if ( V_7 -> V_450 < V_350 )
return - V_148 ;
return 0 ;
}
static void F_196 ( struct V_412 * V_22 )
{
if ( V_22 -> V_429 == 0 )
V_22 -> V_429 = V_22 -> V_454 - 1 ;
else
V_22 -> V_429 -- ;
}
static T_1 F_197 ( int V_455 , int V_456 ,
int V_457 , int V_458 )
{
T_1 V_459 ;
V_459 = ( V_455 << V_460 ) ;
V_459 |= ( V_457 << V_461 ) ;
V_459 |= V_462 ;
if ( V_456 == F_51 ( V_218 ) ) {
V_459 &= ~ V_462 ;
V_459 &= ~ V_463 ;
} else {
V_459 |= V_463 ;
}
if ( V_458 == V_158 ) {
V_459 &= ~ V_464 ;
V_459 &= ~ V_465 ;
} else if ( V_458 == V_159 ) {
V_459 |= V_464 ;
V_459 &= ~ V_465 ;
} else {
V_459 |= V_466 ;
}
return V_459 ;
}
static inline int F_198 ( struct V_18 * V_19 ,
struct V_412 * V_22 )
{
T_1 V_64 ;
V_64 = F_3 ( V_19 -> V_2 , F_199 ( V_22 -> V_21 ) ) ;
return ( V_64 & V_467 ) >>
V_468 ;
}
static void F_200 ( void * V_366 )
{
struct V_18 * V_19 = V_366 ;
int V_390 ;
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
int V_21 = V_19 -> V_413 [ V_390 ] -> V_21 ;
F_3 ( V_19 -> V_2 , F_199 ( V_21 ) ) ;
}
}
static void F_201 ( struct V_18 * V_19 )
{
T_1 V_64 , V_9 , V_361 ;
int V_22 , V_389 ;
V_361 = V_19 -> V_309 * 8 ;
if ( V_361 > V_469 )
V_361 = V_469 ;
V_361 = 3 * V_361 ;
V_389 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_396 , V_389 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_470 ) ;
V_64 &= ~ V_469 ;
V_64 |= V_361 ;
F_1 ( V_19 -> V_2 , V_470 , V_64 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_405 ) ;
V_9 = V_64 & V_404 ;
if ( V_9 < V_361 ) {
V_9 = V_361 ;
V_64 &= ~ V_404 ;
V_64 |= V_9 ;
F_1 ( V_19 -> V_2 , V_405 , V_64 ) ;
}
for ( V_22 = 0 ; V_22 < V_411 ; V_22 ++ ) {
V_64 = F_3 ( V_19 -> V_2 ,
F_202 ( V_22 ) ) ;
V_9 = V_64 & V_471 ;
if ( V_9 < V_361 ) {
V_9 = V_361 ;
V_64 &= ~ V_471 ;
V_64 |= V_9 ;
F_1 ( V_19 -> V_2 ,
F_202 ( V_22 ) ,
V_64 ) ;
}
}
}
static void F_203 ( struct V_18 * V_19 ,
struct V_427 * V_355 , T_1 V_472 )
{
T_1 V_64 ;
V_64 = ( V_472 & V_473 ) ;
F_1 ( V_19 -> V_2 , V_474 , V_355 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_475 , V_64 ) ;
V_355 -> V_476 = V_472 ;
}
static void F_204 ( struct V_18 * V_19 ,
struct V_427 * V_355 , T_1 V_477 )
{
T_1 V_64 ;
V_64 = ( V_19 -> V_2 -> V_399 / V_400 ) * V_477 ;
F_1 ( V_19 -> V_2 , F_205 ( V_355 -> V_21 ) , V_64 ) ;
V_355 -> V_478 = V_477 ;
}
static void F_206 ( struct V_18 * V_19 ,
struct V_412 * V_22 ,
struct V_6 * V_7 , int V_350 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_350 ; V_26 ++ ) {
T_4 V_17 =
V_7 -> V_16 [ V_7 -> V_8 ] ;
struct V_10 * V_11 = V_7 -> V_14 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
F_114 ( V_19 -> V_233 -> V_233 . V_333 , V_17 ,
F_207 ( V_11 ) , V_479 ) ;
if ( ! V_11 )
continue;
F_115 ( V_11 ) ;
}
}
static inline struct V_427 * F_208 ( struct V_18 * V_19 ,
T_1 V_480 )
{
int V_390 = F_209 ( V_480 ) - 1 ;
return V_19 -> V_326 [ V_390 ] ;
}
static inline struct V_412 * F_210 ( struct V_18 * V_19 ,
T_1 V_480 )
{
int V_390 = F_209 ( V_480 ) - 1 ;
return V_19 -> V_413 [ V_390 ] ;
}
static void F_211 ( struct V_18 * V_19 , struct V_412 * V_22 ,
struct V_6 * V_7 )
{
struct V_481 * V_482 = F_212 ( V_19 -> V_233 , V_22 -> V_483 ) ;
int V_484 ;
if ( V_7 -> V_364 != F_185 () )
F_139 ( V_19 -> V_233 , L_12 ) ;
V_484 = F_198 ( V_19 , V_22 ) ;
if ( ! V_484 )
return;
F_206 ( V_19 , V_22 , V_7 , V_484 ) ;
V_7 -> V_442 -= V_484 ;
if ( F_213 ( V_482 ) )
if ( V_7 -> V_9 - V_7 -> V_442 >= V_485 + 1 )
F_214 ( V_482 ) ;
}
static unsigned int F_215 ( struct V_18 * V_19 , T_1 V_480 )
{
struct V_412 * V_22 ;
struct V_6 * V_7 ;
unsigned int V_486 = 0 ;
while ( V_480 ) {
V_22 = F_210 ( V_19 , V_480 ) ;
if ( ! V_22 )
break;
V_7 = F_216 ( V_22 -> V_452 ) ;
if ( V_7 -> V_442 ) {
F_211 ( V_19 , V_22 , V_7 ) ;
V_486 += V_7 -> V_442 ;
}
V_480 &= ~ ( 1 << V_22 -> V_483 ) ;
}
return V_486 ;
}
static int F_217 ( struct V_230 * V_231 ,
struct V_412 * V_441 ,
int V_487 , int V_364 ,
struct V_1 * V_2 )
{
V_441 -> V_414 = F_101 ( & V_231 -> V_233 ,
V_487 * V_488 ,
& V_441 -> V_489 , V_98 ) ;
if ( ! V_441 -> V_414 )
return - V_148 ;
V_441 -> V_454 = V_441 -> V_9 - 1 ;
V_441 -> V_429 = F_3 ( V_2 ,
F_218 ( V_364 ) ) ;
F_1 ( V_2 , F_219 ( V_364 ) ,
V_441 -> V_489 ) ;
F_1 ( V_2 , F_220 ( V_364 ) , V_487 ) ;
return 0 ;
}
static int F_221 ( struct V_18 * V_19 ,
struct V_427 * V_355 )
{
V_355 -> V_9 = V_19 -> V_490 ;
V_355 -> V_414 = F_101 ( V_19 -> V_233 -> V_233 . V_333 ,
V_355 -> V_9 * V_488 ,
& V_355 -> V_489 , V_98 ) ;
if ( ! V_355 -> V_414 )
return - V_148 ;
V_355 -> V_454 = V_355 -> V_9 - 1 ;
F_1 ( V_19 -> V_2 , F_177 ( V_355 -> V_21 ) , 0 ) ;
F_1 ( V_19 -> V_2 , V_474 , V_355 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_491 , V_355 -> V_489 ) ;
F_1 ( V_19 -> V_2 , V_492 , V_355 -> V_9 ) ;
F_1 ( V_19 -> V_2 , V_493 , 0 ) ;
F_183 ( V_19 , V_355 -> V_21 , V_494 ) ;
F_203 ( V_19 , V_355 , V_355 -> V_476 ) ;
F_204 ( V_19 , V_355 , V_355 -> V_478 ) ;
F_178 ( V_19 , V_355 -> V_21 , 0 , V_355 -> V_9 ) ;
return 0 ;
}
static void F_222 ( struct V_18 * V_19 ,
struct V_427 * V_355 )
{
int V_495 , V_26 ;
V_495 = F_176 ( V_19 , V_355 -> V_21 ) ;
if ( ! V_495 )
return;
for ( V_26 = 0 ; V_26 < V_495 ; V_26 ++ ) {
struct V_426 * V_428 = F_180 ( V_355 ) ;
T_1 V_337 = F_184 ( V_428 ) ;
F_136 ( V_19 , V_337 , V_428 -> V_17 ,
V_428 -> V_496 ) ;
}
F_178 ( V_19 , V_355 -> V_21 , V_495 , V_495 ) ;
}
static void F_223 ( struct V_18 * V_19 ,
struct V_427 * V_355 )
{
F_222 ( V_19 , V_355 ) ;
if ( V_355 -> V_414 )
F_103 ( V_19 -> V_233 -> V_233 . V_333 ,
V_355 -> V_9 * V_488 ,
V_355 -> V_414 ,
V_355 -> V_489 ) ;
V_355 -> V_414 = NULL ;
V_355 -> V_454 = 0 ;
V_355 -> V_429 = 0 ;
V_355 -> V_489 = 0 ;
F_1 ( V_19 -> V_2 , F_177 ( V_355 -> V_21 ) , 0 ) ;
F_1 ( V_19 -> V_2 , V_474 , V_355 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_491 , 0 ) ;
F_1 ( V_19 -> V_2 , V_492 , 0 ) ;
}
static int F_224 ( struct V_18 * V_19 ,
struct V_412 * V_22 )
{
T_1 V_64 ;
int V_364 , V_497 , V_498 , V_389 ;
struct V_6 * V_7 ;
V_22 -> V_9 = V_19 -> V_499 ;
V_22 -> V_414 = F_101 ( V_19 -> V_233 -> V_233 . V_333 ,
V_22 -> V_9 * V_488 ,
& V_22 -> V_489 , V_98 ) ;
if ( ! V_22 -> V_414 )
return - V_148 ;
V_22 -> V_454 = V_22 -> V_9 - 1 ;
F_1 ( V_19 -> V_2 , V_436 , V_22 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_500 , V_22 -> V_489 ) ;
F_1 ( V_19 -> V_2 , V_501 , V_22 -> V_9 &
V_502 ) ;
F_1 ( V_19 -> V_2 , V_503 , 0 ) ;
F_1 ( V_19 -> V_2 , V_504 ,
V_22 -> V_21 << V_505 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_437 ) ;
V_64 &= ~ V_438 ;
F_1 ( V_19 -> V_2 , V_437 , V_64 ) ;
V_498 = 16 ;
V_497 = ( V_19 -> V_21 * V_23 * V_498 ) +
( V_22 -> V_483 * V_498 ) ;
F_1 ( V_19 -> V_2 , V_506 ,
F_225 ( V_497 ) | V_507 |
F_226 ( V_498 / 2 ) ) ;
V_389 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_396 , V_389 ) ;
V_64 = F_3 ( V_19 -> V_2 , F_227 ( V_22 -> V_483 ) ) ;
V_64 &= ~ V_508 ;
V_64 |= F_228 ( 1 ) ;
V_64 |= V_509 ;
F_1 ( V_19 -> V_2 , F_227 ( V_22 -> V_483 ) , V_64 ) ;
V_64 = V_471 ;
F_1 ( V_19 -> V_2 , F_202 ( V_22 -> V_483 ) ,
V_64 ) ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_452 , V_364 ) ;
V_7 -> V_9 = V_22 -> V_9 ;
V_7 -> V_14 = F_229 ( V_7 -> V_9 *
sizeof( * V_7 -> V_14 ) ,
V_98 ) ;
if ( ! V_7 -> V_14 )
goto error;
V_7 -> V_16 = F_229 ( V_7 -> V_9 *
sizeof( T_4 ) , V_98 ) ;
if ( ! V_7 -> V_16 )
goto error;
V_7 -> V_442 = 0 ;
V_7 -> V_450 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_8 = 0 ;
}
return 0 ;
error:
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_452 , V_364 ) ;
F_42 ( V_7 -> V_14 ) ;
F_42 ( V_7 -> V_16 ) ;
}
F_103 ( V_19 -> V_233 -> V_233 . V_333 ,
V_22 -> V_9 * V_488 ,
V_22 -> V_414 , V_22 -> V_489 ) ;
return - V_148 ;
}
static void F_230 ( struct V_18 * V_19 ,
struct V_412 * V_22 )
{
struct V_6 * V_7 ;
int V_364 ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_452 , V_364 ) ;
F_42 ( V_7 -> V_14 ) ;
F_42 ( V_7 -> V_16 ) ;
}
if ( V_22 -> V_414 )
F_103 ( V_19 -> V_233 -> V_233 . V_333 ,
V_22 -> V_9 * V_488 ,
V_22 -> V_414 , V_22 -> V_489 ) ;
V_22 -> V_414 = NULL ;
V_22 -> V_454 = 0 ;
V_22 -> V_429 = 0 ;
V_22 -> V_489 = 0 ;
F_1 ( V_19 -> V_2 , F_166 ( V_22 -> V_21 ) , 0 ) ;
F_1 ( V_19 -> V_2 , V_436 , V_22 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_500 , 0 ) ;
F_1 ( V_19 -> V_2 , V_501 , 0 ) ;
}
static void F_231 ( struct V_18 * V_19 , struct V_412 * V_22 )
{
struct V_6 * V_7 ;
int V_417 , V_439 , V_364 ;
T_1 V_64 ;
F_1 ( V_19 -> V_2 , V_436 , V_22 -> V_21 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_506 ) ;
V_64 |= V_510 ;
F_1 ( V_19 -> V_2 , V_506 , V_64 ) ;
V_417 = 0 ;
do {
if ( V_417 >= V_511 ) {
F_174 ( V_19 -> V_233 ,
L_13 ,
V_19 -> V_21 , V_22 -> V_483 ) ;
break;
}
F_175 ( 1 ) ;
V_417 ++ ;
V_439 = F_186 ( V_19 , V_22 ) ;
} while ( V_439 );
V_64 &= ~ V_510 ;
F_1 ( V_19 -> V_2 , V_506 , V_64 ) ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_452 , V_364 ) ;
F_206 ( V_19 , V_22 , V_7 , V_7 -> V_442 ) ;
V_7 -> V_442 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_8 = 0 ;
}
}
static void F_232 ( struct V_18 * V_19 )
{
struct V_412 * V_22 ;
int V_390 ;
T_1 V_64 ;
V_64 = F_3 ( V_19 -> V_2 , V_512 ) ;
V_64 |= F_233 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_512 , V_64 ) ;
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
V_22 = V_19 -> V_413 [ V_390 ] ;
F_231 ( V_19 , V_22 ) ;
F_230 ( V_19 , V_22 ) ;
}
F_234 ( F_200 , V_19 , 1 ) ;
V_64 &= ~ F_233 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_512 , V_64 ) ;
}
static void F_235 ( struct V_18 * V_19 )
{
int V_390 ;
for ( V_390 = 0 ; V_390 < V_357 ; V_390 ++ )
F_223 ( V_19 , V_19 -> V_326 [ V_390 ] ) ;
}
static int F_236 ( struct V_18 * V_19 )
{
int V_390 , V_232 ;
for ( V_390 = 0 ; V_390 < V_357 ; V_390 ++ ) {
V_232 = F_221 ( V_19 , V_19 -> V_326 [ V_390 ] ) ;
if ( V_232 )
goto V_513;
}
return 0 ;
V_513:
F_235 ( V_19 ) ;
return V_232 ;
}
static int F_237 ( struct V_18 * V_19 )
{
struct V_412 * V_22 ;
int V_390 , V_232 ;
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
V_22 = V_19 -> V_413 [ V_390 ] ;
V_232 = F_224 ( V_19 , V_22 ) ;
if ( V_232 )
goto V_513;
}
F_234 ( F_200 , V_19 , 1 ) ;
return 0 ;
V_513:
F_232 ( V_19 ) ;
return V_232 ;
}
static T_6 F_238 ( int V_514 , void * V_515 )
{
struct V_18 * V_19 = (struct V_18 * ) V_515 ;
F_151 ( V_19 ) ;
F_239 ( & V_19 -> V_516 ) ;
return V_517 ;
}
static void F_240 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_518 * V_519 = V_233 -> V_519 ;
int V_520 = 0 ;
T_1 V_64 ;
if ( V_519 -> V_521 ) {
if ( ( V_19 -> V_383 != V_519 -> V_383 ) ||
( V_19 -> V_522 != V_519 -> V_522 ) ) {
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_376 ) ;
V_64 &= ~ ( V_523 |
V_524 |
V_525 |
V_526 |
V_527 ) ;
if ( V_519 -> V_522 )
V_64 |= V_525 ;
if ( V_519 -> V_383 == V_528 )
V_64 |= V_524 ;
else if ( V_519 -> V_383 == V_529 )
V_64 |= V_523 ;
F_2 ( V_64 , V_19 -> V_5 + V_376 ) ;
V_19 -> V_522 = V_519 -> V_522 ;
V_19 -> V_383 = V_519 -> V_383 ;
}
}
if ( V_519 -> V_521 != V_19 -> V_521 ) {
if ( ! V_519 -> V_521 ) {
V_19 -> V_522 = - 1 ;
V_19 -> V_383 = 0 ;
}
V_19 -> V_521 = V_519 -> V_521 ;
V_520 = 1 ;
}
if ( V_520 ) {
if ( V_519 -> V_521 ) {
V_64 = F_4 ( V_19 -> V_5 + V_376 ) ;
V_64 |= ( V_530 |
V_531 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_376 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
} else {
F_171 ( V_19 ) ;
F_173 ( V_19 ) ;
}
F_241 ( V_519 ) ;
}
}
static void F_242 ( struct V_532 * V_533 )
{
T_7 V_534 ;
if ( ! V_533 -> V_535 ) {
V_533 -> V_535 = true ;
V_534 = F_243 ( 0 , V_536 ) ;
F_244 ( & V_533 -> V_537 , V_534 ,
V_538 ) ;
}
}
static void F_245 ( unsigned long V_4 )
{
struct V_269 * V_233 = (struct V_269 * ) V_4 ;
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_532 * V_533 = F_216 ( V_19 -> V_452 ) ;
unsigned int V_486 , V_480 ;
if ( ! F_246 ( V_233 ) )
return;
V_533 -> V_535 = false ;
V_480 = ( 1 << V_411 ) - 1 ;
V_486 = F_215 ( V_19 , V_480 ) ;
if ( V_486 )
F_242 ( V_533 ) ;
}
static enum V_539 F_247 ( struct V_540 * V_541 )
{
struct V_532 * V_533 = F_248 ( V_541 ,
struct V_532 ,
V_537 ) ;
F_249 ( & V_533 -> V_542 ) ;
return V_543 ;
}
static void F_250 ( struct V_18 * V_19 ,
struct V_426 * V_428 )
{
T_1 V_432 = V_428 -> V_432 ;
switch ( V_432 & V_544 ) {
case V_545 :
F_139 ( V_19 -> V_233 , L_14 ,
V_432 , V_428 -> V_546 ) ;
break;
case V_547 :
F_139 ( V_19 -> V_233 , L_15 ,
V_432 , V_428 -> V_546 ) ;
break;
case V_548 :
F_139 ( V_19 -> V_233 , L_16 ,
V_432 , V_428 -> V_546 ) ;
break;
}
}
static void F_251 ( struct V_18 * V_19 , T_1 V_432 ,
struct V_10 * V_11 )
{
if ( ( ( V_432 & V_549 ) &&
! ( V_432 & V_550 ) ) ||
( V_432 & V_551 ) )
if ( ( ( V_432 & V_552 ) ||
( V_432 & V_553 ) ) &&
( V_432 & V_554 ) ) {
V_11 -> V_555 = 0 ;
V_11 -> V_556 = V_557 ;
return;
}
V_11 -> V_556 = V_558 ;
}
static int F_252 ( struct V_18 * V_19 ,
struct V_301 * V_302 ,
T_1 V_337 , int V_559 )
{
struct V_10 * V_11 ;
T_4 V_305 ;
if ( V_559 &&
( F_253 ( & V_302 -> V_311 ) < V_302 -> V_346 ) )
return 0 ;
V_11 = F_125 ( V_19 , V_302 , & V_305 , V_560 ) ;
if ( ! V_11 )
return - V_148 ;
F_136 ( V_19 , V_337 , ( T_1 ) V_305 , ( T_1 ) V_11 ) ;
F_254 ( & V_302 -> V_311 ) ;
return 0 ;
}
static T_1 F_255 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
if ( V_11 -> V_556 == V_561 ) {
int V_457 = 0 ;
T_3 V_458 ;
if ( V_11 -> V_562 == F_256 ( V_218 ) ) {
struct V_163 * V_563 = F_257 ( V_11 ) ;
V_457 = V_563 -> V_564 ;
V_458 = V_563 -> V_562 ;
} else if ( V_11 -> V_562 == F_256 ( V_225 ) ) {
struct V_182 * V_565 = F_258 ( V_11 ) ;
if ( F_259 ( V_11 ) > 0 )
V_457 = ( F_259 ( V_11 ) >> 2 ) ;
V_458 = V_565 -> V_566 ;
} else {
return V_466 ;
}
return F_197 ( F_260 ( V_11 ) ,
V_11 -> V_562 , V_457 , V_458 ) ;
}
return V_466 | V_462 ;
}
static void F_261 ( struct V_18 * V_19 ,
struct V_426 * V_428 )
{
struct V_567 * V_568 ;
struct V_10 * V_11 ;
T_1 V_569 = V_428 -> V_432 ;
T_1 V_570 ;
T_1 V_571 ;
T_1 V_572 ;
T_1 V_573 ;
int V_341 ;
int V_574 ;
V_574 = ( V_569 & V_433 ) >>
V_434 ;
V_570 = V_428 -> V_17 ;
V_571 = V_428 -> V_496 ;
do {
V_11 = (struct V_10 * ) V_571 ;
V_568 = (struct V_567 * ) V_11 -> V_334 ;
V_341 = F_262 ( V_568 -> V_575 ) ;
V_572 = V_568 -> V_576 ;
V_573 = V_568 -> V_577 ;
F_135 ( V_19 , V_574 , V_570 ,
V_571 , V_341 ) ;
V_570 = V_572 ;
V_571 = V_573 ;
} while ( ! F_263 ( V_568 -> V_575 ) );
}
static int F_264 ( struct V_18 * V_19 , int V_578 ,
struct V_427 * V_355 )
{
struct V_269 * V_233 = V_19 -> V_233 ;
int V_495 ;
int V_579 = 0 ;
T_1 V_580 = 0 ;
T_1 V_581 = 0 ;
V_495 = F_176 ( V_19 , V_355 -> V_21 ) ;
if ( V_578 > V_495 )
V_578 = V_495 ;
while ( V_579 < V_578 ) {
struct V_426 * V_428 = F_180 ( V_355 ) ;
struct V_301 * V_302 ;
struct V_10 * V_11 ;
T_4 V_305 ;
T_1 V_337 , V_569 ;
int V_336 , V_582 , V_232 ;
V_579 ++ ;
V_569 = V_428 -> V_432 ;
V_582 = V_428 -> V_546 - V_194 ;
V_305 = V_428 -> V_17 ;
V_337 = F_184 ( V_428 ) ;
V_336 = F_132 ( V_337 ) ;
V_302 = & V_19 -> V_2 -> V_321 [ V_336 ] ;
if ( V_569 & V_583 ) {
F_261 ( V_19 , V_428 ) ;
continue;
}
if ( V_569 & V_584 ) {
V_585:
V_233 -> V_586 . V_587 ++ ;
F_250 ( V_19 , V_428 ) ;
F_136 ( V_19 , V_337 , V_428 -> V_17 ,
V_428 -> V_496 ) ;
continue;
}
V_11 = (struct V_10 * ) V_428 -> V_496 ;
V_232 = F_252 ( V_19 , V_302 , V_337 , 0 ) ;
if ( V_232 ) {
F_139 ( V_19 -> V_233 , L_17 ) ;
goto V_585;
}
F_114 ( V_233 -> V_233 . V_333 , V_305 ,
V_302 -> V_312 , V_317 ) ;
V_580 ++ ;
V_581 += V_582 ;
F_265 ( & V_302 -> V_311 ) ;
F_266 ( V_11 , V_194 ) ;
F_267 ( V_11 , V_582 ) ;
V_11 -> V_562 = F_268 ( V_11 , V_233 ) ;
F_251 ( V_19 , V_569 , V_11 ) ;
F_269 ( & V_19 -> V_516 , V_11 ) ;
}
if ( V_580 ) {
struct V_588 * V_586 = F_216 ( V_19 -> V_586 ) ;
F_270 ( & V_586 -> V_589 ) ;
V_586 -> V_590 += V_580 ;
V_586 -> V_582 += V_581 ;
F_271 ( & V_586 -> V_589 ) ;
}
F_272 () ;
F_178 ( V_19 , V_355 -> V_21 , V_579 , V_579 ) ;
return V_578 ;
}
static inline void
F_273 ( struct V_314 * V_233 , struct V_412 * V_22 ,
struct V_12 * V_497 )
{
F_114 ( V_233 , V_497 -> V_17 ,
V_497 -> V_546 , V_479 ) ;
F_196 ( V_22 ) ;
}
static int F_274 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_412 * V_441 ,
struct V_412 * V_22 )
{
struct V_6 * V_7 = F_216 ( V_22 -> V_452 ) ;
struct V_12 * V_13 ;
int V_26 ;
T_4 V_17 ;
for ( V_26 = 0 ; V_26 < F_275 ( V_11 ) -> V_591 ; V_26 ++ ) {
T_8 * V_592 = & F_275 ( V_11 ) -> V_593 [ V_26 ] ;
void * V_594 = F_276 ( V_592 -> V_595 . V_596 ) + V_592 -> V_597 ;
V_13 = F_187 ( V_441 ) ;
V_13 -> V_598 = V_22 -> V_21 ;
V_13 -> V_546 = V_592 -> V_9 ;
V_17 = F_127 ( V_19 -> V_233 -> V_233 . V_333 , V_594 ,
V_13 -> V_546 ,
V_479 ) ;
if ( F_130 ( V_19 -> V_233 -> V_233 . V_333 , V_17 ) ) {
F_196 ( V_22 ) ;
goto error;
}
V_13 -> V_599 = V_17 & V_600 ;
V_13 -> V_17 = V_17 & ( ~ V_600 ) ;
if ( V_26 == ( F_275 ( V_11 ) -> V_591 - 1 ) ) {
V_13 -> V_459 = V_601 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_13 -> V_459 = 0 ;
F_6 ( V_7 , NULL , V_13 ) ;
}
}
return 0 ;
error:
for ( V_26 = V_26 - 1 ; V_26 >= 0 ; V_26 -- ) {
V_13 = V_22 -> V_414 + V_26 ;
F_273 ( V_19 -> V_233 -> V_233 . V_333 , V_22 , V_13 ) ;
}
return - V_148 ;
}
static int F_277 ( struct V_10 * V_11 , struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_412 * V_22 , * V_441 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
T_4 V_17 ;
int V_593 = 0 ;
T_2 V_602 ;
T_1 V_603 ;
V_602 = F_278 ( V_11 ) ;
V_22 = V_19 -> V_413 [ V_602 ] ;
V_7 = F_216 ( V_22 -> V_452 ) ;
V_441 = & V_19 -> V_2 -> V_604 [ F_185 () ] ;
V_593 = F_275 ( V_11 ) -> V_591 + 1 ;
if ( F_189 ( V_19 -> V_2 , V_441 , V_593 ) ||
F_192 ( V_19 -> V_2 , V_22 ,
V_7 , V_593 ) ) {
V_593 = 0 ;
goto V_605;
}
V_13 = F_187 ( V_441 ) ;
V_13 -> V_598 = V_22 -> V_21 ;
V_13 -> V_546 = F_207 ( V_11 ) ;
V_17 = F_127 ( V_233 -> V_233 . V_333 , V_11 -> V_4 ,
V_13 -> V_546 , V_479 ) ;
if ( F_129 ( F_130 ( V_233 -> V_233 . V_333 , V_17 ) ) ) {
F_196 ( V_22 ) ;
V_593 = 0 ;
goto V_605;
}
V_13 -> V_599 = V_17 & V_600 ;
V_13 -> V_17 = V_17 & ~ V_600 ;
V_603 = F_255 ( V_19 , V_11 ) ;
if ( V_593 == 1 ) {
V_603 |= V_606 | V_601 ;
V_13 -> V_459 = V_603 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_603 |= V_606 | V_607 ;
V_13 -> V_459 = V_603 ;
F_6 ( V_7 , NULL , V_13 ) ;
if ( F_274 ( V_19 , V_11 , V_441 , V_22 ) ) {
F_273 ( V_19 -> V_233 -> V_233 . V_333 , V_22 , V_13 ) ;
V_593 = 0 ;
goto V_605;
}
}
V_7 -> V_450 -= V_593 ;
V_7 -> V_442 += V_593 ;
V_441 -> V_442 += V_593 ;
F_272 () ;
F_188 ( V_19 , V_593 ) ;
if ( V_7 -> V_9 - V_7 -> V_442 < V_485 + 1 ) {
struct V_481 * V_482 = F_212 ( V_233 , V_602 ) ;
F_279 ( V_482 ) ;
}
V_605:
if ( V_593 > 0 ) {
struct V_588 * V_586 = F_216 ( V_19 -> V_586 ) ;
F_270 ( & V_586 -> V_589 ) ;
V_586 -> V_608 ++ ;
V_586 -> V_609 += V_11 -> V_264 ;
F_271 ( & V_586 -> V_589 ) ;
} else {
V_233 -> V_586 . V_610 ++ ;
F_115 ( V_11 ) ;
}
if ( V_7 -> V_442 >= V_22 -> V_611 )
F_211 ( V_19 , V_22 , V_7 ) ;
if ( V_7 -> V_442 <= V_593 && V_7 -> V_442 > 0 ) {
struct V_532 * V_533 = F_216 ( V_19 -> V_452 ) ;
F_242 ( V_533 ) ;
}
return V_612 ;
}
static inline void F_280 ( struct V_269 * V_233 , int V_480 )
{
if ( V_480 & V_613 )
F_139 ( V_233 , L_18 ) ;
if ( V_480 & V_614 )
F_139 ( V_233 , L_19 ) ;
if ( V_480 & V_615 )
F_139 ( V_233 , L_20 ) ;
}
static int F_281 ( struct V_616 * V_516 , int V_617 )
{
T_1 V_618 , V_619 , V_620 ;
int V_579 = 0 ;
struct V_18 * V_19 = F_86 ( V_516 -> V_233 ) ;
V_618 = F_3 ( V_19 -> V_2 ,
F_282 ( V_19 -> V_21 ) ) ;
V_618 &= ~ V_621 ;
V_620 = V_618 & V_367 ;
if ( V_620 ) {
F_280 ( V_19 -> V_233 , V_620 ) ;
F_1 ( V_19 -> V_2 , V_622 , 0 ) ;
F_1 ( V_19 -> V_2 , F_282 ( V_19 -> V_21 ) ,
V_618 & ~ V_367 ) ;
}
V_619 = V_618 & V_368 ;
V_619 |= V_19 -> V_623 ;
while ( V_619 && V_617 > 0 ) {
int V_442 ;
struct V_427 * V_355 ;
V_355 = F_208 ( V_19 , V_619 ) ;
if ( ! V_355 )
break;
V_442 = F_264 ( V_19 , V_617 , V_355 ) ;
V_579 += V_442 ;
V_617 -= V_442 ;
if ( V_617 > 0 ) {
V_619 &= ~ ( 1 << V_355 -> V_624 ) ;
}
}
if ( V_617 > 0 ) {
V_619 = 0 ;
F_283 ( V_516 ) ;
F_147 ( V_19 ) ;
}
V_19 -> V_623 = V_619 ;
return V_579 ;
}
static void F_284 ( struct V_18 * V_19 )
{
struct V_269 * V_625 = V_19 -> V_233 ;
F_163 ( V_19 ) ;
F_201 ( V_19 ) ;
F_285 ( & V_19 -> V_516 ) ;
F_147 ( V_19 ) ;
F_158 ( V_19 ) ;
F_286 ( V_625 -> V_519 ) ;
F_287 ( V_19 -> V_233 ) ;
}
static void F_288 ( struct V_18 * V_19 )
{
struct V_269 * V_625 = V_19 -> V_233 ;
F_171 ( V_19 ) ;
F_175 ( 10 ) ;
F_151 ( V_19 ) ;
F_289 ( & V_19 -> V_516 ) ;
F_290 ( V_19 -> V_233 ) ;
F_291 ( V_19 -> V_233 ) ;
F_173 ( V_19 ) ;
F_159 ( V_19 ) ;
F_292 ( V_625 -> V_519 ) ;
}
static inline int F_293 ( struct V_269 * V_233 , int V_361 )
{
if ( V_361 < 68 ) {
F_139 ( V_233 , L_21 ) ;
return - V_29 ;
}
if ( V_361 > 9676 ) {
F_294 ( V_233 , L_22 , V_361 ) ;
V_361 = 9676 ;
}
if ( ! F_102 ( F_145 ( V_361 ) , 8 ) ) {
F_294 ( V_233 , L_23 , V_361 ,
F_110 ( F_145 ( V_361 ) , 8 ) ) ;
V_361 = F_110 ( F_145 ( V_361 ) , 8 ) ;
}
return V_361 ;
}
static int F_295 ( struct V_269 * V_233 ,
struct V_626 * V_627 )
{
T_2 V_628 = V_627 -> V_629 ;
T_2 V_630 = V_627 -> V_631 ;
if ( V_627 -> V_629 == 0 || V_627 -> V_631 == 0 )
return - V_29 ;
if ( V_627 -> V_629 > V_632 )
V_628 = V_632 ;
else if ( ! F_102 ( V_627 -> V_629 , 16 ) )
V_628 = F_110 ( V_627 -> V_629 , 16 ) ;
if ( V_627 -> V_631 > V_633 )
V_630 = V_633 ;
else if ( ! F_102 ( V_627 -> V_631 , 32 ) )
V_630 = F_110 ( V_627 -> V_631 , 32 ) ;
if ( V_627 -> V_629 != V_628 ) {
F_294 ( V_233 , L_24 ,
V_627 -> V_629 , V_628 ) ;
V_627 -> V_629 = V_628 ;
}
if ( V_627 -> V_631 != V_630 ) {
F_294 ( V_233 , L_25 ,
V_627 -> V_631 , V_630 ) ;
V_627 -> V_631 = V_630 ;
}
return 0 ;
}
static void F_296 ( struct V_18 * V_19 , unsigned char * V_594 )
{
T_1 V_634 , V_635 , V_636 ;
V_634 = F_4 ( V_19 -> V_5 + V_381 ) ;
V_635 = F_4 ( V_19 -> V_2 -> V_637 + V_638 ) ;
V_636 = F_4 ( V_19 -> V_2 -> V_637 + V_639 ) ;
V_594 [ 0 ] = ( V_636 >> 24 ) & 0xFF ;
V_594 [ 1 ] = ( V_636 >> 16 ) & 0xFF ;
V_594 [ 2 ] = ( V_636 >> 8 ) & 0xFF ;
V_594 [ 3 ] = V_636 & 0xFF ;
V_594 [ 4 ] = V_635 & 0xFF ;
V_594 [ 5 ] = ( V_634 >> V_640 ) & 0xFF ;
}
static int F_297 ( struct V_18 * V_19 )
{
struct V_518 * V_641 ;
V_641 = F_298 ( V_19 -> V_233 , V_19 -> V_642 , F_240 , 0 ,
V_19 -> V_370 ) ;
if ( ! V_641 ) {
F_139 ( V_19 -> V_233 , L_26 ) ;
return - V_643 ;
}
V_641 -> V_644 &= V_645 ;
V_641 -> V_646 = V_641 -> V_644 ;
V_19 -> V_521 = 0 ;
V_19 -> V_522 = 0 ;
V_19 -> V_383 = 0 ;
return 0 ;
}
static void F_299 ( struct V_18 * V_19 )
{
struct V_269 * V_625 = V_19 -> V_233 ;
F_300 ( V_625 -> V_519 ) ;
}
static int F_301 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
unsigned char V_647 [ V_111 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_232 ;
V_232 = F_82 ( V_19 -> V_2 , V_19 -> V_21 , V_647 , true ) ;
if ( V_232 ) {
F_139 ( V_233 , L_27 ) ;
return V_232 ;
}
V_232 = F_82 ( V_19 -> V_2 , V_19 -> V_21 ,
V_233 -> V_270 , true ) ;
if ( V_232 ) {
F_139 ( V_233 , L_28 ) ;
return V_232 ;
}
V_232 = F_89 ( V_19 -> V_2 , V_19 -> V_21 , V_274 ) ;
if ( V_232 ) {
F_139 ( V_233 , L_29 ) ;
return V_232 ;
}
V_232 = F_90 ( V_19 ) ;
if ( V_232 ) {
F_139 ( V_233 , L_30 ) ;
return V_232 ;
}
V_232 = F_236 ( V_19 ) ;
if ( V_232 ) {
F_139 ( V_19 -> V_233 , L_31 ) ;
return V_232 ;
}
V_232 = F_237 ( V_19 ) ;
if ( V_232 ) {
F_139 ( V_19 -> V_233 , L_32 ) ;
goto V_648;
}
V_232 = F_302 ( V_19 -> V_514 , F_238 , 0 , V_233 -> V_649 , V_19 ) ;
if ( V_232 ) {
F_139 ( V_19 -> V_233 , L_33 , V_19 -> V_514 ) ;
goto V_650;
}
F_290 ( V_19 -> V_233 ) ;
V_232 = F_297 ( V_19 ) ;
if ( V_232 < 0 )
goto V_651;
F_234 ( F_155 , V_19 , 1 ) ;
F_284 ( V_19 ) ;
return 0 ;
V_651:
F_303 ( V_19 -> V_514 , V_19 ) ;
V_650:
F_232 ( V_19 ) ;
V_648:
F_235 ( V_19 ) ;
return V_232 ;
}
static int F_304 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_532 * V_533 ;
int V_364 ;
F_288 ( V_19 ) ;
F_299 ( V_19 ) ;
F_234 ( F_153 , V_19 , 1 ) ;
F_303 ( V_19 -> V_514 , V_19 ) ;
F_148 (cpu) {
V_533 = F_193 ( V_19 -> V_452 , V_364 ) ;
F_305 ( & V_533 -> V_537 ) ;
V_533 -> V_535 = false ;
F_306 ( & V_533 -> V_542 ) ;
}
F_235 ( V_19 ) ;
F_232 ( V_19 ) ;
return 0 ;
}
static void F_307 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_652 * V_653 ;
int V_21 = V_19 -> V_21 ;
bool V_654 = V_233 -> V_392 & V_655 ;
F_46 ( V_2 , V_21 , V_233 -> V_392 & V_656 ) ;
F_47 ( V_2 , V_21 , V_114 , V_654 ) ;
F_47 ( V_2 , V_21 , V_196 , V_654 ) ;
F_88 ( V_2 , V_21 ) ;
if ( V_654 && ! F_308 ( V_233 ) ) {
F_309 (ha, dev)
F_82 ( V_2 , V_21 , V_653 -> V_594 , true ) ;
}
}
static int F_310 ( struct V_269 * V_233 , void * V_596 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
const struct V_657 * V_594 = V_596 ;
int V_232 ;
if ( ! F_311 ( V_594 -> V_658 ) ) {
V_232 = - V_659 ;
goto error;
}
if ( ! F_246 ( V_233 ) ) {
V_232 = F_85 ( V_233 , V_594 -> V_658 ) ;
if ( ! V_232 )
return 0 ;
V_232 = F_85 ( V_233 , V_233 -> V_270 ) ;
if ( V_232 )
goto error;
}
F_288 ( V_19 ) ;
V_232 = F_85 ( V_233 , V_594 -> V_658 ) ;
if ( ! V_232 )
goto V_660;
V_232 = F_85 ( V_233 , V_233 -> V_270 ) ;
if ( V_232 )
goto error;
V_660:
F_284 ( V_19 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
return 0 ;
error:
F_139 ( V_233 , L_34 ) ;
return V_232 ;
}
static int F_312 ( struct V_269 * V_233 , int V_361 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
int V_232 ;
V_361 = F_293 ( V_233 , V_361 ) ;
if ( V_361 < 0 ) {
V_232 = V_361 ;
goto error;
}
if ( ! F_246 ( V_233 ) ) {
V_232 = F_144 ( V_233 , V_361 ) ;
if ( ! V_232 ) {
V_19 -> V_309 = F_145 ( V_361 ) ;
return 0 ;
}
V_232 = F_144 ( V_233 , V_233 -> V_361 ) ;
if ( V_232 )
goto error;
}
F_288 ( V_19 ) ;
V_232 = F_144 ( V_233 , V_361 ) ;
if ( ! V_232 ) {
V_19 -> V_309 = F_145 ( V_361 ) ;
goto V_660;
}
V_232 = F_144 ( V_233 , V_233 -> V_361 ) ;
if ( V_232 )
goto error;
V_660:
F_284 ( V_19 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
return 0 ;
error:
F_139 ( V_233 , L_35 ) ;
return V_232 ;
}
static struct V_661 *
F_313 ( struct V_269 * V_233 , struct V_661 * V_586 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
unsigned int V_101 ;
int V_364 ;
F_314 (cpu) {
struct V_588 * V_662 ;
T_9 V_590 ;
T_9 V_582 ;
T_9 V_608 ;
T_9 V_609 ;
V_662 = F_193 ( V_19 -> V_586 , V_364 ) ;
do {
V_101 = F_315 ( & V_662 -> V_589 ) ;
V_590 = V_662 -> V_590 ;
V_582 = V_662 -> V_582 ;
V_608 = V_662 -> V_608 ;
V_609 = V_662 -> V_609 ;
} while ( F_316 ( & V_662 -> V_589 , V_101 ) );
V_586 -> V_590 += V_590 ;
V_586 -> V_582 += V_582 ;
V_586 -> V_608 += V_608 ;
V_586 -> V_609 += V_609 ;
}
V_586 -> V_587 = V_233 -> V_586 . V_587 ;
V_586 -> V_663 = V_233 -> V_586 . V_663 ;
V_586 -> V_610 = V_233 -> V_586 . V_610 ;
return V_586 ;
}
static int F_317 ( struct V_269 * V_233 , struct V_664 * V_665 , int V_666 )
{
int V_147 ;
if ( ! V_233 -> V_519 )
return - V_667 ;
V_147 = F_318 ( V_233 -> V_519 , V_665 , V_666 ) ;
if ( ! V_147 )
F_240 ( V_233 ) ;
return V_147 ;
}
static int F_319 ( struct V_269 * V_233 ,
struct V_668 * V_669 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
int V_390 ;
for ( V_390 = 0 ; V_390 < V_357 ; V_390 ++ ) {
struct V_427 * V_355 = V_19 -> V_326 [ V_390 ] ;
V_355 -> V_478 = V_669 -> V_670 ;
V_355 -> V_476 = V_669 -> V_671 ;
F_203 ( V_19 , V_355 , V_355 -> V_476 ) ;
F_204 ( V_19 , V_355 , V_355 -> V_478 ) ;
}
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
struct V_412 * V_22 = V_19 -> V_413 [ V_390 ] ;
V_22 -> V_611 = V_669 -> V_672 ;
}
return 0 ;
}
static int F_320 ( struct V_269 * V_233 ,
struct V_668 * V_669 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
V_669 -> V_670 = V_19 -> V_326 [ 0 ] -> V_478 ;
V_669 -> V_671 = V_19 -> V_326 [ 0 ] -> V_476 ;
V_669 -> V_672 = V_19 -> V_413 [ 0 ] -> V_611 ;
return 0 ;
}
static void F_321 ( struct V_269 * V_233 ,
struct V_673 * V_674 )
{
F_322 ( V_674 -> V_675 , V_676 ,
sizeof( V_674 -> V_675 ) ) ;
F_322 ( V_674 -> V_677 , V_678 ,
sizeof( V_674 -> V_677 ) ) ;
F_322 ( V_674 -> V_679 , F_323 ( & V_233 -> V_233 ) ,
sizeof( V_674 -> V_679 ) ) ;
}
static void F_324 ( struct V_269 * V_233 ,
struct V_626 * V_627 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
V_627 -> V_680 = V_632 ;
V_627 -> V_681 = V_633 ;
V_627 -> V_629 = V_19 -> V_490 ;
V_627 -> V_631 = V_19 -> V_499 ;
}
static int F_325 ( struct V_269 * V_233 ,
struct V_626 * V_627 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
T_2 V_682 = V_19 -> V_490 ;
T_2 V_683 = V_19 -> V_499 ;
int V_232 ;
V_232 = F_295 ( V_233 , V_627 ) ;
if ( V_232 )
return V_232 ;
if ( ! F_246 ( V_233 ) ) {
V_19 -> V_490 = V_627 -> V_629 ;
V_19 -> V_499 = V_627 -> V_631 ;
return 0 ;
}
F_288 ( V_19 ) ;
F_235 ( V_19 ) ;
F_232 ( V_19 ) ;
V_19 -> V_490 = V_627 -> V_629 ;
V_19 -> V_499 = V_627 -> V_631 ;
V_232 = F_236 ( V_19 ) ;
if ( V_232 ) {
V_19 -> V_490 = V_682 ;
V_627 -> V_629 = V_682 ;
V_232 = F_236 ( V_19 ) ;
if ( V_232 )
goto V_684;
}
V_232 = F_237 ( V_19 ) ;
if ( V_232 ) {
V_19 -> V_499 = V_683 ;
V_627 -> V_631 = V_683 ;
V_232 = F_237 ( V_19 ) ;
if ( V_232 )
goto V_685;
}
F_284 ( V_19 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
return 0 ;
V_685:
F_235 ( V_19 ) ;
V_684:
F_139 ( V_233 , L_36 ) ;
return V_232 ;
}
static void F_326 ( struct V_18 * V_19 )
{
F_156 ( V_19 ) ;
F_160 ( V_19 ) ;
F_157 ( V_19 ) ;
F_162 ( V_19 ) ;
}
static int F_327 ( struct V_18 * V_19 )
{
struct V_314 * V_233 = V_19 -> V_233 -> V_233 . V_333 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 ;
int V_390 , V_364 , V_232 ;
if ( V_19 -> V_296 + V_357 > V_686 )
return - V_29 ;
F_173 ( V_19 ) ;
F_159 ( V_19 ) ;
V_19 -> V_413 = F_75 ( V_233 , V_411 , sizeof( * V_19 -> V_413 ) ,
V_98 ) ;
if ( ! V_19 -> V_413 )
return - V_148 ;
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
int V_687 = F_8 ( V_19 -> V_21 , V_390 ) ;
struct V_412 * V_22 ;
V_22 = F_328 ( V_233 , sizeof( * V_22 ) , V_98 ) ;
if ( ! V_22 )
return - V_148 ;
V_22 -> V_452 = F_329 ( struct V_6 ) ;
if ( ! V_22 -> V_452 ) {
V_232 = - V_148 ;
goto V_688;
}
V_22 -> V_21 = V_687 ;
V_22 -> V_483 = V_390 ;
V_22 -> V_611 = V_689 ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_452 , V_364 ) ;
V_7 -> V_364 = V_364 ;
}
V_19 -> V_413 [ V_390 ] = V_22 ;
}
V_19 -> V_326 = F_75 ( V_233 , V_357 , sizeof( * V_19 -> V_326 ) ,
V_98 ) ;
if ( ! V_19 -> V_326 ) {
V_232 = - V_148 ;
goto V_688;
}
for ( V_390 = 0 ; V_390 < V_357 ; V_390 ++ ) {
struct V_427 * V_355 ;
V_355 = F_328 ( V_233 , sizeof( * V_355 ) , V_98 ) ;
if ( ! V_355 ) {
V_232 = - V_148 ;
goto V_688;
}
V_355 -> V_21 = V_19 -> V_296 + V_390 ;
V_355 -> V_19 = V_19 -> V_21 ;
V_355 -> V_624 = V_390 ;
V_19 -> V_326 [ V_390 ] = V_355 ;
}
F_1 ( V_2 , F_330 ( V_19 -> V_21 ) , V_357 ) ;
for ( V_390 = 0 ; V_390 < V_357 ; V_390 ++ ) {
struct V_427 * V_355 = V_19 -> V_326 [ V_390 ] ;
V_355 -> V_9 = V_19 -> V_490 ;
V_355 -> V_476 = V_690 ;
V_355 -> V_478 = V_691 ;
}
F_171 ( V_19 ) ;
F_164 ( V_19 ) ;
F_96 ( V_19 ) ;
F_94 ( V_19 ) ;
V_19 -> V_309 = F_145 ( V_19 -> V_233 -> V_361 ) ;
V_232 = F_142 ( V_19 ) ;
if ( V_232 )
goto V_688;
return 0 ;
V_688:
for ( V_390 = 0 ; V_390 < V_411 ; V_390 ++ ) {
if ( ! V_19 -> V_413 [ V_390 ] )
continue;
F_331 ( V_19 -> V_413 [ V_390 ] -> V_452 ) ;
}
return V_232 ;
}
static int F_332 ( struct V_230 * V_231 ,
struct V_692 * V_693 ,
struct V_1 * V_2 ,
int * V_694 )
{
struct V_692 * V_642 ;
struct V_18 * V_19 ;
struct V_532 * V_533 ;
struct V_269 * V_233 ;
struct V_695 * V_696 ;
const char * V_697 ;
const char * V_698 ;
char V_699 [ V_111 ] ;
T_1 V_21 ;
int V_700 ;
int V_701 ;
int V_702 = 2 ;
int V_232 , V_26 , V_364 ;
V_233 = F_333 ( sizeof( struct V_18 ) , V_411 ,
V_357 ) ;
if ( ! V_233 )
return - V_148 ;
V_642 = F_334 ( V_693 , L_37 , 0 ) ;
if ( ! V_642 ) {
F_104 ( & V_231 -> V_233 , L_38 ) ;
V_232 = - V_643 ;
goto V_703;
}
V_701 = F_335 ( V_693 ) ;
if ( V_701 < 0 ) {
F_104 ( & V_231 -> V_233 , L_39 ) ;
V_232 = V_701 ;
goto V_703;
}
if ( F_336 ( V_693 , L_40 , & V_21 ) ) {
V_232 = - V_29 ;
F_104 ( & V_231 -> V_233 , L_41 ) ;
goto V_703;
}
V_233 -> V_704 = V_633 ;
V_233 -> V_705 = 5 * V_706 ;
V_233 -> V_707 = & V_708 ;
V_233 -> V_709 = & V_710 ;
V_19 = F_86 ( V_233 ) ;
V_19 -> V_514 = F_337 ( V_693 , 0 ) ;
if ( V_19 -> V_514 <= 0 ) {
V_232 = - V_29 ;
goto V_703;
}
if ( F_338 ( V_693 , L_42 ) )
V_19 -> V_392 |= V_393 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_296 = * V_694 ;
V_19 -> V_642 = V_642 ;
V_19 -> V_370 = V_701 ;
V_696 = F_339 ( V_231 , V_711 ,
V_702 + V_21 ) ;
V_19 -> V_5 = F_340 ( & V_231 -> V_233 , V_696 ) ;
if ( F_341 ( V_19 -> V_5 ) ) {
V_232 = F_342 ( V_19 -> V_5 ) ;
goto V_651;
}
V_19 -> V_586 = F_343 ( struct V_588 ) ;
if ( ! V_19 -> V_586 ) {
V_232 = - V_148 ;
goto V_651;
}
V_697 = F_344 ( V_693 ) ;
if ( V_697 && F_311 ( V_697 ) ) {
V_698 = L_43 ;
F_87 ( V_233 -> V_270 , V_697 ) ;
} else {
F_296 ( V_19 , V_699 ) ;
if ( F_311 ( V_699 ) ) {
V_698 = L_44 ;
F_87 ( V_233 -> V_270 , V_699 ) ;
} else {
V_698 = L_45 ;
F_345 ( V_233 ) ;
}
}
V_19 -> V_499 = V_633 ;
V_19 -> V_490 = V_632 ;
V_19 -> V_233 = V_233 ;
F_346 ( V_233 , & V_231 -> V_233 ) ;
V_232 = F_327 ( V_19 ) ;
if ( V_232 < 0 ) {
F_104 ( & V_231 -> V_233 , L_46 , V_21 ) ;
goto V_712;
}
F_326 ( V_19 ) ;
V_19 -> V_452 = F_329 ( struct V_532 ) ;
if ( ! V_19 -> V_452 ) {
V_232 = - V_148 ;
goto V_713;
}
F_148 (cpu) {
V_533 = F_193 ( V_19 -> V_452 , V_364 ) ;
F_347 ( & V_533 -> V_537 , V_714 ,
V_538 ) ;
V_533 -> V_537 . V_715 = F_247 ;
V_533 -> V_535 = false ;
F_348 ( & V_533 -> V_542 , F_245 ,
( unsigned long ) V_233 ) ;
}
F_349 ( V_233 , & V_19 -> V_516 , F_281 , V_716 ) ;
V_700 = V_717 | V_718 ;
V_233 -> V_700 = V_700 | V_719 ;
V_233 -> V_720 |= V_700 | V_719 | V_721 ;
V_233 -> V_722 |= V_700 ;
V_232 = F_350 ( V_233 ) ;
if ( V_232 < 0 ) {
F_104 ( & V_231 -> V_233 , L_47 ) ;
goto V_723;
}
F_294 ( V_233 , L_48 , V_698 , V_233 -> V_270 ) ;
* V_694 += V_357 ;
V_2 -> V_724 [ V_21 ] = V_19 ;
return 0 ;
V_723:
F_331 ( V_19 -> V_452 ) ;
V_713:
for ( V_26 = 0 ; V_26 < V_411 ; V_26 ++ )
F_331 ( V_19 -> V_413 [ V_26 ] -> V_452 ) ;
V_712:
F_331 ( V_19 -> V_586 ) ;
V_651:
F_351 ( V_19 -> V_514 ) ;
V_703:
F_352 ( V_642 ) ;
F_353 ( V_233 ) ;
return V_232 ;
}
static void F_354 ( struct V_18 * V_19 )
{
int V_26 ;
F_355 ( V_19 -> V_233 ) ;
F_352 ( V_19 -> V_642 ) ;
F_331 ( V_19 -> V_452 ) ;
F_331 ( V_19 -> V_586 ) ;
for ( V_26 = 0 ; V_26 < V_411 ; V_26 ++ )
F_331 ( V_19 -> V_413 [ V_26 ] -> V_452 ) ;
F_351 ( V_19 -> V_514 ) ;
F_353 ( V_19 -> V_233 ) ;
}
static void F_356 ( const struct V_725 * V_726 ,
struct V_1 * V_2 )
{
T_1 V_727 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 6 ; V_26 ++ ) {
F_1 ( V_2 , F_357 ( V_26 ) , 0 ) ;
F_1 ( V_2 , F_358 ( V_26 ) , 0 ) ;
if ( V_26 < 4 )
F_1 ( V_2 , F_359 ( V_26 ) , 0 ) ;
}
V_727 = 0 ;
for ( V_26 = 0 ; V_26 < V_726 -> V_728 ; V_26 ++ ) {
const struct V_729 * V_730 = V_726 -> V_730 + V_26 ;
F_1 ( V_2 , F_357 ( V_26 ) ,
( V_730 -> V_5 & 0xffff0000 ) | ( V_730 -> V_731 << 8 ) |
V_726 -> V_732 ) ;
F_1 ( V_2 , F_358 ( V_26 ) ,
( V_730 -> V_9 - 1 ) & 0xffff0000 ) ;
V_727 |= ( 1 << V_26 ) ;
}
F_1 ( V_2 , V_733 , V_727 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_189 ; V_19 ++ ) {
F_1 ( V_2 , F_361 ( V_19 ) ,
V_734 ) ;
F_1 ( V_2 , F_362 ( V_19 ) ,
V_735 ) ;
}
F_1 ( V_2 , V_736 ,
V_737 ) ;
F_1 ( V_2 , V_738 , 0x1 ) ;
}
static int F_363 ( struct V_230 * V_231 , struct V_1 * V_2 )
{
const struct V_725 * V_739 ;
int V_232 , V_26 ;
T_1 V_64 ;
if ( V_357 % 4 || ( V_357 > V_740 ) ||
( V_411 > V_23 ) ) {
F_104 ( & V_231 -> V_233 , L_49 ) ;
return - V_29 ;
}
V_739 = F_364 () ;
if ( V_739 )
F_356 ( V_739 , V_2 ) ;
V_64 = F_4 ( V_2 -> V_637 + V_741 ) ;
V_64 |= V_742 ;
F_2 ( V_64 , V_2 -> V_637 + V_741 ) ;
V_2 -> V_604 = F_75 ( & V_231 -> V_233 , F_195 () ,
sizeof( struct V_412 ) ,
V_98 ) ;
if ( ! V_2 -> V_604 )
return - V_148 ;
F_148 (i) {
V_2 -> V_604 [ V_26 ] . V_21 = V_26 ;
V_2 -> V_604 [ V_26 ] . V_9 = V_743 ;
V_232 = F_217 ( V_231 , & V_2 -> V_604 [ V_26 ] ,
V_743 , V_26 , V_2 ) ;
if ( V_232 < 0 )
return V_232 ;
}
F_360 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_189 ; V_26 ++ )
F_1 ( V_2 , F_330 ( V_26 ) , V_357 ) ;
F_2 ( V_744 ,
V_2 -> V_637 + V_745 ) ;
F_1 ( V_2 , V_746 , 0x1 ) ;
V_232 = F_119 ( V_231 , V_2 ) ;
if ( V_232 < 0 )
return V_232 ;
V_232 = F_79 ( V_231 , V_2 ) ;
if ( V_232 < 0 )
return V_232 ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_365 ( struct V_230 * V_231 )
{
struct V_692 * V_747 = V_231 -> V_233 . V_748 ;
struct V_692 * V_693 ;
struct V_1 * V_2 ;
struct V_695 * V_696 ;
int V_749 , V_296 ;
int V_232 ;
V_2 = F_328 ( & V_231 -> V_233 , sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_2 )
return - V_148 ;
V_696 = F_339 ( V_231 , V_711 , 0 ) ;
V_2 -> V_5 = F_340 ( & V_231 -> V_233 , V_696 ) ;
if ( F_341 ( V_2 -> V_5 ) )
return F_342 ( V_2 -> V_5 ) ;
V_696 = F_339 ( V_231 , V_711 , 1 ) ;
V_2 -> V_637 = F_340 ( & V_231 -> V_233 , V_696 ) ;
if ( F_341 ( V_2 -> V_637 ) )
return F_342 ( V_2 -> V_637 ) ;
V_2 -> V_750 = F_366 ( & V_231 -> V_233 , L_50 ) ;
if ( F_341 ( V_2 -> V_750 ) )
return F_342 ( V_2 -> V_750 ) ;
V_232 = F_367 ( V_2 -> V_750 ) ;
if ( V_232 < 0 )
return V_232 ;
V_2 -> V_751 = F_366 ( & V_231 -> V_233 , L_51 ) ;
if ( F_341 ( V_2 -> V_751 ) ) {
V_232 = F_342 ( V_2 -> V_751 ) ;
goto V_752;
}
V_232 = F_367 ( V_2 -> V_751 ) ;
if ( V_232 < 0 )
goto V_752;
V_2 -> V_399 = F_368 ( V_2 -> V_750 ) ;
V_232 = F_363 ( V_231 , V_2 ) ;
if ( V_232 < 0 ) {
F_104 ( & V_231 -> V_233 , L_52 ) ;
goto V_753;
}
V_749 = F_369 ( V_747 ) ;
if ( V_749 == 0 ) {
F_104 ( & V_231 -> V_233 , L_53 ) ;
V_232 = - V_643 ;
goto V_753;
}
V_2 -> V_724 = F_75 ( & V_231 -> V_233 , V_749 ,
sizeof( struct V_18 * ) ,
V_98 ) ;
if ( ! V_2 -> V_724 ) {
V_232 = - V_148 ;
goto V_753;
}
V_296 = 0 ;
F_370 (dn, port_node) {
V_232 = F_332 ( V_231 , V_693 , V_2 , & V_296 ) ;
if ( V_232 < 0 )
goto V_753;
}
F_371 ( V_231 , V_2 ) ;
return 0 ;
V_753:
F_372 ( V_2 -> V_751 ) ;
V_752:
F_372 ( V_2 -> V_750 ) ;
return V_232 ;
}
static int F_373 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = F_374 ( V_231 ) ;
struct V_692 * V_747 = V_231 -> V_233 . V_748 ;
struct V_692 * V_693 ;
int V_26 = 0 ;
F_370 (dn, port_node) {
if ( V_2 -> V_724 [ V_26 ] )
F_354 ( V_2 -> V_724 [ V_26 ] ) ;
V_26 ++ ;
}
for ( V_26 = 0 ; V_26 < V_320 ; V_26 ++ ) {
struct V_301 * V_302 = & V_2 -> V_321 [ V_26 ] ;
F_116 ( V_231 , V_2 , V_302 ) ;
}
F_148 (i) {
struct V_412 * V_441 = & V_2 -> V_604 [ V_26 ] ;
F_103 ( & V_231 -> V_233 ,
V_743 * V_488 ,
V_441 -> V_414 ,
V_441 -> V_489 ) ;
}
F_372 ( V_2 -> V_750 ) ;
F_372 ( V_2 -> V_751 ) ;
return 0 ;
}
