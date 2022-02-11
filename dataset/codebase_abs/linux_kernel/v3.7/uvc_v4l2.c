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
if ( V_48 == NULL || V_48 -> V_53 != V_44 -> V_44 . V_54 . V_55 ) {
F_5 ( V_56 , L_4 ,
V_44 -> V_44 . V_54 . V_55 ) ;
return - V_24 ;
}
V_49 = V_44 -> V_44 . V_54 . V_57 ;
V_50 = V_44 -> V_44 . V_54 . V_58 ;
V_52 = ( unsigned int ) - 1 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_60 ; ++ V_33 ) {
T_2 V_61 = V_48 -> V_31 [ V_33 ] . V_62 ;
T_2 V_63 = V_48 -> V_31 [ V_33 ] . V_64 ;
V_51 = V_38 ( V_61 , V_49 ) * V_38 ( V_63 , V_50 ) ;
V_51 = V_61 * V_63 + V_49 * V_50 - 2 * V_51 ;
if ( V_51 < V_52 ) {
V_52 = V_51 ;
V_31 = & V_48 -> V_31 [ V_33 ] ;
}
if ( V_52 == 0 )
break;
}
if ( V_31 == NULL ) {
F_5 ( V_56 , L_5 ,
V_44 -> V_44 . V_54 . V_57 , V_44 -> V_44 . V_54 . V_58 ) ;
return - V_24 ;
}
V_32 = V_31 -> V_65 ;
F_5 ( V_56 , L_6
L_7 , V_32 / 10 , V_32 % 10 , 10000000 / V_32 ,
( 100000000 / V_32 ) % 10 ) ;
memset ( V_46 , 0 , sizeof *V_46 ) ;
V_46 -> V_66 = 1 ;
V_46 -> V_67 = V_48 -> V_68 ;
V_46 -> V_69 = V_31 -> V_69 ;
V_46 -> V_37 = F_8 ( V_31 , V_32 ) ;
F_10 ( & V_42 -> V_70 ) ;
if ( V_42 -> V_71 -> V_72 & V_73 )
V_46 -> V_74 =
V_42 -> V_75 . V_74 ;
V_8 = F_11 ( V_42 , V_46 ) ;
F_12 ( & V_42 -> V_70 ) ;
if ( V_8 < 0 )
goto V_25;
V_44 -> V_44 . V_54 . V_57 = V_31 -> V_62 ;
V_44 -> V_44 . V_54 . V_58 = V_31 -> V_64 ;
V_44 -> V_44 . V_54 . V_76 = V_77 ;
V_44 -> V_44 . V_54 . V_78 = V_48 -> V_79 * V_31 -> V_62 / 8 ;
V_44 -> V_44 . V_54 . V_80 = V_46 -> V_74 ;
V_44 -> V_44 . V_54 . V_81 = V_48 -> V_81 ;
V_44 -> V_44 . V_54 . V_82 = 0 ;
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
F_10 ( & V_42 -> V_70 ) ;
V_48 = V_42 -> V_83 ;
V_31 = V_42 -> V_84 ;
if ( V_48 == NULL || V_31 == NULL ) {
V_8 = - V_24 ;
goto V_25;
}
V_44 -> V_44 . V_54 . V_55 = V_48 -> V_53 ;
V_44 -> V_44 . V_54 . V_57 = V_31 -> V_62 ;
V_44 -> V_44 . V_54 . V_58 = V_31 -> V_64 ;
V_44 -> V_44 . V_54 . V_76 = V_77 ;
V_44 -> V_44 . V_54 . V_78 = V_48 -> V_79 * V_31 -> V_62 / 8 ;
V_44 -> V_44 . V_54 . V_80 = V_42 -> V_75 . V_74 ;
V_44 -> V_44 . V_54 . V_81 = V_48 -> V_81 ;
V_44 -> V_44 . V_54 . V_82 = 0 ;
V_25:
F_12 ( & V_42 -> V_70 ) ;
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
F_10 ( & V_42 -> V_70 ) ;
if ( F_15 ( & V_42 -> V_85 ) ) {
V_8 = - V_86 ;
goto V_25;
}
memcpy ( & V_42 -> V_75 , & V_46 , sizeof V_46 ) ;
V_42 -> V_83 = V_48 ;
V_42 -> V_84 = V_31 ;
V_25:
F_12 ( & V_42 -> V_70 ) ;
return V_8 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_87 * V_88 )
{
T_4 V_89 , V_90 ;
if ( V_88 -> type != V_42 -> type )
return - V_24 ;
F_10 ( & V_42 -> V_70 ) ;
V_89 = V_42 -> V_75 . V_37 ;
F_12 ( & V_42 -> V_70 ) ;
V_90 = 10000000 ;
F_17 ( & V_89 , & V_90 , 8 , 333 ) ;
memset ( V_88 , 0 , sizeof *V_88 ) ;
V_88 -> type = V_42 -> type ;
if ( V_42 -> type == V_91 ) {
V_88 -> V_88 . V_92 . V_93 = V_94 ;
V_88 -> V_88 . V_92 . V_95 = 0 ;
V_88 -> V_88 . V_92 . V_96 . V_89 = V_89 ;
V_88 -> V_88 . V_92 . V_96 . V_90 = V_90 ;
V_88 -> V_88 . V_92 . V_97 = 0 ;
V_88 -> V_88 . V_92 . V_98 = 0 ;
} else {
V_88 -> V_88 . V_99 . V_93 = V_94 ;
V_88 -> V_88 . V_99 . V_100 = 0 ;
V_88 -> V_88 . V_99 . V_96 . V_89 = V_89 ;
V_88 -> V_88 . V_99 . V_96 . V_90 = V_90 ;
}
return 0 ;
}
static int F_18 ( struct V_41 * V_42 ,
struct V_87 * V_88 )
{
struct V_45 V_46 ;
struct V_101 V_96 ;
T_4 V_32 ;
int V_8 ;
if ( V_88 -> type != V_42 -> type )
return - V_24 ;
if ( V_88 -> type == V_91 )
V_96 = V_88 -> V_88 . V_92 . V_96 ;
else
V_96 = V_88 -> V_88 . V_99 . V_96 ;
V_32 = F_19 ( V_96 . V_89 ,
V_96 . V_90 ) ;
F_5 ( V_56 , L_8 ,
V_96 . V_89 , V_96 . V_90 , V_32 ) ;
F_10 ( & V_42 -> V_70 ) ;
if ( F_20 ( & V_42 -> V_85 ) ) {
F_12 ( & V_42 -> V_70 ) ;
return - V_86 ;
}
memcpy ( & V_46 , & V_42 -> V_75 , sizeof V_46 ) ;
V_46 . V_37 =
F_8 ( V_42 -> V_84 , V_32 ) ;
V_8 = F_11 ( V_42 , & V_46 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_42 -> V_70 ) ;
return V_8 ;
}
memcpy ( & V_42 -> V_75 , & V_46 , sizeof V_46 ) ;
F_12 ( & V_42 -> V_70 ) ;
V_96 . V_89 = V_46 . V_37 ;
V_96 . V_90 = 10000000 ;
F_17 ( & V_96 . V_89 ,
& V_96 . V_90 , 8 , 333 ) ;
if ( V_88 -> type == V_91 )
V_88 -> V_88 . V_92 . V_96 = V_96 ;
else
V_88 -> V_88 . V_99 . V_96 = V_96 ;
return 0 ;
}
static int F_21 ( struct V_102 * V_103 )
{
if ( V_103 -> V_104 == V_105 )
return 0 ;
if ( F_22 ( & V_103 -> V_42 -> V_106 ) != 1 ) {
F_23 ( & V_103 -> V_42 -> V_106 ) ;
return - V_86 ;
}
V_103 -> V_104 = V_105 ;
return 0 ;
}
static void F_24 ( struct V_102 * V_103 )
{
if ( V_103 -> V_104 == V_105 )
F_23 ( & V_103 -> V_42 -> V_106 ) ;
V_103 -> V_104 = V_107 ;
}
static int F_25 ( struct V_102 * V_103 )
{
return V_103 -> V_104 == V_105 ;
}
static int F_26 ( struct V_108 * V_108 )
{
struct V_41 * V_42 ;
struct V_102 * V_103 ;
int V_8 = 0 ;
F_5 ( V_109 , L_9 ) ;
V_42 = F_27 ( V_108 ) ;
if ( V_42 -> V_71 -> V_104 & V_110 )
return - V_111 ;
V_8 = F_28 ( V_42 -> V_71 -> V_112 ) ;
if ( V_8 < 0 )
return V_8 ;
V_103 = F_2 ( sizeof *V_103 , V_9 ) ;
if ( V_103 == NULL ) {
F_29 ( V_42 -> V_71 -> V_112 ) ;
return - V_10 ;
}
if ( F_22 ( & V_42 -> V_71 -> V_113 ) == 1 ) {
V_8 = F_30 ( V_42 -> V_71 ) ;
if ( V_8 < 0 ) {
F_29 ( V_42 -> V_71 -> V_112 ) ;
F_23 ( & V_42 -> V_71 -> V_113 ) ;
F_7 ( V_103 ) ;
return V_8 ;
}
}
F_31 ( & V_103 -> V_114 , V_42 -> V_115 ) ;
F_32 ( & V_103 -> V_114 ) ;
V_103 -> V_2 = V_42 -> V_2 ;
V_103 -> V_42 = V_42 ;
V_103 -> V_104 = V_107 ;
V_108 -> V_116 = V_103 ;
return 0 ;
}
static int F_33 ( struct V_108 * V_108 )
{
struct V_102 * V_103 = V_108 -> V_116 ;
struct V_41 * V_42 = V_103 -> V_42 ;
F_5 ( V_109 , L_10 ) ;
if ( F_25 ( V_103 ) ) {
F_34 ( V_42 , 0 ) ;
F_35 ( & V_42 -> V_85 ) ;
}
F_24 ( V_103 ) ;
F_36 ( & V_103 -> V_114 ) ;
F_37 ( & V_103 -> V_114 ) ;
F_7 ( V_103 ) ;
V_108 -> V_116 = NULL ;
if ( F_38 ( & V_42 -> V_71 -> V_113 ) == 0 )
F_39 ( V_42 -> V_71 ) ;
F_29 ( V_42 -> V_71 -> V_112 ) ;
return 0 ;
}
static long F_40 ( struct V_108 * V_108 , unsigned int V_117 , void * V_118 )
{
struct V_119 * V_115 = F_41 ( V_108 ) ;
struct V_102 * V_103 = V_108 -> V_116 ;
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_41 * V_42 = V_103 -> V_42 ;
long V_8 = 0 ;
switch ( V_117 ) {
case V_120 :
{
struct V_121 * V_122 = V_118 ;
memset ( V_122 , 0 , sizeof *V_122 ) ;
F_42 ( V_122 -> V_123 , L_11 , sizeof V_122 -> V_123 ) ;
F_42 ( V_122 -> V_124 , V_115 -> V_12 , sizeof V_122 -> V_124 ) ;
F_43 ( V_42 -> V_71 -> V_125 ,
V_122 -> V_126 , sizeof( V_122 -> V_126 ) ) ;
V_122 -> V_127 = V_128 ;
if ( V_42 -> type == V_91 )
V_122 -> V_129 = V_130
| V_131 ;
else
V_122 -> V_129 = V_132
| V_131 ;
break;
}
case V_133 :
return F_44 ( V_2 , V_118 ) ;
case V_134 :
{
struct V_135 * V_75 = V_118 ;
struct V_136 V_137 ;
memset ( & V_137 , 0 , sizeof V_137 ) ;
V_137 . V_11 = V_75 -> V_11 ;
V_8 = F_45 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_46 ( V_2 , & V_137 ) ;
F_47 ( V_103 ) ;
if ( V_8 >= 0 )
V_75 -> V_138 = V_137 . V_138 ;
break;
}
case V_139 :
{
struct V_135 * V_75 = V_118 ;
struct V_136 V_137 ;
memset ( & V_137 , 0 , sizeof V_137 ) ;
V_137 . V_11 = V_75 -> V_11 ;
V_137 . V_138 = V_75 -> V_138 ;
V_8 = F_45 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_48 ( V_2 , & V_137 ) ;
if ( V_8 < 0 ) {
F_47 ( V_103 ) ;
return V_8 ;
}
V_8 = F_49 ( V_103 , & V_137 , 1 ) ;
if ( V_8 == 0 )
V_75 -> V_138 = V_137 . V_138 ;
break;
}
case V_140 :
return F_50 ( V_2 , V_118 ) ;
case V_141 :
{
struct V_142 * V_143 = V_118 ;
struct V_136 * V_75 = V_143 -> V_144 ;
unsigned int V_33 ;
V_8 = F_45 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_143 -> V_145 ; ++ V_75 , ++ V_33 ) {
V_8 = F_46 ( V_2 , V_75 ) ;
if ( V_8 < 0 ) {
F_47 ( V_103 ) ;
V_143 -> V_146 = V_33 ;
return V_8 ;
}
}
V_143 -> V_146 = 0 ;
V_8 = F_47 ( V_103 ) ;
break;
}
case V_147 :
case V_148 :
{
struct V_142 * V_143 = V_118 ;
struct V_136 * V_75 = V_143 -> V_144 ;
unsigned int V_33 ;
V_8 = F_45 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_143 -> V_145 ; ++ V_75 , ++ V_33 ) {
V_8 = F_48 ( V_2 , V_75 ) ;
if ( V_8 < 0 ) {
F_47 ( V_103 ) ;
V_143 -> V_146 = V_33 ;
return V_8 ;
}
}
V_143 -> V_146 = 0 ;
if ( V_117 == V_147 )
V_8 = F_49 ( V_103 ,
V_143 -> V_144 , V_143 -> V_145 ) ;
else
V_8 = F_47 ( V_103 ) ;
break;
}
case V_149 :
{
const struct V_150 * V_14 = V_2 -> V_14 ;
struct V_151 * V_152 = V_118 ;
struct V_150 * V_153 = NULL ;
T_5 V_68 = V_152 -> V_68 ;
int V_154 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_71 -> V_72 & V_155 ) ) {
if ( V_68 != 0 )
return - V_24 ;
F_51 (iterm, &chain->entities, chain) {
if ( F_52 ( V_153 ) )
break;
}
V_154 = V_153 -> V_11 ;
} else if ( V_68 < V_14 -> V_156 ) {
V_154 = V_14 -> V_157 [ V_68 ] ;
F_51 (iterm, &chain->entities, chain) {
if ( ! F_52 ( V_153 ) )
continue;
if ( V_153 -> V_11 == V_154 )
break;
}
}
if ( V_153 == NULL || V_153 -> V_11 != V_154 )
return - V_24 ;
memset ( V_152 , 0 , sizeof *V_152 ) ;
V_152 -> V_68 = V_68 ;
F_42 ( V_152 -> V_12 , V_153 -> V_12 , sizeof V_152 -> V_12 ) ;
if ( F_53 ( V_153 ) == V_158 )
V_152 -> type = V_159 ;
break;
}
case V_160 :
{
T_6 V_152 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_71 -> V_72 & V_155 ) ) {
* ( int * ) V_118 = 0 ;
break;
}
V_8 = F_54 ( V_2 -> V_71 , V_161 ,
V_2 -> V_14 -> V_11 , V_2 -> V_71 -> V_162 ,
V_163 , & V_152 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* ( int * ) V_118 = V_152 - 1 ;
break;
}
case V_164 :
{
T_5 V_152 = * ( T_5 * ) V_118 + 1 ;
if ( ( V_8 = F_21 ( V_103 ) ) < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_71 -> V_72 & V_155 ) ) {
if ( V_152 != 1 )
return - V_24 ;
break;
}
if ( V_152 == 0 || V_152 > V_2 -> V_14 -> V_156 )
return - V_24 ;
return F_54 ( V_2 -> V_71 , V_165 ,
V_2 -> V_14 -> V_11 , V_2 -> V_71 -> V_162 ,
V_163 , & V_152 , 1 ) ;
}
case V_166 :
{
struct V_167 * V_44 = V_118 ;
struct V_47 * V_48 ;
enum V_168 type = V_44 -> type ;
T_1 V_68 = V_44 -> V_68 ;
if ( V_44 -> type != V_42 -> type ||
V_44 -> V_68 >= V_42 -> V_59 )
return - V_24 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_68 = V_68 ;
V_44 -> type = type ;
V_48 = & V_42 -> V_48 [ V_44 -> V_68 ] ;
V_44 -> V_169 = 0 ;
if ( V_48 -> V_169 & V_170 )
V_44 -> V_169 |= V_171 ;
F_42 ( V_44 -> V_172 , V_48 -> V_12 ,
sizeof V_44 -> V_172 ) ;
V_44 -> V_172 [ sizeof V_44 -> V_172 - 1 ] = 0 ;
V_44 -> V_55 = V_48 -> V_53 ;
break;
}
case V_173 :
{
struct V_45 V_46 ;
return F_9 ( V_42 , V_118 , & V_46 , NULL , NULL ) ;
}
case V_174 :
if ( ( V_8 = F_21 ( V_103 ) ) < 0 )
return V_8 ;
return F_14 ( V_42 , V_118 ) ;
case V_175 :
return F_13 ( V_42 , V_118 ) ;
case V_176 :
{
struct V_177 * V_178 = V_118 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 ==
V_178 -> V_179 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
if ( V_178 -> V_68 >= V_48 -> V_60 )
return - V_24 ;
V_31 = & V_48 -> V_31 [ V_178 -> V_68 ] ;
V_178 -> type = V_180 ;
V_178 -> V_181 . V_57 = V_31 -> V_62 ;
V_178 -> V_181 . V_58 = V_31 -> V_64 ;
break;
}
case V_182 :
{
struct V_183 * V_184 = V_118 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 ==
V_184 -> V_179 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_60 ; V_33 ++ ) {
if ( V_48 -> V_31 [ V_33 ] . V_62 == V_184 -> V_57 &&
V_48 -> V_31 [ V_33 ] . V_64 == V_184 -> V_58 ) {
V_31 = & V_48 -> V_31 [ V_33 ] ;
break;
}
}
if ( V_31 == NULL )
return - V_24 ;
if ( V_31 -> V_34 ) {
if ( V_184 -> V_68 >= V_31 -> V_34 )
return - V_24 ;
V_184 -> type = V_185 ;
V_184 -> V_181 . V_89 =
V_31 -> V_37 [ V_184 -> V_68 ] ;
V_184 -> V_181 . V_90 = 10000000 ;
F_17 ( & V_184 -> V_181 . V_89 ,
& V_184 -> V_181 . V_90 , 8 , 333 ) ;
} else {
V_184 -> type = V_186 ;
V_184 -> V_187 . V_38 . V_89 =
V_31 -> V_37 [ 0 ] ;
V_184 -> V_187 . V_38 . V_90 = 10000000 ;
V_184 -> V_187 . V_39 . V_89 =
V_31 -> V_37 [ 1 ] ;
V_184 -> V_187 . V_39 . V_90 = 10000000 ;
V_184 -> V_187 . V_40 . V_89 =
V_31 -> V_37 [ 2 ] ;
V_184 -> V_187 . V_40 . V_90 = 10000000 ;
F_17 ( & V_184 -> V_187 . V_38 . V_89 ,
& V_184 -> V_187 . V_38 . V_90 , 8 , 333 ) ;
F_17 ( & V_184 -> V_187 . V_39 . V_89 ,
& V_184 -> V_187 . V_39 . V_90 , 8 , 333 ) ;
F_17 ( & V_184 -> V_187 . V_40 . V_89 ,
& V_184 -> V_187 . V_40 . V_90 , 8 , 333 ) ;
}
break;
}
case V_188 :
return F_16 ( V_42 , V_118 ) ;
case V_189 :
if ( ( V_8 = F_21 ( V_103 ) ) < 0 )
return V_8 ;
return F_18 ( V_42 , V_118 ) ;
case V_190 :
{
struct V_191 * V_192 = V_118 ;
if ( V_192 -> type != V_42 -> type )
return - V_24 ;
V_192 -> V_193 . V_194 = 0 ;
V_192 -> V_193 . V_195 = 0 ;
F_10 ( & V_42 -> V_70 ) ;
V_192 -> V_193 . V_57 = V_42 -> V_84 -> V_62 ;
V_192 -> V_193 . V_58 = V_42 -> V_84 -> V_64 ;
F_12 ( & V_42 -> V_70 ) ;
V_192 -> V_196 = V_192 -> V_193 ;
V_192 -> V_197 . V_89 = 1 ;
V_192 -> V_197 . V_90 = 1 ;
break;
}
case V_198 :
case V_199 :
return - V_24 ;
case V_200 :
if ( ( V_8 = F_21 ( V_103 ) ) < 0 )
return V_8 ;
F_10 ( & V_42 -> V_70 ) ;
V_8 = F_55 ( & V_42 -> V_85 , V_118 ) ;
F_12 ( & V_42 -> V_70 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_24 ( V_103 ) ;
V_8 = 0 ;
break;
case V_201 :
{
struct V_202 * V_203 = V_118 ;
if ( ! F_25 ( V_103 ) )
return - V_86 ;
return F_56 ( & V_42 -> V_85 , V_203 ) ;
}
case V_204 :
if ( ! F_25 ( V_103 ) )
return - V_86 ;
return F_57 ( & V_42 -> V_85 , V_118 ) ;
case V_205 :
if ( ! F_25 ( V_103 ) )
return - V_86 ;
return F_58 ( & V_42 -> V_85 , V_118 ,
V_108 -> V_206 & V_207 ) ;
case V_208 :
{
int * type = V_118 ;
if ( * type != V_42 -> type )
return - V_24 ;
if ( ! F_25 ( V_103 ) )
return - V_86 ;
F_10 ( & V_42 -> V_70 ) ;
V_8 = F_34 ( V_42 , 1 ) ;
F_12 ( & V_42 -> V_70 ) ;
if ( V_8 < 0 )
return V_8 ;
break;
}
case V_209 :
{
int * type = V_118 ;
if ( * type != V_42 -> type )
return - V_24 ;
if ( ! F_25 ( V_103 ) )
return - V_86 ;
return F_34 ( V_42 , 0 ) ;
}
case V_210 :
{
struct V_211 * V_212 = V_118 ;
switch ( V_212 -> type ) {
case V_213 :
return F_59 ( & V_103 -> V_114 , V_212 , 0 ,
& V_214 ) ;
default:
return - V_24 ;
}
}
case V_215 :
return F_60 ( & V_103 -> V_114 , V_118 ) ;
case V_216 :
return F_61 ( & V_103 -> V_114 , V_118 ,
V_108 -> V_206 & V_207 ) ;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
F_5 ( V_225 , L_12 , V_117 ) ;
return - V_24 ;
case V_226 :
return F_1 ( V_2 , V_118 ) ;
case V_227 :
return F_62 ( V_2 , V_118 ) ;
default:
F_5 ( V_225 , L_13 , V_117 ) ;
return - V_29 ;
}
return V_8 ;
}
static long F_63 ( struct V_108 * V_108 ,
unsigned int V_117 , unsigned long V_118 )
{
if ( V_228 & V_225 ) {
F_64 ( V_229 , L_14 ) ;
F_65 ( NULL , V_117 ) ;
F_66 ( L_15 ) ;
}
return F_67 ( V_108 , V_117 , V_118 , F_40 ) ;
}
static int F_68 ( struct V_3 * V_230 ,
const struct V_231 T_7 * V_232 )
{
struct V_233 T_7 * V_234 ;
struct V_233 T_7 * V_235 ;
T_8 V_236 ;
if ( ! F_69 ( V_237 , V_232 , sizeof( * V_232 ) ) ||
F_70 ( V_230 , V_232 , F_71 ( F_72 ( * V_232 ) , V_26 ) ) ||
F_73 ( V_230 -> V_22 , & V_232 -> V_22 ) )
return - V_27 ;
memset ( V_230 -> V_238 , 0 , sizeof( V_230 -> V_238 ) ) ;
if ( V_230 -> V_22 == 0 ) {
V_230 -> V_26 = NULL ;
return 0 ;
}
if ( F_73 ( V_236 , & V_232 -> V_26 ) )
return - V_27 ;
V_234 = F_74 ( V_236 ) ;
if ( ! F_69 ( V_237 , V_234 , V_230 -> V_22 * sizeof( * V_234 ) ) )
return - V_27 ;
V_235 = F_75 ( V_230 -> V_22 * sizeof( * V_235 ) ) ;
if ( V_235 == NULL )
return - V_27 ;
V_230 -> V_26 = V_235 ;
if ( F_76 ( V_235 , V_234 , V_230 -> V_22 * sizeof( * V_234 ) ) )
return - V_27 ;
return 0 ;
}
static int F_77 ( const struct V_3 * V_230 ,
struct V_231 T_7 * V_232 )
{
struct V_233 T_7 * V_234 ;
struct V_233 T_7 * V_235 = V_230 -> V_26 ;
T_8 V_236 ;
if ( ! F_69 ( V_239 , V_232 , sizeof( * V_232 ) ) ||
F_78 ( V_232 , V_230 , F_71 ( F_72 ( * V_232 ) , V_26 ) ) ||
F_79 ( V_230 -> V_22 , & V_232 -> V_22 ) )
return - V_27 ;
if ( F_80 ( V_232 -> V_238 , sizeof( V_232 -> V_238 ) ) )
return - V_27 ;
if ( V_230 -> V_22 == 0 )
return 0 ;
if ( F_81 ( V_236 , & V_232 -> V_26 ) )
return - V_27 ;
V_234 = F_74 ( V_236 ) ;
if ( F_76 ( V_234 , V_235 , V_230 -> V_22 * sizeof( * V_234 ) ) )
return - V_27 ;
return 0 ;
}
static int F_82 ( struct V_240 * V_230 ,
const struct V_241 T_7 * V_232 )
{
T_6 T_7 * V_242 ;
T_6 T_7 * V_243 ;
T_8 V_236 ;
if ( ! F_69 ( V_237 , V_232 , sizeof( * V_232 ) ) ||
F_70 ( V_230 , V_232 , F_71 ( F_72 ( * V_232 ) , V_244 ) ) )
return - V_27 ;
if ( V_230 -> V_7 == 0 ) {
V_230 -> V_244 = NULL ;
return 0 ;
}
if ( F_73 ( V_236 , & V_232 -> V_244 ) )
return - V_27 ;
V_242 = F_74 ( V_236 ) ;
if ( ! F_69 ( V_237 , V_242 , V_230 -> V_7 ) )
return - V_27 ;
V_243 = F_75 ( V_230 -> V_7 ) ;
if ( V_243 == NULL )
return - V_27 ;
V_230 -> V_244 = V_243 ;
if ( F_76 ( V_243 , V_242 , V_230 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static int F_83 ( const struct V_240 * V_230 ,
struct V_241 T_7 * V_232 )
{
T_6 T_7 * V_242 ;
T_6 T_7 * V_243 = V_230 -> V_244 ;
T_8 V_236 ;
if ( ! F_69 ( V_239 , V_232 , sizeof( * V_232 ) ) ||
F_78 ( V_232 , V_230 , F_71 ( F_72 ( * V_232 ) , V_244 ) ) )
return - V_27 ;
if ( V_230 -> V_7 == 0 )
return 0 ;
if ( F_81 ( V_236 , & V_232 -> V_244 ) )
return - V_27 ;
V_242 = F_74 ( V_236 ) ;
if ( ! F_69 ( V_237 , V_242 , V_230 -> V_7 ) )
return - V_27 ;
if ( F_76 ( V_242 , V_243 , V_230 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static long F_84 ( struct V_108 * V_108 ,
unsigned int V_117 , unsigned long V_118 )
{
union {
struct V_3 V_4 ;
struct V_240 V_245 ;
} V_246 ;
void T_7 * V_232 = F_74 ( V_118 ) ;
T_9 V_247 ;
long V_8 ;
switch ( V_117 ) {
case V_248 :
V_117 = V_226 ;
V_8 = F_68 ( & V_246 . V_4 , V_232 ) ;
break;
case V_249 :
V_117 = V_227 ;
V_8 = F_82 ( & V_246 . V_245 , V_232 ) ;
break;
default:
return - V_250 ;
}
V_247 = F_85 () ;
F_86 ( V_251 ) ;
V_8 = F_63 ( V_108 , V_117 , ( unsigned long ) & V_246 ) ;
F_86 ( V_247 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_117 ) {
case V_226 :
V_8 = F_77 ( & V_246 . V_4 , V_232 ) ;
break;
case V_227 :
V_8 = F_83 ( & V_246 . V_245 , V_232 ) ;
break;
}
return V_8 ;
}
static T_10 F_87 ( struct V_108 * V_108 , char T_7 * V_244 ,
T_11 V_145 , T_12 * V_252 )
{
F_5 ( V_109 , L_16 ) ;
return - V_24 ;
}
static int F_88 ( struct V_108 * V_108 , struct V_253 * V_254 )
{
struct V_102 * V_103 = V_108 -> V_116 ;
struct V_41 * V_42 = V_103 -> V_42 ;
F_5 ( V_109 , L_17 ) ;
return F_89 ( & V_42 -> V_85 , V_254 ) ;
}
static unsigned int F_90 ( struct V_108 * V_108 , T_13 * V_255 )
{
struct V_102 * V_103 = V_108 -> V_116 ;
struct V_41 * V_42 = V_103 -> V_42 ;
F_5 ( V_109 , L_18 ) ;
return F_91 ( & V_42 -> V_85 , V_108 , V_255 ) ;
}
static unsigned long F_92 ( struct V_108 * V_108 ,
unsigned long V_256 , unsigned long V_257 , unsigned long V_258 ,
unsigned long V_169 )
{
struct V_102 * V_103 = V_108 -> V_116 ;
struct V_41 * V_42 = V_103 -> V_42 ;
F_5 ( V_109 , L_19 ) ;
return F_93 ( & V_42 -> V_85 , V_258 ) ;
}
