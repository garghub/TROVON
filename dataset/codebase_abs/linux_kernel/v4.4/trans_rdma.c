static int F_1 ( char * V_1 , struct V_2 * V_3 )
{
char * V_4 ;
T_1 args [ V_5 ] ;
int V_6 ;
char * V_7 , * V_8 ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = V_12 ;
V_3 -> V_13 = V_14 ;
V_3 -> V_15 = V_16 ;
V_3 -> V_17 = 0 ;
if ( ! V_1 )
return 0 ;
V_8 = F_2 ( V_1 , V_18 ) ;
if ( ! V_8 ) {
F_3 ( V_19 ,
L_1 ) ;
return - V_20 ;
}
V_7 = V_8 ;
while ( ( V_4 = F_4 ( & V_7 , L_2 ) ) != NULL ) {
int V_21 ;
int V_22 ;
if ( ! * V_4 )
continue;
V_21 = F_5 ( V_4 , V_23 , args ) ;
if ( ( V_21 != V_24 ) && ( V_21 != V_25 ) ) {
V_22 = F_6 ( & args [ 0 ] , & V_6 ) ;
if ( V_22 < 0 ) {
F_3 ( V_19 ,
L_3 ) ;
continue;
}
}
switch ( V_21 ) {
case V_26 :
V_3 -> V_9 = V_6 ;
break;
case V_27 :
V_3 -> V_11 = V_6 ;
break;
case V_28 :
V_3 -> V_13 = V_6 ;
break;
case V_29 :
V_3 -> V_15 = V_6 ;
break;
case V_25 :
V_3 -> V_17 = 1 ;
break;
default:
continue;
}
}
V_3 -> V_13 = F_7 ( V_3 -> V_13 , V_3 -> V_11 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
static int
F_9 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_37 * V_38 = V_35 -> V_39 ;
switch ( V_33 -> V_33 ) {
case V_40 :
F_10 ( V_38 -> V_41 != V_42 ) ;
V_38 -> V_41 = V_43 ;
break;
case V_44 :
F_10 ( V_38 -> V_41 != V_43 ) ;
V_38 -> V_41 = V_45 ;
break;
case V_46 :
F_10 ( V_38 -> V_41 != V_45 ) ;
V_38 -> V_41 = V_47 ;
break;
case V_48 :
if ( V_38 )
V_38 -> V_41 = V_49 ;
if ( V_35 )
V_35 -> V_50 = V_51 ;
break;
case V_52 :
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_35 -> V_50 = V_51 ;
F_11 ( V_38 -> V_64 ) ;
break;
default:
F_12 () ;
}
F_13 ( & V_38 -> V_65 ) ;
return 0 ;
}
static void
F_14 ( struct V_34 * V_66 , struct V_37 * V_38 ,
struct V_67 * V_35 , enum V_68 V_50 , T_2 V_69 )
{
struct V_70 * V_71 ;
int V_72 = 0 ;
T_3 V_73 ;
V_71 = NULL ;
F_15 ( V_38 -> V_64 -> V_74 , V_35 -> V_75 , V_66 -> V_76 ,
V_77 ) ;
if ( V_50 != V_78 )
goto V_79;
V_72 = F_16 ( V_35 -> V_80 , NULL , NULL , & V_73 , 1 ) ;
if ( V_72 )
goto V_79;
V_71 = F_17 ( V_66 , V_73 ) ;
if ( ! V_71 )
goto V_79;
if ( F_18 ( V_71 -> V_80 ) ) {
F_19 ( L_4 , V_73 ) ;
goto V_79;
}
V_71 -> V_80 = V_35 -> V_80 ;
F_20 ( V_66 , V_71 , V_81 ) ;
return;
V_79:
F_3 ( V_19 , L_5 , V_71 , V_72 , V_50 ) ;
V_38 -> V_41 = V_82 ;
V_66 -> V_50 = V_51 ;
}
static void
F_21 ( struct V_34 * V_66 , struct V_37 * V_38 ,
struct V_67 * V_35 , enum V_68 V_50 , T_2 V_69 )
{
F_15 ( V_38 -> V_64 -> V_74 ,
V_35 -> V_75 , V_35 -> V_71 -> V_83 -> V_84 ,
V_85 ) ;
}
static void F_22 ( struct V_86 * V_33 , void * V_36 )
{
F_3 ( V_19 , L_6 ,
V_33 -> V_33 , V_36 ) ;
}
static void F_23 ( struct V_87 * V_88 , void * V_89 )
{
struct V_34 * V_66 = V_89 ;
struct V_37 * V_38 = V_66 -> V_39 ;
int V_90 ;
struct V_91 V_92 ;
F_24 ( V_38 -> V_88 , V_93 ) ;
while ( ( V_90 = F_25 ( V_88 , 1 , & V_92 ) ) > 0 ) {
struct V_67 * V_35 = ( void * ) ( unsigned long ) V_92 . V_94 ;
switch ( V_35 -> V_95 ) {
case V_96 :
F_14 ( V_66 , V_38 , V_35 , V_92 . V_50 , V_92 . V_69 ) ;
F_26 ( & V_38 -> V_97 ) ;
break;
case V_98 :
F_21 ( V_66 , V_38 , V_35 , V_92 . V_50 , V_92 . V_69 ) ;
F_26 ( & V_38 -> V_99 ) ;
break;
default:
F_19 ( L_7 ,
V_35 -> V_95 , V_92 . V_100 , V_92 . V_50 ) ;
break;
}
F_8 ( V_35 ) ;
}
}
static void F_27 ( struct V_86 * V_101 , void * V_102 )
{
F_3 ( V_19 , L_8 , V_101 -> V_33 , V_102 ) ;
}
static void F_28 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
if ( V_38 -> V_103 && ! F_29 ( V_38 -> V_103 ) )
F_30 ( V_38 -> V_103 ) ;
if ( V_38 -> V_104 && ! F_29 ( V_38 -> V_104 ) )
F_31 ( V_38 -> V_104 ) ;
if ( V_38 -> V_88 && ! F_29 ( V_38 -> V_88 ) )
F_32 ( V_38 -> V_88 ) ;
if ( V_38 -> V_64 && ! F_29 ( V_38 -> V_64 ) )
F_33 ( V_38 -> V_64 ) ;
F_8 ( V_38 ) ;
}
static int
F_34 ( struct V_34 * V_66 , struct V_67 * V_35 )
{
struct V_37 * V_38 = V_66 -> V_39 ;
struct V_105 V_106 , * V_107 ;
struct V_108 V_109 ;
V_35 -> V_75 = F_35 ( V_38 -> V_64 -> V_74 ,
V_35 -> V_80 -> V_110 , V_66 -> V_76 ,
V_77 ) ;
if ( F_36 ( V_38 -> V_64 -> V_74 , V_35 -> V_75 ) )
goto error;
V_109 . V_111 = V_35 -> V_75 ;
V_109 . V_112 = V_66 -> V_76 ;
V_109 . V_113 = V_38 -> V_104 -> V_114 ;
V_106 . V_115 = NULL ;
V_35 -> V_95 = V_96 ;
V_106 . V_94 = ( unsigned long ) V_35 ;
V_106 . V_116 = & V_109 ;
V_106 . V_117 = 1 ;
return F_37 ( V_38 -> V_103 , & V_106 , & V_107 ) ;
error:
F_3 ( V_19 , L_9 ) ;
return - V_118 ;
}
static int F_38 ( struct V_34 * V_66 , struct V_70 * V_71 )
{
struct V_37 * V_38 = V_66 -> V_39 ;
struct V_119 V_106 , * V_107 ;
struct V_108 V_109 ;
int V_72 = 0 ;
unsigned long V_120 ;
struct V_67 * V_35 = NULL ;
struct V_67 * V_121 = NULL ;
if ( F_18 ( F_39 ( & V_38 -> V_122 ) > 0 ) ) {
if ( ( F_40 ( 1 , & V_38 -> V_122 ) >= 0 ) ) {
F_8 ( V_71 -> V_80 ) ;
V_71 -> V_80 = NULL ;
goto V_123;
} else {
F_41 ( & V_38 -> V_122 ) ;
}
}
V_121 = F_42 ( sizeof *V_121 , V_124 ) ;
if ( ! V_121 ) {
V_72 = - V_20 ;
goto V_125;
}
V_121 -> V_80 = V_71 -> V_80 ;
if ( F_43 ( & V_38 -> V_97 ) ) {
V_72 = - V_126 ;
goto V_125;
}
V_72 = F_34 ( V_66 , V_121 ) ;
if ( V_72 ) {
F_3 ( V_127 , L_10 ) ;
goto V_125;
}
V_71 -> V_80 = NULL ;
V_123:
V_35 = F_42 ( sizeof *V_35 , V_124 ) ;
if ( ! V_35 ) {
V_72 = - V_20 ;
goto V_128;
}
V_35 -> V_71 = V_71 ;
V_35 -> V_75 = F_35 ( V_38 -> V_64 -> V_74 ,
V_35 -> V_71 -> V_83 -> V_110 , V_35 -> V_71 -> V_83 -> V_84 ,
V_85 ) ;
if ( F_36 ( V_38 -> V_64 -> V_74 , V_35 -> V_75 ) ) {
V_72 = - V_118 ;
goto V_128;
}
V_109 . V_111 = V_35 -> V_75 ;
V_109 . V_112 = V_35 -> V_71 -> V_83 -> V_84 ;
V_109 . V_113 = V_38 -> V_104 -> V_114 ;
V_106 . V_115 = NULL ;
V_35 -> V_95 = V_98 ;
V_106 . V_94 = ( unsigned long ) V_35 ;
V_106 . V_100 = V_129 ;
V_106 . V_130 = V_131 ;
V_106 . V_116 = & V_109 ;
V_106 . V_117 = 1 ;
if ( F_43 ( & V_38 -> V_99 ) ) {
V_72 = - V_126 ;
goto V_128;
}
V_71 -> V_50 = V_132 ;
V_72 = F_44 ( V_38 -> V_103 , & V_106 , & V_107 ) ;
if ( V_72 )
goto V_128;
return 0 ;
V_128:
V_71 -> V_50 = V_133 ;
F_8 ( V_35 ) ;
F_3 ( V_19 , L_11 , V_72 ) ;
F_41 ( & V_38 -> V_122 ) ;
return V_72 ;
V_125:
F_8 ( V_121 ) ;
F_45 ( & V_38 -> V_134 , V_120 ) ;
if ( V_38 -> V_41 < V_135 ) {
V_38 -> V_41 = V_135 ;
F_46 ( & V_38 -> V_134 , V_120 ) ;
F_11 ( V_38 -> V_64 ) ;
} else
F_46 ( & V_38 -> V_134 , V_120 ) ;
return V_72 ;
}
static void F_47 ( struct V_34 * V_66 )
{
struct V_37 * V_38 ;
if ( ! V_66 )
return;
V_38 = V_66 -> V_39 ;
if ( ! V_38 )
return;
V_66 -> V_50 = V_51 ;
F_11 ( V_38 -> V_64 ) ;
F_28 ( V_38 ) ;
}
static struct V_37 * F_48 ( struct V_2 * V_3 )
{
struct V_37 * V_38 ;
V_38 = F_49 ( sizeof( struct V_37 ) , V_18 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_11 = V_3 -> V_11 ;
V_38 -> V_13 = V_3 -> V_13 ;
V_38 -> V_15 = V_3 -> V_15 ;
F_50 ( & V_38 -> V_134 ) ;
F_51 ( & V_38 -> V_65 ) ;
F_52 ( & V_38 -> V_99 , V_38 -> V_11 ) ;
F_52 ( & V_38 -> V_97 , V_38 -> V_13 ) ;
F_53 ( & V_38 -> V_122 , 0 ) ;
return V_38 ;
}
static int F_54 ( struct V_34 * V_66 , struct V_70 * V_71 )
{
return 1 ;
}
static int F_55 ( struct V_34 * V_66 , struct V_70 * V_71 )
{
struct V_37 * V_38 = V_66 -> V_39 ;
F_41 ( & V_38 -> V_122 ) ;
return 0 ;
}
static int F_56 ( struct V_37 * V_38 )
{
struct V_136 V_137 = {
. V_138 = V_139 ,
. V_140 . V_141 = F_57 ( V_142 ) ,
} ;
int V_9 , V_72 = - V_143 ;
for ( V_9 = V_144 ; V_9 >= V_145 ; V_9 -- ) {
V_137 . V_146 = F_58 ( ( V_147 ) V_9 ) ;
V_72 = F_59 ( V_38 -> V_64 , (struct V_148 * ) & V_137 ) ;
if ( V_72 != - V_149 )
break;
}
return V_72 ;
}
static int
F_60 ( struct V_34 * V_66 , const char * V_111 , char * args )
{
int V_72 ;
struct V_2 V_3 ;
struct V_37 * V_38 ;
struct V_150 V_151 ;
struct V_152 V_153 ;
struct V_154 V_155 = {} ;
V_72 = F_1 ( args , & V_3 ) ;
if ( V_72 < 0 )
return V_72 ;
V_38 = F_48 ( & V_3 ) ;
if ( ! V_38 )
return - V_20 ;
V_38 -> V_64 = F_61 ( & V_156 , F_9 , V_66 ,
V_157 , V_158 ) ;
if ( F_29 ( V_38 -> V_64 ) )
goto error;
V_66 -> V_39 = V_38 ;
if ( V_3 . V_17 ) {
V_72 = F_56 ( V_38 ) ;
if ( V_72 < 0 ) {
F_19 ( L_12 ,
V_159 , F_62 ( V_160 ) , - V_72 ) ;
goto error;
}
}
V_38 -> V_111 . V_138 = V_139 ;
V_38 -> V_111 . V_140 . V_141 = F_63 ( V_111 ) ;
V_38 -> V_111 . V_146 = F_58 ( V_3 . V_9 ) ;
V_72 = F_64 ( V_38 -> V_64 , NULL ,
(struct V_148 * ) & V_38 -> V_111 ,
V_38 -> V_15 ) ;
if ( V_72 )
goto error;
V_72 = F_65 ( & V_38 -> V_65 ) ;
if ( V_72 || ( V_38 -> V_41 != V_43 ) )
goto error;
V_72 = F_66 ( V_38 -> V_64 , V_38 -> V_15 ) ;
if ( V_72 )
goto error;
V_72 = F_65 ( & V_38 -> V_65 ) ;
if ( V_72 || ( V_38 -> V_41 != V_45 ) )
goto error;
V_155 . V_161 = V_3 . V_11 + V_3 . V_13 + 1 ;
V_38 -> V_88 = F_67 ( V_38 -> V_64 -> V_74 , F_23 ,
F_27 , V_66 ,
& V_155 ) ;
if ( F_29 ( V_38 -> V_88 ) )
goto error;
F_24 ( V_38 -> V_88 , V_93 ) ;
V_38 -> V_104 = F_68 ( V_38 -> V_64 -> V_74 ) ;
if ( F_29 ( V_38 -> V_104 ) )
goto error;
memset ( & V_153 , 0 , sizeof V_153 ) ;
V_153 . V_162 = F_22 ;
V_153 . V_163 = V_66 ;
V_153 . V_164 . V_165 = V_3 . V_11 ;
V_153 . V_164 . V_166 = V_3 . V_13 ;
V_153 . V_164 . V_167 = V_168 ;
V_153 . V_164 . V_169 = V_170 ;
V_153 . V_171 = V_172 ;
V_153 . V_173 = V_158 ;
V_153 . V_174 = V_38 -> V_88 ;
V_153 . V_175 = V_38 -> V_88 ;
V_72 = F_69 ( V_38 -> V_64 , V_38 -> V_104 , & V_153 ) ;
if ( V_72 )
goto error;
V_38 -> V_103 = V_38 -> V_64 -> V_103 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_176 = NULL ;
V_151 . V_177 = 0 ;
V_151 . V_178 = V_179 ;
V_151 . V_180 = V_181 ;
V_72 = F_70 ( V_38 -> V_64 , & V_151 ) ;
if ( V_72 )
goto error;
V_72 = F_65 ( & V_38 -> V_65 ) ;
if ( V_72 || ( V_38 -> V_41 != V_47 ) )
goto error;
V_66 -> V_50 = V_182 ;
return 0 ;
error:
F_28 ( V_38 ) ;
return - V_183 ;
}
static int T_4 F_71 ( void )
{
F_72 ( & V_184 ) ;
return 0 ;
}
static void T_5 F_73 ( void )
{
F_74 ( & V_184 ) ;
}
