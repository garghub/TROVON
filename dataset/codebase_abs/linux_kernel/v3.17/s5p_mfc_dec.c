static struct V_1 * F_1 ( struct V_2 * V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 == V_3 -> V_9 . V_10 . V_11 &&
V_7 [ V_5 ] . type == V_4 )
return & V_7 [ V_5 ] ;
}
return NULL ;
}
static int F_2 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 >= 1 && V_13 -> V_15 == V_16 )
return 1 ;
if ( V_13 -> V_14 >= 1 &&
V_13 -> V_15 == V_17 &&
V_13 -> V_18 >= V_13 -> V_19 )
return 1 ;
if ( V_13 -> V_15 == V_20 &&
V_13 -> V_18 >= V_13 -> V_19 )
return 1 ;
if ( V_13 -> V_14 >= 1 &&
V_13 -> V_15 == V_21 &&
V_13 -> V_22 == V_23 )
return 1 ;
if ( ( V_13 -> V_15 == V_24 ||
V_13 -> V_15 == V_25 ) &&
V_13 -> V_18 >= V_13 -> V_19 )
return 1 ;
if ( V_13 -> V_15 == V_26 &&
V_13 -> V_14 >= 1 )
return 1 ;
F_3 ( 2 , L_1 ) ;
return 0 ;
}
static int F_4 ( struct V_27 * V_27 , void * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
strncpy ( V_30 -> V_33 , V_32 -> V_34 -> V_35 , sizeof( V_30 -> V_33 ) - 1 ) ;
strncpy ( V_30 -> V_36 , V_32 -> V_34 -> V_35 , sizeof( V_30 -> V_36 ) - 1 ) ;
V_30 -> V_37 [ 0 ] = 0 ;
V_30 -> V_38 = F_6 ( 1 , 0 , 0 ) ;
V_30 -> V_39 = V_40 | V_41 |
V_42 |
V_43 ;
return 0 ;
}
static int F_7 ( struct V_27 * V_27 , struct V_44 * V_3 ,
bool V_45 , bool V_46 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
int V_5 , V_47 = 0 ;
for ( V_5 = 0 ; V_5 < F_8 ( V_7 ) ; ++ V_5 ) {
if ( V_45 && V_7 [ V_5 ] . V_48 == 1 )
continue;
else if ( ! V_45 && V_7 [ V_5 ] . V_48 > 1 )
continue;
if ( V_46 && V_7 [ V_5 ] . type != V_49 )
continue;
else if ( ! V_46 && V_7 [ V_5 ] . type != V_50 )
continue;
else if ( ( V_32 -> V_51 -> V_52 & V_7 [ V_5 ] . V_53 ) == 0 )
continue;
if ( V_47 == V_3 -> V_54 )
break;
++ V_47 ;
}
if ( V_5 == F_8 ( V_7 ) )
return - V_55 ;
V_9 = & V_7 [ V_5 ] ;
F_9 ( V_3 -> V_56 , V_9 -> V_35 , sizeof( V_3 -> V_56 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_27 , void * V_57 ,
struct V_44 * V_3 )
{
return F_7 ( V_27 , V_3 , false , false ) ;
}
static int F_11 ( struct V_27 * V_27 , void * V_57 ,
struct V_44 * V_3 )
{
return F_7 ( V_27 , V_3 , true , false ) ;
}
static int F_12 ( struct V_27 * V_27 , void * V_28 ,
struct V_44 * V_3 )
{
return F_7 ( V_27 , V_3 , false , true ) ;
}
static int F_13 ( struct V_27 * V_27 , void * V_28 ,
struct V_44 * V_3 )
{
return F_7 ( V_27 , V_3 , true , true ) ;
}
static int F_14 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_58 * V_10 ;
F_16 () ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_59 &&
( V_13 -> V_15 == V_16 || V_13 -> V_15 ==
V_26 ) ) {
F_17 ( V_13 ) ;
F_18 ( V_13 , V_60 ,
0 ) ;
}
if ( V_3 -> type == V_59 &&
V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_61 ) {
V_10 -> V_62 = V_13 -> V_63 ;
V_10 -> V_64 = V_13 -> V_65 ;
V_10 -> V_66 = V_67 ;
V_10 -> V_48 = 2 ;
V_10 -> V_11 = V_13 -> V_68 -> V_8 ;
V_10 -> V_69 [ 0 ] . V_70 = V_13 -> V_63 ;
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_72 ;
V_10 -> V_69 [ 1 ] . V_70 = V_13 -> V_63 ;
V_10 -> V_69 [ 1 ] . V_71 = V_13 -> V_73 ;
} else if ( V_3 -> type == V_74 ) {
V_10 -> V_62 = 0 ;
V_10 -> V_64 = 0 ;
V_10 -> V_66 = V_67 ;
V_10 -> V_69 [ 0 ] . V_70 = V_13 -> V_75 ;
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_75 ;
V_10 -> V_11 = V_13 -> V_76 -> V_8 ;
V_10 -> V_48 = V_13 -> V_76 -> V_48 ;
} else {
F_19 ( L_2 ) ;
F_3 ( 2 , L_3 , V_77 ) ;
return - V_55 ;
}
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
F_3 ( 2 , L_4 , V_3 -> type ) ;
if ( V_3 -> type == V_74 ) {
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 ) {
F_19 ( L_5 ) ;
return - V_55 ;
}
if ( V_9 -> V_78 == V_79 ) {
F_19 ( L_6 ) ;
return - V_55 ;
}
if ( ( V_32 -> V_51 -> V_52 & V_9 -> V_53 ) == 0 ) {
F_19 ( L_7 ) ;
return - V_55 ;
}
} else if ( V_3 -> type == V_59 ) {
V_9 = F_1 ( V_3 , V_50 ) ;
if ( ! V_9 ) {
F_19 ( L_8 ) ;
return - V_55 ;
}
if ( ( V_32 -> V_51 -> V_52 & V_9 -> V_53 ) == 0 ) {
F_19 ( L_7 ) ;
return - V_55 ;
}
}
return 0 ;
}
static int F_22 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 = 0 ;
struct V_58 * V_10 ;
struct V_81 * V_82 = V_32 -> V_51 -> V_82 ;
F_16 () ;
V_80 = F_21 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_80 )
return V_80 ;
if ( V_13 -> V_83 . V_84 || V_13 -> V_85 . V_84 ) {
F_23 ( & V_32 -> V_86 , L_9 , V_77 ) ;
V_80 = - V_87 ;
goto V_46;
}
if ( V_3 -> type == V_59 ) {
V_13 -> V_68 = F_1 ( V_3 , V_50 ) ;
V_80 = 0 ;
goto V_46;
} else if ( V_3 -> type == V_74 ) {
V_13 -> V_76 = F_1 ( V_3 , V_49 ) ;
V_13 -> V_78 = V_13 -> V_76 -> V_78 ;
F_3 ( 2 , L_10 , V_13 -> V_78 ) ;
V_10 -> V_64 = 0 ;
V_10 -> V_62 = 0 ;
if ( V_10 -> V_69 [ 0 ] . V_71 == 0 )
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_75 =
V_88 ;
else if ( V_10 -> V_69 [ 0 ] . V_71 > V_82 -> V_89 )
V_13 -> V_75 = V_82 -> V_89 ;
else
V_13 -> V_75 = V_10 -> V_69 [ 0 ] . V_71 ;
V_10 -> V_69 [ 0 ] . V_70 = 0 ;
V_13 -> V_15 = V_90 ;
V_80 = 0 ;
goto V_46;
} else {
F_19 ( L_11 , V_3 -> type ) ;
V_80 = - V_55 ;
goto V_46;
}
V_46:
F_20 () ;
return V_80 ;
}
static int F_24 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_91 * V_92 )
{
int V_80 = 0 ;
F_25 () ;
if ( V_92 -> V_93 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_80 = F_26 ( & V_13 -> V_83 , V_92 ) ;
if ( V_80 )
goto V_46;
F_27 ( V_32 , V_13 ) ;
V_13 -> V_94 = 0 ;
V_13 -> V_95 = V_96 ;
} else if ( V_13 -> V_95 == V_96 ) {
F_28 ( V_13 -> V_94 != 0 ) ;
if ( V_13 -> V_15 != V_90 ) {
F_19 ( L_13 ) ;
V_80 = - V_55 ;
goto V_46;
}
F_3 ( 2 , L_14 ,
V_92 -> V_93 ) ;
V_80 = F_26 ( & V_13 -> V_83 , V_92 ) ;
if ( V_80 )
goto V_46;
V_80 = F_29 ( V_32 , V_13 ) ;
if ( V_80 ) {
V_92 -> V_93 = 0 ;
F_26 ( & V_13 -> V_83 , V_92 ) ;
goto V_46;
}
V_13 -> V_95 = V_97 ;
} else {
F_19 ( L_15 ) ;
V_80 = - V_55 ;
}
V_46:
F_30 () ;
if ( V_80 )
F_19 ( L_16 ) ;
return V_80 ;
}
static int F_31 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_91 * V_92 )
{
int V_80 = 0 ;
F_25 () ;
if ( V_92 -> V_93 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_80 = F_26 ( & V_13 -> V_85 , V_92 ) ;
if ( V_80 )
goto V_46;
F_32 ( V_32 -> V_98 , V_99 , V_13 ) ;
V_13 -> V_100 = 0 ;
} else if ( V_13 -> V_22 == V_96 ) {
F_28 ( V_13 -> V_100 != 0 ) ;
F_3 ( 2 , L_17 ,
V_92 -> V_93 ) ;
V_80 = F_26 ( & V_13 -> V_85 , V_92 ) ;
if ( V_80 )
goto V_46;
V_13 -> V_22 = V_97 ;
V_13 -> V_101 = V_92 -> V_93 ;
V_80 = F_32 ( V_32 -> V_98 , V_102 , V_13 ) ;
if ( V_80 ) {
F_19 ( L_18 ) ;
V_92 -> V_93 = 0 ;
F_26 ( & V_13 -> V_85 , V_92 ) ;
V_80 = - V_103 ;
V_13 -> V_22 = V_96 ;
goto V_46;
}
F_28 ( V_13 -> V_100 != V_13 -> V_101 ) ;
V_13 -> V_22 = V_23 ;
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_32 ( V_32 -> V_98 , V_104 , V_32 ) ;
F_18 ( V_13 , V_105 ,
0 ) ;
} else {
F_19 ( L_15 ) ;
V_80 = - V_55 ;
}
V_46:
F_30 () ;
if ( V_80 )
F_19 ( L_19 ) ;
return V_80 ;
}
static int F_34 ( struct V_27 * V_27 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_92 -> V_106 != V_107 ) {
F_19 ( L_20 ) ;
return - V_55 ;
}
if ( V_92 -> type == V_74 ) {
return F_24 ( V_32 , V_13 , V_92 ) ;
} else if ( V_92 -> type == V_59 ) {
return F_31 ( V_32 , V_13 , V_92 ) ;
} else {
F_19 ( L_21 ) ;
return - V_55 ;
}
}
static int F_35 ( struct V_27 * V_27 , void * V_28 ,
struct V_108 * V_109 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 ;
int V_5 ;
if ( V_109 -> V_106 != V_107 ) {
F_19 ( L_22 ) ;
return - V_55 ;
}
F_3 ( 2 , L_23 , V_13 -> V_15 , V_109 -> type ) ;
if ( V_13 -> V_15 == V_16 &&
V_109 -> type == V_74 ) {
V_80 = F_36 ( & V_13 -> V_83 , V_109 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_109 -> type == V_59 ) {
V_80 = F_36 ( & V_13 -> V_85 , V_109 ) ;
for ( V_5 = 0 ; V_5 < V_109 -> V_110 ; V_5 ++ )
V_109 -> V_111 . V_112 [ V_5 ] . V_111 . V_113 += V_114 ;
} else {
F_19 ( L_24 ) ;
V_80 = - V_55 ;
}
F_20 () ;
return V_80 ;
}
static int F_37 ( struct V_27 * V_27 , void * V_28 , struct V_108 * V_109 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_115 ) {
F_19 ( L_25 ) ;
return - V_116 ;
}
if ( V_109 -> type == V_74 )
return F_38 ( & V_13 -> V_83 , V_109 ) ;
else if ( V_109 -> type == V_59 )
return F_38 ( & V_13 -> V_85 , V_109 ) ;
return - V_55 ;
}
static int F_39 ( struct V_27 * V_27 , void * V_28 , struct V_108 * V_109 )
{
const struct V_117 V_118 = {
. type = V_119
} ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 ;
if ( V_13 -> V_15 == V_115 ) {
F_19 ( L_26 ) ;
return - V_116 ;
}
if ( V_109 -> type == V_74 )
V_80 = F_40 ( & V_13 -> V_83 , V_109 , V_27 -> V_120 & V_121 ) ;
else if ( V_109 -> type == V_59 ) {
V_80 = F_40 ( & V_13 -> V_85 , V_109 , V_27 -> V_120 & V_121 ) ;
if ( V_80 == 0 && V_13 -> V_15 == V_122 &&
F_41 ( & V_13 -> V_85 . V_123 ) )
F_42 ( & V_13 -> V_124 , & V_118 ) ;
} else {
V_80 = - V_55 ;
}
return V_80 ;
}
static int F_43 ( struct V_27 * V_27 , void * V_28 ,
struct V_125 * V_126 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_126 -> type == V_74 )
return F_44 ( & V_13 -> V_83 , V_126 ) ;
if ( V_126 -> type == V_59 )
return F_44 ( & V_13 -> V_85 , V_126 ) ;
return - V_55 ;
}
static int F_45 ( struct V_27 * V_27 , void * V_28 ,
enum V_127 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 = - V_55 ;
F_16 () ;
if ( type == V_74 )
V_80 = F_46 ( & V_13 -> V_83 , type ) ;
else if ( type == V_59 )
V_80 = F_46 ( & V_13 -> V_85 , type ) ;
F_20 () ;
return V_80 ;
}
static int F_47 ( struct V_27 * V_27 , void * V_28 ,
enum V_127 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( type == V_74 )
return F_48 ( & V_13 -> V_83 , type ) ;
else if ( type == V_59 )
return F_48 ( & V_13 -> V_85 , type ) ;
return - V_55 ;
}
static int F_49 ( struct V_128 * V_129 )
{
struct V_12 * V_13 = F_50 ( V_129 ) ;
switch ( V_129 -> V_130 ) {
case V_131 :
V_13 -> V_132 = V_129 -> V_133 ;
break;
case V_134 :
V_13 -> V_135 = V_129 -> V_133 ;
break;
case V_136 :
V_13 -> V_137 = V_129 -> V_133 ;
break;
case V_138 :
V_13 -> V_139 = V_129 -> V_133 ;
break;
default:
F_19 ( L_27 , V_129 -> V_130 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_51 ( struct V_128 * V_129 )
{
struct V_12 * V_13 = F_50 ( V_129 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_129 -> V_130 ) {
case V_140 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_61 ) {
V_129 -> V_133 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_90 ) {
F_23 ( & V_32 -> V_86 , L_28 ) ;
return - V_55 ;
}
F_17 ( V_13 ) ;
F_18 ( V_13 ,
V_60 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_61 ) {
V_129 -> V_133 = V_13 -> V_19 ;
} else {
F_23 ( & V_32 -> V_86 , L_28 ) ;
return - V_55 ;
}
break;
}
return 0 ;
}
static int F_52 ( struct V_27 * V_27 , void * V_28 ,
struct V_141 * V_142 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_143 , V_144 , V_145 , V_146 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_122 ) {
F_19 ( L_29 ) ;
return - V_55 ;
}
if ( V_13 -> V_76 -> V_8 == V_147 ) {
V_143 = F_32 ( V_32 -> V_98 , V_148 , V_13 ) ;
V_144 = V_143 >> V_149 ;
V_143 = V_143 & V_150 ;
V_145 = F_32 ( V_32 -> V_98 , V_151 , V_13 ) ;
V_146 = V_145 >> V_152 ;
V_145 = V_145 & V_153 ;
V_142 -> V_154 . V_143 = V_143 ;
V_142 -> V_154 . V_145 = V_145 ;
V_142 -> V_154 . V_62 = V_13 -> V_155 - V_143 - V_144 ;
V_142 -> V_154 . V_64 = V_13 -> V_156 - V_145 - V_146 ;
F_3 ( 2 , L_30
L_31 , V_143 , V_145 ,
V_142 -> V_154 . V_62 , V_142 -> V_154 . V_64 , V_144 , V_146 ,
V_13 -> V_63 , V_13 -> V_65 ) ;
} else {
V_142 -> V_154 . V_143 = 0 ;
V_142 -> V_154 . V_145 = 0 ;
V_142 -> V_154 . V_62 = V_13 -> V_155 ;
V_142 -> V_154 . V_64 = V_13 -> V_156 ;
F_3 ( 2 , L_32
L_33 , V_142 -> V_154 . V_62 , V_142 -> V_154 . V_64 , V_13 -> V_63 ,
V_13 -> V_65 ) ;
}
return 0 ;
}
int F_53 ( struct V_27 * V_27 , void * V_28 ,
struct V_157 * V_158 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_159 * V_109 ;
unsigned long V_160 ;
switch ( V_158 -> V_158 ) {
case V_161 :
if ( V_158 -> V_160 != 0 )
return - V_55 ;
if ( ! V_13 -> V_83 . V_84 )
return - V_55 ;
F_54 ( & V_32 -> V_162 , V_160 ) ;
if ( F_41 ( & V_13 -> V_163 ) ) {
F_19 ( L_34 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_55 ( & V_32 -> V_162 , V_160 ) ;
F_32 ( V_32 -> V_98 , V_104 , V_32 ) ;
} else {
F_19 ( L_35 ) ;
V_109 = F_56 ( V_13 -> V_163 . V_164 ,
struct V_159 , V_165 ) ;
if ( V_109 -> V_160 & V_166 )
V_13 -> V_15 = V_20 ;
else
V_109 -> V_160 |= V_167 ;
F_55 ( & V_32 -> V_162 , V_160 ) ;
}
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_57 ( struct V_168 * V_124 ,
const struct V_169 * V_170 )
{
switch ( V_170 -> type ) {
case V_119 :
return F_58 ( V_124 , V_170 , 2 , NULL ) ;
case V_171 :
return F_59 ( V_124 , V_170 ) ;
default:
return - V_55 ;
}
}
static int F_60 ( struct V_172 * V_173 ,
const struct V_2 * V_9 , unsigned int * V_174 ,
unsigned int * V_175 , unsigned int V_176 [] ,
void * V_177 [] )
{
struct V_12 * V_13 = F_15 ( V_173 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_90 &&
V_173 -> type == V_74 ) {
* V_175 = 1 ;
if ( * V_174 < 1 )
* V_174 = 1 ;
if ( * V_174 > V_179 )
* V_174 = V_179 ;
} else if ( V_13 -> V_15 == V_21 &&
V_173 -> type == V_59 ) {
* V_175 = 2 ;
if ( * V_174 < V_13 -> V_19 )
* V_174 = V_13 -> V_19 ;
if ( * V_174 > V_13 -> V_19 + V_180 )
* V_174 = V_13 -> V_19 + V_180 ;
if ( * V_174 > V_179 )
* V_174 = V_179 ;
} else {
F_19 ( L_36 ,
V_13 -> V_15 , V_173 -> type ) ;
return - V_55 ;
}
F_3 ( 2 , L_37 ,
* V_174 , * V_175 ) ;
if ( V_13 -> V_15 == V_21 &&
V_173 -> type == V_59 ) {
V_176 [ 0 ] = V_13 -> V_72 ;
V_176 [ 1 ] = V_13 -> V_73 ;
if ( F_61 ( V_32 ) )
V_177 [ 0 ] =
V_13 -> V_32 -> V_181 [ V_182 ] ;
else
V_177 [ 0 ] =
V_13 -> V_32 -> V_181 [ V_183 ] ;
V_177 [ 1 ] = V_13 -> V_32 -> V_181 [ V_182 ] ;
} else if ( V_173 -> type == V_74 &&
V_13 -> V_15 == V_90 ) {
V_176 [ 0 ] = V_13 -> V_75 ;
V_177 [ 0 ] = V_13 -> V_32 -> V_181 [ V_182 ] ;
} else {
F_19 ( L_38 ) ;
return - V_55 ;
}
return 0 ;
}
static void F_62 ( struct V_172 * V_184 )
{
struct V_12 * V_13 = F_15 ( V_184 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_63 ( & V_32 -> V_185 ) ;
}
static void F_64 ( struct V_172 * V_184 )
{
struct V_12 * V_13 = F_15 ( V_184 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_65 ( & V_32 -> V_185 ) ;
}
static int F_66 ( struct V_186 * V_187 )
{
struct V_172 * V_173 = V_187 -> V_172 ;
struct V_12 * V_13 = F_15 ( V_173 -> V_178 ) ;
unsigned int V_5 ;
if ( V_173 -> type == V_59 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 <= V_13 -> V_76 -> V_48 ; V_5 ++ ) {
if ( F_67 ( F_68 (
F_69 ( V_187 , V_5 ) ) ) ) {
F_19 ( L_39 ) ;
return - V_55 ;
}
}
if ( F_70 ( V_187 , 0 ) < V_13 -> V_72 ||
F_70 ( V_187 , 1 ) < V_13 -> V_73 ) {
F_19 ( L_40 ) ;
return - V_55 ;
}
V_5 = V_187 -> V_188 . V_54 ;
V_13 -> V_189 [ V_5 ] . V_190 = V_187 ;
V_13 -> V_189 [ V_5 ] . V_191 . V_192 . V_193 =
F_69 ( V_187 , 0 ) ;
V_13 -> V_189 [ V_5 ] . V_191 . V_192 . V_194 =
F_69 ( V_187 , 1 ) ;
V_13 -> V_100 ++ ;
} else if ( V_173 -> type == V_74 ) {
if ( F_67 ( F_68 (
F_69 ( V_187 , 0 ) ) ) ) {
F_19 ( L_41 ) ;
return - V_55 ;
}
if ( F_70 ( V_187 , 0 ) < V_13 -> V_75 ) {
F_19 ( L_42 ) ;
return - V_55 ;
}
V_5 = V_187 -> V_188 . V_54 ;
V_13 -> V_195 [ V_5 ] . V_190 = V_187 ;
V_13 -> V_195 [ V_5 ] . V_191 . V_196 =
F_69 ( V_187 , 0 ) ;
V_13 -> V_94 ++ ;
} else {
F_19 ( L_43 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_71 ( struct V_172 * V_184 , unsigned int V_93 )
{
struct V_12 * V_13 = F_15 ( V_184 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_72 ( & V_13 -> V_197 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_122 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_32 ( V_32 -> V_98 , V_104 , V_32 ) ;
return 0 ;
}
static void F_73 ( struct V_172 * V_184 )
{
unsigned long V_160 ;
struct V_12 * V_13 = F_15 ( V_184 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_198 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_199 == V_13 -> V_200 && V_32 -> V_201 ) {
V_13 -> V_15 = V_61 ;
F_18 ( V_13 ,
V_202 , 0 ) ;
V_198 = 1 ;
}
if ( V_184 -> type == V_59 ) {
F_54 ( & V_32 -> V_162 , V_160 ) ;
F_32 ( V_32 -> V_98 , V_203 , & V_13 -> V_204 ,
& V_13 -> V_85 ) ;
F_74 ( & V_13 -> V_204 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_205 = 1 ;
V_13 -> V_206 = 0 ;
F_55 ( & V_32 -> V_162 , V_160 ) ;
if ( F_61 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_207 ;
F_33 ( V_13 ) ;
F_17 ( V_13 ) ;
F_32 ( V_32 -> V_98 , V_104 , V_32 ) ;
if ( F_18 ( V_13 ,
V_208 , 0 ) )
F_19 ( L_44 ) ;
}
}
if ( V_184 -> type == V_74 ) {
F_54 ( & V_32 -> V_162 , V_160 ) ;
F_32 ( V_32 -> V_98 , V_203 , & V_13 -> V_163 ,
& V_13 -> V_83 ) ;
F_74 ( & V_13 -> V_163 ) ;
V_13 -> V_14 = 0 ;
F_55 ( & V_32 -> V_162 , V_160 ) ;
}
if ( V_198 )
V_13 -> V_15 = V_17 ;
}
static void F_75 ( struct V_186 * V_187 )
{
struct V_172 * V_173 = V_187 -> V_172 ;
struct V_12 * V_13 = F_15 ( V_173 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_160 ;
struct V_159 * V_209 ;
if ( V_173 -> type == V_74 ) {
V_209 = & V_13 -> V_195 [ V_187 -> V_188 . V_54 ] ;
V_209 -> V_160 &= ~ V_166 ;
F_54 ( & V_32 -> V_162 , V_160 ) ;
F_76 ( & V_209 -> V_165 , & V_13 -> V_163 ) ;
V_13 -> V_14 ++ ;
F_55 ( & V_32 -> V_162 , V_160 ) ;
} else if ( V_173 -> type == V_59 ) {
V_209 = & V_13 -> V_189 [ V_187 -> V_188 . V_54 ] ;
V_209 -> V_160 &= ~ V_166 ;
F_54 ( & V_32 -> V_162 , V_160 ) ;
F_77 ( V_187 -> V_188 . V_54 , & V_13 -> V_206 ) ;
F_76 ( & V_209 -> V_165 , & V_13 -> V_204 ) ;
V_13 -> V_18 ++ ;
F_55 ( & V_32 -> V_162 , V_160 ) ;
} else {
F_19 ( L_45 , V_173 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_32 ( V_32 -> V_98 , V_104 , V_32 ) ;
}
struct V_210 * F_78 ( void )
{
return & V_211 ;
}
struct V_212 * F_79 ( void )
{
return & V_213 ;
}
const struct V_214 * F_80 ( void )
{
return & V_215 ;
}
int F_81 ( struct V_12 * V_13 )
{
struct V_216 V_217 ;
int V_5 ;
F_82 ( & V_13 -> V_197 , V_218 ) ;
if ( V_13 -> V_197 . error ) {
F_19 ( L_46 ) ;
return V_13 -> V_197 . error ;
}
for ( V_5 = 0 ; V_5 < V_218 ; V_5 ++ ) {
if ( F_83 ( V_219 [ V_5 ] . V_130 ) ) {
memset ( & V_217 , 0 , sizeof( struct V_216 ) ) ;
V_217 . V_220 = & V_221 ;
V_217 . V_130 = V_219 [ V_5 ] . V_130 ;
V_217 . V_222 = V_219 [ V_5 ] . V_223 ;
V_217 . V_224 = V_219 [ V_5 ] . V_225 ;
V_217 . V_226 = V_219 [ V_5 ] . V_227 ;
V_217 . V_35 = V_219 [ V_5 ] . V_35 ;
V_217 . type = V_219 [ V_5 ] . type ;
V_217 . V_228 = V_219 [ V_5 ] . V_228 ;
V_217 . V_229 = 0 ;
V_13 -> V_230 [ V_5 ] = F_84 ( & V_13 -> V_197 ,
& V_217 , NULL ) ;
} else {
V_13 -> V_230 [ V_5 ] = F_85 ( & V_13 -> V_197 ,
& V_221 ,
V_219 [ V_5 ] . V_130 , V_219 [ V_5 ] . V_223 ,
V_219 [ V_5 ] . V_225 , V_219 [ V_5 ] . V_228 ,
V_219 [ V_5 ] . V_227 ) ;
}
if ( V_13 -> V_197 . error ) {
F_19 ( L_47 , V_5 ) ;
return V_13 -> V_197 . error ;
}
if ( V_219 [ V_5 ] . V_231 && V_13 -> V_230 [ V_5 ] )
V_13 -> V_230 [ V_5 ] -> V_160 |= V_232 ;
}
return 0 ;
}
void F_86 ( struct V_12 * V_13 )
{
int V_5 ;
F_87 ( & V_13 -> V_197 ) ;
for ( V_5 = 0 ; V_5 < V_218 ; V_5 ++ )
V_13 -> V_230 [ V_5 ] = NULL ;
}
void F_88 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_147 ;
V_13 -> V_76 = F_1 ( & V_3 , V_49 ) ;
if ( F_89 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_233 ;
else if ( F_61 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_234 ;
else
V_3 . V_9 . V_10 . V_11 = V_235 ;
V_13 -> V_68 = F_1 ( & V_3 , V_50 ) ;
F_3 ( 2 , L_48 ,
( unsigned int ) V_13 -> V_76 , ( unsigned int ) V_13 -> V_68 ) ;
}
