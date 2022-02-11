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
static int F_91 ( struct V_67 * V_68 )
{
struct V_24 * V_25 = F_4 ( V_68 , struct V_24 ,
V_76 ) ;
return V_25 -> V_135 ;
}
static struct V_127 * F_92 (
struct V_67 * V_68 )
{
struct V_136 * V_137 ;
V_137 = F_30 ( sizeof( struct V_136 ) , V_73 ) ;
if ( ! V_137 ) {
F_26 ( L_26 ) ;
return NULL ;
}
return & V_137 -> V_127 ;
}
static void F_93 (
struct V_67 * V_68 ,
struct V_127 * V_128 )
{
struct V_136 * V_137 = F_4 ( V_128 ,
struct V_136 , V_127 ) ;
F_38 ( V_137 ) ;
}
static T_1 F_94 ( struct V_67 * V_68 )
{
return 1 ;
}
static T_1 F_95 ( struct V_66 * V_48 )
{
return 1 ;
}
static void F_96 ( struct V_127 * V_138 )
{
return;
}
static T_1 F_97 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_59 ;
}
static int F_98 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_139 ;
}
static int F_99 ( struct V_66 * V_48 )
{
return 0 ;
}
static void F_100 ( struct V_66 * V_48 )
{
return;
}
static int F_101 ( struct V_1 * V_1 )
{
F_102 ( V_1 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_104 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_24 ( L_27
L_28 , V_19 , V_19 -> V_49 [ 0 ] ) ;
V_19 -> V_140 = V_141 ;
F_11 ( V_19 , V_142 ) ;
if ( ( V_1 -> V_2 & V_143 ) ||
( V_1 -> V_2 & V_144 ) )
F_105 ( V_19 , V_1 -> V_145 ) ;
V_19 -> V_54 ( V_19 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_24 ( L_29
L_28 , V_19 , V_19 -> V_49 [ 0 ] ) ;
if ( V_1 -> V_146 &&
( ( V_1 -> V_2 & V_147 ) ||
( V_1 -> V_2 & V_148 ) ) ) {
memcpy ( V_19 -> V_146 , V_1 -> V_146 ,
V_149 ) ;
V_19 -> V_140 = V_150 ;
F_107 ( V_19 , V_151 ) ;
} else
V_19 -> V_140 = V_1 -> V_152 ;
F_11 ( V_19 , V_142 ) ;
if ( ( V_1 -> V_2 & V_143 ) ||
( V_1 -> V_2 & V_144 ) )
F_105 ( V_19 , V_1 -> V_145 ) ;
V_19 -> V_54 ( V_19 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_1 )
{
struct V_80 * V_153 = V_1 -> V_80 ;
struct V_69 * V_70 = V_153 -> V_154 ;
F_109 ( & V_70 -> V_83 , 1 ) ;
F_110 ( & V_70 -> V_75 ) ;
}
static void F_111 ( struct V_1 * V_1 )
{
return;
}
static char * F_112 ( struct V_22 * V_23 )
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
static int F_113 (
struct V_67 * V_68 ,
struct V_155 * V_51 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 = V_25 -> V_23 ;
F_114 ( & V_25 -> V_156 ) ;
F_115 ( V_23 -> V_55 , 0 , V_25 -> V_126 , V_51 -> V_157 ) ;
F_24 ( L_34 ) ;
return 0 ;
}
static void F_116 (
struct V_67 * V_68 ,
struct V_155 * V_155 )
{
struct V_90 * V_91 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_25 = F_4 ( V_68 , struct V_24 , V_76 ) ;
V_23 = V_25 -> V_23 ;
V_91 = F_117 ( V_23 -> V_55 , 0 , V_25 -> V_126 ,
V_155 -> V_157 ) ;
if ( ! V_91 ) {
F_26 ( L_35
L_36 , 0 , V_25 -> V_126 , V_155 -> V_157 ) ;
return;
}
F_118 ( V_91 ) ;
F_119 ( V_91 ) ;
F_120 ( & V_25 -> V_156 ) ;
F_24 ( L_37 ) ;
}
static T_4 F_121 (
struct V_67 * V_68 ,
char * V_158 )
{
struct V_24 * V_25 = F_4 ( V_68 , struct V_24 ,
V_76 ) ;
return sprintf ( V_158 , L_36 , V_25 -> V_135 ) ;
}
static T_4 F_122 (
struct V_67 * V_68 ,
const char * V_158 ,
T_5 V_159 )
{
struct V_24 * V_25 = F_4 ( V_68 , struct V_24 ,
V_76 ) ;
unsigned long V_160 ;
int V_71 = F_123 ( V_158 , 0 , & V_160 ) ;
if ( V_71 ) {
F_26 ( L_38 , V_71 ) ;
return V_71 ;
}
if ( V_160 != 0 && V_160 != 1 && V_160 != 3 ) {
F_26 ( L_39 , V_160 ) ;
return - V_161 ;
}
V_25 -> V_135 = V_160 ;
return V_159 ;
}
static int F_124 (
struct V_24 * V_25 ,
const char * V_162 )
{
struct V_67 * V_68 ;
struct V_22 * V_23 = V_25 -> V_23 ;
struct V_20 * V_21 ;
int V_71 = - V_163 ;
if ( V_25 -> V_21 ) {
F_24 ( L_40 ) ;
return - V_164 ;
}
V_68 = & V_25 -> V_76 ;
V_21 = F_30 ( sizeof( struct V_20 ) , V_73 ) ;
if ( ! V_21 ) {
F_26 ( L_41 ) ;
return - V_163 ;
}
V_21 -> V_48 = F_125 (
V_165 | V_166 ) ;
if ( F_59 ( V_21 -> V_48 ) ) {
V_71 = F_60 ( V_21 -> V_48 ) ;
goto V_167;
}
V_21 -> V_48 -> V_127 = F_126 (
V_68 , ( unsigned char * ) V_162 ) ;
if ( ! V_21 -> V_48 -> V_127 ) {
F_127 ( V_21 -> V_48 ) ;
goto V_167;
}
F_128 ( V_68 , V_21 -> V_48 -> V_127 ,
V_21 -> V_48 , V_21 ) ;
V_25 -> V_21 = V_21 ;
F_24 ( L_42
L_43 , F_112 ( V_23 ) ,
V_162 ) ;
return 0 ;
V_167:
F_38 ( V_21 ) ;
return V_71 ;
}
static int F_129 (
struct V_24 * V_168 )
{
struct V_66 * V_48 ;
struct V_20 * V_21 ;
V_21 = V_168 -> V_21 ;
if ( ! V_21 )
return - V_97 ;
V_48 = V_21 -> V_48 ;
if ( ! V_48 )
return - V_97 ;
if ( F_37 ( & V_168 -> V_156 ) ) {
F_26 ( L_44
L_45 ,
F_37 ( & V_168 -> V_156 ) ) ;
return - V_169 ;
}
F_24 ( L_46
L_43 , F_112 ( V_168 -> V_23 ) ,
V_21 -> V_48 -> V_127 -> V_170 ) ;
F_130 ( V_21 -> V_48 ) ;
V_168 -> V_21 = NULL ;
F_38 ( V_21 ) ;
return 0 ;
}
static T_4 F_131 (
struct V_67 * V_68 ,
char * V_158 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_20 * V_21 ;
T_4 V_71 ;
V_21 = V_25 -> V_21 ;
if ( ! V_21 )
return - V_97 ;
V_71 = snprintf ( V_158 , V_171 , L_47 ,
V_21 -> V_48 -> V_127 -> V_170 ) ;
return V_71 ;
}
static T_4 F_132 (
struct V_67 * V_68 ,
const char * V_158 ,
T_5 V_159 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned char V_172 [ V_173 ] , * V_174 , * V_175 ;
int V_71 ;
if ( ! strncmp ( V_158 , L_48 , 4 ) ) {
V_71 = F_129 ( V_25 ) ;
return ( ! V_71 ) ? V_159 : V_71 ;
}
if ( strlen ( V_158 ) >= V_173 ) {
F_26 ( L_49
L_50 , V_158 , V_173 ) ;
return - V_161 ;
}
snprintf ( & V_172 [ 0 ] , V_173 , L_51 , V_158 ) ;
V_174 = strstr ( V_172 , L_52 ) ;
if ( V_174 ) {
if ( V_23 -> V_121 != V_122 ) {
F_26 ( L_53
L_54 , V_172 ,
F_112 ( V_23 ) ) ;
return - V_161 ;
}
V_175 = & V_172 [ 0 ] ;
goto V_176;
}
V_174 = strstr ( V_172 , L_55 ) ;
if ( V_174 ) {
if ( V_23 -> V_121 != V_123 ) {
F_26 ( L_56
L_54 , V_172 ,
F_112 ( V_23 ) ) ;
return - V_161 ;
}
V_175 = & V_172 [ 3 ] ;
goto V_176;
}
V_174 = strstr ( V_172 , L_57 ) ;
if ( V_174 ) {
if ( V_23 -> V_121 != V_124 ) {
F_26 ( L_58
L_54 , V_172 ,
F_112 ( V_23 ) ) ;
return - V_161 ;
}
V_175 = & V_172 [ 0 ] ;
goto V_176;
}
F_26 ( L_59
L_60 , V_172 ) ;
return - V_161 ;
V_176:
if ( V_172 [ strlen ( V_172 ) - 1 ] == '\n' )
V_172 [ strlen ( V_172 ) - 1 ] = '\0' ;
V_71 = F_124 ( V_25 , V_175 ) ;
if ( V_71 < 0 )
return V_71 ;
return V_159 ;
}
static T_4 F_133 (
struct V_67 * V_68 ,
char * V_158 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
const char * V_177 = NULL ;
T_4 V_71 = - V_161 ;
switch ( V_25 -> V_35 ) {
case V_89 :
V_177 = L_61 ;
break;
case V_36 :
V_177 = L_62 ;
break;
default:
break;
}
if ( V_177 )
V_71 = snprintf ( V_158 , V_171 , L_47 , V_177 ) ;
return V_71 ;
}
static T_4 F_134 (
struct V_67 * V_68 ,
const char * V_158 ,
T_5 V_159 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
if ( ! strncmp ( V_158 , L_61 , 6 ) ) {
V_25 -> V_35 = V_89 ;
return V_159 ;
}
if ( ! strncmp ( V_158 , L_62 , 7 ) ) {
V_25 -> V_35 = V_36 ;
return V_159 ;
}
return - V_161 ;
}
static struct V_67 * F_135 (
struct V_178 * V_179 ,
struct V_180 * V_181 ,
const char * V_162 )
{
struct V_22 * V_23 = F_4 ( V_179 ,
struct V_22 , V_182 ) ;
struct V_24 * V_25 ;
int V_71 ;
unsigned long V_183 ;
if ( strstr ( V_162 , L_63 ) != V_162 ) {
F_26 ( L_64
L_65 ) ;
return F_136 ( - V_161 ) ;
}
if ( F_123 ( V_162 + 5 , 10 , & V_183 ) )
return F_136 ( - V_161 ) ;
if ( V_183 >= V_184 ) {
F_26 ( L_66
L_67 , V_183 , V_184 ) ;
return F_136 ( - V_161 ) ;
}
V_25 = & V_23 -> V_31 [ V_183 ] ;
V_25 -> V_23 = V_23 ;
V_25 -> V_126 = V_183 ;
V_71 = F_137 ( & V_185 , V_179 , & V_25 -> V_76 , V_25 ,
V_186 ) ;
if ( V_71 < 0 )
return F_136 ( - V_163 ) ;
F_24 ( L_68
L_69 , F_112 ( V_23 ) ,
F_138 ( & V_179 -> V_187 . V_188 ) , V_183 ) ;
return & V_25 -> V_76 ;
}
static void F_139 (
struct V_67 * V_68 )
{
struct V_178 * V_179 = V_68 -> V_189 ;
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 ;
unsigned short V_183 ;
V_23 = V_25 -> V_23 ;
V_183 = V_25 -> V_126 ;
F_129 ( V_25 ) ;
F_140 ( V_68 ) ;
V_25 -> V_23 = NULL ;
V_25 -> V_126 = 0 ;
F_24 ( L_70
L_71 , F_112 ( V_23 ) ,
F_138 ( & V_179 -> V_187 . V_188 ) , V_183 ) ;
}
static struct V_178 * F_141 (
struct V_190 * V_191 ,
struct V_180 * V_181 ,
const char * V_162 )
{
struct V_22 * V_23 ;
struct V_10 * V_55 ;
char * V_174 ;
int V_71 , V_192 = 0 ;
V_23 = F_30 ( sizeof( struct V_22 ) , V_73 ) ;
if ( ! V_23 ) {
F_26 ( L_72 ) ;
return F_136 ( - V_163 ) ;
}
V_174 = strstr ( V_162 , L_52 ) ;
if ( V_174 ) {
V_23 -> V_121 = V_122 ;
goto V_193;
}
V_174 = strstr ( V_162 , L_55 ) ;
if ( V_174 ) {
V_23 -> V_121 = V_123 ;
V_192 = 3 ;
goto V_193;
}
V_174 = strstr ( V_162 , L_57 ) ;
if ( ! V_174 ) {
F_26 ( L_73
L_74 , V_162 ) ;
V_71 = - V_161 ;
goto V_167;
}
V_23 -> V_121 = V_124 ;
V_193:
if ( strlen ( V_162 ) >= V_173 ) {
F_26 ( L_75
L_50 , V_162 , F_112 ( V_23 ) ,
V_173 ) ;
V_71 = - V_161 ;
goto V_167;
}
snprintf ( & V_23 -> V_125 [ 0 ] , V_173 , L_51 , & V_162 [ V_192 ] ) ;
V_71 = F_54 ( V_23 , V_194 ) ;
if ( V_71 )
goto V_167;
V_55 = V_23 -> V_55 ;
V_194 ++ ;
F_24 ( L_76
L_77 ,
F_112 ( V_23 ) , V_162 , V_55 -> V_56 ) ;
return & V_23 -> V_182 ;
V_167:
F_38 ( V_23 ) ;
return F_136 ( V_71 ) ;
}
static void F_142 (
struct V_178 * V_179 )
{
struct V_22 * V_23 = F_4 ( V_179 ,
struct V_22 , V_182 ) ;
F_24 ( L_78
L_79 ,
V_23 -> V_125 , V_23 -> V_55 -> V_56 ) ;
F_143 ( & V_23 -> V_13 ) ;
}
static T_4 F_144 (
struct V_190 * V_191 ,
char * V_158 )
{
return sprintf ( V_158 , L_80 , V_195 ) ;
}
static int T_6 F_145 ( void )
{
int V_71 = - V_163 ;
V_62 = F_146 ( L_81 , 0 , 0 ) ;
if ( ! V_62 )
goto V_167;
V_7 = F_147 ( L_82 ,
sizeof( struct V_4 ) ,
F_148 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_24 ( L_83
L_84 ) ;
goto V_196;
}
V_71 = F_57 () ;
if ( V_71 )
goto V_197;
V_71 = F_149 ( & V_185 ) ;
if ( V_71 )
goto V_198;
return 0 ;
V_198:
F_65 () ;
V_197:
F_150 ( V_7 ) ;
V_196:
F_151 ( V_62 ) ;
V_167:
return V_71 ;
}
static void T_7 F_152 ( void )
{
F_153 ( & V_185 ) ;
F_65 () ;
F_150 ( V_7 ) ;
F_151 ( V_62 ) ;
}
