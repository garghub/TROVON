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
V_10 -> V_11 = V_66 ;
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
struct V_1 * V_9 ;
if ( V_3 -> type != V_72 ) {
F_19 ( L_4 ) ;
return - V_52 ;
}
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 ) {
F_19 ( L_5 ) ;
return - V_52 ;
}
if ( V_9 -> type != V_49 ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_22 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_76 = 0 ;
struct V_1 * V_9 ;
struct V_56 * V_10 ;
F_16 () ;
V_76 = F_21 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_76 )
return V_76 ;
if ( V_13 -> V_77 . V_78 || V_13 -> V_79 . V_78 ) {
F_23 ( & V_32 -> V_80 , L_7 , V_75 ) ;
V_76 = - V_81 ;
goto V_46;
}
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 || V_9 -> V_82 == V_83 ) {
F_19 ( L_8 ) ;
V_76 = - V_52 ;
goto V_46;
}
if ( V_9 -> type != V_49 ) {
F_19 ( L_9
L_10 ) ;
V_76 = - V_52 ;
goto V_46;
}
V_13 -> V_74 = V_9 ;
V_13 -> V_82 = V_9 -> V_82 ;
F_3 ( 2 , L_11 , V_13 -> V_82 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_60 = 0 ;
if ( V_10 -> V_67 [ 0 ] . V_69 )
V_13 -> V_73 = V_10 -> V_67 [ 0 ] . V_69 ;
else
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_73 =
V_84 ;
V_10 -> V_67 [ 0 ] . V_68 = 0 ;
V_13 -> V_15 = V_85 ;
V_46:
F_20 () ;
return V_76 ;
}
static int F_24 ( struct V_27 * V_27 , void * V_28 ,
struct V_86 * V_87 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_76 = 0 ;
unsigned long V_88 ;
if ( V_87 -> V_89 != V_90 ) {
F_19 ( L_12 ) ;
return - V_52 ;
}
if ( V_87 -> type == V_72 ) {
if ( V_13 -> V_15 == V_85 ) {
V_13 -> V_91 = 0 ;
if ( V_87 -> V_92 == 0 ) {
F_3 ( 2 , L_13 ) ;
F_25 () ;
V_76 = F_26 ( & V_13 -> V_77 , V_87 ) ;
F_27 () ;
return V_76 ;
}
if ( V_13 -> V_93 != V_94 ) {
F_19 ( L_14 ) ;
return - V_52 ;
}
F_25 () ;
V_76 = F_26 ( & V_13 -> V_77 , V_87 ) ;
F_27 () ;
if ( V_76 ) {
F_19 ( L_15 ) ;
return V_76 ;
}
F_3 ( 2 , L_16 , V_76 ) ;
V_13 -> V_93 = V_95 ;
}
} else if ( V_87 -> type == V_57 ) {
V_13 -> V_96 = 0 ;
if ( V_87 -> V_92 == 0 ) {
F_3 ( 2 , L_13 ) ;
F_25 () ;
V_76 = F_26 ( & V_13 -> V_79 , V_87 ) ;
F_27 () ;
return V_76 ;
}
if ( V_13 -> V_22 != V_94 ) {
F_19 ( L_14 ) ;
return - V_52 ;
}
V_13 -> V_22 = V_95 ;
F_25 () ;
V_76 = F_26 ( & V_13 -> V_79 , V_87 ) ;
F_27 () ;
if ( V_76 ) {
F_19 ( L_17 ) ;
return V_76 ;
}
if ( V_87 -> V_92 < V_13 -> V_19 ) {
F_19 ( L_18 ) ;
V_87 -> V_92 = 0 ;
F_25 () ;
V_76 = F_26 ( & V_13 -> V_79 , V_87 ) ;
F_27 () ;
return - V_97 ;
}
V_13 -> V_98 = V_87 -> V_92 ;
V_76 = F_28 ( V_13 ) ;
if ( V_76 ) {
F_19 ( L_19 ) ;
V_87 -> V_92 = 0 ;
F_25 () ;
V_76 = F_26 ( & V_13 -> V_79 , V_87 ) ;
F_27 () ;
return - V_97 ;
}
if ( V_13 -> V_96 == V_13 -> V_98 ) {
V_13 -> V_22 = V_23 ;
} else {
F_19 ( L_20 ) ;
V_87 -> V_92 = 0 ;
F_25 () ;
V_76 = F_26 ( & V_13 -> V_79 , V_87 ) ;
F_29 ( V_13 ) ;
F_27 () ;
return - V_97 ;
}
if ( F_2 ( V_13 ) ) {
F_30 ( & V_32 -> V_99 , V_88 ) ;
F_31 ( V_13 -> V_100 , & V_32 -> V_101 ) ;
F_32 ( & V_32 -> V_99 , V_88 ) ;
}
F_33 ( V_32 ) ;
F_18 ( V_13 ,
V_102 , 0 ) ;
}
return V_76 ;
}
static int F_34 ( struct V_27 * V_27 , void * V_28 ,
struct V_103 * V_104 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_76 ;
int V_5 ;
if ( V_104 -> V_89 != V_90 ) {
F_19 ( L_21 ) ;
return - V_52 ;
}
F_3 ( 2 , L_22 , V_13 -> V_15 , V_104 -> type ) ;
if ( V_13 -> V_15 == V_85 &&
V_104 -> type == V_72 ) {
V_76 = F_35 ( & V_13 -> V_77 , V_104 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_104 -> type == V_57 ) {
V_76 = F_35 ( & V_13 -> V_79 , V_104 ) ;
for ( V_5 = 0 ; V_5 < V_104 -> V_105 ; V_5 ++ )
V_104 -> V_106 . V_107 [ V_5 ] . V_106 . V_108 += V_109 ;
} else {
F_19 ( L_23 ) ;
V_76 = - V_52 ;
}
F_20 () ;
return V_76 ;
}
static int F_36 ( struct V_27 * V_27 , void * V_28 , struct V_103 * V_104 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_110 ) {
F_19 ( L_24 ) ;
return - V_111 ;
}
if ( V_104 -> type == V_72 )
return F_37 ( & V_13 -> V_77 , V_104 ) ;
else if ( V_104 -> type == V_57 )
return F_37 ( & V_13 -> V_79 , V_104 ) ;
return - V_52 ;
}
static int F_38 ( struct V_27 * V_27 , void * V_28 , struct V_103 * V_104 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_110 ) {
F_19 ( L_25 ) ;
return - V_111 ;
}
if ( V_104 -> type == V_72 )
return F_39 ( & V_13 -> V_77 , V_104 , V_27 -> V_112 & V_113 ) ;
else if ( V_104 -> type == V_57 )
return F_39 ( & V_13 -> V_79 , V_104 , V_27 -> V_112 & V_113 ) ;
return - V_52 ;
}
static int F_40 ( struct V_27 * V_27 , void * V_28 ,
enum V_114 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_88 ;
int V_76 = - V_52 ;
F_16 () ;
if ( type == V_72 ) {
if ( V_13 -> V_15 == V_85 ) {
V_13 -> V_96 = 0 ;
V_13 -> V_91 = 0 ;
V_13 -> V_22 = V_94 ;
V_13 -> V_93 = V_94 ;
F_41 ( V_13 ) ;
F_42 ( V_13 ) ;
F_30 ( & V_32 -> V_99 , V_88 ) ;
F_31 ( V_13 -> V_100 , & V_32 -> V_101 ) ;
F_32 ( & V_32 -> V_99 , V_88 ) ;
F_17 ( V_13 ) ;
F_33 ( V_32 ) ;
if ( F_18 ( V_13 ,
V_115 , 0 ) ) {
F_19 ( L_26 ) ;
F_43 ( V_13 ) ;
F_44 ( V_13 ) ;
return - V_111 ;
}
F_3 ( 2 , L_27 , V_13 -> V_116 ) ;
}
V_76 = F_45 ( & V_13 -> V_77 , type ) ;
}
else if ( type == V_57 )
V_76 = F_45 ( & V_13 -> V_79 , type ) ;
F_20 () ;
return V_76 ;
}
static int F_46 ( struct V_27 * V_27 , void * V_28 ,
enum V_114 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( type == V_72 )
return F_47 ( & V_13 -> V_77 , type ) ;
else if ( type == V_57 )
return F_47 ( & V_13 -> V_79 , type ) ;
return - V_52 ;
}
static int F_48 ( struct V_117 * V_118 )
{
struct V_12 * V_13 = F_49 ( V_118 ) ;
switch ( V_118 -> V_119 ) {
case V_120 :
V_13 -> V_121 = V_118 -> V_122 ;
break;
case V_123 :
V_13 -> V_124 = V_118 -> V_122 ;
break;
case V_125 :
V_13 -> V_126 = V_118 -> V_122 ;
break;
case V_127 :
V_13 -> V_128 = V_118 -> V_122 ;
break;
default:
F_19 ( L_28 , V_118 -> V_119 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_50 ( struct V_117 * V_118 )
{
struct V_12 * V_13 = F_49 ( V_118 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_118 -> V_119 ) {
case V_129 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_118 -> V_122 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_85 ) {
F_23 ( & V_32 -> V_80 , L_29 ) ;
return - V_52 ;
}
F_17 ( V_13 ) ;
F_18 ( V_13 ,
V_58 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_118 -> V_122 = V_13 -> V_19 ;
} else {
F_23 ( & V_32 -> V_80 , L_29 ) ;
return - V_52 ;
}
break;
}
return 0 ;
}
static int F_51 ( struct V_27 * V_27 , void * V_28 ,
struct V_130 * V_131 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
T_1 V_132 , V_133 , V_134 , V_135 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_136 ) {
F_19 ( L_30 ) ;
return - V_52 ;
}
if ( V_13 -> V_74 -> V_8 == V_137 ) {
V_132 = F_52 ( V_13 , V_138 ) ;
V_133 = V_132 >> V_139 ;
V_132 = V_132 & V_140 ;
V_134 = F_52 ( V_13 , V_141 ) ;
V_135 = V_134 >> V_142 ;
V_134 = V_134 & V_143 ;
V_131 -> V_144 . V_132 = V_132 ;
V_131 -> V_144 . V_134 = V_134 ;
V_131 -> V_144 . V_60 = V_13 -> V_145 - V_132 - V_133 ;
V_131 -> V_144 . V_62 = V_13 -> V_146 - V_134 - V_135 ;
F_3 ( 2 , L_31
L_32 , V_132 , V_134 ,
V_131 -> V_144 . V_60 , V_131 -> V_144 . V_62 , V_133 , V_135 ,
V_13 -> V_61 , V_13 -> V_63 ) ;
} else {
V_131 -> V_144 . V_132 = 0 ;
V_131 -> V_144 . V_134 = 0 ;
V_131 -> V_144 . V_60 = V_13 -> V_145 ;
V_131 -> V_144 . V_62 = V_13 -> V_146 ;
F_3 ( 2 , L_33
L_34 , V_131 -> V_144 . V_60 , V_131 -> V_144 . V_62 , V_13 -> V_61 ,
V_13 -> V_63 ) ;
}
return 0 ;
}
static int F_53 ( struct V_147 * V_148 ,
const struct V_2 * V_9 , unsigned int * V_149 ,
unsigned int * V_150 , unsigned int V_151 [] ,
void * V_152 [] )
{
struct V_12 * V_13 = F_15 ( V_148 -> V_153 ) ;
if ( V_13 -> V_15 == V_85 &&
V_148 -> type == V_72 ) {
* V_150 = 1 ;
if ( * V_149 < 1 )
* V_149 = 1 ;
if ( * V_149 > V_154 )
* V_149 = V_154 ;
} else if ( V_13 -> V_15 == V_21 &&
V_148 -> type == V_57 ) {
* V_150 = 2 ;
if ( * V_149 < V_13 -> V_19 )
* V_149 = V_13 -> V_19 ;
if ( * V_149 > V_13 -> V_19 + V_155 )
* V_149 = V_13 -> V_19 + V_155 ;
if ( * V_149 > V_154 )
* V_149 = V_154 ;
} else {
F_19 ( L_35 ,
V_13 -> V_15 , V_148 -> type ) ;
return - V_52 ;
}
F_3 ( 2 , L_36 ,
* V_149 , * V_150 ) ;
if ( V_13 -> V_15 == V_21 &&
V_148 -> type == V_57 ) {
V_151 [ 0 ] = V_13 -> V_70 ;
V_151 [ 1 ] = V_13 -> V_71 ;
V_152 [ 0 ] = V_13 -> V_32 -> V_156 [ V_157 ] ;
V_152 [ 1 ] = V_13 -> V_32 -> V_156 [ V_158 ] ;
} else if ( V_148 -> type == V_72 &&
V_13 -> V_15 == V_85 ) {
V_151 [ 0 ] = V_13 -> V_73 ;
V_152 [ 0 ] = V_13 -> V_32 -> V_156 [ V_158 ] ;
} else {
F_19 ( L_37 ) ;
return - V_52 ;
}
return 0 ;
}
static void F_54 ( struct V_147 * V_159 )
{
struct V_12 * V_13 = F_15 ( V_159 -> V_153 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_55 ( & V_32 -> V_160 ) ;
}
static void F_56 ( struct V_147 * V_159 )
{
struct V_12 * V_13 = F_15 ( V_159 -> V_153 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_57 ( & V_32 -> V_160 ) ;
}
static int F_58 ( struct V_161 * V_162 )
{
struct V_147 * V_148 = V_162 -> V_147 ;
struct V_12 * V_13 = F_15 ( V_148 -> V_153 ) ;
unsigned int V_5 ;
if ( V_148 -> type == V_57 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 <= V_13 -> V_74 -> V_48 ; V_5 ++ ) {
if ( F_59 ( F_60 (
F_61 ( V_162 , V_5 ) ) ) ) {
F_19 ( L_38 ) ;
return - V_52 ;
}
}
if ( F_62 ( V_162 , 0 ) < V_13 -> V_70 ||
F_62 ( V_162 , 1 ) < V_13 -> V_71 ) {
F_19 ( L_39 ) ;
return - V_52 ;
}
V_5 = V_162 -> V_163 . V_51 ;
V_13 -> V_164 [ V_5 ] . V_165 = V_162 ;
V_13 -> V_164 [ V_5 ] . V_166 . V_167 . V_168 =
F_61 ( V_162 , 0 ) ;
V_13 -> V_164 [ V_5 ] . V_166 . V_167 . V_169 =
F_61 ( V_162 , 1 ) ;
V_13 -> V_96 ++ ;
} else if ( V_148 -> type == V_72 ) {
if ( F_59 ( F_60 (
F_61 ( V_162 , 0 ) ) ) ) {
F_19 ( L_40 ) ;
return - V_52 ;
}
if ( F_62 ( V_162 , 0 ) < V_13 -> V_73 ) {
F_19 ( L_41 ) ;
return - V_52 ;
}
V_5 = V_162 -> V_163 . V_51 ;
V_13 -> V_170 [ V_5 ] . V_165 = V_162 ;
V_13 -> V_170 [ V_5 ] . V_166 . V_171 =
F_61 ( V_162 , 0 ) ;
V_13 -> V_91 ++ ;
} else {
F_19 ( L_42 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_63 ( struct V_147 * V_159 , unsigned int V_92 )
{
struct V_12 * V_13 = F_15 ( V_159 -> V_153 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_88 ;
F_64 ( & V_13 -> V_172 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_136 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) ) {
F_30 ( & V_32 -> V_99 , V_88 ) ;
F_31 ( V_13 -> V_100 , & V_32 -> V_101 ) ;
F_32 ( & V_32 -> V_99 , V_88 ) ;
}
F_33 ( V_32 ) ;
return 0 ;
}
static int F_65 ( struct V_147 * V_159 )
{
unsigned long V_88 ;
struct V_12 * V_13 = F_15 ( V_159 -> V_153 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_173 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_174 == V_13 -> V_100 && V_32 -> V_175 ) {
V_13 -> V_15 = V_59 ;
F_18 ( V_13 ,
V_176 , 0 ) ;
V_173 = 1 ;
}
F_30 ( & V_32 -> V_177 , V_88 ) ;
if ( V_159 -> type == V_57 ) {
F_66 ( & V_13 -> V_178 , & V_13 -> V_79 ) ;
F_67 ( & V_13 -> V_178 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_179 = 1 ;
V_13 -> V_180 = 0 ;
}
if ( V_159 -> type == V_72 ) {
F_66 ( & V_13 -> V_181 , & V_13 -> V_77 ) ;
F_67 ( & V_13 -> V_181 ) ;
V_13 -> V_14 = 0 ;
}
if ( V_173 )
V_13 -> V_15 = V_17 ;
F_32 ( & V_32 -> V_177 , V_88 ) ;
return 0 ;
}
static void F_68 ( struct V_161 * V_162 )
{
struct V_147 * V_148 = V_162 -> V_147 ;
struct V_12 * V_13 = F_15 ( V_148 -> V_153 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_88 ;
struct V_182 * V_183 ;
if ( V_148 -> type == V_72 ) {
V_183 = & V_13 -> V_170 [ V_162 -> V_163 . V_51 ] ;
V_183 -> V_184 = 0 ;
F_30 ( & V_32 -> V_177 , V_88 ) ;
F_69 ( & V_183 -> V_185 , & V_13 -> V_181 ) ;
V_13 -> V_14 ++ ;
F_32 ( & V_32 -> V_177 , V_88 ) ;
} else if ( V_148 -> type == V_57 ) {
V_183 = & V_13 -> V_164 [ V_162 -> V_163 . V_51 ] ;
V_183 -> V_184 = 0 ;
F_30 ( & V_32 -> V_177 , V_88 ) ;
F_31 ( V_162 -> V_163 . V_51 , & V_13 -> V_180 ) ;
F_69 ( & V_183 -> V_185 , & V_13 -> V_178 ) ;
V_13 -> V_18 ++ ;
F_32 ( & V_32 -> V_177 , V_88 ) ;
} else {
F_19 ( L_43 , V_148 -> type ) ;
}
if ( F_2 ( V_13 ) ) {
F_30 ( & V_32 -> V_99 , V_88 ) ;
F_31 ( V_13 -> V_100 , & V_32 -> V_101 ) ;
F_32 ( & V_32 -> V_99 , V_88 ) ;
}
F_33 ( V_32 ) ;
}
struct V_186 * F_70 ( void )
{
return & V_187 ;
}
struct V_188 * F_71 ( void )
{
return & V_189 ;
}
const struct V_190 * F_72 ( void )
{
return & V_191 ;
}
int F_73 ( struct V_12 * V_13 )
{
struct V_192 V_193 ;
int V_5 ;
F_74 ( & V_13 -> V_172 , V_194 ) ;
if ( V_13 -> V_172 . error ) {
F_19 ( L_44 ) ;
return V_13 -> V_172 . error ;
}
for ( V_5 = 0 ; V_5 < V_194 ; V_5 ++ ) {
if ( F_75 ( V_195 [ V_5 ] . V_119 ) ) {
memset ( & V_193 , 0 , sizeof( struct V_192 ) ) ;
V_193 . V_196 = & V_197 ;
V_193 . V_119 = V_195 [ V_5 ] . V_119 ;
V_193 . V_198 = V_195 [ V_5 ] . V_199 ;
V_193 . V_200 = V_195 [ V_5 ] . V_201 ;
V_193 . V_202 = V_195 [ V_5 ] . V_203 ;
V_193 . V_35 = V_195 [ V_5 ] . V_35 ;
V_193 . type = V_195 [ V_5 ] . type ;
V_193 . V_204 = V_195 [ V_5 ] . V_204 ;
V_193 . V_205 = 0 ;
V_13 -> V_206 [ V_5 ] = F_76 ( & V_13 -> V_172 ,
& V_193 , NULL ) ;
} else {
V_13 -> V_206 [ V_5 ] = F_77 ( & V_13 -> V_172 ,
& V_197 ,
V_195 [ V_5 ] . V_119 , V_195 [ V_5 ] . V_199 ,
V_195 [ V_5 ] . V_201 , V_195 [ V_5 ] . V_204 ,
V_195 [ V_5 ] . V_203 ) ;
}
if ( V_13 -> V_172 . error ) {
F_19 ( L_45 , V_5 ) ;
return V_13 -> V_172 . error ;
}
if ( V_195 [ V_5 ] . V_207 && V_13 -> V_206 [ V_5 ] )
V_13 -> V_206 [ V_5 ] -> V_88 |= V_208 ;
}
return 0 ;
}
void F_78 ( struct V_12 * V_13 )
{
int V_5 ;
F_79 ( & V_13 -> V_172 ) ;
for ( V_5 = 0 ; V_5 < V_194 ; V_5 ++ )
V_13 -> V_206 [ V_5 ] = NULL ;
}
