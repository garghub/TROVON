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
V_48 = F_10 ( int , F_21 ( V_2 ) ,
F_22 () ) ;
} else {
V_48 = F_10 ( int , V_55 , F_22 () ) ;
}
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_2 -> V_14 [ V_37 ] . V_16 = V_48 ;
F_23 ( 100 ) ;
return 0 ;
}
static int F_24 ( struct V_56 * V_44 , int V_12 )
{
#ifdef F_15
struct V_1 * V_2 = F_25 ( V_44 ) ;
int V_45 = 0 ;
int V_6 ;
int V_42 = F_8 ( V_44 ) ;
if ( V_42 && V_42 != V_12 )
V_45 = F_13 ( V_2 ) ;
else if ( V_42 && V_42 == V_12 )
return V_12 ;
if ( V_45 )
return V_45 ;
if ( ( V_12 + V_2 -> V_57 ) > V_58 )
return - V_49 ;
V_2 -> V_12 = V_12 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 )
return V_45 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_26 ( V_44 , ( V_6 | 0x10000000 ) ) ;
V_45 = F_11 ( V_44 , V_12 ) ;
if ( V_45 ) {
F_17 ( L_3 , V_45 ) ;
return V_45 ;
}
F_27 ( V_2 ) ;
return V_12 ;
#else
return 0 ;
#endif
}
static int F_28 ( struct V_56 * V_44 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
int V_45 ;
#ifdef F_15
T_1 V_59 = V_2 -> V_9 ;
#endif
V_45 = F_13 ( V_2 ) ;
#ifdef F_15
if ( ! V_45 && V_59 != V_2 -> V_9 )
F_27 ( V_2 ) ;
#endif
return V_45 ;
}
int F_29 ( struct V_56 * V_44 , int V_12 )
{
if ( V_12 == 0 )
return F_28 ( V_44 ) ;
else
return F_24 ( V_44 , V_12 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 V_24 )
{
int V_61 = ( V_60 [ 0 ] & V_62 )
>> V_63 ;
T_2 * V_64 = ( T_2 * ) & V_60 [ 1 ] ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_61 = F_32 ( V_61 , V_69 ) ;
V_29 -> V_70 = V_61 ;
for ( V_6 = 0 ; V_6 < V_61 ; V_6 ++ ) {
V_29 -> V_71 [ V_6 ] = V_64 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_29 -> V_70 ; V_6 ++ ) {
V_66 = ( V_29 -> V_71 [ V_6 ] >> 5 ) & 0x7F ;
V_65 = V_29 -> V_71 [ V_6 ] & 0x1F ;
V_67 = F_19 ( V_4 , F_33 ( V_66 ) ) ;
V_67 |= ( 1 << V_65 ) ;
F_6 ( V_4 , F_33 ( V_66 ) , V_67 ) ;
}
V_68 |= V_72 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_68 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 ;
int V_6 , V_73 ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_67 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
T_1 V_68 = F_19 ( V_4 , F_31 ( V_6 ) ) ;
V_29 = & V_2 -> V_29 [ V_6 ] ;
for ( V_73 = 0 ; V_73 < V_29 -> V_70 ; V_73 ++ ) {
V_4 -> V_74 . V_75 ++ ;
V_66 = ( V_29 -> V_71 [ V_73 ] >> 5 ) & 0x7F ;
V_65 = V_29 -> V_71 [ V_73 ] & 0x1F ;
V_67 = F_19 ( V_4 , F_33 ( V_66 ) ) ;
V_67 |= ( 1 << V_65 ) ;
F_6 ( V_4 , F_33 ( V_66 ) , V_67 ) ;
}
if ( V_29 -> V_70 )
V_68 |= V_72 ;
else
V_68 &= ~ V_72 ;
F_6 ( V_4 , F_31 ( V_6 ) , V_68 ) ;
}
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_76 , int V_77 ,
T_1 V_24 )
{
if ( ! V_77 && ! V_76 )
return 0 ;
return V_2 -> V_4 . V_18 . V_78 . V_79 ( & V_2 -> V_4 , V_77 , V_24 , ( bool ) V_76 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 , T_1 * V_60 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_80 = V_60 [ 1 ] ;
T_1 V_81 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_82 * V_44 = V_2 -> V_83 ;
int V_84 = V_44 -> V_85 + V_86 ;
T_1 V_87 , V_88 , V_89 ;
T_3 V_45 = 0 ;
#ifdef F_38
if ( V_44 -> V_90 & V_91 )
V_84 = F_39 ( int , V_84 ,
V_92 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_93 ) {
case V_94 :
if ( V_84 > V_95 )
break;
default:
if ( ( V_84 > V_95 ) ||
( V_80 > ( V_95 + V_96 ) ) )
V_45 = - V_97 ;
break;
}
V_88 = V_24 % 32 ;
V_87 = V_24 / 32 ;
V_89 = F_19 ( V_4 , F_40 ( V_87 ) ) ;
if ( V_45 )
V_89 &= ~ ( 1 << V_88 ) ;
else
V_89 |= 1 << V_88 ;
F_6 ( V_4 , F_40 ( V_87 ) , V_89 ) ;
if ( V_45 ) {
F_12 ( V_98 , L_7 , V_80 ) ;
return V_45 ;
}
}
if ( V_80 > V_99 ) {
F_12 ( V_98 , L_7 , V_80 ) ;
return - V_97 ;
}
V_81 = F_19 ( V_4 , V_100 ) ;
V_81 &= V_101 ;
V_81 >>= V_102 ;
if ( V_81 < V_80 ) {
V_81 = V_80 << V_102 ;
F_6 ( V_4 , V_100 , V_81 ) ;
}
F_2 ( V_4 , L_8 , V_80 ) ;
return 0 ;
}
static void F_41 ( struct V_3 * V_4 , T_1 V_24 , bool V_103 )
{
T_1 V_68 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_68 |= V_104 ;
if ( V_103 )
V_68 |= V_105 ;
else
V_68 &= ~ V_105 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_68 ) ;
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
T_4 V_33 = F_45 ( V_2 -> V_83 ) ;
F_36 ( V_2 , true , V_29 -> V_106 , V_24 ) ;
F_41 ( V_4 , V_24 , ! V_29 -> V_106 ) ;
if ( ! V_29 -> V_106 && ! V_29 -> V_107 && ! V_33 ) {
F_42 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_107 || ! V_33 )
F_46 ( V_2 , V_29 -> V_106 ,
V_29 -> V_107 , V_24 ) ;
else
F_46 ( V_2 , V_29 -> V_106 ,
V_2 -> V_108 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_78 . V_109 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_70 = 0 ;
F_47 ( V_2 -> V_83 ) ;
F_48 ( V_2 , V_2 -> V_29 [ V_24 ] . V_110 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_93 = V_111 ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_112 )
{
F_48 ( V_2 , V_2 -> V_29 [ V_24 ] . V_110 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_110 , V_112 , V_113 ) ;
F_50 ( V_2 , V_2 -> V_29 [ V_24 ] . V_110 , V_24 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_24 , int V_114 , unsigned char * V_112 )
{
struct V_115 * V_116 ;
struct V_7 * V_117 ;
if ( V_114 <= 1 ) {
F_52 (pos, &adapter->vf_mvs.l) {
V_117 = F_53 ( V_116 , struct V_7 , V_23 ) ;
if ( V_117 -> V_24 == V_24 ) {
V_117 -> V_24 = - 1 ;
V_117 -> free = true ;
V_117 -> V_118 = false ;
F_48 ( V_2 ,
V_117 -> V_119 , V_24 ) ;
}
}
}
if ( ! V_114 )
return 0 ;
V_117 = NULL ;
F_52 (pos, &adapter->vf_mvs.l) {
V_117 = F_53 ( V_116 , struct V_7 , V_23 ) ;
if ( V_117 -> free )
break;
}
if ( ! V_117 || ! V_117 -> free )
return - V_120 ;
V_117 -> free = false ;
V_117 -> V_118 = true ;
V_117 -> V_24 = V_24 ;
memcpy ( V_117 -> V_119 , V_112 , V_113 ) ;
F_50 ( V_2 , V_112 , V_24 ) ;
return 0 ;
}
int F_26 ( struct V_56 * V_43 , unsigned int V_121 )
{
struct V_1 * V_2 = F_25 ( V_43 ) ;
unsigned int V_122 = ( V_121 & 0x3f ) ;
bool V_123 = ( ( V_121 & 0x10000000U ) != 0 ) ;
if ( V_123 )
F_54 ( V_2 -> V_29 [ V_122 ] . V_110 ) ;
return 0 ;
}
static inline void F_55 ( struct V_1 * V_2 , T_1 V_24 ,
T_1 V_124 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
T_1 V_127 = F_56 ( 1 , ~ V_126 -> V_128 ) ;
int V_6 ;
for ( V_6 = V_24 * V_127 ; V_6 < ( ( V_24 + 1 ) * V_127 ) ; V_6 ++ ) {
T_1 V_129 ;
F_20 ( V_4 ) ;
V_129 = V_130 | V_131 ;
V_129 |= V_6 << V_132 ;
F_6 ( V_4 , V_133 , V_129 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_134 = V_2 -> V_29 [ V_24 ] . V_110 ;
T_1 V_129 , V_87 , V_88 ;
T_1 V_60 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_135 = ( T_4 * ) ( & V_60 [ 1 ] ) ;
T_1 V_127 = F_56 ( 1 , ~ V_126 -> V_128 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_44 ( V_2 , V_24 ) ;
if ( ! F_58 ( V_134 ) )
F_49 ( V_2 , V_24 , V_134 ) ;
V_88 = V_24 % 32 ;
V_87 = V_24 / 32 ;
V_129 = F_19 ( V_4 , F_59 ( V_87 ) ) ;
V_129 |= 1 << V_88 ;
F_6 ( V_4 , F_59 ( V_87 ) , V_129 ) ;
F_55 ( V_2 , V_24 , V_131 ) ;
V_129 = F_19 ( V_4 , F_40 ( V_87 ) ) ;
V_129 |= 1 << V_88 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_82 * V_44 = V_2 -> V_83 ;
int V_84 = V_44 -> V_85 + V_86 ;
#ifdef F_38
if ( V_44 -> V_90 & V_91 )
V_84 = F_39 ( int , V_84 ,
V_92 ) ;
#endif
if ( V_84 > V_95 )
V_129 &= ~ ( 1 << V_88 ) ;
}
F_6 ( V_4 , F_40 ( V_87 ) , V_129 ) ;
V_2 -> V_29 [ V_24 ] . V_136 = true ;
V_129 = F_19 ( V_4 , F_60 ( V_87 ) ) ;
V_129 |= ( 1 << V_88 ) ;
F_6 ( V_4 , F_60 ( V_87 ) , V_129 ) ;
for ( V_6 = 0 ; V_6 < V_127 ; V_6 ++ ) {
F_6 ( V_4 , F_61 ( V_127 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_62 ( V_127 , V_24 , V_6 ) , 0 ) ;
}
V_60 [ 0 ] = V_137 ;
if ( ! F_58 ( V_134 ) ) {
V_60 [ 0 ] |= V_138 ;
memcpy ( V_135 , V_134 , V_113 ) ;
} else {
V_60 [ 0 ] |= V_139 ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_10 ,
V_24 ) ;
}
V_60 [ 3 ] = V_4 -> V_18 . V_140 ;
F_63 ( V_4 , V_60 , V_141 , V_24 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 V_24 )
{
T_4 * V_142 = ( ( T_4 * ) ( & V_60 [ 1 ] ) ) ;
if ( ! F_65 ( V_142 ) ) {
F_66 ( V_98 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_143 &&
! F_67 ( V_2 -> V_29 [ V_24 ] . V_110 , V_142 ) ) {
F_66 ( V_98 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_49 ( V_2 , V_24 , V_142 ) < 0 ;
}
static int F_68 ( struct V_3 * V_4 , T_1 V_144 )
{
T_1 V_145 ;
T_3 V_146 ;
if ( V_144 == 0 )
return 0 ;
for ( V_146 = 1 ; V_146 < V_147 ; V_146 ++ ) {
V_145 = F_19 ( V_4 , F_69 ( V_146 ) ) ;
if ( ( V_145 & V_148 ) == V_144 )
break;
}
if ( V_146 >= V_147 )
V_146 = - 1 ;
return V_146 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_76 = ( V_60 [ 0 ] & V_62 ) >> V_63 ;
int V_77 = ( V_60 [ 1 ] & V_149 ) ;
int V_45 ;
T_3 V_150 ;
T_1 V_145 ;
T_1 V_151 ;
T_4 V_152 = F_45 ( V_2 -> V_83 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_106 || V_152 ) {
F_66 ( V_98 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( V_76 )
V_2 -> V_29 [ V_24 ] . V_153 ++ ;
else if ( V_2 -> V_29 [ V_24 ] . V_153 )
V_2 -> V_29 [ V_24 ] . V_153 -- ;
if ( V_76 && V_2 -> V_83 -> V_9 & V_154 )
V_45 = F_36 ( V_2 , V_76 , V_77 , F_71 ( 0 ) ) ;
V_45 = F_36 ( V_2 , V_76 , V_77 , V_24 ) ;
if ( ! V_45 && V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_78 . V_109 ( V_4 , true , V_24 ) ;
if ( ! V_76 && V_2 -> V_83 -> V_9 & V_154 ) {
V_150 = F_68 ( V_4 , V_77 ) ;
if ( V_150 < 0 )
return V_45 ;
V_145 = F_19 ( V_4 , F_69 ( V_150 ) ) ;
if ( F_71 ( 0 ) < 32 ) {
V_151 = F_19 ( V_4 , F_72 ( V_150 * 2 ) ) ;
V_151 &= ~ ( 1 << F_71 ( 0 ) ) ;
V_151 |= F_19 ( V_4 ,
F_72 ( V_150 * 2 ) + 1 ) ;
} else {
V_151 = F_19 ( V_4 ,
F_72 ( V_150 * 2 ) + 1 ) ;
V_151 &= ~ ( 1 << ( F_71 ( 0 ) - 32 ) ) ;
V_151 |= F_19 ( V_4 , F_72 ( V_150 * 2 ) ) ;
}
if ( ( V_145 & V_148 ) == V_77 &&
! F_73 ( V_77 , V_2 -> V_155 ) && ! V_151 )
F_36 ( V_2 , V_76 , V_77 , F_71 ( 0 ) ) ;
}
return V_45 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 V_24 )
{
T_4 * V_142 = ( ( T_4 * ) ( & V_60 [ 1 ] ) ) ;
int V_114 = ( V_60 [ 0 ] & V_62 ) >>
V_63 ;
int V_45 ;
if ( V_2 -> V_29 [ V_24 ] . V_143 && V_114 > 0 ) {
F_66 ( V_98 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_114 ) {
if ( ! F_65 ( V_142 ) ) {
F_66 ( V_98 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 )
F_75 ( V_2 -> V_83 , V_24 , false ) ;
}
V_45 = F_51 ( V_2 , V_24 , V_114 , V_142 ) ;
if ( V_45 == - V_120 )
F_66 ( V_98 ,
L_16 ,
V_24 ) ;
return V_45 < 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 V_24 )
{
int V_156 = V_60 [ 1 ] ;
switch ( V_156 ) {
case V_111 :
case V_94 :
V_2 -> V_29 [ V_24 ] . V_93 = V_156 ;
return 0 ;
default:
break;
}
F_2 ( V_98 , L_17 , V_24 , V_156 ) ;
return - 1 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_1 * V_60 , T_1 V_24 )
{
struct V_82 * V_44 = V_2 -> V_83 ;
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_157 = 0 ;
T_4 V_33 = F_45 ( V_44 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_93 ) {
case V_158 :
case V_94 :
break;
default:
return - 1 ;
}
V_60 [ V_159 ] = F_56 ( 1 , ~ V_126 -> V_128 ) ;
V_60 [ V_160 ] = F_56 ( 1 , ~ V_126 -> V_128 ) ;
if ( V_33 > 1 )
V_157 = F_78 ( V_44 , V_2 -> V_108 ) ;
if ( V_33 )
V_60 [ V_161 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_106 || V_2 -> V_29 [ V_24 ] . V_107 )
V_60 [ V_161 ] = 1 ;
else
V_60 [ V_161 ] = 0 ;
V_60 [ V_162 ] = V_157 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_163 = V_164 ;
T_1 V_60 [ V_164 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_165 ;
V_165 = F_80 ( V_4 , V_60 , V_163 , V_24 ) ;
if ( V_165 ) {
F_81 ( L_18 ) ;
return V_165 ;
}
if ( V_60 [ 0 ] & ( V_138 | V_139 ) )
return 0 ;
F_20 ( V_4 ) ;
if ( V_60 [ 0 ] == V_137 )
return F_57 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_136 ) {
V_60 [ 0 ] |= V_139 ;
F_63 ( V_4 , V_60 , 1 , V_24 ) ;
return 0 ;
}
switch ( ( V_60 [ 0 ] & 0xFFFF ) ) {
case V_166 :
V_165 = F_64 ( V_2 , V_60 , V_24 ) ;
break;
case V_167 :
V_165 = F_30 ( V_2 , V_60 , V_24 ) ;
break;
case V_168 :
V_165 = F_70 ( V_2 , V_60 , V_24 ) ;
break;
case V_169 :
V_165 = F_37 ( V_2 , V_60 , V_24 ) ;
break;
case V_170 :
V_165 = F_74 ( V_2 , V_60 , V_24 ) ;
break;
case V_171 :
V_165 = F_76 ( V_2 , V_60 , V_24 ) ;
break;
case V_172 :
V_165 = F_77 ( V_2 , V_60 , V_24 ) ;
break;
default:
F_12 ( V_98 , L_19 , V_60 [ 0 ] ) ;
V_165 = V_173 ;
break;
}
if ( V_165 )
V_60 [ 0 ] |= V_139 ;
else
V_60 [ 0 ] |= V_138 ;
V_60 [ 0 ] |= V_174 ;
F_63 ( V_4 , V_60 , V_163 , V_24 ) ;
return V_165 ;
}
static void F_82 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_175 = V_139 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_136 )
F_63 ( V_4 , & V_175 , 1 , V_24 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_84 ( V_4 , V_24 ) )
F_44 ( V_2 , V_24 ) ;
if ( ! F_85 ( V_4 , V_24 ) )
F_79 ( V_2 , V_24 ) ;
if ( ! F_86 ( V_4 , V_24 ) )
F_82 ( V_2 , V_24 ) ;
}
}
void F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_59 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_59 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 1 ) , 0 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_176 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_176 = V_177 ;
if ( V_2 -> V_29 [ V_6 ] . V_136 )
V_176 |= V_174 ;
F_63 ( V_4 , & V_176 , 1 , V_6 ) ;
}
}
int F_89 ( struct V_82 * V_83 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_90 ( V_83 ) ;
if ( ! F_65 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_97 ;
V_2 -> V_29 [ V_24 ] . V_143 = true ;
F_91 ( & V_2 -> V_43 -> V_44 , L_20 , V_18 , V_24 ) ;
F_91 ( & V_2 -> V_43 -> V_44 , L_21
L_22 ) ;
if ( F_73 ( V_178 , & V_2 -> V_179 ) ) {
F_9 ( & V_2 -> V_43 -> V_44 , L_23
L_24 ) ;
F_9 ( & V_2 -> V_43 -> V_44 , L_25
L_26 ) ;
}
return F_49 ( V_2 , V_24 , V_18 ) ;
}
static int F_92 ( struct V_1 * V_2 , int V_24 ,
T_2 V_144 , T_4 V_180 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_45 = 0 ;
if ( V_2 -> V_29 [ V_24 ] . V_106 )
V_45 = F_36 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_106 ,
V_24 ) ;
if ( V_45 )
goto V_181;
F_46 ( V_2 , V_144 , V_180 , V_24 ) ;
F_41 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_78 . V_109 ( V_4 , true , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_153 ++ ;
if ( V_4 -> V_18 . type >= V_182 )
F_55 ( V_2 , V_24 , V_131 |
V_183 ) ;
V_2 -> V_29 [ V_24 ] . V_106 = V_144 ;
V_2 -> V_29 [ V_24 ] . V_107 = V_180 ;
F_91 ( & V_2 -> V_43 -> V_44 ,
L_27 , V_144 , V_180 , V_24 ) ;
if ( F_73 ( V_178 , & V_2 -> V_179 ) ) {
F_9 ( & V_2 -> V_43 -> V_44 ,
L_28 ) ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_29 ) ;
}
V_181:
return V_45 ;
}
static int F_93 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_45 ;
V_45 = F_36 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_106 , V_24 ) ;
F_42 ( V_2 , V_24 ) ;
F_41 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_78 . V_109 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_153 )
V_2 -> V_29 [ V_24 ] . V_153 -- ;
V_2 -> V_29 [ V_24 ] . V_106 = 0 ;
V_2 -> V_29 [ V_24 ] . V_107 = 0 ;
return V_45 ;
}
int F_94 ( struct V_82 * V_83 , int V_24 , T_2 V_144 , T_4 V_180 )
{
int V_45 = 0 ;
struct V_1 * V_2 = F_90 ( V_83 ) ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_144 > 4095 ) || ( V_180 > 7 ) )
return - V_97 ;
if ( V_144 || V_180 ) {
if ( V_2 -> V_29 [ V_24 ] . V_106 )
V_45 = F_93 ( V_2 , V_24 ) ;
if ( V_45 )
goto V_181;
V_45 = F_92 ( V_2 , V_24 , V_144 , V_180 ) ;
} else {
V_45 = F_93 ( V_2 , V_24 ) ;
}
V_181:
return V_45 ;
}
static int F_95 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_184 ) {
case V_185 :
return 100 ;
case V_186 :
return 1000 ;
case V_187 :
return 10000 ;
default:
return 0 ;
}
}
static void F_96 ( struct V_1 * V_2 , int V_24 )
{
struct V_125 * V_126 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_188 = 0 ;
T_2 V_189 , V_190 ;
T_2 V_191 = V_2 -> V_29 [ V_24 ] . V_191 ;
if ( V_191 ) {
V_188 = V_2 -> V_192 ;
V_188 <<= V_193 ;
V_188 /= V_191 ;
V_188 &= V_194 |
V_195 ;
V_188 |= V_196 ;
}
switch ( V_4 -> V_18 . type ) {
case V_31 :
F_6 ( V_4 , V_197 , 0x4 ) ;
break;
case V_198 :
F_6 ( V_4 , V_197 , 0x14 ) ;
break;
default:
break;
}
V_190 = F_56 ( 1 , ~ V_126 -> V_128 ) ;
for ( V_189 = 0 ; V_189 < V_190 ; V_189 ++ ) {
unsigned int V_199 = ( V_24 * V_190 ) + V_189 ;
F_6 ( V_4 , V_200 , V_199 ) ;
F_6 ( V_4 , V_201 , V_188 ) ;
}
}
void F_97 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_192 )
return;
if ( F_95 ( V_2 ) != V_2 -> V_192 ) {
V_2 -> V_192 = 0 ;
F_91 ( & V_2 -> V_43 -> V_44 ,
L_30 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_192 )
V_2 -> V_29 [ V_6 ] . V_191 = 0 ;
F_96 ( V_2 , V_6 ) ;
}
}
int F_98 ( struct V_82 * V_83 , int V_24 , int V_202 ,
int V_203 )
{
struct V_1 * V_2 = F_90 ( V_83 ) ;
int V_184 ;
if ( V_24 >= V_2 -> V_12 )
return - V_97 ;
if ( ! V_2 -> V_204 )
return - V_97 ;
V_184 = F_95 ( V_2 ) ;
if ( V_184 != 10000 )
return - V_97 ;
if ( V_202 )
return - V_97 ;
if ( V_203 && ( ( V_203 <= 10 ) || ( V_203 > V_184 ) ) )
return - V_97 ;
V_2 -> V_192 = V_184 ;
V_2 -> V_29 [ V_24 ] . V_191 = V_203 ;
F_96 ( V_2 , V_24 ) ;
return 0 ;
}
int F_75 ( struct V_82 * V_83 , int V_24 , bool V_205 )
{
struct V_1 * V_2 = F_90 ( V_83 ) ;
int V_206 = V_24 >> 3 ;
int V_207 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_208 ;
if ( V_24 >= V_2 -> V_12 )
return - V_97 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_205 ;
V_208 = F_19 ( V_4 , F_99 ( V_206 ) ) ;
V_208 &= ~ ( 1 << V_207 ) ;
V_208 |= ( V_205 << V_207 ) ;
F_6 ( V_4 , F_99 ( V_206 ) , V_208 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_153 ) {
V_207 += V_209 ;
V_208 = F_19 ( V_4 , F_99 ( V_206 ) ) ;
V_208 &= ~ ( 1 << V_207 ) ;
V_208 |= ( V_205 << V_207 ) ;
F_6 ( V_4 , F_99 ( V_206 ) , V_208 ) ;
}
return 0 ;
}
int F_100 ( struct V_82 * V_83 ,
int V_24 , struct V_210 * V_211 )
{
struct V_1 * V_2 = F_90 ( V_83 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_97 ;
V_211 -> V_24 = V_24 ;
memcpy ( & V_211 -> V_18 , V_2 -> V_29 [ V_24 ] . V_110 , V_113 ) ;
V_211 -> V_203 = V_2 -> V_29 [ V_24 ] . V_191 ;
V_211 -> V_202 = 0 ;
V_211 -> V_144 = V_2 -> V_29 [ V_24 ] . V_106 ;
V_211 -> V_180 = V_2 -> V_29 [ V_24 ] . V_107 ;
V_211 -> V_212 = V_2 -> V_29 [ V_24 ] . V_40 ;
return 0 ;
}
