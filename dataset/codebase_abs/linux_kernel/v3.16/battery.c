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
inline char * F_8 ( struct V_1 * V_2 )
{
return ( V_2 -> V_67 == V_68 ) ?
L_6 : L_7 ;
}
static int F_9 ( struct V_1 * V_2 ,
union V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
int V_74 ;
union V_69 * V_75 ;
if ( V_70 -> type != V_76 )
return - V_77 ;
for ( V_74 = 0 ; V_74 < V_73 ; ++ V_74 ) {
if ( V_70 -> V_70 . V_78 <= V_74 )
return - V_77 ;
V_75 = & V_70 -> V_70 . V_79 [ V_74 ] ;
if ( V_72 [ V_74 ] . V_80 ) {
T_1 * V_81 = ( T_1 * ) V_2 + V_72 [ V_74 ] . V_82 ;
if ( V_75 -> type == V_83 ||
V_75 -> type == V_84 )
strncpy ( V_81 , V_75 -> string . V_85 , 32 ) ;
else if ( V_75 -> type == V_86 ) {
strncpy ( V_81 , ( T_1 * ) & V_75 -> integer . V_87 ,
sizeof( V_88 ) ) ;
V_81 [ sizeof( V_88 ) ] = 0 ;
} else
* V_81 = 0 ;
} else {
int * V_89 = ( int * ) ( ( T_1 * ) V_2 + V_72 [ V_74 ] . V_82 ) ;
* V_89 = ( V_75 -> type == V_86 ) ?
V_75 -> integer . V_87 : - 1 ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 -> V_3 ) ) {
F_12 ( ( V_90 , V_91 , L_8 ) ) ;
return - V_24 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_92 = - V_77 ;
T_2 V_4 = 0 ;
char * V_93 = F_7 ( V_94 , & V_2 -> V_54 ) ?
L_9 : L_10 ;
struct V_95 V_96 = { V_97 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_14 ( & V_2 -> V_98 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_99 , V_93 ,
NULL , & V_96 ) ;
F_16 ( & V_2 -> V_98 ) ;
if ( F_17 ( V_4 ) ) {
F_12 ( ( V_90 , V_4 , L_11 , V_93 ) ) ;
return - V_24 ;
}
if ( V_100 )
V_92 = F_9 ( V_2 , V_96 . V_85 ,
V_101 + 1 ,
F_18 ( V_101 ) - 1 ) ;
else if ( F_7 ( V_94 , & V_2 -> V_54 ) )
V_92 = F_9 ( V_2 , V_96 . V_85 ,
V_101 ,
F_18 ( V_101 ) ) ;
else
V_92 = F_9 ( V_2 , V_96 . V_85 ,
V_102 , F_18 ( V_102 ) ) ;
F_19 ( V_96 . V_85 ) ;
if ( F_7 ( V_103 , & V_2 -> V_54 ) )
V_2 -> V_14 = V_2 -> V_15 ;
if ( F_7 ( V_104 , & V_2 -> V_54 ) &&
V_2 -> V_67 && V_2 -> V_37 ) {
V_2 -> V_15 = V_2 -> V_15 *
10000 / V_2 -> V_37 ;
V_2 -> V_14 = V_2 -> V_14 *
10000 / V_2 -> V_37 ;
V_2 -> V_105 =
V_2 -> V_105 *
10000 / V_2 -> V_37 ;
}
return V_92 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
T_2 V_4 = 0 ;
struct V_95 V_96 = { V_97 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_106 &&
F_20 ( V_107 , V_2 -> V_106 +
F_21 ( V_108 ) ) )
return 0 ;
F_14 ( & V_2 -> V_98 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_99 , L_12 ,
NULL , & V_96 ) ;
F_16 ( & V_2 -> V_98 ) ;
if ( F_17 ( V_4 ) ) {
F_12 ( ( V_90 , V_4 , L_13 ) ) ;
return - V_24 ;
}
V_92 = F_9 ( V_2 , V_96 . V_85 ,
V_109 , F_18 ( V_109 ) ) ;
V_2 -> V_106 = V_107 ;
F_19 ( V_96 . V_85 ) ;
if ( V_2 -> V_67 == V_68 &&
V_2 -> V_42 != V_13 &&
( V_110 ) ( V_2 -> V_42 ) < 0 ) {
V_2 -> V_42 = abs ( ( V_110 ) V_2 -> V_42 ) ;
F_22 (KERN_WARNING FW_BUG L_14
L_15 ) ;
}
if ( V_2 -> V_12 > V_2 -> V_14
&& V_2 -> V_14 != V_13 ) {
V_2 -> V_12 = V_2 -> V_14 ;
if ( V_2 -> V_12 != V_2 -> V_15 )
F_22 (KERN_WARNING FW_BUG
L_16
L_17 ,
battery->capacity_now, battery->full_charge_capacity) ;
}
if ( F_7 ( V_103 , & V_2 -> V_54 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
if ( F_7 ( V_104 , & V_2 -> V_54 ) &&
V_2 -> V_67 && V_2 -> V_37 ) {
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_37 ;
}
return V_92 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
if ( ! F_1 ( V_2 ) ||
! F_7 ( V_53 , & V_2 -> V_54 ) )
return - V_24 ;
F_14 ( & V_2 -> V_98 ) ;
V_4 = F_24 ( V_2 -> V_3 -> V_99 , L_18 ,
V_2 -> V_55 ) ;
F_16 ( & V_2 -> V_98 ) ;
if ( F_17 ( V_4 ) )
return - V_24 ;
F_25 ( ( V_111 , L_19 , V_2 -> V_55 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( ! F_27 ( V_2 -> V_3 -> V_99 , L_18 ) ) {
F_28 ( V_53 , & V_2 -> V_54 ) ;
return 0 ;
}
F_29 ( V_53 , & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = V_2 -> V_105 ;
return F_23 ( V_2 ) ;
}
static T_3 F_30 ( struct V_3 * V_112 ,
struct V_113 * V_114 ,
char * V_115 )
{
struct V_1 * V_2 = F_5 ( F_31 ( V_112 ) ) ;
return sprintf ( V_115 , L_20 , V_2 -> V_55 * 1000 ) ;
}
static T_3 F_32 ( struct V_3 * V_112 ,
struct V_113 * V_114 ,
const char * V_115 , T_4 V_78 )
{
unsigned long V_89 ;
struct V_1 * V_2 = F_5 ( F_31 ( V_112 ) ) ;
if ( sscanf ( V_115 , L_21 , & V_89 ) == 1 )
V_2 -> V_55 = V_89 / 1000 ;
if ( F_1 ( V_2 ) )
F_23 ( V_2 ) ;
return V_78 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_92 ;
if ( V_2 -> V_67 == V_68 ) {
V_2 -> V_116 . V_117 = V_118 ;
V_2 -> V_116 . V_119 =
F_18 ( V_118 ) ;
} else {
V_2 -> V_116 . V_117 = V_120 ;
V_2 -> V_116 . V_119 =
F_18 ( V_120 ) ;
}
V_2 -> V_116 . V_93 = F_34 ( V_2 -> V_3 ) ;
V_2 -> V_116 . type = V_121 ;
V_2 -> V_116 . V_122 = F_4 ;
V_92 = F_35 ( & V_2 -> V_3 -> V_112 , & V_2 -> V_116 ) ;
if ( V_92 )
return V_92 ;
return F_36 ( V_2 -> V_116 . V_112 , & V_123 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_124 ) ;
if ( ! V_2 -> V_116 . V_112 ) {
F_16 ( & V_2 -> V_124 ) ;
return;
}
F_38 ( V_2 -> V_116 . V_112 , & V_123 ) ;
F_39 ( & V_2 -> V_116 ) ;
V_2 -> V_116 . V_112 = NULL ;
F_16 ( & V_2 -> V_124 ) ;
}
static void F_40 ( const struct V_125 * V_126 , void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
if ( V_126 -> type == V_128 && V_126 -> V_129 >= 8 ) {
const T_1 * V_130 = ( const T_1 * ) ( V_126 + 1 ) ;
int V_131 = F_41 ( ( const V_132 * ) ( V_130 + 6 ) ) ;
if ( V_126 -> V_129 >= 18 )
V_131 *= V_130 [ 17 ] ;
if ( V_2 -> V_15 * V_2 -> V_37 / 1000
!= V_131 &&
V_2 -> V_15 * 10 == V_131 )
F_29 ( V_104 ,
& V_2 -> V_54 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
if ( F_7 ( V_103 , & V_2 -> V_54 ) )
return;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_42 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_29 ( V_103 , & V_2 -> V_54 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
if ( F_7 ( V_104 , & V_2 -> V_54 ) )
return;
if ( V_2 -> V_67 && F_43 ( L_22 ) ) {
const char * V_133 ;
V_133 = F_44 ( V_134 ) ;
if ( V_133 && ! F_45 ( V_133 , L_23 , 8 ) ) {
F_46 ( F_40 , V_2 ) ;
if ( F_7 ( V_104 ,
& V_2 -> V_54 ) &&
V_2 -> V_37 ) {
V_2 -> V_15 =
V_2 -> V_15 *
10000 / V_2 -> V_37 ;
V_2 -> V_14 =
V_2 -> V_14 *
10000 / V_2 -> V_37 ;
V_2 -> V_105 =
V_2 -> V_105 *
10000 / V_2 -> V_37 ;
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_37 ;
}
}
}
}
static int F_47 ( struct V_1 * V_2 , bool V_135 )
{
int V_92 , V_136 = F_1 ( V_2 ) ;
V_92 = F_10 ( V_2 ) ;
if ( V_92 )
return V_92 ;
if ( ! F_1 ( V_2 ) ) {
F_37 ( V_2 ) ;
V_2 -> V_106 = 0 ;
return 0 ;
}
if ( V_135 )
return 0 ;
if ( ! V_2 -> V_106 ||
V_136 != F_1 ( V_2 ) ) {
V_92 = F_13 ( V_2 ) ;
if ( V_92 )
return V_92 ;
F_26 ( V_2 ) ;
}
if ( ! V_2 -> V_116 . V_112 ) {
V_92 = F_33 ( V_2 ) ;
if ( V_92 )
return V_92 ;
}
V_92 = F_6 ( V_2 ) ;
if ( V_92 )
return V_92 ;
F_42 ( V_2 ) ;
if ( ( V_2 -> V_11 & V_51 ) ||
( F_7 ( V_53 , & V_2 -> V_54 ) &&
( V_2 -> V_12 <= V_2 -> V_55 ) ) )
F_48 ( & V_2 -> V_3 -> V_112 , 0 ) ;
return V_92 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_67 ;
if ( ! V_2 -> V_116 . V_112 )
return;
V_67 = V_2 -> V_67 ;
F_13 ( V_2 ) ;
if ( V_67 == V_2 -> V_67 )
return;
F_37 ( V_2 ) ;
F_33 ( V_2 ) ;
}
static int F_50 ( struct V_137 * V_138 , int V_92 )
{
struct V_1 * V_2 = V_138 -> V_127 ;
if ( V_92 )
goto V_139;
F_51 ( V_138 , L_24 ,
F_1 ( V_2 ) ? L_25 : L_26 ) ;
if ( ! F_1 ( V_2 ) )
goto V_139;
if ( V_2 -> V_15 == V_13 )
F_51 ( V_138 , L_27 ) ;
else
F_51 ( V_138 , L_28 ,
V_2 -> V_15 ,
F_8 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_51 ( V_138 , L_29 ) ;
else
F_51 ( V_138 , L_30 ,
V_2 -> V_14 ,
F_8 ( V_2 ) ) ;
F_51 ( V_138 , L_31 ,
( ! V_2 -> V_140 ) ? L_32 : L_33 ) ;
if ( V_2 -> V_37 == V_13 )
F_51 ( V_138 , L_34 ) ;
else
F_51 ( V_138 , L_35 ,
V_2 -> V_37 ) ;
F_51 ( V_138 , L_36 ,
V_2 -> V_105 ,
F_8 ( V_2 ) ) ;
F_51 ( V_138 , L_37 ,
V_2 -> V_141 ,
F_8 ( V_2 ) ) ;
F_51 ( V_138 , L_38 , V_2 -> V_35 ) ;
F_51 ( V_138 , L_39 ,
V_2 -> V_142 ,
F_8 ( V_2 ) ) ;
F_51 ( V_138 , L_40 ,
V_2 -> V_143 ,
F_8 ( V_2 ) ) ;
F_51 ( V_138 , L_41 , V_2 -> V_61 ) ;
F_51 ( V_138 , L_42 , V_2 -> V_65 ) ;
F_51 ( V_138 , L_43 , V_2 -> type ) ;
F_51 ( V_138 , L_44 , V_2 -> V_63 ) ;
V_139:
if ( V_92 )
F_51 ( V_138 , L_45 ) ;
return V_92 ;
}
static int F_52 ( struct V_137 * V_138 , int V_92 )
{
struct V_1 * V_2 = V_138 -> V_127 ;
if ( V_92 )
goto V_139;
F_51 ( V_138 , L_24 ,
F_1 ( V_2 ) ? L_25 : L_26 ) ;
if ( ! F_1 ( V_2 ) )
goto V_139;
F_51 ( V_138 , L_46 ,
( V_2 -> V_11 & 0x04 ) ? L_47 : L_48 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_51 ( V_138 ,
L_49 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_51 ( V_138 , L_50 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_51 ( V_138 , L_51 ) ;
else
F_51 ( V_138 , L_52 ) ;
if ( V_2 -> V_42 == V_13 )
F_51 ( V_138 , L_53 ) ;
else
F_51 ( V_138 , L_54 ,
V_2 -> V_42 , F_8 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_51 ( V_138 , L_55 ) ;
else
F_51 ( V_138 , L_56 ,
V_2 -> V_12 , F_8 ( V_2 ) ) ;
if ( V_2 -> V_39 == V_13 )
F_51 ( V_138 , L_57 ) ;
else
F_51 ( V_138 , L_58 ,
V_2 -> V_39 ) ;
V_139:
if ( V_92 )
F_51 ( V_138 , L_59 ) ;
return V_92 ;
}
static int F_53 ( struct V_137 * V_138 , int V_92 )
{
struct V_1 * V_2 = V_138 -> V_127 ;
if ( V_92 )
goto V_139;
if ( ! F_1 ( V_2 ) ) {
F_51 ( V_138 , L_60 ) ;
goto V_139;
}
F_51 ( V_138 , L_61 ) ;
if ( ! V_2 -> V_55 )
F_51 ( V_138 , L_62 ) ;
else
F_51 ( V_138 , L_63 , V_2 -> V_55 ,
F_8 ( V_2 ) ) ;
V_139:
if ( V_92 )
F_51 ( V_138 , L_64 ) ;
return V_92 ;
}
static T_3 F_54 ( struct V_144 * V_144 ,
const char T_5 * V_96 ,
T_4 V_78 , T_6 * V_145 )
{
int V_92 = 0 ;
char V_146 [ 12 ] = { '\0' } ;
struct V_137 * V_147 = V_144 -> V_148 ;
struct V_1 * V_2 = V_147 -> V_127 ;
if ( ! V_2 || ( V_78 > sizeof( V_146 ) - 1 ) )
return - V_66 ;
if ( ! F_1 ( V_2 ) ) {
V_92 = - V_24 ;
goto V_139;
}
if ( F_55 ( V_146 , V_96 , V_78 ) ) {
V_92 = - V_77 ;
goto V_139;
}
V_146 [ V_78 ] = '\0' ;
if ( F_56 ( V_146 , 0 , & V_2 -> V_55 ) ) {
V_92 = - V_66 ;
goto V_139;
}
V_92 = F_23 ( V_2 ) ;
V_139:
if ( ! V_92 )
return V_78 ;
return V_92 ;
}
static int F_57 ( int V_149 , struct V_137 * V_138 )
{
struct V_1 * V_2 = V_138 -> V_127 ;
int V_92 = F_47 ( V_2 , false ) ;
return V_150 [ V_149 ] ( V_138 , V_92 ) ;
}
static int F_58 ( struct V_151 * V_3 )
{
struct V_152 * V_153 = NULL ;
int V_74 ;
F_59 (KERN_WARNING PREFIX L_65
L_66 ) ;
if ( ! F_60 ( V_3 ) ) {
F_60 ( V_3 ) = F_61 ( F_34 ( V_3 ) ,
V_154 ) ;
if ( ! F_60 ( V_3 ) )
return - V_24 ;
}
for ( V_74 = 0 ; V_74 < V_155 ; ++ V_74 ) {
V_153 = F_62 ( V_156 [ V_74 ] . V_93 ,
V_156 [ V_74 ] . V_80 ,
F_60 ( V_3 ) ,
& V_156 [ V_74 ] . V_157 ,
F_63 ( V_3 ) ) ;
if ( ! V_153 )
return - V_24 ;
}
return 0 ;
}
static void F_64 ( struct V_151 * V_3 )
{
int V_74 ;
if ( ! F_60 ( V_3 ) )
return;
for ( V_74 = 0 ; V_74 < V_155 ; ++ V_74 )
F_65 ( V_156 [ V_74 ] . V_93 ,
F_60 ( V_3 ) ) ;
F_65 ( F_34 ( V_3 ) , V_154 ) ;
F_60 ( V_3 ) = NULL ;
}
static void F_66 ( struct V_151 * V_3 , T_7 V_158 )
{
struct V_1 * V_2 = F_63 ( V_3 ) ;
struct V_3 * V_159 ;
if ( ! V_2 )
return;
V_159 = V_2 -> V_116 . V_112 ;
if ( V_160 > 0 )
F_67 ( V_160 ) ;
if ( V_158 == V_161 )
F_49 ( V_2 ) ;
F_47 ( V_2 , false ) ;
F_68 ( V_3 -> V_162 . V_163 ,
F_69 ( & V_3 -> V_112 ) , V_158 ,
F_1 ( V_2 ) ) ;
F_70 ( V_3 , V_158 , F_1 ( V_2 ) ) ;
if ( V_159 && V_2 -> V_116 . V_112 )
F_71 ( & V_2 -> V_116 ) ;
}
static int F_72 ( struct V_164 * V_165 ,
unsigned long V_80 , void * V_166 )
{
struct V_1 * V_2 = F_73 ( V_165 , struct V_1 ,
V_167 ) ;
int V_92 ;
switch ( V_80 ) {
case V_168 :
case V_169 :
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_116 . V_112 ) {
V_92 = F_13 ( V_2 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_33 ( V_2 ) ;
if ( V_92 )
return V_92 ;
} else
F_49 ( V_2 ) ;
F_26 ( V_2 ) ;
F_6 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_74 ( const struct V_170 * V_171 )
{
V_100 = 1 ;
return 0 ;
}
static int F_75 ( const struct V_170 * V_171 )
{
V_160 = 1000 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_172 , V_22 ;
for ( V_172 = 5 ; V_172 ; V_172 -- ) {
V_22 = F_47 ( V_2 , false ) ;
if ( ! V_22 )
break;
F_67 ( 20 ) ;
}
return V_22 ;
}
static int F_77 ( struct V_151 * V_3 )
{
int V_92 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_3 )
return - V_66 ;
V_2 = F_78 ( sizeof( struct V_1 ) , V_173 ) ;
if ( ! V_2 )
return - V_174 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_79 ( V_3 ) , V_175 ) ;
strcpy ( F_80 ( V_3 ) , V_176 ) ;
V_3 -> V_177 = V_2 ;
F_81 ( & V_2 -> V_98 ) ;
F_81 ( & V_2 -> V_124 ) ;
if ( F_27 ( V_2 -> V_3 -> V_99 , L_9 ) )
F_29 ( V_94 , & V_2 -> V_54 ) ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 )
goto V_178;
#ifdef F_82
V_92 = F_58 ( V_3 ) ;
#endif
if ( V_92 ) {
#ifdef F_82
F_64 ( V_3 ) ;
#endif
goto V_178;
}
F_59 (KERN_INFO PREFIX L_67 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_68 : L_69 ) ;
V_2 -> V_167 . V_179 = F_72 ;
F_83 ( & V_2 -> V_167 ) ;
F_84 ( & V_3 -> V_112 , 1 ) ;
return V_92 ;
V_178:
F_37 ( V_2 ) ;
F_85 ( & V_2 -> V_98 ) ;
F_85 ( & V_2 -> V_124 ) ;
F_19 ( V_2 ) ;
return V_92 ;
}
static int F_86 ( struct V_151 * V_3 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_63 ( V_3 ) )
return - V_66 ;
F_84 ( & V_3 -> V_112 , 0 ) ;
V_2 = F_63 ( V_3 ) ;
F_87 ( & V_2 -> V_167 ) ;
#ifdef F_82
F_64 ( V_3 ) ;
#endif
F_37 ( V_2 ) ;
F_85 ( & V_2 -> V_98 ) ;
F_85 ( & V_2 -> V_124 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_3 * V_112 )
{
struct V_1 * V_2 ;
if ( ! V_112 )
return - V_66 ;
V_2 = F_63 ( F_89 ( V_112 ) ) ;
if ( ! V_2 )
return - V_66 ;
V_2 -> V_106 = 0 ;
F_47 ( V_2 , true ) ;
return 0 ;
}
static void T_8 F_90 ( void * V_180 , T_9 V_181 )
{
if ( V_182 )
return;
F_91 ( V_183 ) ;
#ifdef F_82
V_154 = F_92 () ;
if ( ! V_154 )
return;
#endif
if ( F_93 ( & V_184 ) < 0 ) {
#ifdef F_82
F_94 ( V_154 ) ;
#endif
return;
}
return;
}
static int T_8 F_95 ( void )
{
F_96 ( F_90 , NULL ) ;
return 0 ;
}
static void T_10 F_97 ( void )
{
F_98 ( & V_184 ) ;
#ifdef F_82
F_94 ( V_154 ) ;
#endif
}
