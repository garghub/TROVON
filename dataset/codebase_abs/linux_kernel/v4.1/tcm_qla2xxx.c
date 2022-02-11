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
static int F_28 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_46 . V_52 ;
}
static struct V_37 * F_29 (
struct V_26 * V_27 )
{
struct V_53 * V_54 ;
V_54 = F_30 ( sizeof( struct V_53 ) , V_55 ) ;
if ( ! V_54 ) {
F_31 ( L_5 ) ;
return NULL ;
}
return & V_54 -> V_37 ;
}
static void F_32 (
struct V_26 * V_27 ,
struct V_37 * V_38 )
{
struct V_53 * V_54 = F_12 ( V_38 ,
struct V_53 , V_37 ) ;
F_33 ( V_54 ) ;
}
static T_3 F_34 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_36 ;
}
static void F_35 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_12 ( V_57 ,
struct V_58 , V_60 ) ;
F_36 ( & V_59 -> V_61 , 0 ) ;
}
static void F_37 ( struct V_58 * V_59 )
{
F_38 ( & V_59 -> V_60 , F_35 ) ;
F_39 ( V_62 , & V_59 -> V_60 ) ;
}
static void F_40 ( struct V_56 * V_57 )
{
struct V_63 * V_64 = F_12 ( V_57 , struct V_63 , V_57 ) ;
V_64 -> V_65 = 0 ;
F_41 ( V_64 -> V_66 & V_67 ) ;
V_64 -> V_66 |= V_67 ;
F_36 ( & V_64 -> V_61 , 0 ) ;
}
static void F_42 ( struct V_63 * V_64 )
{
V_64 -> V_65 = 1 ;
F_38 ( & V_64 -> V_57 , F_40 ) ;
F_39 ( V_62 , & V_64 -> V_57 ) ;
}
static int F_43 ( struct V_61 * V_61 )
{
struct V_63 * V_64 ;
if ( ( V_61 -> V_68 & V_69 ) == 0 ) {
V_64 = F_12 ( V_61 , struct V_63 , V_61 ) ;
V_64 -> V_66 |= V_70 ;
}
return F_44 ( V_61 -> V_71 , V_61 ) ;
}
static void F_45 ( struct V_61 * V_61 )
{
struct V_63 * V_64 ;
if ( V_61 -> V_68 & V_69 ) {
struct V_58 * V_59 = F_12 ( V_61 ,
struct V_58 , V_61 ) ;
F_46 ( V_59 ) ;
return;
}
V_64 = F_12 ( V_61 , struct V_63 , V_61 ) ;
F_47 ( V_64 ) ;
}
static int F_48 ( struct V_72 * V_71 )
{
struct V_73 * V_74 = V_71 -> V_75 ;
struct V_76 * V_77 ;
unsigned long V_78 ;
F_49 ( ! V_74 ) ;
V_77 = V_74 -> V_77 ;
F_50 ( & V_77 -> V_79 -> V_80 , V_78 ) ;
F_51 ( V_71 ) ;
F_52 ( & V_77 -> V_79 -> V_80 , V_78 ) ;
return 1 ;
}
static void F_53 ( struct V_72 * V_71 )
{
struct V_73 * V_74 = V_71 -> V_75 ;
struct V_76 * V_77 ;
unsigned long V_78 ;
F_49 ( ! V_74 ) ;
V_77 = V_74 -> V_77 ;
F_50 ( & V_77 -> V_79 -> V_80 , V_78 ) ;
F_54 ( V_74 ) ;
F_52 ( & V_77 -> V_79 -> V_80 , V_78 ) ;
}
static T_3 F_55 ( struct V_72 * V_71 )
{
return 0 ;
}
static int F_56 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_12 ( V_61 ,
struct V_63 , V_61 ) ;
V_64 -> V_81 = V_61 -> V_82 ;
V_64 -> V_83 = F_57 ( V_61 ) ;
V_64 -> V_84 = V_61 -> V_85 ;
V_64 -> V_86 = V_61 -> V_87 ;
V_64 -> V_88 = V_61 -> V_89 ;
V_64 -> V_90 = V_61 -> V_91 ;
V_64 -> V_92 = V_61 -> V_93 -> V_94 . V_95 ;
V_61 -> V_96 = 0 ;
return F_58 ( V_64 ) ;
}
static int F_59 ( struct V_61 * V_61 )
{
unsigned long V_78 ;
F_50 ( & V_61 -> V_97 , V_78 ) ;
if ( V_61 -> V_98 == V_99 ||
V_61 -> V_98 == V_100 ) {
F_52 ( & V_61 -> V_97 , V_78 ) ;
F_60 ( & V_61 -> V_101 ,
3000 ) ;
return 0 ;
}
F_52 ( & V_61 -> V_97 , V_78 ) ;
return 0 ;
}
static void F_61 ( struct V_37 * V_54 )
{
return;
}
static T_3 F_62 ( struct V_61 * V_61 )
{
struct V_63 * V_64 ;
if ( V_61 -> V_68 & V_69 )
return 0xffffffff ;
V_64 = F_12 ( V_61 , struct V_63 , V_61 ) ;
return V_64 -> V_102 ;
}
static int F_63 ( struct V_61 * V_61 )
{
return 0 ;
}
static int F_64 ( T_7 * V_77 , struct V_63 * V_64 ,
unsigned char * V_103 , T_8 V_82 , int V_104 ,
int V_105 , int V_106 )
{
struct V_61 * V_61 = & V_64 -> V_61 ;
struct V_72 * V_71 ;
struct V_73 * V_74 ;
int V_78 = V_107 ;
if ( V_106 )
V_78 |= V_108 ;
V_74 = V_64 -> V_74 ;
if ( ! V_74 ) {
F_31 ( L_6 ) ;
return - V_20 ;
}
V_71 = V_74 -> V_71 ;
if ( ! V_71 ) {
F_31 ( L_7 ) ;
return - V_20 ;
}
return F_65 ( V_61 , V_71 , V_103 , & V_64 -> V_109 [ 0 ] ,
V_64 -> V_110 , V_82 , V_104 ,
V_105 , V_78 ) ;
}
static void F_66 ( struct V_56 * V_57 )
{
struct V_63 * V_64 = F_12 ( V_57 , struct V_63 , V_57 ) ;
V_64 -> V_65 = 0 ;
V_64 -> V_66 |= V_111 ;
if ( ! V_64 -> V_112 ) {
if ( V_64 -> V_61 . V_113 & V_114 ) {
F_67 ( & V_64 -> V_61 . V_101 ) ;
return;
}
if ( V_64 -> V_61 . V_96 )
F_68 ( & V_64 -> V_61 ,
V_64 -> V_61 . V_96 ) ;
else
F_68 ( & V_64 -> V_61 ,
V_115 ) ;
return;
}
return F_69 ( & V_64 -> V_61 ) ;
}
static void F_70 ( struct V_63 * V_64 )
{
V_64 -> V_66 |= V_116 ;
V_64 -> V_65 = 1 ;
F_38 ( & V_64 -> V_57 , F_66 ) ;
F_39 ( V_62 , & V_64 -> V_57 ) ;
}
static void F_71 ( struct V_56 * V_57 )
{
struct V_63 * V_64 = F_12 ( V_57 , struct V_63 , V_57 ) ;
F_72 ( & V_64 -> V_61 . V_117 ) ;
F_68 ( & V_64 -> V_61 , V_64 -> V_61 . V_96 ) ;
}
static void F_73 ( struct V_63 * V_64 )
{
F_38 ( & V_64 -> V_57 , F_71 ) ;
F_39 ( V_62 , & V_64 -> V_57 ) ;
}
static int F_74 ( struct V_58 * V_59 , T_8 V_118 ,
T_9 V_119 , T_8 V_102 )
{
struct V_73 * V_74 = V_59 -> V_74 ;
struct V_61 * V_61 = & V_59 -> V_61 ;
return F_75 ( V_61 , V_74 -> V_71 , NULL , V_118 , V_59 ,
V_119 , V_120 , V_102 , V_107 ) ;
}
static int F_76 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_12 ( V_61 ,
struct V_63 , V_61 ) ;
V_64 -> V_66 |= V_121 ;
V_64 -> V_81 = V_61 -> V_82 ;
V_64 -> V_83 = F_57 ( V_61 ) ;
V_64 -> V_122 = ( V_61 -> V_113 & V_114 ) ;
V_64 -> V_84 = V_61 -> V_85 ;
V_64 -> V_86 = V_61 -> V_87 ;
V_64 -> V_123 = 0 ;
V_64 -> V_66 |= V_124 ;
V_64 -> V_88 = V_61 -> V_89 ;
V_64 -> V_90 = V_61 -> V_91 ;
V_64 -> V_92 = V_61 -> V_93 -> V_94 . V_95 ;
V_61 -> V_96 = 0 ;
return F_77 ( V_64 , V_125 | V_126 ,
V_61 -> V_127 ) ;
}
static int F_78 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_12 ( V_61 ,
struct V_63 , V_61 ) ;
int V_128 = V_126 ;
V_64 -> V_81 = V_61 -> V_82 ;
V_64 -> V_86 = NULL ;
V_64 -> V_84 = 0 ;
V_64 -> V_123 = 0 ;
V_64 -> V_83 = F_57 ( V_61 ) ;
V_64 -> V_122 = ( V_61 -> V_113 & V_114 ) ;
if ( V_64 -> V_66 & V_129 ) {
F_79 ( L_8 , V_64 ) ;
F_80 () ;
}
V_64 -> V_66 |= V_129 ;
if ( V_61 -> V_130 == V_131 ) {
if ( V_61 -> V_68 & V_132 ) {
V_61 -> V_68 &= ~ V_132 ;
V_61 -> V_133 = 0 ;
}
V_61 -> V_68 |= V_134 ;
V_61 -> V_133 += V_61 -> V_82 ;
V_64 -> V_81 = 0 ;
}
return F_77 ( V_64 , V_128 , V_61 -> V_127 ) ;
}
static void F_81 ( struct V_61 * V_61 )
{
struct V_135 * V_136 = V_61 -> V_135 ;
struct V_58 * V_59 = F_12 ( V_61 ,
struct V_58 , V_61 ) ;
F_2 ( L_9 ,
V_59 , V_136 -> V_137 , V_136 -> V_138 ) ;
switch ( V_136 -> V_138 ) {
case V_139 :
V_59 -> V_140 = V_141 ;
break;
case V_142 :
V_59 -> V_140 = V_143 ;
break;
case V_144 :
V_59 -> V_140 = V_145 ;
break;
case V_146 :
default:
V_59 -> V_140 = V_147 ;
break;
}
F_82 ( V_59 ) ;
}
static void F_83 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_12 ( V_61 ,
struct V_63 , V_61 ) ;
struct V_76 * V_77 = V_64 -> V_77 ;
struct V_148 * V_149 = V_77 -> V_79 ;
if ( ! V_64 -> V_150 )
return;
F_84 ( V_149 -> V_151 , V_64 -> V_86 , V_64 -> V_84 , V_64 -> V_83 ) ;
V_64 -> V_150 = 0 ;
}
static void F_85 ( struct V_73 * V_74 )
{
struct V_37 * V_38 = V_74 -> V_71 -> V_37 ;
struct V_26 * V_27 = V_38 -> V_27 ;
struct V_152 * V_152 = V_27 -> V_153 ;
struct V_30 * V_31 = F_12 ( V_152 ,
struct V_30 , V_154 ) ;
struct V_53 * V_54 = F_12 ( V_38 ,
struct V_53 , V_37 ) ;
void * V_155 ;
F_2 ( L_10 , V_54 -> V_156 ) ;
V_155 = F_86 ( & V_31 -> V_157 , V_54 -> V_156 ) ;
if ( F_41 ( V_155 && ( V_155 != V_38 ) ) ) {
F_87 ( & V_31 -> V_157 , V_54 -> V_156 ,
V_155 , V_120 ) ;
}
F_2 ( L_11 ,
V_38 , V_54 -> V_158 , V_54 -> V_156 ) ;
F_88 ( V_31 , V_54 , V_74 ) ;
}
static void F_89 ( struct V_159 * V_159 )
{
struct V_72 * V_71 = F_12 ( V_159 ,
struct V_72 , V_160 ) ;
F_54 ( V_71 -> V_75 ) ;
}
static void F_90 ( struct V_72 * V_71 )
{
struct V_73 * V_74 = V_71 -> V_75 ;
struct V_148 * V_149 = V_74 -> V_77 -> V_79 ;
unsigned long V_78 ;
F_50 ( & V_149 -> V_80 , V_78 ) ;
F_91 ( & V_71 -> V_160 , F_89 ) ;
F_52 ( & V_149 -> V_80 , V_78 ) ;
}
static void F_92 ( struct V_73 * V_74 )
{
if ( ! V_74 )
return;
F_93 ( & V_74 -> V_77 -> V_79 -> V_80 ) ;
F_91 ( & V_74 -> V_71 -> V_160 , F_89 ) ;
}
static void F_94 ( struct V_73 * V_74 )
{
F_93 ( & V_74 -> V_77 -> V_79 -> V_80 ) ;
F_51 ( V_74 -> V_71 ) ;
}
static struct V_37 * F_95 (
struct V_26 * V_27 ,
struct V_161 * V_162 ,
const char * V_1 )
{
struct V_37 * V_38 , * V_163 ;
struct V_53 * V_54 ;
T_2 V_23 ;
T_3 V_164 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return F_96 ( - V_20 ) ;
V_163 = F_29 ( V_27 ) ;
if ( ! V_163 )
return F_96 ( - V_165 ) ;
V_164 = 1 ;
V_38 = F_97 ( V_27 , V_163 ,
V_1 , V_164 ) ;
if ( F_98 ( V_38 ) ) {
F_32 ( V_27 , V_163 ) ;
return V_38 ;
}
V_54 = F_12 ( V_38 , struct V_53 , V_37 ) ;
V_54 -> V_158 = V_23 ;
F_3 ( & V_54 -> V_166 [ 0 ] , V_10 , V_23 ) ;
return V_38 ;
}
static void F_99 ( struct V_37 * V_167 )
{
struct V_26 * V_27 = V_167 -> V_27 ;
struct V_53 * V_54 = F_12 ( V_167 ,
struct V_53 , V_37 ) ;
F_100 ( V_27 , V_167 , 1 ) ;
F_33 ( V_54 ) ;
}
static T_1 F_101 (
struct V_26 * V_27 ,
char * V_168 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_168 , V_169 , L_12 ,
F_102 ( & V_29 -> V_170 ) ) ;
}
static void F_103 ( struct V_56 * V_57 )
{
struct V_28 * V_171 = F_12 ( V_57 ,
struct V_28 , V_172 ) ;
struct V_26 * V_27 = & V_171 -> V_27 ;
struct V_76 * V_173 = V_171 -> V_31 -> V_174 ;
if ( ! F_104 ( & V_27 -> V_175 . V_176 ) ) {
F_105 ( & V_171 -> V_170 , 1 ) ;
F_106 ( V_173 ) ;
}
F_67 ( & V_171 -> V_177 ) ;
}
static void F_107 ( struct V_56 * V_57 )
{
struct V_28 * V_171 = F_12 ( V_57 ,
struct V_28 , V_172 ) ;
struct V_26 * V_27 = & V_171 -> V_27 ;
struct V_76 * V_173 = V_171 -> V_31 -> V_174 ;
if ( ! F_108 ( V_173 -> V_178 . V_179 ) ) {
F_105 ( & V_171 -> V_170 , 0 ) ;
F_109 ( & V_27 -> V_175 . V_176 ) ;
}
F_67 ( & V_171 -> V_177 ) ;
}
static T_1 F_110 (
struct V_26 * V_27 ,
const char * V_168 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_180 ;
int V_25 ;
V_25 = F_111 ( V_168 , 0 , & V_180 ) ;
if ( V_25 < 0 ) {
F_31 ( L_13 , V_25 ) ;
return - V_20 ;
}
if ( ( V_180 != 1 ) && ( V_180 != 0 ) ) {
F_31 ( L_14 , V_180 ) ;
return - V_20 ;
}
if ( V_180 ) {
if ( F_102 ( & V_29 -> V_170 ) )
return - V_181 ;
F_38 ( & V_29 -> V_172 , F_103 ) ;
} else {
if ( ! F_102 ( & V_29 -> V_170 ) )
return V_21 ;
F_38 ( & V_29 -> V_172 , F_107 ) ;
}
F_112 ( & V_29 -> V_177 ) ;
F_113 ( & V_29 -> V_172 ) ;
F_114 ( & V_29 -> V_177 ) ;
if ( V_180 ) {
if ( ! F_102 ( & V_29 -> V_170 ) )
return - V_182 ;
} else {
if ( F_102 ( & V_29 -> V_170 ) )
return - V_183 ;
}
return V_21 ;
}
static T_1 F_115 (
struct V_26 * V_27 ,
char * V_168 )
{
return F_116 ( V_27 , V_168 ) ;
}
static T_1 F_117 (
struct V_26 * V_27 ,
const char * V_168 ,
T_4 V_21 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_184 ;
int V_42 = F_111 ( V_168 , 0 , & V_184 ) ;
if ( V_42 ) {
F_31 ( L_15 , V_42 ) ;
return V_42 ;
}
if ( V_184 != 0 && V_184 != 1 && V_184 != 3 ) {
F_31 ( L_16 , V_184 ) ;
return - V_20 ;
}
V_29 -> V_46 . V_52 = V_184 ;
return V_21 ;
}
static T_1 F_118 (
struct V_26 * V_27 ,
char * V_168 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_168 , L_12 , V_29 -> V_46 . V_52 ) ;
}
static struct V_26 * F_119 (
struct V_152 * V_2 ,
struct V_161 * V_162 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_154 ) ;
struct V_28 * V_29 ;
unsigned long V_185 ;
int V_42 ;
if ( strstr ( V_1 , L_17 ) != V_1 )
return F_96 ( - V_20 ) ;
if ( F_111 ( V_1 + 5 , 10 , & V_185 ) || V_185 > V_186 )
return F_96 ( - V_20 ) ;
if ( ( V_185 != 1 ) ) {
F_31 ( L_18 ) ;
return F_96 ( - V_187 ) ;
}
V_29 = F_30 ( sizeof( struct V_28 ) , V_55 ) ;
if ( ! V_29 ) {
F_31 ( L_19 ) ;
return F_96 ( - V_165 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_185 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_120 ( & V_188 , V_2 ,
& V_29 -> V_27 , V_29 , V_189 ) ;
if ( V_42 < 0 ) {
F_33 ( V_29 ) ;
return NULL ;
}
V_31 -> V_190 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_121 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_76 * V_77 = V_31 -> V_174 ;
if ( V_77 -> V_178 . V_179 && ! V_77 -> V_178 . V_179 -> V_191 )
F_108 ( V_77 -> V_178 . V_179 ) ;
F_122 ( V_27 ) ;
V_31 -> V_190 = NULL ;
F_33 ( V_29 ) ;
}
static T_1 F_123 (
struct V_26 * V_27 ,
char * V_168 )
{
return F_101 ( V_27 , V_168 ) ;
}
static T_1 F_124 (
struct V_26 * V_27 ,
const char * V_168 ,
T_4 V_21 )
{
struct V_152 * V_152 = V_27 -> V_153 ;
struct V_30 * V_31 = F_12 ( V_152 ,
struct V_30 , V_154 ) ;
struct V_76 * V_77 = V_31 -> V_174 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_180 ;
int V_25 ;
V_25 = F_111 ( V_168 , 0 , & V_180 ) ;
if ( V_25 < 0 ) {
F_31 ( L_13 , V_25 ) ;
return - V_20 ;
}
if ( ( V_180 != 1 ) && ( V_180 != 0 ) ) {
F_31 ( L_14 , V_180 ) ;
return - V_20 ;
}
if ( V_180 ) {
if ( F_102 ( & V_29 -> V_170 ) )
return - V_181 ;
F_105 ( & V_29 -> V_170 , 1 ) ;
F_106 ( V_77 ) ;
} else {
if ( ! F_102 ( & V_29 -> V_170 ) )
return V_21 ;
F_105 ( & V_29 -> V_170 , 0 ) ;
F_108 ( V_77 -> V_178 . V_179 ) ;
}
return V_21 ;
}
static struct V_26 * F_125 (
struct V_152 * V_2 ,
struct V_161 * V_162 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_154 ) ;
struct V_28 * V_29 ;
unsigned long V_185 ;
int V_42 ;
if ( strstr ( V_1 , L_17 ) != V_1 )
return F_96 ( - V_20 ) ;
if ( F_111 ( V_1 + 5 , 10 , & V_185 ) || V_185 > V_186 )
return F_96 ( - V_20 ) ;
V_29 = F_30 ( sizeof( struct V_28 ) , V_55 ) ;
if ( ! V_29 ) {
F_31 ( L_19 ) ;
return F_96 ( - V_165 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = V_185 ;
V_29 -> V_46 . V_47 = 1 ;
V_29 -> V_46 . V_49 = 1 ;
V_29 -> V_46 . V_48 = 1 ;
V_29 -> V_46 . V_51 = 1 ;
V_42 = F_120 ( & V_192 , V_2 ,
& V_29 -> V_27 , V_29 , V_189 ) ;
if ( V_42 < 0 ) {
F_33 ( V_29 ) ;
return NULL ;
}
V_31 -> V_190 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_73 * F_126 (
T_7 * V_77 ,
const T_9 * V_193 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_53 * V_54 ;
T_3 V_194 ;
V_31 = V_77 -> V_178 . V_195 ;
if ( ! V_31 ) {
F_31 ( L_20 ) ;
F_80 () ;
return NULL ;
}
V_194 = ( ( ( unsigned long ) V_193 [ 0 ] << 16 ) |
( ( unsigned long ) V_193 [ 1 ] << 8 ) |
( unsigned long ) V_193 [ 2 ] ) ;
F_2 ( L_21 , V_194 ) ;
V_38 = F_127 ( & V_31 -> V_157 , V_194 ) ;
if ( ! V_38 ) {
F_2 ( L_22 , V_194 ) ;
return NULL ;
}
F_2 ( L_23 ,
V_38 , V_38 -> V_196 ) ;
V_54 = F_12 ( V_38 , struct V_53 , V_37 ) ;
if ( ! V_54 -> V_73 ) {
F_31 ( L_24 ) ;
return NULL ;
}
return V_54 -> V_73 ;
}
static void F_128 (
struct V_30 * V_31 ,
struct V_37 * V_197 ,
struct V_53 * V_54 ,
struct V_72 * V_71 ,
struct V_73 * V_73 ,
T_9 * V_193 )
{
T_3 V_194 ;
void * V_198 ;
int V_25 ;
V_194 = ( ( ( unsigned long ) V_193 [ 0 ] << 16 ) |
( ( unsigned long ) V_193 [ 1 ] << 8 ) |
( unsigned long ) V_193 [ 2 ] ) ;
F_2 ( L_25 , V_194 ) ;
V_198 = F_127 ( & V_31 -> V_157 , V_194 ) ;
if ( ! V_198 ) {
if ( V_197 ) {
F_2 ( L_26 ) ;
V_54 -> V_156 = V_194 ;
V_25 = F_87 ( & V_31 -> V_157 , V_194 ,
V_197 , V_120 ) ;
if ( V_25 )
F_129 ( V_199 L_27 ,
( int ) V_194 ) ;
} else {
F_2 ( L_28 ) ;
}
V_73 -> V_71 = V_71 ;
V_54 -> V_73 = V_73 ;
return;
}
if ( V_54 -> V_73 ) {
if ( V_197 == NULL ) {
F_2 ( L_29 ) ;
F_86 ( & V_31 -> V_157 , V_194 ) ;
V_54 -> V_73 = NULL ;
return;
}
F_2 ( L_30 ) ;
F_130 ( & V_31 -> V_157 , V_194 , V_197 ) ;
V_73 -> V_71 = V_71 ;
V_54 -> V_73 = V_73 ;
return;
}
if ( V_197 == NULL ) {
F_2 ( L_31 ) ;
F_86 ( & V_31 -> V_157 , V_194 ) ;
return;
}
F_2 ( L_32 ) ;
F_130 ( & V_31 -> V_157 , V_194 , V_197 ) ;
V_73 -> V_71 = V_71 ;
V_54 -> V_73 = V_73 ;
F_2 ( L_33 ,
V_54 -> V_73 , V_197 , V_197 -> V_196 ) ;
}
static struct V_73 * F_131 (
T_7 * V_77 ,
const T_10 V_200 )
{
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_53 * V_54 ;
struct V_201 * V_202 ;
V_31 = V_77 -> V_178 . V_195 ;
if ( ! V_31 ) {
F_31 ( L_20 ) ;
F_80 () ;
return NULL ;
}
F_2 ( L_34 , V_200 ) ;
V_202 = V_31 -> V_203 + V_200 ;
V_38 = V_202 -> V_38 ;
if ( ! V_38 ) {
F_2 ( L_35 ,
V_200 ) ;
return NULL ;
}
V_54 = F_12 ( V_38 , struct V_53 , V_37 ) ;
if ( ! V_54 -> V_73 ) {
F_31 ( L_24 ) ;
return NULL ;
}
return V_54 -> V_73 ;
}
static void F_132 (
struct V_30 * V_31 ,
struct V_37 * V_197 ,
struct V_53 * V_54 ,
struct V_72 * V_71 ,
struct V_73 * V_73 ,
T_10 V_200 )
{
struct V_37 * V_204 ;
struct V_201 * V_202 ;
F_2 ( L_36 , V_200 ) ;
V_202 = & ( (struct V_201 * )
V_31 -> V_203 ) [ V_200 ] ;
V_204 = V_202 -> V_38 ;
if ( ! V_204 ) {
F_2 ( L_37 ) ;
V_202 -> V_38 = V_197 ;
if ( V_73 -> V_71 != V_71 )
V_73 -> V_71 = V_71 ;
if ( V_54 -> V_73 != V_73 )
V_54 -> V_73 = V_73 ;
return;
}
if ( V_54 -> V_73 ) {
if ( V_197 == NULL ) {
F_2 ( L_38 ) ;
V_202 -> V_38 = NULL ;
V_54 -> V_73 = NULL ;
return;
}
F_2 ( L_39 ) ;
V_202 -> V_38 = V_197 ;
if ( V_73 -> V_71 != V_71 )
V_73 -> V_71 = V_71 ;
if ( V_54 -> V_73 != V_73 )
V_54 -> V_73 = V_73 ;
return;
}
if ( V_197 == NULL ) {
F_2 ( L_40 ) ;
V_202 -> V_38 = NULL ;
return;
}
F_2 ( L_41 ) ;
V_202 -> V_38 = V_197 ;
if ( V_73 -> V_71 != V_71 )
V_73 -> V_71 = V_71 ;
if ( V_54 -> V_73 != V_73 )
V_54 -> V_73 = V_73 ;
F_2 ( L_42 ,
V_54 -> V_73 , V_197 , V_197 -> V_196 ) ;
}
static void F_88 ( struct V_30 * V_31 ,
struct V_53 * V_54 , struct V_73 * V_74 )
{
struct V_72 * V_71 = V_74 -> V_71 ;
unsigned char V_205 [ 3 ] ;
V_205 [ 0 ] = V_74 -> V_193 . V_14 . V_206 ;
V_205 [ 1 ] = V_74 -> V_193 . V_14 . V_207 ;
V_205 [ 2 ] = V_74 -> V_193 . V_14 . V_208 ;
F_128 ( V_31 , NULL , V_54 , V_71 ,
V_74 , V_205 ) ;
F_132 ( V_31 , NULL , V_54 , V_71 ,
V_74 , V_74 -> V_200 ) ;
}
static void F_133 ( struct V_73 * V_74 )
{
struct V_179 * V_209 = V_74 -> V_209 ;
struct V_148 * V_149 = V_209 -> V_149 ;
T_7 * V_77 = F_134 ( V_149 -> V_151 ) ;
struct V_72 * V_71 ;
struct V_37 * V_38 ;
struct V_30 * V_31 ;
struct V_53 * V_54 ;
F_49 ( F_135 () ) ;
V_71 = V_74 -> V_71 ;
if ( ! V_71 ) {
F_31 ( L_43 ) ;
F_80 () ;
return;
}
V_38 = V_71 -> V_37 ;
V_54 = F_12 ( V_38 , struct V_53 , V_37 ) ;
V_31 = V_77 -> V_178 . V_195 ;
if ( ! V_31 ) {
F_31 ( L_20 ) ;
F_80 () ;
return;
}
F_136 ( V_71 ) ;
F_137 ( V_74 -> V_71 ) ;
F_138 ( V_74 -> V_71 ) ;
}
static int F_139 (
T_7 * V_77 ,
unsigned char * V_210 ,
void * V_73 ,
T_9 * V_193 ,
T_10 V_200 )
{
struct V_148 * V_149 = V_77 -> V_79 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_53 * V_54 ;
struct V_26 * V_27 ;
struct V_37 * V_38 ;
struct V_72 * V_71 ;
struct V_73 * V_74 = V_73 ;
unsigned char V_211 [ 36 ] ;
unsigned long V_78 ;
int V_212 = ( V_149 -> V_213 ) ? V_149 -> V_213 :
V_214 ;
V_31 = V_77 -> V_178 . V_195 ;
if ( ! V_31 ) {
F_31 ( L_20 ) ;
F_80 () ;
return - V_20 ;
}
V_29 = V_31 -> V_190 ;
if ( ! V_29 ) {
F_31 ( L_44 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_71 = F_140 ( V_212 ,
sizeof( struct V_63 ) ,
V_215 ) ;
if ( F_98 ( V_71 ) ) {
F_31 ( L_45 ) ;
return F_141 ( V_71 ) ;
}
memset ( & V_211 , 0 , 36 ) ;
snprintf ( V_211 , sizeof( V_211 ) , L_46 , V_210 ) ;
V_71 -> V_37 = F_142 ( V_27 ,
V_211 ) ;
if ( ! V_71 -> V_37 ) {
F_143 ( V_71 ) ;
return - V_20 ;
}
V_38 = V_71 -> V_37 ;
V_54 = F_12 ( V_38 , struct V_53 , V_37 ) ;
F_50 ( & V_149 -> V_80 , V_78 ) ;
F_128 ( V_31 , V_38 , V_54 , V_71 ,
V_73 , V_193 ) ;
F_132 ( V_31 , V_38 , V_54 , V_71 ,
V_73 , V_200 ) ;
F_52 ( & V_149 -> V_80 , V_78 ) ;
F_144 ( V_38 -> V_27 , V_38 , V_71 , V_74 ) ;
return 0 ;
}
static void F_145 ( struct V_73 * V_74 , T_11 V_193 ,
T_10 V_200 , bool V_216 )
{
struct V_179 * V_209 = V_74 -> V_209 ;
struct V_148 * V_149 = V_209 -> V_149 ;
T_7 * V_77 = F_134 ( V_149 -> V_151 ) ;
struct V_30 * V_31 = V_77 -> V_178 . V_195 ;
struct V_37 * V_38 = V_74 -> V_71 -> V_37 ;
struct V_53 * V_54 = F_12 ( V_38 ,
struct V_53 , V_37 ) ;
T_3 V_194 ;
if ( V_74 -> V_200 != V_200 || V_74 -> V_193 . V_217 != V_193 . V_217 )
F_146 ( L_47 ,
V_74 , V_74 -> V_211 ,
V_74 -> V_200 , V_200 , V_74 -> V_193 . V_14 . V_206 ,
V_74 -> V_193 . V_14 . V_207 , V_74 -> V_193 . V_14 . V_208 , V_193 . V_14 . V_206 ,
V_193 . V_14 . V_207 , V_193 . V_14 . V_208 ) ;
if ( V_74 -> V_200 != V_200 ) {
if ( V_31 -> V_203 [ V_74 -> V_200 ] . V_38 == V_38 )
V_31 -> V_203 [ V_74 -> V_200 ] . V_38 = NULL ;
V_31 -> V_203 [ V_200 ] . V_38 = V_38 ;
V_74 -> V_200 = V_200 ;
}
if ( V_74 -> V_193 . V_217 != V_193 . V_217 ) {
V_194 = ( ( ( T_3 ) V_74 -> V_193 . V_14 . V_206 << 16 ) |
( ( T_3 ) V_74 -> V_193 . V_14 . V_207 << 8 ) |
( ( T_3 ) V_74 -> V_193 . V_14 . V_208 ) ) ;
if ( F_127 ( & V_31 -> V_157 , V_194 ) )
F_147 ( F_86 ( & V_31 -> V_157 , V_194 ) != V_38 ,
L_48 ,
V_74 -> V_193 . V_14 . V_206 , V_74 -> V_193 . V_14 . V_207 , V_74 -> V_193 . V_14 . V_208 ) ;
else
F_147 ( 1 , L_49 ,
V_74 -> V_193 . V_14 . V_206 , V_74 -> V_193 . V_14 . V_207 , V_74 -> V_193 . V_14 . V_208 ) ;
V_194 = ( ( ( T_3 ) V_193 . V_14 . V_206 << 16 ) |
( ( T_3 ) V_193 . V_14 . V_207 << 8 ) |
( ( T_3 ) V_193 . V_14 . V_208 ) ) ;
if ( F_127 ( & V_31 -> V_157 , V_194 ) ) {
F_147 ( 1 , L_50 ,
V_193 . V_14 . V_206 , V_193 . V_14 . V_207 , V_193 . V_14 . V_208 ) ;
F_130 ( & V_31 -> V_157 , V_194 , V_38 ) ;
} else {
F_87 ( & V_31 -> V_157 , V_194 , V_38 , V_120 ) ;
}
V_74 -> V_193 = V_193 ;
V_54 -> V_156 = V_194 ;
}
V_74 -> V_216 = V_216 ;
}
static int F_148 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_149 ( & V_31 -> V_157 ) ;
if ( V_25 ) {
F_31 ( L_51 ) ;
return V_25 ;
}
V_31 -> V_203 = F_150 ( sizeof( struct V_201 ) *
65536 ) ;
if ( ! V_31 -> V_203 ) {
F_31 ( L_52 ,
sizeof( struct V_201 ) * 65536 ) ;
F_151 ( & V_31 -> V_157 ) ;
return - V_165 ;
}
memset ( V_31 -> V_203 , 0 , sizeof( struct V_201 )
* 65536 ) ;
F_2 ( L_53 ,
sizeof( struct V_201 ) * 65536 ) ;
return 0 ;
}
static int F_152 ( struct V_76 * V_77 ,
void * V_195 ,
T_2 V_218 , T_2 V_219 )
{
struct V_148 * V_149 = V_77 -> V_79 ;
struct V_30 * V_31 =
(struct V_30 * ) V_195 ;
V_149 -> V_209 . V_220 = & V_221 ;
V_77 -> V_178 . V_195 = V_195 ;
V_31 -> V_174 = V_77 ;
return 0 ;
}
static struct V_152 * F_153 (
struct V_222 * V_223 ,
struct V_161 * V_162 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_42 = - V_182 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_96 ( - V_20 ) ;
V_31 = F_30 ( sizeof( struct V_30 ) , V_55 ) ;
if ( ! V_31 ) {
F_31 ( L_54 ) ;
return F_96 ( - V_165 ) ;
}
V_31 -> V_224 = V_22 ;
F_3 ( & V_31 -> V_225 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_35 , L_55 , ( unsigned long long ) V_22 ) ;
V_42 = F_148 ( V_31 ) ;
if ( V_42 != 0 )
goto V_226;
V_42 = F_154 ( V_31 , V_22 , 0 , 0 ,
F_152 ) ;
if ( V_42 != 0 )
goto V_227;
return & V_31 -> V_154 ;
V_227:
F_155 ( V_31 -> V_203 ) ;
F_151 ( & V_31 -> V_157 ) ;
V_226:
F_33 ( V_31 ) ;
return F_96 ( V_42 ) ;
}
static void F_156 ( struct V_152 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_154 ) ;
struct V_76 * V_77 = V_31 -> V_174 ;
struct V_37 * V_155 ;
T_3 V_194 = 0 ;
if ( V_77 -> V_178 . V_179 && ! V_77 -> V_178 . V_179 -> V_228 )
F_157 ( V_77 -> V_178 . V_179 ) ;
F_158 ( V_77 ) ;
F_155 ( V_31 -> V_203 ) ;
F_159 (&lport->lport_fcport_map, key, node)
F_86 ( & V_31 -> V_157 , V_194 ) ;
F_151 ( & V_31 -> V_157 ) ;
F_33 ( V_31 ) ;
}
static int F_160 ( struct V_76 * V_173 ,
void * V_195 ,
T_2 V_218 , T_2 V_219 )
{
struct V_229 * V_230 ;
struct V_231 * V_232 = V_173 -> V_233 ;
struct V_76 * V_234 ;
struct V_30 * V_31 =
(struct V_30 * ) V_195 ;
struct V_30 * V_235 =
(struct V_30 * ) V_173 -> V_178 . V_195 ;
struct V_28 * V_171 ;
struct V_236 V_237 ;
if ( ! F_161 ( V_173 ) ) {
F_31 ( L_56 ) ;
return - V_183 ;
}
if ( ! V_235 || ! V_235 -> V_190 ||
! F_102 ( & V_235 -> V_190 -> V_170 ) ) {
F_31 ( L_57 ) ;
return - V_183 ;
}
V_171 = V_235 -> V_190 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_211 = V_218 ;
V_237 . V_238 = V_219 ;
V_237 . V_239 = V_240 ;
V_237 . V_241 = V_242 ;
V_237 . V_243 = false ;
V_230 = F_162 ( V_232 , 0 , & V_237 ) ;
if ( ! V_230 ) {
F_31 ( L_58 ) ;
return - V_182 ;
}
V_234 = (struct V_76 * ) V_230 -> V_244 ;
V_234 -> V_178 . V_195 = V_195 ;
V_31 -> V_174 = V_234 ;
F_163 ( V_234 -> V_233 ) ;
return 0 ;
}
static struct V_152 * F_164 (
struct V_222 * V_223 ,
struct V_161 * V_162 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_245 , V_218 , V_219 ;
char * V_246 , V_247 [ 128 ] ;
int V_42 ;
snprintf ( V_247 , 128 , L_59 , V_1 ) ;
V_246 = strchr ( V_247 , '@' ) ;
if ( ! V_246 ) {
F_31 ( L_60 ) ;
return F_96 ( - V_20 ) ;
}
* V_246 ++ = '\0' ;
if ( F_1 ( V_247 , & V_245 , 1 ) < 0 )
return F_96 ( - V_20 ) ;
if ( F_9 ( V_246 , strlen ( V_246 ) + 1 ,
& V_218 , & V_219 ) < 0 )
return F_96 ( - V_20 ) ;
V_31 = F_30 ( sizeof( struct V_30 ) , V_55 ) ;
if ( ! V_31 ) {
F_31 ( L_61 ) ;
return F_96 ( - V_165 ) ;
}
V_31 -> V_248 = V_218 ;
V_31 -> V_249 = V_219 ;
sprintf ( V_31 -> V_35 , L_55 , ( unsigned long long ) V_218 ) ;
V_42 = F_148 ( V_31 ) ;
if ( V_42 != 0 )
goto V_226;
V_42 = F_154 ( V_31 , V_245 , V_218 , V_219 ,
F_160 ) ;
if ( V_42 != 0 )
goto V_227;
return & V_31 -> V_154 ;
V_227:
F_155 ( V_31 -> V_203 ) ;
F_151 ( & V_31 -> V_157 ) ;
V_226:
F_33 ( V_31 ) ;
return F_96 ( V_42 ) ;
}
static void F_165 ( struct V_152 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_154 ) ;
struct V_76 * V_234 = V_31 -> V_174 ;
struct V_148 * V_149 = V_234 -> V_79 ;
T_7 * V_173 = F_134 ( V_149 -> V_151 ) ;
F_166 ( V_234 -> V_233 ) ;
F_167 ( V_234 -> V_229 ) ;
F_166 ( V_173 -> V_233 ) ;
F_33 ( V_31 ) ;
}
static T_1 F_168 (
struct V_222 * V_223 ,
char * V_168 )
{
return sprintf ( V_168 ,
L_62
V_250 L_63 , V_251 , F_169 () -> V_252 ,
F_169 () -> V_253 ) ;
}
static int F_170 ( void )
{
int V_42 ;
F_2 ( L_64
V_250 L_63 , V_251 , F_169 () -> V_252 ,
F_169 () -> V_253 ) ;
V_42 = F_171 ( & V_188 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_171 ( & V_192 ) ;
if ( V_42 )
goto V_254;
V_62 = F_172 ( L_65 ,
V_255 , 0 ) ;
if ( ! V_62 ) {
V_42 = - V_165 ;
goto V_256;
}
V_257 = F_172 ( L_66 , 0 , 0 ) ;
if ( ! V_257 ) {
V_42 = - V_165 ;
goto V_258;
}
return 0 ;
V_258:
F_173 ( V_62 ) ;
V_256:
F_174 ( & V_192 ) ;
V_254:
F_174 ( & V_188 ) ;
return V_42 ;
}
static void F_175 ( void )
{
F_173 ( V_257 ) ;
F_173 ( V_62 ) ;
F_174 ( & V_188 ) ;
F_174 ( & V_192 ) ;
}
static int T_12 F_176 ( void )
{
int V_42 ;
V_42 = F_170 () ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static void T_13 F_177 ( void )
{
F_175 () ;
}
