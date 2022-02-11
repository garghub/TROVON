static struct V_1 * F_1 ( struct V_1 * * V_2 , int V_3 )
{
struct V_1 * V_1 ;
struct V_1 * V_4 ;
F_2 ( ! V_3 ) ;
F_2 ( ! V_2 ) ;
V_1 = * V_2 ;
if ( ! V_1 )
return NULL ;
while ( V_1 ) {
V_4 = F_3 ( V_1 ) ;
if ( -- V_3 == 0 )
break;
if ( V_4 == NULL )
return NULL ;
V_1 = V_4 ;
}
F_4 ( V_1 , 0 ) ;
V_1 = * V_2 ;
* V_2 = V_4 ;
return V_1 ;
}
static struct V_1 * F_5 ( struct V_1 * V_1 , int * V_5 )
{
struct V_1 * V_4 ;
int V_6 = 1 ;
while ( ( V_4 = F_3 ( V_1 ) ) )
++ V_6 , V_1 = V_4 ;
if ( V_5 )
* V_5 = V_6 ;
return V_1 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_1 * V_4 ;
int V_6 = 0 ;
F_7 (page, tmp) {
F_8 ( V_1 ) ;
++ V_6 ;
}
return V_6 ;
}
static void F_9 ( struct V_1 * * V_2 ,
struct V_1 * V_7 , struct V_1 * V_8 )
{
#if 1
struct V_1 * V_4 ;
V_4 = F_5 ( V_7 , NULL ) ;
F_2 ( V_4 != V_8 ) ;
#endif
F_4 ( V_8 , ( unsigned long ) * V_2 ) ;
* V_2 = V_7 ;
}
static struct V_1 * F_10 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_4 = NULL ;
int V_6 = 0 ;
if ( V_12 >= V_11 ) {
F_11 ( & V_13 ) ;
V_1 = F_1 ( & V_14 , V_11 ) ;
if ( V_1 )
V_12 -= V_11 ;
F_12 ( & V_13 ) ;
if ( V_1 )
return V_1 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
V_4 = F_13 ( V_15 ) ;
if ( ! V_4 )
break;
F_4 ( V_4 , ( unsigned long ) V_1 ) ;
V_1 = V_4 ;
}
if ( V_6 == V_11 )
return V_1 ;
if ( V_1 ) {
V_4 = F_5 ( V_1 , NULL ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
return NULL ;
}
static void F_14 ( struct V_9 * V_10 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_16 * V_20 , * V_21 ;
F_15 (le, tle, &mdev->net_ee) {
V_19 = F_16 ( V_20 , struct V_18 , V_22 . V_23 ) ;
if ( F_17 ( V_19 ) )
break;
F_18 ( V_20 , V_17 ) ;
}
}
static void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_24 ) ;
struct V_18 * V_19 , * V_25 ;
F_21 ( & V_10 -> V_26 ) ;
F_14 ( V_10 , & V_24 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_23 (e, t, &reclaimed, w.list)
F_24 ( V_10 , V_19 ) ;
}
static struct V_1 * F_25 ( struct V_9 * V_10 , unsigned V_11 , bool V_27 )
{
struct V_1 * V_1 = NULL ;
F_26 ( V_28 ) ;
if ( F_27 ( & V_10 -> V_29 ) < V_10 -> V_30 -> V_31 )
V_1 = F_10 ( V_10 , V_11 ) ;
while ( V_1 == NULL ) {
F_28 ( & V_32 , & V_28 , V_33 ) ;
F_19 ( V_10 ) ;
if ( F_27 ( & V_10 -> V_29 ) < V_10 -> V_30 -> V_31 ) {
V_1 = F_10 ( V_10 , V_11 ) ;
if ( V_1 )
break;
}
if ( ! V_27 )
break;
if ( F_29 ( V_34 ) ) {
F_30 ( V_35 , L_1 ) ;
break;
}
F_31 () ;
}
F_32 ( & V_32 , & V_28 ) ;
if ( V_1 )
F_33 ( V_11 , & V_10 -> V_29 ) ;
return V_1 ;
}
static void F_34 ( struct V_9 * V_10 , struct V_1 * V_1 , int V_36 )
{
T_1 * V_37 = V_36 ? & V_10 -> V_38 : & V_10 -> V_29 ;
int V_6 ;
if ( V_12 > ( V_39 / V_40 ) * V_41 )
V_6 = F_6 ( V_1 ) ;
else {
struct V_1 * V_4 ;
V_4 = F_5 ( V_1 , & V_6 ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
V_6 = F_35 ( V_6 , V_37 ) ;
if ( V_6 < 0 )
F_30 ( V_35 , L_2 ,
V_36 ? L_3 : L_4 , V_6 ) ;
F_36 ( & V_32 ) ;
}
struct V_18 * F_37 ( struct V_9 * V_10 ,
T_2 V_42 ,
T_3 V_43 ,
unsigned int V_44 ,
T_4 V_45 ) __must_hold( T_5 )
{
struct V_18 * V_19 ;
struct V_1 * V_1 ;
unsigned V_46 = ( V_44 + V_40 - 1 ) >> V_47 ;
if ( F_38 ( V_10 , V_48 ) )
return NULL ;
V_19 = F_39 ( V_49 , V_45 & ~ V_50 ) ;
if ( ! V_19 ) {
if ( ! ( V_45 & V_51 ) )
F_40 ( V_35 , L_5 ) ;
return NULL ;
}
V_1 = F_25 ( V_10 , V_46 , ( V_45 & V_52 ) ) ;
if ( ! V_1 )
goto V_53;
F_41 ( & V_19 -> V_54 ) ;
V_19 -> V_55 = NULL ;
V_19 -> V_10 = V_10 ;
V_19 -> V_56 = V_1 ;
F_42 ( & V_19 -> V_57 , 0 ) ;
V_19 -> V_58 = V_44 ;
V_19 -> V_59 = 0 ;
V_19 -> V_43 = V_43 ;
V_19 -> V_60 = V_42 ;
return V_19 ;
V_53:
F_43 ( V_19 , V_49 ) ;
return NULL ;
}
void F_44 ( struct V_9 * V_10 , struct V_18 * V_19 , int V_36 )
{
if ( V_19 -> V_59 & V_61 )
F_45 ( V_19 -> V_62 ) ;
F_34 ( V_10 , V_19 -> V_56 , V_36 ) ;
F_46 ( F_27 ( & V_19 -> V_57 ) == 0 ) ;
F_46 ( F_47 ( & V_19 -> V_54 ) ) ;
F_43 ( V_19 , V_49 ) ;
}
int F_48 ( struct V_9 * V_10 , struct V_16 * V_23 )
{
F_20 ( V_63 ) ;
struct V_18 * V_19 , * V_25 ;
int V_64 = 0 ;
int V_36 = V_23 == & V_10 -> V_65 ;
F_21 ( & V_10 -> V_26 ) ;
F_49 ( V_23 , & V_63 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_23 (e, t, &work_list, w.list) {
F_44 ( V_10 , V_19 , V_36 ) ;
V_64 ++ ;
}
return V_64 ;
}
static int F_50 ( struct V_9 * V_10 )
{
F_20 ( V_63 ) ;
F_20 ( V_24 ) ;
struct V_18 * V_19 , * V_25 ;
int V_66 = ( V_10 -> V_67 . V_68 >= V_69 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_14 ( V_10 , & V_24 ) ;
F_49 ( & V_10 -> V_70 , & V_63 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_23 (e, t, &reclaimed, w.list)
F_24 ( V_10 , V_19 ) ;
F_23 (e, t, &work_list, w.list) {
V_66 = V_19 -> V_22 . V_71 ( V_10 , & V_19 -> V_22 , ! V_66 ) && V_66 ;
F_51 ( V_10 , V_19 ) ;
}
F_36 ( & V_10 -> V_72 ) ;
return V_66 ;
}
void F_52 ( struct V_9 * V_10 , struct V_16 * V_2 )
{
F_26 ( V_28 ) ;
while ( ! F_53 ( V_2 ) ) {
F_28 ( & V_10 -> V_72 , & V_28 , V_73 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_54 () ;
F_32 ( & V_10 -> V_72 , & V_28 ) ;
F_21 ( & V_10 -> V_26 ) ;
}
}
void F_55 ( struct V_9 * V_10 , struct V_16 * V_2 )
{
F_21 ( & V_10 -> V_26 ) ;
F_52 ( V_10 , V_2 ) ;
F_22 ( & V_10 -> V_26 ) ;
}
static int F_56 ( struct V_9 * V_10 , const char * * V_74 ,
struct V_75 * V_76 , struct V_75 * * V_77 )
{
struct V_76 * V_78 = V_76 -> V_78 ;
int V_79 = 0 ;
* V_74 = L_6 ;
V_79 = V_76 -> V_80 -> V_81 ( V_76 , 5 ) ;
if ( V_79 < 0 )
goto V_82;
* V_74 = L_7 ;
V_79 = F_57 ( V_78 -> V_83 , V_78 -> V_84 , V_78 -> V_85 ,
V_77 ) ;
if ( V_79 < 0 )
goto V_82;
* V_74 = L_8 ;
V_79 = V_76 -> V_80 -> V_86 ( V_76 , * V_77 , 0 ) ;
if ( V_79 < 0 ) {
F_58 ( * V_77 ) ;
* V_77 = NULL ;
goto V_82;
}
( * V_77 ) -> V_80 = V_76 -> V_80 ;
F_59 ( ( * V_77 ) -> V_80 -> V_87 ) ;
V_82:
return V_79 ;
}
static int F_60 ( struct V_9 * V_10 , struct V_75 * V_76 ,
void * V_88 , T_6 V_58 , int V_59 )
{
T_7 V_89 ;
struct V_90 V_91 = {
. V_92 = V_88 ,
. V_93 = V_58 ,
} ;
struct V_94 V_95 = {
. V_96 = 1 ,
. V_97 = (struct V_98 * ) & V_91 ,
. V_99 = ( V_59 ? V_59 : V_100 | V_101 )
} ;
int V_102 ;
V_89 = F_61 () ;
F_62 ( V_103 ) ;
V_102 = F_63 ( V_76 , & V_95 , V_58 , V_95 . V_99 ) ;
F_62 ( V_89 ) ;
return V_102 ;
}
static int F_64 ( struct V_9 * V_10 , void * V_88 , T_6 V_58 )
{
T_7 V_89 ;
struct V_90 V_91 = {
. V_92 = V_88 ,
. V_93 = V_58 ,
} ;
struct V_94 V_95 = {
. V_96 = 1 ,
. V_97 = (struct V_98 * ) & V_91 ,
. V_99 = V_100 | V_101
} ;
int V_102 ;
V_89 = F_61 () ;
F_62 ( V_103 ) ;
for (; ; ) {
V_102 = F_63 ( V_10 -> V_104 . V_75 , & V_95 , V_58 , V_95 . V_99 ) ;
if ( V_102 == V_58 )
break;
if ( V_102 < 0 ) {
if ( V_102 == - V_105 )
F_65 ( V_35 , L_9 ) ;
else if ( V_102 != - V_106 )
F_40 ( V_35 , L_10 , V_102 ) ;
break;
} else if ( V_102 == 0 ) {
F_65 ( V_35 , L_11 ) ;
break;
} else {
break;
}
} ;
F_62 ( V_89 ) ;
if ( V_102 != V_58 )
F_66 ( V_10 , F_67 ( V_68 , V_107 ) ) ;
return V_102 ;
}
static void F_68 ( struct V_75 * V_76 , unsigned int V_108 ,
unsigned int V_109 )
{
if ( V_108 ) {
V_76 -> V_78 -> V_110 = V_108 ;
V_76 -> V_78 -> V_111 |= V_112 ;
}
if ( V_109 ) {
V_76 -> V_78 -> V_113 = V_109 ;
V_76 -> V_78 -> V_111 |= V_114 ;
}
}
static struct V_75 * F_69 ( struct V_9 * V_10 )
{
const char * V_74 ;
struct V_75 * V_76 ;
struct V_115 V_116 ;
int V_79 ;
int V_117 = 1 ;
if ( ! F_70 ( V_10 ) )
return NULL ;
V_74 = L_12 ;
V_79 = F_71 ( ( (struct V_118 * ) V_10 -> V_30 -> V_119 ) -> V_120 ,
V_121 , V_122 , & V_76 ) ;
if ( V_79 < 0 ) {
V_76 = NULL ;
goto V_82;
}
V_76 -> V_78 -> V_123 =
V_76 -> V_78 -> V_124 = V_10 -> V_30 -> V_125 * V_126 ;
F_68 ( V_76 , V_10 -> V_30 -> V_127 ,
V_10 -> V_30 -> V_128 ) ;
memcpy ( & V_116 , V_10 -> V_30 -> V_119 ,
F_72 ( int , V_10 -> V_30 -> V_129 , sizeof( V_116 ) ) ) ;
if ( ( (struct V_118 * ) V_10 -> V_30 -> V_119 ) -> V_120 == V_130 )
V_116 . V_131 = 0 ;
else
( (struct V_132 * ) & V_116 ) -> V_133 = 0 ;
V_74 = L_13 ;
V_79 = V_76 -> V_80 -> V_134 ( V_76 ,
(struct V_118 * ) & V_116 ,
V_10 -> V_30 -> V_129 ) ;
if ( V_79 < 0 )
goto V_82;
V_117 = 0 ;
V_74 = L_14 ;
V_79 = V_76 -> V_80 -> V_135 ( V_76 ,
(struct V_118 * ) V_10 -> V_30 -> V_136 ,
V_10 -> V_30 -> V_137 , 0 ) ;
V_82:
if ( V_79 < 0 ) {
if ( V_76 ) {
F_58 ( V_76 ) ;
V_76 = NULL ;
}
switch ( - V_79 ) {
case V_138 : case V_139 : case V_140 :
case V_141 : case V_106 :
case V_142 : case V_143 :
case V_144 : case V_145 :
V_117 = 0 ;
break;
default:
F_40 ( V_35 , L_15 , V_74 , V_79 ) ;
}
if ( V_117 )
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
}
F_73 ( V_10 ) ;
return V_76 ;
}
static struct V_75 * F_74 ( struct V_9 * V_10 )
{
int V_147 , V_79 ;
struct V_75 * V_148 = NULL , * V_149 ;
const char * V_74 ;
if ( ! F_70 ( V_10 ) )
return NULL ;
V_74 = L_12 ;
V_79 = F_71 ( ( (struct V_118 * ) V_10 -> V_30 -> V_119 ) -> V_120 ,
V_121 , V_122 , & V_149 ) ;
if ( V_79 ) {
V_149 = NULL ;
goto V_82;
}
V_147 = V_10 -> V_30 -> V_125 * V_126 ;
V_147 += ( F_75 () & 1 ) ? V_147 / 7 : - V_147 / 7 ;
V_149 -> V_78 -> V_150 = V_151 ;
V_149 -> V_78 -> V_123 = V_147 ;
V_149 -> V_78 -> V_124 = V_147 ;
F_68 ( V_149 , V_10 -> V_30 -> V_127 ,
V_10 -> V_30 -> V_128 ) ;
V_74 = L_16 ;
V_79 = V_149 -> V_80 -> V_134 ( V_149 ,
(struct V_118 * ) V_10 -> V_30 -> V_119 ,
V_10 -> V_30 -> V_129 ) ;
if ( V_79 < 0 )
goto V_82;
V_79 = F_56 ( V_10 , & V_74 , V_149 , & V_148 ) ;
V_82:
if ( V_149 )
F_58 ( V_149 ) ;
if ( V_79 < 0 ) {
if ( V_79 != - V_139 && V_79 != - V_141 && V_79 != - V_106 ) {
F_40 ( V_35 , L_15 , V_74 , V_79 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
}
}
F_73 ( V_10 ) ;
return V_148 ;
}
static int F_76 ( struct V_9 * V_10 ,
struct V_75 * V_76 , enum V_152 V_153 )
{
struct V_154 * V_155 = & V_10 -> V_104 . V_156 . V_157 . V_158 ;
return F_77 ( V_10 , V_76 , V_153 , V_155 , sizeof( * V_155 ) , 0 ) ;
}
static enum V_152 F_78 ( struct V_9 * V_10 , struct V_75 * V_76 )
{
struct V_154 * V_155 = & V_10 -> V_104 . V_159 . V_157 . V_158 ;
int V_160 ;
V_160 = F_60 ( V_10 , V_76 , V_155 , sizeof( * V_155 ) , 0 ) ;
if ( V_160 == sizeof( * V_155 ) && V_155 -> V_161 == V_162 )
return F_79 ( V_155 -> V_163 ) ;
return 0xffff ;
}
static int F_80 ( struct V_9 * V_10 , struct V_75 * * V_76 )
{
int V_160 ;
char V_164 [ 4 ] ;
if ( ! * V_76 )
return false ;
V_160 = F_60 ( V_10 , * V_76 , V_164 , 4 , V_165 | V_166 ) ;
if ( V_160 > 0 || V_160 == - V_139 ) {
return true ;
} else {
F_58 ( * V_76 ) ;
* V_76 = NULL ;
return false ;
}
}
static int F_81 ( struct V_9 * V_10 )
{
struct V_75 * V_167 , * V_76 , * V_168 ;
int V_169 , V_155 , V_66 ;
enum V_170 V_102 ;
F_46 ( ! V_10 -> V_104 . V_75 ) ;
if ( F_82 ( V_10 , F_67 ( V_68 , V_171 ) ) < V_172 )
return - 2 ;
F_83 ( V_173 , & V_10 -> V_59 ) ;
V_76 = NULL ;
V_168 = NULL ;
do {
for ( V_169 = 0 ; ; ) {
V_167 = F_69 ( V_10 ) ;
if ( V_167 || ++ V_169 >= 3 )
break;
F_84 ( V_126 / 10 ) ;
}
if ( V_167 ) {
if ( ! V_76 ) {
F_76 ( V_10 , V_167 , V_174 ) ;
V_76 = V_167 ;
V_167 = NULL ;
} else if ( ! V_168 ) {
F_76 ( V_10 , V_167 , V_175 ) ;
V_168 = V_167 ;
V_167 = NULL ;
} else {
F_40 ( V_35 , L_17 ) ;
goto V_176;
}
}
if ( V_76 && V_168 ) {
F_84 ( V_10 -> V_30 -> V_177 * V_126 / 10 ) ;
V_66 = F_80 ( V_10 , & V_76 ) ;
V_66 = F_80 ( V_10 , & V_168 ) && V_66 ;
if ( V_66 )
break;
}
V_27:
V_167 = F_74 ( V_10 ) ;
if ( V_167 ) {
V_169 = F_78 ( V_10 , V_167 ) ;
F_80 ( V_10 , & V_76 ) ;
F_80 ( V_10 , & V_168 ) ;
switch ( V_169 ) {
case V_174 :
if ( V_76 ) {
F_30 ( V_35 , L_18 ) ;
F_58 ( V_76 ) ;
}
V_76 = V_167 ;
break;
case V_175 :
if ( V_168 ) {
F_30 ( V_35 , L_19 ) ;
F_58 ( V_168 ) ;
}
V_168 = V_167 ;
F_85 ( V_173 , & V_10 -> V_59 ) ;
break;
default:
F_30 ( V_35 , L_20 ) ;
F_58 ( V_167 ) ;
if ( F_75 () & 1 )
goto V_27;
}
}
if ( V_10 -> V_67 . V_68 <= V_146 )
goto V_176;
if ( F_29 ( V_34 ) ) {
F_86 ( V_34 ) ;
F_87 () ;
if ( F_88 ( & V_10 -> V_178 ) == V_179 )
goto V_176;
}
if ( V_76 && V_168 ) {
V_66 = F_80 ( V_10 , & V_76 ) ;
V_66 = F_80 ( V_10 , & V_168 ) && V_66 ;
if ( V_66 )
break;
}
} while ( 1 );
V_168 -> V_78 -> V_150 = V_151 ;
V_76 -> V_78 -> V_150 = V_151 ;
V_76 -> V_78 -> V_180 = V_181 ;
V_168 -> V_78 -> V_180 = V_181 ;
V_76 -> V_78 -> V_182 = V_183 ;
V_168 -> V_78 -> V_182 = V_184 ;
V_76 -> V_78 -> V_124 =
V_76 -> V_78 -> V_123 = V_10 -> V_30 -> V_177 * 4 * V_126 / 10 ;
V_168 -> V_78 -> V_124 = V_10 -> V_30 -> V_185 * V_126 / 10 ;
V_168 -> V_78 -> V_123 = V_10 -> V_30 -> V_186 * V_126 ;
F_89 ( V_76 ) ;
F_89 ( V_168 ) ;
V_10 -> V_104 . V_75 = V_76 ;
V_10 -> V_187 . V_75 = V_168 ;
V_10 -> V_188 = V_189 ;
F_46 ( V_10 -> V_190 . V_191 == NULL ) ;
V_155 = F_90 ( V_10 ) ;
if ( V_155 <= 0 )
return V_155 ;
if ( V_10 -> V_192 ) {
switch ( F_91 ( V_10 ) ) {
case - 1 :
F_40 ( V_35 , L_21 ) ;
return - 1 ;
case 0 :
F_40 ( V_35 , L_22 ) ;
return 0 ;
}
}
V_76 -> V_78 -> V_124 = V_10 -> V_30 -> V_185 * V_126 / 10 ;
V_76 -> V_78 -> V_123 = V_193 ;
F_42 ( & V_10 -> V_194 , 0 ) ;
V_10 -> V_195 = 0 ;
if ( F_92 ( V_10 ) == - 1 )
return - 1 ;
F_85 ( V_196 , & V_10 -> V_59 ) ;
F_93 ( V_10 , & V_10 -> V_197 ) ;
F_94 ( V_10 , 0 , 0 ) ;
F_95 ( V_10 ) ;
F_96 ( V_10 ) ;
F_83 ( V_198 , & V_10 -> V_59 ) ;
F_83 ( V_199 , & V_10 -> V_59 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_102 = F_97 ( F_98 ( V_10 , V_68 , V_69 ) , V_200 , NULL ) ;
if ( V_10 -> V_67 . V_68 != V_69 )
F_83 ( V_196 , & V_10 -> V_59 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_102 < V_172 )
return 0 ;
F_99 ( & V_10 -> V_190 ) ;
F_100 ( & V_10 -> V_201 , V_189 + V_126 ) ;
return 1 ;
V_176:
if ( V_76 )
F_58 ( V_76 ) ;
if ( V_168 )
F_58 ( V_168 ) ;
return - 1 ;
}
static int F_101 ( struct V_9 * V_10 , enum V_152 * V_153 , unsigned int * V_202 )
{
union V_203 * V_155 = & V_10 -> V_104 . V_159 . V_157 ;
int V_204 ;
V_204 = F_64 ( V_10 , V_155 , sizeof( * V_155 ) ) ;
if ( F_102 ( V_204 != sizeof( * V_155 ) ) ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_23 , V_204 ) ;
return false ;
}
if ( F_103 ( V_155 -> V_158 . V_161 == V_162 ) ) {
* V_153 = F_79 ( V_155 -> V_158 . V_163 ) ;
* V_202 = F_79 ( V_155 -> V_158 . V_205 ) ;
} else if ( V_155 -> V_206 . V_161 == V_207 ) {
* V_153 = F_79 ( V_155 -> V_206 . V_163 ) ;
* V_202 = F_104 ( V_155 -> V_206 . V_205 ) ;
} else {
F_40 ( V_35 , L_24 ,
F_104 ( V_155 -> V_158 . V_161 ) ,
F_79 ( V_155 -> V_158 . V_163 ) ,
F_79 ( V_155 -> V_158 . V_205 ) ) ;
return false ;
}
V_10 -> V_188 = V_189 ;
return true ;
}
static void F_105 ( struct V_9 * V_10 )
{
int V_102 ;
if ( V_10 -> V_208 >= V_209 && F_106 ( V_10 ) ) {
V_102 = F_107 ( V_10 -> V_210 -> V_211 , V_212 ,
NULL ) ;
if ( V_102 ) {
F_65 ( V_35 , L_25 , V_102 ) ;
F_108 ( V_10 , V_213 ) ;
}
F_109 ( V_10 ) ;
}
}
static enum V_214 F_110 ( struct V_9 * V_10 ,
struct V_215 * V_55 ,
enum V_216 V_217 )
{
int V_218 ;
struct V_215 * V_219 ;
enum V_214 V_102 = V_220 ;
F_11 ( & V_10 -> V_221 ) ;
do {
V_219 = NULL ;
V_218 = F_27 ( & V_55 -> V_218 ) ;
switch ( V_217 & ~ V_222 ) {
case V_223 :
F_111 ( & V_55 -> V_224 ) ;
break;
case V_225 :
F_85 ( V_226 , & V_55 -> V_59 ) ;
break;
case V_227 :
break;
}
if ( V_218 != 0 &&
F_27 ( & V_55 -> V_224 ) == 0 &&
( F_112 ( V_226 , & V_55 -> V_59 ) || V_217 & V_222 ) ) {
if ( ! ( V_217 & V_222 ) ) {
F_12 ( & V_10 -> V_221 ) ;
F_113 ( V_10 , V_55 -> V_228 , V_218 ) ;
F_11 ( & V_10 -> V_221 ) ;
}
if ( F_112 ( V_226 , & V_55 -> V_59 ) )
F_114 ( V_10 ) ;
if ( V_10 -> V_229 != V_55 ) {
V_219 = F_16 ( V_55 -> V_23 . V_230 , struct V_215 , V_23 ) ;
F_115 ( & V_55 -> V_23 ) ;
V_217 = V_227 | ( V_217 & V_222 ) ;
V_10 -> V_231 -- ;
F_45 ( V_55 ) ;
if ( V_102 == V_220 )
V_102 = V_232 ;
} else {
V_55 -> V_59 = 0 ;
F_42 ( & V_55 -> V_218 , 0 ) ;
if ( V_102 == V_220 )
V_102 = V_233 ;
F_36 ( & V_10 -> V_72 ) ;
}
}
if ( ! V_219 )
break;
V_55 = V_219 ;
} while ( 1 );
F_12 ( & V_10 -> V_221 ) ;
return V_102 ;
}
void F_108 ( struct V_9 * V_10 , enum V_234 V_235 ) __must_hold( T_5 )
{
enum V_234 V_236 ;
static char * V_237 [] = {
[ V_238 ] = L_26 ,
[ V_213 ] = L_27 ,
[ V_209 ] = L_28 ,
} ;
V_236 = V_10 -> V_208 ;
V_235 = F_116 ( V_236 , V_235 ) ;
if ( V_235 == V_209 && V_10 -> V_210 -> V_239 . V_240 )
V_235 = V_213 ;
if ( V_235 == V_213 && V_10 -> V_210 -> V_239 . V_241 )
V_235 = V_238 ;
V_10 -> V_208 = V_235 ;
if ( V_236 != V_10 -> V_208 || V_235 == V_209 )
F_65 ( V_35 , L_29 , V_237 [ V_10 -> V_208 ] ) ;
}
int F_117 ( struct V_9 * V_10 , struct V_18 * V_19 ,
const unsigned V_242 , const int V_243 )
{
struct V_244 * V_245 = NULL ;
struct V_244 * V_244 ;
struct V_1 * V_1 = V_19 -> V_56 ;
T_3 V_43 = V_19 -> V_43 ;
unsigned V_246 = V_19 -> V_58 ;
unsigned V_247 = 0 ;
unsigned V_46 = ( V_246 + V_40 - 1 ) >> V_47 ;
int V_79 = - V_248 ;
V_249:
V_244 = F_118 ( V_181 , V_46 ) ;
if ( ! V_244 ) {
F_40 ( V_35 , L_30 ) ;
goto V_53;
}
V_244 -> V_250 = V_43 ;
V_244 -> V_251 = V_10 -> V_210 -> V_211 ;
V_244 -> V_252 = V_242 ;
V_244 -> V_253 = V_19 ;
V_244 -> V_254 = V_255 ;
V_244 -> V_256 = V_245 ;
V_245 = V_244 ;
++ V_247 ;
F_119 (page) {
unsigned V_5 = F_72 ( unsigned , V_246 , V_40 ) ;
if ( ! F_120 ( V_244 , V_1 , V_5 , 0 ) ) {
if ( V_244 -> V_257 == 0 ) {
F_40 ( V_35 ,
L_31
L_32 ,
V_5 , ( unsigned long long ) V_244 -> V_250 ) ;
V_79 = - V_258 ;
goto V_53;
}
goto V_249;
}
V_246 -= V_5 ;
V_43 += V_5 >> 9 ;
-- V_46 ;
}
F_46 ( V_1 == NULL ) ;
F_46 ( V_246 == 0 ) ;
F_42 ( & V_19 -> V_57 , V_247 ) ;
do {
V_244 = V_245 ;
V_245 = V_245 -> V_256 ;
V_244 -> V_256 = NULL ;
F_121 ( V_10 , V_243 , V_244 ) ;
} while ( V_245 );
return 0 ;
V_53:
while ( V_245 ) {
V_244 = V_245 ;
V_245 = V_245 -> V_256 ;
F_122 ( V_244 ) ;
}
return V_79 ;
}
static int F_123 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
int V_102 ;
struct V_259 * V_260 = & V_10 -> V_104 . V_159 . V_261 ;
struct V_215 * V_55 ;
F_124 ( V_10 ) ;
V_10 -> V_229 -> V_228 = V_260 -> V_261 ;
V_102 = F_110 ( V_10 , V_10 -> V_229 , V_225 ) ;
switch ( V_10 -> V_208 ) {
case V_238 :
if ( V_102 == V_233 )
return true ;
V_55 = F_125 ( sizeof( struct V_215 ) , V_181 ) ;
if ( V_55 )
break;
else
F_30 ( V_35 , L_33 ) ;
case V_209 :
case V_213 :
F_55 ( V_10 , & V_10 -> V_262 ) ;
F_105 ( V_10 ) ;
if ( F_27 ( & V_10 -> V_229 -> V_218 ) ) {
V_55 = F_125 ( sizeof( struct V_215 ) , V_181 ) ;
if ( V_55 )
break;
}
V_55 = V_10 -> V_229 ;
F_126 ( V_10 -> V_72 , F_27 ( & V_55 -> V_218 ) == 0 ) ;
F_46 ( F_27 ( & V_55 -> V_224 ) == 0 ) ;
F_46 ( V_55 -> V_59 == 0 ) ;
return true ;
default:
F_40 ( V_35 , L_34 , V_10 -> V_208 ) ;
return false ;
}
V_55 -> V_59 = 0 ;
F_42 ( & V_55 -> V_218 , 0 ) ;
F_42 ( & V_55 -> V_224 , 0 ) ;
F_11 ( & V_10 -> V_221 ) ;
if ( F_27 ( & V_10 -> V_229 -> V_218 ) ) {
F_127 ( & V_55 -> V_23 , & V_10 -> V_229 -> V_23 ) ;
V_10 -> V_229 = V_55 ;
V_10 -> V_231 ++ ;
} else {
F_45 ( V_55 ) ;
}
F_12 ( & V_10 -> V_221 ) ;
return true ;
}
static struct V_18 *
F_128 ( struct V_9 * V_10 , T_2 V_42 , T_3 V_43 , int V_44 ) __must_hold( T_5 )
{
const T_3 V_263 = F_129 ( V_10 -> V_264 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_265 , V_246 , V_160 ;
void * V_266 = V_10 -> V_267 ;
void * V_268 = V_10 -> V_269 ;
unsigned long * V_104 ;
V_265 = ( V_10 -> V_270 >= 87 && V_10 -> V_271 ) ?
F_130 ( V_10 -> V_271 ) : 0 ;
if ( V_265 ) {
V_160 = F_64 ( V_10 , V_266 , V_265 ) ;
if ( V_160 != V_265 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 ,
L_35 ,
V_160 , V_265 ) ;
return NULL ;
}
}
V_44 -= V_265 ;
F_131 (data_size == 0 ) return NULL ;
F_131 (data_size & 0x1ff ) return NULL ;
F_131 (data_size > DRBD_MAX_BIO_SIZE) return NULL ;
if ( V_43 + ( V_44 >> 9 ) > V_263 ) {
F_40 ( V_35 , L_36
L_37 ,
( unsigned long long ) V_263 ,
( unsigned long long ) V_43 , V_44 ) ;
return NULL ;
}
V_19 = F_37 ( V_10 , V_42 , V_43 , V_44 , V_181 ) ;
if ( ! V_19 )
return NULL ;
V_246 = V_44 ;
V_1 = V_19 -> V_56 ;
F_119 (page) {
unsigned V_5 = F_72 ( int , V_246 , V_40 ) ;
V_104 = F_132 ( V_1 ) ;
V_160 = F_64 ( V_10 , V_104 , V_5 ) ;
if ( F_38 ( V_10 , V_272 ) ) {
F_40 ( V_35 , L_38 ) ;
V_104 [ 0 ] = V_104 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_133 ( V_1 ) ;
if ( V_160 != V_5 ) {
F_51 ( V_10 , V_19 ) ;
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_39 ,
V_160 , V_5 ) ;
return NULL ;
}
V_246 -= V_160 ;
}
if ( V_265 ) {
F_134 ( V_10 , V_10 -> V_271 , V_19 , V_268 ) ;
if ( memcmp ( V_266 , V_268 , V_265 ) ) {
F_40 ( V_35 , L_40 ,
( unsigned long long ) V_43 , V_44 ) ;
F_135 ( V_10 , L_41 ,
V_265 , V_266 , V_268 , V_19 ) ;
F_51 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_273 += V_44 >> 9 ;
return V_19 ;
}
static int F_136 ( struct V_9 * V_10 , int V_44 )
{
struct V_1 * V_1 ;
int V_160 , V_102 = 1 ;
void * V_104 ;
if ( ! V_44 )
return true ;
V_1 = F_25 ( V_10 , 1 , 1 ) ;
V_104 = F_132 ( V_1 ) ;
while ( V_44 ) {
V_160 = F_64 ( V_10 , V_104 , F_72 ( int , V_44 , V_40 ) ) ;
if ( V_160 != F_72 ( int , V_44 , V_40 ) ) {
V_102 = 0 ;
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 ,
L_39 ,
V_160 , F_72 ( int , V_44 , V_40 ) ) ;
break;
}
V_44 -= V_160 ;
}
F_133 ( V_1 ) ;
F_34 ( V_10 , V_1 , 0 ) ;
return V_102 ;
}
static int F_137 ( struct V_9 * V_10 , struct V_274 * V_275 ,
T_3 V_43 , int V_44 )
{
struct V_276 * V_277 ;
struct V_244 * V_244 ;
int V_265 , V_160 , V_6 , V_278 ;
void * V_266 = V_10 -> V_267 ;
void * V_268 = V_10 -> V_269 ;
V_265 = ( V_10 -> V_270 >= 87 && V_10 -> V_271 ) ?
F_130 ( V_10 -> V_271 ) : 0 ;
if ( V_265 ) {
V_160 = F_64 ( V_10 , V_266 , V_265 ) ;
if ( V_160 != V_265 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 ,
L_42 ,
V_160 , V_265 ) ;
return 0 ;
}
}
V_44 -= V_265 ;
V_10 -> V_273 += V_44 >> 9 ;
V_244 = V_275 -> V_279 ;
F_46 ( V_43 == V_244 -> V_250 ) ;
F_138 (bvec, bio, i) {
V_278 = F_72 ( int , V_44 , V_277 -> V_280 ) ;
V_160 = F_64 ( V_10 ,
F_132 ( V_277 -> V_281 ) + V_277 -> V_282 ,
V_278 ) ;
F_133 ( V_277 -> V_281 ) ;
if ( V_160 != V_278 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_43
L_44 ,
V_160 , V_278 ) ;
return 0 ;
}
V_44 -= V_160 ;
}
if ( V_265 ) {
F_139 ( V_10 , V_10 -> V_271 , V_244 , V_268 ) ;
if ( memcmp ( V_266 , V_268 , V_265 ) ) {
F_40 ( V_35 , L_45 ) ;
return 0 ;
}
}
F_46 ( V_44 == 0 ) ;
return 1 ;
}
static int F_140 ( struct V_9 * V_10 , struct V_283 * V_22 , int V_284 )
{
struct V_18 * V_19 = (struct V_18 * ) V_22 ;
T_3 V_43 = V_19 -> V_43 ;
int V_66 ;
F_46 ( F_47 ( & V_19 -> V_54 ) ) ;
if ( F_103 ( ( V_19 -> V_59 & V_285 ) == 0 ) ) {
F_141 ( V_10 , V_43 , V_19 -> V_58 ) ;
V_66 = F_142 ( V_10 , V_286 , V_19 ) ;
} else {
F_143 ( V_10 , V_43 , V_19 -> V_58 ) ;
V_66 = F_142 ( V_10 , V_287 , V_19 ) ;
}
F_114 ( V_10 ) ;
return V_66 ;
}
static int F_144 ( struct V_9 * V_10 , T_3 V_43 , int V_44 ) __releases( T_5 )
{
struct V_18 * V_19 ;
V_19 = F_128 ( V_10 , V_288 , V_43 , V_44 ) ;
if ( ! V_19 )
goto V_53;
F_145 ( V_10 ) ;
F_124 ( V_10 ) ;
V_19 -> V_22 . V_71 = F_140 ;
F_21 ( & V_10 -> V_26 ) ;
F_127 ( & V_19 -> V_22 . V_23 , & V_10 -> V_289 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_33 ( V_44 >> 9 , & V_10 -> V_290 ) ;
if ( F_117 ( V_10 , V_19 , V_291 , V_292 ) == 0 )
return true ;
F_40 ( V_35 , L_46 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_115 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_51 ( V_10 , V_19 ) ;
V_53:
F_109 ( V_10 ) ;
return false ;
}
static int F_146 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_274 * V_275 ;
T_3 V_43 ;
int V_66 ;
struct V_293 * V_260 = & V_10 -> V_104 . V_159 . V_104 ;
V_43 = F_147 ( V_260 -> V_43 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_275 = F_148 ( V_10 , V_260 -> V_60 , V_43 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( F_102 ( ! V_275 ) ) {
F_40 ( V_35 , L_47 ) ;
return false ;
}
V_66 = F_137 ( V_10 , V_275 , V_43 , V_44 ) ;
if ( V_66 )
F_149 ( V_275 , V_294 ) ;
return V_66 ;
}
static int F_150 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
T_3 V_43 ;
int V_66 ;
struct V_293 * V_260 = & V_10 -> V_104 . V_159 . V_104 ;
V_43 = F_147 ( V_260 -> V_43 ) ;
F_46 ( V_260 -> V_60 == V_288 ) ;
if ( F_106 ( V_10 ) ) {
V_66 = F_144 ( V_10 , V_43 , V_44 ) ;
} else {
if ( F_151 ( & V_295 ) )
F_40 ( V_35 , L_48 ) ;
V_66 = F_136 ( V_10 , V_44 ) ;
F_152 ( V_10 , V_287 , V_260 , V_44 ) ;
}
F_33 ( V_44 >> 9 , & V_10 -> V_296 ) ;
return V_66 ;
}
static int F_153 ( struct V_9 * V_10 , struct V_283 * V_22 , int V_297 )
{
struct V_18 * V_19 = (struct V_18 * ) V_22 ;
T_3 V_43 = V_19 -> V_43 ;
int V_66 = 1 , V_298 ;
if ( V_10 -> V_30 -> V_299 == V_300 ) {
if ( F_103 ( ( V_19 -> V_59 & V_285 ) == 0 ) ) {
V_298 = ( V_10 -> V_67 . V_68 >= V_301 &&
V_10 -> V_67 . V_68 <= V_302 &&
V_19 -> V_59 & V_303 ) ?
V_286 : V_304 ;
V_66 &= F_142 ( V_10 , V_298 , V_19 ) ;
if ( V_298 == V_286 )
F_141 ( V_10 , V_43 , V_19 -> V_58 ) ;
} else {
V_66 = F_142 ( V_10 , V_287 , V_19 ) ;
}
F_114 ( V_10 ) ;
}
if ( V_10 -> V_30 -> V_305 ) {
F_21 ( & V_10 -> V_26 ) ;
F_46 ( ! F_47 ( & V_19 -> V_54 ) ) ;
F_154 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
} else {
F_46 ( F_47 ( & V_19 -> V_54 ) ) ;
}
F_110 ( V_10 , V_19 -> V_55 , V_223 + ( V_297 ? V_222 : 0 ) ) ;
return V_66 ;
}
static int F_155 ( struct V_9 * V_10 , struct V_283 * V_22 , int V_284 )
{
struct V_18 * V_19 = (struct V_18 * ) V_22 ;
int V_66 = 1 ;
F_46 ( V_10 -> V_30 -> V_299 == V_300 ) ;
V_66 = F_142 ( V_10 , V_306 , V_19 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_46 ( ! F_47 ( & V_19 -> V_54 ) ) ;
F_154 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_114 ( V_10 ) ;
return V_66 ;
}
static bool F_156 ( struct V_9 * V_10 , struct V_18 * V_307 )
{
struct V_18 * V_308 ;
bool V_102 = 0 ;
F_21 ( & V_10 -> V_26 ) ;
F_157 (rs_e, &mdev->sync_ee, w.list) {
if ( F_158 ( V_307 -> V_43 , V_307 -> V_58 , V_308 -> V_43 , V_308 -> V_58 ) ) {
V_102 = 1 ;
break;
}
}
F_22 ( & V_10 -> V_26 ) ;
return V_102 ;
}
static int F_159 ( struct V_9 * V_10 , const T_8 V_194 )
{
F_26 ( V_28 ) ;
unsigned int V_309 ;
long V_185 ;
int V_310 = 0 ;
F_11 ( & V_10 -> V_311 ) ;
for (; ; ) {
F_28 ( & V_10 -> V_312 , & V_28 , V_33 ) ;
if ( F_160 ( V_194 , V_10 -> V_195 + 1 ) )
break;
if ( F_29 ( V_34 ) ) {
V_310 = - V_106 ;
break;
}
V_309 = V_10 -> V_195 ;
F_12 ( & V_10 -> V_311 ) ;
V_185 = F_161 ( 30 * V_126 ) ;
F_11 ( & V_10 -> V_311 ) ;
if ( V_185 == 0 && V_309 == V_10 -> V_195 ) {
V_310 = - V_138 ;
F_40 ( V_35 , L_49 ) ;
break;
}
}
F_32 ( & V_10 -> V_312 , & V_28 ) ;
if ( V_10 -> V_195 + 1 == V_194 )
V_10 -> V_195 ++ ;
F_12 ( & V_10 -> V_311 ) ;
return V_310 ;
}
static unsigned long F_162 ( struct V_9 * V_10 , T_8 V_313 )
{
return ( V_313 & V_314 ? V_315 : 0 ) |
( V_313 & V_316 ? V_317 : 0 ) |
( V_313 & V_318 ? V_319 : 0 ) |
( V_313 & V_320 ? V_321 : 0 ) ;
}
static int F_163 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
T_3 V_43 ;
struct V_18 * V_19 ;
struct V_293 * V_260 = & V_10 -> V_104 . V_159 . V_104 ;
int V_242 = V_291 ;
T_8 V_322 ;
if ( ! F_106 ( V_10 ) ) {
F_11 ( & V_10 -> V_311 ) ;
if ( V_10 -> V_195 + 1 == F_104 ( V_260 -> V_323 ) )
V_10 -> V_195 ++ ;
F_12 ( & V_10 -> V_311 ) ;
F_152 ( V_10 , V_287 , V_260 , V_44 ) ;
F_164 ( & V_10 -> V_229 -> V_218 ) ;
return F_136 ( V_10 , V_44 ) ;
}
V_43 = F_147 ( V_260 -> V_43 ) ;
V_19 = F_128 ( V_10 , V_260 -> V_60 , V_43 , V_44 ) ;
if ( ! V_19 ) {
F_109 ( V_10 ) ;
return false ;
}
V_19 -> V_22 . V_71 = F_153 ;
V_322 = F_104 ( V_260 -> V_322 ) ;
V_242 |= F_162 ( V_10 , V_322 ) ;
if ( V_322 & V_324 )
V_19 -> V_59 |= V_303 ;
F_11 ( & V_10 -> V_221 ) ;
V_19 -> V_55 = V_10 -> V_229 ;
F_164 ( & V_19 -> V_55 -> V_218 ) ;
F_164 ( & V_19 -> V_55 -> V_224 ) ;
F_12 ( & V_10 -> V_221 ) ;
if ( ! V_10 -> V_30 -> V_305 ) {
F_21 ( & V_10 -> V_26 ) ;
} else {
const int V_58 = V_19 -> V_58 ;
const int V_325 = F_112 ( V_173 , & V_10 -> V_59 ) ;
F_26 ( V_28 ) ;
struct V_274 * V_6 ;
struct V_326 * V_3 ;
struct V_327 * V_328 ;
int V_329 ;
F_46 ( V_10 -> V_30 -> V_299 == V_300 ) ;
F_2 ( V_10 -> V_330 == NULL ) ;
F_2 ( V_10 -> V_331 == NULL ) ;
if ( F_159 ( V_10 , F_104 ( V_260 -> V_323 ) ) )
goto V_332;
F_21 ( & V_10 -> V_26 ) ;
F_165 ( & V_19 -> V_54 , F_166 ( V_10 , V_43 ) ) ;
#define F_167 overlaps(i->sector, i->size, sector, size)
V_328 = F_168 ( V_10 , V_43 ) ;
V_329 = 1 ;
for (; ; ) {
int V_333 = 0 ;
int V_334 = 0 ;
F_28 ( & V_10 -> V_335 , & V_28 ,
V_33 ) ;
F_169 (i, n, slot, collision) {
if ( F_167 ) {
if ( V_329 )
F_170 ( V_35 , L_50
L_51 ,
V_34 -> V_336 , V_34 -> V_337 ,
( unsigned long long ) V_43 , V_58 ,
( unsigned long long ) V_6 -> V_43 , V_6 -> V_58 ) ;
if ( V_6 -> V_338 & V_339 )
++ V_333 ;
++ V_334 ;
}
}
#undef F_167
if ( ! V_334 )
break;
if ( V_329 && V_325 && V_333 ) {
F_170 ( V_35 , L_52 ,
( unsigned long long ) V_43 ) ;
F_124 ( V_10 ) ;
V_19 -> V_22 . V_71 = F_155 ;
F_171 ( & V_19 -> V_22 . V_23 , & V_10 -> V_70 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_109 ( V_10 ) ;
F_172 ( V_10 ) ;
F_32 ( & V_10 -> V_335 , & V_28 ) ;
return true ;
}
if ( F_29 ( V_34 ) ) {
F_154 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_32 ( & V_10 -> V_335 , & V_28 ) ;
goto V_332;
}
F_22 ( & V_10 -> V_26 ) ;
if ( V_329 ) {
V_329 = 0 ;
F_170 ( V_35 , L_53
L_54 , ( unsigned long long ) V_43 ) ;
} else if ( V_325 ) {
F_46 ( V_333 == 0 ) ;
}
F_31 () ;
F_21 ( & V_10 -> V_26 ) ;
}
F_32 ( & V_10 -> V_335 , & V_28 ) ;
}
F_127 ( & V_19 -> V_22 . V_23 , & V_10 -> V_262 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_10 -> V_67 . V_68 == V_340 )
F_126 ( V_10 -> V_72 , ! F_156 ( V_10 , V_19 ) ) ;
switch ( V_10 -> V_30 -> V_299 ) {
case V_300 :
F_124 ( V_10 ) ;
break;
case V_341 :
F_142 ( V_10 , V_342 , V_19 ) ;
break;
case V_343 :
break;
}
if ( V_10 -> V_67 . V_344 < V_345 ) {
F_173 ( V_10 , V_19 -> V_43 , V_19 -> V_58 ) ;
V_19 -> V_59 |= V_346 ;
V_19 -> V_59 &= ~ V_303 ;
F_174 ( V_10 , V_19 -> V_43 ) ;
}
if ( F_117 ( V_10 , V_19 , V_242 , V_347 ) == 0 )
return true ;
F_40 ( V_35 , L_46 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_115 ( & V_19 -> V_22 . V_23 ) ;
F_154 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_19 -> V_59 & V_346 )
F_175 ( V_10 , V_19 -> V_43 ) ;
V_332:
F_110 ( V_10 , V_19 -> V_55 , V_223 + V_222 ) ;
F_109 ( V_10 ) ;
F_51 ( V_10 , V_19 ) ;
return false ;
}
int F_176 ( struct V_9 * V_10 , T_3 V_43 )
{
struct V_348 * V_349 = V_10 -> V_210 -> V_211 -> V_350 -> V_351 ;
unsigned long V_352 , V_353 , V_354 ;
struct V_355 * V_4 ;
int V_356 ;
int V_357 = 0 ;
if ( V_10 -> V_197 . V_358 == 0 )
return 0 ;
F_21 ( & V_10 -> V_359 ) ;
V_4 = F_177 ( V_10 -> V_360 , F_178 ( V_43 ) ) ;
if ( V_4 ) {
struct V_361 * V_362 = F_179 ( V_4 , struct V_361 , V_363 ) ;
if ( F_112 ( V_364 , & V_362 -> V_59 ) ) {
F_22 ( & V_10 -> V_359 ) ;
return 0 ;
}
}
F_22 ( & V_10 -> V_359 ) ;
V_356 = ( int ) F_180 ( & V_349 -> V_365 , V_366 [ 0 ] ) +
( int ) F_180 ( & V_349 -> V_365 , V_366 [ 1 ] ) -
F_27 ( & V_10 -> V_290 ) ;
if ( ! V_10 -> V_367 || V_356 - V_10 -> V_367 > 64 ) {
unsigned long V_368 ;
int V_6 ;
V_10 -> V_367 = V_356 ;
V_6 = ( V_10 -> V_369 + V_370 - 1 ) % V_370 ;
if ( V_10 -> V_67 . V_68 == V_371 || V_10 -> V_67 . V_68 == V_372 )
V_368 = V_10 -> V_373 ;
else
V_368 = F_181 ( V_10 ) - V_10 -> V_374 ;
V_353 = ( ( long ) V_189 - ( long ) V_10 -> V_375 [ V_6 ] ) / V_126 ;
if ( ! V_353 )
V_353 ++ ;
V_352 = V_10 -> V_376 [ V_6 ] - V_368 ;
V_354 = F_182 ( V_352 / V_353 ) ;
if ( V_354 > V_10 -> V_197 . V_358 )
V_357 = 1 ;
}
return V_357 ;
}
static int F_183 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_377 )
{
T_3 V_43 ;
const T_3 V_263 = F_129 ( V_10 -> V_264 ) ;
struct V_18 * V_19 ;
struct V_378 * V_379 = NULL ;
int V_58 , V_380 ;
unsigned int V_243 ;
struct V_381 * V_260 = & V_10 -> V_104 . V_159 . V_382 ;
V_43 = F_147 ( V_260 -> V_43 ) ;
V_58 = F_104 ( V_260 -> V_383 ) ;
if ( V_58 <= 0 || ( V_58 & 0x1ff ) != 0 || V_58 > V_39 ) {
F_40 ( V_35 , L_55 , __FILE__ , __LINE__ ,
( unsigned long long ) V_43 , V_58 ) ;
return false ;
}
if ( V_43 + ( V_58 >> 9 ) > V_263 ) {
F_40 ( V_35 , L_55 , __FILE__ , __LINE__ ,
( unsigned long long ) V_43 , V_58 ) ;
return false ;
}
if ( ! F_184 ( V_10 , V_384 ) ) {
V_380 = 1 ;
switch ( V_153 ) {
case V_385 :
F_185 ( V_10 , V_386 , V_260 ) ;
break;
case V_387 :
case V_388 :
case V_389 :
F_185 ( V_10 , V_390 , V_260 ) ;
break;
case V_391 :
V_380 = 0 ;
F_145 ( V_10 ) ;
F_186 ( V_10 , V_392 , V_43 , V_58 , V_393 ) ;
break;
default:
F_40 ( V_35 , L_56 ,
F_187 ( V_153 ) ) ;
}
if ( V_380 && F_151 ( & V_295 ) )
F_40 ( V_35 , L_57
L_58 ) ;
return F_136 ( V_10 , V_377 ) ;
}
V_19 = F_37 ( V_10 , V_260 -> V_60 , V_43 , V_58 , V_181 ) ;
if ( ! V_19 ) {
F_109 ( V_10 ) ;
return false ;
}
switch ( V_153 ) {
case V_385 :
V_19 -> V_22 . V_71 = V_394 ;
V_243 = V_395 ;
goto V_396;
case V_387 :
V_19 -> V_22 . V_71 = V_397 ;
V_243 = V_398 ;
V_10 -> V_399 = F_188 ( V_43 ) ;
break;
case V_391 :
case V_388 :
V_243 = V_398 ;
V_379 = F_125 ( sizeof( * V_379 ) + V_377 , V_181 ) ;
if ( ! V_379 )
goto V_400;
V_379 -> V_377 = V_377 ;
V_379 -> V_62 = ( ( ( char * ) V_379 ) + sizeof( struct V_378 ) ) ;
V_19 -> V_62 = V_379 ;
V_19 -> V_59 |= V_61 ;
if ( F_64 ( V_10 , V_379 -> V_62 , V_377 ) != V_377 )
goto V_400;
if ( V_153 == V_388 ) {
F_46 ( V_10 -> V_270 >= 89 ) ;
V_19 -> V_22 . V_71 = V_401 ;
V_10 -> V_399 = F_188 ( V_43 ) ;
} else if ( V_153 == V_391 ) {
F_33 ( V_58 >> 9 , & V_10 -> V_296 ) ;
V_19 -> V_22 . V_71 = V_402 ;
F_145 ( V_10 ) ;
goto V_403;
}
break;
case V_389 :
if ( V_10 -> V_404 == ~ ( T_3 ) 0 &&
V_10 -> V_270 >= 90 ) {
unsigned long V_405 = V_189 ;
int V_6 ;
V_10 -> V_404 = V_43 ;
V_10 -> V_406 = V_43 ;
V_10 -> V_373 = F_189 ( V_10 ) - F_188 ( V_43 ) ;
V_10 -> V_407 = V_10 -> V_373 ;
for ( V_6 = 0 ; V_6 < V_370 ; V_6 ++ ) {
V_10 -> V_376 [ V_6 ] = V_10 -> V_373 ;
V_10 -> V_375 [ V_6 ] = V_405 ;
}
F_65 ( V_35 , L_59 ,
( unsigned long long ) V_43 ) ;
}
V_19 -> V_22 . V_71 = V_408 ;
V_243 = V_398 ;
break;
default:
F_40 ( V_35 , L_56 ,
F_187 ( V_153 ) ) ;
V_243 = V_409 ;
goto V_400;
}
if ( V_10 -> V_67 . V_410 != V_411 && F_176 ( V_10 , V_43 ) )
F_190 ( V_126 / 10 ) ;
if ( F_191 ( V_10 , V_43 ) )
goto V_400;
V_403:
F_33 ( V_58 >> 9 , & V_10 -> V_290 ) ;
V_396:
F_124 ( V_10 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_171 ( & V_19 -> V_22 . V_23 , & V_10 -> V_412 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( F_117 ( V_10 , V_19 , V_413 , V_243 ) == 0 )
return true ;
F_40 ( V_35 , L_46 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_115 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 ) ;
V_400:
F_109 ( V_10 ) ;
F_51 ( V_10 , V_19 ) ;
return false ;
}
static int F_192 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_414 , V_410 , V_102 = - 100 ;
unsigned long V_415 , V_416 ;
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_419 ] & 1 ;
V_410 = V_10 -> V_420 [ V_419 ] & 1 ;
V_416 = V_10 -> V_420 [ V_421 ] ;
V_415 = V_10 -> V_422 ;
switch ( V_10 -> V_30 -> V_423 ) {
case V_424 :
case V_425 :
case V_426 :
F_40 ( V_35 , L_60 ) ;
break;
case V_427 :
break;
case V_428 :
if ( V_414 == 0 && V_410 == 1 ) {
V_102 = - 1 ;
break;
}
if ( V_414 == 1 && V_410 == 0 ) {
V_102 = 1 ;
break;
}
case V_429 :
if ( V_414 == 0 && V_410 == 1 ) {
V_102 = 1 ;
break;
}
if ( V_414 == 1 && V_410 == 0 ) {
V_102 = - 1 ;
break;
}
F_30 ( V_35 , L_61
L_62 ) ;
case V_430 :
if ( V_416 == 0 && V_415 == 0 ) {
V_102 = F_112 ( V_173 , & V_10 -> V_59 )
? - 1 : 1 ;
break;
} else {
if ( V_416 == 0 ) { V_102 = 1 ; break; }
if ( V_415 == 0 ) { V_102 = - 1 ; break; }
}
if ( V_10 -> V_30 -> V_423 == V_430 )
break;
case V_431 :
if ( V_415 < V_416 )
V_102 = - 1 ;
else if ( V_415 > V_416 )
V_102 = 1 ;
else
V_102 = F_112 ( V_173 , & V_10 -> V_59 )
? - 1 : 1 ;
break;
case V_432 :
V_102 = - 1 ;
break;
case V_433 :
V_102 = 1 ;
}
return V_102 ;
}
static int F_193 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_434 , V_102 = - 100 ;
switch ( V_10 -> V_30 -> V_435 ) {
case V_428 :
case V_429 :
case V_431 :
case V_432 :
case V_433 :
F_40 ( V_35 , L_60 ) ;
break;
case V_427 :
break;
case V_424 :
V_434 = F_192 ( V_10 ) ;
if ( V_434 == - 1 && V_10 -> V_67 . V_436 == V_437 )
V_102 = V_434 ;
if ( V_434 == 1 && V_10 -> V_67 . V_436 == V_411 )
V_102 = V_434 ;
break;
case V_438 :
V_102 = F_192 ( V_10 ) ;
break;
case V_425 :
return V_10 -> V_67 . V_436 == V_411 ? 1 : - 1 ;
case V_426 :
V_434 = F_192 ( V_10 ) ;
if ( V_434 == - 1 && V_10 -> V_67 . V_436 == V_411 ) {
enum V_170 V_439 ;
F_194 ( V_10 , V_437 , 0 ) ;
V_439 = F_195 ( V_10 , V_200 , F_67 ( V_436 , V_437 ) ) ;
if ( V_439 != V_172 ) {
F_196 ( V_10 , L_63 ) ;
} else {
F_30 ( V_35 , L_64 ) ;
V_102 = V_434 ;
}
} else
V_102 = V_434 ;
}
return V_102 ;
}
static int F_197 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_434 , V_102 = - 100 ;
switch ( V_10 -> V_30 -> V_440 ) {
case V_428 :
case V_429 :
case V_431 :
case V_432 :
case V_433 :
case V_424 :
case V_425 :
F_40 ( V_35 , L_60 ) ;
break;
case V_438 :
V_102 = F_192 ( V_10 ) ;
break;
case V_427 :
break;
case V_426 :
V_434 = F_192 ( V_10 ) ;
if ( V_434 == - 1 ) {
enum V_170 V_439 ;
V_439 = F_195 ( V_10 , V_200 , F_67 ( V_436 , V_437 ) ) ;
if ( V_439 != V_172 ) {
F_196 ( V_10 , L_63 ) ;
} else {
F_30 ( V_35 , L_64 ) ;
V_102 = V_434 ;
}
} else
V_102 = V_434 ;
}
return V_102 ;
}
static void F_198 ( struct V_9 * V_10 , char * V_441 , T_2 * V_418 ,
T_2 V_442 , T_2 V_59 )
{
if ( ! V_418 ) {
F_65 ( V_35 , L_65 , V_441 ) ;
return;
}
F_65 ( V_35 , L_66 ,
V_441 ,
( unsigned long long ) V_418 [ V_443 ] ,
( unsigned long long ) V_418 [ V_419 ] ,
( unsigned long long ) V_418 [ V_444 ] ,
( unsigned long long ) V_418 [ V_445 ] ,
( unsigned long long ) V_442 ,
( unsigned long long ) V_59 ) ;
}
static int F_199 ( struct V_9 * V_10 , int * V_446 ) __must_hold( T_5 )
{
T_2 V_414 , V_410 ;
int V_6 , V_447 ;
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_443 ] & ~ ( ( T_2 ) 1 ) ;
V_410 = V_10 -> V_420 [ V_443 ] & ~ ( ( T_2 ) 1 ) ;
* V_446 = 10 ;
if ( V_414 == V_448 && V_410 == V_448 )
return 0 ;
* V_446 = 20 ;
if ( ( V_414 == V_448 || V_414 == ( T_2 ) 0 ) &&
V_410 != V_448 )
return - 2 ;
* V_446 = 30 ;
if ( V_414 != V_448 &&
( V_410 == V_448 || V_410 == ( T_2 ) 0 ) )
return 2 ;
if ( V_414 == V_410 ) {
int V_449 , V_239 ;
if ( V_10 -> V_420 [ V_419 ] == ( T_2 ) 0 && V_10 -> V_210 -> V_417 . V_418 [ V_419 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_270 < 91 )
return - 1091 ;
if ( ( V_10 -> V_210 -> V_417 . V_418 [ V_419 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_420 [ V_444 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_210 -> V_417 . V_418 [ V_444 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_420 [ V_444 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_65 ( V_35 , L_67 ) ;
F_200 ( V_10 , 0UL ) ;
F_198 ( V_10 , L_68 , V_10 -> V_210 -> V_417 . V_418 ,
V_10 -> V_67 . V_349 >= V_450 ? F_181 ( V_10 ) : 0 , 0 ) ;
* V_446 = 34 ;
} else {
F_65 ( V_35 , L_69 ) ;
* V_446 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_210 -> V_417 . V_418 [ V_419 ] == ( T_2 ) 0 && V_10 -> V_420 [ V_419 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_270 < 91 )
return - 1091 ;
if ( ( V_10 -> V_210 -> V_417 . V_418 [ V_444 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_420 [ V_419 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_210 -> V_417 . V_418 [ V_444 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_420 [ V_444 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_65 ( V_35 , L_70 ) ;
V_10 -> V_420 [ V_444 + 1 ] = V_10 -> V_420 [ V_444 ] ;
V_10 -> V_420 [ V_444 ] = V_10 -> V_420 [ V_419 ] ;
V_10 -> V_420 [ V_419 ] = 0UL ;
F_198 ( V_10 , L_71 , V_10 -> V_420 , V_10 -> V_420 [ V_421 ] , V_10 -> V_420 [ V_451 ] ) ;
* V_446 = 35 ;
} else {
F_65 ( V_35 , L_72 ) ;
* V_446 = 37 ;
}
return - 1 ;
}
V_449 = ( F_112 ( V_452 , & V_10 -> V_59 ) ? 1 : 0 ) +
( V_10 -> V_420 [ V_451 ] & 2 ) ;
* V_446 = 40 ;
switch ( V_449 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_239 = F_112 ( V_173 , & V_10 -> V_59 ) ;
return V_239 ? - 1 : 1 ;
}
}
* V_446 = 50 ;
V_410 = V_10 -> V_420 [ V_419 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 )
return - 1 ;
* V_446 = 51 ;
V_410 = V_10 -> V_420 [ V_444 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 ) {
if ( V_10 -> V_270 < 96 ?
( V_10 -> V_210 -> V_417 . V_418 [ V_444 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_420 [ V_444 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_410 + V_453 == ( V_10 -> V_420 [ V_419 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_270 < 91 )
return - 1091 ;
V_10 -> V_420 [ V_419 ] = V_10 -> V_420 [ V_444 ] ;
V_10 -> V_420 [ V_444 ] = V_10 -> V_420 [ V_444 + 1 ] ;
F_65 ( V_35 , L_73 ) ;
F_198 ( V_10 , L_71 , V_10 -> V_420 , V_10 -> V_420 [ V_421 ] , V_10 -> V_420 [ V_451 ] ) ;
return - 1 ;
}
}
* V_446 = 60 ;
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_443 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_444 ; V_6 <= V_445 ; V_6 ++ ) {
V_410 = V_10 -> V_420 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 )
return - 2 ;
}
* V_446 = 70 ;
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_419 ] & ~ ( ( T_2 ) 1 ) ;
V_410 = V_10 -> V_420 [ V_443 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 )
return 1 ;
* V_446 = 71 ;
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_444 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 ) {
if ( V_10 -> V_270 < 96 ?
( V_10 -> V_210 -> V_417 . V_418 [ V_444 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_420 [ V_444 ] & ~ ( ( T_2 ) 1 ) ) :
V_414 + V_453 == ( V_10 -> V_210 -> V_417 . V_418 [ V_419 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_270 < 91 )
return - 1091 ;
F_201 ( V_10 , V_419 , V_10 -> V_210 -> V_417 . V_418 [ V_444 ] ) ;
F_201 ( V_10 , V_444 , V_10 -> V_210 -> V_417 . V_418 [ V_444 + 1 ] ) ;
F_65 ( V_35 , L_74 ) ;
F_198 ( V_10 , L_68 , V_10 -> V_210 -> V_417 . V_418 ,
V_10 -> V_67 . V_349 >= V_450 ? F_181 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_446 = 80 ;
V_410 = V_10 -> V_420 [ V_443 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_444 ; V_6 <= V_445 ; V_6 ++ ) {
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 )
return 2 ;
}
* V_446 = 90 ;
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_419 ] & ~ ( ( T_2 ) 1 ) ;
V_410 = V_10 -> V_420 [ V_419 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 && V_414 != ( ( T_2 ) 0 ) )
return 100 ;
* V_446 = 100 ;
for ( V_6 = V_444 ; V_6 <= V_445 ; V_6 ++ ) {
V_414 = V_10 -> V_210 -> V_417 . V_418 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_447 = V_444 ; V_447 <= V_445 ; V_447 ++ ) {
V_410 = V_10 -> V_420 [ V_447 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_414 == V_410 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_454 F_202 ( struct V_9 * V_10 , enum V_455 V_456 ,
enum V_457 V_458 ) __must_hold( T_5 )
{
int V_434 , V_446 ;
enum V_454 V_102 = V_459 ;
enum V_457 V_460 ;
V_460 = V_10 -> V_67 . V_349 ;
if ( V_460 == V_450 )
V_460 = V_10 -> V_461 . V_349 ;
F_65 ( V_35 , L_75 ) ;
F_198 ( V_10 , L_68 , V_10 -> V_210 -> V_417 . V_418 , V_10 -> V_422 , 0 ) ;
F_198 ( V_10 , L_71 , V_10 -> V_420 ,
V_10 -> V_420 [ V_421 ] , V_10 -> V_420 [ V_451 ] ) ;
V_434 = F_199 ( V_10 , & V_446 ) ;
F_65 ( V_35 , L_76 , V_434 , V_446 ) ;
if ( V_434 == - 1000 ) {
F_170 ( V_35 , L_77 ) ;
return V_459 ;
}
if ( V_434 < - 1000 ) {
F_170 ( V_35 , L_78 , - V_434 - 1000 ) ;
return V_459 ;
}
if ( ( V_460 == V_345 && V_458 > V_345 ) ||
( V_458 == V_345 && V_460 > V_345 ) ) {
int V_462 = ( V_434 == - 100 ) || abs ( V_434 ) == 2 ;
V_434 = V_460 > V_345 ? 1 : - 1 ;
if ( V_462 )
V_434 = V_434 * 2 ;
F_65 ( V_35 , L_79 ,
V_434 > 0 ? L_80 : L_81 ) ;
}
if ( abs ( V_434 ) == 100 )
F_196 ( V_10 , L_82 ) ;
if ( V_434 == 100 || ( V_434 == - 100 && V_10 -> V_30 -> V_463 ) ) {
int V_464 = ( V_10 -> V_67 . V_436 == V_411 )
+ ( V_456 == V_411 ) ;
int V_465 = ( V_434 == - 100 ) ;
switch ( V_464 ) {
case 0 :
V_434 = F_192 ( V_10 ) ;
break;
case 1 :
V_434 = F_193 ( V_10 ) ;
break;
case 2 :
V_434 = F_197 ( V_10 ) ;
break;
}
if ( abs ( V_434 ) < 100 ) {
F_30 ( V_35 , L_83
L_84 ,
V_464 , ( V_434 < 0 ) ? L_71 : L_85 ) ;
if ( V_465 ) {
F_30 ( V_35 , L_86
L_87 ) ;
V_434 = V_434 * 2 ;
}
}
}
if ( V_434 == - 100 ) {
if ( V_10 -> V_30 -> V_466 && ! ( V_10 -> V_420 [ V_451 ] & 1 ) )
V_434 = - 1 ;
if ( ! V_10 -> V_30 -> V_466 && ( V_10 -> V_420 [ V_451 ] & 1 ) )
V_434 = 1 ;
if ( abs ( V_434 ) < 100 )
F_30 ( V_35 , L_88
L_89 ,
( V_434 < 0 ) ? L_71 : L_85 ) ;
}
if ( V_434 == - 100 ) {
F_170 ( V_35 , L_90 ) ;
F_196 ( V_10 , L_91 ) ;
return V_459 ;
}
if ( V_434 > 0 && V_460 <= V_345 ) {
F_40 ( V_35 , L_92 ) ;
return V_459 ;
}
if ( V_434 < 0 &&
V_10 -> V_67 . V_436 == V_411 && V_10 -> V_67 . V_349 >= V_467 ) {
switch ( V_10 -> V_30 -> V_468 ) {
case V_426 :
F_196 ( V_10 , L_93 ) ;
case V_427 :
F_40 ( V_35 , L_94 ) ;
return V_459 ;
case V_438 :
F_30 ( V_35 , L_95
L_96 ) ;
}
}
if ( V_10 -> V_30 -> V_469 || F_112 ( V_470 , & V_10 -> V_59 ) ) {
if ( V_434 == 0 )
F_65 ( V_35 , L_97 ) ;
else
F_65 ( V_35 , L_98 ,
F_203 ( V_434 > 0 ? V_301 : V_340 ) ,
abs ( V_434 ) >= 2 ? L_99 : L_100 ) ;
return V_459 ;
}
if ( abs ( V_434 ) >= 2 ) {
F_65 ( V_35 , L_101 ) ;
if ( F_204 ( V_10 , & V_471 , L_102 ,
V_472 ) )
return V_459 ;
}
if ( V_434 > 0 ) {
V_102 = V_473 ;
} else if ( V_434 < 0 ) {
V_102 = V_474 ;
} else {
V_102 = V_475 ;
if ( F_181 ( V_10 ) ) {
F_65 ( V_35 , L_103 ,
F_181 ( V_10 ) ) ;
}
}
return V_102 ;
}
static int F_205 ( enum V_476 V_410 , enum V_476 V_414 )
{
if ( ( V_410 == V_433 && V_414 == V_432 ) ||
( V_414 == V_433 && V_410 == V_432 ) )
return 0 ;
if ( V_410 == V_433 || V_410 == V_432 ||
V_414 == V_433 || V_414 == V_432 )
return 1 ;
if ( V_410 == V_414 )
return 0 ;
return 1 ;
}
static int F_206 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_477 * V_260 = & V_10 -> V_104 . V_159 . V_478 ;
int V_479 , V_480 , V_481 , V_482 ;
int V_483 , V_484 , V_485 ;
char V_486 [ V_487 ] = L_104 ;
V_479 = F_104 ( V_260 -> V_478 ) ;
V_480 = F_104 ( V_260 -> V_423 ) ;
V_481 = F_104 ( V_260 -> V_435 ) ;
V_482 = F_104 ( V_260 -> V_440 ) ;
V_484 = F_104 ( V_260 -> V_305 ) ;
V_485 = F_104 ( V_260 -> V_488 ) ;
V_483 = V_485 & V_489 ;
F_83 ( V_470 , & V_10 -> V_59 ) ;
if ( V_485 & V_490 )
F_85 ( V_470 , & V_10 -> V_59 ) ;
if ( V_479 != V_10 -> V_30 -> V_299 ) {
F_40 ( V_35 , L_105 ) ;
goto V_491;
}
if ( F_205 ( V_480 , V_10 -> V_30 -> V_423 ) ) {
F_40 ( V_35 , L_106 ) ;
goto V_491;
}
if ( F_205 ( V_481 , V_10 -> V_30 -> V_435 ) ) {
F_40 ( V_35 , L_107 ) ;
goto V_491;
}
if ( F_205 ( V_482 , V_10 -> V_30 -> V_440 ) ) {
F_40 ( V_35 , L_108 ) ;
goto V_491;
}
if ( V_483 && V_10 -> V_30 -> V_466 ) {
F_40 ( V_35 , L_109 ) ;
goto V_491;
}
if ( V_484 != V_10 -> V_30 -> V_305 ) {
F_40 ( V_35 , L_110 ) ;
goto V_491;
}
if ( V_10 -> V_270 >= 87 ) {
unsigned char * V_492 = V_10 -> V_30 -> V_493 ;
if ( F_64 ( V_10 , V_486 , V_44 ) != V_44 )
return false ;
V_486 [ V_487 - 1 ] = 0 ;
if ( strcmp ( V_486 , V_492 ) ) {
F_40 ( V_35 , L_111 ) ;
goto V_491;
}
F_65 ( V_35 , L_112 ,
V_492 [ 0 ] ? V_492 : ( unsigned char * ) L_113 ) ;
}
return true ;
V_491:
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
return false ;
}
struct V_494 * F_207 ( const struct V_9 * V_10 ,
const char * V_495 , const char * V_496 )
{
struct V_494 * V_497 ;
if ( ! V_495 [ 0 ] )
return NULL ;
V_497 = F_208 ( V_495 , 0 , V_498 ) ;
if ( F_209 ( V_497 ) ) {
F_40 ( V_35 , L_114 ,
V_495 , V_496 , F_210 ( V_497 ) ) ;
return V_497 ;
}
if ( ! F_211 ( F_212 ( V_497 ) ) ) {
F_213 ( V_497 ) ;
F_40 ( V_35 , L_115 , V_495 , V_496 ) ;
return F_214 ( - V_499 ) ;
}
return V_497 ;
}
static int F_215 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_202 )
{
int V_66 = true ;
struct V_500 * V_260 = & V_10 -> V_104 . V_159 . V_501 ;
unsigned int V_502 , V_44 , V_503 ;
struct V_494 * V_504 = NULL ;
struct V_494 * V_505 = NULL ;
const int V_506 = V_10 -> V_270 ;
int * V_507 = NULL ;
int V_508 = 0 ;
V_503 = V_506 <= 87 ? sizeof( struct V_509 )
: V_506 == 88 ? sizeof( struct V_509 )
+ V_487
: V_506 <= 94 ? sizeof( struct V_510 )
: sizeof( struct V_500 ) ;
if ( V_202 > V_503 ) {
F_40 ( V_35 , L_116 ,
V_202 , V_503 ) ;
return false ;
}
if ( V_506 <= 88 ) {
V_502 = sizeof( struct V_509 ) - sizeof( struct V_154 ) ;
V_44 = V_202 - V_502 ;
} else if ( V_506 <= 94 ) {
V_502 = sizeof( struct V_510 ) - sizeof( struct V_154 ) ;
V_44 = V_202 - V_502 ;
F_46 ( V_44 == 0 ) ;
} else {
V_502 = sizeof( struct V_500 ) - sizeof( struct V_154 ) ;
V_44 = V_202 - V_502 ;
F_46 ( V_44 == 0 ) ;
}
memset ( V_260 -> V_511 , 0 , 2 * V_487 ) ;
if ( F_64 ( V_10 , & V_260 -> V_2 . V_512 , V_502 ) != V_502 )
return false ;
V_10 -> V_197 . V_513 = F_104 ( V_260 -> V_513 ) ;
if ( V_506 >= 88 ) {
if ( V_506 == 88 ) {
if ( V_44 > V_487 || V_44 == 0 ) {
F_40 ( V_35 , L_117
L_118 ,
V_44 , V_487 ) ;
return false ;
}
if ( F_64 ( V_10 , V_260 -> V_511 , V_44 ) != V_44 )
return false ;
F_46 ( V_260 -> V_511 [ V_44 - 1 ] == 0 ) ;
V_260 -> V_511 [ V_44 - 1 ] = 0 ;
} else {
F_46 ( V_260 -> V_511 [ V_487 - 1 ] == 0 ) ;
F_46 ( V_260 -> V_514 [ V_487 - 1 ] == 0 ) ;
V_260 -> V_511 [ V_487 - 1 ] = 0 ;
V_260 -> V_514 [ V_487 - 1 ] = 0 ;
}
if ( strcmp ( V_10 -> V_197 . V_511 , V_260 -> V_511 ) ) {
if ( V_10 -> V_67 . V_68 == V_69 ) {
F_40 ( V_35 , L_119 ,
V_10 -> V_197 . V_511 , V_260 -> V_511 ) ;
goto V_491;
}
V_504 = F_207 ( V_10 ,
V_260 -> V_511 , L_120 ) ;
if ( F_209 ( V_504 ) ) {
V_504 = NULL ;
goto V_491;
}
}
if ( V_506 >= 89 && strcmp ( V_10 -> V_197 . V_514 , V_260 -> V_514 ) ) {
if ( V_10 -> V_67 . V_68 == V_69 ) {
F_40 ( V_35 , L_121 ,
V_10 -> V_197 . V_514 , V_260 -> V_514 ) ;
goto V_491;
}
V_505 = F_207 ( V_10 ,
V_260 -> V_514 , L_122 ) ;
if ( F_209 ( V_505 ) ) {
V_505 = NULL ;
goto V_491;
}
}
if ( V_506 > 94 ) {
V_10 -> V_197 . V_513 = F_104 ( V_260 -> V_513 ) ;
V_10 -> V_197 . V_515 = F_104 ( V_260 -> V_515 ) ;
V_10 -> V_197 . V_516 = F_104 ( V_260 -> V_516 ) ;
V_10 -> V_197 . V_517 = F_104 ( V_260 -> V_517 ) ;
V_10 -> V_197 . V_518 = F_104 ( V_260 -> V_518 ) ;
V_508 = ( V_10 -> V_197 . V_515 * 10 * V_519 ) / V_126 ;
if ( V_508 != V_10 -> V_507 . V_58 && V_508 > 0 ) {
V_507 = F_216 ( sizeof( int ) * V_508 , V_212 ) ;
if ( ! V_507 ) {
F_40 ( V_35 , L_123 ) ;
goto V_491;
}
}
}
F_11 ( & V_10 -> V_311 ) ;
if ( V_504 ) {
strcpy ( V_10 -> V_197 . V_511 , V_260 -> V_511 ) ;
V_10 -> V_197 . V_520 = strlen ( V_260 -> V_511 ) + 1 ;
F_213 ( V_10 -> V_504 ) ;
V_10 -> V_504 = V_504 ;
F_65 ( V_35 , L_124 , V_260 -> V_511 ) ;
}
if ( V_505 ) {
strcpy ( V_10 -> V_197 . V_514 , V_260 -> V_514 ) ;
V_10 -> V_197 . V_521 = strlen ( V_260 -> V_514 ) + 1 ;
F_213 ( V_10 -> V_505 ) ;
V_10 -> V_505 = V_505 ;
F_65 ( V_35 , L_125 , V_260 -> V_514 ) ;
}
if ( V_508 != V_10 -> V_507 . V_58 ) {
F_45 ( V_10 -> V_507 . V_522 ) ;
V_10 -> V_507 . V_522 = V_507 ;
V_10 -> V_507 . V_58 = V_508 ;
V_10 -> V_523 = 0 ;
}
F_12 ( & V_10 -> V_311 ) ;
}
return V_66 ;
V_491:
F_213 ( V_505 ) ;
F_213 ( V_504 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
return false ;
}
static void F_217 ( struct V_9 * V_10 ,
const char * V_167 , T_3 V_37 , T_3 V_524 )
{
T_3 V_525 ;
if ( V_37 == 0 || V_524 == 0 )
return;
V_525 = ( V_37 > V_524 ) ? ( V_37 - V_524 ) : ( V_524 - V_37 ) ;
if ( V_525 > ( V_37 >> 3 ) || V_525 > ( V_524 >> 3 ) )
F_30 ( V_35 , L_126 , V_167 ,
( unsigned long long ) V_37 , ( unsigned long long ) V_524 ) ;
}
static int F_218 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_526 * V_260 = & V_10 -> V_104 . V_159 . V_527 ;
enum V_528 V_529 = V_530 ;
T_3 V_531 , V_532 , V_533 ;
int V_534 = 0 ;
enum V_535 V_536 ;
V_531 = F_147 ( V_260 -> V_537 ) ;
V_532 = F_147 ( V_260 -> V_538 ) ;
if ( V_531 == 0 && V_10 -> V_67 . V_349 == V_539 ) {
F_40 ( V_35 , L_127 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
return false ;
}
V_10 -> V_531 = V_531 ;
if ( F_106 ( V_10 ) ) {
F_217 ( V_10 , L_128 ,
V_531 , F_219 ( V_10 -> V_210 ) ) ;
F_217 ( V_10 , L_129 ,
V_532 , V_10 -> V_210 -> V_239 . V_540 ) ;
if ( V_10 -> V_67 . V_68 == V_69 )
V_532 = F_220 ( ( T_3 ) V_10 -> V_210 -> V_239 . V_540 ,
V_532 ) ;
V_533 = V_10 -> V_210 -> V_239 . V_540 ;
if ( V_10 -> V_210 -> V_239 . V_540 != V_532 ) {
V_10 -> V_210 -> V_239 . V_540 = V_532 ;
F_65 ( V_35 , L_130 ,
( unsigned long ) V_10 -> V_210 -> V_239 . V_540 ) ;
}
if ( F_221 ( V_10 , V_10 -> V_210 , 0 ) <
F_129 ( V_10 -> V_264 ) &&
V_10 -> V_67 . V_349 >= V_541 &&
V_10 -> V_67 . V_68 < V_475 ) {
F_40 ( V_35 , L_131 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
V_10 -> V_210 -> V_239 . V_540 = V_533 ;
F_109 ( V_10 ) ;
return false ;
}
F_109 ( V_10 ) ;
}
V_536 = F_79 ( V_260 -> V_535 ) ;
if ( F_106 ( V_10 ) ) {
V_529 = F_222 ( V_10 , V_536 ) ;
F_109 ( V_10 ) ;
if ( V_529 == V_542 )
return false ;
F_223 ( V_10 ) ;
} else {
F_224 ( V_10 , V_531 ) ;
}
V_10 -> V_543 = F_104 ( V_260 -> V_544 ) ;
F_225 ( V_10 ) ;
if ( F_106 ( V_10 ) ) {
if ( V_10 -> V_210 -> V_545 != F_129 ( V_10 -> V_210 -> V_211 ) ) {
V_10 -> V_210 -> V_545 = F_129 ( V_10 -> V_210 -> V_211 ) ;
V_534 = 1 ;
}
F_109 ( V_10 ) ;
}
if ( V_10 -> V_67 . V_68 > V_69 ) {
if ( F_147 ( V_260 -> V_546 ) !=
F_129 ( V_10 -> V_264 ) || V_534 ) {
F_94 ( V_10 , 0 , V_536 ) ;
}
if ( F_226 ( V_199 , & V_10 -> V_59 ) ||
( V_529 == V_547 && V_10 -> V_67 . V_68 == V_475 ) ) {
if ( V_10 -> V_67 . V_344 >= V_345 &&
V_10 -> V_67 . V_349 >= V_345 ) {
if ( V_536 & V_548 )
F_65 ( V_35 , L_132 ) ;
else
F_227 ( V_10 ) ;
} else
F_85 ( V_549 , & V_10 -> V_59 ) ;
}
}
return true ;
}
static int F_228 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_550 * V_260 = & V_10 -> V_104 . V_159 . V_551 ;
T_2 * V_420 ;
int V_6 , V_552 = 0 ;
V_420 = F_125 ( sizeof( T_2 ) * V_553 , V_181 ) ;
for ( V_6 = V_443 ; V_6 < V_553 ; V_6 ++ )
V_420 [ V_6 ] = F_147 ( V_260 -> V_418 [ V_6 ] ) ;
F_45 ( V_10 -> V_420 ) ;
V_10 -> V_420 = V_420 ;
if ( V_10 -> V_67 . V_68 < V_475 &&
V_10 -> V_67 . V_349 < V_345 &&
V_10 -> V_67 . V_436 == V_411 &&
( V_10 -> V_554 & ~ ( ( T_2 ) 1 ) ) != ( V_420 [ V_443 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_40 ( V_35 , L_133 ,
( unsigned long long ) V_10 -> V_554 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
return false ;
}
if ( F_106 ( V_10 ) ) {
int V_555 =
V_10 -> V_67 . V_68 == V_475 &&
V_10 -> V_270 >= 90 &&
V_10 -> V_210 -> V_417 . V_418 [ V_443 ] == V_448 &&
( V_420 [ V_451 ] & 8 ) ;
if ( V_555 ) {
F_65 ( V_35 , L_134 ) ;
F_204 ( V_10 , & V_556 ,
L_135 ,
V_557 ) ;
F_201 ( V_10 , V_443 , V_420 [ V_443 ] ) ;
F_201 ( V_10 , V_419 , 0 ) ;
F_97 ( F_229 ( V_10 , V_349 , V_384 , V_344 , V_384 ) ,
V_200 , NULL ) ;
F_223 ( V_10 ) ;
V_552 = 1 ;
}
F_109 ( V_10 ) ;
} else if ( V_10 -> V_67 . V_349 < V_345 &&
V_10 -> V_67 . V_436 == V_411 ) {
V_552 = F_230 ( V_10 , V_420 [ V_443 ] ) ;
}
F_126 ( V_10 -> V_335 , ! F_112 ( V_558 , & V_10 -> V_59 ) ) ;
if ( V_10 -> V_67 . V_68 >= V_475 && V_10 -> V_67 . V_349 < V_345 )
V_552 |= F_230 ( V_10 , V_420 [ V_443 ] ) ;
if ( V_552 )
F_231 ( V_10 , L_136 ) ;
return true ;
}
static union V_559 F_232 ( union V_559 V_560 )
{
union V_559 V_561 ;
static enum V_454 V_562 [] = {
[ V_475 ] = V_475 ,
[ V_563 ] = V_564 ,
[ V_564 ] = V_563 ,
[ V_146 ] = V_565 ,
[ V_371 ] = V_372 ,
[ V_459 ] = V_459 ,
} ;
V_561 . V_6 = V_560 . V_6 ;
V_561 . V_68 = V_562 [ V_560 . V_68 ] ;
V_561 . V_410 = V_560 . V_436 ;
V_561 . V_436 = V_560 . V_410 ;
V_561 . V_344 = V_560 . V_349 ;
V_561 . V_349 = V_560 . V_344 ;
V_561 . V_566 = ( V_560 . V_567 | V_560 . V_568 ) ;
return V_561 ;
}
static int F_233 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_569 * V_260 = & V_10 -> V_104 . V_159 . V_570 ;
union V_559 V_571 , V_572 ;
enum V_170 V_102 ;
V_571 . V_6 = F_104 ( V_260 -> V_571 ) ;
V_572 . V_6 = F_104 ( V_260 -> V_572 ) ;
if ( F_112 ( V_173 , & V_10 -> V_59 ) &&
F_112 ( V_558 , & V_10 -> V_59 ) ) {
F_234 ( V_10 , V_573 ) ;
return true ;
}
V_571 = F_232 ( V_571 ) ;
V_572 = F_232 ( V_572 ) ;
V_102 = F_195 ( V_10 , V_200 , V_571 , V_572 ) ;
F_234 ( V_10 , V_102 ) ;
F_223 ( V_10 ) ;
return true ;
}
static int F_235 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_574 * V_260 = & V_10 -> V_104 . V_159 . V_67 ;
union V_559 V_575 , V_576 , V_577 ;
enum V_457 V_578 ;
enum V_579 V_580 ;
int V_102 ;
V_577 . V_6 = F_104 ( V_260 -> V_67 ) ;
V_578 = V_577 . V_349 ;
if ( V_577 . V_349 == V_450 ) {
V_578 = V_10 -> V_420 [ V_451 ] & 4 ? V_345 : V_467 ;
F_65 ( V_35 , L_137 , F_236 ( V_578 ) ) ;
}
F_21 ( & V_10 -> V_26 ) ;
V_27:
V_575 = V_576 = V_10 -> V_67 ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_575 . V_68 <= V_565 )
return false ;
if ( ( V_575 . V_344 == V_345 || V_575 . V_344 == V_467 ) &&
V_578 == V_384 &&
V_575 . V_68 > V_475 && V_575 . V_349 == V_384 ) {
if ( V_577 . V_68 > V_475 &&
V_577 . V_68 < V_301 )
V_578 = V_345 ;
else if ( V_575 . V_68 >= V_301 &&
V_577 . V_68 == V_475 ) {
if ( F_181 ( V_10 ) <= V_10 -> V_374 )
F_237 ( V_10 ) ;
return true ;
}
}
if ( V_575 . V_344 == V_384 && V_578 == V_345 &&
V_575 . V_68 == V_475 && V_577 . V_68 > V_301 )
V_578 = V_384 ;
if ( V_576 . V_68 == V_69 )
V_576 . V_68 = V_475 ;
if ( V_577 . V_68 == V_581 )
V_576 . V_68 = V_582 ;
if ( V_10 -> V_420 && V_577 . V_349 >= V_450 &&
F_184 ( V_10 , V_450 ) ) {
int V_583 ;
V_583 = ( V_575 . V_68 < V_475 ) ;
V_583 |= ( V_575 . V_68 == V_475 &&
( V_577 . V_349 == V_450 ||
V_575 . V_349 == V_450 ) ) ;
V_583 |= F_112 ( V_584 , & V_10 -> V_59 ) ;
V_583 |= ( V_575 . V_68 == V_475 &&
( V_577 . V_68 >= V_563 &&
V_577 . V_68 <= V_474 ) ) ;
if ( V_583 )
V_576 . V_68 = F_202 ( V_10 , V_577 . V_436 , V_578 ) ;
F_109 ( V_10 ) ;
if ( V_576 . V_68 == V_459 ) {
V_576 . V_68 = V_475 ;
if ( V_10 -> V_67 . V_349 == V_450 ) {
F_66 ( V_10 , F_67 ( V_349 , V_585 ) ) ;
} else if ( V_577 . V_349 == V_450 ) {
F_40 ( V_35 , L_138 ) ;
V_577 . V_349 = V_539 ;
V_578 = V_539 ;
} else {
if ( F_226 ( V_470 , & V_10 -> V_59 ) )
return false ;
F_46 ( V_575 . V_68 == V_69 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
return false ;
}
}
}
F_21 ( & V_10 -> V_26 ) ;
if ( V_10 -> V_67 . V_6 != V_575 . V_6 )
goto V_27;
F_83 ( V_584 , & V_10 -> V_59 ) ;
V_576 . V_410 = V_577 . V_436 ;
V_576 . V_344 = V_578 ;
V_576 . V_566 = ( V_577 . V_567 | V_577 . V_568 ) ;
if ( ( V_576 . V_68 == V_475 || V_576 . V_68 == V_473 ) && V_576 . V_349 == V_450 )
V_576 . V_349 = V_10 -> V_461 . V_349 ;
V_580 = V_200 + ( V_575 . V_68 < V_475 && V_576 . V_68 >= V_475 ? 0 : V_586 ) ;
if ( V_576 . V_344 == V_467 && F_238 ( V_576 ) && V_576 . V_68 == V_475 && V_575 . V_68 < V_475 &&
F_112 ( V_587 , & V_10 -> V_59 ) ) {
F_22 ( & V_10 -> V_26 ) ;
F_40 ( V_35 , L_139 ) ;
F_239 ( V_10 ) ;
F_240 ( V_10 ) ;
F_83 ( V_587 , & V_10 -> V_59 ) ;
F_66 ( V_10 , F_241 ( V_68 , V_588 , V_589 , 0 ) ) ;
return false ;
}
V_102 = F_97 ( V_10 , V_576 , V_580 , NULL ) ;
V_576 = V_10 -> V_67 ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_102 < V_172 ) {
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
return false ;
}
if ( V_575 . V_68 > V_69 ) {
if ( V_576 . V_68 > V_475 && V_577 . V_68 <= V_475 &&
V_577 . V_349 != V_450 ) {
F_95 ( V_10 ) ;
F_96 ( V_10 ) ;
}
}
V_10 -> V_30 -> V_466 = 0 ;
F_223 ( V_10 ) ;
return true ;
}
static int F_242 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_590 * V_260 = & V_10 -> V_104 . V_159 . V_591 ;
F_126 ( V_10 -> V_335 ,
V_10 -> V_67 . V_68 == V_592 ||
V_10 -> V_67 . V_68 == V_582 ||
V_10 -> V_67 . V_68 < V_475 ||
V_10 -> V_67 . V_349 < V_450 ) ;
if ( F_184 ( V_10 , V_450 ) ) {
F_201 ( V_10 , V_443 , F_147 ( V_260 -> V_418 ) ) ;
F_201 ( V_10 , V_419 , 0UL ) ;
F_231 ( V_10 , L_140 ) ;
F_243 ( V_10 , V_340 ) ;
F_109 ( V_10 ) ;
} else
F_40 ( V_35 , L_141 ) ;
return true ;
}
static int
F_244 ( struct V_9 * V_10 , unsigned int V_44 ,
unsigned long * V_593 , struct V_594 * V_595 )
{
unsigned V_596 = F_72 ( T_6 , V_597 , V_595 -> V_598 - V_595 -> V_599 ) ;
unsigned V_600 = V_596 * sizeof( long ) ;
int V_79 ;
if ( V_600 != V_44 ) {
F_40 ( V_35 , L_142 , V_601 , V_600 , V_44 ) ;
return - V_602 ;
}
if ( V_600 == 0 )
return 0 ;
V_79 = F_64 ( V_10 , V_593 , V_600 ) ;
if ( V_79 != V_600 ) {
if ( V_79 >= 0 )
V_79 = - V_602 ;
return V_79 ;
}
F_245 ( V_10 , V_595 -> V_599 , V_596 , V_593 ) ;
V_595 -> V_599 += V_596 ;
V_595 -> V_603 = V_595 -> V_599 * V_604 ;
if ( V_595 -> V_603 > V_595 -> V_605 )
V_595 -> V_603 = V_595 -> V_605 ;
return 1 ;
}
static int
F_246 ( struct V_9 * V_10 ,
struct V_606 * V_260 ,
struct V_594 * V_595 )
{
struct V_607 V_608 ;
T_2 V_609 ;
T_2 V_610 ;
T_2 V_4 ;
unsigned long V_167 = V_595 -> V_603 ;
unsigned long V_19 ;
int V_5 = F_79 ( V_260 -> V_2 . V_205 ) - ( sizeof( * V_260 ) - sizeof( V_260 -> V_2 ) ) ;
int V_611 = F_247 ( V_260 ) ;
int V_612 ;
int V_442 ;
F_248 ( & V_608 , V_260 -> V_613 , V_5 , F_249 ( V_260 ) ) ;
V_442 = F_250 ( & V_608 , & V_609 , 64 ) ;
if ( V_442 < 0 )
return - V_602 ;
for ( V_612 = V_442 ; V_612 > 0 ; V_167 += V_610 , V_611 = ! V_611 ) {
V_442 = F_251 ( & V_610 , V_609 ) ;
if ( V_442 <= 0 )
return - V_602 ;
if ( V_611 ) {
V_19 = V_167 + V_610 - 1 ;
if ( V_19 >= V_595 -> V_605 ) {
F_40 ( V_35 , L_143 , V_19 ) ;
return - V_602 ;
}
F_252 ( V_10 , V_167 , V_19 ) ;
}
if ( V_612 < V_442 ) {
F_40 ( V_35 , L_144 ,
V_612 , V_442 , V_609 ,
( unsigned int ) ( V_608 . V_614 . V_524 - V_260 -> V_613 ) ,
( unsigned int ) V_608 . V_615 ) ;
return - V_602 ;
}
V_609 >>= V_442 ;
V_612 -= V_442 ;
V_442 = F_250 ( & V_608 , & V_4 , 64 - V_612 ) ;
if ( V_442 < 0 )
return - V_602 ;
V_609 |= V_4 << V_612 ;
V_612 += V_442 ;
}
V_595 -> V_603 = V_167 ;
F_253 ( V_595 ) ;
return ( V_167 != V_595 -> V_605 ) ;
}
static int
F_254 ( struct V_9 * V_10 ,
struct V_606 * V_260 ,
struct V_594 * V_595 )
{
if ( F_255 ( V_260 ) == V_616 )
return F_246 ( V_10 , V_260 , V_595 ) ;
F_40 ( V_35 , L_145 , V_260 -> V_617 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_588 ) ) ;
return - V_602 ;
}
void F_256 ( struct V_9 * V_10 ,
const char * V_618 , struct V_594 * V_595 )
{
unsigned V_619 = sizeof( struct V_154 ) *
( ( V_595 -> V_598 + V_597 - 1 ) / V_597 + 1 )
+ V_595 -> V_598 * sizeof( long ) ;
unsigned V_620 = V_595 -> V_621 [ 0 ] + V_595 -> V_621 [ 1 ] ;
unsigned V_204 ;
if ( V_620 == 0 )
return;
if ( V_620 >= V_619 )
return;
V_204 = ( V_620 > V_622 / 1000 ) ? ( V_620 / ( V_619 / 1000 ) )
: ( 1000 * V_620 / V_619 ) ;
if ( V_204 > 1000 )
V_204 = 1000 ;
V_204 = 1000 - V_204 ;
F_65 ( V_35 , L_146
L_147 ,
V_618 ,
V_595 -> V_621 [ 1 ] , V_595 -> V_623 [ 1 ] ,
V_595 -> V_621 [ 0 ] , V_595 -> V_623 [ 0 ] ,
V_620 , V_204 / 10 , V_204 % 10 ) ;
}
static int F_257 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_594 V_595 ;
void * V_593 ;
int V_79 ;
int V_66 = false ;
struct V_154 * V_155 = & V_10 -> V_104 . V_159 . V_157 . V_158 ;
F_258 ( V_10 , L_148 , V_472 ) ;
V_593 = ( unsigned long * ) F_259 ( V_181 ) ;
if ( ! V_593 ) {
F_40 ( V_35 , L_149 , V_601 ) ;
goto V_82;
}
V_595 = (struct V_594 ) {
. V_605 = F_189 ( V_10 ) ,
. V_598 = F_260 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_153 == V_624 ) {
V_79 = F_244 ( V_10 , V_44 , V_593 , & V_595 ) ;
} else if ( V_153 == V_625 ) {
struct V_606 * V_260 ;
if ( V_44 > V_626 ) {
F_40 ( V_35 , L_150 ) ;
goto V_82;
}
V_260 = V_593 ;
memcpy ( V_260 , V_155 , sizeof( * V_155 ) ) ;
if ( F_64 ( V_10 , V_260 -> V_2 . V_512 , V_44 ) != V_44 )
goto V_82;
if ( V_44 <= ( sizeof( * V_260 ) - sizeof( V_260 -> V_2 ) ) ) {
F_40 ( V_35 , L_151 , V_44 ) ;
goto V_82;
}
V_79 = F_254 ( V_10 , V_260 , & V_595 ) ;
} else {
F_30 ( V_35 , L_152 , V_153 ) ;
goto V_82;
}
V_595 . V_623 [ V_153 == V_624 ] ++ ;
V_595 . V_621 [ V_153 == V_624 ] += sizeof( struct V_154 ) + V_44 ;
if ( V_79 <= 0 ) {
if ( V_79 < 0 )
goto V_82;
break;
}
if ( ! F_101 ( V_10 , & V_153 , & V_44 ) )
goto V_82;
}
F_256 ( V_10 , L_153 , & V_595 ) ;
if ( V_10 -> V_67 . V_68 == V_474 ) {
enum V_170 V_102 ;
V_66 = ! F_261 ( V_10 ) ;
if ( ! V_66 )
goto V_82;
V_102 = F_262 ( V_10 , F_67 ( V_68 , V_592 ) , V_200 ) ;
F_46 ( V_102 == V_172 ) ;
} else if ( V_10 -> V_67 . V_68 != V_473 ) {
F_65 ( V_35 , L_154 ,
F_203 ( V_10 -> V_67 . V_68 ) ) ;
}
V_66 = true ;
V_82:
F_263 ( V_10 ) ;
if ( V_66 && V_10 -> V_67 . V_68 == V_473 )
F_243 ( V_10 , V_301 ) ;
F_264 ( ( unsigned long ) V_593 ) ;
return V_66 ;
}
static int F_265 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
static char V_627 [ 128 ] ;
int V_58 , V_600 , V_204 ;
F_30 ( V_35 , L_155 ,
V_153 , V_44 ) ;
V_58 = V_44 ;
while ( V_58 > 0 ) {
V_600 = F_72 ( int , V_58 , sizeof( V_627 ) ) ;
V_204 = F_64 ( V_10 , V_627 , V_600 ) ;
F_131 (r <= 0 ) break;
V_58 -= V_204 ;
}
return V_58 == 0 ;
}
static int F_266 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
F_267 ( V_10 -> V_104 . V_75 ) ;
return true ;
}
static int F_268 ( struct V_9 * V_10 , enum V_152 V_153 , unsigned int V_44 )
{
struct V_628 * V_260 = & V_10 -> V_104 . V_159 . V_629 ;
switch ( V_10 -> V_67 . V_68 ) {
case V_592 :
case V_474 :
case V_582 :
break;
default:
F_40 ( V_35 , L_156 ,
F_203 ( V_10 -> V_67 . V_68 ) ) ;
}
F_173 ( V_10 , F_147 ( V_260 -> V_43 ) , F_104 ( V_260 -> V_383 ) ) ;
return true ;
}
static void F_269 ( struct V_9 * V_10 )
{
union V_203 * V_157 = & V_10 -> V_104 . V_159 . V_157 ;
unsigned int V_202 ;
enum V_152 V_153 ;
T_6 V_630 ;
int V_102 ;
while ( F_88 ( & V_10 -> V_178 ) == V_631 ) {
F_270 ( V_10 ) ;
if ( ! F_101 ( V_10 , & V_153 , & V_202 ) )
goto V_632;
if ( F_102 ( V_153 >= V_633 || ! V_634 [ V_153 ] . V_635 ) ) {
F_40 ( V_35 , L_157 , V_153 , V_202 ) ;
goto V_632;
}
V_630 = V_634 [ V_153 ] . V_636 - sizeof( union V_203 ) ;
if ( V_202 - V_630 > 0 && ! V_634 [ V_153 ] . V_637 ) {
F_40 ( V_35 , L_158 , F_187 ( V_153 ) , V_202 ) ;
goto V_632;
}
if ( V_630 ) {
V_102 = F_64 ( V_10 , & V_157 -> V_158 . V_512 , V_630 ) ;
if ( F_102 ( V_102 != V_630 ) ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_159 , V_102 ) ;
goto V_632;
}
}
V_102 = V_634 [ V_153 ] . V_635 ( V_10 , V_153 , V_202 - V_630 ) ;
if ( F_102 ( ! V_102 ) ) {
F_40 ( V_35 , L_160 ,
F_187 ( V_153 ) , V_202 ) ;
goto V_632;
}
}
if ( 0 ) {
V_632:
F_66 ( V_10 , F_67 ( V_68 , V_588 ) ) ;
}
F_223 ( V_10 ) ;
}
void F_271 ( struct V_9 * V_10 )
{
struct V_638 V_639 ;
V_639 . V_22 . V_71 = V_640 ;
F_272 ( & V_639 . V_641 ) ;
F_273 ( & V_10 -> V_104 . V_642 , & V_639 . V_22 ) ;
F_274 ( & V_639 . V_641 ) ;
}
void F_275 ( struct V_9 * V_10 )
{
struct V_327 * V_155 ;
F_21 ( & V_10 -> V_26 ) ;
if ( ! V_10 -> V_331 || V_10 -> V_67 . V_68 != V_643 ) {
F_22 ( & V_10 -> V_26 ) ;
return;
}
for ( V_155 = V_10 -> V_330 ; V_155 < V_10 -> V_330 + V_10 -> V_644 ; V_155 ++ )
if ( V_155 -> V_329 )
F_40 ( V_35 , L_161 ,
( int ) ( V_155 - V_10 -> V_330 ) , V_155 -> V_329 ) ;
F_45 ( V_10 -> V_330 ) ;
V_10 -> V_330 = NULL ;
V_10 -> V_644 = 0 ;
for ( V_155 = V_10 -> V_331 ; V_155 < V_10 -> V_331 + V_10 -> V_645 ; V_155 ++ )
if ( V_155 -> V_329 )
F_40 ( V_35 , L_162 ,
( int ) ( V_155 - V_10 -> V_331 ) , V_155 -> V_329 ) ;
F_45 ( V_10 -> V_331 ) ;
V_10 -> V_331 = NULL ;
V_10 -> V_645 = 0 ;
F_22 ( & V_10 -> V_26 ) ;
}
static void F_276 ( struct V_9 * V_10 )
{
enum V_646 V_647 ;
union V_559 V_575 , V_576 ;
int V_102 = V_648 ;
unsigned int V_6 ;
if ( V_10 -> V_67 . V_68 == V_643 )
return;
F_66 ( V_10 , F_67 ( V_68 , V_649 ) ) ;
F_277 ( & V_10 -> V_190 ) ;
F_278 ( V_10 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_52 ( V_10 , & V_10 -> V_262 ) ;
F_52 ( V_10 , & V_10 -> V_289 ) ;
F_52 ( V_10 , & V_10 -> V_412 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_279 ( V_10 ) ;
V_10 -> V_407 = 0 ;
V_10 -> V_374 = 0 ;
F_42 ( & V_10 -> V_650 , 0 ) ;
F_36 ( & V_10 -> V_335 ) ;
F_280 ( & V_10 -> V_651 ) ;
F_281 ( ( unsigned long ) V_10 ) ;
F_271 ( V_10 ) ;
F_50 ( V_10 ) ;
F_45 ( V_10 -> V_420 ) ;
V_10 -> V_420 = NULL ;
if ( ! F_238 ( V_10 -> V_67 ) )
F_239 ( V_10 ) ;
F_65 ( V_35 , L_163 ) ;
F_223 ( V_10 ) ;
V_647 = V_652 ;
if ( F_106 ( V_10 ) ) {
V_647 = V_10 -> V_210 -> V_239 . V_653 ;
F_109 ( V_10 ) ;
}
if ( V_10 -> V_67 . V_436 == V_411 && V_647 >= V_654 && V_10 -> V_67 . V_344 >= V_655 )
F_282 ( V_10 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_575 = V_10 -> V_67 ;
if ( V_575 . V_68 >= V_656 ) {
V_576 = V_575 ;
V_576 . V_68 = V_656 ;
V_102 = F_97 ( V_10 , V_576 , V_200 , NULL ) ;
}
F_22 ( & V_10 -> V_26 ) ;
if ( V_575 . V_68 == V_146 ) {
F_126 ( V_10 -> V_657 , F_27 ( & V_10 -> V_658 ) == 0 ) ;
F_213 ( V_10 -> V_192 ) ;
V_10 -> V_192 = NULL ;
F_45 ( V_10 -> V_30 ) ;
V_10 -> V_30 = NULL ;
F_82 ( V_10 , F_67 ( V_68 , V_643 ) ) ;
}
F_126 ( V_10 -> V_335 , ! F_112 ( V_659 , & V_10 -> V_59 ) ) ;
V_6 = F_48 ( V_10 , & V_10 -> V_65 ) ;
if ( V_6 )
F_65 ( V_35 , L_164 , V_6 ) ;
V_6 = F_27 ( & V_10 -> V_38 ) ;
if ( V_6 )
F_65 ( V_35 , L_165 , V_6 ) ;
V_6 = F_27 ( & V_10 -> V_29 ) ;
if ( V_6 )
F_65 ( V_35 , L_166 , V_6 ) ;
F_46 ( F_53 ( & V_10 -> V_412 ) ) ;
F_46 ( F_53 ( & V_10 -> V_262 ) ) ;
F_46 ( F_53 ( & V_10 -> V_289 ) ) ;
F_46 ( F_53 ( & V_10 -> V_70 ) ) ;
F_42 ( & V_10 -> V_229 -> V_218 , 0 ) ;
F_46 ( F_53 ( & V_10 -> V_229 -> V_23 ) ) ;
}
static int F_283 ( struct V_9 * V_10 )
{
struct V_660 * V_260 = & V_10 -> V_104 . V_156 . V_661 ;
int V_66 ;
if ( F_284 ( & V_10 -> V_104 . V_662 ) ) {
F_40 ( V_35 , L_167 ) ;
return 0 ;
}
if ( V_10 -> V_104 . V_75 == NULL ) {
F_285 ( & V_10 -> V_104 . V_662 ) ;
return 0 ;
}
memset ( V_260 , 0 , sizeof( * V_260 ) ) ;
V_260 -> V_663 = F_286 ( V_664 ) ;
V_260 -> V_665 = F_286 ( V_666 ) ;
V_66 = F_77 ( V_10 , V_10 -> V_104 . V_75 , V_667 ,
(struct V_154 * ) V_260 , sizeof( * V_260 ) , 0 ) ;
F_285 ( & V_10 -> V_104 . V_662 ) ;
return V_66 ;
}
static int F_90 ( struct V_9 * V_10 )
{
struct V_660 * V_260 = & V_10 -> V_104 . V_159 . V_661 ;
const int V_278 = sizeof( struct V_660 ) - sizeof( struct V_154 ) ;
unsigned int V_205 ;
enum V_152 V_153 ;
int V_102 ;
V_102 = F_283 ( V_10 ) ;
if ( ! V_102 )
return 0 ;
V_102 = F_101 ( V_10 , & V_153 , & V_205 ) ;
if ( ! V_102 )
return 0 ;
if ( V_153 != V_667 ) {
F_40 ( V_35 , L_168 ,
F_187 ( V_153 ) , V_153 ) ;
return - 1 ;
}
if ( V_205 != V_278 ) {
F_40 ( V_35 , L_169 ,
V_278 , V_205 ) ;
return - 1 ;
}
V_102 = F_64 ( V_10 , & V_260 -> V_2 . V_512 , V_278 ) ;
if ( V_102 != V_278 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_170 , V_102 ) ;
return 0 ;
}
V_260 -> V_663 = F_104 ( V_260 -> V_663 ) ;
V_260 -> V_665 = F_104 ( V_260 -> V_665 ) ;
if ( V_260 -> V_665 == 0 )
V_260 -> V_665 = V_260 -> V_663 ;
if ( V_666 < V_260 -> V_663 ||
V_664 > V_260 -> V_665 )
goto V_668;
V_10 -> V_270 = F_72 ( int , V_666 , V_260 -> V_665 ) ;
F_65 ( V_35 , L_171
L_172 , V_10 -> V_270 ) ;
return 1 ;
V_668:
F_40 ( V_35 , L_173
L_174 ,
V_664 , V_666 ,
V_260 -> V_663 , V_260 -> V_665 ) ;
return - 1 ;
}
static int F_91 ( struct V_9 * V_10 )
{
F_40 ( V_35 , L_175 ) ;
F_40 ( V_35 , L_176 ) ;
return - 1 ;
}
static int F_91 ( struct V_9 * V_10 )
{
char V_669 [ V_670 ] ;
struct V_671 V_672 ;
char * V_673 = NULL ;
char * V_674 = NULL ;
char * V_675 = NULL ;
unsigned int V_676 = strlen ( V_10 -> V_30 -> V_677 ) ;
unsigned int V_678 ;
struct V_679 V_680 ;
enum V_152 V_153 ;
unsigned int V_205 ;
int V_102 ;
V_680 . V_497 = V_10 -> V_192 ;
V_680 . V_59 = 0 ;
V_102 = F_287 ( V_10 -> V_192 ,
( V_681 * ) V_10 -> V_30 -> V_677 , V_676 ) ;
if ( V_102 ) {
F_40 ( V_35 , L_177 , V_102 ) ;
V_102 = - 1 ;
goto V_53;
}
F_288 ( V_669 , V_670 ) ;
V_102 = F_289 ( V_10 , V_682 , V_669 , V_670 ) ;
if ( ! V_102 )
goto V_53;
V_102 = F_101 ( V_10 , & V_153 , & V_205 ) ;
if ( ! V_102 )
goto V_53;
if ( V_153 != V_682 ) {
F_40 ( V_35 , L_178 ,
F_187 ( V_153 ) , V_153 ) ;
V_102 = 0 ;
goto V_53;
}
if ( V_205 > V_670 * 2 ) {
F_40 ( V_35 , L_179 ) ;
V_102 = - 1 ;
goto V_53;
}
V_675 = F_125 ( V_205 , V_181 ) ;
if ( V_675 == NULL ) {
F_40 ( V_35 , L_180 ) ;
V_102 = - 1 ;
goto V_53;
}
V_102 = F_64 ( V_10 , V_675 , V_205 ) ;
if ( V_102 != V_205 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_181 , V_102 ) ;
V_102 = 0 ;
goto V_53;
}
V_678 = F_130 ( V_10 -> V_192 ) ;
V_673 = F_125 ( V_678 , V_181 ) ;
if ( V_673 == NULL ) {
F_40 ( V_35 , L_182 ) ;
V_102 = - 1 ;
goto V_53;
}
F_290 ( & V_672 , 1 ) ;
F_291 ( & V_672 , V_675 , V_205 ) ;
V_102 = F_292 ( & V_680 , & V_672 , V_672 . V_205 , V_673 ) ;
if ( V_102 ) {
F_40 ( V_35 , L_183 , V_102 ) ;
V_102 = - 1 ;
goto V_53;
}
V_102 = F_289 ( V_10 , V_683 , V_673 , V_678 ) ;
if ( ! V_102 )
goto V_53;
V_102 = F_101 ( V_10 , & V_153 , & V_205 ) ;
if ( ! V_102 )
goto V_53;
if ( V_153 != V_683 ) {
F_40 ( V_35 , L_184 ,
F_187 ( V_153 ) , V_153 ) ;
V_102 = 0 ;
goto V_53;
}
if ( V_205 != V_678 ) {
F_40 ( V_35 , L_185 ) ;
V_102 = 0 ;
goto V_53;
}
V_102 = F_64 ( V_10 , V_673 , V_678 ) ;
if ( V_102 != V_678 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_186 , V_102 ) ;
V_102 = 0 ;
goto V_53;
}
V_674 = F_125 ( V_678 , V_181 ) ;
if ( V_674 == NULL ) {
F_40 ( V_35 , L_187 ) ;
V_102 = - 1 ;
goto V_53;
}
F_291 ( & V_672 , V_669 , V_670 ) ;
V_102 = F_292 ( & V_680 , & V_672 , V_672 . V_205 , V_674 ) ;
if ( V_102 ) {
F_40 ( V_35 , L_183 , V_102 ) ;
V_102 = - 1 ;
goto V_53;
}
V_102 = ! memcmp ( V_673 , V_674 , V_678 ) ;
if ( V_102 )
F_65 ( V_35 , L_188 ,
V_678 , V_10 -> V_30 -> V_684 ) ;
else
V_102 = - 1 ;
V_53:
F_45 ( V_675 ) ;
F_45 ( V_673 ) ;
F_45 ( V_674 ) ;
return V_102 ;
}
int F_293 ( struct V_685 * V_686 )
{
struct V_9 * V_10 = V_686 -> V_10 ;
unsigned int V_687 = F_294 ( V_10 ) ;
int V_155 ;
sprintf ( V_34 -> V_336 , L_189 , V_687 ) ;
F_65 ( V_35 , L_190 ) ;
do {
V_155 = F_81 ( V_10 ) ;
if ( V_155 == 0 ) {
F_276 ( V_10 ) ;
F_84 ( V_126 ) ;
}
if ( V_155 == - 1 ) {
F_30 ( V_35 , L_191 ) ;
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
}
} while ( V_155 == 0 );
if ( V_155 > 0 ) {
if ( F_70 ( V_10 ) ) {
F_269 ( V_10 ) ;
F_73 ( V_10 ) ;
}
}
F_276 ( V_10 ) ;
F_65 ( V_35 , L_192 ) ;
return 0 ;
}
static int F_295 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_688 * V_260 = (struct V_688 * ) V_155 ;
int V_689 = F_104 ( V_260 -> V_689 ) ;
if ( V_689 >= V_172 ) {
F_85 ( V_690 , & V_10 -> V_59 ) ;
} else {
F_85 ( V_691 , & V_10 -> V_59 ) ;
F_40 ( V_35 , L_193 ,
F_296 ( V_689 ) , V_689 ) ;
}
F_36 ( & V_10 -> V_692 ) ;
return true ;
}
static int F_297 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
return F_298 ( V_10 ) ;
}
static int F_299 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
V_10 -> V_187 . V_75 -> V_78 -> V_123 = V_10 -> V_30 -> V_186 * V_126 ;
if ( ! F_300 ( V_693 , & V_10 -> V_59 ) )
F_36 ( & V_10 -> V_335 ) ;
return true ;
}
static int F_301 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_694 * V_260 = (struct V_694 * ) V_155 ;
T_3 V_43 = F_147 ( V_260 -> V_43 ) ;
int V_383 = F_104 ( V_260 -> V_383 ) ;
F_46 ( V_10 -> V_270 >= 89 ) ;
F_302 ( V_10 , F_104 ( V_260 -> V_323 ) ) ;
if ( F_106 ( V_10 ) ) {
F_303 ( V_10 , V_43 ) ;
F_141 ( V_10 , V_43 , V_383 ) ;
V_10 -> V_695 += ( V_383 >> V_696 ) ;
F_109 ( V_10 ) ;
}
F_145 ( V_10 ) ;
F_33 ( V_383 >> 9 , & V_10 -> V_296 ) ;
return true ;
}
static struct V_274 * F_304 ( struct V_9 * V_10 ,
T_2 V_42 , T_3 V_43 )
{
struct V_327 * V_328 = F_168 ( V_10 , V_43 ) ;
struct V_326 * V_3 ;
struct V_274 * V_275 ;
F_169 (req, n, slot, collision) {
if ( ( unsigned long ) V_275 == ( unsigned long ) V_42 ) {
if ( V_275 -> V_43 != V_43 ) {
F_40 ( V_35 , L_194
L_195 , V_275 ,
( unsigned long long ) V_275 -> V_43 ,
( unsigned long long ) V_43 ) ;
break;
}
return V_275 ;
}
}
return NULL ;
}
static int F_305 ( struct V_9 * V_10 ,
T_2 V_42 , T_3 V_43 , T_9 V_697 ,
const char * V_698 , enum V_699 V_74 )
{
struct V_274 * V_275 ;
struct V_700 V_701 ;
F_21 ( & V_10 -> V_26 ) ;
V_275 = V_697 ( V_10 , V_42 , V_43 ) ;
if ( F_102 ( ! V_275 ) ) {
F_22 ( & V_10 -> V_26 ) ;
F_40 ( V_35 , L_196 , V_698 ,
( void * ) ( unsigned long ) V_42 , ( unsigned long long ) V_43 ) ;
return false ;
}
F_306 ( V_275 , V_74 , & V_701 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_701 . V_244 )
F_307 ( V_10 , & V_701 ) ;
return true ;
}
static int F_308 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_694 * V_260 = (struct V_694 * ) V_155 ;
T_3 V_43 = F_147 ( V_260 -> V_43 ) ;
int V_383 = F_104 ( V_260 -> V_383 ) ;
enum V_699 V_74 ;
F_302 ( V_10 , F_104 ( V_260 -> V_323 ) ) ;
if ( F_309 ( V_260 -> V_60 ) ) {
F_141 ( V_10 , V_43 , V_383 ) ;
F_145 ( V_10 ) ;
return true ;
}
switch ( F_79 ( V_155 -> V_163 ) ) {
case V_286 :
F_46 ( V_10 -> V_30 -> V_299 == V_300 ) ;
V_74 = V_702 ;
break;
case V_304 :
F_46 ( V_10 -> V_30 -> V_299 == V_300 ) ;
V_74 = V_703 ;
break;
case V_342 :
F_46 ( V_10 -> V_30 -> V_299 == V_341 ) ;
V_74 = V_704 ;
break;
case V_306 :
F_46 ( V_10 -> V_30 -> V_299 == V_300 ) ;
V_74 = V_705 ;
break;
default:
F_46 ( 0 ) ;
return false ;
}
return F_305 ( V_10 , V_260 -> V_60 , V_43 ,
F_304 , V_601 , V_74 ) ;
}
static int F_310 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_694 * V_260 = (struct V_694 * ) V_155 ;
T_3 V_43 = F_147 ( V_260 -> V_43 ) ;
int V_58 = F_104 ( V_260 -> V_383 ) ;
struct V_274 * V_275 ;
struct V_700 V_701 ;
F_302 ( V_10 , F_104 ( V_260 -> V_323 ) ) ;
if ( F_309 ( V_260 -> V_60 ) ) {
F_145 ( V_10 ) ;
F_143 ( V_10 , V_43 , V_58 ) ;
return true ;
}
F_21 ( & V_10 -> V_26 ) ;
V_275 = F_304 ( V_10 , V_260 -> V_60 , V_43 ) ;
if ( ! V_275 ) {
F_22 ( & V_10 -> V_26 ) ;
if ( V_10 -> V_30 -> V_299 == V_343 ||
V_10 -> V_30 -> V_299 == V_341 ) {
F_173 ( V_10 , V_43 , V_58 ) ;
return true ;
} else {
F_40 ( V_35 , L_196 , V_601 ,
( void * ) ( unsigned long ) V_260 -> V_60 , ( unsigned long long ) V_43 ) ;
return false ;
}
}
F_306 ( V_275 , V_706 , & V_701 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_701 . V_244 )
F_307 ( V_10 , & V_701 ) ;
return true ;
}
static int F_311 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_694 * V_260 = (struct V_694 * ) V_155 ;
T_3 V_43 = F_147 ( V_260 -> V_43 ) ;
F_302 ( V_10 , F_104 ( V_260 -> V_323 ) ) ;
F_40 ( V_35 , L_197 ,
( unsigned long long ) V_43 , F_104 ( V_260 -> V_383 ) ) ;
return F_305 ( V_10 , V_260 -> V_60 , V_43 ,
F_148 , V_601 , V_706 ) ;
}
static int F_312 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
T_3 V_43 ;
int V_58 ;
struct V_694 * V_260 = (struct V_694 * ) V_155 ;
V_43 = F_147 ( V_260 -> V_43 ) ;
V_58 = F_104 ( V_260 -> V_383 ) ;
F_302 ( V_10 , F_104 ( V_260 -> V_323 ) ) ;
F_145 ( V_10 ) ;
if ( F_184 ( V_10 , V_585 ) ) {
F_303 ( V_10 , V_43 ) ;
switch ( F_79 ( V_155 -> V_163 ) ) {
case V_390 :
F_143 ( V_10 , V_43 , V_58 ) ;
case V_707 :
break;
default:
F_46 ( 0 ) ;
F_109 ( V_10 ) ;
return false ;
}
F_109 ( V_10 ) ;
}
return true ;
}
static int F_313 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_708 * V_260 = (struct V_708 * ) V_155 ;
F_314 ( V_10 , V_260 -> V_261 , F_104 ( V_260 -> V_709 ) ) ;
if ( V_10 -> V_67 . V_68 == V_581 &&
F_27 ( & V_10 -> V_710 ) == 0 &&
! F_300 ( V_711 , & V_10 -> V_59 ) ) {
V_10 -> V_712 . V_713 = V_189 + V_126 ;
F_315 ( & V_10 -> V_712 ) ;
}
return true ;
}
static int F_316 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_694 * V_260 = (struct V_694 * ) V_155 ;
struct V_283 * V_22 ;
T_3 V_43 ;
int V_58 ;
V_43 = F_147 ( V_260 -> V_43 ) ;
V_58 = F_104 ( V_260 -> V_383 ) ;
F_302 ( V_10 , F_104 ( V_260 -> V_323 ) ) ;
if ( F_147 ( V_260 -> V_60 ) == V_714 )
F_317 ( V_10 , V_43 , V_58 ) ;
else
F_318 ( V_10 ) ;
if ( ! F_106 ( V_10 ) )
return true ;
F_303 ( V_10 , V_43 ) ;
F_145 ( V_10 ) ;
-- V_10 -> V_373 ;
if ( ( V_10 -> V_373 & 0x200 ) == 0x200 )
F_319 ( V_10 , V_10 -> V_373 ) ;
if ( V_10 -> V_373 == 0 ) {
V_22 = F_125 ( sizeof( * V_22 ) , V_181 ) ;
if ( V_22 ) {
V_22 -> V_71 = V_715 ;
F_320 ( & V_10 -> V_104 . V_642 , V_22 ) ;
} else {
F_40 ( V_35 , L_198 ) ;
F_318 ( V_10 ) ;
F_237 ( V_10 ) ;
}
}
F_109 ( V_10 ) ;
return true ;
}
static int F_321 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
return true ;
}
static struct V_716 * F_322 ( int V_153 )
{
static struct V_716 V_717 [] = {
[ V_718 ] = { sizeof( struct V_154 ) , F_297 } ,
[ V_719 ] = { sizeof( struct V_154 ) , F_299 } ,
[ V_342 ] = { sizeof( struct V_694 ) , F_308 } ,
[ V_304 ] = { sizeof( struct V_694 ) , F_308 } ,
[ V_286 ] = { sizeof( struct V_694 ) , F_308 } ,
[ V_306 ] = { sizeof( struct V_694 ) , F_308 } ,
[ V_287 ] = { sizeof( struct V_694 ) , F_310 } ,
[ V_386 ] = { sizeof( struct V_694 ) , F_311 } ,
[ V_390 ] = { sizeof( struct V_694 ) , F_312 } ,
[ V_392 ] = { sizeof( struct V_694 ) , F_316 } ,
[ V_720 ] = { sizeof( struct V_708 ) , F_313 } ,
[ V_721 ] = { sizeof( struct V_688 ) , F_295 } ,
[ V_722 ] = { sizeof( struct V_694 ) , F_301 } ,
[ V_723 ] = { sizeof( struct V_724 ) , F_321 } ,
[ V_707 ] = { sizeof( struct V_694 ) , F_312 } ,
[ V_633 ] = { 0 , NULL } ,
} ;
if ( V_153 > V_633 || V_717 [ V_153 ] . V_725 == NULL )
return NULL ;
return & V_717 [ V_153 ] ;
}
int F_323 ( struct V_685 * V_686 )
{
struct V_9 * V_10 = V_686 -> V_10 ;
struct V_154 * V_155 = & V_10 -> V_187 . V_159 . V_157 . V_158 ;
struct V_716 * V_153 = NULL ;
int V_102 , V_5 ;
void * V_88 = V_155 ;
int V_726 = 0 ;
int V_278 = sizeof( struct V_154 ) ;
int V_727 ;
int V_728 = 0 ;
sprintf ( V_34 -> V_336 , L_199 , F_294 ( V_10 ) ) ;
V_34 -> V_729 = V_730 ;
V_34 -> V_731 = 2 ;
while ( F_88 ( V_686 ) == V_631 ) {
F_270 ( V_10 ) ;
if ( F_226 ( V_732 , & V_10 -> V_59 ) ) {
F_131 (!drbd_send_ping(mdev)) goto V_733;
V_10 -> V_187 . V_75 -> V_78 -> V_123 =
V_10 -> V_30 -> V_177 * V_126 / 10 ;
V_728 = 1 ;
}
if ( ! V_10 -> V_30 -> V_734 &&
3 < F_27 ( & V_10 -> V_735 ) )
F_324 ( V_10 -> V_187 . V_75 ) ;
while ( 1 ) {
F_83 ( V_736 , & V_10 -> V_59 ) ;
F_86 ( V_34 ) ;
if ( ! F_50 ( V_10 ) )
goto V_733;
F_85 ( V_736 , & V_10 -> V_59 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_727 = F_53 ( & V_10 -> V_70 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_727 )
break;
}
if ( ! V_10 -> V_30 -> V_734 )
F_325 ( V_10 -> V_187 . V_75 ) ;
if ( F_29 ( V_34 ) )
continue;
V_102 = F_60 ( V_10 , V_10 -> V_187 . V_75 ,
V_88 , V_278 - V_726 , 0 ) ;
F_83 ( V_736 , & V_10 -> V_59 ) ;
F_86 ( V_34 ) ;
if ( F_103 ( V_102 > 0 ) ) {
V_726 += V_102 ;
V_88 += V_102 ;
} else if ( V_102 == 0 ) {
F_40 ( V_35 , L_200 ) ;
goto V_733;
} else if ( V_102 == - V_139 ) {
if ( F_326 ( V_10 -> V_188 ,
V_189 - V_10 -> V_187 . V_75 -> V_78 -> V_123 ) )
continue;
if ( V_728 ) {
F_40 ( V_35 , L_201 ) ;
goto V_733;
}
F_85 ( V_732 , & V_10 -> V_59 ) ;
continue;
} else if ( V_102 == - V_141 ) {
continue;
} else {
F_40 ( V_35 , L_10 , V_102 ) ;
goto V_733;
}
if ( V_726 == V_278 && V_153 == NULL ) {
if ( F_102 ( V_155 -> V_161 != V_162 ) ) {
F_40 ( V_35 , L_202 ,
F_104 ( V_155 -> V_161 ) ,
F_79 ( V_155 -> V_163 ) ,
F_79 ( V_155 -> V_205 ) ) ;
goto V_733;
}
V_153 = F_322 ( F_79 ( V_155 -> V_163 ) ) ;
V_5 = F_79 ( V_155 -> V_205 ) ;
if ( F_102 ( V_153 == NULL ) ) {
F_40 ( V_35 , L_203 ,
F_104 ( V_155 -> V_161 ) ,
F_79 ( V_155 -> V_163 ) ,
F_79 ( V_155 -> V_205 ) ) ;
goto V_491;
}
V_278 = V_153 -> V_636 ;
F_131 (len != expect-sizeof(struct p_header80))
goto V_733;
}
if ( V_726 == V_278 ) {
V_10 -> V_188 = V_189 ;
F_46 ( V_153 != NULL ) ;
if ( ! V_153 -> V_725 ( V_10 , V_155 ) )
goto V_733;
if ( V_153 == F_322 ( V_719 ) )
V_728 = 0 ;
V_88 = V_155 ;
V_726 = 0 ;
V_278 = sizeof( struct V_154 ) ;
V_153 = NULL ;
}
}
if ( 0 ) {
V_733:
F_66 ( V_10 , F_67 ( V_68 , V_649 ) ) ;
F_223 ( V_10 ) ;
}
if ( 0 ) {
V_491:
F_66 ( V_10 , F_67 ( V_68 , V_146 ) ) ;
F_223 ( V_10 ) ;
}
F_83 ( V_736 , & V_10 -> V_59 ) ;
F_46 ( V_10 -> V_67 . V_68 < V_475 ) ;
F_65 ( V_35 , L_204 ) ;
return 0 ;
}
