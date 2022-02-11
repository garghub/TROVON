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
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
if ( V_11 -> V_48 != V_109 )
F_19 ( V_11 , L_6 ,
V_11 -> V_48 ) ;
V_107 = F_53 ( V_11 ) ;
V_11 -> V_48 = V_101 ;
F_52 ( V_11 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_110 V_111 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_112 = V_113 ;
V_111 . V_114 = V_115 ;
return F_54 ( V_11 , V_105 , V_116 , & V_111 ) ;
}
static int F_59 ( struct V_10 * V_11 )
{
struct V_117 V_118 ;
int V_107 ;
F_60 ( & V_118 , & V_11 -> V_16 , V_11 -> V_119 ) ;
V_107 = F_54 ( V_11 , V_105 , V_120 , 0 ) ;
if ( V_107 == 0 )
V_107 = F_54 ( V_11 , V_121 , V_122 , & V_118 ) ;
V_107 += F_58 ( V_11 ) ;
return V_107 ;
}
static int F_61 ( struct V_10 * V_11 )
{
int V_107 ;
unsigned long V_23 ;
if ( V_11 -> V_123 == V_124 && V_11 -> V_22 == 0 &&
F_17 ( V_11 , 0 ) )
return - V_35 ;
if ( F_9 ( V_11 ) ) {
F_59 ( V_11 ) ;
V_107 = F_45 ( V_11 ) ;
if ( V_107 )
return V_107 ;
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
static int F_62 ( struct V_125 * V_126 ,
const struct V_127 * V_70 , unsigned int * V_22 ,
unsigned int * V_128 , unsigned int V_129 [] ,
void * V_130 [] )
{
struct V_10 * V_11 = F_63 ( V_126 ) ;
int V_131 = ( V_11 -> V_123 == V_132 ) ? 3 : 2 ;
V_129 [ 0 ] = V_11 -> V_16 . V_17 ;
* V_128 = 1 ;
if ( * V_22 < V_131 )
* V_22 = V_131 ;
if ( V_11 -> V_123 == V_132 )
V_130 [ 0 ] = V_11 -> V_133 ;
return 0 ;
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_6 * V_134 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_125 ) ;
unsigned long V_23 ;
int V_135 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
V_135 = ( V_11 -> V_48 == V_136 ) && ! F_27 ( & V_11 -> V_50 ) ;
F_65 ( & V_134 -> V_54 , & V_11 -> V_50 ) ;
if ( V_11 -> V_48 == V_49 && F_10 ( V_66 , & V_11 -> V_23 ) )
F_42 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
if ( V_135 )
F_61 ( V_11 ) ;
}
static void F_66 ( struct V_125 * V_126 )
{
struct V_10 * V_11 = F_63 ( V_126 ) ;
F_57 ( & V_11 -> V_108 ) ;
}
static void F_67 ( struct V_125 * V_126 )
{
struct V_10 * V_11 = F_63 ( V_126 ) ;
F_56 ( & V_11 -> V_108 ) ;
}
static int F_68 ( struct V_125 * V_126 , unsigned int V_137 )
{
struct V_10 * V_11 = F_63 ( V_126 ) ;
if ( V_11 -> V_48 != V_101 ) {
F_69 ( & V_11 -> V_50 ) ;
return - V_138 ;
}
V_11 -> V_18 = 0 ;
if ( V_11 -> V_123 != V_124 && F_27 ( & V_11 -> V_50 ) ) {
V_11 -> V_48 = V_136 ;
return 0 ;
}
return F_61 ( V_11 ) ;
}
static int F_70 ( struct V_125 * V_126 )
{
struct V_10 * V_11 = F_63 ( V_126 ) ;
unsigned long V_23 ;
if ( V_11 -> V_48 == V_136 ) {
V_11 -> V_48 = V_101 ;
return 0 ;
}
if ( V_11 -> V_48 != V_49 )
return - V_138 ;
F_49 ( V_11 ) ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_69 ( & V_11 -> V_50 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_8 )
{
struct V_6 * V_134 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_125 ) ;
int V_139 = V_11 -> V_16 . V_17 / V_140 + 1 ;
V_134 -> V_141 = F_18 ( V_11 -> V_32 ,
V_139 * sizeof( struct V_63 ) ,
& V_134 -> V_60 , V_34 ) ;
if ( V_134 -> V_141 == NULL ) {
F_21 ( V_11 , L_7 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_8 )
{
struct V_6 * V_134 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_125 ) ;
struct V_142 * V_143 = F_73 ( V_8 , 0 ) ;
struct V_63 * V_144 = V_134 -> V_141 ;
struct V_145 * V_146 ;
int V_3 ;
V_134 -> V_62 = F_74 ( V_11 -> V_32 , V_143 -> V_147 , V_143 -> V_148 ,
V_149 ) ;
if ( V_134 -> V_62 <= 0 )
return - V_150 ;
F_75 (sgd->sglist, sg, mvb->dma_desc_nent, i) {
V_144 -> V_151 = F_76 ( V_146 ) ;
V_144 -> V_152 = F_77 ( V_146 ) ;
V_144 ++ ;
}
return 0 ;
}
static int F_78 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_63 ( V_8 -> V_125 ) ;
struct V_142 * V_143 = F_73 ( V_8 , 0 ) ;
F_79 ( V_11 -> V_32 , V_143 -> V_147 , V_143 -> V_148 , V_149 ) ;
return 0 ;
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_63 ( V_8 -> V_125 ) ;
struct V_6 * V_134 = F_2 ( V_8 ) ;
int V_139 = V_11 -> V_16 . V_17 / V_140 + 1 ;
F_20 ( V_11 -> V_32 , V_139 * sizeof( struct V_63 ) ,
V_134 -> V_141 , V_134 -> V_60 ) ;
}
static int F_81 ( struct V_10 * V_11 )
{
struct V_125 * V_126 = & V_11 -> V_153 ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> type = V_154 ;
V_126 -> V_155 = V_11 ;
F_69 ( & V_11 -> V_50 ) ;
switch ( V_11 -> V_123 ) {
case V_132 :
#ifdef F_82
V_126 -> V_156 = & V_157 ;
V_126 -> V_158 = & V_159 ;
V_11 -> V_133 = F_83 ( V_11 -> V_32 ) ;
V_126 -> V_160 = V_161 | V_162 ;
V_11 -> V_94 = F_37 ;
V_11 -> V_163 = F_38 ;
#endif
break;
case V_164 :
#ifdef F_84
V_126 -> V_156 = & V_165 ;
V_126 -> V_158 = & V_166 ;
V_126 -> V_160 = V_161 | V_162 ;
V_11 -> V_94 = F_40 ;
V_11 -> V_163 = F_41 ;
#endif
break;
case V_124 :
#ifdef F_85
F_86 ( & V_11 -> V_55 , F_25 ,
( unsigned long ) V_11 ) ;
V_126 -> V_156 = & V_157 ;
V_126 -> V_158 = & V_167 ;
V_126 -> V_168 = sizeof( struct V_6 ) ;
V_126 -> V_160 = V_161 ;
V_11 -> V_94 = F_23 ;
V_11 -> V_163 = F_33 ;
#endif
break;
}
return F_87 ( V_126 ) ;
}
static void F_88 ( struct V_10 * V_11 )
{
F_89 ( & V_11 -> V_153 ) ;
#ifdef F_82
if ( V_11 -> V_123 == V_132 )
F_90 ( V_11 -> V_133 ) ;
#endif
}
static int F_91 ( struct V_169 * V_170 , void * V_171 ,
enum V_172 type )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_92 ( & V_11 -> V_153 , type ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_93 ( struct V_169 * V_170 , void * V_171 ,
enum V_172 type )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_94 ( & V_11 -> V_153 , type ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_95 ( struct V_169 * V_170 , void * V_171 ,
struct V_174 * V_175 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_96 ( & V_11 -> V_153 , V_175 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_97 ( struct V_169 * V_170 , void * V_171 ,
struct V_176 * V_45 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_98 ( & V_11 -> V_153 , V_45 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_99 ( struct V_169 * V_170 , void * V_171 ,
struct V_176 * V_45 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_100 ( & V_11 -> V_153 , V_45 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_101 ( struct V_169 * V_170 , void * V_171 ,
struct V_176 * V_45 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_102 ( & V_11 -> V_153 , V_45 , V_170 -> V_177 & V_178 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_103 ( struct V_169 * V_169 , void * V_171 ,
struct V_179 * V_180 )
{
strcpy ( V_180 -> V_181 , L_8 ) ;
strcpy ( V_180 -> V_182 , L_8 ) ;
V_180 -> V_183 = 1 ;
V_180 -> V_184 = V_185 |
V_186 | V_187 ;
return 0 ;
}
static int F_104 ( struct V_169 * V_170 ,
void * V_171 , struct V_188 * V_70 )
{
if ( V_70 -> V_189 >= V_4 )
return - V_138 ;
F_105 ( V_70 -> V_190 , V_5 [ V_70 -> V_189 ] . V_144 ,
sizeof( V_70 -> V_190 ) ) ;
V_70 -> V_2 = V_5 [ V_70 -> V_189 ] . V_2 ;
return 0 ;
}
static int F_106 ( struct V_169 * V_170 , void * V_171 ,
struct V_127 * V_70 )
{
struct V_10 * V_11 = V_171 ;
struct V_1 * V_191 ;
struct V_69 * V_192 = & V_70 -> V_70 . V_192 ;
struct V_117 V_118 ;
int V_107 ;
V_191 = F_1 ( V_192 -> V_2 ) ;
V_192 -> V_2 = V_191 -> V_2 ;
F_60 ( & V_118 , V_192 , V_191 -> V_119 ) ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_54 ( V_11 , V_121 , V_193 , & V_118 ) ;
F_57 ( & V_11 -> V_108 ) ;
F_107 ( V_192 , & V_118 ) ;
V_192 -> V_74 = V_192 -> V_194 * V_191 -> V_195 ;
V_192 -> V_17 = V_192 -> V_71 * V_192 -> V_74 ;
return V_107 ;
}
static int F_108 ( struct V_169 * V_170 , void * V_171 ,
struct V_127 * V_70 )
{
struct V_10 * V_11 = V_171 ;
struct V_1 * V_191 ;
int V_107 ;
if ( V_11 -> V_48 != V_101 || V_11 -> V_153 . V_196 > 0 )
return - V_197 ;
V_191 = F_1 ( V_70 -> V_70 . V_192 . V_2 ) ;
V_107 = F_106 ( V_170 , V_171 , V_70 ) ;
if ( V_107 )
return V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_11 -> V_16 = V_70 -> V_70 . V_192 ;
V_11 -> V_119 = V_191 -> V_119 ;
if ( V_11 -> V_123 == V_124 ) {
V_107 = F_32 ( V_11 ) ;
if ( V_107 )
goto V_198;
}
F_11 ( V_11 , 1 ) ;
V_198:
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_109 ( struct V_169 * V_170 , void * V_171 ,
struct V_127 * V_191 )
{
struct V_10 * V_11 = V_171 ;
V_191 -> V_70 . V_192 = V_11 -> V_16 ;
return 0 ;
}
static int F_110 ( struct V_169 * V_170 , void * V_171 ,
struct V_199 * V_200 )
{
if ( V_200 -> V_189 != 0 )
return - V_138 ;
V_200 -> type = V_201 ;
V_200 -> V_202 = V_203 ;
strcpy ( V_200 -> V_204 , L_9 ) ;
return 0 ;
}
static int F_111 ( struct V_169 * V_170 , void * V_171 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_112 ( struct V_169 * V_170 , void * V_171 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_138 ;
return 0 ;
}
static int F_113 ( struct V_169 * V_170 , void * V_171 , T_2 V_205 )
{
return 0 ;
}
static int F_114 ( struct V_169 * V_170 , void * V_171 , T_2 * V_205 )
{
* V_205 = V_206 ;
return 0 ;
}
static int F_115 ( struct V_169 * V_170 , void * V_171 ,
struct V_207 * V_208 )
{
struct V_10 * V_11 = V_171 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_54 ( V_11 , V_121 , V_209 , V_208 ) ;
F_57 ( & V_11 -> V_108 ) ;
V_208 -> V_210 . V_211 . V_212 = V_30 ;
return V_107 ;
}
static int F_116 ( struct V_169 * V_170 , void * V_171 ,
struct V_207 * V_208 )
{
struct V_10 * V_11 = V_171 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_54 ( V_11 , V_121 , V_213 , V_208 ) ;
F_57 ( & V_11 -> V_108 ) ;
V_208 -> V_210 . V_211 . V_212 = V_30 ;
return V_107 ;
}
static int F_117 ( struct V_169 * V_170 , void * V_171 ,
struct V_214 * V_129 )
{
struct V_10 * V_11 = V_171 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_54 ( V_11 , V_121 , V_215 , V_129 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_118 ( struct V_169 * V_170 , void * V_171 ,
struct V_216 * V_217 )
{
struct V_10 * V_11 = V_171 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_54 ( V_11 , V_121 , V_218 , V_217 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_119 ( struct V_169 * V_169 , void * V_171 ,
struct V_219 * V_220 )
{
struct V_10 * V_11 = V_171 ;
if ( V_220 -> V_220 > V_11 -> V_221 - 4 )
return - V_138 ;
V_220 -> V_222 = F_120 ( V_11 , V_220 -> V_220 ) ;
V_220 -> V_223 = 4 ;
return 0 ;
}
static int F_121 ( struct V_169 * V_169 , void * V_171 ,
const struct V_219 * V_220 )
{
struct V_10 * V_11 = V_171 ;
if ( V_220 -> V_220 > V_11 -> V_221 - 4 )
return - V_138 ;
F_24 ( V_11 , V_220 -> V_220 , V_220 -> V_222 ) ;
return 0 ;
}
static int F_122 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = F_123 ( V_170 ) ;
int V_107 = 0 ;
V_170 -> V_173 = V_11 ;
V_11 -> V_51 . V_224 = 0 ;
V_11 -> V_51 . V_52 = 0 ;
V_11 -> V_51 . V_53 = 0 ;
F_56 ( & V_11 -> V_108 ) ;
if ( V_11 -> V_225 == 0 ) {
V_107 = F_81 ( V_11 ) ;
if ( V_107 )
goto V_198;
F_51 ( V_11 ) ;
F_53 ( V_11 ) ;
F_11 ( V_11 , 1 ) ;
}
( V_11 -> V_225 ) ++ ;
V_198:
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_124 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
F_125 ( V_11 , L_10 ,
V_11 -> V_51 . V_224 , V_11 -> V_51 . V_52 ,
V_11 -> V_51 . V_53 ) ;
F_56 ( & V_11 -> V_108 ) ;
( V_11 -> V_225 ) -- ;
if ( V_11 -> V_225 == 0 ) {
F_49 ( V_11 ) ;
F_88 ( V_11 ) ;
F_52 ( V_11 ) ;
if ( V_11 -> V_123 == V_124 && V_226 )
F_22 ( V_11 ) ;
}
F_57 ( & V_11 -> V_108 ) ;
return 0 ;
}
static T_3 F_126 ( struct V_169 * V_170 ,
char T_4 * V_227 , T_5 V_228 , T_6 * V_229 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_127 ( & V_11 -> V_153 , V_227 , V_228 , V_229 ,
V_170 -> V_177 & V_178 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static unsigned int F_128 ( struct V_169 * V_170 ,
struct V_230 * V_231 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_129 ( & V_11 -> V_153 , V_170 , V_231 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static int F_130 ( struct V_169 * V_170 , struct V_232 * V_233 )
{
struct V_10 * V_11 = V_170 -> V_173 ;
int V_107 ;
F_56 ( & V_11 -> V_108 ) ;
V_107 = F_131 ( & V_11 -> V_153 , V_233 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
}
static void F_132 ( struct V_10 * V_11 , int V_12 )
{
F_12 ( V_12 , & V_11 -> V_23 ) ;
F_8 ( V_102 , & V_11 -> V_23 ) ;
V_11 -> V_21 = V_12 ;
V_11 -> V_19 [ V_12 ] = ++ ( V_11 -> V_18 ) ;
V_11 -> V_51 . V_224 ++ ;
if ( V_11 -> V_48 != V_49 )
return;
V_11 -> V_163 ( V_11 , V_12 ) ;
}
int F_133 ( struct V_10 * V_11 , unsigned int V_234 )
{
unsigned int V_12 , V_235 = 0 ;
F_24 ( V_11 , V_95 , V_96 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
if ( V_234 & ( V_236 << V_12 ) ) {
F_132 ( V_11 , V_12 ) ;
V_235 = 1 ;
if ( V_11 -> V_123 == V_164 )
break;
}
if ( V_234 & ( V_237 | V_238 | V_239 ) ) {
F_12 ( V_102 , & V_11 -> V_23 ) ;
V_235 = 1 ;
if ( V_11 -> V_123 == V_164 )
F_15 ( V_11 ) ;
}
return V_235 ;
}
int F_134 ( struct V_10 * V_11 )
{
struct V_240 V_241 = {
. type = L_11 ,
. V_242 = 0x42 >> 1 ,
. V_243 = & V_244 ,
} ;
int V_107 ;
if ( V_123 >= 0 )
V_11 -> V_123 = V_123 ;
if ( V_11 -> V_123 == V_164 &&
V_11 -> V_41 == V_42 ) {
F_135 ( V_245 L_12
L_13 ) ;
V_11 -> V_123 = V_124 ;
}
if ( ! F_136 ( V_11 -> V_123 ) ) {
F_135 ( V_245 L_14 ,
V_11 -> V_123 ) ;
return - V_138 ;
}
V_107 = F_137 ( V_11 -> V_32 , & V_11 -> V_246 ) ;
if ( V_107 )
return V_107 ;
F_138 ( & V_11 -> V_108 ) ;
V_11 -> V_48 = V_109 ;
F_11 ( V_11 , 1 ) ;
V_11 -> V_16 = V_247 ;
V_11 -> V_119 = V_248 ;
F_69 ( & V_11 -> V_50 ) ;
F_48 ( V_11 ) ;
V_244 . V_249 = V_11 -> V_249 ;
V_244 . V_250 = V_11 -> V_250 ;
V_11 -> V_251 = V_241 . V_242 ;
V_11 -> V_252 = F_139 ( & V_11 -> V_246 ,
V_11 -> V_253 , & V_241 , NULL ) ;
if ( V_11 -> V_252 == NULL ) {
V_107 = - V_254 ;
goto V_255;
}
V_107 = F_55 ( V_11 ) ;
if ( V_107 )
goto V_255;
V_107 = F_140 ( & V_11 -> V_256 , 10 ) ;
if ( V_107 )
goto V_255;
V_11 -> V_246 . V_256 = & V_11 -> V_256 ;
F_56 ( & V_11 -> V_108 ) ;
V_11 -> V_257 = V_258 ;
V_11 -> V_257 . V_259 = 0 ;
V_11 -> V_257 . V_246 = & V_11 -> V_246 ;
F_141 ( & V_11 -> V_257 , V_11 ) ;
V_107 = F_142 ( & V_11 -> V_257 , V_260 , - 1 ) ;
if ( V_107 )
goto V_198;
if ( V_11 -> V_123 == V_124 && ! V_226 ) {
if ( F_17 ( V_11 , 1 ) )
F_19 ( V_11 , L_15
L_16 ) ;
}
V_198:
F_143 ( & V_11 -> V_256 ) ;
F_57 ( & V_11 -> V_108 ) ;
return V_107 ;
V_255:
F_144 ( & V_11 -> V_246 ) ;
return V_107 ;
}
void F_145 ( struct V_10 * V_11 )
{
if ( V_11 -> V_225 > 0 ) {
F_19 ( V_11 , L_17 ) ;
F_52 ( V_11 ) ;
}
F_89 ( & V_11 -> V_153 ) ;
if ( V_11 -> V_123 == V_124 )
F_22 ( V_11 ) ;
F_146 ( & V_11 -> V_257 ) ;
F_143 ( & V_11 -> V_256 ) ;
F_144 ( & V_11 -> V_246 ) ;
}
void F_147 ( struct V_10 * V_11 )
{
F_56 ( & V_11 -> V_108 ) ;
if ( V_11 -> V_225 > 0 ) {
enum V_261 V_262 = V_11 -> V_48 ;
F_49 ( V_11 ) ;
F_52 ( V_11 ) ;
V_11 -> V_48 = V_262 ;
}
F_57 ( & V_11 -> V_108 ) ;
}
int F_148 ( struct V_10 * V_11 )
{
int V_107 = 0 ;
F_56 ( & V_11 -> V_108 ) ;
if ( V_11 -> V_225 > 0 ) {
F_51 ( V_11 ) ;
F_53 ( V_11 ) ;
} else {
F_52 ( V_11 ) ;
}
F_57 ( & V_11 -> V_108 ) ;
F_12 ( V_24 , & V_11 -> V_23 ) ;
if ( V_11 -> V_48 == V_49 ) {
if ( V_11 -> V_123 == V_164 && V_11 -> V_56 [ 0 ] )
F_65 ( & V_11 -> V_56 [ 0 ] -> V_54 , & V_11 -> V_50 ) ;
V_107 = F_61 ( V_11 ) ;
}
return V_107 ;
}
