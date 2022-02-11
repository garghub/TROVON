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
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_79 -> V_48 = V_81 ;
F_21 ( V_79 -> V_47 , V_40 -> V_82 ) ;
memcpy ( V_79 -> V_61 , V_40 -> V_61 , 6 ) ;
V_79 -> V_83 = F_22 ( V_40 -> V_83 ) ;
V_79 -> V_62 = V_40 -> V_63 ;
V_79 -> V_84 = F_23 ( V_12 -> V_85 ++ ) ;
V_79 -> V_86 = F_23 ( V_12 -> V_17 -> V_87 ) ;
V_79 -> V_88 = F_23 ( V_12 -> V_17 -> V_89 ) ;
F_24 ( L_36
L_37
L_38 , V_79 -> V_53 , ( V_90 T_1 ) V_79 -> V_62 ,
F_25 ( V_79 -> V_86 ) , F_25 ( V_79 -> V_88 ) ,
F_25 ( V_79 -> V_84 ) , V_40 -> V_82 ) ;
V_77 = ( ( - V_40 -> V_82 ) & 3 ) ;
if ( V_12 -> V_91 -> V_92 ( V_12 , V_40 ,
V_40 -> V_82 + V_77 ) < 0 )
return - 1 ;
V_40 -> V_82 = 0 ;
F_26 ( & V_17 -> V_93 ) ;
V_79 -> V_86 = F_23 ( V_17 -> V_87 ) ;
V_79 -> V_88 = F_23 ( V_17 -> V_89 ) ;
F_27 ( & V_17 -> V_93 ) ;
return 0 ;
}
static void F_28 ( struct V_94 * V_95 , int V_96 )
{
struct V_11 * V_12 = V_95 -> V_97 ;
bool V_98 ;
F_24 ( L_39 , V_12 ) ;
F_29 ( & V_95 -> V_99 ) ;
if ( ! V_95 -> V_97 ) {
F_30 ( & V_95 -> V_99 ) ;
return;
}
if ( ! F_31 ( V_100 , & V_12 -> V_101 ) ) {
F_30 ( & V_95 -> V_99 ) ;
F_24 ( L_40 , V_12 ) ;
return;
}
if ( F_31 ( V_102 , & V_12 -> V_101 ) ) {
F_30 ( & V_95 -> V_99 ) ;
F_24 ( L_41 , V_12 ) ;
return;
}
if ( F_32 ( V_103 , & V_12 -> V_101 ) ) {
F_30 ( & V_95 -> V_99 ) ;
F_24 ( L_42 , V_12 ) ;
return;
}
V_98 = F_33 ( & V_12 -> V_104 , 0 ) ;
if ( V_98 == false ) {
F_24 ( L_43
L_44 ) ;
}
F_30 ( & V_95 -> V_99 ) ;
}
static void F_34 ( struct V_11 * V_12 )
{
struct V_94 * V_95 ;
if ( ! V_12 -> V_94 )
return;
V_95 = V_12 -> V_94 -> V_95 ;
F_24 ( L_45 , V_12 ) ;
F_29 ( & V_95 -> V_99 ) ;
V_95 -> V_97 = V_12 ;
V_12 -> V_105 = V_95 -> V_106 ;
V_12 -> V_107 = V_95 -> V_108 ;
V_95 -> V_106 = F_28 ;
V_95 -> V_108 = V_109 ;
F_30 ( & V_95 -> V_99 ) ;
V_95 -> V_110 = V_111 * V_112 ;
V_95 -> V_113 = V_111 * V_112 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_94 * V_95 ;
if ( ! V_12 -> V_94 )
return;
V_95 = V_12 -> V_94 -> V_95 ;
F_24 ( L_46 , V_12 ) ;
F_29 ( & V_95 -> V_99 ) ;
if ( ! V_95 -> V_97 ) {
F_30 ( & V_95 -> V_99 ) ;
return;
}
V_95 -> V_97 = NULL ;
V_95 -> V_106 = V_12 -> V_105 ;
V_95 -> V_108 = V_12 -> V_107 ;
F_30 ( & V_95 -> V_99 ) ;
V_95 -> V_110 = V_114 ;
V_95 -> V_113 = V_114 ;
}
static bool F_36 ( struct V_94 * V_95 )
{
if ( V_95 -> V_115 == V_116 || V_95 -> V_115 == V_117 ) {
F_24 ( L_47
L_48 ) ;
return false ;
}
return true ;
}
static void F_37 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
struct V_118 * V_119 = V_40 -> V_119 ;
bool V_120 = V_40 -> V_120 ;
F_10 ( V_12 ) ;
F_38 ( V_12 ) ;
F_39 ( V_12 , V_119 , V_120 , true ) ;
}
static void F_40 ( unsigned long V_121 )
{
struct V_11 * V_12 = (struct V_11 * ) V_121 ;
F_24 ( L_49 ) ;
if ( V_12 -> V_122 ) {
F_24 ( L_50 ,
V_12 -> V_122 -> V_123 , V_12 -> V_122 -> V_124 ) ;
F_41 ( V_125 , V_12 -> V_122 , 1 ) ;
}
}
static void F_42 ( struct V_126 * V_127 )
{
struct V_11 * V_12 = F_6 ( V_127 ,
struct V_11 , V_104 . V_127 ) ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_118 * V_119 = V_40 -> V_119 ;
struct V_22 * V_128 = V_12 -> V_128 ;
struct V_129 * V_130 = V_12 -> V_130 ;
struct V_131 V_132 ;
int V_98 , V_120 = V_40 -> V_120 ;
bool V_133 ;
F_24 ( L_51 ,
V_12 , V_134 -> V_123 , V_134 -> V_124 ) ;
F_43 ( & V_128 -> V_135 ) ;
V_133 = ( V_128 -> V_136 == V_137 ) ;
F_44 ( & V_128 -> V_135 ) ;
if ( V_133 == false ) {
F_24 ( L_52 ) ;
F_35 ( V_12 ) ;
F_37 ( V_12 , V_40 ) ;
F_45 ( V_119 , V_128 , V_130 ) ;
return;
}
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
F_46 ( & V_95 -> V_99 ) ;
V_133 = F_36 ( V_95 ) ;
F_47 ( & V_95 -> V_99 ) ;
if ( V_133 == false ) {
F_24 ( L_53 ) ;
F_35 ( V_12 ) ;
F_37 ( V_12 , V_40 ) ;
F_45 ( V_119 , V_128 , V_130 ) ;
return;
}
}
V_12 -> V_122 = V_134 ;
F_48 ( V_125 ) ;
F_49 ( & V_132 ) ;
V_132 . V_138 = ( F_50 () + V_111 * V_112 ) ;
V_132 . V_121 = ( unsigned long ) V_12 ;
V_132 . V_139 = F_40 ;
F_51 ( & V_132 ) ;
F_24 ( L_54 , V_134 -> V_123 , V_134 -> V_124 ) ;
V_98 = V_12 -> V_91 -> V_140 ( V_12 , V_40 ) ;
F_52 ( & V_132 ) ;
F_53 ( V_134 ) ;
V_12 -> V_122 = NULL ;
if ( V_98 < 0 ) {
F_35 ( V_12 ) ;
F_37 ( V_12 , V_40 ) ;
F_45 ( V_119 , V_128 , V_130 ) ;
return;
}
F_24 ( L_55 ,
V_12 , V_134 -> V_123 , V_134 -> V_124 ) ;
V_98 = F_54 ( V_12 , V_40 ) ;
if ( V_98 < 0 ) {
F_35 ( V_12 ) ;
F_37 ( V_12 , V_40 ) ;
F_45 ( V_119 , V_128 , V_130 ) ;
} else if ( ! V_98 ) {
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
F_29 ( & V_95 -> V_99 ) ;
F_55 ( V_103 , & V_12 -> V_101 ) ;
F_30 ( & V_95 -> V_99 ) ;
}
} else if ( V_98 == 1 ) {
F_38 ( V_12 ) ;
F_56 ( V_119 , V_12 , V_120 ) ;
F_45 ( V_119 , V_128 , V_130 ) ;
}
}
static void F_57 ( struct V_126 * V_127 )
{
struct V_11 * V_12 = F_6 ( V_127 ,
struct V_11 , V_141 . V_127 ) ;
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_118 * V_119 = V_40 -> V_119 ;
struct V_22 * V_128 = V_12 -> V_128 ;
struct V_129 * V_130 = V_12 -> V_130 ;
F_24 ( L_56 ) ;
F_58 ( & V_12 -> V_104 ) ;
V_12 -> V_107 ( V_95 ) ;
F_35 ( V_12 ) ;
F_37 ( V_12 , V_40 ) ;
F_45 ( V_119 , V_128 , V_130 ) ;
F_24 ( L_57 ) ;
}
static void V_109 ( struct V_94 * V_95 )
{
struct V_11 * V_12 ;
void (* V_107)( struct V_94 * );
bool V_133 ;
F_24 ( L_58 ) ;
F_29 ( & V_95 -> V_99 ) ;
V_12 = V_95 -> V_97 ;
if ( ! V_12 ) {
F_30 ( & V_95 -> V_99 ) ;
return;
}
V_107 = V_12 -> V_107 ;
if ( ! F_31 ( V_100 , & V_12 -> V_101 ) ) {
F_24 ( L_59 ,
V_12 ) ;
F_30 ( & V_95 -> V_99 ) ;
V_107 ( V_95 ) ;
return;
}
if ( F_31 ( V_103 , & V_12 -> V_101 ) ) {
F_24 ( L_60
L_61 , V_12 ) ;
F_30 ( & V_95 -> V_99 ) ;
V_107 ( V_95 ) ;
return;
}
if ( F_32 ( V_102 , & V_12 -> V_101 ) ) {
F_24 ( L_62 ,
V_12 ) ;
F_30 ( & V_95 -> V_99 ) ;
V_107 ( V_95 ) ;
return;
}
V_133 = F_36 ( V_95 ) ;
F_30 ( & V_95 -> V_99 ) ;
F_24 ( L_63 , V_133 ) ;
if ( ! V_133 ) {
F_24 ( L_64 ) ;
F_33 ( & V_12 -> V_141 , 0 ) ;
return;
}
V_107 ( V_95 ) ;
}
static int F_59 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_142 )
return 0 ;
V_40 -> V_142 = 1 ;
if ( ! V_40 -> V_83 )
return F_60 ( V_12 ) ;
else
return F_61 ( V_12 , V_40 -> V_143 ,
V_40 -> V_144 ) ;
}
static int F_62 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_145 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_66 = F_63 ( V_146 , V_12 -> V_147 ) ;
if ( ! V_66 )
return - 1 ;
V_145 = F_5 (
V_12 ,
V_40 -> V_148 ,
V_40 -> V_149 ,
V_43 ,
& V_40 -> V_82 ,
V_66 -> V_71 ) ;
switch ( V_145 ) {
case 0 :
F_24 ( L_65
L_66 ) ;
break;
case 1 :
F_24 ( L_67
L_68 ) ;
V_40 -> V_150 = 1 ;
if ( ( V_45 -> V_53 & V_151 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= ( V_151 |
V_55 ) ;
V_40 -> V_56 = 1 ;
}
return F_59 (
V_12 , V_40 ) ;
case 2 :
F_4 ( L_69
L_70 ) ;
F_14 ( V_12 , V_51 ,
V_152 ) ;
return - 1 ;
default:
F_4 ( L_71
L_72 , V_145 ) ;
F_14 ( V_12 , V_153 ,
V_154 ) ;
return - 1 ;
}
return 0 ;
}
static int F_64 (
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
V_66 = F_63 ( V_146 , V_12 -> V_147 ) ;
if ( ! V_66 )
return - 1 ;
V_155 = F_65 (
V_156 | V_157 ,
V_158 | V_159 ,
V_40 -> V_148 ,
V_43 ,
V_12 ) ;
if ( V_155 < 0 )
return - 1 ;
if ( V_155 > 0 ) {
if ( V_40 -> V_150 ) {
F_4 ( L_73
L_74
L_75 , V_66 -> V_71 ) ;
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
goto V_160;
}
if ( V_40 -> V_67 )
if ( F_17 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_155 = F_66 (
V_156 | V_157 ,
V_161 ,
V_40 -> V_149 ,
& V_40 -> V_82 ,
V_12 -> V_147 ) ;
if ( V_155 < 0 )
return - 1 ;
if ( ! F_67 ( V_12 -> V_147 ) ) {
if ( V_12 -> V_128 -> V_162 . V_163 &&
! strncmp ( V_66 -> V_71 , V_37 , 4 ) ) {
F_4 ( L_76
L_77
L_78 ) ;
F_14 ( V_12 , V_51 ,
V_152 ) ;
return - 1 ;
}
if ( V_12 -> V_128 -> V_162 . V_163 &&
! V_40 -> V_150 )
return 0 ;
if ( strncmp ( V_66 -> V_71 , V_37 , 4 ) && ! V_40 -> V_150 )
return 0 ;
if ( ( V_45 -> V_53 & V_151 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= V_151 |
V_55 ;
V_40 -> V_56 = 1 ;
}
}
return 0 ;
V_160:
return F_62 ( V_12 , V_40 ) ;
}
static int F_68 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_155 ;
T_1 V_43 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_155 = F_65 (
V_164 | V_157 ,
V_158 | V_159 ,
V_40 -> V_148 ,
V_43 ,
V_12 ) ;
if ( V_155 < 0 ) {
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_17 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( F_59 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_155 = F_66 (
V_164 | V_157 ,
V_161 ,
V_40 -> V_149 ,
& V_40 -> V_82 ,
V_12 -> V_147 ) ;
if ( V_155 < 0 ) {
F_14 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ! V_40 -> V_150 &&
V_12 -> V_128 -> V_162 . V_163 ) {
F_4 ( L_79
L_80
L_81 ) ;
F_14 ( V_12 , V_51 ,
V_152 ) ;
return - 1 ;
}
if ( ! F_67 ( V_12 -> V_147 ) )
if ( ( V_45 -> V_53 & V_165 ) &&
( V_45 -> V_53 & V_55 ) )
V_79 -> V_53 |= V_165 |
V_55 ;
return 0 ;
}
static int F_54 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_166 = 0 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
while ( 1 ) {
if ( ++ V_166 > V_167 ) {
F_4 ( L_82 ) ;
F_14 ( V_12 , V_153 ,
V_154 ) ;
return - 1 ;
}
switch ( F_15 ( V_45 -> V_53 ) ) {
case 0 :
V_79 -> V_53 &= ~ V_168 ;
if ( F_64 ( V_12 , V_40 ) < 0 )
return - 1 ;
break;
case 1 :
V_79 -> V_53 |= V_169 ;
if ( F_68 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_40 -> V_83 = V_12 -> V_17 -> V_83 ;
V_40 -> V_170 = 1 ;
F_35 ( V_12 ) ;
if ( F_20 ( V_12 ,
V_40 ) < 0 )
return - 1 ;
return 1 ;
}
break;
default:
F_4 ( L_83
L_84 ,
F_15 ( V_45 -> V_53 ) ) ;
break;
}
if ( F_20 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_79 -> V_53 &= ~ V_55 ;
V_79 -> V_53 &= ~ V_171 ;
}
break;
}
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
bool V_133 ;
F_46 ( & V_95 -> V_99 ) ;
V_133 = F_36 ( V_95 ) ;
F_47 ( & V_95 -> V_99 ) ;
if ( ! V_133 ) {
F_24 ( L_85
L_61 , V_12 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_69 (
char * V_172 )
{
char * V_173 ;
T_1 V_174 = strlen ( V_172 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_174 ; V_3 ++ ) {
V_173 = & V_172 [ V_3 ] ;
if ( ! isupper ( * V_173 ) )
continue;
* V_173 = tolower ( * V_173 ) ;
}
}
int F_70 (
struct V_118 * V_119 ,
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
char * V_175 = NULL , * V_176 = NULL , * V_177 = NULL ;
char * V_178 , * V_179 = NULL , * V_180 = NULL , * V_181 , * V_71 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_182 * V_183 ;
struct V_129 * V_130 = NULL ;
struct V_44 * V_45 ;
struct V_24 * V_25 ;
T_1 V_43 , V_184 = 0 ;
int V_185 = 0 , V_155 = 0 , V_186 , V_187 ;
F_71 ( & V_12 -> V_104 , F_42 ) ;
F_71 ( & V_12 -> V_141 , F_57 ) ;
F_34 ( V_12 ) ;
V_40 -> V_119 = V_119 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_13 ( V_45 -> V_47 ) ;
V_178 = F_72 ( V_43 + 1 , V_188 ) ;
if ( ! V_178 ) {
F_4 ( L_86 ) ;
return - 1 ;
}
memcpy ( V_178 , V_40 -> V_148 , V_43 ) ;
V_178 [ V_43 ] = '\0' ;
V_179 = V_178 ;
V_180 = ( V_179 + V_43 ) ;
while ( V_179 < V_180 ) {
if ( F_73 ( V_179 , & V_181 , & V_71 ) < 0 ) {
V_155 = - 1 ;
goto V_189;
}
if ( ! strncmp ( V_181 , L_87 , 13 ) )
V_175 = V_71 ;
else if ( ! strncmp ( V_181 , L_88 , 11 ) )
V_176 = V_71 ;
else if ( ! strncmp ( V_181 , L_89 , 10 ) )
V_177 = V_71 ;
V_179 += strlen ( V_181 ) + strlen ( V_71 ) + 2 ;
}
if ( ! V_175 ) {
F_4 ( L_30
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_155 = - 1 ;
goto V_189;
}
F_69 ( V_175 ) ;
if ( ! V_176 ) {
if ( ! V_40 -> V_74 )
goto V_190;
F_4 ( L_28
L_29 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_155 = - 1 ;
goto V_189;
}
V_185 = strncmp ( V_176 , V_72 , 9 ) ;
if ( ! V_185 ) {
V_12 -> V_128 = V_34 -> V_191 ;
if ( ! V_40 -> V_74 )
goto V_190;
V_17 -> V_26 -> V_27 = 1 ;
if ( F_74 ( V_12 ) < 0 ) {
F_4 ( L_90 ) ;
V_155 = - 1 ;
goto V_189;
}
if ( F_75 ( V_119 , V_12 -> V_128 ) < 0 ) {
F_14 ( V_12 , V_153 ,
V_192 ) ;
V_155 = - 1 ;
goto V_189;
}
V_155 = 0 ;
goto V_193;
}
V_190:
if ( ! V_177 ) {
F_4 ( L_91
L_92
L_93 ) ;
F_14 ( V_12 , V_51 ,
V_70 ) ;
V_155 = - 1 ;
goto V_189;
}
V_183 = F_76 ( V_177 ) ;
if ( ! V_183 ) {
F_4 ( L_94
L_95 , V_177 ) ;
F_14 ( V_12 , V_153 ,
V_192 ) ;
V_155 = - 1 ;
goto V_189;
}
F_24 ( L_96 , V_183 -> V_183 ) ;
V_12 -> V_128 = F_77 ( V_183 , V_119 , & V_130 ) ;
if ( ! V_12 -> V_128 ) {
F_4 ( L_97
L_98 , V_183 -> V_183 ) ;
F_78 ( V_183 ) ;
F_14 ( V_12 , V_153 ,
V_192 ) ;
V_155 = - 1 ;
goto V_189;
}
V_12 -> V_130 = V_130 ;
F_24 ( L_99 , V_12 -> V_128 -> V_194 ) ;
if ( F_74 ( V_12 ) < 0 ) {
F_4 ( L_90 ) ;
F_79 ( & V_130 -> V_195 , V_196 ) ;
F_78 ( V_183 ) ;
V_12 -> V_128 = NULL ;
V_155 = - 1 ;
goto V_189;
}
if ( F_75 ( V_119 , V_12 -> V_128 ) < 0 ) {
F_79 ( & V_130 -> V_195 , V_196 ) ;
F_78 ( V_183 ) ;
F_14 ( V_12 , V_153 ,
V_192 ) ;
V_12 -> V_128 = NULL ;
V_155 = - 1 ;
goto V_189;
}
if ( ! V_40 -> V_74 ) {
V_155 = 0 ;
goto V_189;
}
V_17 -> V_26 -> V_27 = 0 ;
V_17 -> V_28 -> V_24 = F_80 (
& V_12 -> V_128 -> V_31 , V_175 ) ;
if ( ! V_17 -> V_28 -> V_24 ) {
F_4 ( L_100
L_101 ,
V_175 , V_12 -> V_128 -> V_194 ) ;
F_14 ( V_12 , V_51 ,
V_197 ) ;
V_155 = - 1 ;
goto V_189;
}
V_25 = V_17 -> V_28 -> V_24 ;
V_184 = V_25 -> V_184 ;
V_193:
V_186 = F_81 ( T_1 , V_198 , V_184 ) ;
V_186 = ( V_186 * 2 ) + V_199 ;
V_187 = sizeof( struct V_200 ) + V_12 -> V_91 -> V_201 ;
V_155 = F_82 ( V_17 -> V_28 , V_186 , V_187 ) ;
if ( V_155 < 0 ) {
F_14 ( V_12 , V_153 ,
V_202 ) ;
V_155 = - 1 ;
}
V_189:
F_11 ( V_178 ) ;
return V_155 ;
}
int F_83 (
struct V_39 * V_40 ,
struct V_11 * V_12 )
{
int V_155 ;
V_155 = F_54 ( V_12 , V_40 ) ;
if ( ! V_155 ) {
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
F_29 ( & V_95 -> V_99 ) ;
F_84 ( V_100 , & V_12 -> V_101 ) ;
F_30 ( & V_95 -> V_99 ) ;
}
} else if ( V_155 < 0 ) {
F_58 ( & V_12 -> V_104 ) ;
F_58 ( & V_12 -> V_141 ) ;
F_35 ( V_12 ) ;
F_10 ( V_12 ) ;
}
if ( V_155 != 0 )
F_38 ( V_12 ) ;
return V_155 ;
}
void F_38 ( struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_203 ;
if ( ! V_40 )
return;
F_11 ( V_40 -> V_148 ) ;
F_11 ( V_40 -> V_149 ) ;
F_11 ( V_40 ) ;
V_12 -> V_203 = NULL ;
}
