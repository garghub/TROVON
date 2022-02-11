static int F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 & V_3 )
return 0 ;
F_2 ( V_1 , 0 ) ;
return 1 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
F_5 ( V_7 , V_5 ) ;
}
static int F_6 ( struct V_8 * V_9 , char * V_10 ,
char * * V_11 , T_1 V_12 ,
int V_13 , int V_14 )
{
return sprintf ( V_10 , L_1 ) ;
}
static int F_7 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
return 1 ;
}
static int F_8 (
struct V_19 * V_20 ,
int V_21 ,
int V_22 )
{
switch ( V_22 ) {
case V_23 :
F_9 ( V_20 , F_10 ( V_20 ) , V_21 ) ;
break;
case V_24 :
F_11 ( V_20 , V_21 ) ;
break;
case V_25 :
F_9 ( V_20 , F_10 ( V_20 ) , V_21 ) ;
break;
default:
return - V_26 ;
}
return V_20 -> V_27 ;
}
static int F_12 ( struct V_28 * V_29 )
{
if ( V_29 -> V_15 -> V_30 ) {
switch ( V_29 -> V_31 ) {
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
default:
break;
}
}
return V_36 ;
}
static void F_13 ( struct V_37 * V_38 )
{
struct V_4 * V_5 =
F_4 ( V_38 , struct V_4 , V_38 ) ;
struct V_1 * V_1 = & V_5 -> V_6 ;
struct V_28 * V_29 = V_5 -> V_29 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = NULL ;
T_2 V_47 = 0 ;
int V_48 ;
V_42 = * (struct V_41 * * ) F_14 ( V_29 -> V_15 -> V_9 ) ;
V_44 = & V_42 -> V_49 [ V_29 -> V_15 -> V_50 ] ;
if ( ! V_44 -> V_42 ) {
F_15 ( V_29 , V_51 ) ;
goto V_52;
}
V_40 = V_42 -> V_40 ;
if ( ! V_40 ) {
F_16 ( V_53 , V_29 , L_2
L_3 ) ;
F_15 ( V_29 , V_54 ) ;
goto V_52;
}
if ( F_17 ( V_29 ) ) {
struct V_55 * V_56 = F_18 ( V_29 ) ;
V_46 = V_56 -> V_57 . V_58 ;
V_47 = V_56 -> V_57 . V_59 ;
V_1 -> V_2 |= V_60 ;
}
V_48 = F_19 ( V_1 , V_40 -> V_61 , V_29 -> V_62 ,
& V_5 -> V_63 [ 0 ] , V_5 -> V_29 -> V_15 -> V_64 ,
F_20 ( V_29 ) , F_12 ( V_29 ) ,
V_29 -> V_65 , 0 ,
F_21 ( V_29 ) , F_22 ( V_29 ) ,
V_46 , V_47 ) ;
if ( V_48 < 0 ) {
F_15 ( V_29 , V_51 ) ;
goto V_52;
}
return;
V_52:
V_29 -> V_66 ( V_29 ) ;
return;
}
static int F_23 ( struct V_8 * V_67 , struct V_28 * V_29 )
{
struct V_4 * V_5 ;
F_24 ( L_4
L_5 , V_29 -> V_15 -> V_9 -> V_68 ,
V_29 -> V_15 -> V_50 , V_29 -> V_15 -> V_69 , V_29 -> V_15 -> V_64 ,
V_29 -> V_62 [ 0 ] , F_20 ( V_29 ) ) ;
V_5 = F_25 ( V_7 , V_70 ) ;
if ( ! V_5 ) {
F_26 ( L_6 ) ;
F_15 ( V_29 , V_54 ) ;
V_29 -> V_66 ( V_29 ) ;
return 0 ;
}
V_5 -> V_29 = V_29 ;
F_27 ( & V_5 -> V_38 , F_13 ) ;
F_28 ( V_71 , & V_5 -> V_38 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = NULL ;
struct V_72 * V_73 ;
struct V_74 * V_61 ;
struct V_4 * V_5 = NULL ;
struct V_41 * V_42 ;
struct V_39 * V_40 ;
struct V_75 * V_76 = NULL ;
struct V_43 * V_44 ;
int V_77 = V_78 , V_48 ;
V_42 = * (struct V_41 * * ) F_14 ( V_29 -> V_15 -> V_9 ) ;
V_40 = V_42 -> V_40 ;
if ( ! V_40 ) {
F_26 ( L_7
L_8 ) ;
return V_78 ;
}
V_61 = V_40 -> V_61 ;
V_44 = & V_42 -> V_49 [ V_29 -> V_15 -> V_50 ] ;
V_73 = & V_44 -> V_79 ;
V_5 = F_25 ( V_7 , V_80 ) ;
if ( ! V_5 ) {
F_26 ( L_9 ) ;
return V_78 ;
}
V_76 = F_30 ( sizeof( struct V_75 ) , V_80 ) ;
if ( ! V_76 ) {
F_26 ( L_10 ) ;
goto V_81;
}
F_31 ( & V_76 -> V_82 ) ;
V_1 = & V_5 -> V_6 ;
F_32 ( V_1 , V_73 -> V_83 , V_61 , 0 ,
V_84 , V_36 ,
& V_5 -> V_63 [ 0 ] ) ;
V_48 = F_33 ( V_1 , V_76 , V_85 , V_80 ) ;
if ( V_48 < 0 )
goto V_81;
if ( F_34 ( V_1 , V_29 -> V_15 -> V_64 ) < 0 )
goto V_81;
F_35 ( V_1 ) ;
F_36 ( V_76 -> V_82 , F_37 ( & V_76 -> V_86 ) ) ;
V_77 = ( V_1 -> V_87 -> V_88 == V_89 ) ?
V_90 : V_78 ;
V_81:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_38 ( V_76 ) ;
return V_77 ;
}
static int F_39 ( struct V_19 * V_91 )
{
F_40 ( V_92 , & V_91 -> V_93 -> V_94 ) ;
return 0 ;
}
static int F_41 ( struct V_19 * V_91 )
{
return 0 ;
}
static int F_42 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_8 * V_67 ;
int error ;
V_42 = F_43 ( V_16 ) ;
V_67 = F_44 ( & V_95 ,
sizeof( struct V_41 ) ) ;
if ( ! V_67 ) {
F_26 ( L_11 ) ;
return - V_96 ;
}
V_42 -> V_67 = V_67 ;
* ( (struct V_41 * * ) V_67 -> V_97 ) = V_42 ;
V_67 -> V_98 = 2 ;
V_67 -> V_99 = 0 ;
V_67 -> V_100 = 0 ;
V_67 -> V_101 = V_102 ;
error = F_45 ( V_67 , & V_42 -> V_16 ) ;
if ( error ) {
F_26 ( L_12 , V_103 ) ;
F_46 ( V_67 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_47 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_8 * V_67 ;
V_42 = F_43 ( V_16 ) ;
V_67 = V_42 -> V_67 ;
F_48 ( V_67 ) ;
F_46 ( V_67 ) ;
return 0 ;
}
static void F_49 ( struct V_15 * V_16 )
{
struct V_41 * V_42 = F_43 ( V_16 ) ;
F_38 ( V_42 ) ;
}
static int F_50 ( struct V_41 * V_42 , int V_104 )
{
int V_77 ;
V_42 -> V_16 . V_105 = & V_106 ;
V_42 -> V_16 . V_107 = V_108 ;
V_42 -> V_16 . V_81 = & F_49 ;
F_51 ( & V_42 -> V_16 , L_13 , V_104 ) ;
V_77 = F_52 ( & V_42 -> V_16 ) ;
if ( V_77 ) {
F_26 ( L_14
L_15 , V_77 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_53 ( void )
{
int V_77 ;
V_108 = F_54 ( L_16 ) ;
if ( F_55 ( V_108 ) ) {
F_26 ( L_17 ) ;
return F_56 ( V_108 ) ;
}
V_77 = F_57 ( & V_106 ) ;
if ( V_77 ) {
F_26 ( L_18 ) ;
goto V_109;
}
V_77 = F_58 ( & V_110 ) ;
if ( V_77 ) {
F_26 ( L_19
L_20 ) ;
goto V_111;
}
F_24 ( L_21 ) ;
return V_77 ;
V_111:
F_59 ( & V_106 ) ;
V_109:
F_60 ( V_108 ) ;
return V_77 ;
}
static void F_61 ( void )
{
F_62 ( & V_110 ) ;
F_59 ( & V_106 ) ;
F_60 ( V_108 ) ;
F_24 ( L_22 ) ;
}
static char * F_63 ( void )
{
return L_23 ;
}
static T_3 F_64 ( struct V_72 * V_73 )
{
struct V_43 * V_44 = V_73 -> V_112 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_113 ) {
case V_114 :
return F_65 ( V_73 ) ;
case V_115 :
return F_66 ( V_73 ) ;
case V_116 :
return F_67 ( V_73 ) ;
default:
F_26 ( L_24
L_25 , V_42 -> V_113 ) ;
break;
}
return F_65 ( V_73 ) ;
}
static char * F_68 ( struct V_72 * V_73 )
{
struct V_43 * V_44 = V_73 -> V_112 ;
return & V_44 -> V_42 -> V_117 [ 0 ] ;
}
static T_4 F_69 ( struct V_72 * V_73 )
{
struct V_43 * V_44 = V_73 -> V_112 ;
return V_44 -> V_118 ;
}
static T_2 F_70 ( struct V_72 * V_73 )
{
return 1 ;
}
static T_2 F_71 (
struct V_72 * V_73 ,
struct V_119 * V_120 ,
struct V_121 * V_122 ,
int * V_123 ,
unsigned char * V_124 )
{
struct V_43 * V_44 = V_73 -> V_112 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_113 ) {
case V_114 :
return F_72 ( V_73 , V_120 , V_122 ,
V_123 , V_124 ) ;
case V_115 :
return F_73 ( V_73 , V_120 , V_122 ,
V_123 , V_124 ) ;
case V_116 :
return F_74 ( V_73 , V_120 , V_122 ,
V_123 , V_124 ) ;
default:
F_26 ( L_24
L_25 , V_42 -> V_113 ) ;
break;
}
return F_72 ( V_73 , V_120 , V_122 ,
V_123 , V_124 ) ;
}
static T_2 F_75 (
struct V_72 * V_73 ,
struct V_119 * V_120 ,
struct V_121 * V_122 ,
int * V_123 )
{
struct V_43 * V_44 = V_73 -> V_112 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_113 ) {
case V_114 :
return F_76 ( V_73 , V_120 , V_122 ,
V_123 ) ;
case V_115 :
return F_77 ( V_73 , V_120 , V_122 ,
V_123 ) ;
case V_116 :
return F_78 ( V_73 , V_120 , V_122 ,
V_123 ) ;
default:
F_26 ( L_24
L_25 , V_42 -> V_113 ) ;
break;
}
return F_76 ( V_73 , V_120 , V_122 ,
V_123 ) ;
}
static char * F_79 (
struct V_72 * V_73 ,
const char * V_124 ,
T_2 * V_125 ,
char * * V_126 )
{
struct V_43 * V_44 = V_73 -> V_112 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_113 ) {
case V_114 :
return F_80 ( V_73 , V_124 , V_125 ,
V_126 ) ;
case V_115 :
return F_81 ( V_73 , V_124 , V_125 ,
V_126 ) ;
case V_116 :
return F_82 ( V_73 , V_124 , V_125 ,
V_126 ) ;
default:
F_26 ( L_24
L_25 , V_42 -> V_113 ) ;
break;
}
return F_80 ( V_73 , V_124 , V_125 ,
V_126 ) ;
}
static int F_83 ( struct V_72 * V_73 )
{
return 1 ;
}
static int F_84 ( struct V_72 * V_73 )
{
return 0 ;
}
static int F_85 ( struct V_72 * V_73 )
{
return 0 ;
}
static int F_86 ( struct V_72 * V_73 )
{
return 0 ;
}
static struct V_119 * F_87 (
struct V_72 * V_73 )
{
struct V_127 * V_128 ;
V_128 = F_30 ( sizeof( struct V_127 ) , V_80 ) ;
if ( ! V_128 ) {
F_26 ( L_26 ) ;
return NULL ;
}
return & V_128 -> V_119 ;
}
static void F_88 (
struct V_72 * V_73 ,
struct V_119 * V_120 )
{
struct V_127 * V_128 = F_4 ( V_120 ,
struct V_127 , V_119 ) ;
F_38 ( V_128 ) ;
}
static T_2 F_89 ( struct V_72 * V_73 )
{
return 1 ;
}
static T_2 F_90 ( struct V_74 * V_61 )
{
return 1 ;
}
static void F_91 ( struct V_119 * V_129 )
{
return;
}
static T_2 F_92 ( struct V_1 * V_1 )
{
return 1 ;
}
static int F_93 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_130 ;
}
static int F_94 ( struct V_74 * V_61 )
{
return 0 ;
}
static void F_95 ( struct V_74 * V_61 )
{
return;
}
static int F_96 ( struct V_1 * V_1 )
{
F_97 ( V_1 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_99 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_28 * V_29 = V_5 -> V_29 ;
F_24 ( L_27
L_28 , V_29 , V_29 -> V_62 [ 0 ] ) ;
V_29 -> V_131 = V_132 ;
F_15 ( V_29 , V_133 ) ;
if ( ( V_1 -> V_2 & V_134 ) ||
( V_1 -> V_2 & V_135 ) )
F_100 ( V_29 , V_1 -> V_136 ) ;
V_29 -> V_66 ( V_29 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_28 * V_29 = V_5 -> V_29 ;
F_24 ( L_29
L_28 , V_29 , V_29 -> V_62 [ 0 ] ) ;
if ( V_1 -> V_137 &&
( ( V_1 -> V_2 & V_138 ) ||
( V_1 -> V_2 & V_139 ) ) ) {
memcpy ( V_29 -> V_137 , V_1 -> V_137 ,
V_140 ) ;
V_29 -> V_131 = V_141 ;
F_102 ( V_29 , V_142 ) ;
} else
V_29 -> V_131 = V_1 -> V_143 ;
F_15 ( V_29 , V_133 ) ;
if ( ( V_1 -> V_2 & V_134 ) ||
( V_1 -> V_2 & V_135 ) )
F_100 ( V_29 , V_1 -> V_136 ) ;
V_29 -> V_66 ( V_29 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_1 )
{
struct V_87 * V_144 = V_1 -> V_87 ;
struct V_75 * V_76 = V_144 -> V_145 ;
F_104 ( & V_76 -> V_86 , 1 ) ;
F_105 ( & V_76 -> V_82 ) ;
return 0 ;
}
static char * F_106 ( struct V_41 * V_42 )
{
switch ( V_42 -> V_113 ) {
case V_114 :
return L_30 ;
case V_115 :
return L_31 ;
case V_116 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_107 (
struct V_72 * V_73 ,
struct V_146 * V_64 )
{
struct V_43 * V_44 = F_4 ( V_73 ,
struct V_43 , V_79 ) ;
struct V_41 * V_42 = V_44 -> V_42 ;
F_108 ( & V_44 -> V_147 ) ;
F_109 () ;
F_110 ( V_42 -> V_67 , 0 , V_44 -> V_118 , V_64 -> V_148 ) ;
F_24 ( L_34 ) ;
return 0 ;
}
static void F_111 (
struct V_72 * V_73 ,
struct V_146 * V_146 )
{
struct V_19 * V_91 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_44 = F_4 ( V_73 , struct V_43 , V_79 ) ;
V_42 = V_44 -> V_42 ;
V_91 = F_112 ( V_42 -> V_67 , 0 , V_44 -> V_118 ,
V_146 -> V_148 ) ;
if ( ! V_91 ) {
F_26 ( L_35
L_36 , 0 , V_44 -> V_118 , V_146 -> V_148 ) ;
return;
}
F_113 ( V_91 ) ;
F_114 ( V_91 ) ;
F_115 ( & V_44 -> V_147 ) ;
F_116 () ;
F_24 ( L_37 ) ;
}
static int F_117 (
struct V_43 * V_44 ,
const char * V_149 )
{
struct V_72 * V_73 ;
struct V_41 * V_42 = V_44 -> V_42 ;
struct V_39 * V_40 ;
int V_77 = - V_150 ;
if ( V_44 -> V_42 -> V_40 ) {
F_24 ( L_38 ) ;
return - V_151 ;
}
V_73 = & V_44 -> V_79 ;
V_40 = F_30 ( sizeof( struct V_39 ) , V_80 ) ;
if ( ! V_40 ) {
F_26 ( L_39 ) ;
return - V_150 ;
}
V_40 -> V_61 = F_118 () ;
if ( F_55 ( V_40 -> V_61 ) ) {
V_77 = F_56 ( V_40 -> V_61 ) ;
goto V_152;
}
V_40 -> V_61 -> V_119 = F_119 (
V_73 , ( unsigned char * ) V_149 ) ;
if ( ! V_40 -> V_61 -> V_119 ) {
F_120 ( V_40 -> V_61 ) ;
goto V_152;
}
F_121 ( V_73 , V_40 -> V_61 -> V_119 ,
V_40 -> V_61 , V_40 ) ;
V_44 -> V_42 -> V_40 = V_40 ;
F_24 ( L_40
L_41 , F_106 ( V_42 ) ,
V_149 ) ;
return 0 ;
V_152:
F_38 ( V_40 ) ;
return V_77 ;
}
static int F_122 (
struct V_43 * V_153 )
{
struct V_74 * V_61 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = V_153 -> V_42 ;
V_40 = V_153 -> V_42 -> V_40 ;
if ( ! V_40 )
return - V_96 ;
V_61 = V_40 -> V_61 ;
if ( ! V_61 )
return - V_96 ;
if ( F_37 ( & V_153 -> V_147 ) ) {
F_26 ( L_42
L_43 ,
F_37 ( & V_153 -> V_147 ) ) ;
return - V_154 ;
}
F_24 ( L_44
L_41 , F_106 ( V_42 ) ,
V_40 -> V_61 -> V_119 -> V_155 ) ;
F_123 ( V_40 -> V_61 ) ;
V_153 -> V_42 -> V_40 = NULL ;
F_38 ( V_40 ) ;
return 0 ;
}
static T_5 F_124 (
struct V_72 * V_73 ,
char * V_156 )
{
struct V_43 * V_44 = F_4 ( V_73 ,
struct V_43 , V_79 ) ;
struct V_39 * V_40 ;
T_5 V_77 ;
V_40 = V_44 -> V_42 -> V_40 ;
if ( ! V_40 )
return - V_96 ;
V_77 = snprintf ( V_156 , V_157 , L_45 ,
V_40 -> V_61 -> V_119 -> V_155 ) ;
return V_77 ;
}
static T_5 F_125 (
struct V_72 * V_73 ,
const char * V_156 ,
T_6 V_158 )
{
struct V_43 * V_44 = F_4 ( V_73 ,
struct V_43 , V_79 ) ;
struct V_41 * V_42 = V_44 -> V_42 ;
unsigned char V_159 [ V_160 ] , * V_161 , * V_162 ;
int V_77 ;
if ( ! strncmp ( V_156 , L_46 , 4 ) ) {
V_77 = F_122 ( V_44 ) ;
return ( ! V_77 ) ? V_158 : V_77 ;
}
if ( strlen ( V_156 ) >= V_160 ) {
F_26 ( L_47
L_48 , V_156 , V_160 ) ;
return - V_163 ;
}
snprintf ( & V_159 [ 0 ] , V_160 , L_49 , V_156 ) ;
V_161 = strstr ( V_159 , L_50 ) ;
if ( V_161 ) {
if ( V_42 -> V_113 != V_114 ) {
F_26 ( L_51
L_52 , V_159 ,
F_106 ( V_42 ) ) ;
return - V_163 ;
}
V_162 = & V_159 [ 0 ] ;
goto V_164;
}
V_161 = strstr ( V_159 , L_53 ) ;
if ( V_161 ) {
if ( V_42 -> V_113 != V_115 ) {
F_26 ( L_54
L_52 , V_159 ,
F_106 ( V_42 ) ) ;
return - V_163 ;
}
V_162 = & V_159 [ 3 ] ;
goto V_164;
}
V_161 = strstr ( V_159 , L_55 ) ;
if ( V_161 ) {
if ( V_42 -> V_113 != V_116 ) {
F_26 ( L_56
L_52 , V_159 ,
F_106 ( V_42 ) ) ;
return - V_163 ;
}
V_162 = & V_159 [ 0 ] ;
goto V_164;
}
F_26 ( L_57
L_58 , V_159 ) ;
return - V_163 ;
V_164:
if ( V_159 [ strlen ( V_159 ) - 1 ] == '\n' )
V_159 [ strlen ( V_159 ) - 1 ] = '\0' ;
V_77 = F_117 ( V_44 , V_162 ) ;
if ( V_77 < 0 )
return V_77 ;
return V_158 ;
}
struct V_72 * F_126 (
struct V_165 * V_166 ,
struct V_167 * V_168 ,
const char * V_149 )
{
struct V_41 * V_42 = F_4 ( V_166 ,
struct V_41 , V_169 ) ;
struct V_43 * V_44 ;
char * V_170 , * V_171 ;
int V_77 ;
unsigned short int V_172 ;
V_170 = strstr ( V_149 , L_59 ) ;
if ( ! V_170 ) {
F_26 ( L_60
L_61 ) ;
return F_127 ( - V_163 ) ;
}
V_170 += 5 ;
V_172 = ( unsigned short int ) F_128 ( V_170 , & V_171 , 0 ) ;
if ( V_172 >= V_173 ) {
F_26 ( L_62
L_63 , V_172 , V_173 ) ;
return F_127 ( - V_163 ) ;
}
V_44 = & V_42 -> V_49 [ V_172 ] ;
V_44 -> V_42 = V_42 ;
V_44 -> V_118 = V_172 ;
V_77 = F_129 ( & V_174 -> V_175 ,
V_166 , & V_44 -> V_79 , V_44 ,
V_176 ) ;
if ( V_77 < 0 )
return F_127 ( - V_150 ) ;
F_24 ( L_64
L_65 , F_106 ( V_42 ) ,
F_130 ( & V_166 -> V_177 . V_178 ) , V_172 ) ;
return & V_44 -> V_79 ;
}
void F_131 (
struct V_72 * V_73 )
{
struct V_165 * V_166 = V_73 -> V_179 ;
struct V_43 * V_44 = F_4 ( V_73 ,
struct V_43 , V_79 ) ;
struct V_41 * V_42 ;
unsigned short V_172 ;
V_42 = V_44 -> V_42 ;
V_172 = V_44 -> V_118 ;
F_122 ( V_44 ) ;
F_132 ( V_73 ) ;
V_44 -> V_42 = NULL ;
V_44 -> V_118 = 0 ;
F_24 ( L_66
L_65 , F_106 ( V_42 ) ,
F_130 ( & V_166 -> V_177 . V_178 ) , V_172 ) ;
}
struct V_165 * F_133 (
struct V_180 * V_181 ,
struct V_167 * V_168 ,
const char * V_149 )
{
struct V_41 * V_42 ;
struct V_8 * V_67 ;
char * V_161 ;
int V_77 , V_182 = 0 ;
V_42 = F_30 ( sizeof( struct V_41 ) , V_80 ) ;
if ( ! V_42 ) {
F_26 ( L_67 ) ;
return F_127 ( - V_150 ) ;
}
V_161 = strstr ( V_149 , L_50 ) ;
if ( V_161 ) {
V_42 -> V_113 = V_114 ;
goto V_183;
}
V_161 = strstr ( V_149 , L_53 ) ;
if ( V_161 ) {
V_42 -> V_113 = V_115 ;
V_182 = 3 ;
goto V_183;
}
V_161 = strstr ( V_149 , L_55 ) ;
if ( ! V_161 ) {
F_26 ( L_68
L_69 , V_149 ) ;
V_77 = - V_163 ;
goto V_152;
}
V_42 -> V_113 = V_116 ;
V_183:
if ( strlen ( V_149 ) >= V_160 ) {
F_26 ( L_70
L_48 , V_149 , F_106 ( V_42 ) ,
V_160 ) ;
V_77 = - V_163 ;
goto V_152;
}
snprintf ( & V_42 -> V_117 [ 0 ] , V_160 , L_49 , & V_149 [ V_182 ] ) ;
V_77 = F_50 ( V_42 , V_184 ) ;
if ( V_77 )
goto V_152;
V_67 = V_42 -> V_67 ;
V_184 ++ ;
F_24 ( L_71
L_72 ,
F_106 ( V_42 ) , V_149 , V_67 -> V_68 ) ;
return & V_42 -> V_169 ;
V_152:
F_38 ( V_42 ) ;
return F_127 ( V_77 ) ;
}
void F_134 (
struct V_165 * V_166 )
{
struct V_41 * V_42 = F_4 ( V_166 ,
struct V_41 , V_169 ) ;
F_24 ( L_73
L_74 ,
V_42 -> V_117 , V_42 -> V_67 -> V_68 ) ;
F_135 ( & V_42 -> V_16 ) ;
}
static T_5 F_136 (
struct V_180 * V_181 ,
char * V_156 )
{
return sprintf ( V_156 , L_75 , V_185 ) ;
}
static int F_137 ( void )
{
struct V_180 * V_186 ;
int V_77 ;
V_184 = 0 ;
V_186 = F_138 ( V_187 , L_23 ) ;
if ( F_55 ( V_186 ) ) {
F_26 ( L_76 ) ;
return F_56 ( V_186 ) ;
}
V_186 -> V_175 . V_188 = & F_63 ;
V_186 -> V_175 . V_189 = & F_64 ;
V_186 -> V_175 . V_190 = & F_68 ;
V_186 -> V_175 . V_191 = & F_69 ;
V_186 -> V_175 . V_192 = & F_70 ;
V_186 -> V_175 . V_193 = & F_71 ;
V_186 -> V_175 . V_194 =
& F_75 ;
V_186 -> V_175 . V_195 =
& F_79 ;
V_186 -> V_175 . V_196 = & F_83 ;
V_186 -> V_175 . V_197 =
& F_84 ;
V_186 -> V_175 . V_198 =
& F_85 ;
V_186 -> V_175 . V_199 =
& F_86 ;
V_186 -> V_175 . V_200 = & F_87 ;
V_186 -> V_175 . V_201 =
& F_88 ;
V_186 -> V_175 . V_202 = & F_89 ;
V_186 -> V_175 . V_203 = & F_1 ;
V_186 -> V_175 . V_204 = & F_3 ;
V_186 -> V_175 . V_205 = & F_94 ;
V_186 -> V_175 . V_206 = & F_95 ;
V_186 -> V_175 . V_207 = & F_90 ;
V_186 -> V_175 . V_208 = NULL ;
V_186 -> V_175 . V_209 = & F_96 ;
V_186 -> V_175 . V_210 = & F_98 ;
V_186 -> V_175 . V_211 =
& F_91 ;
V_186 -> V_175 . V_212 = & F_92 ;
V_186 -> V_175 . V_213 = & F_93 ;
V_186 -> V_175 . V_214 = & F_99 ;
V_186 -> V_175 . V_215 = & F_101 ;
V_186 -> V_175 . V_216 = & F_103 ;
V_186 -> V_175 . V_217 = & F_133 ;
V_186 -> V_175 . V_218 = & F_134 ;
V_186 -> V_175 . V_219 = & F_126 ;
V_186 -> V_175 . V_220 = & F_131 ;
V_186 -> V_175 . V_221 = & F_107 ;
V_186 -> V_175 . V_222 = & F_111 ;
V_186 -> V_175 . V_223 = NULL ;
V_186 -> V_175 . V_224 = NULL ;
F_139 ( V_186 ) -> V_225 . V_226 = V_227 ;
F_139 ( V_186 ) -> V_228 . V_226 = V_229 ;
F_139 ( V_186 ) -> V_230 . V_226 = NULL ;
F_139 ( V_186 ) -> V_231 . V_226 = NULL ;
F_139 ( V_186 ) -> V_232 . V_226 = NULL ;
V_77 = F_140 ( V_186 ) ;
if ( V_77 < 0 ) {
F_26 ( L_77
L_78 ) ;
F_141 ( V_186 ) ;
return - 1 ;
}
V_174 = V_186 ;
F_24 ( L_79
L_80 ) ;
return 0 ;
}
static void F_142 ( void )
{
if ( ! V_174 )
return;
F_143 ( V_174 ) ;
V_174 = NULL ;
F_24 ( L_81
L_80 ) ;
}
static int T_7 F_144 ( void )
{
int V_77 = - V_150 ;
V_71 = F_145 ( L_82 , 0 , 0 ) ;
if ( ! V_71 )
goto V_152;
V_7 = F_146 ( L_83 ,
sizeof( struct V_4 ) ,
F_147 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_24 ( L_84
L_85 ) ;
goto V_233;
}
V_77 = F_53 () ;
if ( V_77 )
goto V_234;
V_77 = F_137 () ;
if ( V_77 )
goto V_235;
return 0 ;
V_235:
F_61 () ;
V_234:
F_148 ( V_7 ) ;
V_233:
F_149 ( V_71 ) ;
V_152:
return V_77 ;
}
static void T_8 F_150 ( void )
{
F_142 () ;
F_61 () ;
F_148 ( V_7 ) ;
F_149 ( V_71 ) ;
}
