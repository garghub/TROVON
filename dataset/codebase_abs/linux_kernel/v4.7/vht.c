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
switch ( V_4 -> V_12 & V_65 ) {
case V_66 :
case V_67 :
V_46 -> V_78 = V_79 ;
break;
default:
V_46 -> V_78 = V_80 ;
}
V_46 -> V_46 . V_81 = F_9 ( V_46 ) ;
if ( V_46 -> V_46 . V_82 == V_83 )
return;
switch ( V_4 -> V_12 & V_84 ) {
case V_60 :
V_46 -> V_46 . V_82 = V_85 ;
break;
case V_59 :
V_46 -> V_46 . V_82 = V_86 ;
break;
case V_58 :
default:
V_46 -> V_46 . V_82 = V_87 ;
break;
}
}
enum V_88 F_10 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = & V_46 -> V_46 . V_4 ;
T_1 V_89 ;
if ( ! V_4 -> V_20 )
return V_46 -> V_46 . V_50 . V_12 & V_90 ?
V_91 :
V_92 ;
V_89 = V_4 -> V_12 & V_65 ;
if ( V_89 == V_66 ||
V_89 == V_67 )
return V_79 ;
return V_80 ;
}
enum V_93 F_11 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = & V_46 -> V_46 . V_4 ;
T_1 V_89 ;
if ( ! V_4 -> V_20 ) {
if ( ! V_46 -> V_46 . V_50 . V_51 )
return V_94 ;
return V_46 -> V_46 . V_50 . V_12 & V_90 ?
V_95 : V_96 ;
}
V_89 = V_4 -> V_12 & V_65 ;
if ( V_89 == V_66 )
return V_97 ;
else if ( V_89 == V_67 )
return V_98 ;
return V_99 ;
}
enum V_88
F_12 ( enum V_93 V_100 )
{
switch ( V_100 ) {
case V_94 :
case V_96 :
return V_92 ;
case V_95 :
return V_91 ;
case V_99 :
return V_80 ;
case V_97 :
case V_98 :
return V_79 ;
default:
F_13 ( 1 ) ;
return V_92 ;
}
}
enum V_88 F_9 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
enum V_88 V_101 ;
enum V_93 V_102 = V_2 -> V_21 . V_103 . V_104 . V_100 ;
V_101 = F_10 ( V_46 ) ;
V_101 = F_14 ( V_101 , V_46 -> V_78 ) ;
V_101 = F_14 ( V_101 , F_12 ( V_102 ) ) ;
return V_101 ;
}
void F_15 ( struct V_45 * V_46 )
{
T_4 V_105 = 0 , V_106 = 0 ;
if ( V_46 -> V_46 . V_107 )
return;
if ( V_46 -> V_46 . V_50 . V_51 ) {
if ( V_46 -> V_46 . V_50 . V_108 . V_109 [ 0 ] )
V_105 ++ ;
if ( V_46 -> V_46 . V_50 . V_108 . V_109 [ 1 ] )
V_105 ++ ;
if ( V_46 -> V_46 . V_50 . V_108 . V_109 [ 2 ] )
V_105 ++ ;
if ( V_46 -> V_46 . V_50 . V_108 . V_109 [ 3 ] )
V_105 ++ ;
}
if ( V_46 -> V_46 . V_4 . V_20 ) {
int V_13 ;
T_3 V_35 ;
V_35 = F_5 ( V_46 -> V_46 . V_4 . V_36 . V_35 ) ;
for ( V_13 = 7 ; V_13 >= 0 ; V_13 -- ) {
T_4 V_108 = ( V_35 >> ( 2 * V_13 ) ) & 3 ;
if ( V_108 != V_40 ) {
V_106 = V_13 + 1 ;
break;
}
}
}
V_105 = F_16 ( V_105 , V_106 ) ;
V_46 -> V_46 . V_107 = F_17 ( T_4 , 1 , V_105 ) ;
}
T_1 F_18 ( struct V_1 * V_2 ,
struct V_45 * V_46 , T_4 V_110 ,
enum V_111 V_112 )
{
struct V_113 * V_114 = V_2 -> V_114 ;
struct V_41 * V_42 ;
enum V_88 V_115 ;
T_1 V_116 = 0 ;
T_4 V_117 ;
V_42 = V_114 -> V_118 . V_119 -> V_120 [ V_112 ] ;
if ( V_110 & V_121 )
return 0 ;
V_117 = V_110 & V_122 ;
V_117 >>= V_123 ;
V_117 += 1 ;
if ( V_46 -> V_46 . V_107 != V_117 ) {
V_46 -> V_46 . V_107 = V_117 ;
V_116 |= V_124 ;
}
switch ( V_110 & V_125 ) {
case V_126 :
V_46 -> V_78 = V_92 ;
break;
case V_127 :
V_46 -> V_78 = V_91 ;
break;
case V_128 :
V_46 -> V_78 = V_80 ;
break;
case V_129 :
V_46 -> V_78 = V_79 ;
break;
}
V_115 = F_9 ( V_46 ) ;
if ( V_115 != V_46 -> V_46 . V_81 ) {
V_46 -> V_46 . V_81 = V_115 ;
V_116 |= V_130 ;
}
return V_116 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_133 * V_103 = & V_2 -> V_21 . V_103 ;
if ( ! V_2 -> V_21 . V_134 )
return;
if ( ! memcmp ( V_132 -> V_7 . V_135 . V_7 . V_136 . V_137 ,
V_103 -> V_138 . V_137 , V_139 ) &&
! memcmp ( V_132 -> V_7 . V_135 . V_7 . V_136 . V_140 ,
V_103 -> V_138 . V_140 , V_141 ) )
return;
memcpy ( V_103 -> V_138 . V_140 ,
V_132 -> V_7 . V_135 . V_7 . V_136 . V_140 ,
V_141 ) ;
memcpy ( V_103 -> V_138 . V_137 ,
V_132 -> V_7 . V_135 . V_7 . V_136 . V_137 ,
V_139 ) ;
F_20 ( V_2 , V_142 ) ;
}
void F_21 ( struct V_143 * V_21 ,
const T_4 * V_140 , const T_4 * V_137 )
{
struct V_133 * V_103 = & V_21 -> V_103 ;
if ( F_13 ( ! V_21 -> V_134 ) )
return;
memcpy ( V_103 -> V_138 . V_140 , V_140 , V_141 ) ;
memcpy ( V_103 -> V_138 . V_137 , V_137 , V_139 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_45 * V_46 , T_4 V_110 ,
enum V_111 V_112 )
{
struct V_113 * V_114 = V_2 -> V_114 ;
struct V_41 * V_42 = V_114 -> V_118 . V_119 -> V_120 [ V_112 ] ;
T_1 V_116 = F_18 ( V_2 , V_46 , V_110 , V_112 ) ;
if ( V_116 > 0 )
F_23 ( V_114 , V_42 , V_46 , V_116 ) ;
}
void F_24 ( T_5 V_4 ,
T_3 V_144 [ V_145 ] )
{
int V_13 ;
T_3 V_146 , V_12 = F_5 ( V_4 ) ;
for ( V_13 = 0 ; V_13 < V_145 ; V_13 ++ ) {
V_146 = ( V_12 >> V_13 * 2 ) & V_40 ;
switch ( V_146 ) {
case V_147 :
V_144 [ V_13 ] = 0x00FF ;
break;
case V_148 :
V_144 [ V_13 ] = 0x01FF ;
break;
case V_149 :
V_144 [ V_13 ] = 0x03FF ;
break;
case V_40 :
default:
V_144 [ V_13 ] = 0 ;
break;
}
}
}
