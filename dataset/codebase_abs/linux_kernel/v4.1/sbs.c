static inline int F_1 ( int log )
{
int V_1 = 1 ;
while ( log -- )
V_1 *= 10 ;
return V_1 ;
}
static inline int F_2 ( struct V_2 * V_3 )
{
return F_1 ( ( V_3 -> V_4 & 0x0f00 ) >> 8 ) ;
}
static inline int F_3 ( struct V_2 * V_3 )
{
return F_1 ( ( V_3 -> V_4 & 0xf000 ) >> 12 ) ;
}
static inline int F_4 ( struct V_2 * V_3 )
{
return ( V_3 -> V_5 & 0x8000 ) ;
}
static inline int F_5 ( struct V_2 * V_3 )
{
return ( F_4 ( V_3 ) ? 10 : 1 ) *
F_3 ( V_3 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
enum V_8 V_9 ,
union V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_7 ) ;
switch ( V_9 ) {
case V_14 :
V_11 -> V_15 = V_13 -> V_16 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
if ( ! strcasecmp ( L_1 , V_3 -> V_18 ) )
return V_19 ;
if ( ! strcasecmp ( L_2 , V_3 -> V_18 ) )
return V_20 ;
if ( ! strcasecmp ( L_3 , V_3 -> V_18 ) )
return V_21 ;
if ( ! strcasecmp ( L_4 , V_3 -> V_18 ) )
return V_22 ;
return V_23 ;
}
static int F_9 ( struct V_6 * V_7 ,
enum V_8 V_9 ,
union V_10 * V_11 )
{
struct V_2 * V_3 = F_10 ( V_7 ) ;
if ( ( ! V_3 -> V_24 ) && V_9 != V_25 )
return - V_26 ;
F_11 ( V_3 ) ;
switch ( V_9 ) {
case V_27 :
if ( V_3 -> V_28 < 0 )
V_11 -> V_15 = V_29 ;
else if ( V_3 -> V_28 > 0 )
V_11 -> V_15 = V_30 ;
else
V_11 -> V_15 = V_31 ;
break;
case V_25 :
V_11 -> V_15 = V_3 -> V_24 ;
break;
case V_32 :
V_11 -> V_15 = F_8 ( V_3 ) ;
break;
case V_33 :
V_11 -> V_15 = V_3 -> V_34 ;
break;
case V_35 :
V_11 -> V_15 = V_3 -> V_36 *
F_2 ( V_3 ) * 1000 ;
break;
case V_37 :
V_11 -> V_15 = V_3 -> V_38 *
F_2 ( V_3 ) * 1000 ;
break;
case V_39 :
case V_40 :
V_11 -> V_15 = abs ( V_3 -> V_28 ) *
F_3 ( V_3 ) * 1000 ;
V_11 -> V_15 *= ( F_4 ( V_3 ) ) ?
( V_3 -> V_38 *
F_2 ( V_3 ) / 1000 ) : 1 ;
break;
case V_41 :
case V_42 :
V_11 -> V_15 = abs ( V_3 -> V_43 ) *
F_3 ( V_3 ) * 1000 ;
V_11 -> V_15 *= ( F_4 ( V_3 ) ) ?
( V_3 -> V_38 *
F_2 ( V_3 ) / 1000 ) : 1 ;
break;
case V_44 :
V_11 -> V_15 = V_3 -> V_45 ;
break;
case V_46 :
case V_47 :
V_11 -> V_15 = V_3 -> V_48 *
F_5 ( V_3 ) * 1000 ;
break;
case V_49 :
case V_50 :
V_11 -> V_15 = V_3 -> V_51 *
F_5 ( V_3 ) * 1000 ;
break;
case V_52 :
case V_53 :
V_11 -> V_15 = V_3 -> V_54 *
F_5 ( V_3 ) * 1000 ;
break;
case V_55 :
V_11 -> V_15 = V_3 -> V_56 - 2730 ;
break;
case V_57 :
V_11 -> V_58 = V_3 -> V_59 ;
break;
case V_60 :
V_11 -> V_58 = V_3 -> V_61 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
int V_62 = 0 ;
T_1 V_63 ;
V_62 = F_13 ( V_13 -> V_64 , V_65 , V_66 ,
0x04 , ( V_67 * ) & V_63 ) ;
if ( ! V_62 )
V_13 -> V_68 = V_63 & 0x000f ;
return V_62 ;
}
static int F_14 ( struct V_2 * V_3 )
{
int V_69 , V_62 = 0 ;
for ( V_69 = 0 ; V_69 < F_15 ( V_70 ) ; ++ V_69 ) {
V_62 = F_13 ( V_3 -> V_13 -> V_64 ,
V_70 [ V_69 ] . V_5 ,
V_71 ,
V_70 [ V_69 ] . V_72 ,
( V_67 * ) V_3 +
V_70 [ V_69 ] . V_73 ) ;
if ( V_62 )
break;
}
return V_62 ;
}
static int F_11 ( struct V_2 * V_3 )
{
int V_69 , V_62 = 0 ;
if ( V_3 -> V_74 &&
F_16 ( V_75 , V_3 -> V_74 +
F_17 ( V_76 ) ) )
return 0 ;
for ( V_69 = 0 ; V_69 < F_15 ( V_77 ) ; ++ V_69 ) {
V_62 = F_13 ( V_3 -> V_13 -> V_64 ,
V_77 [ V_69 ] . V_5 ,
V_71 ,
V_77 [ V_69 ] . V_72 ,
( V_67 * ) V_3 +
V_77 [ V_69 ] . V_73 ) ;
if ( V_62 )
goto V_78;
}
V_78:
V_3 -> V_74 = V_75 ;
return V_62 ;
}
static int F_18 ( struct V_2 * V_3 )
{
return F_13 ( V_3 -> V_13 -> V_64 , V_65 ,
V_71 , 0x01 ,
( V_67 * ) & V_3 -> V_79 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = V_3 -> V_13 ;
T_1 V_80 , V_81 = 1 << ( V_3 -> V_82 + 12 ) ;
int V_83 ;
if ( V_13 -> V_84 ) {
V_83 = F_13 ( V_13 -> V_64 , V_65 , V_66 ,
0x01 , ( V_67 * ) & V_80 ) ;
if ( V_83 )
goto V_78;
if ( ( V_80 & 0xf000 ) != V_81 ) {
V_80 &= 0x0fff ;
V_80 |= V_81 ;
V_83 = F_20 ( V_13 -> V_64 , V_85 ,
V_66 ,
0x01 , ( V_67 * ) & V_80 , 2 ) ;
if ( V_83 )
goto V_78;
}
}
V_83 = F_20 ( V_13 -> V_64 , V_85 , V_71 ,
0x01 , ( V_67 * ) & V_3 -> V_79 , 2 ) ;
V_78:
return V_83 ;
}
static int F_21 ( struct V_12 * V_13 )
{
int V_62 ;
T_1 V_86 ;
V_62 = F_13 ( V_13 -> V_64 , V_65 , V_87 ,
0x13 , ( V_67 * ) & V_86 ) ;
if ( V_62 )
return V_62 ;
if ( ! ( ( V_86 >> 4 ) & 0x1 ) )
return - V_26 ;
V_13 -> V_16 = ( V_86 >> 15 ) & 0x1 ;
return 0 ;
}
static T_2 F_22 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
char * V_92 )
{
struct V_2 * V_3 = F_10 ( F_23 ( V_89 ) ) ;
F_18 ( V_3 ) ;
return sprintf ( V_92 , L_5 , V_3 -> V_79 *
F_5 ( V_3 ) * 1000 ) ;
}
static T_2 F_24 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
const char * V_92 , T_3 V_93 )
{
unsigned long V_94 ;
struct V_2 * V_3 = F_10 ( F_23 ( V_89 ) ) ;
if ( sscanf ( V_92 , L_6 , & V_94 ) == 1 )
V_3 -> V_79 = V_94 /
( 1000 * F_5 ( V_3 ) ) ;
if ( V_3 -> V_24 )
F_19 ( V_3 ) ;
return V_93 ;
}
static int F_25 ( struct V_2 * V_3 )
{
int V_62 = 0 , V_95 = V_3 -> V_24 ;
T_1 V_96 ;
if ( V_3 -> V_13 -> V_84 ) {
V_62 = F_13 ( V_3 -> V_13 -> V_64 , V_65 ,
V_66 , 0x01 , ( V_67 * ) & V_96 ) ;
if ( ! V_62 )
V_3 -> V_24 = V_96 & ( 1 << V_3 -> V_82 ) ;
V_96 &= 0x0fff ;
V_96 |= 1 << ( V_3 -> V_82 + 12 ) ;
F_20 ( V_3 -> V_13 -> V_64 , V_85 ,
V_66 , 0x01 , ( V_67 * ) & V_96 , 2 ) ;
} else if ( V_3 -> V_82 == 0 )
V_3 -> V_24 = 1 ;
if ( V_62 || ! V_3 -> V_24 )
return V_62 ;
if ( V_95 != V_3 -> V_24 ) {
V_3 -> V_74 = 0 ;
V_62 = F_14 ( V_3 ) ;
if ( V_62 ) {
V_3 -> V_24 = 0 ;
return V_62 ;
}
}
V_62 = F_11 ( V_3 ) ;
if ( V_62 )
V_3 -> V_24 = 0 ;
return V_62 ;
}
static int F_26 ( struct V_12 * V_13 , int V_82 )
{
struct V_2 * V_3 = & V_13 -> V_3 [ V_82 ] ;
struct V_97 V_98 = { . V_99 = V_3 , } ;
int V_62 ;
V_3 -> V_82 = V_82 ;
V_3 -> V_13 = V_13 ;
V_62 = F_25 ( V_3 ) ;
if ( V_62 )
return V_62 ;
sprintf ( V_3 -> V_100 , V_101 , V_82 ) ;
V_3 -> V_102 . V_100 = V_3 -> V_100 ;
V_3 -> V_102 . type = V_103 ;
if ( ! F_4 ( V_3 ) ) {
V_3 -> V_102 . V_104 = V_105 ;
V_3 -> V_102 . V_106 =
F_15 ( V_105 ) ;
} else {
V_3 -> V_102 . V_104 = V_107 ;
V_3 -> V_102 . V_106 =
F_15 ( V_107 ) ;
}
V_3 -> V_102 . V_108 = F_9 ;
V_3 -> V_109 = F_27 ( & V_13 -> V_88 -> V_89 ,
& V_3 -> V_102 , & V_98 ) ;
if ( F_28 ( V_3 -> V_109 ) ) {
V_62 = F_29 ( V_3 -> V_109 ) ;
V_3 -> V_109 = NULL ;
goto V_78;
}
V_62 = F_30 ( & V_3 -> V_109 -> V_89 , & V_110 ) ;
if ( V_62 )
goto V_78;
V_3 -> V_111 = 1 ;
V_78:
F_31 (KERN_INFO PREFIX L_7 ,
ACPI_SBS_DEVICE_NAME, acpi_device_bid(sbs->device),
battery->name, battery->present ? L_8 : L_9 ) ;
return V_62 ;
}
static void F_32 ( struct V_12 * V_13 , int V_82 )
{
struct V_2 * V_3 = & V_13 -> V_3 [ V_82 ] ;
if ( V_3 -> V_109 ) {
if ( V_3 -> V_111 )
F_33 ( & V_3 -> V_109 -> V_89 , & V_110 ) ;
F_34 ( V_3 -> V_109 ) ;
}
}
static int F_35 ( struct V_12 * V_13 )
{
int V_62 ;
struct V_97 V_98 = { . V_99 = V_13 , } ;
V_62 = F_21 ( V_13 ) ;
if ( V_62 )
goto V_78;
V_13 -> V_112 = 1 ;
V_13 -> V_113 = F_27 ( & V_13 -> V_88 -> V_89 ,
& V_114 , & V_98 ) ;
if ( F_28 ( V_13 -> V_113 ) ) {
V_62 = F_29 ( V_13 -> V_113 ) ;
V_13 -> V_113 = NULL ;
}
F_31 (KERN_INFO PREFIX L_10 ,
ACPI_SBS_DEVICE_NAME, acpi_device_bid(sbs->device),
ACPI_AC_DIR_NAME, sbs->charger_present ? L_11 : L_12 ) ;
V_78:
return V_62 ;
}
static void F_36 ( struct V_12 * V_13 )
{
if ( V_13 -> V_113 )
F_34 ( V_13 -> V_113 ) ;
}
static void F_37 ( void * V_115 )
{
int V_82 ;
struct V_12 * V_13 = V_115 ;
struct V_2 * V_109 ;
V_67 V_116 = V_13 -> V_16 ;
V_67 V_117 ;
if ( V_13 -> V_112 ) {
F_21 ( V_13 ) ;
if ( V_13 -> V_16 != V_116 )
F_38 ( & V_13 -> V_113 -> V_89 . V_118 , V_119 ) ;
}
if ( V_13 -> V_84 ) {
for ( V_82 = 0 ; V_82 < V_120 ; ++ V_82 ) {
if ( ! ( V_13 -> V_68 & ( 1 << V_82 ) ) )
continue;
V_109 = & V_13 -> V_3 [ V_82 ] ;
V_117 = V_109 -> V_24 ;
F_25 ( V_109 ) ;
if ( V_117 == V_109 -> V_24 )
continue;
F_38 ( & V_109 -> V_109 -> V_89 . V_118 , V_119 ) ;
}
}
}
static int F_39 ( const struct V_121 * V_122 )
{
V_123 = true ;
return 0 ;
}
static int F_40 ( struct V_124 * V_88 )
{
struct V_12 * V_13 ;
int V_62 = 0 ;
int V_82 ;
F_41 ( V_125 ) ;
V_13 = F_42 ( sizeof( struct V_12 ) , V_126 ) ;
if ( ! V_13 ) {
V_62 = - V_127 ;
goto V_78;
}
F_43 ( & V_13 -> V_128 ) ;
V_13 -> V_64 = F_44 ( V_88 -> V_129 ) ;
V_13 -> V_88 = V_88 ;
strcpy ( F_45 ( V_88 ) , V_130 ) ;
strcpy ( F_46 ( V_88 ) , V_131 ) ;
V_88 -> V_132 = V_13 ;
V_62 = F_35 ( V_13 ) ;
if ( V_62 && V_62 != - V_26 )
goto V_78;
V_62 = 0 ;
if ( ! V_123 ) {
V_62 = F_12 ( V_13 ) ;
if ( ! V_62 ) {
V_13 -> V_84 = 1 ;
for ( V_82 = 0 ; V_82 < V_120 ; ++ V_82 )
if ( ( V_13 -> V_68 & ( 1 << V_82 ) ) )
F_26 ( V_13 , V_82 ) ;
}
}
if ( ! V_13 -> V_84 )
F_26 ( V_13 , 0 ) ;
F_47 ( V_13 -> V_64 , F_37 , V_13 ) ;
V_78:
if ( V_62 )
F_48 ( V_88 ) ;
return V_62 ;
}
static int F_48 ( struct V_124 * V_88 )
{
struct V_12 * V_13 ;
int V_82 ;
if ( ! V_88 )
return - V_17 ;
V_13 = F_44 ( V_88 ) ;
if ( ! V_13 )
return - V_17 ;
F_49 ( & V_13 -> V_128 ) ;
F_50 ( V_13 -> V_64 ) ;
for ( V_82 = 0 ; V_82 < V_120 ; ++ V_82 )
F_32 ( V_13 , V_82 ) ;
F_36 ( V_13 ) ;
F_51 ( & V_13 -> V_128 ) ;
F_52 ( & V_13 -> V_128 ) ;
F_53 ( V_13 ) ;
return 0 ;
}
static int F_54 ( struct V_88 * V_89 )
{
struct V_12 * V_13 ;
if ( ! V_89 )
return - V_17 ;
V_13 = F_55 ( V_89 ) -> V_132 ;
F_37 ( V_13 ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
int V_62 = 0 ;
if ( V_133 )
return - V_26 ;
V_62 = F_57 ( & V_134 ) ;
if ( V_62 < 0 )
return - V_26 ;
return 0 ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_134 ) ;
return;
}
