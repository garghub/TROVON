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
if ( V_2 -> V_12 && V_2 -> V_14 )
V_21 -> V_26 = V_2 -> V_12 * 100 /
V_2 -> V_14 ;
else
V_21 -> V_26 = 0 ;
break;
case V_48 :
V_21 -> V_49 = V_2 -> V_50 ;
break;
case V_51 :
V_21 -> V_49 = V_2 -> V_52 ;
break;
case V_53 :
V_21 -> V_49 = V_2 -> V_54 ;
break;
default:
V_22 = - V_55 ;
}
return V_22 ;
}
inline char * F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_56 == V_57 ) ?
L_6 : L_7 ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_58 * V_59 ,
struct V_60 * V_61 , int V_62 )
{
int V_63 ;
union V_58 * V_64 ;
if ( V_59 -> type != V_65 )
return - V_66 ;
for ( V_63 = 0 ; V_63 < V_62 ; ++ V_63 ) {
if ( V_59 -> V_59 . V_67 <= V_63 )
return - V_66 ;
V_64 = & V_59 -> V_59 . V_68 [ V_63 ] ;
if ( V_61 [ V_63 ] . V_69 ) {
T_1 * V_70 = ( T_1 * ) V_2 + V_61 [ V_63 ] . V_71 ;
if ( V_64 -> type == V_72 ||
V_64 -> type == V_73 )
strncpy ( V_70 , V_64 -> string . V_74 , 32 ) ;
else if ( V_64 -> type == V_75 ) {
strncpy ( V_70 , ( T_1 * ) & V_64 -> integer . V_76 ,
sizeof( V_77 ) ) ;
V_70 [ sizeof( V_77 ) ] = 0 ;
} else
* V_70 = 0 ;
} else {
int * V_78 = ( int * ) ( ( T_1 * ) V_2 + V_61 [ V_63 ] . V_71 ) ;
* V_78 = ( V_64 -> type == V_75 ) ?
V_64 -> integer . V_76 : - 1 ;
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 -> V_3 ) ) {
F_11 ( ( V_79 , V_80 , L_8 ) ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_81 = - V_66 ;
T_2 V_4 = 0 ;
char * V_82 = F_13 ( V_83 , & V_2 -> V_84 ) ?
L_9 : L_10 ;
struct V_85 V_86 = { V_87 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_14 ( & V_2 -> V_88 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_89 , V_82 ,
NULL , & V_86 ) ;
F_16 ( & V_2 -> V_88 ) ;
if ( F_17 ( V_4 ) ) {
F_11 ( ( V_79 , V_4 , L_11 , V_82 ) ) ;
return - V_24 ;
}
if ( F_13 ( V_83 , & V_2 -> V_84 ) )
V_81 = F_8 ( V_2 , V_86 . V_74 ,
V_90 ,
F_18 ( V_90 ) ) ;
else
V_81 = F_8 ( V_2 , V_86 . V_74 ,
V_91 , F_18 ( V_91 ) ) ;
F_19 ( V_86 . V_74 ) ;
if ( F_13 ( V_92 , & V_2 -> V_84 ) )
V_2 -> V_14 = V_2 -> V_15 ;
return V_81 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
T_2 V_4 = 0 ;
struct V_85 V_86 = { V_87 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_93 &&
F_20 ( V_94 , V_2 -> V_93 +
F_21 ( V_95 ) ) )
return 0 ;
F_14 ( & V_2 -> V_88 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_89 , L_12 ,
NULL , & V_86 ) ;
F_16 ( & V_2 -> V_88 ) ;
if ( F_17 ( V_4 ) ) {
F_11 ( ( V_79 , V_4 , L_13 ) ) ;
return - V_24 ;
}
V_81 = F_8 ( V_2 , V_86 . V_74 ,
V_96 , F_18 ( V_96 ) ) ;
V_2 -> V_93 = V_94 ;
F_19 ( V_86 . V_74 ) ;
if ( V_2 -> V_56 == V_57 &&
V_2 -> V_40 != V_13 &&
( V_97 ) ( V_2 -> V_40 ) < 0 ) {
V_2 -> V_40 = abs ( ( V_97 ) V_2 -> V_40 ) ;
F_22 (KERN_WARNING FW_BUG L_14
L_15 ) ;
}
if ( F_13 ( V_92 , & V_2 -> V_84 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
return V_81 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
union V_58 V_98 = { . type = V_75 } ;
struct V_99 V_100 = { 1 , & V_98 } ;
if ( ! F_1 ( V_2 ) ||
! F_13 ( V_101 , & V_2 -> V_84 ) )
return - V_24 ;
V_98 . integer . V_76 = V_2 -> V_102 ;
F_14 ( & V_2 -> V_88 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_89 , L_16 ,
& V_100 , NULL ) ;
F_16 ( & V_2 -> V_88 ) ;
if ( F_17 ( V_4 ) )
return - V_24 ;
F_24 ( ( V_103 , L_17 , V_2 -> V_102 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_4 = V_104 ;
T_3 V_89 = NULL ;
V_4 = F_26 ( V_2 -> V_3 -> V_89 , L_16 , & V_89 ) ;
if ( F_17 ( V_4 ) ) {
F_27 ( V_101 , & V_2 -> V_84 ) ;
return 0 ;
}
F_28 ( V_101 , & V_2 -> V_84 ) ;
if ( ! V_2 -> V_102 )
V_2 -> V_102 = V_2 -> V_105 ;
return F_23 ( V_2 ) ;
}
static T_4 F_29 ( struct V_3 * V_106 ,
struct V_107 * V_108 ,
char * V_109 )
{
struct V_1 * V_2 = F_5 ( F_30 ( V_106 ) ) ;
return sprintf ( V_109 , L_18 , V_2 -> V_102 * 1000 ) ;
}
static T_4 F_31 ( struct V_3 * V_106 ,
struct V_107 * V_108 ,
const char * V_109 , T_5 V_67 )
{
unsigned long V_78 ;
struct V_1 * V_2 = F_5 ( F_30 ( V_106 ) ) ;
if ( sscanf ( V_109 , L_19 , & V_78 ) == 1 )
V_2 -> V_102 = V_78 / 1000 ;
if ( F_1 ( V_2 ) )
F_23 ( V_2 ) ;
return V_67 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_81 ;
if ( V_2 -> V_56 == V_57 ) {
V_2 -> V_110 . V_111 = V_112 ;
V_2 -> V_110 . V_113 =
F_18 ( V_112 ) ;
} else {
V_2 -> V_110 . V_111 = V_114 ;
V_2 -> V_110 . V_113 =
F_18 ( V_114 ) ;
}
V_2 -> V_110 . V_82 = F_33 ( V_2 -> V_3 ) ;
V_2 -> V_110 . type = V_115 ;
V_2 -> V_110 . V_116 = F_4 ;
V_81 = F_34 ( & V_2 -> V_3 -> V_106 , & V_2 -> V_110 ) ;
if ( V_81 )
return V_81 ;
return F_35 ( V_2 -> V_110 . V_106 , & V_117 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_118 ) ;
if ( ! V_2 -> V_110 . V_106 ) {
F_16 ( & V_2 -> V_118 ) ;
return;
}
F_37 ( V_2 -> V_110 . V_106 , & V_117 ) ;
F_38 ( & V_2 -> V_110 ) ;
V_2 -> V_110 . V_106 = NULL ;
F_16 ( & V_2 -> V_118 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_13 ( V_92 , & V_2 -> V_84 ) )
return ;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_40 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_28 ( V_92 , & V_2 -> V_84 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_81 , V_119 = F_1 ( V_2 ) ;
V_81 = F_9 ( V_2 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_1 ( V_2 ) ) {
F_36 ( V_2 ) ;
V_2 -> V_93 = 0 ;
return 0 ;
}
if ( ! V_2 -> V_93 ||
V_119 != F_1 ( V_2 ) ) {
V_81 = F_12 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_25 ( V_2 ) ;
}
if ( ! V_2 -> V_110 . V_106 ) {
V_81 = F_32 ( V_2 ) ;
if ( V_81 )
return V_81 ;
}
V_81 = F_6 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_81 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_56 ;
if ( ! V_2 -> V_110 . V_106 )
return;
V_56 = V_2 -> V_56 ;
F_12 ( V_2 ) ;
if ( V_56 == V_2 -> V_56 )
return;
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_42 ( struct V_120 * V_121 , int V_81 )
{
struct V_1 * V_2 = V_121 -> V_122 ;
if ( V_81 )
goto V_123;
F_43 ( V_121 , L_20 ,
F_1 ( V_2 ) ? L_21 : L_22 ) ;
if ( ! F_1 ( V_2 ) )
goto V_123;
if ( V_2 -> V_15 == V_13 )
F_43 ( V_121 , L_23 ) ;
else
F_43 ( V_121 , L_24 ,
V_2 -> V_15 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_43 ( V_121 , L_25 ) ;
else
F_43 ( V_121 , L_26 ,
V_2 -> V_14 ,
F_7 ( V_2 ) ) ;
F_43 ( V_121 , L_27 ,
( ! V_2 -> V_124 ) ? L_28 : L_29 ) ;
if ( V_2 -> V_35 == V_13 )
F_43 ( V_121 , L_30 ) ;
else
F_43 ( V_121 , L_31 ,
V_2 -> V_35 ) ;
F_43 ( V_121 , L_32 ,
V_2 -> V_105 ,
F_7 ( V_2 ) ) ;
F_43 ( V_121 , L_33 ,
V_2 -> V_125 ,
F_7 ( V_2 ) ) ;
F_43 ( V_121 , L_34 , V_2 -> V_33 ) ;
F_43 ( V_121 , L_35 ,
V_2 -> V_126 ,
F_7 ( V_2 ) ) ;
F_43 ( V_121 , L_36 ,
V_2 -> V_127 ,
F_7 ( V_2 ) ) ;
F_43 ( V_121 , L_37 , V_2 -> V_50 ) ;
F_43 ( V_121 , L_38 , V_2 -> V_54 ) ;
F_43 ( V_121 , L_39 , V_2 -> type ) ;
F_43 ( V_121 , L_40 , V_2 -> V_52 ) ;
V_123:
if ( V_81 )
F_43 ( V_121 , L_41 ) ;
return V_81 ;
}
static int F_44 ( struct V_120 * V_121 , int V_81 )
{
struct V_1 * V_2 = V_121 -> V_122 ;
if ( V_81 )
goto V_123;
F_43 ( V_121 , L_20 ,
F_1 ( V_2 ) ? L_21 : L_22 ) ;
if ( ! F_1 ( V_2 ) )
goto V_123;
F_43 ( V_121 , L_42 ,
( V_2 -> V_11 & 0x04 ) ? L_43 : L_44 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_43 ( V_121 ,
L_45 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_43 ( V_121 , L_46 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_43 ( V_121 , L_47 ) ;
else
F_43 ( V_121 , L_48 ) ;
if ( V_2 -> V_40 == V_13 )
F_43 ( V_121 , L_49 ) ;
else
F_43 ( V_121 , L_50 ,
V_2 -> V_40 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_43 ( V_121 , L_51 ) ;
else
F_43 ( V_121 , L_52 ,
V_2 -> V_12 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_37 == V_13 )
F_43 ( V_121 , L_53 ) ;
else
F_43 ( V_121 , L_54 ,
V_2 -> V_37 ) ;
V_123:
if ( V_81 )
F_43 ( V_121 , L_55 ) ;
return V_81 ;
}
static int F_45 ( struct V_120 * V_121 , int V_81 )
{
struct V_1 * V_2 = V_121 -> V_122 ;
if ( V_81 )
goto V_123;
if ( ! F_1 ( V_2 ) ) {
F_43 ( V_121 , L_56 ) ;
goto V_123;
}
F_43 ( V_121 , L_57 ) ;
if ( ! V_2 -> V_102 )
F_43 ( V_121 , L_58 ) ;
else
F_43 ( V_121 , L_59 , V_2 -> V_102 ,
F_7 ( V_2 ) ) ;
V_123:
if ( V_81 )
F_43 ( V_121 , L_60 ) ;
return V_81 ;
}
static T_4 F_46 ( struct V_128 * V_128 ,
const char T_6 * V_86 ,
T_5 V_67 , T_7 * V_129 )
{
int V_81 = 0 ;
char V_130 [ 12 ] = { '\0' } ;
struct V_120 * V_131 = V_128 -> V_132 ;
struct V_1 * V_2 = V_131 -> V_122 ;
if ( ! V_2 || ( V_67 > sizeof( V_130 ) - 1 ) )
return - V_55 ;
if ( ! F_1 ( V_2 ) ) {
V_81 = - V_24 ;
goto V_123;
}
if ( F_47 ( V_130 , V_86 , V_67 ) ) {
V_81 = - V_66 ;
goto V_123;
}
V_130 [ V_67 ] = '\0' ;
V_2 -> V_102 = F_48 ( V_130 , NULL , 0 ) ;
V_81 = F_23 ( V_2 ) ;
V_123:
if ( ! V_81 )
return V_67 ;
return V_81 ;
}
static int F_49 ( int V_133 , struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_122 ;
int V_81 = F_40 ( V_2 ) ;
return V_134 [ V_133 ] ( V_121 , V_81 ) ;
}
static int F_50 ( struct V_135 * V_3 )
{
struct V_136 * V_137 = NULL ;
int V_63 ;
F_51 (KERN_WARNING PREFIX L_61
L_62 ) ;
if ( ! F_52 ( V_3 ) ) {
F_52 ( V_3 ) = F_53 ( F_33 ( V_3 ) ,
V_138 ) ;
if ( ! F_52 ( V_3 ) )
return - V_24 ;
}
for ( V_63 = 0 ; V_63 < V_139 ; ++ V_63 ) {
V_137 = F_54 ( V_140 [ V_63 ] . V_82 ,
V_140 [ V_63 ] . V_69 ,
F_52 ( V_3 ) ,
& V_140 [ V_63 ] . V_141 ,
F_55 ( V_3 ) ) ;
if ( ! V_137 )
return - V_24 ;
}
return 0 ;
}
static void F_56 ( struct V_135 * V_3 )
{
int V_63 ;
if ( ! F_52 ( V_3 ) )
return;
for ( V_63 = 0 ; V_63 < V_139 ; ++ V_63 )
F_57 ( V_140 [ V_63 ] . V_82 ,
F_52 ( V_3 ) ) ;
F_57 ( F_33 ( V_3 ) , V_138 ) ;
F_52 ( V_3 ) = NULL ;
}
static void F_58 ( struct V_135 * V_3 , T_8 V_142 )
{
struct V_1 * V_2 = F_55 ( V_3 ) ;
struct V_3 * V_143 ;
if ( ! V_2 )
return;
V_143 = V_2 -> V_110 . V_106 ;
if ( V_142 == V_144 )
F_41 ( V_2 ) ;
F_40 ( V_2 ) ;
F_59 ( V_3 , V_142 ,
F_1 ( V_2 ) ) ;
F_60 ( V_3 -> V_145 . V_146 ,
F_61 ( & V_3 -> V_106 ) , V_142 ,
F_1 ( V_2 ) ) ;
if ( V_143 && V_2 -> V_110 . V_106 )
F_62 ( & V_2 -> V_110 ) ;
}
static int F_63 ( struct V_147 * V_148 ,
unsigned long V_69 , void * V_149 )
{
struct V_1 * V_2 = F_64 ( V_148 , struct V_1 ,
V_150 ) ;
switch ( V_69 ) {
case V_151 :
case V_152 :
if ( V_2 -> V_110 . V_106 ) {
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
break;
}
return 0 ;
}
static int F_65 ( struct V_135 * V_3 )
{
int V_81 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_89 ;
if ( ! V_3 )
return - V_55 ;
V_2 = F_66 ( sizeof( struct V_1 ) , V_153 ) ;
if ( ! V_2 )
return - V_154 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_67 ( V_3 ) , V_155 ) ;
strcpy ( F_68 ( V_3 ) , V_156 ) ;
V_3 -> V_157 = V_2 ;
F_69 ( & V_2 -> V_88 ) ;
F_69 ( & V_2 -> V_118 ) ;
if ( F_70 ( F_26 ( V_2 -> V_3 -> V_89 ,
L_9 , & V_89 ) ) )
F_28 ( V_83 , & V_2 -> V_84 ) ;
V_81 = F_40 ( V_2 ) ;
if ( V_81 )
goto V_158;
#ifdef F_71
V_81 = F_50 ( V_3 ) ;
#endif
if ( V_81 ) {
#ifdef F_71
F_56 ( V_3 ) ;
#endif
goto V_158;
}
F_51 (KERN_INFO PREFIX L_63 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_64 : L_65 ) ;
V_2 -> V_150 . V_159 = F_63 ;
F_72 ( & V_2 -> V_150 ) ;
return V_81 ;
V_158:
F_36 ( V_2 ) ;
F_73 ( & V_2 -> V_88 ) ;
F_73 ( & V_2 -> V_118 ) ;
F_19 ( V_2 ) ;
return V_81 ;
}
static int F_74 ( struct V_135 * V_3 , int type )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_55 ( V_3 ) )
return - V_55 ;
V_2 = F_55 ( V_3 ) ;
F_75 ( & V_2 -> V_150 ) ;
#ifdef F_71
F_56 ( V_3 ) ;
#endif
F_36 ( V_2 ) ;
F_73 ( & V_2 -> V_88 ) ;
F_73 ( & V_2 -> V_118 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_3 * V_106 )
{
struct V_1 * V_2 ;
if ( ! V_106 )
return - V_55 ;
V_2 = F_55 ( F_77 ( V_106 ) ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_93 = 0 ;
F_40 ( V_2 ) ;
return 0 ;
}
static void T_9 F_78 ( void * V_160 , T_10 V_161 )
{
if ( V_162 )
return;
#ifdef F_71
V_138 = F_79 () ;
if ( ! V_138 )
return;
#endif
if ( F_80 ( & V_163 ) < 0 ) {
#ifdef F_71
F_81 ( V_138 ) ;
#endif
return;
}
return;
}
static int T_9 F_82 ( void )
{
F_83 ( F_78 , NULL ) ;
return 0 ;
}
static void T_11 F_84 ( void )
{
F_85 ( & V_163 ) ;
#ifdef F_71
F_81 ( V_138 ) ;
#endif
}
