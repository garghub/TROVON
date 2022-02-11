static void F_1 ( char * * V_1 , const char * V_2 ,
const struct V_3 V_4 [] ,
const unsigned int V_5 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
snprintf ( * V_1 , V_7 , L_1 ,
V_2 , V_4 [ V_6 ] . V_8 ) ;
* V_1 += V_7 ;
}
}
static void F_2 ( struct V_9 * V_10 , T_1 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
char * V_1 = ( char * ) V_11 ;
unsigned int V_6 ;
F_1 ( & V_1 , L_2 , V_14 ,
V_15 ) ;
F_1 ( & V_1 , L_2 , V_16 ,
V_17 ) ;
F_1 ( & V_1 , L_2 , V_18 ,
V_19 ) ;
if ( V_13 -> V_20 . V_21 . type != V_22 )
F_1 ( & V_1 , L_2 , V_23 ,
V_24 ) ;
for ( V_6 = 0 ; V_6 < V_13 -> V_20 . V_21 . V_25 ; V_6 ++ ) {
char V_2 [ V_7 ] ;
snprintf ( V_2 , V_7 , L_3 , V_6 ) ;
F_1 ( & V_1 , V_2 ,
V_26 ,
V_27 ) ;
snprintf ( V_2 , V_7 , L_4 , V_6 ) ;
F_1 ( & V_1 , V_2 ,
V_26 ,
V_27 ) ;
}
}
static void F_4 ( struct V_9 * V_10 ,
T_2 V_28 , T_1 * V_11 )
{
char * V_1 = ( char * ) V_11 ;
switch ( V_28 ) {
case V_29 :
memcpy ( V_11 , * V_30 ,
V_31 * V_7 ) ;
break;
case V_32 :
F_2 ( V_10 , V_11 ) ;
break;
case V_33 :
memcpy ( V_1 , V_34 ,
V_35 * V_7 ) ;
break;
}
}
static int F_5 ( struct V_9 * V_10 , int V_36 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
int V_38 = V_39 ;
switch ( V_36 ) {
case V_29 :
return V_31 ;
case V_32 :
V_38 += V_20 -> V_21 . V_25 * 2 * V_27 ;
if ( V_20 -> V_21 . type != V_22 )
V_38 += V_24 ;
return V_38 ;
case V_33 :
return V_35 ;
default:
return - V_40 ;
}
}
static void F_6 ( T_3 * * V_11 , void * V_41 ,
const struct V_3 V_4 [] ,
const unsigned int V_5 )
{
unsigned int V_6 ;
char * V_1 ;
if ( ! V_41 ) {
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
* ( ( * V_11 ) ++ ) = 0 ;
return;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_1 = ( char * ) V_41 + V_4 [ V_6 ] . V_42 ;
switch ( V_4 [ V_6 ] . V_43 ) {
case sizeof( T_3 ) :
* ( ( * V_11 ) ++ ) = * ( T_3 * ) V_1 ;
break;
case sizeof( T_2 ) :
* ( ( * V_11 ) ++ ) = * ( T_2 * ) V_1 ;
break;
case sizeof( V_44 ) :
* ( ( * V_11 ) ++ ) = * ( V_44 * ) V_1 ;
break;
case sizeof( T_1 ) :
* ( ( * V_11 ) ++ ) = * ( T_1 * ) V_1 ;
break;
default:
* ( ( * V_11 ) ++ ) = 0 ;
}
}
}
static void F_7 ( struct V_9 * V_45 ,
struct V_46 T_4 * V_4 ,
T_3 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
struct V_47 * V_48 = & V_45 -> V_4 ;
int V_6 ;
F_8 ( V_13 ) ;
F_6 ( & V_11 , V_48 , V_14 ,
V_15 ) ;
F_6 ( & V_11 , V_13 , V_16 ,
V_17 ) ;
F_6 ( & V_11 , & V_13 -> V_20 . V_49 ,
V_18 ,
V_19 ) ;
if ( V_13 -> V_20 . V_21 . type != V_22 ) {
F_6 ( & V_11 , V_13 ,
V_23 ,
V_24 ) ;
}
for ( V_6 = 0 ; V_6 < V_13 -> V_20 . V_21 . V_25 ; V_6 ++ ) {
struct V_50 * V_51 ;
V_51 = V_13 -> V_52 [ V_6 ] ;
F_6 ( & V_11 , V_51 ,
V_26 ,
V_27 ) ;
V_51 = V_13 -> V_53 [ V_6 ] ;
F_6 ( & V_11 , V_51 ,
V_26 ,
V_27 ) ;
}
}
static void F_9 ( struct V_37 * V_20 , T_2 * V_54 , int V_6 )
{
int V_55 = 0 ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_11 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_12 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_13 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_14 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_15 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_16 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_17 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_18 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_19 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_20 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_21 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_22 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_23 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_24 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_25 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_26 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_27 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_28 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_29 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_30 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_31 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_32 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_33 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_34 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_35 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_36 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_37 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_38 ( V_6 ) ) ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_39 ( V_6 ) ) ;
F_40 ( V_55 != V_56 ) ;
}
static void F_41 ( struct V_37 * V_20 , T_2 * V_54 , int V_6 )
{
int V_55 = 0 , V_57 ;
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_42 ( V_6 ) ) ;
for ( V_57 = 0 ; V_57 < 10 ; V_57 ++ )
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_43 ( V_6 , V_57 ) ) ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ )
V_54 [ V_55 ++ ] = F_10 ( V_20 , F_44 ( V_6 , V_57 ) ) ;
F_40 ( V_55 != V_58 ) ;
}
static void F_45 ( struct V_9 * V_45 ,
struct V_59 * V_60 , void * V_1 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
T_2 * V_54 = V_1 ;
V_44 V_6 ;
V_60 -> V_61 = F_46 ( 24 ) | ( V_20 -> V_62 << 16 ) | V_20 -> V_63 ;
switch ( V_20 -> V_21 . type ) {
case V_64 :
* ( V_54 ++ ) = F_10 ( V_20 , V_65 ) ;
* ( V_54 ++ ) = F_10 ( V_20 , V_66 ) ;
* ( V_54 ++ ) = F_10 ( V_20 , V_67 ) ;
* ( V_54 ++ ) = F_10 ( V_20 , V_68 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
* ( V_54 ++ ) = F_10 ( V_20 , F_47 ( V_6 ) ) ;
* ( V_54 ++ ) = F_10 ( V_20 , F_48 ( V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 < 65 ; V_6 ++ ) {
F_41 ( V_20 , V_54 , V_6 ) ;
V_54 += V_58 ;
}
* ( V_54 ++ ) = F_10 ( V_20 , V_69 ) ;
* ( V_54 ++ ) = F_10 ( V_20 , V_70 ) ;
for ( V_6 = 0 ; V_6 < V_71 ; V_6 ++ ) {
F_9 ( V_20 , V_54 , V_6 ) ;
V_54 += V_56 ;
}
* ( V_54 ++ ) = F_10 ( V_20 , V_72 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
* ( V_54 ++ ) = F_10 ( V_20 , F_49 ( V_6 ) ) ;
for ( V_6 = 0 ; V_6 < 130 ; V_6 ++ )
* ( V_54 ++ ) = F_10 ( V_20 , F_50 ( V_6 ) ) ;
break;
case V_22 :
* ( V_54 ++ ) = F_10 ( V_20 , V_73 ) ;
* ( V_54 ++ ) = F_10 ( V_20 , V_74 ) ;
* ( V_54 ++ ) = F_10 ( V_20 , V_75 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
* ( V_54 ++ ) = F_10 ( V_20 , F_51 ( V_6 ) ) ;
F_41 ( V_20 , V_54 , 0 ) ;
V_54 += V_58 ;
for ( V_6 = 0 ; V_6 < V_76 ; V_6 ++ ) {
if ( V_6 < V_20 -> V_21 . V_25 )
F_9 ( V_20 , V_54 , V_6 ) ;
else
memset ( V_54 , 0 , sizeof( T_2 ) * V_56 ) ;
V_54 += V_56 ;
}
break;
default:
return;
}
}
static int F_52 ( struct V_9 * V_45 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
switch ( V_20 -> V_21 . type ) {
case V_64 :
return V_77 * sizeof( T_2 ) ;
case V_22 :
return V_78 * sizeof( T_2 ) ;
default:
return 0 ;
}
}
static void F_53 ( struct V_9 * V_10 ,
struct V_79 * V_80 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
strncpy ( V_80 -> V_81 , V_82 ,
sizeof( V_80 -> V_81 ) - 1 ) ;
strncpy ( V_80 -> V_61 , V_83 ,
sizeof( V_80 -> V_61 ) - 1 ) ;
strncpy ( V_80 -> V_84 , F_54 ( V_13 -> V_85 ) ,
sizeof( V_80 -> V_84 ) - 1 ) ;
}
static void F_55 ( struct V_9 * V_10 ,
struct V_86 * V_87 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
V_87 -> V_88 = 0 ;
V_87 -> V_89 = 1 ;
V_87 -> V_90 = V_13 -> V_90 ? 1 : 0 ;
}
static int F_56 ( struct V_9 * V_10 ,
struct V_86 * V_87 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
if ( V_87 -> V_88 || ! V_87 -> V_89 )
return - V_91 ;
if ( V_20 -> V_21 . type == V_64 )
V_13 -> V_90 = V_87 -> V_90 ? ~ 0 : 0 ;
else if ( V_87 -> V_90 )
return - V_91 ;
if ( F_57 ( V_10 ) )
F_58 ( V_13 ) ;
return 0 ;
}
static T_2 F_59 ( struct V_9 * V_45 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
return V_13 -> V_92 ;
}
static void F_60 ( struct V_9 * V_45 , T_2 V_11 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
V_13 -> V_92 = V_11 ;
}
static void F_61 ( struct V_9 * V_45 ,
struct V_93 * V_51 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
V_51 -> V_94 = V_95 ;
V_51 -> V_96 = V_97 ;
V_51 -> V_98 = 0 ;
V_51 -> V_99 = 0 ;
V_51 -> V_100 = V_13 -> V_101 ;
V_51 -> V_102 = V_13 -> V_103 ;
V_51 -> V_104 = 0 ;
V_51 -> V_105 = 0 ;
}
static int F_62 ( struct V_9 * V_45 ,
struct V_93 * V_51 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
struct V_50 * V_106 ;
int V_6 , V_107 = 0 ;
T_2 V_108 , V_109 ;
if ( ( V_51 -> V_104 ) || ( V_51 -> V_105 ) )
return - V_91 ;
V_109 = F_63 ( T_2 , V_51 -> V_102 ,
V_110 , V_97 ) ;
V_109 = F_64 ( V_109 , V_111 ) ;
V_108 = F_63 ( T_2 , V_51 -> V_100 ,
V_112 , V_95 ) ;
V_108 = F_64 ( V_108 , V_113 ) ;
if ( ( V_109 == V_13 -> V_103 ) &&
( V_108 == V_13 -> V_101 ) ) {
return 0 ;
}
while ( F_65 ( V_114 , & V_13 -> V_115 ) )
F_66 ( 1000 , 2000 ) ;
if ( ! F_57 ( V_13 -> V_45 ) ) {
for ( V_6 = 0 ; V_6 < V_13 -> V_116 ; V_6 ++ )
V_13 -> V_52 [ V_6 ] -> V_117 = V_109 ;
for ( V_6 = 0 ; V_6 < V_13 -> V_118 ; V_6 ++ )
V_13 -> V_53 [ V_6 ] -> V_117 = V_108 ;
V_13 -> V_103 = V_109 ;
V_13 -> V_101 = V_108 ;
goto V_119;
}
V_6 = F_67 ( int , V_13 -> V_116 , V_13 -> V_118 ) ;
V_106 = F_68 ( V_6 * sizeof( struct V_50 ) ) ;
if ( ! V_106 ) {
V_107 = - V_120 ;
goto V_119;
}
F_69 ( V_13 ) ;
if ( V_109 != V_13 -> V_103 ) {
for ( V_6 = 0 ; V_6 < V_13 -> V_116 ; V_6 ++ ) {
memcpy ( & V_106 [ V_6 ] , V_13 -> V_52 [ V_6 ] ,
sizeof( struct V_50 ) ) ;
V_106 [ V_6 ] . V_117 = V_109 ;
V_107 = F_70 ( & V_106 [ V_6 ] ) ;
if ( V_107 ) {
while ( V_6 ) {
V_6 -- ;
F_71 ( & V_106 [ V_6 ] ) ;
}
goto V_121;
}
}
for ( V_6 = 0 ; V_6 < V_13 -> V_116 ; V_6 ++ ) {
F_71 ( V_13 -> V_52 [ V_6 ] ) ;
memcpy ( V_13 -> V_52 [ V_6 ] , & V_106 [ V_6 ] ,
sizeof( struct V_50 ) ) ;
}
V_13 -> V_103 = V_109 ;
}
if ( V_108 != V_13 -> V_101 ) {
for ( V_6 = 0 ; V_6 < V_13 -> V_118 ; V_6 ++ ) {
memcpy ( & V_106 [ V_6 ] , V_13 -> V_53 [ V_6 ] ,
sizeof( struct V_50 ) ) ;
V_106 [ V_6 ] . V_117 = V_108 ;
V_107 = F_72 ( & V_106 [ V_6 ] ) ;
if ( V_107 ) {
while ( V_6 ) {
V_6 -- ;
F_73 ( & V_106 [ V_6 ] ) ;
}
goto V_121;
}
}
for ( V_6 = 0 ; V_6 < V_13 -> V_118 ; V_6 ++ ) {
F_73 ( V_13 -> V_53 [ V_6 ] ) ;
memcpy ( V_13 -> V_53 [ V_6 ] , & V_106 [ V_6 ] ,
sizeof( struct V_50 ) ) ;
}
V_13 -> V_101 = V_108 ;
}
V_121:
F_74 ( V_13 ) ;
F_75 ( V_106 ) ;
V_119:
F_76 ( V_114 , & V_13 -> V_115 ) ;
return V_107 ;
}
static int F_77 ( struct V_9 * V_10 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
V_123 -> V_124 = F_78 ( V_13 -> V_125 ) ;
V_123 -> V_126 = V_13 -> V_125 & ~ V_127 ;
V_123 -> V_128 = F_78 ( V_13 -> V_129 ) ;
V_123 -> V_130 = V_13 -> V_129 & ~ V_127 ;
return 0 ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
struct V_131 * V_132 ;
V_44 V_125 , V_129 ;
int V_6 ;
if ( ( V_123 -> V_130 > V_133 ) ||
( V_123 -> V_126 > V_133 ) )
return - V_91 ;
V_125 = V_123 -> V_126 ;
V_129 = V_123 -> V_130 ;
if ( V_123 -> V_124 )
V_125 = V_127 | V_134 ;
if ( V_123 -> V_128 )
V_129 = V_127 | V_135 ;
V_13 -> V_125 = V_125 ;
V_13 -> V_129 = V_129 ;
for ( V_6 = 0 ; V_6 < V_13 -> V_136 ; V_6 ++ ) {
V_132 = V_13 -> V_137 [ V_6 ] ;
V_132 -> V_138 . V_139 = V_125 ;
V_132 -> V_140 . V_139 = V_129 ;
}
return 0 ;
}
static int F_80 ( struct V_12 * V_13 ,
struct V_141 * V_142 )
{
V_142 -> V_11 = 0 ;
switch ( V_142 -> V_143 ) {
case V_144 :
case V_145 :
V_142 -> V_11 |= V_146 | V_147 ;
case V_148 :
if ( V_13 -> V_149 & V_150 )
V_142 -> V_11 |= V_146 | V_147 ;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
V_142 -> V_11 |= V_161 | V_162 ;
break;
case V_163 :
if ( V_13 -> V_149 & V_164 )
V_142 -> V_11 |= V_146 | V_147 ;
V_142 -> V_11 |= V_161 | V_162 ;
break;
default:
return - V_91 ;
}
return 0 ;
}
static int F_81 ( struct V_9 * V_10 , struct V_141 * V_142 ,
T_2 T_4 * V_165 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
int V_166 = - V_40 ;
switch ( V_142 -> V_142 ) {
case V_167 :
V_142 -> V_11 = V_13 -> V_118 ;
V_166 = 0 ;
break;
case V_168 :
V_166 = F_80 ( V_13 , V_142 ) ;
break;
default:
break;
}
return V_166 ;
}
static int F_82 ( struct V_12 * V_13 ,
struct V_141 * V_169 )
{
T_2 V_149 = V_13 -> V_149 ;
if ( V_169 -> V_11 & ~ ( V_161 | V_162 |
V_146 | V_147 ) )
return - V_91 ;
switch ( V_169 -> V_143 ) {
case V_144 :
case V_145 :
if ( ! ( V_169 -> V_11 & V_161 ) ||
! ( V_169 -> V_11 & V_162 ) ||
! ( V_169 -> V_11 & V_146 ) ||
! ( V_169 -> V_11 & V_147 ) )
return - V_91 ;
break;
case V_148 :
if ( ! ( V_169 -> V_11 & V_161 ) ||
! ( V_169 -> V_11 & V_162 ) )
return - V_91 ;
switch ( V_169 -> V_11 & ( V_146 | V_147 ) ) {
case 0 :
V_149 &= ~ V_150 ;
break;
case ( V_146 | V_147 ) :
V_149 |= V_150 ;
break;
default:
return - V_91 ;
}
break;
case V_163 :
if ( ! ( V_169 -> V_11 & V_161 ) ||
! ( V_169 -> V_11 & V_162 ) )
return - V_91 ;
switch ( V_169 -> V_11 & ( V_146 | V_147 ) ) {
case 0 :
V_149 &= ~ V_164 ;
break;
case ( V_146 | V_147 ) :
V_149 |= V_164 ;
break;
default:
return - V_91 ;
}
break;
case V_153 :
case V_155 :
case V_157 :
case V_151 :
case V_154 :
case V_156 :
case V_158 :
case V_152 :
if ( ! ( V_169 -> V_11 & V_161 ) ||
! ( V_169 -> V_11 & V_162 ) ||
( V_169 -> V_11 & V_146 ) ||
( V_169 -> V_11 & V_147 ) )
return - V_91 ;
break;
default:
return - V_91 ;
}
if ( V_149 != V_13 -> V_149 ) {
struct V_37 * V_20 = & V_13 -> V_20 ;
T_2 V_170 ;
if ( ( V_149 & V_171 ) &&
! ( V_13 -> V_149 & V_171 ) )
F_83 ( V_13 , V_172 , V_13 -> V_45 ,
L_5 ) ;
V_13 -> V_149 = V_149 ;
V_170 = V_173 |
V_174 |
V_175 |
V_176 ;
if ( V_149 & V_150 )
V_170 |= V_177 ;
if ( V_149 & V_164 )
V_170 |= V_178 ;
F_84 ( V_20 , F_42 ( 0 ) , V_170 ) ;
}
return 0 ;
}
static int F_85 ( struct V_9 * V_10 , struct V_141 * V_142 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
int V_166 = - V_40 ;
switch ( V_142 -> V_142 ) {
case V_179 :
V_166 = F_82 ( V_13 , V_142 ) ;
break;
default:
break;
}
return V_166 ;
}
static int F_86 ( struct V_12 * V_13 , T_3 * V_11 )
{
struct V_37 * V_20 = & V_13 -> V_20 ;
struct V_180 * V_49 = & V_20 -> V_49 ;
T_2 V_181 , V_182 [ 6 ] ;
unsigned long V_183 ;
int V_107 = - V_91 ;
if ( V_20 -> V_21 . type != V_22 )
return 0 ;
for ( V_181 = F_46 ( V_184 ) ;
V_181 < F_46 ( 2 * V_185 ) ;
V_181 += V_181 ) {
F_87 ( V_182 , V_181 ) ;
F_88 ( V_13 ) ;
V_49 -> V_186 = V_187 ;
V_107 = V_49 -> V_188 . V_189 ( V_20 , V_49 , V_182 ) ;
F_89 ( V_13 ) ;
V_183 = V_190 + V_191 ;
do {
if ( V_107 < 0 )
goto V_192;
F_66 ( 500 , 1000 ) ;
F_88 ( V_13 ) ;
V_49 -> V_188 . V_193 ( V_20 , V_49 ) ;
F_89 ( V_13 ) ;
V_107 = V_49 -> V_186 ;
if ( ! V_107 )
break;
} while ( F_90 ( V_183 ) );
if ( V_107 )
goto V_192;
}
V_192:
* V_11 = V_107 < 0 ? ( V_181 ) : ( V_107 > 0 ) ;
return V_107 ;
}
static void F_91 ( struct V_9 * V_10 ,
struct V_194 * V_195 , T_3 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
memset ( V_11 , 0 , sizeof( * V_11 ) * V_31 ) ;
if ( F_92 ( V_20 ) ) {
F_93 ( V_13 , V_172 , V_10 ,
L_6 ) ;
V_195 -> V_149 |= V_196 ;
return;
}
if ( F_86 ( V_13 , & V_11 [ V_197 ] ) )
V_195 -> V_149 |= V_196 ;
}
static T_2 F_94 ( struct V_9 * V_45 )
{
return 0 ;
}
static int F_95 ( struct V_9 * V_45 , T_2 V_198 )
{
if ( V_198 >= F_46 ( V_35 ) )
return - V_91 ;
return 0 ;
}
T_2 F_96 ( struct V_9 T_4 * V_45 )
{
return V_199 * V_200 ;
}
void F_97 ( struct V_12 * V_13 , const T_2 * V_201 )
{
V_44 V_202 = V_13 -> V_203 [ V_204 ] . V_205 ;
struct V_37 * V_20 = & V_13 -> V_20 ;
T_2 V_206 [ 4 ] ;
int V_6 , V_57 ;
for ( V_6 = 0 ; V_6 < V_199 ; V_6 ++ ) {
T_2 V_207 , V_208 ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
if ( V_201 )
V_208 = V_201 [ V_6 + V_57 ] ;
else
V_208 = F_98 ( V_6 + V_57 , V_202 ) ;
V_206 [ V_57 ] = V_208 ;
}
V_207 = V_206 [ 0 ] |
( V_206 [ 1 ] << 8 ) |
( V_206 [ 2 ] << 16 ) |
( V_206 [ 3 ] << 24 ) ;
if ( V_13 -> V_207 [ V_6 ] == V_207 )
continue;
V_13 -> V_207 [ V_6 ] = V_207 ;
F_84 ( V_20 , F_44 ( 0 , V_6 ) , V_207 ) ;
}
}
static int F_99 ( struct V_9 * V_45 , T_2 * V_201 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
int V_6 ;
if ( ! V_201 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_199 ; V_6 ++ , V_201 += 4 ) {
T_2 V_207 = V_13 -> V_207 [ V_6 ] ;
V_201 [ 0 ] = ( V_207 << 24 ) >> 24 ;
V_201 [ 1 ] = ( V_207 << 16 ) >> 24 ;
V_201 [ 2 ] = ( V_207 << 8 ) >> 24 ;
V_201 [ 3 ] = ( V_207 ) >> 24 ;
}
return 0 ;
}
static int F_100 ( struct V_9 * V_45 , const T_2 * V_201 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
int V_6 ;
V_44 V_202 ;
if ( ! V_201 )
return 0 ;
V_202 = V_13 -> V_203 [ V_204 ] . V_205 ;
for ( V_6 = F_96 ( V_45 ) ; V_6 -- ; ) {
if ( V_201 [ V_6 ] < V_202 )
continue;
return - V_91 ;
}
F_97 ( V_13 , V_201 ) ;
return 0 ;
}
static T_2 F_101 ( struct V_9 T_4 * V_45 )
{
return V_209 * V_210 ;
}
static int F_102 ( struct V_9 * V_45 , T_2 * V_201 , T_1 * V_211 ,
T_1 * V_212 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
int V_6 , V_107 ;
if ( V_212 )
* V_212 = V_213 ;
V_107 = F_99 ( V_45 , V_201 ) ;
if ( V_107 || ! V_211 )
return V_107 ;
for ( V_6 = 0 ; V_6 < V_209 ; V_6 ++ , V_211 += 4 )
* ( V_214 * ) V_211 = F_103 ( V_13 -> V_215 [ V_6 ] ) ;
return 0 ;
}
static int F_104 ( struct V_9 * V_45 , const T_2 * V_201 ,
const T_1 * V_211 , const T_1 V_212 )
{
struct V_12 * V_13 = F_3 ( V_45 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
int V_6 , V_107 ;
if ( V_212 != V_216 && V_212 != V_213 )
return - V_40 ;
V_107 = F_100 ( V_45 , V_201 ) ;
if ( V_107 || ! V_211 )
return V_107 ;
for ( V_6 = 0 ; V_6 < V_209 ; V_6 ++ , V_211 += 4 ) {
T_2 V_215 = F_105 ( * ( V_214 * ) V_211 ) ;
if ( V_13 -> V_215 [ V_6 ] == V_215 )
continue;
V_13 -> V_215 [ V_6 ] = V_215 ;
F_84 ( V_20 , F_43 ( 0 , V_6 ) , V_215 ) ;
}
return 0 ;
}
static unsigned int F_106 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
unsigned int V_217 = V_13 -> V_20 . V_21 . V_25 ;
T_1 V_218 = F_107 ( V_10 ) ;
if ( V_218 > 1 )
V_217 = F_46 ( ( F_108 ( V_217 / V_218 ) - 1 ) ) ;
return V_217 ;
}
static void F_109 ( struct V_9 * V_10 ,
struct V_219 * V_220 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
struct V_37 * V_20 = & V_13 -> V_20 ;
V_220 -> V_217 = F_106 ( V_10 ) ;
V_220 -> V_221 = F_110 ( V_20 ) ;
V_220 -> V_222 = V_220 -> V_221 ;
V_220 -> V_223 = V_13 -> V_203 [ V_204 ] . V_205 ;
}
static int F_111 ( struct V_9 * V_10 ,
struct V_219 * V_220 )
{
struct V_12 * V_13 = F_3 ( V_10 ) ;
unsigned int V_117 = V_220 -> V_223 ;
struct V_37 * V_20 = & V_13 -> V_20 ;
if ( ! V_117 || V_220 -> V_224 || V_220 -> V_225 )
return - V_91 ;
if ( V_220 -> V_222 != F_110 ( V_20 ) )
return - V_91 ;
if ( V_117 > F_106 ( V_10 ) )
return - V_91 ;
V_13 -> V_203 [ V_204 ] . V_226 = V_117 ;
return F_112 ( V_10 , F_107 ( V_10 ) ) ;
}
void F_113 ( struct V_9 * V_10 )
{
V_10 -> V_227 = & V_228 ;
}
