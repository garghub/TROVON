static void F_1 ( T_1 V_1 )
{
F_2 ( L_1 ) ;
if ( V_1 & V_2 )
F_2 ( L_2 ) ;
if ( V_1 & V_3 )
F_2 ( L_3 ) ;
if ( V_1 & V_4 )
F_2 ( L_4 ) ;
if ( V_1 & V_5 )
F_2 ( L_5 ) ;
if ( V_1 & V_6 )
F_2 ( L_6 ) ;
if ( V_1 & V_7 )
F_2 ( L_7 ) ;
if ( V_1 & V_8 )
F_2 ( L_8 ) ;
if ( V_1 & V_9 )
F_2 ( L_9 ) ;
if ( V_1 & V_10 )
F_2 ( L_10 ) ;
if ( V_1 & V_11 )
F_2 ( L_11 ) ;
if ( V_1 & V_12 )
F_2 ( L_12 ) ;
if ( V_1 & V_13 )
F_2 ( L_13 ) ;
if ( V_1 & V_14 )
F_2 ( L_14 ) ;
if ( V_1 & V_15 )
F_2 ( L_15 ) ;
}
static int F_3 ( struct V_16 * V_17 )
{
int V_18 ;
V_18 = F_4 ( V_17 , & V_17 -> V_19 ) ;
if ( F_5 ( V_18 != 0 ) ) {
F_6 ( L_16 ) ;
return V_18 ;
}
return 0 ;
}
static void F_7 ( struct V_16 * V_17 )
{
F_8 ( V_17 , & V_17 -> V_19 ) ;
}
int F_9 ( struct V_16 * V_17 )
{
int V_18 = 0 ;
F_10 ( & V_17 -> V_20 ) ;
if ( F_5 ( V_17 -> V_21 ++ == 0 ) ) {
V_18 = F_3 ( V_17 ) ;
if ( F_5 ( V_18 != 0 ) )
-- V_17 -> V_21 ;
}
F_11 ( & V_17 -> V_20 ) ;
return V_18 ;
}
void F_12 ( struct V_16 * V_17 )
{
T_2 V_22 ;
F_10 ( & V_17 -> V_20 ) ;
if ( F_5 ( -- V_17 -> V_21 == 0 ) )
F_7 ( V_17 ) ;
V_22 = ( T_2 ) V_17 -> V_21 ;
F_11 ( & V_17 -> V_20 ) ;
F_13 ( V_22 < 0 ) ;
}
static int F_14 ( struct V_23 * V_24 , unsigned long V_25 )
{
struct V_16 * V_17 ;
int V_18 ;
T_1 V_26 ;
V_17 = F_15 ( sizeof( * V_17 ) , V_27 ) ;
if ( F_5 ( V_17 == NULL ) ) {
F_6 ( L_17 ) ;
return - V_28 ;
}
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_24 = V_24 ;
V_17 -> V_29 = V_25 ;
V_17 -> V_30 = ( T_1 ) - 100 ;
F_16 ( & V_17 -> V_31 ) ;
F_16 ( & V_17 -> V_32 ) ;
F_16 ( & V_17 -> V_20 ) ;
F_17 ( & V_17 -> V_33 ) ;
F_18 ( & V_17 -> V_34 ) ;
F_18 ( & V_17 -> V_35 ) ;
F_18 ( & V_17 -> V_36 ) ;
F_16 ( & V_17 -> V_37 ) ;
F_19 ( & V_17 -> V_38 ) ;
F_19 ( & V_17 -> V_39 ) ;
F_20 ( & V_17 -> V_40 , 0 ) ;
F_20 ( & V_17 -> V_41 , 0 ) ;
V_17 -> V_42 = F_21 ( V_24 -> V_43 , 0 ) ;
V_17 -> V_44 = F_21 ( V_24 -> V_43 , 1 ) ;
V_17 -> V_45 = F_21 ( V_24 -> V_43 , 2 ) ;
V_17 -> V_46 = V_47 ;
F_10 ( & V_17 -> V_31 ) ;
F_22 ( V_17 , V_48 , V_49 ) ;
V_26 = F_23 ( V_17 , V_48 ) ;
if ( V_26 != V_49 ) {
V_18 = - V_50 ;
F_6 ( L_18 , V_26 ) ;
F_11 ( & V_17 -> V_31 ) ;
goto V_51;
}
V_17 -> V_1 = F_23 ( V_17 , V_52 ) ;
if ( V_17 -> V_1 & V_14 ) {
V_17 -> V_53 =
F_23 ( V_17 ,
V_54 ) ;
V_17 -> V_55 =
F_23 ( V_17 , V_56 ) ;
}
V_17 -> V_57 = F_23 ( V_17 , V_58 ) ;
V_17 -> V_59 = F_23 ( V_17 , V_60 ) ;
V_17 -> V_61 = F_23 ( V_17 , V_62 ) ;
V_17 -> V_63 = F_23 ( V_17 , V_64 ) ;
F_11 ( & V_17 -> V_31 ) ;
F_1 ( V_17 -> V_1 ) ;
if ( V_17 -> V_1 & V_14 ) {
F_2 ( L_19 ,
( unsigned ) V_17 -> V_55 ) ;
F_2 ( L_20 ,
( unsigned ) V_17 -> V_53 ) ;
}
F_2 ( L_21 ,
V_17 -> V_44 , V_17 -> V_57 / 1024 ) ;
F_2 ( L_22 ,
V_17 -> V_45 , V_17 -> V_59 / 1024 ) ;
V_18 = F_24 ( V_17 ) ;
if ( F_5 ( V_18 != 0 ) )
goto V_51;
F_25 ( & V_17 -> V_65 ) ;
F_26 ( & V_17 -> V_65 . V_66 , false , V_67 ) ;
V_17 -> V_68 = & V_17 -> V_65 ;
V_18 = F_27 ( & V_17 -> V_69 ,
V_17 -> V_70 . V_71 . V_72 ,
& V_73 , V_74 ,
false ) ;
if ( F_5 ( V_18 != 0 ) ) {
F_6 ( L_23 ) ;
goto V_75;
}
V_18 = F_28 ( & V_17 -> V_69 , V_76 ,
( V_17 -> V_57 >> V_77 ) ) ;
if ( F_5 ( V_18 != 0 ) ) {
F_6 ( L_24 ) ;
goto V_78;
}
V_17 -> V_79 = true ;
if ( F_28 ( & V_17 -> V_69 , V_80 ,
V_17 -> V_55 ) != 0 ) {
F_2 ( L_25
L_26 ) ;
V_17 -> V_79 = false ;
}
V_17 -> V_81 = F_29 ( V_17 -> V_45 ,
V_17 -> V_59 , V_82 ) ;
V_17 -> V_83 = F_30 ( V_17 -> V_45 ,
V_17 -> V_59 ) ;
if ( F_5 ( V_17 -> V_83 == NULL ) ) {
V_18 = - V_28 ;
F_6 ( L_27 ) ;
goto V_84;
}
if ( ! ( V_17 -> V_1 & V_13 ) &&
! ( V_17 -> V_1 & V_11 ) &&
! F_31 ( V_17 ) ) {
V_18 = - V_50 ;
F_6 ( L_28 ) ;
goto V_85;
}
V_17 -> V_86 = F_32
( V_17 -> V_87 . V_72 , 12 ) ;
if ( F_5 ( V_17 -> V_86 == NULL ) ) {
F_6 ( L_29 ) ;
V_18 = - V_28 ;
goto V_85;
}
V_24 -> V_88 = V_17 ;
V_18 = F_33 ( V_24 -> V_43 , L_30 ) ;
V_17 -> V_89 = ( V_18 != 0 ) ;
if ( V_17 -> V_89 ) {
F_2 ( L_31
L_32 ) ;
V_18 = F_34 ( V_24 -> V_43 , 2 , L_33 ) ;
if ( F_5 ( V_18 != 0 ) ) {
F_6 ( L_34 ) ;
goto V_90;
}
}
V_18 = F_35 ( V_17 ) ;
if ( F_5 ( V_18 != 0 ) )
goto V_91;
F_36 ( V_17 ) ;
if ( V_17 -> V_46 ) {
V_18 = F_9 ( V_17 ) ;
if ( F_5 ( V_18 != 0 ) )
goto V_92;
F_37 ( V_17 ) ;
F_38 ( V_17 ) ;
F_2 ( L_35 , F_39 ( V_17 ) ?
L_36 :
L_37 ) ;
} else {
F_2 ( L_38
L_39 ) ;
}
if ( V_17 -> V_1 & V_12 ) {
V_18 = F_40 ( V_24 ) ;
if ( F_5 ( V_18 != 0 ) ) {
F_6 ( L_40 , V_18 ) ;
goto V_93;
}
}
V_17 -> V_94 . V_95 = V_96 ;
F_41 ( & V_17 -> V_94 ) ;
return 0 ;
V_93:
if ( V_17 -> V_46 ) {
F_42 ( V_17 ) ;
F_43 ( V_17 ) ;
F_12 ( V_17 ) ;
}
V_92:
F_44 ( V_17 ) ;
F_45 ( V_17 ) ;
V_91:
if ( V_17 -> V_89 )
F_46 ( V_24 -> V_43 , 2 ) ;
else
F_47 ( V_24 -> V_43 ) ;
V_90:
F_48 ( & V_17 -> V_86 ) ;
V_85:
F_49 ( V_17 -> V_83 ) ;
V_84:
F_50 ( V_17 -> V_81 , V_17 -> V_45 ,
V_17 -> V_59 , V_82 ) ;
if ( V_17 -> V_79 )
( void ) F_51 ( & V_17 -> V_69 , V_80 ) ;
( void ) F_51 ( & V_17 -> V_69 , V_76 ) ;
V_78:
( void ) F_52 ( & V_17 -> V_69 ) ;
V_75:
F_53 ( V_17 ) ;
V_51:
F_54 ( & V_17 -> V_35 ) ;
F_54 ( & V_17 -> V_34 ) ;
F_54 ( & V_17 -> V_36 ) ;
F_55 ( V_17 ) ;
return V_18 ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_57 ( V_24 ) ;
F_58 ( & V_17 -> V_94 ) ;
if ( V_17 -> V_1 & V_12 )
F_59 ( V_17 -> V_24 ) ;
if ( V_17 -> V_46 ) {
F_42 ( V_17 ) ;
F_43 ( V_17 ) ;
F_12 ( V_17 ) ;
}
F_45 ( V_17 ) ;
F_44 ( V_17 ) ;
if ( V_17 -> V_89 )
F_46 ( V_24 -> V_43 , 2 ) ;
else
F_47 ( V_24 -> V_43 ) ;
F_48 ( & V_17 -> V_86 ) ;
F_49 ( V_17 -> V_83 ) ;
F_50 ( V_17 -> V_81 , V_17 -> V_45 ,
V_17 -> V_59 , V_82 ) ;
if ( V_17 -> V_79 )
( void ) F_51 ( & V_17 -> V_69 , V_80 ) ;
( void ) F_51 ( & V_17 -> V_69 , V_76 ) ;
( void ) F_52 ( & V_17 -> V_69 ) ;
F_53 ( V_17 ) ;
F_54 ( & V_17 -> V_35 ) ;
F_54 ( & V_17 -> V_34 ) ;
F_54 ( & V_17 -> V_36 ) ;
F_55 ( V_17 ) ;
return 0 ;
}
static void F_60 ( struct V_23 * V_24 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 ;
V_100 = V_99 ( V_98 ) ;
F_61 ( & V_100 -> V_101 ) ;
if ( V_100 -> V_102 )
F_62 ( & V_100 -> V_102 ) ;
F_55 ( V_100 ) ;
}
static int F_63 ( struct V_23 * V_24 , struct V_97 * V_98 )
{
struct V_16 * V_17 = F_57 ( V_24 ) ;
struct V_99 * V_100 ;
int V_18 = - V_28 ;
V_100 = F_15 ( sizeof( * V_100 ) , V_27 ) ;
if ( F_5 ( V_100 == NULL ) )
return V_18 ;
V_100 -> V_101 = F_64 ( V_17 -> V_86 , 10 ) ;
if ( F_5 ( V_100 -> V_101 == NULL ) )
goto V_103;
V_98 -> V_104 = V_100 ;
if ( F_5 ( V_17 -> V_69 . V_105 == NULL ) )
V_17 -> V_69 . V_105 =
V_98 -> V_106 -> V_107 . V_108 -> V_109 -> V_110 ;
return 0 ;
V_103:
F_55 ( V_100 ) ;
return V_18 ;
}
static long F_65 ( struct V_111 * V_106 , unsigned int V_112 ,
unsigned long V_113 )
{
struct V_97 * V_98 = V_106 -> V_114 ;
struct V_23 * V_24 = V_98 -> V_115 -> V_24 ;
unsigned int V_116 = F_66 ( V_112 ) ;
if ( ( V_116 >= V_117 ) && ( V_116 < V_118 )
&& ( V_116 < V_117 + V_24 -> V_119 -> V_120 ) ) {
struct V_121 * V_122 =
& V_123 [ V_116 - V_117 ] ;
if ( F_5 ( V_122 -> V_124 != V_112 ) ) {
F_6 ( L_41 ,
V_116 - V_117 ) ;
return - V_125 ;
}
}
return F_67 ( V_106 , V_112 , V_113 ) ;
}
static int F_68 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_57 ( V_24 ) ;
V_17 -> V_126 = true ;
return 0 ;
}
static void F_69 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_57 ( V_24 ) ;
struct V_127 * V_128 ;
struct V_129 V_130 ;
int V_18 ;
if ( ! V_17 -> V_126 )
return;
V_17 -> V_126 = false ;
V_130 . V_131 = 0 ;
V_130 . V_132 = 0 ;
V_130 . V_133 = NULL ;
V_130 . V_134 = NULL ;
V_130 . V_135 = NULL ;
V_130 . V_136 = 0 ;
F_70 (crtc, &dev->mode_config.crtc_list, head) {
V_130 . V_128 = V_128 ;
V_18 = V_128 -> V_137 -> V_138 ( & V_130 ) ;
F_71 ( V_18 != 0 ) ;
}
}
static void F_25 ( struct V_139 * V_140 )
{
F_72 ( & V_140 -> V_66 ) ;
F_73 ( & V_140 -> V_141 ) ;
F_16 ( & V_140 -> V_142 ) ;
}
static int F_74 ( struct V_23 * V_24 ,
struct V_143 * V_144 )
{
struct V_139 * V_140 ;
V_140 = F_15 ( sizeof( * V_140 ) , V_27 ) ;
if ( F_5 ( V_140 == NULL ) )
return - V_28 ;
F_25 ( V_140 ) ;
F_26 ( & V_140 -> V_66 , true , V_67 ) ;
V_144 -> V_104 = V_140 ;
return 0 ;
}
static void F_75 ( struct V_23 * V_24 ,
struct V_143 * V_144 )
{
struct V_139 * V_140 = V_139 ( V_144 ) ;
V_144 -> V_104 = NULL ;
F_55 ( V_140 ) ;
}
static int F_76 ( struct V_23 * V_24 ,
struct V_97 * V_98 ,
bool V_145 )
{
struct V_16 * V_17 = F_57 ( V_24 ) ;
struct V_99 * V_100 = V_99 ( V_98 ) ;
struct V_139 * V_146 = V_17 -> V_68 ;
struct V_139 * V_140 = V_139 ( V_98 -> V_144 ) ;
int V_18 = 0 ;
if ( ! V_17 -> V_46 ) {
V_18 = F_9 ( V_17 ) ;
if ( F_5 ( V_18 != 0 ) )
return V_18 ;
F_37 ( V_17 ) ;
F_10 ( & V_17 -> V_31 ) ;
F_22 ( V_17 , V_147 , 0 ) ;
F_11 ( & V_17 -> V_31 ) ;
}
if ( V_146 ) {
F_13 ( V_146 != & V_17 -> V_65 ) ;
V_18 = F_77 ( & V_146 -> V_66 , false , V_100 -> V_101 ) ;
if ( F_5 ( V_18 != 0 ) )
goto V_148;
F_26 ( & V_146 -> V_66 , true , V_67 ) ;
V_18 = F_78 ( & V_17 -> V_69 , V_76 ) ;
if ( F_5 ( V_18 != 0 ) ) {
F_6 ( L_42
L_43 ) ;
}
V_17 -> V_68 = NULL ;
}
F_26 ( & V_140 -> V_66 , false , V_67 ) ;
if ( ! V_145 ) {
F_79 ( & V_140 -> V_66 ) ;
F_13 ( V_100 -> V_102 != V_98 -> V_144 ) ;
F_62 ( & V_100 -> V_102 ) ;
}
V_17 -> V_68 = V_140 ;
return 0 ;
V_148:
if ( ! V_17 -> V_46 ) {
F_10 ( & V_17 -> V_31 ) ;
F_22 ( V_17 , V_147 , 1 ) ;
F_11 ( & V_17 -> V_31 ) ;
F_43 ( V_17 ) ;
F_12 ( V_17 ) ;
}
return V_18 ;
}
static void F_80 ( struct V_23 * V_24 ,
struct V_97 * V_98 ,
bool V_149 )
{
struct V_16 * V_17 = F_57 ( V_24 ) ;
struct V_99 * V_100 = V_99 ( V_98 ) ;
struct V_139 * V_140 = V_139 ( V_98 -> V_144 ) ;
int V_18 ;
V_100 -> V_102 = F_81 ( V_98 -> V_144 ) ;
V_18 = F_77 ( & V_140 -> V_66 , false , V_100 -> V_101 ) ;
F_82 ( V_140 ) ;
if ( F_5 ( ( V_18 != 0 ) ) ) {
F_6 ( L_44 ) ;
F_62 ( & V_100 -> V_102 ) ;
}
F_26 ( & V_140 -> V_66 , true , V_67 ) ;
if ( ! V_17 -> V_46 ) {
V_18 = F_78 ( & V_17 -> V_69 , V_76 ) ;
if ( F_5 ( V_18 != 0 ) )
F_6 ( L_45 ) ;
F_10 ( & V_17 -> V_31 ) ;
F_22 ( V_17 , V_147 , 1 ) ;
F_11 ( & V_17 -> V_31 ) ;
F_43 ( V_17 ) ;
F_12 ( V_17 ) ;
}
V_17 -> V_68 = & V_17 -> V_65 ;
F_26 ( & V_17 -> V_65 . V_66 , false , V_67 ) ;
F_79 ( & V_17 -> V_65 . V_66 ) ;
if ( V_17 -> V_46 )
F_83 ( V_17 ) ;
}
static void F_84 ( struct V_150 * V_43 )
{
struct V_23 * V_24 = F_85 ( V_43 ) ;
F_86 ( V_24 ) ;
}
static int V_96 ( struct V_151 * V_152 , unsigned long V_153 ,
void * V_154 )
{
struct V_16 * V_17 =
F_87 ( V_152 , struct V_16 , V_94 ) ;
struct V_139 * V_140 = V_17 -> V_68 ;
switch ( V_153 ) {
case V_155 :
case V_156 :
F_88 ( & V_140 -> V_66 ) ;
F_89 ( & V_17 -> V_69 ) ;
break;
case V_157 :
case V_158 :
case V_159 :
F_90 ( & V_140 -> V_66 ) ;
break;
case V_160 :
break;
default:
break;
}
return 0 ;
}
static int F_91 ( struct V_150 * V_43 , T_3 V_161 )
{
struct V_23 * V_24 = F_85 ( V_43 ) ;
struct V_16 * V_17 = F_57 ( V_24 ) ;
if ( V_17 -> V_21 != 0 ) {
F_2 ( L_46
L_47 ) ;
return - V_162 ;
}
F_92 ( V_43 ) ;
F_93 ( V_43 ) ;
F_94 ( V_43 , V_163 ) ;
return 0 ;
}
static int F_95 ( struct V_150 * V_43 )
{
F_94 ( V_43 , V_164 ) ;
F_96 ( V_43 ) ;
return F_97 ( V_43 ) ;
}
static int F_98 ( struct V_165 * V_166 )
{
struct V_150 * V_43 = F_99 ( V_166 ) ;
struct V_167 V_168 ;
V_168 . V_169 = 0 ;
return F_91 ( V_43 , V_168 ) ;
}
static int F_100 ( struct V_165 * V_166 )
{
struct V_150 * V_43 = F_99 ( V_166 ) ;
return F_95 ( V_43 ) ;
}
static int F_101 ( struct V_165 * V_166 )
{
struct V_150 * V_43 = F_99 ( V_166 ) ;
struct V_23 * V_24 = F_85 ( V_43 ) ;
struct V_16 * V_17 = F_57 ( V_24 ) ;
V_17 -> V_170 = true ;
if ( V_17 -> V_46 )
F_12 ( V_17 ) ;
if ( V_17 -> V_21 != 0 ) {
F_2 ( L_46
L_47 ) ;
if ( V_17 -> V_46 )
F_9 ( V_17 ) ;
V_17 -> V_170 = false ;
return - V_162 ;
}
return 0 ;
}
static void F_102 ( struct V_165 * V_166 )
{
struct V_150 * V_43 = F_99 ( V_166 ) ;
struct V_23 * V_24 = F_85 ( V_43 ) ;
struct V_16 * V_17 = F_57 ( V_24 ) ;
if ( V_17 -> V_46 )
F_9 ( V_17 ) ;
V_17 -> V_170 = false ;
}
static int F_103 ( struct V_150 * V_43 , const struct V_171 * V_172 )
{
return F_104 ( V_43 , V_172 , & V_119 ) ;
}
static int T_4 F_105 ( void )
{
int V_18 ;
V_18 = F_106 ( & V_119 , & V_173 ) ;
if ( V_18 )
F_6 ( L_48 ) ;
return V_18 ;
}
static void T_5 F_107 ( void )
{
F_108 ( & V_119 , & V_173 ) ;
}
