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
static const T_1 V_48 [ V_25 ] = { 0x01 , 0x80 , 0xC2 , 0x00 , 0x00 ,
0x00 } ;
unsigned int V_49 = 0 ;
int V_50 = V_2 -> V_3 , V_51 ;
short T_3 V_52 = - 1 ;
bool V_53 = false ;
T_4 V_54 ;
if ( F_13 ( & V_9 -> V_29 ) != V_30 )
goto V_55;
V_37 -> V_56 = V_57 ;
switch ( F_20 ( V_38 -> V_58 ) ) {
case V_59 :
V_45 = (struct V_44 * ) V_2 -> V_39 ;
T_3 = F_20 ( V_45 -> V_60 ) & V_61 ;
if ( V_45 -> V_62 != V_46 )
break;
case V_47 :
goto V_55;
}
if ( F_21 ( V_9 , V_2 , T_3 ) )
goto V_55;
F_15 ( V_37 , V_38 -> V_63 , V_2 -> V_64 ) ;
if ( F_22 ( V_38 -> V_65 , V_48 ) )
goto V_55;
if ( F_23 ( V_38 -> V_65 ) ) {
V_53 = true ;
switch ( F_13 ( & V_9 -> V_66 ) ) {
case V_67 :
V_51 = F_24 ( V_2 , & V_49 ) ;
if ( V_51 )
goto V_55;
break;
case V_68 :
V_51 = F_24 ( V_2 , & V_49 ) ;
if ( V_51 )
V_53 = false ;
break;
case V_69 :
default:
break;
}
}
if ( V_53 ) {
V_41 = F_25 ( V_9 ) ;
if ( ! V_41 )
goto V_55;
if ( F_1 ( V_2 , sizeof( * V_43 ) ) < 0 )
goto V_55;
V_43 = (struct V_42 * ) V_2 -> V_39 ;
V_43 -> V_70 . V_71 = V_72 ;
V_43 -> V_70 . V_73 = V_74 ;
V_43 -> V_70 . V_75 = V_76 ;
V_43 -> V_77 = 0 ;
memcpy ( V_43 -> V_78 ,
V_41 -> V_79 -> V_28 , V_25 ) ;
V_54 = F_26 ( & V_9 -> V_80 ) ;
V_43 -> V_54 = F_27 ( V_54 ) ;
F_28 ( V_9 , V_2 , 1 ) ;
F_29 ( V_2 ) ;
} else {
if ( F_13 ( & V_9 -> V_66 ) != V_69 ) {
V_51 = F_30 ( V_9 , V_2 , V_38 ) ;
if ( V_51 )
goto V_55;
}
V_51 = F_31 ( V_2 , V_9 ) ;
if ( V_51 != 0 )
goto V_81;
}
F_32 ( V_9 , V_12 ) ;
F_33 ( V_9 , V_14 , V_50 ) ;
goto V_82;
V_55:
F_29 ( V_2 ) ;
V_81:
F_32 ( V_9 , V_16 ) ;
V_82:
if ( V_41 )
F_34 ( V_41 ) ;
return V_83 ;
}
void F_35 ( struct V_5 * V_37 ,
struct V_1 * V_2 , struct V_40 * V_84 ,
int V_85 , struct V_86 * V_87 )
{
struct V_8 * V_9 = F_9 ( V_37 ) ;
struct V_38 * V_38 ;
struct V_44 * V_45 ;
struct V_88 * V_88 = (struct V_88 * ) V_2 -> V_39 ;
short T_3 V_52 = - 1 ;
T_2 V_46 = F_19 ( V_47 ) ;
bool V_89 ;
V_89 = ( V_88 -> V_75 == V_76 ) ;
if ( ! F_36 ( V_2 , V_85 ) )
goto V_55;
F_37 ( V_2 , V_85 ) ;
F_38 ( V_2 ) ;
V_38 = (struct V_38 * ) F_39 ( V_2 ) ;
switch ( F_20 ( V_38 -> V_58 ) ) {
case V_59 :
V_45 = (struct V_44 * ) V_2 -> V_39 ;
T_3 = F_20 ( V_45 -> V_60 ) & V_61 ;
if ( V_45 -> V_62 != V_46 )
break;
case V_47 :
goto V_55;
}
if ( F_40 ( ! F_36 ( V_2 , V_90 ) ) )
goto V_55;
V_2 -> V_91 = F_41 ( V_2 , V_37 ) ;
F_32 ( V_9 , V_18 ) ;
F_33 ( V_9 , V_20 ,
V_2 -> V_3 + V_90 ) ;
V_37 -> V_92 = V_57 ;
if ( F_42 ( V_9 , V_2 , T_3 , V_89 ) )
goto V_93;
if ( V_87 )
F_43 ( V_9 , V_87 ,
V_38 -> V_63 ) ;
if ( F_44 ( V_9 , V_38 -> V_63 , V_38 -> V_65 ) )
goto V_55;
F_45 ( V_2 ) ;
goto V_93;
V_55:
F_29 ( V_2 ) ;
V_93:
return;
}
static void F_46 ( struct V_5 * V_6 )
{
struct V_8 * V_94 = F_9 ( V_6 ) ;
F_47 ( V_6 ) ;
V_6 -> V_95 = & V_96 ;
V_6 -> V_97 = V_98 ;
V_6 -> V_99 = 0 ;
V_6 -> V_36 = V_100 ;
V_6 -> V_101 = V_102 ;
F_48 ( V_6 ) ;
F_49 ( V_6 , & V_103 ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
}
struct V_5 * F_50 ( const char * V_104 )
{
struct V_5 * V_37 ;
struct V_8 * V_9 ;
int V_51 ;
T_5 V_105 = sizeof( V_106 ) * V_107 ;
V_37 = F_51 ( sizeof( * V_9 ) , V_104 ,
F_46 ) ;
if ( ! V_37 )
goto V_93;
V_9 = F_9 ( V_37 ) ;
V_9 -> V_108 = F_52 ( V_105 , F_53 ( V_106 ) ) ;
if ( ! V_9 -> V_108 )
goto V_109;
V_51 = F_54 ( V_37 ) ;
if ( V_51 < 0 ) {
F_55 ( L_2 ,
V_104 , V_51 ) ;
goto V_110;
}
F_56 ( & V_9 -> V_111 , 1 ) ;
F_56 ( & V_9 -> V_112 , 0 ) ;
F_56 ( & V_9 -> V_113 , 0 ) ;
F_56 ( & V_9 -> V_114 , 0 ) ;
F_56 ( & V_9 -> V_115 , V_116 ) ;
F_56 ( & V_9 -> V_66 , V_69 ) ;
F_56 ( & V_9 -> V_117 , 20 ) ;
F_56 ( & V_9 -> V_118 , 41 ) ;
F_56 ( & V_9 -> V_119 , 1000 ) ;
F_56 ( & V_9 -> V_120 , 30 ) ;
F_56 ( & V_9 -> V_121 , 0 ) ;
F_56 ( & V_9 -> V_122 , 1 ) ;
F_56 ( & V_9 -> V_123 , V_124 ) ;
F_56 ( & V_9 -> V_125 , V_126 ) ;
F_56 ( & V_9 -> V_29 , V_127 ) ;
F_56 ( & V_9 -> V_80 , 1 ) ;
F_56 ( & V_9 -> V_128 . V_129 , 0 ) ;
F_56 ( & V_9 -> V_128 . V_130 , 0 ) ;
F_56 ( & V_9 -> V_128 . V_131 , 0 ) ;
#ifdef F_57
F_56 ( & V_9 -> V_132 . V_133 , 0 ) ;
#endif
V_9 -> V_128 . V_134 = NULL ;
V_9 -> V_128 . V_135 = 0 ;
V_9 -> V_128 . V_136 = false ;
V_9 -> V_41 = NULL ;
V_9 -> V_137 = 0 ;
V_51 = F_58 ( V_9 , V_138 ) ;
if ( V_51 < 0 )
goto V_139;
V_51 = F_59 ( V_37 ) ;
if ( V_51 < 0 )
goto V_139;
V_51 = F_60 ( V_37 ) ;
if ( V_51 < 0 )
goto V_140;
V_51 = F_61 ( V_37 ) ;
if ( V_51 < 0 )
goto V_141;
return V_37 ;
V_141:
F_62 ( V_37 ) ;
V_140:
F_63 ( V_37 ) ;
V_139:
F_64 ( V_9 -> V_108 ) ;
F_65 ( V_37 ) ;
return NULL ;
V_110:
F_64 ( V_9 -> V_108 ) ;
V_109:
V_98 ( V_37 ) ;
V_93:
return NULL ;
}
void F_66 ( struct V_5 * V_37 )
{
F_62 ( V_37 ) ;
F_63 ( V_37 ) ;
F_67 ( V_37 ) ;
F_65 ( V_37 ) ;
}
int F_68 ( const struct V_5 * V_79 )
{
if ( V_79 -> V_95 -> V_142 == F_18 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 , struct V_143 * V_144 )
{
V_144 -> V_145 = 0 ;
V_144 -> V_146 = 0 ;
F_70 ( V_144 , V_147 ) ;
V_144 -> V_148 = V_149 ;
V_144 -> V_150 = V_151 ;
V_144 -> V_152 = 0 ;
V_144 -> V_153 = V_154 ;
V_144 -> V_155 = V_156 ;
V_144 -> V_157 = 0 ;
V_144 -> V_158 = 0 ;
return 0 ;
}
static void F_71 ( struct V_5 * V_6 ,
struct V_159 * V_160 )
{
strcpy ( V_160 -> V_161 , L_3 ) ;
strcpy ( V_160 -> V_71 , V_162 ) ;
strcpy ( V_160 -> V_163 , L_4 ) ;
strcpy ( V_160 -> V_164 , L_5 ) ;
}
static T_6 F_72 ( struct V_5 * V_6 )
{
return - V_165 ;
}
static void F_73 ( struct V_5 * V_6 , T_6 V_166 )
{
}
static T_6 F_74 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_75 ( struct V_5 * V_6 , T_4 V_167 ,
T_1 * V_39 )
{
if ( V_167 == V_168 )
memcpy ( V_39 , V_169 ,
sizeof( V_169 ) ) ;
}
static void F_76 ( struct V_5 * V_6 ,
struct V_170 * V_10 ,
V_106 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_171 ;
for ( V_171 = 0 ; V_171 < V_107 ; V_171 ++ )
V_39 [ V_171 ] = F_10 ( V_9 , V_171 ) ;
}
static int F_77 ( struct V_5 * V_6 , int V_167 )
{
if ( V_167 == V_168 )
return V_107 ;
return - V_165 ;
}
