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
if ( V_90 )
V_81 = F_8 ( V_2 , V_86 . V_74 ,
V_91 + 1 ,
F_18 ( V_91 ) - 1 ) ;
else if ( F_13 ( V_83 , & V_2 -> V_84 ) )
V_81 = F_8 ( V_2 , V_86 . V_74 ,
V_91 ,
F_18 ( V_91 ) ) ;
else
V_81 = F_8 ( V_2 , V_86 . V_74 ,
V_92 , F_18 ( V_92 ) ) ;
F_19 ( V_86 . V_74 ) ;
if ( F_13 ( V_93 , & V_2 -> V_84 ) )
V_2 -> V_14 = V_2 -> V_15 ;
if ( F_13 ( V_94 , & V_2 -> V_84 ) &&
V_2 -> V_56 && V_2 -> V_35 ) {
V_2 -> V_15 = V_2 -> V_15 *
10000 / V_2 -> V_35 ;
V_2 -> V_14 = V_2 -> V_14 *
10000 / V_2 -> V_35 ;
V_2 -> V_95 =
V_2 -> V_95 *
10000 / V_2 -> V_35 ;
}
return V_81 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
T_2 V_4 = 0 ;
struct V_85 V_86 = { V_87 , NULL } ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_96 &&
F_20 ( V_97 , V_2 -> V_96 +
F_21 ( V_98 ) ) )
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
V_99 , F_18 ( V_99 ) ) ;
V_2 -> V_96 = V_97 ;
F_19 ( V_86 . V_74 ) ;
if ( V_2 -> V_56 == V_57 &&
V_2 -> V_40 != V_13 &&
( V_100 ) ( V_2 -> V_40 ) < 0 ) {
V_2 -> V_40 = abs ( ( V_100 ) V_2 -> V_40 ) ;
F_22 (KERN_WARNING FW_BUG L_14
L_15 ) ;
}
if ( F_13 ( V_93 , & V_2 -> V_84 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
if ( F_13 ( V_94 , & V_2 -> V_84 ) &&
V_2 -> V_56 && V_2 -> V_35 ) {
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_35 ;
}
return V_81 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
if ( ! F_1 ( V_2 ) ||
! F_13 ( V_101 , & V_2 -> V_84 ) )
return - V_24 ;
F_14 ( & V_2 -> V_88 ) ;
V_4 = F_24 ( V_2 -> V_3 -> V_89 , L_16 ,
V_2 -> V_102 ) ;
F_16 ( & V_2 -> V_88 ) ;
if ( F_17 ( V_4 ) )
return - V_24 ;
F_25 ( ( V_103 , L_17 , V_2 -> V_102 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( ! F_27 ( V_2 -> V_3 -> V_89 , L_16 ) ) {
F_28 ( V_101 , & V_2 -> V_84 ) ;
return 0 ;
}
F_29 ( V_101 , & V_2 -> V_84 ) ;
if ( ! V_2 -> V_102 )
V_2 -> V_102 = V_2 -> V_95 ;
return F_23 ( V_2 ) ;
}
static T_3 F_30 ( struct V_3 * V_104 ,
struct V_105 * V_106 ,
char * V_107 )
{
struct V_1 * V_2 = F_5 ( F_31 ( V_104 ) ) ;
return sprintf ( V_107 , L_18 , V_2 -> V_102 * 1000 ) ;
}
static T_3 F_32 ( struct V_3 * V_104 ,
struct V_105 * V_106 ,
const char * V_107 , T_4 V_67 )
{
unsigned long V_78 ;
struct V_1 * V_2 = F_5 ( F_31 ( V_104 ) ) ;
if ( sscanf ( V_107 , L_19 , & V_78 ) == 1 )
V_2 -> V_102 = V_78 / 1000 ;
if ( F_1 ( V_2 ) )
F_23 ( V_2 ) ;
return V_67 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_81 ;
if ( V_2 -> V_56 == V_57 ) {
V_2 -> V_108 . V_109 = V_110 ;
V_2 -> V_108 . V_111 =
F_18 ( V_110 ) ;
} else {
V_2 -> V_108 . V_109 = V_112 ;
V_2 -> V_108 . V_111 =
F_18 ( V_112 ) ;
}
V_2 -> V_108 . V_82 = F_34 ( V_2 -> V_3 ) ;
V_2 -> V_108 . type = V_113 ;
V_2 -> V_108 . V_114 = F_4 ;
V_81 = F_35 ( & V_2 -> V_3 -> V_104 , & V_2 -> V_108 ) ;
if ( V_81 )
return V_81 ;
return F_36 ( V_2 -> V_108 . V_104 , & V_115 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_116 ) ;
if ( ! V_2 -> V_108 . V_104 ) {
F_16 ( & V_2 -> V_116 ) ;
return;
}
F_38 ( V_2 -> V_108 . V_104 , & V_115 ) ;
F_39 ( & V_2 -> V_108 ) ;
V_2 -> V_108 . V_104 = NULL ;
F_16 ( & V_2 -> V_116 ) ;
}
static void F_40 ( const struct V_117 * V_118 , void * V_119 )
{
struct V_1 * V_2 = (struct V_1 * ) V_119 ;
if ( V_118 -> type == V_120 && V_118 -> V_121 >= 8 ) {
const T_1 * V_122 = ( const T_1 * ) ( V_118 + 1 ) ;
int V_123 = F_41 ( ( const V_124 * ) ( V_122 + 6 ) ) ;
if ( V_118 -> V_121 >= 18 )
V_123 *= V_122 [ 17 ] ;
if ( V_2 -> V_15 * V_2 -> V_35 / 1000
!= V_123 &&
V_2 -> V_15 * 10 == V_123 )
F_29 ( V_94 ,
& V_2 -> V_84 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
if ( F_13 ( V_93 , & V_2 -> V_84 ) )
return;
if ( V_2 -> V_14 == 100 &&
V_2 -> V_40 == V_13 &&
V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 ) {
F_29 ( V_93 , & V_2 -> V_84 ) ;
V_2 -> V_14 = V_2 -> V_15 ;
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
}
if ( F_13 ( V_94 , & V_2 -> V_84 ) )
return;
if ( V_2 -> V_56 && F_43 ( L_20 ) ) {
const char * V_125 ;
V_125 = F_44 ( V_126 ) ;
if ( V_125 && ! F_45 ( V_125 , L_21 , 8 ) ) {
F_46 ( F_40 , V_2 ) ;
if ( F_13 ( V_94 ,
& V_2 -> V_84 ) &&
V_2 -> V_35 ) {
V_2 -> V_15 =
V_2 -> V_15 *
10000 / V_2 -> V_35 ;
V_2 -> V_14 =
V_2 -> V_14 *
10000 / V_2 -> V_35 ;
V_2 -> V_95 =
V_2 -> V_95 *
10000 / V_2 -> V_35 ;
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_35 ;
}
}
}
}
static int F_47 ( struct V_1 * V_2 )
{
int V_81 , V_127 = F_1 ( V_2 ) ;
V_81 = F_9 ( V_2 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_1 ( V_2 ) ) {
F_37 ( V_2 ) ;
V_2 -> V_96 = 0 ;
return 0 ;
}
if ( ! V_2 -> V_96 ||
V_127 != F_1 ( V_2 ) ) {
V_81 = F_12 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_26 ( V_2 ) ;
}
if ( ! V_2 -> V_108 . V_104 ) {
V_81 = F_33 ( V_2 ) ;
if ( V_81 )
return V_81 ;
}
V_81 = F_6 ( V_2 ) ;
F_42 ( V_2 ) ;
return V_81 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_56 ;
if ( ! V_2 -> V_108 . V_104 )
return;
V_56 = V_2 -> V_56 ;
F_12 ( V_2 ) ;
if ( V_56 == V_2 -> V_56 )
return;
F_37 ( V_2 ) ;
F_33 ( V_2 ) ;
}
static int F_49 ( struct V_128 * V_129 , int V_81 )
{
struct V_1 * V_2 = V_129 -> V_119 ;
if ( V_81 )
goto V_130;
F_50 ( V_129 , L_22 ,
F_1 ( V_2 ) ? L_23 : L_24 ) ;
if ( ! F_1 ( V_2 ) )
goto V_130;
if ( V_2 -> V_15 == V_13 )
F_50 ( V_129 , L_25 ) ;
else
F_50 ( V_129 , L_26 ,
V_2 -> V_15 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_50 ( V_129 , L_27 ) ;
else
F_50 ( V_129 , L_28 ,
V_2 -> V_14 ,
F_7 ( V_2 ) ) ;
F_50 ( V_129 , L_29 ,
( ! V_2 -> V_131 ) ? L_30 : L_31 ) ;
if ( V_2 -> V_35 == V_13 )
F_50 ( V_129 , L_32 ) ;
else
F_50 ( V_129 , L_33 ,
V_2 -> V_35 ) ;
F_50 ( V_129 , L_34 ,
V_2 -> V_95 ,
F_7 ( V_2 ) ) ;
F_50 ( V_129 , L_35 ,
V_2 -> V_132 ,
F_7 ( V_2 ) ) ;
F_50 ( V_129 , L_36 , V_2 -> V_33 ) ;
F_50 ( V_129 , L_37 ,
V_2 -> V_133 ,
F_7 ( V_2 ) ) ;
F_50 ( V_129 , L_38 ,
V_2 -> V_134 ,
F_7 ( V_2 ) ) ;
F_50 ( V_129 , L_39 , V_2 -> V_50 ) ;
F_50 ( V_129 , L_40 , V_2 -> V_54 ) ;
F_50 ( V_129 , L_41 , V_2 -> type ) ;
F_50 ( V_129 , L_42 , V_2 -> V_52 ) ;
V_130:
if ( V_81 )
F_50 ( V_129 , L_43 ) ;
return V_81 ;
}
static int F_51 ( struct V_128 * V_129 , int V_81 )
{
struct V_1 * V_2 = V_129 -> V_119 ;
if ( V_81 )
goto V_130;
F_50 ( V_129 , L_22 ,
F_1 ( V_2 ) ? L_23 : L_24 ) ;
if ( ! F_1 ( V_2 ) )
goto V_130;
F_50 ( V_129 , L_44 ,
( V_2 -> V_11 & 0x04 ) ? L_45 : L_46 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_50 ( V_129 ,
L_47 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_50 ( V_129 , L_48 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_50 ( V_129 , L_49 ) ;
else
F_50 ( V_129 , L_50 ) ;
if ( V_2 -> V_40 == V_13 )
F_50 ( V_129 , L_51 ) ;
else
F_50 ( V_129 , L_52 ,
V_2 -> V_40 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_50 ( V_129 , L_53 ) ;
else
F_50 ( V_129 , L_54 ,
V_2 -> V_12 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_37 == V_13 )
F_50 ( V_129 , L_55 ) ;
else
F_50 ( V_129 , L_56 ,
V_2 -> V_37 ) ;
V_130:
if ( V_81 )
F_50 ( V_129 , L_57 ) ;
return V_81 ;
}
static int F_52 ( struct V_128 * V_129 , int V_81 )
{
struct V_1 * V_2 = V_129 -> V_119 ;
if ( V_81 )
goto V_130;
if ( ! F_1 ( V_2 ) ) {
F_50 ( V_129 , L_58 ) ;
goto V_130;
}
F_50 ( V_129 , L_59 ) ;
if ( ! V_2 -> V_102 )
F_50 ( V_129 , L_60 ) ;
else
F_50 ( V_129 , L_61 , V_2 -> V_102 ,
F_7 ( V_2 ) ) ;
V_130:
if ( V_81 )
F_50 ( V_129 , L_62 ) ;
return V_81 ;
}
static T_3 F_53 ( struct V_135 * V_135 ,
const char T_5 * V_86 ,
T_4 V_67 , T_6 * V_136 )
{
int V_81 = 0 ;
char V_137 [ 12 ] = { '\0' } ;
struct V_128 * V_138 = V_135 -> V_139 ;
struct V_1 * V_2 = V_138 -> V_119 ;
if ( ! V_2 || ( V_67 > sizeof( V_137 ) - 1 ) )
return - V_55 ;
if ( ! F_1 ( V_2 ) ) {
V_81 = - V_24 ;
goto V_130;
}
if ( F_54 ( V_137 , V_86 , V_67 ) ) {
V_81 = - V_66 ;
goto V_130;
}
V_137 [ V_67 ] = '\0' ;
V_2 -> V_102 = F_55 ( V_137 , NULL , 0 ) ;
V_81 = F_23 ( V_2 ) ;
V_130:
if ( ! V_81 )
return V_67 ;
return V_81 ;
}
static int F_56 ( int V_140 , struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_119 ;
int V_81 = F_47 ( V_2 ) ;
return V_141 [ V_140 ] ( V_129 , V_81 ) ;
}
static int F_57 ( struct V_142 * V_3 )
{
struct V_143 * V_144 = NULL ;
int V_63 ;
F_58 (KERN_WARNING PREFIX L_63
L_64 ) ;
if ( ! F_59 ( V_3 ) ) {
F_59 ( V_3 ) = F_60 ( F_34 ( V_3 ) ,
V_145 ) ;
if ( ! F_59 ( V_3 ) )
return - V_24 ;
}
for ( V_63 = 0 ; V_63 < V_146 ; ++ V_63 ) {
V_144 = F_61 ( V_147 [ V_63 ] . V_82 ,
V_147 [ V_63 ] . V_69 ,
F_59 ( V_3 ) ,
& V_147 [ V_63 ] . V_148 ,
F_62 ( V_3 ) ) ;
if ( ! V_144 )
return - V_24 ;
}
return 0 ;
}
static void F_63 ( struct V_142 * V_3 )
{
int V_63 ;
if ( ! F_59 ( V_3 ) )
return;
for ( V_63 = 0 ; V_63 < V_146 ; ++ V_63 )
F_64 ( V_147 [ V_63 ] . V_82 ,
F_59 ( V_3 ) ) ;
F_64 ( F_34 ( V_3 ) , V_145 ) ;
F_59 ( V_3 ) = NULL ;
}
static void F_65 ( struct V_142 * V_3 , T_7 V_149 )
{
struct V_1 * V_2 = F_62 ( V_3 ) ;
struct V_3 * V_150 ;
if ( ! V_2 )
return;
V_150 = V_2 -> V_108 . V_104 ;
if ( V_149 == V_151 )
F_48 ( V_2 ) ;
F_47 ( V_2 ) ;
F_66 ( V_3 -> V_152 . V_153 ,
F_67 ( & V_3 -> V_104 ) , V_149 ,
F_1 ( V_2 ) ) ;
F_68 ( V_3 , V_149 , F_1 ( V_2 ) ) ;
if ( V_150 && V_2 -> V_108 . V_104 )
F_69 ( & V_2 -> V_108 ) ;
}
static int F_70 ( struct V_154 * V_155 ,
unsigned long V_69 , void * V_156 )
{
struct V_1 * V_2 = F_71 ( V_155 , struct V_1 ,
V_157 ) ;
switch ( V_69 ) {
case V_158 :
case V_159 :
if ( V_2 -> V_108 . V_104 ) {
F_37 ( V_2 ) ;
F_33 ( V_2 ) ;
}
break;
}
return 0 ;
}
static int F_72 ( struct V_142 * V_3 )
{
int V_81 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_3 )
return - V_55 ;
V_2 = F_73 ( sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_2 )
return - V_161 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_74 ( V_3 ) , V_162 ) ;
strcpy ( F_75 ( V_3 ) , V_163 ) ;
V_3 -> V_164 = V_2 ;
F_76 ( & V_2 -> V_88 ) ;
F_76 ( & V_2 -> V_116 ) ;
if ( F_27 ( V_2 -> V_3 -> V_89 , L_9 ) )
F_29 ( V_83 , & V_2 -> V_84 ) ;
V_81 = F_47 ( V_2 ) ;
if ( V_81 )
goto V_165;
#ifdef F_77
V_81 = F_57 ( V_3 ) ;
#endif
if ( V_81 ) {
#ifdef F_77
F_63 ( V_3 ) ;
#endif
goto V_165;
}
F_58 (KERN_INFO PREFIX L_65 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_66 : L_67 ) ;
V_2 -> V_157 . V_166 = F_70 ;
F_78 ( & V_2 -> V_157 ) ;
return V_81 ;
V_165:
F_37 ( V_2 ) ;
F_79 ( & V_2 -> V_88 ) ;
F_79 ( & V_2 -> V_116 ) ;
F_19 ( V_2 ) ;
return V_81 ;
}
static int F_80 ( struct V_142 * V_3 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_62 ( V_3 ) )
return - V_55 ;
V_2 = F_62 ( V_3 ) ;
F_81 ( & V_2 -> V_157 ) ;
#ifdef F_77
F_63 ( V_3 ) ;
#endif
F_37 ( V_2 ) ;
F_79 ( & V_2 -> V_88 ) ;
F_79 ( & V_2 -> V_116 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_3 * V_104 )
{
struct V_1 * V_2 ;
if ( ! V_104 )
return - V_55 ;
V_2 = F_62 ( F_83 ( V_104 ) ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_96 = 0 ;
F_47 ( V_2 ) ;
return 0 ;
}
static void T_8 F_84 ( void * V_167 , T_9 V_168 )
{
if ( V_169 )
return;
if ( F_85 ( V_170 ) )
V_90 = 1 ;
#ifdef F_77
V_145 = F_86 () ;
if ( ! V_145 )
return;
#endif
if ( F_87 ( & V_171 ) < 0 ) {
#ifdef F_77
F_88 ( V_145 ) ;
#endif
return;
}
return;
}
static int T_8 F_89 ( void )
{
F_90 ( F_84 , NULL ) ;
return 0 ;
}
static void T_10 F_91 ( void )
{
F_92 ( & V_171 ) ;
#ifdef F_77
F_88 ( V_145 ) ;
#endif
}
