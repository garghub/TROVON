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
const struct V_30 * V_31 ,
unsigned int * V_32 , unsigned int * V_33 ,
unsigned int V_34 [] , void * V_35 [] )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
if ( V_31 && V_31 -> V_31 . V_36 . V_37 < V_5 -> V_31 . V_37 )
return - V_25 ;
if ( V_29 -> V_38 + * V_32 < 2 )
* V_32 = 2 ;
* V_33 = 1 ;
V_34 [ 0 ] = V_31 ? V_31 -> V_31 . V_36 . V_37 : V_5 -> V_31 . V_37 ;
V_35 [ 0 ] = V_5 -> V_39 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
unsigned long V_40 = V_5 -> V_31 . V_37 ;
if ( F_11 ( V_3 , 0 ) < V_40 ) {
F_12 ( & V_5 -> V_41 , L_1 ,
F_11 ( V_3 , 0 ) , V_40 ) ;
return - V_25 ;
}
F_13 ( V_3 , 0 , V_40 ) ;
V_3 -> V_42 . V_43 = V_5 -> V_31 . V_43 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
struct V_1 * V_44 = F_1 ( V_3 ) ;
unsigned long V_45 ;
F_15 ( & V_5 -> V_46 , V_45 ) ;
F_16 ( & V_44 -> V_47 , & V_5 -> V_48 ) ;
F_17 ( & V_5 -> V_46 , V_45 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_3 -> V_28 ) ;
struct V_1 * V_44 = F_1 ( V_3 ) ;
unsigned long V_45 ;
F_15 ( & V_5 -> V_46 , V_45 ) ;
F_19 ( & V_44 -> V_47 ) ;
F_17 ( & V_5 -> V_46 , V_45 ) ;
}
static int F_20 ( struct V_28 * V_29 , unsigned int V_49 )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
struct V_1 * V_44 , * V_52 ;
struct V_53 V_54 ;
T_1 V_55 ;
int V_56 ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_58 , 1 ) ;
if ( V_56 && ( V_56 != - V_59 ) ) {
F_12 ( & V_5 -> V_41 , L_2 ) ;
goto V_60;
}
V_54 . V_61 = V_5 -> V_31 . V_61 ;
V_54 . V_62 = V_5 -> V_31 . V_62 ;
V_54 . V_63 = V_5 -> V_63 ;
V_54 . V_64 = V_5 -> V_64 ;
V_54 . V_65 = V_5 -> V_66 -> V_65 ;
V_54 . V_67 = V_5 -> V_66 -> V_67 ;
if ( V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] . V_70
& V_71 ) {
struct V_72 * V_73 = & V_5 -> V_74 . V_73 ;
V_54 . V_75 = V_73 -> V_76 + V_73 -> V_77 ;
V_54 . V_78 = V_73 -> V_79 + V_73 -> V_80 ;
V_54 . line = F_21 ( V_73 ) ;
V_54 . V_81 = F_22 ( V_73 ) ;
} else if ( V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] . V_70
& V_82 ) {
V_54 . V_75 = 0 ;
V_54 . V_78 = 0 ;
if ( V_5 -> V_83 & V_84 ) {
V_54 . line = 858 ;
V_54 . V_81 = 525 ;
} else {
V_54 . line = 864 ;
V_54 . V_81 = 625 ;
}
} else {
V_54 . V_75 = 0 ;
V_54 . V_78 = 0 ;
V_54 . line = V_54 . V_61 + V_5 -> V_66 -> V_85 ;
V_54 . V_81 = V_54 . V_62 ;
}
V_56 = V_51 -> V_86 -> V_87 ( V_51 , & V_54 ) ;
if ( V_56 < 0 ) {
F_12 ( & V_5 -> V_41 ,
L_3 ) ;
goto V_60;
}
V_56 = V_51 -> V_86 -> V_88 ( V_51 , V_89 ) ;
if ( V_56 < 0 ) {
F_12 ( & V_5 -> V_41 ,
L_4 ) ;
goto V_60;
}
V_5 -> V_90 = 0 ;
F_23 ( & V_5 -> V_91 ) ;
V_5 -> V_92 = false ;
V_5 -> V_93 = F_24 ( V_5 -> V_48 . V_94 ,
struct V_1 , V_47 ) ;
F_19 ( & V_5 -> V_93 -> V_47 ) ;
V_55 = F_25 ( & V_5 -> V_93 -> V_3 , 0 ) ;
V_51 -> V_86 -> V_95 ( V_51 , ( unsigned long ) V_55 ) ;
V_51 -> V_86 -> V_96 ( V_51 ) ;
return 0 ;
V_60:
F_26 (buf, tmp, &bcap_dev->dma_queue, list) {
F_27 ( & V_44 -> V_47 ) ;
F_28 ( & V_44 -> V_3 , V_97 ) ;
}
return V_56 ;
}
static void F_29 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_9 ( V_29 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
int V_56 ;
V_5 -> V_92 = true ;
F_30 ( & V_5 -> V_91 ) ;
V_51 -> V_86 -> V_92 ( V_51 ) ;
V_51 -> V_86 -> V_98 ( V_51 ) ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_58 , 0 ) ;
if ( V_56 && ( V_56 != - V_59 ) )
F_12 ( & V_5 -> V_41 ,
L_5 ) ;
if ( V_5 -> V_93 )
F_28 ( & V_5 -> V_93 -> V_3 , V_99 ) ;
while ( ! F_31 ( & V_5 -> V_48 ) ) {
V_5 -> V_93 = F_24 ( V_5 -> V_48 . V_94 ,
struct V_1 , V_47 ) ;
F_19 ( & V_5 -> V_93 -> V_47 ) ;
F_28 ( & V_5 -> V_93 -> V_3 , V_99 ) ;
}
}
static T_2 V_89 ( int V_100 , void * V_101 )
{
struct V_50 * V_51 = V_101 ;
struct V_4 * V_5 = V_51 -> V_102 ;
struct V_2 * V_3 = & V_5 -> V_93 -> V_3 ;
T_1 V_55 ;
F_32 ( & V_5 -> V_46 ) ;
if ( ! F_31 ( & V_5 -> V_48 ) ) {
F_33 ( & V_3 -> V_42 . V_103 ) ;
if ( V_51 -> V_60 ) {
F_28 ( V_3 , V_99 ) ;
V_51 -> V_60 = false ;
} else {
V_3 -> V_42 . V_90 = V_5 -> V_90 ++ ;
F_28 ( V_3 , V_104 ) ;
}
V_5 -> V_93 = F_24 ( V_5 -> V_48 . V_94 ,
struct V_1 , V_47 ) ;
F_19 ( & V_5 -> V_93 -> V_47 ) ;
} else {
if ( V_51 -> V_60 )
V_51 -> V_60 = false ;
}
V_51 -> V_86 -> V_92 ( V_51 ) ;
if ( V_5 -> V_92 ) {
F_34 ( & V_5 -> V_91 ) ;
} else {
V_55 = F_25 ( & V_5 -> V_93 -> V_3 , 0 ) ;
V_51 -> V_86 -> V_95 ( V_51 , ( unsigned long ) V_55 ) ;
V_51 -> V_86 -> V_96 ( V_51 ) ;
}
F_35 ( & V_5 -> V_46 ) ;
return V_105 ;
}
static int F_36 ( struct V_106 * V_106 , void * V_102 , T_3 * V_83 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_82 ) )
return - V_109 ;
return F_4 ( V_5 -> V_15 , V_57 , V_110 , V_83 ) ;
}
static int F_38 ( struct V_106 * V_106 , void * V_102 , T_3 * V_83 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_82 ) )
return - V_109 ;
* V_83 = V_5 -> V_83 ;
return 0 ;
}
static int F_39 ( struct V_106 * V_106 , void * V_102 , T_3 V_83 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
int V_56 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_82 ) )
return - V_109 ;
if ( F_40 ( & V_5 -> V_111 ) )
return - V_112 ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_113 , V_83 ) ;
if ( V_56 < 0 )
return V_56 ;
V_5 -> V_83 = V_83 ;
return 0 ;
}
static int F_41 ( struct V_106 * V_106 , void * V_102 ,
struct V_114 * V_115 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_71 ) )
return - V_109 ;
V_115 -> V_16 = 0 ;
return F_4 ( V_5 -> V_15 , V_16 ,
V_116 , V_115 ) ;
}
static int F_42 ( struct V_106 * V_106 , void * V_102 ,
struct V_117 * V_115 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_71 ) )
return - V_109 ;
return F_4 ( V_5 -> V_15 , V_57 ,
V_118 , V_115 ) ;
}
static int F_43 ( struct V_106 * V_106 , void * V_102 ,
struct V_117 * V_115 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_71 ) )
return - V_109 ;
* V_115 = V_5 -> V_74 ;
return 0 ;
}
static int F_44 ( struct V_106 * V_106 , void * V_102 ,
struct V_117 * V_115 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_107 V_108 ;
int V_56 ;
V_108 = V_5 -> V_66 -> V_68 [ V_5 -> V_69 ] ;
if ( ! ( V_108 . V_70 & V_71 ) )
return - V_109 ;
if ( F_40 ( & V_5 -> V_111 ) )
return - V_112 ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_119 , V_115 ) ;
if ( V_56 < 0 )
return V_56 ;
V_5 -> V_74 = * V_115 ;
return 0 ;
}
static int F_45 ( struct V_106 * V_106 , void * V_102 ,
struct V_107 * V_108 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_120 * V_121 = V_5 -> V_66 ;
int V_56 ;
T_4 V_122 ;
if ( V_108 -> V_18 >= V_121 -> V_123 )
return - V_25 ;
* V_108 = V_121 -> V_68 [ V_108 -> V_18 ] ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_124 , & V_122 ) ;
if ( ! V_56 )
V_108 -> V_122 = V_122 ;
return 0 ;
}
static int F_46 ( struct V_106 * V_106 , void * V_102 , unsigned int * V_18 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
* V_18 = V_5 -> V_69 ;
return 0 ;
}
static int F_47 ( struct V_106 * V_106 , void * V_102 , unsigned int V_18 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_120 * V_121 = V_5 -> V_66 ;
struct V_125 * V_126 ;
int V_56 ;
if ( F_40 ( & V_5 -> V_111 ) )
return - V_112 ;
if ( V_18 >= V_121 -> V_123 )
return - V_25 ;
V_126 = & V_121 -> V_127 [ V_18 ] ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_128 ,
V_126 -> V_108 , V_126 -> V_129 , 0 ) ;
if ( ( V_56 < 0 ) && ( V_56 != - V_59 ) ) {
F_12 ( & V_5 -> V_41 , L_6 ) ;
return V_56 ;
}
V_5 -> V_69 = V_18 ;
if ( V_126 -> V_65 )
V_121 -> V_65 = V_126 -> V_65 ;
return 0 ;
}
static int F_48 ( struct V_4 * V_130 ,
struct V_131 * V_132 ,
struct V_10 * V_133 )
{
struct V_10 * V_11 = V_130 -> V_26 ;
struct V_10 * V_31 = NULL ;
struct V_134 V_135 ;
struct V_136 V_137 = {
. V_8 = V_138 ,
} ;
int V_56 , V_13 ;
for ( V_13 = 0 ; V_13 < V_130 -> V_27 ; V_13 ++ ) {
V_31 = & V_11 [ V_13 ] ;
if ( V_132 -> V_139 == V_31 -> V_139 )
break;
}
if ( V_13 == V_130 -> V_27 )
V_31 = & V_11 [ 0 ] ;
F_49 ( & V_137 . V_137 , V_132 , V_31 -> V_24 ) ;
V_56 = F_4 ( V_130 -> V_15 , V_16 , V_140 , & V_135 ,
& V_137 ) ;
if ( V_56 < 0 )
return V_56 ;
F_50 ( V_132 , & V_137 . V_137 ) ;
if ( V_133 ) {
for ( V_13 = 0 ; V_13 < V_130 -> V_27 ; V_13 ++ ) {
V_31 = & V_11 [ V_13 ] ;
if ( V_137 . V_137 . V_7 == V_31 -> V_24 )
break;
}
* V_133 = * V_31 ;
}
V_132 -> V_141 = V_132 -> V_61 * V_31 -> V_63 / 8 ;
V_132 -> V_37 = V_132 -> V_141 * V_132 -> V_62 ;
return 0 ;
}
static int F_51 ( struct V_106 * V_106 , void * V_102 ,
struct V_142 * V_31 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_10 * V_11 = V_5 -> V_26 ;
if ( V_31 -> V_18 >= V_5 -> V_27 )
return - V_25 ;
V_31 -> type = V_143 ;
F_52 ( V_31 -> V_144 ,
V_11 [ V_31 -> V_18 ] . V_145 ,
sizeof( V_31 -> V_144 ) ) ;
V_31 -> V_139 = V_11 [ V_31 -> V_18 ] . V_139 ;
return 0 ;
}
static int F_53 ( struct V_106 * V_106 , void * V_102 ,
struct V_30 * V_31 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_131 * V_132 = & V_31 -> V_31 . V_36 ;
return F_48 ( V_5 , V_132 , NULL ) ;
}
static int F_54 ( struct V_106 * V_106 , void * V_102 ,
struct V_30 * V_31 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
V_31 -> V_31 . V_36 = V_5 -> V_31 ;
return 0 ;
}
static int F_55 ( struct V_106 * V_106 , void * V_102 ,
struct V_30 * V_31 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
struct V_136 V_137 = {
. V_8 = V_9 ,
} ;
struct V_10 V_133 ;
struct V_131 * V_132 = & V_31 -> V_31 . V_36 ;
int V_56 ;
if ( F_40 ( & V_5 -> V_111 ) )
return - V_112 ;
V_56 = F_48 ( V_5 , V_132 , & V_133 ) ;
if ( V_56 < 0 )
return V_56 ;
F_49 ( & V_137 . V_137 , V_132 , V_133 . V_24 ) ;
V_56 = F_4 ( V_5 -> V_15 , V_16 , V_140 , NULL , & V_137 ) ;
if ( V_56 < 0 )
return V_56 ;
V_5 -> V_31 = * V_132 ;
V_5 -> V_63 = V_133 . V_63 ;
V_5 -> V_64 = V_133 . V_64 ;
return 0 ;
}
static int F_56 ( struct V_106 * V_106 , void * V_102 ,
struct V_146 * V_147 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
V_147 -> V_148 = V_149 | V_150 ;
V_147 -> V_70 = V_147 -> V_148 | V_151 ;
F_52 ( V_147 -> V_152 , V_153 , sizeof( V_147 -> V_152 ) ) ;
F_52 ( V_147 -> V_154 , L_7 , sizeof( V_147 -> V_154 ) ) ;
F_52 ( V_147 -> V_155 , V_5 -> V_66 -> V_156 , sizeof( V_147 -> V_155 ) ) ;
return 0 ;
}
static int F_57 ( struct V_106 * V_106 , void * V_157 ,
struct V_158 * V_159 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
if ( V_159 -> type != V_143 )
return - V_25 ;
return F_4 ( V_5 -> V_15 , V_57 , V_160 , V_159 ) ;
}
static int F_58 ( struct V_106 * V_106 , void * V_157 ,
struct V_158 * V_159 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
if ( V_159 -> type != V_143 )
return - V_25 ;
return F_4 ( V_5 -> V_15 , V_57 , V_161 , V_159 ) ;
}
static int F_59 ( struct V_106 * V_106 , void * V_102 )
{
struct V_4 * V_5 = F_37 ( V_106 ) ;
F_60 ( & V_5 -> V_41 , 0 , V_162 , V_163 ) ;
return 0 ;
}
static int F_61 ( struct V_164 * V_165 )
{
struct V_4 * V_5 ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
struct V_120 * V_121 ;
struct V_28 * V_170 ;
struct V_125 * V_126 ;
int V_56 ;
V_121 = V_165 -> V_171 . V_172 ;
if ( ! V_121 || ! V_121 -> V_123 ) {
F_12 ( V_165 -> V_171 . V_152 , L_8 ) ;
return - V_173 ;
}
V_5 = F_5 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 ) {
F_12 ( V_165 -> V_171 . V_152 , L_9 ) ;
return - V_21 ;
}
V_5 -> V_66 = V_121 ;
V_5 -> V_51 = F_62 ( V_165 , V_121 -> V_174 ) ;
if ( ! V_5 -> V_51 ) {
F_12 ( V_165 -> V_171 . V_152 , L_10 ) ;
V_56 = - V_173 ;
goto V_175;
}
V_5 -> V_51 -> V_102 = V_5 ;
V_5 -> V_39 = F_63 ( & V_165 -> V_171 ) ;
if ( F_64 ( V_5 -> V_39 ) ) {
V_56 = F_65 ( V_5 -> V_39 ) ;
goto V_176;
}
V_167 = & V_5 -> V_177 ;
V_167 -> V_178 = V_179 ;
V_167 -> V_180 = & V_181 ;
V_167 -> V_182 = & V_183 ;
V_167 -> V_184 = 0 ;
V_167 -> V_41 = & V_5 -> V_41 ;
strncpy ( V_167 -> V_185 , V_153 , sizeof( V_167 -> V_185 ) ) ;
V_56 = F_66 ( & V_165 -> V_171 , & V_5 -> V_41 ) ;
if ( V_56 ) {
F_12 ( V_165 -> V_171 . V_152 ,
L_11 ) ;
goto V_186;
}
F_67 ( & V_5 -> V_41 , L_12 ) ;
V_5 -> V_41 . V_187 = & V_5 -> V_187 ;
V_56 = F_68 ( & V_5 -> V_187 , 0 ) ;
if ( V_56 ) {
F_12 ( & V_5 -> V_41 ,
L_13 ) ;
goto V_188;
}
F_69 ( & V_5 -> V_46 ) ;
V_170 = & V_5 -> V_111 ;
V_170 -> type = V_143 ;
V_170 -> V_189 = V_190 | V_191 ;
V_170 -> V_192 = V_5 ;
V_170 -> V_193 = sizeof( struct V_1 ) ;
V_170 -> V_86 = & V_194 ;
V_170 -> V_195 = & V_196 ;
V_170 -> V_197 = V_198 ;
V_170 -> V_46 = & V_5 -> V_199 ;
V_170 -> V_200 = 1 ;
V_56 = F_70 ( V_170 ) ;
if ( V_56 )
goto V_201;
F_71 ( & V_5 -> V_199 ) ;
F_72 ( & V_5 -> V_91 ) ;
F_73 ( & V_5 -> V_48 ) ;
V_167 -> V_46 = & V_5 -> V_199 ;
V_167 -> V_202 = V_170 ;
V_56 = F_74 ( & V_5 -> V_177 , V_203 , - 1 ) ;
if ( V_56 ) {
F_12 ( & V_5 -> V_41 ,
L_14 ) ;
goto V_201;
}
F_75 ( & V_5 -> V_177 , V_5 ) ;
F_67 ( & V_5 -> V_41 , L_15 ,
F_76 ( V_167 ) ) ;
V_169 = F_77 ( V_121 -> V_204 ) ;
if ( ! V_169 ) {
F_12 ( & V_5 -> V_41 ,
L_16 ) ;
V_56 = - V_173 ;
goto V_205;
}
V_5 -> V_15 = F_78 ( & V_5 -> V_41 ,
V_169 ,
& V_121 -> V_206 ,
NULL ) ;
if ( V_5 -> V_15 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_121 -> V_123 ; V_13 ++ )
V_167 -> V_184 |= V_121 -> V_68 [ V_13 ] . V_83 ;
} else {
F_12 ( & V_5 -> V_41 ,
L_17 ) ;
V_56 = - V_173 ;
goto V_205;
}
F_67 ( & V_5 -> V_41 , L_18 ) ;
V_126 = & V_121 -> V_127 [ 0 ] ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_128 ,
V_126 -> V_108 , V_126 -> V_129 , 0 ) ;
if ( ( V_56 < 0 ) && ( V_56 != - V_59 ) ) {
F_12 ( & V_5 -> V_41 , L_6 ) ;
goto V_205;
}
V_5 -> V_69 = 0 ;
if ( V_126 -> V_65 )
V_121 -> V_65 = V_126 -> V_65 ;
if ( V_121 -> V_68 [ 0 ] . V_70 & V_82 ) {
T_3 V_83 ;
V_56 = F_4 ( V_5 -> V_15 , V_57 , V_207 , & V_83 ) ;
if ( V_56 ) {
F_12 ( & V_5 -> V_41 ,
L_19 ) ;
goto V_205;
}
V_5 -> V_83 = V_83 ;
}
if ( V_121 -> V_68 [ 0 ] . V_70 & V_71 ) {
struct V_117 V_74 ;
V_56 = F_4 ( V_5 -> V_15 , V_57 ,
V_208 , & V_74 ) ;
if ( V_56 ) {
F_12 ( & V_5 -> V_41 ,
L_20 ) ;
goto V_205;
}
V_5 -> V_74 = V_74 ;
}
V_56 = F_3 ( V_5 ) ;
if ( V_56 ) {
F_12 ( & V_5 -> V_41 ,
L_21 ) ;
goto V_205;
}
return 0 ;
V_205:
F_79 ( & V_5 -> V_177 ) ;
V_201:
F_80 ( & V_5 -> V_187 ) ;
V_188:
F_81 ( & V_5 -> V_41 ) ;
V_186:
F_82 ( V_5 -> V_39 ) ;
V_176:
F_83 ( V_5 -> V_51 ) ;
V_175:
F_6 ( V_5 ) ;
return V_56 ;
}
static int F_84 ( struct V_164 * V_165 )
{
struct V_209 * V_41 = F_85 ( V_165 ) ;
struct V_4 * V_5 = F_2 ( V_41 ,
struct V_4 , V_41 ) ;
F_7 ( V_5 ) ;
F_79 ( & V_5 -> V_177 ) ;
F_80 ( & V_5 -> V_187 ) ;
F_81 ( V_41 ) ;
F_82 ( V_5 -> V_39 ) ;
F_83 ( V_5 -> V_51 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
