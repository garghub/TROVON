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
memset ( & V_277 . V_4 , 0 , sizeof( V_277 . V_4 ) ) ;
for ( V_27 = 0 ; V_27 < V_291 ; V_27 ++ ) {
V_277 . V_27 = V_27 ;
F_91 ( V_2 , & V_277 ) ;
}
V_283 . V_4 = 0 ;
for ( V_27 = 0 ; V_27 < V_292 ; V_27 ++ ) {
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
V_64 = F_3 ( V_19 -> V_2 , V_293 ) ;
V_64 &= ~ F_95 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_293 , V_64 ) ;
V_283 . V_286 = V_19 -> V_21 ;
V_283 . V_284 = 0 ;
V_283 . V_4 = 0 ;
V_283 . V_4 &= ~ V_294 ;
V_283 . V_4 |= V_19 -> V_295 ;
V_283 . V_4 &= ~ V_296 ;
F_92 ( V_19 -> V_2 , & V_283 ) ;
}
static void F_96 ( struct V_18 * V_19 )
{
T_1 V_64 ;
F_1 ( V_19 -> V_2 , F_97 ( V_19 -> V_21 ) ,
V_19 -> V_295 & V_297 ) ;
F_1 ( V_19 -> V_2 , F_98 ( V_19 -> V_21 ) ,
( V_19 -> V_295 >> V_298 ) ) ;
V_64 = F_3 ( V_19 -> V_2 , V_299 ) ;
V_64 |= F_99 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_299 , V_64 ) ;
}
static int F_100 ( struct V_230 * V_231 ,
struct V_1 * V_2 ,
struct V_300 * V_301 , int V_9 )
{
int V_302 ;
T_1 V_64 ;
V_302 = sizeof( T_1 ) * V_9 ;
V_301 -> V_303 = F_101 ( & V_231 -> V_233 , V_302 ,
& V_301 -> V_304 ,
V_98 ) ;
if ( ! V_301 -> V_303 )
return - V_148 ;
if ( ! F_102 ( ( T_1 ) V_301 -> V_303 , V_305 ) ) {
F_103 ( & V_231 -> V_233 , V_302 , V_301 -> V_303 ,
V_301 -> V_304 ) ;
F_104 ( & V_231 -> V_233 , L_1 ,
V_301 -> V_21 , V_305 ) ;
return - V_148 ;
}
F_1 ( V_2 , F_105 ( V_301 -> V_21 ) ,
V_301 -> V_304 ) ;
F_1 ( V_2 , F_106 ( V_301 -> V_21 ) , V_9 ) ;
V_64 = F_3 ( V_2 , F_107 ( V_301 -> V_21 ) ) ;
V_64 |= V_306 ;
F_1 ( V_2 , F_107 ( V_301 -> V_21 ) , V_64 ) ;
V_301 -> type = V_307 ;
V_301 -> V_9 = V_9 ;
V_301 -> V_308 = 0 ;
V_301 -> V_309 = 0 ;
F_108 ( & V_301 -> V_310 , 0 ) ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_300 * V_301 ,
int V_311 )
{
T_1 V_64 ;
V_301 -> V_311 = V_311 ;
V_64 = F_110 ( V_311 , 1 << V_312 ) ;
F_1 ( V_2 , F_111 ( V_301 -> V_21 ) , V_64 ) ;
}
static void F_112 ( struct V_313 * V_233 , struct V_1 * V_2 ,
struct V_300 * V_301 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_301 -> V_309 ; V_26 ++ ) {
T_4 V_17 ;
T_1 V_314 ;
V_17 = F_3 ( V_2 ,
F_113 ( V_301 -> V_21 ) ) ;
V_314 = F_3 ( V_2 , V_315 ) ;
F_114 ( V_233 , V_17 ,
V_301 -> V_311 , V_316 ) ;
if ( ! V_314 )
break;
F_115 ( (struct V_10 * ) V_314 ) ;
}
V_301 -> V_309 -= V_26 ;
}
static int F_116 ( struct V_230 * V_231 ,
struct V_1 * V_2 ,
struct V_300 * V_301 )
{
T_1 V_64 ;
F_112 ( & V_231 -> V_233 , V_2 , V_301 ) ;
if ( V_301 -> V_309 ) {
F_117 ( 1 , L_2 , V_301 -> V_21 ) ;
return 0 ;
}
V_64 = F_3 ( V_2 , F_107 ( V_301 -> V_21 ) ) ;
V_64 |= V_317 ;
F_1 ( V_2 , F_107 ( V_301 -> V_21 ) , V_64 ) ;
F_103 ( & V_231 -> V_233 , sizeof( T_1 ) * V_301 -> V_9 ,
V_301 -> V_303 ,
V_301 -> V_304 ) ;
return 0 ;
}
static int F_118 ( struct V_230 * V_231 ,
struct V_1 * V_2 )
{
int V_26 , V_232 , V_9 ;
struct V_300 * V_301 ;
V_9 = V_318 ;
for ( V_26 = 0 ; V_26 < V_319 ; V_26 ++ ) {
V_301 = & V_2 -> V_320 [ V_26 ] ;
V_301 -> V_21 = V_26 ;
V_232 = F_100 ( V_231 , V_2 , V_301 , V_9 ) ;
if ( V_232 )
goto V_321;
F_109 ( V_2 , V_301 , 0 ) ;
}
return 0 ;
V_321:
F_104 ( & V_231 -> V_233 , L_3 , V_26 , V_9 ) ;
for ( V_26 = V_26 - 1 ; V_26 >= 0 ; V_26 -- )
F_116 ( V_231 , V_2 , & V_2 -> V_320 [ V_26 ] ) ;
return V_232 ;
}
static int F_119 ( struct V_230 * V_231 , struct V_1 * V_2 )
{
int V_26 , V_232 ;
for ( V_26 = 0 ; V_26 < V_319 ; V_26 ++ ) {
F_1 ( V_2 , F_120 ( V_26 ) , 0 ) ;
F_1 ( V_2 , F_121 ( V_26 ) , 0 ) ;
}
V_2 -> V_320 = F_75 ( & V_231 -> V_233 , V_319 ,
sizeof( struct V_300 ) , V_98 ) ;
if ( ! V_2 -> V_320 )
return - V_148 ;
V_232 = F_118 ( V_231 , V_2 ) ;
if ( V_232 < 0 )
return V_232 ;
return 0 ;
}
static void F_122 ( struct V_18 * V_19 ,
int V_322 , int V_323 )
{
T_1 V_64 ;
int V_324 ;
V_324 = V_19 -> V_325 [ V_322 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_324 ) ) ;
V_64 &= ~ V_326 ;
V_64 |= ( ( V_323 << V_327 ) &
V_326 ) ;
F_1 ( V_19 -> V_2 , F_123 ( V_324 ) , V_64 ) ;
}
static void F_124 ( struct V_18 * V_19 ,
int V_322 , int V_328 )
{
T_1 V_64 ;
int V_324 ;
V_324 = V_19 -> V_325 [ V_322 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_324 ) ) ;
V_64 &= ~ V_329 ;
V_64 |= ( ( V_328 << V_330 ) &
V_329 ) ;
F_1 ( V_19 -> V_2 , F_123 ( V_324 ) , V_64 ) ;
}
static struct V_10 * F_125 ( struct V_18 * V_19 ,
struct V_300 * V_301 ,
T_4 * V_17 ,
T_5 V_331 )
{
struct V_10 * V_11 ;
T_4 V_304 ;
V_11 = F_126 ( V_301 -> V_308 , V_331 ) ;
if ( ! V_11 )
return NULL ;
V_304 = F_127 ( V_19 -> V_233 -> V_233 . V_332 , V_11 -> V_333 ,
F_128 ( V_301 -> V_308 ) ,
V_316 ) ;
if ( F_129 ( F_130 ( V_19 -> V_233 -> V_233 . V_332 , V_304 ) ) ) {
F_115 ( V_11 ) ;
return NULL ;
}
* V_17 = V_304 ;
return V_11 ;
}
static inline T_1 F_131 ( T_1 V_334 , int V_335 )
{
T_1 V_336 ;
V_336 = V_334 & ~ ( 0xFF << V_337 ) ;
V_336 |= ( ( V_335 & 0xFF ) << V_337 ) ;
return V_336 ;
}
static inline int F_132 ( T_1 V_334 )
{
return ( V_334 >> V_337 ) & 0xFF ;
}
static inline void F_133 ( struct V_18 * V_19 , int V_335 ,
T_1 V_17 , T_1 V_338 )
{
F_1 ( V_19 -> V_2 , V_339 , V_338 ) ;
F_1 ( V_19 -> V_2 , F_134 ( V_335 ) , V_17 ) ;
}
static void F_135 ( struct V_18 * V_19 , int V_335 ,
T_1 V_17 , T_1 V_338 ,
int V_340 )
{
T_1 V_64 = 0 ;
V_64 |= ( V_340 & V_341 ) ;
F_1 ( V_19 -> V_2 , V_342 , V_64 ) ;
F_133 ( V_19 , V_335 ,
V_17 | V_343 ,
V_338 ) ;
}
static void F_136 ( struct V_18 * V_19 , T_1 V_336 ,
T_1 V_304 , T_1 V_334 )
{
int V_335 = F_132 ( V_336 ) ;
F_133 ( V_19 , V_335 , V_304 , V_334 ) ;
}
static int F_137 ( struct V_18 * V_19 ,
struct V_300 * V_301 , int V_309 )
{
struct V_10 * V_11 ;
int V_26 , V_311 , V_344 ;
T_1 V_336 ;
T_4 V_304 ;
V_311 = F_128 ( V_301 -> V_308 ) ;
V_344 = F_138 ( V_311 ) ;
if ( V_309 < 0 ||
( V_309 + V_301 -> V_309 > V_301 -> V_9 ) ) {
F_139 ( V_19 -> V_233 ,
L_4 ,
V_309 , V_301 -> V_21 ) ;
return 0 ;
}
V_336 = F_131 ( 0 , V_301 -> V_21 ) ;
for ( V_26 = 0 ; V_26 < V_309 ; V_26 ++ ) {
V_11 = F_125 ( V_19 , V_301 , & V_304 , V_98 ) ;
if ( ! V_11 )
break;
F_136 ( V_19 , V_336 , ( T_1 ) V_304 , ( T_1 ) V_11 ) ;
}
V_301 -> V_309 += V_26 ;
V_301 -> V_345 = V_301 -> V_309 / 4 ;
F_140 ( V_19 -> V_233 ,
L_5 ,
V_301 -> type == V_346 ? L_6 : L_7 ,
V_301 -> V_21 , V_301 -> V_308 , V_311 , V_344 ) ;
F_140 ( V_19 -> V_233 ,
L_8 ,
V_301 -> type == V_346 ? L_6 : L_7 ,
V_301 -> V_21 , V_26 , V_309 ) ;
return V_26 ;
}
static struct V_300 *
F_141 ( struct V_18 * V_19 , int V_335 , enum V_347 type ,
int V_308 )
{
struct V_300 * V_348 = & V_19 -> V_2 -> V_320 [ V_335 ] ;
int V_349 ;
if ( V_348 -> type != V_307 && V_348 -> type != type ) {
F_139 ( V_19 -> V_233 , L_9 ) ;
return NULL ;
}
if ( V_348 -> type == V_307 )
V_348 -> type = type ;
if ( ( ( type == V_350 ) && ( V_308 > V_348 -> V_308 ) ) ||
( V_348 -> V_308 == 0 ) ) {
int V_351 ;
V_351 = V_348 -> V_309 ;
if ( V_351 == 0 )
V_351 = type == V_350 ?
V_352 :
V_353 ;
else
F_112 ( V_19 -> V_233 -> V_233 . V_332 ,
V_19 -> V_2 , V_348 ) ;
V_348 -> V_308 = V_308 ;
V_349 = F_137 ( V_19 , V_348 , V_351 ) ;
if ( V_349 != V_351 ) {
F_117 ( 1 , L_10 ,
V_348 -> V_21 , V_349 , V_351 ) ;
return NULL ;
}
}
F_109 ( V_19 -> V_2 , V_348 ,
F_128 ( V_348 -> V_308 ) ) ;
return V_348 ;
}
static int F_142 ( struct V_18 * V_19 )
{
int V_354 ;
if ( ! V_19 -> V_355 ) {
V_19 -> V_355 =
F_141 ( V_19 , F_143 ( V_19 -> V_21 ) ,
V_350 ,
V_19 -> V_308 ) ;
if ( ! V_19 -> V_355 )
return - V_148 ;
V_19 -> V_355 -> V_145 |= ( 1 << V_19 -> V_21 ) ;
for ( V_354 = 0 ; V_354 < V_356 ; V_354 ++ )
F_122 ( V_19 , V_354 , V_19 -> V_355 -> V_21 ) ;
}
if ( ! V_19 -> V_357 ) {
V_19 -> V_357 =
F_141 ( V_19 , V_358 ,
V_346 ,
V_359 ) ;
if ( ! V_19 -> V_357 )
return - V_148 ;
V_19 -> V_357 -> V_145 |= ( 1 << V_19 -> V_21 ) ;
for ( V_354 = 0 ; V_354 < V_356 ; V_354 ++ )
F_124 ( V_19 , V_354 ,
V_19 -> V_357 -> V_21 ) ;
}
return 0 ;
}
static int F_144 ( struct V_269 * V_233 , int V_360 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_300 * V_361 = V_19 -> V_355 ;
int V_349 , V_351 = V_361 -> V_309 ;
int V_308 = F_145 ( V_360 ) ;
F_112 ( V_233 -> V_233 . V_332 , V_19 -> V_2 , V_361 ) ;
if ( V_361 -> V_309 ) {
F_117 ( 1 , L_2 , V_361 -> V_21 ) ;
return - V_362 ;
}
V_361 -> V_308 = V_308 ;
V_349 = F_137 ( V_19 , V_361 , V_351 ) ;
if ( V_349 != V_351 ) {
F_117 ( 1 , L_10 ,
V_361 -> V_21 , V_349 , V_351 ) ;
return - V_362 ;
}
F_109 ( V_19 -> V_2 , V_361 ,
F_128 ( V_361 -> V_308 ) ) ;
V_233 -> V_360 = V_360 ;
F_146 ( V_233 ) ;
return 0 ;
}
static inline void F_147 ( struct V_18 * V_19 )
{
int V_363 , V_364 = 0 ;
F_148 (cpu)
V_364 |= 1 << V_363 ;
F_1 ( V_19 -> V_2 , F_149 ( V_19 -> V_21 ) ,
F_150 ( V_364 ) ) ;
}
static inline void F_151 ( struct V_18 * V_19 )
{
int V_363 , V_364 = 0 ;
F_148 (cpu)
V_364 |= 1 << V_363 ;
F_1 ( V_19 -> V_2 , F_149 ( V_19 -> V_21 ) ,
F_152 ( V_364 ) ) ;
}
static void F_153 ( void * V_365 )
{
struct V_18 * V_19 = V_365 ;
F_1 ( V_19 -> V_2 , F_154 ( V_19 -> V_21 ) , 0 ) ;
}
static void F_155 ( void * V_365 )
{
struct V_18 * V_19 = V_365 ;
F_1 ( V_19 -> V_2 , F_154 ( V_19 -> V_21 ) ,
( V_366 |
V_367 ) ) ;
}
static void F_156 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_368 ) ;
switch ( V_19 -> V_369 ) {
case V_370 :
V_64 |= V_371 ;
break;
case V_372 :
V_64 |= V_373 ;
default:
V_64 &= ~ V_374 ;
}
F_2 ( V_64 , V_19 -> V_5 + V_368 ) ;
}
static void F_157 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_375 ) ;
V_64 |= V_376 ;
F_2 ( V_64 , V_19 -> V_5 + V_375 ) ;
}
static void F_158 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_377 ) ;
V_64 |= V_378 ;
V_64 |= V_379 ;
F_2 ( V_64 , V_19 -> V_5 + V_377 ) ;
}
static void F_159 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_377 ) ;
V_64 &= ~ ( V_378 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_377 ) ;
}
static void F_160 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_380 ) &
~ V_381 ;
F_2 ( V_64 , V_19 -> V_5 + V_380 ) ;
}
static void F_161 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_380 ) ;
if ( V_19 -> V_382 == 1000 )
V_64 |= V_383 ;
else
V_64 &= ~ V_383 ;
if ( V_19 -> V_369 == V_370 )
V_64 |= V_384 ;
else
V_64 &= ~ V_384 ;
F_2 ( V_64 , V_19 -> V_5 + V_380 ) ;
}
static void F_162 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_368 ) &
~ V_385 ;
F_2 ( V_64 , V_19 -> V_5 + V_368 ) ;
while ( F_4 ( V_19 -> V_5 + V_368 ) &
V_385 )
continue;
}
static inline void F_163 ( struct V_18 * V_19 )
{
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_377 ) ;
V_64 &= ~ V_386 ;
V_64 |= ( ( ( V_19 -> V_308 - V_194 ) / 2 ) <<
V_387 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_377 ) ;
}
static void F_164 ( struct V_18 * V_19 )
{
int V_388 , V_64 , V_389 , V_390 , V_322 ;
if ( V_19 -> V_391 & V_392 )
F_161 ( V_19 ) ;
V_64 = F_4 ( V_19 -> V_5 + V_393 ) ;
V_64 &= ~ V_394 ;
V_64 |= F_165 ( 64 - 4 - 2 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_393 ) ;
V_388 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_395 ,
V_388 ) ;
F_1 ( V_19 -> V_2 , V_396 , 0 ) ;
for ( V_389 = 0 ; V_389 < V_23 ; V_389 ++ ) {
V_390 = F_8 ( V_19 -> V_21 , V_389 ) ;
F_1 ( V_19 -> V_2 ,
F_166 ( V_390 ) , 0 ) ;
}
F_1 ( V_19 -> V_2 , V_397 ,
V_19 -> V_2 -> V_398 / V_399 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_400 ) ;
V_64 &= ~ V_401 ;
V_64 |= F_167 ( 1 ) ;
V_64 |= V_402 ;
F_1 ( V_19 -> V_2 , V_400 , V_64 ) ;
V_64 = V_403 ;
F_1 ( V_19 -> V_2 , V_404 , V_64 ) ;
F_1 ( V_19 -> V_2 , F_168 ( V_19 -> V_21 ) ,
V_405 |
F_169 ( 256 ) ) ;
for ( V_322 = 0 ; V_322 < V_356 ; V_322 ++ ) {
V_389 = V_19 -> V_325 [ V_322 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_389 ) ) ;
V_64 |= V_406 |
V_407 ;
F_1 ( V_19 -> V_2 , F_123 ( V_389 ) , V_64 ) ;
}
F_151 ( V_19 ) ;
}
static void F_170 ( struct V_18 * V_19 )
{
T_1 V_64 ;
int V_322 , V_389 ;
for ( V_322 = 0 ; V_322 < V_356 ; V_322 ++ ) {
V_389 = V_19 -> V_325 [ V_322 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_389 ) ) ;
V_64 &= ~ V_408 ;
F_1 ( V_19 -> V_2 , F_123 ( V_389 ) , V_64 ) ;
}
}
static void F_171 ( struct V_18 * V_19 )
{
T_1 V_64 ;
int V_322 , V_389 ;
for ( V_322 = 0 ; V_322 < V_356 ; V_322 ++ ) {
V_389 = V_19 -> V_325 [ V_322 ] -> V_21 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_389 ) ) ;
V_64 |= V_408 ;
F_1 ( V_19 -> V_2 , F_123 ( V_389 ) , V_64 ) ;
}
}
static void F_172 ( struct V_18 * V_19 )
{
T_1 V_409 ;
int V_389 ;
int V_388 = F_7 ( V_19 ) ;
V_409 = 0 ;
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
struct V_411 * V_22 = V_19 -> V_412 [ V_389 ] ;
if ( V_22 -> V_413 != NULL )
V_409 |= ( 1 << V_389 ) ;
}
F_1 ( V_19 -> V_2 , V_395 , V_388 ) ;
F_1 ( V_19 -> V_2 , V_414 , V_409 ) ;
}
static void F_173 ( struct V_18 * V_19 )
{
T_1 V_415 ;
int V_416 ;
int V_388 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_395 , V_388 ) ;
V_415 = ( F_3 ( V_19 -> V_2 , V_414 ) ) &
V_417 ;
if ( V_415 != 0 )
F_1 ( V_19 -> V_2 , V_414 ,
( V_415 << V_418 ) ) ;
V_416 = 0 ;
do {
if ( V_416 >= V_419 ) {
F_174 ( V_19 -> V_233 ,
L_11 ,
V_415 ) ;
break;
}
F_175 ( 1 ) ;
V_416 ++ ;
V_415 = F_3 ( V_19 -> V_2 , V_414 ) ;
} while ( V_415 & V_417 );
}
static inline int
F_176 ( struct V_18 * V_19 , int V_420 )
{
T_1 V_64 = F_3 ( V_19 -> V_2 , F_177 ( V_420 ) ) ;
return V_64 & V_421 ;
}
static inline void
F_178 ( struct V_18 * V_19 , int V_420 ,
int V_422 , int V_423 )
{
T_1 V_64 = V_422 | ( V_423 << V_424 ) ;
F_1 ( V_19 -> V_2 , F_179 ( V_420 ) , V_64 ) ;
}
static inline struct V_425 *
F_180 ( struct V_426 * V_354 )
{
int V_427 = V_354 -> V_428 ;
V_354 -> V_428 = F_181 ( V_354 , V_427 ) ;
F_182 ( V_354 -> V_413 + V_354 -> V_428 ) ;
return V_354 -> V_413 + V_427 ;
}
static void F_183 ( struct V_18 * V_19 ,
int V_324 , int V_3 )
{
T_1 V_64 ;
V_3 = V_3 >> 5 ;
V_64 = F_3 ( V_19 -> V_2 , F_123 ( V_324 ) ) ;
V_64 &= ~ V_429 ;
V_64 |= ( ( V_3 << V_430 ) &
V_429 ) ;
F_1 ( V_19 -> V_2 , F_123 ( V_324 ) , V_64 ) ;
}
static T_1 F_184 ( struct V_425 * V_427 )
{
int V_335 = ( V_427 -> V_431 & V_432 ) >>
V_433 ;
int V_363 = F_185 () ;
return ( ( V_335 & 0xFF ) << V_337 ) |
( ( V_363 & 0xFF ) << V_434 ) ;
}
static int F_186 ( struct V_18 * V_19 ,
struct V_411 * V_22 )
{
T_1 V_64 ;
F_1 ( V_19 -> V_2 , V_435 , V_22 -> V_21 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_436 ) ;
return V_64 & V_437 ;
}
static struct V_12 *
F_187 ( struct V_411 * V_22 )
{
int V_13 = V_22 -> V_428 ;
V_22 -> V_428 = F_181 ( V_22 , V_13 ) ;
return V_22 -> V_413 + V_13 ;
}
static void F_188 ( struct V_18 * V_19 , int V_438 )
{
F_1 ( V_19 -> V_2 , V_439 , V_438 ) ;
}
static int F_189 ( struct V_1 * V_2 ,
struct V_411 * V_440 , int V_349 )
{
if ( ( V_440 -> V_441 + V_349 ) > V_440 -> V_9 ) {
int V_363 = F_185 () ;
T_1 V_64 = F_3 ( V_2 , F_190 ( V_363 ) ) ;
V_440 -> V_441 = V_64 & V_442 ;
}
if ( ( V_440 -> V_441 + V_349 ) > V_440 -> V_9 )
return - V_148 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_411 * V_22 , int V_349 )
{
T_1 V_64 ;
V_64 = ( V_22 -> V_21 << V_443 ) | V_349 ;
F_1 ( V_2 , V_444 , V_64 ) ;
V_64 = F_3 ( V_2 , V_445 ) ;
return V_64 & V_446 ;
}
static int F_192 ( struct V_1 * V_2 ,
struct V_411 * V_22 ,
struct V_6 * V_7 ,
int V_349 )
{
int V_447 , V_363 , V_448 ;
if ( V_7 -> V_449 >= V_349 )
return 0 ;
V_448 = 0 ;
F_148 (cpu) {
struct V_6 * V_450 ;
V_450 = F_193 ( V_22 -> V_451 , V_363 ) ;
V_448 += V_450 -> V_441 ;
V_448 += V_450 -> V_449 ;
}
V_447 = F_194 ( V_452 , V_349 - V_7 -> V_449 ) ;
V_448 += V_447 ;
if ( V_448 >
( V_22 -> V_9 - ( F_195 () * V_452 ) ) )
return - V_148 ;
V_7 -> V_449 += F_191 ( V_2 , V_22 , V_447 ) ;
if ( V_7 -> V_449 < V_349 )
return - V_148 ;
return 0 ;
}
static void F_196 ( struct V_411 * V_22 )
{
if ( V_22 -> V_428 == 0 )
V_22 -> V_428 = V_22 -> V_453 - 1 ;
else
V_22 -> V_428 -- ;
}
static T_1 F_197 ( int V_454 , int V_455 ,
int V_456 , int V_457 )
{
T_1 V_458 ;
V_458 = ( V_454 << V_459 ) ;
V_458 |= ( V_456 << V_460 ) ;
V_458 |= V_461 ;
if ( V_455 == F_51 ( V_218 ) ) {
V_458 &= ~ V_461 ;
V_458 &= ~ V_462 ;
} else {
V_458 |= V_462 ;
}
if ( V_457 == V_158 ) {
V_458 &= ~ V_463 ;
V_458 &= ~ V_464 ;
} else if ( V_457 == V_159 ) {
V_458 |= V_463 ;
V_458 &= ~ V_464 ;
} else {
V_458 |= V_465 ;
}
return V_458 ;
}
static inline int F_198 ( struct V_18 * V_19 ,
struct V_411 * V_22 )
{
T_1 V_64 ;
V_64 = F_3 ( V_19 -> V_2 , F_199 ( V_22 -> V_21 ) ) ;
return ( V_64 & V_466 ) >>
V_467 ;
}
static void F_200 ( void * V_365 )
{
struct V_18 * V_19 = V_365 ;
int V_389 ;
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
int V_21 = V_19 -> V_412 [ V_389 ] -> V_21 ;
F_3 ( V_19 -> V_2 , F_199 ( V_21 ) ) ;
}
}
static void F_201 ( struct V_18 * V_19 )
{
T_1 V_64 , V_9 , V_360 ;
int V_22 , V_388 ;
V_360 = V_19 -> V_308 * 8 ;
if ( V_360 > V_468 )
V_360 = V_468 ;
V_360 = 3 * V_360 ;
V_388 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_395 , V_388 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_469 ) ;
V_64 &= ~ V_468 ;
V_64 |= V_360 ;
F_1 ( V_19 -> V_2 , V_469 , V_64 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_404 ) ;
V_9 = V_64 & V_403 ;
if ( V_9 < V_360 ) {
V_9 = V_360 ;
V_64 &= ~ V_403 ;
V_64 |= V_9 ;
F_1 ( V_19 -> V_2 , V_404 , V_64 ) ;
}
for ( V_22 = 0 ; V_22 < V_410 ; V_22 ++ ) {
V_64 = F_3 ( V_19 -> V_2 ,
F_202 ( V_22 ) ) ;
V_9 = V_64 & V_470 ;
if ( V_9 < V_360 ) {
V_9 = V_360 ;
V_64 &= ~ V_470 ;
V_64 |= V_9 ;
F_1 ( V_19 -> V_2 ,
F_202 ( V_22 ) ,
V_64 ) ;
}
}
}
static void F_203 ( struct V_18 * V_19 ,
struct V_426 * V_354 , T_1 V_471 )
{
T_1 V_64 ;
V_64 = ( V_471 & V_472 ) ;
F_1 ( V_19 -> V_2 , V_473 , V_354 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_474 , V_64 ) ;
V_354 -> V_475 = V_471 ;
}
static void F_204 ( struct V_18 * V_19 ,
struct V_426 * V_354 , T_1 V_476 )
{
T_1 V_64 ;
V_64 = ( V_19 -> V_2 -> V_398 / V_399 ) * V_476 ;
F_1 ( V_19 -> V_2 , F_205 ( V_354 -> V_21 ) , V_64 ) ;
V_354 -> V_477 = V_476 ;
}
static void F_206 ( struct V_18 * V_19 ,
struct V_411 * V_22 ,
struct V_6 * V_7 , int V_349 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_349 ; V_26 ++ ) {
T_4 V_17 =
V_7 -> V_16 [ V_7 -> V_8 ] ;
struct V_10 * V_11 = V_7 -> V_14 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
F_114 ( V_19 -> V_233 -> V_233 . V_332 , V_17 ,
F_207 ( V_11 ) , V_478 ) ;
if ( ! V_11 )
continue;
F_115 ( V_11 ) ;
}
}
static inline struct V_426 * F_208 ( struct V_18 * V_19 ,
T_1 V_479 )
{
int V_389 = F_209 ( V_479 ) - 1 ;
return V_19 -> V_325 [ V_389 ] ;
}
static inline struct V_411 * F_210 ( struct V_18 * V_19 ,
T_1 V_479 )
{
int V_389 = F_209 ( V_479 ) - 1 ;
return V_19 -> V_412 [ V_389 ] ;
}
static void F_211 ( struct V_18 * V_19 , struct V_411 * V_22 ,
struct V_6 * V_7 )
{
struct V_480 * V_481 = F_212 ( V_19 -> V_233 , V_22 -> V_482 ) ;
int V_483 ;
if ( V_7 -> V_363 != F_185 () )
F_139 ( V_19 -> V_233 , L_12 ) ;
V_483 = F_198 ( V_19 , V_22 ) ;
if ( ! V_483 )
return;
F_206 ( V_19 , V_22 , V_7 , V_483 ) ;
V_7 -> V_441 -= V_483 ;
if ( F_213 ( V_481 ) )
if ( V_7 -> V_9 - V_7 -> V_441 >= V_484 + 1 )
F_214 ( V_481 ) ;
}
static unsigned int F_215 ( struct V_18 * V_19 , T_1 V_479 )
{
struct V_411 * V_22 ;
struct V_6 * V_7 ;
unsigned int V_485 = 0 ;
while ( V_479 ) {
V_22 = F_210 ( V_19 , V_479 ) ;
if ( ! V_22 )
break;
V_7 = F_216 ( V_22 -> V_451 ) ;
if ( V_7 -> V_441 ) {
F_211 ( V_19 , V_22 , V_7 ) ;
V_485 += V_7 -> V_441 ;
}
V_479 &= ~ ( 1 << V_22 -> V_482 ) ;
}
return V_485 ;
}
static int F_217 ( struct V_230 * V_231 ,
struct V_411 * V_440 ,
int V_486 , int V_363 ,
struct V_1 * V_2 )
{
V_440 -> V_413 = F_101 ( & V_231 -> V_233 ,
V_486 * V_487 ,
& V_440 -> V_488 , V_98 ) ;
if ( ! V_440 -> V_413 )
return - V_148 ;
V_440 -> V_453 = V_440 -> V_9 - 1 ;
V_440 -> V_428 = F_3 ( V_2 ,
F_218 ( V_363 ) ) ;
F_1 ( V_2 , F_219 ( V_363 ) ,
V_440 -> V_488 ) ;
F_1 ( V_2 , F_220 ( V_363 ) , V_486 ) ;
return 0 ;
}
static int F_221 ( struct V_18 * V_19 ,
struct V_426 * V_354 )
{
V_354 -> V_9 = V_19 -> V_489 ;
V_354 -> V_413 = F_101 ( V_19 -> V_233 -> V_233 . V_332 ,
V_354 -> V_9 * V_487 ,
& V_354 -> V_488 , V_98 ) ;
if ( ! V_354 -> V_413 )
return - V_148 ;
V_354 -> V_453 = V_354 -> V_9 - 1 ;
F_1 ( V_19 -> V_2 , F_177 ( V_354 -> V_21 ) , 0 ) ;
F_1 ( V_19 -> V_2 , V_473 , V_354 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_490 , V_354 -> V_488 ) ;
F_1 ( V_19 -> V_2 , V_491 , V_354 -> V_9 ) ;
F_1 ( V_19 -> V_2 , V_492 , 0 ) ;
F_183 ( V_19 , V_354 -> V_21 , V_493 ) ;
F_203 ( V_19 , V_354 , V_354 -> V_475 ) ;
F_204 ( V_19 , V_354 , V_354 -> V_477 ) ;
F_178 ( V_19 , V_354 -> V_21 , 0 , V_354 -> V_9 ) ;
return 0 ;
}
static void F_222 ( struct V_18 * V_19 ,
struct V_426 * V_354 )
{
int V_494 , V_26 ;
V_494 = F_176 ( V_19 , V_354 -> V_21 ) ;
if ( ! V_494 )
return;
for ( V_26 = 0 ; V_26 < V_494 ; V_26 ++ ) {
struct V_425 * V_427 = F_180 ( V_354 ) ;
T_1 V_336 = F_184 ( V_427 ) ;
F_136 ( V_19 , V_336 , V_427 -> V_17 ,
V_427 -> V_495 ) ;
}
F_178 ( V_19 , V_354 -> V_21 , V_494 , V_494 ) ;
}
static void F_223 ( struct V_18 * V_19 ,
struct V_426 * V_354 )
{
F_222 ( V_19 , V_354 ) ;
if ( V_354 -> V_413 )
F_103 ( V_19 -> V_233 -> V_233 . V_332 ,
V_354 -> V_9 * V_487 ,
V_354 -> V_413 ,
V_354 -> V_488 ) ;
V_354 -> V_413 = NULL ;
V_354 -> V_453 = 0 ;
V_354 -> V_428 = 0 ;
V_354 -> V_488 = 0 ;
F_1 ( V_19 -> V_2 , F_177 ( V_354 -> V_21 ) , 0 ) ;
F_1 ( V_19 -> V_2 , V_473 , V_354 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_490 , 0 ) ;
F_1 ( V_19 -> V_2 , V_491 , 0 ) ;
}
static int F_224 ( struct V_18 * V_19 ,
struct V_411 * V_22 )
{
T_1 V_64 ;
int V_363 , V_496 , V_497 , V_388 ;
struct V_6 * V_7 ;
V_22 -> V_9 = V_19 -> V_498 ;
V_22 -> V_413 = F_101 ( V_19 -> V_233 -> V_233 . V_332 ,
V_22 -> V_9 * V_487 ,
& V_22 -> V_488 , V_98 ) ;
if ( ! V_22 -> V_413 )
return - V_148 ;
V_22 -> V_453 = V_22 -> V_9 - 1 ;
F_1 ( V_19 -> V_2 , V_435 , V_22 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_499 , V_22 -> V_488 ) ;
F_1 ( V_19 -> V_2 , V_500 , V_22 -> V_9 &
V_501 ) ;
F_1 ( V_19 -> V_2 , V_502 , 0 ) ;
F_1 ( V_19 -> V_2 , V_503 ,
V_22 -> V_21 << V_504 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_436 ) ;
V_64 &= ~ V_437 ;
F_1 ( V_19 -> V_2 , V_436 , V_64 ) ;
V_497 = 16 ;
V_496 = ( V_19 -> V_21 * V_23 * V_497 ) +
( V_22 -> V_482 * V_497 ) ;
F_1 ( V_19 -> V_2 , V_505 ,
F_225 ( V_496 ) | V_506 |
F_226 ( V_497 / 2 ) ) ;
V_388 = F_7 ( V_19 ) ;
F_1 ( V_19 -> V_2 , V_395 , V_388 ) ;
V_64 = F_3 ( V_19 -> V_2 , F_227 ( V_22 -> V_482 ) ) ;
V_64 &= ~ V_507 ;
V_64 |= F_228 ( 1 ) ;
V_64 |= V_508 ;
F_1 ( V_19 -> V_2 , F_227 ( V_22 -> V_482 ) , V_64 ) ;
V_64 = V_470 ;
F_1 ( V_19 -> V_2 , F_202 ( V_22 -> V_482 ) ,
V_64 ) ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_451 , V_363 ) ;
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
V_7 -> V_441 = 0 ;
V_7 -> V_449 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_8 = 0 ;
}
return 0 ;
error:
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_451 , V_363 ) ;
F_42 ( V_7 -> V_14 ) ;
F_42 ( V_7 -> V_16 ) ;
}
F_103 ( V_19 -> V_233 -> V_233 . V_332 ,
V_22 -> V_9 * V_487 ,
V_22 -> V_413 , V_22 -> V_488 ) ;
return - V_148 ;
}
static void F_230 ( struct V_18 * V_19 ,
struct V_411 * V_22 )
{
struct V_6 * V_7 ;
int V_363 ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_451 , V_363 ) ;
F_42 ( V_7 -> V_14 ) ;
F_42 ( V_7 -> V_16 ) ;
}
if ( V_22 -> V_413 )
F_103 ( V_19 -> V_233 -> V_233 . V_332 ,
V_22 -> V_9 * V_487 ,
V_22 -> V_413 , V_22 -> V_488 ) ;
V_22 -> V_413 = NULL ;
V_22 -> V_453 = 0 ;
V_22 -> V_428 = 0 ;
V_22 -> V_488 = 0 ;
F_1 ( V_19 -> V_2 , F_166 ( V_22 -> V_21 ) , 0 ) ;
F_1 ( V_19 -> V_2 , V_435 , V_22 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_499 , 0 ) ;
F_1 ( V_19 -> V_2 , V_500 , 0 ) ;
}
static void F_231 ( struct V_18 * V_19 , struct V_411 * V_22 )
{
struct V_6 * V_7 ;
int V_416 , V_438 , V_363 ;
T_1 V_64 ;
F_1 ( V_19 -> V_2 , V_435 , V_22 -> V_21 ) ;
V_64 = F_3 ( V_19 -> V_2 , V_505 ) ;
V_64 |= V_509 ;
F_1 ( V_19 -> V_2 , V_505 , V_64 ) ;
V_416 = 0 ;
do {
if ( V_416 >= V_510 ) {
F_174 ( V_19 -> V_233 ,
L_13 ,
V_19 -> V_21 , V_22 -> V_482 ) ;
break;
}
F_175 ( 1 ) ;
V_416 ++ ;
V_438 = F_186 ( V_19 , V_22 ) ;
} while ( V_438 );
V_64 &= ~ V_509 ;
F_1 ( V_19 -> V_2 , V_505 , V_64 ) ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_451 , V_363 ) ;
F_206 ( V_19 , V_22 , V_7 , V_7 -> V_441 ) ;
V_7 -> V_441 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_8 = 0 ;
}
}
static void F_232 ( struct V_18 * V_19 )
{
struct V_411 * V_22 ;
int V_389 ;
T_1 V_64 ;
V_64 = F_3 ( V_19 -> V_2 , V_511 ) ;
V_64 |= F_233 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_511 , V_64 ) ;
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
V_22 = V_19 -> V_412 [ V_389 ] ;
F_231 ( V_19 , V_22 ) ;
F_230 ( V_19 , V_22 ) ;
}
F_234 ( F_200 , V_19 , 1 ) ;
V_64 &= ~ F_233 ( V_19 -> V_21 ) ;
F_1 ( V_19 -> V_2 , V_511 , V_64 ) ;
}
static void F_235 ( struct V_18 * V_19 )
{
int V_389 ;
for ( V_389 = 0 ; V_389 < V_356 ; V_389 ++ )
F_223 ( V_19 , V_19 -> V_325 [ V_389 ] ) ;
}
static int F_236 ( struct V_18 * V_19 )
{
int V_389 , V_232 ;
for ( V_389 = 0 ; V_389 < V_356 ; V_389 ++ ) {
V_232 = F_221 ( V_19 , V_19 -> V_325 [ V_389 ] ) ;
if ( V_232 )
goto V_512;
}
return 0 ;
V_512:
F_235 ( V_19 ) ;
return V_232 ;
}
static int F_237 ( struct V_18 * V_19 )
{
struct V_411 * V_22 ;
int V_389 , V_232 ;
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
V_22 = V_19 -> V_412 [ V_389 ] ;
V_232 = F_224 ( V_19 , V_22 ) ;
if ( V_232 )
goto V_512;
}
F_234 ( F_200 , V_19 , 1 ) ;
return 0 ;
V_512:
F_232 ( V_19 ) ;
return V_232 ;
}
static T_6 F_238 ( int V_513 , void * V_514 )
{
struct V_18 * V_19 = (struct V_18 * ) V_514 ;
F_151 ( V_19 ) ;
F_239 ( & V_19 -> V_515 ) ;
return V_516 ;
}
static void F_240 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_517 * V_518 = V_233 -> V_518 ;
int V_519 = 0 ;
T_1 V_64 ;
if ( V_518 -> V_520 ) {
if ( ( V_19 -> V_382 != V_518 -> V_382 ) ||
( V_19 -> V_521 != V_518 -> V_521 ) ) {
T_1 V_64 ;
V_64 = F_4 ( V_19 -> V_5 + V_375 ) ;
V_64 &= ~ ( V_522 |
V_523 |
V_524 |
V_525 |
V_526 ) ;
if ( V_518 -> V_521 )
V_64 |= V_524 ;
if ( V_518 -> V_382 == V_527 )
V_64 |= V_523 ;
else if ( V_518 -> V_382 == V_528 )
V_64 |= V_522 ;
F_2 ( V_64 , V_19 -> V_5 + V_375 ) ;
V_19 -> V_521 = V_518 -> V_521 ;
V_19 -> V_382 = V_518 -> V_382 ;
}
}
if ( V_518 -> V_520 != V_19 -> V_520 ) {
if ( ! V_518 -> V_520 ) {
V_19 -> V_521 = - 1 ;
V_19 -> V_382 = 0 ;
}
V_19 -> V_520 = V_518 -> V_520 ;
V_519 = 1 ;
}
if ( V_519 ) {
if ( V_518 -> V_520 ) {
V_64 = F_4 ( V_19 -> V_5 + V_375 ) ;
V_64 |= ( V_529 |
V_530 ) ;
F_2 ( V_64 , V_19 -> V_5 + V_375 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
} else {
F_171 ( V_19 ) ;
F_173 ( V_19 ) ;
}
F_241 ( V_518 ) ;
}
}
static void F_242 ( struct V_531 * V_532 )
{
T_7 V_533 ;
if ( ! V_532 -> V_534 ) {
V_532 -> V_534 = true ;
V_533 = F_243 ( 0 , V_535 ) ;
F_244 ( & V_532 -> V_536 , V_533 ,
V_537 ) ;
}
}
static void F_245 ( unsigned long V_4 )
{
struct V_269 * V_233 = (struct V_269 * ) V_4 ;
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_531 * V_532 = F_216 ( V_19 -> V_451 ) ;
unsigned int V_485 , V_479 ;
if ( ! F_246 ( V_233 ) )
return;
V_532 -> V_534 = false ;
V_479 = ( 1 << V_410 ) - 1 ;
V_485 = F_215 ( V_19 , V_479 ) ;
if ( V_485 )
F_242 ( V_532 ) ;
}
static enum V_538 F_247 ( struct V_539 * V_540 )
{
struct V_531 * V_532 = F_248 ( V_540 ,
struct V_531 ,
V_536 ) ;
F_249 ( & V_532 -> V_541 ) ;
return V_542 ;
}
static void F_250 ( struct V_18 * V_19 ,
struct V_425 * V_427 )
{
T_1 V_431 = V_427 -> V_431 ;
switch ( V_431 & V_543 ) {
case V_544 :
F_139 ( V_19 -> V_233 , L_14 ,
V_431 , V_427 -> V_545 ) ;
break;
case V_546 :
F_139 ( V_19 -> V_233 , L_15 ,
V_431 , V_427 -> V_545 ) ;
break;
case V_547 :
F_139 ( V_19 -> V_233 , L_16 ,
V_431 , V_427 -> V_545 ) ;
break;
}
}
static void F_251 ( struct V_18 * V_19 , T_1 V_431 ,
struct V_10 * V_11 )
{
if ( ( ( V_431 & V_548 ) &&
! ( V_431 & V_549 ) ) ||
( V_431 & V_550 ) )
if ( ( ( V_431 & V_551 ) ||
( V_431 & V_552 ) ) &&
( V_431 & V_553 ) ) {
V_11 -> V_554 = 0 ;
V_11 -> V_555 = V_556 ;
return;
}
V_11 -> V_555 = V_557 ;
}
static int F_252 ( struct V_18 * V_19 ,
struct V_300 * V_301 ,
T_1 V_336 , int V_558 )
{
struct V_10 * V_11 ;
T_4 V_304 ;
if ( V_558 &&
( F_253 ( & V_301 -> V_310 ) < V_301 -> V_345 ) )
return 0 ;
V_11 = F_125 ( V_19 , V_301 , & V_304 , V_559 ) ;
if ( ! V_11 )
return - V_148 ;
F_136 ( V_19 , V_336 , ( T_1 ) V_304 , ( T_1 ) V_11 ) ;
F_254 ( & V_301 -> V_310 ) ;
return 0 ;
}
static T_1 F_255 ( struct V_18 * V_19 , struct V_10 * V_11 )
{
if ( V_11 -> V_555 == V_560 ) {
int V_456 = 0 ;
T_3 V_457 ;
if ( V_11 -> V_561 == F_256 ( V_218 ) ) {
struct V_163 * V_562 = F_257 ( V_11 ) ;
V_456 = V_562 -> V_563 ;
V_457 = V_562 -> V_561 ;
} else if ( V_11 -> V_561 == F_256 ( V_225 ) ) {
struct V_182 * V_564 = F_258 ( V_11 ) ;
if ( F_259 ( V_11 ) > 0 )
V_456 = ( F_259 ( V_11 ) >> 2 ) ;
V_457 = V_564 -> V_565 ;
} else {
return V_465 ;
}
return F_197 ( F_260 ( V_11 ) ,
V_11 -> V_561 , V_456 , V_457 ) ;
}
return V_465 | V_461 ;
}
static void F_261 ( struct V_18 * V_19 ,
struct V_425 * V_427 )
{
struct V_566 * V_567 ;
struct V_10 * V_11 ;
T_1 V_568 = V_427 -> V_431 ;
T_1 V_569 ;
T_1 V_570 ;
T_1 V_571 ;
T_1 V_572 ;
int V_340 ;
int V_573 ;
V_573 = ( V_568 & V_432 ) >>
V_433 ;
V_569 = V_427 -> V_17 ;
V_570 = V_427 -> V_495 ;
do {
V_11 = (struct V_10 * ) V_570 ;
V_567 = (struct V_566 * ) V_11 -> V_333 ;
V_340 = F_262 ( V_567 -> V_574 ) ;
V_571 = V_567 -> V_575 ;
V_572 = V_567 -> V_576 ;
F_135 ( V_19 , V_573 , V_569 ,
V_570 , V_340 ) ;
V_569 = V_571 ;
V_570 = V_572 ;
} while ( ! F_263 ( V_567 -> V_574 ) );
}
static int F_264 ( struct V_18 * V_19 , int V_577 ,
struct V_426 * V_354 )
{
struct V_269 * V_233 = V_19 -> V_233 ;
int V_494 ;
int V_578 = 0 ;
T_1 V_579 = 0 ;
T_1 V_580 = 0 ;
V_494 = F_176 ( V_19 , V_354 -> V_21 ) ;
if ( V_577 > V_494 )
V_577 = V_494 ;
while ( V_578 < V_577 ) {
struct V_425 * V_427 = F_180 ( V_354 ) ;
struct V_300 * V_301 ;
struct V_10 * V_11 ;
T_4 V_304 ;
T_1 V_336 , V_568 ;
int V_335 , V_581 , V_232 ;
V_578 ++ ;
V_568 = V_427 -> V_431 ;
V_581 = V_427 -> V_545 - V_194 ;
V_304 = V_427 -> V_17 ;
V_336 = F_184 ( V_427 ) ;
V_335 = F_132 ( V_336 ) ;
V_301 = & V_19 -> V_2 -> V_320 [ V_335 ] ;
if ( V_568 & V_582 ) {
F_261 ( V_19 , V_427 ) ;
continue;
}
if ( V_568 & V_583 ) {
V_584:
V_233 -> V_585 . V_586 ++ ;
F_250 ( V_19 , V_427 ) ;
F_136 ( V_19 , V_336 , V_427 -> V_17 ,
V_427 -> V_495 ) ;
continue;
}
V_11 = (struct V_10 * ) V_427 -> V_495 ;
V_232 = F_252 ( V_19 , V_301 , V_336 , 0 ) ;
if ( V_232 ) {
F_139 ( V_19 -> V_233 , L_17 ) ;
goto V_584;
}
F_114 ( V_233 -> V_233 . V_332 , V_304 ,
V_301 -> V_311 , V_316 ) ;
V_579 ++ ;
V_580 += V_581 ;
F_265 ( & V_301 -> V_310 ) ;
F_266 ( V_11 , V_194 ) ;
F_267 ( V_11 , V_581 ) ;
V_11 -> V_561 = F_268 ( V_11 , V_233 ) ;
F_251 ( V_19 , V_568 , V_11 ) ;
F_269 ( & V_19 -> V_515 , V_11 ) ;
}
if ( V_579 ) {
struct V_587 * V_585 = F_216 ( V_19 -> V_585 ) ;
F_270 ( & V_585 -> V_588 ) ;
V_585 -> V_589 += V_579 ;
V_585 -> V_581 += V_580 ;
F_271 ( & V_585 -> V_588 ) ;
}
F_272 () ;
F_178 ( V_19 , V_354 -> V_21 , V_578 , V_578 ) ;
return V_577 ;
}
static inline void
F_273 ( struct V_313 * V_233 , struct V_411 * V_22 ,
struct V_12 * V_496 )
{
F_114 ( V_233 , V_496 -> V_17 ,
V_496 -> V_545 , V_478 ) ;
F_196 ( V_22 ) ;
}
static int F_274 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_411 * V_440 ,
struct V_411 * V_22 )
{
struct V_6 * V_7 = F_216 ( V_22 -> V_451 ) ;
struct V_12 * V_13 ;
int V_26 ;
T_4 V_17 ;
for ( V_26 = 0 ; V_26 < F_275 ( V_11 ) -> V_590 ; V_26 ++ ) {
T_8 * V_591 = & F_275 ( V_11 ) -> V_592 [ V_26 ] ;
void * V_593 = F_276 ( V_591 -> V_594 . V_595 ) + V_591 -> V_596 ;
V_13 = F_187 ( V_440 ) ;
V_13 -> V_597 = V_22 -> V_21 ;
V_13 -> V_545 = V_591 -> V_9 ;
V_17 = F_127 ( V_19 -> V_233 -> V_233 . V_332 , V_593 ,
V_13 -> V_545 ,
V_478 ) ;
if ( F_130 ( V_19 -> V_233 -> V_233 . V_332 , V_17 ) ) {
F_196 ( V_22 ) ;
goto error;
}
V_13 -> V_598 = V_17 & V_599 ;
V_13 -> V_17 = V_17 & ( ~ V_599 ) ;
if ( V_26 == ( F_275 ( V_11 ) -> V_590 - 1 ) ) {
V_13 -> V_458 = V_600 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_13 -> V_458 = 0 ;
F_6 ( V_7 , NULL , V_13 ) ;
}
}
return 0 ;
error:
for ( V_26 = V_26 - 1 ; V_26 >= 0 ; V_26 -- ) {
V_13 = V_22 -> V_413 + V_26 ;
F_273 ( V_19 -> V_233 -> V_233 . V_332 , V_22 , V_13 ) ;
}
return - V_148 ;
}
static int F_277 ( struct V_10 * V_11 , struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_411 * V_22 , * V_440 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
T_4 V_17 ;
int V_592 = 0 ;
T_2 V_601 ;
T_1 V_602 ;
V_601 = F_278 ( V_11 ) ;
V_22 = V_19 -> V_412 [ V_601 ] ;
V_7 = F_216 ( V_22 -> V_451 ) ;
V_440 = & V_19 -> V_2 -> V_603 [ F_185 () ] ;
V_592 = F_275 ( V_11 ) -> V_590 + 1 ;
if ( F_189 ( V_19 -> V_2 , V_440 , V_592 ) ||
F_192 ( V_19 -> V_2 , V_22 ,
V_7 , V_592 ) ) {
V_592 = 0 ;
goto V_604;
}
V_13 = F_187 ( V_440 ) ;
V_13 -> V_597 = V_22 -> V_21 ;
V_13 -> V_545 = F_207 ( V_11 ) ;
V_17 = F_127 ( V_233 -> V_233 . V_332 , V_11 -> V_4 ,
V_13 -> V_545 , V_478 ) ;
if ( F_129 ( F_130 ( V_233 -> V_233 . V_332 , V_17 ) ) ) {
F_196 ( V_22 ) ;
V_592 = 0 ;
goto V_604;
}
V_13 -> V_598 = V_17 & V_599 ;
V_13 -> V_17 = V_17 & ~ V_599 ;
V_602 = F_255 ( V_19 , V_11 ) ;
if ( V_592 == 1 ) {
V_602 |= V_605 | V_600 ;
V_13 -> V_458 = V_602 ;
F_6 ( V_7 , V_11 , V_13 ) ;
} else {
V_602 |= V_605 | V_606 ;
V_13 -> V_458 = V_602 ;
F_6 ( V_7 , NULL , V_13 ) ;
if ( F_274 ( V_19 , V_11 , V_440 , V_22 ) ) {
F_273 ( V_19 -> V_233 -> V_233 . V_332 , V_22 , V_13 ) ;
V_592 = 0 ;
goto V_604;
}
}
V_7 -> V_449 -= V_592 ;
V_7 -> V_441 += V_592 ;
V_440 -> V_441 += V_592 ;
F_272 () ;
F_188 ( V_19 , V_592 ) ;
if ( V_7 -> V_9 - V_7 -> V_441 < V_484 + 1 ) {
struct V_480 * V_481 = F_212 ( V_233 , V_601 ) ;
F_279 ( V_481 ) ;
}
V_604:
if ( V_592 > 0 ) {
struct V_587 * V_585 = F_216 ( V_19 -> V_585 ) ;
F_270 ( & V_585 -> V_588 ) ;
V_585 -> V_607 ++ ;
V_585 -> V_608 += V_11 -> V_264 ;
F_271 ( & V_585 -> V_588 ) ;
} else {
V_233 -> V_585 . V_609 ++ ;
F_115 ( V_11 ) ;
}
if ( V_7 -> V_441 >= V_22 -> V_610 )
F_211 ( V_19 , V_22 , V_7 ) ;
if ( V_7 -> V_441 <= V_592 && V_7 -> V_441 > 0 ) {
struct V_531 * V_532 = F_216 ( V_19 -> V_451 ) ;
F_242 ( V_532 ) ;
}
return V_611 ;
}
static inline void F_280 ( struct V_269 * V_233 , int V_479 )
{
if ( V_479 & V_612 )
F_139 ( V_233 , L_18 ) ;
if ( V_479 & V_613 )
F_139 ( V_233 , L_19 ) ;
if ( V_479 & V_614 )
F_139 ( V_233 , L_20 ) ;
}
static int F_281 ( struct V_615 * V_515 , int V_616 )
{
T_1 V_617 , V_618 , V_619 ;
int V_578 = 0 ;
struct V_18 * V_19 = F_86 ( V_515 -> V_233 ) ;
V_617 = F_3 ( V_19 -> V_2 ,
F_282 ( V_19 -> V_21 ) ) ;
V_617 &= ~ V_620 ;
V_619 = V_617 & V_366 ;
if ( V_619 ) {
F_280 ( V_19 -> V_233 , V_619 ) ;
F_1 ( V_19 -> V_2 , V_621 , 0 ) ;
F_1 ( V_19 -> V_2 , F_282 ( V_19 -> V_21 ) ,
V_617 & ~ V_366 ) ;
}
V_618 = V_617 & V_367 ;
V_618 |= V_19 -> V_622 ;
while ( V_618 && V_616 > 0 ) {
int V_441 ;
struct V_426 * V_354 ;
V_354 = F_208 ( V_19 , V_618 ) ;
if ( ! V_354 )
break;
V_441 = F_264 ( V_19 , V_616 , V_354 ) ;
V_578 += V_441 ;
V_616 -= V_441 ;
if ( V_616 > 0 ) {
V_618 &= ~ ( 1 << V_354 -> V_623 ) ;
}
}
if ( V_616 > 0 ) {
V_618 = 0 ;
F_283 ( V_515 ) ;
F_147 ( V_19 ) ;
}
V_19 -> V_622 = V_618 ;
return V_578 ;
}
static void F_284 ( struct V_18 * V_19 )
{
struct V_269 * V_624 = V_19 -> V_233 ;
F_163 ( V_19 ) ;
F_201 ( V_19 ) ;
F_285 ( & V_19 -> V_515 ) ;
F_147 ( V_19 ) ;
F_158 ( V_19 ) ;
F_286 ( V_624 -> V_518 ) ;
F_287 ( V_19 -> V_233 ) ;
}
static void F_288 ( struct V_18 * V_19 )
{
struct V_269 * V_624 = V_19 -> V_233 ;
F_171 ( V_19 ) ;
F_175 ( 10 ) ;
F_151 ( V_19 ) ;
F_289 ( & V_19 -> V_515 ) ;
F_290 ( V_19 -> V_233 ) ;
F_291 ( V_19 -> V_233 ) ;
F_173 ( V_19 ) ;
F_159 ( V_19 ) ;
F_292 ( V_624 -> V_518 ) ;
}
static inline int F_293 ( struct V_269 * V_233 , int V_360 )
{
if ( V_360 < 68 ) {
F_139 ( V_233 , L_21 ) ;
return - V_29 ;
}
if ( V_360 > 9676 ) {
F_294 ( V_233 , L_22 , V_360 ) ;
V_360 = 9676 ;
}
if ( ! F_102 ( F_145 ( V_360 ) , 8 ) ) {
F_294 ( V_233 , L_23 , V_360 ,
F_110 ( F_145 ( V_360 ) , 8 ) ) ;
V_360 = F_110 ( F_145 ( V_360 ) , 8 ) ;
}
return V_360 ;
}
static int F_295 ( struct V_269 * V_233 ,
struct V_625 * V_626 )
{
T_2 V_627 = V_626 -> V_628 ;
T_2 V_629 = V_626 -> V_630 ;
if ( V_626 -> V_628 == 0 || V_626 -> V_630 == 0 )
return - V_29 ;
if ( V_626 -> V_628 > V_631 )
V_627 = V_631 ;
else if ( ! F_102 ( V_626 -> V_628 , 16 ) )
V_627 = F_110 ( V_626 -> V_628 , 16 ) ;
if ( V_626 -> V_630 > V_632 )
V_629 = V_632 ;
else if ( ! F_102 ( V_626 -> V_630 , 32 ) )
V_629 = F_110 ( V_626 -> V_630 , 32 ) ;
if ( V_626 -> V_628 != V_627 ) {
F_294 ( V_233 , L_24 ,
V_626 -> V_628 , V_627 ) ;
V_626 -> V_628 = V_627 ;
}
if ( V_626 -> V_630 != V_629 ) {
F_294 ( V_233 , L_25 ,
V_626 -> V_630 , V_629 ) ;
V_626 -> V_630 = V_629 ;
}
return 0 ;
}
static void F_296 ( struct V_18 * V_19 , unsigned char * V_593 )
{
T_1 V_633 , V_634 , V_635 ;
V_633 = F_4 ( V_19 -> V_5 + V_380 ) ;
V_634 = F_4 ( V_19 -> V_2 -> V_636 + V_637 ) ;
V_635 = F_4 ( V_19 -> V_2 -> V_636 + V_638 ) ;
V_593 [ 0 ] = ( V_635 >> 24 ) & 0xFF ;
V_593 [ 1 ] = ( V_635 >> 16 ) & 0xFF ;
V_593 [ 2 ] = ( V_635 >> 8 ) & 0xFF ;
V_593 [ 3 ] = V_635 & 0xFF ;
V_593 [ 4 ] = V_634 & 0xFF ;
V_593 [ 5 ] = ( V_633 >> V_639 ) & 0xFF ;
}
static int F_297 ( struct V_18 * V_19 )
{
struct V_517 * V_640 ;
V_640 = F_298 ( V_19 -> V_233 , V_19 -> V_641 , F_240 , 0 ,
V_19 -> V_369 ) ;
if ( ! V_640 ) {
F_139 ( V_19 -> V_233 , L_26 ) ;
return - V_642 ;
}
V_640 -> V_643 &= V_644 ;
V_640 -> V_645 = V_640 -> V_643 ;
V_19 -> V_520 = 0 ;
V_19 -> V_521 = 0 ;
V_19 -> V_382 = 0 ;
return 0 ;
}
static void F_299 ( struct V_18 * V_19 )
{
struct V_269 * V_624 = V_19 -> V_233 ;
F_300 ( V_624 -> V_518 ) ;
}
static int F_301 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
unsigned char V_646 [ V_111 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_232 ;
V_232 = F_82 ( V_19 -> V_2 , V_19 -> V_21 , V_646 , true ) ;
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
goto V_647;
}
V_232 = F_302 ( V_19 -> V_513 , F_238 , 0 , V_233 -> V_648 , V_19 ) ;
if ( V_232 ) {
F_139 ( V_19 -> V_233 , L_33 , V_19 -> V_513 ) ;
goto V_649;
}
F_290 ( V_19 -> V_233 ) ;
V_232 = F_297 ( V_19 ) ;
if ( V_232 < 0 )
goto V_650;
F_234 ( F_155 , V_19 , 1 ) ;
F_284 ( V_19 ) ;
return 0 ;
V_650:
F_303 ( V_19 -> V_513 , V_19 ) ;
V_649:
F_232 ( V_19 ) ;
V_647:
F_235 ( V_19 ) ;
return V_232 ;
}
static int F_304 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_531 * V_532 ;
int V_363 ;
F_288 ( V_19 ) ;
F_299 ( V_19 ) ;
F_234 ( F_153 , V_19 , 1 ) ;
F_303 ( V_19 -> V_513 , V_19 ) ;
F_148 (cpu) {
V_532 = F_193 ( V_19 -> V_451 , V_363 ) ;
F_305 ( & V_532 -> V_536 ) ;
V_532 -> V_534 = false ;
F_306 ( & V_532 -> V_541 ) ;
}
F_235 ( V_19 ) ;
F_232 ( V_19 ) ;
return 0 ;
}
static void F_307 ( struct V_269 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_651 * V_652 ;
int V_21 = V_19 -> V_21 ;
bool V_653 = V_233 -> V_391 & V_654 ;
F_46 ( V_2 , V_21 , V_233 -> V_391 & V_655 ) ;
F_47 ( V_2 , V_21 , V_114 , V_653 ) ;
F_47 ( V_2 , V_21 , V_196 , V_653 ) ;
F_88 ( V_2 , V_21 ) ;
if ( V_653 && ! F_308 ( V_233 ) ) {
F_309 (ha, dev)
F_82 ( V_2 , V_21 , V_652 -> V_593 , true ) ;
}
}
static int F_310 ( struct V_269 * V_233 , void * V_595 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
const struct V_656 * V_593 = V_595 ;
int V_232 ;
if ( ! F_311 ( V_593 -> V_657 ) ) {
V_232 = - V_658 ;
goto error;
}
if ( ! F_246 ( V_233 ) ) {
V_232 = F_85 ( V_233 , V_593 -> V_657 ) ;
if ( ! V_232 )
return 0 ;
V_232 = F_85 ( V_233 , V_233 -> V_270 ) ;
if ( V_232 )
goto error;
}
F_288 ( V_19 ) ;
V_232 = F_85 ( V_233 , V_593 -> V_657 ) ;
if ( ! V_232 )
goto V_659;
V_232 = F_85 ( V_233 , V_233 -> V_270 ) ;
if ( V_232 )
goto error;
V_659:
F_284 ( V_19 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
return 0 ;
error:
F_139 ( V_233 , L_34 ) ;
return V_232 ;
}
static int F_312 ( struct V_269 * V_233 , int V_360 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
int V_232 ;
V_360 = F_293 ( V_233 , V_360 ) ;
if ( V_360 < 0 ) {
V_232 = V_360 ;
goto error;
}
if ( ! F_246 ( V_233 ) ) {
V_232 = F_144 ( V_233 , V_360 ) ;
if ( ! V_232 ) {
V_19 -> V_308 = F_145 ( V_360 ) ;
return 0 ;
}
V_232 = F_144 ( V_233 , V_233 -> V_360 ) ;
if ( V_232 )
goto error;
}
F_288 ( V_19 ) ;
V_232 = F_144 ( V_233 , V_360 ) ;
if ( ! V_232 ) {
V_19 -> V_308 = F_145 ( V_360 ) ;
goto V_659;
}
V_232 = F_144 ( V_233 , V_233 -> V_360 ) ;
if ( V_232 )
goto error;
V_659:
F_284 ( V_19 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
return 0 ;
error:
F_139 ( V_233 , L_35 ) ;
return V_232 ;
}
static struct V_660 *
F_313 ( struct V_269 * V_233 , struct V_660 * V_585 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
unsigned int V_101 ;
int V_363 ;
F_314 (cpu) {
struct V_587 * V_661 ;
T_9 V_589 ;
T_9 V_581 ;
T_9 V_607 ;
T_9 V_608 ;
V_661 = F_193 ( V_19 -> V_585 , V_363 ) ;
do {
V_101 = F_315 ( & V_661 -> V_588 ) ;
V_589 = V_661 -> V_589 ;
V_581 = V_661 -> V_581 ;
V_607 = V_661 -> V_607 ;
V_608 = V_661 -> V_608 ;
} while ( F_316 ( & V_661 -> V_588 , V_101 ) );
V_585 -> V_589 += V_589 ;
V_585 -> V_581 += V_581 ;
V_585 -> V_607 += V_607 ;
V_585 -> V_608 += V_608 ;
}
V_585 -> V_586 = V_233 -> V_585 . V_586 ;
V_585 -> V_662 = V_233 -> V_585 . V_662 ;
V_585 -> V_609 = V_233 -> V_585 . V_609 ;
return V_585 ;
}
static int F_317 ( struct V_269 * V_233 , struct V_663 * V_664 , int V_665 )
{
int V_147 ;
if ( ! V_233 -> V_518 )
return - V_666 ;
V_147 = F_318 ( V_233 -> V_518 , V_664 , V_665 ) ;
if ( ! V_147 )
F_240 ( V_233 ) ;
return V_147 ;
}
static int F_319 ( struct V_269 * V_233 ,
struct V_667 * V_668 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
int V_389 ;
for ( V_389 = 0 ; V_389 < V_356 ; V_389 ++ ) {
struct V_426 * V_354 = V_19 -> V_325 [ V_389 ] ;
V_354 -> V_477 = V_668 -> V_669 ;
V_354 -> V_475 = V_668 -> V_670 ;
F_203 ( V_19 , V_354 , V_354 -> V_475 ) ;
F_204 ( V_19 , V_354 , V_354 -> V_477 ) ;
}
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
struct V_411 * V_22 = V_19 -> V_412 [ V_389 ] ;
V_22 -> V_610 = V_668 -> V_671 ;
}
return 0 ;
}
static int F_320 ( struct V_269 * V_233 ,
struct V_667 * V_668 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
V_668 -> V_669 = V_19 -> V_325 [ 0 ] -> V_477 ;
V_668 -> V_670 = V_19 -> V_325 [ 0 ] -> V_475 ;
V_668 -> V_671 = V_19 -> V_412 [ 0 ] -> V_610 ;
return 0 ;
}
static void F_321 ( struct V_269 * V_233 ,
struct V_672 * V_673 )
{
F_322 ( V_673 -> V_674 , V_675 ,
sizeof( V_673 -> V_674 ) ) ;
F_322 ( V_673 -> V_676 , V_677 ,
sizeof( V_673 -> V_676 ) ) ;
F_322 ( V_673 -> V_678 , F_323 ( & V_233 -> V_233 ) ,
sizeof( V_673 -> V_678 ) ) ;
}
static void F_324 ( struct V_269 * V_233 ,
struct V_625 * V_626 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
V_626 -> V_679 = V_631 ;
V_626 -> V_680 = V_632 ;
V_626 -> V_628 = V_19 -> V_489 ;
V_626 -> V_630 = V_19 -> V_498 ;
}
static int F_325 ( struct V_269 * V_233 ,
struct V_625 * V_626 )
{
struct V_18 * V_19 = F_86 ( V_233 ) ;
T_2 V_681 = V_19 -> V_489 ;
T_2 V_682 = V_19 -> V_498 ;
int V_232 ;
V_232 = F_295 ( V_233 , V_626 ) ;
if ( V_232 )
return V_232 ;
if ( ! F_246 ( V_233 ) ) {
V_19 -> V_489 = V_626 -> V_628 ;
V_19 -> V_498 = V_626 -> V_630 ;
return 0 ;
}
F_288 ( V_19 ) ;
F_235 ( V_19 ) ;
F_232 ( V_19 ) ;
V_19 -> V_489 = V_626 -> V_628 ;
V_19 -> V_498 = V_626 -> V_630 ;
V_232 = F_236 ( V_19 ) ;
if ( V_232 ) {
V_19 -> V_489 = V_681 ;
V_626 -> V_628 = V_681 ;
V_232 = F_236 ( V_19 ) ;
if ( V_232 )
goto V_683;
}
V_232 = F_237 ( V_19 ) ;
if ( V_232 ) {
V_19 -> V_498 = V_682 ;
V_626 -> V_630 = V_682 ;
V_232 = F_237 ( V_19 ) ;
if ( V_232 )
goto V_684;
}
F_284 ( V_19 ) ;
F_172 ( V_19 ) ;
F_170 ( V_19 ) ;
return 0 ;
V_684:
F_235 ( V_19 ) ;
V_683:
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
struct V_313 * V_233 = V_19 -> V_233 -> V_233 . V_332 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 ;
int V_389 , V_363 , V_232 ;
if ( V_19 -> V_295 + V_356 > V_685 )
return - V_29 ;
F_173 ( V_19 ) ;
F_159 ( V_19 ) ;
V_19 -> V_412 = F_75 ( V_233 , V_410 , sizeof( * V_19 -> V_412 ) ,
V_98 ) ;
if ( ! V_19 -> V_412 )
return - V_148 ;
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
int V_686 = F_8 ( V_19 -> V_21 , V_389 ) ;
struct V_411 * V_22 ;
V_22 = F_328 ( V_233 , sizeof( * V_22 ) , V_98 ) ;
if ( ! V_22 )
return - V_148 ;
V_22 -> V_451 = F_329 ( struct V_6 ) ;
if ( ! V_22 -> V_451 ) {
V_232 = - V_148 ;
goto V_687;
}
V_22 -> V_21 = V_686 ;
V_22 -> V_482 = V_389 ;
V_22 -> V_610 = V_688 ;
F_148 (cpu) {
V_7 = F_193 ( V_22 -> V_451 , V_363 ) ;
V_7 -> V_363 = V_363 ;
}
V_19 -> V_412 [ V_389 ] = V_22 ;
}
V_19 -> V_325 = F_75 ( V_233 , V_356 , sizeof( * V_19 -> V_325 ) ,
V_98 ) ;
if ( ! V_19 -> V_325 ) {
V_232 = - V_148 ;
goto V_687;
}
for ( V_389 = 0 ; V_389 < V_356 ; V_389 ++ ) {
struct V_426 * V_354 ;
V_354 = F_328 ( V_233 , sizeof( * V_354 ) , V_98 ) ;
if ( ! V_354 ) {
V_232 = - V_148 ;
goto V_687;
}
V_354 -> V_21 = V_19 -> V_295 + V_389 ;
V_354 -> V_19 = V_19 -> V_21 ;
V_354 -> V_623 = V_389 ;
V_19 -> V_325 [ V_389 ] = V_354 ;
}
F_1 ( V_2 , F_330 ( V_19 -> V_21 ) , V_356 ) ;
for ( V_389 = 0 ; V_389 < V_356 ; V_389 ++ ) {
struct V_426 * V_354 = V_19 -> V_325 [ V_389 ] ;
V_354 -> V_9 = V_19 -> V_489 ;
V_354 -> V_475 = V_689 ;
V_354 -> V_477 = V_690 ;
}
F_171 ( V_19 ) ;
F_164 ( V_19 ) ;
F_96 ( V_19 ) ;
F_94 ( V_19 ) ;
V_19 -> V_308 = F_145 ( V_19 -> V_233 -> V_360 ) ;
V_232 = F_142 ( V_19 ) ;
if ( V_232 )
goto V_687;
return 0 ;
V_687:
for ( V_389 = 0 ; V_389 < V_410 ; V_389 ++ ) {
if ( ! V_19 -> V_412 [ V_389 ] )
continue;
F_331 ( V_19 -> V_412 [ V_389 ] -> V_451 ) ;
}
return V_232 ;
}
static int F_332 ( struct V_230 * V_231 ,
struct V_691 * V_692 ,
struct V_1 * V_2 ,
int * V_693 )
{
struct V_691 * V_641 ;
struct V_18 * V_19 ;
struct V_531 * V_532 ;
struct V_269 * V_233 ;
struct V_694 * V_695 ;
const char * V_696 ;
const char * V_697 ;
char V_698 [ V_111 ] ;
T_1 V_21 ;
int V_699 ;
int V_700 ;
int V_701 = 2 ;
int V_232 , V_26 , V_363 ;
V_233 = F_333 ( sizeof( struct V_18 ) , V_410 ,
V_356 ) ;
if ( ! V_233 )
return - V_148 ;
V_641 = F_334 ( V_692 , L_37 , 0 ) ;
if ( ! V_641 ) {
F_104 ( & V_231 -> V_233 , L_38 ) ;
V_232 = - V_642 ;
goto V_702;
}
V_700 = F_335 ( V_692 ) ;
if ( V_700 < 0 ) {
F_104 ( & V_231 -> V_233 , L_39 ) ;
V_232 = V_700 ;
goto V_702;
}
if ( F_336 ( V_692 , L_40 , & V_21 ) ) {
V_232 = - V_29 ;
F_104 ( & V_231 -> V_233 , L_41 ) ;
goto V_702;
}
V_233 -> V_703 = V_632 ;
V_233 -> V_704 = 5 * V_705 ;
V_233 -> V_706 = & V_707 ;
V_233 -> V_708 = & V_709 ;
V_19 = F_86 ( V_233 ) ;
V_19 -> V_513 = F_337 ( V_692 , 0 ) ;
if ( V_19 -> V_513 <= 0 ) {
V_232 = - V_29 ;
goto V_702;
}
if ( F_338 ( V_692 , L_42 ) )
V_19 -> V_391 |= V_392 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_295 = * V_693 ;
V_19 -> V_641 = V_641 ;
V_19 -> V_369 = V_700 ;
V_695 = F_339 ( V_231 , V_710 ,
V_701 + V_21 ) ;
V_19 -> V_5 = F_340 ( & V_231 -> V_233 , V_695 ) ;
if ( F_341 ( V_19 -> V_5 ) ) {
V_232 = F_342 ( V_19 -> V_5 ) ;
goto V_650;
}
V_19 -> V_585 = F_343 ( struct V_587 ) ;
if ( ! V_19 -> V_585 ) {
V_232 = - V_148 ;
goto V_650;
}
V_696 = F_344 ( V_692 ) ;
if ( V_696 && F_311 ( V_696 ) ) {
V_697 = L_43 ;
F_87 ( V_233 -> V_270 , V_696 ) ;
} else {
F_296 ( V_19 , V_698 ) ;
if ( F_311 ( V_698 ) ) {
V_697 = L_44 ;
F_87 ( V_233 -> V_270 , V_698 ) ;
} else {
V_697 = L_45 ;
F_345 ( V_233 ) ;
}
}
V_19 -> V_498 = V_632 ;
V_19 -> V_489 = V_631 ;
V_19 -> V_233 = V_233 ;
F_346 ( V_233 , & V_231 -> V_233 ) ;
V_232 = F_327 ( V_19 ) ;
if ( V_232 < 0 ) {
F_104 ( & V_231 -> V_233 , L_46 , V_21 ) ;
goto V_711;
}
F_326 ( V_19 ) ;
V_19 -> V_451 = F_329 ( struct V_531 ) ;
if ( ! V_19 -> V_451 ) {
V_232 = - V_148 ;
goto V_712;
}
F_148 (cpu) {
V_532 = F_193 ( V_19 -> V_451 , V_363 ) ;
F_347 ( & V_532 -> V_536 , V_713 ,
V_537 ) ;
V_532 -> V_536 . V_714 = F_247 ;
V_532 -> V_534 = false ;
F_348 ( & V_532 -> V_541 , F_245 ,
( unsigned long ) V_233 ) ;
}
F_349 ( V_233 , & V_19 -> V_515 , F_281 , V_715 ) ;
V_699 = V_716 | V_717 ;
V_233 -> V_699 = V_699 | V_718 ;
V_233 -> V_719 |= V_699 | V_718 | V_720 ;
V_233 -> V_721 |= V_699 ;
V_232 = F_350 ( V_233 ) ;
if ( V_232 < 0 ) {
F_104 ( & V_231 -> V_233 , L_47 ) ;
goto V_722;
}
F_294 ( V_233 , L_48 , V_697 , V_233 -> V_270 ) ;
* V_693 += V_356 ;
V_2 -> V_723 [ V_21 ] = V_19 ;
return 0 ;
V_722:
F_331 ( V_19 -> V_451 ) ;
V_712:
for ( V_26 = 0 ; V_26 < V_410 ; V_26 ++ )
F_331 ( V_19 -> V_412 [ V_26 ] -> V_451 ) ;
V_711:
F_331 ( V_19 -> V_585 ) ;
V_650:
F_351 ( V_19 -> V_513 ) ;
V_702:
F_352 ( V_641 ) ;
F_353 ( V_233 ) ;
return V_232 ;
}
static void F_354 ( struct V_18 * V_19 )
{
int V_26 ;
F_355 ( V_19 -> V_233 ) ;
F_352 ( V_19 -> V_641 ) ;
F_331 ( V_19 -> V_451 ) ;
F_331 ( V_19 -> V_585 ) ;
for ( V_26 = 0 ; V_26 < V_410 ; V_26 ++ )
F_331 ( V_19 -> V_412 [ V_26 ] -> V_451 ) ;
F_351 ( V_19 -> V_513 ) ;
F_353 ( V_19 -> V_233 ) ;
}
static void F_356 ( const struct V_724 * V_725 ,
struct V_1 * V_2 )
{
T_1 V_726 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 6 ; V_26 ++ ) {
F_1 ( V_2 , F_357 ( V_26 ) , 0 ) ;
F_1 ( V_2 , F_358 ( V_26 ) , 0 ) ;
if ( V_26 < 4 )
F_1 ( V_2 , F_359 ( V_26 ) , 0 ) ;
}
V_726 = 0 ;
for ( V_26 = 0 ; V_26 < V_725 -> V_727 ; V_26 ++ ) {
const struct V_728 * V_729 = V_725 -> V_729 + V_26 ;
F_1 ( V_2 , F_357 ( V_26 ) ,
( V_729 -> V_5 & 0xffff0000 ) | ( V_729 -> V_730 << 8 ) |
V_725 -> V_731 ) ;
F_1 ( V_2 , F_358 ( V_26 ) ,
( V_729 -> V_9 - 1 ) & 0xffff0000 ) ;
V_726 |= ( 1 << V_26 ) ;
}
F_1 ( V_2 , V_732 , V_726 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_189 ; V_19 ++ ) {
F_1 ( V_2 , F_361 ( V_19 ) ,
V_733 ) ;
F_1 ( V_2 , F_362 ( V_19 ) ,
V_734 ) ;
}
F_1 ( V_2 , V_735 ,
V_736 ) ;
F_1 ( V_2 , V_737 , 0x1 ) ;
}
static int F_363 ( struct V_230 * V_231 , struct V_1 * V_2 )
{
const struct V_724 * V_738 ;
int V_232 , V_26 ;
T_1 V_64 ;
if ( V_356 % 4 || ( V_356 > V_739 ) ||
( V_410 > V_23 ) ) {
F_104 ( & V_231 -> V_233 , L_49 ) ;
return - V_29 ;
}
V_738 = F_364 () ;
if ( V_738 )
F_356 ( V_738 , V_2 ) ;
V_64 = F_4 ( V_2 -> V_636 + V_740 ) ;
V_64 |= V_741 ;
F_2 ( V_64 , V_2 -> V_636 + V_740 ) ;
V_2 -> V_603 = F_75 ( & V_231 -> V_233 , F_195 () ,
sizeof( struct V_411 ) ,
V_98 ) ;
if ( ! V_2 -> V_603 )
return - V_148 ;
F_148 (i) {
V_2 -> V_603 [ V_26 ] . V_21 = V_26 ;
V_2 -> V_603 [ V_26 ] . V_9 = V_742 ;
V_232 = F_217 ( V_231 , & V_2 -> V_603 [ V_26 ] ,
V_742 , V_26 , V_2 ) ;
if ( V_232 < 0 )
return V_232 ;
}
F_360 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_189 ; V_26 ++ )
F_1 ( V_2 , F_330 ( V_26 ) , V_356 ) ;
F_2 ( V_743 ,
V_2 -> V_636 + V_744 ) ;
F_1 ( V_2 , V_745 , 0x1 ) ;
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
struct V_691 * V_746 = V_231 -> V_233 . V_747 ;
struct V_691 * V_692 ;
struct V_1 * V_2 ;
struct V_694 * V_695 ;
int V_748 , V_295 ;
int V_232 ;
V_2 = F_328 ( & V_231 -> V_233 , sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_2 )
return - V_148 ;
V_695 = F_339 ( V_231 , V_710 , 0 ) ;
V_2 -> V_5 = F_340 ( & V_231 -> V_233 , V_695 ) ;
if ( F_341 ( V_2 -> V_5 ) )
return F_342 ( V_2 -> V_5 ) ;
V_695 = F_339 ( V_231 , V_710 , 1 ) ;
V_2 -> V_636 = F_340 ( & V_231 -> V_233 , V_695 ) ;
if ( F_341 ( V_2 -> V_636 ) )
return F_342 ( V_2 -> V_636 ) ;
V_2 -> V_749 = F_366 ( & V_231 -> V_233 , L_50 ) ;
if ( F_341 ( V_2 -> V_749 ) )
return F_342 ( V_2 -> V_749 ) ;
V_232 = F_367 ( V_2 -> V_749 ) ;
if ( V_232 < 0 )
return V_232 ;
V_2 -> V_750 = F_366 ( & V_231 -> V_233 , L_51 ) ;
if ( F_341 ( V_2 -> V_750 ) ) {
V_232 = F_342 ( V_2 -> V_750 ) ;
goto V_751;
}
V_232 = F_367 ( V_2 -> V_750 ) ;
if ( V_232 < 0 )
goto V_751;
V_2 -> V_398 = F_368 ( V_2 -> V_749 ) ;
V_232 = F_363 ( V_231 , V_2 ) ;
if ( V_232 < 0 ) {
F_104 ( & V_231 -> V_233 , L_52 ) ;
goto V_752;
}
V_748 = F_369 ( V_746 ) ;
if ( V_748 == 0 ) {
F_104 ( & V_231 -> V_233 , L_53 ) ;
V_232 = - V_642 ;
goto V_752;
}
V_2 -> V_723 = F_75 ( & V_231 -> V_233 , V_748 ,
sizeof( struct V_18 * ) ,
V_98 ) ;
if ( ! V_2 -> V_723 ) {
V_232 = - V_148 ;
goto V_752;
}
V_295 = 0 ;
F_370 (dn, port_node) {
V_232 = F_332 ( V_231 , V_692 , V_2 , & V_295 ) ;
if ( V_232 < 0 )
goto V_752;
}
F_371 ( V_231 , V_2 ) ;
return 0 ;
V_752:
F_372 ( V_2 -> V_750 ) ;
V_751:
F_372 ( V_2 -> V_749 ) ;
return V_232 ;
}
static int F_373 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = F_374 ( V_231 ) ;
struct V_691 * V_746 = V_231 -> V_233 . V_747 ;
struct V_691 * V_692 ;
int V_26 = 0 ;
F_370 (dn, port_node) {
if ( V_2 -> V_723 [ V_26 ] )
F_354 ( V_2 -> V_723 [ V_26 ] ) ;
V_26 ++ ;
}
for ( V_26 = 0 ; V_26 < V_319 ; V_26 ++ ) {
struct V_300 * V_301 = & V_2 -> V_320 [ V_26 ] ;
F_116 ( V_231 , V_2 , V_301 ) ;
}
F_148 (i) {
struct V_411 * V_440 = & V_2 -> V_603 [ V_26 ] ;
F_103 ( & V_231 -> V_233 ,
V_742 * V_487 ,
V_440 -> V_413 ,
V_440 -> V_488 ) ;
}
F_372 ( V_2 -> V_749 ) ;
F_372 ( V_2 -> V_750 ) ;
return 0 ;
}
