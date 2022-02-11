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
V_45 = F_24 ( V_1 , V_37 -> V_61 , V_28 -> V_62 ,
& V_5 -> V_63 [ 0 ] , V_5 -> V_28 -> V_12 -> V_64 ,
F_25 ( V_28 ) , F_17 ( V_28 ) ,
V_28 -> V_65 , 0 ,
F_26 ( V_28 ) , F_27 ( V_28 ) ,
V_43 , V_44 ,
F_28 ( V_28 ) , F_29 ( V_28 ) ) ;
if ( V_45 < 0 ) {
F_20 ( V_28 , V_48 ) ;
goto V_49;
}
return;
V_49:
V_28 -> V_66 ( V_28 ) ;
return;
}
static int F_30 ( struct V_10 * V_67 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
F_31 ( L_4
L_5 , V_28 -> V_12 -> V_11 -> V_68 ,
V_28 -> V_12 -> V_47 , V_28 -> V_12 -> V_69 , V_28 -> V_12 -> V_64 ,
V_28 -> V_62 [ 0 ] , F_25 ( V_28 ) ) ;
V_5 = F_32 ( V_7 , V_70 ) ;
if ( ! V_5 ) {
F_33 ( L_6 ) ;
F_20 ( V_28 , V_54 ) ;
V_28 -> V_66 ( V_28 ) ;
return 0 ;
}
V_5 -> V_28 = V_28 ;
V_5 -> V_71 = V_28 -> V_25 ;
F_34 ( & V_5 -> V_35 , F_18 ) ;
F_35 ( V_72 , & V_5 -> V_35 ) ;
return 0 ;
}
static int F_36 ( struct V_40 * V_41 ,
struct V_36 * V_37 ,
int V_64 , int V_73 , enum V_74 V_75 )
{
struct V_1 * V_1 = NULL ;
struct V_76 * V_61 ;
struct V_77 * V_78 ;
struct V_4 * V_5 = NULL ;
struct V_79 * V_80 = NULL ;
int V_81 = V_82 , V_45 ;
V_5 = F_32 ( V_7 , V_83 ) ;
if ( ! V_5 ) {
F_33 ( L_7 ) ;
return V_81 ;
}
V_80 = F_37 ( sizeof( struct V_79 ) , V_83 ) ;
if ( ! V_80 ) {
F_33 ( L_8 ) ;
goto V_84;
}
F_38 ( & V_80 -> V_85 ) ;
V_1 = & V_5 -> V_6 ;
V_78 = & V_41 -> V_86 ;
V_61 = V_37 -> V_61 ;
F_39 ( V_1 , V_78 -> V_87 , V_61 , 0 ,
V_88 , V_33 ,
& V_5 -> V_63 [ 0 ] ) ;
V_45 = F_40 ( V_1 , V_80 , V_75 , V_83 ) ;
if ( V_45 < 0 )
goto V_84;
if ( V_75 == V_89 )
V_1 -> V_90 -> V_91 = V_73 ;
if ( F_41 ( V_1 , V_64 ) < 0 ) {
V_81 = V_92 ;
goto V_84;
}
F_42 ( V_1 ) ;
F_43 ( V_80 -> V_85 , F_44 ( & V_80 -> V_93 ) ) ;
V_81 = V_1 -> V_90 -> V_94 ;
V_84:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_45 ( V_80 ) ;
return V_81 ;
}
static int F_46 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_81 = V_95 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_33 ( L_9
L_10 ) ;
return V_95 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
V_81 = F_36 ( V_41 , V_37 , V_28 -> V_12 -> V_64 ,
V_28 -> V_25 , V_89 ) ;
return ( V_81 == V_96 ) ? V_97 : V_95 ;
}
static int F_47 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_81 = V_95 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_33 ( L_9
L_10 ) ;
return V_95 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
V_81 = F_36 ( V_41 , V_37 , V_28 -> V_12 -> V_64 ,
0 , V_98 ) ;
return ( V_81 == V_96 ) ? V_97 : V_95 ;
}
static int F_48 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
if ( ! V_39 ) {
F_33 ( L_9
L_10 ) ;
return V_95 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
if ( V_41 ) {
V_41 -> V_50 = V_99 ;
return V_97 ;
}
return V_95 ;
}
static int F_49 ( struct V_16 * V_100 )
{
F_50 ( V_101 , & V_100 -> V_102 -> V_103 ) ;
return 0 ;
}
static int F_51 ( struct V_16 * V_100 )
{
if ( V_100 -> V_26 ) {
F_15 ( V_100 , V_100 -> V_24 ) ;
F_10 ( V_100 , V_33 ,
V_100 -> V_11 -> V_104 ) ;
} else {
F_10 ( V_100 , 0 ,
V_100 -> V_11 -> V_104 ) ;
}
return 0 ;
}
static int F_52 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_67 ;
int error , V_105 ;
V_39 = F_53 ( V_13 ) ;
V_67 = F_54 ( & V_106 ,
sizeof( struct V_38 ) ) ;
if ( ! V_67 ) {
F_33 ( L_11 ) ;
return - V_107 ;
}
V_39 -> V_67 = V_67 ;
* ( (struct V_38 * * ) V_67 -> V_108 ) = V_39 ;
V_67 -> V_109 = 2 ;
V_67 -> V_110 = 0 ;
V_67 -> V_111 = 0 ;
V_67 -> V_112 = V_113 ;
V_105 = V_114 | V_115 |
V_116 | V_117 |
V_118 | V_119 ;
F_55 ( V_67 , V_105 ) ;
F_56 ( V_67 , V_120 ) ;
error = F_57 ( V_67 , & V_39 -> V_13 ) ;
if ( error ) {
F_33 ( L_12 , V_121 ) ;
F_58 ( V_67 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_59 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_67 ;
V_39 = F_53 ( V_13 ) ;
V_67 = V_39 -> V_67 ;
F_60 ( V_67 ) ;
F_58 ( V_67 ) ;
return 0 ;
}
static void F_61 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = F_53 ( V_13 ) ;
F_45 ( V_39 ) ;
}
static int F_62 ( struct V_38 * V_39 , int V_122 )
{
int V_81 ;
V_39 -> V_13 . V_123 = & V_124 ;
V_39 -> V_13 . V_125 = V_126 ;
V_39 -> V_13 . V_84 = & F_61 ;
F_63 ( & V_39 -> V_13 , L_13 , V_122 ) ;
V_81 = F_64 ( & V_39 -> V_13 ) ;
if ( V_81 ) {
F_33 ( L_14
L_15 , V_81 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_65 ( void )
{
int V_81 ;
V_126 = F_66 ( L_16 ) ;
if ( F_67 ( V_126 ) ) {
F_33 ( L_17 ) ;
return F_68 ( V_126 ) ;
}
V_81 = F_69 ( & V_124 ) ;
if ( V_81 ) {
F_33 ( L_18 ) ;
goto V_127;
}
V_81 = F_70 ( & V_128 ) ;
if ( V_81 ) {
F_33 ( L_19
L_20 ) ;
goto V_129;
}
F_31 ( L_21 ) ;
return V_81 ;
V_129:
F_71 ( & V_124 ) ;
V_127:
F_72 ( V_126 ) ;
return V_81 ;
}
static void F_73 ( void )
{
F_74 ( & V_128 ) ;
F_71 ( & V_124 ) ;
F_72 ( V_126 ) ;
F_31 ( L_22 ) ;
}
static char * F_75 ( void )
{
return L_23 ;
}
static T_2 F_76 ( struct V_77 * V_78 )
{
struct V_40 * V_41 = V_78 -> V_130 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_131 ) {
case V_132 :
return F_77 ( V_78 ) ;
case V_133 :
return F_78 ( V_78 ) ;
case V_134 :
return F_79 ( V_78 ) ;
default:
F_33 ( L_24
L_25 , V_39 -> V_131 ) ;
break;
}
return F_77 ( V_78 ) ;
}
static char * F_80 ( struct V_77 * V_78 )
{
struct V_40 * V_41 = V_78 -> V_130 ;
return & V_41 -> V_39 -> V_135 [ 0 ] ;
}
static T_3 F_81 ( struct V_77 * V_78 )
{
struct V_40 * V_41 = V_78 -> V_130 ;
return V_41 -> V_136 ;
}
static T_1 F_82 ( struct V_77 * V_78 )
{
return 1 ;
}
static T_1 F_83 (
struct V_77 * V_78 ,
struct V_137 * V_138 ,
struct V_139 * V_140 ,
int * V_141 ,
unsigned char * V_142 )
{
struct V_40 * V_41 = V_78 -> V_130 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_131 ) {
case V_132 :
return F_84 ( V_78 , V_138 , V_140 ,
V_141 , V_142 ) ;
case V_133 :
return F_85 ( V_78 , V_138 , V_140 ,
V_141 , V_142 ) ;
case V_134 :
return F_86 ( V_78 , V_138 , V_140 ,
V_141 , V_142 ) ;
default:
F_33 ( L_24
L_25 , V_39 -> V_131 ) ;
break;
}
return F_84 ( V_78 , V_138 , V_140 ,
V_141 , V_142 ) ;
}
static T_1 F_87 (
struct V_77 * V_78 ,
struct V_137 * V_138 ,
struct V_139 * V_140 ,
int * V_141 )
{
struct V_40 * V_41 = V_78 -> V_130 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_131 ) {
case V_132 :
return F_88 ( V_78 , V_138 , V_140 ,
V_141 ) ;
case V_133 :
return F_89 ( V_78 , V_138 , V_140 ,
V_141 ) ;
case V_134 :
return F_90 ( V_78 , V_138 , V_140 ,
V_141 ) ;
default:
F_33 ( L_24
L_25 , V_39 -> V_131 ) ;
break;
}
return F_88 ( V_78 , V_138 , V_140 ,
V_141 ) ;
}
static char * F_91 (
struct V_77 * V_78 ,
const char * V_142 ,
T_1 * V_143 ,
char * * V_144 )
{
struct V_40 * V_41 = V_78 -> V_130 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_131 ) {
case V_132 :
return F_92 ( V_78 , V_142 , V_143 ,
V_144 ) ;
case V_133 :
return F_93 ( V_78 , V_142 , V_143 ,
V_144 ) ;
case V_134 :
return F_94 ( V_78 , V_142 , V_143 ,
V_144 ) ;
default:
F_33 ( L_24
L_25 , V_39 -> V_131 ) ;
break;
}
return F_92 ( V_78 , V_142 , V_143 ,
V_144 ) ;
}
static int F_95 ( struct V_77 * V_78 )
{
return 1 ;
}
static int F_96 ( struct V_77 * V_78 )
{
return 0 ;
}
static int F_97 ( struct V_77 * V_78 )
{
return 0 ;
}
static int F_98 ( struct V_77 * V_78 )
{
return 0 ;
}
static struct V_137 * F_99 (
struct V_77 * V_78 )
{
struct V_145 * V_146 ;
V_146 = F_37 ( sizeof( struct V_145 ) , V_83 ) ;
if ( ! V_146 ) {
F_33 ( L_26 ) ;
return NULL ;
}
return & V_146 -> V_137 ;
}
static void F_100 (
struct V_77 * V_78 ,
struct V_137 * V_138 )
{
struct V_145 * V_146 = F_4 ( V_138 ,
struct V_145 , V_137 ) ;
F_45 ( V_146 ) ;
}
static T_1 F_101 ( struct V_77 * V_78 )
{
return 1 ;
}
static T_1 F_102 ( struct V_76 * V_61 )
{
return 1 ;
}
static void F_103 ( struct V_137 * V_147 )
{
return;
}
static T_1 F_104 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_71 ;
}
static int F_105 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_148 ;
}
static int F_106 ( struct V_76 * V_61 )
{
return 0 ;
}
static void F_107 ( struct V_76 * V_61 )
{
return;
}
static int F_108 ( struct V_1 * V_1 )
{
F_109 ( V_1 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_111 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_31 ( L_27
L_28 , V_28 , V_28 -> V_62 [ 0 ] ) ;
V_28 -> V_149 = V_150 ;
F_20 ( V_28 , V_151 ) ;
if ( ( V_1 -> V_2 & V_152 ) ||
( V_1 -> V_2 & V_153 ) )
F_112 ( V_28 , V_1 -> V_154 ) ;
V_28 -> V_66 ( V_28 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_31 ( L_29
L_28 , V_28 , V_28 -> V_62 [ 0 ] ) ;
if ( V_1 -> V_155 &&
( ( V_1 -> V_2 & V_156 ) ||
( V_1 -> V_2 & V_157 ) ) ) {
memcpy ( V_28 -> V_155 , V_1 -> V_155 ,
V_158 ) ;
V_28 -> V_149 = V_159 ;
F_114 ( V_28 , V_160 ) ;
} else
V_28 -> V_149 = V_1 -> V_161 ;
F_20 ( V_28 , V_151 ) ;
if ( ( V_1 -> V_2 & V_152 ) ||
( V_1 -> V_2 & V_153 ) )
F_112 ( V_28 , V_1 -> V_154 ) ;
V_28 -> V_66 ( V_28 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_1 )
{
struct V_90 * V_162 = V_1 -> V_90 ;
struct V_79 * V_80 = V_162 -> V_163 ;
F_116 ( & V_80 -> V_93 , 1 ) ;
F_117 ( & V_80 -> V_85 ) ;
}
static char * F_118 ( struct V_38 * V_39 )
{
switch ( V_39 -> V_131 ) {
case V_132 :
return L_30 ;
case V_133 :
return L_31 ;
case V_134 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_119 (
struct V_77 * V_78 ,
struct V_164 * V_64 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
F_120 ( & V_41 -> V_165 ) ;
F_121 () ;
F_122 ( V_39 -> V_67 , 0 , V_41 -> V_136 , V_64 -> V_166 ) ;
F_31 ( L_34 ) ;
return 0 ;
}
static void F_123 (
struct V_77 * V_78 ,
struct V_164 * V_164 )
{
struct V_16 * V_100 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = F_4 ( V_78 , struct V_40 , V_86 ) ;
V_39 = V_41 -> V_39 ;
V_100 = F_124 ( V_39 -> V_67 , 0 , V_41 -> V_136 ,
V_164 -> V_166 ) ;
if ( ! V_100 ) {
F_33 ( L_35
L_36 , 0 , V_41 -> V_136 , V_164 -> V_166 ) ;
return;
}
F_125 ( V_100 ) ;
F_126 ( V_100 ) ;
F_127 ( & V_41 -> V_165 ) ;
F_128 () ;
F_31 ( L_37 ) ;
}
static int F_129 (
struct V_40 * V_41 ,
const char * V_167 )
{
struct V_77 * V_78 ;
struct V_38 * V_39 = V_41 -> V_39 ;
struct V_36 * V_37 ;
int V_81 = - V_168 ;
if ( V_41 -> V_39 -> V_37 ) {
F_31 ( L_38 ) ;
return - V_169 ;
}
V_78 = & V_41 -> V_86 ;
V_37 = F_37 ( sizeof( struct V_36 ) , V_83 ) ;
if ( ! V_37 ) {
F_33 ( L_39 ) ;
return - V_168 ;
}
V_37 -> V_61 = F_130 () ;
if ( F_67 ( V_37 -> V_61 ) ) {
V_81 = F_68 ( V_37 -> V_61 ) ;
goto V_170;
}
V_37 -> V_61 -> V_137 = F_131 (
V_78 , ( unsigned char * ) V_167 ) ;
if ( ! V_37 -> V_61 -> V_137 ) {
F_132 ( V_37 -> V_61 ) ;
goto V_170;
}
F_133 ( V_78 , V_37 -> V_61 -> V_137 ,
V_37 -> V_61 , V_37 ) ;
V_41 -> V_39 -> V_37 = V_37 ;
F_31 ( L_40
L_41 , F_118 ( V_39 ) ,
V_167 ) ;
return 0 ;
V_170:
F_45 ( V_37 ) ;
return V_81 ;
}
static int F_134 (
struct V_40 * V_171 )
{
struct V_76 * V_61 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_171 -> V_39 ;
if ( ! V_39 )
return - V_107 ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 )
return - V_107 ;
V_61 = V_37 -> V_61 ;
if ( ! V_61 )
return - V_107 ;
if ( F_44 ( & V_171 -> V_165 ) ) {
F_33 ( L_42
L_43 ,
F_44 ( & V_171 -> V_165 ) ) ;
return - V_172 ;
}
F_31 ( L_44
L_41 , F_118 ( V_39 ) ,
V_37 -> V_61 -> V_137 -> V_173 ) ;
F_135 ( V_37 -> V_61 ) ;
V_171 -> V_39 -> V_37 = NULL ;
F_45 ( V_37 ) ;
return 0 ;
}
static T_4 F_136 (
struct V_77 * V_78 ,
char * V_174 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_36 * V_37 ;
T_4 V_81 ;
V_37 = V_41 -> V_39 -> V_37 ;
if ( ! V_37 )
return - V_107 ;
V_81 = snprintf ( V_174 , V_175 , L_45 ,
V_37 -> V_61 -> V_137 -> V_173 ) ;
return V_81 ;
}
static T_4 F_137 (
struct V_77 * V_78 ,
const char * V_174 ,
T_5 V_176 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
unsigned char V_177 [ V_178 ] , * V_179 , * V_180 ;
int V_81 ;
if ( ! strncmp ( V_174 , L_46 , 4 ) ) {
V_81 = F_134 ( V_41 ) ;
return ( ! V_81 ) ? V_176 : V_81 ;
}
if ( strlen ( V_174 ) >= V_178 ) {
F_33 ( L_47
L_48 , V_174 , V_178 ) ;
return - V_181 ;
}
snprintf ( & V_177 [ 0 ] , V_178 , L_49 , V_174 ) ;
V_179 = strstr ( V_177 , L_50 ) ;
if ( V_179 ) {
if ( V_39 -> V_131 != V_132 ) {
F_33 ( L_51
L_52 , V_177 ,
F_118 ( V_39 ) ) ;
return - V_181 ;
}
V_180 = & V_177 [ 0 ] ;
goto V_182;
}
V_179 = strstr ( V_177 , L_53 ) ;
if ( V_179 ) {
if ( V_39 -> V_131 != V_133 ) {
F_33 ( L_54
L_52 , V_177 ,
F_118 ( V_39 ) ) ;
return - V_181 ;
}
V_180 = & V_177 [ 3 ] ;
goto V_182;
}
V_179 = strstr ( V_177 , L_55 ) ;
if ( V_179 ) {
if ( V_39 -> V_131 != V_134 ) {
F_33 ( L_56
L_52 , V_177 ,
F_118 ( V_39 ) ) ;
return - V_181 ;
}
V_180 = & V_177 [ 0 ] ;
goto V_182;
}
F_33 ( L_57
L_58 , V_177 ) ;
return - V_181 ;
V_182:
if ( V_177 [ strlen ( V_177 ) - 1 ] == '\n' )
V_177 [ strlen ( V_177 ) - 1 ] = '\0' ;
V_81 = F_129 ( V_41 , V_180 ) ;
if ( V_81 < 0 )
return V_81 ;
return V_176 ;
}
static T_4 F_138 (
struct V_77 * V_78 ,
char * V_174 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
const char * V_183 = NULL ;
T_4 V_81 = - V_181 ;
switch ( V_41 -> V_50 ) {
case V_99 :
V_183 = L_59 ;
break;
case V_51 :
V_183 = L_60 ;
break;
default:
break;
}
if ( V_183 )
V_81 = snprintf ( V_174 , V_175 , L_45 , V_183 ) ;
return V_81 ;
}
static T_4 F_139 (
struct V_77 * V_78 ,
const char * V_174 ,
T_5 V_176 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
if ( ! strncmp ( V_174 , L_59 , 6 ) ) {
V_41 -> V_50 = V_99 ;
return V_176 ;
}
if ( ! strncmp ( V_174 , L_60 , 7 ) ) {
V_41 -> V_50 = V_51 ;
return V_176 ;
}
return - V_181 ;
}
static struct V_77 * F_140 (
struct V_184 * V_185 ,
struct V_186 * V_187 ,
const char * V_167 )
{
struct V_38 * V_39 = F_4 ( V_185 ,
struct V_38 , V_188 ) ;
struct V_40 * V_41 ;
char * V_189 , * V_190 ;
int V_81 ;
unsigned short int V_191 ;
V_189 = strstr ( V_167 , L_61 ) ;
if ( ! V_189 ) {
F_33 ( L_62
L_63 ) ;
return F_141 ( - V_181 ) ;
}
V_189 += 5 ;
V_191 = ( unsigned short int ) F_142 ( V_189 , & V_190 , 0 ) ;
if ( V_191 >= V_192 ) {
F_33 ( L_64
L_65 , V_191 , V_192 ) ;
return F_141 ( - V_181 ) ;
}
V_41 = & V_39 -> V_46 [ V_191 ] ;
V_41 -> V_39 = V_39 ;
V_41 -> V_136 = V_191 ;
V_81 = F_143 ( & V_193 -> V_194 ,
V_185 , & V_41 -> V_86 , V_41 ,
V_195 ) ;
if ( V_81 < 0 )
return F_141 ( - V_168 ) ;
F_31 ( L_66
L_67 , F_118 ( V_39 ) ,
F_144 ( & V_185 -> V_196 . V_197 ) , V_191 ) ;
return & V_41 -> V_86 ;
}
static void F_145 (
struct V_77 * V_78 )
{
struct V_184 * V_185 = V_78 -> V_198 ;
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_38 * V_39 ;
unsigned short V_191 ;
V_39 = V_41 -> V_39 ;
V_191 = V_41 -> V_136 ;
F_134 ( V_41 ) ;
F_146 ( V_78 ) ;
V_41 -> V_39 = NULL ;
V_41 -> V_136 = 0 ;
F_31 ( L_68
L_67 , F_118 ( V_39 ) ,
F_144 ( & V_185 -> V_196 . V_197 ) , V_191 ) ;
}
static struct V_184 * F_147 (
struct V_199 * V_200 ,
struct V_186 * V_187 ,
const char * V_167 )
{
struct V_38 * V_39 ;
struct V_10 * V_67 ;
char * V_179 ;
int V_81 , V_201 = 0 ;
V_39 = F_37 ( sizeof( struct V_38 ) , V_83 ) ;
if ( ! V_39 ) {
F_33 ( L_69 ) ;
return F_141 ( - V_168 ) ;
}
V_179 = strstr ( V_167 , L_50 ) ;
if ( V_179 ) {
V_39 -> V_131 = V_132 ;
goto V_202;
}
V_179 = strstr ( V_167 , L_53 ) ;
if ( V_179 ) {
V_39 -> V_131 = V_133 ;
V_201 = 3 ;
goto V_202;
}
V_179 = strstr ( V_167 , L_55 ) ;
if ( ! V_179 ) {
F_33 ( L_70
L_71 , V_167 ) ;
V_81 = - V_181 ;
goto V_170;
}
V_39 -> V_131 = V_134 ;
V_202:
if ( strlen ( V_167 ) >= V_178 ) {
F_33 ( L_72
L_48 , V_167 , F_118 ( V_39 ) ,
V_178 ) ;
V_81 = - V_181 ;
goto V_170;
}
snprintf ( & V_39 -> V_135 [ 0 ] , V_178 , L_49 , & V_167 [ V_201 ] ) ;
V_81 = F_62 ( V_39 , V_203 ) ;
if ( V_81 )
goto V_170;
V_67 = V_39 -> V_67 ;
V_203 ++ ;
F_31 ( L_73
L_74 ,
F_118 ( V_39 ) , V_167 , V_67 -> V_68 ) ;
return & V_39 -> V_188 ;
V_170:
F_45 ( V_39 ) ;
return F_141 ( V_81 ) ;
}
static void F_148 (
struct V_184 * V_185 )
{
struct V_38 * V_39 = F_4 ( V_185 ,
struct V_38 , V_188 ) ;
F_31 ( L_75
L_76 ,
V_39 -> V_135 , V_39 -> V_67 -> V_68 ) ;
F_149 ( & V_39 -> V_13 ) ;
}
static T_4 F_150 (
struct V_199 * V_200 ,
char * V_174 )
{
return sprintf ( V_174 , L_77 , V_204 ) ;
}
static int F_151 ( void )
{
struct V_199 * V_205 ;
int V_81 ;
V_203 = 0 ;
V_205 = F_152 ( V_206 , L_23 ) ;
if ( F_67 ( V_205 ) ) {
F_33 ( L_78 ) ;
return F_68 ( V_205 ) ;
}
V_205 -> V_194 . V_207 = & F_75 ;
V_205 -> V_194 . V_208 = & F_76 ;
V_205 -> V_194 . V_209 = & F_80 ;
V_205 -> V_194 . V_210 = & F_81 ;
V_205 -> V_194 . V_211 = & F_82 ;
V_205 -> V_194 . V_212 = & F_83 ;
V_205 -> V_194 . V_213 =
& F_87 ;
V_205 -> V_194 . V_214 =
& F_91 ;
V_205 -> V_194 . V_215 = & F_95 ;
V_205 -> V_194 . V_216 =
& F_96 ;
V_205 -> V_194 . V_217 =
& F_97 ;
V_205 -> V_194 . V_218 =
& F_98 ;
V_205 -> V_194 . V_219 = & F_99 ;
V_205 -> V_194 . V_220 =
& F_100 ;
V_205 -> V_194 . V_221 = & F_101 ;
V_205 -> V_194 . V_222 = & F_1 ;
V_205 -> V_194 . V_223 = & F_3 ;
V_205 -> V_194 . V_224 = & F_106 ;
V_205 -> V_194 . V_225 = & F_107 ;
V_205 -> V_194 . V_226 = & F_102 ;
V_205 -> V_194 . V_227 = NULL ;
V_205 -> V_194 . V_228 = & F_108 ;
V_205 -> V_194 . V_229 = & F_110 ;
V_205 -> V_194 . V_230 =
& F_103 ;
V_205 -> V_194 . V_231 = & F_104 ;
V_205 -> V_194 . V_232 = & F_105 ;
V_205 -> V_194 . V_233 = & F_111 ;
V_205 -> V_194 . V_234 = & F_113 ;
V_205 -> V_194 . V_235 = & F_115 ;
V_205 -> V_194 . V_236 = & F_147 ;
V_205 -> V_194 . V_237 = & F_148 ;
V_205 -> V_194 . V_238 = & F_140 ;
V_205 -> V_194 . V_239 = & F_145 ;
V_205 -> V_194 . V_240 = & F_119 ;
V_205 -> V_194 . V_241 = & F_123 ;
V_205 -> V_194 . V_242 = NULL ;
V_205 -> V_194 . V_243 = NULL ;
V_205 -> V_244 . V_245 . V_246 = V_247 ;
V_205 -> V_244 . V_248 . V_246 = V_249 ;
V_205 -> V_244 . V_250 . V_246 = NULL ;
V_205 -> V_244 . V_251 . V_246 = NULL ;
V_205 -> V_244 . V_252 . V_246 = NULL ;
V_81 = F_153 ( V_205 ) ;
if ( V_81 < 0 ) {
F_33 ( L_79
L_80 ) ;
F_154 ( V_205 ) ;
return - 1 ;
}
V_193 = V_205 ;
F_31 ( L_81
L_82 ) ;
return 0 ;
}
static void F_155 ( void )
{
if ( ! V_193 )
return;
F_156 ( V_193 ) ;
V_193 = NULL ;
F_31 ( L_83
L_82 ) ;
}
static int T_6 F_157 ( void )
{
int V_81 = - V_168 ;
V_72 = F_158 ( L_84 , 0 , 0 ) ;
if ( ! V_72 )
goto V_170;
V_7 = F_159 ( L_85 ,
sizeof( struct V_4 ) ,
F_160 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_31 ( L_86
L_87 ) ;
goto V_253;
}
V_81 = F_65 () ;
if ( V_81 )
goto V_254;
V_81 = F_151 () ;
if ( V_81 )
goto V_255;
return 0 ;
V_255:
F_73 () ;
V_254:
F_161 ( V_7 ) ;
V_253:
F_162 ( V_72 ) ;
V_170:
return V_81 ;
}
static void T_7 F_163 ( void )
{
F_155 () ;
F_73 () ;
F_161 ( V_7 ) ;
F_162 ( V_72 ) ;
}
