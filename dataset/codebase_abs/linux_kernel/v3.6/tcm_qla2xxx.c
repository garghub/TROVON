static int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1 F_3 ( const char * V_3 , T_2 * V_4 , int V_5 )
{
const char * V_6 ;
char V_7 ;
T_3 V_8 ;
T_3 V_9 = 0 ;
T_3 V_10 = 0 ;
T_3 V_11 ;
* V_4 = 0 ;
for ( V_6 = V_3 ; V_6 < & V_3 [ V_12 - 1 ] ; V_6 ++ ) {
V_7 = * V_6 ;
if ( V_7 == '\n' && V_6 [ 1 ] == '\0' )
continue;
if ( V_5 && V_10 ++ == 2 && V_9 ++ < 7 ) {
V_10 = 0 ;
if ( V_7 == ':' )
continue;
V_11 = 1 ;
goto V_13;
}
if ( V_7 == '\0' ) {
V_11 = 2 ;
if ( V_5 && V_9 != 8 )
goto V_13;
return V_6 - V_3 ;
}
V_11 = 3 ;
if ( isdigit ( V_7 ) )
V_8 = V_7 - '0' ;
else if ( isxdigit ( V_7 ) && ( islower ( V_7 ) || ! V_5 ) )
V_8 = tolower ( V_7 ) - 'a' + 10 ;
else
goto V_13;
* V_4 = ( * V_4 << 4 ) | V_8 ;
}
V_11 = 4 ;
V_13:
F_4 ( L_1 ,
V_11 , V_6 - V_3 , V_10 , V_9 ) ;
return - 1 ;
}
static T_1 F_5 ( char * V_14 , T_4 V_15 , T_2 V_4 )
{
T_5 V_16 [ 8 ] ;
F_6 ( V_4 , V_16 ) ;
return snprintf ( V_14 , V_15 ,
L_2 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] , V_16 [ 4 ] , V_16 [ 5 ] , V_16 [ 6 ] , V_16 [ 7 ] ) ;
}
static char * F_7 ( void )
{
return L_3 ;
}
static int F_8 ( const char * V_17 , T_2 * V_18 )
{
unsigned int V_19 , V_20 ;
T_5 V_4 [ 8 ] ;
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
for ( V_19 = 0 , V_20 = 0 ; V_19 < 16 ; V_19 ++ ) {
int V_21 ;
V_21 = F_9 ( * V_17 ++ ) ;
if ( V_21 >= 0 )
V_20 = ( V_20 << 4 ) | V_21 ;
else
return - V_22 ;
if ( V_19 % 2 ) {
V_4 [ V_19 / 2 ] = V_20 & 0xff ;
V_20 = 0 ;
}
}
* V_18 = F_10 ( V_4 ) ;
return 0 ;
}
static int F_11 (
const char * V_3 ,
T_4 V_23 ,
T_2 * V_24 ,
T_2 * V_25 )
{
unsigned int V_26 = V_23 ;
int V_27 ;
* V_24 = 0 ;
* V_25 = 0 ;
if ( V_3 [ V_26 - 1 ] == '\n' )
V_26 -- ;
if ( ( V_26 != ( 16 + 1 + 16 ) ) || ( V_3 [ 16 ] != ':' ) )
return - V_22 ;
V_27 = F_8 ( & V_3 [ 0 ] , V_24 ) ;
if ( V_27 != 0 )
return V_27 ;
V_27 = F_8 ( & V_3 [ 17 ] , V_25 ) ;
if ( V_27 != 0 )
return V_27 ;
return 0 ;
}
static T_1 F_12 ( char * V_14 , T_4 V_15 ,
T_2 V_24 , T_2 V_25 )
{
T_5 V_16 [ 8 ] , V_28 [ 8 ] ;
F_6 ( V_24 , V_16 ) ;
F_6 ( V_25 , V_28 ) ;
return snprintf ( V_14 , V_15 ,
L_4
L_2 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] , V_16 [ 4 ] , V_16 [ 5 ] , V_16 [ 6 ] , V_16 [ 7 ] ,
V_28 [ 0 ] , V_28 [ 1 ] , V_28 [ 2 ] , V_28 [ 3 ] , V_28 [ 4 ] , V_28 [ 5 ] , V_28 [ 6 ] , V_28 [ 7 ] ) ;
}
static char * F_13 ( void )
{
return L_5 ;
}
static T_5 F_14 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
T_5 V_33 ;
switch ( V_32 -> V_34 ) {
case V_35 :
default:
V_33 = F_16 ( V_2 ) ;
break;
}
return V_33 ;
}
static char * F_17 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
return & V_32 -> V_36 [ 0 ] ;
}
static char * F_18 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
return & V_32 -> V_37 [ 0 ] ;
}
static T_6 F_19 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_38 ;
}
static T_3 F_20 ( struct V_1 * V_2 )
{
return 1 ;
}
static T_3 F_21 (
struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
int * V_43 ,
unsigned char * V_14 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
int V_44 = 0 ;
switch ( V_32 -> V_34 ) {
case V_35 :
default:
V_44 = F_22 ( V_2 , V_40 , V_42 ,
V_43 , V_14 ) ;
break;
}
return V_44 ;
}
static T_3 F_23 (
struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
int * V_43 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
int V_44 = 0 ;
switch ( V_32 -> V_34 ) {
case V_35 :
default:
V_44 = F_24 ( V_2 , V_40 , V_42 ,
V_43 ) ;
break;
}
return V_44 ;
}
static char * F_25 (
struct V_1 * V_2 ,
const char * V_14 ,
T_3 * V_45 ,
char * * V_46 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
char * V_47 = NULL ;
switch ( V_32 -> V_34 ) {
case V_35 :
default:
V_47 = F_26 ( V_2 , V_14 , V_45 ,
V_46 ) ;
break;
}
return V_47 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_48 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_49 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_50 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_51 ;
}
static struct V_39 * F_32 (
struct V_1 * V_2 )
{
struct V_52 * V_53 ;
V_53 = F_33 ( sizeof( struct V_52 ) , V_54 ) ;
if ( ! V_53 ) {
F_34 ( L_6 ) ;
return NULL ;
}
return & V_53 -> V_39 ;
}
static void F_35 (
struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_52 * V_53 = F_15 ( V_40 ,
struct V_52 , V_39 ) ;
F_36 ( V_53 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_38 ;
}
static void F_38 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_15 ( V_56 ,
struct V_57 , V_59 ) ;
F_39 ( & V_58 -> V_60 , 0 ) ;
}
static void F_40 ( struct V_57 * V_58 )
{
F_41 ( & V_58 -> V_59 , F_38 ) ;
F_42 ( V_61 , & V_58 -> V_59 ) ;
}
static void F_43 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_15 ( V_56 , struct V_62 , V_56 ) ;
F_39 ( & V_63 -> V_60 , 0 ) ;
}
static void F_44 ( struct V_62 * V_63 )
{
F_41 ( & V_63 -> V_56 , F_43 ) ;
F_42 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_45 ( struct V_60 * V_60 )
{
return F_46 ( V_60 -> V_64 , V_60 ) ;
}
static void F_47 ( struct V_60 * V_60 )
{
struct V_62 * V_63 ;
if ( V_60 -> V_65 & V_66 ) {
struct V_57 * V_58 = F_15 ( V_60 ,
struct V_57 , V_60 ) ;
F_48 ( V_58 ) ;
return;
}
V_63 = F_15 ( V_60 , struct V_62 , V_60 ) ;
F_49 ( V_63 ) ;
}
static int F_50 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_71 * V_72 ;
unsigned long V_73 ;
F_51 ( ! V_69 ) ;
V_72 = V_69 -> V_72 ;
F_52 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
F_53 ( V_64 ) ;
F_54 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
return 1 ;
}
static void F_55 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_71 * V_72 ;
unsigned long V_73 ;
F_51 ( ! V_69 ) ;
V_72 = V_69 -> V_72 ;
F_52 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
F_56 ( V_69 ) ;
F_54 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
}
static T_3 F_57 ( struct V_67 * V_64 )
{
return 0 ;
}
static enum V_76 F_58 ( struct V_60 * V_60 )
{
if ( V_60 -> V_65 & V_77 )
return V_78 ;
switch ( V_60 -> V_79 ) {
case V_80 :
return V_81 ;
case V_81 :
return V_80 ;
case V_82 :
default:
return V_82 ;
}
}
static int F_59 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_15 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_76 = F_58 ( V_60 ) ;
V_63 -> V_85 = V_60 -> V_86 ;
V_63 -> V_87 = V_60 -> V_88 ;
return F_60 ( V_63 ) ;
}
static int F_61 ( struct V_60 * V_60 )
{
unsigned long V_73 ;
F_52 ( & V_60 -> V_89 , V_73 ) ;
if ( V_60 -> V_90 == V_91 ||
V_60 -> V_90 == V_92 ) {
F_54 ( & V_60 -> V_89 , V_73 ) ;
F_62 ( & V_60 -> V_93 ,
3000 ) ;
return 0 ;
}
F_54 ( & V_60 -> V_89 , V_73 ) ;
return 0 ;
}
static void F_63 ( struct V_39 * V_53 )
{
return;
}
static T_3 F_64 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_15 ( V_60 ,
struct V_62 , V_60 ) ;
return V_63 -> V_94 ;
}
static int F_65 ( struct V_60 * V_60 )
{
return 0 ;
}
static int F_66 ( T_7 * V_72 , struct V_62 * V_63 ,
unsigned char * V_95 , T_8 V_84 , int V_96 ,
int V_97 , int V_98 )
{
struct V_60 * V_60 = & V_63 -> V_60 ;
struct V_67 * V_64 ;
struct V_68 * V_69 ;
int V_73 = V_99 ;
if ( V_98 )
V_73 |= V_100 ;
V_69 = V_63 -> V_69 ;
if ( ! V_69 ) {
F_34 ( L_7 ) ;
return - V_22 ;
}
V_64 = V_69 -> V_64 ;
if ( ! V_64 ) {
F_34 ( L_8 ) ;
return - V_22 ;
}
return F_67 ( V_60 , V_64 , V_95 , & V_63 -> V_101 [ 0 ] ,
V_63 -> V_102 , V_84 , V_96 ,
V_97 , V_73 ) ;
}
static void F_68 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_15 ( V_56 , struct V_62 , V_56 ) ;
if ( ! V_63 -> V_103 ) {
if ( V_63 -> V_60 . V_104 & V_105 ) {
F_69 ( & V_63 -> V_60 . V_93 ) ;
return;
}
V_63 -> V_60 . V_106 = V_107 ;
F_70 ( & V_63 -> V_60 ) ;
return;
}
return F_71 ( & V_63 -> V_60 ) ;
}
static void F_72 ( struct V_62 * V_63 )
{
F_41 ( & V_63 -> V_56 , F_68 ) ;
F_42 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_73 ( struct V_57 * V_58 , T_8 V_108 ,
T_9 V_109 , T_8 V_94 )
{
struct V_68 * V_69 = V_58 -> V_69 ;
struct V_60 * V_60 = & V_58 -> V_60 ;
return F_74 ( V_60 , V_69 -> V_64 , NULL , V_108 , V_58 ,
V_109 , V_110 , V_94 , V_99 ) ;
}
static int F_75 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_15 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_76 = F_58 ( V_60 ) ;
V_63 -> V_111 = ( V_60 -> V_104 & V_105 ) ;
V_63 -> V_85 = V_60 -> V_86 ;
V_63 -> V_87 = V_60 -> V_88 ;
V_63 -> V_112 = 0 ;
return F_76 ( V_63 , V_113 | V_114 ,
V_60 -> V_115 ) ;
}
static int F_77 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_15 ( V_60 ,
struct V_62 , V_60 ) ;
int V_116 = V_114 ;
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_87 = NULL ;
V_63 -> V_85 = 0 ;
V_63 -> V_112 = 0 ;
V_63 -> V_76 = F_58 ( V_60 ) ;
V_63 -> V_111 = ( V_60 -> V_104 & V_105 ) ;
if ( V_60 -> V_79 == V_81 ) {
V_60 -> V_65 |= V_117 ;
V_60 -> V_118 = V_60 -> V_84 ;
V_63 -> V_83 = 0 ;
}
return F_76 ( V_63 , V_116 , V_60 -> V_115 ) ;
}
static int F_78 ( struct V_60 * V_60 )
{
struct V_119 * V_120 = V_60 -> V_119 ;
struct V_57 * V_58 = F_15 ( V_60 ,
struct V_57 , V_60 ) ;
F_4 ( L_9 ,
V_58 , V_120 -> V_121 , V_120 -> V_122 ) ;
switch ( V_120 -> V_122 ) {
case V_123 :
V_58 -> V_124 = V_125 ;
break;
case V_126 :
V_58 -> V_124 = V_127 ;
break;
case V_128 :
V_58 -> V_124 = V_129 ;
break;
case V_130 :
default:
V_58 -> V_124 = V_131 ;
break;
}
F_79 ( V_58 ) ;
return 0 ;
}
static T_6 F_80 ( void )
{
return 0 ;
}
static T_6 F_81 ( struct V_60 * V_60 ,
T_3 V_132 )
{
return 0 ;
}
static void F_82 ( struct V_68 * V_69 )
{
struct V_39 * V_40 = V_69 -> V_64 -> V_39 ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_133 * V_133 = V_2 -> V_134 ;
struct V_31 * V_32 = F_15 ( V_133 ,
struct V_31 , V_135 ) ;
struct V_52 * V_53 = F_15 ( V_40 ,
struct V_52 , V_39 ) ;
void * V_136 ;
F_4 ( L_10 , V_53 -> V_137 ) ;
V_136 = F_83 ( & V_32 -> V_138 , V_53 -> V_137 ) ;
F_84 ( V_136 && ( V_136 != V_40 ) ) ;
F_4 ( L_11 ,
V_40 , V_53 -> V_139 , V_53 -> V_137 ) ;
F_85 ( V_32 , V_53 , V_69 ) ;
}
static void F_86 ( struct V_140 * V_140 )
{
struct V_67 * V_64 = F_15 ( V_140 ,
struct V_67 , V_141 ) ;
F_56 ( V_64 -> V_70 ) ;
}
static void F_87 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_142 * V_143 = V_69 -> V_72 -> V_74 ;
unsigned long V_73 ;
F_52 ( & V_143 -> V_75 , V_73 ) ;
F_88 ( & V_64 -> V_141 , F_86 ) ;
F_54 ( & V_143 -> V_75 , V_73 ) ;
}
static void F_89 ( struct V_68 * V_69 )
{
F_87 ( V_69 -> V_64 ) ;
}
static void F_90 ( struct V_68 * V_69 )
{
F_50 ( V_69 -> V_64 ) ;
}
static struct V_39 * F_91 (
struct V_1 * V_2 ,
struct V_144 * V_145 ,
const char * V_3 )
{
struct V_39 * V_40 , * V_146 ;
struct V_52 * V_53 ;
T_2 V_25 ;
T_3 V_147 ;
if ( F_3 ( V_3 , & V_25 , 1 ) < 0 )
return F_92 ( - V_22 ) ;
V_146 = F_32 ( V_2 ) ;
if ( ! V_146 )
return F_92 ( - V_148 ) ;
V_147 = 1 ;
V_40 = F_93 ( V_2 , V_146 ,
V_3 , V_147 ) ;
if ( F_94 ( V_40 ) ) {
F_35 ( V_2 , V_146 ) ;
return V_40 ;
}
V_53 = F_15 ( V_40 , struct V_52 , V_39 ) ;
V_53 -> V_139 = V_25 ;
F_5 ( & V_53 -> V_149 [ 0 ] , V_12 , V_25 ) ;
return V_40 ;
}
static void F_95 ( struct V_39 * V_150 )
{
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_52 * V_53 = F_15 ( V_150 ,
struct V_52 , V_39 ) ;
F_96 ( V_2 , V_150 , 1 ) ;
F_36 ( V_53 ) ;
}
static T_1 F_97 (
struct V_1 * V_2 ,
char * V_151 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return snprintf ( V_151 , V_152 , L_12 ,
F_98 ( & V_30 -> V_153 ) ) ;
}
static T_1 F_99 (
struct V_1 * V_2 ,
const char * V_151 ,
T_4 V_23 )
{
struct V_133 * V_133 = V_2 -> V_134 ;
struct V_31 * V_32 = F_15 ( V_133 ,
struct V_31 , V_135 ) ;
struct V_71 * V_72 = V_32 -> V_154 ;
struct V_142 * V_143 = V_72 -> V_74 ;
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
unsigned long V_155 ;
int V_27 ;
V_27 = F_100 ( V_151 , 0 , & V_155 ) ;
if ( V_27 < 0 ) {
F_34 ( L_13 , V_27 ) ;
return - V_22 ;
}
if ( ( V_155 != 1 ) && ( V_155 != 0 ) ) {
F_34 ( L_14 , V_155 ) ;
return - V_22 ;
}
if ( V_155 ) {
F_101 ( & V_30 -> V_153 , 1 ) ;
F_102 ( V_72 ) ;
} else {
if ( ! V_143 -> V_156 . V_157 ) {
F_34 ( L_15 ) ;
return - V_158 ;
}
F_101 ( & V_30 -> V_153 , 0 ) ;
F_103 ( V_143 -> V_156 . V_157 ) ;
}
return V_23 ;
}
static struct V_1 * F_104 (
struct V_133 * V_4 ,
struct V_144 * V_145 ,
const char * V_3 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_135 ) ;
struct V_29 * V_30 ;
unsigned long V_159 ;
int V_44 ;
if ( strstr ( V_3 , L_16 ) != V_3 )
return F_92 ( - V_22 ) ;
if ( F_100 ( V_3 + 5 , 10 , & V_159 ) || V_159 > V_160 )
return F_92 ( - V_22 ) ;
if ( ! V_32 -> V_161 && ( V_159 != 1 ) ) {
F_34 ( L_17 ) ;
return F_92 ( - V_162 ) ;
}
V_30 = F_33 ( sizeof( struct V_29 ) , V_54 ) ;
if ( ! V_30 ) {
F_34 ( L_18 ) ;
return F_92 ( - V_148 ) ;
}
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_159 ;
F_28 ( V_30 ) -> V_48 = 1 ;
F_28 ( V_30 ) -> V_50 = 1 ;
F_28 ( V_30 ) -> V_49 = 1 ;
V_44 = F_105 ( & V_163 -> V_164 , V_4 ,
& V_30 -> V_2 , V_30 , V_165 ) ;
if ( V_44 < 0 ) {
F_36 ( V_30 ) ;
return NULL ;
}
if ( V_32 -> V_161 == NULL )
V_32 -> V_166 = V_30 ;
return & V_30 -> V_2 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_71 * V_72 = V_32 -> V_154 ;
struct V_142 * V_143 = V_72 -> V_74 ;
if ( V_143 -> V_156 . V_157 && ! V_143 -> V_156 . V_157 -> V_167 )
F_103 ( V_143 -> V_156 . V_157 ) ;
F_107 ( V_2 ) ;
if ( V_32 -> V_161 == NULL )
V_32 -> V_166 = NULL ;
F_36 ( V_30 ) ;
}
static struct V_1 * F_108 (
struct V_133 * V_4 ,
struct V_144 * V_145 ,
const char * V_3 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_135 ) ;
struct V_29 * V_30 ;
unsigned long V_159 ;
int V_44 ;
if ( strstr ( V_3 , L_16 ) != V_3 )
return F_92 ( - V_22 ) ;
if ( F_100 ( V_3 + 5 , 10 , & V_159 ) || V_159 > V_160 )
return F_92 ( - V_22 ) ;
V_30 = F_33 ( sizeof( struct V_29 ) , V_54 ) ;
if ( ! V_30 ) {
F_34 ( L_18 ) ;
return F_92 ( - V_148 ) ;
}
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_159 ;
V_44 = F_105 ( & V_168 -> V_164 , V_4 ,
& V_30 -> V_2 , V_30 , V_165 ) ;
if ( V_44 < 0 ) {
F_36 ( V_30 ) ;
return NULL ;
}
return & V_30 -> V_2 ;
}
static struct V_68 * F_109 (
T_7 * V_72 ,
const T_9 * V_169 )
{
struct V_142 * V_143 = V_72 -> V_74 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_52 * V_53 ;
T_3 V_170 ;
V_32 = V_143 -> V_156 . V_171 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_110 () ;
return NULL ;
}
V_170 = ( ( ( unsigned long ) V_169 [ 0 ] << 16 ) |
( ( unsigned long ) V_169 [ 1 ] << 8 ) |
( unsigned long ) V_169 [ 2 ] ) ;
F_4 ( L_20 , V_170 ) ;
V_40 = F_111 ( & V_32 -> V_138 , V_170 ) ;
if ( ! V_40 ) {
F_4 ( L_21 , V_170 ) ;
return NULL ;
}
F_4 ( L_22 ,
V_40 , V_40 -> V_172 ) ;
V_53 = F_15 ( V_40 , struct V_52 , V_39 ) ;
if ( ! V_53 -> V_68 ) {
F_34 ( L_23 ) ;
return NULL ;
}
return V_53 -> V_68 ;
}
static void F_112 (
struct V_31 * V_32 ,
struct V_39 * V_173 ,
struct V_52 * V_53 ,
struct V_67 * V_64 ,
struct V_68 * V_68 ,
T_9 * V_169 )
{
T_3 V_170 ;
void * V_174 ;
int V_27 ;
V_170 = ( ( ( unsigned long ) V_169 [ 0 ] << 16 ) |
( ( unsigned long ) V_169 [ 1 ] << 8 ) |
( unsigned long ) V_169 [ 2 ] ) ;
F_4 ( L_24 , V_170 ) ;
V_174 = F_111 ( & V_32 -> V_138 , V_170 ) ;
if ( ! V_174 ) {
if ( V_173 ) {
F_4 ( L_25 ) ;
V_53 -> V_137 = V_170 ;
V_27 = F_113 ( & V_32 -> V_138 , V_170 ,
V_173 , V_110 ) ;
if ( V_27 )
F_114 ( V_175 L_26 ,
( int ) V_170 ) ;
} else {
F_4 ( L_27 ) ;
}
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
return;
}
if ( V_53 -> V_68 ) {
if ( V_173 == NULL ) {
F_4 ( L_28 ) ;
F_83 ( & V_32 -> V_138 , V_170 ) ;
V_53 -> V_68 = NULL ;
return;
}
F_4 ( L_29 ) ;
F_115 ( & V_32 -> V_138 , V_170 , V_173 ) ;
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
return;
}
if ( V_173 == NULL ) {
F_4 ( L_30 ) ;
F_83 ( & V_32 -> V_138 , V_170 ) ;
return;
}
F_4 ( L_31 ) ;
F_115 ( & V_32 -> V_138 , V_170 , V_173 ) ;
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
F_4 ( L_32 ,
V_53 -> V_68 , V_173 , V_173 -> V_172 ) ;
}
static struct V_68 * F_116 (
T_7 * V_72 ,
const T_10 V_176 )
{
struct V_142 * V_143 = V_72 -> V_74 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_52 * V_53 ;
struct V_177 * V_178 ;
V_32 = V_143 -> V_156 . V_171 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_110 () ;
return NULL ;
}
F_4 ( L_33 , V_176 ) ;
V_178 = V_32 -> V_179 + V_176 ;
V_40 = V_178 -> V_40 ;
if ( ! V_40 ) {
F_4 ( L_34 ,
V_176 ) ;
return NULL ;
}
V_53 = F_15 ( V_40 , struct V_52 , V_39 ) ;
if ( ! V_53 -> V_68 ) {
F_34 ( L_23 ) ;
return NULL ;
}
return V_53 -> V_68 ;
}
static void F_117 (
struct V_31 * V_32 ,
struct V_39 * V_173 ,
struct V_52 * V_53 ,
struct V_67 * V_64 ,
struct V_68 * V_68 ,
T_10 V_176 )
{
struct V_39 * V_180 ;
struct V_177 * V_178 ;
F_4 ( L_35 , V_176 ) ;
V_178 = & ( (struct V_177 * )
V_32 -> V_179 ) [ V_176 ] ;
V_180 = V_178 -> V_40 ;
if ( ! V_180 ) {
F_4 ( L_36 ) ;
V_178 -> V_40 = V_173 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
return;
}
if ( V_53 -> V_68 ) {
if ( V_173 == NULL ) {
F_4 ( L_37 ) ;
V_178 -> V_40 = NULL ;
V_53 -> V_68 = NULL ;
return;
}
F_4 ( L_38 ) ;
V_178 -> V_40 = V_173 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
return;
}
if ( V_173 == NULL ) {
F_4 ( L_39 ) ;
V_178 -> V_40 = NULL ;
return;
}
F_4 ( L_40 ) ;
V_178 -> V_40 = V_173 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
F_4 ( L_41 ,
V_53 -> V_68 , V_173 , V_173 -> V_172 ) ;
}
static void F_85 ( struct V_31 * V_32 ,
struct V_52 * V_53 , struct V_68 * V_69 )
{
struct V_67 * V_64 = V_69 -> V_64 ;
unsigned char V_181 [ 3 ] ;
V_181 [ 0 ] = V_69 -> V_169 . V_16 . V_182 ;
V_181 [ 1 ] = V_69 -> V_169 . V_16 . V_183 ;
V_181 [ 2 ] = V_69 -> V_169 . V_16 . V_184 ;
F_112 ( V_32 , NULL , V_53 , V_64 ,
V_69 , V_181 ) ;
F_117 ( V_32 , NULL , V_53 , V_64 ,
V_69 , V_69 -> V_176 ) ;
}
static void F_118 ( struct V_68 * V_69 )
{
struct V_157 * V_156 = V_69 -> V_156 ;
struct V_142 * V_143 = V_156 -> V_143 ;
struct V_67 * V_64 ;
struct V_39 * V_40 ;
struct V_31 * V_32 ;
struct V_52 * V_53 ;
F_51 ( F_119 () ) ;
V_64 = V_69 -> V_64 ;
if ( ! V_64 ) {
F_34 ( L_42 ) ;
F_110 () ;
return;
}
V_40 = V_64 -> V_39 ;
V_53 = F_15 ( V_40 , struct V_52 , V_39 ) ;
V_32 = V_143 -> V_156 . V_171 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_110 () ;
return;
}
F_120 ( V_64 , 0 ) ;
F_121 ( V_69 -> V_64 ) ;
F_122 ( V_69 -> V_64 ) ;
}
static int F_123 (
T_7 * V_72 ,
unsigned char * V_185 ,
void * V_68 ,
T_9 * V_169 ,
T_10 V_176 )
{
struct V_142 * V_143 = V_72 -> V_74 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
struct V_52 * V_53 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_67 * V_64 ;
struct V_68 * V_69 = V_68 ;
unsigned char V_186 [ 36 ] ;
unsigned long V_73 ;
V_32 = V_143 -> V_156 . V_171 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_110 () ;
return - V_22 ;
}
V_30 = V_32 -> V_166 ;
if ( ! V_30 ) {
F_34 ( L_43 ) ;
return - V_22 ;
}
V_2 = & V_30 -> V_2 ;
V_64 = F_124 () ;
if ( F_94 ( V_64 ) ) {
F_34 ( L_44 ) ;
return F_125 ( V_64 ) ;
}
memset ( & V_186 , 0 , 36 ) ;
snprintf ( V_186 , 36 , L_45 ,
V_185 [ 0 ] , V_185 [ 1 ] , V_185 [ 2 ] , V_185 [ 3 ] , V_185 [ 4 ] ,
V_185 [ 5 ] , V_185 [ 6 ] , V_185 [ 7 ] ) ;
V_64 -> V_39 = F_126 ( V_2 ,
V_186 ) ;
if ( ! V_64 -> V_39 ) {
F_127 ( V_64 ) ;
return - V_22 ;
}
V_40 = V_64 -> V_39 ;
V_53 = F_15 ( V_40 , struct V_52 , V_39 ) ;
F_52 ( & V_143 -> V_75 , V_73 ) ;
F_112 ( V_32 , V_40 , V_53 , V_64 ,
V_68 , V_169 ) ;
F_117 ( V_32 , V_40 , V_53 , V_64 ,
V_68 , V_176 ) ;
F_54 ( & V_143 -> V_75 , V_73 ) ;
F_128 ( V_40 -> V_2 , V_40 , V_64 , V_69 ) ;
return 0 ;
}
static int F_129 ( struct V_31 * V_32 )
{
int V_27 ;
V_27 = F_130 ( & V_32 -> V_138 ) ;
if ( V_27 ) {
F_34 ( L_46 ) ;
return V_27 ;
}
V_32 -> V_179 = F_131 ( sizeof( struct V_177 ) *
65536 ) ;
if ( ! V_32 -> V_179 ) {
F_34 ( L_47 ,
sizeof( struct V_177 ) * 65536 ) ;
F_132 ( & V_32 -> V_138 ) ;
return - V_148 ;
}
memset ( V_32 -> V_179 , 0 , sizeof( struct V_177 )
* 65536 ) ;
F_4 ( L_48 ,
sizeof( struct V_177 ) * 65536 ) ;
return 0 ;
}
static int F_133 ( struct V_71 * V_72 )
{
struct V_142 * V_143 = V_72 -> V_74 ;
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) V_143 -> V_156 . V_171 ;
V_32 -> V_154 = V_72 ;
return 0 ;
}
static struct V_133 * F_134 (
struct V_187 * V_188 ,
struct V_144 * V_145 ,
const char * V_3 )
{
struct V_31 * V_32 ;
T_2 V_24 ;
int V_44 = - V_158 ;
if ( F_3 ( V_3 , & V_24 , 1 ) < 0 )
return F_92 ( - V_22 ) ;
V_32 = F_33 ( sizeof( struct V_31 ) , V_54 ) ;
if ( ! V_32 ) {
F_34 ( L_49 ) ;
return F_92 ( - V_148 ) ;
}
V_32 -> V_189 = V_24 ;
F_5 ( & V_32 -> V_36 [ 0 ] , V_12 ,
V_24 ) ;
V_44 = F_129 ( V_32 ) ;
if ( V_44 != 0 )
goto V_190;
V_44 = F_135 ( & V_191 , V_24 ,
F_133 , V_32 ) ;
if ( V_44 != 0 )
goto V_192;
return & V_32 -> V_135 ;
V_192:
F_136 ( V_32 -> V_179 ) ;
F_132 ( & V_32 -> V_138 ) ;
V_190:
F_36 ( V_32 ) ;
return F_92 ( V_44 ) ;
}
static void F_137 ( struct V_133 * V_4 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_135 ) ;
struct V_71 * V_72 = V_32 -> V_154 ;
struct V_142 * V_143 = V_72 -> V_74 ;
struct V_39 * V_136 ;
T_3 V_170 = 0 ;
if ( V_143 -> V_156 . V_157 && ! V_143 -> V_156 . V_157 -> V_193 )
F_138 ( V_143 -> V_156 . V_157 ) ;
F_139 ( V_72 ) ;
F_136 ( V_32 -> V_179 ) ;
F_140 (&lport->lport_fcport_map, key, node)
F_83 ( & V_32 -> V_138 , V_170 ) ;
F_132 ( & V_32 -> V_138 ) ;
F_36 ( V_32 ) ;
}
static struct V_133 * F_141 (
struct V_187 * V_188 ,
struct V_144 * V_145 ,
const char * V_3 )
{
struct V_31 * V_32 ;
T_2 V_194 , V_195 ;
int V_44 ;
if ( F_11 ( V_3 , strlen ( V_3 ) + 1 ,
& V_194 , & V_195 ) < 0 )
return F_92 ( - V_22 ) ;
V_32 = F_33 ( sizeof( struct V_31 ) , V_54 ) ;
if ( ! V_32 ) {
F_34 ( L_50 ) ;
return F_92 ( - V_148 ) ;
}
V_32 -> V_196 = V_194 ;
V_32 -> V_197 = V_195 ;
F_12 ( & V_32 -> V_37 [ 0 ] ,
V_12 , V_194 , V_195 ) ;
V_44 = - V_162 ;
if ( V_44 != 0 )
goto V_190;
return & V_32 -> V_135 ;
V_190:
F_36 ( V_32 ) ;
return F_92 ( V_44 ) ;
}
static void F_142 ( struct V_133 * V_4 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_135 ) ;
struct V_71 * V_72 = V_32 -> V_154 ;
struct V_198 * V_199 = V_72 -> V_200 ;
F_143 ( V_32 -> V_201 ) ;
F_144 ( V_199 ) ;
F_36 ( V_32 ) ;
}
static T_1 F_145 (
struct V_187 * V_188 ,
char * V_151 )
{
return sprintf ( V_151 ,
L_51
V_202 L_52 , V_203 , F_146 () -> V_204 ,
F_146 () -> V_205 ) ;
}
static int F_147 ( void )
{
struct V_187 * V_206 , * V_207 ;
int V_44 ;
F_4 ( L_53
V_202 L_52 , V_203 , F_146 () -> V_204 ,
F_146 () -> V_205 ) ;
V_206 = F_148 ( V_208 , L_3 ) ;
if ( F_94 ( V_206 ) ) {
F_34 ( L_54 ) ;
return F_125 ( V_206 ) ;
}
V_206 -> V_164 = V_209 ;
F_149 ( V_206 ) -> V_210 . V_211 = V_212 ;
F_149 ( V_206 ) -> V_213 . V_211 = V_214 ;
F_149 ( V_206 ) -> V_215 . V_211 =
V_216 ;
F_149 ( V_206 ) -> V_217 . V_211 = NULL ;
F_149 ( V_206 ) -> V_218 . V_211 = NULL ;
F_149 ( V_206 ) -> V_219 . V_211 = NULL ;
F_149 ( V_206 ) -> V_220 . V_211 = NULL ;
F_149 ( V_206 ) -> V_221 . V_211 = NULL ;
F_149 ( V_206 ) -> V_222 . V_211 = NULL ;
V_44 = F_150 ( V_206 ) ;
if ( V_44 < 0 ) {
F_34 ( L_55 ) ;
return V_44 ;
}
V_163 = V_206 ;
F_4 ( L_56 ) ;
V_207 = F_148 ( V_208 , L_5 ) ;
if ( F_94 ( V_207 ) ) {
F_34 ( L_54 ) ;
V_44 = F_125 ( V_207 ) ;
goto V_223;
}
V_207 -> V_164 = V_224 ;
F_149 ( V_207 ) -> V_210 . V_211 = V_212 ;
F_149 ( V_207 ) -> V_213 . V_211 = NULL ;
F_149 ( V_207 ) -> V_215 . V_211 = NULL ;
F_149 ( V_207 ) -> V_217 . V_211 = NULL ;
F_149 ( V_207 ) -> V_218 . V_211 = NULL ;
F_149 ( V_207 ) -> V_219 . V_211 = NULL ;
F_149 ( V_207 ) -> V_220 . V_211 = NULL ;
F_149 ( V_207 ) -> V_221 . V_211 = NULL ;
F_149 ( V_207 ) -> V_222 . V_211 = NULL ;
V_44 = F_150 ( V_207 ) ;
if ( V_44 < 0 ) {
F_34 ( L_55 ) ;
goto V_223;
}
V_168 = V_207 ;
F_4 ( L_57 ) ;
V_61 = F_151 ( L_58 ,
V_225 , 0 ) ;
if ( ! V_61 ) {
V_44 = - V_148 ;
goto V_226;
}
V_227 = F_151 ( L_59 , 0 , 0 ) ;
if ( ! V_227 ) {
V_44 = - V_148 ;
goto V_228;
}
return 0 ;
V_228:
F_152 ( V_61 ) ;
V_226:
F_153 ( V_168 ) ;
V_223:
F_153 ( V_163 ) ;
return V_44 ;
}
static void F_154 ( void )
{
F_152 ( V_227 ) ;
F_152 ( V_61 ) ;
F_153 ( V_163 ) ;
V_163 = NULL ;
F_4 ( L_60 ) ;
F_153 ( V_168 ) ;
V_168 = NULL ;
F_4 ( L_61 ) ;
}
static int T_11 F_155 ( void )
{
int V_44 ;
V_44 = F_147 () ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
}
static void T_12 F_156 ( void )
{
F_154 () ;
}
