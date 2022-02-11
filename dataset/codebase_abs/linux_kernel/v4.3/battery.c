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
static int F_12 ( struct V_1 * V_2 )
{
int V_90 = - V_75 ;
T_2 V_4 = 0 ;
char * V_91 = F_7 ( V_92 , & V_2 -> V_54 ) ?
L_7 : L_8 ;
struct V_93 V_94 = { V_95 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_13 ( & V_2 -> V_96 ) ;
V_4 = F_14 ( V_2 -> V_3 -> V_97 , V_91 ,
NULL , & V_94 ) ;
F_15 ( & V_2 -> V_96 ) ;
if ( F_16 ( V_4 ) ) {
F_11 ( ( V_88 , V_4 , L_9 , V_91 ) ) ;
return - V_24 ;
}
if ( V_98 )
V_90 = F_8 ( V_2 , V_94 . V_83 ,
V_99 + 1 ,
F_17 ( V_99 ) - 1 ) ;
else if ( F_7 ( V_92 , & V_2 -> V_54 ) )
V_90 = F_8 ( V_2 , V_94 . V_83 ,
V_99 ,
F_17 ( V_99 ) ) ;
else
V_90 = F_8 ( V_2 , V_94 . V_83 ,
V_100 , F_17 ( V_100 ) ) ;
F_18 ( V_94 . V_83 ) ;
if ( F_7 ( V_101 , & V_2 -> V_54 ) )
V_2 -> V_14 = V_2 -> V_15 ;
if ( F_7 ( V_102 , & V_2 -> V_54 ) &&
V_2 -> V_103 && V_2 -> V_37 ) {
V_2 -> V_15 = V_2 -> V_15 *
10000 / V_2 -> V_37 ;
V_2 -> V_14 = V_2 -> V_14 *
10000 / V_2 -> V_37 ;
V_2 -> V_104 =
V_2 -> V_104 *
10000 / V_2 -> V_37 ;
}
return V_90 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_90 = 0 ;
T_2 V_4 = 0 ;
struct V_93 V_94 = { V_95 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_105 &&
F_19 ( V_106 , V_2 -> V_105 +
F_20 ( V_107 ) ) )
return 0 ;
F_13 ( & V_2 -> V_96 ) ;
V_4 = F_14 ( V_2 -> V_3 -> V_97 , L_10 ,
NULL , & V_94 ) ;
F_15 ( & V_2 -> V_96 ) ;
if ( F_16 ( V_4 ) ) {
F_11 ( ( V_88 , V_4 , L_11 ) ) ;
return - V_24 ;
}
V_90 = F_8 ( V_2 , V_94 . V_83 ,
V_108 , F_17 ( V_108 ) ) ;
V_2 -> V_105 = V_106 ;
F_18 ( V_94 . V_83 ) ;
if ( V_2 -> V_103 == V_109 &&
V_2 -> V_42 != V_13 &&
( V_110 ) ( V_2 -> V_42 ) < 0 ) {
V_2 -> V_42 = abs ( ( V_110 ) V_2 -> V_42 ) ;
F_21 (KERN_WARNING FW_BUG
L_12 ) ;
}
if ( F_7 ( V_101 , & V_2 -> V_54 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
if ( F_7 ( V_102 , & V_2 -> V_54 ) &&
V_2 -> V_103 && V_2 -> V_37 ) {
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_37 ;
}
return V_90 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
if ( ! F_1 ( V_2 ) ||
! F_7 ( V_53 , & V_2 -> V_54 ) )
return - V_24 ;
F_13 ( & V_2 -> V_96 ) ;
V_4 = F_23 ( V_2 -> V_3 -> V_97 , L_13 ,
V_2 -> V_55 ) ;
F_15 ( & V_2 -> V_96 ) ;
if ( F_16 ( V_4 ) )
return - V_24 ;
F_24 ( ( V_111 , L_14 , V_2 -> V_55 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( ! F_26 ( V_2 -> V_3 -> V_97 , L_13 ) ) {
F_27 ( V_53 , & V_2 -> V_54 ) ;
return 0 ;
}
F_28 ( V_53 , & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = V_2 -> V_104 ;
return F_22 ( V_2 ) ;
}
static T_3 F_29 ( struct V_3 * V_112 ,
struct V_113 * V_114 ,
char * V_115 )
{
struct V_1 * V_2 = F_5 ( F_30 ( V_112 ) ) ;
return sprintf ( V_115 , L_15 , V_2 -> V_55 * 1000 ) ;
}
static T_3 F_31 ( struct V_3 * V_112 ,
struct V_113 * V_114 ,
const char * V_115 , T_4 V_76 )
{
unsigned long V_87 ;
struct V_1 * V_2 = F_5 ( F_30 ( V_112 ) ) ;
if ( sscanf ( V_115 , L_16 , & V_87 ) == 1 )
V_2 -> V_55 = V_87 / 1000 ;
if ( F_1 ( V_2 ) )
F_22 ( V_2 ) ;
return V_76 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_116 V_117 = { . V_118 = V_2 , } ;
if ( V_2 -> V_103 == V_109 ) {
V_2 -> V_119 . V_120 = V_121 ;
V_2 -> V_119 . V_122 =
F_17 ( V_121 ) ;
} else {
V_2 -> V_119 . V_120 = V_123 ;
V_2 -> V_119 . V_122 =
F_17 ( V_123 ) ;
}
V_2 -> V_119 . V_91 = F_33 ( V_2 -> V_3 ) ;
V_2 -> V_119 . type = V_124 ;
V_2 -> V_119 . V_125 = F_4 ;
V_2 -> V_126 = F_34 ( & V_2 -> V_3 -> V_112 ,
& V_2 -> V_119 , & V_117 ) ;
if ( F_35 ( V_2 -> V_126 ) ) {
int V_90 = F_36 ( V_2 -> V_126 ) ;
V_2 -> V_126 = NULL ;
return V_90 ;
}
return F_37 ( & V_2 -> V_126 -> V_112 , & V_127 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_128 ) ;
if ( ! V_2 -> V_126 ) {
F_15 ( & V_2 -> V_128 ) ;
return;
}
F_39 ( & V_2 -> V_126 -> V_112 , & V_127 ) ;
F_40 ( V_2 -> V_126 ) ;
V_2 -> V_126 = NULL ;
F_15 ( & V_2 -> V_128 ) ;
}
static void F_41 ( const struct V_129 * V_130 , void * V_131 )
{
struct V_1 * V_2 = (struct V_1 * ) V_131 ;
if ( V_130 -> type == V_132 && V_130 -> V_133 >= 8 ) {
const T_1 * V_134 = ( const T_1 * ) ( V_130 + 1 ) ;
int V_135 = F_42 ( ( const V_136 * ) ( V_134 + 6 ) ) ;
if ( V_130 -> V_133 >= 18 )
V_135 *= V_134 [ 17 ] ;
if ( V_2 -> V_15 * V_2 -> V_37 / 1000
!= V_135 &&
V_2 -> V_15 * 10 == V_135 )
F_28 ( V_102 ,
& V_2 -> V_54 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
if ( F_7 ( V_101 , & V_2 -> V_54 ) )
return;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_42 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_28 ( V_101 , & V_2 -> V_54 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
if ( F_7 ( V_102 , & V_2 -> V_54 ) )
return;
if ( V_2 -> V_103 && F_44 ( L_17 ) ) {
const char * V_137 ;
V_137 = F_45 ( V_138 ) ;
if ( V_137 && ! strncasecmp ( V_137 , L_18 , 8 ) ) {
F_46 ( F_41 , V_2 ) ;
if ( F_7 ( V_102 ,
& V_2 -> V_54 ) &&
V_2 -> V_37 ) {
V_2 -> V_15 =
V_2 -> V_15 *
10000 / V_2 -> V_37 ;
V_2 -> V_14 =
V_2 -> V_14 *
10000 / V_2 -> V_37 ;
V_2 -> V_104 =
V_2 -> V_104 *
10000 / V_2 -> V_37 ;
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_37 ;
}
}
}
}
static int F_47 ( struct V_1 * V_2 , bool V_139 )
{
int V_90 , V_140 = F_1 ( V_2 ) ;
V_90 = F_9 ( V_2 ) ;
if ( V_90 )
return V_90 ;
if ( ! F_1 ( V_2 ) ) {
F_38 ( V_2 ) ;
V_2 -> V_105 = 0 ;
return 0 ;
}
if ( V_139 )
return 0 ;
if ( ! V_2 -> V_105 ||
V_140 != F_1 ( V_2 ) ) {
V_90 = F_12 ( V_2 ) ;
if ( V_90 )
return V_90 ;
F_25 ( V_2 ) ;
}
if ( ! V_2 -> V_126 ) {
V_90 = F_32 ( V_2 ) ;
if ( V_90 )
return V_90 ;
}
V_90 = F_6 ( V_2 ) ;
if ( V_90 )
return V_90 ;
F_43 ( V_2 ) ;
if ( ( V_2 -> V_11 & V_51 ) ||
( F_7 ( V_53 , & V_2 -> V_54 ) &&
( V_2 -> V_12 <= V_2 -> V_55 ) ) )
F_48 ( & V_2 -> V_3 -> V_112 , 0 ) ;
return V_90 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_103 ;
if ( ! V_2 -> V_126 )
return;
V_103 = V_2 -> V_103 ;
F_12 ( V_2 ) ;
if ( V_103 == V_2 -> V_103 )
return;
F_38 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static const char * F_50 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_103 == V_109 ) ?
L_19 : L_20 ;
}
static int F_51 ( struct V_141 * V_142 , int V_90 )
{
struct V_1 * V_2 = V_142 -> V_131 ;
if ( V_90 )
goto V_143;
F_52 ( V_142 , L_21 ,
F_1 ( V_2 ) ? L_22 : L_23 ) ;
if ( ! F_1 ( V_2 ) )
goto V_143;
if ( V_2 -> V_15 == V_13 )
F_52 ( V_142 , L_24 ) ;
else
F_52 ( V_142 , L_25 ,
V_2 -> V_15 ,
F_50 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_52 ( V_142 , L_26 ) ;
else
F_52 ( V_142 , L_27 ,
V_2 -> V_14 ,
F_50 ( V_2 ) ) ;
F_52 ( V_142 , L_28 ,
( ! V_2 -> V_144 ) ? L_29 : L_30 ) ;
if ( V_2 -> V_37 == V_13 )
F_52 ( V_142 , L_31 ) ;
else
F_52 ( V_142 , L_32 ,
V_2 -> V_37 ) ;
F_52 ( V_142 , L_33 ,
V_2 -> V_104 ,
F_50 ( V_2 ) ) ;
F_52 ( V_142 , L_34 ,
V_2 -> V_145 ,
F_50 ( V_2 ) ) ;
F_52 ( V_142 , L_35 , V_2 -> V_35 ) ;
F_52 ( V_142 , L_36 ,
V_2 -> V_146 ,
F_50 ( V_2 ) ) ;
F_52 ( V_142 , L_37 ,
V_2 -> V_147 ,
F_50 ( V_2 ) ) ;
F_52 ( V_142 , L_38 , V_2 -> V_61 ) ;
F_52 ( V_142 , L_39 , V_2 -> V_65 ) ;
F_52 ( V_142 , L_40 , V_2 -> type ) ;
F_52 ( V_142 , L_41 , V_2 -> V_63 ) ;
V_143:
if ( V_90 )
F_52 ( V_142 , L_42 ) ;
return V_90 ;
}
static int F_53 ( struct V_141 * V_142 , int V_90 )
{
struct V_1 * V_2 = V_142 -> V_131 ;
if ( V_90 )
goto V_143;
F_52 ( V_142 , L_21 ,
F_1 ( V_2 ) ? L_22 : L_23 ) ;
if ( ! F_1 ( V_2 ) )
goto V_143;
F_52 ( V_142 , L_43 ,
( V_2 -> V_11 & 0x04 ) ? L_44 : L_45 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_52 ( V_142 ,
L_46 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_52 ( V_142 , L_47 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_52 ( V_142 , L_48 ) ;
else
F_52 ( V_142 , L_49 ) ;
if ( V_2 -> V_42 == V_13 )
F_52 ( V_142 , L_50 ) ;
else
F_52 ( V_142 , L_51 ,
V_2 -> V_42 , F_50 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_52 ( V_142 , L_52 ) ;
else
F_52 ( V_142 , L_53 ,
V_2 -> V_12 , F_50 ( V_2 ) ) ;
if ( V_2 -> V_39 == V_13 )
F_52 ( V_142 , L_54 ) ;
else
F_52 ( V_142 , L_55 ,
V_2 -> V_39 ) ;
V_143:
if ( V_90 )
F_52 ( V_142 , L_56 ) ;
return V_90 ;
}
static int F_54 ( struct V_141 * V_142 , int V_90 )
{
struct V_1 * V_2 = V_142 -> V_131 ;
if ( V_90 )
goto V_143;
if ( ! F_1 ( V_2 ) ) {
F_52 ( V_142 , L_57 ) ;
goto V_143;
}
F_52 ( V_142 , L_58 ) ;
if ( ! V_2 -> V_55 )
F_52 ( V_142 , L_59 ) ;
else
F_52 ( V_142 , L_60 , V_2 -> V_55 ,
F_50 ( V_2 ) ) ;
V_143:
if ( V_90 )
F_52 ( V_142 , L_61 ) ;
return V_90 ;
}
static T_3 F_55 ( struct V_148 * V_148 ,
const char T_5 * V_94 ,
T_4 V_76 , T_6 * V_149 )
{
int V_90 = 0 ;
char V_150 [ 12 ] = { '\0' } ;
struct V_141 * V_151 = V_148 -> V_152 ;
struct V_1 * V_2 = V_151 -> V_131 ;
if ( ! V_2 || ( V_76 > sizeof( V_150 ) - 1 ) )
return - V_66 ;
if ( ! F_1 ( V_2 ) ) {
V_90 = - V_24 ;
goto V_143;
}
if ( F_56 ( V_150 , V_94 , V_76 ) ) {
V_90 = - V_75 ;
goto V_143;
}
V_150 [ V_76 ] = '\0' ;
if ( F_57 ( V_150 , 0 , & V_2 -> V_55 ) ) {
V_90 = - V_66 ;
goto V_143;
}
V_90 = F_22 ( V_2 ) ;
V_143:
if ( ! V_90 )
return V_76 ;
return V_90 ;
}
static int F_58 ( int V_153 , struct V_141 * V_142 )
{
struct V_1 * V_2 = V_142 -> V_131 ;
int V_90 = F_47 ( V_2 , false ) ;
return V_154 [ V_153 ] ( V_142 , V_90 ) ;
}
static int F_59 ( struct V_155 * V_3 )
{
struct V_156 * V_157 = NULL ;
int V_72 ;
F_60 (KERN_WARNING PREFIX L_62
L_63 ) ;
if ( ! F_61 ( V_3 ) ) {
F_61 ( V_3 ) = F_62 ( F_33 ( V_3 ) ,
V_158 ) ;
if ( ! F_61 ( V_3 ) )
return - V_24 ;
}
for ( V_72 = 0 ; V_72 < V_159 ; ++ V_72 ) {
V_157 = F_63 ( V_160 [ V_72 ] . V_91 ,
V_160 [ V_72 ] . V_78 ,
F_61 ( V_3 ) ,
& V_160 [ V_72 ] . V_161 ,
F_64 ( V_3 ) ) ;
if ( ! V_157 )
return - V_24 ;
}
return 0 ;
}
static void F_65 ( struct V_155 * V_3 )
{
int V_72 ;
if ( ! F_61 ( V_3 ) )
return;
for ( V_72 = 0 ; V_72 < V_159 ; ++ V_72 )
F_66 ( V_160 [ V_72 ] . V_91 ,
F_61 ( V_3 ) ) ;
F_66 ( F_33 ( V_3 ) , V_158 ) ;
F_61 ( V_3 ) = NULL ;
}
static void F_67 ( struct V_155 * V_3 , T_7 V_162 )
{
struct V_1 * V_2 = F_64 ( V_3 ) ;
struct V_16 * V_163 ;
if ( ! V_2 )
return;
V_163 = V_2 -> V_126 ;
if ( V_164 > 0 )
F_68 ( V_164 ) ;
if ( V_162 == V_165 )
F_49 ( V_2 ) ;
F_47 ( V_2 , false ) ;
F_69 ( V_3 -> V_166 . V_167 ,
F_70 ( & V_3 -> V_112 ) , V_162 ,
F_1 ( V_2 ) ) ;
F_71 ( V_3 , V_162 , F_1 ( V_2 ) ) ;
if ( V_163 && V_2 -> V_126 )
F_72 ( V_2 -> V_126 ) ;
}
static int F_73 ( struct V_168 * V_169 ,
unsigned long V_78 , void * V_170 )
{
struct V_1 * V_2 = F_74 ( V_169 , struct V_1 ,
V_171 ) ;
int V_90 ;
switch ( V_78 ) {
case V_172 :
case V_173 :
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_126 ) {
V_90 = F_12 ( V_2 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_32 ( V_2 ) ;
if ( V_90 )
return V_90 ;
} else
F_49 ( V_2 ) ;
F_25 ( V_2 ) ;
F_6 ( V_2 ) ;
break;
}
return 0 ;
}
static int T_8
F_75 ( const struct V_174 * V_175 )
{
V_98 = 1 ;
return 0 ;
}
static int T_8
F_76 ( const struct V_174 * V_175 )
{
V_164 = 1000 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_176 , V_22 ;
for ( V_176 = 5 ; V_176 ; V_176 -- ) {
V_22 = F_47 ( V_2 , false ) ;
if ( ! V_22 )
break;
F_68 ( 20 ) ;
}
return V_22 ;
}
static int F_78 ( struct V_155 * V_3 )
{
int V_90 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_3 )
return - V_66 ;
if ( V_3 -> V_177 )
return - V_178 ;
V_2 = F_79 ( sizeof( struct V_1 ) , V_179 ) ;
if ( ! V_2 )
return - V_180 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_80 ( V_3 ) , V_181 ) ;
strcpy ( F_81 ( V_3 ) , V_182 ) ;
V_3 -> V_183 = V_2 ;
F_82 ( & V_2 -> V_96 ) ;
F_82 ( & V_2 -> V_128 ) ;
if ( F_26 ( V_2 -> V_3 -> V_97 , L_7 ) )
F_28 ( V_92 , & V_2 -> V_54 ) ;
V_90 = F_77 ( V_2 ) ;
if ( V_90 )
goto V_184;
#ifdef F_83
V_90 = F_59 ( V_3 ) ;
#endif
if ( V_90 ) {
#ifdef F_83
F_65 ( V_3 ) ;
#endif
goto V_184;
}
F_60 (KERN_INFO PREFIX L_64 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_65 : L_66 ) ;
V_2 -> V_171 . V_185 = F_73 ;
F_84 ( & V_2 -> V_171 ) ;
F_85 ( & V_3 -> V_112 , 1 ) ;
return V_90 ;
V_184:
F_38 ( V_2 ) ;
F_86 ( & V_2 -> V_96 ) ;
F_86 ( & V_2 -> V_128 ) ;
F_18 ( V_2 ) ;
return V_90 ;
}
static int F_87 ( struct V_155 * V_3 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_64 ( V_3 ) )
return - V_66 ;
F_85 ( & V_3 -> V_112 , 0 ) ;
V_2 = F_64 ( V_3 ) ;
F_88 ( & V_2 -> V_171 ) ;
#ifdef F_83
F_65 ( V_3 ) ;
#endif
F_38 ( V_2 ) ;
F_86 ( & V_2 -> V_96 ) ;
F_86 ( & V_2 -> V_128 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_3 * V_112 )
{
struct V_1 * V_2 ;
if ( ! V_112 )
return - V_66 ;
V_2 = F_64 ( F_90 ( V_112 ) ) ;
if ( ! V_2 )
return - V_66 ;
V_2 -> V_105 = 0 ;
F_47 ( V_2 , true ) ;
return 0 ;
}
static void T_8 F_91 ( void * V_186 , T_9 V_187 )
{
int V_90 ;
F_92 ( V_188 ) ;
#ifdef F_83
V_158 = F_93 () ;
if ( ! V_158 )
return;
#endif
V_90 = F_94 ( & V_189 ) ;
#ifdef F_83
if ( V_90 < 0 )
F_95 ( V_158 ) ;
#endif
}
static int T_8 F_96 ( void )
{
if ( V_190 )
return - V_24 ;
V_191 = F_97 ( F_91 , NULL ) ;
return 0 ;
}
static void T_10 F_98 ( void )
{
F_99 ( V_191 ) ;
F_100 ( & V_189 ) ;
#ifdef F_83
F_95 ( V_158 ) ;
#endif
}
