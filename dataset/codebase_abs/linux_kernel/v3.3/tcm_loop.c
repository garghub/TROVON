static struct V_1 * F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 ;
int V_14 ;
if ( ! V_11 ) {
F_2 ( V_15 , V_7 , L_1
L_2 ) ;
F_3 ( V_7 , V_16 ) ;
return NULL ;
}
V_9 = V_11 -> V_9 ;
V_13 = F_4 ( V_17 , V_18 ) ;
if ( ! V_13 ) {
F_5 ( L_3 ) ;
F_3 ( V_7 , V_16 ) ;
return NULL ;
}
V_1 = & V_13 -> V_19 ;
V_13 -> V_7 = V_7 ;
if ( V_7 -> V_20 -> V_21 ) {
switch ( V_7 -> V_22 ) {
case V_23 :
V_14 = V_24 ;
break;
case V_25 :
V_14 = V_26 ;
break;
default:
V_14 = V_27 ;
break;
}
} else
V_14 = V_27 ;
F_6 ( V_1 , V_5 -> V_28 , V_9 ,
F_7 ( V_7 ) , V_7 -> V_29 , V_14 ,
& V_13 -> V_30 [ 0 ] ) ;
if ( F_8 ( V_7 ) )
V_1 -> V_31 |= V_32 ;
if ( F_9 ( V_1 , V_13 -> V_7 -> V_20 -> V_33 ) < 0 ) {
F_10 ( V_17 , V_13 ) ;
F_3 ( V_7 , V_34 ) ;
return NULL ;
}
return V_1 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_12 ( V_1 ,
struct V_12 , V_19 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
struct V_35 * V_36 = NULL ;
T_1 V_37 = 0 ;
int V_38 ;
V_38 = F_13 ( V_1 , V_7 -> V_39 ) ;
if ( V_38 != 0 )
return V_38 ;
if ( V_1 -> V_31 & V_32 ) {
struct V_40 * V_41 = F_14 ( V_7 ) ;
V_36 = V_41 -> V_42 . V_43 ;
V_37 = V_41 -> V_42 . V_44 ;
}
if ( V_1 -> V_31 & V_45 &&
V_1 -> V_46 == V_47 ) {
struct V_35 * V_48 = F_15 ( V_7 ) ;
unsigned char * V_49 = F_16 ( F_17 ( V_48 ) ) + V_48 -> V_50 ;
if ( V_49 != NULL ) {
memset ( V_49 , 0 , V_48 -> V_51 ) ;
F_18 ( F_17 ( V_48 ) ) ;
}
}
return F_19 ( V_1 , F_15 ( V_7 ) ,
F_20 ( V_7 ) , V_36 , V_37 ) ;
}
static int F_21 ( struct V_1 * V_1 )
{
if ( V_1 -> V_52 )
return 0 ;
F_22 ( V_1 , 0 ) ;
return 1 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_12 ( V_1 ,
struct V_12 , V_19 ) ;
F_10 ( V_17 , V_13 ) ;
}
static int F_24 ( struct V_53 * V_54 , char * V_55 ,
char * * V_56 , T_2 V_50 ,
int V_51 , int V_57 )
{
return sprintf ( V_55 , L_4 ) ;
}
static int F_25 ( struct V_20 * V_58 ,
struct V_59 * V_60 )
{
return 1 ;
}
static int F_26 (
struct V_61 * V_62 ,
int V_63 ,
int V_64 )
{
switch ( V_64 ) {
case V_65 :
F_27 ( V_62 , F_28 ( V_62 ) , V_63 ) ;
break;
case V_66 :
F_29 ( V_62 , V_63 ) ;
break;
case V_67 :
F_27 ( V_62 , F_28 ( V_62 ) , V_63 ) ;
break;
default:
return - V_68 ;
}
return V_62 -> V_69 ;
}
static int F_30 (
struct V_53 * V_70 ,
struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
struct V_71 * V_72 ;
F_31 ( L_5
L_6 , V_7 -> V_20 -> V_54 -> V_73 ,
V_7 -> V_20 -> V_74 , V_7 -> V_20 -> V_75 , V_7 -> V_20 -> V_33 ,
V_7 -> V_39 [ 0 ] , F_7 ( V_7 ) ) ;
V_3 = * (struct V_2 * * ) F_32 ( V_7 -> V_20 -> V_54 ) ;
V_72 = & V_3 -> V_76 [ V_7 -> V_20 -> V_74 ] ;
if ( ! V_72 -> V_3 ) {
F_3 ( V_7 , V_34 ) ;
V_7 -> V_77 ( V_7 ) ;
return 0 ;
}
V_5 = & V_72 -> V_78 ;
V_1 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( ! V_1 ) {
V_7 -> V_77 ( V_7 ) ;
return 0 ;
}
F_33 ( V_1 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = NULL ;
struct V_4 * V_5 ;
struct V_8 * V_9 ;
struct V_12 * V_13 = NULL ;
struct V_2 * V_3 ;
struct V_10 * V_11 ;
struct V_79 * V_80 = NULL ;
struct V_71 * V_72 ;
int V_38 = V_81 ;
V_3 = * (struct V_2 * * ) F_32 ( V_7 -> V_20 -> V_54 ) ;
V_11 = V_3 -> V_11 ;
if ( ! V_11 ) {
F_5 ( L_7
L_8 ) ;
return V_81 ;
}
V_9 = V_11 -> V_9 ;
V_72 = & V_3 -> V_76 [ V_7 -> V_20 -> V_74 ] ;
V_5 = & V_72 -> V_78 ;
V_13 = F_4 ( V_17 , V_82 ) ;
if ( ! V_13 ) {
F_5 ( L_9 ) ;
return V_81 ;
}
V_80 = F_35 ( sizeof( struct V_79 ) , V_82 ) ;
if ( ! V_80 ) {
F_5 ( L_10 ) ;
goto V_83;
}
F_36 ( & V_80 -> V_84 ) ;
V_1 = & V_13 -> V_19 ;
F_6 ( V_1 , V_5 -> V_28 , V_9 , 0 ,
V_85 , V_27 ,
& V_13 -> V_30 [ 0 ] ) ;
V_1 -> V_52 = F_37 ( V_1 , V_80 ,
V_86 , V_82 ) ;
if ( F_38 ( V_1 -> V_52 ) )
goto V_83;
if ( F_39 ( V_1 , V_7 -> V_20 -> V_33 ) < 0 )
goto V_83;
F_40 ( V_1 ) ;
F_41 ( V_80 -> V_84 , F_42 ( & V_80 -> V_87 ) ) ;
V_38 = ( V_1 -> V_52 -> V_88 == V_89 ) ?
V_90 : V_81 ;
V_83:
if ( V_1 )
F_22 ( V_1 , 1 ) ;
else
F_10 ( V_17 , V_13 ) ;
F_43 ( V_80 ) ;
return V_38 ;
}
static int F_44 ( struct V_61 * V_91 )
{
F_45 ( V_92 , & V_91 -> V_93 -> V_94 ) ;
return 0 ;
}
static int F_46 ( struct V_61 * V_91 )
{
return 0 ;
}
static int F_47 ( struct V_20 * V_58 )
{
struct V_2 * V_3 ;
struct V_53 * V_70 ;
int error ;
V_3 = F_48 ( V_58 ) ;
V_70 = F_49 ( & V_95 ,
sizeof( struct V_2 ) ) ;
if ( ! V_70 ) {
F_5 ( L_11 ) ;
return - V_96 ;
}
V_3 -> V_70 = V_70 ;
* ( (struct V_2 * * ) V_70 -> V_97 ) = V_3 ;
V_70 -> V_98 = 2 ;
V_70 -> V_99 = 0 ;
V_70 -> V_100 = 0 ;
V_70 -> V_101 = V_102 ;
error = F_50 ( V_70 , & V_3 -> V_58 ) ;
if ( error ) {
F_5 ( L_12 , V_103 ) ;
F_51 ( V_70 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_52 ( struct V_20 * V_58 )
{
struct V_2 * V_3 ;
struct V_53 * V_70 ;
V_3 = F_48 ( V_58 ) ;
V_70 = V_3 -> V_70 ;
F_53 ( V_70 ) ;
F_51 ( V_70 ) ;
return 0 ;
}
static void F_54 ( struct V_20 * V_58 )
{
struct V_2 * V_3 = F_48 ( V_58 ) ;
F_43 ( V_3 ) ;
}
static int F_55 ( struct V_2 * V_3 , int V_104 )
{
int V_38 ;
V_3 -> V_58 . V_105 = & V_106 ;
V_3 -> V_58 . V_107 = V_108 ;
V_3 -> V_58 . V_83 = & F_54 ;
F_56 ( & V_3 -> V_58 , L_13 , V_104 ) ;
V_38 = F_57 ( & V_3 -> V_58 ) ;
if ( V_38 ) {
F_5 ( L_14
L_15 , V_38 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_58 ( void )
{
int V_38 ;
V_108 = F_59 ( L_16 ) ;
if ( F_38 ( V_108 ) ) {
F_5 ( L_17 ) ;
return F_60 ( V_108 ) ;
}
V_38 = F_61 ( & V_106 ) ;
if ( V_38 ) {
F_5 ( L_18 ) ;
goto V_109;
}
V_38 = F_62 ( & V_110 ) ;
if ( V_38 ) {
F_5 ( L_19
L_20 ) ;
goto V_111;
}
F_31 ( L_21 ) ;
return V_38 ;
V_111:
F_63 ( & V_106 ) ;
V_109:
F_64 ( V_108 ) ;
return V_38 ;
}
static void F_65 ( void )
{
F_66 ( & V_110 ) ;
F_63 ( & V_106 ) ;
F_64 ( V_108 ) ;
F_31 ( L_22 ) ;
}
static char * F_67 ( void )
{
return L_23 ;
}
static T_3 F_68 ( struct V_4 * V_5 )
{
struct V_71 * V_72 = V_5 -> V_112 ;
struct V_2 * V_3 = V_72 -> V_3 ;
switch ( V_3 -> V_113 ) {
case V_114 :
return F_69 ( V_5 ) ;
case V_115 :
return F_70 ( V_5 ) ;
case V_116 :
return F_71 ( V_5 ) ;
default:
F_5 ( L_24
L_25 , V_3 -> V_113 ) ;
break;
}
return F_69 ( V_5 ) ;
}
static char * F_72 ( struct V_4 * V_5 )
{
struct V_71 * V_72 = V_5 -> V_112 ;
return & V_72 -> V_3 -> V_117 [ 0 ] ;
}
static T_4 F_73 ( struct V_4 * V_5 )
{
struct V_71 * V_72 = V_5 -> V_112 ;
return V_72 -> V_118 ;
}
static T_1 F_74 ( struct V_4 * V_5 )
{
return 1 ;
}
static T_1 F_75 (
struct V_4 * V_5 ,
struct V_119 * V_120 ,
struct V_121 * V_122 ,
int * V_123 ,
unsigned char * V_49 )
{
struct V_71 * V_72 = V_5 -> V_112 ;
struct V_2 * V_3 = V_72 -> V_3 ;
switch ( V_3 -> V_113 ) {
case V_114 :
return F_76 ( V_5 , V_120 , V_122 ,
V_123 , V_49 ) ;
case V_115 :
return F_77 ( V_5 , V_120 , V_122 ,
V_123 , V_49 ) ;
case V_116 :
return F_78 ( V_5 , V_120 , V_122 ,
V_123 , V_49 ) ;
default:
F_5 ( L_24
L_25 , V_3 -> V_113 ) ;
break;
}
return F_76 ( V_5 , V_120 , V_122 ,
V_123 , V_49 ) ;
}
static T_1 F_79 (
struct V_4 * V_5 ,
struct V_119 * V_120 ,
struct V_121 * V_122 ,
int * V_123 )
{
struct V_71 * V_72 = V_5 -> V_112 ;
struct V_2 * V_3 = V_72 -> V_3 ;
switch ( V_3 -> V_113 ) {
case V_114 :
return F_80 ( V_5 , V_120 , V_122 ,
V_123 ) ;
case V_115 :
return F_81 ( V_5 , V_120 , V_122 ,
V_123 ) ;
case V_116 :
return F_82 ( V_5 , V_120 , V_122 ,
V_123 ) ;
default:
F_5 ( L_24
L_25 , V_3 -> V_113 ) ;
break;
}
return F_80 ( V_5 , V_120 , V_122 ,
V_123 ) ;
}
static char * F_83 (
struct V_4 * V_5 ,
const char * V_49 ,
T_1 * V_124 ,
char * * V_125 )
{
struct V_71 * V_72 = V_5 -> V_112 ;
struct V_2 * V_3 = V_72 -> V_3 ;
switch ( V_3 -> V_113 ) {
case V_114 :
return F_84 ( V_5 , V_49 , V_124 ,
V_125 ) ;
case V_115 :
return F_85 ( V_5 , V_49 , V_124 ,
V_125 ) ;
case V_116 :
return F_86 ( V_5 , V_49 , V_124 ,
V_125 ) ;
default:
F_5 ( L_24
L_25 , V_3 -> V_113 ) ;
break;
}
return F_84 ( V_5 , V_49 , V_124 ,
V_125 ) ;
}
static int F_87 ( struct V_4 * V_5 )
{
return 1 ;
}
static int F_88 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_89 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_90 ( struct V_4 * V_5 )
{
return 0 ;
}
static struct V_119 * F_91 (
struct V_4 * V_5 )
{
struct V_126 * V_127 ;
V_127 = F_35 ( sizeof( struct V_126 ) , V_82 ) ;
if ( ! V_127 ) {
F_5 ( L_26 ) ;
return NULL ;
}
return & V_127 -> V_119 ;
}
static void F_92 (
struct V_4 * V_5 ,
struct V_119 * V_120 )
{
struct V_126 * V_127 = F_12 ( V_120 ,
struct V_126 , V_119 ) ;
F_43 ( V_127 ) ;
}
static T_1 F_93 ( struct V_4 * V_5 )
{
return 1 ;
}
static int F_94 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_95 ( struct V_8 * V_9 )
{
return 1 ;
}
static T_1 F_96 ( struct V_8 * V_9 )
{
return 1 ;
}
static void F_97 ( struct V_119 * V_128 )
{
return;
}
static T_1 F_98 ( struct V_1 * V_1 )
{
return 1 ;
}
static int F_99 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_12 ( V_1 ,
struct V_12 , V_19 ) ;
return V_13 -> V_129 ;
}
static int F_100 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_101 ( struct V_8 * V_9 )
{
return;
}
static void F_102 (
struct V_8 * V_9 ,
int V_130 ,
int V_131 )
{
return;
}
static void F_103 ( struct V_8 * V_9 )
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
struct V_12 * V_13 = F_12 ( V_1 ,
struct V_12 , V_19 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
F_31 ( L_27
L_28 , V_7 , V_7 -> V_39 [ 0 ] ) ;
V_7 -> V_132 = V_133 ;
F_3 ( V_7 , V_134 ) ;
V_7 -> V_77 ( V_7 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_12 ( V_1 ,
struct V_12 , V_19 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
F_31 ( L_29
L_28 , V_7 , V_7 -> V_39 [ 0 ] ) ;
if ( V_1 -> V_135 &&
( ( V_1 -> V_31 & V_136 ) ||
( V_1 -> V_31 & V_137 ) ) ) {
memcpy ( V_7 -> V_135 , V_1 -> V_135 ,
V_138 ) ;
V_7 -> V_132 = V_139 ;
F_109 ( V_7 , V_140 ) ;
} else
V_7 -> V_132 = V_1 -> V_141 ;
F_3 ( V_7 , V_134 ) ;
V_7 -> V_77 ( V_7 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_1 )
{
struct V_52 * V_142 = V_1 -> V_52 ;
struct V_79 * V_80 = V_142 -> V_143 ;
F_111 ( & V_80 -> V_87 , 1 ) ;
F_112 ( & V_80 -> V_84 ) ;
return 0 ;
}
static T_4 F_113 ( struct V_1 * V_1 , T_1 V_144 )
{
return 0 ;
}
static T_4 F_114 ( void )
{
return 0 ;
}
static char * F_115 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_113 ) {
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
static int F_116 (
struct V_4 * V_5 ,
struct V_145 * V_33 )
{
struct V_71 * V_72 = F_12 ( V_5 ,
struct V_71 , V_78 ) ;
struct V_2 * V_3 = V_72 -> V_3 ;
F_117 ( & V_72 -> V_146 ) ;
F_118 () ;
F_119 ( V_3 -> V_70 , 0 , V_72 -> V_118 , V_33 -> V_147 ) ;
F_31 ( L_34 ) ;
return 0 ;
}
static void F_120 (
struct V_4 * V_5 ,
struct V_145 * V_145 )
{
struct V_61 * V_91 ;
struct V_2 * V_3 ;
struct V_71 * V_72 ;
V_72 = F_12 ( V_5 , struct V_71 , V_78 ) ;
V_3 = V_72 -> V_3 ;
V_91 = F_121 ( V_3 -> V_70 , 0 , V_72 -> V_118 ,
V_145 -> V_147 ) ;
if ( ! V_91 ) {
F_5 ( L_35
L_36 , 0 , V_72 -> V_118 , V_145 -> V_147 ) ;
return;
}
F_122 ( V_91 ) ;
F_123 ( V_91 ) ;
F_124 ( & V_72 -> V_146 ) ;
F_125 () ;
F_31 ( L_37 ) ;
}
static int F_126 (
struct V_71 * V_72 ,
const char * V_148 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = V_72 -> V_3 ;
struct V_10 * V_11 ;
int V_38 = - V_149 ;
if ( V_72 -> V_3 -> V_11 ) {
F_31 ( L_38 ) ;
return - V_150 ;
}
V_5 = & V_72 -> V_78 ;
V_11 = F_35 ( sizeof( struct V_10 ) , V_82 ) ;
if ( ! V_11 ) {
F_5 ( L_39 ) ;
return - V_149 ;
}
V_11 -> V_9 = F_127 () ;
if ( F_38 ( V_11 -> V_9 ) ) {
V_38 = F_60 ( V_11 -> V_9 ) ;
goto V_151;
}
V_11 -> V_9 -> V_119 = F_128 (
V_5 , ( unsigned char * ) V_148 ) ;
if ( ! V_11 -> V_9 -> V_119 ) {
F_129 ( V_11 -> V_9 ) ;
goto V_151;
}
F_130 ( V_5 , V_11 -> V_9 -> V_119 ,
V_11 -> V_9 , V_11 ) ;
V_72 -> V_3 -> V_11 = V_11 ;
F_31 ( L_40
L_41 , F_115 ( V_3 ) ,
V_148 ) ;
return 0 ;
V_151:
F_43 ( V_11 ) ;
return V_38 ;
}
static int F_131 (
struct V_71 * V_152 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_2 * V_3 = V_152 -> V_3 ;
V_11 = V_152 -> V_3 -> V_11 ;
if ( ! V_11 )
return - V_96 ;
V_9 = V_11 -> V_9 ;
if ( ! V_9 )
return - V_96 ;
if ( F_42 ( & V_152 -> V_146 ) ) {
F_5 ( L_42
L_43 ,
F_42 ( & V_152 -> V_146 ) ) ;
return - V_153 ;
}
F_31 ( L_44
L_41 , F_115 ( V_3 ) ,
V_11 -> V_9 -> V_119 -> V_154 ) ;
F_132 ( V_11 -> V_9 ) ;
V_152 -> V_3 -> V_11 = NULL ;
F_43 ( V_11 ) ;
return 0 ;
}
static T_5 F_133 (
struct V_4 * V_5 ,
char * V_155 )
{
struct V_71 * V_72 = F_12 ( V_5 ,
struct V_71 , V_78 ) ;
struct V_10 * V_11 ;
T_5 V_38 ;
V_11 = V_72 -> V_3 -> V_11 ;
if ( ! V_11 )
return - V_96 ;
V_38 = snprintf ( V_155 , V_156 , L_45 ,
V_11 -> V_9 -> V_119 -> V_154 ) ;
return V_38 ;
}
static T_5 F_134 (
struct V_4 * V_5 ,
const char * V_155 ,
T_6 V_157 )
{
struct V_71 * V_72 = F_12 ( V_5 ,
struct V_71 , V_78 ) ;
struct V_2 * V_3 = V_72 -> V_3 ;
unsigned char V_158 [ V_159 ] , * V_160 , * V_161 ;
int V_38 ;
if ( ! strncmp ( V_155 , L_46 , 4 ) ) {
V_38 = F_131 ( V_72 ) ;
return ( ! V_38 ) ? V_157 : V_38 ;
}
if ( strlen ( V_155 ) >= V_159 ) {
F_5 ( L_47
L_48 , V_155 , V_159 ) ;
return - V_162 ;
}
snprintf ( & V_158 [ 0 ] , V_159 , L_49 , V_155 ) ;
V_160 = strstr ( V_158 , L_50 ) ;
if ( V_160 ) {
if ( V_3 -> V_113 != V_114 ) {
F_5 ( L_51
L_52 , V_158 ,
F_115 ( V_3 ) ) ;
return - V_162 ;
}
V_161 = & V_158 [ 0 ] ;
goto V_163;
}
V_160 = strstr ( V_158 , L_53 ) ;
if ( V_160 ) {
if ( V_3 -> V_113 != V_115 ) {
F_5 ( L_54
L_52 , V_158 ,
F_115 ( V_3 ) ) ;
return - V_162 ;
}
V_161 = & V_158 [ 3 ] ;
goto V_163;
}
V_160 = strstr ( V_158 , L_55 ) ;
if ( V_160 ) {
if ( V_3 -> V_113 != V_116 ) {
F_5 ( L_56
L_52 , V_158 ,
F_115 ( V_3 ) ) ;
return - V_162 ;
}
V_161 = & V_158 [ 0 ] ;
goto V_163;
}
F_5 ( L_57
L_58 , V_158 ) ;
return - V_162 ;
V_163:
if ( V_158 [ strlen ( V_158 ) - 1 ] == '\n' )
V_158 [ strlen ( V_158 ) - 1 ] = '\0' ;
V_38 = F_126 ( V_72 , V_161 ) ;
if ( V_38 < 0 )
return V_38 ;
return V_157 ;
}
struct V_4 * F_135 (
struct V_164 * V_165 ,
struct V_166 * V_167 ,
const char * V_148 )
{
struct V_2 * V_3 = F_12 ( V_165 ,
struct V_2 , V_168 ) ;
struct V_71 * V_72 ;
char * V_169 , * V_170 ;
int V_38 ;
unsigned short int V_171 ;
V_169 = strstr ( V_148 , L_59 ) ;
if ( ! V_169 ) {
F_5 ( L_60
L_61 ) ;
return F_136 ( - V_162 ) ;
}
V_169 += 5 ;
V_171 = ( unsigned short int ) F_137 ( V_169 , & V_170 , 0 ) ;
if ( V_171 >= V_172 ) {
F_5 ( L_62
L_63 , V_171 , V_172 ) ;
return F_136 ( - V_162 ) ;
}
V_72 = & V_3 -> V_76 [ V_171 ] ;
V_72 -> V_3 = V_3 ;
V_72 -> V_118 = V_171 ;
V_38 = F_138 ( & V_173 -> V_174 ,
V_165 , & V_72 -> V_78 , V_72 ,
V_175 ) ;
if ( V_38 < 0 )
return F_136 ( - V_149 ) ;
F_31 ( L_64
L_65 , F_115 ( V_3 ) ,
F_139 ( & V_165 -> V_176 . V_177 ) , V_171 ) ;
return & V_72 -> V_78 ;
}
void F_140 (
struct V_4 * V_5 )
{
struct V_164 * V_165 = V_5 -> V_178 ;
struct V_71 * V_72 = F_12 ( V_5 ,
struct V_71 , V_78 ) ;
struct V_2 * V_3 ;
unsigned short V_171 ;
V_3 = V_72 -> V_3 ;
V_171 = V_72 -> V_118 ;
F_131 ( V_72 ) ;
F_141 ( V_5 ) ;
V_72 -> V_3 = NULL ;
V_72 -> V_118 = 0 ;
F_31 ( L_66
L_65 , F_115 ( V_3 ) ,
F_139 ( & V_165 -> V_176 . V_177 ) , V_171 ) ;
}
struct V_164 * F_142 (
struct V_179 * V_180 ,
struct V_166 * V_167 ,
const char * V_148 )
{
struct V_2 * V_3 ;
struct V_53 * V_70 ;
char * V_160 ;
int V_38 , V_181 = 0 ;
V_3 = F_35 ( sizeof( struct V_2 ) , V_82 ) ;
if ( ! V_3 ) {
F_5 ( L_67 ) ;
return F_136 ( - V_149 ) ;
}
V_160 = strstr ( V_148 , L_50 ) ;
if ( V_160 ) {
V_3 -> V_113 = V_114 ;
goto V_182;
}
V_160 = strstr ( V_148 , L_53 ) ;
if ( V_160 ) {
V_3 -> V_113 = V_115 ;
V_181 = 3 ;
goto V_182;
}
V_160 = strstr ( V_148 , L_55 ) ;
if ( ! V_160 ) {
F_5 ( L_68
L_69 , V_148 ) ;
V_38 = - V_162 ;
goto V_151;
}
V_3 -> V_113 = V_116 ;
V_182:
if ( strlen ( V_148 ) >= V_159 ) {
F_5 ( L_70
L_48 , V_148 , F_115 ( V_3 ) ,
V_159 ) ;
V_38 = - V_162 ;
goto V_151;
}
snprintf ( & V_3 -> V_117 [ 0 ] , V_159 , L_49 , & V_148 [ V_181 ] ) ;
V_38 = F_55 ( V_3 , V_183 ) ;
if ( V_38 )
goto V_151;
V_70 = V_3 -> V_70 ;
V_183 ++ ;
F_31 ( L_71
L_72 ,
F_115 ( V_3 ) , V_148 , V_70 -> V_73 ) ;
return & V_3 -> V_168 ;
V_151:
F_43 ( V_3 ) ;
return F_136 ( V_38 ) ;
}
void F_143 (
struct V_164 * V_165 )
{
struct V_2 * V_3 = F_12 ( V_165 ,
struct V_2 , V_168 ) ;
F_31 ( L_73
L_74 ,
V_3 -> V_117 , V_3 -> V_70 -> V_73 ) ;
F_144 ( & V_3 -> V_58 ) ;
}
static T_5 F_145 (
struct V_179 * V_180 ,
char * V_155 )
{
return sprintf ( V_155 , L_75 , V_184 ) ;
}
static int F_146 ( void )
{
struct V_179 * V_185 ;
struct V_166 * V_186 ;
int V_38 ;
V_183 = 0 ;
V_185 = F_147 ( V_187 , L_23 ) ;
if ( F_38 ( V_185 ) ) {
F_5 ( L_76 ) ;
return F_60 ( V_185 ) ;
}
V_185 -> V_174 . V_188 = & F_67 ;
V_185 -> V_174 . V_189 = & F_68 ;
V_185 -> V_174 . V_190 = & F_72 ;
V_185 -> V_174 . V_191 = & F_73 ;
V_185 -> V_174 . V_192 = & F_74 ;
V_185 -> V_174 . V_193 = & F_75 ;
V_185 -> V_174 . V_194 =
& F_79 ;
V_185 -> V_174 . V_195 =
& F_83 ;
V_185 -> V_174 . V_196 = & F_87 ;
V_185 -> V_174 . V_197 =
& F_88 ;
V_185 -> V_174 . V_198 =
& F_89 ;
V_185 -> V_174 . V_199 =
& F_90 ;
V_185 -> V_174 . V_200 = & F_91 ;
V_185 -> V_174 . V_201 =
& F_92 ;
V_185 -> V_174 . V_202 = & F_93 ;
V_185 -> V_174 . V_203 = & F_11 ;
V_185 -> V_174 . V_204 = & F_21 ;
V_185 -> V_174 . V_205 = & F_23 ;
V_185 -> V_174 . V_206 = & F_100 ;
V_185 -> V_174 . V_207 = & F_101 ;
V_185 -> V_174 . V_208 = & F_102 ;
V_185 -> V_174 . V_209 = & F_103 ;
V_185 -> V_174 . V_210 = & F_95 ;
V_185 -> V_174 . V_211 = & F_96 ;
V_185 -> V_174 . V_212 = NULL ;
V_185 -> V_174 . V_213 = & F_104 ;
V_185 -> V_174 . V_214 = & F_106 ;
V_185 -> V_174 . V_215 =
& F_97 ;
V_185 -> V_174 . V_216 = & F_98 ;
V_185 -> V_174 . V_217 = & F_99 ;
V_185 -> V_174 . V_218 = & F_107 ;
V_185 -> V_174 . V_219 = & F_108 ;
V_185 -> V_174 . V_220 = & F_110 ;
V_185 -> V_174 . V_221 = & F_113 ;
V_185 -> V_174 . V_222 = & F_114 ;
V_185 -> V_174 . V_223 = & F_94 ;
V_186 = & V_185 -> V_224 ;
V_185 -> V_174 . V_225 = & F_142 ;
V_185 -> V_174 . V_226 = & F_143 ;
V_185 -> V_174 . V_227 = & F_135 ;
V_185 -> V_174 . V_228 = & F_140 ;
V_185 -> V_174 . V_229 = & F_116 ;
V_185 -> V_174 . V_230 = & F_120 ;
V_185 -> V_174 . V_231 = NULL ;
V_185 -> V_174 . V_232 = NULL ;
F_148 ( V_185 ) -> V_233 . V_234 = V_235 ;
F_148 ( V_185 ) -> V_236 . V_234 = V_237 ;
F_148 ( V_185 ) -> V_238 . V_234 = NULL ;
F_148 ( V_185 ) -> V_239 . V_234 = NULL ;
F_148 ( V_185 ) -> V_240 . V_234 = NULL ;
V_38 = F_149 ( V_185 ) ;
if ( V_38 < 0 ) {
F_5 ( L_77
L_78 ) ;
F_150 ( V_185 ) ;
return - 1 ;
}
V_173 = V_185 ;
F_31 ( L_79
L_80 ) ;
return 0 ;
}
static void F_151 ( void )
{
if ( ! V_173 )
return;
F_152 ( V_173 ) ;
V_173 = NULL ;
F_31 ( L_81
L_80 ) ;
}
static int T_7 F_153 ( void )
{
int V_38 ;
V_17 = F_154 ( L_82 ,
sizeof( struct V_12 ) ,
F_155 ( struct V_12 ) ,
0 , NULL ) ;
if ( ! V_17 ) {
F_31 ( L_83
L_84 ) ;
return - V_149 ;
}
V_38 = F_58 () ;
if ( V_38 )
return V_38 ;
V_38 = F_146 () ;
if ( V_38 ) {
F_65 () ;
return V_38 ;
}
return 0 ;
}
static void T_8 F_156 ( void )
{
F_151 () ;
F_65 () ;
F_157 ( V_17 ) ;
}
