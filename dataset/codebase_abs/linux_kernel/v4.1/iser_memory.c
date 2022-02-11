static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 (data->sg, sg, data->size, count)
F_3 ( F_4 ( V_4 ) ) ;
F_5 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_2 -> V_6 ;
V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_6 = NULL ;
V_2 -> V_8 = 0 ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_9 * V_9 ;
unsigned long V_10 = V_2 -> V_11 ;
int V_12 = 0 , V_13 = F_7 ( V_10 , V_14 ) ;
V_4 = F_8 ( V_13 , sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
goto V_16;
F_9 ( V_4 , V_13 ) ;
while ( V_10 ) {
T_1 V_17 = F_10 ( T_1 , V_10 , V_14 ) ;
V_9 = F_11 ( V_15 ) ;
if ( ! V_9 )
goto V_16;
F_12 ( & V_4 [ V_12 ] , V_9 , V_17 , 0 ) ;
V_10 -= V_17 ;
V_12 ++ ;
}
V_2 -> V_6 = V_2 -> V_4 ;
V_2 -> V_8 = V_2 -> V_7 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = V_13 ;
return 0 ;
V_16:
for (; V_12 > 0 ; V_12 -- )
F_3 ( F_4 ( & V_4 [ V_12 - 1 ] ) ) ;
F_5 ( V_4 ) ;
return - V_18 ;
}
static void
F_13 ( struct V_1 * V_2 , bool V_19 )
{
struct V_3 * V_20 , * V_21 = V_2 -> V_4 ;
void * V_22 , * V_23 ;
unsigned int V_24 = V_2 -> V_11 ;
unsigned int V_25 = 0 ;
int V_12 ;
F_2 (data->orig_sg, osg, data->orig_size, i) {
unsigned int V_26 , V_27 = 0 ;
V_22 = F_14 ( F_4 ( V_20 ) ) + V_20 -> V_28 ;
V_26 = F_15 ( V_24 , V_20 -> V_10 ) ;
while ( V_26 ) {
unsigned int V_29 = F_15 ( V_26 , V_21 -> V_10 - V_25 ) ;
V_23 = F_14 ( F_4 ( V_21 ) ) + V_21 -> V_28 ;
if ( V_19 )
memcpy ( V_23 + V_25 , V_22 + V_27 , V_29 ) ;
else
memcpy ( V_22 + V_27 , V_23 + V_25 , V_29 ) ;
F_16 ( V_23 - V_21 -> V_28 ) ;
V_27 += V_29 ;
V_25 += V_29 ;
V_26 -= V_29 ;
if ( V_25 >= V_21 -> V_10 ) {
V_21 = F_17 ( V_21 ) ;
V_25 = 0 ;
}
}
F_16 ( V_22 - V_20 -> V_28 ) ;
V_24 -= V_27 ;
}
}
static inline void
F_18 ( struct V_1 * V_2 )
{
F_13 ( V_2 , false ) ;
}
static inline void
F_19 ( struct V_1 * V_2 )
{
F_13 ( V_2 , true ) ;
}
struct V_30 *
F_20 ( struct V_31 * V_31 )
{
struct V_30 * V_32 ;
unsigned long V_33 ;
F_21 ( & V_31 -> V_34 , V_33 ) ;
V_32 = F_22 ( & V_31 -> V_35 . V_36 ,
struct V_30 , V_37 ) ;
F_23 ( & V_32 -> V_37 ) ;
F_24 ( & V_31 -> V_34 , V_33 ) ;
return V_32 ;
}
void
F_25 ( struct V_31 * V_31 ,
struct V_30 * V_32 )
{
unsigned long V_33 ;
F_21 ( & V_31 -> V_34 , V_33 ) ;
F_26 ( & V_32 -> V_37 , & V_31 -> V_35 . V_36 ) ;
F_24 ( & V_31 -> V_34 , V_33 ) ;
}
static int F_27 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
enum V_40 V_41 )
{
struct V_42 * V_43 = V_39 -> V_44 -> V_31 . V_45 -> V_42 ;
int V_46 ;
V_46 = F_6 ( V_2 ) ;
if ( V_46 ) {
F_28 ( L_1 ,
V_2 -> V_11 ) ;
return V_46 ;
}
if ( V_41 == V_47 )
F_19 ( V_2 ) ;
V_2 -> V_48 = F_29 ( V_43 , V_2 -> V_4 , V_2 -> V_7 ,
( V_41 == V_47 ) ?
V_49 : V_50 ) ;
if ( ! V_2 -> V_48 ) {
F_28 ( L_2 ,
V_2 -> V_48 ) ;
V_46 = - V_18 ;
goto V_16;
}
return 0 ;
V_16:
F_1 ( V_2 ) ;
return V_46 ;
}
void F_30 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
enum V_40 V_41 )
{
struct V_42 * V_43 = V_39 -> V_44 -> V_31 . V_45 -> V_42 ;
F_31 ( V_43 , V_2 -> V_4 , V_2 -> V_7 ,
( V_41 == V_47 ) ?
V_49 : V_50 ) ;
if ( V_41 == V_51 )
F_18 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_42 * V_52 , T_2 * V_53 ,
int * V_28 , int * V_54 )
{
struct V_3 * V_4 , * V_55 = V_2 -> V_4 ;
T_2 V_56 , V_57 , V_9 , V_58 = 0 ;
unsigned long V_59 = 0 ;
unsigned int V_60 ;
int V_12 , V_61 , V_62 , V_63 = V_2 -> V_48 - 1 ;
* V_28 = ( T_2 ) V_55 [ 0 ] . V_28 & ~ V_64 ;
V_61 = 1 ;
V_62 = 0 ;
F_2 (sgl, sg, data->dma_nents, i) {
V_56 = F_33 ( V_52 , V_4 ) ;
if ( V_61 )
V_58 = V_56 ;
V_60 = F_34 ( V_52 , V_4 ) ;
V_57 = V_56 + V_60 ;
V_59 += V_60 ;
if ( ! F_35 ( V_57 ) && V_12 < V_63 ) {
V_61 = 0 ;
continue;
}
V_61 = 1 ;
V_9 = V_58 & V_64 ;
do {
V_53 [ V_62 ++ ] = V_9 ;
V_9 += V_65 ;
} while ( V_9 < V_57 );
}
* V_54 = V_59 ;
F_36 ( L_3 ,
* V_54 , V_62 ) ;
return V_62 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_42 * V_52 )
{
struct V_3 * V_4 , * V_55 , * V_66 = NULL ;
T_2 V_56 , V_57 ;
int V_12 , V_67 , V_68 = 0 ;
if ( V_2 -> V_48 == 1 )
return 1 ;
V_55 = V_2 -> V_4 ;
V_56 = F_33 ( V_52 , V_55 ) ;
F_2 (sgl, sg, data->dma_nents, i) {
if ( V_68 && ! F_35 ( V_56 ) )
break;
V_66 = F_17 ( V_4 ) ;
if ( ! V_66 )
break;
V_57 = V_56 + F_34 ( V_52 , V_4 ) ;
V_56 = F_33 ( V_52 , V_66 ) ;
if ( V_57 == V_56 ) {
V_68 = 0 ;
continue;
} else
V_68 = 1 ;
if ( ! F_35 ( V_57 ) )
break;
}
V_67 = ( V_66 ) ? V_12 : V_12 + 1 ;
F_36 ( L_4 ,
V_67 , V_2 -> V_48 , V_2 ) ;
return V_67 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_42 * V_52 )
{
struct V_3 * V_4 ;
int V_12 ;
F_2 (data->sg, sg, data->dma_nents, i)
F_36 ( L_5
L_6 ,
V_12 , ( unsigned long ) F_33 ( V_52 , V_4 ) ,
F_4 ( V_4 ) , V_4 -> V_28 ,
V_4 -> V_10 , F_34 ( V_52 , V_4 ) ) ;
}
static void F_39 ( struct V_69 * V_70 )
{
int V_12 ;
F_28 ( L_7 ,
V_70 -> V_10 , V_70 -> V_54 ) ;
for ( V_12 = 0 ; V_12 < V_70 -> V_10 ; V_12 ++ )
F_28 ( L_8 , V_12 , ( unsigned long ) V_70 -> V_53 [ V_12 ] ) ;
}
int F_40 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
enum V_40 V_71 ,
enum V_72 V_73 )
{
struct V_42 * V_43 ;
V_39 -> V_74 [ V_71 ] = 1 ;
V_43 = V_39 -> V_44 -> V_31 . V_45 -> V_42 ;
V_2 -> V_48 = F_29 ( V_43 , V_2 -> V_4 , V_2 -> V_7 , V_73 ) ;
if ( V_2 -> V_48 == 0 ) {
F_28 ( L_9 ) ;
return - V_75 ;
}
return 0 ;
}
void F_41 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
enum V_72 V_74 )
{
struct V_42 * V_43 ;
V_43 = V_39 -> V_44 -> V_31 . V_45 -> V_42 ;
F_31 ( V_43 , V_2 -> V_4 , V_2 -> V_7 , V_74 ) ;
}
static int
F_42 ( struct V_76 * V_45 , struct V_1 * V_77 ,
struct V_78 * V_79 )
{
struct V_3 * V_4 = V_77 -> V_4 ;
V_79 -> V_80 . V_81 = V_45 -> V_82 -> V_81 ;
V_79 -> V_83 = V_45 -> V_82 -> V_83 ;
V_79 -> V_80 . V_84 = F_33 ( V_45 -> V_42 , & V_4 [ 0 ] ) ;
V_79 -> V_80 . V_10 = F_34 ( V_45 -> V_42 , & V_4 [ 0 ] ) ;
F_36 ( L_10
L_11 , V_79 -> V_80 . V_81 , V_79 -> V_83 ,
V_79 -> V_80 . V_84 , V_79 -> V_80 . V_10 ) ;
return 0 ;
}
static int F_43 ( struct V_38 * V_39 ,
struct V_1 * V_77 ,
enum V_40 V_41 ,
int V_85 )
{
struct V_86 * V_86 = V_39 -> V_44 -> V_86 ;
struct V_76 * V_45 = V_39 -> V_44 -> V_31 . V_45 ;
V_86 -> V_87 ++ ;
F_44 ( L_12 ,
V_85 , V_77 -> V_7 ) ;
if ( V_88 > 0 )
F_38 ( V_77 , V_45 -> V_42 ) ;
F_41 ( V_39 , V_77 ,
( V_41 == V_47 ) ?
V_49 : V_50 ) ;
if ( F_27 ( V_39 , V_77 , V_41 ) != 0 )
return - V_18 ;
return 0 ;
}
static
int F_45 ( struct V_38 * V_39 ,
struct V_1 * V_77 ,
struct V_69 * V_70 ,
struct V_78 * V_89 )
{
struct V_31 * V_31 = & V_39 -> V_44 -> V_31 ;
struct V_76 * V_45 = V_31 -> V_45 ;
struct V_90 * V_91 ;
int V_92 , V_93 ;
V_93 = F_32 ( V_77 , V_45 -> V_42 ,
V_70 -> V_53 ,
& V_70 -> V_28 ,
& V_70 -> V_54 ) ;
V_70 -> V_10 = V_93 ;
if ( V_93 * V_65 < V_70 -> V_54 ) {
F_28 ( L_13 ) ;
F_38 ( V_77 , V_45 -> V_42 ) ;
F_39 ( V_70 ) ;
return - V_75 ;
}
V_91 = F_46 ( V_31 -> V_91 . V_36 ,
V_70 -> V_53 ,
V_70 -> V_10 ,
V_70 -> V_53 [ 0 ] ) ;
if ( F_47 ( V_91 ) ) {
V_92 = F_48 ( V_91 ) ;
F_28 ( L_14 , V_92 ) ;
return V_92 ;
}
V_89 -> V_80 . V_81 = V_91 -> V_91 -> V_81 ;
V_89 -> V_83 = V_91 -> V_91 -> V_83 ;
V_89 -> V_80 . V_84 = V_70 -> V_53 [ 0 ] + V_70 -> V_28 ;
V_89 -> V_80 . V_10 = V_70 -> V_54 ;
V_89 -> V_94 = V_91 ;
return 0 ;
}
void F_49 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
struct V_78 * V_79 = & V_39 -> V_95 [ V_41 ] ;
int V_92 ;
if ( ! V_79 -> V_94 )
return;
F_36 ( L_15 , V_79 -> V_94 ) ;
V_92 = F_50 ( (struct V_90 * ) V_79 -> V_94 ) ;
if ( V_92 )
F_28 ( L_16 , V_92 ) ;
V_79 -> V_94 = NULL ;
}
void F_51 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
struct V_78 * V_79 = & V_39 -> V_95 [ V_41 ] ;
if ( ! V_79 -> V_94 )
return;
F_25 ( & V_39 -> V_44 -> V_31 ,
V_79 -> V_94 ) ;
V_79 -> V_94 = NULL ;
}
int F_52 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
struct V_31 * V_31 = & V_39 -> V_44 -> V_31 ;
struct V_76 * V_45 = V_31 -> V_45 ;
struct V_42 * V_52 = V_45 -> V_42 ;
struct V_1 * V_77 = & V_39 -> V_2 [ V_41 ] ;
struct V_78 * V_89 ;
int V_85 ;
int V_16 ;
int V_12 ;
V_89 = & V_39 -> V_95 [ V_41 ] ;
V_85 = F_37 ( V_77 , V_52 ) ;
if ( V_85 != V_77 -> V_48 ) {
V_16 = F_43 ( V_39 , V_77 ,
V_41 , V_85 ) ;
if ( V_16 ) {
F_28 ( L_17 ) ;
return V_16 ;
}
}
if ( V_77 -> V_48 == 1 ) {
return F_42 ( V_45 , V_77 , V_89 ) ;
} else {
V_16 = F_45 ( V_39 , V_77 , V_31 -> V_91 . V_70 ,
V_89 ) ;
if ( V_16 && V_16 != - V_96 ) {
F_38 ( V_77 , V_52 ) ;
F_28 ( L_18 ,
V_77 -> V_48 ,
F_53 ( V_39 -> V_32 . V_97 . V_98 ) ) ;
F_28 ( L_19 ,
V_31 -> V_91 . V_70 -> V_54 ,
V_31 -> V_91 . V_70 -> V_10 ,
V_31 -> V_91 . V_70 -> V_28 ) ;
for ( V_12 = 0 ; V_12 < V_31 -> V_91 . V_70 -> V_10 ; V_12 ++ )
F_28 ( L_20 , V_12 ,
( unsigned long long ) V_31 -> V_91 . V_70 -> V_53 [ V_12 ] ) ;
}
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static void
F_54 ( struct V_99 * V_100 , struct V_101 * V_102 ,
struct V_103 * V_104 )
{
V_104 -> V_105 = V_106 ;
V_104 -> V_107 . V_108 . V_109 = F_55 ( V_100 ) ;
V_104 -> V_107 . V_108 . V_110 = F_56 ( V_100 ) ;
V_104 -> V_107 . V_108 . V_111 = 0xffff ;
V_104 -> V_107 . V_108 . V_112 = true ;
V_104 -> V_107 . V_108 . V_113 = true ;
if ( V_100 -> V_114 & V_115 )
V_104 -> V_107 . V_108 . V_116 = true ;
}
static int
F_57 ( struct V_99 * V_100 , struct V_101 * V_102 )
{
switch ( F_58 ( V_100 ) ) {
case V_117 :
case V_118 :
V_102 -> V_77 . V_105 = V_119 ;
F_54 ( V_100 , V_102 , & V_102 -> V_120 ) ;
V_102 -> V_120 . V_107 . V_108 . V_121 = V_122 ;
break;
case V_123 :
case V_124 :
V_102 -> V_120 . V_105 = V_119 ;
F_54 ( V_100 , V_102 , & V_102 -> V_77 ) ;
V_102 -> V_77 . V_107 . V_108 . V_121 = V_100 -> V_114 & V_125 ?
V_126 : V_122 ;
break;
case V_127 :
case V_128 :
F_54 ( V_100 , V_102 , & V_102 -> V_120 ) ;
V_102 -> V_120 . V_107 . V_108 . V_121 = V_122 ;
F_54 ( V_100 , V_102 , & V_102 -> V_77 ) ;
V_102 -> V_77 . V_107 . V_108 . V_121 = V_100 -> V_114 & V_125 ?
V_126 : V_122 ;
break;
default:
F_28 ( L_21 ,
F_58 ( V_100 ) ) ;
return - V_75 ;
}
return 0 ;
}
static inline void
F_59 ( struct V_99 * V_100 , T_3 * V_129 )
{
* V_129 = 0 ;
if ( V_100 -> V_114 & V_130 )
* V_129 |= V_131 ;
if ( V_100 -> V_114 & V_132 )
* V_129 |= V_133 ;
}
static void
F_60 ( struct V_134 * V_135 , struct V_136 * V_82 )
{
T_1 V_83 ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_135 -> V_137 = V_138 ;
V_135 -> V_139 = V_140 ;
V_135 -> V_141 . V_142 = V_82 -> V_83 ;
V_83 = F_61 ( V_82 -> V_83 ) ;
F_62 ( V_82 , V_83 ) ;
}
static int
F_63 ( struct V_38 * V_39 ,
struct V_30 * V_32 ,
struct V_78 * V_143 ,
struct V_78 * V_144 ,
struct V_78 * V_145 )
{
struct V_31 * V_31 = & V_39 -> V_44 -> V_31 ;
struct V_146 * V_147 = V_32 -> V_147 ;
struct V_134 V_148 , V_135 ;
struct V_134 * V_149 , * V_150 = NULL ;
struct V_101 V_102 ;
int V_92 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_92 = F_57 ( V_39 -> V_100 , & V_102 ) ;
if ( V_92 )
goto V_16;
F_59 ( V_39 -> V_100 , & V_102 . V_151 ) ;
if ( ! ( V_32 -> V_152 & V_153 ) ) {
F_60 ( & V_135 , V_147 -> V_154 ) ;
V_150 = & V_135 ;
}
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_137 = V_155 ;
V_148 . V_139 = V_140 ;
V_148 . V_156 = & V_143 -> V_80 ;
V_148 . V_157 = 1 ;
V_148 . V_150 . V_158 . V_102 = & V_102 ;
V_148 . V_150 . V_158 . V_154 = V_147 -> V_154 ;
if ( F_64 ( V_39 -> V_100 ) )
V_148 . V_150 . V_158 . V_159 = & V_144 -> V_80 ;
V_148 . V_150 . V_158 . V_160 = V_161 |
V_162 |
V_163 ;
if ( ! V_150 )
V_150 = & V_148 ;
else
V_150 -> V_164 = & V_148 ;
V_92 = F_65 ( V_31 -> V_165 , V_150 , & V_149 ) ;
if ( V_92 ) {
F_28 ( L_22 , V_92 ) ;
goto V_16;
}
V_32 -> V_152 &= ~ V_153 ;
V_145 -> V_80 . V_81 = V_147 -> V_154 -> V_81 ;
V_145 -> V_83 = V_147 -> V_154 -> V_83 ;
V_145 -> V_80 . V_84 = 0 ;
V_145 -> V_80 . V_10 = F_66 ( V_39 -> V_100 ) ;
F_36 ( L_23 ,
V_145 -> V_80 . V_81 , V_145 -> V_83 , V_145 -> V_80 . V_84 ,
V_145 -> V_80 . V_10 ) ;
V_16:
return V_92 ;
}
static int F_67 ( struct V_38 * V_39 ,
struct V_1 * V_77 ,
struct V_30 * V_32 ,
enum V_166 V_167 ,
struct V_78 * V_79 )
{
struct V_31 * V_31 = & V_39 -> V_44 -> V_31 ;
struct V_76 * V_45 = V_31 -> V_45 ;
struct V_136 * V_82 ;
struct V_168 * V_169 ;
struct V_134 V_170 , V_135 ;
struct V_134 * V_149 , * V_150 = NULL ;
int V_92 , V_28 , V_7 , V_93 ;
if ( V_77 -> V_48 == 1 )
return F_42 ( V_45 , V_77 , V_79 ) ;
if ( V_167 == V_171 ) {
V_82 = V_32 -> V_172 ;
V_169 = V_32 -> V_173 ;
} else {
V_82 = V_32 -> V_147 -> V_174 ;
V_169 = V_32 -> V_147 -> V_175 ;
}
V_93 = F_32 ( V_77 , V_45 -> V_42 , V_169 -> V_176 ,
& V_28 , & V_7 ) ;
if ( V_93 * V_65 < V_7 ) {
F_28 ( L_24 ) ;
return - V_75 ;
}
if ( ! ( V_32 -> V_152 & V_167 ) ) {
F_60 ( & V_135 , V_82 ) ;
V_150 = & V_135 ;
}
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_139 = V_140 ;
V_170 . V_137 = V_177 ;
V_170 . V_150 . V_178 . V_179 = V_169 -> V_176 [ 0 ] + V_28 ;
V_170 . V_150 . V_178 . V_176 = V_169 ;
V_170 . V_150 . V_178 . V_180 = V_93 ;
V_170 . V_150 . V_178 . V_181 = V_182 ;
V_170 . V_150 . V_178 . V_10 = V_7 ;
V_170 . V_150 . V_178 . V_83 = V_82 -> V_83 ;
V_170 . V_150 . V_178 . V_160 = ( V_161 |
V_163 |
V_162 ) ;
if ( ! V_150 )
V_150 = & V_170 ;
else
V_150 -> V_164 = & V_170 ;
V_92 = F_65 ( V_31 -> V_165 , V_150 , & V_149 ) ;
if ( V_92 ) {
F_28 ( L_25 , V_92 ) ;
return V_92 ;
}
V_32 -> V_152 &= ~ V_167 ;
V_79 -> V_80 . V_81 = V_82 -> V_81 ;
V_79 -> V_83 = V_82 -> V_83 ;
V_79 -> V_80 . V_84 = V_169 -> V_176 [ 0 ] + V_28 ;
V_79 -> V_80 . V_10 = V_7 ;
return V_92 ;
}
int F_68 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
struct V_31 * V_31 = & V_39 -> V_44 -> V_31 ;
struct V_76 * V_45 = V_31 -> V_45 ;
struct V_42 * V_52 = V_45 -> V_42 ;
struct V_1 * V_77 = & V_39 -> V_2 [ V_41 ] ;
struct V_78 * V_89 = & V_39 -> V_95 [ V_41 ] ;
struct V_30 * V_32 = NULL ;
int V_16 , V_85 ;
V_85 = F_37 ( V_77 , V_52 ) ;
if ( V_85 != V_77 -> V_48 ) {
V_16 = F_43 ( V_39 , V_77 ,
V_41 , V_85 ) ;
if ( V_16 ) {
F_28 ( L_17 ) ;
return V_16 ;
}
}
if ( V_77 -> V_48 != 1 ||
F_58 ( V_39 -> V_100 ) != V_183 ) {
V_32 = F_20 ( V_31 ) ;
V_89 -> V_94 = V_32 ;
}
V_16 = F_67 ( V_39 , V_77 , V_32 ,
V_171 , V_89 ) ;
if ( V_16 )
goto V_184;
if ( F_58 ( V_39 -> V_100 ) != V_183 ) {
struct V_78 V_144 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
if ( F_64 ( V_39 -> V_100 ) ) {
V_77 = & V_39 -> V_159 [ V_41 ] ;
V_85 = F_37 ( V_77 , V_52 ) ;
if ( V_85 != V_77 -> V_48 ) {
V_16 = F_43 ( V_39 , V_77 ,
V_41 , V_85 ) ;
if ( V_16 ) {
F_28 ( L_17 ) ;
return V_16 ;
}
}
V_16 = F_67 ( V_39 , V_77 , V_32 ,
V_185 , & V_144 ) ;
if ( V_16 )
goto V_184;
}
V_16 = F_63 ( V_39 , V_32 , V_89 ,
& V_144 , V_89 ) ;
if ( V_16 ) {
F_28 ( L_26 ) ;
return V_16 ;
}
V_32 -> V_152 |= V_186 ;
}
return 0 ;
V_184:
if ( V_32 )
F_25 ( V_31 , V_32 ) ;
return V_16 ;
}
