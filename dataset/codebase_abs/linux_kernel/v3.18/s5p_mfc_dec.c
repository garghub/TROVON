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
bool V_45 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
int V_5 , V_46 = 0 ;
for ( V_5 = 0 ; V_5 < F_8 ( V_7 ) ; ++ V_5 ) {
if ( V_45 && V_7 [ V_5 ] . type != V_47 )
continue;
else if ( ! V_45 && V_7 [ V_5 ] . type != V_48 )
continue;
else if ( ( V_32 -> V_49 -> V_50 & V_7 [ V_5 ] . V_51 ) == 0 )
continue;
if ( V_46 == V_3 -> V_52 )
break;
++ V_46 ;
}
if ( V_5 == F_8 ( V_7 ) )
return - V_53 ;
V_9 = & V_7 [ V_5 ] ;
F_9 ( V_3 -> V_54 , V_9 -> V_35 , sizeof( V_3 -> V_54 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_27 , void * V_55 ,
struct V_44 * V_3 )
{
return F_7 ( V_27 , V_3 , false ) ;
}
static int F_11 ( struct V_27 * V_27 , void * V_28 ,
struct V_44 * V_3 )
{
return F_7 ( V_27 , V_3 , true ) ;
}
static int F_12 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
struct V_56 * V_10 ;
F_14 () ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_57 &&
( V_13 -> V_15 == V_16 || V_13 -> V_15 ==
V_26 ) ) {
F_15 ( V_13 ) ;
F_16 ( V_13 , V_58 ,
0 ) ;
}
if ( V_3 -> type == V_57 &&
V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_10 -> V_60 = V_13 -> V_61 ;
V_10 -> V_62 = V_13 -> V_63 ;
V_10 -> V_64 = V_65 ;
V_10 -> V_66 = 2 ;
V_10 -> V_11 = V_13 -> V_67 -> V_8 ;
V_10 -> V_68 [ 0 ] . V_69 = V_13 -> V_61 ;
V_10 -> V_68 [ 0 ] . V_70 = V_13 -> V_71 ;
V_10 -> V_68 [ 1 ] . V_69 = V_13 -> V_61 ;
V_10 -> V_68 [ 1 ] . V_70 = V_13 -> V_72 ;
} else if ( V_3 -> type == V_73 ) {
V_10 -> V_60 = 0 ;
V_10 -> V_62 = 0 ;
V_10 -> V_64 = V_65 ;
V_10 -> V_68 [ 0 ] . V_69 = V_13 -> V_74 ;
V_10 -> V_68 [ 0 ] . V_70 = V_13 -> V_74 ;
V_10 -> V_11 = V_13 -> V_75 -> V_8 ;
V_10 -> V_66 = V_13 -> V_75 -> V_66 ;
} else {
F_17 ( L_2 ) ;
F_3 ( 2 , L_3 , V_76 ) ;
return - V_53 ;
}
F_18 () ;
return 0 ;
}
static int F_19 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
F_3 ( 2 , L_4 , V_3 -> type ) ;
if ( V_3 -> type == V_73 ) {
V_9 = F_1 ( V_3 , V_47 ) ;
if ( ! V_9 ) {
F_17 ( L_5 ) ;
return - V_53 ;
}
if ( V_9 -> V_77 == V_78 ) {
F_17 ( L_6 ) ;
return - V_53 ;
}
if ( ( V_32 -> V_49 -> V_50 & V_9 -> V_51 ) == 0 ) {
F_17 ( L_7 ) ;
return - V_53 ;
}
} else if ( V_3 -> type == V_57 ) {
V_9 = F_1 ( V_3 , V_48 ) ;
if ( ! V_9 ) {
F_17 ( L_8 ) ;
return - V_53 ;
}
if ( ( V_32 -> V_49 -> V_50 & V_9 -> V_51 ) == 0 ) {
F_17 ( L_7 ) ;
return - V_53 ;
}
}
return 0 ;
}
static int F_20 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_79 = 0 ;
struct V_56 * V_10 ;
struct V_80 * V_81 = V_32 -> V_49 -> V_81 ;
F_14 () ;
V_79 = F_19 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_79 )
return V_79 ;
if ( V_13 -> V_82 . V_83 || V_13 -> V_84 . V_83 ) {
F_21 ( & V_32 -> V_85 , L_9 , V_76 ) ;
V_79 = - V_86 ;
goto V_45;
}
if ( V_3 -> type == V_57 ) {
V_13 -> V_67 = F_1 ( V_3 , V_48 ) ;
V_79 = 0 ;
goto V_45;
} else if ( V_3 -> type == V_73 ) {
V_13 -> V_75 = F_1 ( V_3 , V_47 ) ;
V_13 -> V_77 = V_13 -> V_75 -> V_77 ;
F_3 ( 2 , L_10 , V_13 -> V_77 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_60 = 0 ;
if ( V_10 -> V_68 [ 0 ] . V_70 == 0 )
V_10 -> V_68 [ 0 ] . V_70 = V_13 -> V_74 =
V_87 ;
else if ( V_10 -> V_68 [ 0 ] . V_70 > V_81 -> V_88 )
V_13 -> V_74 = V_81 -> V_88 ;
else
V_13 -> V_74 = V_10 -> V_68 [ 0 ] . V_70 ;
V_10 -> V_68 [ 0 ] . V_69 = 0 ;
V_13 -> V_15 = V_89 ;
V_79 = 0 ;
goto V_45;
} else {
F_17 ( L_11 , V_3 -> type ) ;
V_79 = - V_53 ;
goto V_45;
}
V_45:
F_18 () ;
return V_79 ;
}
static int F_22 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_90 * V_91 )
{
int V_79 = 0 ;
F_23 () ;
if ( V_91 -> V_92 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_79 = F_24 ( & V_13 -> V_82 , V_91 ) ;
if ( V_79 )
goto V_45;
F_25 ( V_32 , V_13 ) ;
V_13 -> V_93 = 0 ;
V_13 -> V_94 = V_95 ;
} else if ( V_13 -> V_94 == V_95 ) {
F_26 ( V_13 -> V_93 != 0 ) ;
if ( V_13 -> V_15 != V_89 ) {
F_17 ( L_13 ) ;
V_79 = - V_53 ;
goto V_45;
}
F_3 ( 2 , L_14 ,
V_91 -> V_92 ) ;
V_79 = F_24 ( & V_13 -> V_82 , V_91 ) ;
if ( V_79 )
goto V_45;
V_79 = F_27 ( V_32 , V_13 ) ;
if ( V_79 ) {
V_91 -> V_92 = 0 ;
F_24 ( & V_13 -> V_82 , V_91 ) ;
goto V_45;
}
V_13 -> V_94 = V_96 ;
} else {
F_17 ( L_15 ) ;
V_79 = - V_53 ;
}
V_45:
F_28 () ;
if ( V_79 )
F_17 ( L_16 ) ;
return V_79 ;
}
static int F_29 ( struct V_31 * V_32 , struct V_12 * V_13 ,
struct V_90 * V_91 )
{
int V_79 = 0 ;
F_23 () ;
if ( V_91 -> V_92 == 0 ) {
F_3 ( 2 , L_12 ) ;
V_79 = F_24 ( & V_13 -> V_84 , V_91 ) ;
if ( V_79 )
goto V_45;
F_30 ( V_32 -> V_97 , V_98 , V_13 ) ;
V_13 -> V_99 = 0 ;
} else if ( V_13 -> V_22 == V_95 ) {
F_26 ( V_13 -> V_99 != 0 ) ;
F_3 ( 2 , L_17 ,
V_91 -> V_92 ) ;
V_79 = F_24 ( & V_13 -> V_84 , V_91 ) ;
if ( V_79 )
goto V_45;
V_13 -> V_22 = V_96 ;
V_13 -> V_100 = V_91 -> V_92 ;
V_79 = F_31 ( V_32 -> V_97 , V_101 , V_13 ) ;
if ( V_79 ) {
F_17 ( L_18 ) ;
V_91 -> V_92 = 0 ;
F_24 ( & V_13 -> V_84 , V_91 ) ;
V_79 = - V_102 ;
V_13 -> V_22 = V_95 ;
goto V_45;
}
F_26 ( V_13 -> V_99 != V_13 -> V_100 ) ;
V_13 -> V_22 = V_23 ;
if ( F_2 ( V_13 ) )
F_32 ( V_13 ) ;
F_30 ( V_32 -> V_97 , V_103 , V_32 ) ;
F_16 ( V_13 , V_104 ,
0 ) ;
} else {
F_17 ( L_15 ) ;
V_79 = - V_53 ;
}
V_45:
F_28 () ;
if ( V_79 )
F_17 ( L_19 ) ;
return V_79 ;
}
static int F_33 ( struct V_27 * V_27 , void * V_28 ,
struct V_90 * V_91 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( V_91 -> V_105 != V_106 ) {
F_17 ( L_20 ) ;
return - V_53 ;
}
if ( V_91 -> type == V_73 ) {
return F_22 ( V_32 , V_13 , V_91 ) ;
} else if ( V_91 -> type == V_57 ) {
return F_29 ( V_32 , V_13 , V_91 ) ;
} else {
F_17 ( L_21 ) ;
return - V_53 ;
}
}
static int F_34 ( struct V_27 * V_27 , void * V_28 ,
struct V_107 * V_108 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_79 ;
int V_5 ;
if ( V_108 -> V_105 != V_106 ) {
F_17 ( L_22 ) ;
return - V_53 ;
}
F_3 ( 2 , L_23 , V_13 -> V_15 , V_108 -> type ) ;
if ( V_13 -> V_15 == V_16 &&
V_108 -> type == V_73 ) {
V_79 = F_35 ( & V_13 -> V_82 , V_108 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_108 -> type == V_57 ) {
V_79 = F_35 ( & V_13 -> V_84 , V_108 ) ;
for ( V_5 = 0 ; V_5 < V_108 -> V_109 ; V_5 ++ )
V_108 -> V_110 . V_111 [ V_5 ] . V_110 . V_112 += V_113 ;
} else {
F_17 ( L_24 ) ;
V_79 = - V_53 ;
}
F_18 () ;
return V_79 ;
}
static int F_36 ( struct V_27 * V_27 , void * V_28 , struct V_107 * V_108 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( V_13 -> V_15 == V_114 ) {
F_17 ( L_25 ) ;
return - V_115 ;
}
if ( V_108 -> type == V_73 )
return F_37 ( & V_13 -> V_82 , V_108 ) ;
else if ( V_108 -> type == V_57 )
return F_37 ( & V_13 -> V_84 , V_108 ) ;
return - V_53 ;
}
static int F_38 ( struct V_27 * V_27 , void * V_28 , struct V_107 * V_108 )
{
const struct V_116 V_117 = {
. type = V_118
} ;
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_79 ;
if ( V_13 -> V_15 == V_114 ) {
F_17 ( L_26 ) ;
return - V_115 ;
}
if ( V_108 -> type == V_73 )
V_79 = F_39 ( & V_13 -> V_82 , V_108 , V_27 -> V_119 & V_120 ) ;
else if ( V_108 -> type == V_57 ) {
V_79 = F_39 ( & V_13 -> V_84 , V_108 , V_27 -> V_119 & V_120 ) ;
if ( V_79 == 0 && V_13 -> V_15 == V_121 &&
F_40 ( & V_13 -> V_84 . V_122 ) )
F_41 ( & V_13 -> V_123 , & V_117 ) ;
} else {
V_79 = - V_53 ;
}
return V_79 ;
}
static int F_42 ( struct V_27 * V_27 , void * V_28 ,
struct V_124 * V_125 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( V_125 -> type == V_73 )
return F_43 ( & V_13 -> V_82 , V_125 ) ;
if ( V_125 -> type == V_57 )
return F_43 ( & V_13 -> V_84 , V_125 ) ;
return - V_53 ;
}
static int F_44 ( struct V_27 * V_27 , void * V_28 ,
enum V_126 type )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
int V_79 = - V_53 ;
F_14 () ;
if ( type == V_73 )
V_79 = F_45 ( & V_13 -> V_82 , type ) ;
else if ( type == V_57 )
V_79 = F_45 ( & V_13 -> V_84 , type ) ;
F_18 () ;
return V_79 ;
}
static int F_46 ( struct V_27 * V_27 , void * V_28 ,
enum V_126 type )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
if ( type == V_73 )
return F_47 ( & V_13 -> V_82 , type ) ;
else if ( type == V_57 )
return F_47 ( & V_13 -> V_84 , type ) ;
return - V_53 ;
}
static int F_48 ( struct V_127 * V_128 )
{
struct V_12 * V_13 = F_49 ( V_128 ) ;
switch ( V_128 -> V_129 ) {
case V_130 :
V_13 -> V_131 = V_128 -> V_132 ;
break;
case V_133 :
V_13 -> V_134 = V_128 -> V_132 ;
break;
case V_135 :
V_13 -> V_136 = V_128 -> V_132 ;
break;
case V_137 :
V_13 -> V_138 = V_128 -> V_132 ;
break;
default:
F_17 ( L_27 , V_128 -> V_129 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_50 ( struct V_127 * V_128 )
{
struct V_12 * V_13 = F_49 ( V_128 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_128 -> V_129 ) {
case V_139 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_128 -> V_132 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_89 ) {
F_21 ( & V_32 -> V_85 , L_28 ) ;
return - V_53 ;
}
F_15 ( V_13 ) ;
F_16 ( V_13 ,
V_58 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_128 -> V_132 = V_13 -> V_19 ;
} else {
F_21 ( & V_32 -> V_85 , L_28 ) ;
return - V_53 ;
}
break;
}
return 0 ;
}
static int F_51 ( struct V_27 * V_27 , void * V_28 ,
struct V_140 * V_141 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_142 , V_143 , V_144 , V_145 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_121 ) {
F_17 ( L_29 ) ;
return - V_53 ;
}
if ( V_13 -> V_75 -> V_8 == V_146 ) {
V_142 = F_31 ( V_32 -> V_97 , V_147 , V_13 ) ;
V_143 = V_142 >> V_148 ;
V_142 = V_142 & V_149 ;
V_144 = F_31 ( V_32 -> V_97 , V_150 , V_13 ) ;
V_145 = V_144 >> V_151 ;
V_144 = V_144 & V_152 ;
V_141 -> V_153 . V_142 = V_142 ;
V_141 -> V_153 . V_144 = V_144 ;
V_141 -> V_153 . V_60 = V_13 -> V_154 - V_142 - V_143 ;
V_141 -> V_153 . V_62 = V_13 -> V_155 - V_144 - V_145 ;
F_3 ( 2 , L_30
L_31 , V_142 , V_144 ,
V_141 -> V_153 . V_60 , V_141 -> V_153 . V_62 , V_143 , V_145 ,
V_13 -> V_61 , V_13 -> V_63 ) ;
} else {
V_141 -> V_153 . V_142 = 0 ;
V_141 -> V_153 . V_144 = 0 ;
V_141 -> V_153 . V_60 = V_13 -> V_154 ;
V_141 -> V_153 . V_62 = V_13 -> V_155 ;
F_3 ( 2 , L_32
L_33 , V_141 -> V_153 . V_60 , V_141 -> V_153 . V_62 , V_13 -> V_61 ,
V_13 -> V_63 ) ;
}
return 0 ;
}
static int F_52 ( struct V_27 * V_27 , void * V_28 ,
struct V_156 * V_157 )
{
struct V_12 * V_13 = F_13 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
struct V_158 * V_108 ;
unsigned long V_159 ;
switch ( V_157 -> V_157 ) {
case V_160 :
if ( V_157 -> V_159 != 0 )
return - V_53 ;
if ( ! V_13 -> V_82 . V_83 )
return - V_53 ;
F_53 ( & V_32 -> V_161 , V_159 ) ;
if ( F_40 ( & V_13 -> V_162 ) ) {
F_17 ( L_34 ) ;
V_13 -> V_15 = V_20 ;
if ( F_2 ( V_13 ) )
F_32 ( V_13 ) ;
F_54 ( & V_32 -> V_161 , V_159 ) ;
F_30 ( V_32 -> V_97 , V_103 , V_32 ) ;
} else {
F_17 ( L_35 ) ;
V_108 = F_55 ( V_13 -> V_162 . V_163 ,
struct V_158 , V_164 ) ;
if ( V_108 -> V_159 & V_165 )
V_13 -> V_15 = V_20 ;
else
V_108 -> V_159 |= V_166 ;
F_54 ( & V_32 -> V_161 , V_159 ) ;
}
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_56 ( struct V_167 * V_123 ,
const struct V_168 * V_169 )
{
switch ( V_169 -> type ) {
case V_118 :
return F_57 ( V_123 , V_169 , 2 , NULL ) ;
case V_170 :
return F_58 ( V_123 , V_169 ) ;
default:
return - V_53 ;
}
}
static int F_59 ( struct V_171 * V_172 ,
const struct V_2 * V_9 , unsigned int * V_173 ,
unsigned int * V_174 , unsigned int V_175 [] ,
void * V_176 [] )
{
struct V_12 * V_13 = F_13 ( V_172 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_89 &&
V_172 -> type == V_73 ) {
* V_174 = 1 ;
if ( * V_173 < 1 )
* V_173 = 1 ;
if ( * V_173 > V_178 )
* V_173 = V_178 ;
} else if ( V_13 -> V_15 == V_21 &&
V_172 -> type == V_57 ) {
* V_174 = 2 ;
if ( * V_173 < V_13 -> V_19 )
* V_173 = V_13 -> V_19 ;
if ( * V_173 > V_13 -> V_19 + V_179 )
* V_173 = V_13 -> V_19 + V_179 ;
if ( * V_173 > V_178 )
* V_173 = V_178 ;
} else {
F_17 ( L_36 ,
V_13 -> V_15 , V_172 -> type ) ;
return - V_53 ;
}
F_3 ( 2 , L_37 ,
* V_173 , * V_174 ) ;
if ( V_13 -> V_15 == V_21 &&
V_172 -> type == V_57 ) {
V_175 [ 0 ] = V_13 -> V_71 ;
V_175 [ 1 ] = V_13 -> V_72 ;
if ( F_60 ( V_32 ) )
V_176 [ 0 ] =
V_13 -> V_32 -> V_180 [ V_181 ] ;
else
V_176 [ 0 ] =
V_13 -> V_32 -> V_180 [ V_182 ] ;
V_176 [ 1 ] = V_13 -> V_32 -> V_180 [ V_181 ] ;
} else if ( V_172 -> type == V_73 &&
V_13 -> V_15 == V_89 ) {
V_175 [ 0 ] = V_13 -> V_74 ;
V_176 [ 0 ] = V_13 -> V_32 -> V_180 [ V_181 ] ;
} else {
F_17 ( L_38 ) ;
return - V_53 ;
}
return 0 ;
}
static void F_61 ( struct V_171 * V_183 )
{
struct V_12 * V_13 = F_13 ( V_183 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_62 ( & V_32 -> V_184 ) ;
}
static void F_63 ( struct V_171 * V_183 )
{
struct V_12 * V_13 = F_13 ( V_183 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_64 ( & V_32 -> V_184 ) ;
}
static int F_65 ( struct V_185 * V_186 )
{
struct V_171 * V_172 = V_186 -> V_171 ;
struct V_12 * V_13 = F_13 ( V_172 -> V_177 ) ;
unsigned int V_5 ;
if ( V_172 -> type == V_57 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_13 -> V_67 -> V_66 ; V_5 ++ ) {
if ( F_66 ( F_67 (
F_68 ( V_186 , V_5 ) ) ) ) {
F_17 ( L_39 ) ;
return - V_53 ;
}
}
if ( F_69 ( V_186 , 0 ) < V_13 -> V_71 ||
F_69 ( V_186 , 1 ) < V_13 -> V_72 ) {
F_17 ( L_40 ) ;
return - V_53 ;
}
V_5 = V_186 -> V_187 . V_52 ;
V_13 -> V_188 [ V_5 ] . V_189 = V_186 ;
V_13 -> V_188 [ V_5 ] . V_190 . V_191 . V_192 =
F_68 ( V_186 , 0 ) ;
V_13 -> V_188 [ V_5 ] . V_190 . V_191 . V_193 =
F_68 ( V_186 , 1 ) ;
V_13 -> V_99 ++ ;
} else if ( V_172 -> type == V_73 ) {
if ( F_66 ( F_67 (
F_68 ( V_186 , 0 ) ) ) ) {
F_17 ( L_41 ) ;
return - V_53 ;
}
if ( F_69 ( V_186 , 0 ) < V_13 -> V_74 ) {
F_17 ( L_42 ) ;
return - V_53 ;
}
V_5 = V_186 -> V_187 . V_52 ;
V_13 -> V_194 [ V_5 ] . V_189 = V_186 ;
V_13 -> V_194 [ V_5 ] . V_190 . V_195 =
F_68 ( V_186 , 0 ) ;
V_13 -> V_93 ++ ;
} else {
F_17 ( L_43 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_70 ( struct V_171 * V_183 , unsigned int V_92 )
{
struct V_12 * V_13 = F_13 ( V_183 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_71 ( & V_13 -> V_196 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_121 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_32 ( V_13 ) ;
F_30 ( V_32 -> V_97 , V_103 , V_32 ) ;
return 0 ;
}
static void F_72 ( struct V_171 * V_183 )
{
unsigned long V_159 ;
struct V_12 * V_13 = F_13 ( V_183 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_197 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_198 == V_13 -> V_199 && V_32 -> V_200 ) {
V_13 -> V_15 = V_59 ;
F_16 ( V_13 ,
V_201 , 0 ) ;
V_197 = 1 ;
}
if ( V_183 -> type == V_57 ) {
F_53 ( & V_32 -> V_161 , V_159 ) ;
F_30 ( V_32 -> V_97 , V_202 ,
& V_13 -> V_203 , & V_13 -> V_84 ) ;
F_73 ( & V_13 -> V_203 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_204 = 1 ;
V_13 -> V_205 = 0 ;
F_54 ( & V_32 -> V_161 , V_159 ) ;
if ( F_60 ( V_32 ) && ( V_13 -> V_15 == V_17 ) ) {
V_13 -> V_15 = V_206 ;
F_32 ( V_13 ) ;
F_15 ( V_13 ) ;
F_30 ( V_32 -> V_97 , V_103 , V_32 ) ;
if ( F_16 ( V_13 ,
V_207 , 0 ) )
F_17 ( L_44 ) ;
}
}
if ( V_183 -> type == V_73 ) {
F_53 ( & V_32 -> V_161 , V_159 ) ;
F_30 ( V_32 -> V_97 , V_202 ,
& V_13 -> V_162 , & V_13 -> V_82 ) ;
F_73 ( & V_13 -> V_162 ) ;
V_13 -> V_14 = 0 ;
F_54 ( & V_32 -> V_161 , V_159 ) ;
}
if ( V_197 )
V_13 -> V_15 = V_17 ;
}
static void F_74 ( struct V_185 * V_186 )
{
struct V_171 * V_172 = V_186 -> V_171 ;
struct V_12 * V_13 = F_13 ( V_172 -> V_177 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_159 ;
struct V_158 * V_208 ;
if ( V_172 -> type == V_73 ) {
V_208 = & V_13 -> V_194 [ V_186 -> V_187 . V_52 ] ;
V_208 -> V_159 &= ~ V_165 ;
F_53 ( & V_32 -> V_161 , V_159 ) ;
F_75 ( & V_208 -> V_164 , & V_13 -> V_162 ) ;
V_13 -> V_14 ++ ;
F_54 ( & V_32 -> V_161 , V_159 ) ;
} else if ( V_172 -> type == V_57 ) {
V_208 = & V_13 -> V_188 [ V_186 -> V_187 . V_52 ] ;
V_208 -> V_159 &= ~ V_165 ;
F_53 ( & V_32 -> V_161 , V_159 ) ;
F_76 ( V_186 -> V_187 . V_52 , & V_13 -> V_205 ) ;
F_75 ( & V_208 -> V_164 , & V_13 -> V_203 ) ;
V_13 -> V_18 ++ ;
F_54 ( & V_32 -> V_161 , V_159 ) ;
} else {
F_17 ( L_45 , V_172 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_32 ( V_13 ) ;
F_30 ( V_32 -> V_97 , V_103 , V_32 ) ;
}
struct V_209 * F_77 ( void )
{
return & V_210 ;
}
struct V_211 * F_78 ( void )
{
return & V_212 ;
}
const struct V_213 * F_79 ( void )
{
return & V_214 ;
}
int F_80 ( struct V_12 * V_13 )
{
struct V_215 V_216 ;
int V_5 ;
F_81 ( & V_13 -> V_196 , V_217 ) ;
if ( V_13 -> V_196 . error ) {
F_17 ( L_46 ) ;
return V_13 -> V_196 . error ;
}
for ( V_5 = 0 ; V_5 < V_217 ; V_5 ++ ) {
if ( F_82 ( V_218 [ V_5 ] . V_129 ) ) {
memset ( & V_216 , 0 , sizeof( struct V_215 ) ) ;
V_216 . V_219 = & V_220 ;
V_216 . V_129 = V_218 [ V_5 ] . V_129 ;
V_216 . V_221 = V_218 [ V_5 ] . V_222 ;
V_216 . V_223 = V_218 [ V_5 ] . V_224 ;
V_216 . V_225 = V_218 [ V_5 ] . V_226 ;
V_216 . V_35 = V_218 [ V_5 ] . V_35 ;
V_216 . type = V_218 [ V_5 ] . type ;
V_216 . V_227 = V_218 [ V_5 ] . V_227 ;
V_216 . V_228 = 0 ;
V_13 -> V_229 [ V_5 ] = F_83 ( & V_13 -> V_196 ,
& V_216 , NULL ) ;
} else {
V_13 -> V_229 [ V_5 ] = F_84 ( & V_13 -> V_196 ,
& V_220 ,
V_218 [ V_5 ] . V_129 , V_218 [ V_5 ] . V_222 ,
V_218 [ V_5 ] . V_224 , V_218 [ V_5 ] . V_227 ,
V_218 [ V_5 ] . V_226 ) ;
}
if ( V_13 -> V_196 . error ) {
F_17 ( L_47 , V_5 ) ;
return V_13 -> V_196 . error ;
}
if ( V_218 [ V_5 ] . V_230 && V_13 -> V_229 [ V_5 ] )
V_13 -> V_229 [ V_5 ] -> V_159 |= V_231 ;
}
return 0 ;
}
void F_85 ( struct V_12 * V_13 )
{
int V_5 ;
F_86 ( & V_13 -> V_196 ) ;
for ( V_5 = 0 ; V_5 < V_217 ; V_5 ++ )
V_13 -> V_229 [ V_5 ] = NULL ;
}
void F_87 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_146 ;
V_13 -> V_75 = F_1 ( & V_3 , V_47 ) ;
if ( F_88 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_232 ;
else if ( F_60 ( V_13 -> V_32 ) )
V_3 . V_9 . V_10 . V_11 = V_233 ;
else
V_3 . V_9 . V_10 . V_11 = V_234 ;
V_13 -> V_67 = F_1 ( & V_3 , V_48 ) ;
F_3 ( 2 , L_48 ,
V_13 -> V_75 , V_13 -> V_67 ) ;
}
