struct V_1 * F_1 ( void )
{
return & V_2 ;
}
static T_1 F_2 ( void * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
return F_3 ( V_6 , V_4 ) ;
}
static T_3 F_4 ( void * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
return F_5 ( V_6 , V_4 ) ;
}
static T_2 F_6 ( void * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
return F_7 ( V_6 , V_4 ) ;
}
static void F_8 ( void * V_3 , T_2 V_4 , T_1 V_7 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
F_9 ( V_6 , V_4 , V_7 ) ;
}
static void F_10 ( void * V_3 , T_2 V_4 , T_3 V_7 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
F_11 ( V_6 , V_4 , V_7 ) ;
}
static void F_12 ( void * V_3 , T_2 V_4 , T_2 V_7 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
F_13 ( V_6 , V_4 , V_7 ) ;
}
static bool F_14 ( void * V_3 , T_1 * V_8 , T_2 V_9 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
if ( V_6 -> V_10 -> V_11 -> V_12 &&
V_6 -> V_10 -> V_11 -> V_12 ( V_6 , V_8 ,
V_9 ) )
return true ;
return false ;
}
static bool F_15 ( void * V_3 , T_1 * V_8 , T_2 V_9 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
if ( V_6 -> V_10 -> V_11 -> V_13 &&
V_6 -> V_10 -> V_11 -> V_13 ( V_6 , V_8 , V_9 ) )
return true ;
return false ;
}
static inline bool F_16 ( struct V_5 * V_6 ,
enum V_14 V_15 ,
enum V_16 V_17 )
{
switch ( V_15 ) {
case V_18 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_23 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
if ( V_17 != V_24 ) {
F_17 ( V_6 , V_19 , V_20 ,
L_2 ,
V_21 , V_15 , V_17 ) ;
}
break;
case V_25 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
if ( V_17 != V_24 ) {
F_17 ( V_6 , V_19 , V_20 ,
L_2 ,
V_21 , V_15 , V_17 ) ;
}
break;
case V_26 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_27 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_28 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_29 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_30 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_31 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_32 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
case V_33 :
F_17 ( V_6 , V_19 , V_20 , L_1 , V_21 ,
V_22 [ V_15 ] ) ;
break;
default:
F_17 ( V_6 , V_19 , V_20 ,
L_3 , V_21 , V_15 ) ;
return false ;
}
return true ;
}
static int F_18 ( struct V_5 * V_6 ,
enum V_14 V_15 , T_1 * V_8 ,
T_2 V_9 , T_2 time )
{
struct V_34 * V_35 ;
if ( ! V_6 -> V_36 . V_37 [ V_15 ] . V_35 ) {
V_35 = F_19 ( sizeof( * V_35 ) , V_38 ) ;
if ( ! V_35 )
return - 1 ;
} else {
F_17 ( V_6 , V_19 , V_20 ,
L_4 , V_21 ,
V_15 ) ;
V_35 = V_6 -> V_36 . V_37 [ V_15 ] . V_35 ;
V_6 -> V_36 . V_37 [ V_15 ] . V_35 = NULL ;
}
F_20 ( V_35 ) ;
V_6 -> V_36 . V_37 [ V_15 ] . V_39 = time ;
V_6 -> V_36 . V_37 [ V_15 ] . V_40 = V_8 ;
V_6 -> V_36 . V_37 [ V_15 ] . V_41 = V_9 ;
V_6 -> V_36 . V_37 [ V_15 ] . V_42 = 0 ;
V_6 -> V_36 . V_37 [ V_15 ] . V_17 = 0 ;
V_6 -> V_36 . V_37 [ V_15 ] . V_35 = V_35 ;
return 0 ;
}
static inline int F_21 ( struct V_5 * V_6 ,
enum V_14 V_15 , T_1 * V_8 ,
T_2 V_9 )
{
return F_18 ( V_6 , V_15 , V_8 , V_9 ,
V_43 ) ;
}
static void F_22 ( struct V_5 * V_6 ,
enum V_14 V_15 )
{
struct V_34 * V_35 ;
if ( ! V_6 -> V_36 . V_37 [ V_15 ] . V_35 )
return;
V_35 = V_6 -> V_36 . V_37 [ V_15 ] . V_35 ;
V_6 -> V_36 . V_37 [ V_15 ] . V_35 = NULL ;
F_23 ( V_35 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
enum V_14 V_15 )
{
struct V_34 * V_35 ;
int V_44 ;
V_35 = V_6 -> V_36 . V_37 [ V_15 ] . V_35 ;
if ( ! V_35 )
return - 1 ;
V_44 = F_25 (
V_35 , V_6 -> V_36 . V_37 [ V_15 ] . V_39 ) ;
F_22 ( V_6 , V_15 ) ;
if ( V_44 > 0 )
return 0 ;
return - 1 ;
}
static bool
F_26 ( void * V_3 , enum V_14 V_45 ,
enum V_16 V_46 , T_1 * V_8 ,
T_2 V_9 )
{
struct V_5 * V_6 ;
struct V_47 * V_48 , * V_37 ;
struct V_34 * V_35 ;
T_2 V_49 ;
bool V_44 ;
V_6 = (struct V_5 * ) V_3 ;
V_48 = V_6 -> V_36 . V_37 ;
V_44 = F_16 ( V_6 , V_45 , V_46 ) ;
if ( ! V_44 )
goto exit;
V_37 = & V_48 [ V_45 ] ;
V_37 -> V_17 = V_46 ;
V_37 -> V_42 = V_9 ;
if ( ! V_37 -> V_35 ) {
F_17 ( V_6 , V_19 , V_20 ,
L_5 , V_21 ,
V_45 ) ;
goto exit;
}
V_35 = V_37 -> V_35 ;
if ( V_46 == V_50 ) {
F_17 ( V_6 , V_19 , V_20 ,
L_6 , V_21 ,
V_45 ) ;
F_27 ( V_35 ) ;
goto exit;
}
if ( V_9 > V_37 -> V_41 ) {
F_17 (
V_6 , V_19 , V_20 ,
L_7 ,
V_21 , V_45 , V_37 -> V_41 , V_9 ) ;
V_49 = V_37 -> V_41 ;
} else {
V_49 = V_9 ;
}
if ( V_49 && V_37 -> V_40 )
memcpy ( V_37 -> V_40 , V_8 , V_49 ) ;
F_27 ( V_35 ) ;
exit:
return true ;
}
static int F_28 ( struct V_51 * V_36 )
{
struct V_47 * V_37 ;
T_2 V_52 , V_9 ;
V_36 -> V_53 = 0 ;
V_52 = V_33 + 1 ;
V_9 = sizeof( * V_37 ) * V_52 ;
V_37 = F_19 ( V_9 , V_38 ) ;
if ( ! V_37 )
return - 1 ;
V_36 -> V_37 = V_37 ;
return 0 ;
}
static void F_29 ( struct V_51 * V_36 )
{
struct V_47 * V_37 ;
V_37 = V_36 -> V_37 ;
V_36 -> V_37 = NULL ;
F_23 ( V_37 ) ;
}
int F_30 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_57 V_58 ;
enum V_59 V_17 ;
int V_60 = 0 ;
struct V_61 * V_62 = & V_63 ;
V_36 = F_31 ( V_6 ) ;
if ( V_36 ) {
V_60 = 0 ;
goto V_64;
}
V_60 = F_28 ( & V_6 -> V_36 ) ;
if ( V_60 )
goto V_64;
V_58 = V_65 ;
V_17 = F_32 ( V_6 , V_62 , V_58 , & V_36 , & V_56 ) ;
if ( V_17 != V_66 ) {
F_17 ( V_6 , V_19 , V_20 ,
L_8 , V_21 ,
V_17 ) ;
V_60 = - 1 ;
goto V_64;
}
V_6 -> V_36 . V_67 = V_36 ;
V_64:
if ( V_60 )
F_33 ( V_6 ) ;
return V_60 ;
}
int F_33 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
enum V_59 V_17 ;
int V_60 = 0 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 ) {
V_60 = 0 ;
goto V_64;
}
F_29 ( & V_6 -> V_36 ) ;
F_34 ( V_36 ) ;
V_17 = F_35 ( V_36 ) ;
V_6 -> V_36 . V_67 = NULL ;
if ( V_17 != V_66 ) {
V_60 = - 1 ;
goto V_64;
}
V_64:
return V_60 ;
}
int F_36 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 )
goto V_64;
V_56 = F_37 ( V_36 ) ;
V_17 = V_56 -> V_68 ( V_36 ) ;
if ( V_17 != V_66 )
goto V_64;
V_17 = V_56 -> V_69 ( V_36 , V_70 ) ;
if ( V_17 != V_66 )
goto V_64;
V_17 = V_56 -> V_71 ( V_36 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_38 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 )
goto V_64;
V_56 = F_37 ( V_36 ) ;
V_17 = V_56 -> V_69 ( V_36 , V_72 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_39 ( struct V_5 * V_6 ,
enum V_73 V_74 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_36 ) ;
V_17 = V_56 -> V_75 ( V_36 , V_74 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
static enum V_59 F_40 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_1 V_76 = 0 ;
int V_60 ;
V_36 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_36 ) ;
if ( V_76 )
V_17 = V_56 -> V_77 ( V_36 , V_78 ) ;
else
V_17 = V_56 -> V_77 ( V_36 ,
V_79 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = F_41 ( V_6 , true ) ;
if ( V_60 )
goto V_64;
if ( V_6 -> V_10 -> V_80 [ V_81 ] )
V_17 = V_56 -> V_82 (
V_36 , V_83 ) ;
else if ( V_6 -> V_10 -> V_80 [ V_84 ] )
V_17 = V_56 -> V_82 ( V_36 ,
V_85 ) ;
else if ( V_6 -> V_10 -> V_80 [ V_86 ] )
V_17 = V_56 -> V_82 ( V_36 ,
V_87 ) ;
else
V_17 = V_56 -> V_82 ( V_36 ,
V_88 ) ;
if ( V_17 != V_66 )
goto V_64;
V_64:
return V_17 ;
}
static inline enum V_89 F_42 ( enum V_90 V_91 )
{
enum V_89 V_92 ;
switch ( V_91 ) {
case V_93 :
V_92 = V_94 ;
break;
case V_95 :
V_92 = V_96 ;
break;
case V_97 :
V_92 = V_98 ;
break;
case V_99 :
V_92 = V_100 ;
break;
default:
V_92 = (enum V_89 ) V_91 ;
break;
}
return V_92 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
struct V_101 V_74 ;
enum V_59 V_17 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 )
return - 1 ;
V_56 = F_37 ( V_36 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_102 = V_6 -> V_103 . V_102 ;
V_74 . V_90 = F_42 ( V_6 -> V_104 . V_90 ) ;
V_17 = V_56 -> V_105 ( V_36 , & V_74 ) ;
switch ( V_17 ) {
case V_66 :
break;
case V_106 :
F_17 ( V_6 , V_19 , V_107 ,
L_9 ,
V_21 ) ;
default:
return - 1 ;
}
return 0 ;
}
static int F_44 ( struct V_5 * V_6 , T_1 * V_108 , T_2 V_109 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
bool V_110 ;
bool V_111 = false ;
int V_60 , V_112 = - 1 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 )
goto V_64;
V_56 = F_37 ( V_36 ) ;
V_60 = F_36 ( V_6 ) ;
if ( V_60 )
goto V_64;
V_6 -> V_36 . V_53 = 0 ;
if ( V_108 && V_109 ) {
V_60 = F_45 ( V_6 , V_108 , V_109 ) ;
if ( V_60 )
goto V_64;
V_111 = true ;
}
V_17 = F_40 ( V_6 ) ;
if ( V_17 != V_66 )
goto V_64;
if ( V_111 ) {
V_6 -> V_36 . V_53 = 0 ;
V_60 = F_43 ( V_6 ) ;
if ( V_60 )
goto V_64;
} else {
V_6 -> V_36 . V_53 = 1 ;
}
if ( V_6 -> V_10 -> V_11 -> V_113 )
V_110 = V_6 -> V_10 -> V_11 -> V_113 ( V_6 ) ;
else
V_110 = false ;
if ( ! V_110 )
goto V_64;
V_60 = F_39 ( V_6 , V_114 ) ;
if ( V_60 )
goto V_64;
if ( V_6 -> V_10 -> V_11 -> V_115 )
V_110 = V_6 -> V_10 -> V_11 -> V_115 ( V_6 ) ;
else
V_110 = false ;
if ( ! V_110 )
goto V_64;
V_17 = V_56 -> V_116 ( V_36 ) ;
if ( V_17 != V_66 )
goto V_64;
V_112 = 0 ;
V_64:
return V_112 ;
}
int F_46 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_103 . V_117 || V_6 -> V_103 . V_109 == 0 )
return - 1 ;
return F_44 ( V_6 , V_6 -> V_103 . V_117 ,
V_6 -> V_103 . V_109 ) ;
}
int F_47 ( struct V_5 * V_6 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 )
goto V_64;
V_56 = F_37 ( V_36 ) ;
V_17 = V_56 -> V_118 ( V_36 ) ;
if ( V_17 != V_66 )
goto V_64;
V_17 = V_56 -> V_69 ( V_36 , V_72 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_48 ( struct V_5 * V_6 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_120 ( V_119 ) ;
if ( V_17 != V_66 )
goto V_64;
V_17 = V_56 -> V_121 ( V_119 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_45 ( struct V_5 * V_6 , T_1 * V_108 , T_2 V_109 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
struct V_122 V_123 ;
int V_60 = 0 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
if ( ( ! V_108 ) || ( ! V_109 ) )
return - 1 ;
V_56 -> V_124 ( V_119 , 0x1000 ) ;
V_119 -> V_125 = 0 ;
V_17 = V_56 -> V_126 ( V_119 , V_108 , V_109 ) ;
if ( V_17 != V_66 )
return - 1 ;
V_17 = V_56 -> V_127 ( V_119 , & V_123 ) ;
if ( V_17 == V_66 ) {
V_6 -> V_103 . V_123 = V_123 . V_128 ;
V_6 -> V_103 . V_129 =
( V_123 . V_130 << 8 ) | ( V_123 . V_131 ) ;
F_17 (
V_6 , V_19 , V_132 ,
L_10 ,
V_6 -> V_103 . V_123 ,
V_6 -> V_103 . V_129 ) ;
}
if ( V_6 -> V_36 . V_53 ) {
V_6 -> V_36 . V_53 = 0 ;
V_60 = F_43 ( V_6 ) ;
}
return V_60 ;
}
int F_49 ( struct V_5 * V_6 , T_1 V_133 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
V_36 = F_31 ( V_6 ) ;
if ( ! V_36 )
return - 1 ;
V_56 = F_37 ( V_36 ) ;
V_17 = V_56 -> V_134 ( V_36 , V_135 , & V_133 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
static bool F_50 ( struct V_5 * V_6 , T_1 V_136 )
{
bool V_137 = false ;
int V_138 = 100 ;
T_1 V_139 ;
F_17 ( V_6 , V_19 , V_20 ,
L_11 , V_21 ,
F_3 ( V_6 , V_140 ) , V_136 ) ;
do {
V_139 = F_3 ( V_6 , V_140 ) & F_51 ( V_136 ) ;
if ( V_139 == 0 )
V_137 = true ;
else
F_52 () ;
} while ( ( ! V_137 ) && ( V_138 -- ) );
return V_137 ;
}
int F_53 ( struct V_5 * V_6 , T_1 * V_141 )
{
T_1 V_142 = 0 ;
T_2 V_143 = 0 ;
T_2 V_144 = 0 ;
T_4 V_145 = 0 ;
T_4 V_146 = 0 ;
T_5 V_44 = - 1 ;
unsigned long V_147 = 0 ;
struct V_148 * V_103 = V_148 ( V_6 ) ;
if ( ! V_141 ) {
F_17 ( V_6 , V_19 , V_20 , L_12 ,
V_21 ) ;
return V_44 ;
}
F_54 ( & V_6 -> V_149 . V_150 , V_147 ) ;
V_142 = V_103 -> V_151 ;
if ( ! F_50 ( V_6 , V_142 ) ) {
F_17 ( V_6 , V_19 , V_20 ,
L_13 ) ;
goto exit;
}
V_144 = V_152 + ( V_142 * V_153 ) ;
memcpy ( ( T_1 * ) ( & V_146 ) , V_141 + 4 , V_153 ) ;
F_13 ( V_6 , V_144 , F_55 ( V_146 ) ) ;
V_143 = V_154 + ( V_142 * V_155 ) ;
memcpy ( ( T_1 * ) ( & V_145 ) , V_141 , 4 ) ;
F_13 ( V_6 , V_143 , F_55 ( V_145 ) ) ;
V_103 -> V_151 = ( V_142 + 1 ) % V_156 ;
V_44 = 0 ;
exit:
F_56 ( & V_6 -> V_149 . V_150 , V_147 ) ;
return V_44 ;
}
int F_57 ( struct V_5 * V_6 , T_1 * V_157 , T_2 V_9 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_158 ( V_119 , V_157 , V_9 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
int F_58 ( struct V_5 * V_6 , T_2 * V_9 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_2 V_7 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_159 ( V_119 , & V_7 ) ;
if ( V_17 != V_66 )
return - 1 ;
* V_9 = V_7 ;
return 0 ;
}
int F_59 ( struct V_5 * V_6 , T_1 * V_160 ,
T_2 V_9 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
enum V_14 V_15 ;
int V_44 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_15 = V_23 ;
V_44 = F_21 ( V_6 , V_15 , V_160 , V_9 ) ;
if ( V_44 )
return - 1 ;
V_17 = V_56 -> V_161 ( V_119 , V_162 ) ;
if ( V_17 != V_66 ) {
F_22 ( V_6 , V_15 ) ;
return - 1 ;
}
V_44 = F_24 ( V_6 , V_15 ) ;
if ( V_44 )
return - 1 ;
return 0 ;
}
int F_60 ( struct V_5 * V_6 , T_2 V_4 ,
T_2 V_163 , T_1 * V_164 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_1 V_165 ;
T_2 V_166 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
for ( V_166 = 0 ; V_166 < V_163 ; V_166 ++ ) {
V_17 = V_56 -> V_167 ( V_119 , V_4 + V_166 , & V_165 ) ;
if ( V_17 != V_66 )
return - 1 ;
V_164 [ V_166 ] = V_165 ;
}
return 0 ;
}
int F_61 ( struct V_5 * V_6 , T_2 V_4 ,
T_2 V_163 , T_1 * V_164 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_2 V_166 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
for ( V_166 = 0 ; V_166 < V_163 ; V_166 ++ ) {
V_17 = V_56 -> V_168 ( V_119 , V_4 + V_166 , V_164 [ V_166 ] ) ;
if ( V_17 != V_66 )
return - 1 ;
}
return 0 ;
}
int F_62 ( struct V_5 * V_6 , T_2 * V_9 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_2 V_7 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_169 ( V_119 , & V_7 ) ;
if ( V_17 != V_66 )
return - 1 ;
* V_9 = V_7 ;
return 0 ;
}
int F_63 ( struct V_5 * V_6 , T_1 * V_160 ,
T_2 V_9 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
enum V_14 V_15 ;
int V_44 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_15 = V_25 ;
V_44 = F_21 ( V_6 , V_15 , V_160 , V_9 ) ;
if ( V_44 )
return - 1 ;
V_17 = V_56 -> V_170 ( V_119 , V_171 ) ;
if ( V_17 != V_66 ) {
F_22 ( V_6 , V_15 ) ;
return - 1 ;
}
V_44 = F_24 ( V_6 , V_15 ) ;
if ( V_44 )
return - 1 ;
return 0 ;
}
int F_64 ( struct V_5 * V_6 , T_1 * V_160 ,
T_2 V_9 , T_1 * V_172 , T_2 V_173 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
struct V_174 V_175 ;
enum V_59 V_17 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_175 . V_176 = V_160 ;
V_175 . V_177 = V_9 ;
V_175 . V_178 = V_172 ;
V_175 . V_179 = V_173 ;
V_17 = V_56 -> V_180 ( V_119 , & V_175 , V_171 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
int F_65 ( struct V_5 * V_6 , T_2 V_4 , T_2 V_163 ,
T_1 * V_164 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_1 V_165 ;
T_2 V_166 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
for ( V_166 = 0 ; V_166 < V_163 ; V_166 ++ ) {
V_17 = V_56 -> V_181 ( V_119 , V_4 + V_166 , & V_165 ) ;
if ( V_17 != V_66 )
return - 1 ;
V_164 [ V_166 ] = V_165 ;
}
return 0 ;
}
int F_66 ( struct V_5 * V_6 , T_2 V_4 ,
T_2 V_163 , T_1 * V_164 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_2 V_166 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
for ( V_166 = 0 ; V_166 < V_163 ; V_166 ++ ) {
V_17 = V_56 -> V_182 ( V_119 , V_4 + V_166 ,
V_164 [ V_166 ] ) ;
if ( V_17 != V_66 )
return - 1 ;
}
return 0 ;
}
int F_67 ( struct V_5 * V_6 , T_1 V_183 , T_1 * V_184 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
T_1 V_185 ;
union V_186 V_187 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_36 ) ;
V_185 = V_183 ;
memset ( & V_187 , 0 , sizeof( V_187 ) ) ;
memcpy ( V_187 . V_188 , V_184 , 6 ) ;
V_17 = V_56 -> V_189 ( V_36 , V_185 , & V_187 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_68 ( struct V_5 * V_6 , T_1 V_183 , T_1 * V_184 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
T_1 V_185 ;
union V_186 V_187 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_36 ) ;
V_185 = V_183 ;
memset ( & V_187 , 0 , sizeof( union V_186 ) ) ;
memcpy ( V_187 . V_188 , V_184 , 6 ) ;
V_17 = V_56 -> V_190 ( V_36 , V_185 , & V_187 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_69 ( struct V_5 * V_6 , T_1 V_191 ,
T_1 V_192 , T_1 V_193 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_194 ( V_119 , V_191 , V_192 , V_193 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
int F_70 ( struct V_5 * V_6 , enum V_195 V_196 ,
void * V_197 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_198 ( V_119 , V_196 , V_197 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
int F_71 ( struct V_5 * V_6 ,
enum V_199 V_200 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
T_1 * V_201 = NULL ;
T_2 V_202 = 0 ;
T_6 V_44 = 0 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_202 = V_56 -> V_203 ( V_119 , V_200 ) ;
if ( V_202 )
V_201 = F_72 ( V_202 ) ;
if ( ! V_201 )
return - 1 ;
V_17 = V_56 -> V_204 ( V_119 , V_200 , 0 , V_202 ,
V_201 ) ;
if ( V_17 != V_66 ) {
V_44 = - 1 ;
goto V_205;
}
V_205:
if ( V_201 )
F_73 ( V_201 ) ;
return V_44 ;
}
int F_41 ( struct V_5 * V_6 , bool V_133 )
{
struct V_54 * V_36 ;
struct V_55 * V_56 ;
struct V_206 V_207 ;
enum V_59 V_17 ;
int V_60 = - 1 ;
V_36 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_36 ) ;
memset ( ( void * ) & V_207 , 0 , sizeof( V_207 ) ) ;
if ( V_133 ) {
} else {
V_207 . V_208 = V_209 ;
}
V_17 = V_56 -> V_210 ( V_36 , & V_207 ) ;
if ( V_17 != V_66 )
goto V_64;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_74 ( struct V_5 * V_6 , T_1 * V_211 )
{
T_1 V_212 ;
int V_60 = - 1 ;
V_212 = F_3 ( V_6 , 0x1C7 ) ;
if ( V_212 == 0xEA )
goto V_64;
* V_211 = V_212 ;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_75 ( struct V_5 * V_6 , T_1 * V_213 )
{
T_1 V_214 = 6 ;
* V_213 = V_214 * 8 ;
return 0 ;
}
int F_76 ( struct V_5 * V_6 , T_3 * V_215 )
{
enum V_59 V_17 ;
struct V_54 * V_36 = F_31 ( V_6 ) ;
struct V_55 * V_56 = F_37 ( V_36 ) ;
V_17 = V_56 -> V_198 ( V_36 , V_216 ,
V_215 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
int F_77 ( struct V_5 * V_6 , T_1 * V_217 , T_2 V_9 )
{
struct V_54 * V_119 ;
struct V_55 * V_56 ;
enum V_59 V_17 ;
V_119 = F_31 ( V_6 ) ;
V_56 = F_37 ( V_119 ) ;
V_17 = V_56 -> V_218 ( V_119 , V_217 , V_9 ) ;
if ( V_17 != V_66 )
return - 1 ;
return 0 ;
}
