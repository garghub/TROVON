static T_1 F_1 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
T_1 V_5 = V_4 ;
int V_6 = F_2 ( V_3 , NULL , 0 ) ;
V_2 = F_3 ( V_2 -> V_7 ) ;
if ( ! V_2 )
return - V_8 ;
switch ( V_6 ) {
case 0 :
F_4 ( V_2 ) ;
break;
case 1 :
F_5 ( V_2 ) ;
break;
default:
V_5 = - V_8 ;
}
F_6 ( V_2 ) ;
return V_5 ;
}
static T_1 F_7 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
V_2 -> V_9 = F_2 ( V_3 , NULL , 0 ) ;
F_8 ( V_10 , & V_2 -> V_11 ) ;
F_9 ( & V_2 -> V_12 ) ;
return V_4 ;
}
static T_1 F_10 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_13 , L_1 , V_2 -> V_14 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
V_2 -> V_14 = F_12 ( V_3 , NULL , 0 ) ;
return V_4 ;
}
static T_1 F_13 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_13 , L_1 , F_14 ( V_2 ) ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
int V_15 = F_12 ( V_3 , NULL , 0 ) ;
if ( V_15 == 1 )
F_8 ( V_16 , & V_2 -> V_11 ) ;
return V_4 ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
T_3 V_17 = F_17 ( V_2 ) ;
return snprintf ( V_3 , V_13 , L_2 , V_17 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_13 , L_3 , V_2 -> V_18 ) ;
}
static T_1 F_19 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_3 )
{
struct V_1 * V_2 = F_20 ( V_20 , struct V_1 , V_23 ) ;
struct V_24 * V_25 = F_20 ( V_22 , struct V_24 , V_22 ) ;
return V_25 -> V_26 ? V_25 -> V_26 ( V_2 , V_3 ) : 0 ;
}
static T_1 F_21 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_3 , T_2 V_4 )
{
struct V_1 * V_2 = F_20 ( V_20 , struct V_1 , V_23 ) ;
struct V_24 * V_25 = F_20 ( V_22 , struct V_24 , V_22 ) ;
return V_25 -> V_27 ? V_25 -> V_27 ( V_2 , V_3 , V_4 ) : V_4 ;
}
static void F_22 ( struct V_19 * V_28 )
{
struct V_1 * V_2 = F_20 ( V_28 , struct V_1 , V_23 ) ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_29 )
{
int error ;
if ( V_29 )
F_25 ( & V_2 -> V_23 , V_30 ) ;
else
F_25 ( & V_2 -> V_23 , V_31 ) ;
F_26 ( V_2 , L_4 , V_29 ? L_5 : L_6 ) ;
error = F_27 ( V_2 -> V_12 ,
F_28 ( V_10 , & V_2 -> V_11 ) ) ;
F_26 ( V_2 , L_7 , error , V_2 -> V_9 ) ;
if ( error )
goto V_32;
error = V_2 -> V_9 ;
V_32:
if ( error )
F_29 ( V_2 , L_8 , V_29 ? L_9 : L_10 ,
error , V_2 -> V_9 ) ;
return error ;
}
static int F_30 ( struct V_33 * V_33 , struct V_19 * V_20 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_20 ( V_20 , struct V_1 , V_23 ) ;
F_31 ( V_35 , L_11 , V_2 -> V_36 ) ;
return 0 ;
}
int T_4 F_32 ( void )
{
V_37 = 0 ;
F_33 ( & V_38 ) ;
F_34 ( & V_39 ) ;
F_35 ( & V_40 ) ;
V_41 = F_36 ( L_12 , & V_42 , V_43 ) ;
if ( ! V_41 ) {
F_37 ( V_44 L_13 , V_45 ) ;
return - V_46 ;
}
return 0 ;
}
void F_38 ( void )
{
F_39 ( V_41 ) ;
}
static struct V_1 * F_40 ( void )
{
struct V_1 * V_2 ;
F_41 ( & V_40 ) ;
F_42 (ls, &lslist, ls_list) {
if ( F_43 ( V_47 , V_2 -> V_48 +
V_49 . V_50 * V_51 ) ) {
F_44 ( & V_40 ) ;
return V_2 ;
}
}
F_44 ( & V_40 ) ;
return NULL ;
}
static int F_45 ( void * V_52 )
{
struct V_1 * V_2 ;
while ( ! F_46 () ) {
V_2 = F_40 () ;
if ( V_2 ) {
if ( F_47 ( V_2 ) ) {
V_2 -> V_48 = V_47 ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
} else {
V_2 -> V_48 += V_51 ;
}
continue;
}
F_52 ( V_49 . V_50 * V_51 ) ;
}
return 0 ;
}
static int F_53 ( void )
{
struct V_53 * V_54 ;
int error = 0 ;
V_54 = F_54 ( F_45 , NULL , L_14 ) ;
if ( F_55 ( V_54 ) )
error = F_56 ( V_54 ) ;
else
V_55 = V_54 ;
return error ;
}
static void F_57 ( void )
{
F_58 ( V_55 ) ;
}
struct V_1 * F_59 ( T_3 V_56 )
{
struct V_1 * V_2 ;
F_41 ( & V_40 ) ;
F_42 (ls, &lslist, ls_list) {
if ( V_2 -> V_14 == V_56 ) {
V_2 -> V_37 ++ ;
goto V_32;
}
}
V_2 = NULL ;
V_32:
F_44 ( & V_40 ) ;
return V_2 ;
}
struct V_1 * F_3 ( T_5 * V_57 )
{
struct V_1 * V_2 ;
F_41 ( & V_40 ) ;
F_42 (ls, &lslist, ls_list) {
if ( V_2 -> V_7 == V_57 ) {
V_2 -> V_37 ++ ;
goto V_32;
}
}
V_2 = NULL ;
V_32:
F_44 ( & V_40 ) ;
return V_2 ;
}
struct V_1 * F_60 ( int V_58 )
{
struct V_1 * V_2 ;
F_41 ( & V_40 ) ;
F_42 (ls, &lslist, ls_list) {
if ( V_2 -> V_59 . V_58 == V_58 ) {
V_2 -> V_37 ++ ;
goto V_32;
}
}
V_2 = NULL ;
V_32:
F_44 ( & V_40 ) ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_41 ( & V_40 ) ;
V_2 -> V_37 -- ;
F_44 ( & V_40 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
for (; ; ) {
F_41 ( & V_40 ) ;
if ( V_2 -> V_37 == 0 ) {
F_62 ( V_2 -> V_60 != 0 ) ;
F_63 ( & V_2 -> V_61 ) ;
F_44 ( & V_40 ) ;
return;
}
F_44 ( & V_40 ) ;
F_64 ( 1 ) ;
}
}
static int F_65 ( void )
{
int error ;
error = F_53 () ;
if ( error ) {
F_66 ( L_15 , error ) ;
goto V_62;
}
error = F_67 () ;
if ( error ) {
F_66 ( L_16 , error ) ;
goto V_63;
}
return 0 ;
V_63:
F_57 () ;
V_62:
return error ;
}
static void F_68 ( void )
{
F_57 () ;
F_69 () ;
}
static int F_70 ( const char * V_64 , const char * V_65 ,
T_3 V_66 , int V_67 ,
const struct V_68 * V_69 , void * V_70 ,
int * V_71 , T_5 * * V_57 )
{
struct V_1 * V_2 ;
int V_72 , V_73 , error ;
int V_74 = 0 ;
int V_75 = strlen ( V_64 ) ;
if ( V_75 > V_76 )
return - V_8 ;
if ( ! V_67 || ( V_67 % 8 ) )
return - V_8 ;
if ( ! F_71 ( V_77 ) )
return - V_8 ;
if ( ! F_72 () ) {
F_66 ( L_17 ) ;
error = - V_78 ;
goto V_32;
}
if ( V_69 && V_71 ) {
if ( ! V_49 . V_79 )
* V_71 = - V_80 ;
else
* V_71 = 0 ;
}
if ( V_49 . V_79 && V_65 &&
strncmp ( V_65 , V_49 . V_81 , V_76 ) ) {
F_66 ( L_18 ,
V_49 . V_81 , V_65 ) ;
error = - V_82 ;
goto V_32;
}
error = 0 ;
F_41 ( & V_40 ) ;
F_42 (ls, &lslist, ls_list) {
F_62 ( V_2 -> V_60 <= 0 ) ;
if ( V_2 -> V_83 != V_75 )
continue;
if ( memcmp ( V_2 -> V_36 , V_64 , V_75 ) )
continue;
if ( V_66 & V_84 ) {
error = - V_85 ;
break;
}
V_2 -> V_60 ++ ;
* V_57 = V_2 ;
error = 1 ;
break;
}
F_44 ( & V_40 ) ;
if ( error )
goto V_32;
error = - V_46 ;
V_2 = F_73 ( sizeof( struct V_1 ) + V_75 , V_86 ) ;
if ( ! V_2 )
goto V_32;
memcpy ( V_2 -> V_36 , V_64 , V_75 ) ;
V_2 -> V_83 = V_75 ;
V_2 -> V_87 = V_67 ;
V_2 -> V_37 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_48 = V_47 ;
if ( V_69 && V_49 . V_79 ) {
V_2 -> V_88 = V_69 ;
V_2 -> V_89 = V_70 ;
}
if ( V_66 & V_90 )
F_8 ( V_91 , & V_2 -> V_11 ) ;
V_2 -> V_92 = ( V_66 & ~ ( V_90 | V_93 |
V_84 ) ) ;
V_73 = V_49 . V_94 ;
V_2 -> V_95 = V_73 ;
V_2 -> V_96 = F_74 ( sizeof( struct V_97 ) * V_73 ) ;
if ( ! V_2 -> V_96 )
goto V_98;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
V_2 -> V_96 [ V_72 ] . V_99 . V_100 = NULL ;
V_2 -> V_96 [ V_72 ] . V_101 . V_100 = NULL ;
F_35 ( & V_2 -> V_96 [ V_72 ] . V_102 ) ;
}
F_35 ( & V_2 -> V_103 ) ;
for ( V_72 = 0 ; V_72 < V_104 ; V_72 ++ ) {
V_2 -> V_105 [ V_72 ] = F_73 ( V_106 + 1 ,
V_107 ) ;
if ( ! V_2 -> V_105 [ V_72 ] )
goto V_108;
}
F_75 ( & V_2 -> V_109 ) ;
F_35 ( & V_2 -> V_110 ) ;
F_34 ( & V_2 -> V_111 ) ;
F_33 ( & V_2 -> V_112 ) ;
F_34 ( & V_2 -> V_113 ) ;
F_33 ( & V_2 -> V_114 ) ;
F_34 ( & V_2 -> V_115 ) ;
F_33 ( & V_2 -> V_116 ) ;
F_34 ( & V_2 -> V_117 ) ;
F_35 ( & V_2 -> V_118 ) ;
F_34 ( & V_2 -> V_119 ) ;
F_34 ( & V_2 -> V_120 ) ;
V_2 -> V_121 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_124 = NULL ;
memset ( & V_2 -> V_125 , 0 , sizeof( struct V_126 ) ) ;
V_2 -> V_125 . V_127 = V_2 ;
V_2 -> V_128 = NULL ;
V_2 -> V_129 = NULL ;
F_76 ( & V_2 -> V_12 ) ;
V_2 -> V_9 = 0 ;
F_77 ( & V_2 -> V_130 ) ;
V_2 -> V_131 = - 1 ;
F_33 ( & V_2 -> V_132 ) ;
F_34 ( & V_2 -> V_133 ) ;
V_2 -> V_134 = NULL ;
F_33 ( & V_2 -> V_135 ) ;
F_35 ( & V_2 -> V_136 ) ;
F_35 ( & V_2 -> V_137 ) ;
F_78 ( & V_2 -> V_138 , sizeof( V_139 ) ) ;
V_2 -> V_140 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_142 = NULL ;
F_79 ( & V_2 -> V_143 ) ;
F_79 ( & V_2 -> V_144 ) ;
F_34 ( & V_2 -> V_145 ) ;
F_33 ( & V_2 -> V_146 ) ;
F_33 ( & V_2 -> V_147 ) ;
V_2 -> V_148 = F_80 ( V_49 . V_149 , V_86 ) ;
if ( ! V_2 -> V_148 )
goto V_150;
V_2 -> V_151 = 0 ;
V_2 -> V_152 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_154 = NULL ;
F_34 ( & V_2 -> V_155 ) ;
F_35 ( & V_2 -> V_156 ) ;
F_75 ( & V_2 -> V_157 ) ;
F_35 ( & V_2 -> V_158 ) ;
V_2 -> V_159 = 0 ;
V_2 -> V_7 = V_2 ;
F_76 ( & V_2 -> V_160 ) ;
F_34 ( & V_2 -> V_161 ) ;
F_79 ( & V_2 -> V_162 ) ;
F_81 ( & V_2 -> V_143 ) ;
F_41 ( & V_40 ) ;
V_2 -> V_60 = 1 ;
F_82 ( & V_2 -> V_61 , & V_39 ) ;
F_44 ( & V_40 ) ;
if ( V_66 & V_93 ) {
error = F_83 ( V_2 ) ;
if ( error ) {
F_29 ( V_2 , L_19 , error ) ;
goto V_163;
}
}
error = F_84 ( V_2 ) ;
if ( error ) {
F_29 ( V_2 , L_20 , error ) ;
goto V_164;
}
V_2 -> V_23 . V_33 = V_41 ;
error = F_85 ( & V_2 -> V_23 , & V_165 , NULL ,
L_21 , V_2 -> V_36 ) ;
if ( error )
goto V_166;
F_25 ( & V_2 -> V_23 , V_167 ) ;
V_74 = 1 ;
error = F_24 ( V_2 , 1 ) ;
if ( error )
goto V_166;
F_86 ( & V_2 -> V_130 ) ;
error = V_2 -> V_131 ;
if ( error )
goto V_168;
F_87 ( V_2 ) ;
F_26 ( V_2 , L_22 ) ;
* V_57 = V_2 ;
return 0 ;
V_168:
F_24 ( V_2 , 0 ) ;
F_88 ( V_2 ) ;
F_23 ( V_2 -> V_124 ) ;
V_166:
F_89 ( V_2 ) ;
V_164:
F_90 ( V_2 ) ;
V_163:
F_41 ( & V_40 ) ;
F_63 ( & V_2 -> V_61 ) ;
F_44 ( & V_40 ) ;
F_91 ( & V_2 -> V_157 ) ;
F_23 ( V_2 -> V_148 ) ;
V_150:
F_91 ( & V_2 -> V_109 ) ;
for ( V_72 = 0 ; V_72 < V_104 ; V_72 ++ ) {
if ( V_2 -> V_105 [ V_72 ] )
F_23 ( V_2 -> V_105 [ V_72 ] ) ;
}
V_108:
F_92 ( V_2 -> V_96 ) ;
V_98:
if ( V_74 )
F_93 ( & V_2 -> V_23 ) ;
else
F_23 ( V_2 ) ;
V_32:
F_94 ( V_77 ) ;
return error ;
}
int F_95 ( const char * V_64 , const char * V_65 ,
T_3 V_66 , int V_67 ,
const struct V_68 * V_69 , void * V_70 ,
int * V_71 , T_5 * * V_57 )
{
int error = 0 ;
F_96 ( & V_38 ) ;
if ( ! V_37 )
error = F_65 () ;
if ( error )
goto V_32;
error = F_70 ( V_64 , V_65 , V_66 , V_67 , V_69 , V_70 ,
V_71 , V_57 ) ;
if ( ! error )
V_37 ++ ;
if ( error > 0 )
error = 0 ;
if ( ! V_37 )
F_68 () ;
V_32:
F_97 ( & V_38 ) ;
return error ;
}
static int F_98 ( int V_56 , void * V_54 , void * V_52 )
{
struct V_169 * V_170 = V_54 ;
if ( ! V_170 -> V_171 )
return 1 ;
return 0 ;
}
static int F_99 ( int V_56 , void * V_54 , void * V_52 )
{
return 1 ;
}
static int F_100 ( int V_56 , void * V_54 , void * V_52 )
{
struct V_169 * V_170 = V_54 ;
if ( V_170 -> V_172 && V_170 -> V_173 & V_174 )
F_101 ( V_170 -> V_172 ) ;
F_102 ( V_170 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , int V_175 )
{
int V_176 ;
F_41 ( & V_2 -> V_110 ) ;
if ( V_175 == 0 ) {
V_176 = F_104 ( & V_2 -> V_109 , F_99 , V_2 ) ;
} else if ( V_175 == 1 ) {
V_176 = F_104 ( & V_2 -> V_109 , F_98 , V_2 ) ;
} else {
V_176 = 0 ;
}
F_44 ( & V_2 -> V_110 ) ;
return V_176 ;
}
static int F_105 ( struct V_1 * V_2 , int V_175 )
{
struct V_126 * V_177 ;
struct V_100 * V_6 ;
int V_72 , V_178 , V_176 ;
V_178 = F_103 ( V_2 , V_175 ) ;
F_41 ( & V_40 ) ;
if ( V_2 -> V_60 == 1 ) {
if ( V_178 ) {
V_176 = - V_179 ;
} else {
V_2 -> V_60 = 0 ;
V_176 = 0 ;
}
} else if ( V_2 -> V_60 > 1 ) {
V_176 = -- V_2 -> V_60 ;
} else {
V_176 = - V_8 ;
}
F_44 ( & V_40 ) ;
if ( V_176 ) {
F_26 ( V_2 , L_23 , V_176 ) ;
return V_176 ;
}
F_106 ( V_2 ) ;
if ( V_175 < 3 && F_72 () )
F_24 ( V_2 , 0 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
F_61 ( V_2 ) ;
F_107 ( V_2 ) ;
F_23 ( V_2 -> V_148 ) ;
F_104 ( & V_2 -> V_109 , F_100 , V_2 ) ;
F_108 ( & V_2 -> V_109 ) ;
F_91 ( & V_2 -> V_109 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_95 ; V_72 ++ ) {
while ( ( V_6 = F_109 ( & V_2 -> V_96 [ V_72 ] . V_99 ) ) ) {
V_177 = F_110 ( V_6 , struct V_126 , V_180 ) ;
F_111 ( V_6 , & V_2 -> V_96 [ V_72 ] . V_99 ) ;
F_112 ( V_177 ) ;
}
while ( ( V_6 = F_109 ( & V_2 -> V_96 [ V_72 ] . V_101 ) ) ) {
V_177 = F_110 ( V_6 , struct V_126 , V_180 ) ;
F_111 ( V_6 , & V_2 -> V_96 [ V_72 ] . V_101 ) ;
F_112 ( V_177 ) ;
}
}
F_92 ( V_2 -> V_96 ) ;
for ( V_72 = 0 ; V_72 < V_104 ; V_72 ++ )
F_23 ( V_2 -> V_105 [ V_72 ] ) ;
while ( ! F_113 ( & V_2 -> V_117 ) ) {
V_177 = F_114 ( & V_2 -> V_117 , struct V_126 ,
V_181 ) ;
F_63 ( & V_177 -> V_181 ) ;
F_112 ( V_177 ) ;
}
F_115 ( V_2 ) ;
F_23 ( V_2 -> V_142 ) ;
F_88 ( V_2 ) ;
F_116 ( V_2 ) ;
F_23 ( V_2 -> V_124 ) ;
F_26 ( V_2 , L_24 ) ;
F_93 ( & V_2 -> V_23 ) ;
F_94 ( V_77 ) ;
return 0 ;
}
int F_117 ( void * V_57 , int V_175 )
{
struct V_1 * V_2 ;
int error ;
V_2 = F_3 ( V_57 ) ;
if ( ! V_2 )
return - V_8 ;
F_6 ( V_2 ) ;
F_96 ( & V_38 ) ;
error = F_105 ( V_2 , V_175 ) ;
if ( ! error )
V_37 -- ;
if ( ! V_37 )
F_68 () ;
F_97 ( & V_38 ) ;
return error ;
}
void F_118 ( void )
{
struct V_1 * V_2 ;
V_182:
F_41 ( & V_40 ) ;
F_42 (ls, &lslist, ls_list) {
if ( ! F_119 ( V_183 , & V_2 -> V_11 ) )
continue;
F_44 ( & V_40 ) ;
F_29 ( V_2 , L_25 ) ;
F_4 ( V_2 ) ;
goto V_182;
}
F_44 ( & V_40 ) ;
}
