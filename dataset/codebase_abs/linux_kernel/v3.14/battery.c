static inline int F_1 ( struct V_1 * V_2 )
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
static int F_7 ( struct V_1 * V_2 ,
union V_56 * V_57 ,
struct V_58 * V_59 , int V_60 )
{
int V_61 ;
union V_56 * V_62 ;
if ( V_57 -> type != V_63 )
return - V_64 ;
for ( V_61 = 0 ; V_61 < V_60 ; ++ V_61 ) {
if ( V_57 -> V_57 . V_65 <= V_61 )
return - V_64 ;
V_62 = & V_57 -> V_57 . V_66 [ V_61 ] ;
if ( V_59 [ V_61 ] . V_67 ) {
T_1 * V_68 = ( T_1 * ) V_2 + V_59 [ V_61 ] . V_69 ;
if ( V_62 -> type == V_70 ||
V_62 -> type == V_71 )
strncpy ( V_68 , V_62 -> string . V_72 , 32 ) ;
else if ( V_62 -> type == V_73 ) {
strncpy ( V_68 , ( T_1 * ) & V_62 -> integer . V_74 ,
sizeof( V_75 ) ) ;
V_68 [ sizeof( V_75 ) ] = 0 ;
} else
* V_68 = 0 ;
} else {
int * V_76 = ( int * ) ( ( T_1 * ) V_2 + V_59 [ V_61 ] . V_69 ) ;
* V_76 = ( V_62 -> type == V_73 ) ?
V_62 -> integer . V_74 : - 1 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 -> V_3 ) ) {
F_10 ( ( V_77 , V_78 , L_6 ) ) ;
return - V_24 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_79 = - V_64 ;
T_2 V_4 = 0 ;
char * V_80 = F_12 ( V_81 , & V_2 -> V_82 ) ?
L_7 : L_8 ;
struct V_83 V_84 = { V_85 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_13 ( & V_2 -> V_86 ) ;
V_4 = F_14 ( V_2 -> V_3 -> V_87 , V_80 ,
NULL , & V_84 ) ;
F_15 ( & V_2 -> V_86 ) ;
if ( F_16 ( V_4 ) ) {
F_10 ( ( V_77 , V_4 , L_9 , V_80 ) ) ;
return - V_24 ;
}
if ( V_88 )
V_79 = F_7 ( V_2 , V_84 . V_72 ,
V_89 + 1 ,
F_17 ( V_89 ) - 1 ) ;
else if ( F_12 ( V_81 , & V_2 -> V_82 ) )
V_79 = F_7 ( V_2 , V_84 . V_72 ,
V_89 ,
F_17 ( V_89 ) ) ;
else
V_79 = F_7 ( V_2 , V_84 . V_72 ,
V_90 , F_17 ( V_90 ) ) ;
F_18 ( V_84 . V_72 ) ;
if ( F_12 ( V_91 , & V_2 -> V_82 ) )
V_2 -> V_14 = V_2 -> V_15 ;
if ( F_12 ( V_92 , & V_2 -> V_82 ) &&
V_2 -> V_93 && V_2 -> V_35 ) {
V_2 -> V_15 = V_2 -> V_15 *
10000 / V_2 -> V_35 ;
V_2 -> V_14 = V_2 -> V_14 *
10000 / V_2 -> V_35 ;
V_2 -> V_94 =
V_2 -> V_94 *
10000 / V_2 -> V_35 ;
}
return V_79 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_79 = 0 ;
T_2 V_4 = 0 ;
struct V_83 V_84 = { V_85 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_95 &&
F_19 ( V_96 , V_2 -> V_95 +
F_20 ( V_97 ) ) )
return 0 ;
F_13 ( & V_2 -> V_86 ) ;
V_4 = F_14 ( V_2 -> V_3 -> V_87 , L_10 ,
NULL , & V_84 ) ;
F_15 ( & V_2 -> V_86 ) ;
if ( F_16 ( V_4 ) ) {
F_10 ( ( V_77 , V_4 , L_11 ) ) ;
return - V_24 ;
}
V_79 = F_7 ( V_2 , V_84 . V_72 ,
V_98 , F_17 ( V_98 ) ) ;
V_2 -> V_95 = V_96 ;
F_18 ( V_84 . V_72 ) ;
if ( V_2 -> V_93 == V_99 &&
V_2 -> V_40 != V_13 &&
( V_100 ) ( V_2 -> V_40 ) < 0 ) {
V_2 -> V_40 = abs ( ( V_100 ) V_2 -> V_40 ) ;
F_21 (KERN_WARNING FW_BUG L_12
L_13 ) ;
}
if ( F_12 ( V_91 , & V_2 -> V_82 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
if ( F_12 ( V_92 , & V_2 -> V_82 ) &&
V_2 -> V_93 && V_2 -> V_35 ) {
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_35 ;
}
return V_79 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
if ( ! F_1 ( V_2 ) ||
! F_12 ( V_101 , & V_2 -> V_82 ) )
return - V_24 ;
F_13 ( & V_2 -> V_86 ) ;
V_4 = F_23 ( V_2 -> V_3 -> V_87 , L_14 ,
V_2 -> V_102 ) ;
F_15 ( & V_2 -> V_86 ) ;
if ( F_16 ( V_4 ) )
return - V_24 ;
F_24 ( ( V_103 , L_15 , V_2 -> V_102 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( ! F_26 ( V_2 -> V_3 -> V_87 , L_14 ) ) {
F_27 ( V_101 , & V_2 -> V_82 ) ;
return 0 ;
}
F_28 ( V_101 , & V_2 -> V_82 ) ;
if ( ! V_2 -> V_102 )
V_2 -> V_102 = V_2 -> V_94 ;
return F_22 ( V_2 ) ;
}
static T_3 F_29 ( struct V_3 * V_104 ,
struct V_105 * V_106 ,
char * V_107 )
{
struct V_1 * V_2 = F_5 ( F_30 ( V_104 ) ) ;
return sprintf ( V_107 , L_16 , V_2 -> V_102 * 1000 ) ;
}
static T_3 F_31 ( struct V_3 * V_104 ,
struct V_105 * V_106 ,
const char * V_107 , T_4 V_65 )
{
unsigned long V_76 ;
struct V_1 * V_2 = F_5 ( F_30 ( V_104 ) ) ;
if ( sscanf ( V_107 , L_17 , & V_76 ) == 1 )
V_2 -> V_102 = V_76 / 1000 ;
if ( F_1 ( V_2 ) )
F_22 ( V_2 ) ;
return V_65 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_79 ;
if ( V_2 -> V_93 == V_99 ) {
V_2 -> V_108 . V_109 = V_110 ;
V_2 -> V_108 . V_111 =
F_17 ( V_110 ) ;
} else {
V_2 -> V_108 . V_109 = V_112 ;
V_2 -> V_108 . V_111 =
F_17 ( V_112 ) ;
}
V_2 -> V_108 . V_80 = F_33 ( V_2 -> V_3 ) ;
V_2 -> V_108 . type = V_113 ;
V_2 -> V_108 . V_114 = F_4 ;
V_79 = F_34 ( & V_2 -> V_3 -> V_104 , & V_2 -> V_108 ) ;
if ( V_79 )
return V_79 ;
return F_35 ( V_2 -> V_108 . V_104 , & V_115 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_116 ) ;
if ( ! V_2 -> V_108 . V_104 ) {
F_15 ( & V_2 -> V_116 ) ;
return;
}
F_37 ( V_2 -> V_108 . V_104 , & V_115 ) ;
F_38 ( & V_2 -> V_108 ) ;
V_2 -> V_108 . V_104 = NULL ;
F_15 ( & V_2 -> V_116 ) ;
}
static void F_39 ( const struct V_117 * V_118 , void * V_119 )
{
struct V_1 * V_2 = (struct V_1 * ) V_119 ;
if ( V_118 -> type == V_120 && V_118 -> V_121 >= 8 ) {
const T_1 * V_122 = ( const T_1 * ) ( V_118 + 1 ) ;
int V_123 = F_40 ( ( const V_124 * ) ( V_122 + 6 ) ) ;
if ( V_118 -> V_121 >= 18 )
V_123 *= V_122 [ 17 ] ;
if ( V_2 -> V_15 * V_2 -> V_35 / 1000
!= V_123 &&
V_2 -> V_15 * 10 == V_123 )
F_28 ( V_92 ,
& V_2 -> V_82 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
if ( F_12 ( V_91 , & V_2 -> V_82 ) )
return;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_40 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_28 ( V_91 , & V_2 -> V_82 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
if ( F_12 ( V_92 , & V_2 -> V_82 ) )
return;
if ( V_2 -> V_93 && F_42 ( L_18 ) ) {
const char * V_125 ;
V_125 = F_43 ( V_126 ) ;
if ( V_125 && ! F_44 ( V_125 , L_19 , 8 ) ) {
F_45 ( F_39 , V_2 ) ;
if ( F_12 ( V_92 ,
& V_2 -> V_82 ) &&
V_2 -> V_35 ) {
V_2 -> V_15 =
V_2 -> V_15 *
10000 / V_2 -> V_35 ;
V_2 -> V_14 =
V_2 -> V_14 *
10000 / V_2 -> V_35 ;
V_2 -> V_94 =
V_2 -> V_94 *
10000 / V_2 -> V_35 ;
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_35 ;
}
}
}
}
static int F_46 ( struct V_1 * V_2 )
{
int V_79 , V_127 = F_1 ( V_2 ) ;
V_79 = F_8 ( V_2 ) ;
if ( V_79 )
return V_79 ;
if ( ! F_1 ( V_2 ) ) {
F_36 ( V_2 ) ;
V_2 -> V_95 = 0 ;
return 0 ;
}
if ( ! V_2 -> V_95 ||
V_127 != F_1 ( V_2 ) ) {
V_79 = F_11 ( V_2 ) ;
if ( V_79 )
return V_79 ;
F_25 ( V_2 ) ;
}
if ( ! V_2 -> V_108 . V_104 ) {
V_79 = F_32 ( V_2 ) ;
if ( V_79 )
return V_79 ;
}
V_79 = F_6 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_79 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_93 ;
if ( ! V_2 -> V_108 . V_104 )
return;
V_93 = V_2 -> V_93 ;
F_11 ( V_2 ) ;
if ( V_93 == V_2 -> V_93 )
return;
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static void F_48 ( struct V_128 * V_3 , T_5 V_129 )
{
struct V_1 * V_2 = F_49 ( V_3 ) ;
struct V_3 * V_130 ;
if ( ! V_2 )
return;
V_130 = V_2 -> V_108 . V_104 ;
if ( V_129 == V_131 )
F_47 ( V_2 ) ;
F_46 ( V_2 ) ;
F_50 ( V_3 -> V_132 . V_133 ,
F_51 ( & V_3 -> V_104 ) , V_129 ,
F_1 ( V_2 ) ) ;
if ( V_130 && V_2 -> V_108 . V_104 )
F_52 ( & V_2 -> V_108 ) ;
}
static int F_53 ( struct V_134 * V_135 ,
unsigned long V_67 , void * V_136 )
{
struct V_1 * V_2 = F_54 ( V_135 , struct V_1 ,
V_137 ) ;
switch ( V_67 ) {
case V_138 :
case V_139 :
if ( V_2 -> V_108 . V_104 ) {
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
break;
}
return 0 ;
}
static int F_55 ( struct V_128 * V_3 )
{
int V_79 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_3 )
return - V_55 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_2 )
return - V_141 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_57 ( V_3 ) , V_142 ) ;
strcpy ( F_58 ( V_3 ) , V_143 ) ;
V_3 -> V_144 = V_2 ;
F_59 ( & V_2 -> V_86 ) ;
F_59 ( & V_2 -> V_116 ) ;
if ( F_26 ( V_2 -> V_3 -> V_87 , L_7 ) )
F_28 ( V_81 , & V_2 -> V_82 ) ;
V_79 = F_46 ( V_2 ) ;
if ( V_79 )
goto V_145;
F_60 (KERN_INFO PREFIX L_20 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_21 : L_22 ) ;
V_2 -> V_137 . V_146 = F_53 ;
F_61 ( & V_2 -> V_137 ) ;
return V_79 ;
V_145:
F_36 ( V_2 ) ;
F_62 ( & V_2 -> V_86 ) ;
F_62 ( & V_2 -> V_116 ) ;
F_18 ( V_2 ) ;
return V_79 ;
}
static int F_63 ( struct V_128 * V_3 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_49 ( V_3 ) )
return - V_55 ;
V_2 = F_49 ( V_3 ) ;
F_64 ( & V_2 -> V_137 ) ;
F_36 ( V_2 ) ;
F_62 ( & V_2 -> V_86 ) ;
F_62 ( & V_2 -> V_116 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_104 )
{
struct V_1 * V_2 ;
if ( ! V_104 )
return - V_55 ;
V_2 = F_49 ( F_66 ( V_104 ) ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_95 = 0 ;
F_46 ( V_2 ) ;
return 0 ;
}
static void T_6 F_67 ( void * V_147 , T_7 V_148 )
{
if ( V_149 )
return;
if ( F_68 ( V_150 ) )
V_88 = 1 ;
F_69 ( & V_151 ) ;
}
static int T_6 F_70 ( void )
{
F_71 ( F_67 , NULL ) ;
return 0 ;
}
static void T_8 F_72 ( void )
{
F_73 ( & V_151 ) ;
}
