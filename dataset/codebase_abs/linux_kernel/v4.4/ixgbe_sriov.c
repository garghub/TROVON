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
void F_7 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
V_46 = F_8 ( V_2 -> V_47 ) ;
if ( ! V_46 && ! V_2 -> V_12 )
return;
if ( V_46 ) {
V_2 -> V_12 = V_46 ;
F_9 ( & V_2 -> V_47 -> V_48 ,
L_2 ) ;
} else {
int V_49 ;
V_2 -> V_12 = F_10 (unsigned int, adapter->num_vfs, IXGBE_MAX_VFS_DRV_LIMIT) ;
V_49 = F_11 ( V_2 -> V_47 , V_2 -> V_12 ) ;
if ( V_49 ) {
F_12 ( V_11 , L_3 , V_49 ) ;
V_2 -> V_12 = 0 ;
return;
}
}
if ( ! F_1 ( V_2 ) )
return;
F_12 ( V_11 , L_4
L_5 ) ;
F_13 ( V_2 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_50 ;
T_1 V_51 ;
int V_52 ;
V_2 -> V_12 = 0 ;
F_14 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
F_14 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
#ifdef F_15
if ( F_16 ( V_2 -> V_47 ) ) {
F_17 ( L_6 ) ;
return - V_53 ;
}
F_18 ( V_2 -> V_47 ) ;
#endif
F_6 ( V_4 , V_54 , 0 ) ;
V_50 = F_19 ( V_4 , V_55 ) ;
V_50 &= ~ V_56 ;
F_6 ( V_4 , V_55 , V_50 ) ;
V_51 = F_19 ( V_4 , V_57 ) ;
V_51 &= ~ V_58 ;
F_6 ( V_4 , V_57 , V_51 ) ;
F_20 ( V_4 ) ;
if ( V_2 -> V_14 [ V_15 ] . V_16 == 1 ) {
V_2 -> V_9 &= ~ V_13 ;
V_2 -> V_9 &= ~ V_10 ;
V_52 = F_10 ( int , F_21 ( V_2 ) ,
F_22 () ) ;
} else {
V_52 = F_10 ( int , V_59 , F_22 () ) ;
}
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_2 -> V_14 [ V_60 ] . V_16 = V_52 ;
F_23 ( 100 ) ;
return 0 ;
}
static int F_24 ( struct V_61 * V_48 , int V_12 )
{
#ifdef F_15
struct V_1 * V_2 = F_25 ( V_48 ) ;
int V_49 = 0 ;
int V_6 ;
int V_46 = F_8 ( V_48 ) ;
if ( V_46 && V_46 != V_12 )
V_49 = F_13 ( V_2 ) ;
else if ( V_46 && V_46 == V_12 )
return V_12 ;
if ( V_49 )
return V_49 ;
if ( ( V_12 + V_2 -> V_62 ) > V_63 )
return - V_53 ;
V_2 -> V_12 = V_12 ;
V_49 = F_1 ( V_2 ) ;
if ( V_49 )
return V_49 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_26 ( V_48 , ( V_6 | 0x10000000 ) ) ;
V_49 = F_11 ( V_48 , V_12 ) ;
if ( V_49 ) {
F_17 ( L_3 , V_49 ) ;
return V_49 ;
}
F_27 ( V_2 ) ;
return V_12 ;
#else
return 0 ;
#endif
}
static int F_28 ( struct V_61 * V_48 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
int V_49 ;
#ifdef F_15
T_1 V_64 = V_2 -> V_9 ;
#endif
V_49 = F_13 ( V_2 ) ;
#ifdef F_15
if ( ! V_49 && V_64 != V_2 -> V_9 )
F_27 ( V_2 ) ;
#endif
return V_49 ;
}
int F_29 ( struct V_61 * V_48 , int V_12 )
{
if ( V_12 == 0 )
return F_28 ( V_48 ) ;
else
return F_24 ( V_48 , V_12 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
int V_66 = ( V_65 [ 0 ] & V_67 )
>> V_68 ;
T_2 * V_69 = ( T_2 * ) & V_65 [ 1 ] ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
T_1 V_73 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_66 = F_32 ( V_66 , V_74 ) ;
V_29 -> V_75 = V_66 ;
for ( V_6 = 0 ; V_6 < V_66 ; V_6 ++ ) {
V_29 -> V_76 [ V_6 ] = V_69 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_29 -> V_75 ; V_6 ++ ) {
V_71 = ( V_29 -> V_76 [ V_6 ] >> 5 ) & 0x7F ;
V_70 = V_29 -> V_76 [ V_6 ] & 0x1F ;
V_72 = F_19 ( V_4 , F_33 ( V_71 ) ) ;
V_72 |= ( 1 << V_70 ) ;
F_6 ( V_4 , F_33 ( V_71 ) , V_72 ) ;
}
V_73 |= V_77 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_73 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 ;
int V_6 , V_78 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
T_1 V_73 = F_19 ( V_4 , F_31 ( V_6 ) ) ;
V_29 = & V_2 -> V_29 [ V_6 ] ;
for ( V_78 = 0 ; V_78 < V_29 -> V_75 ; V_78 ++ ) {
V_4 -> V_79 . V_80 ++ ;
V_71 = ( V_29 -> V_76 [ V_78 ] >> 5 ) & 0x7F ;
V_70 = V_29 -> V_76 [ V_78 ] & 0x1F ;
V_72 = F_19 ( V_4 , F_33 ( V_71 ) ) ;
V_72 |= ( 1 << V_70 ) ;
F_6 ( V_4 , F_33 ( V_71 ) , V_72 ) ;
}
if ( V_29 -> V_75 )
V_73 |= V_77 ;
else
V_73 &= ~ V_77 ;
F_6 ( V_4 , F_31 ( V_6 ) , V_73 ) ;
}
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_81 , int V_82 ,
T_1 V_24 )
{
if ( ! V_82 && ! V_81 )
return 0 ;
return V_2 -> V_4 . V_18 . V_83 . V_84 ( & V_2 -> V_4 , V_82 , V_24 , ( bool ) V_81 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 , T_1 * V_65 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_85 = V_65 [ 1 ] ;
T_1 V_86 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_87 * V_48 = V_2 -> V_88 ;
int V_89 = V_48 -> V_90 + V_91 ;
T_1 V_92 , V_93 , V_94 ;
T_3 V_49 = 0 ;
#ifdef F_38
if ( V_48 -> V_95 & V_96 )
V_89 = F_39 ( int , V_89 ,
V_97 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_98 ) {
case V_99 :
case V_100 :
if ( V_89 > V_101 )
break;
default:
if ( ( V_89 > V_101 ) ||
( V_85 > ( V_101 + V_102 ) ) )
V_49 = - V_103 ;
break;
}
V_93 = V_24 % 32 ;
V_92 = V_24 / 32 ;
V_94 = F_19 ( V_4 , F_40 ( V_92 ) ) ;
if ( V_49 )
V_94 &= ~ ( 1 << V_93 ) ;
else
V_94 |= 1 << V_93 ;
F_6 ( V_4 , F_40 ( V_92 ) , V_94 ) ;
if ( V_49 ) {
F_12 ( V_104 , L_7 , V_85 ) ;
return V_49 ;
}
}
if ( V_85 > V_105 ) {
F_12 ( V_104 , L_7 , V_85 ) ;
return - V_103 ;
}
V_86 = F_19 ( V_4 , V_106 ) ;
V_86 &= V_107 ;
V_86 >>= V_108 ;
if ( V_86 < V_85 ) {
V_86 = V_85 << V_108 ;
F_6 ( V_4 , V_106 , V_86 ) ;
}
F_2 ( V_4 , L_8 , V_85 ) ;
return 0 ;
}
static void F_41 ( struct V_3 * V_4 , T_1 V_24 , bool V_109 )
{
T_1 V_73 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_73 |= V_110 ;
if ( V_109 )
V_73 |= V_111 ;
else
V_73 &= ~ V_111 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_73 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_43 ( V_24 ) , 0 ) ;
}
static inline void F_44 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
T_4 V_33 = F_45 ( V_2 -> V_88 ) ;
F_36 ( V_2 , true , V_29 -> V_112 , V_24 ) ;
F_41 ( V_4 , V_24 , ! V_29 -> V_112 ) ;
if ( ! V_29 -> V_112 && ! V_29 -> V_113 && ! V_33 ) {
F_42 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_113 || ! V_33 )
F_46 ( V_2 , V_29 -> V_112 ,
V_29 -> V_113 , V_24 ) ;
else
F_46 ( V_2 , V_29 -> V_112 ,
V_2 -> V_114 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_83 . V_115 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_75 = 0 ;
F_47 ( V_2 -> V_88 ) ;
F_48 ( V_2 , V_2 -> V_29 [ V_24 ] . V_116 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_98 = V_117 ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_118 )
{
F_48 ( V_2 , V_2 -> V_29 [ V_24 ] . V_116 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_116 , V_118 , V_119 ) ;
F_50 ( V_2 , V_2 -> V_29 [ V_24 ] . V_116 , V_24 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_24 , int V_120 , unsigned char * V_118 )
{
struct V_121 * V_122 ;
struct V_7 * V_123 ;
if ( V_120 <= 1 ) {
F_52 (pos, &adapter->vf_mvs.l) {
V_123 = F_53 ( V_122 , struct V_7 , V_23 ) ;
if ( V_123 -> V_24 == V_24 ) {
V_123 -> V_24 = - 1 ;
V_123 -> free = true ;
V_123 -> V_124 = false ;
F_48 ( V_2 ,
V_123 -> V_125 , V_24 ) ;
}
}
}
if ( ! V_120 )
return 0 ;
V_123 = NULL ;
F_52 (pos, &adapter->vf_mvs.l) {
V_123 = F_53 ( V_122 , struct V_7 , V_23 ) ;
if ( V_123 -> free )
break;
}
if ( ! V_123 || ! V_123 -> free )
return - V_126 ;
V_123 -> free = false ;
V_123 -> V_124 = true ;
V_123 -> V_24 = V_24 ;
memcpy ( V_123 -> V_125 , V_118 , V_119 ) ;
F_50 ( V_2 , V_118 , V_24 ) ;
return 0 ;
}
int F_26 ( struct V_61 * V_47 , unsigned int V_127 )
{
struct V_1 * V_2 = F_25 ( V_47 ) ;
unsigned int V_128 = ( V_127 & 0x3f ) ;
bool V_129 = ( ( V_127 & 0x10000000U ) != 0 ) ;
if ( V_129 )
F_54 ( V_2 -> V_29 [ V_128 ] . V_116 ) ;
return 0 ;
}
static inline void F_55 ( struct V_1 * V_2 , T_1 V_24 ,
T_1 V_130 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_131 * V_132 = & V_2 -> V_14 [ V_15 ] ;
T_1 V_133 = F_56 ( 1 , ~ V_132 -> V_134 ) ;
int V_6 ;
for ( V_6 = V_24 * V_133 ; V_6 < ( ( V_24 + 1 ) * V_133 ) ; V_6 ++ ) {
T_1 V_135 ;
F_20 ( V_4 ) ;
V_135 = V_136 | V_137 ;
V_135 |= V_6 << V_138 ;
F_6 ( V_4 , V_139 , V_135 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_131 * V_132 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_140 = V_2 -> V_29 [ V_24 ] . V_116 ;
T_1 V_135 , V_92 , V_93 ;
T_1 V_65 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_141 = ( T_4 * ) ( & V_65 [ 1 ] ) ;
T_1 V_133 = F_56 ( 1 , ~ V_132 -> V_134 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_44 ( V_2 , V_24 ) ;
if ( ! F_58 ( V_140 ) )
F_49 ( V_2 , V_24 , V_140 ) ;
V_93 = V_24 % 32 ;
V_92 = V_24 / 32 ;
V_135 = F_19 ( V_4 , F_59 ( V_92 ) ) ;
V_135 |= 1 << V_93 ;
F_6 ( V_4 , F_59 ( V_92 ) , V_135 ) ;
F_55 ( V_2 , V_24 , V_137 ) ;
V_135 = F_19 ( V_4 , F_40 ( V_92 ) ) ;
V_135 |= 1 << V_93 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_87 * V_48 = V_2 -> V_88 ;
int V_89 = V_48 -> V_90 + V_91 ;
#ifdef F_38
if ( V_48 -> V_95 & V_96 )
V_89 = F_39 ( int , V_89 ,
V_97 ) ;
#endif
if ( V_89 > V_101 )
V_135 &= ~ ( 1 << V_93 ) ;
}
F_6 ( V_4 , F_40 ( V_92 ) , V_135 ) ;
V_2 -> V_29 [ V_24 ] . V_142 = true ;
V_135 = F_19 ( V_4 , F_60 ( V_92 ) ) ;
V_135 |= ( 1 << V_93 ) ;
F_6 ( V_4 , F_60 ( V_92 ) , V_135 ) ;
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ ) {
F_6 ( V_4 , F_61 ( V_133 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_62 ( V_133 , V_24 , V_6 ) , 0 ) ;
}
V_65 [ 0 ] = V_143 ;
if ( ! F_58 ( V_140 ) ) {
V_65 [ 0 ] |= V_144 ;
memcpy ( V_141 , V_140 , V_119 ) ;
} else {
V_65 [ 0 ] |= V_145 ;
F_9 ( & V_2 -> V_47 -> V_48 ,
L_10 ,
V_24 ) ;
}
V_65 [ 3 ] = V_4 -> V_18 . V_146 ;
F_63 ( V_4 , V_65 , V_147 , V_24 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
T_4 * V_148 = ( ( T_4 * ) ( & V_65 [ 1 ] ) ) ;
if ( ! F_65 ( V_148 ) ) {
F_66 ( V_104 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_149 &&
! F_67 ( V_2 -> V_29 [ V_24 ] . V_116 , V_148 ) ) {
F_66 ( V_104 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_49 ( V_2 , V_24 , V_148 ) < 0 ;
}
static int F_68 ( struct V_3 * V_4 , T_1 V_150 )
{
T_1 V_151 ;
T_3 V_152 ;
if ( V_150 == 0 )
return 0 ;
for ( V_152 = 1 ; V_152 < V_153 ; V_152 ++ ) {
V_151 = F_19 ( V_4 , F_69 ( V_152 ) ) ;
if ( ( V_151 & V_154 ) == V_150 )
break;
}
if ( V_152 >= V_153 )
V_152 = - 1 ;
return V_152 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_81 = ( V_65 [ 0 ] & V_67 ) >> V_68 ;
int V_82 = ( V_65 [ 1 ] & V_155 ) ;
int V_49 ;
T_3 V_156 ;
T_1 V_151 ;
T_1 V_157 ;
T_4 V_158 = F_45 ( V_2 -> V_88 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_112 || V_158 ) {
F_66 ( V_104 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( V_81 )
V_2 -> V_29 [ V_24 ] . V_159 ++ ;
else if ( V_2 -> V_29 [ V_24 ] . V_159 )
V_2 -> V_29 [ V_24 ] . V_159 -- ;
if ( V_81 && V_2 -> V_88 -> V_9 & V_160 )
V_49 = F_36 ( V_2 , V_81 , V_82 , F_71 ( 0 ) ) ;
V_49 = F_36 ( V_2 , V_81 , V_82 , V_24 ) ;
if ( ! V_49 && V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_83 . V_115 ( V_4 , true , V_24 ) ;
if ( ! V_81 && V_2 -> V_88 -> V_9 & V_160 ) {
V_156 = F_68 ( V_4 , V_82 ) ;
if ( V_156 < 0 )
return V_49 ;
V_151 = F_19 ( V_4 , F_69 ( V_156 ) ) ;
if ( F_71 ( 0 ) < 32 ) {
V_157 = F_19 ( V_4 , F_72 ( V_156 * 2 ) ) ;
V_157 &= ~ ( 1 << F_71 ( 0 ) ) ;
V_157 |= F_19 ( V_4 ,
F_72 ( V_156 * 2 ) + 1 ) ;
} else {
V_157 = F_19 ( V_4 ,
F_72 ( V_156 * 2 ) + 1 ) ;
V_157 &= ~ ( 1 << ( F_71 ( 0 ) - 32 ) ) ;
V_157 |= F_19 ( V_4 , F_72 ( V_156 * 2 ) ) ;
}
if ( ( V_151 & V_154 ) == V_82 &&
! F_73 ( V_82 , V_2 -> V_161 ) && ! V_157 )
F_36 ( V_2 , V_81 , V_82 , F_71 ( 0 ) ) ;
}
return V_49 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
T_4 * V_148 = ( ( T_4 * ) ( & V_65 [ 1 ] ) ) ;
int V_120 = ( V_65 [ 0 ] & V_67 ) >>
V_68 ;
int V_49 ;
if ( V_2 -> V_29 [ V_24 ] . V_149 && V_120 > 0 ) {
F_66 ( V_104 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_120 ) {
if ( ! F_65 ( V_148 ) ) {
F_66 ( V_104 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 )
F_75 ( V_2 -> V_88 , V_24 , false ) ;
}
V_49 = F_51 ( V_2 , V_24 , V_120 , V_148 ) ;
if ( V_49 == - V_126 )
F_66 ( V_104 ,
L_16 ,
V_24 ) ;
return V_49 < 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
int V_162 = V_65 [ 1 ] ;
switch ( V_162 ) {
case V_117 :
case V_99 :
case V_100 :
V_2 -> V_29 [ V_24 ] . V_98 = V_162 ;
return 0 ;
default:
break;
}
F_2 ( V_104 , L_17 , V_24 , V_162 ) ;
return - 1 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
struct V_87 * V_48 = V_2 -> V_88 ;
struct V_131 * V_132 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_163 = 0 ;
T_4 V_33 = F_45 ( V_48 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_98 ) {
case V_164 :
case V_99 :
case V_100 :
break;
default:
return - 1 ;
}
V_65 [ V_165 ] = F_56 ( 1 , ~ V_132 -> V_134 ) ;
V_65 [ V_166 ] = F_56 ( 1 , ~ V_132 -> V_134 ) ;
if ( V_33 > 1 )
V_163 = F_78 ( V_48 , V_2 -> V_114 ) ;
if ( V_33 )
V_65 [ V_167 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_112 || V_2 -> V_29 [ V_24 ] . V_113 )
V_65 [ V_167 ] = 1 ;
else
V_65 [ V_167 ] = 0 ;
V_65 [ V_168 ] = V_163 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 * V_65 , T_1 V_24 )
{
T_1 V_6 , V_78 ;
T_1 * V_169 = & V_65 [ 1 ] ;
const T_4 * V_170 = V_2 -> V_171 ;
T_1 V_172 = F_80 ( V_2 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_53 ;
if ( V_2 -> V_29 [ V_24 ] . V_98 != V_100 )
return - V_173 ;
for ( V_6 = 0 ; V_6 < V_172 / 16 ; V_6 ++ ) {
V_169 [ V_6 ] = 0 ;
for ( V_78 = 0 ; V_78 < 16 ; V_78 ++ )
V_169 [ V_6 ] |= ( T_1 ) ( V_170 [ 16 * V_6 + V_78 ] & 0x3 ) << ( 2 * V_78 ) ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
T_1 * V_174 = & V_65 [ 1 ] ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_53 ;
if ( V_2 -> V_29 [ V_24 ] . V_98 != V_100 )
return - V_173 ;
memcpy ( V_174 , V_2 -> V_174 , sizeof( V_2 -> V_174 ) ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_1 * V_65 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_43 = V_65 [ 1 ] ;
T_1 V_73 , V_175 , V_129 ;
switch ( V_2 -> V_29 [ V_24 ] . V_98 ) {
case V_100 :
break;
default:
return - V_173 ;
}
if ( V_43 > V_176 &&
! V_2 -> V_29 [ V_24 ] . V_42 ) {
V_43 = V_176 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_43 == V_43 )
goto V_177;
switch ( V_43 ) {
case V_44 :
V_175 = V_110 | V_77 | V_178 ;
V_129 = 0 ;
break;
case V_176 :
V_175 = V_178 ;
V_129 = V_110 | V_77 ;
break;
case V_179 :
V_175 = 0 ;
V_129 = V_110 | V_77 | V_178 ;
break;
default:
return - V_173 ;
}
V_73 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_73 &= ~ V_175 ;
V_73 |= V_129 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_73 ) ;
V_2 -> V_29 [ V_24 ] . V_43 = V_43 ;
V_177:
V_65 [ 1 ] = V_43 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_180 = V_181 ;
T_1 V_65 [ V_181 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_182 ;
V_182 = F_84 ( V_4 , V_65 , V_180 , V_24 ) ;
if ( V_182 ) {
F_85 ( L_18 ) ;
return V_182 ;
}
if ( V_65 [ 0 ] & ( V_144 | V_145 ) )
return 0 ;
F_20 ( V_4 ) ;
if ( V_65 [ 0 ] == V_143 )
return F_57 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_142 ) {
V_65 [ 0 ] |= V_145 ;
F_63 ( V_4 , V_65 , 1 , V_24 ) ;
return 0 ;
}
switch ( ( V_65 [ 0 ] & 0xFFFF ) ) {
case V_183 :
V_182 = F_64 ( V_2 , V_65 , V_24 ) ;
break;
case V_184 :
V_182 = F_30 ( V_2 , V_65 , V_24 ) ;
break;
case V_185 :
V_182 = F_70 ( V_2 , V_65 , V_24 ) ;
break;
case V_186 :
V_182 = F_37 ( V_2 , V_65 , V_24 ) ;
break;
case V_187 :
V_182 = F_74 ( V_2 , V_65 , V_24 ) ;
break;
case V_188 :
V_182 = F_76 ( V_2 , V_65 , V_24 ) ;
break;
case V_189 :
V_182 = F_77 ( V_2 , V_65 , V_24 ) ;
break;
case V_190 :
V_182 = F_79 ( V_2 , V_65 , V_24 ) ;
break;
case V_191 :
V_182 = F_81 ( V_2 , V_65 , V_24 ) ;
break;
case V_192 :
V_182 = F_82 ( V_2 , V_65 , V_24 ) ;
break;
default:
F_12 ( V_104 , L_19 , V_65 [ 0 ] ) ;
V_182 = V_193 ;
break;
}
if ( V_182 )
V_65 [ 0 ] |= V_145 ;
else
V_65 [ 0 ] |= V_144 ;
V_65 [ 0 ] |= V_194 ;
F_63 ( V_4 , V_65 , V_180 , V_24 ) ;
return V_182 ;
}
static void F_86 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_195 = V_145 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_142 )
F_63 ( V_4 , & V_195 , 1 , V_24 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_88 ( V_4 , V_24 ) )
F_44 ( V_2 , V_24 ) ;
if ( ! F_89 ( V_4 , V_24 ) )
F_83 ( V_2 , V_24 ) ;
if ( ! F_90 ( V_4 , V_24 ) )
F_86 ( V_2 , V_24 ) ;
}
}
void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_59 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_59 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 1 ) , 0 ) ;
}
static inline void F_92 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_196 ;
V_196 = V_197 ;
if ( V_2 -> V_29 [ V_24 ] . V_142 )
V_196 |= V_194 ;
F_63 ( V_4 , & V_196 , 1 , V_24 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_196 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_196 = V_197 ;
if ( V_2 -> V_29 [ V_6 ] . V_142 )
V_196 |= V_194 ;
F_63 ( V_4 , & V_196 , 1 , V_6 ) ;
}
}
int F_94 ( struct V_87 * V_88 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_95 ( V_88 ) ;
if ( ! F_65 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_103 ;
V_2 -> V_29 [ V_24 ] . V_149 = true ;
F_96 ( & V_2 -> V_47 -> V_48 , L_20 , V_18 , V_24 ) ;
F_96 ( & V_2 -> V_47 -> V_48 , L_21
L_22 ) ;
if ( F_73 ( V_198 , & V_2 -> V_199 ) ) {
F_9 ( & V_2 -> V_47 -> V_48 , L_23
L_24 ) ;
F_9 ( & V_2 -> V_47 -> V_48 , L_25
L_26 ) ;
}
return F_49 ( V_2 , V_24 , V_18 ) ;
}
static int F_97 ( struct V_1 * V_2 , int V_24 ,
T_2 V_150 , T_4 V_200 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_49 ;
V_49 = F_36 ( V_2 , true , V_150 , V_24 ) ;
if ( V_49 )
goto V_177;
F_46 ( V_2 , V_150 , V_200 , V_24 ) ;
F_41 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_83 . V_115 ( V_4 , true , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_159 ++ ;
if ( V_4 -> V_18 . type >= V_201 )
F_55 ( V_2 , V_24 , V_137 |
V_202 ) ;
V_2 -> V_29 [ V_24 ] . V_112 = V_150 ;
V_2 -> V_29 [ V_24 ] . V_113 = V_200 ;
F_96 ( & V_2 -> V_47 -> V_48 ,
L_27 , V_150 , V_200 , V_24 ) ;
if ( F_73 ( V_198 , & V_2 -> V_199 ) ) {
F_9 ( & V_2 -> V_47 -> V_48 ,
L_28 ) ;
F_9 ( & V_2 -> V_47 -> V_48 ,
L_29 ) ;
}
V_177:
return V_49 ;
}
static int F_98 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_49 ;
V_49 = F_36 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_112 , V_24 ) ;
F_42 ( V_2 , V_24 ) ;
F_41 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_83 . V_115 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_159 )
V_2 -> V_29 [ V_24 ] . V_159 -- ;
if ( V_4 -> V_18 . type >= V_201 )
F_55 ( V_2 , V_24 , V_137 ) ;
V_2 -> V_29 [ V_24 ] . V_112 = 0 ;
V_2 -> V_29 [ V_24 ] . V_113 = 0 ;
return V_49 ;
}
int F_99 ( struct V_87 * V_88 , int V_24 , T_2 V_150 , T_4 V_200 )
{
int V_49 = 0 ;
struct V_1 * V_2 = F_95 ( V_88 ) ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_150 > 4095 ) || ( V_200 > 7 ) )
return - V_103 ;
if ( V_150 || V_200 ) {
if ( V_2 -> V_29 [ V_24 ] . V_112 )
V_49 = F_98 ( V_2 , V_24 ) ;
if ( V_49 )
goto V_177;
V_49 = F_97 ( V_2 , V_24 , V_150 , V_200 ) ;
} else {
V_49 = F_98 ( V_2 , V_24 ) ;
}
V_177:
return V_49 ;
}
static int F_100 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_203 ) {
case V_204 :
return 100 ;
case V_205 :
return 1000 ;
case V_206 :
return 10000 ;
default:
return 0 ;
}
}
static void F_101 ( struct V_1 * V_2 , int V_24 )
{
struct V_131 * V_132 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_207 = 0 ;
T_2 V_208 , V_209 ;
T_2 V_210 = V_2 -> V_29 [ V_24 ] . V_210 ;
if ( V_210 ) {
V_207 = V_2 -> V_211 ;
V_207 <<= V_212 ;
V_207 /= V_210 ;
V_207 &= V_213 |
V_214 ;
V_207 |= V_215 ;
}
switch ( V_4 -> V_18 . type ) {
case V_31 :
F_6 ( V_4 , V_216 , 0x4 ) ;
break;
case V_217 :
F_6 ( V_4 , V_216 , 0x14 ) ;
break;
default:
break;
}
V_209 = F_56 ( 1 , ~ V_132 -> V_134 ) ;
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ ) {
unsigned int V_218 = ( V_24 * V_209 ) + V_208 ;
F_6 ( V_4 , V_219 , V_218 ) ;
F_6 ( V_4 , V_220 , V_207 ) ;
}
}
void F_102 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_211 )
return;
if ( F_100 ( V_2 ) != V_2 -> V_211 ) {
V_2 -> V_211 = 0 ;
F_96 ( & V_2 -> V_47 -> V_48 ,
L_30 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_211 )
V_2 -> V_29 [ V_6 ] . V_210 = 0 ;
F_101 ( V_2 , V_6 ) ;
}
}
int F_103 ( struct V_87 * V_88 , int V_24 , int V_221 ,
int V_222 )
{
struct V_1 * V_2 = F_95 ( V_88 ) ;
int V_203 ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
if ( ! V_2 -> V_223 )
return - V_103 ;
V_203 = F_100 ( V_2 ) ;
if ( V_203 != 10000 )
return - V_103 ;
if ( V_221 )
return - V_103 ;
if ( V_222 && ( ( V_222 <= 10 ) || ( V_222 > V_203 ) ) )
return - V_103 ;
V_2 -> V_211 = V_203 ;
V_2 -> V_29 [ V_24 ] . V_210 = V_222 ;
F_101 ( V_2 , V_24 ) ;
return 0 ;
}
int F_75 ( struct V_87 * V_88 , int V_24 , bool V_224 )
{
struct V_1 * V_2 = F_95 ( V_88 ) ;
int V_225 = V_24 >> 3 ;
int V_226 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_227 ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_224 ;
V_227 = F_19 ( V_4 , F_104 ( V_225 ) ) ;
V_227 &= ~ ( 1 << V_226 ) ;
V_227 |= ( V_224 << V_226 ) ;
F_6 ( V_4 , F_104 ( V_225 ) , V_227 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_159 ) {
V_226 += V_228 ;
V_227 = F_19 ( V_4 , F_104 ( V_225 ) ) ;
V_227 &= ~ ( 1 << V_226 ) ;
V_227 |= ( V_224 << V_226 ) ;
F_6 ( V_4 , F_104 ( V_225 ) , V_227 ) ;
}
return 0 ;
}
int F_105 ( struct V_87 * V_88 , int V_24 ,
bool V_224 )
{
struct V_1 * V_2 = F_95 ( V_88 ) ;
if ( V_2 -> V_4 . V_18 . type < V_31 ||
V_2 -> V_4 . V_18 . type >= V_201 )
return - V_173 ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
V_2 -> V_29 [ V_24 ] . V_41 = V_224 ;
return 0 ;
}
int F_106 ( struct V_87 * V_88 , int V_24 , bool V_224 )
{
struct V_1 * V_2 = F_95 ( V_88 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
if ( V_2 -> V_29 [ V_24 ] . V_42 == V_224 )
return 0 ;
V_2 -> V_29 [ V_24 ] . V_42 = V_224 ;
V_2 -> V_29 [ V_24 ] . V_142 = false ;
F_92 ( V_2 , V_24 ) ;
F_2 ( V_104 , L_31 , V_24 , V_224 ? L_32 : L_33 ) ;
return 0 ;
}
int F_107 ( struct V_87 * V_88 ,
int V_24 , struct V_229 * V_230 )
{
struct V_1 * V_2 = F_95 ( V_88 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
V_230 -> V_24 = V_24 ;
memcpy ( & V_230 -> V_18 , V_2 -> V_29 [ V_24 ] . V_116 , V_119 ) ;
V_230 -> V_222 = V_2 -> V_29 [ V_24 ] . V_210 ;
V_230 -> V_221 = 0 ;
V_230 -> V_150 = V_2 -> V_29 [ V_24 ] . V_112 ;
V_230 -> V_200 = V_2 -> V_29 [ V_24 ] . V_113 ;
V_230 -> V_231 = V_2 -> V_29 [ V_24 ] . V_40 ;
V_230 -> V_232 = V_2 -> V_29 [ V_24 ] . V_41 ;
V_230 -> V_42 = V_2 -> V_29 [ V_24 ] . V_42 ;
return 0 ;
}
