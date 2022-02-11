static T_1
F_1 ( int V_1 )
{
switch ( V_1 ) {
case 1 :
case 2 :
return 8 ;
case 4 :
return 4 ;
case 8 :
return 2 ;
default:
F_2 ( L_1 , V_1 ) ;
return 1 ;
}
}
static T_1
F_3 ( int V_1 )
{
switch ( V_1 ) {
case 1 :
return 8 ;
case 2 :
case 4 :
case 8 :
return 4 ;
default:
F_2 ( L_1 , V_1 ) ;
return 1 ;
}
}
static bool
F_4 ( T_1 V_2 , T_1 V_3 , int V_1 )
{
return ( V_2 <= 4 * F_1 ( V_1 ) ||
V_3 <= 4 * F_3 ( V_1 ) ) ;
}
struct V_4 *
F_5 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_4 * V_8 ;
struct V_9 * V_10 ;
if ( V_7 >= V_6 -> V_11 ) {
F_2 ( L_2 ,
V_7 , V_6 -> V_11 ) ;
return NULL ;
}
V_8 = V_6 -> V_10 [ V_7 ] ;
V_10 = F_6 ( & V_8 -> V_12 ) ;
if ( V_10 -> V_13 ) {
F_2 ( L_3
L_4 ) ;
return NULL ;
}
return V_8 ;
}
static struct V_4 *
F_7 ( struct V_5 * V_6 , T_1 V_14 )
{
return F_5 ( V_6 , V_6 -> V_15 [ V_14 ] ) ;
}
static bool
F_8 ( struct V_5 * V_6 , void * V_16 , T_1 V_17 )
{
return ( V_16 - 1 == V_6 -> V_18 + V_17 ) ;
}
static T_1
F_9 ( T_1 V_19 )
{
T_1 V_20 = V_19 & 7 ;
bool V_21 = V_19 & 8 ;
if ( V_20 == 0 )
V_20 = 8 ;
if ( V_21 )
return 100 + V_20 * 4 ;
else
return 36 + V_20 * 8 ;
}
bool
F_10 ( struct V_5 * V_6 , struct V_4 * V_22 ,
T_1 V_23 , T_2 V_24 ,
T_1 V_2 , T_1 V_3 , T_2 V_1 )
{
T_1 V_25 , V_26 , V_27 , V_28 ;
T_1 V_29 = F_1 ( V_1 ) ;
T_1 V_30 = F_3 ( V_1 ) ;
if ( V_2 > 4096 || V_3 > 4096 ) {
F_2 ( L_5 , V_2 , V_3 ) ;
return false ;
}
switch ( V_24 ) {
case V_31 :
V_25 = F_11 ( V_2 , V_29 ) ;
V_26 = V_3 ;
break;
case V_32 :
V_25 = F_11 ( V_2 , V_29 * 8 ) ;
V_26 = F_11 ( V_3 , V_30 * 8 ) ;
break;
case V_33 :
V_25 = F_11 ( V_2 , V_29 ) ;
V_26 = F_11 ( V_3 , V_30 ) ;
break;
default:
F_2 ( L_6 , V_24 ) ;
return false ;
}
V_27 = V_25 * V_1 ;
V_28 = V_27 * V_26 ;
if ( V_28 + V_23 < V_28 ||
V_28 + V_23 > V_22 -> V_12 . V_28 ) {
F_2 ( L_7 ,
V_2 , V_3 ,
V_25 , V_26 ,
V_28 , V_23 , V_22 -> V_12 . V_28 ) ;
return false ;
}
return true ;
}
static int
F_12 ( T_3 )
{
if ( ! F_8 ( V_6 , V_16 , V_6 -> args -> V_34 - 1 ) ) {
F_2 ( L_8 ) ;
return - V_35 ;
}
V_6 -> V_36 = true ;
return 0 ;
}
static int
F_13 ( T_3 )
{
if ( V_6 -> V_37 ) {
F_2 ( L_9 ) ;
return - V_35 ;
}
V_6 -> V_37 = true ;
if ( ! V_6 -> V_38 ) {
F_2 ( L_10 ) ;
return - V_35 ;
}
return 0 ;
}
static int
F_14 ( T_3 )
{
if ( ! F_8 ( V_6 , V_16 , V_6 -> args -> V_34 - 2 ) ) {
F_2 ( L_11
L_12 ) ;
return - V_35 ;
}
V_6 -> V_39 = true ;
return 0 ;
}
static int
F_15 ( T_3 )
{
struct V_4 * V_40 ;
T_1 V_41 = * ( T_1 * ) ( V_16 + 1 ) ;
T_1 V_23 = * ( T_1 * ) ( V_16 + 5 ) ;
T_1 V_42 = * ( T_1 * ) ( V_16 + 9 ) ;
T_1 V_43 = ( * ( T_2 * ) ( V_16 + 0 ) >> 4 ) ? 2 : 1 ;
struct V_44 * V_45 ;
if ( V_6 -> V_46 == 0 ) {
F_2 ( L_13 ) ;
return - V_35 ;
}
V_45 = & V_6 -> V_45 [ V_6 -> V_46 - 1 ] ;
if ( V_42 > V_45 -> V_42 )
V_45 -> V_42 = V_42 ;
V_40 = F_7 ( V_6 , 0 ) ;
if ( ! V_40 )
return - V_35 ;
if ( V_23 > V_40 -> V_12 . V_28 ||
( V_40 -> V_12 . V_28 - V_23 ) / V_43 < V_41 ) {
F_2 ( L_14 ,
V_23 , V_41 , V_43 , V_40 -> V_12 . V_28 ) ;
return - V_35 ;
}
* ( T_1 * ) ( V_47 + 5 ) = V_40 -> V_48 + V_23 ;
return 0 ;
}
static int
F_16 ( T_3 )
{
T_1 V_41 = * ( T_1 * ) ( V_16 + 1 ) ;
T_1 V_49 = * ( T_1 * ) ( V_16 + 5 ) ;
T_1 V_42 ;
struct V_44 * V_45 ;
if ( V_6 -> V_46 == 0 ) {
F_2 ( L_13 ) ;
return - V_35 ;
}
V_45 = & V_6 -> V_45 [ V_6 -> V_46 - 1 ] ;
if ( V_41 + V_49 < V_41 ) {
F_2 ( L_15 ) ;
return - V_35 ;
}
V_42 = V_41 + V_49 - 1 ;
if ( V_42 > V_45 -> V_42 )
V_45 -> V_42 = V_42 ;
return 0 ;
}
static int
F_17 ( T_3 )
{
T_1 V_50 = V_6 -> V_46 ++ ;
if ( V_50 >= V_6 -> V_51 ) {
F_2 ( L_16 ) ;
return - V_35 ;
}
V_6 -> V_45 [ V_50 ] . V_52 = * ( T_1 * ) V_16 ;
V_6 -> V_45 [ V_50 ] . V_42 = 0 ;
if ( V_6 -> V_45 [ V_50 ] . V_52 & ~ 0xf ) {
F_2 ( L_17 ) ;
return - V_35 ;
}
* ( T_1 * ) V_47 = ( V_6 -> V_53 +
V_6 -> V_45 [ V_50 ] . V_52 ) ;
V_6 -> V_53 +=
F_18 ( F_9 ( V_6 -> V_45 [ V_50 ] . V_52 ) , 16 ) ;
return 0 ;
}
static int
F_19 ( T_3 )
{
struct V_54 * V_55 = V_6 -> V_56 -> V_12 . V_55 ;
struct V_9 * V_57 ;
T_2 V_58 ;
T_1 V_59 , V_60 ;
T_1 V_61 ;
if ( V_6 -> V_38 ) {
F_2 ( L_18 ) ;
return - V_35 ;
}
V_6 -> V_38 = true ;
V_6 -> V_62 = * ( T_2 * ) ( V_16 + 12 ) ;
V_6 -> V_63 = * ( T_2 * ) ( V_16 + 13 ) ;
V_61 = V_6 -> V_62 * V_6 -> V_63 ;
V_58 = * ( T_2 * ) ( V_16 + 14 ) ;
if ( V_6 -> V_62 == 0 ||
V_6 -> V_63 == 0 ) {
F_2 ( L_19 ,
V_6 -> V_62 , V_6 -> V_63 ) ;
return - V_35 ;
}
if ( V_58 & ( V_64 |
V_65 ) ) {
F_2 ( L_20 , V_58 ) ;
return - V_35 ;
}
V_59 = 48 * V_61 ;
V_6 -> V_66 = F_18 ( V_59 , 4096 ) ;
* ( T_2 * ) ( V_47 + 14 ) =
( ( V_58 & ~ ( V_67 |
V_68 ) ) |
V_69 |
F_20 ( V_70 ,
V_71 ) |
F_20 ( V_72 ,
V_73 ) ) ;
V_60 = 32 * V_61 ;
V_60 = F_18 ( V_60 , 256 ) ;
V_60 += 1024 * 1024 ;
V_57 = F_21 ( V_55 , V_6 -> V_66 + V_60 ,
true ) ;
V_6 -> V_57 = & V_57 -> V_12 ;
if ( F_22 ( V_6 -> V_57 ) )
return F_23 ( V_6 -> V_57 ) ;
F_24 ( & V_57 -> V_74 , & V_6 -> V_75 ) ;
* ( T_1 * ) ( V_47 + 0 ) = ( V_6 -> V_57 -> V_48 +
V_6 -> V_66 ) ;
* ( T_1 * ) ( V_47 + 4 ) = V_60 ;
* ( T_1 * ) ( V_47 + 8 ) = V_6 -> V_57 -> V_48 ;
return 0 ;
}
static int
F_25 ( T_3 )
{
memcpy ( V_6 -> V_15 , V_16 , sizeof( V_6 -> V_15 ) ) ;
return 0 ;
}
int
F_26 ( struct V_54 * V_55 ,
void * V_47 ,
void * V_76 ,
struct V_5 * V_6 )
{
T_1 V_77 = V_6 -> args -> V_34 ;
T_1 V_78 = 0 ;
T_1 V_79 = 0 ;
while ( V_79 < V_77 ) {
void * V_80 = V_47 + V_78 ;
void * V_81 = V_76 + V_79 ;
T_4 V_82 = * ( T_2 * ) V_81 ;
const struct V_83 * V_84 ;
if ( V_82 >= F_27 ( V_83 ) ) {
F_2 ( L_21 ,
V_79 , V_82 ) ;
return - V_35 ;
}
V_84 = & V_83 [ V_82 ] ;
if ( ! V_84 -> V_85 ) {
F_2 ( L_22 ,
V_79 , V_82 ) ;
return - V_35 ;
}
if ( V_79 + V_84 -> V_77 > V_77 ) {
F_2 ( L_23
L_24 ,
V_79 , V_82 , V_84 -> V_85 , V_84 -> V_77 ,
V_79 + V_77 ) ;
return - V_35 ;
}
if ( V_82 != V_86 )
memcpy ( V_80 , V_81 , V_84 -> V_77 ) ;
if ( V_84 -> V_87 && V_84 -> V_87 ( V_6 ,
V_80 + 1 ,
V_81 + 1 ) ) {
F_2 ( L_25 ,
V_79 , V_82 , V_84 -> V_85 ) ;
return - V_35 ;
}
V_79 += V_84 -> V_77 ;
if ( V_82 != V_86 )
V_78 += V_84 -> V_77 ;
if ( V_82 == V_88 )
break;
}
V_6 -> V_89 = V_6 -> V_90 + V_78 ;
if ( ! V_6 -> V_37 ) {
F_2 ( L_26 ) ;
return - V_35 ;
}
if ( ! V_6 -> V_39 || ! V_6 -> V_36 ) {
F_2 ( L_27
L_28 ) ;
return - V_35 ;
}
return 0 ;
}
static bool
F_28 ( struct V_5 * V_6 ,
void * V_91 ,
struct V_92 * V_93 ,
T_1 V_94 )
{
struct V_4 * V_95 ;
T_1 V_96 = * ( T_1 * ) ( V_91 + V_93 -> V_97 [ 0 ] ) ;
T_1 V_98 = * ( T_1 * ) ( V_91 + V_93 -> V_97 [ 1 ] ) ;
T_1 V_99 = ( V_93 -> V_97 [ 2 ] != ~ 0 ?
* ( T_1 * ) ( V_91 + V_93 -> V_97 [ 2 ] ) : 0 ) ;
T_1 V_100 = ( V_93 -> V_97 [ 3 ] != ~ 0 ?
* ( T_1 * ) ( V_91 + V_93 -> V_97 [ 3 ] ) : 0 ) ;
T_1 * V_101 = V_6 -> V_102 + V_93 -> V_97 [ 0 ] ;
T_1 V_23 = V_96 & V_103 ;
T_1 V_104 = F_29 ( V_96 , V_105 ) ;
T_1 V_2 = F_29 ( V_98 , V_106 ) ;
T_1 V_3 = F_29 ( V_98 , V_107 ) ;
T_1 V_1 , V_24 , V_29 , V_30 ;
T_1 V_50 ;
T_1 V_108 = 0 ;
enum V_109 type ;
V_95 = F_5 ( V_6 , V_94 ) ;
if ( ! V_95 )
return false ;
if ( V_93 -> V_110 ) {
T_1 V_111 = V_95 -> V_12 . V_28 - V_96 ;
if ( V_96 > V_95 -> V_12 . V_28 - 4 ) {
F_2 ( L_29 ) ;
goto V_112;
}
if ( V_98 > V_111 - 4 ) {
F_2 ( L_30
L_31 ) ;
goto V_112;
}
* V_101 = V_95 -> V_48 + V_96 ;
return true ;
}
if ( V_2 == 0 )
V_2 = 2048 ;
if ( V_3 == 0 )
V_3 = 2048 ;
if ( V_96 & V_113 ) {
if ( F_29 ( V_99 , V_114 ) ==
V_115 )
V_108 = V_99 & V_116 ;
if ( F_29 ( V_100 , V_114 ) ==
V_115 ) {
if ( V_108 ) {
F_2 ( L_32 ) ;
goto V_112;
}
V_108 = V_100 & V_116 ;
}
if ( ! V_108 ) {
F_2 ( L_33 ) ;
goto V_112;
}
}
type = ( F_29 ( V_96 , V_117 ) |
( F_29 ( V_98 , V_118 ) << 4 ) ) ;
switch ( type ) {
case V_119 :
case V_120 :
case V_121 :
V_1 = 4 ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_1 = 2 ;
break;
case V_128 :
case V_129 :
case V_130 :
V_1 = 1 ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
default:
F_2 ( L_34 , type ) ;
goto V_112;
}
V_29 = F_1 ( V_1 ) ;
V_30 = F_3 ( V_1 ) ;
if ( type == V_121 ) {
V_24 = V_31 ;
} else {
if ( F_4 ( V_2 , V_3 , V_1 ) )
V_24 = V_33 ;
else
V_24 = V_32 ;
}
if ( ! F_10 ( V_6 , V_95 , V_23 + V_108 * 5 ,
V_24 , V_2 , V_3 , V_1 ) ) {
goto V_112;
}
for ( V_50 = 1 ; V_50 <= V_104 ; V_50 ++ ) {
T_1 V_137 = F_30 ( V_2 >> V_50 , 1u ) ;
T_1 V_138 = F_30 ( V_3 >> V_50 , 1u ) ;
T_1 V_25 , V_26 ;
T_1 V_139 ;
if ( V_24 == V_32 &&
F_4 ( V_137 , V_138 , V_1 ) ) {
V_24 = V_33 ;
}
switch ( V_24 ) {
case V_32 :
V_25 = F_11 ( V_137 , V_29 * 8 ) ;
V_26 = F_11 ( V_138 , V_30 * 8 ) ;
break;
case V_33 :
V_25 = F_11 ( V_137 , V_29 ) ;
V_26 = F_11 ( V_138 , V_30 ) ;
break;
default:
V_25 = F_11 ( V_137 , V_29 ) ;
V_26 = V_138 ;
break;
}
V_139 = V_25 * V_1 * V_26 ;
if ( V_23 < V_139 ) {
F_2 ( L_35
L_36 ,
V_50 , V_137 , V_138 ,
V_25 , V_26 ,
V_139 , V_23 ) ;
goto V_112;
}
V_23 -= V_139 ;
}
* V_101 = V_95 -> V_48 + V_96 ;
return true ;
V_112:
F_31 ( L_37 , V_93 -> V_97 [ 0 ] , V_96 ) ;
F_31 ( L_38 , V_93 -> V_97 [ 1 ] , V_98 ) ;
F_31 ( L_39 , V_93 -> V_97 [ 2 ] , V_99 ) ;
F_31 ( L_40 , V_93 -> V_97 [ 3 ] , V_100 ) ;
return false ;
}
static int
F_32 ( struct V_54 * V_55 ,
struct V_5 * V_6 ,
struct V_44 * V_140 )
{
T_1 * V_141 ;
void * V_142 , * V_143 ;
static const T_1 V_144 [] = {
4 ,
16 ,
28 ,
} ;
T_1 V_145 = F_27 ( V_144 ) ;
struct V_4 * V_10 [ V_145 + 8 ] ;
T_1 V_146 , V_147 , V_148 ;
int V_50 ;
V_146 = V_140 -> V_52 & 0x7 ;
if ( V_146 == 0 )
V_146 = 8 ;
V_148 = F_9 ( V_140 -> V_52 ) ;
V_147 = F_27 ( V_144 ) + V_146 ;
if ( V_147 * 4 > V_6 -> V_149 ) {
F_2 ( L_41
L_42 ,
V_147 , V_6 -> V_149 ) ;
return - V_35 ;
}
V_141 = V_6 -> V_150 ;
V_6 -> V_150 += V_147 * 4 ;
V_6 -> V_149 -= V_147 * 4 ;
if ( V_148 > V_6 -> V_149 ) {
F_2 ( L_43
L_42 ,
V_148 , V_6 -> V_149 ) ;
return - V_35 ;
}
V_142 = V_6 -> V_150 ;
V_143 = V_6 -> V_151 ;
memcpy ( V_143 , V_142 , V_148 ) ;
V_6 -> V_150 += V_148 ;
F_33 ( F_18 ( V_148 , 16 ) - V_148 > V_147 * 4 ) ;
V_6 -> V_151 += F_18 ( V_148 , 16 ) ;
V_6 -> V_149 -= V_148 ;
if ( ! ( * ( V_152 * ) V_142 & V_153 ) ) {
F_2 ( L_44 ) ;
return - V_35 ;
}
for ( V_50 = 0 ; V_50 < V_145 ; V_50 ++ ) {
if ( V_141 [ V_50 ] > V_6 -> V_11 ) {
F_2 ( L_45 , V_141 [ V_50 ] ) ;
return - V_35 ;
}
V_10 [ V_50 ] = V_6 -> V_10 [ V_141 [ V_50 ] ] ;
if ( ! V_10 [ V_50 ] )
return - V_35 ;
}
for ( V_50 = V_145 ; V_50 < V_147 ; V_50 ++ ) {
V_10 [ V_50 ] = F_5 ( V_6 , V_141 [ V_50 ] ) ;
if ( ! V_10 [ V_50 ] )
return - V_35 ;
}
for ( V_50 = 0 ; V_50 < V_145 ; V_50 ++ ) {
struct V_154 * V_13 ;
T_1 V_155 = V_144 [ V_50 ] ;
T_1 V_79 = * ( T_1 * ) ( V_142 + V_155 ) ;
T_1 * V_156 ;
void * V_91 ;
T_1 V_95 , V_157 ;
* ( T_1 * ) ( V_143 + V_155 ) = V_10 [ V_50 ] -> V_48 + V_79 ;
if ( V_79 != 0 ) {
F_2 ( L_46
L_47 ) ;
return - V_35 ;
}
V_13 = F_6 ( & V_10 [ V_50 ] -> V_12 ) -> V_13 ;
if ( ! V_13 )
return - V_35 ;
if ( V_13 -> V_158 >
V_6 -> V_159 ) {
F_2 ( L_48 ) ;
return - V_35 ;
}
V_156 = V_6 -> V_160 ;
V_91 = ( V_156 +
V_13 -> V_161 ) ;
memcpy ( V_6 -> V_102 , V_91 ,
V_13 -> V_159 ) ;
for ( V_95 = 0 ;
V_95 < V_13 -> V_161 ;
V_95 ++ ) {
if ( ! F_28 ( V_6 ,
V_91 ,
& V_13 -> V_162 [ V_95 ] ,
V_156 [ V_95 ] ) ) {
return - V_35 ;
}
}
for ( V_157 = 0 ;
V_157 < V_13 -> V_163 ;
V_157 ++ ) {
T_1 V_155 = V_13 -> V_164 [ V_157 ] ;
( ( T_1 * ) V_6 -> V_102 ) [ V_155 ] = V_6 -> V_165 ;
}
* ( T_1 * ) ( V_143 + V_155 + 4 ) = V_6 -> V_165 ;
V_6 -> V_160 += V_13 -> V_158 ;
V_6 -> V_102 += V_13 -> V_159 ;
V_6 -> V_165 += V_13 -> V_159 ;
}
for ( V_50 = 0 ; V_50 < V_146 ; V_50 ++ ) {
struct V_4 * V_166 =
V_10 [ F_27 ( V_144 ) + V_50 ] ;
T_1 V_155 = 36 + V_50 * 8 ;
T_1 V_23 = * ( T_1 * ) ( V_142 + V_155 + 0 ) ;
T_1 V_167 = * ( T_2 * ) ( V_142 + V_155 + 4 ) + 1 ;
T_1 V_27 = * ( T_2 * ) ( V_142 + V_155 + 5 ) ;
T_1 V_42 ;
if ( V_140 -> V_52 & 0x8 )
V_27 |= ( * ( T_1 * ) ( V_142 + 100 + V_50 * 4 ) ) & ~ 0xff ;
if ( V_166 -> V_12 . V_28 < V_23 ||
V_166 -> V_12 . V_28 - V_23 < V_167 ) {
F_2 ( L_49 ,
V_23 , V_167 , V_166 -> V_12 . V_28 ) ;
return - V_35 ;
}
if ( V_27 != 0 ) {
V_42 = ( ( V_166 -> V_12 . V_28 - V_23 - V_167 ) /
V_27 ) ;
if ( V_140 -> V_42 > V_42 ) {
F_2 ( L_50
L_51 ,
V_140 -> V_42 , V_42 ) ;
return - V_35 ;
}
}
* ( T_1 * ) ( V_143 + V_155 ) = V_166 -> V_48 + V_23 ;
}
return 0 ;
}
int
F_34 ( struct V_54 * V_55 ,
struct V_5 * V_6 )
{
T_1 V_50 ;
int V_168 = 0 ;
for ( V_50 = 0 ; V_50 < V_6 -> V_46 ; V_50 ++ ) {
V_168 = F_32 ( V_55 , V_6 , & V_6 -> V_45 [ V_50 ] ) ;
if ( V_168 )
return V_168 ;
}
return V_168 ;
}
