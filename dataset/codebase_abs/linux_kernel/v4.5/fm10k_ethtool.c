static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
char * V_8 = ( char * ) V_3 ;
unsigned int V_9 ;
unsigned int V_10 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
memcpy ( V_8 , V_12 [ V_9 ] . V_13 ,
V_14 ) ;
V_8 += V_14 ;
}
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
memcpy ( V_8 , V_16 [ V_9 ] . V_13 ,
V_14 ) ;
V_8 += V_14 ;
}
if ( V_5 -> V_17 & V_18 ) {
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
memcpy ( V_8 , V_20 [ V_9 ] . V_13 ,
V_14 ) ;
V_8 += V_14 ;
}
}
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
memcpy ( V_8 , V_22 [ V_9 ] . V_13 ,
V_14 ) ;
V_8 += V_14 ;
}
if ( V_5 -> V_23 . V_24 . type != V_25 ) {
for ( V_9 = 0 ; V_9 < V_26 ; V_9 ++ ) {
memcpy ( V_8 , V_27 [ V_9 ] . V_13 ,
V_14 ) ;
V_8 += V_14 ;
}
}
if ( ( V_5 -> V_17 & V_18 ) && V_7 ) {
for ( V_9 = 0 ; V_9 < V_7 -> V_28 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ ) {
snprintf ( V_8 ,
V_14 ,
L_1 , V_9 ,
V_22 [ V_10 ] . V_13 ) ;
V_8 += V_14 ;
}
}
}
for ( V_9 = 0 ; V_9 < V_5 -> V_23 . V_24 . V_29 ; V_9 ++ ) {
snprintf ( V_8 , V_14 , L_2 , V_9 ) ;
V_8 += V_14 ;
snprintf ( V_8 , V_14 , L_3 , V_9 ) ;
V_8 += V_14 ;
snprintf ( V_8 , V_14 , L_4 , V_9 ) ;
V_8 += V_14 ;
snprintf ( V_8 , V_14 , L_5 , V_9 ) ;
V_8 += V_14 ;
}
}
static void F_3 ( struct V_1 * V_2 ,
T_2 V_30 , T_1 * V_3 )
{
char * V_8 = ( char * ) V_3 ;
switch ( V_30 ) {
case V_31 :
memcpy ( V_3 , * V_32 ,
V_33 * V_14 ) ;
break;
case V_34 :
F_1 ( V_2 , V_3 ) ;
break;
case V_35 :
memcpy ( V_8 , V_36 ,
V_37 * V_14 ) ;
break;
}
}
static int F_4 ( struct V_1 * V_2 , int V_38 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_39 * V_23 = & V_5 -> V_23 ;
int V_40 = V_41 ;
switch ( V_38 ) {
case V_31 :
return V_33 ;
case V_34 :
V_40 += F_5 ( V_23 -> V_24 . V_29 ) ;
if ( V_23 -> V_24 . type != V_25 )
V_40 += V_26 ;
if ( V_5 -> V_17 & V_18 ) {
V_40 += V_19 ;
if ( V_7 )
V_40 += V_21 *
V_7 -> V_28 ;
}
return V_40 ;
case V_35 :
return V_37 ;
default:
return - V_42 ;
}
}
static void F_6 ( struct V_1 * V_43 ,
struct V_44 T_3 * V_45 ,
T_4 * V_3 )
{
const int V_46 = sizeof( struct V_47 ) / sizeof( T_4 ) ;
struct V_4 * V_5 = F_2 ( V_43 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_48 * V_49 = & V_43 -> V_45 ;
char * V_8 ;
int V_9 , V_10 ;
F_7 ( V_5 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
V_8 = ( char * ) V_49 + V_12 [ V_9 ] . V_50 ;
* ( V_3 ++ ) = ( V_12 [ V_9 ] . V_51 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_8 : * ( T_2 * ) V_8 ;
}
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
V_8 = ( char * ) V_5 +
V_16 [ V_9 ] . V_50 ;
* ( V_3 ++ ) = ( V_16 [ V_9 ] . V_51 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_8 : * ( T_2 * ) V_8 ;
}
if ( V_5 -> V_17 & V_18 ) {
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_8 = ( char * ) V_5 +
V_20 [ V_9 ] . V_50 ;
* ( V_3 ++ ) = ( V_20 [ V_9 ] . V_51 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_8 : * ( T_2 * ) V_8 ;
}
}
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
V_8 = ( char * ) & V_5 -> V_23 . V_52 +
V_22 [ V_9 ] . V_50 ;
* ( V_3 ++ ) = ( V_22 [ V_9 ] . V_51 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_8 : * ( T_2 * ) V_8 ;
}
if ( V_5 -> V_23 . V_24 . type != V_25 ) {
for ( V_9 = 0 ; V_9 < V_26 ; V_9 ++ ) {
V_8 = ( char * ) V_5 +
V_27 [ V_9 ] . V_50 ;
* ( V_3 ++ ) = ( V_27 [ V_9 ] . V_51 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_8 : * ( T_2 * ) V_8 ;
}
}
if ( ( V_5 -> V_17 & V_18 ) && V_7 ) {
for ( V_9 = 0 ; V_9 < V_7 -> V_28 ; V_9 ++ ) {
struct V_53 * V_54 ;
V_54 = & V_7 -> V_54 [ V_9 ] ;
if ( ! V_54 ) {
V_3 += V_21 ;
continue;
}
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ ) {
V_8 = ( char * ) & V_54 -> V_52 +
V_22 [ V_10 ] . V_50 ;
* ( V_3 ++ ) = ( V_22 [ V_10 ] . V_51 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_8 : * ( T_2 * ) V_8 ;
}
}
}
for ( V_9 = 0 ; V_9 < V_5 -> V_23 . V_24 . V_29 ; V_9 ++ ) {
struct V_55 * V_56 ;
T_4 * V_57 ;
V_56 = V_5 -> V_58 [ V_9 ] ;
if ( V_56 )
V_57 = ( T_4 * ) & V_56 -> V_45 ;
for ( V_10 = 0 ; V_10 < V_46 ; V_10 ++ )
* ( V_3 ++ ) = V_56 ? V_57 [ V_10 ] : 0 ;
V_56 = V_5 -> V_59 [ V_9 ] ;
if ( V_56 )
V_57 = ( T_4 * ) & V_56 -> V_45 ;
for ( V_10 = 0 ; V_10 < V_46 ; V_10 ++ )
* ( V_3 ++ ) = V_56 ? V_57 [ V_10 ] : 0 ;
}
}
static void F_8 ( struct V_39 * V_23 , T_2 * V_60 , int V_9 )
{
int V_61 = 0 ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_10 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_11 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_12 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_13 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_14 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_15 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_16 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_17 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_18 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_19 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_20 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_21 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_22 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_23 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_24 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_25 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_26 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_27 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_28 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_29 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_30 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_31 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_32 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_33 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_34 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_35 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_36 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_37 ( V_9 ) ) ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_38 ( V_9 ) ) ;
F_39 ( V_61 != V_62 ) ;
}
static void F_40 ( struct V_39 * V_23 , T_2 * V_60 , int V_9 )
{
int V_61 = 0 , V_10 ;
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_41 ( V_9 ) ) ;
for ( V_10 = 0 ; V_10 < 10 ; V_10 ++ )
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_42 ( V_9 , V_10 ) ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ )
V_60 [ V_61 ++ ] = F_9 ( V_23 , F_43 ( V_9 , V_10 ) ) ;
F_39 ( V_61 != V_63 ) ;
}
static void F_44 ( struct V_1 * V_43 ,
struct V_64 * V_65 , void * V_8 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
T_2 * V_60 = V_8 ;
T_5 V_9 ;
V_65 -> V_66 = ( 1 << 24 ) | ( V_23 -> V_67 << 16 ) | V_23 -> V_68 ;
switch ( V_23 -> V_24 . type ) {
case V_69 :
* ( V_60 ++ ) = F_9 ( V_23 , V_70 ) ;
* ( V_60 ++ ) = F_9 ( V_23 , V_71 ) ;
* ( V_60 ++ ) = F_9 ( V_23 , V_72 ) ;
* ( V_60 ++ ) = F_9 ( V_23 , V_73 ) ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
* ( V_60 ++ ) = F_9 ( V_23 , F_45 ( V_9 ) ) ;
* ( V_60 ++ ) = F_9 ( V_23 , F_46 ( V_9 ) ) ;
}
for ( V_9 = 0 ; V_9 < 65 ; V_9 ++ ) {
F_40 ( V_23 , V_60 , V_9 ) ;
V_60 += V_63 ;
}
* ( V_60 ++ ) = F_9 ( V_23 , V_74 ) ;
* ( V_60 ++ ) = F_9 ( V_23 , V_75 ) ;
for ( V_9 = 0 ; V_9 < V_76 ; V_9 ++ ) {
F_8 ( V_23 , V_60 , V_9 ) ;
V_60 += V_62 ;
}
* ( V_60 ++ ) = F_9 ( V_23 , V_77 ) ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
* ( V_60 ++ ) = F_9 ( V_23 , F_47 ( V_9 ) ) ;
for ( V_9 = 0 ; V_9 < 130 ; V_9 ++ )
* ( V_60 ++ ) = F_9 ( V_23 , F_48 ( V_9 ) ) ;
break;
case V_25 :
* ( V_60 ++ ) = F_9 ( V_23 , V_78 ) ;
* ( V_60 ++ ) = F_9 ( V_23 , V_79 ) ;
* ( V_60 ++ ) = F_9 ( V_23 , V_80 ) ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
* ( V_60 ++ ) = F_9 ( V_23 , F_49 ( V_9 ) ) ;
F_40 ( V_23 , V_60 , 0 ) ;
V_60 += V_63 ;
for ( V_9 = 0 ; V_9 < V_81 ; V_9 ++ ) {
if ( V_9 < V_23 -> V_24 . V_29 )
F_8 ( V_23 , V_60 , V_9 ) ;
else
memset ( V_60 , 0 , sizeof( T_2 ) * V_62 ) ;
V_60 += V_62 ;
}
break;
default:
return;
}
}
static int F_50 ( struct V_1 * V_43 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
switch ( V_23 -> V_24 . type ) {
case V_69 :
return V_82 * sizeof( T_2 ) ;
case V_25 :
return V_83 * sizeof( T_2 ) ;
default:
return 0 ;
}
}
static void F_51 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
strncpy ( V_85 -> V_86 , V_87 ,
sizeof( V_85 -> V_86 ) - 1 ) ;
strncpy ( V_85 -> V_66 , V_88 ,
sizeof( V_85 -> V_66 ) - 1 ) ;
strncpy ( V_85 -> V_89 , F_52 ( V_5 -> V_90 ) ,
sizeof( V_85 -> V_89 ) - 1 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_92 -> V_93 = 0 ;
V_92 -> V_94 = 1 ;
V_92 -> V_95 = V_5 -> V_95 ? 1 : 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
if ( V_92 -> V_93 || ! V_92 -> V_94 )
return - V_96 ;
if ( V_23 -> V_24 . type == V_69 )
V_5 -> V_95 = V_92 -> V_95 ? ~ 0 : 0 ;
else if ( V_92 -> V_95 )
return - V_96 ;
if ( F_55 ( V_2 ) )
F_56 ( V_5 ) ;
return 0 ;
}
static T_2 F_57 ( struct V_1 * V_43 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
return V_5 -> V_97 ;
}
static void F_58 ( struct V_1 * V_43 , T_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
V_5 -> V_97 = V_3 ;
}
static void F_59 ( struct V_1 * V_43 ,
struct V_98 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
V_56 -> V_99 = V_100 ;
V_56 -> V_101 = V_102 ;
V_56 -> V_103 = 0 ;
V_56 -> V_104 = 0 ;
V_56 -> V_105 = V_5 -> V_106 ;
V_56 -> V_107 = V_5 -> V_108 ;
V_56 -> V_109 = 0 ;
V_56 -> V_110 = 0 ;
}
static int F_60 ( struct V_1 * V_43 ,
struct V_98 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
struct V_55 * V_111 ;
int V_9 , V_112 = 0 ;
T_2 V_113 , V_114 ;
if ( ( V_56 -> V_109 ) || ( V_56 -> V_110 ) )
return - V_96 ;
V_114 = F_61 ( T_2 , V_56 -> V_107 ,
V_115 , V_102 ) ;
V_114 = F_62 ( V_114 , V_116 ) ;
V_113 = F_61 ( T_2 , V_56 -> V_105 ,
V_117 , V_100 ) ;
V_113 = F_62 ( V_113 , V_118 ) ;
if ( ( V_114 == V_5 -> V_108 ) &&
( V_113 == V_5 -> V_106 ) ) {
return 0 ;
}
while ( F_63 ( V_119 , & V_5 -> V_120 ) )
F_64 ( 1000 , 2000 ) ;
if ( ! F_55 ( V_5 -> V_43 ) ) {
for ( V_9 = 0 ; V_9 < V_5 -> V_121 ; V_9 ++ )
V_5 -> V_58 [ V_9 ] -> V_122 = V_114 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_123 ; V_9 ++ )
V_5 -> V_59 [ V_9 ] -> V_122 = V_113 ;
V_5 -> V_108 = V_114 ;
V_5 -> V_106 = V_113 ;
goto V_124;
}
V_9 = F_65 ( int , V_5 -> V_121 , V_5 -> V_123 ) ;
V_111 = F_66 ( V_9 * sizeof( struct V_55 ) ) ;
if ( ! V_111 ) {
V_112 = - V_125 ;
goto V_124;
}
F_67 ( V_5 ) ;
if ( V_114 != V_5 -> V_108 ) {
for ( V_9 = 0 ; V_9 < V_5 -> V_121 ; V_9 ++ ) {
memcpy ( & V_111 [ V_9 ] , V_5 -> V_58 [ V_9 ] ,
sizeof( struct V_55 ) ) ;
V_111 [ V_9 ] . V_122 = V_114 ;
V_112 = F_68 ( & V_111 [ V_9 ] ) ;
if ( V_112 ) {
while ( V_9 ) {
V_9 -- ;
F_69 ( & V_111 [ V_9 ] ) ;
}
goto V_126;
}
}
for ( V_9 = 0 ; V_9 < V_5 -> V_121 ; V_9 ++ ) {
F_69 ( V_5 -> V_58 [ V_9 ] ) ;
memcpy ( V_5 -> V_58 [ V_9 ] , & V_111 [ V_9 ] ,
sizeof( struct V_55 ) ) ;
}
V_5 -> V_108 = V_114 ;
}
if ( V_113 != V_5 -> V_106 ) {
for ( V_9 = 0 ; V_9 < V_5 -> V_123 ; V_9 ++ ) {
memcpy ( & V_111 [ V_9 ] , V_5 -> V_59 [ V_9 ] ,
sizeof( struct V_55 ) ) ;
V_111 [ V_9 ] . V_122 = V_113 ;
V_112 = F_70 ( & V_111 [ V_9 ] ) ;
if ( V_112 ) {
while ( V_9 ) {
V_9 -- ;
F_71 ( & V_111 [ V_9 ] ) ;
}
goto V_126;
}
}
for ( V_9 = 0 ; V_9 < V_5 -> V_123 ; V_9 ++ ) {
F_71 ( V_5 -> V_59 [ V_9 ] ) ;
memcpy ( V_5 -> V_59 [ V_9 ] , & V_111 [ V_9 ] ,
sizeof( struct V_55 ) ) ;
}
V_5 -> V_106 = V_113 ;
}
V_126:
F_72 ( V_5 ) ;
F_73 ( V_111 ) ;
V_124:
F_74 ( V_119 , & V_5 -> V_120 ) ;
return V_112 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_128 -> V_129 = F_76 ( V_5 -> V_130 ) ;
V_128 -> V_131 = V_5 -> V_130 & ~ V_132 ;
V_128 -> V_133 = F_76 ( V_5 -> V_134 ) ;
V_128 -> V_135 = V_5 -> V_134 & ~ V_132 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_136 * V_137 ;
T_5 V_130 , V_134 ;
int V_9 ;
if ( ( V_128 -> V_135 > V_138 ) ||
( V_128 -> V_131 > V_138 ) )
return - V_96 ;
V_130 = V_128 -> V_131 ;
V_134 = V_128 -> V_135 ;
if ( V_128 -> V_129 )
V_130 = V_132 | V_139 ;
if ( V_128 -> V_133 )
V_134 = V_132 | V_140 ;
V_5 -> V_130 = V_130 ;
V_5 -> V_134 = V_134 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_141 ; V_9 ++ ) {
V_137 = V_5 -> V_142 [ V_9 ] ;
V_137 -> V_143 . V_144 = V_130 ;
V_137 -> V_145 . V_144 = V_134 ;
}
return 0 ;
}
static int F_78 ( struct V_4 * V_5 ,
struct V_146 * V_147 )
{
V_147 -> V_3 = 0 ;
switch ( V_147 -> V_148 ) {
case V_149 :
case V_150 :
V_147 -> V_3 |= V_151 | V_152 ;
case V_153 :
if ( V_5 -> V_17 & V_154 )
V_147 -> V_3 |= V_151 | V_152 ;
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
V_147 -> V_3 |= V_165 | V_166 ;
break;
case V_167 :
if ( V_5 -> V_17 & V_168 )
V_147 -> V_3 |= V_151 | V_152 ;
V_147 -> V_3 |= V_165 | V_166 ;
break;
default:
return - V_96 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_146 * V_147 ,
T_2 T_3 * V_169 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_170 = - V_42 ;
switch ( V_147 -> V_147 ) {
case V_171 :
V_147 -> V_3 = V_5 -> V_123 ;
V_170 = 0 ;
break;
case V_172 :
V_170 = F_78 ( V_5 , V_147 ) ;
break;
default:
break;
}
return V_170 ;
}
static int F_80 ( struct V_4 * V_5 ,
struct V_146 * V_173 )
{
T_2 V_17 = V_5 -> V_17 ;
if ( V_173 -> V_3 & ~ ( V_165 | V_166 |
V_151 | V_152 ) )
return - V_96 ;
switch ( V_173 -> V_148 ) {
case V_149 :
case V_150 :
if ( ! ( V_173 -> V_3 & V_165 ) ||
! ( V_173 -> V_3 & V_166 ) ||
! ( V_173 -> V_3 & V_151 ) ||
! ( V_173 -> V_3 & V_152 ) )
return - V_96 ;
break;
case V_153 :
if ( ! ( V_173 -> V_3 & V_165 ) ||
! ( V_173 -> V_3 & V_166 ) )
return - V_96 ;
switch ( V_173 -> V_3 & ( V_151 | V_152 ) ) {
case 0 :
V_17 &= ~ V_154 ;
break;
case ( V_151 | V_152 ) :
V_17 |= V_154 ;
break;
default:
return - V_96 ;
}
break;
case V_167 :
if ( ! ( V_173 -> V_3 & V_165 ) ||
! ( V_173 -> V_3 & V_166 ) )
return - V_96 ;
switch ( V_173 -> V_3 & ( V_151 | V_152 ) ) {
case 0 :
V_17 &= ~ V_168 ;
break;
case ( V_151 | V_152 ) :
V_17 |= V_168 ;
break;
default:
return - V_96 ;
}
break;
case V_157 :
case V_159 :
case V_161 :
case V_155 :
case V_158 :
case V_160 :
case V_162 :
case V_156 :
if ( ! ( V_173 -> V_3 & V_165 ) ||
! ( V_173 -> V_3 & V_166 ) ||
( V_173 -> V_3 & V_151 ) ||
( V_173 -> V_3 & V_152 ) )
return - V_96 ;
break;
default:
return - V_96 ;
}
if ( V_17 != V_5 -> V_17 ) {
struct V_39 * V_23 = & V_5 -> V_23 ;
T_2 V_174 ;
if ( ( V_17 & V_175 ) &&
! ( V_5 -> V_17 & V_175 ) )
F_81 ( V_5 , V_176 , V_5 -> V_43 ,
L_6 ) ;
V_5 -> V_17 = V_17 ;
V_174 = V_177 |
V_178 |
V_179 |
V_180 ;
if ( V_17 & V_154 )
V_174 |= V_181 ;
if ( V_17 & V_168 )
V_174 |= V_182 ;
F_82 ( V_23 , F_41 ( 0 ) , V_174 ) ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_170 = - V_42 ;
switch ( V_147 -> V_147 ) {
case V_183 :
V_170 = F_80 ( V_5 , V_147 ) ;
break;
default:
break;
}
return V_170 ;
}
static int F_84 ( struct V_4 * V_5 , T_4 * V_3 )
{
struct V_39 * V_23 = & V_5 -> V_23 ;
struct V_184 * V_52 = & V_23 -> V_52 ;
T_2 V_185 , V_186 [ 6 ] ;
unsigned long V_187 ;
int V_112 ;
if ( V_23 -> V_24 . type != V_25 )
return 0 ;
for ( V_185 = ( 1 << V_188 ) ;
V_185 < ( 1 << ( 2 * V_189 ) ) ;
V_185 += V_185 ) {
F_85 ( V_186 , V_185 ) ;
F_86 ( V_5 ) ;
V_52 -> V_190 = V_191 ;
V_112 = V_52 -> V_192 . V_193 ( V_23 , V_52 , V_186 ) ;
F_87 ( V_5 ) ;
V_187 = V_194 + V_195 ;
do {
if ( V_112 < 0 )
goto V_196;
F_64 ( 500 , 1000 ) ;
F_86 ( V_5 ) ;
V_52 -> V_192 . V_197 ( V_23 , V_52 ) ;
F_87 ( V_5 ) ;
V_112 = V_52 -> V_190 ;
if ( ! V_112 )
break;
} while ( F_88 ( V_187 ) );
if ( V_112 )
goto V_196;
}
V_196:
* V_3 = V_112 < 0 ? ( V_185 ) : ( V_112 > 0 ) ;
return V_112 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_198 * V_199 , T_4 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
memset ( V_3 , 0 , sizeof( * V_3 ) * V_33 ) ;
if ( F_90 ( V_23 ) ) {
F_91 ( V_5 , V_176 , V_2 ,
L_7 ) ;
V_199 -> V_17 |= V_200 ;
return;
}
if ( F_84 ( V_5 , & V_3 [ V_201 ] ) )
V_199 -> V_17 |= V_200 ;
}
static T_2 F_92 ( struct V_1 * V_43 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
T_2 V_202 = 0 ;
if ( V_5 -> V_17 & V_18 )
V_202 |= 1 << V_203 ;
return V_202 ;
}
static int F_93 ( struct V_1 * V_43 , T_2 V_202 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
if ( V_202 >= ( 1 << V_37 ) )
return - V_96 ;
if ( V_202 & ( 1 << V_203 ) )
V_5 -> V_17 |= V_18 ;
else
V_5 -> V_17 &= ~ V_18 ;
return 0 ;
}
static T_2 F_94 ( struct V_1 T_3 * V_43 )
{
return V_204 * V_205 ;
}
static int F_95 ( struct V_1 * V_43 , T_2 * V_206 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
int V_9 ;
if ( ! V_206 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_204 ; V_9 ++ , V_206 += 4 ) {
T_2 V_207 = V_5 -> V_207 [ V_9 ] ;
V_206 [ 0 ] = ( V_207 << 24 ) >> 24 ;
V_206 [ 1 ] = ( V_207 << 16 ) >> 24 ;
V_206 [ 2 ] = ( V_207 << 8 ) >> 24 ;
V_206 [ 3 ] = ( V_207 ) >> 24 ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_43 , const T_2 * V_206 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
int V_9 ;
T_5 V_208 ;
if ( ! V_206 )
return 0 ;
V_208 = V_5 -> V_209 [ V_210 ] . V_211 ;
for ( V_9 = F_94 ( V_43 ) ; V_9 -- ; ) {
if ( V_206 [ V_9 ] < V_208 )
continue;
return - V_96 ;
}
for ( V_9 = 0 ; V_9 < V_204 ; V_9 ++ , V_206 += 4 ) {
T_2 V_207 = V_206 [ 0 ] |
( V_206 [ 1 ] << 8 ) |
( V_206 [ 2 ] << 16 ) |
( V_206 [ 3 ] << 24 ) ;
if ( V_5 -> V_207 [ V_9 ] == V_207 )
continue;
V_5 -> V_207 [ V_9 ] = V_207 ;
F_82 ( V_23 , F_43 ( 0 , V_9 ) , V_207 ) ;
}
return 0 ;
}
static T_2 F_97 ( struct V_1 T_3 * V_43 )
{
return V_212 * V_213 ;
}
static int F_98 ( struct V_1 * V_43 , T_2 * V_206 , T_1 * V_214 ,
T_1 * V_215 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
int V_9 , V_112 ;
if ( V_215 )
* V_215 = V_216 ;
V_112 = F_95 ( V_43 , V_206 ) ;
if ( V_112 || ! V_214 )
return V_112 ;
for ( V_9 = 0 ; V_9 < V_212 ; V_9 ++ , V_214 += 4 )
* ( V_217 * ) V_214 = F_99 ( V_5 -> V_218 [ V_9 ] ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_43 , const T_2 * V_206 ,
const T_1 * V_214 , const T_1 V_215 )
{
struct V_4 * V_5 = F_2 ( V_43 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
int V_9 , V_112 ;
if ( V_215 != V_219 && V_215 != V_216 )
return - V_42 ;
V_112 = F_96 ( V_43 , V_206 ) ;
if ( V_112 || ! V_214 )
return V_112 ;
for ( V_9 = 0 ; V_9 < V_212 ; V_9 ++ , V_214 += 4 ) {
T_2 V_218 = F_101 ( * ( V_217 * ) V_214 ) ;
if ( V_5 -> V_218 [ V_9 ] == V_218 )
continue;
V_5 -> V_218 [ V_9 ] = V_218 ;
F_82 ( V_23 , F_42 ( 0 , V_9 ) , V_218 ) ;
}
return 0 ;
}
static unsigned int F_102 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_220 = V_5 -> V_23 . V_24 . V_29 ;
T_1 V_221 = F_103 ( V_2 ) ;
if ( V_221 > 1 )
V_220 = 1 << ( F_104 ( V_220 / V_221 ) - 1 ) ;
return V_220 ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_39 * V_23 = & V_5 -> V_23 ;
V_223 -> V_220 = F_102 ( V_2 ) ;
V_223 -> V_224 = F_106 ( V_23 ) ;
V_223 -> V_225 = V_223 -> V_224 ;
V_223 -> V_226 = V_5 -> V_209 [ V_210 ] . V_211 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_122 = V_223 -> V_226 ;
struct V_39 * V_23 = & V_5 -> V_23 ;
if ( ! V_122 || V_223 -> V_227 || V_223 -> V_228 )
return - V_96 ;
if ( V_223 -> V_225 != F_106 ( V_23 ) )
return - V_96 ;
if ( V_122 > F_102 ( V_2 ) )
return - V_96 ;
V_5 -> V_209 [ V_210 ] . V_229 = V_122 ;
return F_108 ( V_2 , F_103 ( V_2 ) ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_230 * V_85 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_85 -> V_231 =
V_232 |
V_233 |
V_234 |
V_235 |
V_236 |
V_237 ;
if ( V_5 -> V_238 )
V_85 -> V_239 = F_110 ( V_5 -> V_238 ) ;
else
V_85 -> V_239 = - 1 ;
V_85 -> V_240 = ( 1 << V_241 ) |
( 1 << V_242 ) ;
V_85 -> V_243 = ( 1 << V_244 ) |
( 1 << V_245 ) ;
return 0 ;
}
void F_111 ( struct V_1 * V_2 )
{
V_2 -> V_246 = & V_247 ;
}
