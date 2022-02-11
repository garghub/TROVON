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
V_1 -> V_48 = V_5 -> V_49 ;
V_30 = F_19 ( V_1 , V_21 -> V_50 , V_19 -> V_51 ,
& V_5 -> V_52 [ 0 ] , V_5 -> V_19 -> V_12 -> V_53 ,
V_29 , V_54 ,
V_19 -> V_55 , 0 ,
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
V_19 -> V_56 ( V_19 ) ;
return;
}
static int F_23 ( struct V_10 * V_57 , struct V_18 * V_19 )
{
struct V_4 * V_5 ;
F_24 ( L_4
L_5 , V_19 -> V_12 -> V_11 -> V_58 ,
V_19 -> V_12 -> V_32 , V_19 -> V_12 -> V_59 , V_19 -> V_12 -> V_53 ,
V_19 -> V_51 [ 0 ] , F_18 ( V_19 ) ) ;
V_5 = F_25 ( V_7 , V_60 ) ;
if ( ! V_5 ) {
F_26 ( L_6 ) ;
F_11 ( V_19 , V_39 ) ;
V_19 -> V_56 ( V_19 ) ;
return 0 ;
}
V_5 -> V_19 = V_19 ;
V_5 -> V_49 = V_19 -> V_61 -> V_48 ;
F_27 ( & V_5 -> V_17 , F_9 ) ;
F_28 ( V_62 , & V_5 -> V_17 ) ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
T_2 V_53 , int V_63 , enum V_64 V_65 )
{
struct V_1 * V_1 = NULL ;
struct V_66 * V_50 ;
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
V_50 = V_25 -> V_21 -> V_50 ;
F_32 ( V_1 , V_68 -> V_77 , V_50 , 0 ,
V_78 , V_54 ,
& V_5 -> V_52 [ 0 ] ) ;
V_30 = F_33 ( V_1 , V_70 , V_65 , V_73 ) ;
if ( V_30 < 0 )
goto V_74;
if ( V_65 == V_79 )
V_1 -> V_80 -> V_81 = V_63 ;
if ( F_34 ( V_1 , V_53 ) < 0 ) {
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
V_71 = F_29 ( V_25 , V_19 -> V_12 -> V_53 ,
V_19 -> V_61 -> V_48 , V_79 ) ;
return ( V_71 == V_86 ) ? V_87 : V_85 ;
}
static int F_40 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_71 = V_85 ;
V_23 = * (struct V_22 * * ) F_10 ( V_19 -> V_12 -> V_11 ) ;
V_25 = & V_23 -> V_31 [ V_19 -> V_12 -> V_32 ] ;
V_71 = F_29 ( V_25 , V_19 -> V_12 -> V_53 ,
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
struct V_10 * V_57 ;
int error , V_95 ;
V_23 = F_45 ( V_13 ) ;
V_57 = F_46 ( & V_96 ,
sizeof( struct V_22 ) ) ;
if ( ! V_57 ) {
F_26 ( L_11 ) ;
return - V_97 ;
}
V_23 -> V_57 = V_57 ;
* ( (struct V_22 * * ) V_57 -> V_98 ) = V_23 ;
V_57 -> V_99 = 2 ;
V_57 -> V_100 = 0 ;
V_57 -> V_101 = 0 ;
V_57 -> V_102 = V_103 ;
V_95 = V_104 | V_105 |
V_106 | V_107 |
V_108 | V_109 ;
F_47 ( V_57 , V_95 ) ;
F_48 ( V_57 , V_110 ) ;
error = F_49 ( V_57 , & V_23 -> V_13 ) ;
if ( error ) {
F_26 ( L_12 , V_111 ) ;
F_50 ( V_57 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
struct V_22 * V_23 ;
struct V_10 * V_57 ;
V_23 = F_45 ( V_13 ) ;
V_57 = V_23 -> V_57 ;
F_52 ( V_57 ) ;
F_50 ( V_57 ) ;
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
static inline struct V_24 * V_25 ( struct V_67 * V_68 )
{
return F_4 ( V_68 , struct V_24 , V_76 ) ;
}
static char * F_68 ( struct V_67 * V_68 )
{
return & V_25 ( V_68 ) -> V_23 -> V_120 [ 0 ] ;
}
static T_3 F_69 ( struct V_67 * V_68 )
{
return V_25 ( V_68 ) -> V_121 ;
}
static int F_70 ( struct V_67 * V_68 )
{
return 1 ;
}
static int F_71 ( struct V_67 * V_68 )
{
return 0 ;
}
static int F_72 ( struct V_67 * V_68 )
{
return 0 ;
}
static int F_73 ( struct V_67 * V_68 )
{
return 0 ;
}
static int F_74 ( struct V_67 * V_68 )
{
struct V_24 * V_25 = F_4 ( V_68 , struct V_24 ,
V_76 ) ;
return V_25 -> V_122 ;
}
static T_1 F_75 ( struct V_67 * V_68 )
{
return 1 ;
}
static T_1 F_76 ( struct V_66 * V_50 )
{
return 1 ;
}
static void F_77 ( struct V_123 * V_124 )
{
return;
}
static int F_78 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_125 ;
}
static int F_79 ( struct V_66 * V_50 )
{
return 0 ;
}
static void F_80 ( struct V_66 * V_50 )
{
return;
}
static int F_81 ( struct V_1 * V_1 )
{
F_82 ( V_1 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_84 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_24 ( L_24
L_25 , V_19 , V_19 -> V_51 [ 0 ] ) ;
V_19 -> V_126 = V_127 ;
F_11 ( V_19 , V_128 ) ;
if ( ( V_1 -> V_2 & V_129 ) ||
( V_1 -> V_2 & V_130 ) )
F_85 ( V_19 , V_1 -> V_131 ) ;
V_19 -> V_56 ( V_19 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_24 ( L_26
L_25 , V_19 , V_19 -> V_51 [ 0 ] ) ;
if ( V_1 -> V_132 &&
( ( V_1 -> V_2 & V_133 ) ||
( V_1 -> V_2 & V_134 ) ) ) {
memcpy ( V_19 -> V_132 , V_1 -> V_132 ,
V_135 ) ;
V_19 -> V_126 = V_136 ;
F_87 ( V_19 , V_137 ) ;
} else
V_19 -> V_126 = V_1 -> V_138 ;
F_11 ( V_19 , V_128 ) ;
if ( ( V_1 -> V_2 & V_129 ) ||
( V_1 -> V_2 & V_130 ) )
F_85 ( V_19 , V_1 -> V_131 ) ;
V_19 -> V_56 ( V_19 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_1 )
{
struct V_80 * V_139 = V_1 -> V_80 ;
struct V_69 * V_70 = V_139 -> V_140 ;
F_89 ( & V_70 -> V_83 , 1 ) ;
F_90 ( & V_70 -> V_75 ) ;
}
static void F_91 ( struct V_1 * V_1 )
{
return;
}
static char * F_92 ( struct V_22 * V_23 )
{
switch ( V_23 -> V_141 ) {
case V_142 :
return L_27 ;
case V_143 :
return L_28 ;
case V_144 :
return L_29 ;
default:
break;
}
return L_30 ;
}
static int F_93 (
struct V_67 * V_68 ,
struct V_145 * V_53 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 = V_25 -> V_23 ;
F_94 ( & V_25 -> V_146 ) ;
F_95 ( V_23 -> V_57 , 0 , V_25 -> V_121 , V_53 -> V_147 ) ;
F_24 ( L_31 ) ;
return 0 ;
}
static void F_96 (
struct V_67 * V_68 ,
struct V_145 * V_145 )
{
struct V_90 * V_91 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_25 = F_4 ( V_68 , struct V_24 , V_76 ) ;
V_23 = V_25 -> V_23 ;
V_91 = F_97 ( V_23 -> V_57 , 0 , V_25 -> V_121 ,
V_145 -> V_147 ) ;
if ( ! V_91 ) {
F_26 ( L_32
L_33 , 0 , V_25 -> V_121 , V_145 -> V_147 ) ;
return;
}
F_98 ( V_91 ) ;
F_99 ( V_91 ) ;
F_100 ( & V_25 -> V_146 ) ;
F_24 ( L_34 ) ;
}
static T_4 F_101 (
struct V_67 * V_68 ,
char * V_148 )
{
struct V_24 * V_25 = F_4 ( V_68 , struct V_24 ,
V_76 ) ;
return sprintf ( V_148 , L_35 , V_25 -> V_122 ) ;
}
static T_4 F_102 (
struct V_67 * V_68 ,
const char * V_148 ,
T_5 V_149 )
{
struct V_24 * V_25 = F_4 ( V_68 , struct V_24 ,
V_76 ) ;
unsigned long V_150 ;
int V_71 = F_103 ( V_148 , 0 , & V_150 ) ;
if ( V_71 ) {
F_26 ( L_36 , V_71 ) ;
return V_71 ;
}
if ( V_150 != 0 && V_150 != 1 && V_150 != 3 ) {
F_26 ( L_37 , V_150 ) ;
return - V_151 ;
}
V_25 -> V_122 = V_150 ;
return V_149 ;
}
static int F_104 (
struct V_24 * V_25 ,
const char * V_152 )
{
struct V_67 * V_68 ;
struct V_22 * V_23 = V_25 -> V_23 ;
struct V_20 * V_21 ;
int V_71 = - V_153 ;
if ( V_25 -> V_21 ) {
F_24 ( L_38 ) ;
return - V_154 ;
}
V_68 = & V_25 -> V_76 ;
V_21 = F_30 ( sizeof( struct V_20 ) , V_73 ) ;
if ( ! V_21 ) {
F_26 ( L_39 ) ;
return - V_153 ;
}
V_21 -> V_50 = F_105 (
V_155 | V_156 ) ;
if ( F_59 ( V_21 -> V_50 ) ) {
V_71 = F_60 ( V_21 -> V_50 ) ;
goto V_157;
}
V_21 -> V_50 -> V_123 = F_106 (
V_68 , ( unsigned char * ) V_152 ) ;
if ( ! V_21 -> V_50 -> V_123 ) {
F_107 ( V_21 -> V_50 ) ;
goto V_157;
}
F_108 ( V_68 , V_21 -> V_50 -> V_123 ,
V_21 -> V_50 , V_21 ) ;
V_25 -> V_21 = V_21 ;
F_24 ( L_40
L_41 , F_92 ( V_23 ) ,
V_152 ) ;
return 0 ;
V_157:
F_38 ( V_21 ) ;
return V_71 ;
}
static int F_109 (
struct V_24 * V_158 )
{
struct V_66 * V_50 ;
struct V_20 * V_21 ;
V_21 = V_158 -> V_21 ;
if ( ! V_21 )
return - V_97 ;
V_50 = V_21 -> V_50 ;
if ( ! V_50 )
return - V_97 ;
if ( F_37 ( & V_158 -> V_146 ) ) {
F_26 ( L_42
L_43 ,
F_37 ( & V_158 -> V_146 ) ) ;
return - V_159 ;
}
F_24 ( L_44
L_41 , F_92 ( V_158 -> V_23 ) ,
V_21 -> V_50 -> V_123 -> V_160 ) ;
F_110 ( V_21 -> V_50 ) ;
V_158 -> V_21 = NULL ;
F_38 ( V_21 ) ;
return 0 ;
}
static T_4 F_111 (
struct V_67 * V_68 ,
char * V_148 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_20 * V_21 ;
T_4 V_71 ;
V_21 = V_25 -> V_21 ;
if ( ! V_21 )
return - V_97 ;
V_71 = snprintf ( V_148 , V_161 , L_45 ,
V_21 -> V_50 -> V_123 -> V_160 ) ;
return V_71 ;
}
static T_4 F_112 (
struct V_67 * V_68 ,
const char * V_148 ,
T_5 V_149 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned char V_162 [ V_163 ] , * V_164 , * V_165 ;
int V_71 ;
if ( ! strncmp ( V_148 , L_46 , 4 ) ) {
V_71 = F_109 ( V_25 ) ;
return ( ! V_71 ) ? V_149 : V_71 ;
}
if ( strlen ( V_148 ) >= V_163 ) {
F_26 ( L_47
L_48 , V_148 , V_163 ) ;
return - V_151 ;
}
snprintf ( & V_162 [ 0 ] , V_163 , L_49 , V_148 ) ;
V_164 = strstr ( V_162 , L_50 ) ;
if ( V_164 ) {
if ( V_23 -> V_141 != V_142 ) {
F_26 ( L_51
L_52 , V_162 ,
F_92 ( V_23 ) ) ;
return - V_151 ;
}
V_165 = & V_162 [ 0 ] ;
goto V_166;
}
V_164 = strstr ( V_162 , L_53 ) ;
if ( V_164 ) {
if ( V_23 -> V_141 != V_143 ) {
F_26 ( L_54
L_52 , V_162 ,
F_92 ( V_23 ) ) ;
return - V_151 ;
}
V_165 = & V_162 [ 3 ] ;
goto V_166;
}
V_164 = strstr ( V_162 , L_55 ) ;
if ( V_164 ) {
if ( V_23 -> V_141 != V_144 ) {
F_26 ( L_56
L_52 , V_162 ,
F_92 ( V_23 ) ) ;
return - V_151 ;
}
V_165 = & V_162 [ 0 ] ;
goto V_166;
}
F_26 ( L_57
L_58 , V_162 ) ;
return - V_151 ;
V_166:
if ( V_162 [ strlen ( V_162 ) - 1 ] == '\n' )
V_162 [ strlen ( V_162 ) - 1 ] = '\0' ;
V_71 = F_104 ( V_25 , V_165 ) ;
if ( V_71 < 0 )
return V_71 ;
return V_149 ;
}
static T_4 F_113 (
struct V_67 * V_68 ,
char * V_148 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
const char * V_167 = NULL ;
T_4 V_71 = - V_151 ;
switch ( V_25 -> V_35 ) {
case V_89 :
V_167 = L_59 ;
break;
case V_36 :
V_167 = L_60 ;
break;
default:
break;
}
if ( V_167 )
V_71 = snprintf ( V_148 , V_161 , L_45 , V_167 ) ;
return V_71 ;
}
static T_4 F_114 (
struct V_67 * V_68 ,
const char * V_148 ,
T_5 V_149 )
{
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
if ( ! strncmp ( V_148 , L_59 , 6 ) ) {
V_25 -> V_35 = V_89 ;
return V_149 ;
}
if ( ! strncmp ( V_148 , L_60 , 7 ) ) {
V_25 -> V_35 = V_36 ;
return V_149 ;
}
return - V_151 ;
}
static struct V_67 * F_115 (
struct V_168 * V_169 ,
struct V_170 * V_171 ,
const char * V_152 )
{
struct V_22 * V_23 = F_4 ( V_169 ,
struct V_22 , V_172 ) ;
struct V_24 * V_25 ;
int V_71 ;
unsigned long V_173 ;
if ( strstr ( V_152 , L_61 ) != V_152 ) {
F_26 ( L_62
L_63 ) ;
return F_116 ( - V_151 ) ;
}
if ( F_103 ( V_152 + 5 , 10 , & V_173 ) )
return F_116 ( - V_151 ) ;
if ( V_173 >= V_174 ) {
F_26 ( L_64
L_65 , V_173 , V_174 ) ;
return F_116 ( - V_151 ) ;
}
V_25 = & V_23 -> V_31 [ V_173 ] ;
V_25 -> V_23 = V_23 ;
V_25 -> V_121 = V_173 ;
V_71 = F_117 ( V_169 , & V_25 -> V_76 , V_23 -> V_141 ) ;
if ( V_71 < 0 )
return F_116 ( - V_153 ) ;
F_24 ( L_66
L_67 , F_92 ( V_23 ) ,
F_118 ( & V_169 -> V_175 . V_176 ) , V_173 ) ;
return & V_25 -> V_76 ;
}
static void F_119 (
struct V_67 * V_68 )
{
struct V_168 * V_169 = V_68 -> V_177 ;
struct V_24 * V_25 = F_4 ( V_68 ,
struct V_24 , V_76 ) ;
struct V_22 * V_23 ;
unsigned short V_173 ;
V_23 = V_25 -> V_23 ;
V_173 = V_25 -> V_121 ;
F_109 ( V_25 ) ;
F_120 ( V_68 ) ;
V_25 -> V_23 = NULL ;
V_25 -> V_121 = 0 ;
F_24 ( L_68
L_69 , F_92 ( V_23 ) ,
F_118 ( & V_169 -> V_175 . V_176 ) , V_173 ) ;
}
static struct V_168 * F_121 (
struct V_178 * V_179 ,
struct V_170 * V_171 ,
const char * V_152 )
{
struct V_22 * V_23 ;
struct V_10 * V_57 ;
char * V_164 ;
int V_71 , V_180 = 0 ;
V_23 = F_30 ( sizeof( struct V_22 ) , V_73 ) ;
if ( ! V_23 ) {
F_26 ( L_70 ) ;
return F_116 ( - V_153 ) ;
}
V_164 = strstr ( V_152 , L_50 ) ;
if ( V_164 ) {
V_23 -> V_141 = V_142 ;
goto V_181;
}
V_164 = strstr ( V_152 , L_53 ) ;
if ( V_164 ) {
V_23 -> V_141 = V_143 ;
V_180 = 3 ;
goto V_181;
}
V_164 = strstr ( V_152 , L_55 ) ;
if ( ! V_164 ) {
F_26 ( L_71
L_72 , V_152 ) ;
V_71 = - V_151 ;
goto V_157;
}
V_23 -> V_141 = V_144 ;
V_181:
if ( strlen ( V_152 ) >= V_163 ) {
F_26 ( L_73
L_48 , V_152 , F_92 ( V_23 ) ,
V_163 ) ;
V_71 = - V_151 ;
goto V_157;
}
snprintf ( & V_23 -> V_120 [ 0 ] , V_163 , L_49 , & V_152 [ V_180 ] ) ;
V_71 = F_54 ( V_23 , V_182 ) ;
if ( V_71 )
goto V_157;
V_57 = V_23 -> V_57 ;
V_182 ++ ;
F_24 ( L_74
L_75 ,
F_92 ( V_23 ) , V_152 , V_57 -> V_58 ) ;
return & V_23 -> V_172 ;
V_157:
F_38 ( V_23 ) ;
return F_116 ( V_71 ) ;
}
static void F_122 (
struct V_168 * V_169 )
{
struct V_22 * V_23 = F_4 ( V_169 ,
struct V_22 , V_172 ) ;
F_24 ( L_76
L_77 ,
V_23 -> V_120 , V_23 -> V_57 -> V_58 ) ;
F_123 ( & V_23 -> V_13 ) ;
}
static T_4 F_124 (
struct V_178 * V_179 ,
char * V_148 )
{
return sprintf ( V_148 , L_78 , V_183 ) ;
}
static int T_6 F_125 ( void )
{
int V_71 = - V_153 ;
V_62 = F_126 ( L_79 , 0 , 0 ) ;
if ( ! V_62 )
goto V_157;
V_7 = F_127 ( L_80 ,
sizeof( struct V_4 ) ,
F_128 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_24 ( L_81
L_82 ) ;
goto V_184;
}
V_71 = F_57 () ;
if ( V_71 )
goto V_185;
V_71 = F_129 ( & V_186 ) ;
if ( V_71 )
goto V_187;
return 0 ;
V_187:
F_65 () ;
V_185:
F_130 ( V_7 ) ;
V_184:
F_131 ( V_62 ) ;
V_157:
return V_71 ;
}
static void T_7 F_132 ( void )
{
F_133 ( & V_186 ) ;
F_65 () ;
F_130 ( V_7 ) ;
F_131 ( V_62 ) ;
}
