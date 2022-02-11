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
static char * F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
return V_31 -> V_32 ;
}
static T_6 F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_33 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_35 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_36 ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_37 ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_38 ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_39 ;
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_40 ;
}
static T_3 F_20 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_33 ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_12 ( V_42 ,
struct V_43 , V_45 ) ;
F_22 ( & V_44 -> V_46 , 0 ) ;
}
static void F_23 ( struct V_43 * V_44 )
{
F_24 ( & V_44 -> V_45 , F_21 ) ;
F_25 ( V_47 , & V_44 -> V_45 ) ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
V_49 -> V_50 = 0 ;
F_27 ( V_49 -> V_51 & V_52 ) ;
V_49 -> V_51 |= V_52 ;
F_22 ( & V_49 -> V_46 , 0 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_26 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static int F_29 ( struct V_46 * V_46 )
{
struct V_48 * V_49 ;
if ( ( V_46 -> V_53 & V_54 ) == 0 ) {
V_49 = F_12 ( V_46 , struct V_48 , V_46 ) ;
V_49 -> V_51 |= V_55 ;
}
return F_30 ( V_46 ) ;
}
static void F_31 ( struct V_46 * V_46 )
{
struct V_48 * V_49 ;
if ( V_46 -> V_53 & V_54 ) {
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_32 ( V_44 ) ;
return;
}
V_49 = F_12 ( V_46 , struct V_48 , V_46 ) ;
F_33 ( V_49 ) ;
}
static int F_34 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 ;
struct V_61 * V_62 ;
unsigned long V_63 ;
F_35 ( ! V_59 ) ;
V_62 = V_59 -> V_62 ;
F_36 ( & V_62 -> V_64 -> V_65 , V_63 ) ;
F_37 ( V_57 ) ;
F_38 ( & V_62 -> V_64 -> V_65 , V_63 ) ;
return 1 ;
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 ;
struct V_61 * V_62 ;
unsigned long V_63 ;
F_35 ( ! V_59 ) ;
V_62 = V_59 -> V_62 ;
F_36 ( & V_62 -> V_64 -> V_65 , V_63 ) ;
F_40 ( V_59 ) ;
F_38 ( & V_62 -> V_64 -> V_65 , V_63 ) ;
}
static T_3 F_41 ( struct V_56 * V_57 )
{
return 0 ;
}
static int F_42 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
V_49 -> V_51 |= V_66 ;
V_49 -> V_67 = V_46 -> V_68 ;
V_49 -> V_69 = F_43 ( V_46 ) ;
V_49 -> V_70 = V_46 -> V_71 ;
V_49 -> V_72 = V_46 -> V_73 ;
V_49 -> V_74 = V_46 -> V_75 ;
V_49 -> V_76 = V_46 -> V_77 ;
V_49 -> V_78 = V_46 -> V_79 -> V_80 . V_81 ;
V_46 -> V_82 = 0 ;
return F_44 ( V_49 ) ;
}
static int F_45 ( struct V_46 * V_46 )
{
unsigned long V_63 ;
F_36 ( & V_46 -> V_83 , V_63 ) ;
if ( V_46 -> V_84 == V_85 ||
V_46 -> V_84 == V_86 ) {
F_38 ( & V_46 -> V_83 , V_63 ) ;
F_46 ( & V_46 -> V_87 ,
3 * V_88 ) ;
return 0 ;
}
F_38 ( & V_46 -> V_83 , V_63 ) ;
return 0 ;
}
static void F_47 ( struct V_89 * V_90 )
{
return;
}
static int F_48 ( struct V_46 * V_46 )
{
return 0 ;
}
static int F_49 ( T_7 * V_62 , struct V_48 * V_49 ,
unsigned char * V_91 , T_8 V_68 , int V_92 ,
int V_93 , int V_94 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_63 = V_95 ;
if ( V_94 )
V_63 |= V_96 ;
V_59 = V_49 -> V_59 ;
if ( ! V_59 ) {
F_50 ( L_5 ) ;
return - V_20 ;
}
V_57 = V_59 -> V_57 ;
if ( ! V_57 ) {
F_50 ( L_6 ) ;
return - V_20 ;
}
return F_51 ( V_46 , V_57 , V_91 , & V_49 -> V_97 [ 0 ] ,
V_49 -> V_98 , V_68 , V_92 ,
V_93 , V_63 ) ;
}
static void F_52 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
V_49 -> V_50 = 0 ;
V_49 -> V_51 |= V_99 ;
if ( ! V_49 -> V_100 ) {
if ( V_49 -> V_46 . V_101 & V_102 ) {
F_53 ( & V_49 -> V_46 . V_87 ) ;
return;
}
if ( V_49 -> V_46 . V_82 )
F_54 ( & V_49 -> V_46 ,
V_49 -> V_46 . V_82 ) ;
else
F_54 ( & V_49 -> V_46 ,
V_103 ) ;
return;
}
return F_55 ( & V_49 -> V_46 ) ;
}
static void F_56 ( struct V_48 * V_49 )
{
V_49 -> V_51 |= V_104 ;
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_52 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static void F_57 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
F_58 ( & V_49 -> V_46 . V_105 ) ;
F_54 ( & V_49 -> V_46 , V_49 -> V_46 . V_82 ) ;
}
static void F_59 ( struct V_48 * V_49 )
{
F_24 ( & V_49 -> V_42 , F_57 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static int F_60 ( struct V_43 * V_44 , T_8 V_106 ,
T_9 V_107 , T_8 V_108 )
{
struct V_58 * V_59 = V_44 -> V_59 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
return F_61 ( V_46 , V_59 -> V_57 , NULL , V_106 , V_44 ,
V_107 , V_109 , V_108 , V_95 ) ;
}
static int F_62 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
V_49 -> V_51 |= V_110 ;
V_49 -> V_67 = V_46 -> V_68 ;
V_49 -> V_69 = F_43 ( V_46 ) ;
V_49 -> V_70 = V_46 -> V_71 ;
V_49 -> V_72 = V_46 -> V_73 ;
V_49 -> V_111 = 0 ;
V_49 -> V_74 = V_46 -> V_75 ;
V_49 -> V_76 = V_46 -> V_77 ;
V_49 -> V_78 = V_46 -> V_79 -> V_80 . V_81 ;
V_46 -> V_82 = 0 ;
return F_63 ( V_49 , V_112 | V_113 ,
V_46 -> V_114 ) ;
}
static int F_64 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
int V_115 = V_113 ;
V_49 -> V_67 = V_46 -> V_68 ;
V_49 -> V_72 = NULL ;
V_49 -> V_70 = 0 ;
V_49 -> V_111 = 0 ;
V_49 -> V_69 = F_43 ( V_46 ) ;
if ( V_49 -> V_51 & V_116 ) {
F_65 ( L_7 , V_49 ) ;
F_66 () ;
}
V_49 -> V_51 |= V_116 ;
if ( V_46 -> V_117 == V_118 ) {
if ( V_46 -> V_53 & V_119 ) {
V_46 -> V_53 &= ~ V_119 ;
V_46 -> V_120 = 0 ;
}
V_46 -> V_53 |= V_121 ;
V_46 -> V_120 += V_46 -> V_68 ;
V_49 -> V_67 = 0 ;
}
return F_63 ( V_49 , V_115 , V_46 -> V_114 ) ;
}
static void F_67 ( struct V_46 * V_46 )
{
struct V_122 * V_123 = V_46 -> V_122 ;
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_2 ( L_8 ,
V_44 , V_123 -> V_124 , V_123 -> V_125 ) ;
switch ( V_123 -> V_125 ) {
case V_126 :
V_44 -> V_127 = V_128 ;
break;
case V_129 :
V_44 -> V_127 = V_130 ;
break;
case V_131 :
V_44 -> V_127 = V_132 ;
break;
case V_133 :
default:
V_44 -> V_127 = V_134 ;
break;
}
F_68 ( V_44 ) ;
}
static void F_69 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
F_70 ( V_49 ) ;
}
static void F_71 ( struct V_58 * V_59 )
{
struct V_89 * V_135 = V_59 -> V_57 -> V_89 ;
struct V_26 * V_27 = V_135 -> V_27 ;
struct V_136 * V_136 = V_27 -> V_137 ;
struct V_30 * V_31 = F_12 ( V_136 ,
struct V_30 , V_138 ) ;
struct V_139 * V_90 = F_12 ( V_135 ,
struct V_139 , V_89 ) ;
void * V_140 ;
F_2 ( L_9 , V_90 -> V_141 ) ;
V_140 = F_72 ( & V_31 -> V_142 , V_90 -> V_141 ) ;
if ( F_27 ( V_140 && ( V_140 != V_135 ) ) ) {
F_73 ( & V_31 -> V_142 , V_90 -> V_141 ,
V_140 , V_109 ) ;
}
F_2 ( L_10 ,
V_135 , V_90 -> V_143 , V_90 -> V_141 ) ;
F_74 ( V_31 , V_90 , V_59 ) ;
}
static void F_75 ( struct V_144 * V_144 )
{
struct V_56 * V_57 = F_12 ( V_144 ,
struct V_56 , V_145 ) ;
F_40 ( V_57 -> V_60 ) ;
}
static void F_76 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_77 ( & V_59 -> V_62 -> V_64 -> V_65 ) ;
F_78 ( & V_59 -> V_57 -> V_145 , F_75 ) ;
}
static void F_79 ( struct V_58 * V_59 )
{
F_77 ( & V_59 -> V_62 -> V_64 -> V_65 ) ;
F_37 ( V_59 -> V_57 ) ;
}
static int F_80 ( struct V_89 * V_135 ,
const char * V_1 )
{
struct V_139 * V_90 =
F_12 ( V_135 , struct V_139 , V_89 ) ;
T_2 V_23 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return - V_20 ;
V_90 -> V_143 = V_23 ;
F_3 ( & V_90 -> V_146 [ 0 ] , V_10 , V_23 ) ;
return 0 ;
}
static T_1 F_81 (
struct V_26 * V_27 ,
char * V_147 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_147 , V_148 , L_11 ,
F_82 ( & V_29 -> V_149 ) ) ;
}
static void F_83 ( struct V_41 * V_42 )
{
struct V_28 * V_150 = F_12 ( V_42 ,
struct V_28 , V_151 ) ;
struct V_26 * V_27 = & V_150 -> V_27 ;
struct V_61 * V_152 = V_150 -> V_31 -> V_153 ;
if ( ! F_84 ( & V_27 -> V_154 . V_155 ) ) {
F_85 ( & V_150 -> V_149 , 1 ) ;
F_86 ( V_152 ) ;
}
F_53 ( & V_150 -> V_156 ) ;
}
static void F_87 ( struct V_41 * V_42 )
{
struct V_28 * V_150 = F_12 ( V_42 ,
struct V_28 , V_151 ) ;
struct V_26 * V_27 = & V_150 -> V_27 ;
struct V_61 * V_152 = V_150 -> V_31 -> V_153 ;
if ( ! F_88 ( V_152 -> V_157 . V_158 ) ) {
F_85 ( & V_150 -> V_149 , 0 ) ;
F_89 ( & V_27 -> V_154 . V_155 ) ;
}
F_53 ( & V_150 -> V_156 ) ;
}
static T_1 F_90 (
struct V_26 * V_27 ,
const char * V_147 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_159 ;
int V_25 ;
V_25 = F_91 ( V_147 , 0 , & V_159 ) ;
if ( V_25 < 0 ) {
F_50 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_159 != 1 ) && ( V_159 != 0 ) ) {
F_50 ( L_13 , V_159 ) ;
return - V_20 ;
}
if ( V_159 ) {
if ( F_82 ( & V_29 -> V_149 ) )
return - V_160 ;
F_24 ( & V_29 -> V_151 , F_83 ) ;
} else {
if ( ! F_82 ( & V_29 -> V_149 ) )
return V_21 ;
F_24 ( & V_29 -> V_151 , F_87 ) ;
}
F_92 ( & V_29 -> V_156 ) ;
F_93 ( & V_29 -> V_151 ) ;
F_94 ( & V_29 -> V_156 ) ;
if ( V_159 ) {
if ( ! F_82 ( & V_29 -> V_149 ) )
return - V_161 ;
} else {
if ( F_82 ( & V_29 -> V_149 ) )
return - V_162 ;
}
return V_21 ;
}
static T_1 F_95 (
struct V_26 * V_27 ,
char * V_147 )
{
return F_96 ( V_27 , V_147 ) ;
}
static T_1 F_97 (
struct V_26 * V_27 ,
const char * V_147 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_163 ;
int V_164 = F_91 ( V_147 , 0 , & V_163 ) ;
if ( V_164 ) {
F_50 ( L_14 , V_164 ) ;
return V_164 ;
}
if ( V_163 != 0 && V_163 != 1 && V_163 != 3 ) {
F_50 ( L_15 , V_163 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_163 ;
return V_21 ;
}
static T_1 F_98 (
struct V_26 * V_27 ,
char * V_147 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_147 , L_11 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_99 (
struct V_136 * V_2 ,
struct V_165 * V_166 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_138 ) ;
struct V_28 * V_29 ;
unsigned long V_167 ;
int V_164 ;
if ( strstr ( V_1 , L_16 ) != V_1 )
return F_100 ( - V_20 ) ;
if ( F_91 ( V_1 + 5 , 10 , & V_167 ) || V_167 > V_168 )
return F_100 ( - V_20 ) ;
if ( ( V_167 != 1 ) ) {
F_50 ( L_17 ) ;
return F_100 ( - V_169 ) ;
}
V_29 = F_101 ( sizeof( struct V_28 ) , V_170 ) ;
if ( ! V_29 ) {
F_50 ( L_18 ) ;
return F_100 ( - V_171 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_167 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_164 = F_102 ( V_2 , & V_29 -> V_27 , V_172 ) ;
if ( V_164 < 0 ) {
F_103 ( V_29 ) ;
return NULL ;
}
V_31 -> V_173 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_104 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_61 * V_62 = V_31 -> V_153 ;
if ( V_62 -> V_157 . V_158 && ! V_62 -> V_157 . V_158 -> V_174 )
F_88 ( V_62 -> V_157 . V_158 ) ;
F_105 ( V_27 ) ;
V_31 -> V_173 = NULL ;
F_103 ( V_29 ) ;
}
static T_1 F_106 (
struct V_26 * V_27 ,
char * V_147 )
{
return F_81 ( V_27 , V_147 ) ;
}
static T_1 F_107 (
struct V_26 * V_27 ,
const char * V_147 ,
T_4 V_21 )
{
struct V_136 * V_136 = V_27 -> V_137 ;
struct V_30 * V_31 = F_12 ( V_136 ,
struct V_30 , V_138 ) ;
struct V_61 * V_62 = V_31 -> V_153 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_159 ;
int V_25 ;
V_25 = F_91 ( V_147 , 0 , & V_159 ) ;
if ( V_25 < 0 ) {
F_50 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_159 != 1 ) && ( V_159 != 0 ) ) {
F_50 ( L_13 , V_159 ) ;
return - V_20 ;
}
if ( V_159 ) {
if ( F_82 ( & V_29 -> V_149 ) )
return - V_160 ;
F_85 ( & V_29 -> V_149 , 1 ) ;
F_86 ( V_62 ) ;
} else {
if ( ! F_82 ( & V_29 -> V_149 ) )
return V_21 ;
F_85 ( & V_29 -> V_149 , 0 ) ;
F_88 ( V_62 -> V_157 . V_158 ) ;
}
return V_21 ;
}
static struct V_26 * F_108 (
struct V_136 * V_2 ,
struct V_165 * V_166 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_138 ) ;
struct V_28 * V_29 ;
unsigned long V_167 ;
int V_164 ;
if ( strstr ( V_1 , L_16 ) != V_1 )
return F_100 ( - V_20 ) ;
if ( F_91 ( V_1 + 5 , 10 , & V_167 ) || V_167 > V_168 )
return F_100 ( - V_20 ) ;
V_29 = F_101 ( sizeof( struct V_28 ) , V_170 ) ;
if ( ! V_29 ) {
F_50 ( L_18 ) ;
return F_100 ( - V_171 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_167 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_164 = F_102 ( V_2 , & V_29 -> V_27 , V_172 ) ;
if ( V_164 < 0 ) {
F_103 ( V_29 ) ;
return NULL ;
}
V_31 -> V_173 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_58 * F_109 (
T_7 * V_62 ,
const T_9 * V_175 )
{
struct V_30 * V_31 ;
struct V_89 * V_135 ;
struct V_139 * V_90 ;
T_3 V_176 ;
V_31 = V_62 -> V_157 . V_177 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return NULL ;
}
V_176 = F_110 ( V_175 ) ;
F_2 ( L_20 , V_176 ) ;
V_135 = F_111 ( & V_31 -> V_142 , V_176 ) ;
if ( ! V_135 ) {
F_2 ( L_21 , V_176 ) ;
return NULL ;
}
F_2 ( L_22 ,
V_135 , V_135 -> V_178 ) ;
V_90 = F_12 ( V_135 , struct V_139 , V_89 ) ;
if ( ! V_90 -> V_58 ) {
F_50 ( L_23 ) ;
return NULL ;
}
return V_90 -> V_58 ;
}
static void F_112 (
struct V_30 * V_31 ,
struct V_89 * V_179 ,
struct V_139 * V_90 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
T_9 * V_175 )
{
T_3 V_176 ;
void * V_180 ;
int V_25 ;
V_176 = F_110 ( V_175 ) ;
F_2 ( L_24 , V_176 ) ;
V_180 = F_111 ( & V_31 -> V_142 , V_176 ) ;
if ( ! V_180 ) {
if ( V_179 ) {
F_2 ( L_25 ) ;
V_90 -> V_141 = V_176 ;
V_25 = F_73 ( & V_31 -> V_142 , V_176 ,
V_179 , V_109 ) ;
if ( V_25 )
F_113 ( V_181 L_26 ,
( int ) V_176 ) ;
} else {
F_2 ( L_27 ) ;
}
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
return;
}
if ( V_90 -> V_58 ) {
if ( V_179 == NULL ) {
F_2 ( L_28 ) ;
F_72 ( & V_31 -> V_142 , V_176 ) ;
V_90 -> V_58 = NULL ;
return;
}
F_2 ( L_29 ) ;
F_114 ( & V_31 -> V_142 , V_176 , V_179 ) ;
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
return;
}
if ( V_179 == NULL ) {
F_2 ( L_30 ) ;
F_72 ( & V_31 -> V_142 , V_176 ) ;
return;
}
F_2 ( L_31 ) ;
F_114 ( & V_31 -> V_142 , V_176 , V_179 ) ;
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
F_2 ( L_32 ,
V_90 -> V_58 , V_179 , V_179 -> V_178 ) ;
}
static struct V_58 * F_115 (
T_7 * V_62 ,
const T_10 V_182 )
{
struct V_30 * V_31 ;
struct V_89 * V_135 ;
struct V_139 * V_90 ;
struct V_183 * V_184 ;
V_31 = V_62 -> V_157 . V_177 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return NULL ;
}
F_2 ( L_33 , V_182 ) ;
V_184 = V_31 -> V_185 + V_182 ;
V_135 = V_184 -> V_135 ;
if ( ! V_135 ) {
F_2 ( L_34 ,
V_182 ) ;
return NULL ;
}
V_90 = F_12 ( V_135 , struct V_139 , V_89 ) ;
if ( ! V_90 -> V_58 ) {
F_50 ( L_23 ) ;
return NULL ;
}
return V_90 -> V_58 ;
}
static void F_116 (
struct V_30 * V_31 ,
struct V_89 * V_179 ,
struct V_139 * V_90 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
T_10 V_182 )
{
struct V_89 * V_186 ;
struct V_183 * V_184 ;
F_2 ( L_35 , V_182 ) ;
V_184 = & ( (struct V_183 * )
V_31 -> V_185 ) [ V_182 ] ;
V_186 = V_184 -> V_135 ;
if ( ! V_186 ) {
F_2 ( L_36 ) ;
V_184 -> V_135 = V_179 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
return;
}
if ( V_90 -> V_58 ) {
if ( V_179 == NULL ) {
F_2 ( L_37 ) ;
V_184 -> V_135 = NULL ;
V_90 -> V_58 = NULL ;
return;
}
F_2 ( L_38 ) ;
V_184 -> V_135 = V_179 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
return;
}
if ( V_179 == NULL ) {
F_2 ( L_39 ) ;
V_184 -> V_135 = NULL ;
return;
}
F_2 ( L_40 ) ;
V_184 -> V_135 = V_179 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
F_2 ( L_41 ,
V_90 -> V_58 , V_179 , V_179 -> V_178 ) ;
}
static void F_74 ( struct V_30 * V_31 ,
struct V_139 * V_90 , struct V_58 * V_59 )
{
struct V_56 * V_57 = V_59 -> V_57 ;
unsigned char V_187 [ 3 ] ;
V_187 [ 0 ] = V_59 -> V_175 . V_14 . V_188 ;
V_187 [ 1 ] = V_59 -> V_175 . V_14 . V_189 ;
V_187 [ 2 ] = V_59 -> V_175 . V_14 . V_190 ;
F_112 ( V_31 , NULL , V_90 , V_57 ,
V_59 , V_187 ) ;
F_116 ( V_31 , NULL , V_90 , V_57 ,
V_59 , V_59 -> V_182 ) ;
}
static void F_117 ( struct V_58 * V_59 )
{
struct V_158 * V_191 = V_59 -> V_191 ;
struct V_192 * V_193 = V_191 -> V_193 ;
T_7 * V_62 = F_118 ( V_193 -> V_194 ) ;
struct V_56 * V_57 ;
struct V_89 * V_135 ;
struct V_30 * V_31 ;
struct V_139 * V_90 ;
F_35 ( F_119 () ) ;
V_57 = V_59 -> V_57 ;
if ( ! V_57 ) {
F_50 ( L_42 ) ;
F_66 () ;
return;
}
V_135 = V_57 -> V_89 ;
V_90 = F_12 ( V_135 , struct V_139 , V_89 ) ;
V_31 = V_62 -> V_157 . V_177 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return;
}
F_120 ( V_57 ) ;
F_121 ( V_59 -> V_57 ) ;
F_122 ( V_59 -> V_57 ) ;
}
static int F_123 (
T_7 * V_62 ,
unsigned char * V_195 ,
void * V_58 ,
T_9 * V_175 ,
T_10 V_182 )
{
struct V_192 * V_193 = V_62 -> V_64 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_139 * V_90 ;
struct V_26 * V_27 ;
struct V_89 * V_135 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_58 ;
unsigned char V_196 [ 36 ] ;
unsigned long V_63 ;
int V_197 = ( V_193 -> V_198 ) ? V_193 -> V_198 :
V_199 ;
V_31 = V_62 -> V_157 . V_177 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return - V_20 ;
}
V_29 = V_31 -> V_173 ;
if ( ! V_29 ) {
F_50 ( L_43 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_57 = F_124 ( V_197 ,
sizeof( struct V_48 ) ,
V_200 ) ;
if ( F_125 ( V_57 ) ) {
F_50 ( L_44 ) ;
return F_126 ( V_57 ) ;
}
memset ( & V_196 , 0 , 36 ) ;
snprintf ( V_196 , sizeof( V_196 ) , L_45 , V_195 ) ;
V_57 -> V_89 = F_127 ( V_27 ,
V_196 ) ;
if ( ! V_57 -> V_89 ) {
F_128 ( V_57 ) ;
return - V_20 ;
}
V_135 = V_57 -> V_89 ;
V_90 = F_12 ( V_135 , struct V_139 , V_89 ) ;
F_36 ( & V_193 -> V_65 , V_63 ) ;
F_112 ( V_31 , V_135 , V_90 , V_57 ,
V_58 , V_175 ) ;
F_116 ( V_31 , V_135 , V_90 , V_57 ,
V_58 , V_182 ) ;
F_38 ( & V_193 -> V_65 , V_63 ) ;
F_129 ( V_135 -> V_27 , V_135 , V_57 , V_59 ) ;
return 0 ;
}
static void F_130 ( struct V_58 * V_59 , T_11 V_175 ,
T_10 V_182 , bool V_201 )
{
struct V_158 * V_191 = V_59 -> V_191 ;
struct V_192 * V_193 = V_191 -> V_193 ;
T_7 * V_62 = F_118 ( V_193 -> V_194 ) ;
struct V_30 * V_31 = V_62 -> V_157 . V_177 ;
struct V_89 * V_135 = V_59 -> V_57 -> V_89 ;
struct V_139 * V_90 = F_12 ( V_135 ,
struct V_139 , V_89 ) ;
T_3 V_176 ;
if ( V_59 -> V_182 != V_182 || V_59 -> V_175 . V_202 != V_175 . V_202 )
F_131 ( L_46 ,
V_59 , V_59 -> V_196 ,
V_59 -> V_182 , V_182 , V_59 -> V_175 . V_14 . V_188 ,
V_59 -> V_175 . V_14 . V_189 , V_59 -> V_175 . V_14 . V_190 , V_175 . V_14 . V_188 ,
V_175 . V_14 . V_189 , V_175 . V_14 . V_190 ) ;
if ( V_59 -> V_182 != V_182 ) {
if ( V_31 -> V_185 [ V_59 -> V_182 ] . V_135 == V_135 )
V_31 -> V_185 [ V_59 -> V_182 ] . V_135 = NULL ;
V_31 -> V_185 [ V_182 ] . V_135 = V_135 ;
V_59 -> V_182 = V_182 ;
}
if ( V_59 -> V_175 . V_202 != V_175 . V_202 ) {
V_176 = ( ( ( T_3 ) V_59 -> V_175 . V_14 . V_188 << 16 ) |
( ( T_3 ) V_59 -> V_175 . V_14 . V_189 << 8 ) |
( ( T_3 ) V_59 -> V_175 . V_14 . V_190 ) ) ;
if ( F_111 ( & V_31 -> V_142 , V_176 ) )
F_132 ( F_72 ( & V_31 -> V_142 , V_176 ) != V_135 ,
L_47 ,
V_59 -> V_175 . V_14 . V_188 , V_59 -> V_175 . V_14 . V_189 , V_59 -> V_175 . V_14 . V_190 ) ;
else
F_132 ( 1 , L_48 ,
V_59 -> V_175 . V_14 . V_188 , V_59 -> V_175 . V_14 . V_189 , V_59 -> V_175 . V_14 . V_190 ) ;
V_176 = ( ( ( T_3 ) V_175 . V_14 . V_188 << 16 ) |
( ( T_3 ) V_175 . V_14 . V_189 << 8 ) |
( ( T_3 ) V_175 . V_14 . V_190 ) ) ;
if ( F_111 ( & V_31 -> V_142 , V_176 ) ) {
F_132 ( 1 , L_49 ,
V_175 . V_14 . V_188 , V_175 . V_14 . V_189 , V_175 . V_14 . V_190 ) ;
F_114 ( & V_31 -> V_142 , V_176 , V_135 ) ;
} else {
F_73 ( & V_31 -> V_142 , V_176 , V_135 , V_109 ) ;
}
V_59 -> V_175 = V_175 ;
V_90 -> V_141 = V_176 ;
}
V_59 -> V_201 = V_201 ;
V_59 -> V_203 = 1 ;
V_59 -> V_204 = 0 ;
}
static int F_133 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_134 ( & V_31 -> V_142 ) ;
if ( V_25 ) {
F_50 ( L_50 ) ;
return V_25 ;
}
V_31 -> V_185 = F_135 ( sizeof( struct V_183 ) *
65536 ) ;
if ( ! V_31 -> V_185 ) {
F_50 ( L_51 ,
sizeof( struct V_183 ) * 65536 ) ;
F_136 ( & V_31 -> V_142 ) ;
return - V_171 ;
}
memset ( V_31 -> V_185 , 0 , sizeof( struct V_183 )
* 65536 ) ;
F_2 ( L_52 ,
sizeof( struct V_183 ) * 65536 ) ;
return 0 ;
}
static int F_137 ( struct V_61 * V_62 ,
void * V_177 ,
T_2 V_205 , T_2 V_206 )
{
struct V_192 * V_193 = V_62 -> V_64 ;
struct V_30 * V_31 =
(struct V_30 * ) V_177 ;
V_193 -> V_191 . V_207 = & V_208 ;
V_62 -> V_157 . V_177 = V_177 ;
V_31 -> V_153 = V_62 ;
return 0 ;
}
static struct V_136 * F_138 (
struct V_209 * V_210 ,
struct V_165 * V_166 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_164 = - V_161 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_100 ( - V_20 ) ;
V_31 = F_101 ( sizeof( struct V_30 ) , V_170 ) ;
if ( ! V_31 ) {
F_50 ( L_53 ) ;
return F_100 ( - V_171 ) ;
}
V_31 -> V_211 = V_22 ;
F_3 ( & V_31 -> V_212 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_54 , ( unsigned long long ) V_22 ) ;
V_164 = F_133 ( V_31 ) ;
if ( V_164 != 0 )
goto V_213;
V_164 = F_139 ( V_31 , V_22 , 0 , 0 ,
F_137 ) ;
if ( V_164 != 0 )
goto V_214;
return & V_31 -> V_138 ;
V_214:
F_140 ( V_31 -> V_185 ) ;
F_136 ( & V_31 -> V_142 ) ;
V_213:
F_103 ( V_31 ) ;
return F_100 ( V_164 ) ;
}
static void F_141 ( struct V_136 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_138 ) ;
struct V_61 * V_62 = V_31 -> V_153 ;
struct V_89 * V_140 ;
T_3 V_176 = 0 ;
if ( V_62 -> V_157 . V_158 && ! V_62 -> V_157 . V_158 -> V_215 )
F_142 ( V_62 -> V_157 . V_158 ) ;
F_143 ( V_62 ) ;
F_140 ( V_31 -> V_185 ) ;
F_144 (&lport->lport_fcport_map, key, node)
F_72 ( & V_31 -> V_142 , V_176 ) ;
F_136 ( & V_31 -> V_142 ) ;
F_103 ( V_31 ) ;
}
static int F_145 ( struct V_61 * V_152 ,
void * V_177 ,
T_2 V_205 , T_2 V_206 )
{
struct V_216 * V_217 ;
struct V_218 * V_219 = V_152 -> V_220 ;
struct V_61 * V_221 ;
struct V_30 * V_31 =
(struct V_30 * ) V_177 ;
struct V_30 * V_222 =
(struct V_30 * ) V_152 -> V_157 . V_177 ;
struct V_28 * V_150 ;
struct V_223 V_224 ;
if ( ! F_146 ( V_152 ) ) {
F_50 ( L_55 ) ;
return - V_162 ;
}
if ( ! V_222 || ! V_222 -> V_173 ||
! F_82 ( & V_222 -> V_173 -> V_149 ) ) {
F_50 ( L_56 ) ;
return - V_162 ;
}
V_150 = V_222 -> V_173 ;
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
V_224 . V_196 = V_205 ;
V_224 . V_225 = V_206 ;
V_224 . V_226 = V_227 ;
V_224 . V_228 = V_229 ;
V_224 . V_230 = false ;
V_217 = F_147 ( V_219 , 0 , & V_224 ) ;
if ( ! V_217 ) {
F_50 ( L_57 ) ;
return - V_161 ;
}
V_221 = (struct V_61 * ) V_217 -> V_231 ;
V_221 -> V_157 . V_177 = V_177 ;
V_31 -> V_153 = V_221 ;
F_148 ( V_221 -> V_220 ) ;
return 0 ;
}
static struct V_136 * F_149 (
struct V_209 * V_210 ,
struct V_165 * V_166 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_232 , V_205 , V_206 ;
char * V_233 , V_234 [ 128 ] ;
int V_164 ;
snprintf ( V_234 , 128 , L_58 , V_1 ) ;
V_233 = strchr ( V_234 , '@' ) ;
if ( ! V_233 ) {
F_50 ( L_59 ) ;
return F_100 ( - V_20 ) ;
}
* V_233 ++ = '\0' ;
if ( F_1 ( V_234 , & V_232 , 1 ) < 0 )
return F_100 ( - V_20 ) ;
if ( F_9 ( V_233 , strlen ( V_233 ) + 1 ,
& V_205 , & V_206 ) < 0 )
return F_100 ( - V_20 ) ;
V_31 = F_101 ( sizeof( struct V_30 ) , V_170 ) ;
if ( ! V_31 ) {
F_50 ( L_60 ) ;
return F_100 ( - V_171 ) ;
}
V_31 -> V_235 = V_205 ;
V_31 -> V_236 = V_206 ;
sprintf ( V_31 -> V_32 , L_54 , ( unsigned long long ) V_205 ) ;
V_164 = F_133 ( V_31 ) ;
if ( V_164 != 0 )
goto V_213;
V_164 = F_139 ( V_31 , V_232 , V_205 , V_206 ,
F_145 ) ;
if ( V_164 != 0 )
goto V_214;
return & V_31 -> V_138 ;
V_214:
F_140 ( V_31 -> V_185 ) ;
F_136 ( & V_31 -> V_142 ) ;
V_213:
F_103 ( V_31 ) ;
return F_100 ( V_164 ) ;
}
static void F_150 ( struct V_136 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_138 ) ;
struct V_61 * V_221 = V_31 -> V_153 ;
struct V_192 * V_193 = V_221 -> V_64 ;
T_7 * V_152 = F_118 ( V_193 -> V_194 ) ;
F_151 ( V_221 -> V_220 ) ;
F_152 ( V_221 -> V_216 ) ;
F_151 ( V_152 -> V_220 ) ;
F_103 ( V_31 ) ;
}
static T_1 F_153 (
struct V_209 * V_210 ,
char * V_147 )
{
return sprintf ( V_147 ,
L_61
V_237 L_62 , V_238 , F_154 () -> V_239 ,
F_154 () -> V_240 ) ;
}
static int F_155 ( void )
{
int V_164 ;
F_2 ( L_63
V_237 L_62 , V_238 , F_154 () -> V_239 ,
F_154 () -> V_240 ) ;
V_164 = F_156 ( & V_241 ) ;
if ( V_164 )
return V_164 ;
V_164 = F_156 ( & V_242 ) ;
if ( V_164 )
goto V_243;
V_47 = F_157 ( L_64 ,
V_244 , 0 ) ;
if ( ! V_47 ) {
V_164 = - V_171 ;
goto V_245;
}
V_246 = F_157 ( L_65 , 0 , 0 ) ;
if ( ! V_246 ) {
V_164 = - V_171 ;
goto V_247;
}
return 0 ;
V_247:
F_158 ( V_47 ) ;
V_245:
F_159 ( & V_242 ) ;
V_243:
F_159 ( & V_241 ) ;
return V_164 ;
}
static void F_160 ( void )
{
F_158 ( V_246 ) ;
F_158 ( V_47 ) ;
F_159 ( & V_241 ) ;
F_159 ( & V_242 ) ;
}
static int T_12 F_161 ( void )
{
int V_164 ;
V_164 = F_155 () ;
if ( V_164 < 0 )
return V_164 ;
return 0 ;
}
static void T_13 F_162 ( void )
{
F_160 () ;
}
