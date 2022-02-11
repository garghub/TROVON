static struct V_1 * F_1 ( T_1 V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_2 == V_2 )
return V_5 + V_3 ;
return V_5 ;
}
static inline struct V_6 * F_2 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , struct V_6 , V_9 ) ;
}
static void F_4 ( struct V_10 * V_11 , int V_12 ,
struct V_7 * V_13 )
{
V_13 -> V_14 . V_15 = V_11 -> V_16 . V_17 ;
V_13 -> V_14 . V_18 = V_11 -> V_19 [ V_12 ] ;
F_5 ( V_13 , 0 , V_11 -> V_16 . V_17 ) ;
F_6 ( V_13 , V_20 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
int V_3 ;
V_11 -> V_21 = - 1 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_22 ; V_3 ++ )
F_8 ( V_3 , & V_11 -> V_23 ) ;
}
static inline int F_9 ( struct V_10 * V_11 )
{
return F_10 ( V_24 , & V_11 -> V_23 ) ;
}
static void F_11 ( struct V_10 * V_11 , int V_25 )
{
if ( V_25 )
F_12 ( V_24 , & V_11 -> V_23 ) ;
else
F_8 ( V_24 , & V_11 -> V_23 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_14 ( V_11 , V_26 , V_27 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_16 ( V_11 , V_26 , V_27 ) ;
}
static int F_17 ( struct V_10 * V_11 , int V_28 )
{
int V_3 ;
F_11 ( V_11 , 1 ) ;
if ( V_28 )
V_11 -> V_29 = V_29 ;
else
V_11 -> V_29 = V_11 -> V_16 . V_17 ;
if ( V_30 > 3 )
V_30 = 3 ;
V_11 -> V_22 = 0 ;
for ( V_3 = 0 ; V_3 < V_30 ; V_3 ++ ) {
V_11 -> V_31 [ V_3 ] = F_18 ( V_11 -> V_32 ,
V_11 -> V_29 , V_11 -> V_33 + V_3 ,
V_34 ) ;
if ( V_11 -> V_31 [ V_3 ] == NULL ) {
F_19 ( V_11 , L_1 ) ;
break;
}
( V_11 -> V_22 ) ++ ;
}
switch ( V_11 -> V_22 ) {
case 1 :
F_20 ( V_11 -> V_32 , V_11 -> V_29 ,
V_11 -> V_31 [ 0 ] , V_11 -> V_33 [ 0 ] ) ;
V_11 -> V_22 = 0 ;
case 0 :
F_21 ( V_11 , L_2 ) ;
return - V_35 ;
case 2 :
if ( V_30 > 2 )
F_19 ( V_11 , L_3 ) ;
break;
}
return 0 ;
}
static void F_22 ( struct V_10 * V_11 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_22 ; V_3 ++ ) {
F_20 ( V_11 -> V_32 , V_11 -> V_29 ,
V_11 -> V_31 [ V_3 ] , V_11 -> V_33 [ V_3 ] ) ;
V_11 -> V_31 [ V_3 ] = NULL ;
}
V_11 -> V_22 = 0 ;
}
static void F_23 ( struct V_10 * V_11 )
{
F_24 ( V_11 , V_36 , V_11 -> V_33 [ 0 ] ) ;
F_24 ( V_11 , V_37 , V_11 -> V_33 [ 1 ] ) ;
if ( V_11 -> V_22 > 2 ) {
F_24 ( V_11 , V_38 , V_11 -> V_33 [ 2 ] ) ;
F_16 ( V_11 , V_39 , V_40 ) ;
} else
F_14 ( V_11 , V_39 , V_40 ) ;
if ( V_11 -> V_41 == V_42 )
F_24 ( V_11 , V_43 , 0 ) ;
}
static void F_25 ( unsigned long V_44 )
{
struct V_10 * V_11 = (struct V_10 * ) V_44 ;
int V_3 ;
unsigned long V_23 ;
struct V_6 * V_45 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_22 ; V_3 ++ ) {
int V_47 = V_11 -> V_21 ;
if ( V_11 -> V_48 != V_49 || V_47 < 0 )
break;
if ( ++ ( V_11 -> V_21 ) >= V_11 -> V_22 )
V_11 -> V_21 = 0 ;
if ( ! F_10 ( V_47 , & V_11 -> V_23 ) )
continue;
if ( F_27 ( & V_11 -> V_50 ) ) {
V_11 -> V_51 . V_52 ++ ;
break;
}
V_11 -> V_51 . V_53 ++ ;
F_8 ( V_47 , & V_11 -> V_23 ) ;
V_45 = F_28 ( & V_11 -> V_50 , struct V_6 ,
V_54 ) ;
F_29 ( & V_45 -> V_54 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
memcpy ( F_31 ( & V_45 -> V_9 , 0 ) , V_11 -> V_31 [ V_47 ] ,
V_11 -> V_16 . V_17 ) ;
F_4 ( V_11 , V_47 , & V_45 -> V_9 ) ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
}
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
if ( V_11 -> V_22 > 0 && V_11 -> V_29 < V_11 -> V_16 . V_17 )
F_22 ( V_11 ) ;
if ( V_11 -> V_22 == 0 )
return F_17 ( V_11 , 0 ) ;
return 0 ;
}
static void F_33 ( struct V_10 * V_11 , int V_12 )
{
F_34 ( & V_11 -> V_55 ) ;
}
static inline int F_17 ( struct V_10 * V_11 , int V_28 )
{
return 0 ;
}
static inline void F_22 ( struct V_10 * V_11 )
{
return;
}
static inline int F_32 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_35 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_45 ;
if ( F_27 ( & V_11 -> V_50 ) ) {
V_45 = V_11 -> V_56 [ V_12 ^ 0x1 ] ;
V_11 -> V_56 [ V_12 ] = V_45 ;
F_24 ( V_11 , V_12 == 0 ? V_36 : V_37 ,
F_36 ( & V_45 -> V_9 , 0 ) ) ;
F_12 ( V_57 , & V_11 -> V_23 ) ;
V_11 -> V_51 . V_52 ++ ;
return;
}
V_45 = F_28 ( & V_11 -> V_50 , struct V_6 , V_54 ) ;
F_29 ( & V_45 -> V_54 ) ;
F_24 ( V_11 , V_12 == 0 ? V_36 : V_37 ,
F_36 ( & V_45 -> V_9 , 0 ) ) ;
V_11 -> V_56 [ V_12 ] = V_45 ;
F_8 ( V_57 , & V_11 -> V_23 ) ;
}
static void F_37 ( struct V_10 * V_11 )
{
F_14 ( V_11 , V_39 , V_40 ) ;
V_11 -> V_22 = 2 ;
F_35 ( V_11 , 0 ) ;
F_35 ( V_11 , 1 ) ;
}
static void F_38 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_45 = V_11 -> V_56 [ V_12 ] ;
if ( ! F_10 ( V_57 , & V_11 -> V_23 ) ) {
V_11 -> V_51 . V_53 ++ ;
F_4 ( V_11 , V_12 , & V_45 -> V_9 ) ;
}
F_35 ( V_11 , V_12 ) ;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_6 * V_45 ;
V_45 = F_28 ( & V_11 -> V_50 , struct V_6 , V_54 ) ;
F_29 ( & V_45 -> V_54 ) ;
F_16 ( V_11 , V_39 , V_58 ) ;
F_24 ( V_11 , V_59 , V_45 -> V_60 ) ;
F_24 ( V_11 , V_61 ,
V_45 -> V_62 * sizeof( struct V_63 ) ) ;
F_24 ( V_11 , V_64 , 0 ) ;
F_24 ( V_11 , V_65 , 0 ) ;
F_14 ( V_11 , V_39 , V_58 ) ;
V_11 -> V_56 [ 0 ] = V_45 ;
}
static void F_40 ( struct V_10 * V_11 )
{
if ( F_27 ( & V_11 -> V_50 ) ) {
F_12 ( V_66 , & V_11 -> V_23 ) ;
return;
}
F_16 ( V_11 , V_39 , V_67 ) ;
F_39 ( V_11 ) ;
V_11 -> V_22 = 3 ;
}
static void F_41 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_45 = V_11 -> V_56 [ 0 ] ;
if ( V_11 -> V_48 != V_49 )
return;
if ( ! F_27 ( & V_11 -> V_50 ) ) {
F_39 ( V_11 ) ;
F_13 ( V_11 ) ;
} else {
F_12 ( V_66 , & V_11 -> V_23 ) ;
V_11 -> V_51 . V_52 ++ ;
V_11 -> V_56 [ 0 ] = NULL ;
}
V_11 -> V_51 . V_53 ++ ;
F_4 ( V_11 , V_12 , & V_45 -> V_9 ) ;
}
static void F_42 ( struct V_10 * V_11 )
{
F_40 ( V_11 ) ;
F_13 ( V_11 ) ;
F_8 ( V_66 , & V_11 -> V_23 ) ;
}
static inline void F_42 ( struct V_10 * V_11 )
{
return;
}
static void F_43 ( struct V_10 * V_11 )
{
int V_68 ;
struct V_69 * V_70 = & V_11 -> V_16 ;
V_68 = ( ( V_70 -> V_71 << V_72 ) & V_73 ) |
( V_70 -> V_74 & V_75 ) ;
F_24 ( V_11 , V_76 , V_68 ) ;
F_24 ( V_11 , V_77 , 0 ) ;
F_44 ( V_11 , V_78 , V_70 -> V_74 ,
V_79 ) ;
switch ( V_11 -> V_16 . V_2 ) {
case V_80 :
F_44 ( V_11 , V_26 ,
V_81 | V_82 | V_83 ,
V_84 ) ;
break;
case V_85 :
F_44 ( V_11 , V_26 ,
V_86 | V_87 | V_88 ,
V_84 ) ;
break;
case V_89 :
F_44 ( V_11 , V_26 ,
V_86 | V_90 | V_91 ,
V_84 ) ;
break;
default:
F_21 ( V_11 , L_4 , V_11 -> V_16 . V_2 ) ;
break;
}
F_44 ( V_11 , V_26 , V_92 ,
V_93 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_8 ( V_66 , & V_11 -> V_23 ) ;
V_11 -> V_94 ( V_11 ) ;
F_43 ( V_11 ) ;
F_11 ( V_11 , 0 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static void F_46 ( struct V_10 * V_11 )
{
F_24 ( V_11 , V_95 , V_96 ) ;
F_14 ( V_11 , V_97 , V_96 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
F_16 ( V_11 , V_97 , V_96 ) ;
}
static void F_48 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_16 ( V_11 , V_39 , V_98 ) ;
F_16 ( V_11 , V_26 , V_27 ) ;
F_44 ( V_11 , V_99 , 2 , V_100 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static void F_49 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_8 ( V_66 , & V_11 -> V_23 ) ;
F_15 ( V_11 ) ;
V_11 -> V_48 = V_101 ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
F_50 ( 150 ) ;
if ( F_10 ( V_102 , & V_11 -> V_23 ) )
F_21 ( V_11 , L_5 ) ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_47 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static void F_51 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
V_11 -> V_103 ( V_11 ) ;
F_16 ( V_11 , V_39 , V_98 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
F_50 ( 5 ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_14 ( V_11 , V_39 , V_98 ) ;
V_11 -> V_104 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static int F_53 ( struct V_10 * V_11 )
{
return F_54 ( V_11 , V_105 , V_106 , 0 ) ;
}
static int F_55 ( struct V_10 * V_11 )
{
struct V_107 V_108 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
if ( V_11 -> V_48 != V_111 )
F_19 ( V_11 , L_6 ,
V_11 -> V_48 ) ;
V_109 = F_53 ( V_11 ) ;
if ( V_109 )
goto V_112;
V_108 . V_113 = V_114 ;
V_108 . V_115 . type = V_116 ;
V_108 . V_115 . V_117 = V_11 -> V_118 ;
V_109 = F_54 ( V_11 , V_105 , V_119 , & V_108 ) ;
if ( V_109 )
goto V_112;
V_11 -> V_120 = V_108 . V_113 ;
if ( V_11 -> V_120 != V_121 ) {
F_21 ( V_11 , L_7 , V_11 -> V_120 ) ;
V_109 = - V_122 ;
goto V_112;
}
V_109 = 0 ;
V_11 -> V_48 = V_101 ;
V_112:
F_52 ( V_11 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_123 V_124 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_125 = V_126 ;
V_124 . V_127 = V_128 ;
return F_54 ( V_11 , V_105 , V_129 , & V_124 ) ;
}
static int F_59 ( struct V_10 * V_11 )
{
struct V_130 V_131 ;
int V_109 ;
F_60 ( & V_131 , & V_11 -> V_16 , V_11 -> V_132 ) ;
V_109 = F_54 ( V_11 , V_105 , V_133 , 0 ) ;
if ( V_109 == 0 )
V_109 = F_54 ( V_11 , V_134 , V_135 , & V_131 ) ;
V_109 += F_58 ( V_11 ) ;
return V_109 ;
}
static int F_61 ( struct V_10 * V_11 )
{
int V_109 ;
unsigned long V_23 ;
if ( V_11 -> V_136 == V_137 && V_11 -> V_22 == 0 &&
F_17 ( V_11 , 0 ) )
return - V_35 ;
if ( F_9 ( V_11 ) ) {
F_59 ( V_11 ) ;
V_109 = F_45 ( V_11 ) ;
if ( V_109 )
return V_109 ;
}
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_8 ( V_102 , & V_11 -> V_23 ) ;
F_7 ( V_11 ) ;
F_46 ( V_11 ) ;
V_11 -> V_48 = V_49 ;
if ( ! F_10 ( V_66 , & V_11 -> V_23 ) )
F_13 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static int F_62 ( struct V_138 * V_139 ,
const struct V_140 * V_70 , unsigned int * V_22 ,
unsigned int * V_141 , unsigned int V_142 [] ,
void * V_143 [] )
{
struct V_10 * V_11 = F_63 ( V_139 ) ;
int V_144 = ( V_11 -> V_136 == V_145 ) ? 3 : 2 ;
V_142 [ 0 ] = V_11 -> V_16 . V_17 ;
* V_141 = 1 ;
if ( * V_22 < V_144 )
* V_22 = V_144 ;
if ( V_11 -> V_136 == V_145 )
V_143 [ 0 ] = V_11 -> V_146 ;
return 0 ;
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_6 * V_147 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_138 ) ;
unsigned long V_23 ;
int V_148 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
V_148 = ( V_11 -> V_48 == V_149 ) && ! F_27 ( & V_11 -> V_50 ) ;
F_65 ( & V_147 -> V_54 , & V_11 -> V_50 ) ;
if ( V_11 -> V_48 == V_49 && F_10 ( V_66 , & V_11 -> V_23 ) )
F_42 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
if ( V_148 )
F_61 ( V_11 ) ;
}
static void F_66 ( struct V_138 * V_139 )
{
struct V_10 * V_11 = F_63 ( V_139 ) ;
F_57 ( & V_11 -> V_110 ) ;
}
static void F_67 ( struct V_138 * V_139 )
{
struct V_10 * V_11 = F_63 ( V_139 ) ;
F_56 ( & V_11 -> V_110 ) ;
}
static int F_68 ( struct V_138 * V_139 , unsigned int V_150 )
{
struct V_10 * V_11 = F_63 ( V_139 ) ;
if ( V_11 -> V_48 != V_101 ) {
F_69 ( & V_11 -> V_50 ) ;
return - V_122 ;
}
V_11 -> V_18 = 0 ;
if ( V_11 -> V_136 != V_137 && F_27 ( & V_11 -> V_50 ) ) {
V_11 -> V_48 = V_149 ;
return 0 ;
}
return F_61 ( V_11 ) ;
}
static int F_70 ( struct V_138 * V_139 )
{
struct V_10 * V_11 = F_63 ( V_139 ) ;
unsigned long V_23 ;
if ( V_11 -> V_48 == V_149 ) {
V_11 -> V_48 = V_101 ;
return 0 ;
}
if ( V_11 -> V_48 != V_49 )
return - V_122 ;
F_49 ( V_11 ) ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_69 ( & V_11 -> V_50 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_8 )
{
struct V_6 * V_147 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_138 ) ;
int V_151 = V_11 -> V_16 . V_17 / V_152 + 1 ;
V_147 -> V_153 = F_18 ( V_11 -> V_32 ,
V_151 * sizeof( struct V_63 ) ,
& V_147 -> V_60 , V_34 ) ;
if ( V_147 -> V_153 == NULL ) {
F_21 ( V_11 , L_8 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_8 )
{
struct V_6 * V_147 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_138 ) ;
struct V_154 * V_155 = F_73 ( V_8 , 0 ) ;
struct V_63 * V_156 = V_147 -> V_153 ;
struct V_157 * V_158 ;
int V_3 ;
V_147 -> V_62 = F_74 ( V_11 -> V_32 , V_155 -> V_159 , V_155 -> V_160 ,
V_161 ) ;
if ( V_147 -> V_62 <= 0 )
return - V_162 ;
F_75 (sgd->sglist, sg, mvb->dma_desc_nent, i) {
V_156 -> V_163 = F_76 ( V_158 ) ;
V_156 -> V_164 = F_77 ( V_158 ) ;
V_156 ++ ;
}
return 0 ;
}
static int F_78 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_63 ( V_8 -> V_138 ) ;
struct V_154 * V_155 = F_73 ( V_8 , 0 ) ;
F_79 ( V_11 -> V_32 , V_155 -> V_159 , V_155 -> V_160 , V_161 ) ;
return 0 ;
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_63 ( V_8 -> V_138 ) ;
struct V_6 * V_147 = F_2 ( V_8 ) ;
int V_151 = V_11 -> V_16 . V_17 / V_152 + 1 ;
F_20 ( V_11 -> V_32 , V_151 * sizeof( struct V_63 ) ,
V_147 -> V_153 , V_147 -> V_60 ) ;
}
static int F_81 ( struct V_10 * V_11 )
{
struct V_138 * V_139 = & V_11 -> V_165 ;
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
V_139 -> type = V_166 ;
V_139 -> V_167 = V_11 ;
F_69 ( & V_11 -> V_50 ) ;
switch ( V_11 -> V_136 ) {
case V_145 :
#ifdef F_82
V_139 -> V_168 = & V_169 ;
V_139 -> V_170 = & V_171 ;
V_11 -> V_146 = F_83 ( V_11 -> V_32 ) ;
V_139 -> V_172 = V_173 | V_174 ;
V_11 -> V_94 = F_37 ;
V_11 -> V_175 = F_38 ;
#endif
break;
case V_176 :
#ifdef F_84
V_139 -> V_168 = & V_177 ;
V_139 -> V_170 = & V_178 ;
V_139 -> V_172 = V_173 | V_174 ;
V_11 -> V_94 = F_40 ;
V_11 -> V_175 = F_41 ;
#endif
break;
case V_137 :
#ifdef F_85
F_86 ( & V_11 -> V_55 , F_25 ,
( unsigned long ) V_11 ) ;
V_139 -> V_168 = & V_169 ;
V_139 -> V_170 = & V_179 ;
V_139 -> V_180 = sizeof( struct V_6 ) ;
V_139 -> V_172 = V_173 ;
V_11 -> V_94 = F_23 ;
V_11 -> V_175 = F_33 ;
#endif
break;
}
return F_87 ( V_139 ) ;
}
static void F_88 ( struct V_10 * V_11 )
{
F_89 ( & V_11 -> V_165 ) ;
#ifdef F_82
if ( V_11 -> V_136 == V_145 )
F_90 ( V_11 -> V_146 ) ;
#endif
}
static int F_91 ( struct V_181 * V_182 , void * V_183 ,
enum V_184 type )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_92 ( & V_11 -> V_165 , type ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_93 ( struct V_181 * V_182 , void * V_183 ,
enum V_184 type )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_94 ( & V_11 -> V_165 , type ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_95 ( struct V_181 * V_182 , void * V_183 ,
struct V_186 * V_187 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_96 ( & V_11 -> V_165 , V_187 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_97 ( struct V_181 * V_182 , void * V_183 ,
struct V_188 * V_45 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_98 ( & V_11 -> V_165 , V_45 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_99 ( struct V_181 * V_182 , void * V_183 ,
struct V_188 * V_45 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_100 ( & V_11 -> V_165 , V_45 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_101 ( struct V_181 * V_182 , void * V_183 ,
struct V_188 * V_45 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_102 ( & V_11 -> V_165 , V_45 , V_182 -> V_189 & V_190 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_103 ( struct V_181 * V_181 , void * V_183 ,
struct V_191 * V_192 )
{
strcpy ( V_192 -> V_193 , L_9 ) ;
strcpy ( V_192 -> V_194 , L_9 ) ;
V_192 -> V_195 = 1 ;
V_192 -> V_196 = V_197 |
V_198 | V_199 ;
return 0 ;
}
static int F_104 ( struct V_181 * V_182 ,
void * V_183 , struct V_200 * V_70 )
{
if ( V_70 -> V_201 >= V_4 )
return - V_122 ;
F_105 ( V_70 -> V_202 , V_5 [ V_70 -> V_201 ] . V_156 ,
sizeof( V_70 -> V_202 ) ) ;
V_70 -> V_2 = V_5 [ V_70 -> V_201 ] . V_2 ;
return 0 ;
}
static int F_106 ( struct V_181 * V_182 , void * V_183 ,
struct V_140 * V_70 )
{
struct V_10 * V_11 = V_183 ;
struct V_1 * V_203 ;
struct V_69 * V_204 = & V_70 -> V_70 . V_204 ;
struct V_130 V_131 ;
int V_109 ;
V_203 = F_1 ( V_204 -> V_2 ) ;
V_204 -> V_2 = V_203 -> V_2 ;
F_60 ( & V_131 , V_204 , V_203 -> V_132 ) ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_54 ( V_11 , V_134 , V_205 , & V_131 ) ;
F_57 ( & V_11 -> V_110 ) ;
F_107 ( V_204 , & V_131 ) ;
V_204 -> V_74 = V_204 -> V_206 * V_203 -> V_207 ;
V_204 -> V_17 = V_204 -> V_71 * V_204 -> V_74 ;
return V_109 ;
}
static int F_108 ( struct V_181 * V_182 , void * V_183 ,
struct V_140 * V_70 )
{
struct V_10 * V_11 = V_183 ;
struct V_1 * V_203 ;
int V_109 ;
if ( V_11 -> V_48 != V_101 || V_11 -> V_165 . V_208 > 0 )
return - V_209 ;
V_203 = F_1 ( V_70 -> V_70 . V_204 . V_2 ) ;
V_109 = F_106 ( V_182 , V_183 , V_70 ) ;
if ( V_109 )
return V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_11 -> V_16 = V_70 -> V_70 . V_204 ;
V_11 -> V_132 = V_203 -> V_132 ;
if ( V_11 -> V_136 == V_137 ) {
V_109 = F_32 ( V_11 ) ;
if ( V_109 )
goto V_112;
}
F_11 ( V_11 , 1 ) ;
V_112:
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_109 ( struct V_181 * V_182 , void * V_183 ,
struct V_140 * V_203 )
{
struct V_10 * V_11 = V_183 ;
V_203 -> V_70 . V_204 = V_11 -> V_16 ;
return 0 ;
}
static int F_110 ( struct V_181 * V_182 , void * V_183 ,
struct V_210 * V_211 )
{
if ( V_211 -> V_201 != 0 )
return - V_122 ;
V_211 -> type = V_212 ;
V_211 -> V_213 = V_214 ;
strcpy ( V_211 -> V_215 , L_10 ) ;
return 0 ;
}
static int F_111 ( struct V_181 * V_182 , void * V_183 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_112 ( struct V_181 * V_182 , void * V_183 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_122 ;
return 0 ;
}
static int F_113 ( struct V_181 * V_182 , void * V_183 , T_2 V_216 )
{
return 0 ;
}
static int F_114 ( struct V_181 * V_182 , void * V_183 ,
struct V_217 * V_218 )
{
struct V_10 * V_11 = V_183 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_54 ( V_11 , V_134 , V_219 , V_218 ) ;
F_57 ( & V_11 -> V_110 ) ;
V_218 -> V_220 . V_221 . V_222 = V_30 ;
return V_109 ;
}
static int F_115 ( struct V_181 * V_182 , void * V_183 ,
struct V_217 * V_218 )
{
struct V_10 * V_11 = V_183 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_54 ( V_11 , V_134 , V_223 , V_218 ) ;
F_57 ( & V_11 -> V_110 ) ;
V_218 -> V_220 . V_221 . V_222 = V_30 ;
return V_109 ;
}
static int F_116 ( struct V_181 * V_181 , void * V_183 ,
struct V_107 * V_108 )
{
struct V_10 * V_11 = V_183 ;
V_108 -> V_113 = V_114 ;
V_108 -> V_224 = 0 ;
if ( F_117 ( & V_108 -> V_115 ) ) {
V_108 -> V_113 = V_11 -> V_41 ;
return 0 ;
}
return F_54 ( V_11 , V_105 , V_119 , V_108 ) ;
}
static int F_118 ( struct V_181 * V_182 , void * V_183 ,
struct V_225 * V_142 )
{
struct V_10 * V_11 = V_183 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_54 ( V_11 , V_134 , V_226 , V_142 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_119 ( struct V_181 * V_182 , void * V_183 ,
struct V_227 * V_228 )
{
struct V_10 * V_11 = V_183 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_54 ( V_11 , V_134 , V_229 , V_228 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_120 ( struct V_181 * V_181 , void * V_183 ,
struct V_230 * V_231 )
{
struct V_10 * V_11 = V_183 ;
if ( F_117 ( & V_231 -> V_115 ) ) {
V_231 -> V_232 = F_121 ( V_11 , V_231 -> V_231 ) ;
V_231 -> V_233 = 4 ;
return 0 ;
}
return F_54 ( V_11 , V_105 , V_234 , V_231 ) ;
}
static int F_122 ( struct V_181 * V_181 , void * V_183 ,
const struct V_230 * V_231 )
{
struct V_10 * V_11 = V_183 ;
if ( F_117 ( & V_231 -> V_115 ) ) {
F_24 ( V_11 , V_231 -> V_231 , V_231 -> V_232 ) ;
return 0 ;
}
return F_54 ( V_11 , V_105 , V_235 , V_231 ) ;
}
static int F_123 ( struct V_181 * V_182 )
{
struct V_10 * V_11 = F_124 ( V_182 ) ;
int V_109 = 0 ;
V_182 -> V_185 = V_11 ;
V_11 -> V_51 . V_236 = 0 ;
V_11 -> V_51 . V_52 = 0 ;
V_11 -> V_51 . V_53 = 0 ;
F_56 ( & V_11 -> V_110 ) ;
if ( V_11 -> V_237 == 0 ) {
V_109 = F_81 ( V_11 ) ;
if ( V_109 )
goto V_112;
F_51 ( V_11 ) ;
F_53 ( V_11 ) ;
F_11 ( V_11 , 1 ) ;
}
( V_11 -> V_237 ) ++ ;
V_112:
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_125 ( struct V_181 * V_182 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
F_126 ( V_11 , L_11 ,
V_11 -> V_51 . V_236 , V_11 -> V_51 . V_52 ,
V_11 -> V_51 . V_53 ) ;
F_56 ( & V_11 -> V_110 ) ;
( V_11 -> V_237 ) -- ;
if ( V_11 -> V_237 == 0 ) {
F_49 ( V_11 ) ;
F_88 ( V_11 ) ;
F_52 ( V_11 ) ;
if ( V_11 -> V_136 == V_137 && V_238 )
F_22 ( V_11 ) ;
}
F_57 ( & V_11 -> V_110 ) ;
return 0 ;
}
static T_3 F_127 ( struct V_181 * V_182 ,
char T_4 * V_239 , T_5 V_240 , T_6 * V_241 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_128 ( & V_11 -> V_165 , V_239 , V_240 , V_241 ,
V_182 -> V_189 & V_190 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static unsigned int F_129 ( struct V_181 * V_182 ,
struct V_242 * V_243 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_130 ( & V_11 -> V_165 , V_182 , V_243 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static int F_131 ( struct V_181 * V_182 , struct V_244 * V_245 )
{
struct V_10 * V_11 = V_182 -> V_185 ;
int V_109 ;
F_56 ( & V_11 -> V_110 ) ;
V_109 = F_132 ( & V_11 -> V_165 , V_245 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
}
static void F_133 ( struct V_10 * V_11 , int V_12 )
{
F_12 ( V_12 , & V_11 -> V_23 ) ;
F_8 ( V_102 , & V_11 -> V_23 ) ;
V_11 -> V_21 = V_12 ;
V_11 -> V_19 [ V_12 ] = ++ ( V_11 -> V_18 ) ;
V_11 -> V_51 . V_236 ++ ;
if ( V_11 -> V_48 != V_49 )
return;
V_11 -> V_175 ( V_11 , V_12 ) ;
}
int F_134 ( struct V_10 * V_11 , unsigned int V_246 )
{
unsigned int V_12 , V_247 = 0 ;
F_24 ( V_11 , V_95 , V_96 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
if ( V_246 & ( V_248 << V_12 ) ) {
F_133 ( V_11 , V_12 ) ;
V_247 = 1 ;
if ( V_11 -> V_136 == V_176 )
break;
}
if ( V_246 & ( V_249 | V_250 | V_251 ) ) {
F_12 ( V_102 , & V_11 -> V_23 ) ;
V_247 = 1 ;
if ( V_11 -> V_136 == V_176 )
F_15 ( V_11 ) ;
}
return V_247 ;
}
int F_135 ( struct V_10 * V_11 )
{
struct V_252 V_253 = {
. type = L_12 ,
. V_117 = 0x42 >> 1 ,
. V_254 = & V_255 ,
} ;
int V_109 ;
if ( V_136 >= 0 )
V_11 -> V_136 = V_136 ;
if ( V_11 -> V_136 == V_176 &&
V_11 -> V_41 == V_42 ) {
F_136 ( V_256 L_13
L_14 ) ;
V_11 -> V_136 = V_137 ;
}
if ( ! F_137 ( V_11 -> V_136 ) ) {
F_136 ( V_256 L_15 ,
V_11 -> V_136 ) ;
return - V_122 ;
}
V_109 = F_138 ( V_11 -> V_32 , & V_11 -> V_257 ) ;
if ( V_109 )
return V_109 ;
F_139 ( & V_11 -> V_110 ) ;
V_11 -> V_48 = V_111 ;
F_11 ( V_11 , 1 ) ;
V_11 -> V_16 = V_258 ;
V_11 -> V_132 = V_259 ;
F_69 ( & V_11 -> V_50 ) ;
F_48 ( V_11 ) ;
V_255 . V_260 = V_11 -> V_260 ;
V_255 . V_261 = V_11 -> V_261 ;
V_11 -> V_118 = V_253 . V_117 ;
V_11 -> V_262 = F_140 ( & V_11 -> V_257 ,
V_11 -> V_263 , & V_253 , NULL ) ;
if ( V_11 -> V_262 == NULL ) {
V_109 = - V_264 ;
goto V_265;
}
V_109 = F_55 ( V_11 ) ;
if ( V_109 )
goto V_265;
V_109 = F_141 ( & V_11 -> V_266 , 10 ) ;
if ( V_109 )
goto V_265;
V_11 -> V_257 . V_266 = & V_11 -> V_266 ;
F_56 ( & V_11 -> V_110 ) ;
V_11 -> V_267 = V_268 ;
V_11 -> V_267 . V_269 = 0 ;
V_11 -> V_267 . V_257 = & V_11 -> V_257 ;
F_142 ( & V_11 -> V_267 , V_11 ) ;
V_109 = F_143 ( & V_11 -> V_267 , V_270 , - 1 ) ;
if ( V_109 )
goto V_112;
if ( V_11 -> V_136 == V_137 && ! V_238 ) {
if ( F_17 ( V_11 , 1 ) )
F_19 ( V_11 , L_16
L_17 ) ;
}
V_112:
F_144 ( & V_11 -> V_266 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_109 ;
V_265:
F_145 ( & V_11 -> V_257 ) ;
return V_109 ;
}
void F_146 ( struct V_10 * V_11 )
{
if ( V_11 -> V_237 > 0 ) {
F_19 ( V_11 , L_18 ) ;
F_52 ( V_11 ) ;
}
F_89 ( & V_11 -> V_165 ) ;
if ( V_11 -> V_136 == V_137 )
F_22 ( V_11 ) ;
F_147 ( & V_11 -> V_267 ) ;
F_144 ( & V_11 -> V_266 ) ;
F_145 ( & V_11 -> V_257 ) ;
}
void F_148 ( struct V_10 * V_11 )
{
F_56 ( & V_11 -> V_110 ) ;
if ( V_11 -> V_237 > 0 ) {
enum V_271 V_272 = V_11 -> V_48 ;
F_49 ( V_11 ) ;
F_52 ( V_11 ) ;
V_11 -> V_48 = V_272 ;
}
F_57 ( & V_11 -> V_110 ) ;
}
int F_149 ( struct V_10 * V_11 )
{
int V_109 = 0 ;
F_56 ( & V_11 -> V_110 ) ;
if ( V_11 -> V_237 > 0 ) {
F_51 ( V_11 ) ;
F_53 ( V_11 ) ;
} else {
F_52 ( V_11 ) ;
}
F_57 ( & V_11 -> V_110 ) ;
F_12 ( V_24 , & V_11 -> V_23 ) ;
if ( V_11 -> V_48 == V_49 ) {
if ( V_11 -> V_136 == V_176 && V_11 -> V_56 [ 0 ] )
F_65 ( & V_11 -> V_56 [ 0 ] -> V_54 , & V_11 -> V_50 ) ;
V_109 = F_61 ( V_11 ) ;
}
return V_109 ;
}
