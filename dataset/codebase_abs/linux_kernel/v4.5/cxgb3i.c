static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = (struct V_9 * ) V_4 -> V_11 ;
V_4 -> V_12 = V_13 ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_16 ) ) ;
F_5 ( V_10 ) = F_3 ( F_6 ( V_17 , V_2 -> V_18 ) ) ;
V_10 -> V_19 = V_2 -> V_20 . V_21 ;
V_10 -> V_22 = V_2 -> V_23 . V_21 ;
V_10 -> V_24 = V_2 -> V_20 . V_25 . V_26 ;
V_10 -> V_27 = V_2 -> V_23 . V_25 . V_26 ;
V_10 -> V_28 = F_3 ( F_7 ( 1 ) | V_29 |
F_8 ( V_7 ) | F_9 ( V_2 -> V_30 ) |
F_10 ( V_6 -> V_31 ) | F_11 ( V_6 -> V_32 ) ) ;
V_10 -> V_33 = F_3 ( F_12 ( V_34 ) |
F_13 ( V_2 -> V_8 >> 10 ) ) ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_1 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_18 ,
& V_10 -> V_24 , F_15 ( V_10 -> V_19 ) ,
& V_10 -> V_27 , F_15 ( V_10 -> V_22 ) ,
V_2 -> V_30 , V_6 -> V_31 , V_6 -> V_32 ) ;
F_16 ( V_2 -> V_39 -> V_40 , V_4 , V_2 -> V_41 ) ;
}
static inline void F_17 ( struct V_42 * V_43 , struct V_3 * V_4 )
{
F_18 ( NULL , V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_44 ;
struct V_45 * V_10 = (struct V_45 * ) V_4 -> V_11 ;
unsigned int V_46 = V_2 -> V_46 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_2 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
V_2 -> V_44 = NULL ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_47 ) ) ;
V_10 -> V_14 . V_48 = F_3 ( F_20 ( V_46 ) ) ;
F_5 ( V_10 ) = F_3 ( F_6 ( V_49 , V_46 ) ) ;
V_10 -> V_50 = F_3 ( V_2 -> V_51 ) ;
F_21 ( V_2 , V_4 ) ;
if ( V_2 -> V_37 >= V_52 )
F_22 ( V_2 , 1 ) ;
}
static void F_23 ( struct V_42 * V_53 , struct V_3 * V_4 )
{
struct V_54 * V_10 = F_24 ( V_4 ) ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_3 ,
V_53 , F_25 ( V_10 ) , V_4 ) ;
V_10 -> V_55 = V_56 ;
F_26 ( V_53 , V_4 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_54 ;
struct V_54 * V_10 ;
if ( F_28 ( V_2 -> V_37 == V_57 || ! V_4 ) )
return;
F_29 ( V_2 , V_57 ) ;
F_30 ( V_2 , V_58 ) ;
F_31 ( V_2 ) ;
V_2 -> V_54 = NULL ;
V_10 = (struct V_54 * ) V_4 -> V_11 ;
V_4 -> V_12 = V_59 ;
F_32 ( V_4 , F_23 ) ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_60 ) ) ;
V_10 -> V_14 . V_48 = F_3 ( F_20 ( V_2 -> V_46 ) ) ;
F_5 ( V_10 ) = F_3 ( F_6 ( V_61 , V_2 -> V_46 ) ) ;
V_10 -> V_62 = F_3 ( V_2 -> V_63 ) ;
V_10 -> V_64 = ! F_33 ( V_2 , V_65 ) ;
V_10 -> V_55 = V_66 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_4 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 , V_2 -> V_63 ,
V_10 -> V_64 ) ;
F_16 ( V_2 -> V_39 -> V_40 , V_4 , V_2 -> V_41 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_68 ;
struct V_68 * V_69 = (struct V_68 * ) V_4 -> V_11 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_5 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 , V_67 ) ;
V_2 -> V_68 = NULL ;
V_4 -> V_12 = V_59 ;
V_69 -> V_14 . V_15 = F_3 ( F_4 ( V_70 ) ) ;
V_69 -> V_14 . V_48 = F_3 ( F_20 ( V_2 -> V_46 ) ) ;
F_5 ( V_69 ) = F_3 ( F_6 ( V_71 , V_2 -> V_46 ) ) ;
V_69 -> V_55 = V_67 ;
F_26 ( V_2 -> V_39 -> V_40 , V_4 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , T_1 V_72 )
{
struct V_3 * V_4 ;
struct V_73 * V_10 ;
T_1 V_74 = V_75 | F_36 ( 1 ) ;
F_14 ( 1 << V_35 | 1 << V_76 ,
L_6 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 , V_72 , V_74 ) ;
V_4 = F_37 ( sizeof( * V_10 ) , 0 , V_77 ) ;
if ( ! V_4 ) {
F_38 ( L_7 , V_2 , V_72 ) ;
return 0 ;
}
V_10 = (struct V_73 * ) V_4 -> V_11 ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_16 ) ) ;
F_5 ( V_10 ) = F_3 ( F_6 ( V_78 , V_2 -> V_46 ) ) ;
V_10 -> V_79 = F_3 ( V_75 | F_36 ( 1 ) |
F_39 ( V_72 ) ) ;
V_4 -> V_12 = V_80 ;
F_26 ( V_2 -> V_39 -> V_40 , V_4 ) ;
return V_72 ;
}
static void F_40 ( unsigned int V_81 )
{
int V_82 ;
if ( V_83 [ 1 ] )
return;
for ( V_82 = 1 ; V_82 < V_84 ; V_82 ++ ) {
int V_85 = ( 3 * V_82 ) / 2 + ( V_82 & 1 ) ;
V_85 += 3 ;
V_83 [ V_82 ] = ( V_85 <= V_81
? 1 : 1 + ( V_85 - 2 ) / ( V_81 - 1 ) ) ;
}
V_86 = V_81 * 8 ;
}
static inline void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_87 , int V_88 )
{
struct V_89 * V_10 ;
struct V_5 * V_41 = V_2 -> V_41 ;
F_42 ( V_4 ) ;
V_10 = (struct V_89 * ) F_43 ( V_4 , sizeof( * V_10 ) ) ;
V_10 -> V_15 = F_3 ( F_4 ( V_90 ) |
( V_88 ? V_91 : 0 ) ) ;
V_10 -> V_48 = F_3 ( F_20 ( V_2 -> V_46 ) ) ;
V_10 -> V_87 = F_3 ( V_87 ) ;
V_10 -> V_38 = F_3 ( F_44 ( F_45 ( V_4 ) ) |
F_46 ( ( F_47 ( & V_2 -> V_92 ) ? 0 : 1 ) ) ) ;
V_10 -> V_93 = F_3 ( V_2 -> V_63 ) ;
V_10 -> V_94 = F_3 ( F_48 ( V_41 -> V_32 ) ) ;
if ( ! F_33 ( V_2 , V_65 ) ) {
V_10 -> V_38 |= F_3 ( F_49 ( 2 ) | V_95 |
F_50 ( V_2 -> V_96 ) ) ;
V_10 -> V_94 |= F_3 ( F_51 ( V_2 -> V_97 >> 15 ) ) ;
F_30 ( V_2 , V_65 ) ;
}
}
static void F_52 ( struct V_42 * V_43 , struct V_3 * V_4 )
{
F_53 ( V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_88 )
{
int V_98 = 0 ;
struct V_3 * V_4 ;
if ( F_28 ( V_2 -> V_37 < V_52 ||
V_2 -> V_37 == V_99 || V_2 -> V_37 >= V_57 ) ) {
F_14 ( 1 << V_35 | 1 << V_100 ,
L_8 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
return 0 ;
}
while ( V_2 -> V_101 && ( V_4 = F_47 ( & V_2 -> V_92 ) ) != NULL ) {
int V_87 = V_4 -> V_87 ;
int V_102 = F_54 ( V_4 ) -> V_103 + ( V_87 != V_4 -> V_104 ) ;
int V_105 = V_83 [ V_102 ] ;
if ( V_105 > 1 && V_87 + sizeof( struct V_89 ) <= V_86 )
V_105 = 1 ;
F_55 ( V_102 >= V_84 || V_105 < 1 ) ;
if ( V_2 -> V_101 < V_105 ) {
F_14 ( 1 << V_100 ,
L_9 ,
V_2 , V_4 -> V_87 , V_4 -> V_104 , V_102 ,
V_105 , V_2 -> V_101 ) ;
break;
}
F_56 ( V_4 , & V_2 -> V_92 ) ;
V_4 -> V_12 = V_59 ;
V_4 -> V_106 = V_105 ;
V_2 -> V_101 -= V_105 ;
V_2 -> V_107 += V_105 ;
F_57 ( V_2 , V_4 ) ;
F_14 ( 1 << V_35 | 1 << V_100 ,
L_10
L_11 ,
V_2 , V_4 -> V_87 , V_4 -> V_104 , V_102 , V_4 -> V_106 ,
V_2 -> V_101 , V_2 -> V_107 ) ;
if ( F_58 ( F_59 ( V_4 , V_108 ) ) ) {
if ( ( V_88 &&
V_2 -> V_107 == V_105 ) ||
V_2 -> V_107 >= V_2 -> V_109 / 2 ) {
V_88 = 1 ;
V_2 -> V_107 = 0 ;
}
V_87 += F_60 ( F_45 ( V_4 ) ) ;
F_41 ( V_2 , V_4 , V_87 , V_88 ) ;
V_2 -> V_63 += V_87 ;
F_61 ( V_4 , V_108 ) ;
}
V_98 += V_4 -> V_110 ;
F_14 ( 1 << V_35 | 1 << V_100 ,
L_12 ,
V_2 , V_2 -> V_46 , V_4 ) ;
F_32 ( V_4 , F_52 ) ;
F_16 ( V_2 -> V_39 -> V_40 , V_4 , V_2 -> V_41 ) ;
}
return V_98 ;
}
static inline void F_62 ( struct V_1 * V_2 )
{
if ( F_33 ( V_2 , V_111 ) ) {
F_63 ( V_2 -> V_39 -> V_40 , V_2 -> V_18 ) ;
F_64 ( V_2 , V_111 ) ;
F_65 ( V_2 ) ;
}
}
static int F_66 ( struct V_42 * V_53 , struct V_3 * V_4 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_113 * V_10 = F_24 ( V_4 ) ;
unsigned int V_46 = F_25 ( V_10 ) ;
unsigned int V_18 = F_67 ( F_68 ( V_10 -> V_114 ) ) ;
T_1 V_115 = F_68 ( V_10 -> V_115 ) ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_13 ,
V_18 , V_18 , V_2 , V_2 -> V_37 , V_2 -> V_38 , V_115 ) ;
F_69 ( V_2 ) ;
F_30 ( V_2 , V_116 ) ;
V_2 -> V_46 = V_46 ;
F_70 ( V_2 -> V_39 -> V_40 , & V_117 , V_2 , V_46 ) ;
F_62 ( V_2 ) ;
V_2 -> V_96 = F_71 ( F_15 ( V_4 -> V_106 ) ) ;
F_72 ( & V_2 -> V_118 ) ;
if ( V_2 -> V_119 . V_120 ) {
F_73 ( & V_2 -> V_119 ) ;
V_2 -> V_119 . V_120 = NULL ;
}
if ( F_28 ( V_2 -> V_37 != V_121 ) )
F_38 ( L_14 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
V_2 -> V_122 = V_2 -> V_123 = V_2 -> V_124 = V_115 ;
if ( V_2 -> V_8 > ( V_125 << 10 ) )
V_2 -> V_123 -= V_2 -> V_8 - ( V_125 << 10 ) ;
F_74 ( V_2 , F_68 ( V_10 -> V_126 ) , F_15 ( V_10 -> V_127 ) ) ;
if ( F_28 ( F_33 ( V_2 , V_128 ) ) )
F_27 ( V_2 ) ;
else {
if ( F_75 ( & V_2 -> V_92 ) )
F_22 ( V_2 , 1 ) ;
F_76 ( V_2 ) ;
}
F_77 ( & V_2 -> V_118 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_79 ( int V_129 )
{
switch ( V_129 ) {
case V_130 :
return - V_131 ;
case V_132 :
return - V_133 ;
case V_134 :
return - V_135 ;
case V_136 :
return - V_137 ;
case V_138 :
return - V_139 ;
default:
return - V_140 ;
}
}
static void F_80 ( unsigned long V_141 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = (struct V_1 * ) V_141 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_2 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
F_69 ( V_2 ) ;
F_72 ( & V_2 -> V_118 ) ;
V_4 = F_37 ( sizeof( struct V_9 ) , 0 , V_77 ) ;
if ( ! V_4 )
F_81 ( V_2 , - V_137 ) ;
else {
V_4 -> V_142 = (struct V_143 * ) V_2 ;
F_32 ( V_4 , F_17 ) ;
F_1 ( V_2 , V_4 , V_2 -> V_41 ) ;
}
F_77 ( & V_2 -> V_118 ) ;
F_65 ( V_2 ) ;
}
static int F_82 ( struct V_42 * V_53 , struct V_3 * V_4 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_144 * V_69 = F_24 ( V_4 ) ;
F_38 ( L_15 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_18 , V_69 -> V_129 ,
& V_2 -> V_20 . V_25 . V_26 , F_15 ( V_2 -> V_20 . V_21 ) ,
& V_2 -> V_23 . V_25 . V_26 , F_15 ( V_2 -> V_23 . V_21 ) ) ;
if ( V_69 -> V_129 != V_136 &&
V_69 -> V_129 != V_138 &&
V_69 -> V_129 != V_132 )
F_83 ( V_53 , F_25 ( V_69 ) ) ;
F_69 ( V_2 ) ;
F_72 ( & V_2 -> V_118 ) ;
if ( V_69 -> V_129 == V_138 &&
V_2 -> V_119 . V_120 != F_80 ) {
V_2 -> V_119 . V_120 = F_80 ;
F_84 ( & V_2 -> V_119 , V_145 + V_146 / 2 ) ;
} else
F_81 ( V_2 ,
F_79 ( V_69 -> V_129 ) ) ;
F_77 ( & V_2 -> V_118 ) ;
F_65 ( V_2 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_85 ( struct V_42 * V_39 , struct V_3 * V_4 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_2 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
F_86 ( V_2 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_87 ( struct V_42 * V_39 , struct V_3 * V_4 ,
void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_147 * V_69 = F_24 ( V_4 ) ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_16 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 , F_68 ( V_69 -> V_63 ) ) ;
F_88 ( V_2 , F_68 ( V_69 -> V_63 ) ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_148 ,
int * V_149 )
{
switch ( V_148 ) {
case V_150 :
case V_130 :
return V_2 -> V_37 > V_52 ? - V_151 : - V_152 ;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
return - V_135 ;
default:
return - V_140 ;
}
}
static int F_90 ( struct V_42 * V_39 , struct V_3 * V_4 , void * V_112 )
{
const struct V_157 * V_10 = F_24 ( V_4 ) ;
struct V_1 * V_2 = V_112 ;
int V_67 = V_56 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_2 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
if ( V_10 -> V_129 == V_158 ||
V_10 -> V_129 == V_159 ) {
goto V_160;
}
F_69 ( V_2 ) ;
F_72 ( & V_2 -> V_118 ) ;
if ( ! F_33 ( V_2 , V_161 ) ) {
F_30 ( V_2 , V_161 ) ;
F_29 ( V_2 , V_57 ) ;
goto V_162;
}
F_64 ( V_2 , V_161 ) ;
F_34 ( V_2 , V_67 ) ;
if ( ! F_33 ( V_2 , V_58 ) ) {
V_2 -> V_163 = F_89 ( V_2 , V_10 -> V_129 , & V_67 ) ;
F_91 ( V_2 ) ;
}
V_162:
F_77 ( & V_2 -> V_118 ) ;
F_65 ( V_2 ) ;
V_160:
F_78 ( V_4 ) ;
return 0 ;
}
static int F_92 ( struct V_42 * V_39 , struct V_3 * V_4 , void * V_112 )
{
struct V_164 * V_69 = F_24 ( V_4 ) ;
struct V_1 * V_2 = V_112 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_17 ,
V_69 -> V_129 , V_2 , V_2 ? V_2 -> V_37 : 0 ,
V_2 ? V_2 -> V_38 : 0UL ) ;
if ( V_69 -> V_129 == V_165 )
goto V_166;
if ( V_2 )
F_93 ( V_2 ) ;
V_166:
F_78 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_42 * V_167 , struct V_3 * V_4 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_168 * V_169 = F_24 ( V_4 ) ;
struct V_170 V_171 ;
struct V_172 V_173 ;
unsigned int V_174 , V_104 , V_129 ;
unsigned int V_87 ;
int V_163 ;
F_14 ( 1 << V_35 | 1 << V_76 ,
L_18 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 , V_4 , V_4 -> V_87 ) ;
F_72 ( & V_2 -> V_118 ) ;
if ( F_28 ( V_2 -> V_37 >= V_175 ) ) {
F_14 ( 1 << V_35 | 1 << V_36 ,
L_19 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
if ( V_2 -> V_37 != V_57 )
goto V_176;
else
goto V_177;
}
F_95 ( V_4 ) = F_68 ( V_169 -> V_178 ) ;
F_96 ( V_4 ) = 0 ;
F_42 ( V_4 ) ;
F_97 ( V_4 , sizeof( struct V_168 ) ) ;
V_87 = V_174 = F_15 ( V_169 -> V_87 ) ;
if ( V_4 -> V_87 <= V_174 ) {
F_98 ( L_20 ,
V_2 -> V_39 -> V_179 [ V_2 -> V_180 ] -> V_181 , V_2 -> V_46 ,
V_4 -> V_87 , V_174 ) ;
goto V_176;
}
F_99 ( V_4 , V_182 ) ;
V_163 = F_100 ( V_4 , V_4 -> V_87 - sizeof( V_173 ) , & V_173 ,
sizeof( V_173 ) ) ;
if ( V_163 < 0 ) {
F_98 ( L_21 ,
V_2 -> V_39 -> V_179 [ V_2 -> V_180 ] -> V_181 , V_2 -> V_46 ,
V_4 -> V_87 , sizeof( V_173 ) , V_163 ) ;
goto V_176;
}
F_99 ( V_4 , V_183 ) ;
F_101 ( V_4 ) = F_15 ( V_173 . V_87 ) ;
F_102 ( V_4 ) = F_68 ( V_173 . V_184 ) ;
V_129 = F_68 ( V_173 . V_185 ) ;
F_14 ( 1 << V_35 | 1 << V_76 ,
L_22 ,
V_2 , V_4 , V_4 -> V_87 , F_101 ( V_4 ) , V_129 ) ;
if ( V_129 & ( 1 << V_186 ) )
F_99 ( V_4 , V_187 ) ;
if ( V_129 & ( 1 << V_188 ) )
F_99 ( V_4 , V_189 ) ;
if ( V_129 & ( 1 << V_190 ) )
F_99 ( V_4 , V_191 ) ;
if ( V_4 -> V_87 > ( V_174 + sizeof( V_173 ) ) ) {
V_163 = F_100 ( V_4 , V_174 , & V_171 , sizeof( V_171 ) ) ;
if ( V_163 < 0 ) {
F_98 ( L_23 ,
V_2 -> V_39 -> V_179 [ V_2 -> V_180 ] -> V_181 ,
V_2 -> V_46 , sizeof( V_171 ) , V_4 -> V_87 , V_163 ) ;
goto V_176;
}
V_104 = F_15 ( V_171 . V_87 ) ;
F_14 ( 1 << V_192 | 1 << V_76 ,
L_24 ,
V_4 , V_104 , F_101 ( V_4 ) , V_129 ) ;
V_87 += sizeof( V_171 ) + V_104 ;
} else if ( V_129 & ( 1 << V_193 ) )
F_99 ( V_4 , V_194 ) ;
V_2 -> V_124 = F_68 ( V_173 . V_178 ) + F_101 ( V_4 ) ;
F_103 ( V_4 , V_87 ) ;
F_104 ( & V_2 -> V_195 , V_4 ) ;
F_105 ( V_2 ) ;
F_77 ( & V_2 -> V_118 ) ;
return 0 ;
V_176:
F_27 ( V_2 ) ;
V_177:
F_77 ( & V_2 -> V_118 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_106 ( struct V_42 * V_39 , struct V_3 * V_4 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_196 * V_197 = F_24 ( V_4 ) ;
F_14 ( 1 << V_35 | 1 << V_76 ,
L_25 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 , F_15 ( V_197 -> V_72 ) ) ;
F_107 ( V_2 , F_15 ( V_197 -> V_72 ) , F_68 ( V_197 -> V_198 ) , 1 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 )
{
V_2 -> V_44 = F_37 ( sizeof( struct V_45 ) , 0 ,
V_199 ) ;
if ( ! V_2 -> V_44 )
return - V_137 ;
V_2 -> V_54 = F_37 ( sizeof( struct V_54 ) , 0 ,
V_199 ) ;
if ( ! V_2 -> V_54 )
goto V_200;
V_2 -> V_68 = F_37 ( sizeof( struct V_68 ) , 0 ,
V_199 ) ;
if ( ! V_2 -> V_68 )
goto V_200;
return 0 ;
V_200:
F_109 ( V_2 ) ;
return - V_137 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_42 * V_167 = (struct V_42 * ) V_2 -> V_39 -> V_40 ;
if ( V_2 -> V_41 ) {
F_111 ( V_167 , V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
F_65 ( V_2 ) ;
}
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_42 * V_167 = (struct V_42 * ) V_2 -> V_39 -> V_40 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_2 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_46 ) ;
V_2 -> V_96 = 0 ;
F_109 ( V_2 ) ;
if ( V_2 -> V_101 != V_2 -> V_109 ) {
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
}
F_110 ( V_2 ) ;
if ( F_33 ( V_2 , V_111 ) )
F_62 ( V_2 ) ;
else if ( F_33 ( V_2 , V_116 ) ) {
F_115 ( V_167 , ( void * ) V_2 , V_2 -> V_46 ) ;
F_64 ( V_2 , V_116 ) ;
F_65 ( V_2 ) ;
}
V_2 -> V_201 = NULL ;
V_2 -> V_39 = NULL ;
}
static void F_116 ( struct V_202 * V_203 )
{
if ( V_203 -> V_204 ) {
if ( V_203 -> V_205 &&
V_203 -> V_204 != F_117 ( V_203 -> V_205 ) ) {
F_118 ( V_203 -> V_205 , V_203 -> V_204 ) ;
F_118 ( V_203 -> V_206 , 0 ) ;
F_38 ( L_26 ,
V_203 -> V_205 -> V_181 , & V_203 -> V_204 ) ;
} else if ( V_203 -> V_204 !=
F_117 ( V_203 -> V_206 ) ) {
F_118 ( V_203 -> V_206 , V_203 -> V_204 ) ;
F_38 ( L_26 ,
V_203 -> V_206 -> V_181 , & V_203 -> V_204 ) ;
}
} else if ( F_117 ( V_203 -> V_206 ) ) {
if ( V_203 -> V_205 )
F_118 ( V_203 -> V_205 , 0 ) ;
F_118 ( V_203 -> V_206 , 0 ) ;
}
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_207 * V_201 = V_2 -> V_201 ;
struct V_208 * V_39 = V_2 -> V_39 ;
struct V_42 * V_167 = (struct V_42 * ) V_39 -> V_40 ;
struct V_209 * V_206 = V_39 -> V_179 [ V_2 -> V_180 ] ;
struct V_202 * V_203 = V_39 -> V_210 [ V_2 -> V_180 ] ;
struct V_3 * V_4 = NULL ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_27 , V_2 , V_2 -> V_37 , V_2 -> V_38 ) ;
F_116 ( V_203 ) ;
if ( V_203 -> V_204 )
V_2 -> V_20 . V_25 . V_26 = V_203 -> V_204 ;
V_2 -> V_96 = 0 ;
V_2 -> V_41 = F_120 ( V_167 , V_201 , V_206 ,
& V_2 -> V_23 . V_25 . V_26 ) ;
if ( ! V_2 -> V_41 ) {
F_98 ( L_28 ) ;
return - V_211 ;
}
F_69 ( V_2 ) ;
V_2 -> V_18 = F_121 ( V_167 , & V_117 , V_2 ) ;
if ( V_2 -> V_18 < 0 ) {
F_98 ( L_29 ) ;
goto V_212;
}
F_30 ( V_2 , V_111 ) ;
F_69 ( V_2 ) ;
V_4 = F_37 ( sizeof( struct V_9 ) , 0 , V_199 ) ;
if ( ! V_4 )
goto V_212;
V_4 -> V_142 = (struct V_143 * ) V_2 ;
F_32 ( V_4 , F_17 ) ;
V_2 -> V_97 = V_213 ;
V_2 -> V_8 = V_214 ;
V_2 -> V_109 = V_2 -> V_101 = F_122 ( V_167 ) -> V_215 - 1 ;
V_2 -> V_107 = 0 ;
V_2 -> V_30 = F_123 ( V_2 , F_124 ( V_201 ) ) ;
F_114 ( V_2 ) ;
V_2 -> V_163 = 0 ;
F_14 ( 1 << V_35 | 1 << V_36 ,
L_30 ,
V_2 , V_2 -> V_37 , V_2 -> V_38 ,
& V_2 -> V_20 . V_25 . V_26 , F_15 ( V_2 -> V_20 . V_21 ) ,
& V_2 -> V_23 . V_25 . V_26 , F_15 ( V_2 -> V_23 . V_21 ) ) ;
F_29 ( V_2 , V_121 ) ;
F_1 ( V_2 , V_4 , V_2 -> V_41 ) ;
return 0 ;
V_212:
if ( V_4 )
F_78 ( V_4 ) ;
return - V_211 ;
}
int F_125 ( struct V_208 * V_39 )
{
struct V_42 * V_167 = (struct V_42 * ) V_39 -> V_40 ;
struct V_216 V_217 ;
struct V_218 V_219 ;
unsigned int V_81 ;
int V_220 ;
if ( V_167 -> V_221 ( V_167 , V_222 , & V_81 ) < 0 ||
V_167 -> V_221 ( V_167 , V_223 , & V_217 ) < 0 ||
V_167 -> V_221 ( V_167 , V_224 , & V_219 ) < 0 ) {
F_126 ( L_31 , V_167 ) ;
return - V_211 ;
}
if ( V_225 > V_226 )
V_225 = V_226 ;
V_220 = F_127 ( V_39 , V_227 ,
V_225 ) ;
if ( V_220 < 0 )
return V_220 ;
F_40 ( V_81 ) ;
V_39 -> V_228 = F_112 ;
V_39 -> V_229 = F_22 ;
V_39 -> V_230 = F_27 ;
V_39 -> V_231 = F_19 ;
V_39 -> V_232 = F_35 ;
V_39 -> V_233 = F_108 ;
V_39 -> V_234 = F_119 ;
F_38 ( L_32 , V_39 ) ;
return 0 ;
}
static inline void F_128 ( struct V_3 * V_4 , unsigned int V_235 )
{
struct V_236 * V_10 = (struct V_236 * ) V_4 -> V_11 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_237 ) ) ;
V_10 -> V_238 = F_3 ( F_129 ( V_235 >> 5 ) |
F_130 ( V_239 ) ) ;
V_10 -> V_87 = F_3 ( F_131 ( V_240 >> 5 ) |
F_132 ( ( V_240 >> 3 ) + 1 ) ) ;
}
static int F_133 ( struct V_1 * V_2 , struct V_241 * V_197 ,
unsigned int V_31 , unsigned int V_242 ,
struct V_243 * V_244 )
{
struct V_208 * V_39 = V_2 -> V_39 ;
struct V_245 * V_246 = V_39 -> V_246 ;
unsigned int V_247 = ( V_31 << V_248 ) + V_246 -> V_249 ;
int V_82 ;
F_14 ( 1 << V_192 ,
L_33 ,
V_2 , V_31 , V_242 , V_244 ) ;
for ( V_82 = 0 ; V_82 < V_242 ; V_82 ++ , V_31 ++ , V_247 += V_240 ) {
struct V_3 * V_4 = F_37 ( sizeof( struct V_236 ) +
V_240 , 0 , V_77 ) ;
if ( ! V_4 )
return - V_137 ;
F_128 ( V_4 , V_247 ) ;
F_134 ( (struct V_250 * ) ( V_4 -> V_11 +
sizeof( struct V_236 ) ) ,
V_197 , V_244 , V_82 * V_251 ) ;
V_4 -> V_12 = V_252 ;
F_26 ( V_39 -> V_40 , V_4 ) ;
}
return 0 ;
}
static void F_135 ( struct V_202 * V_203 , unsigned int V_253 ,
unsigned int V_31 , unsigned int V_242 )
{
struct V_208 * V_39 = V_203 -> V_39 ;
struct V_245 * V_246 = V_39 -> V_246 ;
unsigned int V_247 = ( V_31 << V_248 ) + V_246 -> V_249 ;
int V_82 ;
F_14 ( 1 << V_192 ,
L_34 ,
V_39 , V_31 , V_242 , V_253 ) ;
for ( V_82 = 0 ; V_82 < V_242 ; V_82 ++ , V_31 ++ , V_247 += V_240 ) {
struct V_3 * V_4 = F_37 ( sizeof( struct V_236 ) +
V_240 , 0 , V_77 ) ;
if ( ! V_4 ) {
F_98 ( L_35 ,
V_253 , V_31 , V_82 , V_242 ) ;
continue;
}
F_128 ( V_4 , V_247 ) ;
V_4 -> V_12 = V_252 ;
F_26 ( V_39 -> V_40 , V_4 ) ;
}
}
static int F_136 ( struct V_1 * V_2 ,
unsigned int V_46 , int V_254 , bool V_255 )
{
struct V_3 * V_4 = F_37 ( sizeof( struct V_256 ) , 0 ,
V_199 ) ;
struct V_256 * V_10 ;
T_2 V_257 = V_254 < V_258 ? V_254 : 0 ;
F_14 ( 1 << V_192 ,
L_36 , V_2 , V_46 , V_254 ) ;
if ( ! V_4 )
return - V_137 ;
V_10 = (struct V_256 * ) V_4 -> V_11 ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_16 ) ) ;
F_5 ( V_10 ) = F_3 ( F_6 ( V_259 , V_46 ) ) ;
V_10 -> V_255 = F_137 ( V_255 ? 0 : 1 ) ;
V_10 -> V_260 = 0 ;
V_10 -> V_261 = F_138 ( 31 ) ;
V_10 -> V_262 = F_139 ( 0xF0000000 ) ;
V_10 -> V_257 = F_139 ( V_257 << 28 ) ;
V_4 -> V_12 = V_252 ;
F_26 ( V_2 -> V_39 -> V_40 , V_4 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , unsigned int V_46 ,
int V_263 , int V_264 , int V_255 )
{
struct V_3 * V_4 = F_37 ( sizeof( struct V_256 ) , 0 ,
V_199 ) ;
struct V_256 * V_10 ;
T_2 V_257 = ( V_263 ? 1 : 0 ) | ( V_264 ? 2 : 0 ) ;
F_14 ( 1 << V_192 ,
L_37 , V_2 , V_46 , V_263 , V_264 ) ;
if ( ! V_4 )
return - V_137 ;
V_10 = (struct V_256 * ) V_4 -> V_11 ;
V_10 -> V_14 . V_15 = F_3 ( F_4 ( V_16 ) ) ;
F_5 ( V_10 ) = F_3 ( F_6 ( V_259 , V_46 ) ) ;
V_10 -> V_255 = F_137 ( V_255 ? 0 : 1 ) ;
V_10 -> V_260 = 0 ;
V_10 -> V_261 = F_138 ( 31 ) ;
V_10 -> V_262 = F_139 ( 0x0F000000 ) ;
V_10 -> V_257 = F_139 ( V_257 << 24 ) ;
V_4 -> V_12 = V_252 ;
F_26 ( V_2 -> V_39 -> V_40 , V_4 ) ;
return 0 ;
}
static void F_141 ( struct V_208 * V_39 )
{
struct V_42 * V_53 = (struct V_42 * ) V_39 -> V_40 ;
if ( F_142 ( V_39 ) ) {
F_38 ( L_38 , V_53 ) ;
V_53 -> V_265 = NULL ;
}
}
static int F_143 ( struct V_208 * V_39 )
{
struct V_42 * V_53 = (struct V_42 * ) V_39 -> V_40 ;
struct V_245 * V_246 = V_53 -> V_265 ;
struct V_266 V_267 ;
unsigned int V_268 [ 4 ] ;
int V_82 , V_163 ;
if ( V_246 ) {
F_144 ( & V_246 -> V_269 ) ;
F_126 ( L_39 ,
V_53 , V_53 -> V_265 ) ;
V_39 -> V_246 = V_246 ;
return - V_270 ;
}
V_163 = V_53 -> V_221 ( V_53 , V_271 , & V_267 ) ;
if ( V_163 < 0 ) {
F_98 ( L_40 ,
V_53 -> V_181 , V_163 ) ;
return V_163 ;
}
V_163 = F_145 ( V_39 , V_267 . V_249 , V_267 . V_272 ,
V_267 . V_273 , V_267 . V_274 ) ;
if ( V_163 < 0 )
return V_163 ;
V_246 = V_39 -> V_246 ;
V_267 . V_275 = V_246 -> V_276 << V_277 ;
F_146 ( V_268 ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ )
V_267 . V_268 [ V_82 ] = V_268 [ V_82 ] ;
V_267 . V_272 = V_267 . V_249 + ( V_246 -> V_278 << V_248 ) ;
V_163 = V_53 -> V_221 ( V_53 , V_279 , & V_267 ) ;
if ( V_163 < 0 ) {
F_126 ( L_41 ,
V_53 -> V_181 , V_163 ) ;
F_142 ( V_39 ) ;
return V_163 ;
}
V_53 -> V_265 = V_246 ;
V_39 -> V_280 = F_140 ;
V_39 -> V_281 = F_136 ;
V_39 -> V_282 = F_133 ;
V_39 -> V_283 = F_135 ;
F_38 ( L_42
L_43 ,
V_53 , V_246 -> V_278 , V_246 -> V_284 , V_246 -> V_276 ,
V_246 -> V_285 , V_246 -> V_273 , V_267 . V_273 ,
V_246 -> V_274 , V_267 . V_274 ) ;
return 0 ;
}
static void F_147 ( struct V_42 * V_167 )
{
struct V_208 * V_39 = F_148 ( V_167 ) ;
if ( ! V_39 || V_39 -> V_38 & V_286 ) {
F_38 ( L_44 , V_39 , V_39 ? V_39 -> V_38 : 0 ) ;
return;
}
F_149 ( V_39 ) ;
}
static void F_150 ( struct V_42 * V_167 )
{
struct V_208 * V_39 = F_148 ( V_167 ) ;
struct V_287 * V_287 = F_151 ( V_167 ) ;
int V_82 , V_163 ;
if ( V_39 ) {
F_38 ( L_45 , V_39 ) ;
return;
}
V_39 = F_152 ( 0 , V_287 -> V_288 . V_289 ) ;
if ( ! V_39 ) {
F_126 ( L_46 , V_167 ) ;
return;
}
V_39 -> V_38 = V_290 | V_291 ;
V_39 -> V_40 = V_167 ;
V_39 -> V_292 = V_287 -> V_292 ;
V_39 -> V_179 = V_287 -> V_217 ;
V_39 -> V_289 = V_287 -> V_288 . V_289 ;
V_39 -> V_293 = V_287 -> V_288 . V_293 ;
V_39 -> V_294 = V_295 ;
V_39 -> V_296 = V_297 ;
V_39 -> V_298 = V_299 ;
V_39 -> V_300 = sizeof( struct V_170 ) ;
V_39 -> V_301 = F_141 ;
V_39 -> V_302 = & V_303 ;
V_163 = F_143 ( V_39 ) ;
if ( V_163 ) {
F_38 ( L_47 , V_39 ) ;
goto V_304;
}
V_163 = F_125 ( V_39 ) ;
if ( V_163 ) {
F_38 ( L_48 , V_39 ) ;
goto V_304;
}
V_163 = F_153 ( V_39 , V_305 , V_226 ,
& V_306 , V_307 ) ;
if ( V_163 )
goto V_304;
for ( V_82 = 0 ; V_82 < V_39 -> V_289 ; V_82 ++ )
V_39 -> V_210 [ V_82 ] -> V_204 =
F_117 ( V_39 -> V_179 [ V_82 ] ) ;
F_38 ( L_49 ,
V_39 , V_39 ? V_39 -> V_38 : 0 , V_167 , V_163 ) ;
return;
V_304:
F_149 ( V_39 ) ;
}
static void F_154 ( struct V_42 * V_167 , T_1 V_308 , T_1 V_217 )
{
struct V_208 * V_39 = F_148 ( V_167 ) ;
F_14 ( 1 << V_35 ,
L_50 ,
V_167 , V_39 , V_308 , V_217 ) ;
if ( ! V_39 )
return;
switch ( V_308 ) {
case V_309 :
V_39 -> V_38 |= V_286 ;
break;
case V_310 :
V_39 -> V_38 &= ~ V_286 ;
break;
}
}
static int T_3 F_155 ( void )
{
int V_220 ;
F_156 ( V_311 L_51 , V_312 ) ;
V_220 = F_157 ( & V_303 , & V_307 ) ;
if ( V_220 < 0 )
return V_220 ;
F_158 ( & V_117 ) ;
return 0 ;
}
static void T_4 F_159 ( void )
{
F_160 ( & V_117 ) ;
F_161 ( V_290 ) ;
F_162 ( & V_303 , & V_307 ) ;
}
