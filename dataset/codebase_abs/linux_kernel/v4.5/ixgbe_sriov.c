static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 , V_6 ;
struct V_7 * V_8 ;
V_2 -> V_9 |= V_10 ;
F_2 ( V_11 , L_1 , V_2 -> V_12 ) ;
V_2 -> V_9 |= V_13 ;
if ( ! V_2 -> V_14 [ V_15 ] . V_16 )
V_2 -> V_14 [ V_15 ] . V_16 = 1 ;
V_2 -> V_14 [ V_15 ] . V_17 = V_2 -> V_12 ;
V_5 = V_4 -> V_18 . V_19 -
( V_20 + 1 + V_2 -> V_12 ) ;
V_2 -> V_8 = V_8 = F_3 ( V_5 ,
sizeof( struct V_7 ) ,
V_21 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_22 . V_23 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_8 -> V_24 = - 1 ;
V_8 -> free = true ;
F_5 ( & V_8 -> V_23 , & V_2 -> V_22 . V_23 ) ;
V_8 ++ ;
}
}
F_6 ( V_4 , V_25 , V_26 ) ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 =
F_3 ( V_2 -> V_12 ,
sizeof( struct V_30 ) , V_21 ) ;
if ( V_2 -> V_29 ) {
if ( ( V_2 -> V_4 . V_18 . type == V_31 ) &&
( V_2 -> V_12 < 16 ) ) {
V_2 -> V_32 . V_33 . V_34 = V_35 ;
V_2 -> V_32 . V_33 . V_36 = V_35 ;
} else if ( V_2 -> V_12 < 32 ) {
V_2 -> V_32 . V_33 . V_34 = 4 ;
V_2 -> V_32 . V_33 . V_36 = 4 ;
} else {
V_2 -> V_32 . V_33 . V_34 = 1 ;
V_2 -> V_32 . V_33 . V_36 = 1 ;
}
V_2 -> V_37 &= ~ ( V_38 |
V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_2 -> V_29 [ V_6 ] . V_40 = true ;
V_2 -> V_29 [ V_6 ] . V_41 = 0 ;
V_2 -> V_29 [ V_6 ] . V_42 = false ;
V_2 -> V_29 [ V_6 ] . V_43 = V_44 ;
}
return 0 ;
}
return - V_45 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
T_1 V_48 = V_47 -> V_48 ;
struct V_46 * V_49 ;
int V_24 = 0 ;
T_1 V_50 ;
int V_51 ;
V_51 = F_8 ( V_47 , V_52 ) ;
if ( ! V_51 )
return;
F_9 ( V_47 , V_51 + V_53 , & V_50 ) ;
V_49 = F_10 ( V_48 , V_50 , NULL ) ;
for (; V_49 ; V_49 = F_10 ( V_48 , V_50 , V_49 ) ) {
if ( ! V_49 -> V_54 )
continue;
if ( V_49 -> V_55 != V_47 )
continue;
if ( V_24 >= V_2 -> V_12 )
continue;
F_11 ( V_49 ) ;
V_2 -> V_29 [ V_24 ] . V_49 = V_49 ;
++ V_24 ;
}
}
void F_12 ( struct V_1 * V_2 )
{
int V_56 = 0 ;
V_56 = F_13 ( V_2 -> V_47 ) ;
if ( ! V_56 && ! V_2 -> V_12 )
return;
if ( V_56 ) {
V_2 -> V_12 = V_56 ;
F_14 ( & V_2 -> V_47 -> V_57 ,
L_2 ) ;
} else {
int V_58 ;
V_2 -> V_12 = F_15 (unsigned int, adapter->num_vfs, IXGBE_MAX_VFS_DRV_LIMIT) ;
V_58 = F_16 ( V_2 -> V_47 , V_2 -> V_12 ) ;
if ( V_58 ) {
F_17 ( V_11 , L_3 , V_58 ) ;
V_2 -> V_12 = 0 ;
return;
}
}
if ( ! F_1 ( V_2 ) ) {
F_7 ( V_2 ) ;
return;
}
F_17 ( V_11 , L_4
L_5 ) ;
F_18 ( V_2 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
unsigned int V_12 = V_2 -> V_12 , V_24 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_59 ;
T_2 V_60 ;
int V_61 ;
V_2 -> V_12 = 0 ;
for ( V_24 = 0 ; V_24 < V_12 ; ++ V_24 ) {
struct V_46 * V_49 = V_2 -> V_29 [ V_24 ] . V_49 ;
if ( ! V_49 )
continue;
V_2 -> V_29 [ V_24 ] . V_49 = NULL ;
F_19 ( V_49 ) ;
}
F_20 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
F_20 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
#ifdef F_21
if ( F_22 ( V_2 -> V_47 ) ) {
F_23 ( L_6 ) ;
return - V_62 ;
}
F_24 ( V_2 -> V_47 ) ;
#endif
F_6 ( V_4 , V_63 , 0 ) ;
V_59 = F_25 ( V_4 , V_64 ) ;
V_59 &= ~ V_65 ;
F_6 ( V_4 , V_64 , V_59 ) ;
V_60 = F_25 ( V_4 , V_66 ) ;
V_60 &= ~ V_67 ;
F_6 ( V_4 , V_66 , V_60 ) ;
F_26 ( V_4 ) ;
if ( V_2 -> V_14 [ V_15 ] . V_16 == 1 ) {
V_2 -> V_9 &= ~ V_13 ;
V_2 -> V_9 &= ~ V_10 ;
V_61 = F_15 ( int , F_27 ( V_2 ) ,
F_28 () ) ;
} else {
V_61 = F_15 ( int , V_68 , F_28 () ) ;
}
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_2 -> V_14 [ V_69 ] . V_16 = V_61 ;
F_29 ( 100 ) ;
return 0 ;
}
static int F_30 ( struct V_46 * V_57 , int V_12 )
{
#ifdef F_21
struct V_1 * V_2 = F_31 ( V_57 ) ;
int V_58 = 0 ;
int V_6 ;
int V_56 = F_13 ( V_57 ) ;
if ( V_56 && V_56 != V_12 )
V_58 = F_18 ( V_2 ) ;
else if ( V_56 && V_56 == V_12 )
return V_12 ;
if ( V_58 )
return V_58 ;
if ( ( V_12 + V_2 -> V_70 ) > V_71 )
return - V_62 ;
V_2 -> V_12 = V_12 ;
V_58 = F_1 ( V_2 ) ;
if ( V_58 )
return V_58 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_32 ( V_57 , ( V_6 | 0x10000000 ) ) ;
V_58 = F_16 ( V_57 , V_12 ) ;
if ( V_58 ) {
F_23 ( L_3 , V_58 ) ;
return V_58 ;
}
F_7 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_12 ;
#else
return 0 ;
#endif
}
static int F_34 ( struct V_46 * V_57 )
{
struct V_1 * V_2 = F_31 ( V_57 ) ;
int V_58 ;
#ifdef F_21
T_2 V_72 = V_2 -> V_9 ;
#endif
V_58 = F_18 ( V_2 ) ;
#ifdef F_21
if ( ! V_58 && V_72 != V_2 -> V_9 )
F_33 ( V_2 ) ;
#endif
return V_58 ;
}
int F_35 ( struct V_46 * V_57 , int V_12 )
{
if ( V_12 == 0 )
return F_34 ( V_57 ) ;
else
return F_30 ( V_57 , V_12 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
int V_74 = ( V_73 [ 0 ] & V_75 )
>> V_76 ;
T_1 * V_77 = ( T_1 * ) & V_73 [ 1 ] ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_2 V_78 ;
T_2 V_79 ;
T_2 V_80 ;
T_2 V_81 = F_25 ( V_4 , F_37 ( V_24 ) ) ;
V_74 = F_38 ( V_74 , V_82 ) ;
V_29 -> V_83 = V_74 ;
for ( V_6 = 0 ; V_6 < V_74 ; V_6 ++ ) {
V_29 -> V_84 [ V_6 ] = V_77 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_29 -> V_83 ; V_6 ++ ) {
V_79 = ( V_29 -> V_84 [ V_6 ] >> 5 ) & 0x7F ;
V_78 = V_29 -> V_84 [ V_6 ] & 0x1F ;
V_80 = F_25 ( V_4 , F_39 ( V_79 ) ) ;
V_80 |= ( 1 << V_78 ) ;
F_6 ( V_4 , F_39 ( V_79 ) , V_80 ) ;
}
V_81 |= V_85 ;
F_6 ( V_4 , F_37 ( V_24 ) , V_81 ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 ;
int V_6 , V_86 ;
T_2 V_78 ;
T_2 V_79 ;
T_2 V_80 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
T_2 V_81 = F_25 ( V_4 , F_37 ( V_6 ) ) ;
V_29 = & V_2 -> V_29 [ V_6 ] ;
for ( V_86 = 0 ; V_86 < V_29 -> V_83 ; V_86 ++ ) {
V_4 -> V_87 . V_88 ++ ;
V_79 = ( V_29 -> V_84 [ V_86 ] >> 5 ) & 0x7F ;
V_78 = V_29 -> V_84 [ V_86 ] & 0x1F ;
V_80 = F_25 ( V_4 , F_39 ( V_79 ) ) ;
V_80 |= ( 1 << V_78 ) ;
F_6 ( V_4 , F_39 ( V_79 ) , V_80 ) ;
}
if ( V_29 -> V_83 )
V_81 |= V_85 ;
else
V_81 &= ~ V_85 ;
F_6 ( V_4 , F_37 ( V_6 ) , V_81 ) ;
}
F_41 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 , int V_89 , int V_90 ,
T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
if ( V_89 && F_43 ( V_90 , V_2 -> V_91 ) ) {
V_58 = V_4 -> V_18 . V_92 . V_93 ( V_4 , V_90 , F_44 ( 0 ) , true , false ) ;
if ( V_58 )
return V_58 ;
}
V_58 = V_4 -> V_18 . V_92 . V_93 ( V_4 , V_90 , V_24 , ! ! V_89 , false ) ;
if ( V_89 && ! V_58 )
return V_58 ;
if ( F_43 ( V_90 , V_2 -> V_91 ) ||
( V_2 -> V_37 & V_94 ) )
F_45 ( V_2 , V_90 ) ;
return V_58 ;
}
static T_3 F_46 ( struct V_1 * V_2 , T_2 * V_73 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_95 = V_73 [ 1 ] ;
T_2 V_96 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_97 * V_57 = V_2 -> V_98 ;
int V_99 = V_57 -> V_100 + V_101 ;
T_2 V_102 , V_103 , V_104 ;
T_3 V_58 = 0 ;
#ifdef F_47
if ( V_57 -> V_105 & V_106 )
V_99 = F_48 ( int , V_99 ,
V_107 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_109 :
case V_110 :
if ( V_99 > V_111 )
break;
default:
if ( ( V_99 > V_111 ) ||
( V_95 > ( V_111 + V_112 ) ) )
V_58 = - V_113 ;
break;
}
V_103 = V_24 % 32 ;
V_102 = V_24 / 32 ;
V_104 = F_25 ( V_4 , F_49 ( V_102 ) ) ;
if ( V_58 )
V_104 &= ~ ( 1 << V_103 ) ;
else
V_104 |= 1 << V_103 ;
F_6 ( V_4 , F_49 ( V_102 ) , V_104 ) ;
if ( V_58 ) {
F_17 ( V_114 , L_7 , V_95 ) ;
return V_58 ;
}
}
if ( V_95 > V_115 ) {
F_17 ( V_114 , L_7 , V_95 ) ;
return - V_113 ;
}
V_96 = F_25 ( V_4 , V_116 ) ;
V_96 &= V_117 ;
V_96 >>= V_118 ;
if ( V_96 < V_95 ) {
V_96 = V_95 << V_118 ;
F_6 ( V_4 , V_116 , V_96 ) ;
}
F_2 ( V_4 , L_8 , V_95 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 , T_2 V_24 , bool V_119 )
{
T_2 V_81 = F_25 ( V_4 , F_37 ( V_24 ) ) ;
V_81 |= V_120 ;
if ( V_119 )
V_81 |= V_121 ;
else
V_81 &= ~ V_121 ;
F_6 ( V_4 , F_37 ( V_24 ) , V_81 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_52 ( V_24 ) , 0 ) ;
}
static void F_53 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_6 ;
for ( V_6 = V_122 ; V_6 -- ; ) {
T_2 V_123 [ 2 ] , V_124 , V_90 , V_125 , V_126 ;
T_2 V_127 = V_6 * 2 + V_24 / 32 ;
T_2 V_128 = 1 << ( V_24 % 32 ) ;
V_124 = F_25 ( V_4 , F_54 ( V_127 ) ) ;
if ( ! ( V_124 & V_128 ) )
continue;
V_124 ^= V_128 ;
V_123 [ V_127 % 2 ] = V_124 ;
V_123 [ ~ V_127 % 2 ] = F_25 ( V_4 , F_54 ( V_127 ^ 1 ) ) ;
if ( V_2 -> V_37 & V_94 ) {
V_123 [ F_44 ( 0 ) / 32 ] &= ~ ( 1 << ( F_44 ( 0 ) % 32 ) ) ;
if ( V_123 [ 0 ] || V_123 [ 1 ] )
goto V_129;
goto V_130;
}
if ( V_123 [ 0 ] || V_123 [ 1 ] )
goto V_129;
V_126 = F_25 ( V_4 , F_55 ( V_6 ) ) ;
if ( ! V_126 )
goto V_129;
V_90 = V_126 & V_131 ;
V_128 = 1 << ( V_90 % 32 ) ;
V_125 = F_25 ( V_4 , F_56 ( V_90 / 32 ) ) ;
if ( V_125 & V_128 )
F_6 ( V_4 , F_56 ( V_90 / 32 ) , V_125 ^ V_128 ) ;
V_130:
F_6 ( V_4 , F_55 ( V_6 ) , 0 ) ;
V_129:
F_6 ( V_4 , F_54 ( V_127 ) , V_124 ) ;
}
}
static inline void F_57 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
T_4 V_33 = F_58 ( V_2 -> V_98 ) ;
F_53 ( V_2 , V_24 ) ;
F_42 ( V_2 , true , V_29 -> V_132 , V_24 ) ;
F_50 ( V_4 , V_24 , ! V_29 -> V_132 ) ;
if ( ! V_29 -> V_132 && ! V_29 -> V_133 && ! V_33 ) {
F_51 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_133 || ! V_33 )
F_59 ( V_2 , V_29 -> V_132 ,
V_29 -> V_133 , V_24 ) ;
else
F_59 ( V_2 , V_29 -> V_132 ,
V_2 -> V_134 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_92 . V_135 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_83 = 0 ;
F_60 ( V_2 -> V_98 ) ;
F_61 ( V_2 , V_2 -> V_29 [ V_24 ] . V_136 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_108 = V_137 ;
}
static int F_62 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_138 )
{
F_61 ( V_2 , V_2 -> V_29 [ V_24 ] . V_136 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_136 , V_138 , V_139 ) ;
F_63 ( V_2 , V_2 -> V_29 [ V_24 ] . V_136 , V_24 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
int V_24 , int V_140 , unsigned char * V_138 )
{
struct V_141 * V_51 ;
struct V_7 * V_142 ;
if ( V_140 <= 1 ) {
F_65 (pos, &adapter->vf_mvs.l) {
V_142 = F_66 ( V_51 , struct V_7 , V_23 ) ;
if ( V_142 -> V_24 == V_24 ) {
V_142 -> V_24 = - 1 ;
V_142 -> free = true ;
V_142 -> V_143 = false ;
F_61 ( V_2 ,
V_142 -> V_144 , V_24 ) ;
}
}
}
if ( ! V_140 )
return 0 ;
V_142 = NULL ;
F_65 (pos, &adapter->vf_mvs.l) {
V_142 = F_66 ( V_51 , struct V_7 , V_23 ) ;
if ( V_142 -> free )
break;
}
if ( ! V_142 || ! V_142 -> free )
return - V_145 ;
V_142 -> free = false ;
V_142 -> V_143 = true ;
V_142 -> V_24 = V_24 ;
memcpy ( V_142 -> V_144 , V_138 , V_139 ) ;
F_63 ( V_2 , V_138 , V_24 ) ;
return 0 ;
}
int F_32 ( struct V_46 * V_47 , unsigned int V_146 )
{
struct V_1 * V_2 = F_31 ( V_47 ) ;
unsigned int V_147 = ( V_146 & 0x3f ) ;
bool V_148 = ( ( V_146 & 0x10000000U ) != 0 ) ;
if ( V_148 )
F_67 ( V_2 -> V_29 [ V_147 ] . V_136 ) ;
return 0 ;
}
static inline void F_68 ( struct V_1 * V_2 , T_2 V_24 ,
T_2 V_149 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_150 * V_151 = & V_2 -> V_14 [ V_15 ] ;
T_2 V_152 = F_69 ( 1 , ~ V_151 -> V_128 ) ;
int V_6 ;
for ( V_6 = V_24 * V_152 ; V_6 < ( ( V_24 + 1 ) * V_152 ) ; V_6 ++ ) {
T_2 V_153 ;
F_26 ( V_4 ) ;
V_153 = V_154 | V_155 ;
V_153 |= V_6 << V_156 ;
F_6 ( V_4 , V_157 , V_153 ) ;
}
}
static int F_70 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_150 * V_151 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_158 = V_2 -> V_29 [ V_24 ] . V_136 ;
T_2 V_153 , V_102 , V_103 ;
T_2 V_73 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_159 = ( T_4 * ) ( & V_73 [ 1 ] ) ;
T_2 V_152 = F_69 ( 1 , ~ V_151 -> V_128 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_57 ( V_2 , V_24 ) ;
if ( ! F_71 ( V_158 ) )
F_62 ( V_2 , V_24 , V_158 ) ;
V_103 = V_24 % 32 ;
V_102 = V_24 / 32 ;
V_153 = F_25 ( V_4 , F_72 ( V_102 ) ) ;
V_153 |= 1 << V_103 ;
F_6 ( V_4 , F_72 ( V_102 ) , V_153 ) ;
F_68 ( V_2 , V_24 , V_155 ) ;
V_153 = F_25 ( V_4 , F_49 ( V_102 ) ) ;
V_153 |= 1 << V_103 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_97 * V_57 = V_2 -> V_98 ;
int V_99 = V_57 -> V_100 + V_101 ;
#ifdef F_47
if ( V_57 -> V_105 & V_106 )
V_99 = F_48 ( int , V_99 ,
V_107 ) ;
#endif
if ( V_99 > V_111 )
V_153 &= ~ ( 1 << V_103 ) ;
}
F_6 ( V_4 , F_49 ( V_102 ) , V_153 ) ;
V_2 -> V_29 [ V_24 ] . V_160 = true ;
V_153 = F_25 ( V_4 , F_73 ( V_102 ) ) ;
V_153 |= ( 1 << V_103 ) ;
F_6 ( V_4 , F_73 ( V_102 ) , V_153 ) ;
for ( V_6 = 0 ; V_6 < V_152 ; V_6 ++ ) {
F_6 ( V_4 , F_74 ( V_152 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_75 ( V_152 , V_24 , V_6 ) , 0 ) ;
}
V_73 [ 0 ] = V_161 ;
if ( ! F_71 ( V_158 ) ) {
V_73 [ 0 ] |= V_162 ;
memcpy ( V_159 , V_158 , V_139 ) ;
} else {
V_73 [ 0 ] |= V_163 ;
F_14 ( & V_2 -> V_47 -> V_57 ,
L_10 ,
V_24 ) ;
}
V_73 [ 3 ] = V_4 -> V_18 . V_164 ;
F_76 ( V_4 , V_73 , V_165 , V_24 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_4 * V_166 = ( ( T_4 * ) ( & V_73 [ 1 ] ) ) ;
if ( ! F_78 ( V_166 ) ) {
F_79 ( V_114 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_167 &&
! F_80 ( V_2 -> V_29 [ V_24 ] . V_136 , V_166 ) ) {
F_79 ( V_114 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_62 ( V_2 , V_24 , V_166 ) < 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_2 V_89 = ( V_73 [ 0 ] & V_75 ) >> V_76 ;
T_2 V_90 = ( V_73 [ 1 ] & V_168 ) ;
T_4 V_169 = F_58 ( V_2 -> V_98 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
if ( V_2 -> V_29 [ V_24 ] . V_132 || V_169 ) {
F_79 ( V_114 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( ! V_90 && ! V_89 )
return 0 ;
V_58 = F_42 ( V_2 , V_89 , V_90 , V_24 ) ;
if ( V_58 )
return V_58 ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_92 . V_135 ( V_4 , true , V_24 ) ;
if ( V_89 )
V_2 -> V_29 [ V_24 ] . V_170 ++ ;
else if ( V_2 -> V_29 [ V_24 ] . V_170 )
V_2 -> V_29 [ V_24 ] . V_170 -- ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_4 * V_166 = ( ( T_4 * ) ( & V_73 [ 1 ] ) ) ;
int V_140 = ( V_73 [ 0 ] & V_75 ) >>
V_76 ;
int V_58 ;
if ( V_2 -> V_29 [ V_24 ] . V_167 && V_140 > 0 ) {
F_79 ( V_114 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_140 ) {
if ( ! F_78 ( V_166 ) ) {
F_79 ( V_114 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 )
F_83 ( V_2 -> V_98 , V_24 , false ) ;
}
V_58 = F_64 ( V_2 , V_24 , V_140 , V_166 ) ;
if ( V_58 == - V_145 )
F_79 ( V_114 ,
L_16 ,
V_24 ) ;
return V_58 < 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
int V_171 = V_73 [ 1 ] ;
switch ( V_171 ) {
case V_137 :
case V_109 :
case V_110 :
V_2 -> V_29 [ V_24 ] . V_108 = V_171 ;
return 0 ;
default:
break;
}
F_2 ( V_114 , L_17 , V_24 , V_171 ) ;
return - 1 ;
}
static int F_85 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
struct V_97 * V_57 = V_2 -> V_98 ;
struct V_150 * V_151 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_172 = 0 ;
T_4 V_33 = F_58 ( V_57 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_173 :
case V_109 :
case V_110 :
break;
default:
return - 1 ;
}
V_73 [ V_174 ] = F_69 ( 1 , ~ V_151 -> V_128 ) ;
V_73 [ V_175 ] = F_69 ( 1 , ~ V_151 -> V_128 ) ;
if ( V_33 > 1 )
V_172 = F_86 ( V_57 , V_2 -> V_134 ) ;
if ( V_33 )
V_73 [ V_176 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_132 || V_2 -> V_29 [ V_24 ] . V_133 )
V_73 [ V_176 ] = 1 ;
else
V_73 [ V_176 ] = 0 ;
V_73 [ V_177 ] = V_172 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , T_2 * V_73 , T_2 V_24 )
{
T_2 V_6 , V_86 ;
T_2 * V_178 = & V_73 [ 1 ] ;
const T_4 * V_179 = V_2 -> V_180 ;
T_2 V_181 = F_88 ( V_2 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_62 ;
if ( V_2 -> V_29 [ V_24 ] . V_108 != V_110 )
return - V_182 ;
for ( V_6 = 0 ; V_6 < V_181 / 16 ; V_6 ++ ) {
V_178 [ V_6 ] = 0 ;
for ( V_86 = 0 ; V_86 < 16 ; V_86 ++ )
V_178 [ V_6 ] |= ( T_2 ) ( V_179 [ 16 * V_6 + V_86 ] & 0x3 ) << ( 2 * V_86 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_2 * V_183 = & V_73 [ 1 ] ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_62 ;
if ( V_2 -> V_29 [ V_24 ] . V_108 != V_110 )
return - V_182 ;
memcpy ( V_183 , V_2 -> V_183 , sizeof( V_2 -> V_183 ) ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_43 = V_73 [ 1 ] ;
T_2 V_81 , V_184 , V_148 ;
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_110 :
break;
default:
return - V_182 ;
}
if ( V_43 > V_185 &&
! V_2 -> V_29 [ V_24 ] . V_42 ) {
V_43 = V_185 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_43 == V_43 )
goto V_186;
switch ( V_43 ) {
case V_44 :
V_184 = V_120 | V_85 | V_187 ;
V_148 = 0 ;
break;
case V_185 :
V_184 = V_187 ;
V_148 = V_120 | V_85 ;
break;
case V_188 :
V_184 = 0 ;
V_148 = V_120 | V_85 | V_187 ;
break;
default:
return - V_182 ;
}
V_81 = F_25 ( V_4 , F_37 ( V_24 ) ) ;
V_81 &= ~ V_184 ;
V_81 |= V_148 ;
F_6 ( V_4 , F_37 ( V_24 ) , V_81 ) ;
V_2 -> V_29 [ V_24 ] . V_43 = V_43 ;
V_186:
V_73 [ 1 ] = V_43 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_2 V_24 )
{
T_2 V_189 = V_190 ;
T_2 V_73 [ V_190 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_191 ;
V_191 = F_92 ( V_4 , V_73 , V_189 , V_24 ) ;
if ( V_191 ) {
F_93 ( L_18 ) ;
return V_191 ;
}
if ( V_73 [ 0 ] & ( V_162 | V_163 ) )
return 0 ;
F_26 ( V_4 ) ;
if ( V_73 [ 0 ] == V_161 )
return F_70 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_160 ) {
V_73 [ 0 ] |= V_163 ;
F_76 ( V_4 , V_73 , 1 , V_24 ) ;
return 0 ;
}
switch ( ( V_73 [ 0 ] & 0xFFFF ) ) {
case V_192 :
V_191 = F_77 ( V_2 , V_73 , V_24 ) ;
break;
case V_193 :
V_191 = F_36 ( V_2 , V_73 , V_24 ) ;
break;
case V_194 :
V_191 = F_81 ( V_2 , V_73 , V_24 ) ;
break;
case V_195 :
V_191 = F_46 ( V_2 , V_73 , V_24 ) ;
break;
case V_196 :
V_191 = F_82 ( V_2 , V_73 , V_24 ) ;
break;
case V_197 :
V_191 = F_84 ( V_2 , V_73 , V_24 ) ;
break;
case V_198 :
V_191 = F_85 ( V_2 , V_73 , V_24 ) ;
break;
case V_199 :
V_191 = F_87 ( V_2 , V_73 , V_24 ) ;
break;
case V_200 :
V_191 = F_89 ( V_2 , V_73 , V_24 ) ;
break;
case V_201 :
V_191 = F_90 ( V_2 , V_73 , V_24 ) ;
break;
default:
F_17 ( V_114 , L_19 , V_73 [ 0 ] ) ;
V_191 = V_202 ;
break;
}
if ( V_191 )
V_73 [ 0 ] |= V_163 ;
else
V_73 [ 0 ] |= V_162 ;
V_73 [ 0 ] |= V_203 ;
F_76 ( V_4 , V_73 , V_189 , V_24 ) ;
return V_191 ;
}
static void F_94 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_204 = V_163 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_160 )
F_76 ( V_4 , & V_204 , 1 , V_24 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_96 ( V_4 , V_24 ) )
F_57 ( V_2 , V_24 ) ;
if ( ! F_97 ( V_4 , V_24 ) )
F_91 ( V_2 , V_24 ) ;
if ( ! F_98 ( V_4 , V_24 ) )
F_94 ( V_2 , V_24 ) ;
}
}
void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_72 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_72 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_49 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_49 ( 1 ) , 0 ) ;
}
static inline void F_100 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_205 ;
V_205 = V_206 ;
if ( V_2 -> V_29 [ V_24 ] . V_160 )
V_205 |= V_203 ;
F_76 ( V_4 , & V_205 , 1 , V_24 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_205 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_205 = V_206 ;
if ( V_2 -> V_29 [ V_6 ] . V_160 )
V_205 |= V_203 ;
F_76 ( V_4 , & V_205 , 1 , V_6 ) ;
}
}
int F_102 ( struct V_97 * V_98 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( ! F_78 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_113 ;
V_2 -> V_29 [ V_24 ] . V_167 = true ;
F_104 ( & V_2 -> V_47 -> V_57 , L_20 , V_18 , V_24 ) ;
F_104 ( & V_2 -> V_47 -> V_57 , L_21
L_22 ) ;
if ( F_43 ( V_207 , & V_2 -> V_208 ) ) {
F_14 ( & V_2 -> V_47 -> V_57 , L_23
L_24 ) ;
F_14 ( & V_2 -> V_47 -> V_57 , L_25
L_26 ) ;
}
return F_62 ( V_2 , V_24 , V_18 ) ;
}
static int F_105 ( struct V_1 * V_2 , int V_24 ,
T_1 V_209 , T_4 V_210 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
V_58 = F_42 ( V_2 , true , V_209 , V_24 ) ;
if ( V_58 )
goto V_186;
F_42 ( V_2 , false , 0 , V_24 ) ;
F_59 ( V_2 , V_209 , V_210 , V_24 ) ;
F_50 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_92 . V_135 ( V_4 , true , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_170 ++ ;
if ( V_4 -> V_18 . type >= V_211 )
F_68 ( V_2 , V_24 , V_155 |
V_212 ) ;
V_2 -> V_29 [ V_24 ] . V_132 = V_209 ;
V_2 -> V_29 [ V_24 ] . V_133 = V_210 ;
F_104 ( & V_2 -> V_47 -> V_57 ,
L_27 , V_209 , V_210 , V_24 ) ;
if ( F_43 ( V_207 , & V_2 -> V_208 ) ) {
F_14 ( & V_2 -> V_47 -> V_57 ,
L_28 ) ;
F_14 ( & V_2 -> V_47 -> V_57 ,
L_29 ) ;
}
V_186:
return V_58 ;
}
static int F_106 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
V_58 = F_42 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_132 , V_24 ) ;
F_42 ( V_2 , true , 0 , V_24 ) ;
F_51 ( V_2 , V_24 ) ;
F_50 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_92 . V_135 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_170 )
V_2 -> V_29 [ V_24 ] . V_170 -- ;
if ( V_4 -> V_18 . type >= V_211 )
F_68 ( V_2 , V_24 , V_155 ) ;
V_2 -> V_29 [ V_24 ] . V_132 = 0 ;
V_2 -> V_29 [ V_24 ] . V_133 = 0 ;
return V_58 ;
}
int F_107 ( struct V_97 * V_98 , int V_24 , T_1 V_209 , T_4 V_210 )
{
int V_58 = 0 ;
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_209 > 4095 ) || ( V_210 > 7 ) )
return - V_113 ;
if ( V_209 || V_210 ) {
if ( V_2 -> V_29 [ V_24 ] . V_132 )
V_58 = F_106 ( V_2 , V_24 ) ;
if ( V_58 )
goto V_186;
V_58 = F_105 ( V_2 , V_24 , V_209 , V_210 ) ;
} else {
V_58 = F_106 ( V_2 , V_24 ) ;
}
V_186:
return V_58 ;
}
static int F_108 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_213 ) {
case V_214 :
return 100 ;
case V_215 :
return 1000 ;
case V_216 :
return 10000 ;
default:
return 0 ;
}
}
static void F_109 ( struct V_1 * V_2 , int V_24 )
{
struct V_150 * V_151 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_217 = 0 ;
T_1 V_218 , V_219 ;
T_1 V_220 = V_2 -> V_29 [ V_24 ] . V_220 ;
if ( V_220 ) {
V_217 = V_2 -> V_221 ;
V_217 <<= V_222 ;
V_217 /= V_220 ;
V_217 &= V_223 |
V_224 ;
V_217 |= V_225 ;
}
switch ( V_4 -> V_18 . type ) {
case V_31 :
F_6 ( V_4 , V_226 , 0x4 ) ;
break;
case V_227 :
F_6 ( V_4 , V_226 , 0x14 ) ;
break;
default:
break;
}
V_219 = F_69 ( 1 , ~ V_151 -> V_128 ) ;
for ( V_218 = 0 ; V_218 < V_219 ; V_218 ++ ) {
unsigned int V_228 = ( V_24 * V_219 ) + V_218 ;
F_6 ( V_4 , V_229 , V_228 ) ;
F_6 ( V_4 , V_230 , V_217 ) ;
}
}
void F_110 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_221 )
return;
if ( F_108 ( V_2 ) != V_2 -> V_221 ) {
V_2 -> V_221 = 0 ;
F_104 ( & V_2 -> V_47 -> V_57 ,
L_30 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_221 )
V_2 -> V_29 [ V_6 ] . V_220 = 0 ;
F_109 ( V_2 , V_6 ) ;
}
}
int F_111 ( struct V_97 * V_98 , int V_24 , int V_231 ,
int V_232 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
int V_213 ;
if ( V_24 >= V_2 -> V_12 )
return - V_113 ;
if ( ! V_2 -> V_233 )
return - V_113 ;
V_213 = F_108 ( V_2 ) ;
if ( V_213 != 10000 )
return - V_113 ;
if ( V_231 )
return - V_113 ;
if ( V_232 && ( ( V_232 <= 10 ) || ( V_232 > V_213 ) ) )
return - V_113 ;
V_2 -> V_221 = V_213 ;
V_2 -> V_29 [ V_24 ] . V_220 = V_232 ;
F_109 ( V_2 , V_24 ) ;
return 0 ;
}
int F_83 ( struct V_97 * V_98 , int V_24 , bool V_234 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
int V_235 = V_24 >> 3 ;
int V_236 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_237 ;
if ( V_24 >= V_2 -> V_12 )
return - V_113 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_234 ;
V_237 = F_25 ( V_4 , F_112 ( V_235 ) ) ;
V_237 &= ~ ( 1 << V_236 ) ;
V_237 |= ( V_234 << V_236 ) ;
F_6 ( V_4 , F_112 ( V_235 ) , V_237 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_170 ) {
V_236 += V_238 ;
V_237 = F_25 ( V_4 , F_112 ( V_235 ) ) ;
V_237 &= ~ ( 1 << V_236 ) ;
V_237 |= ( V_234 << V_236 ) ;
F_6 ( V_4 , F_112 ( V_235 ) , V_237 ) ;
}
return 0 ;
}
int F_113 ( struct V_97 * V_98 , int V_24 ,
bool V_234 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( V_2 -> V_4 . V_18 . type < V_31 ||
V_2 -> V_4 . V_18 . type >= V_211 )
return - V_182 ;
if ( V_24 >= V_2 -> V_12 )
return - V_113 ;
V_2 -> V_29 [ V_24 ] . V_41 = V_234 ;
return 0 ;
}
int F_114 ( struct V_97 * V_98 , int V_24 , bool V_234 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_113 ;
if ( V_2 -> V_29 [ V_24 ] . V_42 == V_234 )
return 0 ;
V_2 -> V_29 [ V_24 ] . V_42 = V_234 ;
V_2 -> V_29 [ V_24 ] . V_160 = false ;
F_100 ( V_2 , V_24 ) ;
F_2 ( V_114 , L_31 , V_24 , V_234 ? L_32 : L_33 ) ;
return 0 ;
}
int F_115 ( struct V_97 * V_98 ,
int V_24 , struct V_239 * V_240 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_113 ;
V_240 -> V_24 = V_24 ;
memcpy ( & V_240 -> V_18 , V_2 -> V_29 [ V_24 ] . V_136 , V_139 ) ;
V_240 -> V_232 = V_2 -> V_29 [ V_24 ] . V_220 ;
V_240 -> V_231 = 0 ;
V_240 -> V_209 = V_2 -> V_29 [ V_24 ] . V_132 ;
V_240 -> V_210 = V_2 -> V_29 [ V_24 ] . V_133 ;
V_240 -> V_241 = V_2 -> V_29 [ V_24 ] . V_40 ;
V_240 -> V_242 = V_2 -> V_29 [ V_24 ] . V_41 ;
V_240 -> V_42 = V_2 -> V_29 [ V_24 ] . V_42 ;
return 0 ;
}
