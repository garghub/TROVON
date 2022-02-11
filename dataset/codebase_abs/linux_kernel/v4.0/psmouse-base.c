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
bool F_30 ( struct V_1 * V_1 , const char * const V_79 [] )
{
int V_61 ;
if ( ! strncmp ( V_1 -> V_31 . V_35 -> V_80 , L_9 , 4 ) )
for ( V_61 = 0 ; V_79 [ V_61 ] ; V_61 ++ )
if ( strstr ( V_1 -> V_31 . V_35 -> V_80 , V_79 [ V_61 ] ) )
return true ;
return false ;
}
static int F_31 ( struct V_1 * V_1 , bool V_81 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 4 ] ;
V_65 [ 0 ] = 3 ;
F_24 ( V_31 , V_65 , V_64 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , V_65 , V_82 ) ;
if ( V_65 [ 0 ] != 0x00 || V_65 [ 1 ] != 0x33 || V_65 [ 2 ] != 0x55 )
return - 1 ;
if ( V_81 ) {
F_32 ( V_18 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_14 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_13 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_10 , V_1 -> V_3 -> V_84 ) ;
V_1 -> V_85 = L_10 ;
V_1 -> V_40 = L_11 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , bool V_81 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 100 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_86 ) ;
if ( V_65 [ 0 ] != 3 )
return - 1 ;
if ( V_81 ) {
F_32 ( V_18 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_10 , V_1 -> V_3 -> V_84 ) ;
if ( ! V_1 -> V_85 )
V_1 -> V_85 = L_12 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_13 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , bool V_81 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
F_33 ( V_1 , 0 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_86 ) ;
if ( V_65 [ 0 ] != 4 )
return - 1 ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 40 ;
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_81 ) {
F_32 ( V_18 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_10 , V_1 -> V_3 -> V_84 ) ;
F_32 ( V_12 , V_1 -> V_3 -> V_84 ) ;
F_32 ( V_13 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_14 , V_1 -> V_3 -> V_83 ) ;
if ( ! V_1 -> V_85 )
V_1 -> V_85 = L_12 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_14 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , bool V_81 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
static const unsigned char V_87 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_61 ;
V_65 [ 0 ] = 10 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 0 ;
F_24 ( V_31 , V_65 , V_64 ) ;
for ( V_61 = 0 ; V_61 < F_36 ( V_87 ) ; V_61 ++ ) {
V_65 [ 0 ] = V_87 [ V_61 ] ;
F_24 ( V_31 , V_65 , V_73 ) ;
}
F_24 ( V_31 , V_65 , V_86 ) ;
if ( V_65 [ 0 ] != 2 )
return - 1 ;
if ( V_81 ) {
F_32 ( V_18 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_14 , V_1 -> V_3 -> V_83 ) ;
V_1 -> V_85 = L_15 ;
V_1 -> V_40 = L_16 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , bool V_81 )
{
if ( V_81 ) {
if ( ! V_1 -> V_85 )
V_1 -> V_85 = L_12 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_11 ;
F_32 ( V_18 , V_1 -> V_3 -> V_83 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , bool V_81 )
{
if ( V_81 ) {
V_1 -> V_85 = L_17 ;
V_1 -> V_40 = L_18 ;
F_32 ( V_18 , V_1 -> V_3 -> V_83 ) ;
F_32 ( V_13 , V_1 -> V_3 -> V_83 ) ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
memset ( V_2 -> V_88 , 0 , sizeof( V_2 -> V_88 ) ) ;
memset ( V_2 -> V_83 , 0 , sizeof( V_2 -> V_83 ) ) ;
memset ( V_2 -> V_84 , 0 , sizeof( V_2 -> V_84 ) ) ;
memset ( V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
memset ( V_2 -> V_90 , 0 , sizeof( V_2 -> V_90 ) ) ;
F_32 ( V_91 , V_2 -> V_88 ) ;
F_32 ( V_92 , V_2 -> V_88 ) ;
F_32 ( V_17 , V_2 -> V_83 ) ;
F_32 ( V_19 , V_2 -> V_83 ) ;
F_32 ( V_20 , V_2 -> V_84 ) ;
F_32 ( V_21 , V_2 -> V_84 ) ;
F_32 ( V_93 , V_2 -> V_94 ) ;
V_1 -> V_95 = F_27 ;
V_1 -> V_96 = F_26 ;
V_1 -> V_97 = F_28 ;
V_1 -> V_98 = F_29 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_6 = 3 ;
V_1 -> V_99 = NULL ;
V_1 -> V_100 = NULL ;
V_1 -> V_101 = NULL ;
V_1 -> V_102 = NULL ;
V_1 -> V_103 = NULL ;
}
static int F_40 ( int (* F_41)( struct V_1 * V_1 ,
bool V_81 ) ,
struct V_1 * V_1 , bool V_81 )
{
if ( V_81 )
F_39 ( V_1 ) ;
return F_41 ( V_1 , V_81 ) ;
}
static int F_42 ( struct V_1 * V_1 ,
unsigned int V_104 , bool V_81 )
{
bool V_105 = false ;
if ( F_40 ( V_106 , V_1 , V_81 ) == 0 ) {
if ( V_104 > V_11 ) {
if ( ! V_81 || F_43 ( V_1 ) == 0 ) {
if ( F_44 ( V_107 ) )
return V_108 ;
V_109 = V_110 ;
return V_110 ;
}
}
}
if ( F_40 ( V_111 , V_1 , V_81 ) == 0 ) {
if ( V_104 > V_11 ) {
if ( ! V_81 || F_45 ( V_1 ) == 0 )
return V_112 ;
}
}
if ( V_104 > V_11 &&
F_40 ( F_35 , V_1 , V_81 ) == 0 ) {
return V_15 ;
}
if ( V_104 > V_110 &&
F_40 ( V_113 , V_1 , V_81 ) == 0 ) {
V_105 = true ;
if ( V_104 > V_11 ) {
if ( F_44 ( V_114 ) &&
( ! V_81 || F_46 ( V_1 ) == 0 ) ) {
return V_115 ;
}
V_104 = V_11 ;
}
F_47 ( V_1 ) ;
}
if ( V_104 > V_11 &&
F_48 ( V_1 , V_81 ) == 0 ) {
if ( F_44 ( V_116 ) ) {
if ( F_49 ( V_1 ) == 0 )
return V_117 ;
return V_110 ;
}
V_104 = V_11 ;
}
if ( V_104 > V_11 ) {
F_24 ( & V_1 -> V_31 , NULL , V_118 ) ;
if ( F_40 ( V_119 ,
V_1 , V_81 ) == 0 ) {
if ( ! V_81 || F_50 ( V_1 ) == 0 )
return V_120 ;
V_104 = V_11 ;
}
}
if ( V_104 > V_11 &&
F_40 ( V_121 , V_1 , V_81 ) == 0 ) {
if ( ! V_81 || F_51 ( V_1 ) == 0 )
return V_57 ;
V_104 = V_11 ;
}
if ( V_104 > V_11 &&
F_40 ( V_122 , V_1 , V_81 ) == 0 ) {
if ( ! V_81 || F_52 ( V_1 ) == 0 )
return V_123 ;
V_104 = V_11 ;
}
if ( V_104 > V_11 ) {
if ( F_40 ( F_31 ,
V_1 , V_81 ) == 0 )
return V_9 ;
if ( F_40 ( V_124 ,
V_1 , V_81 ) == 0 )
return V_125 ;
if ( F_40 ( V_126 ,
V_1 , V_81 ) == 0 )
return V_127 ;
if ( F_40 ( V_128 ,
V_1 , V_81 ) == 0 )
return V_129 ;
}
if ( V_104 > V_11 ) {
if ( F_40 ( V_130 ,
V_1 , V_81 ) == 0 ) {
if ( ! V_81 || F_53 ( V_1 ) == 0 )
return V_131 ;
V_104 = V_11 ;
}
}
F_24 ( & V_1 -> V_31 , NULL , V_118 ) ;
F_25 ( V_1 ) ;
if ( V_104 >= V_11 &&
F_40 ( F_34 ,
V_1 , V_81 ) == 0 ) {
return V_11 ;
}
if ( V_104 >= V_8 &&
F_40 ( F_33 ,
V_1 , V_81 ) == 0 ) {
return V_8 ;
}
F_40 ( F_37 , V_1 , V_81 ) ;
if ( V_105 ) {
F_25 ( V_1 ) ;
}
return V_110 ;
}
static const struct V_132 * F_54 ( enum V_133 type )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_36 ( V_134 ) ; V_61 ++ )
if ( V_134 [ V_61 ] . type == type )
return & V_134 [ V_61 ] ;
F_55 ( 1 ) ;
return & V_134 [ 0 ] ;
}
static const struct V_132 * F_56 ( const char * V_40 , T_3 V_135 )
{
const struct V_132 * V_69 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_36 ( V_134 ) ; V_61 ++ ) {
V_69 = & V_134 [ V_61 ] ;
if ( ( strlen ( V_69 -> V_40 ) == V_135 && ! strncmp ( V_69 -> V_40 , V_40 , V_135 ) ) ||
( strlen ( V_69 -> V_136 ) == V_135 && ! strncmp ( V_69 -> V_136 , V_40 , V_135 ) ) )
return & V_134 [ V_61 ] ;
}
return NULL ;
}
static int F_57 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 0xa5 ;
if ( F_24 ( V_31 , V_65 , V_86 ) )
return - 1 ;
if ( V_65 [ 0 ] != 0x00 && V_65 [ 0 ] != 0x03 &&
V_65 [ 0 ] != 0x04 && V_65 [ 0 ] != 0xff )
return - 1 ;
if ( F_24 ( V_31 , NULL , V_118 ) )
F_12 ( V_1 , L_19 ,
V_31 -> V_35 -> V_41 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_1 )
{
if ( V_109 != V_110 ) {
V_1 -> V_95 ( V_1 , V_1 -> V_70 ) ;
V_1 -> V_96 ( V_1 , V_1 -> V_67 ) ;
V_1 -> V_97 ( V_1 , V_137 ) ;
}
}
int F_59 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_138 ) ) {
F_12 ( V_1 , L_20 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_39 ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_139 ) ) {
F_12 ( V_1 , L_21 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_140 ) ;
return 0 ;
}
static void F_61 ( struct V_141 * V_24 )
{
struct V_1 * V_142 = NULL , * V_1 =
F_62 ( V_24 , struct V_1 , V_54 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_143 = false , V_144 = false ;
int V_61 ;
F_63 ( & V_145 ) ;
if ( V_1 -> V_29 != V_51 )
goto V_45;
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
F_60 ( V_142 ) ;
}
V_1 -> V_148 ++ ;
if ( F_64 ( & V_1 -> V_31 , V_139 , 20 ) ) {
if ( V_1 -> V_148 < 3 || V_1 -> V_149 )
V_143 = true ;
} else
V_1 -> V_149 = true ;
if ( ! V_143 ) {
if ( V_1 -> V_98 ( V_1 ) )
V_143 = true ;
else {
F_8 ( V_1 , V_140 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_6 ; V_61 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_143 = true ;
F_8 ( V_1 , V_51 ) ;
}
}
for ( V_61 = 0 ; V_61 < 5 ; V_61 ++ ) {
if ( ! F_24 ( & V_1 -> V_31 , NULL , V_138 ) ) {
V_144 = true ;
break;
}
F_65 ( 200 ) ;
}
if ( ! V_144 ) {
F_12 ( V_1 , L_22 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
V_143 = true ;
}
if ( V_143 ) {
F_8 ( V_1 , V_43 ) ;
F_22 ( V_1 ,
L_23 ) ;
F_14 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_142 )
F_59 ( V_142 ) ;
V_45:
F_66 ( & V_145 ) ;
}
static void F_67 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_142 = NULL ;
F_63 ( & V_145 ) ;
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
F_60 ( V_142 ) ;
}
F_8 ( V_1 , V_150 ) ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_139 ) )
F_12 ( V_1 , L_24 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
if ( V_1 -> V_101 )
V_1 -> V_101 ( V_1 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_118 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_138 ) ;
if ( V_142 ) {
if ( V_142 -> V_103 )
V_142 -> V_103 ( V_142 ) ;
F_59 ( V_142 ) ;
}
F_66 ( & V_145 ) ;
}
static void F_68 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_142 = NULL ;
V_1 = F_16 ( V_35 ) ;
F_69 ( & V_35 -> V_3 . V_151 , & V_152 ) ;
F_63 ( & V_145 ) ;
F_8 ( V_1 , V_140 ) ;
F_66 ( & V_145 ) ;
F_70 ( V_26 ) ;
F_63 ( & V_145 ) ;
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
F_60 ( V_142 ) ;
}
if ( V_1 -> V_100 )
V_1 -> V_100 ( V_1 ) ;
if ( V_142 && V_142 -> V_103 )
V_142 -> V_103 ( V_142 ) ;
F_8 ( V_1 , V_43 ) ;
F_71 ( V_35 ) ;
F_72 ( V_35 , NULL ) ;
F_73 ( V_1 -> V_3 ) ;
F_74 ( V_1 ) ;
if ( V_142 )
F_59 ( V_142 ) ;
F_66 ( & V_145 ) ;
}
static int F_75 ( struct V_1 * V_1 ,
const struct V_132 * V_153 )
{
const struct V_132 * V_154 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_142 = & V_1 -> V_31 . V_35 -> V_3 ;
if ( V_153 && ( V_153 -> F_41 || V_153 -> V_155 ) ) {
F_39 ( V_1 ) ;
if ( V_153 -> F_41 && V_153 -> F_41 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_153 -> V_155 && V_153 -> V_155 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_153 -> type ;
V_154 = V_153 ;
} else {
V_1 -> type = F_42 ( V_1 ,
V_109 , true ) ;
V_154 = F_54 ( V_1 -> type ) ;
}
V_1 -> V_48 = V_154 -> V_48 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_58 = 0 ;
if ( V_1 -> V_58 && V_1 -> V_98 ( V_1 ) )
V_1 -> V_58 = 0 ;
snprintf ( V_1 -> V_156 , sizeof( V_1 -> V_156 ) , L_25 ,
V_154 -> V_40 , V_1 -> V_85 , V_1 -> V_40 ) ;
V_2 -> V_40 = V_1 -> V_156 ;
V_2 -> V_41 = V_1 -> V_41 ;
V_2 -> V_146 . V_157 = V_158 ;
V_2 -> V_146 . V_85 = 0x0002 ;
V_2 -> V_146 . V_159 = V_1 -> type ;
V_2 -> V_146 . V_160 = V_1 -> V_161 ;
return 0 ;
}
static int F_76 ( struct V_35 * V_35 , struct V_162 * V_163 )
{
struct V_1 * V_1 , * V_142 = NULL ;
struct V_2 * V_2 ;
int V_164 = 0 , error = - V_165 ;
F_63 ( & V_145 ) ;
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
F_60 ( V_142 ) ;
}
V_1 = F_77 ( sizeof( struct V_1 ) , V_166 ) ;
V_2 = F_78 () ;
if ( ! V_1 || ! V_2 )
goto V_167;
F_79 ( & V_1 -> V_31 , V_35 ) ;
F_80 ( & V_1 -> V_54 , F_61 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_41 , sizeof( V_1 -> V_41 ) , L_26 , V_35 -> V_41 ) ;
F_8 ( V_1 , V_150 ) ;
F_72 ( V_35 , V_1 ) ;
error = F_81 ( V_35 , V_163 ) ;
if ( error )
goto V_168;
if ( F_57 ( V_1 ) < 0 ) {
error = - V_169 ;
goto V_170;
}
V_1 -> V_70 = V_171 ;
V_1 -> V_67 = V_172 ;
V_1 -> V_42 = V_173 ;
V_1 -> V_58 = V_142 ? 0 : V_174 ;
V_1 -> V_175 = V_176 ;
F_75 ( V_1 , NULL ) ;
F_8 ( V_1 , V_140 ) ;
F_58 ( V_1 ) ;
error = F_82 ( V_1 -> V_3 ) ;
if ( error )
goto V_177;
if ( V_142 && V_142 -> V_102 )
V_142 -> V_102 ( V_142 ) ;
error = F_83 ( & V_35 -> V_3 . V_151 , & V_152 ) ;
if ( error )
goto V_178;
F_59 ( V_1 ) ;
V_45:
if ( V_142 )
F_59 ( V_142 ) ;
F_66 ( & V_145 ) ;
return V_164 ;
V_178:
if ( V_142 && V_142 -> V_103 )
V_142 -> V_103 ( V_142 ) ;
F_73 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_177:
if ( V_1 -> V_100 )
V_1 -> V_100 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_170:
F_71 ( V_35 ) ;
V_168:
F_72 ( V_35 , NULL ) ;
V_167:
F_84 ( V_2 ) ;
F_74 ( V_1 ) ;
V_164 = error ;
goto V_45;
}
static int F_85 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_142 = NULL ;
unsigned char type ;
int V_36 = - 1 ;
F_63 ( & V_145 ) ;
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
F_60 ( V_142 ) ;
}
F_8 ( V_1 , V_150 ) ;
if ( V_1 -> V_99 ) {
if ( V_1 -> V_99 ( V_1 ) )
goto V_45;
} else {
F_25 ( V_1 ) ;
if ( F_57 ( V_1 ) < 0 )
goto V_45;
type = F_42 ( V_1 , V_109 , false ) ;
if ( V_1 -> type != type )
goto V_45;
}
F_8 ( V_1 , V_140 ) ;
F_58 ( V_1 ) ;
if ( V_142 && V_142 -> V_102 )
V_142 -> V_102 ( V_142 ) ;
F_59 ( V_1 ) ;
V_36 = 0 ;
V_45:
if ( V_142 )
F_59 ( V_142 ) ;
F_66 ( & V_145 ) ;
return V_36 ;
}
T_4 F_86 ( struct V_179 * V_3 , struct V_180 * V_181 ,
char * V_182 )
{
struct V_35 * V_35 = F_87 ( V_3 ) ;
struct V_183 * V_184 = F_88 ( V_181 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( V_35 ) ;
return V_184 -> V_185 ( V_1 , V_184 -> V_44 , V_182 ) ;
}
T_4 F_89 ( struct V_179 * V_3 , struct V_180 * V_181 ,
const char * V_182 , T_3 V_186 )
{
struct V_35 * V_35 = F_87 ( V_3 ) ;
struct V_183 * V_184 = F_88 ( V_181 ) ;
struct V_1 * V_1 , * V_142 = NULL ;
int V_164 ;
V_164 = F_90 ( & V_145 ) ;
if ( V_164 )
goto V_45;
V_1 = F_16 ( V_35 ) ;
if ( V_184 -> V_187 ) {
if ( V_1 -> V_29 == V_43 ) {
V_164 = - V_169 ;
goto V_188;
}
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
F_60 ( V_142 ) ;
}
F_60 ( V_1 ) ;
}
V_164 = V_184 -> V_189 ( V_1 , V_184 -> V_44 , V_182 , V_186 ) ;
if ( V_184 -> V_187 ) {
if ( V_164 != - V_169 )
F_59 ( V_1 ) ;
if ( V_142 )
F_59 ( V_142 ) ;
}
V_188:
F_66 ( & V_145 ) ;
V_45:
return V_164 ;
}
static T_4 F_91 ( struct V_1 * V_1 , void * V_190 , char * V_182 )
{
unsigned int * V_191 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_190 ) ;
return sprintf ( V_182 , L_27 , * V_191 ) ;
}
static T_4 F_92 ( struct V_1 * V_1 , void * V_190 , const char * V_182 , T_3 V_186 )
{
unsigned int * V_191 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_190 ) ;
unsigned int V_192 ;
int V_193 ;
V_193 = F_93 ( V_182 , 10 , & V_192 ) ;
if ( V_193 )
return V_193 ;
* V_191 = V_192 ;
return V_186 ;
}
static T_4 F_94 ( struct V_1 * V_1 , void * V_44 , char * V_182 )
{
return sprintf ( V_182 , L_28 , F_54 ( V_1 -> type ) -> V_40 ) ;
}
static T_4 F_95 ( struct V_1 * V_1 , void * V_44 , const char * V_182 , T_3 V_186 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_142 = NULL ;
struct V_2 * V_194 , * V_195 ;
const struct V_132 * V_153 , * V_196 ;
int error ;
int V_197 = 0 ;
V_153 = F_56 ( V_182 , V_186 ) ;
if ( ! V_153 )
return - V_198 ;
if ( V_1 -> type == V_153 -> type )
return V_186 ;
V_195 = F_78 () ;
if ( ! V_195 )
return - V_165 ;
while ( ! F_96 ( & V_35 -> V_199 ) ) {
if ( ++ V_197 > 3 ) {
F_12 ( V_1 ,
L_29 ) ;
F_84 ( V_195 ) ;
return - V_200 ;
}
F_66 ( & V_145 ) ;
F_97 ( V_35 ) ;
F_63 ( & V_145 ) ;
if ( V_35 -> V_163 != & V_201 ) {
F_84 ( V_195 ) ;
return - V_169 ;
}
if ( V_1 -> type == V_153 -> type ) {
F_84 ( V_195 ) ;
return V_186 ;
}
}
if ( V_35 -> V_142 && V_35 -> V_146 . type == V_147 ) {
V_142 = F_16 ( V_35 -> V_142 ) ;
if ( V_142 -> V_103 )
V_142 -> V_103 ( V_142 ) ;
}
V_194 = V_1 -> V_3 ;
V_196 = F_54 ( V_1 -> type ) ;
if ( V_1 -> V_100 )
V_1 -> V_100 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_1 -> V_3 = V_195 ;
F_8 ( V_1 , V_150 ) ;
if ( F_75 ( V_1 , V_153 ) < 0 ) {
F_25 ( V_1 ) ;
F_75 ( V_1 , & V_134 [ 0 ] ) ;
}
F_58 ( V_1 ) ;
F_8 ( V_1 , V_140 ) ;
error = F_82 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_100 )
V_1 -> V_100 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
F_84 ( V_195 ) ;
V_1 -> V_3 = V_194 ;
F_8 ( V_1 , V_150 ) ;
F_75 ( V_1 , V_196 ) ;
F_58 ( V_1 ) ;
F_8 ( V_1 , V_140 ) ;
return error ;
}
F_73 ( V_194 ) ;
if ( V_142 && V_142 -> V_102 )
V_142 -> V_102 ( V_142 ) ;
return V_186 ;
}
static T_4 F_98 ( struct V_1 * V_1 , void * V_44 , const char * V_182 , T_3 V_186 )
{
unsigned int V_192 ;
int V_193 ;
V_193 = F_93 ( V_182 , 10 , & V_192 ) ;
if ( V_193 )
return V_193 ;
V_1 -> V_95 ( V_1 , V_192 ) ;
return V_186 ;
}
static T_4 F_99 ( struct V_1 * V_1 , void * V_44 , const char * V_182 , T_3 V_186 )
{
unsigned int V_192 ;
int V_193 ;
V_193 = F_93 ( V_182 , 10 , & V_192 ) ;
if ( V_193 )
return V_193 ;
V_1 -> V_96 ( V_1 , V_192 ) ;
return V_186 ;
}
static int F_100 ( const char * V_202 , const struct V_203 * V_204 )
{
const struct V_132 * V_153 ;
if ( ! V_202 )
return - V_198 ;
V_153 = F_56 ( V_202 , strlen ( V_202 ) ) ;
if ( ! V_153 || ! V_153 -> V_205 )
return - V_198 ;
* ( ( unsigned int * ) V_204 -> V_206 ) = V_153 -> type ;
return 0 ;
}
static int F_101 ( char * V_207 , const struct V_203 * V_204 )
{
int type = * ( ( unsigned int * ) V_204 -> V_206 ) ;
return sprintf ( V_207 , L_30 , F_54 ( type ) -> V_40 ) ;
}
static int T_5 F_102 ( void )
{
int V_193 ;
F_103 () ;
F_104 () ;
F_105 () ;
V_26 = F_106 ( L_31 ) ;
if ( ! V_26 ) {
F_107 ( L_32 ) ;
return - V_165 ;
}
V_193 = F_108 ( & V_201 ) ;
if ( V_193 )
F_109 ( V_26 ) ;
return V_193 ;
}
static void T_6 F_110 ( void )
{
F_111 ( & V_201 ) ;
F_109 ( V_26 ) ;
}
