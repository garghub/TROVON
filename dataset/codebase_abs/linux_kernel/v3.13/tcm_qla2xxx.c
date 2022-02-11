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
return V_32 -> V_36 ;
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
return V_30 -> V_48 . V_49 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_48 . V_50 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_48 . V_51 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_48 . V_52 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_48 . V_53 ;
}
static struct V_39 * F_32 (
struct V_1 * V_2 )
{
struct V_54 * V_55 ;
V_55 = F_33 ( sizeof( struct V_54 ) , V_56 ) ;
if ( ! V_55 ) {
F_34 ( L_6 ) ;
return NULL ;
}
return & V_55 -> V_39 ;
}
static void F_35 (
struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_54 * V_55 = F_15 ( V_40 ,
struct V_54 , V_39 ) ;
F_36 ( V_55 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_38 ;
}
static void F_38 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_15 ( V_58 ,
struct V_59 , V_61 ) ;
F_39 ( & V_60 -> V_62 , 0 ) ;
}
static void F_40 ( struct V_59 * V_60 )
{
F_41 ( & V_60 -> V_61 , F_38 ) ;
F_42 ( V_63 , & V_60 -> V_61 ) ;
}
static void F_43 ( struct V_57 * V_58 )
{
struct V_64 * V_65 = F_15 ( V_58 , struct V_64 , V_58 ) ;
F_39 ( & V_65 -> V_62 , 0 ) ;
}
static void F_44 ( struct V_64 * V_65 )
{
F_41 ( & V_65 -> V_58 , F_43 ) ;
F_42 ( V_63 , & V_65 -> V_58 ) ;
}
static int F_45 ( struct V_62 * V_62 )
{
return F_46 ( V_62 -> V_66 , V_62 ) ;
}
static void F_47 ( struct V_62 * V_62 )
{
struct V_64 * V_65 ;
if ( V_62 -> V_67 & V_68 ) {
struct V_59 * V_60 = F_15 ( V_62 ,
struct V_59 , V_62 ) ;
F_48 ( V_60 ) ;
return;
}
V_65 = F_15 ( V_62 , struct V_64 , V_62 ) ;
F_49 ( V_65 ) ;
}
static int F_50 ( struct V_69 * V_66 )
{
struct V_70 * V_71 = V_66 -> V_72 ;
struct V_73 * V_74 ;
unsigned long V_75 ;
F_51 ( ! V_71 ) ;
V_74 = V_71 -> V_74 ;
F_52 ( & V_74 -> V_76 -> V_77 , V_75 ) ;
F_53 ( V_66 ) ;
F_54 ( & V_74 -> V_76 -> V_77 , V_75 ) ;
return 1 ;
}
static void F_55 ( struct V_69 * V_66 )
{
struct V_70 * V_71 = V_66 -> V_72 ;
struct V_73 * V_74 ;
unsigned long V_75 ;
F_51 ( ! V_71 ) ;
V_74 = V_71 -> V_74 ;
F_52 ( & V_74 -> V_76 -> V_77 , V_75 ) ;
F_56 ( V_71 ) ;
F_54 ( & V_74 -> V_76 -> V_77 , V_75 ) ;
}
static T_3 F_57 ( struct V_69 * V_66 )
{
return 0 ;
}
static int F_58 ( struct V_62 * V_62 )
{
struct V_64 * V_65 = F_15 ( V_62 ,
struct V_64 , V_62 ) ;
V_65 -> V_78 = V_62 -> V_79 ;
V_65 -> V_80 = F_59 ( V_62 ) ;
V_65 -> V_81 = V_62 -> V_82 ;
V_65 -> V_83 = V_62 -> V_84 ;
return F_60 ( V_65 ) ;
}
static int F_61 ( struct V_62 * V_62 )
{
unsigned long V_75 ;
F_52 ( & V_62 -> V_85 , V_75 ) ;
if ( V_62 -> V_86 == V_87 ||
V_62 -> V_86 == V_88 ) {
F_54 ( & V_62 -> V_85 , V_75 ) ;
F_62 ( & V_62 -> V_89 ,
3000 ) ;
return 0 ;
}
F_54 ( & V_62 -> V_85 , V_75 ) ;
return 0 ;
}
static void F_63 ( struct V_39 * V_55 )
{
return;
}
static T_3 F_64 ( struct V_62 * V_62 )
{
struct V_64 * V_65 = F_15 ( V_62 ,
struct V_64 , V_62 ) ;
return V_65 -> V_90 ;
}
static int F_65 ( struct V_62 * V_62 )
{
return 0 ;
}
static int F_66 ( T_7 * V_74 , struct V_64 * V_65 ,
unsigned char * V_91 , T_8 V_79 , int V_92 ,
int V_93 , int V_94 )
{
struct V_62 * V_62 = & V_65 -> V_62 ;
struct V_69 * V_66 ;
struct V_70 * V_71 ;
int V_75 = V_95 ;
if ( V_94 )
V_75 |= V_96 ;
V_71 = V_65 -> V_71 ;
if ( ! V_71 ) {
F_34 ( L_7 ) ;
return - V_22 ;
}
V_66 = V_71 -> V_66 ;
if ( ! V_66 ) {
F_34 ( L_8 ) ;
return - V_22 ;
}
return F_67 ( V_62 , V_66 , V_91 , & V_65 -> V_97 [ 0 ] ,
V_65 -> V_98 , V_79 , V_92 ,
V_93 , V_75 ) ;
}
static void F_68 ( struct V_57 * V_58 )
{
struct V_64 * V_65 = F_15 ( V_58 , struct V_64 , V_58 ) ;
if ( ! V_65 -> V_99 ) {
if ( V_65 -> V_62 . V_100 & V_101 ) {
F_69 ( & V_65 -> V_62 . V_89 ) ;
return;
}
F_70 ( & V_65 -> V_62 ,
V_102 ) ;
return;
}
return F_71 ( & V_65 -> V_62 ) ;
}
static void F_72 ( struct V_64 * V_65 )
{
F_41 ( & V_65 -> V_58 , F_68 ) ;
F_42 ( V_63 , & V_65 -> V_58 ) ;
}
static int F_73 ( struct V_59 * V_60 , T_8 V_103 ,
T_9 V_104 , T_8 V_90 )
{
struct V_70 * V_71 = V_60 -> V_71 ;
struct V_62 * V_62 = & V_60 -> V_62 ;
return F_74 ( V_62 , V_71 -> V_66 , NULL , V_103 , V_60 ,
V_104 , V_105 , V_90 , V_95 ) ;
}
static int F_75 ( struct V_62 * V_62 )
{
struct V_64 * V_65 = F_15 ( V_62 ,
struct V_64 , V_62 ) ;
V_65 -> V_78 = V_62 -> V_79 ;
V_65 -> V_80 = F_59 ( V_62 ) ;
V_65 -> V_106 = ( V_62 -> V_100 & V_101 ) ;
V_65 -> V_81 = V_62 -> V_82 ;
V_65 -> V_83 = V_62 -> V_84 ;
V_65 -> V_107 = 0 ;
return F_76 ( V_65 , V_108 | V_109 ,
V_62 -> V_110 ) ;
}
static int F_77 ( struct V_62 * V_62 )
{
struct V_64 * V_65 = F_15 ( V_62 ,
struct V_64 , V_62 ) ;
int V_111 = V_109 ;
V_65 -> V_78 = V_62 -> V_79 ;
V_65 -> V_83 = NULL ;
V_65 -> V_81 = 0 ;
V_65 -> V_107 = 0 ;
V_65 -> V_80 = F_59 ( V_62 ) ;
V_65 -> V_106 = ( V_62 -> V_100 & V_101 ) ;
if ( V_62 -> V_112 == V_113 ) {
if ( V_62 -> V_67 & V_114 ) {
V_62 -> V_67 &= ~ V_114 ;
V_62 -> V_115 = 0 ;
}
V_62 -> V_67 |= V_116 ;
V_62 -> V_115 += V_62 -> V_79 ;
V_65 -> V_78 = 0 ;
}
return F_76 ( V_65 , V_111 , V_62 -> V_110 ) ;
}
static void F_78 ( struct V_62 * V_62 )
{
struct V_117 * V_118 = V_62 -> V_117 ;
struct V_59 * V_60 = F_15 ( V_62 ,
struct V_59 , V_62 ) ;
F_4 ( L_9 ,
V_60 , V_118 -> V_119 , V_118 -> V_120 ) ;
switch ( V_118 -> V_120 ) {
case V_121 :
V_60 -> V_122 = V_123 ;
break;
case V_124 :
V_60 -> V_122 = V_125 ;
break;
case V_126 :
V_60 -> V_122 = V_127 ;
break;
case V_128 :
default:
V_60 -> V_122 = V_129 ;
break;
}
F_79 ( V_60 ) ;
}
static void F_80 ( struct V_70 * V_71 )
{
struct V_39 * V_40 = V_71 -> V_66 -> V_39 ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_130 * V_130 = V_2 -> V_131 ;
struct V_31 * V_32 = F_15 ( V_130 ,
struct V_31 , V_132 ) ;
struct V_54 * V_55 = F_15 ( V_40 ,
struct V_54 , V_39 ) ;
void * V_133 ;
F_4 ( L_10 , V_55 -> V_134 ) ;
V_133 = F_81 ( & V_32 -> V_135 , V_55 -> V_134 ) ;
F_82 ( V_133 && ( V_133 != V_40 ) ) ;
F_4 ( L_11 ,
V_40 , V_55 -> V_136 , V_55 -> V_134 ) ;
F_83 ( V_32 , V_55 , V_71 ) ;
}
static void F_84 ( struct V_137 * V_137 )
{
struct V_69 * V_66 = F_15 ( V_137 ,
struct V_69 , V_138 ) ;
F_56 ( V_66 -> V_72 ) ;
}
static void F_85 ( struct V_69 * V_66 )
{
struct V_70 * V_71 = V_66 -> V_72 ;
struct V_139 * V_140 = V_71 -> V_74 -> V_76 ;
unsigned long V_75 ;
F_52 ( & V_140 -> V_77 , V_75 ) ;
F_86 ( & V_66 -> V_138 , F_84 ) ;
F_54 ( & V_140 -> V_77 , V_75 ) ;
}
static void F_87 ( struct V_70 * V_71 )
{
F_88 ( & V_71 -> V_74 -> V_76 -> V_77 ) ;
F_86 ( & V_71 -> V_66 -> V_138 , F_84 ) ;
}
static void F_89 ( struct V_70 * V_71 )
{
F_88 ( & V_71 -> V_74 -> V_76 -> V_77 ) ;
F_53 ( V_71 -> V_66 ) ;
}
static struct V_39 * F_90 (
struct V_1 * V_2 ,
struct V_141 * V_142 ,
const char * V_3 )
{
struct V_39 * V_40 , * V_143 ;
struct V_54 * V_55 ;
T_2 V_25 ;
T_3 V_144 ;
if ( F_3 ( V_3 , & V_25 , 1 ) < 0 )
return F_91 ( - V_22 ) ;
V_143 = F_32 ( V_2 ) ;
if ( ! V_143 )
return F_91 ( - V_145 ) ;
V_144 = 1 ;
V_40 = F_92 ( V_2 , V_143 ,
V_3 , V_144 ) ;
if ( F_93 ( V_40 ) ) {
F_35 ( V_2 , V_143 ) ;
return V_40 ;
}
V_55 = F_15 ( V_40 , struct V_54 , V_39 ) ;
V_55 -> V_136 = V_25 ;
F_5 ( & V_55 -> V_146 [ 0 ] , V_12 , V_25 ) ;
return V_40 ;
}
static void F_94 ( struct V_39 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_2 ;
struct V_54 * V_55 = F_15 ( V_147 ,
struct V_54 , V_39 ) ;
F_95 ( V_2 , V_147 , 1 ) ;
F_36 ( V_55 ) ;
}
static T_1 F_96 (
struct V_1 * V_2 ,
char * V_148 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return snprintf ( V_148 , V_149 , L_12 ,
F_97 ( & V_30 -> V_150 ) ) ;
}
static T_1 F_98 (
struct V_1 * V_2 ,
const char * V_148 ,
T_4 V_23 )
{
struct V_130 * V_130 = V_2 -> V_131 ;
struct V_31 * V_32 = F_15 ( V_130 ,
struct V_31 , V_132 ) ;
struct V_73 * V_74 = V_32 -> V_151 ;
struct V_139 * V_140 = V_74 -> V_76 ;
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
unsigned long V_152 ;
int V_27 ;
V_27 = F_99 ( V_148 , 0 , & V_152 ) ;
if ( V_27 < 0 ) {
F_34 ( L_13 , V_27 ) ;
return - V_22 ;
}
if ( ( V_152 != 1 ) && ( V_152 != 0 ) ) {
F_34 ( L_14 , V_152 ) ;
return - V_22 ;
}
if ( V_152 ) {
F_100 ( & V_30 -> V_150 , 1 ) ;
F_101 ( V_74 ) ;
} else {
if ( ! V_140 -> V_153 . V_154 ) {
F_34 ( L_15 ) ;
return - V_155 ;
}
F_100 ( & V_30 -> V_150 , 0 ) ;
F_102 ( V_140 -> V_153 . V_154 ) ;
}
return V_23 ;
}
static struct V_1 * F_103 (
struct V_130 * V_4 ,
struct V_141 * V_142 ,
const char * V_3 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_132 ) ;
struct V_29 * V_30 ;
unsigned long V_156 ;
int V_44 ;
if ( strstr ( V_3 , L_16 ) != V_3 )
return F_91 ( - V_22 ) ;
if ( F_99 ( V_3 + 5 , 10 , & V_156 ) || V_156 > V_157 )
return F_91 ( - V_22 ) ;
if ( ! V_32 -> V_158 && ( V_156 != 1 ) ) {
F_34 ( L_17 ) ;
return F_91 ( - V_159 ) ;
}
V_30 = F_33 ( sizeof( struct V_29 ) , V_56 ) ;
if ( ! V_30 ) {
F_34 ( L_18 ) ;
return F_91 ( - V_145 ) ;
}
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_156 ;
V_30 -> V_48 . V_49 = 1 ;
V_30 -> V_48 . V_51 = 1 ;
V_30 -> V_48 . V_50 = 1 ;
V_30 -> V_48 . V_53 = 1 ;
V_44 = F_104 ( & V_160 -> V_161 , V_4 ,
& V_30 -> V_2 , V_30 , V_162 ) ;
if ( V_44 < 0 ) {
F_36 ( V_30 ) ;
return NULL ;
}
if ( V_32 -> V_158 == NULL )
V_32 -> V_163 = V_30 ;
return & V_30 -> V_2 ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_73 * V_74 = V_32 -> V_151 ;
struct V_139 * V_140 = V_74 -> V_76 ;
if ( V_140 -> V_153 . V_154 && ! V_140 -> V_153 . V_154 -> V_164 )
F_102 ( V_140 -> V_153 . V_154 ) ;
F_106 ( V_2 ) ;
if ( V_32 -> V_158 == NULL )
V_32 -> V_163 = NULL ;
F_36 ( V_30 ) ;
}
static struct V_1 * F_107 (
struct V_130 * V_4 ,
struct V_141 * V_142 ,
const char * V_3 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_132 ) ;
struct V_29 * V_30 ;
unsigned long V_156 ;
int V_44 ;
if ( strstr ( V_3 , L_16 ) != V_3 )
return F_91 ( - V_22 ) ;
if ( F_99 ( V_3 + 5 , 10 , & V_156 ) || V_156 > V_157 )
return F_91 ( - V_22 ) ;
V_30 = F_33 ( sizeof( struct V_29 ) , V_56 ) ;
if ( ! V_30 ) {
F_34 ( L_18 ) ;
return F_91 ( - V_145 ) ;
}
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_156 ;
V_44 = F_104 ( & V_165 -> V_161 , V_4 ,
& V_30 -> V_2 , V_30 , V_162 ) ;
if ( V_44 < 0 ) {
F_36 ( V_30 ) ;
return NULL ;
}
return & V_30 -> V_2 ;
}
static struct V_70 * F_108 (
T_7 * V_74 ,
const T_9 * V_166 )
{
struct V_139 * V_140 = V_74 -> V_76 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_54 * V_55 ;
T_3 V_167 ;
V_32 = V_140 -> V_153 . V_168 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_109 () ;
return NULL ;
}
V_167 = ( ( ( unsigned long ) V_166 [ 0 ] << 16 ) |
( ( unsigned long ) V_166 [ 1 ] << 8 ) |
( unsigned long ) V_166 [ 2 ] ) ;
F_4 ( L_20 , V_167 ) ;
V_40 = F_110 ( & V_32 -> V_135 , V_167 ) ;
if ( ! V_40 ) {
F_4 ( L_21 , V_167 ) ;
return NULL ;
}
F_4 ( L_22 ,
V_40 , V_40 -> V_169 ) ;
V_55 = F_15 ( V_40 , struct V_54 , V_39 ) ;
if ( ! V_55 -> V_70 ) {
F_34 ( L_23 ) ;
return NULL ;
}
return V_55 -> V_70 ;
}
static void F_111 (
struct V_31 * V_32 ,
struct V_39 * V_170 ,
struct V_54 * V_55 ,
struct V_69 * V_66 ,
struct V_70 * V_70 ,
T_9 * V_166 )
{
T_3 V_167 ;
void * V_171 ;
int V_27 ;
V_167 = ( ( ( unsigned long ) V_166 [ 0 ] << 16 ) |
( ( unsigned long ) V_166 [ 1 ] << 8 ) |
( unsigned long ) V_166 [ 2 ] ) ;
F_4 ( L_24 , V_167 ) ;
V_171 = F_110 ( & V_32 -> V_135 , V_167 ) ;
if ( ! V_171 ) {
if ( V_170 ) {
F_4 ( L_25 ) ;
V_55 -> V_134 = V_167 ;
V_27 = F_112 ( & V_32 -> V_135 , V_167 ,
V_170 , V_105 ) ;
if ( V_27 )
F_113 ( V_172 L_26 ,
( int ) V_167 ) ;
} else {
F_4 ( L_27 ) ;
}
V_70 -> V_66 = V_66 ;
V_55 -> V_70 = V_70 ;
return;
}
if ( V_55 -> V_70 ) {
if ( V_170 == NULL ) {
F_4 ( L_28 ) ;
F_81 ( & V_32 -> V_135 , V_167 ) ;
V_55 -> V_70 = NULL ;
return;
}
F_4 ( L_29 ) ;
F_114 ( & V_32 -> V_135 , V_167 , V_170 ) ;
V_70 -> V_66 = V_66 ;
V_55 -> V_70 = V_70 ;
return;
}
if ( V_170 == NULL ) {
F_4 ( L_30 ) ;
F_81 ( & V_32 -> V_135 , V_167 ) ;
return;
}
F_4 ( L_31 ) ;
F_114 ( & V_32 -> V_135 , V_167 , V_170 ) ;
V_70 -> V_66 = V_66 ;
V_55 -> V_70 = V_70 ;
F_4 ( L_32 ,
V_55 -> V_70 , V_170 , V_170 -> V_169 ) ;
}
static struct V_70 * F_115 (
T_7 * V_74 ,
const T_10 V_173 )
{
struct V_139 * V_140 = V_74 -> V_76 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_54 * V_55 ;
struct V_174 * V_175 ;
V_32 = V_140 -> V_153 . V_168 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_109 () ;
return NULL ;
}
F_4 ( L_33 , V_173 ) ;
V_175 = V_32 -> V_176 + V_173 ;
V_40 = V_175 -> V_40 ;
if ( ! V_40 ) {
F_4 ( L_34 ,
V_173 ) ;
return NULL ;
}
V_55 = F_15 ( V_40 , struct V_54 , V_39 ) ;
if ( ! V_55 -> V_70 ) {
F_34 ( L_23 ) ;
return NULL ;
}
return V_55 -> V_70 ;
}
static void F_116 (
struct V_31 * V_32 ,
struct V_39 * V_170 ,
struct V_54 * V_55 ,
struct V_69 * V_66 ,
struct V_70 * V_70 ,
T_10 V_173 )
{
struct V_39 * V_177 ;
struct V_174 * V_175 ;
F_4 ( L_35 , V_173 ) ;
V_175 = & ( (struct V_174 * )
V_32 -> V_176 ) [ V_173 ] ;
V_177 = V_175 -> V_40 ;
if ( ! V_177 ) {
F_4 ( L_36 ) ;
V_175 -> V_40 = V_170 ;
if ( V_70 -> V_66 != V_66 )
V_70 -> V_66 = V_66 ;
if ( V_55 -> V_70 != V_70 )
V_55 -> V_70 = V_70 ;
return;
}
if ( V_55 -> V_70 ) {
if ( V_170 == NULL ) {
F_4 ( L_37 ) ;
V_175 -> V_40 = NULL ;
V_55 -> V_70 = NULL ;
return;
}
F_4 ( L_38 ) ;
V_175 -> V_40 = V_170 ;
if ( V_70 -> V_66 != V_66 )
V_70 -> V_66 = V_66 ;
if ( V_55 -> V_70 != V_70 )
V_55 -> V_70 = V_70 ;
return;
}
if ( V_170 == NULL ) {
F_4 ( L_39 ) ;
V_175 -> V_40 = NULL ;
return;
}
F_4 ( L_40 ) ;
V_175 -> V_40 = V_170 ;
if ( V_70 -> V_66 != V_66 )
V_70 -> V_66 = V_66 ;
if ( V_55 -> V_70 != V_70 )
V_55 -> V_70 = V_70 ;
F_4 ( L_41 ,
V_55 -> V_70 , V_170 , V_170 -> V_169 ) ;
}
static void F_83 ( struct V_31 * V_32 ,
struct V_54 * V_55 , struct V_70 * V_71 )
{
struct V_69 * V_66 = V_71 -> V_66 ;
unsigned char V_178 [ 3 ] ;
V_178 [ 0 ] = V_71 -> V_166 . V_16 . V_179 ;
V_178 [ 1 ] = V_71 -> V_166 . V_16 . V_180 ;
V_178 [ 2 ] = V_71 -> V_166 . V_16 . V_181 ;
F_111 ( V_32 , NULL , V_55 , V_66 ,
V_71 , V_178 ) ;
F_116 ( V_32 , NULL , V_55 , V_66 ,
V_71 , V_71 -> V_173 ) ;
}
static void F_117 ( struct V_70 * V_71 )
{
struct V_154 * V_153 = V_71 -> V_153 ;
struct V_139 * V_140 = V_153 -> V_140 ;
struct V_69 * V_66 ;
struct V_39 * V_40 ;
struct V_31 * V_32 ;
struct V_54 * V_55 ;
F_51 ( F_118 () ) ;
V_66 = V_71 -> V_66 ;
if ( ! V_66 ) {
F_34 ( L_42 ) ;
F_109 () ;
return;
}
V_40 = V_66 -> V_39 ;
V_55 = F_15 ( V_40 , struct V_54 , V_39 ) ;
V_32 = V_140 -> V_153 . V_168 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_109 () ;
return;
}
F_119 ( V_66 ) ;
F_120 ( V_71 -> V_66 ) ;
F_121 ( V_71 -> V_66 ) ;
}
static int F_122 (
T_7 * V_74 ,
unsigned char * V_182 ,
void * V_70 ,
T_9 * V_166 ,
T_10 V_173 )
{
struct V_139 * V_140 = V_74 -> V_76 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
struct V_54 * V_55 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_69 * V_66 ;
struct V_70 * V_71 = V_70 ;
unsigned char V_183 [ 36 ] ;
unsigned long V_75 ;
V_32 = V_140 -> V_153 . V_168 ;
if ( ! V_32 ) {
F_34 ( L_19 ) ;
F_109 () ;
return - V_22 ;
}
V_30 = V_32 -> V_163 ;
if ( ! V_30 ) {
F_34 ( L_43 ) ;
return - V_22 ;
}
V_2 = & V_30 -> V_2 ;
V_66 = F_123 () ;
if ( F_93 ( V_66 ) ) {
F_34 ( L_44 ) ;
return F_124 ( V_66 ) ;
}
memset ( & V_183 , 0 , 36 ) ;
snprintf ( V_183 , 36 , L_45 ,
V_182 [ 0 ] , V_182 [ 1 ] , V_182 [ 2 ] , V_182 [ 3 ] , V_182 [ 4 ] ,
V_182 [ 5 ] , V_182 [ 6 ] , V_182 [ 7 ] ) ;
V_66 -> V_39 = F_125 ( V_2 ,
V_183 ) ;
if ( ! V_66 -> V_39 ) {
F_126 ( V_66 ) ;
return - V_22 ;
}
V_40 = V_66 -> V_39 ;
V_55 = F_15 ( V_40 , struct V_54 , V_39 ) ;
F_52 ( & V_140 -> V_77 , V_75 ) ;
F_111 ( V_32 , V_40 , V_55 , V_66 ,
V_70 , V_166 ) ;
F_116 ( V_32 , V_40 , V_55 , V_66 ,
V_70 , V_173 ) ;
F_54 ( & V_140 -> V_77 , V_75 ) ;
F_127 ( V_40 -> V_2 , V_40 , V_66 , V_71 ) ;
return 0 ;
}
static void F_128 ( struct V_70 * V_71 , T_11 V_166 ,
T_10 V_173 , bool V_184 )
{
struct V_154 * V_153 = V_71 -> V_153 ;
struct V_139 * V_140 = V_153 -> V_140 ;
struct V_31 * V_32 = V_140 -> V_153 . V_168 ;
struct V_39 * V_40 = V_71 -> V_66 -> V_39 ;
struct V_54 * V_55 = F_15 ( V_40 ,
struct V_54 , V_39 ) ;
T_3 V_167 ;
if ( V_71 -> V_173 != V_173 || V_71 -> V_166 . V_185 != V_166 . V_185 )
F_129 ( L_46 ,
V_71 , V_71 -> V_183 ,
V_71 -> V_173 , V_173 , V_71 -> V_166 . V_16 . V_179 ,
V_71 -> V_166 . V_16 . V_180 , V_71 -> V_166 . V_16 . V_181 , V_166 . V_16 . V_179 ,
V_166 . V_16 . V_180 , V_166 . V_16 . V_181 ) ;
if ( V_71 -> V_173 != V_173 ) {
if ( V_32 -> V_176 [ V_71 -> V_173 ] . V_40 == V_40 )
V_32 -> V_176 [ V_71 -> V_173 ] . V_40 = NULL ;
V_32 -> V_176 [ V_173 ] . V_40 = V_40 ;
V_71 -> V_173 = V_173 ;
}
if ( V_71 -> V_166 . V_185 != V_166 . V_185 ) {
V_167 = ( ( ( T_3 ) V_71 -> V_166 . V_16 . V_179 << 16 ) |
( ( T_3 ) V_71 -> V_166 . V_16 . V_180 << 8 ) |
( ( T_3 ) V_71 -> V_166 . V_16 . V_181 ) ) ;
if ( F_110 ( & V_32 -> V_135 , V_167 ) )
F_130 ( F_81 ( & V_32 -> V_135 , V_167 ) != V_40 ,
L_47 ,
V_71 -> V_166 . V_16 . V_179 , V_71 -> V_166 . V_16 . V_180 , V_71 -> V_166 . V_16 . V_181 ) ;
else
F_130 ( 1 , L_48 ,
V_71 -> V_166 . V_16 . V_179 , V_71 -> V_166 . V_16 . V_180 , V_71 -> V_166 . V_16 . V_181 ) ;
V_167 = ( ( ( T_3 ) V_166 . V_16 . V_179 << 16 ) |
( ( T_3 ) V_166 . V_16 . V_180 << 8 ) |
( ( T_3 ) V_166 . V_16 . V_181 ) ) ;
if ( F_110 ( & V_32 -> V_135 , V_167 ) ) {
F_130 ( 1 , L_49 ,
V_166 . V_16 . V_179 , V_166 . V_16 . V_180 , V_166 . V_16 . V_181 ) ;
F_114 ( & V_32 -> V_135 , V_167 , V_40 ) ;
} else {
F_112 ( & V_32 -> V_135 , V_167 , V_40 , V_105 ) ;
}
V_71 -> V_166 = V_166 ;
V_55 -> V_134 = V_167 ;
}
V_71 -> V_184 = V_184 ;
}
static int F_131 ( struct V_31 * V_32 )
{
int V_27 ;
V_27 = F_132 ( & V_32 -> V_135 ) ;
if ( V_27 ) {
F_34 ( L_50 ) ;
return V_27 ;
}
V_32 -> V_176 = F_133 ( sizeof( struct V_174 ) *
65536 ) ;
if ( ! V_32 -> V_176 ) {
F_34 ( L_51 ,
sizeof( struct V_174 ) * 65536 ) ;
F_134 ( & V_32 -> V_135 ) ;
return - V_145 ;
}
memset ( V_32 -> V_176 , 0 , sizeof( struct V_174 )
* 65536 ) ;
F_4 ( L_52 ,
sizeof( struct V_174 ) * 65536 ) ;
return 0 ;
}
static int F_135 ( struct V_73 * V_74 )
{
struct V_139 * V_140 = V_74 -> V_76 ;
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) V_140 -> V_153 . V_168 ;
V_32 -> V_151 = V_74 ;
return 0 ;
}
static struct V_130 * F_136 (
struct V_186 * V_187 ,
struct V_141 * V_142 ,
const char * V_3 )
{
struct V_31 * V_32 ;
T_2 V_24 ;
int V_44 = - V_155 ;
if ( F_3 ( V_3 , & V_24 , 1 ) < 0 )
return F_91 ( - V_22 ) ;
V_32 = F_33 ( sizeof( struct V_31 ) , V_56 ) ;
if ( ! V_32 ) {
F_34 ( L_53 ) ;
return F_91 ( - V_145 ) ;
}
V_32 -> V_188 = V_24 ;
F_5 ( & V_32 -> V_189 [ 0 ] , V_12 ,
V_24 ) ;
sprintf ( V_32 -> V_36 , L_54 , ( unsigned long long ) V_24 ) ;
V_44 = F_131 ( V_32 ) ;
if ( V_44 != 0 )
goto V_190;
V_44 = F_137 ( & V_191 , V_24 ,
F_135 , V_32 ) ;
if ( V_44 != 0 )
goto V_192;
return & V_32 -> V_132 ;
V_192:
F_138 ( V_32 -> V_176 ) ;
F_134 ( & V_32 -> V_135 ) ;
V_190:
F_36 ( V_32 ) ;
return F_91 ( V_44 ) ;
}
static void F_139 ( struct V_130 * V_4 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_132 ) ;
struct V_73 * V_74 = V_32 -> V_151 ;
struct V_139 * V_140 = V_74 -> V_76 ;
struct V_39 * V_133 ;
T_3 V_167 = 0 ;
if ( V_140 -> V_153 . V_154 && ! V_140 -> V_153 . V_154 -> V_193 )
F_140 ( V_140 -> V_153 . V_154 ) ;
F_141 ( V_74 ) ;
F_138 ( V_32 -> V_176 ) ;
F_142 (&lport->lport_fcport_map, key, node)
F_81 ( & V_32 -> V_135 , V_167 ) ;
F_134 ( & V_32 -> V_135 ) ;
F_36 ( V_32 ) ;
}
static struct V_130 * F_143 (
struct V_186 * V_187 ,
struct V_141 * V_142 ,
const char * V_3 )
{
struct V_31 * V_32 ;
T_2 V_194 , V_195 ;
int V_44 ;
if ( F_11 ( V_3 , strlen ( V_3 ) + 1 ,
& V_194 , & V_195 ) < 0 )
return F_91 ( - V_22 ) ;
V_32 = F_33 ( sizeof( struct V_31 ) , V_56 ) ;
if ( ! V_32 ) {
F_34 ( L_55 ) ;
return F_91 ( - V_145 ) ;
}
V_32 -> V_196 = V_194 ;
V_32 -> V_197 = V_195 ;
F_12 ( & V_32 -> V_37 [ 0 ] ,
V_12 , V_194 , V_195 ) ;
sprintf ( V_32 -> V_36 , L_54 , ( unsigned long long ) V_194 ) ;
V_44 = - V_159 ;
if ( V_44 != 0 )
goto V_190;
return & V_32 -> V_132 ;
V_190:
F_36 ( V_32 ) ;
return F_91 ( V_44 ) ;
}
static void F_144 ( struct V_130 * V_4 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_132 ) ;
struct V_73 * V_74 = V_32 -> V_151 ;
struct V_198 * V_199 = V_74 -> V_200 ;
F_145 ( V_32 -> V_201 ) ;
F_146 ( V_199 ) ;
F_36 ( V_32 ) ;
}
static T_1 F_147 (
struct V_186 * V_187 ,
char * V_148 )
{
return sprintf ( V_148 ,
L_56
V_202 L_57 , V_203 , F_148 () -> V_204 ,
F_148 () -> V_205 ) ;
}
static int F_149 ( void )
{
struct V_186 * V_206 , * V_207 ;
int V_44 ;
F_4 ( L_58
V_202 L_57 , V_203 , F_148 () -> V_204 ,
F_148 () -> V_205 ) ;
V_206 = F_150 ( V_208 , L_3 ) ;
if ( F_93 ( V_206 ) ) {
F_34 ( L_59 ) ;
return F_124 ( V_206 ) ;
}
V_206 -> V_161 = V_209 ;
V_206 -> V_210 . V_211 . V_212 = V_213 ;
V_206 -> V_210 . V_214 . V_212 = V_215 ;
V_206 -> V_210 . V_216 . V_212 =
V_217 ;
V_206 -> V_210 . V_218 . V_212 = NULL ;
V_206 -> V_210 . V_219 . V_212 = NULL ;
V_206 -> V_210 . V_220 . V_212 = NULL ;
V_206 -> V_210 . V_221 . V_212 = NULL ;
V_206 -> V_210 . V_222 . V_212 = NULL ;
V_206 -> V_210 . V_223 . V_212 = NULL ;
V_44 = F_151 ( V_206 ) ;
if ( V_44 < 0 ) {
F_34 ( L_60 ) ;
return V_44 ;
}
V_160 = V_206 ;
F_4 ( L_61 ) ;
V_207 = F_150 ( V_208 , L_5 ) ;
if ( F_93 ( V_207 ) ) {
F_34 ( L_59 ) ;
V_44 = F_124 ( V_207 ) ;
goto V_224;
}
V_207 -> V_161 = V_225 ;
V_207 -> V_210 . V_211 . V_212 = V_213 ;
V_207 -> V_210 . V_214 . V_212 = NULL ;
V_207 -> V_210 . V_216 . V_212 = NULL ;
V_207 -> V_210 . V_218 . V_212 = NULL ;
V_207 -> V_210 . V_219 . V_212 = NULL ;
V_207 -> V_210 . V_220 . V_212 = NULL ;
V_207 -> V_210 . V_221 . V_212 = NULL ;
V_207 -> V_210 . V_222 . V_212 = NULL ;
V_207 -> V_210 . V_223 . V_212 = NULL ;
V_44 = F_151 ( V_207 ) ;
if ( V_44 < 0 ) {
F_34 ( L_60 ) ;
goto V_224;
}
V_165 = V_207 ;
F_4 ( L_62 ) ;
V_63 = F_152 ( L_63 ,
V_226 , 0 ) ;
if ( ! V_63 ) {
V_44 = - V_145 ;
goto V_227;
}
V_228 = F_152 ( L_64 , 0 , 0 ) ;
if ( ! V_228 ) {
V_44 = - V_145 ;
goto V_229;
}
return 0 ;
V_229:
F_153 ( V_63 ) ;
V_227:
F_154 ( V_165 ) ;
V_224:
F_154 ( V_160 ) ;
return V_44 ;
}
static void F_155 ( void )
{
F_153 ( V_228 ) ;
F_153 ( V_63 ) ;
F_154 ( V_160 ) ;
V_160 = NULL ;
F_4 ( L_65 ) ;
F_154 ( V_165 ) ;
V_165 = NULL ;
F_4 ( L_66 ) ;
}
static int T_12 F_156 ( void )
{
int V_44 ;
V_44 = F_149 () ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
}
static void T_13 F_157 ( void )
{
F_155 () ;
}
