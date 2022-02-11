static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
T_1 V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 ;
int V_10 , V_11 ;
while ( ! F_4 ( V_5 -> V_12 , V_13 ,
V_14 , V_9 , & V_6 ) )
V_9 ++ ;
if ( ! V_9 )
return - V_15 ;
V_8 = F_5 ( V_9 * sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
F_4 ( V_5 -> V_12 , V_13 ,
V_14 , V_10 , & V_6 ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ )
if ( V_6 == V_19 [ V_11 ] . V_20 )
break;
if ( V_11 == V_18 ) {
F_6 ( V_8 ) ;
return - V_21 ;
}
V_8 [ V_10 ] = V_19 [ V_11 ] ;
}
V_5 -> V_22 = V_8 ;
V_5 -> V_23 = V_9 ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
V_5 -> V_23 = 0 ;
F_6 ( V_5 -> V_22 ) ;
V_5 -> V_22 = NULL ;
}
static int F_8 ( struct V_24 * V_25 ,
const struct V_26 * V_27 ,
unsigned int * V_28 , unsigned int * V_29 ,
unsigned int V_30 [] , void * V_31 [] )
{
struct V_4 * V_5 = F_9 ( V_25 ) ;
if ( V_27 && V_27 -> V_27 . V_32 . V_33 < V_5 -> V_27 . V_33 )
return - V_21 ;
if ( V_25 -> V_34 + * V_28 < 2 )
* V_28 = 2 ;
* V_29 = 1 ;
V_30 [ 0 ] = V_27 ? V_27 -> V_27 . V_32 . V_33 : V_5 -> V_27 . V_33 ;
V_31 [ 0 ] = V_5 -> V_35 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 -> V_24 ) ;
unsigned long V_36 = V_5 -> V_27 . V_33 ;
if ( F_11 ( V_3 , 0 ) < V_36 ) {
F_12 ( & V_5 -> V_37 , L_1 ,
F_11 ( V_3 , 0 ) , V_36 ) ;
return - V_21 ;
}
F_13 ( V_3 , 0 , V_36 ) ;
V_3 -> V_38 . V_39 = V_5 -> V_27 . V_39 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 -> V_24 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
unsigned long V_41 ;
F_15 ( & V_5 -> V_42 , V_41 ) ;
F_16 ( & V_40 -> V_43 , & V_5 -> V_44 ) ;
F_17 ( & V_5 -> V_42 , V_41 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 -> V_24 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
unsigned long V_41 ;
F_15 ( & V_5 -> V_42 , V_41 ) ;
F_19 ( & V_40 -> V_43 ) ;
F_17 ( & V_5 -> V_42 , V_41 ) ;
}
static int F_20 ( struct V_24 * V_25 , unsigned int V_45 )
{
struct V_4 * V_5 = F_9 ( V_25 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_1 * V_40 , * V_48 ;
struct V_49 V_50 ;
T_2 V_51 ;
int V_52 ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_53 , 1 ) ;
if ( V_52 && ( V_52 != - V_54 ) ) {
F_12 ( & V_5 -> V_37 , L_2 ) ;
goto V_55;
}
V_50 . V_56 = V_5 -> V_27 . V_56 ;
V_50 . V_57 = V_5 -> V_27 . V_57 ;
V_50 . V_58 = V_5 -> V_58 ;
V_50 . V_59 = V_5 -> V_59 ;
V_50 . V_60 = V_5 -> V_61 -> V_60 ;
V_50 . V_62 = V_5 -> V_61 -> V_62 ;
if ( V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] . V_65
& V_66 ) {
struct V_67 * V_68 = & V_5 -> V_69 . V_68 ;
V_50 . V_70 = V_68 -> V_71 + V_68 -> V_72 ;
V_50 . V_73 = V_68 -> V_74 + V_68 -> V_75 ;
V_50 . line = F_21 ( V_68 ) ;
V_50 . V_76 = F_22 ( V_68 ) ;
} else if ( V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] . V_65
& V_77 ) {
V_50 . V_70 = 0 ;
V_50 . V_73 = 0 ;
if ( V_5 -> V_78 & V_79 ) {
V_50 . line = 858 ;
V_50 . V_76 = 525 ;
} else {
V_50 . line = 864 ;
V_50 . V_76 = 625 ;
}
} else {
V_50 . V_70 = 0 ;
V_50 . V_73 = 0 ;
V_50 . line = V_50 . V_56 + V_5 -> V_61 -> V_80 ;
V_50 . V_76 = V_50 . V_57 ;
}
V_52 = V_47 -> V_81 -> V_82 ( V_47 , & V_50 ) ;
if ( V_52 < 0 ) {
F_12 ( & V_5 -> V_37 ,
L_3 ) ;
goto V_55;
}
V_52 = V_47 -> V_81 -> V_83 ( V_47 , V_84 ) ;
if ( V_52 < 0 ) {
F_12 ( & V_5 -> V_37 ,
L_4 ) ;
goto V_55;
}
V_5 -> V_85 = 0 ;
F_23 ( & V_5 -> V_86 ) ;
V_5 -> V_87 = false ;
V_5 -> V_88 = F_24 ( V_5 -> V_44 . V_89 ,
struct V_1 , V_43 ) ;
F_19 ( & V_5 -> V_88 -> V_43 ) ;
V_51 = F_25 ( & V_5 -> V_88 -> V_3 , 0 ) ;
V_47 -> V_81 -> V_90 ( V_47 , ( unsigned long ) V_51 ) ;
V_47 -> V_81 -> V_91 ( V_47 ) ;
return 0 ;
V_55:
F_26 (buf, tmp, &bcap_dev->dma_queue, list) {
F_27 ( & V_40 -> V_43 ) ;
F_28 ( & V_40 -> V_3 , V_92 ) ;
}
return V_52 ;
}
static void F_29 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_9 ( V_25 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
int V_52 ;
V_5 -> V_87 = true ;
F_30 ( & V_5 -> V_86 ) ;
V_47 -> V_81 -> V_87 ( V_47 ) ;
V_47 -> V_81 -> V_93 ( V_47 ) ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_53 , 0 ) ;
if ( V_52 && ( V_52 != - V_54 ) )
F_12 ( & V_5 -> V_37 ,
L_5 ) ;
if ( V_5 -> V_88 )
F_28 ( & V_5 -> V_88 -> V_3 , V_94 ) ;
while ( ! F_31 ( & V_5 -> V_44 ) ) {
V_5 -> V_88 = F_24 ( V_5 -> V_44 . V_89 ,
struct V_1 , V_43 ) ;
F_19 ( & V_5 -> V_88 -> V_43 ) ;
F_28 ( & V_5 -> V_88 -> V_3 , V_94 ) ;
}
}
static T_3 V_84 ( int V_95 , void * V_96 )
{
struct V_46 * V_47 = V_96 ;
struct V_4 * V_5 = V_47 -> V_97 ;
struct V_2 * V_3 = & V_5 -> V_88 -> V_3 ;
T_2 V_51 ;
F_32 ( & V_5 -> V_42 ) ;
if ( ! F_31 ( & V_5 -> V_44 ) ) {
F_33 ( & V_3 -> V_38 . V_98 ) ;
if ( V_47 -> V_55 ) {
F_28 ( V_3 , V_94 ) ;
V_47 -> V_55 = false ;
} else {
V_3 -> V_38 . V_85 = V_5 -> V_85 ++ ;
F_28 ( V_3 , V_99 ) ;
}
V_5 -> V_88 = F_24 ( V_5 -> V_44 . V_89 ,
struct V_1 , V_43 ) ;
F_19 ( & V_5 -> V_88 -> V_43 ) ;
} else {
if ( V_47 -> V_55 )
V_47 -> V_55 = false ;
}
V_47 -> V_81 -> V_87 ( V_47 ) ;
if ( V_5 -> V_87 ) {
F_34 ( & V_5 -> V_86 ) ;
} else {
V_51 = F_25 ( & V_5 -> V_88 -> V_3 , 0 ) ;
V_47 -> V_81 -> V_90 ( V_47 , ( unsigned long ) V_51 ) ;
V_47 -> V_81 -> V_91 ( V_47 ) ;
}
F_35 ( & V_5 -> V_42 ) ;
return V_100 ;
}
static int F_36 ( struct V_101 * V_101 , void * V_97 , T_4 * V_78 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_77 ) )
return - V_104 ;
return F_4 ( V_5 -> V_12 , V_13 , V_105 , V_78 ) ;
}
static int F_38 ( struct V_101 * V_101 , void * V_97 , T_4 * V_78 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_77 ) )
return - V_104 ;
* V_78 = V_5 -> V_78 ;
return 0 ;
}
static int F_39 ( struct V_101 * V_101 , void * V_97 , T_4 V_78 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
int V_52 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_77 ) )
return - V_104 ;
if ( F_40 ( & V_5 -> V_106 ) )
return - V_107 ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_108 , V_78 ) ;
if ( V_52 < 0 )
return V_52 ;
V_5 -> V_78 = V_78 ;
return 0 ;
}
static int F_41 ( struct V_101 * V_101 , void * V_97 ,
struct V_109 * V_110 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_66 ) )
return - V_104 ;
V_110 -> V_111 = 0 ;
return F_4 ( V_5 -> V_12 , V_111 ,
V_112 , V_110 ) ;
}
static int F_42 ( struct V_101 * V_101 , void * V_97 ,
struct V_113 * V_110 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_66 ) )
return - V_104 ;
return F_4 ( V_5 -> V_12 , V_13 ,
V_114 , V_110 ) ;
}
static int F_43 ( struct V_101 * V_101 , void * V_97 ,
struct V_113 * V_110 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_66 ) )
return - V_104 ;
* V_110 = V_5 -> V_69 ;
return 0 ;
}
static int F_44 ( struct V_101 * V_101 , void * V_97 ,
struct V_113 * V_110 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_102 V_103 ;
int V_52 ;
V_103 = V_5 -> V_61 -> V_63 [ V_5 -> V_64 ] ;
if ( ! ( V_103 . V_65 & V_66 ) )
return - V_104 ;
if ( F_40 ( & V_5 -> V_106 ) )
return - V_107 ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_115 , V_110 ) ;
if ( V_52 < 0 )
return V_52 ;
V_5 -> V_69 = * V_110 ;
return 0 ;
}
static int F_45 ( struct V_101 * V_101 , void * V_97 ,
struct V_102 * V_103 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_116 * V_117 = V_5 -> V_61 ;
int V_52 ;
T_1 V_118 ;
if ( V_103 -> V_119 >= V_117 -> V_120 )
return - V_21 ;
* V_103 = V_117 -> V_63 [ V_103 -> V_119 ] ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_121 , & V_118 ) ;
if ( ! V_52 )
V_103 -> V_118 = V_118 ;
return 0 ;
}
static int F_46 ( struct V_101 * V_101 , void * V_97 , unsigned int * V_119 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
* V_119 = V_5 -> V_64 ;
return 0 ;
}
static int F_47 ( struct V_101 * V_101 , void * V_97 , unsigned int V_119 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_116 * V_117 = V_5 -> V_61 ;
struct V_122 * V_123 ;
int V_52 ;
if ( F_40 ( & V_5 -> V_106 ) )
return - V_107 ;
if ( V_119 >= V_117 -> V_120 )
return - V_21 ;
V_123 = & V_117 -> V_124 [ V_119 ] ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_125 ,
V_123 -> V_103 , V_123 -> V_126 , 0 ) ;
if ( ( V_52 < 0 ) && ( V_52 != - V_54 ) ) {
F_12 ( & V_5 -> V_37 , L_6 ) ;
return V_52 ;
}
V_5 -> V_64 = V_119 ;
if ( V_123 -> V_60 )
V_117 -> V_60 = V_123 -> V_60 ;
return 0 ;
}
static int F_48 ( struct V_4 * V_127 ,
struct V_128 * V_129 ,
struct V_7 * V_130 )
{
struct V_7 * V_8 = V_127 -> V_22 ;
struct V_7 * V_27 = NULL ;
struct V_131 V_132 ;
int V_52 , V_10 ;
for ( V_10 = 0 ; V_10 < V_127 -> V_23 ; V_10 ++ ) {
V_27 = & V_8 [ V_10 ] ;
if ( V_129 -> V_133 == V_27 -> V_133 )
break;
}
if ( V_10 == V_127 -> V_23 )
V_27 = & V_8 [ 0 ] ;
F_49 ( & V_132 , V_129 , V_27 -> V_20 ) ;
V_52 = F_4 ( V_127 -> V_12 , V_13 ,
V_134 , & V_132 ) ;
if ( V_52 < 0 )
return V_52 ;
F_50 ( V_129 , & V_132 ) ;
if ( V_130 ) {
for ( V_10 = 0 ; V_10 < V_127 -> V_23 ; V_10 ++ ) {
V_27 = & V_8 [ V_10 ] ;
if ( V_132 . V_6 == V_27 -> V_20 )
break;
}
* V_130 = * V_27 ;
}
V_129 -> V_135 = V_129 -> V_56 * V_27 -> V_58 / 8 ;
V_129 -> V_33 = V_129 -> V_135 * V_129 -> V_57 ;
return 0 ;
}
static int F_51 ( struct V_101 * V_101 , void * V_97 ,
struct V_136 * V_27 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_7 * V_8 = V_5 -> V_22 ;
if ( V_27 -> V_119 >= V_5 -> V_23 )
return - V_21 ;
V_27 -> type = V_137 ;
F_52 ( V_27 -> V_138 ,
V_8 [ V_27 -> V_119 ] . V_139 ,
sizeof( V_27 -> V_138 ) ) ;
V_27 -> V_133 = V_8 [ V_27 -> V_119 ] . V_133 ;
return 0 ;
}
static int F_53 ( struct V_101 * V_101 , void * V_97 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_128 * V_129 = & V_27 -> V_27 . V_32 ;
return F_48 ( V_5 , V_129 , NULL ) ;
}
static int F_54 ( struct V_101 * V_101 , void * V_97 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
V_27 -> V_27 . V_32 = V_5 -> V_27 ;
return 0 ;
}
static int F_55 ( struct V_101 * V_101 , void * V_97 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
struct V_131 V_132 ;
struct V_7 V_130 ;
struct V_128 * V_129 = & V_27 -> V_27 . V_32 ;
int V_52 ;
if ( F_40 ( & V_5 -> V_106 ) )
return - V_107 ;
V_52 = F_48 ( V_5 , V_129 , & V_130 ) ;
if ( V_52 < 0 )
return V_52 ;
F_49 ( & V_132 , V_129 , V_130 . V_20 ) ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_140 , & V_132 ) ;
if ( V_52 < 0 )
return V_52 ;
V_5 -> V_27 = * V_129 ;
V_5 -> V_58 = V_130 . V_58 ;
V_5 -> V_59 = V_130 . V_59 ;
return 0 ;
}
static int F_56 ( struct V_101 * V_101 , void * V_97 ,
struct V_141 * V_142 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
V_142 -> V_143 = V_144 | V_145 ;
V_142 -> V_65 = V_142 -> V_143 | V_146 ;
F_52 ( V_142 -> V_147 , V_148 , sizeof( V_142 -> V_147 ) ) ;
F_52 ( V_142 -> V_149 , L_7 , sizeof( V_142 -> V_149 ) ) ;
F_52 ( V_142 -> V_150 , V_5 -> V_61 -> V_151 , sizeof( V_142 -> V_150 ) ) ;
return 0 ;
}
static int F_57 ( struct V_101 * V_101 , void * V_152 ,
struct V_153 * V_154 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
if ( V_154 -> type != V_137 )
return - V_21 ;
return F_4 ( V_5 -> V_12 , V_13 , V_155 , V_154 ) ;
}
static int F_58 ( struct V_101 * V_101 , void * V_152 ,
struct V_153 * V_154 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
if ( V_154 -> type != V_137 )
return - V_21 ;
return F_4 ( V_5 -> V_12 , V_13 , V_156 , V_154 ) ;
}
static int F_59 ( struct V_101 * V_101 , void * V_97 )
{
struct V_4 * V_5 = F_37 ( V_101 ) ;
F_60 ( & V_5 -> V_37 , 0 , V_157 , V_158 ) ;
return 0 ;
}
static int F_61 ( struct V_159 * V_160 )
{
struct V_4 * V_5 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_116 * V_117 ;
struct V_24 * V_165 ;
struct V_122 * V_123 ;
int V_52 ;
V_117 = V_160 -> V_166 . V_167 ;
if ( ! V_117 || ! V_117 -> V_120 ) {
F_12 ( V_160 -> V_166 . V_147 , L_8 ) ;
return - V_168 ;
}
V_5 = F_5 ( sizeof( * V_5 ) , V_16 ) ;
if ( ! V_5 ) {
F_12 ( V_160 -> V_166 . V_147 , L_9 ) ;
return - V_17 ;
}
V_5 -> V_61 = V_117 ;
V_5 -> V_47 = F_62 ( V_160 , V_117 -> V_169 ) ;
if ( ! V_5 -> V_47 ) {
F_12 ( V_160 -> V_166 . V_147 , L_10 ) ;
V_52 = - V_168 ;
goto V_170;
}
V_5 -> V_47 -> V_97 = V_5 ;
V_5 -> V_35 = F_63 ( & V_160 -> V_166 ) ;
if ( F_64 ( V_5 -> V_35 ) ) {
V_52 = F_65 ( V_5 -> V_35 ) ;
goto V_171;
}
V_162 = & V_5 -> V_172 ;
V_162 -> V_173 = V_174 ;
V_162 -> V_175 = & V_176 ;
V_162 -> V_177 = & V_178 ;
V_162 -> V_179 = 0 ;
V_162 -> V_37 = & V_5 -> V_37 ;
strncpy ( V_162 -> V_180 , V_148 , sizeof( V_162 -> V_180 ) ) ;
V_52 = F_66 ( & V_160 -> V_166 , & V_5 -> V_37 ) ;
if ( V_52 ) {
F_12 ( V_160 -> V_166 . V_147 ,
L_11 ) ;
goto V_181;
}
F_67 ( & V_5 -> V_37 , L_12 ) ;
V_5 -> V_37 . V_182 = & V_5 -> V_182 ;
V_52 = F_68 ( & V_5 -> V_182 , 0 ) ;
if ( V_52 ) {
F_12 ( & V_5 -> V_37 ,
L_13 ) ;
goto V_183;
}
F_69 ( & V_5 -> V_42 ) ;
V_165 = & V_5 -> V_106 ;
V_165 -> type = V_137 ;
V_165 -> V_184 = V_185 | V_186 ;
V_165 -> V_187 = V_5 ;
V_165 -> V_188 = sizeof( struct V_1 ) ;
V_165 -> V_81 = & V_189 ;
V_165 -> V_190 = & V_191 ;
V_165 -> V_192 = V_193 ;
V_165 -> V_42 = & V_5 -> V_194 ;
V_165 -> V_195 = 1 ;
V_52 = F_70 ( V_165 ) ;
if ( V_52 )
goto V_196;
F_71 ( & V_5 -> V_194 ) ;
F_72 ( & V_5 -> V_86 ) ;
F_73 ( & V_5 -> V_44 ) ;
V_162 -> V_42 = & V_5 -> V_194 ;
V_162 -> V_197 = V_165 ;
V_52 = F_74 ( & V_5 -> V_172 , V_198 , - 1 ) ;
if ( V_52 ) {
F_12 ( & V_5 -> V_37 ,
L_14 ) ;
goto V_196;
}
F_75 ( & V_5 -> V_172 , V_5 ) ;
F_67 ( & V_5 -> V_37 , L_15 ,
F_76 ( V_162 ) ) ;
V_164 = F_77 ( V_117 -> V_199 ) ;
if ( ! V_164 ) {
F_12 ( & V_5 -> V_37 ,
L_16 ) ;
V_52 = - V_168 ;
goto V_200;
}
V_5 -> V_12 = F_78 ( & V_5 -> V_37 ,
V_164 ,
& V_117 -> V_201 ,
NULL ) ;
if ( V_5 -> V_12 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_117 -> V_120 ; V_10 ++ )
V_162 -> V_179 |= V_117 -> V_63 [ V_10 ] . V_78 ;
} else {
F_12 ( & V_5 -> V_37 ,
L_17 ) ;
V_52 = - V_168 ;
goto V_200;
}
F_67 ( & V_5 -> V_37 , L_18 ) ;
V_123 = & V_117 -> V_124 [ 0 ] ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_125 ,
V_123 -> V_103 , V_123 -> V_126 , 0 ) ;
if ( ( V_52 < 0 ) && ( V_52 != - V_54 ) ) {
F_12 ( & V_5 -> V_37 , L_6 ) ;
goto V_200;
}
V_5 -> V_64 = 0 ;
if ( V_123 -> V_60 )
V_117 -> V_60 = V_123 -> V_60 ;
if ( V_117 -> V_63 [ 0 ] . V_65 & V_77 ) {
T_4 V_78 ;
V_52 = F_4 ( V_5 -> V_12 , V_13 , V_202 , & V_78 ) ;
if ( V_52 ) {
F_12 ( & V_5 -> V_37 ,
L_19 ) ;
goto V_200;
}
V_5 -> V_78 = V_78 ;
}
if ( V_117 -> V_63 [ 0 ] . V_65 & V_66 ) {
struct V_113 V_69 ;
V_52 = F_4 ( V_5 -> V_12 , V_13 ,
V_203 , & V_69 ) ;
if ( V_52 ) {
F_12 ( & V_5 -> V_37 ,
L_20 ) ;
goto V_200;
}
V_5 -> V_69 = V_69 ;
}
V_52 = F_3 ( V_5 ) ;
if ( V_52 ) {
F_12 ( & V_5 -> V_37 ,
L_21 ) ;
goto V_200;
}
return 0 ;
V_200:
F_79 ( & V_5 -> V_172 ) ;
V_196:
F_80 ( & V_5 -> V_182 ) ;
V_183:
F_81 ( & V_5 -> V_37 ) ;
V_181:
F_82 ( V_5 -> V_35 ) ;
V_171:
F_83 ( V_5 -> V_47 ) ;
V_170:
F_6 ( V_5 ) ;
return V_52 ;
}
static int F_84 ( struct V_159 * V_160 )
{
struct V_204 * V_37 = F_85 ( V_160 ) ;
struct V_4 * V_5 = F_2 ( V_37 ,
struct V_4 , V_37 ) ;
F_7 ( V_5 ) ;
F_79 ( & V_5 -> V_172 ) ;
F_80 ( & V_5 -> V_182 ) ;
F_81 ( V_37 ) ;
F_82 ( V_5 -> V_35 ) ;
F_83 ( V_5 -> V_47 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
