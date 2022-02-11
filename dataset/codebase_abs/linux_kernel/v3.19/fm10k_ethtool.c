static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
char * V_5 = ( char * ) V_4 ;
int V_6 ;
switch ( V_3 ) {
case V_7 :
memcpy ( V_4 , * V_8 ,
V_9 * V_10 ) ;
break;
case V_11 :
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ ) {
memcpy ( V_5 , V_13 [ V_6 ] . V_14 ,
V_10 ) ;
V_5 += V_10 ;
}
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
memcpy ( V_5 , V_16 [ V_6 ] . V_14 ,
V_10 ) ;
V_5 += V_10 ;
}
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
sprintf ( V_5 , L_1 , V_6 ) ;
V_5 += V_10 ;
sprintf ( V_5 , L_2 , V_6 ) ;
V_5 += V_10 ;
sprintf ( V_5 , L_3 , V_6 ) ;
V_5 += V_10 ;
sprintf ( V_5 , L_4 , V_6 ) ;
V_5 += V_10 ;
}
break;
}
}
static int F_2 ( struct V_1 * V_2 , int V_18 )
{
switch ( V_18 ) {
case V_7 :
return V_9 ;
case V_11 :
return V_19 ;
default:
return - V_20 ;
}
}
static void F_3 ( struct V_1 * V_21 ,
struct V_22 * V_23 , T_3 * V_4 )
{
const int V_24 = sizeof( struct V_25 ) / sizeof( T_3 ) ;
struct V_26 * V_27 = F_4 ( V_21 ) ;
struct V_28 * V_29 = & V_21 -> V_23 ;
char * V_5 ;
int V_6 , V_30 ;
F_5 ( V_27 ) ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ ) {
V_5 = ( char * ) V_29 + V_13 [ V_6 ] . V_31 ;
* ( V_4 ++ ) = ( V_13 [ V_6 ] . V_32 ==
sizeof( T_3 ) ) ? * ( T_3 * ) V_5 : * ( T_1 * ) V_5 ;
}
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
V_5 = ( char * ) V_27 + V_16 [ V_6 ] . V_31 ;
* ( V_4 ++ ) = ( V_16 [ V_6 ] . V_32 ==
sizeof( T_3 ) ) ? * ( T_3 * ) V_5 : * ( T_1 * ) V_5 ;
}
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
struct V_33 * V_34 ;
T_3 * V_35 ;
V_34 = V_27 -> V_36 [ V_6 ] ;
if ( V_34 )
V_35 = ( T_3 * ) & V_34 -> V_23 ;
for ( V_30 = 0 ; V_30 < V_24 ; V_30 ++ )
* ( V_4 ++ ) = V_34 ? V_35 [ V_30 ] : 0 ;
V_34 = V_27 -> V_37 [ V_6 ] ;
if ( V_34 )
V_35 = ( T_3 * ) & V_34 -> V_23 ;
for ( V_30 = 0 ; V_30 < V_24 ; V_30 ++ )
* ( V_4 ++ ) = V_34 ? V_35 [ V_30 ] : 0 ;
}
}
static void F_6 ( struct V_38 * V_39 , T_1 * V_40 , int V_6 )
{
int V_41 = 0 ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_8 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_9 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_10 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_11 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_12 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_13 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_14 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_15 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_16 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_17 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_18 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_19 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_20 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_21 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_22 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_23 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_24 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_25 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_26 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_27 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_28 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_29 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_30 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_31 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_32 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_33 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_34 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_35 ( V_6 ) ) ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_36 ( V_6 ) ) ;
F_37 ( V_41 != V_42 ) ;
}
static void F_38 ( struct V_38 * V_39 , T_1 * V_40 , int V_6 )
{
int V_41 = 0 , V_30 ;
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_39 ( V_6 ) ) ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ )
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_40 ( V_6 , V_30 ) ) ;
for ( V_30 = 0 ; V_30 < 32 ; V_30 ++ )
V_40 [ V_41 ++ ] = F_7 ( V_39 , F_41 ( V_6 , V_30 ) ) ;
F_37 ( V_41 != V_43 ) ;
}
static void F_42 ( struct V_1 * V_21 ,
struct V_44 * V_45 , void * V_5 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
T_1 * V_40 = V_5 ;
T_4 V_6 ;
V_45 -> V_46 = ( 1 << 24 ) | ( V_39 -> V_47 << 16 ) | V_39 -> V_48 ;
switch ( V_39 -> V_49 . type ) {
case V_50 :
* ( V_40 ++ ) = F_7 ( V_39 , V_51 ) ;
* ( V_40 ++ ) = F_7 ( V_39 , V_52 ) ;
* ( V_40 ++ ) = F_7 ( V_39 , V_53 ) ;
* ( V_40 ++ ) = F_7 ( V_39 , V_54 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
* ( V_40 ++ ) = F_7 ( V_39 , F_43 ( V_6 ) ) ;
* ( V_40 ++ ) = F_7 ( V_39 , F_44 ( V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 < 65 ; V_6 ++ ) {
F_38 ( V_39 , V_40 , V_6 ) ;
V_40 += V_43 ;
}
* ( V_40 ++ ) = F_7 ( V_39 , V_55 ) ;
* ( V_40 ++ ) = F_7 ( V_39 , V_56 ) ;
for ( V_6 = 0 ; V_6 < V_57 ; V_6 ++ ) {
F_6 ( V_39 , V_40 , V_6 ) ;
V_40 += V_42 ;
}
* ( V_40 ++ ) = F_7 ( V_39 , V_58 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
* ( V_40 ++ ) = F_7 ( V_39 , F_45 ( V_6 ) ) ;
for ( V_6 = 0 ; V_6 < 130 ; V_6 ++ )
* ( V_40 ++ ) = F_7 ( V_39 , F_46 ( V_6 ) ) ;
break;
case V_59 :
* ( V_40 ++ ) = F_7 ( V_39 , V_60 ) ;
* ( V_40 ++ ) = F_7 ( V_39 , V_61 ) ;
* ( V_40 ++ ) = F_7 ( V_39 , V_62 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
* ( V_40 ++ ) = F_7 ( V_39 , F_47 ( V_6 ) ) ;
F_38 ( V_39 , V_40 , 0 ) ;
V_40 += V_43 ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 ++ ) {
if ( V_6 < V_39 -> V_49 . V_64 )
F_6 ( V_39 , V_40 , V_6 ) ;
else
memset ( V_40 , 0 , sizeof( T_1 ) * V_42 ) ;
V_40 += V_42 ;
}
break;
default:
return;
}
}
static int F_48 ( struct V_1 * V_21 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
switch ( V_39 -> V_49 . type ) {
case V_50 :
return V_65 * sizeof( T_1 ) ;
case V_59 :
return V_66 * sizeof( T_1 ) ;
default:
return 0 ;
}
}
static void F_49 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
strncpy ( V_68 -> V_69 , V_70 ,
sizeof( V_68 -> V_69 ) - 1 ) ;
strncpy ( V_68 -> V_46 , V_71 ,
sizeof( V_68 -> V_46 ) - 1 ) ;
strncpy ( V_68 -> V_72 , F_50 ( V_27 -> V_73 ) ,
sizeof( V_68 -> V_72 ) - 1 ) ;
V_68 -> V_74 = V_19 ;
V_68 -> V_75 = F_48 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
V_77 -> V_78 = 0 ;
V_77 -> V_79 = 1 ;
V_77 -> V_80 = V_27 -> V_80 ? 1 : 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
if ( V_77 -> V_78 || ! V_77 -> V_79 )
return - V_81 ;
if ( V_39 -> V_49 . type == V_50 )
V_27 -> V_80 = V_77 -> V_80 ? ~ 0 : 0 ;
else if ( V_77 -> V_80 )
return - V_81 ;
if ( F_53 ( V_2 ) )
F_54 ( V_27 ) ;
return 0 ;
}
static T_1 F_55 ( struct V_1 * V_21 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
return V_27 -> V_82 ;
}
static void F_56 ( struct V_1 * V_21 , T_1 V_4 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
V_27 -> V_82 = V_4 ;
}
static void F_57 ( struct V_1 * V_21 ,
struct V_83 * V_34 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
V_34 -> V_84 = V_85 ;
V_34 -> V_86 = V_87 ;
V_34 -> V_88 = 0 ;
V_34 -> V_89 = 0 ;
V_34 -> V_90 = V_27 -> V_91 ;
V_34 -> V_92 = V_27 -> V_93 ;
V_34 -> V_94 = 0 ;
V_34 -> V_95 = 0 ;
}
static int F_58 ( struct V_1 * V_21 ,
struct V_83 * V_34 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
struct V_33 * V_96 ;
int V_6 , V_97 = 0 ;
T_1 V_98 , V_99 ;
if ( ( V_34 -> V_94 ) || ( V_34 -> V_95 ) )
return - V_81 ;
V_99 = F_59 ( T_1 , V_34 -> V_92 ,
V_100 , V_87 ) ;
V_99 = F_60 ( V_99 , V_101 ) ;
V_98 = F_59 ( T_1 , V_34 -> V_90 ,
V_102 , V_85 ) ;
V_98 = F_60 ( V_98 , V_103 ) ;
if ( ( V_99 == V_27 -> V_93 ) &&
( V_98 == V_27 -> V_91 ) ) {
return 0 ;
}
while ( F_61 ( V_104 , & V_27 -> V_105 ) )
F_62 ( 1000 , 2000 ) ;
if ( ! F_53 ( V_27 -> V_21 ) ) {
for ( V_6 = 0 ; V_6 < V_27 -> V_106 ; V_6 ++ )
V_27 -> V_36 [ V_6 ] -> V_107 = V_99 ;
for ( V_6 = 0 ; V_6 < V_27 -> V_108 ; V_6 ++ )
V_27 -> V_37 [ V_6 ] -> V_107 = V_98 ;
V_27 -> V_93 = V_99 ;
V_27 -> V_91 = V_98 ;
goto V_109;
}
V_6 = F_63 ( int , V_27 -> V_106 , V_27 -> V_108 ) ;
V_96 = F_64 ( V_6 * sizeof( struct V_33 ) ) ;
if ( ! V_96 ) {
V_97 = - V_110 ;
goto V_109;
}
F_65 ( V_27 ) ;
if ( V_99 != V_27 -> V_93 ) {
for ( V_6 = 0 ; V_6 < V_27 -> V_106 ; V_6 ++ ) {
memcpy ( & V_96 [ V_6 ] , V_27 -> V_36 [ V_6 ] ,
sizeof( struct V_33 ) ) ;
V_96 [ V_6 ] . V_107 = V_99 ;
V_97 = F_66 ( & V_96 [ V_6 ] ) ;
if ( V_97 ) {
while ( V_6 ) {
V_6 -- ;
F_67 ( & V_96 [ V_6 ] ) ;
}
goto V_111;
}
}
for ( V_6 = 0 ; V_6 < V_27 -> V_106 ; V_6 ++ ) {
F_67 ( V_27 -> V_36 [ V_6 ] ) ;
memcpy ( V_27 -> V_36 [ V_6 ] , & V_96 [ V_6 ] ,
sizeof( struct V_33 ) ) ;
}
V_27 -> V_93 = V_99 ;
}
if ( V_98 != V_27 -> V_91 ) {
for ( V_6 = 0 ; V_6 < V_27 -> V_108 ; V_6 ++ ) {
memcpy ( & V_96 [ V_6 ] , V_27 -> V_37 [ V_6 ] ,
sizeof( struct V_33 ) ) ;
V_96 [ V_6 ] . V_107 = V_98 ;
V_97 = F_68 ( & V_96 [ V_6 ] ) ;
if ( V_97 ) {
while ( V_6 ) {
V_6 -- ;
F_69 ( & V_96 [ V_6 ] ) ;
}
goto V_111;
}
}
for ( V_6 = 0 ; V_6 < V_27 -> V_108 ; V_6 ++ ) {
F_69 ( V_27 -> V_37 [ V_6 ] ) ;
memcpy ( V_27 -> V_37 [ V_6 ] , & V_96 [ V_6 ] ,
sizeof( struct V_33 ) ) ;
}
V_27 -> V_91 = V_98 ;
}
V_111:
F_70 ( V_27 ) ;
F_71 ( V_96 ) ;
V_109:
F_72 ( V_104 , & V_27 -> V_105 ) ;
return V_97 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
V_113 -> V_114 =
! ! ( V_27 -> V_115 & V_116 ) ;
V_113 -> V_117 = V_27 -> V_115 & ~ V_116 ;
V_113 -> V_118 =
! ! ( V_27 -> V_119 & V_116 ) ;
V_113 -> V_120 = V_27 -> V_119 & ~ V_116 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
struct V_121 * V_122 ;
T_4 V_115 , V_119 ;
int V_6 ;
if ( ( V_113 -> V_120 > V_123 ) ||
( V_113 -> V_117 > V_123 ) )
return - V_81 ;
V_115 = V_113 -> V_117 ;
V_119 = V_113 -> V_120 ;
if ( V_113 -> V_114 )
V_115 = V_116 | V_124 ;
if ( V_113 -> V_118 )
V_119 = V_116 | V_125 ;
V_27 -> V_115 = V_115 ;
V_27 -> V_119 = V_119 ;
for ( V_6 = 0 ; V_6 < V_27 -> V_126 ; V_6 ++ ) {
V_122 = V_27 -> V_127 [ V_6 ] ;
V_122 -> V_128 . V_129 = V_115 ;
V_122 -> V_130 . V_129 = V_119 ;
}
return 0 ;
}
static int F_75 ( struct V_26 * V_27 ,
struct V_131 * V_132 )
{
V_132 -> V_4 = 0 ;
switch ( V_132 -> V_133 ) {
case V_134 :
case V_135 :
V_132 -> V_4 |= V_136 | V_137 ;
case V_138 :
if ( V_27 -> V_139 & V_140 )
V_132 -> V_4 |= V_136 | V_137 ;
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_132 -> V_4 |= V_151 | V_152 ;
break;
case V_153 :
if ( V_27 -> V_139 & V_154 )
V_132 -> V_4 |= V_136 | V_137 ;
V_132 -> V_4 |= V_151 | V_152 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_131 * V_132 ,
T_1 * V_155 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
int V_156 = - V_20 ;
switch ( V_132 -> V_132 ) {
case V_157 :
V_132 -> V_4 = V_27 -> V_108 ;
V_156 = 0 ;
break;
case V_158 :
V_156 = F_75 ( V_27 , V_132 ) ;
break;
default:
break;
}
return V_156 ;
}
static int F_77 ( struct V_26 * V_27 ,
struct V_131 * V_159 )
{
T_1 V_139 = V_27 -> V_139 ;
if ( V_159 -> V_4 & ~ ( V_151 | V_152 |
V_136 | V_137 ) )
return - V_81 ;
switch ( V_159 -> V_133 ) {
case V_134 :
case V_135 :
if ( ! ( V_159 -> V_4 & V_151 ) ||
! ( V_159 -> V_4 & V_152 ) ||
! ( V_159 -> V_4 & V_136 ) ||
! ( V_159 -> V_4 & V_137 ) )
return - V_81 ;
break;
case V_138 :
if ( ! ( V_159 -> V_4 & V_151 ) ||
! ( V_159 -> V_4 & V_152 ) )
return - V_81 ;
switch ( V_159 -> V_4 & ( V_136 | V_137 ) ) {
case 0 :
V_139 &= ~ V_140 ;
break;
case ( V_136 | V_137 ) :
V_139 |= V_140 ;
break;
default:
return - V_81 ;
}
break;
case V_153 :
if ( ! ( V_159 -> V_4 & V_151 ) ||
! ( V_159 -> V_4 & V_152 ) )
return - V_81 ;
switch ( V_159 -> V_4 & ( V_136 | V_137 ) ) {
case 0 :
V_139 &= ~ V_154 ;
break;
case ( V_136 | V_137 ) :
V_139 |= V_154 ;
break;
default:
return - V_81 ;
}
break;
case V_143 :
case V_145 :
case V_147 :
case V_141 :
case V_144 :
case V_146 :
case V_148 :
case V_142 :
if ( ! ( V_159 -> V_4 & V_151 ) ||
! ( V_159 -> V_4 & V_152 ) ||
( V_159 -> V_4 & V_136 ) ||
( V_159 -> V_4 & V_137 ) )
return - V_81 ;
break;
default:
return - V_81 ;
}
if ( V_139 != V_27 -> V_139 ) {
struct V_38 * V_39 = & V_27 -> V_39 ;
T_1 V_160 ;
if ( ( V_139 & V_161 ) &&
! ( V_27 -> V_139 & V_161 ) )
F_78 ( V_27 , V_162 , V_27 -> V_21 ,
L_5 ) ;
V_27 -> V_139 = V_139 ;
V_160 = V_163 |
V_164 |
V_165 |
V_166 ;
if ( V_139 & V_140 )
V_160 |= V_167 ;
if ( V_139 & V_154 )
V_160 |= V_168 ;
F_79 ( V_39 , F_39 ( 0 ) , V_160 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
int V_156 = - V_20 ;
switch ( V_132 -> V_132 ) {
case V_169 :
V_156 = F_77 ( V_27 , V_132 ) ;
break;
default:
break;
}
return V_156 ;
}
static int F_81 ( struct V_26 * V_27 , T_3 * V_4 )
{
struct V_38 * V_39 = & V_27 -> V_39 ;
struct V_170 * V_171 = & V_39 -> V_171 ;
T_1 V_172 , V_173 [ 6 ] ;
unsigned long V_174 ;
int V_97 ;
if ( V_39 -> V_49 . type != V_59 )
return 0 ;
for ( V_172 = ( 1 << V_175 ) ;
V_172 < ( 1 << ( 2 * V_176 ) ) ;
V_172 += V_172 ) {
F_82 ( V_173 , V_172 ) ;
F_83 ( V_27 ) ;
V_171 -> V_177 = V_178 ;
V_97 = V_171 -> V_179 . V_180 ( V_39 , V_171 , V_173 ) ;
F_84 ( V_27 ) ;
V_174 = V_181 + V_182 ;
do {
if ( V_97 < 0 )
goto V_183;
F_62 ( 500 , 1000 ) ;
F_83 ( V_27 ) ;
V_171 -> V_179 . V_184 ( V_39 , V_171 ) ;
F_84 ( V_27 ) ;
V_97 = V_171 -> V_177 ;
if ( ! V_97 )
break;
} while ( F_85 ( V_174 ) );
if ( V_97 )
goto V_183;
}
V_183:
* V_4 = V_97 < 0 ? ( V_172 ) : ( V_97 > 0 ) ;
return V_97 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_185 * V_186 , T_3 * V_4 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
memset ( V_4 , 0 , sizeof( * V_4 ) * V_9 ) ;
if ( F_87 ( V_39 ) ) {
F_88 ( V_27 , V_162 , V_2 ,
L_6 ) ;
V_186 -> V_139 |= V_187 ;
return;
}
if ( F_81 ( V_27 , & V_4 [ V_188 ] ) )
V_186 -> V_139 |= V_187 ;
}
static T_1 F_89 ( struct V_1 * V_21 )
{
return V_189 * V_190 ;
}
static int F_90 ( struct V_1 * V_21 , T_1 * V_191 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
int V_6 ;
if ( ! V_191 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_189 ; V_6 ++ , V_191 += 4 ) {
T_1 V_192 = V_27 -> V_192 [ V_6 ] ;
V_191 [ 0 ] = ( V_192 << 24 ) >> 24 ;
V_191 [ 1 ] = ( V_192 << 16 ) >> 24 ;
V_191 [ 2 ] = ( V_192 << 8 ) >> 24 ;
V_191 [ 3 ] = ( V_192 ) >> 24 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_21 , const T_1 * V_191 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
int V_6 ;
T_4 V_193 ;
if ( ! V_191 )
return 0 ;
V_193 = V_27 -> V_194 [ V_195 ] . V_196 ;
for ( V_6 = F_89 ( V_21 ) ; V_6 -- ; ) {
if ( V_191 [ V_6 ] < V_193 )
continue;
return - V_81 ;
}
for ( V_6 = 0 ; V_6 < V_189 ; V_6 ++ , V_191 += 4 ) {
T_1 V_192 = V_191 [ 0 ] |
( V_191 [ 1 ] << 8 ) |
( V_191 [ 2 ] << 16 ) |
( V_191 [ 3 ] << 24 ) ;
if ( V_27 -> V_192 [ V_6 ] == V_192 )
continue;
V_27 -> V_192 [ V_6 ] = V_192 ;
F_79 ( V_39 , F_41 ( 0 , V_6 ) , V_192 ) ;
}
return 0 ;
}
static T_1 F_92 ( struct V_1 * V_21 )
{
return V_197 * V_198 ;
}
static int F_93 ( struct V_1 * V_21 , T_1 * V_191 , T_2 * V_199 ,
T_2 * V_200 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
int V_6 , V_97 ;
if ( V_200 )
* V_200 = V_201 ;
V_97 = F_90 ( V_21 , V_191 ) ;
if ( V_97 || ! V_199 )
return V_97 ;
for ( V_6 = 0 ; V_6 < V_197 ; V_6 ++ , V_199 += 4 )
* ( V_202 * ) V_199 = F_94 ( V_27 -> V_203 [ V_6 ] ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_21 , const T_1 * V_191 ,
const T_2 * V_199 , const T_2 V_200 )
{
struct V_26 * V_27 = F_4 ( V_21 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
int V_6 , V_97 ;
if ( V_200 != V_204 && V_200 != V_201 )
return - V_20 ;
V_97 = F_91 ( V_21 , V_191 ) ;
if ( V_97 || ! V_199 )
return V_97 ;
for ( V_6 = 0 ; V_6 < V_197 ; V_6 ++ , V_199 += 4 ) {
T_1 V_203 = F_96 ( * ( V_202 * ) V_199 ) ;
if ( V_27 -> V_203 [ V_6 ] == V_203 )
continue;
V_27 -> V_203 [ V_6 ] = V_203 ;
F_79 ( V_39 , F_40 ( 0 , V_6 ) , V_203 ) ;
}
return 0 ;
}
static unsigned int F_97 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
unsigned int V_205 = V_27 -> V_39 . V_49 . V_64 ;
T_2 V_206 = F_98 ( V_2 ) ;
if ( V_206 > 1 )
V_205 = 1 << ( F_99 ( V_205 / V_206 ) - 1 ) ;
return V_205 ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
struct V_38 * V_39 = & V_27 -> V_39 ;
V_208 -> V_205 = F_97 ( V_2 ) ;
V_208 -> V_209 = F_101 ( V_39 ) ;
V_208 -> V_210 = V_208 -> V_209 ;
V_208 -> V_211 = V_27 -> V_194 [ V_195 ] . V_196 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
unsigned int V_107 = V_208 -> V_211 ;
struct V_38 * V_39 = & V_27 -> V_39 ;
if ( ! V_107 || V_208 -> V_212 || V_208 -> V_213 )
return - V_81 ;
if ( V_208 -> V_210 != F_101 ( V_39 ) )
return - V_81 ;
if ( V_107 > F_97 ( V_2 ) )
return - V_81 ;
V_27 -> V_194 [ V_195 ] . V_214 = V_107 ;
return F_103 ( V_2 , F_98 ( V_2 ) ) ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_215 * V_68 )
{
struct V_26 * V_27 = F_4 ( V_2 ) ;
V_68 -> V_216 =
V_217 |
V_218 |
V_219 |
V_220 |
V_221 |
V_222 ;
if ( V_27 -> V_223 )
V_68 -> V_224 = F_105 ( V_27 -> V_223 ) ;
else
V_68 -> V_224 = - 1 ;
V_68 -> V_225 = ( 1 << V_226 ) |
( 1 << V_227 ) ;
V_68 -> V_228 = ( 1 << V_229 ) |
( 1 << V_230 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
V_2 -> V_231 = & V_232 ;
}
