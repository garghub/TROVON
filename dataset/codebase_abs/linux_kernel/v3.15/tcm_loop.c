static int F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 & V_3 )
return 0 ;
F_2 ( V_1 , 0 ) ;
return 1 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
F_5 ( V_7 , V_5 ) ;
}
static int F_6 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
F_7 ( V_9 , L_1 ) ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
return 1 ;
}
static int F_9 (
struct V_16 * V_17 ,
int V_18 ,
int V_19 )
{
switch ( V_19 ) {
case V_20 :
F_10 ( V_17 , F_11 ( V_17 ) , V_18 ) ;
break;
case V_21 :
F_12 ( V_17 , V_18 ) ;
break;
case V_22 :
F_10 ( V_17 , F_11 ( V_17 ) , V_18 ) ;
break;
default:
return - V_23 ;
}
return V_17 -> V_24 ;
}
static int F_13 ( struct V_16 * V_17 , int V_25 )
{
if ( V_17 -> V_26 ) {
F_14 ( V_17 , V_25 ) ;
if ( V_25 )
F_15 ( V_17 , V_17 -> V_24 ) ;
else
F_16 ( V_17 , V_17 -> V_24 ) ;
} else
V_25 = 0 ;
return V_25 ;
}
static int F_17 ( struct V_27 * V_28 )
{
if ( V_28 -> V_12 -> V_26 ) {
switch ( V_28 -> V_25 ) {
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
default:
break;
}
}
return V_33 ;
}
static void F_18 ( struct V_34 * V_35 )
{
struct V_4 * V_5 =
F_4 ( V_35 , struct V_4 , V_35 ) ;
struct V_1 * V_1 = & V_5 -> V_6 ;
struct V_27 * V_28 = V_5 -> V_28 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 = NULL ;
T_1 V_44 = 0 ;
int V_45 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
if ( ! V_41 -> V_39 ) {
F_20 ( V_28 , V_48 ) ;
goto V_49;
}
if ( V_41 -> V_50 == V_51 ) {
F_20 ( V_28 , V_52 ) ;
goto V_49;
}
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_21 ( V_53 , V_28 , L_2
L_3 ) ;
F_20 ( V_28 , V_54 ) ;
goto V_49;
}
if ( F_22 ( V_28 ) ) {
struct V_55 * V_56 = F_23 ( V_28 ) ;
V_43 = V_56 -> V_57 . V_58 ;
V_44 = V_56 -> V_57 . V_59 ;
V_1 -> V_2 |= V_60 ;
}
if ( ! F_24 ( V_28 ) && F_25 ( V_28 ) != V_61 )
V_1 -> V_62 = true ;
V_45 = F_26 ( V_1 , V_37 -> V_63 , V_28 -> V_64 ,
& V_5 -> V_65 [ 0 ] , V_5 -> V_28 -> V_12 -> V_66 ,
F_27 ( V_28 ) , F_17 ( V_28 ) ,
V_28 -> V_67 , 0 ,
F_28 ( V_28 ) , F_29 ( V_28 ) ,
V_43 , V_44 ,
F_30 ( V_28 ) , F_24 ( V_28 ) ) ;
if ( V_45 < 0 ) {
F_20 ( V_28 , V_48 ) ;
goto V_49;
}
return;
V_49:
V_28 -> V_68 ( V_28 ) ;
return;
}
static int F_31 ( struct V_10 * V_69 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
F_32 ( L_4
L_5 , V_28 -> V_12 -> V_11 -> V_70 ,
V_28 -> V_12 -> V_47 , V_28 -> V_12 -> V_71 , V_28 -> V_12 -> V_66 ,
V_28 -> V_64 [ 0 ] , F_27 ( V_28 ) ) ;
V_5 = F_33 ( V_7 , V_72 ) ;
if ( ! V_5 ) {
F_34 ( L_6 ) ;
F_20 ( V_28 , V_54 ) ;
V_28 -> V_68 ( V_28 ) ;
return 0 ;
}
V_5 -> V_28 = V_28 ;
V_5 -> V_73 = V_28 -> V_25 ;
F_35 ( & V_5 -> V_35 , F_18 ) ;
F_36 ( V_74 , & V_5 -> V_35 ) ;
return 0 ;
}
static int F_37 ( struct V_40 * V_41 ,
struct V_36 * V_37 ,
int V_66 , int V_75 , enum V_76 V_77 )
{
struct V_1 * V_1 = NULL ;
struct V_78 * V_63 ;
struct V_79 * V_80 ;
struct V_4 * V_5 = NULL ;
struct V_81 * V_82 = NULL ;
int V_83 = V_84 , V_45 ;
V_5 = F_33 ( V_7 , V_85 ) ;
if ( ! V_5 ) {
F_34 ( L_7 ) ;
return V_83 ;
}
V_82 = F_38 ( sizeof( struct V_81 ) , V_85 ) ;
if ( ! V_82 ) {
F_34 ( L_8 ) ;
goto V_86;
}
F_39 ( & V_82 -> V_87 ) ;
V_1 = & V_5 -> V_6 ;
V_80 = & V_41 -> V_88 ;
V_63 = V_37 -> V_63 ;
F_40 ( V_1 , V_80 -> V_89 , V_63 , 0 ,
V_90 , V_33 ,
& V_5 -> V_65 [ 0 ] ) ;
V_45 = F_41 ( V_1 , V_82 , V_77 , V_85 ) ;
if ( V_45 < 0 )
goto V_86;
if ( V_77 == V_91 )
V_1 -> V_92 -> V_93 = V_75 ;
if ( F_42 ( V_1 , V_66 ) < 0 ) {
V_83 = V_94 ;
goto V_86;
}
F_43 ( V_1 ) ;
F_44 ( V_82 -> V_87 , F_45 ( & V_82 -> V_95 ) ) ;
V_83 = V_1 -> V_92 -> V_96 ;
V_86:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_46 ( V_82 ) ;
return V_83 ;
}
static int F_47 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_83 = V_97 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_34 ( L_9
L_10 ) ;
return V_97 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
V_83 = F_37 ( V_41 , V_37 , V_28 -> V_12 -> V_66 ,
V_28 -> V_25 , V_91 ) ;
return ( V_83 == V_98 ) ? V_99 : V_97 ;
}
static int F_48 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_83 = V_97 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_34 ( L_9
L_10 ) ;
return V_97 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
V_83 = F_37 ( V_41 , V_37 , V_28 -> V_12 -> V_66 ,
0 , V_100 ) ;
return ( V_83 == V_98 ) ? V_99 : V_97 ;
}
static int F_49 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
if ( ! V_39 ) {
F_34 ( L_9
L_10 ) ;
return V_97 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
if ( V_41 ) {
V_41 -> V_50 = V_101 ;
return V_99 ;
}
return V_97 ;
}
static int F_50 ( struct V_16 * V_102 )
{
F_51 ( V_103 , & V_102 -> V_104 -> V_105 ) ;
return 0 ;
}
static int F_52 ( struct V_16 * V_102 )
{
if ( V_102 -> V_26 ) {
F_15 ( V_102 , V_102 -> V_24 ) ;
F_10 ( V_102 , V_33 ,
V_102 -> V_11 -> V_106 ) ;
} else {
F_10 ( V_102 , 0 ,
V_102 -> V_11 -> V_106 ) ;
}
return 0 ;
}
static int F_53 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_69 ;
int error , V_107 ;
V_39 = F_54 ( V_13 ) ;
V_69 = F_55 ( & V_108 ,
sizeof( struct V_38 ) ) ;
if ( ! V_69 ) {
F_34 ( L_11 ) ;
return - V_109 ;
}
V_39 -> V_69 = V_69 ;
* ( (struct V_38 * * ) V_69 -> V_110 ) = V_39 ;
V_69 -> V_111 = 2 ;
V_69 -> V_112 = 0 ;
V_69 -> V_113 = 0 ;
V_69 -> V_114 = V_115 ;
V_107 = V_116 | V_117 |
V_118 | V_119 |
V_120 | V_121 ;
F_56 ( V_69 , V_107 ) ;
F_57 ( V_69 , V_122 ) ;
error = F_58 ( V_69 , & V_39 -> V_13 ) ;
if ( error ) {
F_34 ( L_12 , V_123 ) ;
F_59 ( V_69 ) ;
return - V_109 ;
}
return 0 ;
}
static int F_60 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_69 ;
V_39 = F_54 ( V_13 ) ;
V_69 = V_39 -> V_69 ;
F_61 ( V_69 ) ;
F_59 ( V_69 ) ;
return 0 ;
}
static void F_62 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = F_54 ( V_13 ) ;
F_46 ( V_39 ) ;
}
static int F_63 ( struct V_38 * V_39 , int V_124 )
{
int V_83 ;
V_39 -> V_13 . V_125 = & V_126 ;
V_39 -> V_13 . V_127 = V_128 ;
V_39 -> V_13 . V_86 = & F_62 ;
F_64 ( & V_39 -> V_13 , L_13 , V_124 ) ;
V_83 = F_65 ( & V_39 -> V_13 ) ;
if ( V_83 ) {
F_34 ( L_14
L_15 , V_83 ) ;
return - V_109 ;
}
return 0 ;
}
static int F_66 ( void )
{
int V_83 ;
V_128 = F_67 ( L_16 ) ;
if ( F_68 ( V_128 ) ) {
F_34 ( L_17 ) ;
return F_69 ( V_128 ) ;
}
V_83 = F_70 ( & V_126 ) ;
if ( V_83 ) {
F_34 ( L_18 ) ;
goto V_129;
}
V_83 = F_71 ( & V_130 ) ;
if ( V_83 ) {
F_34 ( L_19
L_20 ) ;
goto V_131;
}
F_32 ( L_21 ) ;
return V_83 ;
V_131:
F_72 ( & V_126 ) ;
V_129:
F_73 ( V_128 ) ;
return V_83 ;
}
static void F_74 ( void )
{
F_75 ( & V_130 ) ;
F_72 ( & V_126 ) ;
F_73 ( V_128 ) ;
F_32 ( L_22 ) ;
}
static char * F_76 ( void )
{
return L_23 ;
}
static T_2 F_77 ( struct V_79 * V_80 )
{
struct V_40 * V_41 = V_80 -> V_132 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_133 ) {
case V_134 :
return F_78 ( V_80 ) ;
case V_135 :
return F_79 ( V_80 ) ;
case V_136 :
return F_80 ( V_80 ) ;
default:
F_34 ( L_24
L_25 , V_39 -> V_133 ) ;
break;
}
return F_78 ( V_80 ) ;
}
static char * F_81 ( struct V_79 * V_80 )
{
struct V_40 * V_41 = V_80 -> V_132 ;
return & V_41 -> V_39 -> V_137 [ 0 ] ;
}
static T_3 F_82 ( struct V_79 * V_80 )
{
struct V_40 * V_41 = V_80 -> V_132 ;
return V_41 -> V_138 ;
}
static T_1 F_83 ( struct V_79 * V_80 )
{
return 1 ;
}
static T_1 F_84 (
struct V_79 * V_80 ,
struct V_139 * V_140 ,
struct V_141 * V_142 ,
int * V_143 ,
unsigned char * V_144 )
{
struct V_40 * V_41 = V_80 -> V_132 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_133 ) {
case V_134 :
return F_85 ( V_80 , V_140 , V_142 ,
V_143 , V_144 ) ;
case V_135 :
return F_86 ( V_80 , V_140 , V_142 ,
V_143 , V_144 ) ;
case V_136 :
return F_87 ( V_80 , V_140 , V_142 ,
V_143 , V_144 ) ;
default:
F_34 ( L_24
L_25 , V_39 -> V_133 ) ;
break;
}
return F_85 ( V_80 , V_140 , V_142 ,
V_143 , V_144 ) ;
}
static T_1 F_88 (
struct V_79 * V_80 ,
struct V_139 * V_140 ,
struct V_141 * V_142 ,
int * V_143 )
{
struct V_40 * V_41 = V_80 -> V_132 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_133 ) {
case V_134 :
return F_89 ( V_80 , V_140 , V_142 ,
V_143 ) ;
case V_135 :
return F_90 ( V_80 , V_140 , V_142 ,
V_143 ) ;
case V_136 :
return F_91 ( V_80 , V_140 , V_142 ,
V_143 ) ;
default:
F_34 ( L_24
L_25 , V_39 -> V_133 ) ;
break;
}
return F_89 ( V_80 , V_140 , V_142 ,
V_143 ) ;
}
static char * F_92 (
struct V_79 * V_80 ,
const char * V_144 ,
T_1 * V_145 ,
char * * V_146 )
{
struct V_40 * V_41 = V_80 -> V_132 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_133 ) {
case V_134 :
return F_93 ( V_80 , V_144 , V_145 ,
V_146 ) ;
case V_135 :
return F_94 ( V_80 , V_144 , V_145 ,
V_146 ) ;
case V_136 :
return F_95 ( V_80 , V_144 , V_145 ,
V_146 ) ;
default:
F_34 ( L_24
L_25 , V_39 -> V_133 ) ;
break;
}
return F_93 ( V_80 , V_144 , V_145 ,
V_146 ) ;
}
static int F_96 ( struct V_79 * V_80 )
{
return 1 ;
}
static int F_97 ( struct V_79 * V_80 )
{
return 0 ;
}
static int F_98 ( struct V_79 * V_80 )
{
return 0 ;
}
static int F_99 ( struct V_79 * V_80 )
{
return 0 ;
}
static struct V_139 * F_100 (
struct V_79 * V_80 )
{
struct V_147 * V_148 ;
V_148 = F_38 ( sizeof( struct V_147 ) , V_85 ) ;
if ( ! V_148 ) {
F_34 ( L_26 ) ;
return NULL ;
}
return & V_148 -> V_139 ;
}
static void F_101 (
struct V_79 * V_80 ,
struct V_139 * V_140 )
{
struct V_147 * V_148 = F_4 ( V_140 ,
struct V_147 , V_139 ) ;
F_46 ( V_148 ) ;
}
static T_1 F_102 ( struct V_79 * V_80 )
{
return 1 ;
}
static T_1 F_103 ( struct V_78 * V_63 )
{
return 1 ;
}
static void F_104 ( struct V_139 * V_149 )
{
return;
}
static T_1 F_105 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_73 ;
}
static int F_106 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_150 ;
}
static int F_107 ( struct V_78 * V_63 )
{
return 0 ;
}
static void F_108 ( struct V_78 * V_63 )
{
return;
}
static int F_109 ( struct V_1 * V_1 )
{
F_110 ( V_1 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_112 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_32 ( L_27
L_28 , V_28 , V_28 -> V_64 [ 0 ] ) ;
V_28 -> V_151 = V_152 ;
F_20 ( V_28 , V_153 ) ;
if ( ( V_1 -> V_2 & V_154 ) ||
( V_1 -> V_2 & V_155 ) )
F_113 ( V_28 , V_1 -> V_156 ) ;
V_28 -> V_68 ( V_28 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_32 ( L_29
L_28 , V_28 , V_28 -> V_64 [ 0 ] ) ;
if ( V_1 -> V_157 &&
( ( V_1 -> V_2 & V_158 ) ||
( V_1 -> V_2 & V_159 ) ) ) {
memcpy ( V_28 -> V_157 , V_1 -> V_157 ,
V_160 ) ;
V_28 -> V_151 = V_161 ;
F_115 ( V_28 , V_162 ) ;
} else
V_28 -> V_151 = V_1 -> V_163 ;
F_20 ( V_28 , V_153 ) ;
if ( ( V_1 -> V_2 & V_154 ) ||
( V_1 -> V_2 & V_155 ) )
F_113 ( V_28 , V_1 -> V_156 ) ;
V_28 -> V_68 ( V_28 ) ;
return 0 ;
}
static void F_116 ( struct V_1 * V_1 )
{
struct V_92 * V_164 = V_1 -> V_92 ;
struct V_81 * V_82 = V_164 -> V_165 ;
F_117 ( & V_82 -> V_95 , 1 ) ;
F_118 ( & V_82 -> V_87 ) ;
}
static void F_119 ( struct V_1 * V_1 )
{
return;
}
static char * F_120 ( struct V_38 * V_39 )
{
switch ( V_39 -> V_133 ) {
case V_134 :
return L_30 ;
case V_135 :
return L_31 ;
case V_136 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_121 (
struct V_79 * V_80 ,
struct V_166 * V_66 )
{
struct V_40 * V_41 = F_4 ( V_80 ,
struct V_40 , V_88 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
F_122 ( & V_41 -> V_167 ) ;
F_123 () ;
F_124 ( V_39 -> V_69 , 0 , V_41 -> V_138 , V_66 -> V_168 ) ;
F_32 ( L_34 ) ;
return 0 ;
}
static void F_125 (
struct V_79 * V_80 ,
struct V_166 * V_166 )
{
struct V_16 * V_102 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = F_4 ( V_80 , struct V_40 , V_88 ) ;
V_39 = V_41 -> V_39 ;
V_102 = F_126 ( V_39 -> V_69 , 0 , V_41 -> V_138 ,
V_166 -> V_168 ) ;
if ( ! V_102 ) {
F_34 ( L_35
L_36 , 0 , V_41 -> V_138 , V_166 -> V_168 ) ;
return;
}
F_127 ( V_102 ) ;
F_128 ( V_102 ) ;
F_129 ( & V_41 -> V_167 ) ;
F_130 () ;
F_32 ( L_37 ) ;
}
static int F_131 (
struct V_40 * V_41 ,
const char * V_169 )
{
struct V_79 * V_80 ;
struct V_38 * V_39 = V_41 -> V_39 ;
struct V_36 * V_37 ;
int V_83 = - V_170 ;
if ( V_41 -> V_39 -> V_37 ) {
F_32 ( L_38 ) ;
return - V_171 ;
}
V_80 = & V_41 -> V_88 ;
V_37 = F_38 ( sizeof( struct V_36 ) , V_85 ) ;
if ( ! V_37 ) {
F_34 ( L_39 ) ;
return - V_170 ;
}
V_37 -> V_63 = F_132 ( V_172 ) ;
if ( F_68 ( V_37 -> V_63 ) ) {
V_83 = F_69 ( V_37 -> V_63 ) ;
goto V_173;
}
V_37 -> V_63 -> V_139 = F_133 (
V_80 , ( unsigned char * ) V_169 ) ;
if ( ! V_37 -> V_63 -> V_139 ) {
F_134 ( V_37 -> V_63 ) ;
goto V_173;
}
F_135 ( V_80 , V_37 -> V_63 -> V_139 ,
V_37 -> V_63 , V_37 ) ;
V_41 -> V_39 -> V_37 = V_37 ;
F_32 ( L_40
L_41 , F_120 ( V_39 ) ,
V_169 ) ;
return 0 ;
V_173:
F_46 ( V_37 ) ;
return V_83 ;
}
static int F_136 (
struct V_40 * V_174 )
{
struct V_78 * V_63 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_174 -> V_39 ;
if ( ! V_39 )
return - V_109 ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 )
return - V_109 ;
V_63 = V_37 -> V_63 ;
if ( ! V_63 )
return - V_109 ;
if ( F_45 ( & V_174 -> V_167 ) ) {
F_34 ( L_42
L_43 ,
F_45 ( & V_174 -> V_167 ) ) ;
return - V_175 ;
}
F_32 ( L_44
L_41 , F_120 ( V_39 ) ,
V_37 -> V_63 -> V_139 -> V_176 ) ;
F_137 ( V_37 -> V_63 ) ;
V_174 -> V_39 -> V_37 = NULL ;
F_46 ( V_37 ) ;
return 0 ;
}
static T_4 F_138 (
struct V_79 * V_80 ,
char * V_177 )
{
struct V_40 * V_41 = F_4 ( V_80 ,
struct V_40 , V_88 ) ;
struct V_36 * V_37 ;
T_4 V_83 ;
V_37 = V_41 -> V_39 -> V_37 ;
if ( ! V_37 )
return - V_109 ;
V_83 = snprintf ( V_177 , V_178 , L_45 ,
V_37 -> V_63 -> V_139 -> V_176 ) ;
return V_83 ;
}
static T_4 F_139 (
struct V_79 * V_80 ,
const char * V_177 ,
T_5 V_179 )
{
struct V_40 * V_41 = F_4 ( V_80 ,
struct V_40 , V_88 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
unsigned char V_180 [ V_181 ] , * V_182 , * V_183 ;
int V_83 ;
if ( ! strncmp ( V_177 , L_46 , 4 ) ) {
V_83 = F_136 ( V_41 ) ;
return ( ! V_83 ) ? V_179 : V_83 ;
}
if ( strlen ( V_177 ) >= V_181 ) {
F_34 ( L_47
L_48 , V_177 , V_181 ) ;
return - V_184 ;
}
snprintf ( & V_180 [ 0 ] , V_181 , L_49 , V_177 ) ;
V_182 = strstr ( V_180 , L_50 ) ;
if ( V_182 ) {
if ( V_39 -> V_133 != V_134 ) {
F_34 ( L_51
L_52 , V_180 ,
F_120 ( V_39 ) ) ;
return - V_184 ;
}
V_183 = & V_180 [ 0 ] ;
goto V_185;
}
V_182 = strstr ( V_180 , L_53 ) ;
if ( V_182 ) {
if ( V_39 -> V_133 != V_135 ) {
F_34 ( L_54
L_52 , V_180 ,
F_120 ( V_39 ) ) ;
return - V_184 ;
}
V_183 = & V_180 [ 3 ] ;
goto V_185;
}
V_182 = strstr ( V_180 , L_55 ) ;
if ( V_182 ) {
if ( V_39 -> V_133 != V_136 ) {
F_34 ( L_56
L_52 , V_180 ,
F_120 ( V_39 ) ) ;
return - V_184 ;
}
V_183 = & V_180 [ 0 ] ;
goto V_185;
}
F_34 ( L_57
L_58 , V_180 ) ;
return - V_184 ;
V_185:
if ( V_180 [ strlen ( V_180 ) - 1 ] == '\n' )
V_180 [ strlen ( V_180 ) - 1 ] = '\0' ;
V_83 = F_131 ( V_41 , V_183 ) ;
if ( V_83 < 0 )
return V_83 ;
return V_179 ;
}
static T_4 F_140 (
struct V_79 * V_80 ,
char * V_177 )
{
struct V_40 * V_41 = F_4 ( V_80 ,
struct V_40 , V_88 ) ;
const char * V_186 = NULL ;
T_4 V_83 = - V_184 ;
switch ( V_41 -> V_50 ) {
case V_101 :
V_186 = L_59 ;
break;
case V_51 :
V_186 = L_60 ;
break;
default:
break;
}
if ( V_186 )
V_83 = snprintf ( V_177 , V_178 , L_45 , V_186 ) ;
return V_83 ;
}
static T_4 F_141 (
struct V_79 * V_80 ,
const char * V_177 ,
T_5 V_179 )
{
struct V_40 * V_41 = F_4 ( V_80 ,
struct V_40 , V_88 ) ;
if ( ! strncmp ( V_177 , L_59 , 6 ) ) {
V_41 -> V_50 = V_101 ;
return V_179 ;
}
if ( ! strncmp ( V_177 , L_60 , 7 ) ) {
V_41 -> V_50 = V_51 ;
return V_179 ;
}
return - V_184 ;
}
static struct V_79 * F_142 (
struct V_187 * V_188 ,
struct V_189 * V_190 ,
const char * V_169 )
{
struct V_38 * V_39 = F_4 ( V_188 ,
struct V_38 , V_191 ) ;
struct V_40 * V_41 ;
char * V_192 , * V_193 ;
int V_83 ;
unsigned short int V_194 ;
V_192 = strstr ( V_169 , L_61 ) ;
if ( ! V_192 ) {
F_34 ( L_62
L_63 ) ;
return F_143 ( - V_184 ) ;
}
V_192 += 5 ;
V_194 = ( unsigned short int ) F_144 ( V_192 , & V_193 , 0 ) ;
if ( V_194 >= V_195 ) {
F_34 ( L_64
L_65 , V_194 , V_195 ) ;
return F_143 ( - V_184 ) ;
}
V_41 = & V_39 -> V_46 [ V_194 ] ;
V_41 -> V_39 = V_39 ;
V_41 -> V_138 = V_194 ;
V_83 = F_145 ( & V_196 -> V_197 ,
V_188 , & V_41 -> V_88 , V_41 ,
V_198 ) ;
if ( V_83 < 0 )
return F_143 ( - V_170 ) ;
F_32 ( L_66
L_67 , F_120 ( V_39 ) ,
F_146 ( & V_188 -> V_199 . V_200 ) , V_194 ) ;
return & V_41 -> V_88 ;
}
static void F_147 (
struct V_79 * V_80 )
{
struct V_187 * V_188 = V_80 -> V_201 ;
struct V_40 * V_41 = F_4 ( V_80 ,
struct V_40 , V_88 ) ;
struct V_38 * V_39 ;
unsigned short V_194 ;
V_39 = V_41 -> V_39 ;
V_194 = V_41 -> V_138 ;
F_136 ( V_41 ) ;
F_148 ( V_80 ) ;
V_41 -> V_39 = NULL ;
V_41 -> V_138 = 0 ;
F_32 ( L_68
L_67 , F_120 ( V_39 ) ,
F_146 ( & V_188 -> V_199 . V_200 ) , V_194 ) ;
}
static struct V_187 * F_149 (
struct V_202 * V_203 ,
struct V_189 * V_190 ,
const char * V_169 )
{
struct V_38 * V_39 ;
struct V_10 * V_69 ;
char * V_182 ;
int V_83 , V_204 = 0 ;
V_39 = F_38 ( sizeof( struct V_38 ) , V_85 ) ;
if ( ! V_39 ) {
F_34 ( L_69 ) ;
return F_143 ( - V_170 ) ;
}
V_182 = strstr ( V_169 , L_50 ) ;
if ( V_182 ) {
V_39 -> V_133 = V_134 ;
goto V_205;
}
V_182 = strstr ( V_169 , L_53 ) ;
if ( V_182 ) {
V_39 -> V_133 = V_135 ;
V_204 = 3 ;
goto V_205;
}
V_182 = strstr ( V_169 , L_55 ) ;
if ( ! V_182 ) {
F_34 ( L_70
L_71 , V_169 ) ;
V_83 = - V_184 ;
goto V_173;
}
V_39 -> V_133 = V_136 ;
V_205:
if ( strlen ( V_169 ) >= V_181 ) {
F_34 ( L_72
L_48 , V_169 , F_120 ( V_39 ) ,
V_181 ) ;
V_83 = - V_184 ;
goto V_173;
}
snprintf ( & V_39 -> V_137 [ 0 ] , V_181 , L_49 , & V_169 [ V_204 ] ) ;
V_83 = F_63 ( V_39 , V_206 ) ;
if ( V_83 )
goto V_173;
V_69 = V_39 -> V_69 ;
V_206 ++ ;
F_32 ( L_73
L_74 ,
F_120 ( V_39 ) , V_169 , V_69 -> V_70 ) ;
return & V_39 -> V_191 ;
V_173:
F_46 ( V_39 ) ;
return F_143 ( V_83 ) ;
}
static void F_150 (
struct V_187 * V_188 )
{
struct V_38 * V_39 = F_4 ( V_188 ,
struct V_38 , V_191 ) ;
F_32 ( L_75
L_76 ,
V_39 -> V_137 , V_39 -> V_69 -> V_70 ) ;
F_151 ( & V_39 -> V_13 ) ;
}
static T_4 F_152 (
struct V_202 * V_203 ,
char * V_177 )
{
return sprintf ( V_177 , L_77 , V_207 ) ;
}
static int F_153 ( void )
{
struct V_202 * V_208 ;
int V_83 ;
V_206 = 0 ;
V_208 = F_154 ( V_209 , L_23 ) ;
if ( F_68 ( V_208 ) ) {
F_34 ( L_78 ) ;
return F_69 ( V_208 ) ;
}
V_208 -> V_197 . V_210 = & F_76 ;
V_208 -> V_197 . V_211 = & F_77 ;
V_208 -> V_197 . V_212 = & F_81 ;
V_208 -> V_197 . V_213 = & F_82 ;
V_208 -> V_197 . V_214 = & F_83 ;
V_208 -> V_197 . V_215 = & F_84 ;
V_208 -> V_197 . V_216 =
& F_88 ;
V_208 -> V_197 . V_217 =
& F_92 ;
V_208 -> V_197 . V_218 = & F_96 ;
V_208 -> V_197 . V_219 =
& F_97 ;
V_208 -> V_197 . V_220 =
& F_98 ;
V_208 -> V_197 . V_221 =
& F_99 ;
V_208 -> V_197 . V_222 = & F_100 ;
V_208 -> V_197 . V_223 =
& F_101 ;
V_208 -> V_197 . V_224 = & F_102 ;
V_208 -> V_197 . V_225 = & F_1 ;
V_208 -> V_197 . V_226 = & F_3 ;
V_208 -> V_197 . V_227 = & F_107 ;
V_208 -> V_197 . V_228 = & F_108 ;
V_208 -> V_197 . V_229 = & F_103 ;
V_208 -> V_197 . V_230 = NULL ;
V_208 -> V_197 . V_231 = & F_109 ;
V_208 -> V_197 . V_232 = & F_111 ;
V_208 -> V_197 . V_233 =
& F_104 ;
V_208 -> V_197 . V_234 = & F_105 ;
V_208 -> V_197 . V_235 = & F_106 ;
V_208 -> V_197 . V_236 = & F_112 ;
V_208 -> V_197 . V_237 = & F_114 ;
V_208 -> V_197 . V_238 = & F_116 ;
V_208 -> V_197 . V_239 = & F_119 ;
V_208 -> V_197 . V_240 = & F_149 ;
V_208 -> V_197 . V_241 = & F_150 ;
V_208 -> V_197 . V_242 = & F_142 ;
V_208 -> V_197 . V_243 = & F_147 ;
V_208 -> V_197 . V_244 = & F_121 ;
V_208 -> V_197 . V_245 = & F_125 ;
V_208 -> V_197 . V_246 = NULL ;
V_208 -> V_197 . V_247 = NULL ;
V_208 -> V_248 . V_249 . V_250 = V_251 ;
V_208 -> V_248 . V_252 . V_250 = V_253 ;
V_208 -> V_248 . V_254 . V_250 = NULL ;
V_208 -> V_248 . V_255 . V_250 = NULL ;
V_208 -> V_248 . V_256 . V_250 = NULL ;
V_83 = F_155 ( V_208 ) ;
if ( V_83 < 0 ) {
F_34 ( L_79
L_80 ) ;
F_156 ( V_208 ) ;
return - 1 ;
}
V_196 = V_208 ;
F_32 ( L_81
L_82 ) ;
return 0 ;
}
static void F_157 ( void )
{
if ( ! V_196 )
return;
F_158 ( V_196 ) ;
V_196 = NULL ;
F_32 ( L_83
L_82 ) ;
}
static int T_6 F_159 ( void )
{
int V_83 = - V_170 ;
V_74 = F_160 ( L_84 , 0 , 0 ) ;
if ( ! V_74 )
goto V_173;
V_7 = F_161 ( L_85 ,
sizeof( struct V_4 ) ,
F_162 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_32 ( L_86
L_87 ) ;
goto V_257;
}
V_83 = F_66 () ;
if ( V_83 )
goto V_258;
V_83 = F_153 () ;
if ( V_83 )
goto V_259;
return 0 ;
V_259:
F_74 () ;
V_258:
F_163 ( V_7 ) ;
V_257:
F_164 ( V_74 ) ;
V_173:
return V_83 ;
}
static void T_7 F_165 ( void )
{
F_157 () ;
F_74 () ;
F_163 ( V_7 ) ;
F_164 ( V_74 ) ;
}
