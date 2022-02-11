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
static T_1 F_81 ( struct V_148 * V_149 ,
char * V_150 )
{
struct V_26 * V_27 = F_82 ( V_149 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_150 , V_151 , L_11 ,
F_83 ( & V_29 -> V_152 ) ) ;
}
static void F_84 ( struct V_41 * V_42 )
{
struct V_28 * V_153 = F_12 ( V_42 ,
struct V_28 , V_154 ) ;
struct V_26 * V_27 = & V_153 -> V_27 ;
struct V_61 * V_155 = V_153 -> V_31 -> V_156 ;
if ( ! F_85 ( & V_27 -> V_157 . V_158 ) ) {
F_86 ( & V_153 -> V_152 , 1 ) ;
F_87 ( V_155 ) ;
}
F_53 ( & V_153 -> V_159 ) ;
}
static void F_88 ( struct V_41 * V_42 )
{
struct V_28 * V_153 = F_12 ( V_42 ,
struct V_28 , V_154 ) ;
struct V_26 * V_27 = & V_153 -> V_27 ;
struct V_61 * V_155 = V_153 -> V_31 -> V_156 ;
if ( ! F_89 ( V_155 -> V_160 . V_161 ) ) {
F_86 ( & V_153 -> V_152 , 0 ) ;
F_90 ( & V_27 -> V_157 . V_158 ) ;
}
F_53 ( & V_153 -> V_159 ) ;
}
static T_1 F_91 ( struct V_148 * V_149 ,
const char * V_150 , T_4 V_21 )
{
struct V_26 * V_27 = F_82 ( V_149 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_162 ;
int V_25 ;
V_25 = F_92 ( V_150 , 0 , & V_162 ) ;
if ( V_25 < 0 ) {
F_50 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_162 != 1 ) && ( V_162 != 0 ) ) {
F_50 ( L_13 , V_162 ) ;
return - V_20 ;
}
if ( V_162 ) {
if ( F_83 ( & V_29 -> V_152 ) )
return - V_163 ;
F_24 ( & V_29 -> V_154 , F_84 ) ;
} else {
if ( ! F_83 ( & V_29 -> V_152 ) )
return V_21 ;
F_24 ( & V_29 -> V_154 , F_88 ) ;
}
F_93 ( & V_29 -> V_159 ) ;
F_94 ( & V_29 -> V_154 ) ;
F_95 ( & V_29 -> V_159 ) ;
if ( V_162 ) {
if ( ! F_83 ( & V_29 -> V_152 ) )
return - V_164 ;
} else {
if ( F_83 ( & V_29 -> V_152 ) )
return - V_165 ;
}
return V_21 ;
}
static T_1 F_96 ( struct V_148 * V_149 ,
char * V_150 )
{
return F_97 ( F_82 ( V_149 ) , V_150 ) ;
}
static T_1 F_98 ( struct V_148 * V_149 ,
const char * V_150 , T_4 V_21 )
{
struct V_26 * V_27 = F_82 ( V_149 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_166 ;
int V_167 = F_92 ( V_150 , 0 , & V_166 ) ;
if ( V_167 ) {
F_50 ( L_14 , V_167 ) ;
return V_167 ;
}
if ( V_166 != 0 && V_166 != 1 && V_166 != 3 ) {
F_50 ( L_15 , V_166 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_166 ;
return V_21 ;
}
static T_1 F_99 ( struct V_148 * V_149 ,
char * V_150 )
{
struct V_26 * V_27 = F_82 ( V_149 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_150 , L_11 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_100 (
struct V_137 * V_2 ,
struct V_168 * V_169 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_28 * V_29 ;
unsigned long V_170 ;
int V_167 ;
if ( strstr ( V_1 , L_16 ) != V_1 )
return F_101 ( - V_20 ) ;
if ( F_92 ( V_1 + 5 , 10 , & V_170 ) || V_170 > V_171 )
return F_101 ( - V_20 ) ;
if ( ( V_170 != 1 ) ) {
F_50 ( L_17 ) ;
return F_101 ( - V_172 ) ;
}
V_29 = F_102 ( sizeof( struct V_28 ) , V_173 ) ;
if ( ! V_29 ) {
F_50 ( L_18 ) ;
return F_101 ( - V_174 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_170 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_167 = F_103 ( V_2 , & V_29 -> V_27 , V_175 ) ;
if ( V_167 < 0 ) {
F_104 ( V_29 ) ;
return NULL ;
}
V_31 -> V_176 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_105 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_61 * V_62 = V_31 -> V_156 ;
if ( V_62 -> V_160 . V_161 && ! V_62 -> V_160 . V_161 -> V_177 )
F_89 ( V_62 -> V_160 . V_161 ) ;
F_106 ( V_27 ) ;
V_31 -> V_176 = NULL ;
F_104 ( V_29 ) ;
}
static T_1 F_107 ( struct V_148 * V_149 ,
char * V_150 )
{
return F_81 ( V_149 , V_150 ) ;
}
static T_1 F_108 ( struct V_148 * V_149 ,
const char * V_150 , T_4 V_21 )
{
struct V_26 * V_27 = F_82 ( V_149 ) ;
struct V_137 * V_137 = V_27 -> V_138 ;
struct V_30 * V_31 = F_12 ( V_137 ,
struct V_30 , V_139 ) ;
struct V_61 * V_62 = V_31 -> V_156 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_162 ;
int V_25 ;
V_25 = F_92 ( V_150 , 0 , & V_162 ) ;
if ( V_25 < 0 ) {
F_50 ( L_12 , V_25 ) ;
return - V_20 ;
}
if ( ( V_162 != 1 ) && ( V_162 != 0 ) ) {
F_50 ( L_13 , V_162 ) ;
return - V_20 ;
}
if ( V_162 ) {
if ( F_83 ( & V_29 -> V_152 ) )
return - V_163 ;
F_86 ( & V_29 -> V_152 , 1 ) ;
F_87 ( V_62 ) ;
} else {
if ( ! F_83 ( & V_29 -> V_152 ) )
return V_21 ;
F_86 ( & V_29 -> V_152 , 0 ) ;
F_89 ( V_62 -> V_160 . V_161 ) ;
}
return V_21 ;
}
static struct V_26 * F_109 (
struct V_137 * V_2 ,
struct V_168 * V_169 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_28 * V_29 ;
unsigned long V_170 ;
int V_167 ;
if ( strstr ( V_1 , L_16 ) != V_1 )
return F_101 ( - V_20 ) ;
if ( F_92 ( V_1 + 5 , 10 , & V_170 ) || V_170 > V_171 )
return F_101 ( - V_20 ) ;
V_29 = F_102 ( sizeof( struct V_28 ) , V_173 ) ;
if ( ! V_29 ) {
F_50 ( L_18 ) ;
return F_101 ( - V_174 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_170 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_167 = F_103 ( V_2 , & V_29 -> V_27 , V_175 ) ;
if ( V_167 < 0 ) {
F_104 ( V_29 ) ;
return NULL ;
}
V_31 -> V_176 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_58 * F_110 (
T_7 * V_62 ,
const T_9 * V_178 )
{
struct V_30 * V_31 ;
struct V_89 * V_136 ;
struct V_140 * V_90 ;
T_3 V_179 ;
V_31 = V_62 -> V_160 . V_180 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return NULL ;
}
V_179 = F_111 ( V_178 ) ;
F_2 ( L_20 , V_179 ) ;
V_136 = F_112 ( & V_31 -> V_143 , V_179 ) ;
if ( ! V_136 ) {
F_2 ( L_21 , V_179 ) ;
return NULL ;
}
F_2 ( L_22 ,
V_136 , V_136 -> V_181 ) ;
V_90 = F_12 ( V_136 , struct V_140 , V_89 ) ;
if ( ! V_90 -> V_58 ) {
F_50 ( L_23 ) ;
return NULL ;
}
return V_90 -> V_58 ;
}
static void F_113 (
struct V_30 * V_31 ,
struct V_89 * V_182 ,
struct V_140 * V_90 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
T_9 * V_178 )
{
T_3 V_179 ;
void * V_183 ;
int V_25 ;
V_179 = F_111 ( V_178 ) ;
F_2 ( L_24 , V_179 ) ;
V_183 = F_112 ( & V_31 -> V_143 , V_179 ) ;
if ( ! V_183 ) {
if ( V_182 ) {
F_2 ( L_25 ) ;
V_90 -> V_142 = V_179 ;
V_25 = F_73 ( & V_31 -> V_143 , V_179 ,
V_182 , V_110 ) ;
if ( V_25 )
F_114 ( V_184 L_26 ,
( int ) V_179 ) ;
} else {
F_2 ( L_27 ) ;
}
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
return;
}
if ( V_90 -> V_58 ) {
if ( V_182 == NULL ) {
F_2 ( L_28 ) ;
F_72 ( & V_31 -> V_143 , V_179 ) ;
V_90 -> V_58 = NULL ;
return;
}
F_2 ( L_29 ) ;
F_115 ( & V_31 -> V_143 , V_179 , V_182 ) ;
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
return;
}
if ( V_182 == NULL ) {
F_2 ( L_30 ) ;
F_72 ( & V_31 -> V_143 , V_179 ) ;
return;
}
F_2 ( L_31 ) ;
F_115 ( & V_31 -> V_143 , V_179 , V_182 ) ;
V_58 -> V_57 = V_57 ;
V_90 -> V_58 = V_58 ;
F_2 ( L_32 ,
V_90 -> V_58 , V_182 , V_182 -> V_181 ) ;
}
static struct V_58 * F_116 (
T_7 * V_62 ,
const T_10 V_185 )
{
struct V_30 * V_31 ;
struct V_89 * V_136 ;
struct V_140 * V_90 ;
struct V_186 * V_187 ;
V_31 = V_62 -> V_160 . V_180 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return NULL ;
}
F_2 ( L_33 , V_185 ) ;
V_187 = V_31 -> V_188 + V_185 ;
V_136 = V_187 -> V_136 ;
if ( ! V_136 ) {
F_2 ( L_34 ,
V_185 ) ;
return NULL ;
}
V_90 = F_12 ( V_136 , struct V_140 , V_89 ) ;
if ( ! V_90 -> V_58 ) {
F_50 ( L_23 ) ;
return NULL ;
}
return V_90 -> V_58 ;
}
static void F_117 (
struct V_30 * V_31 ,
struct V_89 * V_182 ,
struct V_140 * V_90 ,
struct V_56 * V_57 ,
struct V_58 * V_58 ,
T_10 V_185 )
{
struct V_89 * V_189 ;
struct V_186 * V_187 ;
F_2 ( L_35 , V_185 ) ;
V_187 = & ( (struct V_186 * )
V_31 -> V_188 ) [ V_185 ] ;
V_189 = V_187 -> V_136 ;
if ( ! V_189 ) {
F_2 ( L_36 ) ;
V_187 -> V_136 = V_182 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
return;
}
if ( V_90 -> V_58 ) {
if ( V_182 == NULL ) {
F_2 ( L_37 ) ;
V_187 -> V_136 = NULL ;
V_90 -> V_58 = NULL ;
return;
}
F_2 ( L_38 ) ;
V_187 -> V_136 = V_182 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
return;
}
if ( V_182 == NULL ) {
F_2 ( L_39 ) ;
V_187 -> V_136 = NULL ;
return;
}
F_2 ( L_40 ) ;
V_187 -> V_136 = V_182 ;
if ( V_58 -> V_57 != V_57 )
V_58 -> V_57 = V_57 ;
if ( V_90 -> V_58 != V_58 )
V_90 -> V_58 = V_58 ;
F_2 ( L_41 ,
V_90 -> V_58 , V_182 , V_182 -> V_181 ) ;
}
static void F_74 ( struct V_30 * V_31 ,
struct V_140 * V_90 , struct V_58 * V_59 )
{
struct V_56 * V_57 = V_59 -> V_57 ;
unsigned char V_190 [ 3 ] ;
V_190 [ 0 ] = V_59 -> V_178 . V_14 . V_191 ;
V_190 [ 1 ] = V_59 -> V_178 . V_14 . V_192 ;
V_190 [ 2 ] = V_59 -> V_178 . V_14 . V_193 ;
F_113 ( V_31 , NULL , V_90 , V_57 ,
V_59 , V_190 ) ;
F_117 ( V_31 , NULL , V_90 , V_57 ,
V_59 , V_59 -> V_185 ) ;
}
static void F_118 ( struct V_58 * V_59 )
{
struct V_161 * V_194 = V_59 -> V_194 ;
struct V_195 * V_196 = V_194 -> V_196 ;
T_7 * V_62 = F_119 ( V_196 -> V_197 ) ;
struct V_56 * V_57 ;
struct V_30 * V_31 ;
F_35 ( F_120 () ) ;
V_57 = V_59 -> V_57 ;
if ( ! V_57 ) {
F_50 ( L_42 ) ;
F_66 () ;
return;
}
V_31 = V_62 -> V_160 . V_180 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return;
}
F_121 ( V_57 ) ;
F_122 ( V_59 -> V_57 ) ;
F_123 ( V_59 -> V_57 ) ;
}
static int F_124 (
T_7 * V_62 ,
unsigned char * V_198 ,
void * V_58 ,
T_9 * V_178 ,
T_10 V_185 )
{
struct V_195 * V_196 = V_62 -> V_64 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_140 * V_90 ;
struct V_26 * V_27 ;
struct V_89 * V_136 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_58 ;
unsigned char V_199 [ 36 ] ;
unsigned long V_63 ;
int V_200 = ( V_196 -> V_201 ) ? V_196 -> V_201 :
V_202 ;
V_31 = V_62 -> V_160 . V_180 ;
if ( ! V_31 ) {
F_50 ( L_19 ) ;
F_66 () ;
return - V_20 ;
}
V_29 = V_31 -> V_176 ;
if ( ! V_29 ) {
F_50 ( L_43 ) ;
return - V_20 ;
}
V_27 = & V_29 -> V_27 ;
V_57 = F_125 ( V_200 ,
sizeof( struct V_48 ) ,
V_203 ) ;
if ( F_126 ( V_57 ) ) {
F_50 ( L_44 ) ;
return F_127 ( V_57 ) ;
}
memset ( & V_199 , 0 , 36 ) ;
snprintf ( V_199 , sizeof( V_199 ) , L_45 , V_198 ) ;
V_57 -> V_89 = F_128 ( V_27 ,
V_199 ) ;
if ( ! V_57 -> V_89 ) {
F_129 ( V_57 ) ;
return - V_20 ;
}
V_136 = V_57 -> V_89 ;
V_90 = F_12 ( V_136 , struct V_140 , V_89 ) ;
F_36 ( & V_196 -> V_65 , V_63 ) ;
F_113 ( V_31 , V_136 , V_90 , V_57 ,
V_58 , V_178 ) ;
F_117 ( V_31 , V_136 , V_90 , V_57 ,
V_58 , V_185 ) ;
F_38 ( & V_196 -> V_65 , V_63 ) ;
F_130 ( V_136 -> V_27 , V_136 , V_57 , V_59 ) ;
return 0 ;
}
static void F_131 ( struct V_58 * V_59 , T_11 V_178 ,
T_10 V_185 , bool V_204 )
{
struct V_161 * V_194 = V_59 -> V_194 ;
struct V_195 * V_196 = V_194 -> V_196 ;
T_7 * V_62 = F_119 ( V_196 -> V_197 ) ;
struct V_30 * V_31 = V_62 -> V_160 . V_180 ;
struct V_89 * V_136 = V_59 -> V_57 -> V_89 ;
struct V_140 * V_90 = F_12 ( V_136 ,
struct V_140 , V_89 ) ;
T_3 V_179 ;
if ( V_59 -> V_185 != V_185 || V_59 -> V_178 . V_205 != V_178 . V_205 )
F_132 ( L_46 ,
V_59 , V_59 -> V_199 ,
V_59 -> V_185 , V_185 , V_59 -> V_178 . V_14 . V_191 ,
V_59 -> V_178 . V_14 . V_192 , V_59 -> V_178 . V_14 . V_193 , V_178 . V_14 . V_191 ,
V_178 . V_14 . V_192 , V_178 . V_14 . V_193 ) ;
if ( V_59 -> V_185 != V_185 ) {
if ( V_31 -> V_188 [ V_59 -> V_185 ] . V_136 == V_136 )
V_31 -> V_188 [ V_59 -> V_185 ] . V_136 = NULL ;
V_31 -> V_188 [ V_185 ] . V_136 = V_136 ;
V_59 -> V_185 = V_185 ;
}
if ( V_59 -> V_178 . V_205 != V_178 . V_205 ) {
V_179 = ( ( ( T_3 ) V_59 -> V_178 . V_14 . V_191 << 16 ) |
( ( T_3 ) V_59 -> V_178 . V_14 . V_192 << 8 ) |
( ( T_3 ) V_59 -> V_178 . V_14 . V_193 ) ) ;
if ( F_112 ( & V_31 -> V_143 , V_179 ) )
F_133 ( F_72 ( & V_31 -> V_143 , V_179 ) != V_136 ,
L_47 ,
V_59 -> V_178 . V_14 . V_191 , V_59 -> V_178 . V_14 . V_192 , V_59 -> V_178 . V_14 . V_193 ) ;
else
F_133 ( 1 , L_48 ,
V_59 -> V_178 . V_14 . V_191 , V_59 -> V_178 . V_14 . V_192 , V_59 -> V_178 . V_14 . V_193 ) ;
V_179 = ( ( ( T_3 ) V_178 . V_14 . V_191 << 16 ) |
( ( T_3 ) V_178 . V_14 . V_192 << 8 ) |
( ( T_3 ) V_178 . V_14 . V_193 ) ) ;
if ( F_112 ( & V_31 -> V_143 , V_179 ) ) {
F_133 ( 1 , L_49 ,
V_178 . V_14 . V_191 , V_178 . V_14 . V_192 , V_178 . V_14 . V_193 ) ;
F_115 ( & V_31 -> V_143 , V_179 , V_136 ) ;
} else {
F_73 ( & V_31 -> V_143 , V_179 , V_136 , V_110 ) ;
}
V_59 -> V_178 = V_178 ;
V_90 -> V_142 = V_179 ;
}
V_59 -> V_204 = V_204 ;
V_59 -> V_206 = 1 ;
V_59 -> V_207 = 0 ;
}
static int F_134 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_135 ( & V_31 -> V_143 ) ;
if ( V_25 ) {
F_50 ( L_50 ) ;
return V_25 ;
}
V_31 -> V_188 = F_136 ( sizeof( struct V_186 ) *
65536 ) ;
if ( ! V_31 -> V_188 ) {
F_50 ( L_51 ,
sizeof( struct V_186 ) * 65536 ) ;
F_137 ( & V_31 -> V_143 ) ;
return - V_174 ;
}
memset ( V_31 -> V_188 , 0 , sizeof( struct V_186 )
* 65536 ) ;
F_2 ( L_52 ,
sizeof( struct V_186 ) * 65536 ) ;
return 0 ;
}
static int F_138 ( struct V_61 * V_62 ,
void * V_180 ,
T_2 V_208 , T_2 V_209 )
{
struct V_195 * V_196 = V_62 -> V_64 ;
struct V_30 * V_31 =
(struct V_30 * ) V_180 ;
V_196 -> V_194 . V_210 = & V_211 ;
V_62 -> V_160 . V_180 = V_180 ;
V_31 -> V_156 = V_62 ;
return 0 ;
}
static struct V_137 * F_139 (
struct V_212 * V_213 ,
struct V_168 * V_169 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_167 = - V_164 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_101 ( - V_20 ) ;
V_31 = F_102 ( sizeof( struct V_30 ) , V_173 ) ;
if ( ! V_31 ) {
F_50 ( L_53 ) ;
return F_101 ( - V_174 ) ;
}
V_31 -> V_214 = V_22 ;
F_3 ( & V_31 -> V_215 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_54 , ( unsigned long long ) V_22 ) ;
V_167 = F_134 ( V_31 ) ;
if ( V_167 != 0 )
goto V_216;
V_167 = F_140 ( V_31 , V_22 , 0 , 0 ,
F_138 ) ;
if ( V_167 != 0 )
goto V_217;
return & V_31 -> V_139 ;
V_217:
F_141 ( V_31 -> V_188 ) ;
F_137 ( & V_31 -> V_143 ) ;
V_216:
F_104 ( V_31 ) ;
return F_101 ( V_167 ) ;
}
static void F_142 ( struct V_137 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_61 * V_62 = V_31 -> V_156 ;
struct V_89 * V_141 ;
T_3 V_179 = 0 ;
if ( V_62 -> V_160 . V_161 && ! V_62 -> V_160 . V_161 -> V_218 )
F_143 ( V_62 -> V_160 . V_161 ) ;
F_144 ( V_62 ) ;
F_141 ( V_31 -> V_188 ) ;
F_145 (&lport->lport_fcport_map, key, node)
F_72 ( & V_31 -> V_143 , V_179 ) ;
F_137 ( & V_31 -> V_143 ) ;
F_104 ( V_31 ) ;
}
static int F_146 ( struct V_61 * V_155 ,
void * V_180 ,
T_2 V_208 , T_2 V_209 )
{
struct V_219 * V_220 ;
struct V_221 * V_222 = V_155 -> V_223 ;
struct V_61 * V_224 ;
struct V_30 * V_31 =
(struct V_30 * ) V_180 ;
struct V_30 * V_225 =
(struct V_30 * ) V_155 -> V_160 . V_180 ;
struct V_226 V_227 ;
if ( ! F_147 ( V_155 ) ) {
F_50 ( L_55 ) ;
return - V_165 ;
}
if ( ! V_225 || ! V_225 -> V_176 ||
! F_83 ( & V_225 -> V_176 -> V_152 ) ) {
F_50 ( L_56 ) ;
return - V_165 ;
}
memset ( & V_227 , 0 , sizeof( V_227 ) ) ;
V_227 . V_199 = V_208 ;
V_227 . V_228 = V_209 ;
V_227 . V_229 = V_230 ;
V_227 . V_231 = V_232 ;
V_227 . V_233 = false ;
V_220 = F_148 ( V_222 , 0 , & V_227 ) ;
if ( ! V_220 ) {
F_50 ( L_57 ) ;
return - V_164 ;
}
V_224 = (struct V_61 * ) V_220 -> V_234 ;
V_224 -> V_160 . V_180 = V_180 ;
V_31 -> V_156 = V_224 ;
F_149 ( V_224 -> V_223 ) ;
return 0 ;
}
static struct V_137 * F_150 (
struct V_212 * V_213 ,
struct V_168 * V_169 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_235 , V_208 , V_209 ;
char * V_236 , V_237 [ 128 ] ;
int V_167 ;
snprintf ( V_237 , 128 , L_58 , V_1 ) ;
V_236 = strchr ( V_237 , '@' ) ;
if ( ! V_236 ) {
F_50 ( L_59 ) ;
return F_101 ( - V_20 ) ;
}
* V_236 ++ = '\0' ;
if ( F_1 ( V_237 , & V_235 , 1 ) < 0 )
return F_101 ( - V_20 ) ;
if ( F_9 ( V_236 , strlen ( V_236 ) + 1 ,
& V_208 , & V_209 ) < 0 )
return F_101 ( - V_20 ) ;
V_31 = F_102 ( sizeof( struct V_30 ) , V_173 ) ;
if ( ! V_31 ) {
F_50 ( L_60 ) ;
return F_101 ( - V_174 ) ;
}
V_31 -> V_238 = V_208 ;
V_31 -> V_239 = V_209 ;
sprintf ( V_31 -> V_32 , L_54 , ( unsigned long long ) V_208 ) ;
V_167 = F_134 ( V_31 ) ;
if ( V_167 != 0 )
goto V_216;
V_167 = F_140 ( V_31 , V_235 , V_208 , V_209 ,
F_146 ) ;
if ( V_167 != 0 )
goto V_217;
return & V_31 -> V_139 ;
V_217:
F_141 ( V_31 -> V_188 ) ;
F_137 ( & V_31 -> V_143 ) ;
V_216:
F_104 ( V_31 ) ;
return F_101 ( V_167 ) ;
}
static void F_151 ( struct V_137 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_139 ) ;
struct V_61 * V_224 = V_31 -> V_156 ;
struct V_195 * V_196 = V_224 -> V_64 ;
T_7 * V_155 = F_119 ( V_196 -> V_197 ) ;
F_152 ( V_224 -> V_223 ) ;
F_153 ( V_224 -> V_219 ) ;
F_152 ( V_155 -> V_223 ) ;
F_104 ( V_31 ) ;
}
static T_1 F_154 ( struct V_148 * V_149 ,
char * V_150 )
{
return sprintf ( V_150 ,
L_61
V_240 L_62 , V_241 , F_155 () -> V_242 ,
F_155 () -> V_243 ) ;
}
static int F_156 ( void )
{
int V_167 ;
F_2 ( L_63
V_240 L_62 , V_241 , F_155 () -> V_242 ,
F_155 () -> V_243 ) ;
V_167 = F_157 ( & V_244 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_157 ( & V_245 ) ;
if ( V_167 )
goto V_246;
V_47 = F_158 ( L_64 ,
V_247 , 0 ) ;
if ( ! V_47 ) {
V_167 = - V_174 ;
goto V_248;
}
V_249 = F_158 ( L_65 , 0 , 0 ) ;
if ( ! V_249 ) {
V_167 = - V_174 ;
goto V_250;
}
return 0 ;
V_250:
F_159 ( V_47 ) ;
V_248:
F_160 ( & V_245 ) ;
V_246:
F_160 ( & V_244 ) ;
return V_167 ;
}
static void F_161 ( void )
{
F_159 ( V_249 ) ;
F_159 ( V_47 ) ;
F_160 ( & V_244 ) ;
F_160 ( & V_245 ) ;
}
static int T_12 F_162 ( void )
{
int V_167 ;
V_167 = F_156 () ;
if ( V_167 < 0 )
return V_167 ;
return 0 ;
}
static void T_13 F_163 ( void )
{
F_161 () ;
}
