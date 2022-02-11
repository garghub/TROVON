static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 != V_9 )
F_2 ( V_2 , L_1 , V_6 -> V_8 ) ;
if ( V_6 -> V_10 != V_11 )
F_2 ( V_2 , L_2 , V_6 -> V_10 ) ;
if ( V_6 -> V_12 != V_13 )
F_2 ( V_2 , L_3 , V_6 -> V_12 ) ;
if ( V_6 -> V_14 != V_15 )
F_2 ( V_2 , L_4 , V_6 -> V_14 ) ;
if ( V_6 -> V_16 )
F_3 ( V_2 , L_5 ) ;
return 0 ;
}
static int F_4 ( char * V_17 , struct V_18 * V_19 )
{
char * V_20 ;
T_1 args [ V_21 ] ;
int V_22 ;
char * V_23 , * V_24 ;
V_19 -> V_8 = V_9 ;
V_19 -> V_10 = V_11 ;
V_19 -> V_12 = V_13 ;
V_19 -> V_14 = V_15 ;
V_19 -> V_16 = false ;
if ( ! V_17 )
return 0 ;
V_24 = F_5 ( V_17 , V_25 ) ;
if ( ! V_24 ) {
F_6 ( V_26 ,
L_6 ) ;
return - V_27 ;
}
V_23 = V_24 ;
while ( ( V_20 = F_7 ( & V_23 , L_7 ) ) != NULL ) {
int V_28 ;
int V_29 ;
if ( ! * V_20 )
continue;
V_28 = F_8 ( V_20 , V_30 , args ) ;
if ( ( V_28 != V_31 ) && ( V_28 != V_32 ) ) {
V_29 = F_9 ( & args [ 0 ] , & V_22 ) ;
if ( V_29 < 0 ) {
F_6 ( V_26 ,
L_8 ) ;
continue;
}
}
switch ( V_28 ) {
case V_33 :
V_19 -> V_8 = V_22 ;
break;
case V_34 :
V_19 -> V_10 = V_22 ;
break;
case V_35 :
V_19 -> V_12 = V_22 ;
break;
case V_36 :
V_19 -> V_14 = V_22 ;
break;
case V_32 :
V_19 -> V_16 = true ;
break;
default:
continue;
}
}
V_19 -> V_12 = F_10 ( V_19 -> V_12 , V_19 -> V_10 ) ;
F_11 ( V_24 ) ;
return 0 ;
}
static int
F_12 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_3 * V_41 = V_38 -> V_42 ;
struct V_5 * V_6 = V_41 -> V_7 ;
switch ( V_40 -> V_40 ) {
case V_43 :
F_13 ( V_6 -> V_44 != V_45 ) ;
V_6 -> V_44 = V_46 ;
break;
case V_47 :
F_13 ( V_6 -> V_44 != V_46 ) ;
V_6 -> V_44 = V_48 ;
break;
case V_49 :
F_13 ( V_6 -> V_44 != V_48 ) ;
V_6 -> V_44 = V_50 ;
break;
case V_51 :
if ( V_6 )
V_6 -> V_44 = V_52 ;
if ( V_41 )
V_41 -> V_53 = V_54 ;
break;
case V_55 :
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_41 -> V_53 = V_54 ;
F_14 ( V_6 -> V_67 ) ;
break;
default:
F_15 () ;
}
F_16 ( & V_6 -> V_68 ) ;
return 0 ;
}
static void
F_17 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_3 * V_73 = V_70 -> V_74 ;
struct V_5 * V_6 = V_73 -> V_7 ;
struct V_75 * V_41 =
F_18 ( V_72 -> V_76 , struct V_75 , V_77 ) ;
struct V_78 * V_79 ;
int V_80 = 0 ;
T_2 V_81 ;
V_79 = NULL ;
F_19 ( V_6 -> V_67 -> V_82 , V_41 -> V_83 , V_73 -> V_84 ,
V_85 ) ;
if ( V_72 -> V_53 != V_86 )
goto V_87;
V_80 = F_20 ( V_41 -> V_88 , NULL , NULL , & V_81 , 1 ) ;
if ( V_80 )
goto V_87;
V_79 = F_21 ( V_73 , V_81 ) ;
if ( ! V_79 )
goto V_87;
if ( F_22 ( V_79 -> V_88 ) ) {
F_23 ( L_9 , V_81 ) ;
goto V_87;
}
V_79 -> V_88 = V_41 -> V_88 ;
F_24 ( V_73 , V_79 , V_89 ) ;
V_90:
F_25 ( & V_6 -> V_91 ) ;
F_11 ( V_41 ) ;
return;
V_87:
F_6 ( V_26 , L_10 ,
V_79 , V_80 , V_72 -> V_53 ) ;
V_6 -> V_44 = V_92 ;
V_73 -> V_53 = V_54 ;
goto V_90;
}
static void
F_26 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_3 * V_73 = V_70 -> V_74 ;
struct V_5 * V_6 = V_73 -> V_7 ;
struct V_75 * V_41 =
F_18 ( V_72 -> V_76 , struct V_75 , V_77 ) ;
F_19 ( V_6 -> V_67 -> V_82 ,
V_41 -> V_83 , V_41 -> V_79 -> V_93 -> V_94 ,
V_95 ) ;
F_25 ( & V_6 -> V_96 ) ;
F_11 ( V_41 ) ;
}
static void F_27 ( struct V_97 * V_40 , void * V_42 )
{
F_6 ( V_26 , L_11 ,
V_40 -> V_40 , V_42 ) ;
}
static void F_28 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
if ( V_6 -> V_98 && ! F_29 ( V_6 -> V_98 ) )
F_30 ( V_6 -> V_98 ) ;
if ( V_6 -> V_99 && ! F_29 ( V_6 -> V_99 ) )
F_31 ( V_6 -> V_99 ) ;
if ( V_6 -> V_70 && ! F_29 ( V_6 -> V_70 ) )
F_32 ( V_6 -> V_70 ) ;
if ( V_6 -> V_67 && ! F_29 ( V_6 -> V_67 ) )
F_33 ( V_6 -> V_67 ) ;
F_11 ( V_6 ) ;
}
static int
F_34 ( struct V_3 * V_73 , struct V_75 * V_41 )
{
struct V_5 * V_6 = V_73 -> V_7 ;
struct V_100 V_101 , * V_102 ;
struct V_103 V_104 ;
V_41 -> V_83 = F_35 ( V_6 -> V_67 -> V_82 ,
V_41 -> V_88 -> V_105 , V_73 -> V_84 ,
V_85 ) ;
if ( F_36 ( V_6 -> V_67 -> V_82 , V_41 -> V_83 ) )
goto error;
V_41 -> V_77 . V_106 = F_17 ;
V_104 . V_107 = V_41 -> V_83 ;
V_104 . V_108 = V_73 -> V_84 ;
V_104 . V_109 = V_6 -> V_99 -> V_110 ;
V_101 . V_111 = NULL ;
V_101 . V_76 = & V_41 -> V_77 ;
V_101 . V_112 = & V_104 ;
V_101 . V_113 = 1 ;
return F_37 ( V_6 -> V_98 , & V_101 , & V_102 ) ;
error:
F_6 ( V_26 , L_12 ) ;
return - V_114 ;
}
static int F_38 ( struct V_3 * V_73 , struct V_78 * V_79 )
{
struct V_5 * V_6 = V_73 -> V_7 ;
struct V_115 V_101 , * V_102 ;
struct V_103 V_104 ;
int V_80 = 0 ;
unsigned long V_116 ;
struct V_75 * V_41 = NULL ;
struct V_75 * V_117 = NULL ;
if ( F_22 ( F_39 ( & V_6 -> V_118 ) > 0 ) ) {
if ( ( F_40 ( 1 , & V_6 -> V_118 ) >= 0 ) ) {
F_11 ( V_79 -> V_88 ) ;
V_79 -> V_88 = NULL ;
goto V_119;
} else {
F_41 ( & V_6 -> V_118 ) ;
}
}
V_117 = F_42 ( sizeof *V_117 , V_120 ) ;
if ( ! V_117 ) {
V_80 = - V_27 ;
goto V_121;
}
V_117 -> V_88 = V_79 -> V_88 ;
if ( F_43 ( & V_6 -> V_91 ) ) {
V_80 = - V_122 ;
goto V_121;
}
V_80 = F_34 ( V_73 , V_117 ) ;
if ( V_80 ) {
F_6 ( V_123 , L_13 ) ;
goto V_121;
}
V_79 -> V_88 = NULL ;
V_119:
V_41 = F_42 ( sizeof *V_41 , V_120 ) ;
if ( ! V_41 ) {
V_80 = - V_27 ;
goto V_124;
}
V_41 -> V_79 = V_79 ;
V_41 -> V_83 = F_35 ( V_6 -> V_67 -> V_82 ,
V_41 -> V_79 -> V_93 -> V_105 , V_41 -> V_79 -> V_93 -> V_94 ,
V_95 ) ;
if ( F_36 ( V_6 -> V_67 -> V_82 , V_41 -> V_83 ) ) {
V_80 = - V_114 ;
goto V_124;
}
V_41 -> V_77 . V_106 = F_26 ;
V_104 . V_107 = V_41 -> V_83 ;
V_104 . V_108 = V_41 -> V_79 -> V_93 -> V_94 ;
V_104 . V_109 = V_6 -> V_99 -> V_110 ;
V_101 . V_111 = NULL ;
V_101 . V_76 = & V_41 -> V_77 ;
V_101 . V_125 = V_126 ;
V_101 . V_127 = V_128 ;
V_101 . V_112 = & V_104 ;
V_101 . V_113 = 1 ;
if ( F_43 ( & V_6 -> V_96 ) ) {
V_80 = - V_122 ;
goto V_124;
}
V_79 -> V_53 = V_129 ;
V_80 = F_44 ( V_6 -> V_98 , & V_101 , & V_102 ) ;
if ( V_80 )
goto V_124;
return 0 ;
V_124:
V_79 -> V_53 = V_130 ;
F_11 ( V_41 ) ;
F_6 ( V_26 , L_14 , V_80 ) ;
F_41 ( & V_6 -> V_118 ) ;
return V_80 ;
V_121:
F_11 ( V_117 ) ;
F_45 ( & V_6 -> V_131 , V_116 ) ;
if ( V_6 -> V_44 < V_132 ) {
V_6 -> V_44 = V_132 ;
F_46 ( & V_6 -> V_131 , V_116 ) ;
F_14 ( V_6 -> V_67 ) ;
} else
F_46 ( & V_6 -> V_131 , V_116 ) ;
return V_80 ;
}
static void F_47 ( struct V_3 * V_73 )
{
struct V_5 * V_6 ;
if ( ! V_73 )
return;
V_6 = V_73 -> V_7 ;
if ( ! V_6 )
return;
V_73 -> V_53 = V_54 ;
F_14 ( V_6 -> V_67 ) ;
F_28 ( V_6 ) ;
}
static struct V_5 * F_48 ( struct V_18 * V_19 )
{
struct V_5 * V_6 ;
V_6 = F_49 ( sizeof( struct V_5 ) , V_25 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_8 = V_19 -> V_8 ;
V_6 -> V_16 = V_19 -> V_16 ;
V_6 -> V_10 = V_19 -> V_10 ;
V_6 -> V_12 = V_19 -> V_12 ;
V_6 -> V_14 = V_19 -> V_14 ;
F_50 ( & V_6 -> V_131 ) ;
F_51 ( & V_6 -> V_68 ) ;
F_52 ( & V_6 -> V_96 , V_6 -> V_10 ) ;
F_52 ( & V_6 -> V_91 , V_6 -> V_12 ) ;
F_53 ( & V_6 -> V_118 , 0 ) ;
return V_6 ;
}
static int F_54 ( struct V_3 * V_73 , struct V_78 * V_79 )
{
return 1 ;
}
static int F_55 ( struct V_3 * V_73 , struct V_78 * V_79 )
{
struct V_5 * V_6 = V_73 -> V_7 ;
F_41 ( & V_6 -> V_118 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_137 . V_138 = F_57 ( V_139 ) ,
} ;
int V_8 , V_80 = - V_140 ;
for ( V_8 = V_141 ; V_8 >= V_142 ; V_8 -- ) {
V_134 . V_143 = F_58 ( ( V_144 ) V_8 ) ;
V_80 = F_59 ( V_6 -> V_67 , (struct V_145 * ) & V_134 ) ;
if ( V_80 != - V_146 )
break;
}
return V_80 ;
}
static int
F_60 ( struct V_3 * V_73 , const char * V_107 , char * args )
{
int V_80 ;
struct V_18 V_19 ;
struct V_5 * V_6 ;
struct V_147 V_148 ;
struct V_149 V_150 ;
V_80 = F_4 ( args , & V_19 ) ;
if ( V_80 < 0 )
return V_80 ;
V_6 = F_48 ( & V_19 ) ;
if ( ! V_6 )
return - V_27 ;
V_6 -> V_67 = F_61 ( & V_151 , F_12 , V_73 ,
V_152 , V_153 ) ;
if ( F_29 ( V_6 -> V_67 ) )
goto error;
V_73 -> V_7 = V_6 ;
if ( V_19 . V_16 ) {
V_80 = F_56 ( V_6 ) ;
if ( V_80 < 0 ) {
F_23 ( L_15 ,
V_154 , F_62 ( V_155 ) , - V_80 ) ;
goto error;
}
}
V_6 -> V_107 . V_135 = V_136 ;
V_6 -> V_107 . V_137 . V_138 = F_63 ( V_107 ) ;
V_6 -> V_107 . V_143 = F_58 ( V_19 . V_8 ) ;
V_80 = F_64 ( V_6 -> V_67 , NULL ,
(struct V_145 * ) & V_6 -> V_107 ,
V_6 -> V_14 ) ;
if ( V_80 )
goto error;
V_80 = F_65 ( & V_6 -> V_68 ) ;
if ( V_80 || ( V_6 -> V_44 != V_46 ) )
goto error;
V_80 = F_66 ( V_6 -> V_67 , V_6 -> V_14 ) ;
if ( V_80 )
goto error;
V_80 = F_65 ( & V_6 -> V_68 ) ;
if ( V_80 || ( V_6 -> V_44 != V_48 ) )
goto error;
V_6 -> V_70 = F_67 ( V_6 -> V_67 -> V_82 , V_73 ,
V_19 . V_10 + V_19 . V_12 + 1 ,
0 , V_156 ) ;
if ( F_29 ( V_6 -> V_70 ) )
goto error;
V_6 -> V_99 = F_68 ( V_6 -> V_67 -> V_82 , 0 ) ;
if ( F_29 ( V_6 -> V_99 ) )
goto error;
memset ( & V_150 , 0 , sizeof V_150 ) ;
V_150 . V_157 = F_27 ;
V_150 . V_158 = V_73 ;
V_150 . V_159 . V_160 = V_19 . V_10 ;
V_150 . V_159 . V_161 = V_19 . V_12 ;
V_150 . V_159 . V_162 = V_163 ;
V_150 . V_159 . V_164 = V_165 ;
V_150 . V_166 = V_167 ;
V_150 . V_168 = V_153 ;
V_150 . V_169 = V_6 -> V_70 ;
V_150 . V_170 = V_6 -> V_70 ;
V_80 = F_69 ( V_6 -> V_67 , V_6 -> V_99 , & V_150 ) ;
if ( V_80 )
goto error;
V_6 -> V_98 = V_6 -> V_67 -> V_98 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_171 = NULL ;
V_148 . V_172 = 0 ;
V_148 . V_173 = V_174 ;
V_148 . V_175 = V_176 ;
V_80 = F_70 ( V_6 -> V_67 , & V_148 ) ;
if ( V_80 )
goto error;
V_80 = F_65 ( & V_6 -> V_68 ) ;
if ( V_80 || ( V_6 -> V_44 != V_50 ) )
goto error;
V_73 -> V_53 = V_177 ;
return 0 ;
error:
F_28 ( V_6 ) ;
return - V_178 ;
}
static int T_3 F_71 ( void )
{
F_72 ( & V_179 ) ;
return 0 ;
}
static void T_4 F_73 ( void )
{
F_74 ( & V_179 ) ;
}
