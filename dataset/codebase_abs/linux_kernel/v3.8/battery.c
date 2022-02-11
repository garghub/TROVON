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
if ( F_13 ( V_93 , & V_2 -> V_84 ) &&
V_2 -> V_56 && V_2 -> V_35 ) {
V_2 -> V_15 = V_2 -> V_15 *
10000 / V_2 -> V_35 ;
V_2 -> V_14 = V_2 -> V_14 *
10000 / V_2 -> V_35 ;
V_2 -> V_94 =
V_2 -> V_94 *
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
if ( V_2 -> V_95 &&
F_20 ( V_96 , V_2 -> V_95 +
F_21 ( V_97 ) ) )
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
V_98 , F_18 ( V_98 ) ) ;
V_2 -> V_95 = V_96 ;
F_19 ( V_86 . V_74 ) ;
if ( V_2 -> V_56 == V_57 &&
V_2 -> V_40 != V_13 &&
( V_99 ) ( V_2 -> V_40 ) < 0 ) {
V_2 -> V_40 = abs ( ( V_99 ) V_2 -> V_40 ) ;
F_22 (KERN_WARNING FW_BUG L_14
L_15 ) ;
}
if ( F_13 ( V_92 , & V_2 -> V_84 )
&& V_2 -> V_12 >= 0 && V_2 -> V_12 <= 100 )
V_2 -> V_12 = ( V_2 -> V_12 *
V_2 -> V_14 ) / 100 ;
if ( F_13 ( V_93 , & V_2 -> V_84 ) &&
V_2 -> V_56 && V_2 -> V_35 ) {
V_2 -> V_12 = V_2 -> V_12 *
10000 / V_2 -> V_35 ;
}
return V_81 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
union V_58 V_100 = { . type = V_75 } ;
struct V_101 V_102 = { 1 , & V_100 } ;
if ( ! F_1 ( V_2 ) ||
! F_13 ( V_103 , & V_2 -> V_84 ) )
return - V_24 ;
V_100 . integer . V_76 = V_2 -> V_104 ;
F_14 ( & V_2 -> V_88 ) ;
V_4 = F_15 ( V_2 -> V_3 -> V_89 , L_16 ,
& V_102 , NULL ) ;
F_16 ( & V_2 -> V_88 ) ;
if ( F_17 ( V_4 ) )
return - V_24 ;
F_24 ( ( V_105 , L_17 , V_2 -> V_104 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_4 = V_106 ;
T_3 V_89 = NULL ;
V_4 = F_26 ( V_2 -> V_3 -> V_89 , L_16 , & V_89 ) ;
if ( F_17 ( V_4 ) ) {
F_27 ( V_103 , & V_2 -> V_84 ) ;
return 0 ;
}
F_28 ( V_103 , & V_2 -> V_84 ) ;
if ( ! V_2 -> V_104 )
V_2 -> V_104 = V_2 -> V_94 ;
return F_23 ( V_2 ) ;
}
static T_4 F_29 ( struct V_3 * V_107 ,
struct V_108 * V_109 ,
char * V_110 )
{
struct V_1 * V_2 = F_5 ( F_30 ( V_107 ) ) ;
return sprintf ( V_110 , L_18 , V_2 -> V_104 * 1000 ) ;
}
static T_4 F_31 ( struct V_3 * V_107 ,
struct V_108 * V_109 ,
const char * V_110 , T_5 V_67 )
{
unsigned long V_78 ;
struct V_1 * V_2 = F_5 ( F_30 ( V_107 ) ) ;
if ( sscanf ( V_110 , L_19 , & V_78 ) == 1 )
V_2 -> V_104 = V_78 / 1000 ;
if ( F_1 ( V_2 ) )
F_23 ( V_2 ) ;
return V_67 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_81 ;
if ( V_2 -> V_56 == V_57 ) {
V_2 -> V_111 . V_112 = V_113 ;
V_2 -> V_111 . V_114 =
F_18 ( V_113 ) ;
} else {
V_2 -> V_111 . V_112 = V_115 ;
V_2 -> V_111 . V_114 =
F_18 ( V_115 ) ;
}
V_2 -> V_111 . V_82 = F_33 ( V_2 -> V_3 ) ;
V_2 -> V_111 . type = V_116 ;
V_2 -> V_111 . V_117 = F_4 ;
V_81 = F_34 ( & V_2 -> V_3 -> V_107 , & V_2 -> V_111 ) ;
if ( V_81 )
return V_81 ;
return F_35 ( V_2 -> V_111 . V_107 , & V_118 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_119 ) ;
if ( ! V_2 -> V_111 . V_107 ) {
F_16 ( & V_2 -> V_119 ) ;
return;
}
F_37 ( V_2 -> V_111 . V_107 , & V_118 ) ;
F_38 ( & V_2 -> V_111 ) ;
V_2 -> V_111 . V_107 = NULL ;
F_16 ( & V_2 -> V_119 ) ;
}
static void F_39 ( const struct V_120 * V_121 , void * V_122 )
{
struct V_1 * V_2 = (struct V_1 * ) V_122 ;
if ( V_121 -> type == V_123 && V_121 -> V_124 >= 8 ) {
const T_1 * V_125 = ( const T_1 * ) ( V_121 + 1 ) ;
int V_126 = F_40 ( ( const V_127 * ) ( V_125 + 6 ) ) ;
if ( V_121 -> V_124 >= 18 )
V_126 *= V_125 [ 17 ] ;
if ( V_2 -> V_15 * V_2 -> V_35 / 1000
!= V_126 &&
V_2 -> V_15 * 10 == V_126 )
F_28 ( V_93 ,
& V_2 -> V_84 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
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
if ( F_13 ( V_93 , & V_2 -> V_84 ) )
return ;
if ( V_2 -> V_56 && F_42 ( L_20 ) ) {
const char * V_128 ;
V_128 = F_43 ( V_129 ) ;
if ( V_128 && ! F_44 ( V_128 , L_21 , 8 ) ) {
F_45 ( F_39 , V_2 ) ;
if ( F_13 ( V_93 ,
& V_2 -> V_84 ) &&
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
int V_81 , V_130 = F_1 ( V_2 ) ;
V_81 = F_9 ( V_2 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_1 ( V_2 ) ) {
F_36 ( V_2 ) ;
V_2 -> V_95 = 0 ;
return 0 ;
}
if ( ! V_2 -> V_95 ||
V_130 != F_1 ( V_2 ) ) {
V_81 = F_12 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_25 ( V_2 ) ;
}
if ( ! V_2 -> V_111 . V_107 ) {
V_81 = F_32 ( V_2 ) ;
if ( V_81 )
return V_81 ;
}
V_81 = F_6 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_81 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_56 ;
if ( ! V_2 -> V_111 . V_107 )
return;
V_56 = V_2 -> V_56 ;
F_12 ( V_2 ) ;
if ( V_56 == V_2 -> V_56 )
return;
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_48 ( struct V_131 * V_132 , int V_81 )
{
struct V_1 * V_2 = V_132 -> V_122 ;
if ( V_81 )
goto V_133;
F_49 ( V_132 , L_22 ,
F_1 ( V_2 ) ? L_23 : L_24 ) ;
if ( ! F_1 ( V_2 ) )
goto V_133;
if ( V_2 -> V_15 == V_13 )
F_49 ( V_132 , L_25 ) ;
else
F_49 ( V_132 , L_26 ,
V_2 -> V_15 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_14 == V_13 )
F_49 ( V_132 , L_27 ) ;
else
F_49 ( V_132 , L_28 ,
V_2 -> V_14 ,
F_7 ( V_2 ) ) ;
F_49 ( V_132 , L_29 ,
( ! V_2 -> V_134 ) ? L_30 : L_31 ) ;
if ( V_2 -> V_35 == V_13 )
F_49 ( V_132 , L_32 ) ;
else
F_49 ( V_132 , L_33 ,
V_2 -> V_35 ) ;
F_49 ( V_132 , L_34 ,
V_2 -> V_94 ,
F_7 ( V_2 ) ) ;
F_49 ( V_132 , L_35 ,
V_2 -> V_135 ,
F_7 ( V_2 ) ) ;
F_49 ( V_132 , L_36 , V_2 -> V_33 ) ;
F_49 ( V_132 , L_37 ,
V_2 -> V_136 ,
F_7 ( V_2 ) ) ;
F_49 ( V_132 , L_38 ,
V_2 -> V_137 ,
F_7 ( V_2 ) ) ;
F_49 ( V_132 , L_39 , V_2 -> V_50 ) ;
F_49 ( V_132 , L_40 , V_2 -> V_54 ) ;
F_49 ( V_132 , L_41 , V_2 -> type ) ;
F_49 ( V_132 , L_42 , V_2 -> V_52 ) ;
V_133:
if ( V_81 )
F_49 ( V_132 , L_43 ) ;
return V_81 ;
}
static int F_50 ( struct V_131 * V_132 , int V_81 )
{
struct V_1 * V_2 = V_132 -> V_122 ;
if ( V_81 )
goto V_133;
F_49 ( V_132 , L_22 ,
F_1 ( V_2 ) ? L_23 : L_24 ) ;
if ( ! F_1 ( V_2 ) )
goto V_133;
F_49 ( V_132 , L_44 ,
( V_2 -> V_11 & 0x04 ) ? L_45 : L_46 ) ;
if ( ( V_2 -> V_11 & 0x01 ) && ( V_2 -> V_11 & 0x02 ) )
F_49 ( V_132 ,
L_47 ) ;
else if ( V_2 -> V_11 & 0x01 )
F_49 ( V_132 , L_48 ) ;
else if ( V_2 -> V_11 & 0x02 )
F_49 ( V_132 , L_49 ) ;
else
F_49 ( V_132 , L_50 ) ;
if ( V_2 -> V_40 == V_13 )
F_49 ( V_132 , L_51 ) ;
else
F_49 ( V_132 , L_52 ,
V_2 -> V_40 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_12 == V_13 )
F_49 ( V_132 , L_53 ) ;
else
F_49 ( V_132 , L_54 ,
V_2 -> V_12 , F_7 ( V_2 ) ) ;
if ( V_2 -> V_37 == V_13 )
F_49 ( V_132 , L_55 ) ;
else
F_49 ( V_132 , L_56 ,
V_2 -> V_37 ) ;
V_133:
if ( V_81 )
F_49 ( V_132 , L_57 ) ;
return V_81 ;
}
static int F_51 ( struct V_131 * V_132 , int V_81 )
{
struct V_1 * V_2 = V_132 -> V_122 ;
if ( V_81 )
goto V_133;
if ( ! F_1 ( V_2 ) ) {
F_49 ( V_132 , L_58 ) ;
goto V_133;
}
F_49 ( V_132 , L_59 ) ;
if ( ! V_2 -> V_104 )
F_49 ( V_132 , L_60 ) ;
else
F_49 ( V_132 , L_61 , V_2 -> V_104 ,
F_7 ( V_2 ) ) ;
V_133:
if ( V_81 )
F_49 ( V_132 , L_62 ) ;
return V_81 ;
}
static T_4 F_52 ( struct V_138 * V_138 ,
const char T_6 * V_86 ,
T_5 V_67 , T_7 * V_139 )
{
int V_81 = 0 ;
char V_140 [ 12 ] = { '\0' } ;
struct V_131 * V_141 = V_138 -> V_142 ;
struct V_1 * V_2 = V_141 -> V_122 ;
if ( ! V_2 || ( V_67 > sizeof( V_140 ) - 1 ) )
return - V_55 ;
if ( ! F_1 ( V_2 ) ) {
V_81 = - V_24 ;
goto V_133;
}
if ( F_53 ( V_140 , V_86 , V_67 ) ) {
V_81 = - V_66 ;
goto V_133;
}
V_140 [ V_67 ] = '\0' ;
V_2 -> V_104 = F_54 ( V_140 , NULL , 0 ) ;
V_81 = F_23 ( V_2 ) ;
V_133:
if ( ! V_81 )
return V_67 ;
return V_81 ;
}
static int F_55 ( int V_143 , struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_122 ;
int V_81 = F_46 ( V_2 ) ;
return V_144 [ V_143 ] ( V_132 , V_81 ) ;
}
static int F_56 ( struct V_145 * V_3 )
{
struct V_146 * V_147 = NULL ;
int V_63 ;
F_57 (KERN_WARNING PREFIX L_63
L_64 ) ;
if ( ! F_58 ( V_3 ) ) {
F_58 ( V_3 ) = F_59 ( F_33 ( V_3 ) ,
V_148 ) ;
if ( ! F_58 ( V_3 ) )
return - V_24 ;
}
for ( V_63 = 0 ; V_63 < V_149 ; ++ V_63 ) {
V_147 = F_60 ( V_150 [ V_63 ] . V_82 ,
V_150 [ V_63 ] . V_69 ,
F_58 ( V_3 ) ,
& V_150 [ V_63 ] . V_151 ,
F_61 ( V_3 ) ) ;
if ( ! V_147 )
return - V_24 ;
}
return 0 ;
}
static void F_62 ( struct V_145 * V_3 )
{
int V_63 ;
if ( ! F_58 ( V_3 ) )
return;
for ( V_63 = 0 ; V_63 < V_149 ; ++ V_63 )
F_63 ( V_150 [ V_63 ] . V_82 ,
F_58 ( V_3 ) ) ;
F_63 ( F_33 ( V_3 ) , V_148 ) ;
F_58 ( V_3 ) = NULL ;
}
static void F_64 ( struct V_145 * V_3 , T_8 V_152 )
{
struct V_1 * V_2 = F_61 ( V_3 ) ;
struct V_3 * V_153 ;
if ( ! V_2 )
return;
V_153 = V_2 -> V_111 . V_107 ;
if ( V_152 == V_154 )
F_47 ( V_2 ) ;
F_46 ( V_2 ) ;
F_65 ( V_3 , V_152 ,
F_1 ( V_2 ) ) ;
F_66 ( V_3 -> V_155 . V_156 ,
F_67 ( & V_3 -> V_107 ) , V_152 ,
F_1 ( V_2 ) ) ;
if ( V_153 && V_2 -> V_111 . V_107 )
F_68 ( & V_2 -> V_111 ) ;
}
static int F_69 ( struct V_157 * V_158 ,
unsigned long V_69 , void * V_159 )
{
struct V_1 * V_2 = F_70 ( V_158 , struct V_1 ,
V_160 ) ;
switch ( V_69 ) {
case V_161 :
case V_162 :
if ( V_2 -> V_111 . V_107 ) {
F_36 ( V_2 ) ;
F_32 ( V_2 ) ;
}
break;
}
return 0 ;
}
static int F_71 ( struct V_145 * V_3 )
{
int V_81 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_89 ;
if ( ! V_3 )
return - V_55 ;
V_2 = F_72 ( sizeof( struct V_1 ) , V_163 ) ;
if ( ! V_2 )
return - V_164 ;
V_2 -> V_3 = V_3 ;
strcpy ( F_73 ( V_3 ) , V_165 ) ;
strcpy ( F_74 ( V_3 ) , V_166 ) ;
V_3 -> V_167 = V_2 ;
F_75 ( & V_2 -> V_88 ) ;
F_75 ( & V_2 -> V_119 ) ;
if ( F_76 ( F_26 ( V_2 -> V_3 -> V_89 ,
L_9 , & V_89 ) ) )
F_28 ( V_83 , & V_2 -> V_84 ) ;
V_81 = F_46 ( V_2 ) ;
if ( V_81 )
goto V_168;
#ifdef F_77
V_81 = F_56 ( V_3 ) ;
#endif
if ( V_81 ) {
#ifdef F_77
F_62 ( V_3 ) ;
#endif
goto V_168;
}
F_57 (KERN_INFO PREFIX L_65 ,
ACPI_BATTERY_DEVICE_NAME, acpi_device_bid(device),
device->status.battery_present ? L_66 : L_67 ) ;
V_2 -> V_160 . V_169 = F_69 ;
F_78 ( & V_2 -> V_160 ) ;
return V_81 ;
V_168:
F_36 ( V_2 ) ;
F_79 ( & V_2 -> V_88 ) ;
F_79 ( & V_2 -> V_119 ) ;
F_19 ( V_2 ) ;
return V_81 ;
}
static int F_80 ( struct V_145 * V_3 , int type )
{
struct V_1 * V_2 = NULL ;
if ( ! V_3 || ! F_61 ( V_3 ) )
return - V_55 ;
V_2 = F_61 ( V_3 ) ;
F_81 ( & V_2 -> V_160 ) ;
#ifdef F_77
F_62 ( V_3 ) ;
#endif
F_36 ( V_2 ) ;
F_79 ( & V_2 -> V_88 ) ;
F_79 ( & V_2 -> V_119 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_3 * V_107 )
{
struct V_1 * V_2 ;
if ( ! V_107 )
return - V_55 ;
V_2 = F_61 ( F_83 ( V_107 ) ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_95 = 0 ;
F_46 ( V_2 ) ;
return 0 ;
}
static void T_9 F_84 ( void * V_170 , T_10 V_171 )
{
if ( V_172 )
return;
#ifdef F_77
V_148 = F_85 () ;
if ( ! V_148 )
return;
#endif
if ( F_86 ( & V_173 ) < 0 ) {
#ifdef F_77
F_87 ( V_148 ) ;
#endif
return;
}
return;
}
static int T_9 F_88 ( void )
{
F_89 ( F_84 , NULL ) ;
return 0 ;
}
static void T_11 F_90 ( void )
{
F_91 ( & V_173 ) ;
#ifdef F_77
F_87 ( V_148 ) ;
#endif
}
