static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char * V_7 = ( char * ) V_4 ;
unsigned int V_8 ;
switch ( V_3 ) {
case V_9 :
memcpy ( V_4 , * V_10 ,
V_11 * V_12 ) ;
break;
case V_13 :
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ ) {
memcpy ( V_7 , V_15 [ V_8 ] . V_16 ,
V_12 ) ;
V_7 += V_12 ;
}
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ ) {
memcpy ( V_7 , V_18 [ V_8 ] . V_16 ,
V_12 ) ;
V_7 += V_12 ;
}
if ( V_6 -> V_19 . V_20 . type != V_21 ) {
for ( V_8 = 0 ; V_8 < V_22 ; V_8 ++ ) {
memcpy ( V_7 , V_23 [ V_8 ] . V_16 ,
V_12 ) ;
V_7 += V_12 ;
}
}
for ( V_8 = 0 ; V_8 < V_6 -> V_19 . V_20 . V_24 ; V_8 ++ ) {
sprintf ( V_7 , L_1 , V_8 ) ;
V_7 += V_12 ;
sprintf ( V_7 , L_2 , V_8 ) ;
V_7 += V_12 ;
sprintf ( V_7 , L_3 , V_8 ) ;
V_7 += V_12 ;
sprintf ( V_7 , L_4 , V_8 ) ;
V_7 += V_12 ;
}
break;
}
}
static int F_3 ( struct V_1 * V_2 , int V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
int V_27 = V_28 ;
switch ( V_25 ) {
case V_9 :
return V_11 ;
case V_13 :
V_27 += F_4 ( V_19 -> V_20 . V_24 ) ;
if ( V_19 -> V_20 . type != V_21 )
V_27 += V_22 ;
return V_27 ;
default:
return - V_29 ;
}
}
static void F_5 ( struct V_1 * V_30 ,
struct V_31 T_3 * V_32 ,
T_4 * V_4 )
{
const int V_33 = sizeof( struct V_34 ) / sizeof( T_4 ) ;
struct V_5 * V_6 = F_2 ( V_30 ) ;
struct V_35 * V_36 = & V_30 -> V_32 ;
char * V_7 ;
int V_8 , V_37 ;
F_6 ( V_6 ) ;
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ ) {
V_7 = ( char * ) V_36 + V_15 [ V_8 ] . V_38 ;
* ( V_4 ++ ) = ( V_15 [ V_8 ] . V_39 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_7 : * ( T_1 * ) V_7 ;
}
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ ) {
V_7 = ( char * ) V_6 +
V_18 [ V_8 ] . V_38 ;
* ( V_4 ++ ) = ( V_18 [ V_8 ] . V_39 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_7 : * ( T_1 * ) V_7 ;
}
if ( V_6 -> V_19 . V_20 . type != V_21 )
for ( V_8 = 0 ; V_8 < V_22 ; V_8 ++ ) {
V_7 = ( char * ) V_6 +
V_23 [ V_8 ] . V_38 ;
* ( V_4 ++ ) = ( V_23 [ V_8 ] . V_39 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_7 : * ( T_1 * ) V_7 ;
}
for ( V_8 = 0 ; V_8 < V_6 -> V_19 . V_20 . V_24 ; V_8 ++ ) {
struct V_40 * V_41 ;
T_4 * V_42 ;
V_41 = V_6 -> V_43 [ V_8 ] ;
if ( V_41 )
V_42 = ( T_4 * ) & V_41 -> V_32 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
* ( V_4 ++ ) = V_41 ? V_42 [ V_37 ] : 0 ;
V_41 = V_6 -> V_44 [ V_8 ] ;
if ( V_41 )
V_42 = ( T_4 * ) & V_41 -> V_32 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
* ( V_4 ++ ) = V_41 ? V_42 [ V_37 ] : 0 ;
}
}
static void F_7 ( struct V_26 * V_19 , T_1 * V_45 , int V_8 )
{
int V_46 = 0 ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_9 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_10 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_11 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_12 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_13 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_14 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_15 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_16 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_17 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_18 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_19 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_20 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_21 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_22 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_23 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_24 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_25 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_26 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_27 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_28 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_29 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_30 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_31 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_32 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_33 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_34 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_35 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_36 ( V_8 ) ) ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_37 ( V_8 ) ) ;
F_38 ( V_46 != V_47 ) ;
}
static void F_39 ( struct V_26 * V_19 , T_1 * V_45 , int V_8 )
{
int V_46 = 0 , V_37 ;
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_40 ( V_8 ) ) ;
for ( V_37 = 0 ; V_37 < 10 ; V_37 ++ )
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_41 ( V_8 , V_37 ) ) ;
for ( V_37 = 0 ; V_37 < 32 ; V_37 ++ )
V_45 [ V_46 ++ ] = F_8 ( V_19 , F_42 ( V_8 , V_37 ) ) ;
F_38 ( V_46 != V_48 ) ;
}
static void F_43 ( struct V_1 * V_30 ,
struct V_49 * V_50 , void * V_7 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
T_1 * V_45 = V_7 ;
T_5 V_8 ;
V_50 -> V_51 = ( 1 << 24 ) | ( V_19 -> V_52 << 16 ) | V_19 -> V_53 ;
switch ( V_19 -> V_20 . type ) {
case V_54 :
* ( V_45 ++ ) = F_8 ( V_19 , V_55 ) ;
* ( V_45 ++ ) = F_8 ( V_19 , V_56 ) ;
* ( V_45 ++ ) = F_8 ( V_19 , V_57 ) ;
* ( V_45 ++ ) = F_8 ( V_19 , V_58 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
* ( V_45 ++ ) = F_8 ( V_19 , F_44 ( V_8 ) ) ;
* ( V_45 ++ ) = F_8 ( V_19 , F_45 ( V_8 ) ) ;
}
for ( V_8 = 0 ; V_8 < 65 ; V_8 ++ ) {
F_39 ( V_19 , V_45 , V_8 ) ;
V_45 += V_48 ;
}
* ( V_45 ++ ) = F_8 ( V_19 , V_59 ) ;
* ( V_45 ++ ) = F_8 ( V_19 , V_60 ) ;
for ( V_8 = 0 ; V_8 < V_61 ; V_8 ++ ) {
F_7 ( V_19 , V_45 , V_8 ) ;
V_45 += V_47 ;
}
* ( V_45 ++ ) = F_8 ( V_19 , V_62 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
* ( V_45 ++ ) = F_8 ( V_19 , F_46 ( V_8 ) ) ;
for ( V_8 = 0 ; V_8 < 130 ; V_8 ++ )
* ( V_45 ++ ) = F_8 ( V_19 , F_47 ( V_8 ) ) ;
break;
case V_21 :
* ( V_45 ++ ) = F_8 ( V_19 , V_63 ) ;
* ( V_45 ++ ) = F_8 ( V_19 , V_64 ) ;
* ( V_45 ++ ) = F_8 ( V_19 , V_65 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
* ( V_45 ++ ) = F_8 ( V_19 , F_48 ( V_8 ) ) ;
F_39 ( V_19 , V_45 , 0 ) ;
V_45 += V_48 ;
for ( V_8 = 0 ; V_8 < V_66 ; V_8 ++ ) {
if ( V_8 < V_19 -> V_20 . V_24 )
F_7 ( V_19 , V_45 , V_8 ) ;
else
memset ( V_45 , 0 , sizeof( T_1 ) * V_47 ) ;
V_45 += V_47 ;
}
break;
default:
return;
}
}
static int F_49 ( struct V_1 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
switch ( V_19 -> V_20 . type ) {
case V_54 :
return V_67 * sizeof( T_1 ) ;
case V_21 :
return V_68 * sizeof( T_1 ) ;
default:
return 0 ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strncpy ( V_70 -> V_71 , V_72 ,
sizeof( V_70 -> V_71 ) - 1 ) ;
strncpy ( V_70 -> V_51 , V_73 ,
sizeof( V_70 -> V_51 ) - 1 ) ;
strncpy ( V_70 -> V_74 , F_51 ( V_6 -> V_75 ) ,
sizeof( V_70 -> V_74 ) - 1 ) ;
V_70 -> V_76 = F_3 ( V_2 , V_13 ) ;
V_70 -> V_77 = F_49 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_79 -> V_80 = 0 ;
V_79 -> V_81 = 1 ;
V_79 -> V_82 = V_6 -> V_82 ? 1 : 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
if ( V_79 -> V_80 || ! V_79 -> V_81 )
return - V_83 ;
if ( V_19 -> V_20 . type == V_54 )
V_6 -> V_82 = V_79 -> V_82 ? ~ 0 : 0 ;
else if ( V_79 -> V_82 )
return - V_83 ;
if ( F_54 ( V_2 ) )
F_55 ( V_6 ) ;
return 0 ;
}
static T_1 F_56 ( struct V_1 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
return V_6 -> V_84 ;
}
static void F_57 ( struct V_1 * V_30 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
V_6 -> V_84 = V_4 ;
}
static void F_58 ( struct V_1 * V_30 ,
struct V_85 * V_41 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
V_41 -> V_86 = V_87 ;
V_41 -> V_88 = V_89 ;
V_41 -> V_90 = 0 ;
V_41 -> V_91 = 0 ;
V_41 -> V_92 = V_6 -> V_93 ;
V_41 -> V_94 = V_6 -> V_95 ;
V_41 -> V_96 = 0 ;
V_41 -> V_97 = 0 ;
}
static int F_59 ( struct V_1 * V_30 ,
struct V_85 * V_41 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
struct V_40 * V_98 ;
int V_8 , V_99 = 0 ;
T_1 V_100 , V_101 ;
if ( ( V_41 -> V_96 ) || ( V_41 -> V_97 ) )
return - V_83 ;
V_101 = F_60 ( T_1 , V_41 -> V_94 ,
V_102 , V_89 ) ;
V_101 = F_61 ( V_101 , V_103 ) ;
V_100 = F_60 ( T_1 , V_41 -> V_92 ,
V_104 , V_87 ) ;
V_100 = F_61 ( V_100 , V_105 ) ;
if ( ( V_101 == V_6 -> V_95 ) &&
( V_100 == V_6 -> V_93 ) ) {
return 0 ;
}
while ( F_62 ( V_106 , & V_6 -> V_107 ) )
F_63 ( 1000 , 2000 ) ;
if ( ! F_54 ( V_6 -> V_30 ) ) {
for ( V_8 = 0 ; V_8 < V_6 -> V_108 ; V_8 ++ )
V_6 -> V_43 [ V_8 ] -> V_109 = V_101 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_110 ; V_8 ++ )
V_6 -> V_44 [ V_8 ] -> V_109 = V_100 ;
V_6 -> V_95 = V_101 ;
V_6 -> V_93 = V_100 ;
goto V_111;
}
V_8 = F_64 ( int , V_6 -> V_108 , V_6 -> V_110 ) ;
V_98 = F_65 ( V_8 * sizeof( struct V_40 ) ) ;
if ( ! V_98 ) {
V_99 = - V_112 ;
goto V_111;
}
F_66 ( V_6 ) ;
if ( V_101 != V_6 -> V_95 ) {
for ( V_8 = 0 ; V_8 < V_6 -> V_108 ; V_8 ++ ) {
memcpy ( & V_98 [ V_8 ] , V_6 -> V_43 [ V_8 ] ,
sizeof( struct V_40 ) ) ;
V_98 [ V_8 ] . V_109 = V_101 ;
V_99 = F_67 ( & V_98 [ V_8 ] ) ;
if ( V_99 ) {
while ( V_8 ) {
V_8 -- ;
F_68 ( & V_98 [ V_8 ] ) ;
}
goto V_113;
}
}
for ( V_8 = 0 ; V_8 < V_6 -> V_108 ; V_8 ++ ) {
F_68 ( V_6 -> V_43 [ V_8 ] ) ;
memcpy ( V_6 -> V_43 [ V_8 ] , & V_98 [ V_8 ] ,
sizeof( struct V_40 ) ) ;
}
V_6 -> V_95 = V_101 ;
}
if ( V_100 != V_6 -> V_93 ) {
for ( V_8 = 0 ; V_8 < V_6 -> V_110 ; V_8 ++ ) {
memcpy ( & V_98 [ V_8 ] , V_6 -> V_44 [ V_8 ] ,
sizeof( struct V_40 ) ) ;
V_98 [ V_8 ] . V_109 = V_100 ;
V_99 = F_69 ( & V_98 [ V_8 ] ) ;
if ( V_99 ) {
while ( V_8 ) {
V_8 -- ;
F_70 ( & V_98 [ V_8 ] ) ;
}
goto V_113;
}
}
for ( V_8 = 0 ; V_8 < V_6 -> V_110 ; V_8 ++ ) {
F_70 ( V_6 -> V_44 [ V_8 ] ) ;
memcpy ( V_6 -> V_44 [ V_8 ] , & V_98 [ V_8 ] ,
sizeof( struct V_40 ) ) ;
}
V_6 -> V_93 = V_100 ;
}
V_113:
F_71 ( V_6 ) ;
F_72 ( V_98 ) ;
V_111:
F_73 ( V_106 , & V_6 -> V_107 ) ;
return V_99 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_115 -> V_116 =
! ! ( V_6 -> V_117 & V_118 ) ;
V_115 -> V_119 = V_6 -> V_117 & ~ V_118 ;
V_115 -> V_120 =
! ! ( V_6 -> V_121 & V_118 ) ;
V_115 -> V_122 = V_6 -> V_121 & ~ V_118 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_123 * V_124 ;
T_5 V_117 , V_121 ;
int V_8 ;
if ( ( V_115 -> V_122 > V_125 ) ||
( V_115 -> V_119 > V_125 ) )
return - V_83 ;
V_117 = V_115 -> V_119 ;
V_121 = V_115 -> V_122 ;
if ( V_115 -> V_116 )
V_117 = V_118 | V_126 ;
if ( V_115 -> V_120 )
V_121 = V_118 | V_127 ;
V_6 -> V_117 = V_117 ;
V_6 -> V_121 = V_121 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_128 ; V_8 ++ ) {
V_124 = V_6 -> V_129 [ V_8 ] ;
V_124 -> V_130 . V_131 = V_117 ;
V_124 -> V_132 . V_131 = V_121 ;
}
return 0 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_133 * V_134 )
{
V_134 -> V_4 = 0 ;
switch ( V_134 -> V_135 ) {
case V_136 :
case V_137 :
V_134 -> V_4 |= V_138 | V_139 ;
case V_140 :
if ( V_6 -> V_141 & V_142 )
V_134 -> V_4 |= V_138 | V_139 ;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
V_134 -> V_4 |= V_153 | V_154 ;
break;
case V_155 :
if ( V_6 -> V_141 & V_156 )
V_134 -> V_4 |= V_138 | V_139 ;
V_134 -> V_4 |= V_153 | V_154 ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_133 * V_134 ,
T_1 T_3 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_158 = - V_29 ;
switch ( V_134 -> V_134 ) {
case V_159 :
V_134 -> V_4 = V_6 -> V_110 ;
V_158 = 0 ;
break;
case V_160 :
V_158 = F_76 ( V_6 , V_134 ) ;
break;
default:
break;
}
return V_158 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_133 * V_161 )
{
T_1 V_141 = V_6 -> V_141 ;
if ( V_161 -> V_4 & ~ ( V_153 | V_154 |
V_138 | V_139 ) )
return - V_83 ;
switch ( V_161 -> V_135 ) {
case V_136 :
case V_137 :
if ( ! ( V_161 -> V_4 & V_153 ) ||
! ( V_161 -> V_4 & V_154 ) ||
! ( V_161 -> V_4 & V_138 ) ||
! ( V_161 -> V_4 & V_139 ) )
return - V_83 ;
break;
case V_140 :
if ( ! ( V_161 -> V_4 & V_153 ) ||
! ( V_161 -> V_4 & V_154 ) )
return - V_83 ;
switch ( V_161 -> V_4 & ( V_138 | V_139 ) ) {
case 0 :
V_141 &= ~ V_142 ;
break;
case ( V_138 | V_139 ) :
V_141 |= V_142 ;
break;
default:
return - V_83 ;
}
break;
case V_155 :
if ( ! ( V_161 -> V_4 & V_153 ) ||
! ( V_161 -> V_4 & V_154 ) )
return - V_83 ;
switch ( V_161 -> V_4 & ( V_138 | V_139 ) ) {
case 0 :
V_141 &= ~ V_156 ;
break;
case ( V_138 | V_139 ) :
V_141 |= V_156 ;
break;
default:
return - V_83 ;
}
break;
case V_145 :
case V_147 :
case V_149 :
case V_143 :
case V_146 :
case V_148 :
case V_150 :
case V_144 :
if ( ! ( V_161 -> V_4 & V_153 ) ||
! ( V_161 -> V_4 & V_154 ) ||
( V_161 -> V_4 & V_138 ) ||
( V_161 -> V_4 & V_139 ) )
return - V_83 ;
break;
default:
return - V_83 ;
}
if ( V_141 != V_6 -> V_141 ) {
struct V_26 * V_19 = & V_6 -> V_19 ;
T_1 V_162 ;
if ( ( V_141 & V_163 ) &&
! ( V_6 -> V_141 & V_163 ) )
F_79 ( V_6 , V_164 , V_6 -> V_30 ,
L_5 ) ;
V_6 -> V_141 = V_141 ;
V_162 = V_165 |
V_166 |
V_167 |
V_168 ;
if ( V_141 & V_142 )
V_162 |= V_169 ;
if ( V_141 & V_156 )
V_162 |= V_170 ;
F_80 ( V_19 , F_40 ( 0 ) , V_162 ) ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_133 * V_134 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_158 = - V_29 ;
switch ( V_134 -> V_134 ) {
case V_171 :
V_158 = F_78 ( V_6 , V_134 ) ;
break;
default:
break;
}
return V_158 ;
}
static int F_82 ( struct V_5 * V_6 , T_4 * V_4 )
{
struct V_26 * V_19 = & V_6 -> V_19 ;
struct V_172 * V_173 = & V_19 -> V_173 ;
T_1 V_174 , V_175 [ 6 ] ;
unsigned long V_176 ;
int V_99 ;
if ( V_19 -> V_20 . type != V_21 )
return 0 ;
for ( V_174 = ( 1 << V_177 ) ;
V_174 < ( 1 << ( 2 * V_178 ) ) ;
V_174 += V_174 ) {
F_83 ( V_175 , V_174 ) ;
F_84 ( V_6 ) ;
V_173 -> V_179 = V_180 ;
V_99 = V_173 -> V_181 . V_182 ( V_19 , V_173 , V_175 ) ;
F_85 ( V_6 ) ;
V_176 = V_183 + V_184 ;
do {
if ( V_99 < 0 )
goto V_185;
F_63 ( 500 , 1000 ) ;
F_84 ( V_6 ) ;
V_173 -> V_181 . V_186 ( V_19 , V_173 ) ;
F_85 ( V_6 ) ;
V_99 = V_173 -> V_179 ;
if ( ! V_99 )
break;
} while ( F_86 ( V_176 ) );
if ( V_99 )
goto V_185;
}
V_185:
* V_4 = V_99 < 0 ? ( V_174 ) : ( V_99 > 0 ) ;
return V_99 ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_187 * V_188 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
memset ( V_4 , 0 , sizeof( * V_4 ) * V_11 ) ;
if ( F_88 ( V_19 ) ) {
F_89 ( V_6 , V_164 , V_2 ,
L_6 ) ;
V_188 -> V_141 |= V_189 ;
return;
}
if ( F_82 ( V_6 , & V_4 [ V_190 ] ) )
V_188 -> V_141 |= V_189 ;
}
static T_1 F_90 ( struct V_1 T_3 * V_30 )
{
return V_191 * V_192 ;
}
static int F_91 ( struct V_1 * V_30 , T_1 * V_193 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
int V_8 ;
if ( ! V_193 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_191 ; V_8 ++ , V_193 += 4 ) {
T_1 V_194 = V_6 -> V_194 [ V_8 ] ;
V_193 [ 0 ] = ( V_194 << 24 ) >> 24 ;
V_193 [ 1 ] = ( V_194 << 16 ) >> 24 ;
V_193 [ 2 ] = ( V_194 << 8 ) >> 24 ;
V_193 [ 3 ] = ( V_194 ) >> 24 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_30 , const T_1 * V_193 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
int V_8 ;
T_5 V_195 ;
if ( ! V_193 )
return 0 ;
V_195 = V_6 -> V_196 [ V_197 ] . V_198 ;
for ( V_8 = F_90 ( V_30 ) ; V_8 -- ; ) {
if ( V_193 [ V_8 ] < V_195 )
continue;
return - V_83 ;
}
for ( V_8 = 0 ; V_8 < V_191 ; V_8 ++ , V_193 += 4 ) {
T_1 V_194 = V_193 [ 0 ] |
( V_193 [ 1 ] << 8 ) |
( V_193 [ 2 ] << 16 ) |
( V_193 [ 3 ] << 24 ) ;
if ( V_6 -> V_194 [ V_8 ] == V_194 )
continue;
V_6 -> V_194 [ V_8 ] = V_194 ;
F_80 ( V_19 , F_42 ( 0 , V_8 ) , V_194 ) ;
}
return 0 ;
}
static T_1 F_93 ( struct V_1 T_3 * V_30 )
{
return V_199 * V_200 ;
}
static int F_94 ( struct V_1 * V_30 , T_1 * V_193 , T_2 * V_201 ,
T_2 * V_202 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
int V_8 , V_99 ;
if ( V_202 )
* V_202 = V_203 ;
V_99 = F_91 ( V_30 , V_193 ) ;
if ( V_99 || ! V_201 )
return V_99 ;
for ( V_8 = 0 ; V_8 < V_199 ; V_8 ++ , V_201 += 4 )
* ( V_204 * ) V_201 = F_95 ( V_6 -> V_205 [ V_8 ] ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_30 , const T_1 * V_193 ,
const T_2 * V_201 , const T_2 V_202 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
int V_8 , V_99 ;
if ( V_202 != V_206 && V_202 != V_203 )
return - V_29 ;
V_99 = F_92 ( V_30 , V_193 ) ;
if ( V_99 || ! V_201 )
return V_99 ;
for ( V_8 = 0 ; V_8 < V_199 ; V_8 ++ , V_201 += 4 ) {
T_1 V_205 = F_97 ( * ( V_204 * ) V_201 ) ;
if ( V_6 -> V_205 [ V_8 ] == V_205 )
continue;
V_6 -> V_205 [ V_8 ] = V_205 ;
F_80 ( V_19 , F_41 ( 0 , V_8 ) , V_205 ) ;
}
return 0 ;
}
static unsigned int F_98 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_207 = V_6 -> V_19 . V_20 . V_24 ;
T_2 V_208 = F_99 ( V_2 ) ;
if ( V_208 > 1 )
V_207 = 1 << ( F_100 ( V_207 / V_208 ) - 1 ) ;
return V_207 ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_19 = & V_6 -> V_19 ;
V_210 -> V_207 = F_98 ( V_2 ) ;
V_210 -> V_211 = F_102 ( V_19 ) ;
V_210 -> V_212 = V_210 -> V_211 ;
V_210 -> V_213 = V_6 -> V_196 [ V_197 ] . V_198 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_109 = V_210 -> V_213 ;
struct V_26 * V_19 = & V_6 -> V_19 ;
if ( ! V_109 || V_210 -> V_214 || V_210 -> V_215 )
return - V_83 ;
if ( V_210 -> V_212 != F_102 ( V_19 ) )
return - V_83 ;
if ( V_109 > F_98 ( V_2 ) )
return - V_83 ;
V_6 -> V_196 [ V_197 ] . V_216 = V_109 ;
return F_104 ( V_2 , F_99 ( V_2 ) ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_217 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_70 -> V_218 =
V_219 |
V_220 |
V_221 |
V_222 |
V_223 |
V_224 ;
if ( V_6 -> V_225 )
V_70 -> V_226 = F_106 ( V_6 -> V_225 ) ;
else
V_70 -> V_226 = - 1 ;
V_70 -> V_227 = ( 1 << V_228 ) |
( 1 << V_229 ) ;
V_70 -> V_230 = ( 1 << V_231 ) |
( 1 << V_232 ) ;
return 0 ;
}
void F_107 ( struct V_1 * V_2 )
{
V_2 -> V_233 = & V_234 ;
}
