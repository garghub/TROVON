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
if ( F_3 ( ! V_1 ) )
return false ;
if ( V_9 > 8 || V_9 < 0 )
V_9 = 6 ;
if ( V_5 == 0 ) {
int V_3 = F_1 ( V_1 ) ;
if ( V_3 == 8 ) ;
else if ( V_3 >= V_9 ) {
F_4 ( L_1 ) ;
memcpy ( V_1 , V_4 , sizeof( V_4 ) ) ;
} else {
goto V_10;
}
}
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ )
V_7 += V_1 [ V_2 ] ;
if ( V_7 ) {
if ( V_6 ) {
F_5 ( L_2 , V_7 ) ;
}
if ( V_1 [ 0 ] != 0x02 )
goto V_10;
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_8 -> V_12 != 1 ) {
F_5 ( L_3 , V_8 -> V_12 ) ;
goto V_10;
}
if ( V_8 -> V_13 > 4 )
F_4 ( L_4 ) ;
break;
default:
break;
}
return true ;
V_10:
if ( V_6 ) {
F_6 ( V_14 L_5 ) ;
F_7 ( V_14 , L_6 , V_15 , 16 , 1 ,
V_1 , V_11 , false ) ;
}
return false ;
}
bool F_8 ( struct V_8 * V_8 )
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
F_9 ( struct V_18 * V_19 , unsigned char * V_20 ,
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
V_25 = F_10 ( V_19 , & V_28 [ 3 - V_24 ] , V_24 ) ;
if ( V_25 == - V_34 ) {
F_11 ( L_7 ,
V_19 -> V_35 ) ;
break;
}
} while ( V_25 != V_24 && -- V_26 );
return V_25 == V_24 ? 0 : - 1 ;
}
static bool F_12 ( T_1 * V_36 , int V_37 )
{
if ( F_13 ( V_36 , 0 , V_37 ) )
return false ;
return true ;
}
static T_1 *
F_14 ( struct V_38 * V_39 , struct V_18 * V_19 )
{
int V_2 , V_40 = 0 , V_41 = 0 ;
T_1 * V_5 , * V_42 ;
bool V_6 = ! V_39 -> V_43 || ( V_44 & V_45 ) ;
if ( ( V_5 = F_15 ( V_11 , V_46 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_9 ( V_19 , V_5 , 0 , V_11 ) )
goto V_47;
if ( F_2 ( V_5 , 0 , V_6 ) )
break;
if ( V_2 == 0 && F_12 ( V_5 , V_11 ) ) {
V_39 -> V_48 ++ ;
goto V_49;
}
}
if ( V_2 == 4 )
goto V_49;
if ( V_5 [ 0x7e ] == 0 )
return V_5 ;
V_42 = F_16 ( V_5 , ( V_5 [ 0x7e ] + 1 ) * V_11 , V_46 ) ;
if ( ! V_42 )
goto V_47;
V_5 = V_42 ;
for ( V_40 = 1 ; V_40 <= V_5 [ 0x7e ] ; V_40 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_9 ( V_19 ,
V_5 + ( V_41 + 1 ) * V_11 ,
V_40 , V_11 ) )
goto V_47;
if ( F_2 ( V_5 + ( V_41 + 1 ) * V_11 , V_40 , V_6 ) ) {
V_41 ++ ;
break;
}
}
if ( V_2 == 4 && V_6 ) {
F_17 ( V_39 -> V_50 -> V_50 ,
L_8 ,
F_18 ( V_39 ) , V_40 ) ;
V_39 -> V_43 ++ ;
}
}
if ( V_41 != V_5 [ 0x7e ] ) {
V_5 [ V_11 - 1 ] += V_5 [ 0x7e ] - V_41 ;
V_5 [ 0x7e ] = V_41 ;
V_42 = F_16 ( V_5 , ( V_41 + 1 ) * V_11 , V_46 ) ;
if ( ! V_42 )
goto V_47;
V_5 = V_42 ;
}
return V_5 ;
V_49:
if ( V_6 ) {
F_17 ( V_39 -> V_50 -> V_50 , L_9 ,
F_18 ( V_39 ) , V_40 ) ;
}
V_39 -> V_43 ++ ;
V_47:
F_19 ( V_5 ) ;
return NULL ;
}
bool
F_20 ( struct V_18 * V_19 )
{
unsigned char V_47 ;
return ( F_9 ( V_19 , & V_47 , 0 , 1 ) == 0 ) ;
}
struct V_8 * F_21 ( struct V_38 * V_39 ,
struct V_18 * V_19 )
{
struct V_8 * V_8 = NULL ;
if ( F_20 ( V_19 ) )
V_8 = (struct V_8 * ) F_14 ( V_39 , V_19 ) ;
return V_8 ;
}
static bool F_22 ( struct V_8 * V_8 , char * V_51 )
{
char F_22 [ 3 ] ;
F_22 [ 0 ] = ( ( V_8 -> V_52 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_22 [ 1 ] = ( ( ( V_8 -> V_52 [ 0 ] & 0x3 ) << 3 ) |
( ( V_8 -> V_52 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_22 [ 2 ] = ( V_8 -> V_52 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_22 , V_51 , 3 ) ;
}
static T_2 F_23 ( struct V_8 * V_8 )
{
struct V_53 * V_54 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_24 ( V_55 ) ; V_2 ++ ) {
V_54 = & V_55 [ V_2 ] ;
if ( F_22 ( V_8 , V_54 -> V_51 ) &&
( F_25 ( V_8 ) == V_54 -> V_56 ) )
return V_54 -> V_57 ;
}
return 0 ;
}
static void F_26 ( struct V_38 * V_39 ,
T_2 V_57 )
{
struct V_58 * V_59 , * V_60 , * V_61 ;
int V_62 = 0 ;
if ( F_27 ( & V_39 -> V_63 ) )
return;
if ( V_57 & V_64 )
V_62 = 60 ;
if ( V_57 & V_65 )
V_62 = 75 ;
V_61 = F_28 ( & V_39 -> V_63 ,
struct V_58 , V_66 ) ;
F_29 (cur_mode, t, &connector->probed_modes, head) {
V_60 -> type &= ~ V_67 ;
if ( V_60 == V_61 )
continue;
if ( F_30 ( V_60 ) > F_30 ( V_61 ) )
V_61 = V_60 ;
if ( ( F_30 ( V_60 ) == F_30 ( V_61 ) ) &&
F_31 ( V_60 , V_62 ) <
F_31 ( V_61 , V_62 ) ) {
V_61 = V_60 ;
}
}
V_61 -> type |= V_67 ;
}
static bool
F_32 ( const struct V_58 * V_68 )
{
return ( V_68 -> V_69 - V_68 -> V_70 == 160 ) &&
( V_68 -> V_71 - V_68 -> V_70 == 80 ) &&
( V_68 -> V_71 - V_68 -> V_72 == 32 ) &&
( V_68 -> V_73 - V_68 -> V_74 == 3 ) ;
}
struct V_58 * F_33 ( struct V_75 * V_50 ,
int V_76 , int V_77 , int V_78 ,
bool V_79 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_24 ( V_80 ) ; V_2 ++ ) {
const struct V_58 * V_81 = & V_80 [ V_2 ] ;
if ( V_76 != V_81 -> V_70 )
continue;
if ( V_77 != V_81 -> V_74 )
continue;
if ( V_78 != F_34 ( V_81 ) )
continue;
if ( V_79 != F_32 ( V_81 ) )
continue;
return F_35 ( V_50 , V_81 ) ;
}
return NULL ;
}
static void
F_36 ( T_1 * V_82 , T_3 * V_83 , void * V_84 )
{
int V_2 , V_85 = 0 ;
T_1 V_86 = V_82 [ 0x02 ] ;
T_1 * V_87 = V_82 + V_86 ;
V_85 = ( 127 - V_86 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_85 ; V_2 ++ )
V_83 ( (struct V_88 * ) ( V_87 + 18 * V_2 ) , V_84 ) ;
}
static void
F_37 ( T_1 * V_82 , T_3 * V_83 , void * V_84 )
{
unsigned int V_2 , V_85 = F_38 ( ( int ) V_82 [ 0x02 ] , 6 ) ;
T_1 * V_87 = V_82 + 5 ;
if ( V_82 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_85 ; V_2 ++ )
V_83 ( (struct V_88 * ) ( V_87 + 18 * V_2 ) , V_84 ) ;
}
static void
F_39 ( T_1 * V_1 , T_3 * V_83 , void * V_84 )
{
int V_2 ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
if ( V_8 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_89 ; V_2 ++ )
V_83 ( & ( V_8 -> V_90 [ V_2 ] ) , V_84 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_82 = V_1 + ( V_2 * V_11 ) ;
switch ( * V_82 ) {
case V_91 :
F_36 ( V_82 , V_83 , V_84 ) ;
break;
case V_92 :
F_37 ( V_82 , V_83 , V_84 ) ;
break;
default:
break;
}
}
}
static void
F_40 ( struct V_88 * V_59 , void * V_93 )
{
T_1 * V_94 = ( T_1 * ) V_59 ;
if ( V_94 [ 3 ] == V_95 )
if ( V_94 [ 15 ] & 0x10 )
* ( bool * ) V_93 = true ;
}
static bool
F_41 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 4 ) {
bool V_25 = false ;
F_39 ( ( T_1 * ) V_8 , F_40 , & V_25 ) ;
return V_25 ;
}
return ( ( V_8 -> V_96 & V_97 ) != 0 ) ;
}
static void
F_42 ( struct V_88 * V_59 , void * V_93 )
{
T_1 * V_94 = ( T_1 * ) V_59 ;
if ( V_94 [ 3 ] == V_95 && V_94 [ 10 ] == 0x02 )
* ( T_1 * * ) V_93 = V_94 ;
}
static int
F_43 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_39 ( ( T_1 * ) V_8 , F_42 , & V_94 ) ;
return V_94 ? ( V_94 [ 12 ] * 2 ) : 0 ;
}
static int
F_44 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_39 ( ( T_1 * ) V_8 , F_42 , & V_94 ) ;
return V_94 ? V_94 [ 13 ] : 0 ;
}
static int
F_45 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_39 ( ( T_1 * ) V_8 , F_42 , & V_94 ) ;
return V_94 ? ( V_94 [ 15 ] << 8 ) + V_94 [ 14 ] : 0 ;
}
static int
F_46 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_39 ( ( T_1 * ) V_8 , F_42 , & V_94 ) ;
return V_94 ? V_94 [ 16 ] : 0 ;
}
static int
F_47 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_39 ( ( T_1 * ) V_8 , F_42 , & V_94 ) ;
return V_94 ? V_94 [ 17 ] : 0 ;
}
static int F_48 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 2 ) {
if ( V_8 -> V_13 >= 4 && ( V_8 -> V_98 & V_99 ) )
return V_100 ;
if ( F_43 ( V_8 ) )
return V_101 ;
return V_102 ;
}
return V_103 ;
}
static int
F_49 ( T_1 V_104 , T_1 V_105 )
{
return ( V_104 == 0x00 && V_105 == 0x00 ) ||
( V_104 == 0x01 && V_105 == 0x01 ) ||
( V_104 == 0x20 && V_105 == 0x20 ) ;
}
static struct V_58 *
F_50 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_106 * V_59 , int V_13 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
struct V_58 * V_107 , * V_68 = NULL ;
int V_76 , V_77 ;
int V_108 ;
unsigned V_109 = ( V_59 -> V_110 & V_111 )
>> V_112 ;
unsigned V_113 = ( V_59 -> V_110 & V_114 )
>> V_115 ;
int V_116 = F_48 ( V_8 ) ;
if ( F_49 ( V_59 -> V_76 , V_59 -> V_110 ) )
return NULL ;
V_76 = V_59 -> V_76 * 8 + 248 ;
V_108 = V_113 + 60 ;
if ( V_109 == 0 ) {
if ( V_13 < 3 )
V_77 = V_76 ;
else
V_77 = ( V_76 * 10 ) / 16 ;
} else if ( V_109 == 1 )
V_77 = ( V_76 * 3 ) / 4 ;
else if ( V_109 == 2 )
V_77 = ( V_76 * 4 ) / 5 ;
else
V_77 = ( V_76 * 9 ) / 16 ;
if ( V_108 == 60 &&
( ( V_76 == 1360 && V_77 == 765 ) ||
( V_76 == 1368 && V_77 == 769 ) ) ) {
V_76 = 1366 ;
V_77 = 768 ;
}
F_51 (m, &connector->probed_modes, head)
if ( V_107 -> V_70 == V_76 && V_107 -> V_74 == V_77 &&
F_34 ( V_107 ) == V_108 )
return NULL ;
if ( V_76 == 1366 && V_77 == 768 && V_108 == 60 ) {
V_68 = F_52 ( V_50 , 1366 , 768 , V_108 , 0 , 0 ,
false ) ;
V_68 -> V_70 = 1366 ;
V_68 -> V_72 = V_68 -> V_72 - 1 ;
V_68 -> V_71 = V_68 -> V_71 - 1 ;
return V_68 ;
}
if ( F_41 ( V_8 ) ) {
V_68 = F_33 ( V_50 , V_76 , V_77 , V_108 ,
true ) ;
if ( V_68 )
return V_68 ;
}
V_68 = F_33 ( V_50 , V_76 , V_77 , V_108 , false ) ;
if ( V_68 )
return V_68 ;
switch ( V_116 ) {
case V_103 :
break;
case V_102 :
V_68 = F_53 ( V_50 , V_76 , V_77 , V_108 , 0 , 0 ) ;
break;
case V_101 :
V_68 = F_53 ( V_50 , V_76 , V_77 , V_108 , 0 , 0 ) ;
if ( ! V_68 )
return NULL ;
if ( F_54 ( V_68 ) > F_43 ( V_8 ) ) {
F_55 ( V_50 , V_68 ) ;
V_68 = F_56 ( V_50 , V_76 , V_77 ,
V_108 , 0 , 0 ,
F_45 ( V_8 ) ,
F_44 ( V_8 ) ,
F_46 ( V_8 ) ,
F_47 ( V_8 ) ) ;
}
break;
case V_100 :
V_68 = F_52 ( V_50 , V_76 , V_77 , V_108 , 0 , 0 ,
false ) ;
break;
}
return V_68 ;
}
static void
F_57 ( struct V_58 * V_68 ,
struct V_117 * V_118 )
{
int V_2 ;
static const struct {
int V_119 , V_120 ;
} V_121 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_118 -> V_122 & V_123 ) )
return;
for ( V_2 = 0 ; V_2 < F_24 ( V_121 ) ; V_2 ++ ) {
if ( ( V_68 -> V_70 == V_121 [ V_2 ] . V_119 ) &&
( V_68 -> V_74 == V_121 [ V_2 ] . V_120 / 2 ) ) {
V_68 -> V_74 *= 2 ;
V_68 -> V_73 *= 2 ;
V_68 -> V_124 *= 2 ;
V_68 -> V_125 *= 2 ;
V_68 -> V_125 |= 1 ;
}
}
V_68 -> V_31 |= V_126 ;
}
static struct V_58 * F_58 ( struct V_75 * V_50 ,
struct V_8 * V_8 ,
struct V_88 * V_127 ,
T_2 V_57 )
{
struct V_58 * V_68 ;
struct V_117 * V_118 = & V_127 -> V_93 . V_128 ;
unsigned V_129 = ( V_118 -> V_130 & 0xf0 ) << 4 | V_118 -> V_131 ;
unsigned V_132 = ( V_118 -> V_133 & 0xf0 ) << 4 | V_118 -> V_134 ;
unsigned V_135 = ( V_118 -> V_130 & 0xf ) << 8 | V_118 -> V_136 ;
unsigned V_137 = ( V_118 -> V_133 & 0xf ) << 8 | V_118 -> V_138 ;
unsigned V_139 = ( V_118 -> V_140 & 0xc0 ) << 2 | V_118 -> V_141 ;
unsigned V_142 = ( V_118 -> V_140 & 0x30 ) << 4 | V_118 -> V_143 ;
unsigned V_144 = ( V_118 -> V_140 & 0xc ) << 2 | V_118 -> V_145 >> 4 ;
unsigned V_146 = ( V_118 -> V_140 & 0x3 ) << 4 | ( V_118 -> V_145 & 0xf ) ;
if ( V_129 < 64 || V_132 < 64 )
return NULL ;
if ( V_118 -> V_122 & V_147 ) {
F_11 ( L_10 ) ;
return NULL ;
}
if ( ! ( V_118 -> V_122 & V_148 ) ) {
F_11 ( L_11 ) ;
}
if ( ! V_142 || ! V_146 ) {
F_11 ( L_12
L_13 ) ;
return NULL ;
}
if ( V_57 & V_149 ) {
V_68 = F_52 ( V_50 , V_129 , V_132 , 60 , true , false , false ) ;
if ( ! V_68 )
return NULL ;
goto V_150;
}
V_68 = F_59 ( V_50 ) ;
if ( ! V_68 )
return NULL ;
if ( V_57 & V_151 )
V_127 -> V_152 = F_60 ( 1088 ) ;
V_68 -> clock = F_61 ( V_127 -> V_152 ) * 10 ;
V_68 -> V_70 = V_129 ;
V_68 -> V_72 = V_68 -> V_70 + V_139 ;
V_68 -> V_71 = V_68 -> V_72 + V_142 ;
V_68 -> V_69 = V_68 -> V_70 + V_135 ;
V_68 -> V_74 = V_132 ;
V_68 -> V_73 = V_68 -> V_74 + V_144 ;
V_68 -> V_124 = V_68 -> V_73 + V_146 ;
V_68 -> V_125 = V_68 -> V_74 + V_137 ;
if ( V_68 -> V_71 > V_68 -> V_69 )
V_68 -> V_69 = V_68 -> V_71 + 1 ;
if ( V_68 -> V_124 > V_68 -> V_125 )
V_68 -> V_125 = V_68 -> V_124 + 1 ;
F_57 ( V_68 , V_118 ) ;
if ( V_57 & V_153 ) {
V_118 -> V_122 |= V_154 | V_155 ;
}
V_68 -> V_31 |= ( V_118 -> V_122 & V_154 ) ?
V_156 : V_157 ;
V_68 -> V_31 |= ( V_118 -> V_122 & V_155 ) ?
V_158 : V_159 ;
V_150:
V_68 -> V_160 = V_118 -> V_161 | ( V_118 -> V_162 & 0xf0 ) << 4 ;
V_68 -> V_163 = V_118 -> V_164 | ( V_118 -> V_162 & 0xf ) << 8 ;
if ( V_57 & V_165 ) {
V_68 -> V_160 *= 10 ;
V_68 -> V_163 *= 10 ;
}
if ( V_57 & V_166 ) {
V_68 -> V_160 = V_8 -> V_167 * 10 ;
V_68 -> V_163 = V_8 -> V_168 * 10 ;
}
V_68 -> type = V_169 ;
V_68 -> V_170 = F_34 ( V_68 ) ;
F_62 ( V_68 ) ;
return V_68 ;
}
static bool
F_63 ( const struct V_58 * V_68 ,
struct V_8 * V_8 , T_1 * V_59 )
{
int V_171 , V_172 , V_173 ;
V_172 = V_59 [ 7 ] ;
if ( V_8 -> V_13 >= 4 )
V_172 += ( ( V_59 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_173 = V_59 [ 8 ] ;
if ( V_8 -> V_13 >= 4 )
V_173 += ( ( V_59 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_171 = F_54 ( V_68 ) ;
return ( V_171 <= V_173 && V_171 >= V_172 ) ;
}
static bool
F_64 ( const struct V_58 * V_68 ,
struct V_8 * V_8 , T_1 * V_59 )
{
int V_174 , V_175 , V_176 ;
V_175 = V_59 [ 5 ] ;
if ( V_8 -> V_13 >= 4 )
V_175 += ( ( V_59 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_176 = V_59 [ 6 ] ;
if ( V_8 -> V_13 >= 4 )
V_176 += ( ( V_59 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_174 = F_34 ( V_68 ) ;
return ( V_174 <= V_176 && V_174 >= V_175 ) ;
}
static T_2
F_65 ( struct V_8 * V_8 , T_1 * V_59 )
{
if ( V_59 [ 9 ] == 0 || V_59 [ 9 ] == 255 )
return 0 ;
if ( V_8 -> V_13 >= 4 && V_59 [ 10 ] == 0x04 )
return ( V_59 [ 9 ] * 10000 ) - ( ( V_59 [ 12 ] >> 2 ) * 250 ) ;
return V_59 [ 9 ] * 10000 + 5001 ;
}
static bool
F_66 ( const struct V_58 * V_68 , struct V_8 * V_8 ,
struct V_88 * V_127 )
{
T_2 V_177 ;
T_1 * V_59 = ( T_1 * ) V_127 ;
if ( ! F_63 ( V_68 , V_8 , V_59 ) )
return false ;
if ( ! F_64 ( V_68 , V_8 , V_59 ) )
return false ;
if ( ( V_177 = F_65 ( V_8 , V_59 ) ) )
if ( V_68 -> clock > V_177 )
return false ;
if ( V_8 -> V_13 >= 4 && V_59 [ 10 ] == 0x04 )
if ( V_59 [ 13 ] && V_68 -> V_70 > 8 * ( V_59 [ 13 ] + ( 256 * ( V_59 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_32 ( V_68 ) && ! F_41 ( V_8 ) )
return false ;
return true ;
}
static bool F_67 ( const struct V_38 * V_39 ,
const struct V_58 * V_68 )
{
struct V_58 * V_107 ;
bool V_178 = false ;
F_51 (m, &connector->probed_modes, head) {
if ( V_68 -> V_70 == V_107 -> V_70 &&
V_68 -> V_74 == V_107 -> V_74 &&
F_34 ( V_68 ) == F_34 ( V_107 ) )
return false ;
if ( V_68 -> V_70 <= V_107 -> V_70 &&
V_68 -> V_74 <= V_107 -> V_74 )
V_178 = true ;
}
return V_178 ;
}
static int
F_68 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_88 * V_127 )
{
int V_2 , V_179 = 0 ;
struct V_58 * V_180 ;
struct V_75 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < F_24 ( V_80 ) ; V_2 ++ ) {
if ( F_66 ( V_80 + V_2 , V_8 , V_127 ) &&
F_67 ( V_39 , V_80 + V_2 ) ) {
V_180 = F_35 ( V_50 , & V_80 [ V_2 ] ) ;
if ( V_180 ) {
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
}
}
return V_179 ;
}
static void F_70 ( struct V_58 * V_68 )
{
if ( V_68 -> V_70 == 1368 && V_68 -> V_74 == 768 ) {
V_68 -> V_70 = 1366 ;
V_68 -> V_72 -- ;
V_68 -> V_71 -- ;
F_62 ( V_68 ) ;
}
}
static int
F_71 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_88 * V_127 )
{
int V_2 , V_179 = 0 ;
struct V_58 * V_180 ;
struct V_75 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < F_24 ( V_181 ) ; V_2 ++ ) {
const struct V_182 * V_107 = & V_181 [ V_2 ] ;
V_180 = F_53 ( V_50 , V_107 -> V_119 , V_107 -> V_120 , V_107 -> V_94 , 0 , 0 ) ;
if ( ! V_180 )
return V_179 ;
F_70 ( V_180 ) ;
if ( ! F_66 ( V_180 , V_8 , V_127 ) ||
! F_67 ( V_39 , V_180 ) ) {
F_55 ( V_50 , V_180 ) ;
continue;
}
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
return V_179 ;
}
static int
F_72 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_88 * V_127 )
{
int V_2 , V_179 = 0 ;
struct V_58 * V_180 ;
struct V_75 * V_50 = V_39 -> V_50 ;
bool V_79 = F_41 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < F_24 ( V_181 ) ; V_2 ++ ) {
const struct V_182 * V_107 = & V_181 [ V_2 ] ;
V_180 = F_52 ( V_50 , V_107 -> V_119 , V_107 -> V_120 , V_107 -> V_94 , V_79 , 0 , 0 ) ;
if ( ! V_180 )
return V_179 ;
F_70 ( V_180 ) ;
if ( ! F_66 ( V_180 , V_8 , V_127 ) ||
! F_67 ( V_39 , V_180 ) ) {
F_55 ( V_50 , V_180 ) ;
continue;
}
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
return V_179 ;
}
static void
F_73 ( struct V_88 * V_127 , void * V_183 )
{
struct V_184 * V_84 = V_183 ;
struct V_185 * V_93 = & V_127 -> V_93 . V_186 ;
struct V_187 * V_188 = & V_93 -> V_93 . V_188 ;
if ( V_93 -> type != V_95 )
return;
V_84 -> V_179 += F_68 ( V_84 -> V_39 ,
V_84 -> V_8 ,
V_127 ) ;
if ( ! F_74 ( V_84 -> V_8 , 1 , 1 ) )
return;
switch ( V_188 -> V_31 ) {
case 0x02 :
case 0x00 :
V_84 -> V_179 += F_71 ( V_84 -> V_39 ,
V_84 -> V_8 ,
V_127 ) ;
break;
case 0x04 :
if ( ! F_74 ( V_84 -> V_8 , 1 , 3 ) )
break;
V_84 -> V_179 += F_72 ( V_84 -> V_39 ,
V_84 -> V_8 ,
V_127 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_75 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_184 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_74 ( V_8 , 1 , 0 ) )
F_39 ( ( T_1 * ) V_8 , F_73 ,
& V_84 ) ;
return V_84 . V_179 ;
}
static int
F_76 ( struct V_38 * V_39 , struct V_88 * V_127 )
{
int V_2 , V_40 , V_107 , V_179 = 0 ;
struct V_58 * V_68 ;
T_1 * V_189 = ( ( T_1 * ) V_127 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_40 = 7 ; V_40 > 0 ; V_40 -- ) {
V_107 = ( V_2 * 8 ) + ( 7 - V_40 ) ;
if ( V_107 >= F_24 ( V_190 ) )
break;
if ( V_189 [ V_2 ] & ( 1 << V_40 ) ) {
V_68 = F_33 ( V_39 -> V_50 ,
V_190 [ V_107 ] . V_119 ,
V_190 [ V_107 ] . V_120 ,
V_190 [ V_107 ] . V_94 ,
V_190 [ V_107 ] . V_79 ) ;
if ( V_68 ) {
F_69 ( V_39 , V_68 ) ;
V_179 ++ ;
}
}
}
}
return V_179 ;
}
static void
F_77 ( struct V_88 * V_127 , void * V_183 )
{
struct V_184 * V_84 = V_183 ;
struct V_185 * V_93 = & V_127 -> V_93 . V_186 ;
if ( V_93 -> type == V_191 )
V_84 -> V_179 += F_76 ( V_84 -> V_39 , V_127 ) ;
}
static int
F_78 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
unsigned long V_192 = V_8 -> V_193 . V_194 |
( V_8 -> V_193 . V_195 << 8 ) |
( ( V_8 -> V_193 . V_196 & 0x80 ) << 9 ) ;
int V_2 , V_179 = 0 ;
struct V_184 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_197 ; V_2 ++ ) {
if ( V_192 & ( 1 << V_2 ) ) {
struct V_58 * V_180 ;
V_180 = F_35 ( V_50 , & V_198 [ V_2 ] ) ;
if ( V_180 ) {
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
}
}
if ( F_74 ( V_8 , 1 , 0 ) )
F_39 ( ( T_1 * ) V_8 ,
F_77 , & V_84 ) ;
return V_179 + V_84 . V_179 ;
}
static void
F_79 ( struct V_88 * V_127 , void * V_183 )
{
struct V_184 * V_84 = V_183 ;
struct V_185 * V_93 = & V_127 -> V_93 . V_186 ;
struct V_38 * V_39 = V_84 -> V_39 ;
struct V_8 * V_8 = V_84 -> V_8 ;
if ( V_93 -> type == V_199 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_106 * V_200 ;
struct V_58 * V_180 ;
V_200 = & V_93 -> V_93 . V_201 [ V_2 ] ;
V_180 = F_50 ( V_39 , V_8 , V_200 ,
V_8 -> V_13 ) ;
if ( V_180 ) {
F_69 ( V_39 , V_180 ) ;
V_84 -> V_179 ++ ;
}
}
}
}
static int
F_80 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_2 , V_179 = 0 ;
struct V_184 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_202 ; V_2 ++ ) {
struct V_58 * V_180 ;
V_180 = F_50 ( V_39 , V_8 ,
& V_8 -> V_203 [ V_2 ] ,
V_8 -> V_13 ) ;
if ( V_180 ) {
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
}
if ( F_74 ( V_8 , 1 , 0 ) )
F_39 ( ( T_1 * ) V_8 , F_79 ,
& V_84 ) ;
return V_179 + V_84 . V_179 ;
}
static int F_81 ( struct V_38 * V_39 ,
struct V_88 * V_127 )
{
int V_2 , V_40 , V_179 = 0 ;
struct V_58 * V_180 ;
struct V_75 * V_50 = V_39 -> V_50 ;
struct V_204 * V_205 ;
const int V_206 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_207 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_208 ( V_209 ) , V_210 ;
V_205 = & ( V_127 -> V_93 . V_186 . V_93 . V_205 [ V_2 ] ) ;
if ( ! memcmp ( V_205 -> V_211 , V_207 , 3 ) )
continue;
V_210 = ( V_205 -> V_211 [ 0 ] + ( ( V_205 -> V_211 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_205 -> V_211 [ 1 ] & 0x0c ) {
case 0x00 :
V_209 = V_210 * 4 / 3 ;
break;
case 0x04 :
V_209 = V_210 * 16 / 9 ;
break;
case 0x08 :
V_209 = V_210 * 16 / 10 ;
break;
case 0x0c :
V_209 = V_210 * 15 / 9 ;
break;
}
for ( V_40 = 1 ; V_40 < 5 ; V_40 ++ ) {
if ( V_205 -> V_211 [ 2 ] & ( 1 << V_40 ) ) {
V_180 = F_52 ( V_50 , V_209 , V_210 ,
V_206 [ V_40 ] , V_40 == 0 ,
false , false ) ;
if ( V_180 ) {
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
}
}
}
return V_179 ;
}
static void
F_82 ( struct V_88 * V_127 , void * V_183 )
{
struct V_184 * V_84 = V_183 ;
struct V_185 * V_93 = & V_127 -> V_93 . V_186 ;
if ( V_93 -> type == V_212 )
V_84 -> V_179 += F_81 ( V_84 -> V_39 , V_127 ) ;
}
static int
F_83 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_184 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_74 ( V_8 , 1 , 2 ) )
F_39 ( ( T_1 * ) V_8 , F_82 , & V_84 ) ;
return V_84 . V_179 ;
}
static void
F_84 ( struct V_88 * V_127 , void * V_183 )
{
struct V_184 * V_84 = V_183 ;
struct V_58 * V_180 ;
if ( V_127 -> V_152 ) {
V_180 = F_58 ( V_84 -> V_39 -> V_50 ,
V_84 -> V_8 , V_127 ,
V_84 -> V_57 ) ;
if ( ! V_180 )
return;
if ( V_84 -> V_213 )
V_180 -> type |= V_67 ;
F_69 ( V_84 -> V_39 , V_180 ) ;
V_84 -> V_179 ++ ;
V_84 -> V_213 = 0 ;
}
}
static int
F_85 ( struct V_38 * V_39 , struct V_8 * V_8 ,
T_2 V_57 )
{
struct V_184 V_84 = {
V_39 ,
V_8 ,
1 ,
V_57 ,
0
} ;
if ( V_84 . V_213 && ! F_74 ( V_8 , 1 , 3 ) )
V_84 . V_213 =
( V_8 -> V_98 & V_214 ) ;
F_39 ( ( T_1 * ) V_8 , F_84 , & V_84 ) ;
return V_84 . V_179 ;
}
T_1 * F_86 ( struct V_8 * V_8 )
{
T_1 * V_215 = NULL ;
int V_2 ;
if ( V_8 == NULL || V_8 -> V_17 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_8 -> V_17 ; V_2 ++ ) {
V_215 = ( T_1 * ) V_8 + V_11 * ( V_2 + 1 ) ;
if ( V_215 [ 0 ] == V_91 )
break;
}
if ( V_2 == V_8 -> V_17 )
return NULL ;
return V_215 ;
}
static unsigned int
F_87 ( const struct V_58 * V_216 )
{
unsigned int clock = V_216 -> clock ;
if ( V_216 -> V_170 % 6 != 0 )
return clock ;
if ( V_216 -> V_74 == 240 || V_216 -> V_74 == 480 )
clock = clock * 1001 / 1000 ;
else
clock = F_88 ( clock * 1000 , 1001 ) ;
return clock ;
}
T_1 F_89 ( const struct V_58 * V_217 )
{
T_1 V_68 ;
if ( ! V_217 -> clock )
return 0 ;
for ( V_68 = 0 ; V_68 < F_24 ( V_218 ) ; V_68 ++ ) {
const struct V_58 * V_216 = & V_218 [ V_68 ] ;
unsigned int V_219 , V_220 ;
V_219 = V_216 -> clock ;
V_220 = F_87 ( V_216 ) ;
if ( ( F_90 ( V_217 -> clock ) == F_90 ( V_219 ) ||
F_90 ( V_217 -> clock ) == F_90 ( V_220 ) ) &&
F_91 ( V_217 , V_216 ) )
return V_68 + 1 ;
}
return 0 ;
}
static int
F_92 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
struct V_58 * V_68 , * V_221 ;
F_93 ( V_222 ) ;
int V_179 = 0 ;
if ( ! F_86 ( V_8 ) )
return 0 ;
F_51 (mode, &connector->probed_modes, head) {
const struct V_58 * V_216 ;
struct V_58 * V_180 ;
T_1 V_223 = F_89 ( V_68 ) - 1 ;
unsigned int V_219 , V_220 ;
if ( V_223 >= F_24 ( V_218 ) )
continue;
V_216 = & V_218 [ V_223 ] ;
V_219 = V_216 -> clock ;
V_220 = F_87 ( V_216 ) ;
if ( V_219 == V_220 )
continue;
if ( V_68 -> clock != V_219 && V_68 -> clock != V_220 )
continue;
V_180 = F_35 ( V_50 , V_216 ) ;
if ( ! V_180 )
continue;
if ( V_68 -> clock != V_219 )
V_180 -> clock = V_219 ;
else
V_180 -> clock = V_220 ;
F_94 ( & V_180 -> V_66 , & V_222 ) ;
}
F_29 (mode, tmp, &list, head) {
F_95 ( & V_68 -> V_66 ) ;
F_69 ( V_39 , V_68 ) ;
V_179 ++ ;
}
return V_179 ;
}
static int
F_96 ( struct V_38 * V_39 , T_1 * V_224 , T_1 V_21 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
T_1 * V_68 , V_216 ;
int V_179 = 0 ;
for ( V_68 = V_224 ; V_68 < V_224 + V_21 ; V_68 ++ ) {
V_216 = ( * V_68 & 127 ) - 1 ;
if ( V_216 < F_24 ( V_218 ) ) {
struct V_58 * V_180 ;
V_180 = F_35 ( V_50 ,
& V_218 [ V_216 ] ) ;
if ( V_180 ) {
V_180 -> V_170 = 0 ;
F_69 ( V_39 , V_180 ) ;
V_179 ++ ;
}
}
}
return V_179 ;
}
static int
F_97 ( const T_1 * V_224 )
{
return V_224 [ 0 ] & 0x1f ;
}
static int
F_98 ( const T_1 * V_224 )
{
return V_224 [ 0 ] >> 5 ;
}
static int
F_99 ( const T_1 * V_225 )
{
return V_225 [ 1 ] ;
}
static int
F_100 ( const T_1 * V_225 , int * V_22 , int * V_226 )
{
* V_22 = 4 ;
* V_226 = V_225 [ 2 ] ;
if ( * V_226 == 0 )
* V_226 = 127 ;
if ( * V_226 < 4 || * V_226 > 127 )
return - V_227 ;
return 0 ;
}
static int
F_101 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_1 * V_225 = F_86 ( V_8 ) ;
T_1 * V_224 , V_228 ;
int V_179 = 0 ;
if ( V_225 && F_99 ( V_225 ) >= 3 ) {
int V_2 , V_22 , V_226 ;
if ( F_100 ( V_225 , & V_22 , & V_226 ) )
return 0 ;
F_102 (cea, i, start, end) {
V_224 = & V_225 [ V_2 ] ;
V_228 = F_97 ( V_224 ) ;
if ( F_98 ( V_224 ) == V_229 )
V_179 += F_96 ( V_39 , V_224 + 1 , V_228 ) ;
}
}
return V_179 ;
}
static void
F_103 ( struct V_38 * V_39 , const T_1 * V_224 )
{
T_1 V_21 = F_97 ( V_224 ) ;
if ( V_21 >= 6 ) {
V_39 -> V_230 [ 5 ] |= ( V_224 [ 6 ] >> 7 ) << 1 ;
V_39 -> V_231 = V_224 [ 6 ] & 1 ;
}
if ( V_21 >= 7 )
V_39 -> V_232 = V_224 [ 7 ] * 5 ;
if ( V_21 >= 8 ) {
V_39 -> V_233 [ 0 ] = V_224 [ 8 ] >> 7 ;
V_39 -> V_233 [ 1 ] = ( V_224 [ 8 ] >> 6 ) & 1 ;
}
if ( V_21 >= 9 )
V_39 -> V_234 [ 0 ] = V_224 [ 9 ] ;
if ( V_21 >= 10 )
V_39 -> V_235 [ 0 ] = V_224 [ 10 ] ;
if ( V_21 >= 11 )
V_39 -> V_234 [ 1 ] = V_224 [ 11 ] ;
if ( V_21 >= 12 )
V_39 -> V_235 [ 1 ] = V_224 [ 12 ] ;
F_11 ( L_14
L_15
L_16
L_17
L_18 ,
V_39 -> V_231 ,
V_39 -> V_232 ,
( int ) V_39 -> V_233 [ 0 ] ,
( int ) V_39 -> V_233 [ 1 ] ,
V_39 -> V_234 [ 0 ] ,
V_39 -> V_234 [ 1 ] ,
V_39 -> V_235 [ 0 ] ,
V_39 -> V_235 [ 1 ] ) ;
}
static void
F_104 ( struct V_88 * V_59 , void * V_93 )
{
if ( V_59 -> V_93 . V_186 . type == V_236 )
* ( T_1 * * ) V_93 = V_59 -> V_93 . V_186 . V_93 . V_237 . V_237 ;
}
static bool F_105 ( const T_1 * V_224 )
{
int V_238 ;
if ( F_98 ( V_224 ) != V_239 )
return false ;
if ( F_97 ( V_224 ) < 5 )
return false ;
V_238 = V_224 [ 1 ] | ( V_224 [ 2 ] << 8 ) | ( V_224 [ 3 ] << 16 ) ;
return V_238 == V_240 ;
}
void F_106 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_4 * V_230 = V_39 -> V_230 ;
T_1 * V_225 ;
T_1 * V_35 ;
T_1 * V_224 ;
int V_241 = 0 ;
int V_242 ;
int V_228 ;
memset ( V_230 , 0 , sizeof( V_39 -> V_230 ) ) ;
V_225 = F_86 ( V_8 ) ;
if ( ! V_225 ) {
F_11 ( L_19 ) ;
return;
}
V_35 = NULL ;
F_39 ( ( T_1 * ) V_8 , F_104 , & V_35 ) ;
for ( V_242 = 0 ; V_35 && V_242 < 13 ; V_242 ++ ) {
if ( V_35 [ V_242 ] == 0x0a )
break;
V_230 [ 20 + V_242 ] = V_35 [ V_242 ] ;
}
V_230 [ 4 ] = ( V_225 [ 1 ] << 5 ) | V_242 ;
F_11 ( L_20 , V_230 + 20 ) ;
V_230 [ 0 ] = 2 << 3 ;
V_230 [ 16 ] = V_8 -> V_52 [ 0 ] ;
V_230 [ 17 ] = V_8 -> V_52 [ 1 ] ;
V_230 [ 18 ] = V_8 -> V_243 [ 0 ] ;
V_230 [ 19 ] = V_8 -> V_243 [ 1 ] ;
if ( F_99 ( V_225 ) >= 3 ) {
int V_2 , V_22 , V_226 ;
if ( F_100 ( V_225 , & V_22 , & V_226 ) ) {
V_22 = 0 ;
V_226 = 0 ;
}
F_102 (cea, i, start, end) {
V_224 = & V_225 [ V_2 ] ;
V_228 = F_97 ( V_224 ) ;
switch ( F_98 ( V_224 ) ) {
case V_244 :
V_241 = V_228 / 3 ;
if ( V_228 >= 1 )
memcpy ( V_230 + 20 + V_242 , & V_224 [ 1 ] , V_228 ) ;
break;
case V_245 :
if ( V_228 >= 1 )
V_230 [ 7 ] = V_224 [ 1 ] ;
break;
case V_239 :
if ( F_105 ( V_224 ) )
F_103 ( V_39 , V_224 ) ;
break;
default:
break;
}
}
}
V_230 [ 5 ] |= V_241 << 4 ;
V_230 [ 2 ] = ( 20 + V_242 + V_241 * 3 + 3 ) / 4 ;
F_11 ( L_21 , ( int ) V_230 [ 2 ] , V_241 ) ;
}
int F_107 ( struct V_8 * V_8 , struct V_246 * * V_247 )
{
int V_248 = 0 ;
int V_2 , V_22 , V_226 , V_228 ;
T_1 * V_225 ;
V_225 = F_86 ( V_8 ) ;
if ( ! V_225 ) {
F_11 ( L_22 ) ;
return - V_249 ;
}
if ( F_99 ( V_225 ) < 3 ) {
F_11 ( L_23 ) ;
return - V_250 ;
}
if ( F_100 ( V_225 , & V_22 , & V_226 ) ) {
F_11 ( L_24 ) ;
return - V_251 ;
}
F_102 (cea, i, start, end) {
T_1 * V_224 = & V_225 [ V_2 ] ;
if ( F_98 ( V_224 ) == V_244 ) {
int V_40 ;
V_228 = F_97 ( V_224 ) ;
V_248 = V_228 / 3 ;
* V_247 = F_108 ( V_248 , sizeof( * * V_247 ) , V_46 ) ;
if ( ! * V_247 )
return - V_252 ;
for ( V_40 = 0 ; V_40 < V_248 ; V_40 ++ ) {
T_1 * V_253 = & V_224 [ 1 + V_40 * 3 ] ;
( * V_247 ) [ V_40 ] . V_254 = ( V_253 [ 0 ] & 0x78 ) >> 3 ;
( * V_247 ) [ V_40 ] . V_255 = V_253 [ 0 ] & 0x7 ;
( * V_247 ) [ V_40 ] . V_256 = V_253 [ 1 ] & 0x7F ;
( * V_247 ) [ V_40 ] . V_257 = V_253 [ 2 ] ;
}
break;
}
}
return V_248 ;
}
int F_109 ( struct V_38 * V_39 ,
struct V_58 * V_68 )
{
int V_2 = ! ! ( V_68 -> V_31 & V_126 ) ;
int V_104 , V_258 ;
if ( ! V_39 -> V_233 [ 0 ] )
return 0 ;
if ( ! V_39 -> V_233 [ 1 ] )
V_2 = 0 ;
V_104 = V_39 -> V_235 [ V_2 ] ;
V_258 = V_39 -> V_234 [ V_2 ] ;
if ( V_104 == 255 || V_258 == 255 )
return 0 ;
if ( V_104 )
V_104 = F_38 ( 2 * ( V_104 - 1 ) , 500 ) ;
if ( V_258 )
V_258 = F_38 ( 2 * ( V_258 - 1 ) , 500 ) ;
return F_110 ( V_258 - V_104 , 0 ) ;
}
struct V_38 * F_111 ( struct V_259 * V_260 ,
struct V_58 * V_68 )
{
struct V_38 * V_39 ;
struct V_75 * V_50 = V_260 -> V_50 ;
F_51 (connector, &dev->mode_config.connector_list, head)
if ( V_39 -> V_260 == V_260 && V_39 -> V_230 [ 0 ] )
return V_39 ;
return NULL ;
}
bool F_112 ( struct V_8 * V_8 )
{
T_1 * V_215 ;
int V_2 ;
int V_261 , V_262 ;
V_215 = F_86 ( V_8 ) ;
if ( ! V_215 )
return false ;
if ( F_100 ( V_215 , & V_261 , & V_262 ) )
return false ;
F_102 (edid_ext, i, start_offset, end_offset) {
if ( F_105 ( & V_215 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_113 ( struct V_8 * V_8 )
{
T_1 * V_215 ;
int V_2 , V_40 ;
bool V_263 = false ;
int V_261 , V_262 ;
V_215 = F_86 ( V_8 ) ;
if ( ! V_215 )
goto V_226;
V_263 = ( ( V_215 [ 3 ] & V_264 ) != 0 ) ;
if ( V_263 ) {
F_11 ( L_25 ) ;
goto V_226;
}
if ( F_100 ( V_215 , & V_261 , & V_262 ) )
goto V_226;
F_102 (edid_ext, i, start_offset, end_offset) {
if ( F_98 ( & V_215 [ V_2 ] ) == V_244 ) {
V_263 = true ;
for ( V_40 = 1 ; V_40 < F_97 ( & V_215 [ V_2 ] ) + 1 ; V_40 += 3 )
F_11 ( L_26 ,
( V_215 [ V_2 + V_40 ] >> 3 ) & 0xf ) ;
goto V_226;
}
}
V_226:
return V_263 ;
}
bool F_114 ( struct V_8 * V_8 )
{
T_1 * V_215 ;
int V_2 , V_22 , V_226 ;
V_215 = F_86 ( V_8 ) ;
if ( ! V_215 )
return false ;
if ( F_100 ( V_215 , & V_22 , & V_226 ) )
return false ;
F_102 (edid_ext, i, start, end) {
if ( F_98 ( & V_215 [ V_2 ] ) == V_265 &&
F_97 ( & V_215 [ V_2 ] ) == 2 ) {
F_11 ( L_27 , V_215 [ V_2 + 2 ] ) ;
return V_215 [ V_2 + 2 ] & V_266 ;
}
}
return false ;
}
static void F_115 ( struct V_8 * V_8 ,
struct V_267 * V_268 )
{
T_1 * V_215 ;
V_268 -> V_160 = V_8 -> V_167 * 10 ;
V_268 -> V_163 = V_8 -> V_168 * 10 ;
V_268 -> V_269 = 0 ;
V_268 -> V_270 = 0 ;
if ( V_8 -> V_13 < 3 )
return;
if ( ! ( V_8 -> V_96 & V_97 ) )
return;
V_215 = F_86 ( V_8 ) ;
if ( V_215 ) {
V_268 -> V_271 = V_215 [ 1 ] ;
V_268 -> V_270 = V_272 ;
if ( V_215 [ 3 ] & V_273 )
V_268 -> V_270 |= V_274 ;
if ( V_215 [ 3 ] & V_275 )
V_268 -> V_270 |= V_276 ;
}
if ( V_8 -> V_13 < 4 )
return;
switch ( V_8 -> V_96 & V_277 ) {
case V_278 :
V_268 -> V_269 = 6 ;
break;
case V_279 :
V_268 -> V_269 = 8 ;
break;
case V_280 :
V_268 -> V_269 = 10 ;
break;
case V_281 :
V_268 -> V_269 = 12 ;
break;
case V_282 :
V_268 -> V_269 = 14 ;
break;
case V_283 :
V_268 -> V_269 = 16 ;
break;
case V_284 :
default:
V_268 -> V_269 = 0 ;
break;
}
V_268 -> V_270 |= V_272 ;
if ( V_8 -> V_98 & V_285 )
V_268 -> V_270 |= V_274 ;
if ( V_8 -> V_98 & V_286 )
V_268 -> V_270 |= V_276 ;
}
int F_116 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_287 = 0 ;
T_2 V_57 ;
if ( V_8 == NULL ) {
return 0 ;
}
if ( ! F_8 ( V_8 ) ) {
F_17 ( V_39 -> V_50 -> V_50 , L_28 ,
F_18 ( V_39 ) ) ;
return 0 ;
}
V_57 = F_23 ( V_8 ) ;
V_287 += F_85 ( V_39 , V_8 , V_57 ) ;
V_287 += F_83 ( V_39 , V_8 ) ;
V_287 += F_80 ( V_39 , V_8 ) ;
V_287 += F_78 ( V_39 , V_8 ) ;
if ( V_8 -> V_98 & V_99 )
V_287 += F_75 ( V_39 , V_8 ) ;
V_287 += F_101 ( V_39 , V_8 ) ;
V_287 += F_92 ( V_39 , V_8 ) ;
if ( V_57 & ( V_64 | V_65 ) )
F_26 ( V_39 , V_57 ) ;
F_115 ( V_8 , & V_39 -> V_288 ) ;
return V_287 ;
}
int F_117 ( struct V_38 * V_39 ,
int V_70 , int V_74 )
{
int V_2 , V_248 , V_287 = 0 ;
struct V_58 * V_68 ;
struct V_75 * V_50 = V_39 -> V_50 ;
V_248 = sizeof( V_80 ) / sizeof( struct V_58 ) ;
if ( V_70 < 0 )
V_70 = 0 ;
if ( V_74 < 0 )
V_74 = 0 ;
for ( V_2 = 0 ; V_2 < V_248 ; V_2 ++ ) {
const struct V_58 * V_81 = & V_80 [ V_2 ] ;
if ( V_70 && V_74 ) {
if ( V_81 -> V_70 > V_70 ||
V_81 -> V_74 > V_74 )
continue;
}
if ( F_34 ( V_81 ) > 61 )
continue;
V_68 = F_35 ( V_50 , V_81 ) ;
if ( V_68 ) {
F_69 ( V_39 , V_68 ) ;
V_287 ++ ;
}
}
return V_287 ;
}
int
F_118 ( struct V_289 * V_290 ,
const struct V_58 * V_68 )
{
int V_291 ;
if ( ! V_290 || ! V_68 )
return - V_292 ;
V_291 = F_119 ( V_290 ) ;
if ( V_291 < 0 )
return V_291 ;
V_290 -> V_293 = F_89 ( V_68 ) ;
if ( ! V_290 -> V_293 )
return 0 ;
V_290 -> V_294 = V_295 ;
V_290 -> V_296 = V_297 ;
return 0 ;
}
