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
if ( V_5 -> V_15 == V_6 &&
( V_5 -> V_17 -> V_18 >= V_4 -> V_17 -> V_18 ) )
V_8 ++ ;
V_6 += 2 ;
V_5 = F_2 ( V_16 ,
V_7 , V_5 ) ;
}
return V_8 ;
}
void F_3 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
int V_22 = 0 ;
int V_23 , V_24 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
V_27 = F_1 ( V_2 ) ;
if ( ! V_27 && ! V_2 -> V_28 )
return;
if ( V_27 ) {
V_2 -> V_28 = V_27 ;
F_4 ( & V_2 -> V_4 -> V_29 , L_1
L_2
L_3 ) ;
} else {
V_22 = F_5 ( V_2 -> V_4 , V_2 -> V_28 ) ;
}
if ( V_22 ) {
F_6 ( V_30 , L_4 , V_22 ) ;
goto V_31;
}
V_2 -> V_32 |= V_33 ;
F_7 ( V_30 , L_5 , V_2 -> V_28 ) ;
V_23 = V_9 -> V_10 . V_34 -
( V_35 + 1 + V_2 -> V_28 ) ;
V_2 -> V_26 = V_26 = F_8 ( V_23 ,
sizeof( struct V_25 ) ,
V_36 ) ;
if ( V_26 ) {
F_9 ( & V_2 -> V_37 . V_38 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
V_26 -> V_39 = - 1 ;
V_26 -> free = true ;
V_26 -> V_40 = V_9 -> V_10 . V_34 -
( V_24 + V_2 -> V_28 + 1 ) ;
F_10 ( & V_26 -> V_38 , & V_2 -> V_37 . V_38 ) ;
V_26 ++ ;
}
}
V_2 -> V_41 =
F_8 ( V_2 -> V_28 ,
sizeof( struct V_42 ) , V_36 ) ;
if ( V_2 -> V_41 ) {
F_11 ( V_9 ) ;
memcpy ( & V_9 -> V_43 . V_44 , V_20 -> V_45 ,
sizeof( V_9 -> V_43 . V_44 ) ) ;
V_2 -> V_46 &= ~ ( V_47 |
V_48 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_28 ; V_24 ++ )
V_2 -> V_41 [ V_24 ] . V_49 = true ;
return;
}
F_6 ( V_30 , L_6
L_7 ) ;
F_12 ( V_2 -> V_4 ) ;
V_31:
V_2 -> V_32 &= ~ V_33 ;
V_2 -> V_28 = 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
T_2 V_50 ;
T_2 V_51 ;
T_2 V_52 ;
int V_24 ;
#ifdef F_14
F_12 ( V_2 -> V_4 ) ;
#endif
V_50 = F_15 ( V_9 , V_53 ) ;
V_50 &= ~ ( V_54 ) ;
F_16 ( V_9 , V_53 , V_50 ) ;
V_51 = F_15 ( V_9 , V_55 ) ;
V_51 &= ~ V_56 ;
F_16 ( V_9 , V_55 , V_51 ) ;
V_52 = F_15 ( V_9 , V_57 ) ;
V_52 &= ~ V_58 ;
F_16 ( V_9 , V_57 , V_52 ) ;
F_17 ( V_9 ) ;
F_18 ( 100 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_28 ; V_24 ++ ) {
if ( V_2 -> V_41 [ V_24 ] . V_59 )
F_19 ( V_2 -> V_41 [ V_24 ] . V_59 ) ;
}
F_20 ( V_2 -> V_41 ) ;
F_20 ( V_2 -> V_26 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_28 = 0 ;
V_2 -> V_32 &= ~ V_33 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_60 , T_1 * V_61 , T_2 V_39 )
{
struct V_42 * V_41 = & V_2 -> V_41 [ V_39 ] ;
struct V_21 * V_9 = & V_2 -> V_9 ;
int V_24 ;
T_2 V_62 ;
T_2 V_63 ;
T_2 V_64 ;
V_60 = F_22 ( V_60 , V_65 ) ;
V_41 -> V_66 = V_60 ;
for ( V_24 = 0 ; V_24 < V_60 ; V_24 ++ ) {
V_41 -> V_67 [ V_24 ] = V_61 [ V_24 ] ;
}
for ( V_24 = 0 ; V_24 < V_41 -> V_66 ; V_24 ++ ) {
V_63 = ( V_41 -> V_67 [ V_24 ] >> 5 ) & 0x7F ;
V_62 = V_41 -> V_67 [ V_24 ] & 0x1F ;
V_64 = F_15 ( V_9 , F_23 ( V_63 ) ) ;
V_64 |= ( 1 << V_62 ) ;
F_16 ( V_9 , F_23 ( V_63 ) , V_64 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
struct V_68 * V_69 ;
struct V_25 * V_70 ;
F_25 (pos, &adapter->vf_mvs.l) {
V_70 = F_26 ( V_69 , struct V_25 , V_38 ) ;
if ( V_70 -> free == false )
V_9 -> V_10 . V_44 . V_71 ( V_9 , V_70 -> V_40 ,
V_70 -> V_72 ,
V_70 -> V_39 , V_73 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
struct V_42 * V_41 ;
int V_24 , V_74 ;
T_2 V_62 ;
T_2 V_63 ;
T_2 V_64 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_28 ; V_24 ++ ) {
V_41 = & V_2 -> V_41 [ V_24 ] ;
for ( V_74 = 0 ; V_74 < V_41 -> V_66 ; V_74 ++ ) {
V_9 -> V_75 . V_76 ++ ;
V_63 = ( V_41 -> V_67 [ V_74 ] >> 5 ) & 0x7F ;
V_62 = V_41 -> V_67 [ V_74 ] & 0x1F ;
V_64 = F_15 ( V_9 , F_23 ( V_63 ) ) ;
V_64 |= ( 1 << V_62 ) ;
F_16 ( V_9 , F_23 ( V_63 ) , V_64 ) ;
}
}
F_24 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_77 , int V_78 ,
T_2 V_39 )
{
return V_2 -> V_9 . V_10 . V_44 . V_79 ( & V_2 -> V_9 , V_78 , V_39 , ( bool ) V_77 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_80 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
int V_81 = V_80 [ 1 ] ;
T_2 V_82 ;
int V_83 = V_81 + V_84 + V_85 ;
if ( V_2 -> V_9 . V_10 . type != V_13 )
return;
if ( ( V_81 < 68 ) || ( V_83 > V_86 ) ) {
F_6 ( V_87 , L_8 , V_81 ) ;
return;
}
V_82 = ( F_15 ( V_9 , V_88 ) &
V_89 ) >> V_90 ;
if ( V_82 < V_81 ) {
V_82 = V_81 << V_90 ;
F_16 ( V_9 , V_88 , V_82 ) ;
}
F_7 ( V_9 , L_9 , V_81 ) ;
}
static void F_30 ( struct V_21 * V_9 , T_2 V_39 , bool V_91 )
{
T_2 V_92 = F_15 ( V_9 , F_31 ( V_39 ) ) ;
V_92 |= ( V_93 |
V_94 ) ;
if ( V_91 )
V_92 |= V_95 ;
else
V_92 &= ~ V_95 ;
F_16 ( V_9 , F_31 ( V_39 ) , V_92 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_78 , T_2 V_39 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
if ( V_78 )
F_16 ( V_9 , F_33 ( V_39 ) ,
( V_78 | V_96 ) ) ;
else
F_16 ( V_9 , F_33 ( V_39 ) , 0 ) ;
}
static inline void F_34 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
int V_40 = V_9 -> V_10 . V_34 - ( V_39 + 1 ) ;
if ( V_2 -> V_41 [ V_39 ] . V_97 ) {
F_28 ( V_2 , true ,
V_2 -> V_41 [ V_39 ] . V_97 , V_39 ) ;
F_32 ( V_2 ,
( V_2 -> V_41 [ V_39 ] . V_97 |
( V_2 -> V_41 [ V_39 ] . V_98 <<
V_99 ) ) , V_39 ) ;
F_30 ( V_9 , V_39 , false ) ;
} else {
F_32 ( V_2 , 0 , V_39 ) ;
F_30 ( V_9 , V_39 , true ) ;
}
V_2 -> V_41 [ V_39 ] . V_66 = 0 ;
F_35 ( V_2 -> V_100 ) ;
V_9 -> V_10 . V_44 . V_101 ( V_9 , V_40 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_39 , unsigned char * V_102 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
int V_40 = V_9 -> V_10 . V_34 - ( V_39 + 1 ) ;
memcpy ( V_2 -> V_41 [ V_39 ] . V_103 , V_102 , 6 ) ;
V_9 -> V_10 . V_44 . V_71 ( V_9 , V_40 , V_102 , V_39 , V_73 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
int V_39 , int V_104 , unsigned char * V_102 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
struct V_68 * V_69 ;
struct V_25 * V_70 ;
if ( V_104 <= 1 ) {
F_25 (pos, &adapter->vf_mvs.l) {
V_70 = F_26 ( V_69 , struct V_25 , V_38 ) ;
if ( V_70 -> V_39 == V_39 ) {
V_70 -> V_39 = - 1 ;
V_70 -> free = true ;
V_70 -> V_105 = false ;
V_9 -> V_10 . V_44 . V_101 ( V_9 , V_70 -> V_40 ) ;
}
}
}
if ( ! V_104 )
return 0 ;
V_70 = NULL ;
F_25 (pos, &adapter->vf_mvs.l) {
V_70 = F_26 ( V_69 , struct V_25 , V_38 ) ;
if ( V_70 -> free )
break;
}
if ( ! V_70 || ! V_70 -> free )
return - V_106 ;
V_70 -> free = false ;
V_70 -> V_105 = true ;
V_70 -> V_39 = V_39 ;
memcpy ( V_70 -> V_72 , V_102 , V_107 ) ;
V_9 -> V_10 . V_44 . V_71 ( V_9 , V_70 -> V_40 , V_102 , V_39 , V_73 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
#ifdef F_14
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_28 ; V_24 ++ ) {
if ( V_2 -> V_41 [ V_24 ] . V_59 -> V_108 &
V_109 )
return true ;
}
#endif
return false ;
}
int F_39 ( struct V_3 * V_4 , unsigned int V_110 )
{
unsigned char V_111 [ 6 ] ;
struct V_1 * V_2 = F_40 ( V_4 ) ;
unsigned int V_112 = ( V_110 & 0x3f ) ;
struct V_3 * V_5 ;
unsigned int V_7 ;
T_1 V_113 = ( V_4 -> V_15 + 0x80 + ( V_112 << 1 ) ) |
( V_4 -> V_15 & 1 ) ;
bool V_114 = ( ( V_110 & 0x10000000U ) != 0 ) ;
if ( V_114 ) {
F_41 ( V_111 ) ;
F_7 ( V_30 , L_10 ,
V_112 , V_111 ) ;
memcpy ( V_2 -> V_41 [ V_112 ] . V_103 , V_111 , 6 ) ;
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
if ( V_5 -> V_15 == V_113 )
break;
V_5 = F_2 ( V_16 ,
V_7 , V_5 ) ;
}
if ( V_5 )
V_2 -> V_41 [ V_112 ] . V_59 = V_5 ;
else
F_6 ( V_87 , L_11 ,
V_113 ) ;
}
return 0 ;
}
static inline void F_42 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
T_2 V_115 ;
T_2 V_116 , V_117 ;
V_117 = V_39 % 32 ;
V_116 = V_39 / 32 ;
V_115 = F_15 ( V_9 , F_43 ( V_116 ) ) ;
V_115 |= ( V_115 | ( 1 << V_117 ) ) ;
F_16 ( V_9 , F_43 ( V_116 ) , V_115 ) ;
V_115 = F_15 ( V_9 , F_44 ( V_116 ) ) ;
V_115 |= ( V_115 | ( 1 << V_117 ) ) ;
F_16 ( V_9 , F_44 ( V_116 ) , V_115 ) ;
V_115 = F_15 ( V_9 , F_45 ( V_116 ) ) ;
V_115 |= ( 1 << V_117 ) ;
F_16 ( V_9 , F_45 ( V_116 ) , V_115 ) ;
F_34 ( V_2 , V_39 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_39 )
{
T_2 V_118 = V_119 ;
T_2 V_80 [ V_119 ] ;
struct V_21 * V_9 = & V_2 -> V_9 ;
T_3 V_120 ;
int V_60 ;
T_1 * V_61 ;
int V_77 , V_78 , V_104 ;
T_4 * V_121 ;
V_120 = F_47 ( V_9 , V_80 , V_118 , V_39 ) ;
if ( V_120 )
F_48 ( L_12 ) ;
if ( V_80 [ 0 ] & ( V_122 | V_123 ) )
return V_120 ;
if ( V_80 [ 0 ] == V_124 ) {
unsigned char * V_125 = V_2 -> V_41 [ V_39 ] . V_103 ;
V_121 = ( T_4 * ) ( & V_80 [ 1 ] ) ;
F_7 ( V_30 , L_13 , V_39 ) ;
V_2 -> V_41 [ V_39 ] . V_126 = false ;
F_42 ( V_2 , V_39 ) ;
V_2 -> V_41 [ V_39 ] . V_126 = true ;
if ( F_49 ( V_121 ) &&
! V_2 -> V_41 [ V_39 ] . V_127 )
F_36 ( V_2 , V_39 , V_125 ) ;
else
F_36 ( V_2 ,
V_39 , V_2 -> V_41 [ V_39 ] . V_103 ) ;
V_80 [ 0 ] = V_124 | V_122 ;
memcpy ( V_121 , V_125 , V_107 ) ;
V_80 [ 3 ] = V_9 -> V_10 . V_128 ;
F_50 ( V_9 , V_80 , V_129 , V_39 ) ;
return V_120 ;
}
if ( ! V_2 -> V_41 [ V_39 ] . V_126 ) {
V_80 [ 0 ] |= V_123 ;
F_50 ( V_9 , V_80 , 1 , V_39 ) ;
return V_120 ;
}
switch ( ( V_80 [ 0 ] & 0xFFFF ) ) {
case V_130 :
V_121 = ( ( T_4 * ) ( & V_80 [ 1 ] ) ) ;
if ( F_49 ( V_121 ) &&
! V_2 -> V_41 [ V_39 ] . V_127 ) {
F_36 ( V_2 , V_39 , V_121 ) ;
} else if ( memcmp ( V_2 -> V_41 [ V_39 ] . V_103 ,
V_121 , V_107 ) ) {
F_51 ( V_87 , L_14
L_15
L_16 , V_39 ) ;
V_120 = - 1 ;
}
break;
case V_131 :
V_60 = ( V_80 [ 0 ] & V_132 )
>> V_133 ;
V_61 = ( T_1 * ) & V_80 [ 1 ] ;
V_120 = F_21 ( V_2 , V_60 ,
V_61 , V_39 ) ;
break;
case V_134 :
F_29 ( V_2 , V_80 ) ;
break;
case V_135 :
V_77 = ( V_80 [ 0 ] & V_132 )
>> V_133 ;
V_78 = ( V_80 [ 1 ] & V_136 ) ;
if ( V_2 -> V_41 [ V_39 ] . V_97 ) {
F_51 ( V_87 , L_14
L_17
L_18 ,
V_39 ) ;
V_120 = - 1 ;
} else {
if ( V_77 )
V_2 -> V_41 [ V_39 ] . V_137 ++ ;
else if ( V_2 -> V_41 [ V_39 ] . V_137 )
V_2 -> V_41 [ V_39 ] . V_137 -- ;
V_120 = F_28 ( V_2 , V_77 , V_78 , V_39 ) ;
if ( ! V_120 && V_2 -> V_41 [ V_39 ] . V_49 )
V_9 -> V_10 . V_44 . V_138 ( V_9 , true , V_39 ) ;
}
break;
case V_139 :
V_104 = ( V_80 [ 0 ] & V_132 ) >>
V_133 ;
if ( V_104 > 0 && V_2 -> V_41 [ V_39 ] . V_49 )
F_52 ( V_2 -> V_100 , V_39 , false ) ;
V_120 = F_37 ( V_2 , V_39 , V_104 ,
( unsigned char * ) ( & V_80 [ 1 ] ) ) ;
if ( V_120 == - V_106 )
F_51 ( V_87 , L_19
L_20 , V_39 ) ;
break;
default:
F_6 ( V_87 , L_21 , V_80 [ 0 ] ) ;
V_120 = V_140 ;
break;
}
if ( V_120 )
V_80 [ 0 ] |= V_123 ;
else
V_80 [ 0 ] |= V_122 ;
V_80 [ 0 ] |= V_141 ;
F_50 ( V_9 , V_80 , 1 , V_39 ) ;
return V_120 ;
}
static void F_53 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
T_2 V_142 = V_123 ;
if ( ! V_2 -> V_41 [ V_39 ] . V_126 )
F_50 ( V_9 , & V_142 , 1 , V_39 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
T_2 V_39 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_28 ; V_39 ++ ) {
if ( ! F_55 ( V_9 , V_39 ) )
F_34 ( V_2 , V_39 ) ;
if ( ! F_56 ( V_9 , V_39 ) )
F_46 ( V_2 , V_39 ) ;
if ( ! F_57 ( V_9 , V_39 ) )
F_53 ( V_2 , V_39 ) ;
}
}
void F_58 ( struct V_1 * V_2 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
F_16 ( V_9 , F_43 ( 0 ) , 0 ) ;
F_16 ( V_9 , F_43 ( 1 ) , 0 ) ;
F_16 ( V_9 , F_44 ( 0 ) , 0 ) ;
F_16 ( V_9 , F_44 ( 1 ) , 0 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_21 * V_9 = & V_2 -> V_9 ;
T_2 V_143 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_28 ; V_24 ++ ) {
V_143 = V_144 ;
if ( V_2 -> V_41 [ V_24 ] . V_126 )
V_143 |= V_141 ;
F_50 ( V_9 , & V_143 , 1 , V_24 ) ;
}
}
int F_60 ( struct V_145 * V_100 , int V_39 , T_4 * V_10 )
{
struct V_1 * V_2 = F_61 ( V_100 ) ;
if ( ! F_49 ( V_10 ) || ( V_39 >= V_2 -> V_28 ) )
return - V_146 ;
V_2 -> V_41 [ V_39 ] . V_127 = true ;
F_62 ( & V_2 -> V_4 -> V_29 , L_22 , V_10 , V_39 ) ;
F_62 ( & V_2 -> V_4 -> V_29 , L_23
L_24 ) ;
if ( F_63 ( V_147 , & V_2 -> V_148 ) ) {
F_4 ( & V_2 -> V_4 -> V_29 , L_25
L_26 ) ;
F_4 ( & V_2 -> V_4 -> V_29 , L_27
L_28 ) ;
}
return F_36 ( V_2 , V_39 , V_10 ) ;
}
int F_64 ( struct V_145 * V_100 , int V_39 , T_1 V_149 , T_4 V_150 )
{
int V_22 = 0 ;
struct V_1 * V_2 = F_61 ( V_100 ) ;
struct V_21 * V_9 = & V_2 -> V_9 ;
if ( ( V_39 >= V_2 -> V_28 ) || ( V_149 > 4095 ) || ( V_150 > 7 ) )
return - V_146 ;
if ( V_149 || V_150 ) {
V_22 = F_28 ( V_2 , true , V_149 , V_39 ) ;
if ( V_22 )
goto V_151;
F_32 ( V_2 , V_149 | ( V_150 << V_99 ) , V_39 ) ;
F_30 ( V_9 , V_39 , false ) ;
if ( V_2 -> V_41 [ V_39 ] . V_49 )
V_9 -> V_10 . V_44 . V_138 ( V_9 , true , V_39 ) ;
V_2 -> V_41 [ V_39 ] . V_137 ++ ;
V_2 -> V_41 [ V_39 ] . V_97 = V_149 ;
V_2 -> V_41 [ V_39 ] . V_98 = V_150 ;
F_62 ( & V_2 -> V_4 -> V_29 ,
L_29 , V_149 , V_150 , V_39 ) ;
if ( F_63 ( V_147 , & V_2 -> V_148 ) ) {
F_4 ( & V_2 -> V_4 -> V_29 ,
L_30
L_26 ) ;
F_4 ( & V_2 -> V_4 -> V_29 ,
L_27
L_28 ) ;
}
} else {
V_22 = F_28 ( V_2 , false ,
V_2 -> V_41 [ V_39 ] . V_97 , V_39 ) ;
F_32 ( V_2 , V_149 , V_39 ) ;
F_30 ( V_9 , V_39 , true ) ;
V_9 -> V_10 . V_44 . V_138 ( V_9 , false , V_39 ) ;
if ( V_2 -> V_41 [ V_39 ] . V_137 )
V_2 -> V_41 [ V_39 ] . V_137 -- ;
V_2 -> V_41 [ V_39 ] . V_97 = 0 ;
V_2 -> V_41 [ V_39 ] . V_98 = 0 ;
}
V_151:
return V_22 ;
}
static int F_65 ( int V_152 )
{
switch ( V_152 ) {
case V_153 :
return 100 ;
case V_154 :
return 1000 ;
case V_155 :
return 10000 ;
default:
return 0 ;
}
}
static void F_66 ( struct V_21 * V_9 , int V_39 , int V_156 ,
int V_157 )
{
int V_158 , V_159 ;
T_2 V_160 ;
if ( V_156 != 0 ) {
V_159 = V_157 / V_156 ;
V_158 = ( V_157 - ( V_159 * V_156 ) ) ;
V_158 = ( V_158 * ( 1 << V_161 ) ) / V_156 ;
V_160 = V_162 ;
V_160 |= ( ( V_159 << V_161 ) &
V_163 ) ;
V_160 |= ( V_158 & V_164 ) ;
} else {
V_160 = 0 ;
}
F_16 ( V_9 , V_165 , 2 * V_39 ) ;
switch ( V_9 -> V_10 . type ) {
case V_11 :
F_16 ( V_9 , V_166 , 0x4 ) ;
break;
case V_13 :
F_16 ( V_9 , V_166 , 0x14 ) ;
break;
default:
break;
}
F_16 ( V_9 , V_167 , V_160 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_168 , V_24 ;
bool V_169 = false ;
if ( V_2 -> V_170 == 0 )
return;
V_168 = F_65 ( V_2 -> V_157 ) ;
if ( V_168 != V_2 -> V_170 ) {
V_169 = true ;
V_2 -> V_170 = 0 ;
F_62 ( & V_2 -> V_4 -> V_29 ,
L_31
L_32 ) ;
}
for ( V_24 = 0 ; V_24 < V_2 -> V_28 ; V_24 ++ ) {
if ( V_169 )
V_2 -> V_41 [ V_24 ] . V_156 = 0 ;
F_66 ( & V_2 -> V_9 , V_24 ,
V_2 -> V_41 [ V_24 ] . V_156 ,
V_168 ) ;
}
}
int F_68 ( struct V_145 * V_100 , int V_39 , int V_156 )
{
struct V_1 * V_2 = F_61 ( V_100 ) ;
struct V_21 * V_9 = & V_2 -> V_9 ;
int V_168 ;
V_168 = F_65 ( V_2 -> V_157 ) ;
if ( ( V_39 >= V_2 -> V_28 ) || ( ! V_2 -> V_171 ) ||
( V_156 > V_168 ) || ( V_168 != 10000 ) ||
( ( V_156 != 0 ) && ( V_156 <= 10 ) ) )
return - V_146 ;
V_2 -> V_170 = V_168 ;
V_2 -> V_41 [ V_39 ] . V_156 = ( T_1 ) V_156 ;
F_66 ( V_9 , V_39 , V_156 , V_168 ) ;
return 0 ;
}
int F_52 ( struct V_145 * V_100 , int V_39 , bool V_172 )
{
struct V_1 * V_2 = F_61 ( V_100 ) ;
int V_173 = V_39 >> 3 ;
int V_174 = V_39 % 8 ;
struct V_21 * V_9 = & V_2 -> V_9 ;
T_2 V_175 ;
V_2 -> V_41 [ V_39 ] . V_49 = V_172 ;
V_175 = F_15 ( V_9 , F_69 ( V_173 ) ) ;
V_175 &= ~ ( 1 << V_174 ) ;
V_175 |= ( V_172 << V_174 ) ;
F_16 ( V_9 , F_69 ( V_173 ) , V_175 ) ;
if ( V_2 -> V_41 [ V_39 ] . V_137 ) {
V_174 += V_176 ;
V_175 = F_15 ( V_9 , F_69 ( V_173 ) ) ;
V_175 &= ~ ( 1 << V_174 ) ;
V_175 |= ( V_172 << V_174 ) ;
F_16 ( V_9 , F_69 ( V_173 ) , V_175 ) ;
}
return 0 ;
}
int F_70 ( struct V_145 * V_100 ,
int V_39 , struct V_177 * V_178 )
{
struct V_1 * V_2 = F_61 ( V_100 ) ;
if ( V_39 >= V_2 -> V_28 )
return - V_146 ;
V_178 -> V_39 = V_39 ;
memcpy ( & V_178 -> V_10 , V_2 -> V_41 [ V_39 ] . V_103 , V_107 ) ;
V_178 -> V_156 = V_2 -> V_41 [ V_39 ] . V_156 ;
V_178 -> V_149 = V_2 -> V_41 [ V_39 ] . V_97 ;
V_178 -> V_150 = V_2 -> V_41 [ V_39 ] . V_98 ;
V_178 -> V_179 = V_2 -> V_41 [ V_39 ] . V_49 ;
return 0 ;
}
