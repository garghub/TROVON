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
V_43 , V_44 ) ;
if ( V_45 < 0 ) {
F_20 ( V_28 , V_48 ) ;
goto V_49;
}
return;
V_49:
V_28 -> V_66 ( V_28 ) ;
return;
}
static int F_28 ( struct V_10 * V_67 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
F_29 ( L_4
L_5 , V_28 -> V_12 -> V_11 -> V_68 ,
V_28 -> V_12 -> V_47 , V_28 -> V_12 -> V_69 , V_28 -> V_12 -> V_64 ,
V_28 -> V_62 [ 0 ] , F_25 ( V_28 ) ) ;
V_5 = F_30 ( V_7 , V_70 ) ;
if ( ! V_5 ) {
F_31 ( L_6 ) ;
F_20 ( V_28 , V_54 ) ;
V_28 -> V_66 ( V_28 ) ;
return 0 ;
}
V_5 -> V_28 = V_28 ;
V_5 -> V_71 = V_28 -> V_25 ;
F_32 ( & V_5 -> V_35 , F_18 ) ;
F_33 ( V_72 , & V_5 -> V_35 ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_41 ,
struct V_36 * V_37 ,
int V_64 , int V_73 , enum V_74 V_75 )
{
struct V_1 * V_1 = NULL ;
struct V_76 * V_61 ;
struct V_77 * V_78 ;
struct V_4 * V_5 = NULL ;
struct V_79 * V_80 = NULL ;
int V_81 = V_82 , V_45 ;
V_5 = F_30 ( V_7 , V_83 ) ;
if ( ! V_5 ) {
F_31 ( L_7 ) ;
return V_81 ;
}
V_80 = F_35 ( sizeof( struct V_79 ) , V_83 ) ;
if ( ! V_80 ) {
F_31 ( L_8 ) ;
goto V_84;
}
F_36 ( & V_80 -> V_85 ) ;
V_1 = & V_5 -> V_6 ;
V_78 = & V_41 -> V_86 ;
V_61 = V_37 -> V_61 ;
F_37 ( V_1 , V_78 -> V_87 , V_61 , 0 ,
V_88 , V_33 ,
& V_5 -> V_63 [ 0 ] ) ;
V_45 = F_38 ( V_1 , V_80 , V_75 , V_83 ) ;
if ( V_45 < 0 )
goto V_84;
if ( V_75 == V_89 )
V_1 -> V_90 -> V_91 = V_73 ;
if ( F_39 ( V_1 , V_64 ) < 0 ) {
V_81 = V_92 ;
goto V_84;
}
F_40 ( V_1 ) ;
F_41 ( V_80 -> V_85 , F_42 ( & V_80 -> V_93 ) ) ;
V_81 = V_1 -> V_90 -> V_94 ;
V_84:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_43 ( V_80 ) ;
return V_81 ;
}
static int F_44 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_81 = V_95 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_31 ( L_9
L_10 ) ;
return V_95 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
V_81 = F_34 ( V_41 , V_37 , V_28 -> V_12 -> V_64 ,
V_28 -> V_25 , V_89 ) ;
return ( V_81 == V_96 ) ? V_97 : V_95 ;
}
static int F_45 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_81 = V_95 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_31 ( L_9
L_10 ) ;
return V_95 ;
}
V_41 = & V_39 -> V_46 [ V_28 -> V_12 -> V_47 ] ;
V_81 = F_34 ( V_41 , V_37 , V_28 -> V_12 -> V_64 ,
0 , V_98 ) ;
return ( V_81 == V_96 ) ? V_97 : V_95 ;
}
static int F_46 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
if ( ! V_39 ) {
F_31 ( L_9
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
static int F_47 ( struct V_16 * V_100 )
{
F_48 ( V_101 , & V_100 -> V_102 -> V_103 ) ;
return 0 ;
}
static int F_49 ( struct V_16 * V_100 )
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
static int F_50 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_67 ;
int error ;
V_39 = F_51 ( V_13 ) ;
V_67 = F_52 ( & V_105 ,
sizeof( struct V_38 ) ) ;
if ( ! V_67 ) {
F_31 ( L_11 ) ;
return - V_106 ;
}
V_39 -> V_67 = V_67 ;
* ( (struct V_38 * * ) V_67 -> V_107 ) = V_39 ;
V_67 -> V_108 = 2 ;
V_67 -> V_109 = 0 ;
V_67 -> V_110 = 0 ;
V_67 -> V_111 = V_112 ;
error = F_53 ( V_67 , & V_39 -> V_13 ) ;
if ( error ) {
F_31 ( L_12 , V_113 ) ;
F_54 ( V_67 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_55 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_67 ;
V_39 = F_51 ( V_13 ) ;
V_67 = V_39 -> V_67 ;
F_56 ( V_67 ) ;
F_54 ( V_67 ) ;
return 0 ;
}
static void F_57 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = F_51 ( V_13 ) ;
F_43 ( V_39 ) ;
}
static int F_58 ( struct V_38 * V_39 , int V_114 )
{
int V_81 ;
V_39 -> V_13 . V_115 = & V_116 ;
V_39 -> V_13 . V_117 = V_118 ;
V_39 -> V_13 . V_84 = & F_57 ;
F_59 ( & V_39 -> V_13 , L_13 , V_114 ) ;
V_81 = F_60 ( & V_39 -> V_13 ) ;
if ( V_81 ) {
F_31 ( L_14
L_15 , V_81 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_61 ( void )
{
int V_81 ;
V_118 = F_62 ( L_16 ) ;
if ( F_63 ( V_118 ) ) {
F_31 ( L_17 ) ;
return F_64 ( V_118 ) ;
}
V_81 = F_65 ( & V_116 ) ;
if ( V_81 ) {
F_31 ( L_18 ) ;
goto V_119;
}
V_81 = F_66 ( & V_120 ) ;
if ( V_81 ) {
F_31 ( L_19
L_20 ) ;
goto V_121;
}
F_29 ( L_21 ) ;
return V_81 ;
V_121:
F_67 ( & V_116 ) ;
V_119:
F_68 ( V_118 ) ;
return V_81 ;
}
static void F_69 ( void )
{
F_70 ( & V_120 ) ;
F_67 ( & V_116 ) ;
F_68 ( V_118 ) ;
F_29 ( L_22 ) ;
}
static char * F_71 ( void )
{
return L_23 ;
}
static T_2 F_72 ( struct V_77 * V_78 )
{
struct V_40 * V_41 = V_78 -> V_122 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_123 ) {
case V_124 :
return F_73 ( V_78 ) ;
case V_125 :
return F_74 ( V_78 ) ;
case V_126 :
return F_75 ( V_78 ) ;
default:
F_31 ( L_24
L_25 , V_39 -> V_123 ) ;
break;
}
return F_73 ( V_78 ) ;
}
static char * F_76 ( struct V_77 * V_78 )
{
struct V_40 * V_41 = V_78 -> V_122 ;
return & V_41 -> V_39 -> V_127 [ 0 ] ;
}
static T_3 F_77 ( struct V_77 * V_78 )
{
struct V_40 * V_41 = V_78 -> V_122 ;
return V_41 -> V_128 ;
}
static T_1 F_78 ( struct V_77 * V_78 )
{
return 1 ;
}
static T_1 F_79 (
struct V_77 * V_78 ,
struct V_129 * V_130 ,
struct V_131 * V_132 ,
int * V_133 ,
unsigned char * V_134 )
{
struct V_40 * V_41 = V_78 -> V_122 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_123 ) {
case V_124 :
return F_80 ( V_78 , V_130 , V_132 ,
V_133 , V_134 ) ;
case V_125 :
return F_81 ( V_78 , V_130 , V_132 ,
V_133 , V_134 ) ;
case V_126 :
return F_82 ( V_78 , V_130 , V_132 ,
V_133 , V_134 ) ;
default:
F_31 ( L_24
L_25 , V_39 -> V_123 ) ;
break;
}
return F_80 ( V_78 , V_130 , V_132 ,
V_133 , V_134 ) ;
}
static T_1 F_83 (
struct V_77 * V_78 ,
struct V_129 * V_130 ,
struct V_131 * V_132 ,
int * V_133 )
{
struct V_40 * V_41 = V_78 -> V_122 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_123 ) {
case V_124 :
return F_84 ( V_78 , V_130 , V_132 ,
V_133 ) ;
case V_125 :
return F_85 ( V_78 , V_130 , V_132 ,
V_133 ) ;
case V_126 :
return F_86 ( V_78 , V_130 , V_132 ,
V_133 ) ;
default:
F_31 ( L_24
L_25 , V_39 -> V_123 ) ;
break;
}
return F_84 ( V_78 , V_130 , V_132 ,
V_133 ) ;
}
static char * F_87 (
struct V_77 * V_78 ,
const char * V_134 ,
T_1 * V_135 ,
char * * V_136 )
{
struct V_40 * V_41 = V_78 -> V_122 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_123 ) {
case V_124 :
return F_88 ( V_78 , V_134 , V_135 ,
V_136 ) ;
case V_125 :
return F_89 ( V_78 , V_134 , V_135 ,
V_136 ) ;
case V_126 :
return F_90 ( V_78 , V_134 , V_135 ,
V_136 ) ;
default:
F_31 ( L_24
L_25 , V_39 -> V_123 ) ;
break;
}
return F_88 ( V_78 , V_134 , V_135 ,
V_136 ) ;
}
static int F_91 ( struct V_77 * V_78 )
{
return 1 ;
}
static int F_92 ( struct V_77 * V_78 )
{
return 0 ;
}
static int F_93 ( struct V_77 * V_78 )
{
return 0 ;
}
static int F_94 ( struct V_77 * V_78 )
{
return 0 ;
}
static struct V_129 * F_95 (
struct V_77 * V_78 )
{
struct V_137 * V_138 ;
V_138 = F_35 ( sizeof( struct V_137 ) , V_83 ) ;
if ( ! V_138 ) {
F_31 ( L_26 ) ;
return NULL ;
}
return & V_138 -> V_129 ;
}
static void F_96 (
struct V_77 * V_78 ,
struct V_129 * V_130 )
{
struct V_137 * V_138 = F_4 ( V_130 ,
struct V_137 , V_129 ) ;
F_43 ( V_138 ) ;
}
static T_1 F_97 ( struct V_77 * V_78 )
{
return 1 ;
}
static T_1 F_98 ( struct V_76 * V_61 )
{
return 1 ;
}
static void F_99 ( struct V_129 * V_139 )
{
return;
}
static T_1 F_100 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_71 ;
}
static int F_101 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_140 ;
}
static int F_102 ( struct V_76 * V_61 )
{
return 0 ;
}
static void F_103 ( struct V_76 * V_61 )
{
return;
}
static int F_104 ( struct V_1 * V_1 )
{
F_105 ( V_1 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_107 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_29 ( L_27
L_28 , V_28 , V_28 -> V_62 [ 0 ] ) ;
V_28 -> V_141 = V_142 ;
F_20 ( V_28 , V_143 ) ;
if ( ( V_1 -> V_2 & V_144 ) ||
( V_1 -> V_2 & V_145 ) )
F_108 ( V_28 , V_1 -> V_146 ) ;
V_28 -> V_66 ( V_28 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_29 ( L_29
L_28 , V_28 , V_28 -> V_62 [ 0 ] ) ;
if ( V_1 -> V_147 &&
( ( V_1 -> V_2 & V_148 ) ||
( V_1 -> V_2 & V_149 ) ) ) {
memcpy ( V_28 -> V_147 , V_1 -> V_147 ,
V_150 ) ;
V_28 -> V_141 = V_151 ;
F_110 ( V_28 , V_152 ) ;
} else
V_28 -> V_141 = V_1 -> V_153 ;
F_20 ( V_28 , V_143 ) ;
if ( ( V_1 -> V_2 & V_144 ) ||
( V_1 -> V_2 & V_145 ) )
F_108 ( V_28 , V_1 -> V_146 ) ;
V_28 -> V_66 ( V_28 ) ;
return 0 ;
}
static void F_111 ( struct V_1 * V_1 )
{
struct V_90 * V_154 = V_1 -> V_90 ;
struct V_79 * V_80 = V_154 -> V_155 ;
F_112 ( & V_80 -> V_93 , 1 ) ;
F_113 ( & V_80 -> V_85 ) ;
}
static char * F_114 ( struct V_38 * V_39 )
{
switch ( V_39 -> V_123 ) {
case V_124 :
return L_30 ;
case V_125 :
return L_31 ;
case V_126 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_115 (
struct V_77 * V_78 ,
struct V_156 * V_64 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
F_116 ( & V_41 -> V_157 ) ;
F_117 () ;
F_118 ( V_39 -> V_67 , 0 , V_41 -> V_128 , V_64 -> V_158 ) ;
F_29 ( L_34 ) ;
return 0 ;
}
static void F_119 (
struct V_77 * V_78 ,
struct V_156 * V_156 )
{
struct V_16 * V_100 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = F_4 ( V_78 , struct V_40 , V_86 ) ;
V_39 = V_41 -> V_39 ;
V_100 = F_120 ( V_39 -> V_67 , 0 , V_41 -> V_128 ,
V_156 -> V_158 ) ;
if ( ! V_100 ) {
F_31 ( L_35
L_36 , 0 , V_41 -> V_128 , V_156 -> V_158 ) ;
return;
}
F_121 ( V_100 ) ;
F_122 ( V_100 ) ;
F_123 ( & V_41 -> V_157 ) ;
F_124 () ;
F_29 ( L_37 ) ;
}
static int F_125 (
struct V_40 * V_41 ,
const char * V_159 )
{
struct V_77 * V_78 ;
struct V_38 * V_39 = V_41 -> V_39 ;
struct V_36 * V_37 ;
int V_81 = - V_160 ;
if ( V_41 -> V_39 -> V_37 ) {
F_29 ( L_38 ) ;
return - V_161 ;
}
V_78 = & V_41 -> V_86 ;
V_37 = F_35 ( sizeof( struct V_36 ) , V_83 ) ;
if ( ! V_37 ) {
F_31 ( L_39 ) ;
return - V_160 ;
}
V_37 -> V_61 = F_126 () ;
if ( F_63 ( V_37 -> V_61 ) ) {
V_81 = F_64 ( V_37 -> V_61 ) ;
goto V_162;
}
V_37 -> V_61 -> V_129 = F_127 (
V_78 , ( unsigned char * ) V_159 ) ;
if ( ! V_37 -> V_61 -> V_129 ) {
F_128 ( V_37 -> V_61 ) ;
goto V_162;
}
F_129 ( V_78 , V_37 -> V_61 -> V_129 ,
V_37 -> V_61 , V_37 ) ;
V_41 -> V_39 -> V_37 = V_37 ;
F_29 ( L_40
L_41 , F_114 ( V_39 ) ,
V_159 ) ;
return 0 ;
V_162:
F_43 ( V_37 ) ;
return V_81 ;
}
static int F_130 (
struct V_40 * V_163 )
{
struct V_76 * V_61 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_163 -> V_39 ;
if ( ! V_39 )
return - V_106 ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 )
return - V_106 ;
V_61 = V_37 -> V_61 ;
if ( ! V_61 )
return - V_106 ;
if ( F_42 ( & V_163 -> V_157 ) ) {
F_31 ( L_42
L_43 ,
F_42 ( & V_163 -> V_157 ) ) ;
return - V_164 ;
}
F_29 ( L_44
L_41 , F_114 ( V_39 ) ,
V_37 -> V_61 -> V_129 -> V_165 ) ;
F_131 ( V_37 -> V_61 ) ;
V_163 -> V_39 -> V_37 = NULL ;
F_43 ( V_37 ) ;
return 0 ;
}
static T_4 F_132 (
struct V_77 * V_78 ,
char * V_166 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_36 * V_37 ;
T_4 V_81 ;
V_37 = V_41 -> V_39 -> V_37 ;
if ( ! V_37 )
return - V_106 ;
V_81 = snprintf ( V_166 , V_167 , L_45 ,
V_37 -> V_61 -> V_129 -> V_165 ) ;
return V_81 ;
}
static T_4 F_133 (
struct V_77 * V_78 ,
const char * V_166 ,
T_5 V_168 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
unsigned char V_169 [ V_170 ] , * V_171 , * V_172 ;
int V_81 ;
if ( ! strncmp ( V_166 , L_46 , 4 ) ) {
V_81 = F_130 ( V_41 ) ;
return ( ! V_81 ) ? V_168 : V_81 ;
}
if ( strlen ( V_166 ) >= V_170 ) {
F_31 ( L_47
L_48 , V_166 , V_170 ) ;
return - V_173 ;
}
snprintf ( & V_169 [ 0 ] , V_170 , L_49 , V_166 ) ;
V_171 = strstr ( V_169 , L_50 ) ;
if ( V_171 ) {
if ( V_39 -> V_123 != V_124 ) {
F_31 ( L_51
L_52 , V_169 ,
F_114 ( V_39 ) ) ;
return - V_173 ;
}
V_172 = & V_169 [ 0 ] ;
goto V_174;
}
V_171 = strstr ( V_169 , L_53 ) ;
if ( V_171 ) {
if ( V_39 -> V_123 != V_125 ) {
F_31 ( L_54
L_52 , V_169 ,
F_114 ( V_39 ) ) ;
return - V_173 ;
}
V_172 = & V_169 [ 3 ] ;
goto V_174;
}
V_171 = strstr ( V_169 , L_55 ) ;
if ( V_171 ) {
if ( V_39 -> V_123 != V_126 ) {
F_31 ( L_56
L_52 , V_169 ,
F_114 ( V_39 ) ) ;
return - V_173 ;
}
V_172 = & V_169 [ 0 ] ;
goto V_174;
}
F_31 ( L_57
L_58 , V_169 ) ;
return - V_173 ;
V_174:
if ( V_169 [ strlen ( V_169 ) - 1 ] == '\n' )
V_169 [ strlen ( V_169 ) - 1 ] = '\0' ;
V_81 = F_125 ( V_41 , V_172 ) ;
if ( V_81 < 0 )
return V_81 ;
return V_168 ;
}
static T_4 F_134 (
struct V_77 * V_78 ,
char * V_166 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
const char * V_175 = NULL ;
T_4 V_81 = - V_173 ;
switch ( V_41 -> V_50 ) {
case V_99 :
V_175 = L_59 ;
break;
case V_51 :
V_175 = L_60 ;
break;
default:
break;
}
if ( V_175 )
V_81 = snprintf ( V_166 , V_167 , L_45 , V_175 ) ;
return V_81 ;
}
static T_4 F_135 (
struct V_77 * V_78 ,
const char * V_166 ,
T_5 V_168 )
{
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
if ( ! strncmp ( V_166 , L_59 , 6 ) ) {
V_41 -> V_50 = V_99 ;
return V_168 ;
}
if ( ! strncmp ( V_166 , L_60 , 7 ) ) {
V_41 -> V_50 = V_51 ;
return V_168 ;
}
return - V_173 ;
}
struct V_77 * F_136 (
struct V_176 * V_177 ,
struct V_178 * V_179 ,
const char * V_159 )
{
struct V_38 * V_39 = F_4 ( V_177 ,
struct V_38 , V_180 ) ;
struct V_40 * V_41 ;
char * V_181 , * V_182 ;
int V_81 ;
unsigned short int V_183 ;
V_181 = strstr ( V_159 , L_61 ) ;
if ( ! V_181 ) {
F_31 ( L_62
L_63 ) ;
return F_137 ( - V_173 ) ;
}
V_181 += 5 ;
V_183 = ( unsigned short int ) F_138 ( V_181 , & V_182 , 0 ) ;
if ( V_183 >= V_184 ) {
F_31 ( L_64
L_65 , V_183 , V_184 ) ;
return F_137 ( - V_173 ) ;
}
V_41 = & V_39 -> V_46 [ V_183 ] ;
V_41 -> V_39 = V_39 ;
V_41 -> V_128 = V_183 ;
V_81 = F_139 ( & V_185 -> V_186 ,
V_177 , & V_41 -> V_86 , V_41 ,
V_187 ) ;
if ( V_81 < 0 )
return F_137 ( - V_160 ) ;
F_29 ( L_66
L_67 , F_114 ( V_39 ) ,
F_140 ( & V_177 -> V_188 . V_189 ) , V_183 ) ;
return & V_41 -> V_86 ;
}
void F_141 (
struct V_77 * V_78 )
{
struct V_176 * V_177 = V_78 -> V_190 ;
struct V_40 * V_41 = F_4 ( V_78 ,
struct V_40 , V_86 ) ;
struct V_38 * V_39 ;
unsigned short V_183 ;
V_39 = V_41 -> V_39 ;
V_183 = V_41 -> V_128 ;
F_130 ( V_41 ) ;
F_142 ( V_78 ) ;
V_41 -> V_39 = NULL ;
V_41 -> V_128 = 0 ;
F_29 ( L_68
L_67 , F_114 ( V_39 ) ,
F_140 ( & V_177 -> V_188 . V_189 ) , V_183 ) ;
}
struct V_176 * F_143 (
struct V_191 * V_192 ,
struct V_178 * V_179 ,
const char * V_159 )
{
struct V_38 * V_39 ;
struct V_10 * V_67 ;
char * V_171 ;
int V_81 , V_193 = 0 ;
V_39 = F_35 ( sizeof( struct V_38 ) , V_83 ) ;
if ( ! V_39 ) {
F_31 ( L_69 ) ;
return F_137 ( - V_160 ) ;
}
V_171 = strstr ( V_159 , L_50 ) ;
if ( V_171 ) {
V_39 -> V_123 = V_124 ;
goto V_194;
}
V_171 = strstr ( V_159 , L_53 ) ;
if ( V_171 ) {
V_39 -> V_123 = V_125 ;
V_193 = 3 ;
goto V_194;
}
V_171 = strstr ( V_159 , L_55 ) ;
if ( ! V_171 ) {
F_31 ( L_70
L_71 , V_159 ) ;
V_81 = - V_173 ;
goto V_162;
}
V_39 -> V_123 = V_126 ;
V_194:
if ( strlen ( V_159 ) >= V_170 ) {
F_31 ( L_72
L_48 , V_159 , F_114 ( V_39 ) ,
V_170 ) ;
V_81 = - V_173 ;
goto V_162;
}
snprintf ( & V_39 -> V_127 [ 0 ] , V_170 , L_49 , & V_159 [ V_193 ] ) ;
V_81 = F_58 ( V_39 , V_195 ) ;
if ( V_81 )
goto V_162;
V_67 = V_39 -> V_67 ;
V_195 ++ ;
F_29 ( L_73
L_74 ,
F_114 ( V_39 ) , V_159 , V_67 -> V_68 ) ;
return & V_39 -> V_180 ;
V_162:
F_43 ( V_39 ) ;
return F_137 ( V_81 ) ;
}
void F_144 (
struct V_176 * V_177 )
{
struct V_38 * V_39 = F_4 ( V_177 ,
struct V_38 , V_180 ) ;
F_29 ( L_75
L_76 ,
V_39 -> V_127 , V_39 -> V_67 -> V_68 ) ;
F_145 ( & V_39 -> V_13 ) ;
}
static T_4 F_146 (
struct V_191 * V_192 ,
char * V_166 )
{
return sprintf ( V_166 , L_77 , V_196 ) ;
}
static int F_147 ( void )
{
struct V_191 * V_197 ;
int V_81 ;
V_195 = 0 ;
V_197 = F_148 ( V_198 , L_23 ) ;
if ( F_63 ( V_197 ) ) {
F_31 ( L_78 ) ;
return F_64 ( V_197 ) ;
}
V_197 -> V_186 . V_199 = & F_71 ;
V_197 -> V_186 . V_200 = & F_72 ;
V_197 -> V_186 . V_201 = & F_76 ;
V_197 -> V_186 . V_202 = & F_77 ;
V_197 -> V_186 . V_203 = & F_78 ;
V_197 -> V_186 . V_204 = & F_79 ;
V_197 -> V_186 . V_205 =
& F_83 ;
V_197 -> V_186 . V_206 =
& F_87 ;
V_197 -> V_186 . V_207 = & F_91 ;
V_197 -> V_186 . V_208 =
& F_92 ;
V_197 -> V_186 . V_209 =
& F_93 ;
V_197 -> V_186 . V_210 =
& F_94 ;
V_197 -> V_186 . V_211 = & F_95 ;
V_197 -> V_186 . V_212 =
& F_96 ;
V_197 -> V_186 . V_213 = & F_97 ;
V_197 -> V_186 . V_214 = & F_1 ;
V_197 -> V_186 . V_215 = & F_3 ;
V_197 -> V_186 . V_216 = & F_102 ;
V_197 -> V_186 . V_217 = & F_103 ;
V_197 -> V_186 . V_218 = & F_98 ;
V_197 -> V_186 . V_219 = NULL ;
V_197 -> V_186 . V_220 = & F_104 ;
V_197 -> V_186 . V_221 = & F_106 ;
V_197 -> V_186 . V_222 =
& F_99 ;
V_197 -> V_186 . V_223 = & F_100 ;
V_197 -> V_186 . V_224 = & F_101 ;
V_197 -> V_186 . V_225 = & F_107 ;
V_197 -> V_186 . V_226 = & F_109 ;
V_197 -> V_186 . V_227 = & F_111 ;
V_197 -> V_186 . V_228 = & F_143 ;
V_197 -> V_186 . V_229 = & F_144 ;
V_197 -> V_186 . V_230 = & F_136 ;
V_197 -> V_186 . V_231 = & F_141 ;
V_197 -> V_186 . V_232 = & F_115 ;
V_197 -> V_186 . V_233 = & F_119 ;
V_197 -> V_186 . V_234 = NULL ;
V_197 -> V_186 . V_235 = NULL ;
V_197 -> V_236 . V_237 . V_238 = V_239 ;
V_197 -> V_236 . V_240 . V_238 = V_241 ;
V_197 -> V_236 . V_242 . V_238 = NULL ;
V_197 -> V_236 . V_243 . V_238 = NULL ;
V_197 -> V_236 . V_244 . V_238 = NULL ;
V_81 = F_149 ( V_197 ) ;
if ( V_81 < 0 ) {
F_31 ( L_79
L_80 ) ;
F_150 ( V_197 ) ;
return - 1 ;
}
V_185 = V_197 ;
F_29 ( L_81
L_82 ) ;
return 0 ;
}
static void F_151 ( void )
{
if ( ! V_185 )
return;
F_152 ( V_185 ) ;
V_185 = NULL ;
F_29 ( L_83
L_82 ) ;
}
static int T_6 F_153 ( void )
{
int V_81 = - V_160 ;
V_72 = F_154 ( L_84 , 0 , 0 ) ;
if ( ! V_72 )
goto V_162;
V_7 = F_155 ( L_85 ,
sizeof( struct V_4 ) ,
F_156 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_29 ( L_86
L_87 ) ;
goto V_245;
}
V_81 = F_61 () ;
if ( V_81 )
goto V_246;
V_81 = F_147 () ;
if ( V_81 )
goto V_247;
return 0 ;
V_247:
F_69 () ;
V_246:
F_157 ( V_7 ) ;
V_245:
F_158 ( V_72 ) ;
V_162:
return V_81 ;
}
static void T_7 F_159 ( void )
{
F_151 () ;
F_69 () ;
F_157 ( V_7 ) ;
F_158 ( V_72 ) ;
}
