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
F_14 ( struct V_66 * V_67 , struct V_68 * V_69 )
{
struct V_34 * V_70 = V_67 -> V_71 ;
struct V_37 * V_38 = V_70 -> V_39 ;
struct V_72 * V_35 =
F_15 ( V_69 -> V_73 , struct V_72 , V_74 ) ;
struct V_75 * V_76 ;
int V_77 = 0 ;
T_2 V_78 ;
V_76 = NULL ;
F_16 ( V_38 -> V_64 -> V_79 , V_35 -> V_80 , V_70 -> V_81 ,
V_82 ) ;
if ( V_69 -> V_50 != V_83 )
goto V_84;
V_77 = F_17 ( V_35 -> V_85 , NULL , NULL , & V_78 , 1 ) ;
if ( V_77 )
goto V_84;
V_76 = F_18 ( V_70 , V_78 ) ;
if ( ! V_76 )
goto V_84;
if ( F_19 ( V_76 -> V_85 ) ) {
F_20 ( L_4 , V_78 ) ;
goto V_84;
}
V_76 -> V_85 = V_35 -> V_85 ;
F_21 ( V_70 , V_76 , V_86 ) ;
V_87:
F_22 ( & V_38 -> V_88 ) ;
F_8 ( V_35 ) ;
return;
V_84:
F_3 ( V_19 , L_5 ,
V_76 , V_77 , V_69 -> V_50 ) ;
V_38 -> V_41 = V_89 ;
V_70 -> V_50 = V_51 ;
goto V_87;
}
static void
F_23 ( struct V_66 * V_67 , struct V_68 * V_69 )
{
struct V_34 * V_70 = V_67 -> V_71 ;
struct V_37 * V_38 = V_70 -> V_39 ;
struct V_72 * V_35 =
F_15 ( V_69 -> V_73 , struct V_72 , V_74 ) ;
F_16 ( V_38 -> V_64 -> V_79 ,
V_35 -> V_80 , V_35 -> V_76 -> V_90 -> V_91 ,
V_92 ) ;
F_22 ( & V_38 -> V_93 ) ;
F_8 ( V_35 ) ;
}
static void F_24 ( struct V_94 * V_33 , void * V_36 )
{
F_3 ( V_19 , L_6 ,
V_33 -> V_33 , V_36 ) ;
}
static void F_25 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
if ( V_38 -> V_95 && ! F_26 ( V_38 -> V_95 ) )
F_27 ( V_38 -> V_95 ) ;
if ( V_38 -> V_96 && ! F_26 ( V_38 -> V_96 ) )
F_28 ( V_38 -> V_96 ) ;
if ( V_38 -> V_67 && ! F_26 ( V_38 -> V_67 ) )
F_29 ( V_38 -> V_67 ) ;
if ( V_38 -> V_64 && ! F_26 ( V_38 -> V_64 ) )
F_30 ( V_38 -> V_64 ) ;
F_8 ( V_38 ) ;
}
static int
F_31 ( struct V_34 * V_70 , struct V_72 * V_35 )
{
struct V_37 * V_38 = V_70 -> V_39 ;
struct V_97 V_98 , * V_99 ;
struct V_100 V_101 ;
V_35 -> V_80 = F_32 ( V_38 -> V_64 -> V_79 ,
V_35 -> V_85 -> V_102 , V_70 -> V_81 ,
V_82 ) ;
if ( F_33 ( V_38 -> V_64 -> V_79 , V_35 -> V_80 ) )
goto error;
V_35 -> V_74 . V_103 = F_14 ;
V_101 . V_104 = V_35 -> V_80 ;
V_101 . V_105 = V_70 -> V_81 ;
V_101 . V_106 = V_38 -> V_96 -> V_107 ;
V_98 . V_108 = NULL ;
V_98 . V_73 = & V_35 -> V_74 ;
V_98 . V_109 = & V_101 ;
V_98 . V_110 = 1 ;
return F_34 ( V_38 -> V_95 , & V_98 , & V_99 ) ;
error:
F_3 ( V_19 , L_7 ) ;
return - V_111 ;
}
static int F_35 ( struct V_34 * V_70 , struct V_75 * V_76 )
{
struct V_37 * V_38 = V_70 -> V_39 ;
struct V_112 V_98 , * V_99 ;
struct V_100 V_101 ;
int V_77 = 0 ;
unsigned long V_113 ;
struct V_72 * V_35 = NULL ;
struct V_72 * V_114 = NULL ;
if ( F_19 ( F_36 ( & V_38 -> V_115 ) > 0 ) ) {
if ( ( F_37 ( 1 , & V_38 -> V_115 ) >= 0 ) ) {
F_8 ( V_76 -> V_85 ) ;
V_76 -> V_85 = NULL ;
goto V_116;
} else {
F_38 ( & V_38 -> V_115 ) ;
}
}
V_114 = F_39 ( sizeof *V_114 , V_117 ) ;
if ( ! V_114 ) {
V_77 = - V_20 ;
goto V_118;
}
V_114 -> V_85 = V_76 -> V_85 ;
if ( F_40 ( & V_38 -> V_88 ) ) {
V_77 = - V_119 ;
goto V_118;
}
V_77 = F_31 ( V_70 , V_114 ) ;
if ( V_77 ) {
F_3 ( V_120 , L_8 ) ;
goto V_118;
}
V_76 -> V_85 = NULL ;
V_116:
V_35 = F_39 ( sizeof *V_35 , V_117 ) ;
if ( ! V_35 ) {
V_77 = - V_20 ;
goto V_121;
}
V_35 -> V_76 = V_76 ;
V_35 -> V_80 = F_32 ( V_38 -> V_64 -> V_79 ,
V_35 -> V_76 -> V_90 -> V_102 , V_35 -> V_76 -> V_90 -> V_91 ,
V_92 ) ;
if ( F_33 ( V_38 -> V_64 -> V_79 , V_35 -> V_80 ) ) {
V_77 = - V_111 ;
goto V_121;
}
V_35 -> V_74 . V_103 = F_23 ;
V_101 . V_104 = V_35 -> V_80 ;
V_101 . V_105 = V_35 -> V_76 -> V_90 -> V_91 ;
V_101 . V_106 = V_38 -> V_96 -> V_107 ;
V_98 . V_108 = NULL ;
V_98 . V_73 = & V_35 -> V_74 ;
V_98 . V_122 = V_123 ;
V_98 . V_124 = V_125 ;
V_98 . V_109 = & V_101 ;
V_98 . V_110 = 1 ;
if ( F_40 ( & V_38 -> V_93 ) ) {
V_77 = - V_119 ;
goto V_121;
}
V_76 -> V_50 = V_126 ;
V_77 = F_41 ( V_38 -> V_95 , & V_98 , & V_99 ) ;
if ( V_77 )
goto V_121;
return 0 ;
V_121:
V_76 -> V_50 = V_127 ;
F_8 ( V_35 ) ;
F_3 ( V_19 , L_9 , V_77 ) ;
F_38 ( & V_38 -> V_115 ) ;
return V_77 ;
V_118:
F_8 ( V_114 ) ;
F_42 ( & V_38 -> V_128 , V_113 ) ;
if ( V_38 -> V_41 < V_129 ) {
V_38 -> V_41 = V_129 ;
F_43 ( & V_38 -> V_128 , V_113 ) ;
F_11 ( V_38 -> V_64 ) ;
} else
F_43 ( & V_38 -> V_128 , V_113 ) ;
return V_77 ;
}
static void F_44 ( struct V_34 * V_70 )
{
struct V_37 * V_38 ;
if ( ! V_70 )
return;
V_38 = V_70 -> V_39 ;
if ( ! V_38 )
return;
V_70 -> V_50 = V_51 ;
F_11 ( V_38 -> V_64 ) ;
F_25 ( V_38 ) ;
}
static struct V_37 * F_45 ( struct V_2 * V_3 )
{
struct V_37 * V_38 ;
V_38 = F_46 ( sizeof( struct V_37 ) , V_18 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_11 = V_3 -> V_11 ;
V_38 -> V_13 = V_3 -> V_13 ;
V_38 -> V_15 = V_3 -> V_15 ;
F_47 ( & V_38 -> V_128 ) ;
F_48 ( & V_38 -> V_65 ) ;
F_49 ( & V_38 -> V_93 , V_38 -> V_11 ) ;
F_49 ( & V_38 -> V_88 , V_38 -> V_13 ) ;
F_50 ( & V_38 -> V_115 , 0 ) ;
return V_38 ;
}
static int F_51 ( struct V_34 * V_70 , struct V_75 * V_76 )
{
return 1 ;
}
static int F_52 ( struct V_34 * V_70 , struct V_75 * V_76 )
{
struct V_37 * V_38 = V_70 -> V_39 ;
F_38 ( & V_38 -> V_115 ) ;
return 0 ;
}
static int F_53 ( struct V_37 * V_38 )
{
struct V_130 V_131 = {
. V_132 = V_133 ,
. V_134 . V_135 = F_54 ( V_136 ) ,
} ;
int V_9 , V_77 = - V_137 ;
for ( V_9 = V_138 ; V_9 >= V_139 ; V_9 -- ) {
V_131 . V_140 = F_55 ( ( V_141 ) V_9 ) ;
V_77 = F_56 ( V_38 -> V_64 , (struct V_142 * ) & V_131 ) ;
if ( V_77 != - V_143 )
break;
}
return V_77 ;
}
static int
F_57 ( struct V_34 * V_70 , const char * V_104 , char * args )
{
int V_77 ;
struct V_2 V_3 ;
struct V_37 * V_38 ;
struct V_144 V_145 ;
struct V_146 V_147 ;
V_77 = F_1 ( args , & V_3 ) ;
if ( V_77 < 0 )
return V_77 ;
V_38 = F_45 ( & V_3 ) ;
if ( ! V_38 )
return - V_20 ;
V_38 -> V_64 = F_58 ( & V_148 , F_9 , V_70 ,
V_149 , V_150 ) ;
if ( F_26 ( V_38 -> V_64 ) )
goto error;
V_70 -> V_39 = V_38 ;
if ( V_3 . V_17 ) {
V_77 = F_53 ( V_38 ) ;
if ( V_77 < 0 ) {
F_20 ( L_10 ,
V_151 , F_59 ( V_152 ) , - V_77 ) ;
goto error;
}
}
V_38 -> V_104 . V_132 = V_133 ;
V_38 -> V_104 . V_134 . V_135 = F_60 ( V_104 ) ;
V_38 -> V_104 . V_140 = F_55 ( V_3 . V_9 ) ;
V_77 = F_61 ( V_38 -> V_64 , NULL ,
(struct V_142 * ) & V_38 -> V_104 ,
V_38 -> V_15 ) ;
if ( V_77 )
goto error;
V_77 = F_62 ( & V_38 -> V_65 ) ;
if ( V_77 || ( V_38 -> V_41 != V_43 ) )
goto error;
V_77 = F_63 ( V_38 -> V_64 , V_38 -> V_15 ) ;
if ( V_77 )
goto error;
V_77 = F_62 ( & V_38 -> V_65 ) ;
if ( V_77 || ( V_38 -> V_41 != V_45 ) )
goto error;
V_38 -> V_67 = F_64 ( V_38 -> V_64 -> V_79 , V_70 ,
V_3 . V_11 + V_3 . V_13 + 1 ,
0 , V_153 ) ;
if ( F_26 ( V_38 -> V_67 ) )
goto error;
V_38 -> V_96 = F_65 ( V_38 -> V_64 -> V_79 , 0 ) ;
if ( F_26 ( V_38 -> V_96 ) )
goto error;
memset ( & V_147 , 0 , sizeof V_147 ) ;
V_147 . V_154 = F_24 ;
V_147 . V_155 = V_70 ;
V_147 . V_156 . V_157 = V_3 . V_11 ;
V_147 . V_156 . V_158 = V_3 . V_13 ;
V_147 . V_156 . V_159 = V_160 ;
V_147 . V_156 . V_161 = V_162 ;
V_147 . V_163 = V_164 ;
V_147 . V_165 = V_150 ;
V_147 . V_166 = V_38 -> V_67 ;
V_147 . V_167 = V_38 -> V_67 ;
V_77 = F_66 ( V_38 -> V_64 , V_38 -> V_96 , & V_147 ) ;
if ( V_77 )
goto error;
V_38 -> V_95 = V_38 -> V_64 -> V_95 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_168 = NULL ;
V_145 . V_169 = 0 ;
V_145 . V_170 = V_171 ;
V_145 . V_172 = V_173 ;
V_77 = F_67 ( V_38 -> V_64 , & V_145 ) ;
if ( V_77 )
goto error;
V_77 = F_62 ( & V_38 -> V_65 ) ;
if ( V_77 || ( V_38 -> V_41 != V_47 ) )
goto error;
V_70 -> V_50 = V_174 ;
return 0 ;
error:
F_25 ( V_38 ) ;
return - V_175 ;
}
static int T_3 F_68 ( void )
{
F_69 ( & V_176 ) ;
return 0 ;
}
static void T_4 F_70 ( void )
{
F_71 ( & V_176 ) ;
}
