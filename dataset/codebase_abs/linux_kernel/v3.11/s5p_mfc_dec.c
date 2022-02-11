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
static int F_7 ( struct V_44 * V_3 , bool V_45 , bool V_46 )
{
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
if ( V_47 == V_3 -> V_51 )
break;
++ V_47 ;
}
if ( V_5 == F_8 ( V_7 ) )
return - V_52 ;
V_9 = & V_7 [ V_5 ] ;
F_9 ( V_3 -> V_53 , V_9 -> V_35 , sizeof( V_3 -> V_53 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_27 , void * V_54 ,
struct V_44 * V_3 )
{
return F_7 ( V_3 , false , false ) ;
}
static int F_11 ( struct V_27 * V_27 , void * V_54 ,
struct V_44 * V_3 )
{
return F_7 ( V_3 , true , false ) ;
}
static int F_12 ( struct V_27 * V_27 , void * V_55 ,
struct V_44 * V_3 )
{
return F_7 ( V_3 , false , true ) ;
}
static int F_13 ( struct V_27 * V_27 , void * V_55 ,
struct V_44 * V_3 )
{
return F_7 ( V_3 , true , true ) ;
}
static int F_14 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_56 * V_10 ;
F_16 () ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_57 &&
( V_13 -> V_15 == V_16 || V_13 -> V_15 ==
V_26 ) ) {
F_17 ( V_13 ) ;
F_18 ( V_13 , V_58 ,
0 ) ;
}
if ( V_3 -> type == V_57 &&
V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_10 -> V_60 = V_13 -> V_61 ;
V_10 -> V_62 = V_13 -> V_63 ;
V_10 -> V_64 = V_65 ;
V_10 -> V_48 = 2 ;
V_10 -> V_11 = V_13 -> V_66 -> V_8 ;
V_10 -> V_67 [ 0 ] . V_68 = V_13 -> V_61 ;
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_70 ;
V_10 -> V_67 [ 1 ] . V_68 = V_13 -> V_61 ;
V_10 -> V_67 [ 1 ] . V_69 = V_13 -> V_71 ;
} else if ( V_3 -> type == V_72 ) {
V_10 -> V_60 = 0 ;
V_10 -> V_62 = 0 ;
V_10 -> V_64 = V_65 ;
V_10 -> V_67 [ 0 ] . V_68 = V_13 -> V_73 ;
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_73 ;
V_10 -> V_11 = V_13 -> V_74 -> V_8 ;
V_10 -> V_48 = V_13 -> V_74 -> V_48 ;
} else {
F_19 ( L_2 ) ;
F_3 ( 2 , L_3 , V_75 ) ;
return - V_52 ;
}
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
F_3 ( 2 , L_4 , V_3 -> type ) ;
if ( V_3 -> type == V_72 ) {
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 ) {
F_19 ( L_5 ) ;
return - V_52 ;
}
if ( V_9 -> V_76 == V_77 ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
if ( ! F_22 ( V_32 ) ) {
if ( V_9 -> V_8 == V_78 ) {
F_19 ( L_7 ) ;
return - V_52 ;
}
}
} else if ( V_3 -> type == V_57 ) {
V_9 = F_1 ( V_3 , V_50 ) ;
if ( ! V_9 ) {
F_19 ( L_8 ) ;
return - V_52 ;
}
if ( F_22 ( V_32 ) && ( V_9 -> V_8 == V_79 ) ) {
F_19 ( L_7 ) ;
return - V_52 ;
} else if ( ! F_22 ( V_32 ) &&
( V_9 -> V_8 != V_79 ) ) {
F_19 ( L_7 ) ;
return - V_52 ;
}
}
return 0 ;
}
static int F_23 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 = 0 ;
struct V_56 * V_10 ;
F_16 () ;
V_80 = F_21 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_80 )
return V_80 ;
if ( V_13 -> V_81 . V_82 || V_13 -> V_83 . V_82 ) {
F_24 ( & V_32 -> V_84 , L_9 , V_75 ) ;
V_80 = - V_85 ;
goto V_46;
}
if ( V_3 -> type == V_57 ) {
V_13 -> V_66 = F_1 ( V_3 , V_50 ) ;
V_80 = 0 ;
goto V_46;
} else if ( V_3 -> type == V_72 ) {
V_13 -> V_74 = F_1 ( V_3 , V_49 ) ;
V_13 -> V_76 = V_13 -> V_74 -> V_76 ;
F_3 ( 2 , L_10 , V_13 -> V_76 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_60 = 0 ;
if ( V_10 -> V_67 [ 0 ] . V_69 )
V_13 -> V_73 = V_10 -> V_67 [ 0 ] . V_69 ;
else
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_73 =
V_86 ;
V_10 -> V_67 [ 0 ] . V_68 = 0 ;
V_13 -> V_15 = V_87 ;
V_80 = 0 ;
goto V_46;
} else {
F_19 ( L_11 , V_3 -> type ) ;
V_80 = - V_52 ;
goto V_46;
}
V_46:
F_20 () ;
return V_80 ;
}
static int F_25 ( struct V_27 * V_27 , void * V_28 ,
struct V_88 * V_89 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 = 0 ;
if ( V_89 -> V_90 != V_91 ) {
F_19 ( L_12 ) ;
return - V_52 ;
}
if ( V_89 -> type == V_72 ) {
if ( V_13 -> V_15 == V_87 ) {
V_13 -> V_92 = 0 ;
if ( V_89 -> V_93 == 0 ) {
F_3 ( 2 , L_13 ) ;
F_26 () ;
V_80 = F_27 ( & V_13 -> V_81 , V_89 ) ;
F_28 () ;
return V_80 ;
}
if ( V_13 -> V_94 != V_95 ) {
F_19 ( L_14 ) ;
return - V_52 ;
}
F_26 () ;
V_80 = F_27 ( & V_13 -> V_81 , V_89 ) ;
F_28 () ;
if ( V_80 ) {
F_19 ( L_15 ) ;
return V_80 ;
}
F_3 ( 2 , L_16 , V_80 ) ;
V_13 -> V_94 = V_96 ;
}
} else if ( V_89 -> type == V_57 ) {
V_13 -> V_97 = 0 ;
if ( V_89 -> V_93 == 0 ) {
F_3 ( 2 , L_13 ) ;
F_26 () ;
V_80 = F_27 ( & V_13 -> V_83 , V_89 ) ;
F_28 () ;
return V_80 ;
}
if ( V_13 -> V_22 != V_95 ) {
F_19 ( L_14 ) ;
return - V_52 ;
}
V_13 -> V_22 = V_96 ;
F_26 () ;
V_80 = F_27 ( & V_13 -> V_83 , V_89 ) ;
F_28 () ;
if ( V_80 ) {
F_19 ( L_17 ) ;
return V_80 ;
}
if ( V_89 -> V_93 < V_13 -> V_19 ) {
F_19 ( L_18 ) ;
V_89 -> V_93 = 0 ;
F_26 () ;
V_80 = F_27 ( & V_13 -> V_83 , V_89 ) ;
F_28 () ;
return - V_98 ;
}
V_13 -> V_99 = V_89 -> V_93 ;
V_80 = F_29 ( V_32 -> V_100 , V_101 , V_13 ) ;
if ( V_80 ) {
F_19 ( L_19 ) ;
V_89 -> V_93 = 0 ;
F_26 () ;
V_80 = F_27 ( & V_13 -> V_83 , V_89 ) ;
F_28 () ;
return - V_98 ;
}
if ( V_13 -> V_97 == V_13 -> V_99 ) {
V_13 -> V_22 = V_23 ;
} else {
F_19 ( L_20 ) ;
V_89 -> V_93 = 0 ;
F_26 () ;
V_80 = F_27 ( & V_13 -> V_83 , V_89 ) ;
F_29 ( V_32 -> V_100 , V_102 ,
V_13 ) ;
F_28 () ;
return - V_98 ;
}
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
F_18 ( V_13 ,
V_104 , 0 ) ;
}
return V_80 ;
}
static int F_31 ( struct V_27 * V_27 , void * V_28 ,
struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 ;
int V_5 ;
if ( V_106 -> V_90 != V_91 ) {
F_19 ( L_21 ) ;
return - V_52 ;
}
F_3 ( 2 , L_22 , V_13 -> V_15 , V_106 -> type ) ;
if ( V_13 -> V_15 == V_87 &&
V_106 -> type == V_72 ) {
V_80 = F_32 ( & V_13 -> V_81 , V_106 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_106 -> type == V_57 ) {
V_80 = F_32 ( & V_13 -> V_83 , V_106 ) ;
for ( V_5 = 0 ; V_5 < V_106 -> V_107 ; V_5 ++ )
V_106 -> V_108 . V_109 [ V_5 ] . V_108 . V_110 += V_111 ;
} else {
F_19 ( L_23 ) ;
V_80 = - V_52 ;
}
F_20 () ;
return V_80 ;
}
static int F_33 ( struct V_27 * V_27 , void * V_28 , struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_112 ) {
F_19 ( L_24 ) ;
return - V_113 ;
}
if ( V_106 -> type == V_72 )
return F_34 ( & V_13 -> V_81 , V_106 ) ;
else if ( V_106 -> type == V_57 )
return F_34 ( & V_13 -> V_83 , V_106 ) ;
return - V_52 ;
}
static int F_35 ( struct V_27 * V_27 , void * V_28 , struct V_105 * V_106 )
{
const struct V_114 V_115 = {
. type = V_116
} ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_80 ;
if ( V_13 -> V_15 == V_112 ) {
F_19 ( L_25 ) ;
return - V_113 ;
}
if ( V_106 -> type == V_72 )
V_80 = F_36 ( & V_13 -> V_81 , V_106 , V_27 -> V_117 & V_118 ) ;
else if ( V_106 -> type == V_57 ) {
V_80 = F_36 ( & V_13 -> V_83 , V_106 , V_27 -> V_117 & V_118 ) ;
if ( V_80 == 0 && V_13 -> V_15 == V_119 &&
F_37 ( & V_13 -> V_83 . V_120 ) )
F_38 ( & V_13 -> V_121 , & V_115 ) ;
} else {
V_80 = - V_52 ;
}
return V_80 ;
}
static int F_39 ( struct V_27 * V_27 , void * V_28 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_123 -> type == V_72 )
return F_40 ( & V_13 -> V_81 , V_123 ) ;
if ( V_123 -> type == V_57 )
return F_40 ( & V_13 -> V_83 , V_123 ) ;
return - V_52 ;
}
static int F_41 ( struct V_27 * V_27 , void * V_28 ,
enum V_124 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_80 = - V_52 ;
F_16 () ;
if ( type == V_72 ) {
if ( V_13 -> V_15 == V_87 ) {
V_13 -> V_97 = 0 ;
V_13 -> V_92 = 0 ;
V_13 -> V_22 = V_95 ;
V_13 -> V_94 = V_95 ;
F_29 ( V_32 -> V_100 , V_125 ,
V_13 ) ;
F_29 ( V_32 -> V_100 , V_126 ,
V_13 ) ;
F_30 ( V_13 ) ;
F_17 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
if ( F_18 ( V_13 ,
V_127 , 0 ) ) {
F_19 ( L_26 ) ;
F_29 ( V_32 -> V_100 ,
V_128 , V_13 ) ;
F_29 ( V_32 -> V_100 ,
V_129 , V_13 ) ;
return - V_113 ;
}
F_3 ( 2 , L_27 , V_13 -> V_130 ) ;
}
V_80 = F_42 ( & V_13 -> V_81 , type ) ;
}
else if ( type == V_57 )
V_80 = F_42 ( & V_13 -> V_83 , type ) ;
F_20 () ;
return V_80 ;
}
static int F_43 ( struct V_27 * V_27 , void * V_28 ,
enum V_124 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( type == V_72 )
return F_44 ( & V_13 -> V_81 , type ) ;
else if ( type == V_57 )
return F_44 ( & V_13 -> V_83 , type ) ;
return - V_52 ;
}
static int F_45 ( struct V_131 * V_132 )
{
struct V_12 * V_13 = F_46 ( V_132 ) ;
switch ( V_132 -> V_133 ) {
case V_134 :
V_13 -> V_135 = V_132 -> V_136 ;
break;
case V_137 :
V_13 -> V_138 = V_132 -> V_136 ;
break;
case V_139 :
V_13 -> V_140 = V_132 -> V_136 ;
break;
case V_141 :
V_13 -> V_142 = V_132 -> V_136 ;
break;
default:
F_19 ( L_28 , V_132 -> V_133 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_47 ( struct V_131 * V_132 )
{
struct V_12 * V_13 = F_46 ( V_132 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_132 -> V_133 ) {
case V_143 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_132 -> V_136 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_87 ) {
F_24 ( & V_32 -> V_84 , L_29 ) ;
return - V_52 ;
}
F_17 ( V_13 ) ;
F_18 ( V_13 ,
V_58 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_132 -> V_136 = V_13 -> V_19 ;
} else {
F_24 ( & V_32 -> V_84 , L_29 ) ;
return - V_52 ;
}
break;
}
return 0 ;
}
static int F_48 ( struct V_27 * V_27 , void * V_28 ,
struct V_144 * V_145 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_146 , V_147 , V_148 , V_149 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_119 ) {
F_19 ( L_30 ) ;
return - V_52 ;
}
if ( V_13 -> V_74 -> V_8 == V_150 ) {
V_146 = F_29 ( V_32 -> V_100 , V_151 , V_13 ) ;
V_147 = V_146 >> V_152 ;
V_146 = V_146 & V_153 ;
V_148 = F_29 ( V_32 -> V_100 , V_154 , V_13 ) ;
V_149 = V_148 >> V_155 ;
V_148 = V_148 & V_156 ;
V_145 -> V_157 . V_146 = V_146 ;
V_145 -> V_157 . V_148 = V_148 ;
V_145 -> V_157 . V_60 = V_13 -> V_158 - V_146 - V_147 ;
V_145 -> V_157 . V_62 = V_13 -> V_159 - V_148 - V_149 ;
F_3 ( 2 , L_31
L_32 , V_146 , V_148 ,
V_145 -> V_157 . V_60 , V_145 -> V_157 . V_62 , V_147 , V_149 ,
V_13 -> V_61 , V_13 -> V_63 ) ;
} else {
V_145 -> V_157 . V_146 = 0 ;
V_145 -> V_157 . V_148 = 0 ;
V_145 -> V_157 . V_60 = V_13 -> V_158 ;
V_145 -> V_157 . V_62 = V_13 -> V_159 ;
F_3 ( 2 , L_33
L_34 , V_145 -> V_157 . V_60 , V_145 -> V_157 . V_62 , V_13 -> V_61 ,
V_13 -> V_63 ) ;
}
return 0 ;
}
int F_49 ( struct V_27 * V_27 , void * V_28 ,
struct V_160 * V_161 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_162 * V_106 ;
unsigned long V_163 ;
switch ( V_161 -> V_161 ) {
case V_164 :
if ( V_161 -> V_163 != 0 )
return - V_52 ;
if ( ! V_13 -> V_81 . V_82 )
return - V_52 ;
F_50 ( & V_32 -> V_165 , V_163 ) ;
if ( F_37 ( & V_13 -> V_166 ) ) {
F_19 ( L_35 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_51 ( & V_32 -> V_165 , V_163 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
} else {
F_19 ( L_36 ) ;
V_106 = F_52 ( V_13 -> V_166 . V_167 ,
struct V_162 , V_168 ) ;
if ( V_106 -> V_163 & V_169 )
V_13 -> V_15 = V_20 ;
else
V_106 -> V_163 |= V_170 ;
F_51 ( & V_32 -> V_165 , V_163 ) ;
}
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_53 ( struct V_171 * V_121 ,
const struct V_172 * V_173 )
{
switch ( V_173 -> type ) {
case V_116 :
return F_54 ( V_121 , V_173 , 2 , NULL ) ;
default:
return - V_52 ;
}
}
static int F_55 ( struct V_174 * V_175 ,
const struct V_2 * V_9 , unsigned int * V_176 ,
unsigned int * V_177 , unsigned int V_178 [] ,
void * V_179 [] )
{
struct V_12 * V_13 = F_15 ( V_175 -> V_180 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_87 &&
V_175 -> type == V_72 ) {
* V_177 = 1 ;
if ( * V_176 < 1 )
* V_176 = 1 ;
if ( * V_176 > V_181 )
* V_176 = V_181 ;
} else if ( V_13 -> V_15 == V_21 &&
V_175 -> type == V_57 ) {
* V_177 = 2 ;
if ( * V_176 < V_13 -> V_19 )
* V_176 = V_13 -> V_19 ;
if ( * V_176 > V_13 -> V_19 + V_182 )
* V_176 = V_13 -> V_19 + V_182 ;
if ( * V_176 > V_181 )
* V_176 = V_181 ;
} else {
F_19 ( L_37 ,
V_13 -> V_15 , V_175 -> type ) ;
return - V_52 ;
}
F_3 ( 2 , L_38 ,
* V_176 , * V_177 ) ;
if ( V_13 -> V_15 == V_21 &&
V_175 -> type == V_57 ) {
V_178 [ 0 ] = V_13 -> V_70 ;
V_178 [ 1 ] = V_13 -> V_71 ;
if ( F_22 ( V_32 ) )
V_179 [ 0 ] =
V_13 -> V_32 -> V_183 [ V_184 ] ;
else
V_179 [ 0 ] =
V_13 -> V_32 -> V_183 [ V_185 ] ;
V_179 [ 1 ] = V_13 -> V_32 -> V_183 [ V_184 ] ;
} else if ( V_175 -> type == V_72 &&
V_13 -> V_15 == V_87 ) {
V_178 [ 0 ] = V_13 -> V_73 ;
V_179 [ 0 ] = V_13 -> V_32 -> V_183 [ V_184 ] ;
} else {
F_19 ( L_39 ) ;
return - V_52 ;
}
return 0 ;
}
static void F_56 ( struct V_174 * V_186 )
{
struct V_12 * V_13 = F_15 ( V_186 -> V_180 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_57 ( & V_32 -> V_187 ) ;
}
static void F_58 ( struct V_174 * V_186 )
{
struct V_12 * V_13 = F_15 ( V_186 -> V_180 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_59 ( & V_32 -> V_187 ) ;
}
static int F_60 ( struct V_188 * V_189 )
{
struct V_174 * V_175 = V_189 -> V_174 ;
struct V_12 * V_13 = F_15 ( V_175 -> V_180 ) ;
unsigned int V_5 ;
if ( V_175 -> type == V_57 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 <= V_13 -> V_74 -> V_48 ; V_5 ++ ) {
if ( F_61 ( F_62 (
F_63 ( V_189 , V_5 ) ) ) ) {
F_19 ( L_40 ) ;
return - V_52 ;
}
}
if ( F_64 ( V_189 , 0 ) < V_13 -> V_70 ||
F_64 ( V_189 , 1 ) < V_13 -> V_71 ) {
F_19 ( L_41 ) ;
return - V_52 ;
}
V_5 = V_189 -> V_190 . V_51 ;
V_13 -> V_191 [ V_5 ] . V_192 = V_189 ;
V_13 -> V_191 [ V_5 ] . V_193 . V_194 . V_195 =
F_63 ( V_189 , 0 ) ;
V_13 -> V_191 [ V_5 ] . V_193 . V_194 . V_196 =
F_63 ( V_189 , 1 ) ;
V_13 -> V_97 ++ ;
} else if ( V_175 -> type == V_72 ) {
if ( F_61 ( F_62 (
F_63 ( V_189 , 0 ) ) ) ) {
F_19 ( L_42 ) ;
return - V_52 ;
}
if ( F_64 ( V_189 , 0 ) < V_13 -> V_73 ) {
F_19 ( L_43 ) ;
return - V_52 ;
}
V_5 = V_189 -> V_190 . V_51 ;
V_13 -> V_197 [ V_5 ] . V_192 = V_189 ;
V_13 -> V_197 [ V_5 ] . V_193 . V_198 =
F_63 ( V_189 , 0 ) ;
V_13 -> V_92 ++ ;
} else {
F_19 ( L_44 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_65 ( struct V_174 * V_186 , unsigned int V_93 )
{
struct V_12 * V_13 = F_15 ( V_186 -> V_180 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_66 ( & V_13 -> V_199 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_119 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
return 0 ;
}
static int F_67 ( struct V_174 * V_186 )
{
unsigned long V_163 ;
struct V_12 * V_13 = F_15 ( V_186 -> V_180 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_200 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_201 == V_13 -> V_202 && V_32 -> V_203 ) {
V_13 -> V_15 = V_59 ;
F_18 ( V_13 ,
V_204 , 0 ) ;
V_200 = 1 ;
}
if ( V_186 -> type == V_57 ) {
F_50 ( & V_32 -> V_165 , V_163 ) ;
F_29 ( V_32 -> V_100 , V_205 , & V_13 -> V_206 ,
& V_13 -> V_83 ) ;
F_68 ( & V_13 -> V_206 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_207 = 1 ;
V_13 -> V_208 = 0 ;
F_51 ( & V_32 -> V_165 , V_163 ) ;
if ( F_22 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_209 ;
F_30 ( V_13 ) ;
F_17 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
if ( F_18 ( V_13 ,
V_210 , 0 ) )
F_19 ( L_45 ) ;
}
}
if ( V_186 -> type == V_72 ) {
F_50 ( & V_32 -> V_165 , V_163 ) ;
F_29 ( V_32 -> V_100 , V_205 , & V_13 -> V_166 ,
& V_13 -> V_81 ) ;
F_68 ( & V_13 -> V_166 ) ;
V_13 -> V_14 = 0 ;
F_51 ( & V_32 -> V_165 , V_163 ) ;
}
if ( V_200 )
V_13 -> V_15 = V_17 ;
return 0 ;
}
static void F_69 ( struct V_188 * V_189 )
{
struct V_174 * V_175 = V_189 -> V_174 ;
struct V_12 * V_13 = F_15 ( V_175 -> V_180 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_163 ;
struct V_162 * V_211 ;
if ( V_175 -> type == V_72 ) {
V_211 = & V_13 -> V_197 [ V_189 -> V_190 . V_51 ] ;
V_211 -> V_163 &= ~ V_169 ;
F_50 ( & V_32 -> V_165 , V_163 ) ;
F_70 ( & V_211 -> V_168 , & V_13 -> V_166 ) ;
V_13 -> V_14 ++ ;
F_51 ( & V_32 -> V_165 , V_163 ) ;
} else if ( V_175 -> type == V_57 ) {
V_211 = & V_13 -> V_191 [ V_189 -> V_190 . V_51 ] ;
V_211 -> V_163 &= ~ V_169 ;
F_50 ( & V_32 -> V_165 , V_163 ) ;
F_71 ( V_189 -> V_190 . V_51 , & V_13 -> V_208 ) ;
F_70 ( & V_211 -> V_168 , & V_13 -> V_206 ) ;
V_13 -> V_18 ++ ;
F_51 ( & V_32 -> V_165 , V_163 ) ;
} else {
F_19 ( L_46 , V_175 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
}
struct V_212 * F_72 ( void )
{
return & V_213 ;
}
struct V_214 * F_73 ( void )
{
return & V_215 ;
}
const struct V_216 * F_74 ( void )
{
return & V_217 ;
}
int F_75 ( struct V_12 * V_13 )
{
struct V_218 V_219 ;
int V_5 ;
F_76 ( & V_13 -> V_199 , V_220 ) ;
if ( V_13 -> V_199 . error ) {
F_19 ( L_47 ) ;
return V_13 -> V_199 . error ;
}
for ( V_5 = 0 ; V_5 < V_220 ; V_5 ++ ) {
if ( F_77 ( V_221 [ V_5 ] . V_133 ) ) {
memset ( & V_219 , 0 , sizeof( struct V_218 ) ) ;
V_219 . V_222 = & V_223 ;
V_219 . V_133 = V_221 [ V_5 ] . V_133 ;
V_219 . V_224 = V_221 [ V_5 ] . V_225 ;
V_219 . V_226 = V_221 [ V_5 ] . V_227 ;
V_219 . V_228 = V_221 [ V_5 ] . V_229 ;
V_219 . V_35 = V_221 [ V_5 ] . V_35 ;
V_219 . type = V_221 [ V_5 ] . type ;
V_219 . V_230 = V_221 [ V_5 ] . V_230 ;
V_219 . V_231 = 0 ;
V_13 -> V_232 [ V_5 ] = F_78 ( & V_13 -> V_199 ,
& V_219 , NULL ) ;
} else {
V_13 -> V_232 [ V_5 ] = F_79 ( & V_13 -> V_199 ,
& V_223 ,
V_221 [ V_5 ] . V_133 , V_221 [ V_5 ] . V_225 ,
V_221 [ V_5 ] . V_227 , V_221 [ V_5 ] . V_230 ,
V_221 [ V_5 ] . V_229 ) ;
}
if ( V_13 -> V_199 . error ) {
F_19 ( L_48 , V_5 ) ;
return V_13 -> V_199 . error ;
}
if ( V_221 [ V_5 ] . V_233 && V_13 -> V_232 [ V_5 ] )
V_13 -> V_232 [ V_5 ] -> V_163 |= V_234 ;
}
return 0 ;
}
void F_80 ( struct V_12 * V_13 )
{
int V_5 ;
F_81 ( & V_13 -> V_199 ) ;
for ( V_5 = 0 ; V_5 < V_220 ; V_5 ++ )
V_13 -> V_232 [ V_5 ] = NULL ;
}
void F_82 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_235 ;
V_13 -> V_74 = F_1 ( & V_3 , V_49 ) ;
V_3 . V_9 . V_10 . V_11 = V_236 ;
V_13 -> V_66 = F_1 ( & V_3 , V_50 ) ;
F_3 ( 2 , L_49 ,
( unsigned int ) V_13 -> V_74 , ( unsigned int ) V_13 -> V_66 ) ;
}
