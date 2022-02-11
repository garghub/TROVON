static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline T_1 F_3 ( void T_2 * V_5 , T_1 V_6 )
{
return F_4 ( V_5 + V_6 ) ;
}
static inline void F_5 ( void T_2 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_6 ( V_7 , V_5 + V_6 ) ;
}
static inline void F_7 ( void T_2 * V_5 , T_1 V_6 , T_1 V_8 )
{
F_5 ( V_5 , V_6 , F_3 ( V_5 , V_6 ) | V_8 ) ;
}
static inline void F_8 ( void T_2 * V_5 , T_1 V_6 , T_1 V_8 )
{
F_5 ( V_5 , V_6 , F_3 ( V_5 , V_6 ) & ~ V_8 ) ;
}
static void F_9 ( void * V_9 )
{
struct V_1 * V_10 = (struct V_1 * ) V_9 ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_13 V_14 ;
enum V_15 V_16 ;
F_10 ( & V_10 -> V_17 ) ;
V_16 = F_11 ( V_12 , V_10 -> V_18 , & V_14 ) ;
switch ( V_16 ) {
case V_19 :
F_12 ( V_10 -> V_20 , L_1 , V_21 ) ;
break;
case V_22 :
F_13 ( V_10 -> V_20 , L_2 , V_21 ) ;
break;
case V_23 :
F_13 ( V_10 -> V_20 , L_3 , V_21 ) ;
break;
case V_24 :
F_12 ( V_10 -> V_20 , L_4 , V_21 ) ;
if ( V_10 -> V_25 ) {
struct V_26 * V_27 = V_10 -> V_25 ;
struct V_28 * V_29 = & V_10 -> V_25 -> V_30 ;
V_29 -> V_31 = V_10 -> V_31 ++ ;
V_29 -> V_32 = V_33 ;
V_29 -> V_34 . V_35 = F_14 () ;
F_15 ( & V_29 -> V_34 , 0 , V_27 -> V_36 ) ;
F_16 ( & V_29 -> V_34 , V_37 ) ;
F_12 ( V_10 -> V_20 , L_5 ,
V_29 -> V_34 . V_38 , V_29 -> V_31 ) ;
V_10 -> V_39 ++ ;
V_10 -> V_25 = NULL ;
}
if ( V_10 -> V_14 == V_40 ) {
if ( F_17 ( & V_10 -> V_41 ) ) {
F_13 ( V_10 -> V_20 , L_6 ,
V_21 ) ;
V_10 -> V_42 ++ ;
V_10 -> V_25 = NULL ;
F_18 ( & V_10 -> V_17 ) ;
return;
}
V_10 -> V_25 = F_19 ( V_10 -> V_41 . V_43 ,
struct V_26 , V_44 ) ;
F_20 ( & V_10 -> V_25 -> V_44 ) ;
if ( F_21 ( V_10 ) ) {
F_13 ( V_10 -> V_20 , L_7 ,
V_21 ) ;
F_18 ( & V_10 -> V_17 ) ;
return;
}
F_7 ( V_10 -> V_45 , V_46 , V_47 ) ;
}
break;
default:
F_13 ( V_10 -> V_20 , L_8 , V_21 ) ;
break;
}
F_18 ( & V_10 -> V_17 ) ;
}
static int F_22 ( struct V_1 * V_10 ,
struct V_26 * V_27 )
{
struct V_48 * V_49 = NULL ;
struct V_50 V_51 ;
int V_52 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_53 = ( V_54 ) V_10 -> V_55 -> V_56 + V_57 ;
V_51 . V_58 = V_59 ;
V_51 . V_60 = V_59 ;
V_51 . V_61 = 4 ;
V_52 = F_23 ( V_10 -> V_11 , & V_51 ) ;
if ( V_52 < 0 ) {
F_13 ( V_10 -> V_20 , L_9 ,
V_21 , V_52 ) ;
return V_52 ;
}
V_49 = F_24 ( V_10 -> V_11 , V_27 -> V_62 ,
V_27 -> V_36 ,
V_63 , V_64 ) ;
if ( ! V_49 ) {
F_13 ( V_10 -> V_20 , L_10 ,
V_21 , V_27 -> V_36 ) ;
return - V_65 ;
}
V_49 -> V_66 = F_9 ;
V_49 -> V_67 = V_10 ;
V_10 -> V_18 = F_25 ( V_49 ) ;
if ( F_26 ( V_10 -> V_18 ) ) {
F_13 ( V_10 -> V_20 , L_11 , V_21 ) ;
return - V_68 ;
}
F_27 ( V_10 -> V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_10 )
{
int V_52 ;
struct V_26 * V_27 = V_10 -> V_25 ;
if ( ! V_27 )
return - V_65 ;
V_52 = F_22 ( V_10 , V_27 ) ;
if ( V_52 ) {
V_10 -> V_42 ++ ;
return V_52 ;
}
F_7 ( V_10 -> V_45 , V_46 , V_47 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_10 )
{
T_1 V_36 , V_56 ;
V_36 = ( ( V_10 -> V_69 . V_70 - 1 ) << 16 ) |
( ( V_10 -> V_69 . V_71 << 1 ) - 1 ) ;
F_5 ( V_10 -> V_45 , V_72 , V_36 ) ;
V_56 = ( ( V_10 -> V_69 . V_73 ) << 16 ) |
( ( V_10 -> V_69 . V_74 << 1 ) ) ;
F_5 ( V_10 -> V_45 , V_75 , V_56 ) ;
F_12 ( V_10 -> V_20 , L_12 ,
V_10 -> V_69 . V_71 , V_10 -> V_69 . V_70 ,
V_10 -> V_69 . V_74 , V_10 -> V_69 . V_73 ) ;
F_7 ( V_10 -> V_45 , V_46 , V_76 ) ;
}
static T_3 F_29 ( int V_77 , void * V_78 )
{
struct V_1 * V_10 = V_78 ;
F_10 ( & V_10 -> V_17 ) ;
if ( V_10 -> V_14 == V_79 ) {
F_8 ( V_10 -> V_45 , V_80 , V_81 | V_82 | V_83 ) ;
V_10 -> V_14 = V_84 ;
F_30 ( & V_10 -> F_30 ) ;
F_18 ( & V_10 -> V_17 ) ;
return V_85 ;
}
if ( ( V_10 -> V_86 & V_82 ) || ( V_10 -> V_86 & V_83 ) ) {
F_31 ( V_10 -> V_20 , L_13 ,
V_21 ) ;
V_10 -> V_42 ++ ;
F_32 ( V_10 -> V_11 ) ;
F_7 ( V_10 -> V_45 , V_87 , V_81 | V_82 | V_83 ) ;
F_12 ( V_10 -> V_20 , L_14 ) ;
if ( F_21 ( V_10 ) ) {
F_13 ( V_10 -> V_20 , L_15 ,
V_21 ) ;
F_18 ( & V_10 -> V_17 ) ;
return V_85 ;
}
}
F_18 ( & V_10 -> V_17 ) ;
return V_85 ;
}
static T_3 F_33 ( int V_77 , void * V_78 )
{
struct V_1 * V_10 = V_78 ;
F_10 ( & V_10 -> V_17 ) ;
V_10 -> V_86 = F_3 ( V_10 -> V_45 , V_88 ) ;
F_7 ( V_10 -> V_45 , V_87 , V_81 | V_82 | V_83 ) ;
F_18 ( & V_10 -> V_17 ) ;
return V_89 ;
}
static int F_34 ( struct V_90 * V_91 ,
unsigned int * V_92 ,
unsigned int * V_93 ,
unsigned int V_94 [] ,
struct V_95 * V_96 [] )
{
struct V_1 * V_10 = F_35 ( V_91 ) ;
unsigned int V_36 ;
V_36 = V_10 -> V_97 . V_97 . V_98 . V_99 ;
if ( * V_93 )
return V_94 [ 0 ] < V_36 ? - V_65 : 0 ;
* V_93 = 1 ;
V_94 [ 0 ] = V_36 ;
V_10 -> V_25 = NULL ;
F_12 ( V_10 -> V_20 , L_16 ,
* V_92 , V_36 ) ;
return 0 ;
}
static int F_36 ( struct V_100 * V_30 )
{
struct V_28 * V_29 = F_37 ( V_30 ) ;
struct V_26 * V_27 = F_2 ( V_29 , struct V_26 , V_30 ) ;
F_38 ( & V_27 -> V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_100 * V_30 )
{
struct V_1 * V_10 = F_35 ( V_30 -> V_90 ) ;
struct V_28 * V_29 = F_37 ( V_30 ) ;
struct V_26 * V_27 = F_2 ( V_29 , struct V_26 , V_30 ) ;
unsigned long V_36 ;
V_36 = V_10 -> V_97 . V_97 . V_98 . V_99 ;
if ( F_40 ( V_30 , 0 ) < V_36 ) {
F_13 ( V_10 -> V_20 , L_17 ,
V_21 , F_40 ( V_30 , 0 ) , V_36 ) ;
return - V_65 ;
}
F_15 ( V_30 , 0 , V_36 ) ;
if ( ! V_27 -> V_101 ) {
V_27 -> V_62 =
F_41 ( & V_27 -> V_30 . V_34 , 0 ) ;
V_27 -> V_36 = F_40 ( & V_27 -> V_30 . V_34 , 0 ) ;
V_27 -> V_101 = true ;
F_15 ( & V_27 -> V_30 . V_34 , 0 , V_27 -> V_36 ) ;
F_12 ( V_10 -> V_20 , L_18 ,
V_30 -> V_38 , & V_27 -> V_62 , V_27 -> V_36 ) ;
}
return 0 ;
}
static void F_42 ( struct V_100 * V_30 )
{
struct V_1 * V_10 = F_35 ( V_30 -> V_90 ) ;
struct V_28 * V_29 = F_37 ( V_30 ) ;
struct V_26 * V_27 = F_2 ( V_29 , struct V_26 , V_30 ) ;
unsigned long V_102 = 0 ;
F_43 ( & V_10 -> V_17 , V_102 ) ;
if ( ( V_10 -> V_14 == V_40 ) && ( ! V_10 -> V_25 ) ) {
V_10 -> V_25 = V_27 ;
F_12 ( V_10 -> V_20 , L_19 ,
V_27 -> V_30 . V_34 . V_38 ) ;
if ( F_21 ( V_10 ) ) {
F_13 ( V_10 -> V_20 , L_15 ,
V_21 ) ;
F_44 ( & V_10 -> V_17 , V_102 ) ;
return;
}
} else {
F_45 ( & V_27 -> V_44 , & V_10 -> V_41 ) ;
}
F_44 ( & V_10 -> V_17 , V_102 ) ;
}
static int F_46 ( struct V_90 * V_91 , unsigned int V_103 )
{
struct V_1 * V_10 = F_35 ( V_91 ) ;
struct V_26 * V_27 , * V_104 ;
T_1 V_7 = 0 ;
int V_52 ;
V_52 = F_47 ( V_10 -> V_105 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_20 ,
V_21 ) ;
goto V_106;
}
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_109 , V_110 , 1 ) ;
if ( V_52 && V_52 != - V_111 ) {
F_13 ( V_10 -> V_20 , L_21 ,
V_21 ) ;
goto V_112;
}
F_49 ( & V_10 -> V_17 ) ;
switch ( V_10 -> V_113 . V_114 ) {
case 14 :
V_7 |= V_115 | V_116 ;
break;
case 12 :
V_7 |= V_116 ;
break;
case 10 :
V_7 |= V_115 ;
break;
default:
break;
}
if ( V_10 -> V_113 . V_102 & V_117 )
V_7 |= V_118 ;
if ( V_10 -> V_113 . V_102 & V_119 )
V_7 |= V_120 ;
if ( V_10 -> V_113 . V_102 & V_121 )
V_7 |= V_122 ;
F_5 ( V_10 -> V_45 , V_46 , V_7 ) ;
if ( V_10 -> V_123 )
F_28 ( V_10 ) ;
F_7 ( V_10 -> V_45 , V_46 , V_124 ) ;
V_10 -> V_14 = V_40 ;
V_10 -> V_31 = 0 ;
V_10 -> V_42 = 0 ;
V_10 -> V_39 = 0 ;
V_10 -> V_25 = NULL ;
if ( F_17 ( & V_10 -> V_41 ) ) {
F_12 ( V_10 -> V_20 , L_22 ) ;
F_50 ( & V_10 -> V_17 ) ;
return 0 ;
}
V_10 -> V_25 = F_19 ( V_10 -> V_41 . V_43 , struct V_26 , V_44 ) ;
F_20 ( & V_10 -> V_25 -> V_44 ) ;
F_12 ( V_10 -> V_20 , L_23 ) ;
V_52 = F_21 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_24 ,
V_21 ) ;
F_50 ( & V_10 -> V_17 ) ;
goto V_125;
}
F_7 ( V_10 -> V_45 , V_80 , V_81 | V_82 | V_83 ) ;
F_50 ( & V_10 -> V_17 ) ;
return 0 ;
V_125:
F_48 ( V_10 -> V_107 . V_108 , V_109 , V_110 , 0 ) ;
V_112:
F_51 ( V_10 -> V_105 ) ;
V_106:
F_49 ( & V_10 -> V_17 ) ;
if ( V_10 -> V_25 ) {
V_27 = V_10 -> V_25 ;
F_16 ( & V_27 -> V_30 . V_34 , V_126 ) ;
V_10 -> V_25 = NULL ;
}
F_52 (buf, node, &dcmi->buffers, list) {
F_20 ( & V_27 -> V_44 ) ;
F_16 ( & V_27 -> V_30 . V_34 , V_126 ) ;
}
F_50 ( & V_10 -> V_17 ) ;
return V_52 ;
}
static void F_53 ( struct V_90 * V_91 )
{
struct V_1 * V_10 = F_35 ( V_91 ) ;
struct V_26 * V_27 , * V_104 ;
unsigned long V_127 = F_54 ( V_128 ) ;
long V_129 ;
int V_52 ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_109 , V_110 , 0 ) ;
if ( V_52 && V_52 != - V_111 )
F_13 ( V_10 -> V_20 , L_25 ) ;
V_10 -> V_14 = V_79 ;
V_129 = F_55 ( & V_10 -> F_30 ,
V_127 ) ;
F_49 ( & V_10 -> V_17 ) ;
F_8 ( V_10 -> V_45 , V_80 , V_81 | V_82 | V_83 ) ;
F_8 ( V_10 -> V_45 , V_46 , V_124 ) ;
if ( ! V_129 ) {
F_13 ( V_10 -> V_20 , L_26 ) ;
V_10 -> V_14 = V_84 ;
}
if ( V_10 -> V_25 ) {
V_27 = V_10 -> V_25 ;
F_16 ( & V_27 -> V_30 . V_34 , V_130 ) ;
V_10 -> V_25 = NULL ;
}
F_52 (buf, node, &dcmi->buffers, list) {
F_20 ( & V_27 -> V_44 ) ;
F_16 ( & V_27 -> V_30 . V_34 , V_130 ) ;
}
F_50 ( & V_10 -> V_17 ) ;
F_32 ( V_10 -> V_11 ) ;
F_51 ( V_10 -> V_105 ) ;
F_12 ( V_10 -> V_20 , L_27 ,
V_10 -> V_42 , V_10 -> V_39 ) ;
}
static int F_56 ( struct V_131 * V_131 , void * V_132 ,
struct V_133 * V_97 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
* V_97 = V_10 -> V_97 ;
return 0 ;
}
static const struct V_134 * F_58 ( struct V_1 * V_10 ,
unsigned int V_135 )
{
unsigned int V_136 = V_10 -> V_137 ;
const struct V_134 * V_97 ;
unsigned int V_138 ;
for ( V_138 = 0 ; V_138 < V_136 ; V_138 ++ ) {
V_97 = V_10 -> V_139 [ V_138 ] ;
if ( V_97 -> V_135 == V_135 )
return V_97 ;
}
return NULL ;
}
static void F_59 ( struct V_1 * V_10 ,
struct V_140 * V_98 ,
struct V_141 * V_142 )
{
struct V_141 * V_143 = NULL ;
unsigned int V_138 ;
unsigned int V_144 = V_145 ;
for ( V_138 = 0 ; V_138 < V_10 -> V_146 ; V_138 ++ ) {
struct V_141 * V_147 = & V_10 -> V_148 [ V_138 ] ;
int V_149 = ( V_147 -> V_71 - V_98 -> V_71 ) ;
int V_150 = ( V_147 -> V_70 - V_98 -> V_70 ) ;
int V_151 = V_149 + V_150 ;
if ( ( V_149 >= 0 ) && ( V_150 >= 0 ) && ( V_151 < V_144 ) ) {
V_144 = V_151 ;
V_143 = V_147 ;
}
}
if ( ! V_143 )
V_143 = & V_10 -> V_148 [ 0 ] ;
* V_142 = * V_143 ;
}
static int F_60 ( struct V_1 * V_10 , struct V_133 * V_152 ,
const struct V_134 * * V_153 ,
struct V_141 * V_154 )
{
const struct V_134 * V_155 ;
struct V_141 V_156 ;
struct V_140 * V_98 = & V_152 -> V_97 . V_98 ;
struct V_157 V_158 ;
struct V_159 V_160 = {
. V_161 = V_162 ,
} ;
int V_52 ;
V_155 = F_58 ( V_10 , V_98 -> V_163 ) ;
if ( ! V_155 ) {
V_155 = V_10 -> V_139 [ V_10 -> V_137 - 1 ] ;
V_98 -> V_163 = V_155 -> V_135 ;
}
V_98 -> V_71 = F_61 ( V_98 -> V_71 , V_164 , V_165 ) ;
V_98 -> V_70 = F_61 ( V_98 -> V_70 , V_166 , V_167 ) ;
if ( V_10 -> V_123 && V_10 -> V_146 ) {
struct V_141 V_168 ;
F_59 ( V_10 , V_98 , & V_168 ) ;
V_98 -> V_71 = V_168 . V_71 ;
V_98 -> V_70 = V_168 . V_70 ;
}
F_62 ( & V_160 . V_160 , V_98 , V_155 -> V_169 ) ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 , V_171 ,
& V_158 , & V_160 ) ;
if ( V_52 < 0 )
return V_52 ;
F_63 ( V_98 , & V_160 . V_160 ) ;
V_156 . V_71 = V_98 -> V_71 ;
V_156 . V_70 = V_98 -> V_70 ;
if ( V_10 -> V_123 ) {
struct V_172 V_173 = V_10 -> V_69 ;
struct V_172 V_174 ;
V_174 . V_73 = 0 ;
V_174 . V_74 = 0 ;
V_174 . V_71 = V_98 -> V_71 ;
V_174 . V_70 = V_98 -> V_70 ;
F_64 ( & V_173 , & V_174 ) ;
V_173 . V_73 = F_65 ( V_175 , V_173 . V_73 , 0 , V_98 -> V_70 - V_173 . V_70 ) ;
V_173 . V_74 = F_65 ( V_175 , V_173 . V_74 , 0 , V_98 -> V_71 - V_173 . V_71 ) ;
V_10 -> V_69 = V_173 ;
V_98 -> V_71 = V_10 -> V_69 . V_71 ;
V_98 -> V_70 = V_10 -> V_69 . V_70 ;
}
V_98 -> V_32 = V_33 ;
V_98 -> V_176 = V_98 -> V_71 * V_155 -> V_177 ;
V_98 -> V_99 = V_98 -> V_176 * V_98 -> V_70 ;
if ( V_153 )
* V_153 = V_155 ;
if ( V_154 )
* V_154 = V_156 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_10 , struct V_133 * V_152 )
{
struct V_159 V_160 = {
. V_161 = V_178 ,
} ;
const struct V_134 * V_153 ;
struct V_141 V_154 ;
struct V_179 * V_180 = & V_160 . V_160 ;
struct V_140 * V_98 = & V_152 -> V_97 . V_98 ;
int V_52 ;
V_52 = F_60 ( V_10 , V_152 , & V_153 , & V_154 ) ;
if ( V_52 )
return V_52 ;
F_62 ( V_180 , V_98 ,
V_153 -> V_169 ) ;
V_180 -> V_71 = V_154 . V_71 ;
V_180 -> V_70 = V_154 . V_70 ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 ,
V_171 , NULL , & V_160 ) ;
if ( V_52 < 0 )
return V_52 ;
F_12 ( V_10 -> V_20 , L_28 ,
V_180 -> V_181 , V_180 -> V_71 , V_180 -> V_70 ) ;
F_12 ( V_10 -> V_20 , L_29 ,
( char * ) & V_98 -> V_163 ,
V_98 -> V_71 , V_98 -> V_70 ) ;
V_10 -> V_97 = * V_152 ;
V_10 -> V_153 = V_153 ;
V_10 -> V_154 = V_154 ;
return 0 ;
}
static int F_67 ( struct V_131 * V_131 , void * V_132 ,
struct V_133 * V_152 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
if ( F_68 ( & V_10 -> V_182 ) )
return - V_183 ;
return F_66 ( V_10 , V_152 ) ;
}
static int F_69 ( struct V_131 * V_131 , void * V_132 ,
struct V_133 * V_152 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
return F_60 ( V_10 , V_152 , NULL , NULL ) ;
}
static int F_70 ( struct V_131 * V_131 , void * V_132 ,
struct V_184 * V_152 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
if ( V_152 -> V_38 >= V_10 -> V_137 )
return - V_65 ;
V_152 -> V_163 = V_10 -> V_139 [ V_152 -> V_38 ] -> V_135 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_10 ,
struct V_140 * V_98 )
{
struct V_159 V_97 = {
. V_161 = V_178 ,
} ;
int V_52 ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 , V_185 , NULL , & V_97 ) ;
if ( V_52 )
return V_52 ;
F_63 ( V_98 , & V_97 . V_160 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_10 ,
struct V_140 * V_98 )
{
const struct V_134 * V_155 ;
struct V_159 V_160 = {
. V_161 = V_162 ,
} ;
struct V_157 V_158 ;
int V_52 ;
V_155 = F_58 ( V_10 , V_98 -> V_163 ) ;
if ( ! V_155 ) {
V_155 = V_10 -> V_139 [ V_10 -> V_137 - 1 ] ;
V_98 -> V_163 = V_155 -> V_135 ;
}
F_62 ( & V_160 . V_160 , V_98 , V_155 -> V_169 ) ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 , V_171 ,
& V_158 , & V_160 ) ;
if ( V_52 < 0 )
return V_52 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_10 ,
struct V_172 * V_186 )
{
struct V_187 V_188 = {
. V_161 = V_178 ,
. V_189 = V_190 ,
} ;
unsigned int V_191 , V_192 , V_193 ;
struct V_140 V_98 ;
unsigned int V_138 ;
int V_52 ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 , V_194 ,
NULL , & V_188 ) ;
if ( ! V_52 )
* V_186 = V_188 . V_186 ;
if ( V_52 != - V_111 )
return V_52 ;
V_191 = 0 ;
V_192 = 0 ;
V_193 = 0 ;
for ( V_138 = 0 ; V_138 < V_10 -> V_146 ; V_138 ++ ) {
struct V_141 * V_147 = & V_10 -> V_148 [ V_138 ] ;
unsigned int V_195 = V_147 -> V_71 * V_147 -> V_70 ;
if ( V_195 > V_193 ) {
V_193 = V_195 ;
V_191 = V_147 -> V_71 ;
V_192 = V_147 -> V_70 ;
}
}
if ( V_193 > 0 ) {
V_186 -> V_73 = 0 ;
V_186 -> V_74 = 0 ;
V_186 -> V_71 = V_191 ;
V_186 -> V_70 = V_192 ;
return 0 ;
}
V_52 = F_71 ( V_10 , & V_98 ) ;
if ( V_52 )
return V_52 ;
V_186 -> V_73 = 0 ;
V_186 -> V_74 = 0 ;
V_186 -> V_71 = V_98 . V_71 ;
V_186 -> V_70 = V_98 . V_70 ;
return 0 ;
}
static int F_74 ( struct V_131 * V_131 , void * V_196 ,
struct V_197 * V_198 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
if ( V_198 -> type != V_199 )
return - V_65 ;
switch ( V_198 -> V_189 ) {
case V_200 :
case V_190 :
V_198 -> V_186 = V_10 -> V_201 ;
return 0 ;
case V_202 :
if ( V_10 -> V_123 ) {
V_198 -> V_186 = V_10 -> V_69 ;
} else {
V_198 -> V_186 . V_73 = 0 ;
V_198 -> V_186 . V_74 = 0 ;
V_198 -> V_186 . V_71 = V_10 -> V_97 . V_97 . V_98 . V_71 ;
V_198 -> V_186 . V_70 = V_10 -> V_97 . V_97 . V_98 . V_70 ;
}
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_75 ( struct V_131 * V_131 , void * V_132 ,
struct V_197 * V_198 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
struct V_172 V_186 = V_198 -> V_186 ;
struct V_172 V_174 ;
struct V_140 V_98 ;
if ( V_198 -> type != V_199 ||
V_198 -> V_189 != V_202 )
return - V_65 ;
V_98 . V_163 = V_10 -> V_97 . V_97 . V_98 . V_163 ;
V_98 . V_71 = V_10 -> V_201 . V_71 ;
V_98 . V_70 = V_10 -> V_201 . V_70 ;
F_72 ( V_10 , & V_98 ) ;
V_174 . V_73 = 0 ;
V_174 . V_74 = 0 ;
V_174 . V_71 = V_98 . V_71 ;
V_174 . V_70 = V_98 . V_70 ;
F_64 ( & V_186 , & V_174 ) ;
V_186 . V_73 = F_65 ( V_175 , V_186 . V_73 , 0 , V_98 . V_70 - V_186 . V_70 ) ;
V_186 . V_74 = F_65 ( V_175 , V_186 . V_74 , 0 , V_98 . V_71 - V_186 . V_71 ) ;
if ( ! ( ( V_186 . V_73 == V_10 -> V_201 . V_73 ) &&
( V_186 . V_74 == V_10 -> V_201 . V_74 ) &&
( V_186 . V_71 == V_10 -> V_201 . V_71 ) &&
( V_186 . V_70 == V_10 -> V_201 . V_70 ) ) ) {
V_10 -> V_123 = true ;
V_10 -> V_69 = V_186 ;
F_12 ( V_10 -> V_20 , L_30 ,
V_186 . V_71 , V_186 . V_70 , V_186 . V_74 , V_186 . V_73 ,
V_98 . V_71 , V_98 . V_70 ) ;
} else {
V_10 -> V_123 = false ;
F_12 ( V_10 -> V_20 , L_31 ) ;
}
V_198 -> V_186 = V_186 ;
return 0 ;
}
static int F_76 ( struct V_131 * V_131 , void * V_132 ,
struct V_203 * V_204 )
{
F_77 ( V_204 -> V_205 , V_206 , sizeof( V_204 -> V_205 ) ) ;
F_77 ( V_204 -> V_207 , L_32 ,
sizeof( V_204 -> V_207 ) ) ;
F_77 ( V_204 -> V_208 , L_33 , sizeof( V_204 -> V_208 ) ) ;
return 0 ;
}
static int F_78 ( struct V_131 * V_131 , void * V_132 ,
struct V_209 * V_138 )
{
if ( V_138 -> V_38 != 0 )
return - V_65 ;
V_138 -> type = V_210 ;
F_77 ( V_138 -> V_211 , L_34 , sizeof( V_138 -> V_211 ) ) ;
return 0 ;
}
static int F_79 ( struct V_131 * V_131 , void * V_132 , unsigned int * V_138 )
{
* V_138 = 0 ;
return 0 ;
}
static int F_80 ( struct V_131 * V_131 , void * V_132 , unsigned int V_138 )
{
if ( V_138 > 0 )
return - V_65 ;
return 0 ;
}
static int F_81 ( struct V_131 * V_131 , void * V_196 ,
struct V_212 * V_147 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
const struct V_134 * V_155 ;
struct V_213 V_214 = {
. V_38 = V_147 -> V_38 ,
. V_161 = V_178 ,
} ;
int V_52 ;
V_155 = F_58 ( V_10 , V_147 -> V_215 ) ;
if ( ! V_155 )
return - V_65 ;
V_214 . V_181 = V_155 -> V_169 ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 , V_216 ,
NULL , & V_214 ) ;
if ( V_52 )
return V_52 ;
V_147 -> type = V_217 ;
V_147 -> V_218 . V_71 = V_214 . V_191 ;
V_147 -> V_218 . V_70 = V_214 . V_192 ;
return 0 ;
}
static int F_82 ( struct V_131 * V_131 , void * V_196 ,
struct V_219 * V_220 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
const struct V_134 * V_155 ;
struct V_221 V_222 = {
. V_38 = V_220 -> V_38 ,
. V_71 = V_220 -> V_71 ,
. V_70 = V_220 -> V_70 ,
. V_161 = V_178 ,
} ;
int V_52 ;
V_155 = F_58 ( V_10 , V_220 -> V_215 ) ;
if ( ! V_155 )
return - V_65 ;
V_222 . V_181 = V_155 -> V_169 ;
V_52 = F_48 ( V_10 -> V_107 . V_108 , V_170 ,
V_223 , NULL , & V_222 ) ;
if ( V_52 )
return V_52 ;
V_220 -> type = V_224 ;
V_220 -> V_218 = V_222 . V_225 ;
return 0 ;
}
static int F_83 ( struct V_131 * V_131 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
struct V_226 * V_227 = V_10 -> V_107 . V_108 ;
int V_52 ;
if ( F_84 ( & V_10 -> V_228 ) )
return - V_229 ;
V_52 = F_85 ( V_131 ) ;
if ( V_52 < 0 )
goto V_230;
if ( ! F_86 ( V_131 ) )
goto V_231;
V_52 = F_48 ( V_227 , V_232 , V_233 , 1 ) ;
if ( V_52 < 0 && V_52 != - V_111 )
goto V_231;
V_52 = F_66 ( V_10 , & V_10 -> V_97 ) ;
if ( V_52 )
F_48 ( V_227 , V_232 , V_233 , 0 ) ;
V_231:
if ( V_52 )
F_87 ( V_131 ) ;
V_230:
F_88 ( & V_10 -> V_228 ) ;
return V_52 ;
}
static int F_89 ( struct V_131 * V_131 )
{
struct V_1 * V_10 = F_57 ( V_131 ) ;
struct V_226 * V_227 = V_10 -> V_107 . V_108 ;
bool V_234 ;
int V_52 ;
F_90 ( & V_10 -> V_228 ) ;
V_234 = F_86 ( V_131 ) ;
V_52 = F_91 ( V_131 , NULL ) ;
if ( V_234 )
F_48 ( V_227 , V_232 , V_233 , 0 ) ;
F_88 ( & V_10 -> V_228 ) ;
return V_52 ;
}
static int F_92 ( struct V_1 * V_10 )
{
struct V_133 V_152 = {
. type = V_199 ,
. V_97 . V_98 = {
. V_71 = V_235 ,
. V_70 = V_236 ,
. V_32 = V_33 ,
. V_163 = V_10 -> V_139 [ 0 ] -> V_135 ,
} ,
} ;
int V_52 ;
V_52 = F_60 ( V_10 , & V_152 , NULL , NULL ) ;
if ( V_52 )
return V_52 ;
V_10 -> V_153 = V_10 -> V_139 [ 0 ] ;
V_10 -> V_97 = V_152 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_10 )
{
const struct V_134 * V_237 [ F_94 ( V_238 ) ] ;
unsigned int V_239 = 0 , V_138 , V_240 ;
struct V_226 * V_108 = V_10 -> V_107 . V_108 ;
struct V_241 V_169 = {
. V_161 = V_178 ,
} ;
while ( ! F_48 ( V_108 , V_170 , V_242 ,
NULL , & V_169 ) ) {
for ( V_138 = 0 ; V_138 < F_94 ( V_238 ) ; V_138 ++ ) {
if ( V_238 [ V_138 ] . V_169 != V_169 . V_181 )
continue;
for ( V_240 = 0 ; V_240 < V_239 ; V_240 ++ )
if ( V_237 [ V_240 ] -> V_135 ==
V_238 [ V_138 ] . V_135 )
break;
if ( V_240 == V_239 )
V_237 [ V_239 ++ ] = V_238 + V_138 ;
}
V_169 . V_38 ++ ;
}
if ( ! V_239 )
return - V_68 ;
V_10 -> V_137 = V_239 ;
V_10 -> V_139 = F_95 ( V_10 -> V_20 ,
V_239 , sizeof( struct V_134 * ) ,
V_243 ) ;
if ( ! V_10 -> V_139 ) {
F_13 ( V_10 -> V_20 , L_35 ) ;
return - V_244 ;
}
memcpy ( V_10 -> V_139 , V_237 ,
V_239 * sizeof( struct V_134 * ) ) ;
V_10 -> V_153 = V_10 -> V_139 [ 0 ] ;
return 0 ;
}
static int F_96 ( struct V_1 * V_10 )
{
unsigned int V_245 = 0 ;
struct V_226 * V_108 = V_10 -> V_107 . V_108 ;
struct V_213 V_214 = {
. V_161 = V_178 ,
. V_181 = V_10 -> V_153 -> V_169 ,
} ;
unsigned int V_52 ;
unsigned int V_138 ;
while ( ! F_48 ( V_108 , V_170 , V_216 ,
NULL , & V_214 ) )
V_214 . V_38 ++ ;
V_245 = V_214 . V_38 ;
if ( ! V_245 )
return 0 ;
V_10 -> V_146 = V_245 ;
V_10 -> V_148 = F_95 ( V_10 -> V_20 , V_245 ,
sizeof( struct V_141 ) ,
V_243 ) ;
if ( ! V_10 -> V_148 ) {
F_13 ( V_10 -> V_20 , L_35 ) ;
return - V_244 ;
}
F_12 ( V_10 -> V_20 , L_36 , V_245 ) ;
for ( V_138 = 0 ; V_138 < V_10 -> V_146 ; V_138 ++ ) {
V_214 . V_38 = V_138 ;
V_52 = F_48 ( V_108 , V_170 , V_216 ,
NULL , & V_214 ) ;
if ( V_52 )
return V_52 ;
V_10 -> V_148 [ V_214 . V_38 ] . V_71 = V_214 . V_191 ;
V_10 -> V_148 [ V_214 . V_38 ] . V_70 = V_214 . V_192 ;
F_12 ( V_10 -> V_20 , L_37 , V_214 . V_191 , V_214 . V_192 ) ;
}
return 0 ;
}
static int F_97 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_52 ;
V_10 -> V_246 -> V_247 = V_10 -> V_107 . V_108 -> V_247 ;
V_52 = F_93 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_38 ) ;
return V_52 ;
}
V_52 = F_96 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_39 ) ;
return V_52 ;
}
V_52 = F_73 ( V_10 , & V_10 -> V_201 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_40 ) ;
return V_52 ;
}
V_52 = F_92 ( V_10 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_41 ) ;
return V_52 ;
}
V_52 = F_98 ( V_10 -> V_246 , V_248 , - 1 ) ;
if ( V_52 ) {
F_13 ( V_10 -> V_20 , L_42 ) ;
return V_52 ;
}
F_12 ( V_10 -> V_20 , L_43 ,
F_99 ( V_10 -> V_246 ) ) ;
return 0 ;
}
static void F_100 ( struct V_2 * V_4 ,
struct V_226 * V_227 ,
struct V_249 * V_250 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_12 ( V_10 -> V_20 , L_44 , F_99 ( V_10 -> V_246 ) ) ;
F_101 ( V_10 -> V_246 ) ;
}
static int F_102 ( struct V_2 * V_4 ,
struct V_226 * V_108 ,
struct V_249 * V_250 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_12 ( V_10 -> V_20 , L_45 , V_108 -> V_211 ) ;
V_10 -> V_107 . V_108 = V_108 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_10 , struct V_251 * V_104 )
{
struct V_251 * V_252 = NULL ;
struct V_251 * V_253 ;
while ( 1 ) {
V_252 = F_104 ( V_104 , V_252 ) ;
if ( ! V_252 )
return - V_65 ;
V_253 = F_105 ( V_252 ) ;
if ( ! V_253 ) {
F_106 ( V_252 ) ;
return - V_65 ;
}
V_10 -> V_107 . V_104 = V_253 ;
V_10 -> V_107 . V_250 . V_254 = V_255 ;
V_10 -> V_107 . V_250 . V_143 . V_256 . V_256 = F_107 ( V_253 ) ;
return 0 ;
}
}
static int F_108 ( struct V_1 * V_10 )
{
struct V_249 * * V_257 = NULL ;
int V_52 ;
V_52 = F_103 ( V_10 , V_10 -> V_20 -> V_258 ) ;
if ( V_52 < 0 ) {
F_13 ( V_10 -> V_20 , L_46 ) ;
return V_52 ;
}
V_257 = F_109 ( V_10 -> V_20 , sizeof( * V_257 ) , V_243 ) ;
if ( ! V_257 ) {
F_106 ( V_10 -> V_107 . V_104 ) ;
return - V_244 ;
}
V_257 [ 0 ] = & V_10 -> V_107 . V_250 ;
V_10 -> V_4 . V_257 = V_257 ;
V_10 -> V_4 . V_259 = 1 ;
V_10 -> V_4 . V_260 = F_102 ;
V_10 -> V_4 . V_261 = F_100 ;
V_10 -> V_4 . F_30 = F_97 ;
V_52 = F_110 ( & V_10 -> V_262 , & V_10 -> V_4 ) ;
if ( V_52 < 0 ) {
F_13 ( V_10 -> V_20 , L_47 ) ;
F_106 ( V_10 -> V_107 . V_104 ) ;
return V_52 ;
}
return 0 ;
}
static int F_111 ( struct V_263 * V_264 )
{
struct V_251 * V_265 = V_264 -> V_20 . V_258 ;
const struct V_266 * V_143 = NULL ;
struct V_267 V_252 ;
struct V_1 * V_10 ;
struct V_90 * V_268 ;
struct V_11 * V_12 ;
struct V_269 * V_105 ;
int V_77 ;
int V_52 = 0 ;
V_143 = F_112 ( F_113 ( V_270 ) , & V_264 -> V_20 ) ;
if ( ! V_143 ) {
F_13 ( & V_264 -> V_20 , L_48 ) ;
return - V_271 ;
}
V_10 = F_109 ( & V_264 -> V_20 , sizeof( struct V_1 ) , V_243 ) ;
if ( ! V_10 )
return - V_244 ;
V_10 -> V_272 = F_114 ( & V_264 -> V_20 , NULL ) ;
if ( F_115 ( V_10 -> V_272 ) ) {
F_13 ( & V_264 -> V_20 , L_49 ) ;
return - V_271 ;
}
V_265 = F_104 ( V_265 , NULL ) ;
if ( ! V_265 ) {
F_13 ( & V_264 -> V_20 , L_50 ) ;
F_106 ( V_265 ) ;
return - V_271 ;
}
V_52 = F_116 ( F_107 ( V_265 ) , & V_252 ) ;
if ( V_52 ) {
F_13 ( & V_264 -> V_20 , L_51 ) ;
F_106 ( V_265 ) ;
return - V_271 ;
}
if ( V_252 . V_273 == V_274 ) {
F_13 ( & V_264 -> V_20 , L_52 ) ;
F_106 ( V_265 ) ;
return - V_271 ;
}
V_10 -> V_113 . V_102 = V_252 . V_113 . V_275 . V_102 ;
V_10 -> V_113 . V_114 = V_252 . V_113 . V_275 . V_114 ;
V_10 -> V_113 . V_276 = V_252 . V_113 . V_275 . V_276 ;
F_106 ( V_265 ) ;
V_77 = F_117 ( V_264 , 0 ) ;
if ( V_77 <= 0 ) {
F_13 ( & V_264 -> V_20 , L_53 ) ;
return - V_271 ;
}
V_10 -> V_55 = F_118 ( V_264 , V_277 , 0 ) ;
if ( ! V_10 -> V_55 ) {
F_13 ( & V_264 -> V_20 , L_54 ) ;
return - V_271 ;
}
V_10 -> V_45 = F_119 ( & V_264 -> V_20 , V_10 -> V_55 ) ;
if ( F_115 ( V_10 -> V_45 ) ) {
F_13 ( & V_264 -> V_20 , L_55 ) ;
return F_120 ( V_10 -> V_45 ) ;
}
V_52 = F_121 ( & V_264 -> V_20 , V_77 , F_33 ,
F_29 , V_278 ,
F_122 ( & V_264 -> V_20 ) , V_10 ) ;
if ( V_52 ) {
F_13 ( & V_264 -> V_20 , L_56 , V_77 ) ;
return - V_271 ;
}
V_105 = F_123 ( & V_264 -> V_20 , L_57 ) ;
if ( F_115 ( V_105 ) ) {
F_13 ( & V_264 -> V_20 , L_58 ) ;
return F_120 ( V_105 ) ;
}
V_12 = F_124 ( & V_264 -> V_20 , L_59 ) ;
if ( ! V_12 ) {
F_125 ( & V_264 -> V_20 , L_60 ) ;
return - V_279 ;
}
V_52 = F_126 ( V_105 ) ;
if ( V_52 ) {
F_13 ( & V_264 -> V_20 , L_61 , V_105 ) ;
goto V_280;
}
F_127 ( & V_10 -> V_17 ) ;
F_128 ( & V_10 -> V_228 ) ;
F_129 ( & V_10 -> F_30 ) ;
F_38 ( & V_10 -> V_41 ) ;
V_10 -> V_20 = & V_264 -> V_20 ;
V_10 -> V_105 = V_105 ;
V_10 -> V_14 = V_84 ;
V_10 -> V_11 = V_12 ;
V_268 = & V_10 -> V_182 ;
V_52 = F_130 ( & V_264 -> V_20 , & V_10 -> V_262 ) ;
if ( V_52 )
goto V_281;
V_10 -> V_246 = F_131 () ;
if ( ! V_10 -> V_246 ) {
V_52 = - V_244 ;
goto V_282;
}
V_10 -> V_246 -> V_283 = & V_284 ;
V_10 -> V_246 -> V_262 = & V_10 -> V_262 ;
V_10 -> V_246 -> V_182 = & V_10 -> V_182 ;
F_77 ( V_10 -> V_246 -> V_211 , V_285 , sizeof( V_10 -> V_246 -> V_211 ) ) ;
V_10 -> V_246 -> V_286 = V_287 ;
V_10 -> V_246 -> V_288 = & V_289 ;
V_10 -> V_246 -> V_228 = & V_10 -> V_228 ;
V_10 -> V_246 -> V_290 = V_291 | V_292 |
V_293 ;
F_132 ( V_10 -> V_246 , V_10 ) ;
V_268 -> type = V_199 ;
V_268 -> V_294 = V_295 | V_296 | V_297 ;
V_268 -> V_228 = & V_10 -> V_228 ;
V_268 -> V_298 = V_10 ;
V_268 -> V_299 = sizeof( struct V_26 ) ;
V_268 -> V_300 = & V_301 ;
V_268 -> V_302 = & V_303 ;
V_268 -> V_304 = V_305 ;
V_268 -> V_306 = 2 ;
V_268 -> V_20 = & V_264 -> V_20 ;
V_52 = F_133 ( V_268 ) ;
if ( V_52 < 0 ) {
F_13 ( & V_264 -> V_20 , L_62 ) ;
goto V_307;
}
V_52 = F_108 ( V_10 ) ;
if ( V_52 < 0 )
goto V_307;
V_52 = F_134 ( V_10 -> V_272 ) ;
if ( V_52 ) {
F_13 ( & V_264 -> V_20 , L_63 ) ;
goto V_307;
}
F_135 ( 3000 , 5000 ) ;
V_52 = F_136 ( V_10 -> V_272 ) ;
if ( V_52 ) {
F_13 ( & V_264 -> V_20 , L_64 ) ;
goto V_307;
}
F_125 ( & V_264 -> V_20 , L_65 ) ;
F_137 ( V_264 , V_10 ) ;
return 0 ;
V_307:
V_287 ( V_10 -> V_246 ) ;
V_282:
F_138 ( & V_10 -> V_262 ) ;
V_281:
F_139 ( V_10 -> V_105 ) ;
V_280:
F_140 ( V_10 -> V_11 ) ;
return V_52 ;
}
static int F_141 ( struct V_263 * V_264 )
{
struct V_1 * V_10 = F_142 ( V_264 ) ;
F_143 ( & V_10 -> V_4 ) ;
F_138 ( & V_10 -> V_262 ) ;
F_139 ( V_10 -> V_105 ) ;
F_140 ( V_10 -> V_11 ) ;
return 0 ;
}
