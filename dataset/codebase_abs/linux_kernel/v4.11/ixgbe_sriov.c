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
F_33 ( V_2 ) ;
V_58 = F_16 ( V_57 , V_12 ) ;
if ( V_58 ) {
F_23 ( L_3 , V_58 ) ;
return V_58 ;
}
F_7 ( V_2 ) ;
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
V_80 |= F_40 ( V_78 ) ;
F_6 ( V_4 , F_39 ( V_79 ) , V_80 ) ;
}
V_81 |= V_85 ;
F_6 ( V_4 , F_37 ( V_24 ) , V_81 ) ;
return 0 ;
}
void F_41 ( struct V_1 * V_2 )
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
V_80 |= F_40 ( V_78 ) ;
F_6 ( V_4 , F_39 ( V_79 ) , V_80 ) ;
}
if ( V_29 -> V_83 )
V_81 |= V_85 ;
else
V_81 &= ~ V_85 ;
F_6 ( V_4 , F_37 ( V_6 ) , V_81 ) ;
}
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_89 , int V_90 ,
T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
if ( V_89 && F_44 ( V_90 , V_2 -> V_91 ) ) {
V_58 = V_4 -> V_18 . V_92 . V_93 ( V_4 , V_90 , F_45 ( 0 ) , true , false ) ;
if ( V_58 )
return V_58 ;
}
V_58 = V_4 -> V_18 . V_92 . V_93 ( V_4 , V_90 , V_24 , ! ! V_89 , false ) ;
if ( V_89 && ! V_58 )
return V_58 ;
if ( F_44 ( V_90 , V_2 -> V_91 ) ||
( V_2 -> V_37 & V_94 ) )
F_46 ( V_2 , V_90 ) ;
return V_58 ;
}
static T_3 F_47 ( struct V_1 * V_2 , T_2 * V_73 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_95 = V_73 [ 1 ] ;
T_2 V_96 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_97 * V_57 = V_2 -> V_98 ;
int V_99 = V_57 -> V_100 + V_101 ;
T_2 V_102 , V_103 , V_104 ;
T_3 V_58 = 0 ;
#ifdef F_48
if ( V_57 -> V_105 & V_106 )
V_99 = F_49 ( int , V_99 ,
V_107 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_109 :
case V_110 :
case V_111 :
if ( V_99 > V_112 )
break;
default:
if ( ( V_99 > V_112 ) ||
( V_95 > ( V_112 + V_113 ) ) )
V_58 = - V_114 ;
break;
}
V_103 = V_24 % 32 ;
V_102 = V_24 / 32 ;
V_104 = F_25 ( V_4 , F_50 ( V_102 ) ) ;
if ( V_58 )
V_104 &= ~ F_40 ( V_103 ) ;
else
V_104 |= F_40 ( V_103 ) ;
F_6 ( V_4 , F_50 ( V_102 ) , V_104 ) ;
if ( V_58 ) {
F_17 ( V_115 , L_7 , V_95 ) ;
return V_58 ;
}
}
if ( V_95 > V_116 ) {
F_17 ( V_115 , L_7 , V_95 ) ;
return - V_114 ;
}
V_96 = F_25 ( V_4 , V_117 ) ;
V_96 &= V_118 ;
V_96 >>= V_119 ;
if ( V_96 < V_95 ) {
V_96 = V_95 << V_119 ;
F_6 ( V_4 , V_117 , V_96 ) ;
}
F_2 ( V_4 , L_8 , V_95 ) ;
return 0 ;
}
static void F_51 ( struct V_3 * V_4 , T_2 V_24 , bool V_120 )
{
T_2 V_81 = F_25 ( V_4 , F_37 ( V_24 ) ) ;
V_81 |= V_121 ;
if ( V_120 )
V_81 |= V_122 ;
else
V_81 &= ~ V_122 ;
F_6 ( V_4 , F_37 ( V_24 ) , V_81 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_53 ( V_24 ) , 0 ) ;
}
static void F_54 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_123 , V_124 , V_6 ;
V_124 = ~ F_40 ( F_45 ( 0 ) % 32 ) ;
V_123 = F_40 ( V_24 % 32 ) ;
for ( V_6 = V_125 ; V_6 -- ; ) {
T_2 V_126 [ 2 ] , V_127 , V_90 , V_128 , V_129 ;
T_2 V_130 = V_6 * 2 + V_24 / 32 ;
T_2 V_131 ;
V_127 = F_25 ( V_4 , F_55 ( V_130 ) ) ;
if ( ! ( V_127 & V_123 ) )
continue;
V_127 ^= V_123 ;
V_126 [ V_130 % 2 ] = V_127 ;
V_126 [ ~ V_130 % 2 ] = F_25 ( V_4 , F_55 ( V_130 ^ 1 ) ) ;
if ( V_126 [ ( F_45 ( 0 ) / 32 ) ^ 1 ] ||
( V_126 [ F_45 ( 0 ) / 32 ] & V_124 ) )
goto V_132;
if ( V_126 [ 0 ] || V_126 [ 1 ] )
goto V_133;
V_129 = F_25 ( V_4 , F_56 ( V_6 ) ) ;
if ( ! V_129 )
goto V_132;
V_90 = V_129 & V_134 ;
V_131 = F_40 ( V_90 % 32 ) ;
V_128 = F_25 ( V_4 , F_57 ( V_90 / 32 ) ) ;
if ( V_128 & V_131 )
F_6 ( V_4 , F_57 ( V_90 / 32 ) , V_128 ^ V_131 ) ;
V_133:
F_6 ( V_4 , F_56 ( V_6 ) , 0 ) ;
if ( ! ( V_2 -> V_37 & V_94 ) )
V_127 = 0 ;
V_132:
F_6 ( V_4 , F_55 ( V_130 ) , V_127 ) ;
}
}
static inline void F_58 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
T_4 V_33 = F_59 ( V_2 -> V_98 ) ;
F_54 ( V_2 , V_24 ) ;
F_43 ( V_2 , true , V_29 -> V_135 , V_24 ) ;
F_51 ( V_4 , V_24 , ! V_29 -> V_135 ) ;
if ( ! V_29 -> V_135 && ! V_29 -> V_136 && ! V_33 ) {
F_52 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_136 || ! V_33 )
F_60 ( V_2 , V_29 -> V_135 ,
V_29 -> V_136 , V_24 ) ;
else
F_60 ( V_2 , V_29 -> V_135 ,
V_2 -> V_137 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_92 . V_138 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_83 = 0 ;
F_61 ( V_2 -> V_98 ) ;
F_62 ( V_2 , V_2 -> V_29 [ V_24 ] . V_139 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_108 = V_140 ;
}
static int F_63 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_141 )
{
F_62 ( V_2 , V_2 -> V_29 [ V_24 ] . V_139 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_139 , V_141 , V_142 ) ;
F_64 ( V_2 , V_2 -> V_29 [ V_24 ] . V_139 , V_24 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
int V_24 , int V_143 , unsigned char * V_141 )
{
struct V_144 * V_51 ;
struct V_7 * V_145 ;
if ( V_143 <= 1 ) {
F_66 (pos, &adapter->vf_mvs.l) {
V_145 = F_67 ( V_51 , struct V_7 , V_23 ) ;
if ( V_145 -> V_24 == V_24 ) {
V_145 -> V_24 = - 1 ;
V_145 -> free = true ;
V_145 -> V_146 = false ;
F_62 ( V_2 ,
V_145 -> V_147 , V_24 ) ;
}
}
}
if ( ! V_143 )
return 0 ;
V_145 = NULL ;
F_66 (pos, &adapter->vf_mvs.l) {
V_145 = F_67 ( V_51 , struct V_7 , V_23 ) ;
if ( V_145 -> free )
break;
}
if ( ! V_145 || ! V_145 -> free )
return - V_148 ;
V_145 -> free = false ;
V_145 -> V_146 = true ;
V_145 -> V_24 = V_24 ;
memcpy ( V_145 -> V_147 , V_141 , V_142 ) ;
F_64 ( V_2 , V_141 , V_24 ) ;
return 0 ;
}
int F_32 ( struct V_46 * V_47 , unsigned int V_149 )
{
struct V_1 * V_2 = F_31 ( V_47 ) ;
unsigned int V_150 = ( V_149 & 0x3f ) ;
bool V_151 = ( ( V_149 & 0x10000000U ) != 0 ) ;
if ( V_151 )
F_68 ( V_2 -> V_29 [ V_150 ] . V_139 ) ;
return 0 ;
}
static inline void F_69 ( struct V_1 * V_2 , T_2 V_24 ,
T_2 V_152 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
T_2 V_155 = F_70 ( 1 , ~ V_154 -> V_131 ) ;
int V_6 ;
for ( V_6 = V_24 * V_155 ; V_6 < ( ( V_24 + 1 ) * V_155 ) ; V_6 ++ ) {
T_2 V_156 ;
F_26 ( V_4 ) ;
V_156 = V_157 | V_158 ;
V_156 |= V_6 << V_159 ;
F_6 ( V_4 , V_160 , V_156 ) ;
}
}
static int F_71 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_161 = V_2 -> V_29 [ V_24 ] . V_139 ;
T_2 V_156 , V_102 , V_103 ;
T_2 V_73 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_162 = ( T_4 * ) ( & V_73 [ 1 ] ) ;
T_2 V_155 = F_70 ( 1 , ~ V_154 -> V_131 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_58 ( V_2 , V_24 ) ;
if ( ! F_72 ( V_161 ) )
F_63 ( V_2 , V_24 , V_161 ) ;
V_103 = V_24 % 32 ;
V_102 = V_24 / 32 ;
V_156 = F_25 ( V_4 , F_73 ( V_102 ) ) ;
V_156 |= F_40 ( V_103 ) ;
F_6 ( V_4 , F_73 ( V_102 ) , V_156 ) ;
F_69 ( V_2 , V_24 , V_158 ) ;
V_156 = F_25 ( V_4 , F_50 ( V_102 ) ) ;
V_156 |= F_40 ( V_103 ) ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_97 * V_57 = V_2 -> V_98 ;
int V_99 = V_57 -> V_100 + V_101 ;
#ifdef F_48
if ( V_57 -> V_105 & V_106 )
V_99 = F_49 ( int , V_99 ,
V_107 ) ;
#endif
if ( V_99 > V_112 )
V_156 &= ~ F_40 ( V_103 ) ;
}
F_6 ( V_4 , F_50 ( V_102 ) , V_156 ) ;
V_2 -> V_29 [ V_24 ] . V_163 = true ;
V_156 = F_25 ( V_4 , F_74 ( V_102 ) ) ;
V_156 |= F_40 ( V_103 ) ;
F_6 ( V_4 , F_74 ( V_102 ) , V_156 ) ;
for ( V_6 = 0 ; V_6 < V_155 ; V_6 ++ ) {
F_6 ( V_4 , F_75 ( V_155 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_76 ( V_155 , V_24 , V_6 ) , 0 ) ;
}
V_73 [ 0 ] = V_164 ;
if ( ! F_72 ( V_161 ) ) {
V_73 [ 0 ] |= V_165 ;
memcpy ( V_162 , V_161 , V_142 ) ;
} else {
V_73 [ 0 ] |= V_166 ;
F_14 ( & V_2 -> V_47 -> V_57 ,
L_10 ,
V_24 ) ;
}
V_73 [ 3 ] = V_4 -> V_18 . V_167 ;
F_77 ( V_4 , V_73 , V_168 , V_24 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_4 * V_169 = ( ( T_4 * ) ( & V_73 [ 1 ] ) ) ;
if ( ! F_79 ( V_169 ) ) {
F_80 ( V_115 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_170 && ! V_2 -> V_29 [ V_24 ] . V_42 &&
! F_81 ( V_2 -> V_29 [ V_24 ] . V_139 , V_169 ) ) {
F_80 ( V_115 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_63 ( V_2 , V_24 , V_169 ) < 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_2 V_89 = ( V_73 [ 0 ] & V_75 ) >> V_76 ;
T_2 V_90 = ( V_73 [ 1 ] & V_171 ) ;
T_4 V_172 = F_59 ( V_2 -> V_98 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_135 || V_172 ) {
F_80 ( V_115 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( ! V_90 && ! V_89 )
return 0 ;
return F_43 ( V_2 , V_89 , V_90 , V_24 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_4 * V_169 = ( ( T_4 * ) ( & V_73 [ 1 ] ) ) ;
int V_143 = ( V_73 [ 0 ] & V_75 ) >>
V_76 ;
int V_58 ;
if ( V_2 -> V_29 [ V_24 ] . V_170 && ! V_2 -> V_29 [ V_24 ] . V_42 &&
V_143 > 0 ) {
F_80 ( V_115 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_143 ) {
if ( ! F_79 ( V_169 ) ) {
F_80 ( V_115 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 ) {
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_18 . V_92 . V_173 ( V_4 , false , V_24 ) ;
V_4 -> V_18 . V_92 . V_138 ( V_4 , false , V_24 ) ;
}
}
V_58 = F_65 ( V_2 , V_24 , V_143 , V_169 ) ;
if ( V_58 == - V_148 )
F_80 ( V_115 ,
L_16 ,
V_24 ) ;
return V_58 < 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
int V_174 = V_73 [ 1 ] ;
switch ( V_174 ) {
case V_140 :
case V_109 :
case V_110 :
case V_111 :
V_2 -> V_29 [ V_24 ] . V_108 = V_174 ;
return 0 ;
default:
break;
}
F_2 ( V_115 , L_17 , V_24 , V_174 ) ;
return - 1 ;
}
static int F_85 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
struct V_97 * V_57 = V_2 -> V_98 ;
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_175 = 0 ;
T_4 V_33 = F_59 ( V_57 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_176 :
case V_109 :
case V_110 :
case V_111 :
break;
default:
return - 1 ;
}
V_73 [ V_177 ] = F_70 ( 1 , ~ V_154 -> V_131 ) ;
V_73 [ V_178 ] = F_70 ( 1 , ~ V_154 -> V_131 ) ;
if ( V_33 > 1 )
V_175 = F_86 ( V_57 , V_2 -> V_137 ) ;
if ( V_33 )
V_73 [ V_179 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_135 || V_2 -> V_29 [ V_24 ] . V_136 )
V_73 [ V_179 ] = 1 ;
else
V_73 [ V_179 ] = 0 ;
V_73 [ V_180 ] = V_175 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , T_2 * V_73 , T_2 V_24 )
{
T_2 V_6 , V_86 ;
T_2 * V_181 = & V_73 [ 1 ] ;
const T_4 * V_182 = V_2 -> V_183 ;
T_2 V_184 = F_88 ( V_2 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_62 ;
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_111 :
case V_110 :
break;
default:
return - V_185 ;
}
for ( V_6 = 0 ; V_6 < V_184 / 16 ; V_6 ++ ) {
V_181 [ V_6 ] = 0 ;
for ( V_86 = 0 ; V_86 < 16 ; V_86 ++ )
V_181 [ V_6 ] |= ( T_2 ) ( V_182 [ 16 * V_6 + V_86 ] & 0x3 ) << ( 2 * V_86 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
T_2 * V_186 = & V_73 [ 1 ] ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_62 ;
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_111 :
case V_110 :
break;
default:
return - V_185 ;
}
memcpy ( V_186 , V_2 -> V_186 , sizeof( V_2 -> V_186 ) ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
T_2 * V_73 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_43 = V_73 [ 1 ] ;
T_2 V_81 , V_187 , V_188 , V_151 ;
switch ( V_2 -> V_29 [ V_24 ] . V_108 ) {
case V_110 :
if ( V_43 == V_189 )
return - V_185 ;
case V_111 :
break;
default:
return - V_185 ;
}
if ( V_43 > V_190 &&
! V_2 -> V_29 [ V_24 ] . V_42 ) {
V_43 = V_190 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_43 == V_43 )
goto V_191;
switch ( V_43 ) {
case V_44 :
V_188 = V_121 | V_85 |
V_192 | V_193 | V_194 ;
V_151 = 0 ;
break;
case V_190 :
V_188 = V_192 | V_193 | V_194 ;
V_151 = V_121 | V_85 ;
break;
case V_195 :
V_188 = V_193 | V_194 ;
V_151 = V_121 | V_85 | V_192 ;
break;
case V_189 :
if ( V_4 -> V_18 . type <= V_31 )
return - V_185 ;
V_187 = F_25 ( V_4 , V_196 ) ;
if ( ! ( V_187 & V_197 ) ) {
F_80 ( V_115 ,
L_18 ) ;
return - V_62 ;
}
V_188 = 0 ;
V_151 = V_121 | V_85 |
V_192 | V_193 | V_194 ;
break;
default:
return - V_185 ;
}
V_81 = F_25 ( V_4 , F_37 ( V_24 ) ) ;
V_81 &= ~ V_188 ;
V_81 |= V_151 ;
F_6 ( V_4 , F_37 ( V_24 ) , V_81 ) ;
V_2 -> V_29 [ V_24 ] . V_43 = V_43 ;
V_191:
V_73 [ 1 ] = V_43 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_2 V_24 )
{
T_2 V_198 = V_199 ;
T_2 V_73 [ V_199 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_200 ;
V_200 = F_92 ( V_4 , V_73 , V_198 , V_24 ) ;
if ( V_200 ) {
F_93 ( L_19 ) ;
return V_200 ;
}
if ( V_73 [ 0 ] & ( V_165 | V_166 ) )
return 0 ;
F_26 ( V_4 ) ;
if ( V_73 [ 0 ] == V_164 )
return F_71 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_163 ) {
V_73 [ 0 ] |= V_166 ;
F_77 ( V_4 , V_73 , 1 , V_24 ) ;
return 0 ;
}
switch ( ( V_73 [ 0 ] & 0xFFFF ) ) {
case V_201 :
V_200 = F_78 ( V_2 , V_73 , V_24 ) ;
break;
case V_202 :
V_200 = F_36 ( V_2 , V_73 , V_24 ) ;
break;
case V_203 :
V_200 = F_82 ( V_2 , V_73 , V_24 ) ;
break;
case V_204 :
V_200 = F_47 ( V_2 , V_73 , V_24 ) ;
break;
case V_205 :
V_200 = F_83 ( V_2 , V_73 , V_24 ) ;
break;
case V_206 :
V_200 = F_84 ( V_2 , V_73 , V_24 ) ;
break;
case V_207 :
V_200 = F_85 ( V_2 , V_73 , V_24 ) ;
break;
case V_208 :
V_200 = F_87 ( V_2 , V_73 , V_24 ) ;
break;
case V_209 :
V_200 = F_89 ( V_2 , V_73 , V_24 ) ;
break;
case V_210 :
V_200 = F_90 ( V_2 , V_73 , V_24 ) ;
break;
default:
F_17 ( V_115 , L_20 , V_73 [ 0 ] ) ;
V_200 = V_211 ;
break;
}
if ( V_200 )
V_73 [ 0 ] |= V_166 ;
else
V_73 [ 0 ] |= V_165 ;
V_73 [ 0 ] |= V_212 ;
F_77 ( V_4 , V_73 , V_198 , V_24 ) ;
return V_200 ;
}
static void F_94 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_213 = V_166 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_163 )
F_77 ( V_4 , & V_213 , 1 , V_24 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_96 ( V_4 , V_24 ) )
F_58 ( V_2 , V_24 ) ;
if ( ! F_97 ( V_4 , V_24 ) )
F_91 ( V_2 , V_24 ) ;
if ( ! F_98 ( V_4 , V_24 ) )
F_94 ( V_2 , V_24 ) ;
}
}
void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_73 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_73 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_50 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_50 ( 1 ) , 0 ) ;
}
static inline void F_100 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_214 ;
V_214 = V_215 ;
if ( V_2 -> V_29 [ V_24 ] . V_163 )
V_214 |= V_212 ;
F_77 ( V_4 , & V_214 , 1 , V_24 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_214 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_214 = V_215 ;
if ( V_2 -> V_29 [ V_6 ] . V_163 )
V_214 |= V_212 ;
F_77 ( V_4 , & V_214 , 1 , V_6 ) ;
}
}
int F_102 ( struct V_97 * V_98 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( ! F_79 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_114 ;
V_2 -> V_29 [ V_24 ] . V_170 = true ;
F_104 ( & V_2 -> V_47 -> V_57 , L_21 , V_18 , V_24 ) ;
F_104 ( & V_2 -> V_47 -> V_57 , L_22
L_23 ) ;
if ( F_44 ( V_216 , & V_2 -> V_217 ) ) {
F_14 ( & V_2 -> V_47 -> V_57 , L_24
L_25 ) ;
F_14 ( & V_2 -> V_47 -> V_57 , L_26
L_27 ) ;
}
return F_63 ( V_2 , V_24 , V_18 ) ;
}
static int F_105 ( struct V_1 * V_2 , int V_24 ,
T_1 V_218 , T_4 V_219 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
V_58 = F_43 ( V_2 , true , V_218 , V_24 ) ;
if ( V_58 )
goto V_191;
F_43 ( V_2 , false , 0 , V_24 ) ;
F_60 ( V_2 , V_218 , V_219 , V_24 ) ;
F_51 ( V_4 , V_24 , false ) ;
if ( V_4 -> V_18 . type >= V_220 )
F_69 ( V_2 , V_24 , V_158 |
V_221 ) ;
V_2 -> V_29 [ V_24 ] . V_135 = V_218 ;
V_2 -> V_29 [ V_24 ] . V_136 = V_219 ;
F_104 ( & V_2 -> V_47 -> V_57 ,
L_28 , V_218 , V_219 , V_24 ) ;
if ( F_44 ( V_216 , & V_2 -> V_217 ) ) {
F_14 ( & V_2 -> V_47 -> V_57 ,
L_29 ) ;
F_14 ( & V_2 -> V_47 -> V_57 ,
L_30 ) ;
}
V_191:
return V_58 ;
}
static int F_106 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 ;
V_58 = F_43 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_135 , V_24 ) ;
F_43 ( V_2 , true , 0 , V_24 ) ;
F_52 ( V_2 , V_24 ) ;
F_51 ( V_4 , V_24 , true ) ;
if ( V_4 -> V_18 . type >= V_220 )
F_69 ( V_2 , V_24 , V_158 ) ;
V_2 -> V_29 [ V_24 ] . V_135 = 0 ;
V_2 -> V_29 [ V_24 ] . V_136 = 0 ;
return V_58 ;
}
int F_107 ( struct V_97 * V_98 , int V_24 , T_1 V_218 ,
T_4 V_219 , T_5 V_222 )
{
int V_58 = 0 ;
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_218 > 4095 ) || ( V_219 > 7 ) )
return - V_114 ;
if ( V_222 != F_108 ( V_223 ) )
return - V_224 ;
if ( V_218 || V_219 ) {
if ( V_2 -> V_29 [ V_24 ] . V_135 )
V_58 = F_106 ( V_2 , V_24 ) ;
if ( V_58 )
goto V_191;
V_58 = F_105 ( V_2 , V_24 , V_218 , V_219 ) ;
} else {
V_58 = F_106 ( V_2 , V_24 ) ;
}
V_191:
return V_58 ;
}
int F_109 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_225 ) {
case V_226 :
return 100 ;
case V_227 :
return 1000 ;
case V_228 :
return 10000 ;
default:
return 0 ;
}
}
static void F_110 ( struct V_1 * V_2 , int V_24 )
{
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_229 = 0 ;
T_1 V_230 , V_231 ;
T_1 V_232 = V_2 -> V_29 [ V_24 ] . V_232 ;
if ( V_232 ) {
V_229 = V_2 -> V_233 ;
V_229 <<= V_234 ;
V_229 /= V_232 ;
V_229 &= V_235 |
V_236 ;
V_229 |= V_237 ;
}
switch ( V_4 -> V_18 . type ) {
case V_31 :
F_6 ( V_4 , V_238 , 0x4 ) ;
break;
case V_239 :
F_6 ( V_4 , V_238 , 0x14 ) ;
break;
default:
break;
}
V_231 = F_70 ( 1 , ~ V_154 -> V_131 ) ;
for ( V_230 = 0 ; V_230 < V_231 ; V_230 ++ ) {
unsigned int V_240 = ( V_24 * V_231 ) + V_230 ;
F_6 ( V_4 , V_241 , V_240 ) ;
F_6 ( V_4 , V_242 , V_229 ) ;
}
}
void F_111 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_233 )
return;
if ( F_109 ( V_2 ) != V_2 -> V_233 ) {
V_2 -> V_233 = 0 ;
F_104 ( & V_2 -> V_47 -> V_57 ,
L_31 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_233 )
V_2 -> V_29 [ V_6 ] . V_232 = 0 ;
F_110 ( V_2 , V_6 ) ;
}
}
int F_112 ( struct V_97 * V_98 , int V_24 , int V_243 ,
int V_244 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
int V_225 ;
if ( V_24 >= V_2 -> V_12 )
return - V_114 ;
if ( ! V_2 -> V_245 )
return - V_114 ;
V_225 = F_109 ( V_2 ) ;
if ( V_225 != 10000 )
return - V_114 ;
if ( V_243 )
return - V_114 ;
if ( V_244 && ( ( V_244 <= 10 ) || ( V_244 > V_225 ) ) )
return - V_114 ;
V_2 -> V_233 = V_225 ;
V_2 -> V_29 [ V_24 ] . V_232 = V_244 ;
F_110 ( V_2 , V_24 ) ;
return 0 ;
}
int F_113 ( struct V_97 * V_98 , int V_24 , bool V_246 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_24 >= V_2 -> V_12 )
return - V_114 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_246 ;
V_4 -> V_18 . V_92 . V_173 ( V_4 , V_246 , V_24 ) ;
V_4 -> V_18 . V_92 . V_138 ( V_4 , V_246 , V_24 ) ;
if ( V_4 -> V_18 . V_92 . V_247 ) {
F_6 ( V_4 , F_114 ( V_248 ) ,
( V_249 |
V_250 |
V_251 ) ) ;
F_6 ( V_4 , F_114 ( V_252 ) ,
( V_249 |
V_250 |
V_253 ) ) ;
V_4 -> V_18 . V_92 . V_247 ( V_4 , V_246 , V_24 ) ;
}
return 0 ;
}
int F_115 ( struct V_97 * V_98 , int V_24 ,
bool V_246 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( V_2 -> V_4 . V_18 . type < V_31 ||
V_2 -> V_4 . V_18 . type >= V_220 )
return - V_185 ;
if ( V_24 >= V_2 -> V_12 )
return - V_114 ;
V_2 -> V_29 [ V_24 ] . V_41 = V_246 ;
return 0 ;
}
int F_116 ( struct V_97 * V_98 , int V_24 , bool V_246 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_114 ;
if ( V_2 -> V_29 [ V_24 ] . V_42 == V_246 )
return 0 ;
V_2 -> V_29 [ V_24 ] . V_42 = V_246 ;
V_2 -> V_29 [ V_24 ] . V_163 = false ;
F_100 ( V_2 , V_24 ) ;
F_2 ( V_115 , L_32 , V_24 , V_246 ? L_33 : L_34 ) ;
return 0 ;
}
int F_117 ( struct V_97 * V_98 ,
int V_24 , struct V_254 * V_255 )
{
struct V_1 * V_2 = F_103 ( V_98 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_114 ;
V_255 -> V_24 = V_24 ;
memcpy ( & V_255 -> V_18 , V_2 -> V_29 [ V_24 ] . V_139 , V_142 ) ;
V_255 -> V_244 = V_2 -> V_29 [ V_24 ] . V_232 ;
V_255 -> V_243 = 0 ;
V_255 -> V_218 = V_2 -> V_29 [ V_24 ] . V_135 ;
V_255 -> V_219 = V_2 -> V_29 [ V_24 ] . V_136 ;
V_255 -> V_256 = V_2 -> V_29 [ V_24 ] . V_40 ;
V_255 -> V_257 = V_2 -> V_29 [ V_24 ] . V_41 ;
V_255 -> V_42 = V_2 -> V_29 [ V_24 ] . V_42 ;
return 0 ;
}
