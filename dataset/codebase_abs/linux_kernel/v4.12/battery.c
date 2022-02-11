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
if ( V_2 -> V_11 & V_26 )
V_21 -> V_27 = V_28 ;
else if ( V_2 -> V_11 & V_29 )
V_21 -> V_27 = V_30 ;
else if ( F_3 ( V_2 ) )
V_21 -> V_27 = V_31 ;
else
V_21 -> V_27 = V_32 ;
break;
case V_23 :
V_21 -> V_27 = F_1 ( V_2 ) ;
break;
case V_33 :
V_21 -> V_27 = F_2 ( V_2 ) ;
break;
case V_34 :
V_21 -> V_27 = V_2 -> V_35 ;
break;
case V_36 :
if ( V_2 -> V_37 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_27 = V_2 -> V_37 * 1000 ;
break;
case V_38 :
if ( V_2 -> V_39 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_27 = V_2 -> V_39 * 1000 ;
break;
case V_40 :
case V_41 :
if ( V_2 -> V_42 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_27 = V_2 -> V_42 * 1000 ;
break;
case V_43 :
case V_44 :
if ( V_2 -> V_15 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_27 = V_2 -> V_15 * 1000 ;
break;
case V_45 :
case V_46 :
if ( V_2 -> V_14 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_27 = V_2 -> V_14 * 1000 ;
break;
case V_47 :
case V_48 :
if ( V_2 -> V_12 == V_13 )
V_22 = - V_24 ;
else
V_21 -> V_27 = V_2 -> V_12 * 1000 ;
break;
case V_49 :
if ( V_2 -> V_12 && V_2 -> V_14 )
V_21 -> V_27 = V_2 -> V_12 * 100 /
V_2 -> V_14 ;
else
V_21 -> V_27 = 0 ;
break;
case V_50 :
if ( V_2 -> V_11 & V_51 )
V_21 -> V_27 = V_52 ;
else if ( F_7 ( V_53 , & V_2 -> V_54 ) &&
( V_2 -> V_12 <= V_2 -> V_55 ) )
V_21 -> V_27 = V_56 ;
else if ( F_3 ( V_2 ) )
V_21 -> V_27 = V_57 ;
else
V_21 -> V_27 = V_58 ;
break;
case V_59 :
V_21 -> V_60 = V_2 -> V_61 ;
break;
case V_62 :
V_21 -> V_60 = V_2 -> V_63 ;
break;
case V_64 :
V_21 -> V_60 = V_2 -> V_65 ;
break;
default:
V_22 = - V_66 ;
}
return V_22 ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_67 * V_68 ,
const struct V_69 * V_70 , int V_71 )
{
int V_72 ;
union V_67 * V_73 ;
if ( V_68 -> type != V_74 )
return - V_75 ;
for ( V_72 = 0 ; V_72 < V_71 ; ++ V_72 ) {
if ( V_68 -> V_68 . V_76 <= V_72 )
return - V_75 ;
V_73 = & V_68 -> V_68 . V_77 [ V_72 ] ;
if ( V_70 [ V_72 ] . V_78 ) {
T_1 * V_79 = ( T_1 * ) V_2 + V_70 [ V_72 ] . V_80 ;
if ( V_73 -> type == V_81 ||
V_73 -> type == V_82 )
strncpy ( V_79 , V_73 -> string . V_83 , 32 ) ;
else if ( V_73 -> type == V_84 ) {
strncpy ( V_79 , ( T_1 * ) & V_73 -> integer . V_85 ,
sizeof( V_86 ) ) ;
V_79 [ sizeof( V_86 ) ] = 0 ;
} else
* V_79 = 0 ;
} else {
int * V_87 = ( int * ) ( ( T_1 * ) V_2 + V_70 [ V_72 ] . V_80 ) ;
* V_87 = ( V_73 -> type == V_84 ) ?
V_73 -> integer . V_85 : - 1 ;
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 -> V_3 ) ) {
F_11 ( ( V_88 , V_89 , L_6 ) ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( const int V_90 ,
struct V_1 * V_2 ,
const struct V_91 * V_92 )
{
int V_93 = - V_75 ;
if ( V_90 && V_94 )
V_93 = F_8 ( V_2 , V_92 -> V_83 ,
V_95 + 1 ,
F_13 ( V_95 ) - 1 ) ;
else if ( V_90 )
V_93 = F_8 ( V_2 , V_92 -> V_83 ,
V_95 ,
F_13 ( V_95 ) ) ;
else
V_93 = F_8 ( V_2 , V_92 -> V_83 ,
V_96 , F_13 ( V_96 ) ) ;
if ( F_7 ( V_97 , & V_2 -> V_54 ) )
V_2 -> V_14 = V_2 -> V_15 ;
if ( F_7 ( V_98 , & V_2 -> V_54 ) &&
V_2 -> V_99 && V_2 -> V_37 ) {
V_2 -> V_15 = V_2 -> V_15 *
10000 / V_2 -> V_37 ;
V_2 -> V_14 = V_2 -> V_14 *
10000 / V_2 -> V_37 ;
V_2 -> V_100 =
V_2 -> V_100 *
10000 / V_2 -> V_37 ;
}
return V_93 ;
}
static int F_14 ( struct V_1 * V_2 )
{
const int V_101 = F_7 ( V_102 , & V_2 -> V_54 ) ;
int V_90 ;
int V_93 = - V_24 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
for ( V_90 = V_101 ? 1 : 0 ; V_90 >= 0 ; V_90 -- ) {
struct V_91 V_92 = { V_103 , NULL } ;
T_2 V_4 = V_89 ;
F_15 ( & V_2 -> V_104 ) ;
V_4 = F_16 ( V_2 -> V_3 -> V_105 ,
V_90 ? L_7 : L_8 ,
NULL , & V_92 ) ;
F_17 ( & V_2 -> V_104 ) ;
if ( F_18 ( V_4 ) ) {
F_11 ( ( V_88 , V_4 , L_9 ,
V_90 ? L_7 : L_8 ) ) ;
} else {
V_93 = F_12 ( V_90 ,
V_2 ,
& V_92 ) ;
F_19 ( V_92 . V_83 ) ;
break;
}
}
if ( ! V_93 && ! V_90 && V_101 )
F_20 ( V_106 L_10 ) ;
return V_93 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_93 = 0 ;
T_2 V_4 = 0 ;
struct V_91 V_92 = { V_103 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_107 &&
F_21 ( V_108 , V_2 -> V_107 +
F_22 ( V_109 ) ) )
return 0 ;
F_15 ( & V_2 -> V_104 ) ;
V_4 = F_16 ( V_2 -> V_3 -> V_105 , L_11 ,
NULL , & V_92 ) ;
F_17 ( & V_2 -> V_104 ) ;
if ( F_18 ( V_4 ) ) {
F_11 ( ( V_88 , V_4 , L_12 ) ) ;
return - V_24 ;
}
V_93 = F_8 ( V_2 , V_92 . V_83 ,
V_110 , F_13 ( V_110 ) ) ;
V_2 -> V_107 = V_108 ;
F_19 ( V_92 . V_83 ) ;
if ( V_2 -> V_99 == V_111 &&
V_2 -> V_42 != V_13 &&
( V_112 ) ( V_2 -> V_42 ) < 0 ) {
V_2 -> V_42 = abs ( ( V_112 ) V_2 -> V_42 ) ;
F_23 (KERN_WARNING FW_BUG
L_13 ) ;
}
if ( F_7 ( V_97 , & V_2 -> V_54 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
if ( F_7 ( V_98 , & V_2 -> V_54 ) &&
V_2 -> V_99 && V_2 -> V_37 ) {
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_37 ;
}
return V_93 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
if ( ! F_1 ( V_2 ) ||
! F_7 ( V_53 , & V_2 -> V_54 ) )
return - V_24 ;
F_15 ( & V_2 -> V_104 ) ;
V_4 = F_25 ( V_2 -> V_3 -> V_105 , L_14 ,
V_2 -> V_55 ) ;
F_17 ( & V_2 -> V_104 ) ;
if ( F_18 ( V_4 ) )
return - V_24 ;
F_26 ( ( V_113 , L_15 , V_2 -> V_55 ) ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 -> V_3 -> V_105 , L_14 ) ) {
F_29 ( V_53 , & V_2 -> V_54 ) ;
return 0 ;
}
F_30 ( V_53 , & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = V_2 -> V_100 ;
return F_24 ( V_2 ) ;
}
static T_3 F_31 ( struct V_3 * V_114 ,
struct V_115 * V_116 ,
char * V_117 )
{
struct V_1 * V_2 = F_5 ( F_32 ( V_114 ) ) ;
return sprintf ( V_117 , L_16 , V_2 -> V_55 * 1000 ) ;
}
static T_3 F_33 ( struct V_3 * V_114 ,
struct V_115 * V_116 ,
const char * V_117 , T_4 V_76 )
{
unsigned long V_87 ;
struct V_1 * V_2 = F_5 ( F_32 ( V_114 ) ) ;
if ( sscanf ( V_117 , L_17 , & V_87 ) == 1 )
V_2 -> V_55 = V_87 / 1000 ;
if ( F_1 ( V_2 ) )
F_24 ( V_2 ) ;
return V_76 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_118 V_119 = { . V_120 = V_2 , } ;
if ( V_2 -> V_99 == V_111 ) {
V_2 -> V_121 . V_122 = V_123 ;
V_2 -> V_121 . V_124 =
F_13 ( V_123 ) ;
} else {
V_2 -> V_121 . V_122 = V_125 ;
V_2 -> V_121 . V_124 =
F_13 ( V_125 ) ;
}
V_2 -> V_121 . V_126 = F_35 ( V_2 -> V_3 ) ;
V_2 -> V_121 . type = V_127 ;
V_2 -> V_121 . V_128 = F_4 ;
V_2 -> V_129 = F_36 ( & V_2 -> V_3 -> V_114 ,
& V_2 -> V_121 , & V_119 ) ;
if ( F_37 ( V_2 -> V_129 ) ) {
int V_93 = F_38 ( V_2 -> V_129 ) ;
V_2 -> V_129 = NULL ;
return V_93 ;
}
return F_39 ( & V_2 -> V_129 -> V_114 , & V_130 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_131 ) ;
if ( ! V_2 -> V_129 ) {
F_17 ( & V_2 -> V_131 ) ;
return;
}
F_41 ( & V_2 -> V_129 -> V_114 , & V_130 ) ;
F_42 ( V_2 -> V_129 ) ;
V_2 -> V_129 = NULL ;
F_17 ( & V_2 -> V_131 ) ;
}
static void F_43 ( const struct V_132 * V_133 , void * V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_134 ;
if ( V_133 -> type == V_135 && V_133 -> V_136 >= 8 ) {
const T_1 * V_137 = ( const T_1 * ) ( V_133 + 1 ) ;
int V_138 = F_44 ( ( const V_139 * ) ( V_137 + 6 ) ) ;
if ( V_133 -> V_136 >= 18 )
V_138 *= V_137 [ 17 ] ;
if ( V_2 -> V_15 * V_2 -> V_37 / 1000
!= V_138 &&
V_2 -> V_15 * 10 == V_138 )
F_30 ( V_98 ,
& V_2 -> V_54 ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
if ( F_7 ( V_97 , & V_2 -> V_54 ) )
return;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_42 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_30 ( V_97 , & V_2 -> V_54 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
if ( F_7 ( V_98 , & V_2 -> V_54 ) )
return;
if ( V_2 -> V_99 && F_46 ( L_18 ) ) {
const char * V_140 ;
V_140 = F_47 ( V_141 ) ;
if ( V_140 && ! strncasecmp ( V_140 , L_19 , 8 ) ) {
F_48 ( F_43 , V_2 ) ;
if ( F_7 ( V_98 ,
& V_2 -> V_54 ) &&
V_2 -> V_37 ) {
V_2 -> V_15 =
V_2 -> V_15 *
10000 / V_2 -> V_37 ;
V_2 -> V_14 =
V_2 -> V_14 *
10000 / V_2 -> V_37 ;
V_2 -> V_100 =
V_2 -> V_100 *
10000 / V_2 -> V_37 ;
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_37 ;
}
}
}
}
static int F_49 ( struct V_1 * V_2 , bool V_142 )
{
int V_93 , V_143 = F_1 ( V_2 ) ;
V_93 = F_9 ( V_2 ) ;
if ( V_93 )
return V_93 ;
if ( ! F_1 ( V_2 ) ) {
F_40 ( V_2 ) ;
V_2 -> V_107 = 0 ;
return 0 ;
}
if ( V_142 )
return 0 ;
if ( ! V_2 -> V_107 ||
V_143 != F_1 ( V_2 ) ) {
V_93 = F_14 ( V_2 ) ;
if ( V_93 )
return V_93 ;
F_27 ( V_2 ) ;
}
V_93 = F_6 ( V_2 ) ;
if ( V_93 )
return V_93 ;
F_45 ( V_2 ) ;
if ( ! V_2 -> V_129 ) {
V_93 = F_34 ( V_2 ) ;
if ( V_93 )
return V_93 ;
}
if ( ( V_2 -> V_11 & V_51 ) ||
( F_7 ( V_53 , & V_2 -> V_54 ) &&
( V_2 -> V_12 <= V_2 -> V_55 ) ) )
F_50 ( & V_2 -> V_3 -> V_114 , 0 ) ;
return V_93 ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_99 ;
if ( ! V_2 -> V_129 )
return;
V_99 = V_2 -> V_99 ;
F_14 ( V_2 ) ;
if ( V_99 == V_2 -> V_99 )
return;
F_40 ( V_2 ) ;
F_34 ( V_2 ) ;
}
static const char * F_52 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_99 == V_111 ) ?
L_20 : L_21 ;
}
static int F_53 ( struct V_144 * V_145 , int V_93 )
{
struct V_1 * V_2 = V_145 -> V_134 ;
if ( V_93 )
goto V_146;
F_54 ( V_145 , L_22 ,
F_1 ( V_2 ) ? L_23 : L_24 ) ;
if ( ! F_1 ( V_2 ) )
goto V_146;
if ( V_2 -> V_15 == V_13 )
F_54 ( V_145 , L_25 ) ;
else
F_54 ( V_145 , L_26 ,
V_2 -> V_15 ,
F_52 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_54 ( V_145 , L_27 ) ;
else
F_54 ( V_145 , L_28 ,
V_2 -> V_14 ,
F_52 ( V_2 ) ) ;
F_54 ( V_145 , L_29 ,
( ! V_2 -> V_147 ) ? L_30 : L_31 ) ;
if ( V_2 -> V_37 == V_13 )
F_54 ( V_145 , L_32 ) ;
else
F_54 ( V_145 , L_33 ,
V_2 -> V_37 ) ;
F_54 ( V_145 , L_34 ,
V_2 -> V_100 ,
F_52 ( V_2 ) ) ;
F_54 ( V_145 , L_35 ,
V_2 -> V_148 ,
F_52 ( V_2 ) ) ;
F_54 ( V_145 , L_36 , V_2 -> V_35 ) ;
F_54 ( V_145 , L_37 ,
V_2 -> V_149 ,
F_52 ( V_2 ) ) ;
F_54 ( V_145 , L_38 ,
V_2 -> V_150 ,
F_52 ( V_2 ) ) ;
F_54 ( V_145 , L_39 , V_2 -> V_61 ) ;
F_54 ( V_145 , L_40 , V_2 -> V_65 ) ;
F_54 ( V_145 , L_41 , V_2 -> type ) ;
F_54 ( V_145 , L_42 , V_2 -> V_63 ) ;
V_146:
if ( V_93 )
F_54 ( V_145 , L_43 ) ;
return V_93 ;
}
static int F_55 ( struct V_144 * V_145 , int V_93 )
{
struct V_1 * V_2 = V_145 -> V_134 ;
if ( V_93 )
goto V_146;
F_54 ( V_145 , L_22 ,
F_1 ( V_2 ) ? L_23 : L_24 ) ;
if ( ! F_1 ( V_2 ) )
goto V_146;
F_54 ( V_145 , L_44 ,
( V_2 -> V_11 & 0x04 ) ? L_45 : L_46 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_54 ( V_145 ,
L_47 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_54 ( V_145 , L_48 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_54 ( V_145 , L_49 ) ;
else
F_54 ( V_145 , L_50 ) ;
if ( V_2 -> V_42 == V_13 )
F_54 ( V_145 , L_51 ) ;
else
F_54 ( V_145 , L_52 ,
V_2 -> V_42 , F_52 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_54 ( V_145 , L_53 ) ;
else
F_54 ( V_145 , L_54 ,
V_2 -> V_12 , F_52 ( V_2 ) ) ;
if ( V_2 -> V_39 == V_13 )
F_54 ( V_145 , L_55 ) ;
else
F_54 ( V_145 , L_56 ,
V_2 -> V_39 ) ;
V_146:
if ( V_93 )
F_54 ( V_145 , L_57 ) ;
return V_93 ;
}
static int F_56 ( struct V_144 * V_145 , int V_93 )
{
struct V_1 * V_2 = V_145 -> V_134 ;
if ( V_93 )
goto V_146;
if ( ! F_1 ( V_2 ) ) {
F_54 ( V_145 , L_58 ) ;
goto V_146;
}
F_54 ( V_145 , L_59 ) ;
if ( ! V_2 -> V_55 )
F_54 ( V_145 , L_60 ) ;
else
F_54 ( V_145 , L_61 , V_2 -> V_55 ,
F_52 ( V_2 ) ) ;
V_146:
if ( V_93 )
F_54 ( V_145 , L_62 ) ;
return V_93 ;
}
static T_3 F_57 ( struct V_151 * V_151 ,
const char T_5 * V_92 ,
T_4 V_76 , T_6 * V_152 )
{
int V_93 = 0 ;
char V_153 [ 12 ] = { '\0' } ;
struct V_144 * V_154 = V_151 -> V_155 ;
struct V_1 * V_2 = V_154 -> V_134 ;
if ( ! V_2 || ( V_76 > sizeof( V_153 ) - 1 ) )
return - V_66 ;
if ( ! F_1 ( V_2 ) ) {
V_93 = - V_24 ;
goto V_146;
}
if ( F_58 ( V_153 , V_92 , V_76 ) ) {
V_93 = - V_75 ;
goto V_146;
}
V_153 [ V_76 ] = '\0' ;
if ( F_59 ( V_153 , 0 , & V_2 -> V_55 ) ) {
V_93 = - V_66 ;
goto V_146;
}
V_93 = F_24 ( V_2 ) ;
V_146:
if ( ! V_93 )
return V_76 ;
return V_93 ;
}
static int F_60 ( int V_156 , struct V_144 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_134 ;
int V_93 = F_49 ( V_2 , false ) ;
return V_157 [ V_156 ] ( V_145 , V_93 ) ;
}
static int F_61 ( struct V_158 * V_3 )
{
struct V_159 * V_160 = NULL ;
int V_72 ;
F_62 (KERN_WARNING PREFIX L_63
L_64 ) ;
if ( ! F_63 ( V_3 ) ) {
F_63 ( V_3 ) = F_64 ( F_35 ( V_3 ) ,
V_161 ) ;
if ( ! F_63 ( V_3 ) )
return - V_24 ;
}
for ( V_72 = 0 ; V_72 < V_162 ; ++ V_72 ) {
V_160 = F_65 ( V_163 [ V_72 ] . V_126 ,
V_163 [ V_72 ] . V_78 ,
F_63 ( V_3 ) ,
& V_163 [ V_72 ] . V_164 ,
F_66 ( V_3 ) ) ;
if ( ! V_160 )
return - V_24 ;
}
return 0 ;
}
static void F_67 ( struct V_158 * V_3 )
{
int V_72 ;
if ( ! F_63 ( V_3 ) )
return;
for ( V_72 = 0 ; V_72 < V_162 ; ++ V_72 )
F_68 ( V_163 [ V_72 ] . V_126 ,
F_63 ( V_3 ) ) ;
F_68 ( F_35 ( V_3 ) , V_161 ) ;
F_63 ( V_3 ) = NULL ;
}
static void F_69 ( struct V_158 * V_3 , T_7 V_165 )
{
struct V_1 * V_2 = F_66 ( V_3 ) ;
struct V_16 * V_166 ;
if ( ! V_2 )
return;
V_166 = V_2 -> V_129 ;
if ( V_167 > 0 )
F_70 ( V_167 ) ;
if ( V_165 == V_168 )
F_51 ( V_2 ) ;
F_49 ( V_2 , false ) ;
F_71 ( V_3 -> V_169 . V_170 ,
F_72 ( & V_3 -> V_114 ) , V_165 ,
F_1 ( V_2 ) ) ;
F_73 ( V_3 , V_165 , F_1 ( V_2 ) ) ;
if ( V_166 && V_2 -> V_129 )
F_74 ( V_2 -> V_129 ) ;
}
static int F_75 ( struct V_171 * V_172 ,
unsigned long V_78 , void * V_173 )
{
struct V_1 * V_2 = F_76 ( V_172 , struct V_1 ,
V_174 ) ;
int V_93 ;
switch ( V_78 ) {
case V_175 :
case V_176 :
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_129 ) {
V_93 = F_14 ( V_2 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_34 ( V_2 ) ;
if ( V_93 )
return V_93 ;
} else
F_51 ( V_2 ) ;
F_27 ( V_2 ) ;
F_6 ( V_2 ) ;
break;
}
return 0 ;
}
static int T_8
F_77 ( const struct V_177 * V_178 )
{
V_94 = 1 ;
return 0 ;
}
static int T_8
F_78 ( const struct V_177 * V_178 )
{
V_167 = 1000 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_179 , V_22 ;
for ( V_179 = 5 ; V_179 ; V_179 -- ) {
V_22 = F_49 ( V_2 , false ) ;
if ( ! V_22 )
break;
F_70 ( 20 ) ;
}
return V_22 ;
}
static int F_80 ( struct V_158 * V_3 )
{
int V_93 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_3 )
return - V_66 ;
if ( V_3 -> V_180 )
return - V_181 ;
V_2 = F_81 ( sizeof( struct V_1 ) , V_182 ) ;
if ( ! V_2 )
return - V_183 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_82 ( V_3 ) , V_184 ) ;
strcpy ( F_83 ( V_3 ) , V_185 ) ;
V_3 -> V_186 = V_2 ;
F_84 ( & V_2 -> V_104 ) ;
F_84 ( & V_2 -> V_131 ) ;
if ( F_28 ( V_2 -> V_3 -> V_105 , L_7 ) )
F_30 ( V_102 , & V_2 -> V_54 ) ;
V_93 = F_79 ( V_2 ) ;
if ( V_93 )
goto V_187;
#ifdef F_85
V_93 = F_61 ( V_3 ) ;
#endif
if ( V_93 ) {
#ifdef F_85
F_67 ( V_3 ) ;
#endif
goto V_187;
}
F_62 (KERN_INFO PREFIX L_65 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_66 : L_67 ) ;
V_2 -> V_174 . V_188 = F_75 ;
F_86 ( & V_2 -> V_174 ) ;
F_87 ( & V_3 -> V_114 , 1 ) ;
return V_93 ;
V_187:
F_40 ( V_2 ) ;
F_88 ( & V_2 -> V_104 ) ;
F_88 ( & V_2 -> V_131 ) ;
F_19 ( V_2 ) ;
return V_93 ;
}
static int F_89 ( struct V_158 * V_3 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_66 ( V_3 ) )
return - V_66 ;
F_87 ( & V_3 -> V_114 , 0 ) ;
V_2 = F_66 ( V_3 ) ;
F_90 ( & V_2 -> V_174 ) ;
#ifdef F_85
F_67 ( V_3 ) ;
#endif
F_40 ( V_2 ) ;
F_88 ( & V_2 -> V_104 ) ;
F_88 ( & V_2 -> V_131 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_3 * V_114 )
{
struct V_1 * V_2 ;
if ( ! V_114 )
return - V_66 ;
V_2 = F_66 ( F_92 ( V_114 ) ) ;
if ( ! V_2 )
return - V_66 ;
V_2 -> V_107 = 0 ;
F_49 ( V_2 , true ) ;
return 0 ;
}
static void T_8 F_93 ( void * V_189 , T_9 V_190 )
{
unsigned int V_72 ;
int V_93 ;
for ( V_72 = 0 ; V_72 < F_13 ( V_191 ) ; V_72 ++ )
if ( F_94 ( V_191 [ V_72 ] , L_68 , - 1 ) ) {
F_95 (PREFIX ACPI_BATTERY_DEVICE_NAME
L_69 ,
acpi_battery_blacklist[i]) ;
return;
}
F_96 ( V_192 ) ;
#ifdef F_85
V_161 = F_97 () ;
if ( ! V_161 )
return;
#endif
V_93 = F_98 ( & V_193 ) ;
#ifdef F_85
if ( V_93 < 0 )
F_99 ( V_161 ) ;
#endif
V_194 = ( V_93 == 0 ) ;
}
static int T_8 F_100 ( void )
{
if ( V_195 )
return - V_24 ;
V_196 = F_101 ( F_93 , NULL ) ;
return 0 ;
}
static void T_10 F_102 ( void )
{
F_103 ( V_196 + 1 ) ;
if ( V_194 )
F_104 ( & V_193 ) ;
#ifdef F_85
if ( V_161 )
F_99 ( V_161 ) ;
#endif
}
