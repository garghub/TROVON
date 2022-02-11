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
if ( F_7 ( V_2 ) ) {
F_8 ( V_6 , L_2 ) ;
return - V_33 ;
}
if ( V_24 -> V_34 || V_24 -> V_35 )
return - V_36 ;
V_30 = F_9 ( V_24 -> V_29 ) ;
V_30 = F_10 ( T_1 , V_30 , V_37 ) ;
V_30 = F_11 ( T_1 , V_30 , V_26 ) ;
V_32 = F_9 ( V_24 -> V_31 ) ;
V_32 = F_10 ( T_1 , V_32 , V_38 ) ;
V_32 = F_11 ( T_1 , V_32 , V_28 ) ;
if ( V_6 -> V_30 != V_30 || V_6 -> V_32 != V_32 )
F_12 ( V_6 , L_3 ,
V_6 -> V_30 , V_30 , V_6 -> V_32 , V_32 ) ;
V_6 -> V_30 = V_30 ;
V_6 -> V_32 = V_32 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_39 , T_2 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_41 = V_40 ;
int V_42 ;
switch ( V_39 ) {
case V_43 :
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
memcpy ( V_41 , V_45 [ V_42 ] . V_46 , V_47 ) ;
V_41 += V_47 ;
}
for ( V_42 = 0 ; V_42 < V_6 -> V_48 ; V_42 ++ ) {
sprintf ( V_41 , L_4 , V_42 ) ;
V_41 += V_47 ;
sprintf ( V_41 , L_5 , V_42 ) ;
V_41 += V_47 ;
sprintf ( V_41 , L_6 , V_42 ) ;
V_41 += V_47 ;
}
strncpy ( V_41 , L_7 , V_47 ) ;
V_41 += V_47 ;
strncpy ( V_41 , L_8 , V_47 ) ;
V_41 += V_47 ;
strncpy ( V_41 , L_9 , V_47 ) ;
V_41 += V_47 ;
strncpy ( V_41 , L_10 , V_47 ) ;
V_41 += V_47 ;
strncpy ( V_41 , L_11 , V_47 ) ;
V_41 += V_47 ;
strncpy ( V_41 , L_12 , V_47 ) ;
V_41 += V_47 ;
strncpy ( V_41 , L_13 , V_47 ) ;
V_41 += V_47 ;
for ( V_42 = 0 ; V_42 < V_6 -> V_49 ; V_42 ++ ) {
sprintf ( V_41 , L_14 , V_42 ) ;
V_41 += V_47 ;
sprintf ( V_41 , L_15 , V_42 ) ;
V_41 += V_47 ;
}
for ( V_42 = 0 ; V_42 < V_6 -> V_50 ; V_42 ++ ) {
sprintf ( V_41 , L_16 , V_42 ) ;
V_41 += V_47 ;
sprintf ( V_41 , L_17 , V_42 ) ;
V_41 += V_47 ;
}
break;
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_51 * V_52 , T_3 * V_40 )
{
T_3 V_53 [ V_54 ] = {} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_55 * V_56 ;
struct V_55 V_57 = {} ;
T_3 V_58 [ V_54 ] ;
T_2 T_4 * V_59 ;
int V_42 , V_60 , V_61 ;
T_2 * V_41 ;
V_56 = F_15 ( V_2 , & V_57 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
switch ( V_45 [ V_42 ] . type ) {
case V_62 :
V_41 = ( char * ) V_56 + V_45 [ V_42 ] . V_63 ;
V_40 [ V_42 ] = V_45 [ V_42 ] . V_64 == sizeof( T_3 ) ?
* ( T_3 * ) V_41 : * ( T_1 * ) V_41 ;
break;
case V_65 :
V_59 = V_6 -> V_66 + V_45 [ V_42 ] . V_63 ;
V_40 [ V_42 ] = F_16 ( V_59 ) ;
break;
}
}
for ( V_60 = 0 ; V_60 < V_6 -> V_48 ; V_60 ++ ) {
unsigned int V_67 ;
do {
V_67 = F_17 ( & V_6 -> V_68 [ V_60 ] . V_69 ) ;
V_40 [ V_42 ++ ] = V_6 -> V_68 [ V_60 ] . V_70 ;
V_58 [ 0 ] = V_6 -> V_68 [ V_60 ] . V_71 ;
V_58 [ 1 ] = V_6 -> V_68 [ V_60 ] . V_72 ;
V_58 [ 2 ] = V_6 -> V_68 [ V_60 ] . V_73 ;
} while ( F_18 ( & V_6 -> V_68 [ V_60 ] . V_69 , V_67 ) );
do {
V_67 = F_17 ( & V_6 -> V_68 [ V_60 ] . V_74 ) ;
V_40 [ V_42 ++ ] = V_6 -> V_68 [ V_60 ] . V_75 ;
V_40 [ V_42 ++ ] = V_6 -> V_68 [ V_60 ] . V_76 ;
V_58 [ 3 ] = V_6 -> V_68 [ V_60 ] . V_77 ;
V_58 [ 4 ] = V_6 -> V_68 [ V_60 ] . V_78 ;
V_58 [ 5 ] = V_6 -> V_68 [ V_60 ] . V_79 ;
V_58 [ 6 ] = V_6 -> V_68 [ V_60 ] . V_80 ;
} while ( F_18 ( & V_6 -> V_68 [ V_60 ] . V_74 , V_67 ) );
for ( V_61 = 0 ; V_61 < V_54 ; V_61 ++ )
V_53 [ V_61 ] += V_58 [ V_61 ] ;
}
for ( V_60 = 0 ; V_60 < V_54 ; V_60 ++ )
V_40 [ V_42 ++ ] = V_53 [ V_60 ] ;
for ( V_60 = 0 ; V_60 < V_6 -> V_49 ; V_60 ++ ) {
V_59 = V_6 -> V_66 + F_19 ( V_60 ) ;
V_40 [ V_42 ++ ] = F_16 ( V_59 ) ;
V_59 = V_6 -> V_66 + F_19 ( V_60 ) + 8 ;
V_40 [ V_42 ++ ] = F_16 ( V_59 ) ;
}
for ( V_60 = 0 ; V_60 < V_6 -> V_50 ; V_60 ++ ) {
V_59 = V_6 -> V_66 + F_20 ( V_60 ) ;
V_40 [ V_42 ++ ] = F_16 ( V_59 ) ;
V_59 = V_6 -> V_66 + F_20 ( V_60 ) + 8 ;
V_40 [ V_42 ++ ] = F_16 ( V_59 ) ;
}
}
static int F_21 ( struct V_1 * V_2 , int V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_81 ) {
case V_43 :
return V_20 ;
default:
return - V_82 ;
}
}
static T_1 F_22 ( T_1 V_83 )
{
static const T_1 V_84 [ V_85 + 1 ] = {
[ V_86 ] = V_87 ,
[ V_88 ] = V_89 ,
[ V_90 ] = V_91 ,
[ V_92 ] = V_93 ,
[ V_94 ] = V_95 ,
[ V_85 ] = V_96 ,
} ;
if ( V_83 >= F_23 ( V_84 ) )
return 0 ;
return V_84 [ V_83 ] ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_97 * V_98 )
{
T_1 V_99 ;
V_98 -> V_40 = 0 ;
if ( ! ( V_6 -> V_100 & V_101 ) )
return - V_82 ;
V_99 = F_22 ( V_98 -> V_83 ) ;
if ( ! V_99 )
return - V_36 ;
V_98 -> V_40 |= V_102 | V_103 ;
if ( V_6 -> V_104 & V_99 )
V_98 -> V_40 |= V_105 | V_106 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_97 * V_98 , T_1 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_98 -> V_98 ) {
case V_108 :
V_98 -> V_40 = V_6 -> V_50 ;
return 0 ;
case V_109 :
return F_24 ( V_6 , V_98 ) ;
default:
return - V_82 ;
}
}
static int F_26 ( struct V_5 * V_6 ,
struct V_97 * V_110 )
{
T_1 V_111 = V_6 -> V_104 ;
T_1 V_99 ;
int V_112 ;
if ( ! ( V_6 -> V_100 & V_101 ) )
return - V_82 ;
if ( V_110 -> V_40 & ~ ( V_102 | V_103 |
V_105 | V_106 ) )
return - V_36 ;
if ( ! ( V_110 -> V_40 & V_102 ) ||
! ( V_110 -> V_40 & V_103 ) )
return - V_36 ;
V_99 = F_22 ( V_110 -> V_83 ) ;
if ( ! V_99 )
return - V_36 ;
switch ( V_110 -> V_40 & ( V_105 | V_106 ) ) {
case 0 :
V_111 &= ~ V_99 ;
break;
case ( V_105 | V_106 ) :
V_111 |= V_99 ;
break;
default:
return - V_36 ;
}
V_111 |= V_113 ;
V_111 |= V_114 ;
if ( V_111 == V_6 -> V_104 )
return 0 ;
F_27 ( V_111 , V_6 -> V_66 + V_115 ) ;
V_112 = F_28 ( V_6 , V_116 ) ;
if ( V_112 )
return V_112 ;
V_6 -> V_104 = V_111 ;
F_12 ( V_6 , L_18 , V_6 -> V_104 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_98 -> V_98 ) {
case V_117 :
return F_26 ( V_6 , V_98 ) ;
default:
return - V_82 ;
}
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_100 & V_101 ) )
return 0 ;
return F_23 ( V_6 -> V_118 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
return V_119 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_120 , T_2 * V_121 ,
T_2 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_42 ;
if ( ! ( V_6 -> V_100 & V_101 ) )
return - V_82 ;
if ( V_120 )
for ( V_42 = 0 ; V_42 < F_23 ( V_6 -> V_118 ) ; V_42 ++ )
V_120 [ V_42 ] = V_6 -> V_118 [ V_42 ] ;
if ( V_121 )
memcpy ( V_121 , V_6 -> V_123 , V_119 ) ;
if ( V_122 )
* V_122 = V_124 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const T_1 * V_120 , const T_2 * V_121 ,
const T_2 V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_42 ;
if ( ! ( V_6 -> V_100 & V_101 ) ||
! ( V_122 == V_125 || V_122 == V_124 ) )
return - V_82 ;
if ( ! V_121 && ! V_120 )
return 0 ;
if ( V_121 ) {
memcpy ( V_6 -> V_123 , V_121 , V_119 ) ;
F_34 ( V_6 ) ;
}
if ( V_120 ) {
for ( V_42 = 0 ; V_42 < F_23 ( V_6 -> V_118 ) ; V_42 ++ )
V_6 -> V_118 [ V_42 ] = V_120 [ V_42 ] ;
F_35 ( V_6 ) ;
}
return F_28 ( V_6 , V_116 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
return V_22 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_126 * V_127 , void * V_41 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * V_128 = V_41 ;
int V_42 ;
V_127 -> V_9 = F_38 ( V_6 , V_129 ) ;
for ( V_42 = 0 ; V_42 < V_22 / sizeof( T_1 ) ; V_42 ++ )
V_128 [ V_42 ] = F_39 ( V_6 -> V_66 + ( V_42 * sizeof( T_1 ) ) ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_100 & V_132 ) )
return - V_36 ;
V_131 -> V_133 = V_6 -> V_133 ;
V_131 -> V_134 = V_6 -> V_135 ;
V_131 -> V_136 = V_6 -> V_136 ;
V_131 -> V_137 = V_6 -> V_138 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_139 ;
if ( V_131 -> V_140 ||
V_131 -> V_141 ||
V_131 -> V_142 ||
V_131 -> V_143 ||
V_131 -> V_144 ||
V_131 -> V_145 ||
V_131 -> V_146 ||
V_131 -> V_147 ||
V_131 -> V_148 ||
V_131 -> V_149 ||
V_131 -> V_150 ||
V_131 -> V_151 ||
V_131 -> V_152 ||
V_131 -> V_153 ||
V_131 -> V_154 ||
V_131 -> V_155 ||
V_131 -> V_156 ||
V_131 -> V_157 )
return - V_158 ;
V_139 = V_6 -> V_159 / 16 ;
if ( ! ( V_6 -> V_100 & V_132 ) )
return - V_36 ;
if ( ! V_131 -> V_133 && ! V_131 -> V_134 )
return - V_36 ;
if ( ! V_131 -> V_136 && ! V_131 -> V_137 )
return - V_36 ;
if ( V_131 -> V_133 * V_139 >= ( ( 1 << 16 ) - 1 ) )
return - V_36 ;
if ( V_131 -> V_136 * V_139 >= ( ( 1 << 16 ) - 1 ) )
return - V_36 ;
if ( V_131 -> V_134 >= ( ( 1 << 16 ) - 1 ) )
return - V_36 ;
if ( V_131 -> V_137 >= ( ( 1 << 16 ) - 1 ) )
return - V_36 ;
V_6 -> V_133 = V_131 -> V_133 ;
V_6 -> V_135 = V_131 -> V_134 ;
V_6 -> V_136 = V_131 -> V_136 ;
V_6 -> V_138 = V_131 -> V_137 ;
F_42 ( V_6 ) ;
return F_28 ( V_6 , V_160 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_161 = & V_162 ;
}
