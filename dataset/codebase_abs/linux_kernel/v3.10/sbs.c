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
if ( ! V_62 )
V_13 -> V_16 = ( V_86 >> 15 ) & 0x1 ;
return V_62 ;
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
static int
F_25 ( struct V_95 * * V_96 ,
struct V_95 * V_97 ,
char * V_98 ,
const struct V_99 * V_100 ,
const struct V_99 * V_101 ,
const struct V_99 * V_102 , void * V_103 )
{
F_26 (KERN_WARNING PREFIX L_7
L_8 ) ;
if ( ! * V_96 ) {
* V_96 = F_27 ( V_98 , V_97 ) ;
if ( ! * V_96 ) {
return - V_26 ;
}
}
if ( V_100 )
F_28 ( V_104 , V_105 , * V_96 ,
V_100 , V_103 ) ;
if ( V_101 )
F_28 ( V_106 , V_105 , * V_96 ,
V_101 , V_103 ) ;
if ( V_102 )
F_28 ( V_107 , V_105 , * V_96 ,
V_102 , V_103 ) ;
return 0 ;
}
static inline char * F_29 ( struct V_2 * V_3 )
{
return F_4 ( V_3 ) ? L_9 : L_10 ;
}
static int F_30 ( struct V_108 * V_109 , void * V_73 )
{
struct V_2 * V_3 = V_109 -> V_110 ;
struct V_12 * V_13 = V_3 -> V_13 ;
int V_62 = 0 ;
F_31 ( & V_13 -> V_111 ) ;
F_32 ( V_109 , L_11 ,
( V_3 -> V_24 ) ? L_12 : L_13 ) ;
if ( ! V_3 -> V_24 )
goto V_78;
F_32 ( V_109 , L_14 ,
V_3 -> V_48 * F_5 ( V_3 ) ,
F_29 ( V_3 ) ) ;
F_32 ( V_109 , L_15 ,
V_3 -> V_51 * F_5 ( V_3 ) ,
F_29 ( V_3 ) ) ;
F_32 ( V_109 , L_16 ) ;
F_32 ( V_109 , L_17 ,
V_3 -> V_36 * F_2 ( V_3 ) ) ;
F_32 ( V_109 , L_18 ) ;
F_32 ( V_109 , L_19 ) ;
F_32 ( V_109 , L_20 , V_3 -> V_34 ) ;
F_32 ( V_109 , L_21 ) ;
F_32 ( V_109 , L_22 ) ;
F_32 ( V_109 , L_23 , V_3 -> V_59 ) ;
F_32 ( V_109 , L_24 ,
V_3 -> V_112 ) ;
F_32 ( V_109 , L_25 ,
V_3 -> V_18 ) ;
F_32 ( V_109 , L_26 ,
V_3 -> V_61 ) ;
V_78:
F_33 ( & V_13 -> V_111 ) ;
return V_62 ;
}
static int F_34 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_35 ( V_114 , F_30 , F_36 ( V_113 ) ) ;
}
static int F_37 ( struct V_108 * V_109 , void * V_73 )
{
struct V_2 * V_3 = V_109 -> V_110 ;
struct V_12 * V_13 = V_3 -> V_13 ;
int V_115 ;
F_31 ( & V_13 -> V_111 ) ;
F_32 ( V_109 , L_11 ,
( V_3 -> V_24 ) ? L_12 : L_13 ) ;
if ( ! V_3 -> V_24 )
goto V_78;
F_11 ( V_3 ) ;
F_32 ( V_109 , L_27 ,
( V_3 -> V_116 & 0x0010 ) ? L_28 : L_29 ) ;
F_32 ( V_109 , L_30 ,
( V_3 -> V_28 < 0 ) ? L_31 :
( ( V_3 -> V_28 > 0 ) ? L_32 : L_33 ) ) ;
V_115 = abs ( V_3 -> V_28 ) * F_3 ( V_3 ) ;
V_115 *= ( F_4 ( V_3 ) ) ? ( V_3 -> V_38 *
F_2 ( V_3 ) / 1000 ) : 1 ;
F_32 ( V_109 , L_34 , V_115 ,
F_29 ( V_3 ) ) ;
F_32 ( V_109 , L_35 ,
V_3 -> V_54 * F_5 ( V_3 ) ,
F_29 ( V_3 ) ) ;
F_32 ( V_109 , L_36 ,
V_3 -> V_38 * F_2 ( V_3 ) ) ;
V_78:
F_33 ( & V_13 -> V_111 ) ;
return 0 ;
}
static int F_38 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_35 ( V_114 , F_37 , F_36 ( V_113 ) ) ;
}
static int F_39 ( struct V_108 * V_109 , void * V_73 )
{
struct V_2 * V_3 = V_109 -> V_110 ;
struct V_12 * V_13 = V_3 -> V_13 ;
int V_62 = 0 ;
F_31 ( & V_13 -> V_111 ) ;
if ( ! V_3 -> V_24 ) {
F_32 ( V_109 , L_37 ) ;
goto V_78;
}
F_18 ( V_3 ) ;
F_32 ( V_109 , L_38 ) ;
if ( V_3 -> V_79 )
F_32 ( V_109 , L_39 ,
V_3 -> V_79 *
F_5 ( V_3 ) ,
F_29 ( V_3 ) ) ;
else
F_32 ( V_109 , L_40 ) ;
V_78:
F_33 ( & V_13 -> V_111 ) ;
return V_62 ;
}
static T_2
F_40 ( struct V_114 * V_114 , const char T_4 * V_117 ,
T_3 V_93 , T_5 * V_118 )
{
struct V_108 * V_109 = V_114 -> V_119 ;
struct V_2 * V_3 = V_109 -> V_110 ;
struct V_12 * V_13 = V_3 -> V_13 ;
char V_120 [ 12 ] = { '\0' } ;
int V_62 = 0 ;
F_31 ( & V_13 -> V_111 ) ;
if ( ! V_3 -> V_24 ) {
V_62 = - V_26 ;
goto V_78;
}
if ( V_93 > sizeof( V_120 ) - 1 ) {
V_62 = - V_17 ;
goto V_78;
}
if ( F_41 ( V_120 , V_117 , V_93 ) ) {
V_62 = - V_121 ;
goto V_78;
}
V_120 [ V_93 ] = 0 ;
V_3 -> V_79 = F_42 ( V_120 , NULL , 0 ) /
F_5 ( V_3 ) ;
F_19 ( V_3 ) ;
V_78:
F_33 ( & V_13 -> V_111 ) ;
if ( V_62 )
return V_62 ;
return V_93 ;
}
static int F_43 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_35 ( V_114 , F_39 , F_36 ( V_113 ) ) ;
}
static int F_44 ( struct V_108 * V_109 , void * V_73 )
{
struct V_12 * V_13 = V_109 -> V_110 ;
F_31 ( & V_13 -> V_111 ) ;
F_32 ( V_109 , L_41 ,
V_13 -> V_16 ? L_42 : L_43 ) ;
F_33 ( & V_13 -> V_111 ) ;
return 0 ;
}
static int F_45 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_35 ( V_114 , F_44 , F_36 ( V_113 ) ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
int V_62 = 0 , V_122 = V_3 -> V_24 ;
T_1 V_116 ;
if ( V_3 -> V_13 -> V_84 ) {
V_62 = F_13 ( V_3 -> V_13 -> V_64 , V_65 ,
V_66 , 0x01 , ( V_67 * ) & V_116 ) ;
if ( ! V_62 )
V_3 -> V_24 = V_116 & ( 1 << V_3 -> V_82 ) ;
V_116 &= 0x0fff ;
V_116 |= 1 << ( V_3 -> V_82 + 12 ) ;
F_20 ( V_3 -> V_13 -> V_64 , V_85 ,
V_66 , 0x01 , ( V_67 * ) & V_116 , 2 ) ;
} else if ( V_3 -> V_82 == 0 )
V_3 -> V_24 = 1 ;
if ( V_62 || ! V_3 -> V_24 )
return V_62 ;
if ( V_122 != V_3 -> V_24 ) {
V_3 -> V_74 = 0 ;
V_62 = F_14 ( V_3 ) ;
if ( V_62 )
return V_62 ;
}
V_62 = F_11 ( V_3 ) ;
return V_62 ;
}
static int F_47 ( struct V_12 * V_13 , int V_82 )
{
struct V_2 * V_3 = & V_13 -> V_3 [ V_82 ] ;
int V_62 ;
V_3 -> V_82 = V_82 ;
V_3 -> V_13 = V_13 ;
V_62 = F_46 ( V_3 ) ;
if ( V_62 )
return V_62 ;
sprintf ( V_3 -> V_123 , V_124 , V_82 ) ;
#ifdef F_48
F_25 ( & V_3 -> V_125 , V_126 ,
V_3 -> V_123 , & V_127 ,
& V_128 , & V_129 ,
V_3 ) ;
#endif
V_3 -> V_130 . V_123 = V_3 -> V_123 ;
V_3 -> V_130 . type = V_131 ;
if ( ! F_4 ( V_3 ) ) {
V_3 -> V_130 . V_132 = V_133 ;
V_3 -> V_130 . V_134 =
F_15 ( V_133 ) ;
} else {
V_3 -> V_130 . V_132 = V_135 ;
V_3 -> V_130 . V_134 =
F_15 ( V_135 ) ;
}
V_3 -> V_130 . V_136 = F_9 ;
V_62 = F_49 ( & V_13 -> V_88 -> V_89 , & V_3 -> V_130 ) ;
if ( V_62 )
goto V_78;
V_62 = F_50 ( V_3 -> V_130 . V_89 , & V_137 ) ;
if ( V_62 )
goto V_78;
V_3 -> V_138 = 1 ;
V_78:
F_26 (KERN_INFO PREFIX L_44 ,
ACPI_SBS_DEVICE_NAME, acpi_device_bid(sbs->device),
battery->name, battery->present ? L_45 : L_46 ) ;
return V_62 ;
}
static void F_51 ( struct V_12 * V_13 , int V_82 )
{
struct V_2 * V_3 = & V_13 -> V_3 [ V_82 ] ;
if ( V_3 -> V_130 . V_89 ) {
if ( V_3 -> V_138 )
F_52 ( V_3 -> V_130 . V_89 , & V_137 ) ;
F_53 ( & V_3 -> V_130 ) ;
}
#ifdef F_48
F_54 ( V_3 -> V_125 ) ;
V_3 -> V_125 = NULL ;
#endif
}
static int F_55 ( struct V_12 * V_13 )
{
int V_62 ;
V_62 = F_21 ( V_13 ) ;
if ( V_62 )
goto V_78;
#ifdef F_48
V_62 = F_25 ( & V_13 -> V_139 , V_140 ,
V_141 , NULL ,
& V_142 , NULL , V_13 ) ;
if ( V_62 )
goto V_78;
#endif
V_13 -> V_143 . V_123 = L_47 ;
V_13 -> V_143 . type = V_144 ;
V_13 -> V_143 . V_132 = V_145 ;
V_13 -> V_143 . V_134 = F_15 ( V_145 ) ;
V_13 -> V_143 . V_136 = F_6 ;
F_49 ( & V_13 -> V_88 -> V_89 , & V_13 -> V_143 ) ;
F_26 (KERN_INFO PREFIX L_48 ,
ACPI_SBS_DEVICE_NAME, acpi_device_bid(sbs->device),
ACPI_AC_DIR_NAME, sbs->charger_present ? L_42 : L_43 ) ;
V_78:
return V_62 ;
}
static void F_56 ( struct V_12 * V_13 )
{
if ( V_13 -> V_143 . V_89 )
F_53 ( & V_13 -> V_143 ) ;
#ifdef F_48
F_54 ( V_13 -> V_139 ) ;
V_13 -> V_139 = NULL ;
#endif
}
static void F_57 ( void * V_146 )
{
int V_82 ;
struct V_12 * V_13 = V_146 ;
struct V_2 * V_130 ;
V_67 V_147 = V_13 -> V_16 ;
V_67 V_148 ;
F_21 ( V_13 ) ;
if ( V_13 -> V_16 != V_147 ) {
#ifdef F_58
F_59 ( V_149 , V_141 ,
V_150 ,
V_13 -> V_16 ) ;
#endif
F_60 ( & V_13 -> V_143 . V_89 -> V_151 , V_152 ) ;
}
if ( V_13 -> V_84 ) {
for ( V_82 = 0 ; V_82 < V_153 ; ++ V_82 ) {
if ( ! ( V_13 -> V_68 & ( 1 << V_82 ) ) )
continue;
V_130 = & V_13 -> V_3 [ V_82 ] ;
V_148 = V_130 -> V_24 ;
F_46 ( V_130 ) ;
if ( V_148 == V_130 -> V_24 )
continue;
#ifdef F_58
F_59 ( V_154 ,
V_130 -> V_123 ,
V_150 ,
V_130 -> V_24 ) ;
#endif
F_60 ( & V_130 -> V_130 . V_89 -> V_151 , V_152 ) ;
}
}
}
static int F_61 ( struct V_155 * V_88 )
{
struct V_12 * V_13 ;
int V_62 = 0 ;
int V_82 ;
V_13 = F_62 ( sizeof( struct V_12 ) , V_156 ) ;
if ( ! V_13 ) {
V_62 = - V_157 ;
goto V_78;
}
F_63 ( & V_13 -> V_111 ) ;
V_13 -> V_64 = F_64 ( V_88 -> V_158 ) ;
V_13 -> V_88 = V_88 ;
strcpy ( F_65 ( V_88 ) , V_159 ) ;
strcpy ( F_66 ( V_88 ) , V_160 ) ;
V_88 -> V_161 = V_13 ;
V_62 = F_55 ( V_13 ) ;
if ( V_62 )
goto V_78;
V_62 = F_12 ( V_13 ) ;
if ( ! V_62 ) {
V_13 -> V_84 = 1 ;
for ( V_82 = 0 ; V_82 < V_153 ; ++ V_82 )
if ( ( V_13 -> V_68 & ( 1 << V_82 ) ) )
F_47 ( V_13 , V_82 ) ;
} else
F_47 ( V_13 , 0 ) ;
F_67 ( V_13 -> V_64 , F_57 , V_13 ) ;
V_78:
if ( V_62 )
F_68 ( V_88 ) ;
return V_62 ;
}
static int F_68 ( struct V_155 * V_88 )
{
struct V_12 * V_13 ;
int V_82 ;
if ( ! V_88 )
return - V_17 ;
V_13 = F_64 ( V_88 ) ;
if ( ! V_13 )
return - V_17 ;
F_31 ( & V_13 -> V_111 ) ;
F_69 ( V_13 -> V_64 ) ;
for ( V_82 = 0 ; V_82 < V_153 ; ++ V_82 )
F_51 ( V_13 , V_82 ) ;
F_56 ( V_13 ) ;
F_33 ( & V_13 -> V_111 ) ;
F_70 ( & V_13 -> V_111 ) ;
F_71 ( V_13 ) ;
return 0 ;
}
static void F_72 ( void )
{
#ifdef F_48
if ( V_140 ) {
F_73 ( V_140 ) ;
V_140 = NULL ;
}
if ( V_126 ) {
F_74 ( V_126 ) ;
V_126 = NULL ;
}
#endif
}
static int F_75 ( struct V_88 * V_89 )
{
struct V_12 * V_13 ;
if ( ! V_89 )
return - V_17 ;
V_13 = F_76 ( V_89 ) -> V_161 ;
F_57 ( V_13 ) ;
return 0 ;
}
static int T_6 F_77 ( void )
{
int V_62 = 0 ;
if ( V_162 )
return - V_26 ;
#ifdef F_48
V_140 = F_78 () ;
if ( ! V_140 )
return - V_26 ;
V_126 = F_79 () ;
if ( ! V_126 ) {
F_72 () ;
return - V_26 ;
}
#endif
V_62 = F_80 ( & V_163 ) ;
if ( V_62 < 0 ) {
F_72 () ;
return - V_26 ;
}
return 0 ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_163 ) ;
F_72 () ;
return;
}
