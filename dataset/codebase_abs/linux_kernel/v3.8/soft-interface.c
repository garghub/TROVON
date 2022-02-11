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
V_6 -> V_32 &= ~ V_33 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , int V_34 )
{
if ( ( V_34 < 68 ) || ( V_34 > F_17 ( V_6 ) ) )
return - V_35 ;
V_6 -> V_36 = V_34 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_5 * V_37 )
{
struct V_38 * V_38 = (struct V_38 * ) V_2 -> V_39 ;
struct V_8 * V_9 = F_9 ( V_37 ) ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
T_2 V_46 = F_19 ( V_47 ) ;
static const T_1 V_48 [ V_25 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_49 [ V_25 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
unsigned int V_50 = 0 ;
int V_51 = V_2 -> V_3 , V_52 ;
short T_3 V_53 = - 1 ;
bool V_54 = false ;
T_4 V_55 ;
unsigned long V_56 = 1 ;
if ( F_13 ( & V_9 -> V_29 ) != V_30 )
goto V_57;
V_37 -> V_58 = V_59 ;
switch ( F_20 ( V_38 -> V_60 ) ) {
case V_61 :
V_45 = (struct V_44 * ) V_2 -> V_39 ;
T_3 = F_20 ( V_45 -> V_62 ) & V_63 ;
if ( V_45 -> V_64 != V_46 )
break;
case V_47 :
goto V_57;
}
if ( F_21 ( V_9 , V_2 , T_3 ) )
goto V_57;
F_15 ( V_37 , V_38 -> V_65 , V_2 -> V_66 ) ;
if ( F_22 ( V_38 -> V_67 , V_48 ) )
goto V_57;
if ( F_22 ( V_38 -> V_67 , V_49 ) )
goto V_57;
if ( F_23 ( V_38 -> V_67 ) ) {
V_54 = true ;
switch ( F_13 ( & V_9 -> V_68 ) ) {
case V_69 :
V_52 = F_24 ( V_2 , & V_50 ) ;
if ( V_52 )
goto V_57;
break;
case V_70 :
V_52 = F_24 ( V_2 , & V_50 ) ;
if ( V_52 )
V_54 = false ;
break;
case V_71 :
default:
break;
}
}
if ( V_54 ) {
V_41 = F_25 ( V_9 ) ;
if ( ! V_41 )
goto V_57;
if ( F_26 ( V_9 , V_2 ) )
V_56 = F_27 ( V_72 ) ;
if ( F_1 ( V_2 , sizeof( * V_43 ) ) < 0 )
goto V_57;
V_43 = (struct V_42 * ) V_2 -> V_39 ;
V_43 -> V_73 . V_74 = V_75 ;
V_43 -> V_73 . V_76 = V_77 ;
V_43 -> V_73 . V_78 = V_79 ;
V_43 -> V_80 = 0 ;
memcpy ( V_43 -> V_81 ,
V_41 -> V_82 -> V_28 , V_25 ) ;
V_55 = F_28 ( & V_9 -> V_83 ) ;
V_43 -> V_55 = F_29 ( V_55 ) ;
F_30 ( V_9 , V_2 , V_56 ) ;
F_31 ( V_2 ) ;
} else {
if ( F_13 ( & V_9 -> V_68 ) != V_71 ) {
V_52 = F_32 ( V_9 , V_2 , V_38 ) ;
if ( V_52 )
goto V_57;
}
if ( F_26 ( V_9 , V_2 ) )
goto V_57;
F_33 ( V_9 , V_2 ) ;
V_52 = F_34 ( V_9 , V_2 ) ;
if ( V_52 != 0 )
goto V_84;
}
F_35 ( V_9 , V_12 ) ;
F_36 ( V_9 , V_14 , V_51 ) ;
goto V_85;
V_57:
F_31 ( V_2 ) ;
V_84:
F_35 ( V_9 , V_16 ) ;
V_85:
if ( V_41 )
F_37 ( V_41 ) ;
return V_86 ;
}
void F_38 ( struct V_5 * V_37 ,
struct V_1 * V_2 , struct V_40 * V_87 ,
int V_88 , struct V_89 * V_90 )
{
struct V_8 * V_9 = F_9 ( V_37 ) ;
struct V_38 * V_38 ;
struct V_44 * V_45 ;
struct V_91 * V_91 = (struct V_91 * ) V_2 -> V_39 ;
short T_3 V_53 = - 1 ;
T_2 V_46 = F_19 ( V_47 ) ;
bool V_92 ;
V_92 = ( V_91 -> V_78 == V_79 ) ;
if ( ! F_39 ( V_2 , V_88 ) )
goto V_57;
F_40 ( V_2 , V_88 ) ;
F_41 ( V_2 ) ;
V_38 = (struct V_38 * ) F_42 ( V_2 ) ;
switch ( F_20 ( V_38 -> V_60 ) ) {
case V_61 :
V_45 = (struct V_44 * ) V_2 -> V_39 ;
T_3 = F_20 ( V_45 -> V_62 ) & V_63 ;
if ( V_45 -> V_64 != V_46 )
break;
case V_47 :
goto V_57;
}
if ( F_43 ( ! F_39 ( V_2 , V_93 ) ) )
goto V_57;
V_2 -> V_94 = F_44 ( V_2 , V_37 ) ;
F_35 ( V_9 , V_18 ) ;
F_36 ( V_9 , V_20 ,
V_2 -> V_3 + V_93 ) ;
V_37 -> V_95 = V_59 ;
if ( F_45 ( V_9 , V_2 , T_3 , V_92 ) )
goto V_96;
if ( V_90 )
F_46 ( V_9 , V_90 ,
V_38 -> V_65 ) ;
if ( F_47 ( V_9 , V_38 -> V_65 , V_38 -> V_67 ) )
goto V_57;
F_48 ( V_2 ) ;
goto V_96;
V_57:
F_31 ( V_2 ) ;
V_96:
return;
}
static void F_49 ( struct V_5 * V_6 ,
struct V_97 * V_98 ,
void * V_99 )
{
F_50 ( & V_98 -> V_100 , & V_101 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_50 ( & V_6 -> V_102 , & V_103 ) ;
F_52 ( V_6 , F_49 , NULL ) ;
}
static int F_53 ( struct V_5 * V_6 )
{
F_51 ( V_6 ) ;
return 0 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_8 * V_104 = F_9 ( V_6 ) ;
F_55 ( V_6 ) ;
V_6 -> V_105 = & V_106 ;
V_6 -> V_107 = V_108 ;
V_6 -> V_109 = 0 ;
V_6 -> V_36 = V_110 ;
V_6 -> V_111 = V_112 ;
F_56 ( V_6 ) ;
F_57 ( V_6 , & V_113 ) ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
}
struct V_5 * F_58 ( const char * V_114 )
{
struct V_5 * V_37 ;
struct V_8 * V_9 ;
int V_52 ;
T_5 V_115 = sizeof( V_116 ) * V_117 ;
V_37 = F_59 ( sizeof( * V_9 ) , V_114 ,
F_54 ) ;
if ( ! V_37 )
goto V_96;
V_9 = F_9 ( V_37 ) ;
V_9 -> V_118 = F_60 ( V_115 , F_61 ( V_116 ) ) ;
if ( ! V_9 -> V_118 )
goto V_119;
V_52 = F_62 ( V_37 ) ;
if ( V_52 < 0 ) {
F_63 ( L_2 ,
V_114 , V_52 ) ;
goto V_120;
}
F_64 ( & V_9 -> V_121 , 1 ) ;
F_64 ( & V_9 -> V_122 , 0 ) ;
F_64 ( & V_9 -> V_123 , 0 ) ;
#ifdef F_65
F_64 ( & V_9 -> V_124 , 1 ) ;
#endif
F_64 ( & V_9 -> V_125 , 0 ) ;
F_64 ( & V_9 -> V_126 , V_127 ) ;
F_64 ( & V_9 -> V_68 , V_71 ) ;
F_64 ( & V_9 -> V_128 , 20 ) ;
F_64 ( & V_9 -> V_129 , 41 ) ;
F_64 ( & V_9 -> V_130 , 1000 ) ;
F_64 ( & V_9 -> V_131 , 30 ) ;
F_64 ( & V_9 -> V_132 , 0 ) ;
F_64 ( & V_9 -> V_133 , 1 ) ;
F_64 ( & V_9 -> V_134 , V_135 ) ;
F_64 ( & V_9 -> V_136 , V_137 ) ;
F_64 ( & V_9 -> V_29 , V_138 ) ;
F_64 ( & V_9 -> V_83 , 1 ) ;
F_64 ( & V_9 -> V_139 . V_140 , 0 ) ;
F_64 ( & V_9 -> V_139 . V_141 , 0 ) ;
F_64 ( & V_9 -> V_139 . V_142 , 0 ) ;
#ifdef F_66
F_64 ( & V_9 -> V_143 . V_144 , 0 ) ;
#endif
V_9 -> V_139 . V_145 = NULL ;
V_9 -> V_139 . V_146 = 0 ;
V_9 -> V_41 = NULL ;
V_9 -> V_147 = 0 ;
V_52 = F_67 ( V_9 , V_148 ) ;
if ( V_52 < 0 )
goto V_149;
V_52 = F_68 ( V_37 ) ;
if ( V_52 < 0 )
goto V_149;
V_52 = F_69 ( V_37 ) ;
if ( V_52 < 0 )
goto V_150;
V_52 = F_70 ( V_37 ) ;
if ( V_52 < 0 )
goto V_151;
return V_37 ;
V_151:
F_71 ( V_37 ) ;
V_150:
F_72 ( V_37 ) ;
V_149:
F_73 ( V_9 -> V_118 ) ;
F_74 ( V_37 ) ;
return NULL ;
V_120:
F_73 ( V_9 -> V_118 ) ;
V_119:
V_108 ( V_37 ) ;
V_96:
return NULL ;
}
void F_75 ( struct V_5 * V_37 )
{
F_71 ( V_37 ) ;
F_72 ( V_37 ) ;
F_76 ( V_37 ) ;
F_74 ( V_37 ) ;
}
int F_77 ( const struct V_5 * V_82 )
{
if ( V_82 -> V_105 -> V_152 == F_18 )
return 1 ;
return 0 ;
}
static int F_78 ( struct V_5 * V_6 , struct V_153 * V_154 )
{
V_154 -> V_155 = 0 ;
V_154 -> V_156 = 0 ;
F_79 ( V_154 , V_157 ) ;
V_154 -> V_158 = V_159 ;
V_154 -> V_160 = V_161 ;
V_154 -> V_162 = 0 ;
V_154 -> V_163 = V_164 ;
V_154 -> V_165 = V_166 ;
V_154 -> V_167 = 0 ;
V_154 -> V_168 = 0 ;
return 0 ;
}
static void F_80 ( struct V_5 * V_6 ,
struct V_169 * V_170 )
{
strcpy ( V_170 -> V_171 , L_3 ) ;
strcpy ( V_170 -> V_74 , V_172 ) ;
strcpy ( V_170 -> V_173 , L_4 ) ;
strcpy ( V_170 -> V_174 , L_5 ) ;
}
static T_6 F_81 ( struct V_5 * V_6 )
{
return - V_175 ;
}
static void F_82 ( struct V_5 * V_6 , T_6 V_176 )
{
}
static T_6 F_83 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_84 ( struct V_5 * V_6 , T_4 V_177 ,
T_1 * V_39 )
{
if ( V_177 == V_178 )
memcpy ( V_39 , V_179 ,
sizeof( V_179 ) ) ;
}
static void F_85 ( struct V_5 * V_6 ,
struct V_180 * V_10 ,
V_116 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_181 ;
for ( V_181 = 0 ; V_181 < V_117 ; V_181 ++ )
V_39 [ V_181 ] = F_10 ( V_9 , V_181 ) ;
}
static int F_86 ( struct V_5 * V_6 , int V_177 )
{
if ( V_177 == V_178 )
return V_117 ;
return - V_175 ;
}
