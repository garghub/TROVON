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
if ( ! ( V_46 -> V_53 & V_54 ) ) {
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
return V_49 -> V_91 ;
}
return 0 ;
}
static int F_49 ( T_7 * V_62 , struct V_48 * V_49 ,
unsigned char * V_92 , T_8 V_68 , int V_93 ,
int V_94 , int V_95 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_63 = V_96 ;
if ( V_95 )
V_63 |= V_97 ;
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
return F_51 ( V_46 , V_57 , V_92 , & V_49 -> V_98 [ 0 ] ,
V_49 -> V_99 , V_68 , V_93 ,
V_94 , V_63 ) ;
}
static void F_52 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
V_49 -> V_50 = 0 ;
V_49 -> V_51 |= V_100 ;
if ( ! V_49 -> V_101 ) {
if ( V_49 -> V_46 . V_102 & V_103 ) {
F_53 ( & V_49 -> V_46 . V_87 ) ;
return;
}
if ( V_49 -> V_46 . V_82 )
F_54 ( & V_49 -> V_46 ,
V_49 -> V_46 . V_82 ) ;
else
F_54 ( & V_49 -> V_46 ,
V_104 ) ;
return;
}
return F_55 ( & V_49 -> V_46 ) ;
}
static void F_56 ( struct V_48 * V_49 )
{
V_49 -> V_51 |= V_105 ;
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_52 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static void F_57 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
F_58 ( & V_49 -> V_46 . V_106 ) ;
F_54 ( & V_49 -> V_46 , V_49 -> V_46 . V_82 ) ;
}
static void F_59 ( struct V_48 * V_49 )
{
F_24 ( & V_49 -> V_42 , F_57 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static int F_60 ( struct V_43 * V_44 , T_8 V_107 ,
T_9 V_108 , T_8 V_109 )
{
struct V_58 * V_59 = V_44 -> V_59 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
return F_61 ( V_46 , V_59 -> V_57 , NULL , V_107 , V_44 ,
V_108 , V_110 , V_109 , V_96 ) ;
}
static int F_62 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
V_49 -> V_51 |= V_111 ;
V_49 -> V_67 = V_46 -> V_68 ;
V_49 -> V_69 = F_43 ( V_46 ) ;
V_49 -> V_70 = V_46 -> V_71 ;
V_49 -> V_72 = V_46 -> V_73 ;
V_49 -> V_112 = 0 ;
V_49 -> V_74 = V_46 -> V_75 ;
V_49 -> V_76 = V_46 -> V_77 ;
V_49 -> V_78 = V_46 -> V_79 -> V_80 . V_81 ;
V_46 -> V_82 = 0 ;
return F_63 ( V_49 , V_113 | V_114 ,
V_46 -> V_115 ) ;
}
static int F_64 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
int V_116 = V_114 ;
V_49 -> V_67 = V_46 -> V_68 ;
V_49 -> V_72 = NULL ;
V_49 -> V_70 = 0 ;
V_49 -> V_112 = 0 ;
V_49 -> V_69 = F_43 ( V_46 ) ;
if ( V_49 -> V_51 & V_117 ) {
F_65 ( L_7 , V_49 ) ;
F_66 () ;
}
V_49 -> V_51 |= V_117 ;
if ( V_46 -> V_118 == V_119 ) {
if ( V_46 -> V_53 & V_120 ) {
V_46 -> V_53 &= ~ V_120 ;
V_46 -> V_121 = 0 ;
}
V_46 -> V_53 |= V_122 ;
V_46 -> V_121 += V_46 -> V_68 ;
V_49 -> V_67 = 0 ;
}
return F_63 ( V_49 , V_116 , V_46 -> V_115 ) ;
}
static void F_67 ( struct V_46 * V_46 )
{
struct V_123 * V_124 = V_46 -> V_123 ;
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_2 ( L_8 ,
V_44 , V_124 -> V_125 , V_124 -> V_126 ) ;
switch ( V_124 -> V_126 ) {
case V_127 :
V_44 -> V_128 = V_129 ;
break;
case V_130 :
V_44 -> V_128 = V_131 ;
break;
case V_132 :
V_44 -> V_128 = V_133 ;
break;
case V_134 :
default:
V_44 -> V_128 = V_135 ;
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
struct V_89 * V_136 = V_59 -> V_57 -> V_89 ;
struct V_26 * V_27 = V_136 -> V_27 ;
struct V_137 * V_137 = V_27 -> V_138 ;
struct V_30 * V_31 = F_12 ( V_137 ,
struct V_30 , V_139 ) ;
struct V_140 * V_90 = F_12 ( V_136 ,
struct V_140 , V_89 ) ;
void * V_141 ;
F_2 ( L_9 , V_90 -> V_142 ) ;
V_141 = F_72 ( & V_31 -> V_143 , V_90 -> V_142 ) ;
if ( F_27 ( V_141 && ( V_141 != V_136 ) ) ) {
F_73 ( & V_31 -> V_143 , V_90 -> V_142 ,
V_141 , V_110 ) ;
}
F_2 ( L_10 ,
V_136 , V_90 -> V_144 , V_90 -> V_142 ) ;
F_74 ( V_31 , V_90 , V_59 ) ;
}
static void F_75 ( struct V_145 * V_145 )
{
struct V_56 * V_57 = F_12 ( V_145 ,
struct V_56 , V_146 ) ;
F_40 ( V_57 -> V_60 ) ;
}
static void F_76 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_77 ( & V_59 -> V_62 -> V_64 -> V_65 ) ;
F_78 ( & V_59 -> V_57 -> V_146 , F_75 ) ;
}
static void F_79 ( struct V_58 * V_59 )
{
F_77 ( & V_59 -> V_62 -> V_64 -> V_65 ) ;
F_37 ( V_59 -> V_57 ) ;
}
static int F_80 ( struct V_89 * V_136 ,
const char * V_1 )
{
struct V_140 * V_90 =
F_12 ( V_136 , struct V_140 , V_89 ) ;
T_2 V_23 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return - V_20 ;
V_90 -> V_144 = V_23 ;
F_3 ( & V_90 -> V_147 [ 0 ] , V_10 , V_23 ) ;
return 0 ;
}
static T_1 F_81 (
struct V_26 * V_27 ,
char * V_148 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_148 , V_149 , L_11 ,
F_82 ( & V_29 -> V_150 ) ) ;
}
static void F_83 ( struct V_41 * V_42 )
{
struct V_28 * V_151 = F_12 ( V_42 ,
struct V_28 , V_152 ) ;
struct V_26 * V_27 = & V_151 -> V_27 ;
struct V_61 * V_153 = V_151 -> V_31 -> V_154 ;
if ( ! F_84 ( & V_27 -> V_155 . V_156 ) ) {
F_85 ( & V_151 -> V_150 , 1 ) ;
F_86 ( V_153 ) ;
}
F_53 ( & V_151 -> V_157 ) ;
}
static void F_87 ( struct V_41 * V_42 )
{
struct V_28 * V_151 = F_12 ( V_42 ,
struct V_28 , V_152 ) ;
struct V_26 * V_27 = & V_151 -> V_27 ;
struct V_61 * V_153 = V_151 -> V_31 -> V_154 ;
if ( ! F_88 ( V_153 -> V_158 . V_159 ) ) {
F_85 ( & V_151 -> V_150 , 0 ) ;
F_89 ( & V_27 -> V_155 . V_156 ) ;
}
F_53 ( & V_151 -> V_157 ) ;
}
static T_1 F_90 (
struct V_26 * V_27 ,
const char * V_148 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_160 ;
int V_25 ;
V_25 = F_91 ( V_148 , 0 , & V_160 ) ;
if ( V_25 < 0 ) {
F_50 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_160 != 1 ) && ( V_160 != 0 ) ) {
F_50 ( L_13 , V_160 ) ;
return - V_20 ;
}
if ( V_160 ) {
if ( F_82 ( & V_29 -> V_150 ) )
return - V_161 ;
F_24 ( & V_29 -> V_152 , F_83 ) ;
} else {
if ( ! F_82 ( & V_29 -> V_150 ) )
return V_21 ;
F_24 ( & V_29 -> V_152 , F_87 ) ;
}
F_92 ( & V_29 -> V_157 ) ;
F_93 ( & V_29 -> V_152 ) ;
F_94 ( & V_29 -> V_157 ) ;
if ( V_160 ) {
if ( ! F_82 ( & V_29 -> V_150 ) )
return - V_162 ;
} else {
if ( F_82 ( & V_29 -> V_150 ) )
return - V_163 ;
}
return V_21 ;
}
static T_1 F_95 (
struct V_26 * V_27 ,
char * V_148 )
{
return F_96 ( V_27 , V_148 ) ;
}
static T_1 F_97 (
struct V_26 * V_27 ,
const char * V_148 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_164 ;
int V_165 = F_91 ( V_148 , 0 , & V_164 ) ;
if ( V_165 ) {
F_50 ( L_14 , V_165 ) ;
return V_165 ;
}
if ( V_164 != 0 && V_164 != 1 && V_164 != 3 ) {
F_50 ( L_15 , V_164 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_164 ;
return V_21 ;
}
static T_1 F_98 (
struct V_26 * V_27 ,
char * V_148 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_148 , L_11 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_99 (
struct V_137 * V_2 ,
struct V_166 * V_167 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_28 * V_29 ;
unsigned long V_168 ;
int V_165 ;
if ( strstr ( V_1 , L_16 ) != V_1 )
return F_100 ( - V_20 ) ;
if ( F_91 ( V_1 + 5 , 10 , & V_168 ) || V_168 > V_169 )
return F_100 ( - V_20 ) ;
if ( ( V_168 != 1 ) ) {
F_50 ( L_17 ) ;
return F_100 ( - V_170 ) ;
}
V_29 = F_101 ( sizeof( struct V_28 ) , V_171 ) ;
if ( ! V_29 ) {
F_50 ( L_18 ) ;
return F_100 ( - V_172 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_168 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_165 = F_102 ( V_2 , & V_29 -> V_27 , V_173 ) ;
if ( V_165 < 0 ) {
F_103 ( V_29 ) ;
return NULL ;
}
V_31 -> V_174 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_104 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_61 * V_62 = V_31 -> V_154 ;
if ( V_62 -> V_158 . V_159 && ! V_62 -> V_158 . V_159 -> V_175 )
F_88 ( V_62 -> V_158 . V_159 ) ;
F_105 ( V_27 ) ;
V_31 -> V_174 = NULL ;
F_103 ( V_29 ) ;
}
static T_1 F_106 (
struct V_26 * V_27 ,
char * V_148 )
{
return F_81 ( V_27 , V_148 ) ;
}
static T_1 F_107 (
struct V_26 * V_27 ,
const char * V_148 ,
T_4 V_21 )
{
struct V_137 * V_137 = V_27 -> V_138 ;
struct V_30 * V_31 = F_12 ( V_137 ,
struct V_30 , V_139 ) ;
struct V_61 * V_62 = V_31 -> V_154 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_160 ;
int V_25 ;
V_25 = F_91 ( V_148 , 0 , & V_160 ) ;
if ( V_25 < 0 ) {
F_50 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_160 != 1 ) && ( V_160 != 0 ) ) {
F_50 ( L_13 , V_160 ) ;
return - V_20 ;
}
if ( V_160 ) {
if ( F_82 ( & V_29 -> V_150 ) )
return - V_161 ;
F_85 ( & V_29 -> V_150 , 1 ) ;
F_86 ( V_62 ) ;
} else {
if ( ! F_82 ( & V_29 -> V_150 ) )
return V_21 ;
F_85 ( & V_29 -> V_150 , 0 ) ;
F_88 ( V_62 -> V_158 . V_159 ) ;
}
return V_21 ;
}
static struct V_26 * F_108 (
struct V_137 * V_2 ,
struct V_166 * V_167 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_28 * V_29 ;
unsigned long V_168 ;
int V_165 ;
if ( strstr ( V_1 , L_16 ) != V_1 )
return F_100 ( - V_20 ) ;
if ( F_91 ( V_1 + 5 , 10 , & V_168 ) || V_168 > V_169 )
return F_100 ( - V_20 ) ;
V_29 = F_101 ( sizeof( struct V_28 ) , V_171 ) ;
if ( ! V_29 ) {
F_50 ( L_18 ) ;
return F_100 ( - V_172 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_168 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_165 = F_102 ( V_2 , & V_29 -> V_27 , V_173 ) ;
if ( V_165 < 0 ) {
F_103 ( V_29 ) ;
return NULL ;
}
V_31 -> V_174 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_58 * F_109 (
T_7 * V_62 ,
const T_9 * V_176 )
{
struct V_30 * V_31 ;
struct V_89 * V_136 ;
struct V_140 * V_90 ;
T_3 V_177 ;
V_31 = V_62 -> V_158 . V_178 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return NULL ;
}
V_177 = F_110 ( V_176 ) ;
F_2 ( L_20 , V_177 ) ;
V_136 = F_111 ( & V_31 -> V_143 , V_177 ) ;
if ( ! V_136 ) {
F_2 ( L_21 , V_177 ) ;
return NULL ;
}
F_2 ( L_22 ,
V_136 , V_136 -> V_179 ) ;
V_90 = F_12 ( V_136 , struct V_140 , V_89 ) ;
if ( ! V_90 -> V_58 ) {
F_50 ( L_23 ) ;
return NULL ;
}
return V_90 -> V_58 ;
}
static void F_112 (
struct V_30 * V_31 ,
struct V_89 * V_180 ,
struct V_140 * V_90 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
T_9 * V_176 )
{
T_3 V_177 ;
void * V_181 ;
int V_25 ;
V_177 = F_110 ( V_176 ) ;
F_2 ( L_24 , V_177 ) ;
V_181 = F_111 ( & V_31 -> V_143 , V_177 ) ;
if ( ! V_181 ) {
if ( V_180 ) {
F_2 ( L_25 ) ;
V_90 -> V_142 = V_177 ;
V_25 = F_73 ( & V_31 -> V_143 , V_177 ,
V_180 , V_110 ) ;
if ( V_25 )
F_113 ( V_182 L_26 ,
( int ) V_177 ) ;
} else {
F_2 ( L_27 ) ;
}
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
return;
}
if ( V_90 -> V_58 ) {
if ( V_180 == NULL ) {
F_2 ( L_28 ) ;
F_72 ( & V_31 -> V_143 , V_177 ) ;
V_90 -> V_58 = NULL ;
return;
}
F_2 ( L_29 ) ;
F_114 ( & V_31 -> V_143 , V_177 , V_180 ) ;
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
return;
}
if ( V_180 == NULL ) {
F_2 ( L_30 ) ;
F_72 ( & V_31 -> V_143 , V_177 ) ;
return;
}
F_2 ( L_31 ) ;
F_114 ( & V_31 -> V_143 , V_177 , V_180 ) ;
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
F_2 ( L_32 ,
V_90 -> V_58 , V_180 , V_180 -> V_179 ) ;
}
static struct V_58 * F_115 (
T_7 * V_62 ,
const T_10 V_183 )
{
struct V_30 * V_31 ;
struct V_89 * V_136 ;
struct V_140 * V_90 ;
struct V_184 * V_185 ;
V_31 = V_62 -> V_158 . V_178 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return NULL ;
}
F_2 ( L_33 , V_183 ) ;
V_185 = V_31 -> V_186 + V_183 ;
V_136 = V_185 -> V_136 ;
if ( ! V_136 ) {
F_2 ( L_34 ,
V_183 ) ;
return NULL ;
}
V_90 = F_12 ( V_136 , struct V_140 , V_89 ) ;
if ( ! V_90 -> V_58 ) {
F_50 ( L_23 ) ;
return NULL ;
}
return V_90 -> V_58 ;
}
static void F_116 (
struct V_30 * V_31 ,
struct V_89 * V_180 ,
struct V_140 * V_90 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
T_10 V_183 )
{
struct V_89 * V_187 ;
struct V_184 * V_185 ;
F_2 ( L_35 , V_183 ) ;
V_185 = & ( (struct V_184 * )
V_31 -> V_186 ) [ V_183 ] ;
V_187 = V_185 -> V_136 ;
if ( ! V_187 ) {
F_2 ( L_36 ) ;
V_185 -> V_136 = V_180 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
return;
}
if ( V_90 -> V_58 ) {
if ( V_180 == NULL ) {
F_2 ( L_37 ) ;
V_185 -> V_136 = NULL ;
V_90 -> V_58 = NULL ;
return;
}
F_2 ( L_38 ) ;
V_185 -> V_136 = V_180 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
return;
}
if ( V_180 == NULL ) {
F_2 ( L_39 ) ;
V_185 -> V_136 = NULL ;
return;
}
F_2 ( L_40 ) ;
V_185 -> V_136 = V_180 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
F_2 ( L_41 ,
V_90 -> V_58 , V_180 , V_180 -> V_179 ) ;
}
static void F_74 ( struct V_30 * V_31 ,
struct V_140 * V_90 , struct V_58 * V_59 )
{
struct V_56 * V_57 = V_59 -> V_57 ;
unsigned char V_188 [ 3 ] ;
V_188 [ 0 ] = V_59 -> V_176 . V_14 . V_189 ;
V_188 [ 1 ] = V_59 -> V_176 . V_14 . V_190 ;
V_188 [ 2 ] = V_59 -> V_176 . V_14 . V_191 ;
F_112 ( V_31 , NULL , V_90 , V_57 ,
V_59 , V_188 ) ;
F_116 ( V_31 , NULL , V_90 , V_57 ,
V_59 , V_59 -> V_183 ) ;
}
static void F_117 ( struct V_58 * V_59 )
{
struct V_159 * V_192 = V_59 -> V_192 ;
struct V_193 * V_194 = V_192 -> V_194 ;
T_7 * V_62 = F_118 ( V_194 -> V_195 ) ;
struct V_56 * V_57 ;
struct V_30 * V_31 ;
F_35 ( F_119 () ) ;
V_57 = V_59 -> V_57 ;
if ( ! V_57 ) {
F_50 ( L_42 ) ;
F_66 () ;
return;
}
V_31 = V_62 -> V_158 . V_178 ;
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
unsigned char * V_196 ,
void * V_58 ,
T_9 * V_176 ,
T_10 V_183 )
{
struct V_193 * V_194 = V_62 -> V_64 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_140 * V_90 ;
struct V_26 * V_27 ;
struct V_89 * V_136 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_58 ;
unsigned char V_197 [ 36 ] ;
unsigned long V_63 ;
int V_198 = ( V_194 -> V_199 ) ? V_194 -> V_199 :
V_200 ;
V_31 = V_62 -> V_158 . V_178 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return - V_20 ;
}
V_29 = V_31 -> V_174 ;
if ( ! V_29 ) {
F_50 ( L_43 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_57 = F_124 ( V_198 ,
sizeof( struct V_48 ) ,
V_201 ) ;
if ( F_125 ( V_57 ) ) {
F_50 ( L_44 ) ;
return F_126 ( V_57 ) ;
}
memset ( & V_197 , 0 , 36 ) ;
snprintf ( V_197 , sizeof( V_197 ) , L_45 , V_196 ) ;
V_57 -> V_89 = F_127 ( V_27 ,
V_197 ) ;
if ( ! V_57 -> V_89 ) {
F_128 ( V_57 ) ;
return - V_20 ;
}
V_136 = V_57 -> V_89 ;
V_90 = F_12 ( V_136 , struct V_140 , V_89 ) ;
F_36 ( & V_194 -> V_65 , V_63 ) ;
F_112 ( V_31 , V_136 , V_90 , V_57 ,
V_58 , V_176 ) ;
F_116 ( V_31 , V_136 , V_90 , V_57 ,
V_58 , V_183 ) ;
F_38 ( & V_194 -> V_65 , V_63 ) ;
F_129 ( V_136 -> V_27 , V_136 , V_57 , V_59 ) ;
return 0 ;
}
static void F_130 ( struct V_58 * V_59 , T_11 V_176 ,
T_10 V_183 , bool V_202 )
{
struct V_159 * V_192 = V_59 -> V_192 ;
struct V_193 * V_194 = V_192 -> V_194 ;
T_7 * V_62 = F_118 ( V_194 -> V_195 ) ;
struct V_30 * V_31 = V_62 -> V_158 . V_178 ;
struct V_89 * V_136 = V_59 -> V_57 -> V_89 ;
struct V_140 * V_90 = F_12 ( V_136 ,
struct V_140 , V_89 ) ;
T_3 V_177 ;
if ( V_59 -> V_183 != V_183 || V_59 -> V_176 . V_203 != V_176 . V_203 )
F_131 ( L_46 ,
V_59 , V_59 -> V_197 ,
V_59 -> V_183 , V_183 , V_59 -> V_176 . V_14 . V_189 ,
V_59 -> V_176 . V_14 . V_190 , V_59 -> V_176 . V_14 . V_191 , V_176 . V_14 . V_189 ,
V_176 . V_14 . V_190 , V_176 . V_14 . V_191 ) ;
if ( V_59 -> V_183 != V_183 ) {
if ( V_31 -> V_186 [ V_59 -> V_183 ] . V_136 == V_136 )
V_31 -> V_186 [ V_59 -> V_183 ] . V_136 = NULL ;
V_31 -> V_186 [ V_183 ] . V_136 = V_136 ;
V_59 -> V_183 = V_183 ;
}
if ( V_59 -> V_176 . V_203 != V_176 . V_203 ) {
V_177 = ( ( ( T_3 ) V_59 -> V_176 . V_14 . V_189 << 16 ) |
( ( T_3 ) V_59 -> V_176 . V_14 . V_190 << 8 ) |
( ( T_3 ) V_59 -> V_176 . V_14 . V_191 ) ) ;
if ( F_111 ( & V_31 -> V_143 , V_177 ) )
F_132 ( F_72 ( & V_31 -> V_143 , V_177 ) != V_136 ,
L_47 ,
V_59 -> V_176 . V_14 . V_189 , V_59 -> V_176 . V_14 . V_190 , V_59 -> V_176 . V_14 . V_191 ) ;
else
F_132 ( 1 , L_48 ,
V_59 -> V_176 . V_14 . V_189 , V_59 -> V_176 . V_14 . V_190 , V_59 -> V_176 . V_14 . V_191 ) ;
V_177 = ( ( ( T_3 ) V_176 . V_14 . V_189 << 16 ) |
( ( T_3 ) V_176 . V_14 . V_190 << 8 ) |
( ( T_3 ) V_176 . V_14 . V_191 ) ) ;
if ( F_111 ( & V_31 -> V_143 , V_177 ) ) {
F_132 ( 1 , L_49 ,
V_176 . V_14 . V_189 , V_176 . V_14 . V_190 , V_176 . V_14 . V_191 ) ;
F_114 ( & V_31 -> V_143 , V_177 , V_136 ) ;
} else {
F_73 ( & V_31 -> V_143 , V_177 , V_136 , V_110 ) ;
}
V_59 -> V_176 = V_176 ;
V_90 -> V_142 = V_177 ;
}
V_59 -> V_202 = V_202 ;
V_59 -> V_204 = 1 ;
V_59 -> V_205 = 0 ;
}
static int F_133 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_134 ( & V_31 -> V_143 ) ;
if ( V_25 ) {
F_50 ( L_50 ) ;
return V_25 ;
}
V_31 -> V_186 = F_135 ( sizeof( struct V_184 ) *
65536 ) ;
if ( ! V_31 -> V_186 ) {
F_50 ( L_51 ,
sizeof( struct V_184 ) * 65536 ) ;
F_136 ( & V_31 -> V_143 ) ;
return - V_172 ;
}
memset ( V_31 -> V_186 , 0 , sizeof( struct V_184 )
* 65536 ) ;
F_2 ( L_52 ,
sizeof( struct V_184 ) * 65536 ) ;
return 0 ;
}
static int F_137 ( struct V_61 * V_62 ,
void * V_178 ,
T_2 V_206 , T_2 V_207 )
{
struct V_193 * V_194 = V_62 -> V_64 ;
struct V_30 * V_31 =
(struct V_30 * ) V_178 ;
V_194 -> V_192 . V_208 = & V_209 ;
V_62 -> V_158 . V_178 = V_178 ;
V_31 -> V_154 = V_62 ;
return 0 ;
}
static struct V_137 * F_138 (
struct V_210 * V_211 ,
struct V_166 * V_167 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_165 = - V_162 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_100 ( - V_20 ) ;
V_31 = F_101 ( sizeof( struct V_30 ) , V_171 ) ;
if ( ! V_31 ) {
F_50 ( L_53 ) ;
return F_100 ( - V_172 ) ;
}
V_31 -> V_212 = V_22 ;
F_3 ( & V_31 -> V_213 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_54 , ( unsigned long long ) V_22 ) ;
V_165 = F_133 ( V_31 ) ;
if ( V_165 != 0 )
goto V_214;
V_165 = F_139 ( V_31 , V_22 , 0 , 0 ,
F_137 ) ;
if ( V_165 != 0 )
goto V_215;
return & V_31 -> V_139 ;
V_215:
F_140 ( V_31 -> V_186 ) ;
F_136 ( & V_31 -> V_143 ) ;
V_214:
F_103 ( V_31 ) ;
return F_100 ( V_165 ) ;
}
static void F_141 ( struct V_137 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_61 * V_62 = V_31 -> V_154 ;
struct V_89 * V_141 ;
T_3 V_177 = 0 ;
if ( V_62 -> V_158 . V_159 && ! V_62 -> V_158 . V_159 -> V_216 )
F_142 ( V_62 -> V_158 . V_159 ) ;
F_143 ( V_62 ) ;
F_140 ( V_31 -> V_186 ) ;
F_144 (&lport->lport_fcport_map, key, node)
F_72 ( & V_31 -> V_143 , V_177 ) ;
F_136 ( & V_31 -> V_143 ) ;
F_103 ( V_31 ) ;
}
static int F_145 ( struct V_61 * V_153 ,
void * V_178 ,
T_2 V_206 , T_2 V_207 )
{
struct V_217 * V_218 ;
struct V_219 * V_220 = V_153 -> V_221 ;
struct V_61 * V_222 ;
struct V_30 * V_31 =
(struct V_30 * ) V_178 ;
struct V_30 * V_223 =
(struct V_30 * ) V_153 -> V_158 . V_178 ;
struct V_224 V_225 ;
if ( ! F_146 ( V_153 ) ) {
F_50 ( L_55 ) ;
return - V_163 ;
}
if ( ! V_223 || ! V_223 -> V_174 ||
! F_82 ( & V_223 -> V_174 -> V_150 ) ) {
F_50 ( L_56 ) ;
return - V_163 ;
}
memset ( & V_225 , 0 , sizeof( V_225 ) ) ;
V_225 . V_197 = V_206 ;
V_225 . V_226 = V_207 ;
V_225 . V_227 = V_228 ;
V_225 . V_229 = V_230 ;
V_225 . V_231 = false ;
V_218 = F_147 ( V_220 , 0 , & V_225 ) ;
if ( ! V_218 ) {
F_50 ( L_57 ) ;
return - V_162 ;
}
V_222 = (struct V_61 * ) V_218 -> V_232 ;
V_222 -> V_158 . V_178 = V_178 ;
V_31 -> V_154 = V_222 ;
F_148 ( V_222 -> V_221 ) ;
return 0 ;
}
static struct V_137 * F_149 (
struct V_210 * V_211 ,
struct V_166 * V_167 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_233 , V_206 , V_207 ;
char * V_234 , V_235 [ 128 ] ;
int V_165 ;
snprintf ( V_235 , 128 , L_58 , V_1 ) ;
V_234 = strchr ( V_235 , '@' ) ;
if ( ! V_234 ) {
F_50 ( L_59 ) ;
return F_100 ( - V_20 ) ;
}
* V_234 ++ = '\0' ;
if ( F_1 ( V_235 , & V_233 , 1 ) < 0 )
return F_100 ( - V_20 ) ;
if ( F_9 ( V_234 , strlen ( V_234 ) + 1 ,
& V_206 , & V_207 ) < 0 )
return F_100 ( - V_20 ) ;
V_31 = F_101 ( sizeof( struct V_30 ) , V_171 ) ;
if ( ! V_31 ) {
F_50 ( L_60 ) ;
return F_100 ( - V_172 ) ;
}
V_31 -> V_236 = V_206 ;
V_31 -> V_237 = V_207 ;
sprintf ( V_31 -> V_32 , L_54 , ( unsigned long long ) V_206 ) ;
V_165 = F_133 ( V_31 ) ;
if ( V_165 != 0 )
goto V_214;
V_165 = F_139 ( V_31 , V_233 , V_206 , V_207 ,
F_145 ) ;
if ( V_165 != 0 )
goto V_215;
return & V_31 -> V_139 ;
V_215:
F_140 ( V_31 -> V_186 ) ;
F_136 ( & V_31 -> V_143 ) ;
V_214:
F_103 ( V_31 ) ;
return F_100 ( V_165 ) ;
}
static void F_150 ( struct V_137 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_61 * V_222 = V_31 -> V_154 ;
struct V_193 * V_194 = V_222 -> V_64 ;
T_7 * V_153 = F_118 ( V_194 -> V_195 ) ;
F_151 ( V_222 -> V_221 ) ;
F_152 ( V_222 -> V_217 ) ;
F_151 ( V_153 -> V_221 ) ;
F_103 ( V_31 ) ;
}
static T_1 F_153 (
struct V_210 * V_211 ,
char * V_148 )
{
return sprintf ( V_148 ,
L_61
V_238 L_62 , V_239 , F_154 () -> V_240 ,
F_154 () -> V_241 ) ;
}
static int F_155 ( void )
{
int V_165 ;
F_2 ( L_63
V_238 L_62 , V_239 , F_154 () -> V_240 ,
F_154 () -> V_241 ) ;
V_165 = F_156 ( & V_242 ) ;
if ( V_165 )
return V_165 ;
V_165 = F_156 ( & V_243 ) ;
if ( V_165 )
goto V_244;
V_47 = F_157 ( L_64 ,
V_245 , 0 ) ;
if ( ! V_47 ) {
V_165 = - V_172 ;
goto V_246;
}
V_247 = F_157 ( L_65 , 0 , 0 ) ;
if ( ! V_247 ) {
V_165 = - V_172 ;
goto V_248;
}
return 0 ;
V_248:
F_158 ( V_47 ) ;
V_246:
F_159 ( & V_243 ) ;
V_244:
F_159 ( & V_242 ) ;
return V_165 ;
}
static void F_160 ( void )
{
F_158 ( V_247 ) ;
F_158 ( V_47 ) ;
F_159 ( & V_242 ) ;
F_159 ( & V_243 ) ;
}
static int T_12 F_161 ( void )
{
int V_165 ;
V_165 = F_155 () ;
if ( V_165 < 0 )
return V_165 ;
return 0 ;
}
static void T_13 F_162 ( void )
{
F_160 () ;
}
