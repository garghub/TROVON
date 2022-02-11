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
V_63 -> V_64 = 0 ;
F_40 ( V_63 -> V_65 & V_66 ) ;
V_63 -> V_65 |= V_66 ;
F_35 ( & V_63 -> V_60 , 0 ) ;
}
static void F_41 ( struct V_62 * V_63 )
{
V_63 -> V_64 = 1 ;
F_37 ( & V_63 -> V_56 , F_39 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_42 ( struct V_60 * V_60 )
{
struct V_62 * V_63 ;
if ( ( V_60 -> V_67 & V_68 ) == 0 ) {
V_63 = F_12 ( V_60 , struct V_62 , V_60 ) ;
V_63 -> V_65 |= V_69 ;
}
return F_43 ( V_60 -> V_70 , V_60 ) ;
}
static void F_44 ( struct V_60 * V_60 )
{
struct V_62 * V_63 ;
if ( V_60 -> V_67 & V_68 ) {
struct V_57 * V_58 = F_12 ( V_60 ,
struct V_57 , V_60 ) ;
F_45 ( V_58 ) ;
return;
}
V_63 = F_12 ( V_60 , struct V_62 , V_60 ) ;
F_46 ( V_63 ) ;
}
static int F_47 ( struct V_71 * V_70 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
F_48 ( ! V_73 ) ;
V_76 = V_73 -> V_76 ;
F_49 ( & V_76 -> V_78 -> V_79 , V_77 ) ;
F_50 ( V_70 ) ;
F_51 ( & V_76 -> V_78 -> V_79 , V_77 ) ;
return 1 ;
}
static void F_52 ( struct V_71 * V_70 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
F_48 ( ! V_73 ) ;
V_76 = V_73 -> V_76 ;
F_49 ( & V_76 -> V_78 -> V_79 , V_77 ) ;
F_53 ( V_73 ) ;
F_51 ( & V_76 -> V_78 -> V_79 , V_77 ) ;
}
static T_3 F_54 ( struct V_71 * V_70 )
{
return 0 ;
}
static int F_55 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_80 = V_60 -> V_81 ;
V_63 -> V_82 = F_56 ( V_60 ) ;
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_85 = V_60 -> V_86 ;
V_63 -> V_87 = V_60 -> V_88 ;
V_63 -> V_89 = V_60 -> V_90 ;
V_63 -> V_91 = V_60 -> V_92 -> V_93 . V_94 ;
V_60 -> V_95 = 0 ;
return F_57 ( V_63 ) ;
}
static int F_58 ( struct V_60 * V_60 )
{
unsigned long V_77 ;
F_49 ( & V_60 -> V_96 , V_77 ) ;
if ( V_60 -> V_97 == V_98 ||
V_60 -> V_97 == V_99 ) {
F_51 ( & V_60 -> V_96 , V_77 ) ;
F_59 ( & V_60 -> V_100 ,
3000 ) ;
return 0 ;
}
F_51 ( & V_60 -> V_96 , V_77 ) ;
return 0 ;
}
static void F_60 ( struct V_37 * V_53 )
{
return;
}
static T_3 F_61 ( struct V_60 * V_60 )
{
struct V_62 * V_63 ;
if ( V_60 -> V_67 & V_68 )
return 0xffffffff ;
V_63 = F_12 ( V_60 , struct V_62 , V_60 ) ;
return V_63 -> V_101 ;
}
static int F_62 ( struct V_60 * V_60 )
{
return 0 ;
}
static int F_63 ( T_7 * V_76 , struct V_62 * V_63 ,
unsigned char * V_102 , T_8 V_81 , int V_103 ,
int V_104 , int V_105 )
{
struct V_60 * V_60 = & V_63 -> V_60 ;
struct V_71 * V_70 ;
struct V_72 * V_73 ;
int V_77 = V_106 ;
if ( V_105 )
V_77 |= V_107 ;
V_73 = V_63 -> V_73 ;
if ( ! V_73 ) {
F_30 ( L_6 ) ;
return - V_20 ;
}
V_70 = V_73 -> V_70 ;
if ( ! V_70 ) {
F_30 ( L_7 ) ;
return - V_20 ;
}
return F_64 ( V_60 , V_70 , V_102 , & V_63 -> V_108 [ 0 ] ,
V_63 -> V_109 , V_81 , V_103 ,
V_104 , V_77 ) ;
}
static void F_65 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_12 ( V_56 , struct V_62 , V_56 ) ;
V_63 -> V_64 = 0 ;
V_63 -> V_65 |= V_110 ;
if ( ! V_63 -> V_111 ) {
if ( V_63 -> V_60 . V_112 & V_113 ) {
F_66 ( & V_63 -> V_60 . V_100 ) ;
return;
}
if ( V_63 -> V_60 . V_95 )
F_67 ( & V_63 -> V_60 ,
V_63 -> V_60 . V_95 ) ;
else
F_67 ( & V_63 -> V_60 ,
V_114 ) ;
return;
}
return F_68 ( & V_63 -> V_60 ) ;
}
static void F_69 ( struct V_62 * V_63 )
{
V_63 -> V_65 |= V_115 ;
V_63 -> V_64 = 1 ;
F_37 ( & V_63 -> V_56 , F_65 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static void F_70 ( struct V_55 * V_56 )
{
struct V_62 * V_63 = F_12 ( V_56 , struct V_62 , V_56 ) ;
F_71 ( & V_63 -> V_60 . V_116 ) ;
F_67 ( & V_63 -> V_60 , V_63 -> V_60 . V_95 ) ;
}
static void F_72 ( struct V_62 * V_63 )
{
F_37 ( & V_63 -> V_56 , F_70 ) ;
F_38 ( V_61 , & V_63 -> V_56 ) ;
}
static int F_73 ( struct V_57 * V_58 , T_8 V_117 ,
T_9 V_118 , T_8 V_101 )
{
struct V_72 * V_73 = V_58 -> V_73 ;
struct V_60 * V_60 = & V_58 -> V_60 ;
return F_74 ( V_60 , V_73 -> V_70 , NULL , V_117 , V_58 ,
V_118 , V_119 , V_101 , V_106 ) ;
}
static int F_75 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
V_63 -> V_65 |= V_120 ;
V_63 -> V_80 = V_60 -> V_81 ;
V_63 -> V_82 = F_56 ( V_60 ) ;
V_63 -> V_121 = ( V_60 -> V_112 & V_113 ) ;
V_63 -> V_83 = V_60 -> V_84 ;
V_63 -> V_85 = V_60 -> V_86 ;
V_63 -> V_122 = 0 ;
V_63 -> V_65 |= V_123 ;
V_63 -> V_87 = V_60 -> V_88 ;
V_63 -> V_89 = V_60 -> V_90 ;
V_63 -> V_91 = V_60 -> V_92 -> V_93 . V_94 ;
V_60 -> V_95 = 0 ;
return F_76 ( V_63 , V_124 | V_125 ,
V_60 -> V_126 ) ;
}
static int F_77 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
int V_127 = V_125 ;
V_63 -> V_80 = V_60 -> V_81 ;
V_63 -> V_85 = NULL ;
V_63 -> V_83 = 0 ;
V_63 -> V_122 = 0 ;
V_63 -> V_82 = F_56 ( V_60 ) ;
V_63 -> V_121 = ( V_60 -> V_112 & V_113 ) ;
if ( V_63 -> V_65 & V_128 ) {
F_78 ( L_8 , V_63 ) ;
F_79 () ;
}
V_63 -> V_65 |= V_128 ;
if ( V_60 -> V_129 == V_130 ) {
if ( V_60 -> V_67 & V_131 ) {
V_60 -> V_67 &= ~ V_131 ;
V_60 -> V_132 = 0 ;
}
V_60 -> V_67 |= V_133 ;
V_60 -> V_132 += V_60 -> V_81 ;
V_63 -> V_80 = 0 ;
}
return F_76 ( V_63 , V_127 , V_60 -> V_126 ) ;
}
static void F_80 ( struct V_60 * V_60 )
{
struct V_134 * V_135 = V_60 -> V_134 ;
struct V_57 * V_58 = F_12 ( V_60 ,
struct V_57 , V_60 ) ;
F_2 ( L_9 ,
V_58 , V_135 -> V_136 , V_135 -> V_137 ) ;
switch ( V_135 -> V_137 ) {
case V_138 :
V_58 -> V_139 = V_140 ;
break;
case V_141 :
V_58 -> V_139 = V_142 ;
break;
case V_143 :
V_58 -> V_139 = V_144 ;
break;
case V_145 :
default:
V_58 -> V_139 = V_146 ;
break;
}
F_81 ( V_58 ) ;
}
static void F_82 ( struct V_60 * V_60 )
{
struct V_62 * V_63 = F_12 ( V_60 ,
struct V_62 , V_60 ) ;
struct V_75 * V_76 = V_63 -> V_76 ;
struct V_147 * V_148 = V_76 -> V_78 ;
if ( ! V_63 -> V_149 )
return;
F_83 ( V_148 -> V_150 , V_63 -> V_85 , V_63 -> V_83 , V_63 -> V_82 ) ;
V_63 -> V_149 = 0 ;
}
static void F_84 ( struct V_72 * V_73 )
{
struct V_37 * V_38 = V_73 -> V_70 -> V_37 ;
struct V_26 * V_27 = V_38 -> V_27 ;
struct V_151 * V_151 = V_27 -> V_152 ;
struct V_30 * V_31 = F_12 ( V_151 ,
struct V_30 , V_153 ) ;
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
void * V_154 ;
F_2 ( L_10 , V_53 -> V_155 ) ;
V_154 = F_85 ( & V_31 -> V_156 , V_53 -> V_155 ) ;
if ( F_40 ( V_154 && ( V_154 != V_38 ) ) ) {
F_86 ( & V_31 -> V_156 , V_53 -> V_155 ,
V_154 , V_119 ) ;
}
F_2 ( L_11 ,
V_38 , V_53 -> V_157 , V_53 -> V_155 ) ;
F_87 ( V_31 , V_53 , V_73 ) ;
}
static void F_88 ( struct V_158 * V_158 )
{
struct V_71 * V_70 = F_12 ( V_158 ,
struct V_71 , V_159 ) ;
F_53 ( V_70 -> V_74 ) ;
}
static void F_89 ( struct V_71 * V_70 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_147 * V_148 = V_73 -> V_76 -> V_78 ;
unsigned long V_77 ;
F_49 ( & V_148 -> V_79 , V_77 ) ;
F_90 ( & V_70 -> V_159 , F_88 ) ;
F_51 ( & V_148 -> V_79 , V_77 ) ;
}
static void F_91 ( struct V_72 * V_73 )
{
if ( ! V_73 )
return;
F_92 ( & V_73 -> V_76 -> V_78 -> V_79 ) ;
F_90 ( & V_73 -> V_70 -> V_159 , F_88 ) ;
}
static void F_93 ( struct V_72 * V_73 )
{
F_92 ( & V_73 -> V_76 -> V_78 -> V_79 ) ;
F_50 ( V_73 -> V_70 ) ;
}
static struct V_37 * F_94 (
struct V_26 * V_27 ,
struct V_160 * V_161 ,
const char * V_1 )
{
struct V_37 * V_38 , * V_162 ;
struct V_52 * V_53 ;
T_2 V_23 ;
T_3 V_163 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return F_95 ( - V_20 ) ;
V_162 = F_28 ( V_27 ) ;
if ( ! V_162 )
return F_95 ( - V_164 ) ;
V_163 = 1 ;
V_38 = F_96 ( V_27 , V_162 ,
V_1 , V_163 ) ;
if ( F_97 ( V_38 ) ) {
F_31 ( V_27 , V_162 ) ;
return V_38 ;
}
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
V_53 -> V_157 = V_23 ;
F_3 ( & V_53 -> V_165 [ 0 ] , V_10 , V_23 ) ;
return V_38 ;
}
static void F_98 ( struct V_37 * V_166 )
{
struct V_26 * V_27 = V_166 -> V_27 ;
struct V_52 * V_53 = F_12 ( V_166 ,
struct V_52 , V_37 ) ;
F_99 ( V_27 , V_166 , 1 ) ;
F_32 ( V_53 ) ;
}
static T_1 F_100 (
struct V_26 * V_27 ,
char * V_167 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_167 , V_168 , L_12 ,
F_101 ( & V_29 -> V_169 ) ) ;
}
static void F_102 ( struct V_55 * V_56 )
{
struct V_28 * V_170 = F_12 ( V_56 ,
struct V_28 , V_171 ) ;
struct V_26 * V_27 = & V_170 -> V_27 ;
struct V_75 * V_172 = V_170 -> V_31 -> V_173 ;
if ( ! F_103 ( V_27 -> V_174 -> V_175 ,
& V_27 -> V_176 . V_177 ) ) {
F_104 ( & V_170 -> V_169 , 1 ) ;
F_105 ( V_172 ) ;
}
F_66 ( & V_170 -> V_178 ) ;
}
static void F_106 ( struct V_55 * V_56 )
{
struct V_28 * V_170 = F_12 ( V_56 ,
struct V_28 , V_171 ) ;
struct V_26 * V_27 = & V_170 -> V_27 ;
struct V_75 * V_172 = V_170 -> V_31 -> V_173 ;
if ( ! F_107 ( V_172 -> V_179 . V_180 ) ) {
F_104 ( & V_170 -> V_169 , 0 ) ;
F_108 ( V_27 -> V_174 -> V_175 ,
& V_27 -> V_176 . V_177 ) ;
}
F_66 ( & V_170 -> V_178 ) ;
}
static T_1 F_109 (
struct V_26 * V_27 ,
const char * V_167 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_181 ;
int V_25 ;
V_25 = F_110 ( V_167 , 0 , & V_181 ) ;
if ( V_25 < 0 ) {
F_30 ( L_13 , V_25 ) ;
return - V_20 ;
}
if ( ( V_181 != 1 ) && ( V_181 != 0 ) ) {
F_30 ( L_14 , V_181 ) ;
return - V_20 ;
}
if ( V_181 ) {
if ( F_101 ( & V_29 -> V_169 ) )
return - V_182 ;
F_37 ( & V_29 -> V_171 , F_102 ) ;
} else {
if ( ! F_101 ( & V_29 -> V_169 ) )
return V_21 ;
F_37 ( & V_29 -> V_171 , F_106 ) ;
}
F_111 ( & V_29 -> V_178 ) ;
F_112 ( & V_29 -> V_171 ) ;
F_113 ( & V_29 -> V_178 ) ;
if ( V_181 ) {
if ( ! F_101 ( & V_29 -> V_169 ) )
return - V_183 ;
} else {
if ( F_101 ( & V_29 -> V_169 ) )
return - V_184 ;
}
return V_21 ;
}
static struct V_26 * F_114 (
struct V_151 * V_2 ,
struct V_160 * V_161 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_153 ) ;
struct V_28 * V_29 ;
unsigned long V_185 ;
int V_42 ;
if ( strstr ( V_1 , L_15 ) != V_1 )
return F_95 ( - V_20 ) ;
if ( F_110 ( V_1 + 5 , 10 , & V_185 ) || V_185 > V_186 )
return F_95 ( - V_20 ) ;
if ( ( V_185 != 1 ) ) {
F_30 ( L_16 ) ;
return F_95 ( - V_187 ) ;
}
V_29 = F_29 ( sizeof( struct V_28 ) , V_54 ) ;
if ( ! V_29 ) {
F_30 ( L_17 ) ;
return F_95 ( - V_164 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_185 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_115 ( & V_188 -> V_189 , V_2 ,
& V_29 -> V_27 , V_29 , V_190 ) ;
if ( V_42 < 0 ) {
F_32 ( V_29 ) ;
return NULL ;
}
V_31 -> V_191 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_116 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_75 * V_76 = V_31 -> V_173 ;
if ( V_76 -> V_179 . V_180 && ! V_76 -> V_179 . V_180 -> V_192 )
F_107 ( V_76 -> V_179 . V_180 ) ;
F_117 ( V_27 ) ;
V_31 -> V_191 = NULL ;
F_32 ( V_29 ) ;
}
static T_1 F_118 (
struct V_26 * V_27 ,
char * V_167 )
{
return F_100 ( V_27 , V_167 ) ;
}
static T_1 F_119 (
struct V_26 * V_27 ,
const char * V_167 ,
T_4 V_21 )
{
struct V_151 * V_151 = V_27 -> V_152 ;
struct V_30 * V_31 = F_12 ( V_151 ,
struct V_30 , V_153 ) ;
struct V_75 * V_76 = V_31 -> V_173 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_181 ;
int V_25 ;
V_25 = F_110 ( V_167 , 0 , & V_181 ) ;
if ( V_25 < 0 ) {
F_30 ( L_13 , V_25 ) ;
return - V_20 ;
}
if ( ( V_181 != 1 ) && ( V_181 != 0 ) ) {
F_30 ( L_14 , V_181 ) ;
return - V_20 ;
}
if ( V_181 ) {
if ( F_101 ( & V_29 -> V_169 ) )
return - V_182 ;
F_104 ( & V_29 -> V_169 , 1 ) ;
F_105 ( V_76 ) ;
} else {
if ( ! F_101 ( & V_29 -> V_169 ) )
return V_21 ;
F_104 ( & V_29 -> V_169 , 0 ) ;
F_107 ( V_76 -> V_179 . V_180 ) ;
}
return V_21 ;
}
static struct V_26 * F_120 (
struct V_151 * V_2 ,
struct V_160 * V_161 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_153 ) ;
struct V_28 * V_29 ;
unsigned long V_185 ;
int V_42 ;
if ( strstr ( V_1 , L_15 ) != V_1 )
return F_95 ( - V_20 ) ;
if ( F_110 ( V_1 + 5 , 10 , & V_185 ) || V_185 > V_186 )
return F_95 ( - V_20 ) ;
V_29 = F_29 ( sizeof( struct V_28 ) , V_54 ) ;
if ( ! V_29 ) {
F_30 ( L_17 ) ;
return F_95 ( - V_164 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_185 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_115 ( & V_193 -> V_189 , V_2 ,
& V_29 -> V_27 , V_29 , V_190 ) ;
if ( V_42 < 0 ) {
F_32 ( V_29 ) ;
return NULL ;
}
V_31 -> V_191 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_72 * F_121 (
T_7 * V_76 ,
const T_9 * V_194 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
T_3 V_195 ;
V_31 = V_76 -> V_179 . V_196 ;
if ( ! V_31 ) {
F_30 ( L_18 ) ;
F_79 () ;
return NULL ;
}
V_195 = ( ( ( unsigned long ) V_194 [ 0 ] << 16 ) |
( ( unsigned long ) V_194 [ 1 ] << 8 ) |
( unsigned long ) V_194 [ 2 ] ) ;
F_2 ( L_19 , V_195 ) ;
V_38 = F_122 ( & V_31 -> V_156 , V_195 ) ;
if ( ! V_38 ) {
F_2 ( L_20 , V_195 ) ;
return NULL ;
}
F_2 ( L_21 ,
V_38 , V_38 -> V_197 ) ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
if ( ! V_53 -> V_72 ) {
F_30 ( L_22 ) ;
return NULL ;
}
return V_53 -> V_72 ;
}
static void F_123 (
struct V_30 * V_31 ,
struct V_37 * V_198 ,
struct V_52 * V_53 ,
struct V_71 * V_70 ,
struct V_72 * V_72 ,
T_9 * V_194 )
{
T_3 V_195 ;
void * V_199 ;
int V_25 ;
V_195 = ( ( ( unsigned long ) V_194 [ 0 ] << 16 ) |
( ( unsigned long ) V_194 [ 1 ] << 8 ) |
( unsigned long ) V_194 [ 2 ] ) ;
F_2 ( L_23 , V_195 ) ;
V_199 = F_122 ( & V_31 -> V_156 , V_195 ) ;
if ( ! V_199 ) {
if ( V_198 ) {
F_2 ( L_24 ) ;
V_53 -> V_155 = V_195 ;
V_25 = F_86 ( & V_31 -> V_156 , V_195 ,
V_198 , V_119 ) ;
if ( V_25 )
F_124 ( V_200 L_25 ,
( int ) V_195 ) ;
} else {
F_2 ( L_26 ) ;
}
V_72 -> V_70 = V_70 ;
V_53 -> V_72 = V_72 ;
return;
}
if ( V_53 -> V_72 ) {
if ( V_198 == NULL ) {
F_2 ( L_27 ) ;
F_85 ( & V_31 -> V_156 , V_195 ) ;
V_53 -> V_72 = NULL ;
return;
}
F_2 ( L_28 ) ;
F_125 ( & V_31 -> V_156 , V_195 , V_198 ) ;
V_72 -> V_70 = V_70 ;
V_53 -> V_72 = V_72 ;
return;
}
if ( V_198 == NULL ) {
F_2 ( L_29 ) ;
F_85 ( & V_31 -> V_156 , V_195 ) ;
return;
}
F_2 ( L_30 ) ;
F_125 ( & V_31 -> V_156 , V_195 , V_198 ) ;
V_72 -> V_70 = V_70 ;
V_53 -> V_72 = V_72 ;
F_2 ( L_31 ,
V_53 -> V_72 , V_198 , V_198 -> V_197 ) ;
}
static struct V_72 * F_126 (
T_7 * V_76 ,
const T_10 V_201 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
struct V_202 * V_203 ;
V_31 = V_76 -> V_179 . V_196 ;
if ( ! V_31 ) {
F_30 ( L_18 ) ;
F_79 () ;
return NULL ;
}
F_2 ( L_32 , V_201 ) ;
V_203 = V_31 -> V_204 + V_201 ;
V_38 = V_203 -> V_38 ;
if ( ! V_38 ) {
F_2 ( L_33 ,
V_201 ) ;
return NULL ;
}
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
if ( ! V_53 -> V_72 ) {
F_30 ( L_22 ) ;
return NULL ;
}
return V_53 -> V_72 ;
}
static void F_127 (
struct V_30 * V_31 ,
struct V_37 * V_198 ,
struct V_52 * V_53 ,
struct V_71 * V_70 ,
struct V_72 * V_72 ,
T_10 V_201 )
{
struct V_37 * V_205 ;
struct V_202 * V_203 ;
F_2 ( L_34 , V_201 ) ;
V_203 = & ( (struct V_202 * )
V_31 -> V_204 ) [ V_201 ] ;
V_205 = V_203 -> V_38 ;
if ( ! V_205 ) {
F_2 ( L_35 ) ;
V_203 -> V_38 = V_198 ;
if ( V_72 -> V_70 != V_70 )
V_72 -> V_70 = V_70 ;
if ( V_53 -> V_72 != V_72 )
V_53 -> V_72 = V_72 ;
return;
}
if ( V_53 -> V_72 ) {
if ( V_198 == NULL ) {
F_2 ( L_36 ) ;
V_203 -> V_38 = NULL ;
V_53 -> V_72 = NULL ;
return;
}
F_2 ( L_37 ) ;
V_203 -> V_38 = V_198 ;
if ( V_72 -> V_70 != V_70 )
V_72 -> V_70 = V_70 ;
if ( V_53 -> V_72 != V_72 )
V_53 -> V_72 = V_72 ;
return;
}
if ( V_198 == NULL ) {
F_2 ( L_38 ) ;
V_203 -> V_38 = NULL ;
return;
}
F_2 ( L_39 ) ;
V_203 -> V_38 = V_198 ;
if ( V_72 -> V_70 != V_70 )
V_72 -> V_70 = V_70 ;
if ( V_53 -> V_72 != V_72 )
V_53 -> V_72 = V_72 ;
F_2 ( L_40 ,
V_53 -> V_72 , V_198 , V_198 -> V_197 ) ;
}
static void F_87 ( struct V_30 * V_31 ,
struct V_52 * V_53 , struct V_72 * V_73 )
{
struct V_71 * V_70 = V_73 -> V_70 ;
unsigned char V_206 [ 3 ] ;
V_206 [ 0 ] = V_73 -> V_194 . V_14 . V_207 ;
V_206 [ 1 ] = V_73 -> V_194 . V_14 . V_208 ;
V_206 [ 2 ] = V_73 -> V_194 . V_14 . V_209 ;
F_123 ( V_31 , NULL , V_53 , V_70 ,
V_73 , V_206 ) ;
F_127 ( V_31 , NULL , V_53 , V_70 ,
V_73 , V_73 -> V_201 ) ;
}
static void F_128 ( struct V_72 * V_73 )
{
struct V_180 * V_210 = V_73 -> V_210 ;
struct V_147 * V_148 = V_210 -> V_148 ;
T_7 * V_76 = F_129 ( V_148 -> V_150 ) ;
struct V_71 * V_70 ;
struct V_37 * V_38 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
F_48 ( F_130 () ) ;
V_70 = V_73 -> V_70 ;
if ( ! V_70 ) {
F_30 ( L_41 ) ;
F_79 () ;
return;
}
V_38 = V_70 -> V_37 ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
V_31 = V_76 -> V_179 . V_196 ;
if ( ! V_31 ) {
F_30 ( L_18 ) ;
F_79 () ;
return;
}
F_131 ( V_70 ) ;
F_132 ( V_73 -> V_70 ) ;
F_133 ( V_73 -> V_70 ) ;
}
static int F_134 (
T_7 * V_76 ,
unsigned char * V_211 ,
void * V_72 ,
T_9 * V_194 ,
T_10 V_201 )
{
struct V_147 * V_148 = V_76 -> V_78 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_52 * V_53 ;
struct V_26 * V_27 ;
struct V_37 * V_38 ;
struct V_71 * V_70 ;
struct V_72 * V_73 = V_72 ;
unsigned char V_212 [ 36 ] ;
unsigned long V_77 ;
int V_213 = ( V_148 -> V_214 ) ? V_148 -> V_214 :
V_215 ;
V_31 = V_76 -> V_179 . V_196 ;
if ( ! V_31 ) {
F_30 ( L_18 ) ;
F_79 () ;
return - V_20 ;
}
V_29 = V_31 -> V_191 ;
if ( ! V_29 ) {
F_30 ( L_42 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_70 = F_135 ( V_213 ,
sizeof( struct V_62 ) ,
V_216 ) ;
if ( F_97 ( V_70 ) ) {
F_30 ( L_43 ) ;
return F_136 ( V_70 ) ;
}
memset ( & V_212 , 0 , 36 ) ;
snprintf ( V_212 , sizeof( V_212 ) , L_44 , V_211 ) ;
V_70 -> V_37 = F_137 ( V_27 ,
V_212 ) ;
if ( ! V_70 -> V_37 ) {
F_138 ( V_70 ) ;
return - V_20 ;
}
V_38 = V_70 -> V_37 ;
V_53 = F_12 ( V_38 , struct V_52 , V_37 ) ;
F_49 ( & V_148 -> V_79 , V_77 ) ;
F_123 ( V_31 , V_38 , V_53 , V_70 ,
V_72 , V_194 ) ;
F_127 ( V_31 , V_38 , V_53 , V_70 ,
V_72 , V_201 ) ;
F_51 ( & V_148 -> V_79 , V_77 ) ;
F_139 ( V_38 -> V_27 , V_38 , V_70 , V_73 ) ;
return 0 ;
}
static void F_140 ( struct V_72 * V_73 , T_11 V_194 ,
T_10 V_201 , bool V_217 )
{
struct V_180 * V_210 = V_73 -> V_210 ;
struct V_147 * V_148 = V_210 -> V_148 ;
T_7 * V_76 = F_129 ( V_148 -> V_150 ) ;
struct V_30 * V_31 = V_76 -> V_179 . V_196 ;
struct V_37 * V_38 = V_73 -> V_70 -> V_37 ;
struct V_52 * V_53 = F_12 ( V_38 ,
struct V_52 , V_37 ) ;
T_3 V_195 ;
if ( V_73 -> V_201 != V_201 || V_73 -> V_194 . V_218 != V_194 . V_218 )
F_141 ( L_45 ,
V_73 , V_73 -> V_212 ,
V_73 -> V_201 , V_201 , V_73 -> V_194 . V_14 . V_207 ,
V_73 -> V_194 . V_14 . V_208 , V_73 -> V_194 . V_14 . V_209 , V_194 . V_14 . V_207 ,
V_194 . V_14 . V_208 , V_194 . V_14 . V_209 ) ;
if ( V_73 -> V_201 != V_201 ) {
if ( V_31 -> V_204 [ V_73 -> V_201 ] . V_38 == V_38 )
V_31 -> V_204 [ V_73 -> V_201 ] . V_38 = NULL ;
V_31 -> V_204 [ V_201 ] . V_38 = V_38 ;
V_73 -> V_201 = V_201 ;
}
if ( V_73 -> V_194 . V_218 != V_194 . V_218 ) {
V_195 = ( ( ( T_3 ) V_73 -> V_194 . V_14 . V_207 << 16 ) |
( ( T_3 ) V_73 -> V_194 . V_14 . V_208 << 8 ) |
( ( T_3 ) V_73 -> V_194 . V_14 . V_209 ) ) ;
if ( F_122 ( & V_31 -> V_156 , V_195 ) )
F_142 ( F_85 ( & V_31 -> V_156 , V_195 ) != V_38 ,
L_46 ,
V_73 -> V_194 . V_14 . V_207 , V_73 -> V_194 . V_14 . V_208 , V_73 -> V_194 . V_14 . V_209 ) ;
else
F_142 ( 1 , L_47 ,
V_73 -> V_194 . V_14 . V_207 , V_73 -> V_194 . V_14 . V_208 , V_73 -> V_194 . V_14 . V_209 ) ;
V_195 = ( ( ( T_3 ) V_194 . V_14 . V_207 << 16 ) |
( ( T_3 ) V_194 . V_14 . V_208 << 8 ) |
( ( T_3 ) V_194 . V_14 . V_209 ) ) ;
if ( F_122 ( & V_31 -> V_156 , V_195 ) ) {
F_142 ( 1 , L_48 ,
V_194 . V_14 . V_207 , V_194 . V_14 . V_208 , V_194 . V_14 . V_209 ) ;
F_125 ( & V_31 -> V_156 , V_195 , V_38 ) ;
} else {
F_86 ( & V_31 -> V_156 , V_195 , V_38 , V_119 ) ;
}
V_73 -> V_194 = V_194 ;
V_53 -> V_155 = V_195 ;
}
V_73 -> V_217 = V_217 ;
}
static int F_143 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_144 ( & V_31 -> V_156 ) ;
if ( V_25 ) {
F_30 ( L_49 ) ;
return V_25 ;
}
V_31 -> V_204 = F_145 ( sizeof( struct V_202 ) *
65536 ) ;
if ( ! V_31 -> V_204 ) {
F_30 ( L_50 ,
sizeof( struct V_202 ) * 65536 ) ;
F_146 ( & V_31 -> V_156 ) ;
return - V_164 ;
}
memset ( V_31 -> V_204 , 0 , sizeof( struct V_202 )
* 65536 ) ;
F_2 ( L_51 ,
sizeof( struct V_202 ) * 65536 ) ;
return 0 ;
}
static int F_147 ( struct V_75 * V_76 ,
void * V_196 ,
T_2 V_219 , T_2 V_220 )
{
struct V_147 * V_148 = V_76 -> V_78 ;
struct V_30 * V_31 =
(struct V_30 * ) V_196 ;
V_148 -> V_210 . V_221 = & V_222 ;
V_76 -> V_179 . V_196 = V_196 ;
V_31 -> V_173 = V_76 ;
return 0 ;
}
static struct V_151 * F_148 (
struct V_223 * V_224 ,
struct V_160 * V_161 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_42 = - V_183 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_95 ( - V_20 ) ;
V_31 = F_29 ( sizeof( struct V_30 ) , V_54 ) ;
if ( ! V_31 ) {
F_30 ( L_52 ) ;
return F_95 ( - V_164 ) ;
}
V_31 -> V_225 = V_22 ;
F_3 ( & V_31 -> V_226 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_35 , L_53 , ( unsigned long long ) V_22 ) ;
V_42 = F_143 ( V_31 ) ;
if ( V_42 != 0 )
goto V_227;
V_42 = F_149 ( V_31 , V_22 , 0 , 0 ,
F_147 ) ;
if ( V_42 != 0 )
goto V_228;
return & V_31 -> V_153 ;
V_228:
F_150 ( V_31 -> V_204 ) ;
F_146 ( & V_31 -> V_156 ) ;
V_227:
F_32 ( V_31 ) ;
return F_95 ( V_42 ) ;
}
static void F_151 ( struct V_151 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_153 ) ;
struct V_75 * V_76 = V_31 -> V_173 ;
struct V_37 * V_154 ;
T_3 V_195 = 0 ;
if ( V_76 -> V_179 . V_180 && ! V_76 -> V_179 . V_180 -> V_229 )
F_152 ( V_76 -> V_179 . V_180 ) ;
F_153 ( V_76 ) ;
F_150 ( V_31 -> V_204 ) ;
F_154 (&lport->lport_fcport_map, key, node)
F_85 ( & V_31 -> V_156 , V_195 ) ;
F_146 ( & V_31 -> V_156 ) ;
F_32 ( V_31 ) ;
}
static int F_155 ( struct V_75 * V_172 ,
void * V_196 ,
T_2 V_219 , T_2 V_220 )
{
struct V_230 * V_231 ;
struct V_232 * V_233 = V_172 -> V_234 ;
struct V_75 * V_235 ;
struct V_30 * V_31 =
(struct V_30 * ) V_196 ;
struct V_30 * V_236 =
(struct V_30 * ) V_172 -> V_179 . V_196 ;
struct V_28 * V_170 ;
struct V_237 V_238 ;
if ( ! F_156 ( V_172 ) ) {
F_30 ( L_54 ) ;
return - V_184 ;
}
if ( ! V_236 || ! V_236 -> V_191 ||
! F_101 ( & V_236 -> V_191 -> V_169 ) ) {
F_30 ( L_55 ) ;
return - V_184 ;
}
V_170 = V_236 -> V_191 ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_212 = V_219 ;
V_238 . V_239 = V_220 ;
V_238 . V_240 = V_241 ;
V_238 . V_242 = V_243 ;
V_238 . V_244 = false ;
V_231 = F_157 ( V_233 , 0 , & V_238 ) ;
if ( ! V_231 ) {
F_30 ( L_56 ) ;
return - V_183 ;
}
V_235 = (struct V_75 * ) V_231 -> V_245 ;
V_235 -> V_179 . V_196 = V_196 ;
V_31 -> V_173 = V_235 ;
F_158 ( V_235 -> V_234 ) ;
return 0 ;
}
static struct V_151 * F_159 (
struct V_223 * V_224 ,
struct V_160 * V_161 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_246 , V_219 , V_220 ;
char * V_247 , V_248 [ 128 ] ;
int V_42 ;
snprintf ( V_248 , 128 , L_57 , V_1 ) ;
V_247 = strchr ( V_248 , '@' ) ;
if ( ! V_247 ) {
F_30 ( L_58 ) ;
return F_95 ( - V_20 ) ;
}
* V_247 ++ = '\0' ;
if ( F_1 ( V_248 , & V_246 , 1 ) < 0 )
return F_95 ( - V_20 ) ;
if ( F_9 ( V_247 , strlen ( V_247 ) + 1 ,
& V_219 , & V_220 ) < 0 )
return F_95 ( - V_20 ) ;
V_31 = F_29 ( sizeof( struct V_30 ) , V_54 ) ;
if ( ! V_31 ) {
F_30 ( L_59 ) ;
return F_95 ( - V_164 ) ;
}
V_31 -> V_249 = V_219 ;
V_31 -> V_250 = V_220 ;
sprintf ( V_31 -> V_35 , L_53 , ( unsigned long long ) V_219 ) ;
V_42 = F_143 ( V_31 ) ;
if ( V_42 != 0 )
goto V_227;
V_42 = F_149 ( V_31 , V_246 , V_219 , V_220 ,
F_155 ) ;
if ( V_42 != 0 )
goto V_228;
return & V_31 -> V_153 ;
V_228:
F_150 ( V_31 -> V_204 ) ;
F_146 ( & V_31 -> V_156 ) ;
V_227:
F_32 ( V_31 ) ;
return F_95 ( V_42 ) ;
}
static void F_160 ( struct V_151 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_153 ) ;
struct V_75 * V_235 = V_31 -> V_173 ;
struct V_147 * V_148 = V_235 -> V_78 ;
T_7 * V_172 = F_129 ( V_148 -> V_150 ) ;
F_161 ( V_235 -> V_234 ) ;
F_162 ( V_235 -> V_230 ) ;
F_161 ( V_172 -> V_234 ) ;
F_32 ( V_31 ) ;
}
static T_1 F_163 (
struct V_223 * V_224 ,
char * V_167 )
{
return sprintf ( V_167 ,
L_60
V_251 L_61 , V_252 , F_164 () -> V_253 ,
F_164 () -> V_254 ) ;
}
static int F_165 ( void )
{
struct V_223 * V_255 , * V_256 ;
int V_42 ;
F_2 ( L_62
V_251 L_61 , V_252 , F_164 () -> V_253 ,
F_164 () -> V_254 ) ;
V_255 = F_166 ( V_257 , L_3 ) ;
if ( F_97 ( V_255 ) ) {
F_30 ( L_63 ) ;
return F_136 ( V_255 ) ;
}
V_255 -> V_189 = V_258 ;
V_255 -> V_259 . V_260 . V_261 = V_262 ;
V_255 -> V_259 . V_263 . V_261 = V_264 ;
V_255 -> V_259 . V_265 . V_261 =
V_266 ;
V_255 -> V_259 . V_267 . V_261 = NULL ;
V_255 -> V_259 . V_268 . V_261 = NULL ;
V_255 -> V_259 . V_269 . V_261 = NULL ;
V_255 -> V_259 . V_270 . V_261 = NULL ;
V_255 -> V_259 . V_271 . V_261 = NULL ;
V_255 -> V_259 . V_272 . V_261 = NULL ;
V_42 = F_167 ( V_255 ) ;
if ( V_42 < 0 ) {
F_30 ( L_64 ) ;
return V_42 ;
}
V_188 = V_255 ;
F_2 ( L_65 ) ;
V_256 = F_166 ( V_257 , L_4 ) ;
if ( F_97 ( V_256 ) ) {
F_30 ( L_63 ) ;
V_42 = F_136 ( V_256 ) ;
goto V_273;
}
V_256 -> V_189 = V_274 ;
V_256 -> V_259 . V_260 . V_261 = V_262 ;
V_256 -> V_259 . V_263 . V_261 =
V_275 ;
V_256 -> V_259 . V_265 . V_261 = NULL ;
V_256 -> V_259 . V_267 . V_261 = NULL ;
V_256 -> V_259 . V_268 . V_261 = NULL ;
V_256 -> V_259 . V_269 . V_261 = NULL ;
V_256 -> V_259 . V_270 . V_261 = NULL ;
V_256 -> V_259 . V_271 . V_261 = NULL ;
V_256 -> V_259 . V_272 . V_261 = NULL ;
V_42 = F_167 ( V_256 ) ;
if ( V_42 < 0 ) {
F_30 ( L_64 ) ;
goto V_273;
}
V_193 = V_256 ;
F_2 ( L_66 ) ;
V_61 = F_168 ( L_67 ,
V_276 , 0 ) ;
if ( ! V_61 ) {
V_42 = - V_164 ;
goto V_277;
}
V_278 = F_168 ( L_68 , 0 , 0 ) ;
if ( ! V_278 ) {
V_42 = - V_164 ;
goto V_279;
}
return 0 ;
V_279:
F_169 ( V_61 ) ;
V_277:
F_170 ( V_193 ) ;
V_273:
F_170 ( V_188 ) ;
return V_42 ;
}
static void F_171 ( void )
{
F_169 ( V_278 ) ;
F_169 ( V_61 ) ;
F_170 ( V_188 ) ;
V_188 = NULL ;
F_2 ( L_69 ) ;
F_170 ( V_193 ) ;
V_193 = NULL ;
F_2 ( L_70 ) ;
}
static int T_12 F_172 ( void )
{
int V_42 ;
V_42 = F_165 () ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static void T_13 F_173 ( void )
{
F_171 () ;
}
