static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 & F_3 ( 0 ) ) ;
F_2 ( V_2 , V_5 , V_3 & F_3 ( 2 ) ) ;
F_2 ( V_2 , V_6 , V_3 & F_3 ( 1 ) ) ;
}
T_2 F_4 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned char * V_8 = V_7 -> V_8 ;
if ( V_7 -> V_9 < V_7 -> V_10 )
return V_11 ;
switch ( V_7 -> V_12 -> type ) {
case V_13 :
F_5 ( V_2 , V_14 , - ( signed char ) V_8 [ 3 ] ) ;
break;
case V_15 :
switch ( V_8 [ 3 ] & 0xC0 ) {
case 0x80 :
F_5 ( V_2 , V_14 , ( int ) ( V_8 [ 3 ] & 32 ) - ( int ) ( V_8 [ 3 ] & 31 ) ) ;
break;
case 0x40 :
F_5 ( V_2 , V_16 , ( int ) ( V_8 [ 3 ] & 32 ) - ( int ) ( V_8 [ 3 ] & 31 ) ) ;
break;
case 0x00 :
case 0xC0 :
F_5 ( V_2 , V_14 , ( int ) ( V_8 [ 3 ] & 8 ) - ( int ) ( V_8 [ 3 ] & 7 ) ) ;
F_2 ( V_2 , V_17 , ( V_8 [ 3 ] >> 4 ) & 1 ) ;
F_2 ( V_2 , V_18 , ( V_8 [ 3 ] >> 5 ) & 1 ) ;
break;
}
break;
case V_19 :
F_5 ( V_2 , V_14 , - ( signed char ) V_8 [ 3 ] ) ;
F_2 ( V_2 , V_17 , ( V_8 [ 0 ] >> 6 ) & 1 ) ;
F_2 ( V_2 , V_18 , ( V_8 [ 0 ] >> 7 ) & 1 ) ;
break;
case V_20 :
F_2 ( V_2 , V_18 , ( V_8 [ 0 ] >> 3 ) & 1 ) ;
V_8 [ 1 ] |= ( V_8 [ 0 ] & 0x40 ) << 1 ;
break;
case V_21 :
F_2 ( V_2 , V_17 , ( V_8 [ 0 ] >> 3 ) & 1 ) ;
V_8 [ 0 ] |= 0x08 ;
break;
default:
break;
}
F_1 ( V_2 ,
V_8 [ 0 ] | V_7 -> V_22 ) ;
F_5 ( V_2 , V_23 , V_8 [ 1 ] ? ( int ) V_8 [ 1 ] - ( int ) ( ( V_8 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_5 ( V_2 , V_24 , V_8 [ 2 ] ? ( int ) ( ( V_8 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_8 [ 2 ] : 0 ) ;
F_6 ( V_2 ) ;
return V_25 ;
}
void F_7 ( struct V_7 * V_7 , struct V_26 * V_27 ,
unsigned long V_28 )
{
F_8 ( V_29 , V_27 , V_28 ) ;
}
static inline void F_9 ( struct V_7 * V_7 , enum V_30 V_31 )
{
V_7 -> V_32 = V_31 ;
V_7 -> V_9 = V_7 -> V_33 = 0 ;
V_7 -> V_34 . V_35 = 0 ;
V_7 -> V_36 = V_37 ;
}
void F_10 ( struct V_7 * V_7 , enum V_30 V_31 )
{
F_11 ( V_7 -> V_34 . V_38 ) ;
F_9 ( V_7 , V_31 ) ;
F_12 ( V_7 -> V_34 . V_38 ) ;
}
static int F_13 ( struct V_7 * V_7 )
{
T_2 V_39 = V_7 -> V_40 ( V_7 ) ;
switch ( V_39 ) {
case V_41 :
if ( V_7 -> V_32 == V_42 ) {
F_14 ( V_7 ,
L_1 ,
V_7 -> V_43 , V_7 -> V_44 ,
V_7 -> V_9 ) ;
if ( ++ V_7 -> V_33 == V_7 -> V_45 ) {
F_9 ( V_7 , V_46 ) ;
F_15 ( V_7 ,
L_2 ) ;
F_16 ( V_7 -> V_34 . V_38 ) ;
return - 1 ;
}
}
V_7 -> V_9 = 0 ;
break;
case V_25 :
V_7 -> V_9 = 0 ;
if ( V_7 -> V_33 ) {
V_7 -> V_33 = 0 ;
F_15 ( V_7 ,
L_3 ,
V_7 -> V_43 , V_7 -> V_44 ) ;
}
break;
case V_11 :
break;
}
return 0 ;
}
static void F_17 ( struct V_7 * V_7 , T_1 V_47 )
{
switch ( V_7 -> V_48 ) {
case V_49 :
V_7 -> V_48 = V_47 ;
break;
case V_50 :
F_1 ( V_7 -> V_2 , V_47 ) ;
F_6 ( V_7 -> V_2 ) ;
V_7 -> V_22 = V_47 ;
V_7 -> V_48 = V_49 ;
break;
default:
F_14 ( V_7 ,
L_4 ,
V_7 -> V_48 ) ;
V_7 -> V_48 = V_49 ;
break;
}
}
static T_3 F_18 ( struct V_38 * V_38 ,
unsigned char V_47 , unsigned int V_35 )
{
struct V_7 * V_7 = F_19 ( V_38 ) ;
if ( V_7 -> V_32 == V_46 )
goto V_51;
if ( F_20 ( ( V_35 & V_52 ) ||
( ( V_35 & V_53 ) &&
! V_7 -> V_12 -> V_54 ) ) ) {
if ( V_7 -> V_32 == V_42 )
F_14 ( V_7 ,
L_5 ,
V_35 & V_52 ? L_6 : L_7 ,
V_35 & V_53 ? L_8 : L_7 ) ;
F_21 ( & V_7 -> V_34 ) ;
goto V_51;
}
if ( V_35 & V_55 ) {
F_17 ( V_7 , V_47 ) ;
goto V_51;
}
if ( F_20 ( V_7 -> V_34 . V_35 & V_56 ) )
if ( F_22 ( & V_7 -> V_34 , V_47 ) )
goto V_51;
if ( F_20 ( V_7 -> V_34 . V_35 & V_57 ) )
if ( F_23 ( & V_7 -> V_34 , V_47 ) )
goto V_51;
if ( V_7 -> V_32 <= V_58 )
goto V_51;
if ( V_7 -> V_32 == V_42 &&
V_7 -> V_9 && F_24 ( V_37 , V_7 -> V_36 + V_59 / 2 ) ) {
F_25 ( V_7 , L_9 ,
V_7 -> V_43 , V_7 -> V_44 , V_7 -> V_9 ) ;
V_7 -> V_60 = V_7 -> V_8 [ 0 ] ;
F_9 ( V_7 , V_58 ) ;
F_7 ( V_7 , & V_7 -> V_61 , 0 ) ;
goto V_51;
}
V_7 -> V_8 [ V_7 -> V_9 ++ ] = V_47 ;
if ( F_20 ( V_7 -> V_8 [ 0 ] == V_62 && V_7 -> V_9 <= 2 ) ) {
if ( V_7 -> V_9 == 1 ) {
V_7 -> V_36 = V_37 ;
goto V_51;
}
if ( V_7 -> V_8 [ 1 ] == V_63 ||
( V_7 -> V_12 -> type == V_64 &&
V_7 -> V_8 [ 1 ] == V_62 ) ) {
F_9 ( V_7 , V_46 ) ;
F_16 ( V_38 ) ;
goto V_51;
}
V_7 -> V_9 = 1 ;
if ( F_13 ( V_7 ) )
goto V_51;
V_7 -> V_8 [ V_7 -> V_9 ++ ] = V_47 ;
}
if ( V_7 -> V_32 == V_42 &&
V_7 -> V_9 == 1 && V_7 -> V_65 &&
F_24 ( V_37 , V_7 -> V_36 + V_7 -> V_65 * V_59 ) ) {
V_7 -> V_60 = V_7 -> V_8 [ 0 ] ;
F_9 ( V_7 , V_58 ) ;
F_7 ( V_7 , & V_7 -> V_61 , 0 ) ;
goto V_51;
}
V_7 -> V_36 = V_37 ;
F_13 ( V_7 ) ;
V_51:
return V_66 ;
}
int F_26 ( struct V_7 * V_7 , unsigned char V_67 )
{
int V_68 ;
if ( F_27 ( & V_7 -> V_34 , NULL , V_69 ) )
return - 1 ;
for ( V_68 = 6 ; V_68 >= 0 ; V_68 -= 2 ) {
unsigned char V_70 = ( V_67 >> V_68 ) & 3 ;
if ( F_27 ( & V_7 -> V_34 , & V_70 , V_71 ) )
return - 1 ;
}
return 0 ;
}
int F_28 ( struct V_7 * V_7 )
{
unsigned char V_72 [ 2 ] ;
if ( F_27 ( & V_7 -> V_34 , V_72 , V_73 ) )
return - 1 ;
if ( V_72 [ 0 ] != V_62 && V_72 [ 1 ] != V_63 )
return - 1 ;
return 0 ;
}
void F_29 ( struct V_7 * V_7 , unsigned int V_74 )
{
static const unsigned char V_75 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_76 ;
if ( V_74 == 0 || V_74 > 200 )
V_74 = 200 ;
V_76 = V_75 [ V_74 / 50 ] ;
F_27 ( & V_7 -> V_34 , & V_76 , V_71 ) ;
V_7 -> V_74 = 25 << V_76 ;
}
static void F_30 ( struct V_7 * V_7 , unsigned int V_77 )
{
static const unsigned char V_78 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 , 0 } ;
unsigned char V_79 ;
int V_68 = 0 ;
while ( V_78 [ V_68 ] > V_77 ) V_68 ++ ;
V_79 = V_78 [ V_68 ] ;
F_27 ( & V_7 -> V_34 , & V_79 , V_80 ) ;
V_7 -> V_77 = V_79 ;
}
static void F_31 ( struct V_7 * V_7 , enum V_81 V_82 )
{
F_27 ( & V_7 -> V_34 , NULL ,
V_82 == V_83 ? V_84 :
V_69 ) ;
}
static int F_32 ( struct V_7 * V_7 )
{
return F_27 ( & V_7 -> V_34 , V_7 -> V_8 ,
V_85 | ( V_7 -> V_10 << 8 ) ) ;
}
static bool F_33 ( const char * V_86 , const char * const V_87 [] )
{
int V_68 ;
for ( V_68 = 0 ; V_87 [ V_68 ] ; V_68 ++ )
if ( ! strcasecmp ( V_86 , V_87 [ V_68 ] ) )
return true ;
return false ;
}
bool F_34 ( struct V_7 * V_7 , const char * const V_87 [] )
{
struct V_38 * V_38 = V_7 -> V_34 . V_38 ;
char * V_76 , * V_88 , * V_89 ;
bool V_90 = false ;
if ( strncmp ( V_38 -> V_91 , L_10 , 5 ) )
return false ;
V_88 = F_35 ( & V_38 -> V_91 [ 5 ] ,
sizeof( V_38 -> V_91 ) - 5 ,
V_92 ) ;
if ( ! V_88 )
return false ;
V_89 = V_88 ;
while ( ( V_76 = F_36 ( & V_88 , L_11 ) ) != NULL ) {
if ( F_33 ( V_76 , V_87 ) ) {
V_90 = true ;
break;
}
}
F_37 ( V_89 ) ;
return V_90 ;
}
static int F_38 ( struct V_7 * V_7 , bool V_93 )
{
struct V_34 * V_34 = & V_7 -> V_34 ;
unsigned char V_72 [ 4 ] ;
V_72 [ 0 ] = 3 ;
F_27 ( V_34 , V_72 , V_71 ) ;
F_27 ( V_34 , NULL , V_69 ) ;
F_27 ( V_34 , NULL , V_69 ) ;
F_27 ( V_34 , NULL , V_69 ) ;
F_27 ( V_34 , V_72 , V_94 ) ;
if ( V_72 [ 0 ] != 0x00 || V_72 [ 1 ] != 0x33 || V_72 [ 2 ] != 0x55 )
return - 1 ;
if ( V_93 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_18 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_17 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_14 , V_7 -> V_2 -> V_96 ) ;
V_7 -> V_97 = L_12 ;
V_7 -> V_43 = L_13 ;
V_7 -> V_10 = 4 ;
}
return 0 ;
}
static int F_40 ( struct V_7 * V_7 , bool V_93 )
{
struct V_34 * V_34 = & V_7 -> V_34 ;
unsigned char V_72 [ 2 ] ;
V_72 [ 0 ] = 200 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 100 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 80 ;
F_27 ( V_34 , V_72 , V_80 ) ;
F_27 ( V_34 , V_72 , V_98 ) ;
if ( V_72 [ 0 ] != 3 )
return - 1 ;
if ( V_93 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_14 , V_7 -> V_2 -> V_96 ) ;
if ( ! V_7 -> V_97 )
V_7 -> V_97 = L_14 ;
if ( ! V_7 -> V_43 )
V_7 -> V_43 = L_15 ;
V_7 -> V_10 = 4 ;
}
return 0 ;
}
static int F_41 ( struct V_7 * V_7 , bool V_93 )
{
struct V_34 * V_34 = & V_7 -> V_34 ;
unsigned char V_72 [ 2 ] ;
F_40 ( V_7 , 0 ) ;
V_72 [ 0 ] = 200 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 200 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 80 ;
F_27 ( V_34 , V_72 , V_80 ) ;
F_27 ( V_34 , V_72 , V_98 ) ;
if ( V_72 [ 0 ] != 4 )
return - 1 ;
V_72 [ 0 ] = 200 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 80 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 40 ;
F_27 ( V_34 , V_72 , V_80 ) ;
if ( V_93 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_14 , V_7 -> V_2 -> V_96 ) ;
F_39 ( V_16 , V_7 -> V_2 -> V_96 ) ;
F_39 ( V_17 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_18 , V_7 -> V_2 -> V_95 ) ;
if ( ! V_7 -> V_97 )
V_7 -> V_97 = L_14 ;
if ( ! V_7 -> V_43 )
V_7 -> V_43 = L_16 ;
V_7 -> V_10 = 4 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_7 , bool V_93 )
{
struct V_34 * V_34 = & V_7 -> V_34 ;
unsigned char V_72 [ 2 ] ;
static const unsigned char V_99 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_68 ;
V_72 [ 0 ] = 10 ;
F_27 ( V_34 , V_72 , V_80 ) ;
V_72 [ 0 ] = 0 ;
F_27 ( V_34 , V_72 , V_71 ) ;
for ( V_68 = 0 ; V_68 < F_43 ( V_99 ) ; V_68 ++ ) {
V_72 [ 0 ] = V_99 [ V_68 ] ;
F_27 ( V_34 , V_72 , V_80 ) ;
}
F_27 ( V_34 , V_72 , V_98 ) ;
if ( V_72 [ 0 ] != 2 )
return - 1 ;
if ( V_93 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_18 , V_7 -> V_2 -> V_95 ) ;
V_7 -> V_97 = L_17 ;
V_7 -> V_43 = L_18 ;
}
return 0 ;
}
static int F_44 ( struct V_7 * V_7 , bool V_93 )
{
if ( V_93 ) {
if ( ! V_7 -> V_97 )
V_7 -> V_97 = L_14 ;
if ( ! V_7 -> V_43 )
V_7 -> V_43 = L_13 ;
F_39 ( V_5 , V_7 -> V_2 -> V_95 ) ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_7 , bool V_93 )
{
if ( V_93 ) {
V_7 -> V_97 = L_19 ;
V_7 -> V_43 = L_20 ;
F_39 ( V_5 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_17 , V_7 -> V_2 -> V_95 ) ;
}
return 0 ;
}
static const struct V_100 * F_46 ( enum V_101 type )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < F_43 ( V_102 ) ; V_68 ++ )
if ( V_102 [ V_68 ] . type == type )
return & V_102 [ V_68 ] ;
return NULL ;
}
static const struct V_100 * F_47 ( enum V_101 type )
{
const struct V_100 * V_103 ;
V_103 = F_46 ( type ) ;
if ( V_103 )
return V_103 ;
F_48 ( 1 ) ;
return & V_102 [ 0 ] ;
}
static const struct V_100 * F_49 ( const char * V_43 , T_4 V_104 )
{
const struct V_100 * V_76 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < F_43 ( V_102 ) ; V_68 ++ ) {
V_76 = & V_102 [ V_68 ] ;
if ( ( strlen ( V_76 -> V_43 ) == V_104 && ! strncmp ( V_76 -> V_43 , V_43 , V_104 ) ) ||
( strlen ( V_76 -> V_105 ) == V_104 && ! strncmp ( V_76 -> V_105 , V_43 , V_104 ) ) )
return & V_102 [ V_68 ] ;
}
return NULL ;
}
static void F_50 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_2 ;
memset ( V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
memset ( V_1 -> V_95 , 0 , sizeof( V_1 -> V_95 ) ) ;
memset ( V_1 -> V_96 , 0 , sizeof( V_1 -> V_96 ) ) ;
memset ( V_1 -> V_107 , 0 , sizeof( V_1 -> V_107 ) ) ;
memset ( V_1 -> V_108 , 0 , sizeof( V_1 -> V_108 ) ) ;
F_39 ( V_109 , V_1 -> V_106 ) ;
F_39 ( V_110 , V_1 -> V_106 ) ;
F_39 ( V_4 , V_1 -> V_95 ) ;
F_39 ( V_6 , V_1 -> V_95 ) ;
F_39 ( V_23 , V_1 -> V_96 ) ;
F_39 ( V_24 , V_1 -> V_96 ) ;
F_39 ( V_111 , V_1 -> V_112 ) ;
V_7 -> V_12 = & V_102 [ 0 ] ;
V_7 -> V_113 = F_30 ;
V_7 -> V_114 = F_29 ;
V_7 -> V_115 = F_31 ;
V_7 -> V_116 = F_32 ;
V_7 -> V_40 = F_4 ;
V_7 -> V_10 = 3 ;
V_7 -> V_117 = NULL ;
V_7 -> V_118 = NULL ;
V_7 -> V_119 = NULL ;
V_7 -> V_120 = NULL ;
V_7 -> V_121 = NULL ;
V_7 -> V_122 = NULL ;
}
static bool F_51 ( struct V_7 * V_7 ,
enum V_101 type ,
unsigned int * V_123 ,
bool V_93 , bool V_124 )
{
const struct V_100 * V_103 ;
V_103 = F_46 ( type ) ;
if ( ! V_103 )
return false ;
if ( V_7 -> V_34 . V_38 -> V_86 . type == V_125 &&
! V_103 -> V_126 ) {
return false ;
}
if ( V_93 )
F_50 ( V_7 ) ;
if ( V_103 -> V_127 ( V_7 , V_93 ) != 0 )
return false ;
if ( V_93 && V_103 -> V_128 && V_124 ) {
if ( V_103 -> V_128 ( V_7 ) != 0 ) {
if ( * V_123 > V_15 )
* V_123 = V_15 ;
return false ;
}
}
return true ;
}
static int F_52 ( struct V_7 * V_7 ,
unsigned int V_123 , bool V_93 )
{
bool V_129 = false ;
int V_130 ;
if ( F_51 ( V_7 , V_131 ,
& V_123 , V_93 , false ) ) {
if ( V_123 > V_15 &&
F_53 ( V_132 ) &&
( ! V_93 || F_54 ( V_7 ) == 0 ) ) {
return V_131 ;
}
V_133 = V_123 = V_134 ;
}
if ( F_51 ( V_7 , V_135 , & V_123 ,
V_93 , V_123 > V_15 ) )
return V_135 ;
if ( F_51 ( V_7 , V_136 , & V_123 ,
V_93 , V_123 > V_15 ) )
return V_136 ;
if ( V_123 > V_15 &&
F_51 ( V_7 , V_20 , & V_123 ,
V_93 , true ) ) {
return V_20 ;
}
if ( V_123 > V_134 &&
F_51 ( V_7 , V_137 , & V_123 ,
V_93 , false ) ) {
V_129 = true ;
if ( V_123 > V_15 ) {
if ( F_53 ( V_138 ) ||
F_53 ( V_139 ) ) {
if ( ! V_93 )
return V_137 ;
V_130 = F_55 ( V_7 ) ;
if ( V_130 >= 0 )
return V_130 ;
}
V_123 = V_15 ;
}
F_56 ( V_7 ) ;
}
if ( V_123 > V_15 &&
F_51 ( V_7 , V_140 , & V_123 ,
V_93 , true ) ) {
return V_140 ;
}
if ( V_123 > V_15 ) {
F_27 ( & V_7 -> V_34 , NULL , V_141 ) ;
if ( F_51 ( V_7 , V_142 ,
& V_123 , V_93 , true ) )
return V_142 ;
}
if ( V_123 > V_15 &&
F_51 ( V_7 , V_64 , & V_123 ,
V_93 , true ) ) {
return V_64 ;
}
if ( V_123 > V_15 &&
F_51 ( V_7 , V_143 ,
& V_123 , V_93 , true ) ) {
return V_143 ;
}
if ( V_123 > V_15 ) {
if ( F_51 ( V_7 , V_19 ,
& V_123 , V_93 , true ) )
return V_19 ;
if ( F_51 ( V_7 , V_144 ,
& V_123 , V_93 , true ) )
return V_144 ;
if ( F_51 ( V_7 , V_145 ,
& V_123 , V_93 , true ) )
return V_145 ;
if ( F_51 ( V_7 , V_146 ,
& V_123 , V_93 , true ) )
return V_146 ;
}
if ( V_123 > V_15 &&
F_51 ( V_7 , V_147 ,
& V_123 , V_93 , true ) ) {
return V_147 ;
}
F_27 ( & V_7 -> V_34 , NULL , V_141 ) ;
F_28 ( V_7 ) ;
if ( V_123 >= V_15 &&
F_51 ( V_7 , V_15 ,
& V_123 , V_93 , true ) ) {
return V_15 ;
}
if ( V_123 >= V_13 &&
F_51 ( V_7 , V_13 ,
& V_123 , V_93 , true ) ) {
return V_13 ;
}
F_51 ( V_7 , V_134 ,
& V_123 , V_93 , true ) ;
if ( V_129 ) {
F_28 ( V_7 ) ;
}
return V_134 ;
}
static int F_57 ( struct V_7 * V_7 )
{
struct V_34 * V_34 = & V_7 -> V_34 ;
unsigned char V_72 [ 2 ] ;
V_72 [ 0 ] = 0xa5 ;
if ( F_27 ( V_34 , V_72 , V_98 ) )
return - 1 ;
if ( V_72 [ 0 ] != 0x00 && V_72 [ 0 ] != 0x03 &&
V_72 [ 0 ] != 0x04 && V_72 [ 0 ] != 0xff )
return - 1 ;
if ( F_27 ( V_34 , NULL , V_141 ) )
F_14 ( V_7 , L_21 ,
V_34 -> V_38 -> V_44 ) ;
return 0 ;
}
static void F_58 ( struct V_7 * V_7 )
{
if ( V_133 != V_134 ) {
V_7 -> V_113 ( V_7 , V_7 -> V_77 ) ;
V_7 -> V_114 ( V_7 , V_7 -> V_74 ) ;
V_7 -> V_115 ( V_7 , V_148 ) ;
}
}
int F_59 ( struct V_7 * V_7 )
{
if ( F_27 ( & V_7 -> V_34 , NULL , V_149 ) ) {
F_14 ( V_7 , L_22 ,
V_7 -> V_34 . V_38 -> V_44 ) ;
return - 1 ;
}
F_10 ( V_7 , V_42 ) ;
return 0 ;
}
int F_60 ( struct V_7 * V_7 )
{
if ( F_27 ( & V_7 -> V_34 , NULL , V_150 ) ) {
F_14 ( V_7 , L_23 ,
V_7 -> V_34 . V_38 -> V_44 ) ;
return - 1 ;
}
F_10 ( V_7 , V_151 ) ;
return 0 ;
}
static void F_61 ( struct V_152 * V_27 )
{
struct V_7 * V_153 = NULL , * V_7 =
F_62 ( V_27 , struct V_7 , V_61 . V_27 ) ;
struct V_38 * V_38 = V_7 -> V_34 . V_38 ;
T_2 V_39 = V_11 ;
bool V_154 = false , V_155 = false ;
int V_68 ;
F_63 ( & V_156 ) ;
if ( V_7 -> V_32 != V_58 )
goto V_51;
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
F_60 ( V_153 ) ;
}
V_7 -> V_157 ++ ;
if ( F_64 ( & V_7 -> V_34 , V_150 , 20 ) ) {
if ( V_7 -> V_157 < 3 || V_7 -> V_158 )
V_154 = true ;
} else
V_7 -> V_158 = true ;
if ( ! V_154 ) {
if ( V_7 -> V_116 ( V_7 ) )
V_154 = true ;
else {
F_10 ( V_7 , V_151 ) ;
for ( V_68 = 0 ; V_68 < V_7 -> V_10 ; V_68 ++ ) {
V_7 -> V_9 ++ ;
V_39 = V_7 -> V_40 ( V_7 ) ;
if ( V_39 != V_11 )
break;
}
if ( V_39 != V_25 )
V_154 = true ;
F_10 ( V_7 , V_58 ) ;
}
}
for ( V_68 = 0 ; V_68 < 5 ; V_68 ++ ) {
if ( ! F_27 ( & V_7 -> V_34 , NULL , V_149 ) ) {
V_155 = true ;
break;
}
F_65 ( 200 ) ;
}
if ( ! V_155 ) {
F_14 ( V_7 , L_24 ,
V_7 -> V_34 . V_38 -> V_44 ) ;
V_154 = true ;
}
if ( V_154 ) {
F_10 ( V_7 , V_46 ) ;
F_25 ( V_7 ,
L_25 ) ;
F_16 ( V_38 ) ;
} else
F_10 ( V_7 , V_42 ) ;
if ( V_153 )
F_59 ( V_153 ) ;
V_51:
F_66 ( & V_156 ) ;
}
static void F_67 ( struct V_38 * V_38 )
{
struct V_7 * V_7 = F_19 ( V_38 ) ;
struct V_7 * V_153 = NULL ;
F_63 ( & V_156 ) ;
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
F_60 ( V_153 ) ;
}
F_10 ( V_7 , V_159 ) ;
if ( F_27 ( & V_7 -> V_34 , NULL , V_150 ) )
F_14 ( V_7 , L_26 ,
V_7 -> V_34 . V_38 -> V_44 ) ;
if ( V_7 -> V_120 )
V_7 -> V_120 ( V_7 ) ;
F_27 ( & V_7 -> V_34 , NULL , V_141 ) ;
F_27 ( & V_7 -> V_34 , NULL , V_149 ) ;
if ( V_153 ) {
if ( V_153 -> V_122 )
V_153 -> V_122 ( V_153 ) ;
F_59 ( V_153 ) ;
}
F_66 ( & V_156 ) ;
}
static void F_68 ( struct V_38 * V_38 )
{
struct V_7 * V_7 = F_19 ( V_38 ) ;
struct V_7 * V_153 = NULL ;
F_69 ( & V_38 -> V_2 . V_160 , & V_161 ) ;
F_63 ( & V_156 ) ;
F_10 ( V_7 , V_151 ) ;
F_66 ( & V_156 ) ;
F_70 ( V_29 ) ;
F_63 ( & V_156 ) ;
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
F_60 ( V_153 ) ;
}
if ( V_7 -> V_119 )
V_7 -> V_119 ( V_7 ) ;
if ( V_153 && V_153 -> V_122 )
V_153 -> V_122 ( V_153 ) ;
F_10 ( V_7 , V_46 ) ;
F_71 ( V_38 ) ;
F_72 ( V_38 , NULL ) ;
if ( V_7 -> V_2 )
F_73 ( V_7 -> V_2 ) ;
F_37 ( V_7 ) ;
if ( V_153 )
F_59 ( V_153 ) ;
F_66 ( & V_156 ) ;
}
static int F_74 ( struct V_7 * V_7 ,
const struct V_100 * V_103 )
{
const struct V_100 * V_162 ;
struct V_1 * V_1 = V_7 -> V_2 ;
enum V_101 type ;
V_1 -> V_2 . V_153 = & V_7 -> V_34 . V_38 -> V_2 ;
if ( V_103 && ( V_103 -> V_127 || V_103 -> V_128 ) ) {
F_50 ( V_7 ) ;
if ( V_103 -> V_127 && V_103 -> V_127 ( V_7 , true ) < 0 )
return - 1 ;
if ( V_103 -> V_128 && V_103 -> V_128 ( V_7 ) < 0 )
return - 1 ;
V_162 = V_103 ;
} else {
type = F_52 ( V_7 , V_133 , true ) ;
V_162 = F_47 ( type ) ;
}
V_7 -> V_12 = V_162 ;
if ( V_7 -> V_10 == 3 )
V_7 -> V_65 = 0 ;
if ( V_7 -> V_65 && V_7 -> V_116 ( V_7 ) )
V_7 -> V_65 = 0 ;
snprintf ( V_7 -> V_163 , sizeof( V_7 -> V_163 ) , L_27 ,
V_162 -> V_43 , V_7 -> V_97 , V_7 -> V_43 ) ;
V_1 -> V_43 = V_7 -> V_163 ;
V_1 -> V_44 = V_7 -> V_44 ;
V_1 -> V_86 . V_164 = V_165 ;
V_1 -> V_86 . V_97 = 0x0002 ;
V_1 -> V_86 . V_166 = V_7 -> V_12 -> type ;
V_1 -> V_86 . V_167 = V_7 -> V_168 ;
return 0 ;
}
static int F_75 ( struct V_38 * V_38 , struct V_169 * V_170 )
{
struct V_7 * V_7 , * V_153 = NULL ;
struct V_1 * V_1 ;
int V_171 = 0 , error = - V_172 ;
F_63 ( & V_156 ) ;
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
F_60 ( V_153 ) ;
}
V_7 = F_76 ( sizeof( struct V_7 ) , V_92 ) ;
V_1 = F_77 () ;
if ( ! V_7 || ! V_1 )
goto V_173;
F_78 ( & V_7 -> V_34 , V_38 ) ;
F_79 ( & V_7 -> V_61 , F_61 ) ;
V_7 -> V_2 = V_1 ;
snprintf ( V_7 -> V_44 , sizeof( V_7 -> V_44 ) , L_28 , V_38 -> V_44 ) ;
F_10 ( V_7 , V_159 ) ;
F_72 ( V_38 , V_7 ) ;
error = F_80 ( V_38 , V_170 ) ;
if ( error )
goto V_174;
if ( V_38 -> V_86 . type == V_125 )
F_81 ( 10000 , 15000 ) ;
if ( F_57 ( V_7 ) < 0 ) {
error = - V_175 ;
goto V_176;
}
V_7 -> V_77 = V_177 ;
V_7 -> V_74 = V_178 ;
V_7 -> V_45 = V_179 ;
V_7 -> V_65 = V_153 ? 0 : V_180 ;
V_7 -> V_181 = V_182 ;
F_74 ( V_7 , NULL ) ;
if ( ! V_7 -> V_12 -> V_183 ) {
F_10 ( V_7 , V_151 ) ;
F_58 ( V_7 ) ;
error = F_82 ( V_1 ) ;
if ( error )
goto V_184;
} else {
F_83 ( V_1 ) ;
V_7 -> V_2 = V_1 = NULL ;
}
if ( V_153 && V_153 -> V_121 )
V_153 -> V_121 ( V_153 ) ;
error = F_84 ( & V_38 -> V_2 . V_160 , & V_161 ) ;
if ( error )
goto V_185;
if ( ! V_7 -> V_12 -> V_183 )
F_59 ( V_7 ) ;
V_51:
if ( V_153 )
F_59 ( V_153 ) ;
F_66 ( & V_156 ) ;
return V_171 ;
V_185:
if ( V_153 && V_153 -> V_122 )
V_153 -> V_122 ( V_153 ) ;
if ( V_1 ) {
F_73 ( V_1 ) ;
V_1 = NULL ;
}
V_184:
if ( V_7 -> V_119 )
V_7 -> V_119 ( V_7 ) ;
F_10 ( V_7 , V_46 ) ;
V_176:
F_71 ( V_38 ) ;
V_174:
F_72 ( V_38 , NULL ) ;
V_173:
F_83 ( V_1 ) ;
F_37 ( V_7 ) ;
V_171 = error ;
goto V_51;
}
static int F_85 ( struct V_38 * V_38 , bool V_118 )
{
struct V_7 * V_7 = F_19 ( V_38 ) ;
struct V_7 * V_153 = NULL ;
int (* F_86)( struct V_7 * );
enum V_101 type ;
int V_39 = - 1 ;
F_63 ( & V_156 ) ;
if ( V_118 ) {
F_86 = V_7 -> V_118 ;
if ( ! F_86 ) {
V_39 = - V_186 ;
goto V_187;
}
} else {
F_86 = V_7 -> V_117 ;
}
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
F_60 ( V_153 ) ;
}
F_10 ( V_7 , V_159 ) ;
if ( F_86 ) {
if ( F_86 ( V_7 ) )
goto V_51;
} else {
F_28 ( V_7 ) ;
if ( F_57 ( V_7 ) < 0 )
goto V_51;
type = F_52 ( V_7 , V_133 , false ) ;
if ( V_7 -> V_12 -> type != type )
goto V_51;
}
if ( ! V_7 -> V_12 -> V_183 ) {
F_10 ( V_7 , V_151 ) ;
F_58 ( V_7 ) ;
}
if ( V_153 && V_153 -> V_121 )
V_153 -> V_121 ( V_153 ) ;
if ( ! V_7 -> V_12 -> V_183 )
F_59 ( V_7 ) ;
V_39 = 0 ;
V_51:
if ( V_153 )
F_59 ( V_153 ) ;
V_187:
F_66 ( & V_156 ) ;
return V_39 ;
}
static int F_87 ( struct V_38 * V_38 )
{
return F_85 ( V_38 , false ) ;
}
static int F_88 ( struct V_38 * V_38 )
{
return F_85 ( V_38 , true ) ;
}
T_5 F_89 ( struct V_188 * V_2 , struct V_189 * V_190 ,
char * V_191 )
{
struct V_38 * V_38 = F_90 ( V_2 ) ;
struct V_192 * V_193 = F_91 ( V_190 ) ;
struct V_7 * V_7 = F_19 ( V_38 ) ;
if ( V_7 -> V_12 -> V_183 &&
V_190 != & V_194 . V_195 )
return - V_186 ;
return V_193 -> V_196 ( V_7 , V_193 -> V_47 , V_191 ) ;
}
T_5 F_92 ( struct V_188 * V_2 , struct V_189 * V_190 ,
const char * V_191 , T_4 V_197 )
{
struct V_38 * V_38 = F_90 ( V_2 ) ;
struct V_192 * V_193 = F_91 ( V_190 ) ;
struct V_7 * V_7 , * V_153 = NULL ;
int V_171 ;
V_171 = F_93 ( & V_156 ) ;
if ( V_171 )
goto V_51;
V_7 = F_19 ( V_38 ) ;
if ( V_7 -> V_12 -> V_183 &&
V_190 != & V_194 . V_195 ) {
V_171 = - V_186 ;
goto V_187;
}
if ( V_193 -> V_198 ) {
if ( V_7 -> V_32 == V_46 ) {
V_171 = - V_175 ;
goto V_187;
}
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
F_60 ( V_153 ) ;
}
if ( ! V_7 -> V_12 -> V_183 )
F_60 ( V_7 ) ;
}
V_171 = V_193 -> V_199 ( V_7 , V_193 -> V_47 , V_191 , V_197 ) ;
if ( V_193 -> V_198 ) {
if ( V_171 != - V_175 && ! V_7 -> V_12 -> V_183 )
F_59 ( V_7 ) ;
if ( V_153 )
F_59 ( V_153 ) ;
}
V_187:
F_66 ( & V_156 ) ;
V_51:
return V_171 ;
}
static T_5 F_94 ( struct V_7 * V_7 , void * V_200 , char * V_191 )
{
unsigned int * V_201 = ( unsigned int * ) ( ( char * ) V_7 + ( T_4 ) V_200 ) ;
return sprintf ( V_191 , L_29 , * V_201 ) ;
}
static T_5 F_95 ( struct V_7 * V_7 , void * V_200 , const char * V_191 , T_4 V_197 )
{
unsigned int * V_201 = ( unsigned int * ) ( ( char * ) V_7 + ( T_4 ) V_200 ) ;
unsigned int V_202 ;
int V_203 ;
V_203 = F_96 ( V_191 , 10 , & V_202 ) ;
if ( V_203 )
return V_203 ;
* V_201 = V_202 ;
return V_197 ;
}
static T_5 F_97 ( struct V_7 * V_7 , void * V_47 , char * V_191 )
{
return sprintf ( V_191 , L_30 , V_7 -> V_12 -> V_43 ) ;
}
static T_5 F_98 ( struct V_7 * V_7 , void * V_47 , const char * V_191 , T_4 V_197 )
{
struct V_38 * V_38 = V_7 -> V_34 . V_38 ;
struct V_7 * V_153 = NULL ;
struct V_1 * V_204 , * V_205 ;
const struct V_100 * V_103 , * V_206 ;
int error ;
int V_207 = 0 ;
V_103 = F_49 ( V_191 , V_197 ) ;
if ( ! V_103 )
return - V_208 ;
if ( V_7 -> V_12 == V_103 )
return V_197 ;
V_205 = F_77 () ;
if ( ! V_205 )
return - V_172 ;
while ( ! F_99 ( & V_38 -> V_209 ) ) {
if ( ++ V_207 > 3 ) {
F_14 ( V_7 ,
L_31 ) ;
F_83 ( V_205 ) ;
return - V_210 ;
}
F_66 ( & V_156 ) ;
F_100 ( V_38 ) ;
F_63 ( & V_156 ) ;
if ( V_38 -> V_170 != & V_211 ) {
F_83 ( V_205 ) ;
return - V_175 ;
}
if ( V_7 -> V_12 == V_103 ) {
F_83 ( V_205 ) ;
return V_197 ;
}
}
if ( V_38 -> V_153 && V_38 -> V_86 . type == V_125 ) {
V_153 = F_19 ( V_38 -> V_153 ) ;
if ( V_153 -> V_122 )
V_153 -> V_122 ( V_153 ) ;
}
V_204 = V_7 -> V_2 ;
V_206 = V_7 -> V_12 ;
if ( V_7 -> V_119 )
V_7 -> V_119 ( V_7 ) ;
F_10 ( V_7 , V_46 ) ;
V_7 -> V_2 = V_205 ;
F_10 ( V_7 , V_159 ) ;
if ( F_74 ( V_7 , V_103 ) < 0 ) {
F_28 ( V_7 ) ;
F_74 ( V_7 , & V_102 [ 0 ] ) ;
}
F_58 ( V_7 ) ;
F_10 ( V_7 , V_151 ) ;
if ( V_7 -> V_12 -> V_183 ) {
F_83 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
} else {
error = F_82 ( V_7 -> V_2 ) ;
if ( error ) {
if ( V_7 -> V_119 )
V_7 -> V_119 ( V_7 ) ;
F_10 ( V_7 , V_46 ) ;
F_83 ( V_205 ) ;
V_7 -> V_2 = V_204 ;
F_10 ( V_7 , V_159 ) ;
F_74 ( V_7 , V_206 ) ;
F_58 ( V_7 ) ;
F_10 ( V_7 , V_151 ) ;
return error ;
}
}
if ( V_204 )
F_73 ( V_204 ) ;
if ( V_153 && V_153 -> V_121 )
V_153 -> V_121 ( V_153 ) ;
return V_197 ;
}
static T_5 F_101 ( struct V_7 * V_7 , void * V_47 , const char * V_191 , T_4 V_197 )
{
unsigned int V_202 ;
int V_203 ;
V_203 = F_96 ( V_191 , 10 , & V_202 ) ;
if ( V_203 )
return V_203 ;
V_7 -> V_113 ( V_7 , V_202 ) ;
return V_197 ;
}
static T_5 F_102 ( struct V_7 * V_7 , void * V_47 , const char * V_191 , T_4 V_197 )
{
unsigned int V_202 ;
int V_203 ;
V_203 = F_96 ( V_191 , 10 , & V_202 ) ;
if ( V_203 )
return V_203 ;
V_7 -> V_114 ( V_7 , V_202 ) ;
return V_197 ;
}
static int F_103 ( const char * V_212 , const struct V_213 * V_214 )
{
const struct V_100 * V_103 ;
if ( ! V_212 )
return - V_208 ;
V_103 = F_49 ( V_212 , strlen ( V_212 ) ) ;
if ( ! V_103 || ! V_103 -> V_215 )
return - V_208 ;
* ( ( unsigned int * ) V_214 -> V_216 ) = V_103 -> type ;
return 0 ;
}
static int F_104 ( char * V_217 , const struct V_213 * V_214 )
{
int type = * ( ( unsigned int * ) V_214 -> V_216 ) ;
return sprintf ( V_217 , L_32 , F_47 ( type ) -> V_43 ) ;
}
static int T_6 F_105 ( void )
{
int V_203 ;
F_106 () ;
F_107 () ;
F_108 () ;
V_203 = F_109 () ;
if ( V_203 )
return V_203 ;
V_29 = F_110 ( L_33 , 0 ) ;
if ( ! V_29 ) {
F_111 ( L_34 ) ;
V_203 = - V_172 ;
goto V_218;
}
V_203 = F_112 ( & V_211 ) ;
if ( V_203 )
goto V_219;
return 0 ;
V_219:
F_113 ( V_29 ) ;
V_218:
F_114 () ;
return V_203 ;
}
static void T_7 F_115 ( void )
{
F_116 ( & V_211 ) ;
F_113 ( V_29 ) ;
F_114 () ;
}
