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
T_1 V_44 = 0 , V_45 ;
int V_46 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_41 = & V_39 -> V_47 [ V_28 -> V_12 -> V_48 ] ;
if ( ! V_41 -> V_39 ) {
F_20 ( V_28 , V_49 ) ;
goto V_50;
}
if ( V_41 -> V_51 == V_52 ) {
F_20 ( V_28 , V_53 ) ;
goto V_50;
}
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_21 ( V_54 , V_28 , L_2
L_3 ) ;
F_20 ( V_28 , V_55 ) ;
goto V_50;
}
if ( F_22 ( V_28 ) ) {
struct V_56 * V_57 = F_23 ( V_28 ) ;
V_43 = V_57 -> V_58 . V_59 ;
V_44 = V_57 -> V_58 . V_60 ;
V_1 -> V_2 |= V_61 ;
}
V_45 = F_24 ( V_28 ) ;
if ( ! F_25 ( V_28 ) &&
F_26 ( V_28 ) != V_62 ) {
V_1 -> V_63 = true ;
V_45 = F_27 ( V_28 ) ;
}
V_46 = F_28 ( V_1 , V_37 -> V_64 , V_28 -> V_65 ,
& V_5 -> V_66 [ 0 ] , V_5 -> V_28 -> V_12 -> V_67 ,
V_45 , F_17 ( V_28 ) ,
V_28 -> V_68 , 0 ,
F_29 ( V_28 ) , F_30 ( V_28 ) ,
V_43 , V_44 ,
F_31 ( V_28 ) , F_25 ( V_28 ) ) ;
if ( V_46 < 0 ) {
F_20 ( V_28 , V_49 ) ;
goto V_50;
}
return;
V_50:
F_5 ( V_7 , V_5 ) ;
V_28 -> V_69 ( V_28 ) ;
return;
}
static int F_32 ( struct V_10 * V_70 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
F_33 ( L_4
L_5 , V_28 -> V_12 -> V_11 -> V_71 ,
V_28 -> V_12 -> V_48 , V_28 -> V_12 -> V_72 , V_28 -> V_12 -> V_67 ,
V_28 -> V_65 [ 0 ] , F_27 ( V_28 ) ) ;
V_5 = F_34 ( V_7 , V_73 ) ;
if ( ! V_5 ) {
F_35 ( L_6 ) ;
F_20 ( V_28 , V_55 ) ;
V_28 -> V_69 ( V_28 ) ;
return 0 ;
}
V_5 -> V_28 = V_28 ;
V_5 -> V_74 = V_28 -> V_25 ;
F_36 ( & V_5 -> V_35 , F_18 ) ;
F_37 ( V_75 , & V_5 -> V_35 ) ;
return 0 ;
}
static int F_38 ( struct V_40 * V_41 ,
struct V_36 * V_37 ,
int V_67 , int V_76 , enum V_77 V_78 )
{
struct V_1 * V_1 = NULL ;
struct V_79 * V_64 ;
struct V_80 * V_81 ;
struct V_4 * V_5 = NULL ;
struct V_82 * V_83 = NULL ;
int V_84 = V_85 , V_46 ;
V_5 = F_34 ( V_7 , V_86 ) ;
if ( ! V_5 ) {
F_35 ( L_7 ) ;
return V_84 ;
}
V_83 = F_39 ( sizeof( struct V_82 ) , V_86 ) ;
if ( ! V_83 ) {
F_35 ( L_8 ) ;
goto V_87;
}
F_40 ( & V_83 -> V_88 ) ;
V_1 = & V_5 -> V_6 ;
V_81 = & V_41 -> V_89 ;
V_64 = V_37 -> V_64 ;
F_41 ( V_1 , V_81 -> V_90 , V_64 , 0 ,
V_91 , V_33 ,
& V_5 -> V_66 [ 0 ] ) ;
V_46 = F_42 ( V_1 , V_83 , V_78 , V_86 ) ;
if ( V_46 < 0 )
goto V_87;
if ( V_78 == V_92 )
V_1 -> V_93 -> V_94 = V_76 ;
if ( F_43 ( V_1 , V_67 ) < 0 ) {
V_84 = V_95 ;
goto V_87;
}
F_44 ( V_1 ) ;
F_45 ( V_83 -> V_88 , F_46 ( & V_83 -> V_96 ) ) ;
V_84 = V_1 -> V_93 -> V_97 ;
V_87:
if ( V_1 )
F_2 ( V_1 , 1 ) ;
else
F_5 ( V_7 , V_5 ) ;
F_47 ( V_83 ) ;
return V_84 ;
}
static int F_48 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_84 = V_98 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_35 ( L_9
L_10 ) ;
return V_98 ;
}
V_41 = & V_39 -> V_47 [ V_28 -> V_12 -> V_48 ] ;
V_84 = F_38 ( V_41 , V_37 , V_28 -> V_12 -> V_67 ,
V_28 -> V_25 , V_92 ) ;
return ( V_84 == V_99 ) ? V_100 : V_98 ;
}
static int F_49 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_40 * V_41 ;
int V_84 = V_98 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 ) {
F_35 ( L_9
L_10 ) ;
return V_98 ;
}
V_41 = & V_39 -> V_47 [ V_28 -> V_12 -> V_48 ] ;
V_84 = F_38 ( V_41 , V_37 , V_28 -> V_12 -> V_67 ,
0 , V_101 ) ;
return ( V_84 == V_99 ) ? V_100 : V_98 ;
}
static int F_50 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_39 = * (struct V_38 * * ) F_19 ( V_28 -> V_12 -> V_11 ) ;
if ( ! V_39 ) {
F_35 ( L_9
L_10 ) ;
return V_98 ;
}
V_41 = & V_39 -> V_47 [ V_28 -> V_12 -> V_48 ] ;
if ( V_41 ) {
V_41 -> V_51 = V_102 ;
return V_100 ;
}
return V_98 ;
}
static int F_51 ( struct V_16 * V_103 )
{
F_52 ( V_104 , & V_103 -> V_105 -> V_106 ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_103 )
{
if ( V_103 -> V_26 ) {
F_15 ( V_103 , V_103 -> V_24 ) ;
F_10 ( V_103 , V_33 ,
V_103 -> V_11 -> V_107 ) ;
} else {
F_10 ( V_103 , 0 ,
V_103 -> V_11 -> V_107 ) ;
}
return 0 ;
}
static int F_54 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_70 ;
int error , V_108 ;
V_39 = F_55 ( V_13 ) ;
V_70 = F_56 ( & V_109 ,
sizeof( struct V_38 ) ) ;
if ( ! V_70 ) {
F_35 ( L_11 ) ;
return - V_110 ;
}
V_39 -> V_70 = V_70 ;
* ( (struct V_38 * * ) V_70 -> V_111 ) = V_39 ;
V_70 -> V_112 = 2 ;
V_70 -> V_113 = 0 ;
V_70 -> V_114 = 0 ;
V_70 -> V_115 = V_116 ;
V_108 = V_117 | V_118 |
V_119 | V_120 |
V_121 | V_122 ;
F_57 ( V_70 , V_108 ) ;
F_58 ( V_70 , V_123 ) ;
error = F_59 ( V_70 , & V_39 -> V_13 ) ;
if ( error ) {
F_35 ( L_12 , V_124 ) ;
F_60 ( V_70 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_61 ( struct V_12 * V_13 )
{
struct V_38 * V_39 ;
struct V_10 * V_70 ;
V_39 = F_55 ( V_13 ) ;
V_70 = V_39 -> V_70 ;
F_62 ( V_70 ) ;
F_60 ( V_70 ) ;
return 0 ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = F_55 ( V_13 ) ;
F_47 ( V_39 ) ;
}
static int F_64 ( struct V_38 * V_39 , int V_125 )
{
int V_84 ;
V_39 -> V_13 . V_126 = & V_127 ;
V_39 -> V_13 . V_128 = V_129 ;
V_39 -> V_13 . V_87 = & F_63 ;
F_65 ( & V_39 -> V_13 , L_13 , V_125 ) ;
V_84 = F_66 ( & V_39 -> V_13 ) ;
if ( V_84 ) {
F_35 ( L_14
L_15 , V_84 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_67 ( void )
{
int V_84 ;
V_129 = F_68 ( L_16 ) ;
if ( F_69 ( V_129 ) ) {
F_35 ( L_17 ) ;
return F_70 ( V_129 ) ;
}
V_84 = F_71 ( & V_127 ) ;
if ( V_84 ) {
F_35 ( L_18 ) ;
goto V_130;
}
V_84 = F_72 ( & V_131 ) ;
if ( V_84 ) {
F_35 ( L_19
L_20 ) ;
goto V_132;
}
F_33 ( L_21 ) ;
return V_84 ;
V_132:
F_73 ( & V_127 ) ;
V_130:
F_74 ( V_129 ) ;
return V_84 ;
}
static void F_75 ( void )
{
F_76 ( & V_131 ) ;
F_73 ( & V_127 ) ;
F_74 ( V_129 ) ;
F_33 ( L_22 ) ;
}
static char * F_77 ( void )
{
return L_23 ;
}
static T_2 F_78 ( struct V_80 * V_81 )
{
struct V_40 * V_41 = V_81 -> V_133 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_134 ) {
case V_135 :
return F_79 ( V_81 ) ;
case V_136 :
return F_80 ( V_81 ) ;
case V_137 :
return F_81 ( V_81 ) ;
default:
F_35 ( L_24
L_25 , V_39 -> V_134 ) ;
break;
}
return F_79 ( V_81 ) ;
}
static char * F_82 ( struct V_80 * V_81 )
{
struct V_40 * V_41 = V_81 -> V_133 ;
return & V_41 -> V_39 -> V_138 [ 0 ] ;
}
static T_3 F_83 ( struct V_80 * V_81 )
{
struct V_40 * V_41 = V_81 -> V_133 ;
return V_41 -> V_139 ;
}
static T_1 F_84 ( struct V_80 * V_81 )
{
return 1 ;
}
static T_1 F_85 (
struct V_80 * V_81 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
int * V_144 ,
unsigned char * V_145 )
{
struct V_40 * V_41 = V_81 -> V_133 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_134 ) {
case V_135 :
return F_86 ( V_81 , V_141 , V_143 ,
V_144 , V_145 ) ;
case V_136 :
return F_87 ( V_81 , V_141 , V_143 ,
V_144 , V_145 ) ;
case V_137 :
return F_88 ( V_81 , V_141 , V_143 ,
V_144 , V_145 ) ;
default:
F_35 ( L_24
L_25 , V_39 -> V_134 ) ;
break;
}
return F_86 ( V_81 , V_141 , V_143 ,
V_144 , V_145 ) ;
}
static T_1 F_89 (
struct V_80 * V_81 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
int * V_144 )
{
struct V_40 * V_41 = V_81 -> V_133 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_134 ) {
case V_135 :
return F_90 ( V_81 , V_141 , V_143 ,
V_144 ) ;
case V_136 :
return F_91 ( V_81 , V_141 , V_143 ,
V_144 ) ;
case V_137 :
return F_92 ( V_81 , V_141 , V_143 ,
V_144 ) ;
default:
F_35 ( L_24
L_25 , V_39 -> V_134 ) ;
break;
}
return F_90 ( V_81 , V_141 , V_143 ,
V_144 ) ;
}
static char * F_93 (
struct V_80 * V_81 ,
const char * V_145 ,
T_1 * V_146 ,
char * * V_147 )
{
struct V_40 * V_41 = V_81 -> V_133 ;
struct V_38 * V_39 = V_41 -> V_39 ;
switch ( V_39 -> V_134 ) {
case V_135 :
return F_94 ( V_81 , V_145 , V_146 ,
V_147 ) ;
case V_136 :
return F_95 ( V_81 , V_145 , V_146 ,
V_147 ) ;
case V_137 :
return F_96 ( V_81 , V_145 , V_146 ,
V_147 ) ;
default:
F_35 ( L_24
L_25 , V_39 -> V_134 ) ;
break;
}
return F_94 ( V_81 , V_145 , V_146 ,
V_147 ) ;
}
static int F_97 ( struct V_80 * V_81 )
{
return 1 ;
}
static int F_98 ( struct V_80 * V_81 )
{
return 0 ;
}
static int F_99 ( struct V_80 * V_81 )
{
return 0 ;
}
static int F_100 ( struct V_80 * V_81 )
{
return 0 ;
}
static struct V_140 * F_101 (
struct V_80 * V_81 )
{
struct V_148 * V_149 ;
V_149 = F_39 ( sizeof( struct V_148 ) , V_86 ) ;
if ( ! V_149 ) {
F_35 ( L_26 ) ;
return NULL ;
}
return & V_149 -> V_140 ;
}
static void F_102 (
struct V_80 * V_81 ,
struct V_140 * V_141 )
{
struct V_148 * V_149 = F_4 ( V_141 ,
struct V_148 , V_140 ) ;
F_47 ( V_149 ) ;
}
static T_1 F_103 ( struct V_80 * V_81 )
{
return 1 ;
}
static T_1 F_104 ( struct V_79 * V_64 )
{
return 1 ;
}
static void F_105 ( struct V_140 * V_150 )
{
return;
}
static T_1 F_106 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_74 ;
}
static int F_107 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
return V_5 -> V_151 ;
}
static int F_108 ( struct V_79 * V_64 )
{
return 0 ;
}
static void F_109 ( struct V_79 * V_64 )
{
return;
}
static int F_110 ( struct V_1 * V_1 )
{
F_111 ( V_1 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_113 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_33 ( L_27
L_28 , V_28 , V_28 -> V_65 [ 0 ] ) ;
V_28 -> V_152 = V_153 ;
F_20 ( V_28 , V_154 ) ;
if ( ( V_1 -> V_2 & V_155 ) ||
( V_1 -> V_2 & V_156 ) )
F_114 ( V_28 , V_1 -> V_157 ) ;
V_28 -> V_69 ( V_28 ) ;
return 0 ;
}
static int F_115 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_4 ( V_1 ,
struct V_4 , V_6 ) ;
struct V_27 * V_28 = V_5 -> V_28 ;
F_33 ( L_29
L_28 , V_28 , V_28 -> V_65 [ 0 ] ) ;
if ( V_1 -> V_158 &&
( ( V_1 -> V_2 & V_159 ) ||
( V_1 -> V_2 & V_160 ) ) ) {
memcpy ( V_28 -> V_158 , V_1 -> V_158 ,
V_161 ) ;
V_28 -> V_152 = V_162 ;
F_116 ( V_28 , V_163 ) ;
} else
V_28 -> V_152 = V_1 -> V_164 ;
F_20 ( V_28 , V_154 ) ;
if ( ( V_1 -> V_2 & V_155 ) ||
( V_1 -> V_2 & V_156 ) )
F_114 ( V_28 , V_1 -> V_157 ) ;
V_28 -> V_69 ( V_28 ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_1 )
{
struct V_93 * V_165 = V_1 -> V_93 ;
struct V_82 * V_83 = V_165 -> V_166 ;
F_118 ( & V_83 -> V_96 , 1 ) ;
F_119 ( & V_83 -> V_88 ) ;
}
static void F_120 ( struct V_1 * V_1 )
{
return;
}
static char * F_121 ( struct V_38 * V_39 )
{
switch ( V_39 -> V_134 ) {
case V_135 :
return L_30 ;
case V_136 :
return L_31 ;
case V_137 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_122 (
struct V_80 * V_81 ,
struct V_167 * V_67 )
{
struct V_40 * V_41 = F_4 ( V_81 ,
struct V_40 , V_89 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
F_123 ( & V_41 -> V_168 ) ;
F_124 () ;
F_125 ( V_39 -> V_70 , 0 , V_41 -> V_139 , V_67 -> V_169 ) ;
F_33 ( L_34 ) ;
return 0 ;
}
static void F_126 (
struct V_80 * V_81 ,
struct V_167 * V_167 )
{
struct V_16 * V_103 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = F_4 ( V_81 , struct V_40 , V_89 ) ;
V_39 = V_41 -> V_39 ;
V_103 = F_127 ( V_39 -> V_70 , 0 , V_41 -> V_139 ,
V_167 -> V_169 ) ;
if ( ! V_103 ) {
F_35 ( L_35
L_36 , 0 , V_41 -> V_139 , V_167 -> V_169 ) ;
return;
}
F_128 ( V_103 ) ;
F_129 ( V_103 ) ;
F_130 ( & V_41 -> V_168 ) ;
F_124 () ;
F_33 ( L_37 ) ;
}
static int F_131 (
struct V_40 * V_41 ,
const char * V_170 )
{
struct V_80 * V_81 ;
struct V_38 * V_39 = V_41 -> V_39 ;
struct V_36 * V_37 ;
int V_84 = - V_171 ;
if ( V_41 -> V_39 -> V_37 ) {
F_33 ( L_38 ) ;
return - V_172 ;
}
V_81 = & V_41 -> V_89 ;
V_37 = F_39 ( sizeof( struct V_36 ) , V_86 ) ;
if ( ! V_37 ) {
F_35 ( L_39 ) ;
return - V_171 ;
}
V_37 -> V_64 = F_132 ( V_173 ) ;
if ( F_69 ( V_37 -> V_64 ) ) {
V_84 = F_70 ( V_37 -> V_64 ) ;
goto V_174;
}
V_37 -> V_64 -> V_140 = F_133 (
V_81 , ( unsigned char * ) V_170 ) ;
if ( ! V_37 -> V_64 -> V_140 ) {
F_134 ( V_37 -> V_64 ) ;
goto V_174;
}
F_135 ( V_81 , V_37 -> V_64 -> V_140 ,
V_37 -> V_64 , V_37 ) ;
V_41 -> V_39 -> V_37 = V_37 ;
F_33 ( L_40
L_41 , F_121 ( V_39 ) ,
V_170 ) ;
return 0 ;
V_174:
F_47 ( V_37 ) ;
return V_84 ;
}
static int F_136 (
struct V_40 * V_175 )
{
struct V_79 * V_64 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_175 -> V_39 ;
if ( ! V_39 )
return - V_110 ;
V_37 = V_39 -> V_37 ;
if ( ! V_37 )
return - V_110 ;
V_64 = V_37 -> V_64 ;
if ( ! V_64 )
return - V_110 ;
if ( F_46 ( & V_175 -> V_168 ) ) {
F_35 ( L_42
L_43 ,
F_46 ( & V_175 -> V_168 ) ) ;
return - V_176 ;
}
F_33 ( L_44
L_41 , F_121 ( V_39 ) ,
V_37 -> V_64 -> V_140 -> V_177 ) ;
F_137 ( V_37 -> V_64 ) ;
V_175 -> V_39 -> V_37 = NULL ;
F_47 ( V_37 ) ;
return 0 ;
}
static T_4 F_138 (
struct V_80 * V_81 ,
char * V_178 )
{
struct V_40 * V_41 = F_4 ( V_81 ,
struct V_40 , V_89 ) ;
struct V_36 * V_37 ;
T_4 V_84 ;
V_37 = V_41 -> V_39 -> V_37 ;
if ( ! V_37 )
return - V_110 ;
V_84 = snprintf ( V_178 , V_179 , L_45 ,
V_37 -> V_64 -> V_140 -> V_177 ) ;
return V_84 ;
}
static T_4 F_139 (
struct V_80 * V_81 ,
const char * V_178 ,
T_5 V_180 )
{
struct V_40 * V_41 = F_4 ( V_81 ,
struct V_40 , V_89 ) ;
struct V_38 * V_39 = V_41 -> V_39 ;
unsigned char V_181 [ V_182 ] , * V_183 , * V_184 ;
int V_84 ;
if ( ! strncmp ( V_178 , L_46 , 4 ) ) {
V_84 = F_136 ( V_41 ) ;
return ( ! V_84 ) ? V_180 : V_84 ;
}
if ( strlen ( V_178 ) >= V_182 ) {
F_35 ( L_47
L_48 , V_178 , V_182 ) ;
return - V_185 ;
}
snprintf ( & V_181 [ 0 ] , V_182 , L_49 , V_178 ) ;
V_183 = strstr ( V_181 , L_50 ) ;
if ( V_183 ) {
if ( V_39 -> V_134 != V_135 ) {
F_35 ( L_51
L_52 , V_181 ,
F_121 ( V_39 ) ) ;
return - V_185 ;
}
V_184 = & V_181 [ 0 ] ;
goto V_186;
}
V_183 = strstr ( V_181 , L_53 ) ;
if ( V_183 ) {
if ( V_39 -> V_134 != V_136 ) {
F_35 ( L_54
L_52 , V_181 ,
F_121 ( V_39 ) ) ;
return - V_185 ;
}
V_184 = & V_181 [ 3 ] ;
goto V_186;
}
V_183 = strstr ( V_181 , L_55 ) ;
if ( V_183 ) {
if ( V_39 -> V_134 != V_137 ) {
F_35 ( L_56
L_52 , V_181 ,
F_121 ( V_39 ) ) ;
return - V_185 ;
}
V_184 = & V_181 [ 0 ] ;
goto V_186;
}
F_35 ( L_57
L_58 , V_181 ) ;
return - V_185 ;
V_186:
if ( V_181 [ strlen ( V_181 ) - 1 ] == '\n' )
V_181 [ strlen ( V_181 ) - 1 ] = '\0' ;
V_84 = F_131 ( V_41 , V_184 ) ;
if ( V_84 < 0 )
return V_84 ;
return V_180 ;
}
static T_4 F_140 (
struct V_80 * V_81 ,
char * V_178 )
{
struct V_40 * V_41 = F_4 ( V_81 ,
struct V_40 , V_89 ) ;
const char * V_187 = NULL ;
T_4 V_84 = - V_185 ;
switch ( V_41 -> V_51 ) {
case V_102 :
V_187 = L_59 ;
break;
case V_52 :
V_187 = L_60 ;
break;
default:
break;
}
if ( V_187 )
V_84 = snprintf ( V_178 , V_179 , L_45 , V_187 ) ;
return V_84 ;
}
static T_4 F_141 (
struct V_80 * V_81 ,
const char * V_178 ,
T_5 V_180 )
{
struct V_40 * V_41 = F_4 ( V_81 ,
struct V_40 , V_89 ) ;
if ( ! strncmp ( V_178 , L_59 , 6 ) ) {
V_41 -> V_51 = V_102 ;
return V_180 ;
}
if ( ! strncmp ( V_178 , L_60 , 7 ) ) {
V_41 -> V_51 = V_52 ;
return V_180 ;
}
return - V_185 ;
}
static struct V_80 * F_142 (
struct V_188 * V_189 ,
struct V_190 * V_191 ,
const char * V_170 )
{
struct V_38 * V_39 = F_4 ( V_189 ,
struct V_38 , V_192 ) ;
struct V_40 * V_41 ;
char * V_193 , * V_194 ;
int V_84 ;
unsigned short int V_195 ;
V_193 = strstr ( V_170 , L_61 ) ;
if ( ! V_193 ) {
F_35 ( L_62
L_63 ) ;
return F_143 ( - V_185 ) ;
}
V_193 += 5 ;
V_195 = ( unsigned short int ) F_144 ( V_193 , & V_194 , 0 ) ;
if ( V_195 >= V_196 ) {
F_35 ( L_64
L_65 , V_195 , V_196 ) ;
return F_143 ( - V_185 ) ;
}
V_41 = & V_39 -> V_47 [ V_195 ] ;
V_41 -> V_39 = V_39 ;
V_41 -> V_139 = V_195 ;
V_84 = F_145 ( & V_197 -> V_198 ,
V_189 , & V_41 -> V_89 , V_41 ,
V_199 ) ;
if ( V_84 < 0 )
return F_143 ( - V_171 ) ;
F_33 ( L_66
L_67 , F_121 ( V_39 ) ,
F_146 ( & V_189 -> V_200 . V_201 ) , V_195 ) ;
return & V_41 -> V_89 ;
}
static void F_147 (
struct V_80 * V_81 )
{
struct V_188 * V_189 = V_81 -> V_202 ;
struct V_40 * V_41 = F_4 ( V_81 ,
struct V_40 , V_89 ) ;
struct V_38 * V_39 ;
unsigned short V_195 ;
V_39 = V_41 -> V_39 ;
V_195 = V_41 -> V_139 ;
F_136 ( V_41 ) ;
F_148 ( V_81 ) ;
V_41 -> V_39 = NULL ;
V_41 -> V_139 = 0 ;
F_33 ( L_68
L_67 , F_121 ( V_39 ) ,
F_146 ( & V_189 -> V_200 . V_201 ) , V_195 ) ;
}
static struct V_188 * F_149 (
struct V_203 * V_204 ,
struct V_190 * V_191 ,
const char * V_170 )
{
struct V_38 * V_39 ;
struct V_10 * V_70 ;
char * V_183 ;
int V_84 , V_205 = 0 ;
V_39 = F_39 ( sizeof( struct V_38 ) , V_86 ) ;
if ( ! V_39 ) {
F_35 ( L_69 ) ;
return F_143 ( - V_171 ) ;
}
V_183 = strstr ( V_170 , L_50 ) ;
if ( V_183 ) {
V_39 -> V_134 = V_135 ;
goto V_206;
}
V_183 = strstr ( V_170 , L_53 ) ;
if ( V_183 ) {
V_39 -> V_134 = V_136 ;
V_205 = 3 ;
goto V_206;
}
V_183 = strstr ( V_170 , L_55 ) ;
if ( ! V_183 ) {
F_35 ( L_70
L_71 , V_170 ) ;
V_84 = - V_185 ;
goto V_174;
}
V_39 -> V_134 = V_137 ;
V_206:
if ( strlen ( V_170 ) >= V_182 ) {
F_35 ( L_72
L_48 , V_170 , F_121 ( V_39 ) ,
V_182 ) ;
V_84 = - V_185 ;
goto V_174;
}
snprintf ( & V_39 -> V_138 [ 0 ] , V_182 , L_49 , & V_170 [ V_205 ] ) ;
V_84 = F_64 ( V_39 , V_207 ) ;
if ( V_84 )
goto V_174;
V_70 = V_39 -> V_70 ;
V_207 ++ ;
F_33 ( L_73
L_74 ,
F_121 ( V_39 ) , V_170 , V_70 -> V_71 ) ;
return & V_39 -> V_192 ;
V_174:
F_47 ( V_39 ) ;
return F_143 ( V_84 ) ;
}
static void F_150 (
struct V_188 * V_189 )
{
struct V_38 * V_39 = F_4 ( V_189 ,
struct V_38 , V_192 ) ;
F_33 ( L_75
L_76 ,
V_39 -> V_138 , V_39 -> V_70 -> V_71 ) ;
F_151 ( & V_39 -> V_13 ) ;
}
static T_4 F_152 (
struct V_203 * V_204 ,
char * V_178 )
{
return sprintf ( V_178 , L_77 , V_208 ) ;
}
static int F_153 ( void )
{
struct V_203 * V_209 ;
int V_84 ;
V_207 = 0 ;
V_209 = F_154 ( V_210 , L_23 ) ;
if ( F_69 ( V_209 ) ) {
F_35 ( L_78 ) ;
return F_70 ( V_209 ) ;
}
V_209 -> V_198 . V_211 = & F_77 ;
V_209 -> V_198 . V_212 = & F_78 ;
V_209 -> V_198 . V_213 = & F_82 ;
V_209 -> V_198 . V_214 = & F_83 ;
V_209 -> V_198 . V_215 = & F_84 ;
V_209 -> V_198 . V_216 = & F_85 ;
V_209 -> V_198 . V_217 =
& F_89 ;
V_209 -> V_198 . V_218 =
& F_93 ;
V_209 -> V_198 . V_219 = & F_97 ;
V_209 -> V_198 . V_220 =
& F_98 ;
V_209 -> V_198 . V_221 =
& F_99 ;
V_209 -> V_198 . V_222 =
& F_100 ;
V_209 -> V_198 . V_223 = & F_101 ;
V_209 -> V_198 . V_224 =
& F_102 ;
V_209 -> V_198 . V_225 = & F_103 ;
V_209 -> V_198 . V_226 = & F_1 ;
V_209 -> V_198 . V_227 = & F_3 ;
V_209 -> V_198 . V_228 = & F_108 ;
V_209 -> V_198 . V_229 = & F_109 ;
V_209 -> V_198 . V_230 = & F_104 ;
V_209 -> V_198 . V_231 = NULL ;
V_209 -> V_198 . V_232 = & F_110 ;
V_209 -> V_198 . V_233 = & F_112 ;
V_209 -> V_198 . V_234 =
& F_105 ;
V_209 -> V_198 . V_235 = & F_106 ;
V_209 -> V_198 . V_236 = & F_107 ;
V_209 -> V_198 . V_237 = & F_113 ;
V_209 -> V_198 . V_238 = & F_115 ;
V_209 -> V_198 . V_239 = & F_117 ;
V_209 -> V_198 . V_240 = & F_120 ;
V_209 -> V_198 . V_241 = & F_149 ;
V_209 -> V_198 . V_242 = & F_150 ;
V_209 -> V_198 . V_243 = & F_142 ;
V_209 -> V_198 . V_244 = & F_147 ;
V_209 -> V_198 . V_245 = & F_122 ;
V_209 -> V_198 . V_246 = & F_126 ;
V_209 -> V_198 . V_247 = NULL ;
V_209 -> V_198 . V_248 = NULL ;
V_209 -> V_249 . V_250 . V_251 = V_252 ;
V_209 -> V_249 . V_253 . V_251 = V_254 ;
V_209 -> V_249 . V_255 . V_251 = NULL ;
V_209 -> V_249 . V_256 . V_251 = NULL ;
V_209 -> V_249 . V_257 . V_251 = NULL ;
V_84 = F_155 ( V_209 ) ;
if ( V_84 < 0 ) {
F_35 ( L_79
L_80 ) ;
F_156 ( V_209 ) ;
return - 1 ;
}
V_197 = V_209 ;
F_33 ( L_81
L_82 ) ;
return 0 ;
}
static void F_157 ( void )
{
if ( ! V_197 )
return;
F_158 ( V_197 ) ;
V_197 = NULL ;
F_33 ( L_83
L_82 ) ;
}
static int T_6 F_159 ( void )
{
int V_84 = - V_171 ;
V_75 = F_160 ( L_84 , 0 , 0 ) ;
if ( ! V_75 )
goto V_174;
V_7 = F_161 ( L_85 ,
sizeof( struct V_4 ) ,
F_162 ( struct V_4 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_33 ( L_86
L_87 ) ;
goto V_258;
}
V_84 = F_67 () ;
if ( V_84 )
goto V_259;
V_84 = F_153 () ;
if ( V_84 )
goto V_260;
return 0 ;
V_260:
F_75 () ;
V_259:
F_163 ( V_7 ) ;
V_258:
F_164 ( V_75 ) ;
V_174:
return V_84 ;
}
static void T_7 F_165 ( void )
{
F_157 () ;
F_75 () ;
F_163 ( V_7 ) ;
F_164 ( V_75 ) ;
}
