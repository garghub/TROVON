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
V_21 = F_6 ( & args [ 0 ] , & V_6 ) ;
if ( V_21 < 0 ) {
F_3 ( V_18 ,
L_3 ) ;
continue;
}
switch ( V_20 ) {
case V_23 :
V_3 -> V_9 = V_6 ;
break;
case V_24 :
V_3 -> V_11 = V_6 ;
break;
case V_25 :
V_3 -> V_13 = V_6 ;
break;
case V_26 :
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
F_9 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_28 -> V_33 ;
struct V_34 * V_35 = V_32 -> V_36 ;
switch ( V_30 -> V_30 ) {
case V_37 :
F_10 ( V_35 -> V_38 != V_39 ) ;
V_35 -> V_38 = V_40 ;
break;
case V_41 :
F_10 ( V_35 -> V_38 != V_40 ) ;
V_35 -> V_38 = V_42 ;
break;
case V_43 :
F_10 ( V_35 -> V_38 != V_42 ) ;
V_35 -> V_38 = V_44 ;
break;
case V_45 :
if ( V_35 )
V_35 -> V_38 = V_46 ;
if ( V_32 )
V_32 -> V_47 = V_48 ;
break;
case V_49 :
break;
case V_50 :
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
V_32 -> V_47 = V_48 ;
F_11 ( V_35 -> V_61 ) ;
break;
default:
F_12 () ;
}
F_13 ( & V_35 -> V_62 ) ;
return 0 ;
}
static void
F_14 ( struct V_31 * V_63 , struct V_34 * V_35 ,
struct V_64 * V_32 , enum V_65 V_47 , T_2 V_66 )
{
struct V_67 * V_68 ;
int V_69 = 0 ;
T_3 V_70 ;
V_68 = NULL ;
F_15 ( V_35 -> V_61 -> V_71 , V_32 -> V_72 , V_63 -> V_73 ,
V_74 ) ;
if ( V_47 != V_75 )
goto V_76;
V_69 = F_16 ( V_32 -> V_77 , NULL , NULL , & V_70 , 1 ) ;
if ( V_69 )
goto V_76;
V_68 = F_17 ( V_63 , V_70 ) ;
if ( ! V_68 )
goto V_76;
V_68 -> V_77 = V_32 -> V_77 ;
V_68 -> V_47 = V_78 ;
F_18 ( V_63 , V_68 ) ;
return;
V_76:
F_3 ( V_18 , L_4 ,
V_68 , V_69 , V_47 ) ;
V_35 -> V_38 = V_79 ;
V_63 -> V_47 = V_48 ;
}
static void
F_19 ( struct V_31 * V_63 , struct V_34 * V_35 ,
struct V_64 * V_32 , enum V_65 V_47 , T_2 V_66 )
{
F_15 ( V_35 -> V_61 -> V_71 ,
V_32 -> V_72 , V_32 -> V_68 -> V_80 -> V_81 ,
V_82 ) ;
}
static void F_20 ( struct V_83 * V_30 , void * V_33 )
{
F_3 ( V_18 , L_5 , V_30 -> V_30 ,
V_33 ) ;
}
static void F_21 ( struct V_84 * V_85 , void * V_86 )
{
struct V_31 * V_63 = V_86 ;
struct V_34 * V_35 = V_63 -> V_36 ;
int V_87 ;
struct V_88 V_89 ;
F_22 ( V_35 -> V_85 , V_90 ) ;
while ( ( V_87 = F_23 ( V_85 , 1 , & V_89 ) ) > 0 ) {
struct V_64 * V_32 = ( void * ) ( unsigned long ) V_89 . V_91 ;
switch ( V_32 -> V_92 ) {
case V_93 :
F_24 ( & V_35 -> V_94 ) ;
F_14 ( V_63 , V_35 , V_32 , V_89 . V_47 , V_89 . V_66 ) ;
break;
case V_95 :
F_19 ( V_63 , V_35 , V_32 , V_89 . V_47 , V_89 . V_66 ) ;
F_25 ( & V_35 -> V_96 ) ;
break;
default:
F_26 ( V_97 L_6
L_7 ,
V_32 -> V_92 , V_89 . V_98 , V_89 . V_47 ) ;
break;
}
F_8 ( V_32 ) ;
}
}
static void F_27 ( struct V_83 * V_99 , void * V_100 )
{
F_3 ( V_18 , L_8 , V_99 -> V_30 , V_100 ) ;
}
static void F_28 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return;
if ( V_35 -> V_101 && ! F_29 ( V_35 -> V_101 ) )
F_30 ( V_35 -> V_101 ) ;
if ( V_35 -> V_102 && ! F_29 ( V_35 -> V_102 ) )
F_31 ( V_35 -> V_102 ) ;
if ( V_35 -> V_103 && ! F_29 ( V_35 -> V_103 ) )
F_32 ( V_35 -> V_103 ) ;
if ( V_35 -> V_85 && ! F_29 ( V_35 -> V_85 ) )
F_33 ( V_35 -> V_85 ) ;
if ( V_35 -> V_61 && ! F_29 ( V_35 -> V_61 ) )
F_34 ( V_35 -> V_61 ) ;
F_8 ( V_35 ) ;
}
static int
F_35 ( struct V_31 * V_63 , struct V_64 * V_32 )
{
struct V_34 * V_35 = V_63 -> V_36 ;
struct V_104 V_105 , * V_106 ;
struct V_107 V_108 ;
V_32 -> V_72 = F_36 ( V_35 -> V_61 -> V_71 ,
V_32 -> V_77 -> V_109 , V_63 -> V_73 ,
V_74 ) ;
if ( F_37 ( V_35 -> V_61 -> V_71 , V_32 -> V_72 ) )
goto error;
V_108 . V_110 = V_32 -> V_72 ;
V_108 . V_111 = V_63 -> V_73 ;
V_108 . V_112 = V_35 -> V_112 ;
V_105 . V_113 = NULL ;
V_32 -> V_92 = V_93 ;
V_105 . V_91 = ( unsigned long ) V_32 ;
V_105 . V_114 = & V_108 ;
V_105 . V_115 = 1 ;
return F_38 ( V_35 -> V_102 , & V_105 , & V_106 ) ;
error:
F_3 ( V_18 , L_9 ) ;
return - V_116 ;
}
static int F_39 ( struct V_31 * V_63 , struct V_67 * V_68 )
{
struct V_34 * V_35 = V_63 -> V_36 ;
struct V_117 V_105 , * V_106 ;
struct V_107 V_108 ;
int V_69 = 0 ;
unsigned long V_118 ;
struct V_64 * V_32 = NULL ;
struct V_64 * V_119 = NULL ;
V_119 = F_40 ( sizeof *V_119 , V_120 ) ;
if ( ! V_119 ) {
V_69 = - V_19 ;
goto V_121;
}
if ( ! V_68 -> V_77 ) {
V_68 -> V_77 = F_40 ( sizeof( struct V_122 ) + V_63 -> V_73 ,
V_120 ) ;
if ( V_68 -> V_77 ) {
V_68 -> V_77 -> V_109 = ( char * ) V_68 -> V_77 +
sizeof( struct V_122 ) ;
V_68 -> V_77 -> V_123 = V_63 -> V_73 ;
}
}
V_119 -> V_77 = V_68 -> V_77 ;
if ( ! V_119 -> V_77 ) {
V_69 = - V_19 ;
goto V_124;
}
if ( F_41 ( & V_35 -> V_94 ) <= V_35 -> V_13 ) {
V_69 = F_35 ( V_63 , V_119 ) ;
if ( V_69 )
goto V_125;
} else
F_24 ( & V_35 -> V_94 ) ;
V_68 -> V_77 = NULL ;
V_32 = F_40 ( sizeof *V_32 , V_120 ) ;
if ( ! V_32 ) {
V_69 = - V_19 ;
goto V_125;
}
V_32 -> V_68 = V_68 ;
V_32 -> V_72 = F_36 ( V_35 -> V_61 -> V_71 ,
V_32 -> V_68 -> V_80 -> V_109 , V_32 -> V_68 -> V_80 -> V_81 ,
V_82 ) ;
if ( F_37 ( V_35 -> V_61 -> V_71 , V_32 -> V_72 ) )
goto error;
V_108 . V_110 = V_32 -> V_72 ;
V_108 . V_111 = V_32 -> V_68 -> V_80 -> V_81 ;
V_108 . V_112 = V_35 -> V_112 ;
V_105 . V_113 = NULL ;
V_32 -> V_92 = V_95 ;
V_105 . V_91 = ( unsigned long ) V_32 ;
V_105 . V_98 = V_126 ;
V_105 . V_127 = V_128 ;
V_105 . V_114 = & V_108 ;
V_105 . V_115 = 1 ;
if ( F_42 ( & V_35 -> V_96 ) )
goto error;
return F_43 ( V_35 -> V_102 , & V_105 , & V_106 ) ;
error:
F_8 ( V_32 ) ;
F_8 ( V_119 -> V_77 ) ;
F_8 ( V_119 ) ;
F_3 ( V_18 , L_9 ) ;
return - V_116 ;
V_125:
F_8 ( V_119 -> V_77 ) ;
V_124:
F_8 ( V_119 ) ;
V_121:
F_44 ( & V_35 -> V_129 , V_118 ) ;
if ( V_35 -> V_38 < V_130 ) {
V_35 -> V_38 = V_130 ;
F_45 ( & V_35 -> V_129 , V_118 ) ;
F_11 ( V_35 -> V_61 ) ;
} else
F_45 ( & V_35 -> V_129 , V_118 ) ;
return V_69 ;
}
static void F_46 ( struct V_31 * V_63 )
{
struct V_34 * V_35 ;
if ( ! V_63 )
return;
V_35 = V_63 -> V_36 ;
if ( ! V_35 )
return;
V_63 -> V_47 = V_48 ;
F_11 ( V_35 -> V_61 ) ;
F_28 ( V_35 ) ;
}
static struct V_34 * F_47 ( struct V_2 * V_3 )
{
struct V_34 * V_35 ;
V_35 = F_48 ( sizeof( struct V_34 ) , V_17 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_11 = V_3 -> V_11 ;
V_35 -> V_13 = V_3 -> V_13 ;
V_35 -> V_15 = V_3 -> V_15 ;
F_49 ( & V_35 -> V_129 ) ;
F_50 ( & V_35 -> V_62 ) ;
F_51 ( & V_35 -> V_96 , V_35 -> V_11 ) ;
F_52 ( & V_35 -> V_94 , 0 ) ;
return V_35 ;
}
static int F_53 ( struct V_31 * V_63 , struct V_67 * V_68 )
{
return 1 ;
}
static int
F_54 ( struct V_31 * V_63 , const char * V_110 , char * args )
{
int V_69 ;
struct V_2 V_3 ;
struct V_34 * V_35 ;
struct V_131 V_132 ;
struct V_133 V_134 ;
struct V_135 V_136 ;
V_69 = F_1 ( args , & V_3 ) ;
if ( V_69 < 0 )
return V_69 ;
V_35 = F_47 ( & V_3 ) ;
if ( ! V_35 )
return - V_19 ;
V_35 -> V_61 = F_55 ( F_9 , V_63 , V_137 ,
V_138 ) ;
if ( F_29 ( V_35 -> V_61 ) )
goto error;
V_63 -> V_36 = V_35 ;
V_35 -> V_110 . V_139 = V_140 ;
V_35 -> V_110 . V_141 . V_142 = F_56 ( V_110 ) ;
V_35 -> V_110 . V_143 = F_57 ( V_3 . V_9 ) ;
V_69 = F_58 ( V_35 -> V_61 , NULL ,
(struct V_144 * ) & V_35 -> V_110 ,
V_35 -> V_15 ) ;
if ( V_69 )
goto error;
V_69 = F_59 ( & V_35 -> V_62 ) ;
if ( V_69 || ( V_35 -> V_38 != V_40 ) )
goto error;
V_69 = F_60 ( V_35 -> V_61 , V_35 -> V_15 ) ;
if ( V_69 )
goto error;
V_69 = F_59 ( & V_35 -> V_62 ) ;
if ( V_69 || ( V_35 -> V_38 != V_42 ) )
goto error;
V_69 = F_61 ( V_35 -> V_61 -> V_71 , & V_136 ) ;
if ( V_69 )
goto error;
V_35 -> V_85 = F_62 ( V_35 -> V_61 -> V_71 , F_21 ,
F_27 , V_63 ,
V_3 . V_11 + V_3 . V_13 + 1 , 0 ) ;
if ( F_29 ( V_35 -> V_85 ) )
goto error;
F_22 ( V_35 -> V_85 , V_90 ) ;
V_35 -> V_103 = F_63 ( V_35 -> V_61 -> V_71 ) ;
if ( F_29 ( V_35 -> V_103 ) )
goto error;
V_35 -> V_101 = NULL ;
if ( V_136 . V_145 & V_146 )
V_35 -> V_112 = V_35 -> V_61 -> V_71 -> V_147 ;
else {
V_35 -> V_101 = F_64 ( V_35 -> V_103 , V_148 ) ;
if ( F_29 ( V_35 -> V_101 ) )
goto error;
V_35 -> V_112 = V_35 -> V_101 -> V_112 ;
}
memset ( & V_134 , 0 , sizeof V_134 ) ;
V_134 . V_149 = F_20 ;
V_134 . V_150 = V_63 ;
V_134 . V_151 . V_152 = V_3 . V_11 ;
V_134 . V_151 . V_153 = V_3 . V_13 ;
V_134 . V_151 . V_154 = V_155 ;
V_134 . V_151 . V_156 = V_157 ;
V_134 . V_158 = V_159 ;
V_134 . V_160 = V_138 ;
V_134 . V_161 = V_35 -> V_85 ;
V_134 . V_162 = V_35 -> V_85 ;
V_69 = F_65 ( V_35 -> V_61 , V_35 -> V_103 , & V_134 ) ;
if ( V_69 )
goto error;
V_35 -> V_102 = V_35 -> V_61 -> V_102 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . V_163 = NULL ;
V_132 . V_164 = 0 ;
V_132 . V_165 = V_166 ;
V_132 . V_167 = V_168 ;
V_69 = F_66 ( V_35 -> V_61 , & V_132 ) ;
if ( V_69 )
goto error;
V_69 = F_59 ( & V_35 -> V_62 ) ;
if ( V_69 || ( V_35 -> V_38 != V_44 ) )
goto error;
V_63 -> V_47 = V_169 ;
return 0 ;
error:
F_28 ( V_35 ) ;
return - V_170 ;
}
static int T_4 F_67 ( void )
{
F_68 ( & V_171 ) ;
return 0 ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_171 ) ;
}
