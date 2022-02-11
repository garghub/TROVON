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
switch ( V_107 -> type ) {
case V_72 :
return F_37 ( & V_13 -> V_81 , V_107 , V_27 -> V_118 & V_119 ) ;
case V_56 :
V_78 = F_37 ( & V_13 -> V_83 , V_107 , V_27 -> V_118 & V_119 ) ;
if ( V_78 )
return V_78 ;
if ( V_13 -> V_15 == V_120 &&
( V_13 -> V_121 [ V_107 -> V_51 ] . V_122 & V_123 ) )
F_38 ( & V_13 -> V_124 , & V_116 ) ;
return 0 ;
default:
return - V_52 ;
}
}
static int F_39 ( struct V_27 * V_27 , void * V_28 ,
struct V_125 * V_126 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
if ( V_126 -> type == V_72 )
return F_40 ( & V_13 -> V_81 , V_126 ) ;
if ( V_126 -> type == V_56 )
return F_40 ( & V_13 -> V_83 , V_126 ) ;
return - V_52 ;
}
static int F_41 ( struct V_27 * V_27 , void * V_28 ,
enum V_127 type )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
int V_78 = - V_52 ;
F_13 () ;
if ( type == V_72 )
V_78 = F_42 ( & V_13 -> V_81 , type ) ;
else if ( type == V_56 )
V_78 = F_42 ( & V_13 -> V_83 , type ) ;
F_16 () ;
return V_78 ;
}
static int F_43 ( struct V_27 * V_27 , void * V_28 ,
enum V_127 type )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
if ( type == V_72 )
return F_44 ( & V_13 -> V_81 , type ) ;
else if ( type == V_56 )
return F_44 ( & V_13 -> V_83 , type ) ;
return - V_52 ;
}
static int F_45 ( struct V_128 * V_129 )
{
struct V_12 * V_13 = F_46 ( V_129 ) ;
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
F_15 ( L_27 , V_129 -> V_130 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_47 ( struct V_128 * V_129 )
{
struct V_12 * V_13 = F_46 ( V_129 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_129 -> V_130 ) {
case V_140 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_129 -> V_133 = V_13 -> V_19 ;
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
V_129 -> V_133 = V_13 -> V_19 ;
} else {
F_19 ( & V_32 -> V_84 , L_28 ) ;
return - V_52 ;
}
break;
}
return 0 ;
}
static int F_48 ( struct V_27 * V_27 , void * V_28 ,
struct V_141 * V_142 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_143 , V_144 , V_145 , V_146 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_120 ) {
F_15 ( L_29 ) ;
return - V_52 ;
}
if ( V_13 -> V_74 -> V_8 == V_147 ) {
V_143 = F_29 ( V_32 -> V_96 , V_148 , V_13 ) ;
V_144 = V_143 >> V_149 ;
V_143 = V_143 & V_150 ;
V_145 = F_29 ( V_32 -> V_96 , V_151 , V_13 ) ;
V_146 = V_145 >> V_152 ;
V_145 = V_145 & V_153 ;
V_142 -> V_154 . V_143 = V_143 ;
V_142 -> V_154 . V_145 = V_145 ;
V_142 -> V_154 . V_59 = V_13 -> V_155 - V_143 - V_144 ;
V_142 -> V_154 . V_61 = V_13 -> V_156 - V_145 - V_146 ;
F_3 ( 2 , L_30
L_31 , V_143 , V_145 ,
V_142 -> V_154 . V_59 , V_142 -> V_154 . V_61 , V_144 , V_146 ,
V_13 -> V_60 , V_13 -> V_62 ) ;
} else {
V_142 -> V_154 . V_143 = 0 ;
V_142 -> V_154 . V_145 = 0 ;
V_142 -> V_154 . V_59 = V_13 -> V_155 ;
V_142 -> V_154 . V_61 = V_13 -> V_156 ;
F_3 ( 2 , L_32
L_33 , V_142 -> V_154 . V_59 , V_142 -> V_154 . V_61 , V_13 -> V_60 ,
V_13 -> V_62 ) ;
}
return 0 ;
}
static int F_49 ( struct V_27 * V_27 , void * V_28 ,
struct V_157 * V_158 )
{
struct V_12 * V_13 = F_12 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_159 * V_107 ;
unsigned long V_122 ;
switch ( V_158 -> V_158 ) {
case V_160 :
if ( V_158 -> V_122 != 0 )
return - V_52 ;
if ( ! V_13 -> V_81 . V_82 )
return - V_52 ;
F_50 ( & V_32 -> V_161 , V_122 ) ;
if ( F_51 ( & V_13 -> V_162 ) ) {
F_15 ( L_34 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_52 ( & V_32 -> V_161 , V_122 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
} else {
F_15 ( L_35 ) ;
V_107 = F_53 ( V_13 -> V_162 . V_163 ,
struct V_159 , V_164 ) ;
if ( V_107 -> V_122 & V_165 )
V_13 -> V_15 = V_20 ;
else
V_107 -> V_122 |= V_123 ;
F_52 ( & V_32 -> V_161 , V_122 ) ;
}
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_54 ( struct V_166 * V_124 ,
const struct V_167 * V_168 )
{
switch ( V_168 -> type ) {
case V_117 :
return F_55 ( V_124 , V_168 , 2 , NULL ) ;
case V_169 :
return F_56 ( V_124 , V_168 ) ;
default:
return - V_52 ;
}
}
static int F_57 ( struct V_170 * V_171 ,
const void * V_172 , unsigned int * V_173 ,
unsigned int * V_174 , unsigned int V_175 [] ,
void * V_176 [] )
{
struct V_12 * V_13 = F_12 ( V_171 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_88 &&
V_171 -> type == V_72 ) {
* V_174 = 1 ;
if ( * V_173 < 1 )
* V_173 = 1 ;
if ( * V_173 > V_178 )
* V_173 = V_178 ;
} else if ( V_13 -> V_15 == V_21 &&
V_171 -> type == V_56 ) {
* V_174 = 2 ;
if ( * V_173 < V_13 -> V_19 )
* V_173 = V_13 -> V_19 ;
if ( * V_173 > V_13 -> V_19 + V_179 )
* V_173 = V_13 -> V_19 + V_179 ;
if ( * V_173 > V_178 )
* V_173 = V_178 ;
} else {
F_15 ( L_36 ,
V_13 -> V_15 , V_171 -> type ) ;
return - V_52 ;
}
F_3 ( 2 , L_37 ,
* V_173 , * V_174 ) ;
if ( V_13 -> V_15 == V_21 &&
V_171 -> type == V_56 ) {
V_175 [ 0 ] = V_13 -> V_70 ;
V_175 [ 1 ] = V_13 -> V_71 ;
if ( F_58 ( V_32 ) )
V_176 [ 0 ] =
V_13 -> V_32 -> V_180 [ V_181 ] ;
else
V_176 [ 0 ] =
V_13 -> V_32 -> V_180 [ V_182 ] ;
V_176 [ 1 ] = V_13 -> V_32 -> V_180 [ V_181 ] ;
} else if ( V_171 -> type == V_72 &&
V_13 -> V_15 == V_88 ) {
V_175 [ 0 ] = V_13 -> V_73 ;
V_176 [ 0 ] = V_13 -> V_32 -> V_180 [ V_181 ] ;
} else {
F_15 ( L_38 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_59 ( struct V_183 * V_184 )
{
struct V_185 * V_186 = F_60 ( V_184 ) ;
struct V_170 * V_171 = V_184 -> V_170 ;
struct V_12 * V_13 = F_12 ( V_171 -> V_177 ) ;
unsigned int V_5 ;
if ( V_171 -> type == V_56 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_13 -> V_66 -> V_65 ; V_5 ++ ) {
if ( F_61 ( F_62 (
F_63 ( V_184 , V_5 ) ) ) ) {
F_15 ( L_39 ) ;
return - V_52 ;
}
}
if ( F_64 ( V_184 , 0 ) < V_13 -> V_70 ||
F_64 ( V_184 , 1 ) < V_13 -> V_71 ) {
F_15 ( L_40 ) ;
return - V_52 ;
}
V_5 = V_184 -> V_51 ;
V_13 -> V_121 [ V_5 ] . V_187 = V_186 ;
V_13 -> V_121 [ V_5 ] . V_188 . V_189 . V_190 =
F_63 ( V_184 , 0 ) ;
V_13 -> V_121 [ V_5 ] . V_188 . V_189 . V_191 =
F_63 ( V_184 , 1 ) ;
V_13 -> V_98 ++ ;
} else if ( V_171 -> type == V_72 ) {
if ( F_61 ( F_62 (
F_63 ( V_184 , 0 ) ) ) ) {
F_15 ( L_41 ) ;
return - V_52 ;
}
if ( F_64 ( V_184 , 0 ) < V_13 -> V_73 ) {
F_15 ( L_42 ) ;
return - V_52 ;
}
V_5 = V_184 -> V_51 ;
V_13 -> V_192 [ V_5 ] . V_187 = V_186 ;
V_13 -> V_192 [ V_5 ] . V_188 . V_193 =
F_63 ( V_184 , 0 ) ;
V_13 -> V_92 ++ ;
} else {
F_15 ( L_43 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_65 ( struct V_170 * V_194 , unsigned int V_91 )
{
struct V_12 * V_13 = F_12 ( V_194 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_66 ( & V_13 -> V_195 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_120 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
return 0 ;
}
static void F_67 ( struct V_170 * V_194 )
{
unsigned long V_122 ;
struct V_12 * V_13 = F_12 ( V_194 -> V_177 ) ;
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
if ( V_194 -> type == V_56 ) {
F_50 ( & V_32 -> V_161 , V_122 ) ;
F_28 ( V_32 -> V_96 , V_201 ,
& V_13 -> V_202 , & V_13 -> V_83 ) ;
F_68 ( & V_13 -> V_202 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_203 = 1 ;
V_13 -> V_204 = 0 ;
F_52 ( & V_32 -> V_161 , V_122 ) ;
if ( F_58 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_205 ;
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
if ( F_14 ( V_13 ,
V_206 , 0 ) )
F_15 ( L_44 ) ;
}
}
if ( V_194 -> type == V_72 ) {
F_50 ( & V_32 -> V_161 , V_122 ) ;
F_28 ( V_32 -> V_96 , V_201 ,
& V_13 -> V_162 , & V_13 -> V_81 ) ;
F_68 ( & V_13 -> V_162 ) ;
V_13 -> V_14 = 0 ;
F_52 ( & V_32 -> V_161 , V_122 ) ;
}
if ( V_196 )
V_13 -> V_15 = V_17 ;
}
static void F_69 ( struct V_183 * V_184 )
{
struct V_170 * V_171 = V_184 -> V_170 ;
struct V_12 * V_13 = F_12 ( V_171 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_122 ;
struct V_159 * V_207 ;
if ( V_171 -> type == V_72 ) {
V_207 = & V_13 -> V_192 [ V_184 -> V_51 ] ;
V_207 -> V_122 &= ~ V_165 ;
F_50 ( & V_32 -> V_161 , V_122 ) ;
F_70 ( & V_207 -> V_164 , & V_13 -> V_162 ) ;
V_13 -> V_14 ++ ;
F_52 ( & V_32 -> V_161 , V_122 ) ;
} else if ( V_171 -> type == V_56 ) {
V_207 = & V_13 -> V_121 [ V_184 -> V_51 ] ;
V_207 -> V_122 &= ~ V_165 ;
F_50 ( & V_32 -> V_161 , V_122 ) ;
F_71 ( V_184 -> V_51 , & V_13 -> V_204 ) ;
F_70 ( & V_207 -> V_164 , & V_13 -> V_202 ) ;
V_13 -> V_18 ++ ;
F_52 ( & V_32 -> V_161 , V_122 ) ;
} else {
F_15 ( L_45 , V_171 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_28 ( V_32 -> V_96 , V_102 , V_32 ) ;
}
struct V_208 * F_72 ( void )
{
return & V_209 ;
}
struct V_210 * F_73 ( void )
{
return & V_211 ;
}
const struct V_212 * F_74 ( void )
{
return & V_213 ;
}
int F_75 ( struct V_12 * V_13 )
{
struct V_214 V_215 ;
int V_5 ;
F_76 ( & V_13 -> V_195 , V_216 ) ;
if ( V_13 -> V_195 . error ) {
F_15 ( L_46 ) ;
return V_13 -> V_195 . error ;
}
for ( V_5 = 0 ; V_5 < V_216 ; V_5 ++ ) {
if ( F_77 ( V_217 [ V_5 ] . V_130 ) ) {
memset ( & V_215 , 0 , sizeof( struct V_214 ) ) ;
V_215 . V_218 = & V_219 ;
V_215 . V_130 = V_217 [ V_5 ] . V_130 ;
V_215 . V_220 = V_217 [ V_5 ] . V_221 ;
V_215 . V_222 = V_217 [ V_5 ] . V_223 ;
V_215 . V_224 = V_217 [ V_5 ] . V_225 ;
V_215 . V_35 = V_217 [ V_5 ] . V_35 ;
V_215 . type = V_217 [ V_5 ] . type ;
V_215 . V_226 = V_217 [ V_5 ] . V_226 ;
V_215 . V_227 = 0 ;
V_13 -> V_228 [ V_5 ] = F_78 ( & V_13 -> V_195 ,
& V_215 , NULL ) ;
} else {
V_13 -> V_228 [ V_5 ] = F_79 ( & V_13 -> V_195 ,
& V_219 ,
V_217 [ V_5 ] . V_130 , V_217 [ V_5 ] . V_221 ,
V_217 [ V_5 ] . V_223 , V_217 [ V_5 ] . V_226 ,
V_217 [ V_5 ] . V_225 ) ;
}
if ( V_13 -> V_195 . error ) {
F_15 ( L_47 , V_5 ) ;
return V_13 -> V_195 . error ;
}
if ( V_217 [ V_5 ] . V_229 && V_13 -> V_228 [ V_5 ] )
V_13 -> V_228 [ V_5 ] -> V_122 |= V_230 ;
}
return 0 ;
}
void F_80 ( struct V_12 * V_13 )
{
int V_5 ;
F_81 ( & V_13 -> V_195 ) ;
for ( V_5 = 0 ; V_5 < V_216 ; V_5 ++ )
V_13 -> V_228 [ V_5 ] = NULL ;
}
void F_82 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_147 ;
V_13 -> V_74 = F_1 ( & V_3 , V_46 ) ;
if ( F_83 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_231 ;
else if ( F_58 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_232 ;
else
V_3 . V_9 . V_10 . V_11 = V_233 ;
V_13 -> V_66 = F_1 ( & V_3 , V_47 ) ;
F_3 ( 2 , L_48 ,
V_13 -> V_74 , V_13 -> V_66 ) ;
}
