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
if ( V_2 > V_6 ) {
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
V_19 = F_7 ( V_21 ) ;
}
} else {
V_19 = & V_33 -> V_34 . V_35 ;
}
if ( strstr ( L_7 , V_15 ) )
strcpy ( V_12 -> V_17 -> V_36 , L_7 ) ;
else
strcpy ( V_12 -> V_17 -> V_36 , V_37 ) ;
if ( strstr ( L_8 , V_15 ) )
return 1 ;
#ifdef F_8
else if ( strstr ( L_9 , V_15 ) )
return F_9 ( V_12 , V_19 , V_4 , V_7 ,
& V_13 , V_14 ) ;
#endif
else if ( strstr ( L_7 , V_15 ) )
return F_10 ( V_12 , V_19 , V_4 , V_7 ,
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
static void F_11 ( struct V_11 * V_12 )
{
F_12 ( V_12 -> V_38 ) ;
}
int F_13 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_41 , V_42 ;
T_1 V_43 ;
struct V_44 * V_45 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
switch ( V_45 -> V_48 & V_49 ) {
case V_50 :
break;
default:
F_4 ( L_13 ,
V_45 -> V_48 & V_49 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_45 -> V_53 & V_54 ) &&
( V_45 -> V_53 & V_55 ) ) {
F_4 ( L_14
L_15 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
V_41 = F_16 ( V_45 -> V_53 ) ;
V_42 = F_17 ( V_45 -> V_53 ) ;
if ( V_41 != V_40 -> V_56 ) {
F_4 ( L_16
L_17 , V_40 -> V_56 ,
V_41 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_42 == 2 ) || ( V_41 >= 2 ) ||
( ( V_45 -> V_53 & V_55 ) &&
( V_42 <= V_41 ) ) ) {
F_4 ( L_18
L_19 , V_41 ,
V_42 , ( V_45 -> V_53 & V_55 ) ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_45 -> V_57 != V_40 -> V_58 ) ||
( V_45 -> V_59 != V_40 -> V_60 ) ) {
F_4 ( L_20
L_21 ,
V_45 -> V_57 , V_45 -> V_59 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( memcmp ( V_45 -> V_61 , V_40 -> V_61 , 6 ) != 0 ) {
F_4 ( L_22
L_23 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_45 -> V_62 != V_40 -> V_63 ) {
F_4 ( L_24
L_25 , V_45 -> V_62 ) ;
F_15 ( V_12 , V_51 ,
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
static int F_18 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
struct V_65 * V_66 = NULL ;
struct V_24 * V_25 ;
V_40 -> V_67 = 0 ;
F_19 (param, &conn->param_list->param_list, p_list) {
if ( ! strncmp ( V_66 -> V_68 , V_69 , 11 ) ) {
if ( ! F_20 ( V_66 ) ) {
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
return - 1 ;
}
if ( ! strncmp ( V_66 -> V_71 , V_72 , 9 ) )
return 0 ;
}
if ( ! strncmp ( V_66 -> V_68 , V_73 , 13 ) ) {
if ( ! F_20 ( V_66 ) ) {
if ( ! V_40 -> V_74 )
continue;
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
return - 1 ;
}
if ( ! V_40 -> V_74 ) {
V_25 = V_12 -> V_17 -> V_28 -> V_24 ;
if ( ! V_25 ) {
F_4 ( L_31
L_32 ) ;
F_15 ( V_12 ,
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
F_15 ( V_12 ,
V_51 ,
V_75 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static int F_21 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
T_1 V_77 = 0 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_79 -> V_48 = V_81 ;
F_22 ( V_79 -> V_47 , V_40 -> V_82 ) ;
memcpy ( V_79 -> V_61 , V_40 -> V_61 , 6 ) ;
V_79 -> V_83 = F_23 ( V_40 -> V_83 ) ;
V_79 -> V_62 = V_40 -> V_63 ;
V_79 -> V_84 = F_24 ( V_12 -> V_85 ++ ) ;
V_79 -> V_86 = F_24 ( V_12 -> V_17 -> V_87 ) ;
V_79 -> V_88 = F_24 ( V_12 -> V_17 -> V_89 ) ;
F_25 ( L_36
L_37
L_38 , V_79 -> V_53 , ( V_90 T_1 ) V_79 -> V_62 ,
F_26 ( V_79 -> V_86 ) , F_26 ( V_79 -> V_88 ) ,
F_26 ( V_79 -> V_84 ) , V_40 -> V_82 ) ;
V_77 = ( ( - V_40 -> V_82 ) & 3 ) ;
if ( V_12 -> V_91 -> V_92 ( V_12 , V_40 ,
V_40 -> V_82 + V_77 ) < 0 )
return - 1 ;
V_40 -> V_82 = 0 ;
F_27 ( & V_17 -> V_93 ) ;
V_79 -> V_86 = F_24 ( V_17 -> V_87 ) ;
V_79 -> V_88 = F_24 ( V_17 -> V_89 ) ;
F_28 ( & V_17 -> V_93 ) ;
return 0 ;
}
static void F_29 ( struct V_94 * V_95 , int V_96 )
{
struct V_11 * V_12 = V_95 -> V_97 ;
bool V_98 ;
F_25 ( L_39 , V_12 ) ;
F_30 ( & V_95 -> V_99 ) ;
if ( ! V_95 -> V_97 ) {
F_31 ( & V_95 -> V_99 ) ;
return;
}
if ( ! F_32 ( V_100 , & V_12 -> V_101 ) ) {
F_31 ( & V_95 -> V_99 ) ;
F_25 ( L_40 , V_12 ) ;
return;
}
if ( F_32 ( V_102 , & V_12 -> V_101 ) ) {
F_31 ( & V_95 -> V_99 ) ;
F_25 ( L_41 , V_12 ) ;
return;
}
if ( F_33 ( V_103 , & V_12 -> V_101 ) ) {
F_31 ( & V_95 -> V_99 ) ;
F_25 ( L_42 , V_12 ) ;
return;
}
V_98 = F_34 ( & V_12 -> V_104 , 0 ) ;
if ( V_98 == false ) {
F_25 ( L_43
L_44 ) ;
}
F_31 ( & V_95 -> V_99 ) ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_94 * V_95 ;
if ( ! V_12 -> V_94 )
return;
V_95 = V_12 -> V_94 -> V_95 ;
F_25 ( L_45 , V_12 ) ;
F_30 ( & V_95 -> V_99 ) ;
V_95 -> V_97 = V_12 ;
V_12 -> V_105 = V_95 -> V_106 ;
V_12 -> V_107 = V_95 -> V_108 ;
V_95 -> V_106 = F_29 ;
V_95 -> V_108 = V_109 ;
F_31 ( & V_95 -> V_99 ) ;
V_95 -> V_110 = V_111 * V_112 ;
V_95 -> V_113 = V_111 * V_112 ;
}
static void F_36 ( struct V_11 * V_12 )
{
struct V_94 * V_95 ;
if ( ! V_12 -> V_94 )
return;
V_95 = V_12 -> V_94 -> V_95 ;
F_25 ( L_46 , V_12 ) ;
F_30 ( & V_95 -> V_99 ) ;
if ( ! V_95 -> V_97 ) {
F_31 ( & V_95 -> V_99 ) ;
return;
}
V_95 -> V_97 = NULL ;
V_95 -> V_106 = V_12 -> V_105 ;
V_95 -> V_108 = V_12 -> V_107 ;
F_31 ( & V_95 -> V_99 ) ;
V_95 -> V_110 = V_114 ;
V_95 -> V_113 = V_114 ;
}
static bool F_37 ( struct V_94 * V_95 )
{
if ( V_95 -> V_115 == V_116 || V_95 -> V_115 == V_117 ) {
F_25 ( L_47
L_48 ) ;
return false ;
}
return true ;
}
static void F_38 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
struct V_118 * V_119 = V_40 -> V_119 ;
bool V_120 = V_40 -> V_120 ;
F_11 ( V_12 ) ;
F_39 ( V_12 ) ;
F_40 ( V_12 , V_119 , V_120 , true ) ;
}
static void F_41 ( unsigned long V_121 )
{
struct V_11 * V_12 = (struct V_11 * ) V_121 ;
F_25 ( L_49 ) ;
if ( V_12 -> V_122 ) {
F_25 ( L_50 ,
V_12 -> V_122 -> V_123 , V_12 -> V_122 -> V_124 ) ;
F_42 ( V_125 , V_12 -> V_122 , 1 ) ;
}
}
static void F_43 ( struct V_126 * V_127 )
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
F_25 ( L_51 ,
V_12 , V_134 -> V_123 , V_134 -> V_124 ) ;
F_44 ( & V_128 -> V_135 ) ;
V_133 = ( V_128 -> V_136 == V_137 ) ;
F_45 ( & V_128 -> V_135 ) ;
if ( V_133 == false ) {
F_25 ( L_52 ) ;
F_36 ( V_12 ) ;
F_38 ( V_12 , V_40 ) ;
F_46 ( V_119 , V_128 , V_130 ) ;
return;
}
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
F_47 ( & V_95 -> V_99 ) ;
V_133 = F_37 ( V_95 ) ;
F_48 ( & V_95 -> V_99 ) ;
if ( V_133 == false ) {
F_25 ( L_53 ) ;
F_36 ( V_12 ) ;
F_38 ( V_12 , V_40 ) ;
F_46 ( V_119 , V_128 , V_130 ) ;
return;
}
}
V_12 -> V_122 = V_134 ;
F_49 ( V_125 ) ;
F_50 ( & V_132 ) ;
V_132 . V_138 = ( F_51 () + V_111 * V_112 ) ;
V_132 . V_121 = ( unsigned long ) V_12 ;
V_132 . V_139 = F_41 ;
F_52 ( & V_132 ) ;
F_25 ( L_54 , V_134 -> V_123 , V_134 -> V_124 ) ;
V_98 = V_12 -> V_91 -> V_140 ( V_12 , V_40 ) ;
F_53 ( & V_132 ) ;
F_54 ( V_134 ) ;
V_12 -> V_122 = NULL ;
if ( V_98 < 0 ) {
F_36 ( V_12 ) ;
F_38 ( V_12 , V_40 ) ;
F_46 ( V_119 , V_128 , V_130 ) ;
return;
}
F_25 ( L_55 ,
V_12 , V_134 -> V_123 , V_134 -> V_124 ) ;
V_98 = F_55 ( V_12 , V_40 ) ;
if ( V_98 < 0 ) {
F_36 ( V_12 ) ;
F_38 ( V_12 , V_40 ) ;
F_46 ( V_119 , V_128 , V_130 ) ;
} else if ( ! V_98 ) {
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
F_30 ( & V_95 -> V_99 ) ;
F_56 ( V_103 , & V_12 -> V_101 ) ;
F_31 ( & V_95 -> V_99 ) ;
}
} else if ( V_98 == 1 ) {
F_39 ( V_12 ) ;
F_57 ( V_119 , V_12 , V_120 ) ;
F_46 ( V_119 , V_128 , V_130 ) ;
}
}
static void F_58 ( struct V_126 * V_127 )
{
struct V_11 * V_12 = F_6 ( V_127 ,
struct V_11 , V_141 . V_127 ) ;
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
struct V_39 * V_40 = V_12 -> V_40 ;
struct V_118 * V_119 = V_40 -> V_119 ;
struct V_22 * V_128 = V_12 -> V_128 ;
struct V_129 * V_130 = V_12 -> V_130 ;
F_25 ( L_56 ) ;
F_59 ( & V_12 -> V_104 ) ;
V_12 -> V_107 ( V_95 ) ;
F_36 ( V_12 ) ;
F_38 ( V_12 , V_40 ) ;
F_46 ( V_119 , V_128 , V_130 ) ;
F_25 ( L_57 ) ;
}
static void V_109 ( struct V_94 * V_95 )
{
struct V_11 * V_12 ;
void (* V_107)( struct V_94 * );
bool V_133 ;
F_25 ( L_58 ) ;
F_30 ( & V_95 -> V_99 ) ;
V_12 = V_95 -> V_97 ;
if ( ! V_12 ) {
F_31 ( & V_95 -> V_99 ) ;
return;
}
V_107 = V_12 -> V_107 ;
if ( ! F_32 ( V_100 , & V_12 -> V_101 ) ) {
F_25 ( L_59 ,
V_12 ) ;
F_31 ( & V_95 -> V_99 ) ;
V_107 ( V_95 ) ;
return;
}
if ( F_32 ( V_103 , & V_12 -> V_101 ) ) {
F_25 ( L_60
L_61 , V_12 ) ;
F_31 ( & V_95 -> V_99 ) ;
V_107 ( V_95 ) ;
return;
}
if ( F_33 ( V_102 , & V_12 -> V_101 ) ) {
F_25 ( L_62 ,
V_12 ) ;
F_31 ( & V_95 -> V_99 ) ;
V_107 ( V_95 ) ;
return;
}
V_133 = F_37 ( V_95 ) ;
F_31 ( & V_95 -> V_99 ) ;
F_25 ( L_63 , V_133 ) ;
if ( ! V_133 ) {
F_25 ( L_64 ) ;
F_34 ( & V_12 -> V_141 , 0 ) ;
return;
}
V_107 ( V_95 ) ;
}
static int F_60 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_142 )
return 0 ;
V_40 -> V_142 = 1 ;
if ( ! V_40 -> V_83 )
return F_61 ( V_12 ) ;
else
return F_62 ( V_12 , V_40 -> V_143 ,
V_40 -> V_144 ) ;
}
static int F_63 (
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
V_43 = F_14 ( V_45 -> V_47 ) ;
V_66 = F_64 ( V_146 , V_12 -> V_147 ) ;
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
F_25 ( L_65
L_66 ) ;
break;
case 1 :
F_25 ( L_67
L_68 ) ;
V_40 -> V_150 = 1 ;
if ( ( V_45 -> V_53 & V_151 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= ( V_151 |
V_55 ) ;
V_40 -> V_56 = 1 ;
}
return F_60 (
V_12 , V_40 ) ;
case 2 :
F_4 ( L_69
L_70 ) ;
F_15 ( V_12 , V_51 ,
V_152 ) ;
return - 1 ;
default:
F_4 ( L_71
L_72 , V_145 ) ;
F_15 ( V_12 , V_153 ,
V_154 ) ;
return - 1 ;
}
return 0 ;
}
static int F_65 (
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
V_43 = F_14 ( V_45 -> V_47 ) ;
V_66 = F_64 ( V_146 , V_12 -> V_147 ) ;
if ( ! V_66 )
return - 1 ;
V_155 = F_66 (
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
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
goto V_160;
}
if ( V_40 -> V_67 )
if ( F_18 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_155 = F_67 (
V_156 | V_157 ,
V_161 ,
V_40 -> V_149 ,
& V_40 -> V_82 ,
V_12 -> V_147 ) ;
if ( V_155 < 0 )
return - 1 ;
if ( ! F_68 ( V_12 -> V_147 ) ) {
if ( F_69 ( F_70 ( V_12 ) ) -> V_162 &&
! strncmp ( V_66 -> V_71 , V_37 , 4 ) ) {
F_4 ( L_76
L_77
L_78 ) ;
F_15 ( V_12 , V_51 ,
V_152 ) ;
return - 1 ;
}
if ( F_69 ( F_70 ( V_12 ) ) -> V_162 &&
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
return F_63 ( V_12 , V_40 ) ;
}
static int F_71 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_155 ;
T_1 V_43 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
V_155 = F_66 (
V_163 | V_157 ,
V_158 | V_159 ,
V_40 -> V_148 ,
V_43 ,
V_12 ) ;
if ( V_155 < 0 ) {
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_18 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( F_60 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_155 = F_67 (
V_163 | V_157 ,
V_161 ,
V_40 -> V_149 ,
& V_40 -> V_82 ,
V_12 -> V_147 ) ;
if ( V_155 < 0 ) {
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ! V_40 -> V_150 &&
F_69 ( F_70 ( V_12 ) ) -> V_162 ) {
F_4 ( L_79
L_80
L_81 ) ;
F_15 ( V_12 , V_51 ,
V_152 ) ;
return - 1 ;
}
if ( ! F_68 ( V_12 -> V_147 ) )
if ( ( V_45 -> V_53 & V_164 ) &&
( V_45 -> V_53 & V_55 ) )
V_79 -> V_53 |= V_164 |
V_55 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_165 = 0 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
while ( 1 ) {
if ( ++ V_165 > V_166 ) {
F_4 ( L_82 ) ;
F_15 ( V_12 , V_153 ,
V_154 ) ;
return - 1 ;
}
switch ( F_16 ( V_45 -> V_53 ) ) {
case 0 :
V_79 -> V_53 &= ~ V_167 ;
if ( F_65 ( V_12 , V_40 ) < 0 )
return - 1 ;
break;
case 1 :
V_79 -> V_53 |= V_168 ;
if ( F_71 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_40 -> V_83 = V_12 -> V_17 -> V_83 ;
V_40 -> V_169 = 1 ;
F_36 ( V_12 ) ;
if ( F_21 ( V_12 ,
V_40 ) < 0 )
return - 1 ;
return 1 ;
}
break;
default:
F_4 ( L_83
L_84 ,
F_16 ( V_45 -> V_53 ) ) ;
break;
}
if ( F_21 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_79 -> V_53 &= ~ V_55 ;
V_79 -> V_53 &= ~ V_170 ;
}
break;
}
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
bool V_133 ;
F_47 ( & V_95 -> V_99 ) ;
V_133 = F_37 ( V_95 ) ;
F_48 ( & V_95 -> V_99 ) ;
if ( ! V_133 ) {
F_25 ( L_85
L_61 , V_12 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_72 (
char * V_171 )
{
char * V_172 ;
T_1 V_173 = strlen ( V_171 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_173 ; V_3 ++ ) {
V_172 = & V_171 [ V_3 ] ;
if ( ! isupper ( * V_172 ) )
continue;
* V_172 = tolower ( * V_172 ) ;
}
}
int F_73 (
struct V_118 * V_119 ,
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
char * V_174 = NULL , * V_175 = NULL , * V_176 = NULL ;
char * V_177 , * V_178 = NULL , * V_179 = NULL , * V_180 , * V_71 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_181 * V_182 ;
struct V_129 * V_130 = NULL ;
struct V_44 * V_45 ;
struct V_24 * V_25 ;
T_1 V_43 , V_183 = 0 ;
int V_184 = 0 , V_155 = 0 , V_185 , V_186 ;
F_74 ( & V_12 -> V_104 , F_43 ) ;
F_74 ( & V_12 -> V_141 , F_58 ) ;
F_35 ( V_12 ) ;
V_40 -> V_119 = V_119 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
V_177 = F_75 ( V_43 + 1 , V_187 ) ;
if ( ! V_177 ) {
F_4 ( L_86 ) ;
return - 1 ;
}
memcpy ( V_177 , V_40 -> V_148 , V_43 ) ;
V_177 [ V_43 ] = '\0' ;
V_178 = V_177 ;
V_179 = ( V_178 + V_43 ) ;
while ( V_178 < V_179 ) {
if ( F_76 ( V_178 , & V_180 , & V_71 ) < 0 ) {
V_155 = - 1 ;
goto V_188;
}
if ( ! strncmp ( V_180 , L_87 , 13 ) )
V_174 = V_71 ;
else if ( ! strncmp ( V_180 , L_88 , 11 ) )
V_175 = V_71 ;
else if ( ! strncmp ( V_180 , L_89 , 10 ) )
V_176 = V_71 ;
V_178 += strlen ( V_180 ) + strlen ( V_71 ) + 2 ;
}
if ( ! V_174 ) {
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
V_155 = - 1 ;
goto V_188;
}
F_72 ( V_174 ) ;
if ( ! V_175 ) {
if ( ! V_40 -> V_74 )
goto V_189;
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
V_155 = - 1 ;
goto V_188;
}
V_184 = strncmp ( V_175 , V_72 , 9 ) ;
if ( ! V_184 ) {
V_12 -> V_128 = V_33 -> V_190 ;
if ( ! V_40 -> V_74 )
goto V_189;
V_17 -> V_26 -> V_27 = 1 ;
if ( F_77 ( V_12 ) < 0 ) {
F_4 ( L_90 ) ;
V_155 = - 1 ;
goto V_188;
}
if ( F_78 ( V_119 , V_12 -> V_128 ) < 0 ) {
F_15 ( V_12 , V_153 ,
V_191 ) ;
V_155 = - 1 ;
goto V_188;
}
V_155 = 0 ;
goto V_192;
}
V_189:
if ( ! V_176 ) {
F_4 ( L_91
L_92
L_93 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
V_155 = - 1 ;
goto V_188;
}
V_182 = F_79 ( V_176 ) ;
if ( ! V_182 ) {
F_4 ( L_94
L_95 , V_176 ) ;
F_15 ( V_12 , V_153 ,
V_191 ) ;
V_155 = - 1 ;
goto V_188;
}
F_25 ( L_96 , V_182 -> V_182 ) ;
V_12 -> V_128 = F_80 ( V_182 , V_119 , & V_130 ) ;
if ( ! V_12 -> V_128 ) {
F_4 ( L_97
L_98 , V_182 -> V_182 ) ;
F_81 ( V_182 ) ;
F_15 ( V_12 , V_153 ,
V_191 ) ;
V_155 = - 1 ;
goto V_188;
}
V_12 -> V_130 = V_130 ;
F_25 ( L_99 , V_12 -> V_128 -> V_193 ) ;
if ( F_77 ( V_12 ) < 0 ) {
F_4 ( L_90 ) ;
F_82 ( & V_130 -> V_194 , V_195 ) ;
F_81 ( V_182 ) ;
V_12 -> V_128 = NULL ;
V_155 = - 1 ;
goto V_188;
}
if ( F_78 ( V_119 , V_12 -> V_128 ) < 0 ) {
F_82 ( & V_130 -> V_194 , V_195 ) ;
F_81 ( V_182 ) ;
F_15 ( V_12 , V_153 ,
V_191 ) ;
V_12 -> V_128 = NULL ;
V_155 = - 1 ;
goto V_188;
}
if ( ! V_40 -> V_74 ) {
V_155 = 0 ;
goto V_188;
}
V_17 -> V_26 -> V_27 = 0 ;
V_17 -> V_28 -> V_24 = F_83 (
& V_12 -> V_128 -> V_31 , V_174 ) ;
if ( ! V_17 -> V_28 -> V_24 ) {
F_4 ( L_100
L_101 ,
V_174 , V_12 -> V_128 -> V_193 ) ;
F_15 ( V_12 , V_51 ,
V_196 ) ;
V_155 = - 1 ;
goto V_188;
}
V_25 = V_17 -> V_28 -> V_24 ;
V_183 = V_25 -> V_183 ;
V_192:
V_185 = F_84 ( T_1 , V_197 , V_183 ) ;
V_185 += ( V_185 / 2 ) + V_198 ;
V_186 = sizeof( struct V_199 ) + V_12 -> V_91 -> V_200 ;
V_155 = F_85 ( V_17 -> V_28 , V_185 , V_186 ) ;
if ( V_155 < 0 ) {
F_15 ( V_12 , V_153 ,
V_201 ) ;
V_155 = - 1 ;
}
V_188:
F_12 ( V_177 ) ;
return V_155 ;
}
int F_86 (
struct V_39 * V_40 ,
struct V_11 * V_12 )
{
int V_155 ;
V_155 = F_55 ( V_12 , V_40 ) ;
if ( ! V_155 ) {
if ( V_12 -> V_94 ) {
struct V_94 * V_95 = V_12 -> V_94 -> V_95 ;
F_30 ( & V_95 -> V_99 ) ;
F_87 ( V_100 , & V_12 -> V_101 ) ;
F_31 ( & V_95 -> V_99 ) ;
}
} else if ( V_155 < 0 ) {
F_59 ( & V_12 -> V_104 ) ;
F_59 ( & V_12 -> V_141 ) ;
F_36 ( V_12 ) ;
F_11 ( V_12 ) ;
}
if ( V_155 != 0 )
F_39 ( V_12 ) ;
return V_155 ;
}
void F_39 ( struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_202 ;
if ( ! V_40 )
return;
F_12 ( V_40 -> V_148 ) ;
F_12 ( V_40 -> V_149 ) ;
F_12 ( V_40 ) ;
V_12 -> V_202 = NULL ;
}
