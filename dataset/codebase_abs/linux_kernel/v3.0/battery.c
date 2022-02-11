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
return ( V_2 -> V_55 ) ? L_6 : L_7 ;
}
static int F_8 ( struct V_1 * V_2 ,
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
static int F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 -> V_3 ) ) {
F_11 ( ( V_77 , V_78 , L_8 ) ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_79 = - V_64 ;
T_2 V_4 = 0 ;
char * V_80 = F_13 ( V_81 , & V_2 -> V_82 ) ?
L_9 : L_10 ;
struct V_83 V_84 = { V_85 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_14 ( & V_2 -> V_86 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_87 , V_80 ,
NULL , & V_84 ) ;
F_16 ( & V_2 -> V_86 ) ;
if ( F_17 ( V_4 ) ) {
F_11 ( ( V_77 , V_4 , L_11 , V_80 ) ) ;
return - V_24 ;
}
if ( F_13 ( V_81 , & V_2 -> V_82 ) )
V_79 = F_8 ( V_2 , V_84 . V_72 ,
V_88 ,
F_18 ( V_88 ) ) ;
else
V_79 = F_8 ( V_2 , V_84 . V_72 ,
V_89 , F_18 ( V_89 ) ) ;
F_19 ( V_84 . V_72 ) ;
if ( F_13 ( V_90 , & V_2 -> V_82 ) )
V_2 -> V_14 = V_2 -> V_15 ;
return V_79 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_79 = 0 ;
T_2 V_4 = 0 ;
struct V_83 V_84 = { V_85 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_91 &&
F_20 ( V_92 , V_2 -> V_91 +
F_21 ( V_93 ) ) )
return 0 ;
F_14 ( & V_2 -> V_86 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_87 , L_12 ,
NULL , & V_84 ) ;
F_16 ( & V_2 -> V_86 ) ;
if ( F_17 ( V_4 ) ) {
F_11 ( ( V_77 , V_4 , L_13 ) ) ;
return - V_24 ;
}
V_79 = F_8 ( V_2 , V_84 . V_72 ,
V_94 , F_18 ( V_94 ) ) ;
V_2 -> V_91 = V_92 ;
F_19 ( V_84 . V_72 ) ;
if ( F_13 ( V_95 , & V_2 -> V_82 ) &&
V_2 -> V_40 != - 1 )
V_2 -> V_40 = abs ( ( V_96 ) V_2 -> V_40 ) ;
if ( F_13 ( V_90 , & V_2 -> V_82 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
return V_79 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
union V_56 V_97 = { . type = V_73 } ;
struct V_98 V_99 = { 1 , & V_97 } ;
if ( ! F_1 ( V_2 ) ||
! F_13 ( V_100 , & V_2 -> V_82 ) )
return - V_24 ;
V_97 . integer . V_74 = V_2 -> V_101 ;
F_14 ( & V_2 -> V_86 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_87 , L_14 ,
& V_99 , NULL ) ;
F_16 ( & V_2 -> V_86 ) ;
if ( F_17 ( V_4 ) )
return - V_24 ;
F_23 ( ( V_102 , L_15 , V_2 -> V_101 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_4 = V_103 ;
T_3 V_87 = NULL ;
V_4 = F_25 ( V_2 -> V_3 -> V_87 , L_14 , & V_87 ) ;
if ( F_17 ( V_4 ) ) {
F_26 ( V_100 , & V_2 -> V_82 ) ;
return 0 ;
}
F_27 ( V_100 , & V_2 -> V_82 ) ;
if ( ! V_2 -> V_101 )
V_2 -> V_101 = V_2 -> V_104 ;
return F_22 ( V_2 ) ;
}
static T_4 F_28 ( struct V_3 * V_105 ,
struct V_106 * V_107 ,
char * V_108 )
{
struct V_1 * V_2 = F_5 ( F_29 ( V_105 ) ) ;
return sprintf ( V_108 , L_16 , V_2 -> V_101 * 1000 ) ;
}
static T_4 F_30 ( struct V_3 * V_105 ,
struct V_106 * V_107 ,
const char * V_108 , T_5 V_65 )
{
unsigned long V_76 ;
struct V_1 * V_2 = F_5 ( F_29 ( V_105 ) ) ;
if ( sscanf ( V_108 , L_17 , & V_76 ) == 1 )
V_2 -> V_101 = V_76 / 1000 ;
if ( F_1 ( V_2 ) )
F_22 ( V_2 ) ;
return V_65 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_79 ;
if ( V_2 -> V_55 ) {
V_2 -> V_109 . V_110 = V_111 ;
V_2 -> V_109 . V_112 =
F_18 ( V_111 ) ;
} else {
V_2 -> V_109 . V_110 = V_113 ;
V_2 -> V_109 . V_112 =
F_18 ( V_113 ) ;
}
V_2 -> V_109 . V_80 = F_32 ( V_2 -> V_3 ) ;
V_2 -> V_109 . type = V_114 ;
V_2 -> V_109 . V_115 = F_4 ;
V_79 = F_33 ( & V_2 -> V_3 -> V_105 , & V_2 -> V_109 ) ;
if ( V_79 )
return V_79 ;
return F_34 ( V_2 -> V_109 . V_105 , & V_116 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_109 . V_105 )
return;
F_36 ( V_2 -> V_109 . V_105 , & V_116 ) ;
F_37 ( & V_2 -> V_109 ) ;
V_2 -> V_109 . V_105 = NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( F_39 ( L_18 ) && V_2 -> V_55 ) {
F_27 ( V_95 , & V_2 -> V_82 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
if ( F_13 ( V_90 , & V_2 -> V_82 ) )
return ;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_40 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_27 ( V_90 , & V_2 -> V_82 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_79 , V_117 = F_1 ( V_2 ) ;
V_79 = F_9 ( V_2 ) ;
if ( V_79 )
return V_79 ;
if ( ! F_1 ( V_2 ) ) {
F_35 ( V_2 ) ;
V_2 -> V_91 = 0 ;
return 0 ;
}
if ( ! V_2 -> V_91 ||
V_117 != F_1 ( V_2 ) ) {
V_79 = F_12 ( V_2 ) ;
if ( V_79 )
return V_79 ;
F_38 ( V_2 ) ;
F_24 ( V_2 ) ;
}
if ( ! V_2 -> V_109 . V_105 )
F_31 ( V_2 ) ;
V_79 = F_6 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_79 ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_109 . V_105 )
return;
F_12 ( V_2 ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
}
static int F_43 ( struct V_118 * V_119 , int V_79 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
if ( V_79 )
goto V_121;
F_44 ( V_119 , L_19 ,
F_1 ( V_2 ) ? L_20 : L_21 ) ;
if ( ! F_1 ( V_2 ) )
goto V_121;
if ( V_2 -> V_15 == V_13 )
F_44 ( V_119 , L_22 ) ;
else
F_44 ( V_119 , L_23 ,
V_2 -> V_15 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_44 ( V_119 , L_24 ) ;
else
F_44 ( V_119 , L_25 ,
V_2 -> V_14 ,
F_7 ( V_2 ) ) ;
F_44 ( V_119 , L_26 ,
( ! V_2 -> V_122 ) ? L_27 : L_28 ) ;
if ( V_2 -> V_35 == V_13 )
F_44 ( V_119 , L_29 ) ;
else
F_44 ( V_119 , L_30 ,
V_2 -> V_35 ) ;
F_44 ( V_119 , L_31 ,
V_2 -> V_104 ,
F_7 ( V_2 ) ) ;
F_44 ( V_119 , L_32 ,
V_2 -> V_123 ,
F_7 ( V_2 ) ) ;
F_44 ( V_119 , L_33 , V_2 -> V_33 ) ;
F_44 ( V_119 , L_34 ,
V_2 -> V_124 ,
F_7 ( V_2 ) ) ;
F_44 ( V_119 , L_35 ,
V_2 -> V_125 ,
F_7 ( V_2 ) ) ;
F_44 ( V_119 , L_36 , V_2 -> V_49 ) ;
F_44 ( V_119 , L_37 , V_2 -> V_53 ) ;
F_44 ( V_119 , L_38 , V_2 -> type ) ;
F_44 ( V_119 , L_39 , V_2 -> V_51 ) ;
V_121:
if ( V_79 )
F_44 ( V_119 , L_40 ) ;
return V_79 ;
}
static int F_45 ( struct V_118 * V_119 , int V_79 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
if ( V_79 )
goto V_121;
F_44 ( V_119 , L_19 ,
F_1 ( V_2 ) ? L_20 : L_21 ) ;
if ( ! F_1 ( V_2 ) )
goto V_121;
F_44 ( V_119 , L_41 ,
( V_2 -> V_11 & 0x04 ) ? L_42 : L_43 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_44 ( V_119 ,
L_44 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_44 ( V_119 , L_45 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_44 ( V_119 , L_46 ) ;
else
F_44 ( V_119 , L_47 ) ;
if ( V_2 -> V_40 == V_13 )
F_44 ( V_119 , L_48 ) ;
else
F_44 ( V_119 , L_49 ,
V_2 -> V_40 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_44 ( V_119 , L_50 ) ;
else
F_44 ( V_119 , L_51 ,
V_2 -> V_12 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_37 == V_13 )
F_44 ( V_119 , L_52 ) ;
else
F_44 ( V_119 , L_53 ,
V_2 -> V_37 ) ;
V_121:
if ( V_79 )
F_44 ( V_119 , L_54 ) ;
return V_79 ;
}
static int F_46 ( struct V_118 * V_119 , int V_79 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
if ( V_79 )
goto V_121;
if ( ! F_1 ( V_2 ) ) {
F_44 ( V_119 , L_55 ) ;
goto V_121;
}
F_44 ( V_119 , L_56 ) ;
if ( ! V_2 -> V_101 )
F_44 ( V_119 , L_57 ) ;
else
F_44 ( V_119 , L_58 , V_2 -> V_101 ,
F_7 ( V_2 ) ) ;
V_121:
if ( V_79 )
F_44 ( V_119 , L_59 ) ;
return V_79 ;
}
static T_4 F_47 ( struct V_126 * V_126 ,
const char T_6 * V_84 ,
T_5 V_65 , T_7 * V_127 )
{
int V_79 = 0 ;
char V_128 [ 12 ] = { '\0' } ;
struct V_118 * V_129 = V_126 -> V_130 ;
struct V_1 * V_2 = V_129 -> V_120 ;
if ( ! V_2 || ( V_65 > sizeof( V_128 ) - 1 ) )
return - V_54 ;
if ( ! F_1 ( V_2 ) ) {
V_79 = - V_24 ;
goto V_121;
}
if ( F_48 ( V_128 , V_84 , V_65 ) ) {
V_79 = - V_64 ;
goto V_121;
}
V_128 [ V_65 ] = '\0' ;
V_2 -> V_101 = F_49 ( V_128 , NULL , 0 ) ;
V_79 = F_22 ( V_2 ) ;
V_121:
if ( ! V_79 )
return V_65 ;
return V_79 ;
}
static int F_50 ( int V_131 , struct V_118 * V_119 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
int V_79 = F_41 ( V_2 ) ;
return V_132 [ V_131 ] ( V_119 , V_79 ) ;
}
static int F_51 ( struct V_133 * V_3 )
{
struct V_134 * V_135 = NULL ;
int V_61 ;
F_52 (KERN_WARNING PREFIX L_60
L_61 ) ;
if ( ! F_53 ( V_3 ) ) {
F_53 ( V_3 ) = F_54 ( F_32 ( V_3 ) ,
V_136 ) ;
if ( ! F_53 ( V_3 ) )
return - V_24 ;
}
for ( V_61 = 0 ; V_61 < V_137 ; ++ V_61 ) {
V_135 = F_55 ( V_138 [ V_61 ] . V_80 ,
V_138 [ V_61 ] . V_67 ,
F_53 ( V_3 ) ,
& V_138 [ V_61 ] . V_139 ,
F_56 ( V_3 ) ) ;
if ( ! V_135 )
return - V_24 ;
}
return 0 ;
}
static void F_57 ( struct V_133 * V_3 )
{
int V_61 ;
if ( ! F_53 ( V_3 ) )
return;
for ( V_61 = 0 ; V_61 < V_137 ; ++ V_61 )
F_58 ( V_138 [ V_61 ] . V_80 ,
F_53 ( V_3 ) ) ;
F_58 ( F_32 ( V_3 ) , V_136 ) ;
F_53 ( V_3 ) = NULL ;
}
static void F_59 ( struct V_133 * V_3 , T_8 V_140 )
{
struct V_1 * V_2 = F_56 ( V_3 ) ;
struct V_3 * V_141 ;
if ( ! V_2 )
return;
V_141 = V_2 -> V_109 . V_105 ;
if ( V_140 == V_142 )
F_42 ( V_2 ) ;
F_41 ( V_2 ) ;
F_60 ( V_3 , V_140 ,
F_1 ( V_2 ) ) ;
F_61 ( V_3 -> V_143 . V_144 ,
F_62 ( & V_3 -> V_105 ) , V_140 ,
F_1 ( V_2 ) ) ;
if ( V_141 && V_2 -> V_109 . V_105 )
F_63 ( & V_2 -> V_109 ) ;
}
static int F_64 ( struct V_145 * V_146 ,
unsigned long V_67 , void * V_147 )
{
struct V_1 * V_2 = F_65 ( V_146 , struct V_1 ,
V_148 ) ;
switch ( V_67 ) {
case V_149 :
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_66 ( struct V_133 * V_3 )
{
int V_79 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_87 ;
if ( ! V_3 )
return - V_54 ;
V_2 = F_67 ( sizeof( struct V_1 ) , V_150 ) ;
if ( ! V_2 )
return - V_151 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_68 ( V_3 ) , V_152 ) ;
strcpy ( F_69 ( V_3 ) , V_153 ) ;
V_3 -> V_154 = V_2 ;
F_70 ( & V_2 -> V_86 ) ;
if ( F_71 ( F_25 ( V_2 -> V_3 -> V_87 ,
L_9 , & V_87 ) ) )
F_27 ( V_81 , & V_2 -> V_82 ) ;
F_41 ( V_2 ) ;
#ifdef F_72
V_79 = F_51 ( V_3 ) ;
#endif
if ( ! V_79 ) {
F_52 (KERN_INFO PREFIX L_62 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_63 : L_64 ) ;
} else {
#ifdef F_72
F_57 ( V_3 ) ;
#endif
F_19 ( V_2 ) ;
}
V_2 -> V_148 . V_155 = F_64 ;
F_73 ( & V_2 -> V_148 ) ;
return V_79 ;
}
static int F_74 ( struct V_133 * V_3 , int type )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_56 ( V_3 ) )
return - V_54 ;
V_2 = F_56 ( V_3 ) ;
F_75 ( & V_2 -> V_148 ) ;
#ifdef F_72
F_57 ( V_3 ) ;
#endif
F_35 ( V_2 ) ;
F_76 ( & V_2 -> V_86 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_133 * V_3 )
{
struct V_1 * V_2 ;
if ( ! V_3 )
return - V_54 ;
V_2 = F_56 ( V_3 ) ;
V_2 -> V_91 = 0 ;
F_41 ( V_2 ) ;
return 0 ;
}
static void T_9 F_78 ( void * V_156 , T_10 V_157 )
{
if ( V_158 )
return;
#ifdef F_72
V_136 = F_79 () ;
if ( ! V_136 )
return;
#endif
if ( F_80 ( & V_159 ) < 0 ) {
#ifdef F_72
F_81 ( V_136 ) ;
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
F_85 ( & V_159 ) ;
#ifdef F_72
F_81 ( V_136 ) ;
#endif
}
