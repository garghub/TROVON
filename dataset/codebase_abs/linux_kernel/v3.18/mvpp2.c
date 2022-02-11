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
int V_143 = 0 ;
V_21 = F_50 ( V_2 , V_131 , V_132 ) ;
if ( ! V_21 ) {
V_93 = F_43 ( V_2 , V_134 ,
V_133 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - V_144 ;
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
V_145 )
break;
}
if ( V_93 <= V_142 ) {
V_143 = - V_25 ;
goto error;
}
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( V_21 , V_120 ) ;
V_21 -> V_23 = V_93 ;
F_29 ( V_21 , 0 , V_131 ) ;
F_37 ( V_21 , V_123 ) ;
F_38 ( V_21 , V_146 ,
V_108 ) ;
F_35 ( V_21 , 0 , V_119 ) ;
if ( V_132 == V_147 ) {
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
error:
F_42 ( V_21 ) ;
return V_143 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 1 ; V_22 < V_148 ; V_22 ++ ) {
if ( ! V_2 -> V_149 [ V_22 ] )
return V_22 ;
}
return - V_25 ;
}
static struct V_20 * F_54 ( struct V_1 * V_2 ,
unsigned short V_150 ,
unsigned short V_151 )
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
V_137 = F_25 ( V_21 , 0 , F_51 ( V_150 ) )
&& F_25 ( V_21 , 4 , F_51 ( V_151 ) ) ;
if ( ! V_137 )
continue;
V_40 = F_34 ( V_21 ) & V_122 ;
if ( V_40 == V_145 )
return V_21 ;
}
F_42 ( V_21 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , unsigned short V_150 ,
unsigned short V_151 ,
unsigned int V_141 )
{
struct V_20 * V_21 ;
int V_142 , V_93 , V_132 , V_143 = 0 ;
V_21 = F_54 ( V_2 , V_150 , V_151 ) ;
if ( ! V_21 ) {
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - V_144 ;
V_132 = F_53 ( V_2 ) ;
if ( V_132 < 0 ) {
V_143 = V_132 ;
goto error;
}
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
if ( V_93 >= V_142 ) {
V_143 = - V_152 ;
goto error;
}
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( V_21 , V_120 ) ;
V_21 -> V_23 = V_93 ;
V_2 -> V_149 [ V_132 ] = true ;
F_29 ( V_21 , 0 , V_150 ) ;
F_29 ( V_21 , 4 , V_151 ) ;
F_37 ( V_21 , V_120 ) ;
F_38 ( V_21 , 2 * V_146 ,
V_108 ) ;
F_33 ( V_21 , V_145 ,
V_122 ) ;
F_35 ( V_21 , V_132 | V_138 ,
V_119 ) ;
F_14 ( V_2 , V_21 -> V_23 , V_120 ) ;
}
F_19 ( V_21 , V_141 ) ;
F_9 ( V_2 , V_21 ) ;
error:
F_42 ( V_21 ) ;
return V_143 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned short V_153 ,
unsigned int V_39 , unsigned int V_40 )
{
struct V_20 V_21 ;
int V_93 ;
if ( ( V_153 != V_154 ) && ( V_153 != V_155 ) &&
( V_153 != V_156 ) )
return - V_25 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_157 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_157 ) ;
F_38 ( & V_21 , 12 , V_108 ) ;
F_39 ( & V_21 , V_158 ,
sizeof( struct V_159 ) - 4 ,
V_160 ) ;
F_35 ( & V_21 , V_161 ,
V_161 ) ;
F_33 ( & V_21 , V_39 | V_162 ,
V_40 | V_162 ) ;
F_21 ( & V_21 , 5 , V_153 , V_163 ) ;
F_26 ( & V_21 , 0 , V_161 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 . V_23 = V_93 ;
V_21 . V_34 . V_27 [ V_66 ] = 0x0 ;
V_21 . V_34 . V_27 [ V_164 ] = 0x0 ;
F_33 ( & V_21 , V_39 , V_40 ) ;
F_21 ( & V_21 , 2 , 0x00 , V_165 ) ;
F_21 ( & V_21 , 3 , 0x00 , V_163 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned short V_166 )
{
struct V_20 V_21 ;
int V_61 , V_93 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_157 ) ;
V_21 . V_23 = V_93 ;
switch ( V_166 ) {
case V_167 :
F_21 ( & V_21 , 0 , V_168 ,
V_169 ) ;
F_33 ( & V_21 , V_170 ,
V_171 ) ;
break;
case V_172 :
V_61 = V_173 ;
F_21 ( & V_21 , 0 , V_61 , V_61 ) ;
F_21 ( & V_21 , 1 , V_61 , V_61 ) ;
F_21 ( & V_21 , 2 , V_61 , V_61 ) ;
F_21 ( & V_21 , 3 , V_61 , V_61 ) ;
F_33 ( & V_21 , V_174 ,
V_171 ) ;
break;
default:
return - V_25 ;
}
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_26 ( & V_21 , V_161 ,
V_161 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned short V_153 ,
unsigned int V_39 , unsigned int V_40 )
{
struct V_20 V_21 ;
int V_93 ;
if ( ( V_153 != V_154 ) && ( V_153 != V_155 ) &&
( V_153 != V_175 ) && ( V_153 != V_176 ) )
return - V_25 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_177 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_39 , V_40 ) ;
F_39 ( & V_21 , V_158 ,
sizeof( struct V_178 ) - 6 ,
V_160 ) ;
F_21 ( & V_21 , 0 , V_153 , V_163 ) ;
F_26 ( & V_21 , V_179 ,
V_179 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_177 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned short V_166 )
{
struct V_20 V_21 ;
int V_93 ;
if ( V_166 != V_167 )
return - V_25 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_177 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_177 ) ;
F_33 ( & V_21 , V_170 ,
V_171 ) ;
F_35 ( & V_21 , V_179 ,
V_179 ) ;
F_38 ( & V_21 , - 18 , V_108 ) ;
F_21 ( & V_21 , 0 , V_180 ,
V_181 ) ;
F_26 ( & V_21 , 0 , V_179 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_177 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_15 , int V_182 ,
int V_183 , int V_3 )
{
T_1 V_60 ;
V_60 = F_3 ( V_2 , V_184 ) ;
V_60 &= ~ F_61 ( V_15 ) ;
V_60 |= F_62 ( V_15 , V_182 ) ;
F_1 ( V_2 , V_184 , V_60 ) ;
V_60 = F_3 ( V_2 , F_63 ( V_15 ) ) ;
V_60 &= ~ F_64 ( V_15 ) ;
V_60 |= F_65 ( V_15 , V_183 ) ;
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
for ( V_15 = 0 ; V_15 < V_185 ; V_15 ++ ) {
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_95 ) ;
V_21 . V_23 = V_186 - V_15 ;
F_19 ( & V_21 , 0 ) ;
F_35 ( & V_21 , V_15 , V_96 ) ;
F_30 ( & V_21 , V_187 , 1 ) ;
F_14 ( V_2 , V_21 . V_23 , V_95 ) ;
F_9 ( V_2 , & V_21 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 . V_23 = V_188 ;
F_16 ( & V_21 , V_189 ) ;
F_38 ( & V_21 , V_190 ,
V_108 ) ;
F_37 ( & V_21 , V_100 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_189 ) ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 . V_23 = V_191 ;
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
F_47 ( V_2 , V_192 , 0 , false ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
F_48 ( V_2 , 0 , false , V_193 ,
V_194 ) ;
F_48 ( V_2 , 0 , false , V_195 , V_194 ) ;
F_48 ( V_2 , 0 , false , V_193 ,
V_196 ) ;
F_48 ( V_2 , 0 , false , V_195 , V_196 ) ;
F_49 ( V_2 , 0 , false ,
V_193 , V_194 ) ;
F_49 ( V_2 , 0 , false ,
V_195 , V_194 ) ;
F_49 ( V_2 , 0 , true ,
V_193 , V_196 ) ;
F_49 ( V_2 , 0 , true ,
V_195 , V_196 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_104 ) ;
V_21 . V_23 = V_197 ;
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
F_29 ( & V_21 , 0 , V_198 ) ;
F_38 ( & V_21 , V_199 ,
V_108 ) ;
F_37 ( & V_21 , V_200 ) ;
F_33 ( & V_21 , V_201 ,
V_201 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = false ;
F_15 ( V_2 , V_21 . V_23 , V_201 ,
V_201 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_205 ) ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_206 ,
V_207 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = true ;
F_15 ( V_2 , V_21 . V_23 , V_206 ,
V_207 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_209 ) ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_210 |
V_211 ,
V_212 |
V_213 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = true ;
F_15 ( V_2 , V_21 . V_23 , V_210 |
V_211 ,
V_212 |
V_213 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_214 ) ;
F_21 ( & V_21 , V_130 ,
V_215 | V_216 ,
V_217 |
V_218 ) ;
F_37 ( & V_21 , V_157 ) ;
F_33 ( & V_21 , V_219 ,
V_207 ) ;
F_38 ( & V_21 , V_130 + 4 ,
V_108 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = false ;
F_15 ( V_2 , V_21 . V_23 , V_219 ,
V_207 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 . V_23 = V_93 ;
V_21 . V_26 . V_43 [ F_22 ( V_130 ) ] = 0x0 ;
V_21 . V_26 . V_43 [ F_23 ( V_130 ) ] = 0x0 ;
F_21 ( & V_21 , V_130 ,
V_215 ,
V_217 ) ;
V_21 . V_34 . V_27 [ V_66 ] = 0x0 ;
V_21 . V_34 . V_27 [ V_164 ] = 0x0 ;
F_33 ( & V_21 , V_220 ,
V_207 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = false ;
F_15 ( V_2 , V_21 . V_23 , V_220 ,
V_207 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_221 ) ;
F_38 ( & V_21 , V_130 + 8 +
V_222 ,
V_108 ) ;
F_37 ( & V_21 , V_177 ) ;
F_33 ( & V_21 , V_223 ,
V_207 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = false ;
F_15 ( V_2 , V_21 . V_23 , V_223 ,
V_207 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_123 ) ;
V_21 . V_23 = V_224 ;
F_19 ( & V_21 , V_49 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_37 ( & V_21 , V_95 ) ;
F_33 ( & V_21 , V_225 ,
V_207 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_123 ) ;
V_2 -> V_37 [ V_21 . V_23 ] . V_202 = V_203 ;
V_2 -> V_37 [ V_21 . V_23 ] . V_204 = true ;
F_15 ( V_2 , V_21 . V_23 , V_225 ,
V_207 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_74 ( struct V_226 * V_227 , struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_228 ;
V_2 -> V_149 = F_75 ( & V_227 -> V_229 , sizeof( bool ) ,
V_148 ,
V_94 ) ;
if ( ! V_2 -> V_149 )
return - V_144 ;
V_228 = F_55 ( V_2 , V_230 , V_231 ,
V_49 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_55 ( V_2 , V_230 , V_230 ,
V_49 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_52 ( V_2 , V_231 , V_147 ,
V_49 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_52 ( V_2 , V_230 , V_147 ,
V_49 ) ;
if ( V_228 )
return V_228 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_120 ) ;
V_21 . V_23 = V_232 ;
F_37 ( & V_21 , V_123 ) ;
F_35 ( & V_21 , 0 , V_119 ) ;
F_33 ( & V_21 , V_145 ,
V_122 ) ;
F_26 ( & V_21 , V_138 ,
V_138 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_120 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_120 ) ;
V_21 . V_23 = V_233 ;
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
F_16 ( & V_21 , V_200 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_234 ) ;
F_37 ( & V_21 , V_157 ) ;
F_33 ( & V_21 , V_220 ,
V_207 ) ;
F_38 ( & V_21 , V_130 + 4 ,
V_108 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_200 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
V_21 . V_23 = V_93 ;
F_21 ( & V_21 , V_130 ,
V_215 | V_216 ,
V_217 |
V_218 ) ;
V_21 . V_34 . V_27 [ V_66 ] = 0x0 ;
V_21 . V_34 . V_27 [ V_164 ] = 0x0 ;
F_33 ( & V_21 , V_219 ,
V_207 ) ;
F_14 ( V_2 , V_21 . V_23 , V_200 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_200 ) ;
V_21 . V_23 = V_93 ;
F_29 ( & V_21 , 0 , V_235 ) ;
F_37 ( & V_21 , V_177 ) ;
F_33 ( & V_21 , V_223 ,
V_207 ) ;
F_38 ( & V_21 , V_130 + 4 ,
V_108 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_200 ) ;
F_9 ( V_2 , & V_21 ) ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_200 ) ;
V_21 . V_23 = V_93 ;
F_33 ( & V_21 , V_225 ,
V_207 ) ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_39 ( & V_21 , V_208 ,
V_130 ,
V_160 ) ;
F_14 ( V_2 , V_21 . V_23 , V_200 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_228 ;
V_228 = F_56 ( V_2 , V_154 , V_236 ,
V_237 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_56 ( V_2 , V_155 , V_238 ,
V_237 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_56 ( V_2 , V_156 ,
V_210 |
V_211 ,
V_212 |
V_213 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_57 ( V_2 , V_172 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_57 ( V_2 , V_167 ) ;
if ( V_228 )
return V_228 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_157 ) ;
V_21 . V_23 = V_239 ;
F_37 ( & V_21 , V_157 ) ;
F_38 ( & V_21 , 12 , V_108 ) ;
F_39 ( & V_21 , V_158 ,
sizeof( struct V_159 ) - 4 ,
V_160 ) ;
F_35 ( & V_21 , V_161 ,
V_161 ) ;
F_33 ( & V_21 , V_240 ,
V_237 ) ;
F_26 ( & V_21 , 0 , V_161 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_157 ) ;
V_21 . V_23 = V_241 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_242 ,
V_171 ) ;
F_26 ( & V_21 , V_161 ,
V_161 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
int V_93 , V_228 ;
V_228 = F_58 ( V_2 , V_154 ,
V_236 ,
V_237 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_58 ( V_2 , V_155 ,
V_238 ,
V_237 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_58 ( V_2 , V_175 ,
V_210 |
V_211 ,
V_212 |
V_213 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_58 ( V_2 , V_176 ,
V_243 ,
V_244 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_59 ( V_2 , V_167 ) ;
if ( V_228 )
return V_228 ;
V_93 = F_43 ( V_2 , V_133 ,
V_134 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_177 ) ;
V_21 . V_23 = V_93 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_225 |
V_101 ,
V_207 |
V_101 ) ;
F_21 ( & V_21 , 1 , 0x00 , V_245 ) ;
F_26 ( & V_21 , V_179 ,
V_179 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_177 ) ;
V_21 . V_23 = V_246 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_240 ,
V_237 ) ;
F_39 ( & V_21 , V_158 ,
sizeof( struct V_178 ) - 4 ,
V_160 ) ;
F_26 ( & V_21 , V_179 ,
V_179 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_177 ) ;
V_21 . V_23 = V_247 ;
F_37 ( & V_21 , V_95 ) ;
F_30 ( & V_21 , V_102 , 1 ) ;
F_33 ( & V_21 , V_240 ,
V_237 ) ;
F_26 ( & V_21 , V_248 ,
V_248 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_157 ) ;
F_9 ( V_2 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
F_16 ( & V_21 , V_177 ) ;
V_21 . V_23 = V_249 ;
F_37 ( & V_21 , V_177 ) ;
F_33 ( & V_21 , V_242 ,
V_171 ) ;
F_35 ( & V_21 , V_179 ,
V_179 ) ;
F_38 ( & V_21 , - 18 , V_108 ) ;
F_26 ( & V_21 , 0 , V_179 ) ;
F_19 ( & V_21 , V_49 ) ;
F_14 ( V_2 , V_21 . V_23 , V_177 ) ;
F_9 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_79 ( struct V_226 * V_227 ,
struct V_1 * V_2 )
{
int V_228 , V_23 , V_22 ;
F_1 ( V_2 , V_250 , V_251 ) ;
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
V_2 -> V_37 = F_75 ( & V_227 -> V_229 , V_24 ,
sizeof( struct V_252 ) ,
V_94 ) ;
if ( ! V_2 -> V_37 )
return - V_144 ;
for ( V_23 = 0 ; V_23 < V_185 ; V_23 ++ )
F_60 ( V_2 , V_23 , V_189 ,
V_253 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
V_228 = F_73 ( V_2 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_74 ( V_227 , V_2 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_76 ( V_2 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_78 ( V_2 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_77 ( V_2 ) ;
if ( V_228 )
return V_228 ;
return 0 ;
}
static bool F_80 ( struct V_20 * V_21 ,
const T_3 * V_254 , unsigned char * V_61 )
{
unsigned char V_255 , V_256 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_107 ; V_23 ++ ) {
F_24 ( V_21 , V_23 , & V_255 , & V_256 ) ;
if ( V_256 != V_61 [ V_23 ] )
return false ;
if ( ( V_256 & V_255 ) != ( V_254 [ V_23 ] & V_61 [ V_23 ] ) )
return false ;
}
return true ;
}
static struct V_20 *
F_81 ( struct V_1 * V_2 , int V_257 , const T_3 * V_254 ,
unsigned char * V_61 , int V_258 )
{
struct V_20 * V_21 ;
int V_93 ;
V_21 = F_41 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return NULL ;
F_16 ( V_21 , V_100 ) ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ ) {
unsigned int V_259 ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
( V_2 -> V_37 [ V_93 ] . V_36 != V_100 ) ||
( V_2 -> V_37 [ V_93 ] . V_202 != V_258 ) )
continue;
V_21 -> V_23 = V_93 ;
F_12 ( V_2 , V_21 ) ;
V_259 = F_20 ( V_21 ) ;
if ( F_80 ( V_21 , V_254 , V_61 ) &&
V_259 == V_257 )
return V_21 ;
}
F_42 ( V_21 ) ;
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_15 ,
const T_3 * V_254 , bool V_45 )
{
struct V_20 * V_21 ;
unsigned int V_257 , V_260 , V_39 ;
unsigned char V_61 [ V_107 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_93 ;
V_21 = F_81 ( V_2 , ( 1 << V_15 ) , V_254 , V_61 ,
V_261 ) ;
if ( ! V_21 ) {
if ( ! V_45 )
return 0 ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ )
if ( V_2 -> V_37 [ V_93 ] . V_38 &&
( V_2 -> V_37 [ V_93 ] . V_36 == V_100 ) &&
( V_2 -> V_37 [ V_93 ] . V_202 ==
V_262 ) )
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
V_257 = F_20 ( V_21 ) ;
if ( V_257 == 0 ) {
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
V_260 = V_107 ;
while ( V_260 -- )
F_21 ( V_21 , V_260 , V_254 [ V_260 ] , 0xff ) ;
if ( F_83 ( V_254 ) )
V_39 = V_263 ;
else if ( F_84 ( V_254 ) )
V_39 = V_111 ;
else
V_39 = V_105 | V_264 ;
F_33 ( V_21 , V_39 , V_106 |
V_264 ) ;
F_15 ( V_2 , V_21 -> V_23 , V_39 , V_106 |
V_264 ) ;
F_38 ( V_21 , 2 * V_107 ,
V_108 ) ;
V_2 -> V_37 [ V_21 -> V_23 ] . V_202 = V_261 ;
F_14 ( V_2 , V_21 -> V_23 , V_100 ) ;
F_9 ( V_2 , V_21 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static int F_85 ( struct V_265 * V_229 , const T_3 * V_254 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
int V_228 ;
V_228 = F_82 ( V_15 -> V_2 , V_15 -> V_17 , V_229 -> V_266 ,
false ) ;
if ( V_228 )
return V_228 ;
V_228 = F_82 ( V_15 -> V_2 , V_15 -> V_17 , V_254 , true ) ;
if ( V_228 )
return V_228 ;
F_87 ( V_229 -> V_266 , V_254 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , int V_15 )
{
struct V_20 V_21 ;
int V_23 , V_93 ;
for ( V_93 = V_133 ;
V_93 <= V_134 ; V_93 ++ ) {
unsigned char V_254 [ V_107 ] , V_267 [ V_107 ] ;
if ( ! V_2 -> V_37 [ V_93 ] . V_38 ||
( V_2 -> V_37 [ V_93 ] . V_36 != V_100 ) ||
( V_2 -> V_37 [ V_93 ] . V_202 != V_261 ) )
continue;
V_21 . V_23 = V_93 ;
F_12 ( V_2 , & V_21 ) ;
for ( V_23 = 0 ; V_23 < V_107 ; V_23 ++ )
F_24 ( & V_21 , V_23 , & V_254 [ V_23 ] ,
& V_267 [ V_23 ] ) ;
if ( F_84 ( V_254 ) && ! F_83 ( V_254 ) )
F_82 ( V_2 , V_15 , V_254 , false ) ;
}
}
static int F_89 ( struct V_1 * V_2 , int V_15 , int type )
{
switch ( type ) {
case V_268 :
F_48 ( V_2 , V_15 , true ,
V_195 , V_194 ) ;
F_48 ( V_2 , V_15 , true ,
V_193 , V_194 ) ;
F_48 ( V_2 , V_15 , false ,
V_195 , V_196 ) ;
F_48 ( V_2 , V_15 , false ,
V_193 , V_196 ) ;
break;
case V_269 :
F_48 ( V_2 , V_15 , true ,
V_195 , V_196 ) ;
F_48 ( V_2 , V_15 , true ,
V_193 , V_196 ) ;
F_48 ( V_2 , V_15 , false ,
V_195 , V_194 ) ;
F_48 ( V_2 , V_15 , false ,
V_193 , V_194 ) ;
break;
case V_270 :
case V_271 :
F_48 ( V_2 , V_15 , false ,
V_195 , V_196 ) ;
F_48 ( V_2 , V_15 , false ,
V_193 , V_196 ) ;
F_48 ( V_2 , V_15 , false ,
V_195 , V_194 ) ;
F_48 ( V_2 , V_15 , false ,
V_193 , V_194 ) ;
break;
default:
if ( ( type < 0 ) || ( type > V_268 ) )
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
return - V_144 ;
F_16 ( V_21 , V_95 ) ;
V_21 -> V_23 = V_93 ;
F_35 ( V_21 , V_15 -> V_17 , V_96 ) ;
F_30 ( V_21 , V_187 , 1 ) ;
F_14 ( V_15 -> V_2 , V_21 -> V_23 , V_95 ) ;
}
F_19 ( V_21 , ( 1 << V_15 -> V_17 ) ) ;
F_9 ( V_15 -> V_2 , V_21 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
F_1 ( V_2 , V_274 , V_273 -> V_23 ) ;
F_1 ( V_2 , V_275 , V_273 -> V_4 [ 0 ] ) ;
F_1 ( V_2 , V_276 , V_273 -> V_4 [ 1 ] ) ;
F_1 ( V_2 , V_277 , V_273 -> V_4 [ 2 ] ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
T_1 V_60 ;
V_60 = ( V_279 -> V_280 << V_281 ) | V_279 -> V_282 ;
F_1 ( V_2 , V_283 , V_60 ) ;
F_1 ( V_2 , V_284 , V_279 -> V_4 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_278 V_279 ;
struct V_272 V_273 ;
int V_23 ;
F_1 ( V_2 , V_285 , V_286 ) ;
memset ( & V_273 . V_4 , 0 , V_287 ) ;
for ( V_23 = 0 ; V_23 < V_288 ; V_23 ++ ) {
V_273 . V_23 = V_23 ;
F_91 ( V_2 , & V_273 ) ;
}
V_279 . V_4 = 0 ;
for ( V_23 = 0 ; V_23 < V_289 ; V_23 ++ ) {
V_279 . V_282 = V_23 ;
V_279 . V_280 = 0 ;
F_92 ( V_2 , & V_279 ) ;
V_279 . V_280 = 1 ;
F_92 ( V_2 , & V_279 ) ;
}
}
static void F_94 ( struct V_14 * V_15 )
{
struct V_278 V_279 ;
T_1 V_60 ;
V_60 = F_3 ( V_15 -> V_2 , V_290 ) ;
V_60 &= ~ F_95 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_290 , V_60 ) ;
V_279 . V_282 = V_15 -> V_17 ;
V_279 . V_280 = 0 ;
V_279 . V_4 = 0 ;
V_279 . V_4 &= ~ V_291 ;
V_279 . V_4 |= V_15 -> V_292 ;
V_279 . V_4 &= ~ V_293 ;
F_92 ( V_15 -> V_2 , & V_279 ) ;
}
static void F_96 ( struct V_14 * V_15 )
{
T_1 V_60 ;
F_1 ( V_15 -> V_2 , F_97 ( V_15 -> V_17 ) ,
V_15 -> V_292 & V_294 ) ;
F_1 ( V_15 -> V_2 , F_98 ( V_15 -> V_17 ) ,
( V_15 -> V_292 >> V_295 ) ) ;
V_60 = F_3 ( V_15 -> V_2 , V_296 ) ;
V_60 |= F_99 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_296 , V_60 ) ;
}
static int F_100 ( struct V_226 * V_227 ,
struct V_1 * V_2 ,
struct V_297 * V_298 , int V_9 )
{
int V_299 ;
T_1 V_60 ;
V_299 = sizeof( T_1 ) * V_9 ;
V_298 -> V_300 = F_101 ( & V_227 -> V_229 , V_299 ,
& V_298 -> V_301 ,
V_94 ) ;
if ( ! V_298 -> V_300 )
return - V_144 ;
if ( ! F_102 ( ( T_1 ) V_298 -> V_300 , V_302 ) ) {
F_103 ( & V_227 -> V_229 , V_299 , V_298 -> V_300 ,
V_298 -> V_301 ) ;
F_104 ( & V_227 -> V_229 , L_1 ,
V_298 -> V_17 , V_302 ) ;
return - V_144 ;
}
F_1 ( V_2 , F_105 ( V_298 -> V_17 ) ,
V_298 -> V_301 ) ;
F_1 ( V_2 , F_106 ( V_298 -> V_17 ) , V_9 ) ;
V_60 = F_3 ( V_2 , F_107 ( V_298 -> V_17 ) ) ;
V_60 |= V_303 ;
F_1 ( V_2 , F_107 ( V_298 -> V_17 ) , V_60 ) ;
V_298 -> type = V_304 ;
V_298 -> V_9 = V_9 ;
V_298 -> V_305 = 0 ;
V_298 -> V_306 = 0 ;
F_108 ( & V_298 -> V_307 , 0 ) ;
F_109 ( & V_298 -> V_308 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_297 * V_298 ,
int V_309 )
{
T_1 V_60 ;
V_298 -> V_309 = V_309 ;
V_60 = F_111 ( V_309 , 1 << V_310 ) ;
F_1 ( V_2 , F_112 ( V_298 -> V_17 ) , V_60 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_297 * V_298 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_298 -> V_306 ; V_22 ++ ) {
T_1 V_311 ;
F_3 ( V_2 , F_114 ( V_298 -> V_17 ) ) ;
V_311 = F_3 ( V_2 , V_312 ) ;
if ( ! V_311 )
break;
F_115 ( (struct V_10 * ) V_311 ) ;
}
V_298 -> V_306 -= V_22 ;
}
static int F_116 ( struct V_226 * V_227 ,
struct V_1 * V_2 ,
struct V_297 * V_298 )
{
T_1 V_60 ;
F_113 ( V_2 , V_298 ) ;
if ( V_298 -> V_306 ) {
F_117 ( 1 , L_2 , V_298 -> V_17 ) ;
return 0 ;
}
V_60 = F_3 ( V_2 , F_107 ( V_298 -> V_17 ) ) ;
V_60 |= V_313 ;
F_1 ( V_2 , F_107 ( V_298 -> V_17 ) , V_60 ) ;
F_103 ( & V_227 -> V_229 , sizeof( T_1 ) * V_298 -> V_9 ,
V_298 -> V_300 ,
V_298 -> V_301 ) ;
return 0 ;
}
static int F_118 ( struct V_226 * V_227 ,
struct V_1 * V_2 )
{
int V_22 , V_228 , V_9 ;
struct V_297 * V_298 ;
V_9 = V_314 ;
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
V_298 = & V_2 -> V_316 [ V_22 ] ;
V_298 -> V_17 = V_22 ;
V_228 = F_100 ( V_227 , V_2 , V_298 , V_9 ) ;
if ( V_228 )
goto V_317;
F_110 ( V_2 , V_298 , 0 ) ;
}
return 0 ;
V_317:
F_104 ( & V_227 -> V_229 , L_3 , V_22 , V_9 ) ;
for ( V_22 = V_22 - 1 ; V_22 >= 0 ; V_22 -- )
F_116 ( V_227 , V_2 , & V_2 -> V_316 [ V_22 ] ) ;
return V_228 ;
}
static int F_119 ( struct V_226 * V_227 , struct V_1 * V_2 )
{
int V_22 , V_228 ;
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
F_1 ( V_2 , F_120 ( V_22 ) , 0 ) ;
F_1 ( V_2 , F_121 ( V_22 ) , 0 ) ;
}
V_2 -> V_316 = F_75 ( & V_227 -> V_229 , V_315 ,
sizeof( struct V_297 ) , V_94 ) ;
if ( ! V_2 -> V_316 )
return - V_144 ;
V_228 = F_118 ( V_227 , V_2 ) ;
if ( V_228 < 0 )
return V_228 ;
return 0 ;
}
static void F_122 ( struct V_14 * V_15 ,
int V_318 , int V_319 )
{
T_1 V_60 ;
int V_320 ;
V_320 = V_15 -> V_321 [ V_318 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_320 ) ) ;
V_60 &= ~ V_322 ;
V_60 |= ( ( V_319 << V_323 ) &
V_322 ) ;
F_1 ( V_15 -> V_2 , F_123 ( V_320 ) , V_60 ) ;
}
static void F_124 ( struct V_14 * V_15 ,
int V_318 , int V_324 )
{
T_1 V_60 ;
int V_320 ;
V_320 = V_15 -> V_321 [ V_318 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_320 ) ) ;
V_60 &= ~ V_325 ;
V_60 |= ( ( V_324 << V_326 ) &
V_325 ) ;
F_1 ( V_15 -> V_2 , F_123 ( V_320 ) , V_60 ) ;
}
static struct V_10 * F_125 ( struct V_14 * V_15 ,
struct V_297 * V_298 ,
T_4 * V_327 ,
T_5 V_328 )
{
struct V_10 * V_11 ;
T_4 V_301 ;
V_11 = F_126 ( V_298 -> V_305 , V_328 ) ;
if ( ! V_11 )
return NULL ;
V_301 = F_127 ( V_15 -> V_229 -> V_229 . V_329 , V_11 -> V_330 ,
F_128 ( V_298 -> V_305 ) ,
V_331 ) ;
if ( F_129 ( F_130 ( V_15 -> V_229 -> V_229 . V_329 , V_301 ) ) ) {
F_115 ( V_11 ) ;
return NULL ;
}
* V_327 = V_301 ;
return V_11 ;
}
static inline T_1 F_131 ( T_1 V_332 , int V_333 )
{
T_1 V_334 ;
V_334 = V_332 & ~ ( 0xFF << V_335 ) ;
V_334 |= ( ( V_333 & 0xFF ) << V_335 ) ;
return V_334 ;
}
static inline int F_132 ( T_1 V_332 )
{
return ( V_332 >> V_335 ) & 0xFF ;
}
static inline void F_133 ( struct V_14 * V_15 , int V_333 ,
T_1 V_327 , T_1 V_336 )
{
F_1 ( V_15 -> V_2 , V_337 , V_336 ) ;
F_1 ( V_15 -> V_2 , F_134 ( V_333 ) , V_327 ) ;
}
static void F_135 ( struct V_14 * V_15 , int V_333 ,
T_1 V_327 , T_1 V_336 ,
int V_338 )
{
T_1 V_60 = 0 ;
V_60 |= ( V_338 & V_339 ) ;
F_1 ( V_15 -> V_2 , V_340 , V_60 ) ;
F_133 ( V_15 , V_333 ,
V_327 | V_341 ,
V_336 ) ;
}
static void F_136 ( struct V_14 * V_15 , T_1 V_334 ,
T_1 V_301 , T_1 V_332 )
{
int V_333 = F_132 ( V_334 ) ;
F_133 ( V_15 , V_333 , V_301 , V_332 ) ;
}
static int F_137 ( struct V_14 * V_15 ,
struct V_297 * V_298 , int V_306 )
{
struct V_10 * V_11 ;
int V_22 , V_309 , V_342 ;
T_1 V_334 ;
T_4 V_301 ;
V_309 = F_128 ( V_298 -> V_305 ) ;
V_342 = F_138 ( V_309 ) ;
if ( V_306 < 0 ||
( V_306 + V_298 -> V_306 > V_298 -> V_9 ) ) {
F_139 ( V_15 -> V_229 ,
L_4 ,
V_306 , V_298 -> V_17 ) ;
return 0 ;
}
V_334 = F_131 ( 0 , V_298 -> V_17 ) ;
for ( V_22 = 0 ; V_22 < V_306 ; V_22 ++ ) {
V_11 = F_125 ( V_15 , V_298 , & V_301 , V_94 ) ;
if ( ! V_11 )
break;
F_136 ( V_15 , V_334 , ( T_1 ) V_301 , ( T_1 ) V_11 ) ;
}
V_298 -> V_306 += V_22 ;
V_298 -> V_343 = V_298 -> V_306 / 4 ;
F_140 ( V_15 -> V_229 ,
L_5 ,
V_298 -> type == V_344 ? L_6 : L_7 ,
V_298 -> V_17 , V_298 -> V_305 , V_309 , V_342 ) ;
F_140 ( V_15 -> V_229 ,
L_8 ,
V_298 -> type == V_344 ? L_6 : L_7 ,
V_298 -> V_17 , V_22 , V_306 ) ;
return V_22 ;
}
static struct V_297 *
F_141 ( struct V_14 * V_15 , int V_333 , enum V_345 type ,
int V_305 )
{
unsigned long V_346 = 0 ;
struct V_297 * V_347 = & V_15 -> V_2 -> V_316 [ V_333 ] ;
int V_348 ;
if ( V_347 -> type != V_304 && V_347 -> type != type ) {
F_139 ( V_15 -> V_229 , L_9 ) ;
return NULL ;
}
F_142 ( & V_347 -> V_308 , V_346 ) ;
if ( V_347 -> type == V_304 )
V_347 -> type = type ;
if ( ( ( type == V_349 ) && ( V_305 > V_347 -> V_305 ) ) ||
( V_347 -> V_305 == 0 ) ) {
int V_350 ;
V_350 = V_347 -> V_306 ;
if ( V_350 == 0 )
V_350 = type == V_349 ?
V_351 :
V_352 ;
else
F_113 ( V_15 -> V_2 , V_347 ) ;
V_347 -> V_305 = V_305 ;
V_348 = F_137 ( V_15 , V_347 , V_350 ) ;
if ( V_348 != V_350 ) {
F_117 ( 1 , L_10 ,
V_347 -> V_17 , V_348 , V_350 ) ;
F_143 ( & V_347 -> V_308 , V_346 ) ;
return NULL ;
}
}
F_110 ( V_15 -> V_2 , V_347 ,
F_128 ( V_347 -> V_305 ) ) ;
F_143 ( & V_347 -> V_308 , V_346 ) ;
return V_347 ;
}
static int F_144 ( struct V_14 * V_15 )
{
unsigned long V_346 = 0 ;
int V_353 ;
if ( ! V_15 -> V_354 ) {
V_15 -> V_354 =
F_141 ( V_15 , F_145 ( V_15 -> V_17 ) ,
V_349 ,
V_15 -> V_305 ) ;
if ( ! V_15 -> V_354 )
return - V_144 ;
F_142 ( & V_15 -> V_354 -> V_308 , V_346 ) ;
V_15 -> V_354 -> V_141 |= ( 1 << V_15 -> V_17 ) ;
F_143 ( & V_15 -> V_354 -> V_308 , V_346 ) ;
for ( V_353 = 0 ; V_353 < V_355 ; V_353 ++ )
F_122 ( V_15 , V_353 , V_15 -> V_354 -> V_17 ) ;
}
if ( ! V_15 -> V_356 ) {
V_15 -> V_356 =
F_141 ( V_15 , V_357 ,
V_344 ,
V_358 ) ;
if ( ! V_15 -> V_356 )
return - V_144 ;
F_142 ( & V_15 -> V_356 -> V_308 , V_346 ) ;
V_15 -> V_356 -> V_141 |= ( 1 << V_15 -> V_17 ) ;
F_143 ( & V_15 -> V_356 -> V_308 , V_346 ) ;
for ( V_353 = 0 ; V_353 < V_355 ; V_353 ++ )
F_124 ( V_15 , V_353 ,
V_15 -> V_356 -> V_17 ) ;
}
return 0 ;
}
static int F_146 ( struct V_265 * V_229 , int V_359 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
struct V_297 * V_360 = V_15 -> V_354 ;
int V_348 , V_350 = V_360 -> V_306 ;
int V_305 = F_147 ( V_359 ) ;
F_113 ( V_15 -> V_2 , V_360 ) ;
if ( V_360 -> V_306 ) {
F_117 ( 1 , L_2 , V_360 -> V_17 ) ;
return - V_361 ;
}
V_360 -> V_305 = V_305 ;
V_348 = F_137 ( V_15 , V_360 , V_350 ) ;
if ( V_348 != V_350 ) {
F_117 ( 1 , L_10 ,
V_360 -> V_17 , V_348 , V_350 ) ;
return - V_361 ;
}
F_110 ( V_15 -> V_2 , V_360 ,
F_128 ( V_360 -> V_305 ) ) ;
V_229 -> V_359 = V_359 ;
F_148 ( V_229 ) ;
return 0 ;
}
static inline void F_149 ( struct V_14 * V_15 )
{
int V_362 , V_363 = 0 ;
F_150 (cpu)
V_363 |= 1 << V_362 ;
F_1 ( V_15 -> V_2 , F_151 ( V_15 -> V_17 ) ,
F_152 ( V_363 ) ) ;
}
static inline void F_153 ( struct V_14 * V_15 )
{
int V_362 , V_363 = 0 ;
F_150 (cpu)
V_363 |= 1 << V_362 ;
F_1 ( V_15 -> V_2 , F_151 ( V_15 -> V_17 ) ,
F_154 ( V_363 ) ) ;
}
static void F_155 ( void * V_364 )
{
struct V_14 * V_15 = V_364 ;
F_1 ( V_15 -> V_2 , F_156 ( V_15 -> V_17 ) , 0 ) ;
}
static void F_157 ( void * V_364 )
{
struct V_14 * V_15 = V_364 ;
F_1 ( V_15 -> V_2 , F_156 ( V_15 -> V_17 ) ,
( V_365 |
V_366 |
V_367 ) ) ;
}
static void F_158 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_368 ) ;
switch ( V_15 -> V_369 ) {
case V_370 :
V_60 |= V_371 ;
break;
case V_372 :
V_60 |= V_373 ;
default:
V_60 &= ~ V_374 ;
}
F_2 ( V_60 , V_15 -> V_5 + V_368 ) ;
}
static void F_159 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_375 ) ;
V_60 |= V_376 ;
F_2 ( V_60 , V_15 -> V_5 + V_375 ) ;
}
static void F_160 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_377 ) ;
V_60 |= V_378 ;
V_60 |= V_379 ;
F_2 ( V_60 , V_15 -> V_5 + V_377 ) ;
}
static void F_161 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_377 ) ;
V_60 &= ~ ( V_378 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_377 ) ;
}
static void F_162 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_380 ) &
~ V_381 ;
F_2 ( V_60 , V_15 -> V_5 + V_380 ) ;
}
static void F_163 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_380 ) ;
if ( V_15 -> V_382 == 1000 )
V_60 |= V_383 ;
else
V_60 &= ~ V_383 ;
if ( V_15 -> V_369 == V_370 )
V_60 |= V_384 ;
else
V_60 &= ~ V_384 ;
F_2 ( V_60 , V_15 -> V_5 + V_380 ) ;
}
static void F_164 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_368 ) &
~ V_385 ;
F_2 ( V_60 , V_15 -> V_5 + V_368 ) ;
while ( F_4 ( V_15 -> V_5 + V_368 ) &
V_385 )
continue;
}
static inline void F_165 ( struct V_14 * V_15 )
{
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_377 ) ;
V_60 &= ~ V_386 ;
V_60 |= ( ( ( V_15 -> V_305 - V_190 ) / 2 ) <<
V_387 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_377 ) ;
}
static void F_166 ( struct V_14 * V_15 )
{
int V_388 , V_60 , V_389 , V_390 , V_318 ;
if ( V_15 -> V_346 & V_391 )
F_163 ( V_15 ) ;
V_60 = F_4 ( V_15 -> V_5 + V_392 ) ;
V_60 &= ~ V_393 ;
V_60 |= F_167 ( 64 - 4 - 2 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_392 ) ;
V_388 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_394 ,
V_388 ) ;
F_1 ( V_15 -> V_2 , V_395 , 0 ) ;
for ( V_389 = 0 ; V_389 < V_19 ; V_389 ++ ) {
V_390 = F_8 ( V_15 -> V_17 , V_389 ) ;
F_1 ( V_15 -> V_2 ,
F_168 ( V_390 ) , 0 ) ;
}
F_1 ( V_15 -> V_2 , V_396 ,
V_15 -> V_2 -> V_397 / V_398 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_399 ) ;
V_60 &= ~ V_400 ;
V_60 |= F_169 ( 1 ) ;
V_60 |= V_401 ;
F_1 ( V_15 -> V_2 , V_399 , V_60 ) ;
V_60 = V_402 ;
F_1 ( V_15 -> V_2 , V_403 , V_60 ) ;
F_1 ( V_15 -> V_2 , F_170 ( V_15 -> V_17 ) ,
V_404 |
F_171 ( 256 ) ) ;
for ( V_318 = 0 ; V_318 < V_355 ; V_318 ++ ) {
V_389 = V_15 -> V_321 [ V_318 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_389 ) ) ;
V_60 |= V_405 |
V_406 ;
F_1 ( V_15 -> V_2 , F_123 ( V_389 ) , V_60 ) ;
}
F_153 ( V_15 ) ;
}
static void F_172 ( struct V_14 * V_15 )
{
T_1 V_60 ;
int V_318 , V_389 ;
for ( V_318 = 0 ; V_318 < V_355 ; V_318 ++ ) {
V_389 = V_15 -> V_321 [ V_318 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_389 ) ) ;
V_60 &= ~ V_407 ;
F_1 ( V_15 -> V_2 , F_123 ( V_389 ) , V_60 ) ;
}
}
static void F_173 ( struct V_14 * V_15 )
{
T_1 V_60 ;
int V_318 , V_389 ;
for ( V_318 = 0 ; V_318 < V_355 ; V_318 ++ ) {
V_389 = V_15 -> V_321 [ V_318 ] -> V_17 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_389 ) ) ;
V_60 |= V_407 ;
F_1 ( V_15 -> V_2 , F_123 ( V_389 ) , V_60 ) ;
}
}
static void F_174 ( struct V_14 * V_15 )
{
T_1 V_408 ;
int V_389 ;
int V_388 = F_7 ( V_15 ) ;
V_408 = 0 ;
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
struct V_410 * V_18 = V_15 -> V_411 [ V_389 ] ;
if ( V_18 -> V_412 != NULL )
V_408 |= ( 1 << V_389 ) ;
}
F_1 ( V_15 -> V_2 , V_394 , V_388 ) ;
F_1 ( V_15 -> V_2 , V_413 , V_408 ) ;
}
static void F_175 ( struct V_14 * V_15 )
{
T_1 V_414 ;
int V_415 ;
int V_388 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_394 , V_388 ) ;
V_414 = ( F_3 ( V_15 -> V_2 , V_413 ) ) &
V_416 ;
if ( V_414 != 0 )
F_1 ( V_15 -> V_2 , V_413 ,
( V_414 << V_417 ) ) ;
V_415 = 0 ;
do {
if ( V_415 >= V_418 ) {
F_176 ( V_15 -> V_229 ,
L_11 ,
V_414 ) ;
break;
}
F_177 ( 1 ) ;
V_415 ++ ;
V_414 = F_3 ( V_15 -> V_2 , V_413 ) ;
} while ( V_414 & V_416 );
}
static inline int
F_178 ( struct V_14 * V_15 , int V_419 )
{
T_1 V_60 = F_3 ( V_15 -> V_2 , F_179 ( V_419 ) ) ;
return V_60 & V_420 ;
}
static inline void
F_180 ( struct V_14 * V_15 , int V_419 ,
int V_421 , int V_422 )
{
T_1 V_60 = V_421 | ( V_422 << V_423 ) ;
F_1 ( V_15 -> V_2 , F_181 ( V_419 ) , V_60 ) ;
}
static inline struct V_424 *
F_182 ( struct V_425 * V_353 )
{
int V_426 = V_353 -> V_427 ;
V_353 -> V_427 = F_183 ( V_353 , V_426 ) ;
F_184 ( V_353 -> V_412 + V_353 -> V_427 ) ;
return V_353 -> V_412 + V_426 ;
}
static void F_185 ( struct V_14 * V_15 ,
int V_320 , int V_3 )
{
T_1 V_60 ;
V_3 = V_3 >> 5 ;
V_60 = F_3 ( V_15 -> V_2 , F_123 ( V_320 ) ) ;
V_60 &= ~ V_428 ;
V_60 |= ( ( V_3 << V_429 ) &
V_428 ) ;
F_1 ( V_15 -> V_2 , F_123 ( V_320 ) , V_60 ) ;
}
static T_1 F_186 ( struct V_424 * V_426 )
{
int V_333 = ( V_426 -> V_430 & V_431 ) >>
V_432 ;
int V_362 = F_187 () ;
return ( ( V_333 & 0xFF ) << V_335 ) |
( ( V_362 & 0xFF ) << V_433 ) ;
}
static int F_188 ( struct V_14 * V_15 ,
struct V_410 * V_18 )
{
T_1 V_60 ;
F_1 ( V_15 -> V_2 , V_434 , V_18 -> V_17 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_435 ) ;
return V_60 & V_436 ;
}
static struct V_437 *
F_189 ( struct V_410 * V_18 )
{
int V_438 = V_18 -> V_427 ;
V_18 -> V_427 = F_183 ( V_18 , V_438 ) ;
return V_18 -> V_412 + V_438 ;
}
static void F_190 ( struct V_14 * V_15 , int V_439 )
{
F_1 ( V_15 -> V_2 , V_440 , V_439 ) ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_410 * V_441 , int V_348 )
{
if ( ( V_441 -> V_442 + V_348 ) > V_441 -> V_9 ) {
int V_362 = F_187 () ;
T_1 V_60 = F_3 ( V_2 , F_192 ( V_362 ) ) ;
V_441 -> V_442 = V_60 & V_443 ;
}
if ( ( V_441 -> V_442 + V_348 ) > V_441 -> V_9 )
return - V_144 ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 ,
struct V_410 * V_18 , int V_348 )
{
T_1 V_60 ;
V_60 = ( V_18 -> V_17 << V_444 ) | V_348 ;
F_1 ( V_2 , V_445 , V_60 ) ;
V_60 = F_3 ( V_2 , V_446 ) ;
return V_60 & V_447 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_410 * V_18 ,
struct V_6 * V_7 ,
int V_348 )
{
int V_448 , V_362 , V_449 ;
if ( V_7 -> V_450 >= V_348 )
return 0 ;
V_449 = 0 ;
F_150 (cpu) {
struct V_6 * V_451 ;
V_451 = F_195 ( V_18 -> V_452 , V_362 ) ;
V_449 += V_451 -> V_442 ;
V_449 += V_451 -> V_450 ;
}
V_448 = F_196 ( V_453 , V_348 - V_7 -> V_450 ) ;
V_449 += V_448 ;
if ( V_449 >
( V_18 -> V_9 - ( F_197 () * V_453 ) ) )
return - V_144 ;
V_7 -> V_450 += F_193 ( V_2 , V_18 , V_448 ) ;
if ( V_7 -> V_450 < V_348 )
return - V_144 ;
return 0 ;
}
static void F_198 ( struct V_410 * V_18 )
{
if ( V_18 -> V_427 == 0 )
V_18 -> V_427 = V_18 -> V_454 - 1 ;
else
V_18 -> V_427 -- ;
}
static T_1 F_199 ( int V_455 , int V_456 ,
int V_457 , int V_458 )
{
T_1 V_459 ;
V_459 = ( V_455 << V_460 ) ;
V_459 |= ( V_457 << V_461 ) ;
V_459 |= V_462 ;
if ( V_456 == F_51 ( V_214 ) ) {
V_459 &= ~ V_462 ;
V_459 &= ~ V_463 ;
} else {
V_459 |= V_463 ;
}
if ( V_458 == V_154 ) {
V_459 &= ~ V_464 ;
V_459 &= ~ V_465 ;
} else if ( V_458 == V_155 ) {
V_459 |= V_464 ;
V_459 &= ~ V_465 ;
} else {
V_459 |= V_466 ;
}
return V_459 ;
}
static inline int F_200 ( struct V_14 * V_15 ,
struct V_410 * V_18 )
{
T_1 V_60 ;
V_60 = F_3 ( V_15 -> V_2 , F_201 ( V_18 -> V_17 ) ) ;
return ( V_60 & V_467 ) >>
V_468 ;
}
static void F_202 ( void * V_364 )
{
struct V_14 * V_15 = V_364 ;
int V_389 ;
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
int V_17 = V_15 -> V_411 [ V_389 ] -> V_17 ;
F_3 ( V_15 -> V_2 , F_201 ( V_17 ) ) ;
}
}
static void F_203 ( struct V_14 * V_15 )
{
T_1 V_60 , V_9 , V_359 ;
int V_18 , V_388 ;
V_359 = V_15 -> V_305 * 8 ;
if ( V_359 > V_469 )
V_359 = V_469 ;
V_359 = 3 * V_359 ;
V_388 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_394 , V_388 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_470 ) ;
V_60 &= ~ V_469 ;
V_60 |= V_359 ;
F_1 ( V_15 -> V_2 , V_470 , V_60 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_403 ) ;
V_9 = V_60 & V_402 ;
if ( V_9 < V_359 ) {
V_9 = V_359 ;
V_60 &= ~ V_402 ;
V_60 |= V_9 ;
F_1 ( V_15 -> V_2 , V_403 , V_60 ) ;
}
for ( V_18 = 0 ; V_18 < V_409 ; V_18 ++ ) {
V_60 = F_3 ( V_15 -> V_2 ,
F_204 ( V_18 ) ) ;
V_9 = V_60 & V_471 ;
if ( V_9 < V_359 ) {
V_9 = V_359 ;
V_60 &= ~ V_471 ;
V_60 |= V_9 ;
F_1 ( V_15 -> V_2 ,
F_204 ( V_18 ) ,
V_60 ) ;
}
}
}
static void F_205 ( struct V_14 * V_15 ,
struct V_425 * V_353 , T_1 V_472 )
{
T_1 V_60 ;
V_60 = ( V_472 & V_473 ) ;
F_1 ( V_15 -> V_2 , V_474 , V_353 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_475 , V_60 ) ;
V_353 -> V_476 = V_472 ;
}
static void F_206 ( struct V_14 * V_15 ,
struct V_425 * V_353 , T_1 V_477 )
{
T_1 V_60 ;
V_60 = ( V_15 -> V_2 -> V_397 / V_398 ) * V_477 ;
F_1 ( V_15 -> V_2 , F_207 ( V_353 -> V_17 ) , V_60 ) ;
V_353 -> V_478 = V_477 ;
}
static void F_208 ( void * V_364 )
{
struct V_14 * V_15 = V_364 ;
int V_389 ;
T_1 V_60 ;
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
struct V_410 * V_18 = V_15 -> V_411 [ V_389 ] ;
V_60 = ( V_18 -> V_479 << V_480 ) &
V_481 ;
F_1 ( V_15 -> V_2 , V_434 , V_18 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_482 , V_60 ) ;
}
}
static void F_209 ( struct V_14 * V_15 ,
struct V_410 * V_18 ,
struct V_6 * V_7 , int V_348 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_348 ; V_22 ++ ) {
struct V_437 * V_438 = V_18 -> V_412 +
V_7 -> V_8 ;
struct V_10 * V_11 = V_7 -> V_12 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! V_11 )
continue;
F_210 ( V_15 -> V_229 -> V_229 . V_329 , V_438 -> V_327 ,
V_438 -> V_483 , V_484 ) ;
F_115 ( V_11 ) ;
}
}
static inline struct V_425 * F_211 ( struct V_14 * V_15 ,
T_1 V_485 )
{
int V_389 = F_212 ( V_485 ) - 1 ;
return V_15 -> V_321 [ V_389 ] ;
}
static inline struct V_410 * F_213 ( struct V_14 * V_15 ,
T_1 V_485 )
{
int V_389 = F_212 ( V_485 >> 16 ) - 1 ;
return V_15 -> V_411 [ V_389 ] ;
}
static void F_214 ( struct V_14 * V_15 , struct V_410 * V_18 ,
struct V_6 * V_7 )
{
struct V_486 * V_487 = F_215 ( V_15 -> V_229 , V_18 -> V_488 ) ;
int V_489 ;
if ( V_7 -> V_362 != F_187 () )
F_139 ( V_15 -> V_229 , L_12 ) ;
V_489 = F_200 ( V_15 , V_18 ) ;
if ( ! V_489 )
return;
F_209 ( V_15 , V_18 , V_7 , V_489 ) ;
V_7 -> V_442 -= V_489 ;
if ( F_216 ( V_487 ) )
if ( V_7 -> V_9 - V_7 -> V_442 >= V_490 + 1 )
F_217 ( V_487 ) ;
}
static int F_218 ( struct V_226 * V_227 ,
struct V_410 * V_441 ,
int V_491 , int V_362 ,
struct V_1 * V_2 )
{
V_441 -> V_412 = F_101 ( & V_227 -> V_229 ,
V_491 * V_492 ,
& V_441 -> V_493 , V_94 ) ;
if ( ! V_441 -> V_412 )
return - V_144 ;
F_219 ( V_441 -> V_412 !=
F_220 ( V_441 -> V_412 , V_494 ) ) ;
V_441 -> V_454 = V_441 -> V_9 - 1 ;
V_441 -> V_427 = F_3 ( V_2 ,
F_221 ( V_362 ) ) ;
F_1 ( V_2 , F_222 ( V_362 ) ,
V_441 -> V_493 ) ;
F_1 ( V_2 , F_223 ( V_362 ) , V_491 ) ;
return 0 ;
}
static int F_224 ( struct V_14 * V_15 ,
struct V_425 * V_353 )
{
V_353 -> V_9 = V_15 -> V_495 ;
V_353 -> V_412 = F_101 ( V_15 -> V_229 -> V_229 . V_329 ,
V_353 -> V_9 * V_492 ,
& V_353 -> V_493 , V_94 ) ;
if ( ! V_353 -> V_412 )
return - V_144 ;
F_219 ( V_353 -> V_412 !=
F_220 ( V_353 -> V_412 , V_494 ) ) ;
V_353 -> V_454 = V_353 -> V_9 - 1 ;
F_1 ( V_15 -> V_2 , F_179 ( V_353 -> V_17 ) , 0 ) ;
F_1 ( V_15 -> V_2 , V_474 , V_353 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_496 , V_353 -> V_493 ) ;
F_1 ( V_15 -> V_2 , V_497 , V_353 -> V_9 ) ;
F_1 ( V_15 -> V_2 , V_498 , 0 ) ;
F_185 ( V_15 , V_353 -> V_17 , V_499 ) ;
F_205 ( V_15 , V_353 , V_353 -> V_476 ) ;
F_206 ( V_15 , V_353 , V_353 -> V_478 ) ;
F_180 ( V_15 , V_353 -> V_17 , 0 , V_353 -> V_9 ) ;
return 0 ;
}
static void F_225 ( struct V_14 * V_15 ,
struct V_425 * V_353 )
{
int V_500 , V_22 ;
V_500 = F_178 ( V_15 , V_353 -> V_17 ) ;
if ( ! V_500 )
return;
for ( V_22 = 0 ; V_22 < V_500 ; V_22 ++ ) {
struct V_424 * V_426 = F_182 ( V_353 ) ;
T_1 V_334 = F_186 ( V_426 ) ;
F_136 ( V_15 , V_334 , V_426 -> V_327 ,
V_426 -> V_501 ) ;
}
F_180 ( V_15 , V_353 -> V_17 , V_500 , V_500 ) ;
}
static void F_226 ( struct V_14 * V_15 ,
struct V_425 * V_353 )
{
F_225 ( V_15 , V_353 ) ;
if ( V_353 -> V_412 )
F_103 ( V_15 -> V_229 -> V_229 . V_329 ,
V_353 -> V_9 * V_492 ,
V_353 -> V_412 ,
V_353 -> V_493 ) ;
V_353 -> V_412 = NULL ;
V_353 -> V_454 = 0 ;
V_353 -> V_427 = 0 ;
V_353 -> V_493 = 0 ;
F_1 ( V_15 -> V_2 , F_179 ( V_353 -> V_17 ) , 0 ) ;
F_1 ( V_15 -> V_2 , V_474 , V_353 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_496 , 0 ) ;
F_1 ( V_15 -> V_2 , V_497 , 0 ) ;
}
static int F_227 ( struct V_14 * V_15 ,
struct V_410 * V_18 )
{
T_1 V_60 ;
int V_362 , V_502 , V_503 , V_388 ;
struct V_6 * V_7 ;
V_18 -> V_9 = V_15 -> V_504 ;
V_18 -> V_412 = F_101 ( V_15 -> V_229 -> V_229 . V_329 ,
V_18 -> V_9 * V_492 ,
& V_18 -> V_493 , V_94 ) ;
if ( ! V_18 -> V_412 )
return - V_144 ;
F_219 ( V_18 -> V_412 !=
F_220 ( V_18 -> V_412 , V_494 ) ) ;
V_18 -> V_454 = V_18 -> V_9 - 1 ;
F_1 ( V_15 -> V_2 , V_434 , V_18 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_505 , V_18 -> V_493 ) ;
F_1 ( V_15 -> V_2 , V_506 , V_18 -> V_9 &
V_507 ) ;
F_1 ( V_15 -> V_2 , V_508 , 0 ) ;
F_1 ( V_15 -> V_2 , V_509 ,
V_18 -> V_17 << V_510 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_435 ) ;
V_60 &= ~ V_436 ;
F_1 ( V_15 -> V_2 , V_435 , V_60 ) ;
V_503 = 16 ;
V_502 = ( V_15 -> V_17 * V_19 * V_503 ) +
( V_18 -> V_488 * V_503 ) ;
F_1 ( V_15 -> V_2 , V_511 ,
F_228 ( V_502 ) | V_512 |
F_229 ( V_503 / 2 ) ) ;
V_388 = F_7 ( V_15 ) ;
F_1 ( V_15 -> V_2 , V_394 , V_388 ) ;
V_60 = F_3 ( V_15 -> V_2 , F_230 ( V_18 -> V_488 ) ) ;
V_60 &= ~ V_513 ;
V_60 |= F_231 ( 1 ) ;
V_60 |= V_514 ;
F_1 ( V_15 -> V_2 , F_230 ( V_18 -> V_488 ) , V_60 ) ;
V_60 = V_471 ;
F_1 ( V_15 -> V_2 , F_204 ( V_18 -> V_488 ) ,
V_60 ) ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_452 , V_362 ) ;
V_7 -> V_9 = V_18 -> V_9 ;
V_7 -> V_12 = F_232 ( V_7 -> V_9 *
sizeof( * V_7 -> V_12 ) ,
V_94 ) ;
if ( ! V_7 -> V_12 ) {
F_103 ( V_15 -> V_229 -> V_229 . V_329 ,
V_18 -> V_9 * V_492 ,
V_18 -> V_412 , V_18 -> V_493 ) ;
return - V_144 ;
}
V_7 -> V_442 = 0 ;
V_7 -> V_450 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_8 = 0 ;
}
return 0 ;
}
static void F_233 ( struct V_14 * V_15 ,
struct V_410 * V_18 )
{
struct V_6 * V_7 ;
int V_362 ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_452 , V_362 ) ;
F_42 ( V_7 -> V_12 ) ;
}
if ( V_18 -> V_412 )
F_103 ( V_15 -> V_229 -> V_229 . V_329 ,
V_18 -> V_9 * V_492 ,
V_18 -> V_412 , V_18 -> V_493 ) ;
V_18 -> V_412 = NULL ;
V_18 -> V_454 = 0 ;
V_18 -> V_427 = 0 ;
V_18 -> V_493 = 0 ;
F_1 ( V_15 -> V_2 , F_168 ( V_18 -> V_17 ) , 0 ) ;
F_1 ( V_15 -> V_2 , V_434 , V_18 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_505 , 0 ) ;
F_1 ( V_15 -> V_2 , V_506 , 0 ) ;
}
static void F_234 ( struct V_14 * V_15 , struct V_410 * V_18 )
{
struct V_6 * V_7 ;
int V_415 , V_439 , V_362 ;
T_1 V_60 ;
F_1 ( V_15 -> V_2 , V_434 , V_18 -> V_17 ) ;
V_60 = F_3 ( V_15 -> V_2 , V_511 ) ;
V_60 |= V_515 ;
F_1 ( V_15 -> V_2 , V_511 , V_60 ) ;
V_415 = 0 ;
do {
if ( V_415 >= V_516 ) {
F_176 ( V_15 -> V_229 ,
L_13 ,
V_15 -> V_17 , V_18 -> V_488 ) ;
break;
}
F_177 ( 1 ) ;
V_415 ++ ;
V_439 = F_188 ( V_15 , V_18 ) ;
} while ( V_439 );
V_60 &= ~ V_515 ;
F_1 ( V_15 -> V_2 , V_511 , V_60 ) ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_452 , V_362 ) ;
F_209 ( V_15 , V_18 , V_7 , V_7 -> V_442 ) ;
V_7 -> V_442 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_8 = 0 ;
}
}
static void F_235 ( struct V_14 * V_15 )
{
struct V_410 * V_18 ;
int V_389 ;
T_1 V_60 ;
V_60 = F_3 ( V_15 -> V_2 , V_517 ) ;
V_60 |= F_236 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_517 , V_60 ) ;
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
V_18 = V_15 -> V_411 [ V_389 ] ;
F_234 ( V_15 , V_18 ) ;
F_233 ( V_15 , V_18 ) ;
}
F_237 ( F_202 , V_15 , 1 ) ;
V_60 &= ~ F_236 ( V_15 -> V_17 ) ;
F_1 ( V_15 -> V_2 , V_517 , V_60 ) ;
}
static void F_238 ( struct V_14 * V_15 )
{
int V_389 ;
for ( V_389 = 0 ; V_389 < V_355 ; V_389 ++ )
F_226 ( V_15 , V_15 -> V_321 [ V_389 ] ) ;
}
static int F_239 ( struct V_14 * V_15 )
{
int V_389 , V_228 ;
for ( V_389 = 0 ; V_389 < V_355 ; V_389 ++ ) {
V_228 = F_224 ( V_15 , V_15 -> V_321 [ V_389 ] ) ;
if ( V_228 )
goto V_518;
}
return 0 ;
V_518:
F_238 ( V_15 ) ;
return V_228 ;
}
static int F_240 ( struct V_14 * V_15 )
{
struct V_410 * V_18 ;
int V_389 , V_228 ;
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
V_18 = V_15 -> V_411 [ V_389 ] ;
V_228 = F_227 ( V_15 , V_18 ) ;
if ( V_228 )
goto V_518;
}
F_237 ( F_208 , V_15 , 1 ) ;
F_237 ( F_202 , V_15 , 1 ) ;
return 0 ;
V_518:
F_235 ( V_15 ) ;
return V_228 ;
}
static T_6 F_241 ( int V_519 , void * V_520 )
{
struct V_14 * V_15 = (struct V_14 * ) V_520 ;
F_153 ( V_15 ) ;
F_242 ( & V_15 -> V_521 ) ;
return V_522 ;
}
static void F_243 ( struct V_265 * V_229 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
struct V_523 * V_524 = V_15 -> V_525 ;
int V_526 = 0 ;
T_1 V_60 ;
if ( V_524 -> V_527 ) {
if ( ( V_15 -> V_382 != V_524 -> V_382 ) ||
( V_15 -> V_528 != V_524 -> V_528 ) ) {
T_1 V_60 ;
V_60 = F_4 ( V_15 -> V_5 + V_375 ) ;
V_60 &= ~ ( V_529 |
V_530 |
V_531 |
V_532 |
V_533 ) ;
if ( V_524 -> V_528 )
V_60 |= V_531 ;
if ( V_524 -> V_382 == V_534 )
V_60 |= V_530 ;
else if ( V_524 -> V_382 == V_535 )
V_60 |= V_529 ;
F_2 ( V_60 , V_15 -> V_5 + V_375 ) ;
V_15 -> V_528 = V_524 -> V_528 ;
V_15 -> V_382 = V_524 -> V_382 ;
}
}
if ( V_524 -> V_527 != V_15 -> V_527 ) {
if ( ! V_524 -> V_527 ) {
V_15 -> V_528 = - 1 ;
V_15 -> V_382 = 0 ;
}
V_15 -> V_527 = V_524 -> V_527 ;
V_526 = 1 ;
}
if ( V_526 ) {
if ( V_524 -> V_527 ) {
V_60 = F_4 ( V_15 -> V_5 + V_375 ) ;
V_60 |= ( V_536 |
V_537 ) ;
F_2 ( V_60 , V_15 -> V_5 + V_375 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
} else {
F_173 ( V_15 ) ;
F_175 ( V_15 ) ;
}
F_244 ( V_524 ) ;
}
}
static void F_245 ( struct V_14 * V_15 ,
struct V_424 * V_426 )
{
T_1 V_430 = V_426 -> V_430 ;
switch ( V_430 & V_538 ) {
case V_539 :
F_139 ( V_15 -> V_229 , L_14 ,
V_430 , V_426 -> V_483 ) ;
break;
case V_540 :
F_139 ( V_15 -> V_229 , L_15 ,
V_430 , V_426 -> V_483 ) ;
break;
case V_541 :
F_139 ( V_15 -> V_229 , L_16 ,
V_430 , V_426 -> V_483 ) ;
break;
}
}
static void F_246 ( struct V_14 * V_15 , T_1 V_430 ,
struct V_10 * V_11 )
{
if ( ( ( V_430 & V_542 ) &&
! ( V_430 & V_543 ) ) ||
( V_430 & V_544 ) )
if ( ( ( V_430 & V_545 ) ||
( V_430 & V_546 ) ) &&
( V_430 & V_547 ) ) {
V_11 -> V_548 = 0 ;
V_11 -> V_549 = V_550 ;
return;
}
V_11 -> V_549 = V_551 ;
}
static int F_247 ( struct V_14 * V_15 ,
struct V_297 * V_298 ,
T_1 V_334 , int V_552 )
{
struct V_10 * V_11 ;
T_4 V_301 ;
if ( V_552 &&
( F_248 ( & V_298 -> V_307 ) < V_298 -> V_343 ) )
return 0 ;
V_11 = F_125 ( V_15 , V_298 , & V_301 , V_553 ) ;
if ( ! V_11 )
return - V_144 ;
F_136 ( V_15 , V_334 , ( T_1 ) V_301 , ( T_1 ) V_11 ) ;
F_249 ( & V_298 -> V_307 ) ;
return 0 ;
}
static T_1 F_250 ( struct V_14 * V_15 , struct V_10 * V_11 )
{
if ( V_11 -> V_549 == V_554 ) {
int V_457 = 0 ;
T_3 V_458 ;
if ( V_11 -> V_555 == F_251 ( V_214 ) ) {
struct V_159 * V_556 = F_252 ( V_11 ) ;
V_457 = V_556 -> V_557 ;
V_458 = V_556 -> V_555 ;
} else if ( V_11 -> V_555 == F_251 ( V_221 ) ) {
struct V_178 * V_558 = F_253 ( V_11 ) ;
if ( F_254 ( V_11 ) > 0 )
V_457 = ( F_254 ( V_11 ) >> 2 ) ;
V_458 = V_558 -> V_559 ;
} else {
return V_466 ;
}
return F_199 ( F_255 ( V_11 ) ,
V_11 -> V_555 , V_457 , V_458 ) ;
}
return V_466 | V_462 ;
}
static void F_256 ( struct V_14 * V_15 ,
struct V_424 * V_426 )
{
struct V_560 * V_561 ;
struct V_10 * V_11 ;
T_1 V_562 = V_426 -> V_430 ;
T_1 V_563 ;
T_1 V_564 ;
T_1 V_565 ;
T_1 V_566 ;
int V_338 ;
int V_567 ;
V_567 = ( V_562 & V_431 ) >>
V_432 ;
V_563 = V_426 -> V_327 ;
V_564 = V_426 -> V_501 ;
do {
V_11 = (struct V_10 * ) V_564 ;
V_561 = (struct V_560 * ) V_11 -> V_330 ;
V_338 = F_257 ( V_561 -> V_568 ) ;
V_565 = V_561 -> V_569 ;
V_566 = V_561 -> V_570 ;
F_135 ( V_15 , V_567 , V_563 ,
V_564 , V_338 ) ;
V_563 = V_565 ;
V_564 = V_566 ;
} while ( ! F_258 ( V_561 -> V_568 ) );
}
static int F_259 ( struct V_14 * V_15 , int V_571 ,
struct V_425 * V_353 )
{
struct V_265 * V_229 = V_15 -> V_229 ;
int V_500 , V_572 , V_22 ;
T_1 V_573 = 0 ;
T_1 V_574 = 0 ;
V_500 = F_178 ( V_15 , V_353 -> V_17 ) ;
if ( V_571 > V_500 )
V_571 = V_500 ;
V_572 = 0 ;
for ( V_22 = 0 ; V_22 < V_571 ; V_22 ++ ) {
struct V_424 * V_426 = F_182 ( V_353 ) ;
struct V_297 * V_298 ;
struct V_10 * V_11 ;
T_1 V_334 , V_562 ;
int V_333 , V_575 , V_228 ;
V_572 ++ ;
V_562 = V_426 -> V_430 ;
V_575 = V_426 -> V_483 - V_190 ;
V_334 = F_186 ( V_426 ) ;
V_333 = F_132 ( V_334 ) ;
V_298 = & V_15 -> V_2 -> V_316 [ V_333 ] ;
if ( V_562 & V_576 ) {
F_256 ( V_15 , V_426 ) ;
continue;
}
if ( V_562 & V_577 ) {
V_229 -> V_578 . V_579 ++ ;
F_245 ( V_15 , V_426 ) ;
F_136 ( V_15 , V_334 , V_426 -> V_327 ,
V_426 -> V_501 ) ;
continue;
}
V_11 = (struct V_10 * ) V_426 -> V_501 ;
V_573 ++ ;
V_574 += V_575 ;
F_260 ( & V_298 -> V_307 ) ;
F_261 ( V_11 , V_190 ) ;
F_262 ( V_11 , V_575 ) ;
V_11 -> V_555 = F_263 ( V_11 , V_229 ) ;
F_246 ( V_15 , V_562 , V_11 ) ;
F_264 ( & V_15 -> V_521 , V_11 ) ;
V_228 = F_247 ( V_15 , V_298 , V_334 , 0 ) ;
if ( V_228 ) {
F_139 ( V_15 -> V_229 , L_17 ) ;
V_572 -- ;
}
}
if ( V_573 ) {
struct V_580 * V_578 = F_265 ( V_15 -> V_578 ) ;
F_266 ( & V_578 -> V_581 ) ;
V_578 -> V_582 += V_573 ;
V_578 -> V_575 += V_574 ;
F_267 ( & V_578 -> V_581 ) ;
}
F_268 () ;
F_180 ( V_15 , V_353 -> V_17 , V_571 , V_572 ) ;
return V_571 ;
}
static inline void
F_269 ( struct V_583 * V_229 , struct V_410 * V_18 ,
struct V_437 * V_502 )
{
F_210 ( V_229 , V_502 -> V_327 ,
V_502 -> V_483 , V_484 ) ;
F_198 ( V_18 ) ;
}
static int F_270 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_410 * V_441 ,
struct V_410 * V_18 )
{
struct V_6 * V_7 = F_265 ( V_18 -> V_452 ) ;
struct V_437 * V_438 ;
int V_22 ;
T_4 V_327 ;
for ( V_22 = 0 ; V_22 < F_271 ( V_11 ) -> V_584 ; V_22 ++ ) {
T_7 * V_585 = & F_271 ( V_11 ) -> V_586 [ V_22 ] ;
void * V_587 = F_272 ( V_585 -> V_588 . V_589 ) + V_585 -> V_590 ;
V_438 = F_189 ( V_441 ) ;
V_438 -> V_591 = V_18 -> V_17 ;
V_438 -> V_483 = V_585 -> V_9 ;
V_327 = F_127 ( V_15 -> V_229 -> V_229 . V_329 , V_587 ,
V_438 -> V_483 ,
V_484 ) ;
if ( F_130 ( V_15 -> V_229 -> V_229 . V_329 , V_327 ) ) {
F_198 ( V_18 ) ;
goto error;
}
V_438 -> V_592 = V_327 & V_593 ;
V_438 -> V_327 = V_327 & ( ~ V_593 ) ;
if ( V_22 == ( F_271 ( V_11 ) -> V_584 - 1 ) ) {
V_438 -> V_459 = V_594 ;
F_6 ( V_7 , V_11 ) ;
} else {
V_438 -> V_459 = 0 ;
F_6 ( V_7 , NULL ) ;
}
}
return 0 ;
error:
for ( V_22 = V_22 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_438 = V_18 -> V_412 + V_22 ;
F_269 ( V_15 -> V_229 -> V_229 . V_329 , V_18 , V_438 ) ;
}
return - V_144 ;
}
static int F_273 ( struct V_10 * V_11 , struct V_265 * V_229 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
struct V_410 * V_18 , * V_441 ;
struct V_6 * V_7 ;
struct V_437 * V_438 ;
T_4 V_327 ;
int V_586 = 0 ;
T_2 V_595 ;
T_1 V_596 ;
V_595 = F_274 ( V_11 ) ;
V_18 = V_15 -> V_411 [ V_595 ] ;
V_7 = F_265 ( V_18 -> V_452 ) ;
V_441 = & V_15 -> V_2 -> V_597 [ F_187 () ] ;
V_586 = F_271 ( V_11 ) -> V_584 + 1 ;
if ( F_191 ( V_15 -> V_2 , V_441 , V_586 ) ||
F_194 ( V_15 -> V_2 , V_18 ,
V_7 , V_586 ) ) {
V_586 = 0 ;
goto V_598;
}
V_438 = F_189 ( V_441 ) ;
V_438 -> V_591 = V_18 -> V_17 ;
V_438 -> V_483 = F_275 ( V_11 ) ;
V_327 = F_127 ( V_229 -> V_229 . V_329 , V_11 -> V_4 ,
V_438 -> V_483 , V_484 ) ;
if ( F_129 ( F_130 ( V_229 -> V_229 . V_329 , V_327 ) ) ) {
F_198 ( V_18 ) ;
V_586 = 0 ;
goto V_598;
}
V_438 -> V_592 = V_327 & V_593 ;
V_438 -> V_327 = V_327 & ~ V_593 ;
V_596 = F_250 ( V_15 , V_11 ) ;
if ( V_586 == 1 ) {
V_596 |= V_599 | V_594 ;
V_438 -> V_459 = V_596 ;
F_6 ( V_7 , V_11 ) ;
} else {
V_596 |= V_599 | V_600 ;
V_438 -> V_459 = V_596 ;
F_6 ( V_7 , NULL ) ;
if ( F_270 ( V_15 , V_11 , V_441 , V_18 ) ) {
F_269 ( V_15 -> V_229 -> V_229 . V_329 , V_18 , V_438 ) ;
V_586 = 0 ;
goto V_598;
}
}
V_7 -> V_450 -= V_586 ;
V_7 -> V_442 += V_586 ;
V_441 -> V_442 += V_586 ;
F_268 () ;
F_190 ( V_15 , V_586 ) ;
if ( V_7 -> V_9 - V_7 -> V_442 < V_490 + 1 ) {
struct V_486 * V_487 = F_215 ( V_229 , V_595 ) ;
F_276 ( V_487 ) ;
}
V_598:
if ( V_586 > 0 ) {
struct V_580 * V_578 = F_265 ( V_15 -> V_578 ) ;
F_266 ( & V_578 -> V_581 ) ;
V_578 -> V_601 ++ ;
V_578 -> V_602 += V_11 -> V_260 ;
F_267 ( & V_578 -> V_581 ) ;
} else {
V_229 -> V_578 . V_603 ++ ;
F_115 ( V_11 ) ;
}
return V_604 ;
}
static inline void F_277 ( struct V_265 * V_229 , int V_485 )
{
if ( V_485 & V_605 )
F_139 ( V_229 , L_18 ) ;
if ( V_485 & V_606 )
F_139 ( V_229 , L_19 ) ;
if ( V_485 & V_607 )
F_139 ( V_229 , L_20 ) ;
}
static void F_278 ( void * V_364 )
{
struct V_14 * V_15 = V_364 ;
T_1 V_608 , V_609 , V_610 ;
V_608 = F_3 ( V_15 -> V_2 ,
F_279 ( V_15 -> V_17 ) ) ;
V_609 = V_608 & V_366 ;
V_610 = V_608 & V_365 ;
if ( V_610 ) {
F_277 ( V_15 -> V_229 , V_610 ) ;
F_1 ( V_15 -> V_2 , V_611 , 0 ) ;
F_1 ( V_15 -> V_2 , F_279 ( V_15 -> V_17 ) ,
V_608 & ~ V_365 ) ;
}
if ( V_609 ) {
struct V_410 * V_18 = F_213 ( V_15 , V_609 ) ;
struct V_6 * V_7 = F_265 ( V_18 -> V_452 ) ;
if ( V_7 -> V_442 )
F_214 ( V_15 , V_18 , V_7 ) ;
}
}
static int F_280 ( struct V_612 * V_521 , int V_613 )
{
T_1 V_608 , V_614 ;
int V_615 = 0 ;
struct V_14 * V_15 = F_86 ( V_521 -> V_229 ) ;
F_237 ( F_278 , V_15 , 1 ) ;
V_608 = F_3 ( V_15 -> V_2 ,
F_279 ( V_15 -> V_17 ) ) ;
V_614 = V_608 & V_367 ;
V_614 |= V_15 -> V_616 ;
while ( V_614 && V_613 > 0 ) {
int V_442 ;
struct V_425 * V_353 ;
V_353 = F_211 ( V_15 , V_614 ) ;
if ( ! V_353 )
break;
V_442 = F_259 ( V_15 , V_613 , V_353 ) ;
V_615 += V_442 ;
V_613 -= V_442 ;
if ( V_613 > 0 ) {
V_614 &= ~ ( 1 << V_353 -> V_617 ) ;
}
}
if ( V_613 > 0 ) {
V_614 = 0 ;
F_281 ( V_521 ) ;
F_149 ( V_15 ) ;
}
V_15 -> V_616 = V_614 ;
return V_615 ;
}
static void F_282 ( struct V_14 * V_15 )
{
F_165 ( V_15 ) ;
F_203 ( V_15 ) ;
F_283 ( & V_15 -> V_521 ) ;
F_149 ( V_15 ) ;
F_160 ( V_15 ) ;
F_284 ( V_15 -> V_525 ) ;
F_285 ( V_15 -> V_229 ) ;
}
static void F_286 ( struct V_14 * V_15 )
{
F_173 ( V_15 ) ;
F_177 ( 10 ) ;
F_153 ( V_15 ) ;
F_287 ( & V_15 -> V_521 ) ;
F_288 ( V_15 -> V_229 ) ;
F_289 ( V_15 -> V_229 ) ;
F_175 ( V_15 ) ;
F_161 ( V_15 ) ;
F_290 ( V_15 -> V_525 ) ;
}
static inline int F_291 ( struct V_265 * V_229 , int V_359 )
{
if ( V_359 < 68 ) {
F_139 ( V_229 , L_21 ) ;
return - V_25 ;
}
if ( V_359 > 9676 ) {
F_292 ( V_229 , L_22 , V_359 ) ;
V_359 = 9676 ;
}
if ( ! F_102 ( F_147 ( V_359 ) , 8 ) ) {
F_292 ( V_229 , L_23 , V_359 ,
F_111 ( F_147 ( V_359 ) , 8 ) ) ;
V_359 = F_111 ( F_147 ( V_359 ) , 8 ) ;
}
return V_359 ;
}
static int F_293 ( struct V_265 * V_229 ,
struct V_618 * V_619 )
{
T_2 V_620 = V_619 -> V_621 ;
T_2 V_622 = V_619 -> V_623 ;
if ( V_619 -> V_621 == 0 || V_619 -> V_623 == 0 )
return - V_25 ;
if ( V_619 -> V_621 > V_624 )
V_620 = V_624 ;
else if ( ! F_102 ( V_619 -> V_621 , 16 ) )
V_620 = F_111 ( V_619 -> V_621 , 16 ) ;
if ( V_619 -> V_623 > V_625 )
V_622 = V_625 ;
else if ( ! F_102 ( V_619 -> V_623 , 32 ) )
V_622 = F_111 ( V_619 -> V_623 , 32 ) ;
if ( V_619 -> V_621 != V_620 ) {
F_292 ( V_229 , L_24 ,
V_619 -> V_621 , V_620 ) ;
V_619 -> V_621 = V_620 ;
}
if ( V_619 -> V_623 != V_622 ) {
F_292 ( V_229 , L_25 ,
V_619 -> V_623 , V_622 ) ;
V_619 -> V_623 = V_622 ;
}
return 0 ;
}
static void F_294 ( struct V_14 * V_15 , unsigned char * V_587 )
{
T_1 V_626 , V_627 , V_628 ;
V_626 = F_4 ( V_15 -> V_5 + V_380 ) ;
V_627 = F_4 ( V_15 -> V_2 -> V_629 + V_630 ) ;
V_628 = F_4 ( V_15 -> V_2 -> V_629 + V_631 ) ;
V_587 [ 0 ] = ( V_628 >> 24 ) & 0xFF ;
V_587 [ 1 ] = ( V_628 >> 16 ) & 0xFF ;
V_587 [ 2 ] = ( V_628 >> 8 ) & 0xFF ;
V_587 [ 3 ] = V_628 & 0xFF ;
V_587 [ 4 ] = V_627 & 0xFF ;
V_587 [ 5 ] = ( V_626 >> V_632 ) & 0xFF ;
}
static int F_295 ( struct V_14 * V_15 )
{
struct V_523 * V_525 ;
V_525 = F_296 ( V_15 -> V_229 , V_15 -> V_633 , F_243 , 0 ,
V_15 -> V_369 ) ;
if ( ! V_525 ) {
F_139 ( V_15 -> V_229 , L_26 ) ;
return - V_634 ;
}
V_525 -> V_635 &= V_636 ;
V_525 -> V_637 = V_525 -> V_635 ;
V_15 -> V_525 = V_525 ;
V_15 -> V_527 = 0 ;
V_15 -> V_528 = 0 ;
V_15 -> V_382 = 0 ;
return 0 ;
}
static void F_297 ( struct V_14 * V_15 )
{
F_298 ( V_15 -> V_525 ) ;
V_15 -> V_525 = NULL ;
}
static int F_299 ( struct V_265 * V_229 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
unsigned char V_638 [ V_107 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_228 ;
V_228 = F_82 ( V_15 -> V_2 , V_15 -> V_17 , V_638 , true ) ;
if ( V_228 ) {
F_139 ( V_229 , L_27 ) ;
return V_228 ;
}
V_228 = F_82 ( V_15 -> V_2 , V_15 -> V_17 ,
V_229 -> V_266 , true ) ;
if ( V_228 ) {
F_139 ( V_229 , L_28 ) ;
return V_228 ;
}
V_228 = F_89 ( V_15 -> V_2 , V_15 -> V_17 , V_270 ) ;
if ( V_228 ) {
F_139 ( V_229 , L_29 ) ;
return V_228 ;
}
V_228 = F_90 ( V_15 ) ;
if ( V_228 ) {
F_139 ( V_229 , L_30 ) ;
return V_228 ;
}
V_228 = F_239 ( V_15 ) ;
if ( V_228 ) {
F_139 ( V_15 -> V_229 , L_31 ) ;
return V_228 ;
}
V_228 = F_240 ( V_15 ) ;
if ( V_228 ) {
F_139 ( V_15 -> V_229 , L_32 ) ;
goto V_639;
}
V_228 = F_300 ( V_15 -> V_519 , F_241 , 0 , V_229 -> V_640 , V_15 ) ;
if ( V_228 ) {
F_139 ( V_15 -> V_229 , L_33 , V_15 -> V_519 ) ;
goto V_641;
}
F_288 ( V_15 -> V_229 ) ;
V_228 = F_295 ( V_15 ) ;
if ( V_228 < 0 )
goto V_642;
F_237 ( F_157 , V_15 , 1 ) ;
F_282 ( V_15 ) ;
return 0 ;
V_642:
F_301 ( V_15 -> V_519 , V_15 ) ;
V_641:
F_235 ( V_15 ) ;
V_639:
F_238 ( V_15 ) ;
return V_228 ;
}
static int F_302 ( struct V_265 * V_229 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
F_286 ( V_15 ) ;
F_297 ( V_15 ) ;
F_237 ( F_155 , V_15 , 1 ) ;
F_301 ( V_15 -> V_519 , V_15 ) ;
F_238 ( V_15 ) ;
F_235 ( V_15 ) ;
return 0 ;
}
static void F_303 ( struct V_265 * V_229 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_643 * V_644 ;
int V_17 = V_15 -> V_17 ;
bool V_645 = V_229 -> V_346 & V_646 ;
F_46 ( V_2 , V_17 , V_229 -> V_346 & V_647 ) ;
F_47 ( V_2 , V_17 , V_110 , V_645 ) ;
F_47 ( V_2 , V_17 , V_192 , V_645 ) ;
F_88 ( V_2 , V_17 ) ;
if ( V_645 && ! F_304 ( V_229 ) ) {
F_305 (ha, dev)
F_82 ( V_2 , V_17 , V_644 -> V_587 , true ) ;
}
}
static int F_306 ( struct V_265 * V_229 , void * V_589 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
const struct V_648 * V_587 = V_589 ;
int V_228 ;
if ( ! F_307 ( V_587 -> V_649 ) ) {
V_228 = - V_650 ;
goto error;
}
if ( ! F_308 ( V_229 ) ) {
V_228 = F_85 ( V_229 , V_587 -> V_649 ) ;
if ( ! V_228 )
return 0 ;
V_228 = F_85 ( V_229 , V_229 -> V_266 ) ;
if ( V_228 )
goto error;
}
F_286 ( V_15 ) ;
V_228 = F_85 ( V_229 , V_587 -> V_649 ) ;
if ( ! V_228 )
goto V_651;
V_228 = F_85 ( V_229 , V_229 -> V_266 ) ;
if ( V_228 )
goto error;
V_651:
F_282 ( V_15 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
return 0 ;
error:
F_139 ( V_229 , L_34 ) ;
return V_228 ;
}
static int F_309 ( struct V_265 * V_229 , int V_359 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
int V_228 ;
V_359 = F_291 ( V_229 , V_359 ) ;
if ( V_359 < 0 ) {
V_228 = V_359 ;
goto error;
}
if ( ! F_308 ( V_229 ) ) {
V_228 = F_146 ( V_229 , V_359 ) ;
if ( ! V_228 ) {
V_15 -> V_305 = F_147 ( V_359 ) ;
return 0 ;
}
V_228 = F_146 ( V_229 , V_229 -> V_359 ) ;
if ( V_228 )
goto error;
}
F_286 ( V_15 ) ;
V_228 = F_146 ( V_229 , V_359 ) ;
if ( ! V_228 ) {
V_15 -> V_305 = F_147 ( V_359 ) ;
goto V_651;
}
V_228 = F_146 ( V_229 , V_229 -> V_359 ) ;
if ( V_228 )
goto error;
V_651:
F_282 ( V_15 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
return 0 ;
error:
F_139 ( V_229 , L_35 ) ;
return V_228 ;
}
static struct V_652 *
F_310 ( struct V_265 * V_229 , struct V_652 * V_578 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
unsigned int V_97 ;
int V_362 ;
F_311 (cpu) {
struct V_580 * V_653 ;
T_8 V_582 ;
T_8 V_575 ;
T_8 V_601 ;
T_8 V_602 ;
V_653 = F_195 ( V_15 -> V_578 , V_362 ) ;
do {
V_97 = F_312 ( & V_653 -> V_581 ) ;
V_582 = V_653 -> V_582 ;
V_575 = V_653 -> V_575 ;
V_601 = V_653 -> V_601 ;
V_602 = V_653 -> V_602 ;
} while ( F_313 ( & V_653 -> V_581 , V_97 ) );
V_578 -> V_582 += V_582 ;
V_578 -> V_575 += V_575 ;
V_578 -> V_601 += V_601 ;
V_578 -> V_602 += V_602 ;
}
V_578 -> V_579 = V_229 -> V_578 . V_579 ;
V_578 -> V_654 = V_229 -> V_578 . V_654 ;
V_578 -> V_603 = V_229 -> V_578 . V_603 ;
return V_578 ;
}
static int F_314 ( struct V_265 * V_229 , struct V_655 * V_656 , int V_657 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
int V_143 ;
if ( ! V_15 -> V_525 )
return - V_658 ;
V_143 = F_315 ( V_15 -> V_525 , V_656 , V_657 ) ;
if ( ! V_143 )
F_243 ( V_229 ) ;
return V_143 ;
}
static int F_316 ( struct V_265 * V_229 ,
struct V_659 * V_657 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
if ( ! V_15 -> V_525 )
return - V_634 ;
return F_317 ( V_15 -> V_525 , V_657 ) ;
}
static int F_318 ( struct V_265 * V_229 ,
struct V_659 * V_657 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
if ( ! V_15 -> V_525 )
return - V_634 ;
return F_319 ( V_15 -> V_525 , V_657 ) ;
}
static int F_320 ( struct V_265 * V_229 ,
struct V_660 * V_661 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
int V_389 ;
for ( V_389 = 0 ; V_389 < V_355 ; V_389 ++ ) {
struct V_425 * V_353 = V_15 -> V_321 [ V_389 ] ;
V_353 -> V_478 = V_661 -> V_662 ;
V_353 -> V_476 = V_661 -> V_663 ;
F_205 ( V_15 , V_353 , V_353 -> V_476 ) ;
F_206 ( V_15 , V_353 , V_353 -> V_478 ) ;
}
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
struct V_410 * V_18 = V_15 -> V_411 [ V_389 ] ;
V_18 -> V_479 = V_661 -> V_664 ;
}
F_237 ( F_208 , V_15 , 1 ) ;
return 0 ;
}
static int F_321 ( struct V_265 * V_229 ,
struct V_660 * V_661 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
V_661 -> V_662 = V_15 -> V_321 [ 0 ] -> V_478 ;
V_661 -> V_663 = V_15 -> V_321 [ 0 ] -> V_476 ;
V_661 -> V_664 = V_15 -> V_411 [ 0 ] -> V_479 ;
return 0 ;
}
static void F_322 ( struct V_265 * V_229 ,
struct V_665 * V_666 )
{
F_323 ( V_666 -> V_667 , V_668 ,
sizeof( V_666 -> V_667 ) ) ;
F_323 ( V_666 -> V_669 , V_670 ,
sizeof( V_666 -> V_669 ) ) ;
F_323 ( V_666 -> V_671 , F_324 ( & V_229 -> V_229 ) ,
sizeof( V_666 -> V_671 ) ) ;
}
static void F_325 ( struct V_265 * V_229 ,
struct V_618 * V_619 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
V_619 -> V_672 = V_624 ;
V_619 -> V_673 = V_625 ;
V_619 -> V_621 = V_15 -> V_495 ;
V_619 -> V_623 = V_15 -> V_504 ;
}
static int F_326 ( struct V_265 * V_229 ,
struct V_618 * V_619 )
{
struct V_14 * V_15 = F_86 ( V_229 ) ;
T_2 V_674 = V_15 -> V_495 ;
T_2 V_675 = V_15 -> V_504 ;
int V_228 ;
V_228 = F_293 ( V_229 , V_619 ) ;
if ( V_228 )
return V_228 ;
if ( ! F_308 ( V_229 ) ) {
V_15 -> V_495 = V_619 -> V_621 ;
V_15 -> V_504 = V_619 -> V_623 ;
return 0 ;
}
F_286 ( V_15 ) ;
F_238 ( V_15 ) ;
F_235 ( V_15 ) ;
V_15 -> V_495 = V_619 -> V_621 ;
V_15 -> V_504 = V_619 -> V_623 ;
V_228 = F_239 ( V_15 ) ;
if ( V_228 ) {
V_15 -> V_495 = V_674 ;
V_619 -> V_621 = V_674 ;
V_228 = F_239 ( V_15 ) ;
if ( V_228 )
goto V_676;
}
V_228 = F_240 ( V_15 ) ;
if ( V_228 ) {
V_15 -> V_504 = V_675 ;
V_619 -> V_623 = V_675 ;
V_228 = F_240 ( V_15 ) ;
if ( V_228 )
goto V_677;
}
F_282 ( V_15 ) ;
F_174 ( V_15 ) ;
F_172 ( V_15 ) ;
return 0 ;
V_677:
F_238 ( V_15 ) ;
V_676:
F_139 ( V_229 , L_36 ) ;
return V_228 ;
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
struct V_583 * V_229 = V_15 -> V_229 -> V_229 . V_329 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_6 * V_7 ;
int V_389 , V_362 , V_228 ;
if ( V_15 -> V_292 + V_355 > V_678 )
return - V_25 ;
F_175 ( V_15 ) ;
F_161 ( V_15 ) ;
V_15 -> V_411 = F_75 ( V_229 , V_409 , sizeof( * V_15 -> V_411 ) ,
V_94 ) ;
if ( ! V_15 -> V_411 )
return - V_144 ;
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
int V_679 = F_8 ( V_15 -> V_17 , V_389 ) ;
struct V_410 * V_18 ;
V_18 = F_329 ( V_229 , sizeof( * V_18 ) , V_94 ) ;
if ( ! V_18 )
return - V_144 ;
V_18 -> V_452 = F_330 ( struct V_6 ) ;
if ( ! V_18 -> V_452 ) {
V_228 = - V_144 ;
goto V_680;
}
V_18 -> V_17 = V_679 ;
V_18 -> V_488 = V_389 ;
V_18 -> V_479 = V_681 ;
F_150 (cpu) {
V_7 = F_195 ( V_18 -> V_452 , V_362 ) ;
V_7 -> V_362 = V_362 ;
}
V_15 -> V_411 [ V_389 ] = V_18 ;
}
V_15 -> V_321 = F_75 ( V_229 , V_355 , sizeof( * V_15 -> V_321 ) ,
V_94 ) ;
if ( ! V_15 -> V_321 ) {
V_228 = - V_144 ;
goto V_680;
}
for ( V_389 = 0 ; V_389 < V_355 ; V_389 ++ ) {
struct V_425 * V_353 ;
V_353 = F_329 ( V_229 , sizeof( * V_353 ) , V_94 ) ;
if ( ! V_353 )
goto V_680;
V_353 -> V_17 = V_15 -> V_292 + V_389 ;
V_353 -> V_15 = V_15 -> V_17 ;
V_353 -> V_617 = V_389 ;
V_15 -> V_321 [ V_389 ] = V_353 ;
}
F_1 ( V_2 , F_331 ( V_15 -> V_17 ) , V_355 ) ;
for ( V_389 = 0 ; V_389 < V_355 ; V_389 ++ ) {
struct V_425 * V_353 = V_15 -> V_321 [ V_389 ] ;
V_353 -> V_9 = V_15 -> V_495 ;
V_353 -> V_476 = V_682 ;
V_353 -> V_478 = V_683 ;
}
F_173 ( V_15 ) ;
F_166 ( V_15 ) ;
F_96 ( V_15 ) ;
F_94 ( V_15 ) ;
V_15 -> V_305 = F_147 ( V_15 -> V_229 -> V_359 ) ;
V_228 = F_144 ( V_15 ) ;
if ( V_228 )
goto V_680;
return 0 ;
V_680:
for ( V_389 = 0 ; V_389 < V_409 ; V_389 ++ ) {
if ( ! V_15 -> V_411 [ V_389 ] )
continue;
F_332 ( V_15 -> V_411 [ V_389 ] -> V_452 ) ;
}
return V_228 ;
}
static int F_333 ( struct V_226 * V_227 ,
struct V_684 * V_685 ,
struct V_1 * V_2 ,
int * V_686 )
{
struct V_684 * V_633 ;
struct V_14 * V_15 ;
struct V_265 * V_229 ;
struct V_687 * V_688 ;
const char * V_689 ;
const char * V_690 ;
char V_691 [ V_107 ] ;
T_1 V_17 ;
int V_692 ;
int V_693 ;
int V_694 = 2 ;
int V_228 , V_22 ;
V_229 = F_334 ( sizeof( struct V_14 ) , V_409 ,
V_355 ) ;
if ( ! V_229 )
return - V_144 ;
V_633 = F_335 ( V_685 , L_37 , 0 ) ;
if ( ! V_633 ) {
F_104 ( & V_227 -> V_229 , L_38 ) ;
V_228 = - V_634 ;
goto V_695;
}
V_693 = F_336 ( V_685 ) ;
if ( V_693 < 0 ) {
F_104 ( & V_227 -> V_229 , L_39 ) ;
V_228 = V_693 ;
goto V_695;
}
if ( F_337 ( V_685 , L_40 , & V_17 ) ) {
V_228 = - V_25 ;
F_104 ( & V_227 -> V_229 , L_41 ) ;
goto V_695;
}
V_229 -> V_696 = V_625 ;
V_229 -> V_697 = 5 * V_698 ;
V_229 -> V_699 = & V_700 ;
V_229 -> V_701 = & V_702 ;
V_15 = F_86 ( V_229 ) ;
V_15 -> V_519 = F_338 ( V_685 , 0 ) ;
if ( V_15 -> V_519 <= 0 ) {
V_228 = - V_25 ;
goto V_695;
}
if ( F_339 ( V_685 , L_42 ) )
V_15 -> V_346 |= V_391 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_292 = * V_686 ;
V_15 -> V_633 = V_633 ;
V_15 -> V_369 = V_693 ;
V_688 = F_340 ( V_227 , V_703 ,
V_694 + V_17 ) ;
V_15 -> V_5 = F_341 ( & V_227 -> V_229 , V_688 ) ;
if ( F_342 ( V_15 -> V_5 ) ) {
V_228 = F_343 ( V_15 -> V_5 ) ;
goto V_642;
}
V_15 -> V_578 = F_344 ( struct V_580 ) ;
if ( ! V_15 -> V_578 ) {
V_228 = - V_144 ;
goto V_642;
}
V_689 = F_345 ( V_685 ) ;
if ( V_689 && F_307 ( V_689 ) ) {
V_690 = L_43 ;
F_87 ( V_229 -> V_266 , V_689 ) ;
} else {
F_294 ( V_15 , V_691 ) ;
if ( F_307 ( V_691 ) ) {
V_690 = L_44 ;
F_87 ( V_229 -> V_266 , V_691 ) ;
} else {
V_690 = L_45 ;
F_346 ( V_229 ) ;
}
}
V_15 -> V_504 = V_625 ;
V_15 -> V_495 = V_624 ;
V_15 -> V_229 = V_229 ;
F_347 ( V_229 , & V_227 -> V_229 ) ;
V_228 = F_328 ( V_15 ) ;
if ( V_228 < 0 ) {
F_104 ( & V_227 -> V_229 , L_46 , V_17 ) ;
goto V_704;
}
F_327 ( V_15 ) ;
F_348 ( V_229 , & V_15 -> V_521 , F_280 , V_705 ) ;
V_692 = V_706 | V_707 ;
V_229 -> V_692 = V_692 | V_708 ;
V_229 -> V_709 |= V_692 | V_708 | V_710 ;
V_229 -> V_711 |= V_692 ;
V_228 = F_349 ( V_229 ) ;
if ( V_228 < 0 ) {
F_104 ( & V_227 -> V_229 , L_47 ) ;
goto V_712;
}
F_292 ( V_229 , L_48 , V_690 , V_229 -> V_266 ) ;
* V_686 += V_355 ;
V_2 -> V_713 [ V_17 ] = V_15 ;
return 0 ;
V_712:
for ( V_22 = 0 ; V_22 < V_409 ; V_22 ++ )
F_332 ( V_15 -> V_411 [ V_22 ] -> V_452 ) ;
V_704:
F_332 ( V_15 -> V_578 ) ;
V_642:
F_350 ( V_15 -> V_519 ) ;
V_695:
F_351 ( V_229 ) ;
return V_228 ;
}
static void F_352 ( struct V_14 * V_15 )
{
int V_22 ;
F_353 ( V_15 -> V_229 ) ;
F_332 ( V_15 -> V_578 ) ;
for ( V_22 = 0 ; V_22 < V_409 ; V_22 ++ )
F_332 ( V_15 -> V_411 [ V_22 ] -> V_452 ) ;
F_350 ( V_15 -> V_519 ) ;
F_351 ( V_15 -> V_229 ) ;
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
for ( V_15 = 0 ; V_15 < V_185 ; V_15 ++ ) {
F_1 ( V_2 , F_359 ( V_15 ) ,
V_723 ) ;
F_1 ( V_2 , F_360 ( V_15 ) ,
V_724 ) ;
}
F_1 ( V_2 , V_725 ,
V_726 ) ;
F_1 ( V_2 , V_727 , 0x1 ) ;
}
static int F_361 ( struct V_226 * V_227 , struct V_1 * V_2 )
{
const struct V_714 * V_728 ;
int V_228 , V_22 ;
T_1 V_60 ;
if ( V_355 % 4 || ( V_355 > V_729 ) ||
( V_409 > V_19 ) ) {
F_104 ( & V_227 -> V_229 , L_49 ) ;
return - V_25 ;
}
V_728 = F_362 () ;
if ( V_728 )
F_354 ( V_728 , V_2 ) ;
V_60 = F_4 ( V_2 -> V_629 + V_730 ) ;
V_60 |= V_731 ;
F_2 ( V_60 , V_2 -> V_629 + V_730 ) ;
V_2 -> V_597 = F_75 ( & V_227 -> V_229 , F_197 () ,
sizeof( struct V_410 ) ,
V_94 ) ;
if ( ! V_2 -> V_597 )
return - V_144 ;
F_150 (i) {
V_2 -> V_597 [ V_22 ] . V_17 = V_22 ;
V_2 -> V_597 [ V_22 ] . V_9 = V_732 ;
V_228 = F_218 ( V_227 , & V_2 -> V_597 [ V_22 ] ,
V_732 , V_22 , V_2 ) ;
if ( V_228 < 0 )
return V_228 ;
}
F_358 ( V_2 ) ;
for ( V_22 = 0 ; V_22 < V_185 ; V_22 ++ )
F_1 ( V_2 , F_331 ( V_22 ) , V_355 ) ;
F_2 ( V_733 ,
V_2 -> V_629 + V_734 ) ;
F_1 ( V_2 , V_735 , 0x1 ) ;
V_228 = F_119 ( V_227 , V_2 ) ;
if ( V_228 < 0 )
return V_228 ;
V_228 = F_79 ( V_227 , V_2 ) ;
if ( V_228 < 0 )
return V_228 ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_363 ( struct V_226 * V_227 )
{
struct V_684 * V_736 = V_227 -> V_229 . V_737 ;
struct V_684 * V_685 ;
struct V_1 * V_2 ;
struct V_687 * V_688 ;
int V_738 , V_292 ;
int V_228 ;
V_2 = F_329 ( & V_227 -> V_229 , sizeof( struct V_1 ) , V_94 ) ;
if ( ! V_2 )
return - V_144 ;
V_688 = F_340 ( V_227 , V_703 , 0 ) ;
V_2 -> V_5 = F_341 ( & V_227 -> V_229 , V_688 ) ;
if ( F_342 ( V_2 -> V_5 ) )
return F_343 ( V_2 -> V_5 ) ;
V_688 = F_340 ( V_227 , V_703 , 1 ) ;
V_2 -> V_629 = F_341 ( & V_227 -> V_229 , V_688 ) ;
if ( F_342 ( V_2 -> V_629 ) )
return F_343 ( V_2 -> V_629 ) ;
V_2 -> V_739 = F_364 ( & V_227 -> V_229 , L_50 ) ;
if ( F_342 ( V_2 -> V_739 ) )
return F_343 ( V_2 -> V_739 ) ;
V_228 = F_365 ( V_2 -> V_739 ) ;
if ( V_228 < 0 )
return V_228 ;
V_2 -> V_740 = F_364 ( & V_227 -> V_229 , L_51 ) ;
if ( F_342 ( V_2 -> V_740 ) ) {
V_228 = F_343 ( V_2 -> V_740 ) ;
goto V_741;
}
V_228 = F_365 ( V_2 -> V_740 ) ;
if ( V_228 < 0 )
goto V_741;
V_2 -> V_397 = F_366 ( V_2 -> V_739 ) ;
V_228 = F_361 ( V_227 , V_2 ) ;
if ( V_228 < 0 ) {
F_104 ( & V_227 -> V_229 , L_52 ) ;
goto V_742;
}
V_738 = F_367 ( V_736 ) ;
if ( V_738 == 0 ) {
F_104 ( & V_227 -> V_229 , L_53 ) ;
V_228 = - V_634 ;
goto V_742;
}
V_2 -> V_713 = F_75 ( & V_227 -> V_229 , V_738 ,
sizeof( struct V_14 * ) ,
V_94 ) ;
if ( ! V_2 -> V_713 ) {
V_228 = - V_144 ;
goto V_742;
}
V_292 = 0 ;
F_368 (dn, port_node) {
V_228 = F_333 ( V_227 , V_685 , V_2 , & V_292 ) ;
if ( V_228 < 0 )
goto V_742;
}
F_369 ( V_227 , V_2 ) ;
return 0 ;
V_742:
F_370 ( V_2 -> V_740 ) ;
V_741:
F_370 ( V_2 -> V_739 ) ;
return V_228 ;
}
static int F_371 ( struct V_226 * V_227 )
{
struct V_1 * V_2 = F_372 ( V_227 ) ;
struct V_684 * V_736 = V_227 -> V_229 . V_737 ;
struct V_684 * V_685 ;
int V_22 = 0 ;
F_368 (dn, port_node) {
if ( V_2 -> V_713 [ V_22 ] )
F_352 ( V_2 -> V_713 [ V_22 ] ) ;
V_22 ++ ;
}
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
struct V_297 * V_298 = & V_2 -> V_316 [ V_22 ] ;
F_116 ( V_227 , V_2 , V_298 ) ;
}
F_150 (i) {
struct V_410 * V_441 = & V_2 -> V_597 [ V_22 ] ;
F_103 ( & V_227 -> V_229 ,
V_732 * V_492 ,
V_441 -> V_412 ,
V_441 -> V_493 ) ;
}
F_370 ( V_2 -> V_739 ) ;
F_370 ( V_2 -> V_740 ) ;
return 0 ;
}
