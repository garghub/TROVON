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
V_51 ++ ;
break;
}
V_52 ++ ;
F_8 ( V_47 , & V_11 -> V_23 ) ;
V_45 = F_28 ( & V_11 -> V_50 , struct V_6 ,
V_53 ) ;
F_29 ( & V_45 -> V_53 ) ;
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
F_34 ( & V_11 -> V_54 ) ;
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
V_45 = V_11 -> V_55 [ V_12 ^ 0x1 ] ;
V_11 -> V_55 [ V_12 ] = V_45 ;
F_24 ( V_11 , V_12 == 0 ? V_36 : V_37 ,
F_36 ( & V_45 -> V_9 , 0 ) ) ;
F_12 ( V_56 , & V_11 -> V_23 ) ;
V_51 ++ ;
return;
}
V_45 = F_28 ( & V_11 -> V_50 , struct V_6 , V_53 ) ;
F_29 ( & V_45 -> V_53 ) ;
F_24 ( V_11 , V_12 == 0 ? V_36 : V_37 ,
F_36 ( & V_45 -> V_9 , 0 ) ) ;
V_11 -> V_55 [ V_12 ] = V_45 ;
F_8 ( V_56 , & V_11 -> V_23 ) ;
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
struct V_6 * V_45 = V_11 -> V_55 [ V_12 ] ;
if ( ! F_10 ( V_56 , & V_11 -> V_23 ) ) {
V_52 ++ ;
F_4 ( V_11 , V_12 , & V_45 -> V_9 ) ;
}
F_35 ( V_11 , V_12 ) ;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_6 * V_45 ;
V_45 = F_28 ( & V_11 -> V_50 , struct V_6 , V_53 ) ;
F_29 ( & V_45 -> V_53 ) ;
F_24 ( V_11 , V_57 , V_45 -> V_58 ) ;
F_24 ( V_11 , V_59 ,
V_45 -> V_60 * sizeof( struct V_61 ) ) ;
F_24 ( V_11 , V_62 , 0 ) ;
F_24 ( V_11 , V_63 , 0 ) ;
V_11 -> V_55 [ 0 ] = V_45 ;
}
static void F_40 ( struct V_10 * V_11 )
{
F_16 ( V_11 , V_39 , V_64 ) ;
F_39 ( V_11 ) ;
F_14 ( V_11 , V_39 , V_65 ) ;
V_11 -> V_22 = 3 ;
}
static void F_41 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_45 = V_11 -> V_55 [ 0 ] ;
F_16 ( V_11 , V_39 , V_65 ) ;
if ( ! F_27 ( & V_11 -> V_50 ) ) {
F_39 ( V_11 ) ;
F_14 ( V_11 , V_39 , V_65 ) ;
F_13 ( V_11 ) ;
} else {
F_12 ( V_66 , & V_11 -> V_23 ) ;
V_51 ++ ;
}
V_52 ++ ;
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
int V_67 ;
struct V_68 * V_69 = & V_11 -> V_16 ;
V_67 = ( ( V_69 -> V_70 << V_71 ) & V_72 ) |
( V_69 -> V_73 & V_74 ) ;
F_24 ( V_11 , V_75 , V_67 ) ;
F_24 ( V_11 , V_76 , 0 ) ;
F_44 ( V_11 , V_77 , V_69 -> V_73 ,
V_78 ) ;
switch ( V_11 -> V_16 . V_2 ) {
case V_79 :
F_44 ( V_11 , V_26 ,
V_80 | V_81 | V_82 ,
V_83 ) ;
break;
case V_84 :
F_44 ( V_11 , V_26 ,
V_85 | V_86 | V_87 ,
V_83 ) ;
break;
case V_88 :
F_44 ( V_11 , V_26 ,
V_85 | V_89 | V_90 ,
V_83 ) ;
break;
default:
F_21 ( V_11 , L_4 , V_11 -> V_16 . V_2 ) ;
break;
}
F_44 ( V_11 , V_26 , V_91 ,
V_92 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
V_11 -> V_93 ( V_11 ) ;
F_43 ( V_11 ) ;
F_11 ( V_11 , 0 ) ;
F_8 ( V_66 , & V_11 -> V_23 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static void F_46 ( struct V_10 * V_11 )
{
F_24 ( V_11 , V_94 , V_95 ) ;
F_14 ( V_11 , V_96 , V_95 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
F_16 ( V_11 , V_96 , V_95 ) ;
}
static void F_48 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_16 ( V_11 , V_39 , V_97 ) ;
F_16 ( V_11 , V_26 , V_27 ) ;
F_44 ( V_11 , V_98 , 2 , V_99 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static void F_49 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_8 ( V_66 , & V_11 -> V_23 ) ;
F_15 ( V_11 ) ;
V_11 -> V_48 = V_100 ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
F_50 ( 40 ) ;
if ( F_10 ( V_101 , & V_11 -> V_23 ) )
F_21 ( V_11 , L_5 ) ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_47 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static void F_51 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
V_11 -> V_102 ( V_11 ) ;
F_16 ( V_11 , V_39 , V_97 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
F_50 ( 5 ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_14 ( V_11 , V_39 , V_97 ) ;
V_11 -> V_103 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
}
static int F_53 ( struct V_10 * V_11 )
{
return F_54 ( V_11 , V_104 , V_105 , 0 ) ;
}
static int F_55 ( struct V_10 * V_11 )
{
struct V_106 V_107 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
if ( V_11 -> V_48 != V_110 )
F_19 ( V_11 , L_6 ,
V_11 -> V_48 ) ;
V_108 = F_53 ( V_11 ) ;
if ( V_108 )
goto V_111;
V_107 . V_112 = V_113 ;
V_107 . V_114 . type = V_115 ;
V_107 . V_114 . V_116 = V_11 -> V_117 ;
V_108 = F_54 ( V_11 , V_104 , V_118 , & V_107 ) ;
if ( V_108 )
goto V_111;
V_11 -> V_119 = V_107 . V_112 ;
if ( V_11 -> V_119 != V_120 ) {
F_21 ( V_11 , L_7 , V_11 -> V_119 ) ;
V_108 = - V_121 ;
goto V_111;
}
V_108 = 0 ;
V_11 -> V_48 = V_100 ;
V_111:
F_52 ( V_11 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_122 V_123 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_124 = V_125 ;
V_123 . V_126 = V_127 ;
return F_54 ( V_11 , V_104 , V_128 , & V_123 ) ;
}
static int F_59 ( struct V_10 * V_11 )
{
struct V_129 V_130 ;
int V_108 ;
F_60 ( & V_130 , & V_11 -> V_16 , V_11 -> V_131 ) ;
V_108 = F_54 ( V_11 , V_104 , V_132 , 0 ) ;
if ( V_108 == 0 )
V_108 = F_54 ( V_11 , V_133 , V_134 , & V_130 ) ;
V_108 += F_58 ( V_11 ) ;
return V_108 ;
}
static int F_61 ( struct V_10 * V_11 )
{
int V_108 ;
unsigned long V_23 ;
if ( V_11 -> V_135 == V_136 && V_11 -> V_22 == 0 &&
F_17 ( V_11 , 0 ) )
return - V_35 ;
if ( F_9 ( V_11 ) ) {
F_59 ( V_11 ) ;
V_108 = F_45 ( V_11 ) ;
if ( V_108 )
return V_108 ;
}
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_7 ( V_11 ) ;
F_46 ( V_11 ) ;
V_11 -> V_48 = V_49 ;
F_13 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static int F_62 ( struct V_137 * V_138 , unsigned int * V_22 ,
unsigned int * V_139 , unsigned long V_140 [] ,
void * V_141 [] )
{
struct V_10 * V_11 = F_63 ( V_138 ) ;
int V_142 = ( V_11 -> V_135 == V_143 ) ? 3 : 2 ;
V_140 [ 0 ] = V_11 -> V_16 . V_17 ;
* V_139 = 1 ;
if ( * V_22 < V_142 )
* V_22 = V_142 ;
if ( V_11 -> V_135 == V_143 )
V_141 [ 0 ] = V_11 -> V_144 ;
return 0 ;
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_6 * V_145 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_137 ) ;
unsigned long V_23 ;
int V_146 ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
V_146 = ( V_11 -> V_48 == V_147 ) && ! F_27 ( & V_11 -> V_50 ) ;
F_65 ( & V_145 -> V_53 , & V_11 -> V_50 ) ;
if ( F_10 ( V_66 , & V_11 -> V_23 ) )
F_42 ( V_11 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
if ( V_146 )
F_61 ( V_11 ) ;
}
static void F_66 ( struct V_137 * V_138 )
{
struct V_10 * V_11 = F_63 ( V_138 ) ;
F_57 ( & V_11 -> V_109 ) ;
}
static void F_67 ( struct V_137 * V_138 )
{
struct V_10 * V_11 = F_63 ( V_138 ) ;
F_56 ( & V_11 -> V_109 ) ;
}
static int F_68 ( struct V_137 * V_138 )
{
struct V_10 * V_11 = F_63 ( V_138 ) ;
if ( V_11 -> V_48 != V_100 )
return - V_121 ;
V_11 -> V_18 = 0 ;
if ( V_11 -> V_135 != V_136 && F_27 ( & V_11 -> V_50 ) ) {
V_11 -> V_48 = V_147 ;
return 0 ;
}
return F_61 ( V_11 ) ;
}
static int F_69 ( struct V_137 * V_138 )
{
struct V_10 * V_11 = F_63 ( V_138 ) ;
unsigned long V_23 ;
if ( V_11 -> V_48 == V_147 ) {
V_11 -> V_48 = V_100 ;
return 0 ;
}
if ( V_11 -> V_48 != V_49 )
return - V_121 ;
F_49 ( V_11 ) ;
F_26 ( & V_11 -> V_46 , V_23 ) ;
F_70 ( & V_11 -> V_50 ) ;
F_30 ( & V_11 -> V_46 , V_23 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_8 )
{
struct V_6 * V_145 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_137 ) ;
int V_148 = V_11 -> V_16 . V_17 / V_149 + 1 ;
V_145 -> V_150 = F_18 ( V_11 -> V_32 ,
V_148 * sizeof( struct V_61 ) ,
& V_145 -> V_58 , V_34 ) ;
if ( V_145 -> V_150 == NULL ) {
F_21 ( V_11 , L_8 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_8 )
{
struct V_6 * V_145 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_63 ( V_8 -> V_137 ) ;
struct V_151 * V_152 = F_73 ( V_8 , 0 ) ;
struct V_61 * V_153 = V_145 -> V_150 ;
struct V_154 * V_155 ;
int V_3 ;
V_145 -> V_60 = F_74 ( V_11 -> V_32 , V_152 -> V_156 , V_152 -> V_157 ,
V_158 ) ;
if ( V_145 -> V_60 <= 0 )
return - V_159 ;
F_75 (sgd->sglist, sg, mvb->dma_desc_nent, i) {
V_153 -> V_160 = F_76 ( V_155 ) ;
V_153 -> V_161 = F_77 ( V_155 ) ;
V_153 ++ ;
}
return 0 ;
}
static int F_78 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_63 ( V_8 -> V_137 ) ;
struct V_151 * V_152 = F_73 ( V_8 , 0 ) ;
F_79 ( V_11 -> V_32 , V_152 -> V_156 , V_152 -> V_157 , V_158 ) ;
return 0 ;
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_63 ( V_8 -> V_137 ) ;
struct V_6 * V_145 = F_2 ( V_8 ) ;
int V_148 = V_11 -> V_16 . V_17 / V_149 + 1 ;
F_20 ( V_11 -> V_32 , V_148 * sizeof( struct V_61 ) ,
V_145 -> V_150 , V_145 -> V_58 ) ;
}
static int F_81 ( struct V_10 * V_11 )
{
struct V_137 * V_138 = & V_11 -> V_162 ;
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
V_138 -> type = V_163 ;
V_138 -> V_164 = V_11 ;
F_70 ( & V_11 -> V_50 ) ;
switch ( V_11 -> V_135 ) {
case V_143 :
#ifdef F_82
V_138 -> V_165 = & V_166 ;
V_138 -> V_167 = & V_168 ;
V_11 -> V_144 = F_83 ( V_11 -> V_32 ) ;
V_138 -> V_169 = V_170 | V_171 ;
V_11 -> V_93 = F_37 ;
V_11 -> V_172 = F_38 ;
#endif
break;
case V_173 :
#ifdef F_84
V_138 -> V_165 = & V_174 ;
V_138 -> V_167 = & V_175 ;
V_138 -> V_169 = V_170 | V_171 ;
V_11 -> V_93 = F_40 ;
V_11 -> V_172 = F_41 ;
#endif
break;
case V_136 :
#ifdef F_85
F_86 ( & V_11 -> V_54 , F_25 ,
( unsigned long ) V_11 ) ;
V_138 -> V_165 = & V_166 ;
V_138 -> V_167 = & V_176 ;
V_138 -> V_177 = sizeof( struct V_6 ) ;
V_138 -> V_169 = V_170 ;
V_11 -> V_93 = F_23 ;
V_11 -> V_172 = F_33 ;
#endif
break;
}
return F_87 ( V_138 ) ;
}
static void F_88 ( struct V_10 * V_11 )
{
F_89 ( & V_11 -> V_162 ) ;
#ifdef F_82
if ( V_11 -> V_135 == V_143 )
F_90 ( V_11 -> V_144 ) ;
#endif
}
static int F_91 ( struct V_178 * V_179 , void * V_180 ,
enum V_181 type )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_92 ( & V_11 -> V_162 , type ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_93 ( struct V_178 * V_179 , void * V_180 ,
enum V_181 type )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_94 ( & V_11 -> V_162 , type ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_95 ( struct V_178 * V_179 , void * V_180 ,
struct V_183 * V_184 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_96 ( & V_11 -> V_162 , V_184 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_97 ( struct V_178 * V_179 , void * V_180 ,
struct V_185 * V_45 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_98 ( & V_11 -> V_162 , V_45 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_99 ( struct V_178 * V_179 , void * V_180 ,
struct V_185 * V_45 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_100 ( & V_11 -> V_162 , V_45 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_101 ( struct V_178 * V_179 , void * V_180 ,
struct V_185 * V_45 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_102 ( & V_11 -> V_162 , V_45 , V_179 -> V_186 & V_187 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_103 ( struct V_178 * V_179 , void * V_180 ,
struct V_188 * V_189 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_104 , V_190 , V_189 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_104 ( struct V_178 * V_179 , void * V_180 ,
struct V_122 * V_123 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_104 , V_191 , V_123 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_105 ( struct V_178 * V_179 , void * V_180 ,
struct V_122 * V_123 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_104 , V_128 , V_123 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_106 ( struct V_178 * V_178 , void * V_180 ,
struct V_192 * V_193 )
{
strcpy ( V_193 -> V_194 , L_9 ) ;
strcpy ( V_193 -> V_195 , L_9 ) ;
V_193 -> V_196 = 1 ;
V_193 -> V_197 = V_198 |
V_199 | V_200 ;
return 0 ;
}
static int F_107 ( struct V_178 * V_179 ,
void * V_180 , struct V_201 * V_69 )
{
if ( V_69 -> V_202 >= V_4 )
return - V_121 ;
F_108 ( V_69 -> V_203 , V_5 [ V_69 -> V_202 ] . V_153 ,
sizeof( V_69 -> V_203 ) ) ;
V_69 -> V_2 = V_5 [ V_69 -> V_202 ] . V_2 ;
return 0 ;
}
static int F_109 ( struct V_178 * V_179 , void * V_180 ,
struct V_204 * V_69 )
{
struct V_10 * V_11 = V_180 ;
struct V_1 * V_205 ;
struct V_68 * V_206 = & V_69 -> V_69 . V_206 ;
struct V_129 V_130 ;
int V_108 ;
V_205 = F_1 ( V_206 -> V_2 ) ;
V_206 -> V_2 = V_205 -> V_2 ;
F_60 ( & V_130 , V_206 , V_205 -> V_131 ) ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_133 , V_207 , & V_130 ) ;
F_57 ( & V_11 -> V_109 ) ;
F_110 ( V_206 , & V_130 ) ;
V_206 -> V_73 = V_206 -> V_208 * V_205 -> V_209 ;
V_206 -> V_17 = V_206 -> V_70 * V_206 -> V_73 ;
return V_108 ;
}
static int F_111 ( struct V_178 * V_179 , void * V_180 ,
struct V_204 * V_69 )
{
struct V_10 * V_11 = V_180 ;
struct V_1 * V_205 ;
int V_108 ;
if ( V_11 -> V_48 != V_100 || V_11 -> V_162 . V_210 > 0 )
return - V_211 ;
V_205 = F_1 ( V_69 -> V_69 . V_206 . V_2 ) ;
V_108 = F_109 ( V_179 , V_180 , V_69 ) ;
if ( V_108 )
return V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_11 -> V_16 = V_69 -> V_69 . V_206 ;
V_11 -> V_131 = V_205 -> V_131 ;
if ( V_11 -> V_135 == V_136 ) {
V_108 = F_32 ( V_11 ) ;
if ( V_108 )
goto V_111;
}
F_11 ( V_11 , 1 ) ;
V_108 = 0 ;
V_111:
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_112 ( struct V_178 * V_179 , void * V_180 ,
struct V_204 * V_205 )
{
struct V_10 * V_11 = V_180 ;
V_205 -> V_69 . V_206 = V_11 -> V_16 ;
return 0 ;
}
static int F_113 ( struct V_178 * V_179 , void * V_180 ,
struct V_212 * V_213 )
{
if ( V_213 -> V_202 != 0 )
return - V_121 ;
V_213 -> type = V_214 ;
V_213 -> V_215 = V_216 ;
strcpy ( V_213 -> V_217 , L_10 ) ;
return 0 ;
}
static int F_114 ( struct V_178 * V_179 , void * V_180 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_115 ( struct V_178 * V_179 , void * V_180 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_121 ;
return 0 ;
}
static int F_116 ( struct V_178 * V_179 , void * V_180 , T_2 * V_218 )
{
return 0 ;
}
static int F_117 ( struct V_178 * V_179 , void * V_180 ,
struct V_219 * V_220 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_133 , V_221 , V_220 ) ;
F_57 ( & V_11 -> V_109 ) ;
V_220 -> V_222 . V_223 . V_224 = V_30 ;
return V_108 ;
}
static int F_118 ( struct V_178 * V_179 , void * V_180 ,
struct V_219 * V_220 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_133 , V_225 , V_220 ) ;
F_57 ( & V_11 -> V_109 ) ;
V_220 -> V_222 . V_223 . V_224 = V_30 ;
return V_108 ;
}
static int F_119 ( struct V_178 * V_178 , void * V_180 ,
struct V_106 * V_107 )
{
struct V_10 * V_11 = V_180 ;
V_107 -> V_112 = V_113 ;
V_107 -> V_226 = 0 ;
if ( F_120 ( & V_107 -> V_114 ) ) {
V_107 -> V_112 = V_11 -> V_41 ;
return 0 ;
}
return F_54 ( V_11 , V_104 , V_118 , V_107 ) ;
}
static int F_121 ( struct V_178 * V_179 , void * V_180 ,
struct V_227 * V_140 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_133 , V_228 , V_140 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_122 ( struct V_178 * V_179 , void * V_180 ,
struct V_229 * V_230 )
{
struct V_10 * V_11 = V_180 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_54 ( V_11 , V_133 , V_231 , V_230 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_123 ( struct V_178 * V_178 , void * V_180 ,
struct V_232 * V_233 )
{
struct V_10 * V_11 = V_180 ;
if ( F_120 ( & V_233 -> V_114 ) ) {
V_233 -> V_234 = F_124 ( V_11 , V_233 -> V_233 ) ;
V_233 -> V_235 = 4 ;
return 0 ;
}
return F_54 ( V_11 , V_104 , V_236 , V_233 ) ;
}
static int F_125 ( struct V_178 * V_178 , void * V_180 ,
struct V_232 * V_233 )
{
struct V_10 * V_11 = V_180 ;
if ( F_120 ( & V_233 -> V_114 ) ) {
F_24 ( V_11 , V_233 -> V_233 , V_233 -> V_234 ) ;
return 0 ;
}
return F_54 ( V_11 , V_104 , V_237 , V_233 ) ;
}
static int F_126 ( struct V_178 * V_179 )
{
struct V_10 * V_11 = F_127 ( V_179 ) ;
int V_108 = 0 ;
V_179 -> V_182 = V_11 ;
V_238 = V_51 = V_52 = 0 ;
F_56 ( & V_11 -> V_109 ) ;
if ( V_11 -> V_239 == 0 ) {
V_108 = F_81 ( V_11 ) ;
if ( V_108 )
goto V_111;
F_51 ( V_11 ) ;
F_53 ( V_11 ) ;
F_11 ( V_11 , 1 ) ;
}
( V_11 -> V_239 ) ++ ;
V_111:
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_128 ( struct V_178 * V_179 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
F_21 ( V_11 , L_11 , V_238 ,
V_51 , V_52 ) ;
F_56 ( & V_11 -> V_109 ) ;
( V_11 -> V_239 ) -- ;
if ( V_179 == V_11 -> V_240 ) {
F_49 ( V_11 ) ;
V_11 -> V_240 = NULL ;
}
if ( V_11 -> V_239 == 0 ) {
F_88 ( V_11 ) ;
F_52 ( V_11 ) ;
if ( V_11 -> V_135 == V_136 && V_241 )
F_22 ( V_11 ) ;
}
F_57 ( & V_11 -> V_109 ) ;
return 0 ;
}
static T_3 F_129 ( struct V_178 * V_179 ,
char T_4 * V_242 , T_5 V_243 , T_6 * V_244 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_130 ( & V_11 -> V_162 , V_242 , V_243 , V_244 ,
V_179 -> V_186 & V_187 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static unsigned int F_131 ( struct V_178 * V_179 ,
struct V_245 * V_246 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_132 ( & V_11 -> V_162 , V_179 , V_246 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static int F_133 ( struct V_178 * V_179 , struct V_247 * V_248 )
{
struct V_10 * V_11 = V_179 -> V_182 ;
int V_108 ;
F_56 ( & V_11 -> V_109 ) ;
V_108 = F_134 ( & V_11 -> V_162 , V_248 ) ;
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
}
static void F_135 ( struct V_10 * V_11 , int V_12 )
{
F_12 ( V_12 , & V_11 -> V_23 ) ;
F_8 ( V_101 , & V_11 -> V_23 ) ;
V_11 -> V_21 = V_12 ;
V_11 -> V_19 [ V_12 ] = ++ ( V_11 -> V_18 ) ;
V_238 ++ ;
if ( V_11 -> V_48 != V_49 )
return;
V_11 -> V_172 ( V_11 , V_12 ) ;
}
int F_136 ( struct V_10 * V_11 , unsigned int V_249 )
{
unsigned int V_12 , V_250 = 0 ;
F_24 ( V_11 , V_94 , V_95 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
if ( V_249 & ( V_251 << V_12 ) ) {
F_135 ( V_11 , V_12 ) ;
V_250 = 1 ;
}
if ( V_249 & ( V_252 | V_253 | V_254 ) ) {
F_12 ( V_101 , & V_11 -> V_23 ) ;
V_250 = 1 ;
if ( V_11 -> V_135 == V_173 )
F_15 ( V_11 ) ;
}
return V_250 ;
}
int F_137 ( struct V_10 * V_11 )
{
struct V_255 V_256 = {
. type = L_12 ,
. V_116 = 0x42 >> 1 ,
. V_257 = & V_258 ,
} ;
int V_108 ;
if ( V_135 >= 0 )
V_11 -> V_135 = V_135 ;
if ( V_11 -> V_135 == V_173 &&
V_11 -> V_41 == V_42 ) {
F_138 ( V_259 L_13
L_14 ) ;
V_11 -> V_135 = V_136 ;
}
if ( ! F_139 ( V_11 -> V_135 ) ) {
F_138 ( V_259 L_15 ,
V_11 -> V_135 ) ;
return - V_121 ;
}
V_108 = F_140 ( V_11 -> V_32 , & V_11 -> V_260 ) ;
if ( V_108 )
return V_108 ;
F_141 ( & V_11 -> V_109 ) ;
V_11 -> V_48 = V_110 ;
F_11 ( V_11 , 1 ) ;
V_11 -> V_16 = V_261 ;
V_11 -> V_131 = V_262 ;
F_70 ( & V_11 -> V_50 ) ;
F_48 ( V_11 ) ;
V_258 . V_263 = V_11 -> V_263 ;
V_258 . V_264 = V_11 -> V_264 ;
V_11 -> V_117 = V_256 . V_116 ;
V_11 -> V_265 = F_142 ( & V_11 -> V_260 ,
V_11 -> V_266 , & V_256 , NULL ) ;
if ( V_11 -> V_265 == NULL ) {
V_108 = - V_267 ;
goto V_268;
}
V_108 = F_55 ( V_11 ) ;
if ( V_108 )
goto V_268;
F_56 ( & V_11 -> V_109 ) ;
V_11 -> V_269 = V_270 ;
V_11 -> V_269 . V_271 = 0 ;
V_11 -> V_269 . V_260 = & V_11 -> V_260 ;
V_108 = F_143 ( & V_11 -> V_269 , V_272 , - 1 ) ;
if ( V_108 )
goto V_111;
F_144 ( & V_11 -> V_269 , V_11 ) ;
if ( V_11 -> V_135 == V_136 && ! V_241 ) {
if ( F_17 ( V_11 , 1 ) )
F_19 ( V_11 , L_16
L_17 ) ;
}
V_111:
F_57 ( & V_11 -> V_109 ) ;
return V_108 ;
V_268:
F_145 ( & V_11 -> V_260 ) ;
return V_108 ;
}
void F_146 ( struct V_10 * V_11 )
{
if ( V_11 -> V_239 > 0 ) {
F_19 ( V_11 , L_18 ) ;
F_52 ( V_11 ) ;
}
F_89 ( & V_11 -> V_162 ) ;
if ( V_11 -> V_135 == V_136 )
F_22 ( V_11 ) ;
F_147 ( & V_11 -> V_269 ) ;
F_145 ( & V_11 -> V_260 ) ;
}
void F_148 ( struct V_10 * V_11 )
{
enum V_273 V_274 = V_11 -> V_48 ;
F_49 ( V_11 ) ;
F_52 ( V_11 ) ;
V_11 -> V_48 = V_274 ;
}
int F_149 ( struct V_10 * V_11 )
{
int V_108 = 0 ;
F_56 ( & V_11 -> V_109 ) ;
if ( V_11 -> V_239 > 0 ) {
F_51 ( V_11 ) ;
F_53 ( V_11 ) ;
} else {
F_52 ( V_11 ) ;
}
F_57 ( & V_11 -> V_109 ) ;
F_12 ( V_24 , & V_11 -> V_23 ) ;
if ( V_11 -> V_48 == V_49 )
V_108 = F_61 ( V_11 ) ;
return V_108 ;
}
