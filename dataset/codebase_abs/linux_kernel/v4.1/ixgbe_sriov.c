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
}
return 0 ;
}
return - V_42 ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_43 = 0 ;
V_43 = F_8 ( V_2 -> V_44 ) ;
if ( ! V_43 && ! V_2 -> V_12 )
return;
if ( V_43 ) {
V_2 -> V_12 = V_43 ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_2 ) ;
} else {
int V_46 ;
V_2 -> V_12 = F_10 (unsigned int, adapter->num_vfs, IXGBE_MAX_VFS_DRV_LIMIT) ;
V_46 = F_11 ( V_2 -> V_44 , V_2 -> V_12 ) ;
if ( V_46 ) {
F_12 ( V_11 , L_3 , V_46 ) ;
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
T_1 V_47 ;
T_1 V_48 ;
int V_49 ;
V_2 -> V_12 = 0 ;
F_14 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
F_14 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
#ifdef F_15
if ( F_16 ( V_2 -> V_44 ) ) {
F_17 ( L_6 ) ;
return - V_50 ;
}
F_18 ( V_2 -> V_44 ) ;
#endif
F_6 ( V_4 , V_51 , 0 ) ;
V_47 = F_19 ( V_4 , V_52 ) ;
V_47 &= ~ V_53 ;
F_6 ( V_4 , V_52 , V_47 ) ;
V_48 = F_19 ( V_4 , V_54 ) ;
V_48 &= ~ V_55 ;
F_6 ( V_4 , V_54 , V_48 ) ;
F_20 ( V_4 ) ;
if ( V_2 -> V_14 [ V_15 ] . V_16 == 1 ) {
V_2 -> V_9 &= ~ V_13 ;
V_2 -> V_9 &= ~ V_10 ;
V_49 = F_10 ( int , F_21 ( V_2 ) ,
F_22 () ) ;
} else {
V_49 = F_10 ( int , V_56 , F_22 () ) ;
}
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_2 -> V_14 [ V_57 ] . V_16 = V_49 ;
F_23 ( 100 ) ;
return 0 ;
}
static int F_24 ( struct V_58 * V_45 , int V_12 )
{
#ifdef F_15
struct V_1 * V_2 = F_25 ( V_45 ) ;
int V_46 = 0 ;
int V_6 ;
int V_43 = F_8 ( V_45 ) ;
if ( V_43 && V_43 != V_12 )
V_46 = F_13 ( V_2 ) ;
else if ( V_43 && V_43 == V_12 )
return V_12 ;
if ( V_46 )
return V_46 ;
if ( ( V_12 + V_2 -> V_59 ) > V_60 )
return - V_50 ;
V_2 -> V_12 = V_12 ;
V_46 = F_1 ( V_2 ) ;
if ( V_46 )
return V_46 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_26 ( V_45 , ( V_6 | 0x10000000 ) ) ;
V_46 = F_11 ( V_45 , V_12 ) ;
if ( V_46 ) {
F_17 ( L_3 , V_46 ) ;
return V_46 ;
}
F_27 ( V_2 ) ;
return V_12 ;
#else
return 0 ;
#endif
}
static int F_28 ( struct V_58 * V_45 )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
int V_46 ;
#ifdef F_15
T_1 V_61 = V_2 -> V_9 ;
#endif
V_46 = F_13 ( V_2 ) ;
#ifdef F_15
if ( ! V_46 && V_61 != V_2 -> V_9 )
F_27 ( V_2 ) ;
#endif
return V_46 ;
}
int F_29 ( struct V_58 * V_45 , int V_12 )
{
if ( V_12 == 0 )
return F_28 ( V_45 ) ;
else
return F_24 ( V_45 , V_12 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
int V_63 = ( V_62 [ 0 ] & V_64 )
>> V_65 ;
T_2 * V_66 = ( T_2 * ) & V_62 [ 1 ] ;
struct V_30 * V_29 = & V_2 -> V_29 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
T_1 V_70 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_63 = F_32 ( V_63 , V_71 ) ;
V_29 -> V_72 = V_63 ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 ++ ) {
V_29 -> V_73 [ V_6 ] = V_66 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_29 -> V_72 ; V_6 ++ ) {
V_68 = ( V_29 -> V_73 [ V_6 ] >> 5 ) & 0x7F ;
V_67 = V_29 -> V_73 [ V_6 ] & 0x1F ;
V_69 = F_19 ( V_4 , F_33 ( V_68 ) ) ;
V_69 |= ( 1 << V_67 ) ;
F_6 ( V_4 , F_33 ( V_68 ) , V_69 ) ;
}
V_70 |= V_74 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_70 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 ;
int V_6 , V_75 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
T_1 V_70 = F_19 ( V_4 , F_31 ( V_6 ) ) ;
V_29 = & V_2 -> V_29 [ V_6 ] ;
for ( V_75 = 0 ; V_75 < V_29 -> V_72 ; V_75 ++ ) {
V_4 -> V_76 . V_77 ++ ;
V_68 = ( V_29 -> V_73 [ V_75 ] >> 5 ) & 0x7F ;
V_67 = V_29 -> V_73 [ V_75 ] & 0x1F ;
V_69 = F_19 ( V_4 , F_33 ( V_68 ) ) ;
V_69 |= ( 1 << V_67 ) ;
F_6 ( V_4 , F_33 ( V_68 ) , V_69 ) ;
}
if ( V_29 -> V_72 )
V_70 |= V_74 ;
else
V_70 &= ~ V_74 ;
F_6 ( V_4 , F_31 ( V_6 ) , V_70 ) ;
}
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_78 , int V_79 ,
T_1 V_24 )
{
if ( ! V_79 && ! V_78 )
return 0 ;
return V_2 -> V_4 . V_18 . V_80 . V_81 ( & V_2 -> V_4 , V_79 , V_24 , ( bool ) V_78 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 , T_1 * V_62 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_82 = V_62 [ 1 ] ;
T_1 V_83 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_84 * V_45 = V_2 -> V_85 ;
int V_86 = V_45 -> V_87 + V_88 ;
T_1 V_89 , V_90 , V_91 ;
T_3 V_46 = 0 ;
#ifdef F_38
if ( V_45 -> V_92 & V_93 )
V_86 = F_39 ( int , V_86 ,
V_94 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_95 ) {
case V_96 :
case V_97 :
if ( V_86 > V_98 )
break;
default:
if ( ( V_86 > V_98 ) ||
( V_82 > ( V_98 + V_99 ) ) )
V_46 = - V_100 ;
break;
}
V_90 = V_24 % 32 ;
V_89 = V_24 / 32 ;
V_91 = F_19 ( V_4 , F_40 ( V_89 ) ) ;
if ( V_46 )
V_91 &= ~ ( 1 << V_90 ) ;
else
V_91 |= 1 << V_90 ;
F_6 ( V_4 , F_40 ( V_89 ) , V_91 ) ;
if ( V_46 ) {
F_12 ( V_101 , L_7 , V_82 ) ;
return V_46 ;
}
}
if ( V_82 > V_102 ) {
F_12 ( V_101 , L_7 , V_82 ) ;
return - V_100 ;
}
V_83 = F_19 ( V_4 , V_103 ) ;
V_83 &= V_104 ;
V_83 >>= V_105 ;
if ( V_83 < V_82 ) {
V_83 = V_82 << V_105 ;
F_6 ( V_4 , V_103 , V_83 ) ;
}
F_2 ( V_4 , L_8 , V_82 ) ;
return 0 ;
}
static void F_41 ( struct V_3 * V_4 , T_1 V_24 , bool V_106 )
{
T_1 V_70 = F_19 ( V_4 , F_31 ( V_24 ) ) ;
V_70 |= V_107 ;
if ( V_106 )
V_70 |= V_108 ;
else
V_70 &= ~ V_108 ;
F_6 ( V_4 , F_31 ( V_24 ) , V_70 ) ;
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
T_4 V_33 = F_45 ( V_2 -> V_85 ) ;
F_36 ( V_2 , true , V_29 -> V_109 , V_24 ) ;
F_41 ( V_4 , V_24 , ! V_29 -> V_109 ) ;
if ( ! V_29 -> V_109 && ! V_29 -> V_110 && ! V_33 ) {
F_42 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_110 || ! V_33 )
F_46 ( V_2 , V_29 -> V_109 ,
V_29 -> V_110 , V_24 ) ;
else
F_46 ( V_2 , V_29 -> V_109 ,
V_2 -> V_111 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_80 . V_112 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_72 = 0 ;
F_47 ( V_2 -> V_85 ) ;
F_48 ( V_2 , V_2 -> V_29 [ V_24 ] . V_113 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_95 = V_114 ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_115 )
{
F_48 ( V_2 , V_2 -> V_29 [ V_24 ] . V_113 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_113 , V_115 , V_116 ) ;
F_50 ( V_2 , V_2 -> V_29 [ V_24 ] . V_113 , V_24 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_24 , int V_117 , unsigned char * V_115 )
{
struct V_118 * V_119 ;
struct V_7 * V_120 ;
if ( V_117 <= 1 ) {
F_52 (pos, &adapter->vf_mvs.l) {
V_120 = F_53 ( V_119 , struct V_7 , V_23 ) ;
if ( V_120 -> V_24 == V_24 ) {
V_120 -> V_24 = - 1 ;
V_120 -> free = true ;
V_120 -> V_121 = false ;
F_48 ( V_2 ,
V_120 -> V_122 , V_24 ) ;
}
}
}
if ( ! V_117 )
return 0 ;
V_120 = NULL ;
F_52 (pos, &adapter->vf_mvs.l) {
V_120 = F_53 ( V_119 , struct V_7 , V_23 ) ;
if ( V_120 -> free )
break;
}
if ( ! V_120 || ! V_120 -> free )
return - V_123 ;
V_120 -> free = false ;
V_120 -> V_121 = true ;
V_120 -> V_24 = V_24 ;
memcpy ( V_120 -> V_122 , V_115 , V_116 ) ;
F_50 ( V_2 , V_115 , V_24 ) ;
return 0 ;
}
int F_26 ( struct V_58 * V_44 , unsigned int V_124 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
unsigned int V_125 = ( V_124 & 0x3f ) ;
bool V_126 = ( ( V_124 & 0x10000000U ) != 0 ) ;
if ( V_126 )
F_54 ( V_2 -> V_29 [ V_125 ] . V_113 ) ;
return 0 ;
}
static inline void F_55 ( struct V_1 * V_2 , T_1 V_24 ,
T_1 V_127 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_128 * V_129 = & V_2 -> V_14 [ V_15 ] ;
T_1 V_130 = F_56 ( 1 , ~ V_129 -> V_131 ) ;
int V_6 ;
for ( V_6 = V_24 * V_130 ; V_6 < ( ( V_24 + 1 ) * V_130 ) ; V_6 ++ ) {
T_1 V_132 ;
F_20 ( V_4 ) ;
V_132 = V_133 | V_134 ;
V_132 |= V_6 << V_135 ;
F_6 ( V_4 , V_136 , V_132 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_128 * V_129 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_137 = V_2 -> V_29 [ V_24 ] . V_113 ;
T_1 V_132 , V_89 , V_90 ;
T_1 V_62 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_138 = ( T_4 * ) ( & V_62 [ 1 ] ) ;
T_1 V_130 = F_56 ( 1 , ~ V_129 -> V_131 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_44 ( V_2 , V_24 ) ;
if ( ! F_58 ( V_137 ) )
F_49 ( V_2 , V_24 , V_137 ) ;
V_90 = V_24 % 32 ;
V_89 = V_24 / 32 ;
V_132 = F_19 ( V_4 , F_59 ( V_89 ) ) ;
V_132 |= 1 << V_90 ;
F_6 ( V_4 , F_59 ( V_89 ) , V_132 ) ;
F_55 ( V_2 , V_24 , V_134 ) ;
V_132 = F_19 ( V_4 , F_40 ( V_89 ) ) ;
V_132 |= 1 << V_90 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_84 * V_45 = V_2 -> V_85 ;
int V_86 = V_45 -> V_87 + V_88 ;
#ifdef F_38
if ( V_45 -> V_92 & V_93 )
V_86 = F_39 ( int , V_86 ,
V_94 ) ;
#endif
if ( V_86 > V_98 )
V_132 &= ~ ( 1 << V_90 ) ;
}
F_6 ( V_4 , F_40 ( V_89 ) , V_132 ) ;
V_2 -> V_29 [ V_24 ] . V_139 = true ;
V_132 = F_19 ( V_4 , F_60 ( V_89 ) ) ;
V_132 |= ( 1 << V_90 ) ;
F_6 ( V_4 , F_60 ( V_89 ) , V_132 ) ;
for ( V_6 = 0 ; V_6 < V_130 ; V_6 ++ ) {
F_6 ( V_4 , F_61 ( V_130 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_62 ( V_130 , V_24 , V_6 ) , 0 ) ;
}
V_62 [ 0 ] = V_140 ;
if ( ! F_58 ( V_137 ) ) {
V_62 [ 0 ] |= V_141 ;
memcpy ( V_138 , V_137 , V_116 ) ;
} else {
V_62 [ 0 ] |= V_142 ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_10 ,
V_24 ) ;
}
V_62 [ 3 ] = V_4 -> V_18 . V_143 ;
F_63 ( V_4 , V_62 , V_144 , V_24 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_4 * V_145 = ( ( T_4 * ) ( & V_62 [ 1 ] ) ) ;
if ( ! F_65 ( V_145 ) ) {
F_66 ( V_101 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_146 &&
! F_67 ( V_2 -> V_29 [ V_24 ] . V_113 , V_145 ) ) {
F_66 ( V_101 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_49 ( V_2 , V_24 , V_145 ) < 0 ;
}
static int F_68 ( struct V_3 * V_4 , T_1 V_147 )
{
T_1 V_148 ;
T_3 V_149 ;
if ( V_147 == 0 )
return 0 ;
for ( V_149 = 1 ; V_149 < V_150 ; V_149 ++ ) {
V_148 = F_19 ( V_4 , F_69 ( V_149 ) ) ;
if ( ( V_148 & V_151 ) == V_147 )
break;
}
if ( V_149 >= V_150 )
V_149 = - 1 ;
return V_149 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_78 = ( V_62 [ 0 ] & V_64 ) >> V_65 ;
int V_79 = ( V_62 [ 1 ] & V_152 ) ;
int V_46 ;
T_3 V_153 ;
T_1 V_148 ;
T_1 V_154 ;
T_4 V_155 = F_45 ( V_2 -> V_85 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_109 || V_155 ) {
F_66 ( V_101 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( V_78 )
V_2 -> V_29 [ V_24 ] . V_156 ++ ;
else if ( V_2 -> V_29 [ V_24 ] . V_156 )
V_2 -> V_29 [ V_24 ] . V_156 -- ;
if ( V_78 && V_2 -> V_85 -> V_9 & V_157 )
V_46 = F_36 ( V_2 , V_78 , V_79 , F_71 ( 0 ) ) ;
V_46 = F_36 ( V_2 , V_78 , V_79 , V_24 ) ;
if ( ! V_46 && V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_80 . V_112 ( V_4 , true , V_24 ) ;
if ( ! V_78 && V_2 -> V_85 -> V_9 & V_157 ) {
V_153 = F_68 ( V_4 , V_79 ) ;
if ( V_153 < 0 )
return V_46 ;
V_148 = F_19 ( V_4 , F_69 ( V_153 ) ) ;
if ( F_71 ( 0 ) < 32 ) {
V_154 = F_19 ( V_4 , F_72 ( V_153 * 2 ) ) ;
V_154 &= ~ ( 1 << F_71 ( 0 ) ) ;
V_154 |= F_19 ( V_4 ,
F_72 ( V_153 * 2 ) + 1 ) ;
} else {
V_154 = F_19 ( V_4 ,
F_72 ( V_153 * 2 ) + 1 ) ;
V_154 &= ~ ( 1 << ( F_71 ( 0 ) - 32 ) ) ;
V_154 |= F_19 ( V_4 , F_72 ( V_153 * 2 ) ) ;
}
if ( ( V_148 & V_151 ) == V_79 &&
! F_73 ( V_79 , V_2 -> V_158 ) && ! V_154 )
F_36 ( V_2 , V_78 , V_79 , F_71 ( 0 ) ) ;
}
return V_46 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_4 * V_145 = ( ( T_4 * ) ( & V_62 [ 1 ] ) ) ;
int V_117 = ( V_62 [ 0 ] & V_64 ) >>
V_65 ;
int V_46 ;
if ( V_2 -> V_29 [ V_24 ] . V_146 && V_117 > 0 ) {
F_66 ( V_101 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_117 ) {
if ( ! F_65 ( V_145 ) ) {
F_66 ( V_101 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 )
F_75 ( V_2 -> V_85 , V_24 , false ) ;
}
V_46 = F_51 ( V_2 , V_24 , V_117 , V_145 ) ;
if ( V_46 == - V_123 )
F_66 ( V_101 ,
L_16 ,
V_24 ) ;
return V_46 < 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
int V_159 = V_62 [ 1 ] ;
switch ( V_159 ) {
case V_114 :
case V_96 :
case V_97 :
V_2 -> V_29 [ V_24 ] . V_95 = V_159 ;
return 0 ;
default:
break;
}
F_2 ( V_101 , L_17 , V_24 , V_159 ) ;
return - 1 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
struct V_84 * V_45 = V_2 -> V_85 ;
struct V_128 * V_129 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_160 = 0 ;
T_4 V_33 = F_45 ( V_45 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_95 ) {
case V_161 :
case V_96 :
case V_97 :
break;
default:
return - 1 ;
}
V_62 [ V_162 ] = F_56 ( 1 , ~ V_129 -> V_131 ) ;
V_62 [ V_163 ] = F_56 ( 1 , ~ V_129 -> V_131 ) ;
if ( V_33 > 1 )
V_160 = F_78 ( V_45 , V_2 -> V_111 ) ;
if ( V_33 )
V_62 [ V_164 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_109 || V_2 -> V_29 [ V_24 ] . V_110 )
V_62 [ V_164 ] = 1 ;
else
V_62 [ V_164 ] = 0 ;
V_62 [ V_165 ] = V_160 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 * V_62 , T_1 V_24 )
{
T_1 V_6 , V_75 ;
T_1 * V_166 = & V_62 [ 1 ] ;
const T_4 * V_167 = V_2 -> V_168 ;
T_1 V_169 = F_80 ( V_2 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_50 ;
if ( V_2 -> V_29 [ V_24 ] . V_95 != V_97 )
return - V_170 ;
for ( V_6 = 0 ; V_6 < V_169 / 16 ; V_6 ++ ) {
V_166 [ V_6 ] = 0 ;
for ( V_75 = 0 ; V_75 < 16 ; V_75 ++ )
V_166 [ V_6 ] |= ( T_1 ) ( V_167 [ 16 * V_6 + V_75 ] & 0x3 ) << ( 2 * V_75 ) ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_1 * V_171 = & V_62 [ 1 ] ;
if ( ! V_2 -> V_29 [ V_24 ] . V_41 )
return - V_50 ;
if ( V_2 -> V_29 [ V_24 ] . V_95 != V_97 )
return - V_170 ;
memcpy ( V_171 , V_2 -> V_171 , sizeof( V_2 -> V_171 ) ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_172 = V_173 ;
T_1 V_62 [ V_173 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_174 ;
V_174 = F_83 ( V_4 , V_62 , V_172 , V_24 ) ;
if ( V_174 ) {
F_84 ( L_18 ) ;
return V_174 ;
}
if ( V_62 [ 0 ] & ( V_141 | V_142 ) )
return 0 ;
F_20 ( V_4 ) ;
if ( V_62 [ 0 ] == V_140 )
return F_57 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_139 ) {
V_62 [ 0 ] |= V_142 ;
F_63 ( V_4 , V_62 , 1 , V_24 ) ;
return 0 ;
}
switch ( ( V_62 [ 0 ] & 0xFFFF ) ) {
case V_175 :
V_174 = F_64 ( V_2 , V_62 , V_24 ) ;
break;
case V_176 :
V_174 = F_30 ( V_2 , V_62 , V_24 ) ;
break;
case V_177 :
V_174 = F_70 ( V_2 , V_62 , V_24 ) ;
break;
case V_178 :
V_174 = F_37 ( V_2 , V_62 , V_24 ) ;
break;
case V_179 :
V_174 = F_74 ( V_2 , V_62 , V_24 ) ;
break;
case V_180 :
V_174 = F_76 ( V_2 , V_62 , V_24 ) ;
break;
case V_181 :
V_174 = F_77 ( V_2 , V_62 , V_24 ) ;
break;
case V_182 :
V_174 = F_79 ( V_2 , V_62 , V_24 ) ;
break;
case V_183 :
V_174 = F_81 ( V_2 , V_62 , V_24 ) ;
break;
default:
F_12 ( V_101 , L_19 , V_62 [ 0 ] ) ;
V_174 = V_184 ;
break;
}
if ( V_174 )
V_62 [ 0 ] |= V_142 ;
else
V_62 [ 0 ] |= V_141 ;
V_62 [ 0 ] |= V_185 ;
F_63 ( V_4 , V_62 , V_172 , V_24 ) ;
return V_174 ;
}
static void F_85 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_186 = V_142 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_139 )
F_63 ( V_4 , & V_186 , 1 , V_24 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_87 ( V_4 , V_24 ) )
F_44 ( V_2 , V_24 ) ;
if ( ! F_88 ( V_4 , V_24 ) )
F_82 ( V_2 , V_24 ) ;
if ( ! F_89 ( V_4 , V_24 ) )
F_85 ( V_2 , V_24 ) ;
}
}
void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_59 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_59 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 1 ) , 0 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_187 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_187 = V_188 ;
if ( V_2 -> V_29 [ V_6 ] . V_139 )
V_187 |= V_185 ;
F_63 ( V_4 , & V_187 , 1 , V_6 ) ;
}
}
int F_92 ( struct V_84 * V_85 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_93 ( V_85 ) ;
if ( ! F_65 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_100 ;
V_2 -> V_29 [ V_24 ] . V_146 = true ;
F_94 ( & V_2 -> V_44 -> V_45 , L_20 , V_18 , V_24 ) ;
F_94 ( & V_2 -> V_44 -> V_45 , L_21
L_22 ) ;
if ( F_73 ( V_189 , & V_2 -> V_190 ) ) {
F_9 ( & V_2 -> V_44 -> V_45 , L_23
L_24 ) ;
F_9 ( & V_2 -> V_44 -> V_45 , L_25
L_26 ) ;
}
return F_49 ( V_2 , V_24 , V_18 ) ;
}
static int F_95 ( struct V_1 * V_2 , int V_24 ,
T_2 V_147 , T_4 V_191 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_46 ;
V_46 = F_36 ( V_2 , true , V_147 , V_24 ) ;
if ( V_46 )
goto V_192;
F_46 ( V_2 , V_147 , V_191 , V_24 ) ;
F_41 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_80 . V_112 ( V_4 , true , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_156 ++ ;
if ( V_4 -> V_18 . type >= V_193 )
F_55 ( V_2 , V_24 , V_134 |
V_194 ) ;
V_2 -> V_29 [ V_24 ] . V_109 = V_147 ;
V_2 -> V_29 [ V_24 ] . V_110 = V_191 ;
F_94 ( & V_2 -> V_44 -> V_45 ,
L_27 , V_147 , V_191 , V_24 ) ;
if ( F_73 ( V_189 , & V_2 -> V_190 ) ) {
F_9 ( & V_2 -> V_44 -> V_45 ,
L_28 ) ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_29 ) ;
}
V_192:
return V_46 ;
}
static int F_96 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_46 ;
V_46 = F_36 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_109 , V_24 ) ;
F_42 ( V_2 , V_24 ) ;
F_41 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_80 . V_112 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_156 )
V_2 -> V_29 [ V_24 ] . V_156 -- ;
if ( V_4 -> V_18 . type >= V_193 )
F_55 ( V_2 , V_24 , V_134 ) ;
V_2 -> V_29 [ V_24 ] . V_109 = 0 ;
V_2 -> V_29 [ V_24 ] . V_110 = 0 ;
return V_46 ;
}
int F_97 ( struct V_84 * V_85 , int V_24 , T_2 V_147 , T_4 V_191 )
{
int V_46 = 0 ;
struct V_1 * V_2 = F_93 ( V_85 ) ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_147 > 4095 ) || ( V_191 > 7 ) )
return - V_100 ;
if ( V_147 || V_191 ) {
if ( V_2 -> V_29 [ V_24 ] . V_109 )
V_46 = F_96 ( V_2 , V_24 ) ;
if ( V_46 )
goto V_192;
V_46 = F_95 ( V_2 , V_24 , V_147 , V_191 ) ;
} else {
V_46 = F_96 ( V_2 , V_24 ) ;
}
V_192:
return V_46 ;
}
static int F_98 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_195 ) {
case V_196 :
return 100 ;
case V_197 :
return 1000 ;
case V_198 :
return 10000 ;
default:
return 0 ;
}
}
static void F_99 ( struct V_1 * V_2 , int V_24 )
{
struct V_128 * V_129 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_199 = 0 ;
T_2 V_200 , V_201 ;
T_2 V_202 = V_2 -> V_29 [ V_24 ] . V_202 ;
if ( V_202 ) {
V_199 = V_2 -> V_203 ;
V_199 <<= V_204 ;
V_199 /= V_202 ;
V_199 &= V_205 |
V_206 ;
V_199 |= V_207 ;
}
switch ( V_4 -> V_18 . type ) {
case V_31 :
F_6 ( V_4 , V_208 , 0x4 ) ;
break;
case V_209 :
F_6 ( V_4 , V_208 , 0x14 ) ;
break;
default:
break;
}
V_201 = F_56 ( 1 , ~ V_129 -> V_131 ) ;
for ( V_200 = 0 ; V_200 < V_201 ; V_200 ++ ) {
unsigned int V_210 = ( V_24 * V_201 ) + V_200 ;
F_6 ( V_4 , V_211 , V_210 ) ;
F_6 ( V_4 , V_212 , V_199 ) ;
}
}
void F_100 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_203 )
return;
if ( F_98 ( V_2 ) != V_2 -> V_203 ) {
V_2 -> V_203 = 0 ;
F_94 ( & V_2 -> V_44 -> V_45 ,
L_30 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_203 )
V_2 -> V_29 [ V_6 ] . V_202 = 0 ;
F_99 ( V_2 , V_6 ) ;
}
}
int F_101 ( struct V_84 * V_85 , int V_24 , int V_213 ,
int V_214 )
{
struct V_1 * V_2 = F_93 ( V_85 ) ;
int V_195 ;
if ( V_24 >= V_2 -> V_12 )
return - V_100 ;
if ( ! V_2 -> V_215 )
return - V_100 ;
V_195 = F_98 ( V_2 ) ;
if ( V_195 != 10000 )
return - V_100 ;
if ( V_213 )
return - V_100 ;
if ( V_214 && ( ( V_214 <= 10 ) || ( V_214 > V_195 ) ) )
return - V_100 ;
V_2 -> V_203 = V_195 ;
V_2 -> V_29 [ V_24 ] . V_202 = V_214 ;
F_99 ( V_2 , V_24 ) ;
return 0 ;
}
int F_75 ( struct V_84 * V_85 , int V_24 , bool V_216 )
{
struct V_1 * V_2 = F_93 ( V_85 ) ;
int V_217 = V_24 >> 3 ;
int V_218 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_219 ;
if ( V_24 >= V_2 -> V_12 )
return - V_100 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_216 ;
V_219 = F_19 ( V_4 , F_102 ( V_217 ) ) ;
V_219 &= ~ ( 1 << V_218 ) ;
V_219 |= ( V_216 << V_218 ) ;
F_6 ( V_4 , F_102 ( V_217 ) , V_219 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_156 ) {
V_218 += V_220 ;
V_219 = F_19 ( V_4 , F_102 ( V_217 ) ) ;
V_219 &= ~ ( 1 << V_218 ) ;
V_219 |= ( V_216 << V_218 ) ;
F_6 ( V_4 , F_102 ( V_217 ) , V_219 ) ;
}
return 0 ;
}
int F_103 ( struct V_84 * V_85 , int V_24 ,
bool V_216 )
{
struct V_1 * V_2 = F_93 ( V_85 ) ;
if ( V_2 -> V_4 . V_18 . type < V_31 ||
V_2 -> V_4 . V_18 . type >= V_193 )
return - V_170 ;
if ( V_24 >= V_2 -> V_12 )
return - V_100 ;
V_2 -> V_29 [ V_24 ] . V_41 = V_216 ;
return 0 ;
}
int F_104 ( struct V_84 * V_85 ,
int V_24 , struct V_221 * V_222 )
{
struct V_1 * V_2 = F_93 ( V_85 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_100 ;
V_222 -> V_24 = V_24 ;
memcpy ( & V_222 -> V_18 , V_2 -> V_29 [ V_24 ] . V_113 , V_116 ) ;
V_222 -> V_214 = V_2 -> V_29 [ V_24 ] . V_202 ;
V_222 -> V_213 = 0 ;
V_222 -> V_147 = V_2 -> V_29 [ V_24 ] . V_109 ;
V_222 -> V_191 = V_2 -> V_29 [ V_24 ] . V_110 ;
V_222 -> V_223 = V_2 -> V_29 [ V_24 ] . V_40 ;
V_222 -> V_224 = V_2 -> V_29 [ V_24 ] . V_41 ;
return 0 ;
}
