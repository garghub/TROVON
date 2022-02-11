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
unsigned int * V_30 , unsigned int * V_31 ,
unsigned int V_32 [] , void * V_33 [] )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
if ( V_29 -> V_34 + * V_30 < 2 )
* V_30 = 2 ;
V_33 [ 0 ] = V_5 -> V_35 ;
if ( * V_31 )
return V_32 [ 0 ] < V_5 -> V_36 . V_37 ? - V_25 : 0 ;
* V_31 = 1 ;
V_32 [ 0 ] = V_5 -> V_36 . V_37 ;
return 0 ;
}
static int F_10 ( struct V_38 * V_3 )
{
struct V_2 * V_39 = F_11 ( V_3 ) ;
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
unsigned long V_40 = V_5 -> V_36 . V_37 ;
if ( F_12 ( V_3 , 0 ) < V_40 ) {
F_13 ( & V_5 -> V_41 , L_1 ,
F_12 ( V_3 , 0 ) , V_40 ) ;
return - V_25 ;
}
F_14 ( V_3 , 0 , V_40 ) ;
V_39 -> V_42 = V_5 -> V_36 . V_42 ;
return 0 ;
}
static void F_15 ( struct V_38 * V_3 )
{
struct V_2 * V_39 = F_11 ( V_3 ) ;
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
struct V_1 * V_43 = F_1 ( V_39 ) ;
unsigned long V_44 ;
F_16 ( & V_5 -> V_45 , V_44 ) ;
F_17 ( & V_43 -> V_46 , & V_5 -> V_47 ) ;
F_18 ( & V_5 -> V_45 , V_44 ) ;
}
static void F_19 ( struct V_38 * V_3 )
{
struct V_2 * V_39 = F_11 ( V_3 ) ;
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
struct V_1 * V_43 = F_1 ( V_39 ) ;
unsigned long V_44 ;
F_16 ( & V_5 -> V_45 , V_44 ) ;
F_20 ( & V_43 -> V_46 ) ;
F_18 ( & V_5 -> V_45 , V_44 ) ;
}
static int F_21 ( struct V_28 * V_29 , unsigned int V_48 )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
struct V_49 * V_50 = V_5 -> V_50 ;
struct V_1 * V_43 , * V_51 ;
struct V_52 V_53 ;
T_1 V_54 ;
int V_55 ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_57 , 1 ) ;
if ( V_55 && ( V_55 != - V_58 ) ) {
F_13 ( & V_5 -> V_41 , L_2 ) ;
goto V_59;
}
V_53 . V_60 = V_5 -> V_36 . V_60 ;
V_53 . V_61 = V_5 -> V_36 . V_61 ;
V_53 . V_62 = V_5 -> V_62 ;
V_53 . V_63 = V_5 -> V_63 ;
V_53 . V_64 = V_5 -> V_65 -> V_64 ;
V_53 . V_66 = V_5 -> V_65 -> V_66 ;
if ( V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] . V_69
& V_70 ) {
struct V_71 * V_72 = & V_5 -> V_73 . V_72 ;
V_53 . V_74 = V_72 -> V_75 + V_72 -> V_76 ;
V_53 . V_77 = V_72 -> V_78 + V_72 -> V_79 ;
V_53 . line = F_22 ( V_72 ) ;
V_53 . V_80 = F_23 ( V_72 ) ;
} else if ( V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] . V_69
& V_81 ) {
V_53 . V_74 = 0 ;
V_53 . V_77 = 0 ;
if ( V_5 -> V_82 & V_83 ) {
V_53 . line = 858 ;
V_53 . V_80 = 525 ;
} else {
V_53 . line = 864 ;
V_53 . V_80 = 625 ;
}
} else {
V_53 . V_74 = 0 ;
V_53 . V_77 = 0 ;
V_53 . line = V_53 . V_60 + V_5 -> V_65 -> V_84 ;
V_53 . V_80 = V_53 . V_61 ;
}
V_55 = V_50 -> V_85 -> V_86 ( V_50 , & V_53 ) ;
if ( V_55 < 0 ) {
F_13 ( & V_5 -> V_41 ,
L_3 ) ;
goto V_59;
}
V_55 = V_50 -> V_85 -> V_87 ( V_50 , V_88 ) ;
if ( V_55 < 0 ) {
F_13 ( & V_5 -> V_41 ,
L_4 ) ;
goto V_59;
}
V_5 -> V_89 = 0 ;
F_24 ( & V_5 -> V_90 ) ;
V_5 -> V_91 = false ;
V_5 -> V_92 = F_25 ( V_5 -> V_47 . V_93 ,
struct V_1 , V_46 ) ;
F_20 ( & V_5 -> V_92 -> V_46 ) ;
V_54 = F_26 ( & V_5 -> V_92 -> V_3 . V_94 ,
0 ) ;
V_50 -> V_85 -> V_95 ( V_50 , ( unsigned long ) V_54 ) ;
V_50 -> V_85 -> V_96 ( V_50 ) ;
return 0 ;
V_59:
F_27 (buf, tmp, &bcap_dev->dma_queue, list) {
F_28 ( & V_43 -> V_46 ) ;
F_29 ( & V_43 -> V_3 . V_94 , V_97 ) ;
}
return V_55 ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
struct V_49 * V_50 = V_5 -> V_50 ;
int V_55 ;
V_5 -> V_91 = true ;
F_31 ( & V_5 -> V_90 ) ;
V_50 -> V_85 -> V_91 ( V_50 ) ;
V_50 -> V_85 -> V_98 ( V_50 ) ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_57 , 0 ) ;
if ( V_55 && ( V_55 != - V_58 ) )
F_13 ( & V_5 -> V_41 ,
L_5 ) ;
if ( V_5 -> V_92 )
F_29 ( & V_5 -> V_92 -> V_3 . V_94 ,
V_99 ) ;
while ( ! F_32 ( & V_5 -> V_47 ) ) {
V_5 -> V_92 = F_25 ( V_5 -> V_47 . V_93 ,
struct V_1 , V_46 ) ;
F_20 ( & V_5 -> V_92 -> V_46 ) ;
F_29 ( & V_5 -> V_92 -> V_3 . V_94 ,
V_99 ) ;
}
}
static T_2 V_88 ( int V_100 , void * V_101 )
{
struct V_49 * V_50 = V_101 ;
struct V_4 * V_5 = V_50 -> V_102 ;
struct V_2 * V_39 = & V_5 -> V_92 -> V_3 ;
struct V_38 * V_3 = & V_39 -> V_94 ;
T_1 V_54 ;
F_33 ( & V_5 -> V_45 ) ;
if ( ! F_32 ( & V_5 -> V_47 ) ) {
V_3 -> V_103 = F_34 () ;
if ( V_50 -> V_59 ) {
F_29 ( V_3 , V_99 ) ;
V_50 -> V_59 = false ;
} else {
V_39 -> V_89 = V_5 -> V_89 ++ ;
F_29 ( V_3 , V_104 ) ;
}
V_5 -> V_92 = F_25 ( V_5 -> V_47 . V_93 ,
struct V_1 , V_46 ) ;
F_20 ( & V_5 -> V_92 -> V_46 ) ;
} else {
if ( V_50 -> V_59 )
V_50 -> V_59 = false ;
}
V_50 -> V_85 -> V_91 ( V_50 ) ;
if ( V_5 -> V_91 ) {
F_35 ( & V_5 -> V_90 ) ;
} else {
V_54 = F_26 (
& V_5 -> V_92 -> V_3 . V_94 , 0 ) ;
V_50 -> V_85 -> V_95 ( V_50 , ( unsigned long ) V_54 ) ;
V_50 -> V_85 -> V_96 ( V_50 ) ;
}
F_36 ( & V_5 -> V_45 ) ;
return V_105 ;
}
static int F_37 ( struct V_106 * V_106 , void * V_102 , T_3 * V_82 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_81 ) )
return - V_109 ;
return F_4 ( V_5 -> V_15 , V_56 , V_110 , V_82 ) ;
}
static int F_39 ( struct V_106 * V_106 , void * V_102 , T_3 * V_82 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_81 ) )
return - V_109 ;
* V_82 = V_5 -> V_82 ;
return 0 ;
}
static int F_40 ( struct V_106 * V_106 , void * V_102 , T_3 V_82 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
int V_55 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_81 ) )
return - V_109 ;
if ( F_41 ( & V_5 -> V_111 ) )
return - V_112 ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_113 , V_82 ) ;
if ( V_55 < 0 )
return V_55 ;
V_5 -> V_82 = V_82 ;
return 0 ;
}
static int F_42 ( struct V_106 * V_106 , void * V_102 ,
struct V_114 * V_115 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_70 ) )
return - V_109 ;
V_115 -> V_16 = 0 ;
return F_4 ( V_5 -> V_15 , V_16 ,
V_116 , V_115 ) ;
}
static int F_43 ( struct V_106 * V_106 , void * V_102 ,
struct V_117 * V_115 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_70 ) )
return - V_109 ;
return F_4 ( V_5 -> V_15 , V_56 ,
V_118 , V_115 ) ;
}
static int F_44 ( struct V_106 * V_106 , void * V_102 ,
struct V_117 * V_115 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_70 ) )
return - V_109 ;
* V_115 = V_5 -> V_73 ;
return 0 ;
}
static int F_45 ( struct V_106 * V_106 , void * V_102 ,
struct V_117 * V_115 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_107 V_108 ;
int V_55 ;
V_108 = V_5 -> V_65 -> V_67 [ V_5 -> V_68 ] ;
if ( ! ( V_108 . V_69 & V_70 ) )
return - V_109 ;
if ( F_41 ( & V_5 -> V_111 ) )
return - V_112 ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_119 , V_115 ) ;
if ( V_55 < 0 )
return V_55 ;
V_5 -> V_73 = * V_115 ;
return 0 ;
}
static int F_46 ( struct V_106 * V_106 , void * V_102 ,
struct V_107 * V_108 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_120 * V_121 = V_5 -> V_65 ;
int V_55 ;
T_4 V_122 ;
if ( V_108 -> V_18 >= V_121 -> V_123 )
return - V_25 ;
* V_108 = V_121 -> V_67 [ V_108 -> V_18 ] ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_124 , & V_122 ) ;
if ( ! V_55 )
V_108 -> V_122 = V_122 ;
return 0 ;
}
static int F_47 ( struct V_106 * V_106 , void * V_102 , unsigned int * V_18 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
* V_18 = V_5 -> V_68 ;
return 0 ;
}
static int F_48 ( struct V_106 * V_106 , void * V_102 , unsigned int V_18 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_120 * V_121 = V_5 -> V_65 ;
struct V_125 * V_126 ;
int V_55 ;
if ( F_41 ( & V_5 -> V_111 ) )
return - V_112 ;
if ( V_18 >= V_121 -> V_123 )
return - V_25 ;
V_126 = & V_121 -> V_127 [ V_18 ] ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_128 ,
V_126 -> V_108 , V_126 -> V_129 , 0 ) ;
if ( ( V_55 < 0 ) && ( V_55 != - V_58 ) ) {
F_13 ( & V_5 -> V_41 , L_6 ) ;
return V_55 ;
}
V_5 -> V_68 = V_18 ;
if ( V_126 -> V_64 )
V_121 -> V_64 = V_126 -> V_64 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_130 ,
struct V_131 * V_132 ,
struct V_10 * V_133 )
{
struct V_10 * V_11 = V_130 -> V_26 ;
struct V_10 * V_36 = NULL ;
struct V_134 V_135 ;
struct V_136 V_137 = {
. V_8 = V_138 ,
} ;
int V_55 , V_13 ;
for ( V_13 = 0 ; V_13 < V_130 -> V_27 ; V_13 ++ ) {
V_36 = & V_11 [ V_13 ] ;
if ( V_132 -> V_139 == V_36 -> V_139 )
break;
}
if ( V_13 == V_130 -> V_27 )
V_36 = & V_11 [ 0 ] ;
F_50 ( & V_137 . V_137 , V_132 , V_36 -> V_24 ) ;
V_55 = F_4 ( V_130 -> V_15 , V_16 , V_140 , & V_135 ,
& V_137 ) ;
if ( V_55 < 0 )
return V_55 ;
F_51 ( V_132 , & V_137 . V_137 ) ;
if ( V_133 ) {
for ( V_13 = 0 ; V_13 < V_130 -> V_27 ; V_13 ++ ) {
V_36 = & V_11 [ V_13 ] ;
if ( V_137 . V_137 . V_7 == V_36 -> V_24 )
break;
}
* V_133 = * V_36 ;
}
V_132 -> V_141 = V_132 -> V_60 * V_36 -> V_62 / 8 ;
V_132 -> V_37 = V_132 -> V_141 * V_132 -> V_61 ;
return 0 ;
}
static int F_52 ( struct V_106 * V_106 , void * V_102 ,
struct V_142 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_10 * V_11 = V_5 -> V_26 ;
if ( V_36 -> V_18 >= V_5 -> V_27 )
return - V_25 ;
V_36 -> type = V_143 ;
F_53 ( V_36 -> V_144 ,
V_11 [ V_36 -> V_18 ] . V_145 ,
sizeof( V_36 -> V_144 ) ) ;
V_36 -> V_139 = V_11 [ V_36 -> V_18 ] . V_139 ;
return 0 ;
}
static int F_54 ( struct V_106 * V_106 , void * V_102 ,
struct V_146 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_131 * V_132 = & V_36 -> V_36 . V_147 ;
return F_49 ( V_5 , V_132 , NULL ) ;
}
static int F_55 ( struct V_106 * V_106 , void * V_102 ,
struct V_146 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
V_36 -> V_36 . V_147 = V_5 -> V_36 ;
return 0 ;
}
static int F_56 ( struct V_106 * V_106 , void * V_102 ,
struct V_146 * V_36 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
struct V_136 V_137 = {
. V_8 = V_9 ,
} ;
struct V_10 V_133 ;
struct V_131 * V_132 = & V_36 -> V_36 . V_147 ;
int V_55 ;
if ( F_41 ( & V_5 -> V_111 ) )
return - V_112 ;
V_55 = F_49 ( V_5 , V_132 , & V_133 ) ;
if ( V_55 < 0 )
return V_55 ;
F_50 ( & V_137 . V_137 , V_132 , V_133 . V_24 ) ;
V_55 = F_4 ( V_5 -> V_15 , V_16 , V_140 , NULL , & V_137 ) ;
if ( V_55 < 0 )
return V_55 ;
V_5 -> V_36 = * V_132 ;
V_5 -> V_62 = V_133 . V_62 ;
V_5 -> V_63 = V_133 . V_63 ;
return 0 ;
}
static int F_57 ( struct V_106 * V_106 , void * V_102 ,
struct V_148 * V_149 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
V_149 -> V_150 = V_151 | V_152 ;
V_149 -> V_69 = V_149 -> V_150 | V_153 ;
F_53 ( V_149 -> V_154 , V_155 , sizeof( V_149 -> V_154 ) ) ;
F_53 ( V_149 -> V_156 , L_7 , sizeof( V_149 -> V_156 ) ) ;
F_53 ( V_149 -> V_157 , V_5 -> V_65 -> V_158 , sizeof( V_149 -> V_157 ) ) ;
return 0 ;
}
static int F_58 ( struct V_106 * V_106 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
if ( V_161 -> type != V_143 )
return - V_25 ;
return F_4 ( V_5 -> V_15 , V_56 , V_162 , V_161 ) ;
}
static int F_59 ( struct V_106 * V_106 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
if ( V_161 -> type != V_143 )
return - V_25 ;
return F_4 ( V_5 -> V_15 , V_56 , V_163 , V_161 ) ;
}
static int F_60 ( struct V_106 * V_106 , void * V_102 )
{
struct V_4 * V_5 = F_38 ( V_106 ) ;
F_61 ( & V_5 -> V_41 , 0 , V_164 , V_165 ) ;
return 0 ;
}
static int F_62 ( struct V_166 * V_167 )
{
struct V_4 * V_5 ;
struct V_168 * V_169 ;
struct V_170 * V_171 ;
struct V_120 * V_121 ;
struct V_28 * V_172 ;
struct V_125 * V_126 ;
int V_55 ;
V_121 = V_167 -> V_173 . V_174 ;
if ( ! V_121 || ! V_121 -> V_123 ) {
F_13 ( V_167 -> V_173 . V_154 , L_8 ) ;
return - V_175 ;
}
V_5 = F_5 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 ) {
F_13 ( V_167 -> V_173 . V_154 , L_9 ) ;
return - V_21 ;
}
V_5 -> V_65 = V_121 ;
V_5 -> V_50 = F_63 ( V_167 , V_121 -> V_176 ) ;
if ( ! V_5 -> V_50 ) {
F_13 ( V_167 -> V_173 . V_154 , L_10 ) ;
V_55 = - V_175 ;
goto V_177;
}
V_5 -> V_50 -> V_102 = V_5 ;
V_5 -> V_35 = F_64 ( & V_167 -> V_173 ) ;
if ( F_65 ( V_5 -> V_35 ) ) {
V_55 = F_66 ( V_5 -> V_35 ) ;
goto V_178;
}
V_169 = & V_5 -> V_179 ;
V_169 -> V_180 = V_181 ;
V_169 -> V_182 = & V_183 ;
V_169 -> V_184 = & V_185 ;
V_169 -> V_186 = 0 ;
V_169 -> V_41 = & V_5 -> V_41 ;
strncpy ( V_169 -> V_187 , V_155 , sizeof( V_169 -> V_187 ) ) ;
V_55 = F_67 ( & V_167 -> V_173 , & V_5 -> V_41 ) ;
if ( V_55 ) {
F_13 ( V_167 -> V_173 . V_154 ,
L_11 ) ;
goto V_188;
}
F_68 ( & V_5 -> V_41 , L_12 ) ;
V_5 -> V_41 . V_189 = & V_5 -> V_189 ;
V_55 = F_69 ( & V_5 -> V_189 , 0 ) ;
if ( V_55 ) {
F_13 ( & V_5 -> V_41 ,
L_13 ) ;
goto V_190;
}
F_70 ( & V_5 -> V_45 ) ;
V_172 = & V_5 -> V_111 ;
V_172 -> type = V_143 ;
V_172 -> V_191 = V_192 | V_193 ;
V_172 -> V_194 = V_5 ;
V_172 -> V_195 = sizeof( struct V_1 ) ;
V_172 -> V_85 = & V_196 ;
V_172 -> V_197 = & V_198 ;
V_172 -> V_199 = V_200 ;
V_172 -> V_45 = & V_5 -> V_201 ;
V_172 -> V_202 = 1 ;
V_55 = F_71 ( V_172 ) ;
if ( V_55 )
goto V_203;
F_72 ( & V_5 -> V_201 ) ;
F_73 ( & V_5 -> V_90 ) ;
F_74 ( & V_5 -> V_47 ) ;
V_169 -> V_45 = & V_5 -> V_201 ;
V_169 -> V_204 = V_172 ;
V_55 = F_75 ( & V_5 -> V_179 , V_205 , - 1 ) ;
if ( V_55 ) {
F_13 ( & V_5 -> V_41 ,
L_14 ) ;
goto V_203;
}
F_76 ( & V_5 -> V_179 , V_5 ) ;
F_68 ( & V_5 -> V_41 , L_15 ,
F_77 ( V_169 ) ) ;
V_171 = F_78 ( V_121 -> V_206 ) ;
if ( ! V_171 ) {
F_13 ( & V_5 -> V_41 ,
L_16 ) ;
V_55 = - V_175 ;
goto V_207;
}
V_5 -> V_15 = F_79 ( & V_5 -> V_41 ,
V_171 ,
& V_121 -> V_208 ,
NULL ) ;
if ( V_5 -> V_15 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_121 -> V_123 ; V_13 ++ )
V_169 -> V_186 |= V_121 -> V_67 [ V_13 ] . V_82 ;
} else {
F_13 ( & V_5 -> V_41 ,
L_17 ) ;
V_55 = - V_175 ;
goto V_207;
}
F_68 ( & V_5 -> V_41 , L_18 ) ;
V_126 = & V_121 -> V_127 [ 0 ] ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_128 ,
V_126 -> V_108 , V_126 -> V_129 , 0 ) ;
if ( ( V_55 < 0 ) && ( V_55 != - V_58 ) ) {
F_13 ( & V_5 -> V_41 , L_6 ) ;
goto V_207;
}
V_5 -> V_68 = 0 ;
if ( V_126 -> V_64 )
V_121 -> V_64 = V_126 -> V_64 ;
if ( V_121 -> V_67 [ 0 ] . V_69 & V_81 ) {
T_3 V_82 ;
V_55 = F_4 ( V_5 -> V_15 , V_56 , V_209 , & V_82 ) ;
if ( V_55 ) {
F_13 ( & V_5 -> V_41 ,
L_19 ) ;
goto V_207;
}
V_5 -> V_82 = V_82 ;
}
if ( V_121 -> V_67 [ 0 ] . V_69 & V_70 ) {
struct V_117 V_73 ;
V_55 = F_4 ( V_5 -> V_15 , V_56 ,
V_210 , & V_73 ) ;
if ( V_55 ) {
F_13 ( & V_5 -> V_41 ,
L_20 ) ;
goto V_207;
}
V_5 -> V_73 = V_73 ;
}
V_55 = F_3 ( V_5 ) ;
if ( V_55 ) {
F_13 ( & V_5 -> V_41 ,
L_21 ) ;
goto V_207;
}
return 0 ;
V_207:
F_80 ( & V_5 -> V_179 ) ;
V_203:
F_81 ( & V_5 -> V_189 ) ;
V_190:
F_82 ( & V_5 -> V_41 ) ;
V_188:
F_83 ( V_5 -> V_35 ) ;
V_178:
F_84 ( V_5 -> V_50 ) ;
V_177:
F_6 ( V_5 ) ;
return V_55 ;
}
static int F_85 ( struct V_166 * V_167 )
{
struct V_211 * V_41 = F_86 ( V_167 ) ;
struct V_4 * V_5 = F_2 ( V_41 ,
struct V_4 , V_41 ) ;
F_7 ( V_5 ) ;
F_80 ( & V_5 -> V_179 ) ;
F_81 ( & V_5 -> V_189 ) ;
F_82 ( V_41 ) ;
F_83 ( V_5 -> V_35 ) ;
F_84 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
