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
return & V_9 -> V_10 ;
}
static int F_10 ( struct V_5 * V_6 , void * V_11 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_12 * V_13 = V_11 ;
T_1 V_14 [ V_15 ] ;
if ( ! F_11 ( V_13 -> V_16 ) )
return - V_17 ;
memcpy ( V_14 , V_6 -> V_18 , V_15 ) ;
memcpy ( V_6 -> V_18 , V_13 -> V_16 , V_15 ) ;
if ( F_12 ( & V_9 -> V_19 ) == V_20 ) {
F_13 ( V_9 , V_14 ,
L_1 , false ) ;
F_14 ( V_6 , V_13 -> V_16 , V_21 ) ;
}
V_6 -> V_22 &= ~ V_23 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , int V_24 )
{
if ( ( V_24 < 68 ) || ( V_24 > F_16 ( V_6 ) ) )
return - V_25 ;
V_6 -> V_26 = V_24 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_5 * V_27 )
{
struct V_28 * V_28 = (struct V_28 * ) V_2 -> V_29 ;
struct V_8 * V_9 = F_9 ( V_27 ) ;
struct V_30 * V_31 = NULL ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_2 V_36 = F_18 ( V_37 ) ;
static const T_1 V_38 [ V_15 ] = { 0x01 , 0x80 , 0xC2 , 0x00 , 0x00 ,
0x00 } ;
unsigned int V_39 = 0 ;
int V_40 = V_2 -> V_3 , V_41 ;
short T_3 V_42 = - 1 ;
bool V_43 = false ;
if ( F_12 ( & V_9 -> V_19 ) != V_20 )
goto V_44;
V_27 -> V_45 = V_46 ;
switch ( F_19 ( V_28 -> V_47 ) ) {
case V_48 :
V_35 = (struct V_34 * ) V_2 -> V_29 ;
T_3 = F_19 ( V_35 -> V_49 ) & V_50 ;
if ( V_35 -> V_51 != V_36 )
break;
case V_37 :
goto V_44;
}
if ( F_20 ( V_9 , V_2 , T_3 ) )
goto V_44;
F_14 ( V_27 , V_28 -> V_52 , V_2 -> V_53 ) ;
if ( F_21 ( V_28 -> V_54 , V_38 ) )
goto V_44;
if ( F_22 ( V_28 -> V_54 ) ) {
V_43 = true ;
switch ( F_12 ( & V_9 -> V_55 ) ) {
case V_56 :
V_41 = F_23 ( V_2 , & V_39 ) ;
if ( V_41 )
goto V_44;
break;
case V_57 :
V_41 = F_23 ( V_2 , & V_39 ) ;
if ( V_41 )
V_43 = false ;
break;
case V_58 :
default:
break;
}
}
if ( V_43 ) {
V_31 = F_24 ( V_9 ) ;
if ( ! V_31 )
goto V_44;
if ( F_1 ( V_2 , sizeof( * V_33 ) ) < 0 )
goto V_44;
V_33 = (struct V_32 * ) V_2 -> V_29 ;
V_33 -> V_59 . V_60 = V_61 ;
V_33 -> V_59 . V_62 = V_63 ;
V_33 -> V_59 . V_64 = V_65 ;
V_33 -> V_66 = 0 ;
memcpy ( V_33 -> V_67 ,
V_31 -> V_68 -> V_18 , V_15 ) ;
V_33 -> V_69 =
F_25 ( F_26 ( & V_9 -> V_70 ) ) ;
F_27 ( V_9 , V_2 , 1 ) ;
F_28 ( V_2 ) ;
} else {
if ( F_12 ( & V_9 -> V_55 ) != V_58 ) {
V_41 = F_29 ( V_9 , V_2 , V_28 ) ;
if ( V_41 )
goto V_44;
}
V_41 = F_30 ( V_2 , V_9 ) ;
if ( V_41 != 0 )
goto V_71;
}
V_9 -> V_10 . V_72 ++ ;
V_9 -> V_10 . V_73 += V_40 ;
goto V_74;
V_44:
F_28 ( V_2 ) ;
V_71:
V_9 -> V_10 . V_75 ++ ;
V_74:
if ( V_31 )
F_31 ( V_31 ) ;
return V_76 ;
}
void F_32 ( struct V_5 * V_27 ,
struct V_1 * V_2 , struct V_30 * V_77 ,
int V_78 )
{
struct V_8 * V_9 = F_9 ( V_27 ) ;
struct V_28 * V_28 ;
struct V_34 * V_35 ;
struct V_79 * V_79 = (struct V_79 * ) V_2 -> V_29 ;
short T_3 V_42 = - 1 ;
T_2 V_36 = F_18 ( V_37 ) ;
bool V_80 ;
V_80 = ( V_79 -> V_64 == V_65 ) ;
if ( ! F_33 ( V_2 , V_78 ) )
goto V_44;
F_34 ( V_2 , V_78 ) ;
F_35 ( V_2 ) ;
V_28 = (struct V_28 * ) F_36 ( V_2 ) ;
switch ( F_19 ( V_28 -> V_47 ) ) {
case V_48 :
V_35 = (struct V_34 * ) V_2 -> V_29 ;
T_3 = F_19 ( V_35 -> V_49 ) & V_50 ;
if ( V_35 -> V_51 != V_36 )
break;
case V_37 :
goto V_44;
}
if ( F_37 ( ! F_33 ( V_2 , V_81 ) ) )
goto V_44;
V_2 -> V_82 = F_38 ( V_2 , V_27 ) ;
V_9 -> V_10 . V_83 ++ ;
V_9 -> V_10 . V_84 += V_2 -> V_3 + V_81 ;
V_27 -> V_85 = V_46 ;
if ( F_39 ( V_9 , V_28 -> V_52 , V_28 -> V_54 ) )
goto V_44;
if ( F_40 ( V_9 , V_2 , T_3 , V_80 ) )
goto V_86;
F_41 ( V_2 ) ;
goto V_86;
V_44:
F_28 ( V_2 ) ;
V_86:
return;
}
static void F_42 ( struct V_5 * V_6 )
{
struct V_8 * V_87 = F_9 ( V_6 ) ;
F_43 ( V_6 ) ;
V_6 -> V_88 = & V_89 ;
V_6 -> V_90 = V_91 ;
V_6 -> V_92 = 0 ;
V_6 -> V_26 = V_93 ;
V_6 -> V_94 = V_95 ;
F_44 ( V_6 ) ;
F_45 ( V_6 , & V_96 ) ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
}
struct V_5 * F_46 ( const char * V_97 )
{
struct V_5 * V_27 ;
struct V_8 * V_9 ;
int V_41 ;
T_4 V_98 = sizeof( V_99 ) * V_100 ;
V_27 = F_47 ( sizeof( * V_9 ) , V_97 ,
F_42 ) ;
if ( ! V_27 )
goto V_86;
V_41 = F_48 ( V_27 ) ;
if ( V_41 < 0 ) {
F_49 ( L_2 ,
V_97 , V_41 ) ;
goto V_101;
}
V_9 = F_9 ( V_27 ) ;
F_50 ( & V_9 -> V_102 , 1 ) ;
F_50 ( & V_9 -> V_103 , 0 ) ;
F_50 ( & V_9 -> V_104 , 0 ) ;
F_50 ( & V_9 -> V_105 , 0 ) ;
F_50 ( & V_9 -> V_106 , V_107 ) ;
F_50 ( & V_9 -> V_55 , V_58 ) ;
F_50 ( & V_9 -> V_108 , 20 ) ;
F_50 ( & V_9 -> V_109 , 41 ) ;
F_50 ( & V_9 -> V_110 , 1000 ) ;
F_50 ( & V_9 -> V_111 , 30 ) ;
F_50 ( & V_9 -> V_112 , 0 ) ;
F_50 ( & V_9 -> V_113 , 1 ) ;
F_50 ( & V_9 -> V_114 , V_115 ) ;
F_50 ( & V_9 -> V_116 , V_117 ) ;
F_50 ( & V_9 -> V_19 , V_118 ) ;
F_50 ( & V_9 -> V_70 , 1 ) ;
F_50 ( & V_9 -> V_119 , 0 ) ;
F_50 ( & V_9 -> V_120 , 0 ) ;
F_50 ( & V_9 -> V_121 , 0 ) ;
F_50 ( & V_9 -> V_122 , 0 ) ;
V_9 -> V_123 = NULL ;
V_9 -> V_124 = 0 ;
V_9 -> V_125 = false ;
V_9 -> V_31 = NULL ;
V_9 -> V_126 = 0 ;
V_9 -> V_127 = F_51 ( V_98 , F_52 ( V_99 ) ) ;
if ( ! V_9 -> V_127 )
goto V_128;
V_41 = F_53 ( V_9 , V_129 ) ;
if ( V_41 < 0 )
goto V_130;
V_41 = F_54 ( V_27 ) ;
if ( V_41 < 0 )
goto V_130;
V_41 = F_55 ( V_27 ) ;
if ( V_41 < 0 )
goto V_131;
V_41 = F_56 ( V_27 ) ;
if ( V_41 < 0 )
goto V_132;
return V_27 ;
V_132:
F_57 ( V_27 ) ;
V_131:
F_58 ( V_27 ) ;
V_130:
F_59 ( V_9 -> V_127 ) ;
V_128:
F_60 ( V_27 ) ;
return NULL ;
V_101:
V_91 ( V_27 ) ;
V_86:
return NULL ;
}
void F_61 ( struct V_5 * V_27 )
{
F_57 ( V_27 ) ;
F_58 ( V_27 ) ;
F_62 ( V_27 ) ;
F_60 ( V_27 ) ;
}
int F_63 ( const struct V_5 * V_68 )
{
if ( V_68 -> V_88 -> V_133 == F_17 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_134 * V_135 )
{
V_135 -> V_136 = 0 ;
V_135 -> V_137 = 0 ;
F_65 ( V_135 , V_138 ) ;
V_135 -> V_139 = V_140 ;
V_135 -> V_141 = V_142 ;
V_135 -> V_143 = 0 ;
V_135 -> V_144 = V_145 ;
V_135 -> V_146 = V_147 ;
V_135 -> V_148 = 0 ;
V_135 -> V_149 = 0 ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 ,
struct V_150 * V_151 )
{
strcpy ( V_151 -> V_152 , L_3 ) ;
strcpy ( V_151 -> V_60 , V_153 ) ;
strcpy ( V_151 -> V_154 , L_4 ) ;
strcpy ( V_151 -> V_155 , L_5 ) ;
}
static T_5 F_67 ( struct V_5 * V_6 )
{
return - V_156 ;
}
static void F_68 ( struct V_5 * V_6 , T_5 V_157 )
{
}
static T_5 F_69 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_70 ( struct V_5 * V_6 , T_6 V_158 ,
T_1 * V_29 )
{
if ( V_158 == V_159 )
memcpy ( V_29 , V_160 ,
sizeof( V_160 ) ) ;
}
static void F_71 ( struct V_5 * V_6 ,
struct V_161 * V_10 ,
V_99 * V_29 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_162 ;
for ( V_162 = 0 ; V_162 < V_100 ; V_162 ++ )
V_29 [ V_162 ] = F_72 ( V_9 , V_162 ) ;
}
static int F_73 ( struct V_5 * V_6 , int V_158 )
{
if ( V_158 == V_159 )
return V_100 ;
return - V_156 ;
}
