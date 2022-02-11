static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 V_7 = {
. V_8 = V_9 ,
} ;
struct V_10 * V_11 ;
unsigned int V_12 = 0 ;
int V_13 , V_14 ;
while ( ! F_4 ( V_5 -> V_15 , V_16 ,
V_17 , NULL , & V_7 ) ) {
V_12 ++ ;
V_7 . V_18 ++ ;
}
if ( ! V_12 )
return - V_19 ;
V_11 = F_5 ( V_12 * sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return - V_21 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_7 . V_18 = V_13 ;
F_4 ( V_5 -> V_15 , V_16 ,
V_17 , NULL , & V_7 ) ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_7 . V_7 == V_23 [ V_14 ] . V_24 )
break;
if ( V_14 == V_22 ) {
F_6 ( V_11 ) ;
return - V_25 ;
}
V_11 [ V_13 ] = V_23 [ V_14 ] ;
}
V_5 -> V_26 = V_11 ;
V_5 -> V_27 = V_12 ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
V_5 -> V_27 = 0 ;
F_6 ( V_5 -> V_26 ) ;
V_5 -> V_26 = NULL ;
}
static int F_8 ( struct V_28 * V_29 ,
const void * V_30 ,
unsigned int * V_31 , unsigned int * V_32 ,
unsigned int V_33 [] , void * V_34 [] )
{
const struct V_35 * V_36 = V_30 ;
struct V_4 * V_5 = F_9 ( V_29 ) ;
if ( V_36 && V_36 -> V_36 . V_37 . V_38 < V_5 -> V_36 . V_38 )
return - V_25 ;
if ( V_29 -> V_39 + * V_31 < 2 )
* V_31 = 2 ;
* V_32 = 1 ;
V_33 [ 0 ] = V_36 ? V_36 -> V_36 . V_37 . V_38 : V_5 -> V_36 . V_38 ;
V_34 [ 0 ] = V_5 -> V_40 ;
return 0 ;
}
static int F_10 ( struct V_41 * V_3 )
{
struct V_2 * V_42 = F_11 ( V_3 ) ;
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
unsigned long V_43 = V_5 -> V_36 . V_38 ;
if ( F_12 ( V_3 , 0 ) < V_43 ) {
F_13 ( & V_5 -> V_44 , L_1 ,
F_12 ( V_3 , 0 ) , V_43 ) ;
return - V_25 ;
}
F_14 ( V_3 , 0 , V_43 ) ;
V_42 -> V_45 = V_5 -> V_36 . V_45 ;
return 0 ;
}
static void F_15 ( struct V_41 * V_3 )
{
struct V_2 * V_42 = F_11 ( V_3 ) ;
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
struct V_1 * V_46 = F_1 ( V_42 ) ;
unsigned long V_47 ;
F_16 ( & V_5 -> V_48 , V_47 ) ;
F_17 ( & V_46 -> V_49 , & V_5 -> V_50 ) ;
F_18 ( & V_5 -> V_48 , V_47 ) ;
}
static void F_19 ( struct V_41 * V_3 )
{
struct V_2 * V_42 = F_11 ( V_3 ) ;
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
struct V_1 * V_46 = F_1 ( V_42 ) ;
unsigned long V_47 ;
F_16 ( & V_5 -> V_48 , V_47 ) ;
F_20 ( & V_46 -> V_49 ) ;
F_18 ( & V_5 -> V_48 , V_47 ) ;
}
static int F_21 ( struct V_28 * V_29 , unsigned int V_51 )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
struct V_52 * V_53 = V_5 -> V_53 ;
struct V_1 * V_46 , * V_54 ;
struct V_55 V_56 ;
T_1 V_57 ;
int V_58 ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_60 , 1 ) ;
if ( V_58 && ( V_58 != - V_61 ) ) {
F_13 ( & V_5 -> V_44 , L_2 ) ;
goto V_62;
}
V_56 . V_63 = V_5 -> V_36 . V_63 ;
V_56 . V_64 = V_5 -> V_36 . V_64 ;
V_56 . V_65 = V_5 -> V_65 ;
V_56 . V_66 = V_5 -> V_66 ;
V_56 . V_67 = V_5 -> V_68 -> V_67 ;
V_56 . V_69 = V_5 -> V_68 -> V_69 ;
if ( V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] . V_72
& V_73 ) {
struct V_74 * V_75 = & V_5 -> V_76 . V_75 ;
V_56 . V_77 = V_75 -> V_78 + V_75 -> V_79 ;
V_56 . V_80 = V_75 -> V_81 + V_75 -> V_82 ;
V_56 . line = F_22 ( V_75 ) ;
V_56 . V_83 = F_23 ( V_75 ) ;
} else if ( V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] . V_72
& V_84 ) {
V_56 . V_77 = 0 ;
V_56 . V_80 = 0 ;
if ( V_5 -> V_85 & V_86 ) {
V_56 . line = 858 ;
V_56 . V_83 = 525 ;
} else {
V_56 . line = 864 ;
V_56 . V_83 = 625 ;
}
} else {
V_56 . V_77 = 0 ;
V_56 . V_80 = 0 ;
V_56 . line = V_56 . V_63 + V_5 -> V_68 -> V_87 ;
V_56 . V_83 = V_56 . V_64 ;
}
V_58 = V_53 -> V_88 -> V_89 ( V_53 , & V_56 ) ;
if ( V_58 < 0 ) {
F_13 ( & V_5 -> V_44 ,
L_3 ) ;
goto V_62;
}
V_58 = V_53 -> V_88 -> V_90 ( V_53 , V_91 ) ;
if ( V_58 < 0 ) {
F_13 ( & V_5 -> V_44 ,
L_4 ) ;
goto V_62;
}
V_5 -> V_92 = 0 ;
F_24 ( & V_5 -> V_93 ) ;
V_5 -> V_94 = false ;
V_5 -> V_95 = F_25 ( V_5 -> V_50 . V_96 ,
struct V_1 , V_49 ) ;
F_20 ( & V_5 -> V_95 -> V_49 ) ;
V_57 = F_26 ( & V_5 -> V_95 -> V_3 . V_97 ,
0 ) ;
V_53 -> V_88 -> V_98 ( V_53 , ( unsigned long ) V_57 ) ;
V_53 -> V_88 -> V_99 ( V_53 ) ;
return 0 ;
V_62:
F_27 (buf, tmp, &bcap_dev->dma_queue, list) {
F_28 ( & V_46 -> V_49 ) ;
F_29 ( & V_46 -> V_3 . V_97 , V_100 ) ;
}
return V_58 ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
struct V_52 * V_53 = V_5 -> V_53 ;
int V_58 ;
V_5 -> V_94 = true ;
F_31 ( & V_5 -> V_93 ) ;
V_53 -> V_88 -> V_94 ( V_53 ) ;
V_53 -> V_88 -> V_101 ( V_53 ) ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_60 , 0 ) ;
if ( V_58 && ( V_58 != - V_61 ) )
F_13 ( & V_5 -> V_44 ,
L_5 ) ;
if ( V_5 -> V_95 )
F_29 ( & V_5 -> V_95 -> V_3 . V_97 ,
V_102 ) ;
while ( ! F_32 ( & V_5 -> V_50 ) ) {
V_5 -> V_95 = F_25 ( V_5 -> V_50 . V_96 ,
struct V_1 , V_49 ) ;
F_20 ( & V_5 -> V_95 -> V_49 ) ;
F_29 ( & V_5 -> V_95 -> V_3 . V_97 ,
V_102 ) ;
}
}
static T_2 V_91 ( int V_103 , void * V_104 )
{
struct V_52 * V_53 = V_104 ;
struct V_4 * V_5 = V_53 -> V_105 ;
struct V_2 * V_42 = & V_5 -> V_95 -> V_3 ;
struct V_41 * V_3 = & V_42 -> V_97 ;
T_1 V_57 ;
F_33 ( & V_5 -> V_48 ) ;
if ( ! F_32 ( & V_5 -> V_50 ) ) {
F_34 ( & V_42 -> V_106 ) ;
if ( V_53 -> V_62 ) {
F_29 ( V_3 , V_102 ) ;
V_53 -> V_62 = false ;
} else {
V_42 -> V_92 = V_5 -> V_92 ++ ;
F_29 ( V_3 , V_107 ) ;
}
V_5 -> V_95 = F_25 ( V_5 -> V_50 . V_96 ,
struct V_1 , V_49 ) ;
F_20 ( & V_5 -> V_95 -> V_49 ) ;
} else {
if ( V_53 -> V_62 )
V_53 -> V_62 = false ;
}
V_53 -> V_88 -> V_94 ( V_53 ) ;
if ( V_5 -> V_94 ) {
F_35 ( & V_5 -> V_93 ) ;
} else {
V_57 = F_26 (
& V_5 -> V_95 -> V_3 . V_97 , 0 ) ;
V_53 -> V_88 -> V_98 ( V_53 , ( unsigned long ) V_57 ) ;
V_53 -> V_88 -> V_99 ( V_53 ) ;
}
F_36 ( & V_5 -> V_48 ) ;
return V_108 ;
}
static int F_37 ( struct V_109 * V_109 , void * V_105 , T_3 * V_85 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_84 ) )
return - V_112 ;
return F_4 ( V_5 -> V_15 , V_59 , V_113 , V_85 ) ;
}
static int F_39 ( struct V_109 * V_109 , void * V_105 , T_3 * V_85 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_84 ) )
return - V_112 ;
* V_85 = V_5 -> V_85 ;
return 0 ;
}
static int F_40 ( struct V_109 * V_109 , void * V_105 , T_3 V_85 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
int V_58 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_84 ) )
return - V_112 ;
if ( F_41 ( & V_5 -> V_114 ) )
return - V_115 ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_116 , V_85 ) ;
if ( V_58 < 0 )
return V_58 ;
V_5 -> V_85 = V_85 ;
return 0 ;
}
static int F_42 ( struct V_109 * V_109 , void * V_105 ,
struct V_117 * V_118 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_73 ) )
return - V_112 ;
V_118 -> V_16 = 0 ;
return F_4 ( V_5 -> V_15 , V_16 ,
V_119 , V_118 ) ;
}
static int F_43 ( struct V_109 * V_109 , void * V_105 ,
struct V_120 * V_118 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_73 ) )
return - V_112 ;
return F_4 ( V_5 -> V_15 , V_59 ,
V_121 , V_118 ) ;
}
static int F_44 ( struct V_109 * V_109 , void * V_105 ,
struct V_120 * V_118 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_73 ) )
return - V_112 ;
* V_118 = V_5 -> V_76 ;
return 0 ;
}
static int F_45 ( struct V_109 * V_109 , void * V_105 ,
struct V_120 * V_118 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_110 V_111 ;
int V_58 ;
V_111 = V_5 -> V_68 -> V_70 [ V_5 -> V_71 ] ;
if ( ! ( V_111 . V_72 & V_73 ) )
return - V_112 ;
if ( F_41 ( & V_5 -> V_114 ) )
return - V_115 ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_122 , V_118 ) ;
if ( V_58 < 0 )
return V_58 ;
V_5 -> V_76 = * V_118 ;
return 0 ;
}
static int F_46 ( struct V_109 * V_109 , void * V_105 ,
struct V_110 * V_111 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_123 * V_124 = V_5 -> V_68 ;
int V_58 ;
T_4 V_125 ;
if ( V_111 -> V_18 >= V_124 -> V_126 )
return - V_25 ;
* V_111 = V_124 -> V_70 [ V_111 -> V_18 ] ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_127 , & V_125 ) ;
if ( ! V_58 )
V_111 -> V_125 = V_125 ;
return 0 ;
}
static int F_47 ( struct V_109 * V_109 , void * V_105 , unsigned int * V_18 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
* V_18 = V_5 -> V_71 ;
return 0 ;
}
static int F_48 ( struct V_109 * V_109 , void * V_105 , unsigned int V_18 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_123 * V_124 = V_5 -> V_68 ;
struct V_128 * V_129 ;
int V_58 ;
if ( F_41 ( & V_5 -> V_114 ) )
return - V_115 ;
if ( V_18 >= V_124 -> V_126 )
return - V_25 ;
V_129 = & V_124 -> V_130 [ V_18 ] ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_131 ,
V_129 -> V_111 , V_129 -> V_132 , 0 ) ;
if ( ( V_58 < 0 ) && ( V_58 != - V_61 ) ) {
F_13 ( & V_5 -> V_44 , L_6 ) ;
return V_58 ;
}
V_5 -> V_71 = V_18 ;
if ( V_129 -> V_67 )
V_124 -> V_67 = V_129 -> V_67 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_133 ,
struct V_134 * V_135 ,
struct V_10 * V_136 )
{
struct V_10 * V_11 = V_133 -> V_26 ;
struct V_10 * V_36 = NULL ;
struct V_137 V_138 ;
struct V_139 V_140 = {
. V_8 = V_141 ,
} ;
int V_58 , V_13 ;
for ( V_13 = 0 ; V_13 < V_133 -> V_27 ; V_13 ++ ) {
V_36 = & V_11 [ V_13 ] ;
if ( V_135 -> V_142 == V_36 -> V_142 )
break;
}
if ( V_13 == V_133 -> V_27 )
V_36 = & V_11 [ 0 ] ;
F_50 ( & V_140 . V_140 , V_135 , V_36 -> V_24 ) ;
V_58 = F_4 ( V_133 -> V_15 , V_16 , V_143 , & V_138 ,
& V_140 ) ;
if ( V_58 < 0 )
return V_58 ;
F_51 ( V_135 , & V_140 . V_140 ) ;
if ( V_136 ) {
for ( V_13 = 0 ; V_13 < V_133 -> V_27 ; V_13 ++ ) {
V_36 = & V_11 [ V_13 ] ;
if ( V_140 . V_140 . V_7 == V_36 -> V_24 )
break;
}
* V_136 = * V_36 ;
}
V_135 -> V_144 = V_135 -> V_63 * V_36 -> V_65 / 8 ;
V_135 -> V_38 = V_135 -> V_144 * V_135 -> V_64 ;
return 0 ;
}
static int F_52 ( struct V_109 * V_109 , void * V_105 ,
struct V_145 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_10 * V_11 = V_5 -> V_26 ;
if ( V_36 -> V_18 >= V_5 -> V_27 )
return - V_25 ;
V_36 -> type = V_146 ;
F_53 ( V_36 -> V_147 ,
V_11 [ V_36 -> V_18 ] . V_148 ,
sizeof( V_36 -> V_147 ) ) ;
V_36 -> V_142 = V_11 [ V_36 -> V_18 ] . V_142 ;
return 0 ;
}
static int F_54 ( struct V_109 * V_109 , void * V_105 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_134 * V_135 = & V_36 -> V_36 . V_37 ;
return F_49 ( V_5 , V_135 , NULL ) ;
}
static int F_55 ( struct V_109 * V_109 , void * V_105 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
V_36 -> V_36 . V_37 = V_5 -> V_36 ;
return 0 ;
}
static int F_56 ( struct V_109 * V_109 , void * V_105 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
struct V_139 V_140 = {
. V_8 = V_9 ,
} ;
struct V_10 V_136 ;
struct V_134 * V_135 = & V_36 -> V_36 . V_37 ;
int V_58 ;
if ( F_41 ( & V_5 -> V_114 ) )
return - V_115 ;
V_58 = F_49 ( V_5 , V_135 , & V_136 ) ;
if ( V_58 < 0 )
return V_58 ;
F_50 ( & V_140 . V_140 , V_135 , V_136 . V_24 ) ;
V_58 = F_4 ( V_5 -> V_15 , V_16 , V_143 , NULL , & V_140 ) ;
if ( V_58 < 0 )
return V_58 ;
V_5 -> V_36 = * V_135 ;
V_5 -> V_65 = V_136 . V_65 ;
V_5 -> V_66 = V_136 . V_66 ;
return 0 ;
}
static int F_57 ( struct V_109 * V_109 , void * V_105 ,
struct V_149 * V_150 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
V_150 -> V_151 = V_152 | V_153 ;
V_150 -> V_72 = V_150 -> V_151 | V_154 ;
F_53 ( V_150 -> V_155 , V_156 , sizeof( V_150 -> V_155 ) ) ;
F_53 ( V_150 -> V_157 , L_7 , sizeof( V_150 -> V_157 ) ) ;
F_53 ( V_150 -> V_158 , V_5 -> V_68 -> V_159 , sizeof( V_150 -> V_158 ) ) ;
return 0 ;
}
static int F_58 ( struct V_109 * V_109 , void * V_160 ,
struct V_161 * V_162 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
if ( V_162 -> type != V_146 )
return - V_25 ;
return F_4 ( V_5 -> V_15 , V_59 , V_163 , V_162 ) ;
}
static int F_59 ( struct V_109 * V_109 , void * V_160 ,
struct V_161 * V_162 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
if ( V_162 -> type != V_146 )
return - V_25 ;
return F_4 ( V_5 -> V_15 , V_59 , V_164 , V_162 ) ;
}
static int F_60 ( struct V_109 * V_109 , void * V_105 )
{
struct V_4 * V_5 = F_38 ( V_109 ) ;
F_61 ( & V_5 -> V_44 , 0 , V_165 , V_166 ) ;
return 0 ;
}
static int F_62 ( struct V_167 * V_168 )
{
struct V_4 * V_5 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
struct V_123 * V_124 ;
struct V_28 * V_173 ;
struct V_128 * V_129 ;
int V_58 ;
V_124 = V_168 -> V_174 . V_175 ;
if ( ! V_124 || ! V_124 -> V_126 ) {
F_13 ( V_168 -> V_174 . V_155 , L_8 ) ;
return - V_176 ;
}
V_5 = F_5 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 ) {
F_13 ( V_168 -> V_174 . V_155 , L_9 ) ;
return - V_21 ;
}
V_5 -> V_68 = V_124 ;
V_5 -> V_53 = F_63 ( V_168 , V_124 -> V_177 ) ;
if ( ! V_5 -> V_53 ) {
F_13 ( V_168 -> V_174 . V_155 , L_10 ) ;
V_58 = - V_176 ;
goto V_178;
}
V_5 -> V_53 -> V_105 = V_5 ;
V_5 -> V_40 = F_64 ( & V_168 -> V_174 ) ;
if ( F_65 ( V_5 -> V_40 ) ) {
V_58 = F_66 ( V_5 -> V_40 ) ;
goto V_179;
}
V_170 = & V_5 -> V_180 ;
V_170 -> V_181 = V_182 ;
V_170 -> V_183 = & V_184 ;
V_170 -> V_185 = & V_186 ;
V_170 -> V_187 = 0 ;
V_170 -> V_44 = & V_5 -> V_44 ;
strncpy ( V_170 -> V_188 , V_156 , sizeof( V_170 -> V_188 ) ) ;
V_58 = F_67 ( & V_168 -> V_174 , & V_5 -> V_44 ) ;
if ( V_58 ) {
F_13 ( V_168 -> V_174 . V_155 ,
L_11 ) ;
goto V_189;
}
F_68 ( & V_5 -> V_44 , L_12 ) ;
V_5 -> V_44 . V_190 = & V_5 -> V_190 ;
V_58 = F_69 ( & V_5 -> V_190 , 0 ) ;
if ( V_58 ) {
F_13 ( & V_5 -> V_44 ,
L_13 ) ;
goto V_191;
}
F_70 ( & V_5 -> V_48 ) ;
V_173 = & V_5 -> V_114 ;
V_173 -> type = V_146 ;
V_173 -> V_192 = V_193 | V_194 ;
V_173 -> V_195 = V_5 ;
V_173 -> V_196 = sizeof( struct V_1 ) ;
V_173 -> V_88 = & V_197 ;
V_173 -> V_198 = & V_199 ;
V_173 -> V_200 = V_201 ;
V_173 -> V_48 = & V_5 -> V_202 ;
V_173 -> V_203 = 1 ;
V_58 = F_71 ( V_173 ) ;
if ( V_58 )
goto V_204;
F_72 ( & V_5 -> V_202 ) ;
F_73 ( & V_5 -> V_93 ) ;
F_74 ( & V_5 -> V_50 ) ;
V_170 -> V_48 = & V_5 -> V_202 ;
V_170 -> V_205 = V_173 ;
V_58 = F_75 ( & V_5 -> V_180 , V_206 , - 1 ) ;
if ( V_58 ) {
F_13 ( & V_5 -> V_44 ,
L_14 ) ;
goto V_204;
}
F_76 ( & V_5 -> V_180 , V_5 ) ;
F_68 ( & V_5 -> V_44 , L_15 ,
F_77 ( V_170 ) ) ;
V_172 = F_78 ( V_124 -> V_207 ) ;
if ( ! V_172 ) {
F_13 ( & V_5 -> V_44 ,
L_16 ) ;
V_58 = - V_176 ;
goto V_208;
}
V_5 -> V_15 = F_79 ( & V_5 -> V_44 ,
V_172 ,
& V_124 -> V_209 ,
NULL ) ;
if ( V_5 -> V_15 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_124 -> V_126 ; V_13 ++ )
V_170 -> V_187 |= V_124 -> V_70 [ V_13 ] . V_85 ;
} else {
F_13 ( & V_5 -> V_44 ,
L_17 ) ;
V_58 = - V_176 ;
goto V_208;
}
F_68 ( & V_5 -> V_44 , L_18 ) ;
V_129 = & V_124 -> V_130 [ 0 ] ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_131 ,
V_129 -> V_111 , V_129 -> V_132 , 0 ) ;
if ( ( V_58 < 0 ) && ( V_58 != - V_61 ) ) {
F_13 ( & V_5 -> V_44 , L_6 ) ;
goto V_208;
}
V_5 -> V_71 = 0 ;
if ( V_129 -> V_67 )
V_124 -> V_67 = V_129 -> V_67 ;
if ( V_124 -> V_70 [ 0 ] . V_72 & V_84 ) {
T_3 V_85 ;
V_58 = F_4 ( V_5 -> V_15 , V_59 , V_210 , & V_85 ) ;
if ( V_58 ) {
F_13 ( & V_5 -> V_44 ,
L_19 ) ;
goto V_208;
}
V_5 -> V_85 = V_85 ;
}
if ( V_124 -> V_70 [ 0 ] . V_72 & V_73 ) {
struct V_120 V_76 ;
V_58 = F_4 ( V_5 -> V_15 , V_59 ,
V_211 , & V_76 ) ;
if ( V_58 ) {
F_13 ( & V_5 -> V_44 ,
L_20 ) ;
goto V_208;
}
V_5 -> V_76 = V_76 ;
}
V_58 = F_3 ( V_5 ) ;
if ( V_58 ) {
F_13 ( & V_5 -> V_44 ,
L_21 ) ;
goto V_208;
}
return 0 ;
V_208:
F_80 ( & V_5 -> V_180 ) ;
V_204:
F_81 ( & V_5 -> V_190 ) ;
V_191:
F_82 ( & V_5 -> V_44 ) ;
V_189:
F_83 ( V_5 -> V_40 ) ;
V_179:
F_84 ( V_5 -> V_53 ) ;
V_178:
F_6 ( V_5 ) ;
return V_58 ;
}
static int F_85 ( struct V_167 * V_168 )
{
struct V_212 * V_44 = F_86 ( V_168 ) ;
struct V_4 * V_5 = F_2 ( V_44 ,
struct V_4 , V_44 ) ;
F_7 ( V_5 ) ;
F_80 ( & V_5 -> V_180 ) ;
F_81 ( & V_5 -> V_190 ) ;
F_82 ( V_44 ) ;
F_83 ( V_5 -> V_40 ) ;
F_84 ( V_5 -> V_53 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
