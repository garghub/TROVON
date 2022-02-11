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
for ( V_3 = 0 ; V_3 < V_11 -> V_22 ; V_3 ++ ) {
F_8 ( V_3 , & V_11 -> V_23 ) ;
F_8 ( V_24 + V_3 , & V_11 -> V_23 ) ;
}
}
static inline int F_9 ( struct V_10 * V_11 )
{
return F_10 ( V_25 , & V_11 -> V_23 ) ;
}
static void F_11 ( struct V_10 * V_11 , int V_26 )
{
if ( V_26 )
F_12 ( V_25 , & V_11 -> V_23 ) ;
else
F_8 ( V_25 , & V_11 -> V_23 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_14 ( V_11 , V_27 , V_28 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_16 ( V_11 , V_27 , V_28 ) ;
}
static void F_17 ( struct V_10 * V_29 )
{
F_18 ( V_29 , L_1 ,
V_29 -> V_30 [ 0 ] , V_29 -> V_30 [ 1 ] , V_29 -> V_30 [ 2 ] ) ;
F_19 ( V_29 , V_31 , V_29 -> V_30 [ 0 ] ) ;
F_19 ( V_29 , V_32 , V_29 -> V_30 [ 1 ] ) ;
F_19 ( V_29 , V_33 , V_29 -> V_30 [ 2 ] ) ;
if ( ! V_29 -> V_34 ) {
if ( V_29 -> V_35 > 4 || V_29 -> V_35 <= 0 ) {
F_20 ( V_29 , L_2 ) ;
V_29 -> V_35 = 1 ;
}
F_19 ( V_29 , V_36 ,
V_37 | F_21 ( V_29 -> V_35 ) ) ;
F_19 ( V_29 , V_38 ,
( V_29 -> V_39 << 29 ) | V_29 -> V_40 ) ;
V_29 -> V_34 = true ;
}
}
static void F_22 ( struct V_10 * V_29 )
{
F_19 ( V_29 , V_36 , 0x0 ) ;
F_19 ( V_29 , V_31 , 0x0 ) ;
F_19 ( V_29 , V_32 , 0x0 ) ;
F_19 ( V_29 , V_33 , 0x0 ) ;
V_29 -> V_34 = false ;
}
static int F_23 ( struct V_10 * V_11 , int V_41 )
{
int V_3 ;
F_11 ( V_11 , 1 ) ;
if ( V_41 )
V_11 -> V_42 = V_42 ;
else
V_11 -> V_42 = V_11 -> V_16 . V_17 ;
if ( V_43 > 3 )
V_43 = 3 ;
V_11 -> V_22 = 0 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
V_11 -> V_44 [ V_3 ] = F_24 ( V_11 -> V_45 ,
V_11 -> V_42 , V_11 -> V_46 + V_3 ,
V_47 ) ;
if ( V_11 -> V_44 [ V_3 ] == NULL ) {
F_20 ( V_11 , L_3 ) ;
break;
}
( V_11 -> V_22 ) ++ ;
}
switch ( V_11 -> V_22 ) {
case 1 :
F_25 ( V_11 -> V_45 , V_11 -> V_42 ,
V_11 -> V_44 [ 0 ] , V_11 -> V_46 [ 0 ] ) ;
V_11 -> V_22 = 0 ;
case 0 :
F_26 ( V_11 , L_4 ) ;
return - V_48 ;
case 2 :
if ( V_43 > 2 )
F_20 ( V_11 , L_5 ) ;
break;
}
return 0 ;
}
static void F_27 ( struct V_10 * V_11 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_22 ; V_3 ++ ) {
F_25 ( V_11 -> V_45 , V_11 -> V_42 ,
V_11 -> V_44 [ V_3 ] , V_11 -> V_46 [ V_3 ] ) ;
V_11 -> V_44 [ V_3 ] = NULL ;
}
V_11 -> V_22 = 0 ;
}
static void F_28 ( struct V_10 * V_11 )
{
F_19 ( V_11 , V_49 , V_11 -> V_46 [ 0 ] ) ;
F_19 ( V_11 , V_50 , V_11 -> V_46 [ 1 ] ) ;
if ( V_11 -> V_22 > 2 ) {
F_19 ( V_11 , V_51 , V_11 -> V_46 [ 2 ] ) ;
F_16 ( V_11 , V_52 , V_53 ) ;
} else
F_14 ( V_11 , V_52 , V_53 ) ;
if ( V_11 -> V_54 == V_55 )
F_19 ( V_11 , V_56 , 0 ) ;
}
static void F_29 ( unsigned long V_57 )
{
struct V_10 * V_11 = (struct V_10 * ) V_57 ;
int V_3 ;
unsigned long V_23 ;
struct V_6 * V_58 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_22 ; V_3 ++ ) {
int V_60 = V_11 -> V_21 ;
if ( V_11 -> V_61 != V_62 || V_60 < 0 )
break;
if ( ++ ( V_11 -> V_21 ) >= V_11 -> V_22 )
V_11 -> V_21 = 0 ;
if ( ! F_10 ( V_60 , & V_11 -> V_23 ) )
continue;
if ( F_31 ( & V_11 -> V_63 ) ) {
V_11 -> V_64 . V_65 ++ ;
break;
}
V_11 -> V_64 . V_66 ++ ;
F_8 ( V_60 , & V_11 -> V_23 ) ;
V_58 = F_32 ( & V_11 -> V_63 , struct V_6 ,
V_67 ) ;
F_33 ( & V_58 -> V_67 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
memcpy ( F_35 ( & V_58 -> V_9 , 0 ) , V_11 -> V_44 [ V_60 ] ,
V_11 -> V_16 . V_17 ) ;
F_4 ( V_11 , V_60 , & V_58 -> V_9 ) ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
}
F_34 ( & V_11 -> V_59 , V_23 ) ;
}
static int F_36 ( struct V_10 * V_11 )
{
if ( V_11 -> V_22 > 0 && V_11 -> V_42 < V_11 -> V_16 . V_17 )
F_27 ( V_11 ) ;
if ( V_11 -> V_22 == 0 )
return F_23 ( V_11 , 0 ) ;
return 0 ;
}
static void F_37 ( struct V_10 * V_11 , int V_12 )
{
F_38 ( & V_11 -> V_68 ) ;
}
static inline int F_23 ( struct V_10 * V_11 , int V_41 )
{
return 0 ;
}
static inline void F_27 ( struct V_10 * V_11 )
{
return;
}
static inline int F_36 ( struct V_10 * V_11 )
{
return 0 ;
}
static bool F_39 ( T_2 V_69 )
{
struct V_1 * V_70 ;
V_70 = F_1 ( V_69 ) ;
return V_70 -> V_71 ;
}
static void F_40 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_58 ;
struct V_72 * V_73 = & V_11 -> V_16 ;
T_3 V_74 ;
T_1 V_75 = V_73 -> V_76 * V_73 -> V_77 ;
struct V_7 * V_8 ;
if ( F_31 ( & V_11 -> V_63 ) ) {
V_58 = V_11 -> V_78 [ V_12 ^ 0x1 ] ;
F_12 ( V_79 , & V_11 -> V_23 ) ;
V_11 -> V_64 . V_65 ++ ;
} else {
V_58 = F_32 ( & V_11 -> V_63 , struct V_6 ,
V_67 ) ;
F_33 ( & V_58 -> V_67 ) ;
F_8 ( V_79 , & V_11 -> V_23 ) ;
}
V_11 -> V_78 [ V_12 ] = V_58 ;
V_8 = & V_58 -> V_9 ;
V_74 = F_41 ( V_8 , 0 ) ;
V_58 -> V_80 . V_81 = V_74 ;
switch ( V_11 -> V_16 . V_2 ) {
case V_82 :
V_58 -> V_80 . V_83 = V_58 -> V_80 . V_81 + V_75 ;
V_58 -> V_80 . V_84 = V_58 -> V_80 . V_83 + V_75 / 2 ;
break;
case V_85 :
V_58 -> V_80 . V_83 = V_58 -> V_80 . V_81 + V_75 ;
V_58 -> V_80 . V_84 = V_58 -> V_80 . V_83 + V_75 / 4 ;
break;
case V_86 :
V_58 -> V_80 . V_84 = V_58 -> V_80 . V_81 + V_75 ;
V_58 -> V_80 . V_83 = V_58 -> V_80 . V_84 + V_75 / 4 ;
break;
default:
break;
}
F_19 ( V_11 , V_12 == 0 ? V_49 : V_50 , V_58 -> V_80 . V_81 ) ;
if ( F_39 ( V_73 -> V_2 ) ) {
F_19 ( V_11 , V_12 == 0 ?
V_87 : V_88 , V_58 -> V_80 . V_83 ) ;
F_19 ( V_11 , V_12 == 0 ?
V_89 : V_90 , V_58 -> V_80 . V_84 ) ;
}
}
static void F_42 ( struct V_10 * V_11 )
{
F_14 ( V_11 , V_52 , V_53 ) ;
V_11 -> V_22 = 2 ;
F_40 ( V_11 , 0 ) ;
F_40 ( V_11 , 1 ) ;
}
static void F_43 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_58 = V_11 -> V_78 [ V_12 ] ;
if ( ! F_10 ( V_79 , & V_11 -> V_23 ) ) {
V_11 -> V_64 . V_66 ++ ;
F_4 ( V_11 , V_12 , & V_58 -> V_9 ) ;
}
F_40 ( V_11 , V_12 ) ;
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_6 * V_58 ;
V_58 = F_32 ( & V_11 -> V_63 , struct V_6 , V_67 ) ;
F_33 ( & V_58 -> V_67 ) ;
F_16 ( V_11 , V_52 , V_91 ) ;
F_19 ( V_11 , V_92 , V_58 -> V_93 ) ;
F_19 ( V_11 , V_94 ,
V_58 -> V_95 * sizeof( struct V_96 ) ) ;
F_19 ( V_11 , V_97 , 0 ) ;
F_19 ( V_11 , V_98 , 0 ) ;
F_14 ( V_11 , V_52 , V_91 ) ;
V_11 -> V_78 [ 0 ] = V_58 ;
}
static void F_45 ( struct V_10 * V_11 )
{
if ( F_31 ( & V_11 -> V_63 ) ) {
F_12 ( V_99 , & V_11 -> V_23 ) ;
return;
}
F_16 ( V_11 , V_52 , V_100 ) ;
F_44 ( V_11 ) ;
V_11 -> V_22 = 3 ;
}
static void F_46 ( struct V_10 * V_11 , int V_12 )
{
struct V_6 * V_58 = V_11 -> V_78 [ 0 ] ;
if ( V_11 -> V_61 != V_62 )
return;
if ( ! F_31 ( & V_11 -> V_63 ) ) {
F_44 ( V_11 ) ;
F_13 ( V_11 ) ;
} else {
F_12 ( V_99 , & V_11 -> V_23 ) ;
V_11 -> V_64 . V_65 ++ ;
V_11 -> V_78 [ 0 ] = NULL ;
}
V_11 -> V_64 . V_66 ++ ;
F_4 ( V_11 , V_12 , & V_58 -> V_9 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
F_45 ( V_11 ) ;
F_13 ( V_11 ) ;
F_8 ( V_99 , & V_11 -> V_23 ) ;
}
static inline void F_47 ( struct V_10 * V_11 )
{
return;
}
static void F_48 ( struct V_10 * V_11 )
{
struct V_72 * V_73 = & V_11 -> V_16 ;
T_1 V_101 = 0 , V_102 = 0 , V_103 , V_104 ;
F_18 ( V_11 , L_6 ,
V_73 -> V_105 , V_73 -> V_17 / V_73 -> V_105 ) ;
V_103 = ( V_73 -> V_77 << V_106 ) & V_107 ;
V_104 = ( V_73 -> V_76 * 2 ) & V_108 ;
switch ( V_73 -> V_2 ) {
case V_109 :
case V_110 :
V_101 = V_73 -> V_76 * 2 ;
V_102 = 0 ;
break;
case V_111 :
V_103 = ( V_73 -> V_17 / V_73 -> V_105 ) << V_106 ;
V_101 = V_73 -> V_105 ;
V_102 = 0 ;
break;
case V_82 :
case V_85 :
case V_86 :
V_101 = V_73 -> V_76 ;
V_102 = V_73 -> V_76 / 2 ;
break;
default:
V_101 = V_73 -> V_105 ;
V_102 = 0 ;
}
F_49 ( V_11 , V_112 , V_102 << 16 | V_101 ,
V_113 | V_114 ) ;
F_19 ( V_11 , V_115 , V_103 | V_104 ) ;
F_19 ( V_11 , V_116 , 0x0 ) ;
switch ( V_73 -> V_2 ) {
case V_82 :
F_49 ( V_11 , V_27 ,
V_117 | V_118 | V_119 , V_120 ) ;
break;
case V_85 :
case V_86 :
F_49 ( V_11 , V_27 ,
V_117 | V_121 | V_119 , V_120 ) ;
break;
case V_109 :
F_49 ( V_11 , V_27 ,
V_117 | V_122 | V_123 , V_120 ) ;
break;
case V_110 :
F_49 ( V_11 , V_27 ,
V_117 | V_122 | V_124 , V_120 ) ;
break;
case V_111 :
F_49 ( V_11 , V_27 ,
V_117 | V_122 | V_124 , V_120 ) ;
break;
case V_125 :
F_49 ( V_11 , V_27 ,
V_126 | V_127 | V_128 , V_120 ) ;
break;
case V_129 :
F_49 ( V_11 , V_27 ,
V_126 | V_130 | V_131 , V_120 ) ;
break;
default:
F_26 ( V_11 , L_7 , V_73 -> V_2 ) ;
break;
}
F_49 ( V_11 , V_27 , V_132 , V_133 ) ;
if ( V_11 -> V_134 != V_135 )
F_14 ( V_11 , V_27 ,
V_136 | V_137 ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_8 ( V_99 , & V_11 -> V_23 ) ;
V_11 -> V_138 ( V_11 ) ;
F_48 ( V_11 ) ;
F_11 ( V_11 , 0 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
return 0 ;
}
static void F_51 ( struct V_10 * V_11 )
{
F_19 ( V_11 , V_139 , V_140 ) ;
F_14 ( V_11 , V_141 , V_140 ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
F_16 ( V_11 , V_141 , V_140 ) ;
}
static void F_53 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_16 ( V_11 , V_52 , V_142 ) ;
F_16 ( V_11 , V_27 , V_28 ) ;
F_49 ( V_11 , V_38 , 2 , V_143 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
}
static void F_54 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_8 ( V_99 , & V_11 -> V_23 ) ;
F_15 ( V_11 ) ;
V_11 -> V_61 = V_144 ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
F_55 ( 150 ) ;
if ( F_10 ( V_145 , & V_11 -> V_23 ) )
F_26 ( V_11 , L_8 ) ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_52 ( V_11 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
}
static int F_56 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
int V_146 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
V_146 = V_11 -> V_147 ( V_11 ) ;
if ( V_146 ) {
F_34 ( & V_11 -> V_59 , V_23 ) ;
return V_146 ;
}
F_16 ( V_11 , V_52 , V_142 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
F_55 ( 5 ) ;
return 0 ;
}
static void F_57 ( struct V_10 * V_11 )
{
unsigned long V_23 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_14 ( V_11 , V_52 , V_142 ) ;
V_11 -> V_148 ( V_11 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
}
static int F_58 ( struct V_10 * V_11 )
{
return F_59 ( V_11 , V_149 , V_150 , 0 ) ;
}
static int F_60 ( struct V_10 * V_11 )
{
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_61 != V_152 )
F_20 ( V_11 , L_9 ,
V_11 -> V_61 ) ;
V_146 = F_58 ( V_11 ) ;
V_11 -> V_61 = V_144 ;
F_57 ( V_11 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_63 ( struct V_10 * V_11 )
{
struct V_153 V_154 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_155 = V_156 ;
V_154 . V_157 = V_158 ;
return F_59 ( V_11 , V_149 , V_159 , & V_154 ) ;
}
static int F_64 ( struct V_10 * V_11 )
{
struct V_160 V_161 ;
int V_146 ;
F_65 ( & V_161 , & V_11 -> V_16 , V_11 -> V_162 ) ;
V_146 = F_59 ( V_11 , V_149 , V_163 , 0 ) ;
if ( V_146 == 0 )
V_146 = F_59 ( V_11 , V_164 , V_165 , & V_161 ) ;
V_146 += F_63 ( V_11 ) ;
return V_146 ;
}
static int F_66 ( struct V_10 * V_11 )
{
int V_146 ;
unsigned long V_23 ;
if ( V_11 -> V_166 == V_167 && V_11 -> V_22 == 0 &&
F_23 ( V_11 , 0 ) )
return - V_48 ;
if ( F_9 ( V_11 ) ) {
F_64 ( V_11 ) ;
V_146 = F_50 ( V_11 ) ;
if ( V_146 )
return V_146 ;
}
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_8 ( V_145 , & V_11 -> V_23 ) ;
F_7 ( V_11 ) ;
if ( V_11 -> V_168 )
V_11 -> V_168 ( V_11 ) ;
F_18 ( V_11 , L_10 ,
V_11 -> V_30 [ 0 ] , V_11 -> V_30 [ 1 ] , V_11 -> V_30 [ 2 ] ) ;
if ( V_11 -> V_134 == V_135 )
F_17 ( V_11 ) ;
else
F_22 ( V_11 ) ;
F_51 ( V_11 ) ;
V_11 -> V_61 = V_62 ;
if ( ! F_10 ( V_99 , & V_11 -> V_23 ) )
F_13 ( V_11 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
return 0 ;
}
static int F_67 ( struct V_169 * V_170 ,
const struct V_171 * V_73 , unsigned int * V_22 ,
unsigned int * V_172 , unsigned int V_173 [] ,
void * V_174 [] )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
int V_175 = ( V_11 -> V_166 == V_176 ) ? 3 : 2 ;
V_173 [ 0 ] = V_11 -> V_16 . V_17 ;
* V_172 = 1 ;
if ( * V_22 < V_175 )
* V_22 = V_175 ;
if ( V_11 -> V_166 == V_176 )
V_174 [ 0 ] = V_11 -> V_177 ;
else if ( V_11 -> V_166 == V_178 )
V_174 [ 0 ] = V_11 -> V_179 ;
return 0 ;
}
static void F_69 ( struct V_7 * V_8 )
{
struct V_6 * V_180 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
unsigned long V_23 ;
int V_181 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
V_181 = ( V_11 -> V_61 == V_182 ) && ! F_31 ( & V_11 -> V_63 ) ;
F_70 ( & V_180 -> V_67 , & V_11 -> V_63 ) ;
if ( V_11 -> V_61 == V_62 && F_10 ( V_99 , & V_11 -> V_23 ) )
F_47 ( V_11 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
if ( V_181 )
F_66 ( V_11 ) ;
}
static int F_71 ( struct V_169 * V_170 , unsigned int V_183 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
unsigned int V_12 ;
if ( V_11 -> V_61 != V_144 ) {
F_72 ( & V_11 -> V_63 ) ;
return - V_184 ;
}
V_11 -> V_18 = 0 ;
if ( V_11 -> V_166 != V_167 && F_31 ( & V_11 -> V_63 ) ) {
V_11 -> V_61 = V_182 ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
F_8 ( V_24 + V_12 , & V_11 -> V_23 ) ;
return F_66 ( V_11 ) ;
}
static void F_73 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
unsigned long V_23 ;
if ( V_11 -> V_61 == V_182 ) {
V_11 -> V_61 = V_144 ;
return;
}
if ( V_11 -> V_61 != V_62 )
return;
F_54 ( V_11 ) ;
if ( V_11 -> V_185 )
V_11 -> V_185 ( V_11 ) ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_72 ( & V_11 -> V_63 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
}
static int F_74 ( struct V_7 * V_8 )
{
struct V_6 * V_180 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
int V_186 = V_11 -> V_16 . V_17 / V_187 + 1 ;
V_180 -> V_188 = F_24 ( V_11 -> V_45 ,
V_186 * sizeof( struct V_96 ) ,
& V_180 -> V_93 , V_47 ) ;
if ( V_180 -> V_188 == NULL ) {
F_26 ( V_11 , L_11 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_75 ( struct V_7 * V_8 )
{
struct V_6 * V_180 = F_2 ( V_8 ) ;
struct V_189 * V_189 = F_76 ( V_8 , 0 ) ;
struct V_96 * V_190 = V_180 -> V_188 ;
struct V_191 * V_192 ;
int V_3 ;
F_77 (sg_table->sgl, sg, sg_table->nents, i) {
V_190 -> V_193 = F_78 ( V_192 ) ;
V_190 -> V_194 = F_79 ( V_192 ) ;
V_190 ++ ;
}
return 0 ;
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
struct V_6 * V_180 = F_2 ( V_8 ) ;
int V_186 = V_11 -> V_16 . V_17 / V_187 + 1 ;
F_25 ( V_11 -> V_45 , V_186 * sizeof( struct V_96 ) ,
V_180 -> V_188 , V_180 -> V_93 ) ;
}
static int F_81 ( struct V_10 * V_11 )
{
struct V_169 * V_170 = & V_11 -> V_195 ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_170 -> type = V_196 ;
V_170 -> V_197 = V_11 ;
V_170 -> V_198 = & V_11 -> V_151 ;
F_72 ( & V_11 -> V_63 ) ;
switch ( V_11 -> V_166 ) {
case V_176 :
#ifdef F_82
V_170 -> V_199 = & V_200 ;
V_170 -> V_201 = & V_202 ;
V_170 -> V_203 = sizeof( struct V_6 ) ;
V_170 -> V_204 = V_205 | V_206 ;
V_11 -> V_138 = F_42 ;
V_11 -> V_207 = F_43 ;
V_11 -> V_177 = F_83 ( V_11 -> V_45 ) ;
if ( F_84 ( V_11 -> V_177 ) )
return F_85 ( V_11 -> V_177 ) ;
#endif
break;
case V_178 :
#ifdef F_86
V_170 -> V_199 = & V_208 ;
V_170 -> V_201 = & V_209 ;
V_170 -> V_203 = sizeof( struct V_6 ) ;
V_170 -> V_204 = V_205 | V_206 ;
V_11 -> V_138 = F_45 ;
V_11 -> V_207 = F_46 ;
V_11 -> V_179 = F_87 ( V_11 -> V_45 ) ;
if ( F_84 ( V_11 -> V_179 ) )
return F_85 ( V_11 -> V_179 ) ;
#endif
break;
case V_167 :
#ifdef F_88
F_89 ( & V_11 -> V_68 , F_29 ,
( unsigned long ) V_11 ) ;
V_170 -> V_199 = & V_200 ;
V_170 -> V_201 = & V_210 ;
V_170 -> V_203 = sizeof( struct V_6 ) ;
V_170 -> V_204 = V_205 ;
V_11 -> V_138 = F_28 ;
V_11 -> V_207 = F_37 ;
#endif
break;
}
return F_90 ( V_170 ) ;
}
static void F_91 ( struct V_10 * V_11 )
{
F_92 ( & V_11 -> V_195 ) ;
#ifdef F_82
if ( V_11 -> V_166 == V_176 )
F_93 ( V_11 -> V_177 ) ;
#endif
#ifdef F_86
if ( V_11 -> V_166 == V_178 )
F_94 ( V_11 -> V_179 ) ;
#endif
}
static int F_95 ( struct V_211 * V_212 , void * V_213 ,
enum V_214 type )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_96 ( & V_11 -> V_195 , type ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_97 ( struct V_211 * V_212 , void * V_213 ,
enum V_214 type )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_98 ( & V_11 -> V_195 , type ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_99 ( struct V_211 * V_212 , void * V_213 ,
struct V_216 * V_217 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_100 ( & V_11 -> V_195 , V_217 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_101 ( struct V_211 * V_212 , void * V_213 ,
struct V_218 * V_58 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_102 ( & V_11 -> V_195 , V_58 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_103 ( struct V_211 * V_212 , void * V_213 ,
struct V_218 * V_58 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_104 ( & V_11 -> V_195 , V_58 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_105 ( struct V_211 * V_212 , void * V_213 ,
struct V_218 * V_58 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_106 ( & V_11 -> V_195 , V_58 , V_212 -> V_219 & V_220 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_107 ( struct V_211 * V_211 , void * V_213 ,
struct V_221 * V_222 )
{
strcpy ( V_222 -> V_223 , L_12 ) ;
strcpy ( V_222 -> V_224 , L_12 ) ;
V_222 -> V_225 = V_226 |
V_227 | V_228 ;
V_222 -> V_229 = V_222 -> V_225 | V_230 ;
return 0 ;
}
static int F_108 ( struct V_211 * V_212 ,
void * V_213 , struct V_231 * V_73 )
{
if ( V_73 -> V_232 >= V_4 )
return - V_184 ;
F_109 ( V_73 -> V_233 , V_5 [ V_73 -> V_232 ] . V_190 ,
sizeof( V_73 -> V_233 ) ) ;
V_73 -> V_2 = V_5 [ V_73 -> V_232 ] . V_2 ;
return 0 ;
}
static int F_110 ( struct V_211 * V_212 , void * V_213 ,
struct V_171 * V_73 )
{
struct V_10 * V_11 = V_213 ;
struct V_1 * V_70 ;
struct V_72 * V_234 = & V_73 -> V_73 . V_234 ;
struct V_160 V_161 ;
int V_146 ;
V_70 = F_1 ( V_234 -> V_2 ) ;
V_234 -> V_2 = V_70 -> V_2 ;
F_65 ( & V_161 , V_234 , V_70 -> V_162 ) ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_235 , & V_161 ) ;
F_62 ( & V_11 -> V_151 ) ;
F_111 ( V_234 , & V_161 ) ;
switch ( V_70 -> V_2 ) {
case V_85 :
case V_86 :
V_234 -> V_105 = V_234 -> V_76 * 3 / 2 ;
break;
default:
V_234 -> V_105 = V_234 -> V_76 * V_70 -> V_236 ;
break;
}
V_234 -> V_17 = V_234 -> V_77 * V_234 -> V_105 ;
return V_146 ;
}
static int F_112 ( struct V_211 * V_212 , void * V_213 ,
struct V_171 * V_73 )
{
struct V_10 * V_11 = V_213 ;
struct V_1 * V_70 ;
int V_146 ;
if ( V_11 -> V_61 != V_144 || V_11 -> V_195 . V_237 > 0 )
return - V_238 ;
V_70 = F_1 ( V_73 -> V_73 . V_234 . V_2 ) ;
V_146 = F_110 ( V_212 , V_213 , V_73 ) ;
if ( V_146 )
return V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_11 -> V_16 = V_73 -> V_73 . V_234 ;
V_11 -> V_162 = V_70 -> V_162 ;
if ( V_11 -> V_166 == V_167 ) {
V_146 = F_36 ( V_11 ) ;
if ( V_146 )
goto V_239;
}
F_11 ( V_11 , 1 ) ;
V_239:
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_113 ( struct V_211 * V_212 , void * V_213 ,
struct V_171 * V_70 )
{
struct V_10 * V_11 = V_213 ;
V_70 -> V_73 . V_234 = V_11 -> V_16 ;
return 0 ;
}
static int F_114 ( struct V_211 * V_212 , void * V_213 ,
struct V_240 * V_241 )
{
if ( V_241 -> V_232 != 0 )
return - V_184 ;
V_241 -> type = V_242 ;
V_241 -> V_243 = V_244 ;
strcpy ( V_241 -> V_245 , L_13 ) ;
return 0 ;
}
static int F_115 ( struct V_211 * V_212 , void * V_213 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_116 ( struct V_211 * V_212 , void * V_213 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_184 ;
return 0 ;
}
static int F_117 ( struct V_211 * V_212 , void * V_213 , T_4 V_246 )
{
return 0 ;
}
static int F_118 ( struct V_211 * V_212 , void * V_213 , T_4 * V_246 )
{
* V_246 = V_247 ;
return 0 ;
}
static int F_119 ( struct V_211 * V_212 , void * V_213 ,
struct V_248 * V_249 )
{
struct V_10 * V_11 = V_213 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_250 , V_249 ) ;
F_62 ( & V_11 -> V_151 ) ;
V_249 -> V_251 . V_252 . V_253 = V_43 ;
return V_146 ;
}
static int F_120 ( struct V_211 * V_212 , void * V_213 ,
struct V_248 * V_249 )
{
struct V_10 * V_11 = V_213 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_254 , V_249 ) ;
F_62 ( & V_11 -> V_151 ) ;
V_249 -> V_251 . V_252 . V_253 = V_43 ;
return V_146 ;
}
static int F_121 ( struct V_211 * V_212 , void * V_213 ,
struct V_255 * V_173 )
{
struct V_10 * V_11 = V_213 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_256 , V_173 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_122 ( struct V_211 * V_212 , void * V_213 ,
struct V_257 * V_258 )
{
struct V_10 * V_11 = V_213 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_259 , V_258 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_123 ( struct V_211 * V_211 , void * V_213 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_213 ;
if ( V_261 -> V_261 > V_11 -> V_262 - 4 )
return - V_184 ;
V_261 -> V_263 = F_124 ( V_11 , V_261 -> V_261 ) ;
V_261 -> V_264 = 4 ;
return 0 ;
}
static int F_125 ( struct V_211 * V_211 , void * V_213 ,
const struct V_260 * V_261 )
{
struct V_10 * V_11 = V_213 ;
if ( V_261 -> V_261 > V_11 -> V_262 - 4 )
return - V_184 ;
F_19 ( V_11 , V_261 -> V_261 , V_261 -> V_263 ) ;
return 0 ;
}
static int F_126 ( struct V_211 * V_212 )
{
struct V_10 * V_11 = F_127 ( V_212 ) ;
int V_146 = 0 ;
V_212 -> V_215 = V_11 ;
V_11 -> V_64 . V_265 = 0 ;
V_11 -> V_64 . V_65 = 0 ;
V_11 -> V_64 . V_66 = 0 ;
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_266 == 0 ) {
V_146 = F_81 ( V_11 ) ;
if ( V_146 )
goto V_239;
V_146 = F_56 ( V_11 ) ;
if ( V_146 )
goto V_239;
F_58 ( V_11 ) ;
F_11 ( V_11 , 1 ) ;
}
( V_11 -> V_266 ) ++ ;
V_239:
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_128 ( struct V_211 * V_212 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
F_18 ( V_11 , L_14 ,
V_11 -> V_64 . V_265 , V_11 -> V_64 . V_65 ,
V_11 -> V_64 . V_66 ) ;
F_61 ( & V_11 -> V_151 ) ;
( V_11 -> V_266 ) -- ;
if ( V_11 -> V_266 == 0 ) {
F_54 ( V_11 ) ;
F_91 ( V_11 ) ;
F_22 ( V_11 ) ;
F_57 ( V_11 ) ;
if ( V_11 -> V_166 == V_167 && V_267 )
F_27 ( V_11 ) ;
}
F_62 ( & V_11 -> V_151 ) ;
return 0 ;
}
static T_5 F_129 ( struct V_211 * V_212 ,
char T_6 * V_268 , T_7 V_269 , T_8 * V_270 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_130 ( & V_11 -> V_195 , V_268 , V_269 , V_270 ,
V_212 -> V_219 & V_220 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static unsigned int F_131 ( struct V_211 * V_212 ,
struct V_271 * V_272 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_132 ( & V_11 -> V_195 , V_212 , V_272 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_133 ( struct V_211 * V_212 , struct V_273 * V_274 )
{
struct V_10 * V_11 = V_212 -> V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_134 ( & V_11 -> V_195 , V_274 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static void F_135 ( struct V_10 * V_11 , int V_12 )
{
F_12 ( V_12 , & V_11 -> V_23 ) ;
F_8 ( V_145 , & V_11 -> V_23 ) ;
V_11 -> V_21 = V_12 ;
V_11 -> V_19 [ V_12 ] = ++ ( V_11 -> V_18 ) ;
V_11 -> V_64 . V_265 ++ ;
if ( V_11 -> V_61 != V_62 )
return;
V_11 -> V_207 ( V_11 , V_12 ) ;
}
int F_136 ( struct V_10 * V_11 , unsigned int V_275 )
{
unsigned int V_12 , V_276 = 0 ;
F_19 ( V_11 , V_139 , V_140 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
if ( V_275 & ( V_277 << V_12 ) &&
F_10 ( V_24 + V_12 , & V_11 -> V_23 ) ) {
F_135 ( V_11 , V_12 ) ;
V_276 = 1 ;
F_8 ( V_24 + V_12 , & V_11 -> V_23 ) ;
if ( V_11 -> V_166 == V_178 )
break;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ ) {
if ( V_275 & ( V_278 << V_12 ) ) {
F_12 ( V_24 + V_12 , & V_11 -> V_23 ) ;
V_276 = V_279 ;
}
}
if ( V_276 == V_279 ) {
F_12 ( V_145 , & V_11 -> V_23 ) ;
if ( V_11 -> V_166 == V_178 )
F_15 ( V_11 ) ;
}
return V_276 ;
}
int F_137 ( struct V_10 * V_11 )
{
struct V_280 V_281 = {
. type = L_15 ,
. V_282 = 0x42 >> 1 ,
. V_283 = & V_284 ,
} ;
int V_146 ;
if ( V_166 >= 0 )
V_11 -> V_166 = V_166 ;
if ( V_11 -> V_166 == V_178 &&
V_11 -> V_54 == V_55 ) {
F_138 ( V_285 L_16
L_17 ) ;
V_11 -> V_166 = V_167 ;
}
if ( ! F_139 ( V_11 -> V_166 ) ) {
F_138 ( V_285 L_18 ,
V_11 -> V_166 ) ;
return - V_184 ;
}
V_146 = F_140 ( V_11 -> V_45 , & V_11 -> V_286 ) ;
if ( V_146 )
return V_146 ;
F_141 ( & V_11 -> V_151 ) ;
V_11 -> V_61 = V_152 ;
F_11 ( V_11 , 1 ) ;
V_11 -> V_16 = V_287 ;
V_11 -> V_162 = V_288 ;
F_72 ( & V_11 -> V_63 ) ;
F_53 ( V_11 ) ;
V_284 . V_289 = V_11 -> V_289 ;
V_284 . V_290 = V_11 -> V_290 ;
V_11 -> V_291 = V_281 . V_282 ;
V_11 -> V_292 = F_142 ( & V_11 -> V_286 ,
V_11 -> V_293 , & V_281 , NULL ) ;
if ( V_11 -> V_292 == NULL ) {
V_146 = - V_294 ;
goto V_295;
}
V_146 = F_60 ( V_11 ) ;
if ( V_146 )
goto V_295;
V_146 = F_143 ( & V_11 -> V_296 , 10 ) ;
if ( V_146 )
goto V_295;
V_11 -> V_286 . V_296 = & V_11 -> V_296 ;
F_61 ( & V_11 -> V_151 ) ;
V_11 -> V_297 = V_298 ;
V_11 -> V_297 . V_299 = 0 ;
V_11 -> V_297 . V_286 = & V_11 -> V_286 ;
F_144 ( & V_11 -> V_297 , V_11 ) ;
V_146 = F_145 ( & V_11 -> V_297 , V_300 , - 1 ) ;
if ( V_146 )
goto V_239;
if ( V_11 -> V_166 == V_167 && ! V_267 ) {
if ( F_23 ( V_11 , 1 ) )
F_20 ( V_11 , L_19
L_20 ) ;
}
V_239:
F_146 ( & V_11 -> V_296 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
V_295:
F_147 ( & V_11 -> V_286 ) ;
return V_146 ;
}
void F_148 ( struct V_10 * V_11 )
{
if ( V_11 -> V_266 > 0 ) {
F_20 ( V_11 , L_21 ) ;
F_57 ( V_11 ) ;
}
F_92 ( & V_11 -> V_195 ) ;
if ( V_11 -> V_166 == V_167 )
F_27 ( V_11 ) ;
F_149 ( & V_11 -> V_297 ) ;
F_146 ( & V_11 -> V_296 ) ;
F_147 ( & V_11 -> V_286 ) ;
}
void F_150 ( struct V_10 * V_11 )
{
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_266 > 0 ) {
enum V_301 V_302 = V_11 -> V_61 ;
F_54 ( V_11 ) ;
F_57 ( V_11 ) ;
V_11 -> V_61 = V_302 ;
}
F_62 ( & V_11 -> V_151 ) ;
}
int F_151 ( struct V_10 * V_11 )
{
int V_146 = 0 ;
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_266 > 0 ) {
V_146 = F_56 ( V_11 ) ;
if ( V_146 ) {
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
F_58 ( V_11 ) ;
} else {
F_57 ( V_11 ) ;
}
F_62 ( & V_11 -> V_151 ) ;
F_12 ( V_25 , & V_11 -> V_23 ) ;
if ( V_11 -> V_61 == V_62 ) {
if ( V_11 -> V_166 == V_178 && V_11 -> V_78 [ 0 ] )
F_70 ( & V_11 -> V_78 [ 0 ] -> V_67 , & V_11 -> V_63 ) ;
V_146 = F_66 ( V_11 ) ;
}
return V_146 ;
}
