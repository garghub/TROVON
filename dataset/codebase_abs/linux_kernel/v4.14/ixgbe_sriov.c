static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 , V_9 ;
V_8 = V_5 -> V_10 . V_11 -
( V_12 + 1 + V_3 ) ;
if ( ! V_8 )
return;
V_7 = F_2 ( V_8 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( V_7 ) {
F_3 ( & V_2 -> V_14 . V_15 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_7 [ V_9 ] . V_16 = - 1 ;
V_7 [ V_9 ] . free = true ;
F_4 ( & V_7 [ V_9 ] . V_15 , & V_2 -> V_14 . V_15 ) ;
}
V_2 -> V_7 = V_7 ;
}
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_9 ;
V_2 -> V_17 |= V_18 ;
V_2 -> V_17 |= V_19 ;
if ( ! V_2 -> V_20 [ V_21 ] . V_22 )
V_2 -> V_20 [ V_21 ] . V_22 = 1 ;
V_2 -> V_23 = F_2 ( V_3 , sizeof( struct V_24 ) ,
V_13 ) ;
if ( ! V_2 -> V_23 )
return - V_25 ;
V_2 -> V_3 = V_3 ;
F_1 ( V_2 , V_3 ) ;
V_2 -> V_20 [ V_21 ] . V_26 = V_3 ;
F_6 ( V_5 , V_27 , V_28 ) ;
V_2 -> V_29 = V_30 ;
if ( ( V_2 -> V_5 . V_10 . type == V_31 ) && ( V_3 < 16 ) ) {
V_2 -> V_32 . V_33 . V_34 = V_35 ;
V_2 -> V_32 . V_33 . V_36 = V_35 ;
} else if ( V_3 < 32 ) {
V_2 -> V_32 . V_33 . V_34 = 4 ;
V_2 -> V_32 . V_33 . V_36 = 4 ;
} else {
V_2 -> V_32 . V_33 . V_34 = 1 ;
V_2 -> V_32 . V_33 . V_36 = 1 ;
}
V_2 -> V_37 &= ~ ( V_38 |
V_39 ) ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ ) {
V_2 -> V_23 [ V_9 ] . V_40 = true ;
V_2 -> V_23 [ V_9 ] . V_41 = 0 ;
V_2 -> V_23 [ V_9 ] . V_42 = false ;
V_2 -> V_23 [ V_9 ] . V_43 = V_44 ;
}
F_7 ( V_45 , L_1 , V_3 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
T_1 V_48 = V_47 -> V_48 ;
struct V_46 * V_49 ;
int V_16 = 0 ;
T_1 V_50 ;
int V_51 ;
V_51 = F_9 ( V_47 , V_52 ) ;
if ( ! V_51 )
return;
F_10 ( V_47 , V_51 + V_53 , & V_50 ) ;
V_49 = F_11 ( V_48 , V_50 , NULL ) ;
for (; V_49 ; V_49 = F_11 ( V_48 , V_50 , V_49 ) ) {
if ( ! V_49 -> V_54 )
continue;
if ( V_49 -> V_55 != V_47 )
continue;
if ( V_16 >= V_2 -> V_3 )
continue;
F_12 ( V_49 ) ;
V_2 -> V_23 [ V_16 ] . V_49 = V_49 ;
++ V_16 ;
}
}
void F_13 ( struct V_1 * V_2 , unsigned int V_56 )
{
int V_57 = 0 ;
unsigned int V_3 ;
V_57 = F_14 ( V_2 -> V_47 ) ;
if ( ! V_57 && ! V_56 )
return;
if ( V_57 ) {
V_3 = V_57 ;
F_15 ( & V_2 -> V_47 -> V_58 ,
L_2 ) ;
} else {
int V_59 ;
V_3 = F_16 (unsigned int, max_vfs, IXGBE_MAX_VFS_DRV_LIMIT) ;
V_59 = F_17 ( V_2 -> V_47 , V_3 ) ;
if ( V_59 ) {
F_18 ( V_45 , L_3 , V_59 ) ;
return;
}
}
if ( ! F_5 ( V_2 , V_3 ) ) {
F_8 ( V_2 ) ;
return;
}
F_18 ( V_45 , L_4
L_5 ) ;
F_19 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 , V_16 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_60 ;
T_2 V_61 ;
int V_62 ;
V_2 -> V_3 = 0 ;
for ( V_16 = 0 ; V_16 < V_3 ; ++ V_16 ) {
struct V_46 * V_49 = V_2 -> V_23 [ V_16 ] . V_49 ;
if ( ! V_49 )
continue;
V_2 -> V_23 [ V_16 ] . V_49 = NULL ;
F_20 ( V_49 ) ;
}
F_21 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
F_21 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
if ( ! ( V_2 -> V_17 & V_18 ) )
return 0 ;
#ifdef F_22
if ( F_23 ( V_2 -> V_47 ) ) {
F_24 ( L_6 ) ;
return - V_63 ;
}
F_25 ( V_2 -> V_47 ) ;
#endif
F_6 ( V_5 , V_64 , 0 ) ;
V_60 = F_26 ( V_5 , V_65 ) ;
V_60 &= ~ V_66 ;
F_6 ( V_5 , V_65 , V_60 ) ;
V_61 = F_26 ( V_5 , V_67 ) ;
V_61 &= ~ V_68 ;
F_6 ( V_5 , V_67 , V_61 ) ;
F_27 ( V_5 ) ;
if ( V_2 -> V_20 [ V_21 ] . V_22 == 1 ) {
V_2 -> V_17 &= ~ V_19 ;
V_2 -> V_17 &= ~ V_18 ;
V_62 = F_16 ( int , F_28 ( V_2 ) ,
F_29 () ) ;
} else {
V_62 = F_16 ( int , V_69 , F_29 () ) ;
}
V_2 -> V_20 [ V_21 ] . V_26 = 0 ;
V_2 -> V_20 [ V_70 ] . V_22 = V_62 ;
F_30 ( 100 ) ;
return 0 ;
}
static int F_31 ( struct V_46 * V_58 , int V_3 )
{
#ifdef F_22
struct V_1 * V_2 = F_32 ( V_58 ) ;
int V_59 = 0 ;
T_3 V_71 ;
int V_9 ;
int V_57 = F_14 ( V_58 ) ;
if ( V_57 && V_57 != V_3 )
V_59 = F_19 ( V_2 ) ;
else if ( V_57 && V_57 == V_3 )
return V_3 ;
if ( V_59 )
return V_59 ;
V_71 = F_33 ( V_2 -> V_72 ) ;
if ( V_71 > 4 ) {
if ( ( V_3 + V_2 -> V_73 ) > V_74 ) {
F_34 ( L_7 , V_71 , V_74 ) ;
return - V_63 ;
}
} else if ( ( V_71 > 1 ) && ( V_71 <= 4 ) ) {
if ( ( V_3 + V_2 -> V_73 ) > V_75 ) {
F_34 ( L_7 , V_71 , V_75 ) ;
return - V_63 ;
}
} else {
if ( ( V_3 + V_2 -> V_73 ) > V_76 ) {
F_34 ( L_7 , V_71 , V_76 ) ;
return - V_63 ;
}
}
V_59 = F_5 ( V_2 , V_3 ) ;
if ( V_59 )
return V_59 ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ )
F_35 ( V_58 , ( V_9 | 0x10000000 ) ) ;
F_36 ( V_2 ) ;
V_59 = F_17 ( V_58 , V_3 ) ;
if ( V_59 ) {
F_24 ( L_3 , V_59 ) ;
return V_59 ;
}
F_8 ( V_2 ) ;
return V_3 ;
#else
return 0 ;
#endif
}
static int F_37 ( struct V_46 * V_58 )
{
struct V_1 * V_2 = F_32 ( V_58 ) ;
int V_59 ;
#ifdef F_22
T_2 V_77 = V_2 -> V_17 ;
#endif
V_59 = F_19 ( V_2 ) ;
#ifdef F_22
if ( ! V_59 && V_77 != V_2 -> V_17 )
F_36 ( V_2 ) ;
#endif
return V_59 ;
}
int F_38 ( struct V_46 * V_58 , int V_3 )
{
if ( V_3 == 0 )
return F_37 ( V_58 ) ;
else
return F_31 ( V_58 , V_3 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
int V_79 = ( V_78 [ 0 ] & V_80 )
>> V_81 ;
T_1 * V_82 = ( T_1 * ) & V_78 [ 1 ] ;
struct V_24 * V_23 = & V_2 -> V_23 [ V_16 ] ;
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_9 ;
T_2 V_83 ;
T_2 V_84 ;
T_2 V_85 ;
T_2 V_86 = F_26 ( V_5 , F_40 ( V_16 ) ) ;
V_79 = F_41 ( V_79 , V_87 ) ;
V_23 -> V_88 = V_79 ;
for ( V_9 = 0 ; V_9 < V_79 ; V_9 ++ ) {
V_23 -> V_89 [ V_9 ] = V_82 [ V_9 ] ;
}
for ( V_9 = 0 ; V_9 < V_23 -> V_88 ; V_9 ++ ) {
V_84 = ( V_23 -> V_89 [ V_9 ] >> 5 ) & 0x7F ;
V_83 = V_23 -> V_89 [ V_9 ] & 0x1F ;
V_85 = F_26 ( V_5 , F_42 ( V_84 ) ) ;
V_85 |= F_43 ( V_83 ) ;
F_6 ( V_5 , F_42 ( V_84 ) , V_85 ) ;
}
V_86 |= V_90 ;
F_6 ( V_5 , F_40 ( V_16 ) , V_86 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_24 * V_23 ;
int V_9 , V_91 ;
T_2 V_83 ;
T_2 V_84 ;
T_2 V_85 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_3 ; V_9 ++ ) {
T_2 V_86 = F_26 ( V_5 , F_40 ( V_9 ) ) ;
V_23 = & V_2 -> V_23 [ V_9 ] ;
for ( V_91 = 0 ; V_91 < V_23 -> V_88 ; V_91 ++ ) {
V_5 -> V_92 . V_93 ++ ;
V_84 = ( V_23 -> V_89 [ V_91 ] >> 5 ) & 0x7F ;
V_83 = V_23 -> V_89 [ V_91 ] & 0x1F ;
V_85 = F_26 ( V_5 , F_42 ( V_84 ) ) ;
V_85 |= F_43 ( V_83 ) ;
F_6 ( V_5 , F_42 ( V_84 ) , V_85 ) ;
}
if ( V_23 -> V_88 )
V_86 |= V_90 ;
else
V_86 &= ~ V_90 ;
F_6 ( V_5 , F_40 ( V_9 ) , V_86 ) ;
}
F_45 ( V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_94 , int V_95 ,
T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_59 ;
if ( V_94 && F_47 ( V_95 , V_2 -> V_96 ) ) {
V_59 = V_5 -> V_10 . V_97 . V_98 ( V_5 , V_95 , F_48 ( 0 ) , true , false ) ;
if ( V_59 )
return V_59 ;
}
V_59 = V_5 -> V_10 . V_97 . V_98 ( V_5 , V_95 , V_16 , ! ! V_94 , false ) ;
if ( V_94 && ! V_59 )
return V_59 ;
if ( F_47 ( V_95 , V_2 -> V_96 ) ||
( V_2 -> V_37 & V_99 ) )
F_49 ( V_2 , V_95 ) ;
return V_59 ;
}
static T_4 F_50 ( struct V_1 * V_2 , T_2 * V_78 , T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_100 = V_78 [ 1 ] ;
T_2 V_101 ;
if ( V_2 -> V_5 . V_10 . type == V_31 ) {
struct V_102 * V_58 = V_2 -> V_72 ;
int V_103 = V_58 -> V_104 + V_105 ;
T_2 V_106 , V_107 , V_108 ;
T_4 V_59 = 0 ;
#ifdef F_51
if ( V_58 -> V_109 & V_110 )
V_103 = F_52 ( int , V_103 ,
V_111 ) ;
#endif
switch ( V_2 -> V_23 [ V_16 ] . V_112 ) {
case V_113 :
case V_114 :
case V_115 :
if ( V_103 > V_116 )
break;
default:
if ( ( V_103 > V_116 ) ||
( V_100 > ( V_116 + V_117 ) ) )
V_59 = - V_118 ;
break;
}
V_107 = V_16 % 32 ;
V_106 = V_16 / 32 ;
V_108 = F_26 ( V_5 , F_53 ( V_106 ) ) ;
if ( V_59 )
V_108 &= ~ F_43 ( V_107 ) ;
else
V_108 |= F_43 ( V_107 ) ;
F_6 ( V_5 , F_53 ( V_106 ) , V_108 ) ;
if ( V_59 ) {
F_18 ( V_119 , L_8 , V_100 ) ;
return V_59 ;
}
}
if ( V_100 > V_120 ) {
F_18 ( V_119 , L_8 , V_100 ) ;
return - V_118 ;
}
V_101 = F_26 ( V_5 , V_121 ) ;
V_101 &= V_122 ;
V_101 >>= V_123 ;
if ( V_101 < V_100 ) {
V_101 = V_100 << V_123 ;
F_6 ( V_5 , V_121 , V_101 ) ;
}
F_7 ( V_5 , L_9 , V_100 ) ;
return 0 ;
}
static void F_54 ( struct V_4 * V_5 , T_2 V_16 , bool V_124 )
{
T_2 V_86 = F_26 ( V_5 , F_40 ( V_16 ) ) ;
V_86 |= V_125 ;
if ( V_124 )
V_86 |= V_126 ;
else
V_86 &= ~ V_126 ;
F_6 ( V_5 , F_40 ( V_16 ) , V_86 ) ;
}
static void F_55 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_6 ( V_5 , F_56 ( V_16 ) , 0 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_127 , V_128 , V_9 ;
V_128 = ~ F_43 ( F_48 ( 0 ) % 32 ) ;
V_127 = F_43 ( V_16 % 32 ) ;
for ( V_9 = V_129 ; V_9 -- ; ) {
T_2 V_130 [ 2 ] , V_131 , V_95 , V_132 , V_133 ;
T_2 V_134 = V_9 * 2 + V_16 / 32 ;
T_2 V_135 ;
V_131 = F_26 ( V_5 , F_58 ( V_134 ) ) ;
if ( ! ( V_131 & V_127 ) )
continue;
V_131 ^= V_127 ;
V_130 [ V_134 % 2 ] = V_131 ;
V_130 [ ~ V_134 % 2 ] = F_26 ( V_5 , F_58 ( V_134 ^ 1 ) ) ;
if ( V_130 [ ( F_48 ( 0 ) / 32 ) ^ 1 ] ||
( V_130 [ F_48 ( 0 ) / 32 ] & V_128 ) )
goto V_136;
if ( V_130 [ 0 ] || V_130 [ 1 ] )
goto V_137;
V_133 = F_26 ( V_5 , F_59 ( V_9 ) ) ;
if ( ! V_133 )
goto V_136;
V_95 = V_133 & V_138 ;
V_135 = F_43 ( V_95 % 32 ) ;
V_132 = F_26 ( V_5 , F_60 ( V_95 / 32 ) ) ;
if ( V_132 & V_135 )
F_6 ( V_5 , F_60 ( V_95 / 32 ) , V_132 ^ V_135 ) ;
V_137:
F_6 ( V_5 , F_59 ( V_9 ) , 0 ) ;
if ( ! ( V_2 -> V_37 & V_99 ) )
V_131 = 0 ;
V_136:
F_6 ( V_5 , F_58 ( V_134 ) , V_131 ) ;
}
}
static int F_61 ( struct V_1 * V_2 ,
int V_16 , int V_139 , unsigned char * V_140 )
{
struct V_6 * V_141 ;
struct V_142 * V_51 ;
int V_143 = 0 ;
if ( V_139 <= 1 ) {
F_62 (pos, &adapter->vf_mvs.l) {
V_141 = F_63 ( V_51 , struct V_6 , V_15 ) ;
if ( V_141 -> V_16 == V_16 ) {
V_141 -> V_16 = - 1 ;
V_141 -> free = true ;
V_141 -> V_144 = false ;
F_64 ( V_2 ,
V_141 -> V_145 , V_16 ) ;
}
}
}
if ( ! V_139 )
return 0 ;
V_141 = NULL ;
F_62 (pos, &adapter->vf_mvs.l) {
V_141 = F_63 ( V_51 , struct V_6 , V_15 ) ;
if ( V_141 -> free )
break;
}
if ( ! V_141 || ! V_141 -> free )
return - V_146 ;
V_143 = F_65 ( V_2 , V_140 , V_16 ) ;
if ( V_143 < 0 )
return V_143 ;
V_141 -> free = false ;
V_141 -> V_144 = true ;
V_141 -> V_16 = V_16 ;
memcpy ( V_141 -> V_145 , V_140 , V_147 ) ;
return 0 ;
}
static inline void F_66 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_24 * V_23 = & V_2 -> V_23 [ V_16 ] ;
T_3 V_33 = F_33 ( V_2 -> V_72 ) ;
F_57 ( V_2 , V_16 ) ;
F_46 ( V_2 , true , V_23 -> V_148 , V_16 ) ;
F_54 ( V_5 , V_16 , ! V_23 -> V_148 ) ;
if ( ! V_23 -> V_148 && ! V_23 -> V_149 && ! V_33 ) {
F_55 ( V_2 , V_16 ) ;
} else {
if ( V_23 -> V_149 || ! V_33 )
F_67 ( V_2 , V_23 -> V_148 ,
V_23 -> V_149 , V_16 ) ;
else
F_67 ( V_2 , V_23 -> V_148 ,
V_2 -> V_150 , V_16 ) ;
if ( V_23 -> V_40 )
V_5 -> V_10 . V_97 . V_151 ( V_5 , true , V_16 ) ;
}
V_2 -> V_23 [ V_16 ] . V_88 = 0 ;
F_68 ( V_2 -> V_72 ) ;
F_64 ( V_2 , V_2 -> V_23 [ V_16 ] . V_152 , V_16 ) ;
F_61 ( V_2 , V_16 , 0 , NULL ) ;
V_2 -> V_23 [ V_16 ] . V_112 = V_153 ;
}
static int F_69 ( struct V_1 * V_2 ,
int V_16 , unsigned char * V_140 )
{
T_4 V_143 ;
F_64 ( V_2 , V_2 -> V_23 [ V_16 ] . V_152 , V_16 ) ;
V_143 = F_65 ( V_2 , V_140 , V_16 ) ;
if ( V_143 >= 0 )
memcpy ( V_2 -> V_23 [ V_16 ] . V_152 , V_140 ,
V_147 ) ;
else
memset ( V_2 -> V_23 [ V_16 ] . V_152 , 0 , V_147 ) ;
return V_143 ;
}
int F_35 ( struct V_46 * V_47 , unsigned int V_154 )
{
struct V_1 * V_2 = F_32 ( V_47 ) ;
unsigned int V_155 = ( V_154 & 0x3f ) ;
bool V_156 = ( ( V_154 & 0x10000000U ) != 0 ) ;
if ( V_156 )
F_70 ( V_2 -> V_23 [ V_155 ] . V_152 ) ;
return 0 ;
}
static inline void F_71 ( struct V_1 * V_2 , T_2 V_16 ,
T_2 V_157 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_158 * V_159 = & V_2 -> V_20 [ V_21 ] ;
T_2 V_160 = F_72 ( 1 , ~ V_159 -> V_135 ) ;
int V_9 ;
for ( V_9 = V_16 * V_160 ; V_9 < ( ( V_16 + 1 ) * V_160 ) ; V_9 ++ ) {
T_2 V_161 ;
F_27 ( V_5 ) ;
V_161 = V_162 | V_157 ;
V_161 |= V_9 << V_163 ;
F_6 ( V_5 , V_164 , V_161 ) ;
}
}
static int F_73 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_158 * V_159 = & V_2 -> V_20 [ V_21 ] ;
struct V_4 * V_5 = & V_2 -> V_5 ;
unsigned char * V_165 = V_2 -> V_23 [ V_16 ] . V_152 ;
T_2 V_161 , V_106 , V_107 ;
T_2 V_78 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_3 * V_166 = ( T_3 * ) ( & V_78 [ 1 ] ) ;
T_2 V_160 = F_72 ( 1 , ~ V_159 -> V_135 ) ;
int V_9 ;
F_7 ( V_45 , L_10 , V_16 ) ;
F_66 ( V_2 , V_16 ) ;
if ( ! F_74 ( V_165 ) )
F_69 ( V_2 , V_16 , V_165 ) ;
V_107 = V_16 % 32 ;
V_106 = V_16 / 32 ;
V_161 = F_26 ( V_5 , F_75 ( V_106 ) ) ;
V_161 |= F_43 ( V_107 ) ;
F_6 ( V_5 , F_75 ( V_106 ) , V_161 ) ;
F_71 ( V_2 , V_16 , V_167 ) ;
V_161 = F_26 ( V_5 , F_53 ( V_106 ) ) ;
V_161 |= F_43 ( V_107 ) ;
if ( V_2 -> V_5 . V_10 . type == V_31 ) {
struct V_102 * V_58 = V_2 -> V_72 ;
int V_103 = V_58 -> V_104 + V_105 ;
#ifdef F_51
if ( V_58 -> V_109 & V_110 )
V_103 = F_52 ( int , V_103 ,
V_111 ) ;
#endif
if ( V_103 > V_116 )
V_161 &= ~ F_43 ( V_107 ) ;
}
F_6 ( V_5 , F_53 ( V_106 ) , V_161 ) ;
V_2 -> V_23 [ V_16 ] . V_168 = true ;
V_161 = F_26 ( V_5 , F_76 ( V_106 ) ) ;
V_161 |= F_43 ( V_107 ) ;
F_6 ( V_5 , F_76 ( V_106 ) , V_161 ) ;
for ( V_9 = 0 ; V_9 < V_160 ; V_9 ++ ) {
F_6 ( V_5 , F_77 ( V_160 , V_16 , V_9 ) , 0 ) ;
F_6 ( V_5 , F_78 ( V_160 , V_16 , V_9 ) , 0 ) ;
}
V_78 [ 0 ] = V_169 ;
if ( ! F_74 ( V_165 ) ) {
V_78 [ 0 ] |= V_170 ;
memcpy ( V_166 , V_165 , V_147 ) ;
} else {
V_78 [ 0 ] |= V_171 ;
F_15 ( & V_2 -> V_47 -> V_58 ,
L_11 ,
V_16 ) ;
}
V_78 [ 3 ] = V_5 -> V_10 . V_172 ;
F_79 ( V_5 , V_78 , V_173 , V_16 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
T_3 * V_174 = ( ( T_3 * ) ( & V_78 [ 1 ] ) ) ;
if ( ! F_81 ( V_174 ) ) {
F_82 ( V_119 , L_12 , V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_23 [ V_16 ] . V_175 && ! V_2 -> V_23 [ V_16 ] . V_42 &&
! F_83 ( V_2 -> V_23 [ V_16 ] . V_152 , V_174 ) ) {
F_82 ( V_119 ,
L_13
L_14 ,
V_16 ) ;
return - 1 ;
}
return F_69 ( V_2 , V_16 , V_174 ) < 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
T_2 V_94 = ( V_78 [ 0 ] & V_80 ) >> V_81 ;
T_2 V_95 = ( V_78 [ 1 ] & V_176 ) ;
T_3 V_177 = F_33 ( V_2 -> V_72 ) ;
if ( V_2 -> V_23 [ V_16 ] . V_148 || V_177 ) {
F_82 ( V_119 ,
L_15
L_14 ,
V_16 ) ;
return - 1 ;
}
if ( ! V_95 && ! V_94 )
return 0 ;
return F_46 ( V_2 , V_94 , V_95 , V_16 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
T_3 * V_174 = ( ( T_3 * ) ( & V_78 [ 1 ] ) ) ;
int V_139 = ( V_78 [ 0 ] & V_80 ) >>
V_81 ;
int V_59 ;
if ( V_2 -> V_23 [ V_16 ] . V_175 && ! V_2 -> V_23 [ V_16 ] . V_42 &&
V_139 > 0 ) {
F_82 ( V_119 ,
L_16 ,
V_16 ) ;
return - 1 ;
}
if ( V_139 ) {
if ( ! F_81 ( V_174 ) ) {
F_82 ( V_119 , L_12 , V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_23 [ V_16 ] . V_40 ) {
struct V_4 * V_5 = & V_2 -> V_5 ;
V_5 -> V_10 . V_97 . V_178 ( V_5 , false , V_16 ) ;
V_5 -> V_10 . V_97 . V_151 ( V_5 , false , V_16 ) ;
}
}
V_59 = F_61 ( V_2 , V_16 , V_139 , V_174 ) ;
if ( V_59 == - V_146 )
F_82 ( V_119 ,
L_17 ,
V_16 ) ;
return V_59 < 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
int V_179 = V_78 [ 1 ] ;
switch ( V_179 ) {
case V_153 :
case V_113 :
case V_114 :
case V_115 :
V_2 -> V_23 [ V_16 ] . V_112 = V_179 ;
return 0 ;
default:
break;
}
F_7 ( V_119 , L_18 , V_16 , V_179 ) ;
return - 1 ;
}
static int F_87 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
struct V_102 * V_58 = V_2 -> V_72 ;
struct V_158 * V_159 = & V_2 -> V_20 [ V_21 ] ;
unsigned int V_180 = 0 ;
T_3 V_33 = F_33 ( V_58 ) ;
switch ( V_2 -> V_23 [ V_16 ] . V_112 ) {
case V_181 :
case V_113 :
case V_114 :
case V_115 :
break;
default:
return - 1 ;
}
V_78 [ V_182 ] = F_72 ( 1 , ~ V_159 -> V_135 ) ;
V_78 [ V_183 ] = F_72 ( 1 , ~ V_159 -> V_135 ) ;
if ( V_33 > 1 )
V_180 = F_88 ( V_58 , V_2 -> V_150 ) ;
if ( V_33 )
V_78 [ V_184 ] = V_33 ;
else if ( V_2 -> V_23 [ V_16 ] . V_148 || V_2 -> V_23 [ V_16 ] . V_149 )
V_78 [ V_184 ] = 1 ;
else
V_78 [ V_184 ] = 0 ;
V_78 [ V_185 ] = V_180 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , T_2 * V_78 , T_2 V_16 )
{
T_2 V_9 , V_91 ;
T_2 * V_186 = & V_78 [ 1 ] ;
const T_3 * V_187 = V_2 -> V_188 ;
T_2 V_189 = F_90 ( V_2 ) ;
if ( ! V_2 -> V_23 [ V_16 ] . V_41 )
return - V_63 ;
switch ( V_2 -> V_23 [ V_16 ] . V_112 ) {
case V_115 :
case V_114 :
break;
default:
return - V_190 ;
}
for ( V_9 = 0 ; V_9 < V_189 / 16 ; V_9 ++ ) {
V_186 [ V_9 ] = 0 ;
for ( V_91 = 0 ; V_91 < 16 ; V_91 ++ )
V_186 [ V_9 ] |= ( T_2 ) ( V_187 [ 16 * V_9 + V_91 ] & 0x3 ) << ( 2 * V_91 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
T_2 * V_191 = & V_78 [ 1 ] ;
if ( ! V_2 -> V_23 [ V_16 ] . V_41 )
return - V_63 ;
switch ( V_2 -> V_23 [ V_16 ] . V_112 ) {
case V_115 :
case V_114 :
break;
default:
return - V_190 ;
}
memcpy ( V_191 , V_2 -> V_191 , V_192 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
T_2 * V_78 , T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_43 = V_78 [ 1 ] ;
T_2 V_86 , V_193 , V_194 , V_156 ;
switch ( V_2 -> V_23 [ V_16 ] . V_112 ) {
case V_114 :
if ( V_43 == V_195 )
return - V_190 ;
case V_115 :
break;
default:
return - V_190 ;
}
if ( V_43 > V_196 &&
! V_2 -> V_23 [ V_16 ] . V_42 ) {
V_43 = V_196 ;
}
if ( V_2 -> V_23 [ V_16 ] . V_43 == V_43 )
goto V_197;
switch ( V_43 ) {
case V_44 :
V_194 = V_125 | V_90 |
V_198 | V_199 | V_200 ;
V_156 = 0 ;
break;
case V_196 :
V_194 = V_198 | V_199 | V_200 ;
V_156 = V_125 | V_90 ;
break;
case V_201 :
V_194 = V_199 | V_200 ;
V_156 = V_125 | V_90 | V_198 ;
break;
case V_195 :
if ( V_5 -> V_10 . type <= V_31 )
return - V_190 ;
V_193 = F_26 ( V_5 , V_202 ) ;
if ( ! ( V_193 & V_203 ) ) {
F_82 ( V_119 ,
L_19 ) ;
return - V_63 ;
}
V_194 = 0 ;
V_156 = V_125 | V_90 |
V_198 | V_199 | V_200 ;
break;
default:
return - V_190 ;
}
V_86 = F_26 ( V_5 , F_40 ( V_16 ) ) ;
V_86 &= ~ V_194 ;
V_86 |= V_156 ;
F_6 ( V_5 , F_40 ( V_16 ) , V_86 ) ;
V_2 -> V_23 [ V_16 ] . V_43 = V_43 ;
V_197:
V_78 [ 1 ] = V_43 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , T_2 V_16 )
{
T_2 V_204 = V_205 ;
T_2 V_78 [ V_205 ] ;
struct V_4 * V_5 = & V_2 -> V_5 ;
T_4 V_143 ;
V_143 = F_94 ( V_5 , V_78 , V_204 , V_16 ) ;
if ( V_143 ) {
F_95 ( L_20 ) ;
return V_143 ;
}
if ( V_78 [ 0 ] & ( V_170 | V_171 ) )
return 0 ;
F_27 ( V_5 ) ;
if ( V_78 [ 0 ] == V_169 )
return F_73 ( V_2 , V_16 ) ;
if ( ! V_2 -> V_23 [ V_16 ] . V_168 ) {
V_78 [ 0 ] |= V_171 ;
F_79 ( V_5 , V_78 , 1 , V_16 ) ;
return 0 ;
}
switch ( ( V_78 [ 0 ] & 0xFFFF ) ) {
case V_206 :
V_143 = F_80 ( V_2 , V_78 , V_16 ) ;
break;
case V_207 :
V_143 = F_39 ( V_2 , V_78 , V_16 ) ;
break;
case V_208 :
V_143 = F_84 ( V_2 , V_78 , V_16 ) ;
break;
case V_209 :
V_143 = F_50 ( V_2 , V_78 , V_16 ) ;
break;
case V_210 :
V_143 = F_85 ( V_2 , V_78 , V_16 ) ;
break;
case V_211 :
V_143 = F_86 ( V_2 , V_78 , V_16 ) ;
break;
case V_212 :
V_143 = F_87 ( V_2 , V_78 , V_16 ) ;
break;
case V_213 :
V_143 = F_89 ( V_2 , V_78 , V_16 ) ;
break;
case V_214 :
V_143 = F_91 ( V_2 , V_78 , V_16 ) ;
break;
case V_215 :
V_143 = F_92 ( V_2 , V_78 , V_16 ) ;
break;
default:
F_18 ( V_119 , L_21 , V_78 [ 0 ] ) ;
V_143 = V_216 ;
break;
}
if ( V_143 )
V_78 [ 0 ] |= V_171 ;
else
V_78 [ 0 ] |= V_170 ;
V_78 [ 0 ] |= V_217 ;
F_79 ( V_5 , V_78 , V_204 , V_16 ) ;
return V_143 ;
}
static void F_96 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_218 = V_171 ;
if ( ! V_2 -> V_23 [ V_16 ] . V_168 )
F_79 ( V_5 , & V_218 , 1 , V_16 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 ; V_16 ++ ) {
if ( ! F_98 ( V_5 , V_16 ) )
F_66 ( V_2 , V_16 ) ;
if ( ! F_99 ( V_5 , V_16 ) )
F_93 ( V_2 , V_16 ) ;
if ( ! F_100 ( V_5 , V_16 ) )
F_96 ( V_2 , V_16 ) ;
}
}
void F_101 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_6 ( V_5 , F_75 ( 0 ) , 0 ) ;
F_6 ( V_5 , F_75 ( 1 ) , 0 ) ;
F_6 ( V_5 , F_53 ( 0 ) , 0 ) ;
F_6 ( V_5 , F_53 ( 1 ) , 0 ) ;
}
static inline void F_102 ( struct V_1 * V_2 , int V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_219 ;
V_219 = V_220 ;
if ( V_2 -> V_23 [ V_16 ] . V_168 )
V_219 |= V_217 ;
F_79 ( V_5 , & V_219 , 1 , V_16 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_219 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_3 ; V_9 ++ ) {
V_219 = V_220 ;
if ( V_2 -> V_23 [ V_9 ] . V_168 )
V_219 |= V_217 ;
F_79 ( V_5 , & V_219 , 1 , V_9 ) ;
}
}
int F_104 ( struct V_102 * V_72 , int V_16 , T_3 * V_10 )
{
struct V_1 * V_2 = F_105 ( V_72 ) ;
T_4 V_143 ;
if ( V_16 >= V_2 -> V_3 )
return - V_118 ;
if ( F_81 ( V_10 ) ) {
F_106 ( & V_2 -> V_47 -> V_58 , L_22 ,
V_10 , V_16 ) ;
F_106 ( & V_2 -> V_47 -> V_58 , L_23 ) ;
V_143 = F_69 ( V_2 , V_16 , V_10 ) ;
if ( V_143 >= 0 ) {
V_2 -> V_23 [ V_16 ] . V_175 = true ;
if ( F_47 ( V_221 , & V_2 -> V_222 ) ) {
F_15 ( & V_2 -> V_47 -> V_58 , L_24 ) ;
F_15 ( & V_2 -> V_47 -> V_58 , L_25 ) ;
}
} else {
F_15 ( & V_2 -> V_47 -> V_58 , L_26 ) ;
}
} else if ( F_74 ( V_10 ) ) {
unsigned char * V_223 =
V_2 -> V_23 [ V_16 ] . V_152 ;
if ( F_74 ( V_223 ) )
return 0 ;
F_106 ( & V_2 -> V_47 -> V_58 , L_27 , V_16 ) ;
V_143 = F_64 ( V_2 , V_223 , V_16 ) ;
if ( V_143 >= 0 ) {
V_2 -> V_23 [ V_16 ] . V_175 = false ;
memcpy ( V_223 , V_10 , V_147 ) ;
} else {
F_15 ( & V_2 -> V_47 -> V_58 , L_28 ) ;
}
} else {
V_143 = - V_118 ;
}
return V_143 ;
}
static int F_107 ( struct V_1 * V_2 , int V_16 ,
T_1 V_224 , T_3 V_225 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_59 ;
V_59 = F_46 ( V_2 , true , V_224 , V_16 ) ;
if ( V_59 )
goto V_197;
F_46 ( V_2 , false , 0 , V_16 ) ;
F_67 ( V_2 , V_224 , V_225 , V_16 ) ;
F_54 ( V_5 , V_16 , false ) ;
if ( V_5 -> V_10 . type >= V_226 )
F_71 ( V_2 , V_16 , V_167 |
V_227 ) ;
V_2 -> V_23 [ V_16 ] . V_148 = V_224 ;
V_2 -> V_23 [ V_16 ] . V_149 = V_225 ;
F_106 ( & V_2 -> V_47 -> V_58 ,
L_29 , V_224 , V_225 , V_16 ) ;
if ( F_47 ( V_221 , & V_2 -> V_222 ) ) {
F_15 ( & V_2 -> V_47 -> V_58 ,
L_30 ) ;
F_15 ( & V_2 -> V_47 -> V_58 ,
L_25 ) ;
}
V_197:
return V_59 ;
}
static int F_108 ( struct V_1 * V_2 , int V_16 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_59 ;
V_59 = F_46 ( V_2 , false ,
V_2 -> V_23 [ V_16 ] . V_148 , V_16 ) ;
F_46 ( V_2 , true , 0 , V_16 ) ;
F_55 ( V_2 , V_16 ) ;
F_54 ( V_5 , V_16 , true ) ;
if ( V_5 -> V_10 . type >= V_226 )
F_71 ( V_2 , V_16 , V_167 ) ;
V_2 -> V_23 [ V_16 ] . V_148 = 0 ;
V_2 -> V_23 [ V_16 ] . V_149 = 0 ;
return V_59 ;
}
int F_109 ( struct V_102 * V_72 , int V_16 , T_1 V_224 ,
T_3 V_225 , T_5 V_228 )
{
int V_59 = 0 ;
struct V_1 * V_2 = F_105 ( V_72 ) ;
if ( ( V_16 >= V_2 -> V_3 ) || ( V_224 > 4095 ) || ( V_225 > 7 ) )
return - V_118 ;
if ( V_228 != F_110 ( V_229 ) )
return - V_230 ;
if ( V_224 || V_225 ) {
if ( V_2 -> V_23 [ V_16 ] . V_148 )
V_59 = F_108 ( V_2 , V_16 ) ;
if ( V_59 )
goto V_197;
V_59 = F_107 ( V_2 , V_16 , V_224 , V_225 ) ;
} else {
V_59 = F_108 ( V_2 , V_16 ) ;
}
V_197:
return V_59 ;
}
int F_111 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_231 ) {
case V_232 :
return 100 ;
case V_233 :
return 1000 ;
case V_234 :
return 10000 ;
default:
return 0 ;
}
}
static void F_112 ( struct V_1 * V_2 , int V_16 )
{
struct V_158 * V_159 = & V_2 -> V_20 [ V_21 ] ;
struct V_4 * V_5 = & V_2 -> V_5 ;
T_2 V_235 = 0 ;
T_1 V_236 , V_237 ;
T_1 V_238 = V_2 -> V_23 [ V_16 ] . V_238 ;
if ( V_238 ) {
V_235 = V_2 -> V_239 ;
V_235 <<= V_240 ;
V_235 /= V_238 ;
V_235 &= V_241 |
V_242 ;
V_235 |= V_243 ;
}
switch ( V_5 -> V_10 . type ) {
case V_31 :
F_6 ( V_5 , V_244 , 0x4 ) ;
break;
case V_245 :
F_6 ( V_5 , V_244 , 0x14 ) ;
break;
default:
break;
}
V_237 = F_72 ( 1 , ~ V_159 -> V_135 ) ;
for ( V_236 = 0 ; V_236 < V_237 ; V_236 ++ ) {
unsigned int V_246 = ( V_16 * V_237 ) + V_236 ;
F_6 ( V_5 , V_247 , V_246 ) ;
F_6 ( V_5 , V_248 , V_235 ) ;
}
}
void F_113 ( struct V_1 * V_2 )
{
int V_9 ;
if ( ! V_2 -> V_239 )
return;
if ( F_111 ( V_2 ) != V_2 -> V_239 ) {
V_2 -> V_239 = 0 ;
F_106 ( & V_2 -> V_47 -> V_58 ,
L_31 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_3 ; V_9 ++ ) {
if ( ! V_2 -> V_239 )
V_2 -> V_23 [ V_9 ] . V_238 = 0 ;
F_112 ( V_2 , V_9 ) ;
}
}
int F_114 ( struct V_102 * V_72 , int V_16 , int V_249 ,
int V_250 )
{
struct V_1 * V_2 = F_105 ( V_72 ) ;
int V_231 ;
if ( V_16 >= V_2 -> V_3 )
return - V_118 ;
if ( ! V_2 -> V_251 )
return - V_118 ;
V_231 = F_111 ( V_2 ) ;
if ( V_231 != 10000 )
return - V_118 ;
if ( V_249 )
return - V_118 ;
if ( V_250 && ( ( V_250 <= 10 ) || ( V_250 > V_231 ) ) )
return - V_118 ;
V_2 -> V_239 = V_231 ;
V_2 -> V_23 [ V_16 ] . V_238 = V_250 ;
F_112 ( V_2 , V_16 ) ;
return 0 ;
}
int F_115 ( struct V_102 * V_72 , int V_16 , bool V_252 )
{
struct V_1 * V_2 = F_105 ( V_72 ) ;
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( V_16 >= V_2 -> V_3 )
return - V_118 ;
V_2 -> V_23 [ V_16 ] . V_40 = V_252 ;
V_5 -> V_10 . V_97 . V_178 ( V_5 , V_252 , V_16 ) ;
V_5 -> V_10 . V_97 . V_151 ( V_5 , V_252 , V_16 ) ;
if ( V_5 -> V_10 . V_97 . V_253 ) {
F_6 ( V_5 , F_116 ( V_254 ) ,
( V_255 |
V_256 |
V_257 ) ) ;
F_6 ( V_5 , F_116 ( V_258 ) ,
( V_255 |
V_256 |
V_259 ) ) ;
V_5 -> V_10 . V_97 . V_253 ( V_5 , V_252 , V_16 ) ;
}
return 0 ;
}
int F_117 ( struct V_102 * V_72 , int V_16 ,
bool V_252 )
{
struct V_1 * V_2 = F_105 ( V_72 ) ;
if ( V_2 -> V_5 . V_10 . type < V_31 ||
V_2 -> V_5 . V_10 . type >= V_226 )
return - V_190 ;
if ( V_16 >= V_2 -> V_3 )
return - V_118 ;
V_2 -> V_23 [ V_16 ] . V_41 = V_252 ;
return 0 ;
}
int F_118 ( struct V_102 * V_72 , int V_16 , bool V_252 )
{
struct V_1 * V_2 = F_105 ( V_72 ) ;
if ( V_16 >= V_2 -> V_3 )
return - V_118 ;
if ( V_2 -> V_23 [ V_16 ] . V_42 == V_252 )
return 0 ;
V_2 -> V_23 [ V_16 ] . V_42 = V_252 ;
V_2 -> V_23 [ V_16 ] . V_168 = false ;
F_102 ( V_2 , V_16 ) ;
F_7 ( V_119 , L_32 , V_16 , V_252 ? L_33 : L_34 ) ;
return 0 ;
}
int F_119 ( struct V_102 * V_72 ,
int V_16 , struct V_260 * V_261 )
{
struct V_1 * V_2 = F_105 ( V_72 ) ;
if ( V_16 >= V_2 -> V_3 )
return - V_118 ;
V_261 -> V_16 = V_16 ;
memcpy ( & V_261 -> V_10 , V_2 -> V_23 [ V_16 ] . V_152 , V_147 ) ;
V_261 -> V_250 = V_2 -> V_23 [ V_16 ] . V_238 ;
V_261 -> V_249 = 0 ;
V_261 -> V_224 = V_2 -> V_23 [ V_16 ] . V_148 ;
V_261 -> V_225 = V_2 -> V_23 [ V_16 ] . V_149 ;
V_261 -> V_262 = V_2 -> V_23 [ V_16 ] . V_40 ;
V_261 -> V_263 = V_2 -> V_23 [ V_16 ] . V_41 ;
V_261 -> V_42 = V_2 -> V_23 [ V_16 ] . V_42 ;
return 0 ;
}
