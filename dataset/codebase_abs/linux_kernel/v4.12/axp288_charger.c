static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
int V_5 ;
if ( V_3 < V_6 )
V_3 = V_6 ;
else if ( V_3 > V_2 -> V_7 )
V_3 = V_2 -> V_7 ;
V_4 = ( V_3 - V_6 ) / V_8 ;
V_3 = ( V_4 * V_8 ) + V_6 ;
V_4 = V_4 << V_9 ;
V_5 = F_2 ( V_2 -> V_10 ,
V_11 ,
V_12 , V_4 ) ;
if ( V_5 >= 0 )
V_2 -> V_3 = V_3 ;
return V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_4 ;
int V_5 ;
if ( V_13 <= V_14 ) {
V_4 = V_15 ;
V_13 = V_14 ;
} else if ( V_13 <= V_16 ) {
V_4 = V_17 ;
V_13 = V_16 ;
} else if ( V_13 <= V_18 ) {
V_4 = V_19 ;
V_13 = V_18 ;
} else {
V_4 = V_20 ;
V_13 = V_21 ;
}
V_4 = V_4 << V_22 ;
V_5 = F_2 ( V_2 -> V_10 ,
V_11 ,
V_23 , V_4 ) ;
if ( V_5 >= 0 )
V_2 -> V_13 = V_13 ;
return V_5 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
int V_24 )
{
int V_5 ;
unsigned int V_25 ;
T_1 V_4 ;
V_5 = F_5 ( V_2 -> V_10 , V_26 , & V_25 ) ;
if ( V_5 < 0 )
goto V_27;
if ( V_24 <= V_28 ) {
V_4 = V_29 ;
V_24 = V_28 ;
} else if ( V_24 <= V_30 ) {
V_4 = V_31 ;
V_24 = V_30 ;
} else if ( V_24 <= V_32 ) {
V_4 = V_33 ;
V_24 = V_32 ;
} else if ( V_24 <= V_34 ) {
V_4 = V_35 ;
V_24 = V_34 ;
} else if ( V_24 <= V_36 ) {
V_4 = V_37 ;
V_24 = V_36 ;
} else if ( V_24 <= V_38 ) {
V_4 = V_39 ;
V_24 = V_38 ;
} else {
V_4 = V_40 ;
V_24 = V_41 ;
}
V_4 = ( V_25 & ~ V_42 )
| ( V_4 << V_43 ) ;
V_5 = F_6 ( V_2 -> V_10 , V_26 , V_4 ) ;
if ( V_5 >= 0 )
V_2 -> V_24 = V_24 ;
else
F_7 ( & V_2 -> V_44 -> V_45 , L_1 , V_5 ) ;
V_27:
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
bool V_46 )
{
int V_5 ;
if ( V_46 )
V_5 = F_2 ( V_2 -> V_10 , V_47 ,
V_48 , 0 ) ;
else
V_5 = F_2 ( V_2 -> V_10 , V_47 ,
V_48 , V_48 ) ;
if ( V_5 < 0 )
F_7 ( & V_2 -> V_44 -> V_45 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
bool V_46 )
{
int V_5 ;
if ( ( int ) V_46 == V_2 -> V_49 )
return 0 ;
if ( V_46 )
V_5 = F_2 ( V_2 -> V_10 , V_11 ,
V_50 , V_50 ) ;
else
V_5 = F_2 ( V_2 -> V_10 , V_11 ,
V_50 , 0 ) ;
if ( V_5 < 0 )
F_7 ( & V_2 -> V_44 -> V_45 , L_3 , V_5 ) ;
else
V_2 -> V_49 = V_46 ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_5 , V_51 = 0 ;
unsigned int V_25 ;
V_5 = F_5 ( V_2 -> V_10 , V_52 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_25 & V_53 )
V_51 = 1 ;
return V_51 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 , V_54 = 0 ;
unsigned int V_25 ;
V_5 = F_5 ( V_2 -> V_10 , V_52 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_25 & V_55 )
V_54 = 1 ;
return V_54 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_5 , V_56 , V_57 ;
int V_58 = V_59 ;
unsigned int V_25 ;
V_5 = F_5 ( V_2 -> V_10 , V_52 , & V_25 ) ;
if ( ( V_5 < 0 ) || ! ( V_25 & V_53 ) )
goto V_60;
else
V_56 = V_25 ;
V_5 = F_5 ( V_2 -> V_10 , V_61 , & V_25 ) ;
if ( V_5 < 0 )
goto V_60;
else
V_57 = V_25 ;
if ( ! ( V_56 & V_55 ) )
V_58 = V_62 ;
else if ( V_57 & V_63 )
V_58 = V_64 ;
else if ( V_57 & V_65 )
V_58 = V_66 ;
else
V_58 = V_67 ;
V_60:
return V_58 ;
}
static int F_13 ( struct V_68 * V_69 ,
enum V_70 V_71 ,
const union V_72 * V_25 )
{
struct V_1 * V_2 = F_14 ( V_69 ) ;
int V_5 = 0 ;
int V_73 ;
F_15 ( & V_2 -> V_74 ) ;
switch ( V_71 ) {
case V_75 :
V_73 = F_16 ( V_25 -> V_76 , V_2 -> V_7 ) ;
V_73 = F_17 ( V_73 , 1000 ) ;
V_5 = F_1 ( V_2 , V_73 ) ;
if ( V_5 < 0 )
F_18 ( & V_2 -> V_44 -> V_45 , L_4 ) ;
break;
case V_77 :
V_73 = F_16 ( V_25 -> V_76 , V_2 -> V_78 ) ;
V_73 = F_17 ( V_73 , 1000 ) ;
V_5 = F_3 ( V_2 , V_73 ) ;
if ( V_5 < 0 )
F_18 ( & V_2 -> V_44 -> V_45 , L_5 ) ;
break;
default:
V_5 = - V_79 ;
}
F_19 ( & V_2 -> V_74 ) ;
return V_5 ;
}
static int F_20 ( struct V_68 * V_69 ,
enum V_70 V_71 ,
union V_72 * V_25 )
{
struct V_1 * V_2 = F_14 ( V_69 ) ;
int V_5 = 0 ;
F_15 ( & V_2 -> V_74 ) ;
switch ( V_71 ) {
case V_80 :
if ( V_2 -> V_81 . V_82 ) {
V_25 -> V_76 = 0 ;
break;
}
V_5 = F_10 ( V_2 ) ;
if ( V_5 < 0 )
goto V_83;
V_25 -> V_76 = V_5 ;
break;
case V_84 :
if ( V_2 -> V_81 . V_82 ) {
V_25 -> V_76 = 0 ;
break;
}
V_5 = F_11 ( V_2 ) ;
if ( V_5 < 0 )
goto V_83;
V_25 -> V_76 = V_5 ;
break;
case V_85 :
V_25 -> V_76 = F_12 ( V_2 ) ;
break;
case V_75 :
V_25 -> V_76 = V_2 -> V_3 * 1000 ;
break;
case V_86 :
V_25 -> V_76 = V_2 -> V_7 * 1000 ;
break;
case V_77 :
V_25 -> V_76 = V_2 -> V_13 * 1000 ;
break;
case V_87 :
V_25 -> V_76 = V_2 -> V_78 * 1000 ;
break;
case V_88 :
V_25 -> V_76 = V_2 -> V_24 * 1000 ;
break;
default:
V_5 = - V_79 ;
goto V_83;
}
V_83:
F_19 ( & V_2 -> V_74 ) ;
return V_5 ;
}
static int F_21 ( struct V_68 * V_69 ,
enum V_70 V_71 )
{
int V_5 ;
switch ( V_71 ) {
case V_75 :
case V_77 :
V_5 = 1 ;
break;
default:
V_5 = 0 ;
}
return V_5 ;
}
static T_2 F_22 ( int V_89 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
if ( V_2 -> V_89 [ V_90 ] == V_89 )
break;
}
if ( V_90 >= V_91 ) {
F_18 ( & V_2 -> V_44 -> V_45 , L_6 ) ;
return V_92 ;
}
switch ( V_90 ) {
case V_93 :
F_23 ( & V_2 -> V_44 -> V_45 , L_7 ) ;
break;
case V_94 :
F_23 ( & V_2 -> V_44 -> V_45 , L_8 ) ;
break;
case V_95 :
F_23 ( & V_2 -> V_44 -> V_45 , L_9 ) ;
break;
case V_96 :
F_23 ( & V_2 -> V_44 -> V_45 ,
L_10 ) ;
break;
case V_97 :
F_23 ( & V_2 -> V_44 -> V_45 ,
L_11 ) ;
break;
case V_98 :
F_23 ( & V_2 -> V_44 -> V_45 ,
L_12 ) ;
break;
case V_99 :
F_23 ( & V_2 -> V_44 -> V_45 ,
L_13 ) ;
break;
case V_100 :
F_23 ( & V_2 -> V_44 -> V_45 ,
L_14 ) ;
break;
case V_101 :
F_23 ( & V_2 -> V_44 -> V_45 ,
L_15 ) ;
break;
default:
F_18 ( & V_2 -> V_44 -> V_45 , L_16 ) ;
goto V_102;
}
F_24 ( V_2 -> V_103 ) ;
V_102:
return V_104 ;
}
static void F_25 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_26 ( V_106 , struct V_1 , V_107 . V_106 ) ;
int V_5 , V_108 ;
struct V_109 * V_110 = V_2 -> V_107 . V_110 ;
bool V_111 = V_2 -> V_107 . V_112 ;
enum V_113 V_114 = V_2 -> V_107 . V_115 ;
if ( F_27 ( V_110 , V_116 ) > 0 ) {
F_23 ( & V_2 -> V_44 -> V_45 , L_17 ) ;
V_2 -> V_107 . V_112 = true ;
V_2 -> V_107 . V_115 = V_117 ;
} else if ( F_27 ( V_110 , V_118 ) > 0 ) {
F_23 ( & V_2 -> V_44 -> V_45 , L_18 ) ;
V_2 -> V_107 . V_112 = true ;
V_2 -> V_107 . V_115 = V_119 ;
} else if ( F_27 ( V_110 , V_120 ) > 0 ) {
F_23 ( & V_2 -> V_44 -> V_45 , L_19 ) ;
V_2 -> V_107 . V_112 = true ;
V_2 -> V_107 . V_115 = V_121 ;
} else {
if ( V_111 )
F_23 ( & V_2 -> V_44 -> V_45 , L_20 ) ;
V_2 -> V_107 . V_112 = false ;
V_2 -> V_107 . V_115 = V_117 ;
}
if ( V_111 == V_2 -> V_107 . V_112 &&
V_114 == V_2 -> V_107 . V_115 )
return;
F_15 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_107 . V_112 ) {
F_9 ( V_2 , false ) ;
switch ( V_2 -> V_107 . V_115 ) {
case V_117 :
V_108 = V_30 ;
break;
case V_119 :
V_108 = V_34 ;
break;
case V_121 :
V_108 = V_36 ;
break;
default:
V_108 = 0 ;
break;
}
V_5 = F_4 ( V_2 , V_108 ) ;
if ( V_5 == 0 )
F_9 ( V_2 , true ) ;
else
F_7 ( & V_2 -> V_44 -> V_45 ,
L_21 , V_5 ) ;
} else {
F_9 ( V_2 , false ) ;
}
F_19 ( & V_2 -> V_74 ) ;
F_24 ( V_2 -> V_103 ) ;
}
static int F_28 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
struct V_1 * V_2 =
F_26 ( V_123 , struct V_1 , V_107 . V_123 [ 0 ] ) ;
F_29 ( & V_2 -> V_107 . V_106 ) ;
return V_126 ;
}
static int F_30 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
struct V_1 * V_2 =
F_26 ( V_123 , struct V_1 , V_107 . V_123 [ 1 ] ) ;
F_29 ( & V_2 -> V_107 . V_106 ) ;
return V_126 ;
}
static int F_31 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
struct V_1 * V_2 =
F_26 ( V_123 , struct V_1 , V_107 . V_123 [ 2 ] ) ;
F_29 ( & V_2 -> V_107 . V_106 ) ;
return V_126 ;
}
static void F_32 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_26 ( V_106 , struct V_1 , V_81 . V_106 ) ;
struct V_109 * V_110 = V_2 -> V_81 . V_107 ;
int V_5 , V_127 = F_27 ( V_110 , V_128 ) ;
F_23 ( & V_2 -> V_44 -> V_45 , L_22 ,
V_127 ? L_23 : L_24 ) ;
V_2 -> V_81 . V_82 = V_127 ;
V_5 = F_8 ( V_2 , ! V_2 -> V_81 . V_82 ) ;
if ( V_5 < 0 )
F_18 ( & V_2 -> V_44 -> V_45 , L_25 ) ;
}
static int F_33 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
struct V_1 * V_2 =
F_26 ( V_123 , struct V_1 , V_81 . V_129 ) ;
F_29 ( & V_2 -> V_81 . V_106 ) ;
return V_126 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_5 , V_3 , V_13 ;
unsigned int V_25 ;
V_5 = F_6 ( V_2 -> V_10 , V_130 , V_131 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_2 -> V_44 -> V_45 , L_26 ,
V_130 , V_5 ) ;
return V_5 ;
}
V_5 = F_6 ( V_2 -> V_10 , V_132 , V_133 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_2 -> V_44 -> V_45 , L_26 ,
V_132 , V_5 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_10 ,
V_134 ,
V_135 , V_135 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_2 -> V_44 -> V_45 , L_26 ,
V_134 , V_5 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_10 ,
V_11 ,
V_136 , 0 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_2 -> V_44 -> V_45 , L_26 ,
V_11 , V_5 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_10 ,
V_137 ,
V_138 , 0 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_2 -> V_44 -> V_45 , L_26 ,
V_137 , V_5 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 -> V_10 , V_11 , & V_25 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_2 -> V_44 -> V_45 , L_27 ,
V_11 , V_5 ) ;
return V_5 ;
}
V_13 = ( V_25 & V_23 ) >> V_22 ;
switch ( V_13 ) {
case V_15 :
V_2 -> V_13 = V_14 ;
break;
case V_17 :
V_2 -> V_13 = V_16 ;
break;
case V_19 :
V_2 -> V_13 = V_18 ;
break;
case V_20 :
V_2 -> V_13 = V_21 ;
break;
}
V_3 = ( V_5 & V_12 ) >> V_9 ;
V_3 = ( V_3 * V_8 ) + V_6 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_78 = V_2 -> V_13 ;
V_2 -> V_7 = V_2 -> V_3 ;
return 0 ;
}
static int F_35 ( struct V_139 * V_44 )
{
int V_5 , V_90 , V_140 ;
struct V_1 * V_2 ;
struct V_141 * V_45 = & V_44 -> V_45 ;
struct V_142 * V_143 = F_36 ( V_44 -> V_45 . V_144 ) ;
struct V_145 V_146 = {} ;
V_2 = F_37 ( & V_44 -> V_45 , sizeof( * V_2 ) , V_147 ) ;
if ( ! V_2 )
return - V_148 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_10 = V_143 -> V_10 ;
V_2 -> V_149 = V_143 -> V_149 ;
V_2 -> V_107 . V_115 = - 1 ;
V_2 -> V_49 = - 1 ;
V_2 -> V_107 . V_110 = F_38 ( V_150 ) ;
if ( V_2 -> V_107 . V_110 == NULL ) {
F_23 ( & V_44 -> V_45 , L_28 ,
V_150 ) ;
return - V_151 ;
}
if ( F_39 ( V_152 , NULL , - 1 ) ) {
V_2 -> V_81 . V_107 = F_38 ( V_153 ) ;
if ( V_2 -> V_81 . V_107 == NULL ) {
F_23 ( V_45 , L_29 ) ;
return - V_151 ;
}
F_40 ( & V_44 -> V_45 ,
L_30 V_152 L_31 ) ;
}
F_41 ( V_44 , V_2 ) ;
F_42 ( & V_2 -> V_74 ) ;
V_5 = F_34 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_146 . V_154 = V_2 ;
V_2 -> V_103 = F_43 ( V_45 , & V_155 ,
& V_146 ) ;
if ( F_44 ( V_2 -> V_103 ) ) {
V_5 = F_45 ( V_2 -> V_103 ) ;
F_7 ( V_45 , L_32 , V_5 ) ;
return V_5 ;
}
F_46 ( & V_2 -> V_107 . V_106 , F_25 ) ;
V_2 -> V_107 . V_123 [ 0 ] . V_156 = F_28 ;
V_2 -> V_107 . V_123 [ 1 ] . V_156 = F_30 ;
V_2 -> V_107 . V_123 [ 2 ] . V_156 = F_31 ;
for ( V_90 = 0 ; V_90 < F_47 ( V_157 ) ; V_90 ++ ) {
V_5 = F_48 ( V_45 , V_2 -> V_107 . V_110 ,
V_157 [ V_90 ] , & V_2 -> V_107 . V_123 [ V_90 ] ) ;
if ( V_5 ) {
F_7 ( V_45 , L_33 ,
V_157 [ V_90 ] , V_5 ) ;
return V_5 ;
}
}
F_29 ( & V_2 -> V_107 . V_106 ) ;
F_46 ( & V_2 -> V_81 . V_106 , F_32 ) ;
V_2 -> V_81 . V_129 . V_156 = F_33 ;
if ( V_2 -> V_81 . V_107 ) {
V_5 = F_48 ( & V_44 -> V_45 , V_2 -> V_81 . V_107 ,
V_128 , & V_2 -> V_81 . V_129 ) ;
if ( V_5 ) {
F_7 ( V_45 , L_34 ) ;
return V_5 ;
}
F_29 ( & V_2 -> V_81 . V_106 ) ;
}
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
V_140 = F_49 ( V_2 -> V_44 , V_90 ) ;
V_2 -> V_89 [ V_90 ] = F_50 ( V_2 -> V_149 , V_140 ) ;
if ( V_2 -> V_89 [ V_90 ] < 0 ) {
F_18 ( & V_2 -> V_44 -> V_45 ,
L_35 , V_140 ) ;
return V_2 -> V_89 [ V_90 ] ;
}
V_5 = F_51 ( & V_2 -> V_44 -> V_45 , V_2 -> V_89 [ V_90 ] ,
NULL , F_22 ,
V_158 , V_2 -> V_44 -> V_159 , V_2 ) ;
if ( V_5 ) {
F_7 ( & V_44 -> V_45 , L_36 ,
V_2 -> V_89 [ V_90 ] ) ;
return V_5 ;
}
}
return 0 ;
}
