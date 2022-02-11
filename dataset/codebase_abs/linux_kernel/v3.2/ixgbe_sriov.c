static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_3 * V_5 ;
T_1 V_6 = 0 ;
int V_7 ;
int V_8 = 0 ;
switch ( V_2 -> V_9 . V_10 . type ) {
case V_11 :
V_7 = V_12 ;
break;
case V_13 :
V_7 = V_14 ;
break;
default:
V_7 = 0 ;
break;
}
V_6 = V_4 -> V_15 + 0x80 ;
V_5 = F_2 ( V_16 , V_7 , NULL ) ;
while ( V_5 ) {
if ( V_5 -> V_15 == V_6 )
V_8 ++ ;
V_6 += 2 ;
V_5 = F_2 ( V_16 ,
V_7 , V_5 ) ;
}
return V_8 ;
}
void F_3 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
int V_20 = 0 ;
int V_21 , V_22 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
V_25 = F_1 ( V_2 ) ;
if ( ! V_25 && ! V_2 -> V_26 )
return;
if ( V_25 ) {
V_2 -> V_26 = V_25 ;
F_4 ( & V_2 -> V_4 -> V_27 , L_1
L_2
L_3 ) ;
} else {
V_20 = F_5 ( V_2 -> V_4 , V_2 -> V_26 ) ;
}
if ( V_20 ) {
F_6 ( V_28 , L_4 , V_20 ) ;
goto V_29;
}
V_2 -> V_30 |= V_31 ;
F_7 ( V_28 , L_5 , V_2 -> V_26 ) ;
V_21 = V_9 -> V_10 . V_32 -
( V_33 + 1 + V_2 -> V_26 ) ;
V_2 -> V_24 = V_24 = F_8 ( V_21 ,
sizeof( struct V_23 ) ,
V_34 ) ;
if ( V_24 ) {
F_9 ( & V_2 -> V_35 . V_36 ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_24 -> V_37 = - 1 ;
V_24 -> free = true ;
V_24 -> V_38 = V_9 -> V_10 . V_32 -
( V_22 + V_2 -> V_26 + 1 ) ;
F_10 ( & V_24 -> V_36 , & V_2 -> V_35 . V_36 ) ;
V_24 ++ ;
}
}
V_2 -> V_39 =
F_8 ( V_2 -> V_26 ,
sizeof( struct V_40 ) , V_34 ) ;
if ( V_2 -> V_39 ) {
F_11 ( V_9 ) ;
memcpy ( & V_9 -> V_41 . V_42 , V_18 -> V_43 ,
sizeof( V_9 -> V_41 . V_42 ) ) ;
V_2 -> V_44 &= ~ ( V_45 |
V_46 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_26 ; V_22 ++ )
V_2 -> V_39 [ V_22 ] . V_47 = true ;
return;
}
F_6 ( V_28 , L_6
L_7 ) ;
F_12 ( V_2 -> V_4 ) ;
V_29:
V_2 -> V_30 &= ~ V_31 ;
V_2 -> V_26 = 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
T_2 V_48 ;
T_2 V_49 ;
T_2 V_50 ;
int V_22 ;
#ifdef F_14
F_12 ( V_2 -> V_4 ) ;
#endif
V_48 = F_15 ( V_9 , V_51 ) ;
V_48 &= ~ ( V_52 ) ;
F_16 ( V_9 , V_51 , V_48 ) ;
V_49 = F_15 ( V_9 , V_53 ) ;
V_49 &= ~ V_54 ;
F_16 ( V_9 , V_53 , V_49 ) ;
V_50 = F_15 ( V_9 , V_55 ) ;
V_50 &= ~ V_56 ;
F_16 ( V_9 , V_55 , V_50 ) ;
F_17 ( V_9 ) ;
F_18 ( 100 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_26 ; V_22 ++ ) {
if ( V_2 -> V_39 [ V_22 ] . V_57 )
F_19 ( V_2 -> V_39 [ V_22 ] . V_57 ) ;
}
F_20 ( V_2 -> V_39 ) ;
F_20 ( V_2 -> V_24 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_26 = 0 ;
V_2 -> V_30 &= ~ V_31 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_58 , T_1 * V_59 , T_2 V_37 )
{
struct V_40 * V_39 = & V_2 -> V_39 [ V_37 ] ;
struct V_19 * V_9 = & V_2 -> V_9 ;
int V_22 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_62 ;
V_58 = F_22 ( V_58 , V_63 ) ;
V_39 -> V_64 = V_58 ;
for ( V_22 = 0 ; V_22 < V_58 ; V_22 ++ ) {
V_39 -> V_65 [ V_22 ] = V_59 [ V_22 ] ;
}
for ( V_22 = 0 ; V_22 < V_39 -> V_64 ; V_22 ++ ) {
V_61 = ( V_39 -> V_65 [ V_22 ] >> 5 ) & 0x7F ;
V_60 = V_39 -> V_65 [ V_22 ] & 0x1F ;
V_62 = F_15 ( V_9 , F_23 ( V_61 ) ) ;
V_62 |= ( 1 << V_60 ) ;
F_16 ( V_9 , F_23 ( V_61 ) , V_62 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
struct V_66 * V_67 ;
struct V_23 * V_68 ;
F_25 (pos, &adapter->vf_mvs.l) {
V_68 = F_26 ( V_67 , struct V_23 , V_36 ) ;
if ( V_68 -> free == false )
V_9 -> V_10 . V_42 . V_69 ( V_9 , V_68 -> V_38 ,
V_68 -> V_70 ,
V_68 -> V_37 , V_71 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
struct V_40 * V_39 ;
int V_22 , V_72 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_62 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_26 ; V_22 ++ ) {
V_39 = & V_2 -> V_39 [ V_22 ] ;
for ( V_72 = 0 ; V_72 < V_39 -> V_64 ; V_72 ++ ) {
V_9 -> V_73 . V_74 ++ ;
V_61 = ( V_39 -> V_65 [ V_72 ] >> 5 ) & 0x7F ;
V_60 = V_39 -> V_65 [ V_72 ] & 0x1F ;
V_62 = F_15 ( V_9 , F_23 ( V_61 ) ) ;
V_62 |= ( 1 << V_60 ) ;
F_16 ( V_9 , F_23 ( V_61 ) , V_62 ) ;
}
}
F_24 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_75 , int V_76 ,
T_2 V_37 )
{
return V_2 -> V_9 . V_10 . V_42 . V_77 ( & V_2 -> V_9 , V_76 , V_37 , ( bool ) V_75 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_78 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
int V_79 = V_78 [ 1 ] ;
T_2 V_80 ;
int V_81 = V_79 + V_82 + V_83 ;
if ( V_2 -> V_9 . V_10 . type != V_13 )
return;
if ( ( V_79 < 68 ) || ( V_81 > V_84 ) ) {
F_6 ( V_85 , L_8 , V_79 ) ;
return;
}
V_80 = ( F_15 ( V_9 , V_86 ) &
V_87 ) >> V_88 ;
if ( V_80 < V_79 ) {
V_80 = V_79 << V_88 ;
F_16 ( V_9 , V_86 , V_80 ) ;
}
F_7 ( V_9 , L_9 , V_79 ) ;
}
static void F_30 ( struct V_19 * V_9 , T_2 V_37 , bool V_89 )
{
T_2 V_90 = F_15 ( V_9 , F_31 ( V_37 ) ) ;
V_90 |= ( V_91 |
V_92 ) ;
if ( V_89 )
V_90 |= V_93 ;
else
V_90 &= ~ V_93 ;
F_16 ( V_9 , F_31 ( V_37 ) , V_90 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_76 , T_2 V_37 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
if ( V_76 )
F_16 ( V_9 , F_33 ( V_37 ) ,
( V_76 | V_94 ) ) ;
else
F_16 ( V_9 , F_33 ( V_37 ) , 0 ) ;
}
static inline void F_34 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
int V_38 = V_9 -> V_10 . V_32 - ( V_37 + 1 ) ;
if ( V_2 -> V_39 [ V_37 ] . V_95 ) {
F_28 ( V_2 , true ,
V_2 -> V_39 [ V_37 ] . V_95 , V_37 ) ;
F_32 ( V_2 ,
( V_2 -> V_39 [ V_37 ] . V_95 |
( V_2 -> V_39 [ V_37 ] . V_96 <<
V_97 ) ) , V_37 ) ;
F_30 ( V_9 , V_37 , false ) ;
} else {
F_32 ( V_2 , 0 , V_37 ) ;
F_30 ( V_9 , V_37 , true ) ;
}
V_2 -> V_39 [ V_37 ] . V_64 = 0 ;
F_35 ( V_2 -> V_98 ) ;
V_9 -> V_10 . V_42 . V_99 ( V_9 , V_38 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_37 , unsigned char * V_100 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
int V_38 = V_9 -> V_10 . V_32 - ( V_37 + 1 ) ;
memcpy ( V_2 -> V_39 [ V_37 ] . V_101 , V_100 , 6 ) ;
V_9 -> V_10 . V_42 . V_69 ( V_9 , V_38 , V_100 , V_37 , V_71 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
int V_37 , int V_102 , unsigned char * V_100 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
struct V_66 * V_67 ;
struct V_23 * V_68 ;
if ( V_102 <= 1 ) {
F_25 (pos, &adapter->vf_mvs.l) {
V_68 = F_26 ( V_67 , struct V_23 , V_36 ) ;
if ( V_68 -> V_37 == V_37 ) {
V_68 -> V_37 = - 1 ;
V_68 -> free = true ;
V_68 -> V_103 = false ;
V_9 -> V_10 . V_42 . V_99 ( V_9 , V_68 -> V_38 ) ;
}
}
}
if ( ! V_102 )
return 0 ;
V_68 = NULL ;
F_25 (pos, &adapter->vf_mvs.l) {
V_68 = F_26 ( V_67 , struct V_23 , V_36 ) ;
if ( V_68 -> free )
break;
}
if ( ! V_68 || ! V_68 -> free )
return - V_104 ;
V_68 -> free = false ;
V_68 -> V_103 = true ;
V_68 -> V_37 = V_37 ;
memcpy ( V_68 -> V_70 , V_100 , V_105 ) ;
V_9 -> V_10 . V_42 . V_69 ( V_9 , V_68 -> V_38 , V_100 , V_37 , V_71 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
#ifdef F_14
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_26 ; V_22 ++ ) {
if ( V_2 -> V_39 [ V_22 ] . V_57 -> V_106 &
V_107 )
return true ;
}
#endif
return false ;
}
int F_39 ( struct V_3 * V_4 , unsigned int V_108 )
{
unsigned char V_109 [ 6 ] ;
struct V_1 * V_2 = F_40 ( V_4 ) ;
unsigned int V_110 = ( V_108 & 0x3f ) ;
struct V_3 * V_5 ;
unsigned int V_7 ;
T_1 V_111 = ( V_4 -> V_15 + 0x80 + ( V_110 << 1 ) ) |
( V_4 -> V_15 & 1 ) ;
bool V_112 = ( ( V_108 & 0x10000000U ) != 0 ) ;
if ( V_112 ) {
F_41 ( V_109 ) ;
F_7 ( V_28 , L_10 ,
V_110 , V_109 ) ;
memcpy ( V_2 -> V_39 [ V_110 ] . V_101 , V_109 , 6 ) ;
switch ( V_2 -> V_9 . V_10 . type ) {
case V_11 :
V_7 = V_12 ;
break;
case V_13 :
V_7 = V_14 ;
break;
default:
V_7 = 0 ;
break;
}
V_5 = F_2 ( V_16 , V_7 , NULL ) ;
while ( V_5 ) {
if ( V_5 -> V_15 == V_111 )
break;
V_5 = F_2 ( V_16 ,
V_7 , V_5 ) ;
}
if ( V_5 )
V_2 -> V_39 [ V_110 ] . V_57 = V_5 ;
else
F_6 ( V_85 , L_11 ,
V_111 ) ;
}
return 0 ;
}
static inline void F_42 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
T_2 V_113 ;
T_2 V_114 , V_115 ;
V_115 = V_37 % 32 ;
V_114 = V_37 / 32 ;
V_113 = F_15 ( V_9 , F_43 ( V_114 ) ) ;
V_113 |= ( V_113 | ( 1 << V_115 ) ) ;
F_16 ( V_9 , F_43 ( V_114 ) , V_113 ) ;
V_113 = F_15 ( V_9 , F_44 ( V_114 ) ) ;
V_113 |= ( V_113 | ( 1 << V_115 ) ) ;
F_16 ( V_9 , F_44 ( V_114 ) , V_113 ) ;
V_113 = F_15 ( V_9 , F_45 ( V_114 ) ) ;
V_113 |= ( 1 << V_115 ) ;
F_16 ( V_9 , F_45 ( V_114 ) , V_113 ) ;
F_34 ( V_2 , V_37 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_37 )
{
T_2 V_116 = V_117 ;
T_2 V_78 [ V_117 ] ;
struct V_19 * V_9 = & V_2 -> V_9 ;
T_3 V_118 ;
int V_58 ;
T_1 * V_59 ;
int V_75 , V_76 , V_102 ;
T_4 * V_119 ;
V_118 = F_47 ( V_9 , V_78 , V_116 , V_37 ) ;
if ( V_118 )
F_48 ( L_12 ) ;
if ( V_78 [ 0 ] & ( V_120 | V_121 ) )
return V_118 ;
if ( V_78 [ 0 ] == V_122 ) {
unsigned char * V_123 = V_2 -> V_39 [ V_37 ] . V_101 ;
V_119 = ( T_4 * ) ( & V_78 [ 1 ] ) ;
F_7 ( V_28 , L_13 , V_37 ) ;
V_2 -> V_39 [ V_37 ] . V_124 = false ;
F_42 ( V_2 , V_37 ) ;
V_2 -> V_39 [ V_37 ] . V_124 = true ;
if ( F_49 ( V_119 ) &&
! V_2 -> V_39 [ V_37 ] . V_125 )
F_36 ( V_2 , V_37 , V_123 ) ;
else
F_36 ( V_2 ,
V_37 , V_2 -> V_39 [ V_37 ] . V_101 ) ;
V_78 [ 0 ] = V_122 | V_120 ;
memcpy ( V_119 , V_123 , V_126 ) ;
V_78 [ 3 ] = V_9 -> V_10 . V_127 ;
F_50 ( V_9 , V_78 , V_128 , V_37 ) ;
return V_118 ;
}
if ( ! V_2 -> V_39 [ V_37 ] . V_124 ) {
V_78 [ 0 ] |= V_121 ;
F_50 ( V_9 , V_78 , 1 , V_37 ) ;
return V_118 ;
}
switch ( ( V_78 [ 0 ] & 0xFFFF ) ) {
case V_129 :
V_119 = ( ( T_4 * ) ( & V_78 [ 1 ] ) ) ;
if ( F_49 ( V_119 ) &&
! V_2 -> V_39 [ V_37 ] . V_125 ) {
F_36 ( V_2 , V_37 , V_119 ) ;
} else if ( memcmp ( V_2 -> V_39 [ V_37 ] . V_101 ,
V_119 , V_105 ) ) {
F_51 ( V_85 , L_14
L_15
L_16 , V_37 ) ;
V_118 = - 1 ;
}
break;
case V_130 :
V_58 = ( V_78 [ 0 ] & V_131 )
>> V_132 ;
V_59 = ( T_1 * ) & V_78 [ 1 ] ;
V_118 = F_21 ( V_2 , V_58 ,
V_59 , V_37 ) ;
break;
case V_133 :
F_29 ( V_2 , V_78 ) ;
break;
case V_134 :
V_75 = ( V_78 [ 0 ] & V_131 )
>> V_132 ;
V_76 = ( V_78 [ 1 ] & V_135 ) ;
if ( V_2 -> V_39 [ V_37 ] . V_95 ) {
F_51 ( V_85 , L_14
L_17
L_18 ,
V_37 ) ;
V_118 = - 1 ;
} else {
if ( V_75 )
V_2 -> V_39 [ V_37 ] . V_136 ++ ;
else if ( V_2 -> V_39 [ V_37 ] . V_136 )
V_2 -> V_39 [ V_37 ] . V_136 -- ;
V_118 = F_28 ( V_2 , V_75 , V_76 , V_37 ) ;
if ( ! V_118 && V_2 -> V_39 [ V_37 ] . V_47 )
V_9 -> V_10 . V_42 . V_137 ( V_9 , true , V_37 ) ;
}
break;
case V_138 :
V_102 = ( V_78 [ 0 ] & V_131 ) >>
V_132 ;
if ( V_102 > 0 && V_2 -> V_39 [ V_37 ] . V_47 )
F_52 ( V_2 -> V_98 , V_37 , false ) ;
V_118 = F_37 ( V_2 , V_37 , V_102 ,
( unsigned char * ) ( & V_78 [ 1 ] ) ) ;
break;
default:
F_6 ( V_85 , L_19 , V_78 [ 0 ] ) ;
V_118 = V_139 ;
break;
}
if ( V_118 )
V_78 [ 0 ] |= V_121 ;
else
V_78 [ 0 ] |= V_120 ;
V_78 [ 0 ] |= V_140 ;
F_50 ( V_9 , V_78 , 1 , V_37 ) ;
return V_118 ;
}
static void F_53 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
T_2 V_141 = V_121 ;
if ( ! V_2 -> V_39 [ V_37 ] . V_124 )
F_50 ( V_9 , & V_141 , 1 , V_37 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
T_2 V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_26 ; V_37 ++ ) {
if ( ! F_55 ( V_9 , V_37 ) )
F_34 ( V_2 , V_37 ) ;
if ( ! F_56 ( V_9 , V_37 ) )
F_46 ( V_2 , V_37 ) ;
if ( ! F_57 ( V_9 , V_37 ) )
F_53 ( V_2 , V_37 ) ;
}
}
void F_58 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
F_16 ( V_9 , F_43 ( 0 ) , 0 ) ;
F_16 ( V_9 , F_43 ( 1 ) , 0 ) ;
F_16 ( V_9 , F_44 ( 0 ) , 0 ) ;
F_16 ( V_9 , F_44 ( 1 ) , 0 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_9 ;
T_2 V_142 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_26 ; V_22 ++ ) {
V_142 = V_143 ;
if ( V_2 -> V_39 [ V_22 ] . V_124 )
V_142 |= V_140 ;
F_50 ( V_9 , & V_142 , 1 , V_22 ) ;
}
}
int F_60 ( struct V_144 * V_98 , int V_37 , T_4 * V_10 )
{
struct V_1 * V_2 = F_61 ( V_98 ) ;
if ( ! F_49 ( V_10 ) || ( V_37 >= V_2 -> V_26 ) )
return - V_145 ;
V_2 -> V_39 [ V_37 ] . V_125 = true ;
F_62 ( & V_2 -> V_4 -> V_27 , L_20 , V_10 , V_37 ) ;
F_62 ( & V_2 -> V_4 -> V_27 , L_21
L_22 ) ;
if ( F_63 ( V_146 , & V_2 -> V_147 ) ) {
F_4 ( & V_2 -> V_4 -> V_27 , L_23
L_24 ) ;
F_4 ( & V_2 -> V_4 -> V_27 , L_25
L_26 ) ;
}
return F_36 ( V_2 , V_37 , V_10 ) ;
}
int F_64 ( struct V_144 * V_98 , int V_37 , T_1 V_148 , T_4 V_149 )
{
int V_20 = 0 ;
struct V_1 * V_2 = F_61 ( V_98 ) ;
struct V_19 * V_9 = & V_2 -> V_9 ;
if ( ( V_37 >= V_2 -> V_26 ) || ( V_148 > 4095 ) || ( V_149 > 7 ) )
return - V_145 ;
if ( V_148 || V_149 ) {
V_20 = F_28 ( V_2 , true , V_148 , V_37 ) ;
if ( V_20 )
goto V_150;
F_32 ( V_2 , V_148 | ( V_149 << V_97 ) , V_37 ) ;
F_30 ( V_9 , V_37 , false ) ;
if ( V_2 -> V_39 [ V_37 ] . V_47 )
V_9 -> V_10 . V_42 . V_137 ( V_9 , true , V_37 ) ;
V_2 -> V_39 [ V_37 ] . V_136 ++ ;
V_2 -> V_39 [ V_37 ] . V_95 = V_148 ;
V_2 -> V_39 [ V_37 ] . V_96 = V_149 ;
F_62 ( & V_2 -> V_4 -> V_27 ,
L_27 , V_148 , V_149 , V_37 ) ;
if ( F_63 ( V_146 , & V_2 -> V_147 ) ) {
F_4 ( & V_2 -> V_4 -> V_27 ,
L_28
L_24 ) ;
F_4 ( & V_2 -> V_4 -> V_27 ,
L_25
L_26 ) ;
}
} else {
V_20 = F_28 ( V_2 , false ,
V_2 -> V_39 [ V_37 ] . V_95 , V_37 ) ;
F_32 ( V_2 , V_148 , V_37 ) ;
F_30 ( V_9 , V_37 , true ) ;
V_9 -> V_10 . V_42 . V_137 ( V_9 , false , V_37 ) ;
if ( V_2 -> V_39 [ V_37 ] . V_136 )
V_2 -> V_39 [ V_37 ] . V_136 -- ;
V_2 -> V_39 [ V_37 ] . V_95 = 0 ;
V_2 -> V_39 [ V_37 ] . V_96 = 0 ;
}
V_150:
return V_20 ;
}
static int F_65 ( int V_151 )
{
switch ( V_151 ) {
case V_152 :
return 100 ;
case V_153 :
return 1000 ;
case V_154 :
return 10000 ;
default:
return 0 ;
}
}
static void F_66 ( struct V_19 * V_9 , int V_37 , int V_155 ,
int V_156 )
{
int V_157 , V_158 ;
T_2 V_159 ;
if ( V_155 != 0 ) {
V_158 = V_156 / V_155 ;
V_157 = ( V_156 - ( V_158 * V_155 ) ) ;
V_157 = ( V_157 * ( 1 << V_160 ) ) / V_155 ;
V_159 = V_161 ;
V_159 |= ( ( V_158 << V_160 ) &
V_162 ) ;
V_159 |= ( V_157 & V_163 ) ;
} else {
V_159 = 0 ;
}
F_16 ( V_9 , V_164 , 2 * V_37 ) ;
switch ( V_9 -> V_10 . type ) {
case V_11 :
F_16 ( V_9 , V_165 , 0x4 ) ;
break;
case V_13 :
F_16 ( V_9 , V_165 , 0x14 ) ;
break;
default:
break;
}
F_16 ( V_9 , V_166 , V_159 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_167 , V_22 ;
bool V_168 = false ;
if ( V_2 -> V_169 == 0 )
return;
V_167 = F_65 ( V_2 -> V_156 ) ;
if ( V_167 != V_2 -> V_169 ) {
V_168 = true ;
V_2 -> V_169 = 0 ;
F_62 ( & V_2 -> V_4 -> V_27 ,
L_29
L_30 ) ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_26 ; V_22 ++ ) {
if ( V_168 )
V_2 -> V_39 [ V_22 ] . V_155 = 0 ;
F_66 ( & V_2 -> V_9 , V_22 ,
V_2 -> V_39 [ V_22 ] . V_155 ,
V_167 ) ;
}
}
int F_68 ( struct V_144 * V_98 , int V_37 , int V_155 )
{
struct V_1 * V_2 = F_61 ( V_98 ) ;
struct V_19 * V_9 = & V_2 -> V_9 ;
int V_167 ;
V_167 = F_65 ( V_2 -> V_156 ) ;
if ( ( V_37 >= V_2 -> V_26 ) || ( ! V_2 -> V_170 ) ||
( V_155 > V_167 ) || ( V_167 != 10000 ) ||
( ( V_155 != 0 ) && ( V_155 <= 10 ) ) )
return - V_145 ;
V_2 -> V_169 = V_167 ;
V_2 -> V_39 [ V_37 ] . V_155 = ( T_1 ) V_155 ;
F_66 ( V_9 , V_37 , V_155 , V_167 ) ;
return 0 ;
}
int F_52 ( struct V_144 * V_98 , int V_37 , bool V_171 )
{
struct V_1 * V_2 = F_61 ( V_98 ) ;
int V_172 = V_37 >> 3 ;
int V_173 = V_37 % 8 ;
struct V_19 * V_9 = & V_2 -> V_9 ;
T_2 V_174 ;
V_2 -> V_39 [ V_37 ] . V_47 = V_171 ;
V_174 = F_15 ( V_9 , F_69 ( V_172 ) ) ;
V_174 &= ~ ( 1 << V_173 ) ;
V_174 |= ( V_171 << V_173 ) ;
F_16 ( V_9 , F_69 ( V_172 ) , V_174 ) ;
if ( V_2 -> V_39 [ V_37 ] . V_136 ) {
V_173 += V_175 ;
V_174 = F_15 ( V_9 , F_69 ( V_172 ) ) ;
V_174 &= ~ ( 1 << V_173 ) ;
V_174 |= ( V_171 << V_173 ) ;
F_16 ( V_9 , F_69 ( V_172 ) , V_174 ) ;
}
return 0 ;
}
int F_70 ( struct V_144 * V_98 ,
int V_37 , struct V_176 * V_177 )
{
struct V_1 * V_2 = F_61 ( V_98 ) ;
if ( V_37 >= V_2 -> V_26 )
return - V_145 ;
V_177 -> V_37 = V_37 ;
memcpy ( & V_177 -> V_10 , V_2 -> V_39 [ V_37 ] . V_101 , V_105 ) ;
V_177 -> V_155 = V_2 -> V_39 [ V_37 ] . V_155 ;
V_177 -> V_148 = V_2 -> V_39 [ V_37 ] . V_95 ;
V_177 -> V_149 = V_2 -> V_39 [ V_37 ] . V_96 ;
V_177 -> V_178 = V_2 -> V_39 [ V_37 ] . V_47 ;
return 0 ;
}
