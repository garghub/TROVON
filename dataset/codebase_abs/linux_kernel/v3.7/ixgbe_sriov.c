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
V_2 -> V_32 =
F_8 ( V_2 -> V_13 ,
sizeof( struct V_33 ) , V_27 ) ;
if ( V_2 -> V_32 ) {
F_11 ( V_6 ) ;
memcpy ( & V_6 -> V_34 . V_35 , V_4 -> V_36 , sizeof( V_6 -> V_34 . V_35 ) ) ;
if ( ( V_2 -> V_6 . V_24 . type == V_37 ) &&
( V_2 -> V_13 < 16 ) ) {
V_2 -> V_38 . V_39 . V_40 = V_41 ;
V_2 -> V_38 . V_39 . V_42 = V_41 ;
} else if ( V_2 -> V_13 < 32 ) {
V_2 -> V_38 . V_39 . V_40 = 4 ;
V_2 -> V_38 . V_39 . V_42 = 4 ;
} else {
V_2 -> V_38 . V_39 . V_40 = 1 ;
V_2 -> V_38 . V_39 . V_42 = 1 ;
}
V_2 -> V_20 [ V_43 ] . V_22 = 1 ;
V_2 -> V_44 &= ~ ( V_45 |
V_46 ) ;
#ifdef F_12
if ( V_2 -> V_6 . V_24 . type == V_37 )
V_2 -> V_17 &= ~ ( V_47 |
V_48 ) ;
#endif
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ )
V_2 -> V_32 [ V_8 ] . V_49 = true ;
return;
}
F_6 ( V_16 , L_6
L_7 ) ;
F_13 ( V_2 ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_50 * V_12 = V_2 -> V_12 ;
struct V_50 * V_51 ;
int V_52 ;
switch ( V_2 -> V_6 . V_24 . type ) {
case V_37 :
V_52 = V_53 ;
break;
case V_54 :
V_52 = V_55 ;
break;
default:
return false ;
}
V_51 = F_15 ( V_56 , V_52 , NULL ) ;
while ( V_51 ) {
if ( V_51 -> V_57 && V_51 -> V_58 == V_12 ) {
if ( V_51 -> V_59 & V_60 )
return true ;
}
V_51 = F_15 ( V_56 , V_52 , V_51 ) ;
}
return false ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_61 ;
T_1 V_62 ;
V_2 -> V_13 = 0 ;
F_16 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
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
F_20 ( V_6 , V_63 , 0 ) ;
V_61 = F_21 ( V_6 , V_64 ) ;
V_61 &= ~ V_65 ;
F_20 ( V_6 , V_64 , V_61 ) ;
V_62 = F_21 ( V_6 , V_66 ) ;
V_62 &= ~ V_67 ;
F_20 ( V_6 , V_66 , V_62 ) ;
F_22 ( V_6 ) ;
if ( V_2 -> V_20 [ V_21 ] . V_22 == 1 )
V_2 -> V_17 &= ~ V_19 ;
V_2 -> V_20 [ V_21 ] . V_23 = 0 ;
F_23 ( 100 ) ;
V_2 -> V_17 &= ~ V_18 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_68 , T_2 * V_69 , T_1 V_30 )
{
struct V_33 * V_32 = & V_2 -> V_32 [ V_30 ] ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_8 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
V_68 = F_25 ( V_68 , V_73 ) ;
V_32 -> V_74 = V_68 ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
V_32 -> V_75 [ V_8 ] = V_69 [ V_8 ] ;
}
for ( V_8 = 0 ; V_8 < V_32 -> V_74 ; V_8 ++ ) {
V_71 = ( V_32 -> V_75 [ V_8 ] >> 5 ) & 0x7F ;
V_70 = V_32 -> V_75 [ V_8 ] & 0x1F ;
V_72 = F_21 ( V_6 , F_26 ( V_71 ) ) ;
V_72 |= ( 1 << V_70 ) ;
F_20 ( V_6 , F_26 ( V_71 ) , V_72 ) ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_76 * V_77 ;
struct V_9 * V_78 ;
F_28 (pos, &adapter->vf_mvs.l) {
V_78 = F_29 ( V_77 , struct V_9 , V_29 ) ;
if ( ! V_78 -> free )
V_6 -> V_24 . V_35 . V_79 ( V_6 , V_78 -> V_31 ,
V_78 -> V_80 ,
V_78 -> V_30 , V_81 ) ;
}
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_33 * V_32 ;
int V_8 , V_82 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
V_32 = & V_2 -> V_32 [ V_8 ] ;
for ( V_82 = 0 ; V_82 < V_32 -> V_74 ; V_82 ++ ) {
V_6 -> V_83 . V_84 ++ ;
V_71 = ( V_32 -> V_75 [ V_82 ] >> 5 ) & 0x7F ;
V_70 = V_32 -> V_75 [ V_82 ] & 0x1F ;
V_72 = F_21 ( V_6 , F_26 ( V_71 ) ) ;
V_72 |= ( 1 << V_70 ) ;
F_20 ( V_6 , F_26 ( V_71 ) , V_72 ) ;
}
}
F_27 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_85 , int V_86 ,
T_1 V_30 )
{
if ( ! V_86 && ! V_85 )
return 0 ;
return V_2 -> V_6 . V_24 . V_35 . V_87 ( & V_2 -> V_6 , V_86 , V_30 , ( bool ) V_85 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_1 * V_88 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_89 = V_88 [ 1 ] ;
T_1 V_90 ;
int V_91 = V_89 + V_92 + V_93 ;
if ( V_2 -> V_6 . V_24 . type != V_54 )
return;
if ( ( V_89 < 68 ) || ( V_91 > V_94 ) ) {
F_6 ( V_95 , L_9 , V_89 ) ;
return;
}
V_90 = ( F_21 ( V_6 , V_96 ) &
V_97 ) >> V_98 ;
if ( V_90 < V_89 ) {
V_90 = V_89 << V_98 ;
F_20 ( V_6 , V_96 , V_90 ) ;
}
F_7 ( V_6 , L_10 , V_89 ) ;
}
static void F_33 ( struct V_5 * V_6 , T_1 V_30 , bool V_99 )
{
T_1 V_100 = F_21 ( V_6 , F_34 ( V_30 ) ) ;
V_100 |= ( V_101 |
V_102 ) ;
if ( V_99 )
V_100 |= V_103 ;
else
V_100 &= ~ V_103 ;
F_20 ( V_6 , F_34 ( V_30 ) , V_100 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_86 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( V_86 )
F_20 ( V_6 , F_36 ( V_30 ) ,
( V_86 | V_104 ) ) ;
else
F_20 ( V_6 , F_36 ( V_30 ) , 0 ) ;
}
static inline void F_37 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_31 = V_6 -> V_24 . V_25 - ( V_30 + 1 ) ;
if ( V_2 -> V_32 [ V_30 ] . V_105 ) {
F_31 ( V_2 , true ,
V_2 -> V_32 [ V_30 ] . V_105 , V_30 ) ;
F_35 ( V_2 ,
( V_2 -> V_32 [ V_30 ] . V_105 |
( V_2 -> V_32 [ V_30 ] . V_106 <<
V_107 ) ) , V_30 ) ;
F_33 ( V_6 , V_30 , false ) ;
} else {
F_31 ( V_2 , true , 0 , V_30 ) ;
F_35 ( V_2 , 0 , V_30 ) ;
F_33 ( V_6 , V_30 , true ) ;
}
V_2 -> V_32 [ V_30 ] . V_74 = 0 ;
F_38 ( V_2 -> V_108 ) ;
V_6 -> V_24 . V_35 . V_109 ( V_6 , V_31 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
int V_30 , unsigned char * V_110 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_31 = V_6 -> V_24 . V_25 - ( V_30 + 1 ) ;
memcpy ( V_2 -> V_32 [ V_30 ] . V_111 , V_110 , 6 ) ;
V_6 -> V_24 . V_35 . V_79 ( V_6 , V_31 , V_110 , V_30 , V_81 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
int V_30 , int V_112 , unsigned char * V_110 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_76 * V_77 ;
struct V_9 * V_78 ;
if ( V_112 <= 1 ) {
F_28 (pos, &adapter->vf_mvs.l) {
V_78 = F_29 ( V_77 , struct V_9 , V_29 ) ;
if ( V_78 -> V_30 == V_30 ) {
V_78 -> V_30 = - 1 ;
V_78 -> free = true ;
V_78 -> V_113 = false ;
V_6 -> V_24 . V_35 . V_109 ( V_6 , V_78 -> V_31 ) ;
}
}
}
if ( ! V_112 )
return 0 ;
V_78 = NULL ;
F_28 (pos, &adapter->vf_mvs.l) {
V_78 = F_29 ( V_77 , struct V_9 , V_29 ) ;
if ( V_78 -> free )
break;
}
if ( ! V_78 || ! V_78 -> free )
return - V_114 ;
V_78 -> free = false ;
V_78 -> V_113 = true ;
V_78 -> V_30 = V_30 ;
memcpy ( V_78 -> V_80 , V_110 , V_115 ) ;
V_6 -> V_24 . V_35 . V_79 ( V_6 , V_78 -> V_31 , V_110 , V_30 , V_81 ) ;
return 0 ;
}
int F_41 ( struct V_50 * V_12 , unsigned int V_116 )
{
unsigned char V_117 [ 6 ] ;
struct V_1 * V_2 = F_42 ( V_12 ) ;
unsigned int V_118 = ( V_116 & 0x3f ) ;
bool V_119 = ( ( V_116 & 0x10000000U ) != 0 ) ;
if ( V_119 ) {
F_43 ( V_117 ) ;
F_7 ( V_16 , L_11 ,
V_118 , V_117 ) ;
memcpy ( V_2 -> V_32 [ V_118 ] . V_111 , V_117 , 6 ) ;
}
return 0 ;
}
static inline void F_44 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
T_1 V_121 , V_122 ;
V_122 = V_30 % 32 ;
V_121 = V_30 / 32 ;
V_120 = F_21 ( V_6 , F_45 ( V_121 ) ) ;
V_120 |= ( V_120 | ( 1 << V_122 ) ) ;
F_20 ( V_6 , F_45 ( V_121 ) , V_120 ) ;
V_120 = F_21 ( V_6 , F_46 ( V_121 ) ) ;
V_120 |= ( V_120 | ( 1 << V_122 ) ) ;
F_20 ( V_6 , F_46 ( V_121 ) , V_120 ) ;
V_120 = F_21 ( V_6 , F_47 ( V_121 ) ) ;
V_120 |= ( 1 << V_122 ) ;
F_20 ( V_6 , F_47 ( V_121 ) , V_120 ) ;
F_37 ( V_2 , V_30 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_123 = V_124 ;
T_1 V_88 [ V_124 ] ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_3 V_125 ;
int V_68 ;
T_2 * V_69 ;
int V_85 , V_86 , V_112 ;
T_4 * V_126 ;
V_125 = F_49 ( V_6 , V_88 , V_123 , V_30 ) ;
if ( V_125 ) {
F_50 ( L_12 ) ;
return V_125 ;
}
if ( V_88 [ 0 ] & ( V_127 | V_128 ) )
return V_125 ;
F_22 ( V_6 ) ;
if ( V_88 [ 0 ] == V_129 ) {
unsigned char * V_130 = V_2 -> V_32 [ V_30 ] . V_111 ;
V_126 = ( T_4 * ) ( & V_88 [ 1 ] ) ;
F_7 ( V_16 , L_13 , V_30 ) ;
V_2 -> V_32 [ V_30 ] . V_131 = false ;
F_44 ( V_2 , V_30 ) ;
V_2 -> V_32 [ V_30 ] . V_131 = true ;
if ( F_51 ( V_126 ) &&
! V_2 -> V_32 [ V_30 ] . V_132 )
F_39 ( V_2 , V_30 , V_130 ) ;
else
F_39 ( V_2 ,
V_30 , V_2 -> V_32 [ V_30 ] . V_111 ) ;
V_88 [ 0 ] = V_129 | V_127 ;
memcpy ( V_126 , V_130 , V_115 ) ;
V_88 [ 3 ] = V_6 -> V_24 . V_133 ;
F_52 ( V_6 , V_88 , V_134 , V_30 ) ;
return V_125 ;
}
if ( ! V_2 -> V_32 [ V_30 ] . V_131 ) {
V_88 [ 0 ] |= V_128 ;
F_52 ( V_6 , V_88 , 1 , V_30 ) ;
return V_125 ;
}
switch ( ( V_88 [ 0 ] & 0xFFFF ) ) {
case V_135 :
V_126 = ( ( T_4 * ) ( & V_88 [ 1 ] ) ) ;
if ( F_51 ( V_126 ) &&
! V_2 -> V_32 [ V_30 ] . V_132 ) {
F_39 ( V_2 , V_30 , V_126 ) ;
} else if ( memcmp ( V_2 -> V_32 [ V_30 ] . V_111 ,
V_126 , V_115 ) ) {
F_53 ( V_95 , L_14
L_15
L_16 , V_30 ) ;
V_125 = - 1 ;
}
break;
case V_136 :
V_68 = ( V_88 [ 0 ] & V_137 )
>> V_138 ;
V_69 = ( T_2 * ) & V_88 [ 1 ] ;
V_125 = F_24 ( V_2 , V_68 ,
V_69 , V_30 ) ;
break;
case V_139 :
F_32 ( V_2 , V_88 ) ;
break;
case V_140 :
V_85 = ( V_88 [ 0 ] & V_137 )
>> V_138 ;
V_86 = ( V_88 [ 1 ] & V_141 ) ;
if ( V_2 -> V_32 [ V_30 ] . V_105 ) {
F_53 ( V_95 , L_14
L_17
L_18 ,
V_30 ) ;
V_125 = - 1 ;
} else {
if ( V_85 )
V_2 -> V_32 [ V_30 ] . V_142 ++ ;
else if ( V_2 -> V_32 [ V_30 ] . V_142 )
V_2 -> V_32 [ V_30 ] . V_142 -- ;
V_125 = F_31 ( V_2 , V_85 , V_86 , V_30 ) ;
if ( ! V_125 && V_2 -> V_32 [ V_30 ] . V_49 )
V_6 -> V_24 . V_35 . V_143 ( V_6 , true , V_30 ) ;
}
break;
case V_144 :
V_112 = ( V_88 [ 0 ] & V_137 ) >>
V_138 ;
if ( V_2 -> V_32 [ V_30 ] . V_132 && V_112 > 0 ) {
F_53 ( V_95 , L_19
L_20 , V_30 ) ;
V_125 = - 1 ;
break;
}
if ( V_112 > 0 && V_2 -> V_32 [ V_30 ] . V_49 )
F_54 ( V_2 -> V_108 , V_30 , false ) ;
V_125 = F_40 ( V_2 , V_30 , V_112 ,
( unsigned char * ) ( & V_88 [ 1 ] ) ) ;
if ( V_125 == - V_114 )
F_53 ( V_95 , L_21
L_22 , V_30 ) ;
break;
default:
F_6 ( V_95 , L_23 , V_88 [ 0 ] ) ;
V_125 = V_145 ;
break;
}
if ( V_125 )
V_88 [ 0 ] |= V_128 ;
else
V_88 [ 0 ] |= V_127 ;
V_88 [ 0 ] |= V_146 ;
F_52 ( V_6 , V_88 , 1 , V_30 ) ;
return V_125 ;
}
static void F_55 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_147 = V_128 ;
if ( ! V_2 -> V_32 [ V_30 ] . V_131 )
F_52 ( V_6 , & V_147 , 1 , V_30 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_13 ; V_30 ++ ) {
if ( ! F_57 ( V_6 , V_30 ) )
F_37 ( V_2 , V_30 ) ;
if ( ! F_58 ( V_6 , V_30 ) )
F_48 ( V_2 , V_30 ) ;
if ( ! F_59 ( V_6 , V_30 ) )
F_55 ( V_2 , V_30 ) ;
}
}
void F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_20 ( V_6 , F_45 ( 0 ) , 0 ) ;
F_20 ( V_6 , F_45 ( 1 ) , 0 ) ;
F_20 ( V_6 , F_46 ( 0 ) , 0 ) ;
F_20 ( V_6 , F_46 ( 1 ) , 0 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_148 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
V_148 = V_149 ;
if ( V_2 -> V_32 [ V_8 ] . V_131 )
V_148 |= V_146 ;
F_52 ( V_6 , & V_148 , 1 , V_8 ) ;
}
}
int F_62 ( struct V_150 * V_108 , int V_30 , T_4 * V_24 )
{
struct V_1 * V_2 = F_63 ( V_108 ) ;
if ( ! F_51 ( V_24 ) || ( V_30 >= V_2 -> V_13 ) )
return - V_151 ;
V_2 -> V_32 [ V_30 ] . V_132 = true ;
F_64 ( & V_2 -> V_12 -> V_14 , L_24 , V_24 , V_30 ) ;
F_64 ( & V_2 -> V_12 -> V_14 , L_25
L_26 ) ;
if ( F_65 ( V_152 , & V_2 -> V_153 ) ) {
F_3 ( & V_2 -> V_12 -> V_14 , L_27
L_28 ) ;
F_3 ( & V_2 -> V_12 -> V_14 , L_29
L_30 ) ;
}
return F_39 ( V_2 , V_30 , V_24 ) ;
}
int F_66 ( struct V_150 * V_108 , int V_30 , T_2 V_154 , T_4 V_155 )
{
int V_15 = 0 ;
struct V_1 * V_2 = F_63 ( V_108 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ( V_30 >= V_2 -> V_13 ) || ( V_154 > 4095 ) || ( V_155 > 7 ) )
return - V_151 ;
if ( V_154 || V_155 ) {
V_15 = F_31 ( V_2 , true , V_154 , V_30 ) ;
if ( V_15 )
goto V_156;
F_35 ( V_2 , V_154 | ( V_155 << V_107 ) , V_30 ) ;
F_33 ( V_6 , V_30 , false ) ;
if ( V_2 -> V_32 [ V_30 ] . V_49 )
V_6 -> V_24 . V_35 . V_143 ( V_6 , true , V_30 ) ;
V_2 -> V_32 [ V_30 ] . V_142 ++ ;
V_2 -> V_32 [ V_30 ] . V_105 = V_154 ;
V_2 -> V_32 [ V_30 ] . V_106 = V_155 ;
F_64 ( & V_2 -> V_12 -> V_14 ,
L_31 , V_154 , V_155 , V_30 ) ;
if ( F_65 ( V_152 , & V_2 -> V_153 ) ) {
F_3 ( & V_2 -> V_12 -> V_14 ,
L_32
L_28 ) ;
F_3 ( & V_2 -> V_12 -> V_14 ,
L_29
L_30 ) ;
}
} else {
V_15 = F_31 ( V_2 , false ,
V_2 -> V_32 [ V_30 ] . V_105 , V_30 ) ;
F_35 ( V_2 , V_154 , V_30 ) ;
F_33 ( V_6 , V_30 , true ) ;
V_6 -> V_24 . V_35 . V_143 ( V_6 , false , V_30 ) ;
if ( V_2 -> V_32 [ V_30 ] . V_142 )
V_2 -> V_32 [ V_30 ] . V_142 -- ;
V_2 -> V_32 [ V_30 ] . V_105 = 0 ;
V_2 -> V_32 [ V_30 ] . V_106 = 0 ;
}
V_156:
return V_15 ;
}
static int F_67 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_157 ) {
case V_158 :
return 100 ;
case V_159 :
return 1000 ;
case V_160 :
return 10000 ;
default:
return 0 ;
}
}
static void F_68 ( struct V_1 * V_2 , int V_30 )
{
struct V_161 * V_162 = & V_2 -> V_20 [ V_21 ] ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_163 = 0 ;
T_2 V_164 , V_165 ;
T_2 V_166 = V_2 -> V_32 [ V_30 ] . V_166 ;
if ( V_166 ) {
V_163 = V_2 -> V_167 ;
V_163 <<= V_168 ;
V_163 /= V_166 ;
V_163 &= V_169 |
V_170 ;
V_163 |= V_171 ;
}
switch ( V_6 -> V_24 . type ) {
case V_37 :
F_20 ( V_6 , V_172 , 0x4 ) ;
break;
case V_54 :
F_20 ( V_6 , V_172 , 0x14 ) ;
break;
default:
break;
}
V_165 = F_69 ( 1 , ~ V_162 -> V_173 ) ;
for ( V_164 = 0 ; V_164 < V_165 ; V_164 ++ ) {
unsigned int V_174 = ( V_30 * V_165 ) + V_164 ;
F_20 ( V_6 , V_175 , V_174 ) ;
F_20 ( V_6 , V_176 , V_163 ) ;
}
}
void F_70 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! V_2 -> V_167 )
return;
if ( F_67 ( V_2 ) != V_2 -> V_167 ) {
V_2 -> V_167 = 0 ;
F_64 ( & V_2 -> V_12 -> V_14 ,
L_33 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; V_8 ++ ) {
if ( ! V_2 -> V_167 )
V_2 -> V_32 [ V_8 ] . V_166 = 0 ;
F_68 ( V_2 , V_8 ) ;
}
}
int F_71 ( struct V_150 * V_108 , int V_30 , int V_166 )
{
struct V_1 * V_2 = F_63 ( V_108 ) ;
int V_157 ;
if ( V_30 >= V_2 -> V_13 )
return - V_151 ;
if ( ! V_2 -> V_177 )
return - V_151 ;
V_157 = F_67 ( V_2 ) ;
if ( V_157 != 10000 )
return - V_151 ;
if ( V_166 && ( ( V_166 <= 10 ) || ( V_166 > V_157 ) ) )
return - V_151 ;
V_2 -> V_167 = V_157 ;
V_2 -> V_32 [ V_30 ] . V_166 = V_166 ;
F_68 ( V_2 , V_30 ) ;
return 0 ;
}
int F_54 ( struct V_150 * V_108 , int V_30 , bool V_178 )
{
struct V_1 * V_2 = F_63 ( V_108 ) ;
int V_179 = V_30 >> 3 ;
int V_180 = V_30 % 8 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_181 ;
V_2 -> V_32 [ V_30 ] . V_49 = V_178 ;
V_181 = F_21 ( V_6 , F_72 ( V_179 ) ) ;
V_181 &= ~ ( 1 << V_180 ) ;
V_181 |= ( V_178 << V_180 ) ;
F_20 ( V_6 , F_72 ( V_179 ) , V_181 ) ;
if ( V_2 -> V_32 [ V_30 ] . V_142 ) {
V_180 += V_182 ;
V_181 = F_21 ( V_6 , F_72 ( V_179 ) ) ;
V_181 &= ~ ( 1 << V_180 ) ;
V_181 |= ( V_178 << V_180 ) ;
F_20 ( V_6 , F_72 ( V_179 ) , V_181 ) ;
}
return 0 ;
}
int F_73 ( struct V_150 * V_108 ,
int V_30 , struct V_183 * V_184 )
{
struct V_1 * V_2 = F_63 ( V_108 ) ;
if ( V_30 >= V_2 -> V_13 )
return - V_151 ;
V_184 -> V_30 = V_30 ;
memcpy ( & V_184 -> V_24 , V_2 -> V_32 [ V_30 ] . V_111 , V_115 ) ;
V_184 -> V_166 = V_2 -> V_32 [ V_30 ] . V_166 ;
V_184 -> V_154 = V_2 -> V_32 [ V_30 ] . V_105 ;
V_184 -> V_155 = V_2 -> V_32 [ V_30 ] . V_106 ;
V_184 -> V_185 = V_2 -> V_32 [ V_30 ] . V_49 ;
return 0 ;
}
