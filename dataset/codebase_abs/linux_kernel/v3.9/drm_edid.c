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
if ( V_2 == 4 && V_6 ) {
F_16 ( V_39 -> V_50 -> V_50 ,
L_8 ,
F_17 ( V_39 ) , V_40 ) ;
V_39 -> V_43 ++ ;
}
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
for ( V_2 = 0 ; V_2 < F_23 ( V_80 ) ; V_2 ++ ) {
const struct V_58 * V_81 = & V_80 [ V_2 ] ;
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
F_35 ( T_1 * V_82 , T_3 * V_83 , void * V_84 )
{
int V_2 , V_85 = 0 ;
T_1 V_86 = V_82 [ 0x02 ] ;
T_1 * V_87 = V_82 + V_86 ;
V_85 = ( 127 - V_86 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_85 ; V_2 ++ )
V_83 ( (struct V_88 * ) ( V_87 + 18 * V_2 ) , V_84 ) ;
}
static void
F_36 ( T_1 * V_82 , T_3 * V_83 , void * V_84 )
{
unsigned int V_2 , V_85 = F_37 ( ( int ) V_82 [ 0x02 ] , 6 ) ;
T_1 * V_87 = V_82 + 5 ;
if ( V_82 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_85 ; V_2 ++ )
V_83 ( (struct V_88 * ) ( V_87 + 18 * V_2 ) , V_84 ) ;
}
static void
F_38 ( T_1 * V_1 , T_3 * V_83 , void * V_84 )
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
F_35 ( V_82 , V_83 , V_84 ) ;
break;
case V_92 :
F_36 ( V_82 , V_83 , V_84 ) ;
break;
default:
break;
}
}
}
static void
F_39 ( struct V_88 * V_59 , void * V_93 )
{
T_1 * V_94 = ( T_1 * ) V_59 ;
if ( V_94 [ 3 ] == V_95 )
if ( V_94 [ 15 ] & 0x10 )
* ( bool * ) V_93 = true ;
}
static bool
F_40 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 4 ) {
bool V_25 = false ;
F_38 ( ( T_1 * ) V_8 , F_39 , & V_25 ) ;
return V_25 ;
}
return ( ( V_8 -> V_96 & V_97 ) != 0 ) ;
}
static void
F_41 ( struct V_88 * V_59 , void * V_93 )
{
T_1 * V_94 = ( T_1 * ) V_59 ;
if ( V_94 [ 3 ] == V_95 && V_94 [ 10 ] == 0x02 )
* ( T_1 * * ) V_93 = V_94 ;
}
static int
F_42 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_94 ) ;
return V_94 ? ( V_94 [ 12 ] * 2 ) : 0 ;
}
static int
F_43 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_94 ) ;
return V_94 ? V_94 [ 13 ] : 0 ;
}
static int
F_44 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_94 ) ;
return V_94 ? ( V_94 [ 15 ] << 8 ) + V_94 [ 14 ] : 0 ;
}
static int
F_45 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_94 ) ;
return V_94 ? V_94 [ 16 ] : 0 ;
}
static int
F_46 ( struct V_8 * V_8 )
{
T_1 * V_94 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_41 , & V_94 ) ;
return V_94 ? V_94 [ 17 ] : 0 ;
}
static int F_47 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 2 ) {
if ( V_8 -> V_13 >= 4 && ( V_8 -> V_98 & V_99 ) )
return V_100 ;
if ( F_42 ( V_8 ) )
return V_101 ;
return V_102 ;
}
return V_103 ;
}
static int
F_48 ( T_1 V_104 , T_1 V_105 )
{
return ( V_104 == 0x00 && V_105 == 0x00 ) ||
( V_104 == 0x01 && V_105 == 0x01 ) ||
( V_104 == 0x20 && V_105 == 0x20 ) ;
}
static struct V_58 *
F_49 ( struct V_38 * V_39 , struct V_8 * V_8 ,
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
int V_116 = F_47 ( V_8 ) ;
if ( F_48 ( V_59 -> V_76 , V_59 -> V_110 ) )
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
F_50 (m, &connector->probed_modes, head)
if ( V_107 -> V_70 == V_76 && V_107 -> V_74 == V_77 &&
F_33 ( V_107 ) == V_108 )
return NULL ;
if ( V_76 == 1366 && V_77 == 768 && V_108 == 60 ) {
V_68 = F_51 ( V_50 , 1366 , 768 , V_108 , 0 , 0 ,
false ) ;
V_68 -> V_70 = 1366 ;
V_68 -> V_72 = V_68 -> V_72 - 1 ;
V_68 -> V_71 = V_68 -> V_71 - 1 ;
return V_68 ;
}
if ( F_40 ( V_8 ) ) {
V_68 = F_32 ( V_50 , V_76 , V_77 , V_108 ,
true ) ;
if ( V_68 )
return V_68 ;
}
V_68 = F_32 ( V_50 , V_76 , V_77 , V_108 , false ) ;
if ( V_68 )
return V_68 ;
switch ( V_116 ) {
case V_103 :
break;
case V_102 :
V_68 = F_52 ( V_50 , V_76 , V_77 , V_108 , 0 , 0 ) ;
break;
case V_101 :
V_68 = F_52 ( V_50 , V_76 , V_77 , V_108 , 0 , 0 ) ;
if ( ! V_68 )
return NULL ;
if ( F_53 ( V_68 ) > F_42 ( V_8 ) ) {
F_54 ( V_50 , V_68 ) ;
V_68 = F_55 ( V_50 , V_76 , V_77 ,
V_108 , 0 , 0 ,
F_44 ( V_8 ) ,
F_43 ( V_8 ) ,
F_45 ( V_8 ) ,
F_46 ( V_8 ) ) ;
}
break;
case V_100 :
V_68 = F_51 ( V_50 , V_76 , V_77 , V_108 , 0 , 0 ,
false ) ;
break;
}
return V_68 ;
}
static void
F_56 ( struct V_58 * V_68 ,
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
for ( V_2 = 0 ; V_2 < F_23 ( V_121 ) ; V_2 ++ ) {
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
static struct V_58 * F_57 ( struct V_75 * V_50 ,
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
F_5 ( V_148 L_10 ) ;
return NULL ;
}
if ( ! ( V_118 -> V_122 & V_149 ) ) {
F_5 ( V_148 L_11 ) ;
}
if ( ! V_142 || ! V_146 ) {
F_10 ( L_12
L_13 ) ;
return NULL ;
}
if ( V_57 & V_150 ) {
V_68 = F_51 ( V_50 , V_129 , V_132 , 60 , true , false , false ) ;
if ( ! V_68 )
return NULL ;
goto V_151;
}
V_68 = F_58 ( V_50 ) ;
if ( ! V_68 )
return NULL ;
if ( V_57 & V_152 )
V_127 -> V_153 = F_59 ( 1088 ) ;
V_68 -> clock = F_60 ( V_127 -> V_153 ) * 10 ;
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
F_56 ( V_68 , V_118 ) ;
if ( V_57 & V_154 ) {
V_118 -> V_122 |= V_155 | V_156 ;
}
V_68 -> V_31 |= ( V_118 -> V_122 & V_155 ) ?
V_157 : V_158 ;
V_68 -> V_31 |= ( V_118 -> V_122 & V_156 ) ?
V_159 : V_160 ;
V_151:
V_68 -> V_161 = V_118 -> V_162 | ( V_118 -> V_163 & 0xf0 ) << 4 ;
V_68 -> V_164 = V_118 -> V_165 | ( V_118 -> V_163 & 0xf ) << 8 ;
if ( V_57 & V_166 ) {
V_68 -> V_161 *= 10 ;
V_68 -> V_164 *= 10 ;
}
if ( V_57 & V_167 ) {
V_68 -> V_161 = V_8 -> V_168 * 10 ;
V_68 -> V_164 = V_8 -> V_169 * 10 ;
}
V_68 -> type = V_170 ;
V_68 -> V_171 = F_33 ( V_68 ) ;
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
struct V_88 * V_127 )
{
T_2 V_178 ;
T_1 * V_59 = ( T_1 * ) V_127 ;
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
struct V_58 * V_107 ;
bool V_179 = false ;
F_50 (m, &connector->probed_modes, head) {
if ( V_68 -> V_70 == V_107 -> V_70 &&
V_68 -> V_74 == V_107 -> V_74 &&
F_33 ( V_68 ) == F_33 ( V_107 ) )
return false ;
if ( V_68 -> V_70 <= V_107 -> V_70 &&
V_68 -> V_74 <= V_107 -> V_74 )
V_179 = true ;
}
return V_179 ;
}
static int
F_67 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_88 * V_127 )
{
int V_2 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < F_23 ( V_80 ) ; V_2 ++ ) {
if ( F_65 ( V_80 + V_2 , V_8 , V_127 ) &&
F_66 ( V_39 , V_80 + V_2 ) ) {
V_181 = F_34 ( V_50 , & V_80 [ V_2 ] ) ;
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
struct V_88 * V_127 )
{
int V_2 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < F_23 ( V_182 ) ; V_2 ++ ) {
const struct V_183 * V_107 = & V_182 [ V_2 ] ;
V_181 = F_52 ( V_50 , V_107 -> V_119 , V_107 -> V_120 , V_107 -> V_94 , 0 , 0 ) ;
if ( ! V_181 )
return V_180 ;
F_69 ( V_181 ) ;
if ( ! F_65 ( V_181 , V_8 , V_127 ) ||
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
struct V_88 * V_127 )
{
int V_2 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
bool V_79 = F_40 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < F_23 ( V_182 ) ; V_2 ++ ) {
const struct V_183 * V_107 = & V_182 [ V_2 ] ;
V_181 = F_51 ( V_50 , V_107 -> V_119 , V_107 -> V_120 , V_107 -> V_94 , V_79 , 0 , 0 ) ;
if ( ! V_181 )
return V_180 ;
F_69 ( V_181 ) ;
if ( ! F_65 ( V_181 , V_8 , V_127 ) ||
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
F_72 ( struct V_88 * V_127 , void * V_184 )
{
struct V_185 * V_84 = V_184 ;
struct V_186 * V_93 = & V_127 -> V_93 . V_187 ;
struct V_188 * V_189 = & V_93 -> V_93 . V_189 ;
if ( V_93 -> type != V_95 )
return;
V_84 -> V_180 += F_67 ( V_84 -> V_39 ,
V_84 -> V_8 ,
V_127 ) ;
if ( ! F_73 ( V_84 -> V_8 , 1 , 1 ) )
return;
switch ( V_189 -> V_31 ) {
case 0x02 :
case 0x00 :
V_84 -> V_180 += F_70 ( V_84 -> V_39 ,
V_84 -> V_8 ,
V_127 ) ;
break;
case 0x04 :
if ( ! F_73 ( V_84 -> V_8 , 1 , 3 ) )
break;
V_84 -> V_180 += F_71 ( V_84 -> V_39 ,
V_84 -> V_8 ,
V_127 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_74 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_185 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_73 ( V_8 , 1 , 0 ) )
F_38 ( ( T_1 * ) V_8 , F_72 ,
& V_84 ) ;
return V_84 . V_180 ;
}
static int
F_75 ( struct V_38 * V_39 , struct V_88 * V_127 )
{
int V_2 , V_40 , V_107 , V_180 = 0 ;
struct V_58 * V_68 ;
T_1 * V_190 = ( ( T_1 * ) V_127 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_40 = 7 ; V_40 > 0 ; V_40 -- ) {
V_107 = ( V_2 * 8 ) + ( 7 - V_40 ) ;
if ( V_107 >= F_23 ( V_191 ) )
break;
if ( V_190 [ V_2 ] & ( 1 << V_40 ) ) {
V_68 = F_32 ( V_39 -> V_50 ,
V_191 [ V_107 ] . V_119 ,
V_191 [ V_107 ] . V_120 ,
V_191 [ V_107 ] . V_94 ,
V_191 [ V_107 ] . V_79 ) ;
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
F_76 ( struct V_88 * V_127 , void * V_184 )
{
struct V_185 * V_84 = V_184 ;
struct V_186 * V_93 = & V_127 -> V_93 . V_187 ;
if ( V_93 -> type == V_192 )
V_84 -> V_180 += F_75 ( V_84 -> V_39 , V_127 ) ;
}
static int
F_77 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
unsigned long V_193 = V_8 -> V_194 . V_195 |
( V_8 -> V_194 . V_196 << 8 ) |
( ( V_8 -> V_194 . V_197 & 0x80 ) << 9 ) ;
int V_2 , V_180 = 0 ;
struct V_185 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_198 ; V_2 ++ ) {
if ( V_193 & ( 1 << V_2 ) ) {
struct V_58 * V_181 ;
V_181 = F_34 ( V_50 , & V_199 [ V_2 ] ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
}
if ( F_73 ( V_8 , 1 , 0 ) )
F_38 ( ( T_1 * ) V_8 ,
F_76 , & V_84 ) ;
return V_180 + V_84 . V_180 ;
}
static void
F_78 ( struct V_88 * V_127 , void * V_184 )
{
struct V_185 * V_84 = V_184 ;
struct V_186 * V_93 = & V_127 -> V_93 . V_187 ;
struct V_38 * V_39 = V_84 -> V_39 ;
struct V_8 * V_8 = V_84 -> V_8 ;
if ( V_93 -> type == V_200 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_106 * V_201 ;
struct V_58 * V_181 ;
V_201 = & V_93 -> V_93 . V_202 [ V_2 ] ;
V_181 = F_49 ( V_39 , V_8 , V_201 ,
V_8 -> V_13 ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_84 -> V_180 ++ ;
}
}
}
}
static int
F_79 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_2 , V_180 = 0 ;
struct V_185 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_203 ; V_2 ++ ) {
struct V_58 * V_181 ;
V_181 = F_49 ( V_39 , V_8 ,
& V_8 -> V_204 [ V_2 ] ,
V_8 -> V_13 ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
if ( F_73 ( V_8 , 1 , 0 ) )
F_38 ( ( T_1 * ) V_8 , F_78 ,
& V_84 ) ;
return V_180 + V_84 . V_180 ;
}
static int F_80 ( struct V_38 * V_39 ,
struct V_88 * V_127 )
{
int V_2 , V_40 , V_180 = 0 ;
struct V_58 * V_181 ;
struct V_75 * V_50 = V_39 -> V_50 ;
struct V_205 * V_206 ;
const int V_207 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_208 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_209 ( V_210 ) , V_211 ;
V_206 = & ( V_127 -> V_93 . V_187 . V_93 . V_206 [ V_2 ] ) ;
if ( ! memcmp ( V_206 -> V_212 , V_208 , 3 ) )
continue;
V_211 = ( V_206 -> V_212 [ 0 ] + ( ( V_206 -> V_212 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_206 -> V_212 [ 1 ] & 0x0c ) {
case 0x00 :
V_210 = V_211 * 4 / 3 ;
break;
case 0x04 :
V_210 = V_211 * 16 / 9 ;
break;
case 0x08 :
V_210 = V_211 * 16 / 10 ;
break;
case 0x0c :
V_210 = V_211 * 15 / 9 ;
break;
}
for ( V_40 = 1 ; V_40 < 5 ; V_40 ++ ) {
if ( V_206 -> V_212 [ 2 ] & ( 1 << V_40 ) ) {
V_181 = F_51 ( V_50 , V_210 , V_211 ,
V_207 [ V_40 ] , V_40 == 0 ,
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
F_81 ( struct V_88 * V_127 , void * V_184 )
{
struct V_185 * V_84 = V_184 ;
struct V_186 * V_93 = & V_127 -> V_93 . V_187 ;
if ( V_93 -> type == V_213 )
V_84 -> V_180 += F_80 ( V_84 -> V_39 , V_127 ) ;
}
static int
F_82 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_185 V_84 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_73 ( V_8 , 1 , 2 ) )
F_38 ( ( T_1 * ) V_8 , F_81 , & V_84 ) ;
return V_84 . V_180 ;
}
static void
F_83 ( struct V_88 * V_127 , void * V_184 )
{
struct V_185 * V_84 = V_184 ;
struct V_58 * V_181 ;
if ( V_127 -> V_153 ) {
V_181 = F_57 ( V_84 -> V_39 -> V_50 ,
V_84 -> V_8 , V_127 ,
V_84 -> V_57 ) ;
if ( ! V_181 )
return;
if ( V_84 -> V_214 )
V_181 -> type |= V_67 ;
F_68 ( V_84 -> V_39 , V_181 ) ;
V_84 -> V_180 ++ ;
V_84 -> V_214 = 0 ;
}
}
static int
F_84 ( struct V_38 * V_39 , struct V_8 * V_8 ,
T_2 V_57 )
{
struct V_185 V_84 = {
V_39 ,
V_8 ,
1 ,
V_57 ,
0
} ;
if ( V_84 . V_214 && ! F_73 ( V_8 , 1 , 3 ) )
V_84 . V_214 =
( V_8 -> V_98 & V_215 ) ;
F_38 ( ( T_1 * ) V_8 , F_83 , & V_84 ) ;
return V_84 . V_180 ;
}
T_1 * F_85 ( struct V_8 * V_8 )
{
T_1 * V_216 = NULL ;
int V_2 ;
if ( V_8 == NULL || V_8 -> V_17 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_8 -> V_17 ; V_2 ++ ) {
V_216 = ( T_1 * ) V_8 + V_11 * ( V_2 + 1 ) ;
if ( V_216 [ 0 ] == V_91 )
break;
}
if ( V_2 == V_8 -> V_17 )
return NULL ;
return V_216 ;
}
T_1 F_86 ( const struct V_58 * V_217 )
{
struct V_58 * V_218 ;
T_1 V_68 ;
for ( V_68 = 0 ; V_68 < F_23 ( V_219 ) ; V_68 ++ ) {
V_218 = (struct V_58 * ) & V_219 [ V_68 ] ;
if ( F_87 ( V_217 , V_218 ) )
return V_68 + 1 ;
}
return 0 ;
}
static int
F_88 ( struct V_38 * V_39 , T_1 * V_220 , T_1 V_21 )
{
struct V_75 * V_50 = V_39 -> V_50 ;
T_1 * V_68 , V_218 ;
int V_180 = 0 ;
for ( V_68 = V_220 ; V_68 < V_220 + V_21 ; V_68 ++ ) {
V_218 = ( * V_68 & 127 ) - 1 ;
if ( V_218 < F_23 ( V_219 ) ) {
struct V_58 * V_181 ;
V_181 = F_34 ( V_50 ,
& V_219 [ V_218 ] ) ;
if ( V_181 ) {
F_68 ( V_39 , V_181 ) ;
V_180 ++ ;
}
}
}
return V_180 ;
}
static int
F_89 ( const T_1 * V_220 )
{
return V_220 [ 0 ] & 0x1f ;
}
static int
F_90 ( const T_1 * V_220 )
{
return V_220 [ 0 ] >> 5 ;
}
static int
F_91 ( const T_1 * V_221 )
{
return V_221 [ 1 ] ;
}
static int
F_92 ( const T_1 * V_221 , int * V_22 , int * V_222 )
{
* V_22 = 4 ;
* V_222 = V_221 [ 2 ] ;
if ( * V_222 == 0 )
* V_222 = 127 ;
if ( * V_222 < 4 || * V_222 > 127 )
return - V_223 ;
return 0 ;
}
static int
F_93 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_1 * V_221 = F_85 ( V_8 ) ;
T_1 * V_220 , V_224 ;
int V_180 = 0 ;
if ( V_221 && F_91 ( V_221 ) >= 3 ) {
int V_2 , V_22 , V_222 ;
if ( F_92 ( V_221 , & V_22 , & V_222 ) )
return 0 ;
F_94 (cea, i, start, end) {
V_220 = & V_221 [ V_2 ] ;
V_224 = F_89 ( V_220 ) ;
if ( F_90 ( V_220 ) == V_225 )
V_180 += F_88 ( V_39 , V_220 + 1 , V_224 ) ;
}
}
return V_180 ;
}
static void
F_95 ( struct V_38 * V_39 , const T_1 * V_220 )
{
T_1 V_21 = F_89 ( V_220 ) ;
if ( V_21 >= 6 ) {
V_39 -> V_226 [ 5 ] |= ( V_220 [ 6 ] >> 7 ) << 1 ;
V_39 -> V_227 = V_220 [ 6 ] & 1 ;
}
if ( V_21 >= 7 )
V_39 -> V_228 = V_220 [ 7 ] * 5 ;
if ( V_21 >= 8 ) {
V_39 -> V_229 [ 0 ] = V_220 [ 8 ] >> 7 ;
V_39 -> V_229 [ 1 ] = ( V_220 [ 8 ] >> 6 ) & 1 ;
}
if ( V_21 >= 9 )
V_39 -> V_230 [ 0 ] = V_220 [ 9 ] ;
if ( V_21 >= 10 )
V_39 -> V_231 [ 0 ] = V_220 [ 10 ] ;
if ( V_21 >= 11 )
V_39 -> V_230 [ 1 ] = V_220 [ 11 ] ;
if ( V_21 >= 12 )
V_39 -> V_231 [ 1 ] = V_220 [ 12 ] ;
F_10 ( L_14
L_15
L_16
L_17
L_18 ,
V_39 -> V_227 ,
V_39 -> V_228 ,
( int ) V_39 -> V_229 [ 0 ] ,
( int ) V_39 -> V_229 [ 1 ] ,
V_39 -> V_230 [ 0 ] ,
V_39 -> V_230 [ 1 ] ,
V_39 -> V_231 [ 0 ] ,
V_39 -> V_231 [ 1 ] ) ;
}
static void
F_96 ( struct V_88 * V_59 , void * V_93 )
{
if ( V_59 -> V_93 . V_187 . type == V_232 )
* ( T_1 * * ) V_93 = V_59 -> V_93 . V_187 . V_93 . V_233 . V_233 ;
}
static bool F_97 ( const T_1 * V_220 )
{
int V_234 ;
if ( F_90 ( V_220 ) != V_235 )
return false ;
if ( F_89 ( V_220 ) < 5 )
return false ;
V_234 = V_220 [ 1 ] | ( V_220 [ 2 ] << 8 ) | ( V_220 [ 3 ] << 16 ) ;
return V_234 == V_236 ;
}
void F_98 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_4 * V_226 = V_39 -> V_226 ;
T_1 * V_221 ;
T_1 * V_35 ;
T_1 * V_220 ;
int V_237 = 0 ;
int V_238 ;
int V_224 ;
memset ( V_226 , 0 , sizeof( V_39 -> V_226 ) ) ;
V_221 = F_85 ( V_8 ) ;
if ( ! V_221 ) {
F_10 ( L_19 ) ;
return;
}
V_35 = NULL ;
F_38 ( ( T_1 * ) V_8 , F_96 , & V_35 ) ;
for ( V_238 = 0 ; V_35 && V_238 < 13 ; V_238 ++ ) {
if ( V_35 [ V_238 ] == 0x0a )
break;
V_226 [ 20 + V_238 ] = V_35 [ V_238 ] ;
}
V_226 [ 4 ] = ( V_221 [ 1 ] << 5 ) | V_238 ;
F_10 ( L_20 , V_226 + 20 ) ;
V_226 [ 0 ] = 2 << 3 ;
V_226 [ 16 ] = V_8 -> V_52 [ 0 ] ;
V_226 [ 17 ] = V_8 -> V_52 [ 1 ] ;
V_226 [ 18 ] = V_8 -> V_239 [ 0 ] ;
V_226 [ 19 ] = V_8 -> V_239 [ 1 ] ;
if ( F_91 ( V_221 ) >= 3 ) {
int V_2 , V_22 , V_222 ;
if ( F_92 ( V_221 , & V_22 , & V_222 ) ) {
V_22 = 0 ;
V_222 = 0 ;
}
F_94 (cea, i, start, end) {
V_220 = & V_221 [ V_2 ] ;
V_224 = F_89 ( V_220 ) ;
switch ( F_90 ( V_220 ) ) {
case V_240 :
V_237 = V_224 / 3 ;
if ( V_224 >= 1 )
memcpy ( V_226 + 20 + V_238 , & V_220 [ 1 ] , V_224 ) ;
break;
case V_241 :
if ( V_224 >= 1 )
V_226 [ 7 ] = V_220 [ 1 ] ;
break;
case V_235 :
if ( F_97 ( V_220 ) )
F_95 ( V_39 , V_220 ) ;
break;
default:
break;
}
}
}
V_226 [ 5 ] |= V_237 << 4 ;
V_226 [ 2 ] = ( 20 + V_238 + V_237 * 3 + 3 ) / 4 ;
F_10 ( L_21 , ( int ) V_226 [ 2 ] , V_237 ) ;
}
int F_99 ( struct V_38 * V_39 ,
struct V_58 * V_68 )
{
int V_2 = ! ! ( V_68 -> V_31 & V_126 ) ;
int V_104 , V_242 ;
if ( ! V_39 -> V_229 [ 0 ] )
return 0 ;
if ( ! V_39 -> V_229 [ 1 ] )
V_2 = 0 ;
V_104 = V_39 -> V_231 [ V_2 ] ;
V_242 = V_39 -> V_230 [ V_2 ] ;
if ( V_104 == 255 || V_242 == 255 )
return 0 ;
if ( V_104 )
V_104 = F_37 ( 2 * ( V_104 - 1 ) , 500 ) ;
if ( V_242 )
V_242 = F_37 ( 2 * ( V_242 - 1 ) , 500 ) ;
return F_100 ( V_242 - V_104 , 0 ) ;
}
struct V_38 * F_101 ( struct V_243 * V_244 ,
struct V_58 * V_68 )
{
struct V_38 * V_39 ;
struct V_75 * V_50 = V_244 -> V_50 ;
F_50 (connector, &dev->mode_config.connector_list, head)
if ( V_39 -> V_244 == V_244 && V_39 -> V_226 [ 0 ] )
return V_39 ;
return NULL ;
}
bool F_102 ( struct V_8 * V_8 )
{
T_1 * V_216 ;
int V_2 ;
int V_245 , V_246 ;
V_216 = F_85 ( V_8 ) ;
if ( ! V_216 )
return false ;
if ( F_92 ( V_216 , & V_245 , & V_246 ) )
return false ;
F_94 (edid_ext, i, start_offset, end_offset) {
if ( F_97 ( & V_216 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_103 ( struct V_8 * V_8 )
{
T_1 * V_216 ;
int V_2 , V_40 ;
bool V_247 = false ;
int V_245 , V_246 ;
V_216 = F_85 ( V_8 ) ;
if ( ! V_216 )
goto V_222;
V_247 = ( ( V_216 [ 3 ] & V_248 ) != 0 ) ;
if ( V_247 ) {
F_10 ( L_22 ) ;
goto V_222;
}
if ( F_92 ( V_216 , & V_245 , & V_246 ) )
goto V_222;
F_94 (edid_ext, i, start_offset, end_offset) {
if ( F_90 ( & V_216 [ V_2 ] ) == V_240 ) {
V_247 = true ;
for ( V_40 = 1 ; V_40 < F_89 ( & V_216 [ V_2 ] ) + 1 ; V_40 += 3 )
F_10 ( L_23 ,
( V_216 [ V_2 + V_40 ] >> 3 ) & 0xf ) ;
goto V_222;
}
}
V_222:
return V_247 ;
}
bool F_104 ( struct V_8 * V_8 )
{
T_1 * V_216 ;
int V_2 , V_22 , V_222 ;
V_216 = F_85 ( V_8 ) ;
if ( ! V_216 )
return false ;
if ( F_92 ( V_216 , & V_22 , & V_222 ) )
return false ;
F_94 (edid_ext, i, start, end) {
if ( F_90 ( & V_216 [ V_2 ] ) == V_249 &&
F_89 ( & V_216 [ V_2 ] ) == 2 ) {
F_10 ( L_24 , V_216 [ V_2 + 2 ] ) ;
return V_216 [ V_2 + 2 ] & V_250 ;
}
}
return false ;
}
static void F_105 ( struct V_8 * V_8 ,
struct V_251 * V_252 )
{
T_1 * V_216 ;
V_252 -> V_161 = V_8 -> V_168 * 10 ;
V_252 -> V_164 = V_8 -> V_169 * 10 ;
V_252 -> V_253 = 0 ;
V_252 -> V_254 = 0 ;
if ( V_8 -> V_13 < 3 )
return;
if ( ! ( V_8 -> V_96 & V_97 ) )
return;
V_216 = F_85 ( V_8 ) ;
if ( V_216 ) {
V_252 -> V_255 = V_216 [ 1 ] ;
V_252 -> V_254 = V_256 ;
if ( V_216 [ 3 ] & V_257 )
V_252 -> V_254 |= V_258 ;
if ( V_216 [ 3 ] & V_259 )
V_252 -> V_254 |= V_260 ;
}
if ( V_8 -> V_13 < 4 )
return;
switch ( V_8 -> V_96 & V_261 ) {
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
if ( V_8 -> V_98 & V_269 )
V_252 -> V_254 |= V_258 ;
if ( V_8 -> V_98 & V_270 )
V_252 -> V_254 |= V_260 ;
}
int F_106 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_271 = 0 ;
T_2 V_57 ;
if ( V_8 == NULL ) {
return 0 ;
}
if ( ! F_7 ( V_8 ) ) {
F_16 ( V_39 -> V_50 -> V_50 , L_25 ,
F_17 ( V_39 ) ) ;
return 0 ;
}
V_57 = F_22 ( V_8 ) ;
V_271 += F_84 ( V_39 , V_8 , V_57 ) ;
V_271 += F_82 ( V_39 , V_8 ) ;
V_271 += F_79 ( V_39 , V_8 ) ;
V_271 += F_77 ( V_39 , V_8 ) ;
if ( V_8 -> V_98 & V_99 )
V_271 += F_74 ( V_39 , V_8 ) ;
V_271 += F_93 ( V_39 , V_8 ) ;
if ( V_57 & ( V_64 | V_65 ) )
F_25 ( V_39 , V_57 ) ;
F_105 ( V_8 , & V_39 -> V_272 ) ;
return V_271 ;
}
int F_107 ( struct V_38 * V_39 ,
int V_70 , int V_74 )
{
int V_2 , V_273 , V_271 = 0 ;
struct V_58 * V_68 ;
struct V_75 * V_50 = V_39 -> V_50 ;
V_273 = sizeof( V_80 ) / sizeof( struct V_58 ) ;
if ( V_70 < 0 )
V_70 = 0 ;
if ( V_74 < 0 )
V_74 = 0 ;
for ( V_2 = 0 ; V_2 < V_273 ; V_2 ++ ) {
const struct V_58 * V_81 = & V_80 [ V_2 ] ;
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
int
F_108 ( struct V_274 * V_275 ,
const struct V_58 * V_68 )
{
int V_276 ;
if ( ! V_275 || ! V_68 )
return - V_277 ;
V_276 = F_109 ( V_275 ) ;
if ( V_276 < 0 )
return V_276 ;
V_275 -> V_278 = F_86 ( V_68 ) ;
if ( ! V_275 -> V_278 )
return 0 ;
V_275 -> V_279 = V_280 ;
V_275 -> V_281 = V_282 ;
return 0 ;
}
