int F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < sizeof( V_4 ) ; V_2 ++ )
if ( V_1 [ V_2 ] == V_4 [ V_2 ] )
V_3 ++ ;
return V_3 ;
}
bool F_2 ( T_1 * V_1 )
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
if ( V_21 == - V_29 ) {
F_10 ( L_7 ,
V_16 -> V_30 ) ;
break;
}
} while ( V_21 != 2 && -- V_22 );
return V_21 == 2 ? 0 : - 1 ;
}
static bool F_11 ( T_1 * V_31 , int V_32 )
{
int V_2 ;
T_2 * V_1 = ( T_2 * ) V_31 ;
for ( V_2 = 0 ; V_2 < V_32 / 4 ; V_2 ++ )
if ( * ( V_1 + V_2 ) != 0 )
return false ;
return true ;
}
static T_1 *
F_12 ( struct V_33 * V_34 , struct V_15 * V_16 )
{
int V_2 , V_35 = 0 , V_36 = 0 ;
T_1 * V_18 , * V_37 ;
if ( ( V_18 = F_13 ( V_8 , V_38 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_16 , V_18 , 0 , V_8 ) )
goto V_39;
if ( F_2 ( V_18 ) )
break;
if ( V_2 == 0 && F_11 ( V_18 , V_8 ) ) {
V_34 -> V_40 ++ ;
goto V_41;
}
}
if ( V_2 == 4 )
goto V_41;
if ( V_18 [ 0x7e ] == 0 )
return V_18 ;
V_37 = F_14 ( V_18 , ( V_18 [ 0x7e ] + 1 ) * V_8 , V_38 ) ;
if ( ! V_37 )
goto V_39;
V_18 = V_37 ;
for ( V_35 = 1 ; V_35 <= V_18 [ 0x7e ] ; V_35 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_16 ,
V_18 + ( V_36 + 1 ) * V_8 ,
V_35 , V_8 ) )
goto V_39;
if ( F_2 ( V_18 + ( V_36 + 1 ) * V_8 ) ) {
V_36 ++ ;
break;
}
}
if ( V_2 == 4 )
F_15 ( V_34 -> V_42 -> V_42 ,
L_8 ,
F_16 ( V_34 ) , V_35 ) ;
}
if ( V_36 != V_18 [ 0x7e ] ) {
V_18 [ V_8 - 1 ] += V_18 [ 0x7e ] - V_36 ;
V_18 [ 0x7e ] = V_36 ;
V_37 = F_14 ( V_18 , ( V_36 + 1 ) * V_8 , V_38 ) ;
if ( ! V_37 )
goto V_39;
V_18 = V_37 ;
}
return V_18 ;
V_41:
F_15 ( V_34 -> V_42 -> V_42 , L_9 ,
F_16 ( V_34 ) , V_35 ) ;
V_39:
F_17 ( V_18 ) ;
return NULL ;
}
static bool
F_18 ( struct V_15 * V_16 )
{
unsigned char V_39 ;
return ( F_8 ( V_16 , & V_39 , 0 , 1 ) == 0 ) ;
}
struct V_6 * F_19 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = NULL ;
if ( F_18 ( V_16 ) )
V_6 = (struct V_6 * ) F_12 ( V_34 , V_16 ) ;
V_34 -> V_43 . V_1 = ( char * ) V_6 ;
return V_6 ;
}
static bool F_20 ( struct V_6 * V_6 , char * V_44 )
{
char F_20 [ 3 ] ;
F_20 [ 0 ] = ( ( V_6 -> V_45 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_20 [ 1 ] = ( ( ( V_6 -> V_45 [ 0 ] & 0x3 ) << 3 ) |
( ( V_6 -> V_45 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_20 [ 2 ] = ( V_6 -> V_45 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_20 , V_44 , 3 ) ;
}
static T_2 F_21 ( struct V_6 * V_6 )
{
struct V_46 * V_47 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_22 ( V_48 ) ; V_2 ++ ) {
V_47 = & V_48 [ V_2 ] ;
if ( F_20 ( V_6 , V_47 -> V_44 ) &&
( F_23 ( V_6 ) == V_47 -> V_49 ) )
return V_47 -> V_50 ;
}
return 0 ;
}
static void F_24 ( struct V_33 * V_34 ,
T_2 V_50 )
{
struct V_51 * V_52 , * V_53 , * V_54 ;
int V_55 = 0 ;
if ( F_25 ( & V_34 -> V_56 ) )
return;
if ( V_50 & V_57 )
V_55 = 60 ;
if ( V_50 & V_58 )
V_55 = 75 ;
V_54 = F_26 ( & V_34 -> V_56 ,
struct V_51 , V_59 ) ;
F_27 (cur_mode, t, &connector->probed_modes, head) {
V_53 -> type &= ~ V_60 ;
if ( V_53 == V_54 )
continue;
if ( F_28 ( V_53 ) > F_28 ( V_54 ) )
V_54 = V_53 ;
if ( ( F_28 ( V_53 ) == F_28 ( V_54 ) ) &&
F_29 ( V_53 , V_55 ) <
F_29 ( V_54 , V_55 ) ) {
V_54 = V_53 ;
}
}
V_54 -> type |= V_60 ;
}
struct V_51 * F_30 ( struct V_61 * V_42 ,
int V_62 , int V_63 , int V_64 )
{
struct V_51 * V_65 = NULL ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_66 ; V_2 ++ ) {
const struct V_51 * V_67 = & V_68 [ V_2 ] ;
if ( V_62 == V_67 -> V_69 &&
V_63 == V_67 -> V_70 &&
V_64 == F_31 ( V_67 ) ) {
V_65 = F_32 ( V_42 , V_67 ) ;
break;
}
}
return V_65 ;
}
static void
F_33 ( T_1 * V_71 , T_3 * V_72 , void * V_73 )
{
int V_2 , V_74 = 0 ;
T_1 V_75 = V_71 [ 0x02 ] ;
T_1 * V_76 = V_71 + V_75 ;
V_74 = ( 127 - V_75 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_74 ; V_2 ++ )
V_72 ( (struct V_77 * ) ( V_76 + 18 * V_2 ) , V_73 ) ;
}
static void
F_34 ( T_1 * V_71 , T_3 * V_72 , void * V_73 )
{
unsigned int V_2 , V_74 = F_35 ( ( int ) V_71 [ 0x02 ] , 6 ) ;
T_1 * V_76 = V_71 + 5 ;
if ( V_71 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_74 ; V_2 ++ )
V_72 ( (struct V_77 * ) ( V_76 + 18 * V_2 ) , V_73 ) ;
}
static void
F_36 ( T_1 * V_1 , T_3 * V_72 , void * V_73 )
{
int V_2 ;
struct V_6 * V_6 = (struct V_6 * ) V_1 ;
if ( V_6 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_78 ; V_2 ++ )
V_72 ( & ( V_6 -> V_79 [ V_2 ] ) , V_73 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_71 = V_1 + ( V_2 * V_8 ) ;
switch ( * V_71 ) {
case V_80 :
F_33 ( V_71 , V_72 , V_73 ) ;
break;
case V_81 :
F_34 ( V_71 , V_72 , V_73 ) ;
break;
default:
break;
}
}
}
static void
F_37 ( struct V_77 * V_52 , void * V_82 )
{
T_1 * V_83 = ( T_1 * ) V_52 ;
if ( V_83 [ 3 ] == V_84 )
if ( V_83 [ 15 ] & 0x10 )
* ( bool * ) V_82 = true ;
}
static bool
F_38 ( struct V_6 * V_6 )
{
if ( V_6 -> V_10 >= 4 ) {
bool V_21 ;
F_36 ( ( T_1 * ) V_6 , F_37 , & V_21 ) ;
return V_21 ;
}
return ( ( V_6 -> V_85 & V_86 ) != 0 ) ;
}
static void
F_39 ( struct V_77 * V_52 , void * V_82 )
{
T_1 * V_83 = ( T_1 * ) V_52 ;
if ( V_83 [ 3 ] == V_84 && V_83 [ 10 ] == 0x02 )
* ( T_1 * * ) V_82 = V_83 ;
}
static int
F_40 ( struct V_6 * V_6 )
{
T_1 * V_83 = NULL ;
F_36 ( ( T_1 * ) V_6 , F_39 , & V_83 ) ;
return V_83 ? ( V_83 [ 12 ] * 2 ) : 0 ;
}
static int
F_41 ( struct V_6 * V_6 )
{
T_1 * V_83 = NULL ;
F_36 ( ( T_1 * ) V_6 , F_39 , & V_83 ) ;
return V_83 ? V_83 [ 13 ] : 0 ;
}
static int
F_42 ( struct V_6 * V_6 )
{
T_1 * V_83 = NULL ;
F_36 ( ( T_1 * ) V_6 , F_39 , & V_83 ) ;
return V_83 ? ( V_83 [ 15 ] << 8 ) + V_83 [ 14 ] : 0 ;
}
static int
F_43 ( struct V_6 * V_6 )
{
T_1 * V_83 = NULL ;
F_36 ( ( T_1 * ) V_6 , F_39 , & V_83 ) ;
return V_83 ? V_83 [ 16 ] : 0 ;
}
static int
F_44 ( struct V_6 * V_6 )
{
T_1 * V_83 = NULL ;
F_36 ( ( T_1 * ) V_6 , F_39 , & V_83 ) ;
return V_83 ? V_83 [ 17 ] : 0 ;
}
static int F_45 ( struct V_6 * V_6 )
{
if ( V_6 -> V_10 >= 2 ) {
if ( V_6 -> V_10 >= 4 && ( V_6 -> V_87 & V_88 ) )
return V_89 ;
if ( F_40 ( V_6 ) )
return V_90 ;
return V_91 ;
}
return V_92 ;
}
static int
F_46 ( T_1 V_93 , T_1 V_94 )
{
return ( V_93 == 0x00 && V_94 == 0x00 ) ||
( V_93 == 0x01 && V_94 == 0x01 ) ||
( V_93 == 0x20 && V_94 == 0x20 ) ;
}
static struct V_51 *
F_47 ( struct V_33 * V_34 , struct V_6 * V_6 ,
struct V_95 * V_52 , int V_10 )
{
struct V_61 * V_42 = V_34 -> V_42 ;
struct V_51 * V_96 , * V_65 = NULL ;
int V_62 , V_63 ;
int V_97 ;
unsigned V_98 = ( V_52 -> V_99 & V_100 )
>> V_101 ;
unsigned V_102 = ( V_52 -> V_99 & V_103 )
>> V_104 ;
int V_105 = F_45 ( V_6 ) ;
if ( F_46 ( V_52 -> V_62 , V_52 -> V_99 ) )
return NULL ;
V_62 = V_52 -> V_62 * 8 + 248 ;
V_97 = V_102 + 60 ;
if ( V_98 == 0 ) {
if ( V_10 < 3 )
V_63 = V_62 ;
else
V_63 = ( V_62 * 10 ) / 16 ;
} else if ( V_98 == 1 )
V_63 = ( V_62 * 3 ) / 4 ;
else if ( V_98 == 2 )
V_63 = ( V_62 * 4 ) / 5 ;
else
V_63 = ( V_62 * 9 ) / 16 ;
if ( V_97 == 60 &&
( ( V_62 == 1360 && V_63 == 765 ) ||
( V_62 == 1368 && V_63 == 769 ) ) ) {
V_62 = 1366 ;
V_63 = 768 ;
}
F_48 (m, &connector->probed_modes, head)
if ( V_96 -> V_69 == V_62 && V_96 -> V_70 == V_63 &&
F_31 ( V_96 ) == V_97 )
return NULL ;
if ( V_62 == 1366 && V_63 == 768 && V_97 == 60 ) {
V_65 = F_49 ( V_42 , 1366 , 768 , V_97 , 0 , 0 ,
false ) ;
V_65 -> V_69 = 1366 ;
V_65 -> V_106 = V_65 -> V_106 - 1 ;
V_65 -> V_107 = V_65 -> V_107 - 1 ;
return V_65 ;
}
V_65 = F_30 ( V_42 , V_62 , V_63 , V_97 ) ;
if ( V_65 )
return V_65 ;
switch ( V_105 ) {
case V_92 :
break;
case V_91 :
V_65 = F_50 ( V_42 , V_62 , V_63 , V_97 , 0 , 0 ) ;
break;
case V_90 :
V_65 = F_50 ( V_42 , V_62 , V_63 , V_97 , 0 , 0 ) ;
if ( F_51 ( V_65 ) > F_40 ( V_6 ) ) {
F_52 ( V_42 , V_65 ) ;
V_65 = F_53 ( V_42 , V_62 , V_63 ,
V_97 , 0 , 0 ,
F_42 ( V_6 ) ,
F_41 ( V_6 ) ,
F_43 ( V_6 ) ,
F_44 ( V_6 ) ) ;
}
break;
case V_89 :
V_65 = F_49 ( V_42 , V_62 , V_63 , V_97 , 0 , 0 ,
false ) ;
break;
}
return V_65 ;
}
static void
F_54 ( struct V_51 * V_65 ,
struct V_108 * V_109 )
{
int V_2 ;
static const struct {
int V_110 , V_111 ;
} V_112 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_109 -> V_113 & V_114 ) )
return;
for ( V_2 = 0 ; V_2 < F_22 ( V_112 ) ; V_2 ++ ) {
if ( ( V_65 -> V_69 == V_112 [ V_2 ] . V_110 ) &&
( V_65 -> V_70 == V_112 [ V_2 ] . V_111 / 2 ) ) {
V_65 -> V_70 *= 2 ;
V_65 -> V_115 *= 2 ;
V_65 -> V_116 *= 2 ;
V_65 -> V_117 *= 2 ;
V_65 -> V_117 |= 1 ;
}
}
V_65 -> V_27 |= V_118 ;
}
static struct V_51 * F_55 ( struct V_61 * V_42 ,
struct V_6 * V_6 ,
struct V_77 * V_119 ,
T_2 V_50 )
{
struct V_51 * V_65 ;
struct V_108 * V_109 = & V_119 -> V_82 . V_120 ;
unsigned V_121 = ( V_109 -> V_122 & 0xf0 ) << 4 | V_109 -> V_123 ;
unsigned V_124 = ( V_109 -> V_125 & 0xf0 ) << 4 | V_109 -> V_126 ;
unsigned V_127 = ( V_109 -> V_122 & 0xf ) << 8 | V_109 -> V_128 ;
unsigned V_129 = ( V_109 -> V_125 & 0xf ) << 8 | V_109 -> V_130 ;
unsigned V_131 = ( V_109 -> V_132 & 0xc0 ) << 2 | V_109 -> V_133 ;
unsigned V_134 = ( V_109 -> V_132 & 0x30 ) << 4 | V_109 -> V_135 ;
unsigned V_136 = ( V_109 -> V_132 & 0xc ) >> 2 | V_109 -> V_137 >> 4 ;
unsigned V_138 = ( V_109 -> V_132 & 0x3 ) << 4 | ( V_109 -> V_137 & 0xf ) ;
if ( V_121 < 64 || V_124 < 64 )
return NULL ;
if ( V_109 -> V_113 & V_139 ) {
F_5 ( V_140 L_10 ) ;
return NULL ;
}
if ( ! ( V_109 -> V_113 & V_141 ) ) {
F_5 ( V_140 L_11 ) ;
}
if ( ! V_134 || ! V_138 ) {
F_10 ( L_12
L_13 ) ;
return NULL ;
}
V_65 = F_56 ( V_42 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> type = V_142 ;
if ( V_50 & V_143 )
V_119 -> V_144 = F_57 ( 1088 ) ;
V_65 -> clock = F_58 ( V_119 -> V_144 ) * 10 ;
V_65 -> V_69 = V_121 ;
V_65 -> V_106 = V_65 -> V_69 + V_131 ;
V_65 -> V_107 = V_65 -> V_106 + V_134 ;
V_65 -> V_145 = V_65 -> V_69 + V_127 ;
V_65 -> V_70 = V_124 ;
V_65 -> V_115 = V_65 -> V_70 + V_136 ;
V_65 -> V_116 = V_65 -> V_115 + V_138 ;
V_65 -> V_117 = V_65 -> V_70 + V_129 ;
if ( V_65 -> V_107 > V_65 -> V_145 )
V_65 -> V_145 = V_65 -> V_107 + 1 ;
if ( V_65 -> V_116 > V_65 -> V_117 )
V_65 -> V_117 = V_65 -> V_116 + 1 ;
F_54 ( V_65 , V_109 ) ;
F_59 ( V_65 ) ;
if ( V_50 & V_146 ) {
V_109 -> V_113 |= V_147 | V_148 ;
}
V_65 -> V_27 |= ( V_109 -> V_113 & V_147 ) ?
V_149 : V_150 ;
V_65 -> V_27 |= ( V_109 -> V_113 & V_148 ) ?
V_151 : V_152 ;
V_65 -> V_153 = V_109 -> V_154 | ( V_109 -> V_155 & 0xf0 ) << 4 ;
V_65 -> V_156 = V_109 -> V_157 | ( V_109 -> V_155 & 0xf ) << 8 ;
if ( V_50 & V_158 ) {
V_65 -> V_153 *= 10 ;
V_65 -> V_156 *= 10 ;
}
if ( V_50 & V_159 ) {
V_65 -> V_153 = V_6 -> V_160 * 10 ;
V_65 -> V_156 = V_6 -> V_161 * 10 ;
}
return V_65 ;
}
static bool
F_60 ( const struct V_51 * V_65 )
{
return ( V_65 -> V_145 - V_65 -> V_69 == 160 ) &&
( V_65 -> V_107 - V_65 -> V_69 == 80 ) &&
( V_65 -> V_107 - V_65 -> V_106 == 32 ) &&
( V_65 -> V_115 - V_65 -> V_70 == 3 ) ;
}
static bool
F_61 ( const struct V_51 * V_65 ,
struct V_6 * V_6 , T_1 * V_52 )
{
int V_162 , V_163 , V_164 ;
V_163 = V_52 [ 7 ] ;
if ( V_6 -> V_10 >= 4 )
V_163 += ( ( V_52 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_164 = V_52 [ 8 ] ;
if ( V_6 -> V_10 >= 4 )
V_164 += ( ( V_52 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_162 = F_51 ( V_65 ) ;
return ( V_162 <= V_164 && V_162 >= V_163 ) ;
}
static bool
F_62 ( const struct V_51 * V_65 ,
struct V_6 * V_6 , T_1 * V_52 )
{
int V_165 , V_166 , V_167 ;
V_166 = V_52 [ 5 ] ;
if ( V_6 -> V_10 >= 4 )
V_166 += ( ( V_52 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_167 = V_52 [ 6 ] ;
if ( V_6 -> V_10 >= 4 )
V_167 += ( ( V_52 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_165 = F_31 ( V_65 ) ;
return ( V_165 <= V_167 && V_165 >= V_166 ) ;
}
static T_2
F_63 ( struct V_6 * V_6 , T_1 * V_52 )
{
if ( V_52 [ 9 ] == 0 || V_52 [ 9 ] == 255 )
return 0 ;
if ( V_6 -> V_10 >= 4 && V_52 [ 10 ] == 0x04 )
return ( V_52 [ 9 ] * 10000 ) - ( ( V_52 [ 12 ] >> 2 ) * 250 ) ;
return V_52 [ 9 ] * 10000 + 5001 ;
}
static bool
F_64 ( const struct V_51 * V_65 , struct V_6 * V_6 ,
struct V_77 * V_119 )
{
T_2 V_168 ;
T_1 * V_52 = ( T_1 * ) V_119 ;
if ( ! F_61 ( V_65 , V_6 , V_52 ) )
return false ;
if ( ! F_62 ( V_65 , V_6 , V_52 ) )
return false ;
if ( ( V_168 = F_63 ( V_6 , V_52 ) ) )
if ( V_65 -> clock > V_168 )
return false ;
if ( V_6 -> V_10 >= 4 && V_52 [ 10 ] == 0x04 )
if ( V_52 [ 13 ] && V_65 -> V_69 > 8 * ( V_52 [ 13 ] + ( 256 * ( V_52 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_60 ( V_65 ) && ! F_38 ( V_6 ) )
return false ;
return true ;
}
static int
F_65 ( struct V_33 * V_34 , struct V_6 * V_6 ,
struct V_77 * V_119 )
{
int V_2 , V_169 = 0 ;
struct V_51 * V_170 ;
struct V_61 * V_42 = V_34 -> V_42 ;
for ( V_2 = 0 ; V_2 < V_66 ; V_2 ++ ) {
if ( F_64 ( V_68 + V_2 , V_6 , V_119 ) ) {
V_170 = F_32 ( V_42 , & V_68 [ V_2 ] ) ;
if ( V_170 ) {
F_66 ( V_34 , V_170 ) ;
V_169 ++ ;
}
}
}
return V_169 ;
}
static void
F_67 ( struct V_77 * V_119 , void * V_171 )
{
struct V_172 * V_73 = V_171 ;
struct V_173 * V_82 = & V_119 -> V_82 . V_174 ;
int V_175 = ( V_73 -> V_6 -> V_87 & V_88 ) ;
if ( V_175 && V_82 -> type == V_84 )
V_73 -> V_169 += F_65 ( V_73 -> V_34 ,
V_73 -> V_6 ,
V_119 ) ;
}
static int
F_68 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
struct V_172 V_73 = {
V_34 , V_6 , 0 , 0 , 0
} ;
if ( F_69 ( V_6 , 1 , 0 ) )
F_36 ( ( T_1 * ) V_6 , F_67 ,
& V_73 ) ;
return V_73 . V_169 ;
}
static int
F_70 ( struct V_33 * V_34 , struct V_77 * V_119 )
{
int V_2 , V_35 , V_96 , V_169 = 0 ;
struct V_51 * V_65 ;
T_1 * V_176 = ( ( T_1 * ) V_119 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_35 = 7 ; V_35 > 0 ; V_35 -- ) {
V_96 = ( V_2 * 8 ) + ( 7 - V_35 ) ;
if ( V_96 >= F_22 ( V_177 ) )
break;
if ( V_176 [ V_2 ] & ( 1 << V_35 ) ) {
V_65 = F_30 ( V_34 -> V_42 ,
V_177 [ V_96 ] . V_110 ,
V_177 [ V_96 ] . V_111 ,
V_177 [ V_96 ] . V_83
) ;
if ( V_65 ) {
F_66 ( V_34 , V_65 ) ;
V_169 ++ ;
}
}
}
}
return V_169 ;
}
static void
F_71 ( struct V_77 * V_119 , void * V_171 )
{
struct V_172 * V_73 = V_171 ;
struct V_173 * V_82 = & V_119 -> V_82 . V_174 ;
if ( V_82 -> type == V_178 )
V_73 -> V_169 += F_70 ( V_73 -> V_34 , V_119 ) ;
}
static int
F_72 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
struct V_61 * V_42 = V_34 -> V_42 ;
unsigned long V_179 = V_6 -> V_180 . V_181 |
( V_6 -> V_180 . V_182 << 8 ) |
( ( V_6 -> V_180 . V_183 & 0x80 ) << 9 ) ;
int V_2 , V_169 = 0 ;
struct V_172 V_73 = {
V_34 , V_6 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_184 ; V_2 ++ ) {
if ( V_179 & ( 1 << V_2 ) ) {
struct V_51 * V_170 ;
V_170 = F_32 ( V_42 , & V_185 [ V_2 ] ) ;
if ( V_170 ) {
F_66 ( V_34 , V_170 ) ;
V_169 ++ ;
}
}
}
if ( F_69 ( V_6 , 1 , 0 ) )
F_36 ( ( T_1 * ) V_6 ,
F_71 , & V_73 ) ;
return V_169 + V_73 . V_169 ;
}
static void
F_73 ( struct V_77 * V_119 , void * V_171 )
{
struct V_172 * V_73 = V_171 ;
struct V_173 * V_82 = & V_119 -> V_82 . V_174 ;
struct V_33 * V_34 = V_73 -> V_34 ;
struct V_6 * V_6 = V_73 -> V_6 ;
if ( V_82 -> type == V_186 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_95 * V_187 ;
struct V_51 * V_170 ;
V_187 = & V_82 -> V_82 . V_188 [ V_2 ] ;
V_170 = F_47 ( V_34 , V_6 , V_187 ,
V_6 -> V_10 ) ;
if ( V_170 ) {
F_66 ( V_34 , V_170 ) ;
V_73 -> V_169 ++ ;
}
}
}
}
static int
F_74 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
int V_2 , V_169 = 0 ;
struct V_172 V_73 = {
V_34 , V_6 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_189 ; V_2 ++ ) {
struct V_51 * V_170 ;
V_170 = F_47 ( V_34 , V_6 ,
& V_6 -> V_190 [ V_2 ] ,
V_6 -> V_10 ) ;
if ( V_170 ) {
F_66 ( V_34 , V_170 ) ;
V_169 ++ ;
}
}
if ( F_69 ( V_6 , 1 , 0 ) )
F_36 ( ( T_1 * ) V_6 , F_73 ,
& V_73 ) ;
return V_169 + V_73 . V_169 ;
}
static int F_75 ( struct V_33 * V_34 ,
struct V_77 * V_119 )
{
int V_2 , V_35 , V_169 = 0 ;
struct V_51 * V_170 ;
struct V_61 * V_42 = V_34 -> V_42 ;
struct V_191 * V_192 ;
const int V_193 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_194 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_195 ( V_196 ) , V_197 ;
V_192 = & ( V_119 -> V_82 . V_174 . V_82 . V_192 [ V_2 ] ) ;
if ( ! memcmp ( V_192 -> V_198 , V_194 , 3 ) )
continue;
V_197 = ( V_192 -> V_198 [ 0 ] + ( ( V_192 -> V_198 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_192 -> V_198 [ 1 ] & 0x0c ) {
case 0x00 :
V_196 = V_197 * 4 / 3 ;
break;
case 0x04 :
V_196 = V_197 * 16 / 9 ;
break;
case 0x08 :
V_196 = V_197 * 16 / 10 ;
break;
case 0x0c :
V_196 = V_197 * 15 / 9 ;
break;
}
for ( V_35 = 1 ; V_35 < 5 ; V_35 ++ ) {
if ( V_192 -> V_198 [ 2 ] & ( 1 << V_35 ) ) {
V_170 = F_49 ( V_42 , V_196 , V_197 ,
V_193 [ V_35 ] , V_35 == 0 ,
false , false ) ;
if ( V_170 ) {
F_66 ( V_34 , V_170 ) ;
V_169 ++ ;
}
}
}
}
return V_169 ;
}
static void
F_76 ( struct V_77 * V_119 , void * V_171 )
{
struct V_172 * V_73 = V_171 ;
struct V_173 * V_82 = & V_119 -> V_82 . V_174 ;
if ( V_82 -> type == V_199 )
V_73 -> V_169 += F_75 ( V_73 -> V_34 , V_119 ) ;
}
static int
F_77 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
struct V_172 V_73 = {
V_34 , V_6 , 0 , 0 , 0
} ;
if ( F_69 ( V_6 , 1 , 2 ) )
F_36 ( ( T_1 * ) V_6 , F_76 , & V_73 ) ;
return V_73 . V_169 ;
}
static void
F_78 ( struct V_77 * V_119 , void * V_171 )
{
struct V_172 * V_73 = V_171 ;
struct V_51 * V_170 ;
if ( V_119 -> V_144 ) {
V_170 = F_55 ( V_73 -> V_34 -> V_42 ,
V_73 -> V_6 , V_119 ,
V_73 -> V_50 ) ;
if ( ! V_170 )
return;
if ( V_73 -> V_200 )
V_170 -> type |= V_60 ;
F_66 ( V_73 -> V_34 , V_170 ) ;
V_73 -> V_169 ++ ;
V_73 -> V_200 = 0 ;
}
}
static int
F_79 ( struct V_33 * V_34 , struct V_6 * V_6 ,
T_2 V_50 )
{
struct V_172 V_73 = {
V_34 ,
V_6 ,
1 ,
V_50 ,
0
} ;
if ( V_73 . V_200 && ! F_69 ( V_6 , 1 , 3 ) )
V_73 . V_200 =
( V_6 -> V_87 & V_201 ) ;
F_36 ( ( T_1 * ) V_6 , F_78 , & V_73 ) ;
return V_73 . V_169 ;
}
T_1 * F_80 ( struct V_6 * V_6 )
{
T_1 * V_202 = NULL ;
int V_2 ;
if ( V_6 == NULL || V_6 -> V_14 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_6 -> V_14 ; V_2 ++ ) {
V_202 = ( T_1 * ) V_6 + V_8 * ( V_2 + 1 ) ;
if ( V_202 [ 0 ] == V_80 )
break;
}
if ( V_2 == V_6 -> V_14 )
return NULL ;
return V_202 ;
}
static int
F_81 ( struct V_33 * V_34 , T_1 * V_203 , T_1 V_19 )
{
struct V_61 * V_42 = V_34 -> V_42 ;
T_1 * V_65 , V_204 ;
int V_169 = 0 ;
for ( V_65 = V_203 ; V_65 < V_203 + V_19 ; V_65 ++ ) {
V_204 = ( * V_65 & 127 ) - 1 ;
if ( V_204 < V_205 ) {
struct V_51 * V_170 ;
V_170 = F_32 ( V_42 ,
& V_206 [ V_204 ] ) ;
if ( V_170 ) {
F_66 ( V_34 , V_170 ) ;
V_169 ++ ;
}
}
}
return V_169 ;
}
static int
F_82 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
T_1 * V_207 = F_80 ( V_6 ) ;
T_1 * V_203 , V_208 ;
int V_169 = 0 ;
if ( V_207 && V_207 [ 1 ] >= 3 ) {
for ( V_203 = V_207 + 4 ; V_203 < V_207 + V_207 [ 2 ] ; V_203 += V_208 + 1 ) {
V_208 = V_203 [ 0 ] & 0x1f ;
if ( ( ( V_203 [ 0 ] & 0xe0 ) >> 5 ) == V_209 )
V_169 += F_81 ( V_34 , V_203 + 1 , V_208 ) ;
}
}
return V_169 ;
}
static void
F_83 ( struct V_33 * V_34 , T_4 * V_203 )
{
V_34 -> V_210 [ 5 ] |= ( V_203 [ 6 ] >> 7 ) << 1 ;
V_34 -> V_211 = V_203 [ 6 ] & 1 ;
V_34 -> V_212 = V_203 [ 7 ] * 5 ;
V_34 -> V_213 [ 0 ] = V_203 [ 8 ] >> 7 ;
V_34 -> V_213 [ 1 ] = ( V_203 [ 8 ] >> 6 ) & 1 ;
V_34 -> V_214 [ 0 ] = V_203 [ 9 ] ;
V_34 -> V_215 [ 0 ] = V_203 [ 10 ] ;
V_34 -> V_214 [ 1 ] = V_203 [ 11 ] ;
V_34 -> V_215 [ 1 ] = V_203 [ 12 ] ;
F_84 ( L_14
L_15
L_16
L_17
L_18 ,
V_34 -> V_211 ,
V_34 -> V_212 ,
( int ) V_34 -> V_213 [ 0 ] ,
( int ) V_34 -> V_213 [ 1 ] ,
V_34 -> V_214 [ 0 ] ,
V_34 -> V_214 [ 1 ] ,
V_34 -> V_215 [ 0 ] ,
V_34 -> V_215 [ 1 ] ) ;
}
static void
F_85 ( struct V_77 * V_52 , void * V_82 )
{
if ( V_52 -> V_82 . V_174 . type == V_216 )
* ( T_1 * * ) V_82 = V_52 -> V_82 . V_174 . V_82 . V_217 . V_217 ;
}
void F_86 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
T_4 * V_210 = V_34 -> V_210 ;
T_1 * V_207 ;
T_1 * V_30 ;
T_1 * V_203 ;
int V_218 = 0 ;
int V_219 ;
int V_208 ;
memset ( V_210 , 0 , sizeof( V_34 -> V_210 ) ) ;
V_207 = F_80 ( V_6 ) ;
if ( ! V_207 ) {
F_10 ( L_19 ) ;
return;
}
V_30 = NULL ;
F_36 ( ( T_1 * ) V_6 , F_85 , & V_30 ) ;
for ( V_219 = 0 ; V_30 && V_219 < 13 ; V_219 ++ ) {
if ( V_30 [ V_219 ] == 0x0a )
break;
V_210 [ 20 + V_219 ] = V_30 [ V_219 ] ;
}
V_210 [ 4 ] = ( V_207 [ 1 ] << 5 ) | V_219 ;
F_10 ( L_20 , V_210 + 20 ) ;
V_210 [ 0 ] = 2 << 3 ;
V_210 [ 16 ] = V_6 -> V_45 [ 0 ] ;
V_210 [ 17 ] = V_6 -> V_45 [ 1 ] ;
V_210 [ 18 ] = V_6 -> V_220 [ 0 ] ;
V_210 [ 19 ] = V_6 -> V_220 [ 1 ] ;
if ( V_207 [ 1 ] >= 3 )
for ( V_203 = V_207 + 4 ; V_203 < V_207 + V_207 [ 2 ] ; V_203 += V_208 + 1 ) {
V_208 = V_203 [ 0 ] & 0x1f ;
switch ( ( V_203 [ 0 ] & 0xe0 ) >> 5 ) {
case V_221 :
V_218 = V_208 / 3 ;
memcpy ( V_210 + 20 + V_219 , & V_203 [ 1 ] , V_208 ) ;
break;
case V_222 :
V_210 [ 7 ] = V_203 [ 1 ] ;
break;
case V_223 :
if ( V_203 [ 1 ] == 0x03 && V_203 [ 2 ] == 0x0c && V_203 [ 3 ] == 0 )
F_83 ( V_34 , V_203 ) ;
break;
default:
break;
}
}
V_210 [ 5 ] |= V_218 << 4 ;
V_210 [ 2 ] = ( 20 + V_219 + V_218 * 3 + 3 ) / 4 ;
F_10 ( L_21 , ( int ) V_210 [ 2 ] , V_218 ) ;
}
int F_87 ( struct V_33 * V_34 ,
struct V_51 * V_65 )
{
int V_2 = ! ! ( V_65 -> V_27 & V_118 ) ;
int V_93 , V_224 ;
if ( ! V_34 -> V_213 [ 0 ] )
return 0 ;
if ( ! V_34 -> V_213 [ 1 ] )
V_2 = 0 ;
V_93 = V_34 -> V_215 [ V_2 ] ;
V_224 = V_34 -> V_214 [ V_2 ] ;
if ( V_93 == 255 || V_224 == 255 )
return 0 ;
if ( V_93 )
V_93 = F_35 ( 2 * ( V_93 - 1 ) , 500 ) ;
if ( V_224 )
V_224 = F_35 ( 2 * ( V_224 - 1 ) , 500 ) ;
return F_88 ( V_224 - V_93 , 0 ) ;
}
struct V_33 * F_89 ( struct V_225 * V_226 ,
struct V_51 * V_65 )
{
struct V_33 * V_34 ;
struct V_61 * V_42 = V_226 -> V_42 ;
F_48 (connector, &dev->mode_config.connector_list, head)
if ( V_34 -> V_226 == V_226 && V_34 -> V_210 [ 0 ] )
return V_34 ;
return NULL ;
}
bool F_90 ( struct V_6 * V_6 )
{
T_1 * V_202 ;
int V_2 , V_227 ;
int V_228 , V_229 ;
bool V_230 = false ;
V_202 = F_80 ( V_6 ) ;
if ( ! V_202 )
goto V_231;
V_228 = 4 ;
V_229 = V_202 [ 2 ] ;
for ( V_2 = V_228 ; V_2 < V_229 ;
V_2 += ( ( V_202 [ V_2 ] & 0x1f ) + 1 ) ) {
if ( ( V_202 [ V_2 ] >> 5 ) == V_223 ) {
V_227 = V_202 [ V_2 + 1 ] | ( V_202 [ V_2 + 2 ] << 8 ) |
V_202 [ V_2 + 3 ] << 16 ;
if ( V_227 == V_232 )
V_230 = true ;
break;
}
}
V_231:
return V_230 ;
}
bool F_91 ( struct V_6 * V_6 )
{
T_1 * V_202 ;
int V_2 , V_35 ;
bool V_233 = false ;
int V_228 , V_229 ;
V_202 = F_80 ( V_6 ) ;
if ( ! V_202 )
goto V_231;
V_233 = ( ( V_202 [ 3 ] & V_234 ) != 0 ) ;
if ( V_233 ) {
F_10 ( L_22 ) ;
goto V_231;
}
V_228 = 4 ;
V_229 = V_202 [ 2 ] ;
for ( V_2 = V_228 ; V_2 < V_229 ;
V_2 += ( ( V_202 [ V_2 ] & 0x1f ) + 1 ) ) {
if ( ( V_202 [ V_2 ] >> 5 ) == V_221 ) {
V_233 = true ;
for ( V_35 = 1 ; V_35 < ( V_202 [ V_2 ] & 0x1f ) ; V_35 += 3 )
F_10 ( L_23 ,
( V_202 [ V_2 + V_35 ] >> 3 ) & 0xf ) ;
goto V_231;
}
}
V_231:
return V_233 ;
}
static void F_92 ( struct V_6 * V_6 ,
struct V_235 * V_236 )
{
T_1 * V_202 ;
V_236 -> V_153 = V_6 -> V_160 * 10 ;
V_236 -> V_156 = V_6 -> V_161 * 10 ;
V_236 -> V_237 = 0 ;
V_236 -> V_238 = 0 ;
if ( V_6 -> V_10 < 4 )
return;
if ( ! ( V_6 -> V_85 & V_86 ) )
return;
switch ( V_6 -> V_85 & V_239 ) {
case V_240 :
V_236 -> V_237 = 6 ;
break;
case V_241 :
V_236 -> V_237 = 8 ;
break;
case V_242 :
V_236 -> V_237 = 10 ;
break;
case V_243 :
V_236 -> V_237 = 12 ;
break;
case V_244 :
V_236 -> V_237 = 14 ;
break;
case V_245 :
V_236 -> V_237 = 16 ;
break;
case V_246 :
default:
V_236 -> V_237 = 0 ;
break;
}
V_236 -> V_238 = V_247 ;
if ( V_236 -> V_238 & V_248 )
V_236 -> V_238 = V_249 ;
if ( V_236 -> V_238 & V_250 )
V_236 -> V_238 = V_251 ;
V_202 = F_80 ( V_6 ) ;
if ( ! V_202 )
return;
V_236 -> V_252 = V_202 [ 1 ] ;
}
int F_93 ( struct V_33 * V_34 , struct V_6 * V_6 )
{
int V_253 = 0 ;
T_2 V_50 ;
if ( V_6 == NULL ) {
return 0 ;
}
if ( ! F_7 ( V_6 ) ) {
F_15 ( V_34 -> V_42 -> V_42 , L_24 ,
F_16 ( V_34 ) ) ;
return 0 ;
}
V_50 = F_21 ( V_6 ) ;
V_253 += F_79 ( V_34 , V_6 , V_50 ) ;
V_253 += F_77 ( V_34 , V_6 ) ;
V_253 += F_74 ( V_34 , V_6 ) ;
V_253 += F_72 ( V_34 , V_6 ) ;
V_253 += F_68 ( V_34 , V_6 ) ;
V_253 += F_82 ( V_34 , V_6 ) ;
if ( V_50 & ( V_57 | V_58 ) )
F_24 ( V_34 , V_50 ) ;
F_92 ( V_6 , & V_34 -> V_43 ) ;
return V_253 ;
}
int F_94 ( struct V_33 * V_34 ,
int V_69 , int V_70 )
{
int V_2 , V_254 , V_253 = 0 ;
struct V_51 * V_65 ;
struct V_61 * V_42 = V_34 -> V_42 ;
V_254 = sizeof( V_68 ) / sizeof( struct V_51 ) ;
if ( V_69 < 0 )
V_69 = 0 ;
if ( V_70 < 0 )
V_70 = 0 ;
for ( V_2 = 0 ; V_2 < V_254 ; V_2 ++ ) {
const struct V_51 * V_67 = & V_68 [ V_2 ] ;
if ( V_69 && V_70 ) {
if ( V_67 -> V_69 > V_69 ||
V_67 -> V_70 > V_70 )
continue;
}
if ( F_31 ( V_67 ) > 61 )
continue;
V_65 = F_32 ( V_42 , V_67 ) ;
if ( V_65 ) {
F_66 ( V_34 , V_65 ) ;
V_253 ++ ;
}
}
return V_253 ;
}
