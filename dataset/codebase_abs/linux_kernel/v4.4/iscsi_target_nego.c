void F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] == '\0' )
V_1 [ V_3 ] = ';' ;
}
static int F_2 ( char * V_1 )
{
int V_3 = 0 ;
while ( V_1 [ V_3 ] != '\0' ) {
if ( V_1 [ V_3 ] == ';' )
return V_3 ;
V_3 ++ ;
}
return - 1 ;
}
int F_3 (
const char * V_4 ,
const char * V_5 ,
unsigned int V_6 ,
char * V_7 ,
unsigned char * type )
{
char * V_8 ;
int V_2 ;
if ( ! V_4 || ! V_5 || ! V_7 || ! type )
return - 1 ;
V_8 = strstr ( V_4 , V_5 ) ;
if ( ! V_8 )
return - 1 ;
V_8 = strstr ( V_8 , L_1 ) ;
if ( ! V_8 )
return - 1 ;
V_8 += 1 ;
if ( * V_8 == '0' && ( * ( V_8 + 1 ) == 'x' || * ( V_8 + 1 ) == 'X' ) ) {
V_8 += 2 ;
* type = V_9 ;
} else
* type = V_10 ;
V_2 = F_2 ( V_8 ) ;
if ( V_2 < 0 )
return - 1 ;
if ( V_2 >= V_6 ) {
F_4 ( L_2
L_3 , V_2 , V_6 ) ;
return - 1 ;
}
memcpy ( V_7 , V_8 , V_2 ) ;
V_7 [ V_2 ] = '\0' ;
return 0 ;
}
static T_1 F_5 (
struct V_11 * V_12 ,
char * V_4 ,
char * V_7 ,
int V_13 ,
int * V_14 ,
unsigned char * V_15 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
if ( ! V_17 -> V_26 -> V_27 ) {
V_25 = V_12 -> V_17 -> V_28 -> V_24 ;
if ( ! V_25 ) {
F_4 ( L_4
L_5 ) ;
return - 1 ;
}
V_21 = F_6 ( V_25 , struct V_20 ,
V_24 ) ;
if ( ! V_21 ) {
F_4 ( L_6
L_5 ) ;
return - 1 ;
}
if ( V_25 -> V_29 ) {
V_23 = F_6 ( V_25 -> V_30 ,
struct V_22 , V_31 ) ;
V_19 = & V_23 -> V_32 ;
} else {
V_21 = F_6 ( V_25 , struct V_20 ,
V_24 ) ;
V_19 = & V_21 -> V_33 ;
}
} else {
V_19 = & V_34 -> V_35 . V_33 ;
}
if ( strstr ( L_7 , V_15 ) )
strcpy ( V_12 -> V_17 -> V_36 , L_7 ) ;
else
strcpy ( V_12 -> V_17 -> V_36 , V_37 ) ;
if ( strstr ( L_8 , V_15 ) )
return 1 ;
#ifdef F_7
else if ( strstr ( L_9 , V_15 ) )
return F_8 ( V_12 , V_19 , V_4 , V_7 ,
& V_13 , V_14 ) ;
#endif
else if ( strstr ( L_7 , V_15 ) )
return F_9 ( V_12 , V_19 , V_4 , V_7 ,
& V_13 , V_14 ) ;
else if ( strstr ( L_10 , V_15 ) )
return 2 ;
else if ( strstr ( L_11 , V_15 ) )
return 2 ;
else if ( strstr ( L_12 , V_15 ) )
return 2 ;
else
return 2 ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_38 ) ;
}
int F_12 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_41 , V_42 ;
T_1 V_43 ;
struct V_44 * V_45 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
switch ( V_45 -> V_48 & V_49 ) {
case V_50 :
break;
default:
F_4 ( L_13 ,
V_45 -> V_48 & V_49 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_45 -> V_53 & V_54 ) &&
( V_45 -> V_53 & V_55 ) ) {
F_4 ( L_14
L_15 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
V_41 = F_15 ( V_45 -> V_53 ) ;
V_42 = F_16 ( V_45 -> V_53 ) ;
if ( V_41 != V_40 -> V_56 ) {
F_4 ( L_16
L_17 , V_40 -> V_56 ,
V_41 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_42 == 2 ) || ( V_41 >= 2 ) ||
( ( V_45 -> V_53 & V_55 ) &&
( V_42 <= V_41 ) ) ) {
F_4 ( L_18
L_19 , V_41 ,
V_42 , ( V_45 -> V_53 & V_55 ) ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_45 -> V_57 != V_40 -> V_58 ) ||
( V_45 -> V_59 != V_40 -> V_60 ) ) {
F_4 ( L_20
L_21 ,
V_45 -> V_57 , V_45 -> V_59 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( memcmp ( V_45 -> V_61 , V_40 -> V_61 , 6 ) != 0 ) {
F_4 ( L_22
L_23 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_45 -> V_62 != V_40 -> V_63 ) {
F_4 ( L_24
L_25 , V_45 -> V_62 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_43 > V_64 ) {
F_4 ( L_26
L_27 ,
V_64 ) ;
return - 1 ;
}
return 0 ;
}
static int F_17 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
struct V_65 * V_66 = NULL ;
struct V_24 * V_25 ;
V_40 -> V_67 = 0 ;
F_18 (param, &conn->param_list->param_list, p_list) {
if ( ! strncmp ( V_66 -> V_68 , V_69 , 11 ) ) {
if ( ! F_19 ( V_66 ) ) {
F_4 ( L_28
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
return - 1 ;
}
if ( ! strncmp ( V_66 -> V_71 , V_72 , 9 ) )
return 0 ;
}
if ( ! strncmp ( V_66 -> V_68 , V_73 , 13 ) ) {
if ( ! F_19 ( V_66 ) ) {
if ( ! V_40 -> V_74 )
continue;
F_4 ( L_30
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
return - 1 ;
}
if ( ! V_40 -> V_74 ) {
V_25 = V_12 -> V_17 -> V_28 -> V_24 ;
if ( ! V_25 ) {
F_4 ( L_31
L_32 ) ;
F_14 ( V_12 ,
V_51 ,
V_75 ) ;
return - 1 ;
}
if ( strcmp ( V_66 -> V_71 ,
V_25 -> V_76 ) ) {
F_4 ( L_33
L_34
L_35 ,
V_66 -> V_71 ) ;
F_14 ( V_12 ,
V_51 ,
V_75 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
T_1 V_77 = 0 ;
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_79 -> V_48 = V_81 ;
F_21 ( V_79 -> V_47 , V_40 -> V_82 ) ;
memcpy ( V_79 -> V_61 , V_40 -> V_61 , 6 ) ;
V_79 -> V_83 = F_22 ( V_40 -> V_83 ) ;
V_79 -> V_62 = V_40 -> V_63 ;
V_79 -> V_84 = F_23 ( V_12 -> V_85 ++ ) ;
V_79 -> V_86 = F_23 ( V_12 -> V_17 -> V_87 ) ;
V_79 -> V_88 = F_23 ( ( T_1 ) F_24 ( & V_12 -> V_17 -> V_89 ) ) ;
F_25 ( L_36
L_37
L_38 , V_79 -> V_53 , ( V_90 T_1 ) V_79 -> V_62 ,
F_26 ( V_79 -> V_86 ) , F_26 ( V_79 -> V_88 ) ,
F_26 ( V_79 -> V_84 ) , V_40 -> V_82 ) ;
V_77 = ( ( - V_40 -> V_82 ) & 3 ) ;
if ( V_40 -> V_91 ) {
int V_92 = F_27 ( V_12 ) ;
if ( V_92 ) {
F_14 ( V_12 , V_93 ,
V_94 ) ;
return - 1 ;
}
}
if ( V_12 -> V_95 -> V_96 ( V_12 , V_40 ,
V_40 -> V_82 + V_77 ) < 0 )
goto V_97;
V_40 -> V_82 = 0 ;
return 0 ;
V_97:
if ( V_40 -> V_91 ) {
if ( V_12 -> V_98 && V_12 -> V_99 ) {
F_28 ( V_100 , V_12 -> V_98 , 1 ) ;
F_29 ( & V_12 -> V_101 ) ;
F_30 ( V_12 -> V_98 ) ;
}
if ( V_12 -> V_102 && V_12 -> V_103 ) {
F_28 ( V_100 , V_12 -> V_102 , 1 ) ;
F_30 ( V_12 -> V_102 ) ;
}
F_31 ( & V_34 -> V_104 ) ;
F_32 ( V_34 -> V_105 , V_12 -> V_106 ,
F_33 ( 1 ) ) ;
F_34 ( & V_34 -> V_104 ) ;
}
return - 1 ;
}
static void F_35 ( struct V_107 * V_108 )
{
struct V_11 * V_12 = V_108 -> V_109 ;
bool V_92 ;
F_25 ( L_39 , V_12 ) ;
F_36 ( & V_108 -> V_110 ) ;
if ( ! V_108 -> V_109 ) {
F_37 ( & V_108 -> V_110 ) ;
return;
}
if ( ! F_38 ( V_111 , & V_12 -> V_112 ) ) {
F_37 ( & V_108 -> V_110 ) ;
F_25 ( L_40 , V_12 ) ;
return;
}
if ( F_38 ( V_113 , & V_12 -> V_112 ) ) {
F_37 ( & V_108 -> V_110 ) ;
F_25 ( L_41 , V_12 ) ;
return;
}
if ( F_39 ( V_114 , & V_12 -> V_112 ) ) {
F_37 ( & V_108 -> V_110 ) ;
F_25 ( L_42 , V_12 ) ;
return;
}
V_92 = F_40 ( & V_12 -> V_115 , 0 ) ;
if ( ! V_92 ) {
F_25 ( L_43
L_44 ) ;
}
F_37 ( & V_108 -> V_110 ) ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_107 * V_108 ;
if ( ! V_12 -> V_107 )
return;
V_108 = V_12 -> V_107 -> V_108 ;
F_25 ( L_45 , V_12 ) ;
F_36 ( & V_108 -> V_110 ) ;
V_108 -> V_109 = V_12 ;
V_12 -> V_116 = V_108 -> V_117 ;
V_12 -> V_118 = V_108 -> V_119 ;
V_108 -> V_117 = F_35 ;
V_108 -> V_119 = V_120 ;
F_37 ( & V_108 -> V_110 ) ;
V_108 -> V_121 = V_122 * V_123 ;
V_108 -> V_124 = V_122 * V_123 ;
}
static void F_42 ( struct V_11 * V_12 )
{
struct V_107 * V_108 ;
if ( ! V_12 -> V_107 )
return;
V_108 = V_12 -> V_107 -> V_108 ;
F_25 ( L_46 , V_12 ) ;
F_36 ( & V_108 -> V_110 ) ;
if ( ! V_108 -> V_109 ) {
F_37 ( & V_108 -> V_110 ) ;
return;
}
V_108 -> V_109 = NULL ;
V_108 -> V_117 = V_12 -> V_116 ;
V_108 -> V_119 = V_12 -> V_118 ;
F_37 ( & V_108 -> V_110 ) ;
V_108 -> V_121 = V_125 ;
V_108 -> V_124 = V_125 ;
}
static bool F_43 ( struct V_107 * V_108 )
{
if ( V_108 -> V_126 == V_127 || V_108 -> V_126 == V_128 ) {
F_25 ( L_47
L_48 ) ;
return false ;
}
return true ;
}
static void F_44 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
struct V_129 * V_130 = V_40 -> V_130 ;
bool V_131 = V_40 -> V_131 ;
F_10 ( V_12 ) ;
F_45 ( V_12 ) ;
F_46 ( V_12 , V_130 , V_131 , true ) ;
}
static void F_47 ( unsigned long V_132 )
{
struct V_11 * V_12 = (struct V_11 * ) V_132 ;
F_25 ( L_49 ) ;
if ( V_12 -> V_133 ) {
F_25 ( L_50 ,
V_12 -> V_133 -> V_134 , V_12 -> V_133 -> V_135 ) ;
F_28 ( V_100 , V_12 -> V_133 , 1 ) ;
}
}
static void F_48 ( struct V_136 * V_137 )
{
struct V_11 * V_12 = F_6 ( V_137 ,
struct V_11 , V_115 . V_137 ) ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_129 * V_130 = V_40 -> V_130 ;
struct V_22 * V_138 = V_12 -> V_138 ;
struct V_139 * V_140 = V_12 -> V_140 ;
struct V_141 V_142 ;
int V_92 , V_131 = V_40 -> V_131 ;
bool V_143 ;
F_25 ( L_51 ,
V_12 , V_144 -> V_134 , V_144 -> V_135 ) ;
F_31 ( & V_138 -> V_145 ) ;
V_143 = ( V_138 -> V_146 == V_147 ) ;
F_34 ( & V_138 -> V_145 ) ;
if ( ! V_143 ) {
F_25 ( L_52 ) ;
F_42 ( V_12 ) ;
F_44 ( V_12 , V_40 ) ;
F_49 ( V_130 , V_138 , V_140 ) ;
return;
}
if ( V_12 -> V_107 ) {
struct V_107 * V_108 = V_12 -> V_107 -> V_108 ;
F_50 ( & V_108 -> V_110 ) ;
V_143 = F_43 ( V_108 ) ;
F_51 ( & V_108 -> V_110 ) ;
if ( ! V_143 ) {
F_25 ( L_53 ) ;
F_42 ( V_12 ) ;
F_44 ( V_12 , V_40 ) ;
F_49 ( V_130 , V_138 , V_140 ) ;
return;
}
}
V_12 -> V_133 = V_144 ;
F_52 ( V_100 ) ;
F_53 ( & V_142 ) ;
V_142 . V_148 = ( F_54 () + V_122 * V_123 ) ;
V_142 . V_132 = ( unsigned long ) V_12 ;
V_142 . V_149 = F_47 ;
F_55 ( & V_142 ) ;
F_25 ( L_54 , V_144 -> V_134 , V_144 -> V_135 ) ;
V_92 = V_12 -> V_95 -> V_150 ( V_12 , V_40 ) ;
F_56 ( & V_142 ) ;
F_57 ( V_144 ) ;
V_12 -> V_133 = NULL ;
if ( V_92 < 0 ) {
F_42 ( V_12 ) ;
F_44 ( V_12 , V_40 ) ;
F_49 ( V_130 , V_138 , V_140 ) ;
return;
}
F_25 ( L_55 ,
V_12 , V_144 -> V_134 , V_144 -> V_135 ) ;
V_92 = F_58 ( V_12 , V_40 ) ;
if ( V_92 < 0 ) {
F_42 ( V_12 ) ;
F_44 ( V_12 , V_40 ) ;
F_49 ( V_130 , V_138 , V_140 ) ;
} else if ( ! V_92 ) {
if ( V_12 -> V_107 ) {
struct V_107 * V_108 = V_12 -> V_107 -> V_108 ;
F_36 ( & V_108 -> V_110 ) ;
F_59 ( V_114 , & V_12 -> V_112 ) ;
F_37 ( & V_108 -> V_110 ) ;
}
} else if ( V_92 == 1 ) {
F_45 ( V_12 ) ;
F_60 ( V_130 , V_12 , V_131 ) ;
F_49 ( V_130 , V_138 , V_140 ) ;
}
}
static void F_61 ( struct V_136 * V_137 )
{
struct V_11 * V_12 = F_6 ( V_137 ,
struct V_11 , V_151 . V_137 ) ;
struct V_107 * V_108 = V_12 -> V_107 -> V_108 ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_129 * V_130 = V_40 -> V_130 ;
struct V_22 * V_138 = V_12 -> V_138 ;
struct V_139 * V_140 = V_12 -> V_140 ;
F_25 ( L_56 ) ;
F_62 ( & V_12 -> V_115 ) ;
V_12 -> V_118 ( V_108 ) ;
F_42 ( V_12 ) ;
F_44 ( V_12 , V_40 ) ;
F_49 ( V_130 , V_138 , V_140 ) ;
F_25 ( L_57 ) ;
}
static void V_120 ( struct V_107 * V_108 )
{
struct V_11 * V_12 ;
void (* V_118)( struct V_107 * );
bool V_143 ;
F_25 ( L_58 ) ;
F_36 ( & V_108 -> V_110 ) ;
V_12 = V_108 -> V_109 ;
if ( ! V_12 ) {
F_37 ( & V_108 -> V_110 ) ;
return;
}
V_118 = V_12 -> V_118 ;
if ( ! F_38 ( V_111 , & V_12 -> V_112 ) ) {
F_25 ( L_59 ,
V_12 ) ;
F_37 ( & V_108 -> V_110 ) ;
V_118 ( V_108 ) ;
return;
}
if ( F_38 ( V_114 , & V_12 -> V_112 ) ) {
F_25 ( L_60
L_61 , V_12 ) ;
F_37 ( & V_108 -> V_110 ) ;
V_118 ( V_108 ) ;
return;
}
if ( F_39 ( V_113 , & V_12 -> V_112 ) ) {
F_25 ( L_62 ,
V_12 ) ;
F_37 ( & V_108 -> V_110 ) ;
V_118 ( V_108 ) ;
return;
}
V_143 = F_43 ( V_108 ) ;
F_37 ( & V_108 -> V_110 ) ;
F_25 ( L_63 , V_143 ) ;
if ( ! V_143 ) {
F_25 ( L_64 ) ;
F_40 ( & V_12 -> V_151 , 0 ) ;
return;
}
V_118 ( V_108 ) ;
}
static int F_63 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_152 )
return 0 ;
V_40 -> V_152 = 1 ;
if ( ! V_40 -> V_83 )
return F_64 ( V_12 ) ;
else
return F_65 ( V_12 , V_40 -> V_153 ,
V_40 -> V_154 ) ;
}
static int F_66 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_155 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_66 = F_67 ( V_156 , V_12 -> V_157 ) ;
if ( ! V_66 )
return - 1 ;
V_155 = F_5 (
V_12 ,
V_40 -> V_158 ,
V_40 -> V_159 ,
V_43 ,
& V_40 -> V_82 ,
V_66 -> V_71 ) ;
switch ( V_155 ) {
case 0 :
F_25 ( L_65
L_66 ) ;
break;
case 1 :
F_25 ( L_67
L_68 ) ;
V_40 -> V_160 = 1 ;
if ( ( V_45 -> V_53 & V_161 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= ( V_161 |
V_55 ) ;
V_40 -> V_56 = 1 ;
}
return F_63 (
V_12 , V_40 ) ;
case 2 :
F_4 ( L_69
L_70 ) ;
F_14 ( V_12 , V_51 ,
V_162 ) ;
return - 1 ;
default:
F_4 ( L_71
L_72 , V_155 ) ;
F_14 ( V_12 , V_93 ,
V_163 ) ;
return - 1 ;
}
return 0 ;
}
static int F_68 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_164 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_66 = F_67 ( V_156 , V_12 -> V_157 ) ;
if ( ! V_66 )
return - 1 ;
V_164 = F_69 (
V_165 | V_166 ,
V_167 | V_168 ,
V_40 -> V_158 ,
V_43 ,
V_12 ) ;
if ( V_164 < 0 )
return - 1 ;
if ( V_164 > 0 ) {
if ( V_40 -> V_160 ) {
F_4 ( L_73
L_74
L_75 , V_66 -> V_71 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
goto V_169;
} else if ( ! V_43 ) {
F_4 ( L_76
L_77 ) ;
F_14 ( V_12 , V_51 ,
V_162 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_17 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_164 = F_70 (
V_165 | V_166 ,
V_170 ,
V_40 -> V_159 ,
& V_40 -> V_82 ,
V_12 -> V_157 ) ;
if ( V_164 < 0 )
return - 1 ;
if ( ! F_71 ( V_12 -> V_157 ) ) {
if ( V_12 -> V_138 -> V_171 . V_172 &&
! strncmp ( V_66 -> V_71 , V_37 , 4 ) ) {
F_4 ( L_78
L_79
L_80 ) ;
F_14 ( V_12 , V_51 ,
V_162 ) ;
return - 1 ;
}
if ( V_12 -> V_138 -> V_171 . V_172 &&
! V_40 -> V_160 )
return 0 ;
if ( strncmp ( V_66 -> V_71 , V_37 , 4 ) && ! V_40 -> V_160 )
return 0 ;
if ( ( V_45 -> V_53 & V_161 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= V_161 |
V_55 ;
V_40 -> V_56 = 1 ;
}
}
return 0 ;
V_169:
return F_66 ( V_12 , V_40 ) ;
}
static int F_72 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_164 ;
T_1 V_43 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_164 = F_69 (
V_173 | V_166 ,
V_167 | V_168 ,
V_40 -> V_158 ,
V_43 ,
V_12 ) ;
if ( V_164 < 0 ) {
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_17 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( F_63 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_164 = F_70 (
V_173 | V_166 ,
V_170 ,
V_40 -> V_159 ,
& V_40 -> V_82 ,
V_12 -> V_157 ) ;
if ( V_164 < 0 ) {
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ! V_40 -> V_160 &&
V_12 -> V_138 -> V_171 . V_172 ) {
F_4 ( L_81
L_82
L_83 ) ;
F_14 ( V_12 , V_51 ,
V_162 ) ;
return - 1 ;
}
if ( ! F_71 ( V_12 -> V_157 ) )
if ( ( V_45 -> V_53 & V_174 ) &&
( V_45 -> V_53 & V_55 ) )
V_79 -> V_53 |= V_174 |
V_55 ;
return 0 ;
}
static int F_58 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_175 = 0 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
while ( 1 ) {
if ( ++ V_175 > V_176 ) {
F_4 ( L_84 ) ;
F_14 ( V_12 , V_93 ,
V_163 ) ;
return - 1 ;
}
switch ( F_15 ( V_45 -> V_53 ) ) {
case 0 :
V_79 -> V_53 &= ~ V_177 ;
if ( F_68 ( V_12 , V_40 ) < 0 )
return - 1 ;
break;
case 1 :
V_79 -> V_53 |= V_178 ;
if ( F_72 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_40 -> V_83 = V_12 -> V_17 -> V_83 ;
V_40 -> V_91 = 1 ;
F_42 ( V_12 ) ;
if ( F_20 ( V_12 ,
V_40 ) < 0 )
return - 1 ;
return 1 ;
}
break;
default:
F_4 ( L_85
L_86 ,
F_15 ( V_45 -> V_53 ) ) ;
break;
}
if ( F_20 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_79 -> V_53 &= ~ V_55 ;
V_79 -> V_53 &= ~ V_179 ;
}
break;
}
if ( V_12 -> V_107 ) {
struct V_107 * V_108 = V_12 -> V_107 -> V_108 ;
bool V_143 ;
F_50 ( & V_108 -> V_110 ) ;
V_143 = F_43 ( V_108 ) ;
F_51 ( & V_108 -> V_110 ) ;
if ( ! V_143 ) {
F_25 ( L_87
L_61 , V_12 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_73 (
char * V_180 )
{
char * V_181 ;
T_1 V_182 = strlen ( V_180 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_182 ; V_3 ++ ) {
V_181 = & V_180 [ V_3 ] ;
if ( ! isupper ( * V_181 ) )
continue;
* V_181 = tolower ( * V_181 ) ;
}
}
int F_74 (
struct V_129 * V_130 ,
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
char * V_183 = NULL , * V_184 = NULL , * V_185 = NULL ;
char * V_186 , * V_187 = NULL , * V_188 = NULL , * V_189 , * V_71 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_190 * V_191 ;
struct V_139 * V_140 = NULL ;
struct V_44 * V_45 ;
struct V_24 * V_25 ;
T_1 V_43 , V_192 = 0 ;
int V_193 = 0 , V_164 = 0 , V_194 , V_195 ;
F_75 ( & V_12 -> V_115 , F_48 ) ;
F_75 ( & V_12 -> V_151 , F_61 ) ;
F_41 ( V_12 ) ;
V_40 -> V_130 = V_130 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_186 = F_76 ( V_43 + 1 , V_196 ) ;
if ( ! V_186 ) {
F_4 ( L_88 ) ;
return - 1 ;
}
memcpy ( V_186 , V_40 -> V_158 , V_43 ) ;
V_186 [ V_43 ] = '\0' ;
V_187 = V_186 ;
V_188 = ( V_187 + V_43 ) ;
while ( V_187 < V_188 ) {
if ( F_77 ( V_187 , & V_189 , & V_71 ) < 0 ) {
V_164 = - 1 ;
goto V_197;
}
if ( ! strncmp ( V_189 , L_89 , 13 ) )
V_183 = V_71 ;
else if ( ! strncmp ( V_189 , L_90 , 11 ) )
V_184 = V_71 ;
else if ( ! strncmp ( V_189 , L_91 , 10 ) )
V_185 = V_71 ;
V_187 += strlen ( V_189 ) + strlen ( V_71 ) + 2 ;
}
if ( ! V_183 ) {
F_4 ( L_30
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_164 = - 1 ;
goto V_197;
}
F_73 ( V_183 ) ;
if ( ! V_184 ) {
if ( ! V_40 -> V_74 )
goto V_198;
F_4 ( L_28
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_164 = - 1 ;
goto V_197;
}
V_193 = strncmp ( V_184 , V_72 , 9 ) ;
if ( ! V_193 ) {
V_12 -> V_138 = V_34 -> V_199 ;
if ( ! V_40 -> V_74 )
goto V_198;
V_17 -> V_26 -> V_27 = 1 ;
if ( F_78 ( V_12 ) < 0 ) {
F_4 ( L_92 ) ;
V_164 = - 1 ;
goto V_197;
}
if ( F_79 ( V_130 , V_12 -> V_138 ) < 0 ) {
F_14 ( V_12 , V_93 ,
V_200 ) ;
V_164 = - 1 ;
goto V_197;
}
V_164 = 0 ;
goto V_201;
}
V_198:
if ( ! V_185 ) {
F_4 ( L_93
L_94
L_95 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_164 = - 1 ;
goto V_197;
}
V_191 = F_80 ( V_185 ) ;
if ( ! V_191 ) {
F_4 ( L_96
L_97 , V_185 ) ;
F_14 ( V_12 , V_93 ,
V_200 ) ;
V_164 = - 1 ;
goto V_197;
}
F_25 ( L_98 , V_191 -> V_191 ) ;
V_12 -> V_138 = F_81 ( V_191 , V_130 , & V_140 ) ;
if ( ! V_12 -> V_138 ) {
F_4 ( L_99
L_100 , V_191 -> V_191 ) ;
F_82 ( V_191 ) ;
F_14 ( V_12 , V_93 ,
V_200 ) ;
V_164 = - 1 ;
goto V_197;
}
V_12 -> V_140 = V_140 ;
F_25 ( L_101 , V_12 -> V_138 -> V_202 ) ;
if ( F_78 ( V_12 ) < 0 ) {
F_4 ( L_92 ) ;
F_83 ( & V_140 -> V_203 , V_204 ) ;
F_82 ( V_191 ) ;
V_12 -> V_138 = NULL ;
V_164 = - 1 ;
goto V_197;
}
if ( F_79 ( V_130 , V_12 -> V_138 ) < 0 ) {
F_83 ( & V_140 -> V_203 , V_204 ) ;
F_82 ( V_191 ) ;
F_14 ( V_12 , V_93 ,
V_200 ) ;
V_12 -> V_138 = NULL ;
V_164 = - 1 ;
goto V_197;
}
if ( ! V_40 -> V_74 ) {
V_164 = 0 ;
goto V_197;
}
V_17 -> V_26 -> V_27 = 0 ;
V_17 -> V_28 -> V_24 = F_84 (
& V_12 -> V_138 -> V_31 , V_183 ) ;
if ( ! V_17 -> V_28 -> V_24 ) {
F_4 ( L_102
L_103 ,
V_183 , V_12 -> V_138 -> V_202 ) ;
F_14 ( V_12 , V_51 ,
V_205 ) ;
V_164 = - 1 ;
goto V_197;
}
V_25 = V_17 -> V_28 -> V_24 ;
V_192 = V_25 -> V_192 ;
V_201:
V_194 = F_85 ( T_1 , V_206 , V_192 ) ;
V_194 = ( V_194 * 2 ) + V_207 ;
V_195 = sizeof( struct V_208 ) + V_12 -> V_95 -> V_209 ;
V_164 = F_86 ( V_17 -> V_28 , V_194 , V_195 ) ;
if ( V_164 < 0 ) {
F_14 ( V_12 , V_93 ,
V_94 ) ;
V_164 = - 1 ;
}
V_197:
F_11 ( V_186 ) ;
return V_164 ;
}
int F_87 (
struct V_39 * V_40 ,
struct V_11 * V_12 )
{
int V_164 ;
V_164 = F_58 ( V_12 , V_40 ) ;
if ( ! V_164 ) {
if ( V_12 -> V_107 ) {
struct V_107 * V_108 = V_12 -> V_107 -> V_108 ;
F_36 ( & V_108 -> V_110 ) ;
F_88 ( V_111 , & V_12 -> V_112 ) ;
F_37 ( & V_108 -> V_110 ) ;
}
} else if ( V_164 < 0 ) {
F_62 ( & V_12 -> V_115 ) ;
F_62 ( & V_12 -> V_151 ) ;
F_42 ( V_12 ) ;
F_10 ( V_12 ) ;
}
if ( V_164 != 0 )
F_45 ( V_12 ) ;
return V_164 ;
}
void F_45 ( struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_210 ;
if ( ! V_40 )
return;
F_11 ( V_40 -> V_158 ) ;
F_11 ( V_40 -> V_159 ) ;
F_11 ( V_40 ) ;
V_12 -> V_210 = NULL ;
}
