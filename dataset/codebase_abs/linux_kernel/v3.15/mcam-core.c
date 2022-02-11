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
return 0 ;
}
static void F_69 ( struct V_7 * V_8 )
{
struct V_6 * V_178 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
unsigned long V_23 ;
int V_179 ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
V_179 = ( V_11 -> V_61 == V_180 ) && ! F_31 ( & V_11 -> V_63 ) ;
F_70 ( & V_178 -> V_67 , & V_11 -> V_63 ) ;
if ( V_11 -> V_61 == V_62 && F_10 ( V_99 , & V_11 -> V_23 ) )
F_47 ( V_11 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
if ( V_179 )
F_66 ( V_11 ) ;
}
static void F_71 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
F_62 ( & V_11 -> V_151 ) ;
}
static void F_72 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
F_61 ( & V_11 -> V_151 ) ;
}
static int F_73 ( struct V_169 * V_170 , unsigned int V_181 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
unsigned int V_12 ;
if ( V_11 -> V_61 != V_144 ) {
F_74 ( & V_11 -> V_63 ) ;
return - V_182 ;
}
V_11 -> V_18 = 0 ;
if ( V_11 -> V_166 != V_167 && F_31 ( & V_11 -> V_63 ) ) {
V_11 -> V_61 = V_180 ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
F_8 ( V_24 + V_12 , & V_11 -> V_23 ) ;
return F_66 ( V_11 ) ;
}
static int F_75 ( struct V_169 * V_170 )
{
struct V_10 * V_11 = F_68 ( V_170 ) ;
unsigned long V_23 ;
if ( V_11 -> V_61 == V_180 ) {
V_11 -> V_61 = V_144 ;
return 0 ;
}
if ( V_11 -> V_61 != V_62 )
return - V_182 ;
F_54 ( V_11 ) ;
if ( V_11 -> V_183 )
V_11 -> V_183 ( V_11 ) ;
F_30 ( & V_11 -> V_59 , V_23 ) ;
F_74 ( & V_11 -> V_63 ) ;
F_34 ( & V_11 -> V_59 , V_23 ) ;
return 0 ;
}
static int F_76 ( struct V_7 * V_8 )
{
struct V_6 * V_178 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
int V_184 = V_11 -> V_16 . V_17 / V_185 + 1 ;
V_178 -> V_186 = F_24 ( V_11 -> V_45 ,
V_184 * sizeof( struct V_96 ) ,
& V_178 -> V_93 , V_47 ) ;
if ( V_178 -> V_186 == NULL ) {
F_26 ( V_11 , L_11 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
struct V_6 * V_178 = F_2 ( V_8 ) ;
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
struct V_187 * V_187 = F_78 ( V_8 , 0 ) ;
struct V_96 * V_188 = V_178 -> V_186 ;
struct V_189 * V_190 ;
int V_3 ;
V_178 -> V_95 = F_79 ( V_11 -> V_45 , V_187 -> V_191 ,
V_187 -> V_192 , V_193 ) ;
if ( V_178 -> V_95 <= 0 )
return - V_194 ;
F_80 (sg_table->sgl, sg, mvb->dma_desc_nent, i) {
V_188 -> V_195 = F_81 ( V_190 ) ;
V_188 -> V_196 = F_82 ( V_190 ) ;
V_188 ++ ;
}
return 0 ;
}
static void F_83 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
struct V_187 * V_187 = F_78 ( V_8 , 0 ) ;
if ( V_187 )
F_84 ( V_11 -> V_45 , V_187 -> V_191 ,
V_187 -> V_192 , V_193 ) ;
}
static void F_85 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_68 ( V_8 -> V_169 ) ;
struct V_6 * V_178 = F_2 ( V_8 ) ;
int V_184 = V_11 -> V_16 . V_17 / V_185 + 1 ;
F_25 ( V_11 -> V_45 , V_184 * sizeof( struct V_96 ) ,
V_178 -> V_186 , V_178 -> V_93 ) ;
}
static int F_86 ( struct V_10 * V_11 )
{
struct V_169 * V_170 = & V_11 -> V_197 ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_170 -> type = V_198 ;
V_170 -> V_199 = V_11 ;
F_74 ( & V_11 -> V_63 ) ;
switch ( V_11 -> V_166 ) {
case V_176 :
#ifdef F_87
V_170 -> V_200 = & V_201 ;
V_170 -> V_202 = & V_203 ;
V_170 -> V_204 = sizeof( struct V_6 ) ;
V_11 -> V_177 = F_88 ( V_11 -> V_45 ) ;
V_170 -> V_205 = V_206 | V_207 ;
V_11 -> V_138 = F_42 ;
V_11 -> V_208 = F_43 ;
#endif
break;
case V_209 :
#ifdef F_89
V_170 -> V_200 = & V_210 ;
V_170 -> V_202 = & V_211 ;
V_170 -> V_204 = sizeof( struct V_6 ) ;
V_170 -> V_205 = V_206 | V_207 ;
V_11 -> V_138 = F_45 ;
V_11 -> V_208 = F_46 ;
#endif
break;
case V_167 :
#ifdef F_90
F_91 ( & V_11 -> V_68 , F_29 ,
( unsigned long ) V_11 ) ;
V_170 -> V_200 = & V_201 ;
V_170 -> V_202 = & V_212 ;
V_170 -> V_204 = sizeof( struct V_6 ) ;
V_170 -> V_205 = V_206 ;
V_11 -> V_138 = F_28 ;
V_11 -> V_208 = F_37 ;
#endif
break;
}
return F_92 ( V_170 ) ;
}
static void F_93 ( struct V_10 * V_11 )
{
F_94 ( & V_11 -> V_197 ) ;
#ifdef F_87
if ( V_11 -> V_166 == V_176 )
F_95 ( V_11 -> V_177 ) ;
#endif
}
static int F_96 ( struct V_213 * V_214 , void * V_215 ,
enum V_216 type )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_97 ( & V_11 -> V_197 , type ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_98 ( struct V_213 * V_214 , void * V_215 ,
enum V_216 type )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_99 ( & V_11 -> V_197 , type ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_100 ( struct V_213 * V_214 , void * V_215 ,
struct V_218 * V_219 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_101 ( & V_11 -> V_197 , V_219 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_102 ( struct V_213 * V_214 , void * V_215 ,
struct V_220 * V_58 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_103 ( & V_11 -> V_197 , V_58 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_104 ( struct V_213 * V_214 , void * V_215 ,
struct V_220 * V_58 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_105 ( & V_11 -> V_197 , V_58 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_106 ( struct V_213 * V_214 , void * V_215 ,
struct V_220 * V_58 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_107 ( & V_11 -> V_197 , V_58 , V_214 -> V_221 & V_222 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_108 ( struct V_213 * V_213 , void * V_215 ,
struct V_223 * V_224 )
{
strcpy ( V_224 -> V_225 , L_12 ) ;
strcpy ( V_224 -> V_226 , L_12 ) ;
V_224 -> V_227 = 1 ;
V_224 -> V_228 = V_229 |
V_230 | V_231 ;
return 0 ;
}
static int F_109 ( struct V_213 * V_214 ,
void * V_215 , struct V_232 * V_73 )
{
if ( V_73 -> V_233 >= V_4 )
return - V_182 ;
F_110 ( V_73 -> V_234 , V_5 [ V_73 -> V_233 ] . V_188 ,
sizeof( V_73 -> V_234 ) ) ;
V_73 -> V_2 = V_5 [ V_73 -> V_233 ] . V_2 ;
return 0 ;
}
static int F_111 ( struct V_213 * V_214 , void * V_215 ,
struct V_171 * V_73 )
{
struct V_10 * V_11 = V_215 ;
struct V_1 * V_70 ;
struct V_72 * V_235 = & V_73 -> V_73 . V_235 ;
struct V_160 V_161 ;
int V_146 ;
V_70 = F_1 ( V_235 -> V_2 ) ;
V_235 -> V_2 = V_70 -> V_2 ;
F_65 ( & V_161 , V_235 , V_70 -> V_162 ) ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_236 , & V_161 ) ;
F_62 ( & V_11 -> V_151 ) ;
F_112 ( V_235 , & V_161 ) ;
switch ( V_70 -> V_2 ) {
case V_85 :
case V_86 :
V_235 -> V_105 = V_235 -> V_76 * 3 / 2 ;
break;
default:
V_235 -> V_105 = V_235 -> V_76 * V_70 -> V_237 ;
break;
}
V_235 -> V_17 = V_235 -> V_77 * V_235 -> V_105 ;
return V_146 ;
}
static int F_113 ( struct V_213 * V_214 , void * V_215 ,
struct V_171 * V_73 )
{
struct V_10 * V_11 = V_215 ;
struct V_1 * V_70 ;
int V_146 ;
if ( V_11 -> V_61 != V_144 || V_11 -> V_197 . V_238 > 0 )
return - V_239 ;
V_70 = F_1 ( V_73 -> V_73 . V_235 . V_2 ) ;
V_146 = F_111 ( V_214 , V_215 , V_73 ) ;
if ( V_146 )
return V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_11 -> V_16 = V_73 -> V_73 . V_235 ;
V_11 -> V_162 = V_70 -> V_162 ;
if ( V_11 -> V_166 == V_167 ) {
V_146 = F_36 ( V_11 ) ;
if ( V_146 )
goto V_240;
}
F_11 ( V_11 , 1 ) ;
V_240:
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_114 ( struct V_213 * V_214 , void * V_215 ,
struct V_171 * V_70 )
{
struct V_10 * V_11 = V_215 ;
V_70 -> V_73 . V_235 = V_11 -> V_16 ;
return 0 ;
}
static int F_115 ( struct V_213 * V_214 , void * V_215 ,
struct V_241 * V_242 )
{
if ( V_242 -> V_233 != 0 )
return - V_182 ;
V_242 -> type = V_243 ;
V_242 -> V_244 = V_245 ;
strcpy ( V_242 -> V_246 , L_13 ) ;
return 0 ;
}
static int F_116 ( struct V_213 * V_214 , void * V_215 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_117 ( struct V_213 * V_214 , void * V_215 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_182 ;
return 0 ;
}
static int F_118 ( struct V_213 * V_214 , void * V_215 , T_4 V_247 )
{
return 0 ;
}
static int F_119 ( struct V_213 * V_214 , void * V_215 , T_4 * V_247 )
{
* V_247 = V_248 ;
return 0 ;
}
static int F_120 ( struct V_213 * V_214 , void * V_215 ,
struct V_249 * V_250 )
{
struct V_10 * V_11 = V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_251 , V_250 ) ;
F_62 ( & V_11 -> V_151 ) ;
V_250 -> V_252 . V_253 . V_254 = V_43 ;
return V_146 ;
}
static int F_121 ( struct V_213 * V_214 , void * V_215 ,
struct V_249 * V_250 )
{
struct V_10 * V_11 = V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_255 , V_250 ) ;
F_62 ( & V_11 -> V_151 ) ;
V_250 -> V_252 . V_253 . V_254 = V_43 ;
return V_146 ;
}
static int F_122 ( struct V_213 * V_214 , void * V_215 ,
struct V_256 * V_173 )
{
struct V_10 * V_11 = V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_257 , V_173 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_123 ( struct V_213 * V_214 , void * V_215 ,
struct V_258 * V_259 )
{
struct V_10 * V_11 = V_215 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_59 ( V_11 , V_164 , V_260 , V_259 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_124 ( struct V_213 * V_213 , void * V_215 ,
struct V_261 * V_262 )
{
struct V_10 * V_11 = V_215 ;
if ( V_262 -> V_262 > V_11 -> V_263 - 4 )
return - V_182 ;
V_262 -> V_264 = F_125 ( V_11 , V_262 -> V_262 ) ;
V_262 -> V_265 = 4 ;
return 0 ;
}
static int F_126 ( struct V_213 * V_213 , void * V_215 ,
const struct V_261 * V_262 )
{
struct V_10 * V_11 = V_215 ;
if ( V_262 -> V_262 > V_11 -> V_263 - 4 )
return - V_182 ;
F_19 ( V_11 , V_262 -> V_262 , V_262 -> V_264 ) ;
return 0 ;
}
static int F_127 ( struct V_213 * V_214 )
{
struct V_10 * V_11 = F_128 ( V_214 ) ;
int V_146 = 0 ;
V_214 -> V_217 = V_11 ;
V_11 -> V_64 . V_266 = 0 ;
V_11 -> V_64 . V_65 = 0 ;
V_11 -> V_64 . V_66 = 0 ;
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_267 == 0 ) {
V_146 = F_86 ( V_11 ) ;
if ( V_146 )
goto V_240;
V_146 = F_56 ( V_11 ) ;
if ( V_146 )
goto V_240;
F_58 ( V_11 ) ;
F_11 ( V_11 , 1 ) ;
}
( V_11 -> V_267 ) ++ ;
V_240:
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_129 ( struct V_213 * V_214 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
F_18 ( V_11 , L_14 ,
V_11 -> V_64 . V_266 , V_11 -> V_64 . V_65 ,
V_11 -> V_64 . V_66 ) ;
F_61 ( & V_11 -> V_151 ) ;
( V_11 -> V_267 ) -- ;
if ( V_11 -> V_267 == 0 ) {
F_54 ( V_11 ) ;
F_93 ( V_11 ) ;
F_22 ( V_11 ) ;
F_57 ( V_11 ) ;
if ( V_11 -> V_166 == V_167 && V_268 )
F_27 ( V_11 ) ;
}
F_62 ( & V_11 -> V_151 ) ;
return 0 ;
}
static T_5 F_130 ( struct V_213 * V_214 ,
char T_6 * V_269 , T_7 V_270 , T_8 * V_271 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_131 ( & V_11 -> V_197 , V_269 , V_270 , V_271 ,
V_214 -> V_221 & V_222 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static unsigned int F_132 ( struct V_213 * V_214 ,
struct V_272 * V_273 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_133 ( & V_11 -> V_197 , V_214 , V_273 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static int F_134 ( struct V_213 * V_214 , struct V_274 * V_275 )
{
struct V_10 * V_11 = V_214 -> V_217 ;
int V_146 ;
F_61 ( & V_11 -> V_151 ) ;
V_146 = F_135 ( & V_11 -> V_197 , V_275 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
}
static void F_136 ( struct V_10 * V_11 , int V_12 )
{
F_12 ( V_12 , & V_11 -> V_23 ) ;
F_8 ( V_145 , & V_11 -> V_23 ) ;
V_11 -> V_21 = V_12 ;
V_11 -> V_19 [ V_12 ] = ++ ( V_11 -> V_18 ) ;
V_11 -> V_64 . V_266 ++ ;
if ( V_11 -> V_61 != V_62 )
return;
V_11 -> V_208 ( V_11 , V_12 ) ;
}
int F_137 ( struct V_10 * V_11 , unsigned int V_276 )
{
unsigned int V_12 , V_277 = 0 ;
F_19 ( V_11 , V_139 , V_140 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ )
if ( V_276 & ( V_278 << V_12 ) &&
F_10 ( V_24 + V_12 , & V_11 -> V_23 ) ) {
F_136 ( V_11 , V_12 ) ;
V_277 = 1 ;
F_8 ( V_24 + V_12 , & V_11 -> V_23 ) ;
if ( V_11 -> V_166 == V_209 )
break;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_22 ; V_12 ++ ) {
if ( V_276 & ( V_279 << V_12 ) ) {
F_12 ( V_24 + V_12 , & V_11 -> V_23 ) ;
V_277 = V_280 ;
}
}
if ( V_277 == V_280 ) {
F_12 ( V_145 , & V_11 -> V_23 ) ;
if ( V_11 -> V_166 == V_209 )
F_15 ( V_11 ) ;
}
return V_277 ;
}
int F_138 ( struct V_10 * V_11 )
{
struct V_281 V_282 = {
. type = L_15 ,
. V_283 = 0x42 >> 1 ,
. V_284 = & V_285 ,
} ;
int V_146 ;
if ( V_166 >= 0 )
V_11 -> V_166 = V_166 ;
if ( V_11 -> V_166 == V_209 &&
V_11 -> V_54 == V_55 ) {
F_139 ( V_286 L_16
L_17 ) ;
V_11 -> V_166 = V_167 ;
}
if ( ! F_140 ( V_11 -> V_166 ) ) {
F_139 ( V_286 L_18 ,
V_11 -> V_166 ) ;
return - V_182 ;
}
V_146 = F_141 ( V_11 -> V_45 , & V_11 -> V_287 ) ;
if ( V_146 )
return V_146 ;
F_142 ( & V_11 -> V_151 ) ;
V_11 -> V_61 = V_152 ;
F_11 ( V_11 , 1 ) ;
V_11 -> V_16 = V_288 ;
V_11 -> V_162 = V_289 ;
F_74 ( & V_11 -> V_63 ) ;
F_53 ( V_11 ) ;
V_285 . V_290 = V_11 -> V_290 ;
V_285 . V_291 = V_11 -> V_291 ;
V_11 -> V_292 = V_282 . V_283 ;
V_11 -> V_293 = F_143 ( & V_11 -> V_287 ,
V_11 -> V_294 , & V_282 , NULL ) ;
if ( V_11 -> V_293 == NULL ) {
V_146 = - V_295 ;
goto V_296;
}
V_146 = F_60 ( V_11 ) ;
if ( V_146 )
goto V_296;
V_146 = F_144 ( & V_11 -> V_297 , 10 ) ;
if ( V_146 )
goto V_296;
V_11 -> V_287 . V_297 = & V_11 -> V_297 ;
F_61 ( & V_11 -> V_151 ) ;
V_11 -> V_298 = V_299 ;
V_11 -> V_298 . V_300 = 0 ;
V_11 -> V_298 . V_287 = & V_11 -> V_287 ;
F_145 ( & V_11 -> V_298 , V_11 ) ;
V_146 = F_146 ( & V_11 -> V_298 , V_301 , - 1 ) ;
if ( V_146 )
goto V_240;
if ( V_11 -> V_166 == V_167 && ! V_268 ) {
if ( F_23 ( V_11 , 1 ) )
F_20 ( V_11 , L_19
L_20 ) ;
}
V_240:
F_147 ( & V_11 -> V_297 ) ;
F_62 ( & V_11 -> V_151 ) ;
return V_146 ;
V_296:
F_148 ( & V_11 -> V_287 ) ;
return V_146 ;
}
void F_149 ( struct V_10 * V_11 )
{
if ( V_11 -> V_267 > 0 ) {
F_20 ( V_11 , L_21 ) ;
F_57 ( V_11 ) ;
}
F_94 ( & V_11 -> V_197 ) ;
if ( V_11 -> V_166 == V_167 )
F_27 ( V_11 ) ;
F_150 ( & V_11 -> V_298 ) ;
F_147 ( & V_11 -> V_297 ) ;
F_148 ( & V_11 -> V_287 ) ;
}
void F_151 ( struct V_10 * V_11 )
{
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_267 > 0 ) {
enum V_302 V_303 = V_11 -> V_61 ;
F_54 ( V_11 ) ;
F_57 ( V_11 ) ;
V_11 -> V_61 = V_303 ;
}
F_62 ( & V_11 -> V_151 ) ;
}
int F_152 ( struct V_10 * V_11 )
{
int V_146 = 0 ;
F_61 ( & V_11 -> V_151 ) ;
if ( V_11 -> V_267 > 0 ) {
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
if ( V_11 -> V_166 == V_209 && V_11 -> V_78 [ 0 ] )
F_70 ( & V_11 -> V_78 [ 0 ] -> V_67 , & V_11 -> V_63 ) ;
V_146 = F_66 ( V_11 ) ;
}
return V_146 ;
}
