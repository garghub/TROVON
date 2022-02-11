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
strncpy ( V_30 -> V_33 , V_34 , sizeof( V_30 -> V_33 ) - 1 ) ;
strncpy ( V_30 -> V_35 , V_32 -> V_36 -> V_37 , sizeof( V_30 -> V_35 ) - 1 ) ;
snprintf ( V_30 -> V_38 , sizeof( V_30 -> V_38 ) , L_2 ,
F_6 ( & V_32 -> V_39 -> V_32 ) ) ;
V_30 -> V_40 = V_41 | V_42 ;
V_30 -> V_43 = V_30 -> V_40 | V_44 ;
return 0 ;
}
static int F_7 ( struct V_27 * V_27 , struct V_45 * V_3 ,
bool V_46 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
int V_5 , V_47 = 0 ;
for ( V_5 = 0 ; V_5 < F_8 ( V_7 ) ; ++ V_5 ) {
if ( V_46 && V_7 [ V_5 ] . type != V_48 )
continue;
else if ( ! V_46 && V_7 [ V_5 ] . type != V_49 )
continue;
else if ( ( V_32 -> V_50 -> V_51 & V_7 [ V_5 ] . V_52 ) == 0 )
continue;
if ( V_47 == V_3 -> V_53 )
break;
++ V_47 ;
}
if ( V_5 == F_8 ( V_7 ) )
return - V_54 ;
V_9 = & V_7 [ V_5 ] ;
F_9 ( V_3 -> V_55 , V_9 -> V_37 , sizeof( V_3 -> V_55 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_27 , void * V_56 ,
struct V_45 * V_3 )
{
return F_7 ( V_27 , V_3 , false ) ;
}
static int F_11 ( struct V_27 * V_27 , void * V_28 ,
struct V_45 * V_3 )
{
return F_7 ( V_27 , V_3 , true ) ;
}
static int F_12 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
struct V_57 * V_10 ;
F_14 () ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_58 &&
( V_13 -> V_15 == V_16 || V_13 -> V_15 ==
V_26 ) ) {
F_15 ( V_13 , V_59 ,
0 ) ;
}
if ( V_3 -> type == V_58 &&
V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_60 ) {
V_10 -> V_61 = V_13 -> V_62 ;
V_10 -> V_63 = V_13 -> V_64 ;
V_10 -> V_65 = V_66 ;
V_10 -> V_67 = 2 ;
V_10 -> V_11 = V_13 -> V_68 -> V_8 ;
V_10 -> V_69 [ 0 ] . V_70 = V_13 -> V_62 ;
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_72 ;
V_10 -> V_69 [ 1 ] . V_70 = V_13 -> V_62 ;
V_10 -> V_69 [ 1 ] . V_71 = V_13 -> V_73 ;
} else if ( V_3 -> type == V_74 ) {
V_10 -> V_61 = 0 ;
V_10 -> V_63 = 0 ;
V_10 -> V_65 = V_66 ;
V_10 -> V_69 [ 0 ] . V_70 = V_13 -> V_75 ;
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_75 ;
V_10 -> V_11 = V_13 -> V_76 -> V_8 ;
V_10 -> V_67 = V_13 -> V_76 -> V_67 ;
} else {
F_16 ( L_3 ) ;
F_3 ( 2 , L_4 , V_77 ) ;
return - V_54 ;
}
F_17 () ;
return 0 ;
}
static int F_18 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
F_3 ( 2 , L_5 , V_3 -> type ) ;
if ( V_3 -> type == V_74 ) {
V_9 = F_1 ( V_3 , V_48 ) ;
if ( ! V_9 ) {
F_16 ( L_6 ) ;
return - V_54 ;
}
if ( V_9 -> V_78 == V_79 ) {
F_16 ( L_7 ) ;
return - V_54 ;
}
if ( ( V_32 -> V_50 -> V_51 & V_9 -> V_52 ) == 0 ) {
F_16 ( L_8 ) ;
return - V_54 ;
}
} else if ( V_3 -> type == V_58 ) {
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 ) {
F_16 ( L_9 ) ;
return - V_54 ;
}
if ( ( V_32 -> V_50 -> V_51 & V_9 -> V_52 ) == 0 ) {
F_16 ( L_8 ) ;
return - V_54 ;
}
}
return 0 ;
}
static int F_19 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_80 = 0 ;
struct V_57 * V_10 ;
struct V_81 * V_82 = V_32 -> V_50 -> V_82 ;
F_14 () ;
V_80 = F_18 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_80 )
return V_80 ;
if ( F_20 ( & V_13 -> V_83 ) || F_20 ( & V_13 -> V_84 ) ) {
F_21 ( & V_32 -> V_85 , L_10 , V_77 ) ;
V_80 = - V_86 ;
goto V_46;
}
if ( V_3 -> type == V_58 ) {
V_13 -> V_68 = F_1 ( V_3 , V_49 ) ;
V_80 = 0 ;
goto V_46;
} else if ( V_3 -> type == V_74 ) {
V_13 -> V_76 = F_1 ( V_3 , V_48 ) ;
V_13 -> V_78 = V_13 -> V_76 -> V_78 ;
F_3 ( 2 , L_11 , V_13 -> V_78 ) ;
V_10 -> V_63 = 0 ;
V_10 -> V_61 = 0 ;
if ( V_10 -> V_69 [ 0 ] . V_71 == 0 )
V_10 -> V_69 [ 0 ] . V_71 = V_13 -> V_75 =
V_87 ;
else if ( V_10 -> V_69 [ 0 ] . V_71 > V_82 -> V_88 )
V_13 -> V_75 = V_82 -> V_88 ;
else
V_13 -> V_75 = V_10 -> V_69 [ 0 ] . V_71 ;
V_10 -> V_69 [ 0 ] . V_70 = 0 ;
V_13 -> V_15 = V_89 ;
V_80 = 0 ;
goto V_46;
} else {
F_16 ( L_12 , V_3 -> type ) ;
V_80 = - V_54 ;
goto V_46;
}
V_46:
F_17 () ;
return V_80 ;
}
static int F_22 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_90 * V_91 )
{
int V_80 = 0 ;
F_23 () ;
if ( V_91 -> V_92 == 0 ) {
F_3 ( 2 , L_13 ) ;
V_80 = F_24 ( & V_13 -> V_83 , V_91 ) ;
if ( V_80 )
goto V_46;
V_13 -> V_93 = 0 ;
V_13 -> V_94 = V_95 ;
} else if ( V_13 -> V_94 == V_95 ) {
F_25 ( V_13 -> V_93 != 0 ) ;
if ( V_13 -> V_15 != V_89 ) {
F_16 ( L_14 ) ;
V_80 = - V_54 ;
goto V_46;
}
F_3 ( 2 , L_15 ,
V_91 -> V_92 ) ;
V_80 = F_24 ( & V_13 -> V_83 , V_91 ) ;
if ( V_80 )
goto V_46;
V_80 = F_26 ( V_32 , V_13 ) ;
if ( V_80 ) {
V_91 -> V_92 = 0 ;
F_24 ( & V_13 -> V_83 , V_91 ) ;
goto V_46;
}
V_13 -> V_94 = V_96 ;
} else {
F_16 ( L_16 ) ;
V_80 = - V_54 ;
}
V_46:
F_27 () ;
if ( V_80 )
F_16 ( L_17 ) ;
return V_80 ;
}
static int F_28 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_90 * V_91 )
{
int V_80 = 0 ;
F_23 () ;
if ( V_91 -> V_92 == 0 ) {
F_3 ( 2 , L_13 ) ;
V_80 = F_24 ( & V_13 -> V_84 , V_91 ) ;
if ( V_80 )
goto V_46;
F_29 ( V_32 -> V_97 , V_98 , V_13 ) ;
V_13 -> V_99 = 0 ;
} else if ( V_13 -> V_22 == V_95 ) {
F_25 ( V_13 -> V_99 != 0 ) ;
F_3 ( 2 , L_18 ,
V_91 -> V_92 ) ;
V_80 = F_24 ( & V_13 -> V_84 , V_91 ) ;
if ( V_80 )
goto V_46;
V_13 -> V_22 = V_96 ;
V_13 -> V_100 = V_91 -> V_92 ;
V_80 = F_29 ( V_32 -> V_97 , V_101 , V_13 ) ;
if ( V_80 ) {
F_16 ( L_19 ) ;
V_91 -> V_92 = 0 ;
F_24 ( & V_13 -> V_84 , V_91 ) ;
V_80 = - V_102 ;
V_13 -> V_22 = V_95 ;
goto V_46;
}
F_25 ( V_13 -> V_99 != V_13 -> V_100 ) ;
V_13 -> V_22 = V_23 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_97 , V_103 , V_32 ) ;
F_15 ( V_13 , V_104 ,
0 ) ;
} else {
F_16 ( L_16 ) ;
V_80 = - V_54 ;
}
V_46:
F_27 () ;
if ( V_80 )
F_16 ( L_20 ) ;
return V_80 ;
}
static int F_31 ( struct V_27 * V_27 , void * V_28 ,
struct V_90 * V_91 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( V_91 -> V_105 != V_106 ) {
F_3 ( 2 , L_21 ) ;
return - V_54 ;
}
if ( V_91 -> type == V_74 ) {
return F_22 ( V_32 , V_13 , V_91 ) ;
} else if ( V_91 -> type == V_58 ) {
return F_28 ( V_32 , V_13 , V_91 ) ;
} else {
F_16 ( L_22 ) ;
return - V_54 ;
}
}
static int F_32 ( struct V_27 * V_27 , void * V_28 ,
struct V_107 * V_108 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_80 ;
int V_5 ;
if ( V_108 -> V_105 != V_106 ) {
F_16 ( L_23 ) ;
return - V_54 ;
}
F_3 ( 2 , L_24 , V_13 -> V_15 , V_108 -> type ) ;
if ( V_13 -> V_15 == V_16 &&
V_108 -> type == V_74 ) {
V_80 = F_33 ( & V_13 -> V_83 , V_108 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_108 -> type == V_58 ) {
V_80 = F_33 ( & V_13 -> V_84 , V_108 ) ;
for ( V_5 = 0 ; V_5 < V_108 -> V_109 ; V_5 ++ )
V_108 -> V_110 . V_111 [ V_5 ] . V_110 . V_112 += V_113 ;
} else {
F_16 ( L_25 ) ;
V_80 = - V_54 ;
}
F_17 () ;
return V_80 ;
}
static int F_34 ( struct V_27 * V_27 , void * V_28 , struct V_107 * V_108 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( V_13 -> V_15 == V_114 ) {
F_16 ( L_26 ) ;
return - V_115 ;
}
if ( V_108 -> type == V_74 )
return F_35 ( & V_13 -> V_83 , V_108 ) ;
else if ( V_108 -> type == V_58 )
return F_35 ( & V_13 -> V_84 , V_108 ) ;
return - V_54 ;
}
static int F_36 ( struct V_27 * V_27 , void * V_28 , struct V_107 * V_108 )
{
const struct V_116 V_117 = {
. type = V_118
} ;
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_80 ;
if ( V_13 -> V_15 == V_114 ) {
F_16 ( L_27 ) ;
return - V_115 ;
}
switch ( V_108 -> type ) {
case V_74 :
return F_37 ( & V_13 -> V_83 , V_108 , V_27 -> V_119 & V_120 ) ;
case V_58 :
V_80 = F_37 ( & V_13 -> V_84 , V_108 , V_27 -> V_119 & V_120 ) ;
if ( V_80 )
return V_80 ;
if ( V_13 -> V_15 == V_121 &&
( V_13 -> V_122 [ V_108 -> V_53 ] . V_123 & V_124 ) )
F_38 ( & V_13 -> V_125 , & V_117 ) ;
return 0 ;
default:
return - V_54 ;
}
}
static int F_39 ( struct V_27 * V_27 , void * V_28 ,
struct V_126 * V_127 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( V_127 -> type == V_74 )
return F_40 ( & V_13 -> V_83 , V_127 ) ;
if ( V_127 -> type == V_58 )
return F_40 ( & V_13 -> V_84 , V_127 ) ;
return - V_54 ;
}
static int F_41 ( struct V_27 * V_27 , void * V_28 ,
enum V_128 type )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_80 = - V_54 ;
F_14 () ;
if ( type == V_74 )
V_80 = F_42 ( & V_13 -> V_83 , type ) ;
else if ( type == V_58 )
V_80 = F_42 ( & V_13 -> V_84 , type ) ;
F_17 () ;
return V_80 ;
}
static int F_43 ( struct V_27 * V_27 , void * V_28 ,
enum V_128 type )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( type == V_74 )
return F_44 ( & V_13 -> V_83 , type ) ;
else if ( type == V_58 )
return F_44 ( & V_13 -> V_84 , type ) ;
return - V_54 ;
}
static int F_45 ( struct V_129 * V_130 )
{
struct V_12 * V_13 = F_46 ( V_130 ) ;
switch ( V_130 -> V_131 ) {
case V_132 :
V_13 -> V_133 = V_130 -> V_134 ;
break;
case V_135 :
V_13 -> V_136 = V_130 -> V_134 ;
break;
case V_137 :
V_13 -> V_138 = V_130 -> V_134 ;
break;
case V_139 :
V_13 -> V_140 = V_130 -> V_134 ;
break;
default:
F_16 ( L_28 , V_130 -> V_131 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_47 ( struct V_129 * V_130 )
{
struct V_12 * V_13 = F_46 ( V_130 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_130 -> V_131 ) {
case V_141 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_60 ) {
V_130 -> V_134 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_89 &&
V_13 -> V_15 != V_26 ) {
F_21 ( & V_32 -> V_85 , L_29 ) ;
return - V_54 ;
}
F_15 ( V_13 ,
V_59 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_60 ) {
V_130 -> V_134 = V_13 -> V_19 ;
} else {
F_21 ( & V_32 -> V_85 , L_29 ) ;
return - V_54 ;
}
break;
}
return 0 ;
}
static int F_48 ( struct V_27 * V_27 , void * V_28 ,
struct V_142 * V_143 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_144 , V_145 , V_146 , V_147 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 &&
V_13 -> V_15 != V_20 &&
V_13 -> V_15 != V_121 ) {
F_16 ( L_30 ) ;
return - V_54 ;
}
if ( V_13 -> V_76 -> V_8 == V_148 ) {
V_144 = F_29 ( V_32 -> V_97 , V_149 , V_13 ) ;
V_145 = V_144 >> V_150 ;
V_144 = V_144 & V_151 ;
V_146 = F_29 ( V_32 -> V_97 , V_152 , V_13 ) ;
V_147 = V_146 >> V_153 ;
V_146 = V_146 & V_154 ;
V_143 -> V_155 . V_144 = V_144 ;
V_143 -> V_155 . V_146 = V_146 ;
V_143 -> V_155 . V_61 = V_13 -> V_156 - V_144 - V_145 ;
V_143 -> V_155 . V_63 = V_13 -> V_157 - V_146 - V_147 ;
F_3 ( 2 , L_31
L_32 , V_144 , V_146 ,
V_143 -> V_155 . V_61 , V_143 -> V_155 . V_63 , V_145 , V_147 ,
V_13 -> V_62 , V_13 -> V_64 ) ;
} else {
V_143 -> V_155 . V_144 = 0 ;
V_143 -> V_155 . V_146 = 0 ;
V_143 -> V_155 . V_61 = V_13 -> V_156 ;
V_143 -> V_155 . V_63 = V_13 -> V_157 ;
F_3 ( 2 , L_33
L_34 , V_143 -> V_155 . V_61 , V_143 -> V_155 . V_63 , V_13 -> V_62 ,
V_13 -> V_64 ) ;
}
return 0 ;
}
static int F_49 ( struct V_27 * V_27 , void * V_28 ,
struct V_158 * V_159 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_160 * V_108 ;
unsigned long V_123 ;
switch ( V_159 -> V_159 ) {
case V_161 :
if ( V_159 -> V_123 != 0 )
return - V_54 ;
if ( ! F_20 ( & V_13 -> V_83 ) )
return - V_54 ;
F_50 ( & V_32 -> V_162 , V_123 ) ;
if ( F_51 ( & V_13 -> V_163 ) ) {
F_16 ( L_35 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
F_29 ( V_32 -> V_97 , V_103 , V_32 ) ;
} else {
F_16 ( L_36 ) ;
V_108 = F_53 ( V_13 -> V_163 . V_164 ,
struct V_160 , V_165 ) ;
if ( V_108 -> V_123 & V_166 )
V_13 -> V_15 = V_20 ;
else
V_108 -> V_123 |= V_124 ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
}
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_54 ( struct V_167 * V_125 ,
const struct V_168 * V_169 )
{
switch ( V_169 -> type ) {
case V_118 :
return F_55 ( V_125 , V_169 , 2 , NULL ) ;
case V_170 :
return F_56 ( V_125 , V_169 ) ;
default:
return - V_54 ;
}
}
static int F_57 ( struct V_171 * V_172 ,
unsigned int * V_173 ,
unsigned int * V_174 , unsigned int V_175 [] ,
struct V_176 * V_177 [] )
{
struct V_12 * V_13 = F_13 ( V_172 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_89 &&
V_172 -> type == V_74 ) {
* V_174 = 1 ;
if ( * V_173 < 1 )
* V_173 = 1 ;
if ( * V_173 > V_179 )
* V_173 = V_179 ;
} else if ( V_13 -> V_15 == V_21 &&
V_172 -> type == V_58 ) {
* V_174 = 2 ;
if ( * V_173 < V_13 -> V_19 )
* V_173 = V_13 -> V_19 ;
if ( * V_173 > V_13 -> V_19 + V_180 )
* V_173 = V_13 -> V_19 + V_180 ;
if ( * V_173 > V_179 )
* V_173 = V_179 ;
} else {
F_16 ( L_37 ,
V_13 -> V_15 , V_172 -> type ) ;
return - V_54 ;
}
F_3 ( 2 , L_38 ,
* V_173 , * V_174 ) ;
if ( V_13 -> V_15 == V_21 &&
V_172 -> type == V_58 ) {
V_175 [ 0 ] = V_13 -> V_72 ;
V_175 [ 1 ] = V_13 -> V_73 ;
if ( F_58 ( V_32 ) )
V_177 [ 0 ] = V_13 -> V_32 -> V_181 ;
else
V_177 [ 0 ] = V_13 -> V_32 -> V_182 ;
V_177 [ 1 ] = V_13 -> V_32 -> V_181 ;
} else if ( V_172 -> type == V_74 &&
V_13 -> V_15 == V_89 ) {
V_175 [ 0 ] = V_13 -> V_75 ;
V_177 [ 0 ] = V_13 -> V_32 -> V_181 ;
} else {
F_16 ( L_39 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_59 ( struct V_183 * V_184 )
{
struct V_185 * V_186 = F_60 ( V_184 ) ;
struct V_171 * V_172 = V_184 -> V_171 ;
struct V_12 * V_13 = F_13 ( V_172 -> V_178 ) ;
unsigned int V_5 ;
if ( V_172 -> type == V_58 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_13 -> V_68 -> V_67 ; V_5 ++ ) {
if ( F_61 ( F_62 (
F_63 ( V_184 , V_5 ) ) ) ) {
F_16 ( L_40 ) ;
return - V_54 ;
}
}
if ( F_64 ( V_184 , 0 ) < V_13 -> V_72 ||
F_64 ( V_184 , 1 ) < V_13 -> V_73 ) {
F_16 ( L_41 ) ;
return - V_54 ;
}
V_5 = V_184 -> V_53 ;
V_13 -> V_122 [ V_5 ] . V_187 = V_186 ;
V_13 -> V_122 [ V_5 ] . V_188 . V_189 . V_190 =
F_63 ( V_184 , 0 ) ;
V_13 -> V_122 [ V_5 ] . V_188 . V_189 . V_191 =
F_63 ( V_184 , 1 ) ;
V_13 -> V_99 ++ ;
} else if ( V_172 -> type == V_74 ) {
if ( F_61 ( F_62 (
F_63 ( V_184 , 0 ) ) ) ) {
F_16 ( L_42 ) ;
return - V_54 ;
}
if ( F_64 ( V_184 , 0 ) < V_13 -> V_75 ) {
F_16 ( L_43 ) ;
return - V_54 ;
}
V_5 = V_184 -> V_53 ;
V_13 -> V_192 [ V_5 ] . V_187 = V_186 ;
V_13 -> V_192 [ V_5 ] . V_188 . V_193 =
F_63 ( V_184 , 0 ) ;
V_13 -> V_93 ++ ;
} else {
F_16 ( L_44 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_65 ( struct V_171 * V_194 , unsigned int V_92 )
{
struct V_12 * V_13 = F_13 ( V_194 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_66 ( & V_13 -> V_195 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_121 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_97 , V_103 , V_32 ) ;
return 0 ;
}
static void F_67 ( struct V_171 * V_194 )
{
unsigned long V_123 ;
struct V_12 * V_13 = F_13 ( V_194 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_196 = 0 ;
F_50 ( & V_32 -> V_162 , V_123 ) ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_197 == V_13 -> V_198 && V_32 -> V_199 ) {
V_13 -> V_15 = V_60 ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
F_15 ( V_13 ,
V_200 , 0 ) ;
V_196 = 1 ;
F_50 ( & V_32 -> V_162 , V_123 ) ;
}
if ( V_194 -> type == V_58 ) {
F_68 ( & V_13 -> V_201 , & V_13 -> V_84 ) ;
F_69 ( & V_13 -> V_201 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_202 = 1 ;
V_13 -> V_203 = 0 ;
if ( F_58 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_204 ;
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_97 , V_103 , V_32 ) ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
if ( F_15 ( V_13 ,
V_205 , 0 ) )
F_16 ( L_45 ) ;
F_50 ( & V_32 -> V_162 , V_123 ) ;
}
} else if ( V_194 -> type == V_74 ) {
F_68 ( & V_13 -> V_163 , & V_13 -> V_83 ) ;
F_69 ( & V_13 -> V_163 ) ;
V_13 -> V_14 = 0 ;
}
if ( V_196 )
V_13 -> V_15 = V_17 ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
}
static void F_70 ( struct V_183 * V_184 )
{
struct V_171 * V_172 = V_184 -> V_171 ;
struct V_12 * V_13 = F_13 ( V_172 -> V_178 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_123 ;
struct V_160 * V_206 ;
if ( V_172 -> type == V_74 ) {
V_206 = & V_13 -> V_192 [ V_184 -> V_53 ] ;
V_206 -> V_123 &= ~ V_166 ;
F_50 ( & V_32 -> V_162 , V_123 ) ;
F_71 ( & V_206 -> V_165 , & V_13 -> V_163 ) ;
V_13 -> V_14 ++ ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
} else if ( V_172 -> type == V_58 ) {
V_206 = & V_13 -> V_122 [ V_184 -> V_53 ] ;
V_206 -> V_123 &= ~ V_166 ;
F_50 ( & V_32 -> V_162 , V_123 ) ;
F_72 ( V_184 -> V_53 , & V_13 -> V_203 ) ;
F_71 ( & V_206 -> V_165 , & V_13 -> V_201 ) ;
V_13 -> V_18 ++ ;
F_52 ( & V_32 -> V_162 , V_123 ) ;
} else {
F_16 ( L_46 , V_172 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_97 , V_103 , V_32 ) ;
}
const struct V_207 * F_73 ( void )
{
return & V_208 ;
}
struct V_209 * F_74 ( void )
{
return & V_210 ;
}
const struct V_211 * F_75 ( void )
{
return & V_212 ;
}
int F_76 ( struct V_12 * V_13 )
{
struct V_213 V_214 ;
int V_5 ;
F_77 ( & V_13 -> V_195 , V_215 ) ;
if ( V_13 -> V_195 . error ) {
F_16 ( L_47 ) ;
return V_13 -> V_195 . error ;
}
for ( V_5 = 0 ; V_5 < V_215 ; V_5 ++ ) {
if ( F_78 ( V_216 [ V_5 ] . V_131 ) ) {
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
V_214 . V_217 = & V_218 ;
V_214 . V_131 = V_216 [ V_5 ] . V_131 ;
V_214 . V_219 = V_216 [ V_5 ] . V_220 ;
V_214 . V_221 = V_216 [ V_5 ] . V_222 ;
V_214 . V_223 = V_216 [ V_5 ] . V_224 ;
V_214 . V_37 = V_216 [ V_5 ] . V_37 ;
V_214 . type = V_216 [ V_5 ] . type ;
V_214 . V_225 = V_216 [ V_5 ] . V_225 ;
V_214 . V_226 = 0 ;
V_13 -> V_227 [ V_5 ] = F_79 ( & V_13 -> V_195 ,
& V_214 , NULL ) ;
} else {
V_13 -> V_227 [ V_5 ] = F_80 ( & V_13 -> V_195 ,
& V_218 ,
V_216 [ V_5 ] . V_131 , V_216 [ V_5 ] . V_220 ,
V_216 [ V_5 ] . V_222 , V_216 [ V_5 ] . V_225 ,
V_216 [ V_5 ] . V_224 ) ;
}
if ( V_13 -> V_195 . error ) {
F_16 ( L_48 , V_5 ) ;
return V_13 -> V_195 . error ;
}
if ( V_216 [ V_5 ] . V_228 && V_13 -> V_227 [ V_5 ] )
V_13 -> V_227 [ V_5 ] -> V_123 |= V_229 ;
}
return 0 ;
}
void F_81 ( struct V_12 * V_13 )
{
int V_5 ;
F_82 ( & V_13 -> V_195 ) ;
for ( V_5 = 0 ; V_5 < V_215 ; V_5 ++ )
V_13 -> V_227 [ V_5 ] = NULL ;
}
void F_83 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_148 ;
V_13 -> V_76 = F_1 ( & V_3 , V_48 ) ;
if ( F_84 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_230 ;
else if ( F_58 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_231 ;
else
V_3 . V_9 . V_10 . V_11 = V_232 ;
V_13 -> V_68 = F_1 ( & V_3 , V_49 ) ;
F_3 ( 2 , L_49 ,
V_13 -> V_76 , V_13 -> V_68 ) ;
}
