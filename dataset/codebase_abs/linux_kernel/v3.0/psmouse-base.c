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
F_12 ( V_40 L_1 ,
V_1 -> V_41 , V_1 -> V_42 , V_1 -> V_5 ) ;
if ( ++ V_1 -> V_30 == V_1 -> V_43 ) {
F_7 ( V_1 , V_44 ) ;
F_12 ( V_45 L_2 ) ;
F_13 ( V_1 -> V_31 . V_35 ) ;
return - 1 ;
}
}
V_1 -> V_5 = 0 ;
break;
case V_22 :
V_1 -> V_5 = 0 ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 = 0 ;
F_12 ( V_45 L_3 ,
V_1 -> V_41 , V_1 -> V_42 ) ;
}
break;
case V_7 :
break;
}
return 0 ;
}
static T_2 F_14 ( struct V_35 * V_35 ,
unsigned char V_46 , unsigned int V_32 )
{
struct V_1 * V_1 = F_15 ( V_35 ) ;
if ( V_1 -> V_29 == V_44 )
goto V_47;
if ( F_16 ( ( V_32 & V_48 ) ||
( ( V_32 & V_49 ) && ! V_1 -> V_50 ) ) ) {
if ( V_1 -> V_29 == V_39 )
F_12 ( V_40 L_4 ,
V_32 & V_48 ? L_5 : L_6 ,
V_32 & V_49 ? L_7 : L_6 ) ;
F_17 ( & V_1 -> V_31 ) ;
goto V_47;
}
if ( F_16 ( V_1 -> V_31 . V_32 & V_51 ) )
if ( F_18 ( & V_1 -> V_31 , V_46 ) )
goto V_47;
if ( F_16 ( V_1 -> V_31 . V_32 & V_52 ) )
if ( F_19 ( & V_1 -> V_31 , V_46 ) )
goto V_47;
if ( V_1 -> V_29 <= V_53 )
goto V_47;
if ( V_1 -> V_29 == V_39 &&
V_1 -> V_5 && F_20 ( V_34 , V_1 -> V_33 + V_54 / 2 ) ) {
F_12 ( V_55 L_8 ,
V_1 -> V_41 , V_1 -> V_42 , V_1 -> V_5 ) ;
V_1 -> V_56 = V_1 -> V_4 [ 0 ] ;
F_7 ( V_1 , V_53 ) ;
F_5 ( V_1 , & V_1 -> V_57 , 0 ) ;
goto V_47;
}
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_46 ;
if ( F_16 ( V_1 -> V_4 [ 0 ] == V_58 && V_1 -> V_5 <= 2 ) ) {
if ( V_1 -> V_5 == 1 ) {
V_1 -> V_33 = V_34 ;
goto V_47;
}
if ( V_1 -> V_4 [ 1 ] == V_59 ||
( V_1 -> type == V_60 &&
V_1 -> V_4 [ 1 ] == V_58 ) ) {
F_7 ( V_1 , V_44 ) ;
F_13 ( V_35 ) ;
goto V_47;
}
V_1 -> V_5 = 1 ;
if ( F_11 ( V_1 ) )
goto V_47;
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_46 ;
}
if ( V_1 -> V_29 == V_39 &&
V_1 -> V_5 == 1 && V_1 -> V_61 &&
F_20 ( V_34 , V_1 -> V_33 + V_1 -> V_61 * V_54 ) ) {
V_1 -> V_56 = V_1 -> V_4 [ 0 ] ;
F_7 ( V_1 , V_53 ) ;
F_5 ( V_1 , & V_1 -> V_57 , 0 ) ;
goto V_47;
}
V_1 -> V_33 = V_34 ;
F_11 ( V_1 ) ;
V_47:
return V_62 ;
}
int F_21 ( struct V_1 * V_1 , unsigned char V_63 )
{
int V_64 ;
if ( F_22 ( & V_1 -> V_31 , NULL , V_65 ) )
return - 1 ;
for ( V_64 = 6 ; V_64 >= 0 ; V_64 -= 2 ) {
unsigned char V_66 = ( V_63 >> V_64 ) & 3 ;
if ( F_22 ( & V_1 -> V_31 , & V_66 , V_67 ) )
return - 1 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 )
{
unsigned char V_68 [ 2 ] ;
if ( F_22 ( & V_1 -> V_31 , V_68 , V_69 ) )
return - 1 ;
if ( V_68 [ 0 ] != V_58 && V_68 [ 1 ] != V_59 )
return - 1 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , bool V_70 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_68 [ 4 ] ;
V_68 [ 0 ] = 3 ;
F_22 ( V_31 , V_68 , V_67 ) ;
F_22 ( V_31 , NULL , V_65 ) ;
F_22 ( V_31 , NULL , V_65 ) ;
F_22 ( V_31 , NULL , V_65 ) ;
F_22 ( V_31 , V_68 , V_71 ) ;
if ( V_68 [ 0 ] != 0x00 || V_68 [ 1 ] != 0x33 || V_68 [ 2 ] != 0x55 )
return - 1 ;
if ( V_70 ) {
F_25 ( V_18 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_14 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_13 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_10 , V_1 -> V_3 -> V_73 ) ;
V_1 -> V_74 = L_9 ;
V_1 -> V_41 = L_10 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , bool V_70 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_68 [ 2 ] ;
V_68 [ 0 ] = 200 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 100 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 80 ;
F_22 ( V_31 , V_68 , V_75 ) ;
F_22 ( V_31 , V_68 , V_76 ) ;
if ( V_68 [ 0 ] != 3 )
return - 1 ;
if ( V_70 ) {
F_25 ( V_18 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_10 , V_1 -> V_3 -> V_73 ) ;
if ( ! V_1 -> V_74 )
V_1 -> V_74 = L_11 ;
if ( ! V_1 -> V_41 )
V_1 -> V_41 = L_12 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_1 , bool V_70 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_68 [ 2 ] ;
F_26 ( V_1 , 0 ) ;
V_68 [ 0 ] = 200 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 200 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 80 ;
F_22 ( V_31 , V_68 , V_75 ) ;
F_22 ( V_31 , V_68 , V_76 ) ;
if ( V_68 [ 0 ] != 4 )
return - 1 ;
V_68 [ 0 ] = 200 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 80 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 40 ;
F_22 ( V_31 , V_68 , V_75 ) ;
if ( V_70 ) {
F_25 ( V_18 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_10 , V_1 -> V_3 -> V_73 ) ;
F_25 ( V_12 , V_1 -> V_3 -> V_73 ) ;
F_25 ( V_13 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_14 , V_1 -> V_3 -> V_72 ) ;
if ( ! V_1 -> V_74 )
V_1 -> V_74 = L_11 ;
if ( ! V_1 -> V_41 )
V_1 -> V_41 = L_13 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , bool V_70 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_68 [ 2 ] ;
static const unsigned char V_77 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_64 ;
V_68 [ 0 ] = 10 ;
F_22 ( V_31 , V_68 , V_75 ) ;
V_68 [ 0 ] = 0 ;
F_22 ( V_31 , V_68 , V_67 ) ;
for ( V_64 = 0 ; V_64 < F_29 ( V_77 ) ; V_64 ++ ) {
V_68 [ 0 ] = V_77 [ V_64 ] ;
F_22 ( V_31 , V_68 , V_75 ) ;
}
F_22 ( V_31 , V_68 , V_76 ) ;
if ( V_68 [ 0 ] != 2 )
return - 1 ;
if ( V_70 ) {
F_25 ( V_18 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_14 , V_1 -> V_3 -> V_72 ) ;
V_1 -> V_74 = L_14 ;
V_1 -> V_41 = L_15 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , bool V_70 )
{
if ( V_70 ) {
if ( ! V_1 -> V_74 )
V_1 -> V_74 = L_11 ;
if ( ! V_1 -> V_41 )
V_1 -> V_41 = L_10 ;
F_25 ( V_18 , V_1 -> V_3 -> V_72 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , bool V_70 )
{
if ( V_70 ) {
V_1 -> V_74 = L_16 ;
V_1 -> V_41 = L_17 ;
F_25 ( V_18 , V_1 -> V_3 -> V_72 ) ;
F_25 ( V_13 , V_1 -> V_3 -> V_72 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 ,
unsigned int V_78 , bool V_70 )
{
bool V_79 = false ;
if ( F_33 ( V_1 , V_70 ) == 0 ) {
if ( V_78 > V_11 ) {
if ( ! V_70 || F_34 ( V_1 ) == 0 )
return V_80 ;
}
}
if ( V_78 > V_11 && F_28 ( V_1 , V_70 ) == 0 )
return V_15 ;
if ( V_78 > V_81 && F_35 ( V_1 , V_70 ) == 0 ) {
V_79 = true ;
if ( V_78 > V_11 ) {
if ( F_36 () &&
( ! V_70 || F_37 ( V_1 ) == 0 ) ) {
return V_82 ;
}
V_78 = V_11 ;
}
F_38 ( V_1 ) ;
}
if ( V_78 > V_11 ) {
F_22 ( & V_1 -> V_31 , NULL , V_83 ) ;
if ( F_39 ( V_1 , V_70 ) == 0 ) {
if ( ! V_70 || F_40 ( V_1 ) == 0 )
return V_84 ;
V_78 = V_11 ;
}
}
if ( V_78 > V_11 &&
F_41 ( V_1 , V_70 ) == 0 ) {
if ( ! V_70 || F_42 ( V_1 ) == 0 )
return V_60 ;
V_78 = V_11 ;
}
if ( V_78 > V_11 &&
F_43 ( V_1 , V_70 ) == 0 ) {
if ( ! V_70 || F_44 ( V_1 ) == 0 )
return V_85 ;
V_78 = V_11 ;
}
if ( V_78 > V_11 ) {
if ( F_24 ( V_1 , V_70 ) == 0 )
return V_9 ;
if ( F_45 ( V_1 , V_70 ) == 0 )
return V_86 ;
if ( F_46 ( V_1 , V_70 ) == 0 )
return V_87 ;
if ( F_47 ( V_1 , V_70 ) == 0 )
return V_88 ;
}
if ( V_78 > V_11 ) {
if ( F_48 ( V_1 , V_70 ) == 0 ) {
if ( ! V_70 || F_49 ( V_1 ) == 0 )
return V_89 ;
V_78 = V_11 ;
}
}
F_22 ( & V_1 -> V_31 , NULL , V_83 ) ;
F_23 ( V_1 ) ;
if ( V_78 >= V_11 && F_27 ( V_1 , V_70 ) == 0 )
return V_11 ;
if ( V_78 >= V_8 && F_26 ( V_1 , V_70 ) == 0 )
return V_8 ;
F_30 ( V_1 , V_70 ) ;
if ( V_79 ) {
F_23 ( V_1 ) ;
}
return V_81 ;
}
static const struct V_90 * F_50 ( enum V_91 type )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < F_29 ( V_92 ) ; V_64 ++ )
if ( V_92 [ V_64 ] . type == type )
return & V_92 [ V_64 ] ;
F_51 ( 1 ) ;
return & V_92 [ 0 ] ;
}
static const struct V_90 * F_52 ( const char * V_41 , T_3 V_93 )
{
const struct V_90 * V_94 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < F_29 ( V_92 ) ; V_64 ++ ) {
V_94 = & V_92 [ V_64 ] ;
if ( ( strlen ( V_94 -> V_41 ) == V_93 && ! strncmp ( V_94 -> V_41 , V_41 , V_93 ) ) ||
( strlen ( V_94 -> V_95 ) == V_93 && ! strncmp ( V_94 -> V_95 , V_41 , V_93 ) ) )
return & V_92 [ V_64 ] ;
}
return NULL ;
}
static int F_53 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_68 [ 2 ] ;
V_68 [ 0 ] = 0xa5 ;
if ( F_22 ( V_31 , V_68 , V_76 ) )
return - 1 ;
if ( V_68 [ 0 ] != 0x00 && V_68 [ 0 ] != 0x03 &&
V_68 [ 0 ] != 0x04 && V_68 [ 0 ] != 0xff )
return - 1 ;
if ( F_22 ( V_31 , NULL , V_83 ) )
F_12 ( V_40 L_18 , V_31 -> V_35 -> V_42 ) ;
return 0 ;
}
void F_54 ( struct V_1 * V_1 , unsigned int V_96 )
{
static const unsigned char V_97 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_94 ;
if ( V_96 == 0 || V_96 > 200 )
V_96 = 200 ;
V_94 = V_97 [ V_96 / 50 ] ;
F_22 ( & V_1 -> V_31 , & V_94 , V_67 ) ;
V_1 -> V_96 = 25 << V_94 ;
}
static void F_55 ( struct V_1 * V_1 , unsigned int V_98 )
{
static const unsigned char V_99 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 , 0 } ;
unsigned char V_100 ;
int V_64 = 0 ;
while ( V_99 [ V_64 ] > V_98 ) V_64 ++ ;
V_100 = V_99 [ V_64 ] ;
F_22 ( & V_1 -> V_31 , & V_100 , V_75 ) ;
V_1 -> V_98 = V_100 ;
}
static void F_56 ( struct V_1 * V_1 )
{
if ( V_101 != V_81 ) {
V_1 -> V_102 ( V_1 , V_1 -> V_98 ) ;
V_1 -> V_103 ( V_1 , V_1 -> V_96 ) ;
F_22 ( & V_1 -> V_31 , NULL , V_65 ) ;
}
}
static void F_57 ( struct V_1 * V_1 )
{
if ( F_22 ( & V_1 -> V_31 , NULL , V_104 ) )
F_12 ( V_40 L_19 ,
V_1 -> V_31 . V_35 -> V_42 ) ;
F_8 ( V_1 , V_39 ) ;
}
static void F_58 ( struct V_1 * V_1 )
{
if ( F_22 ( & V_1 -> V_31 , NULL , V_105 ) )
F_12 ( V_40 L_20 ,
V_1 -> V_31 . V_35 -> V_42 ) ;
F_8 ( V_1 , V_106 ) ;
}
static int F_59 ( struct V_1 * V_1 )
{
return F_22 ( & V_1 -> V_31 , V_1 -> V_4 ,
V_107 | ( V_1 -> V_6 << 8 ) ) ;
}
static void F_60 ( struct V_108 * V_24 )
{
struct V_1 * V_109 = NULL , * V_1 =
F_61 ( V_24 , struct V_1 , V_57 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_110 = false , V_111 = false ;
int V_64 ;
F_62 ( & V_112 ) ;
if ( V_1 -> V_29 != V_53 )
goto V_47;
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
F_58 ( V_109 ) ;
}
V_1 -> V_115 ++ ;
if ( F_63 ( & V_1 -> V_31 , V_105 , 20 ) ) {
if ( V_1 -> V_115 < 3 || V_1 -> V_116 )
V_110 = true ;
} else
V_1 -> V_116 = true ;
if ( ! V_110 ) {
if ( V_1 -> V_117 ( V_1 ) )
V_110 = true ;
else {
F_8 ( V_1 , V_106 ) ;
for ( V_64 = 0 ; V_64 < V_1 -> V_6 ; V_64 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_110 = true ;
F_8 ( V_1 , V_53 ) ;
}
}
for ( V_64 = 0 ; V_64 < 5 ; V_64 ++ ) {
if ( ! F_22 ( & V_1 -> V_31 , NULL , V_104 ) ) {
V_111 = true ;
break;
}
F_64 ( 200 ) ;
}
if ( ! V_111 ) {
F_12 ( V_40 L_21 ,
V_1 -> V_31 . V_35 -> V_42 ) ;
V_110 = true ;
}
if ( V_110 ) {
F_8 ( V_1 , V_44 ) ;
F_12 ( V_55 L_22 ) ;
F_13 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_109 )
F_57 ( V_109 ) ;
V_47:
F_65 ( & V_112 ) ;
}
static void F_66 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_15 ( V_35 ) ;
struct V_1 * V_109 = NULL ;
F_62 ( & V_112 ) ;
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
F_58 ( V_109 ) ;
}
F_8 ( V_1 , V_118 ) ;
if ( F_22 ( & V_1 -> V_31 , NULL , V_105 ) )
F_12 ( V_40 L_23 ,
V_1 -> V_31 . V_35 -> V_42 ) ;
if ( V_1 -> V_119 )
V_1 -> V_119 ( V_1 ) ;
F_22 ( & V_1 -> V_31 , NULL , V_83 ) ;
F_22 ( & V_1 -> V_31 , NULL , V_104 ) ;
if ( V_109 ) {
if ( V_109 -> V_120 )
V_109 -> V_120 ( V_109 ) ;
F_57 ( V_109 ) ;
}
F_65 ( & V_112 ) ;
}
static void F_67 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_109 = NULL ;
V_1 = F_15 ( V_35 ) ;
F_68 ( & V_35 -> V_3 . V_121 , & V_122 ) ;
F_62 ( & V_112 ) ;
F_8 ( V_1 , V_106 ) ;
F_65 ( & V_112 ) ;
F_69 ( V_26 ) ;
F_62 ( & V_112 ) ;
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
F_58 ( V_109 ) ;
}
if ( V_1 -> V_123 )
V_1 -> V_123 ( V_1 ) ;
if ( V_109 && V_109 -> V_120 )
V_109 -> V_120 ( V_109 ) ;
F_8 ( V_1 , V_44 ) ;
F_70 ( V_35 ) ;
F_71 ( V_35 , NULL ) ;
F_72 ( V_1 -> V_3 ) ;
F_73 ( V_1 ) ;
if ( V_109 )
F_57 ( V_109 ) ;
F_65 ( & V_112 ) ;
}
static int F_74 ( struct V_1 * V_1 ,
const struct V_90 * V_124 )
{
const struct V_90 * V_125 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_109 = & V_1 -> V_31 . V_35 -> V_3 ;
V_2 -> V_126 [ 0 ] = F_75 ( V_127 ) | F_75 ( V_128 ) ;
V_2 -> V_72 [ F_76 ( V_129 ) ] =
F_75 ( V_17 ) | F_75 ( V_19 ) ;
V_2 -> V_73 [ 0 ] = F_75 ( V_20 ) | F_75 ( V_21 ) ;
V_1 -> V_102 = F_55 ;
V_1 -> V_103 = F_54 ;
V_1 -> V_117 = F_59 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_6 = 3 ;
if ( V_124 && ( V_124 -> V_130 || V_124 -> V_131 ) ) {
if ( V_124 -> V_130 && V_124 -> V_130 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_124 -> V_131 && V_124 -> V_131 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_124 -> type ;
V_125 = V_124 ;
} else {
V_1 -> type = F_32 ( V_1 ,
V_101 , true ) ;
V_125 = F_50 ( V_1 -> type ) ;
}
V_1 -> V_50 = V_125 -> V_50 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_61 = 0 ;
if ( V_1 -> V_61 && V_1 -> V_117 ( V_1 ) )
V_1 -> V_61 = 0 ;
snprintf ( V_1 -> V_132 , sizeof( V_1 -> V_132 ) , L_24 ,
V_125 -> V_41 , V_1 -> V_74 , V_1 -> V_41 ) ;
V_2 -> V_41 = V_1 -> V_132 ;
V_2 -> V_42 = V_1 -> V_42 ;
V_2 -> V_113 . V_133 = V_134 ;
V_2 -> V_113 . V_74 = 0x0002 ;
V_2 -> V_113 . V_135 = V_1 -> type ;
V_2 -> V_113 . V_136 = V_1 -> V_137 ;
return 0 ;
}
static int F_77 ( struct V_35 * V_35 , struct V_138 * V_139 )
{
struct V_1 * V_1 , * V_109 = NULL ;
struct V_2 * V_2 ;
int V_140 = 0 , error = - V_141 ;
F_62 ( & V_112 ) ;
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
F_58 ( V_109 ) ;
}
V_1 = F_78 ( sizeof( struct V_1 ) , V_142 ) ;
V_2 = F_79 () ;
if ( ! V_1 || ! V_2 )
goto V_143;
F_80 ( & V_1 -> V_31 , V_35 ) ;
F_81 ( & V_1 -> V_57 , F_60 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_42 , sizeof( V_1 -> V_42 ) , L_25 , V_35 -> V_42 ) ;
F_8 ( V_1 , V_118 ) ;
F_71 ( V_35 , V_1 ) ;
error = F_82 ( V_35 , V_139 ) ;
if ( error )
goto V_144;
if ( F_53 ( V_1 ) < 0 ) {
error = - V_145 ;
goto V_146;
}
V_1 -> V_98 = V_147 ;
V_1 -> V_96 = V_148 ;
V_1 -> V_43 = V_149 ;
V_1 -> V_61 = V_109 ? 0 : V_150 ;
V_1 -> V_151 = V_152 ;
F_74 ( V_1 , NULL ) ;
F_8 ( V_1 , V_106 ) ;
F_56 ( V_1 ) ;
error = F_83 ( V_1 -> V_3 ) ;
if ( error )
goto V_153;
if ( V_109 && V_109 -> V_154 )
V_109 -> V_154 ( V_109 ) ;
error = F_84 ( & V_35 -> V_3 . V_121 , & V_122 ) ;
if ( error )
goto V_155;
F_57 ( V_1 ) ;
V_47:
if ( V_109 )
F_57 ( V_109 ) ;
F_65 ( & V_112 ) ;
return V_140 ;
V_155:
if ( V_109 && V_109 -> V_120 )
V_109 -> V_120 ( V_109 ) ;
F_72 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_153:
if ( V_1 -> V_123 )
V_1 -> V_123 ( V_1 ) ;
F_8 ( V_1 , V_44 ) ;
V_146:
F_70 ( V_35 ) ;
V_144:
F_71 ( V_35 , NULL ) ;
V_143:
F_85 ( V_2 ) ;
F_73 ( V_1 ) ;
V_140 = error ;
goto V_47;
}
static int F_86 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_15 ( V_35 ) ;
struct V_1 * V_109 = NULL ;
struct V_138 * V_139 = V_35 -> V_139 ;
unsigned char type ;
int V_36 = - 1 ;
if ( ! V_139 || ! V_1 ) {
F_12 ( V_156 L_26 ) ;
return - 1 ;
}
F_62 ( & V_112 ) ;
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
F_58 ( V_109 ) ;
}
F_8 ( V_1 , V_118 ) ;
if ( V_1 -> V_157 ) {
if ( V_1 -> V_157 ( V_1 ) )
goto V_47;
} else {
F_23 ( V_1 ) ;
if ( F_53 ( V_1 ) < 0 )
goto V_47;
type = F_32 ( V_1 , V_101 , false ) ;
if ( V_1 -> type != type )
goto V_47;
}
F_8 ( V_1 , V_106 ) ;
F_56 ( V_1 ) ;
if ( V_109 && V_109 -> V_154 )
V_109 -> V_154 ( V_109 ) ;
F_57 ( V_1 ) ;
V_36 = 0 ;
V_47:
if ( V_109 )
F_57 ( V_109 ) ;
F_65 ( & V_112 ) ;
return V_36 ;
}
T_4 F_87 ( struct V_158 * V_3 , struct V_159 * V_160 ,
char * V_161 )
{
struct V_35 * V_35 = F_88 ( V_3 ) ;
struct V_162 * V_163 = F_89 ( V_160 ) ;
struct V_1 * V_1 ;
V_1 = F_15 ( V_35 ) ;
return V_163 -> V_164 ( V_1 , V_163 -> V_46 , V_161 ) ;
}
T_4 F_90 ( struct V_158 * V_3 , struct V_159 * V_160 ,
const char * V_161 , T_3 V_165 )
{
struct V_35 * V_35 = F_88 ( V_3 ) ;
struct V_162 * V_163 = F_89 ( V_160 ) ;
struct V_1 * V_1 , * V_109 = NULL ;
int V_140 ;
V_140 = F_91 ( & V_112 ) ;
if ( V_140 )
goto V_47;
V_1 = F_15 ( V_35 ) ;
if ( V_163 -> V_166 ) {
if ( V_1 -> V_29 == V_44 ) {
V_140 = - V_145 ;
goto V_167;
}
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
F_58 ( V_109 ) ;
}
F_58 ( V_1 ) ;
}
V_140 = V_163 -> V_168 ( V_1 , V_163 -> V_46 , V_161 , V_165 ) ;
if ( V_163 -> V_166 ) {
if ( V_140 != - V_145 )
F_57 ( V_1 ) ;
if ( V_109 )
F_57 ( V_109 ) ;
}
V_167:
F_65 ( & V_112 ) ;
V_47:
return V_140 ;
}
static T_4 F_92 ( struct V_1 * V_1 , void * V_169 , char * V_161 )
{
unsigned int * V_170 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_169 ) ;
return sprintf ( V_161 , L_27 , * V_170 ) ;
}
static T_4 F_93 ( struct V_1 * V_1 , void * V_169 , const char * V_161 , T_3 V_165 )
{
unsigned int * V_170 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_169 ) ;
unsigned long V_171 ;
if ( F_94 ( V_161 , 10 , & V_171 ) )
return - V_172 ;
if ( ( unsigned int ) V_171 != V_171 )
return - V_172 ;
* V_170 = V_171 ;
return V_165 ;
}
static T_4 F_95 ( struct V_1 * V_1 , void * V_46 , char * V_161 )
{
return sprintf ( V_161 , L_28 , F_50 ( V_1 -> type ) -> V_41 ) ;
}
static T_4 F_96 ( struct V_1 * V_1 , void * V_46 , const char * V_161 , T_3 V_165 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_109 = NULL ;
struct V_2 * V_173 , * V_174 ;
const struct V_90 * V_124 , * V_175 ;
int error ;
int V_176 = 0 ;
V_124 = F_52 ( V_161 , V_165 ) ;
if ( ! V_124 )
return - V_172 ;
if ( V_1 -> type == V_124 -> type )
return V_165 ;
V_174 = F_79 () ;
if ( ! V_174 )
return - V_141 ;
while ( ! F_97 ( & V_35 -> V_177 ) ) {
if ( ++ V_176 > 3 ) {
F_12 ( V_40
L_29
L_30 ) ;
F_85 ( V_174 ) ;
return - V_178 ;
}
F_65 ( & V_112 ) ;
F_98 ( V_35 ) ;
F_62 ( & V_112 ) ;
if ( V_35 -> V_139 != & V_179 ) {
F_85 ( V_174 ) ;
return - V_145 ;
}
if ( V_1 -> type == V_124 -> type ) {
F_85 ( V_174 ) ;
return V_165 ;
}
}
if ( V_35 -> V_109 && V_35 -> V_113 . type == V_114 ) {
V_109 = F_15 ( V_35 -> V_109 ) ;
if ( V_109 -> V_120 )
V_109 -> V_120 ( V_109 ) ;
}
V_173 = V_1 -> V_3 ;
V_175 = F_50 ( V_1 -> type ) ;
if ( V_1 -> V_123 )
V_1 -> V_123 ( V_1 ) ;
F_8 ( V_1 , V_44 ) ;
V_1 -> V_3 = V_174 ;
F_8 ( V_1 , V_118 ) ;
if ( F_74 ( V_1 , V_124 ) < 0 ) {
F_23 ( V_1 ) ;
F_74 ( V_1 , & V_92 [ 0 ] ) ;
}
F_56 ( V_1 ) ;
F_8 ( V_1 , V_106 ) ;
error = F_83 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_123 )
V_1 -> V_123 ( V_1 ) ;
F_8 ( V_1 , V_44 ) ;
F_85 ( V_174 ) ;
V_1 -> V_3 = V_173 ;
F_8 ( V_1 , V_118 ) ;
F_74 ( V_1 , V_175 ) ;
F_56 ( V_1 ) ;
F_8 ( V_1 , V_106 ) ;
return error ;
}
F_72 ( V_173 ) ;
if ( V_109 && V_109 -> V_154 )
V_109 -> V_154 ( V_109 ) ;
return V_165 ;
}
static T_4 F_99 ( struct V_1 * V_1 , void * V_46 , const char * V_161 , T_3 V_165 )
{
unsigned long V_171 ;
if ( F_94 ( V_161 , 10 , & V_171 ) )
return - V_172 ;
V_1 -> V_102 ( V_1 , V_171 ) ;
return V_165 ;
}
static T_4 F_100 ( struct V_1 * V_1 , void * V_46 , const char * V_161 , T_3 V_165 )
{
unsigned long V_171 ;
if ( F_94 ( V_161 , 10 , & V_171 ) )
return - V_172 ;
V_1 -> V_103 ( V_1 , V_171 ) ;
return V_165 ;
}
static int F_101 ( const char * V_180 , const struct V_181 * V_182 )
{
const struct V_90 * V_124 ;
if ( ! V_180 )
return - V_172 ;
V_124 = F_52 ( V_180 , strlen ( V_180 ) ) ;
if ( ! V_124 || ! V_124 -> V_183 )
return - V_172 ;
* ( ( unsigned int * ) V_182 -> V_184 ) = V_124 -> type ;
return 0 ;
}
static int F_102 ( char * V_185 , const struct V_181 * V_182 )
{
int type = * ( ( unsigned int * ) V_182 -> V_184 ) ;
return sprintf ( V_185 , L_31 , F_50 ( type ) -> V_41 ) ;
}
static int T_5 F_103 ( void )
{
int V_186 ;
F_104 () ;
F_105 () ;
F_106 () ;
V_26 = F_107 ( L_32 ) ;
if ( ! V_26 ) {
F_12 ( V_187 L_33 ) ;
return - V_141 ;
}
V_186 = F_108 ( & V_179 ) ;
if ( V_186 )
F_109 ( V_26 ) ;
return V_186 ;
}
static void T_6 F_110 ( void )
{
F_111 ( & V_179 ) ;
F_109 ( V_26 ) ;
}
