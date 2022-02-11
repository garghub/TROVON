static inline int F_1 ( unsigned int V_1 )
{
if ( V_1 == 2 )
return 0 ;
else
return V_2 + 2 - V_1 ;
}
static void F_2 ( const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_7 ;
unsigned char V_8 ;
unsigned int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_6 -> V_8 ) ; V_9 ++ ) {
V_8 = V_6 -> V_8 [ V_9 ] ;
V_10 = F_5 ( V_9 ) ;
if ( V_8 & V_11 ) {
if ( V_6 -> V_12 & V_13 ) {
if ( V_9 > 0 )
continue;
F_6 ( V_4 , L_1
L_2 , V_10 ) ;
} else {
F_6 ( V_4 ,
L_3 ,
V_10 , V_8 & V_14 ?
L_4 : L_5 ,
V_8 & V_15 ?
L_6 : L_7 ) ;
}
if ( V_8 & V_15 )
V_7 = V_16 ;
else
V_7 = 0 ;
if ( V_8 & V_14 )
V_7 |= V_17 ;
F_7 ( V_6 , V_18 [ V_10 ] . V_19 , V_7 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_21 | V_22 |
V_23 | V_24 ) ;
if ( V_8 & V_14 )
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_27 |
V_28 | V_29 ) ;
else
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_30 |
V_28 | V_29 ) ;
} else {
F_6 ( V_4 , L_1
L_8 , V_10 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_29 | V_28 |
V_31 | V_26 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_32 | V_22 |
V_33 | V_24 ) ;
}
}
}
static void F_8 ( const struct V_5 * V_6 )
{
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_6 -> V_8 ) ; V_9 ++ ) {
V_10 = F_5 ( V_9 ) ;
if ( V_6 -> V_8 [ V_9 ] & V_11 ) {
if ( V_9 > 0 && V_6 -> V_12 & V_13 )
continue;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_30 |
V_28 | V_29 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_32 | V_22 |
V_33 | V_24 ) ;
} else {
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_29 | V_28 |
V_31 | V_26 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_32 | V_22 |
V_33 | V_24 ) ;
}
}
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_7 ( V_6 , V_34 , V_35 | V_36 ) ;
V_6 -> V_37 . V_38 = V_39 ;
F_10 ( V_6 , V_40 ) ;
F_7 ( V_6 , V_41 , 0 ) ;
F_8 ( V_6 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_10 ( V_6 , V_40 ) ;
F_7 ( V_6 , V_41 , V_42 ) ;
F_2 ( V_4 ) ;
F_7 ( V_6 , V_34 , V_6 -> V_12 ) ;
V_6 -> V_37 . V_38 = V_43 ;
}
static void F_12 ( struct V_5 * V_6 )
{
int V_10 , V_44 , V_45 ;
F_7 ( V_6 , V_34 , ( V_35 | V_36 ) ) ;
F_7 ( V_6 , V_46 , V_6 -> V_46 ) ;
F_7 ( V_6 , V_47 , V_6 -> V_47 ) ;
F_7 ( V_6 , V_48 , V_6 -> V_48 ) ;
F_10 ( V_6 , V_40 ) ;
F_7 ( V_6 , V_41 , 0 ) ;
for ( V_10 = V_49 ; V_10 <= V_2 ; V_10 ++ ) {
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_50 | V_33 |
V_22 | V_32 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_24 | V_33 |
V_22 | V_32 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_30 |
V_28 | V_29 ) ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ )
F_7 ( V_6 , V_18 [ V_10 ] . V_45 [ V_45 ] , 0 ) ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ )
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ V_44 ] , 0 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_19 , 0 ) ;
}
F_7 ( V_6 , V_51 [ 0 ] , 0 ) ;
F_7 ( V_6 , V_51 [ 1 ] , 0 ) ;
F_7 ( V_6 , V_52 [ 0 ] , 0 ) ;
F_7 ( V_6 , V_52 [ 1 ] , 0 ) ;
F_7 ( V_6 , V_52 [ 2 ] , 0 ) ;
F_7 ( V_6 , V_52 [ 3 ] , 0 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_7 ( V_6 , V_34 , V_35 | V_13 | V_36 ) ;
F_7 ( V_6 , V_47 , V_6 -> V_47 ) ;
if ( F_10 ( V_6 , V_47 ) & V_53 ) {
F_14 ( V_4 , L_9 ,
V_6 -> V_54 ) ;
return - V_55 ;
}
F_7 ( V_6 , V_18 [ 1 ] . V_45 [ 1 ] , 0x25 ) ;
F_7 ( V_6 , V_18 [ 2 ] . V_45 [ 3 ] , 0x52 ) ;
F_7 ( V_6 , V_18 [ 10 ] . V_45 [ 6 ] , 0xc3 ) ;
if ( ( F_10 ( V_6 , V_18 [ 1 ] . V_45 [ 1 ] ) != 0x25 ) ||
( F_10 ( V_6 , V_18 [ 2 ] . V_45 [ 3 ] ) != 0x52 ) ||
( F_10 ( V_6 , V_18 [ 10 ] . V_45 [ 6 ] ) != 0xc3 ) ) {
F_14 ( V_4 , L_10 ,
V_6 -> V_54 ) ;
return - V_55 ;
}
if ( F_10 ( V_6 , V_34 ) & V_13 )
V_6 -> V_12 |= V_13 ;
return 0 ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
if ( V_6 -> V_37 . V_38 != V_39 )
F_9 ( V_4 ) ;
F_11 ( V_4 ) ;
}
static int F_16 ( struct V_3 * V_4 , enum V_56 V_57 )
{
switch ( V_57 ) {
case V_58 :
F_15 ( V_4 ) ;
F_17 ( V_4 ) ;
break;
default:
return - V_59 ;
}
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_60 * V_61 = & V_6 -> V_37 . V_62 ;
T_1 V_63 , V_64 ;
V_63 = ( ( V_61 -> V_65 - 1 ) & 0x3f ) | ( ( ( V_61 -> V_66 - 1 ) & 0x3 ) << 6 ) ;
V_64 = ( ( V_61 -> V_67 + V_61 -> V_68 - 1 ) & 0xf ) |
( ( ( V_61 -> V_69 - 1 ) & 0x7 ) << 4 ) ;
if ( V_6 -> V_37 . V_70 & V_71 )
V_64 |= 0x80 ;
F_14 ( V_4 , L_11 , V_63 , V_64 ) ;
F_7 ( V_6 , V_72 , V_63 ) ;
F_7 ( V_6 , V_73 , V_64 ) ;
return 0 ;
}
static int F_19 ( const struct V_3 * V_4 ,
struct V_74 * V_75 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_75 -> V_76 = F_10 ( V_6 , V_77 ) ;
V_75 -> V_78 = F_10 ( V_6 , V_79 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_80 * V_81 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_82 * V_83 = & V_4 -> V_83 ;
struct V_84 * V_85 = (struct V_84 * ) V_81 -> V_45 ;
unsigned int V_10 = F_5 ( V_86 ) ;
T_1 V_87 , V_88 ;
T_3 V_44 ;
int V_89 ;
if ( F_21 ( V_4 , V_81 ) )
return V_90 ;
if ( ( F_10 ( V_6 ,
V_18 [ V_10 ] . V_25 ) & V_91 ) == V_92 ) {
F_22 ( V_4 , L_12 ) ;
return V_93 ;
}
F_23 ( V_4 ) ;
V_87 = V_85 -> V_94 ;
V_44 = V_85 -> V_95 ;
if ( V_85 -> V_95 & V_96 )
V_88 = 0 ;
else
V_88 = V_17 ;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_29 | V_28 | V_27 | V_26 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_21 | V_97 | V_33 | V_24 ) ;
if ( V_44 & V_98 ) {
V_44 &= V_99 ;
F_7 ( V_6 , V_18 [ V_10 ] . V_19 ,
( V_87 << 4 ) | V_88 | V_16 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ 3 ] , V_44 << 3 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ 2 ] , V_44 >> 5 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ 1 ] , V_44 >> 13 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ 0 ] , V_44 >> 21 ) ;
} else {
V_44 &= V_100 ;
F_7 ( V_6 , V_18 [ V_10 ] . V_19 , ( V_87 << 4 ) | V_88 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ 0 ] , V_44 >> 3 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_44 [ 1 ] , V_44 << 5 ) ;
}
for ( V_89 = 0 ; V_89 < V_87 ; V_89 ++ )
F_7 ( V_6 , V_18 [ V_10 ] . V_45 [ V_89 ] , V_85 -> V_45 [ V_89 ] ) ;
F_24 ( V_81 , V_4 , 0 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_29 | V_92 | V_31 | V_101 ) ;
V_83 -> V_102 += V_87 ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_103 | V_104 | V_105 | V_24 ) ;
return V_90 ;
}
static void F_25 ( struct V_3 * V_4 , unsigned int V_10 , T_1 V_25 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_82 * V_83 = & V_4 -> V_83 ;
struct V_84 * V_85 ;
struct V_80 * V_81 ;
T_1 V_19 ;
T_3 V_44 ;
int V_89 ;
V_81 = F_26 ( V_4 , & V_85 ) ;
if ( ! V_81 )
return;
V_19 = F_10 ( V_6 , V_18 [ V_10 ] . V_19 ) ;
if ( V_25 & V_106 ) {
V_85 -> V_95 = V_96 ;
if ( V_19 & V_16 )
V_85 -> V_95 |= V_98 ;
V_85 -> V_94 = 0 ;
} else {
if ( V_19 & V_16 ) {
V_44 = F_10 ( V_6 , V_18 [ V_10 ] . V_44 [ 3 ] ) ;
V_44 |= F_10 ( V_6 , V_18 [ V_10 ] . V_44 [ 2 ] ) << 8 ;
V_44 |= F_10 ( V_6 , V_18 [ V_10 ] . V_44 [ 1 ] ) << 16 ;
V_44 |= F_10 ( V_6 , V_18 [ V_10 ] . V_44 [ 0 ] ) << 24 ;
V_44 >>= 3 ;
V_44 |= V_98 ;
} else {
V_44 = F_10 ( V_6 , V_18 [ V_10 ] . V_44 [ 1 ] ) ;
V_44 |= F_10 ( V_6 , V_18 [ V_10 ] . V_44 [ 0 ] ) << 8 ;
V_44 >>= 5 ;
}
V_85 -> V_95 = V_44 ;
V_85 -> V_94 = F_27 ( ( V_19 & 0xf0 ) >> 4 ) ;
for ( V_89 = 0 ; V_89 < V_85 -> V_94 ; V_89 ++ )
V_85 -> V_45 [ V_89 ] = F_10 ( V_6 , V_18 [ V_10 ] . V_45 [ V_89 ] ) ;
}
V_83 -> V_107 ++ ;
V_83 -> V_108 += V_85 -> V_94 ;
F_28 ( V_81 ) ;
}
static int F_29 ( struct V_3 * V_4 , T_1 V_41 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_82 * V_83 = & V_4 -> V_83 ;
struct V_84 * V_85 ;
struct V_80 * V_81 ;
T_1 V_109 ;
F_6 ( V_4 , L_13 , V_41 ) ;
V_81 = F_30 ( V_4 , & V_85 ) ;
if ( ! V_81 )
return - V_110 ;
if ( V_6 -> V_12 & V_13 ) {
V_85 -> V_45 [ 6 ] = F_10 ( V_6 , V_77 ) ;
V_85 -> V_45 [ 7 ] = F_10 ( V_6 , V_79 ) ;
}
if ( V_41 & V_111 ) {
F_7 ( V_6 , V_34 , V_36 ) ;
V_85 -> V_95 |= V_112 ;
V_6 -> V_37 . V_38 = V_113 ;
V_6 -> V_37 . V_114 . V_115 ++ ;
F_31 ( V_4 ) ;
} else if ( V_41 & V_116 ) {
V_85 -> V_95 |= V_117 ;
if ( V_85 -> V_45 [ 7 ] > 127 ) {
V_85 -> V_45 [ 1 ] = V_118 |
V_119 ;
V_6 -> V_37 . V_38 = V_120 ;
V_6 -> V_37 . V_114 . V_121 ++ ;
} else {
V_85 -> V_45 [ 1 ] = V_122 |
V_123 ;
V_6 -> V_37 . V_38 = V_124 ;
V_6 -> V_37 . V_114 . V_125 ++ ;
}
} else {
V_85 -> V_95 |= V_126 ;
V_85 -> V_45 [ 2 ] = V_127 ;
V_6 -> V_37 . V_38 = V_43 ;
}
V_109 = V_41 & V_42 ;
if ( V_109 < 7 && V_109 > 0 ) {
if ( V_109 == V_128 ) {
V_85 -> V_95 |= V_129 ;
} else {
V_85 -> V_95 |= V_126 ;
switch ( V_109 ) {
case V_130 :
V_85 -> V_45 [ 2 ] |= V_131 ;
break;
case V_132 :
V_85 -> V_45 [ 2 ] |= V_133 ;
break;
case V_134 :
V_85 -> V_45 [ 2 ] |= V_135 ;
break;
case V_136 :
V_85 -> V_45 [ 2 ] |= V_137 ;
break;
case V_138 :
V_85 -> V_45 [ 3 ] = V_139 ;
break;
}
}
}
V_83 -> V_107 ++ ;
V_83 -> V_108 += V_85 -> V_94 ;
F_28 ( V_81 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_41 ;
V_41 = F_10 ( V_6 , V_41 ) ;
F_7 ( V_6 , V_41 , V_42 ) ;
if ( V_41 & ( V_116 | V_111 ) ||
( V_41 & V_42 ) != V_42 ) {
F_29 ( V_4 , V_41 ) ;
return V_41 & V_111 ;
}
return 0 ;
}
static void F_33 ( struct V_3 * V_4 , unsigned int V_9 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_82 * V_83 = & V_4 -> V_83 ;
unsigned int V_10 = F_5 ( V_9 ) ;
T_1 V_25 ;
int V_140 = V_141 ;
while ( V_140 -- ) {
V_25 = F_10 ( V_6 , V_18 [ V_10 ] . V_25 ) ;
if ( ! ( V_25 & V_142 ) ) {
if ( V_6 -> V_12 & V_13 ) {
if ( ! ( F_10 ( V_6 , V_18 [ V_10 ] . V_20 ) &
V_143 ) )
break;
} else {
break;
}
}
if ( V_25 & V_144 ) {
V_83 -> V_145 ++ ;
V_83 -> V_146 ++ ;
}
if ( V_10 < V_2 )
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_30 |
V_91 | V_147 ) ;
F_25 ( V_4 , V_10 , V_25 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_21 | V_22 |
V_23 | V_24 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_30 |
V_28 | V_29 ) ;
}
}
static void F_34 ( struct V_3 * V_4 , unsigned int V_9 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned int V_10 = F_5 ( V_9 ) ;
T_1 V_20 , V_25 ;
int V_140 = V_141 ;
while ( V_140 -- ) {
V_20 = F_10 ( V_6 , V_18 [ V_10 ] . V_20 ) ;
if ( ! ( V_20 & V_143 ) )
break;
V_25 = F_10 ( V_6 , V_18 [ V_10 ] . V_25 ) ;
F_25 ( V_4 , V_10 , V_25 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_21 | V_22 |
V_23 | V_24 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_25 ,
V_26 | V_27 |
V_28 | V_29 ) ;
}
}
static void F_35 ( struct V_3 * V_4 , unsigned int V_9 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_82 * V_83 = & V_4 -> V_83 ;
unsigned int V_10 = F_5 ( V_9 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_32 | V_22 | V_33 | V_24 ) ;
F_7 ( V_6 , V_18 [ V_10 ] . V_20 ,
V_103 | V_104 | V_105 | V_24 ) ;
V_83 -> V_148 ++ ;
F_36 ( V_4 , 0 ) ;
F_17 ( V_4 ) ;
}
static T_4 F_37 ( int V_149 , void * V_150 )
{
struct V_3 * V_4 = (struct V_3 * ) V_150 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_1 ;
int V_9 , V_140 = 0 ;
if ( V_6 -> V_37 . V_38 == V_39 )
return V_151 ;
if ( V_6 -> V_152 )
V_6 -> V_152 ( V_6 ) ;
while ( V_140 < V_153 ) {
V_1 = F_10 ( V_6 , V_40 ) ;
if ( ! V_1 )
break;
V_140 ++ ;
if ( V_1 == 1 ) {
if ( F_32 ( V_4 ) )
break;
} else {
V_9 = F_1 ( V_1 ) ;
if ( V_9 >= V_154 ) {
F_22 ( V_4 , L_14 ,
V_1 ) ;
continue;
}
if ( V_6 -> V_8 [ V_9 ] & V_14 )
F_34 ( V_4 , V_9 ) ;
else if ( V_6 -> V_8 [ V_9 ] & V_11 )
F_33 ( V_4 , V_9 ) ;
else
F_35 ( V_4 , V_9 ) ;
}
}
if ( V_6 -> V_155 )
V_6 -> V_155 ( V_6 ) ;
if ( V_140 >= V_153 )
F_6 ( V_4 , L_15 , V_140 ) ;
return ( V_140 ) ? V_156 : V_151 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_157 ;
F_9 ( V_4 ) ;
V_157 = F_39 ( V_4 ) ;
if ( V_157 )
return V_157 ;
V_157 = F_40 ( V_4 -> V_149 , & F_37 , V_6 -> V_158 ,
V_4 -> V_159 , V_4 ) ;
if ( V_157 ) {
F_41 ( V_4 ) ;
return - V_160 ;
}
F_15 ( V_4 ) ;
F_42 ( V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 )
{
F_23 ( V_4 ) ;
F_9 ( V_4 ) ;
F_44 ( V_4 -> V_149 , V_4 ) ;
F_41 ( V_4 ) ;
return 0 ;
}
struct V_3 * F_45 ( int V_161 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_46 ( sizeof( struct V_5 ) + V_161 ,
V_162 ) ;
if ( ! V_4 )
return NULL ;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_37 . V_163 = & V_164 ;
V_6 -> V_37 . V_165 = F_18 ;
V_6 -> V_37 . V_166 = F_16 ;
V_6 -> V_37 . V_167 = V_71 ;
memcpy ( V_6 -> V_8 , V_168 , sizeof( V_168 ) ) ;
if ( V_161 )
V_6 -> V_6 = ( void * ) V_6 + sizeof( struct V_5 ) ;
return V_4 ;
}
void F_47 ( struct V_3 * V_4 )
{
F_48 ( V_4 ) ;
}
int F_49 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_157 ;
V_157 = F_13 ( V_4 ) ;
if ( V_157 )
return V_157 ;
V_4 -> V_169 = & V_170 ;
V_4 -> V_171 |= V_172 ;
if ( ! V_173 && V_6 -> V_12 & V_13 ) {
V_6 -> V_37 . V_174 = F_19 ;
V_6 -> V_12 = V_175 | V_13 | V_176 ;
F_6 ( V_4 , L_16 ) ;
} else {
V_6 -> V_12 = V_175 | V_176 ;
F_6 ( V_4 , L_17 ) ;
}
F_12 ( V_6 ) ;
F_9 ( V_4 ) ;
return F_50 ( V_4 ) ;
}
void F_51 ( struct V_3 * V_4 )
{
F_9 ( V_4 ) ;
F_52 ( V_4 ) ;
}
static T_5 int F_53 ( void )
{
if ( V_177 ) {
V_168 [ V_178 ] |= V_15 ;
V_168 [ V_179 ] &= ~ V_15 ;
}
F_54 ( L_18 ) ;
return 0 ;
}
static T_6 void F_55 ( void )
{
F_54 ( L_19 ) ;
}
