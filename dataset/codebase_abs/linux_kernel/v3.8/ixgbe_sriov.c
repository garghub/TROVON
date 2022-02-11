void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 , V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
V_11 = F_2 ( V_2 -> V_12 ) ;
if ( ! V_11 && ! V_2 -> V_13 )
return;
if ( V_11 ) {
V_2 -> V_13 = V_11 ;
F_3 ( & V_2 -> V_12 -> V_14 , L_1
L_2
L_3 ) ;
} else {
int V_15 ;
V_2 -> V_13 = F_4 (unsigned int, adapter->num_vfs, 63 ) ;
V_15 = F_5 ( V_2 -> V_12 , V_2 -> V_13 ) ;
if ( V_15 ) {
F_6 ( V_16 , L_4 , V_15 ) ;
V_2 -> V_13 = 0 ;
return;
}
}
V_2 -> V_17 |= V_18 ;
F_7 ( V_16 , L_5 , V_2 -> V_13 ) ;
V_2 -> V_17 |= V_19 ;
if ( ! V_2 -> V_20 [ V_21 ] . V_22 )
V_2 -> V_20 [ V_21 ] . V_22 = 1 ;
V_2 -> V_20 [ V_21 ] . V_23 = V_2 -> V_13 ;
V_7 = V_6 -> V_24 . V_25 -
( V_26 + 1 + V_2 -> V_13 ) ;
V_2 -> V_10 = V_10 = F_8 ( V_7 ,
sizeof( struct V_9 ) ,
V_27 ) ;
if ( V_10 ) {
F_9 ( & V_2 -> V_28 . V_29 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_10 -> V_30 = - 1 ;
V_10 -> free = true ;
V_10 -> V_31 = V_6 -> V_24 . V_25 -
( V_8 + V_2 -> V_13 + 1 ) ;
F_10 ( & V_10 -> V_29 , & V_2 -> V_28 . V_29 ) ;
V_10 ++ ;
}
}
F_11 ( V_6 , V_32 , V_33 ) ;
V_2 -> V_34 |= V_35 ;
V_2 -> V_36 =
F_8 ( V_2 -> V_13 ,
sizeof( struct V_37 ) , V_27 ) ;
if ( V_2 -> V_36 ) {
F_12 ( V_6 ) ;
memcpy ( & V_6 -> V_38 . V_39 , V_4 -> V_40 , sizeof( V_6 -> V_38 . V_39 ) ) ;
if ( ( V_2 -> V_6 . V_24 . type == V_41 ) &&
( V_2 -> V_13 < 16 ) ) {
V_2 -> V_42 . V_43 . V_44 = V_45 ;
V_2 -> V_42 . V_43 . V_46 = V_45 ;
} else if ( V_2 -> V_13 < 32 ) {
V_2 -> V_42 . V_43 . V_44 = 4 ;
V_2 -> V_42 . V_43 . V_46 = 4 ;
} else {
V_2 -> V_42 . V_43 . V_44 = 1 ;
V_2 -> V_42 . V_43 . V_46 = 1 ;
}
V_2 -> V_20 [ V_47 ] . V_22 = 1 ;
V_2 -> V_34 &= ~ ( V_48 |
V_49 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ )
V_2 -> V_36 [ V_8 ] . V_50 = true ;
return;
}
F_6 ( V_16 , L_6
L_7 ) ;
F_13 ( V_2 ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_51 * V_12 = V_2 -> V_12 ;
struct V_51 * V_52 ;
int V_53 ;
switch ( V_2 -> V_6 . V_24 . type ) {
case V_41 :
V_53 = V_54 ;
break;
case V_55 :
V_53 = V_56 ;
break;
default:
return false ;
}
V_52 = F_15 ( V_57 , V_53 , NULL ) ;
while ( V_52 ) {
if ( V_52 -> V_58 && V_52 -> V_59 == V_12 ) {
if ( V_52 -> V_60 & V_61 )
return true ;
}
V_52 = F_15 ( V_57 , V_53 , V_52 ) ;
}
return false ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_62 ;
T_1 V_63 ;
V_2 -> V_13 = 0 ;
F_16 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
F_16 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
if ( ! ( V_2 -> V_17 & V_18 ) )
return;
#ifdef F_17
if ( F_14 ( V_2 ) ) {
F_18 ( L_8 ) ;
return;
}
F_19 ( V_2 -> V_12 ) ;
#endif
F_11 ( V_6 , V_64 , 0 ) ;
V_62 = F_20 ( V_6 , V_65 ) ;
V_62 &= ~ V_66 ;
F_11 ( V_6 , V_65 , V_62 ) ;
V_63 = F_20 ( V_6 , V_67 ) ;
V_63 &= ~ V_68 ;
F_11 ( V_6 , V_67 , V_63 ) ;
F_21 ( V_6 ) ;
if ( V_2 -> V_20 [ V_21 ] . V_22 == 1 )
V_2 -> V_17 &= ~ V_19 ;
V_2 -> V_20 [ V_21 ] . V_23 = 0 ;
F_22 ( 100 ) ;
V_2 -> V_17 &= ~ V_18 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 * V_69 , T_1 V_30 )
{
int V_70 = ( V_69 [ 0 ] & V_71 )
>> V_72 ;
T_2 * V_73 = ( T_2 * ) & V_69 [ 1 ] ;
struct V_37 * V_36 = & V_2 -> V_36 [ V_30 ] ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_8 ;
T_1 V_74 ;
T_1 V_75 ;
T_1 V_76 ;
V_70 = F_24 ( V_70 , V_77 ) ;
V_36 -> V_78 = V_70 ;
for ( V_8 = 0 ; V_8 < V_70 ; V_8 ++ ) {
V_36 -> V_79 [ V_8 ] = V_73 [ V_8 ] ;
}
for ( V_8 = 0 ; V_8 < V_36 -> V_78 ; V_8 ++ ) {
V_75 = ( V_36 -> V_79 [ V_8 ] >> 5 ) & 0x7F ;
V_74 = V_36 -> V_79 [ V_8 ] & 0x1F ;
V_76 = F_20 ( V_6 , F_25 ( V_75 ) ) ;
V_76 |= ( 1 << V_74 ) ;
F_11 ( V_6 , F_25 ( V_75 ) , V_76 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_80 * V_81 ;
struct V_9 * V_82 ;
F_27 (pos, &adapter->vf_mvs.l) {
V_82 = F_28 ( V_81 , struct V_9 , V_29 ) ;
if ( ! V_82 -> free )
V_6 -> V_24 . V_39 . V_83 ( V_6 , V_82 -> V_31 ,
V_82 -> V_84 ,
V_82 -> V_30 , V_85 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_37 * V_36 ;
int V_8 , V_86 ;
T_1 V_74 ;
T_1 V_75 ;
T_1 V_76 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
V_36 = & V_2 -> V_36 [ V_8 ] ;
for ( V_86 = 0 ; V_86 < V_36 -> V_78 ; V_86 ++ ) {
V_6 -> V_87 . V_88 ++ ;
V_75 = ( V_36 -> V_79 [ V_86 ] >> 5 ) & 0x7F ;
V_74 = V_36 -> V_79 [ V_86 ] & 0x1F ;
V_76 = F_20 ( V_6 , F_25 ( V_75 ) ) ;
V_76 |= ( 1 << V_74 ) ;
F_11 ( V_6 , F_25 ( V_75 ) , V_76 ) ;
}
}
F_26 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , int V_89 , int V_90 ,
T_1 V_30 )
{
if ( ! V_90 && ! V_89 )
return 0 ;
return V_2 -> V_6 . V_24 . V_39 . V_91 ( & V_2 -> V_6 , V_90 , V_30 , ( bool ) V_89 ) ;
}
static T_3 F_31 ( struct V_1 * V_2 , T_1 * V_69 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_92 = V_69 [ 1 ] ;
T_1 V_93 ;
if ( V_2 -> V_6 . V_24 . type == V_41 ) {
struct V_94 * V_14 = V_2 -> V_95 ;
int V_96 = V_14 -> V_97 + V_98 ;
T_1 V_99 , V_100 , V_101 ;
T_3 V_15 = 0 ;
#ifdef F_32
if ( V_14 -> V_102 & V_103 )
V_96 = F_33 ( int , V_96 ,
V_104 ) ;
#endif
switch ( V_2 -> V_36 [ V_30 ] . V_105 ) {
case V_106 :
if ( V_96 > V_107 )
break;
default:
if ( ( V_96 > V_107 ) ||
( V_92 > ( V_107 + V_108 ) ) )
V_15 = - V_109 ;
break;
}
V_100 = V_30 % 32 ;
V_99 = V_30 / 32 ;
V_101 = F_20 ( V_6 , F_34 ( V_99 ) ) ;
if ( V_15 )
V_101 &= ~ ( 1 << V_100 ) ;
else
V_101 |= 1 << V_100 ;
F_11 ( V_6 , F_34 ( V_99 ) , V_101 ) ;
if ( V_15 ) {
F_6 ( V_110 , L_9 , V_92 ) ;
return V_15 ;
}
}
if ( V_92 > V_111 ) {
F_6 ( V_110 , L_9 , V_92 ) ;
return - V_109 ;
}
V_93 = F_20 ( V_6 , V_112 ) ;
V_93 &= V_113 ;
V_93 >>= V_114 ;
if ( V_93 < V_92 ) {
V_93 = V_92 << V_114 ;
F_11 ( V_6 , V_112 , V_93 ) ;
}
F_7 ( V_6 , L_10 , V_92 ) ;
return 0 ;
}
static void F_35 ( struct V_5 * V_6 , T_1 V_30 , bool V_115 )
{
T_1 V_116 = F_20 ( V_6 , F_36 ( V_30 ) ) ;
V_116 |= ( V_117 |
V_118 ) ;
if ( V_115 )
V_116 |= V_119 ;
else
V_116 &= ~ V_119 ;
F_11 ( V_6 , F_36 ( V_30 ) , V_116 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
T_2 V_90 , T_2 V_120 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_121 = V_90 | ( V_120 << V_122 ) | V_123 ;
F_11 ( V_6 , F_38 ( V_30 ) , V_121 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_11 ( V_6 , F_38 ( V_30 ) , 0 ) ;
}
static inline void F_40 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_37 * V_36 = & V_2 -> V_36 [ V_30 ] ;
int V_31 = V_6 -> V_24 . V_25 - ( V_30 + 1 ) ;
T_4 V_43 = F_41 ( V_2 -> V_95 ) ;
F_30 ( V_2 , true , V_36 -> V_124 , V_30 ) ;
F_35 ( V_6 , V_30 , ! V_36 -> V_124 ) ;
if ( ! V_36 -> V_124 && ! V_36 -> V_125 && ! V_43 ) {
F_39 ( V_2 , V_30 ) ;
} else {
if ( V_36 -> V_125 || ! V_43 )
F_37 ( V_2 , V_36 -> V_124 ,
V_36 -> V_125 , V_30 ) ;
else
F_37 ( V_2 , V_36 -> V_124 ,
V_2 -> V_126 , V_30 ) ;
if ( V_36 -> V_50 )
V_6 -> V_24 . V_39 . V_127 ( V_6 , true , V_30 ) ;
}
V_2 -> V_36 [ V_30 ] . V_78 = 0 ;
F_42 ( V_2 -> V_95 ) ;
V_6 -> V_24 . V_39 . V_128 ( V_6 , V_31 ) ;
V_2 -> V_36 [ V_30 ] . V_105 = V_129 ;
}
static int F_43 ( struct V_1 * V_2 ,
int V_30 , unsigned char * V_130 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_31 = V_6 -> V_24 . V_25 - ( V_30 + 1 ) ;
memcpy ( V_2 -> V_36 [ V_30 ] . V_131 , V_130 , 6 ) ;
V_6 -> V_24 . V_39 . V_83 ( V_6 , V_31 , V_130 , V_30 , V_85 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
int V_30 , int V_132 , unsigned char * V_130 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_80 * V_81 ;
struct V_9 * V_82 ;
if ( V_132 <= 1 ) {
F_27 (pos, &adapter->vf_mvs.l) {
V_82 = F_28 ( V_81 , struct V_9 , V_29 ) ;
if ( V_82 -> V_30 == V_30 ) {
V_82 -> V_30 = - 1 ;
V_82 -> free = true ;
V_82 -> V_133 = false ;
V_6 -> V_24 . V_39 . V_128 ( V_6 , V_82 -> V_31 ) ;
}
}
}
if ( ! V_132 )
return 0 ;
V_82 = NULL ;
F_27 (pos, &adapter->vf_mvs.l) {
V_82 = F_28 ( V_81 , struct V_9 , V_29 ) ;
if ( V_82 -> free )
break;
}
if ( ! V_82 || ! V_82 -> free )
return - V_134 ;
V_82 -> free = false ;
V_82 -> V_133 = true ;
V_82 -> V_30 = V_30 ;
memcpy ( V_82 -> V_84 , V_130 , V_135 ) ;
V_6 -> V_24 . V_39 . V_83 ( V_6 , V_82 -> V_31 , V_130 , V_30 , V_85 ) ;
return 0 ;
}
int F_45 ( struct V_51 * V_12 , unsigned int V_136 )
{
unsigned char V_137 [ 6 ] ;
struct V_1 * V_2 = F_46 ( V_12 ) ;
unsigned int V_138 = ( V_136 & 0x3f ) ;
bool V_139 = ( ( V_136 & 0x10000000U ) != 0 ) ;
if ( V_139 ) {
F_47 ( V_137 ) ;
F_7 ( V_16 , L_11 ,
V_138 , V_137 ) ;
memcpy ( V_2 -> V_36 [ V_138 ] . V_131 , V_137 , 6 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned char * V_140 = V_2 -> V_36 [ V_30 ] . V_131 ;
T_1 V_141 , V_69 [ 4 ] ;
T_1 V_99 , V_100 ;
T_4 * V_142 = ( T_4 * ) ( & V_69 [ 1 ] ) ;
F_7 ( V_16 , L_12 , V_30 ) ;
F_40 ( V_2 , V_30 ) ;
F_43 ( V_2 , V_30 , V_140 ) ;
V_100 = V_30 % 32 ;
V_99 = V_30 / 32 ;
V_141 = F_20 ( V_6 , F_49 ( V_99 ) ) ;
V_141 |= 1 << V_100 ;
F_11 ( V_6 , F_49 ( V_99 ) , V_141 ) ;
V_141 = F_20 ( V_6 , F_34 ( V_99 ) ) ;
V_141 |= 1 << V_100 ;
if ( V_2 -> V_6 . V_24 . type == V_41 ) {
struct V_94 * V_14 = V_2 -> V_95 ;
int V_96 = V_14 -> V_97 + V_98 ;
#ifdef F_32
if ( V_14 -> V_102 & V_103 )
V_96 = F_33 ( int , V_96 ,
V_104 ) ;
#endif
if ( V_96 > V_107 )
V_141 &= ~ ( 1 << V_100 ) ;
}
F_11 ( V_6 , F_34 ( V_99 ) , V_141 ) ;
V_2 -> V_36 [ V_30 ] . V_143 = true ;
V_141 = F_20 ( V_6 , F_50 ( V_99 ) ) ;
V_141 |= ( 1 << V_100 ) ;
F_11 ( V_6 , F_50 ( V_99 ) , V_141 ) ;
V_69 [ 0 ] = V_144 | V_145 ;
memcpy ( V_142 , V_140 , V_135 ) ;
V_69 [ 3 ] = V_6 -> V_24 . V_146 ;
F_51 ( V_6 , V_69 , V_147 , V_30 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
T_1 * V_69 , T_1 V_30 )
{
T_4 * V_148 = ( ( T_4 * ) ( & V_69 [ 1 ] ) ) ;
if ( ! F_53 ( V_148 ) ) {
F_54 ( V_110 , L_13 , V_30 ) ;
return - 1 ;
}
if ( V_2 -> V_36 [ V_30 ] . V_149 &&
memcmp ( V_2 -> V_36 [ V_30 ] . V_131 , V_148 ,
V_135 ) ) {
F_54 ( V_110 ,
L_14
L_15 ,
V_30 ) ;
return - 1 ;
}
return F_43 ( V_2 , V_30 , V_148 ) < 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
T_1 * V_69 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_89 = ( V_69 [ 0 ] & V_71 ) >> V_72 ;
int V_90 = ( V_69 [ 1 ] & V_150 ) ;
int V_15 ;
T_4 V_151 = F_41 ( V_2 -> V_95 ) ;
if ( V_2 -> V_36 [ V_30 ] . V_124 || V_151 ) {
F_54 ( V_110 ,
L_16
L_15 ,
V_30 ) ;
return - 1 ;
}
if ( V_89 )
V_2 -> V_36 [ V_30 ] . V_152 ++ ;
else if ( V_2 -> V_36 [ V_30 ] . V_152 )
V_2 -> V_36 [ V_30 ] . V_152 -- ;
V_15 = F_30 ( V_2 , V_89 , V_90 , V_30 ) ;
if ( ! V_15 && V_2 -> V_36 [ V_30 ] . V_50 )
V_6 -> V_24 . V_39 . V_127 ( V_6 , true , V_30 ) ;
return V_15 ;
}
static int F_56 ( struct V_1 * V_2 ,
T_1 * V_69 , T_1 V_30 )
{
T_4 * V_148 = ( ( T_4 * ) ( & V_69 [ 1 ] ) ) ;
int V_132 = ( V_69 [ 0 ] & V_71 ) >>
V_72 ;
int V_15 ;
if ( V_2 -> V_36 [ V_30 ] . V_149 && V_132 > 0 ) {
F_54 ( V_110 ,
L_17 ,
V_30 ) ;
return - 1 ;
}
if ( V_132 ) {
if ( ! F_53 ( V_148 ) ) {
F_54 ( V_110 , L_13 , V_30 ) ;
return - 1 ;
}
if ( V_2 -> V_36 [ V_30 ] . V_50 )
F_57 ( V_2 -> V_95 , V_30 , false ) ;
}
V_15 = F_44 ( V_2 , V_30 , V_132 , V_148 ) ;
if ( V_15 == - V_134 )
F_54 ( V_110 ,
L_18 ,
V_30 ) ;
return V_15 < 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
T_1 * V_69 , T_1 V_30 )
{
int V_153 = V_69 [ 1 ] ;
switch ( V_153 ) {
case V_129 :
case V_106 :
V_2 -> V_36 [ V_30 ] . V_105 = V_153 ;
return 0 ;
default:
break;
}
F_7 ( V_110 , L_19 , V_30 , V_153 ) ;
return - 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_1 * V_69 , T_1 V_30 )
{
struct V_94 * V_14 = V_2 -> V_95 ;
struct V_154 * V_155 = & V_2 -> V_20 [ V_21 ] ;
unsigned int V_156 = 0 ;
T_4 V_43 = F_41 ( V_14 ) ;
switch ( V_2 -> V_36 [ V_30 ] . V_105 ) {
case V_157 :
case V_106 :
break;
default:
return - 1 ;
}
V_69 [ V_158 ] = F_60 ( 1 , ~ V_155 -> V_159 ) ;
V_69 [ V_160 ] = F_60 ( 1 , ~ V_155 -> V_159 ) ;
if ( V_43 > 1 )
V_156 = F_61 ( V_14 , V_2 -> V_126 ) ;
if ( V_43 )
V_69 [ V_161 ] = V_43 ;
else if ( V_2 -> V_36 [ V_30 ] . V_124 || V_2 -> V_36 [ V_30 ] . V_125 )
V_69 [ V_161 ] = 1 ;
else
V_69 [ V_161 ] = 0 ;
V_69 [ V_162 ] = V_156 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_163 = V_164 ;
T_1 V_69 [ V_164 ] ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_3 V_165 ;
V_165 = F_63 ( V_6 , V_69 , V_163 , V_30 ) ;
if ( V_165 ) {
F_64 ( L_20 ) ;
return V_165 ;
}
if ( V_69 [ 0 ] & ( V_145 | V_166 ) )
return V_165 ;
F_21 ( V_6 ) ;
if ( V_69 [ 0 ] == V_144 )
return F_48 ( V_2 , V_30 ) ;
if ( ! V_2 -> V_36 [ V_30 ] . V_143 ) {
V_69 [ 0 ] |= V_166 ;
F_51 ( V_6 , V_69 , 1 , V_30 ) ;
return V_165 ;
}
switch ( ( V_69 [ 0 ] & 0xFFFF ) ) {
case V_167 :
V_165 = F_52 ( V_2 , V_69 , V_30 ) ;
break;
case V_168 :
V_165 = F_23 ( V_2 , V_69 , V_30 ) ;
break;
case V_169 :
V_165 = F_55 ( V_2 , V_69 , V_30 ) ;
break;
case V_170 :
V_165 = F_31 ( V_2 , V_69 , V_30 ) ;
break;
case V_171 :
V_165 = F_56 ( V_2 , V_69 , V_30 ) ;
break;
case V_172 :
V_165 = F_58 ( V_2 , V_69 , V_30 ) ;
break;
case V_173 :
V_165 = F_59 ( V_2 , V_69 , V_30 ) ;
break;
default:
F_6 ( V_110 , L_21 , V_69 [ 0 ] ) ;
V_165 = V_174 ;
break;
}
if ( V_165 )
V_69 [ 0 ] |= V_166 ;
else
V_69 [ 0 ] |= V_145 ;
V_69 [ 0 ] |= V_175 ;
F_51 ( V_6 , V_69 , V_163 , V_30 ) ;
return V_165 ;
}
static void F_65 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_176 = V_166 ;
if ( ! V_2 -> V_36 [ V_30 ] . V_143 )
F_51 ( V_6 , & V_176 , 1 , V_30 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_13 ; V_30 ++ ) {
if ( ! F_67 ( V_6 , V_30 ) )
F_40 ( V_2 , V_30 ) ;
if ( ! F_68 ( V_6 , V_30 ) )
F_62 ( V_2 , V_30 ) ;
if ( ! F_69 ( V_6 , V_30 ) )
F_65 ( V_2 , V_30 ) ;
}
}
void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_11 ( V_6 , F_49 ( 0 ) , 0 ) ;
F_11 ( V_6 , F_49 ( 1 ) , 0 ) ;
F_11 ( V_6 , F_34 ( 0 ) , 0 ) ;
F_11 ( V_6 , F_34 ( 1 ) , 0 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_177 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
V_177 = V_178 ;
if ( V_2 -> V_36 [ V_8 ] . V_143 )
V_177 |= V_175 ;
F_51 ( V_6 , & V_177 , 1 , V_8 ) ;
}
}
int F_72 ( struct V_94 * V_95 , int V_30 , T_4 * V_24 )
{
struct V_1 * V_2 = F_73 ( V_95 ) ;
if ( ! F_53 ( V_24 ) || ( V_30 >= V_2 -> V_13 ) )
return - V_109 ;
V_2 -> V_36 [ V_30 ] . V_149 = true ;
F_74 ( & V_2 -> V_12 -> V_14 , L_22 , V_24 , V_30 ) ;
F_74 ( & V_2 -> V_12 -> V_14 , L_23
L_24 ) ;
if ( F_75 ( V_179 , & V_2 -> V_180 ) ) {
F_3 ( & V_2 -> V_12 -> V_14 , L_25
L_26 ) ;
F_3 ( & V_2 -> V_12 -> V_14 , L_27
L_28 ) ;
}
return F_43 ( V_2 , V_30 , V_24 ) ;
}
int F_76 ( struct V_94 * V_95 , int V_30 , T_2 V_181 , T_4 V_120 )
{
int V_15 = 0 ;
struct V_1 * V_2 = F_73 ( V_95 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ( V_30 >= V_2 -> V_13 ) || ( V_181 > 4095 ) || ( V_120 > 7 ) )
return - V_109 ;
if ( V_181 || V_120 ) {
V_15 = F_30 ( V_2 , true , V_181 , V_30 ) ;
if ( V_15 )
goto V_182;
F_37 ( V_2 , V_181 , V_120 , V_30 ) ;
F_35 ( V_6 , V_30 , false ) ;
if ( V_2 -> V_36 [ V_30 ] . V_50 )
V_6 -> V_24 . V_39 . V_127 ( V_6 , true , V_30 ) ;
V_2 -> V_36 [ V_30 ] . V_152 ++ ;
V_2 -> V_36 [ V_30 ] . V_124 = V_181 ;
V_2 -> V_36 [ V_30 ] . V_125 = V_120 ;
F_74 ( & V_2 -> V_12 -> V_14 ,
L_29 , V_181 , V_120 , V_30 ) ;
if ( F_75 ( V_179 , & V_2 -> V_180 ) ) {
F_3 ( & V_2 -> V_12 -> V_14 ,
L_30
L_26 ) ;
F_3 ( & V_2 -> V_12 -> V_14 ,
L_27
L_28 ) ;
}
} else {
V_15 = F_30 ( V_2 , false ,
V_2 -> V_36 [ V_30 ] . V_124 , V_30 ) ;
F_39 ( V_2 , V_30 ) ;
F_35 ( V_6 , V_30 , true ) ;
V_6 -> V_24 . V_39 . V_127 ( V_6 , false , V_30 ) ;
if ( V_2 -> V_36 [ V_30 ] . V_152 )
V_2 -> V_36 [ V_30 ] . V_152 -- ;
V_2 -> V_36 [ V_30 ] . V_124 = 0 ;
V_2 -> V_36 [ V_30 ] . V_125 = 0 ;
}
V_182:
return V_15 ;
}
static int F_77 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_183 ) {
case V_184 :
return 100 ;
case V_185 :
return 1000 ;
case V_186 :
return 10000 ;
default:
return 0 ;
}
}
static void F_78 ( struct V_1 * V_2 , int V_30 )
{
struct V_154 * V_155 = & V_2 -> V_20 [ V_21 ] ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_187 = 0 ;
T_2 V_188 , V_189 ;
T_2 V_190 = V_2 -> V_36 [ V_30 ] . V_190 ;
if ( V_190 ) {
V_187 = V_2 -> V_191 ;
V_187 <<= V_192 ;
V_187 /= V_190 ;
V_187 &= V_193 |
V_194 ;
V_187 |= V_195 ;
}
switch ( V_6 -> V_24 . type ) {
case V_41 :
F_11 ( V_6 , V_196 , 0x4 ) ;
break;
case V_55 :
F_11 ( V_6 , V_196 , 0x14 ) ;
break;
default:
break;
}
V_189 = F_60 ( 1 , ~ V_155 -> V_159 ) ;
for ( V_188 = 0 ; V_188 < V_189 ; V_188 ++ ) {
unsigned int V_197 = ( V_30 * V_189 ) + V_188 ;
F_11 ( V_6 , V_198 , V_197 ) ;
F_11 ( V_6 , V_199 , V_187 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! V_2 -> V_191 )
return;
if ( F_77 ( V_2 ) != V_2 -> V_191 ) {
V_2 -> V_191 = 0 ;
F_74 ( & V_2 -> V_12 -> V_14 ,
L_31 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
if ( ! V_2 -> V_191 )
V_2 -> V_36 [ V_8 ] . V_190 = 0 ;
F_78 ( V_2 , V_8 ) ;
}
}
int F_80 ( struct V_94 * V_95 , int V_30 , int V_190 )
{
struct V_1 * V_2 = F_73 ( V_95 ) ;
int V_183 ;
if ( V_30 >= V_2 -> V_13 )
return - V_109 ;
if ( ! V_2 -> V_200 )
return - V_109 ;
V_183 = F_77 ( V_2 ) ;
if ( V_183 != 10000 )
return - V_109 ;
if ( V_190 && ( ( V_190 <= 10 ) || ( V_190 > V_183 ) ) )
return - V_109 ;
V_2 -> V_191 = V_183 ;
V_2 -> V_36 [ V_30 ] . V_190 = V_190 ;
F_78 ( V_2 , V_30 ) ;
return 0 ;
}
int F_57 ( struct V_94 * V_95 , int V_30 , bool V_201 )
{
struct V_1 * V_2 = F_73 ( V_95 ) ;
int V_202 = V_30 >> 3 ;
int V_203 = V_30 % 8 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_204 ;
V_2 -> V_36 [ V_30 ] . V_50 = V_201 ;
V_204 = F_20 ( V_6 , F_81 ( V_202 ) ) ;
V_204 &= ~ ( 1 << V_203 ) ;
V_204 |= ( V_201 << V_203 ) ;
F_11 ( V_6 , F_81 ( V_202 ) , V_204 ) ;
if ( V_2 -> V_36 [ V_30 ] . V_152 ) {
V_203 += V_205 ;
V_204 = F_20 ( V_6 , F_81 ( V_202 ) ) ;
V_204 &= ~ ( 1 << V_203 ) ;
V_204 |= ( V_201 << V_203 ) ;
F_11 ( V_6 , F_81 ( V_202 ) , V_204 ) ;
}
return 0 ;
}
int F_82 ( struct V_94 * V_95 ,
int V_30 , struct V_206 * V_207 )
{
struct V_1 * V_2 = F_73 ( V_95 ) ;
if ( V_30 >= V_2 -> V_13 )
return - V_109 ;
V_207 -> V_30 = V_30 ;
memcpy ( & V_207 -> V_24 , V_2 -> V_36 [ V_30 ] . V_131 , V_135 ) ;
V_207 -> V_190 = V_2 -> V_36 [ V_30 ] . V_190 ;
V_207 -> V_181 = V_2 -> V_36 [ V_30 ] . V_124 ;
V_207 -> V_120 = V_2 -> V_36 [ V_30 ] . V_125 ;
V_207 -> V_208 = V_2 -> V_36 [ V_30 ] . V_50 ;
return 0 ;
}
