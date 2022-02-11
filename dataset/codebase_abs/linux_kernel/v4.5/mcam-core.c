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
V_13 -> V_14 . V_15 [ 0 ] . V_16 = V_11 -> V_17 . V_18 ;
V_13 -> V_19 = V_11 -> V_20 [ V_12 ] ;
V_13 -> V_21 = V_22 ;
V_13 -> V_14 . V_23 = F_5 () ;
F_6 ( & V_13 -> V_14 , 0 , V_11 -> V_17 . V_18 ) ;
F_7 ( & V_13 -> V_14 , V_24 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
int V_3 ;
V_11 -> V_25 = - 1 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_26 ; V_3 ++ ) {
F_9 ( V_3 , & V_11 -> V_27 ) ;
F_9 ( V_28 + V_3 , & V_11 -> V_27 ) ;
}
}
static inline int F_10 ( struct V_10 * V_11 )
{
return F_11 ( V_29 , & V_11 -> V_27 ) ;
}
static void F_12 ( struct V_10 * V_11 , int V_30 )
{
if ( V_30 )
F_13 ( V_29 , & V_11 -> V_27 ) ;
else
F_9 ( V_29 , & V_11 -> V_27 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
F_15 ( V_11 , V_31 , V_32 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_17 ( V_11 , V_31 , V_32 ) ;
}
static void F_18 ( struct V_10 * V_33 )
{
F_19 ( V_33 , L_1 ,
V_33 -> V_34 [ 0 ] , V_33 -> V_34 [ 1 ] , V_33 -> V_34 [ 2 ] ) ;
F_20 ( V_33 , V_35 , V_33 -> V_34 [ 0 ] ) ;
F_20 ( V_33 , V_36 , V_33 -> V_34 [ 1 ] ) ;
F_20 ( V_33 , V_37 , V_33 -> V_34 [ 2 ] ) ;
if ( ! V_33 -> V_38 ) {
if ( V_33 -> V_39 > 4 || V_33 -> V_39 <= 0 ) {
F_21 ( V_33 , L_2 ) ;
V_33 -> V_39 = 1 ;
}
F_20 ( V_33 , V_40 ,
V_41 | F_22 ( V_33 -> V_39 ) ) ;
F_20 ( V_33 , V_42 ,
( V_33 -> V_43 << 29 ) | V_33 -> V_44 ) ;
V_33 -> V_38 = true ;
}
}
static void F_23 ( struct V_10 * V_33 )
{
F_20 ( V_33 , V_40 , 0x0 ) ;
F_20 ( V_33 , V_35 , 0x0 ) ;
F_20 ( V_33 , V_36 , 0x0 ) ;
F_20 ( V_33 , V_37 , 0x0 ) ;
V_33 -> V_38 = false ;
}
static bool F_24 ( T_2 V_45 )
{
struct V_1 * V_46 ;
V_46 = F_1 ( V_45 ) ;
return V_46 -> V_47 ;
}
static void F_25 ( struct V_10 * V_11 ,
unsigned V_12 , T_3 V_48 )
{
struct V_49 * V_50 = & V_11 -> V_17 ;
T_1 V_51 = V_50 -> V_52 * V_50 -> V_53 ;
T_3 V_54 , V_55 = 0 , V_56 = 0 ;
V_54 = V_48 ;
switch ( V_50 -> V_2 ) {
case V_57 :
V_55 = V_54 + V_51 ;
V_56 = V_55 + V_51 / 4 ;
break;
case V_58 :
V_56 = V_54 + V_51 ;
V_55 = V_56 + V_51 / 4 ;
break;
default:
break;
}
F_20 ( V_11 , V_59 + V_12 * 4 , V_54 ) ;
if ( F_24 ( V_50 -> V_2 ) ) {
F_20 ( V_11 , V_60 + V_12 * 4 , V_55 ) ;
F_20 ( V_11 , V_61 + V_12 * 4 , V_56 ) ;
}
}
static int F_26 ( struct V_10 * V_11 , int V_62 )
{
int V_3 ;
F_12 ( V_11 , 1 ) ;
if ( V_62 )
V_11 -> V_63 = V_63 ;
else
V_11 -> V_63 = V_11 -> V_17 . V_18 ;
if ( V_64 > 3 )
V_64 = 3 ;
V_11 -> V_26 = 0 ;
for ( V_3 = 0 ; V_3 < V_64 ; V_3 ++ ) {
V_11 -> V_65 [ V_3 ] = F_27 ( V_11 -> V_66 ,
V_11 -> V_63 , V_11 -> V_67 + V_3 ,
V_68 ) ;
if ( V_11 -> V_65 [ V_3 ] == NULL ) {
F_21 ( V_11 , L_3 ) ;
break;
}
( V_11 -> V_26 ) ++ ;
}
switch ( V_11 -> V_26 ) {
case 1 :
F_28 ( V_11 -> V_66 , V_11 -> V_63 ,
V_11 -> V_65 [ 0 ] , V_11 -> V_67 [ 0 ] ) ;
V_11 -> V_26 = 0 ;
case 0 :
F_29 ( V_11 , L_4 ) ;
return - V_69 ;
case 2 :
if ( V_64 > 2 )
F_21 ( V_11 , L_5 ) ;
break;
}
return 0 ;
}
static void F_30 ( struct V_10 * V_11 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_26 ; V_3 ++ ) {
F_28 ( V_11 -> V_66 , V_11 -> V_63 ,
V_11 -> V_65 [ V_3 ] , V_11 -> V_67 [ V_3 ] ) ;
V_11 -> V_65 [ V_3 ] = NULL ;
}
V_11 -> V_26 = 0 ;
}
static void F_31 ( struct V_10 * V_11 )
{
F_25 ( V_11 , 0 , V_11 -> V_67 [ 0 ] ) ;
F_25 ( V_11 , 1 , V_11 -> V_67 [ 1 ] ) ;
if ( V_11 -> V_26 > 2 ) {
F_25 ( V_11 , 2 , V_11 -> V_67 [ 2 ] ) ;
F_17 ( V_11 , V_70 , V_71 ) ;
} else
F_15 ( V_11 , V_70 , V_71 ) ;
if ( V_11 -> V_72 == V_73 )
F_20 ( V_11 , V_74 , 0 ) ;
}
static void F_32 ( unsigned long V_75 )
{
struct V_10 * V_11 = (struct V_10 * ) V_75 ;
int V_3 ;
unsigned long V_27 ;
struct V_6 * V_76 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_26 ; V_3 ++ ) {
int V_78 = V_11 -> V_25 ;
if ( V_11 -> V_79 != V_80 || V_78 < 0 )
break;
if ( ++ ( V_11 -> V_25 ) >= V_11 -> V_26 )
V_11 -> V_25 = 0 ;
if ( ! F_11 ( V_78 , & V_11 -> V_27 ) )
continue;
if ( F_34 ( & V_11 -> V_81 ) ) {
V_11 -> V_82 . V_83 ++ ;
break;
}
V_11 -> V_82 . V_84 ++ ;
F_9 ( V_78 , & V_11 -> V_27 ) ;
V_76 = F_35 ( & V_11 -> V_81 , struct V_6 ,
V_85 ) ;
F_36 ( & V_76 -> V_85 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
memcpy ( F_38 ( & V_76 -> V_9 . V_14 , 0 ) ,
V_11 -> V_65 [ V_78 ] ,
V_11 -> V_17 . V_18 ) ;
F_4 ( V_11 , V_78 , & V_76 -> V_9 ) ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
}
F_37 ( & V_11 -> V_77 , V_27 ) ;
}
static int F_39 ( struct V_10 * V_11 )
{
if ( V_11 -> V_26 > 0 && V_11 -> V_63 < V_11 -> V_17 . V_18 )
F_30 ( V_11 ) ;
if ( V_11 -> V_26 == 0 )
return F_26 ( V_11 , 0 ) ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 , int V_12 )
{
F_41 ( & V_11 -> V_86 ) ;
}
static inline int F_26 ( struct V_10 * V_11 , int V_62 )
{
return 0 ;
}
static inline void F_30 ( struct V_10 * V_11 )
{
return;
}
static inline int F_39 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_42 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_76 ;
T_3 V_87 ;
struct V_7 * V_8 ;
if ( F_34 ( & V_11 -> V_81 ) ) {
V_76 = V_11 -> V_88 [ V_12 ^ 0x1 ] ;
F_13 ( V_89 , & V_11 -> V_27 ) ;
V_11 -> V_82 . V_83 ++ ;
} else {
V_76 = F_35 ( & V_11 -> V_81 , struct V_6 ,
V_85 ) ;
F_36 ( & V_76 -> V_85 ) ;
F_9 ( V_89 , & V_11 -> V_27 ) ;
}
V_11 -> V_88 [ V_12 ] = V_76 ;
V_8 = & V_76 -> V_9 ;
V_87 = F_43 ( & V_8 -> V_14 , 0 ) ;
F_25 ( V_11 , V_12 , V_87 ) ;
}
static void F_44 ( struct V_10 * V_11 )
{
F_15 ( V_11 , V_70 , V_71 ) ;
V_11 -> V_26 = 2 ;
F_42 ( V_11 , 0 ) ;
F_42 ( V_11 , 1 ) ;
}
static void F_45 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_76 = V_11 -> V_88 [ V_12 ] ;
if ( ! F_11 ( V_89 , & V_11 -> V_27 ) ) {
V_11 -> V_82 . V_84 ++ ;
V_11 -> V_88 [ V_12 ] = NULL ;
F_4 ( V_11 , V_12 , & V_76 -> V_9 ) ;
}
F_42 ( V_11 , V_12 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
struct V_6 * V_76 ;
V_76 = F_35 ( & V_11 -> V_81 , struct V_6 , V_85 ) ;
F_36 ( & V_76 -> V_85 ) ;
F_17 ( V_11 , V_70 , V_90 ) ;
F_20 ( V_11 , V_91 , V_76 -> V_92 ) ;
F_20 ( V_11 , V_93 ,
V_76 -> V_94 * sizeof( struct V_95 ) ) ;
F_20 ( V_11 , V_96 , 0 ) ;
F_20 ( V_11 , V_97 , 0 ) ;
F_15 ( V_11 , V_70 , V_90 ) ;
V_11 -> V_88 [ 0 ] = V_76 ;
}
static void F_47 ( struct V_10 * V_11 )
{
if ( F_34 ( & V_11 -> V_81 ) ) {
F_13 ( V_98 , & V_11 -> V_27 ) ;
return;
}
F_17 ( V_11 , V_70 , V_99 ) ;
F_46 ( V_11 ) ;
V_11 -> V_26 = 3 ;
}
static void F_48 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_76 = V_11 -> V_88 [ 0 ] ;
if ( V_11 -> V_79 != V_80 )
return;
if ( ! F_34 ( & V_11 -> V_81 ) ) {
F_46 ( V_11 ) ;
F_14 ( V_11 ) ;
} else {
F_13 ( V_98 , & V_11 -> V_27 ) ;
V_11 -> V_82 . V_83 ++ ;
V_11 -> V_88 [ 0 ] = NULL ;
}
V_11 -> V_82 . V_84 ++ ;
F_4 ( V_11 , V_12 , & V_76 -> V_9 ) ;
}
static void F_49 ( struct V_10 * V_11 )
{
F_47 ( V_11 ) ;
F_14 ( V_11 ) ;
F_9 ( V_98 , & V_11 -> V_27 ) ;
}
static inline void F_49 ( struct V_10 * V_11 )
{
return;
}
static void F_50 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = & V_11 -> V_17 ;
T_1 V_100 = 0 , V_101 = 0 , V_102 , V_103 ;
F_19 ( V_11 , L_6 ,
V_50 -> V_104 , V_50 -> V_18 / V_50 -> V_104 ) ;
V_102 = ( V_50 -> V_53 << V_105 ) & V_106 ;
V_103 = ( V_50 -> V_52 * 2 ) & V_107 ;
switch ( V_50 -> V_2 ) {
case V_108 :
case V_109 :
V_100 = V_50 -> V_52 * 2 ;
V_101 = 0 ;
break;
case V_57 :
case V_58 :
V_100 = V_50 -> V_52 ;
V_101 = V_50 -> V_52 / 2 ;
break;
default:
V_100 = V_50 -> V_104 ;
V_101 = 0 ;
break;
}
F_51 ( V_11 , V_110 , V_101 << 16 | V_100 ,
V_111 | V_112 ) ;
F_20 ( V_11 , V_113 , V_102 | V_103 ) ;
F_20 ( V_11 , V_114 , 0x0 ) ;
switch ( V_50 -> V_2 ) {
case V_57 :
case V_58 :
F_51 ( V_11 , V_31 ,
V_115 | V_116 | V_117 , V_118 ) ;
break;
case V_108 :
F_51 ( V_11 , V_31 ,
V_115 | V_119 | V_120 , V_118 ) ;
break;
case V_109 :
F_51 ( V_11 , V_31 ,
V_115 | V_119 | V_121 , V_118 ) ;
break;
case V_122 :
F_51 ( V_11 , V_31 ,
V_123 | V_124 | V_125 , V_118 ) ;
break;
case V_126 :
F_51 ( V_11 , V_31 ,
V_123 | V_127 | V_128 , V_118 ) ;
break;
case V_129 :
F_51 ( V_11 , V_31 ,
V_123 | V_130 , V_118 ) ;
break;
default:
F_29 ( V_11 , L_7 , V_50 -> V_2 ) ;
break;
}
F_51 ( V_11 , V_31 , V_131 , V_132 ) ;
if ( V_11 -> V_133 != V_134 )
F_15 ( V_11 , V_31 ,
V_135 | V_136 ) ;
}
static int F_52 ( struct V_10 * V_11 )
{
unsigned long V_27 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_9 ( V_98 , & V_11 -> V_27 ) ;
V_11 -> V_137 ( V_11 ) ;
F_50 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
return 0 ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_20 ( V_11 , V_138 , V_139 ) ;
F_15 ( V_11 , V_140 , V_139 ) ;
}
static void F_54 ( struct V_10 * V_11 )
{
F_17 ( V_11 , V_140 , V_139 ) ;
}
static void F_55 ( struct V_10 * V_11 )
{
unsigned long V_27 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_17 ( V_11 , V_70 , V_141 ) ;
F_17 ( V_11 , V_31 , V_32 ) ;
F_51 ( V_11 , V_42 , 2 , V_142 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
}
static void F_56 ( struct V_10 * V_11 )
{
unsigned long V_27 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_9 ( V_98 , & V_11 -> V_27 ) ;
F_16 ( V_11 ) ;
V_11 -> V_79 = V_143 ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
F_57 ( 150 ) ;
if ( F_11 ( V_144 , & V_11 -> V_27 ) )
F_29 ( V_11 , L_8 ) ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_54 ( V_11 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
}
static int F_58 ( struct V_10 * V_11 )
{
unsigned long V_27 ;
int V_145 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
V_145 = V_11 -> V_146 ( V_11 ) ;
if ( V_145 ) {
F_37 ( & V_11 -> V_77 , V_27 ) ;
return V_145 ;
}
F_17 ( V_11 , V_70 , V_141 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
F_57 ( 5 ) ;
return 0 ;
}
static void F_59 ( struct V_10 * V_11 )
{
unsigned long V_27 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_15 ( V_11 , V_70 , V_141 ) ;
V_11 -> V_147 ( V_11 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
}
static int F_60 ( struct V_10 * V_11 )
{
return F_61 ( V_11 , V_148 , V_149 , 0 ) ;
}
static int F_62 ( struct V_10 * V_11 )
{
int V_145 ;
if ( V_11 -> V_79 != V_150 )
F_21 ( V_11 , L_9 ,
V_11 -> V_79 ) ;
V_145 = F_60 ( V_11 ) ;
V_11 -> V_79 = V_143 ;
F_59 ( V_11 ) ;
return V_145 ;
}
static int F_63 ( struct V_10 * V_11 )
{
struct V_151 V_152 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_153 = V_154 ;
V_152 . V_155 = V_156 ;
return F_61 ( V_11 , V_148 , V_157 , & V_152 ) ;
}
static int F_64 ( struct V_10 * V_11 )
{
struct V_158 V_159 = {
. V_160 = V_161 ,
} ;
int V_145 ;
F_65 ( & V_159 . V_159 , & V_11 -> V_17 , V_11 -> V_162 ) ;
V_145 = F_61 ( V_11 , V_148 , V_163 , 0 ) ;
if ( V_145 == 0 )
V_145 = F_61 ( V_11 , V_164 , V_165 , NULL , & V_159 ) ;
V_145 += F_63 ( V_11 ) ;
return V_145 ;
}
static int F_66 ( struct V_10 * V_11 )
{
int V_145 ;
unsigned long V_27 ;
if ( V_11 -> V_166 == V_167 && V_11 -> V_26 == 0 &&
F_26 ( V_11 , 0 ) )
return - V_69 ;
if ( F_10 ( V_11 ) ) {
F_64 ( V_11 ) ;
V_145 = F_52 ( V_11 ) ;
if ( V_145 )
return V_145 ;
}
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_9 ( V_144 , & V_11 -> V_27 ) ;
F_8 ( V_11 ) ;
if ( V_11 -> V_168 )
V_11 -> V_168 ( V_11 ) ;
F_19 ( V_11 , L_10 ,
V_11 -> V_34 [ 0 ] , V_11 -> V_34 [ 1 ] , V_11 -> V_34 [ 2 ] ) ;
if ( V_11 -> V_133 == V_134 )
F_18 ( V_11 ) ;
else
F_23 ( V_11 ) ;
F_53 ( V_11 ) ;
V_11 -> V_79 = V_80 ;
if ( ! F_11 ( V_98 , & V_11 -> V_27 ) )
F_14 ( V_11 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
return 0 ;
}
static int F_67 ( struct V_169 * V_170 ,
unsigned int * V_26 ,
unsigned int * V_171 , unsigned int V_172 [] ,
void * V_173 [] )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
int V_174 = ( V_11 -> V_166 == V_175 ) ? 3 : 2 ;
unsigned V_176 = V_11 -> V_17 . V_18 ;
if ( * V_26 < V_174 )
* V_26 = V_174 ;
if ( V_11 -> V_166 == V_175 )
V_173 [ 0 ] = V_11 -> V_177 ;
else if ( V_11 -> V_166 == V_178 )
V_173 [ 0 ] = V_11 -> V_179 ;
if ( * V_171 )
return V_172 [ 0 ] < V_176 ? - V_180 : 0 ;
V_172 [ 0 ] = V_176 ;
* V_171 = 1 ;
return 0 ;
}
static void F_69 ( struct V_181 * V_8 )
{
struct V_7 * V_13 = F_70 ( V_8 ) ;
struct V_6 * V_182 = F_2 ( V_13 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
unsigned long V_27 ;
int V_183 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
V_183 = ( V_11 -> V_79 == V_184 ) && ! F_34 ( & V_11 -> V_81 ) ;
F_71 ( & V_182 -> V_85 , & V_11 -> V_81 ) ;
if ( V_11 -> V_79 == V_80 && F_11 ( V_98 , & V_11 -> V_27 ) )
F_49 ( V_11 ) ;
F_37 ( & V_11 -> V_77 , V_27 ) ;
if ( V_183 )
F_66 ( V_11 ) ;
}
static void F_72 ( struct V_169 * V_170 ,
enum V_185 V_79 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
struct V_6 * V_76 , * V_186 ;
unsigned long V_27 ;
unsigned V_3 ;
F_33 ( & V_11 -> V_77 , V_27 ) ;
F_73 (buf, node, &cam->buffers, queue) {
F_7 ( & V_76 -> V_9 . V_14 , V_79 ) ;
F_74 ( & V_76 -> V_85 ) ;
}
for ( V_3 = 0 ; V_3 < V_187 ; V_3 ++ ) {
V_76 = V_11 -> V_88 [ V_3 ] ;
if ( V_76 ) {
F_7 ( & V_76 -> V_9 . V_14 , V_79 ) ;
V_11 -> V_88 [ V_3 ] = NULL ;
}
}
F_37 ( & V_11 -> V_77 , V_27 ) ;
}
static int F_75 ( struct V_169 * V_170 , unsigned int V_188 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
unsigned int V_12 ;
int V_145 ;
if ( V_11 -> V_79 != V_143 ) {
F_72 ( V_170 , V_189 ) ;
return - V_180 ;
}
V_11 -> V_82 . V_190 = 0 ;
V_11 -> V_82 . V_83 = 0 ;
V_11 -> V_82 . V_84 = 0 ;
V_11 -> V_19 = 0 ;
if ( V_11 -> V_166 != V_167 && F_34 ( & V_11 -> V_81 ) ) {
V_11 -> V_79 = V_184 ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_26 ; V_12 ++ )
F_9 ( V_28 + V_12 , & V_11 -> V_27 ) ;
V_145 = F_66 ( V_11 ) ;
if ( V_145 )
F_72 ( V_170 , V_189 ) ;
return V_145 ;
}
static void F_76 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
F_19 ( V_11 , L_11 ,
V_11 -> V_82 . V_190 , V_11 -> V_82 . V_83 ,
V_11 -> V_82 . V_84 ) ;
if ( V_11 -> V_79 == V_184 ) {
V_11 -> V_79 = V_143 ;
return;
}
if ( V_11 -> V_79 != V_80 )
return;
F_56 ( V_11 ) ;
if ( V_11 -> V_191 )
V_11 -> V_191 ( V_11 ) ;
F_72 ( V_170 , V_192 ) ;
}
static int F_77 ( struct V_181 * V_8 )
{
struct V_7 * V_13 = F_70 ( V_8 ) ;
struct V_6 * V_182 = F_2 ( V_13 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
int V_193 = V_11 -> V_17 . V_18 / V_194 + 1 ;
V_182 -> V_195 = F_27 ( V_11 -> V_66 ,
V_193 * sizeof( struct V_95 ) ,
& V_182 -> V_92 , V_68 ) ;
if ( V_182 -> V_195 == NULL ) {
F_29 ( V_11 , L_12 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_78 ( struct V_181 * V_8 )
{
struct V_7 * V_13 = F_70 ( V_8 ) ;
struct V_6 * V_182 = F_2 ( V_13 ) ;
struct V_196 * V_196 = F_79 ( V_8 , 0 ) ;
struct V_95 * V_197 = V_182 -> V_195 ;
struct V_198 * V_199 ;
int V_3 ;
F_80 (sg_table->sgl, sg, sg_table->nents, i) {
V_197 -> V_200 = F_81 ( V_199 ) ;
V_197 -> V_201 = F_82 ( V_199 ) ;
V_197 ++ ;
}
return 0 ;
}
static void F_83 ( struct V_181 * V_8 )
{
struct V_7 * V_13 = F_70 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
struct V_6 * V_182 = F_2 ( V_13 ) ;
int V_193 = V_11 -> V_17 . V_18 / V_194 + 1 ;
F_28 ( V_11 -> V_66 , V_193 * sizeof( struct V_95 ) ,
V_182 -> V_195 , V_182 -> V_92 ) ;
}
static int F_84 ( struct V_10 * V_11 )
{
struct V_169 * V_170 = & V_11 -> V_202 ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_170 -> type = V_203 ;
V_170 -> V_204 = V_11 ;
V_170 -> V_205 = & V_11 -> V_206 ;
V_170 -> V_207 = V_208 ;
V_170 -> V_209 = V_210 | V_211 | V_212 | V_213 ;
V_170 -> V_214 = sizeof( struct V_6 ) ;
F_85 ( & V_11 -> V_81 ) ;
switch ( V_11 -> V_166 ) {
case V_175 :
#ifdef F_86
V_170 -> V_215 = & V_216 ;
V_170 -> V_217 = & V_218 ;
V_11 -> V_137 = F_44 ;
V_11 -> V_219 = F_45 ;
V_11 -> V_177 = F_87 ( V_11 -> V_66 ) ;
if ( F_88 ( V_11 -> V_177 ) )
return F_89 ( V_11 -> V_177 ) ;
#endif
break;
case V_178 :
#ifdef F_90
V_170 -> V_215 = & V_220 ;
V_170 -> V_217 = & V_221 ;
V_11 -> V_137 = F_47 ;
V_11 -> V_219 = F_48 ;
V_11 -> V_179 = F_91 ( V_11 -> V_66 ) ;
if ( F_88 ( V_11 -> V_179 ) )
return F_89 ( V_11 -> V_179 ) ;
#endif
break;
case V_167 :
#ifdef F_92
F_93 ( & V_11 -> V_86 , F_32 ,
( unsigned long ) V_11 ) ;
V_170 -> V_215 = & V_216 ;
V_170 -> V_217 = & V_222 ;
V_11 -> V_137 = F_31 ;
V_11 -> V_219 = F_40 ;
#endif
break;
}
return F_94 ( V_170 ) ;
}
static void F_95 ( struct V_10 * V_11 )
{
#ifdef F_86
if ( V_11 -> V_166 == V_175 )
F_96 ( V_11 -> V_177 ) ;
#endif
#ifdef F_90
if ( V_11 -> V_166 == V_178 )
F_97 ( V_11 -> V_179 ) ;
#endif
}
static int F_98 ( struct V_223 * V_223 , void * V_224 ,
struct V_225 * V_226 )
{
struct V_10 * V_11 = F_99 ( V_223 ) ;
strcpy ( V_226 -> V_227 , L_13 ) ;
strcpy ( V_226 -> V_228 , L_13 ) ;
F_100 ( V_226 -> V_229 , V_11 -> V_229 , sizeof( V_226 -> V_229 ) ) ;
V_226 -> V_230 = V_231 |
V_232 | V_233 ;
V_226 -> V_234 = V_226 -> V_230 | V_235 ;
return 0 ;
}
static int F_101 ( struct V_223 * V_236 ,
void * V_224 , struct V_237 * V_50 )
{
if ( V_50 -> V_238 >= V_4 )
return - V_180 ;
F_100 ( V_50 -> V_239 , V_5 [ V_50 -> V_238 ] . V_197 ,
sizeof( V_50 -> V_239 ) ) ;
V_50 -> V_2 = V_5 [ V_50 -> V_238 ] . V_2 ;
return 0 ;
}
static int F_102 ( struct V_223 * V_236 , void * V_224 ,
struct V_240 * V_50 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
struct V_1 * V_46 ;
struct V_49 * V_241 = & V_50 -> V_50 . V_241 ;
struct V_242 V_243 ;
struct V_158 V_159 = {
. V_160 = V_244 ,
} ;
int V_145 ;
V_46 = F_1 ( V_241 -> V_2 ) ;
V_241 -> V_2 = V_46 -> V_2 ;
F_65 ( & V_159 . V_159 , V_241 , V_46 -> V_162 ) ;
V_145 = F_61 ( V_11 , V_164 , V_165 , & V_243 , & V_159 ) ;
F_103 ( V_241 , & V_159 . V_159 ) ;
V_241 -> V_104 = V_241 -> V_52 * V_46 -> V_245 ;
switch ( V_46 -> V_2 ) {
case V_57 :
case V_58 :
V_241 -> V_18 = V_241 -> V_53 * V_241 -> V_104 * 3 / 2 ;
break;
default:
V_241 -> V_18 = V_241 -> V_53 * V_241 -> V_104 ;
break;
}
V_241 -> V_246 = V_247 ;
return V_145 ;
}
static int F_104 ( struct V_223 * V_236 , void * V_224 ,
struct V_240 * V_50 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
struct V_1 * V_46 ;
int V_145 ;
if ( V_11 -> V_79 != V_143 || F_105 ( & V_11 -> V_202 ) )
return - V_248 ;
V_46 = F_1 ( V_50 -> V_50 . V_241 . V_2 ) ;
V_145 = F_102 ( V_236 , V_224 , V_50 ) ;
if ( V_145 )
return V_145 ;
V_11 -> V_17 = V_50 -> V_50 . V_241 ;
V_11 -> V_162 = V_46 -> V_162 ;
if ( V_11 -> V_166 == V_167 ) {
V_145 = F_39 ( V_11 ) ;
if ( V_145 )
goto V_249;
}
F_12 ( V_11 , 1 ) ;
V_249:
return V_145 ;
}
static int F_106 ( struct V_223 * V_236 , void * V_224 ,
struct V_240 * V_46 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
V_46 -> V_50 . V_241 = V_11 -> V_17 ;
return 0 ;
}
static int F_107 ( struct V_223 * V_236 , void * V_224 ,
struct V_250 * V_251 )
{
if ( V_251 -> V_238 != 0 )
return - V_180 ;
V_251 -> type = V_252 ;
strcpy ( V_251 -> V_253 , L_14 ) ;
return 0 ;
}
static int F_108 ( struct V_223 * V_236 , void * V_224 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_109 ( struct V_223 * V_236 , void * V_224 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_180 ;
return 0 ;
}
static int F_110 ( struct V_223 * V_236 , void * V_224 ,
struct V_254 * V_255 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
int V_145 ;
V_145 = F_61 ( V_11 , V_256 , V_257 , V_255 ) ;
V_255 -> V_258 . V_259 . V_260 = V_64 ;
return V_145 ;
}
static int F_111 ( struct V_223 * V_236 , void * V_224 ,
struct V_254 * V_255 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
int V_145 ;
V_145 = F_61 ( V_11 , V_256 , V_261 , V_255 ) ;
V_255 -> V_258 . V_259 . V_260 = V_64 ;
return V_145 ;
}
static int F_112 ( struct V_223 * V_236 , void * V_224 ,
struct V_262 * V_172 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
struct V_1 * V_46 ;
struct V_263 V_264 = {
. V_238 = V_172 -> V_238 ,
. V_160 = V_161 ,
} ;
int V_145 ;
V_46 = F_1 ( V_172 -> V_265 ) ;
if ( V_46 -> V_2 != V_172 -> V_265 )
return - V_180 ;
V_264 . V_266 = V_46 -> V_162 ;
V_145 = F_61 ( V_11 , V_164 , V_267 , NULL , & V_264 ) ;
if ( V_145 )
return V_145 ;
if ( V_264 . V_268 == V_264 . V_269 &&
V_264 . V_270 == V_264 . V_271 ) {
V_172 -> type = V_272 ;
V_172 -> V_273 . V_52 = V_264 . V_268 ;
V_172 -> V_273 . V_53 = V_264 . V_270 ;
return 0 ;
}
V_172 -> type = V_274 ;
V_172 -> V_275 . V_268 = V_264 . V_268 ;
V_172 -> V_275 . V_269 = V_264 . V_269 ;
V_172 -> V_275 . V_270 = V_264 . V_270 ;
V_172 -> V_275 . V_271 = V_264 . V_271 ;
V_172 -> V_275 . V_276 = 1 ;
V_172 -> V_275 . V_277 = 1 ;
return 0 ;
}
static int F_113 ( struct V_223 * V_236 , void * V_224 ,
struct V_278 * V_279 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
struct V_1 * V_46 ;
struct V_280 V_281 = {
. V_238 = V_279 -> V_238 ,
. V_52 = V_279 -> V_52 ,
. V_53 = V_279 -> V_53 ,
. V_160 = V_161 ,
} ;
int V_145 ;
V_46 = F_1 ( V_279 -> V_265 ) ;
if ( V_46 -> V_2 != V_279 -> V_265 )
return - V_180 ;
V_281 . V_266 = V_46 -> V_162 ;
V_145 = F_61 ( V_11 , V_164 , V_282 , NULL , & V_281 ) ;
if ( V_145 )
return V_145 ;
V_279 -> type = V_283 ;
V_279 -> V_273 = V_281 . V_279 ;
return 0 ;
}
static int F_114 ( struct V_223 * V_223 , void * V_224 ,
struct V_284 * V_285 )
{
struct V_10 * V_11 = F_99 ( V_223 ) ;
if ( V_285 -> V_285 > V_11 -> V_286 - 4 )
return - V_180 ;
V_285 -> V_287 = F_115 ( V_11 , V_285 -> V_285 ) ;
V_285 -> V_176 = 4 ;
return 0 ;
}
static int F_116 ( struct V_223 * V_223 , void * V_224 ,
const struct V_284 * V_285 )
{
struct V_10 * V_11 = F_99 ( V_223 ) ;
if ( V_285 -> V_285 > V_11 -> V_286 - 4 )
return - V_180 ;
F_20 ( V_11 , V_285 -> V_285 , V_285 -> V_287 ) ;
return 0 ;
}
static int F_117 ( struct V_223 * V_236 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
int V_145 ;
F_118 ( & V_11 -> V_206 ) ;
V_145 = F_119 ( V_236 ) ;
if ( V_145 )
goto V_249;
if ( F_120 ( V_236 ) ) {
V_145 = F_58 ( V_11 ) ;
if ( V_145 )
goto V_249;
F_60 ( V_11 ) ;
F_12 ( V_11 , 1 ) ;
}
V_249:
F_121 ( & V_11 -> V_206 ) ;
if ( V_145 )
F_122 ( V_236 ) ;
return V_145 ;
}
static int F_123 ( struct V_223 * V_236 )
{
struct V_10 * V_11 = F_99 ( V_236 ) ;
bool V_288 ;
F_118 ( & V_11 -> V_206 ) ;
V_288 = F_120 ( V_236 ) ;
F_124 ( V_236 , NULL ) ;
if ( V_288 ) {
F_23 ( V_11 ) ;
F_59 ( V_11 ) ;
if ( V_11 -> V_166 == V_167 && V_289 )
F_30 ( V_11 ) ;
}
F_121 ( & V_11 -> V_206 ) ;
return 0 ;
}
static void F_125 ( struct V_10 * V_11 , int V_12 )
{
F_13 ( V_12 , & V_11 -> V_27 ) ;
F_9 ( V_144 , & V_11 -> V_27 ) ;
V_11 -> V_25 = V_12 ;
V_11 -> V_20 [ V_12 ] = V_11 -> V_19 ++ ;
V_11 -> V_82 . V_190 ++ ;
if ( V_11 -> V_79 != V_80 )
return;
V_11 -> V_219 ( V_11 , V_12 ) ;
}
int F_126 ( struct V_10 * V_11 , unsigned int V_290 )
{
unsigned int V_12 , V_291 = 0 ;
F_20 ( V_11 , V_138 , V_139 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_26 ; V_12 ++ )
if ( V_290 & ( V_292 << V_12 ) &&
F_11 ( V_28 + V_12 , & V_11 -> V_27 ) ) {
F_125 ( V_11 , V_12 ) ;
V_291 = 1 ;
F_9 ( V_28 + V_12 , & V_11 -> V_27 ) ;
if ( V_11 -> V_166 == V_178 )
break;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_26 ; V_12 ++ ) {
if ( V_290 & ( V_293 << V_12 ) ) {
F_13 ( V_28 + V_12 , & V_11 -> V_27 ) ;
V_291 = V_294 ;
}
}
if ( V_291 == V_294 ) {
F_13 ( V_144 , & V_11 -> V_27 ) ;
if ( V_11 -> V_166 == V_178 )
F_16 ( V_11 ) ;
}
return V_291 ;
}
int F_127 ( struct V_10 * V_11 )
{
struct V_295 V_296 = {
. type = L_15 ,
. V_297 = 0x42 >> 1 ,
. V_298 = & V_299 ,
} ;
int V_145 ;
if ( V_166 >= 0 )
V_11 -> V_166 = V_166 ;
if ( V_11 -> V_166 == V_178 &&
V_11 -> V_72 == V_73 ) {
F_128 ( V_300 L_16
L_17 ) ;
V_11 -> V_166 = V_167 ;
}
if ( ! F_129 ( V_11 -> V_166 ) ) {
F_128 ( V_300 L_18 ,
V_11 -> V_166 ) ;
return - V_180 ;
}
V_145 = F_130 ( V_11 -> V_66 , & V_11 -> V_301 ) ;
if ( V_145 )
return V_145 ;
F_131 ( & V_11 -> V_206 ) ;
V_11 -> V_79 = V_150 ;
F_12 ( V_11 , 1 ) ;
V_11 -> V_17 = V_302 ;
V_11 -> V_162 = V_303 ;
F_55 ( V_11 ) ;
V_145 = F_132 ( & V_11 -> V_304 , 10 ) ;
if ( V_145 )
goto V_305;
V_11 -> V_301 . V_304 = & V_11 -> V_304 ;
V_299 . V_306 = V_11 -> V_306 ;
V_299 . V_307 = V_11 -> V_307 ;
V_11 -> V_308 = V_296 . V_297 ;
V_11 -> V_309 = F_133 ( & V_11 -> V_301 ,
V_11 -> V_310 , & V_296 , NULL ) ;
if ( V_11 -> V_309 == NULL ) {
V_145 = - V_311 ;
goto V_305;
}
V_145 = F_62 ( V_11 ) ;
if ( V_145 )
goto V_305;
V_145 = F_84 ( V_11 ) ;
if ( V_145 )
goto V_305;
F_118 ( & V_11 -> V_206 ) ;
V_11 -> V_312 = V_313 ;
V_11 -> V_312 . V_301 = & V_11 -> V_301 ;
V_11 -> V_312 . V_205 = & V_11 -> V_206 ;
V_11 -> V_312 . V_85 = & V_11 -> V_202 ;
F_134 ( & V_11 -> V_312 , V_11 ) ;
V_145 = F_135 ( & V_11 -> V_312 , V_314 , - 1 ) ;
if ( V_145 ) {
F_121 ( & V_11 -> V_206 ) ;
goto V_305;
}
if ( V_11 -> V_166 == V_167 && ! V_289 ) {
if ( F_26 ( V_11 , 1 ) )
F_21 ( V_11 , L_19
L_20 ) ;
}
F_121 ( & V_11 -> V_206 ) ;
return 0 ;
V_305:
F_136 ( & V_11 -> V_304 ) ;
F_137 ( & V_11 -> V_301 ) ;
return V_145 ;
}
void F_138 ( struct V_10 * V_11 )
{
if ( ! F_34 ( & V_11 -> V_312 . V_315 ) ) {
F_21 ( V_11 , L_21 ) ;
F_59 ( V_11 ) ;
}
F_95 ( V_11 ) ;
if ( V_11 -> V_166 == V_167 )
F_30 ( V_11 ) ;
F_139 ( & V_11 -> V_312 ) ;
F_136 ( & V_11 -> V_304 ) ;
F_137 ( & V_11 -> V_301 ) ;
}
void F_140 ( struct V_10 * V_11 )
{
F_118 ( & V_11 -> V_206 ) ;
if ( ! F_34 ( & V_11 -> V_312 . V_315 ) ) {
enum V_316 V_317 = V_11 -> V_79 ;
F_56 ( V_11 ) ;
F_59 ( V_11 ) ;
V_11 -> V_79 = V_317 ;
}
F_121 ( & V_11 -> V_206 ) ;
}
int F_141 ( struct V_10 * V_11 )
{
int V_145 = 0 ;
F_118 ( & V_11 -> V_206 ) ;
if ( ! F_34 ( & V_11 -> V_312 . V_315 ) ) {
V_145 = F_58 ( V_11 ) ;
if ( V_145 ) {
F_121 ( & V_11 -> V_206 ) ;
return V_145 ;
}
F_60 ( V_11 ) ;
} else {
F_59 ( V_11 ) ;
}
F_121 ( & V_11 -> V_206 ) ;
F_13 ( V_29 , & V_11 -> V_27 ) ;
if ( V_11 -> V_79 == V_80 ) {
if ( V_11 -> V_166 == V_178 && V_11 -> V_88 [ 0 ] )
F_71 ( & V_11 -> V_88 [ 0 ] -> V_85 , & V_11 -> V_81 ) ;
V_145 = F_66 ( V_11 ) ;
}
return V_145 ;
}
