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
if ( F_22 ( & V_42 -> V_72 -> V_114 ) == 1 ) {
V_8 = F_30 ( V_42 -> V_72 ) ;
if ( V_8 < 0 ) {
F_23 ( & V_42 -> V_72 -> V_114 ) ;
F_29 ( V_42 -> V_72 -> V_113 ) ;
F_7 ( V_104 ) ;
return V_8 ;
}
}
F_31 ( & V_104 -> V_115 , V_42 -> V_116 ) ;
F_32 ( & V_104 -> V_115 ) ;
V_104 -> V_2 = V_42 -> V_2 ;
V_104 -> V_42 = V_42 ;
V_104 -> V_105 = V_108 ;
V_109 -> V_117 = V_104 ;
return 0 ;
}
static int F_33 ( struct V_109 * V_109 )
{
struct V_103 * V_104 = V_109 -> V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_9 ) ;
if ( F_25 ( V_104 ) ) {
F_34 ( V_42 , 0 ) ;
F_35 ( & V_42 -> V_86 ) ;
}
F_24 ( V_104 ) ;
F_36 ( & V_104 -> V_115 ) ;
F_37 ( & V_104 -> V_115 ) ;
F_7 ( V_104 ) ;
V_109 -> V_117 = NULL ;
if ( F_38 ( & V_42 -> V_72 -> V_114 ) == 0 )
F_39 ( V_42 -> V_72 ) ;
F_29 ( V_42 -> V_72 -> V_113 ) ;
return 0 ;
}
static long F_40 ( struct V_109 * V_109 , unsigned int V_118 , void * V_119 )
{
struct V_120 * V_116 = F_41 ( V_109 ) ;
struct V_103 * V_104 = V_109 -> V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_41 * V_42 = V_104 -> V_42 ;
long V_8 = 0 ;
switch ( V_118 ) {
case V_121 :
{
struct V_122 * V_123 = V_119 ;
memset ( V_123 , 0 , sizeof *V_123 ) ;
F_42 ( V_123 -> V_124 , L_10 , sizeof V_123 -> V_124 ) ;
F_42 ( V_123 -> V_125 , V_116 -> V_12 , sizeof V_123 -> V_125 ) ;
F_43 ( V_42 -> V_72 -> V_126 ,
V_123 -> V_127 , sizeof( V_123 -> V_127 ) ) ;
V_123 -> V_128 = V_129 ;
V_123 -> V_130 = V_131 | V_132
| V_2 -> V_133 ;
if ( V_42 -> type == V_92 )
V_123 -> V_134 = V_135
| V_132 ;
else
V_123 -> V_134 = V_136
| V_132 ;
break;
}
case V_137 :
* ( V_138 * ) V_119 = F_44 ( V_116 -> V_139 ) ;
break;
case V_140 :
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_46 ( V_116 -> V_139 , & V_104 -> V_115 . V_139 ,
* ( V_138 * ) V_119 ) ;
case V_141 :
return F_47 ( V_2 , V_119 ) ;
case V_142 :
{
struct V_143 * V_76 = V_119 ;
struct V_144 V_145 ;
memset ( & V_145 , 0 , sizeof V_145 ) ;
V_145 . V_11 = V_76 -> V_11 ;
V_8 = F_48 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_49 ( V_2 , & V_145 ) ;
F_50 ( V_104 ) ;
if ( V_8 >= 0 )
V_76 -> V_146 = V_145 . V_146 ;
break;
}
case V_147 :
{
struct V_143 * V_76 = V_119 ;
struct V_144 V_145 ;
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
memset ( & V_145 , 0 , sizeof V_145 ) ;
V_145 . V_11 = V_76 -> V_11 ;
V_145 . V_146 = V_76 -> V_146 ;
V_8 = F_48 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_2 , & V_145 ) ;
if ( V_8 < 0 ) {
F_50 ( V_104 ) ;
return V_8 ;
}
V_8 = F_52 ( V_104 , & V_145 , 1 ) ;
if ( V_8 == 0 )
V_76 -> V_146 = V_145 . V_146 ;
break;
}
case V_148 :
return F_53 ( V_2 , V_119 ) ;
case V_149 :
{
struct V_150 * V_151 = V_119 ;
struct V_144 * V_76 = V_151 -> V_152 ;
unsigned int V_33 ;
V_8 = F_48 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_151 -> V_153 ; ++ V_76 , ++ V_33 ) {
V_8 = F_49 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_50 ( V_104 ) ;
V_151 -> V_154 = V_33 ;
return V_8 ;
}
}
V_151 -> V_154 = 0 ;
V_8 = F_50 ( V_104 ) ;
break;
}
case V_155 :
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
case V_156 :
{
struct V_150 * V_151 = V_119 ;
struct V_144 * V_76 = V_151 -> V_152 ;
unsigned int V_33 ;
V_8 = F_48 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_151 -> V_153 ; ++ V_76 , ++ V_33 ) {
V_8 = F_51 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_50 ( V_104 ) ;
V_151 -> V_154 = V_118 == V_155
? V_151 -> V_153 : V_33 ;
return V_8 ;
}
}
V_151 -> V_154 = 0 ;
if ( V_118 == V_155 )
V_8 = F_52 ( V_104 ,
V_151 -> V_152 , V_151 -> V_153 ) ;
else
V_8 = F_50 ( V_104 ) ;
break;
}
case V_157 :
{
const struct V_158 * V_14 = V_2 -> V_14 ;
struct V_159 * V_160 = V_119 ;
struct V_158 * V_161 = NULL ;
V_138 V_69 = V_160 -> V_69 ;
int V_162 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_163 ) ) {
if ( V_69 != 0 )
return - V_24 ;
F_54 (iterm, &chain->entities, chain) {
if ( F_55 ( V_161 ) )
break;
}
V_162 = V_161 -> V_11 ;
} else if ( V_69 < V_14 -> V_164 ) {
V_162 = V_14 -> V_165 [ V_69 ] ;
F_54 (iterm, &chain->entities, chain) {
if ( ! F_55 ( V_161 ) )
continue;
if ( V_161 -> V_11 == V_162 )
break;
}
}
if ( V_161 == NULL || V_161 -> V_11 != V_162 )
return - V_24 ;
memset ( V_160 , 0 , sizeof *V_160 ) ;
V_160 -> V_69 = V_69 ;
F_42 ( V_160 -> V_12 , V_161 -> V_12 , sizeof V_160 -> V_12 ) ;
if ( F_56 ( V_161 ) == V_166 )
V_160 -> type = V_167 ;
break;
}
case V_168 :
{
T_5 V_160 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_163 ) ) {
* ( int * ) V_119 = 0 ;
break;
}
V_8 = F_57 ( V_2 -> V_72 , V_169 ,
V_2 -> V_14 -> V_11 , V_2 -> V_72 -> V_170 ,
V_171 , & V_160 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* ( int * ) V_119 = V_160 - 1 ;
break;
}
case V_172 :
{
V_138 V_160 = * ( V_138 * ) V_119 + 1 ;
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_163 ) ) {
if ( V_160 != 1 )
return - V_24 ;
break;
}
if ( V_160 == 0 || V_160 > V_2 -> V_14 -> V_164 )
return - V_24 ;
return F_57 ( V_2 -> V_72 , V_173 ,
V_2 -> V_14 -> V_11 , V_2 -> V_72 -> V_170 ,
V_171 , & V_160 , 1 ) ;
}
case V_174 :
{
struct V_175 * V_44 = V_119 ;
struct V_47 * V_48 ;
enum V_176 type = V_44 -> type ;
T_1 V_69 = V_44 -> V_69 ;
if ( V_44 -> type != V_42 -> type ||
V_44 -> V_69 >= V_42 -> V_59 )
return - V_24 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_69 = V_69 ;
V_44 -> type = type ;
V_48 = & V_42 -> V_48 [ V_44 -> V_69 ] ;
V_44 -> V_177 = 0 ;
if ( V_48 -> V_177 & V_178 )
V_44 -> V_177 |= V_179 ;
F_42 ( V_44 -> V_180 , V_48 -> V_12 ,
sizeof V_44 -> V_180 ) ;
V_44 -> V_180 [ sizeof V_44 -> V_180 - 1 ] = 0 ;
V_44 -> V_55 = V_48 -> V_53 ;
break;
}
case V_181 :
{
struct V_45 V_46 ;
return F_9 ( V_42 , V_119 , & V_46 , NULL , NULL ) ;
}
case V_182 :
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
return F_14 ( V_42 , V_119 ) ;
case V_183 :
return F_13 ( V_42 , V_119 ) ;
case V_184 :
{
struct V_185 * V_186 = V_119 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 ==
V_186 -> V_187 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
if ( V_186 -> V_69 >= V_48 -> V_61 )
return - V_24 ;
V_31 = & V_48 -> V_31 [ V_186 -> V_69 ] ;
V_186 -> type = V_188 ;
V_186 -> V_189 . V_57 = V_31 -> V_63 ;
V_186 -> V_189 . V_58 = V_31 -> V_65 ;
break;
}
case V_190 :
{
struct V_191 * V_192 = V_119 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 ==
V_192 -> V_187 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_61 ; V_33 ++ ) {
if ( V_48 -> V_31 [ V_33 ] . V_63 == V_192 -> V_57 &&
V_48 -> V_31 [ V_33 ] . V_65 == V_192 -> V_58 ) {
V_31 = & V_48 -> V_31 [ V_33 ] ;
break;
}
}
if ( V_31 == NULL )
return - V_24 ;
if ( V_31 -> V_34 ) {
if ( V_192 -> V_69 >= V_31 -> V_34 )
return - V_24 ;
V_192 -> type = V_193 ;
V_192 -> V_189 . V_90 =
V_31 -> V_37 [ V_192 -> V_69 ] ;
V_192 -> V_189 . V_91 = 10000000 ;
F_17 ( & V_192 -> V_189 . V_90 ,
& V_192 -> V_189 . V_91 , 8 , 333 ) ;
} else {
V_192 -> type = V_194 ;
V_192 -> V_195 . V_38 . V_90 =
V_31 -> V_37 [ 0 ] ;
V_192 -> V_195 . V_38 . V_91 = 10000000 ;
V_192 -> V_195 . V_39 . V_90 =
V_31 -> V_37 [ 1 ] ;
V_192 -> V_195 . V_39 . V_91 = 10000000 ;
V_192 -> V_195 . V_40 . V_90 =
V_31 -> V_37 [ 2 ] ;
V_192 -> V_195 . V_40 . V_91 = 10000000 ;
F_17 ( & V_192 -> V_195 . V_38 . V_90 ,
& V_192 -> V_195 . V_38 . V_91 , 8 , 333 ) ;
F_17 ( & V_192 -> V_195 . V_39 . V_90 ,
& V_192 -> V_195 . V_39 . V_91 , 8 , 333 ) ;
F_17 ( & V_192 -> V_195 . V_40 . V_90 ,
& V_192 -> V_195 . V_40 . V_91 , 8 , 333 ) ;
}
break;
}
case V_196 :
return F_16 ( V_42 , V_119 ) ;
case V_197 :
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
return F_18 ( V_42 , V_119 ) ;
case V_198 :
{
struct V_199 * V_200 = V_119 ;
if ( V_200 -> type != V_42 -> type )
return - V_24 ;
V_200 -> V_201 . V_202 = 0 ;
V_200 -> V_201 . V_203 = 0 ;
F_10 ( & V_42 -> V_71 ) ;
V_200 -> V_201 . V_57 = V_42 -> V_85 -> V_63 ;
V_200 -> V_201 . V_58 = V_42 -> V_85 -> V_65 ;
F_12 ( & V_42 -> V_71 ) ;
V_200 -> V_204 = V_200 -> V_201 ;
V_200 -> V_205 . V_90 = 1 ;
V_200 -> V_205 . V_91 = 1 ;
break;
}
case V_206 :
case V_207 :
return - V_29 ;
case V_208 :
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_21 ( V_104 ) ) < 0 )
return V_8 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_58 ( & V_42 -> V_86 , V_119 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_24 ( V_104 ) ;
V_8 = 0 ;
break;
case V_209 :
{
struct V_210 * V_211 = V_119 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_59 ( & V_42 -> V_86 , V_211 ) ;
}
case V_212 :
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_60 ( & V_42 -> V_86 , V_119 ) ;
case V_213 :
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_61 ( & V_42 -> V_86 , V_119 ,
V_109 -> V_214 & V_215 ) ;
case V_216 :
{
int * type = V_119 ;
if ( * type != V_42 -> type )
return - V_24 ;
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
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
case V_217 :
{
int * type = V_119 ;
if ( * type != V_42 -> type )
return - V_24 ;
V_8 = F_45 ( V_116 -> V_139 , V_104 -> V_115 . V_139 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_34 ( V_42 , 0 ) ;
}
case V_218 :
{
struct V_219 * V_220 = V_119 ;
switch ( V_220 -> type ) {
case V_221 :
return F_62 ( & V_104 -> V_115 , V_220 , 0 ,
& V_222 ) ;
default:
return - V_24 ;
}
}
case V_223 :
return F_63 ( & V_104 -> V_115 , V_119 ) ;
case V_224 :
return F_64 ( & V_104 -> V_115 , V_119 ,
V_109 -> V_214 & V_215 ) ;
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
F_5 ( V_233 , L_11 , V_118 ) ;
return - V_29 ;
case V_234 :
return F_1 ( V_2 , V_119 ) ;
case V_235 :
return F_65 ( V_2 , V_119 ) ;
default:
F_5 ( V_233 , L_12 , V_118 ) ;
return - V_29 ;
}
return V_8 ;
}
static long F_66 ( struct V_109 * V_109 ,
unsigned int V_118 , unsigned long V_119 )
{
if ( V_236 & V_233 ) {
F_67 ( V_237 , L_13 ) ;
F_68 ( NULL , V_118 ) ;
F_69 ( L_14 ) ;
}
return F_70 ( V_109 , V_118 , V_119 , F_40 ) ;
}
static int F_71 ( struct V_3 * V_238 ,
const struct V_239 T_6 * V_240 )
{
struct V_241 T_6 * V_242 ;
struct V_241 T_6 * V_243 ;
T_7 V_244 ;
if ( ! F_72 ( V_245 , V_240 , sizeof( * V_240 ) ) ||
F_73 ( V_238 , V_240 , F_74 ( F_75 ( * V_240 ) , V_26 ) ) ||
F_76 ( V_238 -> V_22 , & V_240 -> V_22 ) )
return - V_27 ;
memset ( V_238 -> V_246 , 0 , sizeof( V_238 -> V_246 ) ) ;
if ( V_238 -> V_22 == 0 ) {
V_238 -> V_26 = NULL ;
return 0 ;
}
if ( F_76 ( V_244 , & V_240 -> V_26 ) )
return - V_27 ;
V_242 = F_77 ( V_244 ) ;
if ( ! F_72 ( V_245 , V_242 , V_238 -> V_22 * sizeof( * V_242 ) ) )
return - V_27 ;
V_243 = F_78 ( V_238 -> V_22 * sizeof( * V_243 ) ) ;
if ( V_243 == NULL )
return - V_27 ;
V_238 -> V_26 = V_243 ;
if ( F_79 ( V_243 , V_242 , V_238 -> V_22 * sizeof( * V_242 ) ) )
return - V_27 ;
return 0 ;
}
static int F_80 ( const struct V_3 * V_238 ,
struct V_239 T_6 * V_240 )
{
struct V_241 T_6 * V_242 ;
struct V_241 T_6 * V_243 = V_238 -> V_26 ;
T_7 V_244 ;
if ( ! F_72 ( V_247 , V_240 , sizeof( * V_240 ) ) ||
F_81 ( V_240 , V_238 , F_74 ( F_75 ( * V_240 ) , V_26 ) ) ||
F_82 ( V_238 -> V_22 , & V_240 -> V_22 ) )
return - V_27 ;
if ( F_83 ( V_240 -> V_246 , sizeof( V_240 -> V_246 ) ) )
return - V_27 ;
if ( V_238 -> V_22 == 0 )
return 0 ;
if ( F_84 ( V_244 , & V_240 -> V_26 ) )
return - V_27 ;
V_242 = F_77 ( V_244 ) ;
if ( F_79 ( V_242 , V_243 , V_238 -> V_22 * sizeof( * V_242 ) ) )
return - V_27 ;
return 0 ;
}
static int F_85 ( struct V_248 * V_238 ,
const struct V_249 T_6 * V_240 )
{
T_5 T_6 * V_250 ;
T_5 T_6 * V_251 ;
T_7 V_244 ;
if ( ! F_72 ( V_245 , V_240 , sizeof( * V_240 ) ) ||
F_73 ( V_238 , V_240 , F_74 ( F_75 ( * V_240 ) , V_252 ) ) )
return - V_27 ;
if ( V_238 -> V_7 == 0 ) {
V_238 -> V_252 = NULL ;
return 0 ;
}
if ( F_76 ( V_244 , & V_240 -> V_252 ) )
return - V_27 ;
V_250 = F_77 ( V_244 ) ;
if ( ! F_72 ( V_245 , V_250 , V_238 -> V_7 ) )
return - V_27 ;
V_251 = F_78 ( V_238 -> V_7 ) ;
if ( V_251 == NULL )
return - V_27 ;
V_238 -> V_252 = V_251 ;
if ( F_79 ( V_251 , V_250 , V_238 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static int F_86 ( const struct V_248 * V_238 ,
struct V_249 T_6 * V_240 )
{
T_5 T_6 * V_250 ;
T_5 T_6 * V_251 = V_238 -> V_252 ;
T_7 V_244 ;
if ( ! F_72 ( V_247 , V_240 , sizeof( * V_240 ) ) ||
F_81 ( V_240 , V_238 , F_74 ( F_75 ( * V_240 ) , V_252 ) ) )
return - V_27 ;
if ( V_238 -> V_7 == 0 )
return 0 ;
if ( F_84 ( V_244 , & V_240 -> V_252 ) )
return - V_27 ;
V_250 = F_77 ( V_244 ) ;
if ( ! F_72 ( V_245 , V_250 , V_238 -> V_7 ) )
return - V_27 ;
if ( F_79 ( V_250 , V_251 , V_238 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static long F_87 ( struct V_109 * V_109 ,
unsigned int V_118 , unsigned long V_119 )
{
union {
struct V_3 V_4 ;
struct V_248 V_253 ;
} V_254 ;
void T_6 * V_240 = F_77 ( V_119 ) ;
T_8 V_255 ;
long V_8 ;
switch ( V_118 ) {
case V_256 :
V_118 = V_234 ;
V_8 = F_71 ( & V_254 . V_4 , V_240 ) ;
break;
case V_257 :
V_118 = V_235 ;
V_8 = F_85 ( & V_254 . V_253 , V_240 ) ;
break;
default:
return - V_258 ;
}
V_255 = F_88 () ;
F_89 ( V_259 ) ;
V_8 = F_66 ( V_109 , V_118 , ( unsigned long ) & V_254 ) ;
F_89 ( V_255 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_118 ) {
case V_234 :
V_8 = F_80 ( & V_254 . V_4 , V_240 ) ;
break;
case V_235 :
V_8 = F_86 ( & V_254 . V_253 , V_240 ) ;
break;
}
return V_8 ;
}
static T_9 F_90 ( struct V_109 * V_109 , char T_6 * V_252 ,
T_10 V_153 , T_11 * V_260 )
{
F_5 ( V_110 , L_15 ) ;
return - V_24 ;
}
static int F_91 ( struct V_109 * V_109 , struct V_261 * V_262 )
{
struct V_103 * V_104 = V_109 -> V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_16 ) ;
return F_92 ( & V_42 -> V_86 , V_262 ) ;
}
static unsigned int F_93 ( struct V_109 * V_109 , T_12 * V_263 )
{
struct V_103 * V_104 = V_109 -> V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_17 ) ;
return F_94 ( & V_42 -> V_86 , V_109 , V_263 ) ;
}
static unsigned long F_95 ( struct V_109 * V_109 ,
unsigned long V_264 , unsigned long V_265 , unsigned long V_266 ,
unsigned long V_177 )
{
struct V_103 * V_104 = V_109 -> V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_18 ) ;
return F_96 ( & V_42 -> V_86 , V_266 ) ;
}
