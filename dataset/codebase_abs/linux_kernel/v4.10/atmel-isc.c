static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 = V_3 -> V_4 ;
struct V_5 * V_5 = V_3 -> V_5 ;
F_3 ( V_3 -> V_6 , L_1 ,
V_7 , V_3 -> div , V_3 -> V_8 ) ;
F_4 ( V_5 , V_9 ,
F_5 ( V_4 ) | F_6 ( V_4 ) ,
( V_3 -> div << F_7 ( V_4 ) ) |
( V_3 -> V_8 << F_8 ( V_4 ) ) ) ;
F_9 ( V_5 , V_10 , F_10 ( V_4 ) ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 = V_3 -> V_4 ;
F_9 ( V_3 -> V_5 , V_11 , F_10 ( V_4 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_12 ;
F_13 ( V_3 -> V_5 , V_13 , & V_12 ) ;
return V_12 & F_10 ( V_3 -> V_4 ) ? 1 : 0 ;
}
static unsigned long
F_14 ( struct V_1 * V_2 , unsigned long V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_15 ( V_14 , V_3 -> div + 1 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
long V_17 = - V_18 ;
int V_19 = - 1 ;
unsigned int V_20 , div ;
for ( V_20 = 0 ; V_20 < F_17 ( V_2 ) ; V_20 ++ ) {
struct V_1 * V_21 ;
unsigned long V_14 ;
V_21 = F_18 ( V_2 , V_20 ) ;
if ( ! V_21 )
continue;
V_14 = F_19 ( V_21 ) ;
if ( ! V_14 )
continue;
for ( div = 1 ; div < V_22 + 2 ; div ++ ) {
unsigned long V_23 ;
int V_24 ;
V_23 = F_15 ( V_14 , div ) ;
V_24 = abs ( V_16 -> V_23 - V_23 ) ;
if ( V_19 < 0 || V_19 > V_24 ) {
V_17 = V_23 ;
V_19 = V_24 ;
V_16 -> V_25 = V_14 ;
V_16 -> V_26 = V_21 ;
}
if ( ! V_19 || V_23 < V_16 -> V_23 )
break;
}
if ( ! V_19 )
break;
}
F_3 ( V_3 -> V_6 ,
L_2 ,
V_7 , V_17 ,
F_20 ( ( V_16 -> V_26 ) -> V_27 ) ,
V_16 -> V_25 ) ;
if ( V_17 < 0 )
return V_17 ;
V_16 -> V_23 = V_17 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_28 >= F_17 ( V_2 ) )
return - V_18 ;
V_3 -> V_8 = V_28 ;
return 0 ;
}
static T_2 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_8 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_23 ,
unsigned long V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 div ;
if ( ! V_23 )
return - V_18 ;
div = F_15 ( V_14 , V_23 ) ;
if ( div > ( V_22 + 1 ) || ! div )
return - V_18 ;
V_3 -> div = div - 1 ;
return 0 ;
}
static int F_24 ( struct V_29 * V_30 , unsigned int V_4 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_31 * V_32 = V_30 -> V_6 -> V_33 ;
struct V_3 * V_3 ;
struct V_34 V_35 ;
const char * V_36 = V_32 -> V_37 ;
const char * V_38 [ 3 ] ;
int V_39 ;
V_39 = F_25 ( V_32 ) ;
if ( V_39 < 1 || V_39 > 3 )
return - V_18 ;
if ( V_39 > 2 && V_4 == V_40 )
V_39 = 2 ;
F_26 ( V_32 , V_38 , V_39 ) ;
if ( V_4 == V_41 )
F_27 ( V_32 , L_3 , & V_36 ) ;
else
V_36 = L_4 ;
V_35 . V_38 = V_38 ;
V_35 . V_39 = V_39 ;
V_35 . V_37 = V_36 ;
V_35 . V_42 = & V_43 ;
V_35 . V_44 = V_45 | V_46 ;
V_3 = & V_30 -> V_47 [ V_4 ] ;
V_3 -> V_2 . V_35 = & V_35 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_6 = V_30 -> V_6 ;
V_3 -> V_27 = F_28 ( V_30 -> V_6 , & V_3 -> V_2 ) ;
if ( F_29 ( V_3 -> V_27 ) ) {
F_30 ( V_30 -> V_6 , L_5 , V_36 ) ;
return F_31 ( V_3 -> V_27 ) ;
} else if ( V_4 == V_41 )
F_32 ( V_32 , V_48 , V_3 -> V_27 ) ;
return 0 ;
}
static int F_33 ( struct V_29 * V_30 )
{
unsigned int V_20 ;
int V_49 ;
for ( V_20 = 0 ; V_20 < F_34 ( V_30 -> V_47 ) ; V_20 ++ )
V_30 -> V_47 [ V_20 ] . V_27 = F_35 ( - V_18 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_30 -> V_47 ) ; V_20 ++ ) {
V_49 = F_24 ( V_30 , V_20 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static void F_36 ( struct V_29 * V_30 )
{
unsigned int V_20 ;
F_37 ( V_30 -> V_6 -> V_33 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_30 -> V_47 ) ; V_20 ++ ) {
struct V_3 * V_3 = & V_30 -> V_47 [ V_20 ] ;
if ( ! F_29 ( V_3 -> V_27 ) )
F_38 ( V_3 -> V_27 ) ;
}
}
static int F_39 ( struct V_50 * V_51 ,
unsigned int * V_52 , unsigned int * V_53 ,
unsigned int V_54 [] , struct V_55 * V_56 [] )
{
struct V_29 * V_30 = F_40 ( V_51 ) ;
unsigned int V_57 = V_30 -> V_58 . V_58 . V_59 . V_60 ;
if ( * V_53 )
return V_54 [ 0 ] < V_57 ? - V_18 : 0 ;
* V_53 = 1 ;
V_54 [ 0 ] = V_57 ;
return 0 ;
}
static int F_41 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_42 ( V_62 ) ;
struct V_29 * V_30 = F_40 ( V_62 -> V_50 ) ;
unsigned long V_57 = V_30 -> V_58 . V_58 . V_59 . V_60 ;
if ( F_43 ( V_62 , 0 ) < V_57 ) {
F_44 ( & V_30 -> V_65 , L_6 ,
F_43 ( V_62 , 0 ) , V_57 ) ;
return - V_18 ;
}
F_45 ( V_62 , 0 , V_57 ) ;
V_64 -> V_66 = V_30 -> V_58 . V_58 . V_59 . V_66 ;
return 0 ;
}
static inline void F_46 ( struct V_5 * V_5 ,
struct V_67 * V_68 , T_1 V_69 )
{
T_3 V_70 ;
V_70 = F_47 ( & V_68 -> V_62 . V_71 , 0 ) ;
F_9 ( V_5 , V_72 , V_69 | V_73 ) ;
F_9 ( V_5 , V_74 , V_70 ) ;
F_9 ( V_5 , V_75 , V_76 ) ;
}
static void F_48 ( struct V_29 * V_30 , T_1 V_77 )
{
T_1 V_78 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_79 ; V_20 ++ ) {
V_78 = V_77 & F_49 ( V_20 ) ? 1 : 0 ;
F_50 ( V_30 -> V_77 [ V_20 ] , V_78 ) ;
}
}
static int F_51 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
const struct V_80 * V_81 = V_30 -> V_81 ;
struct V_82 * V_83 = V_30 -> V_84 ;
T_1 V_78 , V_85 ;
int V_86 = 10 ;
V_78 = V_81 -> V_87 | V_83 -> V_88 |
V_89 ;
V_85 = V_90 | V_91 |
V_92 | V_93 |
V_94 ;
F_4 ( V_5 , V_95 , V_85 , V_78 ) ;
F_4 ( V_5 , V_96 , V_97 ,
V_81 -> V_98 ) ;
F_4 ( V_5 , V_99 , V_100 ,
V_81 -> V_101 ) ;
F_48 ( V_30 , 0x0 ) ;
F_9 ( V_5 , V_75 , V_102 ) ;
F_13 ( V_5 , V_103 , & V_78 ) ;
while ( ( V_78 & V_102 ) && V_86 -- ) {
F_52 ( 1000 , 2000 ) ;
F_13 ( V_5 , V_103 , & V_78 ) ;
}
if ( V_86 < 0 )
return - V_104 ;
return 0 ;
}
static int F_53 ( struct V_50 * V_51 , unsigned int V_105 )
{
struct V_29 * V_30 = F_40 ( V_51 ) ;
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_67 * V_106 ;
unsigned long V_44 ;
int V_49 ;
T_1 V_78 ;
V_49 = F_54 ( V_30 -> V_84 -> V_107 , V_108 , V_109 , 1 ) ;
if ( V_49 && V_49 != - V_110 ) {
F_44 ( & V_30 -> V_65 , L_7 ) ;
goto V_111;
}
F_55 ( V_30 -> V_6 ) ;
F_9 ( V_30 -> V_5 , V_112 , ( T_1 ) ~ 0UL ) ;
F_13 ( V_5 , V_113 , & V_78 ) ;
V_49 = F_51 ( V_30 ) ;
if ( F_56 ( V_49 ) )
goto V_114;
F_9 ( V_5 , V_115 , V_116 ) ;
F_57 ( & V_30 -> V_117 , V_44 ) ;
V_30 -> V_118 = 0 ;
V_30 -> V_119 = false ;
F_58 ( & V_30 -> V_120 ) ;
V_30 -> V_121 = F_59 ( & V_30 -> V_122 ,
struct V_67 , V_123 ) ;
F_60 ( & V_30 -> V_121 -> V_123 ) ;
F_46 ( V_5 , V_30 -> V_121 , V_30 -> V_81 -> V_124 ) ;
F_61 ( & V_30 -> V_117 , V_44 ) ;
return 0 ;
V_114:
F_62 ( V_30 -> V_6 ) ;
F_54 ( V_30 -> V_84 -> V_107 , V_108 , V_109 , 0 ) ;
V_111:
F_57 ( & V_30 -> V_117 , V_44 ) ;
F_63 (buf, &isc->dma_queue, list)
F_64 ( & V_106 -> V_62 . V_71 , V_125 ) ;
F_65 ( & V_30 -> V_122 ) ;
F_61 ( & V_30 -> V_117 , V_44 ) ;
return V_49 ;
}
static void F_66 ( struct V_50 * V_51 )
{
struct V_29 * V_30 = F_40 ( V_51 ) ;
unsigned long V_44 ;
struct V_67 * V_106 ;
int V_49 ;
V_30 -> V_119 = true ;
if ( V_30 -> V_121 && ! F_67 ( & V_30 -> V_120 , 5 * V_126 ) )
F_44 ( & V_30 -> V_65 ,
L_8 ) ;
F_9 ( V_30 -> V_5 , V_112 , V_116 ) ;
F_62 ( V_30 -> V_6 ) ;
V_49 = F_54 ( V_30 -> V_84 -> V_107 , V_108 , V_109 , 0 ) ;
if ( V_49 && V_49 != - V_110 )
F_44 ( & V_30 -> V_65 , L_9 ) ;
F_57 ( & V_30 -> V_117 , V_44 ) ;
if ( F_56 ( V_30 -> V_121 ) ) {
F_64 ( & V_30 -> V_121 -> V_62 . V_71 ,
V_127 ) ;
V_30 -> V_121 = NULL ;
}
F_63 (buf, &isc->dma_queue, list)
F_64 ( & V_106 -> V_62 . V_71 , V_127 ) ;
F_65 ( & V_30 -> V_122 ) ;
F_61 ( & V_30 -> V_117 , V_44 ) ;
}
static void F_68 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_42 ( V_62 ) ;
struct V_67 * V_106 = F_69 ( V_64 , struct V_67 , V_62 ) ;
struct V_29 * V_30 = F_40 ( V_62 -> V_50 ) ;
unsigned long V_44 ;
F_57 ( & V_30 -> V_117 , V_44 ) ;
if ( ! V_30 -> V_121 && F_70 ( & V_30 -> V_122 ) &&
F_71 ( V_62 -> V_50 ) ) {
V_30 -> V_121 = V_106 ;
F_46 ( V_30 -> V_5 , V_30 -> V_121 ,
V_30 -> V_81 -> V_124 ) ;
} else
F_72 ( & V_106 -> V_123 , & V_30 -> V_122 ) ;
F_61 ( & V_30 -> V_117 , V_44 ) ;
}
static int F_73 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
strcpy ( V_131 -> V_132 , V_133 ) ;
strcpy ( V_131 -> V_134 , L_10 ) ;
snprintf ( V_131 -> V_135 , sizeof( V_131 -> V_135 ) ,
L_11 , V_30 -> V_65 . V_37 ) ;
return 0 ;
}
static int F_75 ( struct V_128 * V_128 , void * V_129 ,
struct V_136 * V_137 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
T_1 V_28 = V_137 -> V_28 ;
if ( V_28 >= V_30 -> V_138 )
return - V_18 ;
V_137 -> V_139 = V_30 -> V_140 [ V_28 ] -> V_141 ;
return 0 ;
}
static int F_76 ( struct V_128 * V_128 , void * V_129 ,
struct V_142 * V_58 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
* V_58 = V_30 -> V_58 ;
return 0 ;
}
static struct V_80 * F_77 ( struct V_29 * V_30 ,
unsigned int V_141 )
{
unsigned int V_143 = V_30 -> V_138 ;
struct V_80 * V_58 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_143 ; V_20 ++ ) {
V_58 = V_30 -> V_140 [ V_20 ] ;
if ( V_58 -> V_141 == V_141 )
return V_58 ;
}
return NULL ;
}
static int F_78 ( struct V_29 * V_30 , struct V_142 * V_137 ,
struct V_80 * * V_81 )
{
struct V_80 * V_144 ;
struct V_145 * V_146 = & V_137 -> V_58 . V_59 ;
struct V_147 V_148 = {
. V_149 = V_150 ,
} ;
int V_49 ;
if ( V_137 -> type != V_151 )
return - V_18 ;
V_144 = F_77 ( V_30 , V_146 -> V_139 ) ;
if ( ! V_144 ) {
F_79 ( & V_30 -> V_65 , L_12 ,
V_146 -> V_139 ) ;
V_144 = V_30 -> V_140 [ V_30 -> V_138 - 1 ] ;
V_146 -> V_139 = V_144 -> V_141 ;
}
if ( V_146 -> V_152 > V_153 )
V_146 -> V_152 = V_153 ;
if ( V_146 -> V_154 > V_155 )
V_146 -> V_154 = V_155 ;
F_80 ( & V_148 . V_148 , V_146 , V_144 -> V_156 ) ;
V_49 = F_54 ( V_30 -> V_84 -> V_107 , V_157 , V_158 ,
V_30 -> V_84 -> V_159 , & V_148 ) ;
if ( V_49 < 0 )
return V_49 ;
F_81 ( V_146 , & V_148 . V_148 ) ;
V_146 -> V_66 = V_160 ;
V_146 -> V_161 = V_146 -> V_152 * V_144 -> V_162 ;
V_146 -> V_60 = V_146 -> V_161 * V_146 -> V_154 ;
if ( V_81 )
* V_81 = V_144 ;
return 0 ;
}
static int F_82 ( struct V_29 * V_30 , struct V_142 * V_137 )
{
struct V_147 V_148 = {
. V_149 = V_163 ,
} ;
struct V_80 * V_81 ;
int V_49 ;
V_49 = F_78 ( V_30 , V_137 , & V_81 ) ;
if ( V_49 )
return V_49 ;
F_80 ( & V_148 . V_148 , & V_137 -> V_58 . V_59 ,
V_81 -> V_156 ) ;
V_49 = F_54 ( V_30 -> V_84 -> V_107 , V_157 ,
V_158 , NULL , & V_148 ) ;
if ( V_49 < 0 )
return V_49 ;
V_30 -> V_58 = * V_137 ;
V_30 -> V_81 = V_81 ;
return 0 ;
}
static int F_83 ( struct V_128 * V_128 , void * V_129 ,
struct V_142 * V_137 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
if ( F_71 ( & V_30 -> V_164 ) )
return - V_165 ;
return F_82 ( V_30 , V_137 ) ;
}
static int F_84 ( struct V_128 * V_128 , void * V_129 ,
struct V_142 * V_137 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
return F_78 ( V_30 , V_137 , NULL ) ;
}
static int F_85 ( struct V_128 * V_128 , void * V_129 ,
struct V_166 * V_167 )
{
if ( V_167 -> V_28 != 0 )
return - V_18 ;
V_167 -> type = V_168 ;
V_167 -> V_169 = 0 ;
strcpy ( V_167 -> V_37 , L_13 ) ;
return 0 ;
}
static int F_86 ( struct V_128 * V_128 , void * V_129 , unsigned int * V_20 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_87 ( struct V_128 * V_128 , void * V_129 , unsigned int V_20 )
{
if ( V_20 > 0 )
return - V_18 ;
return 0 ;
}
static int F_88 ( struct V_128 * V_128 , void * V_170 , struct V_171 * V_172 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
if ( V_172 -> type != V_151 )
return - V_18 ;
return F_54 ( V_30 -> V_84 -> V_107 , V_108 , V_173 , V_172 ) ;
}
static int F_89 ( struct V_128 * V_128 , void * V_170 , struct V_171 * V_172 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
if ( V_172 -> type != V_151 )
return - V_18 ;
return F_54 ( V_30 -> V_84 -> V_107 , V_108 , V_174 , V_172 ) ;
}
static int F_90 ( struct V_128 * V_128 , void * V_170 ,
struct V_175 * V_176 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
const struct V_80 * V_144 ;
struct V_177 V_178 = {
. V_28 = V_176 -> V_28 ,
. V_149 = V_163 ,
} ;
int V_49 ;
V_144 = F_77 ( V_30 , V_176 -> V_179 ) ;
if ( ! V_144 )
return - V_18 ;
V_178 . V_180 = V_144 -> V_156 ;
V_49 = F_54 ( V_30 -> V_84 -> V_107 , V_157 , V_181 ,
NULL , & V_178 ) ;
if ( V_49 )
return V_49 ;
V_176 -> type = V_182 ;
V_176 -> V_183 . V_152 = V_178 . V_184 ;
V_176 -> V_183 . V_154 = V_178 . V_185 ;
return 0 ;
}
static int F_91 ( struct V_128 * V_128 , void * V_170 ,
struct V_186 * V_187 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
const struct V_80 * V_144 ;
struct V_188 V_189 = {
. V_28 = V_187 -> V_28 ,
. V_152 = V_187 -> V_152 ,
. V_154 = V_187 -> V_154 ,
. V_149 = V_163 ,
} ;
int V_49 ;
V_144 = F_77 ( V_30 , V_187 -> V_179 ) ;
if ( ! V_144 )
return - V_18 ;
V_189 . V_180 = V_144 -> V_156 ;
V_49 = F_54 ( V_30 -> V_84 -> V_107 , V_157 ,
V_190 , NULL , & V_189 ) ;
if ( V_49 )
return V_49 ;
V_187 -> type = V_191 ;
V_187 -> V_183 = V_189 . V_192 ;
return 0 ;
}
static int F_92 ( struct V_128 * V_128 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
struct V_193 * V_107 = V_30 -> V_84 -> V_107 ;
int V_49 ;
if ( F_93 ( & V_30 -> V_194 ) )
return - V_195 ;
V_49 = F_94 ( V_128 ) ;
if ( V_49 < 0 )
goto V_196;
if ( ! F_95 ( V_128 ) )
goto V_196;
V_49 = F_54 ( V_107 , V_197 , V_198 , 1 ) ;
if ( V_49 < 0 && V_49 != - V_110 ) {
F_96 ( V_128 ) ;
goto V_196;
}
V_49 = F_82 ( V_30 , & V_30 -> V_58 ) ;
if ( V_49 ) {
F_54 ( V_107 , V_197 , V_198 , 0 ) ;
F_96 ( V_128 ) ;
}
V_196:
F_97 ( & V_30 -> V_194 ) ;
return V_49 ;
}
static int F_98 ( struct V_128 * V_128 )
{
struct V_29 * V_30 = F_74 ( V_128 ) ;
struct V_193 * V_107 = V_30 -> V_84 -> V_107 ;
bool V_199 ;
int V_49 ;
F_99 ( & V_30 -> V_194 ) ;
V_199 = F_95 ( V_128 ) ;
V_49 = F_100 ( V_128 , NULL ) ;
if ( V_199 )
F_54 ( V_107 , V_197 , V_198 , 0 ) ;
F_97 ( & V_30 -> V_194 ) ;
return V_49 ;
}
static T_4 F_101 ( int V_200 , void * V_201 )
{
struct V_29 * V_30 = (struct V_29 * ) V_201 ;
struct V_5 * V_5 = V_30 -> V_5 ;
T_1 V_202 , V_203 , V_204 ;
T_4 V_49 = V_205 ;
F_102 ( & V_30 -> V_117 ) ;
F_13 ( V_5 , V_113 , & V_202 ) ;
F_13 ( V_5 , V_206 , & V_203 ) ;
V_204 = V_202 & V_203 ;
if ( F_103 ( V_204 & V_116 ) ) {
if ( V_30 -> V_121 ) {
struct V_63 * V_64 = & V_30 -> V_121 -> V_62 ;
struct V_61 * V_62 = & V_64 -> V_71 ;
V_62 -> V_207 = F_104 () ;
V_64 -> V_118 = V_30 -> V_118 ++ ;
F_64 ( V_62 , V_208 ) ;
V_30 -> V_121 = NULL ;
}
if ( ! F_70 ( & V_30 -> V_122 ) && ! V_30 -> V_119 ) {
V_30 -> V_121 = F_59 ( & V_30 -> V_122 ,
struct V_67 , V_123 ) ;
F_60 ( & V_30 -> V_121 -> V_123 ) ;
F_46 ( V_5 , V_30 -> V_121 ,
V_30 -> V_81 -> V_124 ) ;
}
if ( V_30 -> V_119 )
F_105 ( & V_30 -> V_120 ) ;
V_49 = V_209 ;
}
F_106 ( & V_30 -> V_117 ) ;
return V_49 ;
}
static int F_107 ( struct V_210 * V_211 ,
struct V_193 * V_83 ,
struct V_212 * V_213 )
{
struct V_29 * V_30 = F_69 ( V_211 -> V_65 ,
struct V_29 , V_65 ) ;
struct V_82 * V_214 =
F_69 ( V_211 , struct V_82 , V_211 ) ;
if ( F_108 ( & V_30 -> V_215 ) ) {
F_44 ( & V_30 -> V_65 , L_14 ) ;
return - V_165 ;
}
V_214 -> V_107 = V_83 ;
return 0 ;
}
static void F_109 ( struct V_210 * V_211 ,
struct V_193 * V_83 ,
struct V_212 * V_213 )
{
struct V_29 * V_30 = F_69 ( V_211 -> V_65 ,
struct V_29 , V_65 ) ;
F_110 ( & V_30 -> V_215 ) ;
if ( V_30 -> V_84 -> V_159 )
F_111 ( V_30 -> V_84 -> V_159 ) ;
}
static struct V_80 * F_112 ( unsigned int V_180 , int * V_28 )
{
struct V_80 * V_58 = & V_216 [ 0 ] ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < F_34 ( V_216 ) ; V_20 ++ ) {
if ( V_58 -> V_156 == V_180 ) {
* V_28 = V_20 ;
return V_58 ;
}
V_58 ++ ;
}
return NULL ;
}
static int F_113 ( struct V_29 * V_30 )
{
struct V_80 * V_58 ;
struct V_193 * V_83 = V_30 -> V_84 -> V_107 ;
int V_217 = 0 , V_20 , V_218 ;
struct V_219 V_156 = {
. V_149 = V_163 ,
} ;
V_58 = & V_216 [ 0 ] ;
for ( V_20 = 0 ; V_20 < F_34 ( V_216 ) ; V_20 ++ ) {
V_58 -> V_220 = false ;
V_58 ++ ;
}
while ( ! F_54 ( V_83 , V_157 , V_221 ,
NULL , & V_156 ) ) {
V_156 . V_28 ++ ;
V_58 = F_112 ( V_156 . V_180 , & V_20 ) ;
if ( ! V_58 )
continue;
V_58 -> V_220 = true ;
V_217 ++ ;
}
if ( ! V_217 )
return - V_222 ;
V_30 -> V_138 = V_217 ;
V_30 -> V_140 = F_114 ( V_30 -> V_6 ,
V_217 , sizeof( struct V_80 * ) ,
V_223 ) ;
if ( ! V_30 -> V_140 ) {
F_44 ( & V_30 -> V_65 , L_15 ) ;
return - V_224 ;
}
V_58 = & V_216 [ 0 ] ;
for ( V_20 = 0 , V_218 = 0 ; V_20 < F_34 ( V_216 ) ; V_20 ++ ) {
if ( V_58 -> V_220 )
V_30 -> V_140 [ V_218 ++ ] = V_58 ;
V_58 ++ ;
}
return 0 ;
}
static int F_115 ( struct V_29 * V_30 )
{
struct V_142 V_137 = {
. type = V_151 ,
. V_58 . V_59 = {
. V_152 = V_225 ,
. V_154 = V_226 ,
. V_66 = V_160 ,
. V_139 = V_30 -> V_140 [ 0 ] -> V_141 ,
} ,
} ;
int V_49 ;
V_49 = F_78 ( V_30 , & V_137 , NULL ) ;
if ( V_49 )
return V_49 ;
V_30 -> V_81 = V_30 -> V_140 [ 0 ] ;
V_30 -> V_58 = V_137 ;
return 0 ;
}
static int F_116 ( struct V_210 * V_211 )
{
struct V_29 * V_30 = F_69 ( V_211 -> V_65 ,
struct V_29 , V_65 ) ;
struct V_82 * V_227 ;
struct V_228 * V_229 = & V_30 -> V_215 ;
struct V_50 * V_230 = & V_30 -> V_164 ;
int V_49 ;
V_30 -> V_84 = F_69 ( V_211 ,
struct V_82 , V_211 ) ;
V_227 = V_30 -> V_84 ;
F_117 ( & V_30 -> V_194 ) ;
F_118 ( & V_30 -> V_120 ) ;
V_230 -> type = V_151 ;
V_230 -> V_231 = V_232 | V_233 | V_234 ;
V_230 -> V_235 = V_30 ;
V_230 -> V_236 = sizeof( struct V_67 ) ;
V_230 -> V_42 = & V_237 ;
V_230 -> V_238 = & V_239 ;
V_230 -> V_240 = V_241 ;
V_230 -> V_194 = & V_30 -> V_194 ;
V_230 -> V_242 = 1 ;
V_230 -> V_6 = V_30 -> V_6 ;
V_49 = F_119 ( V_230 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 ,
L_16 , V_49 ) ;
return V_49 ;
}
F_65 ( & V_30 -> V_122 ) ;
F_120 ( & V_30 -> V_117 ) ;
V_227 -> V_159 = F_121 ( V_227 -> V_107 ) ;
if ( V_227 -> V_159 == NULL )
return - V_224 ;
V_49 = F_113 ( V_30 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 ,
L_17 , V_49 ) ;
return V_49 ;
}
V_49 = F_115 ( V_30 ) ;
if ( V_49 ) {
F_44 ( & V_30 -> V_65 , L_18 ) ;
return V_49 ;
}
F_122 ( V_229 -> V_37 , V_133 , sizeof( V_229 -> V_37 ) ) ;
V_229 -> V_243 = V_244 ;
V_229 -> V_245 = & V_246 ;
V_229 -> V_247 = & V_248 ;
V_229 -> V_65 = & V_30 -> V_65 ;
V_229 -> V_249 = V_250 ;
V_229 -> V_251 = V_230 ;
V_229 -> V_194 = & V_30 -> V_194 ;
V_229 -> V_252 = V_30 -> V_84 -> V_107 -> V_252 ;
V_229 -> V_253 = V_254 | V_255 ;
F_123 ( V_229 , V_30 ) ;
V_49 = F_124 ( V_229 , V_256 , - 1 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 ,
L_19 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static void F_125 ( struct V_29 * V_30 )
{
struct V_82 * V_214 ;
F_63 (subdev_entity, &isc->subdev_entities, list)
F_126 ( & V_214 -> V_211 ) ;
F_65 ( & V_30 -> V_257 ) ;
}
static int F_127 ( struct V_29 * V_30 )
{
struct V_55 * V_6 = V_30 -> V_6 ;
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_258 * V_259 ;
unsigned int V_20 ;
const struct V_260 V_261 [ V_79 ] = {
F_128 ( V_262 , 0 , 0 ) ,
F_128 ( V_263 , 0 , 0 ) ,
F_128 ( V_264 , 0 , 0 ) ,
F_128 ( V_265 , 0 , 0 ) ,
F_128 ( V_265 , 1 , 1 ) ,
F_128 ( V_265 , 2 , 2 ) ,
F_128 ( V_265 , 3 , 3 ) ,
F_128 ( V_266 , 0 , 0 ) ,
F_128 ( V_267 , 0 , 0 ) ,
F_128 ( V_268 , 0 , 0 ) ,
F_128 ( V_269 , 0 , 0 ) ,
} ;
for ( V_20 = 0 ; V_20 < V_79 ; V_20 ++ ) {
V_259 = F_129 ( V_6 , V_5 , V_261 [ V_20 ] ) ;
if ( F_29 ( V_259 ) )
return F_31 ( V_259 ) ;
V_30 -> V_77 [ V_20 ] = V_259 ;
}
return 0 ;
}
static int F_130 ( struct V_55 * V_6 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_6 -> V_33 ;
struct V_31 * V_270 = NULL , * V_271 ;
struct V_272 V_273 ;
struct V_82 * V_214 ;
unsigned int V_44 ;
int V_49 ;
F_65 ( & V_30 -> V_257 ) ;
for (; ; ) {
V_270 = F_131 ( V_32 , V_270 ) ;
if ( ! V_270 )
break;
V_271 = F_132 ( V_270 ) ;
if ( ! V_271 ) {
F_133 ( V_6 , L_20 ,
F_134 ( V_270 ) ) ;
continue;
}
V_49 = F_135 ( V_270 , & V_273 ) ;
if ( V_49 ) {
F_136 ( V_271 ) ;
V_49 = - V_18 ;
F_30 ( V_6 , L_21 ) ;
break;
}
V_214 = F_137 ( V_6 ,
sizeof( * V_214 ) , V_223 ) ;
if ( V_214 == NULL ) {
F_136 ( V_271 ) ;
V_49 = - V_224 ;
break;
}
V_214 -> V_213 = F_137 ( V_6 ,
sizeof( * V_214 -> V_213 ) , V_223 ) ;
if ( V_214 -> V_213 == NULL ) {
F_136 ( V_271 ) ;
V_49 = - V_224 ;
break;
}
V_44 = V_273 . V_274 . V_275 . V_44 ;
if ( V_44 & V_276 )
V_214 -> V_88 = V_91 ;
if ( V_44 & V_277 )
V_214 -> V_88 |= V_92 ;
if ( V_44 & V_278 )
V_214 -> V_88 |= V_93 ;
V_214 -> V_213 -> V_279 = V_280 ;
V_214 -> V_213 -> V_281 . V_282 . V_283 = V_271 ;
F_72 ( & V_214 -> V_123 , & V_30 -> V_257 ) ;
}
F_136 ( V_270 ) ;
return V_49 ;
}
static int F_138 ( struct V_284 * V_285 )
{
struct V_55 * V_6 = & V_285 -> V_6 ;
struct V_29 * V_30 ;
struct V_286 * V_287 ;
void T_5 * V_288 ;
struct V_82 * V_214 ;
int V_200 ;
int V_49 ;
V_30 = F_137 ( V_6 , sizeof( * V_30 ) , V_223 ) ;
if ( ! V_30 )
return - V_224 ;
F_139 ( V_285 , V_30 ) ;
V_30 -> V_6 = V_6 ;
V_287 = F_140 ( V_285 , V_289 , 0 ) ;
V_288 = F_141 ( V_6 , V_287 ) ;
if ( F_29 ( V_288 ) )
return F_31 ( V_288 ) ;
V_30 -> V_5 = F_142 ( V_6 , V_288 , & V_290 ) ;
if ( F_29 ( V_30 -> V_5 ) ) {
V_49 = F_31 ( V_30 -> V_5 ) ;
F_30 ( V_6 , L_22 , V_49 ) ;
return V_49 ;
}
V_200 = F_143 ( V_285 , 0 ) ;
if ( V_200 < 0 ) {
V_49 = V_200 ;
F_30 ( V_6 , L_23 , V_49 ) ;
return V_49 ;
}
V_49 = F_144 ( V_6 , V_200 , F_101 , 0 ,
V_133 , V_30 ) ;
if ( V_49 < 0 ) {
F_30 ( V_6 , L_24 ,
V_200 , V_49 ) ;
return V_49 ;
}
V_49 = F_127 ( V_30 ) ;
if ( V_49 )
return V_49 ;
V_30 -> V_291 = F_145 ( V_6 , L_25 ) ;
if ( F_29 ( V_30 -> V_291 ) ) {
V_49 = F_31 ( V_30 -> V_291 ) ;
F_30 ( V_6 , L_26 , V_49 ) ;
return V_49 ;
}
V_49 = F_33 ( V_30 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_27 , V_49 ) ;
goto V_292;
}
V_30 -> V_293 = V_30 -> V_47 [ V_40 ] . V_27 ;
V_49 = F_146 ( V_30 -> V_293 , F_147 ( V_30 -> V_291 ) ) ;
if ( V_49 ) {
F_30 ( V_6 , L_28 , V_49 ) ;
goto V_292;
}
V_49 = F_148 ( V_6 , & V_30 -> V_65 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_29 ) ;
goto V_292;
}
V_49 = F_130 ( V_6 , V_30 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_30 ) ;
goto V_294;
}
if ( F_70 ( & V_30 -> V_257 ) ) {
F_30 ( V_6 , L_31 ) ;
V_49 = - V_295 ;
goto V_294;
}
F_63 (subdev_entity, &isc->subdev_entities, list) {
V_214 -> V_211 . V_296 = & V_214 -> V_213 ;
V_214 -> V_211 . V_297 = 1 ;
V_214 -> V_211 . V_298 = F_107 ;
V_214 -> V_211 . V_299 = F_109 ;
V_214 -> V_211 . F_105 = F_116 ;
V_49 = F_149 ( & V_30 -> V_65 ,
& V_214 -> V_211 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_32 ) ;
goto V_300;
}
if ( F_108 ( & V_30 -> V_215 ) )
break;
}
F_150 ( V_6 ) ;
return 0 ;
V_300:
F_125 ( V_30 ) ;
V_294:
F_151 ( & V_30 -> V_65 ) ;
V_292:
F_36 ( V_30 ) ;
return V_49 ;
}
static int F_152 ( struct V_284 * V_285 )
{
struct V_29 * V_30 = F_153 ( V_285 ) ;
F_154 ( & V_285 -> V_6 ) ;
F_125 ( V_30 ) ;
F_151 ( & V_30 -> V_65 ) ;
F_36 ( V_30 ) ;
return 0 ;
}
static int T_6 F_155 ( struct V_55 * V_6 )
{
struct V_29 * V_30 = F_156 ( V_6 ) ;
F_157 ( V_30 -> V_293 ) ;
F_157 ( V_30 -> V_291 ) ;
return 0 ;
}
static int T_6 F_158 ( struct V_55 * V_6 )
{
struct V_29 * V_30 = F_156 ( V_6 ) ;
int V_49 ;
V_49 = F_159 ( V_30 -> V_291 ) ;
if ( V_49 )
return V_49 ;
return F_159 ( V_30 -> V_293 ) ;
}
