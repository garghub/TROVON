static T_1 F_1 ( struct V_1 * V_1 )
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
static int F_26 ( struct V_1 * V_1 , bool V_67 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 4 ] ;
V_65 [ 0 ] = 3 ;
F_24 ( V_31 , V_65 , V_64 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , V_65 , V_68 ) ;
if ( V_65 [ 0 ] != 0x00 || V_65 [ 1 ] != 0x33 || V_65 [ 2 ] != 0x55 )
return - 1 ;
if ( V_67 ) {
F_27 ( V_18 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_14 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_13 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_10 , V_1 -> V_3 -> V_70 ) ;
V_1 -> V_71 = L_9 ;
V_1 -> V_40 = L_10 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , bool V_67 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 100 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_72 ) ;
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_65 [ 0 ] != 3 )
return - 1 ;
if ( V_67 ) {
F_27 ( V_18 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_10 , V_1 -> V_3 -> V_70 ) ;
if ( ! V_1 -> V_71 )
V_1 -> V_71 = L_11 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_12 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , bool V_67 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
F_28 ( V_1 , 0 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_72 ) ;
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_65 [ 0 ] != 4 )
return - 1 ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 40 ;
F_24 ( V_31 , V_65 , V_72 ) ;
if ( V_67 ) {
F_27 ( V_18 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_10 , V_1 -> V_3 -> V_70 ) ;
F_27 ( V_12 , V_1 -> V_3 -> V_70 ) ;
F_27 ( V_13 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_14 , V_1 -> V_3 -> V_69 ) ;
if ( ! V_1 -> V_71 )
V_1 -> V_71 = L_11 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_13 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , bool V_67 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
static const unsigned char V_74 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_61 ;
V_65 [ 0 ] = 10 ;
F_24 ( V_31 , V_65 , V_72 ) ;
V_65 [ 0 ] = 0 ;
F_24 ( V_31 , V_65 , V_64 ) ;
for ( V_61 = 0 ; V_61 < F_31 ( V_74 ) ; V_61 ++ ) {
V_65 [ 0 ] = V_74 [ V_61 ] ;
F_24 ( V_31 , V_65 , V_72 ) ;
}
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_65 [ 0 ] != 2 )
return - 1 ;
if ( V_67 ) {
F_27 ( V_18 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_14 , V_1 -> V_3 -> V_69 ) ;
V_1 -> V_71 = L_14 ;
V_1 -> V_40 = L_15 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , bool V_67 )
{
if ( V_67 ) {
if ( ! V_1 -> V_71 )
V_1 -> V_71 = L_11 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_10 ;
F_27 ( V_18 , V_1 -> V_3 -> V_69 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , bool V_67 )
{
if ( V_67 ) {
V_1 -> V_71 = L_16 ;
V_1 -> V_40 = L_17 ;
F_27 ( V_18 , V_1 -> V_3 -> V_69 ) ;
F_27 ( V_13 , V_1 -> V_3 -> V_69 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 ,
unsigned int V_75 , bool V_67 )
{
bool V_76 = false ;
if ( F_35 ( V_1 , V_67 ) == 0 ) {
if ( V_75 > V_11 ) {
if ( ! V_67 || F_36 ( V_1 ) == 0 )
return V_77 ;
}
}
if ( V_75 > V_11 && F_30 ( V_1 , V_67 ) == 0 )
return V_15 ;
if ( V_75 > V_78 && F_37 ( V_1 , V_67 ) == 0 ) {
V_76 = true ;
if ( V_75 > V_11 ) {
if ( F_38 () &&
( ! V_67 || F_39 ( V_1 ) == 0 ) ) {
return V_79 ;
}
V_75 = V_11 ;
}
F_40 ( V_1 ) ;
}
if ( V_75 > V_11 ) {
F_24 ( & V_1 -> V_31 , NULL , V_80 ) ;
if ( F_41 ( V_1 , V_67 ) == 0 ) {
if ( ! V_67 || F_42 ( V_1 ) == 0 )
return V_81 ;
V_75 = V_11 ;
}
}
if ( V_75 > V_11 &&
F_43 ( V_1 , V_67 ) == 0 ) {
if ( ! V_67 || F_44 ( V_1 ) == 0 )
return V_57 ;
V_75 = V_11 ;
}
if ( V_75 > V_11 &&
F_45 ( V_1 , V_67 ) == 0 ) {
if ( ! V_67 || F_46 ( V_1 ) == 0 )
return V_82 ;
V_75 = V_11 ;
}
if ( V_75 > V_11 ) {
if ( F_26 ( V_1 , V_67 ) == 0 )
return V_9 ;
if ( F_47 ( V_1 , V_67 ) == 0 )
return V_83 ;
if ( F_48 ( V_1 , V_67 ) == 0 )
return V_84 ;
if ( F_49 ( V_1 , V_67 ) == 0 )
return V_85 ;
}
if ( V_75 > V_11 ) {
if ( F_50 ( V_1 , V_67 ) == 0 ) {
if ( ! V_67 || F_51 ( V_1 ) == 0 )
return V_86 ;
V_75 = V_11 ;
}
}
F_24 ( & V_1 -> V_31 , NULL , V_80 ) ;
F_25 ( V_1 ) ;
if ( V_75 >= V_11 && F_29 ( V_1 , V_67 ) == 0 )
return V_11 ;
if ( V_75 >= V_8 && F_28 ( V_1 , V_67 ) == 0 )
return V_8 ;
F_32 ( V_1 , V_67 ) ;
if ( V_76 ) {
F_25 ( V_1 ) ;
}
return V_78 ;
}
static const struct V_87 * F_52 ( enum V_88 type )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_31 ( V_89 ) ; V_61 ++ )
if ( V_89 [ V_61 ] . type == type )
return & V_89 [ V_61 ] ;
F_53 ( 1 ) ;
return & V_89 [ 0 ] ;
}
static const struct V_87 * F_54 ( const char * V_40 , T_3 V_90 )
{
const struct V_87 * V_91 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_31 ( V_89 ) ; V_61 ++ ) {
V_91 = & V_89 [ V_61 ] ;
if ( ( strlen ( V_91 -> V_40 ) == V_90 && ! strncmp ( V_91 -> V_40 , V_40 , V_90 ) ) ||
( strlen ( V_91 -> V_92 ) == V_90 && ! strncmp ( V_91 -> V_92 , V_40 , V_90 ) ) )
return & V_89 [ V_61 ] ;
}
return NULL ;
}
static int F_55 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 0xa5 ;
if ( F_24 ( V_31 , V_65 , V_73 ) )
return - 1 ;
if ( V_65 [ 0 ] != 0x00 && V_65 [ 0 ] != 0x03 &&
V_65 [ 0 ] != 0x04 && V_65 [ 0 ] != 0xff )
return - 1 ;
if ( F_24 ( V_31 , NULL , V_80 ) )
F_12 ( V_1 , L_18 ,
V_31 -> V_35 -> V_41 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_1 , unsigned int V_93 )
{
static const unsigned char V_94 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_91 ;
if ( V_93 == 0 || V_93 > 200 )
V_93 = 200 ;
V_91 = V_94 [ V_93 / 50 ] ;
F_24 ( & V_1 -> V_31 , & V_91 , V_64 ) ;
V_1 -> V_93 = 25 << V_91 ;
}
static void F_57 ( struct V_1 * V_1 , unsigned int V_95 )
{
static const unsigned char V_96 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 , 0 } ;
unsigned char V_97 ;
int V_61 = 0 ;
while ( V_96 [ V_61 ] > V_95 ) V_61 ++ ;
V_97 = V_96 [ V_61 ] ;
F_24 ( & V_1 -> V_31 , & V_97 , V_72 ) ;
V_1 -> V_95 = V_97 ;
}
static void F_58 ( struct V_1 * V_1 )
{
if ( V_98 != V_78 ) {
V_1 -> V_99 ( V_1 , V_1 -> V_95 ) ;
V_1 -> V_100 ( V_1 , V_1 -> V_93 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_62 ) ;
}
}
static void F_59 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_101 ) )
F_12 ( V_1 , L_19 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
F_8 ( V_1 , V_39 ) ;
}
static void F_60 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_102 ) )
F_12 ( V_1 , L_20 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
F_8 ( V_1 , V_103 ) ;
}
static int F_61 ( struct V_1 * V_1 )
{
return F_24 ( & V_1 -> V_31 , V_1 -> V_4 ,
V_104 | ( V_1 -> V_6 << 8 ) ) ;
}
static void F_62 ( struct V_105 * V_24 )
{
struct V_1 * V_106 = NULL , * V_1 =
F_63 ( V_24 , struct V_1 , V_54 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_107 = false , V_108 = false ;
int V_61 ;
F_64 ( & V_109 ) ;
if ( V_1 -> V_29 != V_51 )
goto V_45;
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
F_60 ( V_106 ) ;
}
V_1 -> V_112 ++ ;
if ( F_65 ( & V_1 -> V_31 , V_102 , 20 ) ) {
if ( V_1 -> V_112 < 3 || V_1 -> V_113 )
V_107 = true ;
} else
V_1 -> V_113 = true ;
if ( ! V_107 ) {
if ( V_1 -> V_114 ( V_1 ) )
V_107 = true ;
else {
F_8 ( V_1 , V_103 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_6 ; V_61 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_107 = true ;
F_8 ( V_1 , V_51 ) ;
}
}
for ( V_61 = 0 ; V_61 < 5 ; V_61 ++ ) {
if ( ! F_24 ( & V_1 -> V_31 , NULL , V_101 ) ) {
V_108 = true ;
break;
}
F_66 ( 200 ) ;
}
if ( ! V_108 ) {
F_12 ( V_1 , L_21 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
V_107 = true ;
}
if ( V_107 ) {
F_8 ( V_1 , V_43 ) ;
F_22 ( V_1 ,
L_22 ) ;
F_14 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_106 )
F_59 ( V_106 ) ;
V_45:
F_67 ( & V_109 ) ;
}
static void F_68 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_106 = NULL ;
F_64 ( & V_109 ) ;
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
F_60 ( V_106 ) ;
}
F_8 ( V_1 , V_115 ) ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_102 ) )
F_12 ( V_1 , L_23 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
if ( V_1 -> V_116 )
V_1 -> V_116 ( V_1 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_80 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_101 ) ;
if ( V_106 ) {
if ( V_106 -> V_117 )
V_106 -> V_117 ( V_106 ) ;
F_59 ( V_106 ) ;
}
F_67 ( & V_109 ) ;
}
static void F_69 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_106 = NULL ;
V_1 = F_16 ( V_35 ) ;
F_70 ( & V_35 -> V_3 . V_118 , & V_119 ) ;
F_64 ( & V_109 ) ;
F_8 ( V_1 , V_103 ) ;
F_67 ( & V_109 ) ;
F_71 ( V_26 ) ;
F_64 ( & V_109 ) ;
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
F_60 ( V_106 ) ;
}
if ( V_1 -> V_120 )
V_1 -> V_120 ( V_1 ) ;
if ( V_106 && V_106 -> V_117 )
V_106 -> V_117 ( V_106 ) ;
F_8 ( V_1 , V_43 ) ;
F_72 ( V_35 ) ;
F_73 ( V_35 , NULL ) ;
F_74 ( V_1 -> V_3 ) ;
F_75 ( V_1 ) ;
if ( V_106 )
F_59 ( V_106 ) ;
F_67 ( & V_109 ) ;
}
static int F_76 ( struct V_1 * V_1 ,
const struct V_87 * V_121 )
{
const struct V_87 * V_122 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_106 = & V_1 -> V_31 . V_35 -> V_3 ;
V_2 -> V_123 [ 0 ] = F_77 ( V_124 ) | F_77 ( V_125 ) ;
V_2 -> V_69 [ F_78 ( V_126 ) ] =
F_77 ( V_17 ) | F_77 ( V_19 ) ;
V_2 -> V_70 [ 0 ] = F_77 ( V_20 ) | F_77 ( V_21 ) ;
V_1 -> V_99 = F_57 ;
V_1 -> V_100 = F_56 ;
V_1 -> V_114 = F_61 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_6 = 3 ;
if ( V_121 && ( V_121 -> V_127 || V_121 -> V_128 ) ) {
if ( V_121 -> V_127 && V_121 -> V_127 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_121 -> V_128 && V_121 -> V_128 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_121 -> type ;
V_122 = V_121 ;
} else {
V_1 -> type = F_34 ( V_1 ,
V_98 , true ) ;
V_122 = F_52 ( V_1 -> type ) ;
}
V_1 -> V_48 = V_122 -> V_48 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_58 = 0 ;
if ( V_1 -> V_58 && V_1 -> V_114 ( V_1 ) )
V_1 -> V_58 = 0 ;
snprintf ( V_1 -> V_129 , sizeof( V_1 -> V_129 ) , L_24 ,
V_122 -> V_40 , V_1 -> V_71 , V_1 -> V_40 ) ;
V_2 -> V_40 = V_1 -> V_129 ;
V_2 -> V_41 = V_1 -> V_41 ;
V_2 -> V_110 . V_130 = V_131 ;
V_2 -> V_110 . V_71 = 0x0002 ;
V_2 -> V_110 . V_132 = V_1 -> type ;
V_2 -> V_110 . V_133 = V_1 -> V_134 ;
return 0 ;
}
static int F_79 ( struct V_35 * V_35 , struct V_135 * V_136 )
{
struct V_1 * V_1 , * V_106 = NULL ;
struct V_2 * V_2 ;
int V_137 = 0 , error = - V_138 ;
F_64 ( & V_109 ) ;
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
F_60 ( V_106 ) ;
}
V_1 = F_80 ( sizeof( struct V_1 ) , V_139 ) ;
V_2 = F_81 () ;
if ( ! V_1 || ! V_2 )
goto V_140;
F_82 ( & V_1 -> V_31 , V_35 ) ;
F_83 ( & V_1 -> V_54 , F_62 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_41 , sizeof( V_1 -> V_41 ) , L_25 , V_35 -> V_41 ) ;
F_8 ( V_1 , V_115 ) ;
F_73 ( V_35 , V_1 ) ;
error = F_84 ( V_35 , V_136 ) ;
if ( error )
goto V_141;
if ( F_55 ( V_1 ) < 0 ) {
error = - V_142 ;
goto V_143;
}
V_1 -> V_95 = V_144 ;
V_1 -> V_93 = V_145 ;
V_1 -> V_42 = V_146 ;
V_1 -> V_58 = V_106 ? 0 : V_147 ;
V_1 -> V_148 = V_149 ;
F_76 ( V_1 , NULL ) ;
F_8 ( V_1 , V_103 ) ;
F_58 ( V_1 ) ;
error = F_85 ( V_1 -> V_3 ) ;
if ( error )
goto V_150;
if ( V_106 && V_106 -> V_151 )
V_106 -> V_151 ( V_106 ) ;
error = F_86 ( & V_35 -> V_3 . V_118 , & V_119 ) ;
if ( error )
goto V_152;
F_59 ( V_1 ) ;
V_45:
if ( V_106 )
F_59 ( V_106 ) ;
F_67 ( & V_109 ) ;
return V_137 ;
V_152:
if ( V_106 && V_106 -> V_117 )
V_106 -> V_117 ( V_106 ) ;
F_74 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_150:
if ( V_1 -> V_120 )
V_1 -> V_120 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_143:
F_72 ( V_35 ) ;
V_141:
F_73 ( V_35 , NULL ) ;
V_140:
F_87 ( V_2 ) ;
F_75 ( V_1 ) ;
V_137 = error ;
goto V_45;
}
static int F_88 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_106 = NULL ;
struct V_135 * V_136 = V_35 -> V_136 ;
unsigned char type ;
int V_36 = - 1 ;
if ( ! V_136 || ! V_1 ) {
F_89 ( V_1 ,
L_26 ) ;
return - 1 ;
}
F_64 ( & V_109 ) ;
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
F_60 ( V_106 ) ;
}
F_8 ( V_1 , V_115 ) ;
if ( V_1 -> V_153 ) {
if ( V_1 -> V_153 ( V_1 ) )
goto V_45;
} else {
F_25 ( V_1 ) ;
if ( F_55 ( V_1 ) < 0 )
goto V_45;
type = F_34 ( V_1 , V_98 , false ) ;
if ( V_1 -> type != type )
goto V_45;
}
F_8 ( V_1 , V_103 ) ;
F_58 ( V_1 ) ;
if ( V_106 && V_106 -> V_151 )
V_106 -> V_151 ( V_106 ) ;
F_59 ( V_1 ) ;
V_36 = 0 ;
V_45:
if ( V_106 )
F_59 ( V_106 ) ;
F_67 ( & V_109 ) ;
return V_36 ;
}
T_4 F_90 ( struct V_154 * V_3 , struct V_155 * V_156 ,
char * V_157 )
{
struct V_35 * V_35 = F_91 ( V_3 ) ;
struct V_158 * V_159 = F_92 ( V_156 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( V_35 ) ;
return V_159 -> V_160 ( V_1 , V_159 -> V_44 , V_157 ) ;
}
T_4 F_93 ( struct V_154 * V_3 , struct V_155 * V_156 ,
const char * V_157 , T_3 V_161 )
{
struct V_35 * V_35 = F_91 ( V_3 ) ;
struct V_158 * V_159 = F_92 ( V_156 ) ;
struct V_1 * V_1 , * V_106 = NULL ;
int V_137 ;
V_137 = F_94 ( & V_109 ) ;
if ( V_137 )
goto V_45;
V_1 = F_16 ( V_35 ) ;
if ( V_159 -> V_162 ) {
if ( V_1 -> V_29 == V_43 ) {
V_137 = - V_142 ;
goto V_163;
}
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
F_60 ( V_106 ) ;
}
F_60 ( V_1 ) ;
}
V_137 = V_159 -> V_164 ( V_1 , V_159 -> V_44 , V_157 , V_161 ) ;
if ( V_159 -> V_162 ) {
if ( V_137 != - V_142 )
F_59 ( V_1 ) ;
if ( V_106 )
F_59 ( V_106 ) ;
}
V_163:
F_67 ( & V_109 ) ;
V_45:
return V_137 ;
}
static T_4 F_95 ( struct V_1 * V_1 , void * V_165 , char * V_157 )
{
unsigned int * V_166 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_165 ) ;
return sprintf ( V_157 , L_27 , * V_166 ) ;
}
static T_4 F_96 ( struct V_1 * V_1 , void * V_165 , const char * V_157 , T_3 V_161 )
{
unsigned int * V_166 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_165 ) ;
unsigned long V_167 ;
if ( F_97 ( V_157 , 10 , & V_167 ) )
return - V_168 ;
if ( ( unsigned int ) V_167 != V_167 )
return - V_168 ;
* V_166 = V_167 ;
return V_161 ;
}
static T_4 F_98 ( struct V_1 * V_1 , void * V_44 , char * V_157 )
{
return sprintf ( V_157 , L_28 , F_52 ( V_1 -> type ) -> V_40 ) ;
}
static T_4 F_99 ( struct V_1 * V_1 , void * V_44 , const char * V_157 , T_3 V_161 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_106 = NULL ;
struct V_2 * V_169 , * V_170 ;
const struct V_87 * V_121 , * V_171 ;
int error ;
int V_172 = 0 ;
V_121 = F_54 ( V_157 , V_161 ) ;
if ( ! V_121 )
return - V_168 ;
if ( V_1 -> type == V_121 -> type )
return V_161 ;
V_170 = F_81 () ;
if ( ! V_170 )
return - V_138 ;
while ( ! F_100 ( & V_35 -> V_173 ) ) {
if ( ++ V_172 > 3 ) {
F_12 ( V_1 ,
L_29 ) ;
F_87 ( V_170 ) ;
return - V_174 ;
}
F_67 ( & V_109 ) ;
F_101 ( V_35 ) ;
F_64 ( & V_109 ) ;
if ( V_35 -> V_136 != & V_175 ) {
F_87 ( V_170 ) ;
return - V_142 ;
}
if ( V_1 -> type == V_121 -> type ) {
F_87 ( V_170 ) ;
return V_161 ;
}
}
if ( V_35 -> V_106 && V_35 -> V_110 . type == V_111 ) {
V_106 = F_16 ( V_35 -> V_106 ) ;
if ( V_106 -> V_117 )
V_106 -> V_117 ( V_106 ) ;
}
V_169 = V_1 -> V_3 ;
V_171 = F_52 ( V_1 -> type ) ;
if ( V_1 -> V_120 )
V_1 -> V_120 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_1 -> V_3 = V_170 ;
F_8 ( V_1 , V_115 ) ;
if ( F_76 ( V_1 , V_121 ) < 0 ) {
F_25 ( V_1 ) ;
F_76 ( V_1 , & V_89 [ 0 ] ) ;
}
F_58 ( V_1 ) ;
F_8 ( V_1 , V_103 ) ;
error = F_85 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_120 )
V_1 -> V_120 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
F_87 ( V_170 ) ;
V_1 -> V_3 = V_169 ;
F_8 ( V_1 , V_115 ) ;
F_76 ( V_1 , V_171 ) ;
F_58 ( V_1 ) ;
F_8 ( V_1 , V_103 ) ;
return error ;
}
F_74 ( V_169 ) ;
if ( V_106 && V_106 -> V_151 )
V_106 -> V_151 ( V_106 ) ;
return V_161 ;
}
static T_4 F_102 ( struct V_1 * V_1 , void * V_44 , const char * V_157 , T_3 V_161 )
{
unsigned long V_167 ;
if ( F_97 ( V_157 , 10 , & V_167 ) )
return - V_168 ;
V_1 -> V_99 ( V_1 , V_167 ) ;
return V_161 ;
}
static T_4 F_103 ( struct V_1 * V_1 , void * V_44 , const char * V_157 , T_3 V_161 )
{
unsigned long V_167 ;
if ( F_97 ( V_157 , 10 , & V_167 ) )
return - V_168 ;
V_1 -> V_100 ( V_1 , V_167 ) ;
return V_161 ;
}
static int F_104 ( const char * V_176 , const struct V_177 * V_178 )
{
const struct V_87 * V_121 ;
if ( ! V_176 )
return - V_168 ;
V_121 = F_54 ( V_176 , strlen ( V_176 ) ) ;
if ( ! V_121 || ! V_121 -> V_179 )
return - V_168 ;
* ( ( unsigned int * ) V_178 -> V_180 ) = V_121 -> type ;
return 0 ;
}
static int F_105 ( char * V_181 , const struct V_177 * V_178 )
{
int type = * ( ( unsigned int * ) V_178 -> V_180 ) ;
return sprintf ( V_181 , L_30 , F_52 ( type ) -> V_40 ) ;
}
static int T_5 F_106 ( void )
{
int V_182 ;
F_107 () ;
F_108 () ;
F_109 () ;
V_26 = F_110 ( L_31 ) ;
if ( ! V_26 ) {
F_111 ( L_32 ) ;
return - V_138 ;
}
V_182 = F_112 ( & V_175 ) ;
if ( V_182 )
F_113 ( V_26 ) ;
return V_182 ;
}
static void T_6 F_114 ( void )
{
F_115 ( & V_175 ) ;
F_113 ( V_26 ) ;
}
