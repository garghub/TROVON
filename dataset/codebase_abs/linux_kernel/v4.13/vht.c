static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 = F_2 ( V_5 ) ;
if ( V_2 -> V_7 . V_8 . V_9 . V_10 & V_6 &&
! ( V_2 -> V_7 . V_8 . V_11 . V_10 & V_6 ) )
V_4 -> V_12 &= ~ V_5 ;
}
void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_13 ;
T_3 V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ;
if ( ! V_4 -> V_20 )
return;
if ( V_2 -> V_21 . type != V_22 )
return;
F_1 ( V_2 , V_4 ,
V_23 ) ;
F_1 ( V_2 , V_4 ,
V_24 ) ;
F_1 ( V_2 , V_4 ,
V_25 ) ;
F_1 ( V_2 , V_4 ,
V_26 ) ;
F_1 ( V_2 , V_4 ,
V_27 ) ;
F_1 ( V_2 , V_4 ,
V_28 ) ;
F_1 ( V_2 , V_4 ,
V_29 ) ;
F_1 ( V_2 , V_4 ,
V_30 ) ;
if ( V_2 -> V_7 . V_8 . V_9 . V_10 &
F_2 ( V_31 ) ) {
T_1 V_12 , V_32 ;
V_32 = F_4 ( V_2 -> V_7 . V_8 . V_11 . V_10 ) &
V_31 ;
V_32 >>= V_33 ;
V_12 = V_4 -> V_12 & V_31 ;
V_12 >>= V_33 ;
if ( V_32 < V_12 ) {
V_4 -> V_12 &=
~ V_31 ;
V_4 -> V_12 |=
V_32 << V_33 ;
}
}
V_14 =
F_5 ( V_2 -> V_7 . V_8 . V_9 . V_34 . V_35 ) ;
V_16 = F_5 ( V_2 -> V_7 . V_8 . V_11 . V_34 . V_35 ) ;
V_16 &= V_14 ;
V_15 = F_5 ( V_4 -> V_36 . V_35 ) ;
V_17 =
F_5 ( V_2 -> V_7 . V_8 . V_9 . V_34 . V_37 ) ;
V_19 = F_5 ( V_2 -> V_7 . V_8 . V_11 . V_34 . V_37 ) ;
V_19 &= V_17 ;
V_18 = F_5 ( V_4 -> V_36 . V_37 ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
T_4 V_38 , V_32 , V_39 ;
V_38 = ( V_14 >> 2 * V_13 ) & V_40 ;
V_32 = ( V_16 >> 2 * V_13 ) & V_40 ;
V_39 = ( V_15 >> 2 * V_13 ) & V_40 ;
if ( V_38 && ( ( V_39 != V_40 && V_32 < V_39 ) ||
V_32 == V_40 ) ) {
V_15 &= ~ ( 3 << 2 * V_13 ) ;
V_15 |= ( V_16 & ( 3 << 2 * V_13 ) ) ;
}
V_38 = ( V_17 >> 2 * V_13 ) & V_40 ;
V_32 = ( V_19 >> 2 * V_13 ) & V_40 ;
V_39 = ( V_18 >> 2 * V_13 ) & V_40 ;
if ( V_38 && ( ( V_39 != V_40 && V_32 < V_39 ) ||
V_32 == V_40 ) ) {
V_18 &= ~ ( 3 << 2 * V_13 ) ;
V_18 |= ( V_19 & ( 3 << 2 * V_13 ) ) ;
}
}
V_4 -> V_36 . V_35 = F_6 ( V_15 ) ;
V_4 -> V_36 . V_37 = F_6 ( V_18 ) ;
}
void
F_7 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
const struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_3 * V_4 = & V_46 -> V_46 . V_4 ;
struct V_3 V_47 ;
T_1 V_48 , V_13 ;
bool V_49 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( ! V_46 -> V_46 . V_50 . V_51 )
return;
if ( ! V_44 || ! V_42 -> V_4 . V_20 )
return;
V_49 = false ;
for ( V_13 = 0 ; V_13 < V_42 -> V_52 ; V_13 ++ ) {
if ( V_42 -> V_53 [ V_13 ] . V_54 & ( V_55 |
V_56 ) )
continue;
V_49 = true ;
break;
}
if ( ! V_49 )
return;
V_4 -> V_20 = true ;
V_47 = V_42 -> V_4 ;
if ( V_2 -> V_21 . type == V_22 &&
! F_8 ( V_46 , V_57 ) )
F_3 ( V_2 , & V_47 ) ;
V_48 = F_4 ( V_44 -> V_10 ) ;
V_4 -> V_12 = V_48 ;
V_4 -> V_12 &= V_58 |
V_59 |
V_60 |
V_23 |
V_61 |
V_62 |
V_31 |
V_63 |
V_64 |
V_29 |
V_30 ;
switch ( V_47 . V_12 & V_65 ) {
case V_66 :
V_4 -> V_12 |= V_48 &
V_66 ;
break;
case V_67 :
V_4 -> V_12 |= V_48 &
V_65 ;
break;
default:
break;
}
V_4 -> V_12 |= V_48 & V_47 . V_12 &
( V_24 |
V_25 ) ;
if ( V_47 . V_12 & V_28 )
V_4 -> V_12 |= V_48 &
( V_27 |
V_68 ) ;
if ( V_47 . V_12 & V_27 )
V_4 -> V_12 |= V_48 &
( V_28 |
V_69 ) ;
if ( V_47 . V_12 & V_70 )
V_4 -> V_12 |= V_48 &
V_71 ;
if ( V_47 . V_12 & V_71 )
V_4 -> V_12 |= V_48 &
V_70 ;
if ( V_47 . V_12 & V_26 )
V_4 -> V_12 |= V_48 & V_72 ;
if ( V_47 . V_12 & V_72 )
V_4 -> V_12 |= V_48 & V_26 ;
memcpy ( & V_4 -> V_36 , & V_44 -> V_34 ,
sizeof( struct V_73 ) ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
T_3 V_74 , V_75 , V_76 , V_77 ;
V_74 = F_5 ( V_47 . V_36 . V_35 ) ;
V_74 = ( V_74 >> V_13 * 2 ) & V_40 ;
V_75 = F_5 ( V_47 . V_36 . V_37 ) ;
V_75 = ( V_75 >> V_13 * 2 ) & V_40 ;
V_76 = F_5 ( V_4 -> V_36 . V_35 ) ;
V_76 = ( V_76 >> V_13 * 2 ) & V_40 ;
V_77 = F_5 ( V_4 -> V_36 . V_37 ) ;
V_77 = ( V_77 >> V_13 * 2 ) & V_40 ;
if ( V_77 != V_40 ) {
if ( V_74 == V_40 )
V_77 = V_40 ;
else if ( V_74 < V_77 )
V_77 = V_74 ;
}
if ( V_76 != V_40 ) {
if ( V_75 == V_40 )
V_76 = V_40 ;
else if ( V_75 < V_76 )
V_76 = V_75 ;
}
V_4 -> V_36 . V_35 &=
~ F_6 ( V_40 << V_13 * 2 ) ;
V_4 -> V_36 . V_35 |= F_6 ( V_76 << V_13 * 2 ) ;
V_4 -> V_36 . V_37 &=
~ F_6 ( V_40 << V_13 * 2 ) ;
V_4 -> V_36 . V_37 |= F_6 ( V_77 << V_13 * 2 ) ;
}
if ( V_4 -> V_36 . V_35 == F_6 ( 0xFFFF ) ) {
V_4 -> V_20 = false ;
F_9 ( V_2 , L_1 ,
V_46 -> V_78 ) ;
return;
}
switch ( V_4 -> V_12 & V_65 ) {
case V_66 :
case V_67 :
V_46 -> V_79 = V_80 ;
break;
default:
V_46 -> V_79 = V_81 ;
}
V_46 -> V_46 . V_82 = F_10 ( V_46 ) ;
if ( V_46 -> V_46 . V_83 == V_84 )
return;
switch ( V_4 -> V_12 & V_85 ) {
case V_60 :
V_46 -> V_46 . V_83 = V_86 ;
break;
case V_59 :
V_46 -> V_46 . V_83 = V_87 ;
break;
case V_58 :
default:
V_46 -> V_46 . V_83 = V_88 ;
break;
}
}
enum V_89 F_11 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = & V_46 -> V_46 . V_4 ;
T_1 V_90 ;
if ( ! V_4 -> V_20 )
return V_46 -> V_46 . V_50 . V_12 & V_91 ?
V_92 :
V_93 ;
V_90 = V_4 -> V_12 & V_65 ;
if ( V_90 == V_66 ||
V_90 == V_67 )
return V_80 ;
return V_81 ;
}
enum V_94 F_12 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = & V_46 -> V_46 . V_4 ;
T_1 V_90 ;
if ( ! V_4 -> V_20 ) {
if ( ! V_46 -> V_46 . V_50 . V_51 )
return V_95 ;
return V_46 -> V_46 . V_50 . V_12 & V_91 ?
V_96 : V_97 ;
}
V_90 = V_4 -> V_12 & V_65 ;
if ( V_90 == V_66 )
return V_98 ;
else if ( V_90 == V_67 )
return V_99 ;
return V_100 ;
}
enum V_89
F_13 ( enum V_94 V_101 )
{
switch ( V_101 ) {
case V_95 :
case V_97 :
return V_93 ;
case V_96 :
return V_92 ;
case V_100 :
return V_81 ;
case V_98 :
case V_99 :
return V_80 ;
default:
F_14 ( 1 ) ;
return V_93 ;
}
}
enum V_89 F_10 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
enum V_89 V_102 ;
enum V_94 V_103 = V_2 -> V_21 . V_104 . V_105 . V_101 ;
V_102 = F_11 ( V_46 ) ;
V_102 = F_15 ( V_102 , V_46 -> V_79 ) ;
V_102 = F_15 ( V_102 , F_13 ( V_103 ) ) ;
return V_102 ;
}
void F_16 ( struct V_45 * V_46 )
{
T_4 V_106 = 0 , V_107 = 0 ;
if ( V_46 -> V_46 . V_108 )
return;
if ( V_46 -> V_46 . V_50 . V_51 ) {
if ( V_46 -> V_46 . V_50 . V_109 . V_110 [ 0 ] )
V_106 ++ ;
if ( V_46 -> V_46 . V_50 . V_109 . V_110 [ 1 ] )
V_106 ++ ;
if ( V_46 -> V_46 . V_50 . V_109 . V_110 [ 2 ] )
V_106 ++ ;
if ( V_46 -> V_46 . V_50 . V_109 . V_110 [ 3 ] )
V_106 ++ ;
}
if ( V_46 -> V_46 . V_4 . V_20 ) {
int V_13 ;
T_3 V_35 ;
V_35 = F_5 ( V_46 -> V_46 . V_4 . V_36 . V_35 ) ;
for ( V_13 = 7 ; V_13 >= 0 ; V_13 -- ) {
T_4 V_109 = ( V_35 >> ( 2 * V_13 ) ) & 3 ;
if ( V_109 != V_40 ) {
V_107 = V_13 + 1 ;
break;
}
}
}
V_106 = F_17 ( V_106 , V_107 ) ;
V_46 -> V_46 . V_108 = F_18 ( T_4 , 1 , V_106 ) ;
}
T_1 F_19 ( struct V_1 * V_2 ,
struct V_45 * V_46 , T_4 V_111 ,
enum V_112 V_113 )
{
enum V_89 V_114 ;
T_1 V_115 = 0 ;
T_4 V_116 ;
if ( V_111 & V_117 )
return 0 ;
V_116 = V_111 & V_118 ;
V_116 >>= V_119 ;
V_116 += 1 ;
if ( V_46 -> V_46 . V_108 != V_116 ) {
V_46 -> V_46 . V_108 = V_116 ;
V_115 |= V_120 ;
}
switch ( V_111 & V_121 ) {
case V_122 :
V_46 -> V_79 = V_93 ;
break;
case V_123 :
V_46 -> V_79 = V_92 ;
break;
case V_124 :
V_46 -> V_79 = V_81 ;
break;
case V_125 :
V_46 -> V_79 = V_80 ;
break;
}
V_114 = F_10 ( V_46 ) ;
if ( V_114 != V_46 -> V_46 . V_82 ) {
V_46 -> V_46 . V_82 = V_114 ;
V_115 |= V_126 ;
}
return V_115 ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_129 * V_104 = & V_2 -> V_21 . V_104 ;
if ( ! V_2 -> V_21 . V_130 )
return;
if ( ! memcmp ( V_128 -> V_7 . V_131 . V_7 . V_132 . V_133 ,
V_104 -> V_134 . V_133 , V_135 ) &&
! memcmp ( V_128 -> V_7 . V_131 . V_7 . V_132 . V_136 ,
V_104 -> V_134 . V_136 , V_137 ) )
return;
memcpy ( V_104 -> V_134 . V_136 ,
V_128 -> V_7 . V_131 . V_7 . V_132 . V_136 ,
V_137 ) ;
memcpy ( V_104 -> V_134 . V_133 ,
V_128 -> V_7 . V_131 . V_7 . V_132 . V_133 ,
V_135 ) ;
F_21 ( V_2 , V_138 ) ;
}
void F_22 ( struct V_139 * V_21 ,
const T_4 * V_136 , const T_4 * V_133 )
{
struct V_129 * V_104 = & V_21 -> V_104 ;
if ( F_14 ( ! V_21 -> V_130 ) )
return;
memcpy ( V_104 -> V_134 . V_136 , V_136 , V_137 ) ;
memcpy ( V_104 -> V_134 . V_133 , V_133 , V_135 ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_45 * V_46 , T_4 V_111 ,
enum V_112 V_113 )
{
struct V_140 * V_141 = V_2 -> V_141 ;
struct V_41 * V_42 = V_141 -> V_142 . V_143 -> V_144 [ V_113 ] ;
T_1 V_115 = F_19 ( V_2 , V_46 , V_111 , V_113 ) ;
if ( V_115 > 0 ) {
F_24 ( V_2 ) ;
F_25 ( V_141 , V_42 , V_46 , V_115 ) ;
}
}
void F_26 ( T_5 V_4 ,
T_3 V_145 [ V_146 ] )
{
int V_13 ;
T_3 V_147 , V_12 = F_5 ( V_4 ) ;
for ( V_13 = 0 ; V_13 < V_146 ; V_13 ++ ) {
V_147 = ( V_12 >> V_13 * 2 ) & V_40 ;
switch ( V_147 ) {
case V_148 :
V_145 [ V_13 ] = 0x00FF ;
break;
case V_149 :
V_145 [ V_13 ] = 0x01FF ;
break;
case V_150 :
V_145 [ V_13 ] = 0x03FF ;
break;
case V_40 :
default:
V_145 [ V_13 ] = 0 ;
break;
}
}
}
