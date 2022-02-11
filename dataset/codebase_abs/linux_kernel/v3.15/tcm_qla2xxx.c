static T_1 F_1 ( const char * V_1 , T_2 * V_2 , int V_3 )
{
const char * V_4 ;
char V_5 ;
T_3 V_6 ;
T_3 V_7 = 0 ;
T_3 V_8 = 0 ;
T_3 V_9 ;
* V_2 = 0 ;
for ( V_4 = V_1 ; V_4 < & V_1 [ V_10 - 1 ] ; V_4 ++ ) {
V_5 = * V_4 ;
if ( V_5 == '\n' && V_4 [ 1 ] == '\0' )
continue;
if ( V_3 && V_8 ++ == 2 && V_7 ++ < 7 ) {
V_8 = 0 ;
if ( V_5 == ':' )
continue;
V_9 = 1 ;
goto V_11;
}
if ( V_5 == '\0' ) {
V_9 = 2 ;
if ( V_3 && V_7 != 8 )
goto V_11;
return V_4 - V_1 ;
}
V_9 = 3 ;
if ( isdigit ( V_5 ) )
V_6 = V_5 - '0' ;
else if ( isxdigit ( V_5 ) && ( islower ( V_5 ) || ! V_3 ) )
V_6 = tolower ( V_5 ) - 'a' + 10 ;
else
goto V_11;
* V_2 = ( * V_2 << 4 ) | V_6 ;
}
V_9 = 4 ;
V_11:
F_2 ( L_1 ,
V_9 , V_4 - V_1 , V_8 , V_7 ) ;
return - 1 ;
}
static T_1 F_3 ( char * V_12 , T_4 V_13 , T_2 V_2 )
{
T_5 V_14 [ 8 ] ;
F_4 ( V_2 , V_14 ) ;
return snprintf ( V_12 , V_13 ,
L_2 ,
V_14 [ 0 ] , V_14 [ 1 ] , V_14 [ 2 ] , V_14 [ 3 ] , V_14 [ 4 ] , V_14 [ 5 ] , V_14 [ 6 ] , V_14 [ 7 ] ) ;
}
static char * F_5 ( void )
{
return L_3 ;
}
static int F_6 ( const char * V_15 , T_2 * V_16 )
{
unsigned int V_17 , V_18 ;
T_5 V_2 [ 8 ] ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
for ( V_17 = 0 , V_18 = 0 ; V_17 < 16 ; V_17 ++ ) {
int V_19 ;
V_19 = F_7 ( * V_15 ++ ) ;
if ( V_19 >= 0 )
V_18 = ( V_18 << 4 ) | V_19 ;
else
return - V_20 ;
if ( V_17 % 2 ) {
V_2 [ V_17 / 2 ] = V_18 & 0xff ;
V_18 = 0 ;
}
}
* V_16 = F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 (
const char * V_1 ,
T_4 V_21 ,
T_2 * V_22 ,
T_2 * V_23 )
{
unsigned int V_24 = V_21 ;
int V_25 ;
* V_22 = 0 ;
* V_23 = 0 ;
if ( V_1 [ V_24 - 1 ] == '\n' || V_1 [ V_24 - 1 ] == 0 )
V_24 -- ;
if ( ( V_24 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_20 ;
V_25 = F_6 ( & V_1 [ 0 ] , V_22 ) ;
if ( V_25 != 0 )
return V_25 ;
V_25 = F_6 ( & V_1 [ 17 ] , V_23 ) ;
if ( V_25 != 0 )
return V_25 ;
return 0 ;
}
static char * F_10 ( void )
{
return L_4 ;
}
static T_5 F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
T_5 V_32 ;
switch ( V_31 -> V_33 ) {
case V_34 :
default:
V_32 = F_13 ( V_27 ) ;
break;
}
return V_32 ;
}
static char * F_14 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
return V_31 -> V_35 ;
}
static T_6 F_15 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_36 ;
}
static T_3 F_16 ( struct V_26 * V_27 )
{
return 1 ;
}
static T_3 F_17 (
struct V_26 * V_27 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
int * V_41 ,
unsigned char * V_12 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
int V_42 = 0 ;
switch ( V_31 -> V_33 ) {
case V_34 :
default:
V_42 = F_18 ( V_27 , V_38 , V_40 ,
V_41 , V_12 ) ;
break;
}
return V_42 ;
}
static T_3 F_19 (
struct V_26 * V_27 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
int * V_41 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
int V_42 = 0 ;
switch ( V_31 -> V_33 ) {
case V_34 :
default:
V_42 = F_20 ( V_27 , V_38 , V_40 ,
V_41 ) ;
break;
}
return V_42 ;
}
static char * F_21 (
struct V_26 * V_27 ,
const char * V_12 ,
T_3 * V_43 ,
char * * V_44 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
char * V_45 = NULL ;
switch ( V_31 -> V_33 ) {
case V_34 :
default:
V_45 = F_22 ( V_27 , V_12 , V_43 ,
V_44 ) ;
break;
}
return V_45 ;
}
static int F_23 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_46 . V_47 ;
}
static int F_24 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_46 . V_48 ;
}
static int F_25 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_46 . V_49 ;
}
static int F_26 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_46 . V_50 ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_46 . V_51 ;
}
static struct V_37 * F_28 (
struct V_26 * V_27 )
{
struct V_52 * V_53 ;
V_53 = F_29 ( sizeof( struct V_52 ) , V_54 ) ;
if ( ! V_53 ) {
F_30 ( L_5 ) ;
return NULL ;
}
return & V_53 -> V_37 ;
}
static void F_31 (
struct V_26 * V_27 ,
struct V_37 * V_38 )
{
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
F_32 ( V_53 ) ;
}
static T_3 F_33 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_36 ;
}
static void F_34 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_12 ( V_56 ,
struct V_57 , V_59 ) ;
F_35 ( & V_58 -> V_60 , 0 ) ;
}
static void F_36 ( struct V_57 * V_58 )
{
F_37 ( & V_58 -> V_59 , F_34 ) ;
F_38 ( V_61 , & V_58 -> V_59 ) ;
}
static void F_39 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_12 ( V_56 , struct V_62 , V_56 ) ;
F_35 ( & V_63 -> V_60 , 0 ) ;
}
static void F_40 ( struct V_62 * V_63 )
{
F_37 ( & V_63 -> V_56 , F_39 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_41 ( struct V_60 * V_60 )
{
return F_42 ( V_60 -> V_64 , V_60 ) ;
}
static void F_43 ( struct V_60 * V_60 )
{
struct V_62 * V_63 ;
if ( V_60 -> V_65 & V_66 ) {
struct V_57 * V_58 = F_12 ( V_60 ,
struct V_57 , V_60 ) ;
F_44 ( V_58 ) ;
return;
}
V_63 = F_12 ( V_60 , struct V_62 , V_60 ) ;
F_45 ( V_63 ) ;
}
static int F_46 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_71 * V_72 ;
unsigned long V_73 ;
F_47 ( ! V_69 ) ;
V_72 = V_69 -> V_72 ;
F_48 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
F_49 ( V_64 ) ;
F_50 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
return 1 ;
}
static void F_51 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_71 * V_72 ;
unsigned long V_73 ;
F_47 ( ! V_69 ) ;
V_72 = V_69 -> V_72 ;
F_48 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
F_52 ( V_69 ) ;
F_50 ( & V_72 -> V_74 -> V_75 , V_73 ) ;
}
static T_3 F_53 ( struct V_67 * V_64 )
{
return 0 ;
}
static int F_54 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_76 = V_60 -> V_77 ;
V_63 -> V_78 = F_55 ( V_60 ) ;
V_63 -> V_79 = V_60 -> V_80 ;
V_63 -> V_81 = V_60 -> V_82 ;
return F_56 ( V_63 ) ;
}
static int F_57 ( struct V_60 * V_60 )
{
unsigned long V_73 ;
F_48 ( & V_60 -> V_83 , V_73 ) ;
if ( V_60 -> V_84 == V_85 ||
V_60 -> V_84 == V_86 ) {
F_50 ( & V_60 -> V_83 , V_73 ) ;
F_58 ( & V_60 -> V_87 ,
3000 ) ;
return 0 ;
}
F_50 ( & V_60 -> V_83 , V_73 ) ;
return 0 ;
}
static void F_59 ( struct V_37 * V_53 )
{
return;
}
static T_3 F_60 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
return V_63 -> V_88 ;
}
static int F_61 ( struct V_60 * V_60 )
{
return 0 ;
}
static int F_62 ( T_7 * V_72 , struct V_62 * V_63 ,
unsigned char * V_89 , T_8 V_77 , int V_90 ,
int V_91 , int V_92 )
{
struct V_60 * V_60 = & V_63 -> V_60 ;
struct V_67 * V_64 ;
struct V_68 * V_69 ;
int V_73 = V_93 ;
if ( V_92 )
V_73 |= V_94 ;
V_69 = V_63 -> V_69 ;
if ( ! V_69 ) {
F_30 ( L_6 ) ;
return - V_20 ;
}
V_64 = V_69 -> V_64 ;
if ( ! V_64 ) {
F_30 ( L_7 ) ;
return - V_20 ;
}
return F_63 ( V_60 , V_64 , V_89 , & V_63 -> V_95 [ 0 ] ,
V_63 -> V_96 , V_77 , V_90 ,
V_91 , V_73 ) ;
}
static void F_64 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_12 ( V_56 , struct V_62 , V_56 ) ;
if ( ! V_63 -> V_97 ) {
if ( V_63 -> V_60 . V_98 & V_99 ) {
F_65 ( & V_63 -> V_60 . V_87 ) ;
return;
}
F_66 ( & V_63 -> V_60 ,
V_100 ) ;
return;
}
return F_67 ( & V_63 -> V_60 ) ;
}
static void F_68 ( struct V_62 * V_63 )
{
F_37 ( & V_63 -> V_56 , F_64 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_69 ( struct V_57 * V_58 , T_8 V_101 ,
T_9 V_102 , T_8 V_88 )
{
struct V_68 * V_69 = V_58 -> V_69 ;
struct V_60 * V_60 = & V_58 -> V_60 ;
return F_70 ( V_60 , V_69 -> V_64 , NULL , V_101 , V_58 ,
V_102 , V_103 , V_88 , V_93 ) ;
}
static int F_71 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_76 = V_60 -> V_77 ;
V_63 -> V_78 = F_55 ( V_60 ) ;
V_63 -> V_104 = ( V_60 -> V_98 & V_99 ) ;
V_63 -> V_79 = V_60 -> V_80 ;
V_63 -> V_81 = V_60 -> V_82 ;
V_63 -> V_105 = 0 ;
return F_72 ( V_63 , V_106 | V_107 ,
V_60 -> V_108 ) ;
}
static int F_73 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
int V_109 = V_107 ;
V_63 -> V_76 = V_60 -> V_77 ;
V_63 -> V_81 = NULL ;
V_63 -> V_79 = 0 ;
V_63 -> V_105 = 0 ;
V_63 -> V_78 = F_55 ( V_60 ) ;
V_63 -> V_104 = ( V_60 -> V_98 & V_99 ) ;
if ( V_60 -> V_110 == V_111 ) {
if ( V_60 -> V_65 & V_112 ) {
V_60 -> V_65 &= ~ V_112 ;
V_60 -> V_113 = 0 ;
}
V_60 -> V_65 |= V_114 ;
V_60 -> V_113 += V_60 -> V_77 ;
V_63 -> V_76 = 0 ;
}
return F_72 ( V_63 , V_109 , V_60 -> V_108 ) ;
}
static void F_74 ( struct V_60 * V_60 )
{
struct V_115 * V_116 = V_60 -> V_115 ;
struct V_57 * V_58 = F_12 ( V_60 ,
struct V_57 , V_60 ) ;
F_2 ( L_8 ,
V_58 , V_116 -> V_117 , V_116 -> V_118 ) ;
switch ( V_116 -> V_118 ) {
case V_119 :
V_58 -> V_120 = V_121 ;
break;
case V_122 :
V_58 -> V_120 = V_123 ;
break;
case V_124 :
V_58 -> V_120 = V_125 ;
break;
case V_126 :
default:
V_58 -> V_120 = V_127 ;
break;
}
F_75 ( V_58 ) ;
}
static void F_76 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
struct V_71 * V_72 = V_63 -> V_72 ;
struct V_128 * V_129 = V_72 -> V_74 ;
if ( ! V_63 -> V_130 )
return;
F_77 ( V_129 -> V_131 , V_63 -> V_81 , V_63 -> V_79 , V_63 -> V_78 ) ;
V_63 -> V_130 = 0 ;
}
static void F_78 ( struct V_68 * V_69 )
{
struct V_37 * V_38 = V_69 -> V_64 -> V_37 ;
struct V_26 * V_27 = V_38 -> V_27 ;
struct V_132 * V_132 = V_27 -> V_133 ;
struct V_30 * V_31 = F_12 ( V_132 ,
struct V_30 , V_134 ) ;
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
void * V_135 ;
F_2 ( L_9 , V_53 -> V_136 ) ;
V_135 = F_79 ( & V_31 -> V_137 , V_53 -> V_136 ) ;
F_80 ( V_135 && ( V_135 != V_38 ) ) ;
F_2 ( L_10 ,
V_38 , V_53 -> V_138 , V_53 -> V_136 ) ;
F_81 ( V_31 , V_53 , V_69 ) ;
}
static void F_82 ( struct V_139 * V_139 )
{
struct V_67 * V_64 = F_12 ( V_139 ,
struct V_67 , V_140 ) ;
F_52 ( V_64 -> V_70 ) ;
}
static void F_83 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_128 * V_129 = V_69 -> V_72 -> V_74 ;
unsigned long V_73 ;
F_48 ( & V_129 -> V_75 , V_73 ) ;
F_84 ( & V_64 -> V_140 , F_82 ) ;
F_50 ( & V_129 -> V_75 , V_73 ) ;
}
static void F_85 ( struct V_68 * V_69 )
{
if ( ! V_69 )
return;
F_86 ( & V_69 -> V_72 -> V_74 -> V_75 ) ;
F_84 ( & V_69 -> V_64 -> V_140 , F_82 ) ;
}
static void F_87 ( struct V_68 * V_69 )
{
F_86 ( & V_69 -> V_72 -> V_74 -> V_75 ) ;
F_49 ( V_69 -> V_64 ) ;
}
static struct V_37 * F_88 (
struct V_26 * V_27 ,
struct V_141 * V_142 ,
const char * V_1 )
{
struct V_37 * V_38 , * V_143 ;
struct V_52 * V_53 ;
T_2 V_23 ;
T_3 V_144 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return F_89 ( - V_20 ) ;
V_143 = F_28 ( V_27 ) ;
if ( ! V_143 )
return F_89 ( - V_145 ) ;
V_144 = 1 ;
V_38 = F_90 ( V_27 , V_143 ,
V_1 , V_144 ) ;
if ( F_91 ( V_38 ) ) {
F_31 ( V_27 , V_143 ) ;
return V_38 ;
}
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
V_53 -> V_138 = V_23 ;
F_3 ( & V_53 -> V_146 [ 0 ] , V_10 , V_23 ) ;
return V_38 ;
}
static void F_92 ( struct V_37 * V_147 )
{
struct V_26 * V_27 = V_147 -> V_27 ;
struct V_52 * V_53 = F_12 ( V_147 ,
struct V_52 , V_37 ) ;
F_93 ( V_27 , V_147 , 1 ) ;
F_32 ( V_53 ) ;
}
static T_1 F_94 (
struct V_26 * V_27 ,
char * V_148 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_148 , V_149 , L_11 ,
F_95 ( & V_29 -> V_150 ) ) ;
}
static void F_96 ( struct V_55 * V_56 )
{
struct V_28 * V_151 = F_12 ( V_56 ,
struct V_28 , V_152 ) ;
struct V_26 * V_27 = & V_151 -> V_27 ;
struct V_71 * V_153 = V_151 -> V_31 -> V_154 ;
if ( ! F_97 ( V_27 -> V_155 -> V_156 ,
& V_27 -> V_157 . V_158 ) ) {
F_98 ( & V_151 -> V_150 , 1 ) ;
F_99 ( V_153 ) ;
}
F_65 ( & V_151 -> V_159 ) ;
}
static void F_100 ( struct V_55 * V_56 )
{
struct V_28 * V_151 = F_12 ( V_56 ,
struct V_28 , V_152 ) ;
struct V_26 * V_27 = & V_151 -> V_27 ;
struct V_71 * V_153 = V_151 -> V_31 -> V_154 ;
if ( ! F_101 ( V_153 -> V_160 . V_161 ) ) {
F_98 ( & V_151 -> V_150 , 0 ) ;
F_102 ( V_27 -> V_155 -> V_156 ,
& V_27 -> V_157 . V_158 ) ;
}
F_65 ( & V_151 -> V_159 ) ;
}
static T_1 F_103 (
struct V_26 * V_27 ,
const char * V_148 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_162 ;
int V_25 ;
V_25 = F_104 ( V_148 , 0 , & V_162 ) ;
if ( V_25 < 0 ) {
F_30 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_162 != 1 ) && ( V_162 != 0 ) ) {
F_30 ( L_13 , V_162 ) ;
return - V_20 ;
}
if ( V_162 ) {
if ( F_95 ( & V_29 -> V_150 ) )
return - V_163 ;
F_37 ( & V_29 -> V_152 , F_96 ) ;
} else {
if ( ! F_95 ( & V_29 -> V_150 ) )
return V_21 ;
F_37 ( & V_29 -> V_152 , F_100 ) ;
}
F_105 ( & V_29 -> V_159 ) ;
F_106 ( & V_29 -> V_152 ) ;
F_107 ( & V_29 -> V_159 ) ;
if ( V_162 ) {
if ( ! F_95 ( & V_29 -> V_150 ) )
return - V_164 ;
} else {
if ( F_95 ( & V_29 -> V_150 ) )
return - V_165 ;
}
return V_21 ;
}
static struct V_26 * F_108 (
struct V_132 * V_2 ,
struct V_141 * V_142 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_134 ) ;
struct V_28 * V_29 ;
unsigned long V_166 ;
int V_42 ;
if ( strstr ( V_1 , L_14 ) != V_1 )
return F_89 ( - V_20 ) ;
if ( F_104 ( V_1 + 5 , 10 , & V_166 ) || V_166 > V_167 )
return F_89 ( - V_20 ) ;
if ( ( V_166 != 1 ) ) {
F_30 ( L_15 ) ;
return F_89 ( - V_168 ) ;
}
V_29 = F_29 ( sizeof( struct V_28 ) , V_54 ) ;
if ( ! V_29 ) {
F_30 ( L_16 ) ;
return F_89 ( - V_145 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_166 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_109 ( & V_169 -> V_170 , V_2 ,
& V_29 -> V_27 , V_29 , V_171 ) ;
if ( V_42 < 0 ) {
F_32 ( V_29 ) ;
return NULL ;
}
V_31 -> V_172 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_110 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_71 * V_72 = V_31 -> V_154 ;
if ( V_72 -> V_160 . V_161 && ! V_72 -> V_160 . V_161 -> V_173 )
F_101 ( V_72 -> V_160 . V_161 ) ;
F_111 ( V_27 ) ;
V_31 -> V_172 = NULL ;
F_32 ( V_29 ) ;
}
static T_1 F_112 (
struct V_26 * V_27 ,
char * V_148 )
{
return F_94 ( V_27 , V_148 ) ;
}
static T_1 F_113 (
struct V_26 * V_27 ,
const char * V_148 ,
T_4 V_21 )
{
struct V_132 * V_132 = V_27 -> V_133 ;
struct V_30 * V_31 = F_12 ( V_132 ,
struct V_30 , V_134 ) ;
struct V_71 * V_72 = V_31 -> V_154 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_162 ;
int V_25 ;
V_25 = F_104 ( V_148 , 0 , & V_162 ) ;
if ( V_25 < 0 ) {
F_30 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_162 != 1 ) && ( V_162 != 0 ) ) {
F_30 ( L_13 , V_162 ) ;
return - V_20 ;
}
if ( V_162 ) {
if ( F_95 ( & V_29 -> V_150 ) )
return - V_163 ;
F_98 ( & V_29 -> V_150 , 1 ) ;
F_99 ( V_72 ) ;
} else {
if ( ! F_95 ( & V_29 -> V_150 ) )
return V_21 ;
F_98 ( & V_29 -> V_150 , 0 ) ;
F_101 ( V_72 -> V_160 . V_161 ) ;
}
return V_21 ;
}
static struct V_26 * F_114 (
struct V_132 * V_2 ,
struct V_141 * V_142 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_134 ) ;
struct V_28 * V_29 ;
unsigned long V_166 ;
int V_42 ;
if ( strstr ( V_1 , L_14 ) != V_1 )
return F_89 ( - V_20 ) ;
if ( F_104 ( V_1 + 5 , 10 , & V_166 ) || V_166 > V_167 )
return F_89 ( - V_20 ) ;
V_29 = F_29 ( sizeof( struct V_28 ) , V_54 ) ;
if ( ! V_29 ) {
F_30 ( L_16 ) ;
return F_89 ( - V_145 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_166 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_109 ( & V_174 -> V_170 , V_2 ,
& V_29 -> V_27 , V_29 , V_171 ) ;
if ( V_42 < 0 ) {
F_32 ( V_29 ) ;
return NULL ;
}
V_31 -> V_172 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_68 * F_115 (
T_7 * V_72 ,
const T_9 * V_175 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
T_3 V_176 ;
V_31 = V_72 -> V_160 . V_177 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_116 () ;
return NULL ;
}
V_176 = ( ( ( unsigned long ) V_175 [ 0 ] << 16 ) |
( ( unsigned long ) V_175 [ 1 ] << 8 ) |
( unsigned long ) V_175 [ 2 ] ) ;
F_2 ( L_18 , V_176 ) ;
V_38 = F_117 ( & V_31 -> V_137 , V_176 ) ;
if ( ! V_38 ) {
F_2 ( L_19 , V_176 ) ;
return NULL ;
}
F_2 ( L_20 ,
V_38 , V_38 -> V_178 ) ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
if ( ! V_53 -> V_68 ) {
F_30 ( L_21 ) ;
return NULL ;
}
return V_53 -> V_68 ;
}
static void F_118 (
struct V_30 * V_31 ,
struct V_37 * V_179 ,
struct V_52 * V_53 ,
struct V_67 * V_64 ,
struct V_68 * V_68 ,
T_9 * V_175 )
{
T_3 V_176 ;
void * V_180 ;
int V_25 ;
V_176 = ( ( ( unsigned long ) V_175 [ 0 ] << 16 ) |
( ( unsigned long ) V_175 [ 1 ] << 8 ) |
( unsigned long ) V_175 [ 2 ] ) ;
F_2 ( L_22 , V_176 ) ;
V_180 = F_117 ( & V_31 -> V_137 , V_176 ) ;
if ( ! V_180 ) {
if ( V_179 ) {
F_2 ( L_23 ) ;
V_53 -> V_136 = V_176 ;
V_25 = F_119 ( & V_31 -> V_137 , V_176 ,
V_179 , V_103 ) ;
if ( V_25 )
F_120 ( V_181 L_24 ,
( int ) V_176 ) ;
} else {
F_2 ( L_25 ) ;
}
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
return;
}
if ( V_53 -> V_68 ) {
if ( V_179 == NULL ) {
F_2 ( L_26 ) ;
F_79 ( & V_31 -> V_137 , V_176 ) ;
V_53 -> V_68 = NULL ;
return;
}
F_2 ( L_27 ) ;
F_121 ( & V_31 -> V_137 , V_176 , V_179 ) ;
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
return;
}
if ( V_179 == NULL ) {
F_2 ( L_28 ) ;
F_79 ( & V_31 -> V_137 , V_176 ) ;
return;
}
F_2 ( L_29 ) ;
F_121 ( & V_31 -> V_137 , V_176 , V_179 ) ;
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
F_2 ( L_30 ,
V_53 -> V_68 , V_179 , V_179 -> V_178 ) ;
}
static struct V_68 * F_122 (
T_7 * V_72 ,
const T_10 V_182 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
struct V_183 * V_184 ;
V_31 = V_72 -> V_160 . V_177 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_116 () ;
return NULL ;
}
F_2 ( L_31 , V_182 ) ;
V_184 = V_31 -> V_185 + V_182 ;
V_38 = V_184 -> V_38 ;
if ( ! V_38 ) {
F_2 ( L_32 ,
V_182 ) ;
return NULL ;
}
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
if ( ! V_53 -> V_68 ) {
F_30 ( L_21 ) ;
return NULL ;
}
return V_53 -> V_68 ;
}
static void F_123 (
struct V_30 * V_31 ,
struct V_37 * V_179 ,
struct V_52 * V_53 ,
struct V_67 * V_64 ,
struct V_68 * V_68 ,
T_10 V_182 )
{
struct V_37 * V_186 ;
struct V_183 * V_184 ;
F_2 ( L_33 , V_182 ) ;
V_184 = & ( (struct V_183 * )
V_31 -> V_185 ) [ V_182 ] ;
V_186 = V_184 -> V_38 ;
if ( ! V_186 ) {
F_2 ( L_34 ) ;
V_184 -> V_38 = V_179 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
return;
}
if ( V_53 -> V_68 ) {
if ( V_179 == NULL ) {
F_2 ( L_35 ) ;
V_184 -> V_38 = NULL ;
V_53 -> V_68 = NULL ;
return;
}
F_2 ( L_36 ) ;
V_184 -> V_38 = V_179 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
return;
}
if ( V_179 == NULL ) {
F_2 ( L_37 ) ;
V_184 -> V_38 = NULL ;
return;
}
F_2 ( L_38 ) ;
V_184 -> V_38 = V_179 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
F_2 ( L_39 ,
V_53 -> V_68 , V_179 , V_179 -> V_178 ) ;
}
static void F_81 ( struct V_30 * V_31 ,
struct V_52 * V_53 , struct V_68 * V_69 )
{
struct V_67 * V_64 = V_69 -> V_64 ;
unsigned char V_187 [ 3 ] ;
V_187 [ 0 ] = V_69 -> V_175 . V_14 . V_188 ;
V_187 [ 1 ] = V_69 -> V_175 . V_14 . V_189 ;
V_187 [ 2 ] = V_69 -> V_175 . V_14 . V_190 ;
F_118 ( V_31 , NULL , V_53 , V_64 ,
V_69 , V_187 ) ;
F_123 ( V_31 , NULL , V_53 , V_64 ,
V_69 , V_69 -> V_182 ) ;
}
static void F_124 ( struct V_68 * V_69 )
{
struct V_161 * V_191 = V_69 -> V_191 ;
struct V_128 * V_129 = V_191 -> V_129 ;
T_7 * V_72 = F_125 ( V_129 -> V_131 ) ;
struct V_67 * V_64 ;
struct V_37 * V_38 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
F_47 ( F_126 () ) ;
V_64 = V_69 -> V_64 ;
if ( ! V_64 ) {
F_30 ( L_40 ) ;
F_116 () ;
return;
}
V_38 = V_64 -> V_37 ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
V_31 = V_72 -> V_160 . V_177 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_116 () ;
return;
}
F_127 ( V_64 ) ;
F_128 ( V_69 -> V_64 ) ;
F_129 ( V_69 -> V_64 ) ;
}
static int F_130 (
T_7 * V_72 ,
unsigned char * V_192 ,
void * V_68 ,
T_9 * V_175 ,
T_10 V_182 )
{
struct V_128 * V_129 = V_72 -> V_74 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
struct V_26 * V_27 ;
struct V_37 * V_38 ;
struct V_67 * V_64 ;
struct V_68 * V_69 = V_68 ;
unsigned char V_193 [ 36 ] ;
unsigned long V_73 ;
V_31 = V_72 -> V_160 . V_177 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_116 () ;
return - V_20 ;
}
V_29 = V_31 -> V_172 ;
if ( ! V_29 ) {
F_30 ( L_41 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_64 = F_131 ( V_194 ) ;
if ( F_91 ( V_64 ) ) {
F_30 ( L_42 ) ;
return F_132 ( V_64 ) ;
}
memset ( & V_193 , 0 , 36 ) ;
snprintf ( V_193 , 36 , L_43 ,
V_192 [ 0 ] , V_192 [ 1 ] , V_192 [ 2 ] , V_192 [ 3 ] , V_192 [ 4 ] ,
V_192 [ 5 ] , V_192 [ 6 ] , V_192 [ 7 ] ) ;
V_64 -> V_37 = F_133 ( V_27 ,
V_193 ) ;
if ( ! V_64 -> V_37 ) {
F_134 ( V_64 ) ;
return - V_20 ;
}
V_38 = V_64 -> V_37 ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
F_48 ( & V_129 -> V_75 , V_73 ) ;
F_118 ( V_31 , V_38 , V_53 , V_64 ,
V_68 , V_175 ) ;
F_123 ( V_31 , V_38 , V_53 , V_64 ,
V_68 , V_182 ) ;
F_50 ( & V_129 -> V_75 , V_73 ) ;
F_135 ( V_38 -> V_27 , V_38 , V_64 , V_69 ) ;
return 0 ;
}
static void F_136 ( struct V_68 * V_69 , T_11 V_175 ,
T_10 V_182 , bool V_195 )
{
struct V_161 * V_191 = V_69 -> V_191 ;
struct V_128 * V_129 = V_191 -> V_129 ;
T_7 * V_72 = F_125 ( V_129 -> V_131 ) ;
struct V_30 * V_31 = V_72 -> V_160 . V_177 ;
struct V_37 * V_38 = V_69 -> V_64 -> V_37 ;
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
T_3 V_176 ;
if ( V_69 -> V_182 != V_182 || V_69 -> V_175 . V_196 != V_175 . V_196 )
F_137 ( L_44 ,
V_69 , V_69 -> V_193 ,
V_69 -> V_182 , V_182 , V_69 -> V_175 . V_14 . V_188 ,
V_69 -> V_175 . V_14 . V_189 , V_69 -> V_175 . V_14 . V_190 , V_175 . V_14 . V_188 ,
V_175 . V_14 . V_189 , V_175 . V_14 . V_190 ) ;
if ( V_69 -> V_182 != V_182 ) {
if ( V_31 -> V_185 [ V_69 -> V_182 ] . V_38 == V_38 )
V_31 -> V_185 [ V_69 -> V_182 ] . V_38 = NULL ;
V_31 -> V_185 [ V_182 ] . V_38 = V_38 ;
V_69 -> V_182 = V_182 ;
}
if ( V_69 -> V_175 . V_196 != V_175 . V_196 ) {
V_176 = ( ( ( T_3 ) V_69 -> V_175 . V_14 . V_188 << 16 ) |
( ( T_3 ) V_69 -> V_175 . V_14 . V_189 << 8 ) |
( ( T_3 ) V_69 -> V_175 . V_14 . V_190 ) ) ;
if ( F_117 ( & V_31 -> V_137 , V_176 ) )
F_138 ( F_79 ( & V_31 -> V_137 , V_176 ) != V_38 ,
L_45 ,
V_69 -> V_175 . V_14 . V_188 , V_69 -> V_175 . V_14 . V_189 , V_69 -> V_175 . V_14 . V_190 ) ;
else
F_138 ( 1 , L_46 ,
V_69 -> V_175 . V_14 . V_188 , V_69 -> V_175 . V_14 . V_189 , V_69 -> V_175 . V_14 . V_190 ) ;
V_176 = ( ( ( T_3 ) V_175 . V_14 . V_188 << 16 ) |
( ( T_3 ) V_175 . V_14 . V_189 << 8 ) |
( ( T_3 ) V_175 . V_14 . V_190 ) ) ;
if ( F_117 ( & V_31 -> V_137 , V_176 ) ) {
F_138 ( 1 , L_47 ,
V_175 . V_14 . V_188 , V_175 . V_14 . V_189 , V_175 . V_14 . V_190 ) ;
F_121 ( & V_31 -> V_137 , V_176 , V_38 ) ;
} else {
F_119 ( & V_31 -> V_137 , V_176 , V_38 , V_103 ) ;
}
V_69 -> V_175 = V_175 ;
V_53 -> V_136 = V_176 ;
}
V_69 -> V_195 = V_195 ;
}
static int F_139 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_140 ( & V_31 -> V_137 ) ;
if ( V_25 ) {
F_30 ( L_48 ) ;
return V_25 ;
}
V_31 -> V_185 = F_141 ( sizeof( struct V_183 ) *
65536 ) ;
if ( ! V_31 -> V_185 ) {
F_30 ( L_49 ,
sizeof( struct V_183 ) * 65536 ) ;
F_142 ( & V_31 -> V_137 ) ;
return - V_145 ;
}
memset ( V_31 -> V_185 , 0 , sizeof( struct V_183 )
* 65536 ) ;
F_2 ( L_50 ,
sizeof( struct V_183 ) * 65536 ) ;
return 0 ;
}
static int F_143 ( struct V_71 * V_72 ,
void * V_177 ,
T_2 V_197 , T_2 V_198 )
{
struct V_128 * V_129 = V_72 -> V_74 ;
struct V_30 * V_31 =
(struct V_30 * ) V_177 ;
V_129 -> V_191 . V_199 = & V_200 ;
V_72 -> V_160 . V_177 = V_177 ;
V_31 -> V_154 = V_72 ;
return 0 ;
}
static struct V_132 * F_144 (
struct V_201 * V_202 ,
struct V_141 * V_142 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_42 = - V_164 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_89 ( - V_20 ) ;
V_31 = F_29 ( sizeof( struct V_30 ) , V_54 ) ;
if ( ! V_31 ) {
F_30 ( L_51 ) ;
return F_89 ( - V_145 ) ;
}
V_31 -> V_203 = V_22 ;
F_3 ( & V_31 -> V_204 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_35 , L_52 , ( unsigned long long ) V_22 ) ;
V_42 = F_139 ( V_31 ) ;
if ( V_42 != 0 )
goto V_205;
V_42 = F_145 ( V_31 , V_22 , 0 , 0 ,
F_143 ) ;
if ( V_42 != 0 )
goto V_206;
return & V_31 -> V_134 ;
V_206:
F_146 ( V_31 -> V_185 ) ;
F_142 ( & V_31 -> V_137 ) ;
V_205:
F_32 ( V_31 ) ;
return F_89 ( V_42 ) ;
}
static void F_147 ( struct V_132 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_134 ) ;
struct V_71 * V_72 = V_31 -> V_154 ;
struct V_37 * V_135 ;
T_3 V_176 = 0 ;
if ( V_72 -> V_160 . V_161 && ! V_72 -> V_160 . V_161 -> V_207 )
F_148 ( V_72 -> V_160 . V_161 ) ;
F_149 ( V_72 ) ;
F_146 ( V_31 -> V_185 ) ;
F_150 (&lport->lport_fcport_map, key, node)
F_79 ( & V_31 -> V_137 , V_176 ) ;
F_142 ( & V_31 -> V_137 ) ;
F_32 ( V_31 ) ;
}
static int F_151 ( struct V_71 * V_153 ,
void * V_177 ,
T_2 V_197 , T_2 V_198 )
{
struct V_208 * V_209 ;
struct V_210 * V_211 = V_153 -> V_212 ;
struct V_71 * V_213 ;
struct V_30 * V_31 =
(struct V_30 * ) V_177 ;
struct V_30 * V_214 =
(struct V_30 * ) V_153 -> V_160 . V_177 ;
struct V_28 * V_151 ;
struct V_215 V_216 ;
if ( ! F_152 ( V_153 ) ) {
F_30 ( L_53 ) ;
return - V_165 ;
}
if ( ! V_214 || ! V_214 -> V_172 ||
! F_95 ( & V_214 -> V_172 -> V_150 ) ) {
F_30 ( L_54 ) ;
return - V_165 ;
}
V_151 = V_214 -> V_172 ;
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_216 . V_193 = V_197 ;
V_216 . V_217 = V_198 ;
V_216 . V_218 = V_219 ;
V_216 . V_220 = V_221 ;
V_216 . V_222 = false ;
V_209 = F_153 ( V_211 , 0 , & V_216 ) ;
if ( ! V_209 ) {
F_30 ( L_55 ) ;
return - V_164 ;
}
V_213 = (struct V_71 * ) V_209 -> V_223 ;
V_213 -> V_160 . V_177 = V_177 ;
V_31 -> V_154 = V_213 ;
F_154 ( V_213 -> V_212 ) ;
return 0 ;
}
static struct V_132 * F_155 (
struct V_201 * V_202 ,
struct V_141 * V_142 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_224 , V_197 , V_198 ;
char * V_225 , V_226 [ 128 ] ;
int V_42 ;
snprintf ( V_226 , 128 , L_56 , V_1 ) ;
V_225 = strchr ( V_226 , '@' ) ;
if ( ! V_225 ) {
F_30 ( L_57 ) ;
return F_89 ( - V_20 ) ;
}
* V_225 ++ = '\0' ;
if ( F_1 ( V_226 , & V_224 , 1 ) < 0 )
return F_89 ( - V_20 ) ;
if ( F_9 ( V_225 , strlen ( V_225 ) + 1 ,
& V_197 , & V_198 ) < 0 )
return F_89 ( - V_20 ) ;
V_31 = F_29 ( sizeof( struct V_30 ) , V_54 ) ;
if ( ! V_31 ) {
F_30 ( L_58 ) ;
return F_89 ( - V_145 ) ;
}
V_31 -> V_227 = V_197 ;
V_31 -> V_228 = V_198 ;
sprintf ( V_31 -> V_35 , L_52 , ( unsigned long long ) V_197 ) ;
V_42 = F_139 ( V_31 ) ;
if ( V_42 != 0 )
goto V_205;
V_42 = F_145 ( V_31 , V_224 , V_197 , V_198 ,
F_151 ) ;
if ( V_42 != 0 )
goto V_206;
return & V_31 -> V_134 ;
V_206:
F_146 ( V_31 -> V_185 ) ;
F_142 ( & V_31 -> V_137 ) ;
V_205:
F_32 ( V_31 ) ;
return F_89 ( V_42 ) ;
}
static void F_156 ( struct V_132 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_134 ) ;
struct V_71 * V_213 = V_31 -> V_154 ;
struct V_128 * V_129 = V_213 -> V_74 ;
T_7 * V_153 = F_125 ( V_129 -> V_131 ) ;
F_157 ( V_213 -> V_212 ) ;
F_158 ( V_213 -> V_208 ) ;
F_157 ( V_153 -> V_212 ) ;
F_32 ( V_31 ) ;
}
static T_1 F_159 (
struct V_201 * V_202 ,
char * V_148 )
{
return sprintf ( V_148 ,
L_59
V_229 L_60 , V_230 , F_160 () -> V_231 ,
F_160 () -> V_232 ) ;
}
static int F_161 ( void )
{
struct V_201 * V_233 , * V_234 ;
int V_42 ;
F_2 ( L_61
V_229 L_60 , V_230 , F_160 () -> V_231 ,
F_160 () -> V_232 ) ;
V_233 = F_162 ( V_235 , L_3 ) ;
if ( F_91 ( V_233 ) ) {
F_30 ( L_62 ) ;
return F_132 ( V_233 ) ;
}
V_233 -> V_170 = V_236 ;
V_233 -> V_237 . V_238 . V_239 = V_240 ;
V_233 -> V_237 . V_241 . V_239 = V_242 ;
V_233 -> V_237 . V_243 . V_239 =
V_244 ;
V_233 -> V_237 . V_245 . V_239 = NULL ;
V_233 -> V_237 . V_246 . V_239 = NULL ;
V_233 -> V_237 . V_247 . V_239 = NULL ;
V_233 -> V_237 . V_248 . V_239 = NULL ;
V_233 -> V_237 . V_249 . V_239 = NULL ;
V_233 -> V_237 . V_250 . V_239 = NULL ;
V_42 = F_163 ( V_233 ) ;
if ( V_42 < 0 ) {
F_30 ( L_63 ) ;
return V_42 ;
}
V_169 = V_233 ;
F_2 ( L_64 ) ;
V_234 = F_162 ( V_235 , L_4 ) ;
if ( F_91 ( V_234 ) ) {
F_30 ( L_62 ) ;
V_42 = F_132 ( V_234 ) ;
goto V_251;
}
V_234 -> V_170 = V_252 ;
V_234 -> V_237 . V_238 . V_239 = V_240 ;
V_234 -> V_237 . V_241 . V_239 =
V_253 ;
V_234 -> V_237 . V_243 . V_239 = NULL ;
V_234 -> V_237 . V_245 . V_239 = NULL ;
V_234 -> V_237 . V_246 . V_239 = NULL ;
V_234 -> V_237 . V_247 . V_239 = NULL ;
V_234 -> V_237 . V_248 . V_239 = NULL ;
V_234 -> V_237 . V_249 . V_239 = NULL ;
V_234 -> V_237 . V_250 . V_239 = NULL ;
V_42 = F_163 ( V_234 ) ;
if ( V_42 < 0 ) {
F_30 ( L_63 ) ;
goto V_251;
}
V_174 = V_234 ;
F_2 ( L_65 ) ;
V_61 = F_164 ( L_66 ,
V_254 , 0 ) ;
if ( ! V_61 ) {
V_42 = - V_145 ;
goto V_255;
}
V_256 = F_164 ( L_67 , 0 , 0 ) ;
if ( ! V_256 ) {
V_42 = - V_145 ;
goto V_257;
}
return 0 ;
V_257:
F_165 ( V_61 ) ;
V_255:
F_166 ( V_174 ) ;
V_251:
F_166 ( V_169 ) ;
return V_42 ;
}
static void F_167 ( void )
{
F_165 ( V_256 ) ;
F_165 ( V_61 ) ;
F_166 ( V_169 ) ;
V_169 = NULL ;
F_2 ( L_68 ) ;
F_166 ( V_174 ) ;
V_174 = NULL ;
F_2 ( L_69 ) ;
}
static int T_12 F_168 ( void )
{
int V_42 ;
V_42 = F_161 () ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static void T_13 F_169 ( void )
{
F_167 () ;
}
