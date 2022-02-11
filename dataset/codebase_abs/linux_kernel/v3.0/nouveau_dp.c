static int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_10 * V_11 ;
int V_12 ;
V_11 = F_2 ( V_7 , V_9 -> V_13 -> V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_12 = F_3 ( V_11 , 9 , V_3 , V_4 , V_5 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_10 * V_11 ;
int V_12 ;
V_11 = F_2 ( V_7 , V_9 -> V_13 -> V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_12 = F_3 ( V_11 , 8 , V_3 , V_4 , V_5 ) ;
return V_12 ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_2 V_17 ;
int V_18 = V_9 -> V_18 , V_19 = ! ( V_9 -> V_13 -> V_20 . V_19 & 1 ) ;
V_17 = F_6 ( V_7 , F_7 ( V_18 , V_19 ) ) ;
V_17 &= ~ ( V_21 |
V_22 ) ;
V_17 |= ( ( 1 << ( V_16 & V_23 ) ) - 1 ) << 16 ;
if ( V_16 & V_24 )
V_17 |= V_21 ;
F_8 ( V_7 , F_7 ( V_18 , V_19 ) , V_17 ) ;
return F_4 ( V_2 , V_25 , & V_16 , 1 ) ;
}
static int
F_9 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_2 V_17 ;
int V_26 = 0x614300 + ( V_9 -> V_18 * 0x800 ) ;
V_17 = F_6 ( V_7 , V_26 ) ;
V_17 &= 0xfff3ffff ;
if ( V_16 == V_27 )
V_17 |= 0x00040000 ;
F_8 ( V_7 , V_26 , V_17 ) ;
return F_4 ( V_2 , V_28 , & V_16 , 1 ) ;
}
static int
F_10 ( struct V_1 * V_2 , int V_29 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_2 V_17 ;
T_1 V_16 ;
int V_18 = V_9 -> V_18 , V_19 = ! ( V_9 -> V_13 -> V_20 . V_19 & 1 ) ;
int V_12 ;
V_17 = F_6 ( V_7 , F_7 ( V_18 , V_19 ) ) ;
V_17 &= ~ V_30 ;
V_17 |= ( V_29 << 24 ) ;
F_8 ( V_7 , F_7 ( V_18 , V_19 ) , V_17 ) ;
V_12 = F_1 ( V_2 , V_31 , & V_16 , 1 ) ;
if ( V_12 )
return V_12 ;
V_16 &= ~ V_32 ;
V_16 |= ( V_29 & V_32 ) ;
return F_4 ( V_2 , V_31 , & V_16 , 1 ) ;
}
static int
F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_37 , V_38 , V_39 = 0 ;
V_36 = F_12 ( V_7 , V_9 -> V_13 , & V_38 ) ;
if ( ! V_36 )
return false ;
V_34 = ( void * ) ( ( char * ) V_36 + V_38 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ , V_34 ++ ) {
if ( V_34 -> V_40 > V_39 )
V_39 = V_34 -> V_40 ;
}
return V_39 ;
}
static int
F_13 ( struct V_1 * V_2 , int V_41 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_37 , V_38 , V_42 = 0 ;
V_36 = F_12 ( V_7 , V_9 -> V_13 , & V_38 ) ;
if ( ! V_36 )
return false ;
V_34 = ( void * ) ( ( char * ) V_36 + V_38 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ , V_34 ++ ) {
if ( V_34 -> V_40 != V_41 )
continue;
if ( V_34 -> V_43 > V_42 )
V_42 = V_34 -> V_43 ;
}
return V_42 ;
}
static bool
F_14 ( struct V_1 * V_2 , T_1 * V_44 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_35 * V_36 ;
int V_12 , V_37 , V_38 , V_41 = 0 , V_45 = 0 ;
T_1 V_46 [ 2 ] ;
V_36 = F_12 ( V_7 , V_9 -> V_13 , & V_38 ) ;
if ( ! V_36 )
return false ;
V_12 = F_1 ( V_2 , V_47 , V_46 , 2 ) ;
if ( V_12 )
return false ;
F_15 ( V_7 , L_1 , V_46 [ 0 ] , V_46 [ 1 ] ) ;
for ( V_37 = 0 ; V_37 < V_9 -> V_48 . V_49 ; V_37 ++ ) {
int V_50 = ( V_46 [ V_37 >> 1 ] >> ( ( V_37 & 1 ) << 2 ) ) & 0xf ;
int V_51 = V_50 & 3 ;
int V_52 = ( V_50 >> 2 ) & 3 ;
if ( V_51 > V_41 )
V_41 = V_51 ;
if ( V_52 > V_45 )
V_45 = V_52 ;
}
if ( V_41 >= F_11 ( V_2 ) ) {
V_41 = F_11 ( V_2 ) ;
V_41 |= 4 ;
}
if ( V_45 >= F_13 ( V_2 , V_41 & 3 ) ) {
V_45 = F_13 ( V_2 , V_41 & 3 ) ;
V_45 |= 4 ;
}
for ( V_37 = 0 ; V_37 < V_9 -> V_48 . V_49 ; V_37 ++ )
V_44 [ V_37 ] = ( V_45 << 3 ) | V_41 ;
return true ;
}
static bool
F_16 ( struct V_1 * V_2 , T_1 * V_44 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_18 = V_9 -> V_18 , V_19 = ! ( V_9 -> V_13 -> V_20 . V_19 & 1 ) ;
int V_38 , V_12 , V_37 ;
F_15 ( V_7 , L_2 ,
V_44 [ 0 ] , V_44 [ 1 ] , V_44 [ 2 ] , V_44 [ 3 ] ) ;
V_36 = F_12 ( V_7 , V_9 -> V_13 , & V_38 ) ;
if ( ! V_36 )
return false ;
V_34 = ( void * ) ( ( char * ) V_36 + V_38 ) ;
for ( V_37 = 0 ; V_37 < V_36 -> V_53 ; V_37 ++ , V_34 ++ ) {
if ( V_34 -> V_40 == ( V_44 [ 0 ] & 3 ) &&
V_34 -> V_43 == ( ( V_44 [ 0 ] >> 3 ) & 3 ) )
break;
}
F_17 ( V_37 == V_36 -> V_53 ) ;
for ( V_37 = 0 ; V_37 < V_9 -> V_48 . V_49 ; V_37 ++ ) {
const int V_54 [ 4 ] = { 16 , 8 , 0 , 24 } ;
T_2 V_55 = 0xff << V_54 [ V_37 ] ;
T_2 V_56 , V_57 , V_58 ;
V_56 = F_6 ( V_7 , F_18 ( V_18 , V_19 ) ) & ~ V_55 ;
V_56 |= ( V_34 -> V_56 << V_54 [ V_37 ] ) ;
V_57 = F_6 ( V_7 , F_19 ( V_18 , V_19 ) ) & ~ V_55 ;
V_57 |= ( V_34 -> V_57 << V_54 [ V_37 ] ) ;
V_58 = F_6 ( V_7 , F_20 ( V_18 , V_19 ) ) & 0xffff00ff ;
V_58 |= ( V_34 -> V_58 << 8 ) ;
F_8 ( V_7 , F_18 ( V_18 , V_19 ) , V_56 ) ;
F_8 ( V_7 , F_19 ( V_18 , V_19 ) , V_57 ) ;
F_8 ( V_7 , F_20 ( V_18 , V_19 ) , V_58 ) ;
}
V_12 = F_4 ( V_2 , V_59 , V_44 , 4 ) ;
if ( V_12 )
return false ;
return true ;
}
bool
F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_60 * V_61 = V_7 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_65 . V_66 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_67 * V_68 ;
struct V_35 * V_36 ;
int V_38 ;
T_1 V_44 [ 4 ] , V_69 [ 3 ] ;
bool V_70 , V_71 , V_72 , V_73 ;
int V_12 = 0 , V_37 , V_74 , V_75 ;
F_15 ( V_7 , L_3 ) ;
V_68 = F_22 ( V_9 ) ;
if ( ! V_68 )
return false ;
V_36 = F_12 ( V_7 , V_9 -> V_13 , & V_38 ) ;
if ( ! V_36 ) {
F_23 ( V_7 , L_4 , V_9 -> V_18 ) ;
return false ;
}
V_73 = V_64 -> V_76 ( V_7 , V_68 -> V_13 -> V_77 , false ) ;
if ( V_36 -> V_78 ) {
F_15 ( V_7 , L_5 , V_9 -> V_18 ) ;
F_24 ( V_7 , F_25 ( V_36 -> V_78 ) ,
V_9 -> V_13 ) ;
}
V_79:
V_70 = V_72 = false ;
F_15 ( V_7 , L_6 ,
V_9 -> V_48 . V_80 , V_9 -> V_48 . V_49 ) ;
V_12 = F_9 ( V_2 , V_9 -> V_48 . V_80 ) ;
if ( V_12 )
return false ;
V_44 [ 0 ] = V_9 -> V_48 . V_49 ;
if ( V_9 -> V_48 . V_81 >= 0x11 &&
V_9 -> V_48 . V_82 )
V_44 [ 0 ] |= V_24 ;
V_12 = F_5 ( V_2 , V_44 [ 0 ] ) ;
if ( V_12 )
return false ;
F_15 ( V_7 , L_7 ) ;
V_12 = F_10 ( V_2 , V_83 ) ;
if ( V_12 )
goto V_84;
V_74 = 0 ;
V_75 = - 1 ;
memset ( V_44 , 0x00 , sizeof( V_44 ) ) ;
for (; ; ) {
if ( ! F_16 ( V_2 , V_44 ) )
break;
F_26 ( 100 ) ;
V_12 = F_1 ( V_2 , V_85 , V_69 , 2 ) ;
if ( V_12 )
break;
F_15 ( V_7 , L_8 ,
V_69 [ 0 ] , V_69 [ 1 ] ) ;
V_70 = true ;
V_71 = false ;
for ( V_37 = 0 ; V_37 < V_9 -> V_48 . V_49 ; V_37 ++ ) {
int V_86 = ( V_69 [ V_37 >> 1 ] >> ( ( V_37 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_86 & V_87 ) ) {
V_70 = false ;
if ( V_44 [ V_37 ] & V_88 )
V_71 = true ;
break;
}
}
if ( ( V_44 [ 0 ] & V_89 ) != V_75 ) {
V_75 = V_44 [ 0 ] & V_89 ;
V_74 = 0 ;
}
if ( V_70 || V_71 || ( ++ V_74 == 5 ) )
break;
if ( ! F_14 ( V_2 , V_44 ) )
break;
}
if ( ! V_70 )
goto V_84;
F_15 ( V_7 , L_9 ) ;
V_12 = F_10 ( V_2 , V_90 ) ;
if ( V_12 )
goto V_84;
for ( V_74 = 0 ; V_74 <= 5 ; V_74 ++ ) {
F_26 ( 400 ) ;
V_12 = F_1 ( V_2 , V_85 , V_69 , 3 ) ;
if ( V_12 )
break;
F_15 ( V_7 , L_8 ,
V_69 [ 0 ] , V_69 [ 1 ] ) ;
V_72 = true ;
if ( ! ( V_69 [ 2 ] & V_91 ) )
V_72 = false ;
for ( V_37 = 0 ; V_72 && V_37 < V_9 -> V_48 . V_49 ; V_37 ++ ) {
int V_86 = ( V_69 [ V_37 >> 1 ] >> ( ( V_37 & 1 ) * 4 ) ) & 0xf ;
if ( ! ( V_86 & V_87 ) ) {
V_70 = false ;
break;
}
if ( ! ( V_86 & V_92 ) ||
! ( V_86 & V_93 ) ) {
V_72 = false ;
break;
}
}
if ( V_72 || ! V_70 )
break;
if ( ! F_14 ( V_2 , V_44 ) ||
! F_16 ( V_2 , V_44 ) )
break;
}
V_84:
V_12 = F_10 ( V_2 , V_94 ) ;
if ( V_12 )
return false ;
if ( ! V_12 && ! ( V_72 && V_70 ) ) {
F_15 ( V_7 , L_10 ) ;
if ( V_9 -> V_48 . V_80 != V_95 ) {
F_15 ( V_7 , L_11 ) ;
V_9 -> V_48 . V_80 = V_95 ;
goto V_79;
}
}
if ( V_36 -> V_96 ) {
F_15 ( V_7 , L_12 , V_9 -> V_18 ) ;
F_24 ( V_7 , F_25 ( V_36 -> V_96 ) ,
V_9 -> V_13 ) ;
}
V_64 -> V_76 ( V_7 , V_68 -> V_13 -> V_77 , V_73 ) ;
return V_72 ;
}
bool
F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_97 [ 4 ] ;
int V_12 ;
V_12 = F_1 ( V_2 , 0x0000 , V_97 , 4 ) ;
if ( V_12 )
return false ;
F_15 ( V_7 , L_13
L_14 ,
V_9 -> V_13 -> V_98 . V_80 ,
V_9 -> V_13 -> V_98 . V_49 ,
V_97 [ 1 ] , V_97 [ 2 ] & 0x0f , V_97 [ 0 ] ) ;
V_9 -> V_48 . V_81 = V_97 [ 0 ] ;
V_9 -> V_48 . V_80 = V_97 [ 1 ] ;
if ( V_9 -> V_48 . V_80 != V_95 &&
! V_9 -> V_13 -> V_98 . V_80 )
V_9 -> V_48 . V_80 = V_95 ;
V_9 -> V_48 . V_49 = V_97 [ 2 ] & V_99 ;
if ( V_9 -> V_48 . V_49 > V_9 -> V_13 -> V_98 . V_49 )
V_9 -> V_48 . V_49 = V_9 -> V_13 -> V_98 . V_49 ;
V_9 -> V_48 . V_82 = ( V_97 [ 2 ] & V_100 ) ;
return true ;
}
int
F_3 ( struct V_10 * V_11 , int V_16 , int V_101 ,
T_1 * V_102 , int V_103 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_2 V_17 , V_104 , V_105 = 0 , V_106 [ 4 ] = {} ;
int V_12 = 0 , V_37 , V_107 = V_11 -> V_108 ;
F_15 ( V_7 , L_15 , V_107 , V_16 , V_101 , V_103 ) ;
V_17 = F_6 ( V_7 , F_28 ( V_11 -> V_108 ) ) ;
F_8 ( V_7 , F_28 ( V_11 -> V_108 ) , V_17 | 0x00100000 ) ;
V_17 = F_6 ( V_7 , F_28 ( V_11 -> V_108 ) ) ;
if ( ! ( V_17 & 0x01000000 ) ) {
F_23 ( V_7 , L_16 , V_17 ) ;
V_12 = - V_109 ;
goto V_110;
}
for ( V_37 = 0 ; V_37 < 3 ; V_37 ++ ) {
V_17 = F_6 ( V_7 , F_29 ( V_11 -> V_108 ) ) ;
if ( V_17 & V_111 )
break;
F_26 ( 100 ) ;
}
if ( V_37 == 3 ) {
V_12 = - V_112 ;
goto V_110;
}
if ( ! ( V_16 & 1 ) ) {
memcpy ( V_106 , V_102 , V_103 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
F_15 ( V_7 , L_17 , V_37 , V_106 [ V_37 ] ) ;
F_8 ( V_7 , F_30 ( V_107 , V_37 ) , V_106 [ V_37 ] ) ;
}
}
F_8 ( V_7 , F_31 ( V_107 ) , V_101 ) ;
V_104 = F_6 ( V_7 , F_28 ( V_107 ) ) ;
V_104 &= ~ ( V_113 | V_114 ) ;
V_104 |= ( V_16 << V_115 ) ;
V_104 |= ( ( V_103 - 1 ) << V_116 ) ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ ) {
F_8 ( V_7 , F_28 ( V_107 ) , V_104 | 0x80000000 ) ;
F_8 ( V_7 , F_28 ( V_107 ) , V_104 ) ;
F_8 ( V_7 , F_28 ( V_107 ) , V_104 | 0x00010000 ) ;
if ( ! F_32 ( V_7 , F_28 ( V_107 ) ,
0x00010000 , 0x00000000 ) ) {
F_23 ( V_7 , L_18 ,
F_6 ( V_7 , F_28 ( V_107 ) ) ) ;
V_12 = - V_112 ;
goto V_110;
}
F_26 ( 400 ) ;
V_105 = F_6 ( V_7 , F_29 ( V_107 ) ) ;
if ( ( V_105 & V_117 ) !=
V_118 )
break;
}
if ( V_37 == 16 ) {
F_23 ( V_7 , L_19 ) ;
V_12 = - V_119 ;
goto V_110;
}
if ( V_16 & 1 ) {
if ( ( V_105 & V_120 ) != V_103 ) {
V_12 = - V_119 ;
goto V_110;
}
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_106 [ V_37 ] = F_6 ( V_7 , F_33 ( V_107 , V_37 ) ) ;
F_15 ( V_7 , L_20 , V_37 , V_106 [ V_37 ] ) ;
}
memcpy ( V_102 , V_106 , V_103 ) ;
}
V_110:
V_17 = F_6 ( V_7 , F_28 ( V_11 -> V_108 ) ) ;
F_8 ( V_7 , F_28 ( V_11 -> V_108 ) , V_17 & ~ 0x00100000 ) ;
V_17 = F_6 ( V_7 , F_28 ( V_11 -> V_108 ) ) ;
if ( V_17 & 0x01000000 ) {
F_23 ( V_7 , L_21 , V_17 ) ;
V_12 = - V_109 ;
}
F_26 ( 400 ) ;
return V_12 ? V_12 : ( V_105 & V_121 ) ;
}
static int
F_34 ( struct V_122 * V_123 , struct V_124 * V_125 , int V_126 )
{
struct V_10 * V_11 = (struct V_10 * ) V_123 ;
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_124 * V_127 = V_125 ;
int V_12 , V_128 = V_126 ;
while ( V_128 -- ) {
T_3 V_129 = V_127 -> V_130 ;
T_3 * V_131 = V_127 -> V_4 ;
while ( V_129 ) {
T_3 V_132 = ( V_129 > 16 ) ? 16 : V_129 ;
T_3 V_16 ;
if ( V_127 -> V_133 & V_134 )
V_16 = V_135 ;
else
V_16 = V_136 ;
if ( V_128 || V_129 > 16 )
V_16 |= V_137 ;
V_12 = F_3 ( V_11 , V_16 , V_127 -> V_101 , V_131 , V_132 ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_12 & V_138 ) {
case V_139 :
break;
case V_140 :
return - V_119 ;
case V_141 :
F_26 ( 100 ) ;
continue;
default:
F_23 ( V_7 , L_22 , V_12 ) ;
return - V_119 ;
}
V_131 += V_132 ;
V_129 -= V_132 ;
}
V_127 ++ ;
}
return V_126 ;
}
static T_4
F_35 ( struct V_122 * V_123 )
{
return V_142 | V_143 ;
}
