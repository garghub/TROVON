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
F_17 ( V_1 , V_44 -> V_55 . V_56 ,
V_40 -> V_57 ,
F_18 ( V_29 ) , V_29 -> V_58 ,
F_12 ( V_29 ) , & V_5 -> V_59 [ 0 ] ) ;
if ( F_19 ( V_29 ) ) {
struct V_60 * V_61 = F_20 ( V_29 ) ;
V_46 = V_61 -> V_62 . V_63 ;
V_47 = V_61 -> V_62 . V_64 ;
V_1 -> V_2 |= V_65 ;
}
if ( F_21 ( V_1 , V_5 -> V_29 -> V_15 -> V_66 ) < 0 ) {
F_5 ( V_7 , V_5 ) ;
F_15 ( V_29 , V_51 ) ;
goto V_52;
}
if ( V_1 -> V_2 & V_67 &&
V_1 -> V_68 == V_69 ) {
struct V_45 * V_70 = F_22 ( V_29 ) ;
unsigned char * V_71 = F_23 ( F_24 ( V_70 ) ) + V_70 -> V_12 ;
if ( V_71 != NULL ) {
memset ( V_71 , 0 , V_70 -> V_13 ) ;
F_25 ( F_24 ( V_70 ) ) ;
}
}
V_48 = F_26 ( V_1 , V_29 -> V_72 ) ;
if ( V_48 == - V_73 ) {
F_27 ( V_1 ,
V_74 , 0 ) ;
F_2 ( V_1 , 0 ) ;
return;
} else if ( V_48 < 0 ) {
if ( V_1 -> V_2 & V_75 )
F_28 ( V_1 ) ;
else
F_27 ( V_1 ,
V_1 -> V_76 , 0 ) ;
F_2 ( V_1 , 0 ) ;
return;
}
V_48 = F_29 ( V_1 , F_22 ( V_29 ) ,
F_30 ( V_29 ) , V_46 , V_47 ) ;
if ( V_48 ) {
F_27 ( V_1 ,
V_1 -> V_76 , 0 ) ;
F_2 ( V_1 , 0 ) ;
return;
}
F_31 ( V_1 ) ;
return;
V_52:
V_29 -> V_77 ( V_29 ) ;
return;
}
static int F_32 ( struct V_8 * V_78 , struct V_28 * V_29 )
{
struct V_4 * V_5 ;
F_33 ( L_4
L_5 , V_29 -> V_15 -> V_9 -> V_79 ,
V_29 -> V_15 -> V_50 , V_29 -> V_15 -> V_80 , V_29 -> V_15 -> V_66 ,
V_29 -> V_72 [ 0 ] , F_18 ( V_29 ) ) ;
V_5 = F_34 ( V_7 , V_81 ) ;
if ( ! V_5 ) {
F_35 ( L_6 ) ;
F_15 ( V_29 , V_54 ) ;
V_29 -> V_77 ( V_29 ) ;
return 0 ;
}
V_5 -> V_29 = V_29 ;
F_36 ( & V_5 -> V_38 , F_13 ) ;
F_37 ( V_82 , & V_5 -> V_38 ) ;
return 0 ;
}
static int F_38 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = NULL ;
struct V_83 * V_84 ;
struct V_85 * V_57 ;
struct V_4 * V_5 = NULL ;
struct V_41 * V_42 ;
struct V_39 * V_40 ;
struct V_86 * V_87 = NULL ;
struct V_43 * V_44 ;
int V_48 = V_88 , V_89 ;
V_42 = * (struct V_41 * * ) F_14 ( V_29 -> V_15 -> V_9 ) ;
V_40 = V_42 -> V_40 ;
if ( ! V_40 ) {
F_35 ( L_7
L_8 ) ;
return V_88 ;
}
V_57 = V_40 -> V_57 ;
V_44 = & V_42 -> V_49 [ V_29 -> V_15 -> V_50 ] ;
V_84 = & V_44 -> V_55 ;
V_5 = F_34 ( V_7 , V_90 ) ;
if ( ! V_5 ) {
F_35 ( L_9 ) ;
return V_88 ;
}
V_87 = F_39 ( sizeof( struct V_86 ) , V_90 ) ;
if ( ! V_87 ) {
F_35 ( L_10 ) ;
goto V_91;
}
F_40 ( & V_87 -> V_92 ) ;
V_1 = & V_5 -> V_6 ;
F_17 ( V_1 , V_84 -> V_56 , V_57 , 0 ,
V_93 , V_36 ,
& V_5 -> V_59 [ 0 ] ) ;
V_89 = F_41 ( V_1 , V_87 , V_94 , V_90 ) ;
if ( V_89 < 0 )
goto V_91;
if ( F_42 ( V_1 , V_29 -> V_15 -> V_66 ) < 0 )
goto V_91;
F_43 ( V_1 ) ;
F_44 ( V_87 -> V_92 , F_45 ( & V_87 -> V_95 ) ) ;
V_48 = ( V_1 -> V_96 -> V_97 == V_98 ) ?
V_99 : V_88 ;
V_91:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_46 ( V_87 ) ;
return V_48 ;
}
static int F_47 ( struct V_19 * V_100 )
{
F_48 ( V_101 , & V_100 -> V_102 -> V_103 ) ;
return 0 ;
}
static int F_49 ( struct V_19 * V_100 )
{
return 0 ;
}
static int F_50 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_8 * V_78 ;
int error ;
V_42 = F_51 ( V_16 ) ;
V_78 = F_52 ( & V_104 ,
sizeof( struct V_41 ) ) ;
if ( ! V_78 ) {
F_35 ( L_11 ) ;
return - V_105 ;
}
V_42 -> V_78 = V_78 ;
* ( (struct V_41 * * ) V_78 -> V_106 ) = V_42 ;
V_78 -> V_107 = 2 ;
V_78 -> V_108 = 0 ;
V_78 -> V_109 = 0 ;
V_78 -> V_110 = V_111 ;
error = F_53 ( V_78 , & V_42 -> V_16 ) ;
if ( error ) {
F_35 ( L_12 , V_112 ) ;
F_54 ( V_78 ) ;
return - V_105 ;
}
return 0 ;
}
static int F_55 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_8 * V_78 ;
V_42 = F_51 ( V_16 ) ;
V_78 = V_42 -> V_78 ;
F_56 ( V_78 ) ;
F_54 ( V_78 ) ;
return 0 ;
}
static void F_57 ( struct V_15 * V_16 )
{
struct V_41 * V_42 = F_51 ( V_16 ) ;
F_46 ( V_42 ) ;
}
static int F_58 ( struct V_41 * V_42 , int V_113 )
{
int V_48 ;
V_42 -> V_16 . V_114 = & V_115 ;
V_42 -> V_16 . V_116 = V_117 ;
V_42 -> V_16 . V_91 = & F_57 ;
F_59 ( & V_42 -> V_16 , L_13 , V_113 ) ;
V_48 = F_60 ( & V_42 -> V_16 ) ;
if ( V_48 ) {
F_35 ( L_14
L_15 , V_48 ) ;
return - V_105 ;
}
return 0 ;
}
static int F_61 ( void )
{
int V_48 ;
V_117 = F_62 ( L_16 ) ;
if ( F_63 ( V_117 ) ) {
F_35 ( L_17 ) ;
return F_64 ( V_117 ) ;
}
V_48 = F_65 ( & V_115 ) ;
if ( V_48 ) {
F_35 ( L_18 ) ;
goto V_118;
}
V_48 = F_66 ( & V_119 ) ;
if ( V_48 ) {
F_35 ( L_19
L_20 ) ;
goto V_120;
}
F_33 ( L_21 ) ;
return V_48 ;
V_120:
F_67 ( & V_115 ) ;
V_118:
F_68 ( V_117 ) ;
return V_48 ;
}
static void F_69 ( void )
{
F_70 ( & V_119 ) ;
F_67 ( & V_115 ) ;
F_68 ( V_117 ) ;
F_33 ( L_22 ) ;
}
static char * F_71 ( void )
{
return L_23 ;
}
static T_3 F_72 ( struct V_83 * V_84 )
{
struct V_43 * V_44 = V_84 -> V_121 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_122 ) {
case V_123 :
return F_73 ( V_84 ) ;
case V_124 :
return F_74 ( V_84 ) ;
case V_125 :
return F_75 ( V_84 ) ;
default:
F_35 ( L_24
L_25 , V_42 -> V_122 ) ;
break;
}
return F_73 ( V_84 ) ;
}
static char * F_76 ( struct V_83 * V_84 )
{
struct V_43 * V_44 = V_84 -> V_121 ;
return & V_44 -> V_42 -> V_126 [ 0 ] ;
}
static T_4 F_77 ( struct V_83 * V_84 )
{
struct V_43 * V_44 = V_84 -> V_121 ;
return V_44 -> V_127 ;
}
static T_2 F_78 ( struct V_83 * V_84 )
{
return 1 ;
}
static T_2 F_79 (
struct V_83 * V_84 ,
struct V_128 * V_129 ,
struct V_130 * V_131 ,
int * V_132 ,
unsigned char * V_71 )
{
struct V_43 * V_44 = V_84 -> V_121 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_122 ) {
case V_123 :
return F_80 ( V_84 , V_129 , V_131 ,
V_132 , V_71 ) ;
case V_124 :
return F_81 ( V_84 , V_129 , V_131 ,
V_132 , V_71 ) ;
case V_125 :
return F_82 ( V_84 , V_129 , V_131 ,
V_132 , V_71 ) ;
default:
F_35 ( L_24
L_25 , V_42 -> V_122 ) ;
break;
}
return F_80 ( V_84 , V_129 , V_131 ,
V_132 , V_71 ) ;
}
static T_2 F_83 (
struct V_83 * V_84 ,
struct V_128 * V_129 ,
struct V_130 * V_131 ,
int * V_132 )
{
struct V_43 * V_44 = V_84 -> V_121 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_122 ) {
case V_123 :
return F_84 ( V_84 , V_129 , V_131 ,
V_132 ) ;
case V_124 :
return F_85 ( V_84 , V_129 , V_131 ,
V_132 ) ;
case V_125 :
return F_86 ( V_84 , V_129 , V_131 ,
V_132 ) ;
default:
F_35 ( L_24
L_25 , V_42 -> V_122 ) ;
break;
}
return F_84 ( V_84 , V_129 , V_131 ,
V_132 ) ;
}
static char * F_87 (
struct V_83 * V_84 ,
const char * V_71 ,
T_2 * V_133 ,
char * * V_134 )
{
struct V_43 * V_44 = V_84 -> V_121 ;
struct V_41 * V_42 = V_44 -> V_42 ;
switch ( V_42 -> V_122 ) {
case V_123 :
return F_88 ( V_84 , V_71 , V_133 ,
V_134 ) ;
case V_124 :
return F_89 ( V_84 , V_71 , V_133 ,
V_134 ) ;
case V_125 :
return F_90 ( V_84 , V_71 , V_133 ,
V_134 ) ;
default:
F_35 ( L_24
L_25 , V_42 -> V_122 ) ;
break;
}
return F_88 ( V_84 , V_71 , V_133 ,
V_134 ) ;
}
static int F_91 ( struct V_83 * V_84 )
{
return 1 ;
}
static int F_92 ( struct V_83 * V_84 )
{
return 0 ;
}
static int F_93 ( struct V_83 * V_84 )
{
return 0 ;
}
static int F_94 ( struct V_83 * V_84 )
{
return 0 ;
}
static struct V_128 * F_95 (
struct V_83 * V_84 )
{
struct V_135 * V_136 ;
V_136 = F_39 ( sizeof( struct V_135 ) , V_90 ) ;
if ( ! V_136 ) {
F_35 ( L_26 ) ;
return NULL ;
}
return & V_136 -> V_128 ;
}
static void F_96 (
struct V_83 * V_84 ,
struct V_128 * V_129 )
{
struct V_135 * V_136 = F_4 ( V_129 ,
struct V_135 , V_128 ) ;
F_46 ( V_136 ) ;
}
static T_2 F_97 ( struct V_83 * V_84 )
{
return 1 ;
}
static T_2 F_98 ( struct V_85 * V_57 )
{
return 1 ;
}
static void F_99 ( struct V_128 * V_137 )
{
return;
}
static T_2 F_100 ( struct V_1 * V_1 )
{
return 1 ;
}
static int F_101 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_138 ;
}
static int F_102 ( struct V_85 * V_57 )
{
return 0 ;
}
static void F_103 ( struct V_85 * V_57 )
{
return;
}
static int F_104 ( struct V_1 * V_1 )
{
F_105 ( V_1 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_107 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_28 * V_29 = V_5 -> V_29 ;
F_33 ( L_27
L_28 , V_29 , V_29 -> V_72 [ 0 ] ) ;
V_29 -> V_139 = V_140 ;
F_15 ( V_29 , V_141 ) ;
if ( ( V_1 -> V_2 & V_142 ) ||
( V_1 -> V_2 & V_143 ) )
F_108 ( V_29 , V_1 -> V_144 ) ;
V_29 -> V_77 ( V_29 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_28 * V_29 = V_5 -> V_29 ;
F_33 ( L_29
L_28 , V_29 , V_29 -> V_72 [ 0 ] ) ;
if ( V_1 -> V_145 &&
( ( V_1 -> V_2 & V_146 ) ||
( V_1 -> V_2 & V_147 ) ) ) {
memcpy ( V_29 -> V_145 , V_1 -> V_145 ,
V_148 ) ;
V_29 -> V_139 = V_149 ;
F_109 ( V_29 , V_150 ) ;
} else
V_29 -> V_139 = V_1 -> V_151 ;
F_15 ( V_29 , V_141 ) ;
if ( ( V_1 -> V_2 & V_142 ) ||
( V_1 -> V_2 & V_143 ) )
F_108 ( V_29 , V_1 -> V_144 ) ;
V_29 -> V_77 ( V_29 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_1 )
{
struct V_96 * V_152 = V_1 -> V_96 ;
struct V_86 * V_87 = V_152 -> V_153 ;
F_111 ( & V_87 -> V_95 , 1 ) ;
F_112 ( & V_87 -> V_92 ) ;
return 0 ;
}
static T_4 F_113 ( struct V_1 * V_1 , T_2 V_154 )
{
return 0 ;
}
static T_4 F_114 ( void )
{
return 0 ;
}
static char * F_115 ( struct V_41 * V_42 )
{
switch ( V_42 -> V_122 ) {
case V_123 :
return L_30 ;
case V_124 :
return L_31 ;
case V_125 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_116 (
struct V_83 * V_84 ,
struct V_155 * V_66 )
{
struct V_43 * V_44 = F_4 ( V_84 ,
struct V_43 , V_55 ) ;
struct V_41 * V_42 = V_44 -> V_42 ;
F_117 ( & V_44 -> V_156 ) ;
F_118 () ;
F_119 ( V_42 -> V_78 , 0 , V_44 -> V_127 , V_66 -> V_157 ) ;
F_33 ( L_34 ) ;
return 0 ;
}
static void F_120 (
struct V_83 * V_84 ,
struct V_155 * V_155 )
{
struct V_19 * V_100 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_44 = F_4 ( V_84 , struct V_43 , V_55 ) ;
V_42 = V_44 -> V_42 ;
V_100 = F_121 ( V_42 -> V_78 , 0 , V_44 -> V_127 ,
V_155 -> V_157 ) ;
if ( ! V_100 ) {
F_35 ( L_35
L_36 , 0 , V_44 -> V_127 , V_155 -> V_157 ) ;
return;
}
F_122 ( V_100 ) ;
F_123 ( V_100 ) ;
F_124 ( & V_44 -> V_156 ) ;
F_125 () ;
F_33 ( L_37 ) ;
}
static int F_126 (
struct V_43 * V_44 ,
const char * V_158 )
{
struct V_83 * V_84 ;
struct V_41 * V_42 = V_44 -> V_42 ;
struct V_39 * V_40 ;
int V_48 = - V_73 ;
if ( V_44 -> V_42 -> V_40 ) {
F_33 ( L_38 ) ;
return - V_159 ;
}
V_84 = & V_44 -> V_55 ;
V_40 = F_39 ( sizeof( struct V_39 ) , V_90 ) ;
if ( ! V_40 ) {
F_35 ( L_39 ) ;
return - V_73 ;
}
V_40 -> V_57 = F_127 () ;
if ( F_63 ( V_40 -> V_57 ) ) {
V_48 = F_64 ( V_40 -> V_57 ) ;
goto V_160;
}
V_40 -> V_57 -> V_128 = F_128 (
V_84 , ( unsigned char * ) V_158 ) ;
if ( ! V_40 -> V_57 -> V_128 ) {
F_129 ( V_40 -> V_57 ) ;
goto V_160;
}
F_130 ( V_84 , V_40 -> V_57 -> V_128 ,
V_40 -> V_57 , V_40 ) ;
V_44 -> V_42 -> V_40 = V_40 ;
F_33 ( L_40
L_41 , F_115 ( V_42 ) ,
V_158 ) ;
return 0 ;
V_160:
F_46 ( V_40 ) ;
return V_48 ;
}
static int F_131 (
struct V_43 * V_161 )
{
struct V_85 * V_57 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = V_161 -> V_42 ;
V_40 = V_161 -> V_42 -> V_40 ;
if ( ! V_40 )
return - V_105 ;
V_57 = V_40 -> V_57 ;
if ( ! V_57 )
return - V_105 ;
if ( F_45 ( & V_161 -> V_156 ) ) {
F_35 ( L_42
L_43 ,
F_45 ( & V_161 -> V_156 ) ) ;
return - V_162 ;
}
F_33 ( L_44
L_41 , F_115 ( V_42 ) ,
V_40 -> V_57 -> V_128 -> V_163 ) ;
F_132 ( V_40 -> V_57 ) ;
V_161 -> V_42 -> V_40 = NULL ;
F_46 ( V_40 ) ;
return 0 ;
}
static T_5 F_133 (
struct V_83 * V_84 ,
char * V_164 )
{
struct V_43 * V_44 = F_4 ( V_84 ,
struct V_43 , V_55 ) ;
struct V_39 * V_40 ;
T_5 V_48 ;
V_40 = V_44 -> V_42 -> V_40 ;
if ( ! V_40 )
return - V_105 ;
V_48 = snprintf ( V_164 , V_165 , L_45 ,
V_40 -> V_57 -> V_128 -> V_163 ) ;
return V_48 ;
}
static T_5 F_134 (
struct V_83 * V_84 ,
const char * V_164 ,
T_6 V_166 )
{
struct V_43 * V_44 = F_4 ( V_84 ,
struct V_43 , V_55 ) ;
struct V_41 * V_42 = V_44 -> V_42 ;
unsigned char V_167 [ V_168 ] , * V_169 , * V_170 ;
int V_48 ;
if ( ! strncmp ( V_164 , L_46 , 4 ) ) {
V_48 = F_131 ( V_44 ) ;
return ( ! V_48 ) ? V_166 : V_48 ;
}
if ( strlen ( V_164 ) >= V_168 ) {
F_35 ( L_47
L_48 , V_164 , V_168 ) ;
return - V_171 ;
}
snprintf ( & V_167 [ 0 ] , V_168 , L_49 , V_164 ) ;
V_169 = strstr ( V_167 , L_50 ) ;
if ( V_169 ) {
if ( V_42 -> V_122 != V_123 ) {
F_35 ( L_51
L_52 , V_167 ,
F_115 ( V_42 ) ) ;
return - V_171 ;
}
V_170 = & V_167 [ 0 ] ;
goto V_172;
}
V_169 = strstr ( V_167 , L_53 ) ;
if ( V_169 ) {
if ( V_42 -> V_122 != V_124 ) {
F_35 ( L_54
L_52 , V_167 ,
F_115 ( V_42 ) ) ;
return - V_171 ;
}
V_170 = & V_167 [ 3 ] ;
goto V_172;
}
V_169 = strstr ( V_167 , L_55 ) ;
if ( V_169 ) {
if ( V_42 -> V_122 != V_125 ) {
F_35 ( L_56
L_52 , V_167 ,
F_115 ( V_42 ) ) ;
return - V_171 ;
}
V_170 = & V_167 [ 0 ] ;
goto V_172;
}
F_35 ( L_57
L_58 , V_167 ) ;
return - V_171 ;
V_172:
if ( V_167 [ strlen ( V_167 ) - 1 ] == '\n' )
V_167 [ strlen ( V_167 ) - 1 ] = '\0' ;
V_48 = F_126 ( V_44 , V_170 ) ;
if ( V_48 < 0 )
return V_48 ;
return V_166 ;
}
struct V_83 * F_135 (
struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_158 )
{
struct V_41 * V_42 = F_4 ( V_174 ,
struct V_41 , V_177 ) ;
struct V_43 * V_44 ;
char * V_178 , * V_179 ;
int V_48 ;
unsigned short int V_180 ;
V_178 = strstr ( V_158 , L_59 ) ;
if ( ! V_178 ) {
F_35 ( L_60
L_61 ) ;
return F_136 ( - V_171 ) ;
}
V_178 += 5 ;
V_180 = ( unsigned short int ) F_137 ( V_178 , & V_179 , 0 ) ;
if ( V_180 >= V_181 ) {
F_35 ( L_62
L_63 , V_180 , V_181 ) ;
return F_136 ( - V_171 ) ;
}
V_44 = & V_42 -> V_49 [ V_180 ] ;
V_44 -> V_42 = V_42 ;
V_44 -> V_127 = V_180 ;
V_48 = F_138 ( & V_182 -> V_183 ,
V_174 , & V_44 -> V_55 , V_44 ,
V_184 ) ;
if ( V_48 < 0 )
return F_136 ( - V_73 ) ;
F_33 ( L_64
L_65 , F_115 ( V_42 ) ,
F_139 ( & V_174 -> V_185 . V_186 ) , V_180 ) ;
return & V_44 -> V_55 ;
}
void F_140 (
struct V_83 * V_84 )
{
struct V_173 * V_174 = V_84 -> V_187 ;
struct V_43 * V_44 = F_4 ( V_84 ,
struct V_43 , V_55 ) ;
struct V_41 * V_42 ;
unsigned short V_180 ;
V_42 = V_44 -> V_42 ;
V_180 = V_44 -> V_127 ;
F_131 ( V_44 ) ;
F_141 ( V_84 ) ;
V_44 -> V_42 = NULL ;
V_44 -> V_127 = 0 ;
F_33 ( L_66
L_65 , F_115 ( V_42 ) ,
F_139 ( & V_174 -> V_185 . V_186 ) , V_180 ) ;
}
struct V_173 * F_142 (
struct V_188 * V_189 ,
struct V_175 * V_176 ,
const char * V_158 )
{
struct V_41 * V_42 ;
struct V_8 * V_78 ;
char * V_169 ;
int V_48 , V_190 = 0 ;
V_42 = F_39 ( sizeof( struct V_41 ) , V_90 ) ;
if ( ! V_42 ) {
F_35 ( L_67 ) ;
return F_136 ( - V_73 ) ;
}
V_169 = strstr ( V_158 , L_50 ) ;
if ( V_169 ) {
V_42 -> V_122 = V_123 ;
goto V_191;
}
V_169 = strstr ( V_158 , L_53 ) ;
if ( V_169 ) {
V_42 -> V_122 = V_124 ;
V_190 = 3 ;
goto V_191;
}
V_169 = strstr ( V_158 , L_55 ) ;
if ( ! V_169 ) {
F_35 ( L_68
L_69 , V_158 ) ;
V_48 = - V_171 ;
goto V_160;
}
V_42 -> V_122 = V_125 ;
V_191:
if ( strlen ( V_158 ) >= V_168 ) {
F_35 ( L_70
L_48 , V_158 , F_115 ( V_42 ) ,
V_168 ) ;
V_48 = - V_171 ;
goto V_160;
}
snprintf ( & V_42 -> V_126 [ 0 ] , V_168 , L_49 , & V_158 [ V_190 ] ) ;
V_48 = F_58 ( V_42 , V_192 ) ;
if ( V_48 )
goto V_160;
V_78 = V_42 -> V_78 ;
V_192 ++ ;
F_33 ( L_71
L_72 ,
F_115 ( V_42 ) , V_158 , V_78 -> V_79 ) ;
return & V_42 -> V_177 ;
V_160:
F_46 ( V_42 ) ;
return F_136 ( V_48 ) ;
}
void F_143 (
struct V_173 * V_174 )
{
struct V_41 * V_42 = F_4 ( V_174 ,
struct V_41 , V_177 ) ;
F_33 ( L_73
L_74 ,
V_42 -> V_126 , V_42 -> V_78 -> V_79 ) ;
F_144 ( & V_42 -> V_16 ) ;
}
static T_5 F_145 (
struct V_188 * V_189 ,
char * V_164 )
{
return sprintf ( V_164 , L_75 , V_193 ) ;
}
static int F_146 ( void )
{
struct V_188 * V_194 ;
int V_48 ;
V_192 = 0 ;
V_194 = F_147 ( V_195 , L_23 ) ;
if ( F_63 ( V_194 ) ) {
F_35 ( L_76 ) ;
return F_64 ( V_194 ) ;
}
V_194 -> V_183 . V_196 = & F_71 ;
V_194 -> V_183 . V_197 = & F_72 ;
V_194 -> V_183 . V_198 = & F_76 ;
V_194 -> V_183 . V_199 = & F_77 ;
V_194 -> V_183 . V_200 = & F_78 ;
V_194 -> V_183 . V_201 = & F_79 ;
V_194 -> V_183 . V_202 =
& F_83 ;
V_194 -> V_183 . V_203 =
& F_87 ;
V_194 -> V_183 . V_204 = & F_91 ;
V_194 -> V_183 . V_205 =
& F_92 ;
V_194 -> V_183 . V_206 =
& F_93 ;
V_194 -> V_183 . V_207 =
& F_94 ;
V_194 -> V_183 . V_208 = & F_95 ;
V_194 -> V_183 . V_209 =
& F_96 ;
V_194 -> V_183 . V_210 = & F_97 ;
V_194 -> V_183 . V_211 = & F_1 ;
V_194 -> V_183 . V_212 = & F_3 ;
V_194 -> V_183 . V_213 = & F_102 ;
V_194 -> V_183 . V_214 = & F_103 ;
V_194 -> V_183 . V_215 = & F_98 ;
V_194 -> V_183 . V_216 = NULL ;
V_194 -> V_183 . V_217 = & F_104 ;
V_194 -> V_183 . V_218 = & F_106 ;
V_194 -> V_183 . V_219 =
& F_99 ;
V_194 -> V_183 . V_220 = & F_100 ;
V_194 -> V_183 . V_221 = & F_101 ;
V_194 -> V_183 . V_222 = & F_107 ;
V_194 -> V_183 . V_223 = & F_28 ;
V_194 -> V_183 . V_224 = & F_110 ;
V_194 -> V_183 . V_225 = & F_113 ;
V_194 -> V_183 . V_226 = & F_114 ;
V_194 -> V_183 . V_227 = & F_142 ;
V_194 -> V_183 . V_228 = & F_143 ;
V_194 -> V_183 . V_229 = & F_135 ;
V_194 -> V_183 . V_230 = & F_140 ;
V_194 -> V_183 . V_231 = & F_116 ;
V_194 -> V_183 . V_232 = & F_120 ;
V_194 -> V_183 . V_233 = NULL ;
V_194 -> V_183 . V_234 = NULL ;
F_148 ( V_194 ) -> V_235 . V_236 = V_237 ;
F_148 ( V_194 ) -> V_238 . V_236 = V_239 ;
F_148 ( V_194 ) -> V_240 . V_236 = NULL ;
F_148 ( V_194 ) -> V_241 . V_236 = NULL ;
F_148 ( V_194 ) -> V_242 . V_236 = NULL ;
V_48 = F_149 ( V_194 ) ;
if ( V_48 < 0 ) {
F_35 ( L_77
L_78 ) ;
F_150 ( V_194 ) ;
return - 1 ;
}
V_182 = V_194 ;
F_33 ( L_79
L_80 ) ;
return 0 ;
}
static void F_151 ( void )
{
if ( ! V_182 )
return;
F_152 ( V_182 ) ;
V_182 = NULL ;
F_33 ( L_81
L_80 ) ;
}
static int T_7 F_153 ( void )
{
int V_48 = - V_73 ;
V_82 = F_154 ( L_82 , 0 , 0 ) ;
if ( ! V_82 )
goto V_160;
V_7 = F_155 ( L_83 ,
sizeof( struct V_4 ) ,
F_156 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_33 ( L_84
L_85 ) ;
goto V_243;
}
V_48 = F_61 () ;
if ( V_48 )
goto V_244;
V_48 = F_146 () ;
if ( V_48 )
goto V_245;
return 0 ;
V_245:
F_69 () ;
V_244:
F_157 ( V_7 ) ;
V_243:
F_158 ( V_82 ) ;
V_160:
return V_48 ;
}
static void T_8 F_159 ( void )
{
F_151 () ;
F_69 () ;
F_157 ( V_7 ) ;
F_158 ( V_82 ) ;
}
