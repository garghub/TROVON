static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != 0 || V_2 -> V_5 == 0 )
return V_2 -> V_3 . V_4 ;
else
return - 1 ;
}
static T_1 F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_3 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
return sprintf ( V_10 , L_1 , V_2 -> V_13 . V_14 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_2 V_15 )
{
struct V_11 * V_12 = F_3 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
unsigned long V_16 ;
if ( F_6 ( V_10 , 0 , & V_16 ) )
return - V_17 ;
V_2 -> V_13 . V_14 = V_16 ;
return V_15 ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
int V_22 ;
switch ( V_21 -> V_23 ) {
case V_24 :
V_2 -> V_25 = V_19 -> V_26 -> V_27 ;
V_2 -> V_28 = 0 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_29 ; V_22 ++ ) {
if ( V_19 -> V_21 [ V_22 ] . V_23 == V_21 -> V_23 ) {
V_2 -> V_28 = V_22 ;
break;
}
}
break;
case V_30 :
V_2 -> V_31 = V_19 -> V_26 -> V_27 ;
V_2 -> V_32 = V_19 -> V_33 [ 0 ] ;
if ( V_2 -> V_13 . V_32 )
V_2 -> V_32 = V_2 -> V_13 . V_32 ;
break;
}
}
static void F_8 ( struct V_34 * V_35 , unsigned int V_36 ,
struct V_18 * V_19 , int V_37 )
{
int V_38 = V_19 -> V_39 ;
int V_40 = V_19 -> V_41 ;
int V_42 = V_37 ? ( V_40 - V_38 ) / V_37 : 0 ;
F_9 ( V_35 , V_36 , V_38 , V_40 , V_42 , 0 ) ;
}
static void F_10 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
if ( V_46 -> V_48 >= V_49 )
return;
V_46 -> V_50 [ V_46 -> V_48 ++ ] = V_21 -> V_23 ;
}
static int F_11 ( struct V_11 * V_12 , struct V_43 * V_44 ,
struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long * * V_51 , int * V_52 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_53 * V_54 = & V_2 -> V_13 ;
int V_36 ;
if ( V_19 -> V_55 == V_56 )
V_2 -> V_57 |= V_58 ;
else if ( V_19 -> V_55 != V_59 )
return 0 ;
if ( V_19 -> V_55 == V_59 ||
( V_21 -> V_23 & V_60 ) == V_61 )
V_2 -> V_57 |= V_62 ;
if ( V_19 -> V_63 == V_64 )
return - 1 ;
switch ( V_21 -> V_23 & V_60 ) {
case V_65 :
switch ( V_21 -> V_23 ) {
case V_66 :
F_12 ( V_44 , V_21 , V_51 , V_52 ,
V_67 , V_68 ) ;
F_8 ( V_44 -> V_35 , V_68 , V_19 ,
V_54 -> V_69 ) ;
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_72 :
F_12 ( V_44 , V_21 , V_51 , V_52 ,
V_67 , V_73 ) ;
F_8 ( V_44 -> V_35 , V_73 , V_19 ,
V_54 -> V_69 ) ;
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
}
return 0 ;
case V_74 :
switch ( V_21 -> V_23 ) {
case V_75 :
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_76 :
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_77 :
F_12 ( V_44 , V_21 , V_51 , V_52 , V_78 , V_79 ) ;
F_13 ( V_44 -> V_35 , V_78 , V_79 ) ;
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_80 :
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
V_2 -> V_81 ++ ;
return 1 ;
case V_82 :
F_12 ( V_44 , V_21 , V_51 , V_52 ,
V_67 , V_83 ) ;
if ( ! ( V_54 -> V_14 & V_84 ) )
F_8 ( V_44 -> V_35 , V_83 , V_19 ,
V_54 -> V_85 ) ;
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_86 :
F_12 ( V_44 , V_21 , V_51 , V_52 ,
V_67 , V_87 ) ;
if ( ! ( V_54 -> V_14 & V_84 ) ) {
F_8 ( V_44 -> V_35 , V_87 , V_19 ,
V_54 -> V_88 ) ;
F_9 ( V_44 -> V_35 ,
V_89 , 0 , 1 , 0 , 0 ) ;
}
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_90 :
F_12 ( V_44 , V_21 , V_51 , V_52 ,
V_67 , V_91 ) ;
F_8 ( V_44 -> V_35 , V_91 , V_19 ,
V_54 -> V_92 ) ;
F_10 ( V_21 , V_2 , V_44 ) ;
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_93 :
V_2 -> V_70 = V_19 -> V_71 ;
return 1 ;
case V_30 :
V_2 -> V_70 = V_19 -> V_71 ;
return - 1 ;
case V_94 :
return - 1 ;
}
return 0 ;
case V_61 :
V_36 = V_95 + ( ( V_21 -> V_23 - 1 ) & V_96 ) ;
F_12 ( V_44 , V_21 , V_51 , V_52 , V_78 , V_36 ) ;
F_13 ( V_44 -> V_35 , V_78 , V_36 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_43 * V_44 ,
struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long * * V_51 , int * V_52 )
{
if ( V_21 -> type == V_78 || V_21 -> type == V_67 )
F_15 ( V_21 -> type , V_44 -> V_35 -> V_97 ) ;
return - 1 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_14 & V_98 )
return V_2 -> V_3 . V_4 ;
if ( V_14 & V_99 )
return F_1 ( V_2 ) ;
if ( V_14 & V_100 )
return V_2 -> V_5 ;
if ( V_14 & V_101 )
return V_2 -> V_3 . V_4 - 1 ;
return F_17 ( V_35 , V_2 -> V_3 . V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
if ( V_2 -> V_102 ) {
int V_103 = F_16 ( V_2 , V_35 ) ;
struct V_104 * V_105 = & V_2 -> V_3 ;
if ( V_103 < 0 || V_103 >= V_2 -> V_32 )
return;
F_19 ( V_35 , V_103 ) ;
F_20 ( V_35 , V_106 ,
V_105 -> V_107 ) ;
if ( V_105 -> V_107 ) {
int V_108 = ( V_105 -> V_109 > V_105 -> V_110 ) ;
int V_111 = V_52 ( V_105 -> V_109 , V_105 -> V_110 ) >> 1 ;
int V_112 = F_21 ( V_105 -> V_109 , V_105 -> V_110 ) >> 1 ;
F_22 ( V_35 , V_67 , V_68 , V_105 -> V_113 ) ;
F_22 ( V_35 , V_67 , V_73 , V_105 -> V_114 ) ;
F_22 ( V_35 , V_67 , V_89 , V_108 ) ;
F_22 ( V_35 , V_67 , V_91 , V_105 -> V_115 ) ;
F_22 ( V_35 , V_67 , V_83 , V_111 ) ;
F_22 ( V_35 , V_67 , V_87 , V_112 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_23 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
F_24 ( V_35 ) ;
F_25 ( V_35 ) ;
V_2 -> V_5 = 0 ;
}
static int F_26 ( struct V_11 * V_23 , struct V_18 * V_19 ,
struct V_20 * V_21 , T_3 V_33 )
{
struct V_1 * V_2 = F_4 ( V_23 ) ;
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_23 -> V_116 & V_117 ) {
switch ( V_21 -> V_23 ) {
case V_75 :
if ( V_14 & V_118 )
V_2 -> V_102 = true ;
else if ( V_14 & V_119 )
V_2 -> V_102 = V_33 ;
break;
case V_77 :
if ( V_14 & V_120 )
V_2 -> V_102 = V_33 ;
V_2 -> V_3 . V_107 = V_33 ;
break;
case V_76 :
if ( V_14 & V_121 )
V_2 -> V_102 = V_33 ;
break;
case V_80 :
V_2 -> V_3 . V_4 = V_33 ;
break;
case V_90 :
V_2 -> V_3 . V_115 = V_33 ;
break;
case V_66 :
V_2 -> V_3 . V_113 = V_33 ;
break;
case V_72 :
V_2 -> V_3 . V_114 = V_33 ;
break;
case V_82 :
V_2 -> V_3 . V_109 = V_33 ;
break;
case V_86 :
V_2 -> V_3 . V_110 = V_33 ;
break;
case V_93 :
if ( V_33 )
V_2 -> V_122 = V_33 ;
break;
case V_94 :
break;
default:
return 0 ;
}
if ( V_21 -> V_23 == V_2 -> V_123 )
F_18 ( V_2 , V_19 -> V_124 -> V_35 ) ;
if ( V_19 -> V_71 == V_2 -> V_70
&& V_2 -> V_5 >= V_2 -> V_122 )
F_23 ( V_2 , V_19 -> V_124 -> V_35 ) ;
}
if ( V_23 -> V_116 & V_125 && V_23 -> V_126 )
V_23 -> V_126 ( V_23 , V_19 , V_21 , V_33 ) ;
return 1 ;
}
static void F_27 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
if ( V_2 -> V_25 < 0 )
return;
V_130 = & ( V_12 -> V_131 [ V_132 ] ) ;
V_128 = V_130 -> V_133 [ V_2 -> V_25 ] ;
if ( V_128 ) {
V_128 -> V_19 [ 0 ] -> V_33 [ V_2 -> V_28 ] = 0x02 ;
F_28 ( V_12 , V_128 , V_134 ) ;
}
}
static void F_29 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
int V_135 , V_52 ;
if ( V_2 -> V_31 < 0 )
return;
if ( ! V_2 -> V_13 . V_32 )
return;
V_130 = & V_12 -> V_131 [ V_132 ] ;
V_128 = V_130 -> V_133 [ V_2 -> V_31 ] ;
if ( V_128 ) {
V_52 = V_2 -> V_13 . V_32 ;
V_135 = V_128 -> V_19 [ 0 ] -> V_41 ;
V_52 = F_21 ( V_135 , V_52 ) ;
if ( V_128 -> V_19 [ 0 ] -> V_33 [ 0 ] != V_52 ) {
V_128 -> V_19 [ 0 ] -> V_33 [ 0 ] = V_52 ;
F_28 ( V_12 , V_128 , V_134 ) ;
}
}
}
static void F_30 ( struct V_1 * V_2 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_81 == 1 ) {
V_14 |= V_118 ;
V_14 &= ~ V_120 ;
V_14 &= ~ V_119 ;
V_14 &= ~ V_121 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
if ( V_2 -> V_81 > 0 ) {
int V_136 = V_46 -> V_48 / V_2 -> V_81 ;
V_2 -> V_123 = V_46 -> V_50 [ V_136 - 1 ] ;
}
}
static void F_32 ( struct V_11 * V_12 , struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_53 * V_54 = & V_2 -> V_13 ;
struct V_34 * V_35 = V_44 -> V_35 ;
if ( ! F_33 ( V_68 , V_35 -> V_137 ) )
return;
if ( ! V_2 -> V_32 )
V_2 -> V_32 = V_138 ;
F_31 ( V_2 ) ;
if ( V_2 -> V_139 )
F_30 ( V_2 ) ;
if ( V_54 -> V_140 )
V_2 -> V_57 |= V_62 ;
if ( V_54 -> V_14 & V_120 )
V_2 -> V_57 |= V_141 ;
F_34 ( V_35 , V_2 -> V_32 , V_2 -> V_57 ) ;
V_2 -> V_57 = 0 ;
}
static int F_35 ( struct V_11 * V_12 , const struct V_142 * V_27 )
{
int V_143 , V_22 ;
struct V_1 * V_2 ;
struct V_53 * V_13 = V_144 ;
for ( V_22 = 0 ; V_144 [ V_22 ] . V_145 ; V_22 ++ ) {
if ( V_27 -> V_146 == V_144 [ V_22 ] . V_145 ) {
V_13 = & ( V_144 [ V_22 ] ) ;
break;
}
}
V_12 -> V_14 |= V_147 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_148 ) ;
if ( ! V_2 ) {
F_37 ( & V_12 -> V_7 , L_2 ) ;
return - V_149 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_25 = - 1 ;
V_2 -> V_31 = - 1 ;
F_38 ( V_12 , V_2 ) ;
V_2 -> V_47 = F_36 ( sizeof( struct V_45 ) , V_148 ) ;
if ( ! V_2 -> V_47 ) {
F_37 ( & V_12 -> V_7 , L_3 ) ;
V_143 = - V_149 ;
goto V_150;
}
if ( V_27 -> V_151 == V_152 && V_27 -> V_153 == V_152 )
V_2 -> V_139 = true ;
V_143 = F_39 ( V_12 ) ;
if ( V_143 != 0 )
goto V_150;
V_143 = F_40 ( V_12 , V_154 ) ;
if ( V_143 )
goto V_150;
V_143 = F_41 ( & V_12 -> V_7 . V_155 , & V_156 ) ;
F_29 ( V_12 ) ;
F_27 ( V_12 ) ;
F_42 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
return 0 ;
V_150:
F_42 ( V_2 -> V_47 ) ;
F_42 ( V_2 ) ;
return V_143 ;
}
static int F_43 ( struct V_11 * V_12 )
{
F_29 ( V_12 ) ;
F_27 ( V_12 ) ;
return 0 ;
}
static int F_44 ( struct V_11 * V_12 )
{
struct V_157 * V_158 ;
struct V_159 * V_160 ;
struct V_161 * V_7 ;
if ( V_12 -> V_162 != V_163 )
return 0 ;
V_158 = F_45 ( V_12 -> V_7 . V_164 ) ;
V_160 = V_158 -> V_165 ;
V_7 = F_46 ( V_12 ) ;
F_47 ( V_7 , F_48 ( V_7 , 0 ) ,
V_166 ,
V_167 | V_168 ,
0 , V_160 -> V_169 . V_170 ,
NULL , 0 , V_171 ) ;
return 0 ;
}
static void F_49 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
F_50 ( & V_12 -> V_7 . V_155 , & V_156 ) ;
F_51 ( V_12 ) ;
F_42 ( V_2 ) ;
F_38 ( V_12 , NULL ) ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_172 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_172 ) ;
}
