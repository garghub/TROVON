static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_3 ( V_4 -> V_9 , V_10 ,
sizeof( V_4 -> V_9 ) ) ;
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_1 ,
V_6 -> V_12 . V_13 , V_6 -> V_12 . V_14 ,
V_6 -> V_12 . V_15 , V_6 -> V_12 . V_16 ) ;
F_3 ( V_4 -> V_17 , F_4 ( V_6 -> V_18 ) ,
sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = V_22 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_24 -> V_25 = V_26 ;
V_24 -> V_27 = V_28 ;
V_24 -> V_29 = V_6 -> V_30 ;
V_24 -> V_31 = V_6 -> V_32 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_30 , V_32 ;
if ( V_24 -> V_33 || V_24 -> V_34 )
return - V_35 ;
V_30 = F_7 ( V_24 -> V_29 ) ;
V_32 = F_7 ( V_24 -> V_31 ) ;
if ( V_30 < V_36 || V_30 > V_26 ||
V_32 < V_37 || V_32 > V_28 )
return - V_35 ;
if ( V_6 -> V_30 == V_30 && V_6 -> V_32 == V_32 )
return 0 ;
F_8 ( V_6 , L_2 ,
V_6 -> V_30 , V_30 , V_6 -> V_32 , V_32 ) ;
return F_9 ( V_6 , V_30 , V_32 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_38 , T_2 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_40 = V_39 ;
int V_41 ;
switch ( V_38 ) {
case V_42 :
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
memcpy ( V_40 , V_44 [ V_41 ] . V_45 , V_46 ) ;
V_40 += V_46 ;
}
for ( V_41 = 0 ; V_41 < V_6 -> V_47 ; V_41 ++ ) {
sprintf ( V_40 , L_3 , V_41 ) ;
V_40 += V_46 ;
sprintf ( V_40 , L_4 , V_41 ) ;
V_40 += V_46 ;
sprintf ( V_40 , L_5 , V_41 ) ;
V_40 += V_46 ;
}
strncpy ( V_40 , L_6 , V_46 ) ;
V_40 += V_46 ;
strncpy ( V_40 , L_7 , V_46 ) ;
V_40 += V_46 ;
strncpy ( V_40 , L_8 , V_46 ) ;
V_40 += V_46 ;
strncpy ( V_40 , L_9 , V_46 ) ;
V_40 += V_46 ;
strncpy ( V_40 , L_10 , V_46 ) ;
V_40 += V_46 ;
strncpy ( V_40 , L_11 , V_46 ) ;
V_40 += V_46 ;
strncpy ( V_40 , L_12 , V_46 ) ;
V_40 += V_46 ;
for ( V_41 = 0 ; V_41 < V_6 -> V_48 ; V_41 ++ ) {
sprintf ( V_40 , L_13 , V_41 ) ;
V_40 += V_46 ;
sprintf ( V_40 , L_14 , V_41 ) ;
V_40 += V_46 ;
}
for ( V_41 = 0 ; V_41 < V_6 -> V_49 ; V_41 ++ ) {
sprintf ( V_40 , L_15 , V_41 ) ;
V_40 += V_46 ;
sprintf ( V_40 , L_16 , V_41 ) ;
V_40 += V_46 ;
}
break;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_50 * V_51 , T_3 * V_39 )
{
T_3 V_52 [ V_53 ] = {} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_54 V_56 = {} ;
T_3 V_57 [ V_53 ] ;
T_2 T_4 * V_58 ;
int V_41 , V_59 , V_60 ;
T_2 * V_40 ;
V_55 = F_12 ( V_2 , & V_56 ) ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
switch ( V_44 [ V_41 ] . type ) {
case V_61 :
V_40 = ( char * ) V_55 + V_44 [ V_41 ] . V_62 ;
V_39 [ V_41 ] = V_44 [ V_41 ] . V_63 == sizeof( T_3 ) ?
* ( T_3 * ) V_40 : * ( T_1 * ) V_40 ;
break;
case V_64 :
V_58 = V_6 -> V_65 + V_44 [ V_41 ] . V_62 ;
V_39 [ V_41 ] = F_13 ( V_58 ) ;
break;
}
}
for ( V_59 = 0 ; V_59 < V_6 -> V_47 ; V_59 ++ ) {
unsigned int V_66 ;
do {
V_66 = F_14 ( & V_6 -> V_67 [ V_59 ] . V_68 ) ;
V_39 [ V_41 ++ ] = V_6 -> V_67 [ V_59 ] . V_69 ;
V_57 [ 0 ] = V_6 -> V_67 [ V_59 ] . V_70 ;
V_57 [ 1 ] = V_6 -> V_67 [ V_59 ] . V_71 ;
V_57 [ 2 ] = V_6 -> V_67 [ V_59 ] . V_72 ;
} while ( F_15 ( & V_6 -> V_67 [ V_59 ] . V_68 , V_66 ) );
do {
V_66 = F_14 ( & V_6 -> V_67 [ V_59 ] . V_73 ) ;
V_39 [ V_41 ++ ] = V_6 -> V_67 [ V_59 ] . V_74 ;
V_39 [ V_41 ++ ] = V_6 -> V_67 [ V_59 ] . V_75 ;
V_57 [ 3 ] = V_6 -> V_67 [ V_59 ] . V_76 ;
V_57 [ 4 ] = V_6 -> V_67 [ V_59 ] . V_77 ;
V_57 [ 5 ] = V_6 -> V_67 [ V_59 ] . V_78 ;
V_57 [ 6 ] = V_6 -> V_67 [ V_59 ] . V_79 ;
} while ( F_15 ( & V_6 -> V_67 [ V_59 ] . V_73 , V_66 ) );
for ( V_60 = 0 ; V_60 < V_53 ; V_60 ++ )
V_52 [ V_60 ] += V_57 [ V_60 ] ;
}
for ( V_59 = 0 ; V_59 < V_53 ; V_59 ++ )
V_39 [ V_41 ++ ] = V_52 [ V_59 ] ;
for ( V_59 = 0 ; V_59 < V_6 -> V_48 ; V_59 ++ ) {
V_58 = V_6 -> V_65 + F_16 ( V_59 ) ;
V_39 [ V_41 ++ ] = F_13 ( V_58 ) ;
V_58 = V_6 -> V_65 + F_16 ( V_59 ) + 8 ;
V_39 [ V_41 ++ ] = F_13 ( V_58 ) ;
}
for ( V_59 = 0 ; V_59 < V_6 -> V_49 ; V_59 ++ ) {
V_58 = V_6 -> V_65 + F_17 ( V_59 ) ;
V_39 [ V_41 ++ ] = F_13 ( V_58 ) ;
V_58 = V_6 -> V_65 + F_17 ( V_59 ) + 8 ;
V_39 [ V_41 ++ ] = F_13 ( V_58 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , int V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_80 ) {
case V_42 :
return V_20 ;
default:
return - V_81 ;
}
}
static T_1 F_19 ( T_1 V_82 )
{
static const T_1 V_83 [ V_84 + 1 ] = {
[ V_85 ] = V_86 ,
[ V_87 ] = V_88 ,
[ V_89 ] = V_90 ,
[ V_91 ] = V_92 ,
[ V_93 ] = V_94 ,
[ V_84 ] = V_95 ,
} ;
if ( V_82 >= F_20 ( V_83 ) )
return 0 ;
return V_83 [ V_82 ] ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
{
T_1 V_98 ;
V_97 -> V_39 = 0 ;
if ( ! ( V_6 -> V_99 & V_100 ) )
return - V_81 ;
V_98 = F_19 ( V_97 -> V_82 ) ;
if ( ! V_98 )
return - V_35 ;
V_97 -> V_39 |= V_101 | V_102 ;
if ( V_6 -> V_103 & V_98 )
V_97 -> V_39 |= V_104 | V_105 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_96 * V_97 , T_1 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_97 -> V_97 ) {
case V_107 :
V_97 -> V_39 = V_6 -> V_49 ;
return 0 ;
case V_108 :
return F_21 ( V_6 , V_97 ) ;
default:
return - V_81 ;
}
}
static int F_23 ( struct V_5 * V_6 ,
struct V_96 * V_109 )
{
T_1 V_110 = V_6 -> V_103 ;
T_1 V_98 ;
int V_111 ;
if ( ! ( V_6 -> V_99 & V_100 ) )
return - V_81 ;
if ( V_109 -> V_39 & ~ ( V_101 | V_102 |
V_104 | V_105 ) )
return - V_35 ;
if ( ! ( V_109 -> V_39 & V_101 ) ||
! ( V_109 -> V_39 & V_102 ) )
return - V_35 ;
V_98 = F_19 ( V_109 -> V_82 ) ;
if ( ! V_98 )
return - V_35 ;
switch ( V_109 -> V_39 & ( V_104 | V_105 ) ) {
case 0 :
V_110 &= ~ V_98 ;
break;
case ( V_104 | V_105 ) :
V_110 |= V_98 ;
break;
default:
return - V_35 ;
}
V_110 |= V_112 ;
V_110 |= V_113 ;
if ( V_110 == V_6 -> V_103 )
return 0 ;
F_24 ( V_110 , V_6 -> V_65 + V_114 ) ;
V_111 = F_25 ( V_6 , V_115 ) ;
if ( V_111 )
return V_111 ;
V_6 -> V_103 = V_110 ;
F_8 ( V_6 , L_17 , V_6 -> V_103 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_97 -> V_97 ) {
case V_116 :
return F_23 ( V_6 , V_97 ) ;
default:
return - V_81 ;
}
}
static T_1 F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_99 & V_100 ) )
return 0 ;
return F_20 ( V_6 -> V_117 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
return V_118 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_119 , T_2 * V_120 ,
T_2 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_41 ;
if ( ! ( V_6 -> V_99 & V_100 ) )
return - V_81 ;
if ( V_119 )
for ( V_41 = 0 ; V_41 < F_20 ( V_6 -> V_117 ) ; V_41 ++ )
V_119 [ V_41 ] = V_6 -> V_117 [ V_41 ] ;
if ( V_120 )
memcpy ( V_120 , V_6 -> V_122 , V_118 ) ;
if ( V_121 )
* V_121 = V_123 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const T_1 * V_119 , const T_2 * V_120 ,
const T_2 V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_41 ;
if ( ! ( V_6 -> V_99 & V_100 ) ||
! ( V_121 == V_124 || V_121 == V_123 ) )
return - V_81 ;
if ( ! V_120 && ! V_119 )
return 0 ;
if ( V_120 ) {
memcpy ( V_6 -> V_122 , V_120 , V_118 ) ;
F_31 ( V_6 ) ;
}
if ( V_119 ) {
for ( V_41 = 0 ; V_41 < F_20 ( V_6 -> V_117 ) ; V_41 ++ )
V_6 -> V_117 [ V_41 ] = V_119 [ V_41 ] ;
F_32 ( V_6 ) ;
}
return F_25 ( V_6 , V_115 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
return V_22 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_125 * V_126 , void * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * V_127 = V_40 ;
int V_41 ;
V_126 -> V_9 = F_35 ( V_6 , V_128 ) ;
for ( V_41 = 0 ; V_41 < V_22 / sizeof( T_1 ) ; V_41 ++ )
V_127 [ V_41 ] = F_36 ( V_6 -> V_65 + ( V_41 * sizeof( T_1 ) ) ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_99 & V_131 ) )
return - V_35 ;
V_130 -> V_132 = V_6 -> V_132 ;
V_130 -> V_133 = V_6 -> V_134 ;
V_130 -> V_135 = V_6 -> V_135 ;
V_130 -> V_136 = V_6 -> V_137 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_138 ;
if ( V_130 -> V_139 ||
V_130 -> V_140 ||
V_130 -> V_141 ||
V_130 -> V_142 ||
V_130 -> V_143 ||
V_130 -> V_144 ||
V_130 -> V_145 ||
V_130 -> V_146 ||
V_130 -> V_147 ||
V_130 -> V_148 ||
V_130 -> V_149 ||
V_130 -> V_150 ||
V_130 -> V_151 ||
V_130 -> V_152 ||
V_130 -> V_153 ||
V_130 -> V_154 ||
V_130 -> V_155 ||
V_130 -> V_156 )
return - V_157 ;
V_138 = V_6 -> V_158 / 16 ;
if ( ! ( V_6 -> V_99 & V_131 ) )
return - V_35 ;
if ( ! V_130 -> V_132 && ! V_130 -> V_133 )
return - V_35 ;
if ( ! V_130 -> V_135 && ! V_130 -> V_136 )
return - V_35 ;
if ( V_130 -> V_132 * V_138 >= ( ( 1 << 16 ) - 1 ) )
return - V_35 ;
if ( V_130 -> V_135 * V_138 >= ( ( 1 << 16 ) - 1 ) )
return - V_35 ;
if ( V_130 -> V_133 >= ( ( 1 << 16 ) - 1 ) )
return - V_35 ;
if ( V_130 -> V_136 >= ( ( 1 << 16 ) - 1 ) )
return - V_35 ;
V_6 -> V_132 = V_130 -> V_132 ;
V_6 -> V_134 = V_130 -> V_133 ;
V_6 -> V_135 = V_130 -> V_135 ;
V_6 -> V_137 = V_130 -> V_136 ;
F_39 ( V_6 ) ;
return F_25 ( V_6 , V_159 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_160 = & V_161 ;
}
