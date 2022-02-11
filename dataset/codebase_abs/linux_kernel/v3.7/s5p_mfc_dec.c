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
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_1 * V_9 ;
F_3 ( 2 , L_4 , V_3 -> type ) ;
if ( V_3 -> type == V_72 ) {
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 ) {
F_19 ( L_5 ) ;
return - V_52 ;
}
if ( ! F_22 ( V_32 ) && ( V_9 -> V_8 == V_76 ) ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
} else if ( V_3 -> type == V_57 ) {
V_9 = F_1 ( V_3 , V_50 ) ;
if ( ! V_9 ) {
F_19 ( L_7 ) ;
return - V_52 ;
}
if ( F_22 ( V_32 ) && ( V_9 -> V_8 == V_66 ) ) {
F_19 ( L_6 ) ;
return - V_52 ;
} else if ( ! F_22 ( V_32 ) &&
( V_9 -> V_8 != V_66 ) ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
}
return 0 ;
}
static int F_23 ( struct V_27 * V_27 , void * V_28 , struct V_2 * V_3 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_77 = 0 ;
struct V_1 * V_9 ;
struct V_56 * V_10 ;
F_16 () ;
V_77 = F_21 ( V_27 , V_28 , V_3 ) ;
V_10 = & V_3 -> V_9 . V_10 ;
if ( V_77 )
return V_77 ;
if ( V_13 -> V_78 . V_79 || V_13 -> V_80 . V_79 ) {
F_24 ( & V_32 -> V_81 , L_8 , V_75 ) ;
V_77 = - V_82 ;
goto V_46;
}
if ( V_3 -> type == V_57 ) {
V_9 = F_1 ( V_3 , V_50 ) ;
if ( ! V_9 ) {
F_19 ( L_5 ) ;
return - V_52 ;
}
if ( ! F_22 ( V_32 ) && ( V_9 -> V_8 != V_66 ) ) {
F_19 ( L_6 ) ;
return - V_52 ;
} else if ( F_22 ( V_32 ) &&
( V_9 -> V_8 == V_66 ) ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
V_13 -> V_83 = V_9 ;
F_20 () ;
return V_77 ;
} else if ( V_3 -> type != V_72 ) {
F_19 ( L_9 , V_3 -> type ) ;
return - V_52 ;
}
V_9 = F_1 ( V_3 , V_49 ) ;
if ( ! V_9 || V_9 -> V_84 == V_85 ) {
F_19 ( L_10 ) ;
V_77 = - V_52 ;
goto V_46;
}
if ( V_9 -> type != V_49 ) {
F_19 ( L_11
L_12 ) ;
V_77 = - V_52 ;
goto V_46;
}
if ( ! F_22 ( V_32 ) && ( V_9 -> V_8 == V_76 ) ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
V_13 -> V_74 = V_9 ;
V_13 -> V_84 = V_9 -> V_84 ;
F_3 ( 2 , L_13 , V_13 -> V_84 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_60 = 0 ;
if ( V_10 -> V_67 [ 0 ] . V_69 )
V_13 -> V_73 = V_10 -> V_67 [ 0 ] . V_69 ;
else
V_10 -> V_67 [ 0 ] . V_69 = V_13 -> V_73 =
V_86 ;
V_10 -> V_67 [ 0 ] . V_68 = 0 ;
V_13 -> V_15 = V_87 ;
V_46:
F_20 () ;
return V_77 ;
}
static int F_25 ( struct V_27 * V_27 , void * V_28 ,
struct V_88 * V_89 )
{
struct V_31 * V_32 = F_5 ( V_27 ) ;
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_77 = 0 ;
if ( V_89 -> V_90 != V_91 ) {
F_19 ( L_14 ) ;
return - V_52 ;
}
if ( V_89 -> type == V_72 ) {
if ( V_13 -> V_15 == V_87 ) {
V_13 -> V_92 = 0 ;
if ( V_89 -> V_93 == 0 ) {
F_3 ( 2 , L_15 ) ;
F_26 () ;
V_77 = F_27 ( & V_13 -> V_78 , V_89 ) ;
F_28 () ;
return V_77 ;
}
if ( V_13 -> V_94 != V_95 ) {
F_19 ( L_16 ) ;
return - V_52 ;
}
F_26 () ;
V_77 = F_27 ( & V_13 -> V_78 , V_89 ) ;
F_28 () ;
if ( V_77 ) {
F_19 ( L_17 ) ;
return V_77 ;
}
F_3 ( 2 , L_18 , V_77 ) ;
V_13 -> V_94 = V_96 ;
}
} else if ( V_89 -> type == V_57 ) {
V_13 -> V_97 = 0 ;
if ( V_89 -> V_93 == 0 ) {
F_3 ( 2 , L_15 ) ;
F_26 () ;
V_77 = F_27 ( & V_13 -> V_80 , V_89 ) ;
F_28 () ;
return V_77 ;
}
if ( V_13 -> V_22 != V_95 ) {
F_19 ( L_16 ) ;
return - V_52 ;
}
V_13 -> V_22 = V_96 ;
F_26 () ;
V_77 = F_27 ( & V_13 -> V_80 , V_89 ) ;
F_28 () ;
if ( V_77 ) {
F_19 ( L_19 ) ;
return V_77 ;
}
if ( V_89 -> V_93 < V_13 -> V_19 ) {
F_19 ( L_20 ) ;
V_89 -> V_93 = 0 ;
F_26 () ;
V_77 = F_27 ( & V_13 -> V_80 , V_89 ) ;
F_28 () ;
return - V_98 ;
}
V_13 -> V_99 = V_89 -> V_93 ;
V_77 = F_29 ( V_32 -> V_100 , V_101 , V_13 ) ;
if ( V_77 ) {
F_19 ( L_21 ) ;
V_89 -> V_93 = 0 ;
F_26 () ;
V_77 = F_27 ( & V_13 -> V_80 , V_89 ) ;
F_28 () ;
return - V_98 ;
}
if ( V_13 -> V_97 == V_13 -> V_99 ) {
V_13 -> V_22 = V_23 ;
} else {
F_19 ( L_22 ) ;
V_89 -> V_93 = 0 ;
F_26 () ;
V_77 = F_27 ( & V_13 -> V_80 , V_89 ) ;
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
return V_77 ;
}
static int F_31 ( struct V_27 * V_27 , void * V_28 ,
struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
int V_77 ;
int V_5 ;
if ( V_106 -> V_90 != V_91 ) {
F_19 ( L_23 ) ;
return - V_52 ;
}
F_3 ( 2 , L_24 , V_13 -> V_15 , V_106 -> type ) ;
if ( V_13 -> V_15 == V_87 &&
V_106 -> type == V_72 ) {
V_77 = F_32 ( & V_13 -> V_78 , V_106 ) ;
} else if ( V_13 -> V_15 == V_17 &&
V_106 -> type == V_57 ) {
V_77 = F_32 ( & V_13 -> V_80 , V_106 ) ;
for ( V_5 = 0 ; V_5 < V_106 -> V_107 ; V_5 ++ )
V_106 -> V_108 . V_109 [ V_5 ] . V_108 . V_110 += V_111 ;
} else {
F_19 ( L_25 ) ;
V_77 = - V_52 ;
}
F_20 () ;
return V_77 ;
}
static int F_33 ( struct V_27 * V_27 , void * V_28 , struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_112 ) {
F_19 ( L_26 ) ;
return - V_113 ;
}
if ( V_106 -> type == V_72 )
return F_34 ( & V_13 -> V_78 , V_106 ) ;
else if ( V_106 -> type == V_57 )
return F_34 ( & V_13 -> V_80 , V_106 ) ;
return - V_52 ;
}
static int F_35 ( struct V_27 * V_27 , void * V_28 , struct V_105 * V_106 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( V_13 -> V_15 == V_112 ) {
F_19 ( L_27 ) ;
return - V_113 ;
}
if ( V_106 -> type == V_72 )
return F_36 ( & V_13 -> V_78 , V_106 , V_27 -> V_114 & V_115 ) ;
else if ( V_106 -> type == V_57 )
return F_36 ( & V_13 -> V_80 , V_106 , V_27 -> V_114 & V_115 ) ;
return - V_52 ;
}
static int F_37 ( struct V_27 * V_27 , void * V_28 ,
enum V_116 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_77 = - V_52 ;
F_16 () ;
if ( type == V_72 ) {
if ( V_13 -> V_15 == V_87 ) {
V_13 -> V_97 = 0 ;
V_13 -> V_92 = 0 ;
V_13 -> V_22 = V_95 ;
V_13 -> V_94 = V_95 ;
F_29 ( V_32 -> V_100 , V_117 ,
V_13 ) ;
F_29 ( V_32 -> V_100 , V_118 ,
V_13 ) ;
F_30 ( V_13 ) ;
F_17 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
if ( F_18 ( V_13 ,
V_119 , 0 ) ) {
F_19 ( L_28 ) ;
F_29 ( V_32 -> V_100 ,
V_120 , V_13 ) ;
F_29 ( V_32 -> V_100 ,
V_121 , V_13 ) ;
return - V_113 ;
}
F_3 ( 2 , L_29 , V_13 -> V_122 ) ;
}
V_77 = F_38 ( & V_13 -> V_78 , type ) ;
}
else if ( type == V_57 )
V_77 = F_38 ( & V_13 -> V_80 , type ) ;
F_20 () ;
return V_77 ;
}
static int F_39 ( struct V_27 * V_27 , void * V_28 ,
enum V_116 type )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
if ( type == V_72 )
return F_40 ( & V_13 -> V_78 , type ) ;
else if ( type == V_57 )
return F_40 ( & V_13 -> V_80 , type ) ;
return - V_52 ;
}
static int F_41 ( struct V_123 * V_124 )
{
struct V_12 * V_13 = F_42 ( V_124 ) ;
switch ( V_124 -> V_125 ) {
case V_126 :
V_13 -> V_127 = V_124 -> V_128 ;
break;
case V_129 :
V_13 -> V_130 = V_124 -> V_128 ;
break;
case V_131 :
V_13 -> V_132 = V_124 -> V_128 ;
break;
case V_133 :
V_13 -> V_134 = V_124 -> V_128 ;
break;
default:
F_19 ( L_30 , V_124 -> V_125 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_43 ( struct V_123 * V_124 )
{
struct V_12 * V_13 = F_42 ( V_124 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
switch ( V_124 -> V_125 ) {
case V_135 :
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_124 -> V_128 = V_13 -> V_19 ;
break;
} else if ( V_13 -> V_15 != V_87 ) {
F_24 ( & V_32 -> V_81 , L_31 ) ;
return - V_52 ;
}
F_17 ( V_13 ) ;
F_18 ( V_13 ,
V_58 , 0 ) ;
if ( V_13 -> V_15 >= V_21 &&
V_13 -> V_15 < V_59 ) {
V_124 -> V_128 = V_13 -> V_19 ;
} else {
F_24 ( & V_32 -> V_81 , L_31 ) ;
return - V_52 ;
}
break;
}
return 0 ;
}
static int F_44 ( struct V_27 * V_27 , void * V_28 ,
struct V_136 * V_137 )
{
struct V_12 * V_13 = F_15 ( V_28 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
T_1 V_138 , V_139 , V_140 , V_141 ;
if ( V_13 -> V_15 != V_21 &&
V_13 -> V_15 != V_17 && V_13 -> V_15 != V_20
&& V_13 -> V_15 != V_142 ) {
F_19 ( L_32 ) ;
return - V_52 ;
}
if ( V_13 -> V_74 -> V_8 == V_143 ) {
V_138 = F_29 ( V_32 -> V_100 , V_144 , V_13 ) ;
V_139 = V_138 >> V_145 ;
V_138 = V_138 & V_146 ;
V_140 = F_29 ( V_32 -> V_100 , V_147 , V_13 ) ;
V_141 = V_140 >> V_148 ;
V_140 = V_140 & V_149 ;
V_137 -> V_150 . V_138 = V_138 ;
V_137 -> V_150 . V_140 = V_140 ;
V_137 -> V_150 . V_60 = V_13 -> V_151 - V_138 - V_139 ;
V_137 -> V_150 . V_62 = V_13 -> V_152 - V_140 - V_141 ;
F_3 ( 2 , L_33
L_34 , V_138 , V_140 ,
V_137 -> V_150 . V_60 , V_137 -> V_150 . V_62 , V_139 , V_141 ,
V_13 -> V_61 , V_13 -> V_63 ) ;
} else {
V_137 -> V_150 . V_138 = 0 ;
V_137 -> V_150 . V_140 = 0 ;
V_137 -> V_150 . V_60 = V_13 -> V_151 ;
V_137 -> V_150 . V_62 = V_13 -> V_152 ;
F_3 ( 2 , L_35
L_36 , V_137 -> V_150 . V_60 , V_137 -> V_150 . V_62 , V_13 -> V_61 ,
V_13 -> V_63 ) ;
}
return 0 ;
}
static int F_45 ( struct V_153 * V_154 ,
const struct V_2 * V_9 , unsigned int * V_155 ,
unsigned int * V_156 , unsigned int V_157 [] ,
void * V_158 [] )
{
struct V_12 * V_13 = F_15 ( V_154 -> V_159 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
if ( V_13 -> V_15 == V_87 &&
V_154 -> type == V_72 ) {
* V_156 = 1 ;
if ( * V_155 < 1 )
* V_155 = 1 ;
if ( * V_155 > V_160 )
* V_155 = V_160 ;
} else if ( V_13 -> V_15 == V_21 &&
V_154 -> type == V_57 ) {
* V_156 = 2 ;
if ( * V_155 < V_13 -> V_19 )
* V_155 = V_13 -> V_19 ;
if ( * V_155 > V_13 -> V_19 + V_161 )
* V_155 = V_13 -> V_19 + V_161 ;
if ( * V_155 > V_160 )
* V_155 = V_160 ;
} else {
F_19 ( L_37 ,
V_13 -> V_15 , V_154 -> type ) ;
return - V_52 ;
}
F_3 ( 2 , L_38 ,
* V_155 , * V_156 ) ;
if ( V_13 -> V_15 == V_21 &&
V_154 -> type == V_57 ) {
V_157 [ 0 ] = V_13 -> V_70 ;
V_157 [ 1 ] = V_13 -> V_71 ;
if ( F_22 ( V_32 ) )
V_158 [ 0 ] =
V_13 -> V_32 -> V_162 [ V_163 ] ;
else
V_158 [ 0 ] =
V_13 -> V_32 -> V_162 [ V_164 ] ;
V_158 [ 1 ] = V_13 -> V_32 -> V_162 [ V_163 ] ;
} else if ( V_154 -> type == V_72 &&
V_13 -> V_15 == V_87 ) {
V_157 [ 0 ] = V_13 -> V_73 ;
V_158 [ 0 ] = V_13 -> V_32 -> V_162 [ V_163 ] ;
} else {
F_19 ( L_39 ) ;
return - V_52 ;
}
return 0 ;
}
static void F_46 ( struct V_153 * V_165 )
{
struct V_12 * V_13 = F_15 ( V_165 -> V_159 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_47 ( & V_32 -> V_166 ) ;
}
static void F_48 ( struct V_153 * V_165 )
{
struct V_12 * V_13 = F_15 ( V_165 -> V_159 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_49 ( & V_32 -> V_166 ) ;
}
static int F_50 ( struct V_167 * V_168 )
{
struct V_153 * V_154 = V_168 -> V_153 ;
struct V_12 * V_13 = F_15 ( V_154 -> V_159 ) ;
unsigned int V_5 ;
if ( V_154 -> type == V_57 ) {
if ( V_13 -> V_22 == V_23 )
return 0 ;
for ( V_5 = 0 ; V_5 <= V_13 -> V_74 -> V_48 ; V_5 ++ ) {
if ( F_51 ( F_52 (
F_53 ( V_168 , V_5 ) ) ) ) {
F_19 ( L_40 ) ;
return - V_52 ;
}
}
if ( F_54 ( V_168 , 0 ) < V_13 -> V_70 ||
F_54 ( V_168 , 1 ) < V_13 -> V_71 ) {
F_19 ( L_41 ) ;
return - V_52 ;
}
V_5 = V_168 -> V_169 . V_51 ;
V_13 -> V_170 [ V_5 ] . V_171 = V_168 ;
V_13 -> V_170 [ V_5 ] . V_172 . V_173 . V_174 =
F_53 ( V_168 , 0 ) ;
V_13 -> V_170 [ V_5 ] . V_172 . V_173 . V_175 =
F_53 ( V_168 , 1 ) ;
V_13 -> V_97 ++ ;
} else if ( V_154 -> type == V_72 ) {
if ( F_51 ( F_52 (
F_53 ( V_168 , 0 ) ) ) ) {
F_19 ( L_42 ) ;
return - V_52 ;
}
if ( F_54 ( V_168 , 0 ) < V_13 -> V_73 ) {
F_19 ( L_43 ) ;
return - V_52 ;
}
V_5 = V_168 -> V_169 . V_51 ;
V_13 -> V_176 [ V_5 ] . V_171 = V_168 ;
V_13 -> V_176 [ V_5 ] . V_172 . V_177 =
F_53 ( V_168 , 0 ) ;
V_13 -> V_92 ++ ;
} else {
F_19 ( L_44 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_55 ( struct V_153 * V_165 , unsigned int V_93 )
{
struct V_12 * V_13 = F_15 ( V_165 -> V_159 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
F_56 ( & V_13 -> V_178 ) ;
if ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_142 )
V_13 -> V_15 = V_17 ;
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
return 0 ;
}
static int F_57 ( struct V_153 * V_165 )
{
unsigned long V_179 ;
struct V_12 * V_13 = F_15 ( V_165 -> V_159 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_180 = 0 ;
if ( ( V_13 -> V_15 == V_20 ||
V_13 -> V_15 == V_17 ) &&
V_32 -> V_181 == V_13 -> V_182 && V_32 -> V_183 ) {
V_13 -> V_15 = V_59 ;
F_18 ( V_13 ,
V_184 , 0 ) ;
V_180 = 1 ;
}
F_58 ( & V_32 -> V_185 , V_179 ) ;
if ( V_165 -> type == V_57 ) {
F_29 ( V_32 -> V_100 , V_186 , & V_13 -> V_187 ,
& V_13 -> V_80 ) ;
F_59 ( & V_13 -> V_187 ) ;
V_13 -> V_18 = 0 ;
V_13 -> V_188 = 1 ;
V_13 -> V_189 = 0 ;
}
if ( V_165 -> type == V_72 ) {
F_29 ( V_32 -> V_100 , V_186 , & V_13 -> V_190 ,
& V_13 -> V_78 ) ;
F_59 ( & V_13 -> V_190 ) ;
V_13 -> V_14 = 0 ;
}
if ( V_180 )
V_13 -> V_15 = V_17 ;
F_60 ( & V_32 -> V_185 , V_179 ) ;
return 0 ;
}
static void F_61 ( struct V_167 * V_168 )
{
struct V_153 * V_154 = V_168 -> V_153 ;
struct V_12 * V_13 = F_15 ( V_154 -> V_159 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
unsigned long V_179 ;
struct V_191 * V_192 ;
if ( V_154 -> type == V_72 ) {
V_192 = & V_13 -> V_176 [ V_168 -> V_169 . V_51 ] ;
V_192 -> V_179 &= ~ V_193 ;
F_58 ( & V_32 -> V_185 , V_179 ) ;
F_62 ( & V_192 -> V_194 , & V_13 -> V_190 ) ;
V_13 -> V_14 ++ ;
F_60 ( & V_32 -> V_185 , V_179 ) ;
} else if ( V_154 -> type == V_57 ) {
V_192 = & V_13 -> V_170 [ V_168 -> V_169 . V_51 ] ;
V_192 -> V_179 &= ~ V_193 ;
F_58 ( & V_32 -> V_185 , V_179 ) ;
F_63 ( V_168 -> V_169 . V_51 , & V_13 -> V_189 ) ;
F_62 ( & V_192 -> V_194 , & V_13 -> V_187 ) ;
V_13 -> V_18 ++ ;
F_60 ( & V_32 -> V_185 , V_179 ) ;
} else {
F_19 ( L_45 , V_154 -> type ) ;
}
if ( F_2 ( V_13 ) )
F_30 ( V_13 ) ;
F_29 ( V_32 -> V_100 , V_103 , V_32 ) ;
}
struct V_195 * F_64 ( void )
{
return & V_196 ;
}
struct V_197 * F_65 ( void )
{
return & V_198 ;
}
const struct V_199 * F_66 ( void )
{
return & V_200 ;
}
int F_67 ( struct V_12 * V_13 )
{
struct V_201 V_202 ;
int V_5 ;
F_68 ( & V_13 -> V_178 , V_203 ) ;
if ( V_13 -> V_178 . error ) {
F_19 ( L_46 ) ;
return V_13 -> V_178 . error ;
}
for ( V_5 = 0 ; V_5 < V_203 ; V_5 ++ ) {
if ( F_69 ( V_204 [ V_5 ] . V_125 ) ) {
memset ( & V_202 , 0 , sizeof( struct V_201 ) ) ;
V_202 . V_205 = & V_206 ;
V_202 . V_125 = V_204 [ V_5 ] . V_125 ;
V_202 . V_207 = V_204 [ V_5 ] . V_208 ;
V_202 . V_209 = V_204 [ V_5 ] . V_210 ;
V_202 . V_211 = V_204 [ V_5 ] . V_212 ;
V_202 . V_35 = V_204 [ V_5 ] . V_35 ;
V_202 . type = V_204 [ V_5 ] . type ;
V_202 . V_213 = V_204 [ V_5 ] . V_213 ;
V_202 . V_214 = 0 ;
V_13 -> V_215 [ V_5 ] = F_70 ( & V_13 -> V_178 ,
& V_202 , NULL ) ;
} else {
V_13 -> V_215 [ V_5 ] = F_71 ( & V_13 -> V_178 ,
& V_206 ,
V_204 [ V_5 ] . V_125 , V_204 [ V_5 ] . V_208 ,
V_204 [ V_5 ] . V_210 , V_204 [ V_5 ] . V_213 ,
V_204 [ V_5 ] . V_212 ) ;
}
if ( V_13 -> V_178 . error ) {
F_19 ( L_47 , V_5 ) ;
return V_13 -> V_178 . error ;
}
if ( V_204 [ V_5 ] . V_216 && V_13 -> V_215 [ V_5 ] )
V_13 -> V_215 [ V_5 ] -> V_179 |= V_217 ;
}
return 0 ;
}
void F_72 ( struct V_12 * V_13 )
{
int V_5 ;
F_73 ( & V_13 -> V_178 ) ;
for ( V_5 = 0 ; V_5 < V_203 ; V_5 ++ )
V_13 -> V_215 [ V_5 ] = NULL ;
}
void F_74 ( struct V_12 * V_13 )
{
struct V_2 V_3 ;
V_3 . V_9 . V_10 . V_11 = V_218 ;
V_13 -> V_74 = F_1 ( & V_3 , V_49 ) ;
V_3 . V_9 . V_10 . V_11 = V_219 ;
V_13 -> V_83 = F_1 ( & V_3 , V_50 ) ;
F_3 ( 2 , L_48 ,
( unsigned int ) V_13 -> V_74 , ( unsigned int ) V_13 -> V_83 ) ;
}
