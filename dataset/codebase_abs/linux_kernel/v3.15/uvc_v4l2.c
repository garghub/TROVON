static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
int V_8 ;
V_6 = F_2 ( sizeof *V_6 , V_9 ) ;
if ( V_6 == NULL )
return - V_10 ;
V_6 -> V_11 = V_4 -> V_11 ;
memcpy ( V_6 -> V_12 , V_4 -> V_12 , sizeof V_6 -> V_12 ) ;
memcpy ( V_6 -> V_13 , V_4 -> V_13 , sizeof V_6 -> V_13 ) ;
V_6 -> V_14 = V_4 -> V_14 ;
V_6 -> V_7 = V_4 -> V_7 ;
V_6 -> V_15 = V_4 -> V_15 ;
V_6 -> V_16 = V_4 -> V_16 ;
V_6 -> V_17 = V_4 -> V_17 ;
switch ( V_4 -> V_16 ) {
case V_18 :
case V_19 :
case V_20 :
break;
case V_21 :
if ( V_4 -> V_22 == 0 ||
V_4 -> V_22 > V_23 ) {
V_8 = - V_24 ;
goto V_25;
}
V_7 = V_4 -> V_22 * sizeof( * V_6 -> V_26 ) ;
V_6 -> V_26 = F_3 ( V_7 , V_9 ) ;
if ( V_6 -> V_26 == NULL ) {
V_8 = - V_10 ;
goto V_25;
}
if ( F_4 ( V_6 -> V_26 , V_4 -> V_26 , V_7 ) ) {
V_8 = - V_27 ;
goto V_25;
}
V_6 -> V_22 = V_4 -> V_22 ;
break;
default:
F_5 ( V_28 , L_1
L_2 , V_4 -> V_16 ) ;
V_8 = - V_29 ;
goto V_25;
}
V_8 = F_6 ( V_2 , V_6 ) ;
V_25:
F_7 ( V_6 -> V_26 ) ;
F_7 ( V_6 ) ;
return V_8 ;
}
static T_1 F_8 ( struct V_30 * V_31 , T_1 V_32 )
{
unsigned int V_33 ;
if ( V_31 -> V_34 ) {
T_1 V_35 = - 1 , V_36 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_34 ; ++ V_33 ) {
V_36 = V_32 > V_31 -> V_37 [ V_33 ]
? V_32 - V_31 -> V_37 [ V_33 ]
: V_31 -> V_37 [ V_33 ] - V_32 ;
if ( V_36 > V_35 )
break;
V_35 = V_36 ;
}
V_32 = V_31 -> V_37 [ V_33 - 1 ] ;
} else {
const T_1 V_38 = V_31 -> V_37 [ 0 ] ;
const T_1 V_39 = V_31 -> V_37 [ 1 ] ;
const T_1 V_40 = V_31 -> V_37 [ 2 ] ;
V_32 = V_38 + ( V_32 - V_38 + V_40 / 2 ) / V_40 * V_40 ;
if ( V_32 > V_39 )
V_32 = V_39 ;
}
return V_32 ;
}
static int F_9 ( struct V_41 * V_42 ,
struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * * V_47 , struct V_30 * * V_30 )
{
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
T_2 V_49 , V_50 ;
unsigned int V_51 , V_52 ;
unsigned int V_33 ;
T_1 V_32 ;
int V_8 = 0 ;
T_3 * V_53 ;
if ( V_44 -> type != V_42 -> type )
return - V_24 ;
V_53 = ( T_3 * ) & V_44 -> V_44 . V_54 . V_55 ;
F_5 ( V_56 , L_3 ,
V_44 -> V_44 . V_54 . V_55 ,
V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] , V_53 [ 3 ] ,
V_44 -> V_44 . V_54 . V_57 , V_44 -> V_44 . V_54 . V_58 ) ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; ++ V_33 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
if ( V_48 -> V_53 == V_44 -> V_44 . V_54 . V_55 )
break;
}
if ( V_33 == V_42 -> V_59 ) {
V_48 = V_42 -> V_60 ;
V_44 -> V_44 . V_54 . V_55 = V_48 -> V_53 ;
}
V_49 = V_44 -> V_44 . V_54 . V_57 ;
V_50 = V_44 -> V_44 . V_54 . V_58 ;
V_52 = ( unsigned int ) - 1 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_61 ; ++ V_33 ) {
T_2 V_62 = V_48 -> V_31 [ V_33 ] . V_63 ;
T_2 V_64 = V_48 -> V_31 [ V_33 ] . V_65 ;
V_51 = V_38 ( V_62 , V_49 ) * V_38 ( V_64 , V_50 ) ;
V_51 = V_62 * V_64 + V_49 * V_50 - 2 * V_51 ;
if ( V_51 < V_52 ) {
V_52 = V_51 ;
V_31 = & V_48 -> V_31 [ V_33 ] ;
}
if ( V_52 == 0 )
break;
}
if ( V_31 == NULL ) {
F_5 ( V_56 , L_4 ,
V_44 -> V_44 . V_54 . V_57 , V_44 -> V_44 . V_54 . V_58 ) ;
return - V_24 ;
}
V_32 = V_31 -> V_66 ;
F_5 ( V_56 , L_5
L_6 , V_32 / 10 , V_32 % 10 , 10000000 / V_32 ,
( 100000000 / V_32 ) % 10 ) ;
memset ( V_46 , 0 , sizeof *V_46 ) ;
V_46 -> V_67 = 1 ;
V_46 -> V_68 = V_48 -> V_69 ;
V_46 -> V_70 = V_31 -> V_70 ;
V_46 -> V_37 = F_8 ( V_31 , V_32 ) ;
F_10 ( & V_42 -> V_71 ) ;
if ( V_42 -> V_72 -> V_73 & V_74 )
V_46 -> V_75 =
V_42 -> V_76 . V_75 ;
V_8 = F_11 ( V_42 , V_46 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
goto V_25;
V_44 -> V_44 . V_54 . V_57 = V_31 -> V_63 ;
V_44 -> V_44 . V_54 . V_58 = V_31 -> V_65 ;
V_44 -> V_44 . V_54 . V_77 = V_78 ;
V_44 -> V_44 . V_54 . V_79 = V_48 -> V_80 * V_31 -> V_63 / 8 ;
V_44 -> V_44 . V_54 . V_81 = V_46 -> V_75 ;
V_44 -> V_44 . V_54 . V_82 = V_48 -> V_82 ;
V_44 -> V_44 . V_54 . V_83 = 0 ;
if ( V_47 != NULL )
* V_47 = V_48 ;
if ( V_30 != NULL )
* V_30 = V_31 ;
V_25:
return V_8 ;
}
static int F_13 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_47 * V_48 ;
struct V_30 * V_31 ;
int V_8 = 0 ;
if ( V_44 -> type != V_42 -> type )
return - V_24 ;
F_10 ( & V_42 -> V_71 ) ;
V_48 = V_42 -> V_84 ;
V_31 = V_42 -> V_85 ;
if ( V_48 == NULL || V_31 == NULL ) {
V_8 = - V_24 ;
goto V_25;
}
V_44 -> V_44 . V_54 . V_55 = V_48 -> V_53 ;
V_44 -> V_44 . V_54 . V_57 = V_31 -> V_63 ;
V_44 -> V_44 . V_54 . V_58 = V_31 -> V_65 ;
V_44 -> V_44 . V_54 . V_77 = V_78 ;
V_44 -> V_44 . V_54 . V_79 = V_48 -> V_80 * V_31 -> V_63 / 8 ;
V_44 -> V_44 . V_54 . V_81 = V_42 -> V_76 . V_75 ;
V_44 -> V_44 . V_54 . V_82 = V_48 -> V_82 ;
V_44 -> V_44 . V_54 . V_83 = 0 ;
V_25:
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
static int F_14 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_45 V_46 ;
struct V_47 * V_48 ;
struct V_30 * V_31 ;
int V_8 ;
if ( V_44 -> type != V_42 -> type )
return - V_24 ;
V_8 = F_9 ( V_42 , V_44 , & V_46 , & V_48 , & V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
F_10 ( & V_42 -> V_71 ) ;
if ( F_15 ( & V_42 -> V_86 ) ) {
V_8 = - V_87 ;
goto V_25;
}
V_42 -> V_76 = V_46 ;
V_42 -> V_84 = V_48 ;
V_42 -> V_85 = V_31 ;
V_25:
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_88 * V_89 )
{
T_4 V_90 , V_91 ;
if ( V_89 -> type != V_42 -> type )
return - V_24 ;
F_10 ( & V_42 -> V_71 ) ;
V_90 = V_42 -> V_76 . V_37 ;
F_12 ( & V_42 -> V_71 ) ;
V_91 = 10000000 ;
F_17 ( & V_90 , & V_91 , 8 , 333 ) ;
memset ( V_89 , 0 , sizeof *V_89 ) ;
V_89 -> type = V_42 -> type ;
if ( V_42 -> type == V_92 ) {
V_89 -> V_89 . V_93 . V_94 = V_95 ;
V_89 -> V_89 . V_93 . V_96 = 0 ;
V_89 -> V_89 . V_93 . V_97 . V_90 = V_90 ;
V_89 -> V_89 . V_93 . V_97 . V_91 = V_91 ;
V_89 -> V_89 . V_93 . V_98 = 0 ;
V_89 -> V_89 . V_93 . V_99 = 0 ;
} else {
V_89 -> V_89 . V_100 . V_94 = V_95 ;
V_89 -> V_89 . V_100 . V_101 = 0 ;
V_89 -> V_89 . V_100 . V_97 . V_90 = V_90 ;
V_89 -> V_89 . V_100 . V_97 . V_91 = V_91 ;
}
return 0 ;
}
static int F_18 ( struct V_41 * V_42 ,
struct V_88 * V_89 )
{
struct V_45 V_46 ;
struct V_102 V_97 ;
T_4 V_32 ;
int V_8 ;
if ( V_89 -> type != V_42 -> type )
return - V_24 ;
if ( V_89 -> type == V_92 )
V_97 = V_89 -> V_89 . V_93 . V_97 ;
else
V_97 = V_89 -> V_89 . V_100 . V_97 ;
V_32 = F_19 ( V_97 . V_90 ,
V_97 . V_91 ) ;
F_5 ( V_56 , L_7 ,
V_97 . V_90 , V_97 . V_91 , V_32 ) ;
F_10 ( & V_42 -> V_71 ) ;
if ( F_20 ( & V_42 -> V_86 ) ) {
F_12 ( & V_42 -> V_71 ) ;
return - V_87 ;
}
V_46 = V_42 -> V_76 ;
V_46 . V_37 =
F_8 ( V_42 -> V_85 , V_32 ) ;
V_8 = F_11 ( V_42 , & V_46 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
V_42 -> V_76 = V_46 ;
F_12 ( & V_42 -> V_71 ) ;
V_97 . V_90 = V_46 . V_37 ;
V_97 . V_91 = 10000000 ;
F_17 ( & V_97 . V_90 ,
& V_97 . V_91 , 8 , 333 ) ;
if ( V_89 -> type == V_92 )
V_89 -> V_89 . V_93 . V_97 = V_97 ;
else
V_89 -> V_89 . V_100 . V_97 = V_97 ;
return 0 ;
}
static int F_21 ( struct V_103 * V_104 )
{
if ( V_104 -> V_105 == V_106 )
return 0 ;
if ( F_22 ( & V_104 -> V_42 -> V_107 ) != 1 ) {
F_23 ( & V_104 -> V_42 -> V_107 ) ;
return - V_87 ;
}
V_104 -> V_105 = V_106 ;
return 0 ;
}
static void F_24 ( struct V_103 * V_104 )
{
if ( V_104 -> V_105 == V_106 )
F_23 ( & V_104 -> V_42 -> V_107 ) ;
V_104 -> V_105 = V_108 ;
}
static int F_25 ( struct V_103 * V_104 )
{
return V_104 -> V_105 == V_106 ;
}
static int F_26 ( struct V_109 * V_109 )
{
struct V_41 * V_42 ;
struct V_103 * V_104 ;
int V_8 = 0 ;
F_5 ( V_110 , L_8 ) ;
V_42 = F_27 ( V_109 ) ;
if ( V_42 -> V_72 -> V_105 & V_111 )
return - V_112 ;
V_8 = F_28 ( V_42 -> V_72 -> V_113 ) ;
if ( V_8 < 0 )
return V_8 ;
V_104 = F_2 ( sizeof *V_104 , V_9 ) ;
if ( V_104 == NULL ) {
F_29 ( V_42 -> V_72 -> V_113 ) ;
return - V_10 ;
}
F_10 ( & V_42 -> V_72 -> V_114 ) ;
if ( V_42 -> V_72 -> V_115 == 0 ) {
V_8 = F_30 ( V_42 -> V_72 , V_9 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_42 -> V_72 -> V_114 ) ;
F_29 ( V_42 -> V_72 -> V_113 ) ;
F_7 ( V_104 ) ;
return V_8 ;
}
}
V_42 -> V_72 -> V_115 ++ ;
F_12 ( & V_42 -> V_72 -> V_114 ) ;
F_31 ( & V_104 -> V_116 , V_42 -> V_117 ) ;
F_32 ( & V_104 -> V_116 ) ;
V_104 -> V_2 = V_42 -> V_2 ;
V_104 -> V_42 = V_42 ;
V_104 -> V_105 = V_108 ;
V_109 -> V_118 = V_104 ;
return 0 ;
}
static int F_33 ( struct V_109 * V_109 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_9 ) ;
if ( F_25 ( V_104 ) ) {
F_34 ( V_42 , 0 ) ;
F_35 ( & V_42 -> V_86 ) ;
}
F_24 ( V_104 ) ;
F_36 ( & V_104 -> V_116 ) ;
F_37 ( & V_104 -> V_116 ) ;
F_7 ( V_104 ) ;
V_109 -> V_118 = NULL ;
F_10 ( & V_42 -> V_72 -> V_114 ) ;
if ( -- V_42 -> V_72 -> V_115 == 0 )
F_38 ( V_42 -> V_72 ) ;
F_12 ( & V_42 -> V_72 -> V_114 ) ;
F_29 ( V_42 -> V_72 -> V_113 ) ;
return 0 ;
}
static long F_39 ( struct V_109 * V_109 , unsigned int V_119 , void * V_120 )
{
struct V_121 * V_117 = F_40 ( V_109 ) ;
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_41 * V_42 = V_104 -> V_42 ;
long V_8 = 0 ;
switch ( V_119 ) {
case V_122 :
{
struct V_123 * V_124 = V_120 ;
memset ( V_124 , 0 , sizeof *V_124 ) ;
F_41 ( V_124 -> V_125 , L_10 , sizeof V_124 -> V_125 ) ;
F_41 ( V_124 -> V_126 , V_117 -> V_12 , sizeof V_124 -> V_126 ) ;
F_42 ( V_42 -> V_72 -> V_127 ,
V_124 -> V_128 , sizeof( V_124 -> V_128 ) ) ;
V_124 -> V_129 = V_130 ;
V_124 -> V_131 = V_132 | V_133
| V_2 -> V_134 ;
if ( V_42 -> type == V_92 )
V_124 -> V_135 = V_136
| V_133 ;
else
V_124 -> V_135 = V_137
| V_133 ;
break;
}
case V_138 :
* ( V_139 * ) V_120 = F_43 ( V_117 -> V_140 ) ;
break;
case V_141 :
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_45 ( V_117 -> V_140 , & V_104 -> V_116 . V_140 ,
* ( V_139 * ) V_120 ) ;
case V_142 :
return F_46 ( V_2 , V_120 ) ;
case V_143 :
{
struct V_144 * V_76 = V_120 ;
struct V_145 V_146 ;
memset ( & V_146 , 0 , sizeof V_146 ) ;
V_146 . V_11 = V_76 -> V_11 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_48 ( V_2 , & V_146 ) ;
F_49 ( V_104 ) ;
if ( V_8 >= 0 )
V_76 -> V_147 = V_146 . V_147 ;
break;
}
case V_148 :
{
struct V_144 * V_76 = V_120 ;
struct V_145 V_146 ;
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
memset ( & V_146 , 0 , sizeof V_146 ) ;
V_146 . V_11 = V_76 -> V_11 ;
V_146 . V_147 = V_76 -> V_147 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_50 ( V_2 , & V_146 ) ;
if ( V_8 < 0 ) {
F_49 ( V_104 ) ;
return V_8 ;
}
V_8 = F_51 ( V_104 , & V_146 , 1 ) ;
if ( V_8 == 0 )
V_76 -> V_147 = V_146 . V_147 ;
break;
}
case V_149 :
return F_52 ( V_2 , V_120 ) ;
case V_150 :
{
struct V_151 * V_152 = V_120 ;
struct V_145 * V_76 = V_152 -> V_153 ;
unsigned int V_33 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_152 -> V_154 ; ++ V_76 , ++ V_33 ) {
V_8 = F_48 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_49 ( V_104 ) ;
V_152 -> V_155 = V_33 ;
return V_8 ;
}
}
V_152 -> V_155 = 0 ;
V_8 = F_49 ( V_104 ) ;
break;
}
case V_156 :
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
case V_157 :
{
struct V_151 * V_152 = V_120 ;
struct V_145 * V_76 = V_152 -> V_153 ;
unsigned int V_33 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_152 -> V_154 ; ++ V_76 , ++ V_33 ) {
V_8 = F_50 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_49 ( V_104 ) ;
V_152 -> V_155 = V_119 == V_156
? V_152 -> V_154 : V_33 ;
return V_8 ;
}
}
V_152 -> V_155 = 0 ;
if ( V_119 == V_156 )
V_8 = F_51 ( V_104 ,
V_152 -> V_153 , V_152 -> V_154 ) ;
else
V_8 = F_49 ( V_104 ) ;
break;
}
case V_158 :
{
const struct V_159 * V_14 = V_2 -> V_14 ;
struct V_160 * V_161 = V_120 ;
struct V_159 * V_162 = NULL ;
V_139 V_69 = V_161 -> V_69 ;
int V_163 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_164 ) ) {
if ( V_69 != 0 )
return - V_24 ;
F_53 (iterm, &chain->entities, chain) {
if ( F_54 ( V_162 ) )
break;
}
V_163 = V_162 -> V_11 ;
} else if ( V_69 < V_14 -> V_165 ) {
V_163 = V_14 -> V_166 [ V_69 ] ;
F_53 (iterm, &chain->entities, chain) {
if ( ! F_54 ( V_162 ) )
continue;
if ( V_162 -> V_11 == V_163 )
break;
}
}
if ( V_162 == NULL || V_162 -> V_11 != V_163 )
return - V_24 ;
memset ( V_161 , 0 , sizeof *V_161 ) ;
V_161 -> V_69 = V_69 ;
F_41 ( V_161 -> V_12 , V_162 -> V_12 , sizeof V_161 -> V_12 ) ;
if ( F_55 ( V_162 ) == V_167 )
V_161 -> type = V_168 ;
break;
}
case V_169 :
{
T_5 V_161 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_164 ) ) {
* ( int * ) V_120 = 0 ;
break;
}
V_8 = F_56 ( V_2 -> V_72 , V_170 ,
V_2 -> V_14 -> V_11 , V_2 -> V_72 -> V_171 ,
V_172 , & V_161 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* ( int * ) V_120 = V_161 - 1 ;
break;
}
case V_173 :
{
V_139 V_161 = * ( V_139 * ) V_120 + 1 ;
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_164 ) ) {
if ( V_161 != 1 )
return - V_24 ;
break;
}
if ( V_161 == 0 || V_161 > V_2 -> V_14 -> V_165 )
return - V_24 ;
return F_56 ( V_2 -> V_72 , V_174 ,
V_2 -> V_14 -> V_11 , V_2 -> V_72 -> V_171 ,
V_172 , & V_161 , 1 ) ;
}
case V_175 :
{
struct V_176 * V_44 = V_120 ;
struct V_47 * V_48 ;
enum V_177 type = V_44 -> type ;
T_1 V_69 = V_44 -> V_69 ;
if ( V_44 -> type != V_42 -> type ||
V_44 -> V_69 >= V_42 -> V_59 )
return - V_24 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_69 = V_69 ;
V_44 -> type = type ;
V_48 = & V_42 -> V_48 [ V_44 -> V_69 ] ;
V_44 -> V_178 = 0 ;
if ( V_48 -> V_178 & V_179 )
V_44 -> V_178 |= V_180 ;
F_41 ( V_44 -> V_181 , V_48 -> V_12 ,
sizeof V_44 -> V_181 ) ;
V_44 -> V_181 [ sizeof V_44 -> V_181 - 1 ] = 0 ;
V_44 -> V_55 = V_48 -> V_53 ;
break;
}
case V_182 :
{
struct V_45 V_46 ;
return F_9 ( V_42 , V_120 , & V_46 , NULL , NULL ) ;
}
case V_183 :
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
return F_14 ( V_42 , V_120 ) ;
case V_184 :
return F_13 ( V_42 , V_120 ) ;
case V_185 :
{
struct V_186 * V_187 = V_120 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 ==
V_187 -> V_188 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
if ( V_187 -> V_69 >= V_48 -> V_61 )
return - V_24 ;
V_31 = & V_48 -> V_31 [ V_187 -> V_69 ] ;
V_187 -> type = V_189 ;
V_187 -> V_190 . V_57 = V_31 -> V_63 ;
V_187 -> V_190 . V_58 = V_31 -> V_65 ;
break;
}
case V_191 :
{
struct V_192 * V_193 = V_120 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 ==
V_193 -> V_188 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_61 ; V_33 ++ ) {
if ( V_48 -> V_31 [ V_33 ] . V_63 == V_193 -> V_57 &&
V_48 -> V_31 [ V_33 ] . V_65 == V_193 -> V_58 ) {
V_31 = & V_48 -> V_31 [ V_33 ] ;
break;
}
}
if ( V_31 == NULL )
return - V_24 ;
if ( V_31 -> V_34 ) {
if ( V_193 -> V_69 >= V_31 -> V_34 )
return - V_24 ;
V_193 -> type = V_194 ;
V_193 -> V_190 . V_90 =
V_31 -> V_37 [ V_193 -> V_69 ] ;
V_193 -> V_190 . V_91 = 10000000 ;
F_17 ( & V_193 -> V_190 . V_90 ,
& V_193 -> V_190 . V_91 , 8 , 333 ) ;
} else {
V_193 -> type = V_195 ;
V_193 -> V_196 . V_38 . V_90 =
V_31 -> V_37 [ 0 ] ;
V_193 -> V_196 . V_38 . V_91 = 10000000 ;
V_193 -> V_196 . V_39 . V_90 =
V_31 -> V_37 [ 1 ] ;
V_193 -> V_196 . V_39 . V_91 = 10000000 ;
V_193 -> V_196 . V_40 . V_90 =
V_31 -> V_37 [ 2 ] ;
V_193 -> V_196 . V_40 . V_91 = 10000000 ;
F_17 ( & V_193 -> V_196 . V_38 . V_90 ,
& V_193 -> V_196 . V_38 . V_91 , 8 , 333 ) ;
F_17 ( & V_193 -> V_196 . V_39 . V_90 ,
& V_193 -> V_196 . V_39 . V_91 , 8 , 333 ) ;
F_17 ( & V_193 -> V_196 . V_40 . V_90 ,
& V_193 -> V_196 . V_40 . V_91 , 8 , 333 ) ;
}
break;
}
case V_197 :
return F_16 ( V_42 , V_120 ) ;
case V_198 :
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
return F_18 ( V_42 , V_120 ) ;
case V_199 :
{
struct V_200 * V_201 = V_120 ;
if ( V_201 -> type != V_42 -> type )
return - V_24 ;
V_201 -> V_202 . V_203 = 0 ;
V_201 -> V_202 . V_204 = 0 ;
F_10 ( & V_42 -> V_71 ) ;
V_201 -> V_202 . V_57 = V_42 -> V_85 -> V_63 ;
V_201 -> V_202 . V_58 = V_42 -> V_85 -> V_65 ;
F_12 ( & V_42 -> V_71 ) ;
V_201 -> V_205 = V_201 -> V_202 ;
V_201 -> V_206 . V_90 = 1 ;
V_201 -> V_206 . V_91 = 1 ;
break;
}
case V_207 :
case V_208 :
return - V_29 ;
case V_209 :
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_57 ( & V_42 -> V_86 , V_120 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_24 ( V_104 ) ;
V_8 = 0 ;
break;
case V_210 :
{
struct V_211 * V_212 = V_120 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_58 ( & V_42 -> V_86 , V_212 ) ;
}
case V_213 :
{
struct V_214 * V_215 = V_120 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_59 ( & V_42 -> V_86 , V_215 ) ;
}
case V_216 :
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_60 ( & V_42 -> V_86 , V_120 ) ;
case V_217 :
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_61 ( & V_42 -> V_86 , V_120 ,
V_109 -> V_218 & V_219 ) ;
case V_220 :
{
int * type = V_120 ;
if ( * type != V_42 -> type )
return - V_24 ;
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_34 ( V_42 , 1 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
return V_8 ;
break;
}
case V_221 :
{
int * type = V_120 ;
if ( * type != V_42 -> type )
return - V_24 ;
V_8 = F_44 ( V_117 -> V_140 , V_104 -> V_116 . V_140 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_34 ( V_42 , 0 ) ;
}
case V_222 :
{
struct V_223 * V_224 = V_120 ;
switch ( V_224 -> type ) {
case V_225 :
return F_62 ( & V_104 -> V_116 , V_224 , 0 ,
& V_226 ) ;
default:
return - V_24 ;
}
}
case V_227 :
return F_63 ( & V_104 -> V_116 , V_120 ) ;
case V_228 :
return F_64 ( & V_104 -> V_116 , V_120 ,
V_109 -> V_218 & V_219 ) ;
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
F_5 ( V_237 , L_11 , V_119 ) ;
return - V_29 ;
case V_238 :
return F_1 ( V_2 , V_120 ) ;
case V_239 :
return F_65 ( V_2 , V_120 ) ;
default:
F_5 ( V_237 , L_12 , V_119 ) ;
return - V_29 ;
}
return V_8 ;
}
static long F_66 ( struct V_109 * V_109 ,
unsigned int V_119 , unsigned long V_120 )
{
if ( V_240 & V_237 ) {
F_67 ( V_241 , L_13 ) ;
F_68 ( NULL , V_119 ) ;
F_69 ( L_14 ) ;
}
return F_70 ( V_109 , V_119 , V_120 , F_39 ) ;
}
static int F_71 ( struct V_3 * V_242 ,
const struct V_243 T_6 * V_244 )
{
struct V_245 T_6 * V_246 ;
struct V_245 T_6 * V_247 ;
T_7 V_248 ;
if ( ! F_72 ( V_249 , V_244 , sizeof( * V_244 ) ) ||
F_73 ( V_242 , V_244 , F_74 ( F_75 ( * V_244 ) , V_26 ) ) ||
F_76 ( V_242 -> V_22 , & V_244 -> V_22 ) )
return - V_27 ;
memset ( V_242 -> V_250 , 0 , sizeof( V_242 -> V_250 ) ) ;
if ( V_242 -> V_22 == 0 ) {
V_242 -> V_26 = NULL ;
return 0 ;
}
if ( F_76 ( V_248 , & V_244 -> V_26 ) )
return - V_27 ;
V_246 = F_77 ( V_248 ) ;
if ( ! F_72 ( V_249 , V_246 , V_242 -> V_22 * sizeof( * V_246 ) ) )
return - V_27 ;
V_247 = F_78 ( V_242 -> V_22 * sizeof( * V_247 ) ) ;
if ( V_247 == NULL )
return - V_27 ;
V_242 -> V_26 = V_247 ;
if ( F_79 ( V_247 , V_246 , V_242 -> V_22 * sizeof( * V_246 ) ) )
return - V_27 ;
return 0 ;
}
static int F_80 ( const struct V_3 * V_242 ,
struct V_243 T_6 * V_244 )
{
struct V_245 T_6 * V_246 ;
struct V_245 T_6 * V_247 = V_242 -> V_26 ;
T_7 V_248 ;
if ( ! F_72 ( V_251 , V_244 , sizeof( * V_244 ) ) ||
F_81 ( V_244 , V_242 , F_74 ( F_75 ( * V_244 ) , V_26 ) ) ||
F_82 ( V_242 -> V_22 , & V_244 -> V_22 ) )
return - V_27 ;
if ( F_83 ( V_244 -> V_250 , sizeof( V_244 -> V_250 ) ) )
return - V_27 ;
if ( V_242 -> V_22 == 0 )
return 0 ;
if ( F_84 ( V_248 , & V_244 -> V_26 ) )
return - V_27 ;
V_246 = F_77 ( V_248 ) ;
if ( F_79 ( V_246 , V_247 , V_242 -> V_22 * sizeof( * V_246 ) ) )
return - V_27 ;
return 0 ;
}
static int F_85 ( struct V_252 * V_242 ,
const struct V_253 T_6 * V_244 )
{
T_5 T_6 * V_254 ;
T_5 T_6 * V_255 ;
T_7 V_248 ;
if ( ! F_72 ( V_249 , V_244 , sizeof( * V_244 ) ) ||
F_73 ( V_242 , V_244 , F_74 ( F_75 ( * V_244 ) , V_256 ) ) )
return - V_27 ;
if ( V_242 -> V_7 == 0 ) {
V_242 -> V_256 = NULL ;
return 0 ;
}
if ( F_76 ( V_248 , & V_244 -> V_256 ) )
return - V_27 ;
V_254 = F_77 ( V_248 ) ;
if ( ! F_72 ( V_249 , V_254 , V_242 -> V_7 ) )
return - V_27 ;
V_255 = F_78 ( V_242 -> V_7 ) ;
if ( V_255 == NULL )
return - V_27 ;
V_242 -> V_256 = V_255 ;
if ( F_79 ( V_255 , V_254 , V_242 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static int F_86 ( const struct V_252 * V_242 ,
struct V_253 T_6 * V_244 )
{
T_5 T_6 * V_254 ;
T_5 T_6 * V_255 = V_242 -> V_256 ;
T_7 V_248 ;
if ( ! F_72 ( V_251 , V_244 , sizeof( * V_244 ) ) ||
F_81 ( V_244 , V_242 , F_74 ( F_75 ( * V_244 ) , V_256 ) ) )
return - V_27 ;
if ( V_242 -> V_7 == 0 )
return 0 ;
if ( F_84 ( V_248 , & V_244 -> V_256 ) )
return - V_27 ;
V_254 = F_77 ( V_248 ) ;
if ( ! F_72 ( V_249 , V_254 , V_242 -> V_7 ) )
return - V_27 ;
if ( F_79 ( V_254 , V_255 , V_242 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static long F_87 ( struct V_109 * V_109 ,
unsigned int V_119 , unsigned long V_120 )
{
union {
struct V_3 V_4 ;
struct V_252 V_257 ;
} V_258 ;
void T_6 * V_244 = F_77 ( V_120 ) ;
T_8 V_259 ;
long V_8 ;
switch ( V_119 ) {
case V_260 :
V_119 = V_238 ;
V_8 = F_71 ( & V_258 . V_4 , V_244 ) ;
break;
case V_261 :
V_119 = V_239 ;
V_8 = F_85 ( & V_258 . V_257 , V_244 ) ;
break;
default:
return - V_262 ;
}
V_259 = F_88 () ;
F_89 ( V_263 ) ;
V_8 = F_66 ( V_109 , V_119 , ( unsigned long ) & V_258 ) ;
F_89 ( V_259 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_119 ) {
case V_238 :
V_8 = F_80 ( & V_258 . V_4 , V_244 ) ;
break;
case V_239 :
V_8 = F_86 ( & V_258 . V_257 , V_244 ) ;
break;
}
return V_8 ;
}
static T_9 F_90 ( struct V_109 * V_109 , char T_6 * V_256 ,
T_10 V_154 , T_11 * V_264 )
{
F_5 ( V_110 , L_15 ) ;
return - V_24 ;
}
static int F_91 ( struct V_109 * V_109 , struct V_265 * V_266 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_16 ) ;
return F_92 ( & V_42 -> V_86 , V_266 ) ;
}
static unsigned int F_93 ( struct V_109 * V_109 , T_12 * V_267 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_17 ) ;
return F_94 ( & V_42 -> V_86 , V_109 , V_267 ) ;
}
static unsigned long F_95 ( struct V_109 * V_109 ,
unsigned long V_268 , unsigned long V_269 , unsigned long V_270 ,
unsigned long V_178 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_18 ) ;
return F_96 ( & V_42 -> V_86 , V_270 ) ;
}
