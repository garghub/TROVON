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
V_30 -> V_39 = V_40 |
V_41 | V_42 ;
return 0 ;
}
static int F_7 ( struct V_43 * V_3 , bool V_44 , bool V_45 )
{
struct V_1 * V_9 ;
int V_5 , V_46 = 0 ;
for ( V_5 = 0 ; V_5 < F_8 ( V_7 ) ; ++ V_5 ) {
if ( V_44 && V_7 [ V_5 ] . V_47 == 1 )
continue;
else if ( ! V_44 && V_7 [ V_5 ] . V_47 > 1 )
continue;
if ( V_45 && V_7 [ V_5 ] . type != V_48 )
continue;
else if ( ! V_45 && V_7 [ V_5 ] . type != V_49 )
continue;
if ( V_46 == V_3 -> V_50 )
break;
++ V_46 ;
}
if ( V_5 == F_8 ( V_7 ) )
return - V_51 ;
V_9 = & V_7 [ V_5 ] ;
F_9 ( V_3 -> V_52 , V_9 -> V_35 , sizeof( V_3 -> V_52 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_27 , void * V_53 ,
struct V_43 * V_3 )
{
return F_7 ( V_3 , false , false ) ;
}
static int F_11 ( struct V_27 * V_27 , void * V_53 ,
struct V_43 * V_3 )
{
return F_7 ( V_3 , true , false ) ;
}
static int F_12 ( struct V_27 * V_27 , void * V_54 ,
struct V_43 * V_3 )
{
return F_7 ( V_3 , false , true ) ;
}
static int F_13 ( struct V_27 * V_27 , void * V_54 ,
struct V_43 * V_3 )
{
return F_7 ( V_3 , true , true ) ;
}
static int F_14 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_55 * V_10 ;
F_16 () ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_56 &&
( V_13 -> V_15 == V_16 || V_13 -> V_15 ==
V_26 ) ) {
F_17 ( V_13 ) ;
F_18 ( V_13 , V_57 ,
0 ) ;
}
if ( V_3 -> type == V_56 &&
V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_10 -> V_59 = V_13 -> V_60 ;
V_10 -> V_61 = V_13 -> V_62 ;
V_10 -> V_63 = V_64 ;
V_10 -> V_47 = 2 ;
V_10 -> V_11 = V_65 ;
V_10 -> V_66 [ 0 ] . V_67 = V_13 -> V_60 ;
V_10 -> V_66 [ 0 ] . V_68 = V_13 -> V_69 ;
V_10 -> V_66 [ 1 ] . V_67 = V_13 -> V_60 ;
V_10 -> V_66 [ 1 ] . V_68 = V_13 -> V_70 ;
} else if ( V_3 -> type == V_71 ) {
V_10 -> V_59 = 0 ;
V_10 -> V_61 = 0 ;
V_10 -> V_63 = V_64 ;
V_10 -> V_66 [ 0 ] . V_67 = V_13 -> V_72 ;
V_10 -> V_66 [ 0 ] . V_68 = V_13 -> V_72 ;
V_10 -> V_11 = V_13 -> V_73 -> V_8 ;
V_10 -> V_47 = V_13 -> V_73 -> V_47 ;
} else {
F_19 ( L_2 ) ;
F_3 ( 2 , L_3 , V_74 ) ;
return - V_51 ;
}
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
if ( V_3 -> type != V_71 ) {
F_19 ( L_4 ) ;
return - V_51 ;
}
V_9 = F_1 ( V_3 , V_48 ) ;
if ( ! V_9 ) {
F_19 ( L_5 ) ;
return - V_51 ;
}
if ( V_9 -> type != V_48 ) {
F_19 ( L_6 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_22 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_75 = 0 ;
struct V_1 * V_9 ;
struct V_55 * V_10 ;
F_16 () ;
V_75 = F_21 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_75 )
return V_75 ;
if ( V_13 -> V_76 . V_77 || V_13 -> V_78 . V_77 ) {
F_23 ( & V_32 -> V_79 , L_7 , V_74 ) ;
V_75 = - V_80 ;
goto V_45;
}
V_9 = F_1 ( V_3 , V_48 ) ;
if ( ! V_9 || V_9 -> V_81 == V_82 ) {
F_19 ( L_8 ) ;
V_75 = - V_51 ;
goto V_45;
}
if ( V_9 -> type != V_48 ) {
F_19 ( L_9
L_10 ) ;
V_75 = - V_51 ;
goto V_45;
}
V_13 -> V_73 = V_9 ;
V_13 -> V_81 = V_9 -> V_81 ;
F_3 ( 2 , L_11 , V_13 -> V_81 ) ;
V_10 -> V_61 = 0 ;
V_10 -> V_59 = 0 ;
if ( V_10 -> V_66 [ 0 ] . V_68 )
V_13 -> V_72 = V_10 -> V_66 [ 0 ] . V_68 ;
else
V_10 -> V_66 [ 0 ] . V_68 = V_13 -> V_72 =
V_83 ;
V_10 -> V_66 [ 0 ] . V_67 = 0 ;
V_13 -> V_15 = V_84 ;
V_45:
F_20 () ;
return V_75 ;
}
static int F_24 ( struct V_27 * V_27 , void * V_28 ,
struct V_85 * V_86 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_75 = 0 ;
unsigned long V_87 ;
if ( V_86 -> V_88 != V_89 ) {
F_19 ( L_12 ) ;
return - V_51 ;
}
if ( V_86 -> type == V_71 ) {
if ( V_13 -> V_15 == V_84 ) {
V_13 -> V_90 = 0 ;
if ( V_86 -> V_91 == 0 ) {
F_3 ( 2 , L_13 ) ;
F_25 () ;
V_75 = F_26 ( & V_13 -> V_76 , V_86 ) ;
F_27 () ;
return V_75 ;
}
if ( V_13 -> V_92 != V_93 ) {
F_19 ( L_14 ) ;
return - V_51 ;
}
F_25 () ;
V_75 = F_26 ( & V_13 -> V_76 , V_86 ) ;
F_27 () ;
if ( V_75 ) {
F_19 ( L_15 ) ;
return V_75 ;
}
F_3 ( 2 , L_16 , V_75 ) ;
V_13 -> V_92 = V_94 ;
}
} else if ( V_86 -> type == V_56 ) {
V_13 -> V_95 = 0 ;
if ( V_86 -> V_91 == 0 ) {
F_3 ( 2 , L_13 ) ;
F_25 () ;
V_75 = F_26 ( & V_13 -> V_78 , V_86 ) ;
F_27 () ;
return V_75 ;
}
if ( V_13 -> V_22 != V_93 ) {
F_19 ( L_14 ) ;
return - V_51 ;
}
V_13 -> V_22 = V_94 ;
F_25 () ;
V_75 = F_26 ( & V_13 -> V_78 , V_86 ) ;
F_27 () ;
if ( V_75 ) {
F_19 ( L_17 ) ;
return V_75 ;
}
if ( V_86 -> V_91 < V_13 -> V_19 ) {
F_19 ( L_18 ) ;
V_86 -> V_91 = 0 ;
F_25 () ;
V_75 = F_26 ( & V_13 -> V_78 , V_86 ) ;
F_27 () ;
return - V_96 ;
}
V_13 -> V_97 = V_86 -> V_91 ;
V_75 = F_28 ( V_13 ) ;
if ( V_75 ) {
F_19 ( L_19 ) ;
V_86 -> V_91 = 0 ;
F_25 () ;
V_75 = F_26 ( & V_13 -> V_78 , V_86 ) ;
F_27 () ;
return - V_96 ;
}
if ( V_13 -> V_95 == V_13 -> V_97 ) {
V_13 -> V_22 = V_23 ;
} else {
F_19 ( L_20 ) ;
V_86 -> V_91 = 0 ;
F_25 () ;
V_75 = F_26 ( & V_13 -> V_78 , V_86 ) ;
F_29 ( V_13 ) ;
F_27 () ;
return - V_96 ;
}
if ( F_2 ( V_13 ) ) {
F_30 ( & V_32 -> V_98 , V_87 ) ;
F_31 ( V_13 -> V_99 , & V_32 -> V_100 ) ;
F_32 ( & V_32 -> V_98 , V_87 ) ;
}
F_33 ( V_32 ) ;
F_18 ( V_13 ,
V_101 , 0 ) ;
}
return V_75 ;
}
static int F_34 ( struct V_27 * V_27 , void * V_28 ,
struct V_102 * V_103 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_75 ;
int V_5 ;
if ( V_103 -> V_88 != V_89 ) {
F_19 ( L_21 ) ;
return - V_51 ;
}
F_3 ( 2 , L_22 , V_13 -> V_15 , V_103 -> type ) ;
if ( V_13 -> V_15 == V_84 &&
V_103 -> type == V_71 ) {
V_75 = F_35 ( & V_13 -> V_76 , V_103 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_103 -> type == V_56 ) {
V_75 = F_35 ( & V_13 -> V_78 , V_103 ) ;
for ( V_5 = 0 ; V_5 < V_103 -> V_104 ; V_5 ++ )
V_103 -> V_105 . V_106 [ V_5 ] . V_105 . V_107 += V_108 ;
} else {
F_19 ( L_23 ) ;
V_75 = - V_51 ;
}
F_20 () ;
return V_75 ;
}
static int F_36 ( struct V_27 * V_27 , void * V_28 , struct V_102 * V_103 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_109 ) {
F_19 ( L_24 ) ;
return - V_110 ;
}
if ( V_103 -> type == V_71 )
return F_37 ( & V_13 -> V_76 , V_103 ) ;
else if ( V_103 -> type == V_56 )
return F_37 ( & V_13 -> V_78 , V_103 ) ;
return - V_51 ;
}
static int F_38 ( struct V_27 * V_27 , void * V_28 , struct V_102 * V_103 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_109 ) {
F_19 ( L_25 ) ;
return - V_110 ;
}
if ( V_103 -> type == V_71 )
return F_39 ( & V_13 -> V_76 , V_103 , V_27 -> V_111 & V_112 ) ;
else if ( V_103 -> type == V_56 )
return F_39 ( & V_13 -> V_78 , V_103 , V_27 -> V_111 & V_112 ) ;
return - V_51 ;
}
static int F_40 ( struct V_27 * V_27 , void * V_28 ,
enum V_113 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_87 ;
int V_75 = - V_51 ;
F_16 () ;
if ( type == V_71 ) {
if ( V_13 -> V_15 == V_84 ) {
V_13 -> V_95 = 0 ;
V_13 -> V_90 = 0 ;
V_13 -> V_22 = V_93 ;
V_13 -> V_92 = V_93 ;
F_41 ( V_13 ) ;
F_42 ( V_13 ) ;
F_30 ( & V_32 -> V_98 , V_87 ) ;
F_31 ( V_13 -> V_99 , & V_32 -> V_100 ) ;
F_32 ( & V_32 -> V_98 , V_87 ) ;
F_17 ( V_13 ) ;
F_33 ( V_32 ) ;
if ( F_18 ( V_13 ,
V_114 , 0 ) ) {
F_19 ( L_26 ) ;
F_43 ( V_13 ) ;
F_44 ( V_13 ) ;
return - V_110 ;
}
F_3 ( 2 , L_27 , V_13 -> V_115 ) ;
}
V_75 = F_45 ( & V_13 -> V_76 , type ) ;
}
else if ( type == V_56 )
V_75 = F_45 ( & V_13 -> V_78 , type ) ;
F_20 () ;
return V_75 ;
}
static int F_46 ( struct V_27 * V_27 , void * V_28 ,
enum V_113 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( type == V_71 )
return F_47 ( & V_13 -> V_76 , type ) ;
else if ( type == V_56 )
return F_47 ( & V_13 -> V_78 , type ) ;
return - V_51 ;
}
static int F_48 ( struct V_116 * V_117 )
{
struct V_12 * V_13 = F_49 ( V_117 ) ;
switch ( V_117 -> V_118 ) {
case V_119 :
V_13 -> V_120 = V_117 -> V_121 ;
break;
case V_122 :
V_13 -> V_123 = V_117 -> V_121 ;
break;
case V_124 :
V_13 -> V_125 = V_117 -> V_121 ;
break;
case V_126 :
V_13 -> V_127 = V_117 -> V_121 ;
break;
default:
F_19 ( L_28 , V_117 -> V_118 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_50 ( struct V_116 * V_117 )
{
struct V_12 * V_13 = F_49 ( V_117 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_117 -> V_118 ) {
case V_128 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_117 -> V_121 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_84 ) {
F_23 ( & V_32 -> V_79 , L_29 ) ;
return - V_51 ;
}
F_17 ( V_13 ) ;
F_18 ( V_13 ,
V_57 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_58 ) {
V_117 -> V_121 = V_13 -> V_19 ;
} else {
F_23 ( & V_32 -> V_79 , L_29 ) ;
return - V_51 ;
}
break;
}
return 0 ;
}
static int F_51 ( struct V_27 * V_27 , void * V_28 ,
struct V_129 * V_130 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
T_1 V_131 , V_132 , V_133 , V_134 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_135 ) {
F_19 ( L_30 ) ;
return - V_51 ;
}
if ( V_13 -> V_73 -> V_8 == V_136 ) {
V_131 = F_52 ( V_13 , V_137 ) ;
V_132 = V_131 >> V_138 ;
V_131 = V_131 & V_139 ;
V_133 = F_52 ( V_13 , V_140 ) ;
V_134 = V_133 >> V_141 ;
V_133 = V_133 & V_142 ;
V_130 -> V_143 . V_131 = V_131 ;
V_130 -> V_143 . V_133 = V_133 ;
V_130 -> V_143 . V_59 = V_13 -> V_144 - V_131 - V_132 ;
V_130 -> V_143 . V_61 = V_13 -> V_145 - V_133 - V_134 ;
F_3 ( 2 , L_31
L_32 , V_131 , V_133 ,
V_130 -> V_143 . V_59 , V_130 -> V_143 . V_61 , V_132 , V_134 ,
V_13 -> V_60 , V_13 -> V_62 ) ;
} else {
V_130 -> V_143 . V_131 = 0 ;
V_130 -> V_143 . V_133 = 0 ;
V_130 -> V_143 . V_59 = V_13 -> V_144 ;
V_130 -> V_143 . V_61 = V_13 -> V_145 ;
F_3 ( 2 , L_33
L_34 , V_130 -> V_143 . V_59 , V_130 -> V_143 . V_61 , V_13 -> V_60 ,
V_13 -> V_62 ) ;
}
return 0 ;
}
static int F_53 ( struct V_146 * V_147 ,
const struct V_2 * V_9 , unsigned int * V_148 ,
unsigned int * V_149 , unsigned int V_150 [] ,
void * V_151 [] )
{
struct V_12 * V_13 = F_15 ( V_147 -> V_152 ) ;
if ( V_13 -> V_15 == V_84 &&
V_147 -> type == V_71 ) {
* V_149 = 1 ;
if ( * V_148 < 1 )
* V_148 = 1 ;
if ( * V_148 > V_153 )
* V_148 = V_153 ;
} else if ( V_13 -> V_15 == V_21 &&
V_147 -> type == V_56 ) {
* V_149 = 2 ;
if ( * V_148 < V_13 -> V_19 )
* V_148 = V_13 -> V_19 ;
if ( * V_148 > V_13 -> V_19 + V_154 )
* V_148 = V_13 -> V_19 + V_154 ;
if ( * V_148 > V_153 )
* V_148 = V_153 ;
} else {
F_19 ( L_35 ,
V_13 -> V_15 , V_147 -> type ) ;
return - V_51 ;
}
F_3 ( 2 , L_36 ,
* V_148 , * V_149 ) ;
if ( V_13 -> V_15 == V_21 &&
V_147 -> type == V_56 ) {
V_150 [ 0 ] = V_13 -> V_69 ;
V_150 [ 1 ] = V_13 -> V_70 ;
V_151 [ 0 ] = V_13 -> V_32 -> V_155 [ V_156 ] ;
V_151 [ 1 ] = V_13 -> V_32 -> V_155 [ V_157 ] ;
} else if ( V_147 -> type == V_71 &&
V_13 -> V_15 == V_84 ) {
V_150 [ 0 ] = V_13 -> V_72 ;
V_151 [ 0 ] = V_13 -> V_32 -> V_155 [ V_157 ] ;
} else {
F_19 ( L_37 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_54 ( struct V_146 * V_158 )
{
struct V_12 * V_13 = F_15 ( V_158 -> V_152 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_55 ( & V_32 -> V_159 ) ;
}
static void F_56 ( struct V_146 * V_158 )
{
struct V_12 * V_13 = F_15 ( V_158 -> V_152 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_57 ( & V_32 -> V_159 ) ;
}
static int F_58 ( struct V_160 * V_161 )
{
struct V_146 * V_147 = V_161 -> V_146 ;
struct V_12 * V_13 = F_15 ( V_147 -> V_152 ) ;
unsigned int V_5 ;
if ( V_147 -> type == V_56 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 <= V_13 -> V_73 -> V_47 ; V_5 ++ ) {
if ( F_59 ( F_60 (
F_61 ( V_161 , V_5 ) ) ) ) {
F_19 ( L_38 ) ;
return - V_51 ;
}
}
if ( F_62 ( V_161 , 0 ) < V_13 -> V_69 ||
F_62 ( V_161 , 1 ) < V_13 -> V_70 ) {
F_19 ( L_39 ) ;
return - V_51 ;
}
V_5 = V_161 -> V_162 . V_50 ;
V_13 -> V_163 [ V_5 ] . V_164 = V_161 ;
V_13 -> V_163 [ V_5 ] . V_165 . V_166 . V_167 =
F_61 ( V_161 , 0 ) ;
V_13 -> V_163 [ V_5 ] . V_165 . V_166 . V_168 =
F_61 ( V_161 , 1 ) ;
V_13 -> V_95 ++ ;
} else if ( V_147 -> type == V_71 ) {
if ( F_59 ( F_60 (
F_61 ( V_161 , 0 ) ) ) ) {
F_19 ( L_40 ) ;
return - V_51 ;
}
if ( F_62 ( V_161 , 0 ) < V_13 -> V_72 ) {
F_19 ( L_41 ) ;
return - V_51 ;
}
V_5 = V_161 -> V_162 . V_50 ;
V_13 -> V_169 [ V_5 ] . V_164 = V_161 ;
V_13 -> V_169 [ V_5 ] . V_165 . V_170 =
F_61 ( V_161 , 0 ) ;
V_13 -> V_90 ++ ;
} else {
F_19 ( L_42 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_63 ( struct V_146 * V_158 , unsigned int V_91 )
{
struct V_12 * V_13 = F_15 ( V_158 -> V_152 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_87 ;
F_64 ( & V_13 -> V_171 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_135 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) ) {
F_30 ( & V_32 -> V_98 , V_87 ) ;
F_31 ( V_13 -> V_99 , & V_32 -> V_100 ) ;
F_32 ( & V_32 -> V_98 , V_87 ) ;
}
F_33 ( V_32 ) ;
return 0 ;
}
static int F_65 ( struct V_146 * V_158 )
{
unsigned long V_87 ;
struct V_12 * V_13 = F_15 ( V_158 -> V_152 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_172 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_173 == V_13 -> V_99 && V_32 -> V_174 ) {
V_13 -> V_15 = V_58 ;
F_18 ( V_13 ,
V_175 , 0 ) ;
V_172 = 1 ;
}
F_30 ( & V_32 -> V_176 , V_87 ) ;
if ( V_158 -> type == V_56 ) {
F_66 ( & V_13 -> V_177 , & V_13 -> V_78 ) ;
F_67 ( & V_13 -> V_177 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_178 = 1 ;
V_13 -> V_179 = 0 ;
}
if ( V_158 -> type == V_71 ) {
F_66 ( & V_13 -> V_180 , & V_13 -> V_76 ) ;
F_67 ( & V_13 -> V_180 ) ;
V_13 -> V_14 = 0 ;
}
if ( V_172 )
V_13 -> V_15 = V_17 ;
F_32 ( & V_32 -> V_176 , V_87 ) ;
return 0 ;
}
static void F_68 ( struct V_160 * V_161 )
{
struct V_146 * V_147 = V_161 -> V_146 ;
struct V_12 * V_13 = F_15 ( V_147 -> V_152 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_87 ;
struct V_181 * V_182 ;
if ( V_147 -> type == V_71 ) {
V_182 = & V_13 -> V_169 [ V_161 -> V_162 . V_50 ] ;
V_182 -> V_183 = 0 ;
F_30 ( & V_32 -> V_176 , V_87 ) ;
F_69 ( & V_182 -> V_184 , & V_13 -> V_180 ) ;
V_13 -> V_14 ++ ;
F_32 ( & V_32 -> V_176 , V_87 ) ;
} else if ( V_147 -> type == V_56 ) {
V_182 = & V_13 -> V_163 [ V_161 -> V_162 . V_50 ] ;
V_182 -> V_183 = 0 ;
F_30 ( & V_32 -> V_176 , V_87 ) ;
F_31 ( V_161 -> V_162 . V_50 , & V_13 -> V_179 ) ;
F_69 ( & V_182 -> V_184 , & V_13 -> V_177 ) ;
V_13 -> V_18 ++ ;
F_32 ( & V_32 -> V_176 , V_87 ) ;
} else {
F_19 ( L_43 , V_147 -> type ) ;
}
if ( F_2 ( V_13 ) ) {
F_30 ( & V_32 -> V_98 , V_87 ) ;
F_31 ( V_13 -> V_99 , & V_32 -> V_100 ) ;
F_32 ( & V_32 -> V_98 , V_87 ) ;
}
F_33 ( V_32 ) ;
}
struct V_185 * F_70 ( void )
{
return & V_186 ;
}
struct V_187 * F_71 ( void )
{
return & V_188 ;
}
const struct V_189 * F_72 ( void )
{
return & V_190 ;
}
int F_73 ( struct V_12 * V_13 )
{
struct V_191 V_192 ;
int V_5 ;
F_74 ( & V_13 -> V_171 , V_193 ) ;
if ( V_13 -> V_171 . error ) {
F_19 ( L_44 ) ;
return V_13 -> V_171 . error ;
}
for ( V_5 = 0 ; V_5 < V_193 ; V_5 ++ ) {
if ( F_75 ( V_194 [ V_5 ] . V_118 ) ) {
memset ( & V_192 , 0 , sizeof( struct V_191 ) ) ;
V_192 . V_195 = & V_196 ;
V_192 . V_118 = V_194 [ V_5 ] . V_118 ;
V_192 . V_197 = V_194 [ V_5 ] . V_198 ;
V_192 . V_199 = V_194 [ V_5 ] . V_200 ;
V_192 . V_201 = V_194 [ V_5 ] . V_202 ;
V_192 . V_35 = V_194 [ V_5 ] . V_35 ;
V_192 . type = V_194 [ V_5 ] . type ;
V_192 . V_203 = V_194 [ V_5 ] . V_203 ;
V_192 . V_204 = 0 ;
V_13 -> V_205 [ V_5 ] = F_76 ( & V_13 -> V_171 ,
& V_192 , NULL ) ;
} else {
V_13 -> V_205 [ V_5 ] = F_77 ( & V_13 -> V_171 ,
& V_196 ,
V_194 [ V_5 ] . V_118 , V_194 [ V_5 ] . V_198 ,
V_194 [ V_5 ] . V_200 , V_194 [ V_5 ] . V_203 ,
V_194 [ V_5 ] . V_202 ) ;
}
if ( V_13 -> V_171 . error ) {
F_19 ( L_45 , V_5 ) ;
return V_13 -> V_171 . error ;
}
if ( V_194 [ V_5 ] . V_206 && V_13 -> V_205 [ V_5 ] )
V_13 -> V_205 [ V_5 ] -> V_87 |= V_207 ;
}
return 0 ;
}
void F_78 ( struct V_12 * V_13 )
{
int V_5 ;
F_79 ( & V_13 -> V_171 ) ;
for ( V_5 = 0 ; V_5 < V_193 ; V_5 ++ )
V_13 -> V_205 [ V_5 ] = NULL ;
}
