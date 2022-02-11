inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 . V_5 ;
}
static int F_2 ( struct V_1 * V_2 )
{
if ( ! strcasecmp ( L_1 , V_2 -> type ) )
return V_6 ;
if ( ! strcasecmp ( L_2 , V_2 -> type ) )
return V_7 ;
if ( ! strcasecmp ( L_3 , V_2 -> type ) )
return V_8 ;
if ( ! strncasecmp ( L_4 , V_2 -> type , 6 ) )
return V_8 ;
if ( ! strcasecmp ( L_5 , V_2 -> type ) )
return V_9 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != 0 )
return 0 ;
if ( V_2 -> V_12 == V_13 ||
V_2 -> V_12 == 0 )
return 0 ;
if ( V_2 -> V_14 == V_2 -> V_12 )
return 1 ;
if ( V_2 -> V_15 == V_2 -> V_12 )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_16 * V_17 ,
enum V_18 V_19 ,
union V_20 * V_21 )
{
int V_22 = 0 ;
struct V_1 * V_2 = F_5 ( V_17 ) ;
if ( F_1 ( V_2 ) ) {
F_6 ( V_2 ) ;
} else if ( V_19 != V_23 )
return - V_24 ;
switch ( V_19 ) {
case V_25 :
if ( V_2 -> V_11 & 0x01 )
V_21 -> V_26 = V_27 ;
else if ( V_2 -> V_11 & 0x02 )
V_21 -> V_26 = V_28 ;
else if ( F_3 ( V_2 ) )
V_21 -> V_26 = V_29 ;
else
V_21 -> V_26 = V_30 ;
break;
case V_23 :
V_21 -> V_26 = F_1 ( V_2 ) ;
break;
case V_31 :
V_21 -> V_26 = F_2 ( V_2 ) ;
break;
case V_32 :
V_21 -> V_26 = V_2 -> V_33 ;
break;
case V_34 :
if ( V_2 -> V_35 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_26 = V_2 -> V_35 * 1000 ;
break;
case V_36 :
if ( V_2 -> V_37 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_26 = V_2 -> V_37 * 1000 ;
break;
case V_38 :
case V_39 :
if ( V_2 -> V_40 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_26 = V_2 -> V_40 * 1000 ;
break;
case V_41 :
case V_42 :
if ( V_2 -> V_15 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_26 = V_2 -> V_15 * 1000 ;
break;
case V_43 :
case V_44 :
if ( V_2 -> V_14 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_26 = V_2 -> V_14 * 1000 ;
break;
case V_45 :
case V_46 :
if ( V_2 -> V_12 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_26 = V_2 -> V_12 * 1000 ;
break;
case V_47 :
V_21 -> V_48 = V_2 -> V_49 ;
break;
case V_50 :
V_21 -> V_48 = V_2 -> V_51 ;
break;
case V_52 :
V_21 -> V_48 = V_2 -> V_53 ;
break;
default:
V_22 = - V_54 ;
}
return V_22 ;
}
inline char * F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_55 == V_56 ) ?
L_6 : L_7 ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_57 * V_58 ,
struct V_59 * V_60 , int V_61 )
{
int V_62 ;
union V_57 * V_63 ;
if ( V_58 -> type != V_64 )
return - V_65 ;
for ( V_62 = 0 ; V_62 < V_61 ; ++ V_62 ) {
if ( V_58 -> V_58 . V_66 <= V_62 )
return - V_65 ;
V_63 = & V_58 -> V_58 . V_67 [ V_62 ] ;
if ( V_60 [ V_62 ] . V_68 ) {
T_1 * V_69 = ( T_1 * ) V_2 + V_60 [ V_62 ] . V_70 ;
if ( V_63 -> type == V_71 ||
V_63 -> type == V_72 )
strncpy ( V_69 , V_63 -> string . V_73 , 32 ) ;
else if ( V_63 -> type == V_74 ) {
strncpy ( V_69 , ( T_1 * ) & V_63 -> integer . V_75 ,
sizeof( V_76 ) ) ;
V_69 [ sizeof( V_76 ) ] = 0 ;
} else
* V_69 = 0 ;
} else {
int * V_77 = ( int * ) ( ( T_1 * ) V_2 + V_60 [ V_62 ] . V_70 ) ;
* V_77 = ( V_63 -> type == V_74 ) ?
V_63 -> integer . V_75 : - 1 ;
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 -> V_3 ) ) {
F_11 ( ( V_78 , V_79 , L_8 ) ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_80 = - V_65 ;
T_2 V_4 = 0 ;
char * V_81 = F_13 ( V_82 , & V_2 -> V_83 ) ?
L_9 : L_10 ;
struct V_84 V_85 = { V_86 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_14 ( & V_2 -> V_87 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_88 , V_81 ,
NULL , & V_85 ) ;
F_16 ( & V_2 -> V_87 ) ;
if ( F_17 ( V_4 ) ) {
F_11 ( ( V_78 , V_4 , L_11 , V_81 ) ) ;
return - V_24 ;
}
if ( F_13 ( V_82 , & V_2 -> V_83 ) )
V_80 = F_8 ( V_2 , V_85 . V_73 ,
V_89 ,
F_18 ( V_89 ) ) ;
else
V_80 = F_8 ( V_2 , V_85 . V_73 ,
V_90 , F_18 ( V_90 ) ) ;
F_19 ( V_85 . V_73 ) ;
if ( F_13 ( V_91 , & V_2 -> V_83 ) )
V_2 -> V_14 = V_2 -> V_15 ;
return V_80 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_80 = 0 ;
T_2 V_4 = 0 ;
struct V_84 V_85 = { V_86 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_92 &&
F_20 ( V_93 , V_2 -> V_92 +
F_21 ( V_94 ) ) )
return 0 ;
F_14 ( & V_2 -> V_87 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_88 , L_12 ,
NULL , & V_85 ) ;
F_16 ( & V_2 -> V_87 ) ;
if ( F_17 ( V_4 ) ) {
F_11 ( ( V_78 , V_4 , L_13 ) ) ;
return - V_24 ;
}
V_80 = F_8 ( V_2 , V_85 . V_73 ,
V_95 , F_18 ( V_95 ) ) ;
V_2 -> V_92 = V_93 ;
F_19 ( V_85 . V_73 ) ;
if ( V_2 -> V_55 == V_56 &&
V_2 -> V_40 != V_13 &&
( V_96 ) ( V_2 -> V_40 ) < 0 ) {
V_2 -> V_40 = abs ( ( V_96 ) V_2 -> V_40 ) ;
F_22 (KERN_WARNING FW_BUG L_14
L_15 ) ;
}
if ( F_13 ( V_91 , & V_2 -> V_83 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
return V_80 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
union V_57 V_97 = { . type = V_74 } ;
struct V_98 V_99 = { 1 , & V_97 } ;
if ( ! F_1 ( V_2 ) ||
! F_13 ( V_100 , & V_2 -> V_83 ) )
return - V_24 ;
V_97 . integer . V_75 = V_2 -> V_101 ;
F_14 ( & V_2 -> V_87 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_88 , L_16 ,
& V_99 , NULL ) ;
F_16 ( & V_2 -> V_87 ) ;
if ( F_17 ( V_4 ) )
return - V_24 ;
F_24 ( ( V_102 , L_17 , V_2 -> V_101 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_4 = V_103 ;
T_3 V_88 = NULL ;
V_4 = F_26 ( V_2 -> V_3 -> V_88 , L_16 , & V_88 ) ;
if ( F_17 ( V_4 ) ) {
F_27 ( V_100 , & V_2 -> V_83 ) ;
return 0 ;
}
F_28 ( V_100 , & V_2 -> V_83 ) ;
if ( ! V_2 -> V_101 )
V_2 -> V_101 = V_2 -> V_104 ;
return F_23 ( V_2 ) ;
}
static T_4 F_29 ( struct V_3 * V_105 ,
struct V_106 * V_107 ,
char * V_108 )
{
struct V_1 * V_2 = F_5 ( F_30 ( V_105 ) ) ;
return sprintf ( V_108 , L_18 , V_2 -> V_101 * 1000 ) ;
}
static T_4 F_31 ( struct V_3 * V_105 ,
struct V_106 * V_107 ,
const char * V_108 , T_5 V_66 )
{
unsigned long V_77 ;
struct V_1 * V_2 = F_5 ( F_30 ( V_105 ) ) ;
if ( sscanf ( V_108 , L_19 , & V_77 ) == 1 )
V_2 -> V_101 = V_77 / 1000 ;
if ( F_1 ( V_2 ) )
F_23 ( V_2 ) ;
return V_66 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_80 ;
if ( V_2 -> V_55 == V_56 ) {
V_2 -> V_109 . V_110 = V_111 ;
V_2 -> V_109 . V_112 =
F_18 ( V_111 ) ;
} else {
V_2 -> V_109 . V_110 = V_113 ;
V_2 -> V_109 . V_112 =
F_18 ( V_113 ) ;
}
V_2 -> V_109 . V_81 = F_33 ( V_2 -> V_3 ) ;
V_2 -> V_109 . type = V_114 ;
V_2 -> V_109 . V_115 = F_4 ;
V_80 = F_34 ( & V_2 -> V_3 -> V_105 , & V_2 -> V_109 ) ;
if ( V_80 )
return V_80 ;
return F_35 ( V_2 -> V_109 . V_105 , & V_116 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_117 ) ;
if ( ! V_2 -> V_109 . V_105 ) {
F_16 ( & V_2 -> V_117 ) ;
return;
}
F_37 ( V_2 -> V_109 . V_105 , & V_116 ) ;
F_38 ( & V_2 -> V_109 ) ;
V_2 -> V_109 . V_105 = NULL ;
F_16 ( & V_2 -> V_117 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_13 ( V_91 , & V_2 -> V_83 ) )
return ;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_40 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_28 ( V_91 , & V_2 -> V_83 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_80 , V_118 = F_1 ( V_2 ) ;
V_80 = F_9 ( V_2 ) ;
if ( V_80 )
return V_80 ;
if ( ! F_1 ( V_2 ) ) {
F_36 ( V_2 ) ;
V_2 -> V_92 = 0 ;
return 0 ;
}
if ( ! V_2 -> V_92 ||
V_118 != F_1 ( V_2 ) ) {
V_80 = F_12 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_25 ( V_2 ) ;
}
if ( ! V_2 -> V_109 . V_105 ) {
V_80 = F_32 ( V_2 ) ;
if ( V_80 )
return V_80 ;
}
V_80 = F_6 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_80 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_55 ;
if ( ! V_2 -> V_109 . V_105 )
return;
V_55 = V_2 -> V_55 ;
F_12 ( V_2 ) ;
if ( V_55 == V_2 -> V_55 )
return;
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_42 ( struct V_119 * V_120 , int V_80 )
{
struct V_1 * V_2 = V_120 -> V_121 ;
if ( V_80 )
goto V_122;
F_43 ( V_120 , L_20 ,
F_1 ( V_2 ) ? L_21 : L_22 ) ;
if ( ! F_1 ( V_2 ) )
goto V_122;
if ( V_2 -> V_15 == V_13 )
F_43 ( V_120 , L_23 ) ;
else
F_43 ( V_120 , L_24 ,
V_2 -> V_15 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_43 ( V_120 , L_25 ) ;
else
F_43 ( V_120 , L_26 ,
V_2 -> V_14 ,
F_7 ( V_2 ) ) ;
F_43 ( V_120 , L_27 ,
( ! V_2 -> V_123 ) ? L_28 : L_29 ) ;
if ( V_2 -> V_35 == V_13 )
F_43 ( V_120 , L_30 ) ;
else
F_43 ( V_120 , L_31 ,
V_2 -> V_35 ) ;
F_43 ( V_120 , L_32 ,
V_2 -> V_104 ,
F_7 ( V_2 ) ) ;
F_43 ( V_120 , L_33 ,
V_2 -> V_124 ,
F_7 ( V_2 ) ) ;
F_43 ( V_120 , L_34 , V_2 -> V_33 ) ;
F_43 ( V_120 , L_35 ,
V_2 -> V_125 ,
F_7 ( V_2 ) ) ;
F_43 ( V_120 , L_36 ,
V_2 -> V_126 ,
F_7 ( V_2 ) ) ;
F_43 ( V_120 , L_37 , V_2 -> V_49 ) ;
F_43 ( V_120 , L_38 , V_2 -> V_53 ) ;
F_43 ( V_120 , L_39 , V_2 -> type ) ;
F_43 ( V_120 , L_40 , V_2 -> V_51 ) ;
V_122:
if ( V_80 )
F_43 ( V_120 , L_41 ) ;
return V_80 ;
}
static int F_44 ( struct V_119 * V_120 , int V_80 )
{
struct V_1 * V_2 = V_120 -> V_121 ;
if ( V_80 )
goto V_122;
F_43 ( V_120 , L_20 ,
F_1 ( V_2 ) ? L_21 : L_22 ) ;
if ( ! F_1 ( V_2 ) )
goto V_122;
F_43 ( V_120 , L_42 ,
( V_2 -> V_11 & 0x04 ) ? L_43 : L_44 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_43 ( V_120 ,
L_45 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_43 ( V_120 , L_46 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_43 ( V_120 , L_47 ) ;
else
F_43 ( V_120 , L_48 ) ;
if ( V_2 -> V_40 == V_13 )
F_43 ( V_120 , L_49 ) ;
else
F_43 ( V_120 , L_50 ,
V_2 -> V_40 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_43 ( V_120 , L_51 ) ;
else
F_43 ( V_120 , L_52 ,
V_2 -> V_12 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_37 == V_13 )
F_43 ( V_120 , L_53 ) ;
else
F_43 ( V_120 , L_54 ,
V_2 -> V_37 ) ;
V_122:
if ( V_80 )
F_43 ( V_120 , L_55 ) ;
return V_80 ;
}
static int F_45 ( struct V_119 * V_120 , int V_80 )
{
struct V_1 * V_2 = V_120 -> V_121 ;
if ( V_80 )
goto V_122;
if ( ! F_1 ( V_2 ) ) {
F_43 ( V_120 , L_56 ) ;
goto V_122;
}
F_43 ( V_120 , L_57 ) ;
if ( ! V_2 -> V_101 )
F_43 ( V_120 , L_58 ) ;
else
F_43 ( V_120 , L_59 , V_2 -> V_101 ,
F_7 ( V_2 ) ) ;
V_122:
if ( V_80 )
F_43 ( V_120 , L_60 ) ;
return V_80 ;
}
static T_4 F_46 ( struct V_127 * V_127 ,
const char T_6 * V_85 ,
T_5 V_66 , T_7 * V_128 )
{
int V_80 = 0 ;
char V_129 [ 12 ] = { '\0' } ;
struct V_119 * V_130 = V_127 -> V_131 ;
struct V_1 * V_2 = V_130 -> V_121 ;
if ( ! V_2 || ( V_66 > sizeof( V_129 ) - 1 ) )
return - V_54 ;
if ( ! F_1 ( V_2 ) ) {
V_80 = - V_24 ;
goto V_122;
}
if ( F_47 ( V_129 , V_85 , V_66 ) ) {
V_80 = - V_65 ;
goto V_122;
}
V_129 [ V_66 ] = '\0' ;
V_2 -> V_101 = F_48 ( V_129 , NULL , 0 ) ;
V_80 = F_23 ( V_2 ) ;
V_122:
if ( ! V_80 )
return V_66 ;
return V_80 ;
}
static int F_49 ( int V_132 , struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_121 ;
int V_80 = F_40 ( V_2 ) ;
return V_133 [ V_132 ] ( V_120 , V_80 ) ;
}
static int F_50 ( struct V_134 * V_3 )
{
struct V_135 * V_136 = NULL ;
int V_62 ;
F_51 (KERN_WARNING PREFIX L_61
L_62 ) ;
if ( ! F_52 ( V_3 ) ) {
F_52 ( V_3 ) = F_53 ( F_33 ( V_3 ) ,
V_137 ) ;
if ( ! F_52 ( V_3 ) )
return - V_24 ;
}
for ( V_62 = 0 ; V_62 < V_138 ; ++ V_62 ) {
V_136 = F_54 ( V_139 [ V_62 ] . V_81 ,
V_139 [ V_62 ] . V_68 ,
F_52 ( V_3 ) ,
& V_139 [ V_62 ] . V_140 ,
F_55 ( V_3 ) ) ;
if ( ! V_136 )
return - V_24 ;
}
return 0 ;
}
static void F_56 ( struct V_134 * V_3 )
{
int V_62 ;
if ( ! F_52 ( V_3 ) )
return;
for ( V_62 = 0 ; V_62 < V_138 ; ++ V_62 )
F_57 ( V_139 [ V_62 ] . V_81 ,
F_52 ( V_3 ) ) ;
F_57 ( F_33 ( V_3 ) , V_137 ) ;
F_52 ( V_3 ) = NULL ;
}
static void F_58 ( struct V_134 * V_3 , T_8 V_141 )
{
struct V_1 * V_2 = F_55 ( V_3 ) ;
struct V_3 * V_142 ;
if ( ! V_2 )
return;
V_142 = V_2 -> V_109 . V_105 ;
if ( V_141 == V_143 )
F_41 ( V_2 ) ;
F_40 ( V_2 ) ;
F_59 ( V_3 , V_141 ,
F_1 ( V_2 ) ) ;
F_60 ( V_3 -> V_144 . V_145 ,
F_61 ( & V_3 -> V_105 ) , V_141 ,
F_1 ( V_2 ) ) ;
if ( V_142 && V_2 -> V_109 . V_105 )
F_62 ( & V_2 -> V_109 ) ;
}
static int F_63 ( struct V_146 * V_147 ,
unsigned long V_68 , void * V_148 )
{
struct V_1 * V_2 = F_64 ( V_147 , struct V_1 ,
V_149 ) ;
switch ( V_68 ) {
case V_150 :
case V_151 :
if ( V_2 -> V_109 . V_105 ) {
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
break;
}
return 0 ;
}
static int F_65 ( struct V_134 * V_3 )
{
int V_80 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_88 ;
if ( ! V_3 )
return - V_54 ;
V_2 = F_66 ( sizeof( struct V_1 ) , V_152 ) ;
if ( ! V_2 )
return - V_153 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_67 ( V_3 ) , V_154 ) ;
strcpy ( F_68 ( V_3 ) , V_155 ) ;
V_3 -> V_156 = V_2 ;
F_69 ( & V_2 -> V_87 ) ;
F_69 ( & V_2 -> V_117 ) ;
if ( F_70 ( F_26 ( V_2 -> V_3 -> V_88 ,
L_9 , & V_88 ) ) )
F_28 ( V_82 , & V_2 -> V_83 ) ;
V_80 = F_40 ( V_2 ) ;
if ( V_80 )
goto V_157;
#ifdef F_71
V_80 = F_50 ( V_3 ) ;
#endif
if ( V_80 ) {
#ifdef F_71
F_56 ( V_3 ) ;
#endif
goto V_157;
}
F_51 (KERN_INFO PREFIX L_63 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_64 : L_65 ) ;
V_2 -> V_149 . V_158 = F_63 ;
F_72 ( & V_2 -> V_149 ) ;
return V_80 ;
V_157:
F_36 ( V_2 ) ;
F_73 ( & V_2 -> V_87 ) ;
F_73 ( & V_2 -> V_117 ) ;
F_19 ( V_2 ) ;
return V_80 ;
}
static int F_74 ( struct V_134 * V_3 , int type )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_55 ( V_3 ) )
return - V_54 ;
V_2 = F_55 ( V_3 ) ;
F_75 ( & V_2 -> V_149 ) ;
#ifdef F_71
F_56 ( V_3 ) ;
#endif
F_36 ( V_2 ) ;
F_73 ( & V_2 -> V_87 ) ;
F_73 ( & V_2 -> V_117 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_134 * V_3 )
{
struct V_1 * V_2 ;
if ( ! V_3 )
return - V_54 ;
V_2 = F_55 ( V_3 ) ;
V_2 -> V_92 = 0 ;
F_40 ( V_2 ) ;
return 0 ;
}
static void T_9 F_77 ( void * V_159 , T_10 V_160 )
{
if ( V_161 )
return;
#ifdef F_71
V_137 = F_78 () ;
if ( ! V_137 )
return;
#endif
if ( F_79 ( & V_162 ) < 0 ) {
#ifdef F_71
F_80 ( V_137 ) ;
#endif
return;
}
return;
}
static int T_9 F_81 ( void )
{
F_82 ( F_77 , NULL ) ;
return 0 ;
}
static void T_11 F_83 ( void )
{
F_84 ( & V_162 ) ;
#ifdef F_71
F_80 ( V_137 ) ;
#endif
}
