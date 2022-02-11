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
V_30 -> V_38 = V_39 | V_40 ;
V_30 -> V_41 = V_30 -> V_38 | V_42 ;
return 0 ;
}
static int F_6 ( struct V_27 * V_27 , struct V_43 * V_3 ,
bool V_44 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
int V_5 , V_45 = 0 ;
for ( V_5 = 0 ; V_5 < F_7 ( V_7 ) ; ++ V_5 ) {
if ( V_44 && V_7 [ V_5 ] . type != V_46 )
continue;
else if ( ! V_44 && V_7 [ V_5 ] . type != V_47 )
continue;
else if ( ( V_32 -> V_48 -> V_49 & V_7 [ V_5 ] . V_50 ) == 0 )
continue;
if ( V_45 == V_3 -> V_51 )
break;
++ V_45 ;
}
if ( V_5 == F_7 ( V_7 ) )
return - V_52 ;
V_9 = & V_7 [ V_5 ] ;
F_8 ( V_3 -> V_53 , V_9 -> V_35 , sizeof( V_3 -> V_53 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
static int F_9 ( struct V_27 * V_27 , void * V_54 ,
struct V_43 * V_3 )
{
return F_6 ( V_27 , V_3 , false ) ;
}
static int F_10 ( struct V_27 * V_27 , void * V_28 ,
struct V_43 * V_3 )
{
return F_6 ( V_27 , V_3 , true ) ;
}
static int F_11 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
struct V_55 * V_10 ;
F_13 () ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_56 &&
( V_13 -> V_15 == V_16 || V_13 -> V_15 ==
V_26 ) ) {
F_14 ( V_13 , V_57 ,
0 ) ;
}
if ( V_3 -> type == V_56 &&
V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_10 -> V_59 = V_13 -> V_60 ;
V_10 -> V_61 = V_13 -> V_62 ;
V_10 -> V_63 = V_64 ;
V_10 -> V_65 = 2 ;
V_10 -> V_11 = V_13 -> V_66 -> V_8 ;
V_10 -> V_67 [ 0 ] . V_68 = V_13 -> V_60 ;
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_70 ;
V_10 -> V_67 [ 1 ] . V_68 = V_13 -> V_60 ;
V_10 -> V_67 [ 1 ] . V_69 = V_13 -> V_71 ;
} else if ( V_3 -> type == V_72 ) {
V_10 -> V_59 = 0 ;
V_10 -> V_61 = 0 ;
V_10 -> V_63 = V_64 ;
V_10 -> V_67 [ 0 ] . V_68 = V_13 -> V_73 ;
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_73 ;
V_10 -> V_11 = V_13 -> V_74 -> V_8 ;
V_10 -> V_65 = V_13 -> V_74 -> V_65 ;
} else {
F_15 ( L_2 ) ;
F_3 ( 2 , L_3 , V_75 ) ;
return - V_52 ;
}
F_16 () ;
return 0 ;
}
static int F_17 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
F_3 ( 2 , L_4 , V_3 -> type ) ;
if ( V_3 -> type == V_72 ) {
V_9 = F_1 ( V_3 , V_46 ) ;
if ( ! V_9 ) {
F_15 ( L_5 ) ;
return - V_52 ;
}
if ( V_9 -> V_76 == V_77 ) {
F_15 ( L_6 ) ;
return - V_52 ;
}
if ( ( V_32 -> V_48 -> V_49 & V_9 -> V_50 ) == 0 ) {
F_15 ( L_7 ) ;
return - V_52 ;
}
} else if ( V_3 -> type == V_56 ) {
V_9 = F_1 ( V_3 , V_47 ) ;
if ( ! V_9 ) {
F_15 ( L_8 ) ;
return - V_52 ;
}
if ( ( V_32 -> V_48 -> V_49 & V_9 -> V_50 ) == 0 ) {
F_15 ( L_7 ) ;
return - V_52 ;
}
}
return 0 ;
}
static int F_18 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_12 ( V_28 ) ;
int V_78 = 0 ;
struct V_55 * V_10 ;
struct V_79 * V_80 = V_32 -> V_48 -> V_80 ;
F_13 () ;
V_78 = F_17 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_78 )
return V_78 ;
if ( V_13 -> V_81 . V_82 || V_13 -> V_83 . V_82 ) {
F_19 ( & V_32 -> V_84 , L_9 , V_75 ) ;
V_78 = - V_85 ;
goto V_44;
}
if ( V_3 -> type == V_56 ) {
V_13 -> V_66 = F_1 ( V_3 , V_47 ) ;
V_78 = 0 ;
goto V_44;
} else if ( V_3 -> type == V_72 ) {
V_13 -> V_74 = F_1 ( V_3 , V_46 ) ;
V_13 -> V_76 = V_13 -> V_74 -> V_76 ;
F_3 ( 2 , L_10 , V_13 -> V_76 ) ;
V_10 -> V_61 = 0 ;
V_10 -> V_59 = 0 ;
if ( V_10 -> V_67 [ 0 ] . V_69 == 0 )
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_73 =
V_86 ;
else if ( V_10 -> V_67 [ 0 ] . V_69 > V_80 -> V_87 )
V_13 -> V_73 = V_80 -> V_87 ;
else
V_13 -> V_73 = V_10 -> V_67 [ 0 ] . V_69 ;
V_10 -> V_67 [ 0 ] . V_68 = 0 ;
V_13 -> V_15 = V_88 ;
V_78 = 0 ;
goto V_44;
} else {
F_15 ( L_11 , V_3 -> type ) ;
V_78 = - V_52 ;
goto V_44;
}
V_44:
F_16 () ;
return V_78 ;
}
static int F_20 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_89 * V_90 )
{
int V_78 = 0 ;
F_21 () ;
if ( V_90 -> V_91 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_78 = F_22 ( & V_13 -> V_81 , V_90 ) ;
if ( V_78 )
goto V_44;
F_23 ( V_32 , V_13 ) ;
V_13 -> V_92 = 0 ;
V_13 -> V_93 = V_94 ;
} else if ( V_13 -> V_93 == V_94 ) {
F_24 ( V_13 -> V_92 != 0 ) ;
if ( V_13 -> V_15 != V_88 ) {
F_15 ( L_13 ) ;
V_78 = - V_52 ;
goto V_44;
}
F_3 ( 2 , L_14 ,
V_90 -> V_91 ) ;
V_78 = F_22 ( & V_13 -> V_81 , V_90 ) ;
if ( V_78 )
goto V_44;
V_78 = F_25 ( V_32 , V_13 ) ;
if ( V_78 ) {
V_90 -> V_91 = 0 ;
F_22 ( & V_13 -> V_81 , V_90 ) ;
goto V_44;
}
V_13 -> V_93 = V_95 ;
} else {
F_15 ( L_15 ) ;
V_78 = - V_52 ;
}
V_44:
F_26 () ;
if ( V_78 )
F_15 ( L_16 ) ;
return V_78 ;
}
static int F_27 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_89 * V_90 )
{
int V_78 = 0 ;
F_21 () ;
if ( V_90 -> V_91 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_78 = F_22 ( & V_13 -> V_83 , V_90 ) ;
if ( V_78 )
goto V_44;
F_28 ( V_32 -> V_96 , V_97 , V_13 ) ;
V_13 -> V_98 = 0 ;
} else if ( V_13 -> V_22 == V_94 ) {
F_24 ( V_13 -> V_98 != 0 ) ;
F_3 ( 2 , L_17 ,
V_90 -> V_91 ) ;
V_78 = F_22 ( & V_13 -> V_83 , V_90 ) ;
if ( V_78 )
goto V_44;
V_13 -> V_22 = V_95 ;
V_13 -> V_99 = V_90 -> V_91 ;
V_78 = F_29 ( V_32 -> V_96 , V_100 , V_13 ) ;
if ( V_78 ) {
F_15 ( L_18 ) ;
V_90 -> V_91 = 0 ;
F_22 ( & V_13 -> V_83 , V_90 ) ;
V_78 = - V_101 ;
V_13 -> V_22 = V_94 ;
goto V_44;
}
F_24 ( V_13 -> V_98 != V_13 -> V_99 ) ;
V_13 -> V_22 = V_23 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
F_14 ( V_13 , V_103 ,
0 ) ;
} else {
F_15 ( L_15 ) ;
V_78 = - V_52 ;
}
V_44:
F_26 () ;
if ( V_78 )
F_15 ( L_19 ) ;
return V_78 ;
}
static int F_31 ( struct V_27 * V_27 , void * V_28 ,
struct V_89 * V_90 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_12 ( V_28 ) ;
if ( V_90 -> V_104 != V_105 ) {
F_15 ( L_20 ) ;
return - V_52 ;
}
if ( V_90 -> type == V_72 ) {
return F_20 ( V_32 , V_13 , V_90 ) ;
} else if ( V_90 -> type == V_56 ) {
return F_27 ( V_32 , V_13 , V_90 ) ;
} else {
F_15 ( L_21 ) ;
return - V_52 ;
}
}
static int F_32 ( struct V_27 * V_27 , void * V_28 ,
struct V_106 * V_107 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
int V_78 ;
int V_5 ;
if ( V_107 -> V_104 != V_105 ) {
F_15 ( L_22 ) ;
return - V_52 ;
}
F_3 ( 2 , L_23 , V_13 -> V_15 , V_107 -> type ) ;
if ( V_13 -> V_15 == V_16 &&
V_107 -> type == V_72 ) {
V_78 = F_33 ( & V_13 -> V_81 , V_107 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_107 -> type == V_56 ) {
V_78 = F_33 ( & V_13 -> V_83 , V_107 ) ;
for ( V_5 = 0 ; V_5 < V_107 -> V_108 ; V_5 ++ )
V_107 -> V_109 . V_110 [ V_5 ] . V_109 . V_111 += V_112 ;
} else {
F_15 ( L_24 ) ;
V_78 = - V_52 ;
}
F_16 () ;
return V_78 ;
}
static int F_34 ( struct V_27 * V_27 , void * V_28 , struct V_106 * V_107 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
if ( V_13 -> V_15 == V_113 ) {
F_15 ( L_25 ) ;
return - V_114 ;
}
if ( V_107 -> type == V_72 )
return F_35 ( & V_13 -> V_81 , V_107 ) ;
else if ( V_107 -> type == V_56 )
return F_35 ( & V_13 -> V_83 , V_107 ) ;
return - V_52 ;
}
static int F_36 ( struct V_27 * V_27 , void * V_28 , struct V_106 * V_107 )
{
const struct V_115 V_116 = {
. type = V_117
} ;
struct V_12 * V_13 = F_12 ( V_28 ) ;
int V_78 ;
if ( V_13 -> V_15 == V_113 ) {
F_15 ( L_26 ) ;
return - V_114 ;
}
if ( V_107 -> type == V_72 )
V_78 = F_37 ( & V_13 -> V_81 , V_107 , V_27 -> V_118 & V_119 ) ;
else if ( V_107 -> type == V_56 ) {
V_78 = F_37 ( & V_13 -> V_83 , V_107 , V_27 -> V_118 & V_119 ) ;
if ( V_78 == 0 && V_13 -> V_15 == V_120 &&
F_38 ( & V_13 -> V_83 . V_121 ) )
F_39 ( & V_13 -> V_122 , & V_116 ) ;
} else {
V_78 = - V_52 ;
}
return V_78 ;
}
static int F_40 ( struct V_27 * V_27 , void * V_28 ,
struct V_123 * V_124 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
if ( V_124 -> type == V_72 )
return F_41 ( & V_13 -> V_81 , V_124 ) ;
if ( V_124 -> type == V_56 )
return F_41 ( & V_13 -> V_83 , V_124 ) ;
return - V_52 ;
}
static int F_42 ( struct V_27 * V_27 , void * V_28 ,
enum V_125 type )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
int V_78 = - V_52 ;
F_13 () ;
if ( type == V_72 )
V_78 = F_43 ( & V_13 -> V_81 , type ) ;
else if ( type == V_56 )
V_78 = F_43 ( & V_13 -> V_83 , type ) ;
F_16 () ;
return V_78 ;
}
static int F_44 ( struct V_27 * V_27 , void * V_28 ,
enum V_125 type )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
if ( type == V_72 )
return F_45 ( & V_13 -> V_81 , type ) ;
else if ( type == V_56 )
return F_45 ( & V_13 -> V_83 , type ) ;
return - V_52 ;
}
static int F_46 ( struct V_126 * V_127 )
{
struct V_12 * V_13 = F_47 ( V_127 ) ;
switch ( V_127 -> V_128 ) {
case V_129 :
V_13 -> V_130 = V_127 -> V_131 ;
break;
case V_132 :
V_13 -> V_133 = V_127 -> V_131 ;
break;
case V_134 :
V_13 -> V_135 = V_127 -> V_131 ;
break;
case V_136 :
V_13 -> V_137 = V_127 -> V_131 ;
break;
default:
F_15 ( L_27 , V_127 -> V_128 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_48 ( struct V_126 * V_127 )
{
struct V_12 * V_13 = F_47 ( V_127 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_127 -> V_128 ) {
case V_138 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_127 -> V_131 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_88 &&
V_13 -> V_15 != V_26 ) {
F_19 ( & V_32 -> V_84 , L_28 ) ;
return - V_52 ;
}
F_14 ( V_13 ,
V_57 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_127 -> V_131 = V_13 -> V_19 ;
} else {
F_19 ( & V_32 -> V_84 , L_28 ) ;
return - V_52 ;
}
break;
}
return 0 ;
}
static int F_49 ( struct V_27 * V_27 , void * V_28 ,
struct V_139 * V_140 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_141 , V_142 , V_143 , V_144 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_120 ) {
F_15 ( L_29 ) ;
return - V_52 ;
}
if ( V_13 -> V_74 -> V_8 == V_145 ) {
V_141 = F_29 ( V_32 -> V_96 , V_146 , V_13 ) ;
V_142 = V_141 >> V_147 ;
V_141 = V_141 & V_148 ;
V_143 = F_29 ( V_32 -> V_96 , V_149 , V_13 ) ;
V_144 = V_143 >> V_150 ;
V_143 = V_143 & V_151 ;
V_140 -> V_152 . V_141 = V_141 ;
V_140 -> V_152 . V_143 = V_143 ;
V_140 -> V_152 . V_59 = V_13 -> V_153 - V_141 - V_142 ;
V_140 -> V_152 . V_61 = V_13 -> V_154 - V_143 - V_144 ;
F_3 ( 2 , L_30
L_31 , V_141 , V_143 ,
V_140 -> V_152 . V_59 , V_140 -> V_152 . V_61 , V_142 , V_144 ,
V_13 -> V_60 , V_13 -> V_62 ) ;
} else {
V_140 -> V_152 . V_141 = 0 ;
V_140 -> V_152 . V_143 = 0 ;
V_140 -> V_152 . V_59 = V_13 -> V_153 ;
V_140 -> V_152 . V_61 = V_13 -> V_154 ;
F_3 ( 2 , L_32
L_33 , V_140 -> V_152 . V_59 , V_140 -> V_152 . V_61 , V_13 -> V_60 ,
V_13 -> V_62 ) ;
}
return 0 ;
}
static int F_50 ( struct V_27 * V_27 , void * V_28 ,
struct V_155 * V_156 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_157 * V_107 ;
unsigned long V_158 ;
switch ( V_156 -> V_156 ) {
case V_159 :
if ( V_156 -> V_158 != 0 )
return - V_52 ;
if ( ! V_13 -> V_81 . V_82 )
return - V_52 ;
F_51 ( & V_32 -> V_160 , V_158 ) ;
if ( F_38 ( & V_13 -> V_161 ) ) {
F_15 ( L_34 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_52 ( & V_32 -> V_160 , V_158 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
} else {
F_15 ( L_35 ) ;
V_107 = F_53 ( V_13 -> V_161 . V_162 ,
struct V_157 , V_163 ) ;
if ( V_107 -> V_158 & V_164 )
V_13 -> V_15 = V_20 ;
else
V_107 -> V_158 |= V_165 ;
F_52 ( & V_32 -> V_160 , V_158 ) ;
}
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_54 ( struct V_166 * V_122 ,
const struct V_167 * V_168 )
{
switch ( V_168 -> type ) {
case V_117 :
return F_55 ( V_122 , V_168 , 2 , NULL ) ;
case V_169 :
return F_56 ( V_122 , V_168 ) ;
default:
return - V_52 ;
}
}
static int F_57 ( struct V_170 * V_171 ,
const struct V_2 * V_9 , unsigned int * V_172 ,
unsigned int * V_173 , unsigned int V_174 [] ,
void * V_175 [] )
{
struct V_12 * V_13 = F_12 ( V_171 -> V_176 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_88 &&
V_171 -> type == V_72 ) {
* V_173 = 1 ;
if ( * V_172 < 1 )
* V_172 = 1 ;
if ( * V_172 > V_177 )
* V_172 = V_177 ;
} else if ( V_13 -> V_15 == V_21 &&
V_171 -> type == V_56 ) {
* V_173 = 2 ;
if ( * V_172 < V_13 -> V_19 )
* V_172 = V_13 -> V_19 ;
if ( * V_172 > V_13 -> V_19 + V_178 )
* V_172 = V_13 -> V_19 + V_178 ;
if ( * V_172 > V_177 )
* V_172 = V_177 ;
} else {
F_15 ( L_36 ,
V_13 -> V_15 , V_171 -> type ) ;
return - V_52 ;
}
F_3 ( 2 , L_37 ,
* V_172 , * V_173 ) ;
if ( V_13 -> V_15 == V_21 &&
V_171 -> type == V_56 ) {
V_174 [ 0 ] = V_13 -> V_70 ;
V_174 [ 1 ] = V_13 -> V_71 ;
if ( F_58 ( V_32 ) )
V_175 [ 0 ] =
V_13 -> V_32 -> V_179 [ V_180 ] ;
else
V_175 [ 0 ] =
V_13 -> V_32 -> V_179 [ V_181 ] ;
V_175 [ 1 ] = V_13 -> V_32 -> V_179 [ V_180 ] ;
} else if ( V_171 -> type == V_72 &&
V_13 -> V_15 == V_88 ) {
V_174 [ 0 ] = V_13 -> V_73 ;
V_175 [ 0 ] = V_13 -> V_32 -> V_179 [ V_180 ] ;
} else {
F_15 ( L_38 ) ;
return - V_52 ;
}
return 0 ;
}
static void F_59 ( struct V_170 * V_182 )
{
struct V_12 * V_13 = F_12 ( V_182 -> V_176 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_60 ( & V_32 -> V_183 ) ;
}
static void F_61 ( struct V_170 * V_182 )
{
struct V_12 * V_13 = F_12 ( V_182 -> V_176 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_62 ( & V_32 -> V_183 ) ;
}
static int F_63 ( struct V_184 * V_185 )
{
struct V_170 * V_171 = V_185 -> V_170 ;
struct V_12 * V_13 = F_12 ( V_171 -> V_176 ) ;
unsigned int V_5 ;
if ( V_171 -> type == V_56 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_13 -> V_66 -> V_65 ; V_5 ++ ) {
if ( F_64 ( F_65 (
F_66 ( V_185 , V_5 ) ) ) ) {
F_15 ( L_39 ) ;
return - V_52 ;
}
}
if ( F_67 ( V_185 , 0 ) < V_13 -> V_70 ||
F_67 ( V_185 , 1 ) < V_13 -> V_71 ) {
F_15 ( L_40 ) ;
return - V_52 ;
}
V_5 = V_185 -> V_186 . V_51 ;
V_13 -> V_187 [ V_5 ] . V_188 = V_185 ;
V_13 -> V_187 [ V_5 ] . V_189 . V_190 . V_191 =
F_66 ( V_185 , 0 ) ;
V_13 -> V_187 [ V_5 ] . V_189 . V_190 . V_192 =
F_66 ( V_185 , 1 ) ;
V_13 -> V_98 ++ ;
} else if ( V_171 -> type == V_72 ) {
if ( F_64 ( F_65 (
F_66 ( V_185 , 0 ) ) ) ) {
F_15 ( L_41 ) ;
return - V_52 ;
}
if ( F_67 ( V_185 , 0 ) < V_13 -> V_73 ) {
F_15 ( L_42 ) ;
return - V_52 ;
}
V_5 = V_185 -> V_186 . V_51 ;
V_13 -> V_193 [ V_5 ] . V_188 = V_185 ;
V_13 -> V_193 [ V_5 ] . V_189 . V_194 =
F_66 ( V_185 , 0 ) ;
V_13 -> V_92 ++ ;
} else {
F_15 ( L_43 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_68 ( struct V_170 * V_182 , unsigned int V_91 )
{
struct V_12 * V_13 = F_12 ( V_182 -> V_176 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_69 ( & V_13 -> V_195 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_120 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
return 0 ;
}
static void F_70 ( struct V_170 * V_182 )
{
unsigned long V_158 ;
struct V_12 * V_13 = F_12 ( V_182 -> V_176 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_196 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_197 == V_13 -> V_198 && V_32 -> V_199 ) {
V_13 -> V_15 = V_58 ;
F_14 ( V_13 ,
V_200 , 0 ) ;
V_196 = 1 ;
}
if ( V_182 -> type == V_56 ) {
F_51 ( & V_32 -> V_160 , V_158 ) ;
F_28 ( V_32 -> V_96 , V_201 ,
& V_13 -> V_202 , & V_13 -> V_83 ) ;
F_71 ( & V_13 -> V_202 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_203 = 1 ;
V_13 -> V_204 = 0 ;
F_52 ( & V_32 -> V_160 , V_158 ) ;
if ( F_58 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_205 ;
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
if ( F_14 ( V_13 ,
V_206 , 0 ) )
F_15 ( L_44 ) ;
}
}
if ( V_182 -> type == V_72 ) {
F_51 ( & V_32 -> V_160 , V_158 ) ;
F_28 ( V_32 -> V_96 , V_201 ,
& V_13 -> V_161 , & V_13 -> V_81 ) ;
F_71 ( & V_13 -> V_161 ) ;
V_13 -> V_14 = 0 ;
F_52 ( & V_32 -> V_160 , V_158 ) ;
}
if ( V_196 )
V_13 -> V_15 = V_17 ;
}
static void F_72 ( struct V_184 * V_185 )
{
struct V_170 * V_171 = V_185 -> V_170 ;
struct V_12 * V_13 = F_12 ( V_171 -> V_176 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_158 ;
struct V_157 * V_207 ;
if ( V_171 -> type == V_72 ) {
V_207 = & V_13 -> V_193 [ V_185 -> V_186 . V_51 ] ;
V_207 -> V_158 &= ~ V_164 ;
F_51 ( & V_32 -> V_160 , V_158 ) ;
F_73 ( & V_207 -> V_163 , & V_13 -> V_161 ) ;
V_13 -> V_14 ++ ;
F_52 ( & V_32 -> V_160 , V_158 ) ;
} else if ( V_171 -> type == V_56 ) {
V_207 = & V_13 -> V_187 [ V_185 -> V_186 . V_51 ] ;
V_207 -> V_158 &= ~ V_164 ;
F_51 ( & V_32 -> V_160 , V_158 ) ;
F_74 ( V_185 -> V_186 . V_51 , & V_13 -> V_204 ) ;
F_73 ( & V_207 -> V_163 , & V_13 -> V_202 ) ;
V_13 -> V_18 ++ ;
F_52 ( & V_32 -> V_160 , V_158 ) ;
} else {
F_15 ( L_45 , V_171 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
}
struct V_208 * F_75 ( void )
{
return & V_209 ;
}
struct V_210 * F_76 ( void )
{
return & V_211 ;
}
const struct V_212 * F_77 ( void )
{
return & V_213 ;
}
int F_78 ( struct V_12 * V_13 )
{
struct V_214 V_215 ;
int V_5 ;
F_79 ( & V_13 -> V_195 , V_216 ) ;
if ( V_13 -> V_195 . error ) {
F_15 ( L_46 ) ;
return V_13 -> V_195 . error ;
}
for ( V_5 = 0 ; V_5 < V_216 ; V_5 ++ ) {
if ( F_80 ( V_217 [ V_5 ] . V_128 ) ) {
memset ( & V_215 , 0 , sizeof( struct V_214 ) ) ;
V_215 . V_218 = & V_219 ;
V_215 . V_128 = V_217 [ V_5 ] . V_128 ;
V_215 . V_220 = V_217 [ V_5 ] . V_221 ;
V_215 . V_222 = V_217 [ V_5 ] . V_223 ;
V_215 . V_224 = V_217 [ V_5 ] . V_225 ;
V_215 . V_35 = V_217 [ V_5 ] . V_35 ;
V_215 . type = V_217 [ V_5 ] . type ;
V_215 . V_226 = V_217 [ V_5 ] . V_226 ;
V_215 . V_227 = 0 ;
V_13 -> V_228 [ V_5 ] = F_81 ( & V_13 -> V_195 ,
& V_215 , NULL ) ;
} else {
V_13 -> V_228 [ V_5 ] = F_82 ( & V_13 -> V_195 ,
& V_219 ,
V_217 [ V_5 ] . V_128 , V_217 [ V_5 ] . V_221 ,
V_217 [ V_5 ] . V_223 , V_217 [ V_5 ] . V_226 ,
V_217 [ V_5 ] . V_225 ) ;
}
if ( V_13 -> V_195 . error ) {
F_15 ( L_47 , V_5 ) ;
return V_13 -> V_195 . error ;
}
if ( V_217 [ V_5 ] . V_229 && V_13 -> V_228 [ V_5 ] )
V_13 -> V_228 [ V_5 ] -> V_158 |= V_230 ;
}
return 0 ;
}
void F_83 ( struct V_12 * V_13 )
{
int V_5 ;
F_84 ( & V_13 -> V_195 ) ;
for ( V_5 = 0 ; V_5 < V_216 ; V_5 ++ )
V_13 -> V_228 [ V_5 ] = NULL ;
}
void F_85 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_145 ;
V_13 -> V_74 = F_1 ( & V_3 , V_46 ) ;
if ( F_86 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_231 ;
else if ( F_58 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_232 ;
else
V_3 . V_9 . V_10 . V_11 = V_233 ;
V_13 -> V_66 = F_1 ( & V_3 , V_47 ) ;
F_3 ( 2 , L_48 ,
V_13 -> V_74 , V_13 -> V_66 ) ;
}
