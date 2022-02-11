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
static int F_6 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
F_7 ( V_9 , L_1 ) ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
return 1 ;
}
static void F_9 ( struct V_16 * V_17 )
{
struct V_4 * V_5 =
F_4 ( V_17 , struct V_4 , V_17 ) ;
struct V_1 * V_1 = & V_5 -> V_6 ;
struct V_18 * V_19 = V_5 -> V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 = NULL ;
T_1 V_28 = 0 , V_29 ;
int V_30 ;
V_23 = * (struct V_22 * * ) F_10 ( V_19 -> V_12 -> V_11 ) ;
V_25 = & V_23 -> V_31 [ V_19 -> V_12 -> V_32 ] ;
if ( ! V_25 -> V_23 ) {
F_11 ( V_19 , V_33 ) ;
goto V_34;
}
if ( V_25 -> V_35 == V_36 ) {
F_11 ( V_19 , V_37 ) ;
goto V_34;
}
V_21 = V_25 -> V_21 ;
if ( ! V_21 ) {
F_12 ( V_38 , V_19 , L_2
L_3 ) ;
F_11 ( V_19 , V_39 ) ;
goto V_34;
}
if ( F_13 ( V_19 ) ) {
struct V_40 * V_41 = F_14 ( V_19 ) ;
V_27 = V_41 -> V_42 . V_43 ;
V_28 = V_41 -> V_42 . V_44 ;
V_1 -> V_2 |= V_45 ;
}
V_29 = F_15 ( V_19 ) ;
if ( ! F_16 ( V_19 ) &&
F_17 ( V_19 ) != V_46 ) {
V_1 -> V_47 = true ;
V_29 = F_18 ( V_19 ) ;
}
V_30 = F_19 ( V_1 , V_21 -> V_48 , V_19 -> V_49 ,
& V_5 -> V_50 [ 0 ] , V_5 -> V_19 -> V_12 -> V_51 ,
V_29 , V_52 ,
V_19 -> V_53 , 0 ,
F_20 ( V_19 ) , F_21 ( V_19 ) ,
V_27 , V_28 ,
F_22 ( V_19 ) , F_16 ( V_19 ) ) ;
if ( V_30 < 0 ) {
F_11 ( V_19 , V_33 ) ;
goto V_34;
}
return;
V_34:
F_5 ( V_7 , V_5 ) ;
V_19 -> V_54 ( V_19 ) ;
return;
}
static int F_23 ( struct V_10 * V_55 , struct V_18 * V_19 )
{
struct V_4 * V_5 ;
F_24 ( L_4
L_5 , V_19 -> V_12 -> V_11 -> V_56 ,
V_19 -> V_12 -> V_32 , V_19 -> V_12 -> V_57 , V_19 -> V_12 -> V_51 ,
V_19 -> V_49 [ 0 ] , F_18 ( V_19 ) ) ;
V_5 = F_25 ( V_7 , V_58 ) ;
if ( ! V_5 ) {
F_26 ( L_6 ) ;
F_11 ( V_19 , V_39 ) ;
V_19 -> V_54 ( V_19 ) ;
return 0 ;
}
V_5 -> V_19 = V_19 ;
V_5 -> V_59 = V_19 -> V_60 -> V_61 ;
F_27 ( & V_5 -> V_17 , F_9 ) ;
F_28 ( V_62 , & V_5 -> V_17 ) ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
int V_51 , int V_63 , enum V_64 V_65 )
{
struct V_1 * V_1 = NULL ;
struct V_66 * V_48 ;
struct V_67 * V_68 ;
struct V_20 * V_21 ;
struct V_4 * V_5 = NULL ;
struct V_69 * V_70 = NULL ;
int V_71 = V_72 , V_30 ;
V_21 = V_25 -> V_21 ;
if ( ! V_21 ) {
F_26 ( L_7
L_8 ) ;
return V_71 ;
}
V_5 = F_25 ( V_7 , V_73 ) ;
if ( ! V_5 ) {
F_26 ( L_9 ) ;
return V_71 ;
}
V_70 = F_30 ( sizeof( struct V_69 ) , V_73 ) ;
if ( ! V_70 ) {
F_26 ( L_10 ) ;
goto V_74;
}
F_31 ( & V_70 -> V_75 ) ;
V_1 = & V_5 -> V_6 ;
V_68 = & V_25 -> V_76 ;
V_48 = V_25 -> V_21 -> V_48 ;
F_32 ( V_1 , V_68 -> V_77 , V_48 , 0 ,
V_78 , V_52 ,
& V_5 -> V_50 [ 0 ] ) ;
V_30 = F_33 ( V_1 , V_70 , V_65 , V_73 ) ;
if ( V_30 < 0 )
goto V_74;
if ( V_65 == V_79 )
V_1 -> V_80 -> V_81 = V_63 ;
if ( F_34 ( V_1 , V_51 ) < 0 ) {
V_71 = V_82 ;
goto V_74;
}
F_35 ( V_1 ) ;
F_36 ( V_70 -> V_75 , F_37 ( & V_70 -> V_83 ) ) ;
V_71 = V_1 -> V_80 -> V_84 ;
V_74:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_38 ( V_70 ) ;
return V_71 ;
}
static int F_39 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_71 = V_85 ;
V_23 = * (struct V_22 * * ) F_10 ( V_19 -> V_12 -> V_11 ) ;
V_25 = & V_23 -> V_31 [ V_19 -> V_12 -> V_32 ] ;
V_71 = F_29 ( V_25 , V_19 -> V_12 -> V_51 ,
V_19 -> V_60 -> V_61 , V_79 ) ;
return ( V_71 == V_86 ) ? V_87 : V_85 ;
}
static int F_40 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_71 = V_85 ;
V_23 = * (struct V_22 * * ) F_10 ( V_19 -> V_12 -> V_11 ) ;
V_25 = & V_23 -> V_31 [ V_19 -> V_12 -> V_32 ] ;
V_71 = F_29 ( V_25 , V_19 -> V_12 -> V_51 ,
0 , V_88 ) ;
return ( V_71 == V_86 ) ? V_87 : V_85 ;
}
static int F_41 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = * (struct V_22 * * ) F_10 ( V_19 -> V_12 -> V_11 ) ;
if ( ! V_23 ) {
F_26 ( L_7
L_8 ) ;
return V_85 ;
}
V_25 = & V_23 -> V_31 [ V_19 -> V_12 -> V_32 ] ;
if ( V_25 ) {
V_25 -> V_35 = V_89 ;
return V_87 ;
}
return V_85 ;
}
static int F_42 ( struct V_90 * V_91 )
{
F_43 ( V_92 , & V_91 -> V_93 -> V_94 ) ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 )
{
struct V_22 * V_23 ;
struct V_10 * V_55 ;
int error , V_95 ;
V_23 = F_45 ( V_13 ) ;
V_55 = F_46 ( & V_96 ,
sizeof( struct V_22 ) ) ;
if ( ! V_55 ) {
F_26 ( L_11 ) ;
return - V_97 ;
}
V_23 -> V_55 = V_55 ;
* ( (struct V_22 * * ) V_55 -> V_98 ) = V_23 ;
V_55 -> V_99 = 2 ;
V_55 -> V_100 = 0 ;
V_55 -> V_101 = 0 ;
V_55 -> V_102 = V_103 ;
V_95 = V_104 | V_105 |
V_106 | V_107 |
V_108 | V_109 ;
F_47 ( V_55 , V_95 ) ;
F_48 ( V_55 , V_110 ) ;
error = F_49 ( V_55 , & V_23 -> V_13 ) ;
if ( error ) {
F_26 ( L_12 , V_111 ) ;
F_50 ( V_55 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
struct V_22 * V_23 ;
struct V_10 * V_55 ;
V_23 = F_45 ( V_13 ) ;
V_55 = V_23 -> V_55 ;
F_52 ( V_55 ) ;
F_50 ( V_55 ) ;
return 0 ;
}
static void F_53 ( struct V_12 * V_13 )
{
struct V_22 * V_23 = F_45 ( V_13 ) ;
F_38 ( V_23 ) ;
}
static int F_54 ( struct V_22 * V_23 , int V_112 )
{
int V_71 ;
V_23 -> V_13 . V_113 = & V_114 ;
V_23 -> V_13 . V_115 = V_116 ;
V_23 -> V_13 . V_74 = & F_53 ;
F_55 ( & V_23 -> V_13 , L_13 , V_112 ) ;
V_71 = F_56 ( & V_23 -> V_13 ) ;
if ( V_71 ) {
F_26 ( L_14
L_15 , V_71 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_57 ( void )
{
int V_71 ;
V_116 = F_58 ( L_16 ) ;
if ( F_59 ( V_116 ) ) {
F_26 ( L_17 ) ;
return F_60 ( V_116 ) ;
}
V_71 = F_61 ( & V_114 ) ;
if ( V_71 ) {
F_26 ( L_18 ) ;
goto V_117;
}
V_71 = F_62 ( & V_118 ) ;
if ( V_71 ) {
F_26 ( L_19
L_20 ) ;
goto V_119;
}
F_24 ( L_21 ) ;
return V_71 ;
V_119:
F_63 ( & V_114 ) ;
V_117:
F_64 ( V_116 ) ;
return V_71 ;
}
static void F_65 ( void )
{
F_66 ( & V_118 ) ;
F_63 ( & V_114 ) ;
F_64 ( V_116 ) ;
F_24 ( L_22 ) ;
}
static char * F_67 ( void )
{
return L_23 ;
}
static T_2 F_68 ( struct V_67 * V_68 )
{
struct V_24 * V_25 = V_68 -> V_120 ;
struct V_22 * V_23 = V_25 -> V_23 ;
switch ( V_23 -> V_121 ) {
case V_122 :
return F_69 ( V_68 ) ;
case V_123 :
return F_70 ( V_68 ) ;
case V_124 :
return F_71 ( V_68 ) ;
default:
F_26 ( L_24
L_25 , V_23 -> V_121 ) ;
break;
}
return F_69 ( V_68 ) ;
}
static char * F_72 ( struct V_67 * V_68 )
{
struct V_24 * V_25 = V_68 -> V_120 ;
return & V_25 -> V_23 -> V_125 [ 0 ] ;
}
static T_3 F_73 ( struct V_67 * V_68 )
{
struct V_24 * V_25 = V_68 -> V_120 ;
return V_25 -> V_126 ;
}
static T_1 F_74 ( struct V_67 * V_68 )
{
return 1 ;
}
static T_1 F_75 (
struct V_67 * V_68 ,
struct V_127 * V_128 ,
struct V_129 * V_130 ,
int * V_131 ,
unsigned char * V_132 )
{
struct V_24 * V_25 = V_68 -> V_120 ;
struct V_22 * V_23 = V_25 -> V_23 ;
switch ( V_23 -> V_121 ) {
case V_122 :
return F_76 ( V_68 , V_128 , V_130 ,
V_131 , V_132 ) ;
case V_123 :
return F_77 ( V_68 , V_128 , V_130 ,
V_131 , V_132 ) ;
case V_124 :
return F_78 ( V_68 , V_128 , V_130 ,
V_131 , V_132 ) ;
default:
F_26 ( L_24
L_25 , V_23 -> V_121 ) ;
break;
}
return F_76 ( V_68 , V_128 , V_130 ,
V_131 , V_132 ) ;
}
static T_1 F_79 (
struct V_67 * V_68 ,
struct V_127 * V_128 ,
struct V_129 * V_130 ,
int * V_131 )
{
struct V_24 * V_25 = V_68 -> V_120 ;
struct V_22 * V_23 = V_25 -> V_23 ;
switch ( V_23 -> V_121 ) {
case V_122 :
return F_80 ( V_68 , V_128 , V_130 ,
V_131 ) ;
case V_123 :
return F_81 ( V_68 , V_128 , V_130 ,
V_131 ) ;
case V_124 :
return F_82 ( V_68 , V_128 , V_130 ,
V_131 ) ;
default:
F_26 ( L_24
L_25 , V_23 -> V_121 ) ;
break;
}
return F_80 ( V_68 , V_128 , V_130 ,
V_131 ) ;
}
static char * F_83 (
struct V_67 * V_68 ,
const char * V_132 ,
T_1 * V_133 ,
char * * V_134 )
{
struct V_24 * V_25 = V_68 -> V_120 ;
struct V_22 * V_23 = V_25 -> V_23 ;
switch ( V_23 -> V_121 ) {
case V_122 :
return F_84 ( V_68 , V_132 , V_133 ,
V_134 ) ;
case V_123 :
return F_85 ( V_68 , V_132 , V_133 ,
V_134 ) ;
case V_124 :
return F_86 ( V_68 , V_132 , V_133 ,
V_134 ) ;
default:
F_26 ( L_24
L_25 , V_23 -> V_121 ) ;
break;
}
return F_84 ( V_68 , V_132 , V_133 ,
V_134 ) ;
}
static int F_87 ( struct V_67 * V_68 )
{
return 1 ;
}
static int F_88 ( struct V_67 * V_68 )
{
return 0 ;
}
static int F_89 ( struct V_67 * V_68 )
{
return 0 ;
}
static int F_90 ( struct V_67 * V_68 )
{
return 0 ;
}
static struct V_127 * F_91 (
struct V_67 * V_68 )
{
struct V_135 * V_136 ;
V_136 = F_30 ( sizeof( struct V_135 ) , V_73 ) ;
if ( ! V_136 ) {
F_26 ( L_26 ) ;
return NULL ;
}
return & V_136 -> V_127 ;
}
static void F_92 (
struct V_67 * V_68 ,
struct V_127 * V_128 )
{
struct V_135 * V_136 = F_4 ( V_128 ,
struct V_135 , V_127 ) ;
F_38 ( V_136 ) ;
}
static T_1 F_93 ( struct V_67 * V_68 )
{
return 1 ;
}
static T_1 F_94 ( struct V_66 * V_48 )
{
return 1 ;
}
static void F_95 ( struct V_127 * V_137 )
{
return;
}
static T_1 F_96 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_59 ;
}
static int F_97 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_138 ;
}
static int F_98 ( struct V_66 * V_48 )
{
return 0 ;
}
static void F_99 ( struct V_66 * V_48 )
{
return;
}
static int F_100 ( struct V_1 * V_1 )
{
F_101 ( V_1 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_103 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_24 ( L_27
L_28 , V_19 , V_19 -> V_49 [ 0 ] ) ;
V_19 -> V_139 = V_140 ;
F_11 ( V_19 , V_141 ) ;
if ( ( V_1 -> V_2 & V_142 ) ||
( V_1 -> V_2 & V_143 ) )
F_104 ( V_19 , V_1 -> V_144 ) ;
V_19 -> V_54 ( V_19 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_24 ( L_29
L_28 , V_19 , V_19 -> V_49 [ 0 ] ) ;
if ( V_1 -> V_145 &&
( ( V_1 -> V_2 & V_146 ) ||
( V_1 -> V_2 & V_147 ) ) ) {
memcpy ( V_19 -> V_145 , V_1 -> V_145 ,
V_148 ) ;
V_19 -> V_139 = V_149 ;
F_106 ( V_19 , V_150 ) ;
} else
V_19 -> V_139 = V_1 -> V_151 ;
F_11 ( V_19 , V_141 ) ;
if ( ( V_1 -> V_2 & V_142 ) ||
( V_1 -> V_2 & V_143 ) )
F_104 ( V_19 , V_1 -> V_144 ) ;
V_19 -> V_54 ( V_19 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_1 )
{
struct V_80 * V_152 = V_1 -> V_80 ;
struct V_69 * V_70 = V_152 -> V_153 ;
F_108 ( & V_70 -> V_83 , 1 ) ;
F_109 ( & V_70 -> V_75 ) ;
}
static void F_110 ( struct V_1 * V_1 )
{
return;
}
static char * F_111 ( struct V_22 * V_23 )
{
switch ( V_23 -> V_121 ) {
case V_122 :
return L_30 ;
case V_123 :
return L_31 ;
case V_124 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_112 (
struct V_67 * V_68 ,
struct V_154 * V_51 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 = V_25 -> V_23 ;
F_113 ( & V_25 -> V_155 ) ;
F_114 ( V_23 -> V_55 , 0 , V_25 -> V_126 , V_51 -> V_156 ) ;
F_24 ( L_34 ) ;
return 0 ;
}
static void F_115 (
struct V_67 * V_68 ,
struct V_154 * V_154 )
{
struct V_90 * V_91 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_25 = F_4 ( V_68 , struct V_24 , V_76 ) ;
V_23 = V_25 -> V_23 ;
V_91 = F_116 ( V_23 -> V_55 , 0 , V_25 -> V_126 ,
V_154 -> V_156 ) ;
if ( ! V_91 ) {
F_26 ( L_35
L_36 , 0 , V_25 -> V_126 , V_154 -> V_156 ) ;
return;
}
F_117 ( V_91 ) ;
F_118 ( V_91 ) ;
F_119 ( & V_25 -> V_155 ) ;
F_24 ( L_37 ) ;
}
static int F_120 (
struct V_24 * V_25 ,
const char * V_157 )
{
struct V_67 * V_68 ;
struct V_22 * V_23 = V_25 -> V_23 ;
struct V_20 * V_21 ;
int V_71 = - V_158 ;
if ( V_25 -> V_21 ) {
F_24 ( L_38 ) ;
return - V_159 ;
}
V_68 = & V_25 -> V_76 ;
V_21 = F_30 ( sizeof( struct V_20 ) , V_73 ) ;
if ( ! V_21 ) {
F_26 ( L_39 ) ;
return - V_158 ;
}
V_21 -> V_48 = F_121 ( V_160 ) ;
if ( F_59 ( V_21 -> V_48 ) ) {
V_71 = F_60 ( V_21 -> V_48 ) ;
goto V_161;
}
V_21 -> V_48 -> V_127 = F_122 (
V_68 , ( unsigned char * ) V_157 ) ;
if ( ! V_21 -> V_48 -> V_127 ) {
F_123 ( V_21 -> V_48 ) ;
goto V_161;
}
F_124 ( V_68 , V_21 -> V_48 -> V_127 ,
V_21 -> V_48 , V_21 ) ;
V_25 -> V_21 = V_21 ;
F_24 ( L_40
L_41 , F_111 ( V_23 ) ,
V_157 ) ;
return 0 ;
V_161:
F_38 ( V_21 ) ;
return V_71 ;
}
static int F_125 (
struct V_24 * V_162 )
{
struct V_66 * V_48 ;
struct V_20 * V_21 ;
V_21 = V_162 -> V_21 ;
if ( ! V_21 )
return - V_97 ;
V_48 = V_21 -> V_48 ;
if ( ! V_48 )
return - V_97 ;
if ( F_37 ( & V_162 -> V_155 ) ) {
F_26 ( L_42
L_43 ,
F_37 ( & V_162 -> V_155 ) ) ;
return - V_163 ;
}
F_24 ( L_44
L_41 , F_111 ( V_162 -> V_23 ) ,
V_21 -> V_48 -> V_127 -> V_164 ) ;
F_126 ( V_21 -> V_48 ) ;
V_162 -> V_21 = NULL ;
F_38 ( V_21 ) ;
return 0 ;
}
static T_4 F_127 (
struct V_67 * V_68 ,
char * V_165 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_20 * V_21 ;
T_4 V_71 ;
V_21 = V_25 -> V_21 ;
if ( ! V_21 )
return - V_97 ;
V_71 = snprintf ( V_165 , V_166 , L_45 ,
V_21 -> V_48 -> V_127 -> V_164 ) ;
return V_71 ;
}
static T_4 F_128 (
struct V_67 * V_68 ,
const char * V_165 ,
T_5 V_167 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned char V_168 [ V_169 ] , * V_170 , * V_171 ;
int V_71 ;
if ( ! strncmp ( V_165 , L_46 , 4 ) ) {
V_71 = F_125 ( V_25 ) ;
return ( ! V_71 ) ? V_167 : V_71 ;
}
if ( strlen ( V_165 ) >= V_169 ) {
F_26 ( L_47
L_48 , V_165 , V_169 ) ;
return - V_172 ;
}
snprintf ( & V_168 [ 0 ] , V_169 , L_49 , V_165 ) ;
V_170 = strstr ( V_168 , L_50 ) ;
if ( V_170 ) {
if ( V_23 -> V_121 != V_122 ) {
F_26 ( L_51
L_52 , V_168 ,
F_111 ( V_23 ) ) ;
return - V_172 ;
}
V_171 = & V_168 [ 0 ] ;
goto V_173;
}
V_170 = strstr ( V_168 , L_53 ) ;
if ( V_170 ) {
if ( V_23 -> V_121 != V_123 ) {
F_26 ( L_54
L_52 , V_168 ,
F_111 ( V_23 ) ) ;
return - V_172 ;
}
V_171 = & V_168 [ 3 ] ;
goto V_173;
}
V_170 = strstr ( V_168 , L_55 ) ;
if ( V_170 ) {
if ( V_23 -> V_121 != V_124 ) {
F_26 ( L_56
L_52 , V_168 ,
F_111 ( V_23 ) ) ;
return - V_172 ;
}
V_171 = & V_168 [ 0 ] ;
goto V_173;
}
F_26 ( L_57
L_58 , V_168 ) ;
return - V_172 ;
V_173:
if ( V_168 [ strlen ( V_168 ) - 1 ] == '\n' )
V_168 [ strlen ( V_168 ) - 1 ] = '\0' ;
V_71 = F_120 ( V_25 , V_171 ) ;
if ( V_71 < 0 )
return V_71 ;
return V_167 ;
}
static T_4 F_129 (
struct V_67 * V_68 ,
char * V_165 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
const char * V_174 = NULL ;
T_4 V_71 = - V_172 ;
switch ( V_25 -> V_35 ) {
case V_89 :
V_174 = L_59 ;
break;
case V_36 :
V_174 = L_60 ;
break;
default:
break;
}
if ( V_174 )
V_71 = snprintf ( V_165 , V_166 , L_45 , V_174 ) ;
return V_71 ;
}
static T_4 F_130 (
struct V_67 * V_68 ,
const char * V_165 ,
T_5 V_167 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
if ( ! strncmp ( V_165 , L_59 , 6 ) ) {
V_25 -> V_35 = V_89 ;
return V_167 ;
}
if ( ! strncmp ( V_165 , L_60 , 7 ) ) {
V_25 -> V_35 = V_36 ;
return V_167 ;
}
return - V_172 ;
}
static struct V_67 * F_131 (
struct V_175 * V_176 ,
struct V_177 * V_178 ,
const char * V_157 )
{
struct V_22 * V_23 = F_4 ( V_176 ,
struct V_22 , V_179 ) ;
struct V_24 * V_25 ;
char * V_180 , * V_181 ;
int V_71 ;
unsigned short int V_182 ;
V_180 = strstr ( V_157 , L_61 ) ;
if ( ! V_180 ) {
F_26 ( L_62
L_63 ) ;
return F_132 ( - V_172 ) ;
}
V_180 += 5 ;
V_182 = ( unsigned short int ) F_133 ( V_180 , & V_181 , 0 ) ;
if ( V_182 >= V_183 ) {
F_26 ( L_64
L_65 , V_182 , V_183 ) ;
return F_132 ( - V_172 ) ;
}
V_25 = & V_23 -> V_31 [ V_182 ] ;
V_25 -> V_23 = V_23 ;
V_25 -> V_126 = V_182 ;
V_71 = F_134 ( & V_184 -> V_185 ,
V_176 , & V_25 -> V_76 , V_25 ,
V_186 ) ;
if ( V_71 < 0 )
return F_132 ( - V_158 ) ;
F_24 ( L_66
L_67 , F_111 ( V_23 ) ,
F_135 ( & V_176 -> V_187 . V_188 ) , V_182 ) ;
return & V_25 -> V_76 ;
}
static void F_136 (
struct V_67 * V_68 )
{
struct V_175 * V_176 = V_68 -> V_189 ;
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 ;
unsigned short V_182 ;
V_23 = V_25 -> V_23 ;
V_182 = V_25 -> V_126 ;
F_125 ( V_25 ) ;
F_137 ( V_68 ) ;
V_25 -> V_23 = NULL ;
V_25 -> V_126 = 0 ;
F_24 ( L_68
L_67 , F_111 ( V_23 ) ,
F_135 ( & V_176 -> V_187 . V_188 ) , V_182 ) ;
}
static struct V_175 * F_138 (
struct V_190 * V_191 ,
struct V_177 * V_178 ,
const char * V_157 )
{
struct V_22 * V_23 ;
struct V_10 * V_55 ;
char * V_170 ;
int V_71 , V_192 = 0 ;
V_23 = F_30 ( sizeof( struct V_22 ) , V_73 ) ;
if ( ! V_23 ) {
F_26 ( L_69 ) ;
return F_132 ( - V_158 ) ;
}
V_170 = strstr ( V_157 , L_50 ) ;
if ( V_170 ) {
V_23 -> V_121 = V_122 ;
goto V_193;
}
V_170 = strstr ( V_157 , L_53 ) ;
if ( V_170 ) {
V_23 -> V_121 = V_123 ;
V_192 = 3 ;
goto V_193;
}
V_170 = strstr ( V_157 , L_55 ) ;
if ( ! V_170 ) {
F_26 ( L_70
L_71 , V_157 ) ;
V_71 = - V_172 ;
goto V_161;
}
V_23 -> V_121 = V_124 ;
V_193:
if ( strlen ( V_157 ) >= V_169 ) {
F_26 ( L_72
L_48 , V_157 , F_111 ( V_23 ) ,
V_169 ) ;
V_71 = - V_172 ;
goto V_161;
}
snprintf ( & V_23 -> V_125 [ 0 ] , V_169 , L_49 , & V_157 [ V_192 ] ) ;
V_71 = F_54 ( V_23 , V_194 ) ;
if ( V_71 )
goto V_161;
V_55 = V_23 -> V_55 ;
V_194 ++ ;
F_24 ( L_73
L_74 ,
F_111 ( V_23 ) , V_157 , V_55 -> V_56 ) ;
return & V_23 -> V_179 ;
V_161:
F_38 ( V_23 ) ;
return F_132 ( V_71 ) ;
}
static void F_139 (
struct V_175 * V_176 )
{
struct V_22 * V_23 = F_4 ( V_176 ,
struct V_22 , V_179 ) ;
F_24 ( L_75
L_76 ,
V_23 -> V_125 , V_23 -> V_55 -> V_56 ) ;
F_140 ( & V_23 -> V_13 ) ;
}
static T_4 F_141 (
struct V_190 * V_191 ,
char * V_165 )
{
return sprintf ( V_165 , L_77 , V_195 ) ;
}
static int F_142 ( void )
{
struct V_190 * V_196 ;
int V_71 ;
V_194 = 0 ;
V_196 = F_143 ( V_197 , L_23 ) ;
if ( F_59 ( V_196 ) ) {
F_26 ( L_78 ) ;
return F_60 ( V_196 ) ;
}
V_196 -> V_185 . V_198 = & F_67 ;
V_196 -> V_185 . V_199 = & F_68 ;
V_196 -> V_185 . V_200 = & F_72 ;
V_196 -> V_185 . V_201 = & F_73 ;
V_196 -> V_185 . V_202 = & F_74 ;
V_196 -> V_185 . V_203 = & F_75 ;
V_196 -> V_185 . V_204 =
& F_79 ;
V_196 -> V_185 . V_205 =
& F_83 ;
V_196 -> V_185 . V_206 = & F_87 ;
V_196 -> V_185 . V_207 =
& F_88 ;
V_196 -> V_185 . V_208 =
& F_89 ;
V_196 -> V_185 . V_209 =
& F_90 ;
V_196 -> V_185 . V_210 = & F_91 ;
V_196 -> V_185 . V_211 =
& F_92 ;
V_196 -> V_185 . V_212 = & F_93 ;
V_196 -> V_185 . V_213 = & F_1 ;
V_196 -> V_185 . V_214 = & F_3 ;
V_196 -> V_185 . V_215 = & F_98 ;
V_196 -> V_185 . V_216 = & F_99 ;
V_196 -> V_185 . V_217 = & F_94 ;
V_196 -> V_185 . V_218 = NULL ;
V_196 -> V_185 . V_219 = & F_100 ;
V_196 -> V_185 . V_220 = & F_102 ;
V_196 -> V_185 . V_221 =
& F_95 ;
V_196 -> V_185 . V_222 = & F_96 ;
V_196 -> V_185 . V_223 = & F_97 ;
V_196 -> V_185 . V_224 = & F_103 ;
V_196 -> V_185 . V_225 = & F_105 ;
V_196 -> V_185 . V_226 = & F_107 ;
V_196 -> V_185 . V_227 = & F_110 ;
V_196 -> V_185 . V_228 = & F_138 ;
V_196 -> V_185 . V_229 = & F_139 ;
V_196 -> V_185 . V_230 = & F_131 ;
V_196 -> V_185 . V_231 = & F_136 ;
V_196 -> V_185 . V_232 = & F_112 ;
V_196 -> V_185 . V_233 = & F_115 ;
V_196 -> V_185 . V_234 = NULL ;
V_196 -> V_185 . V_235 = NULL ;
V_196 -> V_236 . V_237 . V_238 = V_239 ;
V_196 -> V_236 . V_240 . V_238 = V_241 ;
V_196 -> V_236 . V_242 . V_238 = NULL ;
V_196 -> V_236 . V_243 . V_238 = NULL ;
V_196 -> V_236 . V_244 . V_238 = NULL ;
V_71 = F_144 ( V_196 ) ;
if ( V_71 < 0 ) {
F_26 ( L_79
L_80 ) ;
F_145 ( V_196 ) ;
return - 1 ;
}
V_184 = V_196 ;
F_24 ( L_81
L_82 ) ;
return 0 ;
}
static void F_146 ( void )
{
if ( ! V_184 )
return;
F_147 ( V_184 ) ;
V_184 = NULL ;
F_24 ( L_83
L_82 ) ;
}
static int T_6 F_148 ( void )
{
int V_71 = - V_158 ;
V_62 = F_149 ( L_84 , 0 , 0 ) ;
if ( ! V_62 )
goto V_161;
V_7 = F_150 ( L_85 ,
sizeof( struct V_4 ) ,
F_151 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_24 ( L_86
L_87 ) ;
goto V_245;
}
V_71 = F_57 () ;
if ( V_71 )
goto V_246;
V_71 = F_142 () ;
if ( V_71 )
goto V_247;
return 0 ;
V_247:
F_65 () ;
V_246:
F_152 ( V_7 ) ;
V_245:
F_153 ( V_62 ) ;
V_161:
return V_71 ;
}
static void T_7 F_154 ( void )
{
F_146 () ;
F_65 () ;
F_152 ( V_7 ) ;
F_153 ( V_62 ) ;
}
