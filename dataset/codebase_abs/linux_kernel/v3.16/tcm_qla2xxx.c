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
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_85 = V_60 -> V_86 ;
V_63 -> V_87 = V_60 -> V_88 -> V_89 . V_90 ;
V_60 -> V_91 = 0 ;
return F_56 ( V_63 ) ;
}
static int F_57 ( struct V_60 * V_60 )
{
unsigned long V_73 ;
F_48 ( & V_60 -> V_92 , V_73 ) ;
if ( V_60 -> V_93 == V_94 ||
V_60 -> V_93 == V_95 ) {
F_50 ( & V_60 -> V_92 , V_73 ) ;
F_58 ( & V_60 -> V_96 ,
3000 ) ;
return 0 ;
}
F_50 ( & V_60 -> V_92 , V_73 ) ;
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
return V_63 -> V_97 ;
}
static int F_61 ( struct V_60 * V_60 )
{
return 0 ;
}
static int F_62 ( T_7 * V_72 , struct V_62 * V_63 ,
unsigned char * V_98 , T_8 V_77 , int V_99 ,
int V_100 , int V_101 )
{
struct V_60 * V_60 = & V_63 -> V_60 ;
struct V_67 * V_64 ;
struct V_68 * V_69 ;
int V_73 = V_102 ;
if ( V_101 )
V_73 |= V_103 ;
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
return F_63 ( V_60 , V_64 , V_98 , & V_63 -> V_104 [ 0 ] ,
V_63 -> V_105 , V_77 , V_99 ,
V_100 , V_73 ) ;
}
static void F_64 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_12 ( V_56 , struct V_62 , V_56 ) ;
if ( ! V_63 -> V_106 ) {
if ( V_63 -> V_60 . V_107 & V_108 ) {
F_65 ( & V_63 -> V_60 . V_96 ) ;
return;
}
if ( V_63 -> V_60 . V_91 )
F_66 ( & V_63 -> V_60 ,
V_63 -> V_60 . V_91 ) ;
else
F_66 ( & V_63 -> V_60 ,
V_109 ) ;
return;
}
return F_67 ( & V_63 -> V_60 ) ;
}
static void F_68 ( struct V_62 * V_63 )
{
F_37 ( & V_63 -> V_56 , F_64 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static void F_69 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_12 ( V_56 , struct V_62 , V_56 ) ;
F_70 ( & V_63 -> V_60 . V_110 ) ;
F_66 ( & V_63 -> V_60 , V_63 -> V_60 . V_91 ) ;
}
static void F_71 ( struct V_62 * V_63 )
{
F_37 ( & V_63 -> V_56 , F_69 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_72 ( struct V_57 * V_58 , T_8 V_111 ,
T_9 V_112 , T_8 V_97 )
{
struct V_68 * V_69 = V_58 -> V_69 ;
struct V_60 * V_60 = & V_58 -> V_60 ;
return F_73 ( V_60 , V_69 -> V_64 , NULL , V_111 , V_58 ,
V_112 , V_113 , V_97 , V_102 ) ;
}
static int F_74 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_76 = V_60 -> V_77 ;
V_63 -> V_78 = F_55 ( V_60 ) ;
V_63 -> V_114 = ( V_60 -> V_107 & V_108 ) ;
V_63 -> V_79 = V_60 -> V_80 ;
V_63 -> V_81 = V_60 -> V_82 ;
V_63 -> V_115 = 0 ;
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_85 = V_60 -> V_86 ;
V_63 -> V_87 = V_60 -> V_88 -> V_89 . V_90 ;
V_60 -> V_91 = 0 ;
return F_75 ( V_63 , V_116 | V_117 ,
V_60 -> V_118 ) ;
}
static int F_76 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
int V_119 = V_117 ;
V_63 -> V_76 = V_60 -> V_77 ;
V_63 -> V_81 = NULL ;
V_63 -> V_79 = 0 ;
V_63 -> V_115 = 0 ;
V_63 -> V_78 = F_55 ( V_60 ) ;
V_63 -> V_114 = ( V_60 -> V_107 & V_108 ) ;
if ( V_60 -> V_120 == V_121 ) {
if ( V_60 -> V_65 & V_122 ) {
V_60 -> V_65 &= ~ V_122 ;
V_60 -> V_123 = 0 ;
}
V_60 -> V_65 |= V_124 ;
V_60 -> V_123 += V_60 -> V_77 ;
V_63 -> V_76 = 0 ;
}
return F_75 ( V_63 , V_119 , V_60 -> V_118 ) ;
}
static void F_77 ( struct V_60 * V_60 )
{
struct V_125 * V_126 = V_60 -> V_125 ;
struct V_57 * V_58 = F_12 ( V_60 ,
struct V_57 , V_60 ) ;
F_2 ( L_8 ,
V_58 , V_126 -> V_127 , V_126 -> V_128 ) ;
switch ( V_126 -> V_128 ) {
case V_129 :
V_58 -> V_130 = V_131 ;
break;
case V_132 :
V_58 -> V_130 = V_133 ;
break;
case V_134 :
V_58 -> V_130 = V_135 ;
break;
case V_136 :
default:
V_58 -> V_130 = V_137 ;
break;
}
F_78 ( V_58 ) ;
}
static void F_79 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
struct V_71 * V_72 = V_63 -> V_72 ;
struct V_138 * V_139 = V_72 -> V_74 ;
if ( ! V_63 -> V_140 )
return;
F_80 ( V_139 -> V_141 , V_63 -> V_81 , V_63 -> V_79 , V_63 -> V_78 ) ;
V_63 -> V_140 = 0 ;
}
static void F_81 ( struct V_68 * V_69 )
{
struct V_37 * V_38 = V_69 -> V_64 -> V_37 ;
struct V_26 * V_27 = V_38 -> V_27 ;
struct V_142 * V_142 = V_27 -> V_143 ;
struct V_30 * V_31 = F_12 ( V_142 ,
struct V_30 , V_144 ) ;
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
void * V_145 ;
F_2 ( L_9 , V_53 -> V_146 ) ;
V_145 = F_82 ( & V_31 -> V_147 , V_53 -> V_146 ) ;
F_83 ( V_145 && ( V_145 != V_38 ) ) ;
F_2 ( L_10 ,
V_38 , V_53 -> V_148 , V_53 -> V_146 ) ;
F_84 ( V_31 , V_53 , V_69 ) ;
}
static void F_85 ( struct V_149 * V_149 )
{
struct V_67 * V_64 = F_12 ( V_149 ,
struct V_67 , V_150 ) ;
F_52 ( V_64 -> V_70 ) ;
}
static void F_86 ( struct V_67 * V_64 )
{
struct V_68 * V_69 = V_64 -> V_70 ;
struct V_138 * V_139 = V_69 -> V_72 -> V_74 ;
unsigned long V_73 ;
F_48 ( & V_139 -> V_75 , V_73 ) ;
F_87 ( & V_64 -> V_150 , F_85 ) ;
F_50 ( & V_139 -> V_75 , V_73 ) ;
}
static void F_88 ( struct V_68 * V_69 )
{
if ( ! V_69 )
return;
F_89 ( & V_69 -> V_72 -> V_74 -> V_75 ) ;
F_87 ( & V_69 -> V_64 -> V_150 , F_85 ) ;
}
static void F_90 ( struct V_68 * V_69 )
{
F_89 ( & V_69 -> V_72 -> V_74 -> V_75 ) ;
F_49 ( V_69 -> V_64 ) ;
}
static struct V_37 * F_91 (
struct V_26 * V_27 ,
struct V_151 * V_152 ,
const char * V_1 )
{
struct V_37 * V_38 , * V_153 ;
struct V_52 * V_53 ;
T_2 V_23 ;
T_3 V_154 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return F_92 ( - V_20 ) ;
V_153 = F_28 ( V_27 ) ;
if ( ! V_153 )
return F_92 ( - V_155 ) ;
V_154 = 1 ;
V_38 = F_93 ( V_27 , V_153 ,
V_1 , V_154 ) ;
if ( F_94 ( V_38 ) ) {
F_31 ( V_27 , V_153 ) ;
return V_38 ;
}
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
V_53 -> V_148 = V_23 ;
F_3 ( & V_53 -> V_156 [ 0 ] , V_10 , V_23 ) ;
return V_38 ;
}
static void F_95 ( struct V_37 * V_157 )
{
struct V_26 * V_27 = V_157 -> V_27 ;
struct V_52 * V_53 = F_12 ( V_157 ,
struct V_52 , V_37 ) ;
F_96 ( V_27 , V_157 , 1 ) ;
F_32 ( V_53 ) ;
}
static T_1 F_97 (
struct V_26 * V_27 ,
char * V_158 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_158 , V_159 , L_11 ,
F_98 ( & V_29 -> V_160 ) ) ;
}
static void F_99 ( struct V_55 * V_56 )
{
struct V_28 * V_161 = F_12 ( V_56 ,
struct V_28 , V_162 ) ;
struct V_26 * V_27 = & V_161 -> V_27 ;
struct V_71 * V_163 = V_161 -> V_31 -> V_164 ;
if ( ! F_100 ( V_27 -> V_165 -> V_166 ,
& V_27 -> V_167 . V_168 ) ) {
F_101 ( & V_161 -> V_160 , 1 ) ;
F_102 ( V_163 ) ;
}
F_65 ( & V_161 -> V_169 ) ;
}
static void F_103 ( struct V_55 * V_56 )
{
struct V_28 * V_161 = F_12 ( V_56 ,
struct V_28 , V_162 ) ;
struct V_26 * V_27 = & V_161 -> V_27 ;
struct V_71 * V_163 = V_161 -> V_31 -> V_164 ;
if ( ! F_104 ( V_163 -> V_170 . V_171 ) ) {
F_101 ( & V_161 -> V_160 , 0 ) ;
F_105 ( V_27 -> V_165 -> V_166 ,
& V_27 -> V_167 . V_168 ) ;
}
F_65 ( & V_161 -> V_169 ) ;
}
static T_1 F_106 (
struct V_26 * V_27 ,
const char * V_158 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_172 ;
int V_25 ;
V_25 = F_107 ( V_158 , 0 , & V_172 ) ;
if ( V_25 < 0 ) {
F_30 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_172 != 1 ) && ( V_172 != 0 ) ) {
F_30 ( L_13 , V_172 ) ;
return - V_20 ;
}
if ( V_172 ) {
if ( F_98 ( & V_29 -> V_160 ) )
return - V_173 ;
F_37 ( & V_29 -> V_162 , F_99 ) ;
} else {
if ( ! F_98 ( & V_29 -> V_160 ) )
return V_21 ;
F_37 ( & V_29 -> V_162 , F_103 ) ;
}
F_108 ( & V_29 -> V_169 ) ;
F_109 ( & V_29 -> V_162 ) ;
F_110 ( & V_29 -> V_169 ) ;
if ( V_172 ) {
if ( ! F_98 ( & V_29 -> V_160 ) )
return - V_174 ;
} else {
if ( F_98 ( & V_29 -> V_160 ) )
return - V_175 ;
}
return V_21 ;
}
static struct V_26 * F_111 (
struct V_142 * V_2 ,
struct V_151 * V_152 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_144 ) ;
struct V_28 * V_29 ;
unsigned long V_176 ;
int V_42 ;
if ( strstr ( V_1 , L_14 ) != V_1 )
return F_92 ( - V_20 ) ;
if ( F_107 ( V_1 + 5 , 10 , & V_176 ) || V_176 > V_177 )
return F_92 ( - V_20 ) ;
if ( ( V_176 != 1 ) ) {
F_30 ( L_15 ) ;
return F_92 ( - V_178 ) ;
}
V_29 = F_29 ( sizeof( struct V_28 ) , V_54 ) ;
if ( ! V_29 ) {
F_30 ( L_16 ) ;
return F_92 ( - V_155 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_176 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_112 ( & V_179 -> V_180 , V_2 ,
& V_29 -> V_27 , V_29 , V_181 ) ;
if ( V_42 < 0 ) {
F_32 ( V_29 ) ;
return NULL ;
}
V_31 -> V_182 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_113 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_71 * V_72 = V_31 -> V_164 ;
if ( V_72 -> V_170 . V_171 && ! V_72 -> V_170 . V_171 -> V_183 )
F_104 ( V_72 -> V_170 . V_171 ) ;
F_114 ( V_27 ) ;
V_31 -> V_182 = NULL ;
F_32 ( V_29 ) ;
}
static T_1 F_115 (
struct V_26 * V_27 ,
char * V_158 )
{
return F_97 ( V_27 , V_158 ) ;
}
static T_1 F_116 (
struct V_26 * V_27 ,
const char * V_158 ,
T_4 V_21 )
{
struct V_142 * V_142 = V_27 -> V_143 ;
struct V_30 * V_31 = F_12 ( V_142 ,
struct V_30 , V_144 ) ;
struct V_71 * V_72 = V_31 -> V_164 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_172 ;
int V_25 ;
V_25 = F_107 ( V_158 , 0 , & V_172 ) ;
if ( V_25 < 0 ) {
F_30 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_172 != 1 ) && ( V_172 != 0 ) ) {
F_30 ( L_13 , V_172 ) ;
return - V_20 ;
}
if ( V_172 ) {
if ( F_98 ( & V_29 -> V_160 ) )
return - V_173 ;
F_101 ( & V_29 -> V_160 , 1 ) ;
F_102 ( V_72 ) ;
} else {
if ( ! F_98 ( & V_29 -> V_160 ) )
return V_21 ;
F_101 ( & V_29 -> V_160 , 0 ) ;
F_104 ( V_72 -> V_170 . V_171 ) ;
}
return V_21 ;
}
static struct V_26 * F_117 (
struct V_142 * V_2 ,
struct V_151 * V_152 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_144 ) ;
struct V_28 * V_29 ;
unsigned long V_176 ;
int V_42 ;
if ( strstr ( V_1 , L_14 ) != V_1 )
return F_92 ( - V_20 ) ;
if ( F_107 ( V_1 + 5 , 10 , & V_176 ) || V_176 > V_177 )
return F_92 ( - V_20 ) ;
V_29 = F_29 ( sizeof( struct V_28 ) , V_54 ) ;
if ( ! V_29 ) {
F_30 ( L_16 ) ;
return F_92 ( - V_155 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_176 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_112 ( & V_184 -> V_180 , V_2 ,
& V_29 -> V_27 , V_29 , V_181 ) ;
if ( V_42 < 0 ) {
F_32 ( V_29 ) ;
return NULL ;
}
V_31 -> V_182 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_68 * F_118 (
T_7 * V_72 ,
const T_9 * V_185 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
T_3 V_186 ;
V_31 = V_72 -> V_170 . V_187 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_119 () ;
return NULL ;
}
V_186 = ( ( ( unsigned long ) V_185 [ 0 ] << 16 ) |
( ( unsigned long ) V_185 [ 1 ] << 8 ) |
( unsigned long ) V_185 [ 2 ] ) ;
F_2 ( L_18 , V_186 ) ;
V_38 = F_120 ( & V_31 -> V_147 , V_186 ) ;
if ( ! V_38 ) {
F_2 ( L_19 , V_186 ) ;
return NULL ;
}
F_2 ( L_20 ,
V_38 , V_38 -> V_188 ) ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
if ( ! V_53 -> V_68 ) {
F_30 ( L_21 ) ;
return NULL ;
}
return V_53 -> V_68 ;
}
static void F_121 (
struct V_30 * V_31 ,
struct V_37 * V_189 ,
struct V_52 * V_53 ,
struct V_67 * V_64 ,
struct V_68 * V_68 ,
T_9 * V_185 )
{
T_3 V_186 ;
void * V_190 ;
int V_25 ;
V_186 = ( ( ( unsigned long ) V_185 [ 0 ] << 16 ) |
( ( unsigned long ) V_185 [ 1 ] << 8 ) |
( unsigned long ) V_185 [ 2 ] ) ;
F_2 ( L_22 , V_186 ) ;
V_190 = F_120 ( & V_31 -> V_147 , V_186 ) ;
if ( ! V_190 ) {
if ( V_189 ) {
F_2 ( L_23 ) ;
V_53 -> V_146 = V_186 ;
V_25 = F_122 ( & V_31 -> V_147 , V_186 ,
V_189 , V_113 ) ;
if ( V_25 )
F_123 ( V_191 L_24 ,
( int ) V_186 ) ;
} else {
F_2 ( L_25 ) ;
}
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
return;
}
if ( V_53 -> V_68 ) {
if ( V_189 == NULL ) {
F_2 ( L_26 ) ;
F_82 ( & V_31 -> V_147 , V_186 ) ;
V_53 -> V_68 = NULL ;
return;
}
F_2 ( L_27 ) ;
F_124 ( & V_31 -> V_147 , V_186 , V_189 ) ;
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
return;
}
if ( V_189 == NULL ) {
F_2 ( L_28 ) ;
F_82 ( & V_31 -> V_147 , V_186 ) ;
return;
}
F_2 ( L_29 ) ;
F_124 ( & V_31 -> V_147 , V_186 , V_189 ) ;
V_68 -> V_64 = V_64 ;
V_53 -> V_68 = V_68 ;
F_2 ( L_30 ,
V_53 -> V_68 , V_189 , V_189 -> V_188 ) ;
}
static struct V_68 * F_125 (
T_7 * V_72 ,
const T_10 V_192 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
struct V_193 * V_194 ;
V_31 = V_72 -> V_170 . V_187 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_119 () ;
return NULL ;
}
F_2 ( L_31 , V_192 ) ;
V_194 = V_31 -> V_195 + V_192 ;
V_38 = V_194 -> V_38 ;
if ( ! V_38 ) {
F_2 ( L_32 ,
V_192 ) ;
return NULL ;
}
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
if ( ! V_53 -> V_68 ) {
F_30 ( L_21 ) ;
return NULL ;
}
return V_53 -> V_68 ;
}
static void F_126 (
struct V_30 * V_31 ,
struct V_37 * V_189 ,
struct V_52 * V_53 ,
struct V_67 * V_64 ,
struct V_68 * V_68 ,
T_10 V_192 )
{
struct V_37 * V_196 ;
struct V_193 * V_194 ;
F_2 ( L_33 , V_192 ) ;
V_194 = & ( (struct V_193 * )
V_31 -> V_195 ) [ V_192 ] ;
V_196 = V_194 -> V_38 ;
if ( ! V_196 ) {
F_2 ( L_34 ) ;
V_194 -> V_38 = V_189 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
return;
}
if ( V_53 -> V_68 ) {
if ( V_189 == NULL ) {
F_2 ( L_35 ) ;
V_194 -> V_38 = NULL ;
V_53 -> V_68 = NULL ;
return;
}
F_2 ( L_36 ) ;
V_194 -> V_38 = V_189 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
return;
}
if ( V_189 == NULL ) {
F_2 ( L_37 ) ;
V_194 -> V_38 = NULL ;
return;
}
F_2 ( L_38 ) ;
V_194 -> V_38 = V_189 ;
if ( V_68 -> V_64 != V_64 )
V_68 -> V_64 = V_64 ;
if ( V_53 -> V_68 != V_68 )
V_53 -> V_68 = V_68 ;
F_2 ( L_39 ,
V_53 -> V_68 , V_189 , V_189 -> V_188 ) ;
}
static void F_84 ( struct V_30 * V_31 ,
struct V_52 * V_53 , struct V_68 * V_69 )
{
struct V_67 * V_64 = V_69 -> V_64 ;
unsigned char V_197 [ 3 ] ;
V_197 [ 0 ] = V_69 -> V_185 . V_14 . V_198 ;
V_197 [ 1 ] = V_69 -> V_185 . V_14 . V_199 ;
V_197 [ 2 ] = V_69 -> V_185 . V_14 . V_200 ;
F_121 ( V_31 , NULL , V_53 , V_64 ,
V_69 , V_197 ) ;
F_126 ( V_31 , NULL , V_53 , V_64 ,
V_69 , V_69 -> V_192 ) ;
}
static void F_127 ( struct V_68 * V_69 )
{
struct V_171 * V_201 = V_69 -> V_201 ;
struct V_138 * V_139 = V_201 -> V_139 ;
T_7 * V_72 = F_128 ( V_139 -> V_141 ) ;
struct V_67 * V_64 ;
struct V_37 * V_38 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
F_47 ( F_129 () ) ;
V_64 = V_69 -> V_64 ;
if ( ! V_64 ) {
F_30 ( L_40 ) ;
F_119 () ;
return;
}
V_38 = V_64 -> V_37 ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
V_31 = V_72 -> V_170 . V_187 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_119 () ;
return;
}
F_130 ( V_64 ) ;
F_131 ( V_69 -> V_64 ) ;
F_132 ( V_69 -> V_64 ) ;
}
static int F_133 (
T_7 * V_72 ,
unsigned char * V_202 ,
void * V_68 ,
T_9 * V_185 ,
T_10 V_192 )
{
struct V_138 * V_139 = V_72 -> V_74 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
struct V_26 * V_27 ;
struct V_37 * V_38 ;
struct V_67 * V_64 ;
struct V_68 * V_69 = V_68 ;
unsigned char V_203 [ 36 ] ;
unsigned long V_73 ;
int V_204 = ( V_139 -> V_205 ) ? V_139 -> V_205 :
V_206 ;
V_31 = V_72 -> V_170 . V_187 ;
if ( ! V_31 ) {
F_30 ( L_17 ) ;
F_119 () ;
return - V_20 ;
}
V_29 = V_31 -> V_182 ;
if ( ! V_29 ) {
F_30 ( L_41 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_64 = F_134 ( V_204 ,
sizeof( struct V_62 ) ,
V_207 ) ;
if ( F_94 ( V_64 ) ) {
F_30 ( L_42 ) ;
return F_135 ( V_64 ) ;
}
memset ( & V_203 , 0 , 36 ) ;
snprintf ( V_203 , 36 , L_43 ,
V_202 [ 0 ] , V_202 [ 1 ] , V_202 [ 2 ] , V_202 [ 3 ] , V_202 [ 4 ] ,
V_202 [ 5 ] , V_202 [ 6 ] , V_202 [ 7 ] ) ;
V_64 -> V_37 = F_136 ( V_27 ,
V_203 ) ;
if ( ! V_64 -> V_37 ) {
F_137 ( V_64 ) ;
return - V_20 ;
}
V_38 = V_64 -> V_37 ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
F_48 ( & V_139 -> V_75 , V_73 ) ;
F_121 ( V_31 , V_38 , V_53 , V_64 ,
V_68 , V_185 ) ;
F_126 ( V_31 , V_38 , V_53 , V_64 ,
V_68 , V_192 ) ;
F_50 ( & V_139 -> V_75 , V_73 ) ;
F_138 ( V_38 -> V_27 , V_38 , V_64 , V_69 ) ;
return 0 ;
}
static void F_139 ( struct V_68 * V_69 , T_11 V_185 ,
T_10 V_192 , bool V_208 )
{
struct V_171 * V_201 = V_69 -> V_201 ;
struct V_138 * V_139 = V_201 -> V_139 ;
T_7 * V_72 = F_128 ( V_139 -> V_141 ) ;
struct V_30 * V_31 = V_72 -> V_170 . V_187 ;
struct V_37 * V_38 = V_69 -> V_64 -> V_37 ;
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
T_3 V_186 ;
if ( V_69 -> V_192 != V_192 || V_69 -> V_185 . V_209 != V_185 . V_209 )
F_140 ( L_44 ,
V_69 , V_69 -> V_203 ,
V_69 -> V_192 , V_192 , V_69 -> V_185 . V_14 . V_198 ,
V_69 -> V_185 . V_14 . V_199 , V_69 -> V_185 . V_14 . V_200 , V_185 . V_14 . V_198 ,
V_185 . V_14 . V_199 , V_185 . V_14 . V_200 ) ;
if ( V_69 -> V_192 != V_192 ) {
if ( V_31 -> V_195 [ V_69 -> V_192 ] . V_38 == V_38 )
V_31 -> V_195 [ V_69 -> V_192 ] . V_38 = NULL ;
V_31 -> V_195 [ V_192 ] . V_38 = V_38 ;
V_69 -> V_192 = V_192 ;
}
if ( V_69 -> V_185 . V_209 != V_185 . V_209 ) {
V_186 = ( ( ( T_3 ) V_69 -> V_185 . V_14 . V_198 << 16 ) |
( ( T_3 ) V_69 -> V_185 . V_14 . V_199 << 8 ) |
( ( T_3 ) V_69 -> V_185 . V_14 . V_200 ) ) ;
if ( F_120 ( & V_31 -> V_147 , V_186 ) )
F_141 ( F_82 ( & V_31 -> V_147 , V_186 ) != V_38 ,
L_45 ,
V_69 -> V_185 . V_14 . V_198 , V_69 -> V_185 . V_14 . V_199 , V_69 -> V_185 . V_14 . V_200 ) ;
else
F_141 ( 1 , L_46 ,
V_69 -> V_185 . V_14 . V_198 , V_69 -> V_185 . V_14 . V_199 , V_69 -> V_185 . V_14 . V_200 ) ;
V_186 = ( ( ( T_3 ) V_185 . V_14 . V_198 << 16 ) |
( ( T_3 ) V_185 . V_14 . V_199 << 8 ) |
( ( T_3 ) V_185 . V_14 . V_200 ) ) ;
if ( F_120 ( & V_31 -> V_147 , V_186 ) ) {
F_141 ( 1 , L_47 ,
V_185 . V_14 . V_198 , V_185 . V_14 . V_199 , V_185 . V_14 . V_200 ) ;
F_124 ( & V_31 -> V_147 , V_186 , V_38 ) ;
} else {
F_122 ( & V_31 -> V_147 , V_186 , V_38 , V_113 ) ;
}
V_69 -> V_185 = V_185 ;
V_53 -> V_146 = V_186 ;
}
V_69 -> V_208 = V_208 ;
}
static int F_142 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_143 ( & V_31 -> V_147 ) ;
if ( V_25 ) {
F_30 ( L_48 ) ;
return V_25 ;
}
V_31 -> V_195 = F_144 ( sizeof( struct V_193 ) *
65536 ) ;
if ( ! V_31 -> V_195 ) {
F_30 ( L_49 ,
sizeof( struct V_193 ) * 65536 ) ;
F_145 ( & V_31 -> V_147 ) ;
return - V_155 ;
}
memset ( V_31 -> V_195 , 0 , sizeof( struct V_193 )
* 65536 ) ;
F_2 ( L_50 ,
sizeof( struct V_193 ) * 65536 ) ;
return 0 ;
}
static int F_146 ( struct V_71 * V_72 ,
void * V_187 ,
T_2 V_210 , T_2 V_211 )
{
struct V_138 * V_139 = V_72 -> V_74 ;
struct V_30 * V_31 =
(struct V_30 * ) V_187 ;
V_139 -> V_201 . V_212 = & V_213 ;
V_72 -> V_170 . V_187 = V_187 ;
V_31 -> V_164 = V_72 ;
return 0 ;
}
static struct V_142 * F_147 (
struct V_214 * V_215 ,
struct V_151 * V_152 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_42 = - V_174 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_92 ( - V_20 ) ;
V_31 = F_29 ( sizeof( struct V_30 ) , V_54 ) ;
if ( ! V_31 ) {
F_30 ( L_51 ) ;
return F_92 ( - V_155 ) ;
}
V_31 -> V_216 = V_22 ;
F_3 ( & V_31 -> V_217 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_35 , L_52 , ( unsigned long long ) V_22 ) ;
V_42 = F_142 ( V_31 ) ;
if ( V_42 != 0 )
goto V_218;
V_42 = F_148 ( V_31 , V_22 , 0 , 0 ,
F_146 ) ;
if ( V_42 != 0 )
goto V_219;
return & V_31 -> V_144 ;
V_219:
F_149 ( V_31 -> V_195 ) ;
F_145 ( & V_31 -> V_147 ) ;
V_218:
F_32 ( V_31 ) ;
return F_92 ( V_42 ) ;
}
static void F_150 ( struct V_142 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_144 ) ;
struct V_71 * V_72 = V_31 -> V_164 ;
struct V_37 * V_145 ;
T_3 V_186 = 0 ;
if ( V_72 -> V_170 . V_171 && ! V_72 -> V_170 . V_171 -> V_220 )
F_151 ( V_72 -> V_170 . V_171 ) ;
F_152 ( V_72 ) ;
F_149 ( V_31 -> V_195 ) ;
F_153 (&lport->lport_fcport_map, key, node)
F_82 ( & V_31 -> V_147 , V_186 ) ;
F_145 ( & V_31 -> V_147 ) ;
F_32 ( V_31 ) ;
}
static int F_154 ( struct V_71 * V_163 ,
void * V_187 ,
T_2 V_210 , T_2 V_211 )
{
struct V_221 * V_222 ;
struct V_223 * V_224 = V_163 -> V_225 ;
struct V_71 * V_226 ;
struct V_30 * V_31 =
(struct V_30 * ) V_187 ;
struct V_30 * V_227 =
(struct V_30 * ) V_163 -> V_170 . V_187 ;
struct V_28 * V_161 ;
struct V_228 V_229 ;
if ( ! F_155 ( V_163 ) ) {
F_30 ( L_53 ) ;
return - V_175 ;
}
if ( ! V_227 || ! V_227 -> V_182 ||
! F_98 ( & V_227 -> V_182 -> V_160 ) ) {
F_30 ( L_54 ) ;
return - V_175 ;
}
V_161 = V_227 -> V_182 ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
V_229 . V_203 = V_210 ;
V_229 . V_230 = V_211 ;
V_229 . V_231 = V_232 ;
V_229 . V_233 = V_234 ;
V_229 . V_235 = false ;
V_222 = F_156 ( V_224 , 0 , & V_229 ) ;
if ( ! V_222 ) {
F_30 ( L_55 ) ;
return - V_174 ;
}
V_226 = (struct V_71 * ) V_222 -> V_236 ;
V_226 -> V_170 . V_187 = V_187 ;
V_31 -> V_164 = V_226 ;
F_157 ( V_226 -> V_225 ) ;
return 0 ;
}
static struct V_142 * F_158 (
struct V_214 * V_215 ,
struct V_151 * V_152 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_237 , V_210 , V_211 ;
char * V_238 , V_239 [ 128 ] ;
int V_42 ;
snprintf ( V_239 , 128 , L_56 , V_1 ) ;
V_238 = strchr ( V_239 , '@' ) ;
if ( ! V_238 ) {
F_30 ( L_57 ) ;
return F_92 ( - V_20 ) ;
}
* V_238 ++ = '\0' ;
if ( F_1 ( V_239 , & V_237 , 1 ) < 0 )
return F_92 ( - V_20 ) ;
if ( F_9 ( V_238 , strlen ( V_238 ) + 1 ,
& V_210 , & V_211 ) < 0 )
return F_92 ( - V_20 ) ;
V_31 = F_29 ( sizeof( struct V_30 ) , V_54 ) ;
if ( ! V_31 ) {
F_30 ( L_58 ) ;
return F_92 ( - V_155 ) ;
}
V_31 -> V_240 = V_210 ;
V_31 -> V_241 = V_211 ;
sprintf ( V_31 -> V_35 , L_52 , ( unsigned long long ) V_210 ) ;
V_42 = F_142 ( V_31 ) ;
if ( V_42 != 0 )
goto V_218;
V_42 = F_148 ( V_31 , V_237 , V_210 , V_211 ,
F_154 ) ;
if ( V_42 != 0 )
goto V_219;
return & V_31 -> V_144 ;
V_219:
F_149 ( V_31 -> V_195 ) ;
F_145 ( & V_31 -> V_147 ) ;
V_218:
F_32 ( V_31 ) ;
return F_92 ( V_42 ) ;
}
static void F_159 ( struct V_142 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_144 ) ;
struct V_71 * V_226 = V_31 -> V_164 ;
struct V_138 * V_139 = V_226 -> V_74 ;
T_7 * V_163 = F_128 ( V_139 -> V_141 ) ;
F_160 ( V_226 -> V_225 ) ;
F_161 ( V_226 -> V_221 ) ;
F_160 ( V_163 -> V_225 ) ;
F_32 ( V_31 ) ;
}
static T_1 F_162 (
struct V_214 * V_215 ,
char * V_158 )
{
return sprintf ( V_158 ,
L_59
V_242 L_60 , V_243 , F_163 () -> V_244 ,
F_163 () -> V_245 ) ;
}
static int F_164 ( void )
{
struct V_214 * V_246 , * V_247 ;
int V_42 ;
F_2 ( L_61
V_242 L_60 , V_243 , F_163 () -> V_244 ,
F_163 () -> V_245 ) ;
V_246 = F_165 ( V_248 , L_3 ) ;
if ( F_94 ( V_246 ) ) {
F_30 ( L_62 ) ;
return F_135 ( V_246 ) ;
}
V_246 -> V_180 = V_249 ;
V_246 -> V_250 . V_251 . V_252 = V_253 ;
V_246 -> V_250 . V_254 . V_252 = V_255 ;
V_246 -> V_250 . V_256 . V_252 =
V_257 ;
V_246 -> V_250 . V_258 . V_252 = NULL ;
V_246 -> V_250 . V_259 . V_252 = NULL ;
V_246 -> V_250 . V_260 . V_252 = NULL ;
V_246 -> V_250 . V_261 . V_252 = NULL ;
V_246 -> V_250 . V_262 . V_252 = NULL ;
V_246 -> V_250 . V_263 . V_252 = NULL ;
V_42 = F_166 ( V_246 ) ;
if ( V_42 < 0 ) {
F_30 ( L_63 ) ;
return V_42 ;
}
V_179 = V_246 ;
F_2 ( L_64 ) ;
V_247 = F_165 ( V_248 , L_4 ) ;
if ( F_94 ( V_247 ) ) {
F_30 ( L_62 ) ;
V_42 = F_135 ( V_247 ) ;
goto V_264;
}
V_247 -> V_180 = V_265 ;
V_247 -> V_250 . V_251 . V_252 = V_253 ;
V_247 -> V_250 . V_254 . V_252 =
V_266 ;
V_247 -> V_250 . V_256 . V_252 = NULL ;
V_247 -> V_250 . V_258 . V_252 = NULL ;
V_247 -> V_250 . V_259 . V_252 = NULL ;
V_247 -> V_250 . V_260 . V_252 = NULL ;
V_247 -> V_250 . V_261 . V_252 = NULL ;
V_247 -> V_250 . V_262 . V_252 = NULL ;
V_247 -> V_250 . V_263 . V_252 = NULL ;
V_42 = F_166 ( V_247 ) ;
if ( V_42 < 0 ) {
F_30 ( L_63 ) ;
goto V_264;
}
V_184 = V_247 ;
F_2 ( L_65 ) ;
V_61 = F_167 ( L_66 ,
V_267 , 0 ) ;
if ( ! V_61 ) {
V_42 = - V_155 ;
goto V_268;
}
V_269 = F_167 ( L_67 , 0 , 0 ) ;
if ( ! V_269 ) {
V_42 = - V_155 ;
goto V_270;
}
return 0 ;
V_270:
F_168 ( V_61 ) ;
V_268:
F_169 ( V_184 ) ;
V_264:
F_169 ( V_179 ) ;
return V_42 ;
}
static void F_170 ( void )
{
F_168 ( V_269 ) ;
F_168 ( V_61 ) ;
F_169 ( V_179 ) ;
V_179 = NULL ;
F_2 ( L_68 ) ;
F_169 ( V_184 ) ;
V_184 = NULL ;
F_2 ( L_69 ) ;
}
static int T_12 F_171 ( void )
{
int V_42 ;
V_42 = F_164 () ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static void T_13 F_172 ( void )
{
F_170 () ;
}
