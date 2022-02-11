int F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < sizeof( V_4 ) ; V_2 ++ )
if ( V_1 [ V_2 ] == V_4 [ V_2 ] )
V_3 ++ ;
return V_3 ;
}
bool F_2 ( T_1 * V_1 , int V_5 )
{
int V_2 ;
T_1 V_6 = 0 ;
struct V_7 * V_7 = (struct V_7 * ) V_1 ;
if ( V_8 > 8 || V_8 < 0 )
V_8 = 6 ;
if ( V_5 == 0 ) {
int V_3 = F_1 ( V_1 ) ;
if ( V_3 == 8 ) ;
else if ( V_3 >= V_8 ) {
F_3 ( L_1 ) ;
memcpy ( V_1 , V_4 , sizeof( V_4 ) ) ;
} else {
goto V_9;
}
}
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ )
V_6 += V_1 [ V_2 ] ;
if ( V_6 ) {
F_4 ( L_2 , V_6 ) ;
if ( V_1 [ 0 ] != 0x02 )
goto V_9;
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_7 -> V_11 != 1 ) {
F_4 ( L_3 , V_7 -> V_11 ) ;
goto V_9;
}
if ( V_7 -> V_12 > 4 )
F_3 ( L_4 ) ;
break;
default:
break;
}
return 1 ;
V_9:
if ( V_1 ) {
F_5 ( V_13 L_5 ) ;
F_6 ( V_13 , L_6 , V_14 , 16 , 1 ,
V_1 , V_10 , false ) ;
}
return 0 ;
}
bool F_7 ( struct V_7 * V_7 )
{
int V_2 ;
T_1 * V_15 = ( T_1 * ) V_7 ;
if ( ! V_7 )
return false ;
for ( V_2 = 0 ; V_2 <= V_7 -> V_16 ; V_2 ++ )
if ( ! F_2 ( V_15 + V_2 * V_10 , V_2 ) )
return false ;
return true ;
}
static int
F_8 ( struct V_17 * V_18 , unsigned char * V_19 ,
int V_5 , int V_20 )
{
unsigned char V_21 = V_5 * V_10 ;
int V_22 , V_23 = 5 ;
do {
struct V_24 V_25 [] = {
{
. V_26 = V_27 ,
. V_28 = 0 ,
. V_20 = 1 ,
. V_19 = & V_21 ,
} , {
. V_26 = V_27 ,
. V_28 = V_29 ,
. V_20 = V_20 ,
. V_19 = V_19 ,
}
} ;
V_22 = F_9 ( V_18 , V_25 , 2 ) ;
if ( V_22 == - V_30 ) {
F_10 ( L_7 ,
V_18 -> V_31 ) ;
break;
}
} while ( V_22 != 2 && -- V_23 );
return V_22 == 2 ? 0 : - 1 ;
}
static bool F_11 ( T_1 * V_32 , int V_33 )
{
int V_2 ;
T_2 * V_1 = ( T_2 * ) V_32 ;
for ( V_2 = 0 ; V_2 < V_33 / 4 ; V_2 ++ )
if ( * ( V_1 + V_2 ) != 0 )
return false ;
return true ;
}
static T_1 *
F_12 ( struct V_34 * V_35 , struct V_17 * V_18 )
{
int V_2 , V_36 = 0 , V_37 = 0 ;
T_1 * V_5 , * V_38 ;
if ( ( V_5 = F_13 ( V_10 , V_39 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_18 , V_5 , 0 , V_10 ) )
goto V_40;
if ( F_2 ( V_5 , 0 ) )
break;
if ( V_2 == 0 && F_11 ( V_5 , V_10 ) ) {
V_35 -> V_41 ++ ;
goto V_42;
}
}
if ( V_2 == 4 )
goto V_42;
if ( V_5 [ 0x7e ] == 0 )
return V_5 ;
V_38 = F_14 ( V_5 , ( V_5 [ 0x7e ] + 1 ) * V_10 , V_39 ) ;
if ( ! V_38 )
goto V_40;
V_5 = V_38 ;
for ( V_36 = 1 ; V_36 <= V_5 [ 0x7e ] ; V_36 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_8 ( V_18 ,
V_5 + ( V_37 + 1 ) * V_10 ,
V_36 , V_10 ) )
goto V_40;
if ( F_2 ( V_5 + ( V_37 + 1 ) * V_10 , V_36 ) ) {
V_37 ++ ;
break;
}
}
if ( V_2 == 4 )
F_15 ( V_35 -> V_43 -> V_43 ,
L_8 ,
F_16 ( V_35 ) , V_36 ) ;
}
if ( V_37 != V_5 [ 0x7e ] ) {
V_5 [ V_10 - 1 ] += V_5 [ 0x7e ] - V_37 ;
V_5 [ 0x7e ] = V_37 ;
V_38 = F_14 ( V_5 , ( V_37 + 1 ) * V_10 , V_39 ) ;
if ( ! V_38 )
goto V_40;
V_5 = V_38 ;
}
return V_5 ;
V_42:
F_15 ( V_35 -> V_43 -> V_43 , L_9 ,
F_16 ( V_35 ) , V_36 ) ;
V_40:
F_17 ( V_5 ) ;
return NULL ;
}
static bool
F_18 ( struct V_17 * V_18 )
{
unsigned char V_40 ;
return ( F_8 ( V_18 , & V_40 , 0 , 1 ) == 0 ) ;
}
struct V_7 * F_19 ( struct V_34 * V_35 ,
struct V_17 * V_18 )
{
struct V_7 * V_7 = NULL ;
if ( F_18 ( V_18 ) )
V_7 = (struct V_7 * ) F_12 ( V_35 , V_18 ) ;
V_35 -> V_44 . V_1 = ( char * ) V_7 ;
return V_7 ;
}
static bool F_20 ( struct V_7 * V_7 , char * V_45 )
{
char F_20 [ 3 ] ;
F_20 [ 0 ] = ( ( V_7 -> V_46 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_20 [ 1 ] = ( ( ( V_7 -> V_46 [ 0 ] & 0x3 ) << 3 ) |
( ( V_7 -> V_46 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_20 [ 2 ] = ( V_7 -> V_46 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_20 , V_45 , 3 ) ;
}
static T_2 F_21 ( struct V_7 * V_7 )
{
struct V_47 * V_48 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_22 ( V_49 ) ; V_2 ++ ) {
V_48 = & V_49 [ V_2 ] ;
if ( F_20 ( V_7 , V_48 -> V_45 ) &&
( F_23 ( V_7 ) == V_48 -> V_50 ) )
return V_48 -> V_51 ;
}
return 0 ;
}
static void F_24 ( struct V_34 * V_35 ,
T_2 V_51 )
{
struct V_52 * V_53 , * V_54 , * V_55 ;
int V_56 = 0 ;
if ( F_25 ( & V_35 -> V_57 ) )
return;
if ( V_51 & V_58 )
V_56 = 60 ;
if ( V_51 & V_59 )
V_56 = 75 ;
V_55 = F_26 ( & V_35 -> V_57 ,
struct V_52 , V_60 ) ;
F_27 (cur_mode, t, &connector->probed_modes, head) {
V_54 -> type &= ~ V_61 ;
if ( V_54 == V_55 )
continue;
if ( F_28 ( V_54 ) > F_28 ( V_55 ) )
V_55 = V_54 ;
if ( ( F_28 ( V_54 ) == F_28 ( V_55 ) ) &&
F_29 ( V_54 , V_56 ) <
F_29 ( V_55 , V_56 ) ) {
V_55 = V_54 ;
}
}
V_55 -> type |= V_61 ;
}
static bool
F_30 ( const struct V_52 * V_62 )
{
return ( V_62 -> V_63 - V_62 -> V_64 == 160 ) &&
( V_62 -> V_65 - V_62 -> V_64 == 80 ) &&
( V_62 -> V_65 - V_62 -> V_66 == 32 ) &&
( V_62 -> V_67 - V_62 -> V_68 == 3 ) ;
}
struct V_52 * F_31 ( struct V_69 * V_43 ,
int V_70 , int V_71 , int V_72 ,
bool V_73 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_74 ; V_2 ++ ) {
const struct V_52 * V_75 = & V_76 [ V_2 ] ;
if ( V_70 != V_75 -> V_64 )
continue;
if ( V_71 != V_75 -> V_68 )
continue;
if ( V_72 != F_32 ( V_75 ) )
continue;
if ( V_73 != F_30 ( V_75 ) )
continue;
return F_33 ( V_43 , V_75 ) ;
}
return NULL ;
}
static void
F_34 ( T_1 * V_77 , T_3 * V_78 , void * V_79 )
{
int V_2 , V_80 = 0 ;
T_1 V_81 = V_77 [ 0x02 ] ;
T_1 * V_82 = V_77 + V_81 ;
V_80 = ( 127 - V_81 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_80 ; V_2 ++ )
V_78 ( (struct V_83 * ) ( V_82 + 18 * V_2 ) , V_79 ) ;
}
static void
F_35 ( T_1 * V_77 , T_3 * V_78 , void * V_79 )
{
unsigned int V_2 , V_80 = F_36 ( ( int ) V_77 [ 0x02 ] , 6 ) ;
T_1 * V_82 = V_77 + 5 ;
if ( V_77 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_80 ; V_2 ++ )
V_78 ( (struct V_83 * ) ( V_82 + 18 * V_2 ) , V_79 ) ;
}
static void
F_37 ( T_1 * V_1 , T_3 * V_78 , void * V_79 )
{
int V_2 ;
struct V_7 * V_7 = (struct V_7 * ) V_1 ;
if ( V_7 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_84 ; V_2 ++ )
V_78 ( & ( V_7 -> V_85 [ V_2 ] ) , V_79 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_77 = V_1 + ( V_2 * V_10 ) ;
switch ( * V_77 ) {
case V_86 :
F_34 ( V_77 , V_78 , V_79 ) ;
break;
case V_87 :
F_35 ( V_77 , V_78 , V_79 ) ;
break;
default:
break;
}
}
}
static void
F_38 ( struct V_83 * V_53 , void * V_88 )
{
T_1 * V_89 = ( T_1 * ) V_53 ;
if ( V_89 [ 3 ] == V_90 )
if ( V_89 [ 15 ] & 0x10 )
* ( bool * ) V_88 = true ;
}
static bool
F_39 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 >= 4 ) {
bool V_22 = false ;
F_37 ( ( T_1 * ) V_7 , F_38 , & V_22 ) ;
return V_22 ;
}
return ( ( V_7 -> V_91 & V_92 ) != 0 ) ;
}
static void
F_40 ( struct V_83 * V_53 , void * V_88 )
{
T_1 * V_89 = ( T_1 * ) V_53 ;
if ( V_89 [ 3 ] == V_90 && V_89 [ 10 ] == 0x02 )
* ( T_1 * * ) V_88 = V_89 ;
}
static int
F_41 ( struct V_7 * V_7 )
{
T_1 * V_89 = NULL ;
F_37 ( ( T_1 * ) V_7 , F_40 , & V_89 ) ;
return V_89 ? ( V_89 [ 12 ] * 2 ) : 0 ;
}
static int
F_42 ( struct V_7 * V_7 )
{
T_1 * V_89 = NULL ;
F_37 ( ( T_1 * ) V_7 , F_40 , & V_89 ) ;
return V_89 ? V_89 [ 13 ] : 0 ;
}
static int
F_43 ( struct V_7 * V_7 )
{
T_1 * V_89 = NULL ;
F_37 ( ( T_1 * ) V_7 , F_40 , & V_89 ) ;
return V_89 ? ( V_89 [ 15 ] << 8 ) + V_89 [ 14 ] : 0 ;
}
static int
F_44 ( struct V_7 * V_7 )
{
T_1 * V_89 = NULL ;
F_37 ( ( T_1 * ) V_7 , F_40 , & V_89 ) ;
return V_89 ? V_89 [ 16 ] : 0 ;
}
static int
F_45 ( struct V_7 * V_7 )
{
T_1 * V_89 = NULL ;
F_37 ( ( T_1 * ) V_7 , F_40 , & V_89 ) ;
return V_89 ? V_89 [ 17 ] : 0 ;
}
static int F_46 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 >= 2 ) {
if ( V_7 -> V_12 >= 4 && ( V_7 -> V_93 & V_94 ) )
return V_95 ;
if ( F_41 ( V_7 ) )
return V_96 ;
return V_97 ;
}
return V_98 ;
}
static int
F_47 ( T_1 V_99 , T_1 V_100 )
{
return ( V_99 == 0x00 && V_100 == 0x00 ) ||
( V_99 == 0x01 && V_100 == 0x01 ) ||
( V_99 == 0x20 && V_100 == 0x20 ) ;
}
static struct V_52 *
F_48 ( struct V_34 * V_35 , struct V_7 * V_7 ,
struct V_101 * V_53 , int V_12 )
{
struct V_69 * V_43 = V_35 -> V_43 ;
struct V_52 * V_102 , * V_62 = NULL ;
int V_70 , V_71 ;
int V_103 ;
unsigned V_104 = ( V_53 -> V_105 & V_106 )
>> V_107 ;
unsigned V_108 = ( V_53 -> V_105 & V_109 )
>> V_110 ;
int V_111 = F_46 ( V_7 ) ;
if ( F_47 ( V_53 -> V_70 , V_53 -> V_105 ) )
return NULL ;
V_70 = V_53 -> V_70 * 8 + 248 ;
V_103 = V_108 + 60 ;
if ( V_104 == 0 ) {
if ( V_12 < 3 )
V_71 = V_70 ;
else
V_71 = ( V_70 * 10 ) / 16 ;
} else if ( V_104 == 1 )
V_71 = ( V_70 * 3 ) / 4 ;
else if ( V_104 == 2 )
V_71 = ( V_70 * 4 ) / 5 ;
else
V_71 = ( V_70 * 9 ) / 16 ;
if ( V_103 == 60 &&
( ( V_70 == 1360 && V_71 == 765 ) ||
( V_70 == 1368 && V_71 == 769 ) ) ) {
V_70 = 1366 ;
V_71 = 768 ;
}
F_49 (m, &connector->probed_modes, head)
if ( V_102 -> V_64 == V_70 && V_102 -> V_68 == V_71 &&
F_32 ( V_102 ) == V_103 )
return NULL ;
if ( V_70 == 1366 && V_71 == 768 && V_103 == 60 ) {
V_62 = F_50 ( V_43 , 1366 , 768 , V_103 , 0 , 0 ,
false ) ;
V_62 -> V_64 = 1366 ;
V_62 -> V_66 = V_62 -> V_66 - 1 ;
V_62 -> V_65 = V_62 -> V_65 - 1 ;
return V_62 ;
}
if ( F_39 ( V_7 ) ) {
V_62 = F_31 ( V_43 , V_70 , V_71 , V_103 ,
true ) ;
if ( V_62 )
return V_62 ;
}
V_62 = F_31 ( V_43 , V_70 , V_71 , V_103 , false ) ;
if ( V_62 )
return V_62 ;
switch ( V_111 ) {
case V_98 :
break;
case V_97 :
V_62 = F_51 ( V_43 , V_70 , V_71 , V_103 , 0 , 0 ) ;
break;
case V_96 :
V_62 = F_51 ( V_43 , V_70 , V_71 , V_103 , 0 , 0 ) ;
if ( ! V_62 )
return NULL ;
if ( F_52 ( V_62 ) > F_41 ( V_7 ) ) {
F_53 ( V_43 , V_62 ) ;
V_62 = F_54 ( V_43 , V_70 , V_71 ,
V_103 , 0 , 0 ,
F_43 ( V_7 ) ,
F_42 ( V_7 ) ,
F_44 ( V_7 ) ,
F_45 ( V_7 ) ) ;
}
break;
case V_95 :
V_62 = F_50 ( V_43 , V_70 , V_71 , V_103 , 0 , 0 ,
false ) ;
break;
}
return V_62 ;
}
static void
F_55 ( struct V_52 * V_62 ,
struct V_112 * V_113 )
{
int V_2 ;
static const struct {
int V_114 , V_115 ;
} V_116 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_113 -> V_117 & V_118 ) )
return;
for ( V_2 = 0 ; V_2 < F_22 ( V_116 ) ; V_2 ++ ) {
if ( ( V_62 -> V_64 == V_116 [ V_2 ] . V_114 ) &&
( V_62 -> V_68 == V_116 [ V_2 ] . V_115 / 2 ) ) {
V_62 -> V_68 *= 2 ;
V_62 -> V_67 *= 2 ;
V_62 -> V_119 *= 2 ;
V_62 -> V_120 *= 2 ;
V_62 -> V_120 |= 1 ;
}
}
V_62 -> V_28 |= V_121 ;
}
static struct V_52 * F_56 ( struct V_69 * V_43 ,
struct V_7 * V_7 ,
struct V_83 * V_122 ,
T_2 V_51 )
{
struct V_52 * V_62 ;
struct V_112 * V_113 = & V_122 -> V_88 . V_123 ;
unsigned V_124 = ( V_113 -> V_125 & 0xf0 ) << 4 | V_113 -> V_126 ;
unsigned V_127 = ( V_113 -> V_128 & 0xf0 ) << 4 | V_113 -> V_129 ;
unsigned V_130 = ( V_113 -> V_125 & 0xf ) << 8 | V_113 -> V_131 ;
unsigned V_132 = ( V_113 -> V_128 & 0xf ) << 8 | V_113 -> V_133 ;
unsigned V_134 = ( V_113 -> V_135 & 0xc0 ) << 2 | V_113 -> V_136 ;
unsigned V_137 = ( V_113 -> V_135 & 0x30 ) << 4 | V_113 -> V_138 ;
unsigned V_139 = ( V_113 -> V_135 & 0xc ) >> 2 | V_113 -> V_140 >> 4 ;
unsigned V_141 = ( V_113 -> V_135 & 0x3 ) << 4 | ( V_113 -> V_140 & 0xf ) ;
if ( V_124 < 64 || V_127 < 64 )
return NULL ;
if ( V_113 -> V_117 & V_142 ) {
F_5 ( V_143 L_10 ) ;
return NULL ;
}
if ( ! ( V_113 -> V_117 & V_144 ) ) {
F_5 ( V_143 L_11 ) ;
}
if ( ! V_137 || ! V_141 ) {
F_10 ( L_12
L_13 ) ;
return NULL ;
}
if ( V_51 & V_145 ) {
V_62 = F_50 ( V_43 , V_124 , V_127 , 60 , true , false , false ) ;
if ( ! V_62 )
return NULL ;
goto V_146;
}
V_62 = F_57 ( V_43 ) ;
if ( ! V_62 )
return NULL ;
if ( V_51 & V_147 )
V_122 -> V_148 = F_58 ( 1088 ) ;
V_62 -> clock = F_59 ( V_122 -> V_148 ) * 10 ;
V_62 -> V_64 = V_124 ;
V_62 -> V_66 = V_62 -> V_64 + V_134 ;
V_62 -> V_65 = V_62 -> V_66 + V_137 ;
V_62 -> V_63 = V_62 -> V_64 + V_130 ;
V_62 -> V_68 = V_127 ;
V_62 -> V_67 = V_62 -> V_68 + V_139 ;
V_62 -> V_119 = V_62 -> V_67 + V_141 ;
V_62 -> V_120 = V_62 -> V_68 + V_132 ;
if ( V_62 -> V_65 > V_62 -> V_63 )
V_62 -> V_63 = V_62 -> V_65 + 1 ;
if ( V_62 -> V_119 > V_62 -> V_120 )
V_62 -> V_120 = V_62 -> V_119 + 1 ;
F_55 ( V_62 , V_113 ) ;
if ( V_51 & V_149 ) {
V_113 -> V_117 |= V_150 | V_151 ;
}
V_62 -> V_28 |= ( V_113 -> V_117 & V_150 ) ?
V_152 : V_153 ;
V_62 -> V_28 |= ( V_113 -> V_117 & V_151 ) ?
V_154 : V_155 ;
V_146:
V_62 -> V_156 = V_113 -> V_157 | ( V_113 -> V_158 & 0xf0 ) << 4 ;
V_62 -> V_159 = V_113 -> V_160 | ( V_113 -> V_158 & 0xf ) << 8 ;
if ( V_51 & V_161 ) {
V_62 -> V_156 *= 10 ;
V_62 -> V_159 *= 10 ;
}
if ( V_51 & V_162 ) {
V_62 -> V_156 = V_7 -> V_163 * 10 ;
V_62 -> V_159 = V_7 -> V_164 * 10 ;
}
V_62 -> type = V_165 ;
F_60 ( V_62 ) ;
return V_62 ;
}
static bool
F_61 ( const struct V_52 * V_62 ,
struct V_7 * V_7 , T_1 * V_53 )
{
int V_166 , V_167 , V_168 ;
V_167 = V_53 [ 7 ] ;
if ( V_7 -> V_12 >= 4 )
V_167 += ( ( V_53 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_168 = V_53 [ 8 ] ;
if ( V_7 -> V_12 >= 4 )
V_168 += ( ( V_53 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_166 = F_52 ( V_62 ) ;
return ( V_166 <= V_168 && V_166 >= V_167 ) ;
}
static bool
F_62 ( const struct V_52 * V_62 ,
struct V_7 * V_7 , T_1 * V_53 )
{
int V_169 , V_170 , V_171 ;
V_170 = V_53 [ 5 ] ;
if ( V_7 -> V_12 >= 4 )
V_170 += ( ( V_53 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_171 = V_53 [ 6 ] ;
if ( V_7 -> V_12 >= 4 )
V_171 += ( ( V_53 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_169 = F_32 ( V_62 ) ;
return ( V_169 <= V_171 && V_169 >= V_170 ) ;
}
static T_2
F_63 ( struct V_7 * V_7 , T_1 * V_53 )
{
if ( V_53 [ 9 ] == 0 || V_53 [ 9 ] == 255 )
return 0 ;
if ( V_7 -> V_12 >= 4 && V_53 [ 10 ] == 0x04 )
return ( V_53 [ 9 ] * 10000 ) - ( ( V_53 [ 12 ] >> 2 ) * 250 ) ;
return V_53 [ 9 ] * 10000 + 5001 ;
}
static bool
F_64 ( const struct V_52 * V_62 , struct V_7 * V_7 ,
struct V_83 * V_122 )
{
T_2 V_172 ;
T_1 * V_53 = ( T_1 * ) V_122 ;
if ( ! F_61 ( V_62 , V_7 , V_53 ) )
return false ;
if ( ! F_62 ( V_62 , V_7 , V_53 ) )
return false ;
if ( ( V_172 = F_63 ( V_7 , V_53 ) ) )
if ( V_62 -> clock > V_172 )
return false ;
if ( V_7 -> V_12 >= 4 && V_53 [ 10 ] == 0x04 )
if ( V_53 [ 13 ] && V_62 -> V_64 > 8 * ( V_53 [ 13 ] + ( 256 * ( V_53 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_30 ( V_62 ) && ! F_39 ( V_7 ) )
return false ;
return true ;
}
static bool F_65 ( const struct V_34 * V_35 ,
const struct V_52 * V_62 )
{
struct V_52 * V_102 ;
bool V_173 = false ;
F_49 (m, &connector->probed_modes, head) {
if ( V_62 -> V_64 == V_102 -> V_64 &&
V_62 -> V_68 == V_102 -> V_68 &&
F_32 ( V_62 ) == F_32 ( V_102 ) )
return false ;
if ( V_62 -> V_64 <= V_102 -> V_64 &&
V_62 -> V_68 <= V_102 -> V_68 )
V_173 = true ;
}
return V_173 ;
}
static int
F_66 ( struct V_34 * V_35 , struct V_7 * V_7 ,
struct V_83 * V_122 )
{
int V_2 , V_174 = 0 ;
struct V_52 * V_175 ;
struct V_69 * V_43 = V_35 -> V_43 ;
for ( V_2 = 0 ; V_2 < V_74 ; V_2 ++ ) {
if ( F_64 ( V_76 + V_2 , V_7 , V_122 ) &&
F_65 ( V_35 , V_76 + V_2 ) ) {
V_175 = F_33 ( V_43 , & V_76 [ V_2 ] ) ;
if ( V_175 ) {
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
}
}
return V_174 ;
}
static void F_68 ( struct V_52 * V_62 )
{
if ( V_62 -> V_64 == 1368 && V_62 -> V_68 == 768 ) {
V_62 -> V_64 = 1366 ;
V_62 -> V_66 -- ;
V_62 -> V_65 -- ;
F_60 ( V_62 ) ;
}
}
static int
F_69 ( struct V_34 * V_35 , struct V_7 * V_7 ,
struct V_83 * V_122 )
{
int V_2 , V_174 = 0 ;
struct V_52 * V_175 ;
struct V_69 * V_43 = V_35 -> V_43 ;
for ( V_2 = 0 ; V_2 < V_176 ; V_2 ++ ) {
const struct V_177 * V_102 = & V_178 [ V_2 ] ;
V_175 = F_51 ( V_43 , V_102 -> V_114 , V_102 -> V_115 , V_102 -> V_89 , 0 , 0 ) ;
if ( ! V_175 )
return V_174 ;
F_68 ( V_175 ) ;
if ( ! F_64 ( V_175 , V_7 , V_122 ) ||
! F_65 ( V_35 , V_175 ) ) {
F_53 ( V_43 , V_175 ) ;
continue;
}
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
return V_174 ;
}
static int
F_70 ( struct V_34 * V_35 , struct V_7 * V_7 ,
struct V_83 * V_122 )
{
int V_2 , V_174 = 0 ;
struct V_52 * V_175 ;
struct V_69 * V_43 = V_35 -> V_43 ;
bool V_73 = F_39 ( V_7 ) ;
for ( V_2 = 0 ; V_2 < V_176 ; V_2 ++ ) {
const struct V_177 * V_102 = & V_178 [ V_2 ] ;
V_175 = F_50 ( V_43 , V_102 -> V_114 , V_102 -> V_115 , V_102 -> V_89 , V_73 , 0 , 0 ) ;
if ( ! V_175 )
return V_174 ;
F_68 ( V_175 ) ;
if ( ! F_64 ( V_175 , V_7 , V_122 ) ||
! F_65 ( V_35 , V_175 ) ) {
F_53 ( V_43 , V_175 ) ;
continue;
}
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
return V_174 ;
}
static void
F_71 ( struct V_83 * V_122 , void * V_179 )
{
struct V_180 * V_79 = V_179 ;
struct V_181 * V_88 = & V_122 -> V_88 . V_182 ;
struct V_183 * V_184 = & V_88 -> V_88 . V_184 ;
if ( V_88 -> type != V_90 )
return;
V_79 -> V_174 += F_66 ( V_79 -> V_35 ,
V_79 -> V_7 ,
V_122 ) ;
if ( ! F_72 ( V_79 -> V_7 , 1 , 1 ) )
return;
switch ( V_184 -> V_28 ) {
case 0x02 :
case 0x00 :
V_79 -> V_174 += F_69 ( V_79 -> V_35 ,
V_79 -> V_7 ,
V_122 ) ;
break;
case 0x04 :
if ( ! F_72 ( V_79 -> V_7 , 1 , 3 ) )
break;
V_79 -> V_174 += F_70 ( V_79 -> V_35 ,
V_79 -> V_7 ,
V_122 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_73 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
struct V_180 V_79 = {
V_35 , V_7 , 0 , 0 , 0
} ;
if ( F_72 ( V_7 , 1 , 0 ) )
F_37 ( ( T_1 * ) V_7 , F_71 ,
& V_79 ) ;
return V_79 . V_174 ;
}
static int
F_74 ( struct V_34 * V_35 , struct V_83 * V_122 )
{
int V_2 , V_36 , V_102 , V_174 = 0 ;
struct V_52 * V_62 ;
T_1 * V_185 = ( ( T_1 * ) V_122 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_36 = 7 ; V_36 > 0 ; V_36 -- ) {
V_102 = ( V_2 * 8 ) + ( 7 - V_36 ) ;
if ( V_102 >= F_22 ( V_186 ) )
break;
if ( V_185 [ V_2 ] & ( 1 << V_36 ) ) {
V_62 = F_31 ( V_35 -> V_43 ,
V_186 [ V_102 ] . V_114 ,
V_186 [ V_102 ] . V_115 ,
V_186 [ V_102 ] . V_89 ,
V_186 [ V_102 ] . V_73 ) ;
if ( V_62 ) {
F_67 ( V_35 , V_62 ) ;
V_174 ++ ;
}
}
}
}
return V_174 ;
}
static void
F_75 ( struct V_83 * V_122 , void * V_179 )
{
struct V_180 * V_79 = V_179 ;
struct V_181 * V_88 = & V_122 -> V_88 . V_182 ;
if ( V_88 -> type == V_187 )
V_79 -> V_174 += F_74 ( V_79 -> V_35 , V_122 ) ;
}
static int
F_76 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
struct V_69 * V_43 = V_35 -> V_43 ;
unsigned long V_188 = V_7 -> V_189 . V_190 |
( V_7 -> V_189 . V_191 << 8 ) |
( ( V_7 -> V_189 . V_192 & 0x80 ) << 9 ) ;
int V_2 , V_174 = 0 ;
struct V_180 V_79 = {
V_35 , V_7 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 <= V_193 ; V_2 ++ ) {
if ( V_188 & ( 1 << V_2 ) ) {
struct V_52 * V_175 ;
V_175 = F_33 ( V_43 , & V_194 [ V_2 ] ) ;
if ( V_175 ) {
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
}
}
if ( F_72 ( V_7 , 1 , 0 ) )
F_37 ( ( T_1 * ) V_7 ,
F_75 , & V_79 ) ;
return V_174 + V_79 . V_174 ;
}
static void
F_77 ( struct V_83 * V_122 , void * V_179 )
{
struct V_180 * V_79 = V_179 ;
struct V_181 * V_88 = & V_122 -> V_88 . V_182 ;
struct V_34 * V_35 = V_79 -> V_35 ;
struct V_7 * V_7 = V_79 -> V_7 ;
if ( V_88 -> type == V_195 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_101 * V_196 ;
struct V_52 * V_175 ;
V_196 = & V_88 -> V_88 . V_197 [ V_2 ] ;
V_175 = F_48 ( V_35 , V_7 , V_196 ,
V_7 -> V_12 ) ;
if ( V_175 ) {
F_67 ( V_35 , V_175 ) ;
V_79 -> V_174 ++ ;
}
}
}
}
static int
F_78 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
int V_2 , V_174 = 0 ;
struct V_180 V_79 = {
V_35 , V_7 , 0 , 0 , 0
} ;
for ( V_2 = 0 ; V_2 < V_198 ; V_2 ++ ) {
struct V_52 * V_175 ;
V_175 = F_48 ( V_35 , V_7 ,
& V_7 -> V_199 [ V_2 ] ,
V_7 -> V_12 ) ;
if ( V_175 ) {
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
}
if ( F_72 ( V_7 , 1 , 0 ) )
F_37 ( ( T_1 * ) V_7 , F_77 ,
& V_79 ) ;
return V_174 + V_79 . V_174 ;
}
static int F_79 ( struct V_34 * V_35 ,
struct V_83 * V_122 )
{
int V_2 , V_36 , V_174 = 0 ;
struct V_52 * V_175 ;
struct V_69 * V_43 = V_35 -> V_43 ;
struct V_200 * V_201 ;
const int V_202 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_203 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_204 ( V_205 ) , V_206 ;
V_201 = & ( V_122 -> V_88 . V_182 . V_88 . V_201 [ V_2 ] ) ;
if ( ! memcmp ( V_201 -> V_207 , V_203 , 3 ) )
continue;
V_206 = ( V_201 -> V_207 [ 0 ] + ( ( V_201 -> V_207 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_201 -> V_207 [ 1 ] & 0x0c ) {
case 0x00 :
V_205 = V_206 * 4 / 3 ;
break;
case 0x04 :
V_205 = V_206 * 16 / 9 ;
break;
case 0x08 :
V_205 = V_206 * 16 / 10 ;
break;
case 0x0c :
V_205 = V_206 * 15 / 9 ;
break;
}
for ( V_36 = 1 ; V_36 < 5 ; V_36 ++ ) {
if ( V_201 -> V_207 [ 2 ] & ( 1 << V_36 ) ) {
V_175 = F_50 ( V_43 , V_205 , V_206 ,
V_202 [ V_36 ] , V_36 == 0 ,
false , false ) ;
if ( V_175 ) {
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
}
}
}
return V_174 ;
}
static void
F_80 ( struct V_83 * V_122 , void * V_179 )
{
struct V_180 * V_79 = V_179 ;
struct V_181 * V_88 = & V_122 -> V_88 . V_182 ;
if ( V_88 -> type == V_208 )
V_79 -> V_174 += F_79 ( V_79 -> V_35 , V_122 ) ;
}
static int
F_81 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
struct V_180 V_79 = {
V_35 , V_7 , 0 , 0 , 0
} ;
if ( F_72 ( V_7 , 1 , 2 ) )
F_37 ( ( T_1 * ) V_7 , F_80 , & V_79 ) ;
return V_79 . V_174 ;
}
static void
F_82 ( struct V_83 * V_122 , void * V_179 )
{
struct V_180 * V_79 = V_179 ;
struct V_52 * V_175 ;
if ( V_122 -> V_148 ) {
V_175 = F_56 ( V_79 -> V_35 -> V_43 ,
V_79 -> V_7 , V_122 ,
V_79 -> V_51 ) ;
if ( ! V_175 )
return;
if ( V_79 -> V_209 )
V_175 -> type |= V_61 ;
F_67 ( V_79 -> V_35 , V_175 ) ;
V_79 -> V_174 ++ ;
V_79 -> V_209 = 0 ;
}
}
static int
F_83 ( struct V_34 * V_35 , struct V_7 * V_7 ,
T_2 V_51 )
{
struct V_180 V_79 = {
V_35 ,
V_7 ,
1 ,
V_51 ,
0
} ;
if ( V_79 . V_209 && ! F_72 ( V_7 , 1 , 3 ) )
V_79 . V_209 =
( V_7 -> V_93 & V_210 ) ;
F_37 ( ( T_1 * ) V_7 , F_82 , & V_79 ) ;
return V_79 . V_174 ;
}
T_1 * F_84 ( struct V_7 * V_7 )
{
T_1 * V_211 = NULL ;
int V_2 ;
if ( V_7 == NULL || V_7 -> V_16 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_7 -> V_16 ; V_2 ++ ) {
V_211 = ( T_1 * ) V_7 + V_10 * ( V_2 + 1 ) ;
if ( V_211 [ 0 ] == V_86 )
break;
}
if ( V_2 == V_7 -> V_16 )
return NULL ;
return V_211 ;
}
static int
F_85 ( struct V_34 * V_35 , T_1 * V_212 , T_1 V_20 )
{
struct V_69 * V_43 = V_35 -> V_43 ;
T_1 * V_62 , V_213 ;
int V_174 = 0 ;
for ( V_62 = V_212 ; V_62 < V_212 + V_20 ; V_62 ++ ) {
V_213 = ( * V_62 & 127 ) - 1 ;
if ( V_213 < V_214 ) {
struct V_52 * V_175 ;
V_175 = F_33 ( V_43 ,
& V_215 [ V_213 ] ) ;
if ( V_175 ) {
F_67 ( V_35 , V_175 ) ;
V_174 ++ ;
}
}
}
return V_174 ;
}
static int
F_86 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
T_1 * V_216 = F_84 ( V_7 ) ;
T_1 * V_212 , V_217 ;
int V_174 = 0 ;
if ( V_216 && V_216 [ 1 ] >= 3 ) {
for ( V_212 = V_216 + 4 ; V_212 < V_216 + V_216 [ 2 ] ; V_212 += V_217 + 1 ) {
V_217 = V_212 [ 0 ] & 0x1f ;
if ( ( ( V_212 [ 0 ] & 0xe0 ) >> 5 ) == V_218 )
V_174 += F_85 ( V_35 , V_212 + 1 , V_217 ) ;
}
}
return V_174 ;
}
static void
F_87 ( struct V_34 * V_35 , T_4 * V_212 )
{
V_35 -> V_219 [ 5 ] |= ( V_212 [ 6 ] >> 7 ) << 1 ;
V_35 -> V_220 = V_212 [ 6 ] & 1 ;
V_35 -> V_221 = V_212 [ 7 ] * 5 ;
V_35 -> V_222 [ 0 ] = V_212 [ 8 ] >> 7 ;
V_35 -> V_222 [ 1 ] = ( V_212 [ 8 ] >> 6 ) & 1 ;
V_35 -> V_223 [ 0 ] = V_212 [ 9 ] ;
V_35 -> V_224 [ 0 ] = V_212 [ 10 ] ;
V_35 -> V_223 [ 1 ] = V_212 [ 11 ] ;
V_35 -> V_224 [ 1 ] = V_212 [ 12 ] ;
F_88 ( L_14
L_15
L_16
L_17
L_18 ,
V_35 -> V_220 ,
V_35 -> V_221 ,
( int ) V_35 -> V_222 [ 0 ] ,
( int ) V_35 -> V_222 [ 1 ] ,
V_35 -> V_223 [ 0 ] ,
V_35 -> V_223 [ 1 ] ,
V_35 -> V_224 [ 0 ] ,
V_35 -> V_224 [ 1 ] ) ;
}
static void
F_89 ( struct V_83 * V_53 , void * V_88 )
{
if ( V_53 -> V_88 . V_182 . type == V_225 )
* ( T_1 * * ) V_88 = V_53 -> V_88 . V_182 . V_88 . V_226 . V_226 ;
}
void F_90 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
T_4 * V_219 = V_35 -> V_219 ;
T_1 * V_216 ;
T_1 * V_31 ;
T_1 * V_212 ;
int V_227 = 0 ;
int V_228 ;
int V_217 ;
memset ( V_219 , 0 , sizeof( V_35 -> V_219 ) ) ;
V_216 = F_84 ( V_7 ) ;
if ( ! V_216 ) {
F_10 ( L_19 ) ;
return;
}
V_31 = NULL ;
F_37 ( ( T_1 * ) V_7 , F_89 , & V_31 ) ;
for ( V_228 = 0 ; V_31 && V_228 < 13 ; V_228 ++ ) {
if ( V_31 [ V_228 ] == 0x0a )
break;
V_219 [ 20 + V_228 ] = V_31 [ V_228 ] ;
}
V_219 [ 4 ] = ( V_216 [ 1 ] << 5 ) | V_228 ;
F_10 ( L_20 , V_219 + 20 ) ;
V_219 [ 0 ] = 2 << 3 ;
V_219 [ 16 ] = V_7 -> V_46 [ 0 ] ;
V_219 [ 17 ] = V_7 -> V_46 [ 1 ] ;
V_219 [ 18 ] = V_7 -> V_229 [ 0 ] ;
V_219 [ 19 ] = V_7 -> V_229 [ 1 ] ;
if ( V_216 [ 1 ] >= 3 )
for ( V_212 = V_216 + 4 ; V_212 < V_216 + V_216 [ 2 ] ; V_212 += V_217 + 1 ) {
V_217 = V_212 [ 0 ] & 0x1f ;
switch ( ( V_212 [ 0 ] & 0xe0 ) >> 5 ) {
case V_230 :
V_227 = V_217 / 3 ;
memcpy ( V_219 + 20 + V_228 , & V_212 [ 1 ] , V_217 ) ;
break;
case V_231 :
V_219 [ 7 ] = V_212 [ 1 ] ;
break;
case V_232 :
if ( V_212 [ 1 ] == 0x03 && V_212 [ 2 ] == 0x0c && V_212 [ 3 ] == 0 )
F_87 ( V_35 , V_212 ) ;
break;
default:
break;
}
}
V_219 [ 5 ] |= V_227 << 4 ;
V_219 [ 2 ] = ( 20 + V_228 + V_227 * 3 + 3 ) / 4 ;
F_10 ( L_21 , ( int ) V_219 [ 2 ] , V_227 ) ;
}
int F_91 ( struct V_34 * V_35 ,
struct V_52 * V_62 )
{
int V_2 = ! ! ( V_62 -> V_28 & V_121 ) ;
int V_99 , V_233 ;
if ( ! V_35 -> V_222 [ 0 ] )
return 0 ;
if ( ! V_35 -> V_222 [ 1 ] )
V_2 = 0 ;
V_99 = V_35 -> V_224 [ V_2 ] ;
V_233 = V_35 -> V_223 [ V_2 ] ;
if ( V_99 == 255 || V_233 == 255 )
return 0 ;
if ( V_99 )
V_99 = F_36 ( 2 * ( V_99 - 1 ) , 500 ) ;
if ( V_233 )
V_233 = F_36 ( 2 * ( V_233 - 1 ) , 500 ) ;
return F_92 ( V_233 - V_99 , 0 ) ;
}
struct V_34 * F_93 ( struct V_234 * V_235 ,
struct V_52 * V_62 )
{
struct V_34 * V_35 ;
struct V_69 * V_43 = V_235 -> V_43 ;
F_49 (connector, &dev->mode_config.connector_list, head)
if ( V_35 -> V_235 == V_235 && V_35 -> V_219 [ 0 ] )
return V_35 ;
return NULL ;
}
bool F_94 ( struct V_7 * V_7 )
{
T_1 * V_211 ;
int V_2 , V_236 ;
int V_237 , V_238 ;
bool V_239 = false ;
V_211 = F_84 ( V_7 ) ;
if ( ! V_211 )
goto V_240;
V_237 = 4 ;
V_238 = V_211 [ 2 ] ;
for ( V_2 = V_237 ; V_2 < V_238 ;
V_2 += ( ( V_211 [ V_2 ] & 0x1f ) + 1 ) ) {
if ( ( V_211 [ V_2 ] >> 5 ) == V_232 ) {
V_236 = V_211 [ V_2 + 1 ] | ( V_211 [ V_2 + 2 ] << 8 ) |
V_211 [ V_2 + 3 ] << 16 ;
if ( V_236 == V_241 )
V_239 = true ;
break;
}
}
V_240:
return V_239 ;
}
bool F_95 ( struct V_7 * V_7 )
{
T_1 * V_211 ;
int V_2 , V_36 ;
bool V_242 = false ;
int V_237 , V_238 ;
V_211 = F_84 ( V_7 ) ;
if ( ! V_211 )
goto V_240;
V_242 = ( ( V_211 [ 3 ] & V_243 ) != 0 ) ;
if ( V_242 ) {
F_10 ( L_22 ) ;
goto V_240;
}
V_237 = 4 ;
V_238 = V_211 [ 2 ] ;
for ( V_2 = V_237 ; V_2 < V_238 ;
V_2 += ( ( V_211 [ V_2 ] & 0x1f ) + 1 ) ) {
if ( ( V_211 [ V_2 ] >> 5 ) == V_230 ) {
V_242 = true ;
for ( V_36 = 1 ; V_36 < ( V_211 [ V_2 ] & 0x1f ) ; V_36 += 3 )
F_10 ( L_23 ,
( V_211 [ V_2 + V_36 ] >> 3 ) & 0xf ) ;
goto V_240;
}
}
V_240:
return V_242 ;
}
static void F_96 ( struct V_7 * V_7 ,
struct V_244 * V_245 )
{
T_1 * V_211 ;
V_245 -> V_156 = V_7 -> V_163 * 10 ;
V_245 -> V_159 = V_7 -> V_164 * 10 ;
V_245 -> V_246 = 0 ;
V_245 -> V_247 = 0 ;
if ( V_7 -> V_12 < 3 )
return;
if ( ! ( V_7 -> V_91 & V_92 ) )
return;
V_211 = F_84 ( V_7 ) ;
if ( V_211 ) {
V_245 -> V_248 = V_211 [ 1 ] ;
V_245 -> V_247 = V_249 ;
if ( V_211 [ 3 ] & V_250 )
V_245 -> V_247 |= V_251 ;
if ( V_211 [ 3 ] & V_252 )
V_245 -> V_247 |= V_253 ;
}
if ( V_7 -> V_12 < 4 )
return;
switch ( V_7 -> V_91 & V_254 ) {
case V_255 :
V_245 -> V_246 = 6 ;
break;
case V_256 :
V_245 -> V_246 = 8 ;
break;
case V_257 :
V_245 -> V_246 = 10 ;
break;
case V_258 :
V_245 -> V_246 = 12 ;
break;
case V_259 :
V_245 -> V_246 = 14 ;
break;
case V_260 :
V_245 -> V_246 = 16 ;
break;
case V_261 :
default:
V_245 -> V_246 = 0 ;
break;
}
V_245 -> V_247 |= V_249 ;
if ( V_7 -> V_93 & V_262 )
V_245 -> V_247 |= V_251 ;
if ( V_7 -> V_93 & V_263 )
V_245 -> V_247 |= V_253 ;
}
int F_97 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
int V_264 = 0 ;
T_2 V_51 ;
if ( V_7 == NULL ) {
return 0 ;
}
if ( ! F_7 ( V_7 ) ) {
F_15 ( V_35 -> V_43 -> V_43 , L_24 ,
F_16 ( V_35 ) ) ;
return 0 ;
}
V_51 = F_21 ( V_7 ) ;
V_264 += F_83 ( V_35 , V_7 , V_51 ) ;
V_264 += F_81 ( V_35 , V_7 ) ;
V_264 += F_78 ( V_35 , V_7 ) ;
V_264 += F_76 ( V_35 , V_7 ) ;
V_264 += F_73 ( V_35 , V_7 ) ;
V_264 += F_86 ( V_35 , V_7 ) ;
if ( V_51 & ( V_58 | V_59 ) )
F_24 ( V_35 , V_51 ) ;
F_96 ( V_7 , & V_35 -> V_44 ) ;
return V_264 ;
}
int F_98 ( struct V_34 * V_35 ,
int V_64 , int V_68 )
{
int V_2 , V_265 , V_264 = 0 ;
struct V_52 * V_62 ;
struct V_69 * V_43 = V_35 -> V_43 ;
V_265 = sizeof( V_76 ) / sizeof( struct V_52 ) ;
if ( V_64 < 0 )
V_64 = 0 ;
if ( V_68 < 0 )
V_68 = 0 ;
for ( V_2 = 0 ; V_2 < V_265 ; V_2 ++ ) {
const struct V_52 * V_75 = & V_76 [ V_2 ] ;
if ( V_64 && V_68 ) {
if ( V_75 -> V_64 > V_64 ||
V_75 -> V_68 > V_68 )
continue;
}
if ( F_32 ( V_75 ) > 61 )
continue;
V_62 = F_33 ( V_43 , V_75 ) ;
if ( V_62 ) {
F_67 ( V_35 , V_62 ) ;
V_264 ++ ;
}
}
return V_264 ;
}
