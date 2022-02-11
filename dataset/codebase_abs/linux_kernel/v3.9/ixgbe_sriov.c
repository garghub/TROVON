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
if ( ! V_43 )
F_9 ( & V_2 -> V_44 -> V_45 ,
L_2 ) ;
if ( V_43 ) {
V_2 -> V_12 = V_43 ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_3 ) ;
} else {
int V_46 ;
V_2 -> V_12 = F_10 (unsigned int, adapter->num_vfs, 63 ) ;
V_46 = F_11 ( V_2 -> V_44 , V_2 -> V_12 ) ;
if ( V_46 ) {
F_12 ( V_11 , L_4 , V_46 ) ;
V_2 -> V_12 = 0 ;
return;
}
}
if ( ! F_1 ( V_2 ) )
return;
F_12 ( V_11 , L_5
L_6 ) ;
F_13 ( V_2 ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_47 * V_44 = V_2 -> V_44 ;
struct V_47 * V_48 ;
int V_49 ;
switch ( V_2 -> V_4 . V_18 . type ) {
case V_32 :
V_49 = V_50 ;
break;
case V_51 :
V_49 = V_52 ;
break;
default:
return false ;
}
V_48 = F_15 ( V_53 , V_49 , NULL ) ;
while ( V_48 ) {
if ( V_48 -> V_54 && V_48 -> V_55 == V_44 ) {
if ( V_48 -> V_56 & V_57 )
return true ;
}
V_48 = F_15 ( V_53 , V_49 , V_48 ) ;
}
return false ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_58 ;
T_1 V_59 ;
int V_60 ;
V_2 -> V_12 = 0 ;
F_16 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
F_16 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
#ifdef F_17
if ( F_14 ( V_2 ) ) {
F_18 ( L_7 ) ;
return - V_61 ;
}
F_19 ( V_2 -> V_44 ) ;
#endif
F_6 ( V_4 , V_62 , 0 ) ;
V_58 = F_20 ( V_4 , V_63 ) ;
V_58 &= ~ V_64 ;
F_6 ( V_4 , V_63 , V_58 ) ;
V_59 = F_20 ( V_4 , V_65 ) ;
V_59 &= ~ V_66 ;
F_6 ( V_4 , V_65 , V_59 ) ;
F_21 ( V_4 ) ;
if ( V_2 -> V_14 [ V_15 ] . V_16 == 1 )
V_2 -> V_9 &= ~ V_13 ;
V_2 -> V_14 [ V_15 ] . V_17 = 0 ;
V_60 = F_10 ( int , V_67 , F_22 () ) ;
V_2 -> V_14 [ V_38 ] . V_16 = V_60 ;
F_23 ( 100 ) ;
V_2 -> V_9 &= ~ V_10 ;
return 0 ;
}
static int F_24 ( struct V_47 * V_45 , int V_12 )
{
#ifdef F_17
struct V_1 * V_2 = F_25 ( V_45 ) ;
int V_46 = 0 ;
int V_6 ;
int V_43 = F_8 ( V_45 ) ;
if ( V_43 && V_43 != V_12 )
V_46 = F_13 ( V_2 ) ;
else if ( V_43 && V_43 == V_12 )
goto V_68;
if ( V_46 )
goto V_69;
if ( V_12 > 63 ) {
V_46 = - V_61 ;
goto V_69;
}
V_2 -> V_12 = V_12 ;
V_46 = F_1 ( V_2 ) ;
if ( V_46 )
goto V_69;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ )
F_26 ( V_45 , ( V_6 | 0x10000000 ) ) ;
V_46 = F_11 ( V_45 , V_12 ) ;
if ( V_46 ) {
F_18 ( L_4 , V_46 ) ;
goto V_69;
}
F_27 ( V_2 ) ;
V_68:
return V_12 ;
V_69:
return V_46 ;
#endif
return 0 ;
}
static int F_28 ( struct V_47 * V_45 )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
int V_46 ;
T_1 V_70 = V_2 -> V_9 ;
V_46 = F_13 ( V_2 ) ;
if ( ! V_46 && V_70 != V_2 -> V_9 ) {
V_2 -> V_9 &= ~ V_13 ;
#ifdef F_17
F_27 ( V_2 ) ;
#endif
}
return V_46 ;
}
int F_29 ( struct V_47 * V_45 , int V_12 )
{
if ( V_12 == 0 )
return F_28 ( V_45 ) ;
else
return F_24 ( V_45 , V_12 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 V_24 )
{
int V_72 = ( V_71 [ 0 ] & V_73 )
>> V_74 ;
T_2 * V_75 = ( T_2 * ) & V_71 [ 1 ] ;
struct V_31 * V_30 = & V_2 -> V_30 [ V_24 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_6 ;
T_1 V_76 ;
T_1 V_77 ;
T_1 V_78 ;
V_72 = F_31 ( V_72 , V_79 ) ;
V_30 -> V_80 = V_72 ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ ) {
V_30 -> V_81 [ V_6 ] = V_75 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 < V_30 -> V_80 ; V_6 ++ ) {
V_77 = ( V_30 -> V_81 [ V_6 ] >> 5 ) & 0x7F ;
V_76 = V_30 -> V_81 [ V_6 ] & 0x1F ;
V_78 = F_20 ( V_4 , F_32 ( V_77 ) ) ;
V_78 |= ( 1 << V_76 ) ;
F_6 ( V_4 , F_32 ( V_77 ) , V_78 ) ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_82 * V_83 ;
struct V_7 * V_84 ;
F_34 (pos, &adapter->vf_mvs.l) {
V_84 = F_35 ( V_83 , struct V_7 , V_23 ) ;
if ( ! V_84 -> free )
V_4 -> V_18 . V_85 . V_86 ( V_4 , V_84 -> V_25 ,
V_84 -> V_87 ,
V_84 -> V_24 , V_88 ) ;
}
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_31 * V_30 ;
int V_6 , V_89 ;
T_1 V_76 ;
T_1 V_77 ;
T_1 V_78 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_30 = & V_2 -> V_30 [ V_6 ] ;
for ( V_89 = 0 ; V_89 < V_30 -> V_80 ; V_89 ++ ) {
V_4 -> V_90 . V_91 ++ ;
V_77 = ( V_30 -> V_81 [ V_89 ] >> 5 ) & 0x7F ;
V_76 = V_30 -> V_81 [ V_89 ] & 0x1F ;
V_78 = F_20 ( V_4 , F_32 ( V_77 ) ) ;
V_78 |= ( 1 << V_76 ) ;
F_6 ( V_4 , F_32 ( V_77 ) , V_78 ) ;
}
}
F_33 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_92 , int V_93 ,
T_1 V_24 )
{
if ( ! V_93 && ! V_92 )
return 0 ;
return V_2 -> V_4 . V_18 . V_85 . V_94 ( & V_2 -> V_4 , V_93 , V_24 , ( bool ) V_92 ) ;
}
static T_3 F_38 ( struct V_1 * V_2 , T_1 * V_71 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_95 = V_71 [ 1 ] ;
T_1 V_96 ;
if ( V_2 -> V_4 . V_18 . type == V_32 ) {
struct V_97 * V_45 = V_2 -> V_98 ;
int V_99 = V_45 -> V_100 + V_101 ;
T_1 V_102 , V_103 , V_104 ;
T_3 V_46 = 0 ;
#ifdef F_39
if ( V_45 -> V_105 & V_106 )
V_99 = F_40 ( int , V_99 ,
V_107 ) ;
#endif
switch ( V_2 -> V_30 [ V_24 ] . V_108 ) {
case V_109 :
if ( V_99 > V_110 )
break;
default:
if ( ( V_99 > V_110 ) ||
( V_95 > ( V_110 + V_111 ) ) )
V_46 = - V_112 ;
break;
}
V_103 = V_24 % 32 ;
V_102 = V_24 / 32 ;
V_104 = F_20 ( V_4 , F_41 ( V_102 ) ) ;
if ( V_46 )
V_104 &= ~ ( 1 << V_103 ) ;
else
V_104 |= 1 << V_103 ;
F_6 ( V_4 , F_41 ( V_102 ) , V_104 ) ;
if ( V_46 ) {
F_12 ( V_113 , L_8 , V_95 ) ;
return V_46 ;
}
}
if ( V_95 > V_114 ) {
F_12 ( V_113 , L_8 , V_95 ) ;
return - V_112 ;
}
V_96 = F_20 ( V_4 , V_115 ) ;
V_96 &= V_116 ;
V_96 >>= V_117 ;
if ( V_96 < V_95 ) {
V_96 = V_95 << V_117 ;
F_6 ( V_4 , V_115 , V_96 ) ;
}
F_2 ( V_4 , L_9 , V_95 ) ;
return 0 ;
}
static void F_42 ( struct V_3 * V_4 , T_1 V_24 , bool V_118 )
{
T_1 V_119 = F_20 ( V_4 , F_43 ( V_24 ) ) ;
V_119 |= ( V_120 |
V_121 ) ;
if ( V_118 )
V_119 |= V_122 ;
else
V_119 &= ~ V_122 ;
F_6 ( V_4 , F_43 ( V_24 ) , V_119 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_45 ( V_24 ) , 0 ) ;
}
static inline void F_46 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_31 * V_30 = & V_2 -> V_30 [ V_24 ] ;
int V_25 = V_4 -> V_18 . V_19 - ( V_24 + 1 ) ;
T_4 V_34 = F_47 ( V_2 -> V_98 ) ;
F_37 ( V_2 , true , V_30 -> V_123 , V_24 ) ;
F_42 ( V_4 , V_24 , ! V_30 -> V_123 ) ;
if ( ! V_30 -> V_123 && ! V_30 -> V_124 && ! V_34 ) {
F_44 ( V_2 , V_24 ) ;
} else {
if ( V_30 -> V_124 || ! V_34 )
F_48 ( V_2 , V_30 -> V_123 ,
V_30 -> V_124 , V_24 ) ;
else
F_48 ( V_2 , V_30 -> V_123 ,
V_2 -> V_125 , V_24 ) ;
if ( V_30 -> V_41 )
V_4 -> V_18 . V_85 . V_126 ( V_4 , true , V_24 ) ;
}
V_2 -> V_30 [ V_24 ] . V_80 = 0 ;
F_49 ( V_2 -> V_98 ) ;
V_4 -> V_18 . V_85 . V_127 ( V_4 , V_25 ) ;
V_2 -> V_30 [ V_24 ] . V_108 = V_128 ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_24 , unsigned char * V_129 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_25 = V_4 -> V_18 . V_19 - ( V_24 + 1 ) ;
memcpy ( V_2 -> V_30 [ V_24 ] . V_130 , V_129 , 6 ) ;
V_4 -> V_18 . V_85 . V_86 ( V_4 , V_25 , V_129 , V_24 , V_88 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_24 , int V_131 , unsigned char * V_129 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_82 * V_83 ;
struct V_7 * V_84 ;
if ( V_131 <= 1 ) {
F_34 (pos, &adapter->vf_mvs.l) {
V_84 = F_35 ( V_83 , struct V_7 , V_23 ) ;
if ( V_84 -> V_24 == V_24 ) {
V_84 -> V_24 = - 1 ;
V_84 -> free = true ;
V_84 -> V_132 = false ;
V_4 -> V_18 . V_85 . V_127 ( V_4 , V_84 -> V_25 ) ;
}
}
}
if ( ! V_131 )
return 0 ;
V_84 = NULL ;
F_34 (pos, &adapter->vf_mvs.l) {
V_84 = F_35 ( V_83 , struct V_7 , V_23 ) ;
if ( V_84 -> free )
break;
}
if ( ! V_84 || ! V_84 -> free )
return - V_133 ;
V_84 -> free = false ;
V_84 -> V_132 = true ;
V_84 -> V_24 = V_24 ;
memcpy ( V_84 -> V_87 , V_129 , V_134 ) ;
V_4 -> V_18 . V_85 . V_86 ( V_4 , V_84 -> V_25 , V_129 , V_24 , V_88 ) ;
return 0 ;
}
int F_26 ( struct V_47 * V_44 , unsigned int V_135 )
{
unsigned char V_136 [ 6 ] ;
struct V_1 * V_2 = F_25 ( V_44 ) ;
unsigned int V_137 = ( V_135 & 0x3f ) ;
bool V_138 = ( ( V_135 & 0x10000000U ) != 0 ) ;
if ( V_138 ) {
F_52 ( V_136 ) ;
F_2 ( V_11 , L_10 ,
V_137 , V_136 ) ;
memcpy ( V_2 -> V_30 [ V_137 ] . V_130 , V_136 , 6 ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned char * V_139 = V_2 -> V_30 [ V_24 ] . V_130 ;
T_1 V_140 , V_71 [ 4 ] ;
T_1 V_102 , V_103 ;
T_4 * V_141 = ( T_4 * ) ( & V_71 [ 1 ] ) ;
F_2 ( V_11 , L_11 , V_24 ) ;
F_46 ( V_2 , V_24 ) ;
F_50 ( V_2 , V_24 , V_139 ) ;
V_103 = V_24 % 32 ;
V_102 = V_24 / 32 ;
V_140 = F_20 ( V_4 , F_54 ( V_102 ) ) ;
V_140 |= 1 << V_103 ;
F_6 ( V_4 , F_54 ( V_102 ) , V_140 ) ;
V_140 = F_20 ( V_4 , F_41 ( V_102 ) ) ;
V_140 |= 1 << V_103 ;
if ( V_2 -> V_4 . V_18 . type == V_32 ) {
struct V_97 * V_45 = V_2 -> V_98 ;
int V_99 = V_45 -> V_100 + V_101 ;
#ifdef F_39
if ( V_45 -> V_105 & V_106 )
V_99 = F_40 ( int , V_99 ,
V_107 ) ;
#endif
if ( V_99 > V_110 )
V_140 &= ~ ( 1 << V_103 ) ;
}
F_6 ( V_4 , F_41 ( V_102 ) , V_140 ) ;
V_2 -> V_30 [ V_24 ] . V_142 = true ;
V_140 = F_20 ( V_4 , F_55 ( V_102 ) ) ;
V_140 |= ( 1 << V_103 ) ;
F_6 ( V_4 , F_55 ( V_102 ) , V_140 ) ;
V_71 [ 0 ] = V_143 | V_144 ;
memcpy ( V_141 , V_139 , V_134 ) ;
V_71 [ 3 ] = V_4 -> V_18 . V_145 ;
F_56 ( V_4 , V_71 , V_146 , V_24 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 V_24 )
{
T_4 * V_147 = ( ( T_4 * ) ( & V_71 [ 1 ] ) ) ;
if ( ! F_58 ( V_147 ) ) {
F_59 ( V_113 , L_12 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_30 [ V_24 ] . V_148 &&
memcmp ( V_2 -> V_30 [ V_24 ] . V_130 , V_147 ,
V_134 ) ) {
F_59 ( V_113 ,
L_13
L_14 ,
V_24 ) ;
return - 1 ;
}
return F_50 ( V_2 , V_24 , V_147 ) < 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_92 = ( V_71 [ 0 ] & V_73 ) >> V_74 ;
int V_93 = ( V_71 [ 1 ] & V_149 ) ;
int V_46 ;
T_4 V_150 = F_47 ( V_2 -> V_98 ) ;
if ( V_2 -> V_30 [ V_24 ] . V_123 || V_150 ) {
F_59 ( V_113 ,
L_15
L_14 ,
V_24 ) ;
return - 1 ;
}
if ( V_92 )
V_2 -> V_30 [ V_24 ] . V_151 ++ ;
else if ( V_2 -> V_30 [ V_24 ] . V_151 )
V_2 -> V_30 [ V_24 ] . V_151 -- ;
V_46 = F_37 ( V_2 , V_92 , V_93 , V_24 ) ;
if ( ! V_46 && V_2 -> V_30 [ V_24 ] . V_41 )
V_4 -> V_18 . V_85 . V_126 ( V_4 , true , V_24 ) ;
return V_46 ;
}
static int F_61 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 V_24 )
{
T_4 * V_147 = ( ( T_4 * ) ( & V_71 [ 1 ] ) ) ;
int V_131 = ( V_71 [ 0 ] & V_73 ) >>
V_74 ;
int V_46 ;
if ( V_2 -> V_30 [ V_24 ] . V_148 && V_131 > 0 ) {
F_59 ( V_113 ,
L_16 ,
V_24 ) ;
return - 1 ;
}
if ( V_131 ) {
if ( ! F_58 ( V_147 ) ) {
F_59 ( V_113 , L_12 , V_24 ) ;
return - 1 ;
}
if ( V_2 -> V_30 [ V_24 ] . V_41 )
F_62 ( V_2 -> V_98 , V_24 , false ) ;
}
V_46 = F_51 ( V_2 , V_24 , V_131 , V_147 ) ;
if ( V_46 == - V_133 )
F_59 ( V_113 ,
L_17 ,
V_24 ) ;
return V_46 < 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 V_24 )
{
int V_152 = V_71 [ 1 ] ;
switch ( V_152 ) {
case V_128 :
case V_109 :
V_2 -> V_30 [ V_24 ] . V_108 = V_152 ;
return 0 ;
default:
break;
}
F_2 ( V_113 , L_18 , V_24 , V_152 ) ;
return - 1 ;
}
static int F_64 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 V_24 )
{
struct V_97 * V_45 = V_2 -> V_98 ;
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
unsigned int V_155 = 0 ;
T_4 V_34 = F_47 ( V_45 ) ;
switch ( V_2 -> V_30 [ V_24 ] . V_108 ) {
case V_156 :
case V_109 :
break;
default:
return - 1 ;
}
V_71 [ V_157 ] = F_65 ( 1 , ~ V_154 -> V_158 ) ;
V_71 [ V_159 ] = F_65 ( 1 , ~ V_154 -> V_158 ) ;
if ( V_34 > 1 )
V_155 = F_66 ( V_45 , V_2 -> V_125 ) ;
if ( V_34 )
V_71 [ V_160 ] = V_34 ;
else if ( V_2 -> V_30 [ V_24 ] . V_123 || V_2 -> V_30 [ V_24 ] . V_124 )
V_71 [ V_160 ] = 1 ;
else
V_71 [ V_160 ] = 0 ;
V_71 [ V_161 ] = V_155 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_162 = V_163 ;
T_1 V_71 [ V_163 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_3 V_164 ;
V_164 = F_68 ( V_4 , V_71 , V_162 , V_24 ) ;
if ( V_164 ) {
F_69 ( L_19 ) ;
return V_164 ;
}
if ( V_71 [ 0 ] & ( V_144 | V_165 ) )
return V_164 ;
F_21 ( V_4 ) ;
if ( V_71 [ 0 ] == V_143 )
return F_53 ( V_2 , V_24 ) ;
if ( ! V_2 -> V_30 [ V_24 ] . V_142 ) {
V_71 [ 0 ] |= V_165 ;
F_56 ( V_4 , V_71 , 1 , V_24 ) ;
return V_164 ;
}
switch ( ( V_71 [ 0 ] & 0xFFFF ) ) {
case V_166 :
V_164 = F_57 ( V_2 , V_71 , V_24 ) ;
break;
case V_167 :
V_164 = F_30 ( V_2 , V_71 , V_24 ) ;
break;
case V_168 :
V_164 = F_60 ( V_2 , V_71 , V_24 ) ;
break;
case V_169 :
V_164 = F_38 ( V_2 , V_71 , V_24 ) ;
break;
case V_170 :
V_164 = F_61 ( V_2 , V_71 , V_24 ) ;
break;
case V_171 :
V_164 = F_63 ( V_2 , V_71 , V_24 ) ;
break;
case V_172 :
V_164 = F_64 ( V_2 , V_71 , V_24 ) ;
break;
default:
F_12 ( V_113 , L_20 , V_71 [ 0 ] ) ;
V_164 = V_173 ;
break;
}
if ( V_164 )
V_71 [ 0 ] |= V_165 ;
else
V_71 [ 0 ] |= V_144 ;
V_71 [ 0 ] |= V_174 ;
F_56 ( V_4 , V_71 , V_162 , V_24 ) ;
return V_164 ;
}
static void F_70 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_175 = V_165 ;
if ( ! V_2 -> V_30 [ V_24 ] . V_142 )
F_56 ( V_4 , & V_175 , 1 , V_24 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( ! F_72 ( V_4 , V_24 ) )
F_46 ( V_2 , V_24 ) ;
if ( ! F_73 ( V_4 , V_24 ) )
F_67 ( V_2 , V_24 ) ;
if ( ! F_74 ( V_4 , V_24 ) )
F_70 ( V_2 , V_24 ) ;
}
}
void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( V_4 , F_54 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_54 ( 1 ) , 0 ) ;
F_6 ( V_4 , F_41 ( 0 ) , 0 ) ;
F_6 ( V_4 , F_41 ( 1 ) , 0 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_176 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
V_176 = V_177 ;
if ( V_2 -> V_30 [ V_6 ] . V_142 )
V_176 |= V_174 ;
F_56 ( V_4 , & V_176 , 1 , V_6 ) ;
}
}
int F_77 ( struct V_97 * V_98 , int V_24 , T_4 * V_18 )
{
struct V_1 * V_2 = F_78 ( V_98 ) ;
if ( ! F_58 ( V_18 ) || ( V_24 >= V_2 -> V_12 ) )
return - V_112 ;
V_2 -> V_30 [ V_24 ] . V_148 = true ;
F_79 ( & V_2 -> V_44 -> V_45 , L_21 , V_18 , V_24 ) ;
F_79 ( & V_2 -> V_44 -> V_45 , L_22
L_23 ) ;
if ( F_80 ( V_178 , & V_2 -> V_179 ) ) {
F_9 ( & V_2 -> V_44 -> V_45 , L_24
L_25 ) ;
F_9 ( & V_2 -> V_44 -> V_45 , L_26
L_27 ) ;
}
return F_50 ( V_2 , V_24 , V_18 ) ;
}
int F_81 ( struct V_97 * V_98 , int V_24 , T_2 V_180 , T_4 V_181 )
{
int V_46 = 0 ;
struct V_1 * V_2 = F_78 ( V_98 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ( V_24 >= V_2 -> V_12 ) || ( V_180 > 4095 ) || ( V_181 > 7 ) )
return - V_112 ;
if ( V_180 || V_181 ) {
if ( V_2 -> V_30 [ V_24 ] . V_123 )
V_46 = F_37 ( V_2 , false ,
V_2 -> V_30 [ V_24 ] . V_123 ,
V_24 ) ;
if ( V_46 )
goto V_68;
V_46 = F_37 ( V_2 , true , V_180 , V_24 ) ;
if ( V_46 )
goto V_68;
F_48 ( V_2 , V_180 , V_181 , V_24 ) ;
F_42 ( V_4 , V_24 , false ) ;
if ( V_2 -> V_30 [ V_24 ] . V_41 )
V_4 -> V_18 . V_85 . V_126 ( V_4 , true , V_24 ) ;
V_2 -> V_30 [ V_24 ] . V_151 ++ ;
V_2 -> V_30 [ V_24 ] . V_123 = V_180 ;
V_2 -> V_30 [ V_24 ] . V_124 = V_181 ;
F_79 ( & V_2 -> V_44 -> V_45 ,
L_28 , V_180 , V_181 , V_24 ) ;
if ( F_80 ( V_178 , & V_2 -> V_179 ) ) {
F_9 ( & V_2 -> V_44 -> V_45 ,
L_29
L_25 ) ;
F_9 ( & V_2 -> V_44 -> V_45 ,
L_26
L_27 ) ;
}
} else {
V_46 = F_37 ( V_2 , false ,
V_2 -> V_30 [ V_24 ] . V_123 , V_24 ) ;
F_44 ( V_2 , V_24 ) ;
F_42 ( V_4 , V_24 , true ) ;
V_4 -> V_18 . V_85 . V_126 ( V_4 , false , V_24 ) ;
if ( V_2 -> V_30 [ V_24 ] . V_151 )
V_2 -> V_30 [ V_24 ] . V_151 -- ;
V_2 -> V_30 [ V_24 ] . V_123 = 0 ;
V_2 -> V_30 [ V_24 ] . V_124 = 0 ;
}
V_68:
return V_46 ;
}
static int F_82 ( struct V_1 * V_2 )
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
static void F_83 ( struct V_1 * V_2 , int V_24 )
{
struct V_153 * V_154 = & V_2 -> V_14 [ V_15 ] ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_186 = 0 ;
T_2 V_187 , V_188 ;
T_2 V_189 = V_2 -> V_30 [ V_24 ] . V_189 ;
if ( V_189 ) {
V_186 = V_2 -> V_190 ;
V_186 <<= V_191 ;
V_186 /= V_189 ;
V_186 &= V_192 |
V_193 ;
V_186 |= V_194 ;
}
switch ( V_4 -> V_18 . type ) {
case V_32 :
F_6 ( V_4 , V_195 , 0x4 ) ;
break;
case V_51 :
F_6 ( V_4 , V_195 , 0x14 ) ;
break;
default:
break;
}
V_188 = F_65 ( 1 , ~ V_154 -> V_158 ) ;
for ( V_187 = 0 ; V_187 < V_188 ; V_187 ++ ) {
unsigned int V_196 = ( V_24 * V_188 ) + V_187 ;
F_6 ( V_4 , V_197 , V_196 ) ;
F_6 ( V_4 , V_198 , V_186 ) ;
}
}
void F_84 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_190 )
return;
if ( F_82 ( V_2 ) != V_2 -> V_190 ) {
V_2 -> V_190 = 0 ;
F_79 ( & V_2 -> V_44 -> V_45 ,
L_30 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_12 ; V_6 ++ ) {
if ( ! V_2 -> V_190 )
V_2 -> V_30 [ V_6 ] . V_189 = 0 ;
F_83 ( V_2 , V_6 ) ;
}
}
int F_85 ( struct V_97 * V_98 , int V_24 , int V_189 )
{
struct V_1 * V_2 = F_78 ( V_98 ) ;
int V_182 ;
if ( V_24 >= V_2 -> V_12 )
return - V_112 ;
if ( ! V_2 -> V_199 )
return - V_112 ;
V_182 = F_82 ( V_2 ) ;
if ( V_182 != 10000 )
return - V_112 ;
if ( V_189 && ( ( V_189 <= 10 ) || ( V_189 > V_182 ) ) )
return - V_112 ;
V_2 -> V_190 = V_182 ;
V_2 -> V_30 [ V_24 ] . V_189 = V_189 ;
F_83 ( V_2 , V_24 ) ;
return 0 ;
}
int F_62 ( struct V_97 * V_98 , int V_24 , bool V_200 )
{
struct V_1 * V_2 = F_78 ( V_98 ) ;
int V_201 = V_24 >> 3 ;
int V_202 = V_24 % 8 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_203 ;
V_2 -> V_30 [ V_24 ] . V_41 = V_200 ;
V_203 = F_20 ( V_4 , F_86 ( V_201 ) ) ;
V_203 &= ~ ( 1 << V_202 ) ;
V_203 |= ( V_200 << V_202 ) ;
F_6 ( V_4 , F_86 ( V_201 ) , V_203 ) ;
if ( V_2 -> V_30 [ V_24 ] . V_151 ) {
V_202 += V_204 ;
V_203 = F_20 ( V_4 , F_86 ( V_201 ) ) ;
V_203 &= ~ ( 1 << V_202 ) ;
V_203 |= ( V_200 << V_202 ) ;
F_6 ( V_4 , F_86 ( V_201 ) , V_203 ) ;
}
return 0 ;
}
int F_87 ( struct V_97 * V_98 ,
int V_24 , struct V_205 * V_206 )
{
struct V_1 * V_2 = F_78 ( V_98 ) ;
if ( V_24 >= V_2 -> V_12 )
return - V_112 ;
V_206 -> V_24 = V_24 ;
memcpy ( & V_206 -> V_18 , V_2 -> V_30 [ V_24 ] . V_130 , V_134 ) ;
V_206 -> V_189 = V_2 -> V_30 [ V_24 ] . V_189 ;
V_206 -> V_180 = V_2 -> V_30 [ V_24 ] . V_123 ;
V_206 -> V_181 = V_2 -> V_30 [ V_24 ] . V_124 ;
V_206 -> V_207 = V_2 -> V_30 [ V_24 ] . V_41 ;
return 0 ;
}
