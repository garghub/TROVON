int F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < sizeof( V_4 ) ; V_2 ++ )
if ( V_1 [ V_2 ] == V_4 [ V_2 ] )
V_3 ++ ;
return V_3 ;
}
static bool
F_2 ( T_1 * V_1 )
{
int V_2 ;
T_1 V_5 = 0 ;
struct V_6 * V_6 = (struct V_6 * ) V_1 ;
if ( V_1 [ 0 ] == 0x00 ) {
int V_3 = F_1 ( V_1 ) ;
if ( V_3 == 8 ) ;
else if ( V_3 >= 6 ) {
F_3 ( L_1 ) ;
memcpy ( V_1 , V_4 , sizeof( V_4 ) ) ;
} else {
goto V_7;
}
}
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ )
V_5 += V_1 [ V_2 ] ;
if ( V_5 ) {
F_4 ( L_2 , V_5 ) ;
if ( V_1 [ 0 ] != 0x02 )
goto V_7;
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_6 -> V_9 != 1 ) {
F_4 ( L_3 , V_6 -> V_9 ) ;
goto V_7;
}
if ( V_6 -> V_10 > 4 )
F_3 ( L_4 ) ;
break;
default:
break;
}
return 1 ;
V_7:
if ( V_1 ) {
F_5 ( V_11 L_5 ) ;
F_6 ( V_11 , L_6 , V_12 , 16 , 1 ,
V_1 , V_8 , false ) ;
}
return 0 ;
}
bool F_7 ( struct V_6 * V_6 )
{
int V_2 ;
T_1 * V_13 = ( T_1 * ) V_6 ;
if ( ! V_6 )
return false ;
for ( V_2 = 0 ; V_2 <= V_6 -> V_14 ; V_2 ++ )
if ( ! F_2 ( V_13 + V_2 * V_8 ) )
return false ;
return true ;
}
static int
F_8 ( struct V_15 * V_16 , unsigned char * V_17 ,
int V_18 , int V_19 )
{
unsigned char V_20 = V_18 * V_8 ;
int V_21 , V_22 = 5 ;
do {
struct V_23 V_24 [] = {
{
. V_25 = V_26 ,
. V_27 = 0 ,
. V_19 = 1 ,
. V_17 = & V_20 ,
} , {
. V_25 = V_26 ,
. V_27 = V_28 ,
. V_19 = V_19 ,
. V_17 = V_17 ,
}
} ;
V_21 = F_9 ( V_16 , V_24 , 2 ) ;
} while ( V_21 != 2 && -- V_22 );
return V_21 == 2 ? 0 : - 1 ;
}
static bool F_10 ( T_1 * V_29 , int V_30 )
{
int V_2 ;
T_2 * V_1 = ( T_2 * ) V_29 ;
for ( V_2 = 0 ; V_2 < V_30 / 4 ; V_2 ++ )
if ( * ( V_1 + V_2 ) != 0 )
return false ;
return true ;
}
static T_1 *
F_11 ( struct V_31 * V_32 , struct V_15 * V_16 )
{
int V_2 , V_33 = 0 , V_34 = 0 ;
T_1 * V_18 , * V_35 ;
if ( ( V_18 = F_12 ( V_8 , V_36 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_16 , V_18 , 0 , V_8 ) )
goto V_37;
if ( F_2 ( V_18 ) )
break;
if ( V_2 == 0 && F_10 ( V_18 , V_8 ) ) {
V_32 -> V_38 ++ ;
goto V_39;
}
}
if ( V_2 == 4 )
goto V_39;
if ( V_18 [ 0x7e ] == 0 )
return V_18 ;
V_35 = F_13 ( V_18 , ( V_18 [ 0x7e ] + 1 ) * V_8 , V_36 ) ;
if ( ! V_35 )
goto V_37;
V_18 = V_35 ;
for ( V_33 = 1 ; V_33 <= V_18 [ 0x7e ] ; V_33 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_16 ,
V_18 + ( V_34 + 1 ) * V_8 ,
V_33 , V_8 ) )
goto V_37;
if ( F_2 ( V_18 + ( V_34 + 1 ) * V_8 ) ) {
V_34 ++ ;
break;
}
}
if ( V_2 == 4 )
F_14 ( V_32 -> V_40 -> V_40 ,
L_7 ,
F_15 ( V_32 ) , V_33 ) ;
}
if ( V_34 != V_18 [ 0x7e ] ) {
V_18 [ V_8 - 1 ] += V_18 [ 0x7e ] - V_34 ;
V_18 [ 0x7e ] = V_34 ;
V_35 = F_13 ( V_18 , ( V_34 + 1 ) * V_8 , V_36 ) ;
if ( ! V_35 )
goto V_37;
V_18 = V_35 ;
}
return V_18 ;
V_39:
F_14 ( V_32 -> V_40 -> V_40 , L_8 ,
F_15 ( V_32 ) , V_33 ) ;
V_37:
F_16 ( V_18 ) ;
return NULL ;
}
static bool
F_17 ( struct V_15 * V_16 )
{
unsigned char V_37 ;
return ( F_8 ( V_16 , & V_37 , 0 , 1 ) == 0 ) ;
}
struct V_6 * F_18 ( struct V_31 * V_32 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = NULL ;
if ( F_17 ( V_16 ) )
V_6 = (struct V_6 * ) F_11 ( V_32 , V_16 ) ;
V_32 -> V_41 . V_1 = ( char * ) V_6 ;
return V_6 ;
}
static bool F_19 ( struct V_6 * V_6 , char * V_42 )
{
char F_19 [ 3 ] ;
F_19 [ 0 ] = ( ( V_6 -> V_43 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_19 [ 1 ] = ( ( ( V_6 -> V_43 [ 0 ] & 0x3 ) << 3 ) |
( ( V_6 -> V_43 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_19 [ 2 ] = ( V_6 -> V_43 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_19 , V_42 , 3 ) ;
}
static T_2 F_20 ( struct V_6 * V_6 )
{
struct V_44 * V_45 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_21 ( V_46 ) ; V_2 ++ ) {
V_45 = & V_46 [ V_2 ] ;
if ( F_19 ( V_6 , V_45 -> V_42 ) &&
( F_22 ( V_6 ) == V_45 -> V_47 ) )
return V_45 -> V_48 ;
}
return 0 ;
}
static void F_23 ( struct V_31 * V_32 ,
T_2 V_48 )
{
struct V_49 * V_50 , * V_51 , * V_52 ;
int V_53 = 0 ;
if ( F_24 ( & V_32 -> V_54 ) )
return;
if ( V_48 & V_55 )
V_53 = 60 ;
if ( V_48 & V_56 )
V_53 = 75 ;
V_52 = F_25 ( & V_32 -> V_54 ,
struct V_49 , V_57 ) ;
F_26 (cur_mode, t, &connector->probed_modes, head) {
V_51 -> type &= ~ V_58 ;
if ( V_51 == V_52 )
continue;
if ( F_27 ( V_51 ) > F_27 ( V_52 ) )
V_52 = V_51 ;
if ( ( F_27 ( V_51 ) == F_27 ( V_52 ) ) &&
F_28 ( V_51 , V_53 ) <
F_28 ( V_52 , V_53 ) ) {
V_52 = V_51 ;
}
}
V_52 -> type |= V_58 ;
}
struct V_49 * F_29 ( struct V_59 * V_40 ,
int V_60 , int V_61 , int V_62 )
{
struct V_49 * V_63 = NULL ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
const struct V_49 * V_65 = & V_66 [ V_2 ] ;
if ( V_60 == V_65 -> V_67 &&
V_61 == V_65 -> V_68 &&
V_62 == F_30 ( V_65 ) ) {
V_63 = F_31 ( V_40 , V_65 ) ;
break;
}
}
return V_63 ;
}
static void
F_32 ( T_1 * V_69 , T_3 * V_70 , void * V_71 )
{
int V_2 , V_72 = 0 ;
T_1 V_73 = V_69 [ 0x01 ] , V_74 = V_69 [ 0x02 ] ;
T_1 * V_75 = V_69 + V_74 ;
switch ( V_73 ) {
case 0 :
return;
case 1 :
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
if ( V_75 [ 18 * V_2 ] || V_75 [ 18 * V_2 + 1 ] )
V_72 ++ ;
break;
default:
V_72 = F_33 ( V_69 [ 0x03 ] & 0x0f , 6 ) ;
break;
}
for ( V_2 = 0 ; V_2 < V_72 ; V_2 ++ )
V_70 ( (struct V_76 * ) ( V_75 + 18 * V_2 ) , V_71 ) ;
}
static void
F_34 ( T_1 * V_69 , T_3 * V_70 , void * V_71 )
{
unsigned int V_2 , V_72 = F_33 ( ( int ) V_69 [ 0x02 ] , 6 ) ;
T_1 * V_75 = V_69 + 5 ;
if ( V_69 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_72 ; V_2 ++ )
V_70 ( (struct V_76 * ) ( V_75 + 18 * V_2 ) , V_71 ) ;
}
static void
F_35 ( T_1 * V_1 , T_3 * V_70 , void * V_71 )
{
int V_2 ;
struct V_6 * V_6 = (struct V_6 * ) V_1 ;
if ( V_6 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_77 ; V_2 ++ )
V_70 ( & ( V_6 -> V_78 [ V_2 ] ) , V_71 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_69 = V_1 + ( V_2 * V_8 ) ;
switch ( * V_69 ) {
case V_79 :
F_32 ( V_69 , V_70 , V_71 ) ;
break;
case V_80 :
F_34 ( V_69 , V_70 , V_71 ) ;
break;
default:
break;
}
}
}
static void
F_36 ( struct V_76 * V_50 , void * V_81 )
{
T_1 * V_82 = ( T_1 * ) V_50 ;
if ( V_82 [ 3 ] == V_83 )
if ( V_82 [ 15 ] & 0x10 )
* ( bool * ) V_81 = true ;
}
static bool
F_37 ( struct V_6 * V_6 )
{
if ( V_6 -> V_10 >= 4 ) {
bool V_21 ;
F_35 ( ( T_1 * ) V_6 , F_36 , & V_21 ) ;
return V_21 ;
}
return ( ( V_6 -> V_84 & V_85 ) != 0 ) ;
}
static void
F_38 ( struct V_76 * V_50 , void * V_81 )
{
T_1 * V_82 = ( T_1 * ) V_50 ;
if ( V_82 [ 3 ] == V_83 && V_82 [ 10 ] == 0x02 )
* ( T_1 * * ) V_81 = V_82 ;
}
static int
F_39 ( struct V_6 * V_6 )
{
T_1 * V_82 = NULL ;
F_35 ( ( T_1 * ) V_6 , F_38 , & V_82 ) ;
return V_82 ? ( V_82 [ 12 ] * 2 ) : 0 ;
}
static int
F_40 ( struct V_6 * V_6 )
{
T_1 * V_82 = NULL ;
F_35 ( ( T_1 * ) V_6 , F_38 , & V_82 ) ;
return V_82 ? V_82 [ 13 ] : 0 ;
}
static int
F_41 ( struct V_6 * V_6 )
{
T_1 * V_82 = NULL ;
F_35 ( ( T_1 * ) V_6 , F_38 , & V_82 ) ;
return V_82 ? ( V_82 [ 15 ] << 8 ) + V_82 [ 14 ] : 0 ;
}
static int
F_42 ( struct V_6 * V_6 )
{
T_1 * V_82 = NULL ;
F_35 ( ( T_1 * ) V_6 , F_38 , & V_82 ) ;
return V_82 ? V_82 [ 16 ] : 0 ;
}
static int
F_43 ( struct V_6 * V_6 )
{
T_1 * V_82 = NULL ;
F_35 ( ( T_1 * ) V_6 , F_38 , & V_82 ) ;
return V_82 ? V_82 [ 17 ] : 0 ;
}
static int F_44 ( struct V_6 * V_6 )
{
if ( V_6 -> V_10 >= 2 ) {
if ( V_6 -> V_10 >= 4 && ( V_6 -> V_86 & V_87 ) )
return V_88 ;
if ( F_39 ( V_6 ) )
return V_89 ;
return V_90 ;
}
return V_91 ;
}
static int
F_45 ( T_1 V_92 , T_1 V_93 )
{
return ( V_92 == 0x00 && V_93 == 0x00 ) ||
( V_92 == 0x01 && V_93 == 0x01 ) ||
( V_92 == 0x20 && V_93 == 0x20 ) ;
}
static struct V_49 *
F_46 ( struct V_31 * V_32 , struct V_6 * V_6 ,
struct V_94 * V_50 , int V_10 )
{
struct V_59 * V_40 = V_32 -> V_40 ;
struct V_49 * V_95 , * V_63 = NULL ;
int V_60 , V_61 ;
int V_96 ;
unsigned V_97 = ( V_50 -> V_98 & V_99 )
>> V_100 ;
unsigned V_101 = ( V_50 -> V_98 & V_102 )
>> V_103 ;
int V_104 = F_44 ( V_6 ) ;
if ( F_45 ( V_50 -> V_60 , V_50 -> V_98 ) )
return NULL ;
V_60 = V_50 -> V_60 * 8 + 248 ;
V_96 = V_101 + 60 ;
if ( V_97 == 0 ) {
if ( V_10 < 3 )
V_61 = V_60 ;
else
V_61 = ( V_60 * 10 ) / 16 ;
} else if ( V_97 == 1 )
V_61 = ( V_60 * 3 ) / 4 ;
else if ( V_97 == 2 )
V_61 = ( V_60 * 4 ) / 5 ;
else
V_61 = ( V_60 * 9 ) / 16 ;
if ( V_96 == 60 &&
( ( V_60 == 1360 && V_61 == 765 ) ||
( V_60 == 1368 && V_61 == 769 ) ) ) {
V_60 = 1366 ;
V_61 = 768 ;
}
F_47 (m, &connector->probed_modes, head)
if ( V_95 -> V_67 == V_60 && V_95 -> V_68 == V_61 &&
F_30 ( V_95 ) == V_96 )
return NULL ;
if ( V_60 == 1366 && V_61 == 768 && V_96 == 60 ) {
V_63 = F_48 ( V_40 , 1366 , 768 , V_96 , 0 , 0 ,
false ) ;
V_63 -> V_67 = 1366 ;
V_63 -> V_105 = V_63 -> V_105 - 1 ;
V_63 -> V_106 = V_63 -> V_106 - 1 ;
return V_63 ;
}
V_63 = F_29 ( V_40 , V_60 , V_61 , V_96 ) ;
if ( V_63 )
return V_63 ;
switch ( V_104 ) {
case V_91 :
break;
case V_90 :
V_63 = F_49 ( V_40 , V_60 , V_61 , V_96 , 0 , 0 ) ;
break;
case V_89 :
V_63 = F_49 ( V_40 , V_60 , V_61 , V_96 , 0 , 0 ) ;
if ( F_50 ( V_63 ) > F_39 ( V_6 ) ) {
F_16 ( V_63 ) ;
V_63 = F_51 ( V_40 , V_60 , V_61 ,
V_96 , 0 , 0 ,
F_41 ( V_6 ) ,
F_40 ( V_6 ) ,
F_42 ( V_6 ) ,
F_43 ( V_6 ) ) ;
}
break;
case V_88 :
V_63 = F_48 ( V_40 , V_60 , V_61 , V_96 , 0 , 0 ,
false ) ;
break;
}
return V_63 ;
}
static void
F_52 ( struct V_49 * V_63 ,
struct V_107 * V_108 )
{
int V_2 ;
static const struct {
int V_109 , V_110 ;
} V_111 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_108 -> V_112 & V_113 ) )
return;
for ( V_2 = 0 ; V_2 < F_21 ( V_111 ) ; V_2 ++ ) {
if ( ( V_63 -> V_67 == V_111 [ V_2 ] . V_109 ) &&
( V_63 -> V_68 == V_111 [ V_2 ] . V_110 / 2 ) ) {
V_63 -> V_68 *= 2 ;
V_63 -> V_114 *= 2 ;
V_63 -> V_115 *= 2 ;
V_63 -> V_116 *= 2 ;
V_63 -> V_116 |= 1 ;
}
}
V_63 -> V_27 |= V_117 ;
}
static struct V_49 * F_53 ( struct V_59 * V_40 ,
struct V_6 * V_6 ,
struct V_76 * V_118 ,
T_2 V_48 )
{
struct V_49 * V_63 ;
struct V_107 * V_108 = & V_118 -> V_81 . V_119 ;
unsigned V_120 = ( V_108 -> V_121 & 0xf0 ) << 4 | V_108 -> V_122 ;
unsigned V_123 = ( V_108 -> V_124 & 0xf0 ) << 4 | V_108 -> V_125 ;
unsigned V_126 = ( V_108 -> V_121 & 0xf ) << 8 | V_108 -> V_127 ;
unsigned V_128 = ( V_108 -> V_124 & 0xf ) << 8 | V_108 -> V_129 ;
unsigned V_130 = ( V_108 -> V_131 & 0xc0 ) << 2 | V_108 -> V_132 ;
unsigned V_133 = ( V_108 -> V_131 & 0x30 ) << 4 | V_108 -> V_134 ;
unsigned V_135 = ( V_108 -> V_131 & 0xc ) >> 2 | V_108 -> V_136 >> 4 ;
unsigned V_137 = ( V_108 -> V_131 & 0x3 ) << 4 | ( V_108 -> V_136 & 0xf ) ;
if ( V_120 < 64 || V_123 < 64 )
return NULL ;
if ( V_108 -> V_112 & V_138 ) {
F_5 ( V_139 L_9 ) ;
return NULL ;
}
if ( ! ( V_108 -> V_112 & V_140 ) ) {
F_5 ( V_139 L_10 ) ;
}
if ( ! V_133 || ! V_137 ) {
F_54 ( L_11
L_12 ) ;
return NULL ;
}
V_63 = F_55 ( V_40 ) ;
if ( ! V_63 )
return NULL ;
V_63 -> type = V_141 ;
if ( V_48 & V_142 )
V_118 -> V_143 = F_56 ( 1088 ) ;
V_63 -> clock = F_57 ( V_118 -> V_143 ) * 10 ;
V_63 -> V_67 = V_120 ;
V_63 -> V_105 = V_63 -> V_67 + V_130 ;
V_63 -> V_106 = V_63 -> V_105 + V_133 ;
V_63 -> V_144 = V_63 -> V_67 + V_126 ;
V_63 -> V_68 = V_123 ;
V_63 -> V_114 = V_63 -> V_68 + V_135 ;
V_63 -> V_115 = V_63 -> V_114 + V_137 ;
V_63 -> V_116 = V_63 -> V_68 + V_128 ;
if ( V_63 -> V_106 > V_63 -> V_144 )
V_63 -> V_144 = V_63 -> V_106 + 1 ;
if ( V_63 -> V_115 > V_63 -> V_116 )
V_63 -> V_116 = V_63 -> V_115 + 1 ;
F_52 ( V_63 , V_108 ) ;
F_58 ( V_63 ) ;
if ( V_48 & V_145 ) {
V_108 -> V_112 |= V_146 | V_147 ;
}
V_63 -> V_27 |= ( V_108 -> V_112 & V_146 ) ?
V_148 : V_149 ;
V_63 -> V_27 |= ( V_108 -> V_112 & V_147 ) ?
V_150 : V_151 ;
V_63 -> V_152 = V_108 -> V_153 | ( V_108 -> V_154 & 0xf0 ) << 4 ;
V_63 -> V_155 = V_108 -> V_156 | ( V_108 -> V_154 & 0xf ) << 8 ;
if ( V_48 & V_157 ) {
V_63 -> V_152 *= 10 ;
V_63 -> V_155 *= 10 ;
}
if ( V_48 & V_158 ) {
V_63 -> V_152 = V_6 -> V_159 * 10 ;
V_63 -> V_155 = V_6 -> V_160 * 10 ;
}
return V_63 ;
}
static bool
F_59 ( const struct V_49 * V_63 )
{
return ( V_63 -> V_144 - V_63 -> V_67 == 160 ) &&
( V_63 -> V_106 - V_63 -> V_67 == 80 ) &&
( V_63 -> V_106 - V_63 -> V_105 == 32 ) &&
( V_63 -> V_114 - V_63 -> V_68 == 3 ) ;
}
static bool
F_60 ( const struct V_49 * V_63 ,
struct V_6 * V_6 , T_1 * V_50 )
{
int V_161 , V_162 , V_163 ;
V_162 = V_50 [ 7 ] ;
if ( V_6 -> V_10 >= 4 )
V_162 += ( ( V_50 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_163 = V_50 [ 8 ] ;
if ( V_6 -> V_10 >= 4 )
V_163 += ( ( V_50 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_161 = F_50 ( V_63 ) ;
return ( V_161 <= V_163 && V_161 >= V_162 ) ;
}
static bool
F_61 ( const struct V_49 * V_63 ,
struct V_6 * V_6 , T_1 * V_50 )
{
int V_164 , V_165 , V_166 ;
V_165 = V_50 [ 5 ] ;
if ( V_6 -> V_10 >= 4 )
V_165 += ( ( V_50 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_166 = V_50 [ 6 ] ;
if ( V_6 -> V_10 >= 4 )
V_166 += ( ( V_50 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_164 = F_30 ( V_63 ) ;
return ( V_164 <= V_166 && V_164 >= V_165 ) ;
}
static T_2
F_62 ( struct V_6 * V_6 , T_1 * V_50 )
{
if ( V_50 [ 9 ] == 0 || V_50 [ 9 ] == 255 )
return 0 ;
if ( V_6 -> V_10 >= 4 && V_50 [ 10 ] == 0x04 )
return ( V_50 [ 9 ] * 10000 ) - ( ( V_50 [ 12 ] >> 2 ) * 250 ) ;
return V_50 [ 9 ] * 10000 + 5001 ;
}
static bool
F_63 ( const struct V_49 * V_63 , struct V_6 * V_6 ,
struct V_76 * V_118 )
{
T_2 V_167 ;
T_1 * V_50 = ( T_1 * ) V_118 ;
if ( ! F_60 ( V_63 , V_6 , V_50 ) )
return false ;
if ( ! F_61 ( V_63 , V_6 , V_50 ) )
return false ;
if ( ( V_167 = F_62 ( V_6 , V_50 ) ) )
if ( V_63 -> clock > V_167 )
return false ;
if ( V_6 -> V_10 >= 4 && V_50 [ 10 ] == 0x04 )
if ( V_50 [ 13 ] && V_63 -> V_67 > 8 * ( V_50 [ 13 ] + ( 256 * ( V_50 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_59 ( V_63 ) && ! F_37 ( V_6 ) )
return false ;
return true ;
}
static int
F_64 ( struct V_31 * V_32 , struct V_6 * V_6 ,
struct V_76 * V_118 )
{
int V_2 , V_168 = 0 ;
struct V_49 * V_169 ;
struct V_59 * V_40 = V_32 -> V_40 ;
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
if ( F_63 ( V_66 + V_2 , V_6 , V_118 ) ) {
V_169 = F_31 ( V_40 , & V_66 [ V_2 ] ) ;
if ( V_169 ) {
F_65 ( V_32 , V_169 ) ;
V_168 ++ ;
}
}
}
return V_168 ;
}
static void
F_66 ( struct V_76 * V_118 , void * V_170 )
{
struct V_171 * V_71 = V_170 ;
struct V_172 * V_81 = & V_118 -> V_81 . V_173 ;
int V_174 = ( V_71 -> V_6 -> V_86 & V_87 ) ;
if ( V_174 && V_81 -> type == V_83 )
V_71 -> V_168 += F_64 ( V_71 -> V_32 ,
V_71 -> V_6 ,
V_118 ) ;
}
static int
F_67 ( struct V_31 * V_32 , struct V_6 * V_6 )
{
struct V_171 V_71 = {
V_32 , V_6 , 0 , 0 , 0
} ;
if ( F_68 ( V_6 , 1 , 0 ) )
F_35 ( ( T_1 * ) V_6 , F_66 ,
& V_71 ) ;
return V_71 . V_168 ;
}
static int
F_69 ( struct V_31 * V_32 , struct V_76 * V_118 )
{
int V_2 , V_33 , V_95 , V_168 = 0 ;
struct V_49 * V_63 ;
T_1 * V_175 = ( ( T_1 * ) V_118 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_33 = 7 ; V_33 > 0 ; V_33 -- ) {
V_95 = ( V_2 * 8 ) + ( 7 - V_33 ) ;
if ( V_95 >= F_21 ( V_176 ) )
break;
if ( V_175 [ V_2 ] & ( 1 << V_33 ) ) {
V_63 = F_29 ( V_32 -> V_40 ,
V_176 [ V_95 ] . V_109 ,
V_176 [ V_95 ] . V_110 ,
V_176 [ V_95 ] . V_82
) ;
if ( V_63 ) {
F_65 ( V_32 , V_63 ) ;
V_168 ++ ;
}
}
}
}
return V_168 ;
}
static void
F_70 ( struct V_76 * V_118 , void * V_170 )
{
struct V_171 * V_71 = V_170 ;
struct V_172 * V_81 = & V_118 -> V_81 . V_173 ;
if ( V_81 -> type == V_177 )
V_71 -> V_168 += F_69 ( V_71 -> V_32 , V_118 ) ;
}
static int
F_71 ( struct V_31 * V_32 , struct V_6 * V_6 )
{
struct V_59 * V_40 = V_32 -> V_40 ;
unsigned long V_178 = V_6 -> V_179 . V_180 |
( V_6 -> V_179 . V_181 << 8 ) |
( ( V_6 -> V_179 . V_182 & 0x80 ) << 9 ) ;
int V_2 , V_168 = 0 ;
struct V_171 V_71 = {
V_32 , V_6 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_183 ; V_2 ++ ) {
if ( V_178 & ( 1 << V_2 ) ) {
struct V_49 * V_169 ;
V_169 = F_31 ( V_40 , & V_184 [ V_2 ] ) ;
if ( V_169 ) {
F_65 ( V_32 , V_169 ) ;
V_168 ++ ;
}
}
}
if ( F_68 ( V_6 , 1 , 0 ) )
F_35 ( ( T_1 * ) V_6 ,
F_70 , & V_71 ) ;
return V_168 + V_71 . V_168 ;
}
static void
F_72 ( struct V_76 * V_118 , void * V_170 )
{
struct V_171 * V_71 = V_170 ;
struct V_172 * V_81 = & V_118 -> V_81 . V_173 ;
struct V_31 * V_32 = V_71 -> V_32 ;
struct V_6 * V_6 = V_71 -> V_6 ;
if ( V_81 -> type == V_185 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_94 * V_186 ;
struct V_49 * V_169 ;
V_186 = & V_81 -> V_81 . V_187 [ V_2 ] ;
V_169 = F_46 ( V_32 , V_6 , V_186 ,
V_6 -> V_10 ) ;
if ( V_169 ) {
F_65 ( V_32 , V_169 ) ;
V_71 -> V_168 ++ ;
}
}
}
}
static int
F_73 ( struct V_31 * V_32 , struct V_6 * V_6 )
{
int V_2 , V_168 = 0 ;
struct V_171 V_71 = {
V_32 , V_6 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_188 ; V_2 ++ ) {
struct V_49 * V_169 ;
V_169 = F_46 ( V_32 , V_6 ,
& V_6 -> V_189 [ V_2 ] ,
V_6 -> V_10 ) ;
if ( V_169 ) {
F_65 ( V_32 , V_169 ) ;
V_168 ++ ;
}
}
if ( F_68 ( V_6 , 1 , 0 ) )
F_35 ( ( T_1 * ) V_6 , F_72 ,
& V_71 ) ;
return V_168 + V_71 . V_168 ;
}
static int F_74 ( struct V_31 * V_32 ,
struct V_76 * V_118 )
{
int V_2 , V_33 , V_168 = 0 ;
struct V_49 * V_169 ;
struct V_59 * V_40 = V_32 -> V_40 ;
struct V_190 * V_191 ;
const int V_192 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_193 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_194 ( V_195 ) , V_196 ;
V_191 = & ( V_118 -> V_81 . V_173 . V_81 . V_191 [ V_2 ] ) ;
if ( ! memcmp ( V_191 -> V_197 , V_193 , 3 ) )
continue;
V_196 = ( V_191 -> V_197 [ 0 ] + ( ( V_191 -> V_197 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_191 -> V_197 [ 1 ] & 0x0c ) {
case 0x00 :
V_195 = V_196 * 4 / 3 ;
break;
case 0x04 :
V_195 = V_196 * 16 / 9 ;
break;
case 0x08 :
V_195 = V_196 * 16 / 10 ;
break;
case 0x0c :
V_195 = V_196 * 15 / 9 ;
break;
}
for ( V_33 = 1 ; V_33 < 5 ; V_33 ++ ) {
if ( V_191 -> V_197 [ 2 ] & ( 1 << V_33 ) ) {
V_169 = F_48 ( V_40 , V_195 , V_196 ,
V_192 [ V_33 ] , V_33 == 0 ,
false , false ) ;
if ( V_169 ) {
F_65 ( V_32 , V_169 ) ;
V_168 ++ ;
}
}
}
}
return V_168 ;
}
static void
F_75 ( struct V_76 * V_118 , void * V_170 )
{
struct V_171 * V_71 = V_170 ;
struct V_172 * V_81 = & V_118 -> V_81 . V_173 ;
if ( V_81 -> type == V_198 )
V_71 -> V_168 += F_74 ( V_71 -> V_32 , V_118 ) ;
}
static int
F_76 ( struct V_31 * V_32 , struct V_6 * V_6 )
{
struct V_171 V_71 = {
V_32 , V_6 , 0 , 0 , 0
} ;
if ( F_68 ( V_6 , 1 , 2 ) )
F_35 ( ( T_1 * ) V_6 , F_75 , & V_71 ) ;
return V_71 . V_168 ;
}
static void
F_77 ( struct V_76 * V_118 , void * V_170 )
{
struct V_171 * V_71 = V_170 ;
struct V_49 * V_169 ;
if ( V_118 -> V_143 ) {
V_169 = F_53 ( V_71 -> V_32 -> V_40 ,
V_71 -> V_6 , V_118 ,
V_71 -> V_48 ) ;
if ( ! V_169 )
return;
if ( V_71 -> V_199 )
V_169 -> type |= V_58 ;
F_65 ( V_71 -> V_32 , V_169 ) ;
V_71 -> V_168 ++ ;
V_71 -> V_199 = 0 ;
}
}
static int
F_78 ( struct V_31 * V_32 , struct V_6 * V_6 ,
T_2 V_48 )
{
struct V_171 V_71 = {
V_32 ,
V_6 ,
1 ,
V_48 ,
0
} ;
if ( V_71 . V_199 && ! F_68 ( V_6 , 1 , 3 ) )
V_71 . V_199 =
( V_6 -> V_86 & V_200 ) ;
F_35 ( ( T_1 * ) V_6 , F_77 , & V_71 ) ;
return V_71 . V_168 ;
}
T_1 * F_79 ( struct V_6 * V_6 )
{
T_1 * V_201 = NULL ;
int V_2 ;
if ( V_6 == NULL || V_6 -> V_14 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_6 -> V_14 ; V_2 ++ ) {
V_201 = ( T_1 * ) V_6 + V_8 * ( V_2 + 1 ) ;
if ( V_201 [ 0 ] == V_79 )
break;
}
if ( V_2 == V_6 -> V_14 )
return NULL ;
return V_201 ;
}
static void
F_80 ( struct V_31 * V_32 , T_4 * V_202 )
{
V_32 -> V_203 [ 5 ] |= ( V_202 [ 6 ] >> 7 ) << 1 ;
V_32 -> V_204 = V_202 [ 6 ] & 1 ;
V_32 -> V_205 = V_202 [ 7 ] * 5 ;
V_32 -> V_206 [ 0 ] = V_202 [ 8 ] >> 7 ;
V_32 -> V_206 [ 1 ] = ( V_202 [ 8 ] >> 6 ) & 1 ;
V_32 -> V_207 [ 0 ] = V_202 [ 9 ] ;
V_32 -> V_208 [ 0 ] = V_202 [ 10 ] ;
V_32 -> V_207 [ 1 ] = V_202 [ 11 ] ;
V_32 -> V_208 [ 1 ] = V_202 [ 12 ] ;
F_81 ( L_13
L_14
L_15
L_16
L_17 ,
V_32 -> V_204 ,
V_32 -> V_205 ,
( int ) V_32 -> V_206 [ 0 ] ,
( int ) V_32 -> V_206 [ 1 ] ,
V_32 -> V_207 [ 0 ] ,
V_32 -> V_207 [ 1 ] ,
V_32 -> V_208 [ 0 ] ,
V_32 -> V_208 [ 1 ] ) ;
}
static void
F_82 ( struct V_76 * V_50 , void * V_81 )
{
if ( V_50 -> V_81 . V_173 . type == V_209 )
* ( T_1 * * ) V_81 = V_50 -> V_81 . V_173 . V_81 . V_210 . V_210 ;
}
void F_83 ( struct V_31 * V_32 , struct V_6 * V_6 )
{
T_4 * V_203 = V_32 -> V_203 ;
T_1 * V_211 ;
T_1 * V_212 ;
T_1 * V_202 ;
int V_213 = 0 ;
int V_214 ;
int V_215 ;
memset ( V_203 , 0 , sizeof( V_32 -> V_203 ) ) ;
V_211 = F_79 ( V_6 ) ;
if ( ! V_211 ) {
F_54 ( L_18 ) ;
return;
}
V_212 = NULL ;
F_35 ( ( T_1 * ) V_6 , F_82 , & V_212 ) ;
for ( V_214 = 0 ; V_212 && V_214 < 13 ; V_214 ++ ) {
if ( V_212 [ V_214 ] == 0x0a )
break;
V_203 [ 20 + V_214 ] = V_212 [ V_214 ] ;
}
V_203 [ 4 ] = ( V_211 [ 1 ] << 5 ) | V_214 ;
F_54 ( L_19 , V_203 + 20 ) ;
V_203 [ 0 ] = 2 << 3 ;
V_203 [ 16 ] = V_6 -> V_43 [ 0 ] ;
V_203 [ 17 ] = V_6 -> V_43 [ 1 ] ;
V_203 [ 18 ] = V_6 -> V_216 [ 0 ] ;
V_203 [ 19 ] = V_6 -> V_216 [ 1 ] ;
for ( V_202 = V_211 + 4 ; V_202 < V_211 + V_211 [ 2 ] ; V_202 += V_215 + 1 ) {
V_215 = V_202 [ 0 ] & 0x1f ;
switch ( ( V_202 [ 0 ] & 0xe0 ) >> 5 ) {
case V_217 :
V_213 = V_215 / 3 ;
memcpy ( V_203 + 20 + V_214 , & V_202 [ 1 ] , V_215 ) ;
break;
case V_218 :
V_203 [ 7 ] = V_202 [ 1 ] ;
break;
case V_219 :
if ( V_202 [ 1 ] == 0x03 && V_202 [ 2 ] == 0x0c && V_202 [ 3 ] == 0 )
F_80 ( V_32 , V_202 ) ;
break;
default:
break;
}
}
V_203 [ 5 ] |= V_213 << 4 ;
V_203 [ 2 ] = ( 20 + V_214 + V_213 * 3 + 3 ) / 4 ;
F_54 ( L_20 , ( int ) V_203 [ 2 ] , V_213 ) ;
}
int F_84 ( struct V_31 * V_32 ,
struct V_49 * V_63 )
{
int V_2 = ! ! ( V_63 -> V_27 & V_117 ) ;
int V_92 , V_220 ;
if ( ! V_32 -> V_206 [ 0 ] )
return 0 ;
if ( ! V_32 -> V_206 [ 1 ] )
V_2 = 0 ;
V_92 = V_32 -> V_208 [ V_2 ] ;
V_220 = V_32 -> V_207 [ V_2 ] ;
if ( V_92 == 255 || V_220 == 255 )
return 0 ;
if ( V_92 )
V_92 = F_33 ( 2 * ( V_92 - 1 ) , 500 ) ;
if ( V_220 )
V_220 = F_33 ( 2 * ( V_220 - 1 ) , 500 ) ;
return F_85 ( V_220 - V_92 , 0 ) ;
}
struct V_31 * F_86 ( struct V_221 * V_222 ,
struct V_49 * V_63 )
{
struct V_31 * V_32 ;
struct V_59 * V_40 = V_222 -> V_40 ;
F_47 (connector, &dev->mode_config.connector_list, head)
if ( V_32 -> V_222 == V_222 && V_32 -> V_203 [ 0 ] )
return V_32 ;
return NULL ;
}
bool F_87 ( struct V_6 * V_6 )
{
T_1 * V_201 ;
int V_2 , V_223 ;
int V_224 , V_225 ;
bool V_226 = false ;
V_201 = F_79 ( V_6 ) ;
if ( ! V_201 )
goto V_227;
V_224 = 4 ;
V_225 = V_201 [ 2 ] ;
for ( V_2 = V_224 ; V_2 < V_225 ;
V_2 += ( ( V_201 [ V_2 ] & 0x1f ) + 1 ) ) {
if ( ( V_201 [ V_2 ] >> 5 ) == V_219 ) {
V_223 = V_201 [ V_2 + 1 ] | ( V_201 [ V_2 + 2 ] << 8 ) |
V_201 [ V_2 + 3 ] << 16 ;
if ( V_223 == V_228 )
V_226 = true ;
break;
}
}
V_227:
return V_226 ;
}
bool F_88 ( struct V_6 * V_6 )
{
T_1 * V_201 ;
int V_2 , V_33 ;
bool V_229 = false ;
int V_224 , V_225 ;
V_201 = F_79 ( V_6 ) ;
if ( ! V_201 )
goto V_227;
V_229 = ( ( V_201 [ 3 ] & V_230 ) != 0 ) ;
if ( V_229 ) {
F_54 ( L_21 ) ;
goto V_227;
}
V_224 = 4 ;
V_225 = V_201 [ 2 ] ;
for ( V_2 = V_224 ; V_2 < V_225 ;
V_2 += ( ( V_201 [ V_2 ] & 0x1f ) + 1 ) ) {
if ( ( V_201 [ V_2 ] >> 5 ) == V_217 ) {
V_229 = true ;
for ( V_33 = 1 ; V_33 < ( V_201 [ V_2 ] & 0x1f ) ; V_33 += 3 )
F_54 ( L_22 ,
( V_201 [ V_2 + V_33 ] >> 3 ) & 0xf ) ;
goto V_227;
}
}
V_227:
return V_229 ;
}
static void F_89 ( struct V_6 * V_6 ,
struct V_231 * V_232 )
{
T_1 * V_201 ;
V_232 -> V_152 = V_6 -> V_159 * 10 ;
V_232 -> V_155 = V_6 -> V_160 * 10 ;
V_232 -> V_233 = 0 ;
V_232 -> V_234 = 0 ;
if ( V_6 -> V_10 < 4 )
return;
if ( ! ( V_6 -> V_84 & V_85 ) )
return;
switch ( V_6 -> V_84 & V_235 ) {
case V_236 :
V_232 -> V_233 = 6 ;
break;
case V_237 :
V_232 -> V_233 = 8 ;
break;
case V_238 :
V_232 -> V_233 = 10 ;
break;
case V_239 :
V_232 -> V_233 = 12 ;
break;
case V_240 :
V_232 -> V_233 = 14 ;
break;
case V_241 :
V_232 -> V_233 = 16 ;
break;
case V_242 :
default:
V_232 -> V_233 = 0 ;
break;
}
V_232 -> V_234 = V_243 ;
if ( V_232 -> V_234 & V_244 )
V_232 -> V_234 = V_245 ;
if ( V_232 -> V_234 & V_246 )
V_232 -> V_234 = V_247 ;
V_201 = F_79 ( V_6 ) ;
if ( ! V_201 )
return;
V_232 -> V_248 = V_201 [ 1 ] ;
}
int F_90 ( struct V_31 * V_32 , struct V_6 * V_6 )
{
int V_249 = 0 ;
T_2 V_48 ;
if ( V_6 == NULL ) {
return 0 ;
}
if ( ! F_7 ( V_6 ) ) {
F_14 ( V_32 -> V_40 -> V_40 , L_23 ,
F_15 ( V_32 ) ) ;
return 0 ;
}
V_48 = F_20 ( V_6 ) ;
V_249 += F_78 ( V_32 , V_6 , V_48 ) ;
V_249 += F_76 ( V_32 , V_6 ) ;
V_249 += F_73 ( V_32 , V_6 ) ;
V_249 += F_71 ( V_32 , V_6 ) ;
V_249 += F_67 ( V_32 , V_6 ) ;
if ( V_48 & ( V_55 | V_56 ) )
F_23 ( V_32 , V_48 ) ;
F_89 ( V_6 , & V_32 -> V_41 ) ;
return V_249 ;
}
int F_91 ( struct V_31 * V_32 ,
int V_67 , int V_68 )
{
int V_2 , V_250 , V_249 = 0 ;
struct V_49 * V_63 ;
struct V_59 * V_40 = V_32 -> V_40 ;
V_250 = sizeof( V_66 ) / sizeof( struct V_49 ) ;
if ( V_67 < 0 )
V_67 = 0 ;
if ( V_68 < 0 )
V_68 = 0 ;
for ( V_2 = 0 ; V_2 < V_250 ; V_2 ++ ) {
const struct V_49 * V_65 = & V_66 [ V_2 ] ;
if ( V_67 && V_68 ) {
if ( V_65 -> V_67 > V_67 ||
V_65 -> V_68 > V_68 )
continue;
}
if ( F_30 ( V_65 ) > 61 )
continue;
V_63 = F_31 ( V_40 , V_65 ) ;
if ( V_63 ) {
F_65 ( V_32 , V_63 ) ;
V_249 ++ ;
}
}
return V_249 ;
}
