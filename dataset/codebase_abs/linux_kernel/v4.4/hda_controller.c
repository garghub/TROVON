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
static int F_56 ( struct V_4 * V_5 ,
struct V_77 * V_78 , struct V_77 * V_79 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_1 = F_13 ( V_5 ) ;
T_1 V_13 ;
if ( ( V_5 -> V_20 -> V_84 . V_11 & V_85 ) &&
( V_81 -> V_86 == V_87 ) ) {
F_57 ( V_5 -> V_20 , V_78 ) ;
V_13 = F_58 ( & V_1 -> V_30 . V_88 ) ;
V_13 = F_11 ( V_13 , 3 ) ;
if ( V_81 -> V_89 )
V_13 = F_10 ( V_5 , V_13 ) ;
* V_79 = F_59 ( V_13 ) ;
V_83 -> V_90 = V_87 ;
V_83 -> V_91 = 1 ;
V_83 -> V_92 = 42 ;
} else
V_83 -> V_90 = V_93 ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_8 * V_14 = F_8 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_1 * V_1 ;
struct V_38 * V_20 = V_5 -> V_20 ;
int V_35 ;
int V_94 ;
F_61 ( V_10 -> V_11 ) ;
F_15 ( & V_3 -> V_23 ) ;
V_1 = F_1 ( V_3 , V_5 ) ;
F_62 ( V_3 , V_1 ) ;
if ( V_1 == NULL ) {
V_35 = - V_28 ;
goto V_29;
}
V_20 -> V_95 = V_1 ;
V_20 -> V_84 = V_96 ;
V_20 -> V_84 . V_97 = V_14 -> V_97 ;
V_20 -> V_84 . V_98 = V_14 -> V_98 ;
V_20 -> V_84 . V_99 = V_14 -> V_99 ;
V_20 -> V_84 . V_100 = V_14 -> V_100 ;
F_63 ( V_20 ) ;
F_64 ( V_20 , V_101 ) ;
F_65 ( V_20 , V_102 ,
20 ,
178000000 ) ;
if ( V_3 -> V_103 )
V_94 = 128 ;
else
V_94 = 4 ;
F_66 ( V_20 , 0 , V_104 ,
V_94 ) ;
F_66 ( V_20 , 0 , V_105 ,
V_94 ) ;
F_67 ( V_10 -> V_19 ) ;
if ( V_14 -> V_17 . V_106 )
V_35 = V_14 -> V_17 . V_106 ( V_14 , V_10 -> V_19 , V_5 ) ;
else
V_35 = - V_107 ;
if ( V_35 < 0 ) {
F_5 ( V_1 ) ;
goto V_108;
}
F_63 ( V_20 ) ;
if ( F_68 ( ! V_20 -> V_84 . V_97 ) ||
F_68 ( ! V_20 -> V_84 . V_98 ) ||
F_68 ( ! V_20 -> V_84 . V_99 ) ||
F_68 ( ! V_20 -> V_84 . V_100 ) ) {
F_5 ( V_1 ) ;
if ( V_14 -> V_17 . V_24 )
V_14 -> V_17 . V_24 ( V_14 , V_10 -> V_19 , V_5 ) ;
V_35 = - V_49 ;
goto V_108;
}
if ( V_5 -> V_12 == V_22 ) {
V_20 -> V_84 . V_11 &= ~ V_109 ;
V_20 -> V_84 . V_11 &= ~ V_85 ;
}
F_69 ( V_5 ) ;
F_17 ( & V_3 -> V_23 ) ;
return 0 ;
V_108:
F_16 ( V_10 -> V_19 ) ;
V_29:
F_17 ( & V_3 -> V_23 ) ;
F_18 ( V_10 -> V_11 ) ;
return V_35 ;
}
static int F_70 ( struct V_4 * V_5 ,
struct V_110 * V_111 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
if ( V_3 -> V_17 -> V_112 )
V_3 -> V_17 -> V_112 ( V_5 , V_111 ) ;
return F_71 ( V_5 , V_111 ) ;
}
static void F_72 ( struct V_113 * V_70 )
{
struct V_9 * V_10 = V_70 -> V_95 ;
if ( V_10 ) {
F_73 ( & V_10 -> V_114 ) ;
V_10 -> V_11 -> V_70 = NULL ;
F_74 ( V_10 ) ;
}
}
int F_75 ( struct V_115 * V_116 , struct V_117 * V_19 ,
struct V_118 * V_119 )
{
struct V_54 * V_55 = & V_116 -> V_30 ;
struct V_2 * V_3 = F_76 ( V_55 ) ;
struct V_113 * V_70 ;
struct V_9 * V_10 ;
int V_120 = V_119 -> V_121 ;
unsigned int V_122 ;
int V_7 , V_35 ;
F_77 (apcm, &chip->pcm_list, list) {
if ( V_10 -> V_70 -> V_121 == V_120 ) {
F_33 ( V_3 -> V_47 -> V_48 , L_2 ,
V_120 ) ;
return - V_28 ;
}
}
V_35 = F_78 ( V_3 -> V_47 , V_119 -> V_123 , V_120 ,
V_119 -> V_12 [ V_124 ] . V_125 ,
V_119 -> V_12 [ V_22 ] . V_125 ,
& V_70 ) ;
if ( V_35 < 0 )
return V_35 ;
F_79 ( V_70 -> V_123 , V_119 -> V_123 , sizeof( V_70 -> V_123 ) ) ;
V_10 = F_80 ( sizeof( * V_10 ) , V_126 ) ;
if ( V_10 == NULL )
return - V_127 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_70 = V_70 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_11 = V_119 ;
V_70 -> V_95 = V_10 ;
V_70 -> V_128 = F_72 ;
if ( V_119 -> V_129 == V_130 )
V_70 -> V_131 = V_132 ;
F_81 ( & V_10 -> V_114 , & V_3 -> V_133 ) ;
V_119 -> V_70 = V_70 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
if ( V_119 -> V_12 [ V_7 ] . V_125 )
F_82 ( V_70 , V_7 , & V_134 ) ;
}
V_122 = V_135 * 1024 ;
if ( V_122 > V_136 )
V_122 = V_136 ;
F_83 ( V_70 , V_137 ,
V_3 -> V_47 -> V_48 ,
V_122 , V_136 ) ;
return 0 ;
}
static unsigned int F_84 ( T_3 V_53 )
{
unsigned int V_138 = V_53 >> 28 ;
if ( V_138 >= V_139 ) {
F_85 () ;
V_138 = 0 ;
}
return V_138 ;
}
static int F_86 ( struct V_54 * V_55 , unsigned int V_138 ,
unsigned int * V_140 )
{
struct V_2 * V_3 = F_76 ( V_55 ) ;
struct V_115 * V_141 = & V_3 -> V_55 ;
unsigned long V_142 ;
unsigned long V_143 ;
int V_144 = 0 ;
V_145:
V_142 = V_146 + F_87 ( 1000 ) ;
for ( V_143 = 0 ; ; V_143 ++ ) {
F_88 ( & V_55 -> V_72 ) ;
if ( V_3 -> V_147 || V_144 )
F_89 ( V_55 ) ;
if ( ! V_55 -> V_148 . V_149 [ V_138 ] ) {
if ( ! V_144 )
V_3 -> V_150 = 0 ;
if ( V_140 )
* V_140 = V_55 -> V_148 . V_140 [ V_138 ] ;
F_90 ( & V_55 -> V_72 ) ;
return 0 ;
}
F_90 ( & V_55 -> V_72 ) ;
if ( F_91 ( V_146 , V_142 ) )
break;
if ( V_141 -> V_151 || V_143 > 3000 )
F_92 ( 2 ) ;
else {
F_93 ( 10 ) ;
F_94 () ;
}
}
if ( V_141 -> V_152 )
return - V_153 ;
if ( ! V_3 -> V_147 && V_3 -> V_150 < 2 ) {
F_95 ( V_3 -> V_47 -> V_48 ,
L_3 ,
V_55 -> V_154 [ V_138 ] ) ;
V_144 = 1 ;
V_3 -> V_150 ++ ;
goto V_145;
}
if ( ! V_3 -> V_147 ) {
F_96 ( V_3 -> V_47 -> V_48 ,
L_4 ,
V_55 -> V_154 [ V_138 ] ) ;
V_3 -> V_147 = 1 ;
goto V_145;
}
if ( V_3 -> V_155 ) {
F_96 ( V_3 -> V_47 -> V_48 ,
L_5 ,
V_55 -> V_154 [ V_138 ] ) ;
if ( V_3 -> V_17 -> V_156 &&
V_3 -> V_17 -> V_156 ( V_3 ) < 0 )
return - V_153 ;
goto V_145;
}
if ( V_3 -> V_157 ) {
return - V_153 ;
}
if ( V_141 -> V_158 && ! V_141 -> V_159 && ! V_141 -> V_160 ) {
V_141 -> V_159 = 1 ;
return - V_161 ;
}
F_33 ( V_3 -> V_47 -> V_48 ,
L_6 ,
V_55 -> V_154 [ V_138 ] ) ;
V_3 -> V_162 = 1 ;
V_141 -> V_159 = 0 ;
F_97 ( V_55 ) ;
return - V_153 ;
}
static int F_98 ( struct V_2 * V_3 , unsigned int V_138 )
{
int V_142 = 50 ;
while ( V_142 -- ) {
if ( F_99 ( V_3 , V_163 ) & V_164 ) {
F_3 ( V_3 ) -> V_148 . V_140 [ V_138 ] = F_100 ( V_3 , V_165 ) ;
return 0 ;
}
F_93 ( 1 ) ;
}
if ( F_101 () )
F_95 ( V_3 -> V_47 -> V_48 , L_7 ,
F_99 ( V_3 , V_163 ) ) ;
F_3 ( V_3 ) -> V_148 . V_140 [ V_138 ] = - 1 ;
return - V_153 ;
}
static int F_102 ( struct V_54 * V_55 , T_3 V_166 )
{
struct V_2 * V_3 = F_76 ( V_55 ) ;
unsigned int V_138 = F_84 ( V_166 ) ;
int V_142 = 50 ;
V_55 -> V_154 [ F_84 ( V_166 ) ] = V_166 ;
while ( V_142 -- ) {
if ( ! ( ( F_99 ( V_3 , V_163 ) & V_167 ) ) ) {
F_103 ( V_3 , V_163 , F_99 ( V_3 , V_163 ) |
V_164 ) ;
F_104 ( V_3 , V_168 , V_166 ) ;
F_103 ( V_3 , V_163 , F_99 ( V_3 , V_163 ) |
V_167 ) ;
return F_98 ( V_3 , V_138 ) ;
}
F_93 ( 1 ) ;
}
if ( F_101 () )
F_95 ( V_3 -> V_47 -> V_48 ,
L_8 ,
F_99 ( V_3 , V_163 ) , V_166 ) ;
return - V_153 ;
}
static int F_105 ( struct V_54 * V_55 , unsigned int V_138 ,
unsigned int * V_140 )
{
if ( V_140 )
* V_140 = V_55 -> V_148 . V_140 [ V_138 ] ;
return 0 ;
}
static int F_106 ( struct V_54 * V_55 , unsigned int V_166 )
{
struct V_2 * V_3 = F_76 ( V_55 ) ;
if ( V_3 -> V_169 )
return 0 ;
if ( V_3 -> V_162 )
return F_102 ( V_55 , V_166 ) ;
else
return F_107 ( V_55 , V_166 ) ;
}
static int F_108 ( struct V_54 * V_55 , unsigned int V_138 ,
unsigned int * V_140 )
{
struct V_2 * V_3 = F_76 ( V_55 ) ;
if ( V_3 -> V_169 )
return 0 ;
if ( V_3 -> V_162 )
return F_105 ( V_55 , V_138 , V_140 ) ;
else
return F_86 ( V_55 , V_138 , V_140 ) ;
}
static int F_109 ( struct V_54 * V_55 , bool V_170 )
{
struct V_2 * V_3 = F_76 ( V_55 ) ;
if ( V_3 -> V_17 -> V_171 )
return V_3 -> V_17 -> V_171 ( V_3 , V_170 ) ;
else
return - V_49 ;
}
static struct V_1 *
F_110 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_6 * V_7 ;
F_77 (s, &bus->stream_list, list)
if ( V_7 -> V_71 == V_3 -> V_172 )
return F_4 ( V_7 ) ;
return NULL ;
}
int F_111 ( struct V_117 * V_19 , unsigned int V_45 ,
unsigned int V_173 ,
struct V_174 * V_175 )
{
struct V_54 * V_55 = & V_19 -> V_55 -> V_30 ;
struct V_2 * V_3 = F_76 ( V_55 ) ;
struct V_1 * V_1 ;
struct V_6 * V_56 ;
bool V_176 = false ;
int V_35 ;
V_1 = F_110 ( V_3 ) ;
V_56 = F_7 ( V_1 ) ;
F_88 ( & V_55 -> V_72 ) ;
if ( V_56 -> V_177 ) {
V_3 -> V_178 = * V_1 ;
V_176 = true ;
}
F_90 ( & V_55 -> V_72 ) ;
V_35 = F_112 ( V_56 , V_45 , V_173 , V_175 ) ;
if ( V_35 < 0 ) {
F_88 ( & V_55 -> V_72 ) ;
if ( V_176 )
* V_1 = V_3 -> V_178 ;
F_90 ( & V_55 -> V_72 ) ;
return V_35 ;
}
V_56 -> V_37 = 0 ;
return V_35 ;
}
void F_113 ( struct V_117 * V_19 , bool V_57 )
{
struct V_54 * V_55 = & V_19 -> V_55 -> V_30 ;
struct V_2 * V_3 = F_76 ( V_55 ) ;
struct V_1 * V_1 = F_110 ( V_3 ) ;
F_114 ( F_7 ( V_1 ) , V_57 ) ;
}
void F_115 ( struct V_117 * V_19 ,
struct V_174 * V_179 )
{
struct V_54 * V_55 = & V_19 -> V_55 -> V_30 ;
struct V_2 * V_3 = F_76 ( V_55 ) ;
struct V_1 * V_1 = F_110 ( V_3 ) ;
struct V_6 * V_56 = F_7 ( V_1 ) ;
if ( ! V_179 -> V_111 || ! V_56 -> V_180 )
return;
F_116 ( V_56 , V_179 ) ;
F_88 ( & V_55 -> V_72 ) ;
if ( V_56 -> V_177 )
* V_1 = V_3 -> V_178 ;
V_56 -> V_180 = false ;
F_90 ( & V_55 -> V_72 ) ;
}
void F_117 ( struct V_2 * V_3 , bool V_181 )
{
if ( F_118 ( F_3 ( V_3 ) , V_181 ) ) {
if ( V_3 -> V_50 & V_51 )
F_103 ( V_3 , V_182 , 0xc0 ) ;
}
}
void F_119 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_6 * V_7 ;
F_77 (s, &bus->stream_list, list)
F_44 ( V_7 ) ;
}
void F_120 ( struct V_2 * V_3 )
{
F_121 ( F_3 ( V_3 ) ) ;
}
static void F_122 ( struct V_54 * V_55 , struct V_6 * V_7 )
{
struct V_2 * V_3 = F_76 ( V_55 ) ;
struct V_1 * V_1 = F_4 ( V_7 ) ;
if ( ! V_3 -> V_17 -> V_183 ||
V_3 -> V_17 -> V_183 ( V_3 , V_1 ) ) {
F_45 ( & V_55 -> V_72 ) ;
F_123 ( F_7 ( V_1 ) -> V_5 ) ;
F_41 ( & V_55 -> V_72 ) ;
}
}
T_4 F_124 ( int V_184 , void * V_185 )
{
struct V_2 * V_3 = V_185 ;
struct V_54 * V_55 = F_3 ( V_3 ) ;
T_3 V_186 ;
#ifdef F_125
if ( F_126 ( V_3 ) )
if ( ! F_127 ( V_3 -> V_47 -> V_48 ) )
return V_187 ;
#endif
F_41 ( & V_55 -> V_72 ) ;
if ( V_3 -> V_169 ) {
F_45 ( & V_55 -> V_72 ) ;
return V_187 ;
}
V_186 = F_100 ( V_3 , V_188 ) ;
if ( V_186 == 0 || V_186 == 0xffffffff ) {
F_45 ( & V_55 -> V_72 ) ;
return V_187 ;
}
F_128 ( V_55 , V_186 , F_122 ) ;
V_186 = F_129 ( V_3 , V_189 ) ;
if ( V_186 & V_190 ) {
if ( V_186 & V_191 ) {
if ( V_3 -> V_50 & V_192 )
F_93 ( 80 ) ;
F_89 ( V_55 ) ;
}
F_130 ( V_3 , V_189 , V_190 ) ;
}
F_45 ( & V_55 -> V_72 ) ;
return V_193 ;
}
static int F_131 ( struct V_2 * V_3 , int V_138 )
{
unsigned int V_53 = ( V_138 << 28 ) | ( V_194 << 20 ) |
( V_195 << 8 ) | V_196 ;
struct V_54 * V_55 = F_3 ( V_3 ) ;
int V_35 ;
unsigned int V_140 = - 1 ;
F_15 ( & V_55 -> V_197 ) ;
V_3 -> V_157 = 1 ;
F_106 ( V_55 , V_53 ) ;
V_35 = F_108 ( V_55 , V_138 , & V_140 ) ;
V_3 -> V_157 = 0 ;
F_17 ( & V_55 -> V_197 ) ;
if ( V_35 < 0 || V_140 == - 1 )
return - V_153 ;
F_95 ( V_3 -> V_47 -> V_48 , L_9 , V_138 ) ;
return 0 ;
}
void F_132 ( struct V_115 * V_55 )
{
struct V_2 * V_3 = F_76 ( & V_55 -> V_30 ) ;
V_55 -> V_160 = 1 ;
F_120 ( V_3 ) ;
F_117 ( V_3 , true ) ;
if ( V_55 -> V_30 . V_198 )
F_133 ( V_55 ) ;
V_55 -> V_160 = 0 ;
}
static int F_134 ( struct V_2 * V_3 )
{
int V_199 ;
unsigned int V_200 ;
if ( ! V_3 -> V_201 )
return 0 ;
V_199 = V_3 -> V_201 [ V_3 -> V_202 ] ;
if ( V_199 == 0 )
return 0 ;
if ( V_199 < 50 || V_199 > 60000 )
V_200 = 0 ;
else
V_200 = F_87 ( V_199 ) ;
if ( V_200 == 0 )
F_96 ( V_3 -> V_47 -> V_48 ,
L_10 , V_199 ) ;
return V_200 ;
}
int F_135 ( struct V_2 * V_3 , const char * V_203 ,
const struct V_204 * V_205 )
{
struct V_115 * V_55 = & V_3 -> V_55 ;
int V_35 ;
V_35 = F_136 ( & V_55 -> V_30 , V_3 -> V_47 -> V_48 , & V_206 ,
V_205 ) ;
if ( V_35 < 0 )
return V_35 ;
V_55 -> V_47 = V_3 -> V_47 ;
F_137 ( & V_55 -> V_207 ) ;
V_55 -> V_208 = V_3 -> V_208 ;
V_55 -> V_209 = V_203 ;
V_55 -> V_210 = - 1 ;
V_55 -> V_30 . V_211 = F_138 ( V_3 ) ;
if ( V_3 -> V_76 [ 0 ] != F_48 ||
V_3 -> V_76 [ 1 ] != F_48 )
V_55 -> V_30 . V_212 = true ;
if ( V_3 -> V_213 )
V_55 -> V_30 . V_213 = V_3 -> V_213 [ V_3 -> V_202 ] ;
if ( V_3 -> V_50 & V_214 )
V_55 -> V_30 . V_215 = true ;
if ( V_3 -> V_50 & V_216 ) {
F_95 ( V_3 -> V_47 -> V_48 , L_11 ) ;
V_55 -> V_151 = 1 ;
}
if ( V_3 -> V_50 & V_217 )
V_55 -> V_30 . V_218 = true ;
if ( V_3 -> V_50 & V_219 ) {
F_95 ( V_3 -> V_47 -> V_48 , L_12 ) ;
V_55 -> V_30 . V_220 = 1 ;
V_55 -> V_158 = 1 ;
}
return 0 ;
}
int F_139 ( struct V_2 * V_3 , unsigned int V_221 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
int V_222 , V_223 , V_35 ;
V_223 = 0 ;
if ( ! V_221 )
V_221 = V_224 ;
for ( V_222 = 0 ; V_222 < V_221 ; V_222 ++ ) {
if ( ( V_55 -> V_225 & ( 1 << V_222 ) ) & V_3 -> V_226 ) {
if ( F_131 ( V_3 , V_222 ) < 0 ) {
F_96 ( V_3 -> V_47 -> V_48 ,
L_13 , V_222 ) ;
V_55 -> V_225 &= ~ ( 1 << V_222 ) ;
F_120 ( V_3 ) ;
F_117 ( V_3 , true ) ;
}
}
}
for ( V_222 = 0 ; V_222 < V_221 ; V_222 ++ ) {
if ( ( V_55 -> V_225 & ( 1 << V_222 ) ) & V_3 -> V_226 ) {
struct V_117 * V_19 ;
V_35 = F_140 ( & V_3 -> V_55 , V_3 -> V_47 , V_222 , & V_19 ) ;
if ( V_35 < 0 )
continue;
V_19 -> V_227 = F_134 ( V_3 ) ;
V_19 -> V_228 = V_3 -> V_228 ;
V_223 ++ ;
}
}
if ( ! V_223 ) {
F_33 ( V_3 -> V_47 -> V_48 , L_14 ) ;
return - V_229 ;
}
return 0 ;
}
int F_141 ( struct V_2 * V_3 )
{
struct V_117 * V_19 ;
F_142 (codec, &chip->bus) {
F_143 ( V_19 ) ;
}
return 0 ;
}
static int F_144 ( struct V_2 * V_3 , unsigned char V_71 )
{
if ( V_71 >= V_3 -> V_230 &&
V_71 < V_3 -> V_230 + V_3 -> V_52 )
return V_22 ;
return V_124 ;
}
int F_145 ( struct V_2 * V_3 )
{
int V_199 ;
int V_231 [ 2 ] = { 0 , 0 } ;
for ( V_199 = 0 ; V_199 < V_3 -> V_232 ; V_199 ++ ) {
struct V_1 * V_1 = F_80 ( sizeof( * V_1 ) , V_126 ) ;
int V_233 , V_234 ;
if ( ! V_1 )
return - V_127 ;
V_233 = F_144 ( V_3 , V_199 ) ;
if ( V_3 -> V_50 & V_235 )
V_234 = ++ V_231 [ V_233 ] ;
else
V_234 = V_199 + 1 ;
F_146 ( F_3 ( V_3 ) , F_7 ( V_1 ) ,
V_199 , V_233 , V_234 ) ;
}
return 0 ;
}
void F_147 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_3 ( V_3 ) ;
struct V_6 * V_7 ;
while ( ! F_148 ( & V_55 -> V_236 ) ) {
V_7 = F_149 ( & V_55 -> V_236 , struct V_6 , V_114 ) ;
F_73 ( & V_7 -> V_114 ) ;
F_74 ( F_4 ( V_7 ) ) ;
}
}
