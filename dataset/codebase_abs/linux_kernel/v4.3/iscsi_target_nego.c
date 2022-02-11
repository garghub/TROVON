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
F_29 ( V_12 -> V_98 ) ;
}
if ( V_12 -> V_101 && V_12 -> V_102 ) {
F_28 ( V_100 , V_12 -> V_101 , 1 ) ;
F_29 ( V_12 -> V_101 ) ;
}
F_30 ( & V_34 -> V_103 ) ;
F_31 ( V_34 -> V_104 , V_12 -> V_105 ,
F_32 ( 1 ) ) ;
F_33 ( & V_34 -> V_103 ) ;
}
return - 1 ;
}
static void F_34 ( struct V_106 * V_107 )
{
struct V_11 * V_12 = V_107 -> V_108 ;
bool V_92 ;
F_25 ( L_39 , V_12 ) ;
F_35 ( & V_107 -> V_109 ) ;
if ( ! V_107 -> V_108 ) {
F_36 ( & V_107 -> V_109 ) ;
return;
}
if ( ! F_37 ( V_110 , & V_12 -> V_111 ) ) {
F_36 ( & V_107 -> V_109 ) ;
F_25 ( L_40 , V_12 ) ;
return;
}
if ( F_37 ( V_112 , & V_12 -> V_111 ) ) {
F_36 ( & V_107 -> V_109 ) ;
F_25 ( L_41 , V_12 ) ;
return;
}
if ( F_38 ( V_113 , & V_12 -> V_111 ) ) {
F_36 ( & V_107 -> V_109 ) ;
F_25 ( L_42 , V_12 ) ;
return;
}
V_92 = F_39 ( & V_12 -> V_114 , 0 ) ;
if ( ! V_92 ) {
F_25 ( L_43
L_44 ) ;
}
F_36 ( & V_107 -> V_109 ) ;
}
static void F_40 ( struct V_11 * V_12 )
{
struct V_106 * V_107 ;
if ( ! V_12 -> V_106 )
return;
V_107 = V_12 -> V_106 -> V_107 ;
F_25 ( L_45 , V_12 ) ;
F_35 ( & V_107 -> V_109 ) ;
V_107 -> V_108 = V_12 ;
V_12 -> V_115 = V_107 -> V_116 ;
V_12 -> V_117 = V_107 -> V_118 ;
V_107 -> V_116 = F_34 ;
V_107 -> V_118 = V_119 ;
F_36 ( & V_107 -> V_109 ) ;
V_107 -> V_120 = V_121 * V_122 ;
V_107 -> V_123 = V_121 * V_122 ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_106 * V_107 ;
if ( ! V_12 -> V_106 )
return;
V_107 = V_12 -> V_106 -> V_107 ;
F_25 ( L_46 , V_12 ) ;
F_35 ( & V_107 -> V_109 ) ;
if ( ! V_107 -> V_108 ) {
F_36 ( & V_107 -> V_109 ) ;
return;
}
V_107 -> V_108 = NULL ;
V_107 -> V_116 = V_12 -> V_115 ;
V_107 -> V_118 = V_12 -> V_117 ;
F_36 ( & V_107 -> V_109 ) ;
V_107 -> V_120 = V_124 ;
V_107 -> V_123 = V_124 ;
}
static bool F_42 ( struct V_106 * V_107 )
{
if ( V_107 -> V_125 == V_126 || V_107 -> V_125 == V_127 ) {
F_25 ( L_47
L_48 ) ;
return false ;
}
return true ;
}
static void F_43 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
struct V_128 * V_129 = V_40 -> V_129 ;
bool V_130 = V_40 -> V_130 ;
F_10 ( V_12 ) ;
F_44 ( V_12 ) ;
F_45 ( V_12 , V_129 , V_130 , true ) ;
}
static void F_46 ( unsigned long V_131 )
{
struct V_11 * V_12 = (struct V_11 * ) V_131 ;
F_25 ( L_49 ) ;
if ( V_12 -> V_132 ) {
F_25 ( L_50 ,
V_12 -> V_132 -> V_133 , V_12 -> V_132 -> V_134 ) ;
F_28 ( V_100 , V_12 -> V_132 , 1 ) ;
}
}
static void F_47 ( struct V_135 * V_136 )
{
struct V_11 * V_12 = F_6 ( V_136 ,
struct V_11 , V_114 . V_136 ) ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_128 * V_129 = V_40 -> V_129 ;
struct V_22 * V_137 = V_12 -> V_137 ;
struct V_138 * V_139 = V_12 -> V_139 ;
struct V_140 V_141 ;
int V_92 , V_130 = V_40 -> V_130 ;
bool V_142 ;
F_25 ( L_51 ,
V_12 , V_143 -> V_133 , V_143 -> V_134 ) ;
F_30 ( & V_137 -> V_144 ) ;
V_142 = ( V_137 -> V_145 == V_146 ) ;
F_33 ( & V_137 -> V_144 ) ;
if ( ! V_142 ) {
F_25 ( L_52 ) ;
F_41 ( V_12 ) ;
F_43 ( V_12 , V_40 ) ;
F_48 ( V_129 , V_137 , V_139 ) ;
return;
}
if ( V_12 -> V_106 ) {
struct V_106 * V_107 = V_12 -> V_106 -> V_107 ;
F_49 ( & V_107 -> V_109 ) ;
V_142 = F_42 ( V_107 ) ;
F_50 ( & V_107 -> V_109 ) ;
if ( ! V_142 ) {
F_25 ( L_53 ) ;
F_41 ( V_12 ) ;
F_43 ( V_12 , V_40 ) ;
F_48 ( V_129 , V_137 , V_139 ) ;
return;
}
}
V_12 -> V_132 = V_143 ;
F_51 ( V_100 ) ;
F_52 ( & V_141 ) ;
V_141 . V_147 = ( F_53 () + V_121 * V_122 ) ;
V_141 . V_131 = ( unsigned long ) V_12 ;
V_141 . V_148 = F_46 ;
F_54 ( & V_141 ) ;
F_25 ( L_54 , V_143 -> V_133 , V_143 -> V_134 ) ;
V_92 = V_12 -> V_95 -> V_149 ( V_12 , V_40 ) ;
F_55 ( & V_141 ) ;
F_56 ( V_143 ) ;
V_12 -> V_132 = NULL ;
if ( V_92 < 0 ) {
F_41 ( V_12 ) ;
F_43 ( V_12 , V_40 ) ;
F_48 ( V_129 , V_137 , V_139 ) ;
return;
}
F_25 ( L_55 ,
V_12 , V_143 -> V_133 , V_143 -> V_134 ) ;
V_92 = F_57 ( V_12 , V_40 ) ;
if ( V_92 < 0 ) {
F_41 ( V_12 ) ;
F_43 ( V_12 , V_40 ) ;
F_48 ( V_129 , V_137 , V_139 ) ;
} else if ( ! V_92 ) {
if ( V_12 -> V_106 ) {
struct V_106 * V_107 = V_12 -> V_106 -> V_107 ;
F_35 ( & V_107 -> V_109 ) ;
F_58 ( V_113 , & V_12 -> V_111 ) ;
F_36 ( & V_107 -> V_109 ) ;
}
} else if ( V_92 == 1 ) {
F_44 ( V_12 ) ;
F_59 ( V_129 , V_12 , V_130 ) ;
F_48 ( V_129 , V_137 , V_139 ) ;
}
}
static void F_60 ( struct V_135 * V_136 )
{
struct V_11 * V_12 = F_6 ( V_136 ,
struct V_11 , V_150 . V_136 ) ;
struct V_106 * V_107 = V_12 -> V_106 -> V_107 ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_128 * V_129 = V_40 -> V_129 ;
struct V_22 * V_137 = V_12 -> V_137 ;
struct V_138 * V_139 = V_12 -> V_139 ;
F_25 ( L_56 ) ;
F_61 ( & V_12 -> V_114 ) ;
V_12 -> V_117 ( V_107 ) ;
F_41 ( V_12 ) ;
F_43 ( V_12 , V_40 ) ;
F_48 ( V_129 , V_137 , V_139 ) ;
F_25 ( L_57 ) ;
}
static void V_119 ( struct V_106 * V_107 )
{
struct V_11 * V_12 ;
void (* V_117)( struct V_106 * );
bool V_142 ;
F_25 ( L_58 ) ;
F_35 ( & V_107 -> V_109 ) ;
V_12 = V_107 -> V_108 ;
if ( ! V_12 ) {
F_36 ( & V_107 -> V_109 ) ;
return;
}
V_117 = V_12 -> V_117 ;
if ( ! F_37 ( V_110 , & V_12 -> V_111 ) ) {
F_25 ( L_59 ,
V_12 ) ;
F_36 ( & V_107 -> V_109 ) ;
V_117 ( V_107 ) ;
return;
}
if ( F_37 ( V_113 , & V_12 -> V_111 ) ) {
F_25 ( L_60
L_61 , V_12 ) ;
F_36 ( & V_107 -> V_109 ) ;
V_117 ( V_107 ) ;
return;
}
if ( F_38 ( V_112 , & V_12 -> V_111 ) ) {
F_25 ( L_62 ,
V_12 ) ;
F_36 ( & V_107 -> V_109 ) ;
V_117 ( V_107 ) ;
return;
}
V_142 = F_42 ( V_107 ) ;
F_36 ( & V_107 -> V_109 ) ;
F_25 ( L_63 , V_142 ) ;
if ( ! V_142 ) {
F_25 ( L_64 ) ;
F_39 ( & V_12 -> V_150 , 0 ) ;
return;
}
V_117 ( V_107 ) ;
}
static int F_62 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_151 )
return 0 ;
V_40 -> V_151 = 1 ;
if ( ! V_40 -> V_83 )
return F_63 ( V_12 ) ;
else
return F_64 ( V_12 , V_40 -> V_152 ,
V_40 -> V_153 ) ;
}
static int F_65 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_154 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_66 = F_66 ( V_155 , V_12 -> V_156 ) ;
if ( ! V_66 )
return - 1 ;
V_154 = F_5 (
V_12 ,
V_40 -> V_157 ,
V_40 -> V_158 ,
V_43 ,
& V_40 -> V_82 ,
V_66 -> V_71 ) ;
switch ( V_154 ) {
case 0 :
F_25 ( L_65
L_66 ) ;
break;
case 1 :
F_25 ( L_67
L_68 ) ;
V_40 -> V_159 = 1 ;
if ( ( V_45 -> V_53 & V_160 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= ( V_160 |
V_55 ) ;
V_40 -> V_56 = 1 ;
}
return F_62 (
V_12 , V_40 ) ;
case 2 :
F_4 ( L_69
L_70 ) ;
F_14 ( V_12 , V_51 ,
V_161 ) ;
return - 1 ;
default:
F_4 ( L_71
L_72 , V_154 ) ;
F_14 ( V_12 , V_93 ,
V_162 ) ;
return - 1 ;
}
return 0 ;
}
static int F_67 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_163 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_66 = F_66 ( V_155 , V_12 -> V_156 ) ;
if ( ! V_66 )
return - 1 ;
V_163 = F_68 (
V_164 | V_165 ,
V_166 | V_167 ,
V_40 -> V_157 ,
V_43 ,
V_12 ) ;
if ( V_163 < 0 )
return - 1 ;
if ( V_163 > 0 ) {
if ( V_40 -> V_159 ) {
F_4 ( L_73
L_74
L_75 , V_66 -> V_71 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
goto V_168;
} else if ( ! V_43 ) {
F_4 ( L_76
L_77 ) ;
F_14 ( V_12 , V_51 ,
V_161 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_17 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_163 = F_69 (
V_164 | V_165 ,
V_169 ,
V_40 -> V_158 ,
& V_40 -> V_82 ,
V_12 -> V_156 ) ;
if ( V_163 < 0 )
return - 1 ;
if ( ! F_70 ( V_12 -> V_156 ) ) {
if ( V_12 -> V_137 -> V_170 . V_171 &&
! strncmp ( V_66 -> V_71 , V_37 , 4 ) ) {
F_4 ( L_78
L_79
L_80 ) ;
F_14 ( V_12 , V_51 ,
V_161 ) ;
return - 1 ;
}
if ( V_12 -> V_137 -> V_170 . V_171 &&
! V_40 -> V_159 )
return 0 ;
if ( strncmp ( V_66 -> V_71 , V_37 , 4 ) && ! V_40 -> V_159 )
return 0 ;
if ( ( V_45 -> V_53 & V_160 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= V_160 |
V_55 ;
V_40 -> V_56 = 1 ;
}
}
return 0 ;
V_168:
return F_65 ( V_12 , V_40 ) ;
}
static int F_71 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_163 ;
T_1 V_43 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_163 = F_68 (
V_172 | V_165 ,
V_166 | V_167 ,
V_40 -> V_157 ,
V_43 ,
V_12 ) ;
if ( V_163 < 0 ) {
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_17 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( F_62 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_163 = F_69 (
V_172 | V_165 ,
V_169 ,
V_40 -> V_158 ,
& V_40 -> V_82 ,
V_12 -> V_156 ) ;
if ( V_163 < 0 ) {
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ! V_40 -> V_159 &&
V_12 -> V_137 -> V_170 . V_171 ) {
F_4 ( L_81
L_82
L_83 ) ;
F_14 ( V_12 , V_51 ,
V_161 ) ;
return - 1 ;
}
if ( ! F_70 ( V_12 -> V_156 ) )
if ( ( V_45 -> V_53 & V_173 ) &&
( V_45 -> V_53 & V_55 ) )
V_79 -> V_53 |= V_173 |
V_55 ;
return 0 ;
}
static int F_57 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_174 = 0 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
while ( 1 ) {
if ( ++ V_174 > V_175 ) {
F_4 ( L_84 ) ;
F_14 ( V_12 , V_93 ,
V_162 ) ;
return - 1 ;
}
switch ( F_15 ( V_45 -> V_53 ) ) {
case 0 :
V_79 -> V_53 &= ~ V_176 ;
if ( F_67 ( V_12 , V_40 ) < 0 )
return - 1 ;
break;
case 1 :
V_79 -> V_53 |= V_177 ;
if ( F_71 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_40 -> V_83 = V_12 -> V_17 -> V_83 ;
V_40 -> V_91 = 1 ;
F_41 ( V_12 ) ;
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
V_79 -> V_53 &= ~ V_178 ;
}
break;
}
if ( V_12 -> V_106 ) {
struct V_106 * V_107 = V_12 -> V_106 -> V_107 ;
bool V_142 ;
F_49 ( & V_107 -> V_109 ) ;
V_142 = F_42 ( V_107 ) ;
F_50 ( & V_107 -> V_109 ) ;
if ( ! V_142 ) {
F_25 ( L_87
L_61 , V_12 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_72 (
char * V_179 )
{
char * V_180 ;
T_1 V_181 = strlen ( V_179 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_181 ; V_3 ++ ) {
V_180 = & V_179 [ V_3 ] ;
if ( ! isupper ( * V_180 ) )
continue;
* V_180 = tolower ( * V_180 ) ;
}
}
int F_73 (
struct V_128 * V_129 ,
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
char * V_182 = NULL , * V_183 = NULL , * V_184 = NULL ;
char * V_185 , * V_186 = NULL , * V_187 = NULL , * V_188 , * V_71 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_189 * V_190 ;
struct V_138 * V_139 = NULL ;
struct V_44 * V_45 ;
struct V_24 * V_25 ;
T_1 V_43 , V_191 = 0 ;
int V_192 = 0 , V_163 = 0 , V_193 , V_194 ;
F_74 ( & V_12 -> V_114 , F_47 ) ;
F_74 ( & V_12 -> V_150 , F_60 ) ;
F_40 ( V_12 ) ;
V_40 -> V_129 = V_129 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_185 = F_75 ( V_43 + 1 , V_195 ) ;
if ( ! V_185 ) {
F_4 ( L_88 ) ;
return - 1 ;
}
memcpy ( V_185 , V_40 -> V_157 , V_43 ) ;
V_185 [ V_43 ] = '\0' ;
V_186 = V_185 ;
V_187 = ( V_186 + V_43 ) ;
while ( V_186 < V_187 ) {
if ( F_76 ( V_186 , & V_188 , & V_71 ) < 0 ) {
V_163 = - 1 ;
goto V_196;
}
if ( ! strncmp ( V_188 , L_89 , 13 ) )
V_182 = V_71 ;
else if ( ! strncmp ( V_188 , L_90 , 11 ) )
V_183 = V_71 ;
else if ( ! strncmp ( V_188 , L_91 , 10 ) )
V_184 = V_71 ;
V_186 += strlen ( V_188 ) + strlen ( V_71 ) + 2 ;
}
if ( ! V_182 ) {
F_4 ( L_30
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_163 = - 1 ;
goto V_196;
}
F_72 ( V_182 ) ;
if ( ! V_183 ) {
if ( ! V_40 -> V_74 )
goto V_197;
F_4 ( L_28
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_163 = - 1 ;
goto V_196;
}
V_192 = strncmp ( V_183 , V_72 , 9 ) ;
if ( ! V_192 ) {
V_12 -> V_137 = V_34 -> V_198 ;
if ( ! V_40 -> V_74 )
goto V_197;
V_17 -> V_26 -> V_27 = 1 ;
if ( F_77 ( V_12 ) < 0 ) {
F_4 ( L_92 ) ;
V_163 = - 1 ;
goto V_196;
}
if ( F_78 ( V_129 , V_12 -> V_137 ) < 0 ) {
F_14 ( V_12 , V_93 ,
V_199 ) ;
V_163 = - 1 ;
goto V_196;
}
V_163 = 0 ;
goto V_200;
}
V_197:
if ( ! V_184 ) {
F_4 ( L_93
L_94
L_95 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_163 = - 1 ;
goto V_196;
}
V_190 = F_79 ( V_184 ) ;
if ( ! V_190 ) {
F_4 ( L_96
L_97 , V_184 ) ;
F_14 ( V_12 , V_93 ,
V_199 ) ;
V_163 = - 1 ;
goto V_196;
}
F_25 ( L_98 , V_190 -> V_190 ) ;
V_12 -> V_137 = F_80 ( V_190 , V_129 , & V_139 ) ;
if ( ! V_12 -> V_137 ) {
F_4 ( L_99
L_100 , V_190 -> V_190 ) ;
F_81 ( V_190 ) ;
F_14 ( V_12 , V_93 ,
V_199 ) ;
V_163 = - 1 ;
goto V_196;
}
V_12 -> V_139 = V_139 ;
F_25 ( L_101 , V_12 -> V_137 -> V_201 ) ;
if ( F_77 ( V_12 ) < 0 ) {
F_4 ( L_92 ) ;
F_82 ( & V_139 -> V_202 , V_203 ) ;
F_81 ( V_190 ) ;
V_12 -> V_137 = NULL ;
V_163 = - 1 ;
goto V_196;
}
if ( F_78 ( V_129 , V_12 -> V_137 ) < 0 ) {
F_82 ( & V_139 -> V_202 , V_203 ) ;
F_81 ( V_190 ) ;
F_14 ( V_12 , V_93 ,
V_199 ) ;
V_12 -> V_137 = NULL ;
V_163 = - 1 ;
goto V_196;
}
if ( ! V_40 -> V_74 ) {
V_163 = 0 ;
goto V_196;
}
V_17 -> V_26 -> V_27 = 0 ;
V_17 -> V_28 -> V_24 = F_83 (
& V_12 -> V_137 -> V_31 , V_182 ) ;
if ( ! V_17 -> V_28 -> V_24 ) {
F_4 ( L_102
L_103 ,
V_182 , V_12 -> V_137 -> V_201 ) ;
F_14 ( V_12 , V_51 ,
V_204 ) ;
V_163 = - 1 ;
goto V_196;
}
V_25 = V_17 -> V_28 -> V_24 ;
V_191 = V_25 -> V_191 ;
V_200:
V_193 = F_84 ( T_1 , V_205 , V_191 ) ;
V_193 = ( V_193 * 2 ) + V_206 ;
V_194 = sizeof( struct V_207 ) + V_12 -> V_95 -> V_208 ;
V_163 = F_85 ( V_17 -> V_28 , V_193 , V_194 ) ;
if ( V_163 < 0 ) {
F_14 ( V_12 , V_93 ,
V_94 ) ;
V_163 = - 1 ;
}
V_196:
F_11 ( V_185 ) ;
return V_163 ;
}
int F_86 (
struct V_39 * V_40 ,
struct V_11 * V_12 )
{
int V_163 ;
V_163 = F_57 ( V_12 , V_40 ) ;
if ( ! V_163 ) {
if ( V_12 -> V_106 ) {
struct V_106 * V_107 = V_12 -> V_106 -> V_107 ;
F_35 ( & V_107 -> V_109 ) ;
F_87 ( V_110 , & V_12 -> V_111 ) ;
F_36 ( & V_107 -> V_109 ) ;
}
} else if ( V_163 < 0 ) {
F_61 ( & V_12 -> V_114 ) ;
F_61 ( & V_12 -> V_150 ) ;
F_41 ( V_12 ) ;
F_10 ( V_12 ) ;
}
if ( V_163 != 0 )
F_44 ( V_12 ) ;
return V_163 ;
}
void F_44 ( struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_209 ;
if ( ! V_40 )
return;
F_11 ( V_40 -> V_157 ) ;
F_11 ( V_40 -> V_158 ) ;
F_11 ( V_40 ) ;
V_12 -> V_209 = NULL ;
}
