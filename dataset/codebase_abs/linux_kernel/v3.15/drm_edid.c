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
struct V_8 * F_22 ( const struct V_8 * V_8 )
{
return F_23 ( V_8 , ( V_8 -> V_17 + 1 ) * V_11 , V_46 ) ;
}
static bool F_24 ( struct V_8 * V_8 , char * V_51 )
{
char F_24 [ 3 ] ;
F_24 [ 0 ] = ( ( V_8 -> V_52 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_24 [ 1 ] = ( ( ( V_8 -> V_52 [ 0 ] & 0x3 ) << 3 ) |
( ( V_8 -> V_52 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_24 [ 2 ] = ( V_8 -> V_52 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_24 , V_51 , 3 ) ;
}
static T_2 F_25 ( struct V_8 * V_8 )
{
struct V_53 * V_54 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_26 ( V_55 ) ; V_2 ++ ) {
V_54 = & V_55 [ V_2 ] ;
if ( F_24 ( V_8 , V_54 -> V_51 ) &&
( F_27 ( V_8 ) == V_54 -> V_56 ) )
return V_54 -> V_57 ;
}
return 0 ;
}
static void F_28 ( struct V_38 * V_39 ,
T_2 V_57 )
{
struct V_58 * V_59 , * V_60 , * V_61 ;
int V_62 = 0 ;
int V_63 , V_64 ;
if ( F_29 ( & V_39 -> V_65 ) )
return;
if ( V_57 & V_66 )
V_62 = 60 ;
if ( V_57 & V_67 )
V_62 = 75 ;
V_61 = F_30 ( & V_39 -> V_65 ,
struct V_58 , V_68 ) ;
F_31 (cur_mode, t, &connector->probed_modes, head) {
V_60 -> type &= ~ V_69 ;
if ( V_60 == V_61 )
continue;
if ( F_32 ( V_60 ) > F_32 ( V_61 ) )
V_61 = V_60 ;
V_63 = V_60 -> V_70 ?
V_60 -> V_70 : F_33 ( V_60 ) ;
V_64 = V_61 -> V_70 ?
V_61 -> V_70 : F_33 ( V_61 ) ;
if ( ( F_32 ( V_60 ) == F_32 ( V_61 ) ) &&
F_34 ( V_63 , V_62 ) <
F_34 ( V_64 , V_62 ) ) {
V_61 = V_60 ;
}
}
V_61 -> type |= V_69 ;
}
static bool
F_35 ( const struct V_58 * V_71 )
{
return ( V_71 -> V_72 - V_71 -> V_73 == 160 ) &&
( V_71 -> V_74 - V_71 -> V_73 == 80 ) &&
( V_71 -> V_74 - V_71 -> V_75 == 32 ) &&
( V_71 -> V_76 - V_71 -> V_77 == 3 ) ;
}
struct V_58 * F_36 ( struct V_78 * V_50 ,
int V_79 , int V_80 , int V_81 ,
bool V_82 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_26 ( V_83 ) ; V_2 ++ ) {
const struct V_58 * V_84 = & V_83 [ V_2 ] ;
if ( V_79 != V_84 -> V_73 )
continue;
if ( V_80 != V_84 -> V_77 )
continue;
if ( V_81 != F_33 ( V_84 ) )
continue;
if ( V_82 != F_35 ( V_84 ) )
continue;
return F_37 ( V_50 , V_84 ) ;
}
return NULL ;
}
static void
F_38 ( T_1 * V_85 , T_3 * V_86 , void * V_87 )
{
int V_2 , V_88 = 0 ;
T_1 V_89 = V_85 [ 0x02 ] ;
T_1 * V_90 = V_85 + V_89 ;
V_88 = ( 127 - V_89 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_88 ; V_2 ++ )
V_86 ( (struct V_91 * ) ( V_90 + 18 * V_2 ) , V_87 ) ;
}
static void
F_39 ( T_1 * V_85 , T_3 * V_86 , void * V_87 )
{
unsigned int V_2 , V_88 = F_40 ( ( int ) V_85 [ 0x02 ] , 6 ) ;
T_1 * V_90 = V_85 + 5 ;
if ( V_85 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_88 ; V_2 ++ )
V_86 ( (struct V_91 * ) ( V_90 + 18 * V_2 ) , V_87 ) ;
}
static void
F_41 ( T_1 * V_1 , T_3 * V_86 , void * V_87 )
{
int V_2 ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
if ( V_8 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_92 ; V_2 ++ )
V_86 ( & ( V_8 -> V_93 [ V_2 ] ) , V_87 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_85 = V_1 + ( V_2 * V_11 ) ;
switch ( * V_85 ) {
case V_94 :
F_38 ( V_85 , V_86 , V_87 ) ;
break;
case V_95 :
F_39 ( V_85 , V_86 , V_87 ) ;
break;
default:
break;
}
}
}
static void
F_42 ( struct V_91 * V_59 , void * V_96 )
{
T_1 * V_97 = ( T_1 * ) V_59 ;
if ( V_97 [ 3 ] == V_98 )
if ( V_97 [ 15 ] & 0x10 )
* ( bool * ) V_96 = true ;
}
static bool
F_43 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 4 ) {
bool V_25 = false ;
F_41 ( ( T_1 * ) V_8 , F_42 , & V_25 ) ;
return V_25 ;
}
return ( ( V_8 -> V_99 & V_100 ) != 0 ) ;
}
static void
F_44 ( struct V_91 * V_59 , void * V_96 )
{
T_1 * V_97 = ( T_1 * ) V_59 ;
if ( V_97 [ 3 ] == V_98 && V_97 [ 10 ] == 0x02 )
* ( T_1 * * ) V_96 = V_97 ;
}
static int
F_45 ( struct V_8 * V_8 )
{
T_1 * V_97 = NULL ;
F_41 ( ( T_1 * ) V_8 , F_44 , & V_97 ) ;
return V_97 ? ( V_97 [ 12 ] * 2 ) : 0 ;
}
static int
F_46 ( struct V_8 * V_8 )
{
T_1 * V_97 = NULL ;
F_41 ( ( T_1 * ) V_8 , F_44 , & V_97 ) ;
return V_97 ? V_97 [ 13 ] : 0 ;
}
static int
F_47 ( struct V_8 * V_8 )
{
T_1 * V_97 = NULL ;
F_41 ( ( T_1 * ) V_8 , F_44 , & V_97 ) ;
return V_97 ? ( V_97 [ 15 ] << 8 ) + V_97 [ 14 ] : 0 ;
}
static int
F_48 ( struct V_8 * V_8 )
{
T_1 * V_97 = NULL ;
F_41 ( ( T_1 * ) V_8 , F_44 , & V_97 ) ;
return V_97 ? V_97 [ 16 ] : 0 ;
}
static int
F_49 ( struct V_8 * V_8 )
{
T_1 * V_97 = NULL ;
F_41 ( ( T_1 * ) V_8 , F_44 , & V_97 ) ;
return V_97 ? V_97 [ 17 ] : 0 ;
}
static int F_50 ( struct V_8 * V_8 )
{
if ( V_8 -> V_13 >= 2 ) {
if ( V_8 -> V_13 >= 4 && ( V_8 -> V_101 & V_102 ) )
return V_103 ;
if ( F_45 ( V_8 ) )
return V_104 ;
return V_105 ;
}
return V_106 ;
}
static int
F_51 ( T_1 V_107 , T_1 V_108 )
{
return ( V_107 == 0x00 && V_108 == 0x00 ) ||
( V_107 == 0x01 && V_108 == 0x01 ) ||
( V_107 == 0x20 && V_108 == 0x20 ) ;
}
static struct V_58 *
F_52 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_109 * V_59 , int V_13 )
{
struct V_78 * V_50 = V_39 -> V_50 ;
struct V_58 * V_110 , * V_71 = NULL ;
int V_79 , V_80 ;
int V_111 ;
unsigned V_112 = ( V_59 -> V_113 & V_114 )
>> V_115 ;
unsigned V_116 = ( V_59 -> V_113 & V_117 )
>> V_118 ;
int V_119 = F_50 ( V_8 ) ;
if ( F_51 ( V_59 -> V_79 , V_59 -> V_113 ) )
return NULL ;
V_79 = V_59 -> V_79 * 8 + 248 ;
V_111 = V_116 + 60 ;
if ( V_112 == 0 ) {
if ( V_13 < 3 )
V_80 = V_79 ;
else
V_80 = ( V_79 * 10 ) / 16 ;
} else if ( V_112 == 1 )
V_80 = ( V_79 * 3 ) / 4 ;
else if ( V_112 == 2 )
V_80 = ( V_79 * 4 ) / 5 ;
else
V_80 = ( V_79 * 9 ) / 16 ;
if ( V_111 == 60 &&
( ( V_79 == 1360 && V_80 == 765 ) ||
( V_79 == 1368 && V_80 == 769 ) ) ) {
V_79 = 1366 ;
V_80 = 768 ;
}
F_53 (m, &connector->probed_modes, head)
if ( V_110 -> V_73 == V_79 && V_110 -> V_77 == V_80 &&
F_33 ( V_110 ) == V_111 )
return NULL ;
if ( V_79 == 1366 && V_80 == 768 && V_111 == 60 ) {
V_71 = F_54 ( V_50 , 1366 , 768 , V_111 , 0 , 0 ,
false ) ;
V_71 -> V_73 = 1366 ;
V_71 -> V_75 = V_71 -> V_75 - 1 ;
V_71 -> V_74 = V_71 -> V_74 - 1 ;
return V_71 ;
}
if ( F_43 ( V_8 ) ) {
V_71 = F_36 ( V_50 , V_79 , V_80 , V_111 ,
true ) ;
if ( V_71 )
return V_71 ;
}
V_71 = F_36 ( V_50 , V_79 , V_80 , V_111 , false ) ;
if ( V_71 )
return V_71 ;
switch ( V_119 ) {
case V_106 :
break;
case V_105 :
V_71 = F_55 ( V_50 , V_79 , V_80 , V_111 , 0 , 0 ) ;
break;
case V_104 :
V_71 = F_55 ( V_50 , V_79 , V_80 , V_111 , 0 , 0 ) ;
if ( ! V_71 )
return NULL ;
if ( F_56 ( V_71 ) > F_45 ( V_8 ) ) {
F_57 ( V_50 , V_71 ) ;
V_71 = F_58 ( V_50 , V_79 , V_80 ,
V_111 , 0 , 0 ,
F_47 ( V_8 ) ,
F_46 ( V_8 ) ,
F_48 ( V_8 ) ,
F_49 ( V_8 ) ) ;
}
break;
case V_103 :
V_71 = F_54 ( V_50 , V_79 , V_80 , V_111 , 0 , 0 ,
false ) ;
break;
}
return V_71 ;
}
static void
F_59 ( struct V_58 * V_71 ,
struct V_120 * V_121 )
{
int V_2 ;
static const struct {
int V_122 , V_123 ;
} V_124 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_121 -> V_125 & V_126 ) )
return;
for ( V_2 = 0 ; V_2 < F_26 ( V_124 ) ; V_2 ++ ) {
if ( ( V_71 -> V_73 == V_124 [ V_2 ] . V_122 ) &&
( V_71 -> V_77 == V_124 [ V_2 ] . V_123 / 2 ) ) {
V_71 -> V_77 *= 2 ;
V_71 -> V_76 *= 2 ;
V_71 -> V_127 *= 2 ;
V_71 -> V_128 *= 2 ;
V_71 -> V_128 |= 1 ;
}
}
V_71 -> V_31 |= V_129 ;
}
static struct V_58 * F_60 ( struct V_78 * V_50 ,
struct V_8 * V_8 ,
struct V_91 * V_130 ,
T_2 V_57 )
{
struct V_58 * V_71 ;
struct V_120 * V_121 = & V_130 -> V_96 . V_131 ;
unsigned V_132 = ( V_121 -> V_133 & 0xf0 ) << 4 | V_121 -> V_134 ;
unsigned V_135 = ( V_121 -> V_136 & 0xf0 ) << 4 | V_121 -> V_137 ;
unsigned V_138 = ( V_121 -> V_133 & 0xf ) << 8 | V_121 -> V_139 ;
unsigned V_140 = ( V_121 -> V_136 & 0xf ) << 8 | V_121 -> V_141 ;
unsigned V_142 = ( V_121 -> V_143 & 0xc0 ) << 2 | V_121 -> V_144 ;
unsigned V_145 = ( V_121 -> V_143 & 0x30 ) << 4 | V_121 -> V_146 ;
unsigned V_147 = ( V_121 -> V_143 & 0xc ) << 2 | V_121 -> V_148 >> 4 ;
unsigned V_149 = ( V_121 -> V_143 & 0x3 ) << 4 | ( V_121 -> V_148 & 0xf ) ;
if ( V_132 < 64 || V_135 < 64 )
return NULL ;
if ( V_121 -> V_125 & V_150 ) {
F_11 ( L_10 ) ;
return NULL ;
}
if ( ! ( V_121 -> V_125 & V_151 ) ) {
F_11 ( L_11 ) ;
}
if ( ! V_145 || ! V_149 ) {
F_11 ( L_12
L_13 ) ;
return NULL ;
}
if ( V_57 & V_152 ) {
V_71 = F_54 ( V_50 , V_132 , V_135 , 60 , true , false , false ) ;
if ( ! V_71 )
return NULL ;
goto V_153;
}
V_71 = F_61 ( V_50 ) ;
if ( ! V_71 )
return NULL ;
if ( V_57 & V_154 )
V_130 -> V_155 = F_62 ( 1088 ) ;
V_71 -> clock = F_63 ( V_130 -> V_155 ) * 10 ;
V_71 -> V_73 = V_132 ;
V_71 -> V_75 = V_71 -> V_73 + V_142 ;
V_71 -> V_74 = V_71 -> V_75 + V_145 ;
V_71 -> V_72 = V_71 -> V_73 + V_138 ;
V_71 -> V_77 = V_135 ;
V_71 -> V_76 = V_71 -> V_77 + V_147 ;
V_71 -> V_127 = V_71 -> V_76 + V_149 ;
V_71 -> V_128 = V_71 -> V_77 + V_140 ;
if ( V_71 -> V_74 > V_71 -> V_72 )
V_71 -> V_72 = V_71 -> V_74 + 1 ;
if ( V_71 -> V_127 > V_71 -> V_128 )
V_71 -> V_128 = V_71 -> V_127 + 1 ;
F_59 ( V_71 , V_121 ) ;
if ( V_57 & V_156 ) {
V_121 -> V_125 |= V_157 | V_158 ;
}
V_71 -> V_31 |= ( V_121 -> V_125 & V_157 ) ?
V_159 : V_160 ;
V_71 -> V_31 |= ( V_121 -> V_125 & V_158 ) ?
V_161 : V_162 ;
V_153:
V_71 -> V_163 = V_121 -> V_164 | ( V_121 -> V_165 & 0xf0 ) << 4 ;
V_71 -> V_166 = V_121 -> V_167 | ( V_121 -> V_165 & 0xf ) << 8 ;
if ( V_57 & V_168 ) {
V_71 -> V_163 *= 10 ;
V_71 -> V_166 *= 10 ;
}
if ( V_57 & V_169 ) {
V_71 -> V_163 = V_8 -> V_170 * 10 ;
V_71 -> V_166 = V_8 -> V_171 * 10 ;
}
V_71 -> type = V_172 ;
V_71 -> V_70 = F_33 ( V_71 ) ;
F_64 ( V_71 ) ;
return V_71 ;
}
static bool
F_65 ( const struct V_58 * V_71 ,
struct V_8 * V_8 , T_1 * V_59 )
{
int V_173 , V_174 , V_175 ;
V_174 = V_59 [ 7 ] ;
if ( V_8 -> V_13 >= 4 )
V_174 += ( ( V_59 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_175 = V_59 [ 8 ] ;
if ( V_8 -> V_13 >= 4 )
V_175 += ( ( V_59 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_173 = F_56 ( V_71 ) ;
return ( V_173 <= V_175 && V_173 >= V_174 ) ;
}
static bool
F_66 ( const struct V_58 * V_71 ,
struct V_8 * V_8 , T_1 * V_59 )
{
int V_176 , V_177 , V_178 ;
V_177 = V_59 [ 5 ] ;
if ( V_8 -> V_13 >= 4 )
V_177 += ( ( V_59 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_178 = V_59 [ 6 ] ;
if ( V_8 -> V_13 >= 4 )
V_178 += ( ( V_59 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_176 = F_33 ( V_71 ) ;
return ( V_176 <= V_178 && V_176 >= V_177 ) ;
}
static T_2
F_67 ( struct V_8 * V_8 , T_1 * V_59 )
{
if ( V_59 [ 9 ] == 0 || V_59 [ 9 ] == 255 )
return 0 ;
if ( V_8 -> V_13 >= 4 && V_59 [ 10 ] == 0x04 )
return ( V_59 [ 9 ] * 10000 ) - ( ( V_59 [ 12 ] >> 2 ) * 250 ) ;
return V_59 [ 9 ] * 10000 + 5001 ;
}
static bool
F_68 ( const struct V_58 * V_71 , struct V_8 * V_8 ,
struct V_91 * V_130 )
{
T_2 V_179 ;
T_1 * V_59 = ( T_1 * ) V_130 ;
if ( ! F_65 ( V_71 , V_8 , V_59 ) )
return false ;
if ( ! F_66 ( V_71 , V_8 , V_59 ) )
return false ;
if ( ( V_179 = F_67 ( V_8 , V_59 ) ) )
if ( V_71 -> clock > V_179 )
return false ;
if ( V_8 -> V_13 >= 4 && V_59 [ 10 ] == 0x04 )
if ( V_59 [ 13 ] && V_71 -> V_73 > 8 * ( V_59 [ 13 ] + ( 256 * ( V_59 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_35 ( V_71 ) && ! F_43 ( V_8 ) )
return false ;
return true ;
}
static bool F_69 ( const struct V_38 * V_39 ,
const struct V_58 * V_71 )
{
struct V_58 * V_110 ;
bool V_180 = false ;
F_53 (m, &connector->probed_modes, head) {
if ( V_71 -> V_73 == V_110 -> V_73 &&
V_71 -> V_77 == V_110 -> V_77 &&
F_33 ( V_71 ) == F_33 ( V_110 ) )
return false ;
if ( V_71 -> V_73 <= V_110 -> V_73 &&
V_71 -> V_77 <= V_110 -> V_77 )
V_180 = true ;
}
return V_180 ;
}
static int
F_70 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_91 * V_130 )
{
int V_2 , V_181 = 0 ;
struct V_58 * V_182 ;
struct V_78 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < F_26 ( V_83 ) ; V_2 ++ ) {
if ( F_68 ( V_83 + V_2 , V_8 , V_130 ) &&
F_69 ( V_39 , V_83 + V_2 ) ) {
V_182 = F_37 ( V_50 , & V_83 [ V_2 ] ) ;
if ( V_182 ) {
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
}
return V_181 ;
}
static void F_72 ( struct V_58 * V_71 )
{
if ( V_71 -> V_73 == 1368 && V_71 -> V_77 == 768 ) {
V_71 -> V_73 = 1366 ;
V_71 -> V_75 -- ;
V_71 -> V_74 -- ;
F_64 ( V_71 ) ;
}
}
static int
F_73 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_91 * V_130 )
{
int V_2 , V_181 = 0 ;
struct V_58 * V_182 ;
struct V_78 * V_50 = V_39 -> V_50 ;
for ( V_2 = 0 ; V_2 < F_26 ( V_183 ) ; V_2 ++ ) {
const struct V_184 * V_110 = & V_183 [ V_2 ] ;
V_182 = F_55 ( V_50 , V_110 -> V_122 , V_110 -> V_123 , V_110 -> V_97 , 0 , 0 ) ;
if ( ! V_182 )
return V_181 ;
F_72 ( V_182 ) ;
if ( ! F_68 ( V_182 , V_8 , V_130 ) ||
! F_69 ( V_39 , V_182 ) ) {
F_57 ( V_50 , V_182 ) ;
continue;
}
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
return V_181 ;
}
static int
F_74 ( struct V_38 * V_39 , struct V_8 * V_8 ,
struct V_91 * V_130 )
{
int V_2 , V_181 = 0 ;
struct V_58 * V_182 ;
struct V_78 * V_50 = V_39 -> V_50 ;
bool V_82 = F_43 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < F_26 ( V_183 ) ; V_2 ++ ) {
const struct V_184 * V_110 = & V_183 [ V_2 ] ;
V_182 = F_54 ( V_50 , V_110 -> V_122 , V_110 -> V_123 , V_110 -> V_97 , V_82 , 0 , 0 ) ;
if ( ! V_182 )
return V_181 ;
F_72 ( V_182 ) ;
if ( ! F_68 ( V_182 , V_8 , V_130 ) ||
! F_69 ( V_39 , V_182 ) ) {
F_57 ( V_50 , V_182 ) ;
continue;
}
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
return V_181 ;
}
static void
F_75 ( struct V_91 * V_130 , void * V_185 )
{
struct V_186 * V_87 = V_185 ;
struct V_187 * V_96 = & V_130 -> V_96 . V_188 ;
struct V_189 * V_190 = & V_96 -> V_96 . V_190 ;
if ( V_96 -> type != V_98 )
return;
V_87 -> V_181 += F_70 ( V_87 -> V_39 ,
V_87 -> V_8 ,
V_130 ) ;
if ( ! F_76 ( V_87 -> V_8 , 1 , 1 ) )
return;
switch ( V_190 -> V_31 ) {
case 0x02 :
case 0x00 :
V_87 -> V_181 += F_73 ( V_87 -> V_39 ,
V_87 -> V_8 ,
V_130 ) ;
break;
case 0x04 :
if ( ! F_76 ( V_87 -> V_8 , 1 , 3 ) )
break;
V_87 -> V_181 += F_74 ( V_87 -> V_39 ,
V_87 -> V_8 ,
V_130 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_77 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_186 V_87 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_76 ( V_8 , 1 , 0 ) )
F_41 ( ( T_1 * ) V_8 , F_75 ,
& V_87 ) ;
return V_87 . V_181 ;
}
static int
F_78 ( struct V_38 * V_39 , struct V_91 * V_130 )
{
int V_2 , V_40 , V_110 , V_181 = 0 ;
struct V_58 * V_71 ;
T_1 * V_191 = ( ( T_1 * ) V_130 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_40 = 7 ; V_40 >= 0 ; V_40 -- ) {
V_110 = ( V_2 * 8 ) + ( 7 - V_40 ) ;
if ( V_110 >= F_26 ( V_192 ) )
break;
if ( V_191 [ V_2 ] & ( 1 << V_40 ) ) {
V_71 = F_36 ( V_39 -> V_50 ,
V_192 [ V_110 ] . V_122 ,
V_192 [ V_110 ] . V_123 ,
V_192 [ V_110 ] . V_97 ,
V_192 [ V_110 ] . V_82 ) ;
if ( V_71 ) {
F_71 ( V_39 , V_71 ) ;
V_181 ++ ;
}
}
}
}
return V_181 ;
}
static void
F_79 ( struct V_91 * V_130 , void * V_185 )
{
struct V_186 * V_87 = V_185 ;
struct V_187 * V_96 = & V_130 -> V_96 . V_188 ;
if ( V_96 -> type == V_193 )
V_87 -> V_181 += F_78 ( V_87 -> V_39 , V_130 ) ;
}
static int
F_80 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_78 * V_50 = V_39 -> V_50 ;
unsigned long V_194 = V_8 -> V_195 . V_196 |
( V_8 -> V_195 . V_197 << 8 ) |
( ( V_8 -> V_195 . V_198 & 0x80 ) << 9 ) ;
int V_2 , V_181 = 0 ;
struct V_186 V_87 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_199 ; V_2 ++ ) {
if ( V_194 & ( 1 << V_2 ) ) {
struct V_58 * V_182 ;
V_182 = F_37 ( V_50 , & V_200 [ V_2 ] ) ;
if ( V_182 ) {
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
}
if ( F_76 ( V_8 , 1 , 0 ) )
F_41 ( ( T_1 * ) V_8 ,
F_79 , & V_87 ) ;
return V_181 + V_87 . V_181 ;
}
static void
F_81 ( struct V_91 * V_130 , void * V_185 )
{
struct V_186 * V_87 = V_185 ;
struct V_187 * V_96 = & V_130 -> V_96 . V_188 ;
struct V_38 * V_39 = V_87 -> V_39 ;
struct V_8 * V_8 = V_87 -> V_8 ;
if ( V_96 -> type == V_201 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_109 * V_202 ;
struct V_58 * V_182 ;
V_202 = & V_96 -> V_96 . V_203 [ V_2 ] ;
V_182 = F_52 ( V_39 , V_8 , V_202 ,
V_8 -> V_13 ) ;
if ( V_182 ) {
F_71 ( V_39 , V_182 ) ;
V_87 -> V_181 ++ ;
}
}
}
}
static int
F_82 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_2 , V_181 = 0 ;
struct V_186 V_87 = {
V_39 , V_8 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_204 ; V_2 ++ ) {
struct V_58 * V_182 ;
V_182 = F_52 ( V_39 , V_8 ,
& V_8 -> V_205 [ V_2 ] ,
V_8 -> V_13 ) ;
if ( V_182 ) {
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
if ( F_76 ( V_8 , 1 , 0 ) )
F_41 ( ( T_1 * ) V_8 , F_81 ,
& V_87 ) ;
return V_181 + V_87 . V_181 ;
}
static int F_83 ( struct V_38 * V_39 ,
struct V_91 * V_130 )
{
int V_2 , V_40 , V_181 = 0 ;
struct V_58 * V_182 ;
struct V_78 * V_50 = V_39 -> V_50 ;
struct V_206 * V_207 ;
const int V_208 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_209 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_210 ( V_211 ) , V_212 ;
V_207 = & ( V_130 -> V_96 . V_188 . V_96 . V_207 [ V_2 ] ) ;
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
V_182 = F_54 ( V_50 , V_211 , V_212 ,
V_208 [ V_40 ] , V_40 == 0 ,
false , false ) ;
if ( V_182 ) {
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
}
}
return V_181 ;
}
static void
F_84 ( struct V_91 * V_130 , void * V_185 )
{
struct V_186 * V_87 = V_185 ;
struct V_187 * V_96 = & V_130 -> V_96 . V_188 ;
if ( V_96 -> type == V_214 )
V_87 -> V_181 += F_83 ( V_87 -> V_39 , V_130 ) ;
}
static int
F_85 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_186 V_87 = {
V_39 , V_8 , 0 , 0 , 0
} ;
if ( F_76 ( V_8 , 1 , 2 ) )
F_41 ( ( T_1 * ) V_8 , F_84 , & V_87 ) ;
return V_87 . V_181 ;
}
static void
F_86 ( struct V_91 * V_130 , void * V_185 )
{
struct V_186 * V_87 = V_185 ;
struct V_58 * V_182 ;
if ( V_130 -> V_155 ) {
V_182 = F_60 ( V_87 -> V_39 -> V_50 ,
V_87 -> V_8 , V_130 ,
V_87 -> V_57 ) ;
if ( ! V_182 )
return;
if ( V_87 -> V_215 )
V_182 -> type |= V_69 ;
F_71 ( V_87 -> V_39 , V_182 ) ;
V_87 -> V_181 ++ ;
V_87 -> V_215 = 0 ;
}
}
static int
F_87 ( struct V_38 * V_39 , struct V_8 * V_8 ,
T_2 V_57 )
{
struct V_186 V_87 = {
V_39 ,
V_8 ,
1 ,
V_57 ,
0
} ;
if ( V_87 . V_215 && ! F_76 ( V_8 , 1 , 3 ) )
V_87 . V_215 =
( V_8 -> V_101 & V_216 ) ;
F_41 ( ( T_1 * ) V_8 , F_86 , & V_87 ) ;
return V_87 . V_181 ;
}
static T_1 * F_88 ( struct V_8 * V_8 )
{
T_1 * V_217 = NULL ;
int V_2 ;
if ( V_8 == NULL || V_8 -> V_17 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_8 -> V_17 ; V_2 ++ ) {
V_217 = ( T_1 * ) V_8 + V_11 * ( V_2 + 1 ) ;
if ( V_217 [ 0 ] == V_94 )
break;
}
if ( V_2 == V_8 -> V_17 )
return NULL ;
return V_217 ;
}
static unsigned int
F_89 ( const struct V_58 * V_218 )
{
unsigned int clock = V_218 -> clock ;
if ( V_218 -> V_70 % 6 != 0 )
return clock ;
if ( V_218 -> V_77 == 240 || V_218 -> V_77 == 480 )
clock = clock * 1001 / 1000 ;
else
clock = F_90 ( clock * 1000 , 1001 ) ;
return clock ;
}
T_1 F_91 ( const struct V_58 * V_219 )
{
T_1 V_71 ;
if ( ! V_219 -> clock )
return 0 ;
for ( V_71 = 0 ; V_71 < F_26 ( V_220 ) ; V_71 ++ ) {
const struct V_58 * V_218 = & V_220 [ V_71 ] ;
unsigned int V_221 , V_222 ;
V_221 = V_218 -> clock ;
V_222 = F_89 ( V_218 ) ;
if ( ( F_92 ( V_219 -> clock ) == F_92 ( V_221 ) ||
F_92 ( V_219 -> clock ) == F_92 ( V_222 ) ) &&
F_93 ( V_219 , V_218 ) )
return V_71 + 1 ;
}
return 0 ;
}
static unsigned int
F_94 ( const struct V_58 * V_223 )
{
if ( V_223 -> V_77 == 4096 && V_223 -> V_73 == 2160 )
return V_223 -> clock ;
return F_89 ( V_223 ) ;
}
static T_1 F_95 ( const struct V_58 * V_219 )
{
T_1 V_71 ;
if ( ! V_219 -> clock )
return 0 ;
for ( V_71 = 0 ; V_71 < F_26 ( V_224 ) ; V_71 ++ ) {
const struct V_58 * V_223 = & V_224 [ V_71 ] ;
unsigned int V_221 , V_222 ;
V_221 = V_223 -> clock ;
V_222 = F_94 ( V_223 ) ;
if ( ( F_92 ( V_219 -> clock ) == F_92 ( V_221 ) ||
F_92 ( V_219 -> clock ) == F_92 ( V_222 ) ) &&
F_93 ( V_219 , V_223 ) )
return V_71 + 1 ;
}
return 0 ;
}
static int
F_96 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
struct V_78 * V_50 = V_39 -> V_50 ;
struct V_58 * V_71 , * V_225 ;
F_97 ( V_226 ) ;
int V_181 = 0 ;
if ( ! F_88 ( V_8 ) )
return 0 ;
F_53 (mode, &connector->probed_modes, head) {
const struct V_58 * V_218 = NULL ;
struct V_58 * V_182 ;
T_1 V_227 = F_91 ( V_71 ) - 1 ;
unsigned int V_221 , V_222 ;
if ( V_227 < F_26 ( V_220 ) ) {
V_218 = & V_220 [ V_227 ] ;
V_222 = F_89 ( V_218 ) ;
} else {
V_227 = F_95 ( V_71 ) - 1 ;
if ( V_227 < F_26 ( V_224 ) ) {
V_218 = & V_224 [ V_227 ] ;
V_222 = F_94 ( V_218 ) ;
}
}
if ( ! V_218 )
continue;
V_221 = V_218 -> clock ;
if ( V_221 == V_222 )
continue;
if ( V_71 -> clock != V_221 && V_71 -> clock != V_222 )
continue;
V_182 = F_37 ( V_50 , V_218 ) ;
if ( ! V_182 )
continue;
V_182 -> V_31 |= V_71 -> V_31 & V_228 ;
if ( V_71 -> clock != V_221 )
V_182 -> clock = V_221 ;
else
V_182 -> clock = V_222 ;
F_98 ( & V_182 -> V_68 , & V_226 ) ;
}
F_31 (mode, tmp, &list, head) {
F_99 ( & V_71 -> V_68 ) ;
F_71 ( V_39 , V_71 ) ;
V_181 ++ ;
}
return V_181 ;
}
static struct V_58 *
F_100 ( struct V_38 * V_39 ,
const T_1 * V_229 , T_1 V_230 ,
T_1 V_231 )
{
struct V_78 * V_50 = V_39 -> V_50 ;
struct V_58 * V_182 ;
T_1 V_218 ;
if ( V_229 == NULL || V_231 >= V_230 )
return NULL ;
V_218 = ( V_229 [ V_231 ] & 127 ) - 1 ;
if ( V_218 >= F_26 ( V_220 ) )
return NULL ;
V_182 = F_37 ( V_50 , & V_220 [ V_218 ] ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_70 = 0 ;
return V_182 ;
}
static int
F_101 ( struct V_38 * V_39 , const T_1 * V_232 , T_1 V_21 )
{
int V_2 , V_181 = 0 ;
for ( V_2 = 0 ; V_2 < V_21 ; V_2 ++ ) {
struct V_58 * V_71 ;
V_71 = F_100 ( V_39 , V_232 , V_21 , V_2 ) ;
if ( V_71 ) {
F_71 ( V_39 , V_71 ) ;
V_181 ++ ;
}
}
return V_181 ;
}
static bool
F_102 ( const struct V_58 * V_71 ,
const struct V_233 * V_234 )
{
unsigned int V_235 = V_71 -> V_31 & V_129 ;
return V_71 -> V_73 == V_234 -> V_211 &&
V_71 -> V_77 == V_234 -> V_212 &&
V_235 == ( V_234 -> V_31 & V_129 ) &&
F_33 ( V_71 ) == V_234 -> V_70 ;
}
static int F_103 ( struct V_38 * V_39 )
{
struct V_78 * V_50 = V_39 -> V_50 ;
const struct V_58 * V_71 ;
struct V_236 V_237 ;
int V_181 = 0 , V_2 ;
F_104 ( & V_237 ) ;
F_53 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_26 ( V_238 ) ; V_2 ++ ) {
const struct V_233 * V_239 ;
struct V_58 * V_240 ;
if ( ! F_102 ( V_71 ,
& V_238 [ V_2 ] ) )
continue;
V_239 = & V_238 [ V_2 ] ;
V_240 = F_37 ( V_50 , V_71 ) ;
if ( ! V_240 )
continue;
V_240 -> V_31 |= V_239 -> V_31 ;
F_98 ( & V_240 -> V_68 , & V_237 ) ;
V_181 ++ ;
}
}
F_105 ( & V_237 , & V_39 -> V_65 ) ;
return V_181 ;
}
static int F_106 ( struct V_38 * V_39 , T_1 V_241 )
{
struct V_78 * V_50 = V_39 -> V_50 ;
struct V_58 * V_182 ;
V_241 -- ;
if ( V_241 >= F_26 ( V_224 ) ) {
F_5 ( L_14 , V_241 ) ;
return 0 ;
}
V_182 = F_37 ( V_50 , & V_224 [ V_241 ] ) ;
if ( ! V_182 )
return 0 ;
F_71 ( V_39 , V_182 ) ;
return 1 ;
}
static int F_107 ( struct V_38 * V_39 , T_4 V_242 ,
const T_1 * V_229 , T_1 V_230 , T_1 V_231 )
{
struct V_58 * V_182 ;
int V_181 = 0 ;
if ( V_242 & ( 1 << 0 ) ) {
V_182 = F_100 ( V_39 , V_229 ,
V_230 ,
V_231 ) ;
if ( V_182 ) {
V_182 -> V_31 |= V_243 ;
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
if ( V_242 & ( 1 << 6 ) ) {
V_182 = F_100 ( V_39 , V_229 ,
V_230 ,
V_231 ) ;
if ( V_182 ) {
V_182 -> V_31 |= V_244 ;
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
if ( V_242 & ( 1 << 8 ) ) {
V_182 = F_100 ( V_39 , V_229 ,
V_230 ,
V_231 ) ;
if ( V_182 ) {
V_182 -> V_31 |= V_245 ;
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
return V_181 ;
}
static int
F_108 ( struct V_38 * V_39 , const T_1 * V_232 , T_1 V_21 ,
const T_1 * V_229 , T_1 V_230 )
{
int V_181 = 0 , V_246 = 0 , V_2 , V_247 = 0 , V_248 ;
T_1 V_249 , V_250 = 0 ;
T_4 V_251 ;
T_4 V_252 ;
if ( V_21 < 8 )
goto V_47;
if ( ! ( V_232 [ 8 ] & ( 1 << 5 ) ) )
goto V_47;
if ( V_232 [ 8 ] & ( 1 << 7 ) )
V_246 += 2 ;
if ( V_232 [ 8 ] & ( 1 << 6 ) )
V_246 += 2 ;
if ( V_21 < ( 8 + V_246 + 2 ) )
goto V_47;
V_246 ++ ;
if ( V_232 [ 8 + V_246 ] & ( 1 << 7 ) ) {
V_181 += F_103 ( V_39 ) ;
V_247 = ( V_232 [ 8 + V_246 ] & 0x60 ) >> 5 ;
}
V_246 ++ ;
V_249 = V_232 [ 8 + V_246 ] >> 5 ;
V_250 = V_232 [ 8 + V_246 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_249 && V_21 >= ( 9 + V_246 + V_2 ) ; V_2 ++ ) {
T_1 V_241 ;
V_241 = V_232 [ 9 + V_246 + V_2 ] ;
V_181 += F_106 ( V_39 , V_241 ) ;
}
V_246 += 1 + V_249 ;
if ( V_247 == 1 )
V_248 = 2 ;
else if ( V_247 == 2 )
V_248 = 4 ;
else
V_248 = 0 ;
if ( V_21 < ( 8 + V_246 + V_250 - 1 ) )
goto V_47;
if ( V_250 < V_248 )
goto V_47;
if ( V_247 == 1 || V_247 == 2 ) {
V_252 = ( V_232 [ 8 + V_246 ] << 8 ) | V_232 [ 9 + V_246 ] ;
if ( V_247 == 2 )
V_251 = ( V_232 [ 10 + V_246 ] << 8 ) | V_232 [ 11 + V_246 ] ;
else
V_251 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_251 & ( 1 << V_2 ) )
V_181 += F_107 ( V_39 ,
V_252 ,
V_229 ,
V_230 , V_2 ) ;
}
}
V_246 += V_248 ;
for ( V_2 = 0 ; V_2 < ( V_250 - V_248 ) ; V_2 ++ ) {
int V_253 ;
struct V_58 * V_182 = NULL ;
unsigned int V_254 = 0 ;
bool V_255 ;
V_255 = ( ( V_232 [ 8 + V_246 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_255 && ( V_2 + 1 == V_250 - V_248 ) )
break;
V_253 = V_232 [ 8 + V_246 + V_2 ] >> 4 ;
switch ( V_232 [ 8 + V_246 + V_2 ] & 0x0f ) {
case 0 :
V_254 = V_243 ;
break;
case 6 :
V_254 = V_244 ;
break;
case 8 :
if ( ( V_232 [ 9 + V_246 + V_2 ] >> 4 ) == 1 )
V_254 = V_245 ;
break;
}
if ( V_254 != 0 ) {
V_182 = F_100 ( V_39 ,
V_229 ,
V_230 ,
V_253 ) ;
if ( V_182 ) {
V_182 -> V_31 |= V_254 ;
F_71 ( V_39 , V_182 ) ;
V_181 ++ ;
}
}
if ( V_255 )
V_2 ++ ;
}
V_47:
return V_181 ;
}
static int
F_109 ( const T_1 * V_232 )
{
return V_232 [ 0 ] & 0x1f ;
}
static int
F_110 ( const T_1 * V_232 )
{
return V_232 [ 0 ] >> 5 ;
}
static int
F_111 ( const T_1 * V_256 )
{
return V_256 [ 1 ] ;
}
static int
F_112 ( const T_1 * V_256 , int * V_22 , int * V_257 )
{
* V_22 = 4 ;
* V_257 = V_256 [ 2 ] ;
if ( * V_257 == 0 )
* V_257 = 127 ;
if ( * V_257 < 4 || * V_257 > 127 )
return - V_258 ;
return 0 ;
}
static bool F_113 ( const T_1 * V_232 )
{
int V_259 ;
if ( F_110 ( V_232 ) != V_260 )
return false ;
if ( F_109 ( V_232 ) < 5 )
return false ;
V_259 = V_232 [ 1 ] | ( V_232 [ 2 ] << 8 ) | ( V_232 [ 3 ] << 16 ) ;
return V_259 == V_261 ;
}
static int
F_114 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
const T_1 * V_256 = F_88 ( V_8 ) ;
const T_1 * V_232 , * V_262 = NULL , * V_263 = NULL ;
T_1 V_264 , V_265 , V_230 = 0 ;
int V_181 = 0 ;
if ( V_256 && F_111 ( V_256 ) >= 3 ) {
int V_2 , V_22 , V_257 ;
if ( F_112 ( V_256 , & V_22 , & V_257 ) )
return 0 ;
F_115 (cea, i, start, end) {
V_232 = & V_256 [ V_2 ] ;
V_264 = F_109 ( V_232 ) ;
if ( F_110 ( V_232 ) == V_266 ) {
V_263 = V_232 + 1 ;
V_230 = V_264 ;
V_181 += F_101 ( V_39 , V_263 , V_264 ) ;
}
else if ( F_113 ( V_232 ) ) {
V_262 = V_232 ;
V_265 = V_264 ;
}
}
}
if ( V_262 )
V_181 += F_108 ( V_39 , V_262 , V_265 , V_263 ,
V_230 ) ;
return V_181 ;
}
static void
F_116 ( struct V_38 * V_39 , const T_1 * V_232 )
{
T_1 V_21 = F_109 ( V_232 ) ;
if ( V_21 >= 6 ) {
V_39 -> V_267 [ 5 ] |= ( V_232 [ 6 ] >> 7 ) << 1 ;
V_39 -> V_268 = V_232 [ 6 ] & 1 ;
}
if ( V_21 >= 7 )
V_39 -> V_269 = V_232 [ 7 ] * 5 ;
if ( V_21 >= 8 ) {
V_39 -> V_270 [ 0 ] = V_232 [ 8 ] >> 7 ;
V_39 -> V_270 [ 1 ] = ( V_232 [ 8 ] >> 6 ) & 1 ;
}
if ( V_21 >= 9 )
V_39 -> V_271 [ 0 ] = V_232 [ 9 ] ;
if ( V_21 >= 10 )
V_39 -> V_272 [ 0 ] = V_232 [ 10 ] ;
if ( V_21 >= 11 )
V_39 -> V_271 [ 1 ] = V_232 [ 11 ] ;
if ( V_21 >= 12 )
V_39 -> V_272 [ 1 ] = V_232 [ 12 ] ;
F_11 ( L_15
L_16
L_17
L_18
L_19 ,
V_39 -> V_268 ,
V_39 -> V_269 ,
( int ) V_39 -> V_270 [ 0 ] ,
( int ) V_39 -> V_270 [ 1 ] ,
V_39 -> V_271 [ 0 ] ,
V_39 -> V_271 [ 1 ] ,
V_39 -> V_272 [ 0 ] ,
V_39 -> V_272 [ 1 ] ) ;
}
static void
F_117 ( struct V_91 * V_59 , void * V_96 )
{
if ( V_59 -> V_96 . V_188 . type == V_273 )
* ( T_1 * * ) V_96 = V_59 -> V_96 . V_188 . V_96 . V_274 . V_274 ;
}
void F_118 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
T_5 * V_267 = V_39 -> V_267 ;
T_1 * V_256 ;
T_1 * V_35 ;
T_1 * V_232 ;
int V_275 = 0 ;
int V_276 ;
int V_264 ;
memset ( V_267 , 0 , sizeof( V_39 -> V_267 ) ) ;
V_256 = F_88 ( V_8 ) ;
if ( ! V_256 ) {
F_11 ( L_20 ) ;
return;
}
V_35 = NULL ;
F_41 ( ( T_1 * ) V_8 , F_117 , & V_35 ) ;
for ( V_276 = 0 ; V_35 && V_276 < 13 ; V_276 ++ ) {
if ( V_35 [ V_276 ] == 0x0a )
break;
V_267 [ 20 + V_276 ] = V_35 [ V_276 ] ;
}
V_267 [ 4 ] = ( V_256 [ 1 ] << 5 ) | V_276 ;
F_11 ( L_21 , V_267 + 20 ) ;
V_267 [ 0 ] = 2 << 3 ;
V_267 [ 16 ] = V_8 -> V_52 [ 0 ] ;
V_267 [ 17 ] = V_8 -> V_52 [ 1 ] ;
V_267 [ 18 ] = V_8 -> V_277 [ 0 ] ;
V_267 [ 19 ] = V_8 -> V_277 [ 1 ] ;
if ( F_111 ( V_256 ) >= 3 ) {
int V_2 , V_22 , V_257 ;
if ( F_112 ( V_256 , & V_22 , & V_257 ) ) {
V_22 = 0 ;
V_257 = 0 ;
}
F_115 (cea, i, start, end) {
V_232 = & V_256 [ V_2 ] ;
V_264 = F_109 ( V_232 ) ;
switch ( F_110 ( V_232 ) ) {
case V_278 :
V_275 = V_264 / 3 ;
if ( V_264 >= 1 )
memcpy ( V_267 + 20 + V_276 , & V_232 [ 1 ] , V_264 ) ;
break;
case V_279 :
if ( V_264 >= 1 )
V_267 [ 7 ] = V_232 [ 1 ] ;
break;
case V_260 :
if ( F_113 ( V_232 ) )
F_116 ( V_39 , V_232 ) ;
break;
default:
break;
}
}
}
V_267 [ 5 ] |= V_275 << 4 ;
V_267 [ 2 ] = ( 20 + V_276 + V_275 * 3 + 3 ) / 4 ;
F_11 ( L_22 , ( int ) V_267 [ 2 ] , V_275 ) ;
}
int F_119 ( struct V_8 * V_8 , struct V_280 * * V_281 )
{
int V_282 = 0 ;
int V_2 , V_22 , V_257 , V_264 ;
T_1 * V_256 ;
V_256 = F_88 ( V_8 ) ;
if ( ! V_256 ) {
F_11 ( L_23 ) ;
return - V_283 ;
}
if ( F_111 ( V_256 ) < 3 ) {
F_11 ( L_24 ) ;
return - V_284 ;
}
if ( F_112 ( V_256 , & V_22 , & V_257 ) ) {
F_11 ( L_25 ) ;
return - V_285 ;
}
F_115 (cea, i, start, end) {
T_1 * V_232 = & V_256 [ V_2 ] ;
if ( F_110 ( V_232 ) == V_278 ) {
int V_40 ;
V_264 = F_109 ( V_232 ) ;
V_282 = V_264 / 3 ;
* V_281 = F_120 ( V_282 , sizeof( * * V_281 ) , V_46 ) ;
if ( ! * V_281 )
return - V_286 ;
for ( V_40 = 0 ; V_40 < V_282 ; V_40 ++ ) {
T_1 * V_287 = & V_232 [ 1 + V_40 * 3 ] ;
( * V_281 ) [ V_40 ] . V_288 = ( V_287 [ 0 ] & 0x78 ) >> 3 ;
( * V_281 ) [ V_40 ] . V_289 = V_287 [ 0 ] & 0x7 ;
( * V_281 ) [ V_40 ] . V_290 = V_287 [ 1 ] & 0x7F ;
( * V_281 ) [ V_40 ] . V_291 = V_287 [ 2 ] ;
}
break;
}
}
return V_282 ;
}
int F_121 ( struct V_8 * V_8 , T_1 * * V_292 )
{
int V_282 = 0 ;
int V_2 , V_22 , V_257 , V_264 ;
const T_1 * V_256 ;
V_256 = F_88 ( V_8 ) ;
if ( ! V_256 ) {
F_11 ( L_23 ) ;
return - V_283 ;
}
if ( F_111 ( V_256 ) < 3 ) {
F_11 ( L_24 ) ;
return - V_284 ;
}
if ( F_112 ( V_256 , & V_22 , & V_257 ) ) {
F_11 ( L_25 ) ;
return - V_285 ;
}
F_115 (cea, i, start, end) {
const T_1 * V_232 = & V_256 [ V_2 ] ;
if ( F_110 ( V_232 ) == V_279 ) {
V_264 = F_109 ( V_232 ) ;
if ( V_264 == 3 ) {
* V_292 = F_15 ( V_264 , V_46 ) ;
if ( ! * V_292 )
return - V_286 ;
memcpy ( * V_292 , & V_232 [ 1 ] , V_264 ) ;
V_282 = V_264 ;
break;
}
}
}
return V_282 ;
}
int F_122 ( struct V_38 * V_39 ,
struct V_58 * V_71 )
{
int V_2 = ! ! ( V_71 -> V_31 & V_129 ) ;
int V_107 , V_293 ;
if ( ! V_39 -> V_270 [ 0 ] )
return 0 ;
if ( ! V_39 -> V_270 [ 1 ] )
V_2 = 0 ;
V_107 = V_39 -> V_272 [ V_2 ] ;
V_293 = V_39 -> V_271 [ V_2 ] ;
if ( V_107 == 255 || V_293 == 255 )
return 0 ;
if ( V_107 )
V_107 = F_40 ( 2 * ( V_107 - 1 ) , 500 ) ;
if ( V_293 )
V_293 = F_40 ( 2 * ( V_293 - 1 ) , 500 ) ;
return F_123 ( V_293 - V_107 , 0 ) ;
}
struct V_38 * F_124 ( struct V_294 * V_295 ,
struct V_58 * V_71 )
{
struct V_38 * V_39 ;
struct V_78 * V_50 = V_295 -> V_50 ;
F_53 (connector, &dev->mode_config.connector_list, head)
if ( V_39 -> V_295 == V_295 && V_39 -> V_267 [ 0 ] )
return V_39 ;
return NULL ;
}
bool F_125 ( struct V_8 * V_8 )
{
T_1 * V_217 ;
int V_2 ;
int V_296 , V_297 ;
V_217 = F_88 ( V_8 ) ;
if ( ! V_217 )
return false ;
if ( F_112 ( V_217 , & V_296 , & V_297 ) )
return false ;
F_115 (edid_ext, i, start_offset, end_offset) {
if ( F_113 ( & V_217 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_126 ( struct V_8 * V_8 )
{
T_1 * V_217 ;
int V_2 , V_40 ;
bool V_298 = false ;
int V_296 , V_297 ;
V_217 = F_88 ( V_8 ) ;
if ( ! V_217 )
goto V_257;
V_298 = ( ( V_217 [ 3 ] & V_299 ) != 0 ) ;
if ( V_298 ) {
F_11 ( L_26 ) ;
goto V_257;
}
if ( F_112 ( V_217 , & V_296 , & V_297 ) )
goto V_257;
F_115 (edid_ext, i, start_offset, end_offset) {
if ( F_110 ( & V_217 [ V_2 ] ) == V_278 ) {
V_298 = true ;
for ( V_40 = 1 ; V_40 < F_109 ( & V_217 [ V_2 ] ) + 1 ; V_40 += 3 )
F_11 ( L_27 ,
( V_217 [ V_2 + V_40 ] >> 3 ) & 0xf ) ;
goto V_257;
}
}
V_257:
return V_298 ;
}
bool F_127 ( struct V_8 * V_8 )
{
T_1 * V_217 ;
int V_2 , V_22 , V_257 ;
V_217 = F_88 ( V_8 ) ;
if ( ! V_217 )
return false ;
if ( F_112 ( V_217 , & V_22 , & V_257 ) )
return false ;
F_115 (edid_ext, i, start, end) {
if ( F_110 ( & V_217 [ V_2 ] ) == V_300 &&
F_109 ( & V_217 [ V_2 ] ) == 2 ) {
F_11 ( L_28 , V_217 [ V_2 + 2 ] ) ;
return V_217 [ V_2 + 2 ] & V_301 ;
}
}
return false ;
}
static void F_128 ( struct V_8 * V_8 ,
struct V_302 * V_303 )
{
T_1 * V_217 ;
V_303 -> V_163 = V_8 -> V_170 * 10 ;
V_303 -> V_166 = V_8 -> V_171 * 10 ;
V_303 -> V_304 = 0 ;
V_303 -> V_305 = 0 ;
if ( V_8 -> V_13 < 3 )
return;
if ( ! ( V_8 -> V_99 & V_100 ) )
return;
V_217 = F_88 ( V_8 ) ;
if ( V_217 ) {
V_303 -> V_306 = V_217 [ 1 ] ;
V_303 -> V_305 = V_307 ;
if ( V_217 [ 3 ] & V_308 )
V_303 -> V_305 |= V_309 ;
if ( V_217 [ 3 ] & V_310 )
V_303 -> V_305 |= V_311 ;
}
if ( V_8 -> V_13 < 4 )
return;
switch ( V_8 -> V_99 & V_312 ) {
case V_313 :
V_303 -> V_304 = 6 ;
break;
case V_314 :
V_303 -> V_304 = 8 ;
break;
case V_315 :
V_303 -> V_304 = 10 ;
break;
case V_316 :
V_303 -> V_304 = 12 ;
break;
case V_317 :
V_303 -> V_304 = 14 ;
break;
case V_318 :
V_303 -> V_304 = 16 ;
break;
case V_319 :
default:
V_303 -> V_304 = 0 ;
break;
}
V_303 -> V_305 |= V_307 ;
if ( V_8 -> V_101 & V_320 )
V_303 -> V_305 |= V_309 ;
if ( V_8 -> V_101 & V_321 )
V_303 -> V_305 |= V_311 ;
}
int F_129 ( struct V_38 * V_39 , struct V_8 * V_8 )
{
int V_322 = 0 ;
T_2 V_57 ;
if ( V_8 == NULL ) {
return 0 ;
}
if ( ! F_8 ( V_8 ) ) {
F_17 ( V_39 -> V_50 -> V_50 , L_29 ,
F_18 ( V_39 ) ) ;
return 0 ;
}
V_57 = F_25 ( V_8 ) ;
V_322 += F_87 ( V_39 , V_8 , V_57 ) ;
V_322 += F_85 ( V_39 , V_8 ) ;
V_322 += F_82 ( V_39 , V_8 ) ;
V_322 += F_80 ( V_39 , V_8 ) ;
if ( V_8 -> V_101 & V_102 )
V_322 += F_77 ( V_39 , V_8 ) ;
V_322 += F_114 ( V_39 , V_8 ) ;
V_322 += F_96 ( V_39 , V_8 ) ;
if ( V_57 & ( V_66 | V_67 ) )
F_28 ( V_39 , V_57 ) ;
F_128 ( V_8 , & V_39 -> V_323 ) ;
if ( V_57 & V_324 )
V_39 -> V_323 . V_304 = 8 ;
return V_322 ;
}
int F_130 ( struct V_38 * V_39 ,
int V_73 , int V_77 )
{
int V_2 , V_282 , V_322 = 0 ;
struct V_58 * V_71 ;
struct V_78 * V_50 = V_39 -> V_50 ;
V_282 = sizeof( V_83 ) / sizeof( struct V_58 ) ;
if ( V_73 < 0 )
V_73 = 0 ;
if ( V_77 < 0 )
V_77 = 0 ;
for ( V_2 = 0 ; V_2 < V_282 ; V_2 ++ ) {
const struct V_58 * V_84 = & V_83 [ V_2 ] ;
if ( V_73 && V_77 ) {
if ( V_84 -> V_73 > V_73 ||
V_84 -> V_77 > V_77 )
continue;
}
if ( F_33 ( V_84 ) > 61 )
continue;
V_71 = F_37 ( V_50 , V_84 ) ;
if ( V_71 ) {
F_71 ( V_39 , V_71 ) ;
V_322 ++ ;
}
}
return V_322 ;
}
void F_131 ( struct V_38 * V_39 ,
int V_325 , int V_326 )
{
struct V_58 * V_71 ;
F_53 (mode, &connector->probed_modes, head) {
if ( V_71 -> V_73 == V_325 &&
V_71 -> V_77 == V_326 )
V_71 -> type |= V_69 ;
}
}
int
F_132 ( struct V_327 * V_328 ,
const struct V_58 * V_71 )
{
int V_329 ;
if ( ! V_328 || ! V_71 )
return - V_330 ;
V_329 = F_133 ( V_328 ) ;
if ( V_329 < 0 )
return V_329 ;
if ( V_71 -> V_31 & V_331 )
V_328 -> V_332 = 1 ;
V_328 -> V_333 = F_91 ( V_71 ) ;
V_328 -> V_334 = V_335 ;
V_328 -> V_336 = V_337 ;
V_328 -> V_338 = V_339 ;
return 0 ;
}
static enum V_340
F_134 ( const struct V_58 * V_71 )
{
T_2 V_341 = V_71 -> V_31 & V_228 ;
switch ( V_341 ) {
case V_243 :
return V_342 ;
case V_343 :
return V_344 ;
case V_345 :
return V_346 ;
case V_347 :
return V_348 ;
case V_349 :
return V_350 ;
case V_351 :
return V_352 ;
case V_244 :
return V_353 ;
case V_245 :
return V_354 ;
default:
return V_355 ;
}
}
int
F_135 ( struct V_356 * V_328 ,
const struct V_58 * V_71 )
{
int V_329 ;
T_2 V_357 ;
T_1 V_241 ;
if ( ! V_328 || ! V_71 )
return - V_330 ;
V_241 = F_95 ( V_71 ) ;
V_357 = V_71 -> V_31 & V_228 ;
if ( ! V_241 && ! V_357 )
return - V_330 ;
if ( V_241 && V_357 )
return - V_330 ;
V_329 = F_136 ( V_328 ) ;
if ( V_329 < 0 )
return V_329 ;
if ( V_241 )
V_328 -> V_241 = V_241 ;
else
V_328 -> V_358 = F_134 ( V_71 ) ;
return 0 ;
}
