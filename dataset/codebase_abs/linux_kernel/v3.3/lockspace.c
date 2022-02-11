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
T_3 V_15 = F_14 ( V_2 ) ;
return snprintf ( V_3 , V_13 , L_2 , V_15 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_13 , L_3 , V_2 -> V_16 ) ;
}
static T_1 F_16 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_3 )
{
struct V_1 * V_2 = F_17 ( V_18 , struct V_1 , V_21 ) ;
struct V_22 * V_23 = F_17 ( V_20 , struct V_22 , V_20 ) ;
return V_23 -> V_24 ? V_23 -> V_24 ( V_2 , V_3 ) : 0 ;
}
static T_1 F_18 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_3 , T_2 V_4 )
{
struct V_1 * V_2 = F_17 ( V_18 , struct V_1 , V_21 ) ;
struct V_22 * V_23 = F_17 ( V_20 , struct V_22 , V_20 ) ;
return V_23 -> V_25 ? V_23 -> V_25 ( V_2 , V_3 , V_4 ) : V_4 ;
}
static void F_19 ( struct V_17 * V_26 )
{
struct V_1 * V_2 = F_17 ( V_26 , struct V_1 , V_21 ) ;
F_20 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_27 )
{
int error ;
if ( V_27 )
F_22 ( & V_2 -> V_21 , V_28 ) ;
else
F_22 ( & V_2 -> V_21 , V_29 ) ;
F_23 ( V_2 , L_4 , V_27 ? L_5 : L_6 ) ;
error = F_24 ( V_2 -> V_12 ,
F_25 ( V_10 , & V_2 -> V_11 ) ) ;
F_23 ( V_2 , L_7 , error , V_2 -> V_9 ) ;
if ( error )
goto V_30;
error = V_2 -> V_9 ;
V_30:
if ( error )
F_26 ( V_2 , L_8 , V_27 ? L_9 : L_10 ,
error , V_2 -> V_9 ) ;
return error ;
}
static int F_27 ( struct V_31 * V_31 , struct V_17 * V_18 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_17 ( V_18 , struct V_1 , V_21 ) ;
F_28 ( V_33 , L_11 , V_2 -> V_34 ) ;
return 0 ;
}
int T_4 F_29 ( void )
{
V_35 = 0 ;
F_30 ( & V_36 ) ;
F_31 ( & V_37 ) ;
F_32 ( & V_38 ) ;
V_39 = F_33 ( L_12 , & V_40 , V_41 ) ;
if ( ! V_39 ) {
F_34 ( V_42 L_13 , V_43 ) ;
return - V_44 ;
}
return 0 ;
}
void F_35 ( void )
{
F_36 ( V_39 ) ;
}
static struct V_1 * F_37 ( void )
{
struct V_1 * V_2 ;
F_38 ( & V_38 ) ;
F_39 (ls, &lslist, ls_list) {
if ( F_40 ( V_45 , V_2 -> V_46 +
V_47 . V_48 * V_49 ) ) {
F_41 ( & V_38 ) ;
return V_2 ;
}
}
F_41 ( & V_38 ) ;
return NULL ;
}
static int F_42 ( void * V_50 )
{
struct V_1 * V_2 ;
while ( ! F_43 () ) {
V_2 = F_37 () ;
if ( V_2 ) {
if ( F_44 ( V_2 ) ) {
V_2 -> V_46 = V_45 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
} else {
V_2 -> V_46 += V_49 ;
}
continue;
}
F_49 ( V_47 . V_48 * V_49 ) ;
}
return 0 ;
}
static int F_50 ( void )
{
struct V_51 * V_52 ;
int error = 0 ;
V_52 = F_51 ( F_42 , NULL , L_14 ) ;
if ( F_52 ( V_52 ) )
error = F_53 ( V_52 ) ;
else
V_53 = V_52 ;
return error ;
}
static void F_54 ( void )
{
F_55 ( V_53 ) ;
}
struct V_1 * F_56 ( T_3 V_54 )
{
struct V_1 * V_2 ;
F_38 ( & V_38 ) ;
F_39 (ls, &lslist, ls_list) {
if ( V_2 -> V_14 == V_54 ) {
V_2 -> V_35 ++ ;
goto V_30;
}
}
V_2 = NULL ;
V_30:
F_41 ( & V_38 ) ;
return V_2 ;
}
struct V_1 * F_3 ( T_5 * V_55 )
{
struct V_1 * V_2 ;
F_38 ( & V_38 ) ;
F_39 (ls, &lslist, ls_list) {
if ( V_2 -> V_7 == V_55 ) {
V_2 -> V_35 ++ ;
goto V_30;
}
}
V_2 = NULL ;
V_30:
F_41 ( & V_38 ) ;
return V_2 ;
}
struct V_1 * F_57 ( int V_56 )
{
struct V_1 * V_2 ;
F_38 ( & V_38 ) ;
F_39 (ls, &lslist, ls_list) {
if ( V_2 -> V_57 . V_56 == V_56 ) {
V_2 -> V_35 ++ ;
goto V_30;
}
}
V_2 = NULL ;
V_30:
F_41 ( & V_38 ) ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_38 ( & V_38 ) ;
V_2 -> V_35 -- ;
F_41 ( & V_38 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
for (; ; ) {
F_38 ( & V_38 ) ;
if ( V_2 -> V_35 == 0 ) {
F_59 ( V_2 -> V_58 != 0 ) ;
F_60 ( & V_2 -> V_59 ) ;
F_41 ( & V_38 ) ;
return;
}
F_41 ( & V_38 ) ;
F_61 ( 1 ) ;
}
}
static int F_62 ( void )
{
int error ;
error = F_50 () ;
if ( error ) {
F_63 ( L_15 , error ) ;
goto V_60;
}
error = F_64 () ;
if ( error ) {
F_63 ( L_16 , error ) ;
goto V_61;
}
return 0 ;
V_61:
F_54 () ;
V_60:
return error ;
}
static void F_65 ( void )
{
F_54 () ;
F_66 () ;
}
static int F_67 ( const char * V_62 , const char * V_63 ,
T_3 V_64 , int V_65 ,
const struct V_66 * V_67 , void * V_68 ,
int * V_69 , T_5 * * V_55 )
{
struct V_1 * V_2 ;
int V_70 , V_71 , error ;
int V_72 = 0 ;
int V_73 = strlen ( V_62 ) ;
if ( V_73 > V_74 )
return - V_8 ;
if ( ! V_65 || ( V_65 % 8 ) )
return - V_8 ;
if ( ! F_68 ( V_75 ) )
return - V_8 ;
if ( ! F_69 () ) {
F_63 ( L_17 ) ;
error = - V_76 ;
goto V_30;
}
if ( V_67 && V_69 ) {
if ( ! V_47 . V_77 )
* V_69 = - V_78 ;
else
* V_69 = 0 ;
}
if ( V_47 . V_77 && V_63 &&
strncmp ( V_63 , V_47 . V_79 , V_74 ) ) {
F_63 ( L_18 ,
V_47 . V_79 , V_63 ) ;
error = - V_80 ;
goto V_30;
}
error = 0 ;
F_38 ( & V_38 ) ;
F_39 (ls, &lslist, ls_list) {
F_59 ( V_2 -> V_58 <= 0 ) ;
if ( V_2 -> V_81 != V_73 )
continue;
if ( memcmp ( V_2 -> V_34 , V_62 , V_73 ) )
continue;
if ( V_64 & V_82 ) {
error = - V_83 ;
break;
}
V_2 -> V_58 ++ ;
* V_55 = V_2 ;
error = 1 ;
break;
}
F_41 ( & V_38 ) ;
if ( error )
goto V_30;
error = - V_44 ;
V_2 = F_70 ( sizeof( struct V_1 ) + V_73 , V_84 ) ;
if ( ! V_2 )
goto V_30;
memcpy ( V_2 -> V_34 , V_62 , V_73 ) ;
V_2 -> V_81 = V_73 ;
V_2 -> V_85 = V_65 ;
V_2 -> V_35 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_46 = V_45 ;
if ( V_67 && V_47 . V_77 ) {
V_2 -> V_86 = V_67 ;
V_2 -> V_87 = V_68 ;
}
if ( V_64 & V_88 )
F_8 ( V_89 , & V_2 -> V_11 ) ;
V_2 -> V_90 = ( V_64 & ~ ( V_88 | V_91 |
V_82 ) ) ;
V_71 = V_47 . V_92 ;
V_2 -> V_93 = V_71 ;
V_2 -> V_94 = F_71 ( sizeof( struct V_95 ) * V_71 ) ;
if ( ! V_2 -> V_94 )
goto V_96;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
V_2 -> V_94 [ V_70 ] . V_97 . V_98 = NULL ;
V_2 -> V_94 [ V_70 ] . V_99 . V_98 = NULL ;
F_32 ( & V_2 -> V_94 [ V_70 ] . V_100 ) ;
}
F_72 ( & V_2 -> V_101 ) ;
F_32 ( & V_2 -> V_102 ) ;
V_71 = V_47 . V_103 ;
V_2 -> V_104 = V_71 ;
V_2 -> V_105 = F_71 ( sizeof( struct V_106 ) * V_71 ) ;
if ( ! V_2 -> V_105 )
goto V_107;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
F_31 ( & V_2 -> V_105 [ V_70 ] . V_108 ) ;
F_32 ( & V_2 -> V_105 [ V_70 ] . V_100 ) ;
}
F_31 ( & V_2 -> V_109 ) ;
F_30 ( & V_2 -> V_110 ) ;
F_31 ( & V_2 -> V_111 ) ;
F_30 ( & V_2 -> V_112 ) ;
F_31 ( & V_2 -> V_113 ) ;
F_30 ( & V_2 -> V_114 ) ;
F_31 ( & V_2 -> V_115 ) ;
F_32 ( & V_2 -> V_116 ) ;
F_31 ( & V_2 -> V_117 ) ;
F_31 ( & V_2 -> V_118 ) ;
V_2 -> V_119 = 0 ;
V_2 -> V_120 = 0 ;
V_2 -> V_121 = 0 ;
V_2 -> V_122 = NULL ;
memset ( & V_2 -> V_123 , 0 , sizeof( struct V_124 ) ) ;
V_2 -> V_123 . V_125 = V_2 ;
V_2 -> V_126 = NULL ;
V_2 -> V_127 = NULL ;
F_73 ( & V_2 -> V_12 ) ;
V_2 -> V_9 = 0 ;
F_74 ( & V_2 -> V_128 ) ;
V_2 -> V_129 = - 1 ;
F_30 ( & V_2 -> V_130 ) ;
F_31 ( & V_2 -> V_131 ) ;
V_2 -> V_132 = NULL ;
F_30 ( & V_2 -> V_133 ) ;
F_32 ( & V_2 -> V_134 ) ;
F_32 ( & V_2 -> V_135 ) ;
F_75 ( & V_2 -> V_136 , sizeof( V_137 ) ) ;
V_2 -> V_138 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_140 = NULL ;
F_76 ( & V_2 -> V_141 ) ;
F_76 ( & V_2 -> V_142 ) ;
F_31 ( & V_2 -> V_143 ) ;
F_30 ( & V_2 -> V_144 ) ;
F_30 ( & V_2 -> V_145 ) ;
V_2 -> V_146 = F_77 ( V_47 . V_147 , V_84 ) ;
if ( ! V_2 -> V_146 )
goto V_148;
V_2 -> V_149 = 0 ;
V_2 -> V_150 = 0 ;
V_2 -> V_151 = 0 ;
V_2 -> V_152 = NULL ;
F_31 ( & V_2 -> V_153 ) ;
F_32 ( & V_2 -> V_154 ) ;
V_2 -> V_155 = 0 ;
V_2 -> V_7 = V_2 ;
F_73 ( & V_2 -> V_156 ) ;
F_31 ( & V_2 -> V_157 ) ;
F_76 ( & V_2 -> V_158 ) ;
F_78 ( & V_2 -> V_141 ) ;
F_38 ( & V_38 ) ;
V_2 -> V_58 = 1 ;
F_79 ( & V_2 -> V_59 , & V_37 ) ;
F_41 ( & V_38 ) ;
if ( V_64 & V_91 ) {
error = F_80 ( V_2 ) ;
if ( error ) {
F_26 ( V_2 , L_19 , error ) ;
goto V_159;
}
}
error = F_81 ( V_2 ) ;
if ( error ) {
F_26 ( V_2 , L_20 , error ) ;
goto V_160;
}
V_2 -> V_21 . V_31 = V_39 ;
error = F_82 ( & V_2 -> V_21 , & V_161 , NULL ,
L_21 , V_2 -> V_34 ) ;
if ( error )
goto V_162;
F_22 ( & V_2 -> V_21 , V_163 ) ;
V_72 = 1 ;
error = F_21 ( V_2 , 1 ) ;
if ( error )
goto V_162;
F_83 ( & V_2 -> V_128 ) ;
error = V_2 -> V_129 ;
if ( error )
goto V_164;
F_84 ( V_2 ) ;
F_23 ( V_2 , L_22 ) ;
* V_55 = V_2 ;
return 0 ;
V_164:
F_21 ( V_2 , 0 ) ;
F_85 ( V_2 ) ;
F_20 ( V_2 -> V_122 ) ;
V_162:
F_86 ( V_2 ) ;
V_160:
F_87 ( V_2 ) ;
V_159:
F_38 ( & V_38 ) ;
F_60 ( & V_2 -> V_59 ) ;
F_41 ( & V_38 ) ;
F_20 ( V_2 -> V_146 ) ;
V_148:
F_88 ( V_2 -> V_105 ) ;
V_107:
F_89 ( & V_2 -> V_101 ) ;
F_88 ( V_2 -> V_94 ) ;
V_96:
if ( V_72 )
F_90 ( & V_2 -> V_21 ) ;
else
F_20 ( V_2 ) ;
V_30:
F_91 ( V_75 ) ;
return error ;
}
int F_92 ( const char * V_62 , const char * V_63 ,
T_3 V_64 , int V_65 ,
const struct V_66 * V_67 , void * V_68 ,
int * V_69 , T_5 * * V_55 )
{
int error = 0 ;
F_93 ( & V_36 ) ;
if ( ! V_35 )
error = F_62 () ;
if ( error )
goto V_30;
error = F_67 ( V_62 , V_63 , V_64 , V_65 , V_67 , V_68 ,
V_69 , V_55 ) ;
if ( ! error )
V_35 ++ ;
if ( error > 0 )
error = 0 ;
if ( ! V_35 )
F_65 () ;
V_30:
F_94 ( & V_36 ) ;
return error ;
}
static int F_95 ( int V_54 , void * V_52 , void * V_50 )
{
struct V_165 * V_166 = V_52 ;
if ( ! V_166 -> V_167 )
return 1 ;
return 0 ;
}
static int F_96 ( int V_54 , void * V_52 , void * V_50 )
{
return 1 ;
}
static int F_97 ( int V_54 , void * V_52 , void * V_50 )
{
struct V_165 * V_166 = V_52 ;
if ( V_166 -> V_168 && V_166 -> V_169 & V_170 )
F_98 ( V_166 -> V_168 ) ;
F_99 ( V_166 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , int V_171 )
{
int V_172 ;
F_38 ( & V_2 -> V_102 ) ;
if ( V_171 == 0 ) {
V_172 = F_101 ( & V_2 -> V_101 , F_96 , V_2 ) ;
} else if ( V_171 == 1 ) {
V_172 = F_101 ( & V_2 -> V_101 , F_95 , V_2 ) ;
} else {
V_172 = 0 ;
}
F_41 ( & V_2 -> V_102 ) ;
return V_172 ;
}
static int F_102 ( struct V_1 * V_2 , int V_171 )
{
struct V_124 * V_173 ;
struct V_98 * V_6 ;
int V_70 , V_174 , V_172 ;
V_174 = F_100 ( V_2 , V_171 ) ;
F_38 ( & V_38 ) ;
if ( V_2 -> V_58 == 1 ) {
if ( V_174 ) {
V_172 = - V_175 ;
} else {
V_2 -> V_58 = 0 ;
V_172 = 0 ;
}
} else if ( V_2 -> V_58 > 1 ) {
V_172 = -- V_2 -> V_58 ;
} else {
V_172 = - V_8 ;
}
F_41 ( & V_38 ) ;
if ( V_172 ) {
F_23 ( V_2 , L_23 , V_172 ) ;
return V_172 ;
}
F_103 ( V_2 ) ;
if ( V_171 < 3 && F_69 () )
F_21 ( V_2 , 0 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
F_58 ( V_2 ) ;
F_104 ( V_2 ) ;
F_20 ( V_2 -> V_146 ) ;
F_105 ( V_2 ) ;
F_88 ( V_2 -> V_105 ) ;
F_101 ( & V_2 -> V_101 , F_97 , V_2 ) ;
F_106 ( & V_2 -> V_101 ) ;
F_89 ( & V_2 -> V_101 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_93 ; V_70 ++ ) {
while ( ( V_6 = F_107 ( & V_2 -> V_94 [ V_70 ] . V_97 ) ) ) {
V_173 = F_108 ( V_6 , struct V_124 , V_176 ) ;
F_109 ( V_6 , & V_2 -> V_94 [ V_70 ] . V_97 ) ;
F_110 ( V_173 ) ;
}
while ( ( V_6 = F_107 ( & V_2 -> V_94 [ V_70 ] . V_99 ) ) ) {
V_173 = F_108 ( V_6 , struct V_124 , V_176 ) ;
F_109 ( V_6 , & V_2 -> V_94 [ V_70 ] . V_99 ) ;
F_110 ( V_173 ) ;
}
}
F_88 ( V_2 -> V_94 ) ;
while ( ! F_111 ( & V_2 -> V_115 ) ) {
V_173 = F_112 ( & V_2 -> V_115 , struct V_124 ,
V_177 ) ;
F_60 ( & V_173 -> V_177 ) ;
F_110 ( V_173 ) ;
}
F_113 ( V_2 ) ;
F_20 ( V_2 -> V_140 ) ;
F_114 ( V_2 ) ;
F_85 ( V_2 ) ;
F_115 ( V_2 ) ;
F_20 ( V_2 -> V_122 ) ;
F_23 ( V_2 , L_24 ) ;
F_90 ( & V_2 -> V_21 ) ;
F_91 ( V_75 ) ;
return 0 ;
}
int F_116 ( void * V_55 , int V_171 )
{
struct V_1 * V_2 ;
int error ;
V_2 = F_3 ( V_55 ) ;
if ( ! V_2 )
return - V_8 ;
F_6 ( V_2 ) ;
F_93 ( & V_36 ) ;
error = F_102 ( V_2 , V_171 ) ;
if ( ! error )
V_35 -- ;
if ( ! V_35 )
F_65 () ;
F_94 ( & V_36 ) ;
return error ;
}
void F_117 ( void )
{
struct V_1 * V_2 ;
V_178:
F_38 ( & V_38 ) ;
F_39 (ls, &lslist, ls_list) {
if ( ! F_118 ( V_179 , & V_2 -> V_11 ) )
continue;
F_41 ( & V_38 ) ;
F_26 ( V_2 , L_25 ) ;
F_4 ( V_2 ) ;
goto V_178;
}
F_41 ( & V_38 ) ;
}
