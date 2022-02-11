static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( F_3 ( V_3 ) , V_5 ) ;
if ( ! V_7 )
return NULL ;
return F_4 ( V_7 ) ;
}
static inline void F_5 ( struct V_1 * V_1 )
{
F_6 ( F_7 ( V_1 ) ) ;
}
static inline struct V_8 *
F_8 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
return & V_10 -> V_11 -> V_12 [ V_5 -> V_12 ] ;
}
static T_1 F_10 ( struct V_4 * V_5 ,
T_1 V_13 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
T_1 V_15 , V_16 ;
if ( ! V_14 -> V_17 . V_18 )
return V_13 ;
V_15 = V_14 -> V_17 . V_18 ( V_14 , V_10 -> V_19 , V_5 ) ;
V_16 = F_11 ( V_15 * 1000000000LL ,
V_5 -> V_20 -> V_21 ) ;
if ( V_5 -> V_12 == V_22 )
return V_13 + V_16 ;
return ( V_13 > V_16 ) ? V_13 - V_16 : 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_1 * V_1 = F_13 ( V_5 ) ;
F_14 ( V_3 , V_1 ) ;
F_15 ( & V_3 -> V_23 ) ;
F_5 ( V_1 ) ;
if ( V_14 -> V_17 . V_24 )
V_14 -> V_17 . V_24 ( V_14 , V_10 -> V_19 , V_5 ) ;
F_16 ( V_10 -> V_19 ) ;
F_17 ( & V_3 -> V_23 ) ;
F_18 ( V_10 -> V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_1 * V_1 = F_13 ( V_5 ) ;
int V_27 ;
F_20 ( V_3 , V_1 ) ;
F_21 ( V_1 ) ;
if ( F_22 ( V_1 ) ) {
V_27 = - V_28 ;
goto V_29;
}
V_1 -> V_30 . V_31 = 0 ;
V_1 -> V_30 . V_32 = 0 ;
V_1 -> V_30 . V_33 = 0 ;
V_27 = V_3 -> V_17 -> V_34 ( V_3 , V_5 ,
F_23 ( V_26 ) ) ;
V_29:
F_24 ( V_1 ) ;
return V_27 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_1 * V_1 = F_13 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
int V_35 ;
F_21 ( V_1 ) ;
if ( ! F_22 ( V_1 ) )
F_26 ( F_7 ( V_1 ) ) ;
F_27 ( V_10 -> V_19 , V_14 , V_5 ) ;
V_35 = V_3 -> V_17 -> V_36 ( V_3 , V_5 ) ;
F_7 ( V_1 ) -> V_37 = 0 ;
F_24 ( V_1 ) ;
return V_35 ;
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_1 * V_1 = F_13 ( V_5 ) ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
struct V_38 * V_20 = V_5 -> V_20 ;
unsigned int V_33 , V_39 ;
int V_35 ;
struct V_40 * V_41 =
F_29 ( V_10 -> V_19 , V_14 -> V_42 ) ;
unsigned short V_43 = V_41 ? V_41 -> V_43 : 0 ;
F_30 ( V_3 , V_1 ) ;
F_21 ( V_1 ) ;
if ( F_22 ( V_1 ) ) {
V_35 = - V_28 ;
goto V_29;
}
F_31 ( F_7 ( V_1 ) ) ;
V_33 = F_32 ( V_20 -> V_21 ,
V_20 -> V_44 ,
V_20 -> V_45 ,
V_14 -> V_46 ,
V_43 ) ;
if ( ! V_33 ) {
F_33 ( V_3 -> V_47 -> V_48 ,
L_1 ,
V_20 -> V_21 , V_20 -> V_44 , V_20 -> V_45 ) ;
V_35 = - V_49 ;
goto V_29;
}
V_35 = F_34 ( F_7 ( V_1 ) , V_33 ) ;
if ( V_35 < 0 )
goto V_29;
F_35 ( F_7 ( V_1 ) ) ;
V_39 = V_1 -> V_30 . V_39 ;
if ( ( V_3 -> V_50 & V_51 ) &&
V_39 > V_3 -> V_52 )
V_39 -= V_3 -> V_52 ;
V_35 = F_36 ( V_10 -> V_19 , V_14 , V_39 ,
V_1 -> V_30 . V_33 , V_5 ) ;
V_29:
if ( ! V_35 )
F_7 ( V_1 ) -> V_37 = 1 ;
F_24 ( V_1 ) ;
return V_35 ;
}
static int F_37 ( struct V_4 * V_5 , int V_53 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_1 * V_1 ;
struct V_4 * V_7 ;
struct V_6 * V_56 ;
bool V_57 ;
int V_58 = 0 ;
int V_59 ;
V_1 = F_13 ( V_5 ) ;
F_38 ( V_3 , V_1 , V_53 ) ;
V_56 = F_7 ( V_1 ) ;
if ( V_3 -> V_50 & V_60 )
V_59 = V_61 ;
else
V_59 = V_62 ;
if ( F_22 ( V_1 ) || ! V_56 -> V_37 )
return - V_63 ;
switch ( V_53 ) {
case V_64 :
case V_65 :
case V_66 :
V_57 = true ;
break;
case V_67 :
case V_68 :
case V_69 :
V_57 = false ;
break;
default:
return - V_49 ;
}
F_39 (s, substream) {
if ( V_7 -> V_70 -> V_47 != V_5 -> V_70 -> V_47 )
continue;
V_1 = F_13 ( V_7 ) ;
V_58 |= 1 << V_1 -> V_30 . V_71 ;
F_40 ( V_7 , V_5 ) ;
}
F_41 ( & V_55 -> V_72 ) ;
F_42 ( V_56 , true , V_58 , V_59 ) ;
F_39 (s, substream) {
if ( V_7 -> V_70 -> V_47 != V_5 -> V_70 -> V_47 )
continue;
V_1 = F_13 ( V_7 ) ;
if ( V_57 ) {
V_1 -> V_73 = 1 ;
F_43 ( F_7 ( V_1 ) , true ) ;
} else {
F_44 ( F_7 ( V_1 ) ) ;
}
}
F_45 ( & V_55 -> V_72 ) ;
F_46 ( V_56 , V_57 , V_58 ) ;
F_41 ( & V_55 -> V_72 ) ;
F_42 ( V_56 , false , V_58 , V_59 ) ;
if ( V_57 )
F_47 ( V_56 , V_58 ) ;
F_45 ( & V_55 -> V_72 ) ;
return 0 ;
}
unsigned int F_48 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
return F_49 ( F_7 ( V_1 ) ) ;
}
unsigned int F_50 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
return F_51 ( F_7 ( V_1 ) ) ;
}
unsigned int F_52 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_30 . V_5 ;
unsigned int V_74 ;
int V_12 = V_5 -> V_12 ;
int V_75 = 0 ;
if ( V_3 -> V_76 [ V_12 ] )
V_74 = V_3 -> V_76 [ V_12 ] ( V_3 , V_1 ) ;
else
V_74 = F_50 ( V_3 , V_1 ) ;
if ( V_74 >= V_1 -> V_30 . V_31 )
V_74 = 0 ;
if ( V_5 -> V_20 ) {
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
if ( V_3 -> V_18 [ V_12 ] )
V_75 += V_3 -> V_18 [ V_12 ] ( V_3 , V_1 , V_74 ) ;
if ( V_14 -> V_17 . V_18 )
V_75 += V_14 -> V_17 . V_18 ( V_14 , V_10 -> V_19 ,
V_5 ) ;
V_5 -> V_20 -> V_75 = V_75 ;
}
F_53 ( V_3 , V_1 , V_74 , V_75 ) ;
return V_74 ;
}
static T_2 F_54 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_1 * V_1 = F_13 ( V_5 ) ;
return F_55 ( V_5 -> V_20 ,
F_52 ( V_3 , V_1 ) ) ;
}
static T_1 F_56 ( T_1 V_77 , T_3 V_78 , T_3 V_79 )
{
T_1 V_80 ;
V_80 = F_57 ( V_77 , V_79 ) ;
V_77 *= V_78 ;
V_80 *= V_78 ;
F_57 ( V_80 , V_79 ) ;
return V_77 + V_80 ;
}
static int F_58 ( T_4 * V_81 ,
struct V_82 * system , void * V_83 )
{
struct V_4 * V_5 = V_83 ;
struct V_1 * V_1 = F_13 ( V_5 ) ;
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_38 * V_20 ;
T_1 V_84 , V_85 , V_86 ;
T_1 V_87 , V_88 , V_89 ;
T_3 V_90 , V_91 ;
bool V_92 ;
T_3 V_93 ;
T_3 V_94 = 200 ;
T_3 V_95 = 0 ;
V_20 = V_5 -> V_20 ;
if ( V_5 -> V_12 == V_96 )
V_92 = 1 ;
else
V_92 = 0 ;
do {
V_94 = 100 ;
V_93 = ( V_92 << V_97 ) |
( V_1 -> V_30 . V_39 - 1 ) ;
F_59 ( F_3 ( V_3 ) , V_98 , V_93 ) ;
F_60 ( F_3 ( V_3 ) , V_98 , 0 , V_99 ) ;
while ( V_94 ) {
if ( F_61 ( F_3 ( V_3 ) , V_98 ) &
V_100 )
break;
V_94 -- ;
}
if ( ! V_94 ) {
F_33 ( V_3 -> V_47 -> V_48 , L_2 ) ;
return - V_101 ;
}
V_90 = F_61 ( F_3 ( V_3 ) , V_102 ) ;
V_88 = F_61 ( F_3 ( V_3 ) , V_103 ) ;
V_89 = F_61 ( F_3 ( V_3 ) , V_104 ) ;
V_85 = F_61 ( F_3 ( V_3 ) , V_105 ) ;
V_86 = F_61 ( F_3 ( V_3 ) , V_106 ) ;
F_59 ( F_3 ( V_3 ) , V_98 , V_107 ) ;
V_87 = ( V_89 << V_108 ) |
V_88 ;
V_84 = ( V_86 << V_109 ) | V_85 ;
V_91 = V_90 & V_110 ;
if ( V_91 < V_111 - V_112
&& V_91 > V_112 )
break;
F_62 ( V_95 ++ ) ;
} while ( V_95 != V_113 );
if ( V_95 == V_113 ) {
F_63 ( V_3 -> V_47 -> V_48 ,
L_3 ) ;
return - V_101 ;
}
* V_81 = F_64 ( F_56 ( V_84 ,
V_114 , V_20 -> V_21 ) ) ;
* V_81 = F_65 ( * V_81 , ( V_91 * V_114 ) /
( ( V_111 + 1 ) * V_20 -> V_21 ) ) ;
* system = F_66 ( V_87 ) ;
return 0 ;
}
static int F_58 ( T_4 * V_81 ,
struct V_82 * system , void * V_83 )
{
return - V_115 ;
}
static int F_67 ( struct V_4 * V_5 ,
struct V_116 * V_117 )
{
return F_68 ( F_58 ,
V_5 , NULL , V_117 ) ;
}
static inline bool F_69 ( struct V_38 * V_20 ,
struct V_118 * V_119 )
{
if ( V_20 -> V_120 . V_11 & V_121 )
if ( V_119 -> V_122 == V_123 )
return true ;
return false ;
}
static int F_70 ( struct V_4 * V_5 ,
struct V_124 * V_125 , struct V_124 * V_126 ,
struct V_118 * V_127 ,
struct V_128 * V_129 )
{
struct V_1 * V_1 = F_13 ( V_5 ) ;
struct V_38 * V_20 = V_5 -> V_20 ;
struct V_116 V_117 ;
int V_27 ;
T_1 V_13 ;
if ( ( V_5 -> V_20 -> V_120 . V_11 & V_130 ) &&
( V_127 -> V_122 == V_131 ) ) {
F_71 ( V_5 -> V_20 , V_125 ) ;
V_13 = F_72 ( & V_1 -> V_30 . V_132 ) ;
V_13 = F_11 ( V_13 , 3 ) ;
if ( V_127 -> V_133 )
V_13 = F_10 ( V_5 , V_13 ) ;
* V_126 = F_73 ( V_13 ) ;
V_129 -> V_134 = V_131 ;
V_129 -> V_135 = 1 ;
V_129 -> V_136 = 42 ;
} else if ( F_69 ( V_20 , V_127 ) ) {
V_27 = F_67 ( V_5 , & V_117 ) ;
if ( V_27 )
return V_27 ;
switch ( V_20 -> V_137 ) {
case V_138 :
return - V_49 ;
case V_139 :
* V_125 = F_74 ( V_117 . V_140 ) ;
break;
default:
* V_125 = F_74 ( V_117 . V_141 ) ;
break;
}
* V_126 = F_74 ( V_117 . V_81 ) ;
V_129 -> V_134 =
V_123 ;
V_129 -> V_135 = 1 ;
V_129 -> V_136 = 42 ;
} else {
V_129 -> V_134 = V_142 ;
}
return 0 ;
}
static int F_75 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_1 * V_1 ;
struct V_38 * V_20 = V_5 -> V_20 ;
int V_35 ;
int V_143 ;
F_76 ( V_10 -> V_11 ) ;
F_15 ( & V_3 -> V_23 ) ;
V_1 = F_1 ( V_3 , V_5 ) ;
F_77 ( V_3 , V_1 ) ;
if ( V_1 == NULL ) {
V_35 = - V_28 ;
goto V_29;
}
V_20 -> V_144 = V_1 ;
if ( V_3 -> V_145 )
V_146 . V_11 = V_146 . V_11 |
V_121 ;
V_20 -> V_120 = V_146 ;
V_20 -> V_120 . V_147 = V_14 -> V_147 ;
V_20 -> V_120 . V_148 = V_14 -> V_148 ;
V_20 -> V_120 . V_149 = V_14 -> V_149 ;
V_20 -> V_120 . V_150 = V_14 -> V_150 ;
F_78 ( V_20 ) ;
F_79 ( V_20 , V_151 ) ;
F_80 ( V_20 , V_152 ,
20 ,
178000000 ) ;
if ( V_3 -> V_153 )
V_143 = 128 ;
else
V_143 = 4 ;
F_81 ( V_20 , 0 , V_154 ,
V_143 ) ;
F_81 ( V_20 , 0 , V_155 ,
V_143 ) ;
F_82 ( V_10 -> V_19 ) ;
if ( V_14 -> V_17 . V_156 )
V_35 = V_14 -> V_17 . V_156 ( V_14 , V_10 -> V_19 , V_5 ) ;
else
V_35 = - V_157 ;
if ( V_35 < 0 ) {
F_5 ( V_1 ) ;
goto V_158;
}
F_78 ( V_20 ) ;
if ( F_83 ( ! V_20 -> V_120 . V_147 ) ||
F_83 ( ! V_20 -> V_120 . V_148 ) ||
F_83 ( ! V_20 -> V_120 . V_149 ) ||
F_83 ( ! V_20 -> V_120 . V_150 ) ) {
F_5 ( V_1 ) ;
if ( V_14 -> V_17 . V_24 )
V_14 -> V_17 . V_24 ( V_14 , V_10 -> V_19 , V_5 ) ;
V_35 = - V_49 ;
goto V_158;
}
if ( V_5 -> V_12 == V_22 ) {
V_20 -> V_120 . V_11 &= ~ V_159 ;
V_20 -> V_120 . V_11 &= ~ V_130 ;
}
F_84 ( V_5 ) ;
F_17 ( & V_3 -> V_23 ) ;
return 0 ;
V_158:
F_16 ( V_10 -> V_19 ) ;
V_29:
F_17 ( & V_3 -> V_23 ) ;
F_18 ( V_10 -> V_11 ) ;
return V_35 ;
}
static int F_85 ( struct V_4 * V_5 ,
struct V_160 * V_161 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
if ( V_3 -> V_17 -> V_162 )
V_3 -> V_17 -> V_162 ( V_5 , V_161 ) ;
return F_86 ( V_5 , V_161 ) ;
}
static void F_87 ( struct V_163 * V_70 )
{
struct V_9 * V_10 = V_70 -> V_144 ;
if ( V_10 ) {
F_88 ( & V_10 -> V_164 ) ;
V_10 -> V_11 -> V_70 = NULL ;
F_89 ( V_10 ) ;
}
}
int F_90 ( struct V_165 * V_166 , struct V_167 * V_19 ,
struct V_168 * V_169 )
{
struct V_54 * V_55 = & V_166 -> V_30 ;
struct V_2 * V_3 = F_91 ( V_55 ) ;
struct V_163 * V_70 ;
struct V_9 * V_10 ;
int V_170 = V_169 -> V_81 ;
unsigned int V_171 ;
int V_7 , V_35 ;
F_92 (apcm, &chip->pcm_list, list) {
if ( V_10 -> V_70 -> V_81 == V_170 ) {
F_33 ( V_3 -> V_47 -> V_48 , L_4 ,
V_170 ) ;
return - V_28 ;
}
}
V_35 = F_93 ( V_3 -> V_47 , V_169 -> V_172 , V_170 ,
V_169 -> V_12 [ V_96 ] . V_173 ,
V_169 -> V_12 [ V_22 ] . V_173 ,
& V_70 ) ;
if ( V_35 < 0 )
return V_35 ;
F_94 ( V_70 -> V_172 , V_169 -> V_172 , sizeof( V_70 -> V_172 ) ) ;
V_10 = F_95 ( sizeof( * V_10 ) , V_174 ) ;
if ( V_10 == NULL )
return - V_175 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_70 = V_70 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_11 = V_169 ;
V_70 -> V_144 = V_10 ;
V_70 -> V_176 = F_87 ;
if ( V_169 -> V_177 == V_178 )
V_70 -> V_179 = V_180 ;
F_96 ( & V_10 -> V_164 , & V_3 -> V_181 ) ;
V_169 -> V_70 = V_70 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
if ( V_169 -> V_12 [ V_7 ] . V_173 )
F_97 ( V_70 , V_7 , & V_182 ) ;
}
V_171 = V_183 * 1024 ;
if ( V_171 > V_184 )
V_171 = V_184 ;
F_98 ( V_70 , V_185 ,
V_3 -> V_47 -> V_48 ,
V_171 , V_184 ) ;
return 0 ;
}
static unsigned int F_99 ( T_3 V_53 )
{
unsigned int V_186 = V_53 >> 28 ;
if ( V_186 >= V_187 ) {
F_100 () ;
V_186 = 0 ;
}
return V_186 ;
}
static int F_101 ( struct V_54 * V_55 , unsigned int V_186 ,
unsigned int * V_188 )
{
struct V_2 * V_3 = F_91 ( V_55 ) ;
struct V_165 * V_189 = & V_3 -> V_55 ;
unsigned long V_94 ;
unsigned long V_190 ;
int V_191 = 0 ;
V_192:
V_94 = V_193 + F_102 ( 1000 ) ;
for ( V_190 = 0 ; ; V_190 ++ ) {
F_103 ( & V_55 -> V_72 ) ;
if ( V_3 -> V_194 || V_191 )
F_104 ( V_55 ) ;
if ( ! V_55 -> V_195 . V_196 [ V_186 ] ) {
if ( ! V_191 )
V_3 -> V_197 = 0 ;
if ( V_188 )
* V_188 = V_55 -> V_195 . V_188 [ V_186 ] ;
F_105 ( & V_55 -> V_72 ) ;
return 0 ;
}
F_105 ( & V_55 -> V_72 ) ;
if ( F_106 ( V_193 , V_94 ) )
break;
if ( V_189 -> V_198 || V_190 > 3000 )
F_107 ( 2 ) ;
else {
F_62 ( 10 ) ;
F_108 () ;
}
}
if ( V_189 -> V_199 )
return - V_101 ;
if ( ! V_3 -> V_194 && V_3 -> V_197 < 2 ) {
F_109 ( V_3 -> V_47 -> V_48 ,
L_5 ,
V_55 -> V_200 [ V_186 ] ) ;
V_191 = 1 ;
V_3 -> V_197 ++ ;
goto V_192;
}
if ( ! V_3 -> V_194 ) {
F_110 ( V_3 -> V_47 -> V_48 ,
L_6 ,
V_55 -> V_200 [ V_186 ] ) ;
V_3 -> V_194 = 1 ;
goto V_192;
}
if ( V_3 -> V_201 ) {
F_110 ( V_3 -> V_47 -> V_48 ,
L_7 ,
V_55 -> V_200 [ V_186 ] ) ;
if ( V_3 -> V_17 -> V_202 &&
V_3 -> V_17 -> V_202 ( V_3 ) < 0 )
return - V_101 ;
goto V_192;
}
if ( V_3 -> V_203 ) {
return - V_101 ;
}
if ( ! V_3 -> V_204 )
return - V_101 ;
if ( V_189 -> V_205 && ! V_189 -> V_206 && ! V_189 -> V_207 ) {
V_189 -> V_206 = 1 ;
return - V_208 ;
}
F_33 ( V_3 -> V_47 -> V_48 ,
L_8 ,
V_55 -> V_200 [ V_186 ] ) ;
V_3 -> V_209 = 1 ;
V_189 -> V_206 = 0 ;
F_111 ( V_55 ) ;
return - V_101 ;
}
static int F_112 ( struct V_2 * V_3 , unsigned int V_186 )
{
int V_94 = 50 ;
while ( V_94 -- ) {
if ( F_113 ( V_3 , V_210 ) & V_211 ) {
F_3 ( V_3 ) -> V_195 . V_188 [ V_186 ] = F_114 ( V_3 , V_212 ) ;
return 0 ;
}
F_62 ( 1 ) ;
}
if ( F_115 () )
F_109 ( V_3 -> V_47 -> V_48 , L_9 ,
F_113 ( V_3 , V_210 ) ) ;
F_3 ( V_3 ) -> V_195 . V_188 [ V_186 ] = - 1 ;
return - V_101 ;
}
static int F_116 ( struct V_54 * V_55 , T_3 V_213 )
{
struct V_2 * V_3 = F_91 ( V_55 ) ;
unsigned int V_186 = F_99 ( V_213 ) ;
int V_94 = 50 ;
V_55 -> V_200 [ F_99 ( V_213 ) ] = V_213 ;
while ( V_94 -- ) {
if ( ! ( ( F_113 ( V_3 , V_210 ) & V_214 ) ) ) {
F_117 ( V_3 , V_210 , F_113 ( V_3 , V_210 ) |
V_211 ) ;
F_118 ( V_3 , V_215 , V_213 ) ;
F_117 ( V_3 , V_210 , F_113 ( V_3 , V_210 ) |
V_214 ) ;
return F_112 ( V_3 , V_186 ) ;
}
F_62 ( 1 ) ;
}
if ( F_115 () )
F_109 ( V_3 -> V_47 -> V_48 ,
L_10 ,
F_113 ( V_3 , V_210 ) , V_213 ) ;
return - V_101 ;
}
static int F_119 ( struct V_54 * V_55 , unsigned int V_186 ,
unsigned int * V_188 )
{
if ( V_188 )
* V_188 = V_55 -> V_195 . V_188 [ V_186 ] ;
return 0 ;
}
static int F_120 ( struct V_54 * V_55 , unsigned int V_213 )
{
struct V_2 * V_3 = F_91 ( V_55 ) ;
if ( V_3 -> V_216 )
return 0 ;
if ( V_3 -> V_209 )
return F_116 ( V_55 , V_213 ) ;
else
return F_121 ( V_55 , V_213 ) ;
}
static int F_122 ( struct V_54 * V_55 , unsigned int V_186 ,
unsigned int * V_188 )
{
struct V_2 * V_3 = F_91 ( V_55 ) ;
if ( V_3 -> V_216 )
return 0 ;
if ( V_3 -> V_209 )
return F_119 ( V_55 , V_186 , V_188 ) ;
else
return F_101 ( V_55 , V_186 , V_188 ) ;
}
static int F_123 ( struct V_54 * V_55 , bool V_217 )
{
struct V_2 * V_3 = F_91 ( V_55 ) ;
if ( V_3 -> V_17 -> V_218 )
return V_3 -> V_17 -> V_218 ( V_3 , V_217 ) ;
else
return - V_49 ;
}
static struct V_1 *
F_124 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_6 * V_7 ;
F_92 (s, &bus->stream_list, list)
if ( V_7 -> V_71 == V_3 -> V_219 )
return F_4 ( V_7 ) ;
return NULL ;
}
int F_125 ( struct V_167 * V_19 , unsigned int V_45 ,
unsigned int V_220 ,
struct V_221 * V_222 )
{
struct V_54 * V_55 = & V_19 -> V_55 -> V_30 ;
struct V_2 * V_3 = F_91 ( V_55 ) ;
struct V_1 * V_1 ;
struct V_6 * V_56 ;
bool V_223 = false ;
int V_35 ;
V_1 = F_124 ( V_3 ) ;
V_56 = F_7 ( V_1 ) ;
F_103 ( & V_55 -> V_72 ) ;
if ( V_56 -> V_224 ) {
V_3 -> V_225 = * V_1 ;
V_223 = true ;
}
F_105 ( & V_55 -> V_72 ) ;
V_35 = F_126 ( V_56 , V_45 , V_220 , V_222 ) ;
if ( V_35 < 0 ) {
F_103 ( & V_55 -> V_72 ) ;
if ( V_223 )
* V_1 = V_3 -> V_225 ;
F_105 ( & V_55 -> V_72 ) ;
return V_35 ;
}
V_56 -> V_37 = 0 ;
return V_35 ;
}
void F_127 ( struct V_167 * V_19 , bool V_57 )
{
struct V_54 * V_55 = & V_19 -> V_55 -> V_30 ;
struct V_2 * V_3 = F_91 ( V_55 ) ;
struct V_1 * V_1 = F_124 ( V_3 ) ;
F_128 ( F_7 ( V_1 ) , V_57 ) ;
}
void F_129 ( struct V_167 * V_19 ,
struct V_221 * V_226 )
{
struct V_54 * V_55 = & V_19 -> V_55 -> V_30 ;
struct V_2 * V_3 = F_91 ( V_55 ) ;
struct V_1 * V_1 = F_124 ( V_3 ) ;
struct V_6 * V_56 = F_7 ( V_1 ) ;
if ( ! V_226 -> V_161 || ! V_56 -> V_227 )
return;
F_130 ( V_56 , V_226 ) ;
F_103 ( & V_55 -> V_72 ) ;
if ( V_56 -> V_224 )
* V_1 = V_3 -> V_225 ;
V_56 -> V_227 = false ;
F_105 ( & V_55 -> V_72 ) ;
}
void F_131 ( struct V_2 * V_3 , bool V_228 )
{
if ( F_132 ( F_3 ( V_3 ) , V_228 ) ) {
if ( V_3 -> V_50 & V_51 )
F_117 ( V_3 , V_229 , 0xc0 ) ;
}
}
void F_133 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_6 * V_7 ;
F_92 (s, &bus->stream_list, list)
F_44 ( V_7 ) ;
}
void F_134 ( struct V_2 * V_3 )
{
F_135 ( F_3 ( V_3 ) ) ;
}
static void F_136 ( struct V_54 * V_55 , struct V_6 * V_7 )
{
struct V_2 * V_3 = F_91 ( V_55 ) ;
struct V_1 * V_1 = F_4 ( V_7 ) ;
if ( ! V_3 -> V_17 -> V_230 ||
V_3 -> V_17 -> V_230 ( V_3 , V_1 ) ) {
F_45 ( & V_55 -> V_72 ) ;
F_137 ( F_7 ( V_1 ) -> V_5 ) ;
F_41 ( & V_55 -> V_72 ) ;
}
}
T_5 F_138 ( int V_231 , void * V_232 )
{
struct V_2 * V_3 = V_232 ;
struct V_54 * V_55 = F_3 ( V_3 ) ;
T_3 V_233 ;
bool V_234 , V_235 = false ;
int V_236 = 0 ;
#ifdef F_139
if ( F_140 ( V_3 ) )
if ( ! F_141 ( V_3 -> V_47 -> V_48 ) )
return V_237 ;
#endif
F_41 ( & V_55 -> V_72 ) ;
if ( V_3 -> V_216 )
goto V_29;
do {
V_233 = F_114 ( V_3 , V_238 ) ;
if ( V_233 == 0 || V_233 == 0xffffffff )
break;
V_235 = true ;
V_234 = false ;
if ( F_142 ( V_55 , V_233 , F_136 ) )
V_234 = true ;
V_233 = F_143 ( V_3 , V_239 ) ;
if ( V_233 & V_240 ) {
V_234 = true ;
if ( V_233 & V_241 ) {
if ( V_3 -> V_50 & V_51 )
F_62 ( 80 ) ;
F_104 ( V_55 ) ;
}
F_144 ( V_3 , V_239 , V_240 ) ;
}
} while ( V_234 && ++ V_236 < 10 );
V_29:
F_45 ( & V_55 -> V_72 ) ;
return F_145 ( V_235 ) ;
}
static int F_146 ( struct V_2 * V_3 , int V_186 )
{
unsigned int V_53 = ( V_186 << 28 ) | ( V_242 << 20 ) |
( V_243 << 8 ) | V_244 ;
struct V_54 * V_55 = F_3 ( V_3 ) ;
int V_35 ;
unsigned int V_188 = - 1 ;
F_15 ( & V_55 -> V_245 ) ;
V_3 -> V_203 = 1 ;
F_120 ( V_55 , V_53 ) ;
V_35 = F_122 ( V_55 , V_186 , & V_188 ) ;
V_3 -> V_203 = 0 ;
F_17 ( & V_55 -> V_245 ) ;
if ( V_35 < 0 || V_188 == - 1 )
return - V_101 ;
F_109 ( V_3 -> V_47 -> V_48 , L_11 , V_186 ) ;
return 0 ;
}
void F_147 ( struct V_165 * V_55 )
{
struct V_2 * V_3 = F_91 ( & V_55 -> V_30 ) ;
V_55 -> V_207 = 1 ;
F_134 ( V_3 ) ;
F_131 ( V_3 , true ) ;
if ( V_55 -> V_30 . V_246 )
F_148 ( V_55 ) ;
V_55 -> V_207 = 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
int V_247 ;
unsigned int V_248 ;
if ( ! V_3 -> V_249 )
return 0 ;
V_247 = V_3 -> V_249 [ V_3 -> V_250 ] ;
if ( V_247 == 0 )
return 0 ;
if ( V_247 < 50 || V_247 > 60000 )
V_248 = 0 ;
else
V_248 = F_102 ( V_247 ) ;
if ( V_248 == 0 )
F_110 ( V_3 -> V_47 -> V_48 ,
L_12 , V_247 ) ;
return V_248 ;
}
int F_150 ( struct V_2 * V_3 , const char * V_251 ,
const struct V_252 * V_253 )
{
struct V_165 * V_55 = & V_3 -> V_55 ;
int V_35 ;
V_35 = F_151 ( & V_55 -> V_30 , V_3 -> V_47 -> V_48 , & V_254 ,
V_253 ) ;
if ( V_35 < 0 )
return V_35 ;
V_55 -> V_47 = V_3 -> V_47 ;
F_152 ( & V_55 -> V_255 ) ;
V_55 -> V_256 = V_3 -> V_256 ;
V_55 -> V_257 = V_251 ;
V_55 -> V_258 = - 1 ;
V_55 -> V_30 . V_259 = F_153 ( V_3 ) ;
if ( V_3 -> V_76 [ 0 ] != F_48 ||
V_3 -> V_76 [ 1 ] != F_48 )
V_55 -> V_30 . V_260 = true ;
V_55 -> V_30 . V_261 = V_3 -> V_261 ;
if ( V_3 -> V_50 & V_262 )
V_55 -> V_30 . V_263 = true ;
if ( V_3 -> V_50 & V_264 )
V_55 -> V_30 . V_265 = true ;
if ( V_3 -> V_50 & V_266 ) {
F_109 ( V_3 -> V_47 -> V_48 , L_13 ) ;
V_55 -> V_30 . V_267 = 1 ;
V_55 -> V_205 = 1 ;
}
return 0 ;
}
int F_154 ( struct V_2 * V_3 , unsigned int V_268 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
int V_269 , V_270 , V_35 ;
V_270 = 0 ;
if ( ! V_268 )
V_268 = V_271 ;
for ( V_269 = 0 ; V_269 < V_268 ; V_269 ++ ) {
if ( ( V_55 -> V_272 & ( 1 << V_269 ) ) & V_3 -> V_273 ) {
if ( F_146 ( V_3 , V_269 ) < 0 ) {
F_110 ( V_3 -> V_47 -> V_48 ,
L_14 , V_269 ) ;
V_55 -> V_272 &= ~ ( 1 << V_269 ) ;
F_134 ( V_3 ) ;
F_131 ( V_3 , true ) ;
}
}
}
for ( V_269 = 0 ; V_269 < V_268 ; V_269 ++ ) {
if ( ( V_55 -> V_272 & ( 1 << V_269 ) ) & V_3 -> V_273 ) {
struct V_167 * V_19 ;
V_35 = F_155 ( & V_3 -> V_55 , V_3 -> V_47 , V_269 , & V_19 ) ;
if ( V_35 < 0 )
continue;
V_19 -> V_274 = F_149 ( V_3 ) ;
V_19 -> V_275 = V_3 -> V_275 ;
V_270 ++ ;
}
}
if ( ! V_270 ) {
F_33 ( V_3 -> V_47 -> V_48 , L_15 ) ;
return - V_115 ;
}
return 0 ;
}
int F_156 ( struct V_2 * V_3 )
{
struct V_167 * V_19 , * V_276 ;
F_157 (codec, next, &chip->bus) {
F_158 ( V_19 ) ;
}
return 0 ;
}
static int F_159 ( struct V_2 * V_3 , unsigned char V_71 )
{
if ( V_71 >= V_3 -> V_277 &&
V_71 < V_3 -> V_277 + V_3 -> V_52 )
return V_22 ;
return V_96 ;
}
int F_160 ( struct V_2 * V_3 )
{
int V_247 ;
int V_278 [ 2 ] = { 0 , 0 } ;
for ( V_247 = 0 ; V_247 < V_3 -> V_279 ; V_247 ++ ) {
struct V_1 * V_1 = F_95 ( sizeof( * V_1 ) , V_174 ) ;
int V_280 , V_281 ;
if ( ! V_1 )
return - V_175 ;
V_280 = F_159 ( V_3 , V_247 ) ;
if ( V_3 -> V_50 & V_282 )
V_281 = ++ V_278 [ V_280 ] ;
else
V_281 = V_247 + 1 ;
F_161 ( F_3 ( V_3 ) , F_7 ( V_1 ) ,
V_247 , V_280 , V_281 ) ;
}
return 0 ;
}
void F_162 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_6 * V_7 ;
while ( ! F_163 ( & V_55 -> V_283 ) ) {
V_7 = F_164 ( & V_55 -> V_283 , struct V_6 , V_164 ) ;
F_88 ( & V_7 -> V_164 ) ;
F_89 ( F_4 ( V_7 ) ) ;
}
}
