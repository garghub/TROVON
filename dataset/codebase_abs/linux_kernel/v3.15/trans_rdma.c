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
if ( ! V_1 )
return 0 ;
V_8 = F_2 ( V_1 , V_17 ) ;
if ( ! V_8 ) {
F_3 ( V_18 ,
L_1 ) ;
return - V_19 ;
}
V_7 = V_8 ;
while ( ( V_4 = F_4 ( & V_7 , L_2 ) ) != NULL ) {
int V_20 ;
int V_21 ;
if ( ! * V_4 )
continue;
V_20 = F_5 ( V_4 , V_22 , args ) ;
if ( V_20 == V_23 )
continue;
V_21 = F_6 ( & args [ 0 ] , & V_6 ) ;
if ( V_21 < 0 ) {
F_3 ( V_18 ,
L_3 ) ;
continue;
}
switch ( V_20 ) {
case V_24 :
V_3 -> V_9 = V_6 ;
break;
case V_25 :
V_3 -> V_11 = V_6 ;
break;
case V_26 :
V_3 -> V_13 = V_6 ;
break;
case V_27 :
V_3 -> V_15 = V_6 ;
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
F_9 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
struct V_32 * V_33 = V_29 -> V_34 ;
struct V_35 * V_36 = V_33 -> V_37 ;
switch ( V_31 -> V_31 ) {
case V_38 :
F_10 ( V_36 -> V_39 != V_40 ) ;
V_36 -> V_39 = V_41 ;
break;
case V_42 :
F_10 ( V_36 -> V_39 != V_41 ) ;
V_36 -> V_39 = V_43 ;
break;
case V_44 :
F_10 ( V_36 -> V_39 != V_43 ) ;
V_36 -> V_39 = V_45 ;
break;
case V_46 :
if ( V_36 )
V_36 -> V_39 = V_47 ;
if ( V_33 )
V_33 -> V_48 = V_49 ;
break;
case V_50 :
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
V_33 -> V_48 = V_49 ;
F_11 ( V_36 -> V_62 ) ;
break;
default:
F_12 () ;
}
F_13 ( & V_36 -> V_63 ) ;
return 0 ;
}
static void
F_14 ( struct V_32 * V_64 , struct V_35 * V_36 ,
struct V_65 * V_33 , enum V_66 V_48 , T_2 V_67 )
{
struct V_68 * V_69 ;
int V_70 = 0 ;
T_3 V_71 ;
V_69 = NULL ;
F_15 ( V_36 -> V_62 -> V_72 , V_33 -> V_73 , V_64 -> V_74 ,
V_75 ) ;
if ( V_48 != V_76 )
goto V_77;
V_70 = F_16 ( V_33 -> V_78 , NULL , NULL , & V_71 , 1 ) ;
if ( V_70 )
goto V_77;
V_69 = F_17 ( V_64 , V_71 ) ;
if ( ! V_69 )
goto V_77;
if ( F_18 ( V_69 -> V_78 ) ) {
F_19 ( L_4 , V_71 ) ;
goto V_77;
}
V_69 -> V_78 = V_33 -> V_78 ;
F_20 ( V_64 , V_69 , V_79 ) ;
return;
V_77:
F_3 ( V_18 , L_5 , V_69 , V_70 , V_48 ) ;
V_36 -> V_39 = V_80 ;
V_64 -> V_48 = V_49 ;
}
static void
F_21 ( struct V_32 * V_64 , struct V_35 * V_36 ,
struct V_65 * V_33 , enum V_66 V_48 , T_2 V_67 )
{
F_15 ( V_36 -> V_62 -> V_72 ,
V_33 -> V_73 , V_33 -> V_69 -> V_81 -> V_82 ,
V_83 ) ;
}
static void F_22 ( struct V_84 * V_31 , void * V_34 )
{
F_3 ( V_18 , L_6 ,
V_31 -> V_31 , V_34 ) ;
}
static void F_23 ( struct V_85 * V_86 , void * V_87 )
{
struct V_32 * V_64 = V_87 ;
struct V_35 * V_36 = V_64 -> V_37 ;
int V_88 ;
struct V_89 V_90 ;
F_24 ( V_36 -> V_86 , V_91 ) ;
while ( ( V_88 = F_25 ( V_86 , 1 , & V_90 ) ) > 0 ) {
struct V_65 * V_33 = ( void * ) ( unsigned long ) V_90 . V_92 ;
switch ( V_33 -> V_93 ) {
case V_94 :
F_14 ( V_64 , V_36 , V_33 , V_90 . V_48 , V_90 . V_67 ) ;
F_26 ( & V_36 -> V_95 ) ;
break;
case V_96 :
F_21 ( V_64 , V_36 , V_33 , V_90 . V_48 , V_90 . V_67 ) ;
F_26 ( & V_36 -> V_97 ) ;
break;
default:
F_19 ( L_7 ,
V_33 -> V_93 , V_90 . V_98 , V_90 . V_48 ) ;
break;
}
F_8 ( V_33 ) ;
}
}
static void F_27 ( struct V_84 * V_99 , void * V_100 )
{
F_3 ( V_18 , L_8 , V_99 -> V_31 , V_100 ) ;
}
static void F_28 ( struct V_35 * V_36 )
{
if ( ! V_36 )
return;
if ( V_36 -> V_101 && ! F_29 ( V_36 -> V_101 ) )
F_30 ( V_36 -> V_101 ) ;
if ( V_36 -> V_102 && ! F_29 ( V_36 -> V_102 ) )
F_31 ( V_36 -> V_102 ) ;
if ( V_36 -> V_103 && ! F_29 ( V_36 -> V_103 ) )
F_32 ( V_36 -> V_103 ) ;
if ( V_36 -> V_86 && ! F_29 ( V_36 -> V_86 ) )
F_33 ( V_36 -> V_86 ) ;
if ( V_36 -> V_62 && ! F_29 ( V_36 -> V_62 ) )
F_34 ( V_36 -> V_62 ) ;
F_8 ( V_36 ) ;
}
static int
F_35 ( struct V_32 * V_64 , struct V_65 * V_33 )
{
struct V_35 * V_36 = V_64 -> V_37 ;
struct V_104 V_105 , * V_106 ;
struct V_107 V_108 ;
V_33 -> V_73 = F_36 ( V_36 -> V_62 -> V_72 ,
V_33 -> V_78 -> V_109 , V_64 -> V_74 ,
V_75 ) ;
if ( F_37 ( V_36 -> V_62 -> V_72 , V_33 -> V_73 ) )
goto error;
V_108 . V_110 = V_33 -> V_73 ;
V_108 . V_111 = V_64 -> V_74 ;
V_108 . V_112 = V_36 -> V_112 ;
V_105 . V_113 = NULL ;
V_33 -> V_93 = V_94 ;
V_105 . V_92 = ( unsigned long ) V_33 ;
V_105 . V_114 = & V_108 ;
V_105 . V_115 = 1 ;
return F_38 ( V_36 -> V_102 , & V_105 , & V_106 ) ;
error:
F_3 ( V_18 , L_9 ) ;
return - V_116 ;
}
static int F_39 ( struct V_32 * V_64 , struct V_68 * V_69 )
{
struct V_35 * V_36 = V_64 -> V_37 ;
struct V_117 V_105 , * V_106 ;
struct V_107 V_108 ;
int V_70 = 0 ;
unsigned long V_118 ;
struct V_65 * V_33 = NULL ;
struct V_65 * V_119 = NULL ;
if ( F_18 ( F_40 ( & V_36 -> V_120 ) > 0 ) ) {
if ( ( F_41 ( 1 , & V_36 -> V_120 ) >= 0 ) ) {
F_8 ( V_69 -> V_78 ) ;
V_69 -> V_78 = NULL ;
goto V_121;
} else {
F_42 ( & V_36 -> V_120 ) ;
}
}
V_119 = F_43 ( sizeof *V_119 , V_122 ) ;
if ( ! V_119 ) {
V_70 = - V_19 ;
goto V_123;
}
V_119 -> V_78 = V_69 -> V_78 ;
if ( F_44 ( & V_36 -> V_95 ) ) {
V_70 = - V_124 ;
goto V_123;
}
V_70 = F_35 ( V_64 , V_119 ) ;
if ( V_70 ) {
F_3 ( V_125 , L_10 ) ;
goto V_123;
}
V_69 -> V_78 = NULL ;
V_121:
V_33 = F_43 ( sizeof *V_33 , V_122 ) ;
if ( ! V_33 ) {
V_70 = - V_19 ;
goto V_126;
}
V_33 -> V_69 = V_69 ;
V_33 -> V_73 = F_36 ( V_36 -> V_62 -> V_72 ,
V_33 -> V_69 -> V_81 -> V_109 , V_33 -> V_69 -> V_81 -> V_82 ,
V_83 ) ;
if ( F_37 ( V_36 -> V_62 -> V_72 , V_33 -> V_73 ) ) {
V_70 = - V_116 ;
goto V_126;
}
V_108 . V_110 = V_33 -> V_73 ;
V_108 . V_111 = V_33 -> V_69 -> V_81 -> V_82 ;
V_108 . V_112 = V_36 -> V_112 ;
V_105 . V_113 = NULL ;
V_33 -> V_93 = V_96 ;
V_105 . V_92 = ( unsigned long ) V_33 ;
V_105 . V_98 = V_127 ;
V_105 . V_128 = V_129 ;
V_105 . V_114 = & V_108 ;
V_105 . V_115 = 1 ;
if ( F_44 ( & V_36 -> V_97 ) ) {
V_70 = - V_124 ;
goto V_126;
}
V_69 -> V_48 = V_130 ;
V_70 = F_45 ( V_36 -> V_102 , & V_105 , & V_106 ) ;
if ( V_70 )
goto V_126;
return 0 ;
V_126:
V_69 -> V_48 = V_131 ;
F_8 ( V_33 ) ;
F_3 ( V_18 , L_11 , V_70 ) ;
F_42 ( & V_36 -> V_120 ) ;
return V_70 ;
V_123:
F_8 ( V_119 ) ;
F_46 ( & V_36 -> V_132 , V_118 ) ;
if ( V_36 -> V_39 < V_133 ) {
V_36 -> V_39 = V_133 ;
F_47 ( & V_36 -> V_132 , V_118 ) ;
F_11 ( V_36 -> V_62 ) ;
} else
F_47 ( & V_36 -> V_132 , V_118 ) ;
return V_70 ;
}
static void F_48 ( struct V_32 * V_64 )
{
struct V_35 * V_36 ;
if ( ! V_64 )
return;
V_36 = V_64 -> V_37 ;
if ( ! V_36 )
return;
V_64 -> V_48 = V_49 ;
F_11 ( V_36 -> V_62 ) ;
F_28 ( V_36 ) ;
}
static struct V_35 * F_49 ( struct V_2 * V_3 )
{
struct V_35 * V_36 ;
V_36 = F_50 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_11 = V_3 -> V_11 ;
V_36 -> V_13 = V_3 -> V_13 ;
V_36 -> V_15 = V_3 -> V_15 ;
F_51 ( & V_36 -> V_132 ) ;
F_52 ( & V_36 -> V_63 ) ;
F_53 ( & V_36 -> V_97 , V_36 -> V_11 ) ;
F_53 ( & V_36 -> V_95 , V_36 -> V_13 ) ;
F_54 ( & V_36 -> V_120 , 0 ) ;
return V_36 ;
}
static int F_55 ( struct V_32 * V_64 , struct V_68 * V_69 )
{
return 1 ;
}
static int F_56 ( struct V_32 * V_64 , struct V_68 * V_69 )
{
struct V_35 * V_36 = V_64 -> V_37 ;
F_42 ( & V_36 -> V_120 ) ;
return 0 ;
}
static int
F_57 ( struct V_32 * V_64 , const char * V_110 , char * args )
{
int V_70 ;
struct V_2 V_3 ;
struct V_35 * V_36 ;
struct V_134 V_135 ;
struct V_136 V_137 ;
struct V_138 V_139 ;
V_70 = F_1 ( args , & V_3 ) ;
if ( V_70 < 0 )
return V_70 ;
V_36 = F_49 ( & V_3 ) ;
if ( ! V_36 )
return - V_19 ;
V_36 -> V_62 = F_58 ( F_9 , V_64 , V_140 ,
V_141 ) ;
if ( F_29 ( V_36 -> V_62 ) )
goto error;
V_64 -> V_37 = V_36 ;
V_36 -> V_110 . V_142 = V_143 ;
V_36 -> V_110 . V_144 . V_145 = F_59 ( V_110 ) ;
V_36 -> V_110 . V_146 = F_60 ( V_3 . V_9 ) ;
V_70 = F_61 ( V_36 -> V_62 , NULL ,
(struct V_147 * ) & V_36 -> V_110 ,
V_36 -> V_15 ) ;
if ( V_70 )
goto error;
V_70 = F_62 ( & V_36 -> V_63 ) ;
if ( V_70 || ( V_36 -> V_39 != V_41 ) )
goto error;
V_70 = F_63 ( V_36 -> V_62 , V_36 -> V_15 ) ;
if ( V_70 )
goto error;
V_70 = F_62 ( & V_36 -> V_63 ) ;
if ( V_70 || ( V_36 -> V_39 != V_43 ) )
goto error;
V_70 = F_64 ( V_36 -> V_62 -> V_72 , & V_139 ) ;
if ( V_70 )
goto error;
V_36 -> V_86 = F_65 ( V_36 -> V_62 -> V_72 , F_23 ,
F_27 , V_64 ,
V_3 . V_11 + V_3 . V_13 + 1 , 0 ) ;
if ( F_29 ( V_36 -> V_86 ) )
goto error;
F_24 ( V_36 -> V_86 , V_91 ) ;
V_36 -> V_103 = F_66 ( V_36 -> V_62 -> V_72 ) ;
if ( F_29 ( V_36 -> V_103 ) )
goto error;
V_36 -> V_101 = NULL ;
if ( V_139 . V_148 & V_149 )
V_36 -> V_112 = V_36 -> V_62 -> V_72 -> V_150 ;
else {
V_36 -> V_101 = F_67 ( V_36 -> V_103 , V_151 ) ;
if ( F_29 ( V_36 -> V_101 ) )
goto error;
V_36 -> V_112 = V_36 -> V_101 -> V_112 ;
}
memset ( & V_137 , 0 , sizeof V_137 ) ;
V_137 . V_152 = F_22 ;
V_137 . V_153 = V_64 ;
V_137 . V_154 . V_155 = V_3 . V_11 ;
V_137 . V_154 . V_156 = V_3 . V_13 ;
V_137 . V_154 . V_157 = V_158 ;
V_137 . V_154 . V_159 = V_160 ;
V_137 . V_161 = V_162 ;
V_137 . V_163 = V_141 ;
V_137 . V_164 = V_36 -> V_86 ;
V_137 . V_165 = V_36 -> V_86 ;
V_70 = F_68 ( V_36 -> V_62 , V_36 -> V_103 , & V_137 ) ;
if ( V_70 )
goto error;
V_36 -> V_102 = V_36 -> V_62 -> V_102 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_166 = NULL ;
V_135 . V_167 = 0 ;
V_135 . V_168 = V_169 ;
V_135 . V_170 = V_171 ;
V_70 = F_69 ( V_36 -> V_62 , & V_135 ) ;
if ( V_70 )
goto error;
V_70 = F_62 ( & V_36 -> V_63 ) ;
if ( V_70 || ( V_36 -> V_39 != V_45 ) )
goto error;
V_64 -> V_48 = V_172 ;
return 0 ;
error:
F_28 ( V_36 ) ;
return - V_173 ;
}
static int T_4 F_70 ( void )
{
F_71 ( & V_174 ) ;
return 0 ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_174 ) ;
}
