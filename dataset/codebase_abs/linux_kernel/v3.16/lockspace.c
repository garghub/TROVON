static T_1 F_1 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
T_1 V_5 = V_4 ;
int V_6 ;
int V_7 = F_2 ( V_3 , 0 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 = F_3 ( V_2 -> V_8 ) ;
if ( ! V_2 )
return - V_9 ;
switch ( V_6 ) {
case 0 :
F_4 ( V_2 ) ;
break;
case 1 :
F_5 ( V_2 ) ;
break;
default:
V_5 = - V_9 ;
}
F_6 ( V_2 ) ;
return V_5 ;
}
static T_1 F_7 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
int V_7 = F_2 ( V_3 , 0 , & V_2 -> V_10 ) ;
if ( V_7 )
return V_7 ;
F_8 ( V_11 , & V_2 -> V_12 ) ;
F_9 ( & V_2 -> V_13 ) ;
return V_4 ;
}
static T_1 F_10 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_14 , L_1 , V_2 -> V_15 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
int V_7 = F_12 ( V_3 , 0 , & V_2 -> V_15 ) ;
if ( V_7 )
return V_7 ;
return V_4 ;
}
static T_1 F_13 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_14 , L_1 , F_14 ( V_2 ) ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , const char * V_3 , T_2 V_4 )
{
int V_16 ;
int V_7 = F_2 ( V_3 , 0 , & V_16 ) ;
if ( V_7 )
return V_7 ;
if ( V_16 == 1 )
F_8 ( V_17 , & V_2 -> V_12 ) ;
return V_4 ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
T_3 V_18 = F_17 ( V_2 ) ;
return snprintf ( V_3 , V_14 , L_2 , V_18 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_14 , L_3 , V_2 -> V_19 ) ;
}
static T_1 F_19 ( struct V_20 * V_21 , struct V_22 * V_23 ,
char * V_3 )
{
struct V_1 * V_2 = F_20 ( V_21 , struct V_1 , V_24 ) ;
struct V_25 * V_26 = F_20 ( V_23 , struct V_25 , V_23 ) ;
return V_26 -> V_27 ? V_26 -> V_27 ( V_2 , V_3 ) : 0 ;
}
static T_1 F_21 ( struct V_20 * V_21 , struct V_22 * V_23 ,
const char * V_3 , T_2 V_4 )
{
struct V_1 * V_2 = F_20 ( V_21 , struct V_1 , V_24 ) ;
struct V_25 * V_26 = F_20 ( V_23 , struct V_25 , V_23 ) ;
return V_26 -> V_28 ? V_26 -> V_28 ( V_2 , V_3 , V_4 ) : V_4 ;
}
static void F_22 ( struct V_20 * V_29 )
{
struct V_1 * V_2 = F_20 ( V_29 , struct V_1 , V_24 ) ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_30 )
{
int error ;
if ( V_30 )
F_25 ( & V_2 -> V_24 , V_31 ) ;
else
F_25 ( & V_2 -> V_24 , V_32 ) ;
F_26 ( V_2 , L_4 , V_30 ? L_5 : L_6 ) ;
error = F_27 ( V_2 -> V_13 ,
F_28 ( V_11 , & V_2 -> V_12 ) ) ;
F_26 ( V_2 , L_7 , error , V_2 -> V_10 ) ;
if ( error )
goto V_33;
error = V_2 -> V_10 ;
V_33:
if ( error )
F_29 ( V_2 , L_8 , V_30 ? L_9 : L_10 ,
error , V_2 -> V_10 ) ;
return error ;
}
static int F_30 ( struct V_34 * V_34 , struct V_20 * V_21 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_20 ( V_21 , struct V_1 , V_24 ) ;
F_31 ( V_36 , L_11 , V_2 -> V_37 ) ;
return 0 ;
}
int T_4 F_32 ( void )
{
V_38 = 0 ;
F_33 ( & V_39 ) ;
F_34 ( & V_40 ) ;
F_35 ( & V_41 ) ;
V_42 = F_36 ( L_12 , & V_43 , V_44 ) ;
if ( ! V_42 ) {
F_37 ( V_45 L_13 , V_46 ) ;
return - V_47 ;
}
return 0 ;
}
void F_38 ( void )
{
F_39 ( V_42 ) ;
}
static struct V_1 * F_40 ( void )
{
struct V_1 * V_2 ;
F_41 ( & V_41 ) ;
F_42 (ls, &lslist, ls_list) {
if ( F_43 ( V_48 , V_2 -> V_49 +
V_50 . V_51 * V_52 ) ) {
F_44 ( & V_41 ) ;
return V_2 ;
}
}
F_44 ( & V_41 ) ;
return NULL ;
}
static int F_45 ( void * V_53 )
{
struct V_1 * V_2 ;
while ( ! F_46 () ) {
V_2 = F_40 () ;
if ( V_2 ) {
if ( F_47 ( V_2 ) ) {
V_2 -> V_49 = V_48 ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
} else {
V_2 -> V_49 += V_52 ;
}
continue;
}
F_52 ( V_50 . V_51 * V_52 ) ;
}
return 0 ;
}
static int F_53 ( void )
{
struct V_54 * V_55 ;
int error = 0 ;
V_55 = F_54 ( F_45 , NULL , L_14 ) ;
if ( F_55 ( V_55 ) )
error = F_56 ( V_55 ) ;
else
V_56 = V_55 ;
return error ;
}
static void F_57 ( void )
{
F_58 ( V_56 ) ;
}
struct V_1 * F_59 ( T_3 V_57 )
{
struct V_1 * V_2 ;
F_41 ( & V_41 ) ;
F_42 (ls, &lslist, ls_list) {
if ( V_2 -> V_15 == V_57 ) {
V_2 -> V_38 ++ ;
goto V_33;
}
}
V_2 = NULL ;
V_33:
F_44 ( & V_41 ) ;
return V_2 ;
}
struct V_1 * F_3 ( T_5 * V_58 )
{
struct V_1 * V_2 ;
F_41 ( & V_41 ) ;
F_42 (ls, &lslist, ls_list) {
if ( V_2 -> V_8 == V_58 ) {
V_2 -> V_38 ++ ;
goto V_33;
}
}
V_2 = NULL ;
V_33:
F_44 ( & V_41 ) ;
return V_2 ;
}
struct V_1 * F_60 ( int V_59 )
{
struct V_1 * V_2 ;
F_41 ( & V_41 ) ;
F_42 (ls, &lslist, ls_list) {
if ( V_2 -> V_60 . V_59 == V_59 ) {
V_2 -> V_38 ++ ;
goto V_33;
}
}
V_2 = NULL ;
V_33:
F_44 ( & V_41 ) ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_41 ( & V_41 ) ;
V_2 -> V_38 -- ;
F_44 ( & V_41 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
for (; ; ) {
F_41 ( & V_41 ) ;
if ( V_2 -> V_38 == 0 ) {
F_62 ( V_2 -> V_61 != 0 ) ;
F_63 ( & V_2 -> V_62 ) ;
F_44 ( & V_41 ) ;
return;
}
F_44 ( & V_41 ) ;
F_64 ( 1 ) ;
}
}
static int F_65 ( void )
{
int error ;
error = F_53 () ;
if ( error ) {
F_66 ( L_15 , error ) ;
goto V_63;
}
error = F_67 () ;
if ( error ) {
F_66 ( L_16 , error ) ;
goto V_64;
}
return 0 ;
V_64:
F_57 () ;
V_63:
return error ;
}
static void F_68 ( void )
{
F_57 () ;
F_69 () ;
}
static int F_70 ( const char * V_65 , const char * V_66 ,
T_3 V_67 , int V_68 ,
const struct V_69 * V_70 , void * V_71 ,
int * V_72 , T_5 * * V_58 )
{
struct V_1 * V_2 ;
int V_73 , V_74 , error ;
int V_75 = 0 ;
int V_76 = strlen ( V_65 ) ;
if ( V_76 > V_77 )
return - V_9 ;
if ( ! V_68 || ( V_68 % 8 ) )
return - V_9 ;
if ( ! F_71 ( V_78 ) )
return - V_9 ;
if ( ! F_72 () ) {
F_66 ( L_17 ) ;
error = - V_79 ;
goto V_33;
}
if ( V_70 && V_72 ) {
if ( ! V_50 . V_80 )
* V_72 = - V_81 ;
else
* V_72 = 0 ;
}
if ( V_50 . V_80 && V_66 &&
strncmp ( V_66 , V_50 . V_82 , V_77 ) ) {
F_66 ( L_18 ,
V_50 . V_82 , V_66 ) ;
error = - V_83 ;
goto V_33;
}
error = 0 ;
F_41 ( & V_41 ) ;
F_42 (ls, &lslist, ls_list) {
F_62 ( V_2 -> V_61 <= 0 ) ;
if ( V_2 -> V_84 != V_76 )
continue;
if ( memcmp ( V_2 -> V_37 , V_65 , V_76 ) )
continue;
if ( V_67 & V_85 ) {
error = - V_86 ;
break;
}
V_2 -> V_61 ++ ;
* V_58 = V_2 ;
error = 1 ;
break;
}
F_44 ( & V_41 ) ;
if ( error )
goto V_33;
error = - V_47 ;
V_2 = F_73 ( sizeof( struct V_1 ) + V_76 , V_87 ) ;
if ( ! V_2 )
goto V_33;
memcpy ( V_2 -> V_37 , V_65 , V_76 ) ;
V_2 -> V_84 = V_76 ;
V_2 -> V_88 = V_68 ;
V_2 -> V_38 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_49 = V_48 ;
if ( V_70 && V_50 . V_80 ) {
V_2 -> V_89 = V_70 ;
V_2 -> V_90 = V_71 ;
}
if ( V_67 & V_91 )
F_8 ( V_92 , & V_2 -> V_12 ) ;
V_2 -> V_93 = ( V_67 & ~ ( V_91 | V_94 |
V_85 ) ) ;
V_74 = V_50 . V_95 ;
V_2 -> V_96 = V_74 ;
V_2 -> V_97 = F_74 ( sizeof( struct V_98 ) * V_74 ) ;
if ( ! V_2 -> V_97 )
goto V_99;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_2 -> V_97 [ V_73 ] . V_100 . V_101 = NULL ;
V_2 -> V_97 [ V_73 ] . V_102 . V_101 = NULL ;
F_35 ( & V_2 -> V_97 [ V_73 ] . V_103 ) ;
}
F_35 ( & V_2 -> V_104 ) ;
for ( V_73 = 0 ; V_73 < V_105 ; V_73 ++ ) {
V_2 -> V_106 [ V_73 ] = F_73 ( V_107 + 1 ,
V_108 ) ;
if ( ! V_2 -> V_106 [ V_73 ] )
goto V_109;
}
F_75 ( & V_2 -> V_110 ) ;
F_35 ( & V_2 -> V_111 ) ;
F_34 ( & V_2 -> V_112 ) ;
F_33 ( & V_2 -> V_113 ) ;
F_34 ( & V_2 -> V_114 ) ;
F_33 ( & V_2 -> V_115 ) ;
F_34 ( & V_2 -> V_116 ) ;
F_33 ( & V_2 -> V_117 ) ;
F_34 ( & V_2 -> V_118 ) ;
F_35 ( & V_2 -> V_119 ) ;
F_34 ( & V_2 -> V_120 ) ;
F_34 ( & V_2 -> V_121 ) ;
V_2 -> V_122 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_124 = 0 ;
V_2 -> V_125 = NULL ;
memset ( & V_2 -> V_126 , 0 , sizeof( struct V_127 ) ) ;
V_2 -> V_126 . V_128 = V_2 ;
V_2 -> V_129 = NULL ;
V_2 -> V_130 = NULL ;
F_76 ( & V_2 -> V_13 ) ;
V_2 -> V_10 = 0 ;
F_77 ( & V_2 -> V_131 ) ;
V_2 -> V_132 = - 1 ;
F_33 ( & V_2 -> V_133 ) ;
F_34 ( & V_2 -> V_134 ) ;
V_2 -> V_135 = NULL ;
F_33 ( & V_2 -> V_136 ) ;
F_35 ( & V_2 -> V_137 ) ;
F_35 ( & V_2 -> V_138 ) ;
F_78 ( & V_2 -> V_139 , sizeof( V_140 ) ) ;
V_2 -> V_141 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_143 = NULL ;
F_79 ( & V_2 -> V_144 ) ;
F_79 ( & V_2 -> V_145 ) ;
F_34 ( & V_2 -> V_146 ) ;
F_33 ( & V_2 -> V_147 ) ;
F_33 ( & V_2 -> V_148 ) ;
V_2 -> V_149 = F_80 ( V_50 . V_150 , V_87 ) ;
if ( ! V_2 -> V_149 )
goto V_151;
V_2 -> V_152 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_154 = 0 ;
V_2 -> V_155 = NULL ;
F_34 ( & V_2 -> V_156 ) ;
F_35 ( & V_2 -> V_157 ) ;
F_75 ( & V_2 -> V_158 ) ;
F_35 ( & V_2 -> V_159 ) ;
V_2 -> V_160 = 0 ;
V_2 -> V_8 = V_2 ;
F_76 ( & V_2 -> V_161 ) ;
F_34 ( & V_2 -> V_162 ) ;
F_79 ( & V_2 -> V_163 ) ;
F_41 ( & V_41 ) ;
V_2 -> V_61 = 1 ;
F_81 ( & V_2 -> V_62 , & V_40 ) ;
F_44 ( & V_41 ) ;
if ( V_67 & V_94 ) {
error = F_82 ( V_2 ) ;
if ( error ) {
F_29 ( V_2 , L_19 , error ) ;
goto V_164;
}
}
F_76 ( & V_2 -> V_165 ) ;
error = F_83 ( V_2 ) ;
if ( error ) {
F_29 ( V_2 , L_20 , error ) ;
goto V_166;
}
F_84 ( V_2 -> V_165 ,
F_85 ( V_167 , & V_2 -> V_12 ) ) ;
V_2 -> V_24 . V_34 = V_42 ;
error = F_86 ( & V_2 -> V_24 , & V_168 , NULL ,
L_21 , V_2 -> V_37 ) ;
if ( error )
goto V_169;
F_25 ( & V_2 -> V_24 , V_170 ) ;
V_75 = 1 ;
error = F_24 ( V_2 , 1 ) ;
if ( error )
goto V_169;
F_87 ( & V_2 -> V_131 ) ;
error = V_2 -> V_132 ;
if ( error )
goto V_171;
F_88 ( V_2 ) ;
F_26 ( V_2 , L_22 ) ;
* V_58 = V_2 ;
return 0 ;
V_171:
F_24 ( V_2 , 0 ) ;
F_89 ( V_2 ) ;
F_23 ( V_2 -> V_125 ) ;
V_169:
F_90 ( V_2 ) ;
V_166:
F_91 ( V_2 ) ;
V_164:
F_41 ( & V_41 ) ;
F_63 ( & V_2 -> V_62 ) ;
F_44 ( & V_41 ) ;
F_92 ( & V_2 -> V_158 ) ;
F_23 ( V_2 -> V_149 ) ;
V_151:
F_92 ( & V_2 -> V_110 ) ;
for ( V_73 = 0 ; V_73 < V_105 ; V_73 ++ ) {
if ( V_2 -> V_106 [ V_73 ] )
F_23 ( V_2 -> V_106 [ V_73 ] ) ;
}
V_109:
F_93 ( V_2 -> V_97 ) ;
V_99:
if ( V_75 )
F_94 ( & V_2 -> V_24 ) ;
else
F_23 ( V_2 ) ;
V_33:
F_95 ( V_78 ) ;
return error ;
}
int F_96 ( const char * V_65 , const char * V_66 ,
T_3 V_67 , int V_68 ,
const struct V_69 * V_70 , void * V_71 ,
int * V_72 , T_5 * * V_58 )
{
int error = 0 ;
F_97 ( & V_39 ) ;
if ( ! V_38 )
error = F_65 () ;
if ( error )
goto V_33;
error = F_70 ( V_65 , V_66 , V_67 , V_68 , V_70 , V_71 ,
V_72 , V_58 ) ;
if ( ! error )
V_38 ++ ;
if ( error > 0 )
error = 0 ;
if ( ! V_38 )
F_68 () ;
V_33:
F_98 ( & V_39 ) ;
return error ;
}
static int F_99 ( int V_57 , void * V_55 , void * V_53 )
{
struct V_172 * V_173 = V_55 ;
return V_173 -> V_174 == 0 && V_173 -> V_175 != V_176 ;
}
static int F_100 ( int V_57 , void * V_55 , void * V_53 )
{
return 1 ;
}
static int F_101 ( int V_57 , void * V_55 , void * V_53 )
{
struct V_172 * V_173 = V_55 ;
if ( V_173 -> V_177 && V_173 -> V_178 & V_179 )
F_102 ( V_173 -> V_177 ) ;
F_103 ( V_173 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , int V_180 )
{
int V_181 ;
F_41 ( & V_2 -> V_111 ) ;
if ( V_180 == 0 ) {
V_181 = F_105 ( & V_2 -> V_110 , F_100 , V_2 ) ;
} else if ( V_180 == 1 ) {
V_181 = F_105 ( & V_2 -> V_110 , F_99 , V_2 ) ;
} else {
V_181 = 0 ;
}
F_44 ( & V_2 -> V_111 ) ;
return V_181 ;
}
static int F_106 ( struct V_1 * V_2 , int V_180 )
{
struct V_127 * V_182 ;
struct V_101 * V_6 ;
int V_73 , V_183 , V_181 ;
V_183 = F_104 ( V_2 , V_180 ) ;
F_41 ( & V_41 ) ;
if ( V_2 -> V_61 == 1 ) {
if ( V_183 ) {
V_181 = - V_184 ;
} else {
V_2 -> V_61 = 0 ;
V_181 = 0 ;
}
} else if ( V_2 -> V_61 > 1 ) {
V_181 = -- V_2 -> V_61 ;
} else {
V_181 = - V_9 ;
}
F_44 ( & V_41 ) ;
if ( V_181 ) {
F_107 ( V_2 , L_23 , V_181 ) ;
return V_181 ;
}
F_108 ( V_2 ) ;
if ( V_180 < 3 && F_72 () )
F_24 ( V_2 , 0 ) ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
F_61 ( V_2 ) ;
F_109 ( V_2 ) ;
F_23 ( V_2 -> V_149 ) ;
F_105 ( & V_2 -> V_110 , F_101 , V_2 ) ;
F_92 ( & V_2 -> V_110 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_96 ; V_73 ++ ) {
while ( ( V_6 = F_110 ( & V_2 -> V_97 [ V_73 ] . V_100 ) ) ) {
V_182 = F_111 ( V_6 , struct V_127 , V_185 ) ;
F_112 ( V_6 , & V_2 -> V_97 [ V_73 ] . V_100 ) ;
F_113 ( V_182 ) ;
}
while ( ( V_6 = F_110 ( & V_2 -> V_97 [ V_73 ] . V_102 ) ) ) {
V_182 = F_111 ( V_6 , struct V_127 , V_185 ) ;
F_112 ( V_6 , & V_2 -> V_97 [ V_73 ] . V_102 ) ;
F_113 ( V_182 ) ;
}
}
F_93 ( V_2 -> V_97 ) ;
for ( V_73 = 0 ; V_73 < V_105 ; V_73 ++ )
F_23 ( V_2 -> V_106 [ V_73 ] ) ;
while ( ! F_114 ( & V_2 -> V_118 ) ) {
V_182 = F_115 ( & V_2 -> V_118 , struct V_127 ,
V_186 ) ;
F_63 ( & V_182 -> V_186 ) ;
F_113 ( V_182 ) ;
}
F_116 ( V_2 ) ;
F_23 ( V_2 -> V_143 ) ;
F_89 ( V_2 ) ;
F_117 ( V_2 ) ;
F_23 ( V_2 -> V_125 ) ;
F_26 ( V_2 , L_24 ) ;
F_94 ( & V_2 -> V_24 ) ;
F_95 ( V_78 ) ;
return 0 ;
}
int F_118 ( void * V_58 , int V_180 )
{
struct V_1 * V_2 ;
int error ;
V_2 = F_3 ( V_58 ) ;
if ( ! V_2 )
return - V_9 ;
F_6 ( V_2 ) ;
F_97 ( & V_39 ) ;
error = F_106 ( V_2 , V_180 ) ;
if ( ! error )
V_38 -- ;
if ( ! V_38 )
F_68 () ;
F_98 ( & V_39 ) ;
return error ;
}
void F_119 ( void )
{
struct V_1 * V_2 ;
int V_187 ;
V_188:
V_187 = 0 ;
F_41 ( & V_41 ) ;
F_42 (ls, &lslist, ls_list) {
if ( ! F_85 ( V_189 , & V_2 -> V_12 ) ) {
V_187 ++ ;
continue;
}
F_44 ( & V_41 ) ;
F_29 ( V_2 , L_25 ) ;
F_4 ( V_2 ) ;
goto V_188;
}
F_44 ( & V_41 ) ;
if ( V_187 )
F_66 ( L_26 , V_187 ) ;
}
