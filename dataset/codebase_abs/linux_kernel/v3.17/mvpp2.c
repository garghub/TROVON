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
struct V_10 * V_11 )
{
V_7 -> V_12 [ V_7 -> V_13 ] = V_11 ;
V_7 -> V_13 ++ ;
if ( V_7 -> V_13 == V_7 -> V_9 )
V_7 -> V_13 = 0 ;
}
static inline int F_7 ( struct V_14 * V_15 )
{
return V_16 + V_15 -> V_17 ;
}
static inline int F_8 ( int V_15 , int V_18 )
{
return ( V_16 + V_15 ) * V_19 + V_18 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 ;
if ( V_21 -> V_23 > V_24 - 1 )
return - V_25 ;
V_21 -> V_26 . V_27 [ V_28 ] &= ~ V_29 ;
F_1 ( V_2 , V_30 , V_21 -> V_23 ) ;
for ( V_22 = 0 ; V_22 < V_31 ; V_22 ++ )
F_1 ( V_2 , F_10 ( V_22 ) , V_21 -> V_26 . V_27 [ V_22 ] ) ;
F_1 ( V_2 , V_32 , V_21 -> V_23 ) ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ )
F_1 ( V_2 , F_11 ( V_22 ) , V_21 -> V_34 . V_27 [ V_22 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 ;
if ( V_21 -> V_23 > V_24 - 1 )
return - V_25 ;
F_1 ( V_2 , V_30 , V_21 -> V_23 ) ;
V_21 -> V_26 . V_27 [ V_28 ] = F_3 ( V_2 ,
F_10 ( V_28 ) ) ;
if ( V_21 -> V_26 . V_27 [ V_28 ] & V_29 )
return V_35 ;
for ( V_22 = 0 ; V_22 < V_31 ; V_22 ++ )
V_21 -> V_26 . V_27 [ V_22 ] = F_3 ( V_2 , F_10 ( V_22 ) ) ;
F_1 ( V_2 , V_32 , V_21 -> V_23 ) ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ )
V_21 -> V_34 . V_27 [ V_22 ] = F_3 ( V_2 , F_11 ( V_22 ) ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , int V_23 )
{
F_1 ( V_2 , V_30 , V_23 ) ;
F_1 ( V_2 , F_10 ( V_28 ) ,
V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_23 , int V_36 )
{
V_2 -> V_37 [ V_23 ] . V_38 = true ;
V_2 -> V_37 [ V_23 ] . V_36 = V_36 ;
}
static void F_15 ( struct V_1 * V_2 , int V_23 ,
unsigned int V_39 , unsigned int V_40 )
{
V_2 -> V_37 [ V_23 ] . V_40 = V_40 ;
V_2 -> V_37 [ V_23 ] . V_39 = V_39 ;
}
static void F_16 ( struct V_20 * V_21 , unsigned int V_36 )
{
int V_41 = F_17 ( V_42 ) ;
V_21 -> V_26 . V_43 [ V_42 ] = V_36 ;
V_21 -> V_26 . V_43 [ V_41 ] = V_44 ;
}
static void F_18 ( struct V_20 * V_21 ,
unsigned int V_15 , bool V_45 )
{
int V_41 = F_17 ( V_46 ) ;
if ( V_45 )
V_21 -> V_26 . V_43 [ V_41 ] &= ~ ( 1 << V_15 ) ;
else
V_21 -> V_26 . V_43 [ V_41 ] |= 1 << V_15 ;
}
static void F_19 ( struct V_20 * V_21 ,
unsigned int V_47 )
{
unsigned char V_48 = V_49 ;
int V_41 = F_17 ( V_46 ) ;
V_21 -> V_26 . V_43 [ V_46 ] = 0 ;
V_21 -> V_26 . V_43 [ V_41 ] &= ~ V_48 ;
V_21 -> V_26 . V_43 [ V_41 ] |= ~ V_47 & V_49 ;
}
static unsigned int F_20 ( struct V_20 * V_21 )
{
int V_41 = F_17 ( V_46 ) ;
return ~ ( V_21 -> V_26 . V_43 [ V_41 ] ) & V_49 ;
}
static void F_21 ( struct V_20 * V_21 ,
unsigned int V_50 , unsigned char V_43 ,
unsigned char V_51 )
{
V_21 -> V_26 . V_43 [ F_22 ( V_50 ) ] = V_43 ;
V_21 -> V_26 . V_43 [ F_23 ( V_50 ) ] = V_51 ;
}
static void F_24 ( struct V_20 * V_21 ,
unsigned int V_50 , unsigned char * V_43 ,
unsigned char * V_51 )
{
* V_43 = V_21 -> V_26 . V_43 [ F_22 ( V_50 ) ] ;
* V_51 = V_21 -> V_26 . V_43 [ F_23 ( V_50 ) ] ;
}
static bool F_25 ( struct V_20 * V_21 , int V_50 ,
T_2 V_4 )
{
int V_52 = F_22 ( V_50 ) ;
T_2 V_53 ;
V_53 = ( 8 << V_21 -> V_26 . V_43 [ V_52 + 1 ] ) | V_21 -> V_26 . V_43 [ V_52 ] ;
if ( V_53 != V_4 )
return false ;
return true ;
}
static void F_26 ( struct V_20 * V_21 ,
unsigned int V_54 , unsigned int V_51 )
{
int V_22 , V_55 = V_56 ;
for ( V_22 = 0 ; V_22 < V_57 ; V_22 ++ ) {
if ( ! ( V_51 & F_27 ( V_22 ) ) )
continue;
if ( V_54 & F_27 ( V_22 ) )
V_21 -> V_26 . V_43 [ V_55 ] |= 1 << V_22 ;
else
V_21 -> V_26 . V_43 [ V_55 ] &= ~ ( 1 << V_22 ) ;
}
V_21 -> V_26 . V_43 [ F_17 ( V_55 ) ] |= V_51 ;
}
static int F_28 ( struct V_20 * V_21 )
{
return V_21 -> V_26 . V_43 [ V_56 ] ;
}
static void F_29 ( struct V_20 * V_21 , int V_3 ,
unsigned short V_58 )
{
F_21 ( V_21 , V_3 + 0 , V_58 >> 8 , 0xff ) ;
F_21 ( V_21 , V_3 + 1 , V_58 & 0xff , 0xff ) ;
}
static void F_30 ( struct V_20 * V_21 , int V_59 ,
int V_60 )
{
V_21 -> V_34 . V_43 [ F_31 ( V_59 ) ] |= ( V_60 << ( V_59 % 8 ) ) ;
}
static void F_32 ( struct V_20 * V_21 , int V_59 ,
int V_60 )
{
V_21 -> V_34 . V_43 [ F_31 ( V_59 ) ] &= ~ ( V_60 << ( V_59 % 8 ) ) ;
}
static void F_33 ( struct V_20 * V_21 ,
unsigned int V_54 , unsigned int V_61 )
{
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_62 ; V_22 ++ ) {
int V_63 = V_64 ;
if ( ! ( V_61 & F_27 ( V_22 ) ) )
continue;
if ( V_54 & F_27 ( V_22 ) )
F_30 ( V_21 , V_63 + V_22 , 1 ) ;
else
F_32 ( V_21 , V_63 + V_22 , 1 ) ;
F_30 ( V_21 , V_65 + V_22 , 1 ) ;
}
}
static int F_34 ( struct V_20 * V_21 )
{
return V_21 -> V_34 . V_27 [ V_66 ] ;
}
static void F_35 ( struct V_20 * V_21 ,
unsigned int V_54 , unsigned int V_61 )
{
unsigned int V_22 ;
int V_67 = V_68 ;
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ ) {
if ( ! ( V_61 & F_27 ( V_22 ) ) )
continue;
if ( V_54 & F_27 ( V_22 ) )
F_30 ( V_21 , V_67 + V_22 , 1 ) ;
else
F_32 ( V_21 , V_67 + V_22 , 1 ) ;
F_30 ( V_21 , V_70 + V_22 , 1 ) ;
}
}
static int F_36 ( struct V_20 * V_21 )
{
T_3 V_54 ;
int V_67 = F_31 ( V_68 ) ;
int V_71 = V_67 + 1 ;
int V_72 = V_68 % 8 ;
V_54 = ( V_21 -> V_34 . V_43 [ V_67 ] >> V_72 ) |
( V_21 -> V_34 . V_43 [ V_71 ] << ( 8 - V_72 ) ) ;
return V_54 ;
}
static void F_37 ( struct V_20 * V_21 ,
unsigned int V_36 )
{
int V_73 = V_74 ;
F_32 ( V_21 , V_73 ,
V_75 ) ;
F_30 ( V_21 , V_73 , V_36 ) ;
}
static void F_38 ( struct V_20 * V_21 , int V_76 ,
unsigned int V_77 )
{
if ( V_76 < 0 ) {
F_30 ( V_21 , V_78 , 1 ) ;
V_76 = 0 - V_76 ;
} else {
F_32 ( V_21 , V_78 , 1 ) ;
}
V_21 -> V_34 . V_43 [ F_31 ( V_79 ) ] =
( unsigned char ) V_76 ;
F_32 ( V_21 , V_80 ,
V_81 ) ;
F_30 ( V_21 , V_80 , V_77 ) ;
F_32 ( V_21 , V_82 , 1 ) ;
}
static void F_39 ( struct V_20 * V_21 ,
unsigned int type , int V_3 ,
unsigned int V_77 )
{
if ( V_3 < 0 ) {
F_30 ( V_21 , V_83 , 1 ) ;
V_3 = 0 - V_3 ;
} else {
F_32 ( V_21 , V_83 , 1 ) ;
}
F_32 ( V_21 , V_84 ,
V_85 ) ;
F_30 ( V_21 , V_84 , V_3 ) ;
V_21 -> V_34 . V_43 [ F_31 ( V_84 +
V_86 ) ] &=
~ ( V_85 >> ( 8 - ( V_84 % 8 ) ) ) ;
V_21 -> V_34 . V_43 [ F_31 ( V_84 +
V_86 ) ] |=
( V_3 >> ( 8 - ( V_84 % 8 ) ) ) ;
F_32 ( V_21 , V_87 ,
V_88 ) ;
F_30 ( V_21 , V_87 , type ) ;
F_32 ( V_21 , V_89 ,
V_90 ) ;
F_30 ( V_21 , V_89 , V_77 ) ;
V_21 -> V_34 . V_43 [ F_31 ( V_89 +
V_91 ) ] &=
~ ( V_90 >>
( 8 - ( V_89 % 8 ) ) ) ;
V_21 -> V_34 . V_43 [ F_31 ( V_89 +
V_91 ) ] |=
( V_77 >> ( 8 - ( V_89 % 8 ) ) ) ;
F_32 ( V_21 , V_82 , 1 ) ;
}
static struct V_20 * F_40 ( struct V_1 * V_2 , int V_92 )
{
struct V_20 * V_21 ;
int V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return NULL ;
F_16 ( V_21 , V_95 ) ;
for ( V_93 = V_24 - 1 ; V_93 >= 0 ; V_93 -- ) {
T_3 V_54 ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
V_2 -> V_37 [ V_93 ] . V_36 != V_95 )
continue;
V_21 -> V_23 = V_93 ;
F_12 ( V_2 , V_21 ) ;
V_54 = F_36 ( V_21 ) ;
if ( ( V_54 & V_96 ) == V_92 )
return V_21 ;
}
F_42 ( V_21 ) ;
return NULL ;
}
static int F_43 ( struct V_1 * V_2 , unsigned char V_97 ,
unsigned char V_98 )
{
int V_93 ;
if ( V_97 > V_98 )
F_44 ( V_97 , V_98 ) ;
if ( V_98 >= V_24 )
V_98 = V_24 - 1 ;
for ( V_93 = V_97 ; V_93 <= V_98 ; V_93 ++ ) {
if ( ! V_2 -> V_37 [ V_93 ] . V_38 )
return V_93 ;
}
return - V_25 ;
}
static void F_45 ( struct V_1 * V_2 , int V_15 , bool V_45 )
{
struct V_20 V_21 ;
if ( V_2 -> V_37 [ V_99 ] . V_38 ) {
V_21 . V_23 = V_99 ;
F_12 ( V_2 , & V_21 ) ;
} else {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_100 ) ;
V_21 . V_23 = V_99 ;
F_33 ( & V_21 , V_101 ,
V_101 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_37 ( & V_21 , V_95 ) ;
F_14 ( V_2 , V_21 . V_23 , V_100 ) ;
F_19 ( & V_21 , 0 ) ;
}
F_18 ( & V_21 , V_15 , V_45 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_46 ( struct V_1 * V_2 , int V_15 , bool V_45 )
{
struct V_20 V_21 ;
if ( V_2 -> V_37 [ V_103 ] . V_38 ) {
V_21 . V_23 = V_103 ;
F_12 ( V_2 , & V_21 ) ;
} else {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_100 ) ;
V_21 . V_23 = V_103 ;
F_37 ( & V_21 , V_104 ) ;
F_33 ( & V_21 , V_105 ,
V_106 ) ;
F_38 ( & V_21 , 2 * V_107 ,
V_108 ) ;
F_19 ( & V_21 , 0 ) ;
F_14 ( V_2 , V_21 . V_23 , V_100 ) ;
}
F_18 ( & V_21 , V_15 , V_45 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_15 , int V_23 ,
bool V_45 )
{
struct V_20 V_21 ;
unsigned char V_109 ;
V_109 = ( V_23 == V_110 ) ? 0x01 : 0x33 ;
if ( V_2 -> V_37 [ V_23 ] . V_38 ) {
V_21 . V_23 = V_23 ;
F_12 ( V_2 , & V_21 ) ;
} else {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_100 ) ;
V_21 . V_23 = V_23 ;
F_37 ( & V_21 , V_104 ) ;
F_33 ( & V_21 , V_111 ,
V_106 ) ;
F_21 ( & V_21 , 0 , V_109 , 0xff ) ;
F_38 ( & V_21 , 2 * V_107 ,
V_108 ) ;
F_19 ( & V_21 , 0 ) ;
F_14 ( V_2 , V_21 . V_23 , V_100 ) ;
}
F_18 ( & V_21 , V_15 , V_45 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_15 , bool V_45 ,
bool V_112 , bool V_113 )
{
struct V_20 V_21 ;
int V_93 , V_76 ;
if ( V_113 ) {
V_93 = V_112 ? V_114 : V_115 ;
V_76 = 8 ;
} else {
V_93 = V_112 ? V_116 : V_117 ;
V_76 = 4 ;
}
if ( V_2 -> V_37 [ V_93 ] . V_38 ) {
V_21 . V_23 = V_93 ;
F_12 ( V_2 , & V_21 ) ;
} else {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_104 ) ;
V_21 . V_23 = V_93 ;
F_38 ( & V_21 , V_76 ,
V_108 ) ;
F_14 ( V_2 , V_21 . V_23 , V_104 ) ;
if ( V_112 ) {
F_21 ( & V_21 , 0 ,
V_118 ,
V_118 ) ;
F_35 ( & V_21 , 0 ,
V_119 ) ;
F_37 ( & V_21 , V_120 ) ;
} else {
F_33 ( & V_21 , V_121 ,
V_122 ) ;
F_37 ( & V_21 , V_123 ) ;
}
F_19 ( & V_21 , 0 ) ;
}
F_18 ( & V_21 , V_15 , V_45 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_15 ,
bool V_45 , bool V_112 , bool V_113 )
{
struct V_20 V_21 ;
int V_93 , V_76 , V_48 ;
if ( V_113 ) {
V_93 = V_112 ? V_124 :
V_125 ;
V_48 = 0 ;
V_76 = 8 ;
} else {
V_93 = V_112 ? V_126 :
V_127 ;
V_48 = V_49 ;
V_76 = 4 ;
}
if ( V_2 -> V_37 [ V_93 ] . V_38 ) {
V_21 . V_23 = V_93 ;
F_12 ( V_2 , & V_21 ) ;
} else {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_104 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_128 ) ;
F_29 ( & V_21 , 2 , 0 ) ;
F_33 ( & V_21 , V_129 ,
V_129 ) ;
F_38 ( & V_21 , 2 + V_130 + V_76 ,
V_108 ) ;
F_14 ( V_2 , V_21 . V_23 , V_104 ) ;
if ( V_112 ) {
F_21 ( & V_21 ,
V_130 + 2 + 3 ,
V_118 ,
V_118 ) ;
F_35 ( & V_21 , 0 ,
V_119 ) ;
F_37 ( & V_21 , V_120 ) ;
} else {
F_33 ( & V_21 , V_121 ,
V_122 ) ;
F_37 ( & V_21 , V_123 ) ;
}
F_19 ( & V_21 , V_48 ) ;
}
F_18 ( & V_21 , V_15 , V_45 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static struct V_20 * F_50 ( struct V_1 * V_2 ,
unsigned short V_131 , int V_132 )
{
struct V_20 * V_21 ;
int V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return NULL ;
F_16 ( V_21 , V_120 ) ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ ) {
unsigned int V_135 , V_136 ;
bool V_137 ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
V_2 -> V_37 [ V_93 ] . V_36 != V_120 )
continue;
V_21 -> V_23 = V_93 ;
F_12 ( V_2 , V_21 ) ;
V_137 = F_25 ( V_21 , 0 , F_51 ( V_131 ) ) ;
if ( ! V_137 )
continue;
V_135 = F_34 ( V_21 ) ;
V_135 &= V_122 ;
V_136 = F_28 ( V_21 ) ;
V_136 &= ~ V_138 ;
if ( V_132 != V_136 )
continue;
if ( V_135 == V_139 ||
V_135 == V_140 )
return V_21 ;
}
F_42 ( V_21 ) ;
return NULL ;
}
static int F_52 ( struct V_1 * V_2 , unsigned short V_131 , int V_132 ,
unsigned int V_141 )
{
struct V_20 * V_21 ;
int V_142 , V_93 ;
V_21 = F_50 ( V_2 , V_131 , V_132 ) ;
if ( ! V_21 ) {
V_93 = F_43 ( V_2 , V_134 ,
V_133 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - V_143 ;
for ( V_142 = V_134 ;
V_142 >= V_133 ; V_142 -- ) {
unsigned int V_135 ;
if ( ! V_2 -> V_37 [ V_142 ] . V_38 ||
V_2 -> V_37 [ V_142 ] . V_36 != V_120 )
continue;
V_21 -> V_23 = V_142 ;
F_12 ( V_2 , V_21 ) ;
V_135 = F_34 ( V_21 ) ;
if ( ( V_135 & V_122 ) ==
V_144 )
break;
}
if ( V_93 <= V_142 )
return - V_25 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( V_21 , V_120 ) ;
V_21 -> V_23 = V_93 ;
F_29 ( V_21 , 0 , V_131 ) ;
F_37 ( V_21 , V_123 ) ;
F_38 ( V_21 , V_145 ,
V_108 ) ;
F_35 ( V_21 , 0 , V_119 ) ;
if ( V_132 == V_146 ) {
F_33 ( V_21 , V_139 ,
V_122 ) ;
} else {
V_132 |= V_138 ;
F_33 ( V_21 , V_140 ,
V_122 ) ;
}
F_26 ( V_21 , V_132 , V_119 ) ;
F_14 ( V_2 , V_21 -> V_23 , V_120 ) ;
}
F_19 ( V_21 , V_141 ) ;
F_9 ( V_2 , V_21 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 1 ; V_22 < V_147 ; V_22 ++ ) {
if ( ! V_2 -> V_148 [ V_22 ] )
return V_22 ;
}
return - V_25 ;
}
static struct V_20 * F_54 ( struct V_1 * V_2 ,
unsigned short V_149 ,
unsigned short V_150 )
{
struct V_20 * V_21 ;
int V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return NULL ;
F_16 ( V_21 , V_120 ) ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ ) {
unsigned int V_40 ;
bool V_137 ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
V_2 -> V_37 [ V_93 ] . V_36 != V_120 )
continue;
V_21 -> V_23 = V_93 ;
F_12 ( V_2 , V_21 ) ;
V_137 = F_25 ( V_21 , 0 , F_51 ( V_149 ) )
&& F_25 ( V_21 , 4 , F_51 ( V_150 ) ) ;
if ( ! V_137 )
continue;
V_40 = F_34 ( V_21 ) & V_122 ;
if ( V_40 == V_144 )
return V_21 ;
}
F_42 ( V_21 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , unsigned short V_149 ,
unsigned short V_150 ,
unsigned int V_141 )
{
struct V_20 * V_21 ;
int V_142 , V_93 , V_132 ;
V_21 = F_54 ( V_2 , V_149 , V_150 ) ;
if ( ! V_21 ) {
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - V_143 ;
V_132 = F_53 ( V_2 ) ;
if ( V_132 < 0 )
return V_132 ;
for ( V_142 = V_133 ;
V_142 <= V_134 ; V_142 ++ ) {
unsigned int V_135 ;
if ( ! V_2 -> V_37 [ V_142 ] . V_38 ||
V_2 -> V_37 [ V_142 ] . V_36 != V_120 )
continue;
V_21 -> V_23 = V_142 ;
F_12 ( V_2 , V_21 ) ;
V_135 = F_34 ( V_21 ) ;
V_135 &= V_122 ;
if ( V_135 == V_139 ||
V_135 == V_140 )
break;
}
if ( V_93 >= V_142 )
return - V_151 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( V_21 , V_120 ) ;
V_21 -> V_23 = V_93 ;
V_2 -> V_148 [ V_132 ] = true ;
F_29 ( V_21 , 0 , V_149 ) ;
F_29 ( V_21 , 4 , V_150 ) ;
F_37 ( V_21 , V_120 ) ;
F_38 ( V_21 , 2 * V_145 ,
V_108 ) ;
F_33 ( V_21 , V_144 ,
V_122 ) ;
F_35 ( V_21 , V_132 | V_138 ,
V_119 ) ;
F_14 ( V_2 , V_21 -> V_23 , V_120 ) ;
}
F_19 ( V_21 , V_141 ) ;
F_9 ( V_2 , V_21 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned short V_152 ,
unsigned int V_39 , unsigned int V_40 )
{
struct V_20 V_21 ;
int V_93 ;
if ( ( V_152 != V_153 ) && ( V_152 != V_154 ) &&
( V_152 != V_155 ) )
return - V_25 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_156 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_156 ) ;
F_38 ( & V_21 , 12 , V_108 ) ;
F_39 ( & V_21 , V_157 ,
sizeof( struct V_158 ) - 4 ,
V_159 ) ;
F_35 ( & V_21 , V_160 ,
V_160 ) ;
F_33 ( & V_21 , V_39 | V_161 ,
V_40 | V_161 ) ;
F_21 ( & V_21 , 5 , V_152 , V_162 ) ;
F_26 ( & V_21 , 0 , V_160 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 . V_23 = V_93 ;
V_21 . V_34 . V_27 [ V_66 ] = 0x0 ;
V_21 . V_34 . V_27 [ V_163 ] = 0x0 ;
F_33 ( & V_21 , V_39 , V_40 ) ;
F_21 ( & V_21 , 2 , 0x00 , V_164 ) ;
F_21 ( & V_21 , 3 , 0x00 , V_162 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned short V_165 )
{
struct V_20 V_21 ;
int V_61 , V_93 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_156 ) ;
V_21 . V_23 = V_93 ;
switch ( V_165 ) {
case V_166 :
F_21 ( & V_21 , 0 , V_167 ,
V_168 ) ;
F_33 ( & V_21 , V_169 ,
V_170 ) ;
break;
case V_171 :
V_61 = V_172 ;
F_21 ( & V_21 , 0 , V_61 , V_61 ) ;
F_21 ( & V_21 , 1 , V_61 , V_61 ) ;
F_21 ( & V_21 , 2 , V_61 , V_61 ) ;
F_21 ( & V_21 , 3 , V_61 , V_61 ) ;
F_33 ( & V_21 , V_173 ,
V_170 ) ;
break;
default:
return - V_25 ;
}
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_26 ( & V_21 , V_160 ,
V_160 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned short V_152 ,
unsigned int V_39 , unsigned int V_40 )
{
struct V_20 V_21 ;
int V_93 ;
if ( ( V_152 != V_153 ) && ( V_152 != V_154 ) &&
( V_152 != V_174 ) && ( V_152 != V_175 ) )
return - V_25 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_176 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_39 , V_40 ) ;
F_39 ( & V_21 , V_157 ,
sizeof( struct V_177 ) - 6 ,
V_159 ) ;
F_21 ( & V_21 , 0 , V_152 , V_162 ) ;
F_26 ( & V_21 , V_178 ,
V_178 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_176 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned short V_165 )
{
struct V_20 V_21 ;
int V_93 ;
if ( V_165 != V_166 )
return - V_25 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_176 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_176 ) ;
F_33 ( & V_21 , V_169 ,
V_170 ) ;
F_35 ( & V_21 , V_178 ,
V_178 ) ;
F_38 ( & V_21 , - 18 , V_108 ) ;
F_21 ( & V_21 , 0 , V_179 ,
V_180 ) ;
F_26 ( & V_21 , 0 , V_178 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_176 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_15 , int V_181 ,
int V_182 , int V_3 )
{
T_1 V_60 ;
V_60 = F_3 ( V_2 , V_183 ) ;
V_60 &= ~ F_61 ( V_15 ) ;
V_60 |= F_62 ( V_15 , V_181 ) ;
F_1 ( V_2 , V_183 , V_60 ) ;
V_60 = F_3 ( V_2 , F_63 ( V_15 ) ) ;
V_60 &= ~ F_64 ( V_15 ) ;
V_60 |= F_65 ( V_15 , V_182 ) ;
F_1 ( V_2 , F_63 ( V_15 ) , V_60 ) ;
V_60 = F_3 ( V_2 , F_66 ( V_15 ) ) ;
V_60 &= ~ F_67 ( V_15 ) ;
V_60 |= F_68 ( V_15 , V_3 ) ;
F_1 ( V_2 , F_66 ( V_15 ) , V_60 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_184 ; V_15 ++ ) {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_95 ) ;
V_21 . V_23 = V_185 - V_15 ;
F_19 ( & V_21 , 0 ) ;
F_35 ( & V_21 , V_15 , V_96 ) ;
F_30 ( & V_21 , V_186 , 1 ) ;
F_14 ( V_2 , V_21 . V_23 , V_95 ) ;
F_9 ( V_2 , & V_21 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 . V_23 = V_187 ;
F_16 ( & V_21 , V_188 ) ;
F_38 ( & V_21 , V_189 ,
V_108 ) ;
F_37 ( & V_21 , V_100 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_188 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 . V_23 = V_190 ;
F_16 ( & V_21 , V_100 ) ;
F_33 ( & V_21 , V_101 ,
V_101 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_37 ( & V_21 , V_95 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_100 ) ;
F_9 ( V_2 , & V_21 ) ;
F_45 ( V_2 , 0 , false ) ;
F_46 ( V_2 , 0 , false ) ;
F_47 ( V_2 , V_110 , 0 , false ) ;
F_47 ( V_2 , V_191 , 0 , false ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
F_48 ( V_2 , 0 , false , V_192 ,
V_193 ) ;
F_48 ( V_2 , 0 , false , V_194 , V_193 ) ;
F_48 ( V_2 , 0 , false , V_192 ,
V_195 ) ;
F_48 ( V_2 , 0 , false , V_194 , V_195 ) ;
F_49 ( V_2 , 0 , false ,
V_192 , V_193 ) ;
F_49 ( V_2 , 0 , false ,
V_194 , V_193 ) ;
F_49 ( V_2 , 0 , true ,
V_192 , V_195 ) ;
F_49 ( V_2 , 0 , true ,
V_194 , V_195 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_104 ) ;
V_21 . V_23 = V_196 ;
F_37 ( & V_21 , V_120 ) ;
F_38 ( & V_21 , 0 , V_108 ) ;
F_14 ( V_2 , V_21 . V_23 , V_100 ) ;
F_35 ( & V_21 , 0 , V_119 ) ;
F_19 ( & V_21 , V_49 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_93 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_197 ) ;
F_38 ( & V_21 , V_198 ,
V_108 ) ;
F_37 ( & V_21 , V_199 ) ;
F_33 ( & V_21 , V_200 ,
V_200 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = false ;
F_15 ( V_2 , V_21 . V_23 , V_200 ,
V_200 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_204 ) ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_205 ,
V_206 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = true ;
F_15 ( V_2 , V_21 . V_23 , V_205 ,
V_206 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_208 ) ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_209 |
V_210 ,
V_211 |
V_212 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = true ;
F_15 ( V_2 , V_21 . V_23 , V_209 |
V_210 ,
V_211 |
V_212 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_213 ) ;
F_21 ( & V_21 , V_130 ,
V_214 | V_215 ,
V_216 |
V_217 ) ;
F_37 ( & V_21 , V_156 ) ;
F_33 ( & V_21 , V_218 ,
V_206 ) ;
F_38 ( & V_21 , V_130 + 4 ,
V_108 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = false ;
F_15 ( V_2 , V_21 . V_23 , V_218 ,
V_206 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 . V_23 = V_93 ;
V_21 . V_26 . V_43 [ F_22 ( V_130 ) ] = 0x0 ;
V_21 . V_26 . V_43 [ F_23 ( V_130 ) ] = 0x0 ;
F_21 ( & V_21 , V_130 ,
V_214 ,
V_216 ) ;
V_21 . V_34 . V_27 [ V_66 ] = 0x0 ;
V_21 . V_34 . V_27 [ V_163 ] = 0x0 ;
F_33 ( & V_21 , V_219 ,
V_206 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = false ;
F_15 ( V_2 , V_21 . V_23 , V_219 ,
V_206 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_220 ) ;
F_38 ( & V_21 , V_130 + 8 +
V_221 ,
V_108 ) ;
F_37 ( & V_21 , V_176 ) ;
F_33 ( & V_21 , V_222 ,
V_206 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = false ;
F_15 ( V_2 , V_21 . V_23 , V_222 ,
V_206 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_223 ;
F_19 ( & V_21 , V_49 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_37 ( & V_21 , V_95 ) ;
F_33 ( & V_21 , V_224 ,
V_206 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_201 = V_202 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_203 = true ;
F_15 ( V_2 , V_21 . V_23 , V_224 ,
V_206 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_74 ( struct V_225 * V_226 , struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_227 ;
V_2 -> V_148 = F_75 ( & V_226 -> V_228 , sizeof( bool ) ,
V_147 ,
V_94 ) ;
if ( ! V_2 -> V_148 )
return - V_143 ;
V_227 = F_55 ( V_2 , V_229 , V_230 ,
V_49 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_55 ( V_2 , V_229 , V_229 ,
V_49 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_52 ( V_2 , V_230 , V_146 ,
V_49 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_52 ( V_2 , V_229 , V_146 ,
V_49 ) ;
if ( V_227 )
return V_227 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_120 ) ;
V_21 . V_23 = V_231 ;
F_37 ( & V_21 , V_123 ) ;
F_35 ( & V_21 , 0 , V_119 ) ;
F_33 ( & V_21 , V_144 ,
V_122 ) ;
F_26 ( & V_21 , V_138 ,
V_138 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_120 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_120 ) ;
V_21 . V_23 = V_232 ;
F_37 ( & V_21 , V_123 ) ;
F_33 ( & V_21 , V_121 ,
V_122 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_120 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_93 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_199 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_233 ) ;
F_37 ( & V_21 , V_156 ) ;
F_33 ( & V_21 , V_219 ,
V_206 ) ;
F_38 ( & V_21 , V_130 + 4 ,
V_108 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_199 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 . V_23 = V_93 ;
F_21 ( & V_21 , V_130 ,
V_214 | V_215 ,
V_216 |
V_217 ) ;
V_21 . V_34 . V_27 [ V_66 ] = 0x0 ;
V_21 . V_34 . V_27 [ V_163 ] = 0x0 ;
F_33 ( & V_21 , V_218 ,
V_206 ) ;
F_14 ( V_2 , V_21 . V_23 , V_199 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_199 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_234 ) ;
F_37 ( & V_21 , V_176 ) ;
F_33 ( & V_21 , V_222 ,
V_206 ) ;
F_38 ( & V_21 , V_130 + 4 ,
V_108 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_199 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_199 ) ;
V_21 . V_23 = V_93 ;
F_33 ( & V_21 , V_224 ,
V_206 ) ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_39 ( & V_21 , V_207 ,
V_130 ,
V_159 ) ;
F_14 ( V_2 , V_21 . V_23 , V_199 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_227 ;
V_227 = F_56 ( V_2 , V_153 , V_235 ,
V_236 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_56 ( V_2 , V_154 , V_237 ,
V_236 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_56 ( V_2 , V_155 ,
V_209 |
V_210 ,
V_211 |
V_212 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_57 ( V_2 , V_171 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_57 ( V_2 , V_166 ) ;
if ( V_227 )
return V_227 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_156 ) ;
V_21 . V_23 = V_238 ;
F_37 ( & V_21 , V_156 ) ;
F_38 ( & V_21 , 12 , V_108 ) ;
F_39 ( & V_21 , V_157 ,
sizeof( struct V_158 ) - 4 ,
V_159 ) ;
F_35 ( & V_21 , V_160 ,
V_160 ) ;
F_33 ( & V_21 , V_239 ,
V_236 ) ;
F_26 ( & V_21 , 0 , V_160 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_156 ) ;
V_21 . V_23 = V_240 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_241 ,
V_170 ) ;
F_26 ( & V_21 , V_160 ,
V_160 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_93 , V_227 ;
V_227 = F_58 ( V_2 , V_153 ,
V_235 ,
V_236 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_58 ( V_2 , V_154 ,
V_237 ,
V_236 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_58 ( V_2 , V_174 ,
V_209 |
V_210 ,
V_211 |
V_212 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_58 ( V_2 , V_175 ,
V_242 ,
V_243 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_59 ( V_2 , V_166 ) ;
if ( V_227 )
return V_227 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_176 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_224 |
V_101 ,
V_206 |
V_101 ) ;
F_21 ( & V_21 , 1 , 0x00 , V_244 ) ;
F_26 ( & V_21 , V_178 ,
V_178 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_176 ) ;
V_21 . V_23 = V_245 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_239 ,
V_236 ) ;
F_39 ( & V_21 , V_157 ,
sizeof( struct V_177 ) - 4 ,
V_159 ) ;
F_26 ( & V_21 , V_178 ,
V_178 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_176 ) ;
V_21 . V_23 = V_246 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_239 ,
V_236 ) ;
F_26 ( & V_21 , V_247 ,
V_247 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_156 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_176 ) ;
V_21 . V_23 = V_248 ;
F_37 ( & V_21 , V_176 ) ;
F_33 ( & V_21 , V_241 ,
V_170 ) ;
F_35 ( & V_21 , V_178 ,
V_178 ) ;
F_38 ( & V_21 , - 18 , V_108 ) ;
F_26 ( & V_21 , 0 , V_178 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_176 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_79 ( struct V_225 * V_226 ,
struct V_1 * V_2 )
{
int V_227 , V_23 , V_22 ;
F_1 ( V_2 , V_249 , V_250 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
F_1 ( V_2 , V_30 , V_23 ) ;
for ( V_22 = 0 ; V_22 < V_31 ; V_22 ++ )
F_1 ( V_2 , F_10 ( V_22 ) , 0 ) ;
F_1 ( V_2 , V_32 , V_23 ) ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ )
F_1 ( V_2 , F_11 ( V_22 ) , 0 ) ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
F_13 ( V_2 , V_23 ) ;
V_2 -> V_37 = F_75 ( & V_226 -> V_228 , V_24 ,
sizeof( struct V_251 ) ,
V_94 ) ;
if ( ! V_2 -> V_37 )
return - V_143 ;
for ( V_23 = 0 ; V_23 < V_184 ; V_23 ++ )
F_60 ( V_2 , V_23 , V_188 ,
V_252 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
V_227 = F_73 ( V_2 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_74 ( V_226 , V_2 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_76 ( V_2 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_78 ( V_2 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_77 ( V_2 ) ;
if ( V_227 )
return V_227 ;
return 0 ;
}
static bool F_80 ( struct V_20 * V_21 ,
const T_3 * V_253 , unsigned char * V_61 )
{
unsigned char V_254 , V_255 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_107 ; V_23 ++ ) {
F_24 ( V_21 , V_23 , & V_254 , & V_255 ) ;
if ( V_255 != V_61 [ V_23 ] )
return false ;
if ( ( V_255 & V_254 ) != ( V_253 [ V_23 ] & V_61 [ V_23 ] ) )
return false ;
}
return true ;
}
static struct V_20 *
F_81 ( struct V_1 * V_2 , int V_256 , const T_3 * V_253 ,
unsigned char * V_61 , int V_257 )
{
struct V_20 * V_21 ;
int V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return NULL ;
F_16 ( V_21 , V_100 ) ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ ) {
unsigned int V_258 ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
( V_2 -> V_37 [ V_93 ] . V_36 != V_100 ) ||
( V_2 -> V_37 [ V_93 ] . V_201 != V_257 ) )
continue;
V_21 -> V_23 = V_93 ;
F_12 ( V_2 , V_21 ) ;
V_258 = F_20 ( V_21 ) ;
if ( F_80 ( V_21 , V_253 , V_61 ) &&
V_258 == V_256 )
return V_21 ;
}
F_42 ( V_21 ) ;
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_15 ,
const T_3 * V_253 , bool V_45 )
{
struct V_20 * V_21 ;
unsigned int V_256 , V_259 , V_39 ;
unsigned char V_61 [ V_107 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_93 ;
V_21 = F_81 ( V_2 , ( 1 << V_15 ) , V_253 , V_61 ,
V_260 ) ;
if ( ! V_21 ) {
if ( ! V_45 )
return 0 ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ )
if ( V_2 -> V_37 [ V_93 ] . V_38 &&
( V_2 -> V_37 [ V_93 ] . V_36 == V_100 ) &&
( V_2 -> V_37 [ V_93 ] . V_201 ==
V_261 ) )
break;
V_93 = F_43 ( V_2 , V_133 ,
V_93 - 1 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - 1 ;
F_16 ( V_21 , V_100 ) ;
V_21 -> V_23 = V_93 ;
F_19 ( V_21 , 0 ) ;
}
F_18 ( V_21 , V_15 , V_45 ) ;
V_256 = F_20 ( V_21 ) ;
if ( V_256 == 0 ) {
if ( V_45 ) {
F_42 ( V_21 ) ;
return - 1 ;
}
F_13 ( V_2 , V_21 -> V_23 ) ;
V_2 -> V_37 [ V_21 -> V_23 ] . V_38 = false ;
F_42 ( V_21 ) ;
return 0 ;
}
F_37 ( V_21 , V_104 ) ;
V_259 = V_107 ;
while ( V_259 -- )
F_21 ( V_21 , V_259 , V_253 [ V_259 ] , 0xff ) ;
if ( F_83 ( V_253 ) )
V_39 = V_262 ;
else if ( F_84 ( V_253 ) )
V_39 = V_111 ;
else
V_39 = V_105 | V_263 ;
F_33 ( V_21 , V_39 , V_106 |
V_263 ) ;
F_15 ( V_2 , V_21 -> V_23 , V_39 , V_106 |
V_263 ) ;
F_38 ( V_21 , 2 * V_107 ,
V_108 ) ;
V_2 -> V_37 [ V_21 -> V_23 ] . V_201 = V_260 ;
F_14 ( V_2 , V_21 -> V_23 , V_100 ) ;
F_9 ( V_2 , V_21 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static int F_85 ( struct V_264 * V_228 , const T_3 * V_253 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
int V_227 ;
V_227 = F_82 ( V_15 -> V_2 , V_15 -> V_17 , V_228 -> V_265 ,
false ) ;
if ( V_227 )
return V_227 ;
V_227 = F_82 ( V_15 -> V_2 , V_15 -> V_17 , V_253 , true ) ;
if ( V_227 )
return V_227 ;
F_87 ( V_228 -> V_265 , V_253 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , int V_15 )
{
struct V_20 V_21 ;
int V_23 , V_93 ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ ) {
unsigned char V_253 [ V_107 ] , V_266 [ V_107 ] ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
( V_2 -> V_37 [ V_93 ] . V_36 != V_100 ) ||
( V_2 -> V_37 [ V_93 ] . V_201 != V_260 ) )
continue;
V_21 . V_23 = V_93 ;
F_12 ( V_2 , & V_21 ) ;
for ( V_23 = 0 ; V_23 < V_107 ; V_23 ++ )
F_24 ( & V_21 , V_23 , & V_253 [ V_23 ] ,
& V_266 [ V_23 ] ) ;
if ( F_84 ( V_253 ) && ! F_83 ( V_253 ) )
F_82 ( V_2 , V_15 , V_253 , false ) ;
}
}
static int F_89 ( struct V_1 * V_2 , int V_15 , int type )
{
switch ( type ) {
case V_267 :
F_48 ( V_2 , V_15 , true ,
V_194 , V_193 ) ;
F_48 ( V_2 , V_15 , true ,
V_192 , V_193 ) ;
F_48 ( V_2 , V_15 , false ,
V_194 , V_195 ) ;
F_48 ( V_2 , V_15 , false ,
V_192 , V_195 ) ;
break;
case V_268 :
F_48 ( V_2 , V_15 , true ,
V_194 , V_195 ) ;
F_48 ( V_2 , V_15 , true ,
V_192 , V_195 ) ;
F_48 ( V_2 , V_15 , false ,
V_194 , V_193 ) ;
F_48 ( V_2 , V_15 , false ,
V_192 , V_193 ) ;
break;
case V_269 :
case V_270 :
F_48 ( V_2 , V_15 , false ,
V_194 , V_195 ) ;
F_48 ( V_2 , V_15 , false ,
V_192 , V_195 ) ;
F_48 ( V_2 , V_15 , false ,
V_194 , V_193 ) ;
F_48 ( V_2 , V_15 , false ,
V_192 , V_193 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_267 ) )
return - V_25 ;
}
return 0 ;
}
static int F_90 ( struct V_14 * V_15 )
{
struct V_20 * V_21 ;
int V_93 ;
V_21 = F_40 ( V_15 -> V_2 , V_15 -> V_17 ) ;
if ( ! V_21 ) {
V_93 = F_43 ( V_15 -> V_2 ,
V_134 ,
V_133 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - V_143 ;
F_16 ( V_21 , V_95 ) ;
V_21 -> V_23 = V_93 ;
F_35 ( V_21 , V_15 -> V_17 , V_96 ) ;
F_30 ( V_21 , V_186 , 1 ) ;
F_14 ( V_15 -> V_2 , V_21 -> V_23 , V_95 ) ;
}
F_19 ( V_21 , ( 1 << V_15 -> V_17 ) ) ;
F_9 ( V_15 -> V_2 , V_21 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_271 * V_272 )
{
F_1 ( V_2 , V_273 , V_272 -> V_23 ) ;
F_1 ( V_2 , V_274 , V_272 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_275 , V_272 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_276 , V_272 -> V_4 [ 2 ] ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
T_1 V_60 ;
V_60 = ( V_278 -> V_279 << V_280 ) | V_278 -> V_281 ;
F_1 ( V_2 , V_282 , V_60 ) ;
F_1 ( V_2 , V_283 , V_278 -> V_4 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_277 V_278 ;
struct V_271 V_272 ;
int V_23 ;
F_1 ( V_2 , V_284 , V_285 ) ;
memset ( & V_272 . V_4 , 0 , V_286 ) ;
for ( V_23 = 0 ; V_23 < V_287 ; V_23 ++ ) {
V_272 . V_23 = V_23 ;
F_91 ( V_2 , & V_272 ) ;
}
V_278 . V_4 = 0 ;
for ( V_23 = 0 ; V_23 < V_288 ; V_23 ++ ) {
V_278 . V_281 = V_23 ;
V_278 . V_279 = 0 ;
F_92 ( V_2 , & V_278 ) ;
V_278 . V_279 = 1 ;
F_92 ( V_2 , & V_278 ) ;
}
}
static void F_94 ( struct V_14 * V_15 )
{
struct V_277 V_278 ;
T_1 V_60 ;
V_60 = F_3 ( V_15 -> V_2 , V_289 ) ;
V_60 &= ~ F_95 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_289 , V_60 ) ;
V_278 . V_281 = V_15 -> V_17 ;
V_278 . V_279 = 0 ;
V_278 . V_4 = 0 ;
V_278 . V_4 &= ~ V_290 ;
V_278 . V_4 |= V_15 -> V_291 ;
V_278 . V_4 &= ~ V_292 ;
F_92 ( V_15 -> V_2 , & V_278 ) ;
}
static void F_96 ( struct V_14 * V_15 )
{
T_1 V_60 ;
F_1 ( V_15 -> V_2 , F_97 ( V_15 -> V_17 ) ,
V_15 -> V_291 & V_293 ) ;
F_1 ( V_15 -> V_2 , F_98 ( V_15 -> V_17 ) ,
( V_15 -> V_291 >> V_294 ) ) ;
V_60 = F_3 ( V_15 -> V_2 , V_295 ) ;
V_60 |= F_99 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_295 , V_60 ) ;
}
static int F_100 ( struct V_225 * V_226 ,
struct V_1 * V_2 ,
struct V_296 * V_297 , int V_9 )
{
int V_298 ;
T_1 V_60 ;
V_298 = sizeof( T_1 ) * V_9 ;
V_297 -> V_299 = F_101 ( & V_226 -> V_228 , V_298 ,
& V_297 -> V_300 ,
V_94 ) ;
if ( ! V_297 -> V_299 )
return - V_143 ;
if ( ! F_102 ( ( T_1 ) V_297 -> V_299 , V_301 ) ) {
F_103 ( & V_226 -> V_228 , V_298 , V_297 -> V_299 ,
V_297 -> V_300 ) ;
F_104 ( & V_226 -> V_228 , L_1 ,
V_297 -> V_17 , V_301 ) ;
return - V_143 ;
}
F_1 ( V_2 , F_105 ( V_297 -> V_17 ) ,
V_297 -> V_300 ) ;
F_1 ( V_2 , F_106 ( V_297 -> V_17 ) , V_9 ) ;
V_60 = F_3 ( V_2 , F_107 ( V_297 -> V_17 ) ) ;
V_60 |= V_302 ;
F_1 ( V_2 , F_107 ( V_297 -> V_17 ) , V_60 ) ;
V_297 -> type = V_303 ;
V_297 -> V_9 = V_9 ;
V_297 -> V_304 = 0 ;
V_297 -> V_305 = 0 ;
F_108 ( & V_297 -> V_306 , 0 ) ;
F_109 ( & V_297 -> V_307 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_296 * V_297 ,
int V_308 )
{
T_1 V_60 ;
V_297 -> V_308 = V_308 ;
V_60 = F_111 ( V_308 , 1 << V_309 ) ;
F_1 ( V_2 , F_112 ( V_297 -> V_17 ) , V_60 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_296 * V_297 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_297 -> V_305 ; V_22 ++ ) {
T_1 V_310 ;
F_3 ( V_2 , F_114 ( V_297 -> V_17 ) ) ;
V_310 = F_3 ( V_2 , V_311 ) ;
if ( ! V_310 )
break;
F_115 ( (struct V_10 * ) V_310 ) ;
}
V_297 -> V_305 -= V_22 ;
}
static int F_116 ( struct V_225 * V_226 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
T_1 V_60 ;
F_113 ( V_2 , V_297 ) ;
if ( V_297 -> V_305 ) {
F_117 ( 1 , L_2 , V_297 -> V_17 ) ;
return 0 ;
}
V_60 = F_3 ( V_2 , F_107 ( V_297 -> V_17 ) ) ;
V_60 |= V_312 ;
F_1 ( V_2 , F_107 ( V_297 -> V_17 ) , V_60 ) ;
F_103 ( & V_226 -> V_228 , sizeof( T_1 ) * V_297 -> V_9 ,
V_297 -> V_299 ,
V_297 -> V_300 ) ;
return 0 ;
}
static int F_118 ( struct V_225 * V_226 ,
struct V_1 * V_2 )
{
int V_22 , V_227 , V_9 ;
struct V_296 * V_297 ;
V_9 = V_313 ;
for ( V_22 = 0 ; V_22 < V_314 ; V_22 ++ ) {
V_297 = & V_2 -> V_315 [ V_22 ] ;
V_297 -> V_17 = V_22 ;
V_227 = F_100 ( V_226 , V_2 , V_297 , V_9 ) ;
if ( V_227 )
goto V_316;
F_110 ( V_2 , V_297 , 0 ) ;
}
return 0 ;
V_316:
F_104 ( & V_226 -> V_228 , L_3 , V_22 , V_9 ) ;
for ( V_22 = V_22 - 1 ; V_22 >= 0 ; V_22 -- )
F_116 ( V_226 , V_2 , & V_2 -> V_315 [ V_22 ] ) ;
return V_227 ;
}
static int F_119 ( struct V_225 * V_226 , struct V_1 * V_2 )
{
int V_22 , V_227 ;
for ( V_22 = 0 ; V_22 < V_314 ; V_22 ++ ) {
F_1 ( V_2 , F_120 ( V_22 ) , 0 ) ;
F_1 ( V_2 , F_121 ( V_22 ) , 0 ) ;
}
V_2 -> V_315 = F_75 ( & V_226 -> V_228 , V_314 ,
sizeof( struct V_296 ) , V_94 ) ;
if ( ! V_2 -> V_315 )
return - V_143 ;
V_227 = F_118 ( V_226 , V_2 ) ;
if ( V_227 < 0 )
return V_227 ;
return 0 ;
}
static void F_122 ( struct V_14 * V_15 ,
int V_317 , int V_318 )
{
T_1 V_60 ;
int V_319 ;
V_319 = V_15 -> V_320 [ V_317 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_319 ) ) ;
V_60 &= ~ V_321 ;
V_60 |= ( ( V_318 << V_322 ) &
V_321 ) ;
F_1 ( V_15 -> V_2 , F_123 ( V_319 ) , V_60 ) ;
}
static void F_124 ( struct V_14 * V_15 ,
int V_317 , int V_323 )
{
T_1 V_60 ;
int V_319 ;
V_319 = V_15 -> V_320 [ V_317 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_319 ) ) ;
V_60 &= ~ V_324 ;
V_60 |= ( ( V_323 << V_325 ) &
V_324 ) ;
F_1 ( V_15 -> V_2 , F_123 ( V_319 ) , V_60 ) ;
}
static struct V_10 * F_125 ( struct V_14 * V_15 ,
struct V_296 * V_297 ,
T_4 * V_326 ,
T_5 V_327 )
{
struct V_10 * V_11 ;
T_4 V_300 ;
V_11 = F_126 ( V_297 -> V_304 , V_327 ) ;
if ( ! V_11 )
return NULL ;
V_300 = F_127 ( V_15 -> V_228 -> V_228 . V_328 , V_11 -> V_329 ,
F_128 ( V_297 -> V_304 ) ,
V_330 ) ;
if ( F_129 ( F_130 ( V_15 -> V_228 -> V_228 . V_328 , V_300 ) ) ) {
F_115 ( V_11 ) ;
return NULL ;
}
* V_326 = V_300 ;
return V_11 ;
}
static inline T_1 F_131 ( T_1 V_331 , int V_332 )
{
T_1 V_333 ;
V_333 = V_331 & ~ ( 0xFF << V_334 ) ;
V_333 |= ( ( V_332 & 0xFF ) << V_334 ) ;
return V_333 ;
}
static inline int F_132 ( T_1 V_331 )
{
return ( V_331 >> V_334 ) & 0xFF ;
}
static inline void F_133 ( struct V_14 * V_15 , int V_332 ,
T_1 V_326 , T_1 V_335 )
{
F_1 ( V_15 -> V_2 , V_336 , V_335 ) ;
F_1 ( V_15 -> V_2 , F_134 ( V_332 ) , V_326 ) ;
}
static void F_135 ( struct V_14 * V_15 , int V_332 ,
T_1 V_326 , T_1 V_335 ,
int V_337 )
{
T_1 V_60 = 0 ;
V_60 |= ( V_337 & V_338 ) ;
F_1 ( V_15 -> V_2 , V_339 , V_60 ) ;
F_133 ( V_15 , V_332 ,
V_326 | V_340 ,
V_335 ) ;
}
static void F_136 ( struct V_14 * V_15 , T_1 V_333 ,
T_1 V_300 , T_1 V_331 )
{
int V_332 = F_132 ( V_333 ) ;
F_133 ( V_15 , V_332 , V_300 , V_331 ) ;
}
static int F_137 ( struct V_14 * V_15 ,
struct V_296 * V_297 , int V_305 )
{
struct V_10 * V_11 ;
int V_22 , V_308 , V_341 ;
T_1 V_333 ;
T_4 V_300 ;
V_308 = F_128 ( V_297 -> V_304 ) ;
V_341 = F_138 ( V_308 ) ;
if ( V_305 < 0 ||
( V_305 + V_297 -> V_305 > V_297 -> V_9 ) ) {
F_139 ( V_15 -> V_228 ,
L_4 ,
V_305 , V_297 -> V_17 ) ;
return 0 ;
}
V_333 = F_131 ( 0 , V_297 -> V_17 ) ;
for ( V_22 = 0 ; V_22 < V_305 ; V_22 ++ ) {
V_11 = F_125 ( V_15 , V_297 , & V_300 , V_94 ) ;
if ( ! V_11 )
break;
F_136 ( V_15 , V_333 , ( T_1 ) V_300 , ( T_1 ) V_11 ) ;
}
V_297 -> V_305 += V_22 ;
V_297 -> V_342 = V_297 -> V_305 / 4 ;
F_140 ( V_15 -> V_228 ,
L_5 ,
V_297 -> type == V_343 ? L_6 : L_7 ,
V_297 -> V_17 , V_297 -> V_304 , V_308 , V_341 ) ;
F_140 ( V_15 -> V_228 ,
L_8 ,
V_297 -> type == V_343 ? L_6 : L_7 ,
V_297 -> V_17 , V_22 , V_305 ) ;
return V_22 ;
}
static struct V_296 *
F_141 ( struct V_14 * V_15 , int V_332 , enum V_344 type ,
int V_304 )
{
unsigned long V_345 = 0 ;
struct V_296 * V_346 = & V_15 -> V_2 -> V_315 [ V_332 ] ;
int V_347 ;
if ( V_346 -> type != V_303 && V_346 -> type != type ) {
F_139 ( V_15 -> V_228 , L_9 ) ;
return NULL ;
}
F_142 ( & V_346 -> V_307 , V_345 ) ;
if ( V_346 -> type == V_303 )
V_346 -> type = type ;
if ( ( ( type == V_348 ) && ( V_304 > V_346 -> V_304 ) ) ||
( V_346 -> V_304 == 0 ) ) {
int V_349 ;
V_349 = V_346 -> V_305 ;
if ( V_349 == 0 )
V_349 = type == V_348 ?
V_350 :
V_351 ;
else
F_113 ( V_15 -> V_2 , V_346 ) ;
V_346 -> V_304 = V_304 ;
V_347 = F_137 ( V_15 , V_346 , V_349 ) ;
if ( V_347 != V_349 ) {
F_117 ( 1 , L_10 ,
V_346 -> V_17 , V_347 , V_349 ) ;
F_143 ( & V_346 -> V_307 , V_345 ) ;
return NULL ;
}
}
F_110 ( V_15 -> V_2 , V_346 ,
F_128 ( V_346 -> V_304 ) ) ;
F_143 ( & V_346 -> V_307 , V_345 ) ;
return V_346 ;
}
static int F_144 ( struct V_14 * V_15 )
{
unsigned long V_345 = 0 ;
int V_352 ;
if ( ! V_15 -> V_353 ) {
V_15 -> V_353 =
F_141 ( V_15 , F_145 ( V_15 -> V_17 ) ,
V_348 ,
V_15 -> V_304 ) ;
if ( ! V_15 -> V_353 )
return - V_143 ;
F_142 ( & V_15 -> V_353 -> V_307 , V_345 ) ;
V_15 -> V_353 -> V_141 |= ( 1 << V_15 -> V_17 ) ;
F_143 ( & V_15 -> V_353 -> V_307 , V_345 ) ;
for ( V_352 = 0 ; V_352 < V_354 ; V_352 ++ )
F_122 ( V_15 , V_352 , V_15 -> V_353 -> V_17 ) ;
}
if ( ! V_15 -> V_355 ) {
V_15 -> V_355 =
F_141 ( V_15 , V_356 ,
V_343 ,
V_357 ) ;
if ( ! V_15 -> V_355 )
return - V_143 ;
F_142 ( & V_15 -> V_355 -> V_307 , V_345 ) ;
V_15 -> V_355 -> V_141 |= ( 1 << V_15 -> V_17 ) ;
F_143 ( & V_15 -> V_355 -> V_307 , V_345 ) ;
for ( V_352 = 0 ; V_352 < V_354 ; V_352 ++ )
F_124 ( V_15 , V_352 ,
V_15 -> V_355 -> V_17 ) ;
}
return 0 ;
}
static int F_146 ( struct V_264 * V_228 , int V_358 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
struct V_296 * V_359 = V_15 -> V_353 ;
int V_347 , V_349 = V_359 -> V_305 ;
int V_304 = F_147 ( V_358 ) ;
F_113 ( V_15 -> V_2 , V_359 ) ;
if ( V_359 -> V_305 ) {
F_117 ( 1 , L_2 , V_359 -> V_17 ) ;
return - V_360 ;
}
V_359 -> V_304 = V_304 ;
V_347 = F_137 ( V_15 , V_359 , V_349 ) ;
if ( V_347 != V_349 ) {
F_117 ( 1 , L_10 ,
V_359 -> V_17 , V_347 , V_349 ) ;
return - V_360 ;
}
F_110 ( V_15 -> V_2 , V_359 ,
F_128 ( V_359 -> V_304 ) ) ;
V_228 -> V_358 = V_358 ;
F_148 ( V_228 ) ;
return 0 ;
}
static inline void F_149 ( struct V_14 * V_15 )
{
int V_361 , V_362 = 0 ;
F_150 (cpu)
V_362 |= 1 << V_361 ;
F_1 ( V_15 -> V_2 , F_151 ( V_15 -> V_17 ) ,
F_152 ( V_362 ) ) ;
}
static inline void F_153 ( struct V_14 * V_15 )
{
int V_361 , V_362 = 0 ;
F_150 (cpu)
V_362 |= 1 << V_361 ;
F_1 ( V_15 -> V_2 , F_151 ( V_15 -> V_17 ) ,
F_154 ( V_362 ) ) ;
}
static void F_155 ( void * V_363 )
{
struct V_14 * V_15 = V_363 ;
F_1 ( V_15 -> V_2 , F_156 ( V_15 -> V_17 ) , 0 ) ;
}
static void F_157 ( void * V_363 )
{
struct V_14 * V_15 = V_363 ;
F_1 ( V_15 -> V_2 , F_156 ( V_15 -> V_17 ) ,
( V_364 |
V_365 |
V_366 ) ) ;
}
static void F_158 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_367 ) ;
switch ( V_15 -> V_368 ) {
case V_369 :
V_60 |= V_370 ;
break;
case V_371 :
V_60 |= V_372 ;
default:
V_60 &= ~ V_373 ;
}
F_2 ( V_60 , V_15 -> V_5 + V_367 ) ;
}
static void F_159 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_374 ) ;
V_60 |= V_375 ;
F_2 ( V_60 , V_15 -> V_5 + V_374 ) ;
}
static void F_160 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_376 ) ;
V_60 |= V_377 ;
V_60 |= V_378 ;
F_2 ( V_60 , V_15 -> V_5 + V_376 ) ;
}
static void F_161 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_376 ) ;
V_60 &= ~ ( V_377 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_376 ) ;
}
static void F_162 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_379 ) &
~ V_380 ;
F_2 ( V_60 , V_15 -> V_5 + V_379 ) ;
}
static void F_163 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_379 ) ;
if ( V_15 -> V_381 == 1000 )
V_60 |= V_382 ;
else
V_60 &= ~ V_382 ;
if ( V_15 -> V_368 == V_369 )
V_60 |= V_383 ;
else
V_60 &= ~ V_383 ;
F_2 ( V_60 , V_15 -> V_5 + V_379 ) ;
}
static void F_164 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_367 ) &
~ V_384 ;
F_2 ( V_60 , V_15 -> V_5 + V_367 ) ;
while ( F_4 ( V_15 -> V_5 + V_367 ) &
V_384 )
continue;
}
static inline void F_165 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_376 ) ;
V_60 &= ~ V_385 ;
V_60 |= ( ( ( V_15 -> V_304 - V_189 ) / 2 ) <<
V_386 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_376 ) ;
}
static void F_166 ( struct V_14 * V_15 )
{
int V_387 , V_60 , V_388 , V_389 , V_317 ;
if ( V_15 -> V_345 & V_390 )
F_163 ( V_15 ) ;
V_60 = F_4 ( V_15 -> V_5 + V_391 ) ;
V_60 &= ~ V_392 ;
V_60 |= F_167 ( 64 - 4 - 2 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_391 ) ;
V_387 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_393 ,
V_387 ) ;
F_1 ( V_15 -> V_2 , V_394 , 0 ) ;
for ( V_388 = 0 ; V_388 < V_19 ; V_388 ++ ) {
V_389 = F_8 ( V_15 -> V_17 , V_388 ) ;
F_1 ( V_15 -> V_2 ,
F_168 ( V_389 ) , 0 ) ;
}
F_1 ( V_15 -> V_2 , V_395 ,
V_15 -> V_2 -> V_396 / V_397 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_398 ) ;
V_60 &= ~ V_399 ;
V_60 |= F_169 ( 1 ) ;
V_60 |= V_400 ;
F_1 ( V_15 -> V_2 , V_398 , V_60 ) ;
V_60 = V_401 ;
F_1 ( V_15 -> V_2 , V_402 , V_60 ) ;
F_1 ( V_15 -> V_2 , F_170 ( V_15 -> V_17 ) ,
V_403 |
F_171 ( 256 ) ) ;
for ( V_317 = 0 ; V_317 < V_354 ; V_317 ++ ) {
V_388 = V_15 -> V_320 [ V_317 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_388 ) ) ;
V_60 |= V_404 |
V_405 ;
F_1 ( V_15 -> V_2 , F_123 ( V_388 ) , V_60 ) ;
}
F_153 ( V_15 ) ;
}
static void F_172 ( struct V_14 * V_15 )
{
T_1 V_60 ;
int V_317 , V_388 ;
for ( V_317 = 0 ; V_317 < V_354 ; V_317 ++ ) {
V_388 = V_15 -> V_320 [ V_317 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_388 ) ) ;
V_60 &= ~ V_406 ;
F_1 ( V_15 -> V_2 , F_123 ( V_388 ) , V_60 ) ;
}
}
static void F_173 ( struct V_14 * V_15 )
{
T_1 V_60 ;
int V_317 , V_388 ;
for ( V_317 = 0 ; V_317 < V_354 ; V_317 ++ ) {
V_388 = V_15 -> V_320 [ V_317 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_388 ) ) ;
V_60 |= V_406 ;
F_1 ( V_15 -> V_2 , F_123 ( V_388 ) , V_60 ) ;
}
}
static void F_174 ( struct V_14 * V_15 )
{
T_1 V_407 ;
int V_388 ;
int V_387 = F_7 ( V_15 ) ;
V_407 = 0 ;
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
struct V_409 * V_18 = V_15 -> V_410 [ V_388 ] ;
if ( V_18 -> V_411 != NULL )
V_407 |= ( 1 << V_388 ) ;
}
F_1 ( V_15 -> V_2 , V_393 , V_387 ) ;
F_1 ( V_15 -> V_2 , V_412 , V_407 ) ;
}
static void F_175 ( struct V_14 * V_15 )
{
T_1 V_413 ;
int V_414 ;
int V_387 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_393 , V_387 ) ;
V_413 = ( F_3 ( V_15 -> V_2 , V_412 ) ) &
V_415 ;
if ( V_413 != 0 )
F_1 ( V_15 -> V_2 , V_412 ,
( V_413 << V_416 ) ) ;
V_414 = 0 ;
do {
if ( V_414 >= V_417 ) {
F_176 ( V_15 -> V_228 ,
L_11 ,
V_413 ) ;
break;
}
F_177 ( 1 ) ;
V_414 ++ ;
V_413 = F_3 ( V_15 -> V_2 , V_412 ) ;
} while ( V_413 & V_415 );
}
static inline int
F_178 ( struct V_14 * V_15 , int V_418 )
{
T_1 V_60 = F_3 ( V_15 -> V_2 , F_179 ( V_418 ) ) ;
return V_60 & V_419 ;
}
static inline void
F_180 ( struct V_14 * V_15 , int V_418 ,
int V_420 , int V_421 )
{
T_1 V_60 = V_420 | ( V_421 << V_422 ) ;
F_1 ( V_15 -> V_2 , F_181 ( V_418 ) , V_60 ) ;
}
static inline struct V_423 *
F_182 ( struct V_424 * V_352 )
{
int V_425 = V_352 -> V_426 ;
V_352 -> V_426 = F_183 ( V_352 , V_425 ) ;
F_184 ( V_352 -> V_411 + V_352 -> V_426 ) ;
return V_352 -> V_411 + V_425 ;
}
static void F_185 ( struct V_14 * V_15 ,
int V_319 , int V_3 )
{
T_1 V_60 ;
V_3 = V_3 >> 5 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_319 ) ) ;
V_60 &= ~ V_427 ;
V_60 |= ( ( V_3 << V_428 ) &
V_427 ) ;
F_1 ( V_15 -> V_2 , F_123 ( V_319 ) , V_60 ) ;
}
static T_1 F_186 ( struct V_423 * V_425 )
{
int V_332 = ( V_425 -> V_429 & V_430 ) >>
V_431 ;
int V_361 = F_187 () ;
return ( ( V_332 & 0xFF ) << V_334 ) |
( ( V_361 & 0xFF ) << V_432 ) ;
}
static int F_188 ( struct V_14 * V_15 ,
struct V_409 * V_18 )
{
T_1 V_60 ;
F_1 ( V_15 -> V_2 , V_433 , V_18 -> V_17 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_434 ) ;
return V_60 & V_435 ;
}
static struct V_436 *
F_189 ( struct V_409 * V_18 )
{
int V_437 = V_18 -> V_426 ;
V_18 -> V_426 = F_183 ( V_18 , V_437 ) ;
return V_18 -> V_411 + V_437 ;
}
static void F_190 ( struct V_14 * V_15 , int V_438 )
{
F_1 ( V_15 -> V_2 , V_439 , V_438 ) ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_409 * V_440 , int V_347 )
{
if ( ( V_440 -> V_441 + V_347 ) > V_440 -> V_9 ) {
int V_361 = F_187 () ;
T_1 V_60 = F_3 ( V_2 , F_192 ( V_361 ) ) ;
V_440 -> V_441 = V_60 & V_442 ;
}
if ( ( V_440 -> V_441 + V_347 ) > V_440 -> V_9 )
return - V_143 ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 ,
struct V_409 * V_18 , int V_347 )
{
T_1 V_60 ;
V_60 = ( V_18 -> V_17 << V_443 ) | V_347 ;
F_1 ( V_2 , V_444 , V_60 ) ;
V_60 = F_3 ( V_2 , V_445 ) ;
return V_60 & V_446 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_409 * V_18 ,
struct V_6 * V_7 ,
int V_347 )
{
int V_447 , V_361 , V_448 ;
if ( V_7 -> V_449 >= V_347 )
return 0 ;
V_448 = 0 ;
F_150 (cpu) {
struct V_6 * V_450 ;
V_450 = F_195 ( V_18 -> V_451 , V_361 ) ;
V_448 += V_450 -> V_441 ;
V_448 += V_450 -> V_449 ;
}
V_447 = F_196 ( V_452 , V_347 - V_7 -> V_449 ) ;
V_448 += V_447 ;
if ( V_448 >
( V_18 -> V_9 - ( F_197 () * V_452 ) ) )
return - V_143 ;
V_7 -> V_449 += F_193 ( V_2 , V_18 , V_447 ) ;
if ( V_7 -> V_449 < V_347 )
return - V_143 ;
return 0 ;
}
static void F_198 ( struct V_409 * V_18 )
{
if ( V_18 -> V_426 == 0 )
V_18 -> V_426 = V_18 -> V_453 - 1 ;
else
V_18 -> V_426 -- ;
}
static T_1 F_199 ( int V_454 , int V_455 ,
int V_456 , int V_457 )
{
T_1 V_458 ;
V_458 = ( V_454 << V_459 ) ;
V_458 |= ( V_456 << V_460 ) ;
V_458 |= V_461 ;
if ( V_455 == F_51 ( V_213 ) ) {
V_458 &= ~ V_461 ;
V_458 &= ~ V_462 ;
} else {
V_458 |= V_462 ;
}
if ( V_457 == V_153 ) {
V_458 &= ~ V_463 ;
V_458 &= ~ V_464 ;
} else if ( V_457 == V_154 ) {
V_458 |= V_463 ;
V_458 &= ~ V_464 ;
} else {
V_458 |= V_465 ;
}
return V_458 ;
}
static inline int F_200 ( struct V_14 * V_15 ,
struct V_409 * V_18 )
{
T_1 V_60 ;
V_60 = F_3 ( V_15 -> V_2 , F_201 ( V_18 -> V_17 ) ) ;
return ( V_60 & V_466 ) >>
V_467 ;
}
static void F_202 ( void * V_363 )
{
struct V_14 * V_15 = V_363 ;
int V_388 ;
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
int V_17 = V_15 -> V_410 [ V_388 ] -> V_17 ;
F_3 ( V_15 -> V_2 , F_201 ( V_17 ) ) ;
}
}
static void F_203 ( struct V_14 * V_15 )
{
T_1 V_60 , V_9 , V_358 ;
int V_18 , V_387 ;
V_358 = V_15 -> V_304 * 8 ;
if ( V_358 > V_468 )
V_358 = V_468 ;
V_358 = 3 * V_358 ;
V_387 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_393 , V_387 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_469 ) ;
V_60 &= ~ V_468 ;
V_60 |= V_358 ;
F_1 ( V_15 -> V_2 , V_469 , V_60 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_402 ) ;
V_9 = V_60 & V_401 ;
if ( V_9 < V_358 ) {
V_9 = V_358 ;
V_60 &= ~ V_401 ;
V_60 |= V_9 ;
F_1 ( V_15 -> V_2 , V_402 , V_60 ) ;
}
for ( V_18 = 0 ; V_18 < V_408 ; V_18 ++ ) {
V_60 = F_3 ( V_15 -> V_2 ,
F_204 ( V_18 ) ) ;
V_9 = V_60 & V_470 ;
if ( V_9 < V_358 ) {
V_9 = V_358 ;
V_60 &= ~ V_470 ;
V_60 |= V_9 ;
F_1 ( V_15 -> V_2 ,
F_204 ( V_18 ) ,
V_60 ) ;
}
}
}
static void F_205 ( struct V_14 * V_15 ,
struct V_424 * V_352 , T_1 V_471 )
{
T_1 V_60 ;
V_60 = ( V_471 & V_472 ) ;
F_1 ( V_15 -> V_2 , V_473 , V_352 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_474 , V_60 ) ;
V_352 -> V_475 = V_471 ;
}
static void F_206 ( struct V_14 * V_15 ,
struct V_424 * V_352 , T_1 V_476 )
{
T_1 V_60 ;
V_60 = ( V_15 -> V_2 -> V_396 / V_397 ) * V_476 ;
F_1 ( V_15 -> V_2 , F_207 ( V_352 -> V_17 ) , V_60 ) ;
V_352 -> V_477 = V_476 ;
}
static void F_208 ( void * V_363 )
{
struct V_14 * V_15 = V_363 ;
int V_388 ;
T_1 V_60 ;
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
struct V_409 * V_18 = V_15 -> V_410 [ V_388 ] ;
V_60 = ( V_18 -> V_478 << V_479 ) &
V_480 ;
F_1 ( V_15 -> V_2 , V_433 , V_18 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_481 , V_60 ) ;
}
}
static void F_209 ( struct V_14 * V_15 ,
struct V_409 * V_18 ,
struct V_6 * V_7 , int V_347 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_347 ; V_22 ++ ) {
struct V_436 * V_437 = V_18 -> V_411 +
V_7 -> V_8 ;
struct V_10 * V_11 = V_7 -> V_12 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! V_11 )
continue;
F_210 ( V_15 -> V_228 -> V_228 . V_328 , V_437 -> V_326 ,
V_437 -> V_482 , V_483 ) ;
F_115 ( V_11 ) ;
}
}
static inline struct V_424 * F_211 ( struct V_14 * V_15 ,
T_1 V_484 )
{
int V_388 = F_212 ( V_484 ) - 1 ;
return V_15 -> V_320 [ V_388 ] ;
}
static inline struct V_409 * F_213 ( struct V_14 * V_15 ,
T_1 V_484 )
{
int V_388 = F_212 ( V_484 >> 16 ) - 1 ;
return V_15 -> V_410 [ V_388 ] ;
}
static void F_214 ( struct V_14 * V_15 , struct V_409 * V_18 ,
struct V_6 * V_7 )
{
struct V_485 * V_486 = F_215 ( V_15 -> V_228 , V_18 -> V_487 ) ;
int V_488 ;
if ( V_7 -> V_361 != F_187 () )
F_139 ( V_15 -> V_228 , L_12 ) ;
V_488 = F_200 ( V_15 , V_18 ) ;
if ( ! V_488 )
return;
F_209 ( V_15 , V_18 , V_7 , V_488 ) ;
V_7 -> V_441 -= V_488 ;
if ( F_216 ( V_486 ) )
if ( V_7 -> V_9 - V_7 -> V_441 >= V_489 + 1 )
F_217 ( V_486 ) ;
}
static int F_218 ( struct V_225 * V_226 ,
struct V_409 * V_440 ,
int V_490 , int V_361 ,
struct V_1 * V_2 )
{
V_440 -> V_411 = F_101 ( & V_226 -> V_228 ,
V_490 * V_491 ,
& V_440 -> V_492 , V_94 ) ;
if ( ! V_440 -> V_411 )
return - V_143 ;
F_219 ( V_440 -> V_411 !=
F_220 ( V_440 -> V_411 , V_493 ) ) ;
V_440 -> V_453 = V_440 -> V_9 - 1 ;
V_440 -> V_426 = F_3 ( V_2 ,
F_221 ( V_361 ) ) ;
F_1 ( V_2 , F_222 ( V_361 ) ,
V_440 -> V_492 ) ;
F_1 ( V_2 , F_223 ( V_361 ) , V_490 ) ;
return 0 ;
}
static int F_224 ( struct V_14 * V_15 ,
struct V_424 * V_352 )
{
V_352 -> V_9 = V_15 -> V_494 ;
V_352 -> V_411 = F_101 ( V_15 -> V_228 -> V_228 . V_328 ,
V_352 -> V_9 * V_491 ,
& V_352 -> V_492 , V_94 ) ;
if ( ! V_352 -> V_411 )
return - V_143 ;
F_219 ( V_352 -> V_411 !=
F_220 ( V_352 -> V_411 , V_493 ) ) ;
V_352 -> V_453 = V_352 -> V_9 - 1 ;
F_1 ( V_15 -> V_2 , F_179 ( V_352 -> V_17 ) , 0 ) ;
F_1 ( V_15 -> V_2 , V_473 , V_352 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_495 , V_352 -> V_492 ) ;
F_1 ( V_15 -> V_2 , V_496 , V_352 -> V_9 ) ;
F_1 ( V_15 -> V_2 , V_497 , 0 ) ;
F_185 ( V_15 , V_352 -> V_17 , V_498 ) ;
F_205 ( V_15 , V_352 , V_352 -> V_475 ) ;
F_206 ( V_15 , V_352 , V_352 -> V_477 ) ;
F_180 ( V_15 , V_352 -> V_17 , 0 , V_352 -> V_9 ) ;
return 0 ;
}
static void F_225 ( struct V_14 * V_15 ,
struct V_424 * V_352 )
{
int V_499 , V_22 ;
V_499 = F_178 ( V_15 , V_352 -> V_17 ) ;
if ( ! V_499 )
return;
for ( V_22 = 0 ; V_22 < V_499 ; V_22 ++ ) {
struct V_423 * V_425 = F_182 ( V_352 ) ;
T_1 V_333 = F_186 ( V_425 ) ;
F_136 ( V_15 , V_333 , V_425 -> V_326 ,
V_425 -> V_500 ) ;
}
F_180 ( V_15 , V_352 -> V_17 , V_499 , V_499 ) ;
}
static void F_226 ( struct V_14 * V_15 ,
struct V_424 * V_352 )
{
F_225 ( V_15 , V_352 ) ;
if ( V_352 -> V_411 )
F_103 ( V_15 -> V_228 -> V_228 . V_328 ,
V_352 -> V_9 * V_491 ,
V_352 -> V_411 ,
V_352 -> V_492 ) ;
V_352 -> V_411 = NULL ;
V_352 -> V_453 = 0 ;
V_352 -> V_426 = 0 ;
V_352 -> V_492 = 0 ;
F_1 ( V_15 -> V_2 , F_179 ( V_352 -> V_17 ) , 0 ) ;
F_1 ( V_15 -> V_2 , V_473 , V_352 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_495 , 0 ) ;
F_1 ( V_15 -> V_2 , V_496 , 0 ) ;
}
static int F_227 ( struct V_14 * V_15 ,
struct V_409 * V_18 )
{
T_1 V_60 ;
int V_361 , V_501 , V_502 , V_387 ;
struct V_6 * V_7 ;
V_18 -> V_9 = V_15 -> V_503 ;
V_18 -> V_411 = F_101 ( V_15 -> V_228 -> V_228 . V_328 ,
V_18 -> V_9 * V_491 ,
& V_18 -> V_492 , V_94 ) ;
if ( ! V_18 -> V_411 )
return - V_143 ;
F_219 ( V_18 -> V_411 !=
F_220 ( V_18 -> V_411 , V_493 ) ) ;
V_18 -> V_453 = V_18 -> V_9 - 1 ;
F_1 ( V_15 -> V_2 , V_433 , V_18 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_504 , V_18 -> V_492 ) ;
F_1 ( V_15 -> V_2 , V_505 , V_18 -> V_9 &
V_506 ) ;
F_1 ( V_15 -> V_2 , V_507 , 0 ) ;
F_1 ( V_15 -> V_2 , V_508 ,
V_18 -> V_17 << V_509 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_434 ) ;
V_60 &= ~ V_435 ;
F_1 ( V_15 -> V_2 , V_434 , V_60 ) ;
V_502 = 16 ;
V_501 = ( V_15 -> V_17 * V_19 * V_502 ) +
( V_18 -> V_487 * V_502 ) ;
F_1 ( V_15 -> V_2 , V_510 ,
F_228 ( V_501 ) | V_511 |
F_229 ( V_502 / 2 ) ) ;
V_387 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_393 , V_387 ) ;
V_60 = F_3 ( V_15 -> V_2 , F_230 ( V_18 -> V_487 ) ) ;
V_60 &= ~ V_512 ;
V_60 |= F_231 ( 1 ) ;
V_60 |= V_513 ;
F_1 ( V_15 -> V_2 , F_230 ( V_18 -> V_487 ) , V_60 ) ;
V_60 = V_470 ;
F_1 ( V_15 -> V_2 , F_204 ( V_18 -> V_487 ) ,
V_60 ) ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_451 , V_361 ) ;
V_7 -> V_9 = V_18 -> V_9 ;
V_7 -> V_12 = F_232 ( V_7 -> V_9 *
sizeof( * V_7 -> V_12 ) ,
V_94 ) ;
if ( ! V_7 -> V_12 ) {
F_103 ( V_15 -> V_228 -> V_228 . V_328 ,
V_18 -> V_9 * V_491 ,
V_18 -> V_411 , V_18 -> V_492 ) ;
return - V_143 ;
}
V_7 -> V_441 = 0 ;
V_7 -> V_449 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_8 = 0 ;
}
return 0 ;
}
static void F_233 ( struct V_14 * V_15 ,
struct V_409 * V_18 )
{
struct V_6 * V_7 ;
int V_361 ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_451 , V_361 ) ;
F_42 ( V_7 -> V_12 ) ;
}
if ( V_18 -> V_411 )
F_103 ( V_15 -> V_228 -> V_228 . V_328 ,
V_18 -> V_9 * V_491 ,
V_18 -> V_411 , V_18 -> V_492 ) ;
V_18 -> V_411 = NULL ;
V_18 -> V_453 = 0 ;
V_18 -> V_426 = 0 ;
V_18 -> V_492 = 0 ;
F_1 ( V_15 -> V_2 , F_168 ( V_18 -> V_17 ) , 0 ) ;
F_1 ( V_15 -> V_2 , V_433 , V_18 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_504 , 0 ) ;
F_1 ( V_15 -> V_2 , V_505 , 0 ) ;
}
static void F_234 ( struct V_14 * V_15 , struct V_409 * V_18 )
{
struct V_6 * V_7 ;
int V_414 , V_438 , V_361 ;
T_1 V_60 ;
F_1 ( V_15 -> V_2 , V_433 , V_18 -> V_17 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_510 ) ;
V_60 |= V_514 ;
F_1 ( V_15 -> V_2 , V_510 , V_60 ) ;
V_414 = 0 ;
do {
if ( V_414 >= V_515 ) {
F_176 ( V_15 -> V_228 ,
L_13 ,
V_15 -> V_17 , V_18 -> V_487 ) ;
break;
}
F_177 ( 1 ) ;
V_414 ++ ;
V_438 = F_188 ( V_15 , V_18 ) ;
} while ( V_438 );
V_60 &= ~ V_514 ;
F_1 ( V_15 -> V_2 , V_510 , V_60 ) ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_451 , V_361 ) ;
F_209 ( V_15 , V_18 , V_7 , V_7 -> V_441 ) ;
V_7 -> V_441 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_8 = 0 ;
}
}
static void F_235 ( struct V_14 * V_15 )
{
struct V_409 * V_18 ;
int V_388 ;
T_1 V_60 ;
V_60 = F_3 ( V_15 -> V_2 , V_516 ) ;
V_60 |= F_236 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_516 , V_60 ) ;
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
V_18 = V_15 -> V_410 [ V_388 ] ;
F_234 ( V_15 , V_18 ) ;
F_233 ( V_15 , V_18 ) ;
}
F_237 ( F_202 , V_15 , 1 ) ;
V_60 &= ~ F_236 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_516 , V_60 ) ;
}
static void F_238 ( struct V_14 * V_15 )
{
int V_388 ;
for ( V_388 = 0 ; V_388 < V_354 ; V_388 ++ )
F_226 ( V_15 , V_15 -> V_320 [ V_388 ] ) ;
}
static int F_239 ( struct V_14 * V_15 )
{
int V_388 , V_227 ;
for ( V_388 = 0 ; V_388 < V_354 ; V_388 ++ ) {
V_227 = F_224 ( V_15 , V_15 -> V_320 [ V_388 ] ) ;
if ( V_227 )
goto V_517;
}
return 0 ;
V_517:
F_238 ( V_15 ) ;
return V_227 ;
}
static int F_240 ( struct V_14 * V_15 )
{
struct V_409 * V_18 ;
int V_388 , V_227 ;
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
V_18 = V_15 -> V_410 [ V_388 ] ;
V_227 = F_227 ( V_15 , V_18 ) ;
if ( V_227 )
goto V_517;
}
F_237 ( F_208 , V_15 , 1 ) ;
F_237 ( F_202 , V_15 , 1 ) ;
return 0 ;
V_517:
F_235 ( V_15 ) ;
return V_227 ;
}
static T_6 F_241 ( int V_518 , void * V_519 )
{
struct V_14 * V_15 = (struct V_14 * ) V_519 ;
F_153 ( V_15 ) ;
F_242 ( & V_15 -> V_520 ) ;
return V_521 ;
}
static void F_243 ( struct V_264 * V_228 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
struct V_522 * V_523 = V_15 -> V_524 ;
int V_525 = 0 ;
T_1 V_60 ;
if ( V_523 -> V_526 ) {
if ( ( V_15 -> V_381 != V_523 -> V_381 ) ||
( V_15 -> V_527 != V_523 -> V_527 ) ) {
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_374 ) ;
V_60 &= ~ ( V_528 |
V_529 |
V_530 |
V_531 |
V_532 ) ;
if ( V_523 -> V_527 )
V_60 |= V_530 ;
if ( V_523 -> V_381 == V_533 )
V_60 |= V_529 ;
else if ( V_523 -> V_381 == V_534 )
V_60 |= V_528 ;
F_2 ( V_60 , V_15 -> V_5 + V_374 ) ;
V_15 -> V_527 = V_523 -> V_527 ;
V_15 -> V_381 = V_523 -> V_381 ;
}
}
if ( V_523 -> V_526 != V_15 -> V_526 ) {
if ( ! V_523 -> V_526 ) {
V_15 -> V_527 = - 1 ;
V_15 -> V_381 = 0 ;
}
V_15 -> V_526 = V_523 -> V_526 ;
V_525 = 1 ;
}
if ( V_525 ) {
if ( V_523 -> V_526 ) {
V_60 = F_4 ( V_15 -> V_5 + V_374 ) ;
V_60 |= ( V_535 |
V_536 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_374 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
} else {
F_173 ( V_15 ) ;
F_175 ( V_15 ) ;
}
F_244 ( V_523 ) ;
}
}
static void F_245 ( struct V_14 * V_15 ,
struct V_423 * V_425 )
{
T_1 V_429 = V_425 -> V_429 ;
switch ( V_429 & V_537 ) {
case V_538 :
F_139 ( V_15 -> V_228 , L_14 ,
V_429 , V_425 -> V_482 ) ;
break;
case V_539 :
F_139 ( V_15 -> V_228 , L_15 ,
V_429 , V_425 -> V_482 ) ;
break;
case V_540 :
F_139 ( V_15 -> V_228 , L_16 ,
V_429 , V_425 -> V_482 ) ;
break;
}
}
static void F_246 ( struct V_14 * V_15 , T_1 V_429 ,
struct V_10 * V_11 )
{
if ( ( ( V_429 & V_541 ) &&
! ( V_429 & V_542 ) ) ||
( V_429 & V_543 ) )
if ( ( ( V_429 & V_544 ) ||
( V_429 & V_545 ) ) &&
( V_429 & V_546 ) ) {
V_11 -> V_547 = 0 ;
V_11 -> V_548 = V_549 ;
return;
}
V_11 -> V_548 = V_550 ;
}
static int F_247 ( struct V_14 * V_15 ,
struct V_296 * V_297 ,
T_1 V_333 , int V_551 )
{
struct V_10 * V_11 ;
T_4 V_300 ;
if ( V_551 &&
( F_248 ( & V_297 -> V_306 ) < V_297 -> V_342 ) )
return 0 ;
V_11 = F_125 ( V_15 , V_297 , & V_300 , V_552 ) ;
if ( ! V_11 )
return - V_143 ;
F_136 ( V_15 , V_333 , ( T_1 ) V_300 , ( T_1 ) V_11 ) ;
F_249 ( & V_297 -> V_306 ) ;
return 0 ;
}
static T_1 F_250 ( struct V_14 * V_15 , struct V_10 * V_11 )
{
if ( V_11 -> V_548 == V_553 ) {
int V_456 = 0 ;
T_3 V_457 ;
if ( V_11 -> V_554 == F_251 ( V_213 ) ) {
struct V_158 * V_555 = F_252 ( V_11 ) ;
V_456 = V_555 -> V_556 ;
V_457 = V_555 -> V_554 ;
} else if ( V_11 -> V_554 == F_251 ( V_220 ) ) {
struct V_177 * V_557 = F_253 ( V_11 ) ;
if ( F_254 ( V_11 ) > 0 )
V_456 = ( F_254 ( V_11 ) >> 2 ) ;
V_457 = V_557 -> V_558 ;
} else {
return V_465 ;
}
return F_199 ( F_255 ( V_11 ) ,
V_11 -> V_554 , V_456 , V_457 ) ;
}
return V_465 | V_461 ;
}
static void F_256 ( struct V_14 * V_15 ,
struct V_423 * V_425 )
{
struct V_559 * V_560 ;
struct V_10 * V_11 ;
T_1 V_561 = V_425 -> V_429 ;
T_1 V_562 ;
T_1 V_563 ;
T_1 V_564 ;
T_1 V_565 ;
int V_337 ;
int V_566 ;
V_566 = ( V_561 & V_430 ) >>
V_431 ;
V_562 = V_425 -> V_326 ;
V_563 = V_425 -> V_500 ;
do {
V_11 = (struct V_10 * ) V_563 ;
V_560 = (struct V_559 * ) V_11 -> V_329 ;
V_337 = F_257 ( V_560 -> V_567 ) ;
V_564 = V_560 -> V_568 ;
V_565 = V_560 -> V_569 ;
F_135 ( V_15 , V_566 , V_562 ,
V_563 , V_337 ) ;
V_562 = V_564 ;
V_563 = V_565 ;
} while ( ! F_258 ( V_560 -> V_567 ) );
}
static int F_259 ( struct V_14 * V_15 , int V_570 ,
struct V_424 * V_352 )
{
struct V_264 * V_228 = V_15 -> V_228 ;
int V_499 , V_571 , V_22 ;
T_1 V_572 = 0 ;
T_1 V_573 = 0 ;
V_499 = F_178 ( V_15 , V_352 -> V_17 ) ;
if ( V_570 > V_499 )
V_570 = V_499 ;
V_571 = 0 ;
for ( V_22 = 0 ; V_22 < V_570 ; V_22 ++ ) {
struct V_423 * V_425 = F_182 ( V_352 ) ;
struct V_296 * V_297 ;
struct V_10 * V_11 ;
T_1 V_333 , V_561 ;
int V_332 , V_574 , V_227 ;
V_571 ++ ;
V_561 = V_425 -> V_429 ;
V_574 = V_425 -> V_482 - V_189 ;
V_333 = F_186 ( V_425 ) ;
V_332 = F_132 ( V_333 ) ;
V_297 = & V_15 -> V_2 -> V_315 [ V_332 ] ;
if ( V_561 & V_575 ) {
F_256 ( V_15 , V_425 ) ;
continue;
}
if ( V_561 & V_576 ) {
V_228 -> V_577 . V_578 ++ ;
F_245 ( V_15 , V_425 ) ;
F_136 ( V_15 , V_333 , V_425 -> V_326 ,
V_425 -> V_500 ) ;
continue;
}
V_11 = (struct V_10 * ) V_425 -> V_500 ;
V_572 ++ ;
V_573 += V_574 ;
F_260 ( & V_297 -> V_306 ) ;
F_261 ( V_11 , V_189 ) ;
F_262 ( V_11 , V_574 ) ;
V_11 -> V_554 = F_263 ( V_11 , V_228 ) ;
F_246 ( V_15 , V_561 , V_11 ) ;
F_264 ( & V_15 -> V_520 , V_11 ) ;
V_227 = F_247 ( V_15 , V_297 , V_333 , 0 ) ;
if ( V_227 ) {
F_139 ( V_15 -> V_228 , L_17 ) ;
V_571 -- ;
}
}
if ( V_572 ) {
struct V_579 * V_577 = F_265 ( V_15 -> V_577 ) ;
F_266 ( & V_577 -> V_580 ) ;
V_577 -> V_581 += V_572 ;
V_577 -> V_574 += V_573 ;
F_267 ( & V_577 -> V_580 ) ;
}
F_268 () ;
F_180 ( V_15 , V_352 -> V_17 , V_570 , V_571 ) ;
return V_570 ;
}
static inline void
F_269 ( struct V_582 * V_228 , struct V_409 * V_18 ,
struct V_436 * V_501 )
{
F_210 ( V_228 , V_501 -> V_326 ,
V_501 -> V_482 , V_483 ) ;
F_198 ( V_18 ) ;
}
static int F_270 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_409 * V_440 ,
struct V_409 * V_18 )
{
struct V_6 * V_7 = F_265 ( V_18 -> V_451 ) ;
struct V_436 * V_437 ;
int V_22 ;
T_4 V_326 ;
for ( V_22 = 0 ; V_22 < F_271 ( V_11 ) -> V_583 ; V_22 ++ ) {
T_7 * V_584 = & F_271 ( V_11 ) -> V_585 [ V_22 ] ;
void * V_586 = F_272 ( V_584 -> V_587 . V_588 ) + V_584 -> V_589 ;
V_437 = F_189 ( V_440 ) ;
V_437 -> V_590 = V_18 -> V_17 ;
V_437 -> V_482 = V_584 -> V_9 ;
V_326 = F_127 ( V_15 -> V_228 -> V_228 . V_328 , V_586 ,
V_437 -> V_482 ,
V_483 ) ;
if ( F_130 ( V_15 -> V_228 -> V_228 . V_328 , V_326 ) ) {
F_198 ( V_18 ) ;
goto error;
}
V_437 -> V_591 = V_326 & V_592 ;
V_437 -> V_326 = V_326 & ( ~ V_592 ) ;
if ( V_22 == ( F_271 ( V_11 ) -> V_583 - 1 ) ) {
V_437 -> V_458 = V_593 ;
F_6 ( V_7 , V_11 ) ;
} else {
V_437 -> V_458 = 0 ;
F_6 ( V_7 , NULL ) ;
}
}
return 0 ;
error:
for ( V_22 = V_22 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_437 = V_18 -> V_411 + V_22 ;
F_269 ( V_15 -> V_228 -> V_228 . V_328 , V_18 , V_437 ) ;
}
return - V_143 ;
}
static int F_273 ( struct V_10 * V_11 , struct V_264 * V_228 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
struct V_409 * V_18 , * V_440 ;
struct V_6 * V_7 ;
struct V_436 * V_437 ;
T_4 V_326 ;
int V_585 = 0 ;
T_2 V_594 ;
T_1 V_595 ;
V_594 = F_274 ( V_11 ) ;
V_18 = V_15 -> V_410 [ V_594 ] ;
V_7 = F_265 ( V_18 -> V_451 ) ;
V_440 = & V_15 -> V_2 -> V_596 [ F_187 () ] ;
V_585 = F_271 ( V_11 ) -> V_583 + 1 ;
if ( F_191 ( V_15 -> V_2 , V_440 , V_585 ) ||
F_194 ( V_15 -> V_2 , V_18 ,
V_7 , V_585 ) ) {
V_585 = 0 ;
goto V_597;
}
V_437 = F_189 ( V_440 ) ;
V_437 -> V_590 = V_18 -> V_17 ;
V_437 -> V_482 = F_275 ( V_11 ) ;
V_326 = F_127 ( V_228 -> V_228 . V_328 , V_11 -> V_4 ,
V_437 -> V_482 , V_483 ) ;
if ( F_129 ( F_130 ( V_228 -> V_228 . V_328 , V_326 ) ) ) {
F_198 ( V_18 ) ;
V_585 = 0 ;
goto V_597;
}
V_437 -> V_591 = V_326 & V_592 ;
V_437 -> V_326 = V_326 & ~ V_592 ;
V_595 = F_250 ( V_15 , V_11 ) ;
if ( V_585 == 1 ) {
V_595 |= V_598 | V_593 ;
V_437 -> V_458 = V_595 ;
F_6 ( V_7 , V_11 ) ;
} else {
V_595 |= V_598 | V_599 ;
V_437 -> V_458 = V_595 ;
F_6 ( V_7 , NULL ) ;
if ( F_270 ( V_15 , V_11 , V_440 , V_18 ) ) {
F_269 ( V_15 -> V_228 -> V_228 . V_328 , V_18 , V_437 ) ;
V_585 = 0 ;
goto V_597;
}
}
V_7 -> V_449 -= V_585 ;
V_7 -> V_441 += V_585 ;
V_440 -> V_441 += V_585 ;
F_268 () ;
F_190 ( V_15 , V_585 ) ;
if ( V_7 -> V_9 - V_7 -> V_441 < V_489 + 1 ) {
struct V_485 * V_486 = F_215 ( V_228 , V_594 ) ;
F_276 ( V_486 ) ;
}
V_597:
if ( V_585 > 0 ) {
struct V_579 * V_577 = F_265 ( V_15 -> V_577 ) ;
F_266 ( & V_577 -> V_580 ) ;
V_577 -> V_600 ++ ;
V_577 -> V_601 += V_11 -> V_259 ;
F_267 ( & V_577 -> V_580 ) ;
} else {
V_228 -> V_577 . V_602 ++ ;
F_115 ( V_11 ) ;
}
return V_603 ;
}
static inline void F_277 ( struct V_264 * V_228 , int V_484 )
{
if ( V_484 & V_604 )
F_139 ( V_228 , L_18 ) ;
if ( V_484 & V_605 )
F_139 ( V_228 , L_19 ) ;
if ( V_484 & V_606 )
F_139 ( V_228 , L_20 ) ;
}
static void F_278 ( void * V_363 )
{
struct V_14 * V_15 = V_363 ;
T_1 V_607 , V_608 , V_609 ;
V_607 = F_3 ( V_15 -> V_2 ,
F_279 ( V_15 -> V_17 ) ) ;
V_608 = V_607 & V_365 ;
V_609 = V_607 & V_364 ;
if ( V_609 ) {
F_277 ( V_15 -> V_228 , V_609 ) ;
F_1 ( V_15 -> V_2 , V_610 , 0 ) ;
F_1 ( V_15 -> V_2 , F_279 ( V_15 -> V_17 ) ,
V_607 & ~ V_364 ) ;
}
if ( V_608 ) {
struct V_409 * V_18 = F_213 ( V_15 , V_608 ) ;
struct V_6 * V_7 = F_265 ( V_18 -> V_451 ) ;
if ( V_7 -> V_441 )
F_214 ( V_15 , V_18 , V_7 ) ;
}
}
static int F_280 ( struct V_611 * V_520 , int V_612 )
{
T_1 V_607 , V_613 ;
int V_614 = 0 ;
struct V_14 * V_15 = F_86 ( V_520 -> V_228 ) ;
F_237 ( F_278 , V_15 , 1 ) ;
V_607 = F_3 ( V_15 -> V_2 ,
F_279 ( V_15 -> V_17 ) ) ;
V_613 = V_607 & V_366 ;
V_613 |= V_15 -> V_615 ;
while ( V_613 && V_612 > 0 ) {
int V_441 ;
struct V_424 * V_352 ;
V_352 = F_211 ( V_15 , V_613 ) ;
if ( ! V_352 )
break;
V_441 = F_259 ( V_15 , V_612 , V_352 ) ;
V_614 += V_441 ;
V_612 -= V_441 ;
if ( V_612 > 0 ) {
V_613 &= ~ ( 1 << V_352 -> V_616 ) ;
}
}
if ( V_612 > 0 ) {
V_613 = 0 ;
F_281 ( V_520 ) ;
F_149 ( V_15 ) ;
}
V_15 -> V_615 = V_613 ;
return V_614 ;
}
static void F_282 ( struct V_14 * V_15 )
{
F_165 ( V_15 ) ;
F_203 ( V_15 ) ;
F_283 ( & V_15 -> V_520 ) ;
F_149 ( V_15 ) ;
F_160 ( V_15 ) ;
F_284 ( V_15 -> V_524 ) ;
F_285 ( V_15 -> V_228 ) ;
}
static void F_286 ( struct V_14 * V_15 )
{
F_173 ( V_15 ) ;
F_177 ( 10 ) ;
F_153 ( V_15 ) ;
F_287 ( & V_15 -> V_520 ) ;
F_288 ( V_15 -> V_228 ) ;
F_289 ( V_15 -> V_228 ) ;
F_175 ( V_15 ) ;
F_161 ( V_15 ) ;
F_290 ( V_15 -> V_524 ) ;
}
static inline int F_291 ( struct V_264 * V_228 , int V_358 )
{
if ( V_358 < 68 ) {
F_139 ( V_228 , L_21 ) ;
return - V_25 ;
}
if ( V_358 > 9676 ) {
F_292 ( V_228 , L_22 , V_358 ) ;
V_358 = 9676 ;
}
if ( ! F_102 ( F_147 ( V_358 ) , 8 ) ) {
F_292 ( V_228 , L_23 , V_358 ,
F_111 ( F_147 ( V_358 ) , 8 ) ) ;
V_358 = F_111 ( F_147 ( V_358 ) , 8 ) ;
}
return V_358 ;
}
static int F_293 ( struct V_264 * V_228 ,
struct V_617 * V_618 )
{
T_2 V_619 = V_618 -> V_620 ;
T_2 V_621 = V_618 -> V_622 ;
if ( V_618 -> V_620 == 0 || V_618 -> V_622 == 0 )
return - V_25 ;
if ( V_618 -> V_620 > V_623 )
V_619 = V_623 ;
else if ( ! F_102 ( V_618 -> V_620 , 16 ) )
V_619 = F_111 ( V_618 -> V_620 , 16 ) ;
if ( V_618 -> V_622 > V_624 )
V_621 = V_624 ;
else if ( ! F_102 ( V_618 -> V_622 , 32 ) )
V_621 = F_111 ( V_618 -> V_622 , 32 ) ;
if ( V_618 -> V_620 != V_619 ) {
F_292 ( V_228 , L_24 ,
V_618 -> V_620 , V_619 ) ;
V_618 -> V_620 = V_619 ;
}
if ( V_618 -> V_622 != V_621 ) {
F_292 ( V_228 , L_25 ,
V_618 -> V_622 , V_621 ) ;
V_618 -> V_622 = V_621 ;
}
return 0 ;
}
static void F_294 ( struct V_14 * V_15 , unsigned char * V_586 )
{
T_1 V_625 , V_626 , V_627 ;
V_625 = F_4 ( V_15 -> V_5 + V_379 ) ;
V_626 = F_4 ( V_15 -> V_2 -> V_628 + V_629 ) ;
V_627 = F_4 ( V_15 -> V_2 -> V_628 + V_630 ) ;
V_586 [ 0 ] = ( V_627 >> 24 ) & 0xFF ;
V_586 [ 1 ] = ( V_627 >> 16 ) & 0xFF ;
V_586 [ 2 ] = ( V_627 >> 8 ) & 0xFF ;
V_586 [ 3 ] = V_627 & 0xFF ;
V_586 [ 4 ] = V_626 & 0xFF ;
V_586 [ 5 ] = ( V_625 >> V_631 ) & 0xFF ;
}
static int F_295 ( struct V_14 * V_15 )
{
struct V_522 * V_524 ;
V_524 = F_296 ( V_15 -> V_228 , V_15 -> V_632 , F_243 , 0 ,
V_15 -> V_368 ) ;
if ( ! V_524 ) {
F_139 ( V_15 -> V_228 , L_26 ) ;
return - V_633 ;
}
V_524 -> V_634 &= V_635 ;
V_524 -> V_636 = V_524 -> V_634 ;
V_15 -> V_524 = V_524 ;
V_15 -> V_526 = 0 ;
V_15 -> V_527 = 0 ;
V_15 -> V_381 = 0 ;
return 0 ;
}
static void F_297 ( struct V_14 * V_15 )
{
F_298 ( V_15 -> V_524 ) ;
V_15 -> V_524 = NULL ;
}
static int F_299 ( struct V_264 * V_228 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
unsigned char V_637 [ V_107 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_227 ;
V_227 = F_82 ( V_15 -> V_2 , V_15 -> V_17 , V_637 , true ) ;
if ( V_227 ) {
F_139 ( V_228 , L_27 ) ;
return V_227 ;
}
V_227 = F_82 ( V_15 -> V_2 , V_15 -> V_17 ,
V_228 -> V_265 , true ) ;
if ( V_227 ) {
F_139 ( V_228 , L_28 ) ;
return V_227 ;
}
V_227 = F_89 ( V_15 -> V_2 , V_15 -> V_17 , V_269 ) ;
if ( V_227 ) {
F_139 ( V_228 , L_29 ) ;
return V_227 ;
}
V_227 = F_90 ( V_15 ) ;
if ( V_227 ) {
F_139 ( V_228 , L_30 ) ;
return V_227 ;
}
V_227 = F_239 ( V_15 ) ;
if ( V_227 ) {
F_139 ( V_15 -> V_228 , L_31 ) ;
return V_227 ;
}
V_227 = F_240 ( V_15 ) ;
if ( V_227 ) {
F_139 ( V_15 -> V_228 , L_32 ) ;
goto V_638;
}
V_227 = F_300 ( V_15 -> V_518 , F_241 , 0 , V_228 -> V_639 , V_15 ) ;
if ( V_227 ) {
F_139 ( V_15 -> V_228 , L_33 , V_15 -> V_518 ) ;
goto V_640;
}
F_288 ( V_15 -> V_228 ) ;
V_227 = F_295 ( V_15 ) ;
if ( V_227 < 0 )
goto V_641;
F_237 ( F_157 , V_15 , 1 ) ;
F_282 ( V_15 ) ;
return 0 ;
V_641:
F_301 ( V_15 -> V_518 , V_15 ) ;
V_640:
F_235 ( V_15 ) ;
V_638:
F_238 ( V_15 ) ;
return V_227 ;
}
static int F_302 ( struct V_264 * V_228 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
F_286 ( V_15 ) ;
F_297 ( V_15 ) ;
F_237 ( F_155 , V_15 , 1 ) ;
F_301 ( V_15 -> V_518 , V_15 ) ;
F_238 ( V_15 ) ;
F_235 ( V_15 ) ;
return 0 ;
}
static void F_303 ( struct V_264 * V_228 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_642 * V_643 ;
int V_17 = V_15 -> V_17 ;
bool V_644 = V_228 -> V_345 & V_645 ;
F_46 ( V_2 , V_17 , V_228 -> V_345 & V_646 ) ;
F_47 ( V_2 , V_17 , V_110 , V_644 ) ;
F_47 ( V_2 , V_17 , V_191 , V_644 ) ;
F_88 ( V_2 , V_17 ) ;
if ( V_644 && ! F_304 ( V_228 ) ) {
F_305 (ha, dev)
F_82 ( V_2 , V_17 , V_643 -> V_586 , true ) ;
}
}
static int F_306 ( struct V_264 * V_228 , void * V_588 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
const struct V_647 * V_586 = V_588 ;
int V_227 ;
if ( ! F_307 ( V_586 -> V_648 ) ) {
V_227 = - V_649 ;
goto error;
}
if ( ! F_308 ( V_228 ) ) {
V_227 = F_85 ( V_228 , V_586 -> V_648 ) ;
if ( ! V_227 )
return 0 ;
V_227 = F_85 ( V_228 , V_228 -> V_265 ) ;
if ( V_227 )
goto error;
}
F_286 ( V_15 ) ;
V_227 = F_85 ( V_228 , V_586 -> V_648 ) ;
if ( ! V_227 )
goto V_650;
V_227 = F_85 ( V_228 , V_228 -> V_265 ) ;
if ( V_227 )
goto error;
V_650:
F_282 ( V_15 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
return 0 ;
error:
F_139 ( V_228 , L_34 ) ;
return V_227 ;
}
static int F_309 ( struct V_264 * V_228 , int V_358 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
int V_227 ;
V_358 = F_291 ( V_228 , V_358 ) ;
if ( V_358 < 0 ) {
V_227 = V_358 ;
goto error;
}
if ( ! F_308 ( V_228 ) ) {
V_227 = F_146 ( V_228 , V_358 ) ;
if ( ! V_227 ) {
V_15 -> V_304 = F_147 ( V_358 ) ;
return 0 ;
}
V_227 = F_146 ( V_228 , V_228 -> V_358 ) ;
if ( V_227 )
goto error;
}
F_286 ( V_15 ) ;
V_227 = F_146 ( V_228 , V_358 ) ;
if ( ! V_227 ) {
V_15 -> V_304 = F_147 ( V_358 ) ;
goto V_650;
}
V_227 = F_146 ( V_228 , V_228 -> V_358 ) ;
if ( V_227 )
goto error;
V_650:
F_282 ( V_15 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
return 0 ;
error:
F_139 ( V_228 , L_35 ) ;
return V_227 ;
}
static struct V_651 *
F_310 ( struct V_264 * V_228 , struct V_651 * V_577 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
unsigned int V_97 ;
int V_361 ;
F_311 (cpu) {
struct V_579 * V_652 ;
T_8 V_581 ;
T_8 V_574 ;
T_8 V_600 ;
T_8 V_601 ;
V_652 = F_195 ( V_15 -> V_577 , V_361 ) ;
do {
V_97 = F_312 ( & V_652 -> V_580 ) ;
V_581 = V_652 -> V_581 ;
V_574 = V_652 -> V_574 ;
V_600 = V_652 -> V_600 ;
V_601 = V_652 -> V_601 ;
} while ( F_313 ( & V_652 -> V_580 , V_97 ) );
V_577 -> V_581 += V_581 ;
V_577 -> V_574 += V_574 ;
V_577 -> V_600 += V_600 ;
V_577 -> V_601 += V_601 ;
}
V_577 -> V_578 = V_228 -> V_577 . V_578 ;
V_577 -> V_653 = V_228 -> V_577 . V_653 ;
V_577 -> V_602 = V_228 -> V_577 . V_602 ;
return V_577 ;
}
static int F_314 ( struct V_264 * V_228 , struct V_654 * V_655 , int V_656 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
int V_657 ;
if ( ! V_15 -> V_524 )
return - V_658 ;
V_657 = F_315 ( V_15 -> V_524 , V_655 , V_656 ) ;
if ( ! V_657 )
F_243 ( V_228 ) ;
return V_657 ;
}
static int F_316 ( struct V_264 * V_228 ,
struct V_659 * V_656 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
if ( ! V_15 -> V_524 )
return - V_633 ;
return F_317 ( V_15 -> V_524 , V_656 ) ;
}
static int F_318 ( struct V_264 * V_228 ,
struct V_659 * V_656 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
if ( ! V_15 -> V_524 )
return - V_633 ;
return F_319 ( V_15 -> V_524 , V_656 ) ;
}
static int F_320 ( struct V_264 * V_228 ,
struct V_660 * V_661 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
int V_388 ;
for ( V_388 = 0 ; V_388 < V_354 ; V_388 ++ ) {
struct V_424 * V_352 = V_15 -> V_320 [ V_388 ] ;
V_352 -> V_477 = V_661 -> V_662 ;
V_352 -> V_475 = V_661 -> V_663 ;
F_205 ( V_15 , V_352 , V_352 -> V_475 ) ;
F_206 ( V_15 , V_352 , V_352 -> V_477 ) ;
}
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
struct V_409 * V_18 = V_15 -> V_410 [ V_388 ] ;
V_18 -> V_478 = V_661 -> V_664 ;
}
F_237 ( F_208 , V_15 , 1 ) ;
return 0 ;
}
static int F_321 ( struct V_264 * V_228 ,
struct V_660 * V_661 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
V_661 -> V_662 = V_15 -> V_320 [ 0 ] -> V_477 ;
V_661 -> V_663 = V_15 -> V_320 [ 0 ] -> V_475 ;
V_661 -> V_664 = V_15 -> V_410 [ 0 ] -> V_478 ;
return 0 ;
}
static void F_322 ( struct V_264 * V_228 ,
struct V_665 * V_666 )
{
F_323 ( V_666 -> V_667 , V_668 ,
sizeof( V_666 -> V_667 ) ) ;
F_323 ( V_666 -> V_669 , V_670 ,
sizeof( V_666 -> V_669 ) ) ;
F_323 ( V_666 -> V_671 , F_324 ( & V_228 -> V_228 ) ,
sizeof( V_666 -> V_671 ) ) ;
}
static void F_325 ( struct V_264 * V_228 ,
struct V_617 * V_618 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
V_618 -> V_672 = V_623 ;
V_618 -> V_673 = V_624 ;
V_618 -> V_620 = V_15 -> V_494 ;
V_618 -> V_622 = V_15 -> V_503 ;
}
static int F_326 ( struct V_264 * V_228 ,
struct V_617 * V_618 )
{
struct V_14 * V_15 = F_86 ( V_228 ) ;
T_2 V_674 = V_15 -> V_494 ;
T_2 V_675 = V_15 -> V_503 ;
int V_227 ;
V_227 = F_293 ( V_228 , V_618 ) ;
if ( V_227 )
return V_227 ;
if ( ! F_308 ( V_228 ) ) {
V_15 -> V_494 = V_618 -> V_620 ;
V_15 -> V_503 = V_618 -> V_622 ;
return 0 ;
}
F_286 ( V_15 ) ;
F_238 ( V_15 ) ;
F_235 ( V_15 ) ;
V_15 -> V_494 = V_618 -> V_620 ;
V_15 -> V_503 = V_618 -> V_622 ;
V_227 = F_239 ( V_15 ) ;
if ( V_227 ) {
V_15 -> V_494 = V_674 ;
V_618 -> V_620 = V_674 ;
V_227 = F_239 ( V_15 ) ;
if ( V_227 )
goto V_676;
}
V_227 = F_240 ( V_15 ) ;
if ( V_227 ) {
V_15 -> V_503 = V_675 ;
V_618 -> V_622 = V_675 ;
V_227 = F_240 ( V_15 ) ;
if ( V_227 )
goto V_677;
}
F_282 ( V_15 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
return 0 ;
V_677:
F_238 ( V_15 ) ;
V_676:
F_139 ( V_228 , L_36 ) ;
return V_227 ;
}
static void F_327 ( struct V_14 * V_15 )
{
F_158 ( V_15 ) ;
F_162 ( V_15 ) ;
F_159 ( V_15 ) ;
F_164 ( V_15 ) ;
}
static int F_328 ( struct V_14 * V_15 )
{
struct V_582 * V_228 = V_15 -> V_228 -> V_228 . V_328 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_6 * V_7 ;
int V_388 , V_361 , V_227 ;
if ( V_15 -> V_291 + V_354 > V_678 )
return - V_25 ;
F_175 ( V_15 ) ;
F_161 ( V_15 ) ;
V_15 -> V_410 = F_75 ( V_228 , V_408 , sizeof( * V_15 -> V_410 ) ,
V_94 ) ;
if ( ! V_15 -> V_410 )
return - V_143 ;
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
int V_679 = F_8 ( V_15 -> V_17 , V_388 ) ;
struct V_409 * V_18 ;
V_18 = F_329 ( V_228 , sizeof( * V_18 ) , V_94 ) ;
if ( ! V_18 )
return - V_143 ;
V_18 -> V_451 = F_330 ( struct V_6 ) ;
if ( ! V_18 -> V_451 ) {
V_227 = - V_143 ;
goto V_680;
}
V_18 -> V_17 = V_679 ;
V_18 -> V_487 = V_388 ;
V_18 -> V_478 = V_681 ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_451 , V_361 ) ;
V_7 -> V_361 = V_361 ;
}
V_15 -> V_410 [ V_388 ] = V_18 ;
}
V_15 -> V_320 = F_75 ( V_228 , V_354 , sizeof( * V_15 -> V_320 ) ,
V_94 ) ;
if ( ! V_15 -> V_320 ) {
V_227 = - V_143 ;
goto V_680;
}
for ( V_388 = 0 ; V_388 < V_354 ; V_388 ++ ) {
struct V_424 * V_352 ;
V_352 = F_329 ( V_228 , sizeof( * V_352 ) , V_94 ) ;
if ( ! V_352 )
goto V_680;
V_352 -> V_17 = V_15 -> V_291 + V_388 ;
V_352 -> V_15 = V_15 -> V_17 ;
V_352 -> V_616 = V_388 ;
V_15 -> V_320 [ V_388 ] = V_352 ;
}
F_1 ( V_2 , F_331 ( V_15 -> V_17 ) , V_354 ) ;
for ( V_388 = 0 ; V_388 < V_354 ; V_388 ++ ) {
struct V_424 * V_352 = V_15 -> V_320 [ V_388 ] ;
V_352 -> V_9 = V_15 -> V_494 ;
V_352 -> V_475 = V_682 ;
V_352 -> V_477 = V_683 ;
}
F_173 ( V_15 ) ;
F_166 ( V_15 ) ;
F_96 ( V_15 ) ;
F_94 ( V_15 ) ;
V_15 -> V_304 = F_147 ( V_15 -> V_228 -> V_358 ) ;
V_227 = F_144 ( V_15 ) ;
if ( V_227 )
goto V_680;
return 0 ;
V_680:
for ( V_388 = 0 ; V_388 < V_408 ; V_388 ++ ) {
if ( ! V_15 -> V_410 [ V_388 ] )
continue;
F_332 ( V_15 -> V_410 [ V_388 ] -> V_451 ) ;
}
return V_227 ;
}
static int F_333 ( struct V_225 * V_226 ,
struct V_684 * V_685 ,
struct V_1 * V_2 ,
int * V_686 )
{
struct V_684 * V_632 ;
struct V_14 * V_15 ;
struct V_264 * V_228 ;
struct V_687 * V_688 ;
const char * V_689 ;
const char * V_690 ;
char V_691 [ V_107 ] ;
T_1 V_17 ;
int V_692 ;
int V_693 ;
int V_694 = 2 ;
int V_227 , V_22 ;
V_228 = F_334 ( sizeof( struct V_14 ) , V_408 ,
V_354 ) ;
if ( ! V_228 )
return - V_143 ;
V_632 = F_335 ( V_685 , L_37 , 0 ) ;
if ( ! V_632 ) {
F_104 ( & V_226 -> V_228 , L_38 ) ;
V_227 = - V_633 ;
goto V_695;
}
V_693 = F_336 ( V_685 ) ;
if ( V_693 < 0 ) {
F_104 ( & V_226 -> V_228 , L_39 ) ;
V_227 = V_693 ;
goto V_695;
}
if ( F_337 ( V_685 , L_40 , & V_17 ) ) {
V_227 = - V_25 ;
F_104 ( & V_226 -> V_228 , L_41 ) ;
goto V_695;
}
V_228 -> V_696 = V_624 ;
V_228 -> V_697 = 5 * V_698 ;
V_228 -> V_699 = & V_700 ;
V_228 -> V_701 = & V_702 ;
V_15 = F_86 ( V_228 ) ;
V_15 -> V_518 = F_338 ( V_685 , 0 ) ;
if ( V_15 -> V_518 <= 0 ) {
V_227 = - V_25 ;
goto V_695;
}
if ( F_339 ( V_685 , L_42 ) )
V_15 -> V_345 |= V_390 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_291 = * V_686 ;
V_15 -> V_632 = V_632 ;
V_15 -> V_368 = V_693 ;
V_688 = F_340 ( V_226 , V_703 ,
V_694 + V_17 ) ;
V_15 -> V_5 = F_341 ( & V_226 -> V_228 , V_688 ) ;
if ( F_342 ( V_15 -> V_5 ) ) {
V_227 = F_343 ( V_15 -> V_5 ) ;
goto V_641;
}
V_15 -> V_577 = F_344 ( struct V_579 ) ;
if ( ! V_15 -> V_577 ) {
V_227 = - V_143 ;
goto V_641;
}
V_689 = F_345 ( V_685 ) ;
if ( V_689 && F_307 ( V_689 ) ) {
V_690 = L_43 ;
F_87 ( V_228 -> V_265 , V_689 ) ;
} else {
F_294 ( V_15 , V_691 ) ;
if ( F_307 ( V_691 ) ) {
V_690 = L_44 ;
F_87 ( V_228 -> V_265 , V_691 ) ;
} else {
V_690 = L_45 ;
F_346 ( V_228 ) ;
}
}
V_15 -> V_503 = V_624 ;
V_15 -> V_494 = V_623 ;
V_15 -> V_228 = V_228 ;
F_347 ( V_228 , & V_226 -> V_228 ) ;
V_227 = F_328 ( V_15 ) ;
if ( V_227 < 0 ) {
F_104 ( & V_226 -> V_228 , L_46 , V_17 ) ;
goto V_704;
}
F_327 ( V_15 ) ;
F_348 ( V_228 , & V_15 -> V_520 , F_280 , V_705 ) ;
V_692 = V_706 | V_707 ;
V_228 -> V_692 = V_692 | V_708 ;
V_228 -> V_709 |= V_692 | V_708 | V_710 ;
V_228 -> V_711 |= V_692 ;
V_227 = F_349 ( V_228 ) ;
if ( V_227 < 0 ) {
F_104 ( & V_226 -> V_228 , L_47 ) ;
goto V_712;
}
F_292 ( V_228 , L_48 , V_690 , V_228 -> V_265 ) ;
* V_686 += V_354 ;
V_2 -> V_713 [ V_17 ] = V_15 ;
return 0 ;
V_712:
for ( V_22 = 0 ; V_22 < V_408 ; V_22 ++ )
F_332 ( V_15 -> V_410 [ V_22 ] -> V_451 ) ;
V_704:
F_332 ( V_15 -> V_577 ) ;
V_641:
F_350 ( V_15 -> V_518 ) ;
V_695:
F_351 ( V_228 ) ;
return V_227 ;
}
static void F_352 ( struct V_14 * V_15 )
{
int V_22 ;
F_353 ( V_15 -> V_228 ) ;
F_332 ( V_15 -> V_577 ) ;
for ( V_22 = 0 ; V_22 < V_408 ; V_22 ++ )
F_332 ( V_15 -> V_410 [ V_22 ] -> V_451 ) ;
F_350 ( V_15 -> V_518 ) ;
F_351 ( V_15 -> V_228 ) ;
}
static void F_354 ( const struct V_714 * V_715 ,
struct V_1 * V_2 )
{
T_1 V_716 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 6 ; V_22 ++ ) {
F_1 ( V_2 , F_355 ( V_22 ) , 0 ) ;
F_1 ( V_2 , F_356 ( V_22 ) , 0 ) ;
if ( V_22 < 4 )
F_1 ( V_2 , F_357 ( V_22 ) , 0 ) ;
}
V_716 = 0 ;
for ( V_22 = 0 ; V_22 < V_715 -> V_717 ; V_22 ++ ) {
const struct V_718 * V_719 = V_715 -> V_719 + V_22 ;
F_1 ( V_2 , F_355 ( V_22 ) ,
( V_719 -> V_5 & 0xffff0000 ) | ( V_719 -> V_720 << 8 ) |
V_715 -> V_721 ) ;
F_1 ( V_2 , F_356 ( V_22 ) ,
( V_719 -> V_9 - 1 ) & 0xffff0000 ) ;
V_716 |= ( 1 << V_22 ) ;
}
F_1 ( V_2 , V_722 , V_716 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_184 ; V_15 ++ ) {
F_1 ( V_2 , F_359 ( V_15 ) ,
V_723 ) ;
F_1 ( V_2 , F_360 ( V_15 ) ,
V_724 ) ;
}
F_1 ( V_2 , V_725 ,
V_726 ) ;
F_1 ( V_2 , V_727 , 0x1 ) ;
}
static int F_361 ( struct V_225 * V_226 , struct V_1 * V_2 )
{
const struct V_714 * V_728 ;
int V_227 , V_22 ;
T_1 V_60 ;
if ( V_354 % 4 || ( V_354 > V_729 ) ||
( V_408 > V_19 ) ) {
F_104 ( & V_226 -> V_228 , L_49 ) ;
return - V_25 ;
}
V_728 = F_362 () ;
if ( V_728 )
F_354 ( V_728 , V_2 ) ;
V_60 = F_4 ( V_2 -> V_628 + V_730 ) ;
V_60 |= V_731 ;
F_2 ( V_60 , V_2 -> V_628 + V_730 ) ;
V_2 -> V_596 = F_75 ( & V_226 -> V_228 , F_197 () ,
sizeof( struct V_409 ) ,
V_94 ) ;
if ( ! V_2 -> V_596 )
return - V_143 ;
F_150 (i) {
V_2 -> V_596 [ V_22 ] . V_17 = V_22 ;
V_2 -> V_596 [ V_22 ] . V_9 = V_732 ;
V_227 = F_218 ( V_226 , & V_2 -> V_596 [ V_22 ] ,
V_732 , V_22 , V_2 ) ;
if ( V_227 < 0 )
return V_227 ;
}
F_358 ( V_2 ) ;
for ( V_22 = 0 ; V_22 < V_184 ; V_22 ++ )
F_1 ( V_2 , F_331 ( V_22 ) , V_354 ) ;
F_2 ( V_733 ,
V_2 -> V_628 + V_734 ) ;
F_1 ( V_2 , V_735 , 0x1 ) ;
V_227 = F_119 ( V_226 , V_2 ) ;
if ( V_227 < 0 )
return V_227 ;
V_227 = F_79 ( V_226 , V_2 ) ;
if ( V_227 < 0 )
return V_227 ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_363 ( struct V_225 * V_226 )
{
struct V_684 * V_736 = V_226 -> V_228 . V_737 ;
struct V_684 * V_685 ;
struct V_1 * V_2 ;
struct V_687 * V_688 ;
int V_738 , V_291 ;
int V_227 ;
V_2 = F_329 ( & V_226 -> V_228 , sizeof( struct V_1 ) , V_94 ) ;
if ( ! V_2 )
return - V_143 ;
V_688 = F_340 ( V_226 , V_703 , 0 ) ;
V_2 -> V_5 = F_341 ( & V_226 -> V_228 , V_688 ) ;
if ( F_342 ( V_2 -> V_5 ) )
return F_343 ( V_2 -> V_5 ) ;
V_688 = F_340 ( V_226 , V_703 , 1 ) ;
V_2 -> V_628 = F_341 ( & V_226 -> V_228 , V_688 ) ;
if ( F_342 ( V_2 -> V_628 ) )
return F_343 ( V_2 -> V_628 ) ;
V_2 -> V_739 = F_364 ( & V_226 -> V_228 , L_50 ) ;
if ( F_342 ( V_2 -> V_739 ) )
return F_343 ( V_2 -> V_739 ) ;
V_227 = F_365 ( V_2 -> V_739 ) ;
if ( V_227 < 0 )
return V_227 ;
V_2 -> V_740 = F_364 ( & V_226 -> V_228 , L_51 ) ;
if ( F_342 ( V_2 -> V_740 ) ) {
V_227 = F_343 ( V_2 -> V_740 ) ;
goto V_741;
}
V_227 = F_365 ( V_2 -> V_740 ) ;
if ( V_227 < 0 )
goto V_741;
V_2 -> V_396 = F_366 ( V_2 -> V_739 ) ;
V_227 = F_361 ( V_226 , V_2 ) ;
if ( V_227 < 0 ) {
F_104 ( & V_226 -> V_228 , L_52 ) ;
goto V_742;
}
V_738 = F_367 ( V_736 ) ;
if ( V_738 == 0 ) {
F_104 ( & V_226 -> V_228 , L_53 ) ;
V_227 = - V_633 ;
goto V_742;
}
V_2 -> V_713 = F_75 ( & V_226 -> V_228 , V_738 ,
sizeof( struct V_14 * ) ,
V_94 ) ;
if ( ! V_2 -> V_713 ) {
V_227 = - V_143 ;
goto V_742;
}
V_291 = 0 ;
F_368 (dn, port_node) {
V_227 = F_333 ( V_226 , V_685 , V_2 , & V_291 ) ;
if ( V_227 < 0 )
goto V_742;
}
F_369 ( V_226 , V_2 ) ;
return 0 ;
V_742:
F_370 ( V_2 -> V_740 ) ;
V_741:
F_370 ( V_2 -> V_739 ) ;
return V_227 ;
}
static int F_371 ( struct V_225 * V_226 )
{
struct V_1 * V_2 = F_372 ( V_226 ) ;
struct V_684 * V_736 = V_226 -> V_228 . V_737 ;
struct V_684 * V_685 ;
int V_22 = 0 ;
F_368 (dn, port_node) {
if ( V_2 -> V_713 [ V_22 ] )
F_352 ( V_2 -> V_713 [ V_22 ] ) ;
V_22 ++ ;
}
for ( V_22 = 0 ; V_22 < V_314 ; V_22 ++ ) {
struct V_296 * V_297 = & V_2 -> V_315 [ V_22 ] ;
F_116 ( V_226 , V_2 , V_297 ) ;
}
F_150 (i) {
struct V_409 * V_440 = & V_2 -> V_596 [ V_22 ] ;
F_103 ( & V_226 -> V_228 ,
V_732 * V_491 ,
V_440 -> V_411 ,
V_440 -> V_492 ) ;
}
F_370 ( V_2 -> V_739 ) ;
F_370 ( V_2 -> V_740 ) ;
return 0 ;
}
