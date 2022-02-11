T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
if ( V_1 -> V_5 < V_1 -> V_6 )
return V_7 ;
if ( V_1 -> type == V_8 || V_1 -> type == V_9 )
F_2 ( V_3 , V_10 , - ( signed char ) V_4 [ 3 ] ) ;
if ( V_1 -> type == V_11 ) {
switch ( V_4 [ 3 ] & 0xC0 ) {
case 0x80 :
F_2 ( V_3 , V_10 , ( int ) ( V_4 [ 3 ] & 32 ) - ( int ) ( V_4 [ 3 ] & 31 ) ) ;
break;
case 0x40 :
F_2 ( V_3 , V_12 , ( int ) ( V_4 [ 3 ] & 32 ) - ( int ) ( V_4 [ 3 ] & 31 ) ) ;
break;
case 0x00 :
case 0xC0 :
F_2 ( V_3 , V_10 , ( int ) ( V_4 [ 3 ] & 8 ) - ( int ) ( V_4 [ 3 ] & 7 ) ) ;
F_3 ( V_3 , V_13 , ( V_4 [ 3 ] >> 4 ) & 1 ) ;
F_3 ( V_3 , V_14 , ( V_4 [ 3 ] >> 5 ) & 1 ) ;
break;
}
}
if ( V_1 -> type == V_9 ) {
F_3 ( V_3 , V_13 , ( V_4 [ 0 ] >> 6 ) & 1 ) ;
F_3 ( V_3 , V_14 , ( V_4 [ 0 ] >> 7 ) & 1 ) ;
}
if ( V_1 -> type == V_15 ) {
F_3 ( V_3 , V_14 , ( V_4 [ 0 ] >> 3 ) & 1 ) ;
V_4 [ 1 ] |= ( V_4 [ 0 ] & 0x40 ) << 1 ;
}
if ( V_1 -> type == V_16 ) {
F_3 ( V_3 , V_13 , ( V_4 [ 0 ] >> 3 ) & 1 ) ;
V_4 [ 0 ] |= 0x08 ;
}
F_3 ( V_3 , V_17 , V_4 [ 0 ] & 1 ) ;
F_3 ( V_3 , V_18 , ( V_4 [ 0 ] >> 2 ) & 1 ) ;
F_3 ( V_3 , V_19 , ( V_4 [ 0 ] >> 1 ) & 1 ) ;
F_2 ( V_3 , V_20 , V_4 [ 1 ] ? ( int ) V_4 [ 1 ] - ( int ) ( ( V_4 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_2 ( V_3 , V_21 , V_4 [ 2 ] ? ( int ) ( ( V_4 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_4 [ 2 ] : 0 ) ;
F_4 ( V_3 ) ;
return V_22 ;
}
void F_5 ( struct V_1 * V_1 , struct V_23 * V_24 ,
unsigned long V_25 )
{
F_6 ( V_26 , V_24 , V_25 ) ;
}
static inline void F_7 ( struct V_1 * V_1 , enum V_27 V_28 )
{
V_1 -> V_29 = V_28 ;
V_1 -> V_5 = V_1 -> V_30 = 0 ;
V_1 -> V_31 . V_32 = 0 ;
V_1 -> V_33 = V_34 ;
}
void F_8 ( struct V_1 * V_1 , enum V_27 V_28 )
{
F_9 ( V_1 -> V_31 . V_35 ) ;
F_7 ( V_1 , V_28 ) ;
F_10 ( V_1 -> V_31 . V_35 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
T_1 V_36 = V_1 -> V_37 ( V_1 ) ;
switch ( V_36 ) {
case V_38 :
if ( V_1 -> V_29 == V_39 ) {
F_12 ( V_1 ,
L_1 ,
V_1 -> V_40 , V_1 -> V_41 ,
V_1 -> V_5 ) ;
if ( ++ V_1 -> V_30 == V_1 -> V_42 ) {
F_7 ( V_1 , V_43 ) ;
F_13 ( V_1 ,
L_2 ) ;
F_14 ( V_1 -> V_31 . V_35 ) ;
return - 1 ;
}
}
V_1 -> V_5 = 0 ;
break;
case V_22 :
V_1 -> V_5 = 0 ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 = 0 ;
F_13 ( V_1 ,
L_3 ,
V_1 -> V_40 , V_1 -> V_41 ) ;
}
break;
case V_7 :
break;
}
return 0 ;
}
static T_2 F_15 ( struct V_35 * V_35 ,
unsigned char V_44 , unsigned int V_32 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
if ( V_1 -> V_29 == V_43 )
goto V_45;
if ( F_17 ( ( V_32 & V_46 ) ||
( ( V_32 & V_47 ) && ! V_1 -> V_48 ) ) ) {
if ( V_1 -> V_29 == V_39 )
F_12 ( V_1 ,
L_4 ,
V_32 & V_46 ? L_5 : L_6 ,
V_32 & V_47 ? L_7 : L_6 ) ;
F_18 ( & V_1 -> V_31 ) ;
goto V_45;
}
if ( F_17 ( V_1 -> V_31 . V_32 & V_49 ) )
if ( F_19 ( & V_1 -> V_31 , V_44 ) )
goto V_45;
if ( F_17 ( V_1 -> V_31 . V_32 & V_50 ) )
if ( F_20 ( & V_1 -> V_31 , V_44 ) )
goto V_45;
if ( V_1 -> V_29 <= V_51 )
goto V_45;
if ( V_1 -> V_29 == V_39 &&
V_1 -> V_5 && F_21 ( V_34 , V_1 -> V_33 + V_52 / 2 ) ) {
F_22 ( V_1 , L_8 ,
V_1 -> V_40 , V_1 -> V_41 , V_1 -> V_5 ) ;
V_1 -> V_53 = V_1 -> V_4 [ 0 ] ;
F_7 ( V_1 , V_51 ) ;
F_5 ( V_1 , & V_1 -> V_54 , 0 ) ;
goto V_45;
}
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_44 ;
if ( F_17 ( V_1 -> V_4 [ 0 ] == V_55 && V_1 -> V_5 <= 2 ) ) {
if ( V_1 -> V_5 == 1 ) {
V_1 -> V_33 = V_34 ;
goto V_45;
}
if ( V_1 -> V_4 [ 1 ] == V_56 ||
( V_1 -> type == V_57 &&
V_1 -> V_4 [ 1 ] == V_55 ) ) {
F_7 ( V_1 , V_43 ) ;
F_14 ( V_35 ) ;
goto V_45;
}
V_1 -> V_5 = 1 ;
if ( F_11 ( V_1 ) )
goto V_45;
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_44 ;
}
if ( V_1 -> V_29 == V_39 &&
V_1 -> V_5 == 1 && V_1 -> V_58 &&
F_21 ( V_34 , V_1 -> V_33 + V_1 -> V_58 * V_52 ) ) {
V_1 -> V_53 = V_1 -> V_4 [ 0 ] ;
F_7 ( V_1 , V_51 ) ;
F_5 ( V_1 , & V_1 -> V_54 , 0 ) ;
goto V_45;
}
V_1 -> V_33 = V_34 ;
F_11 ( V_1 ) ;
V_45:
return V_59 ;
}
int F_23 ( struct V_1 * V_1 , unsigned char V_60 )
{
int V_61 ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_62 ) )
return - 1 ;
for ( V_61 = 6 ; V_61 >= 0 ; V_61 -= 2 ) {
unsigned char V_63 = ( V_60 >> V_61 ) & 3 ;
if ( F_24 ( & V_1 -> V_31 , & V_63 , V_64 ) )
return - 1 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_1 )
{
unsigned char V_65 [ 2 ] ;
if ( F_24 ( & V_1 -> V_31 , V_65 , V_66 ) )
return - 1 ;
if ( V_65 [ 0 ] != V_55 && V_65 [ 1 ] != V_56 )
return - 1 ;
return 0 ;
}
void F_26 ( struct V_1 * V_1 , unsigned int V_67 )
{
static const unsigned char V_68 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_69 ;
if ( V_67 == 0 || V_67 > 200 )
V_67 = 200 ;
V_69 = V_68 [ V_67 / 50 ] ;
F_24 ( & V_1 -> V_31 , & V_69 , V_64 ) ;
V_1 -> V_67 = 25 << V_69 ;
}
static void F_27 ( struct V_1 * V_1 , unsigned int V_70 )
{
static const unsigned char V_71 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 , 0 } ;
unsigned char V_72 ;
int V_61 = 0 ;
while ( V_71 [ V_61 ] > V_70 ) V_61 ++ ;
V_72 = V_71 [ V_61 ] ;
F_24 ( & V_1 -> V_31 , & V_72 , V_73 ) ;
V_1 -> V_70 = V_72 ;
}
static void F_28 ( struct V_1 * V_1 , enum V_74 V_75 )
{
F_24 ( & V_1 -> V_31 , NULL ,
V_75 == V_76 ? V_77 :
V_62 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
return F_24 ( & V_1 -> V_31 , V_1 -> V_4 ,
V_78 | ( V_1 -> V_6 << 8 ) ) ;
}
static bool F_30 ( const char * V_79 , const char * const V_80 [] )
{
int V_61 ;
for ( V_61 = 0 ; V_80 [ V_61 ] ; V_61 ++ )
if ( ! strcasecmp ( V_79 , V_80 [ V_61 ] ) )
return true ;
return false ;
}
bool F_31 ( struct V_1 * V_1 , const char * const V_80 [] )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
char * V_69 , * V_81 , * V_82 ;
bool V_83 = false ;
if ( strncmp ( V_35 -> V_84 , L_9 , 5 ) )
return false ;
V_81 = F_32 ( & V_35 -> V_84 [ 5 ] ,
sizeof( V_35 -> V_84 ) - 5 ,
V_85 ) ;
if ( ! V_81 )
return false ;
V_82 = V_81 ;
while ( ( V_69 = F_33 ( & V_81 , L_10 ) ) != NULL ) {
if ( F_30 ( V_69 , V_80 ) ) {
V_83 = true ;
break;
}
}
F_34 ( V_82 ) ;
return V_83 ;
}
static int F_35 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 4 ] ;
V_65 [ 0 ] = 3 ;
F_24 ( V_31 , V_65 , V_64 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , V_65 , V_87 ) ;
if ( V_65 [ 0 ] != 0x00 || V_65 [ 1 ] != 0x33 || V_65 [ 2 ] != 0x55 )
return - 1 ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_14 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_13 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_10 , V_1 -> V_3 -> V_89 ) ;
V_1 -> V_90 = L_11 ;
V_1 -> V_40 = L_12 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 100 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_91 ) ;
if ( V_65 [ 0 ] != 3 )
return - 1 ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_10 , V_1 -> V_3 -> V_89 ) ;
if ( ! V_1 -> V_90 )
V_1 -> V_90 = L_13 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_14 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
F_37 ( V_1 , 0 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_91 ) ;
if ( V_65 [ 0 ] != 4 )
return - 1 ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 40 ;
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_10 , V_1 -> V_3 -> V_89 ) ;
F_36 ( V_12 , V_1 -> V_3 -> V_89 ) ;
F_36 ( V_13 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_14 , V_1 -> V_3 -> V_88 ) ;
if ( ! V_1 -> V_90 )
V_1 -> V_90 = L_13 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_15 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
static const unsigned char V_92 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_61 ;
V_65 [ 0 ] = 10 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 0 ;
F_24 ( V_31 , V_65 , V_64 ) ;
for ( V_61 = 0 ; V_61 < F_40 ( V_92 ) ; V_61 ++ ) {
V_65 [ 0 ] = V_92 [ V_61 ] ;
F_24 ( V_31 , V_65 , V_73 ) ;
}
F_24 ( V_31 , V_65 , V_91 ) ;
if ( V_65 [ 0 ] != 2 )
return - 1 ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_14 , V_1 -> V_3 -> V_88 ) ;
V_1 -> V_90 = L_16 ;
V_1 -> V_40 = L_17 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , bool V_86 )
{
if ( V_86 ) {
if ( ! V_1 -> V_90 )
V_1 -> V_90 = L_13 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_12 ;
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , bool V_86 )
{
if ( V_86 ) {
V_1 -> V_90 = L_18 ;
V_1 -> V_40 = L_19 ;
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_13 , V_1 -> V_3 -> V_88 ) ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
memset ( V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
memset ( V_2 -> V_88 , 0 , sizeof( V_2 -> V_88 ) ) ;
memset ( V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
memset ( V_2 -> V_94 , 0 , sizeof( V_2 -> V_94 ) ) ;
memset ( V_2 -> V_95 , 0 , sizeof( V_2 -> V_95 ) ) ;
F_36 ( V_96 , V_2 -> V_93 ) ;
F_36 ( V_97 , V_2 -> V_93 ) ;
F_36 ( V_17 , V_2 -> V_88 ) ;
F_36 ( V_19 , V_2 -> V_88 ) ;
F_36 ( V_20 , V_2 -> V_89 ) ;
F_36 ( V_21 , V_2 -> V_89 ) ;
F_36 ( V_98 , V_2 -> V_99 ) ;
V_1 -> V_100 = F_27 ;
V_1 -> V_101 = F_26 ;
V_1 -> V_102 = F_28 ;
V_1 -> V_103 = F_29 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_6 = 3 ;
V_1 -> V_104 = NULL ;
V_1 -> V_105 = NULL ;
V_1 -> V_106 = NULL ;
V_1 -> V_107 = NULL ;
V_1 -> V_108 = NULL ;
}
static int F_44 ( int (* F_45)( struct V_1 * V_1 ,
bool V_86 ) ,
struct V_1 * V_1 , bool V_86 )
{
if ( V_86 )
F_43 ( V_1 ) ;
return F_45 ( V_1 , V_86 ) ;
}
static int F_46 ( struct V_1 * V_1 ,
unsigned int V_109 , bool V_86 )
{
bool V_110 = false ;
if ( F_44 ( V_111 , V_1 , V_86 ) == 0 ) {
if ( V_109 > V_11 ) {
if ( ! V_86 || F_47 ( V_1 ) == 0 ) {
if ( F_48 ( V_112 ) )
return V_113 ;
V_114 = V_115 ;
return V_115 ;
}
}
}
if ( F_44 ( V_116 , V_1 , V_86 ) == 0 ) {
if ( V_109 > V_11 ) {
if ( ! V_86 || F_49 ( V_1 ) == 0 )
return V_117 ;
}
}
if ( F_44 ( V_118 , V_1 , V_86 ) == 0 ) {
if ( V_109 > V_11 ) {
if ( ! V_86 || F_50 ( V_1 ) == 0 )
return V_119 ;
}
}
if ( V_109 > V_11 &&
F_44 ( F_39 , V_1 , V_86 ) == 0 ) {
return V_15 ;
}
if ( V_109 > V_115 &&
F_44 ( V_120 , V_1 , V_86 ) == 0 ) {
V_110 = true ;
if ( V_109 > V_11 ) {
if ( F_48 ( V_121 ) &&
( ! V_86 || F_51 ( V_1 ) == 0 ) ) {
return V_122 ;
}
V_109 = V_11 ;
}
F_52 ( V_1 ) ;
}
if ( V_109 > V_11 &&
F_53 ( V_1 , V_86 ) == 0 ) {
if ( F_48 ( V_123 ) ) {
if ( F_54 ( V_1 ) == 0 )
return V_124 ;
return V_115 ;
}
V_109 = V_11 ;
}
if ( V_109 > V_11 ) {
F_24 ( & V_1 -> V_31 , NULL , V_125 ) ;
if ( F_44 ( V_126 ,
V_1 , V_86 ) == 0 ) {
if ( ! V_86 || F_55 ( V_1 ) == 0 )
return V_127 ;
V_109 = V_11 ;
}
}
if ( V_109 > V_11 &&
F_44 ( V_128 , V_1 , V_86 ) == 0 ) {
if ( ! V_86 || F_56 ( V_1 ) == 0 )
return V_57 ;
V_109 = V_11 ;
}
if ( V_109 > V_11 &&
F_44 ( V_129 , V_1 , V_86 ) == 0 ) {
if ( ! V_86 || F_57 ( V_1 ) == 0 )
return V_130 ;
V_109 = V_11 ;
}
if ( V_109 > V_11 ) {
if ( F_44 ( F_35 ,
V_1 , V_86 ) == 0 )
return V_9 ;
if ( F_44 ( V_131 ,
V_1 , V_86 ) == 0 )
return V_132 ;
if ( F_44 ( V_133 ,
V_1 , V_86 ) == 0 )
return V_134 ;
if ( F_44 ( V_135 ,
V_1 , V_86 ) == 0 )
return V_136 ;
}
if ( V_109 > V_11 ) {
if ( F_44 ( V_137 ,
V_1 , V_86 ) == 0 ) {
if ( ! V_86 || F_58 ( V_1 ) == 0 )
return V_138 ;
V_109 = V_11 ;
}
}
F_24 ( & V_1 -> V_31 , NULL , V_125 ) ;
F_25 ( V_1 ) ;
if ( V_109 >= V_11 &&
F_44 ( F_38 ,
V_1 , V_86 ) == 0 ) {
return V_11 ;
}
if ( V_109 >= V_8 &&
F_44 ( F_37 ,
V_1 , V_86 ) == 0 ) {
return V_8 ;
}
F_44 ( F_41 , V_1 , V_86 ) ;
if ( V_110 ) {
F_25 ( V_1 ) ;
}
return V_115 ;
}
static const struct V_139 * F_59 ( enum V_140 type )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_40 ( V_141 ) ; V_61 ++ )
if ( V_141 [ V_61 ] . type == type )
return & V_141 [ V_61 ] ;
F_60 ( 1 ) ;
return & V_141 [ 0 ] ;
}
static const struct V_139 * F_61 ( const char * V_40 , T_3 V_142 )
{
const struct V_139 * V_69 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_40 ( V_141 ) ; V_61 ++ ) {
V_69 = & V_141 [ V_61 ] ;
if ( ( strlen ( V_69 -> V_40 ) == V_142 && ! strncmp ( V_69 -> V_40 , V_40 , V_142 ) ) ||
( strlen ( V_69 -> V_143 ) == V_142 && ! strncmp ( V_69 -> V_143 , V_40 , V_142 ) ) )
return & V_141 [ V_61 ] ;
}
return NULL ;
}
static int F_62 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 0xa5 ;
if ( F_24 ( V_31 , V_65 , V_91 ) )
return - 1 ;
if ( V_65 [ 0 ] != 0x00 && V_65 [ 0 ] != 0x03 &&
V_65 [ 0 ] != 0x04 && V_65 [ 0 ] != 0xff )
return - 1 ;
if ( F_24 ( V_31 , NULL , V_125 ) )
F_12 ( V_1 , L_20 ,
V_31 -> V_35 -> V_41 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_1 )
{
if ( V_114 != V_115 ) {
V_1 -> V_100 ( V_1 , V_1 -> V_70 ) ;
V_1 -> V_101 ( V_1 , V_1 -> V_67 ) ;
V_1 -> V_102 ( V_1 , V_144 ) ;
}
}
int F_64 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_145 ) ) {
F_12 ( V_1 , L_21 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_39 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_146 ) ) {
F_12 ( V_1 , L_22 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_147 ) ;
return 0 ;
}
static void F_66 ( struct V_148 * V_24 )
{
struct V_1 * V_149 = NULL , * V_1 =
F_67 ( V_24 , struct V_1 , V_54 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_150 = false , V_151 = false ;
int V_61 ;
F_68 ( & V_152 ) ;
if ( V_1 -> V_29 != V_51 )
goto V_45;
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
F_65 ( V_149 ) ;
}
V_1 -> V_154 ++ ;
if ( F_69 ( & V_1 -> V_31 , V_146 , 20 ) ) {
if ( V_1 -> V_154 < 3 || V_1 -> V_155 )
V_150 = true ;
} else
V_1 -> V_155 = true ;
if ( ! V_150 ) {
if ( V_1 -> V_103 ( V_1 ) )
V_150 = true ;
else {
F_8 ( V_1 , V_147 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_6 ; V_61 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_150 = true ;
F_8 ( V_1 , V_51 ) ;
}
}
for ( V_61 = 0 ; V_61 < 5 ; V_61 ++ ) {
if ( ! F_24 ( & V_1 -> V_31 , NULL , V_145 ) ) {
V_151 = true ;
break;
}
F_70 ( 200 ) ;
}
if ( ! V_151 ) {
F_12 ( V_1 , L_23 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
V_150 = true ;
}
if ( V_150 ) {
F_8 ( V_1 , V_43 ) ;
F_22 ( V_1 ,
L_24 ) ;
F_14 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_149 )
F_64 ( V_149 ) ;
V_45:
F_71 ( & V_152 ) ;
}
static void F_72 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_149 = NULL ;
F_68 ( & V_152 ) ;
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
F_65 ( V_149 ) ;
}
F_8 ( V_1 , V_156 ) ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_146 ) )
F_12 ( V_1 , L_25 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
if ( V_1 -> V_106 )
V_1 -> V_106 ( V_1 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_125 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_145 ) ;
if ( V_149 ) {
if ( V_149 -> V_108 )
V_149 -> V_108 ( V_149 ) ;
F_64 ( V_149 ) ;
}
F_71 ( & V_152 ) ;
}
static void F_73 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_149 = NULL ;
V_1 = F_16 ( V_35 ) ;
F_74 ( & V_35 -> V_3 . V_157 , & V_158 ) ;
F_68 ( & V_152 ) ;
F_8 ( V_1 , V_147 ) ;
F_71 ( & V_152 ) ;
F_75 ( V_26 ) ;
F_68 ( & V_152 ) ;
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
F_65 ( V_149 ) ;
}
if ( V_1 -> V_105 )
V_1 -> V_105 ( V_1 ) ;
if ( V_149 && V_149 -> V_108 )
V_149 -> V_108 ( V_149 ) ;
F_8 ( V_1 , V_43 ) ;
F_76 ( V_35 ) ;
F_77 ( V_35 , NULL ) ;
F_78 ( V_1 -> V_3 ) ;
F_34 ( V_1 ) ;
if ( V_149 )
F_64 ( V_149 ) ;
F_71 ( & V_152 ) ;
}
static int F_79 ( struct V_1 * V_1 ,
const struct V_139 * V_159 )
{
const struct V_139 * V_160 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_149 = & V_1 -> V_31 . V_35 -> V_3 ;
if ( V_159 && ( V_159 -> F_45 || V_159 -> V_161 ) ) {
F_43 ( V_1 ) ;
if ( V_159 -> F_45 && V_159 -> F_45 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_159 -> V_161 && V_159 -> V_161 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_159 -> type ;
V_160 = V_159 ;
} else {
V_1 -> type = F_46 ( V_1 ,
V_114 , true ) ;
V_160 = F_59 ( V_1 -> type ) ;
}
V_1 -> V_48 = V_160 -> V_48 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_58 = 0 ;
if ( V_1 -> V_58 && V_1 -> V_103 ( V_1 ) )
V_1 -> V_58 = 0 ;
snprintf ( V_1 -> V_162 , sizeof( V_1 -> V_162 ) , L_26 ,
V_160 -> V_40 , V_1 -> V_90 , V_1 -> V_40 ) ;
V_2 -> V_40 = V_1 -> V_162 ;
V_2 -> V_41 = V_1 -> V_41 ;
V_2 -> V_79 . V_163 = V_164 ;
V_2 -> V_79 . V_90 = 0x0002 ;
V_2 -> V_79 . V_165 = V_1 -> type ;
V_2 -> V_79 . V_166 = V_1 -> V_167 ;
return 0 ;
}
static int F_80 ( struct V_35 * V_35 , struct V_168 * V_169 )
{
struct V_1 * V_1 , * V_149 = NULL ;
struct V_2 * V_2 ;
int V_170 = 0 , error = - V_171 ;
F_68 ( & V_152 ) ;
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
F_65 ( V_149 ) ;
}
V_1 = F_81 ( sizeof( struct V_1 ) , V_85 ) ;
V_2 = F_82 () ;
if ( ! V_1 || ! V_2 )
goto V_172;
F_83 ( & V_1 -> V_31 , V_35 ) ;
F_84 ( & V_1 -> V_54 , F_66 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_41 , sizeof( V_1 -> V_41 ) , L_27 , V_35 -> V_41 ) ;
F_8 ( V_1 , V_156 ) ;
F_77 ( V_35 , V_1 ) ;
error = F_85 ( V_35 , V_169 ) ;
if ( error )
goto V_173;
if ( F_62 ( V_1 ) < 0 ) {
error = - V_174 ;
goto V_175;
}
V_1 -> V_70 = V_176 ;
V_1 -> V_67 = V_177 ;
V_1 -> V_42 = V_178 ;
V_1 -> V_58 = V_149 ? 0 : V_179 ;
V_1 -> V_180 = V_181 ;
F_79 ( V_1 , NULL ) ;
F_8 ( V_1 , V_147 ) ;
F_63 ( V_1 ) ;
error = F_86 ( V_1 -> V_3 ) ;
if ( error )
goto V_182;
if ( V_149 && V_149 -> V_107 )
V_149 -> V_107 ( V_149 ) ;
error = F_87 ( & V_35 -> V_3 . V_157 , & V_158 ) ;
if ( error )
goto V_183;
F_64 ( V_1 ) ;
V_45:
if ( V_149 )
F_64 ( V_149 ) ;
F_71 ( & V_152 ) ;
return V_170 ;
V_183:
if ( V_149 && V_149 -> V_108 )
V_149 -> V_108 ( V_149 ) ;
F_78 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_182:
if ( V_1 -> V_105 )
V_1 -> V_105 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_175:
F_76 ( V_35 ) ;
V_173:
F_77 ( V_35 , NULL ) ;
V_172:
F_88 ( V_2 ) ;
F_34 ( V_1 ) ;
V_170 = error ;
goto V_45;
}
static int F_89 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_149 = NULL ;
unsigned char type ;
int V_36 = - 1 ;
F_68 ( & V_152 ) ;
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
F_65 ( V_149 ) ;
}
F_8 ( V_1 , V_156 ) ;
if ( V_1 -> V_104 ) {
if ( V_1 -> V_104 ( V_1 ) )
goto V_45;
} else {
F_25 ( V_1 ) ;
if ( F_62 ( V_1 ) < 0 )
goto V_45;
type = F_46 ( V_1 , V_114 , false ) ;
if ( V_1 -> type != type )
goto V_45;
}
F_8 ( V_1 , V_147 ) ;
F_63 ( V_1 ) ;
if ( V_149 && V_149 -> V_107 )
V_149 -> V_107 ( V_149 ) ;
F_64 ( V_1 ) ;
V_36 = 0 ;
V_45:
if ( V_149 )
F_64 ( V_149 ) ;
F_71 ( & V_152 ) ;
return V_36 ;
}
T_4 F_90 ( struct V_184 * V_3 , struct V_185 * V_186 ,
char * V_187 )
{
struct V_35 * V_35 = F_91 ( V_3 ) ;
struct V_188 * V_189 = F_92 ( V_186 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( V_35 ) ;
return V_189 -> V_190 ( V_1 , V_189 -> V_44 , V_187 ) ;
}
T_4 F_93 ( struct V_184 * V_3 , struct V_185 * V_186 ,
const char * V_187 , T_3 V_191 )
{
struct V_35 * V_35 = F_91 ( V_3 ) ;
struct V_188 * V_189 = F_92 ( V_186 ) ;
struct V_1 * V_1 , * V_149 = NULL ;
int V_170 ;
V_170 = F_94 ( & V_152 ) ;
if ( V_170 )
goto V_45;
V_1 = F_16 ( V_35 ) ;
if ( V_189 -> V_192 ) {
if ( V_1 -> V_29 == V_43 ) {
V_170 = - V_174 ;
goto V_193;
}
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
F_65 ( V_149 ) ;
}
F_65 ( V_1 ) ;
}
V_170 = V_189 -> V_194 ( V_1 , V_189 -> V_44 , V_187 , V_191 ) ;
if ( V_189 -> V_192 ) {
if ( V_170 != - V_174 )
F_64 ( V_1 ) ;
if ( V_149 )
F_64 ( V_149 ) ;
}
V_193:
F_71 ( & V_152 ) ;
V_45:
return V_170 ;
}
static T_4 F_95 ( struct V_1 * V_1 , void * V_195 , char * V_187 )
{
unsigned int * V_196 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_195 ) ;
return sprintf ( V_187 , L_28 , * V_196 ) ;
}
static T_4 F_96 ( struct V_1 * V_1 , void * V_195 , const char * V_187 , T_3 V_191 )
{
unsigned int * V_196 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_195 ) ;
unsigned int V_197 ;
int V_198 ;
V_198 = F_97 ( V_187 , 10 , & V_197 ) ;
if ( V_198 )
return V_198 ;
* V_196 = V_197 ;
return V_191 ;
}
static T_4 F_98 ( struct V_1 * V_1 , void * V_44 , char * V_187 )
{
return sprintf ( V_187 , L_29 , F_59 ( V_1 -> type ) -> V_40 ) ;
}
static T_4 F_99 ( struct V_1 * V_1 , void * V_44 , const char * V_187 , T_3 V_191 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_149 = NULL ;
struct V_2 * V_199 , * V_200 ;
const struct V_139 * V_159 , * V_201 ;
int error ;
int V_202 = 0 ;
V_159 = F_61 ( V_187 , V_191 ) ;
if ( ! V_159 )
return - V_203 ;
if ( V_1 -> type == V_159 -> type )
return V_191 ;
V_200 = F_82 () ;
if ( ! V_200 )
return - V_171 ;
while ( ! F_100 ( & V_35 -> V_204 ) ) {
if ( ++ V_202 > 3 ) {
F_12 ( V_1 ,
L_30 ) ;
F_88 ( V_200 ) ;
return - V_205 ;
}
F_71 ( & V_152 ) ;
F_101 ( V_35 ) ;
F_68 ( & V_152 ) ;
if ( V_35 -> V_169 != & V_206 ) {
F_88 ( V_200 ) ;
return - V_174 ;
}
if ( V_1 -> type == V_159 -> type ) {
F_88 ( V_200 ) ;
return V_191 ;
}
}
if ( V_35 -> V_149 && V_35 -> V_79 . type == V_153 ) {
V_149 = F_16 ( V_35 -> V_149 ) ;
if ( V_149 -> V_108 )
V_149 -> V_108 ( V_149 ) ;
}
V_199 = V_1 -> V_3 ;
V_201 = F_59 ( V_1 -> type ) ;
if ( V_1 -> V_105 )
V_1 -> V_105 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_1 -> V_3 = V_200 ;
F_8 ( V_1 , V_156 ) ;
if ( F_79 ( V_1 , V_159 ) < 0 ) {
F_25 ( V_1 ) ;
F_79 ( V_1 , & V_141 [ 0 ] ) ;
}
F_63 ( V_1 ) ;
F_8 ( V_1 , V_147 ) ;
error = F_86 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_105 )
V_1 -> V_105 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
F_88 ( V_200 ) ;
V_1 -> V_3 = V_199 ;
F_8 ( V_1 , V_156 ) ;
F_79 ( V_1 , V_201 ) ;
F_63 ( V_1 ) ;
F_8 ( V_1 , V_147 ) ;
return error ;
}
F_78 ( V_199 ) ;
if ( V_149 && V_149 -> V_107 )
V_149 -> V_107 ( V_149 ) ;
return V_191 ;
}
static T_4 F_102 ( struct V_1 * V_1 , void * V_44 , const char * V_187 , T_3 V_191 )
{
unsigned int V_197 ;
int V_198 ;
V_198 = F_97 ( V_187 , 10 , & V_197 ) ;
if ( V_198 )
return V_198 ;
V_1 -> V_100 ( V_1 , V_197 ) ;
return V_191 ;
}
static T_4 F_103 ( struct V_1 * V_1 , void * V_44 , const char * V_187 , T_3 V_191 )
{
unsigned int V_197 ;
int V_198 ;
V_198 = F_97 ( V_187 , 10 , & V_197 ) ;
if ( V_198 )
return V_198 ;
V_1 -> V_101 ( V_1 , V_197 ) ;
return V_191 ;
}
static int F_104 ( const char * V_207 , const struct V_208 * V_209 )
{
const struct V_139 * V_159 ;
if ( ! V_207 )
return - V_203 ;
V_159 = F_61 ( V_207 , strlen ( V_207 ) ) ;
if ( ! V_159 || ! V_159 -> V_210 )
return - V_203 ;
* ( ( unsigned int * ) V_209 -> V_211 ) = V_159 -> type ;
return 0 ;
}
static int F_105 ( char * V_212 , const struct V_208 * V_209 )
{
int type = * ( ( unsigned int * ) V_209 -> V_211 ) ;
return sprintf ( V_212 , L_31 , F_59 ( type ) -> V_40 ) ;
}
static int T_5 F_106 ( void )
{
int V_198 ;
F_107 () ;
F_108 () ;
F_109 () ;
V_26 = F_110 ( L_32 ) ;
if ( ! V_26 ) {
F_111 ( L_33 ) ;
return - V_171 ;
}
V_198 = F_112 ( & V_206 ) ;
if ( V_198 )
F_113 ( V_26 ) ;
return V_198 ;
}
static void T_6 F_114 ( void )
{
F_115 ( & V_206 ) ;
F_113 ( V_26 ) ;
}
