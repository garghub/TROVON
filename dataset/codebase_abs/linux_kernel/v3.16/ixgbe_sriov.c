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
goto V_58;
if ( V_45 )
goto V_59;
if ( V_12 > V_60 ) {
V_45 = - V_49 ;
goto V_59;
}
V_2 -> V_12 = V_12 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 )
goto V_59;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_25 ( V_44 , ( V_6 | 0x10000000 ) ) ;
V_45 = F_11 ( V_44 , V_12 ) ;
if ( V_45 ) {
F_17 ( L_3 , V_45 ) ;
goto V_59;
}
F_26 ( V_2 ) ;
V_58:
return V_12 ;
V_59:
return V_45 ;
#endif
return 0 ;
}
static int F_27 ( struct V_57 * V_44 )
{
struct V_1 * V_2 = F_24 ( V_44 ) ;
int V_45 ;
#ifdef F_15
T_1 V_61 = V_2 -> V_9 ;
#endif
V_45 = F_13 ( V_2 ) ;
#ifdef F_15
if ( ! V_45 && V_61 != V_2 -> V_9 )
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
T_1 V_70 = F_19 ( V_4 , F_30 ( V_24 ) ) ;
V_63 = F_31 ( V_63 , V_71 ) ;
V_29 -> V_72 = V_63 ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 ++ ) {
V_29 -> V_73 [ V_6 ] = V_66 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_29 -> V_72 ; V_6 ++ ) {
V_68 = ( V_29 -> V_73 [ V_6 ] >> 5 ) & 0x7F ;
V_67 = V_29 -> V_73 [ V_6 ] & 0x1F ;
V_69 = F_19 ( V_4 , F_32 ( V_68 ) ) ;
V_69 |= ( 1 << V_67 ) ;
F_6 ( V_4 , F_32 ( V_68 ) , V_69 ) ;
}
V_70 |= V_74 ;
F_6 ( V_4 , F_30 ( V_24 ) , V_70 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_29 ;
int V_6 , V_75 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
T_1 V_70 = F_19 ( V_4 , F_30 ( V_6 ) ) ;
V_29 = & V_2 -> V_29 [ V_6 ] ;
for ( V_75 = 0 ; V_75 < V_29 -> V_72 ; V_75 ++ ) {
V_4 -> V_76 . V_77 ++ ;
V_68 = ( V_29 -> V_73 [ V_75 ] >> 5 ) & 0x7F ;
V_67 = V_29 -> V_73 [ V_75 ] & 0x1F ;
V_69 = F_19 ( V_4 , F_32 ( V_68 ) ) ;
V_69 |= ( 1 << V_67 ) ;
F_6 ( V_4 , F_32 ( V_68 ) , V_69 ) ;
}
if ( V_29 -> V_72 )
V_70 |= V_74 ;
else
V_70 &= ~ V_74 ;
F_6 ( V_4 , F_30 ( V_6 ) , V_70 ) ;
}
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , int V_78 , int V_79 ,
T_1 V_24 )
{
if ( ! V_79 && ! V_78 )
return 0 ;
return V_2 -> V_4 . V_18 . V_80 . V_81 ( & V_2 -> V_4 , V_79 , V_24 , ( bool ) V_78 ) ;
}
static T_3 F_36 ( struct V_1 * V_2 , T_1 * V_62 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_82 = V_62 [ 1 ] ;
T_1 V_83 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_84 * V_44 = V_2 -> V_85 ;
int V_86 = V_44 -> V_87 + V_88 ;
T_1 V_89 , V_90 , V_91 ;
T_3 V_45 = 0 ;
#ifdef F_37
if ( V_44 -> V_92 & V_93 )
V_86 = F_38 ( int , V_86 ,
V_94 ) ;
#endif
switch ( V_2 -> V_29 [ V_24 ] . V_95 ) {
case V_96 :
if ( V_86 > V_97 )
break;
default:
if ( ( V_86 > V_97 ) ||
( V_82 > ( V_97 + V_98 ) ) )
V_45 = - V_99 ;
break;
}
V_90 = V_24 % 32 ;
V_89 = V_24 / 32 ;
V_91 = F_19 ( V_4 , F_39 ( V_89 ) ) ;
if ( V_45 )
V_91 &= ~ ( 1 << V_90 ) ;
else
V_91 |= 1 << V_90 ;
F_6 ( V_4 , F_39 ( V_89 ) , V_91 ) ;
if ( V_45 ) {
F_12 ( V_100 , L_7 , V_82 ) ;
return V_45 ;
}
}
if ( V_82 > V_101 ) {
F_12 ( V_100 , L_7 , V_82 ) ;
return - V_99 ;
}
V_83 = F_19 ( V_4 , V_102 ) ;
V_83 &= V_103 ;
V_83 >>= V_104 ;
if ( V_83 < V_82 ) {
V_83 = V_82 << V_104 ;
F_6 ( V_4 , V_102 , V_83 ) ;
}
F_2 ( V_4 , L_8 , V_82 ) ;
return 0 ;
}
static void F_40 ( struct V_3 * V_4 , T_1 V_24 , bool V_105 )
{
T_1 V_70 = F_19 ( V_4 , F_30 ( V_24 ) ) ;
V_70 |= V_106 ;
if ( V_105 )
V_70 |= V_107 ;
else
V_70 &= ~ V_107 ;
F_6 ( V_4 , F_30 ( V_24 ) , V_70 ) ;
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
T_4 V_33 = F_44 ( V_2 -> V_85 ) ;
F_35 ( V_2 , true , V_29 -> V_108 , V_24 ) ;
F_40 ( V_4 , V_24 , ! V_29 -> V_108 ) ;
if ( ! V_29 -> V_108 && ! V_29 -> V_109 && ! V_33 ) {
F_41 ( V_2 , V_24 ) ;
} else {
if ( V_29 -> V_109 || ! V_33 )
F_45 ( V_2 , V_29 -> V_108 ,
V_29 -> V_109 , V_24 ) ;
else
F_45 ( V_2 , V_29 -> V_108 ,
V_2 -> V_110 , V_24 ) ;
if ( V_29 -> V_40 )
V_4 -> V_18 . V_80 . V_111 ( V_4 , true , V_24 ) ;
}
V_2 -> V_29 [ V_24 ] . V_72 = 0 ;
F_46 ( V_2 -> V_85 ) ;
F_47 ( V_2 , V_2 -> V_29 [ V_24 ] . V_112 , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_95 = V_113 ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_114 )
{
F_47 ( V_2 , V_2 -> V_29 [ V_24 ] . V_112 , V_24 ) ;
memcpy ( V_2 -> V_29 [ V_24 ] . V_112 , V_114 , V_115 ) ;
F_49 ( V_2 , V_2 -> V_29 [ V_24 ] . V_112 , V_24 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_24 , int V_116 , unsigned char * V_114 )
{
struct V_117 * V_118 ;
struct V_7 * V_119 ;
if ( V_116 <= 1 ) {
F_51 (pos, &adapter->vf_mvs.l) {
V_119 = F_52 ( V_118 , struct V_7 , V_23 ) ;
if ( V_119 -> V_24 == V_24 ) {
V_119 -> V_24 = - 1 ;
V_119 -> free = true ;
V_119 -> V_120 = false ;
F_47 ( V_2 ,
V_119 -> V_121 , V_24 ) ;
}
}
}
if ( ! V_116 )
return 0 ;
V_119 = NULL ;
F_51 (pos, &adapter->vf_mvs.l) {
V_119 = F_52 ( V_118 , struct V_7 , V_23 ) ;
if ( V_119 -> free )
break;
}
if ( ! V_119 || ! V_119 -> free )
return - V_122 ;
V_119 -> free = false ;
V_119 -> V_120 = true ;
V_119 -> V_24 = V_24 ;
memcpy ( V_119 -> V_121 , V_114 , V_115 ) ;
F_49 ( V_2 , V_114 , V_24 ) ;
return 0 ;
}
int F_25 ( struct V_57 * V_43 , unsigned int V_123 )
{
struct V_1 * V_2 = F_24 ( V_43 ) ;
unsigned int V_124 = ( V_123 & 0x3f ) ;
bool V_125 = ( ( V_123 & 0x10000000U ) != 0 ) ;
if ( V_125 )
F_53 ( V_2 -> V_29 [ V_124 ] . V_112 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_126 * V_127 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_128 = V_2 -> V_29 [ V_24 ] . V_112 ;
T_1 V_129 , V_89 , V_90 ;
T_1 V_62 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_130 = ( T_4 * ) ( & V_62 [ 1 ] ) ;
T_1 V_131 = F_55 ( 1 , ~ V_127 -> V_132 ) ;
int V_6 ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_43 ( V_2 , V_24 ) ;
if ( ! F_56 ( V_128 ) )
F_48 ( V_2 , V_24 , V_128 ) ;
V_90 = V_24 % 32 ;
V_89 = V_24 / 32 ;
V_129 = F_19 ( V_4 , F_57 ( V_89 ) ) ;
V_129 |= 1 << V_90 ;
F_6 ( V_4 , F_57 ( V_89 ) , V_129 ) ;
for ( V_6 = V_24 * V_131 ; V_6 < ( ( V_24 + 1 ) * V_131 ) ; V_6 ++ ) {
F_20 ( V_4 ) ;
V_129 = V_133 | V_134 ;
V_129 |= V_6 << V_135 ;
F_6 ( V_4 , V_136 , V_129 ) ;
}
V_129 = F_19 ( V_4 , F_39 ( V_89 ) ) ;
V_129 |= 1 << V_90 ;
if ( V_2 -> V_4 . V_18 . type == V_31 ) {
struct V_84 * V_44 = V_2 -> V_85 ;
int V_86 = V_44 -> V_87 + V_88 ;
#ifdef F_37
if ( V_44 -> V_92 & V_93 )
V_86 = F_38 ( int , V_86 ,
V_94 ) ;
#endif
if ( V_86 > V_97 )
V_129 &= ~ ( 1 << V_90 ) ;
}
F_6 ( V_4 , F_39 ( V_89 ) , V_129 ) ;
V_2 -> V_29 [ V_24 ] . V_137 = true ;
V_129 = F_19 ( V_4 , F_58 ( V_89 ) ) ;
V_129 |= ( 1 << V_90 ) ;
F_6 ( V_4 , F_58 ( V_89 ) , V_129 ) ;
for ( V_6 = 0 ; V_6 < V_131 ; V_6 ++ ) {
F_6 ( V_4 , F_59 ( V_131 , V_24 , V_6 ) , 0 ) ;
F_6 ( V_4 , F_60 ( V_131 , V_24 , V_6 ) , 0 ) ;
}
V_62 [ 0 ] = V_138 ;
if ( ! F_56 ( V_128 ) ) {
V_62 [ 0 ] |= V_139 ;
memcpy ( V_130 , V_128 , V_115 ) ;
} else {
V_62 [ 0 ] |= V_140 ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_10 ,
V_24 ) ;
}
V_62 [ 3 ] = V_4 -> V_18 . V_141 ;
F_61 ( V_4 , V_62 , V_142 , V_24 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_4 * V_143 = ( ( T_4 * ) ( & V_62 [ 1 ] ) ) ;
if ( ! F_63 ( V_143 ) ) {
F_64 ( V_100 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_144 &&
! F_65 ( V_2 -> V_29 [ V_24 ] . V_112 , V_143 ) ) {
F_64 ( V_100 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_48 ( V_2 , V_24 , V_143 ) < 0 ;
}
static int F_66 ( struct V_3 * V_4 , T_1 V_145 )
{
T_1 V_146 ;
T_3 V_147 ;
if ( V_145 == 0 )
return 0 ;
for ( V_147 = 1 ; V_147 < V_148 ; V_147 ++ ) {
V_146 = F_19 ( V_4 , F_67 ( V_147 ) ) ;
if ( ( V_146 & V_149 ) == V_145 )
break;
}
if ( V_147 >= V_148 )
V_147 = - 1 ;
return V_147 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_78 = ( V_62 [ 0 ] & V_64 ) >> V_65 ;
int V_79 = ( V_62 [ 1 ] & V_150 ) ;
int V_45 ;
T_3 V_151 ;
T_1 V_146 ;
T_1 V_152 ;
T_4 V_153 = F_44 ( V_2 -> V_85 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_108 || V_153 ) {
F_64 ( V_100 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( V_78 )
V_2 -> V_29 [ V_24 ] . V_154 ++ ;
else if ( V_2 -> V_29 [ V_24 ] . V_154 )
V_2 -> V_29 [ V_24 ] . V_154 -- ;
if ( V_78 && V_2 -> V_85 -> V_9 & V_155 )
V_45 = F_35 ( V_2 , V_78 , V_79 , F_69 ( 0 ) ) ;
V_45 = F_35 ( V_2 , V_78 , V_79 , V_24 ) ;
if ( ! V_45 && V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_80 . V_111 ( V_4 , true , V_24 ) ;
if ( ! V_78 && V_2 -> V_85 -> V_9 & V_155 ) {
V_151 = F_66 ( V_4 , V_79 ) ;
if ( V_151 < 0 )
goto V_58;
V_146 = F_19 ( V_4 , F_67 ( V_151 ) ) ;
if ( F_69 ( 0 ) < 32 ) {
V_152 = F_19 ( V_4 , F_70 ( V_151 * 2 ) ) ;
V_152 &= ~ ( 1 << F_69 ( 0 ) ) ;
V_152 |= F_19 ( V_4 ,
F_70 ( V_151 * 2 ) + 1 ) ;
} else {
V_152 = F_19 ( V_4 ,
F_70 ( V_151 * 2 ) + 1 ) ;
V_152 &= ~ ( 1 << ( F_69 ( 0 ) - 32 ) ) ;
V_152 |= F_19 ( V_4 , F_70 ( V_151 * 2 ) ) ;
}
if ( ( V_146 & V_149 ) == V_79 &&
! F_71 ( V_79 , V_2 -> V_156 ) && ! V_152 )
F_35 ( V_2 , V_78 , V_79 , F_69 ( 0 ) ) ;
}
V_58:
return V_45 ;
}
static int F_72 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_4 * V_143 = ( ( T_4 * ) ( & V_62 [ 1 ] ) ) ;
int V_116 = ( V_62 [ 0 ] & V_64 ) >>
V_65 ;
int V_45 ;
if ( V_2 -> V_29 [ V_24 ] . V_144 && V_116 > 0 ) {
F_64 ( V_100 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_116 ) {
if ( ! F_63 ( V_143 ) ) {
F_64 ( V_100 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_29 [ V_24 ] . V_40 )
F_73 ( V_2 -> V_85 , V_24 , false ) ;
}
V_45 = F_50 ( V_2 , V_24 , V_116 , V_143 ) ;
if ( V_45 == - V_122 )
F_64 ( V_100 ,
L_16 ,
V_24 ) ;
return V_45 < 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
int V_157 = V_62 [ 1 ] ;
switch ( V_157 ) {
case V_113 :
case V_96 :
V_2 -> V_29 [ V_24 ] . V_95 = V_157 ;
return 0 ;
default:
break;
}
F_2 ( V_100 , L_17 , V_24 , V_157 ) ;
return - 1 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
struct V_84 * V_44 = V_2 -> V_85 ;
struct V_126 * V_127 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_158 = 0 ;
T_4 V_33 = F_44 ( V_44 ) ;
switch ( V_2 -> V_29 [ V_24 ] . V_95 ) {
case V_159 :
case V_96 :
break;
default:
return - 1 ;
}
V_62 [ V_160 ] = F_55 ( 1 , ~ V_127 -> V_132 ) ;
V_62 [ V_161 ] = F_55 ( 1 , ~ V_127 -> V_132 ) ;
if ( V_33 > 1 )
V_158 = F_76 ( V_44 , V_2 -> V_110 ) ;
if ( V_33 )
V_62 [ V_162 ] = V_33 ;
else if ( V_2 -> V_29 [ V_24 ] . V_108 || V_2 -> V_29 [ V_24 ] . V_109 )
V_62 [ V_162 ] = 1 ;
else
V_62 [ V_162 ] = 0 ;
V_62 [ V_163 ] = V_158 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_164 = V_165 ;
T_1 V_62 [ V_165 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_166 ;
V_166 = F_78 ( V_4 , V_62 , V_164 , V_24 ) ;
if ( V_166 ) {
F_79 ( L_18 ) ;
return V_166 ;
}
if ( V_62 [ 0 ] & ( V_139 | V_140 ) )
return V_166 ;
F_20 ( V_4 ) ;
if ( V_62 [ 0 ] == V_138 )
return F_54 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_29 [ V_24 ] . V_137 ) {
V_62 [ 0 ] |= V_140 ;
F_61 ( V_4 , V_62 , 1 , V_24 ) ;
return V_166 ;
}
switch ( ( V_62 [ 0 ] & 0xFFFF ) ) {
case V_167 :
V_166 = F_62 ( V_2 , V_62 , V_24 ) ;
break;
case V_168 :
V_166 = F_29 ( V_2 , V_62 , V_24 ) ;
break;
case V_169 :
V_166 = F_68 ( V_2 , V_62 , V_24 ) ;
break;
case V_170 :
V_166 = F_36 ( V_2 , V_62 , V_24 ) ;
break;
case V_171 :
V_166 = F_72 ( V_2 , V_62 , V_24 ) ;
break;
case V_172 :
V_166 = F_74 ( V_2 , V_62 , V_24 ) ;
break;
case V_173 :
V_166 = F_75 ( V_2 , V_62 , V_24 ) ;
break;
default:
F_12 ( V_100 , L_19 , V_62 [ 0 ] ) ;
V_166 = V_174 ;
break;
}
if ( V_166 )
V_62 [ 0 ] |= V_140 ;
else
V_62 [ 0 ] |= V_139 ;
V_62 [ 0 ] |= V_175 ;
F_61 ( V_4 , V_62 , V_164 , V_24 ) ;
return V_166 ;
}
static void F_80 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_176 = V_140 ;
if ( ! V_2 -> V_29 [ V_24 ] . V_137 )
F_61 ( V_4 , & V_176 , 1 , V_24 ) ;
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
T_1 V_177 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_177 = V_178 ;
if ( V_2 -> V_29 [ V_6 ] . V_137 )
V_177 |= V_175 ;
F_61 ( V_4 , & V_177 , 1 , V_6 ) ;
}
}
int F_87 ( struct V_84 * V_85 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_88 ( V_85 ) ;
if ( ! F_63 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_99 ;
V_2 -> V_29 [ V_24 ] . V_144 = true ;
F_89 ( & V_2 -> V_43 -> V_44 , L_20 , V_18 , V_24 ) ;
F_89 ( & V_2 -> V_43 -> V_44 , L_21
L_22 ) ;
if ( F_71 ( V_179 , & V_2 -> V_180 ) ) {
F_9 ( & V_2 -> V_43 -> V_44 , L_23
L_24 ) ;
F_9 ( & V_2 -> V_43 -> V_44 , L_25
L_26 ) ;
}
return F_48 ( V_2 , V_24 , V_18 ) ;
}
int F_90 ( struct V_84 * V_85 , int V_24 , T_2 V_145 , T_4 V_181 )
{
int V_45 = 0 ;
struct V_1 * V_2 = F_88 ( V_85 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_145 > 4095 ) || ( V_181 > 7 ) )
return - V_99 ;
if ( V_145 || V_181 ) {
if ( V_2 -> V_29 [ V_24 ] . V_108 )
V_45 = F_35 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_108 ,
V_24 ) ;
if ( V_45 )
goto V_58;
V_45 = F_35 ( V_2 , true , V_145 , V_24 ) ;
if ( V_45 )
goto V_58;
F_45 ( V_2 , V_145 , V_181 , V_24 ) ;
F_40 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_29 [ V_24 ] . V_40 )
V_4 -> V_18 . V_80 . V_111 ( V_4 , true , V_24 ) ;
V_2 -> V_29 [ V_24 ] . V_154 ++ ;
V_2 -> V_29 [ V_24 ] . V_108 = V_145 ;
V_2 -> V_29 [ V_24 ] . V_109 = V_181 ;
F_89 ( & V_2 -> V_43 -> V_44 ,
L_27 , V_145 , V_181 , V_24 ) ;
if ( F_71 ( V_179 , & V_2 -> V_180 ) ) {
F_9 ( & V_2 -> V_43 -> V_44 ,
L_28
L_24 ) ;
F_9 ( & V_2 -> V_43 -> V_44 ,
L_25
L_26 ) ;
}
} else {
V_45 = F_35 ( V_2 , false ,
V_2 -> V_29 [ V_24 ] . V_108 , V_24 ) ;
F_41 ( V_2 , V_24 ) ;
F_40 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_80 . V_111 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_154 )
V_2 -> V_29 [ V_24 ] . V_154 -- ;
V_2 -> V_29 [ V_24 ] . V_108 = 0 ;
V_2 -> V_29 [ V_24 ] . V_109 = 0 ;
}
V_58:
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
struct V_126 * V_127 = & V_2 -> V_14 [ V_15 ] ;
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
V_188 = F_55 ( 1 , ~ V_127 -> V_132 ) ;
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
int F_94 ( struct V_84 * V_85 , int V_24 , int V_200 ,
int V_201 )
{
struct V_1 * V_2 = F_88 ( V_85 ) ;
int V_182 ;
if ( V_24 >= V_2 -> V_12 )
return - V_99 ;
if ( ! V_2 -> V_202 )
return - V_99 ;
V_182 = F_91 ( V_2 ) ;
if ( V_182 != 10000 )
return - V_99 ;
if ( V_200 )
return - V_99 ;
if ( V_201 && ( ( V_201 <= 10 ) || ( V_201 > V_182 ) ) )
return - V_99 ;
V_2 -> V_190 = V_182 ;
V_2 -> V_29 [ V_24 ] . V_189 = V_201 ;
F_92 ( V_2 , V_24 ) ;
return 0 ;
}
int F_73 ( struct V_84 * V_85 , int V_24 , bool V_203 )
{
struct V_1 * V_2 = F_88 ( V_85 ) ;
int V_204 = V_24 >> 3 ;
int V_205 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_206 ;
V_2 -> V_29 [ V_24 ] . V_40 = V_203 ;
V_206 = F_19 ( V_4 , F_95 ( V_204 ) ) ;
V_206 &= ~ ( 1 << V_205 ) ;
V_206 |= ( V_203 << V_205 ) ;
F_6 ( V_4 , F_95 ( V_204 ) , V_206 ) ;
if ( V_2 -> V_29 [ V_24 ] . V_154 ) {
V_205 += V_207 ;
V_206 = F_19 ( V_4 , F_95 ( V_204 ) ) ;
V_206 &= ~ ( 1 << V_205 ) ;
V_206 |= ( V_203 << V_205 ) ;
F_6 ( V_4 , F_95 ( V_204 ) , V_206 ) ;
}
return 0 ;
}
int F_96 ( struct V_84 * V_85 ,
int V_24 , struct V_208 * V_209 )
{
struct V_1 * V_2 = F_88 ( V_85 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_99 ;
V_209 -> V_24 = V_24 ;
memcpy ( & V_209 -> V_18 , V_2 -> V_29 [ V_24 ] . V_112 , V_115 ) ;
V_209 -> V_201 = V_2 -> V_29 [ V_24 ] . V_189 ;
V_209 -> V_200 = 0 ;
V_209 -> V_145 = V_2 -> V_29 [ V_24 ] . V_108 ;
V_209 -> V_181 = V_2 -> V_29 [ V_24 ] . V_109 ;
V_209 -> V_210 = V_2 -> V_29 [ V_24 ] . V_40 ;
return 0 ;
}
