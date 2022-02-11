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
unsigned short T_3 V_51 = V_52 ;
bool V_53 = false ;
T_4 V_54 ;
unsigned long V_55 = 1 ;
if ( F_13 ( & V_9 -> V_29 ) != V_30 )
goto V_56;
V_35 -> V_57 = V_58 ;
switch ( F_20 ( V_36 -> V_59 ) ) {
case V_60 :
V_43 = (struct V_42 * ) V_2 -> V_37 ;
T_3 = F_20 ( V_43 -> V_61 ) & V_62 ;
if ( V_43 -> V_63 != V_44 )
break;
case V_45 :
goto V_56;
}
if ( F_21 ( V_9 , V_2 , T_3 ) )
goto V_56;
V_36 = (struct V_36 * ) V_2 -> V_37 ;
if ( ! F_22 ( V_36 -> V_64 ) )
F_15 ( V_35 , V_36 -> V_64 , V_2 -> V_65 ) ;
if ( F_23 ( V_36 -> V_66 , V_46 ) )
goto V_56;
if ( F_23 ( V_36 -> V_66 , V_47 ) )
goto V_56;
if ( F_22 ( V_36 -> V_66 ) ) {
V_53 = true ;
switch ( F_13 ( & V_9 -> V_67 ) ) {
case V_68 :
V_50 = F_24 ( V_2 , & V_48 ) ;
if ( V_50 )
goto V_56;
break;
case V_69 :
V_50 = F_24 ( V_2 , & V_48 ) ;
if ( V_50 )
V_53 = false ;
break;
case V_70 :
default:
break;
}
}
if ( V_53 ) {
V_39 = F_25 ( V_9 ) ;
if ( ! V_39 )
goto V_56;
if ( F_26 ( V_9 , V_2 ) )
V_55 = F_27 ( V_71 ) ;
if ( F_1 ( V_2 , sizeof( * V_41 ) ) < 0 )
goto V_56;
V_41 = (struct V_40 * ) V_2 -> V_37 ;
V_41 -> V_72 . V_73 = V_74 ;
V_41 -> V_72 . V_75 = V_76 ;
V_41 -> V_72 . V_77 = V_78 ;
V_41 -> V_79 = 0 ;
memcpy ( V_41 -> V_80 ,
V_39 -> V_81 -> V_28 , V_25 ) ;
V_54 = F_28 ( & V_9 -> V_82 ) ;
V_41 -> V_54 = F_29 ( V_54 ) ;
F_30 ( V_9 , V_2 , V_55 ) ;
F_31 ( V_2 ) ;
} else {
if ( F_13 ( & V_9 -> V_67 ) != V_70 ) {
V_50 = F_32 ( V_9 , V_2 ) ;
if ( V_50 )
goto V_56;
}
if ( F_26 ( V_9 , V_2 ) )
goto V_56;
F_33 ( V_9 , V_2 ) ;
V_50 = F_34 ( V_9 , V_2 ) ;
if ( V_50 != 0 )
goto V_83;
}
F_35 ( V_9 , V_12 ) ;
F_36 ( V_9 , V_14 , V_49 ) ;
goto V_84;
V_56:
F_31 ( V_2 ) ;
V_83:
F_35 ( V_9 , V_16 ) ;
V_84:
if ( V_39 )
F_37 ( V_39 ) ;
return V_85 ;
}
void F_38 ( struct V_5 * V_35 ,
struct V_1 * V_2 , struct V_38 * V_86 ,
int V_87 , struct V_88 * V_89 )
{
struct V_8 * V_9 = F_9 ( V_35 ) ;
struct V_36 * V_36 ;
struct V_42 * V_43 ;
struct V_90 * V_90 = (struct V_90 * ) V_2 -> V_37 ;
unsigned short T_3 V_51 = V_52 ;
T_2 V_44 = F_19 ( V_45 ) ;
bool V_91 ;
V_91 = ( V_90 -> V_77 == V_78 ) ;
if ( ! F_39 ( V_2 , V_87 ) )
goto V_56;
F_40 ( V_2 , V_87 ) ;
F_41 ( V_2 ) ;
V_36 = F_42 ( V_2 ) ;
switch ( F_20 ( V_36 -> V_59 ) ) {
case V_60 :
V_43 = (struct V_42 * ) V_2 -> V_37 ;
T_3 = F_20 ( V_43 -> V_61 ) & V_62 ;
if ( V_43 -> V_63 != V_44 )
break;
case V_45 :
goto V_56;
}
if ( F_43 ( ! F_39 ( V_2 , V_92 ) ) )
goto V_56;
V_2 -> V_93 = F_44 ( V_2 , V_35 ) ;
F_35 ( V_9 , V_18 ) ;
F_36 ( V_9 , V_20 ,
V_2 -> V_3 + V_92 ) ;
V_35 -> V_94 = V_58 ;
if ( F_45 ( V_9 , V_2 , T_3 , V_91 ) )
goto V_95;
if ( V_89 )
F_46 ( V_9 , V_89 ,
V_36 -> V_64 ) ;
if ( F_47 ( V_9 , V_36 -> V_64 , V_36 -> V_66 ) )
goto V_56;
F_48 ( V_2 ) ;
goto V_95;
V_56:
F_31 ( V_2 ) ;
V_95:
return;
}
static void F_49 ( struct V_5 * V_6 ,
struct V_96 * V_97 ,
void * V_98 )
{
F_50 ( & V_97 -> V_99 , & V_100 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_50 ( & V_6 -> V_101 , & V_102 ) ;
F_52 ( V_6 , F_49 , NULL ) ;
}
static void F_53 ( struct V_103 * V_104 )
{
struct V_8 * V_9 ;
struct V_5 * V_35 ;
V_9 = F_54 ( V_104 , struct V_8 ,
V_105 ) ;
V_35 = V_9 -> V_35 ;
F_55 ( V_35 ) ;
F_56 () ;
F_57 ( V_35 ) ;
F_58 () ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int V_50 ;
T_5 V_106 = sizeof( V_107 ) * V_108 ;
F_51 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_35 = V_6 ;
F_60 ( & V_9 -> V_105 , F_53 ) ;
V_9 -> V_109 = F_61 ( V_106 , F_62 ( V_107 ) ) ;
if ( ! V_9 -> V_109 )
return - V_110 ;
F_63 ( & V_9 -> V_111 , 1 ) ;
F_63 ( & V_9 -> V_112 , 0 ) ;
#ifdef F_64
F_63 ( & V_9 -> V_113 , 0 ) ;
#endif
#ifdef F_65
F_63 ( & V_9 -> V_114 , 1 ) ;
#endif
F_63 ( & V_9 -> V_115 , 0 ) ;
F_63 ( & V_9 -> V_116 , V_117 ) ;
F_63 ( & V_9 -> V_67 , V_70 ) ;
F_63 ( & V_9 -> V_118 , 20 ) ;
F_63 ( & V_9 -> V_119 , 41 ) ;
F_63 ( & V_9 -> V_120 , 1000 ) ;
F_63 ( & V_9 -> V_121 , 30 ) ;
#ifdef F_66
F_63 ( & V_9 -> V_122 , 0 ) ;
#endif
F_63 ( & V_9 -> V_123 , 1 ) ;
F_63 ( & V_9 -> V_124 , V_125 ) ;
F_63 ( & V_9 -> V_126 , V_127 ) ;
F_63 ( & V_9 -> V_29 , V_128 ) ;
F_63 ( & V_9 -> V_82 , 1 ) ;
F_63 ( & V_9 -> V_129 . V_130 , 0 ) ;
F_63 ( & V_9 -> V_129 . V_131 , 0 ) ;
F_63 ( & V_9 -> V_129 . V_132 , 0 ) ;
#ifdef F_64
F_63 ( & V_9 -> V_133 . V_134 , 0 ) ;
#endif
V_9 -> V_129 . V_135 = NULL ;
V_9 -> V_129 . V_136 = 0 ;
V_9 -> V_39 = NULL ;
V_9 -> V_137 = 0 ;
F_67 ( V_9 ) ;
V_50 = F_68 ( V_9 , V_138 ) ;
if ( V_50 < 0 )
goto V_139;
V_50 = F_69 ( V_6 ) ;
if ( V_50 < 0 )
goto V_139;
V_50 = F_70 ( V_6 ) ;
if ( V_50 < 0 )
goto V_140;
return 0 ;
V_140:
F_71 ( V_6 ) ;
V_139:
F_72 ( V_9 -> V_109 ) ;
V_9 -> V_109 = NULL ;
return V_50 ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_5 * V_141 )
{
struct V_38 * V_142 ;
int V_50 = - V_33 ;
V_142 = F_74 ( V_141 ) ;
if ( ! V_142 || V_142 -> V_35 != NULL )
goto V_95;
V_50 = F_75 ( V_142 , V_6 -> V_143 ) ;
V_95:
if ( V_142 )
F_37 ( V_142 ) ;
return V_50 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_5 * V_141 )
{
struct V_38 * V_142 ;
int V_50 = - V_33 ;
V_142 = F_74 ( V_141 ) ;
if ( ! V_142 || V_142 -> V_35 != V_6 )
goto V_95;
F_77 ( V_142 , V_144 ) ;
V_50 = 0 ;
V_95:
if ( V_142 )
F_37 ( V_142 ) ;
return V_50 ;
}
static void F_78 ( struct V_5 * V_6 )
{
F_71 ( V_6 ) ;
F_79 ( V_6 ) ;
F_80 () ;
F_81 ( V_6 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_8 * V_145 = F_9 ( V_6 ) ;
F_83 ( V_6 ) ;
V_6 -> V_146 = & V_147 ;
V_6 -> V_148 = F_78 ;
V_6 -> V_149 = 0 ;
V_6 -> V_34 = V_150 ;
V_6 -> V_151 = V_152 ;
F_84 ( V_6 ) ;
F_85 ( V_6 , & V_153 ) ;
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
}
struct V_5 * F_86 ( const char * V_143 )
{
struct V_5 * V_35 ;
int V_50 ;
V_35 = F_87 ( sizeof( struct V_8 ) , V_143 ,
F_82 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_154 = & V_155 ;
V_50 = F_88 ( V_35 ) ;
if ( V_50 < 0 ) {
F_89 ( L_2 ,
V_143 , V_50 ) ;
F_81 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
void F_90 ( struct V_5 * V_35 )
{
struct V_8 * V_9 = F_9 ( V_35 ) ;
F_91 ( V_156 , & V_9 -> V_105 ) ;
}
static void F_92 ( struct V_5 * V_35 ,
struct V_157 * V_158 )
{
struct V_38 * V_142 ;
F_93 (hard_iface, &batadv_hardif_list, list) {
if ( V_142 -> V_35 == V_35 )
F_77 ( V_142 ,
V_144 ) ;
}
F_55 ( V_35 ) ;
F_94 ( V_35 , V_158 ) ;
}
int F_95 ( const struct V_5 * V_81 )
{
if ( V_81 -> V_146 -> V_159 == F_18 )
return 1 ;
return 0 ;
}
static int F_96 ( struct V_5 * V_6 , struct V_160 * V_161 )
{
V_161 -> V_162 = 0 ;
V_161 -> V_163 = 0 ;
F_97 ( V_161 , V_164 ) ;
V_161 -> V_165 = V_166 ;
V_161 -> V_167 = V_168 ;
V_161 -> V_169 = 0 ;
V_161 -> V_170 = V_171 ;
V_161 -> V_172 = V_173 ;
V_161 -> V_174 = 0 ;
V_161 -> V_175 = 0 ;
return 0 ;
}
static void F_98 ( struct V_5 * V_6 ,
struct V_176 * V_177 )
{
F_99 ( V_177 -> V_178 , L_3 , sizeof( V_177 -> V_178 ) ) ;
F_99 ( V_177 -> V_73 , V_179 , sizeof( V_177 -> V_73 ) ) ;
F_99 ( V_177 -> V_180 , L_4 , sizeof( V_177 -> V_180 ) ) ;
F_99 ( V_177 -> V_181 , L_5 , sizeof( V_177 -> V_181 ) ) ;
}
static T_6 F_100 ( struct V_5 * V_6 )
{
return - V_182 ;
}
static void F_101 ( struct V_5 * V_6 , T_6 V_183 )
{
}
static T_6 F_102 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_103 ( struct V_5 * V_6 , T_4 V_184 ,
T_1 * V_37 )
{
if ( V_184 == V_185 )
memcpy ( V_37 , V_186 ,
sizeof( V_186 ) ) ;
}
static void F_104 ( struct V_5 * V_6 ,
struct V_187 * V_10 ,
V_107 * V_37 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_188 ;
for ( V_188 = 0 ; V_188 < V_108 ; V_188 ++ )
V_37 [ V_188 ] = F_10 ( V_9 , V_188 ) ;
}
static int F_105 ( struct V_5 * V_6 , int V_184 )
{
if ( V_184 == V_185 )
return V_108 ;
return - V_182 ;
}
