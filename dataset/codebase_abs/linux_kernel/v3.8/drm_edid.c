int F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < sizeof( V_4 ) ; V_2 ++ )
if ( V_1 [ V_2 ] == V_4 [ V_2 ] )
V_3 ++ ;
return V_3 ;
}
bool F_2 ( T_1 * V_1 , int V_5 , bool V_6 )
{
int V_2 ;
T_1 V_7 = 0 ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
if ( V_9 > 8 || V_9 < 0 )
V_9 = 6 ;
if ( V_5 == 0 ) {
int V_3 = F_1 ( V_1 ) ;
if ( V_3 == 8 ) ;
else if ( V_3 >= V_9 ) {
F_3 ( L_1 ) ;
memcpy ( V_1 , V_4 , sizeof( V_4 ) ) ;
} else {
goto V_10;
}
}
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ )
V_7 += V_1 [ V_2 ] ;
if ( V_7 ) {
if ( V_6 ) {
F_4 ( L_2 , V_7 ) ;
}
if ( V_1 [ 0 ] != 0x02 )
goto V_10;
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_8 -> V_12 != 1 ) {
F_4 ( L_3 , V_8 -> V_12 ) ;
goto V_10;
}
if ( V_8 -> V_13 > 4 )
F_3 ( L_4 ) ;
break;
default:
break;
}
return 1 ;
V_10:
if ( V_1 && V_6 ) {
F_5 ( V_14 L_5 ) ;
F_6 ( V_14 , L_6 , V_15 , 16 , 1 ,
V_1 , V_11 , false ) ;
}
return 0 ;
}
bool F_7 ( struct V_8 * V_8 )
{
int V_2 ;
T_1 * V_16 = ( T_1 * ) V_8 ;
if ( ! V_8 )
return false ;
for ( V_2 = 0 ; V_2 <= V_8 -> V_17 ; V_2 ++ )
if ( ! F_2 ( V_16 + V_2 * V_11 , V_2 , true ) )
return false ;
return true ;
}
static int
F_8 ( struct V_18 * V_19 , unsigned char * V_20 ,
int V_5 , int V_21 )
{
unsigned char V_22 = V_5 * V_11 ;
unsigned char V_23 = V_5 >> 1 ;
unsigned char V_24 = V_23 ? 3 : 2 ;
int V_25 , V_26 = 5 ;
do {
struct V_27 V_28 [] = {
{
. V_29 = V_30 ,
. V_31 = 0 ,
. V_21 = 1 ,
. V_20 = & V_23 ,
} , {
. V_29 = V_32 ,
. V_31 = 0 ,
. V_21 = 1 ,
. V_20 = & V_22 ,
} , {
. V_29 = V_32 ,
. V_31 = V_33 ,
. V_21 = V_21 ,
. V_20 = V_20 ,
}
} ;
V_25 = F_9 ( V_19 , & V_28 [ 3 - V_24 ] , V_24 ) ;
if ( V_25 == - V_34 ) {
F_10 ( L_7 ,
V_19 -> V_35 ) ;
break;
}
} while ( V_25 != V_24 && -- V_26 );
return V_25 == V_24 ? 0 : - 1 ;
}
static bool F_11 ( T_1 * V_36 , int V_37 )
{
if ( F_12 ( V_36 , 0 , V_37 ) )
return false ;
return true ;
}
static T_1 *
F_13 ( struct V_38 * V_39 , struct V_18 * V_19 )
{
int V_2 , V_40 = 0 , V_41 = 0 ;
T_1 * V_5 , * V_42 ;
bool V_6 = ! V_39 -> V_43 || ( V_44 & V_45 ) ;
if ( ( V_5 = F_14 ( V_11 , V_46 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_19 , V_5 , 0 , V_11 ) )
goto V_47;
if ( F_2 ( V_5 , 0 , V_6 ) )
break;
if ( V_2 == 0 && F_11 ( V_5 , V_11 ) ) {
V_39 -> V_48 ++ ;
goto V_49;
}
}
if ( V_2 == 4 )
goto V_49;
if ( V_5 [ 0x7e ] == 0 )
return V_5 ;
V_42 = F_15 ( V_5 , ( V_5 [ 0x7e ] + 1 ) * V_11 , V_46 ) ;
if ( ! V_42 )
goto V_47;
V_5 = V_42 ;
for ( V_40 = 1 ; V_40 <= V_5 [ 0x7e ] ; V_40 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_19 ,
V_5 + ( V_41 + 1 ) * V_11 ,
V_40 , V_11 ) )
goto V_47;
if ( F_2 ( V_5 + ( V_41 + 1 ) * V_11 , V_40 , V_6 ) ) {
V_41 ++ ;
break;
}
}
if ( V_2 == 4 )
F_16 ( V_39 -> V_50 -> V_50 ,
L_8 ,
F_17 ( V_39 ) , V_40 ) ;
}
if ( V_41 != V_5 [ 0x7e ] ) {
V_5 [ V_11 - 1 ] += V_5 [ 0x7e ] - V_41 ;
V_5 [ 0x7e ] = V_41 ;
V_42 = F_15 ( V_5 , ( V_41 + 1 ) * V_11 , V_46 ) ;
if ( ! V_42 )
goto V_47;
V_5 = V_42 ;
}
return V_5 ;
V_49:
if ( V_6 ) {
F_16 ( V_39 -> V_50 -> V_50 , L_9 ,
F_17 ( V_39 ) , V_40 ) ;
}
V_39 -> V_43 ++ ;
V_47:
F_18 ( V_5 ) ;
return NULL ;
}
bool
F_19 ( struct V_18 * V_19 )
{
unsigned char V_47 ;
return ( F_8 ( V_19 , & V_47 , 0 , 1 ) == 0 ) ;
}
struct V_8 * F_20 ( struct V_38 * V_39 ,
struct V_18 * V_19 )
{
struct V_8 * V_8 = NULL ;
if ( F_19 ( V_19 ) )
V_8 = (struct V_8 * ) F_13 ( V_39 , V_19 ) ;
return V_8 ;
}
static bool F_21 ( struct V_8 * V_8 , char * V_51 )
{
char F_21 [ 3 ] ;
F_21 [ 0 ] = ( ( V_8 -> V_52 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_21 [ 1 ] = ( ( ( V_8 -> V_52 [ 0 ] & 0x3 ) << 3 ) |
( ( V_8 -> V_52 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_21 [ 2 ] = ( V_8 -> V_52 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_21 , V_51 , 3 ) ;
}
static T_2 F_22 ( struct V_8 * V_8 )
{
struct V_53 * V_54 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_23 ( V_55 ) ; V_2 ++ ) {
V_54 = & V_55 [ V_2 ] ;
if ( F_21 ( V_8 , V_54 -> V_51 ) &&
( F_24 ( V_8 ) == V_54 -> V_56 ) )
return V_54 -> V_57 ;
}
return 0 ;
}
static void F_25 ( struct V_38 * V_39 ,
T_2 V_57 )
{
struct V_58 * V_59 , * V_60 , * V_61 ;
int V_62 = 0 ;
if ( F_26 ( & V_39 -> V_63 ) )
return;
if ( V_57 & V_64 )
V_62 = 60 ;
if ( V_57 & V_65 )
V_62 = 75 ;
V_61 = F_27 ( & V_39 -> V_63 ,
struct V_58 , V_66 ) ;
F_28 (cur_mode, t, &connector->probed_modes, head) {
V_60 -> type &= ~ V_67 ;
if ( V_60 == V_61 )
continue;
if ( F_29 ( V_60 ) > F_29 ( V_61 ) )
V_61 = V_60 ;
if ( ( F_29 ( V_60 ) == F_29 ( V_61 ) ) &&
F_30 ( V_60 , V_62 ) <
F_30 ( V_61 , V_62 ) ) {
V_61 = V_60 ;
}
}
V_61 -> type |= V_67 ;
}
static bool
F_31 ( const struct V_58 * V_68 )
{
return ( V_68 -> V_69 - V_68 -> V_70 == 160 ) &&
( V_68 -> V_71 - V_68 -> V_70 == 80 ) &&
( V_68 -> V_71 - V_68 -> V_72 == 32 ) &&
( V_68 -> V_73 - V_68 -> V_74 == 3 ) ;
}
struct V_58 * F_32 ( struct V_75 * V_50 ,
int V_76 , int V_77 , int V_78 ,
bool V_79 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_80 ; V_2 ++ ) {
const struct V_58 * V_81 = & V_82 [ V_2 ] ;
if ( V_76 != V_81 -> V_70 )
continue;
if ( V_77 != V_81 -> V_74 )
continue;
if ( V_78 != F_33 ( V_81 ) )
continue;
if ( V_79 != F_31 ( V_81 ) )
continue;
return F_34 ( V_50 , V_81 ) ;
}
return NULL ;
}
static void
F_35 ( T_1 * V_83 , T_3 * V_84 , void * V_85 )
{
int V_2 , V_86 = 0 ;
T_1 V_87 = V_83 [ 0x02 ] ;
T_1 * V_88 = V_83 + V_87 ;
V_86 = ( 127 - V_87 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_86 ; V_2 ++ )
V_84 ( (struct V_89 * ) ( V_88 + 18 * V_2 ) , V_85 ) ;
}
static void
F_36 ( T_1 * V_83 , T_3 * V_84 , void * V_85 )
{
unsigned int V_2 , V_86 = F_37 ( ( int ) V_83 [ 0x02 ] , 6 ) ;
T_1 * V_88 = V_83 + 5 ;
if ( V_83 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_86 ; V_2 ++ )
V_84 ( (struct V_89 * ) ( V_88 + 18 * V_2 ) , V_85 ) ;
}
static void
F_38 ( T_1 * V_1 , T_3 * V_84 , void * V_85 )
{
int V_2 ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
if ( V_8 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_90 ; V_2 ++ )
V_84 ( & ( V_8 -> V_91 [ V_2 ] ) , V_85 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_83 = V_1 + ( V_2 * V_11 ) ;
switch ( * V_83 ) {
case V_92 :
F_35 ( V_83 , V_84 , V_85 ) ;
break;
case V_93 :
F_36 ( V_83 , V_84 , V_85 ) ;
break;
default:
break;
}
}
}
static void
F_39 ( struct V_89 * V_59 , void * V_94 )
{
T_1 * V_95 = ( T_1 * ) V_59 ;
if ( V_95 [ 3 ] == V_96 )
if ( V_95 [ 15 ] & 0x10 )
* ( bool * ) V_94 = true ;
}
static bool
F_40 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 4 ) {
bool V_25 = false ;
F_38 ( ( T_1 * ) V_8 , F_39 , & V_25 ) ;
return V_25 ;
}
return ( ( V_8 -> V_97 & V_98 ) != 0 ) ;
}
static void
F_41 ( struct V_89 * V_59 , void * V_94 )
{
T_1 * V_95 = ( T_1 * ) V_59 ;
if ( V_95 [ 3 ] == V_96 && V_95 [ 10 ] == 0x02 )
* ( T_1 * * ) V_94 = V_95 ;
}
static int
F_42 ( struct V_8 * V_8 )
{
T_1 * V_95 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_95 ) ;
return V_95 ? ( V_95 [ 12 ] * 2 ) : 0 ;
}
static int
F_43 ( struct V_8 * V_8 )
{
T_1 * V_95 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_95 ) ;
return V_95 ? V_95 [ 13 ] : 0 ;
}
static int
F_44 ( struct V_8 * V_8 )
{
T_1 * V_95 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_95 ) ;
return V_95 ? ( V_95 [ 15 ] << 8 ) + V_95 [ 14 ] : 0 ;
}
static int
F_45 ( struct V_8 * V_8 )
{
T_1 * V_95 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_95 ) ;
return V_95 ? V_95 [ 16 ] : 0 ;
}
static int
F_46 ( struct V_8 * V_8 )
{
T_1 * V_95 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_95 ) ;
return V_95 ? V_95 [ 17 ] : 0 ;
}
static int F_47 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 2 ) {
if ( V_8 -> V_13 >= 4 && ( V_8 -> V_99 & V_100 ) )
return V_101 ;
if ( F_42 ( V_8 ) )
return V_102 ;
return V_103 ;
}
return V_104 ;
}
static int
F_48 ( T_1 V_105 , T_1 V_106 )
{
return ( V_105 == 0x00 && V_106 == 0x00 ) ||
( V_105 == 0x01 && V_106 == 0x01 ) ||
( V_105 == 0x20 && V_106 == 0x20 ) ;
}
static struct V_58 *
F_49 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_107 * V_59 , int V_13 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
struct V_58 * V_108 , * V_68 = NULL ;
int V_76 , V_77 ;
int V_109 ;
unsigned V_110 = ( V_59 -> V_111 & V_112 )
>> V_113 ;
unsigned V_114 = ( V_59 -> V_111 & V_115 )
>> V_116 ;
int V_117 = F_47 ( V_8 ) ;
if ( F_48 ( V_59 -> V_76 , V_59 -> V_111 ) )
return NULL ;
V_76 = V_59 -> V_76 * 8 + 248 ;
V_109 = V_114 + 60 ;
if ( V_110 == 0 ) {
if ( V_13 < 3 )
V_77 = V_76 ;
else
V_77 = ( V_76 * 10 ) / 16 ;
} else if ( V_110 == 1 )
V_77 = ( V_76 * 3 ) / 4 ;
else if ( V_110 == 2 )
V_77 = ( V_76 * 4 ) / 5 ;
else
V_77 = ( V_76 * 9 ) / 16 ;
if ( V_109 == 60 &&
( ( V_76 == 1360 && V_77 == 765 ) ||
( V_76 == 1368 && V_77 == 769 ) ) ) {
V_76 = 1366 ;
V_77 = 768 ;
}
F_50 (m, &connector->probed_modes, head)
if ( V_108 -> V_70 == V_76 && V_108 -> V_74 == V_77 &&
F_33 ( V_108 ) == V_109 )
return NULL ;
if ( V_76 == 1366 && V_77 == 768 && V_109 == 60 ) {
V_68 = F_51 ( V_50 , 1366 , 768 , V_109 , 0 , 0 ,
false ) ;
V_68 -> V_70 = 1366 ;
V_68 -> V_72 = V_68 -> V_72 - 1 ;
V_68 -> V_71 = V_68 -> V_71 - 1 ;
return V_68 ;
}
if ( F_40 ( V_8 ) ) {
V_68 = F_32 ( V_50 , V_76 , V_77 , V_109 ,
true ) ;
if ( V_68 )
return V_68 ;
}
V_68 = F_32 ( V_50 , V_76 , V_77 , V_109 , false ) ;
if ( V_68 )
return V_68 ;
switch ( V_117 ) {
case V_104 :
break;
case V_103 :
V_68 = F_52 ( V_50 , V_76 , V_77 , V_109 , 0 , 0 ) ;
break;
case V_102 :
V_68 = F_52 ( V_50 , V_76 , V_77 , V_109 , 0 , 0 ) ;
if ( ! V_68 )
return NULL ;
if ( F_53 ( V_68 ) > F_42 ( V_8 ) ) {
F_54 ( V_50 , V_68 ) ;
V_68 = F_55 ( V_50 , V_76 , V_77 ,
V_109 , 0 , 0 ,
F_44 ( V_8 ) ,
F_43 ( V_8 ) ,
F_45 ( V_8 ) ,
F_46 ( V_8 ) ) ;
}
break;
case V_101 :
V_68 = F_51 ( V_50 , V_76 , V_77 , V_109 , 0 , 0 ,
false ) ;
break;
}
return V_68 ;
}
static void
F_56 ( struct V_58 * V_68 ,
struct V_118 * V_119 )
{
int V_2 ;
static const struct {
int V_120 , V_121 ;
} V_122 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_119 -> V_123 & V_124 ) )
return;
for ( V_2 = 0 ; V_2 < F_23 ( V_122 ) ; V_2 ++ ) {
if ( ( V_68 -> V_70 == V_122 [ V_2 ] . V_120 ) &&
( V_68 -> V_74 == V_122 [ V_2 ] . V_121 / 2 ) ) {
V_68 -> V_74 *= 2 ;
V_68 -> V_73 *= 2 ;
V_68 -> V_125 *= 2 ;
V_68 -> V_126 *= 2 ;
V_68 -> V_126 |= 1 ;
}
}
V_68 -> V_31 |= V_127 ;
}
static struct V_58 * F_57 ( struct V_75 * V_50 ,
struct V_8 * V_8 ,
struct V_89 * V_128 ,
T_2 V_57 )
{
struct V_58 * V_68 ;
struct V_118 * V_119 = & V_128 -> V_94 . V_129 ;
unsigned V_130 = ( V_119 -> V_131 & 0xf0 ) << 4 | V_119 -> V_132 ;
unsigned V_133 = ( V_119 -> V_134 & 0xf0 ) << 4 | V_119 -> V_135 ;
unsigned V_136 = ( V_119 -> V_131 & 0xf ) << 8 | V_119 -> V_137 ;
unsigned V_138 = ( V_119 -> V_134 & 0xf ) << 8 | V_119 -> V_139 ;
unsigned V_140 = ( V_119 -> V_141 & 0xc0 ) << 2 | V_119 -> V_142 ;
unsigned V_143 = ( V_119 -> V_141 & 0x30 ) << 4 | V_119 -> V_144 ;
unsigned V_145 = ( V_119 -> V_141 & 0xc ) >> 2 | V_119 -> V_146 >> 4 ;
unsigned V_147 = ( V_119 -> V_141 & 0x3 ) << 4 | ( V_119 -> V_146 & 0xf ) ;
if ( V_130 < 64 || V_133 < 64 )
return NULL ;
if ( V_119 -> V_123 & V_148 ) {
F_5 ( V_149 L_10 ) ;
return NULL ;
}
if ( ! ( V_119 -> V_123 & V_150 ) ) {
F_5 ( V_149 L_11 ) ;
}
if ( ! V_143 || ! V_147 ) {
F_10 ( L_12
L_13 ) ;
return NULL ;
}
if ( V_57 & V_151 ) {
V_68 = F_51 ( V_50 , V_130 , V_133 , 60 , true , false , false ) ;
if ( ! V_68 )
return NULL ;
goto V_152;
}
V_68 = F_58 ( V_50 ) ;
if ( ! V_68 )
return NULL ;
if ( V_57 & V_153 )
V_128 -> V_154 = F_59 ( 1088 ) ;
V_68 -> clock = F_60 ( V_128 -> V_154 ) * 10 ;
V_68 -> V_70 = V_130 ;
V_68 -> V_72 = V_68 -> V_70 + V_140 ;
V_68 -> V_71 = V_68 -> V_72 + V_143 ;
V_68 -> V_69 = V_68 -> V_70 + V_136 ;
V_68 -> V_74 = V_133 ;
V_68 -> V_73 = V_68 -> V_74 + V_145 ;
V_68 -> V_125 = V_68 -> V_73 + V_147 ;
V_68 -> V_126 = V_68 -> V_74 + V_138 ;
if ( V_68 -> V_71 > V_68 -> V_69 )
V_68 -> V_69 = V_68 -> V_71 + 1 ;
if ( V_68 -> V_125 > V_68 -> V_126 )
V_68 -> V_126 = V_68 -> V_125 + 1 ;
F_56 ( V_68 , V_119 ) ;
if ( V_57 & V_155 ) {
V_119 -> V_123 |= V_156 | V_157 ;
}
V_68 -> V_31 |= ( V_119 -> V_123 & V_156 ) ?
V_158 : V_159 ;
V_68 -> V_31 |= ( V_119 -> V_123 & V_157 ) ?
V_160 : V_161 ;
V_152:
V_68 -> V_162 = V_119 -> V_163 | ( V_119 -> V_164 & 0xf0 ) << 4 ;
V_68 -> V_165 = V_119 -> V_166 | ( V_119 -> V_164 & 0xf ) << 8 ;
if ( V_57 & V_167 ) {
V_68 -> V_162 *= 10 ;
V_68 -> V_165 *= 10 ;
}
if ( V_57 & V_168 ) {
V_68 -> V_162 = V_8 -> V_169 * 10 ;
V_68 -> V_165 = V_8 -> V_170 * 10 ;
}
V_68 -> type = V_171 ;
F_61 ( V_68 ) ;
return V_68 ;
}
static bool
F_62 ( const struct V_58 * V_68 ,
struct V_8 * V_8 , T_1 * V_59 )
{
int V_172 , V_173 , V_174 ;
V_173 = V_59 [ 7 ] ;
if ( V_8 -> V_13 >= 4 )
V_173 += ( ( V_59 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_174 = V_59 [ 8 ] ;
if ( V_8 -> V_13 >= 4 )
V_174 += ( ( V_59 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_172 = F_53 ( V_68 ) ;
return ( V_172 <= V_174 && V_172 >= V_173 ) ;
}
static bool
F_63 ( const struct V_58 * V_68 ,
struct V_8 * V_8 , T_1 * V_59 )
{
int V_175 , V_176 , V_177 ;
V_176 = V_59 [ 5 ] ;
if ( V_8 -> V_13 >= 4 )
V_176 += ( ( V_59 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_177 = V_59 [ 6 ] ;
if ( V_8 -> V_13 >= 4 )
V_177 += ( ( V_59 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_175 = F_33 ( V_68 ) ;
return ( V_175 <= V_177 && V_175 >= V_176 ) ;
}
static T_2
F_64 ( struct V_8 * V_8 , T_1 * V_59 )
{
if ( V_59 [ 9 ] == 0 || V_59 [ 9 ] == 255 )
return 0 ;
if ( V_8 -> V_13 >= 4 && V_59 [ 10 ] == 0x04 )
return ( V_59 [ 9 ] * 10000 ) - ( ( V_59 [ 12 ] >> 2 ) * 250 ) ;
return V_59 [ 9 ] * 10000 + 5001 ;
}
static bool
F_65 ( const struct V_58 * V_68 , struct V_8 * V_8 ,
struct V_89 * V_128 )
{
T_2 V_178 ;
T_1 * V_59 = ( T_1 * ) V_128 ;
if ( ! F_62 ( V_68 , V_8 , V_59 ) )
return false ;
if ( ! F_63 ( V_68 , V_8 , V_59 ) )
return false ;
if ( ( V_178 = F_64 ( V_8 , V_59 ) ) )
if ( V_68 -> clock > V_178 )
return false ;
if ( V_8 -> V_13 >= 4 && V_59 [ 10 ] == 0x04 )
if ( V_59 [ 13 ] && V_68 -> V_70 > 8 * ( V_59 [ 13 ] + ( 256 * ( V_59 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_31 ( V_68 ) && ! F_40 ( V_8 ) )
return false ;
return true ;
}
static bool F_66 ( const struct V_38 * V_39 ,
const struct V_58 * V_68 )
{
struct V_58 * V_108 ;
bool V_179 = false ;
F_50 (m, &connector->probed_modes, head) {
if ( V_68 -> V_70 == V_108 -> V_70 &&
V_68 -> V_74 == V_108 -> V_74 &&
F_33 ( V_68 ) == F_33 ( V_108 ) )
return false ;
if ( V_68 -> V_70 <= V_108 -> V_70 &&
V_68 -> V_74 <= V_108 -> V_74 )
V_179 = true ;
}
return V_179 ;
}
static int
F_67 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_89 * V_128 )
{
int V_2 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < V_80 ; V_2 ++ ) {
if ( F_65 ( V_82 + V_2 , V_8 , V_128 ) &&
F_66 ( V_39 , V_82 + V_2 ) ) {
V_181 = F_34 ( V_50 , & V_82 [ V_2 ] ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
}
return V_180 ;
}
static void F_69 ( struct V_58 * V_68 )
{
if ( V_68 -> V_70 == 1368 && V_68 -> V_74 == 768 ) {
V_68 -> V_70 = 1366 ;
V_68 -> V_72 -- ;
V_68 -> V_71 -- ;
F_61 ( V_68 ) ;
}
}
static int
F_70 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_89 * V_128 )
{
int V_2 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < V_182 ; V_2 ++ ) {
const struct V_183 * V_108 = & V_184 [ V_2 ] ;
V_181 = F_52 ( V_50 , V_108 -> V_120 , V_108 -> V_121 , V_108 -> V_95 , 0 , 0 ) ;
if ( ! V_181 )
return V_180 ;
F_69 ( V_181 ) ;
if ( ! F_65 ( V_181 , V_8 , V_128 ) ||
! F_66 ( V_39 , V_181 ) ) {
F_54 ( V_50 , V_181 ) ;
continue;
}
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
return V_180 ;
}
static int
F_71 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_89 * V_128 )
{
int V_2 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
bool V_79 = F_40 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < V_182 ; V_2 ++ ) {
const struct V_183 * V_108 = & V_184 [ V_2 ] ;
V_181 = F_51 ( V_50 , V_108 -> V_120 , V_108 -> V_121 , V_108 -> V_95 , V_79 , 0 , 0 ) ;
if ( ! V_181 )
return V_180 ;
F_69 ( V_181 ) ;
if ( ! F_65 ( V_181 , V_8 , V_128 ) ||
! F_66 ( V_39 , V_181 ) ) {
F_54 ( V_50 , V_181 ) ;
continue;
}
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
return V_180 ;
}
static void
F_72 ( struct V_89 * V_128 , void * V_185 )
{
struct V_186 * V_85 = V_185 ;
struct V_187 * V_94 = & V_128 -> V_94 . V_188 ;
struct V_189 * V_190 = & V_94 -> V_94 . V_190 ;
if ( V_94 -> type != V_96 )
return;
V_85 -> V_180 += F_67 ( V_85 -> V_39 ,
V_85 -> V_8 ,
V_128 ) ;
if ( ! F_73 ( V_85 -> V_8 , 1 , 1 ) )
return;
switch ( V_190 -> V_31 ) {
case 0x02 :
case 0x00 :
V_85 -> V_180 += F_70 ( V_85 -> V_39 ,
V_85 -> V_8 ,
V_128 ) ;
break;
case 0x04 :
if ( ! F_73 ( V_85 -> V_8 , 1 , 3 ) )
break;
V_85 -> V_180 += F_71 ( V_85 -> V_39 ,
V_85 -> V_8 ,
V_128 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_74 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_186 V_85 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_73 ( V_8 , 1 , 0 ) )
F_38 ( ( T_1 * ) V_8 , F_72 ,
& V_85 ) ;
return V_85 . V_180 ;
}
static int
F_75 ( struct V_38 * V_39 , struct V_89 * V_128 )
{
int V_2 , V_40 , V_108 , V_180 = 0 ;
struct V_58 * V_68 ;
T_1 * V_191 = ( ( T_1 * ) V_128 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_40 = 7 ; V_40 > 0 ; V_40 -- ) {
V_108 = ( V_2 * 8 ) + ( 7 - V_40 ) ;
if ( V_108 >= F_23 ( V_192 ) )
break;
if ( V_191 [ V_2 ] & ( 1 << V_40 ) ) {
V_68 = F_32 ( V_39 -> V_50 ,
V_192 [ V_108 ] . V_120 ,
V_192 [ V_108 ] . V_121 ,
V_192 [ V_108 ] . V_95 ,
V_192 [ V_108 ] . V_79 ) ;
if ( V_68 ) {
F_68 ( V_39 , V_68 ) ;
V_180 ++ ;
}
}
}
}
return V_180 ;
}
static void
F_76 ( struct V_89 * V_128 , void * V_185 )
{
struct V_186 * V_85 = V_185 ;
struct V_187 * V_94 = & V_128 -> V_94 . V_188 ;
if ( V_94 -> type == V_193 )
V_85 -> V_180 += F_75 ( V_85 -> V_39 , V_128 ) ;
}
static int
F_77 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
unsigned long V_194 = V_8 -> V_195 . V_196 |
( V_8 -> V_195 . V_197 << 8 ) |
( ( V_8 -> V_195 . V_198 & 0x80 ) << 9 ) ;
int V_2 , V_180 = 0 ;
struct V_186 V_85 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_199 ; V_2 ++ ) {
if ( V_194 & ( 1 << V_2 ) ) {
struct V_58 * V_181 ;
V_181 = F_34 ( V_50 , & V_200 [ V_2 ] ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
}
if ( F_73 ( V_8 , 1 , 0 ) )
F_38 ( ( T_1 * ) V_8 ,
F_76 , & V_85 ) ;
return V_180 + V_85 . V_180 ;
}
static void
F_78 ( struct V_89 * V_128 , void * V_185 )
{
struct V_186 * V_85 = V_185 ;
struct V_187 * V_94 = & V_128 -> V_94 . V_188 ;
struct V_38 * V_39 = V_85 -> V_39 ;
struct V_8 * V_8 = V_85 -> V_8 ;
if ( V_94 -> type == V_201 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_107 * V_202 ;
struct V_58 * V_181 ;
V_202 = & V_94 -> V_94 . V_203 [ V_2 ] ;
V_181 = F_49 ( V_39 , V_8 , V_202 ,
V_8 -> V_13 ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_85 -> V_180 ++ ;
}
}
}
}
static int
F_79 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_2 , V_180 = 0 ;
struct V_186 V_85 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_204 ; V_2 ++ ) {
struct V_58 * V_181 ;
V_181 = F_49 ( V_39 , V_8 ,
& V_8 -> V_205 [ V_2 ] ,
V_8 -> V_13 ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
if ( F_73 ( V_8 , 1 , 0 ) )
F_38 ( ( T_1 * ) V_8 , F_78 ,
& V_85 ) ;
return V_180 + V_85 . V_180 ;
}
static int F_80 ( struct V_38 * V_39 ,
struct V_89 * V_128 )
{
int V_2 , V_40 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
struct V_206 * V_207 ;
const int V_208 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_209 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_210 ( V_211 ) , V_212 ;
V_207 = & ( V_128 -> V_94 . V_188 . V_94 . V_207 [ V_2 ] ) ;
if ( ! memcmp ( V_207 -> V_213 , V_209 , 3 ) )
continue;
V_212 = ( V_207 -> V_213 [ 0 ] + ( ( V_207 -> V_213 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_207 -> V_213 [ 1 ] & 0x0c ) {
case 0x00 :
V_211 = V_212 * 4 / 3 ;
break;
case 0x04 :
V_211 = V_212 * 16 / 9 ;
break;
case 0x08 :
V_211 = V_212 * 16 / 10 ;
break;
case 0x0c :
V_211 = V_212 * 15 / 9 ;
break;
}
for ( V_40 = 1 ; V_40 < 5 ; V_40 ++ ) {
if ( V_207 -> V_213 [ 2 ] & ( 1 << V_40 ) ) {
V_181 = F_51 ( V_50 , V_211 , V_212 ,
V_208 [ V_40 ] , V_40 == 0 ,
false , false ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
}
}
return V_180 ;
}
static void
F_81 ( struct V_89 * V_128 , void * V_185 )
{
struct V_186 * V_85 = V_185 ;
struct V_187 * V_94 = & V_128 -> V_94 . V_188 ;
if ( V_94 -> type == V_214 )
V_85 -> V_180 += F_80 ( V_85 -> V_39 , V_128 ) ;
}
static int
F_82 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_186 V_85 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_73 ( V_8 , 1 , 2 ) )
F_38 ( ( T_1 * ) V_8 , F_81 , & V_85 ) ;
return V_85 . V_180 ;
}
static void
F_83 ( struct V_89 * V_128 , void * V_185 )
{
struct V_186 * V_85 = V_185 ;
struct V_58 * V_181 ;
if ( V_128 -> V_154 ) {
V_181 = F_57 ( V_85 -> V_39 -> V_50 ,
V_85 -> V_8 , V_128 ,
V_85 -> V_57 ) ;
if ( ! V_181 )
return;
if ( V_85 -> V_215 )
V_181 -> type |= V_67 ;
F_68 ( V_85 -> V_39 , V_181 ) ;
V_85 -> V_180 ++ ;
V_85 -> V_215 = 0 ;
}
}
static int
F_84 ( struct V_38 * V_39 , struct V_8 * V_8 ,
T_2 V_57 )
{
struct V_186 V_85 = {
V_39 ,
V_8 ,
1 ,
V_57 ,
0
} ;
if ( V_85 . V_215 && ! F_73 ( V_8 , 1 , 3 ) )
V_85 . V_215 =
( V_8 -> V_99 & V_216 ) ;
F_38 ( ( T_1 * ) V_8 , F_83 , & V_85 ) ;
return V_85 . V_180 ;
}
T_1 * F_85 ( struct V_8 * V_8 )
{
T_1 * V_217 = NULL ;
int V_2 ;
if ( V_8 == NULL || V_8 -> V_17 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_8 -> V_17 ; V_2 ++ ) {
V_217 = ( T_1 * ) V_8 + V_11 * ( V_2 + 1 ) ;
if ( V_217 [ 0 ] == V_92 )
break;
}
if ( V_2 == V_8 -> V_17 )
return NULL ;
return V_217 ;
}
T_1 F_86 ( struct V_58 * V_218 )
{
struct V_58 * V_219 ;
T_1 V_68 ;
for ( V_68 = 0 ; V_68 < V_220 ; V_68 ++ ) {
V_219 = (struct V_58 * ) & V_221 [ V_68 ] ;
if ( F_87 ( V_218 , V_219 ) )
return V_68 + 1 ;
}
return 0 ;
}
static int
F_88 ( struct V_38 * V_39 , T_1 * V_222 , T_1 V_21 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
T_1 * V_68 , V_219 ;
int V_180 = 0 ;
for ( V_68 = V_222 ; V_68 < V_222 + V_21 ; V_68 ++ ) {
V_219 = ( * V_68 & 127 ) - 1 ;
if ( V_219 < V_220 ) {
struct V_58 * V_181 ;
V_181 = F_34 ( V_50 ,
& V_221 [ V_219 ] ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
}
return V_180 ;
}
static int
F_89 ( const T_1 * V_222 )
{
return V_222 [ 0 ] & 0x1f ;
}
static int
F_90 ( const T_1 * V_222 )
{
return V_222 [ 0 ] >> 5 ;
}
static int
F_91 ( const T_1 * V_223 )
{
return V_223 [ 1 ] ;
}
static int
F_92 ( const T_1 * V_223 , int * V_22 , int * V_224 )
{
* V_22 = 4 ;
* V_224 = V_223 [ 2 ] ;
if ( * V_224 == 0 )
* V_224 = 127 ;
if ( * V_224 < 4 || * V_224 > 127 )
return - V_225 ;
return 0 ;
}
static int
F_93 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_1 * V_223 = F_85 ( V_8 ) ;
T_1 * V_222 , V_226 ;
int V_180 = 0 ;
if ( V_223 && F_91 ( V_223 ) >= 3 ) {
int V_2 , V_22 , V_224 ;
if ( F_92 ( V_223 , & V_22 , & V_224 ) )
return 0 ;
F_94 (cea, i, start, end) {
V_222 = & V_223 [ V_2 ] ;
V_226 = F_89 ( V_222 ) ;
if ( F_90 ( V_222 ) == V_227 )
V_180 += F_88 ( V_39 , V_222 + 1 , V_226 ) ;
}
}
return V_180 ;
}
static void
F_95 ( struct V_38 * V_39 , const T_1 * V_222 )
{
T_1 V_21 = F_89 ( V_222 ) ;
if ( V_21 >= 6 ) {
V_39 -> V_228 [ 5 ] |= ( V_222 [ 6 ] >> 7 ) << 1 ;
V_39 -> V_229 = V_222 [ 6 ] & 1 ;
}
if ( V_21 >= 7 )
V_39 -> V_230 = V_222 [ 7 ] * 5 ;
if ( V_21 >= 8 ) {
V_39 -> V_231 [ 0 ] = V_222 [ 8 ] >> 7 ;
V_39 -> V_231 [ 1 ] = ( V_222 [ 8 ] >> 6 ) & 1 ;
}
if ( V_21 >= 9 )
V_39 -> V_232 [ 0 ] = V_222 [ 9 ] ;
if ( V_21 >= 10 )
V_39 -> V_233 [ 0 ] = V_222 [ 10 ] ;
if ( V_21 >= 11 )
V_39 -> V_232 [ 1 ] = V_222 [ 11 ] ;
if ( V_21 >= 12 )
V_39 -> V_233 [ 1 ] = V_222 [ 12 ] ;
F_10 ( L_14
L_15
L_16
L_17
L_18 ,
V_39 -> V_229 ,
V_39 -> V_230 ,
( int ) V_39 -> V_231 [ 0 ] ,
( int ) V_39 -> V_231 [ 1 ] ,
V_39 -> V_232 [ 0 ] ,
V_39 -> V_232 [ 1 ] ,
V_39 -> V_233 [ 0 ] ,
V_39 -> V_233 [ 1 ] ) ;
}
static void
F_96 ( struct V_89 * V_59 , void * V_94 )
{
if ( V_59 -> V_94 . V_188 . type == V_234 )
* ( T_1 * * ) V_94 = V_59 -> V_94 . V_188 . V_94 . V_235 . V_235 ;
}
static bool F_97 ( const T_1 * V_222 )
{
int V_236 ;
if ( F_90 ( V_222 ) != V_237 )
return false ;
if ( F_89 ( V_222 ) < 5 )
return false ;
V_236 = V_222 [ 1 ] | ( V_222 [ 2 ] << 8 ) | ( V_222 [ 3 ] << 16 ) ;
return V_236 == V_238 ;
}
void F_98 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_4 * V_228 = V_39 -> V_228 ;
T_1 * V_223 ;
T_1 * V_35 ;
T_1 * V_222 ;
int V_239 = 0 ;
int V_240 ;
int V_226 ;
memset ( V_228 , 0 , sizeof( V_39 -> V_228 ) ) ;
V_223 = F_85 ( V_8 ) ;
if ( ! V_223 ) {
F_10 ( L_19 ) ;
return;
}
V_35 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_96 , & V_35 ) ;
for ( V_240 = 0 ; V_35 && V_240 < 13 ; V_240 ++ ) {
if ( V_35 [ V_240 ] == 0x0a )
break;
V_228 [ 20 + V_240 ] = V_35 [ V_240 ] ;
}
V_228 [ 4 ] = ( V_223 [ 1 ] << 5 ) | V_240 ;
F_10 ( L_20 , V_228 + 20 ) ;
V_228 [ 0 ] = 2 << 3 ;
V_228 [ 16 ] = V_8 -> V_52 [ 0 ] ;
V_228 [ 17 ] = V_8 -> V_52 [ 1 ] ;
V_228 [ 18 ] = V_8 -> V_241 [ 0 ] ;
V_228 [ 19 ] = V_8 -> V_241 [ 1 ] ;
if ( F_91 ( V_223 ) >= 3 ) {
int V_2 , V_22 , V_224 ;
if ( F_92 ( V_223 , & V_22 , & V_224 ) ) {
V_22 = 0 ;
V_224 = 0 ;
}
F_94 (cea, i, start, end) {
V_222 = & V_223 [ V_2 ] ;
V_226 = F_89 ( V_222 ) ;
switch ( F_90 ( V_222 ) ) {
case V_242 :
V_239 = V_226 / 3 ;
if ( V_226 >= 1 )
memcpy ( V_228 + 20 + V_240 , & V_222 [ 1 ] , V_226 ) ;
break;
case V_243 :
if ( V_226 >= 1 )
V_228 [ 7 ] = V_222 [ 1 ] ;
break;
case V_237 :
if ( F_97 ( V_222 ) )
F_95 ( V_39 , V_222 ) ;
break;
default:
break;
}
}
}
V_228 [ 5 ] |= V_239 << 4 ;
V_228 [ 2 ] = ( 20 + V_240 + V_239 * 3 + 3 ) / 4 ;
F_10 ( L_21 , ( int ) V_228 [ 2 ] , V_239 ) ;
}
int F_99 ( struct V_38 * V_39 ,
struct V_58 * V_68 )
{
int V_2 = ! ! ( V_68 -> V_31 & V_127 ) ;
int V_105 , V_244 ;
if ( ! V_39 -> V_231 [ 0 ] )
return 0 ;
if ( ! V_39 -> V_231 [ 1 ] )
V_2 = 0 ;
V_105 = V_39 -> V_233 [ V_2 ] ;
V_244 = V_39 -> V_232 [ V_2 ] ;
if ( V_105 == 255 || V_244 == 255 )
return 0 ;
if ( V_105 )
V_105 = F_37 ( 2 * ( V_105 - 1 ) , 500 ) ;
if ( V_244 )
V_244 = F_37 ( 2 * ( V_244 - 1 ) , 500 ) ;
return F_100 ( V_244 - V_105 , 0 ) ;
}
struct V_38 * F_101 ( struct V_245 * V_246 ,
struct V_58 * V_68 )
{
struct V_38 * V_39 ;
struct V_75 * V_50 = V_246 -> V_50 ;
F_50 (connector, &dev->mode_config.connector_list, head)
if ( V_39 -> V_246 == V_246 && V_39 -> V_228 [ 0 ] )
return V_39 ;
return NULL ;
}
bool F_102 ( struct V_8 * V_8 )
{
T_1 * V_217 ;
int V_2 ;
int V_247 , V_248 ;
V_217 = F_85 ( V_8 ) ;
if ( ! V_217 )
return false ;
if ( F_92 ( V_217 , & V_247 , & V_248 ) )
return false ;
F_94 (edid_ext, i, start_offset, end_offset) {
if ( F_97 ( & V_217 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_103 ( struct V_8 * V_8 )
{
T_1 * V_217 ;
int V_2 , V_40 ;
bool V_249 = false ;
int V_247 , V_248 ;
V_217 = F_85 ( V_8 ) ;
if ( ! V_217 )
goto V_224;
V_249 = ( ( V_217 [ 3 ] & V_250 ) != 0 ) ;
if ( V_249 ) {
F_10 ( L_22 ) ;
goto V_224;
}
if ( F_92 ( V_217 , & V_247 , & V_248 ) )
goto V_224;
F_94 (edid_ext, i, start_offset, end_offset) {
if ( F_90 ( & V_217 [ V_2 ] ) == V_242 ) {
V_249 = true ;
for ( V_40 = 1 ; V_40 < F_89 ( & V_217 [ V_2 ] ) + 1 ; V_40 += 3 )
F_10 ( L_23 ,
( V_217 [ V_2 + V_40 ] >> 3 ) & 0xf ) ;
goto V_224;
}
}
V_224:
return V_249 ;
}
static void F_104 ( struct V_8 * V_8 ,
struct V_251 * V_252 )
{
T_1 * V_217 ;
V_252 -> V_162 = V_8 -> V_169 * 10 ;
V_252 -> V_165 = V_8 -> V_170 * 10 ;
V_252 -> V_253 = 0 ;
V_252 -> V_254 = 0 ;
if ( V_8 -> V_13 < 3 )
return;
if ( ! ( V_8 -> V_97 & V_98 ) )
return;
V_217 = F_85 ( V_8 ) ;
if ( V_217 ) {
V_252 -> V_255 = V_217 [ 1 ] ;
V_252 -> V_254 = V_256 ;
if ( V_217 [ 3 ] & V_257 )
V_252 -> V_254 |= V_258 ;
if ( V_217 [ 3 ] & V_259 )
V_252 -> V_254 |= V_260 ;
}
if ( V_8 -> V_13 < 4 )
return;
switch ( V_8 -> V_97 & V_261 ) {
case V_262 :
V_252 -> V_253 = 6 ;
break;
case V_263 :
V_252 -> V_253 = 8 ;
break;
case V_264 :
V_252 -> V_253 = 10 ;
break;
case V_265 :
V_252 -> V_253 = 12 ;
break;
case V_266 :
V_252 -> V_253 = 14 ;
break;
case V_267 :
V_252 -> V_253 = 16 ;
break;
case V_268 :
default:
V_252 -> V_253 = 0 ;
break;
}
V_252 -> V_254 |= V_256 ;
if ( V_8 -> V_99 & V_269 )
V_252 -> V_254 |= V_258 ;
if ( V_8 -> V_99 & V_270 )
V_252 -> V_254 |= V_260 ;
}
int F_105 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_271 = 0 ;
T_2 V_57 ;
if ( V_8 == NULL ) {
return 0 ;
}
if ( ! F_7 ( V_8 ) ) {
F_16 ( V_39 -> V_50 -> V_50 , L_24 ,
F_17 ( V_39 ) ) ;
return 0 ;
}
V_57 = F_22 ( V_8 ) ;
V_271 += F_84 ( V_39 , V_8 , V_57 ) ;
V_271 += F_82 ( V_39 , V_8 ) ;
V_271 += F_79 ( V_39 , V_8 ) ;
V_271 += F_77 ( V_39 , V_8 ) ;
V_271 += F_74 ( V_39 , V_8 ) ;
V_271 += F_93 ( V_39 , V_8 ) ;
if ( V_57 & ( V_64 | V_65 ) )
F_25 ( V_39 , V_57 ) ;
F_104 ( V_8 , & V_39 -> V_272 ) ;
return V_271 ;
}
int F_106 ( struct V_38 * V_39 ,
int V_70 , int V_74 )
{
int V_2 , V_273 , V_271 = 0 ;
struct V_58 * V_68 ;
struct V_75 * V_50 = V_39 -> V_50 ;
V_273 = sizeof( V_82 ) / sizeof( struct V_58 ) ;
if ( V_70 < 0 )
V_70 = 0 ;
if ( V_74 < 0 )
V_74 = 0 ;
for ( V_2 = 0 ; V_2 < V_273 ; V_2 ++ ) {
const struct V_58 * V_81 = & V_82 [ V_2 ] ;
if ( V_70 && V_74 ) {
if ( V_81 -> V_70 > V_70 ||
V_81 -> V_74 > V_74 )
continue;
}
if ( F_33 ( V_81 ) > 61 )
continue;
V_68 = F_34 ( V_50 , V_81 ) ;
if ( V_68 ) {
F_68 ( V_39 , V_68 ) ;
V_271 ++ ;
}
}
return V_271 ;
}
T_4 F_107 ( const struct V_58 * V_68 )
{
T_4 V_2 ;
for ( V_2 = 0 ; V_2 < V_220 ; V_2 ++ )
if ( F_87 ( V_68 , & V_221 [ V_2 ] ) )
return V_2 + 1 ;
return 0 ;
}
