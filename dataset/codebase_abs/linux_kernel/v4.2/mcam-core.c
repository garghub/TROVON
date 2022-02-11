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
V_13 -> V_14 . V_20 = V_21 ;
F_5 ( & V_13 -> V_14 . V_22 ) ;
F_6 ( V_13 , 0 , V_11 -> V_16 . V_17 ) ;
F_7 ( V_13 , V_23 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
int V_3 ;
V_11 -> V_24 = - 1 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_25 ; V_3 ++ ) {
F_9 ( V_3 , & V_11 -> V_26 ) ;
F_9 ( V_27 + V_3 , & V_11 -> V_26 ) ;
}
}
static inline int F_10 ( struct V_10 * V_11 )
{
return F_11 ( V_28 , & V_11 -> V_26 ) ;
}
static void F_12 ( struct V_10 * V_11 , int V_29 )
{
if ( V_29 )
F_13 ( V_28 , & V_11 -> V_26 ) ;
else
F_9 ( V_28 , & V_11 -> V_26 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
F_15 ( V_11 , V_30 , V_31 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_17 ( V_11 , V_30 , V_31 ) ;
}
static void F_18 ( struct V_10 * V_32 )
{
F_19 ( V_32 , L_1 ,
V_32 -> V_33 [ 0 ] , V_32 -> V_33 [ 1 ] , V_32 -> V_33 [ 2 ] ) ;
F_20 ( V_32 , V_34 , V_32 -> V_33 [ 0 ] ) ;
F_20 ( V_32 , V_35 , V_32 -> V_33 [ 1 ] ) ;
F_20 ( V_32 , V_36 , V_32 -> V_33 [ 2 ] ) ;
if ( ! V_32 -> V_37 ) {
if ( V_32 -> V_38 > 4 || V_32 -> V_38 <= 0 ) {
F_21 ( V_32 , L_2 ) ;
V_32 -> V_38 = 1 ;
}
F_20 ( V_32 , V_39 ,
V_40 | F_22 ( V_32 -> V_38 ) ) ;
F_20 ( V_32 , V_41 ,
( V_32 -> V_42 << 29 ) | V_32 -> V_43 ) ;
V_32 -> V_37 = true ;
}
}
static void F_23 ( struct V_10 * V_32 )
{
F_20 ( V_32 , V_39 , 0x0 ) ;
F_20 ( V_32 , V_34 , 0x0 ) ;
F_20 ( V_32 , V_35 , 0x0 ) ;
F_20 ( V_32 , V_36 , 0x0 ) ;
V_32 -> V_37 = false ;
}
static bool F_24 ( T_2 V_44 )
{
struct V_1 * V_45 ;
V_45 = F_1 ( V_44 ) ;
return V_45 -> V_46 ;
}
static void F_25 ( struct V_10 * V_11 ,
unsigned V_12 , T_3 V_47 )
{
struct V_48 * V_49 = & V_11 -> V_16 ;
T_1 V_50 = V_49 -> V_51 * V_49 -> V_52 ;
T_3 V_53 , V_54 = 0 , V_55 = 0 ;
V_53 = V_47 ;
switch ( V_49 -> V_2 ) {
case V_56 :
V_54 = V_53 + V_50 ;
V_55 = V_54 + V_50 / 4 ;
break;
case V_57 :
V_55 = V_53 + V_50 ;
V_54 = V_55 + V_50 / 4 ;
break;
default:
break;
}
F_20 ( V_11 , V_58 + V_12 * 4 , V_53 ) ;
if ( F_24 ( V_49 -> V_2 ) ) {
F_20 ( V_11 , V_59 + V_12 * 4 , V_54 ) ;
F_20 ( V_11 , V_60 + V_12 * 4 , V_55 ) ;
}
}
static int F_26 ( struct V_10 * V_11 , int V_61 )
{
int V_3 ;
F_12 ( V_11 , 1 ) ;
if ( V_61 )
V_11 -> V_62 = V_62 ;
else
V_11 -> V_62 = V_11 -> V_16 . V_17 ;
if ( V_63 > 3 )
V_63 = 3 ;
V_11 -> V_25 = 0 ;
for ( V_3 = 0 ; V_3 < V_63 ; V_3 ++ ) {
V_11 -> V_64 [ V_3 ] = F_27 ( V_11 -> V_65 ,
V_11 -> V_62 , V_11 -> V_66 + V_3 ,
V_67 ) ;
if ( V_11 -> V_64 [ V_3 ] == NULL ) {
F_21 ( V_11 , L_3 ) ;
break;
}
( V_11 -> V_25 ) ++ ;
}
switch ( V_11 -> V_25 ) {
case 1 :
F_28 ( V_11 -> V_65 , V_11 -> V_62 ,
V_11 -> V_64 [ 0 ] , V_11 -> V_66 [ 0 ] ) ;
V_11 -> V_25 = 0 ;
case 0 :
F_29 ( V_11 , L_4 ) ;
return - V_68 ;
case 2 :
if ( V_63 > 2 )
F_21 ( V_11 , L_5 ) ;
break;
}
return 0 ;
}
static void F_30 ( struct V_10 * V_11 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_25 ; V_3 ++ ) {
F_28 ( V_11 -> V_65 , V_11 -> V_62 ,
V_11 -> V_64 [ V_3 ] , V_11 -> V_66 [ V_3 ] ) ;
V_11 -> V_64 [ V_3 ] = NULL ;
}
V_11 -> V_25 = 0 ;
}
static void F_31 ( struct V_10 * V_11 )
{
F_25 ( V_11 , 0 , V_11 -> V_66 [ 0 ] ) ;
F_25 ( V_11 , 1 , V_11 -> V_66 [ 1 ] ) ;
if ( V_11 -> V_25 > 2 ) {
F_25 ( V_11 , 2 , V_11 -> V_66 [ 2 ] ) ;
F_17 ( V_11 , V_69 , V_70 ) ;
} else
F_15 ( V_11 , V_69 , V_70 ) ;
if ( V_11 -> V_71 == V_72 )
F_20 ( V_11 , V_73 , 0 ) ;
}
static void F_32 ( unsigned long V_74 )
{
struct V_10 * V_11 = (struct V_10 * ) V_74 ;
int V_3 ;
unsigned long V_26 ;
struct V_6 * V_75 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_25 ; V_3 ++ ) {
int V_77 = V_11 -> V_24 ;
if ( V_11 -> V_78 != V_79 || V_77 < 0 )
break;
if ( ++ ( V_11 -> V_24 ) >= V_11 -> V_25 )
V_11 -> V_24 = 0 ;
if ( ! F_11 ( V_77 , & V_11 -> V_26 ) )
continue;
if ( F_34 ( & V_11 -> V_80 ) ) {
V_11 -> V_81 . V_82 ++ ;
break;
}
V_11 -> V_81 . V_83 ++ ;
F_9 ( V_77 , & V_11 -> V_26 ) ;
V_75 = F_35 ( & V_11 -> V_80 , struct V_6 ,
V_84 ) ;
F_36 ( & V_75 -> V_84 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
memcpy ( F_38 ( & V_75 -> V_9 , 0 ) , V_11 -> V_64 [ V_77 ] ,
V_11 -> V_16 . V_17 ) ;
F_4 ( V_11 , V_77 , & V_75 -> V_9 ) ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
}
F_37 ( & V_11 -> V_76 , V_26 ) ;
}
static int F_39 ( struct V_10 * V_11 )
{
if ( V_11 -> V_25 > 0 && V_11 -> V_62 < V_11 -> V_16 . V_17 )
F_30 ( V_11 ) ;
if ( V_11 -> V_25 == 0 )
return F_26 ( V_11 , 0 ) ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 , int V_12 )
{
F_41 ( & V_11 -> V_85 ) ;
}
static inline int F_26 ( struct V_10 * V_11 , int V_61 )
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
struct V_6 * V_75 ;
T_3 V_86 ;
struct V_7 * V_8 ;
if ( F_34 ( & V_11 -> V_80 ) ) {
V_75 = V_11 -> V_87 [ V_12 ^ 0x1 ] ;
F_13 ( V_88 , & V_11 -> V_26 ) ;
V_11 -> V_81 . V_82 ++ ;
} else {
V_75 = F_35 ( & V_11 -> V_80 , struct V_6 ,
V_84 ) ;
F_36 ( & V_75 -> V_84 ) ;
F_9 ( V_88 , & V_11 -> V_26 ) ;
}
V_11 -> V_87 [ V_12 ] = V_75 ;
V_8 = & V_75 -> V_9 ;
V_86 = F_43 ( V_8 , 0 ) ;
F_25 ( V_11 , V_12 , V_86 ) ;
}
static void F_44 ( struct V_10 * V_11 )
{
F_15 ( V_11 , V_69 , V_70 ) ;
V_11 -> V_25 = 2 ;
F_42 ( V_11 , 0 ) ;
F_42 ( V_11 , 1 ) ;
}
static void F_45 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_75 = V_11 -> V_87 [ V_12 ] ;
if ( ! F_11 ( V_88 , & V_11 -> V_26 ) ) {
V_11 -> V_81 . V_83 ++ ;
V_11 -> V_87 [ V_12 ] = NULL ;
F_4 ( V_11 , V_12 , & V_75 -> V_9 ) ;
}
F_42 ( V_11 , V_12 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
struct V_6 * V_75 ;
V_75 = F_35 ( & V_11 -> V_80 , struct V_6 , V_84 ) ;
F_36 ( & V_75 -> V_84 ) ;
F_17 ( V_11 , V_69 , V_89 ) ;
F_20 ( V_11 , V_90 , V_75 -> V_91 ) ;
F_20 ( V_11 , V_92 ,
V_75 -> V_93 * sizeof( struct V_94 ) ) ;
F_20 ( V_11 , V_95 , 0 ) ;
F_20 ( V_11 , V_96 , 0 ) ;
F_15 ( V_11 , V_69 , V_89 ) ;
V_11 -> V_87 [ 0 ] = V_75 ;
}
static void F_47 ( struct V_10 * V_11 )
{
if ( F_34 ( & V_11 -> V_80 ) ) {
F_13 ( V_97 , & V_11 -> V_26 ) ;
return;
}
F_17 ( V_11 , V_69 , V_98 ) ;
F_46 ( V_11 ) ;
V_11 -> V_25 = 3 ;
}
static void F_48 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_75 = V_11 -> V_87 [ 0 ] ;
if ( V_11 -> V_78 != V_79 )
return;
if ( ! F_34 ( & V_11 -> V_80 ) ) {
F_46 ( V_11 ) ;
F_14 ( V_11 ) ;
} else {
F_13 ( V_97 , & V_11 -> V_26 ) ;
V_11 -> V_81 . V_82 ++ ;
V_11 -> V_87 [ 0 ] = NULL ;
}
V_11 -> V_81 . V_83 ++ ;
F_4 ( V_11 , V_12 , & V_75 -> V_9 ) ;
}
static void F_49 ( struct V_10 * V_11 )
{
F_47 ( V_11 ) ;
F_14 ( V_11 ) ;
F_9 ( V_97 , & V_11 -> V_26 ) ;
}
static inline void F_49 ( struct V_10 * V_11 )
{
return;
}
static void F_50 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = & V_11 -> V_16 ;
T_1 V_99 = 0 , V_100 = 0 , V_101 , V_102 ;
F_19 ( V_11 , L_6 ,
V_49 -> V_103 , V_49 -> V_17 / V_49 -> V_103 ) ;
V_101 = ( V_49 -> V_52 << V_104 ) & V_105 ;
V_102 = ( V_49 -> V_51 * 2 ) & V_106 ;
switch ( V_49 -> V_2 ) {
case V_107 :
case V_108 :
V_99 = V_49 -> V_51 * 2 ;
V_100 = 0 ;
break;
case V_56 :
case V_57 :
V_99 = V_49 -> V_51 ;
V_100 = V_49 -> V_51 / 2 ;
break;
default:
V_99 = V_49 -> V_103 ;
V_100 = 0 ;
break;
}
F_51 ( V_11 , V_109 , V_100 << 16 | V_99 ,
V_110 | V_111 ) ;
F_20 ( V_11 , V_112 , V_101 | V_102 ) ;
F_20 ( V_11 , V_113 , 0x0 ) ;
switch ( V_49 -> V_2 ) {
case V_56 :
case V_57 :
F_51 ( V_11 , V_30 ,
V_114 | V_115 | V_116 , V_117 ) ;
break;
case V_107 :
F_51 ( V_11 , V_30 ,
V_114 | V_118 | V_119 , V_117 ) ;
break;
case V_108 :
F_51 ( V_11 , V_30 ,
V_114 | V_118 | V_120 , V_117 ) ;
break;
case V_121 :
F_51 ( V_11 , V_30 ,
V_122 | V_123 | V_124 , V_117 ) ;
break;
case V_125 :
F_51 ( V_11 , V_30 ,
V_122 | V_126 | V_127 , V_117 ) ;
break;
case V_128 :
F_51 ( V_11 , V_30 ,
V_122 | V_129 , V_117 ) ;
break;
default:
F_29 ( V_11 , L_7 , V_49 -> V_2 ) ;
break;
}
F_51 ( V_11 , V_30 , V_130 , V_131 ) ;
if ( V_11 -> V_132 != V_133 )
F_15 ( V_11 , V_30 ,
V_134 | V_135 ) ;
}
static int F_52 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_9 ( V_97 , & V_11 -> V_26 ) ;
V_11 -> V_136 ( V_11 ) ;
F_50 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
return 0 ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_20 ( V_11 , V_137 , V_138 ) ;
F_15 ( V_11 , V_139 , V_138 ) ;
}
static void F_54 ( struct V_10 * V_11 )
{
F_17 ( V_11 , V_139 , V_138 ) ;
}
static void F_55 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_17 ( V_11 , V_69 , V_140 ) ;
F_17 ( V_11 , V_30 , V_31 ) ;
F_51 ( V_11 , V_41 , 2 , V_141 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
}
static void F_56 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_9 ( V_97 , & V_11 -> V_26 ) ;
F_16 ( V_11 ) ;
V_11 -> V_78 = V_142 ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
F_57 ( 150 ) ;
if ( F_11 ( V_143 , & V_11 -> V_26 ) )
F_29 ( V_11 , L_8 ) ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_54 ( V_11 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
}
static int F_58 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
int V_144 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
V_144 = V_11 -> V_145 ( V_11 ) ;
if ( V_144 ) {
F_37 ( & V_11 -> V_76 , V_26 ) ;
return V_144 ;
}
F_17 ( V_11 , V_69 , V_140 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
F_57 ( 5 ) ;
return 0 ;
}
static void F_59 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_15 ( V_11 , V_69 , V_140 ) ;
V_11 -> V_146 ( V_11 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
}
static int F_60 ( struct V_10 * V_11 )
{
return F_61 ( V_11 , V_147 , V_148 , 0 ) ;
}
static int F_62 ( struct V_10 * V_11 )
{
int V_144 ;
if ( V_11 -> V_78 != V_149 )
F_21 ( V_11 , L_9 ,
V_11 -> V_78 ) ;
V_144 = F_60 ( V_11 ) ;
V_11 -> V_78 = V_142 ;
F_59 ( V_11 ) ;
return V_144 ;
}
static int F_63 ( struct V_10 * V_11 )
{
struct V_150 V_151 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_152 = V_153 ;
V_151 . V_154 = V_155 ;
return F_61 ( V_11 , V_147 , V_156 , & V_151 ) ;
}
static int F_64 ( struct V_10 * V_11 )
{
struct V_157 V_158 = {
. V_159 = V_160 ,
} ;
int V_144 ;
F_65 ( & V_158 . V_158 , & V_11 -> V_16 , V_11 -> V_161 ) ;
V_144 = F_61 ( V_11 , V_147 , V_162 , 0 ) ;
if ( V_144 == 0 )
V_144 = F_61 ( V_11 , V_163 , V_164 , NULL , & V_158 ) ;
V_144 += F_63 ( V_11 ) ;
return V_144 ;
}
static int F_66 ( struct V_10 * V_11 )
{
int V_144 ;
unsigned long V_26 ;
if ( V_11 -> V_165 == V_166 && V_11 -> V_25 == 0 &&
F_26 ( V_11 , 0 ) )
return - V_68 ;
if ( F_10 ( V_11 ) ) {
F_64 ( V_11 ) ;
V_144 = F_52 ( V_11 ) ;
if ( V_144 )
return V_144 ;
}
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_9 ( V_143 , & V_11 -> V_26 ) ;
F_8 ( V_11 ) ;
if ( V_11 -> V_167 )
V_11 -> V_167 ( V_11 ) ;
F_19 ( V_11 , L_10 ,
V_11 -> V_33 [ 0 ] , V_11 -> V_33 [ 1 ] , V_11 -> V_33 [ 2 ] ) ;
if ( V_11 -> V_132 == V_133 )
F_18 ( V_11 ) ;
else
F_23 ( V_11 ) ;
F_53 ( V_11 ) ;
V_11 -> V_78 = V_79 ;
if ( ! F_11 ( V_97 , & V_11 -> V_26 ) )
F_14 ( V_11 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
return 0 ;
}
static int F_67 ( struct V_168 * V_169 ,
const struct V_170 * V_49 , unsigned int * V_25 ,
unsigned int * V_171 , unsigned int V_172 [] ,
void * V_173 [] )
{
struct V_10 * V_11 = F_68 ( V_169 ) ;
int V_174 = ( V_11 -> V_165 == V_175 ) ? 3 : 2 ;
if ( V_49 && V_49 -> V_49 . V_176 . V_17 < V_11 -> V_16 . V_17 )
return - V_177 ;
V_172 [ 0 ] = V_49 ? V_49 -> V_49 . V_176 . V_17 : V_11 -> V_16 . V_17 ;
* V_171 = 1 ;
if ( * V_25 < V_174 )
* V_25 = V_174 ;
if ( V_11 -> V_165 == V_175 )
V_173 [ 0 ] = V_11 -> V_178 ;
else if ( V_11 -> V_165 == V_179 )
V_173 [ 0 ] = V_11 -> V_180 ;
return 0 ;
}
static void F_69 ( struct V_7 * V_8 )
{
struct V_6 * V_181 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_168 ) ;
unsigned long V_26 ;
int V_182 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
V_182 = ( V_11 -> V_78 == V_183 ) && ! F_34 ( & V_11 -> V_80 ) ;
F_70 ( & V_181 -> V_84 , & V_11 -> V_80 ) ;
if ( V_11 -> V_78 == V_79 && F_11 ( V_97 , & V_11 -> V_26 ) )
F_49 ( V_11 ) ;
F_37 ( & V_11 -> V_76 , V_26 ) ;
if ( V_182 )
F_66 ( V_11 ) ;
}
static void F_71 ( struct V_168 * V_169 ,
enum V_184 V_78 )
{
struct V_10 * V_11 = F_68 ( V_169 ) ;
struct V_6 * V_75 , * V_185 ;
unsigned long V_26 ;
unsigned V_3 ;
F_33 ( & V_11 -> V_76 , V_26 ) ;
F_72 (buf, node, &cam->buffers, queue) {
F_7 ( & V_75 -> V_9 , V_78 ) ;
F_73 ( & V_75 -> V_84 ) ;
}
for ( V_3 = 0 ; V_3 < V_186 ; V_3 ++ ) {
V_75 = V_11 -> V_87 [ V_3 ] ;
if ( V_75 ) {
F_7 ( & V_75 -> V_9 , V_78 ) ;
V_11 -> V_87 [ V_3 ] = NULL ;
}
}
F_37 ( & V_11 -> V_76 , V_26 ) ;
}
static int F_74 ( struct V_168 * V_169 , unsigned int V_187 )
{
struct V_10 * V_11 = F_68 ( V_169 ) ;
unsigned int V_12 ;
int V_144 ;
if ( V_11 -> V_78 != V_142 ) {
F_71 ( V_169 , V_188 ) ;
return - V_177 ;
}
V_11 -> V_81 . V_189 = 0 ;
V_11 -> V_81 . V_82 = 0 ;
V_11 -> V_81 . V_83 = 0 ;
V_11 -> V_18 = 0 ;
if ( V_11 -> V_165 != V_166 && F_34 ( & V_11 -> V_80 ) ) {
V_11 -> V_78 = V_183 ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_25 ; V_12 ++ )
F_9 ( V_27 + V_12 , & V_11 -> V_26 ) ;
V_144 = F_66 ( V_11 ) ;
if ( V_144 )
F_71 ( V_169 , V_188 ) ;
return V_144 ;
}
static void F_75 ( struct V_168 * V_169 )
{
struct V_10 * V_11 = F_68 ( V_169 ) ;
F_19 ( V_11 , L_11 ,
V_11 -> V_81 . V_189 , V_11 -> V_81 . V_82 ,
V_11 -> V_81 . V_83 ) ;
if ( V_11 -> V_78 == V_183 ) {
V_11 -> V_78 = V_142 ;
return;
}
if ( V_11 -> V_78 != V_79 )
return;
F_56 ( V_11 ) ;
if ( V_11 -> V_190 )
V_11 -> V_190 ( V_11 ) ;
F_71 ( V_169 , V_191 ) ;
}
static int F_76 ( struct V_7 * V_8 )
{
struct V_6 * V_181 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_168 ) ;
int V_192 = V_11 -> V_16 . V_17 / V_193 + 1 ;
V_181 -> V_194 = F_27 ( V_11 -> V_65 ,
V_192 * sizeof( struct V_94 ) ,
& V_181 -> V_91 , V_67 ) ;
if ( V_181 -> V_194 == NULL ) {
F_29 ( V_11 , L_12 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
struct V_6 * V_181 = F_2 ( V_8 ) ;
struct V_195 * V_195 = F_78 ( V_8 , 0 ) ;
struct V_94 * V_196 = V_181 -> V_194 ;
struct V_197 * V_198 ;
int V_3 ;
F_79 (sg_table->sgl, sg, sg_table->nents, i) {
V_196 -> V_199 = F_80 ( V_198 ) ;
V_196 -> V_200 = F_81 ( V_198 ) ;
V_196 ++ ;
}
return 0 ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_68 ( V_8 -> V_168 ) ;
struct V_6 * V_181 = F_2 ( V_8 ) ;
int V_192 = V_11 -> V_16 . V_17 / V_193 + 1 ;
F_28 ( V_11 -> V_65 , V_192 * sizeof( struct V_94 ) ,
V_181 -> V_194 , V_181 -> V_91 ) ;
}
static int F_83 ( struct V_10 * V_11 )
{
struct V_168 * V_169 = & V_11 -> V_201 ;
memset ( V_169 , 0 , sizeof( * V_169 ) ) ;
V_169 -> type = V_202 ;
V_169 -> V_203 = V_11 ;
V_169 -> V_204 = & V_11 -> V_205 ;
V_169 -> V_206 = V_207 ;
V_169 -> V_208 = V_209 | V_210 | V_211 | V_212 ;
V_169 -> V_213 = sizeof( struct V_6 ) ;
F_84 ( & V_11 -> V_80 ) ;
switch ( V_11 -> V_165 ) {
case V_175 :
#ifdef F_85
V_169 -> V_214 = & V_215 ;
V_169 -> V_216 = & V_217 ;
V_11 -> V_136 = F_44 ;
V_11 -> V_218 = F_45 ;
V_11 -> V_178 = F_86 ( V_11 -> V_65 ) ;
if ( F_87 ( V_11 -> V_178 ) )
return F_88 ( V_11 -> V_178 ) ;
#endif
break;
case V_179 :
#ifdef F_89
V_169 -> V_214 = & V_219 ;
V_169 -> V_216 = & V_220 ;
V_11 -> V_136 = F_47 ;
V_11 -> V_218 = F_48 ;
V_11 -> V_180 = F_90 ( V_11 -> V_65 ) ;
if ( F_87 ( V_11 -> V_180 ) )
return F_88 ( V_11 -> V_180 ) ;
#endif
break;
case V_166 :
#ifdef F_91
F_92 ( & V_11 -> V_85 , F_32 ,
( unsigned long ) V_11 ) ;
V_169 -> V_214 = & V_215 ;
V_169 -> V_216 = & V_221 ;
V_11 -> V_136 = F_31 ;
V_11 -> V_218 = F_40 ;
#endif
break;
}
return F_93 ( V_169 ) ;
}
static void F_94 ( struct V_10 * V_11 )
{
#ifdef F_85
if ( V_11 -> V_165 == V_175 )
F_95 ( V_11 -> V_178 ) ;
#endif
#ifdef F_89
if ( V_11 -> V_165 == V_179 )
F_96 ( V_11 -> V_180 ) ;
#endif
}
static int F_97 ( struct V_222 * V_222 , void * V_223 ,
struct V_224 * V_225 )
{
struct V_10 * V_11 = F_98 ( V_222 ) ;
strcpy ( V_225 -> V_226 , L_13 ) ;
strcpy ( V_225 -> V_227 , L_13 ) ;
F_99 ( V_225 -> V_228 , V_11 -> V_228 , sizeof( V_225 -> V_228 ) ) ;
V_225 -> V_229 = V_230 |
V_231 | V_232 ;
V_225 -> V_233 = V_225 -> V_229 | V_234 ;
return 0 ;
}
static int F_100 ( struct V_222 * V_235 ,
void * V_223 , struct V_236 * V_49 )
{
if ( V_49 -> V_237 >= V_4 )
return - V_177 ;
F_99 ( V_49 -> V_238 , V_5 [ V_49 -> V_237 ] . V_196 ,
sizeof( V_49 -> V_238 ) ) ;
V_49 -> V_2 = V_5 [ V_49 -> V_237 ] . V_2 ;
return 0 ;
}
static int F_101 ( struct V_222 * V_235 , void * V_223 ,
struct V_170 * V_49 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
struct V_1 * V_45 ;
struct V_48 * V_176 = & V_49 -> V_49 . V_176 ;
struct V_239 V_240 ;
struct V_157 V_158 = {
. V_159 = V_241 ,
} ;
int V_144 ;
V_45 = F_1 ( V_176 -> V_2 ) ;
V_176 -> V_2 = V_45 -> V_2 ;
F_65 ( & V_158 . V_158 , V_176 , V_45 -> V_161 ) ;
V_144 = F_61 ( V_11 , V_163 , V_164 , & V_240 , & V_158 ) ;
F_102 ( V_176 , & V_158 . V_158 ) ;
V_176 -> V_103 = V_176 -> V_51 * V_45 -> V_242 ;
switch ( V_45 -> V_2 ) {
case V_56 :
case V_57 :
V_176 -> V_17 = V_176 -> V_52 * V_176 -> V_103 * 3 / 2 ;
break;
default:
V_176 -> V_17 = V_176 -> V_52 * V_176 -> V_103 ;
break;
}
V_176 -> V_243 = V_244 ;
return V_144 ;
}
static int F_103 ( struct V_222 * V_235 , void * V_223 ,
struct V_170 * V_49 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
struct V_1 * V_45 ;
int V_144 ;
if ( V_11 -> V_78 != V_142 || F_104 ( & V_11 -> V_201 ) )
return - V_245 ;
V_45 = F_1 ( V_49 -> V_49 . V_176 . V_2 ) ;
V_144 = F_101 ( V_235 , V_223 , V_49 ) ;
if ( V_144 )
return V_144 ;
V_11 -> V_16 = V_49 -> V_49 . V_176 ;
V_11 -> V_161 = V_45 -> V_161 ;
if ( V_11 -> V_165 == V_166 ) {
V_144 = F_39 ( V_11 ) ;
if ( V_144 )
goto V_246;
}
F_12 ( V_11 , 1 ) ;
V_246:
return V_144 ;
}
static int F_105 ( struct V_222 * V_235 , void * V_223 ,
struct V_170 * V_45 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
V_45 -> V_49 . V_176 = V_11 -> V_16 ;
return 0 ;
}
static int F_106 ( struct V_222 * V_235 , void * V_223 ,
struct V_247 * V_248 )
{
if ( V_248 -> V_237 != 0 )
return - V_177 ;
V_248 -> type = V_249 ;
strcpy ( V_248 -> V_250 , L_14 ) ;
return 0 ;
}
static int F_107 ( struct V_222 * V_235 , void * V_223 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_108 ( struct V_222 * V_235 , void * V_223 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_177 ;
return 0 ;
}
static int F_109 ( struct V_222 * V_235 , void * V_223 ,
struct V_251 * V_252 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
int V_144 ;
V_144 = F_61 ( V_11 , V_253 , V_254 , V_252 ) ;
V_252 -> V_255 . V_256 . V_257 = V_63 ;
return V_144 ;
}
static int F_110 ( struct V_222 * V_235 , void * V_223 ,
struct V_251 * V_252 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
int V_144 ;
V_144 = F_61 ( V_11 , V_253 , V_258 , V_252 ) ;
V_252 -> V_255 . V_256 . V_257 = V_63 ;
return V_144 ;
}
static int F_111 ( struct V_222 * V_235 , void * V_223 ,
struct V_259 * V_172 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
struct V_1 * V_45 ;
struct V_260 V_261 = {
. V_237 = V_172 -> V_237 ,
. V_159 = V_160 ,
} ;
int V_144 ;
V_45 = F_1 ( V_172 -> V_262 ) ;
if ( V_45 -> V_2 != V_172 -> V_262 )
return - V_177 ;
V_261 . V_263 = V_45 -> V_161 ;
V_144 = F_61 ( V_11 , V_163 , V_264 , NULL , & V_261 ) ;
if ( V_144 )
return V_144 ;
if ( V_261 . V_265 == V_261 . V_266 &&
V_261 . V_267 == V_261 . V_268 ) {
V_172 -> type = V_269 ;
V_172 -> V_270 . V_51 = V_261 . V_265 ;
V_172 -> V_270 . V_52 = V_261 . V_267 ;
return 0 ;
}
V_172 -> type = V_271 ;
V_172 -> V_272 . V_265 = V_261 . V_265 ;
V_172 -> V_272 . V_266 = V_261 . V_266 ;
V_172 -> V_272 . V_267 = V_261 . V_267 ;
V_172 -> V_272 . V_268 = V_261 . V_268 ;
V_172 -> V_272 . V_273 = 1 ;
V_172 -> V_272 . V_274 = 1 ;
return 0 ;
}
static int F_112 ( struct V_222 * V_235 , void * V_223 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
struct V_1 * V_45 ;
struct V_277 V_278 = {
. V_237 = V_276 -> V_237 ,
. V_51 = V_276 -> V_51 ,
. V_52 = V_276 -> V_52 ,
. V_159 = V_160 ,
} ;
int V_144 ;
V_45 = F_1 ( V_276 -> V_262 ) ;
if ( V_45 -> V_2 != V_276 -> V_262 )
return - V_177 ;
V_278 . V_263 = V_45 -> V_161 ;
V_144 = F_61 ( V_11 , V_163 , V_279 , NULL , & V_278 ) ;
if ( V_144 )
return V_144 ;
V_276 -> type = V_280 ;
V_276 -> V_270 = V_278 . V_276 ;
return 0 ;
}
static int F_113 ( struct V_222 * V_222 , void * V_223 ,
struct V_281 * V_282 )
{
struct V_10 * V_11 = F_98 ( V_222 ) ;
if ( V_282 -> V_282 > V_11 -> V_283 - 4 )
return - V_177 ;
V_282 -> V_284 = F_114 ( V_11 , V_282 -> V_282 ) ;
V_282 -> V_285 = 4 ;
return 0 ;
}
static int F_115 ( struct V_222 * V_222 , void * V_223 ,
const struct V_281 * V_282 )
{
struct V_10 * V_11 = F_98 ( V_222 ) ;
if ( V_282 -> V_282 > V_11 -> V_283 - 4 )
return - V_177 ;
F_20 ( V_11 , V_282 -> V_282 , V_282 -> V_284 ) ;
return 0 ;
}
static int F_116 ( struct V_222 * V_235 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
int V_144 ;
F_117 ( & V_11 -> V_205 ) ;
V_144 = F_118 ( V_235 ) ;
if ( V_144 )
goto V_246;
if ( F_119 ( V_235 ) ) {
V_144 = F_58 ( V_11 ) ;
if ( V_144 )
goto V_246;
F_60 ( V_11 ) ;
F_12 ( V_11 , 1 ) ;
}
V_246:
F_120 ( & V_11 -> V_205 ) ;
if ( V_144 )
F_121 ( V_235 ) ;
return V_144 ;
}
static int F_122 ( struct V_222 * V_235 )
{
struct V_10 * V_11 = F_98 ( V_235 ) ;
bool V_286 ;
F_117 ( & V_11 -> V_205 ) ;
V_286 = F_119 ( V_235 ) ;
F_123 ( V_235 , NULL ) ;
if ( V_286 ) {
F_23 ( V_11 ) ;
F_59 ( V_11 ) ;
if ( V_11 -> V_165 == V_166 && V_287 )
F_30 ( V_11 ) ;
}
F_120 ( & V_11 -> V_205 ) ;
return 0 ;
}
static void F_124 ( struct V_10 * V_11 , int V_12 )
{
F_13 ( V_12 , & V_11 -> V_26 ) ;
F_9 ( V_143 , & V_11 -> V_26 ) ;
V_11 -> V_24 = V_12 ;
V_11 -> V_19 [ V_12 ] = V_11 -> V_18 ++ ;
V_11 -> V_81 . V_189 ++ ;
if ( V_11 -> V_78 != V_79 )
return;
V_11 -> V_218 ( V_11 , V_12 ) ;
}
int F_125 ( struct V_10 * V_11 , unsigned int V_288 )
{
unsigned int V_12 , V_289 = 0 ;
F_20 ( V_11 , V_137 , V_138 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_25 ; V_12 ++ )
if ( V_288 & ( V_290 << V_12 ) &&
F_11 ( V_27 + V_12 , & V_11 -> V_26 ) ) {
F_124 ( V_11 , V_12 ) ;
V_289 = 1 ;
F_9 ( V_27 + V_12 , & V_11 -> V_26 ) ;
if ( V_11 -> V_165 == V_179 )
break;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_25 ; V_12 ++ ) {
if ( V_288 & ( V_291 << V_12 ) ) {
F_13 ( V_27 + V_12 , & V_11 -> V_26 ) ;
V_289 = V_292 ;
}
}
if ( V_289 == V_292 ) {
F_13 ( V_143 , & V_11 -> V_26 ) ;
if ( V_11 -> V_165 == V_179 )
F_16 ( V_11 ) ;
}
return V_289 ;
}
int F_126 ( struct V_10 * V_11 )
{
struct V_293 V_294 = {
. type = L_15 ,
. V_295 = 0x42 >> 1 ,
. V_296 = & V_297 ,
} ;
int V_144 ;
if ( V_165 >= 0 )
V_11 -> V_165 = V_165 ;
if ( V_11 -> V_165 == V_179 &&
V_11 -> V_71 == V_72 ) {
F_127 ( V_298 L_16
L_17 ) ;
V_11 -> V_165 = V_166 ;
}
if ( ! F_128 ( V_11 -> V_165 ) ) {
F_127 ( V_298 L_18 ,
V_11 -> V_165 ) ;
return - V_177 ;
}
V_144 = F_129 ( V_11 -> V_65 , & V_11 -> V_299 ) ;
if ( V_144 )
return V_144 ;
F_130 ( & V_11 -> V_205 ) ;
V_11 -> V_78 = V_149 ;
F_12 ( V_11 , 1 ) ;
V_11 -> V_16 = V_300 ;
V_11 -> V_161 = V_301 ;
F_55 ( V_11 ) ;
V_144 = F_131 ( & V_11 -> V_302 , 10 ) ;
if ( V_144 )
goto V_303;
V_11 -> V_299 . V_302 = & V_11 -> V_302 ;
V_297 . V_304 = V_11 -> V_304 ;
V_297 . V_305 = V_11 -> V_305 ;
V_11 -> V_306 = V_294 . V_295 ;
V_11 -> V_307 = F_132 ( & V_11 -> V_299 ,
V_11 -> V_308 , & V_294 , NULL ) ;
if ( V_11 -> V_307 == NULL ) {
V_144 = - V_309 ;
goto V_303;
}
V_144 = F_62 ( V_11 ) ;
if ( V_144 )
goto V_303;
V_144 = F_83 ( V_11 ) ;
if ( V_144 )
goto V_303;
F_117 ( & V_11 -> V_205 ) ;
V_11 -> V_310 = V_311 ;
V_11 -> V_310 . V_299 = & V_11 -> V_299 ;
V_11 -> V_310 . V_204 = & V_11 -> V_205 ;
V_11 -> V_310 . V_84 = & V_11 -> V_201 ;
F_133 ( & V_11 -> V_310 , V_11 ) ;
V_144 = F_134 ( & V_11 -> V_310 , V_312 , - 1 ) ;
if ( V_144 ) {
F_120 ( & V_11 -> V_205 ) ;
goto V_303;
}
if ( V_11 -> V_165 == V_166 && ! V_287 ) {
if ( F_26 ( V_11 , 1 ) )
F_21 ( V_11 , L_19
L_20 ) ;
}
F_120 ( & V_11 -> V_205 ) ;
return 0 ;
V_303:
F_135 ( & V_11 -> V_302 ) ;
F_136 ( & V_11 -> V_299 ) ;
return V_144 ;
}
void F_137 ( struct V_10 * V_11 )
{
if ( ! F_34 ( & V_11 -> V_310 . V_313 ) ) {
F_21 ( V_11 , L_21 ) ;
F_59 ( V_11 ) ;
}
F_94 ( V_11 ) ;
if ( V_11 -> V_165 == V_166 )
F_30 ( V_11 ) ;
F_138 ( & V_11 -> V_310 ) ;
F_135 ( & V_11 -> V_302 ) ;
F_136 ( & V_11 -> V_299 ) ;
}
void F_139 ( struct V_10 * V_11 )
{
F_117 ( & V_11 -> V_205 ) ;
if ( ! F_34 ( & V_11 -> V_310 . V_313 ) ) {
enum V_314 V_315 = V_11 -> V_78 ;
F_56 ( V_11 ) ;
F_59 ( V_11 ) ;
V_11 -> V_78 = V_315 ;
}
F_120 ( & V_11 -> V_205 ) ;
}
int F_140 ( struct V_10 * V_11 )
{
int V_144 = 0 ;
F_117 ( & V_11 -> V_205 ) ;
if ( ! F_34 ( & V_11 -> V_310 . V_313 ) ) {
V_144 = F_58 ( V_11 ) ;
if ( V_144 ) {
F_120 ( & V_11 -> V_205 ) ;
return V_144 ;
}
F_60 ( V_11 ) ;
} else {
F_59 ( V_11 ) ;
}
F_120 ( & V_11 -> V_205 ) ;
F_13 ( V_28 , & V_11 -> V_26 ) ;
if ( V_11 -> V_78 == V_79 ) {
if ( V_11 -> V_165 == V_179 && V_11 -> V_87 [ 0 ] )
F_70 ( & V_11 -> V_87 [ 0 ] -> V_84 , & V_11 -> V_80 ) ;
V_144 = F_66 ( V_11 ) ;
}
return V_144 ;
}
