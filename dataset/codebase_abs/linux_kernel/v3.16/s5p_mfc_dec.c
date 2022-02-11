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
F_16 () ;
V_80 = F_21 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_80 )
return V_80 ;
if ( V_13 -> V_81 . V_82 || V_13 -> V_83 . V_82 ) {
F_23 ( & V_32 -> V_84 , L_9 , V_77 ) ;
V_80 = - V_85 ;
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
if ( V_10 -> V_69 [ 0 ] . V_71 )
V_13 -> V_75 = V_10 -> V_69 [ 0 ] . V_71 ;
else
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_75 =
V_86 ;
V_10 -> V_69 [ 0 ] . V_70 = 0 ;
V_13 -> V_15 = V_87 ;
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
struct V_88 * V_89 )
{
int V_80 = 0 ;
F_25 () ;
if ( V_89 -> V_90 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_80 = F_26 ( & V_13 -> V_81 , V_89 ) ;
if ( V_80 )
goto V_46;
F_27 ( V_32 , V_13 ) ;
V_13 -> V_91 = 0 ;
V_13 -> V_92 = V_93 ;
} else if ( V_13 -> V_92 == V_93 ) {
F_28 ( V_13 -> V_91 != 0 ) ;
if ( V_13 -> V_15 != V_87 ) {
F_19 ( L_13 ) ;
V_80 = - V_55 ;
goto V_46;
}
F_3 ( 2 , L_14 ,
V_89 -> V_90 ) ;
V_80 = F_26 ( & V_13 -> V_81 , V_89 ) ;
if ( V_80 )
goto V_46;
V_80 = F_29 ( V_32 , V_13 ) ;
if ( V_80 ) {
V_89 -> V_90 = 0 ;
F_26 ( & V_13 -> V_81 , V_89 ) ;
goto V_46;
}
V_13 -> V_92 = V_94 ;
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
struct V_88 * V_89 )
{
int V_80 = 0 ;
F_25 () ;
if ( V_89 -> V_90 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_80 = F_26 ( & V_13 -> V_83 , V_89 ) ;
if ( V_80 )
goto V_46;
F_32 ( V_32 -> V_95 , V_96 , V_13 ) ;
V_13 -> V_97 = 0 ;
} else if ( V_13 -> V_22 == V_93 ) {
F_28 ( V_13 -> V_97 != 0 ) ;
F_3 ( 2 , L_17 ,
V_89 -> V_90 ) ;
V_80 = F_26 ( & V_13 -> V_83 , V_89 ) ;
if ( V_80 )
goto V_46;
V_13 -> V_22 = V_94 ;
V_13 -> V_98 = V_89 -> V_90 ;
V_80 = F_32 ( V_32 -> V_95 , V_99 , V_13 ) ;
if ( V_80 ) {
F_19 ( L_18 ) ;
V_89 -> V_90 = 0 ;
F_26 ( & V_13 -> V_83 , V_89 ) ;
V_80 = - V_100 ;
V_13 -> V_22 = V_93 ;
goto V_46;
}
F_28 ( V_13 -> V_97 != V_13 -> V_98 ) ;
V_13 -> V_22 = V_23 ;
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_32 ( V_32 -> V_95 , V_101 , V_32 ) ;
F_18 ( V_13 , V_102 ,
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
struct V_88 * V_89 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_89 -> V_103 != V_104 ) {
F_19 ( L_20 ) ;
return - V_55 ;
}
if ( V_89 -> type == V_74 ) {
return F_24 ( V_32 , V_13 , V_89 ) ;
} else if ( V_89 -> type == V_59 ) {
return F_31 ( V_32 , V_13 , V_89 ) ;
} else {
F_19 ( L_21 ) ;
return - V_55 ;
}
}
static int F_35 ( struct V_27 * V_27 , void * V_28 ,
struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 ;
int V_5 ;
if ( V_106 -> V_103 != V_104 ) {
F_19 ( L_22 ) ;
return - V_55 ;
}
F_3 ( 2 , L_23 , V_13 -> V_15 , V_106 -> type ) ;
if ( V_13 -> V_15 == V_16 &&
V_106 -> type == V_74 ) {
V_80 = F_36 ( & V_13 -> V_81 , V_106 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_106 -> type == V_59 ) {
V_80 = F_36 ( & V_13 -> V_83 , V_106 ) ;
for ( V_5 = 0 ; V_5 < V_106 -> V_107 ; V_5 ++ )
V_106 -> V_108 . V_109 [ V_5 ] . V_108 . V_110 += V_111 ;
} else {
F_19 ( L_24 ) ;
V_80 = - V_55 ;
}
F_20 () ;
return V_80 ;
}
static int F_37 ( struct V_27 * V_27 , void * V_28 , struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_112 ) {
F_19 ( L_25 ) ;
return - V_113 ;
}
if ( V_106 -> type == V_74 )
return F_38 ( & V_13 -> V_81 , V_106 ) ;
else if ( V_106 -> type == V_59 )
return F_38 ( & V_13 -> V_83 , V_106 ) ;
return - V_55 ;
}
static int F_39 ( struct V_27 * V_27 , void * V_28 , struct V_105 * V_106 )
{
const struct V_114 V_115 = {
. type = V_116
} ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 ;
if ( V_13 -> V_15 == V_112 ) {
F_19 ( L_26 ) ;
return - V_113 ;
}
if ( V_106 -> type == V_74 )
V_80 = F_40 ( & V_13 -> V_81 , V_106 , V_27 -> V_117 & V_118 ) ;
else if ( V_106 -> type == V_59 ) {
V_80 = F_40 ( & V_13 -> V_83 , V_106 , V_27 -> V_117 & V_118 ) ;
if ( V_80 == 0 && V_13 -> V_15 == V_119 &&
F_41 ( & V_13 -> V_83 . V_120 ) )
F_42 ( & V_13 -> V_121 , & V_115 ) ;
} else {
V_80 = - V_55 ;
}
return V_80 ;
}
static int F_43 ( struct V_27 * V_27 , void * V_28 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_123 -> type == V_74 )
return F_44 ( & V_13 -> V_81 , V_123 ) ;
if ( V_123 -> type == V_59 )
return F_44 ( & V_13 -> V_83 , V_123 ) ;
return - V_55 ;
}
static int F_45 ( struct V_27 * V_27 , void * V_28 ,
enum V_124 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 = - V_55 ;
F_16 () ;
if ( type == V_74 )
V_80 = F_46 ( & V_13 -> V_81 , type ) ;
else if ( type == V_59 )
V_80 = F_46 ( & V_13 -> V_83 , type ) ;
F_20 () ;
return V_80 ;
}
static int F_47 ( struct V_27 * V_27 , void * V_28 ,
enum V_124 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( type == V_74 )
return F_48 ( & V_13 -> V_81 , type ) ;
else if ( type == V_59 )
return F_48 ( & V_13 -> V_83 , type ) ;
return - V_55 ;
}
static int F_49 ( struct V_125 * V_126 )
{
struct V_12 * V_13 = F_50 ( V_126 ) ;
switch ( V_126 -> V_127 ) {
case V_128 :
V_13 -> V_129 = V_126 -> V_130 ;
break;
case V_131 :
V_13 -> V_132 = V_126 -> V_130 ;
break;
case V_133 :
V_13 -> V_134 = V_126 -> V_130 ;
break;
case V_135 :
V_13 -> V_136 = V_126 -> V_130 ;
break;
default:
F_19 ( L_27 , V_126 -> V_127 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_51 ( struct V_125 * V_126 )
{
struct V_12 * V_13 = F_50 ( V_126 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_126 -> V_127 ) {
case V_137 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_61 ) {
V_126 -> V_130 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_87 ) {
F_23 ( & V_32 -> V_84 , L_28 ) ;
return - V_55 ;
}
F_17 ( V_13 ) ;
F_18 ( V_13 ,
V_60 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_61 ) {
V_126 -> V_130 = V_13 -> V_19 ;
} else {
F_23 ( & V_32 -> V_84 , L_28 ) ;
return - V_55 ;
}
break;
}
return 0 ;
}
static int F_52 ( struct V_27 * V_27 , void * V_28 ,
struct V_138 * V_139 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_140 , V_141 , V_142 , V_143 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_119 ) {
F_19 ( L_29 ) ;
return - V_55 ;
}
if ( V_13 -> V_76 -> V_8 == V_144 ) {
V_140 = F_32 ( V_32 -> V_95 , V_145 , V_13 ) ;
V_141 = V_140 >> V_146 ;
V_140 = V_140 & V_147 ;
V_142 = F_32 ( V_32 -> V_95 , V_148 , V_13 ) ;
V_143 = V_142 >> V_149 ;
V_142 = V_142 & V_150 ;
V_139 -> V_151 . V_140 = V_140 ;
V_139 -> V_151 . V_142 = V_142 ;
V_139 -> V_151 . V_62 = V_13 -> V_152 - V_140 - V_141 ;
V_139 -> V_151 . V_64 = V_13 -> V_153 - V_142 - V_143 ;
F_3 ( 2 , L_30
L_31 , V_140 , V_142 ,
V_139 -> V_151 . V_62 , V_139 -> V_151 . V_64 , V_141 , V_143 ,
V_13 -> V_63 , V_13 -> V_65 ) ;
} else {
V_139 -> V_151 . V_140 = 0 ;
V_139 -> V_151 . V_142 = 0 ;
V_139 -> V_151 . V_62 = V_13 -> V_152 ;
V_139 -> V_151 . V_64 = V_13 -> V_153 ;
F_3 ( 2 , L_32
L_33 , V_139 -> V_151 . V_62 , V_139 -> V_151 . V_64 , V_13 -> V_63 ,
V_13 -> V_65 ) ;
}
return 0 ;
}
int F_53 ( struct V_27 * V_27 , void * V_28 ,
struct V_154 * V_155 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_156 * V_106 ;
unsigned long V_157 ;
switch ( V_155 -> V_155 ) {
case V_158 :
if ( V_155 -> V_157 != 0 )
return - V_55 ;
if ( ! V_13 -> V_81 . V_82 )
return - V_55 ;
F_54 ( & V_32 -> V_159 , V_157 ) ;
if ( F_41 ( & V_13 -> V_160 ) ) {
F_19 ( L_34 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_55 ( & V_32 -> V_159 , V_157 ) ;
F_32 ( V_32 -> V_95 , V_101 , V_32 ) ;
} else {
F_19 ( L_35 ) ;
V_106 = F_56 ( V_13 -> V_160 . V_161 ,
struct V_156 , V_162 ) ;
if ( V_106 -> V_157 & V_163 )
V_13 -> V_15 = V_20 ;
else
V_106 -> V_157 |= V_164 ;
F_55 ( & V_32 -> V_159 , V_157 ) ;
}
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_57 ( struct V_165 * V_121 ,
const struct V_166 * V_167 )
{
switch ( V_167 -> type ) {
case V_116 :
return F_58 ( V_121 , V_167 , 2 , NULL ) ;
case V_168 :
return F_59 ( V_121 , V_167 ) ;
default:
return - V_55 ;
}
}
static int F_60 ( struct V_169 * V_170 ,
const struct V_2 * V_9 , unsigned int * V_171 ,
unsigned int * V_172 , unsigned int V_173 [] ,
void * V_174 [] )
{
struct V_12 * V_13 = F_15 ( V_170 -> V_175 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_87 &&
V_170 -> type == V_74 ) {
* V_172 = 1 ;
if ( * V_171 < 1 )
* V_171 = 1 ;
if ( * V_171 > V_176 )
* V_171 = V_176 ;
} else if ( V_13 -> V_15 == V_21 &&
V_170 -> type == V_59 ) {
* V_172 = 2 ;
if ( * V_171 < V_13 -> V_19 )
* V_171 = V_13 -> V_19 ;
if ( * V_171 > V_13 -> V_19 + V_177 )
* V_171 = V_13 -> V_19 + V_177 ;
if ( * V_171 > V_176 )
* V_171 = V_176 ;
} else {
F_19 ( L_36 ,
V_13 -> V_15 , V_170 -> type ) ;
return - V_55 ;
}
F_3 ( 2 , L_37 ,
* V_171 , * V_172 ) ;
if ( V_13 -> V_15 == V_21 &&
V_170 -> type == V_59 ) {
V_173 [ 0 ] = V_13 -> V_72 ;
V_173 [ 1 ] = V_13 -> V_73 ;
if ( F_61 ( V_32 ) )
V_174 [ 0 ] =
V_13 -> V_32 -> V_178 [ V_179 ] ;
else
V_174 [ 0 ] =
V_13 -> V_32 -> V_178 [ V_180 ] ;
V_174 [ 1 ] = V_13 -> V_32 -> V_178 [ V_179 ] ;
} else if ( V_170 -> type == V_74 &&
V_13 -> V_15 == V_87 ) {
V_173 [ 0 ] = V_13 -> V_75 ;
V_174 [ 0 ] = V_13 -> V_32 -> V_178 [ V_179 ] ;
} else {
F_19 ( L_38 ) ;
return - V_55 ;
}
return 0 ;
}
static void F_62 ( struct V_169 * V_181 )
{
struct V_12 * V_13 = F_15 ( V_181 -> V_175 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_63 ( & V_32 -> V_182 ) ;
}
static void F_64 ( struct V_169 * V_181 )
{
struct V_12 * V_13 = F_15 ( V_181 -> V_175 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_65 ( & V_32 -> V_182 ) ;
}
static int F_66 ( struct V_183 * V_184 )
{
struct V_169 * V_170 = V_184 -> V_169 ;
struct V_12 * V_13 = F_15 ( V_170 -> V_175 ) ;
unsigned int V_5 ;
if ( V_170 -> type == V_59 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 <= V_13 -> V_76 -> V_48 ; V_5 ++ ) {
if ( F_67 ( F_68 (
F_69 ( V_184 , V_5 ) ) ) ) {
F_19 ( L_39 ) ;
return - V_55 ;
}
}
if ( F_70 ( V_184 , 0 ) < V_13 -> V_72 ||
F_70 ( V_184 , 1 ) < V_13 -> V_73 ) {
F_19 ( L_40 ) ;
return - V_55 ;
}
V_5 = V_184 -> V_185 . V_54 ;
V_13 -> V_186 [ V_5 ] . V_187 = V_184 ;
V_13 -> V_186 [ V_5 ] . V_188 . V_189 . V_190 =
F_69 ( V_184 , 0 ) ;
V_13 -> V_186 [ V_5 ] . V_188 . V_189 . V_191 =
F_69 ( V_184 , 1 ) ;
V_13 -> V_97 ++ ;
} else if ( V_170 -> type == V_74 ) {
if ( F_67 ( F_68 (
F_69 ( V_184 , 0 ) ) ) ) {
F_19 ( L_41 ) ;
return - V_55 ;
}
if ( F_70 ( V_184 , 0 ) < V_13 -> V_75 ) {
F_19 ( L_42 ) ;
return - V_55 ;
}
V_5 = V_184 -> V_185 . V_54 ;
V_13 -> V_192 [ V_5 ] . V_187 = V_184 ;
V_13 -> V_192 [ V_5 ] . V_188 . V_193 =
F_69 ( V_184 , 0 ) ;
V_13 -> V_91 ++ ;
} else {
F_19 ( L_43 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_71 ( struct V_169 * V_181 , unsigned int V_90 )
{
struct V_12 * V_13 = F_15 ( V_181 -> V_175 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_72 ( & V_13 -> V_194 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_119 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_32 ( V_32 -> V_95 , V_101 , V_32 ) ;
return 0 ;
}
static void F_73 ( struct V_169 * V_181 )
{
unsigned long V_157 ;
struct V_12 * V_13 = F_15 ( V_181 -> V_175 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_195 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_196 == V_13 -> V_197 && V_32 -> V_198 ) {
V_13 -> V_15 = V_61 ;
F_18 ( V_13 ,
V_199 , 0 ) ;
V_195 = 1 ;
}
if ( V_181 -> type == V_59 ) {
F_54 ( & V_32 -> V_159 , V_157 ) ;
F_32 ( V_32 -> V_95 , V_200 , & V_13 -> V_201 ,
& V_13 -> V_83 ) ;
F_74 ( & V_13 -> V_201 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_202 = 1 ;
V_13 -> V_203 = 0 ;
F_55 ( & V_32 -> V_159 , V_157 ) ;
if ( F_61 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_204 ;
F_33 ( V_13 ) ;
F_17 ( V_13 ) ;
F_32 ( V_32 -> V_95 , V_101 , V_32 ) ;
if ( F_18 ( V_13 ,
V_205 , 0 ) )
F_19 ( L_44 ) ;
}
}
if ( V_181 -> type == V_74 ) {
F_54 ( & V_32 -> V_159 , V_157 ) ;
F_32 ( V_32 -> V_95 , V_200 , & V_13 -> V_160 ,
& V_13 -> V_81 ) ;
F_74 ( & V_13 -> V_160 ) ;
V_13 -> V_14 = 0 ;
F_55 ( & V_32 -> V_159 , V_157 ) ;
}
if ( V_195 )
V_13 -> V_15 = V_17 ;
}
static void F_75 ( struct V_183 * V_184 )
{
struct V_169 * V_170 = V_184 -> V_169 ;
struct V_12 * V_13 = F_15 ( V_170 -> V_175 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_157 ;
struct V_156 * V_206 ;
if ( V_170 -> type == V_74 ) {
V_206 = & V_13 -> V_192 [ V_184 -> V_185 . V_54 ] ;
V_206 -> V_157 &= ~ V_163 ;
F_54 ( & V_32 -> V_159 , V_157 ) ;
F_76 ( & V_206 -> V_162 , & V_13 -> V_160 ) ;
V_13 -> V_14 ++ ;
F_55 ( & V_32 -> V_159 , V_157 ) ;
} else if ( V_170 -> type == V_59 ) {
V_206 = & V_13 -> V_186 [ V_184 -> V_185 . V_54 ] ;
V_206 -> V_157 &= ~ V_163 ;
F_54 ( & V_32 -> V_159 , V_157 ) ;
F_77 ( V_184 -> V_185 . V_54 , & V_13 -> V_203 ) ;
F_76 ( & V_206 -> V_162 , & V_13 -> V_201 ) ;
V_13 -> V_18 ++ ;
F_55 ( & V_32 -> V_159 , V_157 ) ;
} else {
F_19 ( L_45 , V_170 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_33 ( V_13 ) ;
F_32 ( V_32 -> V_95 , V_101 , V_32 ) ;
}
struct V_207 * F_78 ( void )
{
return & V_208 ;
}
struct V_209 * F_79 ( void )
{
return & V_210 ;
}
const struct V_211 * F_80 ( void )
{
return & V_212 ;
}
int F_81 ( struct V_12 * V_13 )
{
struct V_213 V_214 ;
int V_5 ;
F_82 ( & V_13 -> V_194 , V_215 ) ;
if ( V_13 -> V_194 . error ) {
F_19 ( L_46 ) ;
return V_13 -> V_194 . error ;
}
for ( V_5 = 0 ; V_5 < V_215 ; V_5 ++ ) {
if ( F_83 ( V_216 [ V_5 ] . V_127 ) ) {
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
V_214 . V_217 = & V_218 ;
V_214 . V_127 = V_216 [ V_5 ] . V_127 ;
V_214 . V_219 = V_216 [ V_5 ] . V_220 ;
V_214 . V_221 = V_216 [ V_5 ] . V_222 ;
V_214 . V_223 = V_216 [ V_5 ] . V_224 ;
V_214 . V_35 = V_216 [ V_5 ] . V_35 ;
V_214 . type = V_216 [ V_5 ] . type ;
V_214 . V_225 = V_216 [ V_5 ] . V_225 ;
V_214 . V_226 = 0 ;
V_13 -> V_227 [ V_5 ] = F_84 ( & V_13 -> V_194 ,
& V_214 , NULL ) ;
} else {
V_13 -> V_227 [ V_5 ] = F_85 ( & V_13 -> V_194 ,
& V_218 ,
V_216 [ V_5 ] . V_127 , V_216 [ V_5 ] . V_220 ,
V_216 [ V_5 ] . V_222 , V_216 [ V_5 ] . V_225 ,
V_216 [ V_5 ] . V_224 ) ;
}
if ( V_13 -> V_194 . error ) {
F_19 ( L_47 , V_5 ) ;
return V_13 -> V_194 . error ;
}
if ( V_216 [ V_5 ] . V_228 && V_13 -> V_227 [ V_5 ] )
V_13 -> V_227 [ V_5 ] -> V_157 |= V_229 ;
}
return 0 ;
}
void F_86 ( struct V_12 * V_13 )
{
int V_5 ;
F_87 ( & V_13 -> V_194 ) ;
for ( V_5 = 0 ; V_5 < V_215 ; V_5 ++ )
V_13 -> V_227 [ V_5 ] = NULL ;
}
void F_88 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_144 ;
V_13 -> V_76 = F_1 ( & V_3 , V_49 ) ;
if ( F_89 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_230 ;
else if ( F_61 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_231 ;
else
V_3 . V_9 . V_10 . V_11 = V_232 ;
V_13 -> V_68 = F_1 ( & V_3 , V_50 ) ;
F_3 ( 2 , L_48 ,
( unsigned int ) V_13 -> V_76 , ( unsigned int ) V_13 -> V_68 ) ;
}
