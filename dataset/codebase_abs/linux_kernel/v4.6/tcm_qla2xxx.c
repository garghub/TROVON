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
V_49 -> V_53 -> V_54 . V_55 ++ ;
V_49 -> V_51 |= V_52 ;
F_22 ( & V_49 -> V_46 , 0 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
V_49 -> V_53 -> V_54 . V_56 ++ ;
V_49 -> V_50 = 1 ;
F_29 ( V_49 -> V_51 & V_57 ) ;
V_49 -> V_51 |= V_57 ;
F_24 ( & V_49 -> V_42 , F_26 ) ;
F_30 ( F_31 () , V_47 , & V_49 -> V_42 ) ;
}
static int F_32 ( struct V_46 * V_46 )
{
struct V_48 * V_49 ;
if ( ( V_46 -> V_58 & V_59 ) == 0 ) {
V_49 = F_12 ( V_46 , struct V_48 , V_46 ) ;
V_49 -> V_51 |= V_60 ;
}
return F_33 ( V_46 ) ;
}
static void F_34 ( struct V_46 * V_46 )
{
struct V_48 * V_49 ;
if ( V_46 -> V_58 & V_59 ) {
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_35 ( V_44 ) ;
return;
}
V_49 = F_12 ( V_46 , struct V_48 , V_46 ) ;
F_36 ( V_49 ) ;
}
static int F_37 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
struct V_66 * V_53 ;
unsigned long V_67 ;
F_29 ( ! V_64 ) ;
V_53 = V_64 -> V_53 ;
F_38 ( & V_53 -> V_68 -> V_69 . V_70 , V_67 ) ;
F_39 ( V_62 ) ;
F_40 ( & V_53 -> V_68 -> V_69 . V_70 , V_67 ) ;
return 1 ;
}
static void F_41 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
struct V_66 * V_53 ;
unsigned long V_67 ;
F_29 ( ! V_64 ) ;
V_53 = V_64 -> V_53 ;
F_38 ( & V_53 -> V_68 -> V_69 . V_70 , V_67 ) ;
F_42 ( V_64 ) ;
F_40 ( & V_53 -> V_68 -> V_69 . V_70 , V_67 ) ;
}
static T_3 F_43 ( struct V_61 * V_62 )
{
return 0 ;
}
static int F_44 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( V_49 -> V_71 ) {
F_2 ( L_5
L_6 ,
V_49 , V_49 -> V_46 . V_72 . V_73 . V_74 ,
V_49 -> V_46 . V_75 ,
V_49 -> V_46 . V_76 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_51 |= V_77 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_80 = F_45 ( V_46 ) ;
V_49 -> V_81 = V_46 -> V_82 ;
V_49 -> V_83 = V_46 -> V_84 ;
V_49 -> V_85 = V_46 -> V_86 ;
V_49 -> V_87 = V_46 -> V_88 ;
V_49 -> V_89 = V_46 -> V_90 -> V_91 . V_92 ;
V_46 -> V_93 = 0 ;
return F_46 ( V_49 ) ;
}
static int F_47 ( struct V_46 * V_46 )
{
unsigned long V_67 ;
F_38 ( & V_46 -> V_94 , V_67 ) ;
if ( V_46 -> V_76 == V_95 ||
V_46 -> V_76 == V_96 ) {
F_40 ( & V_46 -> V_94 , V_67 ) ;
F_48 ( & V_46 -> V_97 ,
50 ) ;
return 0 ;
}
F_40 ( & V_46 -> V_94 , V_67 ) ;
return 0 ;
}
static void F_49 ( struct V_98 * V_99 )
{
return;
}
static int F_50 ( struct V_46 * V_46 )
{
if ( ! ( V_46 -> V_58 & V_59 ) ) {
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
return V_49 -> V_100 ;
}
return 0 ;
}
static int F_51 ( T_7 * V_53 , struct V_48 * V_49 ,
unsigned char * V_101 , T_8 V_79 , int V_102 ,
int V_103 , int V_104 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_67 = V_105 ;
if ( V_104 )
V_67 |= V_106 ;
if ( V_46 -> V_107 != V_108 )
V_67 |= V_109 ;
V_64 = V_49 -> V_64 ;
if ( ! V_64 ) {
F_52 ( L_7 ) ;
return - V_20 ;
}
V_62 = V_64 -> V_62 ;
if ( ! V_62 ) {
F_52 ( L_8 ) ;
return - V_20 ;
}
V_49 -> V_53 -> V_54 . V_110 ++ ;
return F_53 ( V_46 , V_62 , V_101 , & V_49 -> V_111 [ 0 ] ,
V_49 -> V_112 , V_79 , V_102 ,
V_103 , V_67 ) ;
}
static void F_54 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
unsigned long V_67 ;
V_49 -> V_50 = 0 ;
F_38 ( & V_49 -> V_113 , V_67 ) ;
V_49 -> V_51 |= V_114 ;
if ( V_49 -> V_71 ) {
V_49 -> V_51 |= V_115 ;
F_40 ( & V_49 -> V_113 , V_67 ) ;
F_28 ( V_49 ) ;
return;
}
F_40 ( & V_49 -> V_113 , V_67 ) ;
V_49 -> V_53 -> V_54 . V_116 ++ ;
if ( ! V_49 -> V_117 ) {
if ( V_49 -> V_46 . V_75 & V_118 ) {
F_55 ( & V_49 -> V_46 . V_97 ) ;
return;
}
if ( V_49 -> V_46 . V_93 )
F_56 ( & V_49 -> V_46 ,
V_49 -> V_46 . V_93 ) ;
else
F_56 ( & V_49 -> V_46 ,
V_119 ) ;
return;
}
return F_57 ( & V_49 -> V_46 ) ;
}
static void F_58 ( struct V_48 * V_49 )
{
V_49 -> V_51 |= V_120 ;
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_54 ) ;
F_30 ( F_31 () , V_47 , & V_49 -> V_42 ) ;
}
static void F_59 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
F_60 ( & V_49 -> V_46 . V_72 ) ;
F_56 ( & V_49 -> V_46 , V_49 -> V_46 . V_93 ) ;
}
static void F_61 ( struct V_48 * V_49 )
{
F_24 ( & V_49 -> V_42 , F_59 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static int F_62 ( struct V_43 * V_44 , T_8 V_121 ,
T_9 V_122 , T_8 V_123 )
{
struct V_63 * V_64 = V_44 -> V_64 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
return F_63 ( V_46 , V_64 -> V_62 , NULL , V_121 , V_44 ,
V_122 , V_124 , V_123 , V_105 ) ;
}
static int F_64 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( V_49 -> V_71 ) {
F_2 ( L_9
L_6 ,
V_49 , V_49 -> V_46 . V_72 . V_73 . V_74 ,
V_49 -> V_46 . V_75 ,
V_49 -> V_46 . V_76 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_51 |= V_125 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_80 = F_45 ( V_46 ) ;
V_49 -> V_81 = V_46 -> V_82 ;
V_49 -> V_83 = V_46 -> V_84 ;
V_49 -> V_126 = 0 ;
V_49 -> V_85 = V_46 -> V_86 ;
V_49 -> V_87 = V_46 -> V_88 ;
V_49 -> V_89 = V_46 -> V_90 -> V_91 . V_92 ;
V_46 -> V_93 = 0 ;
return F_65 ( V_49 , V_127 | V_128 ,
V_46 -> V_129 ) ;
}
static int F_66 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
int V_130 = V_128 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_83 = NULL ;
V_49 -> V_81 = 0 ;
V_49 -> V_126 = 0 ;
V_49 -> V_80 = F_45 ( V_46 ) ;
if ( V_49 -> V_51 & V_131 ) {
F_67 ( L_10 , V_49 ) ;
F_68 () ;
}
V_49 -> V_51 |= V_131 ;
if ( V_46 -> V_132 == V_133 ) {
if ( V_46 -> V_58 & V_134 ) {
V_46 -> V_58 &= ~ V_134 ;
V_46 -> V_135 = 0 ;
}
V_46 -> V_58 |= V_136 ;
V_46 -> V_135 += V_46 -> V_79 ;
V_49 -> V_78 = 0 ;
}
return F_65 ( V_49 , V_130 , V_46 -> V_129 ) ;
}
static void F_69 ( struct V_46 * V_46 )
{
struct V_137 * V_138 = V_46 -> V_137 ;
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_2 ( L_11 ,
V_44 , V_138 -> V_139 , V_138 -> V_140 ) ;
switch ( V_138 -> V_140 ) {
case V_141 :
V_44 -> V_142 = V_143 ;
break;
case V_144 :
V_44 -> V_142 = V_145 ;
break;
case V_146 :
V_44 -> V_142 = V_147 ;
break;
case V_148 :
default:
V_44 -> V_142 = V_149 ;
break;
}
F_70 ( V_44 ) ;
}
static void F_71 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
unsigned long V_67 ;
if ( F_72 ( V_49 ) )
return;
F_38 ( & V_49 -> V_113 , V_67 ) ;
if ( ( V_49 -> V_100 == V_150 ) ||
( ( V_49 -> V_100 == V_151 ) &&
F_73 ( V_49 -> V_51 ) ) ) {
V_49 -> V_51 |= V_115 ;
F_40 ( & V_49 -> V_113 , V_67 ) ;
F_28 ( V_49 ) ;
return;
}
F_40 ( & V_49 -> V_113 , V_67 ) ;
return;
}
static void F_74 ( struct V_63 * V_64 )
{
struct V_98 * V_152 = V_64 -> V_62 -> V_98 ;
struct V_26 * V_27 = V_152 -> V_27 ;
struct V_153 * V_153 = V_27 -> V_154 ;
struct V_30 * V_31 = F_12 ( V_153 ,
struct V_30 , V_155 ) ;
struct V_156 * V_99 = F_12 ( V_152 ,
struct V_156 , V_98 ) ;
void * V_157 ;
F_2 ( L_12 , V_99 -> V_158 ) ;
V_157 = F_75 ( & V_31 -> V_159 , V_99 -> V_158 ) ;
if ( F_27 ( V_157 && ( V_157 != V_152 ) ) ) {
F_76 ( & V_31 -> V_159 , V_99 -> V_158 ,
V_157 , V_124 ) ;
}
F_2 ( L_13 ,
V_152 , V_99 -> V_160 , V_99 -> V_158 ) ;
F_77 ( V_31 , V_99 , V_64 ) ;
}
static void F_78 ( struct V_161 * V_161 )
{
struct V_61 * V_62 = F_12 ( V_161 ,
struct V_61 , V_162 ) ;
F_42 ( V_62 -> V_65 ) ;
}
static void F_79 ( struct V_63 * V_64 )
{
if ( ! V_64 )
return;
F_80 ( & V_64 -> V_53 -> V_68 -> V_69 . V_70 ) ;
F_81 ( & V_64 -> V_62 -> V_162 , F_78 ) ;
}
static void F_82 ( struct V_63 * V_64 )
{
F_80 ( & V_64 -> V_53 -> V_68 -> V_69 . V_70 ) ;
F_39 ( V_64 -> V_62 ) ;
}
static int F_83 ( struct V_98 * V_152 ,
const char * V_1 )
{
struct V_156 * V_99 =
F_12 ( V_152 , struct V_156 , V_98 ) ;
T_2 V_23 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return - V_20 ;
V_99 -> V_160 = V_23 ;
F_3 ( & V_99 -> V_163 [ 0 ] , V_10 , V_23 ) ;
return 0 ;
}
static T_1 F_84 ( struct V_164 * V_165 ,
char * V_166 )
{
struct V_26 * V_27 = F_85 ( V_165 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_166 , V_167 , L_14 ,
F_86 ( & V_29 -> V_168 ) ) ;
}
static void F_87 ( struct V_41 * V_42 )
{
struct V_28 * V_169 = F_12 ( V_42 ,
struct V_28 , V_170 ) ;
struct V_26 * V_27 = & V_169 -> V_27 ;
struct V_66 * V_171 = V_169 -> V_31 -> V_172 ;
if ( ! F_88 ( & V_27 -> V_173 . V_174 ) ) {
F_89 ( & V_169 -> V_168 , 1 ) ;
F_90 ( V_171 ) ;
}
F_55 ( & V_169 -> V_175 ) ;
}
static void F_91 ( struct V_41 * V_42 )
{
struct V_28 * V_169 = F_12 ( V_42 ,
struct V_28 , V_170 ) ;
struct V_26 * V_27 = & V_169 -> V_27 ;
struct V_66 * V_171 = V_169 -> V_31 -> V_172 ;
if ( ! F_92 ( V_171 -> V_176 . V_177 ) ) {
F_89 ( & V_169 -> V_168 , 0 ) ;
F_93 ( & V_27 -> V_173 . V_174 ) ;
}
F_55 ( & V_169 -> V_175 ) ;
}
static T_1 F_94 ( struct V_164 * V_165 ,
const char * V_166 , T_4 V_21 )
{
struct V_26 * V_27 = F_85 ( V_165 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_178 ;
int V_25 ;
V_25 = F_95 ( V_166 , 0 , & V_178 ) ;
if ( V_25 < 0 ) {
F_52 ( L_15 , V_25 ) ;
return - V_20 ;
}
if ( ( V_178 != 1 ) && ( V_178 != 0 ) ) {
F_52 ( L_16 , V_178 ) ;
return - V_20 ;
}
if ( V_178 ) {
if ( F_86 ( & V_29 -> V_168 ) )
return - V_179 ;
F_24 ( & V_29 -> V_170 , F_87 ) ;
} else {
if ( ! F_86 ( & V_29 -> V_168 ) )
return V_21 ;
F_24 ( & V_29 -> V_170 , F_91 ) ;
}
F_96 ( & V_29 -> V_175 ) ;
F_97 ( & V_29 -> V_170 ) ;
F_98 ( & V_29 -> V_175 ) ;
if ( V_178 ) {
if ( ! F_86 ( & V_29 -> V_168 ) )
return - V_180 ;
} else {
if ( F_86 ( & V_29 -> V_168 ) )
return - V_181 ;
}
return V_21 ;
}
static T_1 F_99 ( struct V_164 * V_165 ,
char * V_166 )
{
return F_100 ( F_85 ( V_165 ) , V_166 ) ;
}
static T_1 F_101 ( struct V_164 * V_165 ,
const char * V_166 , T_4 V_21 )
{
struct V_26 * V_27 = F_85 ( V_165 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_182 ;
int V_183 = F_95 ( V_166 , 0 , & V_182 ) ;
if ( V_183 ) {
F_52 ( L_17 , V_183 ) ;
return V_183 ;
}
if ( V_182 != 0 && V_182 != 1 && V_182 != 3 ) {
F_52 ( L_18 , V_182 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_182 ;
return V_21 ;
}
static T_1 F_102 ( struct V_164 * V_165 ,
char * V_166 )
{
struct V_26 * V_27 = F_85 ( V_165 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_166 , L_14 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_103 (
struct V_153 * V_2 ,
struct V_184 * V_185 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_155 ) ;
struct V_28 * V_29 ;
unsigned long V_186 ;
int V_183 ;
if ( strstr ( V_1 , L_19 ) != V_1 )
return F_104 ( - V_20 ) ;
if ( F_95 ( V_1 + 5 , 10 , & V_186 ) || V_186 > V_187 )
return F_104 ( - V_20 ) ;
if ( ( V_186 != 1 ) ) {
F_52 ( L_20 ) ;
return F_104 ( - V_188 ) ;
}
V_29 = F_105 ( sizeof( struct V_28 ) , V_189 ) ;
if ( ! V_29 ) {
F_52 ( L_21 ) ;
return F_104 ( - V_190 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_186 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_183 = F_106 ( V_2 , & V_29 -> V_27 , V_191 ) ;
if ( V_183 < 0 ) {
F_107 ( V_29 ) ;
return NULL ;
}
V_31 -> V_192 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_108 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_66 * V_53 = V_31 -> V_172 ;
if ( V_53 -> V_176 . V_177 && ! V_53 -> V_176 . V_177 -> V_193 )
F_92 ( V_53 -> V_176 . V_177 ) ;
F_109 ( V_27 ) ;
V_31 -> V_192 = NULL ;
F_107 ( V_29 ) ;
}
static T_1 F_110 ( struct V_164 * V_165 ,
char * V_166 )
{
return F_84 ( V_165 , V_166 ) ;
}
static T_1 F_111 ( struct V_164 * V_165 ,
const char * V_166 , T_4 V_21 )
{
struct V_26 * V_27 = F_85 ( V_165 ) ;
struct V_153 * V_153 = V_27 -> V_154 ;
struct V_30 * V_31 = F_12 ( V_153 ,
struct V_30 , V_155 ) ;
struct V_66 * V_53 = V_31 -> V_172 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_178 ;
int V_25 ;
V_25 = F_95 ( V_166 , 0 , & V_178 ) ;
if ( V_25 < 0 ) {
F_52 ( L_15 , V_25 ) ;
return - V_20 ;
}
if ( ( V_178 != 1 ) && ( V_178 != 0 ) ) {
F_52 ( L_16 , V_178 ) ;
return - V_20 ;
}
if ( V_178 ) {
if ( F_86 ( & V_29 -> V_168 ) )
return - V_179 ;
F_89 ( & V_29 -> V_168 , 1 ) ;
F_90 ( V_53 ) ;
} else {
if ( ! F_86 ( & V_29 -> V_168 ) )
return V_21 ;
F_89 ( & V_29 -> V_168 , 0 ) ;
F_92 ( V_53 -> V_176 . V_177 ) ;
}
return V_21 ;
}
static struct V_26 * F_112 (
struct V_153 * V_2 ,
struct V_184 * V_185 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_155 ) ;
struct V_28 * V_29 ;
unsigned long V_186 ;
int V_183 ;
if ( strstr ( V_1 , L_19 ) != V_1 )
return F_104 ( - V_20 ) ;
if ( F_95 ( V_1 + 5 , 10 , & V_186 ) || V_186 > V_187 )
return F_104 ( - V_20 ) ;
V_29 = F_105 ( sizeof( struct V_28 ) , V_189 ) ;
if ( ! V_29 ) {
F_52 ( L_21 ) ;
return F_104 ( - V_190 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_186 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_183 = F_106 ( V_2 , & V_29 -> V_27 , V_191 ) ;
if ( V_183 < 0 ) {
F_107 ( V_29 ) ;
return NULL ;
}
V_31 -> V_192 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_63 * F_113 (
T_7 * V_53 ,
const T_9 * V_194 )
{
struct V_30 * V_31 ;
struct V_98 * V_152 ;
struct V_156 * V_99 ;
T_3 V_195 ;
V_31 = V_53 -> V_176 . V_196 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_68 () ;
return NULL ;
}
V_195 = F_114 ( V_194 ) ;
F_2 ( L_23 , V_195 ) ;
V_152 = F_115 ( & V_31 -> V_159 , V_195 ) ;
if ( ! V_152 ) {
F_2 ( L_24 , V_195 ) ;
return NULL ;
}
F_2 ( L_25 ,
V_152 , V_152 -> V_197 ) ;
V_99 = F_12 ( V_152 , struct V_156 , V_98 ) ;
if ( ! V_99 -> V_63 ) {
F_52 ( L_26 ) ;
return NULL ;
}
return V_99 -> V_63 ;
}
static void F_116 (
struct V_30 * V_31 ,
struct V_98 * V_198 ,
struct V_156 * V_99 ,
struct V_61 * V_62 ,
struct V_63 * V_63 ,
T_9 * V_194 )
{
T_3 V_195 ;
void * V_199 ;
int V_25 ;
V_195 = F_114 ( V_194 ) ;
F_2 ( L_27 , V_195 ) ;
V_199 = F_115 ( & V_31 -> V_159 , V_195 ) ;
if ( ! V_199 ) {
if ( V_198 ) {
F_2 ( L_28 ) ;
V_99 -> V_158 = V_195 ;
V_25 = F_76 ( & V_31 -> V_159 , V_195 ,
V_198 , V_124 ) ;
if ( V_25 )
F_117 ( V_200 L_29 ,
( int ) V_195 ) ;
} else {
F_2 ( L_30 ) ;
}
V_63 -> V_62 = V_62 ;
V_99 -> V_63 = V_63 ;
return;
}
if ( V_99 -> V_63 ) {
if ( V_198 == NULL ) {
F_2 ( L_31 ) ;
F_75 ( & V_31 -> V_159 , V_195 ) ;
V_99 -> V_63 = NULL ;
return;
}
F_2 ( L_32 ) ;
F_118 ( & V_31 -> V_159 , V_195 , V_198 ) ;
V_63 -> V_62 = V_62 ;
V_99 -> V_63 = V_63 ;
return;
}
if ( V_198 == NULL ) {
F_2 ( L_33 ) ;
F_75 ( & V_31 -> V_159 , V_195 ) ;
return;
}
F_2 ( L_34 ) ;
F_118 ( & V_31 -> V_159 , V_195 , V_198 ) ;
V_63 -> V_62 = V_62 ;
V_99 -> V_63 = V_63 ;
F_2 ( L_35 ,
V_99 -> V_63 , V_198 , V_198 -> V_197 ) ;
}
static struct V_63 * F_119 (
T_7 * V_53 ,
const T_10 V_201 )
{
struct V_30 * V_31 ;
struct V_98 * V_152 ;
struct V_156 * V_99 ;
struct V_202 * V_203 ;
V_31 = V_53 -> V_176 . V_196 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_68 () ;
return NULL ;
}
F_2 ( L_36 , V_201 ) ;
V_203 = V_31 -> V_204 + V_201 ;
V_152 = V_203 -> V_152 ;
if ( ! V_152 ) {
F_2 ( L_37 ,
V_201 ) ;
return NULL ;
}
V_99 = F_12 ( V_152 , struct V_156 , V_98 ) ;
if ( ! V_99 -> V_63 ) {
F_52 ( L_26 ) ;
return NULL ;
}
return V_99 -> V_63 ;
}
static void F_120 (
struct V_30 * V_31 ,
struct V_98 * V_198 ,
struct V_156 * V_99 ,
struct V_61 * V_62 ,
struct V_63 * V_63 ,
T_10 V_201 )
{
struct V_98 * V_205 ;
struct V_202 * V_203 ;
F_2 ( L_38 , V_201 ) ;
V_203 = & ( (struct V_202 * )
V_31 -> V_204 ) [ V_201 ] ;
V_205 = V_203 -> V_152 ;
if ( ! V_205 ) {
F_2 ( L_39 ) ;
V_203 -> V_152 = V_198 ;
if ( V_63 -> V_62 != V_62 )
V_63 -> V_62 = V_62 ;
if ( V_99 -> V_63 != V_63 )
V_99 -> V_63 = V_63 ;
return;
}
if ( V_99 -> V_63 ) {
if ( V_198 == NULL ) {
F_2 ( L_40 ) ;
V_203 -> V_152 = NULL ;
V_99 -> V_63 = NULL ;
return;
}
F_2 ( L_41 ) ;
V_203 -> V_152 = V_198 ;
if ( V_63 -> V_62 != V_62 )
V_63 -> V_62 = V_62 ;
if ( V_99 -> V_63 != V_63 )
V_99 -> V_63 = V_63 ;
return;
}
if ( V_198 == NULL ) {
F_2 ( L_42 ) ;
V_203 -> V_152 = NULL ;
return;
}
F_2 ( L_43 ) ;
V_203 -> V_152 = V_198 ;
if ( V_63 -> V_62 != V_62 )
V_63 -> V_62 = V_62 ;
if ( V_99 -> V_63 != V_63 )
V_99 -> V_63 = V_63 ;
F_2 ( L_44 ,
V_99 -> V_63 , V_198 , V_198 -> V_197 ) ;
}
static void F_77 ( struct V_30 * V_31 ,
struct V_156 * V_99 , struct V_63 * V_64 )
{
struct V_61 * V_62 = V_64 -> V_62 ;
unsigned char V_206 [ 3 ] ;
V_206 [ 0 ] = V_64 -> V_194 . V_14 . V_207 ;
V_206 [ 1 ] = V_64 -> V_194 . V_14 . V_208 ;
V_206 [ 2 ] = V_64 -> V_194 . V_14 . V_209 ;
F_116 ( V_31 , NULL , V_99 , V_62 ,
V_64 , V_206 ) ;
F_120 ( V_31 , NULL , V_99 , V_62 ,
V_64 , V_64 -> V_201 ) ;
}
static void F_121 ( struct V_63 * V_64 )
{
struct V_177 * V_69 = V_64 -> V_69 ;
struct V_210 * V_211 = V_69 -> V_211 ;
T_7 * V_53 = F_122 ( V_211 -> V_212 ) ;
struct V_61 * V_62 ;
struct V_30 * V_31 ;
F_29 ( F_123 () ) ;
V_62 = V_64 -> V_62 ;
if ( ! V_62 ) {
F_52 ( L_45 ) ;
F_68 () ;
return;
}
V_31 = V_53 -> V_176 . V_196 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_68 () ;
return;
}
F_124 ( V_62 ) ;
F_125 ( V_64 -> V_62 ) ;
F_126 ( V_64 -> V_62 ) ;
}
static int F_127 ( struct V_26 * V_27 ,
struct V_61 * V_62 , void * V_213 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_210 * V_211 = V_31 -> V_172 -> V_68 ;
struct V_98 * V_152 = V_62 -> V_98 ;
struct V_156 * V_99 = F_12 ( V_152 ,
struct V_156 , V_98 ) ;
struct V_63 * V_214 = V_213 ;
T_10 V_201 = V_214 -> V_201 ;
unsigned long V_67 ;
unsigned char V_206 [ 3 ] ;
V_206 [ 0 ] = V_214 -> V_194 . V_14 . V_207 ;
V_206 [ 1 ] = V_214 -> V_194 . V_14 . V_208 ;
V_206 [ 2 ] = V_214 -> V_194 . V_14 . V_209 ;
F_38 ( & V_211 -> V_69 . V_70 , V_67 ) ;
F_116 ( V_31 , V_152 , V_99 ,
V_62 , V_214 , V_206 ) ;
F_120 ( V_31 , V_152 , V_99 ,
V_62 , V_214 , V_201 ) ;
F_40 ( & V_211 -> V_69 . V_70 , V_67 ) ;
return 0 ;
}
static int F_128 (
T_7 * V_53 ,
unsigned char * V_215 ,
struct V_63 * V_214 )
{
struct V_210 * V_211 = V_53 -> V_68 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_61 * V_62 ;
unsigned char V_216 [ 36 ] ;
int V_217 = ( V_211 -> V_218 ) ? V_211 -> V_218 :
V_219 ;
V_31 = V_53 -> V_176 . V_196 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_68 () ;
return - V_20 ;
}
V_29 = V_31 -> V_192 ;
if ( ! V_29 ) {
F_52 ( L_46 ) ;
return - V_20 ;
}
memset ( & V_216 , 0 , 36 ) ;
snprintf ( V_216 , sizeof( V_216 ) , L_47 , V_215 ) ;
V_62 = F_129 ( & V_29 -> V_27 , V_217 ,
sizeof( struct V_48 ) ,
V_220 , V_216 ,
V_214 , F_127 ) ;
if ( F_130 ( V_62 ) )
return F_131 ( V_62 ) ;
return 0 ;
}
static void F_132 ( struct V_63 * V_64 , T_11 V_194 ,
T_10 V_201 , bool V_221 )
{
struct V_177 * V_69 = V_64 -> V_69 ;
struct V_210 * V_211 = V_69 -> V_211 ;
T_7 * V_53 = F_122 ( V_211 -> V_212 ) ;
struct V_30 * V_31 = V_53 -> V_176 . V_196 ;
struct V_98 * V_152 = V_64 -> V_62 -> V_98 ;
struct V_156 * V_99 = F_12 ( V_152 ,
struct V_156 , V_98 ) ;
T_3 V_195 ;
if ( V_64 -> V_201 != V_201 || V_64 -> V_194 . V_222 != V_194 . V_222 )
F_133 ( L_48 ,
V_64 , V_64 -> V_216 ,
V_64 -> V_201 , V_201 , V_64 -> V_194 . V_14 . V_207 ,
V_64 -> V_194 . V_14 . V_208 , V_64 -> V_194 . V_14 . V_209 , V_194 . V_14 . V_207 ,
V_194 . V_14 . V_208 , V_194 . V_14 . V_209 ) ;
if ( V_64 -> V_201 != V_201 ) {
if ( V_31 -> V_204 [ V_64 -> V_201 ] . V_152 == V_152 )
V_31 -> V_204 [ V_64 -> V_201 ] . V_152 = NULL ;
V_31 -> V_204 [ V_201 ] . V_152 = V_152 ;
V_64 -> V_201 = V_201 ;
}
if ( V_64 -> V_194 . V_222 != V_194 . V_222 ) {
V_195 = ( ( ( T_3 ) V_64 -> V_194 . V_14 . V_207 << 16 ) |
( ( T_3 ) V_64 -> V_194 . V_14 . V_208 << 8 ) |
( ( T_3 ) V_64 -> V_194 . V_14 . V_209 ) ) ;
if ( F_115 ( & V_31 -> V_159 , V_195 ) )
F_134 ( F_75 ( & V_31 -> V_159 , V_195 ) != V_152 ,
L_49 ,
V_64 -> V_194 . V_14 . V_207 , V_64 -> V_194 . V_14 . V_208 , V_64 -> V_194 . V_14 . V_209 ) ;
else
F_134 ( 1 , L_50 ,
V_64 -> V_194 . V_14 . V_207 , V_64 -> V_194 . V_14 . V_208 , V_64 -> V_194 . V_14 . V_209 ) ;
V_195 = ( ( ( T_3 ) V_194 . V_14 . V_207 << 16 ) |
( ( T_3 ) V_194 . V_14 . V_208 << 8 ) |
( ( T_3 ) V_194 . V_14 . V_209 ) ) ;
if ( F_115 ( & V_31 -> V_159 , V_195 ) ) {
F_134 ( 1 , L_51 ,
V_194 . V_14 . V_207 , V_194 . V_14 . V_208 , V_194 . V_14 . V_209 ) ;
F_118 ( & V_31 -> V_159 , V_195 , V_152 ) ;
} else {
F_76 ( & V_31 -> V_159 , V_195 , V_152 , V_124 ) ;
}
V_64 -> V_194 = V_194 ;
V_99 -> V_158 = V_195 ;
}
V_64 -> V_221 = V_221 ;
V_64 -> V_223 = 1 ;
V_64 -> V_224 = 0 ;
}
static int F_135 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_136 ( & V_31 -> V_159 ) ;
if ( V_25 ) {
F_52 ( L_52 ) ;
return V_25 ;
}
V_31 -> V_204 = F_137 ( sizeof( struct V_202 ) *
65536 ) ;
if ( ! V_31 -> V_204 ) {
F_52 ( L_53 ,
sizeof( struct V_202 ) * 65536 ) ;
F_138 ( & V_31 -> V_159 ) ;
return - V_190 ;
}
memset ( V_31 -> V_204 , 0 , sizeof( struct V_202 )
* 65536 ) ;
F_2 ( L_54 ,
sizeof( struct V_202 ) * 65536 ) ;
return 0 ;
}
static int F_139 ( struct V_66 * V_53 ,
void * V_196 ,
T_2 V_225 , T_2 V_226 )
{
struct V_210 * V_211 = V_53 -> V_68 ;
struct V_30 * V_31 =
(struct V_30 * ) V_196 ;
V_211 -> V_69 . V_227 = & V_228 ;
V_53 -> V_176 . V_196 = V_196 ;
V_31 -> V_172 = V_53 ;
return 0 ;
}
static struct V_153 * F_140 (
struct V_229 * V_230 ,
struct V_184 * V_185 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_183 = - V_180 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_104 ( - V_20 ) ;
V_31 = F_105 ( sizeof( struct V_30 ) , V_189 ) ;
if ( ! V_31 ) {
F_52 ( L_55 ) ;
return F_104 ( - V_190 ) ;
}
V_31 -> V_231 = V_22 ;
F_3 ( & V_31 -> V_232 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_56 , ( unsigned long long ) V_22 ) ;
V_183 = F_135 ( V_31 ) ;
if ( V_183 != 0 )
goto V_233;
V_183 = F_141 ( V_31 , V_22 , 0 , 0 ,
F_139 ) ;
if ( V_183 != 0 )
goto V_234;
return & V_31 -> V_155 ;
V_234:
F_142 ( V_31 -> V_204 ) ;
F_138 ( & V_31 -> V_159 ) ;
V_233:
F_107 ( V_31 ) ;
return F_104 ( V_183 ) ;
}
static void F_143 ( struct V_153 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_155 ) ;
struct V_66 * V_53 = V_31 -> V_172 ;
struct V_98 * V_157 ;
T_3 V_195 = 0 ;
if ( V_53 -> V_176 . V_177 && ! V_53 -> V_176 . V_177 -> V_235 )
F_144 ( V_53 -> V_176 . V_177 ) ;
F_145 ( V_53 ) ;
F_142 ( V_31 -> V_204 ) ;
F_146 (&lport->lport_fcport_map, key, node)
F_75 ( & V_31 -> V_159 , V_195 ) ;
F_138 ( & V_31 -> V_159 ) ;
F_107 ( V_31 ) ;
}
static int F_147 ( struct V_66 * V_171 ,
void * V_196 ,
T_2 V_225 , T_2 V_226 )
{
struct V_236 * V_237 ;
struct V_238 * V_239 = V_171 -> V_240 ;
struct V_66 * V_241 ;
struct V_30 * V_31 =
(struct V_30 * ) V_196 ;
struct V_30 * V_242 =
(struct V_30 * ) V_171 -> V_176 . V_196 ;
struct V_243 V_244 ;
if ( ! F_148 ( V_171 ) ) {
F_52 ( L_57 ) ;
return - V_181 ;
}
if ( ! V_242 || ! V_242 -> V_192 ||
! F_86 ( & V_242 -> V_192 -> V_168 ) ) {
F_52 ( L_58 ) ;
return - V_181 ;
}
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
V_244 . V_216 = V_225 ;
V_244 . V_245 = V_226 ;
V_244 . V_246 = V_247 ;
V_244 . V_248 = V_249 ;
V_244 . V_250 = false ;
V_237 = F_149 ( V_239 , 0 , & V_244 ) ;
if ( ! V_237 ) {
F_52 ( L_59 ) ;
return - V_180 ;
}
V_241 = (struct V_66 * ) V_237 -> V_251 ;
V_241 -> V_176 . V_196 = V_196 ;
V_31 -> V_172 = V_241 ;
F_150 ( V_241 -> V_240 ) ;
return 0 ;
}
static struct V_153 * F_151 (
struct V_229 * V_230 ,
struct V_184 * V_185 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_252 , V_225 , V_226 ;
char * V_213 , V_253 [ 128 ] ;
int V_183 ;
snprintf ( V_253 , 128 , L_60 , V_1 ) ;
V_213 = strchr ( V_253 , '@' ) ;
if ( ! V_213 ) {
F_52 ( L_61 ) ;
return F_104 ( - V_20 ) ;
}
* V_213 ++ = '\0' ;
if ( F_1 ( V_253 , & V_252 , 1 ) < 0 )
return F_104 ( - V_20 ) ;
if ( F_9 ( V_213 , strlen ( V_213 ) + 1 ,
& V_225 , & V_226 ) < 0 )
return F_104 ( - V_20 ) ;
V_31 = F_105 ( sizeof( struct V_30 ) , V_189 ) ;
if ( ! V_31 ) {
F_52 ( L_62 ) ;
return F_104 ( - V_190 ) ;
}
V_31 -> V_254 = V_225 ;
V_31 -> V_255 = V_226 ;
sprintf ( V_31 -> V_32 , L_56 , ( unsigned long long ) V_225 ) ;
V_183 = F_135 ( V_31 ) ;
if ( V_183 != 0 )
goto V_233;
V_183 = F_141 ( V_31 , V_252 , V_225 , V_226 ,
F_147 ) ;
if ( V_183 != 0 )
goto V_234;
return & V_31 -> V_155 ;
V_234:
F_142 ( V_31 -> V_204 ) ;
F_138 ( & V_31 -> V_159 ) ;
V_233:
F_107 ( V_31 ) ;
return F_104 ( V_183 ) ;
}
static void F_152 ( struct V_153 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_155 ) ;
struct V_66 * V_241 = V_31 -> V_172 ;
struct V_210 * V_211 = V_241 -> V_68 ;
T_7 * V_171 = F_122 ( V_211 -> V_212 ) ;
F_153 ( V_241 -> V_240 ) ;
F_154 ( V_241 -> V_236 ) ;
F_153 ( V_171 -> V_240 ) ;
F_107 ( V_31 ) ;
}
static T_1 F_155 ( struct V_164 * V_165 ,
char * V_166 )
{
return sprintf ( V_166 ,
L_63
V_256 L_64 , V_257 , F_156 () -> V_258 ,
F_156 () -> V_259 ) ;
}
static int F_157 ( void )
{
int V_183 ;
F_2 ( L_65
V_256 L_64 , V_257 , F_156 () -> V_258 ,
F_156 () -> V_259 ) ;
V_183 = F_158 ( & V_260 ) ;
if ( V_183 )
return V_183 ;
V_183 = F_158 ( & V_261 ) ;
if ( V_183 )
goto V_262;
V_47 = F_159 ( L_66 ,
V_263 , 0 ) ;
if ( ! V_47 ) {
V_183 = - V_190 ;
goto V_264;
}
V_265 = F_159 ( L_67 , 0 , 0 ) ;
if ( ! V_265 ) {
V_183 = - V_190 ;
goto V_266;
}
return 0 ;
V_266:
F_160 ( V_47 ) ;
V_264:
F_161 ( & V_261 ) ;
V_262:
F_161 ( & V_260 ) ;
return V_183 ;
}
static void F_162 ( void )
{
F_160 ( V_265 ) ;
F_160 ( V_47 ) ;
F_161 ( & V_260 ) ;
F_161 ( & V_261 ) ;
}
static int T_12 F_163 ( void )
{
int V_183 ;
V_183 = F_157 () ;
if ( V_183 < 0 )
return V_183 ;
return 0 ;
}
static void T_13 F_164 ( void )
{
F_162 () ;
}
