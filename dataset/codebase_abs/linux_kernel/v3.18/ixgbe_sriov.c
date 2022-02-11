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
V_2 -> V_27 |= V_28 ;
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
V_2 -> V_14 [ V_37 ] . V_16 = 1 ;
V_2 -> V_27 &= ~ ( V_38 |
V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
V_2 -> V_29 [ V_6 ] . V_40 = true ;
return 0 ;
}
return - V_41 ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
V_42 = F_8 ( V_2 -> V_43 ) ;
if ( ! V_42 && ! V_2 -> V_12 )
return;
if ( V_42 ) {
V_2 -> V_12 = V_42 ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_2 ) ;
} else {
int V_45 ;
V_2 -> V_12 = F_10 (unsigned int, adapter->num_vfs, IXGBE_MAX_VFS_DRV_LIMIT) ;
V_45 = F_11 ( V_2 -> V_43 , V_2 -> V_12 ) ;
if ( V_45 ) {
F_12 ( V_11 , L_3 , V_45 ) ;
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
T_1 V_46 ;
T_1 V_47 ;
int V_48 ;
V_2 -> V_12 = 0 ;
F_14 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
F_14 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
#ifdef F_15
if ( F_16 ( V_2 -> V_43 ) ) {
F_17 ( L_6 ) ;
return - V_49 ;
}
F_18 ( V_2 -> V_43 ) ;
#endif
F_6 ( V_4 , V_50 , 0 ) ;
V_46 = F_19 ( V_4 , V_51 ) ;
V_46 &= ~ V_52 ;
F_6 ( V_4 , V_51 , V_46 ) ;
V_47 = F_19 ( V_4 , V_53 ) ;
V_47 &= ~ V_54 ;
F_6 ( V_4 , V_53 , V_47 ) ;
F_20 ( V_4 ) ;
if ( V_2 -> V_14 [ V_15 ] . V_16 == 1 ) {
V_2 -> V_9 &= ~ V_13 ;
V_2 -> V_9 &= ~ V_10 ;
V_48 = F_10 ( int , V_55 , F_21 () ) ;
} else {
V_48 = F_10 ( int , V_56 , F_21 () ) ;
}
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_2 -> V_14 [ V_37 ] . V_16 = V_48 ;
F_22 ( 100 ) ;
return 0 ;
}
static int F_23 ( struct V_57 * V_44 , int V_12 )
{
#ifdef F_15
struct V_1 * V_2 = F_24 ( V_44 ) ;
int V_45 = 0 ;
int V_6 ;
int V_42 = F_8 ( V_44 ) ;
if ( V_42 && V_42 != V_12 )
V_45 = F_13 ( V_2 ) ;
else if ( V_42 && V_42 == V_12 )
return V_12 ;
if ( V_45 )
return V_45 ;
if ( ( V_12 + V_2 -> V_58 ) > V_59 )
return - V_49 ;
V_2 -> V_12 = V_12 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 )
return V_45 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_25 ( V_44 , ( V_6 | 0x10000000 ) ) ;
V_45 = F_11 ( V_44 , V_12 ) ;
if ( V_45 ) {
F_17 ( L_3 , V_45 ) ;
return V_45 ;
}
F_26 ( V_2 ) ;
return V_12 ;
#else
return 0 ;
#endif
}
static int F_27 ( struct V_57 * V_44 )
{
struct V_1 * V_2 = F_24 ( V_44 ) ;
int V_45 ;
#ifdef F_15
T_1 V_60 = V_2 -> V_9 ;
#endif
V_45 = F_13 ( V_2 ) ;
#ifdef F_15
if ( ! V_45 && V_60 != V_2 -> V_9 )
F_26 ( V_2 ) ;
#endif
return V_45 ;
}
int F_28 ( struct V_57 * V_44 , int V_12 )
{
if ( V_12 == 0 )
return F_27 ( V_44 ) ;
else
return F_23 ( V_44 , V_12 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_24 )
{
int V_62 = ( V_61 [ 0 ] & V_63 )
>> V_64 ;
T_2 * V_65 = ( T_2 * ) & V_61 [ 1 ] ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 = F_19 ( V_4 , F_30 ( V_24 ) ) ;
V_62 = F_31 ( V_62 , V_70 ) ;
V_29 -> V_71 = V_62 ;
for ( V_6 = 0 ; V_6 < V_62 ; V_6 ++ ) {
V_29 -> V_72 [ V_6 ] = V_65 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_29 -> V_71 ; V_6 ++ ) {
V_67 = ( V_29 -> V_72 [ V_6 ] >> 5 ) & 0x7F ;
V_66 = V_29 -> V_72 [ V_6 ] & 0x1F ;
V_68 = F_19 ( V_4 , F_32 ( V_67 ) ) ;
V_68 |= ( 1 << V_66 ) ;
F_6 ( V_4 , F_32 ( V_67 ) , V_68 ) ;
}
V_69 |= V_73 ;
F_6 ( V_4 , F_30 ( V_24 ) , V_69 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 ;
int V_6 , V_74 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
T_1 V_69 = F_19 ( V_4 , F_30 ( V_6 ) ) ;
V_29 = & V_2 -> V_29 [ V_6 ] ;
for ( V_74 = 0 ; V_74 < V_29 -> V_71 ; V_74 ++ ) {
V_4 -> V_75 . V_76 ++ ;
V_67 = ( V_29 -> V_72 [ V_74 ] >> 5 ) & 0x7F ;
V_66 = V_29 -> V_72 [ V_74 ] & 0x1F ;
V_68 = F_19 ( V_4 , F_32 ( V_67 ) ) ;
V_68 |= ( 1 << V_66 ) ;
F_6 ( V_4 , F_32 ( V_67 ) , V_68 ) ;
}
if ( V_29 -> V_71 )
V_69 |= V_73 ;
else
V_69 &= ~ V_73 ;
F_6 ( V_4 , F_30 ( V_6 ) , V_69 ) ;
}
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , int V_77 , int V_78 ,
T_1 V_24 )
{
if ( ! V_78 && ! V_77 )
return 0 ;
return V_2 -> V_4 . V_18 . V_79 . V_80 ( & V_2 -> V_4 , V_78 , V_24 , ( bool ) V_77 ) ;
}
static T_3 F_36 ( struct V_1 * V_2 , T_1 * V_61 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_81 = V_61 [ 1 ] ;
T_1 V_82 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_83 * V_44 = V_2 -> V_84 ;
int V_85 = V_44 -> V_86 + V_87 ;
T_1 V_88 , V_89 , V_90 ;
T_3 V_45 = 0 ;
#ifdef F_37
if ( V_44 -> V_91 & V_92 )
V_85 = F_38 ( int , V_85 ,
V_93 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_94 ) {
case V_95 :
if ( V_85 > V_96 )
break;
default:
if ( ( V_85 > V_96 ) ||
( V_81 > ( V_96 + V_97 ) ) )
V_45 = - V_98 ;
break;
}
V_89 = V_24 % 32 ;
V_88 = V_24 / 32 ;
V_90 = F_19 ( V_4 , F_39 ( V_88 ) ) ;
if ( V_45 )
V_90 &= ~ ( 1 << V_89 ) ;
else
V_90 |= 1 << V_89 ;
F_6 ( V_4 , F_39 ( V_88 ) , V_90 ) ;
if ( V_45 ) {
F_12 ( V_99 , L_7 , V_81 ) ;
return V_45 ;
}
}
if ( V_81 > V_100 ) {
F_12 ( V_99 , L_7 , V_81 ) ;
return - V_98 ;
}
V_82 = F_19 ( V_4 , V_101 ) ;
V_82 &= V_102 ;
V_82 >>= V_103 ;
if ( V_82 < V_81 ) {
V_82 = V_81 << V_103 ;
F_6 ( V_4 , V_101 , V_82 ) ;
}
F_2 ( V_4 , L_8 , V_81 ) ;
return 0 ;
}
static void F_40 ( struct V_3 * V_4 , T_1 V_24 , bool V_104 )
{
T_1 V_69 = F_19 ( V_4 , F_30 ( V_24 ) ) ;
V_69 |= V_105 ;
if ( V_104 )
V_69 |= V_106 ;
else
V_69 &= ~ V_106 ;
F_6 ( V_4 , F_30 ( V_24 ) , V_69 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_42 ( V_24 ) , 0 ) ;
}
static inline void F_43 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
T_4 V_33 = F_44 ( V_2 -> V_84 ) ;
F_35 ( V_2 , true , V_29 -> V_107 , V_24 ) ;
F_40 ( V_4 , V_24 , ! V_29 -> V_107 ) ;
if ( ! V_29 -> V_107 && ! V_29 -> V_108 && ! V_33 ) {
F_41 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_108 || ! V_33 )
F_45 ( V_2 , V_29 -> V_107 ,
V_29 -> V_108 , V_24 ) ;
else
F_45 ( V_2 , V_29 -> V_107 ,
V_2 -> V_109 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_79 . V_110 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_71 = 0 ;
F_46 ( V_2 -> V_84 ) ;
F_47 ( V_2 , V_2 -> V_29 [ V_24 ] . V_111 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_94 = V_112 ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_113 )
{
F_47 ( V_2 , V_2 -> V_29 [ V_24 ] . V_111 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_111 , V_113 , V_114 ) ;
F_49 ( V_2 , V_2 -> V_29 [ V_24 ] . V_111 , V_24 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_24 , int V_115 , unsigned char * V_113 )
{
struct V_116 * V_117 ;
struct V_7 * V_118 ;
if ( V_115 <= 1 ) {
F_51 (pos, &adapter->vf_mvs.l) {
V_118 = F_52 ( V_117 , struct V_7 , V_23 ) ;
if ( V_118 -> V_24 == V_24 ) {
V_118 -> V_24 = - 1 ;
V_118 -> free = true ;
V_118 -> V_119 = false ;
F_47 ( V_2 ,
V_118 -> V_120 , V_24 ) ;
}
}
}
if ( ! V_115 )
return 0 ;
V_118 = NULL ;
F_51 (pos, &adapter->vf_mvs.l) {
V_118 = F_52 ( V_117 , struct V_7 , V_23 ) ;
if ( V_118 -> free )
break;
}
if ( ! V_118 || ! V_118 -> free )
return - V_121 ;
V_118 -> free = false ;
V_118 -> V_119 = true ;
V_118 -> V_24 = V_24 ;
memcpy ( V_118 -> V_120 , V_113 , V_114 ) ;
F_49 ( V_2 , V_113 , V_24 ) ;
return 0 ;
}
int F_25 ( struct V_57 * V_43 , unsigned int V_122 )
{
struct V_1 * V_2 = F_24 ( V_43 ) ;
unsigned int V_123 = ( V_122 & 0x3f ) ;
bool V_124 = ( ( V_122 & 0x10000000U ) != 0 ) ;
if ( V_124 )
F_53 ( V_2 -> V_29 [ V_123 ] . V_111 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_127 = V_2 -> V_29 [ V_24 ] . V_111 ;
T_1 V_128 , V_88 , V_89 ;
T_1 V_61 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_129 = ( T_4 * ) ( & V_61 [ 1 ] ) ;
T_1 V_130 = F_55 ( 1 , ~ V_126 -> V_131 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_43 ( V_2 , V_24 ) ;
if ( ! F_56 ( V_127 ) )
F_48 ( V_2 , V_24 , V_127 ) ;
V_89 = V_24 % 32 ;
V_88 = V_24 / 32 ;
V_128 = F_19 ( V_4 , F_57 ( V_88 ) ) ;
V_128 |= 1 << V_89 ;
F_6 ( V_4 , F_57 ( V_88 ) , V_128 ) ;
for ( V_6 = V_24 * V_130 ; V_6 < ( ( V_24 + 1 ) * V_130 ) ; V_6 ++ ) {
F_20 ( V_4 ) ;
V_128 = V_132 | V_133 ;
V_128 |= V_6 << V_134 ;
F_6 ( V_4 , V_135 , V_128 ) ;
}
V_128 = F_19 ( V_4 , F_39 ( V_88 ) ) ;
V_128 |= 1 << V_89 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_83 * V_44 = V_2 -> V_84 ;
int V_85 = V_44 -> V_86 + V_87 ;
#ifdef F_37
if ( V_44 -> V_91 & V_92 )
V_85 = F_38 ( int , V_85 ,
V_93 ) ;
#endif
if ( V_85 > V_96 )
V_128 &= ~ ( 1 << V_89 ) ;
}
F_6 ( V_4 , F_39 ( V_88 ) , V_128 ) ;
V_2 -> V_29 [ V_24 ] . V_136 = true ;
V_128 = F_19 ( V_4 , F_58 ( V_88 ) ) ;
V_128 |= ( 1 << V_89 ) ;
F_6 ( V_4 , F_58 ( V_88 ) , V_128 ) ;
for ( V_6 = 0 ; V_6 < V_130 ; V_6 ++ ) {
F_6 ( V_4 , F_59 ( V_130 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_60 ( V_130 , V_24 , V_6 ) , 0 ) ;
}
V_61 [ 0 ] = V_137 ;
if ( ! F_56 ( V_127 ) ) {
V_61 [ 0 ] |= V_138 ;
memcpy ( V_129 , V_127 , V_114 ) ;
} else {
V_61 [ 0 ] |= V_139 ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_10 ,
V_24 ) ;
}
V_61 [ 3 ] = V_4 -> V_18 . V_140 ;
F_61 ( V_4 , V_61 , V_141 , V_24 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_24 )
{
T_4 * V_142 = ( ( T_4 * ) ( & V_61 [ 1 ] ) ) ;
if ( ! F_63 ( V_142 ) ) {
F_64 ( V_99 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_143 &&
! F_65 ( V_2 -> V_29 [ V_24 ] . V_111 , V_142 ) ) {
F_64 ( V_99 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_48 ( V_2 , V_24 , V_142 ) < 0 ;
}
static int F_66 ( struct V_3 * V_4 , T_1 V_144 )
{
T_1 V_145 ;
T_3 V_146 ;
if ( V_144 == 0 )
return 0 ;
for ( V_146 = 1 ; V_146 < V_147 ; V_146 ++ ) {
V_145 = F_19 ( V_4 , F_67 ( V_146 ) ) ;
if ( ( V_145 & V_148 ) == V_144 )
break;
}
if ( V_146 >= V_147 )
V_146 = - 1 ;
return V_146 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_77 = ( V_61 [ 0 ] & V_63 ) >> V_64 ;
int V_78 = ( V_61 [ 1 ] & V_149 ) ;
int V_45 ;
T_3 V_150 ;
T_1 V_145 ;
T_1 V_151 ;
T_4 V_152 = F_44 ( V_2 -> V_84 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_107 || V_152 ) {
F_64 ( V_99 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( V_77 )
V_2 -> V_29 [ V_24 ] . V_153 ++ ;
else if ( V_2 -> V_29 [ V_24 ] . V_153 )
V_2 -> V_29 [ V_24 ] . V_153 -- ;
if ( V_77 && V_2 -> V_84 -> V_9 & V_154 )
V_45 = F_35 ( V_2 , V_77 , V_78 , F_69 ( 0 ) ) ;
V_45 = F_35 ( V_2 , V_77 , V_78 , V_24 ) ;
if ( ! V_45 && V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_79 . V_110 ( V_4 , true , V_24 ) ;
if ( ! V_77 && V_2 -> V_84 -> V_9 & V_154 ) {
V_150 = F_66 ( V_4 , V_78 ) ;
if ( V_150 < 0 )
return V_45 ;
V_145 = F_19 ( V_4 , F_67 ( V_150 ) ) ;
if ( F_69 ( 0 ) < 32 ) {
V_151 = F_19 ( V_4 , F_70 ( V_150 * 2 ) ) ;
V_151 &= ~ ( 1 << F_69 ( 0 ) ) ;
V_151 |= F_19 ( V_4 ,
F_70 ( V_150 * 2 ) + 1 ) ;
} else {
V_151 = F_19 ( V_4 ,
F_70 ( V_150 * 2 ) + 1 ) ;
V_151 &= ~ ( 1 << ( F_69 ( 0 ) - 32 ) ) ;
V_151 |= F_19 ( V_4 , F_70 ( V_150 * 2 ) ) ;
}
if ( ( V_145 & V_148 ) == V_78 &&
! F_71 ( V_78 , V_2 -> V_155 ) && ! V_151 )
F_35 ( V_2 , V_77 , V_78 , F_69 ( 0 ) ) ;
}
return V_45 ;
}
static int F_72 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_24 )
{
T_4 * V_142 = ( ( T_4 * ) ( & V_61 [ 1 ] ) ) ;
int V_115 = ( V_61 [ 0 ] & V_63 ) >>
V_64 ;
int V_45 ;
if ( V_2 -> V_29 [ V_24 ] . V_143 && V_115 > 0 ) {
F_64 ( V_99 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_115 ) {
if ( ! F_63 ( V_142 ) ) {
F_64 ( V_99 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 )
F_73 ( V_2 -> V_84 , V_24 , false ) ;
}
V_45 = F_50 ( V_2 , V_24 , V_115 , V_142 ) ;
if ( V_45 == - V_121 )
F_64 ( V_99 ,
L_16 ,
V_24 ) ;
return V_45 < 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_24 )
{
int V_156 = V_61 [ 1 ] ;
switch ( V_156 ) {
case V_112 :
case V_95 :
V_2 -> V_29 [ V_24 ] . V_94 = V_156 ;
return 0 ;
default:
break;
}
F_2 ( V_99 , L_17 , V_24 , V_156 ) ;
return - 1 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_24 )
{
struct V_83 * V_44 = V_2 -> V_84 ;
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_157 = 0 ;
T_4 V_33 = F_44 ( V_44 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_94 ) {
case V_158 :
case V_95 :
break;
default:
return - 1 ;
}
V_61 [ V_159 ] = F_55 ( 1 , ~ V_126 -> V_131 ) ;
V_61 [ V_160 ] = F_55 ( 1 , ~ V_126 -> V_131 ) ;
if ( V_33 > 1 )
V_157 = F_76 ( V_44 , V_2 -> V_109 ) ;
if ( V_33 )
V_61 [ V_161 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_107 || V_2 -> V_29 [ V_24 ] . V_108 )
V_61 [ V_161 ] = 1 ;
else
V_61 [ V_161 ] = 0 ;
V_61 [ V_162 ] = V_157 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_163 = V_164 ;
T_1 V_61 [ V_164 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_165 ;
V_165 = F_78 ( V_4 , V_61 , V_163 , V_24 ) ;
if ( V_165 ) {
F_79 ( L_18 ) ;
return V_165 ;
}
if ( V_61 [ 0 ] & ( V_138 | V_139 ) )
return 0 ;
F_20 ( V_4 ) ;
if ( V_61 [ 0 ] == V_137 )
return F_54 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_136 ) {
V_61 [ 0 ] |= V_139 ;
F_61 ( V_4 , V_61 , 1 , V_24 ) ;
return 0 ;
}
switch ( ( V_61 [ 0 ] & 0xFFFF ) ) {
case V_166 :
V_165 = F_62 ( V_2 , V_61 , V_24 ) ;
break;
case V_167 :
V_165 = F_29 ( V_2 , V_61 , V_24 ) ;
break;
case V_168 :
V_165 = F_68 ( V_2 , V_61 , V_24 ) ;
break;
case V_169 :
V_165 = F_36 ( V_2 , V_61 , V_24 ) ;
break;
case V_170 :
V_165 = F_72 ( V_2 , V_61 , V_24 ) ;
break;
case V_171 :
V_165 = F_74 ( V_2 , V_61 , V_24 ) ;
break;
case V_172 :
V_165 = F_75 ( V_2 , V_61 , V_24 ) ;
break;
default:
F_12 ( V_99 , L_19 , V_61 [ 0 ] ) ;
V_165 = V_173 ;
break;
}
if ( V_165 )
V_61 [ 0 ] |= V_139 ;
else
V_61 [ 0 ] |= V_138 ;
V_61 [ 0 ] |= V_174 ;
F_61 ( V_4 , V_61 , V_163 , V_24 ) ;
return V_165 ;
}
static void F_80 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_175 = V_139 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_136 )
F_61 ( V_4 , & V_175 , 1 , V_24 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_82 ( V_4 , V_24 ) )
F_43 ( V_2 , V_24 ) ;
if ( ! F_83 ( V_4 , V_24 ) )
F_77 ( V_2 , V_24 ) ;
if ( ! F_84 ( V_4 , V_24 ) )
F_80 ( V_2 , V_24 ) ;
}
}
void F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_57 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_57 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_39 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_39 ( 1 ) , 0 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_176 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_176 = V_177 ;
if ( V_2 -> V_29 [ V_6 ] . V_136 )
V_176 |= V_174 ;
F_61 ( V_4 , & V_176 , 1 , V_6 ) ;
}
}
int F_87 ( struct V_83 * V_84 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_88 ( V_84 ) ;
if ( ! F_63 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_98 ;
V_2 -> V_29 [ V_24 ] . V_143 = true ;
F_89 ( & V_2 -> V_43 -> V_44 , L_20 , V_18 , V_24 ) ;
F_89 ( & V_2 -> V_43 -> V_44 , L_21
L_22 ) ;
if ( F_71 ( V_178 , & V_2 -> V_179 ) ) {
F_9 ( & V_2 -> V_43 -> V_44 , L_23
L_24 ) ;
F_9 ( & V_2 -> V_43 -> V_44 , L_25
L_26 ) ;
}
return F_48 ( V_2 , V_24 , V_18 ) ;
}
int F_90 ( struct V_83 * V_84 , int V_24 , T_2 V_144 , T_4 V_180 )
{
int V_45 = 0 ;
struct V_1 * V_2 = F_88 ( V_84 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_144 > 4095 ) || ( V_180 > 7 ) )
return - V_98 ;
if ( V_144 || V_180 ) {
if ( V_2 -> V_29 [ V_24 ] . V_107 )
V_45 = F_35 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_107 ,
V_24 ) ;
if ( V_45 )
goto V_181;
V_45 = F_35 ( V_2 , true , V_144 , V_24 ) ;
if ( V_45 )
goto V_181;
F_45 ( V_2 , V_144 , V_180 , V_24 ) ;
F_40 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_79 . V_110 ( V_4 , true , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_153 ++ ;
V_2 -> V_29 [ V_24 ] . V_107 = V_144 ;
V_2 -> V_29 [ V_24 ] . V_108 = V_180 ;
F_89 ( & V_2 -> V_43 -> V_44 ,
L_27 , V_144 , V_180 , V_24 ) ;
if ( F_71 ( V_178 , & V_2 -> V_179 ) ) {
F_9 ( & V_2 -> V_43 -> V_44 ,
L_28
L_24 ) ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_25
L_26 ) ;
}
} else {
V_45 = F_35 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_107 , V_24 ) ;
F_41 ( V_2 , V_24 ) ;
F_40 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_79 . V_110 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_153 )
V_2 -> V_29 [ V_24 ] . V_153 -- ;
V_2 -> V_29 [ V_24 ] . V_107 = 0 ;
V_2 -> V_29 [ V_24 ] . V_108 = 0 ;
}
V_181:
return V_45 ;
}
static int F_91 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_182 ) {
case V_183 :
return 100 ;
case V_184 :
return 1000 ;
case V_185 :
return 10000 ;
default:
return 0 ;
}
}
static void F_92 ( struct V_1 * V_2 , int V_24 )
{
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_186 = 0 ;
T_2 V_187 , V_188 ;
T_2 V_189 = V_2 -> V_29 [ V_24 ] . V_189 ;
if ( V_189 ) {
V_186 = V_2 -> V_190 ;
V_186 <<= V_191 ;
V_186 /= V_189 ;
V_186 &= V_192 |
V_193 ;
V_186 |= V_194 ;
}
switch ( V_4 -> V_18 . type ) {
case V_31 :
F_6 ( V_4 , V_195 , 0x4 ) ;
break;
case V_196 :
F_6 ( V_4 , V_195 , 0x14 ) ;
break;
default:
break;
}
V_188 = F_55 ( 1 , ~ V_126 -> V_131 ) ;
for ( V_187 = 0 ; V_187 < V_188 ; V_187 ++ ) {
unsigned int V_197 = ( V_24 * V_188 ) + V_187 ;
F_6 ( V_4 , V_198 , V_197 ) ;
F_6 ( V_4 , V_199 , V_186 ) ;
}
}
void F_93 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_190 )
return;
if ( F_91 ( V_2 ) != V_2 -> V_190 ) {
V_2 -> V_190 = 0 ;
F_89 ( & V_2 -> V_43 -> V_44 ,
L_29 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_190 )
V_2 -> V_29 [ V_6 ] . V_189 = 0 ;
F_92 ( V_2 , V_6 ) ;
}
}
int F_94 ( struct V_83 * V_84 , int V_24 , int V_200 ,
int V_201 )
{
struct V_1 * V_2 = F_88 ( V_84 ) ;
int V_182 ;
if ( V_24 >= V_2 -> V_12 )
return - V_98 ;
if ( ! V_2 -> V_202 )
return - V_98 ;
V_182 = F_91 ( V_2 ) ;
if ( V_182 != 10000 )
return - V_98 ;
if ( V_200 )
return - V_98 ;
if ( V_201 && ( ( V_201 <= 10 ) || ( V_201 > V_182 ) ) )
return - V_98 ;
V_2 -> V_190 = V_182 ;
V_2 -> V_29 [ V_24 ] . V_189 = V_201 ;
F_92 ( V_2 , V_24 ) ;
return 0 ;
}
int F_73 ( struct V_83 * V_84 , int V_24 , bool V_203 )
{
struct V_1 * V_2 = F_88 ( V_84 ) ;
int V_204 = V_24 >> 3 ;
int V_205 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_206 ;
if ( V_24 >= V_2 -> V_12 )
return - V_98 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_203 ;
V_206 = F_19 ( V_4 , F_95 ( V_204 ) ) ;
V_206 &= ~ ( 1 << V_205 ) ;
V_206 |= ( V_203 << V_205 ) ;
F_6 ( V_4 , F_95 ( V_204 ) , V_206 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_153 ) {
V_205 += V_207 ;
V_206 = F_19 ( V_4 , F_95 ( V_204 ) ) ;
V_206 &= ~ ( 1 << V_205 ) ;
V_206 |= ( V_203 << V_205 ) ;
F_6 ( V_4 , F_95 ( V_204 ) , V_206 ) ;
}
return 0 ;
}
int F_96 ( struct V_83 * V_84 ,
int V_24 , struct V_208 * V_209 )
{
struct V_1 * V_2 = F_88 ( V_84 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_98 ;
V_209 -> V_24 = V_24 ;
memcpy ( & V_209 -> V_18 , V_2 -> V_29 [ V_24 ] . V_111 , V_114 ) ;
V_209 -> V_201 = V_2 -> V_29 [ V_24 ] . V_189 ;
V_209 -> V_200 = 0 ;
V_209 -> V_144 = V_2 -> V_29 [ V_24 ] . V_107 ;
V_209 -> V_180 = V_2 -> V_29 [ V_24 ] . V_108 ;
V_209 -> V_210 = V_2 -> V_29 [ V_24 ] . V_40 ;
return 0 ;
}
