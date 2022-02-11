static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = F_2 ( V_1 ) ;
if ( V_3 )
return - V_4 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return 0 ;
}
static T_1 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
T_2 V_10 = 0 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_10 ) , & V_10 , sizeof( T_2 ) ) ;
return F_7 ( V_9 , V_13 , L_1 , V_10 ) ;
}
static T_1 F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
T_2 V_10 ;
int V_15 ;
if ( F_9 ( V_9 , 10 , & V_10 ) )
return - V_16 ;
V_15 = F_10
( V_11 ,
F_6 ( struct V_12 ,
V_10 ) ,
& V_10 , sizeof( T_2 ) ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_11 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_17 V_17 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_18 ) , & V_17 ,
sizeof( struct V_17 ) ) ;
return F_7 ( V_9 , V_13 , L_1 ,
V_17 . V_19 ) ;
}
static T_1 F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
int V_20 , V_15 ;
struct V_17 V_17 ;
if ( F_13 ( V_9 , 10 , & V_20 ) )
return - V_16 ;
V_17 . V_19 = V_20 ;
V_15 = F_10
( V_11 ,
F_6 ( struct V_12 ,
V_18 ) , & ( V_17 ) ,
sizeof( struct V_17 ) ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
T_4 error = 0 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_21 ) ,
& error , sizeof( T_4 ) ) ;
return F_7 ( V_9 , V_13 , L_2 , error ) ;
}
static T_1 F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
T_4 error ;
int V_15 ;
if ( F_16 ( V_9 , 10 , & error ) )
return - V_16 ;
V_15 = F_10
( V_11 ,
F_6 ( struct V_12 ,
V_21 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_17 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
T_4 V_22 = 0 ;
F_5
( V_11 ,
F_6 ( struct V_12 ,
V_23 ) ,
& V_22 , sizeof( T_4 ) ) ;
return F_7 ( V_9 , V_13 , L_2 , V_22 ) ;
}
static T_1 F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
T_4 V_22 ;
int V_15 ;
if ( F_16 ( V_9 , 10 , & V_22 ) )
return - V_16 ;
V_15 = F_10
( V_11 ,
F_6 ( struct V_12 ,
V_23 ) ,
& V_22 , sizeof( T_4 ) ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
T_5 V_24 = 0 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_25 ) ,
& V_24 , sizeof( T_5 ) ) ;
return F_7 ( V_9 , V_13 , L_3 , V_24 ) ;
}
static T_1 F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
T_5 V_24 ;
int V_15 ;
if ( F_21 ( V_9 , 10 , & V_24 ) )
return - V_16 ;
V_15 = F_10
( V_11 ,
F_6 ( struct V_12 ,
V_25 ) ,
& V_24 , sizeof( T_5 ) ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_6
F_22 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = NULL ;
if ( ! V_27 )
return V_30 ;
V_29 = (struct V_28 * ) ( V_27 -> V_31 ) ;
return V_29 -> V_32 ;
}
static void
F_23 ( struct V_26 * V_27 ,
enum V_33 V_34 )
{
struct V_28 * V_29 = NULL ;
if ( ! V_27 )
return;
V_29 = (struct V_28 * ) ( V_27 -> V_31 ) ;
switch ( V_34 ) {
case V_35 :
V_27 -> V_36 = V_27 -> V_31 + V_29 -> V_37 ;
V_27 -> V_38 = V_29 -> V_39 ;
break;
case V_40 :
V_27 -> V_36 = V_27 -> V_31 + V_29 -> V_41 ;
V_27 -> V_38 = V_29 -> V_42 ;
break;
case V_43 :
V_27 -> V_36 = V_27 -> V_31 + V_29 -> V_44 ;
V_27 -> V_38 = V_29 -> V_45 ;
break;
case V_46 :
V_27 -> V_36 = V_27 -> V_31 + V_29 -> V_47 ;
V_27 -> V_38 = V_29 -> V_48 ;
break;
default:
break;
}
}
static void F_24 ( struct V_26 * V_27 )
{
if ( ! V_27 )
return;
V_49 -= V_27 -> V_50 ;
F_25 ( V_27 ) ;
}
static void *
F_26 ( struct V_26 * V_27 )
{
T_2 * V_51 ;
unsigned long V_52 ;
int V_53 = - 1 ;
void * V_54 = NULL ;
int V_55 ;
if ( ! V_27 )
return NULL ;
V_51 = V_27 -> V_36 ;
V_52 = V_27 -> V_38 ;
if ( V_52 == 0 )
return NULL ;
if ( ! V_51 )
return NULL ;
for ( V_55 = 0 , V_53 = - 1 ; V_55 < V_52 ; V_55 ++ )
if ( V_51 [ V_55 ] == '\0' ) {
V_53 = V_55 ;
break;
}
if ( V_53 < 0 )
V_53 = V_52 ;
V_54 = F_27 ( V_53 + 1 , V_56 | V_57 ) ;
if ( ! V_54 )
return NULL ;
if ( V_53 > 0 )
memcpy ( V_54 , V_51 , V_53 ) ;
( ( T_2 * ) ( V_54 ) ) [ V_53 ] = '\0' ;
return V_54 ;
}
static int F_28 ( struct V_5 * V_6 , void * V_31 )
{
struct V_58 * V_59 = F_29 ( V_6 ) ;
struct V_60 * V_32 = V_31 ;
T_4 V_61 = V_32 -> V_61 ;
T_4 V_62 = V_32 -> V_62 ;
if ( ( V_59 -> V_63 == V_61 ) &&
( V_59 -> V_64 == V_62 ) )
return 1 ;
return 0 ;
}
struct V_58 * F_30 ( T_4 V_61 , T_4 V_62 ,
struct V_58 * V_65 )
{
struct V_5 * V_6 ;
struct V_5 * V_66 = NULL ;
struct V_58 * V_59 = NULL ;
struct V_60 V_32 = {
. V_61 = V_61 ,
. V_62 = V_62
} ;
if ( V_65 )
V_66 = & V_65 -> V_5 ;
V_6 = F_31 ( & V_67 , V_66 , ( void * ) & V_32 ,
F_28 ) ;
if ( V_6 )
V_59 = F_29 ( V_6 ) ;
return V_59 ;
}
static void
F_32 ( struct V_68 * V_69 ,
struct V_70 * V_71 , int V_72 )
{
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
memcpy ( & V_69 -> V_73 , V_71 , sizeof( struct V_70 ) ) ;
V_69 -> V_73 . V_74 = 0 ;
V_69 -> V_73 . V_75 = 0 ;
V_69 -> V_73 . V_76 = 0 ;
if ( V_72 < 0 ) {
V_69 -> V_73 . V_77 . V_78 = 1 ;
V_69 -> V_73 . V_79 = ( T_4 ) ( - V_72 ) ;
}
}
static int
F_33 ( struct V_70 * V_71 ,
int V_72 ,
enum V_80 V_81 )
{
struct V_68 V_82 ;
F_32 ( & V_82 , V_71 , V_72 ) ;
V_82 . V_83 . V_84 . V_81 = V_81 ;
return F_34 ( V_11 ,
V_85 , & V_82 ) ;
}
static int
F_35 ( struct V_68 * V_86 )
{
static int V_87 ;
enum V_80 V_81 = 0 ;
int V_88 = V_89 ;
int V_90 = 0 ;
F_36 ( V_91 , 0 , 0 , V_92 ) ;
if ( V_87 ) {
V_88 = - V_93 ;
V_90 = - V_94 ;
goto V_95;
}
V_87 = 1 ;
F_36 ( V_96 , 0 , 0 , V_92 ) ;
V_81 = V_86 -> V_83 . V_84 . V_81 &
V_97 ;
V_81 |= V_98 ;
V_95:
if ( V_86 -> V_73 . V_77 . V_99 )
V_90 = F_33 ( & V_86 -> V_73 , V_88 , V_81 ) ;
return V_90 ;
}
static int
F_37 ( struct V_70 * V_71 , int V_72 )
{
struct V_68 V_82 ;
F_32 ( & V_82 , V_71 , V_72 ) ;
if ( V_82 . V_73 . V_77 . V_100 == 1 )
return - V_16 ;
return F_34 ( V_11 ,
V_85 , & V_82 ) ;
}
static int F_38 (
struct V_70 * V_71 , int V_72 ,
struct V_101 V_102 )
{
struct V_68 V_82 ;
F_32 ( & V_82 , V_71 , V_72 ) ;
V_82 . V_83 . V_103 . V_102 = V_102 ;
V_82 . V_83 . V_103 . V_77 . V_104 = 1 ;
return F_34 ( V_11 ,
V_85 , & V_82 ) ;
}
static int
F_39 ( struct V_68 * V_69 , enum V_105 V_106 )
{
T_4 V_107 ;
T_5 V_108 ;
int V_109 ;
V_109 = F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_110 ) ,
& V_108 , sizeof( T_5 ) ) ;
if ( V_109 ) {
F_36 ( V_111 , 0 , 0 ,
V_112 ) ;
return V_109 ;
}
if ( V_108 != V_113 ) {
F_36 ( V_114 , 0 ,
V_108 ,
V_112 ) ;
return - V_94 ;
}
V_109 = F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_115 ) ,
& V_107 , sizeof( T_4 ) ) ;
if ( V_109 ) {
F_36 ( V_111 , 0 , 0 ,
V_112 ) ;
return V_109 ;
}
if ( V_106 == V_116 ) {
V_109 = F_10 ( V_11 ,
V_107 ,
V_69 ,
sizeof( struct V_68 ) ) ;
if ( V_109 ) {
F_36 ( V_117 , 0 , 0 ,
V_112 ) ;
return V_109 ;
}
} else {
V_107 += sizeof( struct V_68 ) ;
V_109 = F_10 ( V_11 ,
V_107 ,
V_69 ,
sizeof( struct V_68 ) ) ;
if ( V_109 ) {
F_36 ( V_118 , 0 , 0 ,
V_112 ) ;
return V_109 ;
}
}
return 0 ;
}
static int
F_40 ( enum V_119 V_120 ,
struct V_70 * V_121 ,
int V_72 )
{
if ( ! V_121 )
return - V_94 ;
if ( V_121 -> V_32 != ( T_4 ) V_120 )
return - V_16 ;
return F_37 ( V_121 , V_72 ) ;
}
static int
F_41 ( enum V_119 V_120 ,
struct V_58 * V_122 , int V_72 ,
struct V_101 V_123 )
{
struct V_68 V_82 ;
T_4 V_61 = V_122 -> V_63 ;
T_4 V_62 = V_122 -> V_64 ;
if ( ! V_122 -> V_121 )
return - V_94 ;
if ( V_122 -> V_121 -> V_32 != V_120 )
return - V_16 ;
F_32 ( & V_82 , V_122 -> V_121 , V_72 ) ;
V_82 . V_83 . V_103 . V_61 = V_61 ;
V_82 . V_83 . V_103 . V_62 = V_62 ;
V_82 . V_83 . V_103 . V_102 = V_123 ;
return F_34 ( V_11 ,
V_85 , & V_82 ) ;
}
static int
F_42 ( enum V_119 V_120 ,
struct V_70 * V_121 ,
int V_72 )
{
if ( ! V_121 )
return - V_94 ;
if ( V_121 -> V_32 != ( T_4 ) V_120 )
return - V_16 ;
return F_37 ( V_121 , V_72 ) ;
}
static int
F_43 ( struct V_68 * V_86 )
{
struct V_124 * V_83 = & V_86 -> V_83 ;
struct V_70 * V_125 = NULL ;
T_4 V_61 = V_83 -> V_126 . V_61 ;
struct V_58 * V_127 ;
struct V_128 * V_128 ;
int V_109 ;
V_127 = F_30 ( V_61 , V_129 , NULL ) ;
if ( V_127 && ( V_127 -> V_102 . V_130 == 1 ) ) {
F_36 ( V_131 , 0 , V_61 ,
V_112 ) ;
V_109 = - V_132 ;
goto V_133;
}
V_127 = F_44 ( sizeof( * V_127 ) , V_56 ) ;
if ( ! V_127 ) {
F_36 ( V_131 , 0 , V_61 ,
V_112 ) ;
V_109 = - V_134 ;
goto V_133;
}
F_45 ( & V_127 -> V_135 ) ;
V_127 -> V_63 = V_61 ;
V_127 -> V_64 = V_129 ;
F_36 ( V_136 , 0 , V_61 , V_92 ) ;
if ( F_46 ( V_83 -> V_126 . V_137 , V_138 ) == 0 )
F_39 ( V_86 , V_116 ) ;
if ( V_86 -> V_73 . V_77 . V_99 == 1 ) {
V_125 = F_44 ( sizeof( * V_125 ) ,
V_56 ) ;
if ( ! V_125 ) {
F_36 ( V_139 , V_83 ,
V_127 -> V_63 ,
V_112 ) ;
V_109 = - V_134 ;
goto V_140;
}
memcpy ( V_125 , & V_86 -> V_73 ,
sizeof( struct V_70 ) ) ;
V_127 -> V_121 = V_125 ;
}
V_128 = F_47 ( V_83 -> V_126 . V_141 ,
V_83 -> V_126 . V_142 ,
V_56 ,
V_83 -> V_126 . V_143 ) ;
if ( ! V_128 ) {
F_36 ( V_131 , 0 , V_61 ,
V_112 ) ;
V_109 = - V_134 ;
goto V_144;
}
V_127 -> V_128 = V_128 ;
F_48 ( V_127 ) ;
F_36 ( V_145 , 0 , V_61 , V_92 ) ;
return 0 ;
V_144:
F_25 ( V_127 -> V_121 ) ;
V_140:
F_25 ( V_127 ) ;
V_133:
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_40 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_109 ) ;
return V_109 ;
}
static int
F_49 ( struct V_68 * V_86 )
{
struct V_124 * V_83 = & V_86 -> V_83 ;
struct V_70 * V_125 = NULL ;
T_4 V_61 = V_83 -> V_146 . V_61 ;
struct V_58 * V_127 ;
int V_109 ;
V_127 = F_30 ( V_61 , V_129 , NULL ) ;
if ( ! V_127 ) {
V_109 = - V_4 ;
goto V_133;
}
if ( V_127 -> V_102 . V_130 == 0 ) {
V_109 = - V_147 ;
goto V_133;
}
if ( V_127 -> V_121 ) {
V_109 = - V_132 ;
goto V_133;
}
if ( V_86 -> V_73 . V_77 . V_99 == 1 ) {
V_125 = F_44 ( sizeof( * V_125 ) , V_56 ) ;
if ( ! V_125 ) {
F_36 ( V_139 , V_83 ,
V_127 -> V_63 ,
V_112 ) ;
V_109 = - V_134 ;
goto V_133;
}
memcpy ( V_125 , & V_86 -> V_73 ,
sizeof( struct V_70 ) ) ;
V_127 -> V_121 = V_125 ;
}
F_50 ( V_127 ) ;
return 0 ;
V_133:
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_40 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_109 ) ;
return V_109 ;
}
static int
F_51 ( struct V_68 * V_86 ,
struct V_26 * V_148 )
{
struct V_124 * V_83 = & V_86 -> V_83 ;
T_4 V_61 ;
struct V_58 * V_127 ;
int V_109 = 0 ;
V_61 = V_83 -> V_149 . V_61 ;
F_36 ( V_150 , 0 , V_61 ,
V_92 ) ;
V_127 = F_30 ( V_61 , V_129 , NULL ) ;
if ( ! V_127 ) {
F_36 ( V_151 , 0 , V_61 ,
V_112 ) ;
V_109 = - V_16 ;
goto V_133;
} else if ( V_127 -> V_102 . V_130 == 0 ) {
F_36 ( V_151 , 0 , V_61 ,
V_112 ) ;
V_109 = - V_16 ;
goto V_133;
} else if ( V_127 -> V_121 ) {
F_36 ( V_151 , 0 , V_61 ,
V_112 ) ;
V_109 = - V_94 ;
goto V_133;
}
V_109 = F_52
( V_127 -> V_128 ,
V_83 -> V_149 . V_152 ) ;
if ( V_109 )
goto V_133;
V_127 -> V_153 = F_22 ( V_148 ) ;
F_23 ( V_148 , V_46 ) ;
V_127 -> V_154 = F_26 ( V_148 ) ;
F_36 ( V_155 , 0 , V_61 ,
V_92 ) ;
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_40 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_109 ) ;
return 0 ;
V_133:
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_40 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_109 ) ;
return V_109 ;
}
static void
F_53 ( struct V_68 * V_86 )
{
struct V_124 * V_83 = & V_86 -> V_83 ;
struct V_70 * V_125 = NULL ;
T_4 V_61 = V_83 -> V_156 . V_61 ;
T_4 V_62 = V_83 -> V_156 . V_62 ;
struct V_58 * V_157 = NULL ;
struct V_58 * V_127 ;
struct V_128 * V_128 ;
int V_88 = V_89 ;
V_127 = F_30 ( V_61 , V_129 , NULL ) ;
if ( ! V_127 ) {
F_36 ( V_158 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_159 ;
goto V_95;
}
if ( V_127 -> V_102 . V_130 == 0 ) {
F_36 ( V_158 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_159 ;
goto V_95;
}
V_157 = F_30 ( V_61 , V_62 , NULL ) ;
if ( V_157 && ( V_157 -> V_102 . V_130 == 1 ) ) {
F_36 ( V_158 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_93 ;
goto V_95;
}
V_157 = F_44 ( sizeof( * V_157 ) , V_56 ) ;
if ( ! V_157 ) {
F_36 ( V_158 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_160 ;
goto V_95;
}
V_157 -> V_63 = V_61 ;
V_157 -> V_64 = V_62 ;
V_157 -> V_161 = V_83 -> V_156 . V_162 ;
V_157 -> V_5 . V_163 = & V_127 -> V_5 ;
F_36 ( V_164 , V_62 , V_61 ,
V_92 ) ;
V_128 =
F_54 ( V_83 -> V_156 . V_141 ,
V_83 -> V_156 . V_142 ,
V_56 ,
V_83 -> V_156 . V_165 ) ;
if ( ! V_128 ) {
F_36 ( V_158 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_160 ;
goto V_166;
}
V_157 -> V_128 = V_128 ;
V_157 -> V_167 = V_83 -> V_156 . V_165 ;
if ( F_46 ( V_83 -> V_156 . V_165 ,
V_168 ) == 0 )
F_39 ( V_86 , V_169 ) ;
if ( V_86 -> V_73 . V_77 . V_99 == 1 ) {
V_125 = F_44 ( sizeof( * V_125 ) , V_56 ) ;
if ( ! V_125 ) {
V_88 = - V_160 ;
goto V_166;
}
memcpy ( V_125 , & V_86 -> V_73 ,
sizeof( struct V_70 ) ) ;
V_157 -> V_121 = V_125 ;
}
F_55 ( V_157 ) ;
F_36 ( V_170 , V_62 , V_61 ,
V_92 ) ;
return;
V_166:
F_25 ( V_157 ) ;
V_95:
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_42 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_88 ) ;
}
static void
F_56 ( struct V_68 * V_86 )
{
struct V_124 * V_83 = & V_86 -> V_83 ;
struct V_70 * V_125 = NULL ;
T_4 V_61 = V_83 -> V_103 . V_61 ;
T_4 V_62 = V_83 -> V_103 . V_62 ;
struct V_101 V_102 = V_83 -> V_103 . V_102 ;
struct V_58 * V_157 ;
int V_88 = V_89 ;
V_157 = F_30 ( V_61 , V_62 , NULL ) ;
if ( ! V_157 ) {
F_36 ( V_171 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_172 ;
goto V_133;
}
if ( V_157 -> V_102 . V_130 == 0 ) {
F_36 ( V_171 , V_62 , V_61 ,
V_112 ) ;
V_88 = - V_172 ;
goto V_133;
}
if ( V_157 -> V_121 ) {
V_88 = - V_173 ;
goto V_133;
}
if ( V_86 -> V_73 . V_77 . V_99 == 1 ) {
V_125 = F_44 ( sizeof( * V_125 ) , V_56 ) ;
if ( ! V_125 ) {
V_88 = - V_160 ;
goto V_133;
}
memcpy ( V_125 , & V_86 -> V_73 ,
sizeof( struct V_70 ) ) ;
V_157 -> V_121 = V_125 ;
}
if ( V_102 . V_174 == V_175 . V_174 &&
V_102 . V_176 == V_175 . V_176 )
F_57 ( V_157 ) ;
else if ( V_102 . V_174 == V_177 . V_174 &&
V_102 . V_176 == V_177 . V_176 )
F_58 ( V_157 ) ;
return;
V_133:
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_42 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_88 ) ;
}
static void
F_59 ( struct V_68 * V_86 )
{
struct V_124 * V_83 = & V_86 -> V_83 ;
struct V_70 * V_125 = NULL ;
T_4 V_61 = V_83 -> V_178 . V_61 ;
T_4 V_62 = V_83 -> V_178 . V_62 ;
struct V_58 * V_157 ;
int V_88 = V_89 ;
V_157 = F_30 ( V_61 , V_62 , NULL ) ;
if ( ! V_157 ) {
V_88 = - V_172 ;
goto V_133;
}
if ( V_157 -> V_102 . V_130 == 0 ) {
V_88 = - V_93 ;
goto V_133;
}
if ( V_157 -> V_121 ) {
V_88 = - V_173 ;
goto V_133;
}
if ( V_86 -> V_73 . V_77 . V_99 == 1 ) {
V_125 = F_44 ( sizeof( * V_125 ) , V_56 ) ;
if ( ! V_125 ) {
V_88 = - V_160 ;
goto V_133;
}
memcpy ( V_125 , & V_86 -> V_73 ,
sizeof( struct V_70 ) ) ;
V_157 -> V_121 = V_125 ;
}
F_60 ( V_157 ) ;
return;
V_133:
if ( V_86 -> V_73 . V_77 . V_99 == 1 )
F_42 ( V_86 -> V_73 . V_32 , & V_86 -> V_73 , V_88 ) ;
}
static int
F_61 ( T_7 V_179 , T_7 V_180 , T_4 V_181 ,
struct V_182 * V_183 )
{
T_2 * V_184 = NULL ;
if ( ! V_183 )
return - V_185 ;
if ( ( V_180 == 0 ) || ( V_181 == 0 ) )
return - V_185 ;
V_184 = F_62 ( V_179 + V_180 , V_181 , V_186 ) ;
if ( ! V_184 )
return - V_187 ;
memset ( V_183 , 0 , sizeof( struct V_182 ) ) ;
V_183 -> V_180 = V_180 ;
V_183 -> V_181 = V_181 ;
V_183 -> V_188 = V_184 ;
return V_89 ;
}
static void
F_63 ( struct V_182 * V_183 )
{
if ( V_183 -> V_188 ) {
F_64 ( V_183 -> V_188 ) ;
V_183 -> V_188 = NULL ;
}
memset ( V_183 , 0 , sizeof( struct V_182 ) ) ;
}
static void
F_65 ( void )
{
T_7 V_179 = F_66 ( V_11 ) ;
T_7 V_189 = 0 ;
T_4 V_74 = 0 ;
if ( F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_190 ) ,
& V_189 , sizeof( V_189 ) ) < 0 ) {
F_36 ( V_191 , 0 , 0 ,
V_112 ) ;
return;
}
if ( F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_192 ) ,
& V_74 , sizeof( V_74 ) ) < 0 ) {
F_36 ( V_191 , 0 , 0 ,
V_112 ) ;
return;
}
F_61 ( V_179 ,
V_189 , V_74 ,
& V_193 ) ;
}
static int
F_67 ( void )
{
static T_8 V_32 = F_68 ( 0 ) ;
return F_69 ( & V_32 ) ;
}
static unsigned long
F_70 ( void )
{
return V_194 + F_71 ( V_195 ) ;
}
static struct V_196 *
F_72 ( struct V_68 * V_69 )
{
struct V_196 * V_197 ;
V_197 = F_27 ( sizeof( * V_197 ) , V_56 | V_57 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_32 = F_67 () ;
V_197 -> V_198 = F_70 () ;
V_197 -> V_69 = * V_69 ;
return V_197 ;
}
static void
F_73 ( struct V_196 * V_197 )
{
F_25 ( V_197 ) ;
}
static int
F_74 ( int V_32 , T_5 V_199 )
{
struct V_200 * V_201 ;
struct V_200 * V_202 ;
F_75 ( & V_203 ) ;
F_76 (pos, tmp, &parahotplug_request_list) {
struct V_196 * V_197 =
F_77 ( V_201 , struct V_196 , V_204 ) ;
if ( V_197 -> V_32 == V_32 ) {
F_78 ( V_201 ) ;
F_79 ( & V_203 ) ;
V_197 -> V_69 . V_83 . V_103 . V_102 . V_199 = V_199 ;
if ( V_197 -> V_69 . V_73 . V_77 . V_99 )
F_38 (
& V_197 -> V_69 . V_73 , V_89 ,
V_197 -> V_69 . V_83 . V_103 . V_102 ) ;
F_73 ( V_197 ) ;
return 0 ;
}
}
F_79 ( & V_203 ) ;
return - V_16 ;
}
static T_1 F_80 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
unsigned int V_32 ;
int V_109 ;
if ( F_81 ( V_9 , 10 , & V_32 ) )
return - V_16 ;
V_109 = F_74 ( V_32 , 0 ) ;
if ( V_109 < 0 )
return V_109 ;
return V_14 ;
}
static T_1 F_82 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_14 )
{
unsigned int V_32 ;
if ( F_81 ( V_9 , 10 , & V_32 ) )
return - V_16 ;
F_74 ( V_32 , 1 ) ;
return V_14 ;
}
static void F_83 ( struct V_5 * V_6 )
{
}
static void
F_84 ( struct V_196 * V_197 )
{
struct V_124 * V_83 = & V_197 -> V_69 . V_83 ;
char V_205 [ 40 ] , V_206 [ 40 ] , V_207 [ 40 ] , V_208 [ 40 ] , V_209 [ 40 ] ,
V_210 [ 40 ] ;
char * V_211 [] = {
V_205 , V_206 , V_207 , V_208 , V_209 , V_210 , NULL
} ;
sprintf ( V_205 , L_4 ) ;
sprintf ( V_206 , L_5 , V_197 -> V_32 ) ;
sprintf ( V_207 , L_6 ,
V_83 -> V_103 . V_102 . V_199 ) ;
sprintf ( V_208 , L_7 ,
V_83 -> V_103 . V_61 ) ;
sprintf ( V_209 , L_8 ,
V_83 -> V_103 . V_62 >> 3 ) ;
sprintf ( V_210 , L_9 ,
V_83 -> V_103 . V_62 & 0x7 ) ;
F_85 ( & V_212 . V_6 . V_213 , V_214 ,
V_211 ) ;
}
static void
F_86 ( struct V_68 * V_86 )
{
struct V_196 * V_197 ;
V_197 = F_72 ( V_86 ) ;
if ( ! V_197 )
return;
if ( V_86 -> V_83 . V_103 . V_102 . V_199 ) {
F_84 ( V_197 ) ;
F_38
( & V_86 -> V_73 ,
V_89 ,
V_86 -> V_83 . V_103 . V_102 ) ;
F_73 ( V_197 ) ;
} else {
F_75 ( & V_203 ) ;
F_87 ( & V_197 -> V_204 , & V_215 ) ;
F_79 ( & V_203 ) ;
F_84 ( V_197 ) ;
}
}
static int
F_88 ( void )
{
F_89 ( & V_212 . V_6 . V_213 , V_216 ) ;
return V_89 ;
}
static int
F_90 ( void )
{
char V_217 [ 20 ] ;
char * V_211 [] = { V_217 , NULL } ;
sprintf ( V_217 , L_10 , 1 ) ;
F_85 ( & V_212 . V_6 . V_213 , V_214 ,
V_211 ) ;
return V_89 ;
}
static int
F_91 ( void )
{
F_89 ( & V_212 . V_6 . V_213 , V_218 ) ;
return V_89 ;
}
static void
F_92 ( struct V_70 * V_71 )
{
int V_88 = F_88 () ;
if ( V_88 != V_89 )
V_88 = - V_88 ;
if ( V_71 -> V_77 . V_99 )
F_37 ( V_71 , V_88 ) ;
}
static void
F_93 ( struct V_70 * V_71 )
{
int V_88 = F_90 () ;
if ( V_88 != V_89 )
V_88 = - V_88 ;
if ( V_71 -> V_77 . V_99 )
F_37 ( V_71 , V_88 ) ;
}
static void
F_94 ( struct V_70 * V_71 )
{
int V_88 = F_91 () ;
if ( V_88 != V_89 )
V_88 = - V_88 ;
if ( V_71 -> V_77 . V_99 )
F_37 ( V_71 , V_88 ) ;
}
static inline unsigned int
F_95 ( T_7 * V_219 , T_4 * V_220 )
{
struct V_221 V_222 ;
int V_223 = V_224 ;
T_7 V_225 ;
V_225 = F_96 ( & V_222 ) ;
F_97 ( V_226 , V_225 , V_223 ) ;
if ( F_98 ( V_223 ) ) {
* V_219 = V_222 . V_227 ;
* V_220 = V_222 . V_142 ;
}
return V_223 ;
}
static T_7 F_99 ( void )
{
T_7 V_228 = 0 ;
T_4 V_229 = 0 ;
if ( ! F_98 ( F_95 ( & V_228 , & V_229 ) ) )
return 0 ;
return V_228 ;
}
static void
F_100 ( struct V_230 * V_231 )
{
struct V_68 V_232 ;
struct V_68 V_233 ;
struct V_68 V_69 ;
T_4 V_107 ;
T_5 V_108 ;
F_36 ( V_234 , 0 , 0 , V_92 ) ;
V_69 . V_73 . V_32 = V_235 ;
V_69 . V_83 . V_84 . V_236 = 23 ;
V_69 . V_83 . V_84 . V_237 = 0 ;
F_35 ( & V_69 ) ;
if ( F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_110 ) ,
& V_108 , sizeof( T_5 ) ) < 0 ) {
F_36 ( V_111 , 0 , 0 ,
V_112 ) ;
return;
}
if ( V_108 != V_113 ) {
F_36 ( V_114 , 0 ,
V_108 ,
V_112 ) ;
return;
}
if ( F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_115 ) ,
& V_107 , sizeof( T_4 ) ) < 0 ) {
F_36 ( V_111 , 0 , 0 ,
V_112 ) ;
return;
}
if ( F_5 ( V_11 ,
V_107 ,
& V_232 ,
sizeof( struct V_68 ) ) < 0 ) {
F_36 ( V_238 , 0 , 0 ,
V_112 ) ;
return;
}
if ( F_5 ( V_11 ,
V_107 +
sizeof( struct V_68 ) ,
& V_233 ,
sizeof( struct V_68 ) ) < 0 ) {
F_36 ( V_239 , 0 , 0 ,
V_112 ) ;
return;
}
if ( V_232 . V_83 . V_126 . V_141 ) {
F_43 ( & V_232 ) ;
} else {
F_36 ( V_240 , 0 , 0 ,
V_112 ) ;
return;
}
if ( V_233 . V_83 . V_156 . V_141 ) {
F_53 ( & V_233 ) ;
} else {
F_36 ( V_241 , 0 , 0 ,
V_112 ) ;
return;
}
F_36 ( V_242 , 0 , 0 , V_92 ) ;
}
void
F_101 ( struct V_58 * V_127 , int V_72 )
{
if ( V_72 >= 0 )
V_127 -> V_102 . V_130 = 1 ;
F_40 ( V_243 , V_127 -> V_121 ,
V_72 ) ;
F_25 ( V_127 -> V_121 ) ;
V_127 -> V_121 = NULL ;
}
void
F_102 ( struct V_58 * V_127 , int V_72 )
{
F_40 ( V_244 , V_127 -> V_121 ,
V_72 ) ;
F_25 ( V_127 -> V_121 ) ;
V_127 -> V_121 = NULL ;
}
void
F_103 ( struct V_58 * V_157 , int V_72 )
{
if ( V_72 >= 0 )
V_157 -> V_102 . V_130 = 1 ;
F_42 ( V_245 , V_157 -> V_121 ,
V_72 ) ;
F_25 ( V_157 -> V_121 ) ;
V_157 -> V_121 = NULL ;
}
void
F_104 ( struct V_58 * V_157 , int V_72 )
{
F_42 ( V_246 , V_157 -> V_121 ,
V_72 ) ;
F_25 ( V_157 -> V_121 ) ;
V_157 -> V_121 = NULL ;
}
void
F_105 ( struct V_58 * V_157 ,
int V_72 )
{
F_41 ( V_247 ,
V_157 , V_72 ,
V_177 ) ;
F_25 ( V_157 -> V_121 ) ;
V_157 -> V_121 = NULL ;
}
void
F_106 ( struct V_58 * V_157 , int V_72 )
{
F_41 ( V_247 ,
V_157 , V_72 ,
V_175 ) ;
F_25 ( V_157 -> V_121 ) ;
V_157 -> V_121 = NULL ;
}
static int
F_107 ( struct V_2 * V_2 , struct V_248 * V_249 )
{
unsigned long V_225 = 0 ;
unsigned long V_180 = V_249 -> V_250 << V_251 ;
T_7 V_228 = 0 ;
if ( V_180 & ( V_13 - 1 ) )
return - V_252 ;
switch ( V_180 ) {
case V_253 :
V_249 -> V_254 |= V_255 ;
if ( ! * V_256 )
return - V_252 ;
F_5
( * V_256 ,
F_6 ( struct V_12 ,
V_257 ) ,
& V_228 , sizeof( V_228 ) ) ;
if ( ! V_228 )
return - V_252 ;
V_225 = ( unsigned long ) V_228 ;
if ( F_108 ( V_249 , V_249 -> V_258 ,
V_225 >> V_251 ,
V_249 -> V_259 - V_249 -> V_258 ,
( V_249 -> V_260 ) ) ) {
return - V_261 ;
}
break;
default:
return - V_252 ;
}
return 0 ;
}
static inline T_9 F_109 ( void )
{
T_7 V_223 = V_224 ;
T_7 V_225 = 0 ;
F_97 ( V_262 , V_225 ,
V_223 ) ;
return V_223 ;
}
static inline int F_110 ( T_7 V_263 )
{
int V_223 = V_224 ;
F_97 ( V_264 , V_263 , V_223 ) ;
return V_223 ;
}
static long F_111 ( struct V_2 * V_2 , unsigned int V_83 ,
unsigned long V_265 )
{
T_7 V_263 ;
T_9 V_266 ;
switch ( V_83 ) {
case V_262 :
V_266 = F_109 () ;
if ( F_112 ( ( void V_267 * ) V_265 , & V_266 ,
sizeof( V_266 ) ) ) {
return - V_268 ;
}
return 0 ;
case V_264 :
if ( F_113 ( & V_263 , ( void V_267 * ) V_265 ,
sizeof( V_263 ) ) ) {
return - V_268 ;
}
return F_110 ( V_263 ) ;
default:
return - V_268 ;
}
}
static int
F_114 ( T_10 V_269 , struct V_128 * * V_11 )
{
int V_88 = 0 ;
V_256 = V_11 ;
F_115 ( & V_270 , & V_271 ) ;
V_270 . V_272 = V_273 ;
if ( F_116 ( V_269 ) == 0 ) {
V_88 = F_117 ( & V_269 , 0 , 1 , L_11 ) ;
if ( V_88 < 0 )
return V_88 ;
} else {
V_88 = F_118 ( V_269 , 1 , L_11 ) ;
if ( V_88 < 0 )
return V_88 ;
}
V_88 = F_119 ( & V_270 , F_120 ( F_116 ( V_269 ) , 0 ) , 1 ) ;
if ( V_88 < 0 ) {
F_121 ( V_269 , 1 ) ;
return V_88 ;
}
return 0 ;
}
static void
F_122 ( T_10 V_269 )
{
if ( V_270 . V_274 )
F_123 ( & V_270 ) ;
V_270 . V_274 = NULL ;
F_121 ( V_269 , 1 ) ;
}
static struct V_26 *
F_124 ( T_7 V_228 , T_4 V_181 , bool V_275 , bool * V_276 )
{
int V_277 = sizeof( struct V_26 ) + V_181 ;
struct V_26 * V_27 ;
if ( V_276 )
* V_276 = false ;
V_277 ++ ;
if ( ( V_49 + V_181 )
> V_278 ) {
if ( V_276 )
* V_276 = true ;
return NULL ;
}
V_27 = F_44 ( V_277 , V_56 | V_57 ) ;
if ( ! V_27 ) {
if ( V_276 )
* V_276 = true ;
return NULL ;
}
V_27 -> V_277 = V_277 ;
V_27 -> V_50 = V_181 ;
V_27 -> V_36 = NULL ;
V_27 -> V_38 = 0 ;
V_27 -> V_279 = false ;
if ( V_275 ) {
void * V_122 ;
if ( V_228 > F_96 ( V_280 - 1 ) )
goto V_281;
V_122 = F_125 ( ( unsigned long ) ( V_228 ) ) ;
memcpy ( V_27 -> V_31 , V_122 , V_181 ) ;
} else {
void * V_282 = F_62 ( V_228 , V_181 , V_186 ) ;
if ( ! V_282 )
goto V_281;
memcpy ( V_27 -> V_31 , V_282 , V_181 ) ;
F_64 ( V_282 ) ;
}
V_27 -> V_279 = true ;
V_49 += V_27 -> V_50 ;
return V_27 ;
V_281:
F_24 ( V_27 ) ;
return NULL ;
}
static bool
F_126 ( struct V_68 V_86 , T_7 V_141 )
{
struct V_124 * V_83 = & V_86 . V_83 ;
T_7 V_283 ;
T_4 V_284 ;
struct V_26 * V_148 = NULL ;
bool V_285 ;
struct V_68 V_286 ;
V_285 = ( V_86 . V_73 . V_77 . V_100 == 1 ) ;
if ( V_141 == 0 )
return true ;
V_283 = V_141 + V_86 . V_73 . V_75 ;
V_284 = V_86 . V_73 . V_74 ;
if ( V_283 && V_284 ) {
bool V_276 = false ;
V_148 =
F_124 ( V_283 , V_284 ,
V_285 , & V_276 ) ;
if ( ! V_148 && V_276 )
return false ;
}
if ( ! V_285 ) {
F_32 ( & V_286 , & V_86 . V_73 ,
V_89 ) ;
if ( V_11 )
F_34 ( V_11 ,
V_287 ,
& V_286 ) ;
}
switch ( V_86 . V_73 . V_32 ) {
case V_235 :
F_35 ( & V_86 ) ;
break;
case V_243 :
F_43 ( & V_86 ) ;
break;
case V_244 :
F_49 ( & V_86 ) ;
break;
case V_288 :
F_51 ( & V_86 , V_148 ) ;
break;
case V_245 :
F_53 ( & V_86 ) ;
break;
case V_247 :
if ( V_83 -> V_103 . V_77 . V_104 ) {
F_86 ( & V_86 ) ;
} else {
F_56 ( & V_86 ) ;
break;
}
break;
case V_246 :
F_59 ( & V_86 ) ;
break;
case V_289 :
if ( V_86 . V_73 . V_77 . V_99 )
F_37 ( & V_86 . V_73 , V_89 ) ;
break;
case V_290 :
F_92 ( & V_86 . V_73 ) ;
break;
case V_291 :
F_93 ( & V_86 . V_73 ) ;
break;
case V_292 :
F_94 ( & V_86 . V_73 ) ;
break;
default:
if ( V_86 . V_73 . V_77 . V_99 )
F_37
( & V_86 . V_73 ,
- V_293 ) ;
break;
}
if ( V_148 ) {
F_24 ( V_148 ) ;
V_148 = NULL ;
}
return true ;
}
static bool
F_127 ( struct V_68 * V_69 )
{
if ( ! F_128 ( V_11 ,
V_294 , V_69 ) ) {
if ( V_69 -> V_73 . V_77 . V_100 == 1 )
return false ;
return true ;
}
return false ;
}
static void
F_129 ( void )
{
struct V_200 * V_201 ;
struct V_200 * V_202 ;
F_75 ( & V_203 ) ;
F_76 (pos, tmp, &parahotplug_request_list) {
struct V_196 * V_197 =
F_77 ( V_201 , struct V_196 , V_204 ) ;
if ( ! F_130 ( V_194 , V_197 -> V_198 ) )
continue;
F_78 ( V_201 ) ;
if ( V_197 -> V_69 . V_73 . V_77 . V_99 )
F_38 (
& V_197 -> V_69 . V_73 ,
V_295 ,
V_197 -> V_69 . V_83 . V_103 . V_102 ) ;
F_73 ( V_197 ) ;
}
F_79 ( & V_203 ) ;
}
static void
F_131 ( struct V_230 * V_231 )
{
struct V_68 V_86 ;
bool V_296 = false ;
bool V_297 = false ;
while ( ! F_128 ( V_11 ,
V_298 ,
& V_86 ) )
;
if ( ! V_296 ) {
if ( V_299 ) {
V_86 = V_300 ;
V_299 = false ;
V_296 = true ;
} else {
V_296 = F_127 ( & V_86 ) ;
}
}
V_297 = false ;
while ( V_296 && ( ! V_297 ) ) {
V_301 = V_194 ;
if ( F_126 ( V_86 ,
F_66
( V_11 ) ) )
V_296 = F_127 ( & V_86 ) ;
else {
V_297 = true ;
V_300 = V_86 ;
V_299 = true ;
}
}
F_129 () ;
if ( F_132 ( V_194 ,
V_301 + ( V_302 * V_303 ) ) ) {
if ( V_304 != V_305 )
V_304 = V_305 ;
} else {
if ( V_304 != V_306 )
V_304 = V_306 ;
}
F_133 ( & V_307 , V_304 ) ;
}
static int
F_134 ( struct V_308 * V_308 )
{
int V_109 = - V_4 ;
T_7 V_228 ;
T_6 V_309 = V_310 ;
V_228 = F_99 () ;
if ( ! V_228 )
goto error;
V_11 = F_54 ( V_228 , 0 ,
V_56 , V_309 ) ;
if ( ! V_11 )
goto error;
if ( F_135 (
F_136 ( V_11 ) ) ) {
F_65 () ;
} else {
goto V_311;
}
V_269 = F_120 ( V_312 , 0 ) ;
V_109 = F_114 ( V_269 , & V_11 ) ;
if ( V_109 < 0 )
goto V_313;
if ( F_137 () )
F_138 ( & V_307 ,
F_100 ) ;
else
F_138 ( & V_307 ,
F_131 ) ;
V_301 = V_194 ;
V_304 = V_306 ;
F_133 ( & V_307 , V_304 ) ;
V_212 . V_6 . V_314 = V_269 ;
if ( F_139 ( & V_212 ) < 0 ) {
F_36 ( V_315 , 0 , 0 ,
V_112 ) ;
V_109 = - V_4 ;
goto V_316;
}
F_36 ( V_317 , 0 , 0 , V_92 ) ;
V_109 = F_140 () ;
if ( V_109 < 0 )
goto V_318;
return 0 ;
V_318:
F_141 ( & V_212 ) ;
V_316:
F_142 ( & V_307 ) ;
F_122 ( V_269 ) ;
V_313:
F_63 ( & V_193 ) ;
V_311:
F_143 ( V_11 ) ;
error:
F_36 ( V_319 , 0 , V_109 , V_112 ) ;
return V_109 ;
}
static int
F_144 ( struct V_308 * V_308 )
{
F_36 ( V_320 , 0 , 0 , V_92 ) ;
F_145 () ;
F_142 ( & V_307 ) ;
F_63 ( & V_193 ) ;
F_143 ( V_11 ) ;
F_122 ( V_212 . V_6 . V_314 ) ;
F_141 ( & V_212 ) ;
F_36 ( V_320 , 0 , 0 , V_92 ) ;
return 0 ;
}
static T_11 T_12 F_146 ( void )
{
unsigned int V_321 , V_322 , V_323 , V_324 ;
if ( F_147 ( V_325 ) ) {
F_148 ( V_326 , & V_321 , & V_322 , & V_323 , & V_324 ) ;
return ( V_322 == V_327 ) &&
( V_323 == V_328 ) &&
( V_324 == V_329 ) ;
} else {
return 0 ;
}
}
static int F_149 ( void )
{
int V_223 ;
if ( ! F_146 () )
return - V_4 ;
V_223 = F_150 ( & V_330 ) ;
if ( V_223 )
return - V_4 ;
F_151 ( L_12 ) ;
return 0 ;
}
static void F_152 ( void )
{
F_153 ( & V_330 ) ;
}
