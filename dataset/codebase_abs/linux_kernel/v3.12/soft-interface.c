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
T_3 |= V_63 ;
if ( V_43 -> V_64 != V_44 )
break;
case V_45 :
goto V_56;
}
if ( F_21 ( V_9 , V_2 , T_3 ) )
goto V_56;
V_36 = (struct V_36 * ) V_2 -> V_37 ;
if ( ! F_22 ( V_36 -> V_65 ) )
F_15 ( V_35 , V_36 -> V_65 , V_2 -> V_66 ) ;
if ( F_23 ( V_36 -> V_67 , V_46 ) )
goto V_56;
if ( F_23 ( V_36 -> V_67 , V_47 ) )
goto V_56;
if ( F_22 ( V_36 -> V_67 ) ) {
V_53 = true ;
switch ( F_13 ( & V_9 -> V_68 ) ) {
case V_69 :
V_50 = F_24 ( V_2 , & V_48 ) ;
if ( V_50 )
goto V_56;
break;
case V_70 :
V_50 = F_24 ( V_2 , & V_48 ) ;
if ( V_50 )
V_53 = false ;
break;
case V_71 :
default:
break;
}
}
F_25 ( V_2 , 0 ) ;
if ( V_53 ) {
V_39 = F_26 ( V_9 ) ;
if ( ! V_39 )
goto V_56;
if ( F_27 ( V_9 , V_2 ) )
V_55 = F_28 ( V_72 ) ;
if ( F_1 ( V_2 , sizeof( * V_41 ) ) < 0 )
goto V_56;
V_41 = (struct V_40 * ) V_2 -> V_37 ;
V_41 -> V_73 . V_74 = V_75 ;
V_41 -> V_73 . V_76 = V_77 ;
V_41 -> V_73 . V_78 = V_79 ;
V_41 -> V_80 = 0 ;
memcpy ( V_41 -> V_81 ,
V_39 -> V_82 -> V_28 , V_25 ) ;
V_54 = F_29 ( & V_9 -> V_83 ) ;
V_41 -> V_54 = F_30 ( V_54 ) ;
F_31 ( V_9 , V_2 , V_55 ) ;
F_32 ( V_2 ) ;
} else {
if ( F_13 ( & V_9 -> V_68 ) != V_71 ) {
V_50 = F_33 ( V_9 , V_2 ) ;
if ( V_50 )
goto V_56;
}
if ( F_27 ( V_9 , V_2 ) )
goto V_56;
F_34 ( V_9 , V_2 ) ;
V_50 = F_35 ( V_9 , V_2 ) ;
if ( V_50 != 0 )
goto V_84;
}
F_36 ( V_9 , V_12 ) ;
F_37 ( V_9 , V_14 , V_49 ) ;
goto V_85;
V_56:
F_32 ( V_2 ) ;
V_84:
F_36 ( V_9 , V_16 ) ;
V_85:
if ( V_39 )
F_38 ( V_39 ) ;
return V_86 ;
}
void F_39 ( struct V_5 * V_35 ,
struct V_1 * V_2 , struct V_38 * V_87 ,
int V_88 , struct V_89 * V_90 )
{
struct V_8 * V_9 = F_9 ( V_35 ) ;
struct V_36 * V_36 ;
struct V_42 * V_43 ;
struct V_91 * V_91 = (struct V_91 * ) V_2 -> V_37 ;
unsigned short T_3 V_51 = V_52 ;
T_2 V_44 = F_19 ( V_45 ) ;
bool V_92 ;
V_92 = ( V_91 -> V_78 == V_79 ) ;
if ( ! F_40 ( V_2 , V_88 ) )
goto V_56;
F_41 ( V_2 , V_88 ) ;
F_42 ( V_2 ) ;
V_36 = F_43 ( V_2 ) ;
switch ( F_20 ( V_36 -> V_59 ) ) {
case V_60 :
V_43 = (struct V_42 * ) V_2 -> V_37 ;
T_3 = F_20 ( V_43 -> V_61 ) & V_62 ;
T_3 |= V_63 ;
if ( V_43 -> V_64 != V_44 )
break;
case V_45 :
goto V_56;
}
if ( F_44 ( ! F_40 ( V_2 , V_93 ) ) )
goto V_56;
V_2 -> V_94 = F_45 ( V_2 , V_35 ) ;
F_36 ( V_9 , V_18 ) ;
F_37 ( V_9 , V_20 ,
V_2 -> V_3 + V_93 ) ;
V_35 -> V_95 = V_58 ;
if ( F_46 ( V_9 , V_2 , T_3 , V_92 ) )
goto V_96;
if ( V_90 )
F_47 ( V_9 , V_90 ,
V_36 -> V_65 ) ;
if ( F_48 ( V_9 , V_36 -> V_65 , V_36 -> V_67 ) )
goto V_56;
F_49 ( V_2 ) ;
goto V_96;
V_56:
F_32 ( V_2 ) ;
V_96:
return;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_97 * V_98 ,
void * V_99 )
{
F_51 ( & V_98 -> V_100 , & V_101 ) ;
}
static void F_52 ( struct V_5 * V_6 )
{
F_51 ( & V_6 -> V_102 , & V_103 ) ;
F_53 ( V_6 , F_50 , NULL ) ;
}
static void F_54 ( struct V_104 * V_105 )
{
struct V_8 * V_9 ;
struct V_5 * V_35 ;
V_9 = F_55 ( V_105 , struct V_8 ,
V_106 ) ;
V_35 = V_9 -> V_35 ;
F_56 ( V_35 ) ;
F_57 () ;
F_58 ( V_35 ) ;
F_59 () ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int V_50 ;
T_5 V_107 = sizeof( V_108 ) * V_109 ;
F_52 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_35 = V_6 ;
F_61 ( & V_9 -> V_106 , F_54 ) ;
V_9 -> V_110 = F_62 ( V_107 , F_63 ( V_108 ) ) ;
if ( ! V_9 -> V_110 )
return - V_111 ;
F_64 ( & V_9 -> V_112 , 1 ) ;
F_64 ( & V_9 -> V_113 , 0 ) ;
#ifdef F_65
F_64 ( & V_9 -> V_114 , 0 ) ;
#endif
#ifdef F_66
F_64 ( & V_9 -> V_115 , 1 ) ;
#endif
F_64 ( & V_9 -> V_116 , 0 ) ;
F_64 ( & V_9 -> V_117 , V_118 ) ;
F_64 ( & V_9 -> V_68 , V_71 ) ;
F_64 ( & V_9 -> V_119 , 20 ) ;
F_64 ( & V_9 -> V_120 , 41 ) ;
F_64 ( & V_9 -> V_121 , 1000 ) ;
F_64 ( & V_9 -> V_122 , 30 ) ;
#ifdef F_67
F_64 ( & V_9 -> V_123 , 0 ) ;
#endif
F_64 ( & V_9 -> V_124 , 1 ) ;
F_64 ( & V_9 -> V_125 , V_126 ) ;
F_64 ( & V_9 -> V_127 , V_128 ) ;
F_64 ( & V_9 -> V_29 , V_129 ) ;
F_64 ( & V_9 -> V_83 , 1 ) ;
F_64 ( & V_9 -> V_130 . V_131 , 0 ) ;
F_64 ( & V_9 -> V_130 . V_132 , 0 ) ;
F_64 ( & V_9 -> V_130 . V_133 , 0 ) ;
#ifdef F_65
F_64 ( & V_9 -> V_134 . V_135 , 0 ) ;
#endif
V_9 -> V_130 . V_136 = NULL ;
V_9 -> V_130 . V_137 = 0 ;
V_9 -> V_39 = NULL ;
V_9 -> V_138 = 0 ;
F_68 ( V_9 ) ;
V_50 = F_69 ( V_9 , V_139 ) ;
if ( V_50 < 0 )
goto V_140;
V_50 = F_70 ( V_6 ) ;
if ( V_50 < 0 )
goto V_140;
V_50 = F_71 ( V_6 ) ;
if ( V_50 < 0 )
goto V_141;
return 0 ;
V_141:
F_72 ( V_6 ) ;
V_140:
F_73 ( V_9 -> V_110 ) ;
V_9 -> V_110 = NULL ;
return V_50 ;
}
static int F_74 ( struct V_5 * V_6 ,
struct V_5 * V_142 )
{
struct V_38 * V_143 ;
int V_50 = - V_33 ;
V_143 = F_75 ( V_142 ) ;
if ( ! V_143 || V_143 -> V_35 != NULL )
goto V_96;
V_50 = F_76 ( V_143 , V_6 -> V_144 ) ;
V_96:
if ( V_143 )
F_38 ( V_143 ) ;
return V_50 ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_5 * V_142 )
{
struct V_38 * V_143 ;
int V_50 = - V_33 ;
V_143 = F_75 ( V_142 ) ;
if ( ! V_143 || V_143 -> V_35 != V_6 )
goto V_96;
F_78 ( V_143 , V_145 ) ;
V_50 = 0 ;
V_96:
if ( V_143 )
F_38 ( V_143 ) ;
return V_50 ;
}
static void F_79 ( struct V_5 * V_6 )
{
F_72 ( V_6 ) ;
F_80 ( V_6 ) ;
F_81 () ;
F_82 ( V_6 ) ;
}
static void F_83 ( struct V_5 * V_6 )
{
struct V_8 * V_146 = F_9 ( V_6 ) ;
F_84 ( V_6 ) ;
V_6 -> V_147 = & V_148 ;
V_6 -> V_149 = F_79 ;
V_6 -> V_150 = 0 ;
V_6 -> V_34 = V_151 ;
V_6 -> V_152 = V_153 ;
F_85 ( V_6 ) ;
F_86 ( V_6 , & V_154 ) ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
}
struct V_5 * F_87 ( const char * V_144 )
{
struct V_5 * V_35 ;
int V_50 ;
V_35 = F_88 ( sizeof( struct V_8 ) , V_144 ,
F_83 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_155 = & V_156 ;
V_50 = F_89 ( V_35 ) ;
if ( V_50 < 0 ) {
F_90 ( L_2 ,
V_144 , V_50 ) ;
F_82 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
void F_91 ( struct V_5 * V_35 )
{
struct V_8 * V_9 = F_9 ( V_35 ) ;
F_92 ( V_157 , & V_9 -> V_106 ) ;
}
static void F_93 ( struct V_5 * V_35 ,
struct V_158 * V_159 )
{
struct V_38 * V_143 ;
F_94 (hard_iface, &batadv_hardif_list, list) {
if ( V_143 -> V_35 == V_35 )
F_78 ( V_143 ,
V_145 ) ;
}
F_56 ( V_35 ) ;
F_95 ( V_35 , V_159 ) ;
}
int F_96 ( const struct V_5 * V_82 )
{
if ( V_82 -> V_147 -> V_160 == F_18 )
return 1 ;
return 0 ;
}
static int F_97 ( struct V_5 * V_6 , struct V_161 * V_162 )
{
V_162 -> V_163 = 0 ;
V_162 -> V_164 = 0 ;
F_98 ( V_162 , V_165 ) ;
V_162 -> V_166 = V_167 ;
V_162 -> V_168 = V_169 ;
V_162 -> V_170 = 0 ;
V_162 -> V_171 = V_172 ;
V_162 -> V_173 = V_174 ;
V_162 -> V_175 = 0 ;
V_162 -> V_176 = 0 ;
return 0 ;
}
static void F_99 ( struct V_5 * V_6 ,
struct V_177 * V_178 )
{
F_100 ( V_178 -> V_179 , L_3 , sizeof( V_178 -> V_179 ) ) ;
F_100 ( V_178 -> V_74 , V_180 , sizeof( V_178 -> V_74 ) ) ;
F_100 ( V_178 -> V_181 , L_4 , sizeof( V_178 -> V_181 ) ) ;
F_100 ( V_178 -> V_182 , L_5 , sizeof( V_178 -> V_182 ) ) ;
}
static T_6 F_101 ( struct V_5 * V_6 )
{
return - V_183 ;
}
static void F_102 ( struct V_5 * V_6 , T_6 V_184 )
{
}
static T_6 F_103 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_104 ( struct V_5 * V_6 , T_4 V_185 ,
T_1 * V_37 )
{
if ( V_185 == V_186 )
memcpy ( V_37 , V_187 ,
sizeof( V_187 ) ) ;
}
static void F_105 ( struct V_5 * V_6 ,
struct V_188 * V_10 ,
V_108 * V_37 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_189 ;
for ( V_189 = 0 ; V_189 < V_109 ; V_189 ++ )
V_37 [ V_189 ] = F_10 ( V_9 , V_189 ) ;
}
static int F_106 ( struct V_5 * V_6 , int V_185 )
{
if ( V_185 == V_186 )
return V_109 ;
return - V_183 ;
}
