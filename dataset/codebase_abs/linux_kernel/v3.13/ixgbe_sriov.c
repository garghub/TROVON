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
V_8 -> V_25 = V_4 -> V_18 . V_19 -
( V_6 + V_2 -> V_12 + 1 ) ;
F_5 ( & V_8 -> V_23 , & V_2 -> V_22 . V_23 ) ;
V_8 ++ ;
}
}
F_6 ( V_4 , V_26 , V_27 ) ;
V_2 -> V_28 |= V_29 ;
V_2 -> V_30 =
F_3 ( V_2 -> V_12 ,
sizeof( struct V_31 ) , V_21 ) ;
if ( V_2 -> V_30 ) {
if ( ( V_2 -> V_4 . V_18 . type == V_32 ) &&
( V_2 -> V_12 < 16 ) ) {
V_2 -> V_33 . V_34 . V_35 = V_36 ;
V_2 -> V_33 . V_34 . V_37 = V_36 ;
} else if ( V_2 -> V_12 < 32 ) {
V_2 -> V_33 . V_34 . V_35 = 4 ;
V_2 -> V_33 . V_34 . V_37 = 4 ;
} else {
V_2 -> V_33 . V_34 . V_35 = 1 ;
V_2 -> V_33 . V_34 . V_37 = 1 ;
}
V_2 -> V_14 [ V_38 ] . V_16 = 1 ;
V_2 -> V_28 &= ~ ( V_39 |
V_40 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
V_2 -> V_30 [ V_6 ] . V_41 = true ;
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
V_2 -> V_12 = F_10 (unsigned int, adapter->num_vfs, 63 ) ;
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
F_14 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
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
V_49 = F_10 ( int , V_56 , F_21 () ) ;
} else {
V_49 = F_10 ( int , V_57 , F_21 () ) ;
}
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_2 -> V_14 [ V_38 ] . V_16 = V_49 ;
F_22 ( 100 ) ;
return 0 ;
}
static int F_23 ( struct V_58 * V_45 , int V_12 )
{
#ifdef F_15
struct V_1 * V_2 = F_24 ( V_45 ) ;
int V_46 = 0 ;
int V_6 ;
int V_43 = F_8 ( V_45 ) ;
if ( V_43 && V_43 != V_12 )
V_46 = F_13 ( V_2 ) ;
else if ( V_43 && V_43 == V_12 )
goto V_59;
if ( V_46 )
goto V_60;
if ( V_12 > 63 ) {
V_46 = - V_50 ;
goto V_60;
}
V_2 -> V_12 = V_12 ;
V_46 = F_1 ( V_2 ) ;
if ( V_46 )
goto V_60;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_25 ( V_45 , ( V_6 | 0x10000000 ) ) ;
V_46 = F_11 ( V_45 , V_12 ) ;
if ( V_46 ) {
F_17 ( L_3 , V_46 ) ;
goto V_60;
}
F_26 ( V_2 ) ;
V_59:
return V_12 ;
V_60:
return V_46 ;
#endif
return 0 ;
}
static int F_27 ( struct V_58 * V_45 )
{
struct V_1 * V_2 = F_24 ( V_45 ) ;
int V_46 ;
#ifdef F_15
T_1 V_61 = V_2 -> V_9 ;
#endif
V_46 = F_13 ( V_2 ) ;
#ifdef F_15
if ( ! V_46 && V_61 != V_2 -> V_9 )
F_26 ( V_2 ) ;
#endif
return V_46 ;
}
int F_28 ( struct V_58 * V_45 , int V_12 )
{
if ( V_12 == 0 )
return F_27 ( V_45 ) ;
else
return F_23 ( V_45 , V_12 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
int V_63 = ( V_62 [ 0 ] & V_64 )
>> V_65 ;
T_2 * V_66 = ( T_2 * ) & V_62 [ 1 ] ;
struct V_31 * V_30 = & V_2 -> V_30 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
V_63 = F_30 ( V_63 , V_70 ) ;
V_30 -> V_71 = V_63 ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 ++ ) {
V_30 -> V_72 [ V_6 ] = V_66 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_30 -> V_71 ; V_6 ++ ) {
V_68 = ( V_30 -> V_72 [ V_6 ] >> 5 ) & 0x7F ;
V_67 = V_30 -> V_72 [ V_6 ] & 0x1F ;
V_69 = F_19 ( V_4 , F_31 ( V_68 ) ) ;
V_69 |= ( 1 << V_67 ) ;
F_6 ( V_4 , F_31 ( V_68 ) , V_69 ) ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_73 * V_74 ;
struct V_7 * V_75 ;
F_33 (pos, &adapter->vf_mvs.l) {
V_75 = F_34 ( V_74 , struct V_7 , V_23 ) ;
if ( ! V_75 -> free )
V_4 -> V_18 . V_76 . V_77 ( V_4 , V_75 -> V_25 ,
V_75 -> V_78 ,
V_75 -> V_24 , V_79 ) ;
}
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_31 * V_30 ;
int V_6 , V_80 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_30 = & V_2 -> V_30 [ V_6 ] ;
for ( V_80 = 0 ; V_80 < V_30 -> V_71 ; V_80 ++ ) {
V_4 -> V_81 . V_82 ++ ;
V_68 = ( V_30 -> V_72 [ V_80 ] >> 5 ) & 0x7F ;
V_67 = V_30 -> V_72 [ V_80 ] & 0x1F ;
V_69 = F_19 ( V_4 , F_31 ( V_68 ) ) ;
V_69 |= ( 1 << V_67 ) ;
F_6 ( V_4 , F_31 ( V_68 ) , V_69 ) ;
}
}
F_32 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_83 , int V_84 ,
T_1 V_24 )
{
if ( ! V_84 && ! V_83 )
return 0 ;
return V_2 -> V_4 . V_18 . V_76 . V_85 ( & V_2 -> V_4 , V_84 , V_24 , ( bool ) V_83 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 , T_1 * V_62 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_86 = V_62 [ 1 ] ;
T_1 V_87 ;
if ( V_2 -> V_4 . V_18 . type == V_32 ) {
struct V_88 * V_45 = V_2 -> V_89 ;
int V_90 = V_45 -> V_91 + V_92 ;
T_1 V_93 , V_94 , V_95 ;
T_3 V_46 = 0 ;
#ifdef F_38
if ( V_45 -> V_96 & V_97 )
V_90 = F_39 ( int , V_90 ,
V_98 ) ;
#endif
switch ( V_2 -> V_30 [ V_24 ] . V_99 ) {
case V_100 :
if ( V_90 > V_101 )
break;
default:
if ( ( V_90 > V_101 ) ||
( V_86 > ( V_101 + V_102 ) ) )
V_46 = - V_103 ;
break;
}
V_94 = V_24 % 32 ;
V_93 = V_24 / 32 ;
V_95 = F_19 ( V_4 , F_40 ( V_93 ) ) ;
if ( V_46 )
V_95 &= ~ ( 1 << V_94 ) ;
else
V_95 |= 1 << V_94 ;
F_6 ( V_4 , F_40 ( V_93 ) , V_95 ) ;
if ( V_46 ) {
F_12 ( V_104 , L_7 , V_86 ) ;
return V_46 ;
}
}
if ( V_86 > V_105 ) {
F_12 ( V_104 , L_7 , V_86 ) ;
return - V_103 ;
}
V_87 = F_19 ( V_4 , V_106 ) ;
V_87 &= V_107 ;
V_87 >>= V_108 ;
if ( V_87 < V_86 ) {
V_87 = V_86 << V_108 ;
F_6 ( V_4 , V_106 , V_87 ) ;
}
F_2 ( V_4 , L_8 , V_86 ) ;
return 0 ;
}
static void F_41 ( struct V_3 * V_4 , T_1 V_24 , bool V_109 )
{
T_1 V_110 = F_19 ( V_4 , F_42 ( V_24 ) ) ;
V_110 |= ( V_111 |
V_112 ) ;
if ( V_109 )
V_110 |= V_113 ;
else
V_110 &= ~ V_113 ;
F_6 ( V_4 , F_42 ( V_24 ) , V_110 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_44 ( V_24 ) , 0 ) ;
}
static inline void F_45 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_31 * V_30 = & V_2 -> V_30 [ V_24 ] ;
int V_25 = V_4 -> V_18 . V_19 - ( V_24 + 1 ) ;
T_4 V_34 = F_46 ( V_2 -> V_89 ) ;
F_36 ( V_2 , true , V_30 -> V_114 , V_24 ) ;
F_41 ( V_4 , V_24 , ! V_30 -> V_114 ) ;
if ( ! V_30 -> V_114 && ! V_30 -> V_115 && ! V_34 ) {
F_43 ( V_2 , V_24 ) ;
} else {
if ( V_30 -> V_115 || ! V_34 )
F_47 ( V_2 , V_30 -> V_114 ,
V_30 -> V_115 , V_24 ) ;
else
F_47 ( V_2 , V_30 -> V_114 ,
V_2 -> V_116 , V_24 ) ;
if ( V_30 -> V_41 )
V_4 -> V_18 . V_76 . V_117 ( V_4 , true , V_24 ) ;
}
V_2 -> V_30 [ V_24 ] . V_71 = 0 ;
F_48 ( V_2 -> V_89 ) ;
V_4 -> V_18 . V_76 . V_118 ( V_4 , V_25 ) ;
V_2 -> V_30 [ V_24 ] . V_99 = V_119 ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_120 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_25 = V_4 -> V_18 . V_19 - ( V_24 + 1 ) ;
memcpy ( V_2 -> V_30 [ V_24 ] . V_121 , V_120 , V_122 ) ;
V_4 -> V_18 . V_76 . V_77 ( V_4 , V_25 , V_120 , V_24 , V_79 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_24 , int V_123 , unsigned char * V_120 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_73 * V_74 ;
struct V_7 * V_75 ;
if ( V_123 <= 1 ) {
F_33 (pos, &adapter->vf_mvs.l) {
V_75 = F_34 ( V_74 , struct V_7 , V_23 ) ;
if ( V_75 -> V_24 == V_24 ) {
V_75 -> V_24 = - 1 ;
V_75 -> free = true ;
V_75 -> V_124 = false ;
V_4 -> V_18 . V_76 . V_118 ( V_4 , V_75 -> V_25 ) ;
}
}
}
if ( ! V_123 )
return 0 ;
V_75 = NULL ;
F_33 (pos, &adapter->vf_mvs.l) {
V_75 = F_34 ( V_74 , struct V_7 , V_23 ) ;
if ( V_75 -> free )
break;
}
if ( ! V_75 || ! V_75 -> free )
return - V_125 ;
V_75 -> free = false ;
V_75 -> V_124 = true ;
V_75 -> V_24 = V_24 ;
memcpy ( V_75 -> V_78 , V_120 , V_122 ) ;
V_4 -> V_18 . V_76 . V_77 ( V_4 , V_75 -> V_25 , V_120 , V_24 , V_79 ) ;
return 0 ;
}
int F_25 ( struct V_58 * V_44 , unsigned int V_126 )
{
struct V_1 * V_2 = F_24 ( V_44 ) ;
unsigned int V_127 = ( V_126 & 0x3f ) ;
bool V_128 = ( ( V_126 & 0x10000000U ) != 0 ) ;
if ( V_128 )
F_51 ( V_2 -> V_30 [ V_127 ] . V_121 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_129 = V_2 -> V_30 [ V_24 ] . V_121 ;
T_1 V_130 , V_93 , V_94 ;
T_1 V_62 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 * V_131 = ( T_4 * ) ( & V_62 [ 1 ] ) ;
F_2 ( V_11 , L_9 , V_24 ) ;
F_45 ( V_2 , V_24 ) ;
if ( ! F_53 ( V_129 ) )
F_49 ( V_2 , V_24 , V_129 ) ;
V_94 = V_24 % 32 ;
V_93 = V_24 / 32 ;
V_130 = F_19 ( V_4 , F_54 ( V_93 ) ) ;
V_130 |= 1 << V_94 ;
F_6 ( V_4 , F_54 ( V_93 ) , V_130 ) ;
V_130 = F_19 ( V_4 , F_40 ( V_93 ) ) ;
V_130 |= 1 << V_94 ;
if ( V_2 -> V_4 . V_18 . type == V_32 ) {
struct V_88 * V_45 = V_2 -> V_89 ;
int V_90 = V_45 -> V_91 + V_92 ;
#ifdef F_38
if ( V_45 -> V_96 & V_97 )
V_90 = F_39 ( int , V_90 ,
V_98 ) ;
#endif
if ( V_90 > V_101 )
V_130 &= ~ ( 1 << V_94 ) ;
}
F_6 ( V_4 , F_40 ( V_93 ) , V_130 ) ;
V_2 -> V_30 [ V_24 ] . V_132 = true ;
V_130 = F_19 ( V_4 , F_55 ( V_93 ) ) ;
V_130 |= ( 1 << V_94 ) ;
F_6 ( V_4 , F_55 ( V_93 ) , V_130 ) ;
V_62 [ 0 ] = V_133 ;
if ( ! F_53 ( V_129 ) ) {
V_62 [ 0 ] |= V_134 ;
memcpy ( V_131 , V_129 , V_122 ) ;
} else {
V_62 [ 0 ] |= V_135 ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_10 ,
V_24 ) ;
}
V_62 [ 3 ] = V_4 -> V_18 . V_136 ;
F_56 ( V_4 , V_62 , V_137 , V_24 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_4 * V_138 = ( ( T_4 * ) ( & V_62 [ 1 ] ) ) ;
if ( ! F_58 ( V_138 ) ) {
F_59 ( V_104 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_30 [ V_24 ] . V_139 &&
memcmp ( V_2 -> V_30 [ V_24 ] . V_121 , V_138 ,
V_122 ) ) {
F_59 ( V_104 ,
L_12
L_13 ,
V_24 ) ;
return - 1 ;
}
return F_49 ( V_2 , V_24 , V_138 ) < 0 ;
}
static int F_60 ( struct V_3 * V_4 , T_1 V_140 )
{
T_1 V_141 ;
T_3 V_142 ;
if ( V_140 == 0 )
return 0 ;
for ( V_142 = 1 ; V_142 < V_143 ; V_142 ++ ) {
V_141 = F_19 ( V_4 , F_61 ( V_142 ) ) ;
if ( ( V_141 & V_144 ) == V_140 )
break;
}
if ( V_142 >= V_143 )
V_142 = - 1 ;
return V_142 ;
}
static int F_62 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_83 = ( V_62 [ 0 ] & V_64 ) >> V_65 ;
int V_84 = ( V_62 [ 1 ] & V_145 ) ;
int V_46 ;
T_3 V_146 ;
T_1 V_141 ;
T_1 V_147 ;
T_4 V_148 = F_46 ( V_2 -> V_89 ) ;
if ( V_2 -> V_30 [ V_24 ] . V_114 || V_148 ) {
F_59 ( V_104 ,
L_14
L_13 ,
V_24 ) ;
return - 1 ;
}
if ( V_83 )
V_2 -> V_30 [ V_24 ] . V_149 ++ ;
else if ( V_2 -> V_30 [ V_24 ] . V_149 )
V_2 -> V_30 [ V_24 ] . V_149 -- ;
if ( V_83 && V_2 -> V_89 -> V_9 & V_150 )
V_46 = F_36 ( V_2 , V_83 , V_84 , F_63 ( 0 ) ) ;
V_46 = F_36 ( V_2 , V_83 , V_84 , V_24 ) ;
if ( ! V_46 && V_2 -> V_30 [ V_24 ] . V_41 )
V_4 -> V_18 . V_76 . V_117 ( V_4 , true , V_24 ) ;
if ( ! V_83 && V_2 -> V_89 -> V_9 & V_150 ) {
V_146 = F_60 ( V_4 , V_84 ) ;
if ( V_146 < 0 )
goto V_59;
V_141 = F_19 ( V_4 , F_61 ( V_146 ) ) ;
if ( F_63 ( 0 ) < 32 ) {
V_147 = F_19 ( V_4 , F_64 ( V_146 * 2 ) ) ;
V_147 &= ~ ( 1 << F_63 ( 0 ) ) ;
V_147 |= F_19 ( V_4 ,
F_64 ( V_146 * 2 ) + 1 ) ;
} else {
V_147 = F_19 ( V_4 ,
F_64 ( V_146 * 2 ) + 1 ) ;
V_147 &= ~ ( 1 << ( F_63 ( 0 ) - 32 ) ) ;
V_147 |= F_19 ( V_4 , F_64 ( V_146 * 2 ) ) ;
}
if ( ( V_141 & V_144 ) == V_84 &&
! F_65 ( V_84 , V_2 -> V_151 ) && ! V_147 )
F_36 ( V_2 , V_83 , V_84 , F_63 ( 0 ) ) ;
}
V_59:
return V_46 ;
}
static int F_66 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
T_4 * V_138 = ( ( T_4 * ) ( & V_62 [ 1 ] ) ) ;
int V_123 = ( V_62 [ 0 ] & V_64 ) >>
V_65 ;
int V_46 ;
if ( V_2 -> V_30 [ V_24 ] . V_139 && V_123 > 0 ) {
F_59 ( V_104 ,
L_15 ,
V_24 ) ;
return - 1 ;
}
if ( V_123 ) {
if ( ! F_58 ( V_138 ) ) {
F_59 ( V_104 , L_11 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_30 [ V_24 ] . V_41 )
F_67 ( V_2 -> V_89 , V_24 , false ) ;
}
V_46 = F_50 ( V_2 , V_24 , V_123 , V_138 ) ;
if ( V_46 == - V_125 )
F_59 ( V_104 ,
L_16 ,
V_24 ) ;
return V_46 < 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
int V_152 = V_62 [ 1 ] ;
switch ( V_152 ) {
case V_119 :
case V_100 :
V_2 -> V_30 [ V_24 ] . V_99 = V_152 ;
return 0 ;
default:
break;
}
F_2 ( V_104 , L_17 , V_24 , V_152 ) ;
return - 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 V_24 )
{
struct V_88 * V_45 = V_2 -> V_89 ;
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_155 = 0 ;
T_4 V_34 = F_46 ( V_45 ) ;
switch ( V_2 -> V_30 [ V_24 ] . V_99 ) {
case V_156 :
case V_100 :
break;
default:
return - 1 ;
}
V_62 [ V_157 ] = F_70 ( 1 , ~ V_154 -> V_158 ) ;
V_62 [ V_159 ] = F_70 ( 1 , ~ V_154 -> V_158 ) ;
if ( V_34 > 1 )
V_155 = F_71 ( V_45 , V_2 -> V_116 ) ;
if ( V_34 )
V_62 [ V_160 ] = V_34 ;
else if ( V_2 -> V_30 [ V_24 ] . V_114 || V_2 -> V_30 [ V_24 ] . V_115 )
V_62 [ V_160 ] = 1 ;
else
V_62 [ V_160 ] = 0 ;
V_62 [ V_161 ] = V_155 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_162 = V_163 ;
T_1 V_62 [ V_163 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_164 ;
V_164 = F_73 ( V_4 , V_62 , V_162 , V_24 ) ;
if ( V_164 ) {
F_74 ( L_18 ) ;
return V_164 ;
}
if ( V_62 [ 0 ] & ( V_134 | V_135 ) )
return V_164 ;
F_20 ( V_4 ) ;
if ( V_62 [ 0 ] == V_133 )
return F_52 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_30 [ V_24 ] . V_132 ) {
V_62 [ 0 ] |= V_135 ;
F_56 ( V_4 , V_62 , 1 , V_24 ) ;
return V_164 ;
}
switch ( ( V_62 [ 0 ] & 0xFFFF ) ) {
case V_165 :
V_164 = F_57 ( V_2 , V_62 , V_24 ) ;
break;
case V_166 :
V_164 = F_29 ( V_2 , V_62 , V_24 ) ;
break;
case V_167 :
V_164 = F_62 ( V_2 , V_62 , V_24 ) ;
break;
case V_168 :
V_164 = F_37 ( V_2 , V_62 , V_24 ) ;
break;
case V_169 :
V_164 = F_66 ( V_2 , V_62 , V_24 ) ;
break;
case V_170 :
V_164 = F_68 ( V_2 , V_62 , V_24 ) ;
break;
case V_171 :
V_164 = F_69 ( V_2 , V_62 , V_24 ) ;
break;
default:
F_12 ( V_104 , L_19 , V_62 [ 0 ] ) ;
V_164 = V_172 ;
break;
}
if ( V_164 )
V_62 [ 0 ] |= V_135 ;
else
V_62 [ 0 ] |= V_134 ;
V_62 [ 0 ] |= V_173 ;
F_56 ( V_4 , V_62 , V_162 , V_24 ) ;
return V_164 ;
}
static void F_75 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_174 = V_135 ;
if ( ! V_2 -> V_30 [ V_24 ] . V_132 )
F_56 ( V_4 , & V_174 , 1 , V_24 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_77 ( V_4 , V_24 ) )
F_45 ( V_2 , V_24 ) ;
if ( ! F_78 ( V_4 , V_24 ) )
F_72 ( V_2 , V_24 ) ;
if ( ! F_79 ( V_4 , V_24 ) )
F_75 ( V_2 , V_24 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_54 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_54 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_40 ( 1 ) , 0 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_175 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_175 = V_176 ;
if ( V_2 -> V_30 [ V_6 ] . V_132 )
V_175 |= V_173 ;
F_56 ( V_4 , & V_175 , 1 , V_6 ) ;
}
}
int F_82 ( struct V_88 * V_89 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_83 ( V_89 ) ;
if ( ! F_58 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_103 ;
V_2 -> V_30 [ V_24 ] . V_139 = true ;
F_84 ( & V_2 -> V_44 -> V_45 , L_20 , V_18 , V_24 ) ;
F_84 ( & V_2 -> V_44 -> V_45 , L_21
L_22 ) ;
if ( F_65 ( V_177 , & V_2 -> V_178 ) ) {
F_9 ( & V_2 -> V_44 -> V_45 , L_23
L_24 ) ;
F_9 ( & V_2 -> V_44 -> V_45 , L_25
L_26 ) ;
}
return F_49 ( V_2 , V_24 , V_18 ) ;
}
int F_85 ( struct V_88 * V_89 , int V_24 , T_2 V_140 , T_4 V_179 )
{
int V_46 = 0 ;
struct V_1 * V_2 = F_83 ( V_89 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_140 > 4095 ) || ( V_179 > 7 ) )
return - V_103 ;
if ( V_140 || V_179 ) {
if ( V_2 -> V_30 [ V_24 ] . V_114 )
V_46 = F_36 ( V_2 , false ,
V_2 -> V_30 [ V_24 ] . V_114 ,
V_24 ) ;
if ( V_46 )
goto V_59;
V_46 = F_36 ( V_2 , true , V_140 , V_24 ) ;
if ( V_46 )
goto V_59;
F_47 ( V_2 , V_140 , V_179 , V_24 ) ;
F_41 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_30 [ V_24 ] . V_41 )
V_4 -> V_18 . V_76 . V_117 ( V_4 , true , V_24 ) ;
V_2 -> V_30 [ V_24 ] . V_149 ++ ;
V_2 -> V_30 [ V_24 ] . V_114 = V_140 ;
V_2 -> V_30 [ V_24 ] . V_115 = V_179 ;
F_84 ( & V_2 -> V_44 -> V_45 ,
L_27 , V_140 , V_179 , V_24 ) ;
if ( F_65 ( V_177 , & V_2 -> V_178 ) ) {
F_9 ( & V_2 -> V_44 -> V_45 ,
L_28
L_24 ) ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_25
L_26 ) ;
}
} else {
V_46 = F_36 ( V_2 , false ,
V_2 -> V_30 [ V_24 ] . V_114 , V_24 ) ;
F_43 ( V_2 , V_24 ) ;
F_41 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_76 . V_117 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_30 [ V_24 ] . V_149 )
V_2 -> V_30 [ V_24 ] . V_149 -- ;
V_2 -> V_30 [ V_24 ] . V_114 = 0 ;
V_2 -> V_30 [ V_24 ] . V_115 = 0 ;
}
V_59:
return V_46 ;
}
static int F_86 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_180 ) {
case V_181 :
return 100 ;
case V_182 :
return 1000 ;
case V_183 :
return 10000 ;
default:
return 0 ;
}
}
static void F_87 ( struct V_1 * V_2 , int V_24 )
{
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_184 = 0 ;
T_2 V_185 , V_186 ;
T_2 V_187 = V_2 -> V_30 [ V_24 ] . V_187 ;
if ( V_187 ) {
V_184 = V_2 -> V_188 ;
V_184 <<= V_189 ;
V_184 /= V_187 ;
V_184 &= V_190 |
V_191 ;
V_184 |= V_192 ;
}
switch ( V_4 -> V_18 . type ) {
case V_32 :
F_6 ( V_4 , V_193 , 0x4 ) ;
break;
case V_194 :
F_6 ( V_4 , V_193 , 0x14 ) ;
break;
default:
break;
}
V_186 = F_70 ( 1 , ~ V_154 -> V_158 ) ;
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ ) {
unsigned int V_195 = ( V_24 * V_186 ) + V_185 ;
F_6 ( V_4 , V_196 , V_195 ) ;
F_6 ( V_4 , V_197 , V_184 ) ;
}
}
void F_88 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_188 )
return;
if ( F_86 ( V_2 ) != V_2 -> V_188 ) {
V_2 -> V_188 = 0 ;
F_84 ( & V_2 -> V_44 -> V_45 ,
L_29 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_188 )
V_2 -> V_30 [ V_6 ] . V_187 = 0 ;
F_87 ( V_2 , V_6 ) ;
}
}
int F_89 ( struct V_88 * V_89 , int V_24 , int V_187 )
{
struct V_1 * V_2 = F_83 ( V_89 ) ;
int V_180 ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
if ( ! V_2 -> V_198 )
return - V_103 ;
V_180 = F_86 ( V_2 ) ;
if ( V_180 != 10000 )
return - V_103 ;
if ( V_187 && ( ( V_187 <= 10 ) || ( V_187 > V_180 ) ) )
return - V_103 ;
V_2 -> V_188 = V_180 ;
V_2 -> V_30 [ V_24 ] . V_187 = V_187 ;
F_87 ( V_2 , V_24 ) ;
return 0 ;
}
int F_67 ( struct V_88 * V_89 , int V_24 , bool V_199 )
{
struct V_1 * V_2 = F_83 ( V_89 ) ;
int V_200 = V_24 >> 3 ;
int V_201 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_202 ;
V_2 -> V_30 [ V_24 ] . V_41 = V_199 ;
V_202 = F_19 ( V_4 , F_90 ( V_200 ) ) ;
V_202 &= ~ ( 1 << V_201 ) ;
V_202 |= ( V_199 << V_201 ) ;
F_6 ( V_4 , F_90 ( V_200 ) , V_202 ) ;
if ( V_2 -> V_30 [ V_24 ] . V_149 ) {
V_201 += V_203 ;
V_202 = F_19 ( V_4 , F_90 ( V_200 ) ) ;
V_202 &= ~ ( 1 << V_201 ) ;
V_202 |= ( V_199 << V_201 ) ;
F_6 ( V_4 , F_90 ( V_200 ) , V_202 ) ;
}
return 0 ;
}
int F_91 ( struct V_88 * V_89 ,
int V_24 , struct V_204 * V_205 )
{
struct V_1 * V_2 = F_83 ( V_89 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_103 ;
V_205 -> V_24 = V_24 ;
memcpy ( & V_205 -> V_18 , V_2 -> V_30 [ V_24 ] . V_121 , V_122 ) ;
V_205 -> V_187 = V_2 -> V_30 [ V_24 ] . V_187 ;
V_205 -> V_140 = V_2 -> V_30 [ V_24 ] . V_114 ;
V_205 -> V_179 = V_2 -> V_30 [ V_24 ] . V_115 ;
V_205 -> V_206 = V_2 -> V_30 [ V_24 ] . V_41 ;
return 0 ;
}
