int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
F_5 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
F_7 ( V_6 ) ;
return 0 ;
}
static struct V_7 * F_8 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_7 * V_10 = & V_9 -> V_10 ;
V_10 -> V_11 = F_10 ( V_9 , V_12 ) ;
V_10 -> V_13 = F_10 ( V_9 , V_14 ) ;
V_10 -> V_15 = F_10 ( V_9 , V_16 ) ;
V_10 -> V_17 = F_10 ( V_9 , V_18 ) ;
V_10 -> V_19 = F_10 ( V_9 , V_20 ) ;
return V_10 ;
}
static int F_11 ( struct V_5 * V_6 , void * V_21 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 = V_21 ;
T_1 V_24 [ V_25 ] ;
if ( ! F_12 ( V_23 -> V_26 ) )
return - V_27 ;
memcpy ( V_24 , V_6 -> V_28 , V_25 ) ;
memcpy ( V_6 -> V_28 , V_23 -> V_26 , V_25 ) ;
if ( F_13 ( & V_9 -> V_29 ) == V_30 ) {
F_14 ( V_9 , V_24 ,
L_1 , false ) ;
F_15 ( V_6 , V_23 -> V_26 , V_31 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , int V_32 )
{
if ( ( V_32 < 68 ) || ( V_32 > F_17 ( V_6 ) ) )
return - V_33 ;
V_6 -> V_34 = V_32 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_5 * V_35 )
{
struct V_36 * V_36 = (struct V_36 * ) V_2 -> V_37 ;
struct V_8 * V_9 = F_9 ( V_35 ) ;
struct V_38 * V_39 = NULL ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
T_2 V_44 = F_19 ( V_45 ) ;
static const T_1 V_46 [ V_25 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_47 [ V_25 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
unsigned int V_48 = 0 ;
int V_49 = V_2 -> V_3 , V_50 ;
short T_3 V_51 = - 1 ;
bool V_52 = false ;
T_4 V_53 ;
unsigned long V_54 = 1 ;
if ( F_13 ( & V_9 -> V_29 ) != V_30 )
goto V_55;
V_35 -> V_56 = V_57 ;
switch ( F_20 ( V_36 -> V_58 ) ) {
case V_59 :
V_43 = (struct V_42 * ) V_2 -> V_37 ;
T_3 = F_20 ( V_43 -> V_60 ) & V_61 ;
if ( V_43 -> V_62 != V_44 )
break;
case V_45 :
goto V_55;
}
if ( F_21 ( V_9 , V_2 , T_3 ) )
goto V_55;
if ( ! F_22 ( V_36 -> V_63 ) )
F_15 ( V_35 , V_36 -> V_63 , V_2 -> V_64 ) ;
if ( F_23 ( V_36 -> V_65 , V_46 ) )
goto V_55;
if ( F_23 ( V_36 -> V_65 , V_47 ) )
goto V_55;
if ( F_22 ( V_36 -> V_65 ) ) {
V_52 = true ;
switch ( F_13 ( & V_9 -> V_66 ) ) {
case V_67 :
V_50 = F_24 ( V_2 , & V_48 ) ;
if ( V_50 )
goto V_55;
break;
case V_68 :
V_50 = F_24 ( V_2 , & V_48 ) ;
if ( V_50 )
V_52 = false ;
break;
case V_69 :
default:
break;
}
}
if ( V_52 ) {
V_39 = F_25 ( V_9 ) ;
if ( ! V_39 )
goto V_55;
if ( F_26 ( V_9 , V_2 ) )
V_54 = F_27 ( V_70 ) ;
if ( F_1 ( V_2 , sizeof( * V_41 ) ) < 0 )
goto V_55;
V_41 = (struct V_40 * ) V_2 -> V_37 ;
V_41 -> V_71 . V_72 = V_73 ;
V_41 -> V_71 . V_74 = V_75 ;
V_41 -> V_71 . V_76 = V_77 ;
V_41 -> V_78 = 0 ;
memcpy ( V_41 -> V_79 ,
V_39 -> V_80 -> V_28 , V_25 ) ;
V_53 = F_28 ( & V_9 -> V_81 ) ;
V_41 -> V_53 = F_29 ( V_53 ) ;
F_30 ( V_9 , V_2 , V_54 ) ;
F_31 ( V_2 ) ;
} else {
if ( F_13 ( & V_9 -> V_66 ) != V_69 ) {
V_50 = F_32 ( V_9 , V_2 , V_36 ) ;
if ( V_50 )
goto V_55;
}
if ( F_26 ( V_9 , V_2 ) )
goto V_55;
F_33 ( V_9 , V_2 ) ;
V_50 = F_34 ( V_9 , V_2 ) ;
if ( V_50 != 0 )
goto V_82;
}
F_35 ( V_9 , V_12 ) ;
F_36 ( V_9 , V_14 , V_49 ) ;
goto V_83;
V_55:
F_31 ( V_2 ) ;
V_82:
F_35 ( V_9 , V_16 ) ;
V_83:
if ( V_39 )
F_37 ( V_39 ) ;
return V_84 ;
}
void F_38 ( struct V_5 * V_35 ,
struct V_1 * V_2 , struct V_38 * V_85 ,
int V_86 , struct V_87 * V_88 )
{
struct V_8 * V_9 = F_9 ( V_35 ) ;
struct V_36 * V_36 ;
struct V_42 * V_43 ;
struct V_89 * V_89 = (struct V_89 * ) V_2 -> V_37 ;
short T_3 V_51 = - 1 ;
T_2 V_44 = F_19 ( V_45 ) ;
bool V_90 ;
V_90 = ( V_89 -> V_76 == V_77 ) ;
if ( ! F_39 ( V_2 , V_86 ) )
goto V_55;
F_40 ( V_2 , V_86 ) ;
F_41 ( V_2 ) ;
V_36 = (struct V_36 * ) F_42 ( V_2 ) ;
switch ( F_20 ( V_36 -> V_58 ) ) {
case V_59 :
V_43 = (struct V_42 * ) V_2 -> V_37 ;
T_3 = F_20 ( V_43 -> V_60 ) & V_61 ;
if ( V_43 -> V_62 != V_44 )
break;
case V_45 :
goto V_55;
}
if ( F_43 ( ! F_39 ( V_2 , V_91 ) ) )
goto V_55;
V_2 -> V_92 = F_44 ( V_2 , V_35 ) ;
F_35 ( V_9 , V_18 ) ;
F_36 ( V_9 , V_20 ,
V_2 -> V_3 + V_91 ) ;
V_35 -> V_93 = V_57 ;
if ( F_45 ( V_9 , V_2 , T_3 , V_90 ) )
goto V_94;
if ( V_88 )
F_46 ( V_9 , V_88 ,
V_36 -> V_63 ) ;
if ( F_47 ( V_9 , V_36 -> V_63 , V_36 -> V_65 ) )
goto V_55;
F_48 ( V_2 ) ;
goto V_94;
V_55:
F_31 ( V_2 ) ;
V_94:
return;
}
static void F_49 ( struct V_5 * V_6 ,
struct V_95 * V_96 ,
void * V_97 )
{
F_50 ( & V_96 -> V_98 , & V_99 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_50 ( & V_6 -> V_100 , & V_101 ) ;
F_52 ( V_6 , F_49 , NULL ) ;
}
static int F_53 ( struct V_5 * V_6 )
{
F_51 ( V_6 ) ;
return 0 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_8 * V_102 = F_9 ( V_6 ) ;
F_55 ( V_6 ) ;
V_6 -> V_103 = & V_104 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_107 = 0 ;
V_6 -> V_34 = V_108 ;
V_6 -> V_109 = V_110 ;
F_56 ( V_6 ) ;
F_57 ( V_6 , & V_111 ) ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
}
static void F_58 ( struct V_112 * V_113 )
{
struct V_8 * V_9 ;
struct V_5 * V_35 ;
V_9 = F_59 ( V_113 , struct V_8 ,
V_114 ) ;
V_35 = V_9 -> V_35 ;
F_60 ( V_35 ) ;
F_61 ( V_35 ) ;
F_62 () ;
F_63 ( V_35 ) ;
F_64 () ;
}
struct V_5 * F_65 ( const char * V_115 )
{
struct V_5 * V_35 ;
struct V_8 * V_9 ;
int V_50 ;
T_5 V_116 = sizeof( V_117 ) * V_118 ;
V_35 = F_66 ( sizeof( * V_9 ) , V_115 ,
F_54 ) ;
if ( ! V_35 )
goto V_94;
V_9 = F_9 ( V_35 ) ;
V_9 -> V_35 = V_35 ;
F_67 ( & V_9 -> V_114 , F_58 ) ;
V_9 -> V_119 = F_68 ( V_116 , F_69 ( V_117 ) ) ;
if ( ! V_9 -> V_119 )
goto V_120;
V_50 = F_70 ( V_35 ) ;
if ( V_50 < 0 ) {
F_71 ( L_2 ,
V_115 , V_50 ) ;
goto V_121;
}
F_72 ( & V_9 -> V_122 , 1 ) ;
F_72 ( & V_9 -> V_123 , 0 ) ;
#ifdef F_73
F_72 ( & V_9 -> V_124 , 0 ) ;
#endif
#ifdef F_74
F_72 ( & V_9 -> V_125 , 1 ) ;
#endif
F_72 ( & V_9 -> V_126 , 0 ) ;
F_72 ( & V_9 -> V_127 , V_128 ) ;
F_72 ( & V_9 -> V_66 , V_69 ) ;
F_72 ( & V_9 -> V_129 , 20 ) ;
F_72 ( & V_9 -> V_130 , 41 ) ;
F_72 ( & V_9 -> V_131 , 1000 ) ;
F_72 ( & V_9 -> V_132 , 30 ) ;
#ifdef F_75
F_72 ( & V_9 -> V_133 , 0 ) ;
#endif
F_72 ( & V_9 -> V_134 , 1 ) ;
F_72 ( & V_9 -> V_135 , V_136 ) ;
F_72 ( & V_9 -> V_137 , V_138 ) ;
F_72 ( & V_9 -> V_29 , V_139 ) ;
F_72 ( & V_9 -> V_81 , 1 ) ;
F_72 ( & V_9 -> V_140 . V_141 , 0 ) ;
F_72 ( & V_9 -> V_140 . V_142 , 0 ) ;
F_72 ( & V_9 -> V_140 . V_143 , 0 ) ;
#ifdef F_73
F_72 ( & V_9 -> V_144 . V_145 , 0 ) ;
#endif
V_9 -> V_140 . V_146 = NULL ;
V_9 -> V_140 . V_147 = 0 ;
V_9 -> V_39 = NULL ;
V_9 -> V_148 = 0 ;
V_50 = F_76 ( V_9 , V_149 ) ;
if ( V_50 < 0 )
goto V_150;
V_50 = F_77 ( V_35 ) ;
if ( V_50 < 0 )
goto V_150;
V_50 = F_78 ( V_35 ) ;
if ( V_50 < 0 )
goto V_151;
V_50 = F_79 ( V_35 ) ;
if ( V_50 < 0 )
goto V_152;
return V_35 ;
V_152:
F_60 ( V_35 ) ;
V_151:
F_61 ( V_35 ) ;
V_150:
F_80 ( V_9 -> V_119 ) ;
F_63 ( V_35 ) ;
return NULL ;
V_121:
F_80 ( V_9 -> V_119 ) ;
V_120:
V_106 ( V_35 ) ;
V_94:
return NULL ;
}
void F_81 ( struct V_5 * V_35 )
{
struct V_8 * V_9 = F_9 ( V_35 ) ;
F_82 ( V_35 ) ;
F_83 ( V_153 , & V_9 -> V_114 ) ;
}
int F_84 ( const struct V_5 * V_80 )
{
if ( V_80 -> V_103 -> V_154 == F_18 )
return 1 ;
return 0 ;
}
static int F_85 ( struct V_5 * V_6 , struct V_155 * V_156 )
{
V_156 -> V_157 = 0 ;
V_156 -> V_158 = 0 ;
F_86 ( V_156 , V_159 ) ;
V_156 -> V_160 = V_161 ;
V_156 -> V_162 = V_163 ;
V_156 -> V_164 = 0 ;
V_156 -> V_165 = V_166 ;
V_156 -> V_167 = V_168 ;
V_156 -> V_169 = 0 ;
V_156 -> V_170 = 0 ;
return 0 ;
}
static void F_87 ( struct V_5 * V_6 ,
struct V_171 * V_172 )
{
F_88 ( V_172 -> V_173 , L_3 , sizeof( V_172 -> V_173 ) ) ;
F_88 ( V_172 -> V_72 , V_174 , sizeof( V_172 -> V_72 ) ) ;
F_88 ( V_172 -> V_175 , L_4 , sizeof( V_172 -> V_175 ) ) ;
F_88 ( V_172 -> V_176 , L_5 , sizeof( V_172 -> V_176 ) ) ;
}
static T_6 F_89 ( struct V_5 * V_6 )
{
return - V_177 ;
}
static void F_90 ( struct V_5 * V_6 , T_6 V_178 )
{
}
static T_6 F_91 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_92 ( struct V_5 * V_6 , T_4 V_179 ,
T_1 * V_37 )
{
if ( V_179 == V_180 )
memcpy ( V_37 , V_181 ,
sizeof( V_181 ) ) ;
}
static void F_93 ( struct V_5 * V_6 ,
struct V_182 * V_10 ,
V_117 * V_37 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_183 ;
for ( V_183 = 0 ; V_183 < V_118 ; V_183 ++ )
V_37 [ V_183 ] = F_10 ( V_9 , V_183 ) ;
}
static int F_94 ( struct V_5 * V_6 , int V_179 )
{
if ( V_179 == V_180 )
return V_118 ;
return - V_177 ;
}
