static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
enum V_6 V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 . V_12 -> V_8 ;
struct V_13 * V_14 = (struct V_13 * ) V_4 -> V_15 ;
struct V_13 * V_16 ;
char * V_17 = NULL ;
unsigned long V_18 = 0 ;
int V_19 , V_20 ;
F_2 (sgl, sg, data->size, i)
V_18 += F_3 ( V_9 , V_16 ) ;
if ( V_18 > V_21 )
V_17 = ( void * ) F_4 ( V_22 ,
F_5 ( F_6 ( V_18 ) ) - V_23 ) ;
else
V_17 = F_7 ( V_18 , V_22 ) ;
if ( V_17 == NULL ) {
F_8 ( L_1 ,
V_4 -> V_24 , ( int ) V_18 ) ;
return - V_25 ;
}
if ( V_7 == V_26 ) {
char * V_27 , * V_28 ;
V_14 = (struct V_13 * ) V_4 -> V_15 ;
V_27 = V_17 ;
F_2 (sgl, sg, data->size, i) {
V_28 = F_9 ( F_10 ( V_16 ) ) ;
memcpy ( V_27 ,
V_28 + V_16 -> V_29 ,
V_16 -> V_30 ) ;
F_11 ( V_28 ) ;
V_27 += V_16 -> V_30 ;
}
}
F_12 ( & V_5 -> V_31 , V_17 , V_18 ) ;
V_5 -> V_15 = & V_5 -> V_31 ;
V_5 -> V_24 = 1 ;
V_5 -> V_32 = V_17 ;
V_19 = F_13 ( V_9 , & V_5 -> V_31 , 1 ,
( V_7 == V_26 ) ?
V_33 : V_34 ) ;
F_14 ( V_19 == 0 ) ;
V_5 -> V_19 = V_19 ;
V_5 -> V_35 = V_18 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
enum V_6 V_7 )
{
struct V_8 * V_9 ;
unsigned long V_18 ;
V_9 = V_2 -> V_10 -> V_11 . V_12 -> V_8 ;
F_16 ( V_9 , & V_5 -> V_31 , 1 ,
( V_7 == V_26 ) ?
V_33 : V_34 ) ;
if ( V_7 == V_36 ) {
char * V_17 ;
struct V_13 * V_14 , * V_16 ;
unsigned char * V_27 , * V_37 ;
unsigned int V_38 ;
int V_20 ;
V_17 = V_5 -> V_32 ;
V_14 = (struct V_13 * ) V_4 -> V_15 ;
V_38 = V_4 -> V_24 ;
V_27 = V_17 ;
F_2 (sgl, sg, sg_size, i) {
V_37 = F_9 ( F_10 ( V_16 ) ) ;
memcpy ( V_37 + V_16 -> V_29 ,
V_27 ,
V_16 -> V_30 ) ;
F_11 ( V_37 ) ;
V_27 += V_16 -> V_30 ;
}
}
V_18 = V_4 -> V_35 ;
if ( V_18 > V_21 )
F_17 ( ( unsigned long ) V_5 -> V_32 ,
F_5 ( F_6 ( V_18 ) ) - V_23 ) ;
else
F_18 ( V_5 -> V_32 ) ;
V_5 -> V_32 = NULL ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_8 * V_39 , T_1 * V_40 ,
int * V_29 , int * V_41 )
{
struct V_13 * V_16 , * V_14 = (struct V_13 * ) V_4 -> V_15 ;
T_1 V_42 , V_43 , V_44 , V_45 = 0 ;
unsigned long V_46 = 0 ;
unsigned int V_47 ;
int V_20 , V_48 , V_49 , V_50 = V_4 -> V_19 - 1 ;
* V_29 = ( T_1 ) V_14 [ 0 ] . V_29 & ~ V_51 ;
V_48 = 1 ;
V_49 = 0 ;
F_2 (sgl, sg, data->dma_nents, i) {
V_42 = F_20 ( V_39 , V_16 ) ;
if ( V_48 )
V_45 = V_42 ;
V_47 = F_3 ( V_39 , V_16 ) ;
V_43 = V_42 + V_47 ;
V_46 += V_47 ;
if ( ! F_21 ( V_43 ) && V_20 < V_50 ) {
V_48 = 0 ;
continue;
}
V_48 = 1 ;
V_44 = V_45 & V_51 ;
do {
V_40 [ V_49 ++ ] = V_44 ;
V_44 += V_52 ;
} while ( V_44 < V_43 );
}
* V_41 = V_46 ;
F_22 ( L_2 ,
* V_41 , V_49 ) ;
return V_49 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_8 * V_39 )
{
struct V_13 * V_14 , * V_16 , * V_53 = NULL ;
T_1 V_42 , V_43 ;
int V_20 , V_54 , V_55 = 0 ;
if ( V_4 -> V_19 == 1 )
return 1 ;
V_14 = (struct V_13 * ) V_4 -> V_15 ;
V_42 = F_20 ( V_39 , V_14 ) ;
F_2 (sgl, sg, data->dma_nents, i) {
if ( V_55 && ! F_21 ( V_42 ) )
break;
V_53 = F_24 ( V_16 ) ;
if ( ! V_53 )
break;
V_43 = V_42 + F_3 ( V_39 , V_16 ) ;
V_42 = F_20 ( V_39 , V_53 ) ;
if ( V_43 == V_42 ) {
V_55 = 0 ;
continue;
} else
V_55 = 1 ;
if ( ! F_21 ( V_43 ) )
break;
}
V_54 = ( V_53 ) ? V_20 : V_20 + 1 ;
F_22 ( L_3 ,
V_54 , V_4 -> V_19 , V_4 ) ;
return V_54 ;
}
static void F_25 ( struct V_3 * V_4 ,
struct V_8 * V_39 )
{
struct V_13 * V_14 = (struct V_13 * ) V_4 -> V_15 ;
struct V_13 * V_16 ;
int V_20 ;
F_2 (sgl, sg, data->dma_nents, i)
F_22 ( L_4
L_5 ,
V_20 , ( unsigned long ) F_20 ( V_39 , V_16 ) ,
F_10 ( V_16 ) , V_16 -> V_29 ,
V_16 -> V_30 , F_3 ( V_39 , V_16 ) ) ;
}
static void F_26 ( struct V_56 * V_57 )
{
int V_20 ;
F_8 ( L_6 ,
V_57 -> V_30 , V_57 -> V_41 ) ;
for ( V_20 = 0 ; V_20 < V_57 -> V_30 ; V_20 ++ )
F_8 ( L_7 , V_20 , ( unsigned long ) V_57 -> V_40 [ V_20 ] ) ;
}
static void F_27 ( struct V_3 * V_4 ,
struct V_56 * V_57 ,
struct V_8 * V_39 )
{
int V_58 = 0 ;
V_57 -> V_30 = 0 ;
V_57 -> V_29 = 0 ;
F_22 ( L_8 , V_4 -> V_19 ) ;
V_58 = F_19 ( V_4 , V_39 , V_57 -> V_40 ,
& V_57 -> V_29 ,
& V_57 -> V_41 ) ;
F_22 ( L_9 , V_4 -> V_19 , V_58 ) ;
V_57 -> V_30 = V_58 ;
if ( V_58 * V_52 < V_57 -> V_41 ) {
F_8 ( L_10 ) ;
F_25 ( V_4 , V_39 ) ;
F_26 ( V_57 ) ;
F_28 () ;
}
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_6 V_59 ,
enum V_60 V_61 )
{
struct V_8 * V_9 ;
V_2 -> V_62 [ V_59 ] = 1 ;
V_9 = V_2 -> V_10 -> V_11 . V_12 -> V_8 ;
V_4 -> V_19 = F_13 ( V_9 , V_4 -> V_15 , V_4 -> V_24 , V_61 ) ;
if ( V_4 -> V_19 == 0 ) {
F_8 ( L_11 ) ;
return - V_63 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_60 V_62 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_10 -> V_11 . V_12 -> V_8 ;
F_16 ( V_9 , V_4 -> V_15 , V_4 -> V_24 , V_62 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_8 * V_39 ,
struct V_3 * V_17 ,
struct V_3 * V_64 ,
enum V_6 V_7 ,
int V_65 )
{
struct V_66 * V_66 = V_2 -> V_10 -> V_66 ;
V_66 -> V_67 ++ ;
F_32 ( L_12 ,
V_65 , V_17 -> V_24 ) ;
if ( V_68 > 0 )
F_25 ( V_17 , V_39 ) ;
F_30 ( V_2 , V_17 ,
( V_7 == V_26 ) ?
V_33 : V_34 ) ;
if ( F_1 ( V_2 , V_17 , V_64 , V_7 ) != 0 )
return - V_25 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
enum V_6 V_7 )
{
struct V_11 * V_11 = & V_2 -> V_10 -> V_11 ;
struct V_69 * V_12 = V_11 -> V_12 ;
struct V_8 * V_39 = V_12 -> V_8 ;
struct V_3 * V_17 = & V_2 -> V_4 [ V_7 ] ;
struct V_70 * V_71 ;
int V_65 ;
int V_72 ;
int V_20 ;
struct V_13 * V_16 ;
V_71 = & V_2 -> V_73 [ V_7 ] ;
V_65 = F_23 ( V_17 , V_39 ) ;
if ( V_65 != V_17 -> V_19 ) {
V_72 = F_31 ( V_2 , V_39 , V_17 ,
& V_2 -> V_5 [ V_7 ] ,
V_7 , V_65 ) ;
if ( V_72 ) {
F_8 ( L_13 ) ;
return V_72 ;
}
V_17 = & V_2 -> V_5 [ V_7 ] ;
}
if ( V_17 -> V_19 == 1 ) {
V_16 = (struct V_13 * ) V_17 -> V_15 ;
V_71 -> V_74 . V_75 = V_12 -> V_76 -> V_75 ;
V_71 -> V_74 . V_77 = V_12 -> V_76 -> V_77 ;
V_71 -> V_74 . V_78 = F_3 ( V_39 , & V_16 [ 0 ] ) ;
V_71 -> V_74 . V_79 = F_20 ( V_39 , & V_16 [ 0 ] ) ;
F_22 ( L_14
L_15 ,
( unsigned int ) V_71 -> V_74 . V_75 ,
( unsigned int ) V_71 -> V_74 . V_77 ,
( unsigned long ) V_71 -> V_74 . V_79 ,
( unsigned long ) V_71 -> V_74 . V_78 ) ;
} else {
F_27 ( V_17 , V_11 -> V_80 . V_57 , V_39 ) ;
V_72 = F_34 ( V_11 , V_11 -> V_80 . V_57 ,
& V_71 -> V_74 ) ;
if ( V_72 && V_72 != - V_81 ) {
F_25 ( V_17 , V_39 ) ;
F_8 ( L_16 ,
V_17 -> V_19 ,
F_35 ( V_2 -> V_82 . V_83 . V_84 ) ) ;
F_8 ( L_17 ,
V_11 -> V_80 . V_57 -> V_41 ,
V_11 -> V_80 . V_57 -> V_30 ,
V_11 -> V_80 . V_57 -> V_29 ) ;
for ( V_20 = 0 ; V_20 < V_11 -> V_80 . V_57 -> V_30 ; V_20 ++ )
F_8 ( L_18 , V_20 ,
( unsigned long long ) V_11 -> V_80 . V_57 -> V_40 [ V_20 ] ) ;
}
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static void
F_36 ( struct V_85 * V_86 , struct V_87 * V_88 ,
struct V_89 * V_90 )
{
V_90 -> V_91 = V_92 ;
V_90 -> V_93 . V_94 . V_95 = F_37 ( V_86 ) ;
V_90 -> V_93 . V_94 . V_96 = F_38 ( V_86 ) ;
V_90 -> V_93 . V_94 . V_97 = 0xffff ;
V_90 -> V_93 . V_94 . V_98 = true ;
V_90 -> V_93 . V_94 . V_99 = true ;
if ( V_86 -> V_100 & V_101 )
V_90 -> V_93 . V_94 . V_102 = true ;
}
static int
F_39 ( struct V_85 * V_86 , struct V_87 * V_88 )
{
switch ( F_40 ( V_86 ) ) {
case V_103 :
case V_104 :
V_88 -> V_17 . V_91 = V_105 ;
F_36 ( V_86 , V_88 , & V_88 -> V_106 ) ;
V_88 -> V_106 . V_93 . V_94 . V_107 = V_108 ;
break;
case V_109 :
case V_110 :
V_88 -> V_106 . V_91 = V_105 ;
F_36 ( V_86 , V_88 , & V_88 -> V_17 ) ;
V_88 -> V_17 . V_93 . V_94 . V_107 = V_86 -> V_100 & V_111 ?
V_112 : V_108 ;
break;
case V_113 :
case V_114 :
F_36 ( V_86 , V_88 , & V_88 -> V_106 ) ;
V_88 -> V_106 . V_93 . V_94 . V_107 = V_108 ;
F_36 ( V_86 , V_88 , & V_88 -> V_17 ) ;
V_88 -> V_17 . V_93 . V_94 . V_107 = V_86 -> V_100 & V_111 ?
V_112 : V_108 ;
break;
default:
F_8 ( L_19 ,
F_40 ( V_86 ) ) ;
return - V_63 ;
}
return 0 ;
}
static inline void
F_41 ( struct V_85 * V_86 , T_2 * V_115 )
{
* V_115 = 0 ;
if ( V_86 -> V_100 & V_116 )
* V_115 |= V_117 ;
if ( V_86 -> V_100 & V_118 )
* V_115 |= V_119 ;
}
static void
F_42 ( struct V_120 * V_121 , struct V_122 * V_76 )
{
T_3 V_77 ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 . V_128 = V_76 -> V_77 ;
V_77 = F_43 ( V_76 -> V_77 ) ;
F_44 ( V_76 , V_77 ) ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_129 * V_82 , struct V_130 * V_131 ,
struct V_130 * V_132 , struct V_130 * V_133 )
{
struct V_11 * V_11 = & V_2 -> V_10 -> V_11 ;
struct V_134 * V_135 = V_82 -> V_135 ;
struct V_120 V_136 , V_121 ;
struct V_120 * V_137 , * V_138 = NULL ;
struct V_87 V_88 ;
int V_139 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_139 = F_39 ( V_2 -> V_86 , & V_88 ) ;
if ( V_139 )
goto V_72;
F_41 ( V_2 -> V_86 , & V_88 . V_140 ) ;
if ( ! ( V_82 -> V_141 & V_142 ) ) {
F_42 ( & V_121 , V_135 -> V_143 ) ;
V_138 = & V_121 ;
}
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_123 = V_144 ;
V_136 . V_125 = V_126 ;
V_136 . V_145 = V_131 ;
V_136 . V_146 = 1 ;
V_136 . V_138 . V_147 . V_88 = & V_88 ;
V_136 . V_138 . V_147 . V_143 = V_135 -> V_143 ;
if ( F_46 ( V_2 -> V_86 ) )
V_136 . V_138 . V_147 . V_148 = V_132 ;
V_136 . V_138 . V_147 . V_149 = V_150 |
V_151 |
V_152 ;
if ( ! V_138 )
V_138 = & V_136 ;
else
V_138 -> V_153 = & V_136 ;
V_139 = F_47 ( V_11 -> V_154 , V_138 , & V_137 ) ;
if ( V_139 ) {
F_8 ( L_20 , V_139 ) ;
goto V_72;
}
V_82 -> V_141 &= ~ V_142 ;
V_133 -> V_75 = V_135 -> V_143 -> V_75 ;
V_133 -> V_155 = 0 ;
V_133 -> V_30 = F_48 ( V_2 -> V_86 ) ;
F_22 ( L_21 ,
V_133 -> V_155 , V_133 -> V_30 ,
V_133 -> V_75 ) ;
V_72:
return V_139 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_3 * V_17 ,
enum V_156 V_157 ,
struct V_130 * V_158 )
{
struct V_129 * V_82 = V_71 -> V_74 . V_159 ;
struct V_11 * V_11 = & V_2 -> V_10 -> V_11 ;
struct V_69 * V_12 = V_11 -> V_12 ;
struct V_8 * V_39 = V_12 -> V_8 ;
struct V_122 * V_76 ;
struct V_160 * V_161 ;
struct V_120 V_162 , V_121 ;
struct V_120 * V_137 , * V_138 = NULL ;
int V_139 , V_29 , V_24 , V_163 ;
if ( V_17 -> V_19 == 1 ) {
struct V_13 * V_16 = (struct V_13 * ) V_17 -> V_15 ;
V_158 -> V_75 = V_12 -> V_76 -> V_75 ;
V_158 -> V_155 = F_20 ( V_39 , & V_16 [ 0 ] ) ;
V_158 -> V_30 = F_3 ( V_39 , & V_16 [ 0 ] ) ;
F_22 ( L_22 ,
V_158 -> V_75 , V_158 -> V_155 , V_158 -> V_30 ) ;
return 0 ;
}
if ( V_157 == V_164 ) {
V_76 = V_82 -> V_165 ;
V_161 = V_82 -> V_166 ;
} else {
V_76 = V_82 -> V_135 -> V_167 ;
V_161 = V_82 -> V_135 -> V_168 ;
}
V_163 = F_19 ( V_17 , V_12 -> V_8 , V_161 -> V_169 ,
& V_29 , & V_24 ) ;
if ( V_163 * V_52 < V_24 ) {
F_8 ( L_23 ) ;
return - V_63 ;
}
if ( ! ( V_82 -> V_141 & V_157 ) ) {
F_42 ( & V_121 , V_76 ) ;
V_138 = & V_121 ;
}
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_125 = V_126 ;
V_162 . V_123 = V_170 ;
V_162 . V_138 . V_171 . V_172 = V_161 -> V_169 [ 0 ] + V_29 ;
V_162 . V_138 . V_171 . V_169 = V_161 ;
V_162 . V_138 . V_171 . V_173 = V_163 ;
V_162 . V_138 . V_171 . V_174 = V_175 ;
V_162 . V_138 . V_171 . V_30 = V_24 ;
V_162 . V_138 . V_171 . V_77 = V_76 -> V_77 ;
V_162 . V_138 . V_171 . V_149 = ( V_150 |
V_152 |
V_151 ) ;
if ( ! V_138 )
V_138 = & V_162 ;
else
V_138 -> V_153 = & V_162 ;
V_139 = F_47 ( V_11 -> V_154 , V_138 , & V_137 ) ;
if ( V_139 ) {
F_8 ( L_24 , V_139 ) ;
return V_139 ;
}
V_82 -> V_141 &= ~ V_157 ;
V_158 -> V_75 = V_76 -> V_75 ;
V_158 -> V_155 = V_161 -> V_169 [ 0 ] + V_29 ;
V_158 -> V_30 = V_24 ;
return V_139 ;
}
int F_50 ( struct V_1 * V_2 ,
enum V_6 V_7 )
{
struct V_11 * V_11 = & V_2 -> V_10 -> V_11 ;
struct V_69 * V_12 = V_11 -> V_12 ;
struct V_8 * V_39 = V_12 -> V_8 ;
struct V_3 * V_17 = & V_2 -> V_4 [ V_7 ] ;
struct V_70 * V_71 = & V_2 -> V_73 [ V_7 ] ;
struct V_129 * V_82 = NULL ;
struct V_130 V_131 ;
int V_72 , V_65 ;
unsigned long V_176 ;
V_65 = F_23 ( V_17 , V_39 ) ;
if ( V_65 != V_17 -> V_19 ) {
V_72 = F_31 ( V_2 , V_39 , V_17 ,
& V_2 -> V_5 [ V_7 ] ,
V_7 , V_65 ) ;
if ( V_72 ) {
F_8 ( L_13 ) ;
return V_72 ;
}
V_17 = & V_2 -> V_5 [ V_7 ] ;
}
if ( V_17 -> V_19 != 1 ||
F_40 ( V_2 -> V_86 ) != V_177 ) {
F_51 ( & V_11 -> V_178 , V_176 ) ;
V_82 = F_52 ( & V_11 -> V_179 . V_180 ,
struct V_129 , V_181 ) ;
F_53 ( & V_82 -> V_181 ) ;
F_54 ( & V_11 -> V_178 , V_176 ) ;
V_71 -> V_74 . V_159 = V_82 ;
}
V_72 = F_49 ( V_2 , V_71 , V_17 ,
V_164 , & V_131 ) ;
if ( V_72 )
goto V_182;
if ( F_40 ( V_2 -> V_86 ) != V_177 ) {
struct V_130 V_132 , V_133 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
if ( F_46 ( V_2 -> V_86 ) ) {
V_17 = & V_2 -> V_148 [ V_7 ] ;
V_65 = F_23 ( V_17 , V_39 ) ;
if ( V_65 != V_17 -> V_19 ) {
V_72 = F_31 ( V_2 , V_39 , V_17 ,
& V_2 -> V_183 [ V_7 ] ,
V_7 , V_65 ) ;
if ( V_72 ) {
F_8 ( L_13 ) ;
return V_72 ;
}
V_17 = & V_2 -> V_183 [ V_7 ] ;
}
V_72 = F_49 ( V_2 , V_71 , V_17 ,
V_184 , & V_132 ) ;
if ( V_72 )
goto V_182;
}
V_72 = F_45 ( V_2 , V_82 , & V_131 ,
& V_132 , & V_133 ) ;
if ( V_72 ) {
F_8 ( L_25 ) ;
return V_72 ;
}
V_82 -> V_141 |= V_185 ;
V_71 -> V_74 . V_75 = V_133 . V_75 ;
V_71 -> V_74 . V_77 = V_82 -> V_135 -> V_143 -> V_77 ;
V_71 -> V_74 . V_79 = V_133 . V_155 ;
V_71 -> V_74 . V_78 = V_133 . V_30 ;
} else {
if ( V_82 )
V_71 -> V_74 . V_77 = V_82 -> V_165 -> V_77 ;
else
V_71 -> V_74 . V_77 = V_12 -> V_76 -> V_77 ;
V_71 -> V_74 . V_75 = V_131 . V_75 ;
V_71 -> V_74 . V_79 = V_131 . V_155 ;
V_71 -> V_74 . V_78 = V_131 . V_30 ;
}
return 0 ;
V_182:
if ( V_82 ) {
F_51 ( & V_11 -> V_178 , V_176 ) ;
F_55 ( & V_82 -> V_181 , & V_11 -> V_179 . V_180 ) ;
F_54 ( & V_11 -> V_178 , V_176 ) ;
}
return V_72 ;
}
