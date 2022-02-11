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
static void F_37 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
struct V_66 * V_53 ;
unsigned long V_67 ;
F_29 ( ! V_64 ) ;
V_53 = V_64 -> V_53 ;
F_38 ( & V_53 -> V_68 -> V_69 . V_70 , V_67 ) ;
F_39 ( V_62 ) ;
F_40 ( V_64 ) ;
F_41 ( & V_53 -> V_68 -> V_69 . V_70 , V_67 ) ;
}
static T_3 F_42 ( struct V_61 * V_62 )
{
return 0 ;
}
static int F_43 ( struct V_46 * V_46 )
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
V_49 -> V_80 = F_44 ( V_46 ) ;
V_49 -> V_81 = V_46 -> V_82 ;
V_49 -> V_83 = V_46 -> V_84 ;
V_49 -> V_85 = V_46 -> V_86 ;
V_49 -> V_87 = V_46 -> V_88 ;
V_49 -> V_89 = V_46 -> V_90 -> V_91 . V_92 ;
V_46 -> V_93 = 0 ;
return F_45 ( V_49 ) ;
}
static int F_46 ( struct V_46 * V_46 )
{
unsigned long V_67 ;
F_38 ( & V_46 -> V_94 , V_67 ) ;
if ( V_46 -> V_76 == V_95 ||
V_46 -> V_76 == V_96 ) {
F_41 ( & V_46 -> V_94 , V_67 ) ;
F_47 ( & V_46 -> V_97 ,
50 ) ;
return 0 ;
}
F_41 ( & V_46 -> V_94 , V_67 ) ;
return 0 ;
}
static void F_48 ( struct V_98 * V_99 )
{
return;
}
static int F_49 ( struct V_46 * V_46 )
{
if ( ! ( V_46 -> V_58 & V_59 ) ) {
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
return V_49 -> V_100 ;
}
return 0 ;
}
static int F_50 ( T_7 * V_53 , struct V_48 * V_49 ,
unsigned char * V_101 , T_8 V_79 , int V_102 ,
int V_103 , int V_104 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
#ifdef F_51
struct V_26 * V_27 ;
struct V_28 * V_29 ;
#endif
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
#ifdef F_51
V_27 = V_62 -> V_27 ;
V_29 = F_12 ( V_27 , struct V_28 , V_27 ) ;
if ( F_53 ( V_29 -> V_34 . V_110 ) ) {
return 0 ;
}
#endif
V_49 -> V_53 -> V_54 . V_111 ++ ;
return F_54 ( V_46 , V_62 , V_101 , & V_49 -> V_112 [ 0 ] ,
V_49 -> V_113 , V_79 , V_102 ,
V_103 , V_67 ) ;
}
static void F_55 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
unsigned long V_67 ;
V_49 -> V_50 = 0 ;
F_38 ( & V_49 -> V_114 , V_67 ) ;
V_49 -> V_51 |= V_115 ;
if ( V_49 -> V_71 ) {
V_49 -> V_51 |= V_116 ;
F_41 ( & V_49 -> V_114 , V_67 ) ;
F_28 ( V_49 ) ;
return;
}
F_41 ( & V_49 -> V_114 , V_67 ) ;
V_49 -> V_53 -> V_54 . V_117 ++ ;
if ( ! V_49 -> V_118 ) {
if ( V_49 -> V_46 . V_75 & V_119 ) {
F_56 ( & V_49 -> V_46 . V_97 ) ;
return;
}
if ( V_49 -> V_46 . V_93 )
F_57 ( & V_49 -> V_46 ,
V_49 -> V_46 . V_93 ) ;
else
F_57 ( & V_49 -> V_46 ,
V_120 ) ;
return;
}
return F_58 ( & V_49 -> V_46 ) ;
}
static void F_59 ( struct V_48 * V_49 )
{
V_49 -> V_51 |= V_121 ;
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_55 ) ;
F_30 ( F_31 () , V_47 , & V_49 -> V_42 ) ;
}
static void F_60 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
F_61 ( & V_49 -> V_46 . V_72 ) ;
F_57 ( & V_49 -> V_46 , V_49 -> V_46 . V_93 ) ;
}
static void F_62 ( struct V_48 * V_49 )
{
F_24 ( & V_49 -> V_42 , F_60 ) ;
F_25 ( V_47 , & V_49 -> V_42 ) ;
}
static int F_63 ( struct V_43 * V_44 , T_8 V_122 ,
T_9 V_123 , T_8 V_124 )
{
struct V_63 * V_64 = V_44 -> V_64 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
return F_64 ( V_46 , V_64 -> V_62 , NULL , V_122 , V_44 ,
V_123 , V_125 , V_124 , V_105 ) ;
}
static int F_65 ( struct V_46 * V_46 )
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
V_49 -> V_51 |= V_126 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_80 = F_44 ( V_46 ) ;
V_49 -> V_81 = V_46 -> V_82 ;
V_49 -> V_83 = V_46 -> V_84 ;
V_49 -> V_127 = 0 ;
V_49 -> V_85 = V_46 -> V_86 ;
V_49 -> V_87 = V_46 -> V_88 ;
V_49 -> V_89 = V_46 -> V_90 -> V_91 . V_92 ;
V_46 -> V_93 = 0 ;
return F_66 ( V_49 , V_128 | V_129 ,
V_46 -> V_130 ) ;
}
static int F_67 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
int V_131 = V_129 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_83 = NULL ;
V_49 -> V_81 = 0 ;
V_49 -> V_127 = 0 ;
V_49 -> V_80 = F_44 ( V_46 ) ;
if ( V_49 -> V_51 & V_132 ) {
F_68 ( L_10 , V_49 ) ;
F_69 () ;
}
V_49 -> V_51 |= V_132 ;
if ( V_46 -> V_133 == V_134 ) {
if ( V_46 -> V_58 & V_135 ) {
V_46 -> V_58 &= ~ V_135 ;
V_46 -> V_136 = 0 ;
}
V_46 -> V_58 |= V_137 ;
V_46 -> V_136 += V_46 -> V_79 ;
V_49 -> V_78 = 0 ;
}
return F_66 ( V_49 , V_131 , V_46 -> V_130 ) ;
}
static void F_70 ( struct V_46 * V_46 )
{
struct V_138 * V_139 = V_46 -> V_138 ;
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_2 ( L_11 ,
V_44 , V_139 -> V_140 , V_139 -> V_141 ) ;
switch ( V_139 -> V_141 ) {
case V_142 :
V_44 -> V_143 = V_144 ;
break;
case V_145 :
V_44 -> V_143 = V_146 ;
break;
case V_147 :
V_44 -> V_143 = V_148 ;
break;
case V_149 :
default:
V_44 -> V_143 = V_150 ;
break;
}
F_71 ( V_44 ) ;
}
static void F_72 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
unsigned long V_67 ;
if ( F_73 ( V_49 ) )
return;
F_38 ( & V_49 -> V_114 , V_67 ) ;
if ( ( V_49 -> V_100 == V_151 ) ||
( ( V_49 -> V_100 == V_152 ) &&
F_74 ( V_49 -> V_51 ) ) ) {
V_49 -> V_51 |= V_116 ;
F_41 ( & V_49 -> V_114 , V_67 ) ;
F_28 ( V_49 ) ;
return;
}
F_41 ( & V_49 -> V_114 , V_67 ) ;
return;
}
static void F_75 ( struct V_63 * V_64 )
{
struct V_98 * V_153 = V_64 -> V_62 -> V_98 ;
struct V_26 * V_27 = V_153 -> V_27 ;
struct V_154 * V_154 = V_27 -> V_155 ;
struct V_30 * V_31 = F_12 ( V_154 ,
struct V_30 , V_156 ) ;
struct V_157 * V_99 = F_12 ( V_153 ,
struct V_157 , V_98 ) ;
void * V_158 ;
F_2 ( L_12 , V_99 -> V_159 ) ;
V_158 = F_76 ( & V_31 -> V_160 , V_99 -> V_159 ) ;
if ( F_27 ( V_158 && ( V_158 != V_153 ) ) ) {
F_77 ( & V_31 -> V_160 , V_99 -> V_159 ,
V_158 , V_125 ) ;
}
F_2 ( L_13 ,
V_153 , V_99 -> V_161 , V_99 -> V_159 ) ;
F_78 ( V_31 , V_99 , V_64 ) ;
}
static void F_79 ( struct V_63 * V_64 )
{
F_80 ( & V_64 -> V_53 -> V_68 -> V_69 . V_70 ) ;
F_39 ( V_64 -> V_62 ) ;
}
static int F_81 ( struct V_98 * V_153 ,
const char * V_1 )
{
struct V_157 * V_99 =
F_12 ( V_153 , struct V_157 , V_98 ) ;
T_2 V_23 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return - V_20 ;
V_99 -> V_161 = V_23 ;
F_3 ( & V_99 -> V_162 [ 0 ] , V_10 , V_23 ) ;
return 0 ;
}
static T_1 F_82 ( struct V_163 * V_164 ,
char * V_165 )
{
struct V_26 * V_27 = F_83 ( V_164 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_165 , V_166 , L_14 ,
F_84 ( & V_29 -> V_167 ) ) ;
}
static void F_85 ( struct V_41 * V_42 )
{
struct V_28 * V_168 = F_12 ( V_42 ,
struct V_28 , V_169 ) ;
struct V_26 * V_27 = & V_168 -> V_27 ;
struct V_66 * V_170 = V_168 -> V_31 -> V_171 ;
if ( ! F_86 ( & V_27 -> V_172 . V_173 ) ) {
F_87 ( & V_168 -> V_167 , 1 ) ;
F_88 ( V_170 ) ;
}
F_56 ( & V_168 -> V_174 ) ;
}
static void F_89 ( struct V_41 * V_42 )
{
struct V_28 * V_168 = F_12 ( V_42 ,
struct V_28 , V_169 ) ;
struct V_26 * V_27 = & V_168 -> V_27 ;
struct V_66 * V_170 = V_168 -> V_31 -> V_171 ;
if ( ! F_90 ( V_170 -> V_175 . V_176 ) ) {
F_87 ( & V_168 -> V_167 , 0 ) ;
F_91 ( & V_27 -> V_172 . V_173 ) ;
}
F_56 ( & V_168 -> V_174 ) ;
}
static T_1 F_92 ( struct V_163 * V_164 ,
const char * V_165 , T_4 V_21 )
{
struct V_26 * V_27 = F_83 ( V_164 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_177 ;
int V_25 ;
V_25 = F_93 ( V_165 , 0 , & V_177 ) ;
if ( V_25 < 0 ) {
F_52 ( L_15 , V_25 ) ;
return - V_20 ;
}
if ( ( V_177 != 1 ) && ( V_177 != 0 ) ) {
F_52 ( L_16 , V_177 ) ;
return - V_20 ;
}
if ( V_177 ) {
if ( F_84 ( & V_29 -> V_167 ) )
return - V_178 ;
F_24 ( & V_29 -> V_169 , F_85 ) ;
} else {
if ( ! F_84 ( & V_29 -> V_167 ) )
return V_21 ;
F_24 ( & V_29 -> V_169 , F_89 ) ;
}
F_94 ( & V_29 -> V_174 ) ;
F_95 ( & V_29 -> V_169 ) ;
F_96 ( & V_29 -> V_174 ) ;
if ( V_177 ) {
if ( ! F_84 ( & V_29 -> V_167 ) )
return - V_179 ;
} else {
if ( F_84 ( & V_29 -> V_167 ) )
return - V_180 ;
}
return V_21 ;
}
static T_1 F_97 ( struct V_163 * V_164 ,
char * V_165 )
{
return F_98 ( F_83 ( V_164 ) , V_165 ) ;
}
static T_1 F_99 ( struct V_163 * V_164 ,
const char * V_165 , T_4 V_21 )
{
struct V_26 * V_27 = F_83 ( V_164 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_181 ;
int V_182 = F_93 ( V_165 , 0 , & V_181 ) ;
if ( V_182 ) {
F_52 ( L_17 , V_182 ) ;
return V_182 ;
}
if ( V_181 != 0 && V_181 != 1 && V_181 != 3 ) {
F_52 ( L_18 , V_181 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_181 ;
return V_21 ;
}
static T_1 F_100 ( struct V_163 * V_164 ,
char * V_165 )
{
struct V_26 * V_27 = F_83 ( V_164 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_165 , L_14 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_101 (
struct V_154 * V_2 ,
struct V_183 * V_184 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_156 ) ;
struct V_28 * V_29 ;
unsigned long V_185 ;
int V_182 ;
if ( strstr ( V_1 , L_19 ) != V_1 )
return F_102 ( - V_20 ) ;
if ( F_93 ( V_1 + 5 , 10 , & V_185 ) || V_185 > V_186 )
return F_102 ( - V_20 ) ;
if ( ( V_185 != 1 ) ) {
F_52 ( L_20 ) ;
return F_102 ( - V_187 ) ;
}
V_29 = F_103 ( sizeof( struct V_28 ) , V_188 ) ;
if ( ! V_29 ) {
F_52 ( L_21 ) ;
return F_102 ( - V_189 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_185 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_29 -> V_34 . V_110 = 0 ;
V_182 = F_104 ( V_2 , & V_29 -> V_27 , V_190 ) ;
if ( V_182 < 0 ) {
F_105 ( V_29 ) ;
return NULL ;
}
V_31 -> V_191 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_106 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_66 * V_53 = V_31 -> V_171 ;
if ( V_53 -> V_175 . V_176 && ! V_53 -> V_175 . V_176 -> V_192 )
F_90 ( V_53 -> V_175 . V_176 ) ;
F_107 ( V_27 ) ;
V_31 -> V_191 = NULL ;
F_105 ( V_29 ) ;
}
static T_1 F_108 ( struct V_163 * V_164 ,
char * V_165 )
{
return F_82 ( V_164 , V_165 ) ;
}
static T_1 F_109 ( struct V_163 * V_164 ,
const char * V_165 , T_4 V_21 )
{
struct V_26 * V_27 = F_83 ( V_164 ) ;
struct V_154 * V_154 = V_27 -> V_155 ;
struct V_30 * V_31 = F_12 ( V_154 ,
struct V_30 , V_156 ) ;
struct V_66 * V_53 = V_31 -> V_171 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_177 ;
int V_25 ;
V_25 = F_93 ( V_165 , 0 , & V_177 ) ;
if ( V_25 < 0 ) {
F_52 ( L_15 , V_25 ) ;
return - V_20 ;
}
if ( ( V_177 != 1 ) && ( V_177 != 0 ) ) {
F_52 ( L_16 , V_177 ) ;
return - V_20 ;
}
if ( V_177 ) {
if ( F_84 ( & V_29 -> V_167 ) )
return - V_178 ;
F_87 ( & V_29 -> V_167 , 1 ) ;
F_88 ( V_53 ) ;
} else {
if ( ! F_84 ( & V_29 -> V_167 ) )
return V_21 ;
F_87 ( & V_29 -> V_167 , 0 ) ;
F_90 ( V_53 -> V_175 . V_176 ) ;
}
return V_21 ;
}
static struct V_26 * F_110 (
struct V_154 * V_2 ,
struct V_183 * V_184 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_156 ) ;
struct V_28 * V_29 ;
unsigned long V_185 ;
int V_182 ;
if ( strstr ( V_1 , L_19 ) != V_1 )
return F_102 ( - V_20 ) ;
if ( F_93 ( V_1 + 5 , 10 , & V_185 ) || V_185 > V_186 )
return F_102 ( - V_20 ) ;
V_29 = F_103 ( sizeof( struct V_28 ) , V_188 ) ;
if ( ! V_29 ) {
F_52 ( L_21 ) ;
return F_102 ( - V_189 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_185 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_182 = F_104 ( V_2 , & V_29 -> V_27 , V_190 ) ;
if ( V_182 < 0 ) {
F_105 ( V_29 ) ;
return NULL ;
}
V_31 -> V_191 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_63 * F_111 (
T_7 * V_53 ,
const T_9 * V_193 )
{
struct V_30 * V_31 ;
struct V_98 * V_153 ;
struct V_157 * V_99 ;
T_3 V_194 ;
V_31 = V_53 -> V_175 . V_195 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_69 () ;
return NULL ;
}
V_194 = F_112 ( V_193 ) ;
F_2 ( L_23 , V_194 ) ;
V_153 = F_113 ( & V_31 -> V_160 , V_194 ) ;
if ( ! V_153 ) {
F_2 ( L_24 , V_194 ) ;
return NULL ;
}
F_2 ( L_25 ,
V_153 , V_153 -> V_196 ) ;
V_99 = F_12 ( V_153 , struct V_157 , V_98 ) ;
if ( ! V_99 -> V_63 ) {
F_52 ( L_26 ) ;
return NULL ;
}
return V_99 -> V_63 ;
}
static void F_114 (
struct V_30 * V_31 ,
struct V_98 * V_197 ,
struct V_157 * V_99 ,
struct V_61 * V_62 ,
struct V_63 * V_63 ,
T_9 * V_193 )
{
T_3 V_194 ;
void * V_198 ;
int V_25 ;
V_194 = F_112 ( V_193 ) ;
F_2 ( L_27 , V_194 ) ;
V_198 = F_113 ( & V_31 -> V_160 , V_194 ) ;
if ( ! V_198 ) {
if ( V_197 ) {
F_2 ( L_28 ) ;
V_99 -> V_159 = V_194 ;
V_25 = F_77 ( & V_31 -> V_160 , V_194 ,
V_197 , V_125 ) ;
if ( V_25 )
F_115 ( V_199 L_29 ,
( int ) V_194 ) ;
} else {
F_2 ( L_30 ) ;
}
V_63 -> V_62 = V_62 ;
V_99 -> V_63 = V_63 ;
return;
}
if ( V_99 -> V_63 ) {
if ( V_197 == NULL ) {
F_2 ( L_31 ) ;
F_76 ( & V_31 -> V_160 , V_194 ) ;
V_99 -> V_63 = NULL ;
return;
}
F_2 ( L_32 ) ;
F_116 ( & V_31 -> V_160 , V_194 , V_197 ) ;
V_63 -> V_62 = V_62 ;
V_99 -> V_63 = V_63 ;
return;
}
if ( V_197 == NULL ) {
F_2 ( L_33 ) ;
F_76 ( & V_31 -> V_160 , V_194 ) ;
return;
}
F_2 ( L_34 ) ;
F_116 ( & V_31 -> V_160 , V_194 , V_197 ) ;
V_63 -> V_62 = V_62 ;
V_99 -> V_63 = V_63 ;
F_2 ( L_35 ,
V_99 -> V_63 , V_197 , V_197 -> V_196 ) ;
}
static struct V_63 * F_117 (
T_7 * V_53 ,
const T_10 V_200 )
{
struct V_30 * V_31 ;
struct V_98 * V_153 ;
struct V_157 * V_99 ;
struct V_201 * V_202 ;
V_31 = V_53 -> V_175 . V_195 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_69 () ;
return NULL ;
}
F_2 ( L_36 , V_200 ) ;
V_202 = V_31 -> V_203 + V_200 ;
V_153 = V_202 -> V_153 ;
if ( ! V_153 ) {
F_2 ( L_37 ,
V_200 ) ;
return NULL ;
}
V_99 = F_12 ( V_153 , struct V_157 , V_98 ) ;
if ( ! V_99 -> V_63 ) {
F_52 ( L_26 ) ;
return NULL ;
}
return V_99 -> V_63 ;
}
static void F_118 (
struct V_30 * V_31 ,
struct V_98 * V_197 ,
struct V_157 * V_99 ,
struct V_61 * V_62 ,
struct V_63 * V_63 ,
T_10 V_200 )
{
struct V_98 * V_204 ;
struct V_201 * V_202 ;
F_2 ( L_38 , V_200 ) ;
V_202 = & ( (struct V_201 * )
V_31 -> V_203 ) [ V_200 ] ;
V_204 = V_202 -> V_153 ;
if ( ! V_204 ) {
F_2 ( L_39 ) ;
V_202 -> V_153 = V_197 ;
if ( V_63 -> V_62 != V_62 )
V_63 -> V_62 = V_62 ;
if ( V_99 -> V_63 != V_63 )
V_99 -> V_63 = V_63 ;
return;
}
if ( V_99 -> V_63 ) {
if ( V_197 == NULL ) {
F_2 ( L_40 ) ;
V_202 -> V_153 = NULL ;
V_99 -> V_63 = NULL ;
return;
}
F_2 ( L_41 ) ;
V_202 -> V_153 = V_197 ;
if ( V_63 -> V_62 != V_62 )
V_63 -> V_62 = V_62 ;
if ( V_99 -> V_63 != V_63 )
V_99 -> V_63 = V_63 ;
return;
}
if ( V_197 == NULL ) {
F_2 ( L_42 ) ;
V_202 -> V_153 = NULL ;
return;
}
F_2 ( L_43 ) ;
V_202 -> V_153 = V_197 ;
if ( V_63 -> V_62 != V_62 )
V_63 -> V_62 = V_62 ;
if ( V_99 -> V_63 != V_63 )
V_99 -> V_63 = V_63 ;
F_2 ( L_44 ,
V_99 -> V_63 , V_197 , V_197 -> V_196 ) ;
}
static void F_78 ( struct V_30 * V_31 ,
struct V_157 * V_99 , struct V_63 * V_64 )
{
struct V_61 * V_62 = V_64 -> V_62 ;
unsigned char V_205 [ 3 ] ;
V_205 [ 0 ] = V_64 -> V_193 . V_14 . V_206 ;
V_205 [ 1 ] = V_64 -> V_193 . V_14 . V_207 ;
V_205 [ 2 ] = V_64 -> V_193 . V_14 . V_208 ;
F_114 ( V_31 , NULL , V_99 , V_62 ,
V_64 , V_205 ) ;
F_118 ( V_31 , NULL , V_99 , V_62 ,
V_64 , V_64 -> V_200 ) ;
}
static void F_119 ( struct V_63 * V_64 )
{
struct V_176 * V_69 = V_64 -> V_69 ;
struct V_209 * V_210 = V_69 -> V_210 ;
T_7 * V_53 = F_120 ( V_210 -> V_211 ) ;
struct V_61 * V_62 ;
struct V_30 * V_31 ;
F_29 ( F_121 () ) ;
V_62 = V_64 -> V_62 ;
if ( ! V_62 ) {
F_52 ( L_45 ) ;
F_69 () ;
return;
}
V_31 = V_53 -> V_175 . V_195 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_69 () ;
return;
}
F_122 ( V_62 ) ;
F_123 ( V_64 -> V_62 ) ;
F_124 ( V_64 -> V_62 ) ;
}
static int F_125 ( struct V_26 * V_27 ,
struct V_61 * V_62 , void * V_212 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_209 * V_210 = V_31 -> V_171 -> V_68 ;
struct V_98 * V_153 = V_62 -> V_98 ;
struct V_157 * V_99 = F_12 ( V_153 ,
struct V_157 , V_98 ) ;
struct V_63 * V_213 = V_212 ;
T_10 V_200 = V_213 -> V_200 ;
unsigned long V_67 ;
unsigned char V_205 [ 3 ] ;
V_205 [ 0 ] = V_213 -> V_193 . V_14 . V_206 ;
V_205 [ 1 ] = V_213 -> V_193 . V_14 . V_207 ;
V_205 [ 2 ] = V_213 -> V_193 . V_14 . V_208 ;
F_38 ( & V_210 -> V_69 . V_70 , V_67 ) ;
F_114 ( V_31 , V_153 , V_99 ,
V_62 , V_213 , V_205 ) ;
F_118 ( V_31 , V_153 , V_99 ,
V_62 , V_213 , V_200 ) ;
F_41 ( & V_210 -> V_69 . V_70 , V_67 ) ;
return 0 ;
}
static int F_126 (
T_7 * V_53 ,
unsigned char * V_214 ,
struct V_63 * V_213 )
{
struct V_209 * V_210 = V_53 -> V_68 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_61 * V_62 ;
unsigned char V_215 [ 36 ] ;
int V_216 = ( V_210 -> V_217 ) ? V_210 -> V_217 :
V_218 ;
V_31 = V_53 -> V_175 . V_195 ;
if ( ! V_31 ) {
F_52 ( L_22 ) ;
F_69 () ;
return - V_20 ;
}
V_29 = V_31 -> V_191 ;
if ( ! V_29 ) {
F_52 ( L_46 ) ;
return - V_20 ;
}
memset ( & V_215 , 0 , 36 ) ;
snprintf ( V_215 , sizeof( V_215 ) , L_47 , V_214 ) ;
V_62 = F_127 ( & V_29 -> V_27 , V_216 ,
sizeof( struct V_48 ) ,
V_219 , V_215 ,
V_213 , F_125 ) ;
if ( F_128 ( V_62 ) )
return F_129 ( V_62 ) ;
return 0 ;
}
static void F_130 ( struct V_63 * V_64 , T_11 V_193 ,
T_10 V_200 , bool V_220 )
{
struct V_176 * V_69 = V_64 -> V_69 ;
struct V_209 * V_210 = V_69 -> V_210 ;
T_7 * V_53 = F_120 ( V_210 -> V_211 ) ;
struct V_30 * V_31 = V_53 -> V_175 . V_195 ;
struct V_98 * V_153 = V_64 -> V_62 -> V_98 ;
struct V_157 * V_99 = F_12 ( V_153 ,
struct V_157 , V_98 ) ;
T_3 V_194 ;
if ( V_64 -> V_200 != V_200 || V_64 -> V_193 . V_221 != V_193 . V_221 )
F_131 ( L_48 ,
V_64 , V_64 -> V_215 ,
V_64 -> V_200 , V_200 , V_64 -> V_193 . V_14 . V_206 ,
V_64 -> V_193 . V_14 . V_207 , V_64 -> V_193 . V_14 . V_208 , V_193 . V_14 . V_206 ,
V_193 . V_14 . V_207 , V_193 . V_14 . V_208 ) ;
if ( V_64 -> V_200 != V_200 ) {
if ( V_31 -> V_203 [ V_64 -> V_200 ] . V_153 == V_153 )
V_31 -> V_203 [ V_64 -> V_200 ] . V_153 = NULL ;
V_31 -> V_203 [ V_200 ] . V_153 = V_153 ;
V_64 -> V_200 = V_200 ;
}
if ( V_64 -> V_193 . V_221 != V_193 . V_221 ) {
V_194 = ( ( ( T_3 ) V_64 -> V_193 . V_14 . V_206 << 16 ) |
( ( T_3 ) V_64 -> V_193 . V_14 . V_207 << 8 ) |
( ( T_3 ) V_64 -> V_193 . V_14 . V_208 ) ) ;
if ( F_113 ( & V_31 -> V_160 , V_194 ) )
F_132 ( F_76 ( & V_31 -> V_160 , V_194 ) != V_153 ,
L_49 ,
V_64 -> V_193 . V_14 . V_206 , V_64 -> V_193 . V_14 . V_207 , V_64 -> V_193 . V_14 . V_208 ) ;
else
F_132 ( 1 , L_50 ,
V_64 -> V_193 . V_14 . V_206 , V_64 -> V_193 . V_14 . V_207 , V_64 -> V_193 . V_14 . V_208 ) ;
V_194 = ( ( ( T_3 ) V_193 . V_14 . V_206 << 16 ) |
( ( T_3 ) V_193 . V_14 . V_207 << 8 ) |
( ( T_3 ) V_193 . V_14 . V_208 ) ) ;
if ( F_113 ( & V_31 -> V_160 , V_194 ) ) {
F_132 ( 1 , L_51 ,
V_193 . V_14 . V_206 , V_193 . V_14 . V_207 , V_193 . V_14 . V_208 ) ;
F_116 ( & V_31 -> V_160 , V_194 , V_153 ) ;
} else {
F_77 ( & V_31 -> V_160 , V_194 , V_153 , V_125 ) ;
}
V_64 -> V_193 = V_193 ;
V_99 -> V_159 = V_194 ;
}
V_64 -> V_220 = V_220 ;
V_64 -> V_222 = 1 ;
V_64 -> V_223 = 0 ;
}
static int F_133 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_134 ( & V_31 -> V_160 ) ;
if ( V_25 ) {
F_52 ( L_52 ) ;
return V_25 ;
}
V_31 -> V_203 = F_135 ( sizeof( struct V_201 ) *
65536 ) ;
if ( ! V_31 -> V_203 ) {
F_52 ( L_53 ,
sizeof( struct V_201 ) * 65536 ) ;
F_136 ( & V_31 -> V_160 ) ;
return - V_189 ;
}
memset ( V_31 -> V_203 , 0 , sizeof( struct V_201 )
* 65536 ) ;
F_2 ( L_54 ,
sizeof( struct V_201 ) * 65536 ) ;
return 0 ;
}
static int F_137 ( struct V_66 * V_53 ,
void * V_195 ,
T_2 V_224 , T_2 V_225 )
{
struct V_209 * V_210 = V_53 -> V_68 ;
struct V_30 * V_31 =
(struct V_30 * ) V_195 ;
V_210 -> V_69 . V_226 = & V_227 ;
V_53 -> V_175 . V_195 = V_195 ;
V_31 -> V_171 = V_53 ;
return 0 ;
}
static struct V_154 * F_138 (
struct V_228 * V_229 ,
struct V_183 * V_184 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_182 = - V_179 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_102 ( - V_20 ) ;
V_31 = F_103 ( sizeof( struct V_30 ) , V_188 ) ;
if ( ! V_31 ) {
F_52 ( L_55 ) ;
return F_102 ( - V_189 ) ;
}
V_31 -> V_230 = V_22 ;
F_3 ( & V_31 -> V_231 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_56 , ( unsigned long long ) V_22 ) ;
V_182 = F_133 ( V_31 ) ;
if ( V_182 != 0 )
goto V_232;
V_182 = F_139 ( V_31 , V_22 , 0 , 0 ,
F_137 ) ;
if ( V_182 != 0 )
goto V_233;
return & V_31 -> V_156 ;
V_233:
F_140 ( V_31 -> V_203 ) ;
F_136 ( & V_31 -> V_160 ) ;
V_232:
F_105 ( V_31 ) ;
return F_102 ( V_182 ) ;
}
static void F_141 ( struct V_154 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_156 ) ;
struct V_66 * V_53 = V_31 -> V_171 ;
struct V_98 * V_158 ;
T_3 V_194 = 0 ;
if ( V_53 -> V_175 . V_176 && ! V_53 -> V_175 . V_176 -> V_234 )
F_142 ( V_53 -> V_175 . V_176 ) ;
F_143 ( V_53 ) ;
F_140 ( V_31 -> V_203 ) ;
F_144 (&lport->lport_fcport_map, key, node)
F_76 ( & V_31 -> V_160 , V_194 ) ;
F_136 ( & V_31 -> V_160 ) ;
F_105 ( V_31 ) ;
}
static int F_145 ( struct V_66 * V_170 ,
void * V_195 ,
T_2 V_224 , T_2 V_225 )
{
struct V_235 * V_236 ;
struct V_237 * V_238 = V_170 -> V_239 ;
struct V_66 * V_240 ;
struct V_30 * V_31 =
(struct V_30 * ) V_195 ;
struct V_30 * V_241 =
(struct V_30 * ) V_170 -> V_175 . V_195 ;
struct V_242 V_243 ;
if ( ! F_146 ( V_170 ) ) {
F_52 ( L_57 ) ;
return - V_180 ;
}
if ( ! V_241 || ! V_241 -> V_191 ||
! F_84 ( & V_241 -> V_191 -> V_167 ) ) {
F_52 ( L_58 ) ;
return - V_180 ;
}
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_215 = V_224 ;
V_243 . V_244 = V_225 ;
V_243 . V_245 = V_246 ;
V_243 . V_247 = V_248 ;
V_243 . V_249 = false ;
V_236 = F_147 ( V_238 , 0 , & V_243 ) ;
if ( ! V_236 ) {
F_52 ( L_59 ) ;
return - V_179 ;
}
V_240 = (struct V_66 * ) V_236 -> V_250 ;
V_240 -> V_175 . V_195 = V_195 ;
V_31 -> V_171 = V_240 ;
F_148 ( V_240 -> V_239 ) ;
return 0 ;
}
static struct V_154 * F_149 (
struct V_228 * V_229 ,
struct V_183 * V_184 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_251 , V_224 , V_225 ;
char * V_212 , V_252 [ 128 ] ;
int V_182 ;
snprintf ( V_252 , 128 , L_60 , V_1 ) ;
V_212 = strchr ( V_252 , '@' ) ;
if ( ! V_212 ) {
F_52 ( L_61 ) ;
return F_102 ( - V_20 ) ;
}
* V_212 ++ = '\0' ;
if ( F_1 ( V_252 , & V_251 , 1 ) < 0 )
return F_102 ( - V_20 ) ;
if ( F_9 ( V_212 , strlen ( V_212 ) + 1 ,
& V_224 , & V_225 ) < 0 )
return F_102 ( - V_20 ) ;
V_31 = F_103 ( sizeof( struct V_30 ) , V_188 ) ;
if ( ! V_31 ) {
F_52 ( L_62 ) ;
return F_102 ( - V_189 ) ;
}
V_31 -> V_253 = V_224 ;
V_31 -> V_254 = V_225 ;
sprintf ( V_31 -> V_32 , L_56 , ( unsigned long long ) V_224 ) ;
V_182 = F_133 ( V_31 ) ;
if ( V_182 != 0 )
goto V_232;
V_182 = F_139 ( V_31 , V_251 , V_224 , V_225 ,
F_145 ) ;
if ( V_182 != 0 )
goto V_233;
return & V_31 -> V_156 ;
V_233:
F_140 ( V_31 -> V_203 ) ;
F_136 ( & V_31 -> V_160 ) ;
V_232:
F_105 ( V_31 ) ;
return F_102 ( V_182 ) ;
}
static void F_150 ( struct V_154 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_156 ) ;
struct V_66 * V_240 = V_31 -> V_171 ;
struct V_209 * V_210 = V_240 -> V_68 ;
T_7 * V_170 = F_120 ( V_210 -> V_211 ) ;
F_151 ( V_240 -> V_239 ) ;
F_152 ( V_240 -> V_235 ) ;
F_151 ( V_170 -> V_239 ) ;
F_105 ( V_31 ) ;
}
static T_1 F_153 ( struct V_163 * V_164 ,
char * V_165 )
{
return sprintf ( V_165 ,
L_63
V_255 L_64 , V_256 , F_154 () -> V_257 ,
F_154 () -> V_258 ) ;
}
static int F_155 ( void )
{
int V_182 ;
F_2 ( L_65
V_255 L_64 , V_256 , F_154 () -> V_257 ,
F_154 () -> V_258 ) ;
V_182 = F_156 ( & V_259 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_156 ( & V_260 ) ;
if ( V_182 )
goto V_261;
V_47 = F_157 ( L_66 ,
V_262 , 0 ) ;
if ( ! V_47 ) {
V_182 = - V_189 ;
goto V_263;
}
V_264 = F_157 ( L_67 , 0 , 0 ) ;
if ( ! V_264 ) {
V_182 = - V_189 ;
goto V_265;
}
return 0 ;
V_265:
F_158 ( V_47 ) ;
V_263:
F_159 ( & V_260 ) ;
V_261:
F_159 ( & V_259 ) ;
return V_182 ;
}
static void F_160 ( void )
{
F_158 ( V_264 ) ;
F_158 ( V_47 ) ;
F_159 ( & V_259 ) ;
F_159 ( & V_260 ) ;
}
static int T_12 F_161 ( void )
{
int V_182 ;
V_182 = F_155 () ;
if ( V_182 < 0 )
return V_182 ;
return 0 ;
}
static void T_13 F_162 ( void )
{
F_160 () ;
}
