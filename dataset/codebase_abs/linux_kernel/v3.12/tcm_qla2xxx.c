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
return F_28 ( V_30 ) -> V_48 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_49 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_50 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_51 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return F_28 ( V_30 ) -> V_52 ;
}
static struct V_39 * F_33 (
struct V_1 * V_2 )
{
struct V_53 * V_54 ;
V_54 = F_34 ( sizeof( struct V_53 ) , V_55 ) ;
if ( ! V_54 ) {
F_35 ( L_6 ) ;
return NULL ;
}
return & V_54 -> V_39 ;
}
static void F_36 (
struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_53 * V_54 = F_15 ( V_40 ,
struct V_53 , V_39 ) ;
F_37 ( V_54 ) ;
}
static T_3 F_38 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return V_30 -> V_38 ;
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_15 ( V_57 ,
struct V_58 , V_60 ) ;
F_40 ( & V_59 -> V_61 , 0 ) ;
}
static void F_41 ( struct V_58 * V_59 )
{
F_42 ( & V_59 -> V_60 , F_39 ) ;
F_43 ( V_62 , & V_59 -> V_60 ) ;
}
static void F_44 ( struct V_56 * V_57 )
{
struct V_63 * V_64 = F_15 ( V_57 , struct V_63 , V_57 ) ;
F_40 ( & V_64 -> V_61 , 0 ) ;
}
static void F_45 ( struct V_63 * V_64 )
{
F_42 ( & V_64 -> V_57 , F_44 ) ;
F_43 ( V_62 , & V_64 -> V_57 ) ;
}
static int F_46 ( struct V_61 * V_61 )
{
return F_47 ( V_61 -> V_65 , V_61 ) ;
}
static void F_48 ( struct V_61 * V_61 )
{
struct V_63 * V_64 ;
if ( V_61 -> V_66 & V_67 ) {
struct V_58 * V_59 = F_15 ( V_61 ,
struct V_58 , V_61 ) ;
F_49 ( V_59 ) ;
return;
}
V_64 = F_15 ( V_61 , struct V_63 , V_61 ) ;
F_50 ( V_64 ) ;
}
static int F_51 ( struct V_68 * V_65 )
{
struct V_69 * V_70 = V_65 -> V_71 ;
struct V_72 * V_73 ;
unsigned long V_74 ;
F_52 ( ! V_70 ) ;
V_73 = V_70 -> V_73 ;
F_53 ( & V_73 -> V_75 -> V_76 , V_74 ) ;
F_54 ( V_65 ) ;
F_55 ( & V_73 -> V_75 -> V_76 , V_74 ) ;
return 1 ;
}
static void F_56 ( struct V_68 * V_65 )
{
struct V_69 * V_70 = V_65 -> V_71 ;
struct V_72 * V_73 ;
unsigned long V_74 ;
F_52 ( ! V_70 ) ;
V_73 = V_70 -> V_73 ;
F_53 ( & V_73 -> V_75 -> V_76 , V_74 ) ;
F_57 ( V_70 ) ;
F_55 ( & V_73 -> V_75 -> V_76 , V_74 ) ;
}
static T_3 F_58 ( struct V_68 * V_65 )
{
return 0 ;
}
static int F_59 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_15 ( V_61 ,
struct V_63 , V_61 ) ;
V_64 -> V_77 = V_61 -> V_78 ;
V_64 -> V_79 = F_60 ( V_61 ) ;
V_64 -> V_80 = V_61 -> V_81 ;
V_64 -> V_82 = V_61 -> V_83 ;
return F_61 ( V_64 ) ;
}
static int F_62 ( struct V_61 * V_61 )
{
unsigned long V_74 ;
F_53 ( & V_61 -> V_84 , V_74 ) ;
if ( V_61 -> V_85 == V_86 ||
V_61 -> V_85 == V_87 ) {
F_55 ( & V_61 -> V_84 , V_74 ) ;
F_63 ( & V_61 -> V_88 ,
3000 ) ;
return 0 ;
}
F_55 ( & V_61 -> V_84 , V_74 ) ;
return 0 ;
}
static void F_64 ( struct V_39 * V_54 )
{
return;
}
static T_3 F_65 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_15 ( V_61 ,
struct V_63 , V_61 ) ;
return V_64 -> V_89 ;
}
static int F_66 ( struct V_61 * V_61 )
{
return 0 ;
}
static int F_67 ( T_7 * V_73 , struct V_63 * V_64 ,
unsigned char * V_90 , T_8 V_78 , int V_91 ,
int V_92 , int V_93 )
{
struct V_61 * V_61 = & V_64 -> V_61 ;
struct V_68 * V_65 ;
struct V_69 * V_70 ;
int V_74 = V_94 ;
if ( V_93 )
V_74 |= V_95 ;
V_70 = V_64 -> V_70 ;
if ( ! V_70 ) {
F_35 ( L_7 ) ;
return - V_22 ;
}
V_65 = V_70 -> V_65 ;
if ( ! V_65 ) {
F_35 ( L_8 ) ;
return - V_22 ;
}
return F_68 ( V_61 , V_65 , V_90 , & V_64 -> V_96 [ 0 ] ,
V_64 -> V_97 , V_78 , V_91 ,
V_92 , V_74 ) ;
}
static void F_69 ( struct V_56 * V_57 )
{
struct V_63 * V_64 = F_15 ( V_57 , struct V_63 , V_57 ) ;
if ( ! V_64 -> V_98 ) {
if ( V_64 -> V_61 . V_99 & V_100 ) {
F_70 ( & V_64 -> V_61 . V_88 ) ;
return;
}
F_71 ( & V_64 -> V_61 ,
V_101 ) ;
return;
}
return F_72 ( & V_64 -> V_61 ) ;
}
static void F_73 ( struct V_63 * V_64 )
{
F_42 ( & V_64 -> V_57 , F_69 ) ;
F_43 ( V_62 , & V_64 -> V_57 ) ;
}
static int F_74 ( struct V_58 * V_59 , T_8 V_102 ,
T_9 V_103 , T_8 V_89 )
{
struct V_69 * V_70 = V_59 -> V_70 ;
struct V_61 * V_61 = & V_59 -> V_61 ;
return F_75 ( V_61 , V_70 -> V_65 , NULL , V_102 , V_59 ,
V_103 , V_104 , V_89 , V_94 ) ;
}
static int F_76 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_15 ( V_61 ,
struct V_63 , V_61 ) ;
V_64 -> V_77 = V_61 -> V_78 ;
V_64 -> V_79 = F_60 ( V_61 ) ;
V_64 -> V_105 = ( V_61 -> V_99 & V_100 ) ;
V_64 -> V_80 = V_61 -> V_81 ;
V_64 -> V_82 = V_61 -> V_83 ;
V_64 -> V_106 = 0 ;
return F_77 ( V_64 , V_107 | V_108 ,
V_61 -> V_109 ) ;
}
static int F_78 ( struct V_61 * V_61 )
{
struct V_63 * V_64 = F_15 ( V_61 ,
struct V_63 , V_61 ) ;
int V_110 = V_108 ;
V_64 -> V_77 = V_61 -> V_78 ;
V_64 -> V_82 = NULL ;
V_64 -> V_80 = 0 ;
V_64 -> V_106 = 0 ;
V_64 -> V_79 = F_60 ( V_61 ) ;
V_64 -> V_105 = ( V_61 -> V_99 & V_100 ) ;
if ( V_61 -> V_111 == V_112 ) {
if ( V_61 -> V_66 & V_113 ) {
V_61 -> V_66 &= ~ V_113 ;
V_61 -> V_114 = 0 ;
}
V_61 -> V_66 |= V_115 ;
V_61 -> V_114 += V_61 -> V_78 ;
V_64 -> V_77 = 0 ;
}
return F_77 ( V_64 , V_110 , V_61 -> V_109 ) ;
}
static void F_79 ( struct V_61 * V_61 )
{
struct V_116 * V_117 = V_61 -> V_116 ;
struct V_58 * V_59 = F_15 ( V_61 ,
struct V_58 , V_61 ) ;
F_4 ( L_9 ,
V_59 , V_117 -> V_118 , V_117 -> V_119 ) ;
switch ( V_117 -> V_119 ) {
case V_120 :
V_59 -> V_121 = V_122 ;
break;
case V_123 :
V_59 -> V_121 = V_124 ;
break;
case V_125 :
V_59 -> V_121 = V_126 ;
break;
case V_127 :
default:
V_59 -> V_121 = V_128 ;
break;
}
F_80 ( V_59 ) ;
}
static void F_81 ( struct V_69 * V_70 )
{
struct V_39 * V_40 = V_70 -> V_65 -> V_39 ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_129 * V_129 = V_2 -> V_130 ;
struct V_31 * V_32 = F_15 ( V_129 ,
struct V_31 , V_131 ) ;
struct V_53 * V_54 = F_15 ( V_40 ,
struct V_53 , V_39 ) ;
void * V_132 ;
F_4 ( L_10 , V_54 -> V_133 ) ;
V_132 = F_82 ( & V_32 -> V_134 , V_54 -> V_133 ) ;
F_83 ( V_132 && ( V_132 != V_40 ) ) ;
F_4 ( L_11 ,
V_40 , V_54 -> V_135 , V_54 -> V_133 ) ;
F_84 ( V_32 , V_54 , V_70 ) ;
}
static void F_85 ( struct V_136 * V_136 )
{
struct V_68 * V_65 = F_15 ( V_136 ,
struct V_68 , V_137 ) ;
F_57 ( V_65 -> V_71 ) ;
}
static void F_86 ( struct V_68 * V_65 )
{
struct V_69 * V_70 = V_65 -> V_71 ;
struct V_138 * V_139 = V_70 -> V_73 -> V_75 ;
unsigned long V_74 ;
F_53 ( & V_139 -> V_76 , V_74 ) ;
F_87 ( & V_65 -> V_137 , F_85 ) ;
F_55 ( & V_139 -> V_76 , V_74 ) ;
}
static void F_88 ( struct V_69 * V_70 )
{
F_89 ( & V_70 -> V_73 -> V_75 -> V_76 ) ;
F_87 ( & V_70 -> V_65 -> V_137 , F_85 ) ;
}
static void F_90 ( struct V_69 * V_70 )
{
F_89 ( & V_70 -> V_73 -> V_75 -> V_76 ) ;
F_54 ( V_70 -> V_65 ) ;
}
static struct V_39 * F_91 (
struct V_1 * V_2 ,
struct V_140 * V_141 ,
const char * V_3 )
{
struct V_39 * V_40 , * V_142 ;
struct V_53 * V_54 ;
T_2 V_25 ;
T_3 V_143 ;
if ( F_3 ( V_3 , & V_25 , 1 ) < 0 )
return F_92 ( - V_22 ) ;
V_142 = F_33 ( V_2 ) ;
if ( ! V_142 )
return F_92 ( - V_144 ) ;
V_143 = 1 ;
V_40 = F_93 ( V_2 , V_142 ,
V_3 , V_143 ) ;
if ( F_94 ( V_40 ) ) {
F_36 ( V_2 , V_142 ) ;
return V_40 ;
}
V_54 = F_15 ( V_40 , struct V_53 , V_39 ) ;
V_54 -> V_135 = V_25 ;
F_5 ( & V_54 -> V_145 [ 0 ] , V_12 , V_25 ) ;
return V_40 ;
}
static void F_95 ( struct V_39 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
struct V_53 * V_54 = F_15 ( V_146 ,
struct V_53 , V_39 ) ;
F_96 ( V_2 , V_146 , 1 ) ;
F_37 ( V_54 ) ;
}
static T_1 F_97 (
struct V_1 * V_2 ,
char * V_147 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
return snprintf ( V_147 , V_148 , L_12 ,
F_98 ( & V_30 -> V_149 ) ) ;
}
static T_1 F_99 (
struct V_1 * V_2 ,
const char * V_147 ,
T_4 V_23 )
{
struct V_129 * V_129 = V_2 -> V_130 ;
struct V_31 * V_32 = F_15 ( V_129 ,
struct V_31 , V_131 ) ;
struct V_72 * V_73 = V_32 -> V_150 ;
struct V_138 * V_139 = V_73 -> V_75 ;
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
unsigned long V_151 ;
int V_27 ;
V_27 = F_100 ( V_147 , 0 , & V_151 ) ;
if ( V_27 < 0 ) {
F_35 ( L_13 , V_27 ) ;
return - V_22 ;
}
if ( ( V_151 != 1 ) && ( V_151 != 0 ) ) {
F_35 ( L_14 , V_151 ) ;
return - V_22 ;
}
if ( V_151 ) {
F_101 ( & V_30 -> V_149 , 1 ) ;
F_102 ( V_73 ) ;
} else {
if ( ! V_139 -> V_152 . V_153 ) {
F_35 ( L_15 ) ;
return - V_154 ;
}
F_101 ( & V_30 -> V_149 , 0 ) ;
F_103 ( V_139 -> V_152 . V_153 ) ;
}
return V_23 ;
}
static struct V_1 * F_104 (
struct V_129 * V_4 ,
struct V_140 * V_141 ,
const char * V_3 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_131 ) ;
struct V_29 * V_30 ;
unsigned long V_155 ;
int V_44 ;
if ( strstr ( V_3 , L_16 ) != V_3 )
return F_92 ( - V_22 ) ;
if ( F_100 ( V_3 + 5 , 10 , & V_155 ) || V_155 > V_156 )
return F_92 ( - V_22 ) ;
if ( ! V_32 -> V_157 && ( V_155 != 1 ) ) {
F_35 ( L_17 ) ;
return F_92 ( - V_158 ) ;
}
V_30 = F_34 ( sizeof( struct V_29 ) , V_55 ) ;
if ( ! V_30 ) {
F_35 ( L_18 ) ;
return F_92 ( - V_144 ) ;
}
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_155 ;
F_28 ( V_30 ) -> V_48 = 1 ;
F_28 ( V_30 ) -> V_50 = 1 ;
F_28 ( V_30 ) -> V_49 = 1 ;
F_28 ( V_30 ) -> V_52 = 1 ;
V_44 = F_105 ( & V_159 -> V_160 , V_4 ,
& V_30 -> V_2 , V_30 , V_161 ) ;
if ( V_44 < 0 ) {
F_37 ( V_30 ) ;
return NULL ;
}
if ( V_32 -> V_157 == NULL )
V_32 -> V_162 = V_30 ;
return & V_30 -> V_2 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_15 ( V_2 ,
struct V_29 , V_2 ) ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_72 * V_73 = V_32 -> V_150 ;
struct V_138 * V_139 = V_73 -> V_75 ;
if ( V_139 -> V_152 . V_153 && ! V_139 -> V_152 . V_153 -> V_163 )
F_103 ( V_139 -> V_152 . V_153 ) ;
F_107 ( V_2 ) ;
if ( V_32 -> V_157 == NULL )
V_32 -> V_162 = NULL ;
F_37 ( V_30 ) ;
}
static struct V_1 * F_108 (
struct V_129 * V_4 ,
struct V_140 * V_141 ,
const char * V_3 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_131 ) ;
struct V_29 * V_30 ;
unsigned long V_155 ;
int V_44 ;
if ( strstr ( V_3 , L_16 ) != V_3 )
return F_92 ( - V_22 ) ;
if ( F_100 ( V_3 + 5 , 10 , & V_155 ) || V_155 > V_156 )
return F_92 ( - V_22 ) ;
V_30 = F_34 ( sizeof( struct V_29 ) , V_55 ) ;
if ( ! V_30 ) {
F_35 ( L_18 ) ;
return F_92 ( - V_144 ) ;
}
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_155 ;
V_44 = F_105 ( & V_164 -> V_160 , V_4 ,
& V_30 -> V_2 , V_30 , V_161 ) ;
if ( V_44 < 0 ) {
F_37 ( V_30 ) ;
return NULL ;
}
return & V_30 -> V_2 ;
}
static struct V_69 * F_109 (
T_7 * V_73 ,
const T_9 * V_165 )
{
struct V_138 * V_139 = V_73 -> V_75 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_53 * V_54 ;
T_3 V_166 ;
V_32 = V_139 -> V_152 . V_167 ;
if ( ! V_32 ) {
F_35 ( L_19 ) ;
F_110 () ;
return NULL ;
}
V_166 = ( ( ( unsigned long ) V_165 [ 0 ] << 16 ) |
( ( unsigned long ) V_165 [ 1 ] << 8 ) |
( unsigned long ) V_165 [ 2 ] ) ;
F_4 ( L_20 , V_166 ) ;
V_40 = F_111 ( & V_32 -> V_134 , V_166 ) ;
if ( ! V_40 ) {
F_4 ( L_21 , V_166 ) ;
return NULL ;
}
F_4 ( L_22 ,
V_40 , V_40 -> V_168 ) ;
V_54 = F_15 ( V_40 , struct V_53 , V_39 ) ;
if ( ! V_54 -> V_69 ) {
F_35 ( L_23 ) ;
return NULL ;
}
return V_54 -> V_69 ;
}
static void F_112 (
struct V_31 * V_32 ,
struct V_39 * V_169 ,
struct V_53 * V_54 ,
struct V_68 * V_65 ,
struct V_69 * V_69 ,
T_9 * V_165 )
{
T_3 V_166 ;
void * V_170 ;
int V_27 ;
V_166 = ( ( ( unsigned long ) V_165 [ 0 ] << 16 ) |
( ( unsigned long ) V_165 [ 1 ] << 8 ) |
( unsigned long ) V_165 [ 2 ] ) ;
F_4 ( L_24 , V_166 ) ;
V_170 = F_111 ( & V_32 -> V_134 , V_166 ) ;
if ( ! V_170 ) {
if ( V_169 ) {
F_4 ( L_25 ) ;
V_54 -> V_133 = V_166 ;
V_27 = F_113 ( & V_32 -> V_134 , V_166 ,
V_169 , V_104 ) ;
if ( V_27 )
F_114 ( V_171 L_26 ,
( int ) V_166 ) ;
} else {
F_4 ( L_27 ) ;
}
V_69 -> V_65 = V_65 ;
V_54 -> V_69 = V_69 ;
return;
}
if ( V_54 -> V_69 ) {
if ( V_169 == NULL ) {
F_4 ( L_28 ) ;
F_82 ( & V_32 -> V_134 , V_166 ) ;
V_54 -> V_69 = NULL ;
return;
}
F_4 ( L_29 ) ;
F_115 ( & V_32 -> V_134 , V_166 , V_169 ) ;
V_69 -> V_65 = V_65 ;
V_54 -> V_69 = V_69 ;
return;
}
if ( V_169 == NULL ) {
F_4 ( L_30 ) ;
F_82 ( & V_32 -> V_134 , V_166 ) ;
return;
}
F_4 ( L_31 ) ;
F_115 ( & V_32 -> V_134 , V_166 , V_169 ) ;
V_69 -> V_65 = V_65 ;
V_54 -> V_69 = V_69 ;
F_4 ( L_32 ,
V_54 -> V_69 , V_169 , V_169 -> V_168 ) ;
}
static struct V_69 * F_116 (
T_7 * V_73 ,
const T_10 V_172 )
{
struct V_138 * V_139 = V_73 -> V_75 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_53 * V_54 ;
struct V_173 * V_174 ;
V_32 = V_139 -> V_152 . V_167 ;
if ( ! V_32 ) {
F_35 ( L_19 ) ;
F_110 () ;
return NULL ;
}
F_4 ( L_33 , V_172 ) ;
V_174 = V_32 -> V_175 + V_172 ;
V_40 = V_174 -> V_40 ;
if ( ! V_40 ) {
F_4 ( L_34 ,
V_172 ) ;
return NULL ;
}
V_54 = F_15 ( V_40 , struct V_53 , V_39 ) ;
if ( ! V_54 -> V_69 ) {
F_35 ( L_23 ) ;
return NULL ;
}
return V_54 -> V_69 ;
}
static void F_117 (
struct V_31 * V_32 ,
struct V_39 * V_169 ,
struct V_53 * V_54 ,
struct V_68 * V_65 ,
struct V_69 * V_69 ,
T_10 V_172 )
{
struct V_39 * V_176 ;
struct V_173 * V_174 ;
F_4 ( L_35 , V_172 ) ;
V_174 = & ( (struct V_173 * )
V_32 -> V_175 ) [ V_172 ] ;
V_176 = V_174 -> V_40 ;
if ( ! V_176 ) {
F_4 ( L_36 ) ;
V_174 -> V_40 = V_169 ;
if ( V_69 -> V_65 != V_65 )
V_69 -> V_65 = V_65 ;
if ( V_54 -> V_69 != V_69 )
V_54 -> V_69 = V_69 ;
return;
}
if ( V_54 -> V_69 ) {
if ( V_169 == NULL ) {
F_4 ( L_37 ) ;
V_174 -> V_40 = NULL ;
V_54 -> V_69 = NULL ;
return;
}
F_4 ( L_38 ) ;
V_174 -> V_40 = V_169 ;
if ( V_69 -> V_65 != V_65 )
V_69 -> V_65 = V_65 ;
if ( V_54 -> V_69 != V_69 )
V_54 -> V_69 = V_69 ;
return;
}
if ( V_169 == NULL ) {
F_4 ( L_39 ) ;
V_174 -> V_40 = NULL ;
return;
}
F_4 ( L_40 ) ;
V_174 -> V_40 = V_169 ;
if ( V_69 -> V_65 != V_65 )
V_69 -> V_65 = V_65 ;
if ( V_54 -> V_69 != V_69 )
V_54 -> V_69 = V_69 ;
F_4 ( L_41 ,
V_54 -> V_69 , V_169 , V_169 -> V_168 ) ;
}
static void F_84 ( struct V_31 * V_32 ,
struct V_53 * V_54 , struct V_69 * V_70 )
{
struct V_68 * V_65 = V_70 -> V_65 ;
unsigned char V_177 [ 3 ] ;
V_177 [ 0 ] = V_70 -> V_165 . V_16 . V_178 ;
V_177 [ 1 ] = V_70 -> V_165 . V_16 . V_179 ;
V_177 [ 2 ] = V_70 -> V_165 . V_16 . V_180 ;
F_112 ( V_32 , NULL , V_54 , V_65 ,
V_70 , V_177 ) ;
F_117 ( V_32 , NULL , V_54 , V_65 ,
V_70 , V_70 -> V_172 ) ;
}
static void F_118 ( struct V_69 * V_70 )
{
struct V_153 * V_152 = V_70 -> V_152 ;
struct V_138 * V_139 = V_152 -> V_139 ;
struct V_68 * V_65 ;
struct V_39 * V_40 ;
struct V_31 * V_32 ;
struct V_53 * V_54 ;
F_52 ( F_119 () ) ;
V_65 = V_70 -> V_65 ;
if ( ! V_65 ) {
F_35 ( L_42 ) ;
F_110 () ;
return;
}
V_40 = V_65 -> V_39 ;
V_54 = F_15 ( V_40 , struct V_53 , V_39 ) ;
V_32 = V_139 -> V_152 . V_167 ;
if ( ! V_32 ) {
F_35 ( L_19 ) ;
F_110 () ;
return;
}
F_120 ( V_65 ) ;
F_121 ( V_70 -> V_65 ) ;
F_122 ( V_70 -> V_65 ) ;
}
static int F_123 (
T_7 * V_73 ,
unsigned char * V_181 ,
void * V_69 ,
T_9 * V_165 ,
T_10 V_172 )
{
struct V_138 * V_139 = V_73 -> V_75 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_68 * V_65 ;
struct V_69 * V_70 = V_69 ;
unsigned char V_182 [ 36 ] ;
unsigned long V_74 ;
V_32 = V_139 -> V_152 . V_167 ;
if ( ! V_32 ) {
F_35 ( L_19 ) ;
F_110 () ;
return - V_22 ;
}
V_30 = V_32 -> V_162 ;
if ( ! V_30 ) {
F_35 ( L_43 ) ;
return - V_22 ;
}
V_2 = & V_30 -> V_2 ;
V_65 = F_124 () ;
if ( F_94 ( V_65 ) ) {
F_35 ( L_44 ) ;
return F_125 ( V_65 ) ;
}
memset ( & V_182 , 0 , 36 ) ;
snprintf ( V_182 , 36 , L_45 ,
V_181 [ 0 ] , V_181 [ 1 ] , V_181 [ 2 ] , V_181 [ 3 ] , V_181 [ 4 ] ,
V_181 [ 5 ] , V_181 [ 6 ] , V_181 [ 7 ] ) ;
V_65 -> V_39 = F_126 ( V_2 ,
V_182 ) ;
if ( ! V_65 -> V_39 ) {
F_127 ( V_65 ) ;
return - V_22 ;
}
V_40 = V_65 -> V_39 ;
V_54 = F_15 ( V_40 , struct V_53 , V_39 ) ;
F_53 ( & V_139 -> V_76 , V_74 ) ;
F_112 ( V_32 , V_40 , V_54 , V_65 ,
V_69 , V_165 ) ;
F_117 ( V_32 , V_40 , V_54 , V_65 ,
V_69 , V_172 ) ;
F_55 ( & V_139 -> V_76 , V_74 ) ;
F_128 ( V_40 -> V_2 , V_40 , V_65 , V_70 ) ;
return 0 ;
}
static void F_129 ( struct V_69 * V_70 , T_11 V_165 ,
T_10 V_172 , bool V_183 )
{
struct V_153 * V_152 = V_70 -> V_152 ;
struct V_138 * V_139 = V_152 -> V_139 ;
struct V_31 * V_32 = V_139 -> V_152 . V_167 ;
struct V_39 * V_40 = V_70 -> V_65 -> V_39 ;
struct V_53 * V_54 = F_15 ( V_40 ,
struct V_53 , V_39 ) ;
T_3 V_166 ;
if ( V_70 -> V_172 != V_172 || V_70 -> V_165 . V_184 != V_165 . V_184 )
F_130 ( L_46 ,
V_70 , V_70 -> V_182 ,
V_70 -> V_172 , V_172 , V_70 -> V_165 . V_16 . V_178 ,
V_70 -> V_165 . V_16 . V_179 , V_70 -> V_165 . V_16 . V_180 , V_165 . V_16 . V_178 ,
V_165 . V_16 . V_179 , V_165 . V_16 . V_180 ) ;
if ( V_70 -> V_172 != V_172 ) {
if ( V_32 -> V_175 [ V_70 -> V_172 ] . V_40 == V_40 )
V_32 -> V_175 [ V_70 -> V_172 ] . V_40 = NULL ;
V_32 -> V_175 [ V_172 ] . V_40 = V_40 ;
V_70 -> V_172 = V_172 ;
}
if ( V_70 -> V_165 . V_184 != V_165 . V_184 ) {
V_166 = ( ( ( T_3 ) V_70 -> V_165 . V_16 . V_178 << 16 ) |
( ( T_3 ) V_70 -> V_165 . V_16 . V_179 << 8 ) |
( ( T_3 ) V_70 -> V_165 . V_16 . V_180 ) ) ;
if ( F_111 ( & V_32 -> V_134 , V_166 ) )
F_131 ( F_82 ( & V_32 -> V_134 , V_166 ) != V_40 ,
L_47 ,
V_70 -> V_165 . V_16 . V_178 , V_70 -> V_165 . V_16 . V_179 , V_70 -> V_165 . V_16 . V_180 ) ;
else
F_131 ( 1 , L_48 ,
V_70 -> V_165 . V_16 . V_178 , V_70 -> V_165 . V_16 . V_179 , V_70 -> V_165 . V_16 . V_180 ) ;
V_166 = ( ( ( T_3 ) V_165 . V_16 . V_178 << 16 ) |
( ( T_3 ) V_165 . V_16 . V_179 << 8 ) |
( ( T_3 ) V_165 . V_16 . V_180 ) ) ;
if ( F_111 ( & V_32 -> V_134 , V_166 ) ) {
F_131 ( 1 , L_49 ,
V_165 . V_16 . V_178 , V_165 . V_16 . V_179 , V_165 . V_16 . V_180 ) ;
F_115 ( & V_32 -> V_134 , V_166 , V_40 ) ;
} else {
F_113 ( & V_32 -> V_134 , V_166 , V_40 , V_104 ) ;
}
V_70 -> V_165 = V_165 ;
V_54 -> V_133 = V_166 ;
}
V_70 -> V_183 = V_183 ;
}
static int F_132 ( struct V_31 * V_32 )
{
int V_27 ;
V_27 = F_133 ( & V_32 -> V_134 ) ;
if ( V_27 ) {
F_35 ( L_50 ) ;
return V_27 ;
}
V_32 -> V_175 = F_134 ( sizeof( struct V_173 ) *
65536 ) ;
if ( ! V_32 -> V_175 ) {
F_35 ( L_51 ,
sizeof( struct V_173 ) * 65536 ) ;
F_135 ( & V_32 -> V_134 ) ;
return - V_144 ;
}
memset ( V_32 -> V_175 , 0 , sizeof( struct V_173 )
* 65536 ) ;
F_4 ( L_52 ,
sizeof( struct V_173 ) * 65536 ) ;
return 0 ;
}
static int F_136 ( struct V_72 * V_73 )
{
struct V_138 * V_139 = V_73 -> V_75 ;
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) V_139 -> V_152 . V_167 ;
V_32 -> V_150 = V_73 ;
return 0 ;
}
static struct V_129 * F_137 (
struct V_185 * V_186 ,
struct V_140 * V_141 ,
const char * V_3 )
{
struct V_31 * V_32 ;
T_2 V_24 ;
int V_44 = - V_154 ;
if ( F_3 ( V_3 , & V_24 , 1 ) < 0 )
return F_92 ( - V_22 ) ;
V_32 = F_34 ( sizeof( struct V_31 ) , V_55 ) ;
if ( ! V_32 ) {
F_35 ( L_53 ) ;
return F_92 ( - V_144 ) ;
}
V_32 -> V_187 = V_24 ;
F_5 ( & V_32 -> V_188 [ 0 ] , V_12 ,
V_24 ) ;
sprintf ( V_32 -> V_36 , L_54 , ( unsigned long long ) V_24 ) ;
V_44 = F_132 ( V_32 ) ;
if ( V_44 != 0 )
goto V_189;
V_44 = F_138 ( & V_190 , V_24 ,
F_136 , V_32 ) ;
if ( V_44 != 0 )
goto V_191;
return & V_32 -> V_131 ;
V_191:
F_139 ( V_32 -> V_175 ) ;
F_135 ( & V_32 -> V_134 ) ;
V_189:
F_37 ( V_32 ) ;
return F_92 ( V_44 ) ;
}
static void F_140 ( struct V_129 * V_4 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_131 ) ;
struct V_72 * V_73 = V_32 -> V_150 ;
struct V_138 * V_139 = V_73 -> V_75 ;
struct V_39 * V_132 ;
T_3 V_166 = 0 ;
if ( V_139 -> V_152 . V_153 && ! V_139 -> V_152 . V_153 -> V_192 )
F_141 ( V_139 -> V_152 . V_153 ) ;
F_142 ( V_73 ) ;
F_139 ( V_32 -> V_175 ) ;
F_143 (&lport->lport_fcport_map, key, node)
F_82 ( & V_32 -> V_134 , V_166 ) ;
F_135 ( & V_32 -> V_134 ) ;
F_37 ( V_32 ) ;
}
static struct V_129 * F_144 (
struct V_185 * V_186 ,
struct V_140 * V_141 ,
const char * V_3 )
{
struct V_31 * V_32 ;
T_2 V_193 , V_194 ;
int V_44 ;
if ( F_11 ( V_3 , strlen ( V_3 ) + 1 ,
& V_193 , & V_194 ) < 0 )
return F_92 ( - V_22 ) ;
V_32 = F_34 ( sizeof( struct V_31 ) , V_55 ) ;
if ( ! V_32 ) {
F_35 ( L_55 ) ;
return F_92 ( - V_144 ) ;
}
V_32 -> V_195 = V_193 ;
V_32 -> V_196 = V_194 ;
F_12 ( & V_32 -> V_37 [ 0 ] ,
V_12 , V_193 , V_194 ) ;
sprintf ( V_32 -> V_36 , L_54 , ( unsigned long long ) V_193 ) ;
V_44 = - V_158 ;
if ( V_44 != 0 )
goto V_189;
return & V_32 -> V_131 ;
V_189:
F_37 ( V_32 ) ;
return F_92 ( V_44 ) ;
}
static void F_145 ( struct V_129 * V_4 )
{
struct V_31 * V_32 = F_15 ( V_4 ,
struct V_31 , V_131 ) ;
struct V_72 * V_73 = V_32 -> V_150 ;
struct V_197 * V_198 = V_73 -> V_199 ;
F_146 ( V_32 -> V_200 ) ;
F_147 ( V_198 ) ;
F_37 ( V_32 ) ;
}
static T_1 F_148 (
struct V_185 * V_186 ,
char * V_147 )
{
return sprintf ( V_147 ,
L_56
V_201 L_57 , V_202 , F_149 () -> V_203 ,
F_149 () -> V_204 ) ;
}
static int F_150 ( void )
{
struct V_185 * V_205 , * V_206 ;
int V_44 ;
F_4 ( L_58
V_201 L_57 , V_202 , F_149 () -> V_203 ,
F_149 () -> V_204 ) ;
V_205 = F_151 ( V_207 , L_3 ) ;
if ( F_94 ( V_205 ) ) {
F_35 ( L_59 ) ;
return F_125 ( V_205 ) ;
}
V_205 -> V_160 = V_208 ;
F_152 ( V_205 ) -> V_209 . V_210 = V_211 ;
F_152 ( V_205 ) -> V_212 . V_210 = V_213 ;
F_152 ( V_205 ) -> V_214 . V_210 =
V_215 ;
F_152 ( V_205 ) -> V_216 . V_210 = NULL ;
F_152 ( V_205 ) -> V_217 . V_210 = NULL ;
F_152 ( V_205 ) -> V_218 . V_210 = NULL ;
F_152 ( V_205 ) -> V_219 . V_210 = NULL ;
F_152 ( V_205 ) -> V_220 . V_210 = NULL ;
F_152 ( V_205 ) -> V_221 . V_210 = NULL ;
V_44 = F_153 ( V_205 ) ;
if ( V_44 < 0 ) {
F_35 ( L_60 ) ;
return V_44 ;
}
V_159 = V_205 ;
F_4 ( L_61 ) ;
V_206 = F_151 ( V_207 , L_5 ) ;
if ( F_94 ( V_206 ) ) {
F_35 ( L_59 ) ;
V_44 = F_125 ( V_206 ) ;
goto V_222;
}
V_206 -> V_160 = V_223 ;
F_152 ( V_206 ) -> V_209 . V_210 = V_211 ;
F_152 ( V_206 ) -> V_212 . V_210 = NULL ;
F_152 ( V_206 ) -> V_214 . V_210 = NULL ;
F_152 ( V_206 ) -> V_216 . V_210 = NULL ;
F_152 ( V_206 ) -> V_217 . V_210 = NULL ;
F_152 ( V_206 ) -> V_218 . V_210 = NULL ;
F_152 ( V_206 ) -> V_219 . V_210 = NULL ;
F_152 ( V_206 ) -> V_220 . V_210 = NULL ;
F_152 ( V_206 ) -> V_221 . V_210 = NULL ;
V_44 = F_153 ( V_206 ) ;
if ( V_44 < 0 ) {
F_35 ( L_60 ) ;
goto V_222;
}
V_164 = V_206 ;
F_4 ( L_62 ) ;
V_62 = F_154 ( L_63 ,
V_224 , 0 ) ;
if ( ! V_62 ) {
V_44 = - V_144 ;
goto V_225;
}
V_226 = F_154 ( L_64 , 0 , 0 ) ;
if ( ! V_226 ) {
V_44 = - V_144 ;
goto V_227;
}
return 0 ;
V_227:
F_155 ( V_62 ) ;
V_225:
F_156 ( V_164 ) ;
V_222:
F_156 ( V_159 ) ;
return V_44 ;
}
static void F_157 ( void )
{
F_155 ( V_226 ) ;
F_155 ( V_62 ) ;
F_156 ( V_159 ) ;
V_159 = NULL ;
F_4 ( L_65 ) ;
F_156 ( V_164 ) ;
V_164 = NULL ;
F_4 ( L_66 ) ;
}
static int T_12 F_158 ( void )
{
int V_44 ;
V_44 = F_150 () ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
}
static void T_13 F_159 ( void )
{
F_157 () ;
}
